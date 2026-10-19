/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : kernel — ядро VxWorks 6.8: задачи, семафоры, очереди, прерывания, память, планировщик
 * Часть  : 1 (функций: 150, адреса 0x30005018..0x300A852C)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * usrAppInit @ 0x30005018  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 11
 * Вызывает: BSP_DLOAD_SetDloadComplete, BSP_DLOAD_SetSoftLoad, BSP_DRV_BOOTROM_Init, BSP_InitBootVersion, BSP_InitBspVersion, BSP_OsWait, BSP_PromptSet, BSP_WDT_Disable, BSP_WDT_HardwareFeed, MSP_Init, taskDelay
 * Вызывают: usrRoot
 * Константы: 0x30005018
 * Данные: DAT_3000514c
 * ---------------------------------------------------------------- */
void usrAppInit(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_3000514c;
  BSP_InitBootVersion();
  BSP_InitBspVersion();
  BSP_DRV_BOOTROM_Init();
  iVar2 = BSP_OsWait(5);
  if (iVar2 == 0) {
    BSP_WDT_Disable(0);
  }
  else {
    BSP_WDT_HardwareFeed(0);
    MSP_Init();
    BSP_WDT_Disable(0);
  }
  *(undefined4 *)(iVar1 + 0xc) = 1;
  BSP_DLOAD_SetDloadComplete(0);
  BSP_DLOAD_SetSoftLoad(0);
  taskDelay(1);
  BSP_PromptSet();
  return;
}

/* ----------------------------------------------------------------
 * usrRtpAppInit @ 0x30005150  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30005150
 * ---------------------------------------------------------------- */
void usrRtpAppInit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * memUsrInitFunction @ 0x30005E50  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: memset, printf
 * Вызывают: BSP_MEM_Init
 * Константы: 0x30005E50
 * Данные: DAT_30006d4c, DAT_30006d50
 * ---------------------------------------------------------------- */
undefined4 memUsrInitFunction(void)

{
  printf(DAT_30006d4c);
  memset(DAT_30006d50,0,0x400);
  return 0;
}

/* ----------------------------------------------------------------
 * edrStubInit @ 0x3003F2E8  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrRoot
 * Константы: 0x3003F2E8
 * ---------------------------------------------------------------- */
void edrStubInit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * edrErrorInjectStub @ 0x3003F2EC  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 11 | Вызывает: 0
 * Вызывают: FUN_300e2404, FUN_300e2e10, excExcHandle, kernelInit, memPartEdrErrorInject, memPartLibInit, reboot, taskDestroy, usrMmuInit, vxTaskEntryFatalInject
 *           ...
 * Константы: 0x3003F2EC
 * ---------------------------------------------------------------- */
undefined4 edrErrorInjectStub(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * edrKernelFatalPolicyHandler @ 0x3003F2F4  (примерный размер ~588 байт)
 * Модуль: kernel | Вызывают: 6 | Вызывает: 3
 * Вызывает: edrFlagsGet, logMsg, taskStopForce
 * Вызывают: FUN_300e2e10, excExcHandle, kernelInit, memPartEdrErrorInject, taskDestroy, vxTaskEntryFatalInject
 * Константы: 0x3003F2F4
 * Данные: DAT_30040290, DAT_30040294, DAT_30040298
 * ---------------------------------------------------------------- */
void edrKernelFatalPolicyHandler(int *param_1)

{
  uint uVar1;
  
  uVar1 = edrFlagsGet();
  if ((uVar1 & 1) == 0) {
    if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
      logMsg(*DAT_30040290,*DAT_30040298,0,0,0,0,0);
      if ((param_1 != (int *)0x0) && (param_1[7] != 0)) {
        logMsg(DAT_30040294,param_1[7],0,0,0,0,0);
      }
      taskStopForce(0);
      *(undefined4 *)(*DAT_30040298 + 0x120) = 0;
    }
    else {
      logMsg(*DAT_30040290,*param_1,0,0,0,0,0);
      if (param_1[7] != 0) {
        logMsg(DAT_30040294,param_1[7],0,0,0,0,0);
      }
      taskStopForce(*param_1);
    }
  }
  else if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    logMsg(*DAT_30040290,*DAT_30040298,0,0,0,0,0);
    if ((param_1 != (int *)0x0) && (param_1[7] != 0)) {
      logMsg(DAT_30040294,param_1[7],0,0,0,0,0);
    }
    taskStopForce(0);
    *(undefined4 *)(*DAT_30040298 + 0x120) = 0;
  }
  else {
    logMsg(*DAT_30040290,*param_1,0,0,0,0,0);
    if (param_1[7] != 0) {
      logMsg(DAT_30040294,param_1[7],0,0,0,0,0);
    }
    taskStopForce(*param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * edrRtpFatalPolicyHandler @ 0x3003F540  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3003F540
 * ---------------------------------------------------------------- */
void edrRtpFatalPolicyHandler(void)

{
  return;
}

/* ----------------------------------------------------------------
 * edrInitFatalPolicyHandler @ 0x3003F544  (примерный размер ~148 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 2
 * Вызывает: edrFlagsGet, reboot
 * Вызывают: excExcHandle, memPartLibInit, usrMmuInit
 * Константы: 0x3003F544
 * Данные: DAT_300404b4, DAT_300404b8
 * ---------------------------------------------------------------- */
void edrInitFatalPolicyHandler(undefined4 *param_1)

{
  uint uVar1;
  
  if ((*DAT_300404b4 != 0) && (param_1 != (undefined4 *)0x0)) {
    *DAT_300404b8 = *DAT_300404b8 + 1;
    (*(code *)*DAT_300404b4)(*param_1,param_1[1],param_1[2],param_1[3]);
    *DAT_300404b8 = *DAT_300404b8 + -1;
  }
  uVar1 = edrFlagsGet();
  if ((uVar1 & 1) == 0) {
    reboot(1);
  }
  else {
    reboot(1);
  }
  return;
}

/* ----------------------------------------------------------------
 * edrInterruptFatalPolicyHandler @ 0x3003F5D8  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: edrFlagsGet, reboot
 * Вызывают: excExcHandle, workQPanic
 * Константы: 0x3003F5D8
 * Данные: DAT_300404b4
 * ---------------------------------------------------------------- */
void edrInterruptFatalPolicyHandler(undefined4 *param_1)

{
  uint uVar1;
  
  if ((*DAT_300404b4 != 0) && (param_1 != (undefined4 *)0x0)) {
    (*(code *)*DAT_300404b4)(*param_1,param_1[1],param_1[2],param_1[3]);
  }
  uVar1 = edrFlagsGet();
  if ((uVar1 & 1) == 0) {
    reboot(0);
  }
  else {
    reboot(0);
  }
  return;
}

/* ----------------------------------------------------------------
 * usrBootLineInit @ 0x3003F644  (примерный размер ~92 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: strcpy, sysNvRamGet
 * Вызывают: usrBootLineParse
 * Константы: 0x3003F644
 * Данные: DAT_30040554, DAT_30040558
 * ---------------------------------------------------------------- */
void usrBootLineInit(void)

{
  int iVar1;
  
  if ((*DAT_30040554 == '\0') &&
     (((iVar1 = sysNvRamGet(DAT_30040554,0xff,0), iVar1 == -1 || (*DAT_30040554 == '\0')) ||
      (*DAT_30040554 == -1)))) {
    strcpy(DAT_30040554,DAT_30040558);
  }
  return;
}

/* ----------------------------------------------------------------
 * usrBootLineCrack @ 0x3003F6A0  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: bootParamsErrorPrint, bootStringToStruct
 * Вызывают: usrBootLineParse
 * Константы: 0x3003F6A0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 usrBootLineCrack(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = (char *)bootStringToStruct(param_1,param_2);
  if (*pcVar1 == '\0') {
    uVar2 = 0;
  }
  else {
    bootParamsErrorPrint(param_1,pcVar1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * usrBootLineParse @ 0x3003F6E4  (примерный размер ~568 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 8
 * Вызывает: bcopy, printf, strcmp, strcpy, strncpy, sysProcNumSet, usrBootLineCrack, usrBootLineInit
 * Вызывают: usrIosExtraInit
 * Константы: 0x3003F6E4, 0xFFFFFFFF
 * Данные: DAT_30040554, DAT_3004055c, DAT_30040560, DAT_30040564, DAT_30040568, DAT_3004056c, DAT_30040570, DAT_30040574
 * ---------------------------------------------------------------- */
undefined4 usrBootLineParse(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2bc [40];
  char local_294 [20];
  char local_280 [180];
  char acStack_1cc [160];
  char acStack_12c [160];
  char acStack_8c [20];
  char acStack_78 [20];
  char acStack_64 [80];
  undefined4 local_14;
  undefined4 local_10;
  
  usrBootLineInit(*DAT_3004055c);
  if (param_1 == 0) {
    param_1 = DAT_30040554;
  }
  iVar1 = usrBootLineCrack(param_1,auStack_2bc);
  if (iVar1 == 0) {
    if ((local_294[0] == '\0') && (iVar1 = strcmp(DAT_30040560,DAT_30040564), iVar1 != 0)) {
      strncpy(local_294,DAT_30040560,0x14);
      printf(DAT_30040568,local_294);
    }
    if ((local_280[0] == '\0') && (iVar1 = strcmp(DAT_3004056c,DAT_30040564), iVar1 != 0)) {
      strncpy(local_280,DAT_3004056c,0x14);
      printf(DAT_30040570,local_280);
    }
    if ((acStack_8c[0] == '\0') && (iVar1 = strcmp(DAT_30040574,DAT_30040564), iVar1 != 0)) {
      strncpy(acStack_8c,DAT_30040574,0x14);
      printf(DAT_30040578,acStack_8c);
    }
    if ((acStack_12c[0] == '\0') && (iVar1 = strcmp(DAT_30040564,DAT_30040564), iVar1 != 0)) {
      strncpy(acStack_12c,DAT_30040564,0xa0);
      printf(DAT_3004057c,acStack_12c);
    }
    if ((acStack_64[0] == '\0') && (iVar1 = strcmp(DAT_30040564,DAT_30040564), iVar1 != 0)) {
      strncpy(acStack_64,DAT_30040564,0x50);
      printf(DAT_30040580,acStack_64);
    }
    if (acStack_78[0] == '\0') {
      strncpy(acStack_78,DAT_30040564,0x14);
    }
    bcopy(auStack_2bc,DAT_30040584,0x2b4);
    *DAT_30040588 = local_10;
    strcpy(DAT_3004058c,local_294);
    strcpy(DAT_30040590,acStack_1cc);
    if (*DAT_30040594 != 1) {
      sysProcNumSet(local_14);
      *DAT_30040594 = 1;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * usrBootLineGet @ 0x3003F91C  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3003F91C
 * Данные: DAT_30040554
 * ---------------------------------------------------------------- */
undefined4 usrBootLineGet(void)

{
  return DAT_30040554;
}

/* ----------------------------------------------------------------
 * usrClock @ 0x3003F924  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: windExit, windTickAnnounce, workQAdd0
 * Константы: 0x3003F924
 * Данные: DAT_3012bbc4, DAT_3012bbc8
 * ---------------------------------------------------------------- */
void usrClock(void)

{
  if (*DAT_3012bbc4 == 1) {
    workQAdd0(DAT_3012bbc8);
  }
  else {
    *DAT_3012bbc4 = 1;
    windTickAnnounce();
    windExit();
  }
  return;
}

/* ----------------------------------------------------------------
 * usrBanner @ 0x3003F948  (примерный размер ~120 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: edrIsDebugMode, printLogo, printf, sysMemTop, sysModel, sysProcNumGet
 * Вызывают: usrShellInit
 * Константы: 0x3003F948, 0x30000000
 * Данные: DAT_3004059c, DAT_300405a0, DAT_300405a4, DAT_300405a8, DAT_300405ac, DAT_300405b0, DAT_300405b4, DAT_300405b8
 * ---------------------------------------------------------------- */
void usrBanner(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  printLogo();
  uVar1 = sysProcNumGet();
  uVar2 = sysModel();
  printf(DAT_3004059c,uVar2,uVar1);
  iVar3 = sysMemTop();
  printf(DAT_300405a0,iVar3 + -0x30000000);
  printf(DAT_300405a4);
  printf(DAT_300405a8,*DAT_300405ac);
  iVar3 = edrIsDebugMode();
  uVar1 = DAT_300405b4;
  if (iVar3 != 0) {
    uVar1 = DAT_300405b0;
  }
  printf(DAT_300405b8,uVar1);
  return;
}

/* ----------------------------------------------------------------
 * usrBreakpointSet @ 0x3003F9C0  (примерный размер ~268 байт)
 * Модуль: kernel | Вызывают: 9 | Вызывает: 1
 * Вызывает: memcpy
 * Вызывают: FUN_300c6554, FUN_300c701c, FUN_300c7bac, FUN_300c7cbc, FUN_300c7f5c, FUN_300c7fec, FUN_300c8154, vxdbgBpAdd, vxdbgBpAllDisable
 * Константы: 0x3003F9C0
 * Данные: DAT_300405bc, DAT_300405c0
 * ---------------------------------------------------------------- */
void usrBreakpointSet(void *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_4;
  
  uVar2 = 0;
  if (param_3 != 0) {
    uVar2 = *(undefined4 *)(param_3 + 0x44);
  }
  if (param_1 != (void *)0x0) {
    local_4 = param_2;
    if (*(int *)(DAT_300405bc + 0x3c) == 0) {
      memcpy(param_1,&local_4,4);
    }
    else {
      iVar1 = (**(code **)(DAT_300405bc + 0x3c))(uVar2,&local_4,param_1,4);
      if (iVar1 != 0) {
        return;
      }
    }
    if (param_4 == 1) {
      if (*(int *)(DAT_300405c0 + 0x1c) != 0) {
        (**(code **)(DAT_300405c0 + 0x1c))(param_1,4);
      }
    }
    else if ((param_4 == 2) && (*(int *)(DAT_300405c0 + 0x1c) != 0)) {
      (**(code **)(DAT_300405c0 + 0x1c))(param_1,4);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * usrCacheEnable @ 0x3003FACC  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: cacheEnable
 * Вызывают: usrInit
 * Константы: 0x3003FACC
 * ---------------------------------------------------------------- */
undefined4 usrCacheEnable(void)

{
  cacheEnable(0);
  cacheEnable(1);
  return 0;
}

/* ----------------------------------------------------------------
 * usrDosfsInit @ 0x3003FB84  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3003fb10, fsmProbeInstall
 * Вызывают: usrIosExtraInit
 * Константы: 0xFFFFFFFF, 0x3003FB84
 * Данные: DAT_300405d0, DAT_300405d4
 * ---------------------------------------------------------------- */
undefined4 usrDosfsInit(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_3003fb10(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = fsmProbeInstall(DAT_300405d0,DAT_300405d4);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * usrMmuInit @ 0x3003FCE4  (примерный размер ~384 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 7
 * Вызывает: __errno, edrErrorInjectStub, edrInitFatalPolicyHandler, reboot, strlen, vmBaseLibInit, vmGlobalMapInit
 * Вызывают: usrRoot
 * Константы: 0x3003FCE4, 0x3003FE40
 * Данные: DAT_3004060c, DAT_30040610, DAT_30040614, DAT_30040618, DAT_3004061c, DAT_30040620, DAT_30040624, DAT_30040628
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x3003fe40) */

void usrMmuInit(void)

{
  int iVar1;
  size_t sVar2;
  uint *puVar3;
  undefined1 *puVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  
  if ((((*DAT_3004060c == 0) || (iVar1 = (*(code *)*DAT_3004060c)(0x1000), iVar1 != 0)) ||
      (iVar1 = vmBaseLibInit(2), iVar1 != 0)) ||
     (iVar1 = vmGlobalMapInit(DAT_30040610,*DAT_30040614,1,2), iVar1 == 0)) {
    sVar2 = strlen((char *)*DAT_3004061c);
    puVar4 = (undefined1 *)(*DAT_3004061c + sVar2 + -2);
    puVar3 = (uint *)__errno();
    uVar7 = *puVar3;
    for (uVar6 = 0; uVar6 < 8; uVar6 = uVar6 + 1) {
      *puVar4 = *(undefined1 *)(DAT_30040620 + (uVar7 & 0xf));
      puVar4 = puVar4 + -1;
      uVar7 = uVar7 >> 4;
    }
    pcVar5 = (char *)*DAT_3004061c;
    while( true ) {
      pcVar8 = (char *)*DAT_30040624;
      *pcVar8 = *pcVar5;
      if (*pcVar8 == '\0') break;
      *DAT_30040624 = pcVar8 + 1;
      pcVar5 = pcVar5 + 1;
    }
    *DAT_30040624 = pcVar8 + 1;
    edrErrorInjectStub(0x31,DAT_30040628,DAT_3004062c,0,0,0,*DAT_3004061c);
    edrInitFatalPolicyHandler(0);
    reboot(1);
  }
  else if (*DAT_30040618 != 0) {
    (*(code *)*DAT_30040618)();
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3003fe64 @ 0x3003FE64  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrSerialInit
 * Константы: 0x3003FE64
 * Данные: DAT_30040630, DAT_30040634, DAT_30040638
 * ---------------------------------------------------------------- */
char * FUN_3003fe64(uint param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = DAT_30040634;
  pcVar1 = DAT_30040630;
  if (param_1 != 0) {
    *DAT_30040634 = '\0';
    for (; pcVar1 = pcVar2, param_1 != 0;
        param_1 = (uint)((ulonglong)DAT_30040638 * (ulonglong)param_1 >> 0x23)) {
      pcVar2 = pcVar2 + -1;
      *pcVar2 = (char)param_1 +
                (char)(uint)((ulonglong)DAT_30040638 * (ulonglong)param_1 >> 0x23) * -10 + '0';
    }
  }
  return pcVar1;
}

/* ----------------------------------------------------------------
 * usrSerialInit @ 0x3003FEE0  (примерный размер ~232 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_3003fe64, ioGlobalStdSet, ioctl, open, strcat, sysSerialChanGet, ttyDevCreate, ttyDrv
 * Вызывают: usrIosCoreInit
 * Константы: 0x3003FEE0
 * Данные: DAT_3004063c, DAT_30040640, DAT_30040644
 * ---------------------------------------------------------------- */
undefined4 usrSerialInit(void)

{
  bool bVar1;
  char *__src;
  undefined4 uVar2;
  int iVar3;
  char local_1c [20];
  
  ttyDrv();
  bVar1 = false;
  while (!bVar1) {
    local_1c[0] = '\0';
    strcat(local_1c,DAT_3004063c);
    __src = (char *)FUN_3003fe64(0);
    strcat(local_1c,__src);
    uVar2 = sysSerialChanGet(0);
    ttyDevCreate(local_1c,uVar2,0x200,0x200);
    iVar3 = open(local_1c,2,0);
    *DAT_30040640 = iVar3;
    ioctl(*DAT_30040640,4,DAT_30040644);
    ioctl(*DAT_30040640,3,0x7f);
    bVar1 = true;
  }
  ioGlobalStdSet(0,*DAT_30040640);
  ioGlobalStdSet(1,*DAT_30040640);
  ioGlobalStdSet(2,*DAT_30040640);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3003ffc8 @ 0x3003FFC8  (примерный размер ~104 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 7
 * Вызывает: shellCompatibleSet, shellConfigDefaultSet, shellMaxSessionsSet, shellTaskDefaultBaseNameSet, shellTaskDefaultOptionsSet, shellTaskDefaultPrioritySet, shellTaskDefaultStackSizeSet
 * Вызывают: usrShell
 * Константы: 0x3003FFC8, 0xFFFFFFFF
 * Данные: DAT_30040648, DAT_3004064c, DAT_30040650, DAT_30040654, DAT_30040658
 * ---------------------------------------------------------------- */
void FUN_3003ffc8(void)

{
  if (*DAT_30040648 == 0) {
    shellTaskDefaultOptionsSet(DAT_3004064c);
    shellTaskDefaultStackSizeSet(0x10000);
    shellTaskDefaultPrioritySet(1);
    shellTaskDefaultBaseNameSet(DAT_30040650);
    shellMaxSessionsSet(0xffffffff);
    shellConfigDefaultSet(DAT_30040654);
    shellCompatibleSet(0);
    *DAT_30040658 = 0;
    *DAT_30040648 = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * usrShell @ 0x30040030  (примерный размер ~104 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_3003ffc8, ioGlobalStdGet, shellGenericInit
 * Вызывают: usrShellInit
 * Константы: 0x30040030
 * ---------------------------------------------------------------- */
void usrShell(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  FUN_3003ffc8();
  uVar1 = ioGlobalStdGet(0);
  uVar2 = ioGlobalStdGet(1);
  uVar3 = ioGlobalStdGet(2);
  shellGenericInit(0,0x10000,0,0,1,0,uVar1,uVar2,uVar3);
  return;
}

/* ----------------------------------------------------------------
 * usrStandaloneInit @ 0x30040098  (примерный размер ~256 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_30040538, errnoGet, printErr, printf, strerror, symNameGet
 * Вызывают: usrSymTblInit
 * Константы: 0x30040098
 * Данные: DAT_3004065c, DAT_30040660, DAT_30040664, DAT_30040668, DAT_3004066c, DAT_30040670, DAT_30040674, DAT_30040678
 * ---------------------------------------------------------------- */
void usrStandaloneInit(void)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_10;
  
  uVar3 = 0;
  if (*DAT_3004065c != 0) {
    printf(DAT_30040660,*DAT_30040664);
    for (uVar4 = 0; uVar4 < *DAT_30040664; uVar4 = uVar4 + 1) {
      if (((*(byte *)(DAT_30040668 + uVar4 * 0x14) & 2) == 0) &&
         (iVar1 = FUN_30040538(DAT_3004066c + uVar4 * 0x14), iVar1 != 0)) {
        iVar1 = symNameGet(DAT_3004066c + uVar4 * 0x14,&local_10);
        if (iVar1 != 0) {
          local_10 = DAT_30040670;
        }
        if (uVar3 < 10) {
          iVar1 = errnoGet();
          pcVar2 = strerror(iVar1);
          printErr(DAT_30040674,local_10,uVar4,pcVar2);
        }
        else if (uVar3 == 10) {
          printf(DAT_30040678);
        }
        uVar3 = uVar3 + 1;
      }
    }
    if (uVar3 != 0) {
      printf(DAT_3004067c,uVar3);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * usrSysHwInit2 @ 0x300401CC  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrRoot
 * Константы: 0x300401CC
 * ---------------------------------------------------------------- */
void usrSysHwInit2(void)

{
  return;
}

/* ----------------------------------------------------------------
 * usrSysSymTblInit @ 0x300401D0  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: symTblCreate
 * Вызывают: usrSymTblInit
 * Константы: 0x300401D0
 * Данные: DAT_3004065c, DAT_30040684, DAT_30040688, DAT_3004068c
 * ---------------------------------------------------------------- */
void usrSysSymTblInit(void)

{
  int iVar1;
  
  iVar1 = symTblCreate(8,1,*DAT_30040684);
  *DAT_3004065c = iVar1;
  if ((*DAT_3004065c == 0) && (*DAT_30040688 != 0)) {
    (*(code *)*DAT_30040688)(DAT_3004068c);
  }
  return;
}

/* ----------------------------------------------------------------
 * usrTipInit @ 0x30040230  (примерный размер ~80 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: memset, tipLibInit
 * Вызывают: usrToolsInit
 * Константы: 0x30040230
 * Данные: DAT_30040690, DAT_30040694, DAT_30040698
 * ---------------------------------------------------------------- */
void usrTipInit(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  memset(&local_30,0,0x24);
  local_30 = DAT_30040690;
  local_2c = DAT_30040694;
  local_28 = DAT_30040698;
  tipLibInit(param_1,param_2,&local_30);
  return;
}

/* ----------------------------------------------------------------
 * usrLoaderInit @ 0x300402F4  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: loadElfInit, loadLibInit, moduleLibInit
 * Вызывают: usrToolsInit
 * Константы: 0x300402F4
 * ---------------------------------------------------------------- */
void usrLoaderInit(void)

{
  moduleLibInit();
  loadElfInit();
  loadLibInit(0);
  return;
}

/* ----------------------------------------------------------------
 * usrShowInit @ 0x3004030C  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: symShowInit, taskShowInit
 * Вызывают: usrToolsInit
 * Константы: 0x3004030C
 * ---------------------------------------------------------------- */
void usrShowInit(void)

{
  taskShowInit();
  symShowInit();
  return;
}

/* ----------------------------------------------------------------
 * usrSymTblInit @ 0x3004031C  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: usrStandaloneInit, usrSysSymTblInit
 * Вызывают: usrToolsInit
 * Константы: 0x3004031C
 * ---------------------------------------------------------------- */
void usrSymTblInit(void)

{
  usrSysSymTblInit();
  usrStandaloneInit();
  return;
}

/* ----------------------------------------------------------------
 * usrShellInit @ 0x3004032C  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: dbgInit, ledModeRegister, shellInterpRegister, shellLibInit, usrBanner, usrShell
 * Вызывают: usrToolsInit
 * Константы: 0x3004032C
 * Данные: DAT_300406a4, DAT_300406a8
 * ---------------------------------------------------------------- */
void usrShellInit(void)

{
  shellLibInit();
  dbgInit();
  usrBanner();
  ledModeRegister(DAT_300406a4);
  shellInterpRegister(DAT_300406a8);
  usrShell();
  return;
}

/* ----------------------------------------------------------------
 * usrToolsInit @ 0x30040354  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 7
 * Вызывает: eventPointStubLibInit, timexInit, usrLoaderInit, usrShellInit, usrShowInit, usrSymTblInit, usrTipInit
 * Вызывают: usrRoot
 * Константы: 0x30040354
 * Данные: DAT_30040564, DAT_300406ac
 * ---------------------------------------------------------------- */
void usrToolsInit(void)

{
  timexInit();
  eventPointStubLibInit();
  usrLoaderInit();
  usrSymTblInit();
  usrTipInit(DAT_30040564,DAT_300406ac);
  usrShowInit();
  usrShellInit();
  return;
}

/* ----------------------------------------------------------------
 * usrKernelCoreInit @ 0x30040380  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 8
 * Вызывает: eventLibInit, msgQCreateLibInit, msgQLibInit, semDeleteLibInit, taskCreateHookInit, taskCreateLibInit, wdCreateLibInit, wdLibInit
 * Вызывают: usrRoot
 * Константы: 0x30040380
 * ---------------------------------------------------------------- */
void usrKernelCoreInit(void)

{
  eventLibInit(0);
  semDeleteLibInit();
  msgQLibInit();
  wdLibInit();
  taskCreateHookInit();
  taskCreateLibInit();
  msgQCreateLibInit();
  wdCreateLibInit();
  return;
}

/* ----------------------------------------------------------------
 * usrKernelExtraInit @ 0x300403AC  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 5
 * Вызывает: clockLibInit, hashLibInit, sigInit, symLibInit, taskVarInit
 * Вызывают: usrRoot
 * Константы: 0x300403AC
 * ---------------------------------------------------------------- */
void usrKernelExtraInit(void)

{
  hashLibInit();
  symLibInit();
  taskVarInit();
  sigInit(0);
  clockLibInit();
  return;
}

/* ----------------------------------------------------------------
 * usrIosCoreInit @ 0x300403CC  (примерный размер ~80 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 10
 * Вызывает: coprocLibInit, iosInit, iosPathLibInit, iosPxLibInit, iosRmvLibInit, iosRtpLibInit, selectInit, ttyDrv, tyLibInit, usrSerialInit
 * Вызывают: usrRoot
 * Константы: 0x300403CC
 * Данные: DAT_300406b0
 * ---------------------------------------------------------------- */
void usrIosCoreInit(void)

{
  selectInit(0x32);
  iosInit(0x14,0x32,DAT_300406b0);
  iosPathLibInit();
  iosRmvLibInit();
  iosPxLibInit(0);
  iosRtpLibInit();
  tyLibInit(0x55,0x32,0x14);
  ttyDrv();
  usrSerialInit();
  coprocLibInit();
  return;
}

/* ----------------------------------------------------------------
 * usrIosExtraInit @ 0x3004041C  (примерный размер ~160 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 20
 * Вызывает: devInit, dosFsCacheLibInit, dosFsShowInit, erfLibInit, excInit, excShowInit, fioLibInit, floatInit, fsEventUtilLibInit, fsMonitorInit, jobLibInit, logInit, pipeDrv, ptyDrv
 *           ...
 * Вызывают: usrRoot
 * Константы: 0x3004041C, 0x00800000, 0x00100000
 * Данные: DAT_30040554, DAT_30040640
 * ---------------------------------------------------------------- */
void usrIosExtraInit(void)

{
  excShowInit();
  jobLibInit(8000);
  excInit(0x10);
  logInit(*DAT_30040640,0x32);
  pipeDrv();
  stdioInit();
  fioLibInit();
  floatInit();
  erfLibInit(0x10,0x10);
  devInit(0xff);
  xbdInit();
  xbdBlkDevLibInit(0x32);
  fsMonitorInit();
  fsEventUtilLibInit();
  usrDosfsInit(0x14,4);
  dosFsCacheLibInit(0x800000,0x100000,0);
  dosFsShowInit();
  rawFsInit(5);
  ptyDrv();
  usrBootLineParse(DAT_30040554);
  return;
}

/* ----------------------------------------------------------------
 * dbg_get_time_diff @ 0x30045724  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: os_get_time, os_memcpy, time_diff
 * Вызывают: os_dprintf
 * Константы: 0x30045724
 * Данные: DAT_30045cbc, DAT_30045cc0
 * ---------------------------------------------------------------- */
undefined4 dbg_get_time_diff(void)

{
  undefined4 uVar1;
  undefined1 auStack_10 [8];
  
  if (*DAT_30045cbc == '\0') {
    *DAT_30045cbc = '\x01';
    os_get_time(DAT_30045cc0);
  }
  os_get_time(auStack_10);
  uVar1 = time_diff(auStack_10,DAT_30045cc0);
  os_memcpy(DAT_30045cc0,auStack_10,8);
  return uVar1;
}

/* ----------------------------------------------------------------
 * mem_log_print @ 0x30046AD0  (примерный размер ~432 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: jstop_stack
 * Константы: 0x30046AD0
 * Данные: DAT_30047a48, DAT_30047a4c, DAT_30047a50, DAT_30047a54, DAT_30047a58, DAT_30047a5c, DAT_30047b64, DAT_30047b68
 * ---------------------------------------------------------------- */
void mem_log_print(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = 0;
  valid_type(0x1e);
  if ((0 < *(int *)(DAT_30047a48 + 0x78)) && (0 < *(int *)(DAT_30047a48 + 0x78))) {
    os_dprintf(DAT_30047a4c,DAT_30047a50,0x43);
    os_printf(DAT_30047a54);
  }
  valid_type(0x1e);
  if ((0 < *(int *)(DAT_30047a48 + 0x78)) && (0 < *(int *)(DAT_30047a48 + 0x78))) {
    os_dprintf(DAT_30047a4c,DAT_30047a50,0x45);
    os_printf(DAT_30047a58);
  }
  for (iVar3 = *(int *)(DAT_30047a5c + 0x24); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x24)) {
    iVar1 = iVar1 + *(int *)(iVar3 + 0xc);
    iVar2 = iVar2 + 1;
    valid_type(0x1e);
    if ((0 < *(int *)(DAT_30047a48 + 0x78)) && (0 < *(int *)(DAT_30047a48 + 0x78))) {
      os_dprintf(DAT_30047a4c,DAT_30047a50,0x4b);
      os_printf(DAT_30047b64,*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 4),
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc),
                *(undefined4 *)(iVar3 + 0x14));
    }
  }
  valid_type(0x1e);
  if ((0 < *(int *)(DAT_30047a48 + 0x78)) && (0 < *(int *)(DAT_30047a48 + 0x78))) {
    os_dprintf(DAT_30047a4c,DAT_30047a50,0x4e);
    os_printf(DAT_30047b68,iVar2,iVar1);
  }
  valid_type(0x1e);
  if ((0 < *(int *)(DAT_30047a48 + 0x78)) && (0 < *(int *)(DAT_30047a48 + 0x78))) {
    os_dprintf(DAT_30047a4c,DAT_30047a50,0x51);
    os_printf(DAT_30047b6c,*DAT_30047b70,*DAT_30047b74);
  }
  return;
}

/* ----------------------------------------------------------------
 * task_threads_init @ 0x300499F4  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300496a0, FUN_300498e4
 * Вызывают: jos_sync_init
 * Константы: 0x300499F4
 * ---------------------------------------------------------------- */
int task_threads_init(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  while ((iVar1 < 1 && (iVar2 == 0))) {
    iVar2 = FUN_300498e4(iVar1);
    iVar1 = iVar1 + 1;
  }
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    while (iVar1 = iVar1 + -1, -1 < iVar1) {
      FUN_300496a0(iVar1);
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * task_threads_uninit @ 0x30049A58  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_300496a0
 * Вызывают: jos_sync_init, jos_sync_uninit
 * Константы: 0x30049A58
 * ---------------------------------------------------------------- */
void task_threads_uninit(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 1; iVar1 = iVar1 + 1) {
    FUN_300496a0(iVar1);
  }
  return;
}

/* ----------------------------------------------------------------
 * vxprintk_get_len @ 0x30062B44  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: log_buf_copy
 * Константы: 0x30062B44
 * Данные: DAT_30063144
 * ---------------------------------------------------------------- */
undefined4 vxprintk_get_len(void)

{
  return *(undefined4 *)(*DAT_30063144 + 0xc);
}

/* ----------------------------------------------------------------
 * vxprintk_buf_clear @ 0x30062B54  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Константы: 0x30062B54, 0xFFFFFFFF
 * Данные: DAT_30063144, DAT_30063148
 * ---------------------------------------------------------------- */
void vxprintk_buf_clear(void)

{
  semTake(*DAT_30063148,0xffffffff);
  *(undefined4 *)(*DAT_30063144 + 0xc) = 0;
  *(undefined4 *)(*DAT_30063144 + 4) = 0;
  *(undefined4 *)(*DAT_30063144 + 8) = 0;
  semGive(*DAT_30063148);
  return;
}

/* ----------------------------------------------------------------
 * vxprintk @ 0x30062EA8  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_30062e20
 * Константы: 0x30062EA8
 * ---------------------------------------------------------------- */
undefined4 vxprintk(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar1 = FUN_30062e20(param_1,&uStack_c);
  return uVar1;
}

/* ----------------------------------------------------------------
 * vxprintk_read @ 0x30062ED8  (примерный размер ~196 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Константы: 0x30062ED8, 0xFFFFFFFF
 * Данные: DAT_30063144, DAT_30063148, DAT_3006314c
 * ---------------------------------------------------------------- */
uint vxprintk_read(undefined1 *param_1,uint param_2)

{
  undefined1 uVar1;
  uint uVar2;
  
  semTake(*DAT_30063148,0xffffffff);
  for (uVar2 = 0; (*(int *)(*DAT_30063144 + 4) != *(int *)(*DAT_30063144 + 8) && (uVar2 < param_2));
      uVar2 = uVar2 + 1) {
    uVar1 = *(undefined1 *)
             (*(int *)(*DAT_30063144 + 0x14) + (*(uint *)(*DAT_30063144 + 4) & DAT_3006314c));
    *(int *)(*DAT_30063144 + 4) = *(int *)(*DAT_30063144 + 4) + 1;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
  }
  *(int *)(*DAT_30063144 + 0xc) = *(int *)(*DAT_30063144 + 0xc) - uVar2;
  semGive(*DAT_30063148);
  return uVar2;
}

/* ----------------------------------------------------------------
 * vxprintk_write @ 0x30062F9C  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_30062c68, FUN_30062d44, semGive, semTake
 * Константы: 0x30062F9C, 0xFFFFFFFF
 * Данные: DAT_30063148, DAT_30063154, DAT_3006315c
 * ---------------------------------------------------------------- */
int vxprintk_write(char *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (*DAT_3006315c == 1) {
    semTake(*DAT_30063148,0xffffffff);
    for (pcVar2 = param_1; pcVar2 < param_1 + param_2; pcVar2 = pcVar2 + 1) {
      if (*DAT_30063154 == 0) {
        FUN_30062c68((int)*pcVar2);
      }
      else {
        FUN_30062d44((int)*pcVar2);
      }
    }
    semGive(*DAT_30063148);
    iVar1 = (int)pcVar2 - (int)param_1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * vxprintk_stop @ 0x30063024  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: memcpy
 * Константы: 0x30063024
 * Данные: DAT_3006315c, DAT_30063164, DAT_30063168
 * ---------------------------------------------------------------- */
void vxprintk_stop(void)

{
  *DAT_3006315c = 0;
  memcpy(DAT_30063164,DAT_30063168,0x2000);
  return;
}

/* ----------------------------------------------------------------
 * vxprintk_init @ 0x30063040  (примерный размер ~308 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: memset, semBCreate
 * Константы: 0x30063040
 * Данные: DAT_30063144, DAT_30063148, DAT_3006315c, DAT_30063168, DAT_3006316c, DAT_30063170
 * ---------------------------------------------------------------- */
void vxprintk_init(void)

{
  undefined4 uVar1;
  
  uVar1 = semBCreate(1,1);
  *DAT_30063148 = uVar1;
  *DAT_30063144 = (int)DAT_30063168;
  if (((*(int *)*DAT_30063144 != DAT_3006316c) || (*(int *)(*DAT_30063144 + 0x10) != DAT_30063170))
     || (*(int *)(*DAT_30063144 + 0x14) != *DAT_30063144 + 0x240)) {
    memset(DAT_30063168,0,0x4000);
    *(int *)*DAT_30063144 = DAT_3006316c;
    *(undefined4 *)(*DAT_30063144 + 4) = 0;
    *(undefined4 *)(*DAT_30063144 + 8) = 0;
    *(undefined4 *)(*DAT_30063144 + 0xc) = 0;
    *(undefined4 *)(*DAT_30063144 + 0x10) = 0x2000;
    *(int *)(*DAT_30063144 + 0x14) = *DAT_30063144 + 0x240;
  }
  *DAT_3006315c = 1;
  return;
}

/* ----------------------------------------------------------------
 * exchLogSave @ 0x300939CC  (примерный размер ~128 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_TRACE, fwrite
 * Константы: 0x300939CC, 0xFFFFFFFF
 * Данные: DAT_30094940
 * ---------------------------------------------------------------- */
undefined4 exchLogSave(void *param_1,size_t param_2,FILE *param_3)

{
  size_t sVar1;
  undefined4 uVar2;
  
  sVar1 = fwrite(param_1,1,param_2,param_3);
  if (sVar1 == 0) {
    BSP_TRACE(4,0x25,DAT_30094940,0,0,0,0,0,0);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * exchLogPrintf @ 0x30093A4C  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 1
 * Вызывает: fioFormatV
 * Вызывают: HI6451_error_log_save, HI6451_reset_log_save, dloadRecord, exchSave, saveTaskStack
 * Константы: 0x30093A4C
 * Данные: DAT_30094944
 * ---------------------------------------------------------------- */
undefined4
exchLogPrintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar1 = fioFormatV(param_2,&uStack_8,DAT_30094944,param_1);
  return uVar1;
}

/* ----------------------------------------------------------------
 * exchGetMaxFileId @ 0x30093A88  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: exchFileSave
 * Константы: 0x30093A88
 * ---------------------------------------------------------------- */
uint exchGetMaxFileId(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  for (uVar1 = 1; uVar1 < param_2; uVar1 = uVar1 + 1) {
    if (*(uint *)(param_1 + uVar2 * 4) < *(uint *)(param_1 + uVar1 * 4)) {
      uVar2 = uVar1;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * exchAddToFile @ 0x30093BC4  (примерный размер ~244 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 4
 * Вызывает: BSP_TRACE, fclose, fopen, fwrite
 * Вызывают: exchFileSave, omExchFileSave
 * Константы: 0xFFFFFFFF, 0x30093BC4
 * Данные: DAT_30094b20, DAT_30094be4
 * ---------------------------------------------------------------- */
undefined4 exchAddToFile(char *param_1,char *param_2,void *param_3,size_t param_4)

{
  FILE *__s;
  undefined4 uVar1;
  size_t sVar2;
  
  __s = fopen(param_1,param_2);
  if (__s == (FILE *)0x0) {
    BSP_TRACE(4,0x25,DAT_30094b20,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    sVar2 = fwrite(param_3,1,param_4,__s);
    if (sVar2 == param_4) {
      fclose(__s);
      uVar1 = 0;
    }
    else {
      fclose(__s);
      BSP_TRACE(4,0x25,DAT_30094be4,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * exchvsnprintf @ 0x30093CB8  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: vsnprintf
 * Вызывают: exchFileSave
 * Константы: 0x30093CB8
 * ---------------------------------------------------------------- */
int exchvsnprintf(char *param_1,size_t param_2,char *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_4;
  
  uStack_4 = param_4;
  iVar1 = vsnprintf(param_1,param_2,param_3,&uStack_4);
  return iVar1;
}

/* ----------------------------------------------------------------
 * exchFileSave @ 0x30093CFC  (примерный размер ~1704 байт)
 * Модуль: kernel | Вызывают: 6 | Вызывает: 18
 * Вызывает: BSP_TRACE, OSAL_LogMsg, access, closedir, exchAddToFile, exchGetMaxFileId, exchvsnprintf, memcpy, memset, mkdir, opendir, readdir, remove, rename
 *           ...
 * Вызывают: exchDumpPrintkBuffer, exchWriteFile, omExchFileSave, testExcFileSave, testExcMemShow, testExcTaskShow
 * Константы: 0xFFFFFFFF, 0x30093CFC
 * Данные: DAT_30094be8, DAT_30094ca8, DAT_30094cac, DAT_30094cb0, DAT_30094cb4, DAT_30094db4, DAT_30094e74, DAT_30094f74
 * ---------------------------------------------------------------- */
undefined4
exchFileSave(char *param_1,char *param_2,undefined4 param_3,undefined4 param_4,char *param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  size_t sVar7;
  size_t sVar8;
  DIR *__dirp;
  dirent *pdVar9;
  int iVar10;
  uint uVar11;
  __mode_t __mode;
  undefined1 *puVar12;
  uint *puVar13;
  char *pcVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  uint *puVar17;
  char *pcVar19;
  char *pcVar20;
  uint uVar21;
  int iVar22;
  uint local_2b0 [10];
  char acStack_288 [52];
  char acStack_254 [52];
  undefined1 auStack_220 [500];
  uint *puVar18;
  
  uVar21 = 0;
  puVar12 = auStack_220;
  iVar22 = 0xfa;
  puVar16 = DAT_30094be8;
  do {
    puVar15 = puVar16 + 1;
    uVar1 = *puVar16;
    puVar16 = puVar16 + 2;
    uVar2 = *puVar15;
    iVar22 = iVar22 + -1;
    puVar15 = puVar12 + 1;
    *puVar12 = uVar1;
    puVar12 = puVar12 + 2;
    *puVar15 = uVar2;
  } while (iVar22 != 0);
  puVar13 = local_2b0;
  iVar22 = 5;
  puVar17 = DAT_30094ca8;
  do {
    puVar18 = puVar17 + 1;
    uVar5 = *puVar17;
    puVar17 = puVar17 + 2;
    uVar11 = *puVar18;
    iVar22 = iVar22 + -1;
    puVar18 = puVar13 + 1;
    *puVar13 = uVar5;
    puVar13 = puVar13 + 2;
    *puVar18 = uVar11;
  } while (iVar22 != 0);
  pcVar14 = acStack_288;
  iVar22 = 0x19;
  pcVar20 = DAT_30094cac;
  do {
    pcVar19 = pcVar20 + 1;
    cVar3 = *pcVar20;
    pcVar20 = pcVar20 + 2;
    cVar4 = *pcVar19;
    iVar22 = iVar22 + -1;
    pcVar19 = pcVar14 + 1;
    *pcVar14 = cVar3;
    pcVar14 = pcVar14 + 2;
    *pcVar19 = cVar4;
  } while (iVar22 != 0);
  pcVar14 = acStack_254;
  iVar22 = 0x19;
  pcVar20 = DAT_30094cb0;
  do {
    pcVar19 = pcVar20 + 1;
    cVar3 = *pcVar20;
    pcVar20 = pcVar20 + 2;
    cVar4 = *pcVar19;
    iVar22 = iVar22 + -1;
    pcVar19 = pcVar14 + 1;
    *pcVar14 = cVar3;
    pcVar14 = pcVar14 + 2;
    *pcVar19 = cVar4;
  } while (iVar22 != 0);
  if ((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) {
    BSP_TRACE(4,0x25,DAT_30094cb4,0,0,0,0,0,0);
    uVar6 = 0xffffffff;
  }
  else {
    sVar7 = strlen(param_1);
    sVar8 = strlen(param_2);
    if (sVar8 + sVar7 < 0x32) {
      sVar7 = strlen(param_1);
      sVar8 = strlen(param_2);
      if (sVar8 + sVar7 < 0x32) {
        __dirp = opendir(param_1);
        if (__dirp == (DIR *)0x0) {
          mkdir(param_1,__mode);
          uVar21 = 0;
        }
        else {
          do {
            pdVar9 = readdir(__dirp);
            if (pdVar9 != (dirent *)0x0) {
              sVar7 = strlen(param_2);
              iVar22 = strncmp((char *)&pdVar9->d_off,param_2,sVar7);
              if (iVar22 == 0) {
                memcpy(auStack_220 + uVar21 * 0x32,&pdVar9->d_off,0x32);
                stringToHex(auStack_220 + uVar21 * 0x32 + 4,local_2b0 + uVar21);
                if (local_2b0[uVar21] < 2) {
                  uVar21 = uVar21 + 1;
                }
                else {
                  memset(acStack_254,0,0x32);
                  exchvsnprintf(acStack_254,0x32,DAT_30094e74,param_1,auStack_220 + uVar21 * 0x32);
                  OSAL_LogMsg(DAT_30094f74,acStack_254,local_2b0[uVar21],0,0,0,0);
                  remove(acStack_254);
                }
                if (9 < uVar21) {
                  BSP_TRACE(4,0x25,DAT_30094f78,uVar21,0,0,0,0,0);
                  break;
                }
              }
            }
          } while (pdVar9 != (dirent *)0x0);
          closedir(__dirp);
        }
        for (uVar5 = 0; uVar5 < uVar21; uVar5 = uVar5 + 1) {
          iVar22 = exchGetMaxFileId(local_2b0,uVar21);
          if (local_2b0[iVar22] != 0) {
            memset(acStack_254,0,0x32);
            memset(acStack_288,0,0x32);
            exchvsnprintf(acStack_254,0x32,DAT_30094e74,param_1,auStack_220 + iVar22 * 0x32);
            exchvsnprintf(acStack_288,0x32,DAT_300950a0,param_1,param_2,local_2b0[iVar22] + 1);
            iVar10 = rename(acStack_254,acStack_288);
            if (iVar10 != 0) {
              OSAL_LogMsg(DAT_300950a4,acStack_254,acStack_288,0,0,0,0);
            }
            BSP_TRACE(1,0x25,DAT_300950a8,acStack_254,acStack_288,0,0,0,0);
            local_2b0[iVar22] = 0;
          }
        }
        memset(acStack_288,0,0x32);
        exchvsnprintf(acStack_288,0x32,DAT_300950a0,param_1,param_2,0);
        iVar22 = access(acStack_288,0);
        if (iVar22 == 0) {
          exchvsnprintf(acStack_254,0x32,DAT_300950a0,param_1,param_2,1);
          iVar22 = rename(acStack_288,acStack_254);
          if (iVar22 != 0) {
            OSAL_LogMsg(DAT_300951fc,acStack_254,acStack_288,0,0,0,0);
          }
        }
        if (param_5 != (char *)0x0) {
          strcpy(param_5,acStack_288);
        }
        BSP_TRACE(1,0x25,DAT_30095200,acStack_288,0,0,0,0,0);
        iVar22 = exchAddToFile(acStack_288,DAT_30095204,param_3,param_4);
        if (iVar22 == 0) {
          uVar6 = 0;
        }
        else {
          BSP_TRACE(4,0x25,DAT_30095208,0,0,0,0,0,0);
          uVar6 = 0xffffffff;
        }
      }
      else {
        BSP_TRACE(4,0x25,DAT_30094db4,0,0,0,0,0,0);
        uVar6 = 0xffffffff;
      }
    }
    else {
      BSP_TRACE(4,0x25,DAT_30094db4,0,0,0,0,0,0);
      uVar6 = 0xffffffff;
    }
  }
  return uVar6;
}

/* ----------------------------------------------------------------
 * exchWriteFile @ 0x300943A4  (примерный размер ~288 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_TRACE, exchFileSave
 * Вызывают: exchSave
 * Константы: 0x300943A4
 * Данные: DAT_3009534c, DAT_30095350, DAT_30095354
 * ---------------------------------------------------------------- */
void exchWriteFile(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    BSP_TRACE(4,0x25,DAT_3009534c,0,0,0,0,0,0);
  }
  else if (param_4 == 0) {
    BSP_TRACE(4,0x25,DAT_30095350,0,0,0,0,0,0);
  }
  else {
    iVar1 = exchFileSave(param_1,param_2,param_3,param_4,0);
    if (iVar1 != 0) {
      BSP_TRACE(4,0x25,DAT_30095354,0,0,0,0,0,0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * exchPrintBuffer @ 0x300944C4  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 1
 * Вызывает: vsnprintf
 * Вызывают: FUN_30095574, FUN_30095814, exchMemShow, exchRegsShow, exchStackTrace, exchTaskShow, exchTrcPrint
 * Константы: 0x300944C4
 * ---------------------------------------------------------------- */
int exchPrintBuffer(int *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_1[1] == 0) {
    iVar1 = 0;
  }
  else {
    uStack_8 = param_3;
    uStack_4 = param_4;
    iVar1 = vsnprintf((char *)*param_1,param_1[1],param_2,&uStack_8);
    *param_1 = *param_1 + iVar1;
    param_1[1] = param_1[1] - iVar1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30094530 @ 0x30094530  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 2
 * Вызывает: bcopy, taskTcb
 * Вызывают: FUN_30095574, exchRegsShow, exchStackTrace
 * Константы: 0x30094530, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_30094530(undefined4 param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = taskTcb(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (*(int *)(iVar1 + 0x120) == 0) {
      bcopy((void *)(iVar1 + 0x1d0),param_2,0x48);
    }
    else {
      bcopy(*(void **)(iVar1 + 0x120),param_2,0x48);
    }
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * exchStackTrace @ 0x30094594  (примерный размер ~512 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 11
 * Вызывает: FUN_30094530, exchPrintBuffer, taskCont, taskIdSelf, taskIdVerify, taskIsStopped, taskIsSuspended, taskName, taskStop, taskTcb, trcStackTrace
 * Вызывают: exchTaskShow, saveTaskStack
 * Константы: 0xFFFFFFFF, 0x30094594
 * Данные: DAT_30095448, DAT_3009544c, DAT_30095450, DAT_3009555c, DAT_30095560, DAT_30095564, DAT_30095568, DAT_3009556c
 * ---------------------------------------------------------------- */
undefined4 exchStackTrace(int param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_d0;
  int local_cc;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined1 *local_b8;
  undefined4 local_b4;
  undefined1 auStack_b0 [72];
  undefined1 auStack_68 [80];
  
  bVar1 = false;
  iVar4 = 0;
  uVar2 = taskName(param_1);
  exchPrintBuffer(param_2,DAT_30095448,uVar2,param_1);
  if ((param_1 == 0) || (iVar3 = taskIdSelf(), iVar3 == param_1)) {
    exchPrintBuffer(param_2,DAT_3009544c,param_1);
    uVar2 = 0xffffffff;
  }
  else {
    iVar3 = taskIdVerify(param_1);
    if (iVar3 == 0) {
      iVar3 = taskIsStopped(param_1);
      if ((iVar3 == 0) && (iVar3 = taskIsSuspended(param_1), iVar3 == 0)) {
        iVar3 = taskStop(param_1);
        if (iVar3 != 0) {
          if ((*(uint *)(param_1 + 0x98) & 2) == 0) {
            exchPrintBuffer(param_2,DAT_30095560,param_1);
          }
          else {
            exchPrintBuffer(param_2,DAT_3009555c);
          }
          return 0xffffffff;
        }
        bVar1 = true;
      }
      FUN_30094530(param_1,auStack_b0);
      if (*DAT_30095564 != 0) {
        iVar4 = taskTcb(param_1);
        iVar4 = (*(code *)*DAT_30095564)(*(undefined4 *)(iVar4 + 0x94),0);
        if (iVar4 == 0) {
          exchPrintBuffer(param_2,DAT_30095568,param_1);
          return 0xffffffff;
        }
      }
      local_d0 = DAT_3009556c;
      local_bc = 0x14;
      local_b8 = auStack_68;
      local_b4 = 1;
      local_cc = param_1;
      local_c0 = param_2;
      iVar3 = trcStackTrace(auStack_b0,&local_d0);
      if (iVar3 != 0) {
        exchPrintBuffer(param_2,DAT_30095570);
      }
      if (*DAT_30095564 != 0) {
        (*(code *)*DAT_30095564)(iVar4,0);
      }
      if (bVar1) {
        taskCont(param_1);
      }
      exchPrintBuffer(param_2,DAT_30095698);
      uVar2 = 0;
    }
    else {
      exchPrintBuffer(param_2,DAT_30095450,param_1);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * exchReadNVToGetSysTime @ 0x30094800  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: sysClkTicksGet
 * Вызывают: HI6451_reset_log_save, exchSave
 * Константы: 0x30094800
 * ---------------------------------------------------------------- */
undefined4 exchReadNVToGetSysTime(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = sysClkTicksGet();
  *param_1 = uVar1;
  return 0;
}

/* ----------------------------------------------------------------
 * exchDumpPrintkBuffer @ 0x30094818  (примерный размер ~72 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: exchFileSave
 * Вызывают: exchSave
 * Константы: 0x30094818
 * Данные: DAT_300956a4, DAT_300956a8, DAT_300956ac, DAT_300956b0, DAT_300956b4
 * ---------------------------------------------------------------- */
void exchDumpPrintkBuffer(void)

{
  exchFileSave(DAT_300956a4,DAT_300956a8,DAT_300956ac,0x4000,0);
  exchFileSave(DAT_300956a4,DAT_300956b0,DAT_300956b4,0x4000,0);
  return;
}

/* ----------------------------------------------------------------
 * exchSave @ 0x30094860  (примерный размер ~3256 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 14
 * Вызывает: BSP_TRACE, BSP_WDT_HardwareFeed, exchDumpPrintkBuffer, exchLogPrintf, exchReadNVToGetSysTime, exchWriteFile, fclose, fopen, ftell, memcpy, memset, printf, remove, saveTaskStack
 * Вызывают: exchInit, exchSaveAndRebootJob, systemError
 * Константы: 0x30094860
 * Данные: DAT_300956a4, DAT_300956b8, DAT_300956bc, DAT_300956c0, DAT_30095760, DAT_30095764, DAT_3009585c, DAT_30095860
 * ---------------------------------------------------------------- */
void exchSave(void)

{
  bool bVar1;
  int iVar2;
  FILE *__stream;
  long lVar3;
  int iVar4;
  undefined4 local_20;
  
  iVar2 = DAT_300956b8;
  local_20 = 0;
  bVar1 = false;
  __stream = fopen(DAT_300956bc,DAT_300956c0);
  if (__stream == (FILE *)0x0) {
    BSP_TRACE(4,0x25,DAT_30095760,0,0,0,0,0,0);
  }
  else {
    lVar3 = ftell(__stream);
    if (lVar3 == -1) {
      BSP_TRACE(4,0x25,DAT_30095764,0,0,0,0,0,0);
      fclose(__stream);
    }
    else {
      BSP_TRACE(1,0x25,DAT_3009585c,lVar3,0,0,0,0,0);
      if (0x3ffff < lVar3) {
        BSP_TRACE(4,0x25,DAT_30095860,0,0,0,0,0,0);
        fclose(__stream);
        iVar4 = remove(DAT_300956bc);
        if (iVar4 != 0) {
          BSP_TRACE(4,0x25,DAT_30095864,0,0,0,0,0,0);
          goto LAB_3009536c;
        }
        __stream = fopen(DAT_300956bc,DAT_300956c0);
        if (__stream == (FILE *)0x0) {
          BSP_TRACE(4,0x25,DAT_30095760,0,0,0,0,0,0);
          goto LAB_3009536c;
        }
      }
      iVar4 = exchReadNVToGetSysTime(&local_20);
      if (iVar4 != 0) {
        BSP_TRACE(4,0x25,DAT_300959b4,0,0,0,0,0,0);
        local_20 = 0;
      }
      if (*(int *)(*DAT_300959b8 + 0x24) == 0) {
        if (*DAT_300959bc == 0) {
          exchLogPrintf(__stream,DAT_300959c8,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                        *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                        *(undefined4 *)(*DAT_300959b8 + 0x40));
          saveTaskStack(*(undefined4 *)(*DAT_300959b8 + 0x30),__stream);
          printf(DAT_300959c8,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                 *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                 *(undefined4 *)(*DAT_300959b8 + 0x40));
        }
        else {
          exchLogPrintf(__stream,DAT_300959c0,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20);
          printf(DAT_300959c4,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20);
        }
      }
      else if (*(int *)(*DAT_300959b8 + 0x24) == 1) {
        if (*DAT_30095ab8 == DAT_30095abc) {
          exchLogPrintf(__stream,DAT_30095ac0,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                        *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                        *(undefined4 *)(*DAT_300959b8 + 0x40));
          printf(DAT_30095ac0,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                 *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                 *(undefined4 *)(*DAT_300959b8 + 0x40));
        }
        else if (*DAT_30095b60 == DAT_30095b64) {
          exchLogPrintf(__stream,DAT_30095b68,*(undefined4 *)(iVar2 + 0xac),local_20,
                        *(undefined4 *)(iVar2 + 0x38),*(undefined4 *)(iVar2 + 0x3c),
                        *(undefined4 *)(iVar2 + 0x40));
          printf(DAT_30095b68,*(undefined4 *)(iVar2 + 0xac),local_20,*(undefined4 *)(iVar2 + 0x38),
                 *(undefined4 *)(iVar2 + 0x3c),*(undefined4 *)(iVar2 + 0x40));
        }
        else {
          exchLogPrintf(__stream,DAT_30095c04,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                        *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                        *(undefined4 *)(*DAT_300959b8 + 0x40));
          printf(DAT_30095c04,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                 *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                 *(undefined4 *)(*DAT_300959b8 + 0x40));
        }
      }
      else if (*(int *)(*DAT_300959b8 + 0x24) == 3) {
        if (*DAT_30095ab8 == DAT_30095abc) {
          exchLogPrintf(__stream,DAT_30095cc8,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                        *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                        *(undefined4 *)(*DAT_300959b8 + 0x40));
          printf(DAT_30095cc8,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                 *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                 *(undefined4 *)(*DAT_300959b8 + 0x40));
        }
        else if (*DAT_30095b60 == DAT_30095b64) {
          exchLogPrintf(__stream,DAT_30095ccc,*(undefined4 *)(iVar2 + 0xac),local_20,
                        *(undefined4 *)(iVar2 + 0x38),*(undefined4 *)(iVar2 + 0x3c),
                        *(undefined4 *)(iVar2 + 0x40));
          printf(DAT_30095ccc,*(undefined4 *)(iVar2 + 0xac),local_20,*(undefined4 *)(iVar2 + 0x38),
                 *(undefined4 *)(iVar2 + 0x3c),*(undefined4 *)(iVar2 + 0x40));
        }
        else {
          exchLogPrintf(__stream,DAT_30095df4,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                        *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                        *(undefined4 *)(*DAT_300959b8 + 0x40));
          printf(DAT_30095df4,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                 *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                 *(undefined4 *)(*DAT_300959b8 + 0x40));
        }
      }
      else if (*(int *)(*DAT_300959b8 + 0x24) == 0xaa) {
        if (*DAT_30095ab8 == DAT_30095abc) {
          exchLogPrintf(__stream,DAT_30095ed4,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                        *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                        *(undefined4 *)(*DAT_300959b8 + 0x40));
          printf(DAT_30095ed4,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                 *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                 *(undefined4 *)(*DAT_300959b8 + 0x40));
        }
        else if (*DAT_30095b60 == DAT_30095b64) {
          exchLogPrintf(__stream,DAT_30095ed8,*(undefined4 *)(iVar2 + 0xac),local_20,
                        *(undefined4 *)(iVar2 + 0x38),*(undefined4 *)(iVar2 + 0x3c),
                        *(undefined4 *)(iVar2 + 0x40));
          printf(DAT_30095ed8,*(undefined4 *)(iVar2 + 0xac),local_20,*(undefined4 *)(iVar2 + 0x38),
                 *(undefined4 *)(iVar2 + 0x3c),*(undefined4 *)(iVar2 + 0x40));
        }
        else {
          exchLogPrintf(__stream,DAT_30095ff4,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                        *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                        *(undefined4 *)(*DAT_300959b8 + 0x40));
          printf(DAT_30095ff4,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                 *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                 *(undefined4 *)(*DAT_300959b8 + 0x40));
        }
      }
      else if ((*(int *)(*DAT_300959b8 + 0x24) == 0xff) && (*(int *)(*DAT_300959b8 + 0x114) == 1)) {
        exchLogPrintf(__stream,DAT_30095ff8,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                      *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                      *(undefined4 *)(*DAT_300959b8 + 0x40));
        printf(DAT_30095ff8,*(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
               *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
               *(undefined4 *)(*DAT_300959b8 + 0x40));
      }
      else {
        exchLogPrintf(__stream,DAT_300960fc,*(undefined4 *)(*DAT_300959b8 + 0x24),
                      *(undefined4 *)(*DAT_300959b8 + 0xac),local_20,
                      *(undefined4 *)(*DAT_300959b8 + 0x38),*(undefined4 *)(*DAT_300959b8 + 0x3c),
                      *(undefined4 *)(*DAT_300959b8 + 0x40));
        printf(DAT_300960fc,*(undefined4 *)(*DAT_300959b8 + 0x24),
               *(undefined4 *)(*DAT_300959b8 + 0xac),local_20,*(undefined4 *)(*DAT_300959b8 + 0x38),
               *(undefined4 *)(*DAT_300959b8 + 0x3c),*(undefined4 *)(*DAT_300959b8 + 0x40));
      }
      memset(DAT_30096100,0,0x2c);
      DAT_30096100[2] = local_20;
      DAT_30096100[3] = *(undefined4 *)(*DAT_300959b8 + 0xac);
      DAT_30096100[1] = DAT_30096104;
      *DAT_30096100 = 0x2c;
      DAT_30096100[4] = *(undefined4 *)(*DAT_300959b8 + 0x24);
      DAT_30096100[5] = *(undefined4 *)(*DAT_300959b8 + 0x38);
      DAT_30096100[6] = *(undefined4 *)(*DAT_300959b8 + 0x3c);
      DAT_30096100[7] = *(undefined4 *)(*DAT_300959b8 + 0x40);
      fclose(__stream);
    }
  }
LAB_3009536c:
  if ((*DAT_30095ab8 == DAT_30095abc) || (*DAT_30095b60 == DAT_30095b64)) {
    bVar1 = true;
  }
  if (*(int *)(*DAT_300959b8 + 0x24) != 0) {
    bVar1 = true;
  }
  if ((*(int *)(*DAT_300959b8 + 0x24) == 0xff) && (*(int *)(*DAT_300959b8 + 0x114) == 1)) {
    bVar1 = false;
  }
  if (bVar1) {
    if ((*(int *)(*DAT_300959b8 + 0x24) == 0xfe) || (*(int *)(*DAT_300959b8 + 0x38) == -1)) {
      memcpy(DAT_30096314,(void *)*DAT_300959b8,0x11c);
      memcpy(DAT_30096318,DAT_30095ab8,0x100);
      exchWriteFile(DAT_300956a4,DAT_3009631c,DAT_30096314,0x5f000);
    }
    else {
      memcpy(DAT_30096314,(void *)*DAT_300959b8,0x11c);
      memcpy(DAT_30096318,DAT_30095ab8,0x100);
      exchWriteFile(DAT_30096320,DAT_30096324,DAT_30096314,0x5f000);
    }
    exchDumpPrintkBuffer();
  }
  if (*(char *)(*DAT_300959b8 + 0x29) == 'U') {
    exchWriteFile(DAT_30096320,DAT_30096328,DAT_3009632c,0x2000);
    exchWriteFile(DAT_30096320,DAT_30096330,DAT_30096334,0x2000);
  }
  if (*(char *)(*DAT_300959b8 + 0x2a) == 'U') {
    exchWriteFile(DAT_30096320,DAT_30096338,DAT_3009633c,0x8000);
    exchWriteFile(DAT_30096320,DAT_30096340,DAT_30096344,0x8000);
  }
  BSP_WDT_HardwareFeed(0);
  return;
}

/* ----------------------------------------------------------------
 * exchHookFuncDelete @ 0x30095518  (примерный размер ~92 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 5
 * Вызывает: omTimerGet, strcpy, subVICIntHookDel, taskSwitchHookDelete, vicIntLvlChgHookDel
 * Вызывают: exchWdtHook, systemError
 * Константы: 0x30095518
 * Данные: DAT_300959b8, DAT_30096348
 * ---------------------------------------------------------------- */
void exchHookFuncDelete(char *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(*DAT_300959b8 + 0x104);
  uVar1 = omTimerGet();
  *puVar2 = uVar1;
  puVar2[1] = param_2;
  strcpy((char *)(puVar2 + 2),param_1);
  taskSwitchHookDelete(DAT_30096348);
  vicIntLvlChgHookDel();
  subVICIntHookDel();
  return;
}

/* ----------------------------------------------------------------
 * FUN_30095574 @ 0x30095574  (примерный размер ~672 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_30094530, exchPrintBuffer, sprintf, strlen, taskIdSelf, taskStatusString
 * Вызывают: FUN_30095814
 * Константы: 0x30095574
 * Данные: DAT_30096448, DAT_3009644c, DAT_30096450, DAT_30096454, DAT_30096458, DAT_3009645c, DAT_30096460, DAT_30096534
 * ---------------------------------------------------------------- */
undefined4 FUN_30095574(int *param_1,int param_2,undefined4 param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 local_7c;
  undefined4 local_78;
  int local_74;
  char local_70;
  char local_6f;
  char local_6e;
  char local_6d;
  undefined1 auStack_6c [12];
  undefined1 auStack_60 [52];
  undefined4 local_2c;
  undefined4 local_24;
  
  local_78 = DAT_30096448;
  local_74 = 0;
  local_70 = *DAT_3009644c;
  local_6f = DAT_3009644c[1];
  local_6e = DAT_3009644c[2];
  local_6d = DAT_3009644c[3];
  taskStatusString(*param_1,auStack_6c);
  sVar1 = strlen((char *)(param_1 + 0x11));
  if (sVar1 < 0xb) {
    exchPrintBuffer(param_3,DAT_30096450,param_1 + 0x11);
  }
  else {
    exchPrintBuffer(param_3,DAT_30096454,param_1 + 0x11);
  }
  if (((*DAT_30096458 != 0) && (*DAT_3009645c != 0)) &&
     (iVar2 = (*(code *)*DAT_30096458)(*DAT_3009645c,0,param_1[4],5,5,&local_7c), iVar2 == 0)) {
    (*(code *)*DAT_30096460)(local_7c,&local_78);
    (*(code *)*DAT_30096534)(local_7c,&local_74);
  }
  if (param_1[4] == local_74) {
    exchPrintBuffer(param_3,DAT_30096538,local_78);
  }
  else {
    exchPrintBuffer(param_3,DAT_3009653c,param_1[4]);
  }
  FUN_30094530(*param_1,auStack_60);
  if (param_2 == 2) {
    if (param_1[0x21] != -1) {
      sprintf(&local_70,DAT_3009663c,param_1[0x21]);
    }
    iVar2 = taskIdSelf();
    if (iVar2 == *param_1) {
      local_24 = DAT_30096640;
    }
    exchPrintBuffer(param_3,DAT_30096644,*param_1,param_1[1],auStack_6c,local_24,local_2c,
                    param_1[0xc],&local_70);
  }
  else {
    iVar2 = taskIdSelf();
    if (iVar2 == *param_1) {
      local_24 = DAT_30096640;
    }
    exchPrintBuffer(param_3,DAT_30096648,*param_1,param_1[1],auStack_6c,local_24,local_2c,
                    param_1[0xc],param_1[0xd]);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30095814 @ 0x30095814  (примерный размер ~376 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_30095574, exchPrintBuffer, objNamePtrGet, taskInfoGet, taskOptionsString
 * Вызывают: exchTaskShow
 * Константы: 0x30095814
 * Данные: DAT_3009664c, DAT_30096718, DAT_3009671c, DAT_30096720, DAT_30096724, DAT_30096728, DAT_3009672c, DAT_30096730
 * ---------------------------------------------------------------- */
undefined4 FUN_30095814(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_1a0 [12];
  uint local_194;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined1 auStack_114 [256];
  
  iVar1 = taskInfoGet(param_1,auStack_1a0);
  if (iVar1 == 0) {
    taskOptionsString(param_1,auStack_114);
    exchPrintBuffer(param_2,DAT_30096718);
    FUN_30095574(auStack_1a0,4,param_2);
    exchPrintBuffer(param_2,DAT_3009671c,local_188,local_184,local_180);
    if ((local_194 & 0x100) == 0) {
      exchPrintBuffer(param_2,DAT_30096728,local_178,local_174,local_180);
    }
    else {
      exchPrintBuffer(param_2,DAT_30096720,DAT_30096724,DAT_30096724,local_180);
    }
    exchPrintBuffer(param_2,DAT_3009672c,local_134,local_130,local_12c,local_138);
    if ((local_194 & 0x100) == 0) {
      exchPrintBuffer(param_2,DAT_30096734,local_128,local_124,local_12c,local_138);
      uVar3 = local_12c;
      uVar4 = local_138;
    }
    else {
      exchPrintBuffer(param_2,DAT_30096730,DAT_30096724,DAT_30096724,local_12c,local_138);
      uVar3 = local_12c;
      uVar4 = local_138;
    }
    uVar2 = objNamePtrGet(local_13c);
    exchPrintBuffer(param_2,DAT_30096834,local_13c,uVar2,uVar3,uVar4);
    exchPrintBuffer(param_2,DAT_30096838,local_194,auStack_114);
  }
  else {
    exchPrintBuffer(param_2,DAT_3009664c);
  }
  return 1;
}

/* ----------------------------------------------------------------
 * exchMemShow @ 0x3009598C  (примерный размер ~736 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 4
 * Вызывает: __div32, bfill, exchPrintBuffer, isprint
 * Вызывают: exchRegsShow, testExcMemShow
 * Константы: 0x3009598C, 0xFFFFFFF0
 * Данные: DAT_3009683c, DAT_30096840, DAT_30096844, DAT_30096848, DAT_3009684c, DAT_30096850, DAT_300969a0, DAT_300969a4
 * ---------------------------------------------------------------- */
undefined4 exchMemShow(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  
  *(undefined1 *)(DAT_3009683c + 0x10) = 0;
  puVar5 = (uint *)(param_1 & ~(param_3 - 1U));
  bfill(DAT_3009683c,0x10,0x2e);
  exchPrintBuffer(param_4,DAT_30096840);
  exchPrintBuffer(param_4,DAT_30096844,(uint)puVar5 & 0xfffffff0);
  for (iVar4 = 0; iVar1 = __div32((uint)puVar5 & 0xf,param_3), puVar6 = puVar5, iVar4 < iVar1;
      iVar4 = iVar4 + 1) {
    exchPrintBuffer(param_4,DAT_30096848,param_3 << 1,DAT_3009684c);
    bfill(iVar4 * param_3 + DAT_3009683c,param_3 << 1,0x20);
  }
  for (; 0 < param_2; param_2 = param_2 + -1) {
    iVar1 = __div32(0x10,param_3);
    if (iVar1 == iVar4) {
      exchPrintBuffer(param_4,DAT_30096850,DAT_3009683c,puVar6);
      bfill(DAT_3009683c,0x10,0x2e);
      iVar4 = 0;
    }
    if (param_3 == 2) {
      local_3c = (uint)(ushort)*puVar5;
      local_38 = 0;
      exchPrintBuffer(param_4,DAT_300969a0,local_3c);
    }
    else if (param_3 == 4) {
      local_3c = *puVar5;
      local_38 = 0;
      exchPrintBuffer(param_4,DAT_300969a4,local_3c);
    }
    else if (param_3 == 8) {
      local_3c = *puVar5;
      local_38 = puVar5[1];
      local_34 = local_3c;
      local_30 = local_38;
      local_2c = local_3c;
      local_28 = local_38;
      exchPrintBuffer(param_4,DAT_300969a8,local_3c,local_38);
    }
    else {
      local_3c = (uint)(byte)*puVar5;
      local_38 = 0;
      exchPrintBuffer(param_4,DAT_300969ac,local_3c);
    }
    exchPrintBuffer(param_4,DAT_3009684c);
    puVar3 = &local_3c;
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      if (((byte)*puVar3 == 0x20) ||
         (((byte)*puVar3 < 0x80 && (iVar2 = isprint((uint)(byte)*puVar3), iVar2 != 0)))) {
        *(byte *)(iVar4 * param_3 + DAT_3009683c + iVar1) = (byte)*puVar3;
      }
      puVar3 = (uint *)((int)puVar3 + 1);
    }
    puVar5 = (uint *)((int)puVar5 + param_3);
    iVar4 = iVar4 + 1;
    puVar6 = (uint *)((int)puVar6 + param_3);
  }
  for (; iVar1 = __div32(0x10,param_3), iVar4 < iVar1; iVar4 = iVar4 + 1) {
    exchPrintBuffer(param_4,DAT_30096848,param_3 << 1,DAT_3009684c);
  }
  exchPrintBuffer(param_4,DAT_30096b08,DAT_3009683c);
  return 0;
}

/* ----------------------------------------------------------------
 * exchRegsShow @ 0x30095C6C  (примерный размер ~416 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 8
 * Вызывает: FUN_30094530, exchMemShow, exchPrintBuffer, taskIdSelf, taskIdVerify, taskTcb, vmPageSizeGet, vmStateGet
 * Вызывают: exchTaskShow, testExcTaskShow
 * Константы: 0xFFFFFFFF, 0x30095C6C
 * Данные: DAT_30096b0c, DAT_30096b10, DAT_30096b14, DAT_30096b18, DAT_30096b1c, DAT_30096b20, DAT_30096b24, DAT_30096c24
 * ---------------------------------------------------------------- */
undefined4 exchRegsShow(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint local_20;
  
  iVar1 = taskTcb(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else if ((param_1 == 0) || (iVar1 = taskIdSelf(), iVar1 == param_1)) {
    exchPrintBuffer(param_2,DAT_30096b0c,param_1);
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = taskIdVerify(param_1);
    if (iVar1 == 0) {
      iVar1 = FUN_30094530(param_1,DAT_30096b14);
      if (iVar1 == 0) {
        for (iVar1 = 0; *(int *)(DAT_30096b18 + iVar1 * 8) != 0; iVar1 = iVar1 + 1) {
          if (**(char **)(DAT_30096b18 + iVar1 * 8) != '\0') {
            exchPrintBuffer(param_2,DAT_30096b1c);
            piVar5 = (int *)(DAT_30096b14 + *(int *)(DAT_30096b20 + iVar1 * 8));
            exchPrintBuffer(param_2,*DAT_30096b24,*(undefined4 *)(DAT_30096b18 + iVar1 * 8),*piVar5)
            ;
            exchPrintBuffer(param_2,DAT_30096b1c);
            if (*piVar5 + 0xcfffffffU < DAT_30096c24) {
              iVar3 = vmPageSizeGet();
              iVar6 = *piVar5;
              iVar4 = vmPageSizeGet();
              iVar3 = vmStateGet(0,(iVar3 + iVar6) - 1U & ~(iVar4 - 1U),&local_20);
              if ((iVar3 == 0) && ((local_20 & 0x41) == 0x41)) {
                exchMemShow(*piVar5,0x20,4,param_2);
              }
            }
          }
        }
        uVar2 = exchPrintBuffer(param_2,DAT_30096b1c);
      }
      else {
        uVar2 = 0xffffffff;
      }
    }
    else {
      exchPrintBuffer(param_2,DAT_30096b10,param_1);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * exchTaskShow @ 0x30095E0C  (примерный размер ~228 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 5
 * Вызывает: FUN_30095814, exchPrintBuffer, exchRegsShow, exchStackTrace, taskIdListGet
 * Вызывают: exchTaskShowJob, testExcTaskShow
 * Константы: 0x30095E0C
 * Данные: DAT_30096c28, DAT_30096c2c, DAT_30096c30, DAT_30096c34, DAT_30096d6c
 * ---------------------------------------------------------------- */
undefined4 exchTaskShow(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  exchPrintBuffer(param_2,DAT_30096c28);
  exchPrintBuffer(param_2,DAT_30096c2c);
  FUN_30095814(param_1,param_2);
  exchStackTrace(param_1,param_2);
  exchRegsShow(param_1,param_2);
  exchPrintBuffer(param_2,DAT_30096c2c);
  iVar1 = taskIdListGet(DAT_30096c30,100);
  exchPrintBuffer(param_2,DAT_30096c34,iVar1);
  for (iVar3 = 0; iVar3 < iVar1; iVar3 = iVar3 + 1) {
    iVar2 = *(int *)(DAT_30096c30 + iVar3 * 4);
    FUN_30095814(*(undefined4 *)(DAT_30096c30 + iVar3 * 4),param_2);
    if (*(int *)(iVar2 + 0x1b4) != 0) {
      exchStackTrace(param_1,param_2);
    }
  }
  exchPrintBuffer(param_2,DAT_30096d6c);
  return 0;
}

/* ----------------------------------------------------------------
 * exchTaskShowJob @ 0x30095EF0  (примерный размер ~72 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: exchTaskShow, memset
 * Вызывают: systemError
 * Константы: 0x30095EF0
 * Данные: DAT_30096d70
 * ---------------------------------------------------------------- */
void exchTaskShowJob(undefined4 param_1,void *param_2,size_t param_3)

{
  void *local_1c;
  size_t local_18;
  undefined4 local_14;
  
  local_14 = DAT_30096d70;
  local_1c = param_2;
  local_18 = param_3;
  memset(param_2,0,param_3);
  exchTaskShow(param_1,&local_1c);
  return;
}

/* ----------------------------------------------------------------
 * exchWdtHook @ 0x300964B8  (примерный размер ~280 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: BSP_WDT_HardwareFeed, CvInfoStart, exchHookFuncDelete, systemError, wdtFeedDisableSet
 * Константы: 0x300964B8
 * Данные: DAT_30096d78, DAT_30096d80, DAT_30096d84, DAT_30096e94, DAT_3009736c, DAT_30097370
 * ---------------------------------------------------------------- */
void exchWdtHook(void)

{
  if (*DAT_30096d80 == 1) {
    if ((*DAT_30096e94 == 0) || ((DAT_30096e94[1] & 1U) == 0)) {
      *(undefined4 *)(*DAT_30096d84 + 0x24) = 3;
      systemError(0x25,3,0,0,0);
    }
    else if (*(char *)(*DAT_30096d84 + 0x2c) == '\0') {
      BSP_WDT_HardwareFeed(0);
      exchHookFuncDelete(DAT_30096d78,DAT_3009736c);
      wdtFeedDisableSet(0,1);
      CvInfoStart((uint)((ulonglong)DAT_30097370 * (ulonglong)(uint)DAT_30096e94[3] >> 0x24),0,
                  (int)((ulonglong)DAT_30097370 * (ulonglong)(uint)DAT_30096e94[3]));
      *(undefined1 *)(*DAT_30096d84 + 0x2c) = 1;
    }
    else {
      *(undefined4 *)(*DAT_30096d84 + 0x24) = 3;
      systemError(0x25,3,0,0,0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * exchStackFlowHook @ 0x300965D0  (примерный размер ~172 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: systemError, taskIdVerify
 * Константы: 0x300965D0
 * Данные: DAT_30096d80, DAT_30096d84, DAT_30097410
 * ---------------------------------------------------------------- */
void exchStackFlowHook(int param_1)

{
  int iVar1;
  
  if ((((*DAT_30096d80 == 1) && (iVar1 = taskIdVerify(param_1), iVar1 == 0)) &&
      ((*(uint *)(param_1 + 0x98) & 0x100) == 0)) &&
     (iVar1 = **(int **)(param_1 + 200), iVar1 != DAT_30097410)) {
    *(int *)(*DAT_30096d84 + 0xa0) = param_1;
    *(undefined4 *)(*DAT_30096d84 + 0x24) = 4;
    systemError(0x25,4,iVar1,0,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * exchTaskSwitchHook @ 0x3009667C  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: QueueLoopIn, omTimerGet, omTimerTickGet, taskIdVerify
 * Константы: 0x3009667C
 * Данные: DAT_30096d80, DAT_30096d84, DAT_30097454
 * ---------------------------------------------------------------- */
void exchTaskSwitchHook(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*DAT_30096d80 == 1) && (iVar1 = taskIdVerify(param_2), iVar1 == 0)) {
    QueueLoopIn(DAT_30097454,param_2);
    uVar2 = omTimerGet();
    QueueLoopIn(DAT_30097454,uVar2);
    *(undefined4 *)(*DAT_30096d84 + 0xa0) = param_2;
    uVar2 = omTimerTickGet();
    *(undefined4 *)(*DAT_30096d84 + 0xa4) = uVar2;
  }
  return;
}

/* ----------------------------------------------------------------
 * exchIntHook @ 0x300966E0  (примерный размер ~148 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: QueueLoopIn, omTimerGet, omTimerTickGet
 * Константы: 0x300966E0
 * Данные: DAT_30096d80, DAT_30096d84, DAT_30097458, DAT_3009745c, DAT_30097460
 * ---------------------------------------------------------------- */
void exchIntHook(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (*DAT_30096d80 == 1) {
    if (*DAT_30097458 == 0) {
      QueueLoopIn(DAT_3009745c,DAT_30097460);
    }
    else {
      QueueLoopIn(DAT_3009745c,param_1);
    }
    uVar1 = omTimerGet();
    QueueLoopIn(DAT_3009745c,uVar1);
    *(undefined4 *)(*DAT_30096d84 + 0xa8) = param_1;
    uVar1 = omTimerTickGet();
    *(undefined4 *)(*DAT_30096d84 + 0xac) = uVar1;
  }
  return;
}

/* ----------------------------------------------------------------
 * exchSubIntHook @ 0x30096774  (примерный размер ~120 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: QueueLoopIn, omTimerGet, omTimerTickGet
 * Константы: 0x30096774
 * Данные: DAT_30096d80, DAT_30096d84, DAT_3009745c, DAT_30097460, DAT_30097464
 * ---------------------------------------------------------------- */
void exchSubIntHook(int param_1)

{
  undefined4 uVar1;
  
  if (*DAT_30096d80 == 1) {
    if (*DAT_30097464 == 0) {
      QueueLoopIn(DAT_3009745c,DAT_30097460);
    }
    else {
      QueueLoopIn(DAT_3009745c,param_1 + 0x400);
    }
    uVar1 = omTimerGet();
    QueueLoopIn(DAT_3009745c,uVar1);
    *(int *)(*DAT_30096d84 + 0xa8) = param_1;
    uVar1 = omTimerTickGet();
    *(undefined4 *)(*DAT_30096d84 + 0xac) = uVar1;
  }
  return;
}

/* ----------------------------------------------------------------
 * exchExcHook @ 0x300967EC  (примерный размер ~236 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: memcpy, omTimerTickGet, systemError, taskIdVerify
 * Константы: 0x300967EC
 * Данные: DAT_30096d80, DAT_30096d84
 * ---------------------------------------------------------------- */
void exchExcHook(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*DAT_30096d80 == 1) && (iVar1 = taskIdVerify(param_1), iVar1 == 0)) {
    *(undefined4 *)(*DAT_30096d84 + 0x48) = param_2;
    *(undefined4 *)(*DAT_30096d84 + 0x8c) = *param_3;
    *(undefined4 *)(*DAT_30096d84 + 0x4c) = param_3[1];
    *(int *)(*DAT_30096d84 + 0xa0) = param_1;
    uVar2 = omTimerTickGet();
    *(undefined4 *)(*DAT_30096d84 + 0xa4) = uVar2;
    memcpy((void *)(*DAT_30096d84 + 0x50),*(void **)(param_1 + 0x120),0x3c);
    *(undefined4 *)(*DAT_30096d84 + 0x24) = 1;
    systemError(0x25,1,0,0,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * exchCheckReboot @ 0x300968D8  (примерный размер ~72 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: exchInit
 * Константы: 0x300968D8
 * Данные: DAT_30096d84, DAT_30097468
 * ---------------------------------------------------------------- */
undefined4 exchCheckReboot(void)

{
  if (*(int *)(*DAT_30096d84 + 0x118) != DAT_30097468) {
    *(undefined4 *)(*DAT_30096d84 + 0x24) = 0;
  }
  *(int *)(*DAT_30096d84 + 0x118) = DAT_30097468;
  return *(undefined4 *)(*DAT_30096d84 + 0x24);
}

/* ----------------------------------------------------------------
 * exchReadConfig @ 0x30096920  (примерный размер ~196 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: BSP_TRACE, NVM_Read, printf
 * Вызывают: exchInit
 * Константы: 0xFFFFFFFF, 0x30096920
 * Данные: DAT_30096e94, DAT_3009746c, DAT_30097470, DAT_30097474
 * ---------------------------------------------------------------- */
undefined4 exchReadConfig(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = NVM_Read(0xd100,DAT_30096e94,0x10);
  printf(DAT_3009746c,DAT_30096e94[1],iVar1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *DAT_30096e94 = 1;
    DAT_30096e94[1] = 0xffffffff;
    DAT_30096e94[3] = DAT_30097470;
    BSP_TRACE(4,0x25,DAT_30097474,iVar1,0,0,0,0,0);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * exchClear @ 0x30096A88  (примерный размер ~200 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: memset
 * Константы: 0x30096A88
 * Данные: DAT_30096d84, DAT_30097184, DAT_3009718c, DAT_30097468, DAT_30097478, DAT_3009747c, DAT_30097480
 * ---------------------------------------------------------------- */
void exchClear(void)

{
  memset((void *)*DAT_30096d84,0,0x11c);
  memset(DAT_3009718c,0,0x5f000);
  memset(DAT_30097184,0,0x100);
  memset(DAT_30097478,0,0x2000);
  memset(DAT_3009747c,0,0x8000);
  *DAT_30097184 = 0;
  *DAT_30097480 = 0;
  *(undefined4 *)(*DAT_30096d84 + 0x24) = 0xff;
  *(undefined4 *)(*DAT_30096d84 + 0x114) = 0;
  *(undefined4 *)(*DAT_30096d84 + 0x118) = DAT_30097468;
  return;
}

/* ----------------------------------------------------------------
 * exchInit @ 0x30096B50  (примерный размер ~864 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 14
 * Вызывает: BSP_OM_GetDloadVer, BSP_TRACE, QueueInit, excHookAdd, exchCheckReboot, exchReadConfig, exchSave, memcpy, memset, mkdir, strlen, subVICIntHook, taskSwitchHookAdd, vicIntLvlChgHookAdd
 * Константы: 0x30096B50
 * Данные: DAT_30096d84, DAT_30096e94, DAT_30097184, DAT_3009718c, DAT_30097454, DAT_3009745c, DAT_30097468, DAT_30097478
 * ---------------------------------------------------------------- */
void exchInit(void)

{
  size_t __n;
  __mode_t extraout_r1;
  __mode_t __mode;
  __mode_t __mode_00;
  undefined8 uVar1;
  
  exchCheckReboot();
  uVar1 = exchReadConfig();
  __mode = (__mode_t)((ulonglong)uVar1 >> 0x20);
  if ((int)uVar1 != 0) {
    BSP_TRACE(4,0x25,DAT_30097484,0,0,0,0,0,0);
    __mode = extraout_r1;
  }
  if (*DAT_30096e94 != 0) {
    mkdir(DAT_30097488,__mode);
    mkdir(DAT_3009748c,__mode_00);
    exchSave();
    memset((void *)*DAT_30096d84,0,0x11c);
    memset(DAT_3009718c,0,0x5f000);
    memset(DAT_30097184,0,0x100);
    memset(DAT_30097478,0,0x2000);
    memset(DAT_3009747c,0,0x8000);
    *DAT_30097184 = 0;
    *DAT_30097480 = 0;
    *DAT_30097490 = DAT_30097494;
    *(undefined1 *)*DAT_30096d84 = 3;
    BSP_OM_GetDloadVer(*DAT_30096d84 + 4,0x20);
    memset(DAT_30097498,0,0x20);
    __n = strlen(DAT_3009749c);
    memcpy(DAT_30097498,DAT_300974a0,__n);
    *(undefined4 *)(*DAT_30096d84 + 0xc4) = DAT_300974a4;
    *(undefined4 *)(*DAT_30096d84 + 200) = DAT_300974a8;
    *(undefined4 *)(*DAT_30096d84 + 0xcc) = DAT_300974ac;
    *(undefined4 *)(*DAT_30096d84 + 0xd0) = DAT_3009745c;
    *(undefined4 *)(*DAT_30096d84 + 0xd8) = DAT_30097454;
    *(undefined4 *)(*DAT_30096d84 + 0xe0) = DAT_300974b0;
    *(undefined4 *)(*DAT_30096d84 + 0xdc) = DAT_300974b4;
    *(undefined4 *)(*DAT_30096d84 + 0xe4) = DAT_300974b8;
    *(undefined4 *)(*DAT_30096d84 + 0xe8) = DAT_300974bc;
    *(void **)(*DAT_30096d84 + 0xf0) = DAT_30097478;
    *(void **)(*DAT_30096d84 + 0xf4) = DAT_3009747c;
    *(undefined4 *)(*DAT_30096d84 + 0xfc) = DAT_300974c0;
    *(undefined4 *)(*DAT_30096d84 + 0x100) = DAT_300974c4;
    *(undefined4 *)(*DAT_300974c8 + 0xec) = DAT_300974cc;
    *(undefined4 *)(*DAT_300974c8 + 0xb8) = 0x32000;
    *(undefined4 *)(*DAT_300974c8 + 0x104) = DAT_300974d0;
    *(undefined4 *)(*DAT_300974c8 + 0x24) = 0xff;
    *(undefined4 *)(*DAT_300974c8 + 0x114) = 0;
    *(undefined4 *)(*DAT_300974c8 + 0x118) = DAT_30097468;
    *DAT_300974d4 = 1;
    QueueInit(*(undefined4 *)(*DAT_300974c8 + 0xd0),DAT_300974d8);
    QueueInit(*(undefined4 *)(*DAT_300974c8 + 0xd8),DAT_300974dc);
    if ((DAT_30096e94[1] & 0x10U) != 0) {
      taskSwitchHookAdd(DAT_300974e0);
    }
    if ((DAT_30096e94[1] & 8U) != 0) {
      taskSwitchHookAdd(DAT_300974e4);
    }
    if ((DAT_30096e94[1] & 0x20U) != 0) {
      vicIntLvlChgHookAdd(DAT_300974e8);
      subVICIntHook(DAT_300974ec);
    }
    if ((DAT_30096e94[1] & 2U) != 0) {
      excHookAdd(DAT_300974f0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * exchRebootRecord @ 0x30096EB0  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: cacheFlush, memcpy
 * Константы: 0x30096EB0
 * Данные: DAT_300974a4, DAT_300974c8, DAT_300974f4, DAT_300974f8
 * ---------------------------------------------------------------- */
void exchRebootRecord(void)

{
  if ((*(uint *)(DAT_300974f4 + 4) & 4) != 0) {
    memcpy(DAT_300974a4,DAT_300974f8,0x200);
  }
  cacheFlush(1,*DAT_300974c8,0x5f000);
  return;
}

/* ----------------------------------------------------------------
 * exchRebootSet @ 0x30096EEC  (примерный размер ~168 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: systemError
 * Константы: 0x30096EEC
 * Данные: DAT_300974c8
 * ---------------------------------------------------------------- */
void exchRebootSet(int param_1,int param_2,int param_3)

{
  if (param_3 != 0) {
    if (param_1 == 5) {
      *(undefined1 *)(*DAT_300974c8 + 0x2d) = 0x55;
    }
    else if (param_1 == 6) {
      *(undefined1 *)(*DAT_300974c8 + 0x2e) = 0x55;
    }
    else if (param_1 == 7) {
      *(undefined1 *)(*DAT_300974c8 + 0x2f) = 0x55;
    }
  }
  if (param_2 != 0) {
    systemError(0x25,param_1,param_3,0,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * exchOMSaveRegister @ 0x30096F94  (примерный размер ~88 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30096F94, 0xFFFFFFFF
 * Данные: DAT_30096fdc, DAT_30097084
 * ---------------------------------------------------------------- */
undefined4 exchOMSaveRegister(int param_1,undefined4 param_2)

{
  if (param_1 == 1) {
    *DAT_30097084 = param_2;
  }
  else {
    if (param_1 != 6) {
      return 0xffffffff;
    }
    *DAT_30096fdc = param_2;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * exchMemMalloc @ 0x30097018  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30097018
 * Данные: DAT_30097504
 * ---------------------------------------------------------------- */
undefined4 exchMemMalloc(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_30097504;
  if (0x10000 < param_1) {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * exchGetOldestFile @ 0x30097044  (примерный размер ~80 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30097044
 * ---------------------------------------------------------------- */
uint exchGetOldestFile(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  for (uVar1 = 1; uVar1 < param_2; uVar1 = uVar1 + 1) {
    if (*(uint *)(param_1 + uVar1 * 4) < *(uint *)(param_1 + uVar2 * 4)) {
      uVar2 = uVar1;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * exchRenameFiles @ 0x30097094  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30097094
 * ---------------------------------------------------------------- */
uint exchRenameFiles(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  for (uVar1 = 1; uVar1 < param_2; uVar1 = uVar1 + 1) {
    if (*(uint *)(param_1 + uVar2 * 4) < *(uint *)(param_1 + uVar1 * 4)) {
      uVar2 = uVar1;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * exchGetBakFile @ 0x300970E0  (примерный размер ~192 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: strncmp
 * Константы: 0x300970E0
 * Данные: DAT_30097508
 * ---------------------------------------------------------------- */
uint exchGetBakFile(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = strncmp((char *)(param_3 * 0x32 + param_1 + 0x10),DAT_30097508,4);
  uVar2 = param_3;
  if (iVar1 != 0) {
    uVar3 = 0;
    while ((uVar2 = param_3, uVar3 < param_2 &&
           ((iVar1 = strncmp((char *)(uVar3 * 0x32 + param_1),(char *)(param_3 * 0x32 + param_1),
                             0x10), iVar1 != 0 ||
            (iVar1 = strncmp((char *)(uVar3 * 0x32 + param_1 + 0x10),DAT_30097508,4), uVar2 = uVar3,
            iVar1 != 0))))) {
      uVar3 = uVar3 + 1;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * exchHookFuncAdd @ 0x3009734C  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: subVICIntHook, taskSwitchHookAdd, vicIntLvlChgHookAdd
 * Константы: 0x3009734C
 * Данные: DAT_300974e0, DAT_300974e8, DAT_300974ec
 * ---------------------------------------------------------------- */
void exchHookFuncAdd(void)

{
  taskSwitchHookAdd(DAT_300974e0);
  vicIntLvlChgHookAdd(DAT_300974e8);
  subVICIntHook(DAT_300974ec);
  return;
}

/* ----------------------------------------------------------------
 * exchUNDEF @ 0x300973A0  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300973A0
 * Данные: DAT_30097494
 * ---------------------------------------------------------------- */
void exchUNDEF(void)

{
  undefined4 local_c;
  
  local_c = DAT_30097494;
  (*(code *)&local_c)();
  return;
}

/* ----------------------------------------------------------------
 * exchSWI @ 0x300973D4  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300973D4
 * ---------------------------------------------------------------- */
void exchSWI(void)

{
  software_interrupt(0x1234);
  return;
}

/* ----------------------------------------------------------------
 * exchPABT @ 0x300973DC  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300973DC
 * Данные: DAT_30097534
 * ---------------------------------------------------------------- */
void exchPABT(void)

{
  (*DAT_30097534)();
  return;
}

/* ----------------------------------------------------------------
 * exchDABT @ 0x300973FC  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300973FC
 * Данные: DAT_30097494, DAT_30097534
 * ---------------------------------------------------------------- */
void exchDABT(void)

{
  *DAT_30097534 = DAT_30097494;
  return;
}

/* ----------------------------------------------------------------
 * exchLOOP @ 0x3009740C  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009740C
 * ---------------------------------------------------------------- */
void exchLOOP(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* ----------------------------------------------------------------
 * exchDIV @ 0x30097418  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: __div32
 * Константы: 0x30097418
 * ---------------------------------------------------------------- */
void exchDIV(undefined4 param_1)

{
  __div32(4,param_1);
  return;
}

/* ----------------------------------------------------------------
 * exchTest @ 0x30097434  (примерный размер ~964 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30097434, 0x30097450
 * Данные: DAT_30097538
 * ---------------------------------------------------------------- */
void exchTest(uint param_1)

{
  if (param_1 < 6) {
                    /* WARNING: Could not recover jumptable at 0x30097450. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_30097538 + param_1 * 4))();
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * exchTrcPrint @ 0x30097AD4  (примерный размер ~848 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: cplusDemangle, exchPrintBuffer, free, shellInternalSymTblFromTaskGet, symByValueAndTypeFind
 * Константы: 0x30097AD4
 * Данные: DAT_30098008, DAT_3009800c, DAT_30098010, DAT_30098014, DAT_30098018, DAT_3009801c, DAT_30098020, DAT_30098024
 * ---------------------------------------------------------------- */
undefined4
exchTrcPrint(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
            undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_138 [4];
  void *local_134;
  int local_130;
  int local_12c;
  undefined1 auStack_128 [260];
  
  local_12c = 0;
  exchPrintBuffer(param_7,DAT_30098008,param_1);
  if (param_6 == 0) {
    iVar1 = shellInternalSymTblFromTaskGet(param_5,param_1);
  }
  else {
    iVar1 = *DAT_3009800c;
  }
  local_134 = (void *)0x0;
  if (iVar1 == 0) {
LAB_30097bbc:
    exchPrintBuffer(param_7,DAT_30098018);
  }
  else {
    iVar1 = symByValueAndTypeFind(iVar1,param_1,&local_134,&local_130,auStack_138,0,0);
    if (iVar1 != 0) goto LAB_30097bbc;
    uVar2 = cplusDemangle(local_134,auStack_128,DAT_30098010);
    exchPrintBuffer(param_7,DAT_30098014,uVar2,param_1 - local_130);
  }
  free(local_134);
  local_134 = (void *)0x0;
  if (param_6 == 0) {
    iVar1 = shellInternalSymTblFromTaskGet(param_5,param_2);
  }
  else {
    iVar1 = *DAT_3009800c;
  }
  if (iVar1 != 0) {
    iVar1 = symByValueAndTypeFind(iVar1,param_2,&local_134,&local_130,auStack_138,0,0);
    if ((iVar1 == 0) && (local_130 == param_2)) {
      uVar2 = cplusDemangle(local_134,auStack_128,DAT_30098010);
      exchPrintBuffer(param_7,DAT_3009801c,uVar2);
      goto LAB_30097c94;
    }
  }
  exchPrintBuffer(param_7,DAT_30098020,param_2);
LAB_30097c94:
  free(local_134);
  local_134 = (void *)0x0;
  if ((param_3 == 0) && (*DAT_30098024 != 0)) {
    local_12c = 1;
    param_3 = *DAT_30098024;
    exchPrintBuffer(param_7,DAT_30098028);
  }
  if (param_6 == 0) {
    iVar1 = shellInternalSymTblFromTaskGet(param_5,0);
  }
  else {
    iVar1 = *DAT_3009800c;
  }
  iVar4 = 0;
  do {
    if (param_3 <= iVar4) {
      if (local_12c != 0) {
        exchPrintBuffer(param_7,DAT_3009803c);
      }
      exchPrintBuffer(param_7,DAT_30098040);
      return 0;
    }
    if (0 < iVar4) {
      exchPrintBuffer(param_7,DAT_3009802c);
    }
    if (*(int *)(param_4 + iVar4 * 4) == 0) {
      exchPrintBuffer(param_7,DAT_30098030);
    }
    else {
      if (iVar1 != 0) {
        iVar3 = symByValueAndTypeFind
                          (iVar1,*(undefined4 *)(param_4 + iVar4 * 4),&local_134,&local_130,
                           auStack_138,0,0);
        if ((iVar3 == 0) && (*(int *)(param_4 + iVar4 * 4) == local_130)) {
          uVar2 = cplusDemangle(local_134,auStack_128,4);
          exchPrintBuffer(param_7,DAT_30098034,uVar2);
          goto LAB_30097dd8;
        }
      }
      exchPrintBuffer(param_7,DAT_30098038,*(undefined4 *)(param_4 + iVar4 * 4));
    }
LAB_30097dd8:
    free(local_134);
    local_134 = (void *)0x0;
    iVar4 = iVar4 + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * exchSaveAndRebootJob @ 0x30097F58  (примерный размер ~268 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_WDT_reboot_direct, exchSave, save_task_name
 * Константы: 0x30097F58
 * Данные: DAT_30098044, DAT_3009805c, DAT_30098060
 * ---------------------------------------------------------------- */
void exchSaveAndRebootJob(void)

{
  save_task_name();
  exchSave();
  *DAT_3009805c = 0;
  *DAT_30098060 = 0;
  *(undefined4 *)(*DAT_30098044 + 0x24) = 0;
  BSP_WDT_reboot_direct();
  return;
}

/* ----------------------------------------------------------------
 * ExceptionInfoRecord @ 0x300997B0  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300997B0
 * ---------------------------------------------------------------- */
undefined4 ExceptionInfoRecord(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * usrEntry @ 0x3009FD84  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009FD84
 * Данные: DAT_3009fd98
 * ---------------------------------------------------------------- */
void usrEntry(void)

{
  (*DAT_3009fd98)();
  return;
}

/* ----------------------------------------------------------------
 * cplusXtorGet @ 0x3009FD9C  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: cplusLoadFixup, cplusUnloadFixup
 * Константы: 0x3009FD9C
 * Данные: DAT_3009ff0c
 * ---------------------------------------------------------------- */
undefined4 cplusXtorGet(void)

{
  return *DAT_3009ff0c;
}

/* ----------------------------------------------------------------
 * cplusXtorSet @ 0x3009FDA8  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009FDA8
 * Данные: DAT_3009ff0c
 * ---------------------------------------------------------------- */
void cplusXtorSet(undefined4 param_1)

{
  *DAT_3009ff0c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * cplusCtors @ 0x3009FDEC  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: cplusCallCtors, moduleEach, moduleFindByName
 * Константы: 0x3009FDEC
 * Данные: DAT_3009ff10, DAT_3009ff14, DAT_3009ff18
 * ---------------------------------------------------------------- */
void cplusCtors(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    moduleEach(DAT_3009ff10,0);
  }
  else {
    iVar1 = moduleFindByName(param_1);
    if (iVar1 == 0) {
      if ((code *)*DAT_3009ff14 != (code *)0x0) {
        (*(code *)*DAT_3009ff14)(DAT_3009ff18,param_1,0,0,0,0,0);
      }
    }
    else if (*(int *)(iVar1 + 0x534) != 0) {
      cplusCallCtors(*(int *)(iVar1 + 0x534));
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * cplusDtors @ 0x3009FE7C  (примерный размер ~168 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: cplusCallDtors, moduleEach, moduleFindByName
 * Константы: 0x3009FE7C
 * Данные: DAT_3009ff14, DAT_3009ff1c, DAT_3009ff20
 * ---------------------------------------------------------------- */
void cplusDtors(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    moduleEach(DAT_3009ff1c,0);
  }
  else {
    iVar1 = moduleFindByName(param_1);
    if (iVar1 == 0) {
      if ((code *)*DAT_3009ff14 != (code *)0x0) {
        (*(code *)*DAT_3009ff14)(DAT_3009ff20,param_1,0,0,0,0,0);
      }
    }
    else if (*(int *)(iVar1 + 0x538) != 0) {
      cplusCallDtors(*(int *)(iVar1 + 0x538));
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * cplusCallCtors @ 0x3009FF24  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: cplusCtors, cplusCtorsLink, cplusLoadFixup
 * Константы: 0x3009FF24
 * ---------------------------------------------------------------- */
void cplusCallCtors(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    (*(code *)*param_1)();
    param_1 = param_1 + 1;
    iVar1 = *param_1;
  }
  return;
}

/* ----------------------------------------------------------------
 * cplusCtorsLink @ 0x3009FF60  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: cplusCallCtors
 * Вызывают: usrRoot
 * Константы: 0x3009FF60
 * Данные: DAT_3009ffe8, DAT_3009ffec
 * ---------------------------------------------------------------- */
void cplusCtorsLink(void)

{
  if (*DAT_3009ffe8 == 0) {
    cplusCallCtors(DAT_3009ffec);
    *DAT_3009ffe8 = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * cplusCallDtors @ 0x3009FF8C  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: cplusDtors, cplusDtorsLink, cplusUnloadFixup
 * Константы: 0x3009FF8C
 * ---------------------------------------------------------------- */
void cplusCallDtors(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1;
  piVar1 = param_1;
  while (iVar2 != 0) {
    piVar1 = piVar1 + 1;
    iVar2 = *piVar1;
  }
  while (param_1 < piVar1) {
    piVar1 = piVar1 + -1;
    (*(code *)*piVar1)();
  }
  return;
}

/* ----------------------------------------------------------------
 * cplusDtorsLink @ 0x3009FFE0  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cplusCallDtors
 * Константы: 0x3009FFE0
 * Данные: DAT_3009fff0
 * ---------------------------------------------------------------- */
void cplusDtorsLink(void)

{
  cplusCallDtors(DAT_3009fff0);
  return;
}

/* ----------------------------------------------------------------
 * cplusDemanglerSet @ 0x3009FFF4  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009FFF4
 * Данные: DAT_300a04f8
 * ---------------------------------------------------------------- */
void cplusDemanglerSet(undefined4 param_1)

{
  *DAT_300a04f8 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * cplusDemangle @ 0x300A0000  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 14 | Вызывает: 0
 * Вызывают: FUN_300f57f0, FUN_300f58d8, FUN_300f5a30, FUN_300f5e28, FUN_300f63ac, FUN_3011423c, FUN_30114ebc, FUN_301159dc, FUN_3011b4e0, FUN_3011cbc4
 *           ...
 * Константы: 0x300A0000
 * Данные: DAT_300a04fc
 * ---------------------------------------------------------------- */
void cplusDemangle(void)

{
  if ((code *)*DAT_300a04fc != (code *)0x0) {
    (*(code *)*DAT_300a04fc)();
  }
  return;
}

/* ----------------------------------------------------------------
 * cplusDemangle2 @ 0x300A0024  (примерный размер ~104 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: malloc, strcpy, strlen
 * Вызывают: FUN_300a0434
 * Константы: 0x300A0024
 * Данные: DAT_300a0500
 * ---------------------------------------------------------------- */
char * cplusDemangle2(char *param_1)

{
  size_t sVar1;
  char *__dest;
  
  if ((code *)*DAT_300a0500 == (code *)0x0) {
    sVar1 = strlen(param_1);
    __dest = (char *)malloc(sVar1 + 1);
    if (__dest == (char *)0x0) {
      __dest = (char *)0x0;
    }
    else {
      strcpy(__dest,param_1);
    }
  }
  else {
    __dest = (char *)(*(code *)*DAT_300a0500)(param_1);
  }
  return __dest;
}

/* ----------------------------------------------------------------
 * cplusDemangleToBuffer @ 0x300A008C  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 0
 * Вызывают: completionSymListGet, cplusMangledSymCheck, cplusUserAsk, symListGet
 * Константы: 0x300A008C
 * Данные: DAT_300a0504
 * ---------------------------------------------------------------- */
void cplusDemangleToBuffer(undefined4 param_1)

{
  undefined4 *in_stack_00000000;
  
  if ((code *)*DAT_300a0504 == (code *)0x0) {
    *in_stack_00000000 = param_1;
  }
  else {
    (*(code *)*DAT_300a0504)(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * cplusUserAsk @ 0x300A00C8  (примерный размер ~224 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 8
 * Вызывает: __stdin, atoi, cplusDemangleToBuffer, fgets, lstCount, lstFirst, lstNext, printf
 * Вызывают: FUN_301040fc, FUN_301044b0, cplusMangledSymGet
 * Константы: 0x300A00C8
 * Данные: DAT_300a0508, DAT_300a050c
 * ---------------------------------------------------------------- */
int cplusUserAsk(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_12c;
  undefined4 local_128;
  char acStack_124 [12];
  undefined1 auStack_118 [256];
  undefined1 local_18;
  
  iVar1 = lstCount();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    local_18 = 0;
    iVar4 = 1;
    iVar2 = lstFirst(param_1);
    while (iVar2 != 0) {
      local_128 = 0x100;
      cplusDemangleToBuffer(*(undefined4 *)(iVar2 + 8),auStack_118,&local_128,2,&local_12c);
      printf(DAT_300a0508,iVar4,local_12c);
      iVar2 = lstNext(iVar2);
      iVar4 = iVar4 + 1;
    }
    do {
      printf(DAT_300a050c);
      puVar3 = (undefined4 *)__stdin();
      fgets(acStack_124,10,(FILE *)*puVar3);
      iVar2 = atoi(acStack_124);
    } while (iVar1 < iVar2);
    iVar1 = 0;
    if (-1 < iVar2) {
      iVar1 = iVar2;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * cplusMatchMangledListGet @ 0x300A01A8  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 1
 * Вызывает: lstCount
 * Вызывают: FUN_301040fc, FUN_301044b0, cplusMangledSymGet
 * Константы: 0x300A01A8
 * Данные: DAT_300a0510, DAT_300a0514
 * ---------------------------------------------------------------- */
void cplusMatchMangledListGet(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  
  if ((code *)*DAT_300a0510 != (code *)0x0) {
    local_10 = param_3;
    local_c = param_2;
    (*(code *)*DAT_300a0510)(param_1,DAT_300a0514,&local_10);
    lstCount(param_3);
  }
  return;
}

/* ----------------------------------------------------------------
 * cplusMangledSymGet @ 0x300A01F4  (примерный размер ~228 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 7
 * Вызывает: cplusMatchMangledListGet, cplusUserAsk, lstFirst, lstFree, lstInit, lstNth, printf
 * Вызывают: FUN_301043e4, cplusMatchMangled
 * Константы: 0xFFFFFFFF, 0x300A01F4
 * Данные: DAT_300a0518, DAT_300a051c
 * ---------------------------------------------------------------- */
undefined4
cplusMangledSymGet(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_28 [12];
  
  *param_5 = 0;
  uVar2 = 0xffffffff;
  if (*DAT_300a0518 == 0) {
    return 0xffffffff;
  }
  lstInit(auStack_28);
  iVar1 = cplusMatchMangledListGet(param_1,param_2,auStack_28);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      iVar1 = lstFirst(auStack_28);
    }
    else {
      *param_5 = 1;
      printf(DAT_300a051c,param_2);
      iVar1 = cplusUserAsk(auStack_28);
      if (iVar1 < 1) goto LAB_300a02c4;
      iVar1 = lstNth(auStack_28,iVar1);
    }
    if (iVar1 != 0) {
      uVar2 = (*(code *)*DAT_300a0518)(param_1,*(undefined4 *)(iVar1 + 8),param_4,param_3);
    }
  }
LAB_300a02c4:
  lstFree(auStack_28);
  return uVar2;
}

/* ----------------------------------------------------------------
 * cplusMatchMangled @ 0x300A02D8  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cplusMangledSymGet
 * Константы: 0x300A02D8
 * ---------------------------------------------------------------- */
bool cplusMatchMangled(void)

{
  int iVar1;
  
  iVar1 = cplusMangledSymGet();
  return iVar1 == 0;
}

/* ----------------------------------------------------------------
 * cplusMangledSymCheck @ 0x300A0300  (примерный размер ~128 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 2
 * Вызывает: cplusDemangleToBuffer, strcmp
 * Вызывают: FUN_301040fc, FUN_301043e4, symListGet
 * Константы: 0x300A0300
 * ---------------------------------------------------------------- */
undefined4 cplusMangledSymCheck(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *local_114;
  undefined4 local_110;
  undefined1 auStack_10c [256];
  undefined1 local_c;
  
  if ((*param_1 == '_') && (param_1[1] == 'Z')) {
    uVar1 = 1;
  }
  else {
    local_110 = 0x100;
    local_c = 0;
    cplusDemangleToBuffer(param_1,auStack_10c,&local_110,2,&local_114);
    iVar2 = strcmp(param_1,local_114);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300a0380 @ 0x300A0380  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300a0434
 * Константы: 0x300A0380
 * ---------------------------------------------------------------- */
char * FUN_300a0380(char *param_1,char *param_2)

{
  bool bVar1;
  
  if ((*param_2 != '\0') && (*param_1 != '\0')) {
    if (*param_1 == *param_2) {
      do {
        bVar1 = *param_2 == '\0';
        if (bVar1) goto LAB_300a03cc;
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
      } while (*param_1 == *param_2);
    }
    bVar1 = *param_2 == '\0';
LAB_300a03cc:
    if (bVar1) {
      return param_1 + -1;
    }
  }
  return (char *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_300a03e0 @ 0x300A03E0  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: calloc, lstAdd, strcpy, strlen
 * Вызывают: FUN_300a0434
 * Константы: 0x300A03E0
 * ---------------------------------------------------------------- */
undefined4 FUN_300a03e0(char *param_1,undefined4 param_2)

{
  size_t sVar1;
  void *pvVar2;
  
  sVar1 = strlen(param_1);
  pvVar2 = calloc(1,sVar1 + 0x19);
  if (pvVar2 == (void *)0x0) {
    return 0;
  }
  *(char **)((int)pvVar2 + 8) = (char *)((int)pvVar2 + 0x18);
  strcpy((char *)((int)pvVar2 + 0x18),param_1);
  lstAdd(param_2,pvVar2);
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300a0434 @ 0x300A0434  (примерный размер ~244 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_300a0380, FUN_300a03e0, cplusDemangle2, free, strcmp, strstr
 * Константы: 0x300A0434
 * Данные: DAT_300a0520, DAT_300a0524
 * ---------------------------------------------------------------- */
undefined4 FUN_300a0434(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  char *pcVar2;
  char *__needle;
  
  __needle = (char *)param_4[1];
  iVar1 = FUN_300a0380(param_1,__needle);
  if ((iVar1 == 0) || (iVar1 = FUN_300a0380(iVar1 + 1,DAT_300a0520), iVar1 == 0)) {
    if ((*param_1 == '_') &&
       ((param_1[1] == 'Z' && (pcVar2 = strstr(param_1,__needle), pcVar2 != (char *)0x0)))) {
      pcVar2 = (char *)cplusDemangle2(param_1,*DAT_300a0524,1);
      if ((pcVar2 != (char *)0x0) && (iVar1 = strcmp(pcVar2,__needle), iVar1 == 0)) {
        FUN_300a03e0(param_1,*param_4);
      }
      free(pcVar2);
    }
  }
  else {
    FUN_300a03e0(param_1,*param_4);
  }
  return 1;
}

/* ----------------------------------------------------------------
 * cplusDemanglerStyleInit @ 0x300A0528  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A0528
 * Данные: DAT_300a0544
 * ---------------------------------------------------------------- */
void cplusDemanglerStyleInit(void)

{
  *DAT_300a0544 = 1;
  return;
}

/* ----------------------------------------------------------------
 * cplusDemanglerStyleSet @ 0x300A0538  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A0538
 * Данные: DAT_300a0544
 * ---------------------------------------------------------------- */
void cplusDemanglerStyleSet(undefined4 param_1)

{
  *DAT_300a0544 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a0548 @ 0x300A0548  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 0
 * Вызывают: FUN_300a0cb8, FUN_300a0d4c, FUN_300a0ddc, FUN_300a0ed0, FUN_300a0fbc, FUN_300a10a8, FUN_300a1110
 * Константы: 0x300A0548
 * Данные: DAT_300a0818
 * ---------------------------------------------------------------- */
undefined4 FUN_300a0548(int param_1)

{
  if (((-1 < param_1) && (param_1 < 2)) && (*(int *)(DAT_300a0818 + param_1 * 4) != 0)) {
    return 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300a0578 @ 0x300A0578  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300a0ddc, FUN_300a0ed0, FUN_300a0fbc
 * Константы: 0x300A0578
 * Данные: DAT_300a081c
 * ---------------------------------------------------------------- */
uint FUN_300a0578(uint param_1,int param_2)

{
  return param_1 & *(uint *)(DAT_300a081c + param_2 * 4);
}

/* ----------------------------------------------------------------
 * FUN_300a0588 @ 0x300A0588  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300a0ddc, FUN_300a0ed0, FUN_300a0fbc
 * Константы: 0x300A0588
 * Данные: DAT_300a081c, DAT_300a0820, DAT_300a0824
 * ---------------------------------------------------------------- */
uint FUN_300a0588(uint param_1,int param_2)

{
  if ((param_1 & *(uint *)(DAT_300a0820 + param_2 * 4)) == 0) {
    return param_1;
  }
  return param_1 + *(int *)(DAT_300a0824 + param_2 * 4) & *(uint *)(DAT_300a081c + param_2 * 4);
}

/* ----------------------------------------------------------------
 * FUN_300a05bc @ 0x300A05BC  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300a0ddc, FUN_300a0ed0, FUN_300a0fbc
 * Константы: 0x300A05BC
 * Данные: DAT_300a0828, DAT_300a082c
 * ---------------------------------------------------------------- */
undefined4 FUN_300a05bc(void)

{
  undefined4 uVar1;
  int in_r3;
  code *pcVar2;
  int in_stack_00000000;
  
  pcVar2 = *(code **)(in_r3 * 0x3c + DAT_300a0828 + in_stack_00000000 * 4);
  uVar1 = DAT_300a082c;
  if (pcVar2 != (code *)0x0) {
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * excEnterSwi @ 0x300A6FB4  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: excExcContinue
 * Константы: 0x300A6FB4
 * Данные: DAT_300a6f34, DAT_300a6f40
 * ---------------------------------------------------------------- */
undefined8 excEnterSwi(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint unaff_r4;
  uint uVar9;
  undefined4 unaff_r5;
  undefined4 uVar10;
  undefined4 unaff_r6;
  undefined4 uVar11;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 in_r12;
  int in_lr;
  uint uVar12;
  
  puVar1 = DAT_300a6f40;
  uVar12 = in_lr - 4;
  DAT_300a6f40[1] = param_1;
  puVar1[2] = param_2;
  puVar1[3] = (uint)puVar1;
  puVar1[4] = param_4;
  puVar1[5] = unaff_r4;
  puVar1[6] = uVar12;
  puVar1[3] = param_3;
  puVar1[5] = unaff_r4;
  *puVar1 = param_4;
  iVar3 = *DAT_300a6f34;
  puVar4 = (undefined1 *)register0x00000054;
  if (iVar3 == 0) {
    uVar9 = puVar1[5];
    puVar5 = (undefined1 *)0x0;
  }
  else if (*(int *)(iVar3 + 0x6c) == 0) {
    uVar9 = puVar1[5];
    puVar4 = *(undefined1 **)(iVar3 + 0x60);
    *(BADSPACEBASE **)(puVar4 + -4) = register0x00000054;
    puVar5 = *(undefined1 **)(puVar4 + -4);
  }
  else {
    uVar9 = puVar1[5];
    puVar5 = (undefined1 *)register0x00000054;
  }
  *(uint *)(puVar4 + -4) = param_4;
  *(uint **)(puVar4 + -8) = puVar1;
  *(undefined1 **)(puVar4 + -0xc) = puVar5;
  *(undefined4 *)(puVar4 + -0x10) = 8;
  uVar2 = coproc_movefrom_Translation_table_base_0();
  *(undefined4 *)(puVar4 + -0x14) = uVar2;
  uVar6 = puVar1[6];
  uVar8 = *puVar1;
  *(uint *)(puVar4 + -0x18) = uVar8;
  *(uint *)(puVar4 + -0x1c) = uVar6;
  if ((uVar8 & 0xf) == 0) {
    *(uint *)(puVar4 + -0x48) = uVar9;
    *(undefined4 *)(puVar4 + -0x44) = unaff_r5;
    *(undefined4 *)(puVar4 + -0x40) = unaff_r6;
    *(undefined4 *)(puVar4 + -0x3c) = unaff_r7;
    *(undefined4 *)(puVar4 + -0x38) = unaff_r8;
    *(undefined4 *)(puVar4 + -0x34) = unaff_r9;
    *(undefined4 *)(puVar4 + -0x30) = unaff_r10;
    *(undefined4 *)(puVar4 + -0x2c) = unaff_r11;
    *(undefined4 *)(puVar4 + -0x28) = in_r12;
    *(undefined1 **)(puVar4 + -0x24) = puVar4 + -0x48;
    *(uint *)(puVar4 + -0x20) = uVar12;
  }
  else {
    *(uint *)(puVar4 + -0x48) = uVar9;
    *(undefined4 *)(puVar4 + -0x44) = unaff_r5;
    *(undefined4 *)(puVar4 + -0x40) = unaff_r6;
    *(undefined4 *)(puVar4 + -0x3c) = unaff_r7;
    *(undefined4 *)(puVar4 + -0x38) = unaff_r8;
    *(undefined4 *)(puVar4 + -0x34) = unaff_r9;
    *(undefined4 *)(puVar4 + -0x30) = unaff_r10;
    *(undefined4 *)(puVar4 + -0x2c) = unaff_r11;
    *(undefined4 *)(puVar4 + -0x28) = in_r12;
    *(undefined1 **)(puVar4 + -0x24) = puVar4 + -0x48;
    *(uint *)(puVar4 + -0x20) = uVar12;
    if ((uVar8 & 0xf) == 3) {
      *(undefined4 *)(puVar4 + -0x24) = *(undefined4 *)(puVar4 + -0xc);
    }
  }
  uVar12 = puVar1[1];
  uVar9 = puVar1[2];
  uVar6 = puVar1[3];
  *(uint *)(puVar4 + -0x4c) = puVar1[4];
  *(uint *)(puVar4 + -0x50) = uVar6;
  *(uint *)(puVar4 + -0x54) = uVar9;
  *(uint *)(puVar4 + -0x58) = uVar12;
  iVar3 = *DAT_300a6f34;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + 1;
  }
  excExcContinue(puVar4 + -0x1c);
  puVar7 = *(undefined4 **)(puVar4 + -8);
  uVar2 = *(undefined4 *)(puVar4 + -0x54);
  uVar10 = *(undefined4 *)(puVar4 + -0x50);
  uVar11 = *(undefined4 *)(puVar4 + -0x4c);
  puVar7[1] = *(uint *)(puVar4 + -0x58);
  puVar7[2] = uVar2;
  puVar7[3] = uVar10;
  puVar7[4] = uVar11;
  if ((*(uint *)(puVar4 + -0x18) & 0xf) == 0) {
    puVar5 = *(undefined1 **)(puVar4 + -0x24);
  }
  else {
    puVar5 = *(undefined1 **)(puVar4 + -0x24);
    if ((*(uint *)(puVar4 + -0x18) & 0xf) == 3) {
      puVar5 = puVar4 + -0x48;
    }
  }
  uVar2 = *(undefined4 *)(puVar5 + 0x30);
  puVar7[5] = *(undefined4 *)(puVar5 + 0x2c);
  *puVar7 = uVar2;
  iVar3 = *DAT_300a6f34;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + -1;
  }
  return *(undefined8 *)(*(int *)(puVar5 + 0x40) + 4);
}

/* ----------------------------------------------------------------
 * excEnterDataAbort @ 0x300A6FE0  (примерный размер ~644 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: excExcContinue
 * Константы: 0x300A6FE0, 0x300A7088, 0x300A70B0, 0x300A70C8, 0x300A70D0, 0x300A70D8, 0x300A70DC, 0x300A70E0
 * Данные: DAT_300a6f34, DAT_300a6f3c, DAT_300a6f58, DAT_300a6f5c, DAT_300a6f60
 * ---------------------------------------------------------------- */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x300a7088) */
/* WARNING: Removing unreachable block (ram,0x300a70b0) */
/* WARNING: Removing unreachable block (ram,0x300a70c8) */
/* WARNING: Removing unreachable block (ram,0x300a70d0) */
/* WARNING: Removing unreachable block (ram,0x300a70d8) */
/* WARNING: Removing unreachable block (ram,0x300a70dc) */
/* WARNING: Removing unreachable block (ram,0x300a70e0) */
/* WARNING: Removing unreachable block (ram,0x300a70f0) */
/* WARNING: Removing unreachable block (ram,0x300a70f4) */
/* WARNING: Removing unreachable block (ram,0x300a70fc) */
/* WARNING: Removing unreachable block (ram,0x300a7104) */
/* WARNING: Removing unreachable block (ram,0x300a710c) */
/* WARNING: Removing unreachable block (ram,0x300a7110) */
/* WARNING: Removing unreachable block (ram,0x300a7114) */
/* WARNING: Removing unreachable block (ram,0x300a7124) */
/* WARNING: Removing unreachable block (ram,0x300a7144) */
/* WARNING: Removing unreachable block (ram,0x300a714c) */
/* WARNING: Removing unreachable block (ram,0x300a7154) */
/* WARNING: Removing unreachable block (ram,0x300a7158) */
/* WARNING: Removing unreachable block (ram,0x300a715c) */
/* WARNING: Removing unreachable block (ram,0x300a716c) */
/* WARNING: Removing unreachable block (ram,0x300a7170) */
/* WARNING: Removing unreachable block (ram,0x300a7178) */
/* WARNING: Removing unreachable block (ram,0x300a7180) */
/* WARNING: Removing unreachable block (ram,0x300a7188) */
/* WARNING: Removing unreachable block (ram,0x300a718c) */
/* WARNING: Removing unreachable block (ram,0x300a7190) */
/* WARNING: Removing unreachable block (ram,0x300a71a0) */
/* WARNING: Removing unreachable block (ram,0x300a71c0) */
/* WARNING: Removing unreachable block (ram,0x300a71c8) */
/* WARNING: Removing unreachable block (ram,0x300a71d0) */
/* WARNING: Removing unreachable block (ram,0x300a71d4) */
/* WARNING: Removing unreachable block (ram,0x300a71d8) */
/* WARNING: Removing unreachable block (ram,0x300a71e8) */
/* WARNING: Removing unreachable block (ram,0x300a71ec) */
/* WARNING: Removing unreachable block (ram,0x300a71fc) */
/* WARNING: Removing unreachable block (ram,0x300a7204) */
/* WARNING: Removing unreachable block (ram,0x300a720c) */
/* WARNING: Removing unreachable block (ram,0x300a7210) */
/* WARNING: Removing unreachable block (ram,0x300a7214) */
/* WARNING: Removing unreachable block (ram,0x300a7224) */
/* WARNING: Removing unreachable block (ram,0x300a7228) */
/* WARNING: Removing unreachable block (ram,0x300a7030) */
/* WARNING: Removing unreachable block (ram,0x300a724c) */

undefined8
excEnterDataAbort(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint unaff_r5;
  uint unaff_r6;
  uint unaff_r7;
  uint unaff_r8;
  uint unaff_r9;
  uint unaff_r10;
  uint unaff_r11;
  uint in_r12;
  int in_lr;
  uint uVar9;
  char in_CY;
  char in_OV;
  bool bVar10;
  byte in_Q;
  undefined4 in_cr0;
  undefined4 in_cr6;
  undefined4 uStack00000004;
  undefined4 uStack00000008;
  undefined4 uStack0000000c;
  undefined4 uStack00000010;
  int iStack00000018;
  
  puVar6 = DAT_300a6f3c;
  iStack00000018 = in_lr + -8;
  iVar5 = *DAT_300a6f34;
  bVar10 = iVar5 == 0;
  if (!bVar10) {
    if (((*DAT_300a6f60 != 0) || (*DAT_300a6f58 != 0)) || (bVar10 = *DAT_300a6f5c == 0, !bVar10)) {
      coprocessor_movefromRt(0xf,0,0,in_cr6,in_cr0);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    iVar5 = 0;
  }
  uVar9 = DAT_300a6f3c[6];
  *DAT_300a6f3c = 0;
  iVar2 = *DAT_300a6f34;
  puVar3 = puVar6;
  if (iVar2 == 0) {
    uVar8 = puVar6[5];
    puVar4 = (uint *)0x0;
  }
  else if (*(int *)(iVar2 + 0x6c) == 0) {
    uVar8 = puVar6[5];
    puVar3 = *(uint **)(iVar2 + 0x60);
    *(undefined4 *)((int)puVar3 + -4) = puVar6;
    puVar4 = *(uint **)((int)puVar3 + -4);
  }
  else {
    uVar8 = puVar6[5];
    puVar4 = puVar6;
  }
  puVar3[-1] = (uint)(byte)((iVar5 < 0) << 4 | bVar10 << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b
  ;
  puVar3[-2] = (uint)puVar6;
  puVar3[-3] = (uint)puVar4;
  puVar3[-4] = 0x10;
  uVar1 = coproc_movefrom_Translation_table_base_0();
  puVar3[-5] = uVar1;
  uVar1 = puVar6[6];
  uVar7 = *puVar6;
  puVar3[-6] = uVar7;
  puVar3[-7] = uVar1;
  if ((uVar7 & 0xf) == 0) {
    puVar3[-0x12] = uVar8;
    puVar3[-0x11] = unaff_r5;
    puVar3[-0x10] = unaff_r6;
    puVar3[-0xf] = unaff_r7;
    puVar3[-0xe] = unaff_r8;
    puVar3[-0xd] = unaff_r9;
    puVar3[-0xc] = unaff_r10;
    puVar3[-0xb] = unaff_r11;
    puVar3[-10] = in_r12;
    puVar3[-9] = (uint)(puVar3 + -0x12);
    puVar3[-8] = uVar9;
  }
  else {
    puVar3[-0x12] = uVar8;
    puVar3[-0x11] = unaff_r5;
    puVar3[-0x10] = unaff_r6;
    puVar3[-0xf] = unaff_r7;
    puVar3[-0xe] = unaff_r8;
    puVar3[-0xd] = unaff_r9;
    puVar3[-0xc] = unaff_r10;
    puVar3[-0xb] = unaff_r11;
    puVar3[-10] = in_r12;
    puVar3[-9] = (uint)(puVar3 + -0x12);
    puVar3[-8] = uVar9;
    if ((uVar7 & 0xf) == 3) {
      puVar3[-9] = puVar3[-3];
    }
  }
  uVar9 = puVar6[1];
  uVar8 = puVar6[2];
  uVar1 = puVar6[3];
  puVar3[-0x13] = puVar6[4];
  puVar3[-0x14] = uVar1;
  puVar3[-0x15] = uVar8;
  puVar3[-0x16] = uVar9;
  iVar5 = *DAT_300a6f34;
  if (iVar5 != 0) {
    *(int *)(iVar5 + 0x6c) = *(int *)(iVar5 + 0x6c) + 1;
  }
  uStack00000004 = param_1;
  uStack00000008 = param_2;
  uStack0000000c = param_3;
  uStack00000010 = param_4;
  excExcContinue(puVar3 + -7);
  puVar6 = (uint *)puVar3[-2];
  uVar9 = puVar3[-0x15];
  uVar8 = puVar3[-0x14];
  uVar1 = puVar3[-0x13];
  puVar6[1] = puVar3[-0x16];
  puVar6[2] = uVar9;
  puVar6[3] = uVar8;
  puVar6[4] = uVar1;
  if ((puVar3[-6] & 0xf) == 0) {
    puVar4 = (uint *)puVar3[-9];
  }
  else {
    puVar4 = (uint *)puVar3[-9];
    if ((puVar3[-6] & 0xf) == 3) {
      puVar4 = puVar3 + -0x12;
    }
  }
  uVar9 = puVar4[0xc];
  puVar6[5] = puVar4[0xb];
  *puVar6 = uVar9;
  iVar5 = *DAT_300a6f34;
  if (iVar5 != 0) {
    *(int *)(iVar5 + 0x6c) = *(int *)(iVar5 + 0x6c) + -1;
  }
  return *(undefined8 *)(puVar4[0x10] + 4);
}

/* ----------------------------------------------------------------
 * excEnterPrefetchAbort @ 0x300A7264  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: excExcContinue
 * Константы: 0x300A7264, 0x300A7308, 0x300A7328, 0x300A7330
 * Данные: DAT_300a6f34
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300a7308) */
/* WARNING: Removing unreachable block (ram,0x300a7328) */
/* WARNING: Removing unreachable block (ram,0x300a7330) */

undefined8
excEnterPrefetchAbort(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 uVar5;
  undefined4 unaff_r6;
  undefined4 uVar6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 in_r12;
  int in_lr;
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  undefined4 *puVar7;
  undefined4 uStack00000000;
  undefined4 uStack00000004;
  undefined4 uStack00000008;
  undefined4 uStack0000000c;
  undefined4 uStack00000010;
  int iStack00000018;
  
  iStack00000018 = in_lr + -4;
  uStack00000000 = 0;
  iVar2 = *DAT_300a6f34;
  puVar3 = (undefined1 *)register0x00000054;
  if (iVar2 == 0) {
    puVar4 = (undefined1 *)0x0;
  }
  else {
    puVar4 = (undefined1 *)register0x00000054;
    if (*(int *)(iVar2 + 0x6c) == 0) {
      puVar3 = *(undefined1 **)(iVar2 + 0x60);
      puVar7 = (undefined4 *)(puVar3 + -4);
      *puVar7 = register0x00000054;
      puVar4 = (undefined1 *)*puVar7;
    }
  }
  *(uint *)(puVar3 + -4) =
       (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
  *(BADSPACEBASE **)(puVar3 + -8) = register0x00000054;
  *(undefined1 **)(puVar3 + -0xc) = puVar4;
  *(undefined4 *)(puVar3 + -0x10) = 0xc;
  uVar1 = coproc_movefrom_Translation_table_base_0();
  *(undefined4 *)(puVar3 + -0x14) = uVar1;
  *(undefined4 *)(puVar3 + -0x18) = 0;
  *(int *)(puVar3 + -0x1c) = iStack00000018;
  *(undefined4 *)(puVar3 + -0x48) = unaff_r4;
  *(undefined4 *)(puVar3 + -0x44) = unaff_r5;
  *(undefined4 *)(puVar3 + -0x40) = unaff_r6;
  *(undefined4 *)(puVar3 + -0x3c) = unaff_r7;
  *(undefined4 *)(puVar3 + -0x38) = unaff_r8;
  *(undefined4 *)(puVar3 + -0x34) = unaff_r9;
  *(undefined4 *)(puVar3 + -0x30) = unaff_r10;
  *(undefined4 *)(puVar3 + -0x2c) = unaff_r11;
  *(undefined4 *)(puVar3 + -0x28) = in_r12;
  *(undefined1 **)(puVar3 + -0x24) = puVar3 + -0x48;
  *(int *)(puVar3 + -0x20) = iStack00000018;
  *(undefined4 *)(puVar3 + -0x4c) = param_4;
  *(undefined4 *)(puVar3 + -0x50) = param_3;
  *(undefined4 *)(puVar3 + -0x54) = param_2;
  *(undefined4 *)(puVar3 + -0x58) = param_1;
  iVar2 = *DAT_300a6f34;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 0x6c) = *(int *)(iVar2 + 0x6c) + 1;
  }
  uStack00000004 = param_1;
  uStack00000008 = param_2;
  uStack0000000c = param_3;
  uStack00000010 = param_4;
  excExcContinue(puVar3 + -0x1c);
  puVar7 = *(undefined4 **)(puVar3 + -8);
  uVar1 = *(undefined4 *)(puVar3 + -0x54);
  uVar5 = *(undefined4 *)(puVar3 + -0x50);
  uVar6 = *(undefined4 *)(puVar3 + -0x4c);
  puVar7[1] = *(undefined4 *)(puVar3 + -0x58);
  puVar7[2] = uVar1;
  puVar7[3] = uVar5;
  puVar7[4] = uVar6;
  if ((*(uint *)(puVar3 + -0x18) & 0xf) == 0) {
    puVar4 = *(undefined1 **)(puVar3 + -0x24);
  }
  else {
    puVar4 = *(undefined1 **)(puVar3 + -0x24);
    if ((*(uint *)(puVar3 + -0x18) & 0xf) == 3) {
      puVar4 = puVar3 + -0x48;
    }
  }
  uVar1 = *(undefined4 *)(puVar4 + 0x30);
  puVar7[5] = *(undefined4 *)(puVar4 + 0x2c);
  *puVar7 = uVar1;
  iVar2 = *DAT_300a6f34;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 0x6c) = *(int *)(iVar2 + 0x6c) + -1;
  }
  return *(undefined8 *)(*(int *)(puVar4 + 0x40) + 4);
}

/* ----------------------------------------------------------------
 * excEnterUndef @ 0x300A7274  (примерный размер ~404 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: excExcContinue
 * Константы: 0x300A7274, 0x300A7308, 0x300A7328, 0x300A7330
 * Данные: DAT_300a6f34
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300a7308) */
/* WARNING: Removing unreachable block (ram,0x300a7328) */
/* WARNING: Removing unreachable block (ram,0x300a7330) */

undefined8
excEnterUndef(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 uVar5;
  undefined4 unaff_r6;
  undefined4 uVar6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 in_r12;
  int in_lr;
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  undefined4 *puVar7;
  undefined4 uStack00000000;
  undefined4 uStack00000004;
  undefined4 uStack00000008;
  undefined4 uStack0000000c;
  undefined4 uStack00000010;
  int iStack00000018;
  
  iStack00000018 = in_lr + -4;
  uStack00000000 = 0;
  iVar2 = *DAT_300a6f34;
  puVar3 = (undefined1 *)register0x00000054;
  if (iVar2 == 0) {
    puVar4 = (undefined1 *)0x0;
  }
  else {
    puVar4 = (undefined1 *)register0x00000054;
    if (*(int *)(iVar2 + 0x6c) == 0) {
      puVar3 = *(undefined1 **)(iVar2 + 0x60);
      puVar7 = (undefined4 *)(puVar3 + -4);
      *puVar7 = register0x00000054;
      puVar4 = (undefined1 *)*puVar7;
    }
  }
  *(uint *)(puVar3 + -4) =
       (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
  *(BADSPACEBASE **)(puVar3 + -8) = register0x00000054;
  *(undefined1 **)(puVar3 + -0xc) = puVar4;
  *(undefined4 *)(puVar3 + -0x10) = 4;
  uVar1 = coproc_movefrom_Translation_table_base_0();
  *(undefined4 *)(puVar3 + -0x14) = uVar1;
  *(undefined4 *)(puVar3 + -0x18) = 0;
  *(int *)(puVar3 + -0x1c) = iStack00000018;
  *(undefined4 *)(puVar3 + -0x48) = unaff_r4;
  *(undefined4 *)(puVar3 + -0x44) = unaff_r5;
  *(undefined4 *)(puVar3 + -0x40) = unaff_r6;
  *(undefined4 *)(puVar3 + -0x3c) = unaff_r7;
  *(undefined4 *)(puVar3 + -0x38) = unaff_r8;
  *(undefined4 *)(puVar3 + -0x34) = unaff_r9;
  *(undefined4 *)(puVar3 + -0x30) = unaff_r10;
  *(undefined4 *)(puVar3 + -0x2c) = unaff_r11;
  *(undefined4 *)(puVar3 + -0x28) = in_r12;
  *(undefined1 **)(puVar3 + -0x24) = puVar3 + -0x48;
  *(int *)(puVar3 + -0x20) = iStack00000018;
  *(undefined4 *)(puVar3 + -0x4c) = param_4;
  *(undefined4 *)(puVar3 + -0x50) = param_3;
  *(undefined4 *)(puVar3 + -0x54) = param_2;
  *(undefined4 *)(puVar3 + -0x58) = param_1;
  iVar2 = *DAT_300a6f34;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 0x6c) = *(int *)(iVar2 + 0x6c) + 1;
  }
  uStack00000004 = param_1;
  uStack00000008 = param_2;
  uStack0000000c = param_3;
  uStack00000010 = param_4;
  excExcContinue(puVar3 + -0x1c);
  puVar7 = *(undefined4 **)(puVar3 + -8);
  uVar1 = *(undefined4 *)(puVar3 + -0x54);
  uVar5 = *(undefined4 *)(puVar3 + -0x50);
  uVar6 = *(undefined4 *)(puVar3 + -0x4c);
  puVar7[1] = *(undefined4 *)(puVar3 + -0x58);
  puVar7[2] = uVar1;
  puVar7[3] = uVar5;
  puVar7[4] = uVar6;
  if ((*(uint *)(puVar3 + -0x18) & 0xf) == 0) {
    puVar4 = *(undefined1 **)(puVar3 + -0x24);
  }
  else {
    puVar4 = *(undefined1 **)(puVar3 + -0x24);
    if ((*(uint *)(puVar3 + -0x18) & 0xf) == 3) {
      puVar4 = puVar3 + -0x48;
    }
  }
  uVar1 = *(undefined4 *)(puVar4 + 0x30);
  puVar7[5] = *(undefined4 *)(puVar4 + 0x2c);
  *puVar7 = uVar1;
  iVar2 = *DAT_300a6f34;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 0x6c) = *(int *)(iVar2 + 0x6c) + -1;
  }
  return *(undefined8 *)(*(int *)(puVar4 + 0x40) + 4);
}

/* ----------------------------------------------------------------
 * excVecBaseSet @ 0x300A7408  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A7408
 * Данные: DAT_300a7bbc
 * ---------------------------------------------------------------- */
void excVecBaseSet(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_300a7bbc;
  *DAT_300a7bbc = param_1 + 4;
  piVar1[2] = param_1 + 8;
  piVar1[4] = param_1 + 0xc;
  piVar1[6] = param_1 + 0x10;
  piVar1[8] = param_1 + 0x18;
  return;
}

/* ----------------------------------------------------------------
 * excVecInit @ 0x300A7438  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: armInitExceptionModes
 * Вызывают: usrInit
 * Константы: 0x300A7438
 * Данные: DAT_300a7bbc, DAT_300a7bc0, DAT_300a7bc4, DAT_300a7bc8, DAT_300a7bcc, DAT_300a7bd0
 * ---------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 excVecInit(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  armInitExceptionModes();
  uVar1 = DAT_300a7bc0;
  iVar2 = 5;
  piVar3 = (int *)(DAT_300a7bbc + -8);
  do {
    piVar4 = piVar3 + 2;
    iVar2 = iVar2 + -1;
    *(undefined4 *)*piVar4 = uVar1;
    *(int *)(*piVar4 + 0xfc) = piVar3[3];
    piVar3 = piVar4;
  } while (iVar2 != 0);
  _Reset = DAT_300a7bc4;
  if (*(code **)(DAT_300a7bc8 + 0x1c) != (code *)0x0) {
    (**(code **)(DAT_300a7bc8 + 0x1c))(0,0x1c);
  }
  *DAT_300a7bcc = DAT_300a7bd0;
  return 0;
}

/* ----------------------------------------------------------------
 * excIntConnect @ 0x300A74B4  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: intLibInit
 * Константы: 0x300A74B4, 0xFFFFFFFF
 * Данные: DAT_300a7bcc
 * ---------------------------------------------------------------- */
undefined4 excIntConnect(int param_1,undefined4 param_2)

{
  if (param_1 != 0x18) {
    return 0xffffffff;
  }
  *DAT_300a7bcc = param_2;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300a74d4 @ 0x300A74D4  (примерный размер ~280 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: taskTcb
 * Вызывают: excExcContinue, excExcHandle
 * Константы: 0x300A74D4, 0x01000000
 * Данные: DAT_300a7bd4, DAT_300a7bd8, DAT_300a7bdc, DAT_300a7be0
 * ---------------------------------------------------------------- */
void FUN_300a74d4(undefined4 param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  *param_4 = 7;
  param_4[1] = *(uint *)(param_2 + 0xc);
  param_4[2] = *(uint *)(param_3 + 0x3c);
  param_4[3] = *(uint *)(param_3 + 0x40);
  uVar2 = *DAT_300a7bd4;
  if (*(int *)(param_2 + 0xc) == 0) {
    *param_4 = 5;
  }
  else if ((((*(int *)(param_2 + 0xc) == 4) && ((code *)*DAT_300a7bd8 != (code *)0x0)) &&
           (iVar1 = (*(code *)*DAT_300a7bd8)(), iVar1 != 0)) &&
          (((code *)*DAT_300a7bdc != (code *)0x0 && (iVar1 = (*(code *)*DAT_300a7bdc)(), iVar1 != 0)
           ))) {
    *param_4 = *param_4 | 8;
    iVar1 = taskTcb(uVar2);
    if ((iVar1 != 0) && (puVar3 = *(undefined4 **)(iVar1 + 0xf0), puVar3 != (undefined4 *)0x0)) {
      for (; puVar3[1] != 0; puVar3 = puVar3 + 3) {
        if ((*(uint *)(puVar3[1] + 4) & 0x1000000) != 0) {
          if ((code *)*DAT_300a7be0 == (code *)0x0) {
            return;
          }
          (*(code *)*DAT_300a7be0)(*puVar3);
          return;
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * excExcHandle @ 0x300A75EC  (примерный размер ~804 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_300a74d4, bcopy, edrErrorInjectStub, edrInitFatalPolicyHandler, edrInterruptFatalPolicyHandler, edrKernelFatalPolicyHandler, intContext, taskIdDefault
 * Константы: 0x300A75EC
 * Данные: DAT_300a7bd4, DAT_300a7be4, DAT_300a7be8, DAT_300a7bec, DAT_300a7bf0, DAT_300a7bf4, DAT_300a7bf8, DAT_300a7bfc
 * ---------------------------------------------------------------- */
void excExcHandle(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_74 [16];
  undefined4 local_64;
  int local_60;
  int local_5c;
  undefined1 *local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  undefined1 *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34 [3];
  int local_28;
  int local_24;
  undefined1 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  uVar5 = *(undefined4 *)(param_1 + 0xc);
  iVar4 = *DAT_300a7bd4;
  FUN_300a74d4(uVar5,param_1,param_2,auStack_74);
  if (((code *)*DAT_300a7be4 == (code *)0x0) ||
     (iVar3 = (*(code *)*DAT_300a7be4)(uVar5,param_1,param_2,auStack_74), iVar3 == 0)) {
    iVar3 = intContext();
    uVar2 = DAT_300a7bfc;
    piVar1 = DAT_300a7bf4;
    if ((iVar3 == 0) && (*DAT_300a7be8 != 1)) {
      if (iVar4 == 0) {
        local_40 = auStack_74;
        local_3c = 1;
        *DAT_300a7bf4 = *DAT_300a7bf4 + 1;
        local_4c = uVar5;
        local_48 = param_1;
        local_44 = param_2;
        edrErrorInjectStub(0x31,DAT_300a7bf8,DAT_300a7c00,param_2,auStack_74,
                           *(undefined4 *)(param_2 + 0x3c),uVar2);
        local_38 = uVar2;
        edrInitFatalPolicyHandler(&local_4c);
        *piVar1 = *piVar1 + -1;
      }
      else {
        *(int *)(iVar4 + 0x120) = param_2;
        taskIdDefault(iVar4);
        bcopy(auStack_74,(void *)(iVar4 + 0x1b4),0x10);
        if ((*(int *)(param_1 + 0xc) == 0x10) && ((code *)*DAT_300a7c04 != (code *)0x0)) {
          (*(code *)*DAT_300a7c04)();
        }
        if ((code *)*DAT_300a7c08 != (code *)0x0) {
          (*(code *)*DAT_300a7c08)(uVar5,uVar5,param_2);
        }
        if ((code *)*DAT_300a7c0c != (code *)0x0) {
          (*(code *)*DAT_300a7c0c)(auStack_74,1,0,0);
        }
        iVar3 = iVar4;
        if (iVar4 == 0) {
          iVar3 = *DAT_300a7bd4;
        }
        if ((*(int *)(iVar3 + 0x94) == *DAT_300a7c10) && ((code *)*DAT_300a7c14 != (code *)0x0)) {
          (*(code *)*DAT_300a7c14)(iVar4,uVar5,param_1);
        }
        uVar2 = DAT_300a7c18;
        local_34[1] = 0;
        local_20 = auStack_74;
        local_1c = 1;
        local_34[0] = iVar4;
        local_34[2] = uVar5;
        local_28 = param_1;
        local_24 = param_2;
        edrErrorInjectStub(0x11,DAT_300a7bf8,DAT_300a7c1c,param_2,local_20,
                           *(undefined4 *)(param_2 + 0x3c),DAT_300a7c18);
        local_18 = uVar2;
        edrKernelFatalPolicyHandler(local_34);
      }
    }
    else {
      iVar4 = intContext();
      local_50 = DAT_300a7bf0;
      if (iVar4 != 0) {
        local_50 = DAT_300a7bec;
      }
      local_58 = auStack_74;
      local_54 = 1;
      *DAT_300a7bf4 = *DAT_300a7bf4 + 1;
      local_64 = uVar5;
      local_60 = param_1;
      local_5c = param_2;
      edrErrorInjectStub(0x21,DAT_300a7bf8,0x284,param_2,auStack_74,*(undefined4 *)(param_2 + 0x3c),
                         local_50);
      edrInterruptFatalPolicyHandler(&local_64);
      *DAT_300a7bf4 = *DAT_300a7bf4 + -1;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * excIntHandle @ 0x300A7910  (примерный размер ~128 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: reboot
 * Константы: 0x300A7910
 * Данные: DAT_300a7bd4, DAT_300a7c20, DAT_300a7c24, DAT_300a7c28
 * ---------------------------------------------------------------- */
void excIntHandle(void)

{
  int iVar1;
  
  iVar1 = *DAT_300a7bd4;
  if ((code *)*DAT_300a7c20 != (code *)0x0) {
    (*(code *)*DAT_300a7c20)();
  }
  if ((code *)*DAT_300a7c24 != (code *)0x0) {
    (*(code *)*DAT_300a7c24)(DAT_300a7c28,0,0,0,0,0,0);
  }
  if (iVar1 == 0) {
    reboot(0);
  }
  return;
}

/* ----------------------------------------------------------------
 * excExcContinue @ 0x300A7990  (примерный размер ~372 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 2
 * Вызывает: FUN_300a74d4, reboot
 * Вызывают: excEnterDataAbort, excEnterPrefetchAbort, excEnterSwi, excEnterUndef
 * Константы: 0x300A7990
 * Данные: DAT_300a7bc4, DAT_300a7bd8, DAT_300a7bdc, DAT_300a7c2c, DAT_300a7c30, DAT_300a7c34, DAT_300a7c38
 * ---------------------------------------------------------------- */
void excExcContinue(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_20 [16];
  
  uVar3 = *(uint *)(param_1 + 0xc);
  piVar1 = *(int **)(param_2 + 0x3c);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (uVar3 != 8) {
    if ((int)uVar3 < 9) {
      if (uVar3 != 0) {
        if (uVar3 != 4) goto LAB_300a7ab4;
        if ((*piVar1 == DAT_300a7bc4) && ((code *)*DAT_300a7c2c != (code *)0x0)) {
          (*(code *)*DAT_300a7c2c)(param_1,param_2);
          return;
        }
        if (((((code *)*DAT_300a7bd8 != (code *)0x0) &&
             (iVar2 = (*(code *)*DAT_300a7bd8)(), iVar2 != 0)) &&
            ((code *)*DAT_300a7bdc != (code *)0x0)) &&
           (((iVar2 = (*(code *)*DAT_300a7bdc)(), iVar2 != 0 &&
             ((code *)*DAT_300a7c30 != (code *)0x0)) &&
            (iVar2 = (*(code *)*DAT_300a7c30)(param_1,param_2), iVar2 != 0)))) {
          return;
        }
      }
    }
    else if ((uVar3 != 0xc) && (uVar3 != 0x10)) {
LAB_300a7ab4:
      FUN_300a74d4(uVar3,param_1,param_2,auStack_20);
      if ((code *)*DAT_300a7c38 != (code *)0x0) {
        (*(code *)*DAT_300a7c38)(uVar3,param_1,param_2,auStack_20);
      }
      reboot(0);
      return;
    }
  }
  (**(code **)(DAT_300a7c34 + (uVar3 >> 2) * 8))(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * excVecSet @ 0x300A7B04  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A7B04
 * Данные: DAT_300a7c3c
 * ---------------------------------------------------------------- */
void excVecSet(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 5;
  piVar1 = DAT_300a7c3c;
  do {
    if ((int *)*piVar1 == param_1) break;
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar3 = 5 - iVar2;
  if (iVar3 < 5) {
    param_1 = DAT_300a7c3c + iVar3 * 2;
  }
  if (0 < iVar2 != SBORROW4(iVar3,5)) {
    param_1[1] = param_2;
  }
  return;
}

/* ----------------------------------------------------------------
 * excVecGet @ 0x300A7B48  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A7B48
 * Данные: DAT_300a7c3c
 * ---------------------------------------------------------------- */
int excVecGet(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 5;
  piVar1 = DAT_300a7c3c;
  do {
    if (*piVar1 == param_1) {
      return piVar1[1];
    }
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

/* ----------------------------------------------------------------
 * excVmStateSet @ 0x300A7B78  (примерный размер ~204 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A7B78, 0xFFFFFFFF
 * Данные: DAT_300a7c40
 * ---------------------------------------------------------------- */
undefined4 excVmStateSet(void)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_300a7c40 + 0x14) == (code *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (**(code **)(DAT_300a7c40 + 0x14))();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * excShowInit @ 0x300A7C44  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrIosExtraInit
 * Константы: 0x300A7C44
 * Данные: DAT_300a8374, DAT_300a8378, DAT_300a837c, DAT_300a8380, DAT_300a8384, DAT_300a8388
 * ---------------------------------------------------------------- */
undefined4 excShowInit(void)

{
  *DAT_300a8378 = DAT_300a8374;
  *DAT_300a8380 = DAT_300a837c;
  *DAT_300a8388 = DAT_300a8384;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300a7c70 @ 0x300A7C70  (примерный размер ~116 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 2
 * Вызывает: oprintf, printExc
 * Вызывают: FUN_300a7ce4, FUN_300a8104, FUN_300a8284
 * Константы: 0x300A7C70
 * ---------------------------------------------------------------- */
void FUN_300a7c70(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  if (param_1 == 0) {
    printExc(param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else if (param_2 == 0) {
    oprintf(0,0,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    oprintf();
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a7ce4 @ 0x300A7CE4  (примерный размер ~1056 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300a7c70
 * Вызывают: FUN_300a8104
 * Константы: 0x300A7CE4, 0x01000000
 * Данные: DAT_300a838c, DAT_300a8390, DAT_300a8394, DAT_300a8398, DAT_300a839c, DAT_300a83a0, DAT_300a83a4, DAT_300a83a8
 * ---------------------------------------------------------------- */
void FUN_300a7ce4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  puVar5 = *(undefined4 **)(param_1 + 0xf0);
  uVar1 = DAT_300a838c;
  if ((puVar5 != (undefined4 *)0x0) && (iVar3 = puVar5[1], uVar1 = DAT_300a8390, iVar3 != 0)) {
    do {
      if ((*(uint *)(iVar3 + 4) & 0x1000000) != 0) break;
      iVar3 = puVar5[4];
      puVar5 = puVar5 + 3;
    } while (iVar3 != 0);
    if (iVar3 != 0) {
      puVar5 = (undefined4 *)*puVar5;
      uVar4 = puVar5[1];
      uVar2 = puVar5[2];
      uVar6 = puVar5[3];
      uVar1 = puVar5[4];
      FUN_300a7c70(param_2,param_3,DAT_300a8394,*puVar5,0,0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a8398,uVar4,0,0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a839c,uVar2,0,0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83a0,uVar6,0,0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83a4,uVar1,0,0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83a8,puVar5[7],puVar5[8],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83ac,puVar5[9],puVar5[10],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83b0,puVar5[0xb],puVar5[0xc],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83b4,puVar5[0xd],puVar5[0xe],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83b8,puVar5[0xf],puVar5[0x10],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83bc,puVar5[0x11],puVar5[0x12],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83c0,puVar5[0x13],puVar5[0x14],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83c4,puVar5[0x15],puVar5[0x16],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83c8,puVar5[0x17],puVar5[0x18],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83cc,puVar5[0x19],puVar5[0x1a],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83d0,puVar5[0x1b],puVar5[0x1c],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83d4,puVar5[0x1d],puVar5[0x1e],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83d8,puVar5[0x1f],puVar5[0x20],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83dc,puVar5[0x21],puVar5[0x22],0,0,0);
      FUN_300a7c70(param_2,param_3,DAT_300a83e0,puVar5[0x23],puVar5[0x24],0,0,0);
      uVar6 = puVar5[0x26];
      param_1 = puVar5[0x25];
      uVar1 = DAT_300a83e4;
      goto LAB_300a80f0;
    }
  }
  uVar6 = 0;
LAB_300a80f0:
  FUN_300a7c70(param_2,param_3,uVar1,param_1,uVar6,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a8104 @ 0x300A8104  (примерный размер ~384 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300a7c70, FUN_300a7ce4, taskName
 * Вызывают: FUN_300a830c
 * Константы: 0x300A8104
 * Данные: DAT_300a83e8, DAT_300a83ec, DAT_300a83f0, DAT_300a83f4, DAT_300a83f8, DAT_300a83fc, DAT_300a8400
 * ---------------------------------------------------------------- */
void FUN_300a8104(uint *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar4 = *DAT_300a83e8;
  if (param_1 != (uint *)0x0) {
    uVar5 = *param_1;
    uVar3 = param_1[1];
    if ((uVar5 & 1) != 0) {
      iVar6 = 0;
      uVar7 = *DAT_300a83ec;
      puVar2 = DAT_300a83ec;
      while (uVar1 = DAT_300a83f4, uVar7 != uVar3) {
        if (puVar2[1] == 0) goto LAB_300a81bc;
        puVar2 = puVar2 + 2;
        iVar6 = iVar6 + 1;
        uVar7 = *puVar2;
      }
      if (DAT_300a83ec[iVar6 * 2 + 1] != 0) {
        uVar1 = DAT_300a83f0;
        uVar3 = DAT_300a83ec[iVar6 * 2 + 1];
      }
LAB_300a81bc:
      FUN_300a7c70(param_3,param_4,uVar1,uVar3,0,0,0,0);
    }
    if ((uVar5 & 2) != 0) {
      FUN_300a7c70(param_3,param_4,DAT_300a83f8,param_1[2],0,0,0,0);
    }
    if ((uVar5 & 4) != 0) {
      FUN_300a7c70(param_3,param_4,DAT_300a83fc,param_1[3],0,0,0,0);
    }
    if ((uVar5 & 8) != 0) {
      FUN_300a7ce4(uVar4,param_3,param_4);
    }
    if (param_2 != 0) {
      uVar1 = taskName(uVar4);
      FUN_300a7c70(param_3,param_4,DAT_300a8400,uVar4,uVar1,0,0,0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a8284 @ 0x300A8284  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300a7c70
 * Константы: 0x300A8284
 * Данные: DAT_300a83e8, DAT_300a8404, DAT_300a8408
 * ---------------------------------------------------------------- */
void FUN_300a8284(void)

{
  if (*DAT_300a83e8 == 0) {
    FUN_300a7c70(0,0,DAT_300a8404,0,0,0,0,0);
  }
  else if ((code *)*DAT_300a8408 != (code *)0x0) {
    (*(code *)*DAT_300a8408)(DAT_300a8404,0,0,0,0,0,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a830c @ 0x300A830C  (примерный размер ~304 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300a8104, printExc
 * Константы: 0x300A830C
 * Данные: DAT_300a840c, DAT_300a8410
 * ---------------------------------------------------------------- */
void FUN_300a830c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  printExc(DAT_300a840c,0,0,0,0,0);
  FUN_300a8104(param_4,0,0,0);
  printExc(DAT_300a8410,param_3,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * intCpuLock @ 0x300A843C  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 31 | Вызывает: 0
 * Вызывают: BSP_CLK_Value, BSP_OM_SoftReboot, BSP_SSI_GetAttr, BSP_SSI_Read, BSP_SSI_SetAttr, BSP_SSI_Write, BSP_TLED_LedFlush, BSP_USB_RegEnumDoneForMsp, BSP_USB_RegEnumDoneForPs, BSP_WDT_reboot_direct
 *           ...
 * Константы: 0x300A843C
 * ---------------------------------------------------------------- */
longlong intCpuLock(void)

{
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  return (ulonglong)
         ((uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b | 0x80) <<
         0x20;
}

/* ----------------------------------------------------------------
 * intCpuUnlock @ 0x300A8450  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 31 | Вызывает: 0
 * Вызывают: BSP_CLK_Value, BSP_INT_UnLock, BSP_SSI_GetAttr, BSP_SSI_Read, BSP_SSI_SetAttr, BSP_SSI_Write, BSP_TLED_LedFlush, BSP_USB_RegEnumDoneForMsp, BSP_USB_RegEnumDoneForPs, FUN_300067b0
 *           ...
 * Константы: 0x300A8450
 * ---------------------------------------------------------------- */
void intCpuUnlock(void)

{
  return;
}

/* ----------------------------------------------------------------
 * intCpuMicroLock @ 0x300A8468  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A8468
 * ---------------------------------------------------------------- */
void intCpuMicroLock(void)

{
  return;
}

/* ----------------------------------------------------------------
 * intCpuMicroUnlock @ 0x300A8478  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A8478
 * ---------------------------------------------------------------- */
void intCpuMicroUnlock(void)

{
  return;
}

/* ----------------------------------------------------------------
 * intIFLock @ 0x300A8480  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 6 | Вызывает: 0
 * Вызывают: FUN_300ac2b4, FUN_300ac2dc, cacheAimArch7DDisable, cacheAimArch7DEnable, cacheAimArch7IDisable, sysToMonitor
 * Константы: 0x300A8480
 * ---------------------------------------------------------------- */
longlong intIFLock(void)

{
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  return (ulonglong)
         ((uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b | 0xc0) <<
         0x20;
}

/* ----------------------------------------------------------------
 * intIFUnlock @ 0x300A8494  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 6 | Вызывает: 0
 * Вызывают: FUN_300ac2b4, FUN_300ac2dc, FUN_300ad138, cacheAimArch7DDisable, cacheAimArch7DEnable, cacheAimArch7IDisable
 * Константы: 0x300A8494
 * ---------------------------------------------------------------- */
void intIFUnlock(void)

{
  return;
}

/* ----------------------------------------------------------------
 * intEnt @ 0x300A84B0  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: reschedule, windPwrUp
 * Константы: 0x300A84B0
 * Данные: DAT_300a8414, DAT_300a8418, DAT_300a841c, DAT_300a8420, DAT_300a8424, DAT_300a8428, DAT_300a842c, DAT_300a8430
 * ---------------------------------------------------------------- */
undefined8 intEnt(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  undefined4 unaff_r5;
  uint uVar6;
  undefined4 unaff_r6;
  uint uVar7;
  undefined4 unaff_r7;
  uint uVar8;
  undefined4 unaff_r8;
  uint uVar9;
  undefined4 unaff_r9;
  uint uVar10;
  undefined4 unaff_r10;
  uint uVar11;
  undefined4 unaff_r11;
  undefined4 in_r12;
  undefined4 *puVar12;
  int in_lr;
  int iVar13;
  undefined4 uVar14;
  byte in_Q;
  byte bVar15;
  bool bVar16;
  undefined8 uVar17;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_1c = 0;
  bVar15 = (in_Q & 1) != 0;
  iVar2 = *DAT_300a8420;
  *DAT_300a8420 = iVar2 + 1;
  puVar12 = &uStack_1c;
  if (iVar2 + 1 == 1) {
    puVar12 = *(undefined4 **)DAT_300a8424;
  }
  uVar3 = *DAT_300a8418;
  uStack_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  uStack_c = param_4;
  puVar12[-1] = in_lr + -4;
  puVar12[-2] = in_r12;
  puVar12[-3] = &uStack_1c;
  puVar12[-4] = &uStack_1c;
  puVar12[-5] = uVar3;
  *DAT_300a841c = *DAT_300a841c + 1;
  if (*DAT_300a8420 == 1) {
    windPwrUp();
  }
  (*(code *)*DAT_300a8428)();
  bVar16 = (bVar15 & 1) != 0;
  *DAT_300a8418 = puVar12[-5];
  piVar1 = DAT_300a8420;
  iVar2 = *DAT_300a8420;
  if ((iVar2 < 2) &&
     ((((*(uint *)puVar12[-3] & 0xf) == 3 || ((*(uint *)puVar12[-3] & 0xf) == 0)) &&
      (*DAT_300a842c == 0)))) {
    iVar4 = *DAT_300a8434;
    iVar13 = *DAT_300a8430;
    if (iVar13 != 0) {
      *DAT_300a842c = 1;
      *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + 1;
      piVar1 = DAT_300a8420;
      *DAT_300a841c = 0;
      *piVar1 = 0;
      uVar17 = reschedule(iVar4,(uint)(byte)((iVar13 < 0) << 4 | (iVar13 == 0) << 3 |
                                             (iVar2 != 0) << 2 | SBORROW4(iVar2,1) << 1 | bVar16) <<
                                0x1b);
      return uVar17;
    }
    if ((iVar4 + 0x50 != *DAT_300a8438) &&
       ((*(int *)(iVar4 + 0x7c) == 0 || (*(int *)(iVar4 + 0x70) != 0)))) {
      iVar13 = puVar12[-4];
      puVar5 = (uint *)puVar12[-3];
      uVar3 = puVar12[-2];
      uVar14 = puVar12[-1];
      if ((*puVar5 & 0xf) == 0) {
        *(undefined4 *)(iVar4 + 0x1e4) = unaff_r5;
        *(undefined4 *)(iVar4 + 0x1e8) = unaff_r6;
        *(undefined4 *)(iVar4 + 0x1ec) = unaff_r7;
        *(undefined4 *)(iVar4 + 0x1f0) = unaff_r8;
        *(undefined4 *)(iVar4 + 500) = unaff_r9;
        *(undefined4 *)(iVar4 + 0x1f8) = unaff_r10;
        *(undefined4 *)(iVar4 + 0x1fc) = unaff_r11;
        *(undefined4 *)(iVar4 + 0x200) = uVar3;
        *(int *)(iVar4 + 0x204) = iVar13;
        *(undefined4 *)(iVar4 + 0x208) = uVar14;
      }
      else {
        *(undefined4 *)(iVar4 + 0x1e4) = unaff_r5;
        *(undefined4 *)(iVar4 + 0x1e8) = unaff_r6;
        *(undefined4 *)(iVar4 + 0x1ec) = unaff_r7;
        *(undefined4 *)(iVar4 + 0x1f0) = unaff_r8;
        *(undefined4 *)(iVar4 + 500) = unaff_r9;
        *(undefined4 *)(iVar4 + 0x1f8) = unaff_r10;
        *(undefined4 *)(iVar4 + 0x1fc) = unaff_r11;
        *(undefined4 *)(iVar4 + 0x200) = uVar3;
        *(int *)(iVar4 + 0x204) = iVar13;
        *(undefined4 *)(iVar4 + 0x208) = uVar14;
      }
      uVar6 = puVar5[1];
      uVar7 = puVar5[2];
      uVar8 = puVar5[3];
      uVar9 = puVar5[4];
      uVar10 = puVar5[5];
      uVar11 = puVar5[6];
      *(uint *)(iVar4 + 0x210) = *puVar5;
      *(uint *)(iVar4 + 0x1e0) = uVar10;
      *(uint *)(iVar4 + 0x1dc) = uVar9;
      *(uint *)(iVar4 + 0x1d8) = uVar8;
      *(uint *)(iVar4 + 0x1d4) = uVar7;
      *(uint *)(iVar4 + 0x1d0) = uVar6;
      *(uint *)(iVar4 + 0x20c) = uVar11;
      *(undefined4 *)(iVar4 + 0x1c4) = *DAT_300a8414;
      uVar3 = coproc_movefrom_Translation_table_base_0();
      *(undefined4 *)(iVar4 + 0x214) = uVar3;
      iVar13 = *(int *)(iVar4 + 0x6c);
      *(int *)(iVar4 + 0x6c) = iVar13 + 1;
      *DAT_300a842c = 1;
      piVar1 = DAT_300a8420;
      *DAT_300a841c = 0;
      *piVar1 = 0;
      uVar17 = reschedule(iVar4,(uint)(byte)((iVar13 < 0) << 4 | (iVar13 == 0) << 3 |
                                             (iVar2 != 0) << 2 | SBORROW4(iVar2,1) << 1 | bVar16) <<
                                0x1b);
      return uVar17;
    }
  }
  *DAT_300a841c = *DAT_300a841c + -1;
  *piVar1 = *piVar1 + -1;
  return *(undefined8 *)(puVar12[-4] + 4);
}

/* ----------------------------------------------------------------
 * intExit @ 0x300A852C  (примерный размер ~492 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: reschedule
 * Константы: 0x300A852C
 * Данные: DAT_300a8414, DAT_300a8418, DAT_300a841c, DAT_300a8420, DAT_300a842c, DAT_300a8430, DAT_300a8434, DAT_300a8438
 * ---------------------------------------------------------------- */
undefined8 intExit(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_r5;
  uint uVar5;
  undefined4 unaff_r6;
  uint uVar6;
  undefined4 unaff_r7;
  uint uVar7;
  undefined4 unaff_r8;
  uint uVar8;
  undefined4 unaff_r9;
  uint uVar9;
  undefined4 unaff_r10;
  uint uVar10;
  undefined4 unaff_r11;
  int iVar11;
  byte in_Q;
  bool bVar12;
  undefined8 uVar13;
  undefined4 in_stack_00000000;
  int in_stack_00000004;
  uint *in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  
  bVar12 = (in_Q & 1) != 0;
  *DAT_300a8418 = in_stack_00000000;
  piVar1 = DAT_300a8420;
  iVar2 = *DAT_300a8420;
  if ((iVar2 < 2) &&
     ((((*in_stack_00000008 & 0xf) == 3 || ((*in_stack_00000008 & 0xf) == 0)) &&
      (*DAT_300a842c == 0)))) {
    iVar3 = *DAT_300a8434;
    iVar11 = *DAT_300a8430;
    if (iVar11 != 0) {
      *DAT_300a842c = 1;
      *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + 1;
      piVar1 = DAT_300a8420;
      *DAT_300a841c = 0;
      *piVar1 = 0;
      uVar13 = reschedule(iVar3,(uint)(byte)((iVar11 < 0) << 4 | (iVar11 == 0) << 3 |
                                             (iVar2 != 0) << 2 | SBORROW4(iVar2,1) << 1 | bVar12) <<
                                0x1b);
      return uVar13;
    }
    if ((iVar3 + 0x50 != *DAT_300a8438) &&
       ((*(int *)(iVar3 + 0x7c) == 0 || (*(int *)(iVar3 + 0x70) != 0)))) {
      if ((*in_stack_00000008 & 0xf) == 0) {
        *(undefined4 *)(iVar3 + 0x1e4) = unaff_r5;
        *(undefined4 *)(iVar3 + 0x1e8) = unaff_r6;
        *(undefined4 *)(iVar3 + 0x1ec) = unaff_r7;
        *(undefined4 *)(iVar3 + 0x1f0) = unaff_r8;
        *(undefined4 *)(iVar3 + 500) = unaff_r9;
        *(undefined4 *)(iVar3 + 0x1f8) = unaff_r10;
        *(undefined4 *)(iVar3 + 0x1fc) = unaff_r11;
        *(undefined4 *)(iVar3 + 0x200) = in_stack_0000000c;
        *(int *)(iVar3 + 0x204) = in_stack_00000004;
        *(undefined4 *)(iVar3 + 0x208) = in_stack_00000010;
      }
      else {
        *(undefined4 *)(iVar3 + 0x1e4) = unaff_r5;
        *(undefined4 *)(iVar3 + 0x1e8) = unaff_r6;
        *(undefined4 *)(iVar3 + 0x1ec) = unaff_r7;
        *(undefined4 *)(iVar3 + 0x1f0) = unaff_r8;
        *(undefined4 *)(iVar3 + 500) = unaff_r9;
        *(undefined4 *)(iVar3 + 0x1f8) = unaff_r10;
        *(undefined4 *)(iVar3 + 0x1fc) = unaff_r11;
        *(undefined4 *)(iVar3 + 0x200) = in_stack_0000000c;
        *(int *)(iVar3 + 0x204) = in_stack_00000004;
        *(undefined4 *)(iVar3 + 0x208) = in_stack_00000010;
      }
      uVar5 = in_stack_00000008[1];
      uVar6 = in_stack_00000008[2];
      uVar7 = in_stack_00000008[3];
      uVar8 = in_stack_00000008[4];
      uVar9 = in_stack_00000008[5];
      uVar10 = in_stack_00000008[6];
      *(uint *)(iVar3 + 0x210) = *in_stack_00000008;
      *(uint *)(iVar3 + 0x1e0) = uVar9;
      *(uint *)(iVar3 + 0x1dc) = uVar8;
      *(uint *)(iVar3 + 0x1d8) = uVar7;
      *(uint *)(iVar3 + 0x1d4) = uVar6;
      *(uint *)(iVar3 + 0x1d0) = uVar5;
      *(uint *)(iVar3 + 0x20c) = uVar10;
      *(undefined4 *)(iVar3 + 0x1c4) = *DAT_300a8414;
      uVar4 = coproc_movefrom_Translation_table_base_0();
      *(undefined4 *)(iVar3 + 0x214) = uVar4;
      iVar11 = *(int *)(iVar3 + 0x6c);
      *(int *)(iVar3 + 0x6c) = iVar11 + 1;
      *DAT_300a842c = 1;
      piVar1 = DAT_300a8420;
      *DAT_300a841c = 0;
      *piVar1 = 0;
      uVar13 = reschedule(iVar3,(uint)(byte)((iVar11 < 0) << 4 | (iVar11 == 0) << 3 |
                                             (iVar2 != 0) << 2 | SBORROW4(iVar2,1) << 1 | bVar12) <<
                                0x1b);
      return uVar13;
    }
  }
  *DAT_300a841c = *DAT_300a841c + -1;
  *piVar1 = *piVar1 + -1;
  return *(undefined8 *)(in_stack_00000004 + 4);
}

