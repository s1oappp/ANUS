/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 4 (функций: 150, адреса 0x3005CDA0..0x3006DAD0)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * os_critical_leave @ 0x3005CDA0  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: intCpuUnlock
 * Вызывают: jos_critical_leave
 * Константы: 0x3005CDA0
 * Данные: DAT_3005d61c
 * ---------------------------------------------------------------- */
void os_critical_leave(void)

{
  intCpuUnlock(*DAT_3005d61c);
  return;
}

/* ----------------------------------------------------------------
 * os_get_time @ 0x3005CDAC  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 1
 * Вызывает: clock_gettime
 * Вызывают: FUN_30048f78, FUN_3005cde8, dbg_get_time_diff, j_arc4random, jmark_time_v, jtask_schedule_d, jtask_stop
 * Константы: 0x3005CDAC
 * ---------------------------------------------------------------- */
void os_get_time(__time_t *param_1)

{
  timespec local_10;
  
  clock_gettime(0,&local_10);
  *param_1 = local_10.tv_sec;
  param_1[1] = (int)(local_10.tv_nsec + ((uint)(local_10.tv_nsec >> 0x1f) >> 0x16)) >> 10;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005cde8 @ 0x3005CDE8  (примерный размер ~320 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: __udiv32, os_dprintf, os_get_time, os_printf, valid_type
 * Вызывают: os_sync_init
 * Константы: 0x3005CDE8
 * Данные: DAT_3005d5e4, DAT_3005d5e8, DAT_3005d5ec, DAT_3005d620, DAT_3005d624, DAT_3005d628, DAT_3005d62c
 * ---------------------------------------------------------------- */
uint FUN_3005cde8(void)

{
  uint uVar1;
  uint uVar2;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_24 = DAT_3005d620;
  valid_type(2);
  if ((3 < *DAT_3005d5e4) && (3 < DAT_3005d5e4[2])) {
    os_dprintf(DAT_3005d5e8,DAT_3005d5ec,0xfe);
    os_printf(DAT_3005d624);
  }
  while( true ) {
    os_get_time(&local_1c);
    for (local_20 = 0; local_20 < local_24; local_20 = local_20 + 1) {
    }
    os_get_time(&local_14);
    uVar2 = (local_14 - local_1c) * 1000 +
            ((int)((local_10 - local_18) + ((uint)(local_10 - local_18 >> 0x1f) >> 0x16)) >> 10);
    if (0x32 < uVar2) break;
    local_24 = local_24 << 1;
  }
  uVar1 = __udiv32(local_24,uVar2);
  valid_type(2);
  if ((2 < *DAT_3005d5e4) && (2 < DAT_3005d5e4[2])) {
    os_dprintf(DAT_3005d5e8,DAT_3005d5ec,DAT_3005d628);
    os_printf(DAT_3005d62c,uVar2,uVar1 >> 10);
  }
  return uVar1 >> 10;
}

/* ----------------------------------------------------------------
 * os_delay_us @ 0x3005CF28  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30050e60, FUN_300557c0
 * Константы: 0x3005CF28
 * Данные: DAT_3005d630
 * ---------------------------------------------------------------- */
void os_delay_us(int param_1)

{
  undefined4 local_c;
  
  for (local_c = 0; local_c < (uint)(param_1 * *DAT_3005d630); local_c = local_c + 1) {
  }
  return;
}

/* ----------------------------------------------------------------
 * os_delay_ms @ 0x3005CF78  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 5
 * Вызывает: jos_safe_enter_d, jos_safe_leave_d, os_panic, sysClkRateGet, taskDelay
 * Вызывают: FUN_300496a0, FUN_3004ffac, FUN_300537e8, FUN_30053910, FUN_300557c0
 * Константы: 0x3005CF78
 * Данные: DAT_3005d5ec, DAT_3005d5f4, DAT_3005d5f8, DAT_3005d5fc, DAT_3005d600, DAT_3005d604, DAT_3005d634, DAT_3005d638
 * ---------------------------------------------------------------- */
void os_delay_ms(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((*DAT_3005d5f4 & 1) == 0) {
    uVar3 = DAT_3005d5f8;
    if ((*DAT_3005d5f4 != 4) && (uVar3 = DAT_3005d600, *DAT_3005d5f4 == 2)) {
      uVar3 = DAT_3005d5fc;
    }
    os_panic(DAT_3005d604,DAT_3005d5ec,DAT_3005d634,uVar3);
  }
  iVar1 = sysClkRateGet();
  uVar2 = (uint)(param_1 * iVar1) >> 10;
  if (uVar2 == 0) {
    uVar2 = 1;
  }
  jos_safe_leave_d(DAT_3005d5ec,DAT_3005d638);
  taskDelay(uVar2);
  jos_safe_enter_d(DAT_3005d5ec,DAT_3005d63c);
  return;
}

/* ----------------------------------------------------------------
 * os_get_timetick @ 0x3005D014  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3005D014
 * Данные: DAT_3012bbcc
 * ---------------------------------------------------------------- */
undefined4 os_get_timetick(void)

{
  return *DAT_3012bbcc;
}

/* ----------------------------------------------------------------
 * os_msleep_init @ 0x3005D018  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: os_panic, semBCreate
 * Вызывают: FUN_300498e4, jtask_init
 * Константы: 0x3005D018
 * Данные: DAT_3005d5ec, DAT_3005d5f4, DAT_3005d5f8, DAT_3005d5fc, DAT_3005d600, DAT_3005d604, DAT_3005d640
 * ---------------------------------------------------------------- */
undefined4 os_msleep_init(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*DAT_3005d5f4 & 1) == 0) {
    uVar2 = DAT_3005d5f8;
    if ((*DAT_3005d5f4 != 4) && (uVar2 = DAT_3005d600, *DAT_3005d5f4 == 2)) {
      uVar2 = DAT_3005d5fc;
    }
    os_panic(DAT_3005d604,DAT_3005d5ec,DAT_3005d640,uVar2);
  }
  iVar1 = semBCreate(1,0);
  *param_1 = iVar1;
  if (iVar1 == 0) {
    uVar2 = 7;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * os_msleep_uninit @ 0x3005D0A4  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: os_panic, semDelete, semFlush
 * Вызывают: FUN_30048f78, FUN_300496a0, jtask_uninit
 * Константы: 0x3005D0A4
 * Данные: DAT_3005d5ec, DAT_3005d5f4, DAT_3005d5f8, DAT_3005d5fc, DAT_3005d600, DAT_3005d604, DAT_3005d644
 * ---------------------------------------------------------------- */
void os_msleep_uninit(undefined4 param_1)

{
  undefined4 uVar1;
  
  if ((*DAT_3005d5f4 & 1) == 0) {
    uVar1 = DAT_3005d5f8;
    if ((*DAT_3005d5f4 != 4) && (uVar1 = DAT_3005d600, *DAT_3005d5f4 == 2)) {
      uVar1 = DAT_3005d5fc;
    }
    os_panic(DAT_3005d604,DAT_3005d5ec,DAT_3005d644,uVar1);
  }
  semFlush(param_1);
  semDelete(param_1);
  return;
}

/* ----------------------------------------------------------------
 * os_msleep @ 0x3005D11C  (примерный размер ~212 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 5
 * Вызывает: jos_safe_enter_d, jos_safe_leave_d, os_panic, semTake, sysClkRateGet
 * Вызывают: FUN_300483e8, FUN_30048f78
 * Константы: 0x3005D11C, 0xFFFFFFFF
 * Данные: DAT_3005d5ec, DAT_3005d5f4, DAT_3005d5f8, DAT_3005d5fc, DAT_3005d600, DAT_3005d604, DAT_3005d648, DAT_3005d64c
 * ---------------------------------------------------------------- */
undefined4 os_msleep(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar2 = 0;
  if ((*DAT_3005d5f4 & 1) == 0) {
    uVar4 = DAT_3005d5f8;
    if ((*DAT_3005d5f4 != 4) && (uVar4 = DAT_3005d600, *DAT_3005d5f4 == 2)) {
      uVar4 = DAT_3005d5fc;
    }
    os_panic(DAT_3005d604,DAT_3005d5ec,DAT_3005d648,uVar4);
  }
  iVar1 = sysClkRateGet();
  uVar3 = (uint)(param_2 * iVar1) >> 10;
  if (param_2 == 0) {
    uVar3 = 0xffffffff;
  }
  else if (uVar3 == 0) {
    uVar3 = 1;
  }
  jos_safe_leave_d(DAT_3005d5ec,DAT_3005d64c);
  iVar1 = semTake(param_1,uVar3);
  jos_safe_enter_d(DAT_3005d5ec,DAT_3005d650);
  if (iVar1 != 0) {
    uVar2 = 0xc;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * os_wakeup @ 0x3005D1F0  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: semGive
 * Вызывают: FUN_30048d14, FUN_30048f78, FUN_300496a0
 * Константы: 0x3005D1F0
 * ---------------------------------------------------------------- */
undefined4 os_wakeup(undefined4 param_1)

{
  semGive(param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * os_get_hz @ 0x3005D210  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3005D210
 * Данные: DAT_30009588
 * ---------------------------------------------------------------- */
undefined4 os_get_hz(void)

{
  return *DAT_30009588;
}

/* ----------------------------------------------------------------
 * os_sync_init @ 0x3005D214  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3005cde8
 * Вызывают: os_port_init
 * Константы: 0x3005D214
 * Данные: DAT_3005d5e0, DAT_3005d630
 * ---------------------------------------------------------------- */
undefined4 os_sync_init(void)

{
  undefined4 uVar1;
  
  *DAT_3005d5e0 = 0;
  DAT_3005d5e0[1] = DAT_3005d5e0;
  uVar1 = FUN_3005cde8();
  *DAT_3005d630 = uVar1;
  return 0;
}

/* ----------------------------------------------------------------
 * os_sync_uninit @ 0x3005D244  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: jusb_exit, os_port_uninit
 * Константы: 0x3005D244
 * ---------------------------------------------------------------- */
void os_sync_uninit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * os_msg_q_create @ 0x3005D248  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 7
 * Вызывает: BSP_FreeDbg, FUN_3005d58c, msgQCreate, os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x3005D248
 * Данные: DAT_3005d5e4, DAT_3005d5e8, DAT_3005d5ec, DAT_3005d5f4, DAT_3005d5f8, DAT_3005d5fc, DAT_3005d600, DAT_3005d604
 * ---------------------------------------------------------------- */
undefined4 os_msg_q_create(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*DAT_3005d5f4 & 1) == 0) {
    uVar3 = DAT_3005d5f8;
    if ((*DAT_3005d5f4 != 4) && (uVar3 = DAT_3005d600, *DAT_3005d5f4 == 2)) {
      uVar3 = DAT_3005d5fc;
    }
    os_panic(DAT_3005d604,DAT_3005d5ec,DAT_3005d654,uVar3);
  }
  piVar1 = (int *)FUN_3005d58c(4,1,DAT_3005d5ec,0x1a4);
  if (piVar1 != (int *)0x0) {
    *param_1 = (int)piVar1;
    iVar2 = msgQCreate(param_2,param_3,0);
    *piVar1 = iVar2;
    if (*piVar1 != 0) {
      return 0;
    }
    BSP_FreeDbg(piVar1,DAT_3005d5ec,DAT_3005d658);
    *param_1 = 0;
  }
  valid_type(2);
  if ((0 < *DAT_3005d5e4) && (0 < DAT_3005d5e4[2])) {
    os_dprintf(DAT_3005d5e8,DAT_3005d5ec,DAT_3005d65c);
    os_printf(DAT_3005d660);
  }
  return 7;
}

/* ----------------------------------------------------------------
 * os_msg_q_send @ 0x3005D360  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: msgQSend
 * Константы: 0x3005D360
 * ---------------------------------------------------------------- */
void os_msg_q_send(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  msgQSend(*param_1,param_2,param_3,param_4,0);
  return;
}

/* ----------------------------------------------------------------
 * os_msg_q_recv @ 0x3005D3A0  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: msgQReceive
 * Константы: 0x3005D3A0
 * ---------------------------------------------------------------- */
void os_msg_q_recv(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  msgQReceive(*param_1,param_2,param_3,param_4);
  return;
}

/* ----------------------------------------------------------------
 * os_msg_q_delete @ 0x3005D3D0  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_FreeDbg, msgQDelete, os_panic
 * Константы: 0x3005D3D0
 * Данные: DAT_3005d5ec, DAT_3005d5f4, DAT_3005d5f8, DAT_3005d5fc, DAT_3005d600, DAT_3005d604, DAT_3005d664, DAT_3005d668
 * ---------------------------------------------------------------- */
void os_msg_q_delete(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if ((*DAT_3005d5f4 & 1) == 0) {
    uVar1 = DAT_3005d5f8;
    if ((*DAT_3005d5f4 != 4) && (uVar1 = DAT_3005d600, *DAT_3005d5f4 == 2)) {
      uVar1 = DAT_3005d5fc;
    }
    os_panic(DAT_3005d604,DAT_3005d5ec,DAT_3005d664,uVar1);
  }
  msgQDelete(*param_1);
  BSP_FreeDbg(param_1,DAT_3005d5ec,DAT_3005d668);
  return;
}

/* ----------------------------------------------------------------
 * os_task_spawn @ 0x3005D450  (примерный размер ~292 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: jos_safe_check, taskSpawn
 * Константы: 0x3005D450
 * Данные: DAT_3005d5ec, DAT_3005d66c, DAT_3005d670
 * ---------------------------------------------------------------- */
void os_task_spawn(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  int param_5,int param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar6;
  undefined4 local_4c [5];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 *puVar5;
  
  iVar6 = 5;
  puVar3 = local_4c;
  puVar4 = DAT_3005d66c;
  do {
    puVar5 = puVar4 + 1;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 2;
    uVar2 = *puVar5;
    iVar6 = iVar6 + -1;
    puVar5 = puVar3 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 2;
    *puVar5 = uVar2;
  } while (iVar6 != 0);
  if (10 < param_5) {
    param_5 = 10;
  }
  if ((param_5 != 0) && (param_6 != 0)) {
    for (iVar6 = 0; iVar6 < param_5; iVar6 = iVar6 + 1) {
      local_4c[iVar6] = *(undefined4 *)(param_6 + iVar6 * 4);
    }
  }
  jos_safe_check(DAT_3005d5ec,DAT_3005d670,local_4c);
  taskSpawn(param_1,param_2,0,param_3,param_4,local_4c[0],local_4c[1],local_4c[2],local_4c[3],
            local_4c[4],local_38,local_34,local_30,local_2c,local_28);
  return;
}

/* ----------------------------------------------------------------
 * os_task_delete @ 0x3005D574  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: taskDelete
 * Константы: 0x3005D574
 * ---------------------------------------------------------------- */
void os_task_delete(undefined4 param_1)

{
  taskDelete(param_1);
  return;
}

/* ----------------------------------------------------------------
 * os_tick_get @ 0x3005D588  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3005D588
 * Данные: DAT_3012bbcc
 * ---------------------------------------------------------------- */
undefined4 os_tick_get(void)

{
  return *DAT_3012bbcc;
}

/* ----------------------------------------------------------------
 * FUN_3005d58c @ 0x3005D58C  (примерный размер ~232 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: BSP_MallocDbg, memset
 * Вызывают: os_msg_q_create, os_mutex_init, os_thread_create
 * Константы: 0x3005D58C
 * ---------------------------------------------------------------- */
void * FUN_3005d58c(size_t param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)BSP_MallocDbg(param_1,0,param_3,param_4);
  if ((param_2 == 1) && (__s != (void *)0x0)) {
    memset(__s,0,param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * FUN_3005d674 @ 0x3005D674  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: get_dev_params
 * Константы: 0x3005D674
 * Данные: DAT_3005d71c, DAT_3005d720
 * ---------------------------------------------------------------- */
undefined4 FUN_3005d674(void)

{
  int iVar1;
  
  if (*(int *)(DAT_3005d71c + *DAT_3005d720 * 4) == 0) {
    *DAT_3005d720 = 0;
  }
  iVar1 = *DAT_3005d720;
  *DAT_3005d720 = *DAT_3005d720 + 1;
  return *(undefined4 *)(DAT_3005d71c + iVar1 * 4);
}

/* ----------------------------------------------------------------
 * get_dev_params @ 0x3005D6C8  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3005d674
 * Вызывают: BSP_USB_GetUwArgs
 * Константы: 0x3005D6C8
 * Данные: DAT_3005d724
 * ---------------------------------------------------------------- */
int get_dev_params(void)

{
  undefined4 uVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar2 < 1; iVar2 = iVar2 + 1) {
    if (*(int *)(DAT_3005d724 + iVar2 * 0x1c) == 0) {
      uVar1 = FUN_3005d674();
      *(undefined4 *)(DAT_3005d724 + iVar2 * 0x1c) = uVar1;
    }
  }
  return DAT_3005d724;
}

/* ----------------------------------------------------------------
 * get_num_of_devices @ 0x3005D714  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_USB_GetUwArgs
 * Константы: 0x3005D714
 * ---------------------------------------------------------------- */
undefined4 get_num_of_devices(void)

{
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3005d728 @ 0x3005D728  (примерный размер ~360 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: cdc_get_iostatus, cdc_send_status, core_stall_ctrl_pipe, os_dprintf, os_printf, valid_type
 * Константы: 0x3005D728
 * Данные: DAT_3005e71c, DAT_3005e720, DAT_3005e724, DAT_3005e728, DAT_3005e72c, DAT_3005e730
 * ---------------------------------------------------------------- */
void FUN_3005d728(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 local_1c [2];
  
  puVar2 = *(undefined4 **)(param_1 + 0x14);
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005e71c + 0xf0)) && (4 < *(int *)(DAT_3005e71c + 0xf8))) {
    os_dprintf(DAT_3005e720,DAT_3005e724,0x24);
    os_printf(DAT_3005e728,0);
  }
  iVar1 = cdc_get_iostatus(param_1,1);
  if (iVar1 == 0) {
    local_1c[0] = *(undefined2 *)**(undefined4 **)(param_1 + 8);
    iVar1 = (*(code *)puVar2[0x28])(*(undefined2 *)((int)puVar2 + 0x4a),local_1c,puVar2[1]);
    if (iVar1 == 0) {
      iVar1 = cdc_send_status(puVar2);
      if (iVar1 == 0) {
        return;
      }
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
        os_dprintf(DAT_3005e720,DAT_3005e724,0x39);
        os_printf(DAT_3005e730,0,iVar1);
      }
    }
    else {
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
        os_dprintf(DAT_3005e720,DAT_3005e724,0x31);
        os_printf(DAT_3005e72c,0,iVar1);
      }
    }
  }
  core_stall_ctrl_pipe(*puVar2,*(undefined1 *)(puVar2 + 0x14));
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005d890 @ 0x3005D890  (примерный размер ~520 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: cdc_create_ep0_read, core_read_data, os_dprintf, os_memcpy, os_printf, valid_type
 * Вызывают: acm_handle_request
 * Константы: 0x3005D890
 * Данные: DAT_3005e71c, DAT_3005e720, DAT_3005e724, DAT_3005e728, DAT_3005e824, DAT_3005e828, DAT_3005e904, DAT_3005e908
 * ---------------------------------------------------------------- */
undefined4 FUN_3005d890(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 10;
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005e71c + 0xf0)) && (4 < *(int *)(DAT_3005e71c + 0xf8))) {
    os_dprintf(DAT_3005e720,DAT_3005e724,0x56);
    os_printf(DAT_3005e728,0);
  }
  if ((*(ushort *)(param_1 + 0x38) & 1) == 0) {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
      os_dprintf(DAT_3005e720,DAT_3005e724,0x5c);
      os_printf(DAT_3005e824,0);
    }
  }
  else if (*(short *)(param_2 + 6) == 2) {
    if (param_1[0x28] == 0) {
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
        os_dprintf(DAT_3005e720,DAT_3005e724,0x6a);
        os_printf(DAT_3005e904,0);
      }
    }
    else {
      os_memcpy(param_1 + 0x12,param_2,8);
      iVar1 = cdc_create_ep0_read(param_1,2);
      if (iVar1 == 0) {
        valid_type(0x3e);
        if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
          os_dprintf(DAT_3005e720,DAT_3005e724,0x75);
          os_printf(DAT_3005e908,0);
        }
        uVar2 = 7;
      }
      else {
        *(undefined4 *)(iVar1 + 0x10) = DAT_3005e90c;
        *(undefined4 **)(iVar1 + 0x14) = param_1;
        uVar2 = core_read_data(*param_1,0,iVar1);
      }
    }
  }
  else {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
      os_dprintf(DAT_3005e720,DAT_3005e724,99);
      os_printf(DAT_3005e828,0,*(undefined2 *)(param_2 + 6));
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3005da98 @ 0x3005DA98  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: cdc_get_iostatus, os_dprintf, os_printf, valid_type
 * Константы: 0x3005DA98
 * Данные: DAT_3005e71c, DAT_3005e720, DAT_3005e724, DAT_3005e9d0
 * ---------------------------------------------------------------- */
void FUN_3005da98(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005e71c + 0xf0)) && (4 < *(int *)(DAT_3005e71c + 0xf8))) {
    os_dprintf(DAT_3005e720,DAT_3005e724,0x91);
    os_printf(DAT_3005e9d0);
  }
  if (*(int *)(iVar2 + 0xbc) != 0) {
    uVar1 = cdc_get_iostatus(param_1,1);
    (**(code **)(iVar2 + 0xbc))(uVar1,*(undefined4 *)(iVar2 + 4));
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005db28 @ 0x3005DB28  (примерный размер ~636 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: cdc_create_ep0_write, core_send_data, os_dprintf, os_printf, valid_type
 * Вызывают: acm_handle_request
 * Константы: 0x3005DB28
 * Данные: DAT_3005e71c, DAT_3005e720, DAT_3005e724, DAT_3005e728, DAT_3005e824, DAT_3005e828, DAT_3005e904, DAT_3005e908
 * ---------------------------------------------------------------- */
int FUN_3005db28(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_24 [4];
  
  iVar1 = 10;
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005e71c + 0xf0)) && (4 < *(int *)(DAT_3005e71c + 0xf8))) {
    os_dprintf(DAT_3005e720,DAT_3005e724,0xaf);
    os_printf(DAT_3005e728,0);
  }
  if ((*(ushort *)(param_1 + 0x38) & 1) == 0) {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
      os_dprintf(DAT_3005e720,DAT_3005e724,0xb5);
      os_printf(DAT_3005e824,0);
    }
  }
  else if (*(short *)(param_2 + 6) == 2) {
    if (param_1[0x29] == 0) {
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
        os_dprintf(DAT_3005e720,DAT_3005e724,0xc3);
        os_printf(DAT_3005e904,0);
      }
    }
    else {
      iVar1 = (*(code *)param_1[0x29])(*(undefined2 *)(param_2 + 2),auStack_24,param_1[1]);
      if (iVar1 == 0) {
        iVar1 = cdc_create_ep0_write(param_1,auStack_24,2,*(undefined2 *)(param_2 + 6));
        if (iVar1 == 0) {
          valid_type(0x3e);
          if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
            os_dprintf(DAT_3005e720,DAT_3005e724,0xd8);
            os_printf(DAT_3005e908,0);
          }
          iVar1 = 7;
        }
        else {
          *(undefined4 *)(iVar1 + 0x10) = DAT_3005ec48;
          *(undefined4 **)(iVar1 + 0x14) = param_1;
          iVar1 = core_send_data(*param_1,0,iVar1);
        }
      }
      else {
        valid_type(0x3e);
        if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
          os_dprintf(DAT_3005e720,DAT_3005e724,0xce);
          os_printf(DAT_3005eb4c,0);
        }
      }
    }
  }
  else {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
      os_dprintf(DAT_3005e720,DAT_3005e724,0xbc);
      os_printf(DAT_3005e828,0,*(undefined2 *)(param_2 + 6));
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3005dda4 @ 0x3005DDA4  (примерный размер ~492 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: cdc_send_status, os_dprintf, os_printf, valid_type
 * Вызывают: acm_handle_request
 * Константы: 0x3005DDA4
 * Данные: DAT_3005e71c, DAT_3005e720, DAT_3005e724, DAT_3005e728, DAT_3005e824, DAT_3005e828, DAT_3005eb4c, DAT_3005ed54
 * ---------------------------------------------------------------- */
int FUN_3005dda4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 10;
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005e71c + 0xf0)) && (4 < *(int *)(DAT_3005e71c + 0xf8))) {
    os_dprintf(DAT_3005e720,DAT_3005e724,0xf9);
    os_printf(DAT_3005e728,0);
  }
  if ((*(ushort *)(param_1 + 0xe0) & 1) == 0) {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
      os_dprintf(DAT_3005e720,DAT_3005e724,0xff);
      os_printf(DAT_3005e824,0);
    }
  }
  else if (*(short *)(param_2 + 6) == 0) {
    if (*(int *)(param_1 + 0xa8) == 0) {
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
        os_dprintf(DAT_3005e720,DAT_3005e724,0x10c);
        os_printf(DAT_3005ed58,0);
      }
    }
    else {
      iVar1 = (**(code **)(param_1 + 0xa8))
                        (*(undefined2 *)(param_2 + 2),*(undefined4 *)(param_1 + 4));
      if (iVar1 == 0) {
        iVar1 = cdc_send_status(param_1);
      }
      else {
        valid_type(0x3e);
        if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
          os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005ee48);
          os_printf(DAT_3005eb4c,0);
        }
      }
    }
  }
  else {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
      os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005ed54);
      os_printf(DAT_3005e828,0,*(undefined2 *)(param_2 + 6));
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3005df90 @ 0x3005DF90  (примерный размер ~432 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: cdc_get_iostatus, cdc_send_status, core_stall_ctrl_pipe, os_dprintf, os_printf, valid_type
 * Константы: 0x3005DF90
 * Данные: DAT_3005e71c, DAT_3005e720, DAT_3005e724, DAT_3005e728, DAT_3005eb4c, DAT_3005ee4c, DAT_3005ef7c, DAT_3005ef80
 * ---------------------------------------------------------------- */
void FUN_3005df90(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  
  puVar4 = *(undefined4 **)(param_1 + 0x14);
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005e71c + 0xf0)) && (4 < *(int *)(DAT_3005e71c + 0xf8))) {
    os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005ee4c);
    os_printf(DAT_3005e728,0);
  }
  iVar2 = cdc_get_iostatus(param_1,1);
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)**(undefined4 **)(param_1 + 8);
    uVar1 = *puVar3;
    local_29 = (undefined1)((uint)uVar1 >> 0x18);
    local_2a = (undefined1)((uint)uVar1 >> 0x10);
    local_2b = (undefined1)((uint)uVar1 >> 8);
    local_2c = (undefined1)uVar1;
    local_28 = *(undefined1 *)(puVar3 + 1);
    local_27 = *(undefined1 *)((int)puVar3 + 5);
    local_26 = *(undefined1 *)((int)puVar3 + 6);
    iVar2 = (*(code *)puVar4[0x2b])(&local_2c,puVar4[1]);
    if (iVar2 == 0) {
      iVar2 = cdc_send_status(puVar4);
      if (iVar2 == 0) {
        return;
      }
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
        os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005ef80);
        os_printf(DAT_3005ef84,0,iVar2);
      }
    }
    else {
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
        os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005ef7c);
        os_printf(DAT_3005eb4c,0);
      }
    }
  }
  core_stall_ctrl_pipe(*puVar4,*(undefined1 *)(puVar4 + 0x14));
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005e140 @ 0x3005E140  (примерный размер ~500 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: cdc_create_ep0_read, core_read_data, os_dprintf, os_printf, valid_type
 * Вызывают: acm_handle_request
 * Константы: 0x3005E140
 * Данные: DAT_3005e71c, DAT_3005e720, DAT_3005e724, DAT_3005e728, DAT_3005e824, DAT_3005ed58, DAT_3005ef88, DAT_3005f08c
 * ---------------------------------------------------------------- */
undefined4 FUN_3005e140(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 10;
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005e71c + 0xf0)) && (4 < *(int *)(DAT_3005e71c + 0xf8))) {
    os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005ef88);
    os_printf(DAT_3005e728,0);
  }
  if ((*(ushort *)(param_1 + 0x38) & 2) == 0) {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
      os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005f08c);
      os_printf(DAT_3005e824,0);
    }
  }
  else if (*(short *)(param_2 + 6) == 7) {
    if (param_1[0x2b] == 0) {
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
        os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005f094);
        os_printf(DAT_3005ed58,0);
      }
    }
    else {
      iVar1 = cdc_create_ep0_read(param_1,7);
      if (iVar1 == 0) {
        valid_type(0x3e);
        if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
          os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005f128);
          os_printf(DAT_3005f12c,0);
        }
        uVar2 = 7;
      }
      else {
        *(undefined4 *)(iVar1 + 0x10) = DAT_3005f130;
        *(undefined4 **)(iVar1 + 0x14) = param_1;
        uVar2 = core_read_data(*param_1,0,iVar1);
      }
    }
  }
  else {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
      os_dprintf(DAT_3005e720,DAT_3005e724,0x174);
      os_printf(DAT_3005f090,0,*(undefined2 *)(param_2 + 6));
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3005e334 @ 0x3005E334  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: cdc_get_iostatus, os_dprintf, os_printf, valid_type
 * Константы: 0x3005E334
 * Данные: DAT_3005e71c, DAT_3005e720, DAT_3005e724, DAT_3005f134, DAT_3005f138
 * ---------------------------------------------------------------- */
void FUN_3005e334(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005e71c + 0xf0)) && (4 < *(int *)(DAT_3005e71c + 0xf8))) {
    os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005f134);
    os_printf(DAT_3005f138);
  }
  if (*(int *)(iVar2 + 0xc0) != 0) {
    uVar1 = cdc_get_iostatus(param_1,1);
    (**(code **)(iVar2 + 0xc0))(uVar1,*(undefined4 *)(iVar2 + 4));
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005e3c4 @ 0x3005E3C4  (примерный размер ~708 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: cdc_create_ep0_write, core_send_data, os_dprintf, os_printf, valid_type
 * Вызывают: acm_handle_request
 * Константы: 0x3005E3C4
 * Данные: DAT_3005e71c, DAT_3005e720, DAT_3005e724, DAT_3005e728, DAT_3005e824, DAT_3005eb4c, DAT_3005ed58, DAT_3005f090
 * ---------------------------------------------------------------- */
int FUN_3005e3c4(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined1 local_2c [8];
  
  iVar1 = 10;
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005e71c + 0xf0)) && (4 < *(int *)(DAT_3005e71c + 0xf8))) {
    os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005f13c);
    os_printf(DAT_3005e728,0);
  }
  if ((*(ushort *)(param_1 + 0x38) & 2) == 0) {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
      os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005f140);
      os_printf(DAT_3005e824,0);
    }
  }
  else if (*(short *)(param_2 + 6) == 7) {
    if (param_1[0x2c] == 0) {
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
        os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005f144);
        os_printf(DAT_3005ed58,0);
      }
    }
    else {
      iVar1 = (*(code *)param_1[0x2c])(local_2c,param_1[1]);
      if (iVar1 == 0) {
        iVar1 = cdc_create_ep0_write(param_1,local_2c,7,*(undefined2 *)(param_2 + 6));
        if (iVar1 == 0) {
          valid_type(0x3e);
          if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
            os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005f14c);
            os_printf(DAT_3005f12c,0);
          }
          iVar1 = 7;
        }
        else {
          *(undefined4 *)(iVar1 + 0x10) = DAT_3005f150;
          *(undefined4 **)(iVar1 + 0x14) = param_1;
          iVar1 = core_send_data(*param_1,0,iVar1);
        }
      }
      else {
        valid_type(0x3e);
        if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
          os_dprintf(DAT_3005e720,DAT_3005e724,DAT_3005f148);
          os_printf(DAT_3005eb4c,0);
        }
      }
    }
  }
  else {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005e71c + 0xf8))) {
      os_dprintf(DAT_3005e720,DAT_3005e724,0x1c8);
      os_printf(DAT_3005f090,0,*(undefined2 *)(param_2 + 6));
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3005e688 @ 0x3005E688  (примерный размер ~444 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: cdc_send_status, os_dprintf, os_printf, valid_type
 * Вызывают: acm_handle_request
 * Константы: 0x3005E688
 * Данные: DAT_3005e71c, DAT_3005e720, DAT_3005e724, DAT_3005e728, DAT_3005e824, DAT_3005eb4c, DAT_3005ed58, DAT_3005f154
 * ---------------------------------------------------------------- */
int FUN_3005e688(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 10;
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005e71c + 0xf0)) && (4 < *(int *)(DAT_3005e71c + 0xf8))) {
    os_dprintf(DAT_3005e720,DAT_3005e724,0x204);
    os_printf(DAT_3005e728,0);
  }
  if ((*(ushort *)(param_1 + 0xe0) & 2) == 0) {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005e71c + 0xf0)) && (0 < *(int *)(DAT_3005f154 + 0xf8))) {
      os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f160);
      os_printf(DAT_3005e824,0);
    }
  }
  else if (*(int *)(param_1 + 0xb4) == 0) {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005f154 + 0xf0)) && (0 < *(int *)(DAT_3005f154 + 0xf8))) {
      os_dprintf(DAT_3005f158,DAT_3005f15c,0x210);
      os_printf(DAT_3005ed58,0);
    }
  }
  else {
    iVar1 = (**(code **)(param_1 + 0xb4))(*(undefined2 *)(param_2 + 2),*(undefined4 *)(param_1 + 4))
    ;
    if (iVar1 == 0) {
      iVar1 = cdc_send_status(param_1);
    }
    else {
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005f154 + 0xf0)) && (0 < *(int *)(DAT_3005f154 + 0xf8))) {
        os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f164);
        os_printf(DAT_3005eb4c,0);
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3005e844 @ 0x3005E844  (примерный размер ~424 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: cdc_send_status, os_dprintf, os_printf, valid_type
 * Вызывают: acm_handle_request
 * Константы: 0x3005E844
 * Данные: DAT_3005eb4c, DAT_3005ed58, DAT_3005f154, DAT_3005f158, DAT_3005f15c, DAT_3005f168, DAT_3005f16c, DAT_3005f170
 * ---------------------------------------------------------------- */
int FUN_3005e844(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 10;
  valid_type(0x3e);
  if ((4 < *(int *)(DAT_3005f154 + 0xf0)) && (4 < *(int *)(DAT_3005f154 + 0xf8))) {
    os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f168);
    os_printf(DAT_3005f16c,0);
  }
  if ((*(ushort *)(param_1 + 0xe0) & 4) == 0) {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005f154 + 0xf0)) && (0 < *(int *)(DAT_3005f154 + 0xf8))) {
      os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f170);
      os_printf(DAT_3005f174,0);
    }
  }
  else if (*(int *)(param_1 + 0xb8) == 0) {
    valid_type(0x3e);
    if ((0 < *(int *)(DAT_3005f154 + 0xf0)) && (0 < *(int *)(DAT_3005f154 + 0xf8))) {
      os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f178);
      os_printf(DAT_3005ed58,0);
    }
  }
  else {
    iVar1 = (**(code **)(param_1 + 0xb8))(*(undefined2 *)(param_2 + 2),*(undefined4 *)(param_1 + 4))
    ;
    if (iVar1 == 0) {
      iVar1 = cdc_send_status(param_1);
    }
    else {
      valid_type(0x3e);
      if ((0 < *(int *)(DAT_3005f154 + 0xf0)) && (0 < *(int *)(DAT_3005f154 + 0xf8))) {
        os_dprintf(DAT_3005f158,DAT_3005f15c,DAT_3005f17c);
        os_printf(DAT_3005eb4c,0);
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * efuseInit @ 0x30063174  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_TRACE, semBCreate
 * Константы: 0x30063174, 0xFFFFFFFF
 * Данные: DAT_30063bc0, DAT_30063bc4, DAT_30063bc8
 * ---------------------------------------------------------------- */
undefined4 efuseInit(void)

{
  int iVar1;
  
  if (*DAT_30063bc0 == 0) {
    if (*DAT_30063bc4 == 0) {
      iVar1 = semBCreate(0,1);
      *DAT_30063bc4 = iVar1;
      *DAT_30063bc0 = 1;
    }
    if (*DAT_30063bc4 == 0) {
      BSP_TRACE(4,0x2a,DAT_30063bc8);
      return 0xffffffff;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * efuseRead @ 0x300631E8  (примерный размер ~372 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 3
 * Вызывает: BSP_TRACE, semGive, semTake
 * Вызывают: CheckHukIsValid, create_crypto_key, efuseWriteHUK, secureAlreadyUse
 * Константы: 0x00200000, 0x00100000, 0x300631E8, 0xFFFFFFFF
 * Данные: DAT_30063bc0, DAT_30063bc4, DAT_30063bcc, DAT_30063bd0, DAT_30063bd4, DAT_30063bd8, DAT_30063bdc, DAT_30063be0
 * ---------------------------------------------------------------- */
undefined4 efuseRead(uint param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = DAT_30063bcc;
  if ((((param_2 != (undefined4 *)0x0) && (uVar1 = DAT_30063bd0, param_1 < 0x81)) &&
      (param_1 + param_3 < 0x81)) && (uVar1 = DAT_30063bd4, *DAT_30063bc0 != 0)) {
    semTake(*DAT_30063bc4,0xffffffff);
    *DAT_30063bd8 = 0x200000;
    *DAT_30063bdc = *DAT_30063bdc | 8;
    for (uVar3 = 0; uVar1 = 0, uVar3 < param_3; uVar3 = uVar3 + 1) {
      *DAT_30063be0 = param_1 + uVar3;
      *DAT_30063bdc = *DAT_30063bdc | 4;
      uVar1 = DAT_30063be4;
      iVar2 = 0x100000;
      do {
        if ((*DAT_30063bdc & 4) == 0) break;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      if (iVar2 == 0) {
        BSP_TRACE(4,0x2a,DAT_30063be8);
        break;
      }
      iVar2 = 0x100000;
      do {
        if ((*DAT_30063bec & 2) != 0) break;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      if (iVar2 == 0) {
        BSP_TRACE(4,0x2a,DAT_30063bf0);
        break;
      }
      *param_2 = *DAT_30063bf4;
      param_2 = param_2 + 1;
    }
    *DAT_30063bf8 = 0x200000;
    semGive(*DAT_30063bc4);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * efuseWrite @ 0x3006335C  (примерный размер ~724 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 8
 * Вызывает: BSP_PMU_LDOOff, BSP_PMU_LDOOn, BSP_PMU_LDOVoltSet, BSP_TRACE, intCpuLock, intCpuUnlock, semGive, semTake
 * Вызывают: efuseWriteAt, efuseWriteHUK, efuseWriteSetSecEn
 * Константы: 0x00100000, 0x00200000, 0x3006335C, 0xFFFFFFFF, 0xFFFFFFFB
 * Данные: DAT_30063bc0, DAT_30063bc4, DAT_30063bcc, DAT_30063bd0, DAT_30063bd4, DAT_30063bd8, DAT_30063bdc, DAT_30063be0
 * ---------------------------------------------------------------- */
int efuseWrite(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = DAT_30063bcc;
  if ((((param_1 != (undefined4 *)0x0) && (iVar6 = DAT_30063bd0, param_2 < 0x81)) &&
      (param_2 + param_3 < 0x81)) && (iVar6 = DAT_30063bd4, *DAT_30063bc0 != 0)) {
    semTake(*DAT_30063bc4,0xffffffff);
    *DAT_30063bd8 = 0x200000;
    uVar1 = intCpuLock();
    iVar6 = DAT_30063c00;
    if ((*DAT_30063bfc & 1) == 0) {
      *DAT_30063bdc = *DAT_30063bdc | 8;
      *DAT_30063c08 = 2;
      *DAT_30063c0c = 0x2ec;
      *DAT_30063bdc = *DAT_30063bdc | 2;
      iVar6 = DAT_30063be4;
      iVar5 = 0x100000;
      do {
        if ((*DAT_30063bec & 4) != 0) break;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      if (iVar5 == 0) {
        BSP_TRACE(4,0x2a,DAT_30063c10);
      }
      else {
        iVar2 = BSP_PMU_LDOVoltSet(0xf,0xfa);
        iVar3 = BSP_PMU_LDOOn(0xf);
        iVar6 = DAT_30063be4;
        iVar5 = DAT_30063c18;
        if (iVar3 + iVar2 == 0) {
          for (; -1 < iVar5; iVar5 = iVar5 + -1) {
          }
          for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + 1) {
            *DAT_30063be0 = param_2;
            *DAT_30063c1c = *param_1;
            *DAT_30063bdc = *DAT_30063bdc | 1;
            iVar6 = 0x100000;
            do {
              if ((*DAT_30063bdc & 1) == 0) break;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            if (iVar6 == 0) {
              BSP_TRACE(4,0x2a,DAT_30063c20);
              break;
            }
            iVar6 = 0x100000;
            do {
              if ((*DAT_30063bec & 1) != 0) break;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            if (iVar6 == 0) {
              BSP_TRACE(4,0x2a,DAT_30063c24);
              break;
            }
            param_2 = param_2 + 1;
            param_1 = param_1 + 1;
          }
          iVar6 = BSP_PMU_LDOOff(0xf);
          iVar5 = DAT_30063be4;
          if (iVar6 != 0) {
            BSP_TRACE(4,0x2a,DAT_30063c28,DAT_30063be4);
            iVar6 = iVar5;
          }
          *DAT_30063bdc = *DAT_30063bdc & 0xfffffffb;
        }
        else {
          BSP_TRACE(4,0x2a,DAT_30063c14,DAT_30063be4);
        }
      }
    }
    else {
      BSP_TRACE(4,0x2a,DAT_30063c04);
    }
    intCpuUnlock(uVar1);
    *DAT_30063bf8 = 0x200000;
    semGive(*DAT_30063bc4);
  }
  return iVar6;
}

/* ----------------------------------------------------------------
 * efuseWriteSetSecEn @ 0x30063630  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_TRACE, efuseWrite
 * Вызывают: efuseWriteAt
 * Константы: 0x30063630
 * Данные: DAT_30063c2c
 * ---------------------------------------------------------------- */
int efuseWriteSetSecEn(void)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = 2;
  iVar1 = efuseWrite(&local_c,0x7f,1);
  if (iVar1 != 0) {
    BSP_TRACE(4,0x2a,DAT_30063c2c,iVar1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * efuseWriteAt @ 0x3006367C  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, efuseWrite, efuseWriteSetSecEn
 * Константы: 0x3006367C
 * Данные: DAT_30063c2c, DAT_30063c30
 * ---------------------------------------------------------------- */
int efuseWriteAt(void)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_1c = *DAT_30063c30;
  local_18 = DAT_30063c30[1];
  local_14 = DAT_30063c30[2];
  local_10 = DAT_30063c30[3];
  local_c = DAT_30063c30[4];
  iVar1 = efuseWrite(&local_1c,0,5);
  if (iVar1 != 0) {
    BSP_TRACE(4,0x2a,DAT_30063c2c,iVar1);
  }
  iVar1 = efuseWriteSetSecEn();
  if (iVar1 != 0) {
    BSP_TRACE(4,0x2a,DAT_30063c2c,iVar1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * efuseWriteCheck @ 0x30063714  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30063714
 * ---------------------------------------------------------------- */
undefined4 efuseWriteCheck(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (param_2 <= iVar1) {
      return 0;
    }
    if (*(int *)(param_1 + iVar1 * 4) != 0) break;
    iVar1 = iVar1 + 1;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * efuseWriteHUK @ 0x3006375C  (примерный размер ~752 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: efuseRead, efuseWrite, free, logMsg, malloc, memcpy
 * Константы: 0xFFFFFFFF, 0x3006375C
 * Данные: DAT_30063c34, DAT_30063c38, DAT_30063c3c, DAT_30063c40, DAT_30063c44, DAT_30063c48, DAT_30063c4c, DAT_30063c50
 * ---------------------------------------------------------------- */
undefined4 efuseWriteHUK(void *param_1,uint param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_1 == (void *)0x0) || (param_2 == 0)) {
    logMsg(DAT_30063c34,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    for (uVar4 = 0; (uVar4 < param_2 && (*(char *)((int)param_1 + uVar4) == '\0'));
        uVar4 = uVar4 + 1) {
    }
    if (uVar4 < param_2) {
      if (param_2 == 0x10) {
        pvVar2 = malloc(0x10);
        if (pvVar2 == (void *)0x0) {
          logMsg(DAT_30063c40,0,0,0,0,0,0);
          uVar1 = 0xffffffff;
        }
        else {
          iVar3 = efuseRead(0x10,pvVar2,4);
          if (iVar3 == 0) {
            for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1) {
              if (*(int *)((int)pvVar2 + uVar4 * 4) != 0) {
                logMsg(DAT_30063c48,0,0,0,0,0,0);
                free(pvVar2);
                return 0xffffffff;
              }
            }
            iVar3 = efuseWrite(param_1,0x10,4);
            if (iVar3 == 0) {
              free(pvVar2);
              pvVar2 = memcpy(DAT_30063c50,param_1,0x10);
              if (pvVar2 == (void *)0x0) {
                logMsg(DAT_30063c54,0,0,0,0,0,0);
                uVar1 = 0xffffffff;
              }
              else {
                logMsg(DAT_30063c58,0,0,0,0,0,0);
                uVar1 = 0;
              }
            }
            else {
              logMsg(DAT_30063c4c,0,0,0,0,0,0);
              free(pvVar2);
              uVar1 = 0xffffffff;
            }
          }
          else {
            logMsg(DAT_30063c44,0,0,0,0,0,0);
            free(pvVar2);
            uVar1 = 0xffffffff;
          }
        }
      }
      else {
        logMsg(DAT_30063c3c,0x10,0,0,0,0,0);
        uVar1 = 0xffffffff;
      }
    }
    else {
      logMsg(DAT_30063c38,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * CheckHukIsValid @ 0x30063A4C  (примерный размер ~540 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: efuseRead, free, logMsg, malloc
 * Константы: 0x30063A4C
 * Данные: DAT_30063c50, DAT_30063c5c, DAT_30063c60, DAT_30063c64
 * ---------------------------------------------------------------- */
undefined4 CheckHukIsValid(void)

{
  void *__ptr;
  int iVar1;
  uint uVar2;
  
  __ptr = malloc(0x10);
  if (__ptr == (void *)0x0) {
    logMsg(DAT_30063c5c,0,0,0,0,0,0);
  }
  else {
    iVar1 = efuseRead(0x10,__ptr,4);
    if (iVar1 == 0) {
      for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1) {
        if (*(int *)((int)__ptr + uVar2 * 4) != 0) {
          logMsg(DAT_30063c60,0,0,0,0,0,0);
          free(__ptr);
          return 1;
        }
      }
      free(__ptr);
    }
    else {
      free(__ptr);
      for (uVar2 = 0; uVar2 < 0x10; uVar2 = uVar2 + 1) {
        if (*(char *)(DAT_30063c50 + uVar2) != '\0') {
          logMsg(DAT_30063c60,0,0,0,0,0,0);
          return 1;
        }
      }
      logMsg(DAT_30063c64,0,0,0,0,0,0);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * I2C_StatusCheck @ 0x30063CD8  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: BSP_I2C_DataRx, BSP_I2C_DataTx
 * Константы: 0x30063CD8, 0xFFFFFFFF
 * Данные: DAT_30064144, DAT_30064148, DAT_3006414c, DAT_30064150
 * ---------------------------------------------------------------- */
undefined4 I2C_StatusCheck(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar2 = DAT_30064144;
  do {
    iVar3 = iVar2;
    if ((*DAT_30064148 & 1) != 0) break;
    iVar3 = iVar2 + -1;
    bVar4 = iVar2 != 0;
    iVar2 = iVar3;
  } while (bVar4);
  *DAT_3006414c = 0x7f;
  if (iVar3 == 0) {
    logMsg(DAT_30064150,1,2,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sdmmcRegRead @ 0x30064198  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: memcpy, printf
 * Константы: 0x30064198
 * Данные: DAT_30064838, DAT_3006483c
 * ---------------------------------------------------------------- */
void sdmmcRegRead(void *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (param_1 == (void *)0x0) {
    puVar1 = DAT_30064838;
    for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1) {
      printf(DAT_3006483c,puVar1,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      puVar1 = puVar1 + 4;
    }
  }
  else {
    memcpy(param_1,DAT_30064838,0x74);
  }
  return;
}

/* ----------------------------------------------------------------
 * sdmmcCardInfo @ 0x30064208  (примерный размер ~1464 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: memcpy, printf
 * Вызывают: sd_mmc_bus_show
 * Константы: 0x30064208
 * Данные: DAT_30064840, DAT_30064844, DAT_30064848, DAT_3006484c, DAT_30064850, DAT_30064854, DAT_30064858, DAT_3006485c
 * ---------------------------------------------------------------- */
void sdmmcCardInfo(void *param_1)

{
  if (param_1 == (void *)0x0) {
    printf(DAT_30064840,0);
    printf(DAT_30064848,(uint)*DAT_30064844);
    printf(DAT_30064850,(uint)*DAT_3006484c);
    printf(DAT_30064858,*DAT_30064854);
    printf(DAT_30064860,*DAT_3006485c);
    printf(DAT_30064868,*DAT_30064864);
    printf(DAT_30064870,*DAT_3006486c);
    printf(DAT_30064878,*DAT_30064874);
    printf(DAT_30064880,*DAT_3006487c);
    printf(DAT_30064888,*DAT_30064884);
    printf(DAT_30064890,*DAT_3006488c);
    printf(DAT_30064898,*DAT_30064894);
    printf(DAT_300648a0,*DAT_3006489c);
    printf(DAT_300648a8,(uint)*DAT_300648a4);
    printf(DAT_300648b0,(uint)*DAT_300648ac);
    printf(DAT_300648b8,DAT_300648b4);
    printf(DAT_300648c0,(uint)*DAT_300648bc);
    printf(DAT_300648c8,*DAT_300648c4);
    printf(DAT_300648d0,(uint)*DAT_300648cc);
    printf(DAT_300648d8,(uint)*DAT_300648d4);
    printf(DAT_300648e0,(uint)*DAT_300648dc);
    printf(DAT_300648e8,(uint)*DAT_300648e4);
    printf(DAT_300648f0,(uint)*DAT_300648ec);
    printf(DAT_300648f8,(uint)*DAT_300648f4);
    printf(DAT_30064900,(uint)*DAT_300648fc);
    printf(DAT_30064908,(uint)*DAT_30064904);
    printf(DAT_30064910,(uint)*DAT_3006490c);
    printf(DAT_30064918,(uint)*DAT_30064914);
    printf(DAT_30064920,(uint)*DAT_3006491c);
    printf(DAT_30064928,(uint)*DAT_30064924);
    printf(DAT_30064930,(uint)*DAT_3006492c);
    printf(DAT_30064938,(uint)*DAT_30064934);
    printf(DAT_30064940,(uint)*DAT_3006493c);
    printf(DAT_30064948,(uint)*DAT_30064944);
    printf(DAT_30064950,(uint)*DAT_3006494c);
    printf(DAT_30064958,(uint)*DAT_30064954);
    printf(DAT_30064960,(uint)*DAT_3006495c);
    printf(DAT_30064968,(uint)*DAT_30064964);
    printf(DAT_30064970,(uint)*DAT_3006496c);
    printf(DAT_30064978,(uint)*DAT_30064974);
    printf(DAT_30064980,(uint)*DAT_3006497c);
    printf(DAT_30064988,(uint)*DAT_30064984);
    printf(DAT_30064990,(uint)*DAT_3006498c);
    printf(DAT_30064998,(uint)*DAT_30064994);
    printf(DAT_300649a0,(uint)*DAT_3006499c);
    printf(DAT_300649a8,(uint)*DAT_300649a4);
    printf(DAT_300649b0,(uint)*DAT_300649ac);
    printf(DAT_300649b8,(uint)*DAT_300649b4);
    printf(DAT_300649c0,(uint)*DAT_300649bc);
    printf(DAT_300649c8,(uint)*DAT_300649c4);
    printf(DAT_300649d0,(uint)*DAT_300649cc);
    printf(DAT_300649d8,(uint)*DAT_300649d4);
    printf(DAT_300649e0,(uint)*DAT_300649dc);
    printf(DAT_300649e8,(uint)*DAT_300649e4);
    printf(DAT_300649f0,(uint)*DAT_300649ec);
    printf(DAT_300649f8,(uint)*DAT_300649f4);
    printf(DAT_30064a00,*DAT_300649fc);
    printf(DAT_30064a08,(uint)*DAT_30064a04);
    printf(DAT_30064a10,*DAT_30064a0c);
    printf(DAT_30064a14,0x88);
    printf(DAT_30064a18);
  }
  else {
    memcpy(param_1,DAT_30064844,0x88);
  }
  return;
}

/* ----------------------------------------------------------------
 * sdmmc_switch_drive_current @ 0x300647C0  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskDelay
 * Вызывают: Enumerate_SD_card_Stack
 * Константы: 0xFFFFFF03, 0x300647C0
 * Данные: DAT_30064a1c
 * ---------------------------------------------------------------- */
void sdmmc_switch_drive_current(int param_1)

{
  if (param_1 == 0) {
    *DAT_30064a1c = *DAT_30064a1c & 0xffffff03 | 0x1c;
  }
  else {
    *DAT_30064a1c = *DAT_30064a1c & 0xffffff03 | 0xfc;
  }
  taskDelay(10);
  return;
}

/* ----------------------------------------------------------------
 * Enumerate_MMC_Card @ 0x30064814  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30064814
 * ---------------------------------------------------------------- */
undefined4 Enumerate_MMC_Card(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * Increment_Card_Count @ 0x3006481C  (примерный размер ~628 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Enumerate_card
 * Константы: 0x3006481C, 0x30064834
 * Данные: DAT_30064a20
 * ---------------------------------------------------------------- */
void Increment_Card_Count(uint param_1)

{
  if (param_1 < 8) {
                    /* WARNING: Could not recover jumptable at 0x30064834. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_30064a20 + param_1 * 4))();
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * Validate_SD_CMD3_Response @ 0x30064A90  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Initialise_SD
 * Константы: 0x30064A90
 * ---------------------------------------------------------------- */
undefined4 Validate_SD_CMD3_Response(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 & 0xe000) == 0) {
    if (((int)param_1 >> 9 & 0xfU) == 2) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x2f;
    }
  }
  else {
    uVar1 = 0x2f;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Read_Write_FIFO @ 0x30064ACC  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: Read_Write_FIFOdata
 * Вызывают: Send_cmd_to_host_raw, sd_mmc_event_Handler
 * Константы: 0x30064ACC, 0xFFFFFFEA
 * ---------------------------------------------------------------- */
undefined4 Read_Write_FIFO(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = Read_Write_FIFOdata(param_2,param_1,param_3,param_4);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Send_cmd_to_host_raw @ 0x30064B08  (примерный размер ~2324 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 16
 * Вызывает: BSP_TRACE, IDMAC_NoCopyReceive, IDMAC_NoCopySend, IDMAC_alloc_desc_queue, IDMAC_free_desc_queue, OSAL_SemTake, Read_Write_FIFO, Read_Write_IPreg, Send_SD_MMC_Command, Set_IP_Parameters, cacheInvalidate, logMsg, memcpy, semGive
 *           ...
 * Вызывают: Send_cmd_to_host
 * Константы: 0x30064B08, 0xFFFFFFFF, 0x02000000, 0xFFFFF000, 0x00800000
 * Данные: DAT_300655e8, DAT_300655ec, DAT_300655f0, DAT_300655f4, DAT_300655f8, DAT_300655fc, DAT_30065600, DAT_30065604
 * ---------------------------------------------------------------- */
uint Send_cmd_to_host_raw
               (size_t *param_1,undefined4 param_2,undefined4 param_3,void *param_4,int param_5,
               undefined4 param_6,undefined4 param_7,int param_8,int param_9,undefined4 param_10)

{
  int iVar1;
  size_t __n;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint local_70;
  uint local_6c;
  void *local_68;
  void *local_64;
  void *local_60;
  void *local_5c;
  uint local_58;
  void *local_54;
  void *local_50;
  void *local_4c;
  void *local_48;
  void *local_44;
  int local_40;
  int local_3c;
  void *local_38;
  undefined1 auStack_34 [4];
  undefined4 local_30;
  
  uVar4 = 0;
  local_30 = 0;
  uVar3 = 0;
  local_6c = 0;
  puVar2 = *(undefined4 **)(*DAT_300655e8 + 4);
  local_3c = 0;
  semTake(*DAT_300655ec,0xffffffff);
  if (*DAT_300655f0 == 0) {
    if ((DAT_300655f4[5] == 0) || ((param_1[3] & 0x4000) != 0)) {
      *DAT_300655f8 = param_4;
      DAT_300655f8[1] = param_2;
      DAT_300655f8[2] = param_3;
      DAT_300655f8[3] = param_6;
      DAT_300655f8[4] = 0;
      DAT_300655f8[5] = 1;
      DAT_300655f8[6] = 0;
      DAT_300655f8[7] = param_1[3] >> 7 & 1;
      if (param_8 != 0) {
        if ((*(int *)(*DAT_300655e8 + 0x40) != 0) && (*(int *)(*DAT_300655e8 + 0x44) != 0)) {
          if (((uint)param_4 & 0x1f) == 0) {
            uVar3 = *param_1 + DAT_300655fc >> 0xc;
          }
          else {
            local_44 = param_4;
            if (((uint)param_4 & 0x1f) != 0) {
              local_44 = (void *)((int)param_4 + (0x20 - ((uint)param_4 & 0x1f)));
            }
            if ((uint)((int)local_44 - (int)param_4) < *param_1) {
              local_48 = param_4;
              if (((uint)param_4 & 0x1f) != 0) {
                local_48 = (void *)((int)param_4 + (0x20 - ((uint)param_4 & 0x1f)));
              }
              local_40 = *param_1 - ((int)local_48 - (int)param_4);
            }
            else {
              local_40 = 0;
            }
            uVar3 = ((uint)(local_40 + DAT_300655fc) >> 0xc) + 1;
          }
          if ((puVar2[6] == 0) || ((uint)puVar2[2] < uVar3)) {
            iVar1 = IDMAC_alloc_desc_queue(puVar2,uVar3 + 1);
            if (iVar1 == 0) {
              puVar2[8] = 0;
              puVar2[7] = 1;
              puVar2[6] = 0;
              *DAT_30065600 = *puVar2;
            }
            else {
              puVar2[8] = 1;
              puVar2[7] = 0;
            }
          }
          else {
            puVar2[8] = 0;
            puVar2[7] = 0;
          }
        }
        if (((*(int *)(*DAT_300655e8 + 0x40) == 0) || (*(int *)(*DAT_300655e8 + 0x44) == 0)) ||
           (puVar2[8] != 0)) {
          BSP_TRACE(2,0xd,DAT_30065608,1,2,3,4,5,6);
          transfer_mode_config(0);
        }
        else {
          BSP_TRACE(2,0xd,DAT_30065604,1,2,3,4,5,6);
          transfer_mode_config(1);
        }
        Set_IP_Parameters(0xf,auStack_34);
        Read_Write_IPreg(0,&local_70,0);
        local_70 = local_70 & 0x2000000;
        if ((param_9 != 0) && (local_70 == 0)) {
          local_3c = Read_Write_FIFO(param_4,*param_1,param_9,param_10);
        }
        *DAT_300655f4 = param_4;
        DAT_300655f4[1] = param_9;
        DAT_300655f4[2] = *param_1;
        if (param_9 == 0) {
          DAT_300655f4[3] = *param_1;
        }
        else {
          DAT_300655f4[3] = *param_1 - local_3c;
        }
        DAT_300655f4[4] = param_6;
        DAT_300655f4[5] = 1;
        DAT_300655f4[6] = param_5;
        DAT_300655f4[7] = param_10;
        DAT_300655f4[8] = 0;
        if (((local_70 != 0) && (*(int *)(*DAT_300655e8 + 0x40) != 0)) &&
           (*(int *)(*DAT_300655e8 + 0x44) != 0)) {
          DAT_300655f4[3] = 0;
          *DAT_3006560c = DAT_30065610;
          if (param_9 == 0) {
            IDMAC_NoCopyReceive(puVar2,param_4,*param_1,uVar3);
          }
          else {
            IDMAC_NoCopySend(puVar2,param_4,*param_1,uVar3);
          }
        }
      }
      local_70 = 0;
      Read_Write_IPreg(0x44,&local_70,0);
      local_70 = local_70 & DAT_30065614;
      Read_Write_IPreg(0x44,&local_70,1);
      iVar1 = Send_SD_MMC_Command(param_1);
      if (iVar1 == 0) {
        uVar3 = 0;
        do {
          if (DAT_300655f8[5] == 0) {
            if ((param_8 != 0) && (param_5 == 0)) {
              iVar1 = OSAL_SemTake(*DAT_3006561c,500);
              if (iVar1 == 0) {
                if (((*(int *)(*DAT_300655e8 + 0x40) != 0) && (*(int *)(*DAT_300655e8 + 0x44) != 0))
                   && (param_9 == 0)) {
                  if (((uint)param_4 & 0x1f) == 0) {
                    cacheInvalidate(1,param_4,*param_1);
                    if (*(int *)(DAT_30065624 + 0x20) != 0) {
                      (**(code **)(DAT_30065624 + 0x20))();
                    }
                  }
                  else {
                    local_4c = param_4;
                    if (((uint)param_4 & 0x1f) != 0) {
                      local_4c = (void *)((int)param_4 + (0x20 - ((uint)param_4 & 0x1f)));
                    }
                    if ((uint)((int)local_4c - (int)param_4) < *param_1) {
                      local_50 = param_4;
                      if (((uint)param_4 & 0x1f) != 0) {
                        local_50 = (void *)((int)param_4 + (0x20 - ((uint)param_4 & 0x1f)));
                      }
                      cacheInvalidate(1,puVar2[5],(int)local_50 - (int)param_4);
                      if (*(int *)(DAT_30065624 + 0x20) != 0) {
                        (**(code **)(DAT_30065624 + 0x20))();
                      }
                      local_54 = param_4;
                      if (((uint)param_4 & 0x1f) != 0) {
                        local_54 = (void *)((int)param_4 + (0x20 - ((uint)param_4 & 0x1f)));
                      }
                      memcpy(param_4,(void *)puVar2[5],(int)local_54 - (int)param_4);
                      local_5c = param_4;
                      if (((uint)param_4 & 0x1f) != 0) {
                        local_5c = (void *)((int)param_4 + (0x20 - ((uint)param_4 & 0x1f)));
                      }
                      if ((uint)((int)local_5c - (int)param_4) < *param_1) {
                        local_60 = param_4;
                        if (((uint)param_4 & 0x1f) != 0) {
                          local_60 = (void *)((int)param_4 + (0x20 - ((uint)param_4 & 0x1f)));
                        }
                        local_58 = *param_1 - ((int)local_60 - (int)param_4);
                      }
                      else {
                        local_58 = 0;
                      }
                      local_6c = local_58 & 0xfffff000;
                      if (local_6c != 0) {
                        local_64 = param_4;
                        if (((uint)param_4 & 0x1f) != 0) {
                          local_64 = (void *)((int)param_4 + (0x20 - ((uint)param_4 & 0x1f)));
                        }
                        cacheInvalidate(1,local_64,local_6c);
                        if (*(int *)(DAT_30065624 + 0x20) != 0) {
                          (**(code **)(DAT_30065624 + 0x20))();
                        }
                      }
                      local_68 = param_4;
                      if (((uint)param_4 & 0x1f) != 0) {
                        local_68 = (void *)((int)param_4 + (0x20 - ((uint)param_4 & 0x1f)));
                      }
                      __n = (*param_1 - ((int)local_68 - (int)param_4)) - local_6c;
                      if (__n != 0) {
                        local_38 = (void *)((int)param_4 + (*param_1 - __n));
                        cacheInvalidate(1,puVar2[9],__n);
                        if (*(int *)(DAT_30065624 + 0x20) != 0) {
                          (**(code **)(DAT_30065624 + 0x20))();
                        }
                        memcpy(local_38,(void *)puVar2[9],__n);
                      }
                    }
                    else {
                      cacheInvalidate(1,puVar2[5],*param_1);
                      if (*(int *)(DAT_30065624 + 0x20) != 0) {
                        (**(code **)(DAT_30065624 + 0x20))();
                      }
                      memcpy(param_4,(void *)puVar2[5],*param_1);
                    }
                  }
                }
              }
              else {
                logMsg(DAT_30065620);
                DAT_300655f4[8] = 0x6f;
              }
            }
            goto LAB_3006534c;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < 0x800000);
        logMsg(DAT_30065618);
        DAT_300655f8[6] = 0x59;
      }
      else {
        uVar3 = 0x42;
      }
LAB_3006534c:
      uVar3 = uVar3 | DAT_300655f4[8] | DAT_300655f8[4];
      DAT_300655f8[5] = 0;
      DAT_300655f4[5] = 0;
      if (*(int *)(*DAT_300655e8 + 0x44) != 0) {
        if (puVar2[7] != 0) {
          IDMAC_free_desc_queue(puVar2);
        }
        if ((puVar2[6] == 0) && (iVar1 = IDMAC_alloc_desc_queue(puVar2,DAT_30065628), iVar1 == 0)) {
          puVar2[6] = 1;
          *DAT_30065600 = *puVar2;
        }
      }
      if (uVar3 != 0) {
        logMsg(DAT_3006562c,uVar3,param_1[3],param_1[2],*param_1);
      }
      semGive(*DAT_300655ec);
    }
    else {
      semGive(*DAT_300655ec);
      uVar3 = 0x59;
    }
  }
  else {
    semGive(*DAT_300655ec);
    uVar3 = 0x5c;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * Send_cmd_to_host @ 0x3006541C  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 13 | Вызывает: 2
 * Вызывает: Send_cmd_to_host_raw, logMsg
 * Вызывают: Blksize_Data_Transfer, Card_Lock, Form_Send_Cmd, Get_WrProtect_Status, HSSD_Send_CMD6, Partial_Blk_Xfer, Read_SD_Reg, Read_Write_StreamData, Resume_Transfer, SDIO_RdWr_Extended
 *           ...
 * Константы: 0x3006541C
 * Данные: DAT_30065630
 * ---------------------------------------------------------------- */
undefined4
Send_cmd_to_host(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,int param_7,undefined4 param_8,
                undefined4 param_9,undefined4 param_10)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_7;
  if (param_7 == 0) {
    iVar3 = 3;
  }
  iVar4 = 0;
  uVar2 = param_1;
  while( true ) {
    if (iVar3 <= iVar4) {
      return uVar2;
    }
    iVar1 = Send_cmd_to_host_raw
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10);
    if (iVar1 == 0) break;
    uVar2 = logMsg(DAT_30065630,iVar1);
    iVar4 = iVar4 + 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * Form_Send_Cmd @ 0x300654DC  (примерный размер ~1464 байт)
 * Модуль: data | Вызывают: 20 | Вызывает: 2
 * Вызывает: Send_cmd_to_host, printf
 * Вызывают: Abort_transfer, Blksize_Data_Transfer, Check_TranState, Enumerate_card, Erase_Card_Data, Identify_Card_Type, Initialise_SD, Read_Write_BlkData, Read_Write_StreamData, Resume_Transfer
 *           ...
 * Константы: 0xFFE0C0C0, 0x300654DC, 0xFFFFBF7F, 0xFFDFFFFF, 0x80008000, 0xFFDF7FFF, 0x80000000, 0x20000000
 * Данные: DAT_30065634, DAT_30065638, DAT_3006563c, DAT_30066284
 * ---------------------------------------------------------------- */
undefined4
Form_Send_Cmd(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  
  local_38 = *DAT_30065634;
  local_34 = DAT_30065634[1];
  local_2c = DAT_30065634[3];
  if (0xf < (int)param_1) {
    return 0x36;
  }
  if (param_2 != 5) {
    if ((int)param_2 < 6) {
      if (((param_2 != 0) && (param_2 != 1)) && ((param_2 != 2 && (param_2 != 3)))) {
LAB_30065598:
        if (*(int *)(DAT_30065638 + param_1 * 0x88) != 1) {
          return 0x37;
        }
      }
    }
    else if ((((param_2 != 8) && (param_2 != 0x29)) && (param_2 != 0x37)) && (param_2 != 100))
    goto LAB_30065598;
  }
  local_30 = 0;
  if (param_2 == 100) {
LAB_30065784:
    uVar5 = local_2c & 0xffffbf7f;
    local_2c = uVar5 | 0x40;
    if (param_2 == 0x65) {
      local_2c = uVar5 | 0x4040;
    }
    if ((param_2 == 0) || (param_2 == 100)) {
      local_2c = local_2c & 0xffdfffff | 0x80008000;
    }
    else {
      local_2c = local_2c & 0xffdf7fff | 0x80000000;
    }
    local_38 = 0;
    local_34 = 0;
    uVar5 = (uint)(param_2 == 0x34) << 0xc;
    uVar1 = (param_1 & 0x1f) << 0x10;
    uVar2 = (param_5 >> 1 & 1) << 0xd;
    uVar3 = (param_5 >> 2 & 1) << 8;
    if ((param_2 == 100) || (param_2 == 0x65)) {
      local_2c = local_2c & 0xffe0c0c0 | uVar5 | uVar1 | uVar2 | uVar3 | 0x34;
    }
    else {
      local_2c = local_2c & 0xffe0c0c0 | uVar5 | uVar1 | uVar2 | uVar3 | param_2 & 0x3f;
    }
    local_2c = local_2c | 0x20000000;
    local_30 = param_3;
    uVar4 = Send_cmd_to_host(&local_38,param_4,0,0,0,0,0,0,0,0);
  }
  else {
    if ((int)param_2 < 0x65) {
      if (param_2 < 0x39) {
                    /* WARNING: Could not recover jumptable at 0x300655e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar4 = (**(code **)(DAT_3006563c + param_2 * 4))();
        return uVar4;
      }
    }
    else if (param_2 == 0x65) goto LAB_30065784;
    printf(DAT_30066284);
    uVar4 = 0x44;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * Send_ACMD41 @ 0x30065A94  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: Form_Send_Cmd
 * Вызывают: Identify_Card_Type, Initialise_SD
 * Константы: 0x30065A94
 * ---------------------------------------------------------------- */
int Send_ACMD41(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_18 [4];
  
  iVar1 = Form_Send_Cmd(param_1,0x37,0,auStack_18,1);
  if (iVar1 == 0) {
    iVar1 = Form_Send_Cmd(param_1,0x29,param_2,param_3,0);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Validate_Response @ 0x30065B00  (примерный размер ~316 байт)
 * Модуль: data | Вызывают: 21 | Вызывает: 4
 * Вызывает: Unpack_CMD52_Resp, mmc_unpack_cid, mmc_unpack_r1, unpack_csd
 * Вызывают: Abort_transfer, Blksize_Data_Transfer, Card_Lock, Check_TranState, Enumerate_card, Erase_Card_Data, Get_WrProtect_Status, HSSD_Send_CMD6, Initialise_SD, Partial_Blk_Xfer
 *           ...
 * Константы: 0x30065B00, 0xFFFFFFEA
 * Данные: DAT_30066288, DAT_3006628c, DAT_30066290, DAT_30066294
 * ---------------------------------------------------------------- */
undefined4 Validate_Response(int param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0xffffffea;
  }
  if (param_1 == 0x27) {
    return 0;
  }
  if (param_1 < 0x28) {
    if (param_1 == 1) {
      *(undefined4 *)(param_3 * 0x88 + DAT_30066288) = *param_2;
      return 0;
    }
    if (param_1 != 2) {
      if (param_1 == 9) {
        if (*(char *)(DAT_3006628c + param_3 * 0x88) == '\0') {
          uVar1 = unpack_csd(param_2,param_3 * 0x88 + DAT_30066290,0);
          return uVar1;
        }
        uVar1 = unpack_csd(param_2,param_3 * 0x88 + DAT_30066290,1);
        return uVar1;
      }
      if (param_1 != 10) goto LAB_30065c24;
    }
    uVar1 = mmc_unpack_cid(param_2,DAT_30066294 + param_3 * 0x88);
  }
  else {
    if (param_1 == 0x28) {
      return 0;
    }
    if ((param_1 == 0x34) || (param_1 == 0x35)) {
      uVar1 = Unpack_CMD52_Resp(param_2);
      return uVar1;
    }
LAB_30065c24:
    uVar1 = mmc_unpack_r1(param_2,param_4);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Initialise_SD @ 0x30065C3C  (примерный размер ~996 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: Form_Send_Cmd, Send_ACMD41, Validate_Response, Validate_SD_CMD3_Response, logMsg, printf, taskDelay
 * Вызывают: Enumerate_card
 * Константы: 0x80000000, 0x30065C3C, 0x40000000
 * Данные: DAT_30066280, DAT_3006628c, DAT_30066298, DAT_3006629c, DAT_300662a0, DAT_300662a4, DAT_300662a8, DAT_300662ac
 * ---------------------------------------------------------------- */
int Initialise_SD(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  undefined1 auStack_28 [16];
  
  iVar2 = -1;
  *(undefined1 *)(param_1 * 0x88 + DAT_3006628c) = 1;
  for (iVar4 = 0; iVar4 < 0xf; iVar4 = iVar4 + 1) {
    iVar2 = Form_Send_Cmd(param_1,0,0,&local_30,1);
    if (iVar2 == 0) break;
    for (local_38 = 0; local_38 < DAT_30066298; local_38 = local_38 + 1) {
    }
  }
  if ((0xe < iVar4) || (iVar2 != 0)) {
    iVar2 = 0x2c;
    goto LAB_30066008;
  }
  iVar2 = 0;
  for (iVar4 = 0; iVar4 < 8; iVar4 = iVar4 + 1) {
    iVar2 = Form_Send_Cmd(param_1,8,DAT_3006629c,&local_30,1);
    if (iVar2 == 0) break;
    for (local_38 = 0; local_38 < DAT_30066298; local_38 = local_38 + 1) {
    }
  }
  uVar1 = DAT_300662ac;
  if (iVar4 < 8) {
    if ((local_30 & DAT_300662a8) != DAT_3006629c) goto LAB_30066008;
    for (iVar4 = 0; iVar4 < 0x19; iVar4 = iVar4 + 1) {
      local_34 = 0;
      iVar2 = Send_ACMD41(param_1,uVar1,&local_34);
      if ((iVar2 == 0) && ((local_34 & 0x80000000) != 0)) break;
      taskDelay(2);
    }
    if ((0x18 < iVar4) || (iVar2 != 0)) {
      iVar2 = 0x34;
      goto LAB_30066008;
    }
    iVar2 = 0;
    if ((local_34 & 0x40000000) != 0) {
      *(undefined1 *)(param_1 * 0x88 + DAT_3006628c) = 8;
    }
  }
  else {
    local_34 = 0;
    iVar2 = Send_ACMD41(param_1,0,&local_34);
    if (iVar2 != 0) {
      printf(DAT_300662a0);
    }
    local_34 = local_34 & DAT_300662a4;
    uVar3 = local_34 | 0x80000000;
    for (iVar4 = 0; iVar4 < 0x19; iVar4 = iVar4 + 1) {
      local_34 = 0;
      iVar2 = Send_ACMD41(param_1,uVar3,&local_34);
      if ((iVar2 == 0) && ((local_34 & 0x80000000) != 0)) break;
      taskDelay(2);
    }
    if ((0x18 < iVar4) || (iVar2 != 0)) {
      iVar2 = 0x34;
      goto LAB_30066008;
    }
  }
  for (iVar4 = 0; iVar4 < 0xf; iVar4 = iVar4 + 1) {
    iVar2 = Form_Send_Cmd(param_1,2,0,auStack_28,1);
    if ((iVar2 == 0) || (iVar2 != 0x42)) break;
    for (local_38 = 0; local_38 < DAT_30066298; local_38 = local_38 + 1) {
    }
  }
  if ((iVar4 < 0xf) && (iVar2 != 0x100)) {
    if (iVar2 == 0) {
      iVar2 = Validate_Response(2,auStack_28,param_1,0xff);
    }
    for (iVar4 = 0; iVar4 < 0xf; iVar4 = iVar4 + 1) {
      iVar2 = Form_Send_Cmd(param_1,3,param_2,&local_2c,1);
      if ((iVar2 == 0) || (iVar2 != 0x42)) break;
      for (local_38 = 0; local_38 < DAT_30066298; local_38 = local_38 + 1) {
      }
    }
    if ((iVar2 == 0) && (iVar2 = Validate_SD_CMD3_Response(local_2c & 0xffff), iVar2 == 0)) {
      *(uint *)(DAT_30066280 + param_1 * 0x88) = local_2c >> 0x10;
    }
  }
  else {
    iVar2 = 0x2e;
  }
LAB_30066008:
  logMsg(DAT_300662b0,iVar2);
  return iVar2;
}

/* ----------------------------------------------------------------
 * Initialise_SDIO @ 0x30066020  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30066020
 * ---------------------------------------------------------------- */
undefined4 Initialise_SDIO(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * Send_SDIO_DummyRead @ 0x30066028  (примерный размер ~208 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: Form_Send_Cmd
 * Вызывают: SDIO_RdWr_Extended
 * Константы: 0x30066028
 * Данные: DAT_300662b4
 * ---------------------------------------------------------------- */
undefined4 Send_SDIO_DummyRead(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
  local_10 = *DAT_300662b4;
  local_f = DAT_300662b4[1];
  local_e = DAT_300662b4[2];
  local_d = DAT_300662b4[3];
  iVar1 = Form_Send_Cmd(param_1,0x34,0,&local_10,0);
  if (iVar1 == 0) {
    *param_2 = local_f;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x21;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * Form_SDIO_CmdReg @ 0x300660F8  (примерный размер ~300 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: Resume_Transfer, SDIO_RdWr_Extended
 * Константы: 0x300660F8, 0x80000000, 0xFFDFFFFF, 0xFFE0FFFF, 0xFFFF7FFF, 0xFFFFBFFF, 0xFFFFDFFF, 0xFFFFEFFF
 * ---------------------------------------------------------------- */
undefined4 Form_SDIO_CmdReg(int param_1,uint param_2,uint param_3,uint param_4)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x80000000;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffdfffff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffe0ffff | (param_2 & 0x1f) << 0x10;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffff7fff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffbfff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffdfff | (param_4 >> 1 & 1) << 0xd;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffefff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffff7ff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffbff | (param_4 >> 7 & 1) << 10;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x200;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffeff | (param_4 >> 2 & 1) << 8;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffff7f;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x40;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffc0 | param_3 & 0x3f;
  return 0;
}

/* ----------------------------------------------------------------
 * Validate_Command @ 0x30066224  (примерный размер ~816 байт)
 * Модуль: data | Вызывают: 22 | Вызывает: 0
 * Вызывают: Abort_transfer, Card_Lock, Change_PwrMode_ForFunction, Change_SDIO_BlkSize, Enable_Disable_SDIOFunction, Enable_Disable_SDIOIRQ, Enable_MasterPwrControl_Mode, Erase_Card_Data, Get_Data_fromTuple, Get_WrProtect_Status
 *           ...
 * Константы: 0x30066224, 0x3006627C
 * Данные: DAT_300662bc, DAT_300662c0
 * ---------------------------------------------------------------- */
undefined4 Validate_Command(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 < 0x10) {
    if (*(int *)(DAT_300662bc + param_1 * 0x88) == 1) {
      if (param_4 - 10U < 9) {
                    /* WARNING: Could not recover jumptable at 0x3006627c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (**(code **)(DAT_300662c0 + (param_4 - 10U) * 4))();
        return uVar1;
      }
      uVar1 = 0;
    }
    else {
      uVar1 = 0x37;
    }
  }
  else {
    uVar1 = 0x36;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * SDIO_RdWr_Extended @ 0x30066554  (примерный размер ~800 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 7
 * Вызывает: Form_SDIO_CmdReg, Send_SDIO_DummyRead, Send_cmd_to_host, Validate_Command, Validate_Response, __udiv32, __urem32
 * Вызывают: Change_SDIO_BlkSize, Get_Data_fromTuple, Suspend_Transfer
 * Константы: 0x30066554, 0x03FFFFFF
 * Данные: DAT_3006751c, DAT_30067520, DAT_30067524, DAT_30067528, DAT_3006752c, DAT_30067530, DAT_30067534
 * ---------------------------------------------------------------- */
int SDIO_RdWr_Extended(int param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,
                      undefined4 param_6,undefined4 param_7,uint param_8,undefined4 param_9,
                      undefined4 param_10,int param_11)

{
  int iVar1;
  uint uVar2;
  byte local_54 [4];
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  local_38 = *DAT_3006751c;
  local_34 = DAT_3006751c[1];
  local_30 = DAT_3006751c[2];
  local_2c = DAT_3006751c[3];
  local_54[0] = 0;
  iVar1 = Validate_Command(param_1,0,param_2,0x10);
  if (iVar1 == 0) {
    if (param_4 == 0) {
      iVar1 = -0x16;
    }
    else {
      uVar2 = param_4;
      if ((param_8 & 2) != 0) {
        if ((*(byte *)(DAT_30067520 + param_1 * 0x88) & 2) == 0) {
          return 0x3a;
        }
        if (*(short *)(DAT_30067524 + param_2 * 2 + param_1 * 0x88) == 0) {
          return -0x16;
        }
        uVar2 = __udiv32(param_4,*(undefined2 *)(DAT_30067524 + param_2 * 2 + param_1 * 0x88));
        iVar1 = __urem32(param_4,*(undefined2 *)(DAT_30067524 + param_2 * 2 + param_1 * 0x88));
        if (iVar1 != 0) {
          return 0x3b;
        }
      }
      local_44 = param_8 & 1;
      local_48 = (int)param_8 >> 1 & 1;
      local_50 = ((local_50 & DAT_30067528 | uVar2 & DAT_3006752c) & DAT_30067530 |
                 (param_3 & DAT_30067534) << 9) & 0x3ffffff | local_44 << 0x1a | local_48 << 0x1b |
                 (param_2 & 7) << 0x1c | (param_11 >> 7) << 0x1f;
      local_34 = param_4;
      if ((param_8 & 2) != 0) {
        local_34 = (uint)*(ushort *)(DAT_30067524 + param_2 * 2 + param_1 * 0x88);
      }
      local_4c = param_2;
      local_40 = param_3;
      local_3c = uVar2;
      local_38 = param_4;
      local_30 = local_50;
      Form_SDIO_CmdReg(&local_38,param_1,0x35,param_11);
      iVar1 = Send_cmd_to_host(&local_38,param_6,param_7,param_5,0,param_11,param_10,1,
                               local_50 >> 0x1f,param_11 >> 6 & 1);
      if (((iVar1 == 0) && (iVar1 = Validate_Response(0x35,param_6,param_1,0xff), iVar1 == 0)) &&
         (iVar1 = Send_SDIO_DummyRead(param_1,local_54), iVar1 == 0)) {
        if ((local_54[0] & 8) == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = 0x29;
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Enumerate_card @ 0x30066874  (примерный размер ~1476 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: Form_Send_Cmd, Increment_Card_Count, Initialise_SD, Set_IP_Parameters, Validate_Response, printf
 * Вызывают: Enumerate_SD_card_Stack, Enumerate_Single_Card
 * Константы: 0x30066874, 0x300668DC, 0x300668D0, 0x300668D8, 0x3006690C, 0x30066C68, 0x30066DA0, 0x30066CC8
 * Данные: DAT_300672cc, DAT_300672d0, DAT_300676fc, DAT_30067700, DAT_30067840, DAT_30067844, DAT_30067848, DAT_3006784c
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300668dc) */
/* WARNING: Removing unreachable block (ram,0x300668d0) */
/* WARNING: Removing unreachable block (ram,0x300668d8) */
/* WARNING: Removing unreachable block (ram,0x3006690c) */
/* WARNING: Removing unreachable block (ram,0x30066c68) */
/* WARNING: Removing unreachable block (ram,0x30066da0) */
/* WARNING: Removing unreachable block (ram,0x30066cc8) */
/* WARNING: Removing unreachable block (ram,0x30066cf0) */
/* WARNING: Removing unreachable block (ram,0x30066d04) */
/* WARNING: Removing unreachable block (ram,0x30066d0c) */
/* WARNING: Removing unreachable block (ram,0x30066d8c) */
/* WARNING: Removing unreachable block (ram,0x30066d70) */
/* WARNING: Removing unreachable block (ram,0x30066d98) */

int Enumerate_card(int param_1)

{
  int iVar1;
  int iVar2;
  uint local_40;
  int local_3c;
  undefined1 auStack_38 [36];
  
  iVar2 = *DAT_300676fc;
  *(undefined4 *)(param_1 * 0x88 + DAT_30067700) = 1;
  local_3c = param_1;
  Set_IP_Parameters(6,&local_3c);
  iVar2 = Initialise_SD(param_1,iVar2 + 1);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 * 0x88 + DAT_30067840) = 1;
    *(undefined4 *)(param_1 * 0x88 + DAT_30067844) = 1;
    Increment_Card_Count(1);
    iVar2 = Form_Send_Cmd(param_1,9,0,auStack_38,1);
    if ((iVar2 == 0) && (iVar2 = Validate_Response(9,auStack_38,param_1,0xff), iVar2 == 0)) {
      if (*(char *)(DAT_300672d0 + param_1 * 0x88) == '\x01') {
        if (*(uint *)(DAT_3006784c + 0x1c) < (uint)*(byte *)(DAT_30067848 + param_1 * 0x88)) {
          *(uint *)(DAT_3006784c + 0x1c) = (uint)*(byte *)(DAT_30067848 + param_1 * 0x88);
        }
        if (*(uint *)(DAT_3006784c + 0x20) < (uint)*(byte *)(DAT_30067850 + param_1 * 0x88)) {
          *(uint *)(DAT_3006784c + 0x20) = (uint)*(byte *)(DAT_30067850 + param_1 * 0x88);
        }
        if (*(byte *)(DAT_30067914 + param_1 * 0x88) < 10) {
          *(int *)(DAT_30067918 + param_1 * 0x88) = 1 << *(sbyte *)(DAT_30067914 + param_1 * 0x88);
        }
        else {
          *(undefined4 *)(param_1 * 0x88 + DAT_30067918) = 0x200;
        }
        if (*(byte *)(DAT_3006791c + param_1 * 0x88) < 10) {
          *(int *)(DAT_30067920 + param_1 * 0x88) = 1 << *(sbyte *)(DAT_3006791c + param_1 * 0x88);
        }
        else {
          *(undefined4 *)(param_1 * 0x88 + DAT_30067920) = 0x200;
        }
        *(uint *)(DAT_300672cc + param_1 * 0x88) =
             (1 << *(sbyte *)(DAT_30067914 + param_1 * 0x88)) *
             (1 << (*(byte *)(DAT_300679d0 + param_1 * 0x88) + 2 & 0xff)) *
             (*(ushort *)(DAT_30067924 + param_1 * 0x88) + 1);
        *DAT_300679d4 = 0;
        *DAT_300679d4 = *(uint *)(DAT_300672cc + param_1 * 0x88) >> 10;
        printf(DAT_300679d8,*(uint *)(DAT_300672cc + param_1 * 0x88) >> 10);
      }
      else {
        *(undefined4 *)(param_1 * 0x88 + DAT_30067918) = 0x200;
        *(undefined4 *)(param_1 * 0x88 + DAT_30067920) = 0x200;
        *(uint *)(DAT_300672cc + param_1 * 0x88) =
             (uint)*(ushort *)(DAT_30067924 + param_1 * 0x88) * 0x400 + 0x400;
        *DAT_300679d4 = 0;
        *DAT_300679d4 = *(uint *)(DAT_300672cc + param_1 * 0x88) >> 10;
        printf(DAT_30067b14,*(uint *)(DAT_300672cc + param_1 * 0x88) >> 1);
      }
    }
  }
  if (iVar2 == 0) {
    *DAT_300676fc = *DAT_300676fc + 1;
    iVar1 = Form_Send_Cmd(param_1,0xd,0,&local_40,1);
    if ((iVar1 == 0) && ((local_40 & 0x2000000) != 0)) {
      *(uint *)(DAT_30067bd4 + param_1 * 0x88) = *(uint *)(DAT_30067bd4 + param_1 * 0x88) | 4;
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * Assign_Clk_Sources @ 0x30066E38  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Set_default_Clk
 * Константы: 0x30066E38
 * Данные: DAT_300672d0, DAT_30067840
 * ---------------------------------------------------------------- */
uint Assign_Clk_Sources(uint param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = param_3;
  for (uVar1 = 0; (int)uVar1 < 0x10; uVar1 = uVar1 + 1) {
    if (((*(byte *)(DAT_300672d0 + uVar1 * 0x88) == param_1) ||
        ((*(byte *)(DAT_300672d0 + uVar1 * 0x88) & 4) == param_2)) &&
       (*(int *)(DAT_30067840 + uVar1 * 0x88) == 1)) {
      param_5 = param_5 | iVar3 << ((uVar1 & 0x7f) << 1);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 1;
      if (iVar2 == param_4) {
        iVar2 = 0;
        iVar3 = param_3;
      }
    }
  }
  return param_5;
}

/* ----------------------------------------------------------------
 * Set_default_Clk @ 0x30066EF4  (примерный размер ~524 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: Assign_Clk_Sources, Read_Write_IPreg
 * Вызывают: Enumerate_SD_card_Stack
 * Константы: 0x30066EF4, 0xFFFFFFFF
 * Данные: DAT_30067840, DAT_3006784c, DAT_30067e80
 * ---------------------------------------------------------------- */
undefined4 Set_default_Clk(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_30;
  undefined4 local_2c;
  uint local_28;
  
  iVar5 = *(int *)(DAT_3006784c + 8);
  iVar4 = *(int *)(DAT_3006784c + 0xc) + *(int *)(DAT_3006784c + 0x10);
  if ((iVar5 == 0) && (iVar4 == 0)) {
    uVar1 = 0x4d;
  }
  else {
    iVar2 = iVar5;
    if ((2 < iVar5) && (iVar2 = 2, iVar4 < 2)) {
      iVar2 = 4 - iVar4;
    }
    iVar6 = 4 - iVar2;
    if (iVar4 < iVar6) {
      iVar6 = iVar4;
    }
    if (iVar5 < iVar2) {
      iVar2 = iVar5;
    }
    local_2c = 0;
    if (iVar6 != 0) {
      local_2c = Assign_Clk_Sources(1,4,0,iVar6,0);
    }
    if (iVar2 != 0) {
      local_2c = Assign_Clk_Sources(0,0xffffffff,iVar6,iVar2,local_2c);
    }
    Read_Write_IPreg(0xc,&local_2c,1);
    local_28 = 1;
    for (uVar3 = 0; (int)uVar3 < iVar6; uVar3 = uVar3 + 1) {
      local_28 = local_28 | 1 << ((uVar3 & 0x1f) << 3);
    }
    for (iVar4 = 0; iVar4 < iVar2; iVar4 = iVar4 + 1) {
      local_28 = local_28 | 2 << ((iVar4 + iVar6) * 8 & 0xffU);
    }
    Read_Write_IPreg(8,&local_28,1);
    local_30 = 0;
    for (uVar3 = 0; (int)uVar3 < 0x10; uVar3 = uVar3 + 1) {
      if (*(int *)(DAT_30067840 + uVar3 * 0x88) == 1) {
        local_30 = local_30 | 1 << (uVar3 & 0xff);
      }
    }
    Read_Write_IPreg(0x10,&local_30,1);
    local_30 = DAT_30067e80;
    Read_Write_IPreg(0x2c,&local_30,1);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Clk_Enable_Disable @ 0x30067100  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: Clk_Enable
 * Вызывают: Enumerate_SD_card_Stack, Enumerate_Single_Card, sdmmcISRInit, sdmmcStatusPollTask
 * Константы: 0x30067100
 * ---------------------------------------------------------------- */
undefined4 Clk_Enable_Disable(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((param_1 < 0x10) || (param_1 == 0xff)) {
    uVar1 = Clk_Enable(param_1,param_2);
  }
  else {
    uVar1 = 0x36;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Set_Clk_Frequency @ 0x30067134  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: Set_ClkDivider_Freq
 * Вызывают: Enumerate_SD_card_Stack, Enumerate_Single_Card, sdmmcISRInit, sdmmcStatusPollTask
 * Константы: 0x30067134, 0xFFFFFFEA
 * Данные: DAT_3006784c
 * ---------------------------------------------------------------- */
undefined4 Set_Clk_Frequency(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    if ((int)param_2 < 0x100) {
      if (param_3 == 0) {
        uVar1 = 0xffffffea;
      }
      else {
        uVar1 = Set_ClkDivider_Freq(param_1,param_2,param_3);
        if (param_2 < *(uint *)(DAT_3006784c + 0x24)) {
          *(uint *)(DAT_3006784c + 0x24) = param_2;
          uVar1 = 0x96;
        }
      }
    }
    else {
      uVar1 = 0x1f;
    }
  }
  else {
    uVar1 = 0x1e;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Enumerate_SD_card_Stack @ 0x300671BC  (примерный размер ~292 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: Clk_Enable_Disable, Enumerate_card, Read_Write_IPreg, Set_Clk_Frequency, Set_default_Clk, logMsg, sdmmc_switch_drive_current, taskDelay
 * Вызывают: SD_MMC_Bus_Init
 * Константы: 0x300671BC
 * Данные: DAT_300676fc, DAT_30067840, DAT_3006784c, DAT_30067fc4, DAT_30067fc8, DAT_30067fcc
 * ---------------------------------------------------------------- */
int Enumerate_SD_card_Stack(void)

{
  int iVar1;
  undefined1 auStack_14 [4];
  uint local_10;
  
  *DAT_300676fc = 0;
  iVar1 = Set_Clk_Frequency(0,0x3f,auStack_14);
  if (iVar1 == 0) {
    logMsg(DAT_30067fc4);
  }
  else {
    logMsg(DAT_30067fc8,iVar1);
  }
  Clk_Enable_Disable(0,1);
  Read_Write_IPreg(0x70,&local_10,0);
  local_10 = (local_10 >> 1 & 0x1f) + 1;
  iVar1 = Enumerate_card(0);
  if (iVar1 != 0) {
    *DAT_30067840 = 0;
    logMsg(DAT_30067fcc,iVar1,0);
  }
  *(int *)(DAT_3006784c + 4) =
       *(int *)(DAT_3006784c + 8) + *(int *)(DAT_3006784c + 0xc) + *(int *)(DAT_3006784c + 0x10);
  if (*(int *)(DAT_3006784c + 4) != 0) {
    sdmmc_switch_drive_current(0);
    Set_default_Clk();
    taskDelay(10);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Set_timeout_values @ 0x300672E0  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: Read_Write_IPreg
 * Вызывают: SD_MMC_Bus_Init
 * Константы: 0x300672E0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void Set_timeout_values(void)

{
  undefined4 local_8 [2];
  
  local_8[0] = 0xffffffff;
  Read_Write_IPreg(0x14,local_8,1);
  return;
}

/* ----------------------------------------------------------------
 * Set_Debounce_Val @ 0x30067324  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: Read_Write_IPreg
 * Вызывают: SD_MMC_Bus_Init
 * Константы: 0x30067324
 * ---------------------------------------------------------------- */
void Set_Debounce_Val(undefined4 param_1)

{
  undefined4 local_4;
  
  local_4 = param_1;
  Read_Write_IPreg(100,&local_4,1);
  return;
}

/* ----------------------------------------------------------------
 * Set_FIFO_Threshold @ 0x30067350  (примерный размер ~252 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: Read_Write_IPreg, Set_IP_Parameters
 * Вызывают: SD_MMC_Bus_Init
 * Константы: 0x30067350, 0x50000000
 * Данные: DAT_300681e4, DAT_300681e8, DAT_300681ec, DAT_300681f0, DAT_300681f4
 * ---------------------------------------------------------------- */
undefined4 Set_FIFO_Threshold(int param_1,int param_2,int param_3)

{
  uint local_1c;
  int local_4;
  
  local_1c = 0;
  local_4 = param_1;
  if (param_3 == 0) {
    if (DAT_300681f4 < param_1 - 100U) {
      return 0x35;
    }
    if (param_2 == 0) {
      Set_IP_Parameters(2,&local_4);
    }
    else {
      Set_IP_Parameters(1,&local_4);
    }
  }
  else {
    local_1c = (DAT_300681e8 & 0x50000000 | ((*DAT_300681e4 >> 1) - 1 & DAT_300681ec) << 0x10) &
               DAT_300681f0 | *DAT_300681e4 >> 1 & DAT_300681ec;
    Read_Write_IPreg(0x4c,&local_1c,1);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * SD_MMC_Bus_Init @ 0x3006744C  (примерный размер ~512 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: Enumerate_SD_card_Stack, Read_Write_IPreg, Set_Debounce_Val, Set_FIFO_Threshold, Set_timeout_values, logMsg, memset
 * Вызывают: SD_MMC_Host_Init
 * Константы: 0x3006744C, 0xFFFFFFCF, 0xFFFFFFFE
 * Данные: DAT_3006784c, DAT_300681f8, DAT_300681fc, DAT_300682c4, DAT_3006836c, DAT_30068370, DAT_30068420
 * ---------------------------------------------------------------- */
int SD_MMC_Bus_Init(void)

{
  int iVar1;
  uint uVar2;
  uint local_20;
  uint local_1c;
  
  local_1c = 0;
  uVar2 = 0;
  memset(DAT_3006784c,0,0x28);
  memset(DAT_300681f8,0,0x880);
  memset(DAT_300681fc,0,0x24);
  local_1c = 0x17;
  Read_Write_IPreg(0x70,&local_20,0);
  *DAT_300682c4 = (local_20 >> 1 & 0x1f) + 1;
  local_20 = 0;
  Read_Write_IPreg(4,&local_20,1);
  local_20 = 0xffffffcf;
  Read_Write_IPreg(0x24,&local_20,1);
  Read_Write_IPreg(0x44,&local_20,0);
  Read_Write_IPreg(0x44,&local_20,1);
  Read_Write_IPreg(0,&local_1c,1);
  do {
    local_20 = *(uint *)*DAT_3006836c;
    uVar2 = uVar2 + 1;
    if (500 < uVar2) {
      logMsg(DAT_30068370,0,0,0,0,0,0);
      return 0x72;
    }
  } while ((local_20 & 1) != 0);
  local_1c = local_1c & 0xfffffffe;
  Set_timeout_values();
  local_20 = 0;
  Read_Write_IPreg(0x50,&local_20,0);
  iVar1 = Enumerate_SD_card_Stack();
  if (iVar1 == 0) {
    Set_Debounce_Val(0x60000);
    Set_FIFO_Threshold(0,0,1);
    logMsg(DAT_30068420);
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Read_ClkSource_Info @ 0x3006764C  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: Read_Write_IPreg
 * Вызывают: Enumerate_Single_Card, Wait_for_CardClkCycles
 * Константы: 0x3006764C, 0xFFFFFFEA
 * ---------------------------------------------------------------- */
undefined4 Read_ClkSource_Info(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  uint local_10;
  
  local_10 = 0;
  if (param_1 == (uint *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    Read_Write_IPreg(0xc,&local_10,0);
    param_1[1] = local_10 >> ((param_2 & 0x7f) << 1) & 3;
    Read_Write_IPreg(8,&local_10,0);
    *param_1 = local_10 >> ((param_1[1] & 0x1f) << 3) & 0xff;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Enumerate_Single_Card @ 0x300676CC  (примерный размер ~336 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: Clk_Enable_Disable, Enumerate_card, Read_ClkSource_Info, Set_Clk_Frequency, printf
 * Вызывают: Card_Detect_Handler
 * Константы: 0x300676CC
 * Данные: DAT_30067840, DAT_3006784c, DAT_30068520, DAT_30068524, DAT_30068528, DAT_30068614
 * ---------------------------------------------------------------- */
int Enumerate_Single_Card(int param_1)

{
  int iVar1;
  char local_20 [4];
  int local_1c;
  undefined1 auStack_18 [4];
  undefined4 local_14;
  
  for (local_1c = 0; local_1c < 0xff; local_1c = local_1c + 1) {
  }
  Read_ClkSource_Info(auStack_18,param_1);
  iVar1 = Set_Clk_Frequency(local_14,0x3e,local_20);
  if (iVar1 == 0) {
    iVar1 = Clk_Enable_Disable(param_1,1);
    if (iVar1 == 0) {
      iVar1 = Enumerate_card(param_1);
      if (iVar1 == 0) {
        local_20[0] = (*(char *)(DAT_30068528 + param_1 * 0x88) == '\0') + '\x01';
      }
      else {
        *(undefined4 *)(param_1 * 0x88 + DAT_30067840) = 0;
      }
      Set_Clk_Frequency(local_14,local_20[0],local_20);
      *(int *)(DAT_3006784c + 4) =
           *(int *)(DAT_3006784c + 8) + *(int *)(DAT_3006784c + 0xc) + *(int *)(DAT_3006784c + 0x10)
      ;
      if (iVar1 == 0) {
        printf(DAT_30068614,param_1);
      }
    }
    else {
      printf(DAT_30068524,iVar1);
    }
  }
  else {
    printf(DAT_30068520,iVar1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Card_Detect_Handler @ 0x3006781C  (примерный размер ~604 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: Enumerate_Single_Card, Read_Write_IPreg, logMsg, memset
 * Вызывают: FUN_30067a78
 * Константы: 0x3006781C, 0x3FFFFFFF
 * Данные: DAT_300681f8, DAT_300682c4, DAT_30068528, DAT_30068618, DAT_300686a8, DAT_3006874c, DAT_30068750, DAT_30068754
 * ---------------------------------------------------------------- */
void Card_Detect_Handler(void)

{
  int iVar1;
  uint uVar2;
  uint local_10;
  
  local_10 = 0;
  Read_Write_IPreg(0x50,&local_10,0);
  local_10 = local_10 & 0x3fffffff;
  for (uVar2 = 0; (int)uVar2 < *DAT_300682c4; uVar2 = uVar2 + 1) {
    if ((local_10 >> (uVar2 & 0xff) & 1) == 0) {
      if (*(int *)(DAT_30068618 + uVar2 * 0x88) == 0) {
        *(undefined4 *)(uVar2 * 0x88 + DAT_30068750) = 1;
        *(undefined4 *)(uVar2 * 0x88 + DAT_3006874c) = 0;
        if (*(int *)(DAT_30068754 + uVar2 * 0x88) == 0) {
          iVar1 = Enumerate_Single_Card(uVar2);
          if (iVar1 == 0) {
            *(undefined4 *)(uVar2 * 0x88 + DAT_30068618) = 1;
          }
          else {
            logMsg(DAT_30068888,uVar2);
          }
        }
      }
    }
    else {
      if (*(int *)(DAT_30068618 + uVar2 * 0x88) == 1) {
        if (*(char *)(DAT_30068528 + uVar2 * 0x88) == '\0') {
          *(int *)(DAT_300686a8 + 8) = *(int *)(DAT_300686a8 + 8) + -1;
        }
        else if (*(char *)(DAT_30068528 + uVar2 * 0x88) == '\x01') {
          *(int *)(DAT_300686a8 + 0xc) = *(int *)(DAT_300686a8 + 0xc) + -1;
        }
        else {
          *(int *)(DAT_300686a8 + 0x10) = *(int *)(DAT_300686a8 + 0x10) + -1;
        }
        memset((void *)(uVar2 * 0x88 + DAT_300681f8),0,0x88);
        *(undefined4 *)(uVar2 * 0x88 + DAT_3006874c) = 1;
        *(undefined4 *)(uVar2 * 0x88 + DAT_30068750) = 0;
        *(int *)(DAT_300686a8 + 4) =
             *(int *)(DAT_300686a8 + 8) + *(int *)(DAT_300686a8 + 0xc) +
             *(int *)(DAT_300686a8 + 0x10);
      }
      *(undefined4 *)(uVar2 * 0x88 + DAT_30068618) = 0;
      *(undefined4 *)(uVar2 * 0x88 + DAT_30068754) = 0;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30067a78 @ 0x30067A78  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: Card_Detect_Handler, Read_Write_IPreg, semTake
 * Константы: 0x30067A78, 0xFFFFFFFE, 0xFFFFFFFF
 * Данные: DAT_3006888c, DAT_30068890
 * ---------------------------------------------------------------- */
void FUN_30067a78(void)

{
  uint local_8 [2];
  
  local_8[0] = 0;
  do {
    if (*DAT_3006888c == 1) {
      Read_Write_IPreg(0x24,local_8,0);
      local_8[0] = local_8[0] & 0xfffffffe;
      Read_Write_IPreg(0x24,local_8,1);
      *DAT_3006888c = 0;
      Card_Detect_Handler();
      Read_Write_IPreg(0x24,local_8,0);
      local_8[0] = local_8[0] | 1;
      Read_Write_IPreg(0x24,local_8,1);
    }
    semTake(*DAT_30068890,0xffffffff);
  } while( true );
}

/* ----------------------------------------------------------------
 * Create_Intr_Thread @ 0x30067B18  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: semBCreate, taskSpawn
 * Константы: 0x30067B18, 0xFFFFFFFF
 * Данные: DAT_30068890, DAT_3006895c, DAT_30068960, DAT_30068964
 * ---------------------------------------------------------------- */
undefined4 Create_Intr_Thread(void)

{
  int iVar1;
  
  if (*DAT_30068890 == 0) {
    iVar1 = semBCreate(1,0);
    *DAT_30068890 = iVar1;
    iVar1 = taskSpawn(DAT_30068960,0x32,0,2000,DAT_3006895c,0,0,0,0,0,0,0,0,0,0);
    if (-1 < iVar1) {
      *DAT_30068964 = iVar1;
      return 0;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * Kill_Intr_Thread @ 0x30067BE4  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: taskDelete
 * Константы: 0x30067BE4
 * Данные: DAT_30068964
 * ---------------------------------------------------------------- */
undefined4 Kill_Intr_Thread(void)

{
  taskDelete(*DAT_30068964);
  return 0;
}

/* ----------------------------------------------------------------
 * SDIO_Reset @ 0x30067C00  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: Form_Send_Cmd, Validate_Response
 * Вызывают: Identify_Card_Type
 * Константы: 0x30067C00, 0x80000C00
 * Данные: DAT_30068a38
 * ---------------------------------------------------------------- */
undefined4 SDIO_Reset(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  
  local_10 = 0;
  iVar1 = Form_Send_Cmd(param_1,100,DAT_30068a38 & 8 | 0x80000c00,&local_10,0);
  if (iVar1 == 0) {
    uVar2 = Validate_Response(0x34,&local_10,param_1,0xff);
  }
  else {
    uVar2 = 0x21;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * Identify_Card_Type @ 0x30067CC0  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: Form_Send_Cmd, SDIO_Reset, Send_ACMD41, logMsg
 * Константы: 0x30067CC0, 0xFFFFFFFF
 * Данные: DAT_30068afc, DAT_30068c08
 * ---------------------------------------------------------------- */
undefined4 Identify_Card_Type(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int local_20;
  undefined1 auStack_1c [4];
  
  uVar2 = 0xffffffff;
  SDIO_Reset(param_1);
  iVar3 = 0x46;
  do {
    if (iVar3 == 0) {
      logMsg(DAT_30068afc);
      return 0x33;
    }
    iVar3 = iVar3 + -1;
    uVar1 = Form_Send_Cmd(param_1,5,0,auStack_1c,1);
  } while (((uVar1 & 0x100) == 0) && (uVar1 != 0));
  if (uVar1 == 0) {
    uVar2 = 4;
  }
  else if ((uVar1 & 0x100) != 0) {
    Form_Send_Cmd(param_1,0,0,auStack_1c,1);
    iVar3 = 0x19;
    do {
      if (iVar3 == 0) {
        return 0x34;
      }
      iVar3 = iVar3 + -1;
      uVar1 = Send_ACMD41(param_1,0,auStack_1c);
      for (local_20 = 0; local_20 < DAT_30068c08; local_20 = local_20 + 1) {
      }
    } while ((((uVar1 & 0x100) == 0) && (0 < iVar3)) && (uVar1 != 0));
    if ((uVar1 & 0x100) == 0) {
      if (uVar1 == 0) {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * Calculate_Data_Timeout @ 0x30067E14  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30067E14
 * Данные: DAT_300686a8, DAT_30068c0c, DAT_30068c10, DAT_30068c14
 * ---------------------------------------------------------------- */
int Calculate_Data_Timeout(void)

{
  return *(int *)(DAT_300686a8 + 0x20) * 1000 +
         (uint)((ulonglong)DAT_30068c14 *
                (ulonglong)
                (uint)(*(int *)(DAT_30068c10 + (*(uint *)(DAT_300686a8 + 0x1c) & 7) * 4) *
                       *(int *)(DAT_30068c0c + (*(uint *)(DAT_300686a8 + 0x1c) >> 3 & 0xf) * 4) *
                      0x19) >> 0x26) + 1;
}

/* ----------------------------------------------------------------
 * Read_Write_TimeOut @ 0x30067E88  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: Read_Write_IPreg
 * Константы: 0x30067E88
 * ---------------------------------------------------------------- */
undefined4 Read_Write_TimeOut(undefined4 param_1,undefined4 param_2)

{
  Read_Write_IPreg(0x14,param_1,param_2);
  return 0;
}

/* ----------------------------------------------------------------
 * Send_Command @ 0x30067EAC  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: Send_cmd_to_host, printf
 * Константы: 0x30067EAC, 0x80000000
 * Данные: DAT_30068618, DAT_30068cdc
 * ---------------------------------------------------------------- */
undefined4 Send_Command(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  
  uVar2 = param_1 >> 0x10 & 0x1f;
  if (uVar2 < 0x10) {
    if (*(int *)(DAT_30068618 + uVar2 * 0x88) == 0) {
      uVar1 = 0x37;
    }
    else {
      local_24 = 0;
      local_20 = 0;
      local_1c = param_2;
      local_18 = param_1;
      if ((param_1 & 0x80000000) == 0) {
        printf(DAT_30068cdc);
        uVar1 = 0x21;
      }
      else {
        uVar1 = Send_cmd_to_host(&local_24,param_3,0,0,0,0,0,0,0,0);
      }
    }
  }
  else {
    uVar1 = 0x36;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Power_ON_Off @ 0x30067F78  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: Set_IP_Parameters
 * Константы: 0x30067F78
 * ---------------------------------------------------------------- */
undefined4 Power_ON_Off(int param_1,int param_2)

{
  undefined4 uVar1;
  int local_4;
  
  if ((param_1 == 0xff) || (param_1 < 0x10)) {
    local_4 = param_1;
    if (param_2 == 0) {
      Set_IP_Parameters(0xb,&local_4);
    }
    else {
      Set_IP_Parameters(10,&local_4);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0x36;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Set_Clk_Source @ 0x30067FF0  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: Set_Clock_Source
 * Константы: 0x30067FF0
 * ---------------------------------------------------------------- */
undefined4 Set_Clk_Source(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 4) {
    if (param_1 < 0x10) {
      uVar1 = Set_Clock_Source(param_1,param_2);
    }
    else {
      uVar1 = 0x36;
    }
  }
  else {
    uVar1 = 0x1e;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Check_TranState @ 0x30068030  (примерный размер ~276 байт)
 * Модуль: data | Вызывают: 10 | Вызывает: 2
 * Вызывает: Form_Send_Cmd, Validate_Response
 * Вызывают: Card_Lock, Erase_Card_Data, Get_WrProtect_Status, HSSD_Send_CMD6, Read_Write_BlkData, Read_Write_StreamData, Send_CMD55, SetBlockLength, Set_Clr_WrProt, Wr_Protect_CardData
 * Константы: 0x30068030
 * ---------------------------------------------------------------- */
int Check_TranState(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint local_14;
  
  iVar1 = Form_Send_Cmd(param_1,0xd,0,&local_14,1);
  if (iVar1 == 0) {
    uVar2 = local_14 >> 9 & 0xf;
    if (uVar2 == 3) {
      iVar1 = Form_Send_Cmd(param_1,7,0,&local_14,1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = Validate_Response(7,&local_14,param_1,0xff);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = Form_Send_Cmd(param_1,0xd,0,&local_14,1);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    else if (uVar2 != 4) {
      return 0x4b;
    }
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Send_CMD55 @ 0x30068144  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: Check_TranState, Form_Send_Cmd
 * Вызывают: Read_SD_Reg, Set_SD_Mode
 * Константы: 0x30068144
 * ---------------------------------------------------------------- */
int Send_CMD55(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_10 [4];
  
  iVar1 = Check_TranState(param_1);
  if (iVar1 == 0) {
    iVar1 = Form_Send_Cmd(param_1,0x37,0,auStack_10,1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Set_SD_Mode @ 0x3006819C  (примерный размер ~416 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: Form_Send_Cmd, Send_CMD55, Set_IP_Parameters, Validate_Response
 * Вызывают: SD_MMC_Host_Init
 * Константы: 0x3006819C
 * Данные: DAT_30068528, DAT_30068618
 * ---------------------------------------------------------------- */
int Set_SD_Mode(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_18 [4];
  int local_4;
  
  uVar2 = 0;
  if ((*(char *)(DAT_30068528 + param_1 * 0x88) == '\x01') ||
     (*(char *)(DAT_30068528 + param_1 * 0x88) == '\b')) {
    if (param_1 < 0x10) {
      if (*(int *)(DAT_30068618 + param_1 * 0x88) == 1) {
        if (*(char *)(DAT_30068528 + param_1 * 0x88) == '\0') {
          iVar1 = 0x20;
        }
        else {
          local_4 = param_1;
          iVar1 = Send_CMD55(param_1);
          if (iVar1 == 0) {
            if (param_2 != 0) {
              uVar2 = 2;
            }
            iVar1 = Form_Send_Cmd(local_4,6,uVar2,auStack_18,0);
            if ((iVar1 == 0) && (iVar1 = Validate_Response(6,auStack_18,local_4,4), iVar1 == 0)) {
              if (param_2 == 0) {
                Set_IP_Parameters(6,&local_4);
              }
              else {
                Set_IP_Parameters(5,&local_4);
              }
            }
          }
          else {
            iVar1 = 0x52;
          }
        }
      }
      else {
        iVar1 = 0x37;
      }
    }
    else {
      iVar1 = 0x36;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Send_RAW_Data_Cmd @ 0x3006833C  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: Send_cmd_to_host, printf
 * Константы: 0x3006833C, 0xFFFFFFEA, 0x80000000
 * Данные: DAT_30068cdc
 * ---------------------------------------------------------------- */
undefined4
Send_RAW_Data_Cmd(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 uint param_10)

{
  undefined4 uVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  
  if (param_5 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    local_30 = param_3;
    local_2c = param_4;
    local_28 = param_2;
    local_24 = param_1;
    if ((param_1 & 0x80000000) == 0) {
      printf(DAT_30068cdc);
      uVar1 = 0x21;
    }
    else {
      uVar1 = Send_cmd_to_host(&local_30,param_5,param_6,param_7,param_8,param_10,param_9,1,
                               param_10 & 0x80,0);
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * SetBlockLength @ 0x300683F4  (примерный размер ~408 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 3
 * Вызывает: Check_TranState, Form_Send_Cmd, Validate_Response
 * Вызывают: Card_Lock, Get_WrProtect_Status, HSSD_Send_CMD6, Read_SD_Reg, Set_Clr_WrProt
 * Константы: 0x300683F4
 * Данные: DAT_300692c0, DAT_300692c4, DAT_300692c8, DAT_300692cc, DAT_30069398, DAT_3006939c
 * ---------------------------------------------------------------- */
int SetBlockLength(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 auStack_1c [4];
  
  if (0x200 < param_2) {
    return 0x60;
  }
  if (param_3 == 0) {
    if ((uint)(1 << *(sbyte *)(DAT_300692c8 + param_1 * 0x88)) < param_2) {
      return 0x4f;
    }
    if ((param_4 == 0) && (*(char *)(DAT_300692cc + param_1 * 0x88) == '\0')) {
      return 0x50;
    }
  }
  else {
    if ((uint)(1 << *(sbyte *)(DAT_300692c0 + param_1 * 0x88)) < param_2) {
      return 0x4f;
    }
    if ((param_4 == 0) && (*(char *)(DAT_300692c4 + param_1 * 0x88) == '\0')) {
      return 0x50;
    }
  }
  iVar1 = Check_TranState(param_1);
  if (iVar1 == 0) {
    iVar1 = Form_Send_Cmd(param_1,0x10,param_2,auStack_1c,2);
    if (iVar1 == 0) {
      iVar1 = Validate_Response(0x10,auStack_1c,param_1,4);
      if (iVar1 == 0) {
        if (param_3 == 0) {
          *(uint *)(DAT_3006939c + param_1 * 0x88) = param_2;
        }
        else {
          *(uint *)(DAT_30069398 + param_1 * 0x88) = param_2;
        }
        iVar1 = 0;
      }
      else {
        iVar1 = 0x51;
      }
    }
    else {
      iVar1 = 0x51;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Read_TotalPorts @ 0x3006858C  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3006858C, 0xFFFFFFEA
 * Данные: DAT_30068618, DAT_300693a0
 * ---------------------------------------------------------------- */
undefined4 Read_TotalPorts(uint param_1,int param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (param_2 == 0) {
    uVar1 = 0xffffffea;
  }
  else if (param_3 < 0x10) {
    uVar1 = 0x39;
  }
  else {
    for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
      if ((*(int *)(DAT_30068618 + iVar3 * 0x88) != 0) &&
         (*(byte *)(DAT_300693a0 + iVar3 * 0x88) == param_1)) {
        *(int *)(param_2 + iVar2 * 4) = iVar3;
        iVar2 = iVar2 + 1;
      }
    }
    *param_4 = iVar2 + 1;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Read_total_cards_connected @ 0x30068634  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30068634
 * Данные: DAT_300686a8
 * ---------------------------------------------------------------- */
undefined4 Read_total_cards_connected(void)

{
  return *(undefined4 *)(DAT_300686a8 + 4);
}

/* ----------------------------------------------------------------
 * Read_Op_Mode @ 0x30068640  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30068640
 * Данные: DAT_300686a8
 * ---------------------------------------------------------------- */
undefined4 Read_Op_Mode(void)

{
  return *DAT_300686a8;
}

/* ----------------------------------------------------------------
 * Read_IP_ID_number @ 0x3006864C  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: Read_Write_IPreg
 * Константы: 0x3006864C, 0xFFFFFFEA
 * ---------------------------------------------------------------- */
undefined4 Read_IP_ID_number(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    Read_Write_IPreg(0x68,param_1,0);
    Read_Write_IPreg(0x6c,param_1 + 4,0);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Read_Card_RCA @ 0x30068690  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30068690
 * Данные: DAT_30069508, DAT_3006950c
 * ---------------------------------------------------------------- */
undefined4 Read_Card_RCA(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x10) {
    if (*(int *)(DAT_30069508 + param_1 * 0x88) == 1) {
      uVar1 = *(undefined4 *)(DAT_3006950c + param_1 * 0x88);
    }
    else {
      uVar1 = 0x37;
    }
  }
  else {
    uVar1 = 0x36;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Read_card_type @ 0x300686E4  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300686E4
 * Данные: DAT_300693a0, DAT_30069508
 * ---------------------------------------------------------------- */
undefined1 Read_card_type(int param_1)

{
  undefined1 uVar1;
  
  if (param_1 < 0x10) {
    if (*(int *)(DAT_30069508 + param_1 * 0x88) == 1) {
      uVar1 = *(undefined1 *)(DAT_300693a0 + param_1 * 0x88);
    }
    else {
      uVar1 = 0x37;
    }
  }
  else {
    uVar1 = 0x36;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Read_CurrState_of_card @ 0x30068734  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30068734
 * Данные: DAT_30069508, DAT_30069610
 * ---------------------------------------------------------------- */
undefined4 Read_CurrState_of_card(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x10) {
    if (*(int *)(DAT_30069508 + param_1 * 0x88) == 1) {
      uVar1 = *(undefined4 *)(DAT_30069610 + param_1 * 0x88);
    }
    else {
      uVar1 = 0x37;
    }
  }
  else {
    uVar1 = 0x36;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Get_card_size @ 0x30068790  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30068790
 * Данные: DAT_30069508, DAT_30069614
 * ---------------------------------------------------------------- */
undefined4 Get_card_size(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x10) {
    if (*(int *)(DAT_30069508 + param_1 * 0x88) == 1) {
      uVar1 = *(undefined4 *)(DAT_30069614 + param_1 * 0x88);
    }
    else {
      uVar1 = 0x37;
    }
  }
  else {
    uVar1 = 0x36;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Get_Card_Attributes @ 0x300687E0  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300687E0
 * Данные: DAT_30069508, DAT_30069618
 * ---------------------------------------------------------------- */
undefined4 Get_Card_Attributes(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x10) {
    if (*(int *)(DAT_30069508 + param_1 * 0x88) == 1) {
      uVar1 = *(undefined4 *)(DAT_30069618 + param_1 * 0x88);
    }
    else {
      uVar1 = 0x37;
    }
  }
  else {
    uVar1 = 0x36;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * SDIO_RdWr_Direct @ 0x30068830  (примерный размер ~380 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 3
 * Вызывает: Form_Send_Cmd, Validate_Command, Validate_Response
 * Вызывают: Change_PwrMode_ForFunction, Enable_Disable_SDIOFunction, Enable_Disable_SDIOIRQ, Enable_MasterPwrControl_Mode, Get_Data_fromTuple, Resume_Transfer, Suspend_Transfer
 * Константы: 0x30068830
 * Данные: DAT_30068a38, DAT_30069770
 * ---------------------------------------------------------------- */
int SDIO_RdWr_Direct(undefined4 param_1,uint param_2,uint param_3,byte *param_4,byte *param_5,
                    int param_6,uint param_7,undefined4 param_8)

{
  int iVar1;
  
  iVar1 = Validate_Command(param_1,0,param_2,0x10);
  if (iVar1 == 0) {
    iVar1 = Form_Send_Cmd(param_1,0x34,
                          *param_4 & DAT_30068a38 | (param_3 & DAT_30069770 & 0x3ffff) << 9 |
                          (param_7 & 1) << 0x1b | (param_2 & 7) << 0x1c | param_6 << 0x1f,param_5,
                          param_8);
    if (iVar1 == 0) {
      if ((param_7 != 0) || (param_6 == 0)) {
        *param_4 = *param_5;
      }
      iVar1 = Validate_Response(0x34,param_5,param_1,0xff);
    }
    else {
      iVar1 = 0x21;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Enable_Disable_SDIOFunction @ 0x300689AC  (примерный размер ~276 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: SDIO_RdWr_Direct, Validate_Command
 * Константы: 0x300689AC
 * Данные: DAT_300698cc
 * ---------------------------------------------------------------- */
int Enable_Disable_SDIOFunction(int param_1,uint param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  byte local_20 [4];
  undefined1 auStack_1c [4];
  
  iVar2 = Validate_Command(param_1,0,param_2,0x10);
  if ((iVar2 == 0) && (iVar2 = SDIO_RdWr_Direct(param_1,0,2,local_20,auStack_1c,0,0,2), iVar2 == 0))
  {
    bVar1 = (byte)(1 << (param_2 & 0xff));
    if (param_3 == 0) {
      local_20[0] = local_20[0] & ~bVar1;
    }
    else {
      local_20[0] = local_20[0] | bVar1;
    }
    *(byte *)(param_1 * 0x88 + DAT_300698cc) = local_20[0];
    iVar2 = SDIO_RdWr_Direct(param_1,0,2,local_20,auStack_1c,1,1,2);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * Enable_Disable_SDIOIRQ @ 0x30068AC0  (примерный размер ~276 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: SDIO_RdWr_Direct, Validate_Command
 * Константы: 0x30068AC0
 * Данные: DAT_30069a50
 * ---------------------------------------------------------------- */
int Enable_Disable_SDIOIRQ(int param_1,uint param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  byte local_20 [4];
  undefined1 auStack_1c [4];
  
  iVar2 = Validate_Command(param_1,0,param_2,0x10);
  if ((iVar2 == 0) && (iVar2 = SDIO_RdWr_Direct(param_1,0,4,local_20,auStack_1c,0,0,2), iVar2 == 0))
  {
    bVar1 = (byte)(1 << (param_2 & 0xff));
    if (param_3 == 0) {
      local_20[0] = local_20[0] & ~bVar1;
    }
    else {
      local_20[0] = local_20[0] | bVar1;
    }
    *(byte *)(param_1 * 0x88 + DAT_30069a50) = local_20[0];
    iVar2 = SDIO_RdWr_Direct(param_1,0,4,local_20,auStack_1c,1,1,2);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * Read_Wait @ 0x30068BD4  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: Set_IP_Parameters, Validate_Command
 * Константы: 0x30068BD4
 * Данные: DAT_30069a54
 * ---------------------------------------------------------------- */
int Read_Wait(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_14;
  
  local_14 = 6;
  iVar1 = Validate_Command(param_1,0,0,0x10);
  if (iVar1 == 0) {
    if ((*(byte *)(DAT_30069a54 + param_1 * 0x88) & 2) == 0) {
      iVar1 = 0x44;
    }
    else {
      if (param_2 == 0) {
        Set_IP_Parameters(0xe,&local_14);
      }
      else {
        Set_IP_Parameters(0xd,&local_14);
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Get_Data_fromTuple @ 0x30068C7C  (примерный размер ~848 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: SDIO_RdWr_Direct, SDIO_RdWr_Extended, Validate_Command
 * Вызывают: Change_SDIO_BlkSize
 * Константы: 0x30068C7C
 * Данные: DAT_30069c00
 * ---------------------------------------------------------------- */
int Get_Data_fromTuple(undefined4 param_1,int param_2,uint param_3,int param_4,uint param_5,
                      undefined4 param_6,uint param_7,int param_8)

{
  int iVar1;
  byte local_30 [4];
  int local_2c;
  int local_28;
  undefined1 auStack_24 [4];
  
  local_2c = 0;
  local_30[0] = 0;
  local_28 = 0;
  iVar1 = Validate_Command(param_1,0,param_2,0x10);
  if (iVar1 == 0) {
    if (param_7 < param_5) {
      iVar1 = 0x60;
    }
    else {
      iVar1 = SDIO_RdWr_Extended(param_1,0,param_2 << 8 | 9,3,&local_2c,auStack_24,0,1,0,0,0x50);
      if (iVar1 == 0) {
        if (DAT_30069c00 < local_2c - 0x1000U) {
          iVar1 = 0x6d;
        }
        else {
          iVar1 = SDIO_RdWr_Direct(param_1,0,local_2c,local_30,auStack_24,0,0,2);
          while (iVar1 == 0) {
            if ((local_30[0] == param_3) || (local_30[0] == 0xff)) {
              if (local_30[0] != param_3) {
                return 0x6a;
              }
              local_28 = 0;
              iVar1 = SDIO_RdWr_Direct(param_1,0,local_2c + 1,&local_28,auStack_24,0,0,2);
              if (iVar1 != 0) {
                return iVar1;
              }
              if (local_28 + 2U < param_4 + param_5) {
                return 0x6b;
              }
              iVar1 = SDIO_RdWr_Extended(param_1,0,local_2c + param_4,param_5,param_6,auStack_24,0,1
                                         ,0,0,param_8 << 6 | 0x10);
              return iVar1;
            }
            if (local_30[0] == 0) {
              local_2c = local_2c + 1;
            }
            else {
              local_28 = 0;
              iVar1 = SDIO_RdWr_Direct(param_1,0,local_2c + 1,&local_28,auStack_24,0,0,2);
              if (iVar1 != 0) {
                return iVar1;
              }
              local_2c = local_2c + local_28 + 2;
            }
            local_30[0] = 0;
            iVar1 = SDIO_RdWr_Direct(param_1,0,local_2c,local_30,auStack_24,0,0,2);
          }
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Change_SDIO_BlkSize @ 0x30068FCC  (примерный размер ~404 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: Get_Data_fromTuple, SDIO_RdWr_Extended, Validate_Command
 * Константы: 0x30068FCC
 * Данные: DAT_30069f28
 * ---------------------------------------------------------------- */
int Change_SDIO_BlkSize(int param_1,int param_2,ushort param_3)

{
  int iVar1;
  undefined4 uVar2;
  ushort local_20;
  ushort local_1e;
  undefined4 local_1c;
  
  local_1c = 0;
  local_20 = 0;
  local_1e = 0;
  iVar1 = Validate_Command(param_1,0,param_2,0x10);
  if (iVar1 == 0) {
    if ((param_3 == 0) || (param_3 == *(ushort *)(DAT_30069f28 + param_2 * 2 + param_1 * 0x88))) {
      iVar1 = 0x60;
    }
    else {
      if (param_2 == 0) {
        uVar2 = 3;
      }
      else {
        uVar2 = 0xe;
      }
      iVar1 = Get_Data_fromTuple(param_1,param_2,0x22,uVar2,2,&local_20,2,1);
      if (iVar1 == 0) {
        if (local_20 < param_3) {
          iVar1 = 0x6c;
        }
        else {
          local_1e = param_3;
          iVar1 = SDIO_RdWr_Extended(param_1,0,param_2 << 8 | 0x10,2,&local_1e,&local_1c,0,1,0,0,
                                     0xd0);
          if (iVar1 == 0) {
            *(ushort *)(DAT_30069f28 + param_2 * 2 + param_1 * 0x88) = param_3;
            iVar1 = 0;
          }
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Enable_MasterPwrControl_Mode @ 0x30069160  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: SDIO_RdWr_Direct, Validate_Command, memset
 * Константы: 0x30069160, 0xFFFFFFFF
 * Данные: DAT_30069fb8
 * ---------------------------------------------------------------- */
int Enable_MasterPwrControl_Mode(undefined4 param_1,int param_2)

{
  int iVar1;
  byte local_18 [4];
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  
  local_18[0] = 0;
  local_14 = *DAT_30069fb8;
  local_13 = DAT_30069fb8[1];
  local_12 = DAT_30069fb8[2];
  local_11 = DAT_30069fb8[3];
  iVar1 = Validate_Command(param_1,0,0,0xffffffff);
  if ((iVar1 == 0) &&
     (iVar1 = SDIO_RdWr_Direct(param_1,0,0x12,local_18,&local_14,0,0,2), iVar1 == 0)) {
    if ((local_18[0] & 1) == 0) {
      iVar1 = 0x68;
    }
    else {
      if (param_2 == 0) {
        local_18[0] = local_18[0] & 0xfd;
      }
      else {
        local_18[0] = local_18[0] | 2;
      }
      memset(&local_14,0,4);
      iVar1 = SDIO_RdWr_Direct(param_1,0,0x12,local_18,&local_14,1,0,2);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Change_PwrMode_ForFunction @ 0x300692B4  (примерный размер ~500 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: SDIO_RdWr_Direct, Validate_Command, memset
 * Константы: 0x300692B4
 * Данные: DAT_3006a1a8
 * ---------------------------------------------------------------- */
int Change_PwrMode_ForFunction(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  byte local_1c [4];
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  
  local_1c[0] = 0;
  local_18 = *DAT_3006a1a8;
  local_17 = DAT_3006a1a8[1];
  local_16 = DAT_3006a1a8[2];
  local_15 = DAT_3006a1a8[3];
  iVar1 = Validate_Command(param_1,0,param_2,0x10);
  if (iVar1 == 0) {
    if (param_2 == 0) {
      iVar1 = 0x60;
    }
    else {
      iVar1 = SDIO_RdWr_Direct(param_1,0,0x12,local_1c,&local_18,0,0,2);
      if (iVar1 == 0) {
        if ((local_1c[0] & 1) == 0) {
          iVar1 = 0x68;
        }
        else {
          iVar1 = SDIO_RdWr_Direct(param_1,0,param_2 << 8 | 2,local_1c,&local_18,0,0,2);
          if (iVar1 == 0) {
            if ((local_1c[0] & 1) == 0) {
              iVar1 = 0x69;
            }
            else {
              if (param_3 == 0) {
                local_1c[0] = local_1c[0] & 0xfd;
              }
              else {
                local_1c[0] = local_1c[0] | 2;
              }
              memset(&local_18,0,4);
              iVar1 = SDIO_RdWr_Direct(param_1,0,param_2 << 8 | 2,local_1c,&local_18,1,0,2);
            }
          }
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Form_Data_Command @ 0x300694A8  (примерный размер ~428 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 0
 * Вызывают: Blksize_Data_Transfer, HSSD_Send_CMD6, Partial_Blk_Xfer, Read_SD_Reg, Read_Write_StreamData
 * Константы: 0x300694A8, 0x80000000, 0xFFDFFFFF, 0xFFE0FFFF, 0xFFFF7FFF, 0xFFFFBFFF, 0xFFFFDFFF, 0xFFFFEFFF
 * Данные: DAT_3006a470, DAT_3006a474
 * ---------------------------------------------------------------- */
undefined4
Form_Data_Command(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4,
                 undefined4 *param_5,uint param_6)

{
  param_5[3] = param_5[3] | 0x80000000;
  param_5[3] = param_5[3] & 0xffdfffff;
  param_5[3] = param_5[3] & 0xffe0ffff | (param_1 & 0x1f) << 0x10;
  param_5[3] = param_5[3] & 0xffff7fff | (param_4 & 1) << 0xf;
  param_5[3] = param_5[3] & 0xffffbfff;
  param_5[3] = param_5[3] & 0xffffdfff | (param_4 >> 1 & 1) << 0xd;
  param_5[3] = param_5[3] & 0xffffefff;
  param_5[3] = param_5[3] & 0xfffff7ff | (param_6 & 1) << 0xb;
  param_5[3] = param_5[3] & 0xfffffbff | (param_4 >> 7 & 1) << 10;
  param_5[3] = param_5[3] | 0x200;
  param_5[3] = param_5[3] & 0xfffffeff | (param_4 >> 2 & 1) << 8;
  param_5[3] = param_5[3] & 0xffffff7f;
  param_5[3] = param_5[3] | 0x40;
  param_5[3] = param_5[3] | 0x20000000;
  param_5[2] = param_2;
  *param_5 = param_3;
  if ((param_5[3] & 0x400) == 0) {
    param_5[1] = *(undefined4 *)(DAT_3006a474 + param_1 * 0x88);
  }
  else {
    param_5[1] = *(undefined4 *)(DAT_3006a470 + param_1 * 0x88);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * Set_Auto_stop @ 0x30069654  (примерный размер ~228 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: Read_Write_IPreg
 * Вызывают: Blksize_Data_Transfer
 * Константы: 0x30069654, 0xFFFFEFFF
 * Данные: DAT_3006a528, DAT_3006a52c
 * ---------------------------------------------------------------- */
void Set_Auto_stop(uint param_1,int *param_2)

{
  int iVar1;
  uint local_1c;
  
  local_1c = 0;
  Read_Write_IPreg(0x18,&local_1c,0);
  if (((local_1c & DAT_3006a528) >> (param_1 & 0xff) & 1) == 0) {
    iVar1 = 4;
  }
  else {
    iVar1 = 1;
  }
  if (*(char *)(DAT_3006a52c + param_1 * 0x88) == '\0') {
    iVar1 = 4;
  }
  param_2[3] = param_2[3] & 0xffffefff;
  if (((((param_2[3] & 0x400U) != 0) && (0x18 < (uint)(iVar1 * param_2[1]))) &&
      (0x18 < (uint)(iVar1 * *param_2))) ||
     ((((param_2[3] & 0x400U) == 0 && (0x18 < (uint)(iVar1 * param_2[1]))) &&
      (0x50 < (uint)(iVar1 * *param_2))))) {
    param_2[3] = param_2[3] | 0x1000;
  }
  return;
}

/* ----------------------------------------------------------------
 * Blksize_Data_Transfer @ 0x30069738  (примерный размер ~624 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: Form_Data_Command, Form_Send_Cmd, Send_cmd_to_host, Set_Auto_stop, Validate_Response, __udiv32, printf
 * Вызывают: Read_Write_BlkData
 * Константы: 0xFFFFFFC0, 0x30069738
 * Данные: DAT_3006a470, DAT_3006a474, DAT_3006a52c, DAT_3006a624, DAT_3006a750, DAT_3006a7fc
 * ---------------------------------------------------------------- */
int Blksize_Data_Transfer
              (int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7,undefined4 param_8,uint param_9)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  
  local_3c = *DAT_3006a624;
  local_38 = DAT_3006a624[1];
  local_34 = DAT_3006a624[2];
  local_30 = DAT_3006a624[3];
  if ((param_9 & 0x80) == 0) {
    uVar2 = *(undefined4 *)(DAT_3006a474 + param_1 * 0x88);
  }
  else {
    uVar2 = *(undefined4 *)(DAT_3006a470 + param_1 * 0x88);
  }
  Form_Data_Command(param_1,param_2,param_3,param_9,&local_3c,0);
  if ((param_9 & 0x80) == 0) {
    local_30 = local_30 & 0xffffffc0 | (*(uint *)(DAT_3006a474 + param_1 * 0x88) < param_3) + 0x11;
  }
  else if (*(uint *)(DAT_3006a470 + param_1 * 0x88) < param_3) {
    local_30 = local_30 & 0xffffffc0 | 0x19;
  }
  else {
    local_30 = local_30 & 0xffffffc0 | 0x18;
  }
  if (((param_9 & 8) != 0) && (*(char *)(DAT_3006a52c + param_1 * 0x88) == '\0')) {
    uVar2 = __udiv32(param_3,uVar2);
    iVar1 = Form_Send_Cmd(param_1,0x17,uVar2,param_5,1);
    if (iVar1 != 0) {
      printf(DAT_3006a750);
      return 0x21;
    }
  }
  if (((local_30 & 0x3f) == 0x19) || ((local_30 & 0x3f) == 0x12)) {
    Set_Auto_stop(param_1,&local_3c);
  }
  iVar1 = Send_cmd_to_host(&local_3c,param_5,param_6,param_4,param_7,param_9,param_8,1,
                           param_9 & 0x80,(int)param_9 >> 6 & 1);
  if (iVar1 == 0) {
    iVar1 = Validate_Response(local_30 & 0x3f,param_5,param_1,4);
  }
  else {
    printf(DAT_3006a7fc,iVar1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Partial_Blk_Xfer @ 0x300699A8  (примерный размер ~652 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: Form_Data_Command, OSAL_LogMsg, Send_cmd_to_host, Validate_Response, free, malloc, memcpy
 * Вызывают: Read_Write_BlkData
 * Константы: 0xFFFFFFC0, 0x300699A8
 * Данные: DAT_3006a474, DAT_3006a800, DAT_3006a908
 * ---------------------------------------------------------------- */
int Partial_Blk_Xfer(int param_1,uint param_2,size_t param_3,void *param_4,undefined4 param_5,
                    undefined4 param_6,undefined4 param_7,uint param_8)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  
  local_40 = *DAT_3006a800;
  local_3c = DAT_3006a800[1];
  local_38 = DAT_3006a800[2];
  local_34 = DAT_3006a800[3];
  __ptr = malloc(0x800);
  if (__ptr == (void *)0x0) {
    OSAL_LogMsg(DAT_3006a908,1,2,3,4,5,6);
    iVar1 = -1;
  }
  else {
    uVar3 = param_2 & ~(*(int *)(DAT_3006a474 + param_1 * 0x88) - 1U);
    Form_Data_Command(param_1,uVar3,*(undefined4 *)(DAT_3006a474 + param_1 * 0x88),param_8 & 0x7f,
                      &local_40,0);
    local_34 = local_34 & 0xffffffc0 | 0x11;
    iVar1 = Send_cmd_to_host(&local_40,param_5,param_6,__ptr,0,param_8,param_7,1,0,1);
    if (iVar1 == 0) {
      iVar1 = Validate_Response(local_34 & 0x3f,param_5,param_1,4);
      if (iVar1 == 0) {
        iVar2 = param_2 - uVar3;
        if ((param_8 & 0x80) == 0) {
          memcpy(param_4,(void *)((int)__ptr + iVar2),param_3);
        }
        else {
          memcpy((void *)((int)__ptr + iVar2),param_4,param_3);
          local_34 = local_34 & 0xffffffc0 | 0x418;
          iVar1 = Send_cmd_to_host(&local_40,param_5,param_6,__ptr,0,param_8,param_7,1,1,1);
          if (iVar1 == 0) {
            iVar1 = Validate_Response(local_34 & 0x3f,param_5,param_1,4);
          }
        }
        free(__ptr);
      }
      else {
        free(__ptr);
      }
    }
    else {
      free(__ptr);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Read_Write_BlkData @ 0x30069C34  (примерный размер ~1032 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: Blksize_Data_Transfer, Check_TranState, Form_Send_Cmd, Partial_Blk_Xfer, Validate_Command, __udiv32, memcpy, printf
 * Вызывают: sdmmcBlkDataRW
 * Константы: 0x30069C34
 * Данные: DAT_3006a470, DAT_3006a474, DAT_3006a52c, DAT_3006ab7c, DAT_3006ab80, DAT_3006ab84, DAT_3006ab88, DAT_3006ab8c
 * ---------------------------------------------------------------- */
int Read_Write_BlkData(int param_1,int param_2,uint param_3,int param_4,undefined4 param_5,
                      void *param_6,undefined4 param_7,undefined4 param_8,uint param_9)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint local_40;
  uint local_3c [4];
  
  bVar1 = true;
  local_3c[0] = *DAT_3006ab7c;
  local_3c[1] = DAT_3006ab7c[1];
  local_3c[2] = DAT_3006ab7c[2];
  local_3c[3] = DAT_3006ab7c[3];
  if (*DAT_3006ab80 != 0) {
    printf(DAT_3006ab84,param_9 >> 7,param_2,param_3);
    *DAT_3006ab88 = *DAT_3006ab88 + 1;
    if ((*DAT_3006ab88 & 7) == 0) {
      printf(DAT_3006ab8c);
    }
  }
  if (param_4 == 0) {
    iVar2 = -0x16;
  }
  else if (param_3 == 0) {
    iVar2 = 0x60;
  }
  else {
    iVar2 = Validate_Command(param_1,param_2,param_3,10);
    if ((iVar2 == 0) && (iVar2 = Check_TranState(param_1), iVar2 == 0)) {
      if ((param_9 & 0x80) == 0) {
        iVar5 = *(int *)(DAT_3006a474 + param_1 * 0x88);
      }
      else {
        iVar5 = *(int *)(DAT_3006a470 + param_1 * 0x88);
      }
      if ((*(char *)(DAT_3006a52c + param_1 * 0x88) == '\x01') &&
         (iVar3 = __udiv32(param_2,iVar5), param_2 != iVar5 * iVar3)) {
        bVar1 = false;
      }
      iVar3 = __udiv32(param_3,iVar5);
      if ((bVar1) && (param_3 == iVar5 * iVar3)) {
        iVar2 = Blksize_Data_Transfer
                          (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
      }
      else {
        if (bVar1) {
          local_3c[0] = 0;
        }
        else {
          iVar3 = __udiv32(param_2,iVar5);
          local_3c[0] = iVar5 - (param_2 - iVar5 * iVar3);
          if (param_3 < local_3c[0]) {
            local_3c[0] = param_3;
          }
        }
        iVar6 = param_3 - local_3c[0];
        iVar3 = __udiv32(iVar6,iVar5);
        local_3c[1] = iVar5 * iVar3;
        local_3c[2] = iVar6 - iVar5 * iVar3;
        for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
          uVar4 = local_3c[iVar3];
          if (uVar4 != 0) {
            iVar2 = __udiv32(uVar4,iVar5);
            if (uVar4 == iVar5 * iVar2) {
              iVar2 = Blksize_Data_Transfer
                                (param_1,param_2,uVar4,param_4,param_5,param_6,0,param_8,param_9);
            }
            else {
              iVar2 = Partial_Blk_Xfer(param_1,param_2,uVar4,param_4,param_5,param_6,param_8,param_9
                                      );
            }
            if (iVar2 != 0) {
              return iVar2;
            }
            param_2 = param_2 + uVar4;
            param_4 = param_4 + uVar4;
            iVar2 = 0;
          }
        }
      }
      if (iVar2 == 0) {
        iVar2 = Form_Send_Cmd(param_1,0xd,0,&local_40,1);
        if (iVar2 == 0) {
          iVar2 = 0;
          if (((local_40 & DAT_3006ae08) != 0) && (iVar2 = 0x6e, param_6 != (void *)0x0)) {
            memcpy(param_6,&local_40,4);
          }
        }
        else {
          iVar2 = 0x6e;
        }
      }
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * sdmmcGetStausPoll @ 0x3006A03C  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: Form_Send_Cmd
 * Вызывают: sdmmcStatusPollTask
 * Константы: 0x3006A03C
 * Данные: DAT_3006ae08
 * ---------------------------------------------------------------- */
undefined4 sdmmcGetStausPoll(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint local_10;
  
  iVar1 = Form_Send_Cmd(param_1,0xd,0,&local_10,1);
  if (iVar1 == 0) {
    uVar2 = 0;
    if ((local_10 & DAT_3006ae08) != 0) {
      uVar2 = 0x6e;
    }
  }
  else {
    uVar2 = 0x6e;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * Read_Write_StreamData @ 0x3006A0A0  (примерный размер ~564 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 7
 * Вызывает: Check_TranState, Form_Data_Command, Form_Send_Cmd, Send_cmd_to_host, Validate_Command, Validate_Response, memcpy
 * Константы: 0xFFFFFFC0, 0x3006A0A0
 * Данные: DAT_3006ae08, DAT_3006af04
 * ---------------------------------------------------------------- */
int Read_Write_StreamData
              (undefined4 param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5,
              void *param_6,undefined4 param_7,undefined4 param_8,uint param_9)

{
  int iVar1;
  uint uVar2;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  local_34 = *DAT_3006af04;
  local_30 = DAT_3006af04[1];
  local_2c = DAT_3006af04[2];
  local_28 = DAT_3006af04[3];
  iVar1 = Validate_Command(param_1,param_2,param_3,0xb);
  if (iVar1 == 0) {
    if (param_4 == 0) {
      iVar1 = -0x16;
    }
    else {
      iVar1 = Check_TranState(param_1);
      if (iVar1 == 0) {
        Form_Data_Command(param_1,param_2,param_3,param_9,&local_34,1);
        local_30 = 0;
        if ((param_9 & 0x80) == 0) {
          uVar2 = local_28 & 0xffffffc0;
          local_28 = uVar2 | 0xb;
          if (0x16 < param_3) {
            local_28 = uVar2 | 0x100b;
          }
        }
        else {
          uVar2 = local_28 & 0xffffffc0;
          local_28 = uVar2 | 0x14;
          if (6 < param_3) {
            local_28 = uVar2 | 0x1014;
          }
        }
        iVar1 = Send_cmd_to_host(&local_34,param_5,param_6,param_4,param_7,param_9,param_8,1,
                                 param_9 & 0x80,0);
        if (iVar1 == 0) {
          iVar1 = Validate_Response(local_28 & 0x3f,param_5,param_1,4);
          if (iVar1 == 0) {
            iVar1 = Form_Send_Cmd(param_1,0xd,0,&local_38,1);
            if (iVar1 == 0) {
              iVar1 = 0;
              if (((local_38 & DAT_3006ae08) != 0) && (iVar1 = 0x6e, param_6 != (void *)0x0)) {
                memcpy(param_6,&local_38,4);
              }
            }
            else {
              iVar1 = 0x6e;
            }
          }
        }
        else {
          iVar1 = 0x21;
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Stop_Transfer @ 0x3006A2D4  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: Form_Send_Cmd, Validate_Command, Validate_Response
 * Константы: 0x3006A2D4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int Stop_Transfer(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_10 [4];
  
  iVar1 = Validate_Command(param_1,0,0,0xffffffff);
  if ((iVar1 == 0) && (iVar1 = Form_Send_Cmd(param_1,0xc,0,auStack_10,1), iVar1 == 0)) {
    iVar1 = Validate_Response(0xc,auStack_10,param_1,0xff);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Abort_transfer @ 0x3006A35C  (примерный размер ~232 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: Form_Send_Cmd, Validate_Command, Validate_Response
 * Константы: 0x3006A35C, 0x8FFFFFFF, 0x80000000
 * Данные: DAT_3006b210, DAT_3006b214
 * ---------------------------------------------------------------- */
int Abort_transfer(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined1 auStack_1c [4];
  
  iVar1 = Validate_Command(param_1,0,param_2,0x10);
  if ((iVar1 == 0) &&
     (iVar1 = Form_Send_Cmd(param_1,0x65,
                            param_2 & 0xff & DAT_3006b210 | DAT_3006b214 & 0x8fffffff | 0x80000000,
                            auStack_1c,0), iVar1 == 0)) {
    iVar1 = Validate_Response(0x34,auStack_1c,param_1,0xff);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Suspend_Transfer @ 0x3006A444  (примерный размер ~576 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: Read_Write_IPreg, SDIO_RdWr_Direct, SDIO_RdWr_Extended, Set_Reset_CNTRLreg, Validate_Command
 * Константы: 0x3006A444
 * Данные: DAT_3006b35c, DAT_3006b430
 * ---------------------------------------------------------------- */
int Suspend_Transfer(int param_1,uint param_2,int param_3)

{
  int iVar1;
  byte local_24 [4];
  uint local_20;
  undefined1 auStack_1c [4];
  
  local_20 = 0;
  if (param_2 == 0) {
    iVar1 = 0x47;
  }
  else {
    iVar1 = Validate_Command(param_1,0,param_2,0x10);
    if (iVar1 == 0) {
      if ((*(byte *)(DAT_3006b35c + param_1 * 0x88) & 8) == 0) {
        iVar1 = 0x3c;
      }
      else {
        iVar1 = SDIO_RdWr_Extended(param_1,0,0xc,2,local_24,auStack_1c,0,1,0,0,0x50);
        if (iVar1 == 0) {
          if ((local_24[0] & 1) == 0) {
            iVar1 = 0x5a;
          }
          else if ((local_24[0] & 0xf) == param_2) {
            local_24[0] = 2;
            iVar1 = SDIO_RdWr_Direct(param_1,0,0xc,local_24,auStack_1c,1,1,2);
            if (iVar1 == 0) {
              if ((local_24[0] & 3) != 0) {
                iVar1 = 0;
                while ((iVar1 < 0xf &&
                       (SDIO_RdWr_Direct(param_1,0,0xc,local_24,auStack_1c,0,0,2),
                       (local_24[0] & 3) != 0))) {
                  iVar1 = iVar1 + 1;
                }
                if (0xe < iVar1) {
                  return 0x3e;
                }
              }
              local_20 = local_20 | 0x100;
              Set_Reset_CNTRLreg(local_20,1);
              do {
              } while (*(int *)(DAT_3006b430 + 0x14) != 0);
              if (param_3 != 0) {
                Read_Write_IPreg(0x5c,param_3,0);
              }
              iVar1 = 0;
            }
          }
          else {
            iVar1 = 0x3d;
          }
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Resume_Transfer @ 0x3006A684  (примерный размер ~720 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: Form_SDIO_CmdReg, Form_Send_Cmd, SDIO_RdWr_Direct, Send_cmd_to_host, Validate_Command, Validate_Response
 * Константы: 0x3006A684, 0xFFFFFF00, 0x8FFFFFFF, 0x80000000
 * Данные: DAT_3006b210, DAT_3006b35c, DAT_3006b434, DAT_3006b438, DAT_3006b43c
 * ---------------------------------------------------------------- */
int Resume_Transfer(int param_1,uint param_2,int param_3,int param_4,uint *param_5,
                   undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9)

{
  int iVar1;
  byte local_3c [4];
  uint local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  int local_28;
  
  local_34 = *DAT_3006b434;
  local_30 = DAT_3006b434[1];
  local_2c = DAT_3006b434[2];
  local_28 = DAT_3006b434[3];
  local_38 = 0;
  if (param_2 == 0) {
    iVar1 = 0x47;
  }
  else {
    iVar1 = Validate_Command(param_1,0,param_2,0x10);
    if (iVar1 == 0) {
      if ((*(byte *)(DAT_3006b35c + param_1 * 0x88) & 8) == 0) {
        iVar1 = 0x3c;
      }
      else if (param_4 == 0) {
        iVar1 = -0x16;
      }
      else if (param_3 == 0) {
        iVar1 = 0x26;
      }
      else {
        SDIO_RdWr_Direct(param_1,0,0xf,local_3c,param_5,0,0,2);
        if ((*param_5 >> 0xc & 3) == 2) {
          iVar1 = 0x3f;
        }
        else if (((*param_5 & 0x3000) != 0) ||
                (iVar1 = Form_Send_Cmd(param_1,7,0,param_5,1), iVar1 == 0)) {
          if (((uint)local_3c[0] & 1 << (param_2 & 0xff)) == 0) {
            iVar1 = 0x67;
          }
          else {
            Form_SDIO_CmdReg(&local_34,param_1,0x34,param_9);
            local_38 = ((local_38 & 0xffffff00 | param_2 & 0xff) & DAT_3006b210 | DAT_3006b438) &
                       0x8fffffff | 0x80000000;
            if (*(short *)(DAT_3006b43c + param_2 * 2 + param_1 * 0x88) == 0) {
              iVar1 = 0x47;
            }
            else {
              local_30 = (uint)*(ushort *)(DAT_3006b43c + param_2 * 2 + param_1 * 0x88);
              local_34 = param_3;
              local_2c = local_38;
              iVar1 = Send_cmd_to_host(&local_34,param_5,param_6,param_4,param_7,param_9,param_8,1,1
                                       ,param_9 >> 6 & 1);
              if (((iVar1 == 0) &&
                  (iVar1 = Validate_Response(0x34,param_5,param_1,0xff), iVar1 == 0)) &&
                 ((*param_5 & 0x80) == 0)) {
                iVar1 = 0x40;
              }
            }
          }
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Wr_Protect_CardData @ 0x3006A954  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: Check_TranState, Form_Send_Cmd, Validate_Command, Validate_Response
 * Константы: 0x3006A954
 * ---------------------------------------------------------------- */
int Wr_Protect_CardData(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char cVar2;
  
  iVar1 = Validate_Command(param_1,param_2,0,0xc);
  if ((iVar1 == 0) && (iVar1 = Check_TranState(param_1), iVar1 == 0)) {
    cVar2 = (param_4 == 0) + '\x1c';
    iVar1 = Form_Send_Cmd(param_1,cVar2,param_2,param_3,1);
    if (iVar1 == 0) {
      iVar1 = Validate_Response(cVar2,param_3,param_1,4);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * ChangeEndian @ 0x3006AA14  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: Read_SD_Reg, Set_Clr_WrProt
 * Константы: 0x3006AA14
 * ---------------------------------------------------------------- */
void ChangeEndian(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  for (iVar2 = 0; iVar3 = param_2 - (param_2 >> 0x1f), iVar2 < param_2 / 2; iVar2 = iVar2 + 1) {
    uVar1 = *(undefined1 *)(param_1 + iVar2);
    *(undefined1 *)(param_1 + iVar2) = *(undefined1 *)(param_1 + (iVar3 - iVar2) + -1);
    *(undefined1 *)(param_1 + (iVar3 - iVar2) + -1) = uVar1;
    param_2 = iVar3;
  }
  return;
}

/* ----------------------------------------------------------------
 * Form_CSD_Write_Cmd @ 0x3006AA70  (примерный размер ~256 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Set_Clr_WrProt
 * Константы: 0x3006AA70, 0x80000000, 0xFFDFFFFF, 0xFFE0FFFF, 0xFFFF7FFF, 0xFFFFBFFF, 0xFFFFEFFF, 0xFFFFF7FF
 * Данные: DAT_3006b440
 * ---------------------------------------------------------------- */
undefined4 Form_CSD_Write_Cmd(undefined4 *param_1,uint param_2)

{
  param_1[3] = param_1[3] | 0x80000000;
  param_1[3] = param_1[3] & 0xffdfffff;
  param_1[3] = param_1[3] & 0xffe0ffff | (param_2 & 0x1f) << 0x10;
  param_1[3] = param_1[3] & 0xffff7fff;
  param_1[3] = param_1[3] & 0xffffbfff;
  param_1[3] = param_1[3] | 0x2000;
  param_1[3] = param_1[3] & 0xffffefff;
  param_1[3] = param_1[3] & 0xfffff7ff;
  param_1[3] = param_1[3] | 0x400;
  param_1[3] = param_1[3] | 0x200;
  param_1[3] = param_1[3] | 0x100;
  param_1[3] = param_1[3] & 0xffffff7f;
  param_1[3] = param_1[3] | 0x40;
  param_1[3] = param_1[3] & 0xffffffc0 | 0x1b;
  param_1[2] = 0;
  *param_1 = 0x10;
  param_1[1] = *(undefined4 *)(DAT_3006b440 + param_2 * 0x88);
  return 0;
}

/* ----------------------------------------------------------------
 * Set_Clr_WrProt @ 0x3006AB70  (примерный размер ~768 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 11
 * Вызывает: ChangeEndian, Check_TranState, Form_CSD_Write_Cmd, Repack_csd, Send_cmd_to_host, SetBlockLength, Validate_Command, Validate_Response, calcCrc7, memset, printf
 * Вызывают: Card_Lock
 * Константы: 0x3006AB70, 0xFFFFFFFF
 * Данные: DAT_3006b440, DAT_3006b444, DAT_3006b448, DAT_3006b44c, DAT_3006b450, DAT_3006b454, DAT_3006b458, DAT_3006b45c
 * ---------------------------------------------------------------- */
int Set_Clr_WrProt(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_40 [4];
  undefined1 uStack_3c;
  byte local_3b;
  byte local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2c = *DAT_3006b444;
  local_28 = DAT_3006b444[1];
  local_24 = DAT_3006b444[2];
  local_20 = DAT_3006b444[3];
  iVar1 = Validate_Command(param_1,0,0,0xffffffff);
  if ((iVar1 == 0) && (iVar1 = Check_TranState(param_1), iVar1 == 0)) {
    iVar2 = *(int *)(DAT_3006b440 + param_1 * 0x88);
    if (iVar2 != 0x10) {
      iVar1 = SetBlockLength(param_1,0x10,1,1);
    }
    if (iVar1 == 0) {
      Form_CSD_Write_Cmd(&local_2c,param_1);
      memset(&uStack_3c,0,0x10);
      if (*(char *)(DAT_3006b448 + param_1 * 0x88) == '\0') {
        Repack_csd(&uStack_3c,param_1 * 0x88 + DAT_3006b44c,0);
      }
      else {
        Repack_csd(&uStack_3c,param_1 * 0x88 + DAT_3006b44c,1);
      }
      if (param_3 == 0) {
        local_3b = local_3b & 0xef;
      }
      else {
        local_3b = local_3b | 0x10;
      }
      ChangeEndian(&uStack_3c,0x10);
      iVar1 = calcCrc7(&uStack_3c,0x78);
      local_2d = local_2d | (byte)(iVar1 << 1) | 1;
      printf(DAT_3006b454,(uint)*(byte *)(DAT_3006b450 + param_1 * 0x88));
      printf(DAT_3006b45c,(uint)*(byte *)(DAT_3006b458 + param_1 * 0x88));
      iVar1 = Send_cmd_to_host(&local_2c,auStack_40,0,&uStack_3c,0,0,0,1,1,1);
      if (iVar1 == 0) {
        iVar1 = Validate_Response(0x1b,auStack_40,param_1,4);
        if (param_2 == 0) {
          if (param_3 == 0) {
            *(undefined1 *)(param_1 * 0x88 + DAT_3006b458) = 0;
          }
          else {
            *(undefined1 *)(param_1 * 0x88 + DAT_3006b458) = 1;
          }
        }
        else if (param_3 == 0) {
          *(undefined1 *)(param_1 * 0x88 + DAT_3006b450) = 0;
        }
        else {
          *(undefined1 *)(param_1 * 0x88 + DAT_3006b450) = 1;
        }
      }
      else {
        iVar1 = 0x21;
      }
      if (iVar2 != 0x10) {
        SetBlockLength(param_1,iVar2,1,1);
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Default_CmdReg_forDataCmd @ 0x3006AE70  (примерный размер ~256 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: Card_Lock, Get_WrProtect_Status
 * Константы: 0x3006AE70, 0x80000000, 0xFFDFFFFF, 0xFFE0FFFF, 0xFFFF7FFF, 0xFFFFBFFF, 0xFFFFEFFF, 0xFFFFF7FF
 * ---------------------------------------------------------------- */
undefined4 Default_CmdReg_forDataCmd(int param_1,uint param_2,uint param_3,uint param_4)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x80000000;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffdfffff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffe0ffff | (param_2 & 0x1f) << 0x10;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffff7fff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffbfff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x2000;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffefff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffff7ff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffbff | (param_4 & 1) << 10;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x200;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x100;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffff7f;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x40;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffc0 | param_3 & 0x3f;
  return 0;
}

/* ----------------------------------------------------------------
 * Get_WrProtect_Status @ 0x3006AF70  (примерный размер ~432 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: Check_TranState, Default_CmdReg_forDataCmd, Send_cmd_to_host, SetBlockLength, Validate_Command, Validate_Response
 * Константы: 0x3006AF70
 * Данные: DAT_3006b460, DAT_3006b464
 * ---------------------------------------------------------------- */
int Get_WrProtect_Status(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_28 = *DAT_3006b460;
  local_24 = DAT_3006b460[1];
  local_20 = DAT_3006b460[2];
  local_1c = DAT_3006b460[3];
  iVar1 = Validate_Command(param_1,param_2,0,0xd);
  if (iVar1 == 0) {
    if (param_3 == 0) {
      iVar1 = -0x16;
    }
    else {
      iVar1 = Check_TranState(param_1);
      if (iVar1 == 0) {
        iVar2 = *(int *)(DAT_3006b464 + param_1 * 0x88);
        if (iVar2 != 4) {
          iVar1 = SetBlockLength(param_1,4,0,1);
        }
        if (iVar1 == 0) {
          Default_CmdReg_forDataCmd(&local_28,param_1,0x1e,0);
          local_28 = 4;
          local_24 = *(undefined4 *)(DAT_3006b464 + param_1 * 0x88);
          local_20 = param_2;
          iVar1 = Send_cmd_to_host(&local_28,auStack_2c,0,param_3,0,0,0,1,0,0);
          if (iVar1 == 0) {
            iVar1 = Validate_Response(0x1e,auStack_2c,param_1,4);
          }
          else {
            iVar1 = 0x21;
          }
          if (iVar2 != 4) {
            SetBlockLength(param_1,iVar2,0,1);
          }
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sdmmcErasePollBusyBit @ 0x3006B120  (примерный размер ~260 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: Read_Write_IPreg, taskDelay
 * Вызывают: Erase_Card_Data
 * Константы: 0x3006B120, 0xFFFFFFFF
 * Данные: DAT_3006b468
 * ---------------------------------------------------------------- */
undefined4 sdmmcErasePollBusyBit(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint local_18;
  
  iVar4 = DAT_3006b468;
  do {
    local_18 = 0;
    Read_Write_IPreg(0x48,&local_18,0);
    iVar3 = iVar4;
    if ((local_18 & 0x200) == 0) break;
    iVar3 = iVar4 + -1;
    bVar1 = 0 < iVar4;
    iVar4 = iVar3;
  } while (bVar1);
  if (iVar3 < 1) {
    iVar4 = 500;
    do {
      taskDelay(2);
      local_18 = 0;
      Read_Write_IPreg(0x48,&local_18,0);
      iVar3 = iVar4;
      if ((local_18 & 0x200) == 0) break;
      iVar3 = iVar4 + -1;
      bVar1 = 0 < iVar4;
      iVar4 = iVar3;
    } while (bVar1);
    if (iVar3 < 1) {
      iVar4 = 5;
      do {
        taskDelay(1000);
        local_18 = 0;
        Read_Write_IPreg(0x48,&local_18,0);
        iVar3 = iVar4;
        if ((local_18 & 0x200) == 0) break;
        iVar3 = iVar4 + -1;
        bVar1 = 0 < iVar4;
        iVar4 = iVar3;
      } while (bVar1);
      if (iVar3 < 1) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * Erase_Card_Data @ 0x3006B224  (примерный размер ~492 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: Check_TranState, Form_Send_Cmd, Validate_Command, Validate_Response, printf, sdmmcErasePollBusyBit
 * Вызывают: sdmmcEraseBlk, testerase
 * Константы: 0x3006B224
 * Данные: DAT_3006b448, DAT_3006b46c, DAT_3006b470
 * ---------------------------------------------------------------- */
int Erase_Card_Data(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    iVar1 = -0x16;
  }
  else {
    iVar1 = Validate_Command(param_2,param_3,param_4,0xe);
    if ((iVar1 == 0) && (iVar1 = Check_TranState(param_2), iVar1 == 0)) {
      if (*(char *)(DAT_3006b448 + param_2 * 0x88) == '\0') {
        uVar2 = 0x23;
      }
      else {
        uVar2 = 0x20;
      }
      iVar1 = Form_Send_Cmd(param_2,uVar2,param_3,param_1,1);
      if (iVar1 == 0) {
        iVar1 = Validate_Response(uVar2,param_1,param_2,4);
        if (iVar1 == 0x4e) {
          iVar1 = 0x4e;
        }
        else {
          if (*(char *)(DAT_3006b448 + param_2 * 0x88) == '\0') {
            uVar2 = 0x24;
          }
          else {
            uVar2 = 0x21;
          }
          iVar1 = Form_Send_Cmd(param_2,uVar2,param_4,param_1,1);
          if (iVar1 == 0) {
            iVar1 = Validate_Response(uVar2,param_1,param_2,4);
            if (iVar1 == 0x4e) {
              iVar1 = 0x4e;
            }
            else {
              iVar1 = Form_Send_Cmd(param_2,0x26,0,param_1,1);
              if (iVar1 == 0) {
                iVar1 = Validate_Response(0x26,param_1,param_2,4);
                if (iVar1 == 0) {
                  iVar1 = sdmmcErasePollBusyBit();
                  if (iVar1 != 0) {
                    printf(DAT_3006b470);
                  }
                }
                else {
                  printf(DAT_3006b46c);
                }
              }
            }
          }
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Set_CardLock_Attributes @ 0x3006B410  (примерный размер ~492 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Card_Lock
 * Константы: 0x3006B410, 0x3006B42C
 * Данные: DAT_3006b474
 * ---------------------------------------------------------------- */
void Set_CardLock_Attributes(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0xff) < 9) {
                    /* WARNING: Could not recover jumptable at 0x3006b42c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_3006b474 + (param_2 & 0xff) * 4))();
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * Card_Lock @ 0x3006B5FC  (примерный размер ~1072 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 9
 * Вызывает: Check_TranState, Default_CmdReg_forDataCmd, Send_cmd_to_host, SetBlockLength, Set_CardLock_Attributes, Set_Clr_WrProt, Validate_Command, Validate_Response, memcpy
 * Константы: 0x3006B5FC, 0xFFFFFFFF
 * Данные: DAT_3006c450, DAT_3006c5f0, DAT_3006c77c, DAT_3006c780, DAT_3006c8e0
 * ---------------------------------------------------------------- */
int Card_Lock(int param_1,byte *param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  byte local_4c [36];
  
  local_5c = *DAT_3006c5f0;
  local_58 = DAT_3006c5f0[1];
  local_54 = DAT_3006c5f0[2];
  local_50 = DAT_3006c5f0[3];
  bVar2 = false;
  bVar1 = false;
  iVar3 = Validate_Command(param_1,0,0,0xffffffff);
  if (iVar3 == 0) {
    if ((param_3 == 0) || (param_2 == (byte *)0x0)) {
      iVar3 = -0x16;
    }
    else {
      bVar4 = *param_2 & 0xf;
      if ((((bVar4 == 3) || (bVar4 == 6)) || (bVar4 == 7)) || (8 < bVar4)) {
        iVar3 = 0x60;
      }
      else {
        if (bVar4 == 8) {
          if (*(char *)(DAT_3006c77c + param_1 * 0x88) != '\0') {
            return 0x47;
          }
        }
        else if ((*(uint *)(DAT_3006c450 + param_1 * 0x88) & 4) == 0) {
          if (*(int *)(param_2 + 4) != 0) {
            return 0x60;
          }
          if ((*(int *)(param_2 + 0xc) == 0) || (param_2[8] == 0)) {
            return -0x16;
          }
          if (0x10 < param_2[8]) {
            return 0x43;
          }
          bVar2 = false;
          bVar1 = true;
        }
        else {
          if ((*(int *)(param_2 + 4) == 0) || (param_2[1] == 0)) {
            return 0x60;
          }
          if (0x10 < param_2[1]) {
            return 0x43;
          }
          bVar2 = true;
          bVar1 = false;
          if ((*param_2 & 1) != 0) {
            if ((*(int *)(param_2 + 0xc) == 0) || (param_2[8] == 0)) {
              return 0x60;
            }
            if (0x10 < param_2[8]) {
              return 0x43;
            }
            bVar1 = true;
          }
        }
        iVar3 = Check_TranState(param_1);
        if (iVar3 == 0) {
          local_4c[0] = bVar4;
          if (bVar4 == 8) {
            bVar5 = 1;
          }
          else {
            bVar5 = 2;
            iVar6 = 2;
            if (bVar2) {
              memcpy(local_4c + 2,*(void **)(param_2 + 4),(uint)param_2[1]);
              iVar6 = param_2[1] + 2;
              bVar5 = param_2[1] + 2;
            }
            if (bVar1) {
              memcpy(local_4c + iVar6,*(void **)(param_2 + 0xc),(uint)param_2[8]);
              bVar5 = bVar5 + param_2[8];
            }
            local_4c[1] = bVar5 - 2;
          }
          Default_CmdReg_forDataCmd(&local_5c,param_1,0x2a,1);
          local_54 = 0;
          local_5c = (uint)bVar5;
          local_58 = (uint)bVar5;
          uVar7 = *(uint *)(DAT_3006c780 + param_1 * 0x88);
          if (bVar5 != uVar7) {
            iVar3 = SetBlockLength(param_1,bVar5,1,1);
          }
          if (iVar3 == 0) {
            iVar3 = Send_cmd_to_host(&local_5c,param_3,0,local_4c,0,0,0,1,1,1);
            if (iVar3 == 0) {
              iVar3 = Validate_Response(0x2a,param_3,param_1,4);
              if (((iVar3 == 0) && (Set_CardLock_Attributes(param_1,bVar4), bVar4 == 8)) &&
                 (*(char *)(DAT_3006c8e0 + param_1 * 0x88) != '\0')) {
                iVar3 = Set_Clr_WrProt(param_1,1,0);
                if (iVar3 == 0) {
                  *(undefined1 *)(param_1 * 0x88 + DAT_3006c8e0) = 0;
                  iVar3 = 0;
                }
                else {
                  iVar3 = 0x66;
                }
              }
            }
            else {
              iVar3 = 0x21;
            }
            if (bVar5 != uVar7) {
              SetBlockLength(param_1,uVar7,1,1);
            }
          }
        }
      }
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * Mask_Interrupt @ 0x3006BA2C  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: Set_IP_Parameters
 * Константы: 0x3006BA2C
 * Данные: DAT_3006c8e4
 * ---------------------------------------------------------------- */
undefined4 Mask_Interrupt(uint param_1,int param_2)

{
  undefined4 uVar1;
  uint local_4;
  
  if ((param_1 & DAT_3006c8e4) == 0) {
    local_4 = param_1;
    if (param_2 == 0) {
      Set_IP_Parameters(8,&local_4);
    }
    else {
      Set_IP_Parameters(7,&local_4);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0x41;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * SD_ErrLogFromIntShow @ 0x3006BA90  (примерный размер ~496 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: OSAL_LogMsg
 * Константы: 0x3006BA90
 * Данные: DAT_3006ca00, DAT_3006ca04, DAT_3006ca08, DAT_3006ca0c, DAT_3006ca10, DAT_3006ca14, DAT_3006ca18, DAT_3006cb14
 * ---------------------------------------------------------------- */
void SD_ErrLogFromIntShow(void)

{
  OSAL_LogMsg(DAT_3006ca04,*(undefined4 *)(DAT_3006ca00 + 0x48),0,0,0,0,0);
  OSAL_LogMsg(DAT_3006ca08,*(undefined4 *)(DAT_3006ca00 + 0x34),0,0,0,0,0);
  OSAL_LogMsg(DAT_3006ca0c,*(undefined4 *)(DAT_3006ca00 + 0x30),0,0,0,0,0);
  OSAL_LogMsg(DAT_3006ca10,*(undefined4 *)(DAT_3006ca00 + 0x2c),0,0,0,0,0);
  OSAL_LogMsg(DAT_3006ca14,*(undefined4 *)(DAT_3006ca00 + 0x28),0,0,0,0,0);
  OSAL_LogMsg(DAT_3006ca18,*(undefined4 *)(DAT_3006ca00 + 0x24),0,0,0,0,0);
  OSAL_LogMsg(DAT_3006cb14,*(undefined4 *)(DAT_3006ca00 + 0x20),0,0,0,0,0);
  OSAL_LogMsg(DAT_3006cb18,*(undefined4 *)(DAT_3006ca00 + 0x1c),0,0,0,0,0);
  OSAL_LogMsg(DAT_3006cb1c,*(undefined4 *)(DAT_3006ca00 + 0x18),0,0,0,0,0);
  OSAL_LogMsg(DAT_3006cb20,*(undefined4 *)(DAT_3006ca00 + 0x10),0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * SD_RecordErrLogFromInt @ 0x3006BC80  (примерный размер ~316 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: OSAL_SemGive
 * Вызывают: ISR_Callback
 * Константы: 0x3006BC80
 * Данные: DAT_3006ca00, DAT_3006cb24, DAT_3006ccdc
 * ---------------------------------------------------------------- */
void SD_RecordErrLogFromInt(uint param_1)

{
  if ((param_1 & DAT_3006cb24) != 0) {
    if ((param_1 & 2) != 0) {
      *(int *)(DAT_3006ca00 + 0x48) = *(int *)(DAT_3006ca00 + 0x48) + 1;
    }
    if ((param_1 & 0x40) != 0) {
      *(int *)(DAT_3006ca00 + 0x34) = *(int *)(DAT_3006ca00 + 0x34) + 1;
    }
    if ((param_1 & 0x80) != 0) {
      *(int *)(DAT_3006ca00 + 0x30) = *(int *)(DAT_3006ca00 + 0x30) + 1;
    }
    if ((param_1 & 0x100) != 0) {
      *(int *)(DAT_3006ca00 + 0x2c) = *(int *)(DAT_3006ca00 + 0x2c) + 1;
    }
    if ((param_1 & 0x200) != 0) {
      *(int *)(DAT_3006ca00 + 0x28) = *(int *)(DAT_3006ca00 + 0x28) + 1;
    }
    if ((param_1 & 0x400) != 0) {
      *(int *)(DAT_3006ca00 + 0x24) = *(int *)(DAT_3006ca00 + 0x24) + 1;
    }
    if ((param_1 & 0x800) != 0) {
      *(int *)(DAT_3006ca00 + 0x20) = *(int *)(DAT_3006ca00 + 0x20) + 1;
    }
    if ((param_1 & 0x1000) != 0) {
      *(int *)(DAT_3006ca00 + 0x1c) = *(int *)(DAT_3006ca00 + 0x1c) + 1;
    }
    if ((param_1 & 0x2000) != 0) {
      *(int *)(DAT_3006ca00 + 0x18) = *(int *)(DAT_3006ca00 + 0x18) + 1;
    }
    if ((param_1 & 0x8000) != 0) {
      *(int *)(DAT_3006ca00 + 0x10) = *(int *)(DAT_3006ca00 + 0x10) + 1;
    }
    OSAL_SemGive(*DAT_3006ccdc);
  }
  return;
}

/* ----------------------------------------------------------------
 * Form_Stop_Cmd @ 0x3006BDBC  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: sd_mmc_event_Handler
 * Константы: 0x3006BDBC
 * ---------------------------------------------------------------- */
void Form_Stop_Cmd(void)

{
  return;
}

/* ----------------------------------------------------------------
 * sd_mmc_event_Handler @ 0x3006BDC0  (примерный размер ~1200 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: Form_Stop_Cmd, OSAL_SemGive, Read_Response, Read_Write_FIFO, Send_SD_MMC_Command
 * Вызывают: ISR_Callback
 * Константы: 0x3006BDC0
 * Данные: DAT_3006c8e4, DAT_3006cce0, DAT_3006cce4, DAT_3006cce8, DAT_3006cf90, DAT_3006cf94, DAT_3006cf98, DAT_3006cf9c
 * ---------------------------------------------------------------- */
undefined4 sd_mmc_event_Handler(uint *param_1)

{
  int iVar1;
  undefined1 auStack_20 [16];
  
  if ((DAT_3006cce0[5] != 0) && (*DAT_3006cce4 == 0)) {
    if (((*param_1 & DAT_3006cce8) != 0) && ((DAT_3006cce0[4] & 0x10U) != 0)) {
      DAT_3006cce0[8] = DAT_3006cce0[8] | *param_1 & DAT_3006cce8;
      if ((DAT_3006cce0[4] & 0x20U) == 0) {
        if (DAT_3006cce0[6] != 0) {
          (*(code *)DAT_3006cce0[6])(DAT_3006cce0[8]);
        }
      }
      else {
        *DAT_3006cce4 = 1;
      }
    }
    if (((*param_1 & DAT_3006cce8) == 0) || ((DAT_3006cce0[4] & 0x10U) == 0)) {
      if ((*param_1 & 0x20) == 0) {
        if (((*param_1 & 0x10) != 0) && (DAT_3006cce0[3] != 0)) {
          iVar1 = Read_Write_FIFO(*DAT_3006cce0 + (DAT_3006cce0[2] - DAT_3006cce0[3]),
                                  DAT_3006cce0[3],1,DAT_3006cce0[7]);
          DAT_3006cce0[3] = DAT_3006cce0[3] - iVar1;
        }
      }
      else if (DAT_3006cce0[3] != 0) {
        iVar1 = Read_Write_FIFO(*DAT_3006cce0 + (DAT_3006cce0[2] - DAT_3006cce0[3]),DAT_3006cce0[3],
                                0,DAT_3006cce0[7]);
        DAT_3006cce0[3] = DAT_3006cce0[3] - iVar1;
      }
    }
  }
  if (DAT_3006cce0[5] != 0) {
    if ((*param_1 & 8) != 0) {
      if (DAT_3006cce0[3] != 0) {
        iVar1 = Read_Write_FIFO(*DAT_3006cce0 + (DAT_3006cce0[2] - DAT_3006cce0[3]),DAT_3006cce0[3],
                                DAT_3006cce0[1],DAT_3006cce0[7]);
        DAT_3006cce0[3] = DAT_3006cce0[3] - iVar1;
        if (DAT_3006cce0[3] != 0) {
          iVar1 = Read_Write_FIFO(*DAT_3006cce0 + (DAT_3006cce0[2] - DAT_3006cce0[3]),
                                  DAT_3006cce0[3],DAT_3006cce0[1],DAT_3006cce0[7]);
          DAT_3006cce0[3] = DAT_3006cce0[3] - iVar1;
        }
      }
      DAT_3006cce0[5] = 0;
      OSAL_SemGive(*DAT_3006cf90);
      if (DAT_3006cce0[6] != 0) {
        (*(code *)DAT_3006cce0[6])(*param_1);
      }
      DAT_3006cce0[6] = 0;
    }
    if (((*param_1 & 0x400) != 0) && (DAT_3006cce0[3] != 0)) {
      iVar1 = Read_Write_FIFO(*DAT_3006cce0 + (DAT_3006cce0[2] - DAT_3006cce0[3]),DAT_3006cce0[3],
                              DAT_3006cce0[1],DAT_3006cce0[7]);
      DAT_3006cce0[3] = DAT_3006cce0[3] - iVar1;
    }
  }
  if ((*param_1 & 1) != 0) {
    *DAT_3006cf94 = 1;
  }
  if ((((*param_1 & 0x4000) != 0) && (DAT_3006cce0[5] != 0)) && (*DAT_3006cf98 == 0)) {
    *DAT_3006cce4 = 0;
  }
  if (((*param_1 & 4) != 0) && (*(int *)(DAT_3006cf9c + 0x14) != 0)) {
    if (*DAT_3006cf98 == 0) {
      if ((*param_1 & DAT_3006c8e4) == 0) {
        if (*(int *)(DAT_3006cf9c + 4) != 0) {
          Read_Response(*(undefined4 *)(DAT_3006cf9c + 4),*(undefined4 *)(DAT_3006cf9c + 0x1c));
        }
      }
      else {
        *(undefined4 *)(DAT_3006cf9c + 0x18) = 1;
      }
      if (*DAT_3006cce4 == 0) {
        *(undefined4 *)(DAT_3006cf9c + 0x14) = 0;
      }
      else {
        *DAT_3006cce4 = 0;
        *DAT_3006cf98 = 1;
        Form_Stop_Cmd(auStack_20);
        Send_SD_MMC_Command(auStack_20);
      }
    }
    else if ((*param_1 & DAT_3006c8e4) != 0) {
      if (*(int *)(DAT_3006cf9c + 8) != 0) {
        Read_Response(*(undefined4 *)(DAT_3006cf9c + 8),0);
      }
      *DAT_3006cf98 = 0;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ISR_Callback @ 0x3006C270  (примерный размер ~400 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: OSAL_LogMsg, OSAL_SemGive, Read_Write_IPreg, SD_RecordErrLogFromInt, Set_IP_Parameters, sd_mmc_event_Handler, sdmmcExcWrite, semGive
 * Константы: 0x3006C270
 * Данные: DAT_3006cce0, DAT_3006cf90, DAT_3006cf94, DAT_3006cf9c, DAT_3006d1ac, DAT_3006d1b0, DAT_3006d1b4, DAT_3006d1b8
 * ---------------------------------------------------------------- */
void ISR_Callback(void)

{
  undefined4 local_c;
  undefined4 local_8 [2];
  
  local_c = 4;
  local_8[0] = 0;
  *DAT_3006d1ac = 0;
  Set_IP_Parameters(0xe,&local_c);
  Read_Write_IPreg(0x40,DAT_3006d1ac,0);
  Read_Write_IPreg(0x44,DAT_3006d1ac,1);
  SD_RecordErrLogFromInt(*DAT_3006d1ac);
  if ((*DAT_3006d1ac & DAT_3006d1b0) != 0) {
    sd_mmc_event_Handler(DAT_3006d1ac);
  }
  *(uint *)(DAT_3006cf9c + 0x10) = *DAT_3006d1ac & DAT_3006d1b4;
  if (*(int *)(DAT_3006cf9c + 0x10) != 0) {
    OSAL_LogMsg(DAT_3006d1b8,*DAT_3006d1ac,0,0,0,0,0);
    Read_Write_IPreg(0x8c,local_8,0);
    OSAL_LogMsg(DAT_3006d1bc,local_8[0],0,0,0,0,0);
    sdmmcExcWrite();
  }
  if ((*DAT_3006d1ac & 0x100) != 0) {
    *(undefined4 *)(DAT_3006cce0 + 0x14) = 0;
    OSAL_SemGive(*DAT_3006cf90);
  }
  Read_Write_IPreg(0x44,DAT_3006d1ac,1);
  *DAT_3006d1ac = 0;
  Set_IP_Parameters(0xd,&local_c);
  if (*DAT_3006cf94 == 1) {
    semGive(*DAT_3006d2c8);
  }
  return;
}

/* ----------------------------------------------------------------
 * sdmmcPollBusyBit @ 0x3006C400  (примерный размер ~256 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: Read_Write_IPreg, taskDelay
 * Вызывают: sdmmcBlkDataRW, sdmmcStatusPollTask
 * Константы: 0x3006C400, 0xFFFFFFFF
 * Данные: DAT_3006d2cc
 * ---------------------------------------------------------------- */
undefined4 sdmmcPollBusyBit(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint local_18;
  
  iVar4 = DAT_3006d2cc;
  do {
    local_18 = 0;
    Read_Write_IPreg(0x48,&local_18,0);
    iVar3 = iVar4;
    if ((local_18 & 0x200) == 0) break;
    iVar3 = iVar4 + -1;
    bVar1 = 0 < iVar4;
    iVar4 = iVar3;
  } while (bVar1);
  if (iVar3 < 1) {
    iVar4 = 500;
    do {
      taskDelay(2);
      local_18 = 0;
      Read_Write_IPreg(0x48,&local_18,0);
      iVar3 = iVar4;
      if ((local_18 & 0x200) == 0) break;
      iVar3 = iVar4 + -1;
      bVar1 = 0 < iVar4;
      iVar4 = iVar3;
    } while (bVar1);
    if (iVar3 < 1) {
      iVar4 = 5;
      do {
        taskDelay(1000);
        local_18 = 0;
        Read_Write_IPreg(0x48,&local_18,0);
        iVar3 = iVar4;
        if ((local_18 & 0x200) == 0) break;
        iVar3 = iVar4 + -1;
        bVar1 = 0 < iVar4;
        iVar4 = iVar3;
      } while (bVar1);
      if (iVar3 < 1) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * copy_csd @ 0x3006C500  (примерный размер ~700 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3006C500
 * Данные: DAT_3006c77c, DAT_3006c8e0, DAT_3006d3e4, DAT_3006d3e8, DAT_3006d3ec, DAT_3006d3f0, DAT_3006d3f4, DAT_3006d3f8
 * ---------------------------------------------------------------- */
void copy_csd(undefined1 *param_1,int param_2)

{
  *param_1 = *(undefined1 *)(DAT_3006d3e4 + param_2 * 0x88);
  param_1[1] = *(undefined1 *)(DAT_3006d3e8 + param_2 * 0x88);
  param_1[2] = *(undefined1 *)(DAT_3006d3ec + param_2 * 0x88);
  param_1[3] = *(undefined1 *)(DAT_3006d3f0 + param_2 * 0x88);
  param_1[4] = *(undefined1 *)(DAT_3006d3f4 + param_2 * 0x88);
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(DAT_3006d3f8 + param_2 * 0x88);
  param_1[8] = *(undefined1 *)(DAT_3006d3fc + param_2 * 0x88);
  param_1[9] = *(undefined1 *)(DAT_3006d400 + param_2 * 0x88);
  param_1[10] = *(undefined1 *)(DAT_3006d404 + param_2 * 0x88);
  param_1[0xb] = *(undefined1 *)(DAT_3006d408 + param_2 * 0x88);
  param_1[0xc] = *(undefined1 *)(DAT_3006d40c + param_2 * 0x88);
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(DAT_3006d410 + param_2 * 0x88);
  param_1[0x10] = *(undefined1 *)(DAT_3006d414 + param_2 * 0x88);
  param_1[0x11] = *(undefined1 *)(DAT_3006d418 + param_2 * 0x88);
  param_1[0x12] = *(undefined1 *)(DAT_3006d41c + param_2 * 0x88);
  param_1[0x13] = *(undefined1 *)(DAT_3006d420 + param_2 * 0x88);
  param_1[0x14] = *(undefined1 *)(DAT_3006d528 + param_2 * 0x88);
  param_1[0x15] = *(undefined1 *)(DAT_3006d52c + param_2 * 0x88);
  param_1[0x16] = *(undefined1 *)(DAT_3006d530 + param_2 * 0x88);
  param_1[0x15] = *(undefined1 *)(DAT_3006d52c + param_2 * 0x88);
  param_1[0x16] = *(undefined1 *)(DAT_3006d530 + param_2 * 0x88);
  param_1[0x17] = *(undefined1 *)(DAT_3006d534 + param_2 * 0x88);
  param_1[0x18] = *(undefined1 *)(DAT_3006d538 + param_2 * 0x88);
  param_1[0x19] = *(undefined1 *)(DAT_3006d53c + param_2 * 0x88);
  param_1[0x1a] = *(undefined1 *)(DAT_3006d540 + param_2 * 0x88);
  param_1[0x1b] = *(undefined1 *)(DAT_3006d544 + param_2 * 0x88);
  param_1[0x1c] = *(undefined1 *)(DAT_3006d548 + param_2 * 0x88);
  param_1[0x1d] = *(undefined1 *)(DAT_3006d54c + param_2 * 0x88);
  param_1[0x1e] = *(undefined1 *)(DAT_3006d550 + param_2 * 0x88);
  param_1[0x1f] = *(undefined1 *)(DAT_3006c77c + param_2 * 0x88);
  param_1[0x20] = *(undefined1 *)(DAT_3006c8e0 + param_2 * 0x88);
  param_1[0x21] = *(undefined1 *)(DAT_3006d658 + param_2 * 0x88);
  param_1[0x22] = *(undefined1 *)(DAT_3006d65c + param_2 * 0x88);
  return;
}

/* ----------------------------------------------------------------
 * Check_Card_Insert @ 0x3006C7BC  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3006C7BC
 * Данные: DAT_3006d660
 * ---------------------------------------------------------------- */
undefined4 Check_Card_Insert(int param_1)

{
  return *(undefined4 *)(DAT_3006d660 + param_1 * 0x88);
}

/* ----------------------------------------------------------------
 * Check_Card_Eject @ 0x3006C7DC  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3006C7DC
 * Данные: DAT_3006d664
 * ---------------------------------------------------------------- */
undefined4 Check_Card_Eject(int param_1)

{
  return *(undefined4 *)(DAT_3006d664 + param_1 * 0x88);
}

/* ----------------------------------------------------------------
 * sdmmcTimerCallBack @ 0x3006C7FC  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: OSAL_SemGive
 * Константы: 0x3006C7FC
 * Данные: DAT_3006d668
 * ---------------------------------------------------------------- */
void sdmmcTimerCallBack(void)

{
  OSAL_SemGive(*DAT_3006d668);
  return;
}

/* ----------------------------------------------------------------
 * sdmmc_break_point @ 0x3006C808  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3006C808
 * ---------------------------------------------------------------- */
void sdmmc_break_point(void)

{
  return;
}

/* ----------------------------------------------------------------
 * sdmmc_break_set @ 0x3006C80C  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3006C80C
 * Данные: DAT_3006d66c
 * ---------------------------------------------------------------- */
void sdmmc_break_set(int param_1)

{
  *DAT_3006d66c = (uint)(param_1 != 0);
  return;
}

/* ----------------------------------------------------------------
 * MMC_ShowCardInfo @ 0x3006C830  (примерный размер ~3728 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: sd_mmc_bus_show
 * Константы: 0x3006C830
 * Данные: DAT_3006d3e4, DAT_3006d3e8, DAT_3006d3ec, DAT_3006d3f0, DAT_3006d3f4, DAT_3006d3f8, DAT_3006d3fc, DAT_3006d400
 * ---------------------------------------------------------------- */
void MMC_ShowCardInfo(int param_1)

{
  logMsg(DAT_3006d670,param_1,0,0,0,0,0);
  logMsg(DAT_3006d678,*(undefined1 *)(DAT_3006d674 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d6dc,*(undefined4 *)(DAT_3006d6d8 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d6e0,0,0,0,0,0,0);
  logMsg(DAT_3006d6e8,*(undefined4 *)(DAT_3006d6e4 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d6ec,*(undefined1 *)(DAT_3006d3e4 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d6f0,*(undefined1 *)(DAT_3006d3e8 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d6f4,*(undefined1 *)(DAT_3006d3ec + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d6f8,*(undefined1 *)(DAT_3006d3f0 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d6fc,*(undefined1 *)(DAT_3006d3f4 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d700,*(undefined2 *)(DAT_3006d3f8 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d704,*(undefined1 *)(DAT_3006d3fc + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d708,*(undefined1 *)(DAT_3006d400 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d70c,*(undefined1 *)(DAT_3006d404 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d710,*(undefined1 *)(DAT_3006d408 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d714,*(undefined1 *)(DAT_3006d40c + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d718,*(undefined2 *)(DAT_3006d410 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d71c,*(undefined1 *)(DAT_3006d414 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d720,*(undefined1 *)(DAT_3006d418 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d724,*(undefined1 *)(DAT_3006d41c + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d728,*(undefined1 *)(DAT_3006d420 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d728,*(undefined1 *)(DAT_3006d420 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d72c,*(undefined1 *)(DAT_3006d528 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d730,*(undefined1 *)(DAT_3006d52c + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d734,*(undefined1 *)(DAT_3006d530 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d738,*(undefined1 *)(DAT_3006d534 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d73c,*(undefined1 *)(DAT_3006d538 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d740,*(undefined1 *)(DAT_3006d53c + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d744,*(undefined1 *)(DAT_3006d540 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d748,*(undefined1 *)(DAT_3006d544 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d74c,*(undefined1 *)(DAT_3006d548 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d750,*(undefined1 *)(DAT_3006d54c + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d754,*(undefined1 *)(DAT_3006d550 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d75c,*(undefined1 *)(DAT_3006d758 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d764,*(undefined1 *)(DAT_3006d760 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d768,*(undefined1 *)(DAT_3006d658 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d76c,*(undefined1 *)(DAT_3006d65c + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d774,*(undefined1 *)(DAT_3006d770 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d77c,*(undefined2 *)(DAT_3006d778 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d784,*(undefined1 *)(DAT_3006d780 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d78c,*(undefined4 *)(DAT_3006d788 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d794,*(undefined1 *)(DAT_3006d790 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d79c,param_1 * 0x88 + DAT_3006d798 + 0x34,0,0,0,0,0);
  logMsg(DAT_3006d7a4,*(undefined1 *)(DAT_3006d7a0 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d7ac,*(undefined1 *)(DAT_3006d7a8 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d7b4,*(undefined1 *)(DAT_3006d7b0 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d7bc,*(undefined1 *)(DAT_3006d7b8 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d7c4,*(undefined1 *)(DAT_3006d7c0 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d7cc,*(undefined1 *)(DAT_3006d7c8 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d7d4,*(undefined4 *)(DAT_3006d7d0 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d7dc,*(undefined1 *)(DAT_3006d7d8 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d7e4,*(undefined4 *)(DAT_3006d7e0 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d7ec,*(undefined4 *)(DAT_3006d7e8 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d7f4,*(undefined4 *)(DAT_3006d7f0 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d7fc,*(undefined4 *)(DAT_3006d7f8 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d804,*(undefined4 *)(DAT_3006d800 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d80c,*(undefined4 *)(DAT_3006d808 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d810,*(undefined4 *)(DAT_3006d660 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d814,*(undefined4 *)(DAT_3006d664 + param_1 * 0x88),0,0,0,0,0);
  logMsg(DAT_3006d818,*(uint *)(DAT_3006d7e8 + param_1 * 0x88) >> 1 & 1,0,0,0,0,0);
  logMsg(DAT_3006d81c,*(uint *)(DAT_3006d7e8 + param_1 * 0x88) >> 2 & 1,0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * sd_mmc_bus_show @ 0x3006D6C0  (примерный размер ~352 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: MMC_ShowCardInfo, sdmmcCardInfo
 * Константы: 0x3006D6C0
 * ---------------------------------------------------------------- */
void sd_mmc_bus_show(void)

{
  MMC_ShowCardInfo(0);
  sdmmcCardInfo(0);
  return;
}

/* ----------------------------------------------------------------
 * sdupgrade_setDbg @ 0x3006D820  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3006D820
 * Данные: DAT_3006db0c
 * ---------------------------------------------------------------- */
void sdupgrade_setDbg(undefined4 param_1)

{
  *DAT_3006db0c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * Read_Write_IPreg @ 0x3006D838  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 21 | Вызывает: 0
 * Вызывают: Card_Detect_Handler, Enumerate_SD_card_Stack, FUN_30067a78, ISR_Callback, Poll_Cmd_Accept, Read_ClkSource_Info, Read_IP_ID_number, Read_Write_TimeOut, SD_MMC_Bus_Init, Send_cmd_to_host_raw
 *           ...
 * Константы: 0x3006D838, 0xFFFFFFEA
 * Данные: DAT_3006db10, DAT_3006db14
 * ---------------------------------------------------------------- */
undefined4 Read_Write_IPreg(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*DAT_3006db10 == 0) {
    uVar1 = 0xffffffea;
  }
  else if (param_1 < 0x100) {
    if (param_3 == 0) {
      *param_2 = *(undefined4 *)(*DAT_3006db14 + param_1);
    }
    else {
      *(undefined4 *)(*DAT_3006db14 + param_1) = *param_2;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0x25;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Poll_Cmd_Accept @ 0x3006D8B0  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: Read_Write_IPreg, printf
 * Вызывают: Assert_n_Poll_startcmd, Send_SD_MMC_Command
 * Константы: 0x3006D8B0, 0x80000000
 * Данные: DAT_3006db14, DAT_3006db18, DAT_3006db1c
 * ---------------------------------------------------------------- */
undefined4 Poll_Cmd_Accept(void)

{
  int local_10;
  int local_c;
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  local_10 = 0;
  while( true ) {
    if ((*(uint *)(*DAT_3006db14 + 0x2c) & 0x80000000) == 0) {
      Read_Write_IPreg(0x2c,local_8,0);
      return 0;
    }
    if ((*(uint *)(*DAT_3006db14 + 0x44) & 0x1000) != 0) break;
    for (local_c = 0; local_c < 0xf; local_c = local_c + 1) {
    }
    local_10 = local_10 + 1;
    if (99 < local_10) {
      printf(DAT_3006db1c);
      return 0x23;
    }
  }
  printf(DAT_3006db18);
  return 0x22;
}

/* ----------------------------------------------------------------
 * Send_SD_MMC_Command @ 0x3006D96C  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: Poll_Cmd_Accept, printf
 * Вызывают: Send_cmd_to_host_raw, sd_mmc_event_Handler
 * Константы: 0x3006D96C, 0xFFFFFFEA, 0xFFFFFFFF
 * Данные: DAT_3006db10, DAT_3006db14, DAT_3006db20
 * ---------------------------------------------------------------- */
undefined4 Send_SD_MMC_Command(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (*DAT_3006db10 == 0) {
    uVar1 = 0xffffffea;
  }
  else if (param_1 == (undefined4 *)0x0) {
    printf(DAT_3006db20);
    uVar1 = 0xffffffff;
  }
  else {
    *(undefined4 *)(*DAT_3006db14 + 0x20) = *param_1;
    *(undefined4 *)(*DAT_3006db14 + 0x1c) = param_1[1];
    *(undefined4 *)(*DAT_3006db14 + 0x28) = param_1[2];
    *(undefined4 *)(*DAT_3006db14 + 0x2c) = param_1[3];
    uVar1 = Poll_Cmd_Accept();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Read_Response @ 0x3006D9EC  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: sd_mmc_event_Handler
 * Константы: 0xFFFFFFEA, 0x3006D9EC
 * Данные: DAT_3006db10, DAT_3006db14
 * ---------------------------------------------------------------- */
undefined4 Read_Response(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*DAT_3006db10 == 0) {
    uVar1 = 0xffffffea;
  }
  else if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    *param_1 = *(undefined4 *)(*DAT_3006db14 + 0x30);
    if (param_2 != 0) {
      param_1[1] = *(undefined4 *)(*DAT_3006db14 + 0x34);
      param_1[2] = *(undefined4 *)(*DAT_3006db14 + 0x38);
      param_1[3] = *(undefined4 *)(*DAT_3006db14 + 0x3c);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Read_PendingData_Status @ 0x3006DA74  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFEA, 0x3006DA74
 * Данные: DAT_3006db10, DAT_3006db14
 * ---------------------------------------------------------------- */
undefined4 Read_PendingData_Status(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (*DAT_3006db10 == 0) {
    uVar1 = 0xffffffea;
  }
  else if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    *param_1 = *(undefined4 *)(*DAT_3006db14 + 0x5c);
    param_1[1] = *(undefined4 *)(*DAT_3006db14 + 0x60);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Set_IP_Parameters @ 0x3006DAD0  (примерный размер ~1104 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: Enumerate_card, ISR_Callback, Mask_Interrupt, Power_ON_Off, Read_Wait, Send_cmd_to_host_raw, Set_FIFO_Threshold, Set_SD_Mode
 * Константы: 0x3006DAD0, 0xFFFFFFEA, 0x3006DB08
 * Данные: DAT_3006db10, DAT_3006db24, DAT_3006ee2c
 * ---------------------------------------------------------------- */
undefined4 Set_IP_Parameters(uint param_1)

{
  undefined4 uVar1;
  
  if (*DAT_3006db10 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    if (param_1 < 0x13) {
                    /* WARNING: Could not recover jumptable at 0x3006db08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(DAT_3006db24 + param_1 * 4))();
      return uVar1;
    }
    printf(DAT_3006ee2c);
    uVar1 = 0x24;
  }
  return uVar1;
}

