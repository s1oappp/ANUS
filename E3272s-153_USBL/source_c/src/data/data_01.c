/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 1 (функций: 150, адреса 0x30004174..0x30036000)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * spinLockAmpGive @ 0x30004174  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300067b0, FUN_30006964
 * Константы: 0x30004174
 * ---------------------------------------------------------------- */
void spinLockAmpGive(undefined4 *param_1)

{
  DataSynchronizationBarrier(0xf);
  *param_1 = 0;
  DataSynchronizationBarrier(0xf);
  return;
}

/* ----------------------------------------------------------------
 * spinLockAmpTake @ 0x30004188  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300067b0, FUN_30006964
 * Константы: 0x30004188
 * ---------------------------------------------------------------- */
void spinLockAmpTake(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  DataSynchronizationBarrier(0xf);
  do {
    do {
      iVar2 = *param_1;
      bVar1 = (bool)hasExclusiveAccess(param_1);
    } while (!bVar1);
    *param_1 = 1;
  } while (iVar2 != 0);
  return;
}

/* ----------------------------------------------------------------
 * spinLockAmpTakeOneTime @ 0x300041AC  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300041AC
 * ---------------------------------------------------------------- */
uint spinLockAmpTakeOneTime(uint *param_1)

{
  bool bVar1;
  uint uVar2;
  
  DataSynchronizationBarrier(0xf);
  uVar2 = *param_1;
  bVar1 = (bool)hasExclusiveAccess(param_1);
  if (bVar1) {
    *param_1 = 1;
  }
  return uVar2 | !bVar1;
}

/* ----------------------------------------------------------------
 * sysNvRamGet @ 0x300042F4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrBootLineInit
 * Константы: 0x300042F4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 sysNvRamGet(void)

{
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * sysNvRamSet @ 0x300042FC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: bootChange
 * Константы: 0x300042FC, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 sysNvRamSet(void)

{
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * sysHwInit0 @ 0x30004314  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: cacheCortexA9LibInstall, mmuCortexA8LibInstall
 * Вызывают: sysStart
 * Константы: 0x30004314
 * Данные: DAT_30004608, DAT_3000460c
 * ---------------------------------------------------------------- */
void sysHwInit0(void)

{
  cacheCortexA9LibInstall(DAT_30004608,DAT_3000460c);
  mmuCortexA8LibInstall(DAT_30004608,DAT_3000460c);
  return;
}

/* ----------------------------------------------------------------
 * sysHwInit2 @ 0x30004360  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: armGicCtlInit, intConnect, intLibInit, sysSerialHwInit2
 * Вызывают: sysClkConnect
 * Константы: 0x30004360
 * Данные: DAT_30004618, DAT_3000461c, DAT_30004620
 * ---------------------------------------------------------------- */
void sysHwInit2(void)

{
  if (*DAT_30004618 == 0) {
    intLibInit(0xa0,0xa0,1);
    armGicCtlInit();
    intConnect(0x5a,DAT_3000461c,0);
    intConnect(0x86,DAT_30004620,0);
    sysSerialHwInit2();
    *DAT_30004618 = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * sysPhysMemTop @ 0x300043BC  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: sysMemTop
 * Константы: 0x300043BC
 * Данные: DAT_30004624, DAT_30004628
 * ---------------------------------------------------------------- */
int sysPhysMemTop(void)

{
  if (*DAT_30004624 == 0) {
    *DAT_30004624 = DAT_30004628;
  }
  return *DAT_30004624;
}

/* ----------------------------------------------------------------
 * sysMemTop @ 0x300043E4  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: sysPhysMemTop
 * Вызывают: usrBanner, usrKernelInit
 * Константы: 0x300043E4
 * Данные: DAT_3000462c, DAT_30004630
 * ---------------------------------------------------------------- */
int sysMemTop(void)

{
  int iVar1;
  
  if (*DAT_3000462c == 0) {
    iVar1 = sysPhysMemTop();
    *DAT_3000462c = iVar1 - DAT_30004630;
  }
  return *DAT_3000462c;
}

/* ----------------------------------------------------------------
 * sysToMonitor @ 0x30004418  (примерный размер ~212 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: BSP_WDT_reboot_direct, cacheFlush, cachePipeFlush, intIFLock, mmuCortexA8ADisable, sysClkDisable
 * Вызывают: kernelInit, reboot
 * Константы: 0xFFFFFFFF, 0x30004418
 * Данные: DAT_30004634, DAT_30004638, DAT_3000463c, DAT_30004640, DAT_30004644, DAT_30004648
 * ---------------------------------------------------------------- */
undefined4 sysToMonitor(void)

{
  int iVar1;
  undefined4 local_c;
  
  sysClkDisable();
  intIFLock();
  local_c = *DAT_30004634 & DAT_30004638;
  while ((local_c != DAT_30004638 && (0xf < local_c))) {
    *DAT_3000463c = local_c;
    local_c = *DAT_30004634 & DAT_30004638;
  }
  for (iVar1 = 0x20; iVar1 < 0xa0; iVar1 = iVar1 + 0x20) {
    iVar1 = iVar1 + ((uint)(iVar1 >> 0x1f) >> 0x1b);
    *(undefined4 *)(DAT_30004640 + (iVar1 >> 5) * 4) = 0xffffffff;
  }
  *DAT_30004644 = 0;
  *DAT_30004648 = 0;
  cacheFlush(1,0,0xffffffff);
  cachePipeFlush();
  mmuCortexA8ADisable();
  BSP_WDT_reboot_direct();
  return 0;
}

/* ----------------------------------------------------------------
 * sysProcNumGet @ 0x300044EC  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrBanner
 * Константы: 0x300044EC
 * Данные: DAT_3000464c
 * ---------------------------------------------------------------- */
undefined4 sysProcNumGet(void)

{
  return *DAT_3000464c;
}

/* ----------------------------------------------------------------
 * sysProcNumSet @ 0x300044F8  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrBootLineParse
 * Константы: 0x300044F8
 * Данные: DAT_3000464c
 * ---------------------------------------------------------------- */
void sysProcNumSet(undefined4 param_1)

{
  *DAT_3000464c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * bspSerialChanGet @ 0x30004510  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30004510, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 bspSerialChanGet(void)

{
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * sysCpuAvailableGet @ 0x30004518  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30004518
 * Данные: DAT_30004650
 * ---------------------------------------------------------------- */
int sysCpuAvailableGet(void)

{
  return (*DAT_30004650 & 3) + 1;
}

/* ----------------------------------------------------------------
 * sysMsDelay @ 0x3000452C  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: __div32, sysClkRateGet
 * Вызывают: sysDelay
 * Константы: 0x3000452C
 * Данные: DAT_30004654, DAT_30004658
 * ---------------------------------------------------------------- */
void sysMsDelay(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_1c;
  undefined4 local_14;
  
  local_14 = 0;
  if (param_1 != 0) {
    uVar1 = sysClkRateGet();
    iVar2 = __div32(DAT_30004654,uVar1);
    local_1c = *DAT_30004658;
    while (local_14 < (uint)(param_1 * 1000)) {
      uVar3 = *DAT_30004658;
      if (uVar3 != local_1c) {
        if (uVar3 < local_1c) {
          local_14 = local_14 + (local_1c - uVar3);
          local_1c = uVar3;
        }
        else {
          local_14 = local_14 + local_1c + (iVar2 - uVar3);
          local_1c = uVar3;
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * sysDelay @ 0x300045F8  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: sysMsDelay
 * Константы: 0x300045F8
 * ---------------------------------------------------------------- */
void sysDelay(void)

{
  sysMsDelay(1);
  return;
}

/* ----------------------------------------------------------------
 * activeAppCore @ 0x300048D8  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300048D8
 * ---------------------------------------------------------------- */
void activeAppCore(void)

{
  return;
}

/* ----------------------------------------------------------------
 * BBP_UnReset @ 0x30004960  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30004960, 0xFFFFFFFE, 0xFFFFFFEF, 0xFFFFFF7F, 0xFFFFFFF7, 0xFFFFFFBF, 0xFFFF1FFF, 0xFFFFFFFF
 * Данные: DAT_300050c0, DAT_300050c4, DAT_300050c8, DAT_300050cc
 * ---------------------------------------------------------------- */
void BBP_UnReset(void)

{
  *DAT_300050c0 = *DAT_300050c0 & 0xfffffffe;
  *DAT_300050c0 = *DAT_300050c0 & 0xffffffef;
  *DAT_300050c0 = *DAT_300050c0 & 0xffffff7f;
  *DAT_300050c0 = *DAT_300050c0 & 0xfffffff7;
  *DAT_300050c0 = *DAT_300050c0 & 0xffffffbf;
  *DAT_300050c0 = *DAT_300050c0 & 0xffff1fff;
  *DAT_300050c4 = 7;
  *DAT_300050c8 = 0;
  *DAT_300050cc = 0xffffffff;
  return;
}

/* ----------------------------------------------------------------
 * waitACoreNandRelease @ 0x30004B2C  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30004B2C
 * ---------------------------------------------------------------- */
void waitACoreNandRelease(void)

{
  return;
}

/* ----------------------------------------------------------------
 * drvMultiCoreInit @ 0x30004B30  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30004B30
 * ---------------------------------------------------------------- */
void drvMultiCoreInit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * dummyForMSP @ 0x30005084  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30005084
 * ---------------------------------------------------------------- */
undefined4 dummyForMSP(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * BSPLogHelp @ 0x300054B8  (примерный размер ~216 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x300054B8
 * Данные: DAT_300055c8, DAT_300055cc, DAT_300055d0, DAT_300055d4, DAT_300055d8, DAT_300055dc, DAT_300055e0, DAT_300055e4
 * ---------------------------------------------------------------- */
void BSPLogHelp(void)

{
  int iVar1;
  
  printf(DAT_300055c8);
  printf(DAT_300055cc);
  printf(DAT_300055d0);
  printf(DAT_300055d4);
  printf(DAT_300055d8);
  printf(DAT_300055dc);
  printf(DAT_300055e0);
  printf(DAT_300055e4);
  printf(DAT_300055e8);
  printf(DAT_300055ec);
  printf(DAT_300055f0);
  for (iVar1 = 0; iVar1 < 0x35; iVar1 = iVar1 + 1) {
    printf(DAT_300055fc,iVar1 * 100 + DAT_300055f8,iVar1,iVar1 * 100 + DAT_300055f4);
  }
  printf(DAT_30005600);
  for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
    printf(DAT_3000560c,iVar1 * 100 + DAT_30005608,iVar1,iVar1 * 100 + DAT_30005604);
  }
  return;
}

/* ----------------------------------------------------------------
 * IOS_Config @ 0x30005590  (примерный размер ~1472 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30005590, 0x300055A8
 * Данные: DAT_30005610
 * ---------------------------------------------------------------- */
void IOS_Config(uint param_1)

{
  if (param_1 < 0x18) {
                    /* WARNING: Could not recover jumptable at 0x300055a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_30005610 + param_1 * 4))();
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30005b50 @ 0x30005B50  (примерный размер ~320 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_TRACE, memalign
 * Вызывают: BSP_MEM_Init
 * Константы: 0xFFFFFFFF, 0x30005B50
 * Данные: DAT_30006b24, DAT_30006b28, DAT_30006b2c, DAT_30006b30, DAT_30006b34, DAT_30006b38, DAT_30006b3c, DAT_30006b40
 * ---------------------------------------------------------------- */
undefined4 FUN_30005b50(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_30006b28;
  if (param_1 == 0) {
    uVar1 = memalign(0x20,0x80000);
    *(undefined4 *)(iVar2 + 0xd8) = uVar1;
    *(undefined4 *)(iVar2 + 0xe0) = *(undefined4 *)(iVar2 + 0xd8);
    *(undefined4 *)(iVar2 + 0xdc) = 0x80000;
    *(undefined4 *)(iVar2 + 0xe4) = 0x80000;
    *(undefined4 *)(iVar2 + 0xe8) = 0x20;
  }
  else {
    iVar3 = *DAT_30006b24 + param_1 * 0xf4;
    iVar2 = iVar3 + -0xf4;
    if (param_1 == 1) {
      *(undefined4 *)(iVar3 + -0x1c) = DAT_30006b2c;
      *(undefined4 *)(iVar3 + -0x14) = DAT_30006b2c;
      *(undefined4 *)(iVar3 + -0x18) = DAT_30006b30;
      *(undefined4 *)(iVar3 + -0x10) = DAT_30006b30;
      *(undefined4 *)(iVar3 + -0xc) = 0x20;
    }
    else {
      if (param_1 != 2) {
        BSP_TRACE(4,0x1c,DAT_30006b40,param_1,DAT_30006b3c);
        return 0xffffffff;
      }
      *(undefined4 *)(iVar3 + -0x1c) = DAT_30006b34;
      *(undefined4 *)(iVar3 + -0x14) = DAT_30006b34;
      *(undefined4 *)(iVar3 + -0x18) = DAT_30006b38;
      *(undefined4 *)(iVar3 + -0x10) = DAT_30006b38;
      *(undefined4 *)(iVar3 + -0xc) = 0x20;
    }
  }
  if (*(int *)(iVar2 + 0xd8) == 0) {
    BSP_TRACE(4,0x1c,DAT_30006b44,0x13c);
    uVar1 = 0xffffffff;
  }
  else {
    *(undefined4 *)(iVar2 + 0xec) = 0;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * lock_swwdt @ 0x300079CC  (примерный размер ~272 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: printf, tickGet
 * Константы: 0x300079CC
 * Данные: DAT_30007ad8
 * ---------------------------------------------------------------- */
void lock_swwdt(int param_1)

{
  tickGet();
  if (param_1 != 0) {
    printf(DAT_30007ad8);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}

/* ----------------------------------------------------------------
 * subVICIntHook @ 0x30007ADC  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: exchHookFuncAdd, exchInit
 * Константы: 0x30007ADC
 * Данные: DAT_30007c2c
 * ---------------------------------------------------------------- */
void subVICIntHook(undefined4 param_1)

{
  *DAT_30007c2c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * subVICIntHookDel @ 0x30007AF4  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: exchHookFuncDelete
 * Константы: 0x30007AF4
 * Данные: DAT_30007c2c
 * ---------------------------------------------------------------- */
void subVICIntHookDel(void)

{
  *DAT_30007c2c = 0;
  return;
}

/* ----------------------------------------------------------------
 * armGicCtlInit @ 0x30007EF4  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30007c30
 * Вызывают: sysHwInit2
 * Константы: 0x30007EF4, 0x08000000
 * Данные: DAT_30008508, DAT_3000851c, DAT_30008534, DAT_30008538, DAT_3000853c, DAT_30008540, DAT_30008544, DAT_30008548
 * ---------------------------------------------------------------- */
undefined4 armGicCtlInit(void)

{
  *DAT_3000851c = 0xa0;
  *DAT_30008508 = 0x8000000;
  *DAT_3000853c = DAT_30008538;
  *DAT_30008544 = DAT_30008540;
  *DAT_3000854c = DAT_30008548;
  *DAT_30008554 = DAT_30008550;
  *DAT_3000855c = DAT_30008558;
  if (*DAT_30008560 == 0) {
    *DAT_30008560 = DAT_30008564;
  }
  if (*DAT_30008568 == 0) {
    *DAT_30008568 = DAT_3000856c;
  }
  FUN_30007c30(*DAT_30008534 & 0xf);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30007f84 @ 0x30007F84  (примерный размер ~216 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30007F84, 0xFFFFFFFF
 * Данные: DAT_30008508, DAT_3000851c, DAT_30008570, DAT_30008574, DAT_30008578, DAT_3000857c
 * ---------------------------------------------------------------- */
undefined4 FUN_30007f84(uint *param_1,uint *param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  *DAT_30008570 = 1;
  if (*DAT_30008574 != 0) {
    (*(code *)*DAT_30008574)();
  }
  uVar2 = *(uint *)(*DAT_30008508 + 0x10c) & DAT_30008578;
  if (uVar2 == DAT_30008578) {
    uVar1 = 0xffffffff;
  }
  else {
    if (uVar2 < 0x10) {
      *param_3 = *(uint *)(*DAT_30008508 + 0x10c) & 0x1c00;
      *param_1 = uVar2 + *DAT_3000851c;
      *param_2 = uVar2 + *DAT_3000851c;
    }
    else {
      *param_1 = uVar2;
      *param_2 = uVar2;
    }
    if (*DAT_3000857c != 0) {
      (*(code *)*DAT_3000857c)(*param_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3000805c @ 0x3000805C  (примерный размер ~760 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000805C, 0xFFFFFFFF
 * Данные: DAT_30008508, DAT_3000851c, DAT_30008570, DAT_3000857c, DAT_30008580
 * ---------------------------------------------------------------- */
undefined4 FUN_3000805c(uint param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  *DAT_30008570 = 0;
  if ((((int)param_1 < 0) || (*DAT_3000851c <= (int)param_1)) || (param_1 - 0x10 < 0x10)) {
    uVar1 = 0xffffffff;
  }
  else {
    if (*DAT_3000851c <= (int)param_1) {
      param_1 = param_1 - *DAT_3000851c | param_3;
    }
    *(uint *)(*DAT_30008508 + 0x110) = param_1;
    if (*DAT_30008580 != 0) {
      (*(code *)*DAT_30008580)();
    }
    if (*DAT_3000857c != 0) {
      (*(code *)*DAT_3000857c)(param_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * armGicHwEnable @ 0x30008354  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: intCpuLock, intCpuUnlock
 * Константы: 0x30008354, 0xFFFFFFFF
 * Данные: DAT_30008508, DAT_3000851c
 * ---------------------------------------------------------------- */
undefined4 armGicHwEnable(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (((int)param_1 < 0) || (0xf < (int)param_1)) {
    if (((int)param_1 < 0x20) || (*DAT_3000851c <= (int)param_1)) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = intCpuLock();
      uVar2 = param_1 & 0x1f;
      if ((int)param_1 < 0) {
        uVar2 = -(-param_1 & 0x1f);
      }
      *(int *)(*DAT_30008508 + ((int)(param_1 + ((uint)((int)param_1 >> 0x1f) >> 0x1b)) >> 5) * 4 +
              0x1100) = 1 << (uVar2 & 0xff);
      intCpuUnlock(uVar1);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * armGicHwDisable @ 0x30008368  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: intCpuLock, intCpuUnlock
 * Константы: 0x30008368, 0xFFFFFFFF
 * Данные: DAT_30008508, DAT_3000851c
 * ---------------------------------------------------------------- */
undefined4 armGicHwDisable(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (((int)param_1 < 0) || (0xf < (int)param_1)) {
    if (((int)param_1 < 0x20) || (*DAT_3000851c <= (int)param_1)) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = intCpuLock();
      uVar2 = param_1 & 0x1f;
      if ((int)param_1 < 0) {
        uVar2 = -(-param_1 & 0x1f);
      }
      *(int *)(*DAT_30008508 + ((int)(param_1 + ((uint)((int)param_1 >> 0x1f) >> 0x1b)) >> 5) * 4 +
              0x1180) = 1 << (uVar2 & 0xff);
      intCpuUnlock(uVar1);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * armGicHwLvlChg @ 0x3000837C  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: intCpuLock, intCpuUnlock
 * Константы: 0xFFFFFFFF, 0x3000837C
 * Данные: DAT_30008508, DAT_3000851c
 * ---------------------------------------------------------------- */
undefined4 armGicHwLvlChg(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 - 0x10U < 0x10) || (*DAT_3000851c <= param_1)) {
    uVar1 = 0xffffffff;
  }
  else if (param_2 < 0xf) {
    uVar1 = intCpuLock();
    uVar4 = param_1 + ((uint)(param_1 >> 0x1f) >> 0x1e);
    uVar2 = uVar4 & 3;
    if ((int)uVar4 < 0) {
      uVar2 = -(-uVar4 & 3);
    }
    uVar3 = uVar4 & 3;
    if ((int)uVar4 < 0) {
      uVar3 = -(-uVar4 & 3);
    }
    *(uint *)(*DAT_30008508 + ((int)(uVar4 + ((uint)((int)uVar4 >> 0x1f) >> 0x1e)) >> 2) * 4 +
             0x1400) =
         *(uint *)(*DAT_30008508 + ((int)uVar4 >> 2) * 4 + 0x1400) &
         ~(0xff << ((uVar2 & 0x1f) << 3)) | (param_2 << 3) << ((uVar3 & 0x1f) << 3);
    intCpuUnlock(uVar1);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * armGicConnect @ 0x30008398  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: intArchConnect
 * Константы: 0x30008398
 * ---------------------------------------------------------------- */
void armGicConnect(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  intArchConnect(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * armGicDisconnect @ 0x300083BC  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: intArchDisconnect
 * Константы: 0x300083BC
 * ---------------------------------------------------------------- */
void armGicDisconnect(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  intArchDisconnect(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * armGicIntReroute @ 0x300083E0  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: intCpuLock, intCpuUnlock
 * Константы: 0xFFFFFFFF, 0xFFFFFFFC, 0x300083E0
 * Данные: DAT_30008508, DAT_3000851c
 * ---------------------------------------------------------------- */
undefined4 armGicIntReroute(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_1 < 0x20) || (*DAT_3000851c < param_1)) {
    uVar1 = 0xffffffff;
  }
  else if (param_2 < 2) {
    uVar1 = intCpuLock();
    *(uint *)(*DAT_30008508 + (param_1 & 0xfffffffc) + 0x1800) =
         *(uint *)(*DAT_30008508 + (param_1 & 0xfffffffc) + 0x1800) &
         ~(0xff << ((param_1 & 3) << 3)) | param_2 << ((param_1 & 3) << 3);
    intCpuUnlock(uVar1);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * vicIntBreakInHook @ 0x30008490  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30008490
 * Данные: DAT_30008574
 * ---------------------------------------------------------------- */
void vicIntBreakInHook(undefined4 param_1)

{
  *DAT_30008574 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * vicIntBreakOutHook @ 0x300084A8  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300084A8
 * Данные: DAT_30008580
 * ---------------------------------------------------------------- */
void vicIntBreakOutHook(undefined4 param_1)

{
  *DAT_30008580 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * vicIntBreakInHookDel @ 0x300084C0  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300084C0
 * Данные: DAT_30008574
 * ---------------------------------------------------------------- */
void vicIntBreakInHookDel(void)

{
  *DAT_30008574 = 0;
  return;
}

/* ----------------------------------------------------------------
 * vicIntBreakOutHookDel @ 0x300084D0  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300084D0
 * Данные: DAT_30008580
 * ---------------------------------------------------------------- */
void vicIntBreakOutHookDel(void)

{
  *DAT_30008580 = 0;
  return;
}

/* ----------------------------------------------------------------
 * vicIntLvlChgHookAdd @ 0x300084E0  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: exchHookFuncAdd, exchInit
 * Константы: 0x300084E0
 * Данные: DAT_3000857c
 * ---------------------------------------------------------------- */
void vicIntLvlChgHookAdd(undefined4 param_1)

{
  *DAT_3000857c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * vicIntLvlChgHookDel @ 0x300084F8  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: exchHookFuncDelete
 * Константы: 0x300084F8
 * Данные: DAT_3000857c
 * ---------------------------------------------------------------- */
void vicIntLvlChgHookDel(void)

{
  *DAT_3000857c = 0;
  return;
}

/* ----------------------------------------------------------------
 * sysClkInt @ 0x300085E0  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_traceProcessInit, TIMER_BASE
 * Константы: 0x300085E0
 * Данные: DAT_300094b8, DAT_300094bc, DAT_300094c0, DAT_300094c4
 * ---------------------------------------------------------------- */
void sysClkInt(void)

{
  int iVar1;
  
  if (*DAT_300094b8 == 0) {
    BSP_traceProcessInit();
  }
  iVar1 = TIMER_BASE(5);
  if (*(int *)(iVar1 + 0x10) != 0) {
    *DAT_300094bc = *DAT_300094bc + 1;
    TIMER_BASE(5);
    if (*DAT_300094c0 != 0) {
      (*(code *)*DAT_300094c0)(*DAT_300094c4);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * sysClkConnect @ 0x30008660  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: sysHwInit2
 * Вызывают: sysClkInit
 * Константы: 0x30008660
 * Данные: DAT_300094c0, DAT_300094c4, DAT_3000957c
 * ---------------------------------------------------------------- */
undefined4 sysClkConnect(int param_1,undefined4 param_2)

{
  if (*DAT_3000957c == 0) {
    sysHwInit2();
    *DAT_3000957c = 1;
  }
  *DAT_300094c0 = 0;
  *DAT_300094c4 = param_2;
  if (param_1 != 0) {
    *DAT_300094c0 = param_1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * sysClkDisable @ 0x300086C0  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Вызывают: sysClkRateSet, sysToMonitor
 * Константы: 0x300086C0
 * Данные: DAT_300094bc, DAT_30009580
 * ---------------------------------------------------------------- */
void sysClkDisable(void)

{
  int iVar1;
  
  if (*DAT_30009580 != 0) {
    iVar1 = TIMER_BASE(5);
    *(undefined4 *)(iVar1 + 8) = 6;
    *DAT_300094bc = 0;
    *DAT_30009580 = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * sysClkEnable @ 0x30008700  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: BSP_TRACE, TIMER_BASE, __div32, intEnable
 * Вызывают: sysClkInit, sysClkRateSet
 * Константы: 0x30008700
 * Данные: DAT_300094bc, DAT_30009580, DAT_30009584, DAT_30009588, DAT_30009698, DAT_3000969c
 * ---------------------------------------------------------------- */
void sysClkEnable(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (*DAT_30009580 == 0) {
    *DAT_300094bc = 0;
    iVar1 = TIMER_BASE(5);
    *(undefined4 *)(iVar1 + 8) = 6;
    uVar2 = __div32(DAT_30009584,*DAT_30009588);
    puVar3 = (undefined4 *)TIMER_BASE(5);
    *puVar3 = uVar2;
    do {
      iVar1 = TIMER_BASE(5);
      uVar4 = uVar4 + 1;
      if ((*(uint *)(iVar1 + 8) & 0x10) != 0) break;
    } while (uVar4 < 100);
    if (uVar4 == 100) {
      BSP_TRACE(4,1,DAT_30009698);
    }
    else {
      iVar1 = TIMER_BASE(5);
      *(undefined4 *)(iVar1 + 8) = 3;
      if (*DAT_3000969c == 0) {
        intEnable(0x5a);
        *DAT_3000969c = 1;
      }
      *DAT_30009580 = 1;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * sysClkRateGet @ 0x300087EC  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 21 | Вызывает: 0
 * Вызывают: BSP_LDScript, FUN_300eb28c, FUN_300f6770, FUN_30110c38, clockLibInit, clock_getres, clock_gettime, clock_gettime_wd, clock_nanosleep, clock_settime
 *           ...
 * Константы: 0x300087EC
 * Данные: DAT_30009588
 * ---------------------------------------------------------------- */
undefined4 sysClkRateGet(void)

{
  return *DAT_30009588;
}

/* ----------------------------------------------------------------
 * sysClkRateSet @ 0x300087F8  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: BSP_TRACE, sysClkDisable, sysClkEnable
 * Вызывают: sysClkInit
 * Константы: 0x300087F8, 0xFFFFFFFF
 * Данные: DAT_30009580, DAT_30009588, DAT_300096a0, DAT_300096a4
 * ---------------------------------------------------------------- */
undefined4 sysClkRateSet(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_300096a0 < param_1 - 10U) {
    BSP_TRACE(4,1,DAT_300096a4,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    *DAT_30009588 = param_1;
    if (*DAT_30009580 != 0) {
      sysClkDisable();
      sysClkEnable();
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sysClkTicksGet @ 0x30008884  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: exchReadNVToGetSysTime, getTimeTickAndCount
 * Константы: 0x30008884
 * Данные: DAT_300094bc
 * ---------------------------------------------------------------- */
undefined4 sysClkTicksGet(void)

{
  return *DAT_300094bc;
}

/* ----------------------------------------------------------------
 * USRCLK_GetCurTimerValue @ 0x30008890  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Вызывают: BSP_USRCLK_TimerMilliSecValue, BSP_USRCLK_TimerValue, getTimeTickAndCount
 * Константы: 0x30008890
 * ---------------------------------------------------------------- */
undefined4 USRCLK_GetCurTimerValue(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = TIMER_BASE(param_1);
  return *(undefined4 *)(iVar1 + 4);
}

/* ----------------------------------------------------------------
 * getTimeTickAndCount @ 0x300088AC  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 4
 * Вызывает: USRCLK_GetCurTimerValue, __div32, sysClkRateGet, sysClkTicksGet
 * Вызывают: CvAnnounce, CvInfoContinue, CvInfoStart, CvTaskSwitchHook
 * Константы: 0x300088AC
 * Данные: DAT_30009584
 * ---------------------------------------------------------------- */
void getTimeTickAndCount(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = sysClkTicksGet();
  *param_1 = uVar1;
  uVar1 = sysClkRateGet();
  iVar2 = __div32(DAT_30009584,uVar1);
  iVar3 = USRCLK_GetCurTimerValue(5);
  *param_2 = iVar2 - iVar3;
  return;
}

/* ----------------------------------------------------------------
 * sysAuxClkInt @ 0x300088EC  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Константы: 0x300088EC
 * Данные: DAT_30009824, DAT_30009828, DAT_3000982c
 * ---------------------------------------------------------------- */
void sysAuxClkInt(void)

{
  int iVar1;
  
  iVar1 = TIMER_BASE(0);
  if (*(int *)(iVar1 + 0x10) != 0) {
    *DAT_30009824 = *DAT_30009824 + 1;
    TIMER_BASE(0);
    if (*DAT_30009828 != 0) {
      (*(code *)*DAT_30009828)(*DAT_3000982c);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * sysAuxClkConnect @ 0x30008958  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: BSP_CLK_Connect, sysTimestampConnect
 * Константы: 0x30008958
 * Данные: DAT_30009828, DAT_3000982c
 * ---------------------------------------------------------------- */
undefined4 sysAuxClkConnect(int param_1,undefined4 param_2)

{
  *DAT_30009828 = 0;
  *DAT_3000982c = param_2;
  if (param_1 != 0) {
    *DAT_30009828 = param_1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * sysAuxClkDisable @ 0x3000899C  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Вызывают: BSP_CLK_Disable, sysAuxClkRateSet, sysTimestampDisable
 * Константы: 0x3000899C
 * Данные: DAT_30009824, DAT_30009830
 * ---------------------------------------------------------------- */
void sysAuxClkDisable(void)

{
  int iVar1;
  
  if (*DAT_30009830 != 0) {
    iVar1 = TIMER_BASE(0);
    *(undefined4 *)(iVar1 + 8) = 6;
    *DAT_30009824 = 0;
    *DAT_30009830 = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * sysAuxClkEnable @ 0x300089DC  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 4
 * Вызывает: BSP_TRACE, TIMER_BASE, __div32, intEnable
 * Вызывают: BSP_CLK_Enable, sysAuxClkRateSet, sysTimestampEnable
 * Константы: 0x300089DC
 * Данные: DAT_30009584, DAT_30009698, DAT_30009824, DAT_30009830, DAT_300098ec, DAT_300098f0
 * ---------------------------------------------------------------- */
void sysAuxClkEnable(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (*DAT_30009830 == 0) {
    *DAT_30009824 = 0;
    iVar1 = TIMER_BASE(0);
    *(undefined4 *)(iVar1 + 8) = 6;
    uVar2 = __div32(DAT_30009584,*DAT_300098ec);
    puVar3 = (undefined4 *)TIMER_BASE(0);
    *puVar3 = uVar2;
    do {
      iVar1 = TIMER_BASE(0);
      uVar4 = uVar4 + 1;
      if ((*(uint *)(iVar1 + 8) & 0x10) != 0) break;
    } while (uVar4 < 100);
    if (uVar4 == 100) {
      BSP_TRACE(4,1,DAT_30009698);
    }
    else {
      iVar1 = TIMER_BASE(0);
      *(undefined4 *)(iVar1 + 8) = 3;
      if (*DAT_300098f0 == 0) {
        intEnable(0x86);
        *DAT_300098f0 = 1;
      }
      *DAT_30009830 = 1;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * sysAuxClkRateGet @ 0x30008AC8  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30008AC8
 * Данные: DAT_300098ec
 * ---------------------------------------------------------------- */
undefined4 sysAuxClkRateGet(void)

{
  return *DAT_300098ec;
}

/* ----------------------------------------------------------------
 * sysAuxClkRateSet @ 0x30008AD4  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, sysAuxClkDisable, sysAuxClkEnable
 * Константы: 0x30008AD4, 0xFFFFFFFF
 * Данные: DAT_30009830, DAT_300098ec, DAT_300099f0, DAT_300099f4
 * ---------------------------------------------------------------- */
undefined4 sysAuxClkRateSet(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_300099f0 < param_1 - 1U) {
    BSP_TRACE(4,1,DAT_300099f4,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    *DAT_300098ec = param_1;
    if (*DAT_30009830 != 0) {
      sysAuxClkDisable();
      sysAuxClkEnable();
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sysAuxClkTicksGet @ 0x30008B60  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30008B60
 * Данные: DAT_30009824
 * ---------------------------------------------------------------- */
undefined4 sysAuxClkTicksGet(void)

{
  return *DAT_30009824;
}

/* ----------------------------------------------------------------
 * softTimeClkInt @ 0x30008B6C  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Константы: 0x30008B6C
 * Данные: DAT_300099f8, DAT_300099fc, DAT_30009a00
 * ---------------------------------------------------------------- */
void softTimeClkInt(void)

{
  int iVar1;
  
  iVar1 = TIMER_BASE(1);
  if (*(int *)(iVar1 + 0x10) != 0) {
    *DAT_300099f8 = *DAT_300099f8 + 1;
    TIMER_BASE(1);
    if (*DAT_300099fc != 0) {
      (*(code *)*DAT_300099fc)(*DAT_30009a00);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * softTimeConnect @ 0x30008BD8  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: intEnable
 * Константы: 0x30008BD8
 * Данные: DAT_300099fc, DAT_30009a00, DAT_30009ae4
 * ---------------------------------------------------------------- */
undefined4 softTimeConnect(int param_1,undefined4 param_2)

{
  *DAT_300099fc = 0;
  *DAT_30009a00 = param_2;
  if (param_1 != 0) {
    *DAT_300099fc = param_1;
    *DAT_300099fc = param_1;
    if (*DAT_30009ae4 == 0) {
      intEnable(0x4e);
      *DAT_30009ae4 = 1;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * sysTimestampConnect @ 0x30008C44  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: sysAuxClkConnect
 * Константы: 0x30008C44
 * ---------------------------------------------------------------- */
void sysTimestampConnect(undefined4 param_1,undefined4 param_2)

{
  sysAuxClkConnect(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * sysTimestampEnable @ 0x30008C60  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_TRACE, sysAuxClkEnable
 * Вызывают: sysTimestampRateSet
 * Константы: 0x30008C60, 0xFFFFFFFF
 * Данные: DAT_30009830, DAT_30009ae8, DAT_30009aec
 * ---------------------------------------------------------------- */
undefined4 sysTimestampEnable(void)

{
  if (*DAT_30009ae8 == 0) {
    if (*DAT_30009830 != 0) {
      BSP_TRACE(4,1,DAT_30009aec);
      return 0xffffffff;
    }
    sysAuxClkEnable();
    *DAT_30009ae8 = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * sysTimestampDisable @ 0x30008CB4  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: sysAuxClkDisable
 * Вызывают: sysTimestampRateSet
 * Константы: 0x30008CB4
 * Данные: DAT_30009ae8
 * ---------------------------------------------------------------- */
undefined4 sysTimestampDisable(void)

{
  if (*DAT_30009ae8 != 0) {
    sysAuxClkDisable();
    *DAT_30009ae8 = 0;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * sysTimestampRateGet @ 0x30008CE0  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30008CE0
 * Данные: DAT_30009af0
 * ---------------------------------------------------------------- */
undefined4 sysTimestampRateGet(void)

{
  return *DAT_30009af0;
}

/* ----------------------------------------------------------------
 * sysTimestampRateSet @ 0x30008CEC  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, sysTimestampDisable, sysTimestampEnable
 * Константы: 0x30008CEC, 0xFFFFFFFF
 * Данные: DAT_300096a0, DAT_30009ae8, DAT_30009af0, DAT_30009bd4
 * ---------------------------------------------------------------- */
undefined4 sysTimestampRateSet(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_300096a0 < param_1 - 10U) {
    BSP_TRACE(4,1,DAT_30009bd4,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    *DAT_30009af0 = param_1;
    if (*DAT_30009ae8 != 0) {
      sysTimestampDisable();
      sysTimestampEnable();
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sysTimestampPeriod @ 0x30008D78  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: __div32
 * Вызывают: sysTimestamp
 * Константы: 0x30008D78
 * Данные: DAT_30009584, DAT_30009af0
 * ---------------------------------------------------------------- */
void sysTimestampPeriod(void)

{
  __div32(DAT_30009584,*DAT_30009af0);
  return;
}

/* ----------------------------------------------------------------
 * sysTimestampFreq @ 0x30008D88  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30008D88
 * Данные: DAT_30009584
 * ---------------------------------------------------------------- */
undefined4 sysTimestampFreq(void)

{
  return DAT_30009584;
}

/* ----------------------------------------------------------------
 * sysTimestampLock @ 0x30008DAC  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: intCpuLock, intCpuUnlock, sysTimestamp
 * Константы: 0x30008DAC
 * ---------------------------------------------------------------- */
undefined4 sysTimestampLock(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = intCpuLock();
  uVar2 = sysTimestamp();
  intCpuUnlock(uVar1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * USRCLK_GetClkId @ 0x30009174  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: USRClkInt_Handle
 * Константы: 0x30009174
 * ---------------------------------------------------------------- */
void USRCLK_GetClkId(int param_1,undefined4 *param_2)

{
  if (param_1 == 6) {
    *param_2 = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * USRClkInt_Handle @ 0x30009198  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: TIMER_BASE, USRCLK_GetClkId
 * Константы: 0x30009198
 * Данные: DAT_30009e3c, DAT_30009ed4, DAT_30009ed8
 * ---------------------------------------------------------------- */
undefined4 USRClkInt_Handle(void)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  *DAT_30009ed4 = *DAT_30009ed4 + 1;
  iVar1 = TIMER_BASE(6);
  if (*(int *)(iVar1 + 0x10) != 0) {
    USRCLK_GetClkId(6,&local_c);
    TIMER_BASE(6);
    if (*(int *)(DAT_30009e3c + local_c * 0x14) != 0) {
      (**(code **)(DAT_30009e3c + local_c * 0x14))(*(undefined4 *)(DAT_30009ed8 + local_c * 0x14));
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * USRCLK_GetClkNum @ 0x300092D0  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 0
 * Вызывают: BSP_USRCLK_Disable, BSP_USRCLK_Enable, BSP_USRCLK_TimerMilliSecStart, BSP_USRCLK_TimerMilliSecValue, BSP_USRCLK_TimerStart, BSP_USRCLK_TimerStop, BSP_USRCLK_TimerValue
 * Константы: 0x300092D0
 * ---------------------------------------------------------------- */
void USRCLK_GetClkNum(int param_1,undefined4 *param_2)

{
  if (param_1 == 0) {
    *param_2 = 6;
  }
  return;
}

/* ----------------------------------------------------------------
 * drv_sleep_call_back @ 0x3000AF18  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: semGive
 * Константы: 0x3000AF18
 * ---------------------------------------------------------------- */
void drv_sleep_call_back(undefined4 *param_1)

{
  semGive(*param_1);
  return;
}

/* ----------------------------------------------------------------
 * drv_sleep @ 0x3000B07C  (примерный размер ~260 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: logMsg, semBCreate, semDelete, semTake, softtimer_create_timer
 * Константы: 0x3000B07C, 0xFFFFFFFF
 * Данные: DAT_3000b350, DAT_3000b35c, DAT_3000b374
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

void drv_sleep(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int local_1c [2];
  
  local_1c[0] = 0;
  local_1c[1] = 0;
  if (*DAT_3000b350 == '\0') {
    logMsg(DAT_3000b35c,0,0,0,0,0,0);
  }
  else if (param_1 != 0) {
    local_1c[0] = semBCreate(1,0);
    if (local_1c[0] != 0) {
      iVar1 = softtimer_create_timer
                        (local_1c + 1,param_1 * 10,0,DAT_3000b374,local_1c,param_2,param_3);
      if (iVar1 == 0) {
        semTake(local_1c[0],0xffffffff);
      }
      semDelete(local_1c[0]);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * primeCellSioDevInit @ 0x3000B43C  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_3000b38c, intCpuLock, intCpuUnlock
 * Вызывают: sysSerialHwInit
 * Константы: 0x3000B43C
 * Данные: DAT_3000b61c, DAT_3000b620, DAT_3000b624
 * ---------------------------------------------------------------- */
void primeCellSioDevInit(undefined4 *param_1)

{
  undefined4 uVar1;
  
  *DAT_3000b61c = 1;
  uVar1 = intCpuLock();
  *param_1 = DAT_3000b620;
  param_1[1] = DAT_3000b624;
  param_1[2] = DAT_3000b624;
  param_1[7] = 0;
  FUN_3000b38c(param_1);
  intCpuUnlock(uVar1);
  return;
}

/* ----------------------------------------------------------------
 * primeCellSioIntRx @ 0x3000B48C  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_3000b4f0, primeCellSioInt
 * Константы: 0x3000B48C
 * Данные: DAT_3000b61c
 * ---------------------------------------------------------------- */
void primeCellSioIntRx(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while ((iVar1 < 0x11 && ((*(uint *)(*(int *)(param_1 + 0x14) + 0x7c) & 8) != 0))) {
    if (*DAT_3000b61c != 0) {
      (**(code **)(param_1 + 8))
                (*(undefined4 *)(param_1 + 0x10),(int)(char)**(undefined4 **)(param_1 + 0x14));
    }
    iVar1 = iVar1 + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3000b4f0 @ 0x3000B4F0  (примерный размер ~868 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: intCpuLock, intCpuUnlock, primeCellSioIntRx
 * Константы: 0xFFFFFFFF, 0x3000B4F0
 * Данные: DAT_3000b628, DAT_3000b62c
 * ---------------------------------------------------------------- */
undefined4 FUN_3000b4f0(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    if ((param_2 & 0xc) < 9) {
      uVar3 = (uint)*(byte *)(DAT_3000b628 + (param_2 & 0xc));
    }
    else {
      uVar3 = 3;
    }
    if ((param_2 & 0x20) != 0) {
      uVar3 = uVar3 | 4;
    }
    if ((param_2 & 0xc0) == 0x40) {
      uVar3 = uVar3 | 8;
    }
    else if ((param_2 & 0xc0) == 0xc0) {
      uVar3 = uVar3 | 0x18;
    }
    if ((param_2 & 2) != 0) {
      uVar3 = uVar3 | 0x40;
    }
    uVar2 = 0;
    while ((uVar2 < DAT_3000b62c && ((*(uint *)(*(int *)(param_1 + 0x14) + 0x7c) & 1) != 0))) {
      primeCellSioIntRx(param_1);
      uVar2 = uVar2 + 1;
    }
    if (uVar2 == DAT_3000b62c) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = intCpuLock();
      *(uint *)(*(int *)(param_1 + 0x14) + 0xc) = uVar3;
      intCpuUnlock(uVar1);
      *(uint *)(param_1 + 0x28) = param_2;
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * primeCellSioIntTx @ 0x3000B854  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: primeCellSioInt
 * Константы: 0x3000B854, 0xFFFFFFFD
 * ---------------------------------------------------------------- */
void primeCellSioIntTx(int param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  char local_18 [4];
  
  iVar2 = 0;
  while( true ) {
    if (0xf < iVar2) {
      return;
    }
    if ((*(uint *)(*(int *)(param_1 + 0x14) + 0x7c) & 2) == 0) break;
    iVar1 = (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 0xc),local_18);
    if (iVar1 == -1) {
      puVar3 = (uint *)(*(int *)(param_1 + 0x14) + 4);
      *puVar3 = *puVar3 & 0xfffffffd;
      return;
    }
    **(int **)(param_1 + 0x14) = (int)local_18[0];
    iVar2 = iVar2 + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * primeCellSioInt @ 0x3000B8E4  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: primeCellSioIntRx, primeCellSioIntTx
 * Константы: 0x3000B8E4
 * ---------------------------------------------------------------- */
void primeCellSioInt(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x14) + 8);
  if ((uVar1 & 2) == 0) {
    if ((uVar1 & 0xc) != 0) {
      primeCellSioIntRx(param_1);
    }
  }
  else {
    primeCellSioIntTx(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3000b924 @ 0x3000B924  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000B924
 * Данные: DAT_3000baa4
 * ---------------------------------------------------------------- */
undefined4 FUN_3000b924(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  undefined1 auStack_14 [4];
  
  if (*(int *)(param_1 + 0x1c) == 2) {
    if (*DAT_3000baa4 == 0) {
      do {
        iVar1 = (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 0xc),auStack_14);
      } while (iVar1 != -1);
    }
    else {
      puVar3 = (uint *)(*(int *)(param_1 + 0x14) + 4);
      *puVar3 = *puVar3 | 2;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0x47;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * sysSerialHwInit @ 0x3000BAAC  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: primeCellSioDevInit
 * Вызывают: sysHwInit
 * Константы: 0x3000BAAC
 * Данные: DAT_3000bca0, DAT_3000bca4, DAT_3000bca8, DAT_3000bcac, DAT_3000bcb0, DAT_3000bcb4, DAT_3000bcb8, DAT_3000bcbc
 * ---------------------------------------------------------------- */
void sysSerialHwInit(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 1; iVar1 = iVar1 + 1) {
    *(undefined4 *)(DAT_3000bca0 + iVar1 * 0x30) = *(undefined4 *)(DAT_3000bca4 + iVar1 * 0xc);
    *(undefined4 *)(DAT_3000bca8 + iVar1 * 0x30) = DAT_3000bcac;
    *(undefined4 *)(DAT_3000bcb0 + iVar1 * 0x30) = DAT_3000bcb4;
    *(undefined1 *)(DAT_3000bcb8 + iVar1 * 0x30) = *(undefined1 *)(DAT_3000bcbc + iVar1 * 0xc);
    *(undefined1 *)(DAT_3000bcc0 + iVar1 * 0x30) = *(undefined1 *)(DAT_3000bcbc + iVar1 * 0xc);
    primeCellSioDevInit(DAT_3000bcc4 + iVar1 * 0x30);
  }
  return;
}

/* ----------------------------------------------------------------
 * sysSerialHwInit2 @ 0x3000BB78  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: intConnect, intEnable
 * Вызывают: sysHwInit2
 * Константы: 0x3000BB78
 * Данные: DAT_3000bcbc, DAT_3000bcc4, DAT_3000bcc8, DAT_3000bccc
 * ---------------------------------------------------------------- */
void sysSerialHwInit2(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 1; iVar1 = iVar1 + 1) {
    intConnect(*(undefined4 *)(DAT_3000bcc8 + iVar1 * 0xc),DAT_3000bccc,DAT_3000bcc4 + iVar1 * 0x30)
    ;
    intEnable(*(undefined1 *)(DAT_3000bcbc + iVar1 * 0xc));
  }
  return;
}

/* ----------------------------------------------------------------
 * sysSerialChanGet @ 0x3000BBD0  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrSerialInit
 * Константы: 0x3000BBD0, 0xFFFFFFFF
 * Данные: DAT_3000bcc4
 * ---------------------------------------------------------------- */
undefined4 sysSerialChanGet(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_3000bcc4;
  if (param_1 != 0) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sysSerialReset @ 0x3000BC00  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: intDisable
 * Константы: 0x3000BC00
 * Данные: DAT_3000bcbc
 * ---------------------------------------------------------------- */
void sysSerialReset(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 1; iVar1 = iVar1 + 1) {
    intDisable(*(undefined1 *)(DAT_3000bcbc + iVar1 * 0xc));
  }
  return;
}

/* ----------------------------------------------------------------
 * SETMAC @ 0x3000D004  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_SetPsMacAddr
 * Константы: 0x3000D004
 * ---------------------------------------------------------------- */
void SETMAC(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined1 param_5,undefined1 param_6)

{
  BSP_SetPsMacAddr(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* ----------------------------------------------------------------
 * SHOWMAC @ 0x3000D048  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x3000D048
 * Данные: DAT_3000d0ec, DAT_3000d0fc
 * ---------------------------------------------------------------- */
void SHOWMAC(void)

{
  logMsg(DAT_3000d0fc,*DAT_3000d0ec,DAT_3000d0ec[1],DAT_3000d0ec[2],DAT_3000d0ec[3],DAT_3000d0ec[4],
         DAT_3000d0ec[5]);
  return;
}

/* ----------------------------------------------------------------
 * testProcess @ 0x3000D2C4  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000D2C4
 * ---------------------------------------------------------------- */
void testProcess(void)

{
  return;
}

/* ----------------------------------------------------------------
 * hwVerGet @ 0x3000D3A4  (примерный размер ~672 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: BSP_GPIO_DrcGet, BSP_GPIO_DrcSet, BSP_GPIO_ValGet, BSP_HKADC_GetVerSafe, logMsg
 * Вызывают: BSP_ProductInfoInit
 * Константы: 0xFFFFFFFF, 0x3000D3A4, 0xFFFFFFFD, 0xFFFFFFF8, 0xFFFFEFFF
 * Данные: DAT_3000dd44, DAT_3000dd48, DAT_3000dd4c, DAT_3000dd50, DAT_3000dd54, DAT_3000dd58, DAT_3000dd5c, DAT_3000dd60
 * ---------------------------------------------------------------- */
undefined4 hwVerGet(ushort *param_1,ushort *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  byte local_1c;
  undefined1 local_1b [3];
  uint local_18;
  uint local_14;
  
  uVar4 = DAT_3000dd44;
  if (param_1 != (ushort *)0x0) {
    *DAT_3000dd48 = *DAT_3000dd48 & 0xfffffffd;
    *DAT_3000dd4c = *DAT_3000dd4c & 0xfffffff8;
    *DAT_3000dd50 = *DAT_3000dd50 & 0xffffefff | 0x1000;
    iVar1 = BSP_GPIO_DrcGet(2,&local_14);
    if (iVar1 == 0) {
      if (((local_14 & 0x11) == 0) || (iVar1 = BSP_GPIO_DrcSet(2,0x11,0), iVar1 == 0)) {
        iVar1 = BSP_GPIO_ValGet(2,&local_18);
        if (iVar1 == 0) {
          local_18 = local_18 & 0x20000;
          if (local_18 == 0) {
            uVar2 = BSP_HKADC_GetVerSafe(0,&local_1c);
            uVar3 = BSP_HKADC_GetVerSafe(2,local_1b);
            if ((uVar3 | uVar2) == 0) {
              *param_1 = CONCAT11(local_1c,local_1b[0]);
              if (*param_1 == DAT_3000dd68) {
                *param_1 = 3;
              }
              iVar1 = BSP_HKADC_GetVerSafe(9,&local_1c);
              if (iVar1 == 0) {
                *param_2 = (ushort)local_1c;
                logMsg(DAT_3000dd70,*param_1,*param_2,0,0,0,0);
                uVar4 = 0;
              }
              else {
                logMsg(DAT_3000dd6c,iVar1,0,0,0,0,0);
                uVar4 = 0xffffffff;
              }
            }
            else {
              logMsg(DAT_3000dd64,0,uVar3 | uVar2,0,0,0,0);
              uVar4 = 0xffffffff;
            }
          }
          else {
            *param_1 = (ushort)DAT_3000dd60;
            *param_2 = 0;
            uVar4 = 0;
          }
        }
        else {
          logMsg(DAT_3000dd5c,0,0,0,0,0,0);
          uVar4 = 0xffffffff;
        }
      }
      else {
        logMsg(DAT_3000dd58,0,0,0,0,0,0);
        uVar4 = 0xffffffff;
      }
    }
    else {
      logMsg(DAT_3000dd54,0,0,0,0,0,0);
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * OM_MemCheckVolid @ 0x3000DDDC  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: OM_REGCheckVolid
 * Константы: 0x3000DDDC, 0xFFFFFFFF
 * Данные: DAT_3000e974, DAT_3000e978, DAT_3000e97c
 * ---------------------------------------------------------------- */
undefined4 OM_MemCheckVolid(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (*DAT_3000e974 <= iVar1) {
      return 0xffffffff;
    }
    if ((*(uint *)(DAT_3000e978 + iVar1 * 0x18) <= param_1) &&
       (param_1 <=
        (*(int *)(DAT_3000e978 + iVar1 * 0x18) + *(int *)(DAT_3000e97c + iVar1 * 0x18)) - 1U))
    break;
    iVar1 = iVar1 + 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * OM_RAMCheckVolid @ 0x3000DE78  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 0
 * Вызывают: BSP_OM_MemChk, BSP_OM_MemNWrite, BSP_OM_MemPrint, BSP_OM_MemRead, BSP_OM_MemWrite, OM_REGCheckVolid
 * Константы: 0x3000DE78, 0x03D00000, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 OM_RAMCheckVolid(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 + 0xd0000000U < 0x3d00000) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * OM_REGCheckVolid @ 0x3000DEA8  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: OM_MemCheckVolid, OM_RAMCheckVolid
 * Вызывают: BSP_OM_RegRead, BSP_OM_RegWrite
 * Константы: 0xFFFFFFFF, 0x3000DEA8
 * ---------------------------------------------------------------- */
undefined4 OM_REGCheckVolid(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = OM_MemCheckVolid(param_1);
  if (iVar1 == 0) {
    iVar1 = OM_RAMCheckVolid(param_1);
    if (iVar1 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * OM_GetVersionInfo @ 0x3000DEF0  (примерный размер ~224 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: memcpy, strlen
 * Вызывают: BSP_OM_GetVersion
 * Константы: 0x3000DEF0, 0xFFFFFFFF
 * Данные: DAT_3000e980, DAT_3000e984, DAT_3000e988, DAT_3000e98c, DAT_3000e990, DAT_3000e994, DAT_3000e998, DAT_3000e99c
 * ---------------------------------------------------------------- */
undefined4 OM_GetVersionInfo(void *param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    sVar2 = strlen(DAT_3000e980);
    memcpy(param_1,DAT_3000e984,sVar2);
    sVar2 = strlen(DAT_3000e988);
    memcpy((void *)((int)param_1 + 0x10),DAT_3000e98c,sVar2);
    sVar2 = strlen(DAT_3000e988);
    memcpy((void *)((int)param_1 + 0x20),DAT_3000e98c,sVar2);
    sVar2 = strlen(DAT_3000e990);
    memcpy((void *)((int)param_1 + 0x30),DAT_3000e994,sVar2);
    sVar2 = strlen(DAT_3000e998);
    memcpy((void *)((int)param_1 + 0x40),DAT_3000e99c,sVar2);
    sVar2 = strlen(DAT_3000e9a0);
    memcpy((void *)((int)param_1 + 0x50),DAT_3000e9a4,sVar2);
    sVar2 = strlen(DAT_3000e9a8);
    memcpy((void *)((int)param_1 + 0x60),DAT_3000e9ac,sVar2);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * bootload_div @ 0x300145F0  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: nand_yaffs_write_size
 * Константы: 0x300145F0
 * ---------------------------------------------------------------- */
int bootload_div(uint param_1,uint param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_2 * 100 <= param_1; param_1 = param_1 + param_2 * -100) {
    iVar1 = iVar1 + 100;
  }
  for (; param_2 <= param_1; param_1 = param_1 - param_2) {
    iVar1 = iVar1 + 1;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = param_1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3001465c @ 0x3001465C  (примерный размер ~1528 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 9
 * Вызывает: FUN_30014448, FUN_30016038, FUN_300161c8, FUN_3001640c, FUN_30016424, __udiv32, nandc_bbm_real_addr, nandc_native_location_by_address, printf
 * Константы: 0xF0000000, 0x1FFFFFFF, 0x0FFFFFFF, 0x3001465C
 * Данные: DAT_300150f8, DAT_30015230, DAT_300156ac, DAT_300156b0, DAT_300156b4, DAT_300156b8, DAT_300157f4, DAT_300157f8
 * ---------------------------------------------------------------- */
int FUN_3001465c(uint param_1,int param_2,uint param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint local_48;
  undefined4 *local_44;
  int local_40;
  int local_38;
  int local_30;
  uint local_4;
  
  local_44 = (undefined4 *)0x0;
  piVar3 = (int *)*DAT_300150f8;
  local_40 = 0;
  iVar4 = 1;
  if (piVar3 == (int *)0x0) {
    return 1;
  }
  iVar2 = *piVar3;
  local_4 = param_3;
  if (param_4 != 0) {
    iVar4 = nandc_native_location_by_address(piVar3,param_1);
    if (iVar4 != 0) goto LAB_30014bd4;
    iVar1 = __udiv32(param_3,param_4 + *(int *)(iVar2 + 4));
    local_4 = param_3 - param_4 * iVar1;
    if (((local_4 & *(uint *)(iVar2 + 0xc)) != 0) || ((param_1 & *(uint *)(iVar2 + 0x2c)) != 0)) {
      if (((*DAT_30015230 & 0x200) != 0) && (-1 < (int)*DAT_30015230)) {
        printf(DAT_300156ac,local_4,param_1);
      }
      iVar4 = 3;
      goto LAB_30014bd4;
    }
  }
  if (((*DAT_30015230 & 0x200) != 0) && (0x1fffffff < (int)(*DAT_30015230 & 0xf0000000))) {
    printf(DAT_300156b0,param_1,param_2,local_4,param_4,param_5);
  }
  while (local_4 != 0) {
    iVar4 = nandc_native_location_by_address(piVar3,param_1);
    if (iVar4 != 0) {
      if (((*DAT_30015230 & 0x200) != 0) && (-1 < (int)*DAT_30015230)) {
        printf(DAT_300156b4,param_1);
      }
      break;
    }
    if (local_44 == (undefined4 *)0x0) {
      local_44 = (undefined4 *)piVar3[2];
    }
    else if ((undefined4 *)piVar3[2] != local_44) {
      if (((*DAT_30015230 & 0x200) != 0) && (-1 < (int)*DAT_30015230)) {
        printf(DAT_300156b8,param_1,*local_44,local_44[2]);
      }
      iVar4 = 0xb;
      break;
    }
    iVar4 = FUN_30014448(param_1 >> (*(uint *)(iVar2 + 0x34) & 0xff),&local_30);
    if (iVar4 != 0) {
      if (((*DAT_30015230 & 0x200) != 0) && (-1 < (int)*DAT_30015230)) {
        printf(DAT_300157f4,param_1);
      }
      break;
    }
    if (local_30 == 1) {
      if (((*DAT_30015230 & 0x200) != 0) && (0xfffffff < (int)(*DAT_30015230 & 0xf0000000))) {
        printf(DAT_300157f8,param_1);
      }
      param_1 = param_1 + *(int *)(*piVar3 + 0x20);
      local_40 = local_40 + 1;
    }
    else {
      if (((*DAT_30015230 & 0x200) != 0) && (0x1fffffff < (int)(*DAT_30015230 & 0xf0000000))) {
        printf(DAT_300157fc,param_1);
      }
      uVar5 = param_1 & *(uint *)(iVar2 + 0xc);
      local_48 = *(int *)(iVar2 + 4) - uVar5;
      if (local_4 < local_48) {
        local_48 = local_4;
      }
      if (local_48 < *(uint *)(iVar2 + 4)) {
        if (((*DAT_30015230 & 0x200) != 0) && (0x1fffffff < (int)(*DAT_30015230 & 0xf0000000))) {
          printf(DAT_30015800,piVar3[0x1d],local_48);
        }
        iVar4 = FUN_30016038(piVar3,uVar5,param_2,local_48);
        if (iVar4 != 0) {
          iVar4 = 0xc;
          break;
        }
        param_2 = param_2 + local_48;
        param_1 = param_1 + local_48;
        local_4 = local_4 - local_48;
        piVar3[0x1d] = local_48 + piVar3[0x1d];
        if (local_4 == 0) {
          iVar4 = 0;
          break;
        }
      }
      uVar5 = *(int *)(iVar2 + 0x20) - (param_1 & *(uint *)(iVar2 + 0x2c));
      if (local_4 < uVar5) {
        uVar5 = local_4;
      }
      iVar4 = nandc_bbm_real_addr(piVar3[0x1d],piVar3 + 0x1c);
      if (iVar4 != 0) break;
      FUN_30016424(piVar3,0x30);
      for (; uVar5 != 0; uVar5 = uVar5 - iVar1) {
        if (uVar5 < *(uint *)(iVar2 + 4)) {
          if (((*DAT_30015230 & 0x200) != 0) && (0xfffffff < (int)(*DAT_30015230 & 0xf0000000))) {
            printf(DAT_30015980,piVar3[0x1d],uVar5);
          }
          iVar4 = FUN_30016038(piVar3,0,param_2,uVar5);
          if (iVar4 != 0) {
            FUN_3001640c(piVar3);
            iVar4 = 0xc;
            goto LAB_30014bd4;
          }
          param_1 = param_1 + uVar5;
          local_4 = local_4 - uVar5;
          iVar4 = 0;
          break;
        }
        if (param_4 == 0) {
          local_38 = 0;
        }
        else {
          local_38 = param_2 + *(int *)(iVar2 + 4);
        }
        iVar4 = FUN_300161c8(piVar3,param_2,local_38,0,param_4,0x30);
        if (iVar4 != 0) {
          if (((*DAT_30015230 & 0x200) != 0) && (-1 < (int)*DAT_30015230)) {
            printf(DAT_30015a44,piVar3[0x1f],piVar3[0x1c]);
          }
          FUN_3001640c(piVar3);
          iVar4 = 0xc;
          goto LAB_30014bd4;
        }
        if (param_4 == 0) {
          param_2 = param_2 + *(int *)(iVar2 + 4);
        }
        else {
          param_2 = param_2 + param_4 + *(int *)(iVar2 + 4);
        }
        param_1 = param_1 + *(int *)(iVar2 + 4);
        local_4 = local_4 - *(int *)(iVar2 + 4);
        iVar1 = *(int *)(iVar2 + 4);
        piVar3[0x1d] = piVar3[0x1d] + *(int *)(iVar2 + 4);
        piVar3[0x1c] = piVar3[0x1c] + *(int *)(iVar2 + 4);
        iVar4 = 0;
      }
      FUN_3001640c(piVar3);
    }
  }
LAB_30014bd4:
  if ((((param_5 != (int *)0x0) &&
       (*param_5 = local_40 << (*(uint *)(iVar2 + 0x34) & 0xff), *param_5 != 0)) &&
      ((*DAT_30015230 & 0x200) != 0)) && (-1 < (int)*DAT_30015230)) {
    printf(DAT_30015b74,*param_5);
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * FUN_30014c54 @ 0x30014C54  (примерный размер ~848 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_30014448, FUN_300161c8, FUN_3001640c, FUN_30016424, nandc_bbm_real_addr, nandc_native_location_by_address, printf
 * Вызывают: FUN_30015718
 * Константы: 0xF0000000, 0x1FFFFFFF, 0x30014C54, 0x0FFFFFFF
 * Данные: DAT_300150f8, DAT_30015230, DAT_300156b4, DAT_300157f4, DAT_300157f8, DAT_300157fc, DAT_30015a44, DAT_30015b78
 * ---------------------------------------------------------------- */
int FUN_30014c54(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  
  local_3c = (undefined4 *)0x0;
  piVar2 = (int *)*DAT_300150f8;
  local_2c = 0;
  iVar4 = 1;
  if (piVar2 == (int *)0x0) {
LAB_30014f90:
    iVar4 = 1;
  }
  else {
    iVar1 = *piVar2;
    if (((*DAT_30015230 & 0x200) != 0) && (0x1fffffff < (int)(*DAT_30015230 & 0xf0000000))) {
      printf(DAT_30015b78,param_1,param_2);
    }
    local_38 = *(int *)(iVar1 + 0x20);
    param_1 = param_1 & *(uint *)(iVar1 + 0x30);
    while (local_38 != 0) {
      iVar4 = nandc_native_location_by_address(piVar2,param_1);
      if (iVar4 != 0) {
        if ((*DAT_30015230 & 0x200) == 0) {
          return iVar4;
        }
        if ((int)*DAT_30015230 < 0) {
          return iVar4;
        }
        printf(DAT_300156b4,param_1);
        return iVar4;
      }
      if (local_3c == (undefined4 *)0x0) {
        local_3c = (undefined4 *)piVar2[2];
      }
      else if ((undefined4 *)piVar2[2] != local_3c) {
        if (((*DAT_30015230 & 0x200) != 0) && (-1 < (int)*DAT_30015230)) {
          printf(DAT_30015c88,param_1,*local_3c,local_3c[2]);
        }
        return 0xb;
      }
      iVar4 = FUN_30014448(param_1 >> (*(uint *)(iVar1 + 0x34) & 0xff),&local_34);
      if (iVar4 != 0) {
        if ((*DAT_30015230 & 0x200) == 0) {
          return iVar4;
        }
        if ((int)*DAT_30015230 < 0) {
          return iVar4;
        }
        printf(DAT_300157f4,param_1);
        return iVar4;
      }
      if (local_34 == 1) {
        if (((*DAT_30015230 & 0x200) != 0) && (0xfffffff < (int)(*DAT_30015230 & 0xf0000000))) {
          printf(DAT_300157f8,param_1);
        }
        goto LAB_30014f90;
      }
      if (((*DAT_30015230 & 0x200) != 0) && (0x1fffffff < (int)(*DAT_30015230 & 0xf0000000))) {
        printf(DAT_300157fc,param_1);
      }
      iVar4 = nandc_bbm_real_addr(piVar2[0x1d],piVar2 + 0x1c);
      if (iVar4 != 0) {
        return iVar4;
      }
      FUN_30016424(piVar2,0x30);
      for (iVar3 = local_38; iVar4 = 0, iVar3 != 0; iVar3 = iVar3 - iVar4) {
        local_30 = param_2 + *(int *)(iVar1 + 4);
        iVar4 = FUN_300161c8(piVar2,param_2,local_30,0,param_3,0x30);
        if (iVar4 != 0) {
          if (((*DAT_30015230 & 0x200) != 0) && (-1 < (int)*DAT_30015230)) {
            printf(DAT_30015a44,piVar2[0x1f],piVar2[0x1c]);
          }
          FUN_3001640c(piVar2);
          return 0xc;
        }
        if (param_3 == 0) {
          iVar4 = *(int *)(iVar1 + 4);
        }
        else {
          iVar4 = param_3 + *(int *)(iVar1 + 4);
        }
        param_2 = param_2 + iVar4;
        param_1 = param_1 + *(int *)(iVar1 + 4);
        local_38 = local_38 - *(int *)(iVar1 + 4);
        iVar4 = *(int *)(iVar1 + 4);
        piVar2[0x1d] = piVar2[0x1d] + *(int *)(iVar1 + 4);
        piVar2[0x1c] = piVar2[0x1c] + *(int *)(iVar1 + 4);
      }
      FUN_3001640c(piVar2);
    }
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * OSAL_SemBCreate @ 0x30017D44  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: semBCreate
 * Вызывают: TFUP_CheckInit, dloadInit, sdmmcISRInit
 * Константы: 0x30017D44
 * ---------------------------------------------------------------- */
void OSAL_SemBCreate(undefined4 param_1,undefined4 param_2)

{
  semBCreate(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * OSAL_SemMCreate @ 0x30017D60  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: semMCreate
 * Вызывают: TFUP_CheckInit, yaffsDevCreate, yaffs_StartUp
 * Константы: 0x30017D60
 * ---------------------------------------------------------------- */
void OSAL_SemMCreate(undefined4 param_1)

{
  semMCreate(param_1);
  return;
}

/* ----------------------------------------------------------------
 * OSAL_SemCCreate @ 0x30017D74  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: semCCreate
 * Константы: 0x30017D74
 * ---------------------------------------------------------------- */
void OSAL_SemCCreate(undefined4 param_1,undefined4 param_2)

{
  semCCreate(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * OSAL_SemTake @ 0x30017D90  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 1
 * Вызывает: semTake
 * Вызывают: Send_cmd_to_host_raw, TFUP_CheckTask, TFUP_DloadTask, TFUP_dosFsDevCreate, yaffsClose, yaffsRead, yaffsWrite, yaffsfs_Lock
 * Константы: 0x30017D90
 * ---------------------------------------------------------------- */
void OSAL_SemTake(undefined4 param_1,undefined4 param_2)

{
  semTake(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * OSAL_SemGive @ 0x30017DAC  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 11 | Вызывает: 1
 * Вызывает: semGive
 * Вызывают: ISR_Callback, SD_RecordErrLogFromInt, TFUP_CheckCallback, TFUP_dosFsDevCreate, dloadTFCallback, sd_mmc_event_Handler, sdmmcTimerCallBack, yaffsClose, yaffsRead, yaffsWrite
 *           ...
 * Константы: 0x30017DAC
 * ---------------------------------------------------------------- */
void OSAL_SemGive(undefined4 param_1)

{
  semGive(param_1);
  return;
}

/* ----------------------------------------------------------------
 * OSAL_SemDelete @ 0x30017DC0  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: semDelete
 * Вызывают: dloadInit
 * Константы: 0x30017DC0
 * ---------------------------------------------------------------- */
void OSAL_SemDelete(undefined4 param_1)

{
  semDelete(param_1);
  return;
}

/* ----------------------------------------------------------------
 * OSAL_LogMsg @ 0x30017DD4  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 96 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: ATCommandProcess, BSP_DLOAD_GetDloadInfo, BSP_DLOAD_GetISOVer, BSP_DLOAD_GetMidwayRestart, BSP_DLOAD_SetMidwayRestart, BSP_Errlog_IFCInit, CvInfoReport, DCBInit, ErrlogRegFunc, FUN_30080798
 *           ...
 * Константы: 0x30017DD4
 * ---------------------------------------------------------------- */
void OSAL_LogMsg(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  logMsg(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30017e20 @ 0x30017E20  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: FUN_30017ee4, FUN_30018014, FUN_300183fc, yaffs2_CheckpointClose
 * Константы: 0x30017E20
 * Данные: DAT_3001898c, DAT_30018990
 * ---------------------------------------------------------------- */
int FUN_30017e20(int param_1,int param_2)

{
  if ((param_2 < *(int *)(param_1 + 0xdc)) || (*(int *)(param_1 + 0xe0) < param_2)) {
    printf(DAT_3001898c,param_2);
    printf(DAT_30018990,0x1e);
  }
  return *(int *)(param_1 + 0x124) + (param_2 - *(int *)(param_1 + 0xdc)) * 8;
}

/* ----------------------------------------------------------------
 * FUN_30017ea0 @ 0x30017EA0  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: yaffs2_CheckpointOpen
 * Константы: 0x30017EA0
 * Данные: DAT_30018988, DAT_30018994
 * ---------------------------------------------------------------- */
bool FUN_30017ea0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x1c);
  if ((*DAT_30018988 & 0x8000) != 0) {
    printf(DAT_30018994,iVar1);
  }
  return 0 < iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30017ee4 @ 0x30017EE4  (примерный размер ~304 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: FUN_30017e20, printf
 * Вызывают: yaffs2_CheckpointInvalidateStream, yaffs2_CheckpointOpen
 * Константы: 0xFF0FFFFF, 0x30017EE4, 0x00900000, 0x00300000
 * Данные: DAT_30018988, DAT_30018998, DAT_3001899c
 * ---------------------------------------------------------------- */
undefined4 FUN_30017ee4(int param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x48) == 0) {
    uVar1 = 0;
  }
  else {
    if ((*DAT_30018988 & 0x8000) != 0) {
      printf(DAT_30018998,*(undefined4 *)(param_1 + 0xdc),*(undefined4 *)(param_1 + 0xe0));
    }
    for (iVar4 = *(int *)(param_1 + 0xdc); iVar4 <= *(int *)(param_1 + 0xe0); iVar4 = iVar4 + 1) {
      puVar2 = (uint *)FUN_30017e20(param_1,iVar4);
      if ((*puVar2 >> 0x14 & 0xf) == 7) {
        if ((*DAT_30018988 & 0x8000) != 0) {
          printf(DAT_3001899c,iVar4);
        }
        *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + 1;
        iVar3 = (**(code **)(param_1 + 0x48))(param_1,iVar4 - *(int *)(param_1 + 0xe4));
        if (iVar3 == 0) {
          (**(code **)(param_1 + 0x5c))(param_1,iVar4);
          *puVar2 = *puVar2 & 0xff0fffff | 0x900000;
        }
        else {
          *puVar2 = *puVar2 & 0xff0fffff | 0x300000;
          *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
          *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) + *(int *)(param_1 + 0xc);
        }
      }
    }
    *(undefined4 *)(param_1 + 0x100) = 0;
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30018014 @ 0x30018014  (примерный размер ~264 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30017e20, printf
 * Вызывают: FUN_300183fc
 * Константы: 0xFFFFFFFF, 0x30018014
 * Данные: DAT_30018988, DAT_300189a0, DAT_300189a4, DAT_300189a8
 * ---------------------------------------------------------------- */
void FUN_30018014(int param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x1c);
  if ((*DAT_30018988 & 0x8000) != 0) {
    printf(DAT_300189a0,*(undefined4 *)(param_1 + 0x134),*(undefined4 *)(param_1 + 0x1c),iVar2,
           *(undefined4 *)(param_1 + 0x10c));
  }
  if (((-1 < *(int *)(param_1 + 0x10c)) && (*(int *)(param_1 + 0x10c) <= *(int *)(param_1 + 0xe0)))
     && (0 < iVar2)) {
    for (iVar2 = *(int *)(param_1 + 0x10c); iVar2 <= *(int *)(param_1 + 0xe0); iVar2 = iVar2 + 1) {
      puVar1 = (uint *)FUN_30017e20(param_1,iVar2);
      if ((*puVar1 >> 0x14 & 0xf) == 3) {
        *(int *)(param_1 + 0x10c) = iVar2 + 1;
        *(int *)(param_1 + 0x108) = iVar2;
        if ((*DAT_30018988 & 0x8000) == 0) {
          return;
        }
        printf(DAT_300189a4,iVar2);
        return;
      }
    }
  }
  if ((*DAT_30018988 & 0x8000) != 0) {
    printf(DAT_300189a8);
  }
  *(undefined4 *)(param_1 + 0x10c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001811c @ 0x3001811C  (примерный размер ~308 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: yaffs2_CheckpointRead
 * Константы: 0xFFFFFFFF, 0x3001811C
 * Данные: DAT_30018988, DAT_300189ac, DAT_300189b0, DAT_300189b4, DAT_300189b8
 * ---------------------------------------------------------------- */
void FUN_3001811c(int param_1)

{
  int iVar1;
  undefined1 auStack_5c [8];
  undefined4 local_54;
  undefined4 local_48;
  int local_38;
  
  if ((*DAT_30018988 & 0x8000) != 0) {
    printf(DAT_300189ac,*(undefined4 *)(param_1 + 0x100),*(undefined4 *)(param_1 + 0x10c));
  }
  if (*(int *)(param_1 + 0x100) < *(int *)(param_1 + 0x114)) {
    for (iVar1 = *(int *)(param_1 + 0x10c); iVar1 <= *(int *)(param_1 + 0xe0); iVar1 = iVar1 + 1) {
      (**(code **)(param_1 + 0x58))
                (param_1,*(int *)(param_1 + 0xc) * iVar1 - *(int *)(param_1 + 0xe8),0,auStack_5c);
      if ((*DAT_30018988 & 0x8000) != 0) {
        printf(DAT_300189b0,iVar1,local_54,local_38,local_48);
      }
      if (local_38 == 0x21) {
        *(undefined4 *)(param_1 + 0x10c) = local_54;
        *(int *)(param_1 + 0x108) = iVar1;
        *(int *)(*(int *)(param_1 + 0x110) + *(int *)(param_1 + 0x100) * 4) = iVar1;
        *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;
        if ((*DAT_30018988 & 0x8000) == 0) {
          return;
        }
        printf(DAT_300189b4,iVar1);
        return;
      }
    }
  }
  if ((*DAT_30018988 & 0x8000) != 0) {
    printf(DAT_300189b8);
  }
  *(undefined4 *)(param_1 + 0x10c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
  return;
}

/* ----------------------------------------------------------------
 * print_yaffs_Device @ 0x30020000  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x30020000
 * ---------------------------------------------------------------- */
undefined4 print_yaffs_Device(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30020008 @ 0x30020008  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x30020008
 * ---------------------------------------------------------------- */
bool FUN_30020008(int param_1)

{
  bool bVar1;
  
  if ((*(int *)(param_1 + 0x48) == 0) || (*(int *)(param_1 + 0x4c) == 0)) {
    bVar1 = false;
  }
  else if ((((*(int *)(param_1 + 0x54) == 0) || (*(int *)(param_1 + 0x58) == 0)) ||
           (*(int *)(param_1 + 0x5c) == 0)) || (*(int *)(param_1 + 0x60) == 0)) {
    if ((((*(int *)(param_1 + 0x2c) == 0) && (*(int *)(param_1 + 0x54) == 0)) &&
        ((*(int *)(param_1 + 0x58) == 0 &&
         ((*(int *)(param_1 + 0x40) != 0 && (*(int *)(param_1 + 0x44) != 0)))))) &&
       (*(int *)(param_1 + 0x5c) == 0)) {
      bVar1 = *(int *)(param_1 + 0x60) == 0;
    }
    else {
      bVar1 = false;
    }
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}

/* ----------------------------------------------------------------
 * FUN_300200d4 @ 0x300200D4  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3001d318, yaffs_AddObjectToDirectory
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x300200D4
 * Данные: DAT_30020ca4
 * ---------------------------------------------------------------- */
undefined4 FUN_300200d4(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xd88) = 0;
  *(undefined4 *)(param_1 + 0xd8c) = 0;
  *(undefined4 *)(param_1 + 0xda4) = 0;
  *(undefined4 *)(param_1 + 0xda0) = 0;
  uVar1 = FUN_3001d318(param_1,3,0x4000);
  *(undefined4 *)(param_1 + 0xda0) = uVar1;
  uVar1 = FUN_3001d318(param_1,4,0x4000);
  *(undefined4 *)(param_1 + 0xda4) = uVar1;
  uVar1 = FUN_3001d318(param_1,1,DAT_30020ca4);
  *(undefined4 *)(param_1 + 0xd88) = uVar1;
  uVar1 = FUN_3001d318(param_1,2,DAT_30020ca4);
  *(undefined4 *)(param_1 + 0xd8c) = uVar1;
  if ((((*(int *)(param_1 + 0xd8c) == 0) || (*(int *)(param_1 + 0xd88) == 0)) ||
      (*(int *)(param_1 + 0xda0) == 0)) || (*(int *)(param_1 + 0xda4) == 0)) {
    uVar1 = 0;
  }
  else {
    yaffs_AddObjectToDirectory(*(undefined4 *)(param_1 + 0xd88),*(undefined4 *)(param_1 + 0xd8c));
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * getdskspc @ 0x30022548  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: yaffs_freespace
 * Константы: 0x30022548, 0xFFFFFFFF
 * Данные: DAT_30022628, DAT_30022644, DAT_30022648, DAT_300226b8
 * ---------------------------------------------------------------- */
undefined4 getdskspc(int param_1,undefined4 param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = yaffs_freespace(param_1,*(undefined4 *)(DAT_300226b8 + param_1 * 4));
  *param_5 = iVar1;
  if (*param_5 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    *param_3 = (*(int *)(DAT_30022648 + DAT_30022628 * param_1) -
               *(int *)(DAT_30022644 + DAT_30022628 * param_1)) * 0x20000 + 0x20000;
    *param_4 = *param_3 - *param_5;
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * CheckInit @ 0x3002632C  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3002632C
 * ---------------------------------------------------------------- */
undefined4 CheckInit(void)

{
  return 1;
}

/* ----------------------------------------------------------------
 * ynandif_WriteChunkToNAND @ 0x30026334  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_TRACE, nand_write_yaffs
 * Константы: 0x30026334
 * Данные: DAT_30026510
 * ---------------------------------------------------------------- */
undefined4 ynandif_WriteChunkToNAND(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_3 == 0) && (param_4 == 0)) {
    uVar1 = 0;
  }
  else {
    iVar2 = nand_write_yaffs(param_2,param_3,param_4,0x10);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
    else {
      BSP_TRACE(4,4,DAT_30026510,param_2,2,3,4,5,6);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * ynandif_ReadChunkFromNAND @ 0x300263D4  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_TRACE, nand_read_yaffs
 * Константы: 0x300263D4
 * Данные: DAT_30026514
 * ---------------------------------------------------------------- */
undefined4 ynandif_ReadChunkFromNAND(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_3 == 0) && (param_4 == 0)) {
    uVar1 = 0;
  }
  else {
    iVar2 = nand_read_yaffs(param_2,param_3,param_4,0x10);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
    else {
      BSP_TRACE(4,4,DAT_30026514,param_2,2,3,4,5,6);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * ynandif_EraseBlockInNAND @ 0x30026474  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: nand_erase, printf
 * Константы: 0x30026474
 * Данные: DAT_3002651c, DAT_30026520
 * ---------------------------------------------------------------- */
undefined4 ynandif_EraseBlockInNAND(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    printf(DAT_3002651c);
    uVar1 = 0;
  }
  else {
    iVar2 = nand_erase(param_2);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
    else {
      printf(DAT_30026520,param_2);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * ynandif_InitialiseNAND @ 0x300264F4  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_mount
 * Константы: 0x300264F4
 * ---------------------------------------------------------------- */
undefined4 ynandif_InitialiseNAND(int param_1)

{
  *(undefined4 *)(param_1 + 0x24) = 1;
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_30026524 @ 0x30026524  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: free, printf
 * Вызывают: yaffs_DeinitialiseRawTnodesAndObjects
 * Константы: 0x30026524
 * Данные: DAT_30026c34
 * ---------------------------------------------------------------- */
void FUN_30026524(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x144);
  if (puVar2 == (undefined4 *)0x0) {
    printf(DAT_30026c34,0x6e);
  }
  else {
    while (puVar2[3] != 0) {
      uVar1 = *(undefined4 *)puVar2[3];
      free(*(void **)(puVar2[3] + 4));
      free((void *)puVar2[3]);
      puVar2[3] = uVar1;
    }
    puVar2[1] = 0;
    puVar2[2] = 0;
    *puVar2 = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300265a8 @ 0x300265A8  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: yaffs_InitialiseRawTnodesAndObjects
 * Константы: 0x300265A8
 * Данные: DAT_30026c34
 * ---------------------------------------------------------------- */
void FUN_300265a8(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x144);
  if (puVar1 == (undefined4 *)0x0) {
    printf(DAT_30026c34,0x8a);
  }
  else {
    puVar1[3] = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30026604 @ 0x30026604  (примерный размер ~380 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: malloc, printf
 * Вызывают: yaffs_AllocateRawTnode
 * Константы: 0x30026604
 * Данные: DAT_30026c30, DAT_30026c34, DAT_30026c38, DAT_30026c3c, DAT_30026c40
 * ---------------------------------------------------------------- */
undefined4 FUN_30026604(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_1 + 0x144);
  if (piVar5 == (int *)0x0) {
    printf(DAT_30026c34,0x98);
    uVar1 = 0;
  }
  else if (param_2 < 1) {
    uVar1 = 1;
  }
  else {
    pvVar2 = malloc(*(int *)(param_1 + 0xb0) * param_2);
    if (pvVar2 == (void *)0x0) {
      printf(DAT_30026c38);
      uVar1 = 0;
    }
    else {
      for (iVar4 = 0; iVar4 < param_2 + -1; iVar4 = iVar4 + 1) {
        *(void **)(iVar4 * *(int *)(param_1 + 0xb0) + (int)pvVar2) =
             (void *)((iVar4 + 1) * *(int *)(param_1 + 0xb0) + (int)pvVar2);
      }
      *(int *)((param_2 + -1) * *(int *)(param_1 + 0xb0) + (int)pvVar2) = piVar5[1];
      piVar5[1] = (int)pvVar2;
      piVar5[2] = param_2 + piVar5[2];
      *piVar5 = param_2 + *piVar5;
      piVar3 = (int *)malloc(8);
      if (piVar3 == (int *)0x0) {
        printf(DAT_30026c3c);
        uVar1 = 0;
      }
      else {
        piVar3[1] = (int)pvVar2;
        *piVar3 = piVar5[3];
        piVar5[3] = (int)piVar3;
        if ((*DAT_30026c30 & 4) != 0) {
          printf(DAT_30026c40);
        }
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * nval_del @ 0x30027104  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_30026f90, memcpy, memset
 * Вызывают: FUN_3001bfb0, nval_set
 * Константы: 0x30027104, 0xFFFFFFB2
 * ---------------------------------------------------------------- */
undefined4 nval_del(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  size_t local_18;
  
  iVar1 = FUN_30026f90(param_1,param_2,param_3,0);
  if ((iVar1 < 0) || (param_2 <= iVar1)) {
    uVar2 = 0xffffffb2;
  }
  else {
    memcpy(&local_18,(void *)(param_1 + iVar1),4);
    memcpy((void *)(param_1 + iVar1),(void *)(param_1 + iVar1 + local_18),
           param_2 - (iVar1 + local_18));
    memset((void *)(param_1 + (param_2 - local_18)),0,local_18);
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nval_set @ 0x300271A4  (примерный размер ~328 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_30026f90, FUN_30027070, memcpy, nval_del, strncpy, ystrnlen
 * Вызывают: FUN_3001bfb0
 * Константы: 0x300271A4, 0xFFFFFFE4, 0xFFFFFFB2, 0xFFFFFFEF
 * ---------------------------------------------------------------- */
undefined4 nval_set(int param_1,int param_2,char *param_3,void *param_4,size_t param_5,uint param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  size_t local_34;
  int local_30;
  int local_2c;
  
  iVar1 = ystrnlen(param_3,param_2);
  local_30 = 0;
  iVar2 = FUN_30026f90(param_1,param_2,param_3,&local_30);
  if (((param_6 & 1) == 0) || (iVar2 < 0)) {
    if (((param_6 & 2) == 0) || (-1 < iVar2)) {
      iVar4 = FUN_30027070(param_1,param_2);
      local_2c = local_30 + (param_2 - iVar4);
      local_34 = param_5 + iVar1 + 5;
      if (local_2c < (int)local_34) {
        uVar3 = 0xffffffe4;
      }
      else {
        if (-1 < iVar2) {
          nval_del(param_1,param_2,param_3);
          iVar4 = FUN_30027070(param_1,param_2);
        }
        memcpy((void *)(param_1 + iVar4),&local_34,4);
        strncpy((char *)(param_1 + iVar4 + 4),param_3,local_34);
        memcpy((void *)(param_1 + iVar4 + 4 + iVar1 + 1),param_4,param_5);
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0xffffffb2;
    }
  }
  else {
    uVar3 = 0xffffffef;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * nval_get @ 0x300272EC  (примерный размер ~248 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30026f90, memcpy
 * Вызывают: yaffs_GetXAttribute
 * Константы: 0x300272EC, 0xFFFFFFB2, 0xFFFFFFDA
 * ---------------------------------------------------------------- */
size_t nval_get(int param_1,int param_2,undefined4 param_3,void *param_4,int param_5)

{
  int iVar1;
  size_t sVar2;
  size_t local_1c;
  
  iVar1 = FUN_30026f90(param_1,param_2,param_3,0);
  if ((-1 < iVar1) && (iVar1 < param_2)) {
    memcpy(&local_1c,(void *)(param_1 + iVar1),4);
    local_1c = local_1c - 4;
    for (iVar1 = iVar1 + 4;
        ((*(char *)(param_1 + iVar1) != '\0' && (0 < (int)local_1c)) && (iVar1 < param_2));
        iVar1 = iVar1 + 1) {
      local_1c = local_1c - 1;
    }
    iVar1 = iVar1 + 1;
    local_1c = local_1c - 1;
    if ((int)local_1c <= param_5) {
      memcpy(param_4,(void *)(param_1 + iVar1),local_1c);
      return local_1c;
    }
  }
  if (iVar1 < 0) {
    sVar2 = 0xffffffb2;
  }
  else {
    sVar2 = 0xffffffda;
  }
  return sVar2;
}

/* ----------------------------------------------------------------
 * nval_list @ 0x300273E4  (примерный размер ~272 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: memcpy, ystrnlen
 * Вызывают: yaffs_GetXAttribute, yaffs_ListXAttributes
 * Константы: 0x300273E4
 * ---------------------------------------------------------------- */
int nval_list(void *param_1,int param_2,undefined1 *param_3,int param_4)

{
  bool bVar1;
  size_t __n;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint local_28;
  
  uVar3 = 0;
  iVar2 = 0;
  bVar1 = false;
  memcpy(&local_28,param_1,4);
  while( true ) {
    if ((((local_28 < 5) || (param_2 < (int)local_28)) || (param_2 <= (int)(uVar3 + local_28))) ||
       (bVar1)) {
      return iVar2;
    }
    iVar4 = uVar3 + 4;
    local_28 = local_28 - 4;
    __n = ystrnlen((int)param_1 + iVar4,local_28);
    if ((int)(iVar2 + __n + 1) < param_4) {
      memcpy(param_3,(void *)((int)param_1 + iVar4),__n);
      param_3[__n] = 0;
      param_3 = param_3 + __n + 1;
      iVar2 = iVar2 + __n + 1;
    }
    else {
      bVar1 = true;
    }
    uVar3 = iVar4 + local_28;
    if (param_2 - 4U <= uVar3) break;
    memcpy(&local_28,(void *)((int)param_1 + uVar3),4);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * nval_hasvalues @ 0x300274F4  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: FUN_30027070
 * Вызывают: FUN_3001bfb0, yaffs_GetXAttribute, yaffs_ListXAttributes
 * Константы: 0x300274F4
 * ---------------------------------------------------------------- */
bool nval_hasvalues(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_30027070(param_1,param_2);
  return 0 < iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3002751c @ 0x3002751C  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: yaffs_VerifyBlocks
 * Константы: 0x3002751C
 * Данные: DAT_30028458, DAT_3002845c
 * ---------------------------------------------------------------- */
int FUN_3002751c(int param_1,int param_2)

{
  if ((param_2 < *(int *)(param_1 + 0xdc)) || (*(int *)(param_1 + 0xe0) < param_2)) {
    printf(DAT_30028458,param_2);
    printf(DAT_3002845c,0x1e);
  }
  return *(int *)(param_1 + 0x124) + (param_2 - *(int *)(param_1 + 0xdc)) * 8;
}

/* ----------------------------------------------------------------
 * ystrnlen @ 0x3002B540  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 9 | Вызывает: 0
 * Вызывают: FUN_3001c6e8, nval_list, nval_set, yaffs_CloneString, yaffs_GetFileSize, yaffs_GetObjectFileLength, yaffs_GetObjectName, yaffs_RenameObject, yaffs_SetObjectName
 * Константы: 0x3002B540
 * ---------------------------------------------------------------- */
int ystrnlen(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = param_1;
  if (param_2 != -1) {
    param_2 = param_2 + 1;
  }
  do {
    pcVar3 = pcVar2;
    if (param_2 == 0) break;
    pcVar3 = pcVar2 + 1;
    cVar1 = *pcVar2;
    param_2 = param_2 + -1;
    pcVar2 = pcVar3;
  } while (cVar1 != '\0');
  return (int)pcVar3 - (int)(param_1 + 1);
}

/* ----------------------------------------------------------------
 * Hi6451_BugAvoid @ 0x3003139C  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: HI6451_reg_write
 * Вызывают: HI6451_init
 * Константы: 0x3003139C
 * Данные: DAT_30032224, DAT_30032228
 * ---------------------------------------------------------------- */
void Hi6451_BugAvoid(void)

{
  if (*DAT_30032224 == 0x10) {
    if (*DAT_30032228 == 0) {
      HI6451_reg_write(0x1d,0x18);
      HI6451_reg_write(0x1f,0x18);
      HI6451_reg_write(0x21,0x18);
      HI6451_reg_write(0x25,0x14);
    }
    else {
      HI6451_reg_write(0x1d,0x1c);
      HI6451_reg_write(0x1f,0x1c);
      HI6451_reg_write(0x21,0x1c);
      HI6451_reg_write(0x25,0x1c);
    }
  }
  HI6451_reg_write(0x70,0x20);
  return;
}

/* ----------------------------------------------------------------
 * pmLDOON @ 0x30033B14  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: HI6451_voltage_switch
 * Константы: 0x30033B14
 * ---------------------------------------------------------------- */
void pmLDOON(undefined1 param_1)

{
  HI6451_voltage_switch(param_1,1);
  return;
}

/* ----------------------------------------------------------------
 * pmLDOOFF @ 0x30033B2C  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: HI6451_voltage_switch
 * Константы: 0x30033B2C
 * ---------------------------------------------------------------- */
void pmLDOOFF(undefined1 param_1)

{
  HI6451_voltage_switch(param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * pmSetLDOVltg @ 0x30033B44  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: HI6451_voltage_set
 * Вызывают: BSP_PMU_VolAdjust_ForSDIO
 * Константы: 0x30033B44
 * ---------------------------------------------------------------- */
void pmSetLDOVltg(undefined1 param_1,undefined2 param_2)

{
  HI6451_voltage_set(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * pmGetLDOVltg @ 0x30033B60  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: HI6451_voltage_get
 * Константы: 0x30033B60
 * ---------------------------------------------------------------- */
undefined4 pmGetLDOVltg(undefined1 param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  
  uVar1 = HI6451_voltage_get(param_1);
  *param_2 = uVar1;
  return 0;
}

/* ----------------------------------------------------------------
 * pmDRON @ 0x30033B80  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: HI6451_current_switch
 * Вызывают: BSP_TLED_LedSwitch
 * Константы: 0x30033B80
 * ---------------------------------------------------------------- */
void pmDRON(undefined1 param_1)

{
  HI6451_current_switch(param_1,1);
  return;
}

/* ----------------------------------------------------------------
 * pmDROFF @ 0x30033B98  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: HI6451_current_switch
 * Вызывают: BSP_TLED_LedOff, BSP_TLED_LedSwitch
 * Константы: 0x30033B98
 * ---------------------------------------------------------------- */
void pmDROFF(undefined1 param_1)

{
  HI6451_current_switch(param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * GetUSBConnStatus @ 0x30033C40  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30033C40
 * ---------------------------------------------------------------- */
undefined4 GetUSBConnStatus(void)

{
  return 1;
}

/* ----------------------------------------------------------------
 * pmGetLDOStatus @ 0x30033E30  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: HI6451_get_voltage_state
 * Вызывают: sdmmcStatusPollTask
 * Константы: 0x30033E30
 * ---------------------------------------------------------------- */
undefined1 pmGetLDOStatus(undefined1 param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = HI6451_get_voltage_state(param_1);
  *param_2 = uVar1;
  return *param_2;
}

/* ----------------------------------------------------------------
 * TestBitValue @ 0x30034450  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: RunSsdmaSha1
 * Константы: 0x30034450, 0x00FFFFFF
 * ---------------------------------------------------------------- */
undefined4 TestBitValue(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (0xffffff < uVar1) {
      return 0;
    }
    if ((param_2 & *param_1) == param_3) break;
    uVar1 = uVar1 + 1;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * SsdmaReset @ 0x3003449C  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x7FFFFFFF, 0x3003449C, 0x80000000
 * Данные: DAT_30034874
 * ---------------------------------------------------------------- */
void SsdmaReset(void)

{
  *DAT_30034874 = *DAT_30034874 & 0x7fffffff;
  *DAT_30034874 = *DAT_30034874 | 0x80000000;
  *DAT_30034874 = *DAT_30034874 & 0x7fffffff;
  return;
}

/* ----------------------------------------------------------------
 * SsdmaSha1Init @ 0x300344E4  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Bsp_SHA1Hash
 * Константы: 0x300344E4
 * Данные: DAT_30034878, DAT_3003487c
 * ---------------------------------------------------------------- */
bool SsdmaSha1Init(void)

{
  bool bVar1;
  
  bVar1 = (*DAT_30034878 & 1) == 0;
  if (bVar1) {
    *DAT_3003487c = *DAT_3003487c | 4;
  }
  return !bVar1;
}

/* ----------------------------------------------------------------
 * SetSsdmaSha1Iv @ 0x30034518  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Bsp_SHA1Hash
 * Константы: 0x30034518
 * Данные: DAT_30034880
 * ---------------------------------------------------------------- */
undefined4 SetSsdmaSha1Iv(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = DAT_30034880;
  for (uVar2 = 0; uVar2 < 5; uVar2 = uVar2 + 1) {
    *puVar1 = *(undefined4 *)(param_1 + uVar2 * 4);
    puVar1 = puVar1 + 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * RunSsdmaSha1 @ 0x30034558  (примерный размер ~196 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: TestBitValue
 * Вызывают: Bsp_SHA1Hash
 * Константы: 0x30034558
 * Данные: DAT_30034878, DAT_30034884, DAT_30034888, DAT_3003488c, DAT_30034890, DAT_30034894
 * ---------------------------------------------------------------- */
undefined4 RunSsdmaSha1(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  *DAT_30034884 = 0x10;
  if ((*DAT_30034878 & 1) == 0) {
    puVar3 = DAT_30034888;
    for (uVar4 = 0; uVar4 < 0x10; uVar4 = uVar4 + 1) {
      *puVar3 = *(undefined4 *)(param_1 + uVar4 * 4);
      puVar3 = puVar3 + 1;
    }
    *DAT_3003488c = 1;
    iVar2 = TestBitValue(DAT_30034890,0x10,0x10);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
    else {
      *DAT_30034884 = 0x10;
      puVar3 = DAT_30034894;
      for (uVar4 = 0; uVar4 < 5; uVar4 = uVar4 + 1) {
        *(undefined4 *)(param_2 + uVar4 * 4) = *puVar3;
        puVar3 = puVar3 + 1;
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * SsdmaRsaInit @ 0x3003461C  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: secDataRsa
 * Константы: 0x3003461C
 * Данные: DAT_3003487c, DAT_30034898
 * ---------------------------------------------------------------- */
bool SsdmaRsaInit(void)

{
  bool bVar1;
  
  bVar1 = (*DAT_30034898 & 1) == 0;
  if (bVar1) {
    *DAT_3003487c = *DAT_3003487c | 0x10;
  }
  return !bVar1;
}

/* ----------------------------------------------------------------
 * SetSsdmaRsaMode @ 0x30034650  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: secDataRsa
 * Константы: 0x30034650, 0xFFFFFFE0, 0xFFFFFFF0
 * Данные: DAT_3003489c, DAT_300348a0, DAT_300348a4
 * ---------------------------------------------------------------- */
void SetSsdmaRsaMode(int param_1,int param_2,int param_3)

{
  *DAT_3003489c = (uint)(param_1 == 0);
  *DAT_300348a0 = *DAT_300348a0 & 0xffffffe0 | param_2 + 0x1fU >> 5 & 0x1f;
  *DAT_300348a4 = *DAT_300348a4 & 0xfffffff0 | param_3 + 0x3fU >> 6 & 0xf;
  return;
}

/* ----------------------------------------------------------------
 * RunSsdmaRsa @ 0x300346D4  (примерный размер ~496 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: secDataRsa
 * Константы: 0x300346D4, 0x01000000, 0xFFFFFFFF
 * Данные: DAT_30034898, DAT_300348a8, DAT_300348ac, DAT_300348b0, DAT_300348b4, DAT_300348b8, DAT_300348bc, DAT_300348c0
 * ---------------------------------------------------------------- */
uint RunSsdmaRsa(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0x1000000;
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    *(undefined4 *)(DAT_300348a8 + iVar2 * 4) = *(undefined4 *)(param_2 + iVar2 * 8);
    *(undefined4 *)(DAT_300348a8 + iVar2 * 4) = *(undefined4 *)(param_2 + iVar2 * 8 + 4);
  }
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    *(undefined4 *)(DAT_300348ac + iVar2 * 4) = *(undefined4 *)(param_3 + iVar2 * 8);
    *(undefined4 *)(DAT_300348ac + iVar2 * 4) = *(undefined4 *)(param_3 + iVar2 * 8 + 4);
  }
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    *(undefined4 *)(DAT_300348b0 + iVar2 * 4) = *(undefined4 *)(param_1 + iVar2 * 8 + 4);
    *(undefined4 *)(DAT_300348b0 + iVar2 * 4) = *(undefined4 *)(param_1 + iVar2 * 8 + 8);
  }
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    *(undefined4 *)(DAT_300348b4 + iVar2 * 4) = *(undefined4 *)(param_1 + iVar2 * 8 + 0x84);
    *(undefined4 *)(DAT_300348b4 + iVar2 * 4) = *(undefined4 *)(param_1 + iVar2 * 8 + 0x88);
  }
  *DAT_300348b8 = 1;
  do {
    if ((*DAT_30034898 & 1) == 0) {
      for (iVar1 = 0; iVar1 < 0x10; iVar1 = iVar1 + 1) {
        *(undefined4 *)(param_4 + iVar1 * 8) = *(undefined4 *)(DAT_300348bc + iVar1 * 4);
        *(undefined4 *)(param_4 + iVar1 * 8 + 4) = *(undefined4 *)(DAT_300348bc + iVar1 * 4);
      }
      return *DAT_300348c0 & 1;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * GPIO_Int_handle @ 0x3003546C  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_GPIO_IntStateClear, BSP_GPIO_IntStateGet
 * Константы: 0x3003546C, 0xFFFF7FFF
 * Данные: DAT_300357b4, DAT_300357b8, DAT_300357ec
 * ---------------------------------------------------------------- */
void GPIO_Int_handle(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar6;
  int iVar7;
  uint local_2c [6];
  uint *puVar5;
  
  uVar6 = 1;
  iVar7 = 3;
  puVar3 = local_2c;
  puVar4 = DAT_300357ec;
  do {
    puVar5 = puVar4 + 1;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 2;
    uVar2 = *puVar5;
    iVar7 = iVar7 + -1;
    puVar5 = puVar3 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 2;
    *puVar5 = uVar2;
  } while (iVar7 != 0);
  if (param_1 < 6) {
    BSP_GPIO_IntStateGet(param_1,local_2c,local_2c);
    BSP_GPIO_IntStateClear(param_1,local_2c[0] & 0xffff7fff);
    for (uVar1 = 0; uVar1 < 0x20; uVar1 = uVar1 + 1) {
      if (uVar1 != 0) {
        uVar6 = uVar6 << 1;
      }
      if (((uVar6 & local_2c[0]) != 0) && (*(int *)(DAT_300357b4 + param_1 * 0x80 + uVar1 * 4) != 0)
         ) {
        (**(code **)(DAT_300357b4 + param_1 * 0x80 + uVar1 * 4))
                  (*(undefined4 *)(DAT_300357b8 + param_1 * 0x80 + uVar1 * 4));
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * setGpioMode @ 0x30035548  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30035548
 * ---------------------------------------------------------------- */
void setGpioMode(void)

{
  return;
}

/* ----------------------------------------------------------------
 * mspFuncCallback @ 0x30035E64  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30035E64
 * Данные: DAT_30035f7c
 * ---------------------------------------------------------------- */
undefined4 mspFuncCallback(void)

{
  return *DAT_30035f7c;
}

/* ----------------------------------------------------------------
 * ST_TST1_cb @ 0x30035E78  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x30035E78
 * Данные: DAT_30035fe8
 * ---------------------------------------------------------------- */
void ST_TST1_cb(void)

{
  logMsg(DAT_30035fe8,0,0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * ST_TST_NOLOOP @ 0x30035EB4  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_TRACE, softtimer_create_timer
 * Константы: 0x30035EB4
 * Данные: DAT_30035f90, DAT_30035fd0, DAT_30035fec, DAT_30035ff0
 * ---------------------------------------------------------------- */
void ST_TST_NOLOOP(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  
  iVar1 = softtimer_create_timer
                    (auStack_14,param_1,0,DAT_30035ff0,auStack_10,DAT_30035f90,DAT_30035fec);
  if (iVar1 != 0) {
    BSP_TRACE(4,0x2d,DAT_30035fd0);
  }
  return;
}

/* ----------------------------------------------------------------
 * ST_TST_LOOP @ 0x30035F18  (примерный размер ~224 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_TRACE, softtimer_create_timer
 * Константы: 0x30035F18
 * Данные: DAT_30035f90, DAT_30035fd0, DAT_30035ff0, DAT_30035ff4
 * ---------------------------------------------------------------- */
void ST_TST_LOOP(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  
  iVar1 = softtimer_create_timer
                    (auStack_14,param_1,1,DAT_30035ff0,auStack_10,DAT_30035f90,DAT_30035ff4);
  if (iVar1 != 0) {
    BSP_TRACE(4,0x2d,DAT_30035fd0);
  }
  return;
}

/* ----------------------------------------------------------------
 * sysIMEIGet @ 0x30035FF8  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30035FF8
 * ---------------------------------------------------------------- */
undefined4 sysIMEIGet(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * sysIMEISet @ 0x30036000  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30036000
 * ---------------------------------------------------------------- */
undefined4 sysIMEISet(void)

{
  return 0;
}

