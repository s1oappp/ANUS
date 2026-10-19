# 05. Ядро VxWorks и командный shell

> Реконструкция по `usblsafe-327x.bin` (Huawei Balong V7R1, VxWorks 6.8, сборка 17.05.2013).
> Адреса — VA (`VA = file_off − 0x3C0 + 0x30004000`). [гипотеза] — не подтверждено напрямую.

## 1. Инвентарь подсистем ядра

Подсчёт по таблице символов (`usbl_src/index/ALL_FUNCTIONS.tsv`, 5171 функция);
колонка — число символов, начинающихся с указанных префиксов:

| Подсистема | Префиксы | Символов |
|---|---|---|
| Задачи/планировщик | `task*` | 86 |
| Семафоры | `sem*` | 55 |
| Исключения/векторы | `exc*` | 63 |
| IOS / pipe / ty / select | `ios* io[A-Z]* pipe* ty[A-Z]* select*` | 113 |
| Символьная таблица | `sym*` | 28 |
| cplus (C++) | `cplus*` | 21 |
| ED&R (Huawei debug/error record) | `edr* Edr* EDR*` | 11 |
| env (переменные окружения) | `env*` | 5 |
| wdb (таргетный отладчик) | `wdb* Wdb*` | 7 |
| dosFs/cbio/tffs | `dosFs* dosVol* cbio* tffs*` | 36 |
| **Сеть** (tcp/udp/ip/icmp/arp) | — | **0** |
| mbuf/net/if | — | 1 |
| socket | — | **0** |
| route/host | — | **0** |
| nfs | — | **0** |
| posix/mq | — | **0** |

**Вывод:** сетевого стека в образе **нет** (ни `tcp_*`, ни `socket`, ни `mbuf`,
ни `if_*` — 0 символов). Строки `netHelp`/`nfsHelp`/`hostAdd` в shell‑каталоге (§4) —
это **штатный текст справки VxWorks shellLib**, скомпилированный в библиотеку,
а не признак наличия подсистем. FTP‑элементы в boot‑параметрах (docs/07) —
тоже лишь шаблон VxWorks. Вся связь с внешним миром идёт через USB (docs/03) и AT/DLOAD (docs/04).

`posix/mq` отсутствуют — shell и приложения используют нативные VxWorks API (task/sem/msgQ).
36 символов `dosFs/cbio/tffs` — вероятно, cbio‑слой для NAND/SD [гипотеза]; фактическое
монтирование — YAFFS (docs/06).

## 2. Конфигурация ядра

| Параметр | Значение | Источник |
|---|---|---|
| Частота системного тика | **100 Гц** (`sysClkRateSet(100)`) | decompiled_all.c, единственный вызов с константой (второй сайт — `param_1`) |
| Первичный пул памяти ядра | **0xBB0 байт** (`memInit(p1,p2,0xbb0)`) | usrRoot |
| Стек root‑задачи | 0x4000 | блок параметров `kernelInit` (см. docs/01 §4.1) |
| Вторичный пул | `memAddToPool(*0x301292A0, *0x3012929C)`; слова‑указатели: 0x3012929C → **0x301C85AC**, 0x301292A0 → **0x301C8590** (BSS, за образом) | usrRoot; значения инициализируются в рантайме |
| `sysAuxClkRateSet` | вызывается с `param_1` (переменная) | decompiled_all.c |
| MMU | включается поздно, в `usrMmuInit`@0x3003FCE4 (из usrRoot) | docs/01 §4.3 |

Стек `usrAppInit`‑блока (BSP_DRV_BOOTROM_Init) создаёт рабочие задачи:
`tUSBTask` (prio 0x50), `tDloadTask` (prio 0x51), `tIdletask` (prio 0xFF) —
подробности в docs/01 §5.

## 3. Shell: инициализация и интерпретатор

| Функция | Адрес | Роль |
|---|---|---|
| `shellLibInit` | 0x3010D7C8 | инициализация библиотеки shell |
| `shellGenericInit` | 0x3010E108 | создание shell‑задачи и привязка ввода-вывода |
| `shellTask` | 0x301105C4 | тело задачи tShell0 |
| `shellTaskDefaultPriorityGet` | 0x3010DA38 | приоритет по умолчанию |
| `shellTaskDefaultStackSizeGet` | 0x3010DC78 | размер стека по умолчанию |
| `shellInterpC*` | (9 символов) | C‑интерпретатор VxWorks (выражения/вызовы функций) |

Сайты `shellGenericInit` (7 вариантов вызова, из них внешние):
- `shellGenericInit(DAT_30005098, 0, 0, &local_14, 0, 0, __fd, 1, 2)` — запуск
  через файловый дескриптор `__fd` (в BSP это стык с `/dev/shell/…`);
- варианты `(0,0,0,DAT_3000e9f4,1,0,…)` и `(0,0x10000,0,0,1,0,…)` — реентерабельные
  обёртки shellLib.

**Автозапуск скрипта.** В строках образа присутствует сценарий
`shtask` → `/yaffs0/ksscript.s` → `INTERPRETER=C` с сообщением об ошибке
`unable to execute startup script: ksscript.s` (строки @file 0x12A4AC–0x12A4DA).
Т.е. при наличии `/yaffs0/ksscript.s` shell исполняет его на C‑интерпретаторе
при старте; в чистой прошивке файла может не быть — отсюда штатное сообщение [гипотеза].

В этой сборке стандартные stdin/stdout/stderr VxWorks привязаны к serial channel 0
(см. `usrSerialInit` в docs/01 и UART в docs/08). Статический USB‑профиль PID
`0x1C05` содержит MODEM+DIAG+PCUI и не содержит `DEVICE_FD_SHELL`; наличие типа
SHELL в таблице USB‑каналов само по себе не доказывает USB-доступ к интерактивному
shell. В коде есть runtime/NV-ветвления, поэтому состав всех возможных профилей
не установлен. См. исследовательское уточнение
[`research/e3272-shell-access/analysis.md`](../../research/e3272-shell-access/analysis.md).

## 4. Каталог встроенных команд shell

Таблица help‑строк: последовательность указателей на 40 NUL‑строк, начинается
@VA **0x301AFB40** (первый указатель 0x3015F617 → `"help … Print this list"`).
Это **типовой набор VxWorks 6.8 shellLib**:

`help`, `dbgHelp`, `edrHelp`, `ioHelp`, `nfsHelp`, `netHelp`, `rtpHelp`, `spyHelp`,
`timexHelp`, `h` (история), `i`/`ti` (TCB), `sp`/`taskSpawn` (запуск задачи),
`tip`, `td`/`ts`/`tr`/`tw`/`w` (управление задачами), `d`/`m` (память),
`mRegs`, `pc`, `iam`/`whoami`, `devs`, `ld`, `lkup`/`lkAddr` (символы),
`checkStack`, `printErrno`, `period`/`repeat`, `version`, `shConfig`, `strFree`,
плюс строки `NOTE:` и примеры `hostAdd`/`netDevCreate` (тексты справки).

Наличие `nfsHelp`/`netHelp`/`rtpHelp` — **только текст** (подсистем нет, §1).
Символы `rtp*` также отсутствуют — строка осталась от shellLib.

## 5. Команды BSP (расширение shell)

Huawei‑команды зарегистрированы как **символы** в встроенной таблице (узлы
`{name, value, 0, 0x00050000}` в области 0x3018xxxx–0x3019xxxx), поэтому
C‑интерпретатор вызывает их по имени. Пример подтверждённой записи:
`BSP_SetLogLevel` (имя @VA 0x30162FD0) → функция **0x30005294** (узел @0x301934CC).

Каталог имён (строки @file 0x15E653+, VA 0x3015E2D3+ и лог‑команды @0x12A799+):

- **Логирование**: `BSP_ClearLogModule`, `BSP_SetLogModule`, `BSP_GetLogModule`,
  `BSP_SetLogLevel`, `BSP_GetLogLevel`, `BSP_SetPrintPos`, `BSP_GetPrintPos`,
  `BSP_ErrnoGet`, `BSP_TaskErrnoGet` (параметры: `enModule`, `enLogLevel`,
  `bPrintPos`, `taskId`; справка — таблица «log command list» @file 0x12A799);
- **Идентификация**: `BSP_GetBuildVersion`, `BSP_GetBootBuildVersion`,
  `BSP_GetProductName`, `BSP_GetProductInnerName`, `BSP_GetProductDloadName`,
  `BSP_GetSupportBands`, `BSP_GetSupportBandsForGu`, `BSP_GetMacAddr`, `BSP_HwGetHwVers`;
- **GPIO**: `BSP_GPIO_DrcGet/DrcSet`, `ValGet/ValSet`, `Init`, `PinModeCtrl`,
  `IntInstall/IntUnInstall`, `IntMaskSet/IntUnMaskSet`, `IntStateGet/Clear`,
  `IntTriggerSet`, `RawIntStateGet`, `PWC_Reg_Save/Restore`, `GetVersion`;
- **HKADC**: `BSP_HKADC_BatVolRead`, `BatADCRead`, `BatTempRead`, `LtePA…`,
  `Convert`, `GetSystemTemperature`, `TemVoltTrans`, `Test` и др.;
- **Прочее**: `BSP_LDScript`, `BSP_SdmmcAddHook`, `BSP_DRV_BOOTROM_Init` (не команда,
  а точка входа инициализации — см. docs/01).

Полный список — `usbl_src/index/STRINGS_BY_MODULE.md` (раздел bsp) и таблица символов.

## 6. Открытые вопросы

1. Точная семантика `memAddToPool`‑пула: значения лежат в BSS (0x301C8590/0x301C85AC)
   и инициализируются кодом до `usrRoot` — найти инициализатор (grep по этим адресам).
2. Роль 36 символов `dosFs/cbio/tffs` — используется ли cbio для SD (sda) или это
   мёртвый код/строки.
3. Приоритет/стек `tShell0` по умолчанию (конфиг‑слова shellLib в .data —
   `shellTaskDefaultPriorityGet`/`StackSizeGet` читают их в рантайме).
4. Список команд, реально доступных вшелле в burn‑режиме (зависит от таблицы символов
   на момент запуска; часть BSP‑символов может быть скрыта).
5. `sysAuxClkRateSet(param_1)` — фактическое значение (вызов с переменной).
