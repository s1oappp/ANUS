/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : boot — стартовая цепочка VxWorks (sysInit -> usrRoot), инициализация CPU/кэшей
 * Часть  : 1 (функций: 14, адреса 0x30004000..0x30122460)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * sysInit @ 0x30004000  (примерный размер ~8 байт)
 * Модуль: boot | Вызывают: 0 | Вызывает: 1
 * Вызывает: usrInit
 * Константы: 0x30004000, 0xFFFFFF00, 0x07000000, 0x30000000
 * Данные: DAT_30004158, DAT_3000415c, DAT_30004160, DAT_30004164, DAT_30004168, DAT_3000416c, DAT_30004170, _DAT_0800000c
 * ---------------------------------------------------------------- */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sysInit(void)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 in_cr0;
  
  iVar2 = DAT_30004164;
  uVar4 = coproc_movefrom_Translation_table_base_0();
  coproc_moveto_Translation_table_base_0(uVar4 & 0xffffff00);
  coproc_moveto_Control(DAT_30004158);
  coproc_moveto_Data_Synchronization(0);
  uVar4 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
  uVar8 = uVar4 & 0x7000000;
  if (uVar8 != 0) {
    uVar11 = 0;
    while( true ) {
      if (1 < (uVar4 & 7)) {
        coprocessor_moveto(0xf,2,0,uVar11,in_cr0,in_cr0);
        coproc_moveto_Flush_Prefetch_Buffer(uVar11);
        uVar5 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
        uVar9 = DAT_3000415c & uVar5 >> 3;
        uVar6 = uVar9;
        uVar10 = DAT_30004160 & uVar5 >> 0xd;
        do {
          do {
            coproc_moveto_Invalidate_Entire_Data_by_Index
                      (uVar11 | uVar6 << LZCOUNT(uVar9) | uVar10 << (uVar5 & 7) + 4);
            bVar1 = 0 < (int)uVar6;
            uVar6 = uVar6 - 1;
          } while (bVar1);
          bVar1 = 0 < (int)uVar10;
          uVar6 = uVar9;
          uVar10 = uVar10 - 1;
        } while (bVar1);
      }
      uVar11 = uVar11 + 2;
      if ((int)(uVar8 >> 0x17) <= (int)uVar11) break;
      uVar4 = uVar4 >> 3;
    }
  }
  *(undefined4 *)(DAT_30004164 + 0x470) = 0x30000000;
  *(undefined4 *)(iVar2 + 0x474) = DAT_30004168;
  *(uint *)(iVar2 + 0x400) = *(uint *)(iVar2 + 0x400) | 1;
  _DAT_0800000c = 0;
  coproc_moveto_FCSE_PID(0);
  coproc_moveto_Context_ID(0);
  *DAT_3000416c = 0;
  puVar3 = DAT_30004170;
  *DAT_30004170 = 0;
  puVar3[2] = 0;
  uVar7 = 0;
  if ((((uVar4 != 0) && (uVar7 = 1, uVar4 != 1)) && (uVar7 = 2, uVar4 != 2)) &&
     (uVar7 = 4, uVar4 != 4)) {
    uVar4 = 0;
  }
  usrInit(uVar4,uVar7,puVar3,0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30004008 @ 0x30004008  (примерный размер ~324 байт)
 * Модуль: boot | Вызывают: 0 | Вызывает: 1
 * Вызывает: usrInit
 * Константы: 0x30004008, 0xFFFFFF00, 0x07000000, 0x30000000
 * Данные: DAT_30004158, DAT_3000415c, DAT_30004160, DAT_30004164, DAT_30004168, DAT_3000416c, DAT_30004170, _DAT_0800000c
 * ---------------------------------------------------------------- */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_30004008(void)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 in_cr0;
  
  iVar2 = DAT_30004164;
  uVar4 = coproc_movefrom_Translation_table_base_0();
  coproc_moveto_Translation_table_base_0(uVar4 & 0xffffff00);
  coproc_moveto_Control(DAT_30004158);
  coproc_moveto_Data_Synchronization(0);
  uVar4 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
  uVar8 = uVar4 & 0x7000000;
  if (uVar8 != 0) {
    uVar11 = 0;
    while( true ) {
      if (1 < (uVar4 & 7)) {
        coprocessor_moveto(0xf,2,0,uVar11,in_cr0,in_cr0);
        coproc_moveto_Flush_Prefetch_Buffer(uVar11);
        uVar5 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
        uVar9 = DAT_3000415c & uVar5 >> 3;
        uVar6 = uVar9;
        uVar10 = DAT_30004160 & uVar5 >> 0xd;
        do {
          do {
            coproc_moveto_Invalidate_Entire_Data_by_Index
                      (uVar11 | uVar6 << LZCOUNT(uVar9) | uVar10 << (uVar5 & 7) + 4);
            bVar1 = 0 < (int)uVar6;
            uVar6 = uVar6 - 1;
          } while (bVar1);
          bVar1 = 0 < (int)uVar10;
          uVar6 = uVar9;
          uVar10 = uVar10 - 1;
        } while (bVar1);
      }
      uVar11 = uVar11 + 2;
      if ((int)(uVar8 >> 0x17) <= (int)uVar11) break;
      uVar4 = uVar4 >> 3;
    }
  }
  *(undefined4 *)(DAT_30004164 + 0x470) = 0x30000000;
  *(undefined4 *)(iVar2 + 0x474) = DAT_30004168;
  *(uint *)(iVar2 + 0x400) = *(uint *)(iVar2 + 0x400) | 1;
  _DAT_0800000c = 0;
  coproc_moveto_FCSE_PID(0);
  coproc_moveto_Context_ID(0);
  *DAT_3000416c = 0;
  puVar3 = DAT_30004170;
  *DAT_30004170 = 0;
  puVar3[2] = 0;
  uVar7 = 0;
  if ((((uVar4 != 0) && (uVar7 = 1, uVar4 != 1)) && (uVar7 = 2, uVar4 != 2)) &&
     (uVar7 = 4, uVar4 != 4)) {
    uVar4 = 0;
  }
  usrInit(uVar4,uVar7,puVar3,0);
  return;
}

/* ----------------------------------------------------------------
 * archPwrDown @ 0x3000414C  (примерный размер ~40 байт)
 * Модуль: boot | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000414C
 * ---------------------------------------------------------------- */
undefined4 archPwrDown(void)

{
  coproc_moveto_Wait_for_interrupt(1);
  return 1;
}

/* ----------------------------------------------------------------
 * sysModel @ 0x30004304  (примерный размер ~8 байт)
 * Модуль: boot | Вызывают: 2 | Вызывает: 0
 * Вызывают: usrBanner, version
 * Константы: 0x30004304
 * Данные: DAT_30004600
 * ---------------------------------------------------------------- */
undefined4 sysModel(void)

{
  return DAT_30004600;
}

/* ----------------------------------------------------------------
 * sysBspRev @ 0x3000430C  (примерный размер ~8 байт)
 * Модуль: boot | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000430C
 * Данные: DAT_30004604
 * ---------------------------------------------------------------- */
undefined4 sysBspRev(void)

{
  return DAT_30004604;
}

/* ----------------------------------------------------------------
 * sysHwInit @ 0x30004334  (примерный размер ~44 байт)
 * Модуль: boot | Вызывают: 1 | Вызывает: 3
 * Вызывает: strlen, strncpy, sysSerialHwInit
 * Вызывают: usrInit
 * Константы: 0x30004334
 * Данные: DAT_30004610, DAT_30004614
 * ---------------------------------------------------------------- */
void sysHwInit(void)

{
  size_t sVar1;
  
  sysSerialHwInit();
  sVar1 = strlen(DAT_30004610);
  strncpy((char *)*DAT_30004614,DAT_30004610,sVar1 + 1);
  return;
}

/* ----------------------------------------------------------------
 * sysTimestamp @ 0x30008D90  (примерный размер ~28 байт)
 * Модуль: boot | Вызывают: 1 | Вызывает: 2
 * Вызывает: TIMER_BASE, sysTimestampPeriod
 * Вызывают: sysTimestampLock
 * Константы: 0x30008D90
 * ---------------------------------------------------------------- */
int sysTimestamp(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = TIMER_BASE(0);
  iVar2 = *(int *)(iVar1 + 4);
  iVar1 = sysTimestampPeriod();
  return iVar1 - iVar2;
}

/* ----------------------------------------------------------------
 * usrKernelInit @ 0x3003FBD8  (примерный размер ~268 байт)
 * Модуль: boot | Вызывают: 1 | Вызывает: 6
 * Вызывает: bfill, kernelInit, qInit, sysMemTop, taskLibInit, workQInit
 * Вызывают: usrInit
 * Константы: 0x3003FBD8
 * Данные: DAT_300405d8, DAT_300405dc, DAT_300405e0, DAT_300405e4, DAT_300405e8, DAT_300405ec, DAT_300405f0, DAT_300405f4
 * ---------------------------------------------------------------- */
void usrKernelInit(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  *DAT_300405dc = DAT_300405d8;
  *DAT_300405e0 = 8;
  *DAT_300405e4 = param_1;
  taskLibInit(0x2000,0x1000,0,0x1000,0x1000,0x1000,0x1000);
  *DAT_300405ec = *DAT_300405e8;
  DAT_300405ec[1] = DAT_300405f0;
  DAT_300405ec[2] = 0x120;
  qInit(DAT_300405f4,*DAT_300405f8);
  workQInit(0x40);
  uVar1 = sysMemTop();
  *DAT_300405fc = uVar1;
  bfill(&local_38,0x30,0);
  local_38 = DAT_30040600;
  local_34 = 0x4000;
  local_30 = DAT_30040604;
  local_2c = *DAT_300405fc;
  local_28 = 0x2000;
  local_24 = 0;
  local_20 = 0x1000;
  kernelInit(DAT_30040608,&local_38);
  return;
}

/* ----------------------------------------------------------------
 * sysStart @ 0x30040198  (примерный размер ~52 байт)
 * Модуль: boot | Вызывают: 1 | Вызывает: 3
 * Вызывает: bzero, intVecBaseSet, sysHwInit0
 * Вызывают: usrInit
 * Константы: 0x30040198
 * Данные: DAT_3004055c, DAT_30040604, DAT_30040680
 * ---------------------------------------------------------------- */
void sysStart(undefined4 param_1)

{
  sysHwInit0();
  bzero(DAT_30040680,DAT_30040604 - (int)DAT_30040680);
  *DAT_3004055c = param_1;
  intVecBaseSet(0);
  return;
}

/* ----------------------------------------------------------------
 * usrInit @ 0x30040280  (примерный размер ~116 байт)
 * Модуль: boot | Вызывают: 2 | Вызывает: 13
 * Вызывает: cacheLibInit, classLibInit, classListLibInit, excVecInit, kernelBaseInit, objInfoInit, objLibInit, semLibInit, sysHwInit, sysStart, usrCacheEnable, usrKernelInit, vxMemProbeInit
 * Вызывают: FUN_30004008, sysInit
 * Константы: 0x30040280
 * Данные: DAT_30040684, DAT_3004069c, DAT_300406a0
 * ---------------------------------------------------------------- */
void usrInit(undefined4 param_1)

{
  sysStart(param_1);
  cacheLibInit(2,2);
  excVecInit();
  sysHwInit();
  usrCacheEnable();
  objInfoInit();
  objLibInit(DAT_3004069c,DAT_300406a0,*DAT_30040684,0);
  vxMemProbeInit();
  classListLibInit();
  semLibInit();
  classLibInit();
  kernelBaseInit();
  usrKernelInit(0);
  return;
}

/* ----------------------------------------------------------------
 * usrRoot @ 0x300404BC  (примерный размер ~124 байт)
 * Модуль: boot | Вызывают: 0 | Вызывает: 19
 * Вызывает: cplusCtorsLink, edrStubInit, edrSystemDebugModeInit, envLibInit, mathSoftInit, memInfoInit, memInit, memPartLibInit, poolLibInit, selTaskDeleteHookAdd, sysClkInit, usrAppInit, usrIosCoreInit, usrIosExtraInit
 *           ...
 * Константы: 0x300404BC
 * ---------------------------------------------------------------- */
void usrRoot(undefined4 param_1,undefined4 param_2)

{
  usrKernelCoreInit();
  poolLibInit();
  memInit(param_1,param_2,0xbb0);
  memPartLibInit(param_1,param_2);
  memInfoInit();
  usrMmuInit(param_1,param_2);
  envLibInit(1);
  edrSystemDebugModeInit();
  usrSysHwInit2();
  sysClkInit();
  edrStubInit();
  mathSoftInit();
  usrIosCoreInit();
  usrKernelExtraInit();
  usrIosExtraInit();
  selTaskDeleteHookAdd();
  cplusCtorsLink();
  usrToolsInit();
  usrAppInit();
  return;
}

/* ----------------------------------------------------------------
 * FUN_30040538 @ 0x30040538  (примерный размер ~380 байт)
 * Модуль: boot | Вызывают: 1 | Вызывает: 1
 * Вызывает: symTblAdd
 * Вызывают: usrStandaloneInit
 * Константы: 0x30040538
 * Данные: DAT_3004065c
 * ---------------------------------------------------------------- */
void FUN_30040538(undefined4 param_1)

{
  symTblAdd(*DAT_3004065c,param_1);
  return;
}

/* ----------------------------------------------------------------
 * intVBRSet @ 0x300A84AC  (примерный размер ~4 байт)
 * Модуль: boot | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A84AC
 * ---------------------------------------------------------------- */
void intVBRSet(void)

{
  return;
}

/* ----------------------------------------------------------------
 * kernelInit @ 0x30122460  (примерный размер ~772 байт)
 * Модуль: boot | Вызывают: 1 | Вызывает: 10
 * Вызывает: bfill, edrErrorInjectStub, edrKernelFatalPolicyHandler, intLockLevelSet, qInit, sprintf, sysToMonitor, taskActivate, taskInitExcStk, windIntStackSet
 * Вызывают: usrKernelInit
 * Константы: 0xFFFFFFFC, 0x30122460
 * Данные: DAT_301228d0, DAT_301228d4, DAT_301228d8, DAT_301228dc, DAT_301228e0, DAT_301228e4, DAT_301228e8, DAT_301228ec
 * ---------------------------------------------------------------- */
void kernelInit(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  char *__s;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 auStack_260 [96];
  undefined4 local_200;
  undefined4 local_1f0;
  undefined4 local_1cc;
  
  qInit(DAT_301228d4,*DAT_301228d0,DAT_301228d0[1],DAT_301228d0[2]);
  if (param_1 != DAT_301228d8) {
    __s = (char *)*DAT_301228dc;
    iVar2 = sprintf(__s,DAT_301228e0,param_1,DAT_301228d8);
    *DAT_301228dc = __s + iVar2;
    sysToMonitor(1);
  }
  uVar4 = *DAT_301228e4 + 3 & 0xfffffffc;
  *DAT_301228e4 = uVar4;
  *DAT_301228e8 = uVar4 + param_2[1] + 3 & 0xfffffffc;
  iVar7 = param_2[7];
  iVar2 = 4;
  if ((iVar7 == 0) && (param_2[8] == 0)) {
    param_2[4] = param_2[4] + 3 & 0xfffffffc;
  }
  else {
    iVar2 = param_2[6];
    uVar4 = ~(iVar2 - 1U);
    uVar3 = (iVar2 + param_2[8]) - 1U & uVar4;
    *DAT_301228ec = uVar3;
    uVar5 = (iVar2 + iVar7) - 1U & uVar4;
    *DAT_301228f0 = uVar5;
    param_2[4] = uVar5 + uVar3 + ((iVar2 + param_2[4]) - 1U & uVar4);
  }
  param_2[3] = param_2[3] & ~(iVar2 - 1U);
  intLockLevelSet(param_2[5]);
  *DAT_301228f4 = 0;
  puVar1 = DAT_301228f8;
  *DAT_301228f8 = 0;
  puVar1[1] = 0;
  uVar4 = (iVar2 + param_2[2]) - 1U & ~(iVar2 - 1U);
  *DAT_301228fc = uVar4;
  iVar7 = param_2[4];
  iVar2 = uVar4 + iVar7;
  *DAT_30122900 = iVar2;
  if (*DAT_30122904 == 0) {
    bfill(uVar4,iVar7,0xee);
  }
  *DAT_30122900 = *DAT_30122900 - *DAT_301228ec;
  *DAT_301228fc = *DAT_301228fc + *DAT_301228f0;
  windIntStackSet();
  *DAT_30122908 = 0;
  uVar4 = *DAT_301228e4;
  iVar6 = (*DAT_301228e8 - uVar4) + -700;
  iVar7 = param_2[3] - *DAT_301228e8;
  *DAT_3012290c = iVar7;
  iVar8 = iVar7 + iVar6 + uVar4;
  iVar9 = iVar8 + 0x38;
  bfill(auStack_260,0x244,0);
  local_1cc = *DAT_30122910;
  local_1f0 = 8;
  iVar10 = *DAT_3012290c;
  *DAT_30122914 = iVar9;
  taskInitExcStk(iVar9,DAT_30122918,0,7,iVar9,iVar6,iVar7 + uVar4 + 0x38,*DAT_301228e4,*param_2,
                 iVar2,iVar10 - iVar2,0,0,0,0,0,0,0,0);
  *DAT_30122908 = (int)auStack_260;
  local_200 = *(undefined4 *)(iVar8 + 0x98);
  taskActivate(iVar9);
  edrErrorInjectStub(0x11,DAT_30122920,DAT_30122924,0,0,0,DAT_3012291c);
  edrKernelFatalPolicyHandler(0);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

