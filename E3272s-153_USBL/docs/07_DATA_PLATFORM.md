# 07. Данные платформы: таблица продуктов, версии, boot‑параметры

> Реконструкция по `usblsafe-327x.bin` (Huawei Balong V7R1, VxWorks 6.8).
> Адреса — VA (`VA = file_off − 0x3C0 + 0x30004000`); сырые данные читались из
> `usbl_payload_30004000.bin` (off = VA − 0x30004000). [гипотеза] — не подтверждено.

## 1. Таблица продуктов huaweiProduct

### 1.1. Расположение

- Записи: область **0x3012FAF0–0x3012FE64** (16 записей, шаг ≈0x30; границы записей
  определяются по слову‑идентификатору — точная выравненность ниже помечена [гипотеза]).
- Строковый пул: **0x3012FE80–0x3012FFDC** (`MPWUDP`, `E392s`, `CH1E392DM`, `B710S0`,
  `E3276s-210`, … `GL04P`, `PV500`, `PORTING`, `T`).
- Рядом (0x30130028–0x30130060) — ключи NV‑итемов: `PRODUCT_NAME`, `PRODUCT_NAME_PLUS`,
  `HW_VER`, `DLOAD_ID`, `PRODUCT_ID` (по ним product info читается из NV, см. docs/06).

### 1.2. Найденные записи (прямое чтение слов образа)

| id (слово) | PRODUCT_NAME | PRODUCT_NAME_PLUS | DLOAD_ID | HW_VER | внутр. имя | b0 | b1 |
|---|---|---|---|---|---|---|---|
| 0x00000001 | E5776s | MPWUDP | CL1E5776SF | B710D0 | 102HW | 0x00000401 | — |
| 0x00000101 | E5776s-860 | MPWUDP | CL3E5776SM | B710D0 | E5776s | 0x00000101 | 0x00000004 |
| 0x00000101¹ | E5776s-71 | MPWUDP | CL1E5776SS | B710D0 | GL04P | 0x00000101 | 0x00000004 |
| 0x00000200 | E3276s-210 | MPWUDP | CH2E3276SM | B710S0 | E3276 | 0x00EC0081 | 0x00080044 |
| 0x00000201 | E3276s-150 | MPWUDP | CH1E3276SM | B710S0 | E3276 | 0x00EC008B | 0x00080045 |
| 0x00000202 | E3276s-861 | MPWUDP | CH3E3276SM | B710S0 | E3276 | 0x00EC0001 | 0x000000E0 |
| 0x00000203 | E3276s-920 | MPWUDP | CH2E3276SM | B710S0 | E3276 | 0x00EC0081 | 0x000000A0 |
| 0x00000204 | E3276s-601 | MPWUDP | CH2E3276SM | B710S0 | E3276 | 0x00EC0081 | 0x00000044 |
| 0x00000205 | E3276s-151 | MPWUDP | CH1E3276SM | B710S0 | E3276 | 0x00EC008B | 0x0008004C |
| 0x00000206 | E3276s-500 | MPWUDP | CH1E3276SM | B710S0 | E3276 | 0x00EC001B | 0x0000005A |
| 0x00000207 | E3276s-152 | MPWUDP | CH1E3276SM | B710S0 | E3276 | 0x00EC0081 | 0x00080040 |
| 0x00000301 | E3272S-153 | MPWUDP | CH1E3272SM | B710S0 | E3272 | 0x00960081 | 0x000800C4 |
| 0x00000306 | E3272S-600 | MPWUDP | CH1E3272SM | B710S0 | E3272 | 0x00960091 | 0x000000C5 |
| 0x0000FFFD | PV500 | PV500 | PV500 | — | — | — | — |
| 0x0000FFFE | PORTING | PORTING | PORTING | PORTING | — | — | — |
| 0x0000FFFF | MPWUDP | MPWUDP | MPWUDP | MPWUDP | MPWUDP | — | — |
| — | E392s | MPWUDP | CH1E392DM | B710S0 | E392 | 0x00EC0085 | 0x000800C5 |

¹ у E5776s‑71 и E5776s‑860 одинаковый id‑байт (0x01) — различаются DLOAD_ID/HW_VER [гипотеза:
приоритет выбора по DLOAD_ID/PCB].

**Интерпретация id** [гипотеза, согласуется с сообщением `u16IdMain=0x%x u16IdSub=0x%x`
@file 0x12C454]: id = (idMain << 8) | idSub, где idMain — старший байт слова, idSub — младший:
E3276s‑210 → (0x02, 0x00); E3272S‑153 → (0x03, 0x01); E5776s‑860 → (0x01, 0x01).
Спец‑записи: 0xFFFD (PV500/GL04P — OEM‑имена), 0xFFFE (PORTING — отладочная),
0xFFFF (MPWUDP — значение по умолчанию для неизвестного id).

### 1.3. Реконструкция структуры записи [гипотеза]

```c
struct huaweiProduct {           /* шаг ~0x30 байт */
    uint32_t id;                 /* +0x00 (idMain<<8)|idSub, либо 0xFFFF-дефолт */
    char    *productName;        /* +0x04 "E3276s-210"        (PRODUCT_NAME)   */
    char    *namePlus;           /* +0x08 обычно "MPWUDP"     (PRODUCT_NAME_PLUS) */
    char    *dloadId;            /* +0x0C "CH2E3276SM"        (DLOAD_ID)       */
    char    *hwVer;              /* +0x10 "B710S0"/"B710D0"   (HW_VER)         */
    char    *innerName;          /* +0x14 "E3276"/"E3272"/"102HW"/"GL04P"       */
    uint32_t bands0;             /* +0x18 маска GU/диапазонов (0x00EC0081…)   */
    uint32_t bands1;             /* +0x1C LTE-маски (0x00080044…)             */
    uint32_t bands2;             /* +0x20 0x20/0x44/0x80/0xA0/0xC4/0xC5/0xE0    */
};
```

Основание: строки `product name / product inner name / product download name /
hardware version / pcb version` + `support bands: GU:%#x LTELow:%#x LTEHigh:%#x`
(@file 0x12C4BC–0x12C5D0) и функции `BSP_GetProductName`, `BSP_GetProductDloadName`,
`BSP_GetSupportBands` (docs/02). Маски бэндов: 0x00EC/0x0096 — группы GU [гипотеза],
0x0008xxxx — LTE low/high [гипотеза].

### 1.4. Кто использует

- `BSP_ProductInfoInit` (docs/02, порядок BSP) — заполнение product info из таблицы + NV;
- `BSP_USB_UpdateDevPidInfo` @0x3005A520 (docs/03 §4) — PID USB на профиль;
- `BSP_GetMacAddr`, `BSP_GetSupportBands*` — отдают значения в AT/shell.

## 2. Версии и идентификаторы

| Строка | VA (file) | Комментарий |
|---|---|---|
| `BalongV%03dR%03dC%02dSPC%03dB%03d %s` | 0x3012C65C (0x12CA1C) | формат версии Balong (V/R/C/SPC/B) |
| `BalongV%03dR%03dC%02dB%03d %s` | 0x3012C694 (0x12CA54) | вариант без SPC |
| `BalongV%03dR%03dC%02dB%03d` | 0x3012C6C4 (0x12CA84) | короткий вариант |
| `H69DUSA` | 0x3012C2D4 (0x12C694) | hw‑id платы |
| `H69DUSAVA` | 0x301442C0 (0x140680) | hw‑id + вариант |
| `HI6920` | 0x301355D0 (0x131990) | имя чипа |
| `set VSB_DIR BALONGV7R1.LIB` | 0x3017632C (0x1766EC) | платформенная сборка VxWorks‑BSP |
| ` Ver.X`, `PORTING` | 0x3012C4AC, 0x3012C390 | поля вывода версии |

**Открытый вопрос:** прямых ссылок из литеральных пулов кода на строку формата
`BalongV…` в образе не найдено (поиск слов == VA дал 0 совпадений) — вероятно,
строка собирается/используется косвенно (или ссылка идёт со смещением).
Ищите в функциях с строками `BSP_GetBuildVersion`/`BSP_GetBootBuildVersion` (docs/02).

## 3. Boot‑параметры (VxWorks BOOT_PARAMS)

Две таблицы имён полей (для `bootParamsShow` и `bootParamsPrompt`):

- 0x3011E7F0: `unit number`, `processor number`, `host name`, `file name`,
  `inet on ethernet (e)`, `inet on backplane (b)`, `host inet (h)`,
  `gateway inet (g)`, `user (u)`, `ftp password (pw)`, `flags (f)`,
  `target name (tn)`, `startup script (s)`, `other (o)`;
- 0x3011E9DC: тот же порядок, без `unit number`, `pw` с пояснением
  `(blank = use rsh)` — вариант для bootrom‑режима.

Строки‑подсказки полей: 0x301AFCEC–0x301AFDE0 (`unit number`, `host name`, …).

**Строка загрузки по умолчанию** (@file 0x12A448, VA 0x3012A088):

```
HiLteFe(0,0) host:vxWorks h=192.168.255.2 e=192.168.255.1:ffffff00 u=anonymous pw= tn=targetname
```

— устройство `HiLteFe(0,0)` (front‑end LTE), host `vxWorks`, IP 192.168.255.2,
ethernet 192.168.255.1/24, user anonymous. Сетевого стека в образе нет (docs/05 §1),
поэтому параметры — совместимость/наследство BSP [гипотеза].

Структура (стандарт VxWorks, порядок подтверждён таблицей имён) [гипотеза по размерам]:

```c
struct bootParams {
    char bootDev[30];      /* "HiLteFe(0,0)" */
    char hostName[30];     /* "host"        */
    char targetName[30];   /* "vxWorks"     */
    char ead[30];          /* "192.168.255.2"       (e) */
    char bad[30];          /* ""                    (b) */
    char had[30];          /* "192.168.255.1"       (h) */
    char gad[30];          /* ""                    (g) */
    char usr[30];          /* "anonymous"           (u) */
    char passwd[30];       /* ""                    (pw) */
    char other[30];        /* ""                    (o) */
    int  unit;             /* (0)  */
    int  processorNum;     /* 0    */
    int  flags;            /* (f)  */
};
```

## 4. Модуль `data`: что внутри (2120 функций)

Модуль `data` — это всё, что не попало в именные подсистемы: OS‑адаптация,
обработчики, утилиты, обвязка. Топ по числу вызовов (fan‑in, из `index/ALL_FUNCTIONS.tsv`):

| Функция | Адрес | Callers | Роль |
|---|---|---|---|
| `os_printf` | 0x3005C0E8 | 227 | printf порта (в os_*) |
| `os_dprintf` | 0x3005C21C | 227 | debug‑printf |
| `valid_type` | 0x30041CF8 | 213 | проверка типа объекта VxWorks |
| `objVerify` | 0x300A8DA4 | 100 | верификация объектов ядра |
| `OSAL_LogMsg` | 0x30017DD4 | 96 | Huawei‑логирование |
| `lstFirst`/`lstNext`/`lstAdd`/`lstDelete`/`lstCount` | 0x3011EC28… | 78/70/34/30/27 | двусвязные списки |
| `printErr` | 0x300C3FA8 | 74 | печать errno |
| `strncpy` | 0x300BDE90 | 67 | libc |
| `os_panic` | 0x3005C168 | 64 | паника порта |
| `windExit` | 0x300A9AC4 | 60 | выход из ядра |
| `ioctl`/`close`/`open` | 0x300E7FEC/0x300E7EB4/0x300E7EAC | 56/45/38 | IOS VxWorks |
| `os_bus_space_read_4` | 0x3005BE28 | 29 | MMIO (порт) |
| `omTimerTickGet` | 0x30099870 | 29 | тики таймера |

Глобальные группы имён по всему образу (навигация): `FUN_` 1282, `BSP_` 311,
`yaffs` 151, `QC_` 65, `os_` 60, `nandc` 42, `HI6451` 40, `nand` 33, `ptable` 32,
`TFUP` 29, `core` 27, `jos` 26, `Lnvm` 24, `nn` 22, `Read` 20, `sda` 19, `yaffs2` 18,
`PWRCTRL` 16, `nvim` 15, `WDT` 14, `crypto` 14, `cdc` 14, `uwd` 14, `NVM` 13, `Lnv` 13.

## 5. Открытые вопросы

1. Точная геометрия записи `huaweiProduct` (шаг/порядок полей) — снять по декомпилу
   `BSP_GetProductName`/`BSP_GetSupportBands`/`BSP_ProductInfoInit` (адреса — docs/02).
2. Семантика `bands0/bands1/bands2` (GU/LTE‑маски) — подтвердить по `BSP_GetSupportBands`.
3. Где формируется строка `BalongV%03dR…` (см. §2) и откуда берутся V/R/C/SPC/B
   (константы сборки или NV‑итемы).
4. Значения `sysBootParams` по умолчанию в .data (адрес переменной) — найти
   инициализатор (grep по строке `HiLteFe`).
5. Назначение `0x301815BC` (таблица 0x30000, 0x1C05, 0x808080, 6,6,1,6…) из docs/03 §7.
