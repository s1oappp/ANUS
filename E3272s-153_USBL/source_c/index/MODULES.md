# Модули реконструированного дерева

| Модуль | Описание | Функций | Файлы |
|---|---|---|---|
| boot | стартовая цепочка VxWorks (sysInit -> usrRoot), инициализация CPU/кэшей | 14 | 1 |
| bsp | BSP Huawei: GPIO, HKADC, PMU HI6451, WDT, LED, SPI/SSI, таймеры, питание | 508 | 4 |
| data | прочее: обработчики данных, product-таблицы, служебные функции | 2120 | 15 |
| dload | протоколы заливки: AT-команды загрузчика, DLOAD, TFUP, обновление | 75 | 1 |
| flash | флеш-подсистема: NAND-контроллер, ptable, YAFFS/YAFFS2, NV-память (NVM/nvim) | 555 | 4 |
| kernel | ядро VxWorks 6.8: задачи, семафоры, очереди, прерывания, память, планировщик | 1006 | 7 |
| lib | libc/математика/криптография/компрессия (AES, zlib-подобный QC_*) | 398 | 3 |
| shell | командный интерпретатор VxWorks shell (C-интерпретатор, таблицы команд) | 309 | 3 |
| usb | USB device-стек: jos/jslave, DWC dcd_syn_hs, CDC/ACM, uwd, порты | 186 | 2 |

## Межмодульные вызовы (топ)

| Из | В | Вызовов |
|---|---|---|
| data | kernel | 1262 |
| data | lib | 1120 |
| kernel | data | 617 |
| kernel | lib | 419 |
| usb | data | 404 |
| flash | lib | 287 |
| shell | data | 244 |
| shell | lib | 215 |
| bsp | lib | 211 |
| shell | kernel | 211 |
| bsp | data | 179 |
| bsp | kernel | 165 |
| dload | data | 151 |
| data | bsp | 116 |
| lib | data | 112 |
| data | usb | 104 |
| lib | kernel | 79 |
| dload | lib | 77 |
| flash | kernel | 74 |
| flash | data | 64 |
| data | shell | 44 |
| data | flash | 36 |
| usb | bsp | 35 |
| boot | kernel | 33 |
| dload | kernel | 33 |
| usb | kernel | 32 |
| kernel | shell | 29 |
| kernel | bsp | 22 |
| dload | bsp | 19 |
| bsp | usb | 18 |
| shell | bsp | 17 |
| boot | data | 15 |
| bsp | flash | 15 |
| bsp | shell | 11 |
| bsp | dload | 10 |
| data | dload | 9 |
| usb | lib | 7 |
| dload | flash | 7 |
| boot | lib | 4 |
| data | boot | 2 |
