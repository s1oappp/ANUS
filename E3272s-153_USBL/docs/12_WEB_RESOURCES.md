# scratch_linux_web.md — веб-разведка: Linux на Huawei Balong (цель — E3272s-153, V7R1 / Hi6920)

Составлено: 2026-10-19. Задача: собрать публичные наработки по (1) инструментам Balong-загрузчиков,
(2) портам Linux на Balong-модемы и mainline-статусу HiSilicon, (3) карте разделов E3272s/E3372 и режимам
загрузки, (4) параметрам Hi6920 (CPU/RAM), (5) прецедентам запуска Linux через USB-загрузчик.
Формат: рабочий конспект; у каждой строки факта — URL источника и метка уровня доверия.
Локальные материалы workspace (дампы, USBL-анализ) в этот файл сознательно НЕ переносятся.

Метки доверия: [код] — первичный код/скрипт в репозитории; [README] — декларации автора репо;
[док] — официальные материалы Huawei/пресса/вики; [блог] — профильный блог с проверенным fetch;
[сниппет] — виден только поисковый фрагмент (сама страница по fetch не открывается);
[гип] — гипотеза, первичного подтверждения нет; [негатив] — отрицательный результат поиска.

---

## 1. Инструменты работы с Balong-загрузчиками (GitHub)

### 1.1 forth32/balongflash — прошивальщик из download-режима (dload)
- Репозиторий: https://github.com/forth32/balongflash — прошивка модемов Huawei из download-режима, GPLv3, ~214★, ~112 коммитов. [код]
- Версия V3.0.x, © forth32 2015; Windows-порт © rust3028 2016 — README репозитория. [код]
- Состав дерева: balong_flash.c, ptable.c/.h, signver.c/.h, flasher.c/.h, hdlcio_linux.c, hdlcio_win32.c, util.c, lzma/. [код]
- Цепочка протокола: open_port → dloadversion() → send_signver() → enter_hdlc() → protocol_version() → dev_ident() → flash_all() → restart_modem()/leave_hdlc() — https://raw.githubusercontent.com/forth32/balongflash/master/balong_flash.c [код]
- Смысл шагов: dloadversion — запрос версии загрузчика; send_signver — согласование проверки подписи; enter_hdlc — переключение порта в HDLC-режим; dev_ident — идентификация устройства; flash_all — прошивка всех разделов пакета. [код]
- Ключи CLI: -p (порт), -n, -g, -m, -e, -s (файл без подписи), -k (ключ), -r, -f, -d (dload_id 0..15; id>7 = подписанный файл) — https://raw.githubusercontent.com/forth32/balongflash/master/balong_flash.c [код]
- Заголовок раздела fw-файла (ptable.h): magic=0xa55aaa55, hdsize, hdversion, unlock[8], code, psize, date[16], time[16], version[32], crc, blocksize — https://raw.githubusercontent.com/forth32/balongflash/master/ptable.h [код]
- BIN-префикс 0x5c байт (заголовок 0x60, первый байт = dload_id); блочные CRC16 по данным раздела — ptable.c. [код]
- Сжатие разделов: zlib (магия 0xda78) и LZMA (первый байт 0x5d + 0xffffffffffffffff по смещению +5) — ptable.c. [код]
- Коды разделов fw-пакета (pcodes): M3Boot 0x20000, Ptable 0x10000, Fastboot 0x110000, Logo 0x130000, Kernel 0x30000, VxWorks 0x40000, M3Image 0x50000, DSP 0x60000, Nvdload 0x70000, Nvimg 0x80000, Oeminfo 0xa0000, CDROMISO 0xb0000, Userdata 0x190000, System 0x100000/0x590000, APP 0x570000/0x5a0000, WEBUI 0x560000/0x5b0000, Modem_fw 0x1e0000 — https://raw.githubusercontent.com/forth32/balongflash/master/ptable.c [код]
- Коды R11 (V7R11): Kernel_R11 0x90000, VxWorks_R11 0x220000, M3Boot_R11 0x200000, DTS_R11 0x270000, DSP_R11 0x240000, Nvdload_R11 0x250000, HIFI_R11 0x280000, Teeos 0x290000 — там же. [код]
- Коды R1 (поколение V7R1): Ptable_R1 0x100, Bootloader_R1 0x101, Bootrom_R1 0x102, VxWorks_R1 0x550103, Fastboot_R1 0x104, Kernel_R1 0x105, System_R1 0x107, Nvimage_R1 0x66, WEBUI_R1 0x113, APP_R1 0x109 — там же. [код]
- Вывод: balongflash изначально поддерживает V7R1-поколение (отдельный набор _R1-кодов) — инструмент применим к E3272s-153 напрямую. [код]

### 1.2 forth32/balong-usbdload — аварийная загрузка usbloader по USB
- Репозиторий: https://github.com/forth32/balong-usbdload — «Утилита для аварийной USB-загрузки модемов на чипсете Balong V2R7, V7R11 и V7R22. Позволяет загрузить внешний загрузчик-прошивальщик (usbloader)» — README. [код]
- V7R1 в README НЕ заявлен — для V7R1 загрузчики ищутся на форумах (ниже). [код]
- Сценарий входа: аварийный USB-serial порт при повреждении прошивки либо замыкании boot-pin на землю — README. [README]
- Репо содержит/автопатчит загрузчики, чтобы не стирать NAND/NVRAM (usblsafe) — README. [README]
- Исходные загрузчики берутся из технологических прошивок с «99» в версии (пример 21.170.99.03.00) — README. [README]
- Win-сборки поддерживал rust3028 — README/форумы. [README]
- V7R1-загрузчики (usbloader и usblsafe) для E5372, E5776s, E392s, E3276, E5375 «и других» выкладывались на 4pda — https://4pda.to/forum/index.php?showtopic=744265&st=240 [сниппет]
- «Original Huawei USB loaders erase NAND flash when loaded. usblsafe.bin "safe" loaders are patched to disable flash erasure procedure» — https://4pda.to/forum/index.php?showtopic=553049&st=1640 [сниппет]
- AUR-описание пакета: «Low level USB Flashing/downloader utility for Huawei E3372 and other modems based on Balong v7. Includes temporary usb loader firmware for some devices» — https://aur.archlinux.org/packages/balong-usbdload-git [док]
- Пример сценария (E5770): замыкание иглой, устройство на 3-м порту, `balong_usbdload.exe -p3 usbloader-e5770.bin`, «модем перешел в режим ожидания загрузки» — https://4pda.to/forum/index.php?showtopic=818849&st=300 [сниппет]

### 1.3 zer0325/balong-malalim — независимая реимплементация
- Репозиторий: https://github.com/zer0325/balong-malalim — альтернативная реализация протокола usbdload. [код]
- Разбор forth32's balong-usbdload (zer0325, 04.09.2020): https://zer0325.github.io/2020/09/04/Analyzing-forth32's-balong-usbdload-software.html [блог]

### 1.4 Прочие утилиты forth32
- balong-nvtool — редактор NVRAM через dload-протокол; список NV-ID в nvid.c (L27): https://github.com/forth32/balong-nvtool [код]
- balong-fbtools — работа с fastboot-загрузчиком модема (если раздел Fastboot присутствует): https://github.com/forth32/balong-fbtools [код]
- qhuaweiflash — GUI-обёртка прошивки: https://github.com/forth32/qhuaweiflash [код]
- Чек-лист инструментов: разбор/прошивка fw → balongflash; аварийная загрузка → balong-usbdload; NVRAM → nvtool; fastboot → fbtools; дамп NAND → raw-dump-tools (ниже). [код]

### 1.5 Организация Huawei-LTE-routers-mods
- README-репо — ссылочная база и карта платформ: https://github.com/Huawei-LTE-routers-mods/README [код]
- balong_series.md — сводка поколений Balong (детали в секции 2): https://github.com/Huawei-LTE-routers-mods/README/blob/master/balong_series.md [код]
- useful_software_posts_and_links.md — подборка ссылок на софт/посты: https://github.com/Huawei-LTE-routers-mods/README/blob/master/useful_software_posts_and_links.md [код]
- huawei_balong_modfw_kitchen — «Инструмент для модификации прошивок модемов Huawei», семейства V7R1/V7R2/V7R11: https://github.com/Huawei-LTE-routers-mods/huawei_balong_modfw_kitchen [код]
- Kitchen умеет: вшить ADB/Telnet, патчить загрузку неподписанных модулей ядра (прошивки 21.333+), Entware, OpenVPN, скрипты IMEI/TTL. [код]
- balong-signcheck — разбор secuboot/проверки подписи (актуально для V7R11+): https://github.com/Huawei-LTE-routers-mods/balong-signcheck [код]
- balong-raw-dump-tools — конвертация RAW NAND-дампа (с OOB/ECC, снятого программатором) в «Huawei block format»: https://github.com/Huawei-LTE-routers-mods/balong-raw-dump-tools [код]

### 1.6 Balong USB Downloader (decker.su) — Delphi-порт
- Статья (март 2016): https://decker.su/2016/03/balong-usb-downloader-huawei-recovery.html [блог]
- Аварийный порт определился как «BOOT_3G», VID_12D1 & PID_1443. [блог]
- Фирменный usbloader.bin стирает флеш, включая NVRAM; безопасные usbsafe-xxx.bin — патчи от forth32. [блог]
- Сценарий: восстановление «непрошиваемых» MTS 829F/827F (E3372H, fw 21.315.01.00.143) через «иглу» + usbdload. [блог]

### 1.7 Примечание об авторах (расхождение с постановкой задачи)
- Во всех проверенных источниках автор утилит balong* — forth32 (Win-сборки — rust3028); zer0325 — реимплементация. [код]
- Аккаунт «forstackoverflow1» публично не подтвердился: репозиториев balong_flash/balong-usbload/balong-nvtool под этим именем поиском не найдено (GitHub/Google, 2026-10-19). [негатив]
- Ближайшие по смыслу имена из задачи: balongflash (п.1.1) и balong-usbdload (п.1.2). [код]

## 2. Порты Linux на Balong-модемы и mainline-статус HiSilicon

### 2.1 Карта платформ (balong_series.md)
- Архитектура Balong V7: 2×ARMv7 (ядра Linux и VxWorks) + 1×Cortex-M3 (boot/M3 monitor) + ConnX BBE16 DSP — https://github.com/Huawei-LTE-routers-mods/README/blob/master/balong_series.md [код]
- V7R1 = Hi6920: LTE cat4; 256MB NAND, 128MB RAM (15MB свободно в Linux); Wi-Fi BCM43241; штатный Linux 2.6.35.7 с Android-модификациями; ARMv7 без FPU; модели: E3272, E3276, E5372, E5172, E5180, B593s. [код]
- V7R2 = Hi6930: 128MB NAND, 128/256MB RAM, Linux 3.4.5; E3372s, E5373, E5377, E5786 и др. [код]
- V7R11 = Hi6921: Linux 3.4.5, vfpv3d16; E3372h, E8372, E5573 и др. [код]
- V7R22 = Hi6932/Hi6931: Linux 3.10.59, vfpv4+NEON; E5785, E5885; B-роутеры — Hi6931. [код]
- Старшие/прочие: V7R5 = Hi6950, V6R65 = Hi6965, серия 5000 = Hi9500. [код]

### 2.2 Главный прецедент: hitechshell на E8372h-153 (V7R11)
- balong-kernel — своё ядро Linux для E8372h-153, сборка gcc 4.6; в README зафиксировано «Its WORK!» — https://github.com/hitechshell/balong-kernel [код]
- Параметры boot.img (mkbootimg): --base 0x54c08000 --kernel_offset 0x00008000; cmdline «root=/dev/ram0 rw console=ttyAMA0,115200 console=uw_tty0,115200 rdinit=/init loglevel=5 mem=0x3300000» — README balong-kernel. [код]
- Раздел kernel на флеше = mtd7; перед образом ядра 128-байтный заголовок ptable (dd skip=128) — README balong-kernel. [код]
- balong-m3boot — реконструкция boot-кода Cortex-M3 (тулчейн armv7a): https://github.com/hitechshell/balong-m3boot [код]
- balong-legacy-bootloader — реконструкция загрузчика (gcc 4.6 из android-ndk-r9d, `make fastboot.img`): https://github.com/hitechshell/balong-legacy-bootloader [код]
- balong-raminit — инициализация RAM отдельным payload: https://github.com/hitechshell/balong-raminit [код]
- usbload-balong — заливка payload по serial: `./usbload --raminit --payload --payload_addr 0x57d00000 --port /dev/ttyUSB0`, затем `fastboot flash fastboot/m3boot`: https://github.com/hitechshell/usbload-balong [код]
- Запуск своего ядра: `fastboot oem m3boot && fastboot boot new_boot.img` — README balong-kernel. [код]
- u-boot-balong — «Experimental U-boot fork for BalongV7 chips», ветка huawei_modem (WIP, форк u-boot/u-boot): https://github.com/hitechshell/u-boot-balong [код]

### 2.3 Родственный гайд: E3372h (V7R11), sh.com.hr
- Статья (14.07.2015): https://sh.com.hr/huawei-e3372/huawei-e3372-lte-modding [блог]
- DEBUG-режим включается XML POST switchMode на http://192.168.8.1/CGI. [блог]
- AT^NVWREX=33,0,4,2,0,0,0 включает консольные порты; AT^NVRDEX=50502,0,128 читает OEM-ключ (50503 = NCK). [блог]
- Порт «FC – ShallB» даёт промпт EUAP>; busybox telnetd поднимает полноценный шелл. [блог]
- Раскладка: /system = mtdblock16, webui = mtdblock15 (mtd15), ядро = mtd7 (замена через flash_erase + nandwrite). [блог]

### 2.4 4pda-темы (только сниппеты — страницы по fetch не открываются)
- E3272 (М100-4/824F/824FT) — тема 508842: https://4pda.to/forum/index.php?showtopic=508842 [сниппет]
- E5372 (V7R1) — тема 618520; примеры сборки kernel-модулей: p=63653054, p=63851093: https://4pda.to/forum/index.php?showtopic=618520 [сниппет]
- Дизассемблирование VxWorks Balong (V7R11) — серия постов в теме 582284: https://4pda.to/forum/index.php?showtopic=582284 [сниппет]
- E8372 — тема 744265: модификация usbloader (p=78454912), работа с yaffs (p=72041932): https://4pda.to/forum/index.php?showtopic=744265 [сниппет]
- Изменённая таблица разделов на E3272 — пост p=77170885: https://4pda.to/forum/index.php?showtopic=508842&p=77170885 [сниппет]
- Зеркало GPL-исходников Huawei: ftp://serv.valdikss.org.ru/Downloads/Huawei_Open_Source/ [блог]

### 2.5 Mainline-статус HiSilicon (телефонные SoC ≠ модемные Balong)
- arch/arm/mach-hisi поддерживает: ARCH_HI3xxx (телефонные Hi36xx), ARCH_HIP01, ARCH_HIP04 (Cortex-A15), ARCH_HIX5HD2 (STB), ARCH_SD5203 (IoT) — https://raw.githubusercontent.com/torvalds/linux/master/arch/arm/mach-hisi/Kconfig [код]
- Патч HiP01 (Wang Long, Huawei, 23.12.2014): «Enable Hisilicon HiP01 SoC. This HiP01 SoC series support both one core or dual cores and quad cores. The core is Cortex A9»; compat «hisilicon,hip01», «hisilicon,hip01-ca9x2» — http://lists.infradead.org/pipermail/linux-arm-kernel/2014-December/312162.html [док]
- hip01-ca9x2.dts: dual Cortex-A9, memreserve 0x80000000 + 0x2000 (8КБ под secondary core) — https://raw.githubusercontent.com/torvalds/linux/master/arch/arm/boot/dts/hisilicon/hip01-ca9x2.dts [код]
- hip01.dtsi: GIC 0x1a001000; DW APB UART 0x10001000–0x10006000 (reg-shift=2, refclk 144МГц); sysctrl 0x10000000 (reboot-offset 0x4); global timer 0xa000200 — https://raw.githubusercontent.com/torvalds/linux/master/arch/arm/boot/dts/hisilicon/hip01.dtsi [код]
- hi3620 = K3V2 (4×Cortex-A9 1.4ГГц; Ascend P6/Mate — телефоны), hi3630 = Kirin 925 (Mate 7 — телефон), hi6220 = Kirin 620 (8×A53; HiKey — телефон) — https://en.wikipedia.org/wiki/HiSilicon [док]
- Kirin = бренд телефонных SoC, Balong = бренд модемных чипов HiSilicon — https://en.wikipedia.org/wiki/HiSilicon [док]
- Побочный штрих: Hi3798 — «SoC series for IPTV STB, with Cortex A9 or A7 cores» (внесение в mach-hisi, 2023) — https://patchew.org/linux/20230317085347.10147-1-mmyangfl@gmail.com/20230317085347.10147-4-mmyangfl@gmail.com [сниппет]
- Вывод: модемные Hi6920/Hi6930/Hi6921 (Balong V7Rx) в mainline НЕ поддерживаются; формально ближе всех HiP01 (2×A9, автор — инженер Huawei), но связь HiP01↔Hi6920 публично не подтверждена. [гип]
- Официально о Balong 710 (Hi6920): «первый LTE Cat 4 chipset Huawei», FDD+TDD, до 150 Мбит/с, MIMO 2x2/4x2, voice CS fallback — https://www.hisilicon.com/en/products/balong/balong-710 [док]
- Анонс Hi6920 (15.11.2011): первый мультимодальный TDD/FDD LTE-чип по 3GPP Release 9 — https://www.mobileworldlive.com/huawei/huawei-claims-lte-chipset-first [док]

## 3. Карта разделов E3272s/E3372 и режимы загрузки

### 3.1 Прошивочный пакет (dload-файл) — формат balongflash
- Разделы пакета распознаются по маркеру 0xa55aaa55 и pheader (структура — п.1.1); тип раздела — по полю code — https://raw.githubusercontent.com/forth32/balongflash/master/ptable.h [код]
- Для V7R1 типы кодируются набором _R1: Ptable_R1 0x100, Bootloader_R1 0x101, Bootrom_R1 0x102, VxWorks_R1 0x550103, Fastboot_R1 0x104, Kernel_R1 0x105, System_R1 0x107, Nvimage_R1 0x66, WEBUI_R1 0x113, APP_R1 0x109 — ptable.c. [код]
- Независимое подтверждение нейминга _R1 и формата: «replace the partition table in E5372 usbloader with E5775 table, you can get it in the firmware `00-00000100-Ptable_R1.bin` file. Copy&paste everything in between `pTableHead` and `pTableTail`» — https://gist.github.com/ValdikSS/323bcdfceb2f09d9c6ef02db1bc573e2 [код]
- Следствие (приём ValdikSS): usbloader можно адаптировать между устройствами, подменив внутри него таблицу pTableHead…pTableTail из Ptable_R1.bin целиевого аппарата. [код]

### 3.2 Таблица разделов на флеше (NAND ptable)
- Маркеры — текстовые «pTableHead» и «pTableTail»; сплиттер заявляет поддержку «Balong V7R1, V7R2, V7R11, V7R22, V7R5 and 5000 series» — https://raw.githubusercontent.com/Huawei-LTE-routers-mods/balong-raw-dump-tools/master/split_dump_to_partitions.py [код]
- Формат записи V7R1/V7R2: имя ASCII 16 байт + offset + size + flags (шаг 16+12 байт; разбор начинается со смещения 12 от pTableHead). [код]
- Формат записи V7R11: смещение 0x30, шаг 16+16 байт (имя + offset + loadsize + size). [код]
- Пример раскладки mtd (E3372h, V7R11): kernel=mtd7, webui=mtd15, /system=mtdblock16 — https://sh.com.hr/huawei-e3372/huawei-e3372-lte-modding [блог]
- Пример масштаба (E5885, V7R22): mtd0..mtd27, дамп через cat /dev/block/mtdblock* + nanddump — https://gist.github.com/ValdikSS/323bcdfceb2f09d9c6ef02db1bc573e2 [код]
- Имена разделов (ASCII-строки в ptable) читаются самим сплиттером из дампа — публичного прислешнота-списка для E3272 не найдено (см. 3.4). [код+негатив]

### 3.3 Режимы загрузки: normal-boot vs download (dload) vs burn/USBL
- normal-boot: штатная загрузка с NAND — мультизагрузка VxWorks (модемная логика) + Linux (UI/сеть) на двух ARMv7 — https://github.com/Huawei-LTE-routers-mods/README/blob/master/balong_series.md [код]
- download (dload): штатный загрузчик принимает прошивку по USB-serial (HDLC-протокол из п.1.1); вход — через процедуру обновления прошивки либо AT^GODLOAD — https://xn--80aegp4abom.xn--p1ai/huawei-e3272-e3276-imei-ttl-igla (игла.рф) [блог]
- burn/USBL (аварийный): срабатывает при повреждении основного загрузчика или замыкании boot-pin; принимает отдельный usbloader.bin по аварийному порту (BOOT_3G, PID 1443) — https://github.com/forth32/balong-usbdload + https://decker.su/2016/03/balong-usb-downloader-huawei-recovery.html [код+блог]
- Фирменный usbloader стирает NAND, включая NVRAM; usblsafe/usbsafe — патченные загрузчики без стирания — https://4pda.to/forum/index.php?showtopic=553049&st=1640 + decker.su. [сниппет+блог]
- Загруженный (модифицированный) usbloader открывает доступ к устройству: telnet/busybox/автозапуск payload — см. секцию 5. [код]
- Дополнительные входы в dload: AT^DATALOCK с кодом, веб-морды разблокировки (Dinis.Ru, Jager911, rust3028, Ильи Федина) — игла.рф. [блог]

### 3.4 Пробел: имена разделов флеша E3272
- Публичных источников с именами разделов E3272 (mcore/lphy/usbl и т.п.) не найдено (запросы: «mcore lphy nvdload E3272», «balong флеш разделы ptable E3272»; 2026-10-19). [негатив]
- Практический выход: снять свой дамп/ptable и разобрать сплиттером из п.3.2 — формат V7R1 подтверждён кодом. [код]

## 4. HI6920 (Balong V7R1): CPU, RAM, NAND
- Hi6920 = Balong 710: официально «первый LTE Cat 4 chipset Huawei», FDD+TDD, до 150 Мбит/с, MIMO 2x2/4x2, voice CS fallback — https://www.hisilicon.com/en/products/balong/balong-710 [док]
- Анонс 15.11.2011: первый мультимодальный TDD/FDD LTE-чип 3GPP R9 — https://www.mobileworldlive.com/huawei/huawei-claims-lte-chipset-first [док]
- Платформа V7R1: 2×ARMv7 без FPU + Cortex-M3 + BBE16 DSP; 128MB RAM (15MB free), 256MB NAND; штатный Linux 2.6.35.7 — https://github.com/Huawei-LTE-routers-mods/README/blob/master/balong_series.md [код]
- Наличие Cortex-M3 boot-ядра независимо подтверждается репо m3boot — https://github.com/hitechshell/balong-m3boot [код]
- HiSilicon лицензировала у ARM Cortex-A9 MPCore, Cortex-M3, Cortex-A7, Cortex-A15 и др. — https://en.wikipedia.org/wiki/HiSilicon [док]
- Тактовая частота CPU Hi6920: в открытых источниках НЕ найдена (проверены «Hi6920 Cortex-A9», «Hi6920 frequency», «Balong 710 1GHz», «Balong V7R1 600MHz», BogoMIPS-поиск, пресс-релизы, вики; 2026-10-19). [негатив]
- Косвенная зацепка по клокам (refclk UART 144МГц) есть в HiP01-dts, но связь HiP01↔Hi6920 не доказана. [гип]
- Тип DDR для V7R1 публично не найден — определять по регистрам контроллера локально. [негатив]

## 5. Прецеденты запуска Linux через USB-загрузчик Balong
- Полный публичный цикл (V7R11, E8372h): usbload --raminit --payload (0x57d00000) → fastboot → своё ядро boot.img; «Its WORK!» — https://github.com/hitechshell/balong-kernel + https://github.com/hitechshell/usbload-balong [код]
- Промежуточный прецедент: balong-usbdload → модифицированный usbloader (busybox + telnetd в /system/autorun.sh) → доступ к работающему Linux (E5885, V7R22; mtd0..27) — https://gist.github.com/ValdikSS/323bcdfceb2f09d9c6ef02db1bc573e2 [код]
- Восстановление «кирпича» через иглу + usbdload (E3372H; E5770: -p3, usbloader-*.bin) — https://decker.su/2016/03/balong-usb-downloader-huawei-recovery.html + https://4pda.to/forum/index.php?showtopic=818849&st=300 [блог+сниппет]
- Терминология ValdikSS для «кирпича»: «flash a firmware using USB crisis boot, load modified usbloader which enables telnet once, and then perform restore steps with telnet» — https://gist.github.com/ValdikSS/323bcdfceb2f09d9c6ef02db1bc573e2 [код]
- Методика для E3272s-153 (Мегафон М100-3 / Билайн E3272): AT^GODLOAD, «игольчатое» восстановление, «НЕ ПУТАЙТЕ E3272 и E3372» — https://xn--80aegp4abom.xn--p1ai/huawei-e3272-e3276-imei-ttl-igla [блог]
- Модифицированные прошивки V7R1 (E5372) с kernel-модулями собирались на 4pda (тема 618520, p=63653054, p=63851093) — https://4pda.to/forum/index.php?showtopic=618520 [сниппет]
- U-Boot-форк для BalongV7 заявлен как экспериментальный (WIP) — https://github.com/hitechshell/u-boot-balong [код]
- Итог: запуск СВОЕГО ядра через USB-загрузчик публично доказан для V7R11; для V7R1 публичного репорта не найдено — методику придётся переносить со своими raminit/payload/адресами. [негатив+гип]

## 6. Что из этого применимо к E3272s-153
- E3272s-153 = Мегафон М100-3 / Билайн E3272 (B1/B3/B7/B8/B20) — аппарат поколения V7R1=Hi6920, а не E3372 (V7R2/V7R11) — https://xn--80aegp4abom.xn--p1ai/huawei-e3272-e3276-imei-ttl-igla + https://github.com/Huawei-LTE-routers-mods/README/blob/master/balong_series.md [блог+код]
- Железо: 128MB RAM / 256MB NAND, 2×ARMv7 без FPU, штатный Linux 2.6.35.7 ⇒ своё ядро собирать для ARMv7 без FPU (softfp/soft) — balong_series.md. [код]
- dload-пакеты для V7R1 кодируются набором _R1 (Ptable_R1 0x100, Kernel_R1 0x105 и др.) — ptable.c balongflash. [код]
- Flash-ptable V7R1: маркеры pTableHead/pTableTail, имена 16 байт, запись 16+12 байт со смещением 12 — сплиттер ValdikSS; имена разделов снимать со своего дампа этим скриптом. [код]
- Прошивка: штатно через dload (AT^GODLOAD) + balongflash; аварийно через usbdload + usbloader — для V7R1 загрузчики существуют (E5372/E5776s/E392s/E3276/E5375 «и других»), под E3272 — искать/адаптировать (подмена pTableHead…pTableTail), стирание NAND отключать usblsafe-патчем — 4pda p=744265&st=240, p=553049&st=1640, gist ValdikSS. [сниппет+код]
- Шаблон запуска Linux — цепочка hitechshell: raminit + payload → fastboot → boot.img; НО конкретные адреса (payload 0x57d00000, base 0x54c08000, mem=0x3300000) взяты с V7R11 и для V7R1 НЕ переносимы без проверки. [код+гип]
- Mainline-каркаса для Hi6920 нет: либо вендорский Linux 2.6.35.7 из GPL-зеркала Huawei (ftp://serv.valdikss.org.ru/Downloads/Huawei_Open_Source/), либо свежее ядро с ручным bring-up (mach-hisi/HiP01 — формальный пример 2×A9) — Kconfig + HiP01-патч. [код+гип]
- Частота CPU и тип DDR: в вебе нет — определять локально по регистрам клок-контроллера/DDR. [негатив]
- Состав USBL-загрузчика (VxWorks 6.8) в веб-источниках не описан — опора только на собственный разбор. [негатив]

## 7. Пробелы, отрицательные результаты, проверенные запросы
- fetch_content на 4pda.to стабильно возвращает ошибку (invalid_response) — использованы только поисковые сниппеты; для проверки постов нужны зеркала/кэш. [инфра]
- Частота HI6920 не найдена: перебраны «Hi6920 Cortex-A9», «Hi6920 frequency», «Balong 710 1GHz», «Balong V7R1 600MHz», BogoMIPS-поиск, официальные страницы, вики. [негатив]
- Связь HiP01↔Hi6920: ни одного источника не найдено; в LKML есть только общий патч HiP01 (см. 2.5). [гип]
- Имена разделов флеша E3272 (mcore/lphy/usbl) публично не найдены — только локальный анализ пользователя. [негатив]
- u-boot-balong: README — стандартный апстримный; реальный статус — смотреть ветку huawei_modem и diff против u-boot/u-boot. [код]
- Аккаунт forstackoverflow1 не идентифицирован; задействованные репозитории принадлежат forth32, zer0325, hitechshell и Huawei-LTE-routers-mods. [негатив]
- Критерий остановки соблюдён: по частоте CPU и именам разделов две смены стратегии поиска не дали новых фактов — зафиксировано как «не найдено». [метод]
