/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : usb — USB device-стек: jos/jslave, DWC dcd_syn_hs, CDC/ACM, uwd, порты
 * Часть  : 1 (функций: 150, адреса 0x30004A18..0x3005F68C)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * USB_UnReset @ 0x30004A18  (примерный размер ~224 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskDelay
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0xFFFFEFFF, 0x30004A18, 0xF7FFFFFF, 0x08000000, 0xFFFFDFFF, 0xFFFFFFFD, 0xFFFFFFFC, 0xFDFFFFFF
 * Данные: DAT_300050d0, DAT_300050d4, DAT_300050d8, DAT_300050dc, DAT_300050e0
 * ---------------------------------------------------------------- */
void USB_UnReset(void)

{
  *DAT_300050d0 = *DAT_300050d0 & 0xf7ffffff | 0x8000000;
  *DAT_300050d0 = *DAT_300050d0 & 0xffffdfff | 0x2000;
  *DAT_300050d4 = *DAT_300050d4 & 0xffffefff;
  taskDelay(2);
  *DAT_300050d8 = *DAT_300050d8 & 0xfffffffd | 2;
  taskDelay(2);
  *DAT_300050dc = *DAT_300050dc & 0xfffffffc | 2;
  *DAT_300050e0 = *DAT_300050e0 & 0xfdffffff | 0x2000000;
  *DAT_300050e0 = *DAT_300050e0 & 0xe7ffffff | 0x18000000;
  *DAT_300050d4 = *DAT_300050d4 & 0xffffefff;
  return;
}

/* ----------------------------------------------------------------
 * jusb_debugSet @ 0x300420FC  (примерный размер ~32 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: valid_type
 * Константы: 0x300420FC
 * Данные: DAT_30042160
 * ---------------------------------------------------------------- */
void jusb_debugSet(int param_1,undefined4 param_2)

{
  valid_type(param_1);
  *(undefined4 *)(DAT_30042160 + param_1 * 4) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * jusb_debugGlobalSet @ 0x3004211C  (примерный размер ~44 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3004211C
 * Данные: DAT_30042160
 * ---------------------------------------------------------------- */
void jusb_debugGlobalSet(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0xf2; iVar1 = iVar1 + 1) {
    *(undefined4 *)(DAT_30042160 + iVar1 * 4) = param_2;
  }
  return;
}

/* ----------------------------------------------------------------
 * jusb_debugGet @ 0x30042148  (примерный размер ~28 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30042148
 * Данные: DAT_30042160
 * ---------------------------------------------------------------- */
undefined4 jusb_debugGet(int param_1)

{
  return *(undefined4 *)(DAT_30042160 + param_1 * 4);
}

/* ----------------------------------------------------------------
 * jos_uninit @ 0x30042284  (примерный размер ~132 байт)
 * Модуль: usb | Вызывают: 3 | Вызывает: 6
 * Вызывает: jdma_free_all, jos_mem_uninit, jos_safe_leave_d, jos_safe_uninit, jos_sync_uninit, os_port_uninit
 * Вызывают: jos_init, jstart_stack, jstop_stack
 * Константы: 0x30042284
 * Данные: DAT_300423d4, DAT_300423ec
 * ---------------------------------------------------------------- */
void jos_uninit(void)

{
  if ((*DAT_300423ec & 8) != 0) {
    jos_sync_uninit();
  }
  if ((*DAT_300423ec & 1) != 0) {
    jdma_free_all();
  }
  if ((*DAT_300423ec & 4) != 0) {
    os_port_uninit();
  }
  if ((*DAT_300423ec & 2) != 0) {
    jos_safe_leave_d(DAT_300423d4,99);
    jos_safe_uninit();
  }
  if ((*DAT_300423ec & 1) != 0) {
    jos_mem_uninit();
  }
  *DAT_300423ec = 0;
  return;
}

/* ----------------------------------------------------------------
 * jos_init @ 0x30042308  (примерный размер ~232 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 8
 * Вызывает: check_byte_order, check_types_length, jos_mem_init, jos_safe_enter_d, jos_safe_init, jos_sync_init, jos_uninit, os_port_init
 * Вызывают: jstart_stack
 * Константы: 0x30042308
 * Данные: DAT_300423d4, DAT_300423ec
 * ---------------------------------------------------------------- */
int jos_init(undefined4 param_1)

{
  int iVar1;
  
  check_byte_order();
  check_types_length();
  iVar1 = jos_mem_init(param_1);
  if (iVar1 == 0) {
    *DAT_300423ec = *DAT_300423ec | 1;
    iVar1 = jos_safe_init();
    if (iVar1 == 0) {
      jos_safe_enter_d(DAT_300423d4,0x42);
      *DAT_300423ec = *DAT_300423ec | 2;
      iVar1 = os_port_init();
      if (iVar1 == 0) {
        *DAT_300423ec = *DAT_300423ec | 4;
        iVar1 = jos_sync_init();
        if (iVar1 == 0) {
          *DAT_300423ec = *DAT_300423ec | 8;
          return 0;
        }
      }
    }
  }
  jos_uninit();
  return iVar1;
}

/* ----------------------------------------------------------------
 * jos_interrupt_teardown @ 0x30042468  (примерный размер ~176 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 7
 * Вызывает: BSP_FreeDbg, jtask_uninit, os_dprintf, os_interrupt_teardown, os_panic, os_printf, valid_type
 * Вызывают: FUN_30055bf0
 * Константы: 0x30042468
 * Данные: DAT_30042720, DAT_30042724, DAT_3004272c, DAT_30042730, DAT_30042734, DAT_30042738, DAT_3004273c
 * ---------------------------------------------------------------- */
void jos_interrupt_teardown(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    os_dprintf(DAT_30042720,DAT_30042724,0x32);
    os_dprintf(DAT_30042730);
    os_panic(DAT_3004272c,DAT_30042724,0x32);
  }
  iVar1 = os_interrupt_teardown(param_1);
  if (((iVar1 != 0) && (valid_type(0x22), 0 < *(int *)(DAT_30042734 + 0x78))) &&
     (0 < *(int *)(DAT_30042734 + 0x88))) {
    os_dprintf(DAT_30042738,DAT_30042724,0x36);
    os_printf(DAT_3004273c);
  }
  jtask_uninit(*(undefined4 *)(param_2 + 8));
  BSP_FreeDbg(param_2,DAT_30042724,0x3b);
  return;
}

/* ----------------------------------------------------------------
 * jos_interrupt_setup @ 0x30042518  (примерный размер ~436 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 8
 * Вызывает: BSP_FreeDbg, FUN_300426cc, jtask_init, jtask_uninit, os_dprintf, os_interrupt_setup, os_printf, valid_type
 * Вызывают: FUN_30055924
 * Константы: 0x30042518
 * Данные: DAT_30042724, DAT_30042734, DAT_30042738, DAT_30042740, DAT_30042744, DAT_30042748, DAT_3004274c
 * ---------------------------------------------------------------- */
int jos_interrupt_setup(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,int *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_300426cc(0xc,0,DAT_30042724,0x55);
  if (puVar1 == (undefined4 *)0x0) {
    valid_type(0x22);
    if ((0 < *(int *)(DAT_30042734 + 0x78)) && (0 < *(int *)(DAT_30042734 + 0x88))) {
      os_dprintf(DAT_30042738,DAT_30042724,0x59);
      os_printf(DAT_30042740);
    }
    iVar2 = 7;
  }
  else {
    iVar2 = jtask_init(puVar1 + 2,0);
    if (iVar2 == 0) {
      *puVar1 = param_4;
      puVar1[1] = param_5;
      iVar2 = os_interrupt_setup(param_1,param_2,param_3,DAT_30042748,puVar1);
      if (iVar2 == 0) {
        *param_6 = (int)puVar1;
        return 0;
      }
      valid_type(0x22);
      if ((0 < *(int *)(DAT_30042734 + 0x78)) && (0 < *(int *)(DAT_30042734 + 0x88))) {
        os_dprintf(DAT_30042738,DAT_30042724,0x72);
        os_printf(DAT_3004274c,iVar2);
      }
    }
    else {
      valid_type(0x22);
      if ((0 < *(int *)(DAT_30042734 + 0x78)) && (0 < *(int *)(DAT_30042734 + 0x88))) {
        os_dprintf(DAT_30042738,DAT_30042724,100);
        os_printf(DAT_30042744,iVar2);
      }
    }
  }
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[2] != 0)) {
    jtask_uninit(puVar1[2]);
  }
  if (puVar1 != (undefined4 *)0x0) {
    BSP_FreeDbg(puVar1,DAT_30042724,0x81);
  }
  *param_6 = 0;
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300426cc @ 0x300426CC  (примерный размер ~132 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_MallocDbg, memset
 * Вызывают: jos_interrupt_setup
 * Константы: 0x300426CC
 * ---------------------------------------------------------------- */
void * FUN_300426cc(size_t param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)BSP_MallocDbg(param_1,0,param_3,param_4);
  if ((param_2 == 1) && (__s != (void *)0x0)) {
    memset(__s,0,param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * j_device_set_core_ctx @ 0x30042750  (примерный размер ~140 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: core_register_dcd, core_unregister_dcd
 * Константы: 0x30042750
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_30043488, DAT_3004348c, DAT_30043490, DAT_30043494
 * ---------------------------------------------------------------- */
void j_device_set_core_ctx(int param_1,undefined4 param_2)

{
  valid_type(0x1f);
  if ((2 < *(int *)(DAT_3004347c + 0x78)) && (2 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0xe);
    os_printf(DAT_30043488,0,param_2);
  }
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x10);
    os_dprintf(DAT_30043490);
    os_panic(DAT_30043494,DAT_30043484,0x10);
  }
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * j_device_get_core_ctx @ 0x300427DC  (примерный размер ~168 байт)
 * Модуль: usb | Вызывают: 4 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: jslave_disable, jslave_enable, jslave_reconfig, jslave_wakeup_host
 * Константы: 0x300427DC
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_30043498, DAT_3004349c
 * ---------------------------------------------------------------- */
undefined4 j_device_get_core_ctx(int param_1)

{
  undefined4 uVar1;
  
  valid_type(0x1f);
  if ((2 < *(int *)(DAT_3004347c + 0x78)) && (2 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0x18);
    os_printf(DAT_30043498,0);
  }
  if (param_1 == 0) {
    valid_type(0x1f);
    if ((0 < *(int *)(DAT_3004347c + 0x78)) && (0 < *(int *)(DAT_3004347c + 0x7c))) {
      os_dprintf(DAT_30043480,DAT_30043484,0x1b);
      os_printf(DAT_3004349c,0);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x2c);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * j_device_get_ivars @ 0x30042884  (примерный размер ~132 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x30042884
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_300434a0, DAT_300434a4
 * ---------------------------------------------------------------- */
undefined4 j_device_get_ivars(int param_1)

{
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x25);
    os_dprintf(DAT_300434a0);
    os_panic(DAT_30043494,DAT_30043484,0x25);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0x27);
    os_printf(DAT_300434a4,param_1);
  }
  return *(undefined4 *)(param_1 + 0x14);
}

/* ----------------------------------------------------------------
 * j_device_set_ivars @ 0x30042908  (примерный размер ~140 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: add_generic_controller_ex
 * Константы: 0x30042908
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_300434a8, DAT_300434ac
 * ---------------------------------------------------------------- */
void j_device_set_ivars(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x2e);
    os_dprintf(DAT_300434a8);
    os_panic(DAT_30043494,DAT_30043484,0x2e);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0x30);
    os_printf(DAT_300434ac,param_1,param_2);
  }
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * j_device_set_params @ 0x30042994  (примерный размер ~140 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: add_generic_controller_ex
 * Константы: 0x30042994
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_300434b0, DAT_300434b4
 * ---------------------------------------------------------------- */
void j_device_set_params(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x37);
    os_dprintf(DAT_300434b0);
    os_panic(DAT_30043494,DAT_30043484,0x37);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0x39);
    os_printf(DAT_300434b4,param_1,param_2);
  }
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * j_device_get_params @ 0x30042A20  (примерный размер ~132 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: core_register_dcd
 * Константы: 0x30042A20
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_300434b8, DAT_300434bc
 * ---------------------------------------------------------------- */
undefined4 j_device_get_params(int param_1)

{
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x40);
    os_dprintf(DAT_300434b8);
    os_panic(DAT_30043494,DAT_30043484,0x40);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0x42);
    os_printf(DAT_300434bc,param_1);
  }
  return *(undefined4 *)(param_1 + 0x24);
}

/* ----------------------------------------------------------------
 * j_device_set_controller_id @ 0x30042AA4  (примерный размер ~140 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: add_generic_controller_ex
 * Константы: 0x30042AA4
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_300434c0, DAT_300434c4
 * ---------------------------------------------------------------- */
void j_device_set_controller_id(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x49);
    os_dprintf(DAT_300434c0);
    os_panic(DAT_30043494,DAT_30043484,0x49);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0x4c);
    os_printf(DAT_300434c4,param_1,param_2);
  }
  *(undefined4 *)(param_1 + 0x28) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * j_device_get_controller_id @ 0x30042B30  (примерный размер ~132 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: j_device_get_from_pending_controllers_list
 * Константы: 0x30042B30
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_300434c8, DAT_300434cc
 * ---------------------------------------------------------------- */
undefined4 j_device_get_controller_id(int param_1)

{
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x53);
    os_dprintf(DAT_300434c8);
    os_panic(DAT_30043494,DAT_30043484,0x53);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0x55);
    os_printf(DAT_300434cc,param_1);
  }
  return *(undefined4 *)(param_1 + 0x28);
}

/* ----------------------------------------------------------------
 * j_device_get_nameunit @ 0x30042BB4  (примерный размер ~184 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: FUN_30055e10, j_device_remove_from_pending_controllers_list
 * Константы: 0x30042BB4
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_300434d0, DAT_300434d4, DAT_300434d8
 * ---------------------------------------------------------------- */
undefined4 j_device_get_nameunit(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x5c);
    os_dprintf(DAT_300434d0);
    os_panic(DAT_30043494,DAT_30043484,0x5c);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0x5f);
    uVar1 = DAT_300434d4;
    if (*(int *)(param_1 + 0x1c) != 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x1c);
    }
    os_printf(DAT_300434d8,param_1,uVar1);
  }
  uVar1 = DAT_300434dc;
  if (*(int *)(param_1 + 0x1c) != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x1c);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * j_device_get_bus @ 0x30042C6C  (примерный размер ~164 байт)
 * Модуль: usb | Вызывают: 4 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: FUN_300537e8, FUN_30055d50, FUN_30055e10, core_resume
 * Константы: 0x30042C6C
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_300434d4, DAT_300434e0, DAT_300434e4
 * ---------------------------------------------------------------- */
undefined4 j_device_get_bus(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x66);
    os_dprintf(DAT_300434e0);
    os_panic(DAT_30043494,DAT_30043484,0x66);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0x69);
    uVar1 = DAT_300434d4;
    if (*(int *)(param_1 + 0x1c) != 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x1c);
    }
    os_printf(DAT_300434e4,param_1,uVar1,*(undefined4 *)(param_1 + 0x10));
  }
  return *(undefined4 *)(param_1 + 0x10);
}

/* ----------------------------------------------------------------
 * j_device_set_bus @ 0x30042D10  (примерный размер ~140 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: FUN_30043bd4, add_generic_controller_ex
 * Константы: 0x30042D10
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_300434e8, DAT_300434ec
 * ---------------------------------------------------------------- */
void j_device_set_bus(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x70);
    os_dprintf(DAT_300434e8);
    os_panic(DAT_30043494,DAT_30043484,0x70);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0x72);
    os_printf(DAT_300434ec,param_1,param_2);
  }
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * j_device_set_nameunit @ 0x30042D9C  (примерный размер ~304 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 8
 * Вызывает: BSP_FreeDbg, FUN_30043428, os_dprintf, os_panic, os_printf, os_snprintf, os_strlen, valid_type
 * Вызывают: FUN_30043bd4, FUN_30043e64
 * Константы: 0x30042D9C
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_300434d4, DAT_300434f0, DAT_300434f4
 * ---------------------------------------------------------------- */
void j_device_set_nameunit(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x7b);
    os_dprintf(DAT_300434f0);
    os_panic(DAT_30043494,DAT_30043484,0x7b);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0x7e);
    iVar1 = DAT_300434d4;
    if (param_2 != 0) {
      iVar1 = param_2;
    }
    os_printf(DAT_300434f4,param_1,iVar1,param_3);
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    BSP_FreeDbg(*(undefined4 *)(param_1 + 0x1c),DAT_30043484,0x81);
  }
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x18) = param_3;
  }
  else {
    iVar1 = os_strlen(param_2);
    uVar2 = FUN_30043428(iVar1 + 10,1,DAT_30043484,0x8b);
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
    if (*(int *)(param_1 + 0x1c) != 0) {
      *(undefined4 *)(param_1 + 0x18) = param_3;
      os_snprintf(*(undefined4 *)(param_1 + 0x1c),iVar1 + 10,DAT_300434f8,param_2,param_3);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * j_device_get_parent @ 0x30042ECC  (примерный размер ~132 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x30042ECC
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_300434fc, DAT_30043500
 * ---------------------------------------------------------------- */
undefined4 j_device_get_parent(int param_1)

{
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x95);
    os_dprintf(DAT_300434fc);
    os_panic(DAT_30043494,DAT_30043484,0x95);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0x97);
    os_printf(DAT_30043500,param_1);
  }
  return *(undefined4 *)(param_1 + 4);
}

/* ----------------------------------------------------------------
 * j_get_usbd_device @ 0x30042F50  (примерный размер ~132 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x30042F50
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_30043504, DAT_30043508
 * ---------------------------------------------------------------- */
undefined4 j_get_usbd_device(int param_1)

{
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0x9e);
    os_dprintf(DAT_30043504);
    os_panic(DAT_30043494,DAT_30043484,0x9e);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0xa0);
    os_printf(DAT_30043508,param_1);
  }
  return *(undefined4 *)(param_1 + 0x10);
}

/* ----------------------------------------------------------------
 * j_device_get_softc @ 0x30042FD4  (примерный размер ~132 байт)
 * Модуль: usb | Вызывают: 26 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: FUN_3004ffac, FUN_30051150, FUN_30053750, FUN_300537e8, FUN_30053910, FUN_300539a0, FUN_300545e8, FUN_3005486c, FUN_30054bd8, FUN_30054ca0
 *           ...
 * Константы: 0x30042FD4
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_3004350c, DAT_30043510
 * ---------------------------------------------------------------- */
undefined4 j_device_get_softc(int param_1)

{
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0xa7);
    os_dprintf(DAT_3004350c);
    os_panic(DAT_30043494,DAT_30043484,0xa7);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0xa9);
    os_printf(DAT_30043510,param_1);
  }
  return *(undefined4 *)(param_1 + 8);
}

/* ----------------------------------------------------------------
 * j_device_get_unit @ 0x30043058  (примерный размер ~132 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x30043058
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_30043514, DAT_30043518
 * ---------------------------------------------------------------- */
undefined4 j_device_get_unit(int param_1)

{
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0xb0);
    os_dprintf(DAT_30043514);
    os_panic(DAT_30043494,DAT_30043484,0xb0);
  }
  valid_type(0x1f);
  if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0xb2);
    os_printf(DAT_30043518,param_1);
  }
  return *(undefined4 *)(param_1 + 0x18);
}

/* ----------------------------------------------------------------
 * j_device_attached @ 0x300430DC  (примерный размер ~80 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 2
 * Вызывает: os_dprintf, os_panic
 * Вызывают: del_generic_controller_ex
 * Константы: 0x300430DC
 * Данные: DAT_30043484, DAT_3004348c, DAT_30043494, DAT_3004351c
 * ---------------------------------------------------------------- */
bool j_device_attached(int *param_1)

{
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0xb9);
    os_dprintf(DAT_3004351c);
    os_panic(DAT_30043494,DAT_30043484,0xb9);
  }
  return *param_1 != 0;
}

/* ----------------------------------------------------------------
 * j_device_probe_and_attach @ 0x3004312C  (примерный размер ~124 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 5
 * Вызывает: jdriver_attach, jos_safe_check, os_dprintf, os_printf, valid_type
 * Константы: 0x3004312C
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_30043520
 * ---------------------------------------------------------------- */
void j_device_probe_and_attach(int param_1,undefined4 param_2)

{
  jos_safe_check(DAT_30043484,199);
  valid_type(0x1f);
  if ((2 < *(int *)(DAT_3004347c + 0x78)) && (2 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0xc9);
    os_printf(DAT_30043520,param_1,param_2);
  }
  *(undefined4 *)(param_1 + 0x10) = param_2;
  jdriver_attach(2,param_1,0,0);
  return;
}

/* ----------------------------------------------------------------
 * j_device_set_desc @ 0x300431A8  (примерный размер ~184 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 6
 * Вызывает: BSP_FreeDbg, j_strdup, os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x300431A8
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004348c, DAT_30043494, DAT_30043524, DAT_30043528
 * ---------------------------------------------------------------- */
void j_device_set_desc(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    os_dprintf(DAT_3004348c,DAT_30043484,0xd2);
    os_dprintf(DAT_30043524);
    os_panic(DAT_30043494,DAT_30043484,0xd2);
  }
  if (param_2 != 0) {
    valid_type(0x1f);
    if ((3 < *(int *)(DAT_3004347c + 0x78)) && (3 < *(int *)(DAT_3004347c + 0x7c))) {
      os_dprintf(DAT_30043480,DAT_30043484,0xd8);
      os_printf(DAT_30043528,param_1,param_2);
    }
    if (*(int *)(param_1 + 0x20) != 0) {
      BSP_FreeDbg(*(undefined4 *)(param_1 + 0x20),DAT_30043484,0xdb);
    }
    uVar1 = j_strdup(param_2);
    *(undefined4 *)(param_1 + 0x20) = uVar1;
  }
  return;
}

/* ----------------------------------------------------------------
 * j_device_get_desc @ 0x30043260  (примерный размер ~40 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30043260
 * ---------------------------------------------------------------- */
undefined4 j_device_get_desc(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x20);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * j_device_detach @ 0x30043288  (примерный размер ~104 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: jdriver_detach, os_dprintf, os_printf, valid_type
 * Константы: 0x30043288
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_3004352c
 * ---------------------------------------------------------------- */
undefined4 j_device_detach(int *param_1)

{
  valid_type(0x1f);
  if ((2 < *(int *)(DAT_3004347c + 0x78)) && (2 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0xe6);
    os_printf(DAT_3004352c,param_1);
  }
  if (*param_1 != 0) {
    jdriver_detach(param_1);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * j_device_ioctl @ 0x300443AC  (примерный размер ~100 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300443AC
 * ---------------------------------------------------------------- */
undefined4 j_device_ioctl(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((*param_1 == 0) || (*(int *)(*(int *)*param_1 + 0x14) == 0)) {
    uVar1 = 10;
  }
  else {
    uVar1 = (**(code **)(*(int *)*param_1 + 0x14))(param_1,param_2,param_3);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * j_device_suspend @ 0x30044410  (примерный размер ~88 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: generic_controller_suspend
 * Константы: 0x30044410
 * ---------------------------------------------------------------- */
undefined4 j_device_suspend(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*param_1 != 0) && (*(int *)(*(int *)*param_1 + 0xc) != 0)) {
    uVar1 = (**(code **)(*(int *)*param_1 + 0xc))(param_1);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * j_device_resume @ 0x30044468  (примерный размер ~88 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: generic_controller_resume
 * Константы: 0x30044468
 * ---------------------------------------------------------------- */
undefined4 j_device_resume(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*param_1 != 0) && (*(int *)(*(int *)*param_1 + 0x10) != 0)) {
    uVar1 = (**(code **)(*(int *)*param_1 + 0x10))(param_1);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * j_device_get_from_pending_controllers_list @ 0x300444C0  (примерный размер ~104 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: j_device_get_controller_id
 * Константы: 0x300444C0
 * Данные: DAT_300445b8
 * ---------------------------------------------------------------- */
int j_device_get_from_pending_controllers_list(int param_1)

{
  int iVar1;
  int iVar2;
  
  for (iVar2 = *DAT_300445b8;
      (iVar2 != 0 &&
      ((iVar1 = j_device_get_controller_id(iVar2), iVar1 != param_1 || (*(int *)(iVar2 + 0x24) != 0)
       ))); iVar2 = *(int *)(iVar2 + 0x30)) {
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * j_device_add_to_pending_controllers_list @ 0x30044528  (примерный размер ~64 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: add_generic_controller_ex
 * Константы: 0x30044528
 * Данные: DAT_300445b8
 * ---------------------------------------------------------------- */
void j_device_add_to_pending_controllers_list(int param_1)

{
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(DAT_300445b8 + 4);
  **(int **)(DAT_300445b8 + 4) = param_1;
  *(int *)(DAT_300445b8 + 4) = param_1 + 0x30;
  return;
}

/* ----------------------------------------------------------------
 * j_device_remove_from_pending_controllers_list @ 0x30044568  (примерный размер ~236 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: j_device_get_nameunit, os_dprintf, os_printf, valid_type
 * Константы: 0x30044568
 * Данные: DAT_300445b8, DAT_30044728, DAT_3004472c, DAT_30044730, DAT_30044734, DAT_30044738, DAT_3004473c
 * ---------------------------------------------------------------- */
undefined4 j_device_remove_from_pending_controllers_list(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = false;
  iVar3 = *DAT_300445b8;
  while (iVar4 = iVar3, iVar4 != 0) {
    iVar3 = *(int *)(iVar4 + 0x30);
    if (iVar4 == param_1) {
      if (*(int *)(iVar4 + 0x30) == 0) {
        *(undefined4 *)(DAT_30044728 + 4) = *(undefined4 *)(iVar4 + 0x34);
      }
      else {
        *(undefined4 *)(*(int *)(iVar4 + 0x30) + 0x34) = *(undefined4 *)(iVar4 + 0x34);
      }
      **(undefined4 **)(iVar4 + 0x34) = *(undefined4 *)(iVar4 + 0x30);
      bVar1 = true;
    }
  }
  if (bVar1) {
    uVar2 = 0;
  }
  else {
    valid_type(0x22);
    if ((0 < *(int *)(DAT_3004472c + 0x78)) && (0 < *(int *)(DAT_3004472c + 0x88))) {
      os_dprintf(DAT_30044730,DAT_30044734,DAT_30044738);
      uVar2 = j_device_get_nameunit(param_1);
      os_printf(DAT_3004473c,param_1,uVar2);
    }
    uVar2 = 10;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30044654 @ 0x30044654  (примерный размер ~236 байт)
 * Модуль: usb | Вызывают: 3 | Вызывает: 2
 * Вызывает: BSP_MallocDbg, memset
 * Вызывают: FUN_30043bd4, FUN_30043e64, jdriver_register
 * Константы: 0x30044654
 * ---------------------------------------------------------------- */
void * FUN_30044654(size_t param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)BSP_MallocDbg(param_1,0,param_3,param_4);
  if ((param_2 == 1) && (__s != (void *)0x0)) {
    memset(__s,0,param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * j_arc4random @ 0x30045784  (примерный размер ~36 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: os_get_time
 * Константы: 0x30045784
 * ---------------------------------------------------------------- */
uint j_arc4random(void)

{
  uint local_c;
  uint local_8;
  
  os_get_time(&local_c);
  return local_c ^ local_8;
}

/* ----------------------------------------------------------------
 * j_strdup @ 0x300457F0  (примерный размер ~88 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_30046974, os_memcpy, os_strlen
 * Вызывают: j_device_set_desc
 * Константы: 0x300457F0
 * Данные: DAT_30045c98
 * ---------------------------------------------------------------- */
int j_strdup(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = os_strlen(param_1);
  iVar2 = FUN_30046974(iVar1 + 1,0,DAT_30045c98,0xab);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    os_memcpy(iVar2,param_1,iVar1 + 1);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * j_strstr @ 0x30045848  (примерный размер ~168 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30045848
 * ---------------------------------------------------------------- */
char * j_strstr(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  do {
    if (*param_1 == '\0') {
      return (char *)0x0;
    }
    if (*param_1 == *param_2) {
      pcVar2 = param_1;
      for (pcVar1 = param_2 + 1;
          ((pcVar2 = pcVar2 + 1, *pcVar2 != '\0' && (*pcVar1 != '\0')) && (*pcVar2 == *pcVar1));
          pcVar1 = pcVar1 + 1) {
      }
      if (*pcVar1 == '\0') {
        return param_1;
      }
      if (*pcVar2 == '\0') {
        return (char *)0x0;
      }
    }
    param_1 = param_1 + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * j_numtostr @ 0x300458F0  (примерный размер ~392 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 6
 * Вызывает: __udiv32, __urem32, os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x300458F0
 * Данные: DAT_30045c94, DAT_30045c98, DAT_30045ca0, DAT_30045cc4, DAT_30045cc8, DAT_30045ccc, DAT_30045cd0, DAT_30045cd4
 * ---------------------------------------------------------------- */
int j_numtostr(int param_1,byte param_2,uint param_3,int param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char acStack_45 [33];
  
  iVar3 = 0;
  uVar2 = 0;
  if (param_1 == 0) {
    os_dprintf(DAT_30045c94,DAT_30045c98,0xfc);
    os_dprintf(DAT_30045cc4);
    os_panic(DAT_30045ca0,DAT_30045c98,0xfc);
  }
  if (param_2 < 2) {
    valid_type(0x24);
    if ((0 < *(int *)(DAT_30045cc8 + 0x78)) && (0 < *(int *)(DAT_30045cc8 + 0x90))) {
      os_dprintf(DAT_30045ccc,DAT_30045c98,DAT_30045cd0);
      os_printf(DAT_30045cd4,param_2);
    }
    param_1 = 0;
  }
  else {
    while (param_5 != 0) {
      bVar1 = __urem32(param_5,param_2);
      param_5 = __udiv32(param_5,param_2);
      if (bVar1 < 10) {
        acStack_45[uVar2 + 1] = bVar1 + 0x30;
      }
      else {
        acStack_45[uVar2 + 1] = bVar1 + 0x37;
      }
      uVar2 = uVar2 + 1;
    }
    for (; uVar2 < param_3; param_3 = param_3 - 1) {
      *(undefined1 *)(param_1 + iVar3) = 0x30;
      iVar3 = iVar3 + 1;
    }
    while ((uVar2 != 0 && (param_4 != 0))) {
      *(char *)(param_1 + iVar3) = acStack_45[uVar2];
      iVar3 = iVar3 + 1;
      uVar2 = uVar2 - 1;
      param_4 = param_4 + -1;
    }
    *(undefined1 *)(param_1 + iVar3) = 0;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * j_strlcpy @ 0x30045A78  (примерный размер ~116 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: os_strlen
 * Константы: 0x30045A78
 * ---------------------------------------------------------------- */
uint j_strlcpy(char *param_1,char *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    if (param_3 <= uVar3) {
      if (param_3 != 0) {
        param_1[-1] = '\0';
      }
      iVar2 = os_strlen(param_2);
      return iVar2 + param_3;
    }
    cVar1 = *param_2;
    *param_1 = cVar1;
    if (cVar1 == '\0') break;
    uVar3 = uVar3 + 1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_30045aec @ 0x30045AEC  (примерный размер ~132 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: j_strtonum
 * Константы: 0xFFFFFFFF, 0x30045AEC
 * ---------------------------------------------------------------- */
uint FUN_30045aec(char param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0xffffffff;
  if ((int)param_1 - 0x30U < 10) {
    uVar1 = (int)param_1 - 0x30;
  }
  else if ((int)param_1 - 0x41U < 6) {
    uVar1 = (int)param_1 - 0x37;
  }
  else if ((int)param_1 - 0x61U < 6) {
    uVar1 = (int)param_1 - 0x57;
  }
  if (param_2 <= uVar1) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * j_strtonum @ 0x30045B70  (примерный размер ~144 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_30045aec
 * Константы: 0x30045B70
 * ---------------------------------------------------------------- */
int j_strtonum(char *param_1,byte param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = 0;
  iVar1 = FUN_30045aec((int)*param_1,param_2);
  pcVar3 = param_1;
  while ((*pcVar3 != '\0' && (iVar1 != -1))) {
    iVar2 = iVar2 * (uint)param_2 + iVar1;
    pcVar3 = pcVar3 + 1;
    iVar1 = FUN_30045aec((int)*pcVar3,param_2);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = pcVar3;
  }
  if (pcVar3 == param_1) {
    iVar2 = -1;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * j_is_space @ 0x30045C00  (примерный размер ~76 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30045C00
 * ---------------------------------------------------------------- */
undefined4 j_is_space(char param_1)

{
  undefined4 uVar1;
  
  if ((((param_1 == ' ') || (param_1 == '\t')) || (param_1 == '\r')) || (param_1 == '\n')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * jos_mem_init @ 0x30047F80  (примерный размер ~80 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: jos_init
 * Константы: 0x30047F80, 0x30047F98
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x30047f98) */

undefined4 jos_mem_init(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * jos_mem_uninit @ 0x30047FD0  (примерный размер ~4 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: jos_uninit
 * Константы: 0x30047FD0
 * ---------------------------------------------------------------- */
void jos_mem_uninit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * FUN_30047fd4 @ 0x30047FD4  (примерный размер ~296 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 2
 * Вызывает: BSP_MallocDbg, memset
 * Вызывают: FUN_30047018, jdma_alloc
 * Константы: 0x30047FD4
 * ---------------------------------------------------------------- */
void * FUN_30047fd4(size_t param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)BSP_MallocDbg(param_1,0,param_3,param_4);
  if ((param_2 == 1) && (__s != (void *)0x0)) {
    memset(__s,0,param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * jos_safe_check @ 0x300480FC  (примерный размер ~312 байт)
 * Модуль: usb | Вызывают: 15 | Вызывает: 5
 * Вызывает: os_dprintf, os_get_context, os_panic, os_printf, valid_type
 * Вызывают: FUN_30048f78, j_device_probe_and_attach, jdevice_add, jdevice_delete, jdma_alloc, jdma_free, jdriver_attach, jdriver_detach, jmalloc_d, jos_mutex_lock
 *           ...
 * Константы: 0x300480FC
 * Данные: DAT_30049074, DAT_30049078, DAT_3004907c, DAT_30049080, DAT_30049084, DAT_30049088, DAT_3004908c, DAT_30049090
 * ---------------------------------------------------------------- */
undefined4 jos_safe_check(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*DAT_30049074;
  if (piVar3 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    if (piVar3[3] == 0) {
      os_dprintf(DAT_30049078,DAT_3004907c,0x420);
      os_dprintf(DAT_30049080,param_1,param_2);
      os_panic(DAT_30049084,DAT_3004907c,0x420);
    }
    iVar2 = os_get_context();
    if (*piVar3 != iVar2) {
      os_dprintf(DAT_30049078,DAT_3004907c,DAT_30049088);
      os_dprintf(DAT_3004908c,param_1,param_2,iVar2,piVar3[1],piVar3[2],*piVar3);
      os_panic(DAT_30049084,DAT_3004907c,DAT_30049088);
    }
    valid_type(0x23);
    if ((4 < *(int *)(DAT_30049090 + 0x78)) && (4 < *(int *)(DAT_30049090 + 0x8c))) {
      os_dprintf(DAT_30049094,DAT_3004907c,DAT_30049190);
      os_printf(DAT_30049194,param_1,param_2,iVar2,piVar3[1],piVar3[2],*piVar3);
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * jos_critical_enter @ 0x3004852C  (примерный размер ~48 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 1
 * Вызывает: os_critical_enter
 * Вызывают: jos_critical_enter_d
 * Константы: 0x3004852C
 * Данные: DAT_300493e0
 * ---------------------------------------------------------------- */
void jos_critical_enter(void)

{
  if (*(int *)(DAT_300493e0 + 0xc) == 0) {
    os_critical_enter();
  }
  *(int *)(DAT_300493e0 + 0xc) = *(int *)(DAT_300493e0 + 0xc) + 1;
  return;
}

/* ----------------------------------------------------------------
 * jos_critical_enter_d @ 0x3004855C  (примерный размер ~240 байт)
 * Модуль: usb | Вызывают: 10 | Вызывает: 4
 * Вызывает: jos_critical_enter, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30048f78, FUN_30053248, FUN_300545e8, FUN_3005486c, jos_mutex_lock_checked, jtask_schedule_d, jtask_stop, os_interrupt_setup, os_interrupt_teardown, usb_enum_notify_usr
 * Константы: 0x3004855C
 * Данные: DAT_3004907c, DAT_30049090, DAT_30049094, DAT_300493e0, DAT_30049518, DAT_3004951c, DAT_30049520
 * ---------------------------------------------------------------- */
void jos_critical_enter_d(int param_1,int param_2)

{
  int iVar1;
  
  if (DAT_300493e0[2] == 0) {
    DAT_300493e0[3] = 0;
    DAT_300493e0[2] = 1;
    *DAT_300493e0 = 0;
    DAT_300493e0[1] = 0;
  }
  valid_type(0x23);
  if ((3 < *(int *)(DAT_30049090 + 0x78)) && (3 < *(int *)(DAT_30049090 + 0x8c))) {
    os_dprintf(DAT_30049094,DAT_3004907c,DAT_30049518);
    iVar1 = DAT_3004951c;
    if (*DAT_300493e0 != 0) {
      iVar1 = *DAT_300493e0;
    }
    os_printf(DAT_30049520,0,DAT_300493e0[3],param_1,param_2,iVar1,DAT_300493e0[1]);
  }
  jos_critical_enter();
  *DAT_300493e0 = param_1;
  DAT_300493e0[1] = param_2;
  return;
}

/* ----------------------------------------------------------------
 * jos_critical_leave @ 0x3004864C  (примерный размер ~48 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 1
 * Вызывает: os_critical_leave
 * Вызывают: jos_critical_leave_d
 * Константы: 0x3004864C
 * Данные: DAT_300493e0
 * ---------------------------------------------------------------- */
void jos_critical_leave(void)

{
  *(int *)(DAT_300493e0 + 0xc) = *(int *)(DAT_300493e0 + 0xc) + -1;
  if (*(int *)(DAT_300493e0 + 0xc) == 0) {
    os_critical_leave();
  }
  return;
}

/* ----------------------------------------------------------------
 * jos_critical_leave_d @ 0x3004867C  (примерный размер ~268 байт)
 * Модуль: usb | Вызывают: 10 | Вызывает: 4
 * Вызывает: jos_critical_leave, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30048f78, FUN_30053248, FUN_300545e8, FUN_3005486c, jos_mutex_lock_checked, jtask_schedule_d, jtask_stop, os_interrupt_setup, os_interrupt_teardown, usb_enum_notify_usr
 * Константы: 0x3004867C
 * Данные: DAT_3004907c, DAT_30049090, DAT_30049094, DAT_300493e0, DAT_30049524, DAT_30049528, DAT_30049630, DAT_30049634
 * ---------------------------------------------------------------- */
void jos_critical_leave_d(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_300493e0[1];
  uVar1 = *DAT_300493e0;
  if (((DAT_300493e0[2] == 0) && (valid_type(0x23), 1 < *(int *)(DAT_30049090 + 0x78))) &&
     (1 < *(int *)(DAT_30049090 + 0x8c))) {
    os_dprintf(DAT_30049094,DAT_3004907c,DAT_30049524);
    os_printf(DAT_30049528,0,param_1,param_2);
  }
  if (DAT_300493e0[3] == 1) {
    DAT_300493e0[1] = 0;
    *DAT_300493e0 = 0;
  }
  jos_critical_leave();
  valid_type(0x23);
  if ((3 < *(int *)(DAT_30049090 + 0x78)) && (3 < *(int *)(DAT_30049090 + 0x8c))) {
    os_dprintf(DAT_30049094,DAT_3004907c,DAT_30049630);
    os_printf(DAT_30049634,0,DAT_300493e0[3],param_1,param_2,uVar1,uVar2);
  }
  return;
}

/* ----------------------------------------------------------------
 * jos_thread_create @ 0x3004989C  (примерный размер ~72 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 2
 * Вызывает: jos_safe_check, os_thread_create
 * Вызывают: FUN_300498e4
 * Константы: 0x3004989C
 * Данные: DAT_30049ef8, DAT_3004a408
 * ---------------------------------------------------------------- */
void jos_thread_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5)

{
  jos_safe_check(DAT_30049ef8,DAT_3004a408);
  os_thread_create(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300498e4 @ 0x300498E4  (примерный размер ~272 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_300496a0, jos_thread_create, os_dprintf, os_memset, os_msleep_init, os_panic
 * Вызывают: task_threads_init
 * Константы: 0x300498E4
 * Данные: DAT_30049b98, DAT_30049ef8, DAT_3004a0ac, DAT_3004a0b8, DAT_3004a40c, DAT_3004a410, DAT_3004a414
 * ---------------------------------------------------------------- */
int FUN_300498e4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_30049b98 + param_1 * 0x50;
  if (iVar2 == 0) {
    os_dprintf(DAT_3004a0ac,DAT_30049ef8,0x268);
    os_dprintf(DAT_3004a40c,param_1);
    os_panic(DAT_3004a0b8,DAT_30049ef8,0x268);
  }
  os_memset(iVar2,0,0x50);
  iVar1 = os_msleep_init(iVar2);
  if (iVar1 == 0) {
    *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) | 1;
    *(undefined1 *)(iVar2 + 0x39) = 1;
    *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) | 4;
    iVar1 = jos_thread_create(DAT_3004a414,param_1,param_1,
                              *(undefined4 *)(DAT_3004a410 + param_1 * 4),iVar2 + 0x34);
    if (iVar1 == 0) {
      *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) | 2;
      return 0;
    }
  }
  FUN_300496a0(param_1);
  return iVar1;
}

/* ----------------------------------------------------------------
 * jos_mutex_lock_checked @ 0x30049A80  (примерный размер ~272 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 6
 * Вызывает: jos_critical_enter_d, jos_critical_leave_d, os_dprintf, os_get_context, os_mutex_lock, os_panic
 * Вызывают: jmutex_lock_d, jos_safe_enter_d
 * Константы: 0x30049A80
 * Данные: DAT_30049ef8, DAT_3004a0ac, DAT_3004a0b8, DAT_3004a418, DAT_3004a41c, DAT_3004a420, DAT_3004a424, DAT_3004a428
 * ---------------------------------------------------------------- */
void jos_mutex_lock_checked(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_3004a0ac,DAT_30049ef8,DAT_3004a418);
    os_dprintf(DAT_3004a41c,param_2,param_3);
    os_panic(DAT_3004a0b8,DAT_30049ef8,DAT_3004a418);
  }
  jos_critical_enter_d(DAT_30049ef8,DAT_3004a420);
  if ((param_1[3] != 0) && (iVar1 = os_get_context(), iVar1 == *param_1)) {
    os_dprintf(DAT_3004a0ac,DAT_30049ef8,DAT_3004a424);
    uVar2 = DAT_3004a430;
    if ((int *)*DAT_3004a428 != param_1) {
      uVar2 = DAT_3004a42c;
    }
    os_dprintf(DAT_3004a434,uVar2,param_2,param_3,param_1[1],param_1[2]);
    os_panic(DAT_3004a0b8,DAT_30049ef8,DAT_3004a424);
  }
  jos_critical_leave_d(DAT_30049ef8,1000);
  os_mutex_lock(param_1[4]);
  param_1[3] = 1;
  param_1[1] = param_2;
  param_1[2] = param_3;
  iVar1 = os_get_context();
  *param_1 = iVar1;
  return;
}

/* ----------------------------------------------------------------
 * jos_safe_enter_d @ 0x30049B90  (примерный размер ~56 байт)
 * Модуль: usb | Вызывают: 17 | Вызывает: 1
 * Вызывает: jos_mutex_lock_checked
 * Вызывают: FUN_3005c700, FUN_3005fcf8, FUN_3005ff20, FUN_30060b5c, FUN_30060dd0, FUN_3006106c, FUN_300612f4, FUN_300613c4, FUN_300615fc, FUN_30061708
 *           ...
 * Константы: 0x30049B90
 * Данные: DAT_3004a428
 * ---------------------------------------------------------------- */
void jos_safe_enter_d(undefined4 param_1,undefined4 param_2)

{
  jos_mutex_lock_checked(*DAT_3004a428,param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * jos_safe_leave_d @ 0x30049D30  (примерный размер ~36 байт)
 * Модуль: usb | Вызывают: 17 | Вызывает: 1
 * Вызывает: jmutex_unlock_d
 * Вызывают: FUN_3005c700, FUN_3005fcf8, FUN_3005ff20, FUN_30060b5c, FUN_30060dd0, FUN_3006106c, FUN_300612f4, FUN_300613c4, FUN_300615fc, FUN_30061708
 *           ...
 * Константы: 0x30049D30
 * Данные: DAT_3004a428
 * ---------------------------------------------------------------- */
void jos_safe_leave_d(undefined4 param_1,undefined4 param_2)

{
  jmutex_unlock_d(*DAT_3004a428,param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * jos_safe_init @ 0x30049E30  (примерный размер ~16 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 1
 * Вызывает: jmutex_init_d
 * Вызывают: jos_init
 * Константы: 0x30049E30
 * Данные: DAT_30049ef8, DAT_3004a428, DAT_3004a464
 * ---------------------------------------------------------------- */
void jos_safe_init(void)

{
  jmutex_init_d(DAT_3004a428,DAT_30049ef8,DAT_3004a464);
  return;
}

/* ----------------------------------------------------------------
 * jos_safe_uninit @ 0x30049F0C  (примерный размер ~40 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 1
 * Вызывает: jmutex_uninit_d
 * Вызывают: jos_uninit
 * Константы: 0x30049F0C
 * Данные: DAT_3004a428, DAT_3004a47c, DAT_3004a480
 * ---------------------------------------------------------------- */
void jos_safe_uninit(void)

{
  jmutex_uninit_d(*DAT_3004a428,DAT_3004a47c,DAT_3004a480);
  *DAT_3004a428 = 0;
  return;
}

/* ----------------------------------------------------------------
 * jos_safe_enter @ 0x30049F34  (примерный размер ~12 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: os_mutex_lock
 * Константы: 0x30049F34
 * Данные: DAT_3004a428
 * ---------------------------------------------------------------- */
void jos_safe_enter(void)

{
  os_mutex_lock(*DAT_3004a428);
  return;
}

/* ----------------------------------------------------------------
 * jos_safe_leave @ 0x30049F40  (примерный размер ~12 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: os_mutex_unlock
 * Константы: 0x30049F40
 * Данные: DAT_3004a428
 * ---------------------------------------------------------------- */
void jos_safe_leave(void)

{
  os_mutex_unlock(*DAT_3004a428);
  return;
}

/* ----------------------------------------------------------------
 * jos_mutex_lock @ 0x30049F4C  (примерный размер ~72 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 5
 * Вызывает: jdbg_check_context, jos_safe_check, jos_safe_enter_d, jos_safe_leave_d, os_mutex_lock
 * Константы: 0x30049F4C
 * Данные: DAT_3004a47c, DAT_3004a484, DAT_3004a488
 * ---------------------------------------------------------------- */
void jos_mutex_lock(undefined4 param_1)

{
  jos_safe_check(DAT_3004a47c,DAT_3004a484);
  jdbg_check_context(0x38,DAT_3004a47c,0x39c);
  jos_safe_leave_d(DAT_3004a47c,DAT_3004a488);
  os_mutex_lock(param_1);
  jos_safe_enter_d(DAT_3004a47c,0x3a0);
  return;
}

/* ----------------------------------------------------------------
 * jos_mutex_unlock @ 0x30049F94  (примерный размер ~44 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: os_mutex_unlock
 * Константы: 0x30049F94
 * ---------------------------------------------------------------- */
void jos_mutex_unlock(undefined4 param_1)

{
  os_mutex_unlock(param_1);
  return;
}

/* ----------------------------------------------------------------
 * jos_core_lock_check @ 0x3004A008  (примерный размер ~204 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 3
 * Вызывает: os_dprintf, os_get_context, os_panic
 * Вызывают: jdriver_attach, jdriver_detach
 * Константы: 0x3004A008
 * Данные: DAT_3004a0ac, DAT_3004a0b8, DAT_3004a454, DAT_3004a47c, DAT_3004a48c, DAT_3004a490, DAT_3004a494, DAT_3004a498
 * ---------------------------------------------------------------- */
void jos_core_lock_check(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*DAT_3004a454;
  if (piVar2[3] == 0) {
    os_dprintf(DAT_3004a0ac,DAT_3004a47c,DAT_3004a48c);
    os_dprintf(DAT_3004a490,param_1,param_2);
    os_panic(DAT_3004a0b8,DAT_3004a47c,DAT_3004a48c);
  }
  iVar1 = os_get_context();
  if (iVar1 != *piVar2) {
    os_dprintf(DAT_3004a0ac,DAT_3004a47c,DAT_3004a494);
    os_dprintf(DAT_3004a498,param_1,param_2,piVar2[1],piVar2[2]);
    os_panic(DAT_3004a0b8,DAT_3004a47c,DAT_3004a494);
  }
  return;
}

/* ----------------------------------------------------------------
 * jos_sync_init @ 0x3004A0D4  (примерный размер ~212 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 7
 * Вызывает: jmutex_init_d, os_dprintf, os_memset, os_printf, task_threads_init, task_threads_uninit, valid_type
 * Вызывают: jos_init
 * Константы: 0x3004A0D4
 * Данные: DAT_3004a454, DAT_3004a47c, DAT_3004a49c, DAT_3004a4a0, DAT_3004a4a4, DAT_3004a4a8, DAT_3004a4ac, DAT_3004a4b0
 * ---------------------------------------------------------------- */
int jos_sync_init(void)

{
  int iVar1;
  
  valid_type(0x23);
  if ((2 < *(int *)(DAT_3004a49c + 0x78)) && (2 < *(int *)(DAT_3004a49c + 0x8c))) {
    os_dprintf(DAT_3004a4a0,DAT_3004a47c,DAT_3004a4a4);
    os_printf(DAT_3004a4a8);
  }
  os_memset(DAT_3004a4ac,0,0x10);
  iVar1 = task_threads_init();
  if ((iVar1 == 0) && (iVar1 = jmutex_init_d(DAT_3004a454,DAT_3004a47c,DAT_3004a4b0), iVar1 != 0)) {
    task_threads_uninit();
  }
  valid_type(0x23);
  if ((2 < *(int *)(DAT_3004a49c + 0x78)) && (2 < *(int *)(DAT_3004a49c + 0x8c))) {
    os_dprintf(DAT_3004a4a0,DAT_3004a47c,DAT_3004a4b4);
    os_printf(DAT_3004a4b8,iVar1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * jos_sync_uninit @ 0x3004A1A8  (примерный размер ~296 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 6
 * Вызывает: jmutex_uninit_d, os_dprintf, os_panic, os_printf, task_threads_uninit, valid_type
 * Вызывают: jos_uninit
 * Константы: 0x3004A1A8
 * Данные: DAT_3004a454, DAT_3004a47c, DAT_3004a49c, DAT_3004a4a0, DAT_3004a4ac, DAT_3004a4bc, DAT_3004a4c0, DAT_3004a4c4
 * ---------------------------------------------------------------- */
void jos_sync_uninit(void)

{
  valid_type(0x23);
  if ((2 < *(int *)(DAT_3004a49c + 0x78)) && (2 < *(int *)(DAT_3004a49c + 0x8c))) {
    os_dprintf(DAT_3004a4a0,DAT_3004a47c,DAT_3004a4bc);
    os_printf(DAT_3004a4c0);
  }
  task_threads_uninit();
  jmutex_uninit_d(*DAT_3004a454,DAT_3004a47c,DAT_3004a4c4);
  *DAT_3004a454 = 0;
  if (DAT_3004a4ac[3] != 0) {
    os_dprintf(DAT_3004a4c8,DAT_3004a47c,DAT_3004a4cc);
    os_dprintf(DAT_3004a4d0);
    os_panic(DAT_3004a4d4,DAT_3004a47c,DAT_3004a4cc);
  }
  DAT_3004a4ac[3] = 0;
  DAT_3004a4ac[2] = 0;
  *DAT_3004a4ac = 0;
  DAT_3004a4ac[1] = 0;
  valid_type(0x23);
  if ((2 < *(int *)(DAT_3004a49c + 0x78)) && (2 < *(int *)(DAT_3004a49c + 0x8c))) {
    os_dprintf(DAT_3004a4a0,DAT_3004a47c,DAT_3004a4d8);
    os_printf(DAT_3004a4dc);
  }
  return;
}

/* ----------------------------------------------------------------
 * jos_critical_check @ 0x3004A2D0  (примерный размер ~12 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: jos_critical_check_d
 * Константы: 0x3004A2D0
 * Данные: DAT_3004a4ac
 * ---------------------------------------------------------------- */
undefined4 jos_critical_check(void)

{
  return *(undefined4 *)(DAT_3004a4ac + 0xc);
}

/* ----------------------------------------------------------------
 * jos_critical_check_d @ 0x3004A2DC  (примерный размер ~180 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: jos_critical_check, os_dprintf, os_printf, valid_type
 * Константы: 0x3004A2DC
 * Данные: DAT_3004a450, DAT_3004a47c, DAT_3004a49c, DAT_3004a4a0, DAT_3004a4ac, DAT_3004a4e0, DAT_3004a4e4
 * ---------------------------------------------------------------- */
void jos_critical_check_d(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  valid_type(0x23);
  if ((3 < *(int *)(DAT_3004a49c + 0x78)) && (3 < *(int *)(DAT_3004a49c + 0x8c))) {
    os_dprintf(DAT_3004a4a0,DAT_3004a47c,DAT_3004a4e0);
    iVar1 = DAT_3004a450;
    if (*DAT_3004a4ac != 0) {
      iVar1 = *DAT_3004a4ac;
    }
    os_printf(DAT_3004a4e4,0,DAT_3004a4ac[3],param_1,param_2,iVar1,DAT_3004a4ac[1]);
  }
  jos_critical_check();
  return;
}

/* ----------------------------------------------------------------
 * FUN_3004a390 @ 0x3004A390  (примерный размер ~344 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 2
 * Вызывает: BSP_MallocDbg, memset
 * Вызывают: jmutex_init_d, jtask_init
 * Константы: 0x3004A390
 * ---------------------------------------------------------------- */
void * FUN_3004a390(size_t param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)BSP_MallocDbg(param_1,0,param_3,param_4);
  if ((param_2 == 1) && (__s != (void *)0x0)) {
    memset(__s,0,param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * jslave_init @ 0x3004A4E8  (примерный размер ~80 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: jstart_stack
 * Константы: 0x3004A4E8
 * Данные: DAT_3004a634, DAT_3004a638, DAT_3004a63c, DAT_3004a640
 * ---------------------------------------------------------------- */
undefined4 jslave_init(void)

{
  valid_type(0x29);
  if ((2 < *(int *)(DAT_3004a634 + 0xa0)) && (2 < *(int *)(DAT_3004a634 + 0xa4))) {
    os_dprintf(DAT_3004a638,DAT_3004a63c,0x16);
    os_printf(DAT_3004a640);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * jslave_uninit @ 0x3004A538  (примерный размер ~4 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 0
 * Вызывают: jstart_stack, jstop_stack
 * Константы: 0x3004A538
 * ---------------------------------------------------------------- */
void jslave_uninit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * jslave_enable @ 0x3004A53C  (примерный размер ~88 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 5
 * Вызывает: core_enable, j_device_get_core_ctx, os_dprintf, os_printf, valid_type
 * Вызывают: jstart_stack
 * Константы: 0x3004A53C
 * Данные: DAT_3004a634, DAT_3004a638, DAT_3004a63c, DAT_3004a644
 * ---------------------------------------------------------------- */
void jslave_enable(undefined4 param_1)

{
  valid_type(0x29);
  if ((2 < *(int *)(DAT_3004a634 + 0xa0)) && (2 < *(int *)(DAT_3004a634 + 0xa4))) {
    os_dprintf(DAT_3004a638,DAT_3004a63c,0x35);
    os_printf(DAT_3004a644);
  }
  j_device_get_core_ctx(param_1);
  core_enable();
  return;
}

/* ----------------------------------------------------------------
 * jslave_disable @ 0x3004A594  (примерный размер ~88 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 5
 * Вызывает: core_disable, j_device_get_core_ctx, os_dprintf, os_printf, valid_type
 * Вызывают: jstart_stack, jstop_stack
 * Константы: 0x3004A594
 * Данные: DAT_3004a634, DAT_3004a638, DAT_3004a63c, DAT_3004a648
 * ---------------------------------------------------------------- */
void jslave_disable(undefined4 param_1)

{
  valid_type(0x29);
  if ((2 < *(int *)(DAT_3004a634 + 0xa0)) && (2 < *(int *)(DAT_3004a634 + 0xa4))) {
    os_dprintf(DAT_3004a638,DAT_3004a63c,0x45);
    os_printf(DAT_3004a648);
  }
  j_device_get_core_ctx(param_1);
  core_disable();
  return;
}

/* ----------------------------------------------------------------
 * jslave_reconfig @ 0x3004A5EC  (примерный размер ~48 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 2
 * Вызывает: core_reconfig, j_device_get_core_ctx
 * Константы: 0x3004A5EC
 * ---------------------------------------------------------------- */
void jslave_reconfig(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = j_device_get_core_ctx(param_1);
  core_reconfig(uVar1,param_2,param_3,param_4);
  return;
}

/* ----------------------------------------------------------------
 * jslave_wakeup_host @ 0x3004A61C  (примерный размер ~48 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 2
 * Вызывает: core_wakeup_host, j_device_get_core_ctx
 * Константы: 0x3004A61C
 * ---------------------------------------------------------------- */
void jslave_wakeup_host(undefined4 param_1)

{
  j_device_get_core_ctx(param_1);
  core_wakeup_host();
  return;
}

/* ----------------------------------------------------------------
 * FUN_3004a64c @ 0x3004A64C  (примерный размер ~308 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: core_request_free, os_dprintf, os_printf, valid_type
 * Константы: 0x3004A64C
 * Данные: DAT_3004b640, DAT_3004b644, DAT_3004b648, DAT_3004b64c, DAT_3004b650, DAT_3004b654
 * ---------------------------------------------------------------- */
void FUN_3004a64c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if (((*(int *)(*(int *)(iVar2 + 0x38) + 0x1c) != *(int *)(*(int *)(iVar2 + 0x38) + 0x20)) &&
      (valid_type(0x29), 0 < *(int *)(DAT_3004b640 + 0xa0))) && (0 < *(int *)(DAT_3004b640 + 0xa4)))
  {
    os_dprintf(DAT_3004b644,DAT_3004b648,0x8a);
    os_printf(DAT_3004b64c,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x20),
              *(undefined4 *)(param_1 + 0x1c));
  }
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
    os_dprintf(DAT_3004b644,DAT_3004b648,0x8e);
    os_printf(DAT_3004b650,*(undefined4 *)(*(int *)(iVar2 + 0x38) + 0x20),
              *(undefined4 *)(*(int *)(iVar2 + 0x38) + 0x1c));
  }
  if (*(int *)(*(int *)(iVar2 + 0x38) + 0x28) != 0) {
    valid_type(0x29);
    if ((2 < *(int *)(DAT_3004b640 + 0xa0)) && (2 < *(int *)(DAT_3004b640 + 0xa4))) {
      os_dprintf(DAT_3004b644,DAT_3004b648,0x95);
      os_printf(DAT_3004b654);
    }
    uVar1 = *(undefined4 *)(*(int *)(iVar2 + 0x38) + 0x28);
    core_request_free(*(undefined4 *)(iVar2 + 0x38));
    *(undefined4 *)(iVar2 + 0x38) = uVar1;
  }
  *(undefined4 *)(*(int *)(iVar2 + 0x38) + 0x18) = 0;
  return;
}

/* ----------------------------------------------------------------
 * dcd_set_out_nak @ 0x30055144  (примерный размер ~124 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 3
 * Вызывает: j_device_get_softc, os_bus_space_read_4, os_bus_space_write_4
 * Вызывают: core_set_out_nak
 * Константы: 0x30055144, 0x04000000, 0x08000000
 * ---------------------------------------------------------------- */
void dcd_set_out_nak(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = j_device_get_softc(param_1);
  if (param_2 != 0) {
    uVar1 = *(uint *)(param_2 + 0x20) >> 1;
    uVar3 = os_bus_space_read_4(*(undefined4 *)(iVar2 + 8),uVar1 * 0x20 + 0xb00);
    if (param_3 == 0) {
      os_bus_space_write_4(*(undefined4 *)(iVar2 + 8),uVar1 * 0x20 + 0xb00,uVar3 | 0x4000000);
    }
    else {
      os_bus_space_write_4(*(undefined4 *)(iVar2 + 8),uVar1 * 0x20 + 0xb00,uVar3 | 0x8000000);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300551c0 @ 0x300551C0  (примерный размер ~280 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 7
 * Вызывает: FUN_30051ff4, FUN_3005264c, j_device_get_softc, os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x300551C0
 * Данные: DAT_300554f0, DAT_300554f4, DAT_300554f8, DAT_300560c8, DAT_300560cc, DAT_300560d0, DAT_300560d4, DAT_300560d8
 * ---------------------------------------------------------------- */
undefined4 FUN_300551c0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = j_device_get_softc(param_1);
  uVar2 = 0;
  if (param_2 == 0) {
    uVar3 = (uint)(*(char *)(param_3 + 1) == '\x01');
  }
  else {
    uVar3 = *(uint *)(param_2 + 0x20);
  }
  if (*(int *)(uVar3 * 0x50 + iVar1 + 0x40) != 0) {
    os_dprintf(DAT_300560c8,DAT_300554f8,DAT_300560cc);
    os_dprintf(DAT_300560d0);
    os_panic(DAT_300560d4,DAT_300554f8,DAT_300560cc);
  }
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_300554f0 + 0xa0)) && (3 < *(int *)(DAT_300554f0 + 0xa8))) {
    os_dprintf(DAT_300554f4,DAT_300554f8,DAT_300560d8);
    os_printf(DAT_300560dc,*(undefined4 *)(param_3 + 0x1c),uVar3);
  }
  *(int *)(uVar3 * 0x50 + iVar1 + 0x40) = param_3;
  if (*(char *)(param_3 + 1) == '\0') {
    uVar2 = FUN_30051ff4(iVar1,uVar3);
  }
  else {
    FUN_3005264c(iVar1,uVar3);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300552d8 @ 0x300552D8  (примерный размер ~84 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: j_device_get_softc
 * Константы: 0x300552D8
 * ---------------------------------------------------------------- */
undefined4 FUN_300552d8(undefined4 param_1,undefined1 *param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = j_device_get_softc(param_1);
  *param_2 = (char)*(undefined4 *)
                    (((uint)((int)(param_3 & 0xff) >> 7 == 0) + (param_3 & 0xf) * 2) * 0x50 + iVar1
                    + 0x44);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3005532c @ 0x3005532C  (примерный размер ~944 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_30050e60, j_device_get_softc, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x3005532C
 * Данные: DAT_300554f0, DAT_300554f4, DAT_300554f8, DAT_300560c8, DAT_300560d4, DAT_30056200, DAT_30056204, DAT_30056208
 * ---------------------------------------------------------------- */
undefined4 FUN_3005532c(undefined4 param_1,char param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  
  iVar1 = j_device_get_softc(param_1);
  uVar4 = 0;
  uVar3 = 0;
  uVar2 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),0x4c);
  uVar2 = (uVar2 >> 0x10) + DAT_30056200;
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_300554f0 + 0xa0)) && (3 < *(int *)(DAT_300554f0 + 0xa8))) {
    os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30056204);
    os_printf(DAT_30056208,param_2);
  }
  valid_type(0x2a);
  if ((4 < *(int *)(DAT_300554f0 + 0xa0)) && (4 < *(int *)(DAT_300554f0 + 0xa8))) {
    os_dprintf(DAT_300554f4,DAT_300554f8,DAT_3005620c);
    os_printf(DAT_30056210,uVar2 & 0xffff);
  }
  if (param_2 != '\0') {
    for (bVar6 = 2; bVar6 < 0x20; bVar6 = bVar6 + 2) {
      iVar5 = iVar1 + (uint)bVar6 * 0x50;
      if (*(int *)(iVar5 + 0x2c) == 0) {
        os_dprintf(DAT_300560c8,DAT_300554f8,DAT_30056214);
        os_dprintf(DAT_300562cc);
        os_panic(DAT_300560d4,DAT_300554f8,DAT_30056214);
      }
      if ((*(int *)(iVar5 + 0x4c) != 0) &&
         ((*(short *)(iVar5 + 0x3c) != 0 || (*(short *)(iVar5 + 0x3e) != 0)))) {
        if ((uVar2 & 0xffff) < (uVar3 & 0xffff) + (uint)*(ushort *)(iVar5 + 0x3a)) {
          valid_type(0x2a);
          if ((0 < *(int *)(DAT_300554f0 + 0xa0)) && (0 < *(int *)(DAT_300554f0 + 0xa8))) {
            os_dprintf(DAT_300554f4,DAT_300554f8,DAT_300562d0);
            os_printf(DAT_300562d4);
          }
          return 10;
        }
        valid_type(0x2a);
        if ((3 < *(int *)(DAT_300562d8 + 0xa0)) && (3 < *(int *)(DAT_300562d8 + 0xa8))) {
          os_dprintf(DAT_300562dc,DAT_300562e0,DAT_300562e4);
          os_printf(DAT_300562e8,(int)(uint)bVar6 >> 1,*(undefined2 *)(iVar5 + 0x3a),
                    (uVar3 & 0xffff) + 0x210);
        }
        os_bus_space_write_4
                  (*(undefined4 *)(iVar1 + 8),((int)(uint)bVar6 >> 1) * 4 + 0x100,
                   (uVar3 & 0xffff) + 0x210 | (uint)*(ushort *)(iVar5 + 0x3a) << 0x10);
        uVar3 = uVar3 + *(ushort *)(iVar5 + 0x3a);
        uVar4 = uVar4 | ((int)(uint)bVar6 >> 1) << 6 | 0x20;
      }
    }
    FUN_30050e60(iVar1,uVar4);
    *(undefined4 *)(iVar1 + 0xa3c) = DAT_300562ec;
    for (bVar6 = 1; bVar6 < *(byte *)(iVar1 + 0xa2c); bVar6 = bVar6 + 1) {
      if ((*(short *)((uint)bVar6 * 0xa0 + iVar1 + 0x3c) != 0) ||
         (*(short *)((uint)bVar6 * 0xa0 + iVar1 + 0x3e) != 0)) {
        *(uint *)(iVar1 + 0xa3c) = *(uint *)(iVar1 + 0xa3c) | 1 << bVar6;
      }
    }
    for (bVar6 = 1; bVar6 < *(byte *)(iVar1 + 0xa2d); bVar6 = bVar6 + 1) {
      if ((*(short *)((uint)bVar6 * 0xa0 + iVar1 + 0x8c) != 0) ||
         (*(short *)((uint)bVar6 * 0xa0 + iVar1 + 0x8e) != 0)) {
        *(uint *)(iVar1 + 0xa3c) = *(uint *)(iVar1 + 0xa3c) | 1 << (uint)(byte)(bVar6 + 0x10);
      }
    }
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),DAT_300562f0,*(undefined4 *)(iVar1 + 0xa3c));
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300556dc @ 0x300556DC  (примерный размер ~228 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_30051150, j_device_get_softc, os_dprintf, os_printf, valid_type
 * Константы: 0x300556DC
 * Данные: DAT_300562d8, DAT_300562dc, DAT_300562e0, DAT_300562f4, DAT_300562f8
 * ---------------------------------------------------------------- */
undefined4 FUN_300556dc(undefined4 param_1,short param_2,uint param_3,undefined1 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)j_device_get_softc(param_1);
  uVar2 = 0xb;
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_300562d8 + 0xa0)) && (3 < *(int *)(DAT_300562d8 + 0xa8))) {
    os_dprintf(DAT_300562dc,DAT_300562e0,DAT_300562f4);
    os_printf(DAT_300562f8,param_2,param_3 & 0xffff,param_4);
  }
  if (param_2 == 0) {
    uVar2 = FUN_30051150(*puVar1,puVar1[((uint)((param_3 & 0x80) == 0) + (param_3 & 0x7f) * 2) *
                                        0x14 + 0x12],param_4);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300557c0 @ 0x300557C0  (примерный размер ~356 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 7
 * Вызывает: os_bus_space_read_4, os_bus_space_write_4, os_delay_ms, os_delay_us, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30055924
 * Константы: 0x300557C0, 0x80000000
 * Данные: DAT_300562d8, DAT_300562dc, DAT_300562e0, DAT_300562fc, DAT_30056300, DAT_30056304, DAT_30056308, DAT_3005630c
 * ---------------------------------------------------------------- */
void FUN_300557c0(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    os_delay_us(10);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x10);
    iVar2 = iVar2 + 1;
    if (DAT_300562fc < iVar2) {
      valid_type(0x2a);
      if (*(int *)(DAT_300562d8 + 0xa0) < 1) {
        return;
      }
      if (*(int *)(DAT_300562d8 + 0xa8) < 1) {
        return;
      }
      os_dprintf(DAT_300562dc,DAT_300562e0,DAT_30056300);
      os_printf(DAT_30056304);
      return;
    }
  } while ((uVar1 & 0x80000000) == 0);
  iVar2 = 0;
  os_bus_space_write_4(*(undefined4 *)(param_1 + 8),0x10,uVar1 | 1);
  do {
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x10);
    iVar2 = iVar2 + 1;
    if (DAT_30056308 < iVar2) {
      valid_type(0x2a);
      if ((0 < *(int *)(DAT_300562d8 + 0xa0)) && (0 < *(int *)(DAT_300562d8 + 0xa8))) {
        os_dprintf(DAT_300562dc,DAT_300562e0,DAT_3005630c);
        os_printf(DAT_30056310);
      }
      break;
    }
    os_delay_us(1);
  } while ((uVar1 & 1) != 0);
  os_delay_ms(100);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30055924 @ 0x30055924  (примерный размер ~716 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 9
 * Вызывает: FUN_300539a0, FUN_300557c0, j_device_get_softc, jos_interrupt_setup, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_printf, valid_type
 * Константы: 0x30055924, 0xFFFFC3F7, 0xFFFFFFFF, 0x00800000
 * Данные: DAT_300562d8, DAT_300562dc, DAT_300562e0, DAT_300562ec, DAT_300562f0, DAT_30056314, DAT_30056318, DAT_3005631c
 * ---------------------------------------------------------------- */
int FUN_30055924(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = j_device_get_softc(param_1);
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_300562d8 + 0xa0)) && (3 < *(int *)(DAT_300562d8 + 0xa8))) {
    os_dprintf(DAT_300562dc,DAT_300562e0,DAT_30056314);
    os_printf(DAT_30056318);
  }
  FUN_300557c0(iVar1);
  uVar2 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),0);
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),0,uVar2 | 0xc0);
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),8,0);
  uVar2 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),0xc);
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),0xc,uVar2 & 0xffffc3f7 | 0x2400);
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),0x14,0xffffffff);
  iVar3 = jos_interrupt_setup(*(undefined4 *)(iVar1 + 0xc),DAT_3005631c,iVar1,DAT_30056320,iVar1,
                              iVar1 + 0x10);
  if (iVar3 == 0) {
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x18) = 0;
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),0x24,0x200);
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),0x28,DAT_3005632c);
    uVar2 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),0x800);
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),0x800,uVar2 | 0x800000);
    uVar2 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),DAT_30056330);
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),DAT_30056330,uVar2 | 0x8000);
    *(undefined4 *)(iVar1 + 0xa34) = DAT_30056334;
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),0x18,*(undefined4 *)(iVar1 + 0xa34));
    valid_type(0x2a);
    if ((4 < *(int *)(DAT_300562d8 + 0xa0)) && (4 < *(int *)(DAT_300562d8 + 0xa8))) {
      os_dprintf(DAT_300562dc,DAT_300562e0,DAT_30056338);
      uVar4 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),0x18);
      os_printf(DAT_3005633c,0,uVar4);
    }
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),DAT_30056340,0x22f);
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),0x810,0x227);
    *(undefined4 *)(iVar1 + 0xa3c) = DAT_300562ec;
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),DAT_300562f0,*(undefined4 *)(iVar1 + 0xa3c));
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),8,0xaf);
    FUN_300539a0(param_1);
  }
  else {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_300562d8 + 0xa0)) && (0 < *(int *)(DAT_300562d8 + 0xa8))) {
      os_dprintf(DAT_300562dc,DAT_300562e0,DAT_30056324);
      os_printf(DAT_30056328,iVar3);
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_30055bf0 @ 0x30055BF0  (примерный размер ~352 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 7
 * Вызывает: j_device_get_softc, jos_interrupt_teardown, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_printf, valid_type
 * Константы: 0x30055BF0, 0xFFFFFF40
 * Данные: DAT_300562d8, DAT_300562dc, DAT_300562e0, DAT_300562f0, DAT_30056344, DAT_30056348, DAT_3005634c, DAT_30056350
 * ---------------------------------------------------------------- */
void FUN_30055bf0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar1 = j_device_get_softc(param_1);
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_300562d8 + 0xa0)) && (3 < *(int *)(DAT_300562d8 + 0xa8))) {
    os_dprintf(DAT_300562dc,DAT_300562e0,DAT_30056344);
    os_printf(DAT_30056348);
  }
  uVar2 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),8);
  uVar3 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),0xc);
  uVar3 = uVar3 & DAT_3005634c;
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),8,uVar2 & 0xffffff40);
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),0xc,uVar3 | 0x2400);
  uVar2 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),0x18);
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),0x18,uVar2 & ~*(uint *)(iVar1 + 0xa34));
  valid_type(0x2a);
  if ((4 < *(int *)(DAT_300562d8 + 0xa0)) && (4 < *(int *)(DAT_300562d8 + 0xa8))) {
    os_dprintf(DAT_300562dc,DAT_300562e0,DAT_30056350);
    uVar4 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),0x18);
    os_printf(DAT_30056354,*(undefined4 *)(iVar1 + 0xa34),uVar4);
  }
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),DAT_300562f0,0);
  if (*(int *)(iVar1 + 0x10) != 0) {
    jos_interrupt_teardown(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10));
    *(undefined4 *)(iVar1 + 0x10) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30055d50 @ 0x30055D50  (примерный размер ~192 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 6
 * Вызывает: core_unregister_dcd, j_device_get_bus, j_device_get_softc, jdma_free, os_bus_release_resource, uninit_endpoints
 * Вызывают: FUN_30055e10
 * Константы: 0x30055D50
 * ---------------------------------------------------------------- */
undefined4 FUN_30055d50(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 != 0) && (iVar1 = j_device_get_softc(param_1), iVar1 != 0)) {
    core_unregister_dcd(*(undefined4 *)(iVar1 + 4));
    if (*(int *)(iVar1 + 0x20) != 0) {
      jdma_free(*(undefined4 *)(iVar1 + 0x20));
    }
    if (*(int *)(iVar1 + 0xac8) != 0) {
      jdma_free(*(undefined4 *)(iVar1 + 0xac8));
    }
    uninit_endpoints(iVar1);
    uVar2 = j_device_get_bus(param_1);
    if (*(int *)(iVar1 + 8) != 0) {
      os_bus_release_resource(uVar2,*(undefined4 *)(iVar1 + 8));
    }
    if (*(int *)(iVar1 + 0xc) != 0) {
      os_bus_release_resource(uVar2,*(undefined4 *)(iVar1 + 0xc));
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30055e10 @ 0x30055E10  (примерный размер ~860 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 14
 * Вызывает: FUN_30055d50, core_register_dcd, init_endpoints, j_device_get_bus, j_device_get_nameunit, j_device_get_softc, jdma_alloc, jdma_buffer_get, jdma_virt_addr, os_bus_alloc_resource, os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x30055E10
 * Данные: DAT_300560c8, DAT_300560d4, DAT_300562d8, DAT_300562dc, DAT_300562e0, DAT_30056358, DAT_3005635c, DAT_30056360
 * ---------------------------------------------------------------- */
int FUN_30055e10(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)j_device_get_softc(param_1);
  uVar2 = j_device_get_bus(param_1);
  valid_type(0x2a);
  if ((2 < *(int *)(DAT_300562d8 + 0xa0)) && (2 < *(int *)(DAT_300562d8 + 0xa8))) {
    os_dprintf(DAT_300562dc,DAT_300562e0,0xe00);
    uVar3 = j_device_get_nameunit(param_1);
    os_printf(DAT_30056358,uVar3);
  }
  *puVar1 = param_1;
  puVar1[9] = 3;
  uVar3 = os_bus_alloc_resource(uVar2,2,0);
  puVar1[2] = uVar3;
  if (puVar1[2] == 0) {
    os_dprintf(DAT_300560c8,DAT_300562e0,DAT_3005635c);
    os_dprintf(DAT_30056360);
    os_panic(DAT_300560d4,DAT_300562e0,DAT_3005635c);
  }
  uVar2 = os_bus_alloc_resource(uVar2,1,0);
  puVar1[3] = uVar2;
  if (puVar1[3] == 0) {
    os_dprintf(DAT_300560c8,DAT_300562e0,DAT_30056364);
    os_dprintf(DAT_30056368);
    os_panic(DAT_300560d4,DAT_300562e0,DAT_30056364);
  }
  iVar4 = jdma_alloc(0x10,4,0,0,1,(int)puVar1 + DAT_3005636c);
  if (iVar4 == 0) {
    uVar2 = jdma_virt_addr(puVar1[0x2b2],0);
    puVar1[0x2b3] = uVar2;
    iVar4 = jdma_alloc(0x40,4,0,0,3,puVar1 + 8);
    if (iVar4 == 0) {
      uVar2 = jdma_buffer_get(puVar1[8]);
      puVar1[7] = uVar2;
      *(undefined4 *)(puVar1[0x2b3] + 4) = *(undefined4 *)(puVar1[7] + 4);
      iVar4 = init_endpoints(puVar1);
      if (iVar4 == 0) {
        iVar4 = core_register_dcd(param_1,DAT_30056384,puVar1 + 1);
        if (((iVar4 != 0) && (valid_type(0x2a), 0 < *(int *)(DAT_300562d8 + 0xa0))) &&
           (0 < *(int *)(DAT_300562d8 + 0xa8))) {
          os_dprintf(DAT_300562dc,DAT_300562e0,DAT_30056388);
          os_printf(DAT_3005638c);
        }
      }
      else {
        valid_type(0x2a);
        if ((0 < *(int *)(DAT_300562d8 + 0xa0)) && (0 < *(int *)(DAT_300562d8 + 0xa8))) {
          os_dprintf(DAT_300562dc,DAT_300562e0,DAT_3005637c);
          os_printf(DAT_30056380);
        }
      }
    }
    else {
      valid_type(0x2a);
      if ((0 < *(int *)(DAT_300562d8 + 0xa0)) && (0 < *(int *)(DAT_300562d8 + 0xa8))) {
        os_dprintf(DAT_300562dc,DAT_300562e0,DAT_30056374);
        os_printf(DAT_30056378);
      }
      puVar1[8] = 0;
    }
  }
  else {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_300562d8 + 0xa0)) && (0 < *(int *)(DAT_300562d8 + 0xa8))) {
      os_dprintf(DAT_300562dc,DAT_300562e0,0xe20);
      os_printf(DAT_30056370);
    }
    puVar1[0x2b2] = 0;
  }
  if (iVar4 != 0) {
    FUN_30055d50(param_1);
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * FUN_3005616c @ 0x3005616C  (примерный размер ~216 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: j_device_get_softc, os_dprintf, os_printf, valid_type
 * Константы: 0x3005616C
 * Данные: DAT_300562d8, DAT_300562dc, DAT_300562e0, DAT_30056390, DAT_30056394, DAT_30056398, DAT_3005639c
 * ---------------------------------------------------------------- */
undefined4 FUN_3005616c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_300562d8 + 0xa0)) && (3 < *(int *)(DAT_300562d8 + 0xa8))) {
    os_dprintf(DAT_300562dc,DAT_300562e0,DAT_30056390);
    os_printf(DAT_30056394);
  }
  if ((param_1 != 0) && (iVar1 = j_device_get_softc(param_1), iVar1 != 0)) {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_300562d8 + 0xa0)) && (0 < *(int *)(DAT_300562d8 + 0xa8))) {
      os_dprintf(DAT_300562dc,DAT_300562e0,DAT_30056398);
      os_printf(DAT_3005639c,param_2);
    }
    uVar2 = 10;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * cdc_get_iostatus @ 0x300563B0  (примерный размер ~308 байт)
 * Модуль: usb | Вызывают: 13 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30056524, FUN_30056644, FUN_30057200, FUN_30057898, FUN_30057c70, FUN_30058178, FUN_30058310, FUN_3005d728, FUN_3005da98, FUN_3005df90
 *           ...
 * Константы: 0xFFFFFFFF, 0x300563B0
 * Данные: DAT_300573b0, DAT_300573b4, DAT_300573b8, DAT_300573bc, DAT_300573c0, DAT_300573c4
 * ---------------------------------------------------------------- */
undefined4 cdc_get_iostatus(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 2) {
    valid_type(0x3d);
    if ((2 < *(int *)(DAT_300573b0 + 0xf0)) && (2 < *(int *)(DAT_300573b0 + 0xf4))) {
      os_dprintf(DAT_300573b4,DAT_300573b8,0x24);
      os_printf(DAT_300573c0,*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x1c));
    }
    uVar1 = 1;
  }
  else if (*(int *)(param_1 + 0x18) == 5) {
    if ((param_2 == 0) || (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x1c))) {
      uVar1 = 0;
    }
    else {
      valid_type(0x3d);
      if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
        os_dprintf(DAT_300573b4,DAT_300573b8,0x1d);
        os_printf(DAT_300573bc,*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x1c));
      }
      uVar1 = 0xffffffff;
    }
  }
  else {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
      os_dprintf(DAT_300573b4,DAT_300573b8,0x2a);
      os_printf(DAT_300573c4,*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x1c));
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300564e4 @ 0x300564E4  (примерный размер ~64 байт)
 * Модуль: usb | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_30058598, FUN_300589d0, cdc_enable
 * Константы: 0x300564E4
 * ---------------------------------------------------------------- */
undefined2 FUN_300564e4(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if (param_2 == 3) {
    if (*(short *)(param_1 + 0xdc) == 0) {
      uVar1 = 0x200;
    }
    else {
      uVar1 = *(undefined2 *)(param_1 + 0xdc);
    }
  }
  else {
    uVar1 = 0x40;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30056524 @ 0x30056524  (примерный размер ~288 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 6
 * Вызывает: __urem32, cdc_get_iostatus, core_request_free, os_dprintf, os_printf, valid_type
 * Константы: 0x30056524
 * Данные: DAT_300573b0, DAT_300573b4, DAT_300573b8, DAT_300574dc, DAT_300574e0
 * ---------------------------------------------------------------- */
void FUN_30056524(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x14);
  valid_type(0x3d);
  if ((2 < *(int *)(DAT_300573b0 + 0xf0)) && (2 < *(int *)(DAT_300573b0 + 0xf4))) {
    os_dprintf(DAT_300573b4,DAT_300573b8,0x56);
    os_printf(DAT_300574dc);
  }
  if (*(int *)(iVar4 + 0x98) != 0) {
    uVar1 = cdc_get_iostatus(param_1,0);
    if ((*(uint *)(param_1 + 0x20) < *(uint *)(param_1 + 0x1c)) ||
       (iVar2 = __urem32(*(undefined4 *)(param_1 + 0x1c),*(undefined2 *)(iVar4 + 0x46)), iVar2 != 0)
       ) {
      uVar3 = 1;
      valid_type(0x3d);
      if ((4 < *(int *)(DAT_300573b0 + 0xf0)) && (4 < *(int *)(DAT_300573b0 + 0xf4))) {
        os_dprintf(DAT_300573b4,DAT_300573b8,0x6c);
        os_printf(DAT_300574e0);
      }
    }
    else {
      uVar3 = 0;
    }
    (**(code **)(iVar4 + 0x98))
              (uVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x20),uVar3,
               *(undefined4 *)(iVar4 + 4),*(undefined4 *)(param_1 + 0x28));
  }
  core_request_free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30056644 @ 0x30056644  (примерный размер ~152 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 5
 * Вызывает: cdc_get_iostatus, core_request_free, os_dprintf, os_printf, valid_type
 * Константы: 0x30056644
 * Данные: DAT_300573b0, DAT_300573b4, DAT_300573b8, DAT_300575b0
 * ---------------------------------------------------------------- */
void FUN_30056644(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_300573b0 + 0xf0)) && (4 < *(int *)(DAT_300573b0 + 0xf4))) {
    os_dprintf(DAT_300573b4,DAT_300573b8,0x84);
    os_printf(DAT_300575b0);
  }
  if (*(int *)(iVar2 + 0x9c) != 0) {
    uVar1 = cdc_get_iostatus(param_1,1);
    (**(code **)(iVar2 + 0x9c))
              (uVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar2 + 4),
               *(undefined4 *)(param_1 + 0x28));
  }
  core_request_free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * uwd_cdc_write @ 0x300566DC  (примерный размер ~552 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 6
 * Вызывает: core_request_alloc, core_request_free, core_send_data, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30060b5c, FUN_30060dd0
 * Константы: 0x300566DC
 * Данные: DAT_300573b0, DAT_300573b4, DAT_300573b8, DAT_300576a8, DAT_300576ac, DAT_300576b0, DAT_300576b4, DAT_300577ec
 * ---------------------------------------------------------------- */
int uwd_cdc_write(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)0x0;
  if ((*(short *)(param_1 + 0x35) == 0) || (param_3 <= *(ushort *)(param_1 + 0x35))) {
    if (param_1[9] == 0) {
      valid_type(0x3d);
      if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
        os_dprintf(DAT_300573b4,DAT_300573b8,0xb3);
        os_printf(DAT_300576ac,0);
      }
      iVar1 = 0x10;
    }
    else {
      puVar2 = (undefined1 *)core_request_alloc(*param_1,param_3,param_2);
      if (puVar2 == (undefined1 *)0x0) {
        valid_type(0x3d);
        if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
          os_dprintf(DAT_300573b4,DAT_300573b8,0xbb);
          os_printf(DAT_300576b0,0);
        }
        iVar1 = 7;
      }
      else {
        if ((param_1[0x36] == 0) &&
           ((*(short *)(param_1 + 0x35) == 0 || (*(ushort *)(param_1 + 0x35) <= param_3)))) {
          *puVar2 = 0;
        }
        else {
          *puVar2 = 1;
        }
        *(undefined4 *)(puVar2 + 0x10) = DAT_300576b4;
        *(undefined4 **)(puVar2 + 0x14) = param_1;
        *(undefined4 *)(puVar2 + 0x28) = param_4;
        *(uint *)(puVar2 + 0x1c) = param_3;
        iVar1 = core_send_data(*param_1,param_1[9],puVar2);
        if (iVar1 == 0) {
          return 0;
        }
        valid_type(0x3d);
        if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
          os_dprintf(DAT_300573b4,DAT_300573b8,0xd9);
          os_printf(DAT_300577ec,0);
        }
      }
    }
  }
  else {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
      os_dprintf(DAT_300573b4,DAT_300573b8,0xab);
      os_printf(DAT_300576a8,0,param_3,*(undefined2 *)(param_1 + 0x35));
    }
    iVar1 = 10;
  }
  if (puVar2 != (undefined1 *)0x0) {
    core_request_free(puVar2);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * uwd_cdc_set_out_nak @ 0x30056904  (примерный размер ~40 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 1
 * Вызывает: core_set_out_nak
 * Вызывают: FUN_30060874
 * Константы: 0x30056904
 * ---------------------------------------------------------------- */
undefined4 uwd_cdc_set_out_nak(undefined4 *param_1,undefined4 param_2)

{
  core_set_out_nak(*param_1,param_1[0xb],param_2);
  return 0;
}

/* ----------------------------------------------------------------
 * uwd_cdc_read @ 0x3005692C  (примерный размер ~500 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 6
 * Вызывает: core_read_data, core_request_alloc, core_request_free, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3005f6fc, FUN_3005fb90
 * Константы: 0x3005692C
 * Данные: DAT_300573b0, DAT_300573b4, DAT_300573b8, DAT_300576a8, DAT_300576b0, DAT_3005790c, DAT_30057910, DAT_30057914
 * ---------------------------------------------------------------- */
int uwd_cdc_read(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((*(short *)(param_1 + 0x35) == 0) || (param_3 <= *(ushort *)(param_1 + 0x35))) {
    if (param_1[0xb] == 0) {
      valid_type(0x3d);
      if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
        os_dprintf(DAT_300573b4,DAT_300573b8,0x114);
        os_printf(DAT_3005790c,0);
      }
      iVar1 = 0x10;
    }
    else {
      iVar2 = core_request_alloc(*param_1,param_3,param_2);
      if (iVar2 == 0) {
        valid_type(0x3d);
        if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
          os_dprintf(DAT_300573b4,DAT_300573b8,0x11c);
          os_printf(DAT_300576b0,0);
        }
        iVar1 = 7;
      }
      else {
        *(undefined4 *)(iVar2 + 0x10) = DAT_30057910;
        *(undefined4 **)(iVar2 + 0x14) = param_1;
        *(undefined4 *)(iVar2 + 0x28) = param_4;
        *(uint *)(iVar2 + 0x1c) = param_3;
        *(undefined4 *)(iVar2 + 0x40) = 0;
        iVar1 = core_read_data(*param_1,param_1[0xb],iVar2);
        if (iVar1 == 0) {
          return 0;
        }
        valid_type(0x3d);
        if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
          os_dprintf(DAT_300573b4,DAT_300573b8,DAT_30057914);
          os_printf(DAT_30057918,0);
        }
      }
    }
  }
  else {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
      os_dprintf(DAT_300573b4,DAT_300573b8,0x10c);
      os_printf(DAT_300576a8,0,param_3,*(undefined2 *)(param_1 + 0x35));
    }
    iVar1 = 10;
  }
  if (iVar2 != 0) {
    core_request_free(iVar2);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * uwd_cdc_read_flow @ 0x30056B20  (примерный размер ~500 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 6
 * Вызывает: core_read_data, core_request_alloc, core_request_free, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3005fb90
 * Константы: 0x30056B20
 * Данные: DAT_300573b0, DAT_300573b4, DAT_300573b8, DAT_300576a8, DAT_300576b0, DAT_3005790c, DAT_30057910, DAT_30057918
 * ---------------------------------------------------------------- */
int uwd_cdc_read_flow(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((*(short *)(param_1 + 0x35) == 0) || (param_3 <= *(ushort *)(param_1 + 0x35))) {
    if (param_1[0xb] == 0) {
      valid_type(0x3d);
      if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
        os_dprintf(DAT_300573b4,DAT_300573b8,DAT_30057a8c);
        os_printf(DAT_3005790c,0);
      }
      iVar1 = 0x10;
    }
    else {
      iVar2 = core_request_alloc(*param_1,param_3,param_2);
      if (iVar2 == 0) {
        valid_type(0x3d);
        if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
          os_dprintf(DAT_300573b4,DAT_300573b8,DAT_30057a90);
          os_printf(DAT_300576b0,0);
        }
        iVar1 = 7;
      }
      else {
        *(undefined4 *)(iVar2 + 0x10) = DAT_30057910;
        *(undefined4 **)(iVar2 + 0x14) = param_1;
        *(undefined4 *)(iVar2 + 0x28) = param_4;
        *(uint *)(iVar2 + 0x1c) = param_3;
        *(undefined4 *)(iVar2 + 0x40) = 1;
        iVar1 = core_read_data(*param_1,param_1[0xb],iVar2);
        if (iVar1 == 0) {
          return 0;
        }
        valid_type(0x3d);
        if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
          os_dprintf(DAT_300573b4,DAT_300573b8,0x168);
          os_printf(DAT_30057918,0);
        }
      }
    }
  }
  else {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
      os_dprintf(DAT_300573b4,DAT_300573b8,DAT_30057a88);
      os_printf(DAT_300576a8,0,param_3,*(undefined2 *)(param_1 + 0x35));
    }
    iVar1 = 10;
  }
  if (iVar2 != 0) {
    core_request_free(iVar2);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * uwd_cdc_abort_write @ 0x30056D14  (примерный размер ~52 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 1
 * Вызывает: core_abort_pipe
 * Вызывают: FUN_3005f620, FUN_300608b0
 * Константы: 0x30056D14
 * ---------------------------------------------------------------- */
undefined4 uwd_cdc_abort_write(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[9] == 0) {
    uVar1 = 6;
  }
  else {
    core_abort_pipe(*param_1,param_1[9]);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * uwd_cdc_abort_read @ 0x30056D48  (примерный размер ~52 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 1
 * Вызывает: core_abort_pipe
 * Вызывают: FUN_3005f620
 * Константы: 0x30056D48
 * ---------------------------------------------------------------- */
undefined4 uwd_cdc_abort_read(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0xb] == 0) {
    uVar1 = 6;
  }
  else {
    core_abort_pipe(*param_1,param_1[0xb]);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * uwd_cdc_get_read_size @ 0x30056D7C  (примерный размер ~20 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30056D7C
 * ---------------------------------------------------------------- */
undefined2 uwd_cdc_get_read_size(int param_1)

{
  return *(undefined2 *)(param_1 + 0x46);
}

/* ----------------------------------------------------------------
 * FUN_30056d90 @ 0x30056D90  (примерный размер ~324 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 5
 * Вызывает: core_request_alloc, core_request_free, os_dprintf, os_printf, valid_type
 * Вызывают: cdc_create_ep0_read, cdc_create_ep0_write
 * Константы: 0x30056D90
 * Данные: DAT_300573b0, DAT_300573b4, DAT_300573b8, DAT_30057cd8, DAT_30057cdc, DAT_30057ce0
 * ---------------------------------------------------------------- */
int FUN_30056d90(undefined4 *param_1,int *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_2;
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x18) != 1)) {
    if ((iVar2 == 0) || (*(undefined4 *)(iVar2 + 0x18) = 0, *(uint *)(iVar2 + 0xc) < param_4)) {
      uVar3 = param_4;
      if (param_4 == 0) {
        uVar3 = 10;
      }
      iVar1 = core_request_alloc(*param_1,uVar3,param_3);
      if (iVar1 == 0) {
        valid_type(0x3d);
        if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
          os_dprintf(DAT_300573b4,DAT_300573b8,0x1dc);
          os_printf(DAT_30057ce0,0);
        }
        goto LAB_30056ecc;
      }
      if (iVar2 != 0) {
        core_request_free(iVar2);
      }
      *param_2 = iVar1;
      iVar2 = *param_2;
    }
    *(uint *)(iVar2 + 0x1c) = param_4;
  }
  else {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
      os_dprintf(DAT_300573b4,DAT_300573b8,DAT_30057cd8);
      os_printf(DAT_30057cdc,0);
    }
LAB_30056ecc:
    iVar2 = 0;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * cdc_create_ep0_read @ 0x30056ED4  (примерный размер ~144 байт)
 * Модуль: usb | Вызывают: 3 | Вызывает: 4
 * Вызывает: FUN_30056d90, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3005d890, FUN_3005e140, cdc_handle_encapsulated_command
 * Константы: 0x30056ED4
 * Данные: DAT_300573b0, DAT_300573b4, DAT_300573b8, DAT_30057df0, DAT_30057df4
 * ---------------------------------------------------------------- */
int cdc_create_ep0_read(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
      os_dprintf(DAT_300573b4,DAT_300573b8,DAT_30057df0);
      os_printf(DAT_30057df4);
    }
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_30056d90(param_1,param_1 + 0x3c,0,param_2);
    if (iVar1 != 0) {
      *(undefined1 *)(iVar1 + 3) = *(undefined1 *)(param_1 + 0x50);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * cdc_create_ep0_write @ 0x30056F64  (примерный размер ~364 байт)
 * Модуль: usb | Вызывают: 4 | Вызывает: 5
 * Вызывает: FUN_30056d90, os_dprintf, os_memcpy, os_printf, valid_type
 * Вызывают: FUN_3005db28, FUN_3005e3c4, cdc_handle_encapsulated_response, cdc_send_status
 * Константы: 0x30056F64
 * Данные: DAT_300573b0, DAT_300573b4, DAT_300573b8, DAT_30057df8, DAT_30057dfc
 * ---------------------------------------------------------------- */
undefined1 * cdc_create_ep0_write(int param_1,int param_2,uint param_3,uint param_4)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
      os_dprintf(DAT_300573b4,DAT_300573b8,0x21c);
      os_printf(DAT_30057df8,0);
    }
    puVar1 = (undefined1 *)0x0;
  }
  else {
    puVar1 = (undefined1 *)FUN_30056d90(param_1,param_1 + 0x40,0,param_3);
    if (puVar1 == (undefined1 *)0x0) {
      valid_type(0x3d);
      if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
        os_dprintf(DAT_300573b4,DAT_300573b8,0x224);
        os_printf(DAT_30057dfc,0);
      }
      puVar1 = (undefined1 *)0x0;
    }
    else {
      if ((param_2 != 0) && (param_3 != 0)) {
        os_memcpy(**(undefined4 **)(*(int *)(param_1 + 0x40) + 8),param_2,param_3);
      }
      uVar3 = param_4;
      if (param_4 <= param_3) {
        uVar3 = 0;
      }
      uVar2 = (undefined1)uVar3;
      if (param_3 < param_4) {
        uVar2 = 1;
      }
      *puVar1 = uVar2;
      puVar1[3] = *(undefined1 *)(param_1 + 0x50);
    }
  }
  return puVar1;
}

/* ----------------------------------------------------------------
 * cdc_send_status @ 0x300570D0  (примерный размер ~304 байт)
 * Модуль: usb | Вызывают: 6 | Вызывает: 5
 * Вызывает: cdc_create_ep0_write, core_send_data, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30057200, FUN_3005d728, FUN_3005dda4, FUN_3005df90, FUN_3005e688, FUN_3005e844
 * Константы: 0x300570D0
 * Данные: DAT_300573b0, DAT_300573b4, DAT_300573b8, DAT_30057f1c, DAT_30057f20, DAT_30058024, DAT_30058028, DAT_3005802c
 * ---------------------------------------------------------------- */
int cdc_send_status(undefined4 *param_1)

{
  int iVar1;
  
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_300573b0 + 0xf0)) && (4 < *(int *)(DAT_300573b0 + 0xf4))) {
    os_dprintf(DAT_300573b4,DAT_300573b8,DAT_30057f1c);
    os_printf(DAT_30057f20,0);
  }
  iVar1 = cdc_create_ep0_write(param_1,0,0,0);
  if (iVar1 == 0) {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
      os_dprintf(DAT_300573b4,DAT_300573b8,DAT_30058024);
      os_printf(DAT_30058028,0);
    }
    iVar1 = 7;
  }
  else {
    *(undefined4 *)(iVar1 + 0x10) = DAT_3005802c;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    iVar1 = core_send_data(*param_1,0,iVar1);
    if (((iVar1 != 0) && (valid_type(0x3d), 0 < *(int *)(DAT_300573b0 + 0xf0))) &&
       (0 < *(int *)(DAT_300573b0 + 0xf4))) {
      os_dprintf(DAT_300573b4,DAT_300573b8,DAT_30058030);
      os_printf(DAT_30058034,0);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30057200 @ 0x30057200  (примерный размер ~340 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 6
 * Вызывает: cdc_get_iostatus, cdc_send_status, core_stall_ctrl_pipe, os_dprintf, os_printf, valid_type
 * Константы: 0x30057200
 * Данные: DAT_300573b0, DAT_300573b4, DAT_300573b8, DAT_30057f20, DAT_30058170, DAT_30058174
 * ---------------------------------------------------------------- */
void FUN_30057200(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x14);
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_300573b0 + 0xf0)) && (4 < *(int *)(DAT_300573b0 + 0xf4))) {
    os_dprintf(DAT_300573b4,DAT_300573b8,0x278);
    os_printf(DAT_30057f20,0);
  }
  iVar1 = cdc_get_iostatus(param_1,1);
  if (iVar1 == 0) {
    iVar1 = (*(code *)puVar2[0x23])
                      (*(undefined4 *)(param_1 + 8),*(uint *)(param_1 + 0x20) & 0xffff,puVar2[1]);
    if (iVar1 == 0) {
      iVar1 = cdc_send_status(puVar2);
      if (iVar1 == 0) {
        return;
      }
      valid_type(0x3d);
      if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
        os_dprintf(DAT_300573b4,DAT_300573b8,0x28c);
        os_printf(DAT_30058174,0,iVar1);
      }
    }
    else {
      valid_type(0x3d);
      if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
        os_dprintf(DAT_300573b4,DAT_300573b8,0x284);
        os_printf(DAT_30058170,0);
      }
    }
  }
  core_stall_ctrl_pipe(*puVar2,*(undefined1 *)(puVar2 + 0x14));
  return;
}

/* ----------------------------------------------------------------
 * FUN_30057354 @ 0x30057354  (примерный размер ~420 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 5
 * Вызывает: core_request_alloc, os_dprintf, os_memcpy, os_printf, valid_type
 * Вызывают: FUN_30057fc8, cdc_create_notification
 * Константы: 0x30057354
 * Данные: DAT_300573b0, DAT_30057df8, DAT_30058294, DAT_30058298, DAT_3005829c, DAT_300582a0, DAT_300582a4
 * ---------------------------------------------------------------- */
undefined1 *
FUN_30057354(undefined4 *param_1,byte param_2,undefined2 param_3,undefined2 param_4,ushort param_5,
            int param_6,int param_7)

{
  undefined1 *puVar1;
  byte *pbVar2;
  char cVar3;
  bool bVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_300573b0 + 0xf0)) && (0 < *(int *)(DAT_300573b0 + 0xf4))) {
      os_dprintf(DAT_30058294,DAT_30058298,0x37c);
      os_printf(DAT_30057df8,0);
    }
    puVar1 = (undefined1 *)0x0;
  }
  else {
    puVar1 = (undefined1 *)core_request_alloc(*param_1,param_5 + 8,0);
    if (puVar1 == (undefined1 *)0x0) {
      valid_type(0x3d);
      if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
        os_dprintf(DAT_30058294,DAT_30058298,DAT_300582a0);
        os_printf(DAT_300582a4,0);
      }
      puVar1 = (undefined1 *)0x0;
    }
    else {
      *puVar1 = 0;
      *(uint *)(puVar1 + 0x1c) = param_5 + 8;
      pbVar2 = (byte *)**(undefined4 **)(puVar1 + 8);
      bVar4 = param_7 == 0;
      if (bVar4) {
        param_7 = 0;
      }
      cVar3 = (char)param_7;
      if (!bVar4) {
        cVar3 = '\x01';
      }
      *pbVar2 = cVar3 * ' ' + 0x20U | 0x81;
      pbVar2[1] = param_2;
      *(undefined2 *)(pbVar2 + 2) = param_3;
      *(undefined2 *)(pbVar2 + 4) = param_4;
      *(ushort *)(pbVar2 + 6) = param_5;
      if ((param_5 != 0) && (param_6 != 0)) {
        os_memcpy(pbVar2 + 8,param_6,param_5);
      }
    }
  }
  return puVar1;
}

/* ----------------------------------------------------------------
 * cdc_create_notification @ 0x300574F8  (примерный размер ~76 байт)
 * Модуль: usb | Вызывают: 3 | Вызывает: 1
 * Вызывает: FUN_30057354
 * Вызывают: FUN_30057544, uwd_acm_notify_network_connection, uwd_acm_notify_serial_state
 * Константы: 0x300574F8
 * ---------------------------------------------------------------- */
void cdc_create_notification
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined2 param_5,undefined4 param_6)

{
  FUN_30057354(param_1,param_2,param_3,param_4,param_5,param_6,0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30057544 @ 0x30057544  (примерный размер ~184 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 3
 * Вызывает: cdc_create_notification, core_request_free, core_send_data
 * Вызывают: cdc_handle_encapsulated_command, uwd_cdc_send_encap_response
 * Константы: 0x30057544
 * Данные: DAT_30058458
 * ---------------------------------------------------------------- */
int FUN_30057544(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1[0xd] == 0) {
    iVar2 = 6;
  }
  else if (param_1[0x16] == 0) {
    iVar1 = cdc_create_notification(param_1,1,0,*(undefined2 *)(param_1 + 0xe),0,0);
    if (iVar1 == 0) {
      iVar2 = 7;
    }
    else {
      *(undefined4 *)(iVar1 + 0x10) = DAT_30058458;
      *(undefined4 **)(iVar1 + 0x14) = param_1;
      iVar2 = core_send_data(*param_1,param_1[0xd],iVar1);
      if (iVar2 == 0) {
        param_1[0x16] = 1;
      }
      else {
        core_request_free(iVar1);
      }
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * cdc_handle_encapsulated_command @ 0x300575FC  (примерный размер ~552 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_30057544, cdc_create_ep0_read, core_read_data, os_dprintf, os_printf, valid_type
 * Вызывают: acm_handle_request
 * Константы: 0x300575FC
 * Данные: DAT_30057f20, DAT_30058294, DAT_30058298, DAT_3005829c, DAT_3005845c, DAT_300585b0, DAT_300585b4, DAT_300585b8
 * ---------------------------------------------------------------- */
undefined4 cdc_handle_encapsulated_command(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 10;
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_3005829c + 0xf0)) && (4 < *(int *)(DAT_3005829c + 0xf4))) {
    os_dprintf(DAT_30058294,DAT_30058298,DAT_3005845c);
    os_printf(DAT_30057f20,0);
  }
  if ((uint)param_1[0x34] < (uint)*(ushort *)(param_2 + 6)) {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
      os_dprintf(DAT_30058294,DAT_30058298,DAT_300585b0);
      os_printf(DAT_300585b4,0,*(undefined2 *)(param_2 + 6));
    }
  }
  else if (param_1[0x23] == 0) {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
      os_dprintf(DAT_30058294,DAT_30058298,0x2b4);
      os_printf(DAT_300585b8,0);
    }
  }
  else {
    if ((((param_1[0x15] != 0) && (iVar1 = FUN_30057544(param_1), iVar1 != 0)) &&
        (valid_type(0x3d), 1 < *(int *)(DAT_3005829c + 0xf0))) &&
       (1 < *(int *)(DAT_3005829c + 0xf4))) {
      os_dprintf(DAT_30058294,DAT_30058298,0x2c0);
      os_printf(DAT_300585bc,0,iVar1);
    }
    iVar1 = cdc_create_ep0_read(param_1,*(undefined2 *)(param_2 + 6));
    if (iVar1 == 0) {
      valid_type(0x3d);
      if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
        os_dprintf(DAT_30058294,DAT_30058298,0x2c8);
        os_printf(DAT_300586b8,0);
      }
      uVar2 = 7;
    }
    else {
      *(undefined4 *)(iVar1 + 0x10) = DAT_300586bc;
      *(undefined4 **)(iVar1 + 0x14) = param_1;
      uVar2 = core_read_data(*param_1,0,iVar1);
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30057824 @ 0x30057824  (примерный размер ~116 байт)
 * Модуль: usb | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_30057898, FUN_30059600, cdc_disable, cdc_handle_encapsulated_response, uwd_cdc_send_encap_response
 * Константы: 0x30057824
 * ---------------------------------------------------------------- */
void FUN_30057824(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x54) == 0) {
    param_2 = 0;
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(param_1 + 0x68) = 0;
  if ((param_2 != 0) && (*(int *)(param_1 + 0x90) != 0)) {
    (**(code **)(param_1 + 0x90))(param_3,uVar1,*(undefined4 *)(param_1 + 4));
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30057898 @ 0x30057898  (примерный размер ~456 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_30057824, cdc_get_iostatus, os_dprintf, os_printf, valid_type
 * Константы: 0x30057898
 * Данные: DAT_30057f20, DAT_30058294, DAT_30058298, DAT_3005829c, DAT_300586c0, DAT_30058830, DAT_30058834, DAT_30058838
 * ---------------------------------------------------------------- */
void FUN_30057898(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_3005829c + 0xf0)) && (4 < *(int *)(DAT_3005829c + 0xf4))) {
    os_dprintf(DAT_30058294,DAT_30058298,DAT_300586c0);
    os_printf(DAT_30057f20,0);
  }
  if (*(int *)(iVar2 + 0x5c) == 0) {
    *(int *)(iVar2 + 0x68) = *(int *)(iVar2 + 0x68) + *(int *)(param_1 + 0x20);
    iVar1 = cdc_get_iostatus(param_1,1);
    if (iVar1 == 0) {
      if (*(int *)(iVar2 + 0x54) == 1) {
        valid_type(0x3d);
        if ((4 < *(int *)(DAT_3005829c + 0xf0)) && (4 < *(int *)(DAT_3005829c + 0xf4))) {
          os_dprintf(DAT_30058294,DAT_30058298,0x308);
          os_printf(DAT_30058840,0,*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(iVar2 + 0x68));
        }
        if (*(uint *)(iVar2 + 0x68) < *(uint *)(iVar2 + 100)) {
          return;
        }
      }
      else {
        valid_type(0x3d);
        if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
          os_dprintf(DAT_30058294,DAT_30058298,DAT_30058838);
          os_printf(DAT_3005883c,0,*(undefined4 *)(iVar2 + 0x54));
        }
        iVar1 = -1;
      }
    }
    FUN_30057824(iVar2,1,iVar1);
  }
  else {
    valid_type(0x3d);
    if ((4 < *(int *)(DAT_3005829c + 0xf0)) && (4 < *(int *)(DAT_3005829c + 0xf4))) {
      os_dprintf(DAT_30058294,DAT_30058298,DAT_30058830);
      os_printf(DAT_30058834,0);
    }
    *(uint *)(iVar2 + 0x54) = (uint)(*(int *)(iVar2 + 100) != 0);
    *(undefined4 *)(iVar2 + 0x5c) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * cdc_handle_encapsulated_response @ 0x30057A60  (примерный размер ~528 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_30057824, cdc_create_ep0_write, core_send_data, os_dprintf, os_printf, valid_type
 * Вызывают: acm_handle_request
 * Константы: 0x30057A60, 0xFFFFFFFF
 * Данные: DAT_30057f20, DAT_30058294, DAT_30058298, DAT_3005829c, DAT_300589a0, DAT_300589a4, DAT_300589a8, DAT_300589ac
 * ---------------------------------------------------------------- */
int cdc_handle_encapsulated_response(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = param_1[0x18];
  uVar2 = (uint)*(ushort *)(param_2 + 6);
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_3005829c + 0xf0)) && (4 < *(int *)(DAT_3005829c + 0xf4))) {
    os_dprintf(DAT_30058294,DAT_30058298,DAT_300589a0);
    os_printf(DAT_30057f20,0);
  }
  if (param_1[0x15] == 0) {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
      os_dprintf(DAT_30058294,DAT_30058298,0x330);
      os_printf(DAT_300589a4,0);
    }
    iVar3 = 0;
  }
  uVar4 = uVar2;
  if ((uint)(param_1[0x19] - param_1[0x1a]) < uVar2) {
    uVar4 = param_1[0x19] - param_1[0x1a];
  }
  iVar1 = cdc_create_ep0_write(param_1,iVar3 + param_1[0x1a],uVar4,uVar2);
  if (iVar1 == 0) {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
      os_dprintf(DAT_30058294,DAT_30058298,DAT_300589a8);
      os_printf(DAT_300589ac,0);
    }
    iVar3 = 7;
  }
  else {
    if (iVar3 == 0) {
      param_1[0x17] = 1;
      *(undefined1 *)(iVar1 + 2) = 1;
    }
    *(undefined4 *)(iVar1 + 0x10) = DAT_30058ab4;
    *(undefined4 **)(iVar1 + 0x14) = param_1;
    iVar3 = core_send_data(*param_1,0,iVar1);
    if (iVar3 == 0) {
      return 0;
    }
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
      os_dprintf(DAT_30058294,DAT_30058298,DAT_30058ab8);
      os_printf(DAT_30058abc,0,iVar3);
    }
  }
  FUN_30057824(param_1,1,0xffffffff);
  param_1[0x17] = 0;
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_30057c70 @ 0x30057C70  (примерный размер ~220 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 5
 * Вызывает: cdc_get_iostatus, core_request_free, os_dprintf, os_printf, valid_type
 * Константы: 0x30057C70
 * Данные: DAT_30057f20, DAT_30058294, DAT_30058298, DAT_3005829c, DAT_30058ac0, DAT_30058bd4, DAT_30058bd8
 * ---------------------------------------------------------------- */
void FUN_30057c70(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_3005829c + 0xf0)) && (4 < *(int *)(DAT_3005829c + 0xf4))) {
    os_dprintf(DAT_30058294,DAT_30058298,DAT_30058ac0);
    os_printf(DAT_30057f20,0);
  }
  *(undefined4 *)(iVar1 + 0x58) = 0;
  iVar1 = cdc_get_iostatus(param_1,1);
  if ((((iVar1 != 0) && (iVar1 != 1)) && (valid_type(0x3d), 0 < *(int *)(DAT_3005829c + 0xf0))) &&
     (0 < *(int *)(DAT_3005829c + 0xf4))) {
    os_dprintf(DAT_30058294,DAT_30058298,DAT_30058bd4);
    os_printf(DAT_30058bd8,0,iVar1);
  }
  core_request_free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * uwd_cdc_send_encap_response @ 0x30057D4C  (примерный размер ~636 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 7
 * Вызывает: FUN_30057544, FUN_30057824, FUN_30059924, os_dprintf, os_memcpy, os_printf, valid_type
 * Константы: 0x30057D4C
 * Данные: DAT_30057f20, DAT_30058294, DAT_30058298, DAT_3005829c, DAT_300585bc, DAT_30058bdc, DAT_30058d08, DAT_30058d0c
 * ---------------------------------------------------------------- */
int uwd_cdc_send_encap_response(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_3005829c + 0xf0)) && (4 < *(int *)(DAT_3005829c + 0xf4))) {
    os_dprintf(DAT_30058294,DAT_30058298,DAT_30058bdc);
    os_printf(DAT_30057f20,0);
  }
  if ((param_2 == 0) || (*(uint *)(param_1 + 0xd0) < param_3)) {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
      os_dprintf(DAT_30058294,DAT_30058298,DAT_30058d08);
      os_printf(DAT_30058d0c,0,param_2,param_3);
    }
    return 10;
  }
  if ((*(int *)(param_1 + 100) != 0) && (*(int *)(param_1 + 0x54) != 0)) {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
      os_dprintf(DAT_30058294,DAT_30058298,DAT_30058d10);
      os_printf(DAT_30058d14,0,*(undefined4 *)(param_1 + 0x54));
    }
    return 8;
  }
  if (*(int *)(param_1 + 0x60) == 0) {
    uVar1 = FUN_30059924(*(undefined4 *)(param_1 + 0xd0),0,DAT_30058298,DAT_30058d18);
    *(undefined4 *)(param_1 + 0x60) = uVar1;
    if (*(int *)(param_1 + 0x60) == 0) {
      valid_type(0x3d);
      if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
        os_dprintf(DAT_30058294,DAT_30058298,DAT_30058d1c);
        os_printf(DAT_30058d20,0);
      }
      iVar2 = 7;
      goto LAB_30057fb0;
    }
  }
  os_memcpy(*(undefined4 *)(param_1 + 0x60),param_2,param_3);
  *(uint *)(param_1 + 100) = param_3;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x54) = 1;
  iVar2 = FUN_30057544(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  valid_type(0x3d);
  if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
    os_dprintf(DAT_30058294,DAT_30058298,DAT_30058e70);
    os_printf(DAT_300585bc,0,iVar2);
  }
LAB_30057fb0:
  FUN_30057824(param_1,0,0);
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_30057fc8 @ 0x30057FC8  (примерный размер ~432 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_30057354, core_request_free, core_send_data, os_dprintf, os_printf, uwe_str, valid_type
 * Вызывают: uwd_cdc_notify_flow_control, uwd_cdc_send_notification
 * Константы: 0x30057FC8
 * Данные: DAT_30058294, DAT_30058298, DAT_3005829c, DAT_30058e74, DAT_30058e78, DAT_30058f40, DAT_30058f44, DAT_30058f48
 * ---------------------------------------------------------------- */
int FUN_30057fc8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1[0xd] == 0) {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
      os_dprintf(DAT_30058294,DAT_30058298,DAT_30058e74);
      os_printf(DAT_30058e78,0);
    }
    iVar3 = 6;
  }
  else {
    iVar1 = FUN_30057354(param_1,param_2,param_3,*(undefined2 *)(param_1 + 0xe),param_4,param_5,1);
    if (iVar1 == 0) {
      valid_type(0x3d);
      if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
        os_dprintf(DAT_30058294,DAT_30058298,DAT_30058f40);
        os_printf(DAT_30058f44,0);
      }
      iVar3 = 7;
    }
    else {
      *(undefined4 *)(iVar1 + 0x10) = param_6;
      *(undefined4 **)(iVar1 + 0x14) = param_1;
      *(undefined4 *)(iVar1 + 0x28) = param_7;
      iVar3 = core_send_data(*param_1,param_1[0xd],iVar1);
      if (iVar3 != 0) {
        valid_type(0x3d);
        if ((0 < *(int *)(DAT_3005829c + 0xf0)) && (0 < *(int *)(DAT_3005829c + 0xf4))) {
          os_dprintf(DAT_30058294,DAT_30058298,DAT_30058f48);
          uVar2 = uwe_str(iVar3);
          os_printf(DAT_30058f4c,0,uVar2);
        }
        core_request_free(iVar1);
      }
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_30058178 @ 0x30058178  (примерный размер ~156 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 5
 * Вызывает: cdc_get_iostatus, core_request_free, os_dprintf, os_printf, valid_type
 * Константы: 0x30058178
 * Данные: DAT_30058294, DAT_30058298, DAT_3005829c, DAT_300590ac, DAT_300590b0
 * ---------------------------------------------------------------- */
void FUN_30058178(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_3005829c + 0xf0)) && (4 < *(int *)(DAT_3005829c + 0xf4))) {
    os_dprintf(DAT_30058294,DAT_30058298,DAT_300590ac);
    os_printf(DAT_300590b0,0);
  }
  if (*(int *)(iVar2 + 0x94) != 0) {
    uVar1 = cdc_get_iostatus(param_1,1);
    (**(code **)(iVar2 + 0x94))(uVar1,*(undefined4 *)(iVar2 + 4));
  }
  core_request_free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * uwd_cdc_notify_flow_control @ 0x30058214  (примерный размер ~252 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_30057fc8, os_dprintf, os_printf, valid_type
 * Константы: 0x30058214
 * Данные: DAT_30058294, DAT_30058298, DAT_3005829c, DAT_300590b4, DAT_300590b8, DAT_30059198, DAT_3005919c, DAT_300591a0
 * ---------------------------------------------------------------- */
void uwd_cdc_notify_flow_control(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = (uint)(param_2 != 0) | ((uint)(param_3 != 0) << 0x10) >> 0xf;
  valid_type(0x3d);
  if ((2 < *(int *)(DAT_3005829c + 0xf0)) && (2 < *(int *)(DAT_3005829c + 0xf4))) {
    os_dprintf(DAT_30058294,DAT_30058298,DAT_300590b4);
    uVar2 = DAT_30059198;
    if (param_2 != 0) {
      uVar2 = DAT_300590b8;
    }
    uVar3 = DAT_30059198;
    if (param_3 != 0) {
      uVar3 = DAT_300590b8;
    }
    os_printf(DAT_3005919c,0,uVar2,uVar3,uVar1);
  }
  FUN_30057fc8(param_1,1,uVar1,0,0,DAT_300591a0,0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30058310 @ 0x30058310  (примерный размер ~168 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 6
 * Вызывает: BSP_FreeDbg, cdc_get_iostatus, core_request_free, os_dprintf, os_printf, valid_type
 * Константы: 0x30058310
 * Данные: DAT_300590b0, DAT_300591a4, DAT_300591a8, DAT_300591ac, DAT_300591b0, DAT_300591b4
 * ---------------------------------------------------------------- */
void FUN_30058310(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x14);
  puVar2 = *(undefined4 **)(param_1 + 0x28);
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_300591a4 + 0xf0)) && (4 < *(int *)(DAT_300591a4 + 0xf4))) {
    os_dprintf(DAT_300591a8,DAT_300591ac,DAT_300591b0);
    os_printf(DAT_300590b0,0);
  }
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = cdc_get_iostatus(param_1,1);
    (*(code *)*puVar2)(uVar1,*(undefined4 *)(iVar3 + 4),puVar2[1]);
    BSP_FreeDbg(puVar2,DAT_300591ac,DAT_300591b4);
  }
  core_request_free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * uwd_cdc_send_notification @ 0x300583B8  (примерный размер ~424 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 7
 * Вызывает: BSP_FreeDbg, FUN_30057fc8, FUN_30059924, os_dprintf, os_printf, uwe_str, valid_type
 * Константы: 0x300583B8
 * Данные: DAT_300591a4, DAT_300591a8, DAT_300591ac, DAT_300592f4, DAT_300592f8, DAT_300592fc, DAT_30059300, DAT_30059304
 * ---------------------------------------------------------------- */
int uwd_cdc_send_notification
              (undefined4 param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,
              int param_6,int param_7)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  valid_type(0x3d);
  if ((2 < *(int *)(DAT_300591a4 + 0xf0)) && (2 < *(int *)(DAT_300591a4 + 0xf4))) {
    os_dprintf(DAT_300591a8,DAT_300591ac,DAT_300592f4);
    os_printf(DAT_300592f8,0,param_2 & 0xff,param_3 & 0xffff,param_4 & 0xffff);
  }
  if (param_6 != 0) {
    piVar3 = (int *)FUN_30059924(8,0,DAT_300591ac,DAT_300592fc);
    if (piVar3 == (int *)0x0) {
      valid_type(0x3d);
      if ((0 < *(int *)(DAT_300591a4 + 0xf0)) && (0 < *(int *)(DAT_300591a4 + 0xf4))) {
        os_dprintf(DAT_300591a8,DAT_300591ac,DAT_30059300);
        os_printf(DAT_30059304,0);
      }
      return 7;
    }
    *piVar3 = param_6;
    piVar3[1] = param_7;
  }
  iVar1 = FUN_30057fc8(param_1,param_2,param_3,param_4,param_5,DAT_30059308,piVar3);
  if (iVar1 != 0) {
    valid_type(0x3d);
    if ((0 < *(int *)(DAT_300591a4 + 0xf0)) && (0 < *(int *)(DAT_300591a4 + 0xf4))) {
      os_dprintf(DAT_300591a8,DAT_300591ac,DAT_30059400);
      uVar2 = uwe_str(iVar1);
      os_printf(DAT_30059404,0,uVar2);
    }
    if (piVar3 != (int *)0x0) {
      BSP_FreeDbg(piVar3,DAT_300591ac,DAT_30059408);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * cdc_free_descriptors @ 0x30058560  (примерный размер ~56 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 1
 * Вызывает: BSP_FreeDbg
 * Вызывают: cdc_init_acm, cdc_uninit
 * Константы: 0x30058560
 * Данные: DAT_300591ac, DAT_3005940c
 * ---------------------------------------------------------------- */
void cdc_free_descriptors(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    BSP_FreeDbg(*(undefined4 *)(param_1 + 0x20),DAT_300591ac,DAT_3005940c);
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30058598 @ 0x30058598  (примерный размер ~1080 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300564e4, FUN_30059924
 * Вызывают: cdc_alloc_descriptors
 * Константы: 0x30058598
 * Данные: DAT_300591ac, DAT_30059510
 * ---------------------------------------------------------------- */
undefined4 FUN_30058598(int param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char cVar7;
  int iVar8;
  bool bVar9;
  char local_40;
  int local_34;
  undefined4 local_2c;
  
  local_34 = 0;
  iVar8 = param_2[4];
  bVar9 = iVar8 == 0;
  if (bVar9) {
    iVar8 = 0;
  }
  cVar7 = (char)iVar8;
  if (!bVar9) {
    cVar7 = '\x01';
  }
  bVar1 = cVar7 + 1;
  local_2c = 7;
  iVar8 = (uint)bVar1 * 0x10 + 0x2c;
  if (param_2[6] != 0) {
    local_34 = (*(code *)param_2[6])(param_1,0,1);
    iVar8 = iVar8 + local_34;
  }
  if (param_2[2] != 0) {
    iVar8 = iVar8 + 0x3c;
  }
  if (param_2[3] != 0) {
    iVar8 = iVar8 + 0x78;
  }
  puVar3 = (undefined4 *)FUN_30059924(iVar8,1,DAT_300591ac,DAT_30059510);
  if (puVar3 != (undefined4 *)0x0) {
    pcVar5 = (char *)(puVar3 + 5);
    local_40 = param_2[2] != 0;
    if ((bool)local_40) {
      pcVar5[0] = '@';
      pcVar5[1] = '\0';
      *(undefined2 *)((int)puVar3 + 0x16) = 0x40;
      puVar3[6] = 3;
      *(undefined1 *)(puVar3 + 7) = 0;
      *(undefined1 *)((int)puVar3 + 0x1d) = 0;
      *(undefined1 *)((int)puVar3 + 0x1e) = 0;
      *(undefined1 *)((int)puVar3 + 0x1f) = 0;
      *(undefined1 *)(puVar3 + 8) = 0;
      *(undefined1 *)((int)puVar3 + 0x21) = 5;
      *(undefined1 *)((int)puVar3 + 0x22) = 1;
    }
    pcVar6 = pcVar5;
    if (param_2[3] != 0) {
      pcVar4 = pcVar5 + (uint)(byte)local_40 * 0x3c;
      pcVar6 = pcVar4 + 0x78;
      uVar2 = FUN_300564e4(param_1,3);
      *(undefined2 *)pcVar4 = uVar2;
      uVar2 = FUN_300564e4(param_1,2);
      *(undefined2 *)(pcVar4 + 2) = uVar2;
      pcVar4[4] = '\x02';
      pcVar4[5] = '\0';
      pcVar4[6] = '\0';
      pcVar4[7] = '\0';
      pcVar4[8] = '\0';
      pcVar4[9] = '\0';
      pcVar4[10] = '\0';
      pcVar4[0xb] = '\0';
      pcVar4[0xc] = '\0';
      pcVar4[0xd] = ' ';
      pcVar4[0xe] = '\x01';
      *(undefined2 *)(pcVar4 + 0x30) = *(undefined2 *)(param_2 + 8);
      uVar2 = FUN_300564e4(param_1,3);
      *(undefined2 *)(pcVar4 + 0x3c) = uVar2;
      uVar2 = FUN_300564e4(param_1,2);
      *(undefined2 *)(pcVar4 + 0x3e) = uVar2;
      pcVar4[0x40] = '\x02';
      pcVar4[0x41] = '\0';
      pcVar4[0x42] = '\0';
      pcVar4[0x43] = '\0';
      pcVar4[0x44] = '\x01';
      pcVar4[0x45] = '\0';
      pcVar4[0x46] = '\0';
      pcVar4[0x47] = '\0';
      pcVar4[0x48] = '\0';
      pcVar4[0x49] = ' ';
      pcVar4[0x4a] = '\x01';
      *(undefined2 *)(pcVar4 + 0x6c) = *(undefined2 *)(param_2 + 8);
      local_40 = local_40 + '\x02';
    }
    pcVar4 = pcVar6 + (uint)bVar1 * 0x10;
    if (param_2[4] == 0) {
      *pcVar6 = local_40;
      *(char **)(pcVar6 + 4) = pcVar5;
    }
    else {
      if (param_2[2] == 0) {
        *pcVar6 = '\0';
        pcVar6[4] = '\0';
        pcVar6[5] = '\0';
        pcVar6[6] = '\0';
        pcVar6[7] = '\0';
      }
      else {
        *pcVar6 = '\x01';
        *(char **)(pcVar6 + 4) = pcVar5;
      }
      pcVar6[0x10] = local_40;
      *(char **)(pcVar6 + 0x14) = pcVar5;
    }
    *(undefined4 *)pcVar4 = *param_2;
    *(char **)(pcVar4 + 4) = pcVar6;
    pcVar4[8] = bVar1;
    pcVar4[9] = '\0';
    pcVar4[0xc] = '\0';
    pcVar4[0xd] = '\0';
    pcVar4[0xe] = '\0';
    pcVar4[0xf] = '\0';
    pcVar4[0x10] = '\0';
    pcVar4[0x11] = '\0';
    pcVar4[0x12] = '\0';
    if (*(char *)((int)param_2 + 6) == '\0') {
      pcVar4[0x13] = -1;
      pcVar4[0x14] = -1;
      pcVar4[0x15] = -1;
    }
    else {
      pcVar4[0x13] = *(char *)((int)param_2 + 5);
      pcVar4[0x14] = *(char *)((int)param_2 + 6);
      pcVar4[0x15] = *(char *)((int)param_2 + 7);
    }
    if (param_2[6] != 0) {
      (*(code *)param_2[6])(param_1,pcVar4 + 0x18,1);
      *(char **)(pcVar4 + 0xc) = pcVar4 + 0x18;
      *(short *)(pcVar4 + 0x10) = (short)local_34;
    }
    *puVar3 = 3;
    *(undefined1 *)(puVar3 + 2) = 1;
    puVar3[3] = pcVar4;
    puVar3[4] = 0;
    *(undefined4 **)(param_1 + 0x20) = puVar3;
    local_2c = 0;
  }
  return local_2c;
}

/* ----------------------------------------------------------------
 * FUN_300589d0 @ 0x300589D0  (примерный размер ~1352 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300564e4, FUN_30059924, core_get_available_iface
 * Вызывают: cdc_alloc_descriptors
 * Константы: 0x300589D0, 0x30058EF4
 * Данные: DAT_300591ac, DAT_30059920
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x30058ef4) */

undefined4 FUN_300589d0(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  char cVar10;
  int iVar11;
  bool bVar12;
  undefined4 *local_38;
  int local_34;
  int local_2c;
  
  puVar7 = (undefined4 *)0x0;
  local_2c = 0;
  iVar11 = param_2[4];
  bVar12 = iVar11 == 0;
  if (bVar12) {
    iVar11 = 0;
  }
  cVar10 = (char)iVar11;
  if (!bVar12) {
    cVar10 = '\x01';
  }
  bVar1 = cVar10 + 1;
  local_34 = 0x3c;
  if (param_2[6] != 0) {
    local_2c = (*(code *)param_2[6])(param_1,0,0);
    local_34 = local_2c + 0x3c;
  }
  if (param_2[2] != 0) {
    local_34 = local_34 + 0x3c;
  }
  if (param_2[3] != 0) {
    local_34 = local_34 + (uint)bVar1 * 0x10 + 0x98;
  }
  puVar4 = (undefined4 *)FUN_30059924(local_34,1,DAT_300591ac,DAT_30059920);
  if (puVar4 == (undefined4 *)0x0) {
    uVar5 = 7;
  }
  else {
    puVar8 = puVar4 + 5;
    puVar6 = (undefined4 *)0x0;
    local_38 = puVar8;
    if (param_2[3] != 0) {
      local_38 = puVar4 + 7;
      *(undefined1 *)puVar8 = 8;
      *(undefined1 *)((int)puVar4 + 0x15) = 0xb;
      uVar2 = core_get_available_iface(*param_1);
      *(undefined1 *)((int)puVar4 + 0x16) = uVar2;
      *(undefined1 *)((int)puVar4 + 0x17) = 2;
      *(undefined1 *)(puVar4 + 6) = 2;
      *(undefined1 *)((int)puVar4 + 0x19) = *(undefined1 *)(param_2 + 1);
      *(undefined1 *)((int)puVar4 + 0x1a) = 0;
      *(undefined1 *)((int)puVar4 + 0x1b) = 0;
      puVar6 = puVar8;
    }
    if (param_2[2] == 0) {
      *(undefined1 *)local_38 = 0;
      local_38[1] = 0;
    }
    else {
      *(undefined2 *)local_38 = 0x40;
      *(undefined2 *)((int)local_38 + 2) = 0x40;
      local_38[1] = 3;
      *(undefined1 *)(local_38 + 2) = 0;
      *(undefined1 *)((int)local_38 + 9) = 0;
      *(undefined1 *)((int)local_38 + 10) = 0;
      *(undefined1 *)((int)local_38 + 0xb) = 0;
      *(undefined1 *)(local_38 + 3) = 0;
      *(undefined1 *)((int)local_38 + 0xd) = 5;
      *(undefined1 *)((int)local_38 + 0xe) = 1;
      *(undefined1 *)(local_38 + 0xf) = 1;
      local_38[0x10] = local_38;
      local_38 = local_38 + 0xf;
    }
    puVar9 = local_38 + 4;
    puVar8 = puVar9;
    if (param_2[3] != 0) {
      puVar7 = local_38 + 0x22;
      uVar3 = FUN_300564e4(param_1,3);
      *(undefined2 *)puVar9 = uVar3;
      uVar3 = FUN_300564e4(param_1,2);
      *(undefined2 *)((int)local_38 + 0x12) = uVar3;
      local_38[5] = 2;
      *(undefined1 *)(local_38 + 6) = 0;
      *(undefined1 *)((int)local_38 + 0x19) = 0;
      *(undefined1 *)((int)local_38 + 0x1a) = 0;
      *(undefined1 *)((int)local_38 + 0x1b) = 0;
      *(undefined1 *)(local_38 + 7) = 0;
      *(undefined1 *)((int)local_38 + 0x1d) = 0x20;
      *(undefined1 *)((int)local_38 + 0x1e) = 1;
      *(undefined2 *)(local_38 + 0x10) = *(undefined2 *)(param_2 + 8);
      uVar3 = FUN_300564e4(param_1,3);
      *(undefined2 *)(local_38 + 0x13) = uVar3;
      uVar3 = FUN_300564e4(param_1,2);
      *(undefined2 *)((int)local_38 + 0x4e) = uVar3;
      local_38[0x14] = 2;
      *(undefined1 *)(local_38 + 0x15) = 1;
      *(undefined1 *)((int)local_38 + 0x55) = 0;
      *(undefined1 *)((int)local_38 + 0x56) = 0;
      *(undefined1 *)((int)local_38 + 0x57) = 0;
      *(undefined1 *)(local_38 + 0x16) = 0;
      *(undefined1 *)((int)local_38 + 0x59) = 0x20;
      *(undefined1 *)((int)local_38 + 0x5a) = 1;
      *(undefined2 *)(local_38 + 0x1f) = *(undefined2 *)(param_2 + 8);
      puVar8 = puVar7 + (uint)bVar1 * 4;
      if (param_2[4] == 0) {
        *(undefined1 *)puVar7 = 2;
        local_38[0x23] = puVar9;
      }
      else {
        *(undefined1 *)puVar7 = 0;
        local_38[0x23] = 0;
        *(undefined1 *)(local_38 + 0x26) = 2;
        local_38[0x27] = puVar9;
      }
    }
    if (param_2[3] == 0) {
      puVar9 = puVar8 + 6;
    }
    else {
      puVar9 = puVar8 + 0xc;
    }
    *puVar8 = *param_2;
    puVar8[1] = local_38;
    *(undefined1 *)(puVar8 + 2) = 1;
    *(undefined1 *)((int)puVar8 + 9) = 0;
    puVar8[3] = 0;
    *(undefined2 *)(puVar8 + 4) = 0;
    *(undefined1 *)((int)puVar8 + 0x12) = 0;
    if (*(char *)((int)param_2 + 6) == '\0') {
      *(undefined1 *)((int)puVar8 + 0x13) = 0xff;
      *(undefined1 *)(puVar8 + 5) = 0xff;
      *(undefined1 *)((int)puVar8 + 0x15) = 0xff;
    }
    else {
      *(undefined1 *)((int)puVar8 + 0x13) = *(undefined1 *)((int)param_2 + 5);
      *(undefined1 *)(puVar8 + 5) = *(undefined1 *)((int)param_2 + 6);
      *(undefined1 *)((int)puVar8 + 0x15) = *(undefined1 *)((int)param_2 + 7);
    }
    if (param_2[3] != 0) {
      puVar8[6] = *param_2;
      puVar8[7] = puVar7;
      *(byte *)(puVar8 + 8) = bVar1;
      *(undefined1 *)((int)puVar8 + 0x21) = 0;
      puVar8[9] = 0;
      *(undefined2 *)(puVar8 + 10) = 0;
      *(undefined1 *)((int)puVar8 + 0x2a) = 0;
      *(undefined1 *)((int)puVar8 + 0x2b) = 10;
      *(undefined1 *)(puVar8 + 0xb) = 0;
      *(undefined1 *)((int)puVar8 + 0x2d) = *(undefined1 *)(param_2 + 5);
    }
    if (param_2[6] != 0) {
      (*(code *)param_2[6])(param_1,puVar9,0);
      puVar8[3] = puVar9;
      *(short *)(puVar8 + 4) = (short)local_2c;
    }
    *puVar4 = 3;
    iVar11 = param_2[3];
    bVar12 = iVar11 == 0;
    if (bVar12) {
      iVar11 = 0;
    }
    cVar10 = (char)iVar11;
    if (!bVar12) {
      cVar10 = '\x01';
    }
    *(char *)(puVar4 + 2) = cVar10 + '\x01';
    puVar4[3] = puVar8;
    if (param_2[3] == 0) {
      puVar4[4] = 0;
    }
    else {
      puVar4[4] = puVar6;
    }
    param_1[8] = puVar4;
    uVar5 = 0;
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * cdc_alloc_descriptors @ 0x30058F18  (примерный размер ~112 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30058598, FUN_300589d0
 * Константы: 0x30058F18
 * ---------------------------------------------------------------- */
undefined4 cdc_alloc_descriptors(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x20) != 0)) {
    uVar1 = 10;
  }
  else if (*(int *)(param_2 + 0x1c) == 0) {
    uVar1 = FUN_300589d0(param_1,param_2);
  }
  else {
    uVar1 = FUN_30058598(param_1,param_2);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30058f88 @ 0x30058F88  (примерный размер ~84 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 1
 * Вызывает: core_abort_pipe
 * Вызывают: FUN_30059600, cdc_disable
 * Константы: 0x30058F88
 * ---------------------------------------------------------------- */
void FUN_30058f88(undefined4 *param_1)

{
  if (param_1[0xd] != 0) {
    core_abort_pipe(*param_1,param_1[0xd]);
  }
  if (param_1[9] != 0) {
    core_abort_pipe(*param_1,param_1[9]);
  }
  if (param_1[0xb] != 0) {
    core_abort_pipe(*param_1,param_1[0xb]);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30058fdc @ 0x30058FDC  (примерный размер ~88 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Константы: 0x30058FDC
 * Данные: DAT_300591a4, DAT_300591a8, DAT_300591ac, DAT_3005997c, DAT_30059980
 * ---------------------------------------------------------------- */
undefined4 FUN_30058fdc(int param_1)

{
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_300591a4 + 0xf0)) && (4 < *(int *)(DAT_300591a4 + 0xf4))) {
    os_dprintf(DAT_300591a8,DAT_300591ac,DAT_3005997c);
    os_printf(DAT_30059980,*(undefined4 *)(param_1 + 0x20));
  }
  return *(undefined4 *)(param_1 + 0x20);
}

/* ----------------------------------------------------------------
 * cdc_enable @ 0x30059034  (примерный размер ~960 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300564e4, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_300593f4
 * Константы: 0x30059034
 * Данные: DAT_300591a4, DAT_300591a8, DAT_300591ac, DAT_30059984, DAT_30059988, DAT_3005998c, DAT_30059990, DAT_30059994
 * ---------------------------------------------------------------- */
undefined4 cdc_enable(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_300591a4 + 0xf0)) && (4 < *(int *)(DAT_300591a4 + 0xf4))) {
    os_dprintf(DAT_300591a8,DAT_300591ac,0x710);
    os_printf(DAT_30059984);
  }
  if ((param_1 == 0) || (*(int *)(param_1 + 0x20) == 0)) {
    uVar2 = 10;
  }
  else {
    bVar6 = (*(ushort *)(param_1 + 0xcc) & 1) == 0;
    uVar3 = (uint)!bVar6;
    if (*(char *)(*(int *)(param_1 + 0x20) + 8) != '\0') {
      uVar4 = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x20) + 0xc) + 9);
      iVar5 = *(int *)(*(int *)(param_1 + 0x20) + 0xc);
      valid_type(0x3d);
      if ((4 < *(int *)(DAT_300591a4 + 0xf0)) && (4 < *(int *)(DAT_300591a4 + 0xf4))) {
        os_dprintf(DAT_300591a8,DAT_300591ac,DAT_30059988);
        os_printf(DAT_3005998c,*(undefined1 *)(iVar5 + 0x12),uVar4);
      }
      *(ushort *)(param_1 + 0x38) = (ushort)*(byte *)(iVar5 + 0x12);
      if (((bVar6) || (*(int *)(*(int *)(iVar5 + 4) + uVar4 * 0x10 + 4) == 0)) ||
         (*(int *)(*(int *)(*(int *)(iVar5 + 4) + uVar4 * 0x10 + 4) + 4) == 3)) {
        *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(*(int *)(iVar5 + 4) + uVar4 * 0x10 + 4);
      }
      else {
        *(undefined4 *)(param_1 + 0x34) = 0;
        uVar3 = 0;
      }
    }
    if ((1 < *(byte *)(*(int *)(param_1 + 0x20) + 8)) || (!bVar6)) {
      uVar4 = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x20) + 0xc) + (uint)bVar6 * 0x18 + 9);
      iVar5 = *(int *)(*(int *)(param_1 + 0x20) + 0xc) + (uint)bVar6 * 0x18;
      valid_type(0x3d);
      if ((4 < *(int *)(DAT_30059990 + 0xf0)) && (4 < *(int *)(DAT_30059990 + 0xf4))) {
        os_dprintf(DAT_30059994,DAT_30059998,DAT_3005999c);
        os_printf(DAT_3005998c,*(undefined1 *)(iVar5 + 0x12),uVar4);
      }
      if (*(char *)(*(int *)(iVar5 + 4) + uVar4 * 0x10) != '\0') {
        *(ushort *)(param_1 + 0x28) = (ushort)*(byte *)(iVar5 + 0x12);
        *(uint *)(param_1 + 0x24) = *(int *)(*(int *)(iVar5 + 4) + uVar4 * 0x10 + 4) + uVar3 * 0x3c;
        valid_type(0x3d);
        if ((4 < *(int *)(DAT_30059990 + 0xf0)) && (4 < *(int *)(DAT_30059990 + 0xf4))) {
          os_dprintf(DAT_30059994,DAT_30059998,DAT_300599a0);
          os_printf(DAT_300599a4,*(undefined1 *)(iVar5 + 0x12),uVar4,
                    *(undefined1 *)(*(int *)(param_1 + 0x24) + 0xb),*(undefined4 *)(param_1 + 0x24))
          ;
        }
      }
      if (1 < *(byte *)(*(int *)(iVar5 + 4) + uVar4 * 0x10)) {
        *(ushort *)(param_1 + 0x30) = (ushort)*(byte *)(iVar5 + 0x12);
        *(uint *)(param_1 + 0x2c) =
             *(int *)(*(int *)(iVar5 + 4) + uVar4 * 0x10 + 4) + uVar3 * 0x3c + 0x3c;
        valid_type(0x3d);
        if ((4 < *(int *)(DAT_30059990 + 0xf0)) && (4 < *(int *)(DAT_30059990 + 0xf4))) {
          os_dprintf(DAT_30059994,DAT_30059998,DAT_300599a8);
          os_printf(DAT_300599ac,*(undefined1 *)(iVar5 + 0x12),uVar4,
                    *(undefined1 *)(*(int *)(param_1 + 0x2c) + 0xb),*(undefined4 *)(param_1 + 0x2c))
          ;
        }
      }
    }
    uVar1 = FUN_300564e4(param_1,*(undefined4 *)(*(int *)(param_1 + 0x20) + 4));
    *(undefined2 *)(param_1 + 0x46) = uVar1;
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300593f4 @ 0x300593F4  (примерный размер ~208 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: cdc_enable, os_dprintf, os_printf, valid_type
 * Константы: 0x300593F4
 * Данные: DAT_30059990, DAT_30059994, DAT_30059998, DAT_300599b0
 * ---------------------------------------------------------------- */
int FUN_300593f4(int param_1)

{
  int iVar1;
  
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_30059990 + 0xf0)) && (4 < *(int *)(DAT_30059990 + 0xf4))) {
    os_dprintf(DAT_30059994,DAT_30059998,0x760);
    os_printf(DAT_300599b0);
  }
  if (param_1 == 0) {
    iVar1 = 10;
  }
  else {
    iVar1 = cdc_enable(param_1);
    if (((iVar1 == 0) && (*(int *)(param_1 + 0x78) != 0)) &&
       (iVar1 = (**(code **)(param_1 + 0x78))(*(undefined4 *)(param_1 + 4)), iVar1 == 0)) {
      *(undefined1 *)(param_1 + 0x44) = 1;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * cdc_disable @ 0x300594C4  (примерный размер ~164 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_30057824, FUN_30058f88, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30059568
 * Константы: 0x300594C4
 * Данные: DAT_30059990, DAT_30059994, DAT_30059998, DAT_300599b4, DAT_300599b8
 * ---------------------------------------------------------------- */
void cdc_disable(int param_1)

{
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_30059990 + 0xf0)) && (4 < *(int *)(DAT_30059990 + 0xf4))) {
    os_dprintf(DAT_30059994,DAT_30059998,DAT_300599b4);
    os_printf(DAT_300599b8);
  }
  FUN_30057824(param_1,1,1);
  FUN_30058f88(param_1);
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined2 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined2 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined2 *)(param_1 + 0x30) = 0;
  *(undefined2 *)(param_1 + 0x46) = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30059568 @ 0x30059568  (примерный размер ~152 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: cdc_disable, os_dprintf, os_printf, valid_type
 * Константы: 0x30059568
 * Данные: DAT_30059990, DAT_30059994, DAT_30059998, DAT_300599bc, DAT_300599c0
 * ---------------------------------------------------------------- */
void FUN_30059568(int param_1)

{
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_30059990 + 0xf0)) && (4 < *(int *)(DAT_30059990 + 0xf4))) {
    os_dprintf(DAT_30059994,DAT_30059998,DAT_300599bc);
    os_printf(DAT_300599c0);
  }
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0x7c) != 0) && (*(char *)(param_1 + 0x44) != '\0')) {
      *(undefined1 *)(param_1 + 0x44) = 0;
      (**(code **)(param_1 + 0x7c))(*(undefined4 *)(param_1 + 4));
    }
    cdc_disable(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30059600 @ 0x30059600  (примерный размер ~152 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_30057824, FUN_30058f88, os_dprintf, os_printf, valid_type
 * Константы: 0x30059600
 * Данные: DAT_30059990, DAT_30059994, DAT_30059998, DAT_300599c4, DAT_300599c8
 * ---------------------------------------------------------------- */
undefined4 FUN_30059600(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  valid_type(0x3d);
  if ((2 < *(int *)(DAT_30059990 + 0xf0)) && (2 < *(int *)(DAT_30059990 + 0xf4))) {
    os_dprintf(DAT_30059994,DAT_30059998,DAT_300599c4);
    os_printf(DAT_300599c8);
  }
  if (*(int *)(param_1 + 0x84) != 0) {
    uVar1 = (**(code **)(param_1 + 0x84))(*(undefined4 *)(param_1 + 4));
  }
  FUN_30057824(param_1,1,1);
  FUN_30058f88(param_1);
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30059698 @ 0x30059698  (примерный размер ~128 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Константы: 0x30059698
 * Данные: DAT_30059990, DAT_30059994, DAT_30059998, DAT_300599cc, DAT_300599d0
 * ---------------------------------------------------------------- */
undefined4 FUN_30059698(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  valid_type(0x3d);
  if ((2 < *(int *)(DAT_30059990 + 0xf0)) && (2 < *(int *)(DAT_30059990 + 0xf4))) {
    os_dprintf(DAT_30059994,DAT_30059998,DAT_300599cc);
    os_printf(DAT_300599d0);
  }
  if (*(int *)(param_1 + 0x88) != 0) {
    uVar1 = (**(code **)(param_1 + 0x88))(*(undefined4 *)(param_1 + 4));
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cdc_uninit @ 0x30059718  (примерный размер ~228 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 6
 * Вызывает: BSP_FreeDbg, cdc_free_descriptors, core_request_free, os_dprintf, os_printf, valid_type
 * Константы: 0x30059718
 * Данные: DAT_30059990, DAT_30059994, DAT_30059998, DAT_300599d4, DAT_300599d8, DAT_300599dc
 * ---------------------------------------------------------------- */
undefined4 cdc_uninit(int param_1)

{
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_30059990 + 0xf0)) && (4 < *(int *)(DAT_30059990 + 0xf4))) {
    os_dprintf(DAT_30059994,DAT_30059998,DAT_300599d4);
    os_printf(DAT_300599d8);
  }
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x80) != 0) {
      (**(code **)(param_1 + 0x80))(*(undefined4 *)(param_1 + 4));
    }
    if (*(int *)(param_1 + 0x3c) != 0) {
      core_request_free(*(undefined4 *)(param_1 + 0x3c));
    }
    if (*(int *)(param_1 + 0x40) != 0) {
      core_request_free(*(undefined4 *)(param_1 + 0x40));
    }
    if (*(int *)(param_1 + 0x60) != 0) {
      BSP_FreeDbg(*(undefined4 *)(param_1 + 0x60),DAT_30059998,DAT_300599dc);
    }
    cdc_free_descriptors(param_1);
    BSP_FreeDbg(param_1,DAT_30059998,0x800);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * cdc_init @ 0x300597FC  (примерный размер ~296 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: core_register_fd, os_dprintf, os_printf, valid_type
 * Константы: 0x300597FC
 * Данные: DAT_30059990, DAT_30059994, DAT_30059998, DAT_300599e0, DAT_300599e4, DAT_300599e8, DAT_300599ec, DAT_300599f0
 * ---------------------------------------------------------------- */
undefined4 cdc_init(undefined4 *param_1)

{
  undefined4 uVar1;
  
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_30059990 + 0xf0)) && (4 < *(int *)(DAT_30059990 + 0xf4))) {
    os_dprintf(DAT_30059994,DAT_30059998,DAT_300599e0);
    os_printf(DAT_300599e4);
  }
  if (param_1[2] == 0) {
    param_1[2] = DAT_300599e8;
  }
  if (param_1[3] == 0) {
    param_1[3] = DAT_300599ec;
  }
  if (param_1[4] == 0) {
    param_1[4] = DAT_300599f0;
  }
  if (param_1[5] == 0) {
    param_1[5] = DAT_300599f4;
  }
  if (param_1[6] == 0) {
    param_1[6] = DAT_300599f8;
  }
  if (param_1[7] == 0) {
    param_1[7] = DAT_300599fc;
  }
  valid_type(0x3d);
  if ((4 < *(int *)(DAT_30059990 + 0xf0)) && (4 < *(int *)(DAT_30059990 + 0xf4))) {
    os_dprintf(DAT_30059994,DAT_30059998,DAT_30059a00);
    os_printf(DAT_30059a04);
  }
  uVar1 = core_register_fd(*param_1,param_1 + 2,param_1);
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30059924 @ 0x30059924  (примерный размер ~228 байт)
 * Модуль: usb | Вызывают: 4 | Вызывает: 2
 * Вызывает: BSP_MallocDbg, memset
 * Вызывают: FUN_30058598, FUN_300589d0, uwd_cdc_send_encap_response, uwd_cdc_send_notification
 * Константы: 0x30059924
 * ---------------------------------------------------------------- */
void * FUN_30059924(size_t param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)BSP_MallocDbg(param_1,0,param_3,param_4);
  if ((param_2 == 1) && (__s != (void *)0x0)) {
    memset(__s,0,param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * usb_enum_notify_usr @ 0x3005B91C  (примерный размер ~152 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 4
 * Вызывает: jos_critical_enter_d, jos_critical_leave_d, jos_safe_enter_d, jos_safe_leave_d
 * Вызывают: os_notify
 * Константы: 0x3005B91C
 * Данные: DAT_3005bf0c, DAT_3005bf44, DAT_3005bf48, DAT_3005bf4c, DAT_3005bf50, DAT_3005bf54, DAT_3005bf58
 * ---------------------------------------------------------------- */
void usb_enum_notify_usr(void)

{
  code *pcVar1;
  code *pcVar2;
  
  jos_critical_enter_d(DAT_3005bf0c,DAT_3005bf44);
  pcVar2 = (code *)*DAT_3005bf48;
  pcVar1 = (code *)*DAT_3005bf4c;
  jos_critical_leave_d(DAT_3005bf0c,300);
  if (pcVar1 != (code *)0x0) {
    jos_safe_leave_d(DAT_3005bf0c,0x130);
    (*pcVar1)();
    jos_safe_enter_d(DAT_3005bf0c,DAT_3005bf50);
  }
  if (pcVar2 != (code *)0x0) {
    jos_safe_leave_d(DAT_3005bf0c,DAT_3005bf54);
    (*pcVar2)();
    jos_safe_enter_d(DAT_3005bf0c,DAT_3005bf58);
  }
  return;
}

/* ----------------------------------------------------------------
 * jusb_entry @ 0x3005BFA0  (примерный размер ~132 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 5
 * Вызывает: get_uw_args, jstart_stack, os_dprintf, os_printf, valid_type
 * Константы: 0x3005BFA0
 * Данные: DAT_3005c0cc, DAT_3005c0d0, DAT_3005c0d4, DAT_3005c0d8, DAT_3005c0dc
 * ---------------------------------------------------------------- */
undefined4 jusb_entry(int param_1)

{
  undefined4 uVar1;
  
  *DAT_3005c0cc = 1;
  if (param_1 == 0) {
    get_uw_args();
    uVar1 = jstart_stack();
  }
  else {
    uVar1 = jstart_stack(param_1);
  }
  valid_type(7);
  if ((2 < *DAT_3005c0d0) && (2 < DAT_3005c0d0[7])) {
    os_dprintf(DAT_3005c0d4,DAT_3005c0d8,0x34);
    os_printf(DAT_3005c0dc,uVar1);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * jusb_exit @ 0x3005C024  (примерный размер ~80 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 5
 * Вызывает: jstop_stack, os_dprintf, os_printf, os_sync_uninit, valid_type
 * Константы: 0x3005C024
 * Данные: DAT_3005c0d0, DAT_3005c0d4, DAT_3005c0d8, DAT_3005c0e0
 * ---------------------------------------------------------------- */
void jusb_exit(void)

{
  jstop_stack();
  os_sync_uninit();
  valid_type(7);
  if ((2 < *DAT_3005c0d0) && (2 < DAT_3005c0d0[7])) {
    os_dprintf(DAT_3005c0d4,DAT_3005c0d8,0x3e);
    os_printf(DAT_3005c0e0);
  }
  return;
}

/* ----------------------------------------------------------------
 * acm_handle_request @ 0x3005E9EC  (примерный размер ~452 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 12
 * Вызывает: FUN_3005d890, FUN_3005db28, FUN_3005dda4, FUN_3005e140, FUN_3005e3c4, FUN_3005e688, FUN_3005e844, cdc_handle_encapsulated_command, cdc_handle_encapsulated_response, os_dprintf, os_printf, valid_type
 * Константы: 0x3005E9EC
 * Данные: DAT_3005f154, DAT_3005f158, DAT_3005f15c, DAT_3005f180, DAT_3005f184, DAT_3005f188, DAT_3005f18c
 * ---------------------------------------------------------------- */
undefined4 acm_handle_request(int param_1,int param_2,undefined1 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005f154 + 0xf0)) && (4 < *(int *)(DAT_3005f154 + 0xf8))) {
    os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f180);
    os_printf(DAT_3005f184,*(undefined1 *)(param_2 + 1));
  }
  *(undefined1 *)(param_1 + 0x50) = param_3;
  bVar1 = *(byte *)(param_2 + 1);
  if (bVar1 == 4) {
    uVar2 = FUN_3005dda4(param_1,param_2);
    return uVar2;
  }
  if (bVar1 < 5) {
    if (bVar1 == 0) {
      uVar2 = cdc_handle_encapsulated_command(param_1,param_2);
      return uVar2;
    }
    if (bVar1 == 1) {
      uVar2 = cdc_handle_encapsulated_response(param_1,param_2);
      return uVar2;
    }
    if (bVar1 == 2) {
      uVar2 = FUN_3005d890(param_1,param_2);
      return uVar2;
    }
    if (bVar1 == 3) {
      uVar2 = FUN_3005db28(param_1,param_2);
      return uVar2;
    }
  }
  else {
    if (bVar1 == 0x20) {
      uVar2 = FUN_3005e140(param_1,param_2);
      return uVar2;
    }
    if (bVar1 == 0x21) {
      uVar2 = FUN_3005e3c4(param_1,param_2);
      return uVar2;
    }
    if (bVar1 == 0x22) {
      uVar2 = FUN_3005e688(param_1,param_2);
      return uVar2;
    }
    if (bVar1 == 0x23) {
      uVar2 = FUN_3005e844(param_1,param_2);
      return uVar2;
    }
  }
  valid_type(0x3e);
  if ((0 < *(int *)(DAT_3005f154 + 0xf0)) && (0 < *(int *)(DAT_3005f154 + 0xf8))) {
    os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f188);
    os_printf(DAT_3005f18c,*(undefined1 *)(param_2 + 1));
  }
  return 0xb;
}

/* ----------------------------------------------------------------
 * FUN_3005ebb0 @ 0x3005EBB0  (примерный размер ~156 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 5
 * Вызывает: cdc_get_iostatus, core_request_free, os_dprintf, os_printf, valid_type
 * Константы: 0x3005EBB0
 * Данные: DAT_3005f154, DAT_3005f158, DAT_3005f15c, DAT_3005f190, DAT_3005f194
 * ---------------------------------------------------------------- */
void FUN_3005ebb0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005f154 + 0xf0)) && (4 < *(int *)(DAT_3005f154 + 0xf8))) {
    os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f190);
    os_printf(DAT_3005f194);
  }
  if (*(int *)(iVar2 + 200) != 0) {
    uVar1 = cdc_get_iostatus(param_1,1);
    (**(code **)(iVar2 + 200))(uVar1,*(undefined4 *)(iVar2 + 4));
  }
  core_request_free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * uwd_acm_notify_serial_state @ 0x3005EC4C  (примерный размер ~192 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 2
 * Вызывает: cdc_create_notification, core_send_data
 * Константы: 0x3005EC4C
 * Данные: DAT_3005f198
 * ---------------------------------------------------------------- */
undefined4 uwd_acm_notify_serial_state(undefined4 *param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_4 [2];
  
  if (param_1[0xd] == 0) {
    uVar2 = 6;
  }
  else if ((*(ushort *)(param_1 + 0x38) & 2) == 0) {
    uVar2 = 0xb;
  }
  else {
    local_4[0] = param_2;
    iVar1 = cdc_create_notification(param_1,0x20,0,*(undefined2 *)(param_1 + 0xe),2,local_4);
    if (iVar1 == 0) {
      uVar2 = 7;
    }
    else {
      *(undefined4 *)(iVar1 + 0x10) = DAT_3005f198;
      *(undefined4 **)(iVar1 + 0x14) = param_1;
      uVar2 = core_send_data(*param_1,param_1[0xd],iVar1);
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3005ed0c @ 0x3005ED0C  (примерный размер ~164 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 5
 * Вызывает: cdc_get_iostatus, core_request_free, os_dprintf, os_printf, valid_type
 * Константы: 0x3005ED0C
 * Данные: DAT_3005f154, DAT_3005f158, DAT_3005f15c, DAT_3005f19c, DAT_3005f1a0
 * ---------------------------------------------------------------- */
void FUN_3005ed0c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005f154 + 0xf0)) && (4 < *(int *)(DAT_3005f154 + 0xf8))) {
    os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f19c);
    os_printf(DAT_3005f1a0);
  }
  if (*(int *)(iVar2 + 0xc4) != 0) {
    uVar1 = cdc_get_iostatus(param_1,1);
    (**(code **)(iVar2 + 0xc4))(uVar1,*(undefined4 *)(iVar2 + 4));
  }
  core_request_free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * uwd_acm_set_max_segment_size @ 0x3005EDB0  (примерный размер ~96 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Константы: 0x3005EDB0
 * Данные: DAT_3005f154, DAT_3005f158, DAT_3005f15c, DAT_3005f1a4, DAT_3005f1a8
 * ---------------------------------------------------------------- */
undefined4 uwd_acm_set_max_segment_size(int param_1,undefined2 param_2)

{
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005f154 + 0xf0)) && (4 < *(int *)(DAT_3005f154 + 0xf8))) {
    os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f1a4);
    os_printf(DAT_3005f1a8,param_2);
  }
  *(undefined2 *)(param_1 + 0xd4) = param_2;
  return 0;
}

/* ----------------------------------------------------------------
 * uwd_acm_notify_network_connection @ 0x3005EE10  (примерный размер ~196 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 2
 * Вызывает: cdc_create_notification, core_send_data
 * Константы: 0x3005EE10
 * Данные: DAT_3005f1ac
 * ---------------------------------------------------------------- */
undefined4 uwd_acm_notify_network_connection(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0xd] == 0) {
    uVar2 = 6;
  }
  else if ((*(ushort *)(param_1 + 0x38) & 8) == 0) {
    uVar2 = 0xb;
  }
  else {
    iVar1 = cdc_create_notification(param_1,0,param_2 != 0,*(undefined2 *)(param_1 + 0xe),0,0);
    if (iVar1 == 0) {
      uVar2 = 7;
    }
    else {
      *(undefined4 *)(iVar1 + 0x10) = DAT_3005f1ac;
      *(undefined4 **)(iVar1 + 0x14) = param_1;
      uVar2 = core_send_data(*param_1,param_1[0xd],iVar1);
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3005eed4 @ 0x3005EED4  (примерный размер ~396 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: core_get_available_iface, os_dprintf, os_printf, valid_type
 * Константы: 0x3005EED4
 * Данные: DAT_3005f154, DAT_3005f158, DAT_3005f15c, DAT_3005f1b0, DAT_3005f1b4
 * ---------------------------------------------------------------- */
undefined4 FUN_3005eed4(undefined4 *param_1,undefined1 *param_2,int param_3)

{
  ushort uVar1;
  char cVar2;
  char cVar3;
  
  uVar1 = *(ushort *)(param_1 + 0x38);
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005f154 + 0xf0)) && (4 < *(int *)(DAT_3005f154 + 0xf8))) {
    os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f1b0);
    os_printf(DAT_3005f1b4);
  }
  if (param_2 != (undefined1 *)0x0) {
    cVar2 = core_get_available_iface(*param_1);
    cVar3 = cVar2;
    if (param_3 == 0) {
      cVar3 = cVar2 + '\x01';
    }
    *param_2 = 5;
    param_2[1] = 0x24;
    param_2[2] = 0;
    param_2[3] = 0x10;
    param_2[4] = 1;
    param_2[5] = 4;
    param_2[6] = 0x24;
    param_2[7] = 2;
    param_2[8] = (byte)uVar1 & 0xf;
    param_2[9] = 5;
    param_2[10] = 0x24;
    param_2[0xb] = 1;
    param_2[0xc] = (char)((uVar1 & 0x30) >> 4);
    param_2[0xd] = cVar3;
    param_2[0xe] = 6;
    param_2[0xf] = 0x24;
    param_2[0x10] = 6;
    param_2[0x11] = cVar2;
    param_2[0x12] = cVar3;
    param_2[0x13] = cVar3;
  }
  return 0x14;
}

/* ----------------------------------------------------------------
 * cdc_init_acm @ 0x3005F060  (примерный размер ~1180 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 6
 * Вызывает: BSP_FreeDbg, FUN_3005f4fc, cdc_free_descriptors, os_dprintf, os_printf, valid_type
 * Константы: 0x3005F060, 0x3005F124
 * Данные: DAT_3005f154, DAT_3005f158, DAT_3005f15c, DAT_3005f1b8, DAT_3005f1bc, DAT_3005f1c0, DAT_3005f1c4, DAT_3005f1c8
 * ---------------------------------------------------------------- */
undefined4 cdc_init_acm(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 == 0) {
    uVar1 = 10;
  }
  else {
    puVar2 = (undefined4 *)FUN_3005f4fc(0xe4,1,DAT_3005f15c,0x3bc);
    if (puVar2 == (undefined4 *)0x0) {
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005f154 + 0xf0)) && (0 < *(int *)(DAT_3005f154 + 0xf8))) {
        os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f1b8);
        os_printf(DAT_3005f1bc,0);
      }
      uVar1 = 7;
    }
    else {
      *puVar2 = param_1;
      if (*(byte *)(DAT_3005f1c0 + *DAT_3005f1c4) < 0x14) {
                    /* WARNING: Could not recover jumptable at 0x3005f124. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (**(code **)(DAT_3005f1c8 + (uint)*(byte *)(DAT_3005f1c0 + *DAT_3005f1c4) * 4))();
        return uVar1;
      }
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005f550 + 0xf0)) && (0 < *(int *)(DAT_3005f550 + 0xf8))) {
        os_dprintf(DAT_3005f554,DAT_3005f558,DAT_3005f55c);
        os_printf(DAT_3005f560,0);
      }
      uVar1 = 0xb;
    }
    if (puVar2 != (undefined4 *)0x0) {
      cdc_free_descriptors(puVar2);
      BSP_FreeDbg(puVar2,DAT_3005f558,DAT_3005f584);
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3005f4fc @ 0x3005F4FC  (примерный размер ~140 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_MallocDbg, memset
 * Вызывают: cdc_init_acm
 * Константы: 0x3005F4FC
 * ---------------------------------------------------------------- */
void * FUN_3005f4fc(size_t param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)BSP_MallocDbg(param_1,0,param_3,param_4);
  if ((param_2 == 1) && (__s != (void *)0x0)) {
    memset(__s,0,param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * FUN_3005f588 @ 0x3005F588  (примерный размер ~80 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: uwd_acm_app_init
 * Константы: 0x3005F588, 0xFFFFFFFF
 * Данные: DAT_3006053c, DAT_30060540, DAT_30060544
 * ---------------------------------------------------------------- */
uint FUN_3005f588(void)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (*DAT_3006053c <= uVar1) {
      return 0xffffffff;
    }
    if (*(int *)(DAT_30060540 + DAT_30060544 * uVar1) == 0) break;
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3005f5d8 @ 0x3005F5D8  (примерный размер ~72 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: uwd_acm_app_init
 * Константы: 0x3005F5D8, 0xFFFFFFFF
 * Данные: DAT_3006053c, DAT_30060540, DAT_30060544
 * ---------------------------------------------------------------- */
undefined4 FUN_3005f5d8(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 - 1U < *DAT_3006053c) {
    *(undefined4 *)((param_1 - 1U) * DAT_30060544 + DAT_30060540) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3005f620 @ 0x3005F620  (примерный размер ~44 байт)
 * Модуль: usb | Вызывают: 3 | Вызывает: 2
 * Вызывает: uwd_cdc_abort_read, uwd_cdc_abort_write
 * Вызывают: FUN_3005f860, FUN_3005faa4, FUN_30061708
 * Константы: 0x3005F620
 * ---------------------------------------------------------------- */
void FUN_3005f620(int param_1)

{
  uwd_cdc_abort_write(*(undefined4 *)(param_1 + 0xcf0));
  uwd_cdc_abort_read(*(undefined4 *)(param_1 + 0xcf0));
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x34) = 1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005f64c @ 0x3005F64C  (примерный размер ~64 байт)
 * Модуль: usb | Вызывают: 6 | Вызывает: 2
 * Вызывает: BSP_Free, FUN_30062924
 * Вызывают: FUN_3005f6fc, FUN_3005fb90, FUN_3005fcf8, FUN_3006106c, FUN_300613c4, FUN_30061708
 * Константы: 0x3005F64C
 * ---------------------------------------------------------------- */
void FUN_3005f64c(int param_1,int param_2)

{
  FUN_30062924(param_2,param_1 + 0x50);
  *(undefined4 *)(param_2 + 8) = 1;
  BSP_Free(*(undefined4 *)(param_2 + 0xc));
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005f68c @ 0x3005F68C  (примерный размер ~112 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 3
 * Вызывает: BSP_Malloc, FUN_300628c8, FUN_300628e8
 * Вызывают: FUN_3005f6fc, FUN_3005fb90
 * Константы: 0x3005F68C
 * ---------------------------------------------------------------- */
int FUN_3005f68c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_300628c8((int *)(param_1 + 0x50));
  if (iVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x50);
    iVar1 = BSP_Malloc(*(undefined4 *)(param_1 + 100),0);
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    else {
      *(int *)(iVar2 + 0xc) = iVar1;
      *(int *)(iVar2 + 0x10) = iVar1;
      FUN_300628e8(iVar2);
      *(undefined4 *)(iVar2 + 8) = 0;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

