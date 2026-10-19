/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : kernel — ядро VxWorks 6.8: задачи, семафоры, очереди, прерывания, память, планировщик
 * Часть  : 2 (функций: 150, адреса 0x300A8718..0x300AE0AC)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * FUN_300a8718 @ 0x300A8718  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A8718, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300a8718(void)

{
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * intArchConnect @ 0x300A8720  (примерный размер ~160 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: armGicConnect, intConnect, intLibInit
 * Константы: 0xFFFFFFFF, 0x300A8720
 * Данные: DAT_300a8d38, DAT_300a8d3c, DAT_300a8d40
 * ---------------------------------------------------------------- */
undefined4 intArchConnect(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  if (((code *)*DAT_300a8d38 == (code *)0x0) ||
     (iVar1 = (*(code *)*DAT_300a8d38)(param_1,param_2,param_3), iVar1 != 0)) {
    if (*DAT_300a8d3c == 0) {
      return 0xffffffff;
    }
    if ((param_1 < 0) || (DAT_300a8d3c[1] <= param_1)) {
      return 0xffffffff;
    }
    piVar2 = (int *)(*DAT_300a8d3c + param_1 * 8);
    if (param_2 == 0) {
      param_3 = param_1;
      param_2 = DAT_300a8d40;
    }
    *piVar2 = param_2;
    piVar2[1] = param_3;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * intLibInit @ 0x300A87C0  (примерный размер ~180 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: excIntConnect, intArchConnect, memPartAlloc
 * Вызывают: sysHwInit2
 * Константы: 0x300A87C0, 0xFFFFFFFF
 * Данные: DAT_300a8d3c, DAT_300a8d44, DAT_300a8d48, DAT_300a8d4c, DAT_300a8d50
 * ---------------------------------------------------------------- */
undefined4 intLibInit(undefined4 param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_300a8d3c;
  if (*DAT_300a8d3c == 0) {
    iVar2 = memPartAlloc(*DAT_300a8d44,param_2 << 3);
    *piVar1 = iVar2;
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    piVar1[1] = param_2;
    iVar2 = 0;
    if (0 < param_2) {
      do {
        intArchConnect(iVar2,0,0);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_2);
    }
    *DAT_300a8d48 = 0;
    if ((param_3 & 1) == 0) {
      excIntConnect(0x18,DAT_300a8d50);
    }
    else {
      excIntConnect(0x18,DAT_300a8d4c);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * intIntRtnPreempt @ 0x300A8874  (примерный размер ~232 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: intCpuLock, intCpuUnlock
 * Константы: 0x300A8874
 * Данные: DAT_300a8d3c, DAT_300a8d48, DAT_300a8d54, DAT_300a8d58, DAT_300a8d5c, DAT_300a8d60, DAT_300a8d64
 * ---------------------------------------------------------------- */
void intIntRtnPreempt(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int *piVar3;
  int iVar4;
  code *pcVar5;
  int local_10;
  int local_c;
  int local_8;
  
  pcVar5 = (code *)*DAT_300a8d54;
  if (pcVar5 == (code *)0x0) {
    piVar3 = &local_c;
    puVar1 = &stack0x0000000c;
    pcVar5 = (code *)*DAT_300a8d58;
    puVar2 = &stack0x00000014;
  }
  else {
    puVar1 = &stack0x00000010;
    puVar2 = &stack0x0000000c;
    piVar3 = (int *)*DAT_300a8d48;
  }
  iVar4 = (*pcVar5)(piVar3,puVar1 + -0x1c,puVar2 + -0x1c);
  if (iVar4 == -1) {
    *DAT_300a8d5c = *DAT_300a8d5c + 1;
  }
  else {
    intCpuUnlock(0);
    (**(code **)(*DAT_300a8d3c + local_10 * 8))(*(undefined4 *)(*DAT_300a8d3c + local_10 * 8 + 4));
    intCpuLock();
    pcVar5 = (code *)*DAT_300a8d60;
    if (pcVar5 == (code *)0x0) {
      pcVar5 = (code *)*DAT_300a8d64;
      iVar4 = local_c;
      local_c = local_10;
      local_10 = local_8;
    }
    else {
      iVar4 = *DAT_300a8d48;
    }
    (*pcVar5)(iVar4,local_c,local_10);
  }
  return;
}

/* ----------------------------------------------------------------
 * intIntRtnNonPreempt @ 0x300A895C  (примерный размер ~300 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A895C
 * Данные: DAT_300a8d3c, DAT_300a8d48, DAT_300a8d54, DAT_300a8d58, DAT_300a8d5c, DAT_300a8d60, DAT_300a8d64
 * ---------------------------------------------------------------- */
void intIntRtnNonPreempt(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  code *pcVar6;
  int local_18;
  int local_14;
  int iStack_10;
  
  piVar1 = DAT_300a8d54;
  pcVar6 = (code *)*DAT_300a8d54;
  if (pcVar6 == (code *)0x0) {
    piVar2 = &local_14;
    piVar4 = &local_18;
    pcVar6 = (code *)*DAT_300a8d58;
    piVar5 = &iStack_10;
  }
  else {
    piVar4 = &local_14;
    piVar5 = &local_18;
    piVar2 = (int *)*DAT_300a8d48;
  }
  iVar3 = (*pcVar6)(piVar2,piVar4,piVar5);
  if (iVar3 == -1) {
    *DAT_300a8d5c = *DAT_300a8d5c + 1;
  }
  else {
    do {
      (**(code **)(*DAT_300a8d3c + local_18 * 8))(*(undefined4 *)(*DAT_300a8d3c + local_18 * 8 + 4))
      ;
      if ((code *)*DAT_300a8d60 == (code *)0x0) {
        (*(code *)*DAT_300a8d64)(local_14,local_18);
      }
      else {
        (*(code *)*DAT_300a8d60)(*DAT_300a8d48,local_14,local_18);
      }
      pcVar6 = (code *)*piVar1;
      if (pcVar6 == (code *)0x0) {
        piVar2 = &local_14;
        piVar4 = &local_18;
        pcVar6 = (code *)*DAT_300a8d58;
        piVar5 = &iStack_10;
      }
      else {
        piVar4 = &local_14;
        piVar5 = &local_18;
        piVar2 = (int *)*DAT_300a8d48;
      }
      iVar3 = (*pcVar6)(piVar2,piVar4,piVar5);
    } while (iVar3 != -1);
  }
  return;
}

/* ----------------------------------------------------------------
 * intLevelSet @ 0x300A8A88  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A8A88
 * Данные: DAT_300a8d48, DAT_300a8d68, DAT_300a8d6c
 * ---------------------------------------------------------------- */
void intLevelSet(undefined4 param_1)

{
  if ((code *)*DAT_300a8d68 == (code *)0x0) {
    (*(code *)*DAT_300a8d6c)();
  }
  else {
    (*(code *)*DAT_300a8d68)(*DAT_300a8d48,param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * intEnable @ 0x300A8ACC  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 14 | Вызывает: 0
 * Вызывают: BSP_GPIO_Init, BSP_INT_Enable, BSP_PMU_BoardInit, BSP_USRCLK_Enable, BSP_WDT_Enable, FUN_30009f84, HI6451_ist, SD_MMC_Host_Init, WDT_APPInit, os_interrupt_setup
 *           ...
 * Константы: 0x300A8ACC
 * Данные: DAT_300a8d48, DAT_300a8d70, DAT_300a8d74
 * ---------------------------------------------------------------- */
void intEnable(undefined4 param_1)

{
  if ((code *)*DAT_300a8d70 == (code *)0x0) {
    (*(code *)*DAT_300a8d74)();
  }
  else {
    (*(code *)*DAT_300a8d70)(*DAT_300a8d48,param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * intDisable @ 0x300A8B10  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 10 | Вызывает: 0
 * Вызывают: BSP_INT_Disable, BSP_OM_SoftReboot, BSP_WDT_reboot_direct, HI6451_isr, SD_MMC_Host_Exit, WDT_APPIntHandler, WDT_IntHandler, os_interrupt_setup, os_interrupt_teardown, sysSerialReset
 * Константы: 0x300A8B10
 * Данные: DAT_300a8d48, DAT_300a8d78, DAT_300a8d7c
 * ---------------------------------------------------------------- */
void intDisable(undefined4 param_1)

{
  if ((code *)*DAT_300a8d78 == (code *)0x0) {
    (*(code *)*DAT_300a8d7c)();
  }
  else {
    (*(code *)*DAT_300a8d78)(*DAT_300a8d48,param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * intArchDisconnect @ 0x300A8B54  (примерный размер ~112 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: armGicDisconnect, intDisconnect
 * Константы: 0x300A8B54, 0xFFFFFFFF
 * Данные: DAT_300a8d3c, DAT_300a8d40
 * ---------------------------------------------------------------- */
undefined4 intArchDisconnect(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  
  if ((((*DAT_300a8d3c == 0) || (param_1 < 0)) || (DAT_300a8d3c[1] <= param_1)) ||
     ((piVar2 = (int *)(*DAT_300a8d3c + param_1 * 8), *piVar2 != param_2 || (piVar2[1] != param_3)))
     ) {
    uVar1 = 0xffffffff;
  }
  else {
    *piVar2 = DAT_300a8d40;
    piVar2[1] = param_1;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * intLockLevelSet @ 0x300A8BC4  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: kernelInit
 * Константы: 0x300A8BC4
 * Данные: DAT_300a8d80
 * ---------------------------------------------------------------- */
void intLockLevelSet(undefined4 param_1)

{
  *DAT_300a8d80 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * intLockLevelGet @ 0x300A8BD0  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A8BD0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 intLockLevelGet(void)

{
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * intVecBaseGet @ 0x300A8BD8  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A8BD8
 * ---------------------------------------------------------------- */
undefined4 intVecBaseGet(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * intVecTableWriteProtect @ 0x300A8BE0  (примерный размер ~164 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: __udiv32, errnoSet
 * Константы: 0xFFFFFFFF, 0x300A8BE0
 * Данные: DAT_300a8d84, DAT_300a8d88
 * ---------------------------------------------------------------- */
undefined4 intVecTableWriteProtect(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_300a8d84;
  if (*DAT_300a8d84 == 0) {
    errnoSet(DAT_300a8d88);
    uVar2 = 0xffffffff;
  }
  else {
    if ((code *)DAT_300a8d84[8] == (code *)0x0) {
      iVar4 = -1;
    }
    else {
      iVar4 = (*(code *)DAT_300a8d84[8])();
    }
    iVar3 = __udiv32(0,iVar4);
    if ((code *)piVar1[5] == (code *)0x0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = (*(code *)piVar1[5])(0,iVar4 * iVar3,iVar4,0x3f,5);
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300a8c84 @ 0x300A8C84  (примерный размер ~112 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A8C84
 * Данные: DAT_300a8d8c, DAT_300a8d90, DAT_300a8d94
 * ---------------------------------------------------------------- */
void FUN_300a8c84(undefined4 param_1)

{
  if ((code *)*DAT_300a8d8c == (code *)0x0) {
    if ((code *)*DAT_300a8d90 != (code *)0x0) {
      (*(code *)*DAT_300a8d90)(DAT_300a8d94,param_1,0,0,0,0,0);
    }
  }
  else {
    (*(code *)*DAT_300a8d8c)(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * intUninitVecSet @ 0x300A8CF4  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A8CF4
 * Данные: DAT_300a8d8c
 * ---------------------------------------------------------------- */
void intUninitVecSet(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  *DAT_300a8d8c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * intVecBaseSet @ 0x300A8D08  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: sysStart
 * Константы: 0x300A8D08
 * ---------------------------------------------------------------- */
void intVecBaseSet(void)

{
  return;
}

/* ----------------------------------------------------------------
 * intRegsLock @ 0x300A8D0C  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A8D0C
 * ---------------------------------------------------------------- */
uint intRegsLock(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x40);
  *(uint *)(param_1 + 0x40) = uVar1 | 0x80;
  return uVar1;
}

/* ----------------------------------------------------------------
 * intRegsUnlock @ 0x300A8D20  (примерный размер ~132 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A8D20, 0xFFFFFF7F
 * ---------------------------------------------------------------- */
void intRegsUnlock(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffff7f | param_2 & 0x80;
  return;
}

/* ----------------------------------------------------------------
 * excOsmInit @ 0x300A900C  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A900C, 0xFFFFFFFF
 * Данные: DAT_300a9044
 * ---------------------------------------------------------------- */
undefined4 excOsmInit(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    *DAT_300a9044 = (param_1 + param_2) - 1U & ~(param_2 - 1U);
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskRegsInit @ 0x300A9048  (примерный размер ~120 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: bzero
 * Вызывают: taskInitialize, taskReset
 * Константы: 0x300A9048
 * Данные: DAT_300a91a8, DAT_300a91ac
 * ---------------------------------------------------------------- */
void taskRegsInit(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x94);
  bzero((void *)(param_1 + 0x1d0),0x48);
  *(int *)(param_1 + 0x204) = param_2 + -0x28;
  *(undefined4 *)(param_1 + 0x210) = 0x13;
  if ((code *)*DAT_300a91a8 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)*DAT_300a91a8)(uVar1);
  }
  *(undefined4 *)(param_1 + 0x214) = uVar1;
  *(undefined4 *)(param_1 + 0x20c) = DAT_300a91ac;
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  return;
}

/* ----------------------------------------------------------------
 * taskArgsSet @ 0x300A90C0  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: taskInitialize, taskReset
 * Константы: 0x300A90C0
 * ---------------------------------------------------------------- */
void taskArgsSet(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)(param_2 + -0x28);
  puVar3 = (undefined4 *)(param_3 + 0xc);
  iVar4 = 6;
  do {
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + -1;
    *puVar1 = *puVar3;
    puVar1 = puVar1 + 1;
  } while (iVar4 != 0);
  puVar3 = (undefined4 *)(param_1 + 0x1cc);
  puVar2 = (undefined4 *)(param_3 + -4);
  iVar4 = 4;
  do {
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    *puVar3 = *puVar2;
    iVar4 = iVar4 + -1;
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
  } while (iVar4 != 0);
  return;
}

/* ----------------------------------------------------------------
 * taskRtnValueSet @ 0x300A9120  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 6 | Вызывает: 0
 * Вызывают: FUN_300e5490, eventTerminate, windPendQFlush, windPendQTerminate, windTickAnnounce, windUndelay
 * Константы: 0x300A9120
 * ---------------------------------------------------------------- */
void taskRtnValueSet(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1d0) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * taskArgsGet @ 0x300A9128  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: taskReset, taskRestart
 * Константы: 0x300A9128
 * ---------------------------------------------------------------- */
void taskArgsGet(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(param_3 + 0xc);
  iVar3 = 6;
  puVar4 = (undefined4 *)(param_2 + -0x28);
  do {
    puVar2 = puVar4 + 1;
    iVar3 = iVar3 + -1;
    puVar1 = puVar1 + 1;
    *puVar1 = *puVar4;
    puVar4 = puVar2;
  } while (iVar3 != 0);
  puVar4 = (undefined4 *)(param_3 + -4);
  iVar3 = 4;
  do {
    iVar3 = iVar3 + -1;
    puVar4 = puVar4 + 1;
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
  } while (iVar3 != 0);
  return;
}

/* ----------------------------------------------------------------
 * vxTaskEntryFatalInject @ 0x300A9168  (примерный размер ~80 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: edrErrorInjectStub, edrKernelFatalPolicyHandler
 * Вызывают: vxTaskEntry
 * Константы: 0x300A9168
 * Данные: DAT_300a91b0, DAT_300a91b4
 * ---------------------------------------------------------------- */
void vxTaskEntryFatalInject(void)

{
  edrErrorInjectStub(0x11,DAT_300a91b4,0x134,0,0,0,DAT_300a91b0);
  edrKernelFatalPolicyHandler(0);
  return;
}

/* ----------------------------------------------------------------
 * vxTas @ 0x300A9628  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A9628
 * ---------------------------------------------------------------- */
uint vxTas(uint *param_1)

{
  bool bVar1;
  uint uVar2;
  
  do {
    uVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = 1;
  return uVar2 & 1 ^ 1;
}

/* ----------------------------------------------------------------
 * vxTaskEntry @ 0x300A9648  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: vxTaskEntryFatalInject
 * Константы: 0x300A9648
 * Данные: DAT_300a9684, DAT_300a9688
 * ---------------------------------------------------------------- */
void vxTaskEntry(void)

{
  (**(code **)(*DAT_300a9684 + 0xc0))();
  if ((code *)*DAT_300a9688 != (code *)0x0) {
    (*(code *)*DAT_300a9688)();
  }
  do {
    vxTaskEntryFatalInject();
  } while( true );
}

/* ----------------------------------------------------------------
 * mmuReadId @ 0x300A967C  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A967C
 * ---------------------------------------------------------------- */
undefined4 mmuReadId(void)

{
  undefined4 uVar1;
  
  uVar1 = coproc_movefrom_Main_ID();
  return uVar1;
}

/* ----------------------------------------------------------------
 * vxCpuIndexGet @ 0x300A9788  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_301158ec
 * Константы: 0x300A9788
 * ---------------------------------------------------------------- */
undefined4 vxCpuIndexGet(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * vxArchPowerDownSet @ 0x300A9790  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A9790
 * Данные: DAT_300a979c
 * ---------------------------------------------------------------- */
void vxArchPowerDownSet(undefined4 param_1)

{
  *DAT_300a979c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * vxMemProbeSup @ 0x300A97A0  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: vxMemProbeErrorRtn
 * Вызывают: vxMemCommonProbe
 * Константы: 0x300A97A0
 * ---------------------------------------------------------------- */
undefined4 vxMemProbeSup(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    *(undefined1 *)param_3 = *(undefined1 *)param_2;
  }
  else if (param_1 == 2) {
    *(undefined2 *)param_3 = *(undefined2 *)param_2;
  }
  else {
    if (param_1 != 4) {
      uVar1 = vxMemProbeErrorRtn();
      return uVar1;
    }
    *param_3 = *param_2;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * vxMemProbeByteRead @ 0x300A97C0  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A97C0
 * ---------------------------------------------------------------- */
undefined4
vxMemProbeByteRead(undefined4 param_1,undefined1 *param_2,undefined1 *param_3,undefined4 param_4)

{
  *param_3 = *param_2;
  return param_4;
}

/* ----------------------------------------------------------------
 * vxMemProbeByteWrite @ 0x300A97C4  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A97C4
 * ---------------------------------------------------------------- */
undefined4
vxMemProbeByteWrite(undefined4 param_1,undefined1 param_2,undefined1 *param_3,undefined4 param_4)

{
  *param_3 = param_2;
  return param_4;
}

/* ----------------------------------------------------------------
 * vxMemProbeWordRead @ 0x300A97CC  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A97CC
 * ---------------------------------------------------------------- */
undefined4
vxMemProbeWordRead(undefined4 param_1,undefined2 *param_2,undefined2 *param_3,undefined4 param_4)

{
  *param_3 = *param_2;
  return param_4;
}

/* ----------------------------------------------------------------
 * vxMemProbeWordWrite @ 0x300A97D0  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A97D0
 * ---------------------------------------------------------------- */
undefined4
vxMemProbeWordWrite(undefined4 param_1,undefined2 param_2,undefined2 *param_3,undefined4 param_4)

{
  *param_3 = param_2;
  return param_4;
}

/* ----------------------------------------------------------------
 * vxMemProbeLongRead @ 0x300A97D8  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A97D8
 * ---------------------------------------------------------------- */
undefined4
vxMemProbeLongRead(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  *param_3 = *param_2;
  return param_4;
}

/* ----------------------------------------------------------------
 * vxMemProbeLongWrite @ 0x300A97DC  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A97DC
 * ---------------------------------------------------------------- */
undefined4
vxMemProbeLongWrite(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  *param_3 = param_2;
  return param_4;
}

/* ----------------------------------------------------------------
 * vxMemProbeErrorRtn @ 0x300A97E4  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: vxMemProbeSup
 * Константы: 0x300A97E4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 vxMemProbeErrorRtn(void)

{
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * vxMemArchProbeInit @ 0x300A97F0  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: vxMemProbeInit
 * Константы: 0x300A97F0
 * Данные: DAT_300a9910, DAT_300a9914, DAT_300a9918
 * ---------------------------------------------------------------- */
undefined4 vxMemArchProbeInit(void)

{
  *DAT_300a9914 = *DAT_300a9910;
  *DAT_300a9910 = DAT_300a9918;
  return 0;
}

/* ----------------------------------------------------------------
 * vxMemArchProbe @ 0x300A9814  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: vxMemCommonProbe
 * Константы: 0xFFFFFFFF, 0x300A9814
 * ---------------------------------------------------------------- */
undefined4 vxMemArchProbe(uint param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  
  if ((param_3 != 1) && (param_3 != 2)) {
    if (param_3 != 4) {
      return 0xffffffff;
    }
    if (((param_1 & 3) != 0) || ((param_4 & 3) != 0)) {
      return 0xffffffff;
    }
  }
  uVar1 = vxMemCommonProbe(param_1,param_2,param_3);
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300a9868 @ 0x300A9868  (примерный размер ~208 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A9868
 * Данные: DAT_300a9914, DAT_300a991c, DAT_300a9920, DAT_300a9924, DAT_300a9928, DAT_300a992c, DAT_300a9930, DAT_300a9934
 * ---------------------------------------------------------------- */
undefined4 FUN_300a9868(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((param_1 == 0x10) || (param_1 == 4)) &&
     (((iVar2 = *(int *)(param_3 + 0x3c), DAT_300a991c == iVar2 ||
       (((DAT_300a9920 == iVar2 || (DAT_300a9924 == iVar2)) || (DAT_300a9928 == iVar2)))) ||
      (((DAT_300a9928 == iVar2 || (DAT_300a992c == iVar2)) || (DAT_300a9930 == iVar2)))))) {
    uVar1 = 1;
    *param_2 = DAT_300a9934;
  }
  else if ((code *)*DAT_300a9914 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)*DAT_300a9914)();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * wdbDbgArchInit @ 0x300A9938  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: vxdbgClntRegister
 * Константы: 0x300A9938
 * Данные: DAT_300a99d0, DAT_300a99d4, DAT_300a99d8
 * ---------------------------------------------------------------- */
void wdbDbgArchInit(void)

{
  int *piVar1;
  
  piVar1 = DAT_300a99d0;
  if (*DAT_300a99d0 == 0) {
    *DAT_300a99d8 = DAT_300a99d4;
    *piVar1 = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a9968 @ 0x300A9968  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: wdbDbgTrap
 * Константы: 0x300A9968
 * ---------------------------------------------------------------- */
void FUN_300a9968(undefined4 *param_1,undefined4 param_2)

{
  wdbDbgTrap(*param_1,param_2,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * wdbDbgTraceModeSet @ 0x300A998C  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 0
 * Вызывают: FUN_300c7bac, FUN_300c7cbc, FUN_300c7f5c, FUN_300c8154
 * Константы: 0x300A998C
 * ---------------------------------------------------------------- */
uint wdbDbgTraceModeSet(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x40);
  *(uint *)(param_1 + 0x40) = uVar1 | 0x80;
  return uVar1;
}

/* ----------------------------------------------------------------
 * wdbDbgTraceModeClear @ 0x300A9990  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300c7cbc, FUN_300c7fec, FUN_300c8154
 * Константы: 0x300A9990, 0xFFFFFF7F
 * ---------------------------------------------------------------- */
void wdbDbgTraceModeClear(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffff7f | param_2 & 0x80;
  return;
}

/* ----------------------------------------------------------------
 * wdbDbgGetNpc @ 0x300A9994  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 1
 * Вызывает: armGetNpc
 * Вызывают: FUN_300c7bac, FUN_300c7cbc, FUN_300c7f5c, FUN_300c8154
 * Константы: 0x300A9994
 * ---------------------------------------------------------------- */
void wdbDbgGetNpc(int param_1)

{
  armGetNpc(**(undefined4 **)(param_1 + 0x3c),param_1);
  return;
}

/* ----------------------------------------------------------------
 * wdbDbgSysCallCheck @ 0x300A99AC  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: vxdbgTaskStep
 * Константы: 0x300A99AC
 * Данные: DAT_300a99dc
 * ---------------------------------------------------------------- */
bool wdbDbgSysCallCheck(int param_1)

{
  return **(int **)(param_1 + 0x3c) == DAT_300a99dc;
}

/* ----------------------------------------------------------------
 * wdbDbgAddrCheck @ 0x300A99C8  (примерный размер ~252 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300c898c
 * Константы: 0x300A99C8
 * ---------------------------------------------------------------- */
undefined4 wdbDbgAddrCheck(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * cacheArchIntLock @ 0x300AA80C  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300ac2b4, FUN_300ad138
 * Константы: 0x300AA80C
 * ---------------------------------------------------------------- */
undefined4 cacheArchIntLock(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch7IIsOn @ 0x300AA828  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AA828
 * Данные: DAT_300aaff4
 * ---------------------------------------------------------------- */
uint cacheAimArch7IIsOn(void)

{
  uint uVar1;
  
  uVar1 = (*(code *)*DAT_300aaff4)();
  return uVar1 & 0x1000;
}

/* ----------------------------------------------------------------
 * cacheAimArch7DIsOn @ 0x300AA844  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AA844
 * Данные: DAT_300aaff8
 * ---------------------------------------------------------------- */
uint cacheAimArch7DIsOn(void)

{
  return *DAT_300aaff8 >> 2 & 1;
}

/* ----------------------------------------------------------------
 * cacheArchL2CacheIsOn @ 0x300AA858  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AA858
 * Данные: DAT_300aaffc
 * ---------------------------------------------------------------- */
undefined4 cacheArchL2CacheIsOn(void)

{
  return *DAT_300aaffc;
}

/* ----------------------------------------------------------------
 * cacheArchL2CacheEnable @ 0x300AA864  (примерный размер ~148 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300ad138, cacheAimArch7DEnable, cacheAimArch7IEnable
 * Константы: 0x300AA864, 0xFFFFFFFF
 * Данные: DAT_300aaff4, DAT_300aaff8, DAT_300aaffc, DAT_300ab000, DAT_300ab004
 * ---------------------------------------------------------------- */
void cacheArchL2CacheEnable(void)

{
  uint uVar1;
  
  uVar1 = (*(code *)*DAT_300aaff4)();
  if ((((uVar1 & 0x1000) != 0) && ((*DAT_300aaff8 & 4) != 0)) && (*DAT_300aaffc == 0)) {
    if ((code *)*DAT_300ab000 != (code *)0x0) {
      (*(code *)*DAT_300ab000)(1,0,0xffffffff);
    }
    if ((code *)*DAT_300ab004 != (code *)0x0) {
      (*(code *)*DAT_300ab004)(1);
      *DAT_300aaffc = 1;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * cacheAimArch7IEnable @ 0x300AA8F8  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: cacheAimArch6IInvalidateAll, cacheArchL2CacheEnable
 * Константы: 0x300AA8F8
 * Данные: DAT_300aaff4, DAT_300ab008
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch7IEnable(void)

{
  uint uVar1;
  
  uVar1 = (*(code *)*DAT_300aaff4)();
  if ((uVar1 & 0x1000) == 0) {
    cacheAimArch6IInvalidateAll();
    (*(code *)*DAT_300ab008)(0x1000,0x1000);
    cacheArchL2CacheEnable();
  }
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch7MmuIsOn @ 0x300AA944  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AA944
 * Данные: DAT_300aaff4
 * ---------------------------------------------------------------- */
uint cacheAimArch7MmuIsOn(void)

{
  uint uVar1;
  
  uVar1 = (*(code *)*DAT_300aaff4)();
  return uVar1 & 1;
}

/* ----------------------------------------------------------------
 * cacheAimArch7DEnable @ 0x300AA960  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: cacheAimArch7DInvalidateAll, cacheArchL2CacheEnable, cacheFuncsSet, intIFLock, intIFUnlock
 * Константы: 0x300AA960
 * Данные: DAT_300aaff4, DAT_300aaff8, DAT_300ab008, DAT_300ab00c
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch7DEnable(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((*DAT_300aaff8 & 4) == 0) {
    cacheAimArch7DInvalidateAll();
    *DAT_300aaff8 = 4;
    uVar1 = intIFLock();
    uVar2 = (*(code *)*DAT_300aaff4)();
    if ((uVar2 & 1) != 0) {
      *DAT_300ab00c = 1;
      cacheFuncsSet();
      (*(code *)*DAT_300ab008)(4,4);
      cacheArchL2CacheEnable();
    }
    intIFUnlock(uVar1);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * cacheArchL2CacheDisable @ 0x300AA9E8  (примерный размер ~112 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300ad138, cacheAimArch7DDisable, cacheAimArch7IDisable
 * Константы: 0x300AA9E8, 0xFFFFFFFF
 * Данные: DAT_300aaffc, DAT_300ab010, DAT_300ab014
 * ---------------------------------------------------------------- */
void cacheArchL2CacheDisable(void)

{
  int *piVar1;
  
  piVar1 = DAT_300aaffc;
  if (*DAT_300aaffc != 0) {
    if ((code *)*DAT_300ab010 != (code *)0x0) {
      (*(code *)*DAT_300ab010)(1,0,0xffffffff);
    }
    if ((code *)*DAT_300ab014 != (code *)0x0) {
      (*(code *)*DAT_300ab014)(1);
      *piVar1 = 0;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * cacheAimArch7IDisable @ 0x300AAA58  (примерный размер ~80 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: cacheArchL2CacheDisable, intIFLock, intIFUnlock
 * Константы: 0x300AAA58
 * Данные: DAT_300aaff4, DAT_300ab018
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch7IDisable(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (*(code *)*DAT_300aaff4)();
  if ((uVar1 & 0x1000) != 0) {
    uVar2 = intIFLock();
    (*(code *)*DAT_300ab018)();
    cacheArchL2CacheDisable();
    intIFUnlock(uVar2);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch7DDisable @ 0x300AAAA8  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: cacheArchL2CacheDisable, cacheFuncsSet, intIFLock, intIFUnlock
 * Константы: 0x300AAAA8, 0xFFFFFFFB
 * Данные: DAT_300aaff8, DAT_300ab00c, DAT_300ab01c
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch7DDisable(void)

{
  uint *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_300aaff8;
  if ((*DAT_300aaff8 & 4) != 0) {
    uVar2 = intIFLock();
    *puVar1 = *puVar1 & 0xfffffffb;
    (*(code *)*DAT_300ab01c)();
    *DAT_300ab00c = 0;
    cacheFuncsSet();
    cacheArchL2CacheDisable();
    intIFUnlock(uVar2);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch7TextUpdate @ 0x300AAB0C  (примерный размер ~184 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: cacheAimArch6IInvalidate, cacheAimArch7DFlushPoU
 * Константы: 0xFFFFFFFF, 0x300AAB0C
 * Данные: DAT_300aaffc, DAT_300ab000, DAT_300ab020
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch7TextUpdate(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  param_2 = param_1 + param_2;
  if (*DAT_300aaffc == 0) {
    iVar1 = cacheAimArch7DFlushPoU(param_1,param_2,param_4);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
  }
  else {
    iVar1 = cacheAimArch7DFlushPoU(param_1,param_2,param_4);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    if ((code *)*DAT_300ab020 != (code *)0x0) {
      (*(code *)*DAT_300ab020)(1,param_1,param_2);
    }
    if ((code *)*DAT_300ab000 != (code *)0x0) {
      (*(code *)*DAT_300ab000)(0,param_1,param_2);
    }
  }
  uVar2 = cacheAimArch6IInvalidate(param_1,param_2,param_3);
  return uVar2;
}

/* ----------------------------------------------------------------
 * cacheAimArch7DmaMalloc @ 0x300AABC4  (примерный размер ~220 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: free, malloc, memPartAlignedAlloc
 * Константы: 0x300AABC4, 0xFFFFFFFF
 * Данные: DAT_300aaff8, DAT_300ab024, DAT_300ab028, DAT_300ab02c
 * ---------------------------------------------------------------- */
void * cacheAimArch7DmaMalloc(size_t param_1)

{
  void *__ptr;
  int iVar1;
  code *pcVar2;
  bool bVar3;
  
  iVar1 = DAT_300ab024;
  if ((*DAT_300aaff8 & 4) == 0) {
    __ptr = malloc(param_1);
  }
  else {
    pcVar2 = *(code **)(DAT_300ab024 + 0x20);
    bVar3 = pcVar2 == (code *)0x0;
    if (!bVar3) {
      pcVar2 = (code *)(*pcVar2)();
      bVar3 = pcVar2 == (code *)0xffffffff;
    }
    if (bVar3) {
      __ptr = (void *)0x0;
    }
    else {
      __ptr = (void *)memPartAlignedAlloc(*DAT_300ab028,
                                          (uint)(pcVar2 + (param_1 - 1)) & ~(uint)(pcVar2 + -1),
                                          pcVar2);
      if (__ptr == (void *)0x0) {
        __ptr = (void *)0x0;
      }
      else if ((*(code **)(iVar1 + 0x14) == (code *)0x0) ||
              (iVar1 = (**(code **)(iVar1 + 0x14))
                                 (0,__ptr,(uint)(pcVar2 + (param_1 - 1)) & ~(uint)(pcVar2 + -1),
                                  DAT_300ab02c,0x10c0), iVar1 != 0)) {
        free(__ptr);
        __ptr = (void *)0x0;
      }
    }
  }
  return __ptr;
}

/* ----------------------------------------------------------------
 * cacheAimArch7DmaFree @ 0x300AACA0  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: free, memBlockSizeGet
 * Константы: 0x300AACA0, 0xFFFFFFFF
 * Данные: DAT_300aaff8, DAT_300ab024
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch7DmaFree(void *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_300ab024;
  uVar2 = 0;
  if (((*DAT_300aaff8 & 4) != 0) && ((*DAT_300ab024 != 0 || (DAT_300ab024[1] != 0)))) {
    if (DAT_300ab024[5] == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = memBlockSizeGet(param_1);
      uVar2 = (*(code *)piVar1[5])(0,param_1,uVar2,0xf80,0x800);
    }
  }
  free(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * cacheAimArch7IProbe @ 0x300AAD30  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AAD30
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch7IProbe(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch7DProbe @ 0x300AAD38  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AAD38
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch7DProbe(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * cacheArchIInvalidate @ 0x300AAD40  (примерный размер ~104 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cacheAimArch6IInvalidate
 * Константы: 0x300AAD40
 * Данные: DAT_300aaffc, DAT_300ab000
 * ---------------------------------------------------------------- */
undefined4 cacheArchIInvalidate(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*DAT_300aaffc != 0) && ((code *)*DAT_300ab000 != (code *)0x0)) {
    (*(code *)*DAT_300ab000)(0,param_1,param_2);
  }
  cacheAimArch6IInvalidate(param_1,param_2,param_3);
  return 0;
}

/* ----------------------------------------------------------------
 * cacheArchIInvalidateAll @ 0x300AADA8  (примерный размер ~72 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cacheAimArch6IInvalidateAll
 * Константы: 0x300AADA8, 0xFFFFFFFF
 * Данные: DAT_300aaffc, DAT_300ab010
 * ---------------------------------------------------------------- */
undefined4 cacheArchIInvalidateAll(void)

{
  if ((*DAT_300aaffc != 0) && ((code *)*DAT_300ab010 != (code *)0x0)) {
    (*(code *)*DAT_300ab010)(0,0,0xffffffff);
  }
  cacheAimArch6IInvalidateAll();
  return 0;
}

/* ----------------------------------------------------------------
 * cacheArchDFlush @ 0x300AADF0  (примерный размер ~88 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cacheAimArch6DFlush
 * Константы: 0x300AADF0
 * Данные: DAT_300aaffc, DAT_300ab020
 * ---------------------------------------------------------------- */
undefined4 cacheArchDFlush(undefined4 param_1,undefined4 param_2)

{
  cacheAimArch6DFlush();
  if ((*DAT_300aaffc != 0) && ((code *)*DAT_300ab020 != (code *)0x0)) {
    (*(code *)*DAT_300ab020)(1,param_1,param_2);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * cacheArchDFlushAll @ 0x300AAE48  (примерный размер ~72 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cacheAimArch7DFlushAll
 * Константы: 0x300AAE48, 0xFFFFFFFF
 * Данные: DAT_300aaffc, DAT_300ab020
 * ---------------------------------------------------------------- */
undefined4 cacheArchDFlushAll(void)

{
  cacheAimArch7DFlushAll();
  if ((*DAT_300aaffc != 0) && ((code *)*DAT_300ab020 != (code *)0x0)) {
    (*(code *)*DAT_300ab020)(1,0,0xffffffff);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * cacheArchDInvalidate @ 0x300AAE90  (примерный размер ~104 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cacheAimArch6DInvalidate
 * Константы: 0x300AAE90
 * Данные: DAT_300aaffc, DAT_300ab000
 * ---------------------------------------------------------------- */
undefined4 cacheArchDInvalidate(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*DAT_300aaffc != 0) && ((code *)*DAT_300ab000 != (code *)0x0)) {
    (*(code *)*DAT_300ab000)(1,param_1,param_2);
  }
  cacheAimArch6DInvalidate(param_1,param_2,param_3);
  return 0;
}

/* ----------------------------------------------------------------
 * cacheArchDInvalidateAll @ 0x300AAEF8  (примерный размер ~72 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cacheAimArch7DInvalidateAll
 * Константы: 0x300AAEF8, 0xFFFFFFFF
 * Данные: DAT_300aaffc, DAT_300ab000
 * ---------------------------------------------------------------- */
undefined4 cacheArchDInvalidateAll(void)

{
  if ((*DAT_300aaffc != 0) && ((code *)*DAT_300ab000 != (code *)0x0)) {
    (*(code *)*DAT_300ab000)(1,0,0xffffffff);
  }
  cacheAimArch7DInvalidateAll();
  return 0;
}

/* ----------------------------------------------------------------
 * cacheArchDClear @ 0x300AAF40  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: cacheAimArch6DFlush, cacheAimArch6DInvalidate
 * Константы: 0x300AAF40
 * Данные: DAT_300aaffc, DAT_300ab010
 * ---------------------------------------------------------------- */
undefined4 cacheArchDClear(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  cacheAimArch6DFlush();
  if ((*DAT_300aaffc != 0) && ((code *)*DAT_300ab010 != (code *)0x0)) {
    (*(code *)*DAT_300ab010)(1,param_1,param_2);
  }
  cacheAimArch6DInvalidate(param_1,param_2,param_3);
  return 0;
}

/* ----------------------------------------------------------------
 * cacheArchDClearAll @ 0x300AAFAC  (примерный размер ~132 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cacheAimArch7DClearAll
 * Константы: 0x300AAFAC, 0xFFFFFFFF
 * Данные: DAT_300aaffc, DAT_300ab010
 * ---------------------------------------------------------------- */
undefined4 cacheArchDClearAll(void)

{
  cacheAimArch7DClearAll();
  if ((*DAT_300aaffc != 0) && ((code *)*DAT_300ab010 != (code *)0x0)) {
    (*(code *)*DAT_300ab010)(1,0,0xffffffff);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch7DClearAll @ 0x300AB030  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: cacheArchDClearAll
 * Константы: 0x300AB030, 0x07000000
 * Данные: DAT_300ab0b8, DAT_300ab0bc
 * ---------------------------------------------------------------- */
void cacheAimArch7DClearAll(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined4 in_cr14;
  
  uVar2 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
  uVar5 = uVar2 & 0x7000000;
  if (uVar5 != 0) {
    uVar8 = 0;
    while( true ) {
      if (1 < (uVar2 & 7)) {
        coprocessor_moveto(0xf,2,0,uVar8,in_cr0,in_cr0);
        coproc_moveto_Flush_Prefetch_Buffer(uVar8);
        uVar3 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
        uVar6 = DAT_300ab0b8 & uVar3 >> 3;
        uVar4 = uVar6;
        uVar7 = DAT_300ab0bc & uVar3 >> 0xd;
        do {
          do {
            coprocessor_moveto(0xf,0,2,uVar8 | uVar4 << LZCOUNT(uVar6) | uVar7 << (uVar3 & 7) + 4,
                               in_cr7,in_cr14);
            bVar1 = 0 < (int)uVar4;
            uVar4 = uVar4 - 1;
          } while (bVar1);
          bVar1 = 0 < (int)uVar7;
          uVar4 = uVar6;
          uVar7 = uVar7 - 1;
        } while (bVar1);
      }
      uVar8 = uVar8 + 2;
      if ((int)(uVar5 >> 0x17) <= (int)uVar8) break;
      uVar2 = uVar2 >> 3;
    }
  }
  DataSynchronizationBarrier(0xf);
  return;
}

/* ----------------------------------------------------------------
 * cacheAimArch7DFlushAll @ 0x300AB0C0  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: cacheArchDFlushAll
 * Константы: 0x300AB0C0, 0x07000000
 * Данные: DAT_300ab148, DAT_300ab14c
 * ---------------------------------------------------------------- */
void cacheAimArch7DFlushAll(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 in_cr0;
  
  uVar2 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
  uVar5 = uVar2 & 0x7000000;
  if (uVar5 != 0) {
    uVar8 = 0;
    while( true ) {
      if (1 < (uVar2 & 7)) {
        coprocessor_moveto(0xf,2,0,uVar8,in_cr0,in_cr0);
        coproc_moveto_Flush_Prefetch_Buffer(uVar8);
        uVar3 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
        uVar6 = DAT_300ab148 & uVar3 >> 3;
        uVar4 = uVar6;
        uVar7 = DAT_300ab14c & uVar3 >> 0xd;
        do {
          do {
            coproc_moveto_Clean_Data_Cache_by_Index
                      (uVar8 | uVar4 << LZCOUNT(uVar6) | uVar7 << (uVar3 & 7) + 4);
            bVar1 = 0 < (int)uVar4;
            uVar4 = uVar4 - 1;
          } while (bVar1);
          bVar1 = 0 < (int)uVar7;
          uVar4 = uVar6;
          uVar7 = uVar7 - 1;
        } while (bVar1);
      }
      uVar8 = uVar8 + 2;
      if ((int)(uVar5 >> 0x17) <= (int)uVar8) break;
      uVar2 = uVar2 >> 3;
    }
  }
  DataSynchronizationBarrier(0xf);
  return;
}

/* ----------------------------------------------------------------
 * cacheAimArch7DFlushPoU @ 0x300AB150  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: cacheAimArch7TextUpdate
 * Константы: 0x300AB150
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch7DFlushPoU(uint param_1,uint param_2,int param_3)

{
  undefined4 in_cr7;
  undefined4 in_cr11;
  
  do {
    coprocessor_moveto(0xf,0,1,param_1,in_cr7,in_cr11);
    param_1 = param_1 + param_3;
  } while (param_1 < param_2);
  coproc_moveto_Data_Synchronization(0);
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch7Identify @ 0x300AB16C  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 0
 * Вызывают: cacheAimCortexA8LibInit, cacheAimCortexA9LibInit, mmuCortexA8TtbrSet, mmuCortexA8TtbrSetAll
 * Константы: 0x300AB16C
 * ---------------------------------------------------------------- */
uint cacheAimArch7Identify(int param_1)

{
  uint uVar1;
  undefined4 in_cr0;
  
  uVar1 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
  return uVar1 >> (param_1 * 3 & 0xffU) & 7;
}

/* ----------------------------------------------------------------
 * cacheAimArch7SizeInfoGet @ 0x300AB188  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: cacheAimCortexA8LibInit, cacheAimCortexA9LibInit
 * Константы: 0x300AB188
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch7SizeInfoGet(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 in_cr0;
  
  coprocessor_moveto(0xf,2,0,param_1 * 2 + param_2,in_cr0,in_cr0);
  coproc_moveto_Flush_Prefetch_Buffer(0);
  uVar1 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheAimArch7DInvalidateAll @ 0x300AB1A4  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: cacheAimArch7DEnable, cacheArchDInvalidateAll
 * Константы: 0x300AB1A4, 0x07000000
 * Данные: DAT_300ab22c, DAT_300ab230
 * ---------------------------------------------------------------- */
void cacheAimArch7DInvalidateAll(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 in_cr0;
  
  uVar2 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
  uVar5 = uVar2 & 0x7000000;
  if (uVar5 != 0) {
    uVar8 = 0;
    while( true ) {
      if (1 < (uVar2 & 7)) {
        coprocessor_moveto(0xf,2,0,uVar8,in_cr0,in_cr0);
        coproc_moveto_Flush_Prefetch_Buffer(uVar8);
        uVar3 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
        uVar6 = DAT_300ab22c & uVar3 >> 3;
        uVar4 = uVar6;
        uVar7 = DAT_300ab230 & uVar3 >> 0xd;
        do {
          do {
            coproc_moveto_Invalidate_Entire_Data_by_Index
                      (uVar8 | uVar4 << LZCOUNT(uVar6) | uVar7 << (uVar3 & 7) + 4);
            bVar1 = 0 < (int)uVar4;
            uVar4 = uVar4 - 1;
          } while (bVar1);
          bVar1 = 0 < (int)uVar7;
          uVar4 = uVar6;
          uVar7 = uVar7 - 1;
        } while (bVar1);
      }
      uVar8 = uVar8 + 2;
      if ((int)(uVar5 >> 0x17) <= (int)uVar8) break;
      uVar2 = uVar2 >> 3;
    }
  }
  DataSynchronizationBarrier(0xf);
  return;
}

/* ----------------------------------------------------------------
 * cacheCortexA8LibInstall @ 0x300AB234  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AB234
 * Данные: DAT_300ab634, DAT_300ab638, DAT_300ab63c, DAT_300ab640, DAT_300ab644
 * ---------------------------------------------------------------- */
void cacheCortexA8LibInstall(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = DAT_300ab634;
  if (*DAT_300ab634 == 0) {
    *DAT_300ab638 = param_1;
    *DAT_300ab63c = param_2;
    *DAT_300ab644 = DAT_300ab640;
    *piVar1 = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * cacheAimCortexA8LibInit @ 0x300AB278  (примерный размер ~1032 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: aimCacheInit, cacheAimArch7Identify, cacheAimArch7SizeInfoGet
 * Константы: 0x80000000, 0x40000000, 0x20000000, 0x10000000, 0x300AB278, 0xFFFFFFFF
 * Данные: DAT_300ab634, DAT_300ab638, DAT_300ab63c, DAT_300ab648, DAT_300ab64c, DAT_300ab650, DAT_300ab654, DAT_300ab658
 * ---------------------------------------------------------------- */
undefined4 cacheAimCortexA8LibInit(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  bool bVar11;
  
  iVar2 = DAT_300ab634;
  bVar11 = (param_1 & 0x10) == 0;
  if (((((bVar11) && (bVar11 = (param_2 & 0x10) == 0, bVar11)) &&
       (bVar11 = (param_1 & 0x20) == 0, bVar11)) &&
      ((bVar11 = (param_2 & 0x20) == 0, bVar11 && (bVar11 = (param_1 & 0x40) == 0, bVar11)))) &&
     ((bVar11 = (param_2 & 0x40) == 0, bVar11 && (bVar11 = (param_1 & 0x80) == 0, bVar11)))) {
    bVar11 = (param_2 & 0x80) == 0;
  }
  if (bVar11) {
    if (*(int *)(DAT_300ab634 + 4) == 0) {
      uVar5 = cacheAimArch7Identify(0);
      puVar3 = DAT_300ab648;
      uVar10 = 0;
      if (*DAT_300ab648 != 0) {
        do {
          if (puVar3[uVar10 * 0x29 + 1] == 0) {
            if ((uVar5 & 1) != 0) {
              puVar3[uVar10 * 0x29 + 2] = param_1;
              uVar6 = cacheAimArch7SizeInfoGet(0,1);
              if ((uVar6 & 0x80000000) != 0) {
                puVar3[uVar10 * 0x29 + 3] = 1;
              }
              if ((uVar6 & 0x40000000) != 0) {
                puVar3[uVar10 * 0x29 + 3] = puVar3[uVar10 * 0x29 + 3] | 2;
              }
              if ((uVar6 & 0x20000000) != 0) {
                puVar3[uVar10 * 0x29 + 3] = puVar3[uVar10 * 0x29 + 3] | 8;
              }
              if ((uVar6 & 0x10000000) != 0) {
                puVar3[uVar10 * 0x29 + 3] = puVar3[uVar10 * 0x29 + 3] | 4;
              }
              uVar1 = 1 << (uVar6 & 7) + 4;
              puVar3[uVar10 * 0x29 + 5] = uVar1;
              puVar3[uVar10 * 0x29 + 6] = uVar1;
              uVar8 = (DAT_300ab64c & uVar6 >> 3) + 1;
              puVar3[uVar10 * 0x29 + 7] = uVar8;
              puVar3[uVar10 * 0x29 + 8] = uVar1;
              uVar6 = (DAT_300ab650 & uVar6 >> 0xd) + 1;
              puVar3[uVar10 * 0x29 + 9] = uVar6;
              puVar3[uVar10 * 0x29 + 10] = uVar1;
              puVar3[uVar10 * 0x29 + 4] = uVar1 * uVar8 * uVar6;
            }
          }
          else if ((puVar3[uVar10 * 0x29 + 1] == 1) && ((uVar5 & 1) != 0)) {
            puVar3[uVar10 * 0x29 + 2] = param_2;
            puVar9 = puVar3 + uVar10 * 0x29 + 0xc;
            uVar6 = cacheAimArch7SizeInfoGet(0,0);
            if ((uVar6 & 0x80000000) != 0) {
              puVar3[uVar10 * 0x29 + 3] = 1;
            }
            if ((uVar6 & 0x40000000) != 0) {
              puVar3[uVar10 * 0x29 + 3] = puVar3[uVar10 * 0x29 + 3] | 2;
            }
            if ((uVar6 & 0x20000000) != 0) {
              puVar3[uVar10 * 0x29 + 3] = puVar3[uVar10 * 0x29 + 3] | 8;
            }
            if ((uVar6 & 0x10000000) != 0) {
              puVar3[uVar10 * 0x29 + 3] = puVar3[uVar10 * 0x29 + 3] | 4;
            }
            uVar1 = 1 << (uVar6 & 7) + 4;
            puVar3[uVar10 * 0x29 + 5] = uVar1;
            puVar3[uVar10 * 0x29 + 6] = uVar1;
            uVar8 = (DAT_300ab64c & uVar6 >> 3) + 1;
            puVar3[uVar10 * 0x29 + 7] = uVar8;
            puVar3[uVar10 * 0x29 + 8] = uVar1;
            uVar6 = (DAT_300ab650 & uVar6 >> 0xd) + 1;
            puVar3[uVar10 * 0x29 + 9] = uVar6;
            puVar3[uVar10 * 0x29 + 10] = uVar1;
            iVar7 = 0xf;
            puVar3[uVar10 * 0x29 + 4] = uVar1 * uVar8 * uVar6;
            do {
              if ((*puVar9 & 0xff) == 8) {
                puVar9[1] = *DAT_300ab63c;
              }
              if ((*puVar9 & 0xff) == 9) {
                puVar9[1] = *DAT_300ab638;
              }
              puVar9 = puVar9 + 2;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < *puVar3);
      }
      *DAT_300ab658 = DAT_300ab654;
      *DAT_300ab660 = DAT_300ab65c;
      iVar7 = cacheAimArch7Identify(1);
      if (iVar7 == 0) {
        puVar9 = puVar3 + 0xc;
        iVar7 = 0xf;
        do {
          if ((*puVar9 & 0xff) == 4) {
            uVar5 = DAT_300ab664;
            if ((*puVar9 & 0x4000) == 0) {
              uVar5 = DAT_300ab668;
            }
            puVar9[1] = uVar5;
          }
          puVar9 = puVar9 + 2;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        puVar9 = puVar3 + 0x35;
        iVar7 = 0xf;
        do {
          if ((*puVar9 & 0xff) == 1) {
            puVar9[1] = DAT_300ab66c;
            break;
          }
          puVar9 = puVar9 + 2;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        *DAT_300ab660 = DAT_300ab670;
      }
      aimCacheInit(puVar3);
      (*(code *)*DAT_300ab658)();
      (*(code *)*DAT_300ab660)();
      *DAT_300ab674 = param_2;
      *DAT_300ab678 = 0;
      *DAT_300ab67c = 0;
      *(undefined4 *)(iVar2 + 4) = 1;
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * cacheCortexA8DClearDisable @ 0x300AB680  (примерный размер ~184 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AB680, 0x07000000, 0xFFFFFFFB, 0xFFFFFFFD
 * Данные: DAT_300ab878, DAT_300ab87c
 * ---------------------------------------------------------------- */
undefined8 cacheCortexA8DClearDisable(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined4 in_cr14;
  
  uVar2 = (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
  uVar4 = uVar2 | 0xc0;
  uVar3 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
  uVar7 = uVar3 & 0x7000000;
  if (uVar7 != 0) {
    uVar10 = 0;
    while( true ) {
      uVar4 = uVar3 & 7;
      if (1 < uVar4) {
        coprocessor_moveto(0xf,2,0,uVar10,in_cr0,in_cr0);
        coproc_moveto_Flush_Prefetch_Buffer(uVar10);
        uVar5 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
        uVar8 = DAT_300ab878 & uVar5 >> 3;
        uVar6 = uVar8;
        uVar9 = DAT_300ab87c & uVar5 >> 0xd;
        do {
          do {
            coprocessor_moveto(0xf,0,2,uVar10 | uVar6 << LZCOUNT(uVar8) | uVar9 << (uVar5 & 7) + 4,
                               in_cr7,in_cr14);
            uVar4 = uVar6 - 1;
            bVar1 = 0 < (int)uVar6;
            uVar6 = uVar4;
          } while (bVar1);
          bVar1 = 0 < (int)uVar9;
          uVar6 = uVar8;
          uVar9 = uVar9 - 1;
        } while (bVar1);
      }
      uVar10 = uVar10 + 2;
      if ((int)(uVar7 >> 0x17) <= (int)uVar10) break;
      uVar3 = uVar3 >> 3;
    }
  }
  DataSynchronizationBarrier(0xf);
  uVar3 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar3 & 0xfffffffb);
  uVar3 = coproc_movefrom_Auxiliary_Control();
  coproc_moveto_Auxiliary_Control(uVar3 & 0xfffffffd);
  return CONCAT44(uVar4,uVar2);
}

/* ----------------------------------------------------------------
 * cacheCortexA8L2CacrGet @ 0x300AB738  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AB738
 * ---------------------------------------------------------------- */
undefined4 cacheCortexA8L2CacrGet(void)

{
  undefined4 uVar1;
  undefined4 in_cr0;
  undefined4 in_cr9;
  
  uVar1 = coprocessor_movefromRt(0xf,1,2,in_cr9,in_cr0);
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheCortexA8L2CacrSet @ 0x300AB740  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AB740, 0xFFFFFFFD
 * ---------------------------------------------------------------- */
void cacheCortexA8L2CacrSet(undefined4 param_1)

{
  uint uVar1;
  undefined4 in_cr0;
  undefined4 in_cr9;
  
  uVar1 = coproc_movefrom_Auxiliary_Control();
  coproc_moveto_Auxiliary_Control(uVar1 & 0xfffffffd);
  coprocessor_moveto(0xf,1,2,param_1,in_cr9,in_cr0);
  coproc_moveto_Auxiliary_Control(uVar1);
  return;
}

/* ----------------------------------------------------------------
 * cacheCortexA8L2Enable @ 0x300AB758  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AB758
 * ---------------------------------------------------------------- */
uint cacheCortexA8L2Enable(void)

{
  uint uVar1;
  
  uVar1 = coproc_movefrom_Auxiliary_Control();
  coproc_moveto_Auxiliary_Control(uVar1 | 2);
  return uVar1 | 2;
}

/* ----------------------------------------------------------------
 * cacheCortexA8L2Disable @ 0x300AB768  (примерный размер ~184 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AB768, 0x07000000, 0xFFFFFFFD
 * Данные: DAT_300ab878, DAT_300ab87c
 * ---------------------------------------------------------------- */
undefined8 cacheCortexA8L2Disable(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char in_CY;
  char in_OV;
  byte in_Q;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined4 in_cr14;
  
  uVar2 = coproc_movefrom_Auxiliary_Control();
  uVar3 = uVar2 & 2;
  if (uVar3 != 0) {
    uVar3 = (uint)(byte)((uVar3 == 0) << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
    uVar2 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
    uVar6 = uVar2 & 0x7000000;
    if (uVar6 != 0) {
      uVar9 = 0;
      while( true ) {
        if (1 < (uVar2 & 7)) {
          coprocessor_moveto(0xf,2,0,uVar9,in_cr0,in_cr0);
          coproc_moveto_Flush_Prefetch_Buffer(uVar9);
          uVar4 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
          uVar7 = DAT_300ab878 & uVar4 >> 3;
          uVar5 = uVar7;
          uVar8 = DAT_300ab87c & uVar4 >> 0xd;
          do {
            do {
              coprocessor_moveto(0xf,0,2,uVar9 | uVar5 << LZCOUNT(uVar7) | uVar8 << (uVar4 & 7) + 4,
                                 in_cr7,in_cr14);
              bVar1 = 0 < (int)uVar5;
              uVar5 = uVar5 - 1;
            } while (bVar1);
            bVar1 = 0 < (int)uVar8;
            uVar5 = uVar7;
            uVar8 = uVar8 - 1;
          } while (bVar1);
        }
        uVar9 = uVar9 + 2;
        if ((int)(uVar6 >> 0x17) <= (int)uVar9) break;
        uVar2 = uVar2 >> 3;
      }
    }
    DataSynchronizationBarrier(0xf);
    uVar2 = coproc_movefrom_Auxiliary_Control();
    uVar2 = uVar2 & 0xfffffffd;
    coproc_moveto_Auxiliary_Control(uVar2);
  }
  return CONCAT44(uVar3,uVar2);
}

/* ----------------------------------------------------------------
 * cacheCortexA8L2ClearAll @ 0x300AB820  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: mmuCortexA8TtbrSet, mmuCortexA8TtbrSetAll
 * Константы: 0x300AB820
 * Данные: DAT_300ab878, DAT_300ab87c
 * ---------------------------------------------------------------- */
/* WARNING: Control flow encountered bad instruction data */

void cacheCortexA8L2ClearAll(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined4 in_cr14;
  
  coprocessor_moveto(0xf,2,0,1,in_cr0,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  uVar2 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
  uVar4 = DAT_300ab878 & uVar2 >> 3;
  uVar3 = uVar4;
  uVar5 = DAT_300ab87c & uVar2 >> 0xd;
  do {
    do {
      coprocessor_moveto(0xf,0,2,uVar3 << LZCOUNT(uVar4) | 1 | uVar5 << (uVar2 & 7) + 4,in_cr7,
                         in_cr14);
      bVar1 = 0 < (int)uVar3;
      uVar3 = uVar3 - 1;
    } while (bVar1);
    bVar1 = 0 < (int)uVar5;
    uVar3 = uVar4;
    uVar5 = uVar5 - 1;
  } while (bVar1);
  DataSynchronizationBarrier(0xf);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ----------------------------------------------------------------
 * cacheCortexA9LibInstall @ 0x300AB880  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: sysHwInit0
 * Константы: 0x300AB880
 * Данные: DAT_300abb24, DAT_300abb28, DAT_300abb2c, DAT_300abb30, DAT_300abb34
 * ---------------------------------------------------------------- */
void cacheCortexA9LibInstall(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = DAT_300abb24;
  if (*DAT_300abb24 == 0) {
    *DAT_300abb28 = param_1;
    *DAT_300abb2c = param_2;
    *DAT_300abb34 = DAT_300abb30;
    *piVar1 = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * cacheAimCortexA9LibInit @ 0x300AB8C4  (примерный размер ~664 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: aimCacheInit, cacheAimArch7Identify, cacheAimArch7SizeInfoGet
 * Константы: 0x80000000, 0x40000000, 0x20000000, 0x10000000, 0x300AB8C4, 0xFFFFFFFF
 * Данные: DAT_300abb24, DAT_300abb28, DAT_300abb2c, DAT_300abb38, DAT_300abb3c, DAT_300abb40, DAT_300abb44, DAT_300abb48
 * ---------------------------------------------------------------- */
undefined4 cacheAimCortexA9LibInit(uint param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  
  iVar1 = DAT_300abb24;
  if (*(int *)(DAT_300abb24 + 4) == 0) {
    uVar4 = cacheAimArch7Identify(0);
    puVar2 = DAT_300abb38;
    uVar7 = 0;
    if (*DAT_300abb38 != 0) {
      do {
        if (puVar2[uVar7 * 0x29 + 1] == 0) {
          if ((uVar4 & 1) != 0) {
            puVar2[uVar7 * 0x29 + 2] = param_1;
            uVar5 = cacheAimArch7SizeInfoGet(0,1);
            if ((uVar5 & 0x80000000) != 0) {
              puVar2[uVar7 * 0x29 + 3] = 1;
            }
            if ((uVar5 & 0x40000000) != 0) {
              puVar2[uVar7 * 0x29 + 3] = puVar2[uVar7 * 0x29 + 3] | 2;
            }
            if ((uVar5 & 0x20000000) != 0) {
              puVar2[uVar7 * 0x29 + 3] = puVar2[uVar7 * 0x29 + 3] | 8;
            }
            if ((uVar5 & 0x10000000) != 0) {
              puVar2[uVar7 * 0x29 + 3] = puVar2[uVar7 * 0x29 + 3] | 4;
            }
            puVar2[uVar7 * 0x29 + 5] = 0x20;
            puVar2[uVar7 * 0x29 + 6] = 0x20;
            puVar2[uVar7 * 0x29 + 7] = 4;
            puVar2[uVar7 * 0x29 + 8] = 0x20;
            uVar5 = (DAT_300abb3c & uVar5 >> 0xd) + 1;
            puVar2[uVar7 * 0x29 + 9] = uVar5;
            puVar2[uVar7 * 0x29 + 10] = 0x20;
            puVar2[uVar7 * 0x29 + 4] = uVar5 * 0x80;
          }
        }
        else if ((puVar2[uVar7 * 0x29 + 1] == 1) && ((uVar4 & 1) != 0)) {
          puVar2[uVar7 * 0x29 + 2] = param_2;
          puVar8 = puVar2 + uVar7 * 0x29 + 0xc;
          uVar5 = cacheAimArch7SizeInfoGet(0,0);
          if ((uVar5 & 0x80000000) != 0) {
            puVar2[uVar7 * 0x29 + 3] = 1;
          }
          if ((uVar5 & 0x40000000) != 0) {
            puVar2[uVar7 * 0x29 + 3] = puVar2[uVar7 * 0x29 + 3] | 2;
          }
          if ((uVar5 & 0x20000000) != 0) {
            puVar2[uVar7 * 0x29 + 3] = puVar2[uVar7 * 0x29 + 3] | 8;
          }
          if ((uVar5 & 0x10000000) != 0) {
            puVar2[uVar7 * 0x29 + 3] = puVar2[uVar7 * 0x29 + 3] | 4;
          }
          puVar2[uVar7 * 0x29 + 5] = 0x20;
          puVar2[uVar7 * 0x29 + 6] = 0x20;
          puVar2[uVar7 * 0x29 + 7] = 4;
          puVar2[uVar7 * 0x29 + 8] = 0x20;
          uVar5 = (DAT_300abb3c & uVar5 >> 0xd) + 1;
          puVar2[uVar7 * 0x29 + 9] = uVar5;
          puVar2[uVar7 * 0x29 + 10] = 0x20;
          puVar2[uVar7 * 0x29 + 4] = uVar5 * 0x80;
          iVar9 = 0xf;
          do {
            if ((*puVar8 & 0xff) == 8) {
              puVar8[1] = *DAT_300abb2c;
            }
            if ((*puVar8 & 0xff) == 9) {
              puVar8[1] = *DAT_300abb28;
            }
            puVar8 = puVar8 + 2;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *puVar2);
    }
    uVar6 = aimCacheInit(puVar2);
    pcVar3 = DAT_300abb40;
    if ((param_1 & 0xf0) != 0 || (param_2 & 0xf0) != 0) {
      return 0xffffffff;
    }
    *DAT_300abb44 = DAT_300abb40;
    *DAT_300abb4c = DAT_300abb48;
    (*pcVar3)(uVar6);
    (*(code *)*DAT_300abb4c)();
    *DAT_300abb50 = param_2;
    *DAT_300abb54 = 0;
    *DAT_300abb58 = 0;
    *(undefined4 *)(iVar1 + 4) = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * cacheCortexA9DClearDisable @ 0x300ABB5C  (примерный размер ~180 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABB5C, 0x07000000, 0xFFFFFFFB
 * Данные: DAT_300abc08, DAT_300abc0c
 * ---------------------------------------------------------------- */
ulonglong cacheCortexA9DClearDisable(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined4 in_cr14;
  
  uVar2 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
  uVar5 = uVar2 & 0x7000000;
  if (uVar5 != 0) {
    uVar8 = 0;
    while( true ) {
      if (1 < (uVar2 & 7)) {
        coprocessor_moveto(0xf,2,0,uVar8,in_cr0,in_cr0);
        coproc_moveto_Flush_Prefetch_Buffer(uVar8);
        uVar3 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
        uVar6 = DAT_300abc08 & uVar3 >> 3;
        uVar4 = uVar6;
        uVar7 = DAT_300abc0c & uVar3 >> 0xd;
        do {
          do {
            coprocessor_moveto(0xf,0,2,uVar8 | uVar4 << LZCOUNT(uVar6) | uVar7 << (uVar3 & 7) + 4,
                               in_cr7,in_cr14);
            bVar1 = 0 < (int)uVar4;
            uVar4 = uVar4 - 1;
          } while (bVar1);
          bVar1 = 0 < (int)uVar7;
          uVar4 = uVar6;
          uVar7 = uVar7 - 1;
        } while (bVar1);
      }
      uVar8 = uVar8 + 2;
      if ((int)(uVar5 >> 0x17) <= (int)uVar8) break;
      uVar2 = uVar2 >> 3;
    }
  }
  coproc_moveto_Data_Synchronization(uVar2);
  uVar2 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar2 & 0xfffffffb);
  return CONCAT44(uVar2,(uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) <<
                        0x1b) & 0xfffffffbffffffff;
}

/* ----------------------------------------------------------------
 * cacheAimArch6IInvalidateAll @ 0x300ABC10  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: cacheAimArch7IEnable, cacheArchIInvalidateAll
 * Константы: 0x300ABC10
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch6IInvalidateAll(void)

{
  coproc_moveto_Invalidate_Entire_Instruction(0);
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch6DClear @ 0x300ABC24  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABC24
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch6DClear(uint param_1,uint param_2,int param_3)

{
  do {
    coproc_moveto_Invalidate_Data_Cache_by_MVA(param_1);
    param_1 = param_1 + param_3;
  } while (param_1 < param_2);
  DataSynchronizationBarrier(0xf);
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch6DFlush @ 0x300ABC40  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: cacheArchDClear, cacheArchDFlush
 * Константы: 0x300ABC40
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch6DFlush(uint param_1,uint param_2,int param_3)

{
  do {
    coproc_moveto_Clean_Data_Cache_by_MVA(param_1);
    param_1 = param_1 + param_3;
  } while (param_1 < param_2);
  DataSynchronizationBarrier(0xf);
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch6DInvalidate @ 0x300ABC5C  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: cacheArchDClear, cacheArchDInvalidate
 * Константы: 0x300ABC5C
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch6DInvalidate(uint param_1,uint param_2,int param_3)

{
  do {
    coproc_moveto_Invalidate_Entire_Data_by_MVA(param_1);
    param_1 = param_1 + param_3;
  } while (param_1 < param_2);
  DataSynchronizationBarrier(0xf);
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch6IClearDisable @ 0x300ABC78  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABC78, 0xFFFFEFFF
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch6IClearDisable(void)

{
  uint uVar1;
  
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 & 0xffffefff);
  coproc_moveto_Invalidate_Entire_Instruction(0);
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch6IInvalidate @ 0x300ABCA8  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: cacheAimArch7TextUpdate, cacheArchIInvalidate
 * Константы: 0x300ABCA8
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch6IInvalidate(uint param_1,uint param_2,int param_3)

{
  do {
    coproc_moveto_Invalidate_Instruction_Cache_by_MVA(param_1);
    param_1 = param_1 + param_3;
  } while (param_1 < param_2);
  return 0;
}

/* ----------------------------------------------------------------
 * cacheAimArch6PipeFlush @ 0x300ABCC0  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABCC0
 * ---------------------------------------------------------------- */
undefined4 cacheAimArch6PipeFlush(void)

{
  coproc_moveto_Data_Synchronization(0);
  return 0;
}

/* ----------------------------------------------------------------
 * mmuHardCrGet @ 0x300ABCCC  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABCCC
 * ---------------------------------------------------------------- */
undefined4 mmuHardCrGet(void)

{
  undefined4 uVar1;
  
  uVar1 = coproc_movefrom_Control();
  return uVar1;
}

/* ----------------------------------------------------------------
 * mmuModifyHardCr @ 0x300ABCD4  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABCD4
 * ---------------------------------------------------------------- */
uint mmuModifyHardCr(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 & ~param_2 | param_1 & param_2);
  return param_1 & param_2;
}

/* ----------------------------------------------------------------
 * mmuFarGet @ 0x300ABD00  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABD00
 * ---------------------------------------------------------------- */
undefined4 mmuFarGet(void)

{
  undefined4 uVar1;
  undefined4 in_cr0;
  undefined4 in_cr6;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr6,in_cr0);
  return uVar1;
}

/* ----------------------------------------------------------------
 * mmuVirtToPhys @ 0x300ABD08  (примерный размер ~116 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABD08
 * Данные: DAT_300abdf0, DAT_300abdf4
 * ---------------------------------------------------------------- */
uint mmuVirtToPhys(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  iVar1 = *DAT_300abdf0;
  puVar3 = DAT_300abdf4;
  if (0 < iVar1) {
    do {
      uVar2 = *puVar3;
      if ((uVar2 <= param_1) && (param_1 <= (uVar2 + puVar3[3]) - 1)) {
        return puVar3[1] + (param_1 - uVar2);
      }
      iVar1 = iVar1 + -1;
      puVar3 = puVar3 + 6;
    } while (iVar1 != 0);
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * mmuPhysToVirt @ 0x300ABD7C  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABD7C
 * Данные: DAT_300abdf0, DAT_300abdf4
 * ---------------------------------------------------------------- */
uint mmuPhysToVirt(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  bool bVar5;
  
  iVar1 = *DAT_300abdf0;
  piVar4 = DAT_300abdf4;
  if (0 < iVar1) {
    do {
      uVar3 = piVar4[2];
      uVar2 = piVar4[1];
      bVar5 = param_2 <= uVar3;
      if (uVar3 == param_2) {
        bVar5 = param_1 <= uVar2;
      }
      if ((!bVar5 || uVar3 == param_2 && uVar2 == param_1) && (param_1 <= (uVar2 + piVar4[3]) - 1))
      {
        return *piVar4 + (param_1 - uVar2);
      }
      iVar1 = iVar1 + -1;
      piVar4 = piVar4 + 6;
    } while (iVar1 != 0);
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * mmuCortexA8TtbrSet @ 0x300ABDF8  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: cacheAimArch7Identify, cacheCortexA8L2ClearAll
 * Вызывают: FUN_300ac2b4
 * Константы: 0x300ABDF8
 * Данные: DAT_300abfac
 * ---------------------------------------------------------------- */
uint mmuCortexA8TtbrSet(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = coproc_movefrom_Translation_table_base_0();
  uVar2 = param_1 & ~DAT_300abfac | uVar2 & DAT_300abfac;
  coproc_moveto_Invalidate_Entire_Instruction(0);
  iVar1 = cacheAimArch7Identify(1);
  if (iVar1 != 0) {
    cacheCortexA8L2ClearAll();
  }
  DataSynchronizationBarrier(0xf);
  coproc_moveto_Translation_table_base_0(uVar2);
  coproc_moveto_Invalidate_unified_TLB_unlocked(0);
  return uVar2;
}

/* ----------------------------------------------------------------
 * mmuCortexA8TtbrSetAll @ 0x300ABE0C  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: cacheAimArch7Identify, cacheCortexA8L2ClearAll
 * Вызывают: FUN_300ad138
 * Константы: 0x300ABE0C
 * ---------------------------------------------------------------- */
undefined4 mmuCortexA8TtbrSetAll(undefined4 param_1)

{
  int iVar1;
  
  coproc_moveto_Invalidate_Entire_Instruction(0);
  iVar1 = cacheAimArch7Identify(1);
  if (iVar1 != 0) {
    cacheCortexA8L2ClearAll();
  }
  DataSynchronizationBarrier(0xf);
  coproc_moveto_Translation_table_base_0(param_1);
  coproc_moveto_Invalidate_unified_TLB_unlocked(0);
  return param_1;
}

/* ----------------------------------------------------------------
 * mmuCortexA8TtbrGet @ 0x300ABE3C  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300ac2b4, mmuArchTtbrGet
 * Константы: 0x300ABE3C
 * Данные: DAT_300abfac
 * ---------------------------------------------------------------- */
uint mmuCortexA8TtbrGet(void)

{
  uint uVar1;
  
  uVar1 = coproc_movefrom_Translation_table_base_0();
  return uVar1 & ~DAT_300abfac;
}

/* ----------------------------------------------------------------
 * mmuCortexA8TtbrGetAll @ 0x300ABE4C  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300ad138
 * Константы: 0x300ABE4C
 * ---------------------------------------------------------------- */
undefined4 mmuCortexA8TtbrGetAll(void)

{
  undefined4 uVar1;
  
  uVar1 = coproc_movefrom_Translation_table_base_0();
  return uVar1;
}

/* ----------------------------------------------------------------
 * mmuCortexA8DacrSet @ 0x300ABE54  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300ad138
 * Константы: 0x300ABE54
 * ---------------------------------------------------------------- */
void mmuCortexA8DacrSet(undefined4 param_1)

{
  coproc_moveto_Domain_Access_Control(param_1);
  return;
}

/* ----------------------------------------------------------------
 * mmuCortexA8AcrSet @ 0x300ABE5C  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABE5C
 * ---------------------------------------------------------------- */
void mmuCortexA8AcrSet(undefined4 param_1)

{
  coproc_moveto_Auxiliary_Control(param_1);
  return;
}

/* ----------------------------------------------------------------
 * mmuCortexA8AcrGet @ 0x300ABE64  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABE64
 * ---------------------------------------------------------------- */
undefined4 mmuCortexA8AcrGet(void)

{
  undefined4 uVar1;
  
  uVar1 = coproc_movefrom_Auxiliary_Control();
  return uVar1;
}

/* ----------------------------------------------------------------
 * mmuCortexA8ITcmrSet @ 0x300ABE6C  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABE6C
 * ---------------------------------------------------------------- */
void mmuCortexA8ITcmrSet(undefined4 param_1)

{
  undefined4 in_cr1;
  undefined4 in_cr9;
  
  coprocessor_moveto(0xf,0,1,param_1,in_cr9,in_cr1);
  return;
}

/* ----------------------------------------------------------------
 * mmuCortexA8ITcmrGet @ 0x300ABE74  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABE74
 * ---------------------------------------------------------------- */
undefined4 mmuCortexA8ITcmrGet(void)

{
  undefined4 uVar1;
  undefined4 in_cr1;
  undefined4 in_cr9;
  
  uVar1 = coprocessor_movefromRt(0xf,0,1,in_cr9,in_cr1);
  return uVar1;
}

/* ----------------------------------------------------------------
 * mmuCortexA8DTcmrSet @ 0x300ABE7C  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABE7C
 * ---------------------------------------------------------------- */
void mmuCortexA8DTcmrSet(undefined4 param_1)

{
  undefined4 in_cr1;
  undefined4 in_cr9;
  
  coprocessor_moveto(0xf,0,0,param_1,in_cr9,in_cr1);
  return;
}

/* ----------------------------------------------------------------
 * mmuCortexA8DTcmrGet @ 0x300ABE84  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300ABE84
 * ---------------------------------------------------------------- */
undefined4 mmuCortexA8DTcmrGet(void)

{
  undefined4 uVar1;
  undefined4 in_cr1;
  undefined4 in_cr9;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr1);
  return uVar1;
}

/* ----------------------------------------------------------------
 * mmuCortexA8BufCopy @ 0x300ABE8C  (примерный размер ~92 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: bcopy
 * Вызывают: FUN_300aebec
 * Константы: 0x300ABE8C
 * ---------------------------------------------------------------- */
void mmuCortexA8BufCopy(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    return;
  }
  uVar2 = 3;
  coproc_moveto_Domain_Access_Control(3);
  uVar4 = (uint)param_1 | (uint)param_2 | param_3;
  uVar3 = (undefined2)uVar4;
  if ((uVar4 & 1) == 0) {
    puVar1 = param_1;
    if (param_3 < 5) {
      puVar1 = param_1 + 1;
      uVar2 = *param_1;
    }
    param_1 = puVar1;
    if (param_3 == 4) {
      param_1 = puVar1 + 1;
      uVar3 = *puVar1;
    }
    puVar1 = param_2;
    if (param_3 < 5) {
      puVar1 = param_2 + 1;
      *param_2 = uVar2;
    }
    param_2 = puVar1;
    if (param_3 == 4) {
      param_2 = puVar1 + 1;
      *puVar1 = uVar3;
    }
    if (param_3 < 5) goto LAB_300abed8;
  }
  bcopy(param_1,param_2,param_3);
LAB_300abed8:
  coproc_moveto_Domain_Access_Control(1);
  return;
}

/* ----------------------------------------------------------------
 * mmuCortexA8WordSet @ 0x300ABEE8  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 12 | Вызывает: 0
 * Вызывают: FUN_300ac018, FUN_300ac330, FUN_300ac494, FUN_300ac6ac, FUN_300ac984, FUN_300ad9ec, FUN_300adeb0, FUN_300adf3c, FUN_300ae13c, FUN_300ae598
 *           ...
 * Константы: 0x300ABEE8
 * ---------------------------------------------------------------- */
void mmuCortexA8WordSet(undefined4 *param_1,undefined4 param_2)

{
  coproc_moveto_Domain_Access_Control(3);
  *param_1 = param_2;
  coproc_moveto_Domain_Access_Control(1);
  return;
}

/* ----------------------------------------------------------------
 * mmuCortexA8WordSetMultiple @ 0x300ABF10  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300ae13c, FUN_300ae500
 * Константы: 0x300ABF10
 * ---------------------------------------------------------------- */
void mmuCortexA8WordSetMultiple(undefined4 *param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    return;
  }
  coproc_moveto_Domain_Access_Control(3);
  do {
    *param_1 = param_2;
    param_3 = param_3 + -1;
    param_1 = param_1 + 1;
  } while (param_3 != 0);
  coproc_moveto_Domain_Access_Control(1);
  return;
}

/* ----------------------------------------------------------------
 * mmuCortexA8AEnable @ 0x300ABF50  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300ad138
 * Константы: 0x300ABF50
 * ---------------------------------------------------------------- */
void mmuCortexA8AEnable(uint param_1)

{
  uint uVar1;
  
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 | 1 | param_1);
  return;
}

/* ----------------------------------------------------------------
 * mmuCortexA8ADisable @ 0x300ABF64  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300ad138, sysToMonitor
 * Константы: 0xFFFFFFF2, 0x300ABF64, 0xFFFFFFFA
 * ---------------------------------------------------------------- */
uint mmuCortexA8ADisable(void)

{
  uint uVar1;
  
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 & 0xfffffffa);
  coproc_moveto_Control(uVar1 & 0xfffffff2);
  return uVar1 & 0xfffffff2;
}

/* ----------------------------------------------------------------
 * mmuCortexA8TLBIDFlushEntry @ 0x300ABF7C  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_300ac018, FUN_300ac984, FUN_300adf3c, FUN_300ae13c, FUN_300ae598
 * Константы: 0x300ABF7C
 * ---------------------------------------------------------------- */
undefined4 mmuCortexA8TLBIDFlushEntry(undefined4 param_1)

{
  coproc_moveto_Invalidate_unified_TLB_by_MVA(param_1);
  coproc_moveto_Instruction_cache(0,6);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return 0;
}

/* ----------------------------------------------------------------
 * mmuCortexA8TLBIDFlushAll @ 0x300ABF94  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 0
 * Вызывают: FUN_300ad138, FUN_300ae500, FUN_300ae930, FUN_300ae9dc
 * Константы: 0x300ABF94
 * ---------------------------------------------------------------- */
undefined4 mmuCortexA8TLBIDFlushAll(void)

{
  coproc_moveto_Invalidate_unified_TLB_unlocked(0);
  coproc_moveto_Instruction_cache(0,6);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300abfb0 @ 0x300ABFB0  (примерный размер ~104 байт)
 * Модуль: kernel | Вызывают: 8 | Вызывает: 0
 * Вызывают: FUN_300ac018, FUN_300ac984, FUN_300ad8cc, FUN_300ad948, FUN_300adeb0, FUN_300adf3c, FUN_300ae500, FUN_300aeed4
 * Константы: 0x300ABFB0, 0xFFFFFFFF
 * Данные: DAT_300acfa4, DAT_300acfa8
 * ---------------------------------------------------------------- */
undefined4 FUN_300abfb0(int param_1,uint param_2,int *param_3,int *param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = (uint *)(param_1 + (param_2 >> 0x14) * 4);
  *param_4 = (int)puVar1;
  uVar4 = *puVar1;
  if ((uVar4 & 3) == 1) {
    iVar3 = (*(code *)*DAT_300acfa4)(uVar4 & DAT_300acfa8,0);
    *param_3 = iVar3 + (param_2 >> 0xc & 0xff) * 4;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300ac018 @ 0x300AC018  (примерный размер ~484 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_300abfb0, cacheClear, cacheFlush, cacheInvalidate, errnoSet, mmuCortexA8TLBIDFlushEntry, mmuCortexA8WordSet
 * Вызывают: FUN_300acc8c, FUN_300ace48
 * Константы: 0x300AC018, 0xFFFFFFFF
 * Данные: DAT_300acfac, DAT_300acfb0, DAT_300acfb4, DAT_300acfb8
 * ---------------------------------------------------------------- */
undefined4 FUN_300ac018(undefined4 *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *local_20;
  undefined1 auStack_1c [4];
  
  iVar3 = FUN_300abfb0(*param_1,param_2,&local_20,auStack_1c);
  puVar2 = DAT_300acfb8;
  if (iVar3 != 0) {
    errnoSet(DAT_300acfac);
    return 0xffffffff;
  }
  if ((param_3 & DAT_300acfb0) == 0) goto LAB_300ac1d0;
  uVar5 = *local_20 >> 2 & 3;
  uVar4 = (param_4 & param_3) >> 2 & 3;
  if ((*local_20 & 0x10c) == 0x104) {
    uVar5 = 3;
  }
  if ((param_4 & 0x10c) == 0x104) {
    uVar4 = 3;
  }
  cVar1 = *(char *)(DAT_300acfb4 + uVar4 + uVar5 * 4);
  if (cVar1 == '\0') {
    uVar4 = (*(code *)*DAT_300acfb8)();
    if (((((uVar4 & 5) != 5) || (uVar5 == 0)) || (uVar5 == 1)) ||
       ((*local_20 & 0x400) == (param_4 & 0x400))) goto LAB_300ac1d0;
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 == '\x02') {
        uVar4 = (*(code *)*DAT_300acfb8)();
        if ((uVar4 & 5) == 5) {
          cacheClear(1,param_2,0x1000);
        }
        uVar4 = (*(code *)*DAT_300acfb8)();
      }
      else {
        if (cVar1 != '\x03') goto LAB_300ac1d0;
        uVar4 = (*(code *)*DAT_300acfb8)();
        if ((uVar4 & 5) == 5) {
          cacheInvalidate(1,param_2,0x1000);
        }
        uVar4 = (*(code *)*puVar2)();
      }
      if ((uVar4 & 0x1000) != 0) {
        cacheInvalidate(0,param_2,0x1000);
      }
      goto LAB_300ac1d0;
    }
    uVar4 = (*(code *)*DAT_300acfb8)();
    if ((uVar4 & 5) != 5) goto LAB_300ac1d0;
  }
  cacheFlush(1,param_2,0x1000);
LAB_300ac1d0:
  mmuCortexA8WordSet(local_20,*local_20 & ~param_3 | param_4 & param_3);
  mmuCortexA8TLBIDFlushEntry(param_2);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ac1fc @ 0x300AC1FC  (примерный размер ~184 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_300ace48, bcopy, memPartAlignedAlloc
 * Вызывают: FUN_300ac6ac, FUN_300ad9ec
 * Константы: 0x300AC1FC, 0xFFFFFFFF
 * Данные: DAT_300ad1b8, DAT_300ad1bc, DAT_300ad1c0
 * ---------------------------------------------------------------- */
undefined4 FUN_300ac1fc(undefined4 *param_1)

{
  void *__dest;
  undefined4 uVar1;
  
  __dest = (void *)memPartAlignedAlloc(*DAT_300ad1b8,0x4000,0x4000);
  if (__dest == (void *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    bcopy((void *)*param_1,__dest,0x4000);
    param_1[1] = __dest;
    FUN_300ace48(*DAT_300ad1bc,__dest,4,DAT_300ad1c0,0x210,0);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300ac2b4 @ 0x300AC2B4  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 5
 * Вызывает: cacheArchIntLock, intIFLock, intIFUnlock, mmuCortexA8TtbrGet, mmuCortexA8TtbrSet
 * Вызывают: FUN_300ac2dc
 * Константы: 0x300AC2B4
 * Данные: DAT_300ad1c4, DAT_300ad1c8
 * ---------------------------------------------------------------- */
void FUN_300ac2b4(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (*(code *)*DAT_300ad1c8)(*param_1);
  uVar2 = cacheArchIntLock();
  uVar1 = DAT_300ad1c4;
  uVar3 = mmuCortexA8TtbrGet();
  if ((uVar3 & uVar1) != (uVar4 & uVar1)) {
    intIFLock();
    mmuCortexA8TtbrSet(uVar4);
  }
  intIFUnlock(uVar2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ac2dc @ 0x300AC2DC  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_300ac2b4, intIFLock, intIFUnlock, vmCurrentGet
 * Вызывают: FUN_300ac6ac, FUN_300ad9ec
 * Константы: 0x300AC2DC
 * Данные: DAT_300ad2ac
 * ---------------------------------------------------------------- */
void FUN_300ac2dc(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = *param_1;
  uVar3 = param_1[1];
  uVar1 = intIFLock();
  *param_1 = uVar3;
  param_1[1] = uVar4;
  iVar2 = vmCurrentGet();
  if (*(undefined4 **)(iVar2 + 0x40) == param_1) {
    FUN_300ac2b4(param_1);
    *(undefined4 *)(*DAT_300ad2ac + 0x214) = uVar3;
  }
  intIFUnlock(uVar1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ac330 @ 0x300AC330  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: mmuCortexA8WordSet
 * Вызывают: FUN_300ac6ac
 * Константы: 0x300AC330, 0xFF000000, 0xFFFBFFFF
 * Данные: DAT_300ad2b0, DAT_300ad2b4
 * ---------------------------------------------------------------- */
void FUN_300ac330(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint local_18;
  
  uVar2 = DAT_300ad2b4;
  uVar1 = DAT_300ad2b0;
  puVar3 = (uint *)(param_1 + ((param_2 & 0xff000000) >> 0x14) * 4);
  iVar4 = 0x10;
  local_18 = *puVar3 & 0xfffbffff;
  do {
    mmuCortexA8WordSet(puVar3,local_18);
    iVar4 = iVar4 + -1;
    local_18 = local_18 & uVar2 | ((local_18 >> 0x14) + 1 & uVar1) << 0x14;
    puVar3 = puVar3 + 1;
  } while (iVar4 != 0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ac39c @ 0x300AC39C  (примерный размер ~248 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_300ace48, bfill, errnoGet, errnoSet, memPartAlignedAlloc, poolBlockAdd, poolItemGet
 * Вызывают: FUN_300ac494, FUN_300adeb0
 * Константы: 0x300AC39C
 * Данные: DAT_300acfb0, DAT_300ad1b8, DAT_300ad1bc, DAT_300ad378
 * ---------------------------------------------------------------- */
int FUN_300ac39c(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = errnoGet();
  puVar1 = DAT_300ad1bc;
  iVar3 = poolItemGet(DAT_300ad1bc[4]);
  if (iVar3 == 0) {
    errnoSet(uVar2);
    iVar3 = memPartAlignedAlloc(*DAT_300ad1b8,puVar1[1],0x1000);
    if (iVar3 == 0) {
      return 0;
    }
    if (puVar1[8] == 0) {
      uVar4 = puVar1[6];
      if (uVar4 < 0x100) {
        *(int *)(DAT_300ad378 + uVar4 * 4) = iVar3;
        puVar1[6] = uVar4 + 1;
      }
    }
    else {
      FUN_300ace48(*puVar1,iVar3,(uint)puVar1[1] >> 0xc,DAT_300acfb0,0,0);
    }
    poolBlockAdd(puVar1[4],iVar3,puVar1[1]);
    iVar3 = poolItemGet(puVar1[4]);
    if (iVar3 == 0) {
      return 0;
    }
  }
  bfill(iVar3,0x400,0);
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_300ac494 @ 0x300AC494  (примерный размер ~164 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300ac39c, mmuCortexA8WordSet
 * Вызывают: FUN_300ac650
 * Константы: 0x300AC494, 0xFFFFFFFF
 * Данные: DAT_300ad1c8, DAT_300ad4a0
 * ---------------------------------------------------------------- */
undefined4 FUN_300ac494(int param_1,uint param_2,uint param_3,undefined4 param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = FUN_300ac39c();
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    (*(code *)*DAT_300ad1c8)(iVar2);
    mmuCortexA8WordSet(param_1 + (param_2 >> 0x14) * 4);
    uVar1 = DAT_300ad4a0;
    iVar4 = 0x100;
    do {
      mmuCortexA8WordSet(iVar2,param_5 | param_3 & uVar1 | 2);
      param_3 = param_3 + 0x1000;
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300ac538 @ 0x300AC538  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300ac568
 * Константы: 0x300AC538
 * ---------------------------------------------------------------- */
uint FUN_300ac538(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 >> 6;
  return param_1 & 0xc | uVar1 & 0x230 | uVar1 & 0x1c0 | uVar1 & 0x400 | param_1 >> 4 & 1;
}

/* ----------------------------------------------------------------
 * FUN_300ac568 @ 0x300AC568  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_300ac538
 * Вызывают: FUN_300ac650, FUN_300ad8cc
 * Константы: 0x300AC568, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300ac568(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + (param_2 >> 0x14) * 4);
  if ((uVar2 & 3) == 2) {
    uVar1 = FUN_300ac538(uVar2);
    *param_3 = uVar1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300ac5b4 @ 0x300AC5B4  (примерный размер ~156 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300ac650, FUN_300ad948
 * Константы: 0x300AC5B4, 0xFF000000, 0x00FFFFFF, 0x00F00000, 0xFFFFFFFF
 * Данные: DAT_300ad2b4, DAT_300ad4a4, DAT_300ad5a4
 * ---------------------------------------------------------------- */
undefined4 FUN_300ac5b4(int param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(param_1 + (param_2 >> 0x14) * 4);
  if ((uVar2 & 3) == 2) {
    if ((uVar2 & DAT_300ad4a4) == 2) {
      uVar4 = 0;
      uVar3 = uVar2 & DAT_300ad5a4 | param_2 & DAT_300ad2b4;
    }
    else {
      uVar3 = uVar2 & 0xff000000 | param_2 & 0xffffff;
      uVar4 = (uVar2 & 0xf00000) >> 0x14;
    }
    *param_3 = uVar3;
    param_3[1] = uVar4;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300ac650 @ 0x300AC650  (примерный размер ~92 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300ac494, FUN_300ac568, FUN_300ac5b4
 * Вызывают: FUN_300ac6ac
 * Константы: 0x300AC650
 * Данные: DAT_300ad1c0, DAT_300ad5a4
 * ---------------------------------------------------------------- */
void FUN_300ac650(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar1 = DAT_300ad1c0;
  param_2 = param_2 & DAT_300ad5a4;
  FUN_300ac568(param_1,param_2,&local_24);
  FUN_300ac5b4(param_1,param_2,&local_20);
  FUN_300ac494(param_1,param_2,local_20,local_1c,local_24 & uVar1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ac6ac @ 0x300AC6AC  (примерный размер ~684 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 8
 * Вызывает: FUN_300ac1fc, FUN_300ac2dc, FUN_300ac330, FUN_300ac650, FUN_300ace48, errnoSet, memPartFree, mmuCortexA8WordSet
 * Вызывают: FUN_300acc8c, FUN_300ae668
 * Константы: 0xFFFFFFFF, 0x300AC6AC
 * Данные: DAT_300ad1b8, DAT_300ad1bc, DAT_300ad1c0, DAT_300ad2b0, DAT_300ad2b4, DAT_300ad6e8, DAT_300ad6ec, DAT_300ad6f0
 * ---------------------------------------------------------------- */
undefined4 FUN_300ac6ac(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (((param_1 == (int *)0x0) || ((param_2 & DAT_300ad2b0) != 0)) || (param_3 == 0)) {
    uVar3 = 0xffffffff;
  }
  else {
    param_1[0x1c] = param_1[0x1c] + 1;
    if ((param_1[1] == 0) && (iVar4 = FUN_300ac1fc(param_1), iVar4 == -1)) {
      uVar3 = 0xffffffff;
    }
    else {
      iVar7 = param_1[1];
      uVar2 = param_2 >> 0x14;
      iVar4 = *param_1;
      uVar5 = *(uint *)(iVar7 + uVar2 * 4);
      uVar6 = param_2 + param_3 * 0x1000;
      if ((uVar5 & 3) == 2) {
        if ((uVar5 & 0x40000) != 0) {
          if ((uVar5 & DAT_300ad6e8) != 0) {
            if ((code *)*DAT_300ad6ec != (code *)0x0) {
              (*(code *)*DAT_300ad6ec)(DAT_300ad6f0,param_2,0,0,0,0,0);
            }
            param_1[0x1c] = param_1[0x1c] + -1;
            errnoSet(DAT_300ad6f4);
            return 0xffffffff;
          }
          FUN_300ac330(iVar7,param_2);
        }
        if ((param_2 & DAT_300ad2b4) != 0) {
          FUN_300ac650(iVar7,param_2);
        }
      }
      if (((*(uint *)(iVar7 + (uVar6 >> 0x14) * 4) & 3) == 2) && ((uVar6 & DAT_300ad2b4) != 0)) {
        FUN_300ac650(iVar7,uVar6);
      }
      FUN_300ac2dc(param_1);
      uVar5 = *(uint *)(iVar4 + uVar2 * 4);
      if ((uVar5 & 3) != 2) {
        if ((code *)*DAT_300ad6ec != (code *)0x0) {
          (*(code *)*DAT_300ad6ec)(DAT_300ad83c,param_2,0,0,0,0,0);
        }
        iVar4 = FUN_300ace48(*DAT_300ad1bc,param_1[1],4,DAT_300ad1c0,
                             *(uint *)(DAT_300ad840 + *(int *)(DAT_300ad840 + 0x40) * 4) | 0x10,0);
        if (iVar4 == 0) {
          memPartFree(*DAT_300ad1b8,param_1[1]);
        }
        param_1[1] = 0;
        param_1[0x1c] = param_1[0x1c] + -1;
        errnoSet(DAT_300ad844);
        return 0xffffffff;
      }
      if ((uVar5 & 0x40000) == 0) {
        mmuCortexA8WordSet(iVar4 + uVar2 * 4,*(undefined4 *)(iVar7 + uVar2 * 4));
      }
      else {
        FUN_300ac330(iVar4,param_2);
        uVar5 = DAT_300ad2b4;
        if ((param_2 & DAT_300ad2b4) != 0) {
          mmuCortexA8WordSet(iVar4 + uVar2 * 4,*(undefined4 *)(iVar7 + uVar2 * 4));
        }
        if ((uVar6 & uVar5) != 0) {
          iVar1 = (uVar6 >> 0x14) * 4;
          mmuCortexA8WordSet(iVar4 + iVar1,*(undefined4 *)(iVar7 + iVar1));
        }
      }
      FUN_300ac2dc(param_1);
      uVar3 = 0;
    }
    param_1[0x1c] = param_1[0x1c] + -1;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300ac958 @ 0x300AC958  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300ac984, FUN_300ad9ec, FUN_300ae13c
 * Константы: 0x300AC958
 * ---------------------------------------------------------------- */
uint FUN_300ac958(uint param_1)

{
  return param_1 & 0xc | (param_1 & 0x230) << 6 | (param_1 & 0x1c0) << 6 | (param_1 & 0x400) << 6 |
         (param_1 & 1) << 4;
}

/* ----------------------------------------------------------------
 * FUN_300ac984 @ 0x300AC984  (примерный размер ~776 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_300abfb0, FUN_300ac958, cacheClear, cacheFlush, cacheInvalidate, mmuCortexA8TLBIDFlushEntry, mmuCortexA8WordSet
 * Вызывают: FUN_300acc8c
 * Константы: 0x00100000, 0xFFFFFFFF, 0x300AC984
 * Данные: DAT_300acfb0, DAT_300acfb4, DAT_300acfb8, DAT_300ad5a4, DAT_300ad6ec, DAT_300ad928, DAT_300ad92c, DAT_300adb40
 * ---------------------------------------------------------------- */
undefined4 FUN_300ac984(int *param_1,uint param_2,uint param_3,uint param_4)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *local_34;
  uint local_30;
  uint *local_2c;
  
  puVar2 = DAT_300acfb8;
  iVar3 = (param_2 >> 0x14) * 4;
  puVar6 = (uint *)(*param_1 + iVar3);
  local_30 = *puVar6;
  if ((local_30 & 3) != 2) {
    return 0xffffffff;
  }
  if ((param_3 & DAT_300acfb0) == 0) goto LAB_300acb50;
  uVar5 = local_30 >> 2 & 3;
  uVar4 = (param_4 & param_3) >> 2 & 3;
  if ((local_30 & DAT_300ad928) == DAT_300ad92c) {
    uVar5 = 3;
  }
  if ((param_4 & 0x10c) == 0x104) {
    uVar4 = 3;
  }
  cVar1 = *(char *)(DAT_300acfb4 + uVar4 + uVar5 * 4);
  if (cVar1 == '\0') {
    uVar4 = (*(code *)*DAT_300acfb8)();
    if (((((uVar4 & 5) != 5) || (uVar5 == 0)) || (uVar5 == 1)) ||
       ((local_30 & 0x10000) == (param_4 & 0x400) * 0x40)) goto LAB_300acb50;
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 == '\x02') {
        uVar4 = (*(code *)*DAT_300acfb8)();
        if ((uVar4 & 5) == 5) {
          cacheClear(1,param_2,0x100000);
        }
        uVar4 = (*(code *)*puVar2)();
      }
      else {
        if (cVar1 != '\x03') goto LAB_300acb50;
        uVar4 = (*(code *)*DAT_300acfb8)();
        if ((uVar4 & 5) == 5) {
          cacheInvalidate(1,param_2,0x100000);
        }
        uVar4 = (*(code *)*puVar2)();
      }
      if ((uVar4 & 0x1000) != 0) {
        cacheInvalidate(0,param_2,0x100000);
      }
      goto LAB_300acb50;
    }
    uVar4 = (*(code *)*DAT_300acfb8)();
    if ((uVar4 & 5) != 5) goto LAB_300acb50;
  }
  cacheFlush(1,param_2,0x100000);
LAB_300acb50:
  uVar4 = FUN_300ac958(param_4);
  uVar5 = FUN_300ac958(param_3);
  mmuCortexA8WordSet(puVar6,local_30 & ~uVar5 | uVar4 & uVar5);
  if (param_1[1] != 0) {
    puVar6 = (uint *)(param_1[1] + iVar3);
    if ((*puVar6 & 3) == 2) {
      mmuCortexA8WordSet(puVar6,*puVar6 & ~uVar5 | uVar4 & uVar5);
    }
    else {
      uVar4 = param_2 & DAT_300ad5a4;
      uVar5 = uVar4 + 0x100000;
      if (uVar5 != uVar4) {
        do {
          local_2c = puVar6;
          iVar3 = FUN_300abfb0(param_1[1],uVar4,&local_34,&local_2c);
          puVar6 = local_2c;
          if (iVar3 != 0) {
            if ((code *)*DAT_300ad6ec != (code *)0x0) {
              (*(code *)*DAT_300ad6ec)(DAT_300adb40,uVar4,0,0,0,0,0);
            }
            mmuCortexA8TLBIDFlushEntry(param_2);
            return 0xffffffff;
          }
          mmuCortexA8WordSet(local_34,*local_34 & ~param_3 | param_4 & param_3);
          uVar4 = uVar4 + 0x1000;
        } while (uVar5 != uVar4);
      }
    }
  }
  mmuCortexA8TLBIDFlushEntry(param_2);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300acc8c @ 0x300ACC8C  (примерный размер ~444 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300ac018, FUN_300ac6ac, FUN_300ac984
 * Вызывают: FUN_300ace48
 * Константы: 0xFFFFFFFF, 0x00100000, 0x00FFFFFF, 0x300ACC8C
 * Данные: DAT_300ad2b4, DAT_300ad5a4
 * ---------------------------------------------------------------- */
undefined4 FUN_300acc8c(int *param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  puVar3 = (uint *)(*param_1 + (param_2 >> 0x14) * 4);
  uVar2 = *puVar3;
  if ((uVar2 & 3) != 2) {
    return 0xffffffff;
  }
  uVar4 = param_2 + param_3 * 0x1000;
  if ((uVar2 & 0x40000) == 0) {
    if ((param_2 & DAT_300ad2b4) != 0) goto LAB_300acd0c;
    uVar5 = uVar4 & DAT_300ad2b4;
  }
  else {
    if ((param_2 & 0xffffff) != 0) goto LAB_300acd0c;
    uVar5 = uVar4 & 0xffffff;
  }
  if (uVar5 == 0) {
    if (param_2 == uVar4) {
      return 0;
    }
    do {
      iVar1 = FUN_300ac984(param_1,param_2,param_4,param_5);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      param_2 = param_2 + 0x100000;
    } while (param_2 != uVar4);
    return 0;
  }
LAB_300acd0c:
  iVar1 = FUN_300ac6ac(param_1,param_2,param_3,puVar3,uVar2);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (param_2 != uVar4) {
    do {
      while (uVar2 = *(uint *)(*param_1 + (param_2 >> 0x14) * 4), (uVar2 & 3) != 2) {
        uVar5 = (param_2 & DAT_300ad5a4) + 0x100000;
        if (((uVar4 < uVar5) && (uVar4 != 0)) || (uVar5 == 0)) {
          uVar5 = uVar4;
        }
        for (; param_2 != uVar5; param_2 = param_2 + 0x1000) {
          iVar1 = FUN_300ac018(param_1,param_2,param_4,param_5,uVar2);
          if (iVar1 != 0) {
            return 0xffffffff;
          }
        }
        if (param_2 == uVar4) {
          return 0;
        }
      }
      iVar1 = FUN_300ac984(param_1,param_2,param_4,param_5);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      param_2 = param_2 + 0x100000;
    } while (param_2 != uVar4);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ace48 @ 0x300ACE48  (примерный размер ~532 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 6
 * Вызывает: FUN_300ac018, FUN_300acc8c, errnoSet, intContext, semMGive, semMTake
 * Вызывают: FUN_300ac1fc, FUN_300ac39c, FUN_300ac6ac, FUN_300ad05c, FUN_300ad5ec, FUN_300ad768, FUN_300aebec
 * Константы: 0xFFFFFFFF, 0x300ACE48, 0x00FFFFFF, 0x00100000, 0xFF000000, 0x01000000
 * Данные: DAT_300ad2b4, DAT_300ad5a4, DAT_300add90, DAT_300add94
 * ---------------------------------------------------------------- */
undefined4
FUN_300ace48(int *param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (param_3 == 0) {
    return 0;
  }
  uVar6 = param_2 + param_3 * 0x1000;
  if ((uVar6 < param_2) && (uVar6 != 0)) {
    errnoSet(DAT_300add90);
  }
  else {
    iVar1 = intContext(param_1);
    if (iVar1 == 0) {
      iVar2 = semMTake(param_1 + 2,0xffffffff);
      if (iVar2 == 0) goto LAB_300acf18;
    }
    else {
      if ((param_1[0x1c] == 0) &&
         ((uVar4 = *(uint *)(*param_1 + (param_2 >> 0x14) * 4), (uVar4 & 3) != 2 ||
          (((param_2 & DAT_300ad2b4) == 0 &&
           (((uVar4 & 0x40000) == 0 || ((param_2 & 0xffffff) == 0)))))))) {
LAB_300acf18:
        if (param_2 != uVar6) {
          do {
            uVar5 = *(uint *)(*param_1 + (param_2 >> 0x14) * 4);
            uVar4 = (param_2 & DAT_300ad5a4) + 0x100000;
            if ((uVar5 & 3) == 2) {
              if ((uVar5 & 0x40000) != 0) {
                uVar4 = (param_2 & 0xff000000) + 0x1000000;
              }
              if (((uVar6 < uVar4) && (uVar6 != 0)) || (uVar7 = uVar4, uVar4 == 0)) {
                uVar7 = uVar6;
              }
              iVar2 = FUN_300acc8c(param_1,param_2,uVar7 - param_2 >> 0xc,param_4,param_5,param_6,
                                   uVar5);
              if (iVar2 == -1) {
LAB_300ad040:
                if (iVar1 != 0) {
                  return 0xffffffff;
                }
                semMGive(param_1 + 2);
                return 0xffffffff;
              }
            }
            else {
              uVar7 = param_2;
              if (((uVar6 < uVar4) && (uVar6 != 0)) || (uVar4 == 0)) {
                uVar4 = uVar6;
              }
              for (; uVar7 != uVar4; uVar7 = uVar7 + 0x1000) {
                iVar2 = FUN_300ac018(param_1,uVar7,param_4,param_5);
                if (iVar2 != 0) goto LAB_300ad040;
              }
            }
            param_2 = uVar7;
          } while (uVar7 != uVar6);
        }
        if (iVar1 != 0) {
          return 0;
        }
        uVar3 = semMGive(param_1 + 2);
        return uVar3;
      }
      errnoSet(DAT_300add94);
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300ad05c @ 0x300AD05C  (примерный размер ~220 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300ace48
 * Вызывают: FUN_300ad138
 * Константы: 0x300AD05C
 * Данные: DAT_300ad1bc, DAT_300ad1c0, DAT_300adfe8, DAT_300adfec
 * ---------------------------------------------------------------- */
void FUN_300ad05c(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  uVar2 = DAT_300ad1c0;
  puVar1 = DAT_300ad1bc;
  iVar3 = param_1[1];
  FUN_300ace48(*DAT_300ad1bc,*param_1,4,DAT_300ad1c0,0x210,0);
  if (iVar3 != 0) {
    FUN_300ace48(*puVar1,iVar3,4,uVar2,0x210,0);
  }
  uVar2 = DAT_300adfec;
  uVar5 = 0;
  puVar4 = DAT_300adfe8;
  if (puVar1[6] != 0) {
    do {
      FUN_300ace48(*puVar1,puVar4[1],(uint)puVar1[1] >> 0xc,uVar2,0,0);
      uVar5 = uVar5 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar5 < (uint)puVar1[6]);
  }
  puVar1[8] = 1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ad138 @ 0x300AD138  (примерный размер ~712 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 14
 * Вызывает: FUN_300ad05c, cacheArchIntLock, cacheArchL2CacheDisable, cacheArchL2CacheEnable, cacheClear, cacheFuncsSet, cacheInvalidate, intIFUnlock, mmuCortexA8ADisable, mmuCortexA8AEnable, mmuCortexA8DacrSet, mmuCortexA8TLBIDFlushAll, mmuCortexA8TtbrGetAll, mmuCortexA8TtbrSetAll
 * Константы: 0xFFFFFFFF, 0x300AD138
 * Данные: DAT_300ad1bc, DAT_300ad1c4, DAT_300adff0, DAT_300ae10c, DAT_300ae110
 * ---------------------------------------------------------------- */
undefined4 FUN_300ad138(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = cacheArchIntLock();
  if (param_1 == 0) {
    cacheClear(1,0,0xffffffff);
    mmuCortexA8ADisable();
    cacheArchL2CacheDisable();
    mmuCortexA8TLBIDFlushAll();
    *DAT_300ae110 = 0;
  }
  else {
    mmuCortexA8TLBIDFlushAll();
    puVar1 = DAT_300ad1bc;
    uVar4 = *DAT_300adff0;
    if (DAT_300ad1bc[7] == 0) {
      mmuCortexA8DacrSet(1);
      mmuCortexA8AEnable(uVar4);
    }
    else {
      FUN_300ad05c(*DAT_300ad1bc);
      mmuCortexA8DacrSet(1);
      uVar3 = mmuCortexA8TtbrGetAll();
      mmuCortexA8TtbrSetAll(uVar3 & DAT_300ad1c4);
      (*(code *)*DAT_300ae10c)(uVar4 | 1,uVar4 | 1);
      puVar1[7] = 0;
    }
    cacheClear(1,0,0xffffffff);
    *DAT_300ae110 = uVar4 >> 2 & 1;
    cacheArchL2CacheEnable();
  }
  cacheFuncsSet();
  cacheInvalidate(0,0,0xffffffff);
  intIFUnlock(uVar2);
  return 0;
}

/* ----------------------------------------------------------------
 * mmuCortexA8LibInstall @ 0x300AD400  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: sysHwInit0
 * Константы: 0x300AD400
 * Данные: DAT_300ae10c, DAT_300ae354, DAT_300ae358, DAT_300ae35c, DAT_300ae360, DAT_300ae364, DAT_300ae368, DAT_300ae36c
 * ---------------------------------------------------------------- */
void mmuCortexA8LibInstall(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DAT_300ae354;
  if (*(int *)(DAT_300ae354 + 0x24) == 0) {
    *DAT_300ae35c = DAT_300ae358;
    *DAT_300ae10c = DAT_300ae360;
    *DAT_300ae368 = DAT_300ae364;
    *(undefined4 *)(iVar1 + 0x14) = param_1;
    *(undefined4 *)(iVar1 + 8) = param_2;
    *DAT_300ae370 = DAT_300ae36c;
    *(undefined4 *)(iVar1 + 0x24) = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ad460 @ 0x300AD460  (примерный размер ~396 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: __div32, __udiv32, errnoSet, poolCreate
 * Константы: 0xFFFFFFFF, 0x300AD460
 * Данные: DAT_300ad840, DAT_300ad844, DAT_300ae354, DAT_300ae374, DAT_300ae378, DAT_300ae37c, DAT_300ae380, DAT_300ae384
 * ---------------------------------------------------------------- */
undefined4 FUN_300ad460(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = DAT_300ae354;
  if (*(int *)(DAT_300ae354 + 0x28) == 0) {
    if (*(int *)(DAT_300ae354 + 0x14) == 0) {
      *(undefined4 *)(DAT_300ae354 + 0x14) = DAT_300ae374;
    }
    if (*(int *)(iVar1 + 8) == 0) {
      *(undefined4 *)(iVar1 + 8) = DAT_300ae378;
    }
    *DAT_300ae380 = DAT_300ae37c;
    *DAT_300ae388 = DAT_300ae384;
    *DAT_300ae38c = DAT_300ad840;
    *DAT_300ae394 = DAT_300ae390;
    *DAT_300ae398 = 0xffffffff;
    *DAT_300ae3a0 = DAT_300ae39c;
    iVar2 = 0x16;
    puVar3 = DAT_300ae3a4;
    puVar4 = DAT_300ae3a8;
    do {
      iVar2 = iVar2 + -1;
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar2 != 0);
    if (param_1 != 0x1000) {
      errnoSet(DAT_300ad844);
      return 0xffffffff;
    }
    *(undefined4 *)(iVar1 + 0xc) = 0x1000;
    uVar5 = *DAT_300ae3ac;
    if (uVar5 == 0) {
      uVar5 = __div32(0x4000,0x400);
      *DAT_300ae3ac = uVar5;
    }
    iVar2 = __udiv32(uVar5 << 10,0x1000);
    uVar6 = iVar2 * 0x1000;
    *(uint *)(iVar1 + 4) = uVar6;
    if (uVar6 < 0x1000) {
      *(undefined4 *)(iVar1 + 4) = 0x1000;
      uVar6 = 0x1000;
    }
    if (uVar5 != 1) {
      *DAT_300ae3ac = uVar6 >> 10;
    }
    iVar2 = poolCreate(DAT_300ae4d0,0x400,0x400,0,0,0,3);
    *(int *)(iVar1 + 0x10) = iVar2;
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(iVar1 + 0x28) = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ad5ec @ 0x300AD5EC  (примерный размер ~176 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300ace48, bfill, memPartAlignedAlloc, semMInitialize
 * Вызывают: FUN_300ad69c
 * Константы: 0x300AD5EC, 0xFFFFFFFF
 * Данные: DAT_300ae354, DAT_300ae4d4, DAT_300ae4d8
 * ---------------------------------------------------------------- */
undefined4 FUN_300ad5ec(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = memPartAlignedAlloc(*DAT_300ae4d4,0x4000,0x4000);
  *param_1 = iVar2;
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    bfill(iVar2,0x4000,0);
    piVar1 = DAT_300ae354;
    if (DAT_300ae354[0xb] == 0) {
      FUN_300ace48(*DAT_300ae354,iVar2,4,DAT_300ae4d8,0x210,0,DAT_300ae354);
    }
    else {
      *DAT_300ae354 = (int)param_1;
      piVar1[0xb] = 0;
    }
    param_1[1] = 0;
    semMInitialize(param_1 + 2,0xd);
    param_1[0x1c] = 0;
    param_1[0x1d] = 0;
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300ad69c @ 0x300AD69C  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300ad5ec, memPartAlloc, memPartFree
 * Константы: 0x300AD69C
 * Данные: DAT_300ae4d4
 * ---------------------------------------------------------------- */
int FUN_300ad69c(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = memPartAlloc(*DAT_300ae4d4,0x78);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = FUN_300ad5ec(iVar1);
  if (iVar2 == -1) {
    memPartFree(*DAT_300ae4d4,iVar1);
    return 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300ad708 @ 0x300AD708  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: poolItemReturn
 * Вызывают: FUN_300ad768, FUN_300ae9dc
 * Константы: 0x300AD708
 * Данные: DAT_300ae354, DAT_300ae640
 * ---------------------------------------------------------------- */
void FUN_300ad708(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_300ae354;
  if ((param_1 & 3) == 1) {
    uVar2 = (**(code **)(DAT_300ae354 + 0x14))(param_1 & DAT_300ae640,0);
    poolItemReturn(*(undefined4 *)(iVar1 + 0x10),uVar2);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ad768 @ 0x300AD768  (примерный размер ~356 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300ace48, FUN_300ad708, memPartFree, semDestroy, semMTake
 * Константы: 0xFFFFFFFF, 0x300AD768
 * Данные: DAT_300ad840, DAT_300ae354, DAT_300ae4d4, DAT_300ae4d8
 * ---------------------------------------------------------------- */
undefined4 FUN_300ad768(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  bool bVar11;
  
  uVar9 = 0;
  iVar4 = semMTake(param_1 + 2,0xffffffff);
  if (iVar4 != 0) {
    uVar9 = 0xffffffff;
  }
  puVar6 = (undefined4 *)*param_1;
  iVar8 = 0x1000;
  iVar4 = 0x1000;
  puVar10 = puVar6;
  do {
    iVar5 = FUN_300ad708(*puVar10);
    uVar3 = DAT_300ae4d8;
    puVar2 = DAT_300ae354;
    iVar1 = DAT_300ad840;
    if (iVar5 != 0) {
      uVar9 = 0xffffffff;
    }
    puVar10 = puVar10 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = FUN_300ace48(*DAT_300ae354,puVar6,4,DAT_300ae4d8,
                       *(uint *)(DAT_300ad840 + *(int *)(DAT_300ad840 + 0x40) * 4) | 0x10,0);
  puVar10 = DAT_300ae4d4;
  bVar11 = iVar4 == 0;
  if (bVar11) {
    iVar4 = memPartFree(*DAT_300ae4d4,puVar6);
    bVar11 = iVar4 == 0;
  }
  if (!bVar11) {
    uVar9 = 0xffffffff;
  }
  puVar7 = (undefined4 *)param_1[1];
  puVar6 = puVar7;
  if (puVar7 != (undefined4 *)0x0) {
    do {
      FUN_300ad708(*puVar6);
      iVar8 = iVar8 + -1;
      puVar6 = puVar6 + 1;
    } while (iVar8 != 0);
    iVar4 = FUN_300ace48(*puVar2,puVar7,4,uVar3,*(uint *)(iVar1 + *(int *)(iVar1 + 0x40) * 4) | 0x10
                         ,0);
    bVar11 = iVar4 == 0;
    if (bVar11) {
      iVar4 = memPartFree(*puVar10,puVar7);
      bVar11 = iVar4 == 0;
    }
    if (!bVar11) {
      uVar9 = 0xffffffff;
    }
  }
  iVar4 = semDestroy(param_1 + 2,0);
  if (iVar4 != 0) {
    uVar9 = 0xffffffff;
  }
  iVar4 = memPartFree(*puVar10,param_1);
  if (iVar4 != 0) {
    uVar9 = 0xffffffff;
  }
  return uVar9;
}

/* ----------------------------------------------------------------
 * FUN_300ad8cc @ 0x300AD8CC  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_300abfb0, FUN_300ac568, errnoSet
 * Вызывают: FUN_300ad9ec, FUN_300aebec
 * Константы: 0x300AD8CC, 0xFFFFFFFF
 * Данные: DAT_300ae874
 * ---------------------------------------------------------------- */
undefined4 FUN_300ad8cc(undefined4 *param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *local_18;
  undefined1 auStack_14 [4];
  
  uVar2 = *param_1;
  iVar1 = FUN_300ac568(uVar2);
  if (iVar1 == -1) {
    iVar1 = FUN_300abfb0(uVar2,param_2,&local_18,auStack_14);
    if (iVar1 != 0) {
      errnoSet(DAT_300ae874);
      return 0xffffffff;
    }
    uVar3 = *local_18;
  }
  else {
    uVar3 = *param_3 | 2;
  }
  *param_3 = uVar3;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ad948 @ 0x300AD948  (примерный размер ~164 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300abfb0, FUN_300ac5b4, errnoSet
 * Вызывают: FUN_300ad9ec
 * Константы: 0xFFFFFFFF, 0x300AD948
 * Данные: DAT_300ae874, DAT_300ae878, DAT_300ae87c
 * ---------------------------------------------------------------- */
undefined4 FUN_300ad948(undefined4 *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *local_1c [2];
  undefined1 auStack_14 [4];
  
  uVar3 = *param_1;
  iVar1 = FUN_300ac5b4(uVar3);
  if (iVar1 == -1) {
    iVar1 = FUN_300abfb0(uVar3,param_2,local_1c,auStack_14);
    if (iVar1 != 0) {
      errnoSet(DAT_300ae874);
      return 0xffffffff;
    }
    uVar2 = *local_1c[0] & 3;
    if ((uVar2 != 3) && (uVar2 != 2)) {
      return 0xffffffff;
    }
    *param_3 = *local_1c[0] & DAT_300ae878 | param_2 & DAT_300ae87c;
    param_3[1] = 0;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ad9ec @ 0x300AD9EC  (примерный размер ~1220 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 9
 * Вызывает: FUN_300ac1fc, FUN_300ac2dc, FUN_300ac958, FUN_300ad8cc, FUN_300ad948, errnoSet, mmuCortexA8WordSet, semMGive, semMTake
 * Константы: 0xFFFFFFFF, 0x00100000, 0x01000000, 0xFF000000, 0x00FFFFFF, 0x300AD9EC, 0xFFFFEFFF, 0xFFEFFFFF
 * Данные: DAT_300add90, DAT_300ae87c, DAT_300ae880, DAT_300ae910, DAT_300ae914, DAT_300ae918, DAT_300aec30, DAT_300aed98
 * ---------------------------------------------------------------- */
undefined4 FUN_300ad9ec(int param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint *local_4c;
  uint local_44;
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  int local_28;
  
  if (param_1 == 0) {
    errnoSet(DAT_300ae880);
    return 0xffffffff;
  }
  local_54 = DAT_300ae87c;
  if ((param_2 & DAT_300ae87c) != 0) {
    errnoSet(DAT_300ae910);
    return 0xffffffff;
  }
  uVar6 = param_2 + param_3 * 0x1000;
  if ((uVar6 < param_2) && (uVar6 != 0)) {
    errnoSet(DAT_300add90);
    return 0xffffffff;
  }
  uVar6 = param_2;
  if (0x100 < param_3) {
    if ((param_2 & DAT_300ae914) == 0) goto LAB_300ada98;
    uVar6 = param_2 + DAT_300ae914 & DAT_300ae918;
    param_3 = param_3 - (uVar6 - param_2 >> 0xc);
  }
  if (param_3 < 0x100) {
    return 0xffffffff;
  }
LAB_300ada98:
  local_50 = param_3 >> 8;
  iVar2 = semMTake(param_1 + 8,0xffffffff);
  if (iVar2 == 0) {
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
    uVar7 = uVar6;
    if (*(int *)(param_1 + 4) == 0) {
      iVar2 = FUN_300ac1fc();
      if (iVar2 == -1) {
        *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + -1;
        semMGive(param_1 + 8);
        return 0xffffffff;
      }
    }
    else {
      FUN_300ac2dc(param_1);
    }
    for (; local_50 != 0; local_50 = local_50 - 1) {
      local_4c = (uint *)(*(int *)(param_1 + 4) + (uVar7 >> 0x14) * 4);
      if ((*local_4c & 3) == 1) {
        uVar8 = uVar7 + 0x100000 & DAT_300ae918;
        local_5c = 0;
        do {
          bVar1 = false;
          uVar4 = uVar7;
          for (; uVar7 != uVar8; uVar7 = uVar7 + 0x1000) {
            if (local_5c == 0) {
              while ((uVar4 = uVar7, uVar4 != uVar8 &&
                     ((iVar2 = FUN_300ad8cc(param_1,uVar4,&local_5c), iVar2 != 0 ||
                      ((local_5c & 2) == 0))))) {
                uVar7 = uVar4 + 0x1000;
              }
              uVar7 = uVar4;
              if (uVar4 == uVar8) break;
              FUN_300ad948(param_1,uVar4,&local_44);
            }
            else {
              iVar2 = FUN_300ad8cc(param_1,uVar7,&local_58);
              if ((iVar2 != 0) || ((local_58 & 2) == 0)) {
                local_5c = 0;
                bVar1 = true;
                break;
              }
              if ((local_5c & local_54) != (local_58 & local_54)) {
                local_5c = local_58;
                FUN_300ad948(param_1,uVar7,&local_44);
                bVar1 = true;
                break;
              }
              FUN_300ad948(param_1,uVar7,&local_3c);
              local_34 = local_44 + 0x1000;
              local_30 = local_40 + (uint)(0xffffefff < local_44);
              local_44 = local_3c;
              local_40 = local_38;
              local_2c = local_34;
              local_28 = local_30;
              if (local_30 != local_38 || local_34 != local_3c) {
                bVar1 = true;
                local_5c = local_58;
                break;
              }
            }
          }
          iVar2 = -uVar4;
          if (uVar7 != 0) {
            iVar2 = uVar7 - uVar4;
          }
          if (iVar2 == 0x100000) {
            uVar4 = FUN_300ac958(local_58);
            mmuCortexA8WordSet(local_4c,local_3c & DAT_300ae918 | uVar4 | 2);
          }
          if (!bVar1) goto LAB_300adcf4;
          uVar7 = uVar7 + 0x1000;
        } while( true );
      }
      uVar7 = uVar7 + 0x100000;
LAB_300adcf4:
    }
    local_50 = -0x1000000;
    local_54 = uVar6 + param_3 * 0x1000 & 0xff000000;
    local_5c = 0;
    for (uVar6 = uVar6 + 0xffffff & 0xff000000; uVar7 = uVar6, uVar6 != local_54;
        uVar6 = uVar6 + 0x1000000) {
      do {
        uVar8 = *(uint *)(*(int *)(param_1 + 4) + (uVar7 >> 0x14) * 4);
        if ((uVar8 & DAT_300aec30) != 2) {
          local_5c = 0;
          break;
        }
        if (local_5c == 0) {
          local_5c = uVar8 & DAT_300ae914;
          FUN_300ad948(param_1,uVar7,&local_44);
        }
        else {
          local_58 = uVar8 & DAT_300ae914;
          if (local_5c != local_58) {
            local_5c = local_58;
            FUN_300ad948(param_1,uVar7,&local_44);
            break;
          }
          FUN_300ad948(param_1,uVar7,&local_3c);
          local_34 = local_44 + 0x100000;
          local_30 = local_40 + (uint)(0xffefffff < local_44);
          local_44 = local_3c;
          local_40 = local_38;
          local_2c = local_34;
          local_28 = local_30;
          if (local_30 != local_38 || local_34 != local_3c) {
            local_5c = local_58;
            break;
          }
        }
        uVar7 = uVar7 + 0x100000;
      } while (uVar7 != local_54);
      uVar4 = local_50;
      uVar8 = -uVar6;
      if (uVar7 != 0) {
        uVar8 = uVar7 - uVar6;
      }
      uVar7 = uVar6 >> 0x14;
      for (; 0xffffff < uVar8; uVar8 = uVar8 + uVar4) {
        iVar2 = 0x10;
        do {
          puVar5 = (uint *)(*(int *)(param_1 + 4) + uVar7 * 4);
          mmuCortexA8WordSet(puVar5,*puVar5 & DAT_300aed98 | 0x40000);
          uVar7 = uVar7 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    FUN_300ac2dc(param_1);
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + -1;
    uVar3 = semMGive(param_1 + 8);
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300adeb0 @ 0x300ADEB0  (примерный размер ~140 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300abfb0, FUN_300ac39c, mmuCortexA8WordSet
 * Вызывают: FUN_300adf3c
 * Константы: 0x300ADEB0, 0xFFFFFFFF
 * Данные: DAT_300aed9c
 * ---------------------------------------------------------------- */
undefined4 FUN_300adeb0(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int local_1c;
  uint local_18;
  undefined1 auStack_14 [4];
  
  iVar1 = FUN_300abfb0(*param_1,param_2,auStack_14,&local_1c);
  if (iVar1 != 0) {
    iVar1 = FUN_300ac39c();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    local_18 = (*(code *)*DAT_300aed9c)(iVar1);
    local_18 = local_18 | 1;
    mmuCortexA8WordSet(local_1c);
    if (param_1[1] != 0) {
      local_1c = param_1[1] + (param_2 >> 0x14) * 4;
      mmuCortexA8WordSet(local_1c,local_18);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300adf3c @ 0x300ADF3C  (примерный размер ~228 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300abfb0, FUN_300adeb0, errnoSet, mmuCortexA8TLBIDFlushEntry, mmuCortexA8WordSet
 * Вызывают: FUN_300ae424
 * Константы: 0xFFFFFFFF, 0x300ADF3C
 * Данные: DAT_300ae874, DAT_300ae878
 * ---------------------------------------------------------------- */
undefined4
FUN_300adf3c(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  uint *local_24;
  undefined1 auStack_20 [4];
  
  iVar1 = FUN_300abfb0(*param_1,param_2,&local_24,auStack_20);
  if (iVar1 == 0) {
    uVar2 = *local_24 & 3;
    if ((uVar2 == 3) || (uVar2 == 2)) {
      if ((*local_24 & DAT_300ae878) == (param_3 & DAT_300ae878)) {
        return 0;
      }
      return 0xffffffff;
    }
  }
  else {
    iVar1 = FUN_300adeb0(param_1,param_2);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    iVar1 = FUN_300abfb0(*param_1,param_2,&local_24,auStack_20);
    if (iVar1 != 0) {
      errnoSet(DAT_300ae874);
      return 0xffffffff;
    }
  }
  mmuCortexA8WordSet(local_24,param_5 | param_3 & DAT_300ae878 | 2);
  mmuCortexA8TLBIDFlushEntry(param_2);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ae020 @ 0x300AE020  (примерный размер ~140 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: __udiv32, errnoSet
 * Вызывают: FUN_300ae2f0
 * Константы: 0xFFFFFFFF, 0x300AE020, 0x00100000, 0x01000000
 * Данные: DAT_300ae87c, DAT_300ae910, DAT_300aef60
 * ---------------------------------------------------------------- */
undefined4 FUN_300ae020(uint param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 2) {
    if ((param_1 & 0xff) != 0) {
      errnoSet(DAT_300ae910);
      return 0xffffffff;
    }
    *param_4 = 0x100000;
  }
  else {
    if (param_2 != DAT_300aef60) {
      return 0xffffffff;
    }
    if ((param_1 & DAT_300ae87c) != 0) {
      errnoSet(DAT_300ae910);
      return 0xffffffff;
    }
    *param_4 = 0x1000000;
  }
  uVar1 = __udiv32(param_1 << 0xc,*param_4);
  *param_3 = uVar1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ae0ac @ 0x300AE0AC  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300ae2f0
 * Константы: 0x300AE0AC
 * Данные: DAT_300aec30, DAT_300aef60, DAT_300aef64, DAT_300aef68
 * ---------------------------------------------------------------- */
undefined8 FUN_300ae0ac(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*DAT_300aef64;
  if ((piVar3 != (int *)0x0) && (iVar2 = *DAT_300aef68, 0 < iVar2)) {
    param_2 = 0;
    do {
      if (*piVar3 == param_1) {
        uVar1 = DAT_300aef60;
        if ((piVar3[5] & DAT_300aec30) == DAT_300aef60) goto LAB_300ae134;
        if ((piVar3[5] & DAT_300aec30) == 2) {
          uVar1 = 2;
          goto LAB_300ae134;
        }
      }
      piVar3 = piVar3 + 6;
      param_2 = param_2 + 0x18;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  uVar1 = 1;
LAB_300ae134:
  return CONCAT44(param_2,uVar1);
}

