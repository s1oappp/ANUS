# 02. Слой BSP/драйверов прошивки usblsafe-327x.bin (Balong V7R1 / HI6920, VxWorks 6.8)

Документ построен по декомпилированному коду (`usbl_src/src/bsp/*.c`, `decompiled_all.c`, `disasm_full.asm`)
и бинарнику `usbl_payload_30004000.bin`. Каждое утверждение снабжено адресом функции или ячейкой литерал-пула
(DAT_xxx). Гипотезы (не сверены с кодом напрямую либо выведены косвенно) помечены **(гип.)**.

## 0. Метод и договорённости

- База чтения бинарника: **VA = file_offset + 0x30004000** (payload начинается ровно с VA 0x30004000;
  конец — 0x301AF46C). Слово `rd32(va)` = 4 байта по смещению `va − 0x30004000`.
- `DAT_xxx` в декомпиляте — ячейка литерал-пула: **значение слова по адресу DAT = фактический указатель/константа**
  (проверено: `ldr ip,[pc,#0xa20]` → слово по 0x30005088 = 0x90000048, далее разыменование 0x90000048).
- Разыменования (`*DAT`, `(cast*)DAT+off`, `DAT[n]`) считались MMIO-доступами и собраны в
  `analysis/bsp_mmio_deref.json`; простые загрузки констант туда не попадали.
- Инвентарь: 508 функций BSP (`usbl_src/index/ALL_FUNCTIONS.tsv`). Скрипты `scratch_*.py` — вспомогательные.

## 1. Обзор слоя

Слой BSP — тонкие регистровые обёртки над блоками SoC HI6920 и внешнего PMIC HI6451:

| Группа | Кол-во функций | Транспорт | Примечание |
|---|---|---|---|
| GPIO (BSP_GPIO_*) | 18 | MMIO 6 банков | DesignWare-стиль (гип.) |
| HKADC (BSP_HKADC_* + hkadc*) | 22+6 | SSI-канал 3 | внешний АЦП-мультиплексор |
| PMU (BSP_PMU_* + HI6451_*) | 31+40 | SPI шина 0 / dev 0 | внешний чип HI6451 |
| WDT (BSP_WDT_* + WDT_*) | 32 | MMIO SP805 | + soft-WDT задача |
| LED: BSP_TLED_* | 12 | логический слой | `led*` (37 ф.) — VxWorks line-editing, НЕ светодиоды |
| SPI | 15 | MMIO 2 шины | PMU/флеш-транспорт |
| SSI | 9 | MMIO 4 канала | ABB (ch2), HKADC (ch3) |
| I2C (BSP_I2C_*) | 5 | MMIO 0x90019000 | клок-генератор CY22393 |
| softtimer / USRCLK / CLK | 6/14/6 | системный таймер | VxWorks-надстройка |
| PWRCTRL/ABB | 17/8 | MMIO 0x90000000+ | клок-гейты, аналоговая часть |

Общая схема: процессор общается с PMU (HI6451) по SPI0, с аналоговым блоком (ABB) по SSI-каналу 2,
с HKADC по SSI-каналу 3; GPIO/WDТ/I2C — прямые MMIO. Персистентная SRAM 0x2ffd8000–0x30000000
используется для журнала кормления WDT и флагов DLOAD.

## 2. Карта регистров

### 2.1 PWRCTRL/CRG — база 0x90000000

| Адрес | Поле | Доказательство |
|---|---|---|
| 0x90000000 | I2C-клок: enable (бит CY22393) | PWRCTRL_I2C_SoftClk* @0x30063C68/CC8 (гип. по паттерну) |
| 0x90000004 | I2C-клок: disable | прогресс-проход, паттерн en/dis/status |
| 0x90000008 | I2C-клок: status | (гип.) |
| **0x9000000C** | SPI/WDT-клок: **enable**; бит31 = WDT | PWRCTRL_WDT_SoftClkEn @0x30007184: `*0x9000000C = 0x80000000` (лит. 0x30007a4c/0x30007a50) |
| **0x90000010** | SPI/WDT-клок: **disable**, бит31 = WDT | PWRCTRL_WDT_SoftClkDis @0x30007174: `*0x90000010 = 0x80000000` (лит. 0x30007a48) |
| **0x90000014** | SPI/WDT-клок: **status**, бит31 = WDT | PWRCTRL_WDT_SoftClkStatus @0x30007124: `*0x90000014 >> 31` (лит. 0x30007a40) |
| 0x90000048 | ABB-блок: сброс/включение ABB (bit0 — reset) | ABB_UnReset @0x3000465C: RMW 0x90000048 (см. 3.7) |
| **0x90000408** | регистр управления WDT на уровне крист.: пишется магия **0x69200001** | BSP_WDT_Enable @0x30007624: `*0x90000408 = 0x69200001` (лит. 0x30007ab8/abc). Назначение полей — гип.: 0x6920 = сигнатура чипа HI6920 |
| 0x90000988 | CRG-клок SPI шины 0: `|= 0x800` | SPI_Init @0x3002D7E4 (прогресс-проход) |
| 0x90000944 | CRG-клок SPI шины 1: `|= 0xC000` | SPI_Init @0x3002D7E4 |
| 0x90007000 | база системного таймера (ustimer/softtimer) | **(гип.)** слово @0x3017d54c; тела USRCLK не дочитаны |

### 2.2 WDT — SP805, база 0x90001000

Все адреса подтверждены литералами (0x30007a54–0x30007ad0).

| Адрес | Регистр SP805 | Использование |
|---|---|---|
| 0x90001000 | WDT_LOAD (0x000) | BSP_WDT_Enable: = 0xF0000; SetTimeOut: = param; reboot_direct: = 10 |
| 0x90001004 | WDT_VALUE (0x004) | BSP_WDT_TimeoutGet читает (лит. 0x30007acc) |
| 0x90001008 | WDT_CONTROL (0x008) | Enable/Resume: = 3 (ENABLE|RESETEN); Disable/Stop: = 0 |
| 0x9000100C | WDT_INTCLR (0x00C) | BSP_WDT_HardwareFeed @0x300071B4: `*0x9000100C = 0` |
| 0x90001C00 | WDT_LOCK (0xC00) | WDT_LOCK/UNLOCK @0x30007194/0x300071A4; unlock-магия **0x1ACCE551** (лит. 0x30007a58) |
| 0x90002098 / 0x9000209C | неизвестно (новый блок 0x90002000) | лит. 0x30007aac/0x30007aa8; тела-потребители не дочитаны — **(гип.)** clk/rescue-регистры |

Тактирование: LOAD=0xF0000=983040 при частоте 32768 Гц даёт ровно **30 с** (983040 = 32768×30) —
стандартный bootrom-интервал. **(гип.)** частота счётчика WDT = 32768 Гц.
BSP_WDT_TimeoutGet @0x30007874 возвращает `LOAD × 0x51EB851F >> 35` = LOAD/100 (реципрокное деление,
лит. 0x30007ad0); единица результата = 10 мс при такте 100 кГц **(гип., формула подтверждена, единица — нет)**.

### 2.3 GPIO — 6 банков DesignWare-стиля (гип. по регистровому раскладу)

Таблица баз @0x301808a8: **0x90006000, 0x90011000, 0x9000E000, 0x90013000, 0x90014000, 0x90015000**.
Номера IRQ @0x301808c0: **112–117 (0x70–0x75)**. Init-флаг @0x301808d8.
Таблицы колбэков @0x301b01e8 / 0x301b04e8 (0x300 байт = 6×32 пина). Общий хендлер прерываний 0x3003546c.

| Смещение от базы банка | Регистр (DesignWare) | Подтверждение |
|---|---|---|
| +0x00 | SWPORTA_DR (data out) | BSP_GPIO_ValSet @0x30034C84 / ValGet @0x30034E20 |
| +0x04 | SWPORTA_DDR (направление) | BSP_GPIO_DrcSet @0x30034AC4 / DrcGet @0x30034BD8 |
| +0x30 | INTEN и далее до +0x4C — блок прерываний | **(гип.)** — поля IntInstall/IntMaskSet не дочитаны |
| +0x50 | EXT_PORTS (вход) | **(гип.)** чтение входа |

Функции: Init @0x30034A34. Прерыванийная группа (IntInstall/MaskSet/StateGet/TriggerSet/RawIntStateGet/
Int_handle/PinModeCtrl/PWC_Reg_Save/Restore) — адреса в ALL_FUNCTIONS.tsv, тела не дочитаны (см. §6).

### 2.4 SPI — 2 шины

Базы из конфига+0x58: **0x90008000** (шина 0) и **0x90023000** (шина 1). Клоки — CRG (см. 2.1).

| Смещение | Регистр | Значения |
|---|---|---|
| +0x00 | CR0 | read-команда: `|=…|0x40`; write: `|0x140` |
| +0x04 | длина фрейма −1 | |
| +0x08 | START | |
| +0x0C | режим | bit1 |
| +0x10 | CS | `1 << dev` |
| +0x14 | CLKDIV | |
| +0x28 | SR | bit0 busy, bit2 tx-done, bit3 rx-avail |
| +0x60 | DR | данные |

Конфигурация: 2 шины × 4 устройства, размер записи 0x6C/0x14 байт; таймаут 0x4E20 (20000).
Глобалы: 0x301803dc (init-флаг), 0x301803e0 (cfg), 0x301803e4 (framebits), 0x301803e8 (iftype),
0x301803ec (devnum), 0x30180430 (семафоры), 0x30180434 (devidx), 0x30180438 (таблица баз).
Функции: Init @0x3002D7E4, SetAttr @0x3002DCB8, Read @0x3002E628, Write @0x3002E058,
POLL_Send @0x3002D9D4, POLL_Receive @0x3002DB04, Lock @0x3002D9A4 (intCpuLock; хвост Lock/UnLock обрезан).

### 2.5 SSI — 4 канала

Каналы: **0x90030000 / 0x90031000 / 0x90032000 / 0x90033000** (инициализация в SSI_Init @0x3002F724
через таблицу DAT_300304f4 → 0x301804c4; записи в +0x04/+0x10/+0x1C/+0x28).
Таблица баз @0x301804c8 (шаг 0xC), флаги @0x301804cc, таймаут 0x1E8480 (2 000 000).

| Смещение | Регистр |
|---|---|
| +0x00 | CR0: framebits−1 \| clkdiv<<3 |
| +0x04 | START |
| +0x08 | «1» при чтении |
| +0x10 | clkdiv2 |
| +0x14 | DR |
| +0x18 | SR: bit0 busy, bit2 data, bit4 active |

Функции: Init @0x3002F724, Read @0x3002FF2C, Write @0x3002FBA8, SetAttr @0x3002F9C0,
GetAttr @0x30030338, FindID @0x3002F640. Блокировка: intCpuLock/Unlock, без семафора.
Потребители каналов: ch2 = ABB, ch3 = HKADC; ch0/ch1 — не определены (открытый вопрос).

### 2.6 I2C — база 0x90019000

Регистры 0x90019000–0x9001901C (DataTx/Rx), клок-гейт — PWRCTRL +0x00/+0x04/+0x08 (см. 2.1).
Функции: I2C_StatusCheck @0x30063CD8, BSP_I2C_DataTx @0x30063D5C, BSP_I2C_DataRx @0x30063F3C,
PWRCTRL_I2C_SoftClkEn/Dis/Status @0x30063CC8/0x30063CB8/0x30063C68. Тела не разобраны (см. §6).
CY22393 Init — программируемый I2C клок-генератор (тактирование периферии).

### 2.7 SRAM / разделяемая память

| Диапазон | Назначение | Доказательство |
|---|---|---|
| 0x2FFD8000–0x30000000 | персистентная SRAM | журнал WDT, флаги DLOAD |
| 0x2FFDF800 / 0x2FFDFB04 | WDT feed log / магия 'AEXC' (u32 0x43584541) | лит. WDT 0x30007a90, 0x30007a94 |
| 0x2FFFE208 / 0x2FFFFEE0 / 0x2FFFFF84 | флаги DLOAD | прогресс-проход |
| 0x27FC0000 | TCM | прогресс-проход |
| 0x33D00000+ / 0x33EFFF00+ | shared memory | ABB/системные |
| 0x33D01000 | начало кэш-флеша при ребуте | BSP_WDT_reboot_direct: `cacheFlush(1, 0x33D01000, 0x100000)` |

## 3. Разбор подсистем

### 3.1 GPIO (BSP_GPIO_*)
Basis и регистры — см. 2.3. Функции: BSP_GPIO_Init @0x30034A34 (заполняет таблицы, ставит init-флаг),
BSP_GPIO_DrcSet @0x30034AC4 (DDR), BSP_GPIO_DrcGet @0x30034BD8, BSP_GPIO_ValSet @0x30034C84 (DR),
BSP_GPIO_ValGet @0x30034E20 (EXT in). Прерывание: 6 векторов IRQ 112–117 → общий хендлер 0x3003546c →
диспетчеризация по таблицам колбэков 0x301b01e8/0x301b04e8 (32 пина × 6 банков). Детали масок/триггеров —
открытый вопрос (гип.: DesignWare +0x30 INTEN, +0x34 INTMASK, +0x38 INTTYPE, +0x40 INTCLR, +0x48 INTSTAT).

### 3.2 HKADC — АЦП через SSI-канал 3 (полностью прочитано)

Транспорт: SSI ch3 (0x90033000), атрибуты {6,7,0xF}.
- hkadcSsiSend @0x300406F0: фрейм `cmd | val<<7`; hkadcSsiRecv @0x3004075C; timeDelay @0x300406B4.
- hkadcInit @0x300407BC: semBCreate (ячейка 0x30181274), send(2,2); hkadcReInit @0x30040878.
- **BSP_HKADC_Convert(ch, &out16) @0x300409A0** — ядро:
  1. ждать init-флага 0x30181320 == 1; взять семафор 0x30181274;
  2. send(0,0x10); send(0,0x12); задержка 562 (лит. 0x30041844 = 0x232);
  3. выбор канала: `send(2, (ch'<<2)|2)`, где `ch' = ch+4 если ch>9`;
  4. send(1,0); send(1,1) — старт; поллинг recv(4) до bit0 (таймаут 0x600 итераций, задержка 1125);
  5. данные: recv(5) = старшие, recv(6) = младшие; стоп: send(0,0x18), send(1,0);
  6. **результат (мВ) = ((hi<<2 | (lo&0xC0)>>6) × 2500 + 0x200) >> 10** — 10 бит, полная шкала 2500 мВ (K=2500, лит. 0x300418b0 = 0x9C4).
- Каналы (таблица @0x30181178 = [0,1,2,…,11], байтовые индексы):
  - **ch1 — LTE PA** (мощность/температура): LtePAPowerRead @0x30041210, LtePATempRead @0x30040FD8, PaValueGet @0x30040E00 (жёстко ch=1);
  - **ch3 — SIM-температура**: SIMTempRead @0x300410A8 (спец-ветка в TemVoltTrans при ch==3);
  - **ch5 — TFT-температура**: TftTempRead @0x300415A0;
  - **ch6 — напряжение батареи**: BatVolRead @0x300412BC + калибровка @0x30181264 = u32 [3400, 3400, 4200, 4200] = {Vmin, ADC@Vmin×?, Vmax, ADC@Vmax}: `V = Vmin + (Vmax−Vmin)×(raw×2 − a_min)/(a_max − a_min)`; в файле-образе вырождено: **V = raw×2 мВ** (делитель 1:2 → полная шкала 5000 мВ) — (гип. о делителе, формула подтверждена);
  - **ch8 — DCXO-температура**: DcxoTempRead @0x300414C8.
- **BSP_HKADC_TemVoltTrans(ch, mv, LUT) @0x30040E68** — перевод мВ→°C по паре {s16 темп, u16 мВ},
  LUT по убыванию мВ, линейная интерполяция; лимит перебора: 19 пар для ch3, 32 для остальных.
- **LUT @0x3018127C** (значения из бинарника): (−30,2498),(−25,2454),(−20,2436),(−15,2413),(−10,2383),
  (−5,2344),(0,2296),(5,2236)…(110,214),(115,184),(0,0)-терминатор. Шаг 5 °C.
- **Таблица диапазонов @0x301812F8** — 10 полос [lo,hi] с шагом 4 байта: [0,146],[148,422],[424,698],
  [700,974],[976,1250],[1252,1525],[1528,1801],[1804,2077],[2080,2353],[2355,2500] мВ.
  Используется BSP_HKADC_GetVer(ch,&ver) @0x30040C44: измерение → **номер полосы = версия платы**;
  GetVerSafe @0x30040D4C — тройное чтение со сверкой (2 из 3), задержка 500 итераций.
- Фоновая задача: BSP_HKADC_GetTempInit @0x300408DC (semBCreate, taskSpawn prio 0x98=152, стек 0x1000,
  entry GetTempTask) → **BSP_HKADC_GetTempTask @0x30040B7C**: цикл semTake(50 тиков); для 12 записей
  таблицы @0x30181118 (шаг 8 байт: +0 значение u16, +2 valid, +3 enable, +4…+7 резерв/LUT (гип.))
  с enable≠0 вызывает Convert(ch, rec). Записи в файле нулевые (BSS) — включение каналов происходит
  в рантайме; писатель не найден (открытый вопрос).
- Служебные: TempVoltGet(sensor) @0x30041674 (0=PA, 1=SIM, 2=DCXO, 6=TFT; LUT = 0x3018127C через лит. 0x30041904);
  SmthProc @0x30041788 — сглаживание `v = (TempVoltGet + 3×avg)/4`, аккумуляторы 12×u32 @0x30181240;
  SmthValGet @0x300417D4. Заглушки: BatADCRead @0x30041598, BatTempRead @0x300414C4,
  GetSystemTemperature @0x30040E60 (всегда 0). Тест: BSP_HKADC_Test @0x30041A98.
- Код ошибки «нет параметра»: 0x1003 (лит. 0x300418bc). HwGetVerMain==0xFFFF → функция возвращает 0 без измерения.

### 3.3 PMU HI6451 — внешний PMIC на SPI шина 0, устройство 0

- reg_read @0x30030D00: 16-битный фрейм `(reg<<9)|0x100`; reg_write @0x30030C88: `(reg<<9)|val`;
  write_mask @0x30030E04 (RMW). Обёртки: BSP_PMU_RegRead @0x3003391C, BSP_PMU_RegWrite @0x300338DC.
- **HI6451_init @0x30031624**: проверка ID (reg0 == 0x10), reg0x51 bit0, статусы 0x40–0x42, 1–3, 0x43/0x44, 4–8;
  current_set(1..3, 3); int_install (якоря DAT_30032854/858/85C/0x30032940/0x30032944);
  voltage_set(3, 0xFA); voltage_switch(3, 1); Hi6451_BugAvoid(); semBCreate; taskSpawn(prio 100, стек 0x1000);
  write_mask(9, 0, 0xC0).
- Таблица init @0x30180860–0x30180880 (16-бит слова): 0x000C, 0x060D, 0x040D, 0x020D, 0x000D, 0x060E,
  0x040E, 0x020E, 0x000E, 0x040F, 0x020F, 0x000F, 0x071D, 0x071F, 0x0721, 0x0323, 0x0124, 0x0725 —
  **(гип.)** последовательность конфигурации buck-каналов (reg<<9|val, рег. 0x0C–0x25).
- BSP_PMU_* (BuckCtrl/LDOCtrl/DRCtrl/ModeSwitch/RF_OnOff/AptEnable/IsWarmStart/VolAdjust_ForSDIO/Sci/
  WiFi_PwrDown) — адреса в ALL_FUNCTIONS.tsv; тела не дочитаны (см. §6).

### 3.4 ABB — аналоговый блок через SSI-канал 2 (0x90032000)

- ABB_Write_Ssi @0x300307D4: фрейм `reg | val<<8`; ABB_Read_Ssi @0x300308C8; ReadData_Ssi @0x300309E8.
- **ABB_Init @0x30030AD4**: 0x20←0xFE, 0x24←0xF8, 0xDC←0xB8, 0xE1←0x40, 0xDA←3, 0xD5←0x80 (задержка 0x19BFCC),
  0xD5←0, 0xC0←3, 0xC1←0, 0xC2←0xD (задержка 0x83D6), 0xC2←0xC, 0x1C←0x13.
- SetBandGapOn @0x30030BC0: reg 0xD6 |= 0x80.
- **ABB_UnReset @0x3000465C**: RMW 0x90000048 (сброс bit0, цикл 1 128 584, установка) — вывод ABB из сброса.
- ABB_LineCtrl @0x300307AC: пишет 0x03FFFFFF в **0x22000198/0x2200019C/0x220001A0** (назначение неизвестно).
- ABB_ReadCfg @0x300305B8: парсит конфиг-файл (строка @0x301368A8 «…:1;cmdStateRf:…»).

### 3.5 WDT (полностью прочитано)

Аппаратная часть — см. 2.2. Программный каркас:
- WDT_LOCK/UNLOCK @0x30007194/0x300071A4 (LOCK reg 0x90001C00, магия 0x1ACCE551).
- BSP_WDT_Enable(0) @0x30007624: если флаг 0x3017D2D4 == 0 → WDT_Init(); PWRCTRL_WDT_SoftClkEn();
  `*0x90000408 = 0x69200001`; UNLOCK; LOAD = 0xF0000 (30 с при 32768 Гц (гип.)); CONTROL = 3; LOCK;
  intConnect(0x25, WDT_IntHandler), intEnable(0x25); флаг = 1.
- WDT_Init @0x30007448: intCpuLock → WDT_SoftWdInit + WDT_APPInit → intCpuUnlock.
- WDT_SoftWdInit @0x300072F4: semBCreate → ячейка 0x3017D2C4; taskSpawn(WDT_LowTask, **prio 0xFE=254**, стек 0x1000);
  флаг 0x3017D2D0 = 1.
- WDT_LowTask @0x30007260: цикл semTake(sem, 500 тиков); если включён — HardwareFeed(0) + WDT_FeedLog.
- BSP_WDT_Feed @0x30007784 — только semGive(семафор) (кормит низкоприоритетная задача).
- BSP_WDT_HardwareFeed @0x300071B4: UNLOCK; `*0x9000100C = 0` (INTCLR); LOCK.
- **WDT_IntHandler @0x30007470** (IRQ 0x25=37): если SRAM 0x2FFDFB04 == 0x43584541 ('AEXC' (гип. расшифровка)) —
  intDisable(0x25), флаг ошибки 0x3017D478=1 (контроль исчерпания); иначе если не ребут — HardwareFeed;
  если установлен пользовательский обработчик (ячейка 0x3017D474) — вызвать его.
- Журнал кормления: WDT_FeedLogStart/Stop @0x30006F54/0x30006F7C; WDT_FeedLog @0x30006F98 — кольцо
  100 дельт тиков (массив 400 байт @0x3017D2E4, счётчик 0x3017D47C, первый тик 0x3017D484, флаг 0x3017D480,
  последний тик 0x3017D488); WDT_ShowLog @0x3000703C печатает 10×10 колонок (0x28 байт строка × 10).
- Ребут: **BSP_WDT_reboot_direct @0x30007910**: PWRCTRL_WDT_SoftClkEn; taskCpuLock+intCpuLock; intDisable(0x25);
  `*(*(0x3017D2E0) + 0x114) = 1` (**(гип.)** причина ребута в PWRCTRL, база — рантайм-ячейка);
  cacheFlush(1, 0x33D01000, 0x100000); UNLOCK; CONTROL=3; LOAD=10; LOCK; WDT_Reboot @0x300075C4
  (флаг 0x3017D2DC=1, бесконечный цикл — сброс по истечении 10 тиков).
- Прочее: BSP_WDT_Disable @0x300076D8 (CONTROL=0, клок-гейт off), BSP_WDT_Stop @0x3000797C / Resume @0x300079A4
  (CONTROL=0 / =3, вызываются из BSP_DRV_BOOTROM_Init), BSP_WDT_Feed_Force @0x300077CC (прямой INTCLR),
  BSP_WDT_IntInstall @0x300077FC (ячейка 0x3017D474), BSP_WDT_Switch @0x300077F4 — заглушка (0),
  BSP_WDT_Init @0x3000761C — заглушка (0), WDT_APPInit @0x30007428, WDT_APPIntHandler @0x30007520.

### 3.6 SPI/SSI (см. 2.4/2.5)
Ключевые функции: SPI_Init @0x3002D7E4, SPI_Read @0x3002E628, SPI_Write @0x3002E058,
SPI_POLL_Send @0x3002D9D4, SPI_POLL_Receive @0x3002DB04, SPI_Lock @0x3002D9A4 (intCpuLock);
SSI_Init @0x3002F724, SSI_Read @0x3002FF2C, SSI_Write @0x3002FBA8, SSI_SetAttr @0x3002F9C0,
SSI_GetAttr @0x30030338, SSI_FindID @0x3002F640.
Клок-гейты: PWRCTRL_SPI_SoftClk* @0x3002D774/7C4/7D4, PWRCTRL_SSI_SoftClk* @0x3002F694/71C/720,
PWRCTRL_NAND_SoftClk* / LowPower* @0x3000F1AC–0x3000F1BC (заглушки-однострочники, гип.).

### 3.7 LED (BSP_TLED_*)
Аппаратных LED-драйверов нет: BSP_TLED_* — программный слой индикации поверх колбэков.
Функции: LedInit @0x30035C74, LedTask @0x30035944, LedOff @0x30035818, LedSwitch @0x3003583C,
LedStateFuncReg @0x3003592C, LedFlush @0x30035B60, LedUpdateCallback @0x30035C00,
LedCallback @0x30035C50, LedControlAddressGet @0x30035DE0, NotifyLedFlush @0x30035DE4.
Внимание: функции `led*` (37 шт., нижний регистр) — VxWorks line-editing library, к светодиодам отношения не имеют.

### 3.8 softtimer / USRCLK / CLK
- softtimer: task_func @0x3000A958, module_start @0x3000AAD8, create/del_timer @0x3000AF30/0x3000AD6C,
  interrupt_call_back @0x30009F50, show_used_info @0x3000B180.
  Глобалы 0x3017D4D8–0x3017D55C (значения 100; указатели функций 0x3000B5E0/0x3000B924/0x3000BA1C/
  0x3000B9DC/0x3000B99C @0x3017D530–0x3017D544). База таймера 0x90007000 — **(гип.)**.
  Область 0x301B5E9C–0x301B5EDC — BSS за концом бинарника (не дампится).
- USRCLK: Init @0x30008F2C, Alloc @0x30008FA4, Free @0x300090A8, Connect @0x30009248, Enable/Disable
  @0x300093F8/0x300092F4, RateGet/RateSet @0x300095E0/0x300096C8, TimerStart/Stop @0x300097D4/0x30009990,
  TimerValue @0x30009A80, TimerMilliSecStart/Value @0x30009B70/0x30009CCC, TimerStart_ID @0x30009DD0,
  USRCLK_GetCurTimerValue @0x30008890, USRCLK_GetClkId/GetClkNum @0x30009174/0x300092D0.
- CLK: Connect @0x30008DD0, Enable/Disable @0x30008DEC/0x30008E40, RateGet/RateSet @0x30008E6C/0x30008E78,
  Value @0x30008F04.
- 0x1B4E81B5 — константа реципрокного умножения (не адрес).

## 4. Порядок инициализации

Точка входа слоя — **BSP_DRV_BOOTROM_Init @0x30004B88** (тело полностью не дочитано; состав восстановлен
по doc-заголовкам «Вызывает» в usbl_src/src/bsp/*.c, порядок частично гипотетический):

1. ABB_UnReset @0x3000465C — вывод ABB из сброса через 0x90000048.
2. SPI_Init @0x3002D7E4 (включение клоков 0x90000988/0x90000944) — открывает доступ к PMU HI6451.
3. SSI_Init @0x3002F724 (каналы 0x90030000–0x90033000) — открывает ABB (ch2) и HKADC (ch3).
4. BSP_GPIO_Init @0x30034A34 — банки GPIO, таблицы колбэков.
5. hkadcInit @0x300407BC — семафор HKADC, подготовка SSI-протокола АЦП.
6. WDT_Init @0x30007448 (создание soft-WDT задачи prio 254 и семафора; выполняется и из BSP_WDT_Enable).
7. BSP_WDT_Stop @0x3000797C / BSP_WDT_Resume @0x300079A4 / BSP_WDT_Feed_Force @0x300077CC — управление
   унаследованным от bootrom watchdog (STOP/RESUME/кормление без семафоров, «голый» INTCLR).

Дальше по ходу VxWorks: BSP_HKADC_GetTempInit @0x300408DC (задача tHKADC prio 152), HI6451_init @0x30031624
(задача prio 100), softtimer_module_start @0x3000AAD8, BSP_USRCLK_Init @0x30008F2C, BSP_TLED_LedInit @0x30035C74,
CY22393 Init (I2C-клок-генератор), BSP_DRV_SubVicInit @0x30007B08 (суб-VIC) / SubVicIntHandler @0x30007B04.

**Семафоры/блокировки** (сводка):
| Подсистема | Механизм | Ячейка |
|---|---|---|
| HKADC | semB (Convert/GetTempTask) | 0x30181274 |
| WDT soft | semB (Feed → LowTask) | 0x3017D2C4 |
| SPI | intCpuLock (+ семафоры 0x30180430) | 0x30180430 |
| SSI | intCpuLock/Unlock, без семафора | — |
| HI6451 | semB + taskSpawn prio 100 | (в HI6451_init) |

## 5. Реконструкция таблиц каналов ADC

Таблица назначений (байты @0x30181178, [i] = канал HKADC для слота i):

| Слот | Канал | Датчик | Функция-читатель |
|---|---|---|---|
| 0 | 0 | резерв | — |
| 1 | 1 | LTE PA (мощность/темп.) | LtePAPowerRead / LtePATempRead / PaValueGet |
| 2 | 2 | резерв | — |
| 3 | 3 | SIM-температура | SIMTempRead (спец-LUT 19 пар (гип.: лимит перебора)) |
| 4 | 4 | резерв | — |
| 5 | 5 | TFT-температура | TftTempRead |
| 6 | 6 | батарея (напряжение) | BatVolRead (калибровка @0x30181264) |
| 7 | 7 | резерв | — |
| 8 | 8 | DCXO-температура | DcxoTempRead |
| 9–11 | 9–11 | резерв | GetTempTask-таблица до 12 каналов |

Записи фоновой задачи @0x30181118 (12×8): {u16 value; u8 valid@+2; u8 enable@+3; u32 резерв/LUT (гип.)}.
Сглаженные значения: 12×u32 @0x30181240 (SmthProc/SmthValGet).
Каналы >9 при передаче сдвигаются: ch += 4 (BSP_HKADC_Convert).

## 6. Открытые вопросы

1. 0x90000408 (магия 0x69200001) — точный смысл полей (WDT-клок-гейт? rescue-регистр?).
2. Блок 0x90002098/0x9000209C (лит. WDT-группы) — назначение; тела-потребители не дочитаны.
3. `*(*(0x3017D2E0)+0x114)=1` в reboot_direct — база (гип. PWRCTRL) хранится в рантайм-ячейке; подтвердить.
4. Хвост SPI_Lock/SPI_UnLock (@0x3002D9A4) — обрезан при выводе; семафоры 0x30180430 не сверены.
5. Пользователи SSI ch0/ch1 (0x90030000/0x90031000) — не найдены.
6. 0x90007000 как база ustimer — гипотеза, требует чтения BSP_USRCLK_Timer*.
7. Битовые поля GPIO-прерываний (+0x30…+0x4C) — сверить по BSP_GPIO_IntInstall/IntMaskSet/TriggerSet.
8. Писатель записей GetTempTask (0x30181118, enable-флаги) — не найден в этой области декомпилята.
9. Регион 0x22000000 (ABB_LineCtrl: 0x22000198–0x220001A0) — назначение неизвестно.
10. Единица результата BSP_WDT_TimeoutGet (формула LOAD/100 подтверждена, единица — нет).
11. BSP_PMU_*/HI6451_* — тела не дочитаны (BuckCtrl/LDOCtrl/ModeSwitch/RF_OnOff/IsWarmStart и др.).
12. BSP_DRV_BOOTROM_Init — полный список и точный порядок вызовов; тело не дочитано.
13. I2C DataTx/DataRx, TLED_* — тела не разобраны (адреса зафиксированы).
14. Ложные срабатывания первого скана: 0x6060E014/18 (BSP_ReportTest/BSP_SPI_Read/Write),
    0x00000BC4 у BSP_HKADC_Convert — артефакты регулярных выражений, в карту не включены.
