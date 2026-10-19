# 04. Протоколы загрузки USBL: AT-интерфейс, DLOAD (USB), TFUP (TF-карта)

**Объект:** usblsafe-327x.bin — USB-загрузчик («прошивальщик») Huawei Balong V7R1,
устройство E3272s-153, версия ПО 21.431.99.07.00, ОС VxWorks 6.8.
**Карта памяти:** VA = file_off − 0x3C0 + 0x30004000 (payload `usbl_payload_30004000.bin`, 1 753 484 б).
**Статус документа:** черновик → уточняется; часть данных проверена дампами из
предыдущей сессии (таблицы, CRC), часть помечена как вывод [INF] или открытый вопрос [TBD].
**Дисциплина пометок:**
- [VER] — проверено дампом/кодом (адрес, содержимое таблицы, вызовы);
- [INF] — вывод из косвенных данных (размеры, набор вызовов), требует подтверждения;
- [TBD] — не проверено, открытый вопрос (см. §8).

Источники: `usbl_src/src/dload/dload_01.c` (75 функций с doc-заголовками),
`usbl_src/src/bsp/bsp_03.c` (BSP_DLOAD_*), `usbl_src/src/data/data_05.c`, `data_06.c`
(ATCommandHandle/Process, ImageDload*), `usbl_src/src/flash/flash_0*.c`,
`usbl_src/index/ALL_FUNCTIONS.tsv`, `firmware_strings.txt`, дампы таблиц прошлой сессии
(scratch_attable.py, scratch_atproc.py, scratch_crc.py).

---

## 1. Обзор: четыре пути заливки

Все пути сходятся в общий исполнительный конвейер «буфер → dynFSDloadProcess → flash»:

| Путь | Вход | Главные функции | Кто запускает |
|---|---|---|---|
| USB DLOAD (пакетный протокол поверх HDLC) | USB VCOM, режим данных после `AT^DATAMODE` | `dloadUSBCallback` → `FUN_30080798` → `imageDloadProcess`/`dynFSDloadProcess` | задача tDloadTask (вход `0x30075EFC`, prio 0x51) [VER: контекст предыдущей сессии] |
| AT-команды загрузчика | те же USB VCOM, текстовые строки | `ATCommandProcess`/`ATCommandHandle` | тот же поток, до перехода в data-mode [VER] |
| TF-карта (TFUP) | файл на microSD | `TFUP_CheckTask` → `TFUP_DloadTask` → `dloadTFPro` → `imageDloadProcess`/`dynFSDloadProcess` | `sdmmcAddHook`-колбэк на вставление карты [VER: вызовы] |
| ФС устройства (WebUI/CD-ROM) | файл из ФС | `dloadFromFsMainThread` → `dynFSDloadProcess` | `update_WebUITask` [VER: «Вызывают»] |

Инициализация: `dloadInit` @ `0x30076BA8` (792 б, 13 вызовов: `DCBInit`, `Om_HdlcInit`,
`OSAL_SemBCreate`, `dload_nand_init`, `drvSecCheck`, `getFactoryMode`, `sdmmcAddHook`,
`TFUP_getTFUpdateFlag`, `taskSpawn`, `malloc/free`) — вызывается из `BSP_DRV_BOOTROM_Init`
[VER: doc-заголовок «Вызывают: BSP_DRV_BOOTROM_Init»]; в контексте проекта зафиксировано,
что цепочка ведёт от `usrRoot`. `dloadInit` спавнит задачу с входом `0x30075EFC` [INF: taskSpawn
в списке вызовов + 0 вызывающих у 0x30075EFC в ALL_FUNCTIONS.tsv].

**Важно об именах:** в symbols.csv адрес `0x30075EFC` подписан `BSP_DLOAD_Init`
(884 б, 9 вызовов: `BSP_Find_VCOM`, `open`, `ioctl`, `semBCreate`, `taskDelay`, …),
0 прямых вызывающих — это классический профиль **входной функции задачи** (task entry),
спавнимой как `tDloadTask` с приоритетом 0x51 [VER: TSV + doc-заголовок; приоритет — VER из
контекста]. Ниже обозначаем её `tDloadTask` (0x30075EFC, симв. BSP_DLOAD_Init).

---

## 2. AT-интерфейс загрузчика

### 2.1. Два уровня разбора

**Уровень 1 — точное сравнение строк** (таблица `ATCommandProcess`, VA `0x30149244`,
11 пар «строка с \r» → код режима) [VER: дамп scratch_atproc.py]:

| # | Строка (с `\r`) | mode |
|---|---|---|
| 0 | `ATE0\r` | 0x0 |
| 1 | `ATE1\r` | 0x1 |
| 2 | `AT^DLOADVER?\r` | 0x2 |
| 3 | `AT^DLOADINFO?\r` | 0x3 |
| 4 | `AT^AUTHORITYVER?\r` | 0x4 |
| 5 | `AT^AUTHORITYID?\r` | 0x5 |
| 6 | `AT^DATAMODE\r` | 0x6 |
| 7 | `AT^HWNATQRY?\r` | 0x7 |
| 8 | `AT^FLASHINFO?\r` | 0x8 |
| 9 | `AT+CMEE=0\r` | 0x9 |
| 10 | `AT^GODLOAD\r` | 0xA |

Потребитель таблицы — `ATCommandProcess` @ `0x3007FCE4` (data_05.c, 292 б, 5 вызовов) [VER: TSV].
Её вызывает `dloadUSBCallback` @ `0x30081C80` (вместе с `Om_HdlcDecap` — то есть AT-строки
приходят в HDLC-декапсулированном потоке) [VER: doc-заголовок]. Сама `ATCommandProcess`
сравнивает через `strnicmp` (регистронезависимо) и передаёт mode в `ATCommandHandle`
@ `0x3007F944` (928 б, 3 вызова), который формирует ответ через `dloadUSBSend` [VER:
doc-заголовки data_05.c].
Таблица лежит в данных: строки @ `0x3014957C…0x30149610`, терминатор-строка
`"\r\nERROR\r\n"` @ `0x301494CC` [VER: дамп].

**Уровень 2 — таблица обработчиков** (VA `0x30154FB8`, записи по 12 б `{func, char* str, int w2}`,
w2 = 0 у всех записей, конец — str=NULL) [VER: дамп scratch_attable.py, 16 записей].
Поиск по таблице — `atFindFunc` @ `0x3009B234` (180 б) [VER: TSV]. Обработку совпадений
обеспечивает связка `atCheckStr` @ `0x3009AF7C` (404 б) — сравнение с учётом `?`/`=`-форм,
`atProcUpString` @ `0x3009B110` (120 б) — верхнеуровневая обработка принятой строки,
`atFormatStr` @ `0x3009B188` (84 б) — нормализация строки, `atCmpATStr` @ `0x3009B1DC` (88 б) —
сравнение [VER: адреса/размеры; точное распределение ролей — INF, см. §8].

### 2.2. ПОЛНАЯ таблица команд (уровень 2, @0x30154FB8)

[VER: полный дамп таблицы, 16 записей, конец по NULL]

| # | Команда | Обработчик | Адрес | Назначение / ответ |
|---|---|---|---|---|
| 0 | `AT^DLOADVER?` | `atQryDLoadVerBr` | 0x3009A728 (396 б) | версия DLOAD; ответ через `dloadUSBSend` [INF] |
| 1 | `AT^DLOADINFO?` | `atQryDLoadInfoBr` | 0x3009A8B4 (780 б) | полная инфо-строка: см. `BSP_DLOAD_GetDloadInfo` |
| 2 | `AT^AUTHORITYVER?` | `atQryAuthorityVerBr` | 0x3009ABC0 (408 б) | версия авторизации (`BSP_DLOAD_GetAuthorityVer`) |
| 3 | `AT^AUTHORITYID?` | `atQryAuthorityIDBr` | 0x3009AD58 (464 б) | ID авторизации (`BSP_DLOAD_GetAuthorityId`) |
| 4 | `AT^DATAMODE` | `atSetDataModeBr` | 0x3009AF28 (48 б) | переход в режим данных DLOAD (см. §3.4) |
| 5 | `AT^BOOTROMVER?` | `atQryBootRomVerBr` | 0x3009A588 (416 б) | версия bootrom (`BSP_DLOAD_GetBootromVer`) |
| 6 | `AT^BOOTROMVER=?` | `atTestOK` | 0x3009AF58 (28 б) | тест-формы: ответ OK |
| 7 | `AT^DLOADVER=?` | `atTestOK` | 0x3009AF58 | ответ OK |
| 8 | `AT^DLOADINFO=?` | `atTestOK` | 0x3009AF58 | ответ OK |
| 9 | `AT^AUTHORITYVER=?` | `atTestOK` | 0x3009AF58 | ответ OK |
| 10 | `AT^AUTHORITYID=?` | `atTestOK` | 0x3009AF58 | ответ OK |
| 11 | `AT^DATAMODE=?` | `atTestOK` | 0x3009AF58 | ответ OK |
| 12 | `ATE0` | `atTestOK` | 0x3009AF58 | ответ OK (эхо off) |
| 13 | `AT` | `atTestOK` | 0x3009AF58 | ответ OK |
| 14 | `AT^GETSDM` | `atGetSdmBr` | 0x3009AF74 (8 б) | заглушка [INF: размер 8 б] |
| 15 | `ATE1` | `atTestOK` | 0x3009AF58 | ответ OK (эхо on) |

Команды уровня 1, отсутствующие в таблице уровня 2 (`AT^HWNATQRY?`, `AT^FLASHINFO?`,
`AT+CMEE=0`, `AT^GODLOAD`), обрабатываются через mode-ветвление в `ATCommandHandle`
@ `0x3007F944` (data_05.c, 928 б, 3 вызова) [VER: TSV; распределение — INF].
`AT^GODLOAD` — «немедленно уйти в DLOAD» (mode 0xA) [INF по имени и контексту].

### 2.3. Конструкторы ответов

- `atBuildResult` @ `0x3009A264` (252 б) — сборка произвольного результата [VER: TSV];
- `atBuildOK` @ `0x3009A360` (88 б), `atBuildERROR` @ `0x3009A3B8` (104 б);
- `atSendOK2PC` @ `0x3009A420` (204 б), `atSendERR2PC` @ `0x3009A4EC` (156 б) — отправка ПК;
- подтверждённый формат ошибки: строка `"\r\nERROR\r\n"` @ `0x301494CC` [VER: дамп];
- ожидаемый формат OK: `"\r\nOK\r\n"` [TBD — подтвердить по STRINGS_BY_MODULE/телам].

Найденный форматный ответ: `^HWNATQRY:%d` (file_off `0x145902` ≈ VA `0x30149542`, рядом
с таблицей уровня 1) [VER: firmware_strings.txt]. Строк вида `^DLOADVER:` в прошивке не
найдено — ответы на запросы версий, вероятно, уходят блоками данных (не AT-текстом)
через `dloadUSBSend`/`dloadUSBSendPro` [INF] — см. §8, вопрос 1.

### 2.4. Как работает парсер (сводка)

1. USB-RX колбэк `dloadUSBCallback` @ `0x30081C80` принимает кадр, `Om_HdlcDecap`
   снимает HDLC-инкапсуляцию, передаёт строку в `ATCommandProcess` [VER: вызовы].
2. `ATCommandProcess` (data_05.c) ищет **точное** совпадение в таблице @ `0x30149244`
   (включая завершающий `\r`) и возвращает mode [VER: формат таблицы].
3. Параллельный/альтернативный путь: `atProcUpString` → `atFormatStr`/`atCheckStr` →
   `atFindFunc` линейно обходит таблицу @ `0x30154FB8` и вызывает обработчик
   `func(…)` [VER: таблица и адреса; точная последовательность вызовов — INF].
4. Ответ собирается `atBuildOK`/`atBuildERROR`/`atBuildResult` и уходит через
   `atSendOK2PC`/`atSendERR2PC` → `dloadUSBSend` @ `0x30076850` → `BSP_DLOAD_SendData`
   @ `0x30075010` [VER: цепочка вызовов doc-заголовков].
5. `ATE0`/`ATE1` переключают эхо (mode 0/1), `AT^DATAMODE` (mode 6) — терминатор
   AT-диалога, после него поток данных уходит в DLOAD-обработку [INF].

---

## 3. DLOAD-протокол (USB, режим данных)

### 3.1. Задача и инициализация

- `tDloadTask` — вход `0x30075EFC` (симв. `BSP_DLOAD_Init`), приоритет 0x51 [VER: контекст
  предыдущей сессии + профиль функции: `semBCreate`, `open/ioctl` VCOM-устройства,
  `taskDelay` — цикл опроса; 0 прямых вызывающих в TSV].
- Спавн из `dloadInit` @ `0x30076BA8` (taskSpawn в списке вызовов) [VER + INF на аргументы].
- USB-приём: колбэк `dloadUSBCallback` @ `0x30081C80`, зарегистрирован через
  `FUN_30075e48` (вызывается из `tDloadTask`) [VER: «Вызывают: FUN_30075e48»].

### 3.2. Приём пакета

`dloadUSBCallback`: `Om_HdlcDecap` → `ATCommandProcess` (если AT-строка) или
`FUN_30080798` (если данные) [VER: список вызовов]. Разграничитель — режим
(databoot flag), установленный `AT^DATAMODE` [INF].

### 3.3. Обработка пакета: FUN_30080798 (главный процессор)

`FUN_30080798` @ `0x30080798`, 5352 б, 27 вызовов [VER: TSV/doc-заголовок]:
`DCBInit`, `Om_HdlcInit`, `DLOAD_LEDInd`, `HighToLow` (порядок байт!), `OSAL_LogMsg`,
`dloadBootromEnd`, `dloadInitRamBuffer`, `dloadNeedMidwayRestart`, `dloadUSBSendPro`,
`dload_GetISOUseableSize`, `dynFSDloadProcess`, `BSP_DLOAD_SetCdromMarker`, `fclose/fopen`.

- Наличие `HighToLow` [INF: конверсия big↔little endian в заголовках пакетов].
- Наличие `dloadNeedMidwayRestart` + `dloadBootromEnd` [VER] — обработчик участвует
  в завершении сессии (§4, §6).
- Ответы уходят через `dloadUSBSendPro` @ `0x3007FE10` (2148 б): `Om_HdlcEncap`,
  `getDloadID`, `BSP_DLOAD_GetSoftwareVer`, `update_record_file` [VER: вызовы] —
  т.е. ответы тоже HDLC-инкапсулируются.

### 3.4. Переход в режим данных

`AT^DATAMODE` → `atSetDataModeBr` @ `0x3009AF28` (48 б) [VER]. Устанавливает флаг
data-mode, после которого USB-поток трактуется как DLOAD-пакеты [INF]. Обратный выход
из data-mode в AT в этом загрузчике не обнаружен [TBD, вопрос 5].

### 3.5. Структура пакета

- Кадрирование: HDLC (`Om_HdlcDecap`/`Om_HdlcEncap` — модуль Om; флаги 0x7E — TBD, вопрос 2).
- Целостность: **CRC-16 PPP-FCS** (отражённый алгоритм; init 0xFFFF, poly 0x8408):
  проверка на 7/7 тестовых образцах из прошивки [VER: scratch_crc.py, сессия 19.10.2026];
  остальные кандидаты (CCITT-FALSE, XMODEM, MODBUS, SUM16, IBM-ARC…) не совпали ни разу.
- Юниты на пути ФС сжаты gzip: `get_uncompress_length` @ `0x30086C74` →
  `gzgetUncompressLength`; `uncompress_file_to_stream` @ `0x30086CA0` →
  `gzuncompressFileToStream` [VER: вызовы data_06.c]; для USB/TF-путей сжатие не
  подтверждено [TBD].
- `TFUP_GetUnitCRC` возвращает 16-битное значение (`uVar4 & 0xffff`) [VER: тело],
  `TFUP_ValidateCRCWithCRCList` использует `CalculateCRC` + `memcmp` [VER: вызовы].
- Точная раскладка полей заголовка пакета (тип команды, длина, счётчики) — **[TBD,
  вопрос 3]**: требуется дизассемблирование заголовочного парсера в `FUN_30080798`
  и сравнение с форматом единиц TFUP (§5.3), у которых юнит-таблица имеет шаг 0x62 б.

### 3.6. Запросы версий

- `atQryDLoadVerBr` (0x3009A728) — версия DLOAD; источник: `BSP_DLOAD_GetDloadVer`
  @ `0x30075B84` / `getDloadVersion` @ `0x300755A4` (data_05.c) [VER: имена/адреса].
- `atQryDLoadInfoBr` (0x3009A8B4) — собирает через `dloadInfoATHandle` @ `0x3007F864`
  → `BSP_DLOAD_GetDloadInfo` @ `0x30075264` (724 б): `BSP_GetProductDloadName`,
  `BSP_DLOAD_GetSoftwareVer`, `BSP_DLOAD_GetISOVer`, `BSP_DLOAD_GetMidwayRestart`,
  сборка строкой `sprintf/strcat/strcpy` [VER: вызовы].
- `atQryBootRomVerBr` (0x3009A588) — `BSP_DLOAD_GetBootromVer` @ `0x30075C74`.
- `atQryAuthorityVerBr`/`atQryAuthorityIDBr` — `BSP_DLOAD_GetAuthorityVer/Id`
  @ `0x30075CD4/0x30075CF0`; `getAuthorityId` (data_05.c) читает NV IMEI через
  `dloadGetNvImeiNumber` → `DR_NV_Read` и сверяет с дефолтом `dloadIsDefaultImeiValue`
  (таблица DAT_300762b0) [VER: вызовы] — авторизация привязана к IMEI (§6).

---

## 4. Путь заливки: от принятого образа до flash

### 4.1. Буферизация

`dloadInitRamBuffer` @ `0x30084E2C` (1024 б): `malloc/free/memset`, `dloadInitImageBufferType`
@ `0x30084D6C` (выбор типа образа/буфера), журналирование через `update_record_file`.
Вызывается всеми тремя главными путями: `FUN_30080798`, `dloadFromFsMainThread`,
`dloadTFPro` [VER: «Вызывают»].

### 4.2. Общая развилка RAM/Flash

`imageDloadProcess` @ `0x30083304` (676 б) — общий финал **всех трёх путей** (его вызывают
`FUN_30080798` (USB), `dloadFromFsMainThread` (ФС), `dloadTFPro` (TF)) [VER: «Вызывают»];
выбирает между:
- `ImageDloadToFlash` @ `0x30082428` (920 б, data_05.c): `FUN_30081f50` (рабочая функция
  записи), `ptable_find_older_part`, `ptable_get_ram_data`, `dloadDealBootrom` [VER: вызовы];
- `ImageDloadToRam` @ `0x30082FA4` (752 б): `FUN_300827c0`, те же `ptable_*` [VER].

`dloadDealBootrom` @ `0x3008230C` (284 б): `ptable_get_table_changed`,
`dloadSetMidwayRestart` @ `0x300822F4`, `BSP_DLOAD_Reset` [VER: вызовы].

**Схема A/B:** `ptable_find_older_part` — образ пишется в *старую* (неактивную) копию
раздела [VER: имя вызова в ImageDloadToFlash]; активация — через `BSP_DLOAD_SetSoftLoad`
и `ptable_replace_flash_table` в `dloadBootromEnd` (§4.4) [VER].

### 4.3. Поточный приём (dynFS-подпуть)

`dynFSDloadProcess` @ `0x300848B8` (1192 б, data_06.c) — приём «поточного» файла:
`dynFSDloadParaChk` @ `0x300835A8` (проверка параметров), `dynFSFirstPacketHandle`,
`dynFSGetFileList`, `dynFSDloadToRam` @ `0x300844E0` → `FUN_300827c0` [VER: вызовы];
вызывается из `FUN_30080798` (USB), `dloadFromFsMainThread` (ФС), `dloadTFPro` (TF) [VER].
Итоговая запись — через `imageDloadProcess` → `ImageDloadToFlash` (§4.2) [VER: «Вызывают»].
Связь `FUN_30081f50`/`FUN_300827c0` с NAND-слоем (`nand_write` @ `0x3000FABC`,
`nand_erase` @ `0x3000FA64`, `ptable_dload_write` @ `0x3002CF9C`) — [TBD, вопрос 4].

### 4.4. Завершение сессии

`dloadBootromEnd` @ `0x30076EC0` (64 б): `ptable_replace_flash_table`,
`ptable_set_integrality`, `BSP_DLOAD_SetSoftLoad`, `BSP_DLOAD_SetMidwayRestart`,
`dloadNeedMidwayRestart`, `BSP_DLOAD_Reset` [VER: вызовы] — фиксация новой таблицы
разделов, пометка целостности, мягкая загрузка нового образа, перезагрузка.
Вызывается из `FUN_30080798`, `TFUP_DloadTask`, `update_WebUITask` [VER].

### 4.5. NAND

`dload_nand_init` @ `0x30076B08` (88 б): `nand_get_spec`, `__udiv32` — расчёт геометрии
NAND в глобалы DAT_300773fc..408 [VER]. Собственно NAND-стек — `src/flash/flash_0*.c`
(вне scope этого документа, см. `02_BSP_DRIVERS.md` / будущий flash-документ).

### 4.6. CD-ROM маркер

`BSP_DLOAD_SetCdromMarker` @ `0x3007555C` (7 вызывающих) и `dload_GetISOUseableSize`
@ `0x3008070C` — загрузчик умеет выставлять «CD-ROM маркер» (виртуальный CD-ROM с ISO-
образом для хоста; см. `dloadFromFsCheckSpaceForISO` @ `0x300779F0`) [VER: вызовы].

---

## 5. TFUP — обновление с TF-карты

### 5.1. Инициализация и обнаружение карты

- `TFUP_CheckInit` @ `0x3007CFFC` (484 б): `OSAL_SemBCreate`/`OSAL_SemMCreate`
  (ошибочные строки `TFUPCheckInit: OSAL_SemBCreate error.` и т.п.),
  `sdmmcAddHook`, `TF_UP_CHECK_T_S` [VER: вызовы + firmware_strings.txt 0x143E70..0x143EF4].
- `TFUP_CheckTask` @ `0x3007F394` (604 б): ожидание карты, `TFUP_dosFsDevCreate`
  @ `0x3007D1E0` (520 б: `sdmmcDevCreate`, `xbdBlkDevCreate`, dosFs), лог
  `TFUP_CheckTask:file check ok!` (0x143FBC) [VER].
- Колбэки вставления/извлечения: `TFUP_CheckCallback` @ `0x3007F6A4`,
  `TFUP_dosFsDevDelete` @ `0x3007F5F0`; семафор `g_checkTFUPsem` (строка 0x13FA50) [VER].
- Флаги TF-обновления в NV через `writeM`: `TFUP_getTFUpdateFlag` @ `0x30076B60` /
  `TFUP_setTFUpdateFlag` @ `0x30076F00`; `TFUP_SetBootromFlag` @ `0x30076F64` /
  `TFUP_GetBootromFlag` @ `0x30076FAC`; `TFUP_SetSuccessFlag` @ `0x30076FD8` /
  `TFUP_GetSuccessFlag` @ `0x30077020`; `TFUP_SetGoOn` @ `0x3007704C` /
  `TFUP_GetGoOn` @ `0x3007707C` [VER: адреса/вызовы; смысл каждого флага — INF].

### 5.2. Проверка файла

- `TFUP_GetAllFileName` @ `0x3007EADC` (764 б) — перечисление файлов на карте.
- `TFUP_CheckFileValidify` @ `0x3007EE38` (1372 б, 13 вызовов) — валидация файла.
- `TFUP_GetFileType` @ `0x3007D3E8` (252 б), `TFUP_IdentifyFile` @ `0x3007D4E4` (1812 б,
  9 вызовов) — распознавание типа/формата пакета [VER].
- `TFUP_CheckVersionMatch` @ `0x3007DBF8` (1652 б) — соответствие версии пакета
  устройству [VER: имя; детали критерия — TBD, вопрос 6].

### 5.3. Структура пакета TF (юниты)

- `TFUP_GetUnitHeadData` @ `0x3007A72C` (1740 б) — чтение заголовков юнитов;
  тела функций используют **шаг таблицы 0x62 (98) байт на юнит** —
  `(uint)bVar7 * 0x62 + DAT_3007bb18` [VER: тело dload_01.c].
- `TFUP_GetUnitSize`/`TFUP_GetUnitData` @ `0x3007B130` (1200 б) — размеры/данные юнитов;
  `uncompress`-аналоги на пути ФС (`uncompress_file_to_stream`, `get_uncompress_length`
  в dloadFromFs*) намекают, что юниты могут быть сжаты [VER: имена; формат — TBD].
- `TFUP_GetUnitCRC` @ `0x3007B5E0` (364 б) — 16-бит CRC юнита [VER: тело].
- `TFUP_ValidateCRCWithCRCList` @ `0x3007A5A0` (396 б): `CalculateCRC` + `memcmp`
  со списком CRC [VER].
- `TFUP_ValidateCRCWithLic` @ `0x3007E26C` (2060 б, 13 вызовов) — проверка юнита
  против лицензии/подписи [VER: имя; алгоритм — TBD, вопрос 7].
- `TFUP_ReadDataFromTF` @ `0x3007ADF8` (824 б) — низкоуровневое чтение с карты.

### 5.4. Главный процесс и завершение

- `dloadTFPro` @ `0x3007B74C` (6188 б, 23 вызова): `TFUP_GetUnitHeadData` →
  `TFUP_GetUnitData`/`TFUP_GetUnitCRC` → `TFUP_ValidateCRCWithCRCList` →
  `dloadInitRamBuffer` → `dynFSDloadProcess` → (прогресс-лог с процентами: тела функций
  считают `+ uVar15 * -100` — вычисление процента) [VER: вызовы; проценты — INF].
  Ошибочные строки: `dloadTFPro: TFUP_GetUnitHeadData error.` (0x14360C),
  `dloadTFPro: TFUP_GetUnitCRC is error.` (0x143820), `dloadTFPro: TFUP_GetUnitData
  error.` (0x1438D0), `dloadTFPro: TFUP_ValidateCRCWithCRCList is error.` (0x143958) [VER].
- `TFUP_DloadTask` @ `0x30077164` (804 б): `OSAL_SemTake`, `dloadTFPro`, при успехе —
  `TFUP_SetSuccessFlag`, `TFUP_setTFUpdateFlag`, `dloadBootromEnd`; логи
  `[%03u.%02us][OK] TFUP_DloadTask:` (0x14102C) / `[ERROR]` (0x141060) [VER].
  Ошибка инициализации: `dloadInit: TF_UP_DLOAD_T_S error.` (0x140FD0) [VER].
- `TFUP_CompleteDeal` @ `0x300770E4`: `TFUP_GetGoOn`/`GetSuccessFlag`/`SetSuccessFlag`,
  `BSP_DLOAD_SetCdromMarker`, `BSP_DLOAD_Reset`, `taskDelay` [VER] — финальная
  обработка и ребут.
- `dloadTFCallback` @ `0x3007CF78`: `OSAL_SemGive`, `ledFlush` — светодиодная
  индикация процесса [VER].
- Лог-файл: `TFUP_LogInit` @ `0x3007EDD8`, `TFUP_LogFsInit` @ `0x3007F72C`,
  `TFUP_LogPrintf` @ `0x3007A47C` (`fopen/fseek/ftell/fvfprintf/remove`) — пишет журнал
  на доступную ФС [VER].

---

## 6. Защита: подписи, версии, откат

| Механизм | Функции | Уровень уверенности |
|---|---|---|
| Секьюрити-чек при инициализации | `drvSecCheck` (вызов из `dloadInit`) [VER] | детали в bsp — вне scope, TBD |
| Допустимость апгрейда | `upgradeAllow` @ `0x30085E1C` → `imgIdioCheck`, `imgUpgradeAllow` [VER: вызовы] | критерий — TBD |
| Лицензия/подпись TF-пакета | `TFUP_ValidateCRCWithLic` @ `0x3007E26C` [VER: имя] | алгоритм — TBD |
| CRC-целостность | CRC-16 PPP-FCS (USB-пакеты, 7/7 [VER]); юнит-CRC TF [VER] | — |
| Авторизация по IMEI | `getAuthorityId` → `dloadGetNvImeiNumber` → `DR_NV_Read`; `dloadIsDefaultImeiValue` (таблица DAT_300762b0) [VER: вызовы] | смысл AT^AUTHORITYID — INF |
| Соответствие версии | `TFUP_CheckVersionMatch` @ `0x3007DBF8` [VER: имя] | критерий — TBD |
| Прерванное обновление | `dloadNeedMidwayRestart` @ `0x30084D60`, `BSP_DLOAD_Get/SetMidwayRestart` @ `0x300750F8/0x30075150`, `dloadSetMidwayRestart` @ `0x300822F4`, флаг в `dloadDealBootrom` (`ptable_get_table_changed`) [VER: вызовы] | сценарий возобновления — INF |
| Целостность ptable/откат | `ptable_set_integrality`, `ptable_replace_flash_table` в `dloadBootromEnd`; запись в неактивную копию через `ptable_find_older_part` (§4.2) [VER] | переключение копий = фактический «откат» через soft-load флаг [INF]; явной функции отката нет — вопрос 8 |

Rollback: подтверждена **двухкопийная схема (A/B)** — `ImageDloadToFlash` пишет через
`ptable_find_older_part` (старую копию), активация — `BSP_DLOAD_SetSoftLoad` +
`ptable_replace_flash_table`/`ptable_set_integrality` в `dloadBootromEnd` [VER: вызовы].
Отдельной функции отката среди 75 функций модуля dload нет [VER: отсутствие в ALL_FUNCTIONS.tsv].

---

## 7. Путь из ФС устройства (dloadFromFs*, CD-ROM/WebUI)

- `dloadFromFsMainThread` @ `0x30078688` (4432 б, 28 вызовов) — главный процесс:
  `dloadFromFsGetUnitHeadData/GetUnitSize/GetUnitData`, `dloadFromFsCheckSpaceForISO`,
  `dynFSDloadProcess`, `dloadInitRamBuffer`, `BSP_DLOAD_SetCdromMarker/SetSoftLoad`,
  `dynFSDloadProcess`, `fclose/fopen` [VER: вызовы].
- `dloadFromFsGetUnitHeadData` @ `0x30077488` (1384 б) — заголовки юнитов из файла
  (fopen/fread/fseek/ftell) [VER].
- `dloadFromFsGetUnitSize` @ `0x300782A0` (1000 б) — `get_uncompress_length` →
  `gzgetUncompressLength`; `dloadFromFsGetUnitData` @ `0x30077D88` (1304 б) —
  `uncompress_file_to_stream` → `gzuncompressFileToStream` (обёртки @ `0x30086C74` /
  `0x30086CA0`, data_06.c): **образы в пакете сжаты gzip** [VER: вызовы].
- `dloadFromFsCheckSpaceForISO` @ `0x300779F0` + `dload_GetISOUseableSize`
  @ `0x3008070C` — проверка места под ISO-образ [VER].
- Вызывает весь путь `update_WebUITask` [VER: «Вызывают»] — WebUI-обновление.
- Журнал обновления: `dloadRecord` @ `0x30085578` (784 б; `exchLogPrintf`,
  fopen/ftell/remove) и `update_record_file` (вызывается почти на каждом шаге) [VER].

---

## 8. Открытые вопросы

1. **Точные форматы OK-ответов** `AT^DLOADVER?/DLOADINFO?/AUTHORITYVER?/AUTHORITYID?/BOOTROMVER?`
   и подтверждение `"\r\nOK\r\n"`. Уточнение: найден только `^HWNATQRY:%d`; строк вида
   `^DLOADVER:` нет — версии, вероятно, уходят блоками данных. Метод: тела atQry* в
   dload_01.c (ссылки на строковые константы Ghidra `s_...`).
2. **HDLC-обрамление DLOAD-кадров**: флаг 0x7E, escaping, FCS на уровне Om_Hdlc —
   какие поля доб. Метод: разбор `Om_HdlcDecap/Encap` (usb/om модули) в decompiled_all.c
   по адресам вызовов.
3. **Раскладка заголовка DLOAD-пакета** (магия, тип команды, длина, счётчик, CRC-позиция).
   Метод: дизассемблер заголовочного парсера внутри `FUN_30080798` (5352 б) в
   decompiled_all.c; сверка с 0x62-байтной таблицей юнитов TFUP; поиск констант-магий
   ('DLOAD', 'SDUP' и т.п.) в firmware_strings.txt.
4. **Связь с NAND-слоем**: цепочка до flash уточнена (`imageDloadProcess` →
   `ImageDloadToFlash` → `FUN_30081f50`, `ptable_find_older_part`); осталось тело
   `FUN_30081f50`/`FUN_300827c0` — вызывают ли `nand_write` @ `0x3000FABC` /
   `ptable_dload_write` @ `0x3002CF9C`. Метод: тела в decompiled_all.c.
5. **Выход из data-mode обратно в AT** — существует ли (AT^GODLOAD? сброс?). Метод:
   тела atSetDataModeBr и поиск сброса флага.
6. **Критерий `TFUP_CheckVersionMatch`** (что с чем сравнивается). Метод: тело функции
   (1652 б) — сравнение строк версии из заголовка пакета с `BSP_DLOAD_GetSoftwareVer`.
7. **Алгоритм `TFUP_ValidateCRCWithLic`** (лицензия из NV? подпись RSA/SHA?). Метод:
   тело (2060 б, 13 вызовов) + `CalculateCRC` (lib).
8. **Механизм отката** — частично закрыто: A/B подтверждена (`ptable_find_older_part`,
   §4.2). Осталось: чем bootrom выбирает копию при старте и что делает
   `ptable_set_integrality`. Метод: ptable_* в flash_03/04.c + boot-модуль.
9. **Смысл mode-кодов 0x7/0x8/0xA** (`AT^HWNATQRY?`, `AT^FLASHINFO?`, `AT^GODLOAD`) в
   `ATCommandHandle`. Метод: тело ATCommandHandle (928 б, data_05.c).
10. **Точное место taskSpawn(tDloadTask, 0x51)** в `dloadInit` (аргументы: имя, стек).
    Метод: тело dloadInit в dload_01.c/decompiled_all.c @0x30076BA8.

## 9. Ссылки на материалы

- `usbl_src/src/dload/dload_01.c` — все 75 функций модуля с doc-заголовками (адрес/вызовы/строки).
- `usbl_src/src/bsp/bsp_03.c` — BSP_DLOAD_* (SendData, GetDloadInfo, Reset, …).
- `usbl_src/src/data/data_05.c`, `data_06.c` — ATCommandHandle/Process, ImageDload*, dynFS*.
- `usbl_src/index/ALL_FUNCTIONS.tsv` — адреса/размеры всех функций.
- `usbl_src/index/STRINGS_BY_MODULE.md` (раздел dload) — строки протокола.
- `firmware_strings.txt` — file-офсеты строк TFUP/ошибок (0x140FD0…0x14409C и др.).
- Дампы прошлой сессии: таблица AT @VA 0x30154FB8 (scratch_attable.py), таблица
  ATCommandProcess @VA 0x30149244 (scratch_atproc.py), CRC-тест (scratch_crc.py, PPP-FCS 7/7).
