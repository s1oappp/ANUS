# 06 — Флеш-подсистема usbl: NANDC, ptable, YAFFS, NVM/nvim

Прошивка: usblsafe-327x.bin (USB-загрузчик Huawei Balong V7R1, VxWorks 6.8).
Соглашения: адреса функций — VA в RAM (образ грузится с 0x30004000; VA = file_off − 0x3C0 + 0x30004000).
Смещения строк даны как file_off из `firmware_strings.txt` (для ключевых строк приведён и VA).

Источники (уровень доказательности):
- **[C1]** первичный код: `usbl_src/src/flash/flash_01.c` (NAND + nandc-контроллер), `flash_03.c` (yaffs + ptable, часть 1), `flash_04.c` (ptable, часть 2 + NVM/nvim/Lnvm); doc-заголовки функций содержат адреса, размеры, вызывающих/вызываемых.
- **[C2]** карта функций: `usbl_src/index/ALL_FUNCTIONS.tsv` (имя → VA → файл).
- **[C3]** строки: `firmware_strings.txt` (file_off; VA = off − 0x3C0 + 0x30004000).
- Выжимка тел функций, по которой писался документ: `scratch_flash_extract.txt` (scratch, 56 функций).

---

## 1. Сводка

- Флеш = SPI-подобный стек из 4 слоёв: **dload/приложения → ptable (карта разделов) → nand_* (raw-API) → nandc_* (контроллер Balong)**, поверх — **YAFFS** (файловые разделы) и **NVM/nvim/Lnvm** (NV-переменные, частично на YAFFS). Уверенность: высокая, видно по вызовам в doc-заголовках [C1].
- ptable хранится во flash по смещению **0x1E000**, размер **0x400** байт (одна копия): `nand_write(0x1E000, head, 0x400, 0)` в `ptable_replace_flash_table @ 0x3002C988` [C1]. Заголовок 0x30 байт + записи по 0x30 байт.
- Двойные копии реализованы **не для ptable, а для содержимого разделов**: у разделов одного `type` выбирается «младшая» копия (счётчик в поле +0x2C) — `ptable_find_older_part @ 0x3002CEB4` [C1].
- YAFFS-разделы определяются флагом **0x600** в поле flags записи ptable (+0x28); монтирование — `ptable_yaffs_mount @ 0x3002D35C` из `yaffsInit @ 0x30022744` [C1].
- YAFFS-чанк = страница данных + **16 байт OOB** (`nand_yaffs_write_size @ 0x3000F86C`: `(page_data + 0x10) * count`) [C1].
- NVM — диспетчер на **2 бэкенда** (таблица записей по 0xC байт с диапазонами id): raw-flash NV и файловый (Lnv/HNV на YAFFS): `NVM_Read @ 0x3009B480`, `NVM_Write @ 0x3009B52C` [C1]. Путь бэкапа NV-файла: **/modem/modem_image/nv_bak/NV.HNV** (строка @0x18D588) [C3].
- Контроллер NANDC существует в трёх версиях — в строках **NANDC_V2.00 / V3.20 / V4.00** (@0x12E528/0x12E534/0x12E540) [C3]; в usbl точно присутствует вариант `nandc2_ctrl_init @ 0x30017248` (тайминговая последовательность), варианты V3/V4 не локализованы — см. §8.

---

## 2. Архитектура слоёв

```
DLOAD (dload_01.c) / приложения (BSP_PMU, exchReadConfig, os_nv_read ...)
   │  ImageDloadToFlash/Ram, ptable_dload_write/read, NVM_Read/Write
   ▼
ptable_* (карта разделов, RAM-таблица + копия во flash @0x1E000)
   │  выборка по name/type, A/B-копии, yaffs-флаги
   ▼
nand_*  raw-API (flash_01.c): nand_read/write/erase/isbad/get_spec/scan_bad
   │  мьютекс + power-manage (PWRCTRL_NAND_LowPowerExit/Enter)
   ▼
nandc_*  контроллер NANDC (командный автомат, ECC, DMA, regset-регистры)
   ▼  (аппаратура)

параллельно: ynandif_* (data_01.c) — адаптер YAFFS→nand_*; yaffs* (flash_03.c) — FS;
             nand_read_yaffs/nand_write_yaffs — чанковый доступ с OOB=16.
```

Факты по слоям: `nand_read_yaffs @ 0x3000F964` вызывается из `ynandif_ReadChunkFromNAND @ 0x30026334/0x300263D4` (data_01.c); `nand_read @ 0x3000F71C`, `nand_write @ 0x3000FABC` вызываются из `ptable_read_by_type/ptable_write_by_type` [C1/C2].

Питание/мьютекс: `nand_mutex_in @ 0x3000F1C4` вызывает `PWRCTRL_NAND_LowPowerExit`, `nand_mutex_out @ 0x3000F220` — `PWRCTRL_NAND_LowPowerEnter`; их вызывают `nand_deinit`, `nand_init_platform`, `nand_read_yaffs`, `nand_run`, `nand_write_yaffs` — т.е. каждый доступ к NAND обёрнут в выход/вход low-power [C1].

---

## 3. ptable — карта разделов

### 3.1 Структуры (RAM)

RAM-таблица: `ptable_get_ram_head @ 0x3002B588` и `ptable_get_ram_data @ 0x3002B590` возвращают указатели на статические блоки (head и массив записей; entries = head + 0x30) [C1].

**Заголовок (0x30 байт):**

| Офсет | Размер | Смысл | Доказательство |
|---|---|---|---|
| +0x00 | 0x10 | имя/магия таблицы | `ptable_ensure @ 0x3002B5B8`: `strcpy(head, DAT_3002c438)` при инициализации; сравнение с константой .data |
| +0x0C | 4 | флаги | bit0 — целостность: `ptable_check_integrality @ 0x3002BAEC` возвращает `(flags & 1) == 0`; bit30 — «таблица по умолчанию»: `ptable_mark_default @ 0x3002B598` ставит `0x40000000` с маской `0xBFFFFFFF` |
| +0x10 | 0x10 | строка версии/продукта №1 | `ptable_replace_ram_table @ 0x3002C674`: `strncmp(head+0x10, DAT_3002d590, ...)`, `memcmp(head+0x10, new+0x10, 0x10)` |
| +0x20 | 0x10 | строка версии/продукта №2 | там же (`head+0x20` vs `new+0x20`, memcmp 0x10) |

Строки версии сверяются с константами прошивки; при несовпадении печатается `ptable_replace_ram_table:[WARN]version back!` (строка @0x1319A0, VA 0x301355E0) — защита от отката версии таблицы [C1/C3].

**Запись раздела (0x30 байт):**

| Офсет | Размер | Смысл | Доказательство |
|---|---|---|---|
| +0x00 | 0x10 | имя раздела (строка) | `ptable_find_by_name @ 0x3002BB68` — `strcmp` по записи |
| +0x10 | 4 | смещение во flash (начало) | `ptable_replace_ram_table`: сравнение `+0x10`; `ptable_dload_write @ 0x3002CF9C`: `write(offset + written + buf)` |
| +0x14 | 4 | записано байт (прогресс DLOAD) | `ptable_dload_write`: `*(iVar2+0x14) = param_4 + *(iVar2+0x14)` |
| +0x18 | 4 | размер раздела | `ptable_parse_mtd_partitions @ 0x3002B800` — фильтр `*(pcVar2+0x18) != 0` |
| +0x1C | 4 | поле сверяется при merge | `ptable_replace_ram_table` (сравнение `+0x1c`) |
| +0x20 | 4 | поле сверяется при merge | там же (`+0x20`) |
| +0x24 | 4 | type (тип образа) | `ptable_find_by_type @ 0x3002B9A4`: `*(param_2+0x24) == param_1` |
| +0x28 | 4 | флаги: биты 0–2 — режим записи (0 = `nand_write`, 1 = `nand_write_oob` c 16B OOB), bit3 — validity, биты 9–10 (0x600) — YAFFS-раздел | `ptable_get_validity @ 0x3002B988`: `>>3 & 1`; `ptable_read_by_type @ 0x3002BBDC`: mode 1 → `nand_read_oob(..., 0x10, ...)`; `ptable_yaffs_mount @ 0x3002D35C`: `flags & 0x600` |
| +0x2C | 4 | счётчик «поколения» (возраст копии) | `ptable_find_older_part @ 0x3002CEB4`: выбор меньшего `+0x2c` как «older», при записи нового — `older.seq = newer.seq + 1` |

`ptable_show @ 0x3002B66C` печатает поля записи в порядке: offset, прогресс(+0x14), size, +0x1C, +0x20, flags(+0x28), seq(+0x2C), type(+0x24) — по 8 полям на строку таблицы [C1].

### 3.2 Хранение во flash и в RAM

- **Расположение: смещение 0x1E000, длина 0x400.** `ptable_replace_flash_table @ 0x3002C988`: `nand_write(0x1e000, ptable_get_ram_head(), 0x400, 0)` [C1].
- 0x400 байт = заголовок 0x30 + до **20 записей** по 0x30; строка `WARNING! ptable_replace_ram_table:new table size too large!!` (@0x1319F8) подтверждает ограничение размера [C3].
- Найдена **одна** копия ptable во flash (все вызовы записи — по 0x1E000); избыточности на уровне таблицы не обнаружено — избыточность реализована на уровне содержимого разделов (§3.3). Уверенность: средняя-высокая (проверены все вызывающие `nand_write` из ptable-слоя: `ptable_replace_flash_table`, `ptable_write_by_type`, `ptable_replace_protected`).
- **Дефолтная таблица** — из констант .data: `ptable_ensure @ 0x3002B5B8` при несовпадении магии head собирает таблицу заново: `memset(0x30)`, `strcpy(head, DAT_3002c438)`, `memcpy(head+0xc, DAT_3002c448, ...)`, `strcpy(head+0x10/0x20, ...)`, `memcpy(entries, DAT_3002c454, ptable_size())` [C1]. Содержимое блока DAT_3002c454 (сами имена разделов) в коде не зашито — см. §8.1.
- Merge таблицы из потока DLOAD: `ptable_replace_ram_table @ 0x3002C674` (788 байт) — по-записное сравнение (offset, size, +0x1C, +0x20, type, flags c точностью до validity-бита, имя); при отличиях — `ptable_set_table_changed @ 0x3002C65C` (глобальный флаг `DAT_3002d58c`) и последующая запись во flash [C1].
- «Защищённые» разделы: `ptable_replace_protected` / `ptable_obtain_protected` (строки @0x1318EC, @0x13195C, @0x131A64–0x131AB8) — чтение/перезапись через `nand_read`/`nand_write` с поиском по имени [C3].
- Связка с MTD-слоем: `ptable_parse_mtd_partitions @ 0x3002B800` строит массив mtd_partition (записи по 0x18 байт: имя, size@+8, offset@+0xC) для записей с size != 0, проверяя непрерывность карты (разрыв → выход); вызывается из `nandc_init_mtd_partition @ 0x30014FF4` [C1]. Строка `ptable_to_mtd_partition, error malloc` (@0x1316B4).

### 3.3 Двойные копии содержимого разделов (A/B по type)

- Для разделов одного `type` существует несколько записей (A/B). Выбор «свежей»: `ptable_find_by_type @ 0x3002B9A4` идёт по таблице и среди записей данного type с validity-битом (bit3 of +0x28) выбирает максимальный seq (+0x2C) [C1].
- Запись новой копии: `ptable_dload_write @ 0x3002CF9C` → `ptable_find_older_part(type, ram_data, flag, validity)` — находит запись с **минимальным** seq (старейшую), при `flag==1` повышает её seq (`older.seq = newer.seq + 1`), переключает validity-бит и, если он изменился, сразу `ptable_replace_flash_table()` (пишет обновлённую таблицу в 0x1E000) [C1].
- Вызывающие `ptable_find_older_part`: `ImageDloadToFlash @ 0x30082428`, `ImageDloadToRam @ 0x30082FA4` (data_05.c), `ptable_dload_write` — т.е. A/B-схема включается именно загрузчиком образов [C1/C2].
- Семантика validity-бита: `ptable_set_validity @ 0x3002BAB0`: `validity==0` → установить bit3 (`&0xFFFFFFF7 | 8`), иначе сбросить. Точная интерпретация («0 = активная копия» судя по `ptable_find_by_type`) — см. §8.2.

### 3.4 API-каталог ptable (адреса [C2])

| Функция | VA | Файл | Назначение (по коду [C1]) |
|---|---|---|---|
| ptable_get_ram_head / _data | 0x3002B588 / 0x3002B590 | flash_03.c | указатели RAM-таблицы |
| ptable_mark_default | 0x3002B598 | flash_03.c | пометить head как default (bit30) |
| ptable_ensure | 0x3002B5B8 | flash_03.c | init из .data-дефолта |
| ptable_show | 0x3002B66C | flash_03.c | печать таблицы |
| ptable_parse_mtd_partitions | 0x3002B800 | flash_03.c | ptable → массив mtd_partition |
| ptable_get_validity / set_validity | 0x3002B988 / 0x3002BAB0 | flash_03.c / flash_03.c | bit3 поля flags |
| ptable_find_by_type / theother_by_type | 0x3002B9A4 / 0x3002BA34 | flash_03.c | поиск по type (A/B) |
| ptable_check_integrality / set_integrality | 0x3002BAEC / 0x3002BB10 | flash_03.c / flash_04.c | bit0 head+0x0C |
| ptable_find_by_name | 0x3002BB68 | flash_04.c | поиск по имени |
| ptable_read_by_type / write_by_type | 0x3002BBDC / 0x3002BCF4 | flash_04.c | raw-доступ с учётом режима (mode 0/1) |
| ptable_erase_partition | 0x3002BE0C | flash_04.c | стирание блоков раздела (пропуск bad) |
| ptable_quary_partition | 0x3002BF8C | flash_04.c | опрос bad-блоков раздела |
| ptable_get_range | 0x3002C0F0 | flash_04.c | диапазон раздела |
| ptable_get/set_cdromiso_version | 0x3002C184 / 0x3002C2DC | flash_04.c | версия ISO-образа (раздел `cdromiso`) |
| ptable_set_table_changed | 0x3002C65C | flash_04.c | флаг изменения |
| ptable_replace_ram_table | 0x3002C674 | flash_04.c | merge новой таблицы |
| ptable_replace_flash_table | 0x3002C988 | flash_04.c | запись таблицы во flash @0x1E000 |
| ptable_flash_prepare | 0x3002CD30 | flash_04.c | `nand_scan_bad(offset, size, 1)` перед записью |
| ptable_find_older_part | 0x3002CEB4 | flash_04.c | A/B: выбор+продвижение копии |
| ptable_dload_write / dload_read | 0x3002CF9C / 0x3002D200 | flash_04.c | запись/чтение образов через ptable |
| ptable_yaffs_mount / _byname / unmount_byname | 0x3002D35C / 0x3002D4B0 / 0x3002D5D4 | flash_04.c | монтирование YAFFS-разделов |
| ptable_size | 0x3002D76C | flash_04.c | размер таблицы |

### 3.5 Имена разделов

- Подтверждено из строк: **`cdromiso`** (@0x17C6CC, VA 0x3018030C) — раздел с ISO-образом (CD-ROM для webui-установщика), для него есть `ptable_get/set_cdromiso_version` [C3/C1].
- Имена остальных разделов в дампе строк **не найдены** (grep по mcore/fastboot/usbl/dsp/nv/nva/nvb/vmall/oeminfo/userdate/splash — 0 попаданий, кроме cdromiso). Вывод: короткие имена лежат внутри .data-блоба дефолтной таблицы (DAT_3002c454) и, возможно, были потеряны при дампе строк (минимальная длина). Путь проверки — §8.1. Это **не найдено**, не «имен нет».

---

## 4. nandc — контроллер NAND (Balong)

### 4.1 Слои и версии

- В прошивке есть версии контроллера **NANDC_V2.00 / V3.20 / V4.00** (строки @0x12E528–0x12E540) [C3]. В usbl локализован init варианта V2: `nandc2_ctrl_init @ 0x30017248` (~200 байт, тайминговая последовательность). Инициализация V3/V4 в извлечённом наборе не найдена — §8.3.
- Готовое устройство собирает `nandc_native_host_create @ 0x30016D78`; спецификации чипа — `nandc_native_get_spec @ 0x3001669C` (1216 байт, разбор ID-ответа) [C1].

### 4.2 Командный автомат

`nandc_ctrl_entry @ 0x30011FCC` — диспетчер по последней NAND-команде (поле хоста **+0x58**); коды совпадают со стандартными ONFI-командами [C1]:

| Команда | Действие |
|---|---|
| 0x00 | idle / нет операции |
| 0x10 | подтверждение page program — запуск записи |
| 0x30 | подтверждение page read — запуск чтения, **до 3 повторов** с задержкой (DAT_30013074) |
| 0x60 / 0x80 | setup стирания / записи (захват адреса) |
| 0x70 | чтение статуса |
| 0x90 | чтение ID (`nandc_ctrl_read_id @ 0x300102DC`) |
| 0xD0 | подтверждение erase — стирание блока |
| 0xFF | reset (`nandc_ctrl_reset @ 0x3000FFC0`, 796 байт) |

Поддержка DMA: при бите 0 в поле +0x5C операции 0x10/0x30 идут через DMA-варианты; иначе через `nandc_ctrl_read_normal @ 0x30010840` (2424 байта) и `nandc_data_transmit_page @ 0x30013588` [C1].

`nandc_ctrl_read_normal` — проверки: адресная валидность (при включённой отладке `DAT_30011778` bit2: `(addr & 0xF0000000) > 0x1FFFFFFF` → отказ; константы 0xF0000000/0x1FFFFFFF), контроль состояния инициализации (переход 1→2 поля +0x18) и выставление регистров из дескриптора чипа (cluster/ECC-конфиг из DAT_3001176C/70/74) [C1].

### 4.3 Геометрия

`nandc_host_add_nand_chip @ 0x30013DD4` — допустимые геометрии [C1]:

- page size: **0x200 / 0x800 / 0x1000 / 0x2000** (512 B – 8 KiB);
- block size: **0x8000 / 0x20000 / 0x40000 / 0x100000** (32–1024 KiB);
- число адресных циклов: 4, либо **5 при ёмкости > 0x8000000 (128 MB)**;
- из размера страницы/блока вычисляются ширины col/row-адреса (сдвиги), используемые затем yaffs-доступом.

`nandc_native_get_spec @ 0x3001669C` разбирает ID-ответ (maker-байт; в коде различаются **0xEC Samsung** и **0xAD Hynix**), из ID-байтов выводит page size (0x800 << …), OOB-размер (по таблице), block size (0x10000/0x20000 << …) и число плоскостей (2 для multi-plane) [C1]. Дамп прошивки содержит полную таблицу описаний чипов: `NAND device: chipsize:0x%08lx, pagesize:0x%x, oobsize:0x%x, blocksize:0x%x, buswidth:0x%x` (@0x12E34C) и перечень «NAND 16MiB…2GiB, 1,8/3,3V, 8/16-bit» (@0x12CD04–0x12CFEC) — т.е. поддерживаются 8/16-битные шины и чипы 16 MiB–2 GiB [C3].

### 4.4 Регистры (regset) и MMIO

- Прямых констант MMIO-базы (0x3FFxxxxx) в flash_01.c **нет**: все обращения к регистрам идут через **regset-дескрипторы** — таблицы троек {маска/бит, офсет регистра, ширина}, из которых адрес регистра вычисляется как `MMIO_base + офсет`; база хранится в дескрипторе устройства (у `nandc_ctrl_read_normal` — поле +0x90/+0x24 структуры). Дескрипторы инициализируются в `nandc_native_host_create`/`nandc2_ctrl_init` [C1]. Конкретная база — §8.4.
- `nandc2_ctrl_init @ 0x30017248` пишет тайминговую последовательность (0x6d, 0x44, 0x66, 0x6e, 0x70, 0x10, 0x1d …) и выставляет бит 0x200 в конфиг-регистре — настройка циклов NAND-интерфейса для варианта V2 [C1].
- ECC: в `nandc_host_set_partition @ 0x30013920` на каждый раздел в mtd-дескриптор прописывается ECC-способность (из спецификации чипа, поле +0xC дескриптора) [C1]. Схема ECC (Hamming 1-bit / BCH) по коду однозначно не определена — §8.5.

### 4.5 Инициализация и raw-API

Порядок: `nand_init_platform @ 0x3000F280` → `nandc_nand_init @ 0x3001505C`: создать хост (`nandc_native_host_create`) → распознать чип (один повтор при сбое) → `nandc_init_mtd_partition @ 0x30014FF4` (`ptable_parse_mtd_partitions` + `nandc_host_set_partition`: mtd-записи по 0x18 байт с кумулятивным offset и ECC-способностью) → `set_chipparam` [C1].

Raw-API (flash_01.c, адреса [C2]): `nand_run @ 0x3000F41C` (прогон командного автомата), `nand_read @ 0x3000F71C`, `nand_get_spec @ 0x3000F78C`, `nand_read_oob @ 0x3000F7F4`, `nand_isbad @ 0x3000F9AC` (маркер bad-блока в OOB), `nand_erase @ 0x3000FA64`, `nand_write @ 0x3000FABC`, `nand_write_oob @ 0x3000FB2C`, `nand_scan_bad @ 0x3000FC64` (полное сканирование, 380 байт), `nand_erase_all @ 0x300176F0`. Сигнатуры восстановлены по вызовам: `nand_read(offset, buf, len, *out_len)`, `nand_isbad(block, *state)`, `nand_erase(block)` [C1].

Плохие блоки: `nand_scan_bad` заполняет карту; `ptable_flash_prepare @ 0x3002CD30` вызывает `nand_scan_bad(offset, size, 1)` перед записью раздела (режим из битов 0–2 flags: ==0 требует только bad-карту) [C1]. Сканирование с сообщениями `BSP_NANDF_Scan:nand_isbad %d failed!` (@0x12E5EC) [C3].

### 4.6 Yaffs-доступ на уровне контроллера

- `nand_read_yaffs @ 0x3000F964` / `nand_write_yaffs @ 0x3000FC1C` переводят номер чанка в (column, page): column = (chunk & col_mask) << shift, page = chunk >> col_bits; чтение — команда 0x30, запись — 0x10 (единая функция FUN_300161C8) [C1].
- `nandc_nand_yaffs_read @ 0x30014148` / `nandc_nand_yaffs_write @ 0x3001514C` — обёртки nandc-уровня; **запись проверяется чтением назад** (memcmp данных+OOB из верификационного буфера хоста, поле +0x368) [C1].
- Размер чанка: `nand_yaffs_write_size @ 0x3000F86C` = `(page_data_size + 0x10) * count`; обратный пересчёт `nand_yaffs_data_size @ 0x3000FDE0` = `bytes / (page+0x10) * page` — **OOB на чанк = 16 байт** [C1].

---

## 5. YAFFS

### 5.1 Монтирование

- `yaffsInit @ 0x30022744` → `ptable_yaffs_mount @ 0x3002D35C`: проход по всем записям ptable; для записей с **flags & 0x600 != 0** и size != 0 — `yaffsDevCreate(index, offset, offset+size, name)` (индекс устройства = порядковый номер среди yaffs-разделов) [C1].
- `yaffsDevCreate @ 0x300227F4` (616 байт) создаёт устройство и монтирует; строки: `yaffs: Mounting %s` (@0x1301E4, VA 0x30133E24), `yaffs: ERROR !! too many partition mount!` (@0x130210 — лимит числа yaffs-разделов), `yaffs: %s already mounted` (@0x13023C), `yaffs: cfgList error` (@0x1301F8 — ошибка списка конфигураций устройств) [C3].
- Точечное монтирование: `ptable_yaffs_mount_byname @ 0x3002D4B0` → `yaffs_mount`; размонтирование `ptable_yaffs_unmount_byname @ 0x3002D5D4` [C1].
- При изменении карты разделов: `ptable_prepare_yaffs: yaffs changed (%s)` (@0x131A38) [C3].

### 5.2 Конфигурация и интерфейс

- Адаптер к FS: `ynandif_WriteChunkToNAND @ 0x30026334`, `ynandif_ReadChunkFromNAND @ 0x300263D4`, `ynandif_EraseBlockInNAND @ 0x30026474`, `ynandif_InitialiseNAND @ 0x300264F4` (data_01.c) — стандартный yaffs-direct интерфейс; ошибки: `ynandif_WriteChunkToNAND:write page %d error!` и т.д. (@0x13032C–0x1303C0) [C2/C3].
- Сборка поддерживает yaffs1/yaffs2 и inband-tags: строка `yaffs: NAND geometry problems: chunk size %d, type is yaffs%s, inbandTags %d` (@0x12F778) [C3]. Фактически используемый режим — чанк = страница + **16 байт OOB** (см. §4.6), т.е. теги в OOB, YAFFS1-стиль; печатается `yaffs: restored from checkpoint` (@0x12F87C) — checkpoint-механизм yaffs2 присутствует [C3].
- GC/структуры: стандартные строки yaffs (`yaffs: GC erasedBlocks %d aggressive %d` @0x12F334, `yaffs: yaffs_GutsInitialise()` @0x12F740 и др.) [C3].

### 5.3 Теги

- Теги YAFFS хранятся в 16-байтовом OOB-пространстве чанка: доступ идёт через `nand_read_oob/nand_write_oob(..., 0x10, ...)` (см. `ptable_read_by_type` mode 1) и через nandc-yaffs-обёртки [C1].
- Поле тегов (chunkId, objectId, serial, ECC) в реконструкции не разобрано по байтам — §8.5. ECC-коррекция для тегов/данных — через nandc (аппаратная способность на раздел) + возможная софтверная ECC YAFFS (в строках дампа прямых упоминаний `yaffs_ECC*` не найдено).

---

## 6. NVM / nvim / Lnvm — NV-переменные

### 6.1 Диспетчер NVM

- `NVM_Read @ 0x3009B480` / `NVM_Write @ 0x3009B52C`: получают контекст (`(*DAT_3009bbac)()`), проверяют состояние init (через `(*DAT_3009bbb0)()`), затем ищут **бэкенд по диапазону id**: таблица из **2 записей по 0xC байт** — {упакованный диапазон (min & mask, max = hi>>0x10), fn_read, fn_write}; id вне диапазонов → код **0x208** [C1].
- Вызывающие NVM_Read (doc-заголовок): `BSP_PMU_AptEnable`, `BSP_PMU_BoardInit`, `exchReadConfig`, `os_nv_read` — NV-сервис используется подсистемами платы и ОС [C1].
- `NVM_Init @ 0x3009B730` (строка ` NVM_Init start!` @0x1515AC): state = 3 → init → 2 при успехе / 1 при провале; при провале init-хранилища вызывается сервисный обработчик и лог `(*DAT_3009bbe4)(6, ret, 0, 5)` [C1/C3].
- `NVM_Flush @ 0x3009B5D8` — вызов flush-функции контекста (+0x30); `NVM_IoRegister @ 0x3009B684` — регистрация IO; `NVM_GetItemLength @ 0x3009BAA8`, `nvim_GetItemLenById @ 0x3009DAB4` [C1/C2].

### 6.2 Upgrade / Factory NV (уровень NVM)

- `NVM_UpgradeBackup @ 0x3009B7DC`, `NVM_UpgradeRestore @ 0x3009B870` — бэкап/восстановление NV при обновлении (строки лога @0x1515C0/@0x1515E4) [C1/C3].
- `NVM_BackUpFNV @ 0x3009B900` — обходит **оба бэкенда** и вызывает их функцию с параметром 3 (бэкап Factory NV; строка ` NVM_BackUpFNV ulRet = %d` @0x151604) [C1/C3].
- `NVM_RevertFNV @ 0x3009B990`, `NVM_SetFactoryDefault @ 0x3009BA1C`, `NVM_AutoRestoreNV @ 0x3009B670`, `NVM_IsReStoreFunAll @ 0x3009BB54` [C2].

### 6.3 nvim — структура main-info (RAM-индекс)

Из `nvim_ShowNvimInfo @ 0x3009FB10` (628 байт) и строк печати [C1/C3]:

```
pstNvimInfo:                          // база (DAT_3009fd3c)
  +0x000: usSectionNum                // печать заголовка; цикл < 2
  +0x004: stSectionInfo[2]            // stride 0x7C (puVar4 += 0x1F dword)
            ulRange[0]                // +0x48 внутри секции (строка @0x151BB8)
            ulRange[1]                // +0x4C (строка @0x151BEC)
            usTotalNviNumber          // +0x50, ushort (строка @0x151C20)
            ulTotalNviSize            // +0x54 (строка @0x151C58)
            ulSectionId               // +0x7C от начала секции (строка @0x151CC0/печать puVar4[0x1F])
  +0x3E4+: индекс элементов, stride 0xC (puVar4 += 3):
            usNviNumber/usItemId      // ushort-поля по офсетам DAT_3009fd48/DAT_3009fd50
            ulFlashOffset             // +0x3E8 от базы (1000 dec; печать @0x151D18)
            usPriorityLevel           // +0x3EC, ushort (строка @0x151D4C)
            usPriorityRatio           // по офсету DAT_3009fd50 (строка @0x151D80)
```

Согласование: в `Lnvm_InitMainInfo @ 0x3009F780` офсет элемента во flash пишется именно в `*(int*)(pstNvimInfo + idx*0xC + 1000)` — 1000 = 0x3E8 = ulFlashOffset [C1]. Два раздела (stSectionInfo[2]) соответствуют двум бэкендам диспетчера NVM (§6.1).

Поиск: `nvimDimidiateSearch @ 0x3009E274` (поиск по диапазону id), `LnvmSearchById @ 0x3009E3A4`, сортировка `LnvmIndexOrder @ 0x3009E468` (384 байта — упорядочивание по приоритету) [C2]. Блокировки индекса: `LnvimLockIndexInfo/UnLockIndexInfo @ 0x3009E214/0x3009E244`, создание индексов `LnvimCreateIndexInfo/CreateNvASynIndexInfo @ 0x3009E1B4/0x3009E1E4` [C2].

### 6.4 Lnvm — файловый NV (HNV) и FactoryNV

- **Хранение на YAFFS**: `Lnvm_WriteToHNV @ 0x3009E728` — fopen/fwrite/fclose через указатели функций; путь выбирается по флагу (`DAT_3009f69c` или `DAT_3009f6a0`); известный путь: **`/modem/modem_image/nv_bak/NV.HNV`** (@0x18D588, VA 0x301911C8) [C1/C3]. Приоритетная запись: `Lnvm_WritePriorityHNV @ 0x3009CC1C` (476 байт; лог ошибки @0x1516BC) [C1/C3].
- **RAM-образ**: `Lnvm_ReadFromMemory @ 0x3009E5E8` — memcpy из RAM-буфера NV (`*DAT_3009f550 + offset`) при выставленном флаге инициализации; `Lnvm_WriteToMemroy @ 0x3009E664` — обратная запись [C1].
- **Раскладка flash-NV** (`Lnvm_InitMainInfo @ 0x3009F780`, 912 байт) [C1]:
  - база образа `*DAT_3009fd1c`; при `*(char*)*DAT_3009fd14 == 1` — чтение заголовка файла версии по смещению **+0x17C** (4 байта);
  - секции начинаются с **+0x1A0**, шаг **0x7C**; заголовок секции содержит число элементов по смещению **+0x50** (ushort);
  - элементы внутри секции: **4-байтный заголовок** (id + размер/служебное полуслово; точное деление — §8.6), затем данные; продвижение `iVar7 += 4 + size`;
  - число секций — ushort по смещению **+100 (0x64)** от базы; для каждого элемента: поиск/создание слота индекса (`(*DAT_3009fd4c)(id, &idx)`) и запись `ulFlashOffset = iVar7 + 4` и размера в слот.
- **FileCheck/приоритеты**: `Lnvm_FileCheck @ 0x3009F62C` (печать `ulFileFormat=%d, usSectionNum=%d` @0x151B30), `Lnvm_PrioFileCheck @ 0x3009F4CC`, `Lnvm_NoPrioFileCheck @ 0x3009F370` — файлы Factory NV делятся на приоритетные/неприоритетные (ulPriorityLevel/ulPriorityRatio в индексе, сортировка LnvmIndexOrder) [C1/C3].
- **Restore/Backup Factory NV**: `Lnvm_BackupFactoryNV @ 0x3009DFD0`, `Lnvm_RevertFactoryNV @ 0x3009DED4`, `Lnvm_RestoreFactoryNv @ 0x3009F120`, варианты `Lnvm_RestorePrioFactoryNv @ 0x3009EF28` / `Lnvm_RestoreNoPrioFactoryNv @ 0x3009ED90`, чтение Factory из backup-домена `Lnvm_Read_FactoryNV_From_Backup_Domain @ 0x3009EC30`, `Lnvm_ReadBackUpData @ 0x3009EB3C` [C2].
- **Backup-домен**: файловый и флешевый варианты — экспорт-имена `Lnv_Backup_To_File`, `Lnv_Backup_To_Flash`, `Lnv_Read_Backup_Data_From_File`, `Lnv_Read_Backup_Data_From_Flash`, `Lnv_Read_From_Backup_Domain`, `Lnv_Write_To_Backup_Domain` (строки-имена @0x160908–0x1608D4); файловая обвязка `Lnv_File_Open/Read/Write/Seek/Close/Remove/Ftell` (@0x160828–0x160868) [C3]. Запись во flash-бэкап: `NVBackupFlashDataWrite` (строки ошибок @0x1406D4–0x140808: проверка выравнивания на 2 байта, «get flash address error», «offset is out of flash memery») [C3].
- **Флеш-адрес NV**: `Lnvm_SetFlashAddr/GetFlashAddr @ 0x3009E194/0x3009E1A0`; бэд-блоки: `Lnvm_NandIsBad @ 0x3009E8F4`, `Lnvm_NandBadCount @ 0x3009E908` (учёт плохих блоков в области NV) [C2].
- **Обновление**: `LNVM_UpgradeBackup @ 0x3009DC44` / `LNVM_UpgradeRestore @ 0x3009DD44` (data_06.c), `Is_LnvmNeedRestore @ 0x3009F25C`, флаги `Lnvm_SetUpgradeOpFlag/GetUpgradeOpFlag @ 0x3009F358/0x3009F364`, `Lnvm_SetUpgradeRestoreFlags @ 0x3009F754`, `Lnvm_SetRestoreFlag/IsRestoreOK @ 0x3009ED20/0x3009ED2C` [C2].

---

## 7. Взаимосвязь с DLOAD (кто пишет разделы)

Цепочка записи образа (по doc-заголовкам «Вызывают/Вызывает» [C1] и адресам [C2]):

1. **Источник данных**: `dloadFromFsMainThread @ 0x30078688` и родня (`dloadFromFsGetUnitHeadData @ 0x30077488`, `dloadFromFsGetUnitData @ 0x30077D88`, `dloadFromFsReadDataFromFS @ 0x30077AEC`, `dloadFromFsCheckSpaceForISO @ 0x300779F0`) — чтение пакета из FS; `dloadUSBRecvPro` для USB-приёма (строка `rm ISO or webui version bin file` @0x145C94) [C2/C3].
2. **Размещение**: `ImageDloadToFlash @ 0x30082428` / `ImageDloadToRam @ 0x30082FA4` (data_05.c) вызывают `ptable_find_older_part` — выбор A/B-копии раздела по type и продвижение счётчика поколений [C1/C2].
3. **Порционная запись**: `FUN_30081F50` / `FUN_300827C0` (dload-окружение, 0x30081xxx–0x30082xxx) вызывают `ptable_dload_write @ 0x3002CF9C`:
   - type **0x100** → `FUN_3002CD64` — приём **новой ptable** из потока (далее merge через `ptable_replace_ram_table` и запись в 0x1E000);
   - иначе: поиск раздела, при первом блоке — `ptable_flash_prepare` (`nand_scan_bad`; режим = биты 0–2 flags, при стирании bad-блоки форсируются при `param_2==1` в `ptable_erase_partition @ 0x3002BE0C`);
   - запись через `ptable_write_by_type` (mode 0 = `nand_write`, mode 1 = `nand_write_oob` по 16B-OOB чанкам, для yaffs-режима объём пересчитывается `nand_yaffs_data_size`);
   - прогресс и курсор — поля +0x14 (записано) / +0x10 (адрес) записи ptable [C1].
4. **Финализация**: `dloadBootromEnd @ 0x30076EC0` и `dloadFromFsMainThread` вызывают `ptable_set_integrality @ 0x3002BB10` (сброс/установка bit0 head+0x0C, печать `ptable_set_integrality is %d` @0x1316F4) и `ptable_replace_flash_table` (запись таблицы в 0x1E000) [C1/C3]. Строка `ptable check error!` (@0x1316DC) соответствует проверке `ptable_check_integrality`.
5. **Чтение/проверка**: `ptable_dload_read @ 0x3002D200` (по type), `ptable_quary_partition`/`ptable_erase_partition` (обслуживание bad-блоков), `ptable_get_range @ 0x3002C0F0` (границы), `secIsSecVer` — проверка версии секции через `ptable_find_by_type` [C1/C2].
6. **NV при обновлении**: `BSP_DLOAD_GetNVBackupFlag` (имя @0x15E448), `NVM_UpgradeBackup/Restore`, `LNVM_UpgradeBackup/Restore`, `update_WebUITask: ... backup NV by OAM` (@0x142D94) — бэкап NV до обновления и восстановление после [C2/C3].

Граф вызовов записи образа (по doc-заголовкам [C1]):

```
dloadFromFsMainThread (0x30078688)
   ├─► dloadFromFsGetUnitHeadData (0x30077488) / GetUnitData (0x30077D88)
   │        └─► ptable_get_ram_data / ptable_find_by_type   // границы раздела
   ├─► ImageDloadToFlash (0x30082428) ─► ptable_find_older_part (A/B)
   │        └─► ptable_replace_flash_table (0x1E000)        // при смене validity
   ├─► FUN_30081F50 / FUN_300827C0 ─► ptable_dload_write (0x3002CF9C)
   │        ├─► ptable_flash_prepare ─► nand_scan_bad
   │        └─► ptable_write_by_type ─► nand_write / nand_write_oob(0x10)
   └─► ptable_set_integrality + ptable_replace_flash_table  // финализация

dloadBootromEnd (0x30076EC0) ─► ptable_set_integrality / ptable_replace_flash_table
```

---

## 8. Открытые вопросы (待证)

1. **Имена разделов дефолтной таблицы.** Блоб DAT_3002c438/448/44C/454 (flash_03.c, данные ~0x3002C438–0x3002C4xx) содержит имена/флаги/записи дефолта. Как проверить: найти определения этих DAT в `decompiled_all.c`/data-файлах (grep по `3002c438|3002c454|3002c46c`), выгрузить 0x400 байт по file_off = VA − 0x30004000 + 0x3C0 и разобрать как head+записи по 0x30. Альтернатива — сэмулировать `ptable_show`.
2. **Семантика validity-бита (bit3 поля +0x28).** Судя по `ptable_find_by_type` (фильтр `validity == 0`), активная копия имеет bit3 = 0; `ptable_set_validity(0)` — установить бит. Нужно подтвердить порядок A/B при первом цикле записи (трассировка `ImageDloadToFlash` → `ptable_find_older_part` с flag=0).
3. **NANDC_V3.20/V4.00.** Есть ли в usbl инициализации nandc3/nandc4: grep `nandc3|nandc4|NANDC_V3|NANDC_V4` по `usbl_src/index/ALL_FUNCTIONS.tsv` и `decompiled_all.c`.
4. **MMIO-база NANDC.** Прямых констант в flash_01.c нет; база зашита в regset-дескрипторах. Как проверить: в `nandc_native_host_create @ 0x30016D78` и `nandc2_ctrl_init @ 0x30017248` отследить источник поля базы (DAT-константы → `decompiled_all.c`/data_*.c), либо grep `0x3FF0|0x9000[0-9A-F]{4}` по data-файлам.
5. **ECC-схема и теги YAFFS.** Не определено: битность ECC (Hamming/BCH), полная раскладка 16-байтового OOB (теги + ECC байт-уровни). Как проверить: тело `nandc_ctrl_read_normal`/`nandc_host_set_partition` (ECC-способность в mtd-дескрипторе) + разбор OOB-буфера в `nandc_nand_yaffs_read`; сравнить с эталонной раскладкой YAFFS1-тегов (18→16-байт packed tags).
6. **Раскладка 4-байтного заголовка элемента NV** в `Lnvm_InitMainInfo` (id + размер? два ushort?) и офсеты полей индекса DAT_3009fd48/DAT_3009fd50. Как проверить: прочитать тела `Lnvm_InitMainInfo`/`nvim_ShowNvimInfo` в flash_04.c целиком (выжимка обрезана на ~1316 символах хвоста) и значения DAT-констант.
7. **Второй путь HNV-файла** (DAT_3009f69c vs DAT_3009f6a0): первый — `/modem/modem_image/nv_bak/NV.HNV`; второй, вероятно, основной файл NV на yaffs-разделе. Как проверить: распечатать строки-указатели в data-файлах (`grep -i "HNV\\|nv_bak\\|nvm_image" firmware_strings.txt`).
8. **Содержимое полей записи ptable +0x1C/+0x20** (сверяются при merge, но не печатаются семантически): вероятные кандидаты — flags2/checksum/приоритет загрузки. Проверка: разбор дефолтного блока (вопрос 1) и трассировка `ptable_dload_write`.
9. **Копий ptable больше одной?** Все найденные записи таблицы идут в 0x1E000. Возможна резервная копия вне usbl (в полной прошивке Balong ptable обычно дублируется). Проверка вне скоупа usbl — по дампам полной прошивки.

---

## 9. Сводные константы

| Константа | Значение | Где |
|---|---|---|
| Смещение ptable во flash | 0x1E000, длина 0x400 | `ptable_replace_flash_table @ 0x3002C988` [C1] |
| Размер head / записи ptable | 0x30 / 0x30 (до 20 записей) | код ptable_* [C1] |
| YAFFS-флаг раздела | flags & 0x600 (поле +0x28) | `ptable_yaffs_mount @ 0x3002D35C` [C1] |
| Режим записи раздела | flags & 7 (0 = raw, 1 = +16B OOB) | `ptable_read/write_by_type` [C1] |
| OOB на YAFFS-чанк | 16 байт | `nand_yaffs_write_size @ 0x3000F86C` [C1] |
| Page size | 0x200/0x800/0x1000/0x2000 | `nandc_host_add_nand_chip @ 0x30013DD4` [C1] |
| Block size | 0x8000/0x20000/0x40000/0x100000 | там же [C1] |
| Адресных циклов | 4 (5 при >128 MB) | там же [C1] |
| Производители чипов в коде | 0xEC (Samsung), 0xAD (Hynix) | `nandc_native_get_spec @ 0x3001669C` [C1] |
| Секции NV во flash | +0x1A0, шаг 0x7C, счётчик по +0x64 | `Lnvm_InitMainInfo @ 0x3009F780` [C1] |
| Индекс NV-элементов | stride 0xC, ulFlashOffset @ +0x3E8 | `nvim_ShowNvimInfo @ 0x3009FB10` [C1] |
| Бэкап NV-файла | /modem/modem_image/nv_bak/NV.HNV | строка @0x18D588 [C3] |
| Код ошибки «id вне диапазона» NVM | 0x208 | `NVM_Read/Write` [C1] |

*Документ построен на статическом анализе реконструкции; пункты §8 — места, где доказательная база неполна. Scratch-выжимка тел функций: `scratch_flash_extract.txt` (корень workspace).*

---

## 9. Дополнение (2026-10-19): дефолтная ptable расшифрована

Имена, смещения, размеры и типы всех 17 разделов извлечены из .data-блоба `DAT_3002c454` → таблица @0x3018000C (полная таблица и метод — **docs/11_FLASH_MAP.md**): `BootLoad` (0x0, 128 КБ, Bootloader_R1 — раздел USBL), `NvBackLTE` (0x20000, 1.5 МБ), `NvBackGU` (0x1A0000, 1 МБ), `BootRom` ×2 (0x2A0000 и 0x4A0000, по 2 МБ — A/B!), `VxWorks` (0x6A0000, 32 МБ), `Logo`, `/yaffs0` (0x26A0000, 12 МБ), `FastBoot` (0x32A0000, 384 КБ), **`kernel` (0x3300000, 3 МБ, Kernel_R1)**, `/yaffs1` (0x3600000, 28 МБ, System_R1), `/yaffs2..6` (динамические, 0x5200000), `cdromiso` (0x5200000, 174 МБ). Поле +0x1C/+0x20 записи — load-адрес (для BootLoad — 0x2FFC0000). **NAND ровно 256 МБ** (cdromiso до 0x10000000). Пункты §8.1 и вопрос имён разделов — ЗАКРЫТЫ.
