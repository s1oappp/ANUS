# 03. USB device‑стек USBL

> Реконструкция по декомпиляции `usblsafe-327x.bin` (Huawei Balong V7R1, VxWorks 6.8).
> Все адреса — VA payload (карта: `VA = file_off − 0x3C0 + 0x30004000`).
> Помечено **[гипотеза]** то, что не подтверждено напрямую кодом/данными.

## 1. Архитектура

Стек — портированный на VxWorks проприетарный стек j*‑архитектуры (jungo‑подобный),
собранный из исходников (пути из assert‑строк сборки):

```
bsp/drivers/usb/
├── jos/                      — каркас bus/device/driver + память/синхронизация
│   ├── jinit.c  jos_bus.c  jos_device.c  jos_driver.c
│   └── jos_entry.c  jos_general.c  jos_mem.c  jos_sync.c
├── jslave/
│   ├── core/  jslave_init.c  jusb_core.c  jusb_chp9.c   (Chapter 9 — EP0)
│   ├── dcd/   dcd_syn_hs.c                              (контроллер Synopsys HS)
│   └── fd/    cdc/cdc_fd.c  cdc/acm_fd.c                (функции CDC/ACM)
├── port/
│   ├── common/app_init.c
│   └── vxworks/  bus.c  entry.c  mem.c  sync.c          (OS-адаптация)
└── adapt/acm/  BSP_USB_ACM_Sio.c                        (стык с SIO VxWorks)
```

Слои снизу вверх:

```
железо (DWC Synopsys HS)
   → dcd_syn_hs          контроллер device
   → jusb_core / jusb_chp9  ядро jslave, EP0, стандартные запросы
   → cdc_fd / acm_fd     функции USB CDC/ACM (каналы PCUI/DIAG/SHELL/DLOAD)
   → uwd_*               обёртки для адаптации (write/read/flow/notifications)
   → BSP_USB_ACM_Sio     мост в SIO/IOS VxWorks (/dev/…)
   → tDloadTask / AT-парсер (см. docs/04)
```

## 2. Запуск стека

| Параметр | Значение | Источник |
|---|---|---|
| Задача | `tUSBTask` | имя @ VA 0x3012E344, указатель @ 0x30005134 |
| Вход | **0x300048B0** = `b jusb_entry` | disasm @0x300048B0 |
| Приоритет | **0x50** | .data, читается в `taskSpawn` из `usrRoot` |
| Стек | **0x4E20** (20000 Б) | там же |
| Перед стартом | `USB_UnReset()` @0x30004A18, `dloadInit()` | usrRoot‑блок |

`taskNameToId`/`taskDelay(100)`-цикл @0x300048B4–0x300048D4 — отдельная задача‑пустышка
(`tIdletask`, entry 0x300048B4, prio 0xFF), ждущая исчезновения `tUSBTask` — маркер
завершения работы стека при переходе в другой режим [гипотеза: семантика «последнего вздоха»].

Путь запуска:

```
jusb_entry 0x3005BFA0
  → get_uw_args 0x3005B2BC
  → jstart_stack 0x30044740:
       debug_init → jos_init → uw_app_init → jdrivers_init
       → jslave_init(mode) → os_hw_init → jslave_enable(для каждого устройства)
    (при ошибке любой стадии — откат уже инициализированного)
```

Симметричный разбор: `jstop_stack` 0x30044B6C (+ `BSP_USB_FreeDevProfile(0)`).

## 3. Компоненты и адреса

### 3.1 jos — каркас
- `jos_init` 0x30042308: `check_byte_order → jos_mem_init → jos_safe_init → os_port_init → jos_sync_init` (флаги‑bitmask).
- память: 0x30047F80, 0x30047FD0; критические секции 0x3004852C–0x3004867C; safe 0x30049B90/0x30049D30;
  мьютексы 0x30049F4C/0x30049F94; sync 0x3004A0D4/0x3004A1A8.
- задачи стека: `jtask_init/stop/uninit/schedule_d` 0x30048234 / 0x30048850 / 0x300489DC / 0x30048D98.
- DMA: `jdma_alloc/free/free_all/buffer_get` 0x300478E4 / 0x30047758 / 0x30047E20 / 0x30046F6C.

### 3.2 bus/device/driver
- `jdevice_add/delete` 0x3004339C/0x300432F0; `jdrivers_init/uninit` 0x300436D0/0x30043544;
  `jdriver_register/attach/detach` 0x300437C4/0x30044258/0x30043A20.
- акцессоры `j_device_*` 0x30042750–0x30043288 (core_ctx, ivars, params, controller_id,
  nameunit, bus, parent, softc, unit, probe_and_attach); список ожидающих контроллеров 0x300444C0–0x30044568.

### 3.3 port/vxworks — OS‑адаптация
- прерывания: `os_generic_isr` 0x3005B31C, `os_interrupt_setup/teardown` 0x3005B39C/0x3005B66C.
- `os_hw_init/uninit` 0x3005BBC4/0x3005BB68; `os_port_init/uninit` 0x3005C074/0x3005C0A4.
- bus space: `os_bus_space_read/write_1/2/4` 0x3005BDE8–0x3005BE90.
- потоки: `os_thread_create` 0x3005C868 — `taskSpawn` с приоритетом `param_3 + 0x7E`.
- память/синхро: `os_malloc/dma_alloc/cache_flush/mutex/msg_q/msleep/wakeup` 0x3005C2F8–0x3005D3A0.

### 3.4 uw‑слой
- `uw_app_init` 0x30059AD4 — таблица `{init,flag,exit}`×12Б по указателю 0x30059BA0 → **0x301815A4,
  в этой сборке пуста** (первый элемент 0) — расширение не используется.
- `uw_hw_init/uninit` — стабы по 4 Б (пустые).
- `uw_code2str` 0x300468DC.

### 3.5 jslave (ядро устройства)
- `jslave_init/uninit/enable/disable/reconfig/wakeup_host` 0x3004A4E8–0x3004A61C.
- Chapter 9: `chp9_handle_set_configuration` 0x3004B1FC, `chp9_handle_usb_command` 0x3004D170
  (диспетчер EP0), `chp9_set_string_descriptors` 0x3004D52C.
- Строки лога: `Starting JSLAVE init`, `jslave_enable()`, `Error running jslave_enable for core %d. rc %s`.
- Диапазон 0x3004A690–0x30055144 (~43 КБ) — тело `jusb_core`/`chp9` (безымянные FUN_*; см. decompiled_all.c).

### 3.6 dcd_syn_hs (контроллер)
- `dcd_set_out_nak` 0x30055144 + блок FUN_300551C0…FUN_3005616C (~5 КБ) — обработка эндпоинтов/IRQ.
- Карта регистров DWC не восстановлена полностью — см. §7.

### 3.7 CDC/ACM и uwd
- `cdc_*` 0x300563B0–0x30059924: init 0x300597FC, enable 0x30059034, alloc/free_descriptors
  0x30058F18/0x30058560, ep0_read/write 0x30056ED4/0x30056F64, send_status 0x300570D0,
  notification 0x300574F8, encapsulated 0x300575FC/0x30057A60.
- `acm_handle_request` 0x3005E9EC; `cdc_init_acm` 0x3005F060.
- `uwd_cdc_write/read/read_flow/set_out_nak/abort_*/get_read_size` 0x300566DC–0x30056D90;
  `uwd_cdc_send_encap_response/notify_flow_control/send_notification` 0x30057D4C/0x30058214/0x300583B8;
  `uwd_acm_notify_serial_state/set_max_segment_size/notify_network_connection/app_init` 0x3005EC4C–0x30062660.
- `BSP_USB_ACM_Sio` — мост в VxWorks SIO (путь сборки подтверждён assert‑строкой @file 0x13C758);
  BSP_USB_*‑профильные функции 0x30059BB0–0x3005B298.

## 4. Дескрипторы USB

Шаблоны в .data @ **VA 0x301813EC** (заполняются рантаймом):

| Дескриптор | Адрес | Байты | Расшифровка |
|---|---|---|---|
| DEVICE | 0x301813EC | `12 01 00 02 00 00 00 08 00 00 00 00 00 00 00 00 00 01` | bcdUSB=0x0200, класс 0/0/0, bMaxPacketSize0=8, **VID/PID/bcdDevice = 0 (рантайм)**, 1 конфигурация |
| DEVICE_QUALIFIER | 0x301813FE | `0a 06 00 02 00 00 00 08 01 00` | HS‑квалификатор |
| CONFIG | 0x30181408 | `09 02 0000 00 00 80 fa` | wTotalLength — плейсхолдер, bmAttributes=0x80 (bus‑powered), bMaxPower=0xFA (500 мА) |
| INTERFACE | 0x30181411 | `09 04 00 00 00 00 00 00 00` | интерфейс 0, 0 эндпоинтов в шаблоне (дополняется профилем) |

Литерал‑пулы, ссылающиеся на шаблоны: 0x3004C440 (→device), 0x3004C944 (→config),
0x3004CC6C (→qualifier) — внутри chp9‑функций 0x3004C000–0x3004D600.

- **VID 0x12D1 в константах не найден** — VID/PID/bcdDevice вставляются рантаймом:
  `BSP_USB_UpdateDevPidInfo` 0x3005A520 (поле `profile->u16DevPid`).
  Источник значений — таблица продуктов `g_huaweiProductInfo` @ **0x3016EADC** (см. docs/07).
- Строки дескрипторов: `HUAWEI Mobile` VA 0x3013BE38, `HUAWEI Technology` VA 0x3013BE48;
  заполнение — `chp9_set_string_descriptors` 0x3004D52C (строки STRING‑индексов не дообследованы).

## 5. Мультиплексирование портов (DEVICE_FD_*)

Таблица имён типов портов @ **0x30181BC4** (указатель @ 0x3005AB78):

| Idx | Тип | Idx | Тип |
|---|---|---|---|
| 0 | NONE | 10 | CDROM |
| 1 | DIAG | 11 | SD |
| 2 | PCUI | 12 | GPS |
| 3 | SHELL | 13 | PCVOICE |
| 4 | DLOAD | 14 | DVB |
| 5 | CTRL | 15 | NIC |
| 6 | MODEM | 16 | RESERVED |
| 7 | ECM | 17 | AUTOTEST |
| 8 | NCM | 18 | DIAG_LTE |
| 9 | PCSC | 19 | DIAG_3G |

(строки имён: 0x3013EFF4–0x3013F134)

**Структура профиля устройства** (из `BSP_USB_DumpDevProfile` 0x30059C00):

```c
struct dev_profile {          // размер ~16+2*n байт
    uint16_t u16DevIdx;       // +0x00 индекс профиля
    uint8_t  u8FdCount;       // +0x02 число портов (function descriptors)
    uint16_t u16DevPid;       // +0x04 PID USB для этого профиля
    /* +0x06 паддинг */
    uint8_t  euAutoRunCapable;// +0x08
    /* +0x09..0x0B паддинг */
    uint32_t u32OSTypeSupport;// +0x0C маска поддерживаемых ОС
    uint16_t fdTypes[];       // +0x10 индексы в таблицу DEVICE_FD_*
};  // [гипотеза] выравнивание/паддинг восстановлены по формату printf-строк дампера
```

Форматы строк дампера: `%s: profile->…`, `[%dth] dev-> %s`.

API профилей (0x30059BB0–0x3005B298): `GetDiagModeValue` (константы 1/2),
`GetU2diagDefaultValue` (литерал **0x5118**, семантика не подтверждена),
`GetIsWwanMode` (значение @0x30181B4C = 0 в образе), `CheckDevProfile`/`ValidateDevProfile`
(до 9 итераций), `FindDevProfile`, `UpdateDevProfileInfo`, `UpdateDevPidInfo`,
`GetDevDescIdx` (строка `MDM+PCUI+DIAG in Bootrom image` @file 0x13B880 — профиль
загрузочного образа: модем + PCUI + DIAG), `BuildDevProfile/FreeDevProfile/BuildDevArgs/
QueryDevProfile/DumpDevProfile/GetUwArgs`.

Питание/подключение: `HI6451_usb_insert/remove_proc` 0x30032268/0x300323C4 (VBUS через PMU),
`GetUSBConnStatus` 0x30033C40, `usb_enum_notify_usr` 0x3005B91C,
`BSP_USB_RegEnumDoneForMsp/Ps` 0x300048E0/0x30004920.

## 6. Регистры DWC (состояние разбора)

- `USB_UnReset` @0x30004A18 работает через указатели DAT_300050D0…DAT_300050E0 —
  **базы MMIO лежат в .data** (значения в образе), битовые маски
  0x08000000 / 0x2000 / 2 / 0x2000000 / 0x18000000 — сброс/тактирование [гипотеза по роли].
- Основной блок `dcd_syn_hs` (FUN_300551C0–0x3005616C) до конца не размечен:
  ожидаемая карта — стандартные офсеты DWC OTG (GOTGCTL 0x000, GUSBCFG 0x040, GINTMSK 0x018,
  DCFG 0x800, DCTL 0x804, DIEP*/DOEP* 0x900+) [гипотеза].
- Точные базы блоков USB (клок‑гейт/физика) — см. docs/02_BSP_DRIVERS.md (CRG‑блок) и §7.

## 7. Открытые вопросы

1. Значения баз MMIO из DAT_300050D0–E0 и полная карта регистров `dcd_syn_hs`
   (декомпил FUN_300551C0–0x3005616C в decompiled_all.c).
2. EP0‑машина: разбор разрыва src/usb/usb_01.c 0x3004A690–0x30055144 (jusb_core/chp9).
3. Источник VID/PID/bcdDevice: декомпил `BSP_USB_UpdateDevPidInfo` + `g_huaweiProductInfo` @0x3016EADC.
4. Путь исходников uwd не найден в assert‑строках (искать в file‑офсетах 0x13C700–0x13E200).
5. AT‑переключение режимов (U2DIAG) в этой сборке не подтверждено — проверяется в docs/04.
6. Семантика литерала 0x5118 (`GetU2diagDefaultValue`) и таблицы @0x301815BC.
