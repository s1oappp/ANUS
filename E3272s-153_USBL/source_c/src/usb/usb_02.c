/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : usb — USB device-стек: jos/jslave, DWC dcd_syn_hs, CDC/ACM, uwd, порты
 * Часть  : 2 (функций: 36, адреса 0x3005F6FC..0x30062924)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * FUN_3005f6fc @ 0x3005F6FC  (примерный размер ~216 байт)
 * Модуль: usb | Вызывают: 3 | Вызывает: 4
 * Вызывает: BSP_TRACE, FUN_3005f64c, FUN_3005f68c, uwd_cdc_read
 * Вызывают: FUN_3005f7d4, FUN_300601e0, FUN_30061708
 * Константы: 0x3005F6FC
 * Данные: DAT_30060728
 * ---------------------------------------------------------------- */
int FUN_3005f6fc(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    if (0 < iVar3) {
      return 0;
    }
    iVar1 = FUN_3005f68c(param_1);
    if (iVar1 == 0) break;
    iVar2 = uwd_cdc_read(*(undefined4 *)(param_1 + 0xcf0),iVar1 + 0xc,*(undefined4 *)(param_1 + 100)
                         ,iVar1);
    if (iVar2 != 0) {
      FUN_3005f64c(param_1,iVar1);
      return iVar2;
    }
    *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
    iVar3 = iVar3 + 1;
  }
  BSP_TRACE(4,0x14,DAT_30060728,0,0,0,0,0,0);
  return -1;
}

/* ----------------------------------------------------------------
 * FUN_3005f7d4 @ 0x3005F7D4  (примерный размер ~140 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 4
 * Вызывает: BSP_TRACE, FUN_3005f6fc, FUN_300628c4, taskIdSelf
 * Константы: 0x3005F7D4
 * Данные: DAT_3006072c, DAT_30060730
 * ---------------------------------------------------------------- */
undefined4 FUN_3005f7d4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  BSP_TRACE(4,0x14,DAT_30060730,*(undefined4 *)(param_1 + 0x44),DAT_3006072c,0,0,0,0);
  *(undefined4 *)(param_1 + 0x24) = 1;
  uVar1 = taskIdSelf();
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  iVar2 = FUN_3005f6fc(param_1);
  if (iVar2 == 0) {
    FUN_300628c4(param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3005f860 @ 0x3005F860  (примерный размер ~112 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, FUN_3005f620, FUN_300628c4
 * Константы: 0x3005F860
 * Данные: DAT_30060734
 * ---------------------------------------------------------------- */
undefined4 FUN_3005f860(int param_1)

{
  BSP_TRACE(4,0x14,DAT_30060734,*(undefined4 *)(param_1 + 0x44),0x250,0,0,0,0);
  *(undefined4 *)(param_1 + 0x24) = 0;
  FUN_3005f620(param_1);
  FUN_300628c4(param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3005f8d0 @ 0x3005F8D0  (примерный размер ~212 байт)
 * Модуль: usb | Вызывают: 3 | Вызывает: 1
 * Вызывает: free
 * Вызывают: FUN_3005f9a4, FUN_3006044c, FUN_30061708
 * Константы: 0x3005F8D0
 * ---------------------------------------------------------------- */
void FUN_3005f8d0(int param_1)

{
  uint uVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x48) + 0xc) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x48) + 0xc) = 0;
  }
  *(int *)(param_1 + 0x50) = param_1 + 0x50;
  *(int *)(param_1 + 0x54) = param_1 + 0x50;
  *(int *)(param_1 + 0x58) = param_1 + 0x58;
  *(int *)(param_1 + 0x5c) = param_1 + 0x58;
  for (uVar1 = 0; uVar1 < *(uint *)(param_1 + 0x68); uVar1 = uVar1 + 1) {
    *(undefined4 *)(uVar1 * 0x24 + *(int *)(param_1 + 0x48) + 0xc) = 0;
    *(undefined4 *)(uVar1 * 0x24 + *(int *)(param_1 + 0x48) + 0x10) = 0;
    *(undefined4 *)(uVar1 * 0x24 + *(int *)(param_1 + 0x48) + 0x14) = 0;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    free(*(void **)(param_1 + 0x48));
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005f9a4 @ 0x3005F9A4  (примерный размер ~256 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 5
 * Вызывает: FUN_3005f8d0, free, jtask_uninit, memset, semDelete
 * Вызывают: FUN_3005faa4, uwd_acm_app_init
 * Константы: 0x3005F9A4
 * Данные: DAT_30060918
 * ---------------------------------------------------------------- */
void FUN_3005f9a4(int param_1)

{
  if (*(int *)(param_1 + 0xce4) != 0) {
    semDelete(*(undefined4 *)(param_1 + 0xce4));
    *(undefined4 *)(param_1 + 0xce4) = 0;
  }
  if (*(int *)(param_1 + 0x90) != 0) {
    semDelete(*(undefined4 *)(param_1 + 0x90));
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  if (*(int *)(param_1 + 0xce8) != 0) {
    semDelete(*(undefined4 *)(param_1 + 0xce8));
    *(undefined4 *)(param_1 + 0xce8) = 0;
  }
  if (*(int *)(param_1 + 0xb0) != 0) {
    free(*(void **)(param_1 + 0xb0));
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    free(*(void **)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  if (*(int *)(param_1 + 0xcec) != 0) {
    jtask_uninit(*(undefined4 *)(param_1 + 0xcec));
    *(undefined4 *)(param_1 + 0xcec) = 0;
  }
  if (*(int *)(param_1 + 0xce0) != 0) {
    jtask_uninit(*(undefined4 *)(param_1 + 0xce0));
    *(undefined4 *)(param_1 + 0xce0) = 0;
  }
  FUN_3005f8d0(param_1);
  memset((void *)(param_1 + 0x48),0,0x4c);
  memset((void *)(param_1 + 0x94),0,DAT_30060918);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005faa4 @ 0x3005FAA4  (примерный размер ~100 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_3005f620, FUN_3005f9a4, iosDevDelete
 * Константы: 0x3005FAA4
 * Данные: DAT_3006091c, DAT_30060920
 * ---------------------------------------------------------------- */
undefined4 FUN_3005faa4(int param_1)

{
  FUN_3005f620(param_1);
  FUN_3005f9a4(param_1);
  *(undefined4 *)(param_1 + 0x44) = 0;
  iosDevDelete(param_1);
  if (*DAT_3006091c != 0) {
    *DAT_3006091c = *DAT_3006091c + -1;
  }
  *DAT_30060920 = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3005fb08 @ 0x3005FB08  (примерный размер ~52 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30062924
 * Вызывают: FUN_3005fcf8
 * Константы: 0x3005FB08
 * ---------------------------------------------------------------- */
void FUN_3005fb08(int param_1,int param_2)

{
  FUN_30062924(param_2,param_1 + 0x58);
  *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + 1;
  *(undefined4 *)(param_2 + 8) = 2;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005fb3c @ 0x3005FB3C  (примерный размер ~84 байт)
 * Модуль: usb | Вызывают: 4 | Вызывает: 2
 * Вызывает: FUN_300628c8, FUN_300628e8
 * Вызывают: FUN_3005fb90, FUN_3006106c, FUN_300612f4, FUN_30061708
 * Константы: 0x3005FB3C
 * ---------------------------------------------------------------- */
int FUN_3005fb3c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_300628c8((int *)(param_1 + 0x58));
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x58);
    FUN_300628e8(iVar1);
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;
    *(undefined4 *)(iVar1 + 8) = 0;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3005fb90 @ 0x3005FB90  (примерный размер ~360 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 6
 * Вызывает: BSP_TRACE, FUN_3005f64c, FUN_3005f68c, FUN_3005fb3c, uwd_cdc_read, uwd_cdc_read_flow
 * Вызывают: FUN_3005fcf8
 * Константы: 0x3005FB90
 * Данные: DAT_30060924
 * ---------------------------------------------------------------- */
int FUN_3005fb90(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_3005f68c(param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_3005fb3c(param_1);
    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
    BSP_TRACE(4,0x14,DAT_30060924,*(undefined4 *)(param_1 + 0x44),iVar1,0,0,0,0);
    if (iVar1 == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = uwd_cdc_read_flow(*(undefined4 *)(param_1 + 0xcf0),iVar1 + 0xc,
                                *(undefined4 *)(param_1 + 100),iVar1);
      *(undefined4 *)(param_1 + 0x70) = 1;
      if (iVar2 == 0) {
        *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
      }
      else {
        FUN_3005f64c(param_1,iVar1);
      }
    }
  }
  else {
    if (*(uint *)(param_1 + 0x68) >> 1 < *(uint *)(param_1 + 0x6c)) {
      iVar2 = uwd_cdc_read_flow(*(undefined4 *)(param_1 + 0xcf0),iVar1 + 0xc,
                                *(undefined4 *)(param_1 + 100),iVar1);
      *(undefined4 *)(param_1 + 0x70) = 1;
    }
    else {
      iVar2 = uwd_cdc_read(*(undefined4 *)(param_1 + 0xcf0),iVar1 + 0xc,
                           *(undefined4 *)(param_1 + 100),iVar1);
    }
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
    }
    else {
      FUN_3005f64c(param_1,iVar1);
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_3005fcf8 @ 0x3005FCF8  (примерный размер ~552 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 9
 * Вызывает: BSP_TRACE, FUN_3005f64c, FUN_3005fb08, FUN_3005fb90, FUN_300628c4, cacheInvalidate, jos_safe_enter_d, jos_safe_leave_d, semGive
 * Константы: 0x3005FCF8
 * Данные: DAT_30060928, DAT_3006092c, DAT_30060930, DAT_30060934, DAT_30060938, DAT_3006093c, DAT_30060940, DAT_30060944
 * ---------------------------------------------------------------- */
void FUN_3005fcf8(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 int param_6)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_5 + 0x7c);
  if (param_1 == 1) {
    BSP_TRACE(3,0x14,DAT_3006092c,*(undefined4 *)(param_5 + 0x44),DAT_30060928,0,0,0,0);
    *(int *)(param_5 + 0x8c) = *(int *)(param_5 + 0x8c) + 1;
  }
  else if (param_1 == -1) {
    BSP_TRACE(4,0x14,DAT_30060934,*(undefined4 *)(param_5 + 0x44),DAT_30060930,0,0,0,0);
    *(int *)(param_5 + 0x8c) = *(int *)(param_5 + 0x8c) + 1;
    if ((*(int *)(param_5 + 0x8c) == 1) || ((*(uint *)(param_5 + 0x8c) & 0x7f) == 0)) {
      FUN_300628c4(param_5);
    }
  }
  if ((*(int *)(param_5 + 0x28) == 0) || (param_1 != 0)) {
    if (*(int *)(param_5 + 0x74) == 0) {
      FUN_3005f64c(param_5,param_6);
    }
    else {
      *(undefined4 *)(param_6 + 0x18) = DAT_30060938;
      *(undefined4 *)(param_5 + 0x74) = 0;
      FUN_3005fb08(param_5,param_6);
      semGive(*(undefined4 *)(param_5 + 0x90));
    }
    if (param_1 == 0) {
      FUN_3005fb90(param_5);
    }
  }
  else if (param_3 == 0) {
    FUN_3005f64c(param_5,param_6);
    FUN_3005fb90(param_5);
  }
  else {
    *(int *)(param_6 + 0x18) = param_3;
    *(undefined4 *)(param_6 + 0x1c) = 0;
    *(int *)(param_6 + 0x20) = param_3;
    *(int *)(param_5 + 0x80) = param_3 + *(int *)(param_5 + 0x80);
    cacheInvalidate(1,*(undefined4 *)(param_6 + 0xc),param_3);
    if (*(int *)(DAT_3006093c + 0x20) != 0) {
      (**(code **)(DAT_3006093c + 0x20))();
    }
    FUN_3005fb08(param_5,param_6);
    FUN_3005fb90(param_5);
    if (*(int *)(param_5 + 0x74) == 0) {
      if (pcVar1 != (code *)0x0) {
        jos_safe_leave_d(DAT_30060940,0x2f4);
        (*pcVar1)();
        jos_safe_enter_d(DAT_30060940,DAT_30060944);
      }
    }
    else {
      *(undefined4 *)(param_5 + 0x74) = 0;
      semGive(*(undefined4 *)(param_5 + 0x90));
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005ff20 @ 0x3005FF20  (примерный размер ~416 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 6
 * Вызывает: BSP_TRACE, FUN_300628c4, jos_safe_enter_d, jos_safe_leave_d, jtask_stop, semGive
 * Константы: 0x3005FF20
 * Данные: DAT_30060938, DAT_30060940, DAT_30060948, DAT_3006094c, DAT_30060950, DAT_30060954, DAT_30060958, DAT_3006095c
 * ---------------------------------------------------------------- */
void FUN_3005ff20(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  
  iVar3 = DAT_30060938;
  if (param_1 == 0) {
    iVar3 = param_4;
  }
  if (param_1 == 1) {
    *(int *)(param_3 + 0xcd4) = *(int *)(param_3 + 0xcd4) + 1;
  }
  else if (param_1 == -1) {
    BSP_TRACE(4,0x14,DAT_3006094c,*(undefined4 *)(param_3 + 0x44),DAT_30060948,0,0,0,0);
    *(int *)(param_3 + 0xcd4) = *(int *)(param_3 + 0xcd4) + 1;
    if ((*(int *)(param_3 + 0xcd4) == 1) || ((*(uint *)(param_3 + 0xcd4) & 0x7f) == 0)) {
      FUN_300628c4(param_3);
    }
  }
  if ((undefined4 *)(param_3 + 0x9c) == param_2) {
    *(int *)(param_3 + 0xa8) = iVar3;
    if (0 < iVar3) {
      *(int *)(param_3 + 0xb4) = iVar3 + *(int *)(param_3 + 0xb4);
    }
    semGive(*(undefined4 *)(param_3 + 0xce8));
  }
  else {
    pcVar2 = *(code **)(param_3 + 200);
    pcVar1 = *(code **)(param_3 + 0xcc);
    if ((0 < iVar3) &&
       (*(int *)(param_3 + 0xbc) = iVar3 + *(int *)(param_3 + 0xbc), *(int *)(param_3 + 0xc4) != 0))
    {
      jtask_stop(*(undefined4 *)(param_3 + 0xce0));
    }
    *(uint *)(param_3 + 0x98) = *(int *)(param_3 + 0x98) + 1U & 0xff;
    if (pcVar1 == (code *)0x0) {
      if (pcVar2 != (code *)0x0) {
        jos_safe_leave_d(DAT_30060940,DAT_30060958);
        (*pcVar2)(*param_2,iVar3);
        jos_safe_enter_d(DAT_30060940,DAT_3006095c);
      }
    }
    else {
      jos_safe_leave_d(DAT_30060940,DAT_30060950);
      (*pcVar1)(*param_2);
      jos_safe_enter_d(DAT_30060940,DAT_30060954);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300600c0 @ 0x300600C0  (примерный размер ~288 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Константы: 0x300600C0
 * Данные: DAT_30060960
 * ---------------------------------------------------------------- */
undefined4 FUN_300600c0(ushort param_1,int param_2)

{
  BSP_TRACE(1,0x14,DAT_30060960,*(undefined4 *)(param_2 + 0x44),param_1,0,0,0,0);
  *(uint *)(param_2 + 0x40) = (uint)param_1;
  if (((param_1 & 1) != 0) && ((*(int *)(param_2 + 0xd00) != 1 || (*(int *)(param_2 + 0x34) != 0))))
  {
    *(undefined4 *)(param_2 + 0xd00) = 1;
    *(undefined4 *)(param_2 + 0x34) = 0;
    if (*(code **)(param_2 + 0xcfc) != (code *)0x0) {
      (**(code **)(param_2 + 0xcfc))(1);
    }
  }
  if (((param_1 & 1) == 0) && ((*(int *)(param_2 + 0xd00) != 0 || (*(int *)(param_2 + 0x34) != 0))))
  {
    *(undefined4 *)(param_2 + 0xd00) = 0;
    *(undefined4 *)(param_2 + 0x34) = 0;
    if (*(code **)(param_2 + 0xcfc) != (code *)0x0) {
      (**(code **)(param_2 + 0xcfc))(0);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300601e0 @ 0x300601E0  (примерный размер ~112 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_TRACE, FUN_3005f6fc
 * Константы: 0x300601E0
 * Данные: DAT_30060964
 * ---------------------------------------------------------------- */
undefined4 FUN_300601e0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  BSP_TRACE(4,0x14,DAT_30060964,*(undefined4 *)(param_1 + 0x44),0,0,0,0,0);
  iVar1 = FUN_3005f6fc(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30060250 @ 0x30060250  (примерный размер ~156 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Константы: 0x30060250
 * Данные: DAT_30060968
 * ---------------------------------------------------------------- */
undefined4 FUN_30060250(int param_1)

{
  BSP_TRACE(4,0x14,DAT_30060968,*(undefined4 *)(param_1 + 0x44),0,0,0,0,0);
  if ((*(int *)(param_1 + 0xd00) != 0) || (*(int *)(param_1 + 0x34) != 0)) {
    *(undefined4 *)(param_1 + 0xd00) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    if (*(code **)(param_1 + 0xcfc) != (code *)0x0) {
      (**(code **)(param_1 + 0xcfc))(0);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300602ec @ 0x300602EC  (примерный размер ~44 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: memcpy
 * Константы: 0x300602EC
 * Данные: DAT_3006096c
 * ---------------------------------------------------------------- */
undefined4 FUN_300602ec(void *param_1,int param_2)

{
  memcpy((void *)(param_2 + DAT_3006096c),param_1,7);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30060318 @ 0x30060318  (примерный размер ~44 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: memcpy
 * Константы: 0x30060318
 * Данные: DAT_3006096c
 * ---------------------------------------------------------------- */
undefined4 FUN_30060318(void *param_1,int param_2)

{
  memcpy(param_1,(void *)(param_2 + DAT_3006096c),7);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30060344 @ 0x30060344  (примерный размер ~72 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30061708
 * Константы: 0x30060344
 * ---------------------------------------------------------------- */
int FUN_30060344(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar2 = 0;
  puVar1 = *(undefined4 **)*param_1;
  puVar4 = (undefined4 *)*param_1;
  while (puVar3 = puVar1, puVar4 != param_1) {
    iVar2 = iVar2 + 1;
    puVar1 = (undefined4 *)*puVar3;
    puVar4 = puVar3;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_3006038c @ 0x3006038C  (примерный размер ~192 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300613c4
 * Константы: 0x3006038C
 * Данные: DAT_30060970
 * ---------------------------------------------------------------- */
int FUN_3006038c(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 0x68);
  iVar5 = *(int *)(param_1 + 0x60) - *(int *)(param_1 + 0x48);
  iVar2 = *(int *)(param_1 + 0x60);
  iVar3 = (int)((longlong)iVar5 * (longlong)DAT_30060970 >> 0x23) - (iVar5 >> 0x1f);
  for (iVar5 = iVar3; -1 < iVar5; iVar5 = iVar5 + -1) {
    if (*(int *)(iVar2 + 0xc) == param_2) {
      return iVar2;
    }
    iVar2 = iVar2 + -0x24;
  }
  iVar5 = *(int *)(param_1 + 0x48) + iVar4 * 0x24;
  do {
    iVar4 = iVar4 + -1;
    iVar2 = iVar5 + -0x24;
    if (iVar4 <= iVar3) {
      return 0;
    }
    piVar1 = (int *)(iVar5 + -0x18);
    iVar5 = iVar2;
  } while (*piVar1 != param_2);
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_3006044c @ 0x3006044C  (примерный размер ~332 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_3005f8d0, FUN_30062924, malloc, memset
 * Вызывают: FUN_30060598, FUN_30061708
 * Константы: 0x3006044C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_3006044c(int param_1,uint param_2,undefined4 param_3)

{
  void *__s;
  undefined4 uVar1;
  uint uVar2;
  
  __s = malloc(param_2 * 0x24);
  if (__s == (void *)0x0) {
    FUN_3005f8d0(param_1);
    uVar1 = 0xffffffff;
  }
  else {
    memset(__s,0,param_2 * 0x24);
    *(void **)(param_1 + 0x48) = __s;
    *(void **)(param_1 + 0x60) = __s;
    *(void **)(param_1 + 0x4c) = (void *)((int)__s + param_2 * 0x24);
    *(int *)(param_1 + 0x50) = param_1 + 0x50;
    *(int *)(param_1 + 0x54) = param_1 + 0x50;
    *(int *)(param_1 + 0x58) = param_1 + 0x58;
    *(int *)(param_1 + 0x5c) = param_1 + 0x58;
    for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1) {
      *(undefined4 *)(uVar2 * 0x24 + *(int *)(param_1 + 0x48) + 0xc) = 0;
      *(undefined4 *)(uVar2 * 0x24 + *(int *)(param_1 + 0x48) + 0x10) = 0;
      *(undefined4 *)(uVar2 * 0x24 + *(int *)(param_1 + 0x48) + 0x14) = 0;
      *(undefined4 *)(uVar2 * 0x24 + *(int *)(param_1 + 0x48) + 8) = 1;
      FUN_30062924(*(int *)(param_1 + 0x48) + uVar2 * 0x24,param_1 + 0x50);
    }
    *(undefined4 *)(param_1 + 100) = param_3;
    *(uint *)(param_1 + 0x68) = param_2;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30060598 @ 0x30060598  (примерный размер ~424 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_3006044c, jtask_init, malloc, memalign, memset, semBCreate, semMCreate
 * Вызывают: uwd_acm_app_init
 * Константы: 0x30060598
 * Данные: DAT_30060918, DAT_3006096c, DAT_30060974
 * ---------------------------------------------------------------- */
undefined4 FUN_30060598(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  
  puVar4 = (undefined1 *)(param_1 + DAT_3006096c);
  puVar4[3] = 0;
  puVar4[2] = 1;
  puVar4[1] = 0xc2;
  *puVar4 = 0;
  *(undefined1 *)(param_1 + 0xcf8) = 0;
  *(undefined1 *)(param_1 + 0xcf9) = 0;
  *(undefined1 *)(param_1 + 0xcfa) = 8;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  memset((void *)(param_1 + 0x48),0,0x4c);
  memset((void *)(param_1 + 0x94),0,DAT_30060918);
  iVar1 = FUN_3006044c(param_1,0x20,0x800);
  if ((iVar1 == 0) && (iVar1 = memalign(0x20,0x800), iVar1 != 0)) {
    *(int *)(param_1 + 0xb0) = iVar1;
    pvVar2 = malloc(0x20);
    *(void **)(param_1 + 0x20) = pvVar2;
    if (*(int *)(param_1 + 0x20) != 0) {
      memset(*(void **)(param_1 + 0x20),0x20,0);
      if (*(int *)(param_1 + 0x90) == 0) {
        uVar3 = semBCreate(0,0);
        *(undefined4 *)(param_1 + 0x90) = uVar3;
      }
      if (*(int *)(param_1 + 0xce8) == 0) {
        uVar3 = semBCreate(0,0);
        *(undefined4 *)(param_1 + 0xce8) = uVar3;
      }
      if (*(int *)(param_1 + 0xce4) == 0) {
        uVar3 = semMCreate(4);
        *(undefined4 *)(param_1 + 0xce4) = uVar3;
      }
      if ((((*(int *)(param_1 + 0x90) != 0) && (*(int *)(param_1 + 0xce8) != 0)) &&
          (*(int *)(param_1 + 0xce4) != 0)) &&
         ((iVar1 = jtask_init(param_1 + DAT_30060974,0), iVar1 == 0 &&
          (iVar1 = jtask_init(param_1 + 0xce0,0), iVar1 == 0)))) {
        return 0;
      }
    }
  }
  return 7;
}

/* ----------------------------------------------------------------
 * FUN_30060740 @ 0x30060740  (примерный размер ~308 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_TRACE, iosDevAdd
 * Вызывают: FUN_300624c4
 * Константы: 0xFFFFFFFF, 0x30060740
 * Данные: DAT_30060920, DAT_30060978, DAT_3006097c, DAT_30060980, DAT_30060984, DAT_30060988, DAT_3006098c, DAT_30060990
 * ---------------------------------------------------------------- */
undefined4 FUN_30060740(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_30060978 < param_2) {
    BSP_TRACE(4,0x14,DAT_3006097c,DAT_30060980,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (*DAT_30060920 < 1) {
    BSP_TRACE(4,0x14,DAT_30060984,DAT_30060988,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = iosDevAdd(DAT_3006098c + DAT_30060990 * param_2,param_1,*DAT_30060920);
    if (iVar2 == -1) {
      BSP_TRACE(4,0x14,DAT_30060994,DAT_30060998,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30060874 @ 0x30060874  (примерный размер ~60 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: uwd_cdc_set_out_nak
 * Константы: 0x30060874
 * ---------------------------------------------------------------- */
void FUN_30060874(int param_1)

{
  if ((*(int *)(param_1 + 0x70) != 0) && (*(int *)(param_1 + 0x6c) == 0)) {
    uwd_cdc_set_out_nak(*(undefined4 *)(param_1 + 0xcf0),0);
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300608b0 @ 0x300608B0  (примерный размер ~56 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: uwd_cdc_abort_write
 * Константы: 0x300608B0
 * ---------------------------------------------------------------- */
void FUN_300608b0(int param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 0xcd8) = *(int *)(param_1 + 0xcd8) + 1;
  iVar1 = uwd_cdc_abort_write(*(undefined4 *)(param_1 + 0xcf0));
  if (iVar1 != 0) {
    *(int *)(param_1 + 0xcdc) = *(int *)(param_1 + 0xcdc) + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300608e8 @ 0x300608E8  (примерный размер ~416 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30061974
 * Константы: 0x300608E8, 0x30060914
 * Данные: DAT_3006099c, DAT_300609a0
 * ---------------------------------------------------------------- */
undefined4 FUN_300608e8(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((uint)(param_2 - DAT_3006099c) < 9) {
                    /* WARNING: Could not recover jumptable at 0x30060914. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_300609a0 + (param_2 - DAT_3006099c) * 4))();
    return uVar1;
  }
  return 0x47;
}

/* ----------------------------------------------------------------
 * FUN_30060a88 @ 0x30060A88  (примерный размер ~212 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Константы: 0x30060A88
 * Данные: DAT_300619e8, DAT_300619ec, DAT_300619f0, DAT_300619f4
 * ---------------------------------------------------------------- */
int FUN_30060a88(int param_1)

{
  if ((param_1 == 0) || (*(int *)(param_1 + 0x48) == 0)) {
    BSP_TRACE(4,0x14,DAT_300619e8,DAT_300619ec,0,0,0,0,0);
    param_1 = -1;
  }
  else if (*(int *)(param_1 + 0x28) == 0) {
    *(undefined4 *)(param_1 + 0x28) = 1;
    *(undefined4 *)(param_1 + 0xac) = 1;
  }
  else {
    BSP_TRACE(4,0x14,DAT_300619f0,DAT_300619f4,0,0,0,0,0);
    param_1 = -1;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * FUN_30060b5c @ 0x30060B5C  (примерный размер ~628 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 7
 * Вызывает: BSP_TRACE, FUN_300628c4, cacheFlush, jos_safe_enter_d, jos_safe_leave_d, jtask_schedule_d, uwd_cdc_write
 * Вызывают: FUN_30060dd0, FUN_30061974
 * Константы: 0x30060B5C
 * Данные: DAT_30061b14, DAT_30061b18, DAT_30061b1c, DAT_30061b20, DAT_30061b24, DAT_30061b28, DAT_30061b2c, DAT_30061bf8
 * ---------------------------------------------------------------- */
undefined4 FUN_30060b5c(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc4);
  if (((param_2 == 0) || (param_3 == 0)) ||
     ((*(int *)(param_1 + 0xac) != 0 && ((param_2 & 0x1f) != 0)))) {
    BSP_TRACE(0,0x14,DAT_30061b14,param_2,param_3,0,0,0,0);
    uVar1 = DAT_30061b18;
  }
  else if (*(int *)(param_1 + 0x24) == 0) {
    BSP_TRACE(0,0x14,DAT_30061b1c,DAT_30061b20,0,0,0,0,0);
    uVar1 = DAT_30061b18;
  }
  else {
    if (*(int *)(param_1 + 0xac) != 0) {
      cacheFlush(1,param_2,param_3);
    }
    jos_safe_enter_d(DAT_30061b24,DAT_30061b28);
    if ((*(int *)(param_1 + 0x94) + 1U & 0xff) == *(uint *)(param_1 + 0x98)) {
      BSP_TRACE(0,0x14,DAT_30061bf8,*(undefined4 *)(param_1 + 0x44),DAT_30061b2c,0,0,0,0);
      uVar1 = DAT_30061bfc;
      *(int *)(param_1 + 0xcd0) = *(int *)(param_1 + 0xcd0) + 1;
      if ((*(int *)(param_1 + 0xcd0) == 1) || ((*(uint *)(param_1 + 0xcd0) & 0x7f) == 0)) {
        FUN_300628c4(param_1);
      }
    }
    else {
      iVar2 = param_1 + *(int *)(param_1 + 0x94) * 0xc;
      *(uint *)(iVar2 + 0xd4) = param_2;
      *(uint *)(iVar2 + 0xd0) = param_2;
      *(undefined4 *)(iVar2 + 0xd8) = 0;
      iVar2 = uwd_cdc_write(*(undefined4 *)(param_1 + 0xcf0),(uint *)(iVar2 + 0xd0),param_3,param_3)
      ;
      if (iVar2 == 0) {
        *(int *)(param_1 + 0xc0) = param_3 + *(int *)(param_1 + 0xc0);
        *(uint *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1U & 0xff;
        uVar1 = 0;
        if (iVar3 != 0) {
          jtask_schedule_d(*(undefined4 *)(param_1 + 0xce0),iVar3,DAT_30061c9c,param_1,DAT_30061b24,
                           DAT_30061c98);
        }
      }
      else {
        BSP_TRACE(0,0x14,DAT_30061c00,DAT_30061c04,0,0,0,0,0);
        uVar1 = DAT_30061c08;
      }
    }
    jos_safe_leave_d(DAT_30061b24,DAT_30061ca0);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30060dd0 @ 0x30060DD0  (примерный размер ~668 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 9
 * Вызывает: BSP_TRACE, FUN_30060b5c, cacheFlush, jos_safe_enter_d, jos_safe_leave_d, memcpy, semGive, semTake, uwd_cdc_write
 * Константы: 0xFFFFFFFF, 0x30060DD0
 * Данные: DAT_30061b14, DAT_30061b18, DAT_30061b1c, DAT_30061b24, DAT_30061c00, DAT_30061c08, DAT_30061ca4, DAT_30061d50
 * ---------------------------------------------------------------- */
undefined4 FUN_30060dd0(int param_1,void *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) == 0)) {
    BSP_TRACE(0,0x14,DAT_30061ca4,DAT_30061d50,0,0,0,0,0);
    return DAT_30061d54;
  }
  if (*(int *)(param_1 + 200) != 0) {
    uVar1 = FUN_30060b5c(param_1,param_2,param_3);
    return uVar1;
  }
  iVar2 = *(int *)(param_1 + 0xac);
  if ((param_2 == (void *)0x0) || (param_3 == 0)) {
    BSP_TRACE(0,0x14,DAT_30061b14,param_2,param_3,0,0,0,0);
    return DAT_30061b18;
  }
  semTake(*(undefined4 *)(param_1 + 0xce4),0xffffffff);
  puVar3 = (undefined4 *)(param_1 + 0x9c);
  *(undefined4 *)(param_1 + 0xa4) = 0;
  if ((iVar2 == 0) || (((uint)param_2 & 0x1f) == 0)) {
    *(void **)(param_1 + 0xa0) = param_2;
    *puVar3 = param_2;
  }
  else {
    *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0xb0);
    *puVar3 = *(undefined4 *)(param_1 + 0xa0);
    uVar1 = 0;
    if (*(int *)(param_1 + 0xa0) == 0) goto LAB_30061058;
    if (0x800 < param_3) {
      param_3 = 0x800;
    }
    memcpy((void *)*puVar3,param_2,param_3);
  }
  if (iVar2 != 0) {
    cacheFlush(1,*puVar3,param_3);
  }
  jos_safe_enter_d(DAT_30061b24,DAT_30061e70);
  if (*(int *)(param_1 + 0x24) == 0) {
    jos_safe_leave_d(DAT_30061b24,DAT_30061e74);
    uVar1 = DAT_30061c08;
    BSP_TRACE(0,0x14,DAT_30061b1c,DAT_30061e78,0,0,0,0,0);
  }
  else {
    iVar2 = uwd_cdc_write(*(undefined4 *)(param_1 + 0xcf0),puVar3,param_3,param_3);
    jos_safe_leave_d(DAT_30061b24,DAT_30061e7c);
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0xb8) = param_3 + *(int *)(param_1 + 0xb8);
      semTake(*(undefined4 *)(param_1 + 0xce8),0xffffffff);
      jos_safe_enter_d(DAT_30061b24,DAT_30061f88);
      uVar1 = *(undefined4 *)(param_1 + 0xa8);
      jos_safe_leave_d(DAT_30061b24,DAT_30061f8c);
    }
    else {
      BSP_TRACE(0,0x14,DAT_30061c00,DAT_30061e80,0,0,0,0,0);
      uVar1 = DAT_30061c08;
    }
  }
LAB_30061058:
  semGive(*(undefined4 *)(param_1 + 0xce4));
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3006106c @ 0x3006106C  (примерный размер ~648 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 8
 * Вызывает: BSP_TRACE, FUN_3005f64c, FUN_3005fb3c, jos_safe_enter_d, jos_safe_leave_d, jtask_schedule_d, memcpy, semTake
 * Константы: 0xFFFFFFFF, 0x3006106C
 * Данные: DAT_30061b18, DAT_30061b24, DAT_30061c08, DAT_30061d54, DAT_30061f90, DAT_30061f94, DAT_30061f98, DAT_30061f9c
 * ---------------------------------------------------------------- */
size_t FUN_3006106c(int param_1,void *param_2,uint param_3)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) == 0)) {
    BSP_TRACE(4,0x14,DAT_30061f90,DAT_30061f94,0,0,0,0,0);
    sVar2 = DAT_30061d54;
  }
  else if ((param_2 == (void *)0x0) || (param_3 == 0)) {
    BSP_TRACE(4,0x14,DAT_30061f9c,param_2,param_3,DAT_30061f98,0,0,0);
    sVar2 = DAT_30061b18;
  }
  else {
    jos_safe_enter_d(DAT_30061b24,DAT_30061fa0);
    if (*(int *)(param_1 + 0x24) == 0) {
      jos_safe_leave_d(DAT_30061b24,DAT_30061fa4);
      sVar2 = DAT_30061c08;
    }
    else {
      if (*(int *)(param_1 + 0x78) == 0) {
        iVar1 = FUN_3005fb3c(param_1);
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x74) = 1;
          jos_safe_leave_d(DAT_30061b24,DAT_300620a8);
          semTake(*(undefined4 *)(param_1 + 0x90),0xffffffff);
          jos_safe_enter_d(DAT_30061b24,DAT_300620ac);
          iVar1 = FUN_3005fb3c(param_1);
          if (iVar1 == 0) {
            jos_safe_leave_d(DAT_30061b24,DAT_300620b0);
            return 0xffffffff;
          }
        }
        if (*(int *)(iVar1 + 0x18) < 1) {
          sVar2 = *(size_t *)(iVar1 + 0x18);
          FUN_3005f64c(param_1,iVar1);
          jos_safe_leave_d(DAT_30061b24,DAT_300620b4);
          return sVar2;
        }
      }
      else {
        iVar1 = *(int *)(param_1 + 0x78);
      }
      iVar4 = *(int *)(iVar1 + 0xc);
      iVar3 = *(int *)(iVar1 + 0x1c);
      if (param_3 < *(uint *)(iVar1 + 0x20)) {
        *(uint *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) - param_3;
        *(uint *)(iVar1 + 0x1c) = param_3 + *(int *)(iVar1 + 0x1c);
        *(int *)(param_1 + 0x78) = iVar1;
      }
      else {
        param_3 = *(size_t *)(iVar1 + 0x20);
        *(undefined4 *)(param_1 + 0x78) = 0;
      }
      jos_safe_leave_d(DAT_30061b24,DAT_300620b8);
      sVar2 = 0;
      if (param_3 != 0) {
        memcpy(param_2,(void *)(iVar4 + iVar3),param_3);
        sVar2 = param_3;
      }
      jos_safe_enter_d(DAT_30061b24,DAT_300620bc);
      if (*(int *)(param_1 + 0x78) == 0) {
        FUN_3005f64c(param_1,iVar1);
      }
      if ((*(int *)(param_1 + 0x70) != 0) && (*(int *)(param_1 + 0x6c) == 0)) {
        jtask_schedule_d(*(undefined4 *)(param_1 + 0xcec),0x1e,DAT_300621e4,param_1,DAT_30061b24,
                         DAT_300621e0);
      }
      jos_safe_leave_d(DAT_30061b24,DAT_300621e8);
    }
  }
  return sVar2;
}

/* ----------------------------------------------------------------
 * FUN_300612f4 @ 0x300612F4  (примерный размер ~208 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 4
 * Вызывает: BSP_TRACE, FUN_3005fb3c, jos_safe_enter_d, jos_safe_leave_d
 * Вызывают: FUN_30061974
 * Константы: 0x300612F4, 0xFFFFFFFF
 * Данные: DAT_30061b24, DAT_30061d54, DAT_30061f90, DAT_300621ec, DAT_300621f0, DAT_300621f4
 * ---------------------------------------------------------------- */
undefined4 FUN_300612f4(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) == 0)) {
    BSP_TRACE(4,0x14,DAT_30061f90,DAT_300621ec,0,0,0,0,0);
    uVar2 = DAT_30061d54;
  }
  else {
    jos_safe_enter_d(DAT_30061b24,DAT_300621f0);
    iVar1 = FUN_3005fb3c(param_1);
    if (iVar1 == 0) {
      jos_safe_leave_d(DAT_30061b24,DAT_300621f4);
      uVar2 = 0xffffffff;
    }
    else {
      *(int *)(param_1 + 0x60) = iVar1;
      jos_safe_leave_d(DAT_30061b24,0x910);
      *param_2 = *(undefined4 *)(iVar1 + 0xc);
      param_2[1] = *(undefined4 *)(iVar1 + 0x18);
      param_2[2] = iVar1;
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300613c4 @ 0x300613C4  (примерный размер ~332 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 6
 * Вызывает: BSP_TRACE, FUN_3005f64c, FUN_3006038c, jos_safe_enter_d, jos_safe_leave_d, jtask_schedule_d
 * Вызывают: FUN_30061974
 * Константы: 0x300613C4
 * Данные: DAT_30061b18, DAT_30061b24, DAT_30061d54, DAT_30061f90, DAT_300621e4, DAT_30062324, DAT_30062328, DAT_3006232c
 * ---------------------------------------------------------------- */
undefined4 FUN_300613c4(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) == 0)) {
    BSP_TRACE(4,0x14,DAT_30061f90,DAT_30062324,0,0,0,0,0);
    uVar2 = DAT_30061d54;
  }
  else {
    jos_safe_enter_d(DAT_30061b24,0x930);
    iVar1 = FUN_3006038c(param_1,*param_2);
    if (iVar1 == 0) {
      jos_safe_leave_d(DAT_30061b24,DAT_30062328);
      BSP_TRACE(4,0x14,DAT_30062330,*param_2,DAT_3006232c,0,0,0,0);
      uVar2 = DAT_30061b18;
    }
    else {
      if (*(int *)(iVar1 + 8) == 0) {
        FUN_3005f64c(param_1,iVar1);
      }
      if ((*(int *)(param_1 + 0x70) != 0) && (*(int *)(param_1 + 0x6c) == 0)) {
        jtask_schedule_d(*(undefined4 *)(param_1 + 0xcec),0x1e,DAT_300621e4,param_1,DAT_30061b24,
                         DAT_30062334);
      }
      jos_safe_leave_d(DAT_30061b24,DAT_30062338);
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * uwd_acm_app_init @ 0x30062660  (примерный размер ~612 байт)
 * Модуль: usb | Вызывают: 0 | Вызывает: 6
 * Вызывает: BSP_TRACE, FUN_3005f588, FUN_3005f5d8, FUN_3005f9a4, FUN_30060598, FUN_300624c4
 * Константы: 0x30062660
 * Данные: DAT_30062994, DAT_30062ad4, DAT_30062b04, DAT_30062b08, DAT_30062b0c, DAT_30062b10, DAT_30062b14, DAT_30062b18
 * ---------------------------------------------------------------- */
int uwd_acm_app_init(undefined4 param_1,undefined4 *param_2,ushort *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_30062b08;
  iVar1 = FUN_3005f588();
  if (iVar1 < 0) {
    iVar2 = 9;
  }
  else {
    iVar3 = DAT_30062994 + DAT_30062b04 * iVar1;
    *(uint *)(iVar3 + 0x2c) = (uint)*(byte *)(DAT_30062b0c + *DAT_30062ad4);
    *param_4 = iVar3;
    *(undefined4 *)(iVar3 + 0xcf0) = param_1;
    param_3[10] = 2;
    param_3[2] = 100;
    param_3[3] = 0;
    param_3[6] = 1;
    param_3[7] = 0;
    param_3[8] = 0x200;
    *param_3 = *param_3 | 9;
    if (*(int *)(iVar3 + 0x2c) != 6) {
      *param_3 = *param_3 | 0x10;
    }
    if (*(int *)(iVar2 + 0x1c) == DAT_30062b10) {
      *param_3 = *param_3 | 2;
    }
    *param_2 = DAT_30062b14;
    param_2[1] = DAT_30062b18;
    param_2[2] = DAT_30062b1c;
    param_2[8] = DAT_30062b20;
    param_2[9] = DAT_30062b24;
    param_2[0xf] = DAT_30062b28;
    param_2[0xd] = DAT_30062b2c;
    param_2[0xe] = DAT_30062b30;
    param_2[4] = DAT_30062b34;
    param_2[3] = DAT_30062b38;
    param_2[5] = DAT_30062b3c;
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[10] = 0;
    param_2[0xb] = 0;
    param_2[0xc] = 0;
    param_2[0x10] = 0;
    param_2[0x11] = 0;
    param_2[0x12] = 0;
    param_2[0x13] = 0;
    param_2[0x14] = 0;
    iVar2 = FUN_30060598(iVar3);
    if (iVar2 == 0) {
      *(int *)(iVar3 + 0x44) = iVar1 + 1;
      iVar2 = FUN_300624c4(iVar3);
      if (iVar2 == 0) {
        BSP_TRACE(0,0x14,DAT_30062b40,*(undefined4 *)(iVar3 + 0x44),0,0,0,0,0);
        return 0;
      }
    }
    FUN_3005f5d8(*(undefined4 *)(iVar3 + 0x44));
    FUN_3005f9a4(iVar3);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300628c4 @ 0x300628C4  (примерный размер ~4 байт)
 * Модуль: usb | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_3005f7d4, FUN_3005f860, FUN_3005fcf8, FUN_3005ff20, FUN_30060b5c
 * Константы: 0x300628C4
 * ---------------------------------------------------------------- */
void FUN_300628c4(void)

{
  return;
}

/* ----------------------------------------------------------------
 * FUN_300628c8 @ 0x300628C8  (примерный размер ~32 байт)
 * Модуль: usb | Вызывают: 3 | Вызывает: 0
 * Вызывают: BSP_AcmDumpList, FUN_3005f68c, FUN_3005fb3c
 * Константы: 0x300628C8
 * ---------------------------------------------------------------- */
bool FUN_300628c8(int *param_1)

{
  return (int *)*param_1 == param_1;
}

/* ----------------------------------------------------------------
 * FUN_300628e8 @ 0x300628E8  (примерный размер ~32 байт)
 * Модуль: usb | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_30062908
 * Вызывают: FUN_3005f68c, FUN_3005fb3c
 * Константы: 0x300628E8
 * ---------------------------------------------------------------- */
void FUN_300628e8(undefined4 *param_1)

{
  FUN_30062908(param_1[1],*param_1);
  *param_1 = param_1;
  param_1[1] = param_1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30062908 @ 0x30062908  (примерный размер ~28 байт)
 * Модуль: usb | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300628e8
 * Константы: 0x30062908
 * ---------------------------------------------------------------- */
void FUN_30062908(int *param_1,int param_2)

{
  *(int **)(param_2 + 4) = param_1;
  *param_1 = param_2;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30062924 @ 0x30062924  (примерный размер ~544 байт)
 * Модуль: usb | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_3005f64c, FUN_3005fb08, FUN_3006044c
 * Константы: 0x30062924
 * ---------------------------------------------------------------- */
void FUN_30062924(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_2 + 4);
  *(int **)(param_2 + 4) = param_1;
  *param_1 = param_2;
  param_1[1] = (int)piVar1;
  *piVar1 = (int)param_1;
  return;
}

