/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 11 (функций: 150, адреса 0x300E390C..0x300EDD18)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * objMemAlloc @ 0x300E390C  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoSet
 * Константы: 0x300E390C
 * Данные: DAT_300e3fa0, DAT_300e3fb0
 * ---------------------------------------------------------------- */
undefined4 objMemAlloc(undefined4 param_1)

{
  undefined4 uVar1;
  
  if ((code *)*DAT_300e3fa0 == (code *)0x0) {
    errnoSet(DAT_300e3fb0,param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)*DAT_300e3fa0)(DAT_300e3fa0[2]);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * objMemFree @ 0x300E3954  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoSet
 * Константы: 0x300E3954, 0xFFFFFFFF
 * Данные: DAT_300e3fa0, DAT_300e3fb0
 * ---------------------------------------------------------------- */
undefined4 objMemFree(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_300e3fa0 + 4) == (code *)0x0) {
    errnoSet(DAT_300e3fb0,param_1);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (**(code **)(DAT_300e3fa0 + 4))(*(undefined4 *)(DAT_300e3fa0 + 8));
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * objFree @ 0x300E399C  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 12 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: FUN_300f2198, FUN_30122a44, FUN_30124a88, FUN_30128940, msgQCreate, semBCreate, semCCreate, semMCreate, semRWCreate, taskCreateWithGuard
 *           ...
 * Константы: 0xFFFFFFFF, 0x300E399C
 * Данные: DAT_300e3fa0, DAT_300e3fb0
 * ---------------------------------------------------------------- */
undefined4 objFree(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 4) == param_1) && (*(char *)(param_1 + 10) == 'i')) {
    pcVar1 = *(code **)(param_1 + 0x2c);
    if (pcVar1 == (code *)0x0) {
      pcVar1 = *(code **)(DAT_300e3fa0 + 4);
      if (pcVar1 == (code *)0x0) {
        errnoSet(DAT_300e3fb0);
        return 0xffffffff;
      }
      uVar2 = *(undefined4 *)(DAT_300e3fa0 + 8);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x34);
    }
    iVar3 = (*pcVar1)(uVar2);
    if (iVar3 == 0) {
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
 * objCoreInit @ 0x300E3A30  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 13 | Вызывает: 2
 * Вызывает: dllInit, handleInit
 * Вызывают: iosInit, iosRtpFdSetup, kernelBaseInit, memPartInit, msgQInit, semBInit, semCInit, semMInit, semRWInitialize, taskInitialize
 *           ...
 * Константы: 0x300E3A30
 * Данные: DAT_300e3fb4, DAT_300e3fb8, DAT_300e3fbc
 * ---------------------------------------------------------------- */
void objCoreInit(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x30) = param_2;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined2 *)(param_1 + 0x3c) = 1;
  *(undefined2 *)(param_1 + 0x3e) = 0;
  handleInit(param_1,*(undefined4 *)(param_2 + 0x38));
  *(undefined2 *)(param_1 + 8) = 0;
  dllInit(param_1 + 0xc);
  dllInit(param_1 + 0x34);
  if (*DAT_300e3fb4 == 0) {
    uVar1 = *DAT_300e3fb8;
  }
  else {
    uVar1 = *(undefined4 *)(*DAT_300e3fb4 + 0x94);
  }
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  if ((code *)*DAT_300e3fbc != (code *)0x0) {
    (*(code *)*DAT_300e3fbc)(param_1,param_2);
  }
  return;
}

/* ----------------------------------------------------------------
 * objCoreInvalidate @ 0x300E3ACC  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 0
 * Вызывают: FUN_300f2198, FUN_30122a44, FUN_30124a88, FUN_30128940, iosRtpFdUnmap2, wdDestroy
 * Константы: 0x300E3ACC
 * ---------------------------------------------------------------- */
undefined4 objCoreInvalidate(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 10) = 0xff;
  return 0;
}

/* ----------------------------------------------------------------
 * objCoreReclaim @ 0x300E3AD0  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30128940, taskDestroy
 * Константы: 0x300E3AD0
 * ---------------------------------------------------------------- */
undefined4 objCoreReclaim(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * objCoreUnlink @ 0x300E3AD8  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30128940
 * Константы: 0x300E3AD8
 * Данные: DAT_300e3fc0
 * ---------------------------------------------------------------- */
void objCoreUnlink(void)

{
  if ((code *)*DAT_300e3fc0 != (code *)0x0) {
    (*(code *)*DAT_300e3fc0)();
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300e3afc @ 0x300E3AFC  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: objCoreTerminate, objNamePtrSet
 * Константы: 0xFFFFFFFF, 0x300E3AFC
 * Данные: DAT_300e3fa0, DAT_300e3fb0, DAT_300e3fc4, DAT_300e3fc8
 * ---------------------------------------------------------------- */
undefined4 FUN_300e3afc(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if ((*(ushort *)(param_1 + 8) & 1) != 0) {
    if (*(code **)(DAT_300e3fa0 + 4) == (code *)0x0) {
      errnoSet(DAT_300e3fb0,*(undefined4 *)(param_1 + 0x2c));
    }
    else {
      (**(code **)(DAT_300e3fa0 + 4))(*(undefined4 *)(DAT_300e3fa0 + 8));
    }
  }
  *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) & (ushort)DAT_300e3fc4;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  if (param_3 != 0) {
    if ((*(uint *)(*(int *)(param_1 + 0x30) + 0x3c) & 1) == 0) {
      if ((code *)*DAT_300e3fc8 == (code *)0x0) {
        errnoSet(DAT_300e3fb0);
        return 0xffffffff;
      }
      iVar1 = (*(code *)*DAT_300e3fc8)(param_1,param_2,param_3);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
    }
    else {
      *(int *)(param_1 + 0x2c) = param_3;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * objCoreTerminate @ 0x300E3BD8  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: FUN_300e3afc
 * Вызывают: FUN_300f2198, FUN_30122a44, FUN_30124a88, iosRtpFdUnmap2, wdDestroy
 * Константы: 0x300E3BD8
 * Данные: DAT_300e3fc0
 * ---------------------------------------------------------------- */
undefined4 objCoreTerminate(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_300e3afc(param_1,uVar1,0);
  }
  if ((code *)*DAT_300e3fc0 != (code *)0x0) {
    (*(code *)*DAT_300e3fc0)(param_1,uVar1);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * objClassTypeGet @ 0x300E3C30  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: objGenericVerify
 * Константы: 0x300E3C30, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 objClassTypeGet(int param_1)

{
  int iVar1;
  
  iVar1 = objGenericVerify();
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x38);
}

/* ----------------------------------------------------------------
 * objNamePtrGet @ 0x300E3C58  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 9 | Вызывает: 1
 * Вызывает: objGenericVerify
 * Вызывают: FUN_30095814, iosFdEntryIoctl, iosFdShow, iosPathFdEntryIoctl, iosRtpFdShow, taskInfoGet, taskName, taskRestart, taskShow
 * Константы: 0x300E3C58
 * ---------------------------------------------------------------- */
int objNamePtrGet(int param_1)

{
  int iVar1;
  
  iVar1 = objGenericVerify();
  if (iVar1 == -1) {
    return 0;
  }
  if (*(int *)(param_1 + 0x2c) == 0) {
    return 0;
  }
  return *(int *)(param_1 + 0x2c);
}

/* ----------------------------------------------------------------
 * objNameGet @ 0x300E3C90  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: errnoSet, objGenericVerify, strlen, strncpy
 * Константы: 0xFFFFFFFF, 0x300E3C90
 * Данные: DAT_300e3fcc, DAT_300e3fd0
 * ---------------------------------------------------------------- */
undefined4 objNameGet(int param_1,char *param_2,uint param_3)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  char *__s;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x2c) == 0) {
    errnoSet(DAT_300e3fcc);
    return 0xffffffff;
  }
  iVar1 = objGenericVerify();
  if ((iVar1 != -1) && (__s = *(char **)(param_1 + 0x2c), __s != (char *)0x0)) {
    sVar2 = strlen(__s);
    if (param_3 < sVar2 + 1) {
      errnoSet(DAT_300e3fd0);
      uVar3 = 0xffffffff;
    }
    strncpy(param_2,__s,param_3);
    param_2[param_3 - 1] = '\0';
    return uVar3;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * objNameLenGet @ 0x300E3D28  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: errnoSet, objGenericVerify, strlen
 * Константы: 0xFFFFFFFF, 0x300E3D28
 * Данные: DAT_300e3fcc
 * ---------------------------------------------------------------- */
size_t objNameLenGet(int param_1)

{
  int iVar1;
  size_t sVar2;
  
  iVar1 = objGenericVerify();
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x2c) == 0) {
    errnoSet(DAT_300e3fcc);
    return 0xffffffff;
  }
  iVar1 = objGenericVerify(param_1);
  if ((iVar1 != -1) && (*(char **)(param_1 + 0x2c) != (char *)0x0)) {
    sVar2 = strlen(*(char **)(param_1 + 0x2c));
    return sVar2;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * objNamePtrSet @ 0x300E3D90  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 3
 * Вызывает: FUN_300e3afc, errnoSet, objGenericVerify
 * Вызывают: FUN_30128940, iosFdEntrySet, iosInit, objNameSet, taskInitialize
 * Константы: 0xFFFFFFFF, 0x300E3D90
 * Данные: DAT_300e3fd4
 * ---------------------------------------------------------------- */
undefined4 objNamePtrSet(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = objGenericVerify();
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  if ((*(int *)(param_1 + 0x2c) != 0) && ((*(uint *)(*(int *)(param_1 + 0x30) + 0x3c) & 2) != 0)) {
    errnoSet(DAT_300e3fd4);
    return 0xffffffff;
  }
  uVar2 = FUN_300e3afc(param_1,*(undefined4 *)(param_1 + 0x30),param_2);
  return uVar2;
}

/* ----------------------------------------------------------------
 * objNameSet @ 0x300E3DF0  (примерный размер ~228 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: errnoSet, objNamePtrSet, strlen, strncpy
 * Вызывают: iosFdEntrySet, taskInitialize
 * Константы: 0x300E3DF0
 * Данные: DAT_300e3fa0, DAT_300e3fb0
 * ---------------------------------------------------------------- */
int objNameSet(int param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  char *__dest;
  
  __dest = (char *)0x0;
  if (param_2 != (char *)0x0) {
    sVar1 = strlen(param_2);
    if ((code *)*DAT_300e3fa0 == (code *)0x0) {
      errnoSet(DAT_300e3fb0);
      __dest = (char *)0x0;
    }
    else {
      __dest = (char *)(*(code *)*DAT_300e3fa0)(DAT_300e3fa0[2],sVar1 + 1);
    }
    if (__dest == (char *)0x0) {
      return -1;
    }
    strncpy(__dest,param_2,sVar1 + 1);
  }
  iVar2 = objNamePtrSet(param_1,__dest);
  if (iVar2 == 0) {
    *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | 1;
  }
  else if ((code *)DAT_300e3fa0[1] == (code *)0x0) {
    errnoSet(DAT_300e3fb0);
  }
  else {
    (*(code *)DAT_300e3fa0[1])(DAT_300e3fa0[2],__dest);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * objClassIdGet @ 0x300E3ED4  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: FUN_30128940, objEach, objInfo, taskEach
 * Константы: 0x300E3ED4
 * Данные: DAT_300e3fd8, DAT_300e3fdc
 * ---------------------------------------------------------------- */
undefined4 objClassIdGet(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x16) {
    uVar1 = *(undefined4 *)(DAT_300e3fdc + param_1 * 4);
  }
  else {
    errnoSet(DAT_300e3fd8);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * objContextGet @ 0x300E3F00  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: handleContextGet, objGenericVerify
 * Константы: 0xFFFFFFFF, 0x300E3F00
 * ---------------------------------------------------------------- */
undefined4 objContextGet(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  int local_10;
  
  bVar3 = param_1 == 0;
  if (!bVar3) {
    iVar1 = objGenericVerify(param_1);
    bVar3 = iVar1 == -1;
  }
  if (bVar3) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = handleContextGet(param_1,param_2,&local_10);
    if (iVar1 == -1) {
      uVar2 = 0xffffffff;
    }
    else if (local_10 == 1) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * objContextSet @ 0x300E3F60  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: handleContextSet, objGenericVerify
 * Константы: 0x300E3F60, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 objContextSet(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 != 0) && (iVar1 = objGenericVerify(param_1), iVar1 != -1)) {
    uVar2 = handleContextSet(param_1,param_2,1);
    return uVar2;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * reboot @ 0x300E3FE0  (примерный размер ~480 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 5
 * Вызывает: edrErrorInjectStub, setjmp, sprintf, sysToMonitor, taskIdSelf
 * Вызывают: edrInitFatalPolicyHandler, edrInterruptFatalPolicyHandler, excExcContinue, excIntHandle, kernelBaseInit, tyIRd, usrMmuInit, workQPanic
 * Константы: 0x300E3FE0, 0xFFFFFFFF
 * Данные: DAT_300e4178, DAT_300e417c, DAT_300e4180, DAT_300e4184, DAT_300e4188, DAT_300e418c, DAT_300e4190, DAT_300e4194
 * ---------------------------------------------------------------- */
int reboot(int __howto)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  code *pcVar4;
  undefined4 uVar5;
  char acStack_b4 [64];
  undefined1 auStack_74 [100];
  
  if ((*DAT_300e4178 != 0) && (iVar2 = taskIdSelf(), iVar2 == *DAT_300e417c)) {
    sysToMonitor(__howto);
  }
  iVar2 = DAT_300e4180;
  uVar5 = DAT_300e4184;
  if ((((__howto != 0) && (iVar2 = DAT_300e4188, uVar5 = DAT_300e418c, __howto != 1)) &&
      (iVar2 = DAT_300e4190, uVar5 = DAT_300e4194, __howto != 2)) &&
     (iVar2 = DAT_300e4198, uVar5 = DAT_300e419c, __howto != 4)) {
    iVar2 = 0;
    uVar5 = 0;
  }
  if (iVar2 == 0) {
    sprintf(acStack_b4,DAT_300e41a0,__howto);
  }
  else {
    sprintf(acStack_b4,DAT_300e41a4,iVar2,uVar5);
  }
  puVar3 = (undefined1 *)0x0;
  if ((*DAT_300e41a8 != 0) && (iVar2 = setjmp((__jmp_buf_tag *)auStack_74), iVar2 == 0)) {
    puVar3 = auStack_74;
  }
  edrErrorInjectStub(DAT_300e41b0,DAT_300e41ac,0xf6,puVar3,0,0,acStack_b4);
  piVar1 = DAT_300e4178;
  *DAT_300e4178 = 1;
  iVar2 = taskIdSelf();
  piVar1[1] = iVar2;
  if (0 < *DAT_300e41b4) {
    iVar2 = 0;
    do {
      pcVar4 = *(code **)(*DAT_300e41b8 + iVar2 * 4);
      if (pcVar4 == (code *)0x0) break;
      (*pcVar4)(__howto);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *DAT_300e41b4);
  }
  if (*(code **)(DAT_300e41bc + 0x18) != (code *)0x0) {
    (**(code **)(DAT_300e41bc + 0x18))(1,0,0xffffffff);
  }
  iVar2 = sysToMonitor(__howto);
  return iVar2;
}

/* ----------------------------------------------------------------
 * getpid @ 0x300E42A0  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300E42A0
 * Данные: DAT_300e42e0, DAT_300e42ec
 * ---------------------------------------------------------------- */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getpid(void)

{
  if (*DAT_300e42e0 != *(__pid_t *)(*DAT_300e42ec + 0x94)) {
    return *(__pid_t *)(*DAT_300e42ec + 0x94);
  }
  return -1;
}

/* ----------------------------------------------------------------
 * sigInit @ 0x300E42F0  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskDeleteHookAdd
 * Вызывают: usrKernelExtraInit
 * Константы: 0x300E42F0, 0xFFFFFFFF
 * Данные: DAT_300e5298, DAT_300e529c, DAT_300e52a0, DAT_300e52a4, DAT_300e52a8, DAT_300e52ac, DAT_300e52b0, DAT_300e52b4
 * ---------------------------------------------------------------- */
undefined4 sigInit(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_300e5298;
  if (DAT_300e5298[1] == 0) {
    *DAT_300e5298 = param_1;
    *DAT_300e52a0 = DAT_300e529c;
    *DAT_300e52a8 = DAT_300e52a4;
    *DAT_300e52b0 = DAT_300e52ac;
    *DAT_300e52b8 = DAT_300e52b4;
    iVar2 = taskDeleteHookAdd(DAT_300e52bc);
    if (iVar2 == -1) {
      return 0xffffffff;
    }
    puVar1[1] = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * sigqueueInit @ 0x300E436C  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: malloc
 * Константы: 0xFFFFFFFF, 0x300E436C
 * Данные: DAT_300e5298, DAT_300e52c0
 * ---------------------------------------------------------------- */
undefined4 sigqueueInit(int param_1)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  
  iVar1 = DAT_300e5298;
  if (*(int *)(DAT_300e5298 + 8) == 0) {
    if (param_1 < 1) {
      return 0xffffffff;
    }
    pvVar2 = malloc(param_1 * 0x28);
    if (pvVar2 == (void *)0x0) {
      return 0xffffffff;
    }
    piVar3 = (int *)((int)pvVar2 + -0x28);
    do {
      piVar3 = piVar3 + 10;
      param_1 = param_1 + -1;
      *piVar3 = *DAT_300e52c0;
      *DAT_300e52c0 = (int)piVar3;
    } while (param_1 != 0);
    *(undefined4 *)(iVar1 + 8) = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300e43ec @ 0x300E43EC  (примерный размер ~248 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: memPartFree, windExit
 * Константы: 0x300E43EC
 * Данные: DAT_300e52c0, DAT_300e52c4, DAT_300e52c8, DAT_300e53e8
 * ---------------------------------------------------------------- */
void FUN_300e43ec(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar4 = *(int *)(param_1 + 0xd8);
  if (iVar4 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x94) == *DAT_300e52c4) {
    puVar3 = (undefined4 *)(iVar4 + 0x400);
    *DAT_300e52c8 = 1;
    iVar2 = 0x40;
    do {
      puVar5 = (undefined4 *)*puVar3;
      while (puVar6 = puVar5, puVar3 != puVar6) {
        puVar5 = (undefined4 *)*puVar6;
        puVar6[1] = 0;
        *puVar6 = 0;
        puVar1 = DAT_300e52c0;
        if (puVar6[3] == 2) {
          *puVar6 = *DAT_300e52c0;
          *puVar1 = puVar6;
        }
      }
      puVar3 = puVar3 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    windExit();
    *(undefined4 *)(param_1 + 0xd8) = 0;
    memPartFree(*DAT_300e53e8,iVar4);
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * sigemptyset @ 0x300E44E4  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300E44E4
 * ---------------------------------------------------------------- */
int sigemptyset(sigset_t *__set)

{
  __set->__val[0] = 0;
  __set->__val[1] = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * sigfillset @ 0x300E44F8  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x300E44F8
 * ---------------------------------------------------------------- */
int sigfillset(sigset_t *__set)

{
  __set->__val[0] = 0xffffffff;
  __set->__val[1] = 0xffffffff;
  return 0;
}

/* ----------------------------------------------------------------
 * sigaddset @ 0x300E450C  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __lsl64, errnoSet
 * Константы: 0x300E450C
 * ---------------------------------------------------------------- */
int sigaddset(sigset_t *__set,int __signo)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if ((__signo < 1) || (0x3f < __signo)) {
    errnoSet(0x16);
    iVar1 = -1;
  }
  else {
    uVar3 = __lsl64(1,0,__signo + -1);
    uVar2 = __set->__val[1];
    __set->__val[0] = (uint)uVar3 | __set->__val[0];
    __set->__val[1] = (uint)((ulonglong)uVar3 >> 0x20) | uVar2;
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sigdelset @ 0x300E456C  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: __lsl64, errnoSet
 * Вызывают: sigaction
 * Константы: 0x300E456C
 * ---------------------------------------------------------------- */
int sigdelset(sigset_t *__set,int __signo)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if ((__signo < 1) || (0x3f < __signo)) {
    errnoSet(0x16);
    iVar1 = -1;
  }
  else {
    uVar3 = __lsl64(1,0,__signo + -1);
    uVar2 = __set->__val[1];
    __set->__val[0] = __set->__val[0] & ~(uint)uVar3;
    __set->__val[1] = uVar2 & ~(uint)((ulonglong)uVar3 >> 0x20);
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sigismember @ 0x300E45D4  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: __lsl64, errnoSet
 * Вызывают: FUN_300e55ec
 * Константы: 0x300E45D4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int sigismember(sigset_t *__set,int __signo)

{
  uint uVar1;
  undefined8 uVar2;
  
  if ((__signo < 1) || (0x3f < __signo)) {
    errnoSet(0x16);
    uVar1 = 0xffffffff;
  }
  else {
    uVar2 = __lsl64(1,0,__signo + -1);
    uVar1 = (uint)((__set->__val[1] & (uint)((ulonglong)uVar2 >> 0x20)) != 0 ||
                  (__set->__val[0] & (uint)uVar2) != 0);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300e463c @ 0x300E463C  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 4
 * Вызывает: __errno, bzero, errnoSet, memPartAlloc
 * Вызывают: sigaction, sigpending, sigprocmask, sigsuspend, sigtimedwait
 * Константы: 0x300E463C
 * Данные: DAT_300e53e8, DAT_300e53ec, DAT_300e5594, DAT_300e5598, DAT_300e559c, DAT_300e55a0
 * ---------------------------------------------------------------- */
void * FUN_300e463c(void)

{
  size_t __n;
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  void *pvVar5;
  
  __n = DAT_300e559c;
  iVar4 = *DAT_300e53ec;
  if (0 < *DAT_300e5594) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300e5598;
    return (void *)0x0;
  }
  pvVar3 = *(void **)(iVar4 + 0xd8);
  if (pvVar3 != (void *)0x0) {
    return pvVar3;
  }
  pvVar3 = (void *)memPartAlloc(*DAT_300e53e8,DAT_300e559c);
  if (pvVar3 == (void *)0x0) {
    errnoSet(0xc);
    return (void *)0x0;
  }
  *(void **)(iVar4 + 0xd8) = pvVar3;
  bzero(pvVar3,__n);
  iVar4 = DAT_300e55a0;
  iVar2 = 0x40;
  pvVar5 = pvVar3;
  do {
    *(int *)((int)pvVar5 + iVar4) = (int)pvVar5 + 0x400;
    *(int *)((int)pvVar5 + 0x400) = (int)pvVar5 + 0x400;
    pvVar5 = (void *)((int)pvVar5 + 8);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return pvVar3;
}

/* ----------------------------------------------------------------
 * sigaction @ 0x300E46EC  (примерный размер ~352 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 4
 * Вызывает: FUN_300e463c, errnoSet, sigdelset, windExit
 * Вызывают: shellTask, signal, sigvec
 * Константы: 0x300E46EC
 * Данные: DAT_300e52c0, DAT_300e52c4, DAT_300e52c8, DAT_300e53ec, DAT_300e5684, DAT_300e5688, DAT_300e568c
 * ---------------------------------------------------------------- */
int sigaction(int __sig,sigaction *__act,sigaction *__oact)

{
  undefined4 *puVar1;
  int iVar2;
  ulong uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  __sighandler_t p_Var7;
  
  if (*(int *)(*DAT_300e53ec + 0x94) == *DAT_300e52c4) {
    if (__sig - 1U < 0x3f) {
      iVar2 = FUN_300e463c();
      if (iVar2 == 0) {
        iVar2 = -1;
      }
      else {
        puVar5 = (undefined4 *)(iVar2 + __sig * 0x10);
        if (__oact != (sigaction *)0x0) {
          uVar3 = puVar5[1];
          (__oact->__sigaction_handler).sa_handler = (__sighandler_t)*puVar5;
          (__oact->sa_mask).__val[0] = uVar3;
          uVar3 = puVar5[3];
          (__oact->sa_mask).__val[1] = puVar5[2];
          (__oact->sa_mask).__val[2] = uVar3;
        }
        if (__act != (sigaction *)0x0) {
          *DAT_300e52c8 = 1;
          p_Var7 = (__act->__sigaction_handler).sa_handler;
          uVar3 = (__act->sa_mask).__val[0];
          *puVar5 = p_Var7;
          puVar5[1] = uVar3;
          uVar3 = (__act->sa_mask).__val[2];
          puVar5[2] = (__act->sa_mask).__val[1];
          puVar5[3] = uVar3;
          if (p_Var7 == (__sighandler_t)0x1) {
            sigdelset((sigset_t *)(iVar2 + DAT_300e5688),__sig);
            sigdelset((sigset_t *)(iVar2 + DAT_300e568c),__sig);
            iVar2 = iVar2 + __sig * 8;
            puVar6 = (undefined4 *)(iVar2 + 0x400);
            puVar5 = *(undefined4 **)(iVar2 + 0x400);
            while (puVar4 = puVar5, puVar6 != puVar4) {
              puVar5 = (undefined4 *)*puVar4;
              puVar4[1] = 0;
              *puVar4 = 0;
              puVar1 = DAT_300e52c0;
              if (puVar4[3] == 2) {
                *puVar4 = *DAT_300e52c0;
                *puVar1 = puVar4;
              }
            }
            *(undefined4 **)(iVar2 + 0x400) = puVar6;
            *(undefined4 **)(iVar2 + 0x404) = puVar6;
          }
          windExit();
        }
        iVar2 = 0;
      }
    }
    else {
      errnoSet(0x16);
      iVar2 = -1;
    }
  }
  else {
    iVar2 = (*(code *)*DAT_300e5684)();
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * signal @ 0x300E484C  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: sigaction
 * Вызывают: FUN_300e48a8
 * Константы: 0x300E484C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
__sighandler_t signal(int __sig,__sighandler_t __handler)

{
  int iVar1;
  _union_1051 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  _union_1051 a_Stack_14 [5];
  
  local_18 = 0;
  local_20 = 0;
  local_1c = 0;
  local_24.sa_handler = __handler;
  iVar1 = sigaction(__sig,(sigaction *)&local_24,(sigaction *)a_Stack_14);
  if (iVar1 == -1) {
    a_Stack_14[0] = (_union_1051)0xffffffff;
  }
  return a_Stack_14[0].sa_handler;
}

/* ----------------------------------------------------------------
 * sigreturn @ 0x300E4888  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: _sigCtxLoad, sigprocmask
 * Вызывают: FUN_300e48a8
 * Константы: 0x300E4888
 * ---------------------------------------------------------------- */
int sigreturn(sigcontext *__scp)

{
  int iVar1;
  
  sigprocmask(3,(sigset_t *)&__scp->es,(sigset_t *)0x0);
  iVar1 = _sigCtxLoad(&__scp->esp);
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300e48a8 @ 0x300E48A8  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: signal, sigreturn
 * Вызывают: FUN_300e4ac4, FUN_300e55ec
 * Константы: 0x300E48A8, 0xFFFFFFFF
 * Данные: DAT_300e53ec
 * ---------------------------------------------------------------- */
void FUN_300e48a8(sigcontext *param_1)

{
  ulong *puVar1;
  undefined4 *puVar2;
  ulong __sig;
  code *pcVar3;
  
  __sig = param_1->edi;
  puVar2 = (undefined4 *)(*(int *)(*DAT_300e53ec + 0xd8) + __sig * 0x10);
  pcVar3 = (code *)*puVar2;
  if ((puVar2[3] & 0x10) != 0) {
    signal(__sig,(__sighandler_t)0x0);
  }
  if (((pcVar3 != (code *)0x0) && (pcVar3 != (code *)0x1)) && (pcVar3 != (code *)0xffffffff)) {
    if ((puVar2[3] & 2) == 0) {
      puVar1 = (ulong *)param_1->ebp;
    }
    else {
      puVar1 = &param_1->edi;
    }
    (*pcVar3)(__sig,puVar1,param_1);
  }
  sigreturn(param_1);
  return;
}

/* ----------------------------------------------------------------
 * sigFfsMsb @ 0x300E4928  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: ffsMsb
 * Вызывают: FUN_300e4960
 * Константы: 0x300E4928
 * ---------------------------------------------------------------- */
int sigFfsMsb(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = ffsMsb(param_1);
  }
  else {
    iVar1 = ffsMsb(param_2);
    iVar1 = iVar1 + 0x20;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300e4960 @ 0x300E4960  (примерный размер ~356 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: sigFfsMsb
 * Вызывают: FUN_300e4ac4, sigtimedwait
 * Константы: 0x300E4960
 * Данные: DAT_300e52c0, DAT_300e568c
 * ---------------------------------------------------------------- */
int FUN_300e4960(int param_1,uint *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  
  uVar4 = *param_2 & *(uint *)(param_1 + 0x61c);
  uVar6 = param_2[1] & *(uint *)(param_1 + 0x620);
  if (uVar6 + uVar4 == 0) {
    iVar2 = 0;
  }
  else {
    uVar5 = uVar4 & -uVar4;
    uVar6 = uVar6 & -(uVar6 + (uVar4 != 0));
    iVar2 = sigFfsMsb(uVar5,uVar6);
    uVar4 = *(uint *)(param_1 + DAT_300e568c);
    uVar3 = ((uint *)(param_1 + DAT_300e568c))[1];
    if ((uVar6 & uVar3) + (uVar5 & uVar4) == 0) {
      piVar7 = *(int **)(param_1 + iVar2 * 8 + 0x400);
      *(int *)piVar7[1] = *piVar7;
      *(int *)(*piVar7 + 4) = piVar7[1];
      *piVar7 = 0;
      piVar7[1] = 0;
      iVar8 = piVar7[3];
      *param_3 = piVar7[2];
      param_3[1] = iVar8;
      param_3[2] = piVar7[4];
      piVar7[5] = piVar7[6];
      piVar7[6] = 0;
      piVar1 = DAT_300e52c0;
      if (piVar7[3] == 2) {
        *piVar7 = *DAT_300e52c0;
        *piVar1 = (int)piVar7;
      }
    }
    else {
      puVar9 = (uint *)(param_1 + DAT_300e568c);
      *puVar9 = uVar4 & ~uVar5;
      puVar9[1] = uVar3 & ~uVar6;
      *param_3 = iVar2;
      param_3[1] = 1;
      param_3[2] = 0;
    }
    iVar8 = param_1 + iVar2 * 8;
    if (*(int *)(iVar8 + 0x400) == iVar8 + 0x400) {
      *(uint *)(param_1 + 0x61c) = *(uint *)(param_1 + 0x61c) & ~uVar5;
      *(uint *)(param_1 + 0x620) = *(uint *)(param_1 + 0x620) & ~uVar6;
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300e4ac4 @ 0x300E4AC4  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_300e48a8, FUN_300e4960, __lsl64, _sigCtxRtnValSet, _sigCtxSave, windExit
 * Вызывают: sigprocmask, sigsuspend
 * Константы: 0x300E4AC4
 * Данные: DAT_300e5a54
 * ---------------------------------------------------------------- */
undefined4 FUN_300e4ac4(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined8 uVar6;
  uint local_8c;
  uint local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 auStack_74 [12];
  undefined1 auStack_68 [76];
  
  iVar2 = DAT_300e5a54;
  local_8c = ~*(uint *)(param_1 + DAT_300e5a54);
  local_88 = ~((uint *)(param_1 + DAT_300e5a54))[1];
  iVar1 = FUN_300e4960(param_1,&local_8c,auStack_74);
  if (0 < iVar1) {
    local_84 = 0;
    local_80 = 0;
    puVar4 = (undefined4 *)(param_1 + iVar2);
    local_7c = *puVar4;
    local_78 = puVar4[1];
    if (iVar1 < 0x41) {
      uVar6 = __lsl64(1,0,iVar1 + -1);
    }
    else {
      uVar6 = 0;
    }
    puVar5 = (uint *)(param_1 + iVar2);
    param_1 = param_1 + iVar1 * 0x10;
    uVar3 = *(uint *)(param_1 + 8);
    *puVar5 = *puVar5 | *(uint *)(param_1 + 4) | (uint)uVar6;
    puVar5[1] = puVar5[1] | uVar3 | (uint)((ulonglong)uVar6 >> 0x20);
    windExit();
    iVar2 = _sigCtxSave(auStack_68);
    if (iVar2 != 0) {
      return 1;
    }
    _sigCtxRtnValSet(auStack_68,1);
    FUN_300e48a8(&local_84);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * sigprocmask @ 0x300E4BB8  (примерный размер ~324 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 4
 * Вызывает: FUN_300e463c, FUN_300e4ac4, errnoSet, windExit
 * Вызывают: sigblock, sigreturn, sigsetmask, sigsuspend
 * Константы: 0x300E4BB8
 * Данные: DAT_300e52c4, DAT_300e52c8, DAT_300e53ec, DAT_300e5a54, DAT_300e5b28
 * ---------------------------------------------------------------- */
int sigprocmask(int __how,sigset_t *__set,sigset_t *__oset)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  uint *puVar5;
  
  if (*(int *)(*DAT_300e53ec + 0x94) != *DAT_300e52c4) {
    iVar1 = (*(code *)*DAT_300e5b28)();
    return iVar1;
  }
  iVar1 = FUN_300e463c();
  if (iVar1 == 0) {
    return -1;
  }
  *DAT_300e52c8 = 1;
  if (__oset != (sigset_t *)0x0) {
    uVar3 = *(ulong *)(iVar1 + 0x618);
    __oset->__val[0] = *(ulong *)(iVar1 + 0x614);
    __oset->__val[1] = uVar3;
  }
  if (__set != (sigset_t *)0x0) {
    if (__how == 1) {
      uVar2 = ((uint *)(iVar1 + DAT_300e5a54))[1];
      puVar5 = (uint *)(iVar1 + DAT_300e5a54);
      uVar4 = __set->__val[1];
      *puVar5 = *(uint *)(iVar1 + DAT_300e5a54) | __set->__val[0];
      puVar5[1] = uVar2 | uVar4;
      goto LAB_300e4cec;
    }
    if (__how == 2) {
      uVar2 = __set->__val[1];
      puVar5 = (uint *)(iVar1 + DAT_300e5a54);
      *puVar5 = *puVar5 & ~__set->__val[0];
      puVar5[1] = puVar5[1] & ~uVar2;
    }
    else {
      if (__how != 3) {
        windExit();
        errnoSet(0x16);
        return -1;
      }
      uVar3 = __set->__val[1];
      *(ulong *)(iVar1 + 0x614) = __set->__val[0];
      *(ulong *)(iVar1 + 0x618) = uVar3;
    }
  }
  iVar1 = FUN_300e4ac4(iVar1);
  if (iVar1 != 0) {
    return 0;
  }
LAB_300e4cec:
  windExit();
  return 0;
}

/* ----------------------------------------------------------------
 * sigpending @ 0x300E4CFC  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300e463c
 * Константы: 0x300E4CFC
 * Данные: DAT_300e52c4, DAT_300e53ec, DAT_300e5c3c
 * ---------------------------------------------------------------- */
int sigpending(sigset_t *__set)

{
  int iVar1;
  ulong uVar2;
  
  if (*(int *)(*DAT_300e53ec + 0x94) == *DAT_300e52c4) {
    iVar1 = FUN_300e463c();
    if (iVar1 == 0) {
      iVar1 = -1;
    }
    else {
      uVar2 = *(ulong *)(iVar1 + 0x620);
      __set->__val[0] = *(ulong *)(iVar1 + 0x61c);
      __set->__val[1] = uVar2;
      iVar1 = 0;
    }
  }
  else {
    iVar1 = (*(code *)*DAT_300e5c3c)(__set);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sigsuspend @ 0x300E4D6C  (примерный размер ~436 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 7
 * Вызывает: FUN_300e463c, FUN_300e4ac4, errnoSet, qInit, sigprocmask, windExit, windPendQPut
 * Константы: 0x300E4D6C, 0xFFFFFFFF
 * Данные: DAT_300e52c4, DAT_300e52c8, DAT_300e53ec, DAT_300e5a54, DAT_300e5c40, DAT_300e5c44, DAT_300e5da0
 * ---------------------------------------------------------------- */
int sigsuspend(sigset_t *__set)

{
  int iVar1;
  ulong uVar2;
  ulong *puVar3;
  undefined4 local_2c [2];
  ulong local_24;
  ulong local_20;
  undefined1 auStack_1c [16];
  
  if (*(int *)(*DAT_300e53ec + 0x94) != *DAT_300e52c4) {
    iVar1 = (*(code *)*DAT_300e5c40)();
    return iVar1;
  }
  iVar1 = FUN_300e463c();
  if (iVar1 != 0) {
    if ((code *)*DAT_300e5c44 != (code *)0x0) {
      (*(code *)*DAT_300e5c44)(0,local_2c);
    }
    *DAT_300e52c8 = 1;
    puVar3 = (ulong *)(iVar1 + DAT_300e5a54);
    local_24 = *puVar3;
    local_20 = puVar3[1];
    uVar2 = __set->__val[1];
    *puVar3 = __set->__val[0];
    puVar3[1] = uVar2;
    iVar1 = FUN_300e4ac4(iVar1);
    if (iVar1 == 1) {
      sigprocmask(3,(sigset_t *)&local_24,(sigset_t *)0x0);
      if ((code *)*DAT_300e5c44 != (code *)0x0) {
        (*(code *)*DAT_300e5c44)(local_2c[0],0);
      }
    }
    else {
      qInit(auStack_1c,*DAT_300e5da0,0,0,0,0,0,0,0,0,0,0);
      iVar1 = windPendQPut(auStack_1c,0xffffffff);
      if (iVar1 != 0) {
        windExit();
        if ((code *)*DAT_300e5c44 == (code *)0x0) {
          return -1;
        }
        (*(code *)*DAT_300e5c44)(local_2c[0],0);
        return -1;
      }
      windExit();
      sigprocmask(3,(sigset_t *)&local_24,(sigset_t *)0x0);
      if ((code *)*DAT_300e5c44 != (code *)0x0) {
        (*(code *)*DAT_300e5c44)(local_2c[0],0);
      }
    }
    errnoSet(4);
  }
  return -1;
}

/* ----------------------------------------------------------------
 * pause @ 0x300E4F20  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: errnoSet, qInit, windExit, windPendQPut
 * Константы: 0x300E4F20, 0xFFFFFFFF
 * Данные: DAT_300e52c4, DAT_300e52c8, DAT_300e53ec, DAT_300e5c44, DAT_300e5da0, DAT_300e5e6c
 * ---------------------------------------------------------------- */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pause(void)

{
  undefined4 *puVar1;
  int iVar2;
  code *pcVar3;
  undefined4 local_1c;
  undefined1 auStack_18 [16];
  
  puVar1 = DAT_300e5c44;
  if (*(int *)(*DAT_300e53ec + 0x94) == *DAT_300e52c4) {
    if ((code *)*DAT_300e5c44 != (code *)0x0) {
      (*(code *)*DAT_300e5c44)(0,&local_1c);
    }
    qInit(auStack_18,*DAT_300e5da0,0,0,0,0,0,0,0,0,0,0);
    *DAT_300e52c8 = 1;
    iVar2 = windPendQPut(auStack_18,0xffffffff);
    if (iVar2 == 0) {
      windExit();
      pcVar3 = (code *)*puVar1;
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(local_1c,0);
      }
      errnoSet(4);
    }
    else {
      windExit();
      pcVar3 = (code *)*puVar1;
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(local_1c,0);
      }
    }
    iVar2 = -1;
  }
  else {
    iVar2 = (*(code *)*DAT_300e5e6c)();
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * sigtimedwait @ 0x300E5038  (примерный размер ~824 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 9
 * Вызывает: FUN_300e463c, FUN_300e4960, __div32, __errno, errnoSet, qInit, sysClkRateGet, windExit, windPendQPut
 * Вызывают: sigwait, sigwaitinfo
 * Константы: 0x300E5038
 * Данные: DAT_300e52c4, DAT_300e52c8, DAT_300e53ec, DAT_300e5c44, DAT_300e5da0, DAT_300e5f64, DAT_300e5f68, DAT_300e6070
 * ---------------------------------------------------------------- */
int sigtimedwait(sigset_t *__set,siginfo_t *__info,timespec *__timeout)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_54;
  int local_50;
  int local_4c;
  int local_48;
  ulong local_44;
  ulong local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined1 auStack_30 [16];
  
  if (*(int *)(*DAT_300e53ec + 0x94) == *DAT_300e52c4) {
    iVar3 = FUN_300e463c();
    puVar1 = DAT_300e5c44;
    if (iVar3 == 0) {
      iVar2 = -1;
    }
    else {
      if ((code *)*DAT_300e5c44 != (code *)0x0) {
        (*(code *)*DAT_300e5c44)(0,&local_54);
      }
      if (__timeout == (timespec *)0x0) {
        iVar6 = -1;
      }
      else {
        iVar2 = sysClkRateGet();
        uVar7 = __timeout->tv_nsec;
        if (DAT_300e5f68 <= uVar7) {
          puVar4 = (undefined4 *)__errno();
          *puVar4 = 0x16;
          if ((code *)*puVar1 != (code *)0x0) {
            (*(code *)*puVar1)(local_54,0);
          }
          return -1;
        }
        uVar5 = __div32(DAT_300e6070,iVar2);
        iVar6 = __div32(uVar7,uVar5);
        iVar6 = iVar2 * __timeout->tv_sec + iVar6;
      }
      *DAT_300e52c8 = 1;
      iVar2 = FUN_300e4960(iVar3,__set,&local_50);
      if (iVar2 < 1) {
        if (iVar6 == 0) {
          windExit();
          *(undefined4 *)(iVar3 + 0x608) = 0;
          if ((code *)*puVar1 != (code *)0x0) {
            (*(code *)*puVar1)(local_54,0);
          }
          errnoSet(0xb);
          iVar2 = -1;
        }
        else {
          local_44 = __set->__val[0];
          local_40 = __set->__val[1];
          qInit(auStack_30,*DAT_300e5da0,0,0,0,0,0,0,0,0,0,0);
          iVar2 = DAT_300e60b4;
          *(ulong **)(iVar3 + 0x608) = &local_44;
          iVar6 = windPendQPut(auStack_30,iVar6);
          if (iVar6 == 0) {
            iVar6 = windExit();
            *(undefined4 *)(iVar3 + iVar2) = 0;
            if (iVar6 == 0) {
              if (__info != (siginfo_t *)0x0) {
                __info->si_signo = local_3c;
                __info->si_errno = local_38;
                __info->si_code = local_34;
              }
              iVar2 = local_3c;
              if ((code *)*puVar1 != (code *)0x0) {
                (*(code *)*puVar1)(local_54,0);
                iVar2 = local_3c;
              }
            }
            else {
              if ((code *)*puVar1 != (code *)0x0) {
                (*(code *)*puVar1)(local_54,0);
              }
              uVar5 = 0xb;
              if (iVar6 == 1) {
                uVar5 = 4;
              }
              errnoSet(uVar5);
              iVar2 = -1;
            }
          }
          else {
            windExit();
            *(undefined4 *)(iVar3 + iVar2) = 0;
            if ((code *)*puVar1 != (code *)0x0) {
              (*(code *)*puVar1)(local_54,0);
            }
            errnoSet(0xb);
            iVar2 = -1;
          }
        }
      }
      else {
        windExit();
        if (__info != (siginfo_t *)0x0) {
          __info->si_signo = local_50;
          __info->si_errno = local_4c;
          __info->si_code = local_48;
        }
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)(local_54,0);
        }
      }
    }
  }
  else {
    iVar2 = (*(code *)*DAT_300e5f64)();
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * sigwaitinfo @ 0x300E5370  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: sigtimedwait
 * Константы: 0x300E5370
 * ---------------------------------------------------------------- */
int sigwaitinfo(sigset_t *__set,siginfo_t *__info)

{
  int iVar1;
  
  iVar1 = sigtimedwait(__set,__info,(timespec *)0x0);
  return iVar1;
}

/* ----------------------------------------------------------------
 * sigwait @ 0x300E5378  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: sigtimedwait
 * Константы: 0x300E5378
 * ---------------------------------------------------------------- */
int sigwait(sigset_t *__set,int *__sig)

{
  int iVar1;
  int iStack_14;
  
  iVar1 = sigtimedwait(__set,(siginfo_t *)&iStack_14,(timespec *)0x0);
  if (iVar1 == -1) {
    iVar1 = -1;
  }
  else {
    iVar1 = 0;
    *__sig = iStack_14;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sigvec @ 0x300E53AC  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: sigaction
 * Константы: 0x300E53AC
 * ---------------------------------------------------------------- */
int sigvec(int __sig,sigvec *__vec,sigvec *__ovec)

{
  int iVar1;
  _union_1051 *__act;
  _union_1051 local_28;
  int local_24;
  int local_20;
  __sighandler_t local_1c;
  _union_1051 local_18;
  int local_14;
  int local_10;
  __sighandler_t local_c;
  
  __act = &local_28;
  if (__vec == (sigvec *)0x0) {
    __act = (_union_1051 *)0x0;
  }
  else {
    local_28 = (_union_1051)__vec->sv_handler;
    local_24 = __vec->sv_mask;
    local_20 = __vec->sv_flags;
    local_1c = __vec[1].sv_handler;
  }
  iVar1 = sigaction(__sig,(sigaction *)__act,(sigaction *)&local_18);
  if (__ovec != (sigvec *)0x0) {
    __ovec->sv_handler = (__sighandler_t)local_18;
    __ovec->sv_mask = local_14;
    __ovec->sv_flags = local_10;
    __ovec[1].sv_handler = local_c;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sigsetmask @ 0x300E5430  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: sigprocmask
 * Константы: 0x300E5430
 * ---------------------------------------------------------------- */
int sigsetmask(int __mask)

{
  ulong local_14;
  ulong local_10;
  ulong local_c;
  
  local_10 = __mask >> 0x1f;
  local_14 = __mask;
  sigprocmask(3,(sigset_t *)&local_14,(sigset_t *)&local_c);
  return local_c;
}

/* ----------------------------------------------------------------
 * sigblock @ 0x300E5460  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: sigprocmask
 * Константы: 0x300E5460
 * ---------------------------------------------------------------- */
int sigblock(int __mask)

{
  ulong local_14;
  ulong local_10;
  ulong local_c;
  
  local_10 = __mask >> 0x1f;
  local_14 = __mask;
  sigprocmask(1,(sigset_t *)&local_14,(sigset_t *)&local_c);
  return local_c;
}

/* ----------------------------------------------------------------
 * FUN_300e5490 @ 0x300E5490  (примерный размер ~348 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskRtnValueSet
 * Вызывают: FUN_300e55ec
 * Константы: 0xFFFFFFFF, 0x300E5490, 0xFFFFFFFB, 0xFFFFFFFD
 * Данные: DAT_300e60b8, DAT_300e60bc, DAT_300e60c0
 * ---------------------------------------------------------------- */
undefined4 FUN_300e5490(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((*(uint *)(param_1 + 0x70) & 6) != 0) {
    if ((*(uint *)(param_1 + 0x70) & 4) != 0) {
      taskRtnValueSet(param_1,1);
      *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & 0xfffffffb;
      iVar1 = DAT_300e60b8;
      (**(code **)(*(int *)(DAT_300e60b8 + 0xc) + 0x18))(DAT_300e60b8,param_1 + 0x40);
      uVar2 = (**(code **)(*(int *)(iVar1 + 0xc) + 0x28))(param_1 + 0x40,1);
    }
    if ((*(uint *)(param_1 + 0x70) & 2) != 0) {
      if ((*(uint *)(*(int *)(param_1 + 0xa8) + 8) & 2) == 0) {
        taskRtnValueSet(param_1,1);
      }
      else {
        taskRtnValueSet(param_1,0xffffffff);
        *(undefined4 *)(param_1 + 0xd0) = 4;
      }
      *(undefined4 *)(param_1 + 0x8c) = 0;
      *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & 0xfffffffd;
      iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0xa8) + 0xc) + 0x18))
                        (*(int *)(param_1 + 0xa8),param_1 + 0x50);
      if (iVar1 == -1) {
        taskRtnValueSet(param_1,0xffffffff);
        *(undefined4 *)(param_1 + 0xd0) = DAT_300e60bc;
      }
      else if (iVar1 == 1) {
        taskRtnValueSet(param_1,0);
      }
    }
    if (*(int *)(param_1 + 0x70) == 0) {
      (**(code **)(*(int *)(DAT_300e60c0 + 0xc) + 0x10))
                (DAT_300e60c0,param_1 + 0x50,*(undefined4 *)(param_1 + 0x74));
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300e55ec @ 0x300E55EC  (примерный размер ~1004 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 10
 * Вызывает: FUN_300e48a8, FUN_300e5490, __lsl64, _sigCtxRtnValSet, _sigCtxSave, _sigCtxSetup, _sigCtxStackEnd, sigismember, windExit, windPendQGet
 * Вызывают: FUN_300e59d8, sigPendKill, sigqueue
 * Константы: 0x300E55EC, 0xFFFFFFFC
 * Данные: DAT_300e5a54, DAT_300e60c4, DAT_300e60c8, DAT_300e60cc, DAT_300e60d0, DAT_300e60d4, DAT_300e60d8
 * ---------------------------------------------------------------- */
void FUN_300e55ec(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  undefined8 uVar14;
  uint local_a4;
  uint local_a0;
  undefined4 local_9c;
  undefined4 *local_98;
  uint local_94;
  uint local_90;
  undefined4 local_8c;
  undefined4 local_88;
  uint local_84;
  uint local_80;
  int local_7c;
  int local_78;
  int local_74;
  undefined1 auStack_70 [72];
  int local_28;
  
  iVar8 = param_2[2];
  iVar12 = *DAT_300e60c4;
  iVar11 = *(int *)(param_1 + 0xd8);
  if (iVar11 != 0) {
    if (((*(sigset_t **)(iVar11 + 0x608) == (sigset_t *)0x0) ||
        (iVar1 = sigismember(*(sigset_t **)(iVar11 + 0x608),iVar8), iVar1 != 1)) ||
       (iVar1 = *(int *)(iVar11 + 0x608), *(int *)(iVar1 + 0x14) == 0)) {
      if ((iVar8 < 1) || (0x40 < iVar8)) {
        uVar14 = 0;
      }
      else {
        uVar14 = __lsl64(1,0,iVar8 + -1);
        uVar4 = (uint)((ulonglong)uVar14 >> 0x20);
        uVar6 = (uint)uVar14;
        local_94 = uVar6 & *(uint *)(iVar11 + 0x614);
        local_90 = uVar4 & *(uint *)(iVar11 + 0x618);
        if (local_90 + local_94 != 0) {
          if (param_2[3] == 1) {
            puVar13 = (uint *)(iVar11 + DAT_300e60c8);
            *puVar13 = uVar6 | *puVar13;
            puVar13[1] = uVar4 | puVar13[1];
            puVar13 = (uint *)(iVar11 + DAT_300e60cc);
            *puVar13 = uVar6 | *puVar13;
            puVar13[1] = uVar4 | puVar13[1];
            return;
          }
          if (*param_2 != 0) {
            param_2[6] = param_2[6] + 1;
            return;
          }
          iVar8 = iVar11 + iVar8 * 8;
          piVar9 = param_2;
          if (param_2[3] == 2) {
            piVar9 = (int *)*DAT_300e60d0;
            *DAT_300e60d0 = *piVar9;
            iVar12 = 10;
            piVar5 = piVar9;
            do {
              iVar12 = iVar12 + -1;
              *piVar5 = *param_2;
              piVar5 = piVar5 + 1;
              param_2 = param_2 + 1;
            } while (iVar12 != 0);
          }
          puVar10 = *(undefined4 **)(iVar8 + 0x404);
          piVar9[1] = (int)puVar10;
          *piVar9 = iVar8 + 0x400;
          *puVar10 = piVar9;
          *(int **)(iVar8 + 0x404) = piVar9;
          puVar13 = (uint *)(iVar11 + DAT_300e60cc);
          *puVar13 = uVar6 | *puVar13;
          puVar13[1] = uVar4 | puVar13[1];
          piVar9[8] = iVar11;
          return;
        }
      }
      local_a0 = (uint)((ulonglong)uVar14 >> 0x20);
      local_a4 = (uint)uVar14;
      iVar1 = *(int *)(iVar11 + iVar8 * 0x10);
      if ((iVar1 != 0) && (iVar1 != 1)) {
        if (iVar12 == param_1) {
          local_8c = 0;
          local_88 = 0;
          iVar8 = iVar11 + iVar8 * 0x10;
          puVar13 = (uint *)(iVar11 + DAT_300e5a54);
          local_84 = *puVar13;
          local_80 = puVar13[1];
          uVar6 = *(uint *)(iVar8 + 8);
          *puVar13 = local_a4 | *puVar13 | *(uint *)(iVar8 + 4);
          puVar13[1] = local_a0 | puVar13[1] | uVar6;
          local_7c = param_2[2];
          local_78 = param_2[3];
          local_74 = param_2[4];
          local_28 = param_2[7];
          windExit();
          iVar8 = _sigCtxSave(auStack_70);
          if (iVar8 == 0) {
            _sigCtxRtnValSet(auStack_70,1);
            FUN_300e48a8(&local_8c);
          }
          *DAT_300e60d8 = 1;
        }
        else {
          iVar12 = _sigCtxStackEnd();
          puVar2 = (undefined4 *)(iVar12 - 0x68U & 0xfffffffc);
          local_9c = 1;
          *(undefined4 *)(iVar11 + 0x608) = 0;
          *puVar2 = 0;
          local_98 = puVar2;
          uVar3 = FUN_300e5490(param_1);
          iVar8 = iVar11 + iVar8 * 0x10;
          puVar2[1] = uVar3;
          uVar3 = *(undefined4 *)(iVar11 + 0x618);
          puVar2[2] = *(undefined4 *)(iVar11 + 0x614);
          puVar2[3] = uVar3;
          uVar6 = *(uint *)(iVar8 + 8);
          *(uint *)(iVar11 + 0x614) = local_a4 | *(uint *)(iVar11 + 0x614) | *(uint *)(iVar8 + 4);
          *(uint *)(iVar11 + 0x618) = local_a0 | *(uint *)(iVar11 + 0x618) | uVar6;
          iVar8 = param_2[3];
          puVar2[4] = param_2[2];
          puVar2[5] = iVar8;
          puVar2[6] = param_2[4];
          iVar8 = 0x12;
          puVar10 = puVar2 + 7;
          puVar7 = (undefined4 *)(param_1 + 0x1d0);
          do {
            iVar8 = iVar8 + -1;
            *puVar10 = *puVar7;
            puVar10 = puVar10 + 1;
            puVar7 = puVar7 + 1;
          } while (iVar8 != 0);
          puVar2[0x19] = param_2[7];
          _sigCtxSetup(param_1 + 0x1d0,puVar2,DAT_300e60d4,&local_9c);
        }
      }
    }
    else {
      iVar8 = param_2[3];
      *(int *)(iVar1 + 8) = param_2[2];
      *(int *)(iVar1 + 0xc) = iVar8;
      *(int *)(iVar1 + 0x10) = param_2[4];
      windPendQGet(*(int *)(iVar11 + 0x608) + 0x14);
      *(undefined4 *)(iVar11 + 0x608) = 0;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300e59d8 @ 0x300E59D8  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300e55ec
 * Вызывают: kill
 * Константы: 0x300E59D8
 * ---------------------------------------------------------------- */
void FUN_300e59d8(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_2c [8];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_10;
  
  local_20 = 1;
  local_1c = 0;
  local_10 = 0;
  local_24 = param_2;
  FUN_300e55ec(param_1,auStack_2c);
  return;
}

/* ----------------------------------------------------------------
 * kill @ 0x300E5A08  (примерный размер ~416 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 5
 * Вызывает: FUN_300e59d8, errnoSet, excJobAdd, objVerify, windExit
 * Вызывают: raise, shellInOutBgndClose
 * Константы: 0x300E5A08
 * Данные: DAT_300e60c4, DAT_300e60d8, DAT_300e60dc, DAT_300e60e0, DAT_300e60e4, DAT_300e60e8, DAT_300e60ec
 * ---------------------------------------------------------------- */
int kill(__pid_t __pid,int __sig)

{
  int iVar1;
  
  iVar1 = objVerify(__pid,*DAT_300e60dc);
  if (iVar1 == 0) {
    iVar1 = __pid;
    if (__pid == 0) {
      iVar1 = *DAT_300e60c4;
    }
    if (*(int *)(iVar1 + 0x94) == *DAT_300e60e0) {
      if (__sig - 1U < 0x3f) {
        if ((*DAT_300e60d8 == 1) || ((0 < *DAT_300e60e8 && (*DAT_300e60c4 == __pid)))) {
          iVar1 = objVerify(__pid,*DAT_300e60dc);
          if (iVar1 != 0) {
            errnoSet(0x16);
            return -1;
          }
          excJobAdd(DAT_300e60ec,__pid,__sig,0,0,0,0);
        }
        else {
          *DAT_300e60d8 = 1;
          iVar1 = objVerify(__pid,*DAT_300e60dc);
          if (iVar1 != 0) {
            windExit();
            errnoSet(0x16);
            return -1;
          }
          FUN_300e59d8(__pid,__sig);
          windExit();
        }
        iVar1 = 0;
      }
      else {
        errnoSet(0x16);
        iVar1 = -1;
      }
    }
    else {
      iVar1 = (*(code *)*DAT_300e60e4)(__pid,__sig);
    }
  }
  else {
    errnoSet(0x16);
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * raise @ 0x300E5BA8  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: kill
 * Вызывают: abort
 * Константы: 0x300E5BA8
 * Данные: DAT_300e60c4
 * ---------------------------------------------------------------- */
int raise(int __sig)

{
  int iVar1;
  
  iVar1 = kill(*DAT_300e60c4,__sig);
  return iVar1;
}

/* ----------------------------------------------------------------
 * sigPendInit @ 0x300E5BBC  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300e5ff0, sigqueue
 * Константы: 0x300E5BBC
 * ---------------------------------------------------------------- */
void sigPendInit(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[7] = 0;
  return;
}

/* ----------------------------------------------------------------
 * sigqueue @ 0x300E5BD4  (примерный размер ~536 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_300e55ec, errnoSet, excJobAdd, objVerify, sigPendInit, windExit
 * Вызывают: FUN_300e5dec
 * Константы: 0x300E5BD4
 * Данные: DAT_300e60c4, DAT_300e60d0, DAT_300e60d8, DAT_300e60dc, DAT_300e60e0, DAT_300e60e8, DAT_300e60f0, DAT_300e60f4
 * ---------------------------------------------------------------- */
int sigqueue(__pid_t __pid,int __sig,sigval __val)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 auStack_40 [8];
  int local_38;
  undefined4 local_34;
  sigval local_30 [6];
  sigval local_4;
  
  puVar1 = DAT_300e60dc;
  local_4 = __val;
  iVar2 = objVerify(__pid,*DAT_300e60dc);
  if (iVar2 == 0) {
    iVar2 = __pid;
    if (__pid == 0) {
      iVar2 = *DAT_300e60c4;
    }
    if (*(int *)(iVar2 + 0x94) == *DAT_300e60e0) {
      if (__sig - 1U < 0x3f) {
        if ((*DAT_300e60d8 == 1) || ((0 < *DAT_300e60e8 && (*DAT_300e60c4 == __pid)))) {
          iVar2 = objVerify(__pid,*puVar1);
          if (iVar2 != 0) {
            errnoSet(0x16);
            return -1;
          }
          if (*DAT_300e60d0 == 0) {
            errnoSet(0xb);
            return -1;
          }
          excJobAdd(DAT_300e60f4,__pid,__sig,local_4.sival_int,0,0,0);
        }
        else {
          *DAT_300e60d8 = 1;
          iVar2 = objVerify(__pid,*puVar1);
          if (iVar2 != 0) {
            windExit();
            errnoSet(0x16);
            return -1;
          }
          if (*DAT_300e60d0 == 0) {
            windExit();
            errnoSet(0xb);
            return -1;
          }
          sigPendInit(auStack_40);
          local_34 = 2;
          local_30[0] = local_4;
          local_38 = __sig;
          FUN_300e55ec(__pid,auStack_40,local_30,&local_4);
          windExit();
        }
        iVar2 = 0;
      }
      else {
        errnoSet(0x16);
        iVar2 = -1;
      }
    }
    else {
      iVar2 = (*(code *)*DAT_300e60f0)(__pid,__sig,local_4.sival_int);
    }
  }
  else {
    errnoSet(0x16);
    iVar2 = -1;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300e5dec @ 0x300E5DEC  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: sigqueue
 * Константы: 0x300E5DEC
 * ---------------------------------------------------------------- */
void FUN_300e5dec(__pid_t param_1,int param_2,sigval param_3)

{
  sigqueue(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * sigPendKill @ 0x300E5E04  (примерный размер ~228 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300e55ec, errnoSet, excJobAdd, objVerify, windExit
 * Вызывают: FUN_300e5ff0
 * Константы: 0xFFFFFFFF, 0x300E5E04
 * Данные: DAT_300e60c4, DAT_300e60d8, DAT_300e60dc, DAT_300e60e8, DAT_300e60f8
 * ---------------------------------------------------------------- */
undefined4 sigPendKill(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((*DAT_300e60d8 == 1) || ((0 < *DAT_300e60e8 && (*DAT_300e60c4 == param_1)))) {
    iVar1 = objVerify(param_1,*DAT_300e60dc);
    if (iVar1 != 0) {
      errnoSet(0x16);
      return 0xffffffff;
    }
    excJobAdd(DAT_300e60f8,param_1,param_2,0,0,0,0);
  }
  else {
    *DAT_300e60d8 = 1;
    iVar1 = objVerify(param_1,*DAT_300e60dc);
    if (iVar1 != 0) {
      windExit();
      errnoSet(0x16);
      return 0xffffffff;
    }
    FUN_300e55ec(param_1,param_2);
    windExit();
  }
  return 0;
}

/* ----------------------------------------------------------------
 * sigPendDestroy @ 0x300E5EE8  (примерный размер ~264 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: __errno, __lsl64, windExit
 * Вызывают: FUN_300e5ff0
 * Константы: 0x300E5EE8, 0xFFFFFFFF
 * Данные: DAT_300e60cc, DAT_300e60d8, DAT_300e60e8, DAT_300e60fc
 * ---------------------------------------------------------------- */
undefined4 sigPendDestroy(int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  
  if (*DAT_300e60e8 < 1) {
    param_1[5] = 0;
    *DAT_300e60d8 = 1;
    if (*param_1 != 0) {
      iVar6 = param_1[1];
      if (iVar6 == *param_1) {
        iVar3 = param_1[2];
        if ((iVar3 < 1) || (0x40 < iVar3)) {
          uVar7 = 0;
        }
        else {
          uVar7 = __lsl64(1,0,iVar3 + -1);
        }
        iVar3 = param_1[8];
        uVar5 = *(uint *)(iVar3 + 0x610);
        puVar4 = (uint *)(iVar3 + DAT_300e60cc);
        *puVar4 = *puVar4 & (*(uint *)(iVar3 + 0x60c) | ~(uint)uVar7);
        puVar4[1] = puVar4[1] & (uVar5 | ~(uint)((ulonglong)uVar7 >> 0x20));
      }
      *(int *)(*param_1 + 4) = iVar6;
      *(int *)param_1[1] = *param_1;
      *param_1 = 0;
      param_1[1] = 0;
    }
    windExit();
    uVar2 = 0;
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300e60fc;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300e5ff0 @ 0x300E5FF0  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: sigPendDestroy, sigPendInit, sigPendKill
 * Вызывают: FUN_300e604c
 * Константы: 0x300E5FF0
 * Данные: DAT_300e60c4
 * ---------------------------------------------------------------- */
void FUN_300e5ff0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_40 [8];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_24;
  
  iVar2 = *DAT_300e60c4;
  uVar1 = *(undefined4 *)(iVar2 + 0x120);
  *(undefined4 *)(iVar2 + 0x120) = 0;
  sigPendInit(auStack_40);
  local_34 = 0;
  local_38 = param_1;
  local_30 = param_2;
  local_24 = param_3;
  sigPendKill(iVar2,auStack_40);
  sigPendDestroy(auStack_40);
  *(undefined4 *)(iVar2 + 0x120) = uVar1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300e604c @ 0x300E604C  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300e5ff0
 * Константы: 0x300E604C
 * Данные: DAT_300e6100, DAT_300e6104, DAT_300e6108
 * ---------------------------------------------------------------- */
void FUN_300e604c(int param_1)

{
  uint uVar1;
  int *piVar2;
  
  for (piVar2 = DAT_300e6100; (*piVar2 != 0 || (piVar2[1] != 0)); piVar2 = piVar2 + 2) {
    if (*piVar2 == param_1) {
      if (*DAT_300e6104 == 0) {
        uVar1 = piVar2[1] & 0xffff;
      }
      else {
        uVar1 = (piVar2[1] & DAT_300e6108) >> 0x10;
      }
      FUN_300e5ff0(uVar1);
      return;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300e610c @ 0x300E610C  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300e61bc, trcStackCtxTrace
 * Константы: 0x300E610C, 0xFFFFFFFF
 * Данные: DAT_300e64d0
 * ---------------------------------------------------------------- */
undefined4 FUN_300e610c(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  
  uVar2 = 0;
  local_18 = 0;
  if ((param_2 != 0) && (param_3 != 0)) {
    if (0 < (int)param_4[5]) {
      uVar2 = (**(code **)(DAT_300e64d0 + 4))
                        (param_2,param_3,param_1,param_4[6],param_4[5],&local_18);
    }
    iVar1 = (*(code *)*param_4)(param_2,param_3,uVar2,local_18,param_4[1],param_4[2],param_4[4]);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300e61bc @ 0x300E61BC  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300e610c
 * Вызывают: trcStackCtxTrace
 * Константы: 0x300E61BC, 0xFFFFFFFF
 * Данные: DAT_300e64d0
 * ---------------------------------------------------------------- */
undefined4 FUN_300e61bc(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_20c;
  int local_208;
  int local_204;
  int local_200 [120];
  
  puVar1 = DAT_300e64d0;
  piVar3 = local_200;
  iVar4 = 0x28;
  do {
    iVar2 = (*(code *)*puVar1)(param_1,param_2,*(undefined4 *)(param_3 + 0xc),&local_208,&local_20c,
                               &local_204);
    if (((iVar2 == -1) || (local_20c == 0)) || (local_208 == 0)) break;
    *piVar3 = param_1;
    piVar3[1] = local_20c;
    iVar4 = iVar4 + -1;
    piVar3[2] = local_204;
    piVar3 = piVar3 + 3;
    param_1 = local_208;
    param_2 = local_20c;
  } while (iVar4 != 0);
  iVar4 = 0x27 - iVar4;
  piVar3 = local_200 + iVar4 * 3;
  while( true ) {
    if (iVar4 < 0) {
      return 0;
    }
    iVar2 = FUN_300e610c(*piVar3,piVar3[1],piVar3[2],param_3);
    if (iVar2 == -1) break;
    piVar3 = piVar3 + -3;
    iVar4 = iVar4 + -1;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * trcStackCtxTrace @ 0x300E62AC  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300e610c, FUN_300e61bc
 * Вызывают: trcStackTrace
 * Константы: 0x300E62AC, 0xFFFFFFFF
 * Данные: DAT_300e64d0, DAT_300e64d4
 * ---------------------------------------------------------------- */
undefined4 trcStackCtxTrace(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 8) == 0) {
    *(undefined4 *)(iVar1 + 8) = DAT_300e64d4;
  }
  iVar1 = (**(code **)(DAT_300e64d0 + 8))(iVar1,&local_14,&local_10,&local_18,&local_c);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = FUN_300e61bc(local_10,local_18,param_1);
    if (iVar1 == 0) {
      FUN_300e610c(local_14,local_18,local_c,param_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * trcStackTrace @ 0x300E6334  (примерный размер ~336 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: taskTcb, trcStackCtxTrace
 * Вызывают: exchStackTrace, trcStack
 * Константы: 0xFFFFFFFF, 0x300E6334
 * Данные: DAT_300e64d4, DAT_300e64d8, DAT_300e64dc, DAT_300e64e0, DAT_300e64e4
 * ---------------------------------------------------------------- */
undefined4 trcStackTrace(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  iVar1 = taskTcb(*(undefined4 *)(param_2 + 4));
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    local_24 = *(undefined4 *)(iVar1 + 0xc4);
    local_20 = *(undefined4 *)(iVar1 + 200);
    local_1c = DAT_300e64d4;
    local_14 = 0;
    *(uint *)(param_2 + 8) = *(uint *)(iVar1 + 0x98) & 1;
    *(undefined4 **)(param_2 + 0xc) = &local_24;
    local_18 = param_1;
    iVar3 = trcStackCtxTrace(param_2);
    if (iVar3 == -1) {
      if ((*(int *)(param_2 + 0x1c) != 0) && ((code *)*DAT_300e64d8 != (code *)0x0)) {
        (*(code *)*DAT_300e64d8)(DAT_300e64dc);
      }
      uVar2 = 0xffffffff;
    }
    else {
      if (local_14 != 0) {
        if ((*(int *)(param_2 + 0x1c) != 0) && ((code *)*DAT_300e64d8 != (code *)0x0)) {
          (*(code *)*DAT_300e64d8)(DAT_300e64e0);
        }
        local_24 = *(undefined4 *)(iVar1 + 0x60);
        local_20 = *(undefined4 *)(iVar1 + 100);
        local_14 = 0;
        *(undefined4 *)(param_2 + 8) = 1;
        local_18 = param_1;
        iVar1 = trcStackCtxTrace(param_2);
        if (iVar1 == -1) {
          if ((*(int *)(param_2 + 0x1c) != 0) && ((code *)*DAT_300e64d8 != (code *)0x0)) {
            (*(code *)*DAT_300e64d8)(DAT_300e64e4);
          }
          return 0xffffffff;
        }
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300e6484 @ 0x300E6484  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: vxMemProbe
 * Константы: 0x300E6484, 0xFFFFFFFF
 * Данные: DAT_300e64e8, DAT_300e64ec
 * ---------------------------------------------------------------- */
undefined4 FUN_300e6484(uint param_1)

{
  undefined4 uVar1;
  undefined1 auStack_8 [8];
  
  if ((param_1 < DAT_300e64e8) || (DAT_300e64ec <= param_1)) {
    uVar1 = vxMemProbe(param_1,0,4,auStack_8);
  }
  else {
    uVar1 = 0xffffffff;
    if ((param_1 & 3) == 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * classListLibInit @ 0x300E665C  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrInit
 * Константы: 0x300E665C
 * Данные: DAT_300e6814, DAT_300e6818, DAT_300e681c, DAT_300e6820, DAT_300e6824, DAT_300e6828, DAT_300e682c, DAT_300e6830
 * ---------------------------------------------------------------- */
undefined4 classListLibInit(void)

{
  *DAT_300e6818 = DAT_300e6814;
  *DAT_300e6820 = DAT_300e681c;
  *DAT_300e6828 = DAT_300e6824;
  *DAT_300e6830 = DAT_300e682c;
  *DAT_300e6838 = DAT_300e6834;
  *DAT_300e6840 = DAT_300e683c;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300e66ac @ 0x300E66AC  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: semMInit
 * Константы: 0x300E66AC
 * Данные: DAT_300e6844
 * ---------------------------------------------------------------- */
void FUN_300e66ac(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0x15;
  iVar2 = DAT_300e6844;
  do {
    semMInit(iVar2,0xd);
    iVar2 = iVar2 + 0x68;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300e66d4 @ 0x300E66D4  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllInit
 * Константы: 0x300E66D4
 * Данные: DAT_300e6848
 * ---------------------------------------------------------------- */
void FUN_300e66d4(int param_1,int param_2)

{
  *(int *)(param_1 + 0x50) = DAT_300e6848 + param_2 * 0x68;
  dllInit(param_1 + 0x48);
  dllInit(param_1 + 0x40);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300e6704 @ 0x300E6704  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllAdd
 * Константы: 0x300E6704
 * Данные: DAT_300e6818, DAT_300e6820
 * ---------------------------------------------------------------- */
void FUN_300e6704(int param_1,int param_2)

{
  int iVar1;
  
  (*(code *)*DAT_300e6818)(param_2);
  if ((*(ushort *)(param_1 + 8) & 0x40) == 0) {
    iVar1 = param_2 + 0x40;
  }
  else {
    iVar1 = param_2 + 0x48;
  }
  dllAdd(iVar1,param_1 + 0x1c);
  (*(code *)*DAT_300e6820)(param_2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300e675c @ 0x300E675C  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllRemove
 * Константы: 0x300E675C
 * Данные: DAT_300e6818, DAT_300e6820
 * ---------------------------------------------------------------- */
void FUN_300e675c(int param_1,int param_2)

{
  int iVar1;
  
  (*(code *)*DAT_300e6818)(param_2);
  if ((*(ushort *)(param_1 + 8) & 0x40) == 0) {
    iVar1 = param_2 + 0x40;
  }
  else {
    iVar1 = param_2 + 0x48;
  }
  dllRemove(iVar1,param_1 + 0x1c);
  (*(code *)*DAT_300e6820)(param_2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300e67b4 @ 0x300E67B4  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: semMTakeScalable
 * Константы: 0x300E67B4, 0xFFFFFFFF
 * Данные: DAT_300e684c
 * ---------------------------------------------------------------- */
void FUN_300e67b4(int param_1)

{
  semMTakeScalable(*(undefined4 *)(param_1 + 0x50),0xffffffff,DAT_300e684c);
  return;
}

/* ----------------------------------------------------------------
 * objInfoInit @ 0x300E685C  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrInit
 * Константы: 0x300E685C
 * Данные: DAT_300e6b9c, DAT_300e6ba0
 * ---------------------------------------------------------------- */
undefined4 objInfoInit(void)

{
  *DAT_300e6b9c = DAT_300e6ba0;
  return 0;
}

/* ----------------------------------------------------------------
 * objInfo @ 0x300E6870  (примерный размер ~288 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: dllCount, errnoSet, objClassIdGet
 * Вызывают: taskIdListGet
 * Константы: 0x300E6870
 * Данные: DAT_300e6ba4, DAT_300e6ba8, DAT_300e6bac
 * ---------------------------------------------------------------- */
int objInfo(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  if ((param_1 < 0x16) && (iVar1 = objClassIdGet(param_1), iVar1 != 0)) {
    (*(code *)*DAT_300e6ba8)(iVar1);
    if (param_2 == (int *)0x0) {
      iVar3 = dllCount(iVar1 + 0x48);
      iVar2 = dllCount(iVar1 + 0x40);
      iVar2 = iVar2 + iVar3;
      (*(code *)*DAT_300e6bac)(iVar1);
    }
    else {
      piVar5 = param_2;
      for (piVar4 = *(int **)(iVar1 + 0x40); piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        param_3 = param_3 + -1;
        if (param_3 < 0) goto LAB_300e693c;
        *piVar5 = (int)(piVar4 + -7);
        piVar5 = piVar5 + 1;
      }
      if (param_3 != 0) {
LAB_300e693c:
        piVar4 = *(int **)(iVar1 + 0x48);
        while ((piVar4 != (int *)0x0 && (param_3 = param_3 + -1, -1 < param_3))) {
          *piVar5 = (int)(piVar4 + -7);
          piVar4 = (int *)*piVar4;
          piVar5 = piVar5 + 1;
        }
      }
      (*(code *)*DAT_300e6bac)(iVar1);
      iVar2 = (int)piVar5 - (int)param_2 >> 2;
    }
  }
  else {
    errnoSet(DAT_300e6ba4);
    iVar2 = 0;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * objEach @ 0x300E6990  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: errnoSet, objClassIdGet
 * Вызывают: FUN_300e6b04, objNameToId
 * Константы: 0x300E6990
 * Данные: DAT_300e6ba4, DAT_300e6ba8, DAT_300e6bac
 * ---------------------------------------------------------------- */
int objEach(int param_1,code *param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  if ((param_1 < 0x16) && (iVar2 = objClassIdGet(), iVar2 != 0)) {
    (*(code *)*DAT_300e6ba8)(iVar2);
    if (param_4 == 0) {
      piVar5 = (int *)*(int *)(iVar2 + 0x40);
    }
    else {
      piVar5 = (int *)*(int *)(iVar2 + 0x48);
    }
    do {
      piVar1 = piVar5;
      if (piVar1 == (int *)0x0) break;
      iVar4 = (int)(piVar1 + -7);
      piVar5 = (int *)*piVar1;
      iVar3 = (*param_2)(iVar4,param_3);
    } while (iVar3 != 0);
    (*(code *)*DAT_300e6bac)(iVar2);
    if (piVar1 == (int *)0x0) {
      iVar4 = 0;
    }
  }
  else {
    errnoSet(DAT_300e6ba4);
    iVar4 = 0;
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * objNameToId @ 0x300E6A58  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: objEach
 * Вызывают: taskNameToId
 * Константы: 0x300E6A58
 * Данные: DAT_300e6bb0
 * ---------------------------------------------------------------- */
undefined4 objNameToId(undefined4 param_1,char *param_2)

{
  undefined4 uVar1;
  
  if (param_2 != (char *)0x0) {
    uVar1 = objEach(param_1,DAT_300e6bb0,param_2,*param_2 == '/');
    return uVar1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300e6a90 @ 0x300E6A90  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: strcmp
 * Константы: 0x300E6A90
 * Данные: DAT_300e6bb4, DAT_300e6bb8
 * ---------------------------------------------------------------- */
bool FUN_300e6a90(int param_1,char *param_2)

{
  int iVar1;
  
  if ((*(char **)(param_1 + 0x2c) != (char *)0x0) &&
     (iVar1 = strcmp(*(char **)(param_1 + 0x2c),param_2), iVar1 == 0)) {
    if (*param_2 != '/') {
      if (*DAT_300e6bb4 == 0) {
        iVar1 = *DAT_300e6bb8;
      }
      else {
        iVar1 = *(int *)(*DAT_300e6bb4 + 0x94);
      }
      return *(int *)(param_1 + 0x28) != iVar1;
    }
    return false;
  }
  return true;
}

/* ----------------------------------------------------------------
 * FUN_300e6b04 @ 0x300E6B04  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: errnoSet, objEach
 * Константы: 0x300E6B04, 0xFFFFFFFF
 * Данные: DAT_300e6ba8, DAT_300e6bac, DAT_300e6bb0, DAT_300e6bbc
 * ---------------------------------------------------------------- */
undefined4 FUN_300e6b04(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  (*(code *)*DAT_300e6ba8)(param_2);
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = objEach(*(undefined4 *)(*(int *)(param_1 + 0x30) + 0x38),DAT_300e6bb0,param_3);
  }
  uVar2 = 0;
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x2c) = param_3;
  }
  else {
    errnoSet(DAT_300e6bbc);
    uVar2 = 0xffffffff;
  }
  (*(code *)*DAT_300e6bac)(param_2);
  return uVar2;
}

/* ----------------------------------------------------------------
 * fstat @ 0x300E76BC  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: ioctl
 * Вызывают: attrib, rmdir
 * Константы: 0x300E76BC
 * ---------------------------------------------------------------- */
int fstat(int __fd,stat *__buf)

{
  int iVar1;
  
  iVar1 = ioctl(__fd,0x40,__buf);
  return iVar1;
}

/* ----------------------------------------------------------------
 * opendir @ 0x300E76C8  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 10 | Вызывает: 7
 * Вызывает: calloc, close, errnoSet, free, ioctl, open, semMCreate
 * Вызывают: BSP_opendir, FUN_3011a5a0, TFUP_GetAllFileName, completionPathListGet, cp, dirList, exchFileSave, mv, xattrib, xcopy
 * Константы: 0x300E76C8
 * ---------------------------------------------------------------- */
DIR * opendir(char *__name)

{
  int iVar1;
  DIR *__ptr;
  int iVar2;
  undefined1 auStack_54 [8];
  uint local_4c;
  
  iVar1 = open(__name,0,0);
  if (iVar1 == -1) {
    __ptr = (DIR *)0x0;
  }
  else {
    iVar2 = ioctl(iVar1,0x40,auStack_54);
    if (iVar2 == 0) {
      if ((local_4c & 0xf000) == 0x4000) {
        __ptr = (DIR *)calloc(0x114,1);
        if (__ptr == (DIR *)0x0) {
          close(iVar1);
          __ptr = (DIR *)0x0;
        }
        else {
          *(int *)__ptr = iVar1;
          *(int *)(__ptr + 4) = 0;
          iVar1 = semMCreate(9);
          if (iVar1 == 0) {
            free(__ptr);
            __ptr = (DIR *)0x0;
          }
          else {
            *(int *)(__ptr + 0x110) = iVar1;
          }
        }
      }
      else {
        errnoSet(0x14);
        close(iVar1);
        __ptr = (DIR *)0x0;
      }
    }
    else {
      close(iVar1);
      __ptr = (DIR *)0x0;
    }
  }
  return __ptr;
}

/* ----------------------------------------------------------------
 * readdir @ 0x300E77A4  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 11 | Вызывает: 1
 * Вызывает: ioctl
 * Вызывают: BSP_readdir, FUN_3011a5a0, TFUP_GetAllFileName, completionPathListGet, cp, dirList, exchFileSave, mv, readdir_r, xattrib
 *           ...
 * Константы: 0x300E77A4
 * ---------------------------------------------------------------- */
dirent * readdir(DIR *__dirp)

{
  int iVar1;
  
  *(undefined4 *)(__dirp + 8) = 0;
  iVar1 = ioctl(*(int *)__dirp,0x25,__dirp);
  if (iVar1 != 0) {
    return (dirent *)0x0;
  }
  if (*(int *)(__dirp + 8) != 0) {
    return (dirent *)0x0;
  }
  return (dirent *)(__dirp + 0xc);
}

/* ----------------------------------------------------------------
 * readdir_r @ 0x300E77F0  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: __errno, memcpy, readdir, semGive, semTake
 * Константы: 0x300E77F0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int readdir_r(DIR *__dirp,dirent *__entry,dirent **__result)

{
  undefined4 *puVar1;
  dirent *__src;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(__dirp + 0x110);
  semTake(uVar3,0xffffffff);
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 0;
  __src = readdir(__dirp);
  if (__src == (dirent *)0x0) {
    *__result = (dirent *)0x0;
    semGive(uVar3);
    piVar2 = (int *)__errno();
    return *piVar2;
  }
  memcpy(__entry,__src,0x104);
  *__result = __entry;
  semGive(uVar3);
  return 0;
}

/* ----------------------------------------------------------------
 * rewinddir @ 0x300E7870  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300E7870
 * ---------------------------------------------------------------- */
void rewinddir(DIR *__dirp)

{
  *(undefined4 *)(__dirp + 4) = 0;
  return;
}

/* ----------------------------------------------------------------
 * closedir @ 0x300E787C  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 10 | Вызывает: 3
 * Вызывает: close, free, semDelete
 * Вызывают: BSP_closedir, FUN_3011a5a0, TFUP_GetAllFileName, completionPathListGet, cp, dirList, exchFileSave, mv, xattrib, xcopy
 * Константы: 0x300E787C
 * ---------------------------------------------------------------- */
int closedir(DIR *__dirp)

{
  int iVar1;
  
  iVar1 = close(*(int *)__dirp);
  if (iVar1 != -1) {
    semDelete(*(undefined4 *)(__dirp + 0x110));
    free(__dirp);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * stat @ 0x300E78B0  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 5
 * Вызывает: close, errnoGet, errnoSet, ioctl, open
 * Вызывают: BSP_stat, FUN_30118f30, FUN_30118fec, completionPathListGet, dirList, shellInOutRedirectOpen
 * Константы: 0x300E78B0
 * ---------------------------------------------------------------- */
int stat(char *__file,stat *__buf)

{
  undefined4 uVar1;
  int __fd;
  uint uVar2;
  uint uVar3;
  
  uVar1 = errnoGet();
  __fd = open(__file,0,0);
  if ((__fd < 0) && (__fd = open(__file,0x40000,0), __fd < 0)) {
    return -1;
  }
  errnoSet(uVar1);
  uVar2 = ioctl(__fd,0x40,__buf);
  uVar3 = close(__fd);
  return uVar3 | uVar2;
}

/* ----------------------------------------------------------------
 * fstatfs @ 0x300E7930  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: ioctl
 * Константы: 0x300E7930
 * ---------------------------------------------------------------- */
int fstatfs(int __fildes,statfs *__buf)

{
  int iVar1;
  
  iVar1 = ioctl(__fildes,0x2e,__buf);
  return iVar1;
}

/* ----------------------------------------------------------------
 * fstatfs64 @ 0x300E793C  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: ioctl
 * Константы: 0x300E793C
 * ---------------------------------------------------------------- */
int fstatfs64(int __fildes,statfs64 *__buf)

{
  int iVar1;
  
  iVar1 = ioctl(__fildes,0x46,__buf);
  return iVar1;
}

/* ----------------------------------------------------------------
 * statfs @ 0x300E7948  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: close, errnoGet, errnoSet, ioctl, open
 * Константы: 0x300E7948
 * ---------------------------------------------------------------- */
int statfs(char *__file,statfs *__buf)

{
  undefined4 uVar1;
  int __fd;
  uint uVar2;
  uint uVar3;
  
  uVar1 = errnoGet();
  __fd = open(__file,0,0);
  if ((__fd < 0) && (__fd = open(__file,0x40000,0), __fd < 0)) {
    return -1;
  }
  errnoSet(uVar1);
  uVar2 = ioctl(__fd,0x2e,__buf);
  uVar3 = close(__fd);
  return uVar3 | uVar2;
}

/* ----------------------------------------------------------------
 * statfs64 @ 0x300E79C8  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: close, errnoGet, errnoSet, ioctl, open
 * Константы: 0x300E79C8
 * ---------------------------------------------------------------- */
int statfs64(char *__file,statfs64 *__buf)

{
  undefined4 uVar1;
  int __fd;
  uint uVar2;
  uint uVar3;
  
  uVar1 = errnoGet();
  __fd = open(__file,0,0);
  if ((__fd < 0) && (__fd = open(__file,0x40000,0), __fd < 0)) {
    return -1;
  }
  errnoSet(uVar1);
  uVar2 = ioctl(__fd,0x46,__buf);
  uVar3 = close(__fd);
  return uVar3 | uVar2;
}

/* ----------------------------------------------------------------
 * utime @ 0x300E7A48  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: close, ioctl, open
 * Константы: 0x300E7A48
 * Данные: DAT_300e7ab8
 * ---------------------------------------------------------------- */
int utime(char *__file,utimbuf *__file_times)

{
  undefined4 uVar1;
  int __fd;
  int iVar2;
  
  uVar1 = DAT_300e7ab8;
  __fd = open(__file,0,DAT_300e7ab8);
  if ((__fd < 0) && (__fd = open(__file,0x40000,uVar1), __fd < 0)) {
    return -1;
  }
  iVar2 = ioctl(__fd,0x2c,__file_times);
  close(__fd);
  return iVar2;
}

/* ----------------------------------------------------------------
 * creat @ 0x300E7EA0  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 15
 * Вызывает: __errno, errnoSet, ioFullFileNameGet, iosCreate, iosDevFind, iosFdEntryGet, iosFdEntryReturn, iosRtpFdReserve, iosRtpFdSetup, iosRtpFdUnmap2, memPartAlloc, memPartFree, memcmp, strcpy
 *           ...
 * Константы: 0x300E7EA0, 0x300E7D24
 * Данные: DAT_300e862c, DAT_300e8634, DAT_300e8638, DAT_300e863c, DAT_300e8640, DAT_300e8644, DAT_300e8648
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300e7d24) */

int creat(char *__file,__mode_t __mode)

{
  int iVar1;
  int iVar2;
  char *__dest;
  int iVar3;
  undefined4 *puVar4;
  char *__src;
  int iVar5;
  int local_44;
  char *local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  
  iVar5 = 1;
  local_38 = 0;
  if ((__file == (char *)0x0) || (*__file == '\0')) {
    errnoSet(2);
    return -1;
  }
  local_44 = iosRtpFdReserve(*(undefined4 *)(*DAT_300e862c + 0x94));
  if (local_44 == -1) {
    if ((code *)*DAT_300e8634 == (code *)0x0) {
      return -1;
    }
    iVar1 = (*(code *)*DAT_300e8634)(1,&local_38,__mode,&local_44);
    if (iVar1 != 0) {
      return -1;
    }
  }
  iVar1 = iosFdEntryGet();
  if (iVar1 == 0) {
    iosRtpFdUnmap2(*(undefined4 *)(*DAT_300e862c + 0x94),local_44,local_38);
    local_44 = -1;
  }
  else {
    iVar2 = memcmp(__file,DAT_300e8638,2);
    if (iVar2 == 0) {
      __file = __file + 1;
    }
    __dest = (char *)memPartAlloc(*DAT_300e863c,0x800);
    if (__dest == (char *)0x0) {
      iosRtpFdUnmap2(*(undefined4 *)(*DAT_300e862c + 0x94),local_44,local_38);
      iosFdEntryReturn(iVar1);
      local_44 = -1;
    }
    else {
      if ((code *)*DAT_300e8640 != (code *)0x0) {
        (*(code *)*DAT_300e8640)(0,&local_30);
      }
      iVar2 = ioFullFileNameGet(__file,&local_3c,__dest);
      if (iVar2 != -1) {
        __src = *(char **)(local_3c + 0xc);
        iVar2 = local_3c;
        do {
          strcpy(__dest + 0x400,__src);
          do {
            iVar3 = iosCreate(iVar2,__dest,__mode);
            if (iVar3 == -1) goto LAB_300e7e44;
            if (iVar3 != -2) {
              if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != DAT_300e8648)) &&
                  (*(int *)(iVar2 + 0xc) != 0)) &&
                 (local_3c = iVar2, local_34 = ioFullFileNameGet(__dest + 0x400,&local_3c,__dest),
                 iVar2 = local_3c, local_34 == -1)) goto LAB_300e7e44;
              iosRtpFdSetup(*(undefined4 *)(*DAT_300e862c + 0x94),iVar1,local_44,iVar2,__file,iVar3)
              ;
              *(__mode_t *)(iVar1 + 0x50) = __mode;
              goto LAB_300e7e6c;
            }
            if (*DAT_300e8644 < iVar5) {
              puVar4 = (undefined4 *)__errno();
              *puVar4 = 0x40;
              goto LAB_300e7e44;
            }
            iVar5 = iVar5 + 1;
            iVar3 = iosDevFind(__dest,&local_40);
            if (iVar3 == 0) goto LAB_300e7e44;
          } while (__dest == local_40);
          strncpy(__dest,local_40,0x400);
          __dest[0x3ff] = '\0';
          __src = *(char **)(iVar3 + 0xc);
          iVar2 = iVar3;
        } while( true );
      }
LAB_300e7e44:
      iosFdEntryReturn(iVar1);
      iosRtpFdUnmap2(*(undefined4 *)(*DAT_300e862c + 0x94),local_44,local_38);
      local_44 = -1;
LAB_300e7e6c:
      if (*DAT_300e8640 != 0) {
        (*(code *)*DAT_300e8640)(local_30,0);
      }
      memPartFree(*DAT_300e863c,__dest);
    }
  }
  return local_44;
}

/* ----------------------------------------------------------------
 * open @ 0x300E7EAC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 38 | Вызывает: 15
 * Вызывает: __errno, errnoSet, ioFullFileNameGet, iosDevFind, iosFdEntryGet, iosFdEntryReturn, iosOpen, iosRtpFdReserve, iosRtpFdSetup, iosRtpFdUnmap2, memPartAlloc, memPartFree, memcmp, strcpy
 *           ...
 * Вызывают: ABB_ReadCfg, BSP_DLOAD_Init, BSP_IfConfigFromFile, BSP_LDScript, BSP_ShowIfCfgFile, FUN_3000c338, FUN_300f8168, FUN_30101f90, FUN_30119fb0, access
 *           ...
 * Константы: 0x300E7EAC, 0x300E7D10
 * Данные: DAT_300e862c, DAT_300e8634, DAT_300e8638, DAT_300e863c, DAT_300e8640, DAT_300e8644, DAT_300e8648
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300e7d10) */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  int iVar2;
  char *__dest;
  undefined4 *puVar3;
  int iVar4;
  char *__src;
  undefined4 in_r2;
  int iVar5;
  int iStack_44;
  char *pcStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 uStack_30;
  
  iVar5 = 1;
  uStack_38 = 0;
  if ((__file == (char *)0x0) || (*__file == '\0')) {
    errnoSet(2);
    return -1;
  }
  iStack_44 = iosRtpFdReserve(*(undefined4 *)(*DAT_300e862c + 0x94));
  if (iStack_44 == -1) {
    if ((code *)*DAT_300e8634 == (code *)0x0) {
      return -1;
    }
    iVar1 = (*(code *)*DAT_300e8634)(0,&uStack_38,__oflag,&iStack_44);
    if (iVar1 != 0) {
      return -1;
    }
  }
  iVar1 = iosFdEntryGet();
  if (iVar1 == 0) {
    iosRtpFdUnmap2(*(undefined4 *)(*DAT_300e862c + 0x94),iStack_44,uStack_38);
    iStack_44 = -1;
  }
  else {
    iVar2 = memcmp(__file,DAT_300e8638,2);
    if (iVar2 == 0) {
      __file = __file + 1;
    }
    __dest = (char *)memPartAlloc(*DAT_300e863c,0x800);
    if (__dest == (char *)0x0) {
      iosRtpFdUnmap2(*(undefined4 *)(*DAT_300e862c + 0x94),iStack_44,uStack_38);
      iosFdEntryReturn(iVar1);
      iStack_44 = -1;
    }
    else {
      if ((code *)*DAT_300e8640 != (code *)0x0) {
        (*(code *)*DAT_300e8640)(0,&uStack_30);
      }
      iVar2 = ioFullFileNameGet(__file,&iStack_3c,__dest);
      if (iVar2 != -1) {
        __src = *(char **)(iStack_3c + 0xc);
        iVar2 = iStack_3c;
        do {
          strcpy(__dest + 0x400,__src);
          do {
            iVar4 = iosOpen(iVar2,__dest,__oflag,in_r2);
            if (iVar4 == -1) goto LAB_300e7e44;
            if (iVar4 != -2) {
              if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != DAT_300e8648)) &&
                  (*(int *)(iVar2 + 0xc) != 0)) &&
                 (iStack_3c = iVar2, iStack_34 = ioFullFileNameGet(__dest + 0x400,&iStack_3c,__dest)
                 , iVar2 = iStack_3c, iStack_34 == -1)) goto LAB_300e7e44;
              iosRtpFdSetup(*(undefined4 *)(*DAT_300e862c + 0x94),iVar1,iStack_44,iVar2,__file,iVar4
                           );
              *(int *)(iVar1 + 0x50) = __oflag;
              goto LAB_300e7e6c;
            }
            if (*DAT_300e8644 < iVar5) {
              puVar3 = (undefined4 *)__errno();
              *puVar3 = 0x40;
              goto LAB_300e7e44;
            }
            iVar5 = iVar5 + 1;
            iVar4 = iosDevFind(__dest,&pcStack_40);
            if (iVar4 == 0) goto LAB_300e7e44;
          } while (__dest == pcStack_40);
          strncpy(__dest,pcStack_40,0x400);
          __dest[0x3ff] = '\0';
          __src = *(char **)(iVar4 + 0xc);
          iVar2 = iVar4;
        } while( true );
      }
LAB_300e7e44:
      iosFdEntryReturn(iVar1);
      iosRtpFdUnmap2(*(undefined4 *)(*DAT_300e862c + 0x94),iStack_44,uStack_38);
      iStack_44 = -1;
LAB_300e7e6c:
      if (*DAT_300e8640 != 0) {
        (*(code *)*DAT_300e8640)(uStack_30,0);
      }
      memPartFree(*DAT_300e863c,__dest);
    }
  }
  return iStack_44;
}

/* ----------------------------------------------------------------
 * close @ 0x300E7EB4  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 45 | Вызывает: 1
 * Вызывает: iosClose
 * Вызывают: ABB_ReadCfg, BSP_IfConfigFromFile, BSP_LDScript, BSP_ShowIfCfgFile, FUN_3000c338, FUN_300f7564, FUN_300f81ac, FUN_30101f90, FUN_3010ef1c, FUN_30110e10
 *           ...
 * Константы: 0x300E7EB4
 * Данные: DAT_300e8640
 * ---------------------------------------------------------------- */
int close(int __fd)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_10;
  
  puVar1 = DAT_300e8640;
  if ((code *)*DAT_300e8640 != (code *)0x0) {
    (*(code *)*DAT_300e8640)(0,&local_10);
  }
  iVar2 = iosClose(__fd);
  if ((code *)*puVar1 != (code *)0x0) {
    (*(code *)*puVar1)(local_10,0);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300e7f1c @ 0x300E7F1C  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: read, write
 * Константы: 0x300E7F1C
 * Данные: DAT_300e8640
 * ---------------------------------------------------------------- */
undefined4 FUN_300e7f1c(code *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 local_20;
  
  puVar1 = DAT_300e8640;
  if ((code *)*DAT_300e8640 != (code *)0x0) {
    (*(code *)*DAT_300e8640)(0,&local_20);
  }
  uVar2 = (*param_1)(param_2,param_3,param_4);
  if ((code *)*puVar1 != (code *)0x0) {
    (*(code *)*puVar1)(local_20,0);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * read @ 0x300E7FA0  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 18 | Вызывает: 1
 * Вызывает: FUN_300e7f1c
 * Вызывают: ABB_ReadCfg, BSP_OsWait, FUN_3000c000, FUN_300f6f30, FUN_300f7094, FUN_300f72a4, FUN_300f8b2c, FUN_30112ec0, __sread, fioRdString
 *           ...
 * Константы: 0x300E7FA0
 * Данные: DAT_300e864c
 * ---------------------------------------------------------------- */
ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  if (__nbytes == 0) {
    sVar1 = 0;
  }
  else {
    sVar1 = FUN_300e7f1c(DAT_300e864c,__fd,__buf,__nbytes);
  }
  return sVar1;
}

/* ----------------------------------------------------------------
 * write @ 0x300E7FCC  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 14 | Вызывает: 1
 * Вызывает: FUN_300e7f1c
 * Вызывают: ABB_ReadCfg, FUN_3000c000, FUN_300f6ea4, FUN_300fee14, FUN_300fee88, FUN_30112ec0, __swrite, copyStreams, ledBeep, ledNWrite
 *           ...
 * Константы: 0x300E7FCC
 * Данные: DAT_300e8650
 * ---------------------------------------------------------------- */
ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = FUN_300e7f1c(DAT_300e8650,__fd,__buf,__n);
  return sVar1;
}

/* ----------------------------------------------------------------
 * ioctl @ 0x300E7FEC  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 56 | Вызывает: 1
 * Вызывает: iosIoctlInternal
 * Вызывают: BSP_DLOAD_Init, BSP_DLOAD_SendData, FUN_30075e48, FUN_300edf80, FUN_300f74f8, FUN_300f85dc, FUN_3010df20, FUN_3010ef1c, FUN_3010f2f0, FUN_30112ec0
 *           ...
 * Константы: 0x300E7FEC
 * ---------------------------------------------------------------- */
int ioctl(int __fd,ulong __request,...)

{
  int iVar1;
  undefined4 in_r2;
  
  iVar1 = iosIoctlInternal(__fd,__request,in_r2,0);
  return iVar1;
}

/* ----------------------------------------------------------------
 * lseek @ 0x300E801C  (примерный размер ~260 байт)
 * Модуль: data | Вызывают: 10 | Вызывает: 2
 * Вызывает: errnoSet, ioctl
 * Вызывают: ABB_ReadCfg, FUN_3000bf98, FUN_3000c000, __sseek, __swrite, loadModuleInfoInit, loadModuleSeek, partLibCreate, partLibCreateSz, shellInOutRedirectOpen
 * Константы: 0x300E801C
 * ---------------------------------------------------------------- */
__off_t lseek(int __fd,__off_t __offset,int __whence)

{
  int iVar1;
  int iVar2;
  int local_10;
  
  if (__whence == 0) {
    iVar2 = ioctl(__fd,7,__offset);
    if (iVar2 != 0) {
      __offset = -1;
    }
  }
  else {
    if (__whence == 1) {
      iVar2 = ioctl(__fd,8,0);
      if (iVar2 != -1) {
        iVar2 = __offset + iVar2;
        if (-1 < iVar2) {
          iVar1 = ioctl(__fd,7,iVar2);
          if (iVar1 == 0) {
            return iVar2;
          }
          return -1;
        }
        errnoSet(0x16);
      }
    }
    else if (((__whence == 2) && (iVar2 = ioctl(__fd,7,0), iVar2 != -1)) &&
            (iVar2 = ioctl(__fd,1,&local_10), iVar2 != -1)) {
      iVar2 = ioctl(__fd,7,__offset + local_10);
      if (iVar2 == 0) {
        return __offset + local_10;
      }
      return -1;
    }
    __offset = -1;
  }
  return __offset;
}

/* ----------------------------------------------------------------
 * readv @ 0x300E8120  (примерный размер ~212 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: iosRead
 * Константы: 0x300E8120
 * Данные: DAT_300e8640
 * ---------------------------------------------------------------- */
ssize_t readv(int __fd,iovec *__iovec,int __count)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  size_t sVar4;
  ssize_t sVar5;
  undefined4 local_28;
  
  puVar1 = DAT_300e8640;
  if ((code *)*DAT_300e8640 != (code *)0x0) {
    (*(code *)*DAT_300e8640)(0,&local_28);
  }
  sVar5 = 0;
  if (0 < __count) {
    do {
      pvVar3 = __iovec->iov_base;
      for (sVar4 = __iovec->iov_len; 0 < (int)sVar4; sVar4 = sVar4 - iVar2) {
        iVar2 = iosRead(__fd,pvVar3,sVar4);
        if (iVar2 == -1) {
          if (sVar5 == 0) {
            sVar5 = -1;
          }
          goto LAB_300e81c4;
        }
        if (iVar2 == 0) goto LAB_300e81c4;
        sVar5 = sVar5 + iVar2;
        pvVar3 = (void *)((int)pvVar3 + iVar2);
      }
      __iovec = __iovec + 1;
      __count = __count + -1;
    } while (__count != 0);
  }
LAB_300e81c4:
  if ((code *)*puVar1 != (code *)0x0) {
    (*(code *)*puVar1)(local_28,0);
  }
  return sVar5;
}

/* ----------------------------------------------------------------
 * writev @ 0x300E81F4  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: iosWrite
 * Константы: 0x300E81F4
 * Данные: DAT_300e8640
 * ---------------------------------------------------------------- */
ssize_t writev(int __fd,iovec *__iovec,int __count)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  ssize_t sVar4;
  size_t sVar5;
  undefined4 local_28;
  
  puVar1 = DAT_300e8640;
  sVar4 = 0;
  if ((code *)*DAT_300e8640 != (code *)0x0) {
    (*(code *)*DAT_300e8640)(0,&local_28);
  }
  if (0 < __count) {
    do {
      pvVar3 = __iovec->iov_base;
      for (sVar5 = __iovec->iov_len; 0 < (int)sVar5; sVar5 = sVar5 - iVar2) {
        iVar2 = iosWrite(__fd,pvVar3,sVar5);
        if (iVar2 == -1) {
          if (sVar4 == 0) {
            sVar4 = -1;
          }
          goto LAB_300e8290;
        }
        sVar4 = sVar4 + iVar2;
        pvVar3 = (void *)((int)pvVar3 + iVar2);
      }
      __iovec = __iovec + 1;
      __count = __count + -1;
    } while (__count != 0);
  }
LAB_300e8290:
  if ((code *)*puVar1 != (code *)0x0) {
    (*(code *)*puVar1)(local_28,0);
  }
  return sVar4;
}

/* ----------------------------------------------------------------
 * isatty @ 0x300E8478  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 1
 * Вызывает: ioctl
 * Вызывают: __smakebuf, shellExitWrapper, shellInOutInputHookSet, shellInOutInputHookUnset, shellParserControl, shellTask
 * Константы: 0x300E8478
 * ---------------------------------------------------------------- */
int isatty(int __fd)

{
  int iVar1;
  
  iVar1 = ioctl(__fd,0x14,0);
  return (uint)(iVar1 == 1);
}

/* ----------------------------------------------------------------
 * fcntl @ 0x300E8498  (примерный размер ~464 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, ioctl
 * Константы: 0x300E8498
 * Данные: DAT_300e8664
 * ---------------------------------------------------------------- */
int fcntl(int __fd,int __cmd,...)

{
  int iVar1;
  undefined4 *puVar2;
  int in_r2;
  undefined4 uVar3;
  int local_24;
  int local_20;
  int *local_1c;
  
  if (__cmd == 0) {
    if ((code *)*DAT_300e8664 != (code *)0x0) {
      local_24 = in_r2;
      iVar1 = (*(code *)*DAT_300e8664)(__fd);
      return iVar1;
    }
    uVar3 = 0x23;
  }
  else {
    if (__cmd == 1) {
      return 1;
    }
    if (__cmd == 2) {
      if (in_r2 == 0) {
        return 0;
      }
      local_24 = in_r2;
      if (in_r2 == 1) {
        return 0;
      }
    }
    else {
      if (__cmd == 3) {
        local_20 = 3;
        local_1c = &local_24;
        iVar1 = ioctl(__fd,0x3e,&local_20);
        if (iVar1 == -1) {
          return -1;
        }
        return local_24;
      }
      if (__cmd == 4) {
        local_20 = 4;
        local_1c = &local_24;
        local_24 = in_r2;
        iVar1 = ioctl(__fd,0x3e,&local_20);
joined_r0x300e85fc:
        if (iVar1 == -1) {
          return -1;
        }
        return 0;
      }
      if (((__cmd == 7) || (__cmd == 8)) || (__cmd == 9)) {
        local_20 = __cmd;
        local_1c = (int *)in_r2;
        iVar1 = ioctl(__fd,0x3e,&local_20);
        goto joined_r0x300e85fc;
      }
    }
    uVar3 = 0x16;
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = uVar3;
  return -1;
}

/* ----------------------------------------------------------------
 * remove @ 0x300E8668  (примерный размер ~488 байт)
 * Модуль: data | Вызывают: 11 | Вызывает: 12
 * Вызывает: __errno, errnoSet, ioFullFileNameGet, iosDelete, iosDevFind, memPartAlloc, memPartFree, pathCat, pathCondense, strlen, strncmp, strncpy
 * Вызывают: BSP_remove, HI6451_record_startflag_save, TFUP_LogFsInit, TFUP_LogPrintf, dloadRecord, exchFileSave, exchSave, power_off_clearup_flag, rmdir, shellInOutRedirectOpen
 *           ...
 * Константы: 0x300E8668
 * Данные: DAT_300e8b80, DAT_300e8b84, DAT_300e8b88
 * ---------------------------------------------------------------- */
int remove(char *__filename)

{
  int iVar1;
  char *__s;
  size_t __n;
  undefined4 *puVar2;
  int iVar3;
  char *local_24;
  int local_20;
  
  iVar3 = 1;
  if ((__filename == (char *)0x0) || (*__filename == '\0')) {
    errnoSet(2);
    iVar1 = -1;
  }
  else {
    __s = (char *)memPartAlloc(*DAT_300e8b80,0x400);
    if (__s == (char *)0x0) {
      iVar1 = -1;
    }
    else {
      iVar1 = pathCat(*(undefined4 *)(*(int *)(*DAT_300e8b84 + 0x94) + 0xd4),__filename,__s);
      if (iVar1 == -1) {
        memPartFree(*DAT_300e8b80,__s);
        iVar1 = -1;
      }
      else {
        pathCondense(__s);
        __n = strlen(__s);
        iVar1 = strncmp(__s,*(char **)(*(int *)(*DAT_300e8b84 + 0x94) + 0xd4),__n);
        if (iVar1 == 0) {
          memPartFree(*DAT_300e8b80,__s);
          iVar1 = -1;
        }
        else {
          iVar1 = ioFullFileNameGet(__filename,&local_20,__s);
          if (iVar1 == -1) {
            memPartFree(*DAT_300e8b80,__s);
            iVar1 = -1;
          }
          else {
            iVar1 = iosDelete(local_20,__s);
            while (iVar1 == -2) {
              if (*DAT_300e8b88 < iVar3) {
                memPartFree(*DAT_300e8b80,__s);
                puVar2 = (undefined4 *)__errno();
                *puVar2 = 0x40;
                return -1;
              }
              iVar3 = iVar3 + 1;
              iVar1 = iosDevFind(__s,&local_24);
              if (iVar1 == 0) {
                memPartFree(*DAT_300e8b80,__s);
                return -1;
              }
              if (__s != local_24) {
                strncpy(__s,local_24,0x400);
                local_20 = iVar1;
              }
              iVar1 = iosDelete(local_20,__s);
            }
            memPartFree(*DAT_300e8b80,__s);
          }
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * chdir @ 0x300E8994  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 10
 * Вызывает: errnoSet, iosDevFind, iosRtpDefPathSet, memPartAlloc, memPartFree, memcmp, pathCat, pathCondense, strcat, strlen
 * Константы: 0x300E8994, 0xFFFFFFFF
 * Данные: DAT_300e8b80, DAT_300e8b84, DAT_300e8b8c
 * ---------------------------------------------------------------- */
undefined4 chdir(char *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  char *__dest;
  int iVar3;
  size_t sVar4;
  undefined4 uVar5;
  bool bVar6;
  char *pcStack_18;
  
  puVar1 = DAT_300e8b80;
  bVar6 = param_1 == (char *)0x0;
  if (!bVar6) {
    bVar6 = *param_1 == '\0';
  }
  if (bVar6) {
    return 0;
  }
  __dest = (char *)memPartAlloc(*DAT_300e8b80,0x400);
  piVar2 = DAT_300e8b84;
  if (__dest != (char *)0x0) {
    iVar3 = pathCat(*(undefined4 *)(*(int *)(*DAT_300e8b84 + 0x94) + 0xd4),param_1,__dest);
    if (iVar3 != -1) {
      pathCondense(__dest);
      sVar4 = strlen(param_1);
      if ((param_1[sVar4 - 1] == '/') && (iVar3 = memcmp(__dest,DAT_300e8b8c,2), iVar3 != 0)) {
        strcat(__dest,DAT_300e8b8c);
      }
      iosDevFind(__dest,&pcStack_18);
      if (pcStack_18 != __dest) {
LAB_300e894c:
        uVar5 = iosRtpDefPathSet(*(undefined4 *)(*piVar2 + 0x94),__dest);
        memPartFree(*puVar1,__dest);
        return uVar5;
      }
      sVar4 = strlen(param_1);
      if (param_1[sVar4 - 1] == '.') {
        strcat(__dest,DAT_300e8b8c);
        iosDevFind(__dest,&pcStack_18);
        if (pcStack_18 != __dest) goto LAB_300e894c;
      }
      errnoSet(0x13);
    }
    memPartFree(*puVar1,__dest);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * getcwd @ 0x300E8998  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: errnoSet, strcpy, strlen
 * Константы: 0x300E8998
 * Данные: DAT_300e8b84
 * ---------------------------------------------------------------- */
char * getcwd(char *__buf,size_t __size)

{
  size_t sVar1;
  char *__s;
  
  if ((__buf != (char *)0x0) && (__size != 0)) {
    __s = *(char **)(*(int *)(*DAT_300e8b84 + 0x94) + 0xd4);
    sVar1 = strlen(__s);
    if (__size < sVar1 + 1) {
      errnoSet(0x26);
      return (char *)0x0;
    }
    strcpy(__buf,__s);
    return __buf;
  }
  errnoSet(0x16);
  return (char *)0x0;
}

/* ----------------------------------------------------------------
 * getwd @ 0x300E8A0C  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: strcpy
 * Константы: 0x300E8A0C
 * Данные: DAT_300e8b84
 * ---------------------------------------------------------------- */
char * getwd(char *__buf)

{
  strcpy(__buf,*(char **)(*(int *)(*DAT_300e8b84 + 0x94) + 0xd4));
  return __buf;
}

/* ----------------------------------------------------------------
 * fcntl_dup @ 0x300E8B94  (примерный размер ~248 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: __errno, close, dup, free, iosRtpIoTableSizeGet, malloc
 * Константы: 0xFFFFFFFF, 0x300E8B94
 * Данные: DAT_300e8d98
 * ---------------------------------------------------------------- */
undefined4 fcntl_dup(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  void *__ptr;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar1 = iosRtpIoTableSizeGet(*DAT_300e8d98);
  if ((param_2 < 0) || (iVar1 <= param_2)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x16;
    return 0xffffffff;
  }
  __ptr = malloc(iVar1 << 2);
  if (__ptr == (void *)0x0) {
    return 0xffffffff;
  }
  iVar6 = iVar1;
  if (0 < iVar1) {
    piVar5 = (int *)((int)__ptr + -4);
    iVar3 = 0;
    do {
      iVar6 = iVar3;
      iVar3 = dup(param_1);
      piVar5 = piVar5 + 1;
      *piVar5 = iVar3;
      if (param_2 <= iVar3) break;
      iVar3 = iVar6 + 1;
      iVar6 = iVar1;
    } while (iVar3 < iVar1);
  }
  if (0 < iVar6) {
    piVar5 = (int *)((int)__ptr + -4);
    iVar3 = iVar6;
    do {
      piVar5 = piVar5 + 1;
      iVar4 = close(*piVar5);
      if (0 < iVar4) {
        close(*piVar5);
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (iVar6 < iVar1) {
    uVar7 = *(undefined4 *)((int)__ptr + iVar6 * 4);
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x18;
    uVar7 = 0xffffffff;
  }
  free(__ptr);
  return uVar7;
}

/* ----------------------------------------------------------------
 * dup @ 0x300EA84C  (примерный размер ~180 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: __errno, iosFdMap, iosFdTableLock, iosFdTableUnlock, iosRtpFdEntryMap, iosRtpFdReserve
 * Вызывают: fcntl_dup
 * Константы: 0x300EA84C, 0xFFEFFFFF
 * Данные: DAT_300eab2c
 * ---------------------------------------------------------------- */
int dup(int __fd)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = *(undefined4 *)(*DAT_300eab2c + 0x94);
  iosFdTableLock(uVar3);
  iVar1 = iosFdMap(__fd);
  if (iVar1 == 0) {
    iVar4 = -1;
  }
  else if (*(int *)(iVar1 + 0x4c) < 1) {
    iVar4 = -1;
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 9;
  }
  else {
    iVar4 = iosRtpFdReserve(*(undefined4 *)(*DAT_300eab2c + 0x94));
    if (iVar4 == -1) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 0x18;
    }
    else {
      iosRtpFdEntryMap(*(undefined4 *)(*DAT_300eab2c + 0x94),iVar4,iVar1);
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) & 0xffefffff;
    }
  }
  iosFdTableUnlock(uVar3);
  return iVar4;
}

/* ----------------------------------------------------------------
 * dup2 @ 0x300EA900  (примерный размер ~276 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: __errno, iosFdMap, iosFdTableLock, iosFdTableUnlock, iosRtpFdEntryMap, iosRtpFdUnmap2
 * Константы: 0x300EA900, 0xFFEFFFFF
 * Данные: DAT_300eab2c
 * ---------------------------------------------------------------- */
int dup2(int __fd,int __fd2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = *(int *)(*DAT_300eab2c + 0x94);
  iosFdTableLock(iVar5);
  if ((-1 < __fd2) && ((uint)__fd2 < *(uint *)(iVar5 + 0xd0))) {
    iVar4 = *(int *)(*(int *)(iVar5 + 0xcc) + __fd2 * 4);
    if (iVar4 != 0) {
      if (iVar4 == -1) {
        iVar3 = 0x10;
        goto LAB_300ea9f0;
      }
      if ((iVar4 == -2) || ((*(uint *)(iVar4 + 0x50) & 0x40000) != 0)) goto LAB_300ea98c;
    }
    iVar1 = iosFdMap(__fd);
    if ((iVar1 != 0) && (0 < *(int *)(iVar1 + 0x4c))) {
      if (__fd != __fd2) {
        if (iVar4 != 0) {
          iosFdTableUnlock(iVar5);
          iosRtpFdUnmap2(iVar5,__fd2,0);
          iosFdTableLock(iVar5);
        }
        iVar4 = iosRtpFdEntryMap(iVar5,__fd2,iVar1);
        if (iVar4 == 0) {
          *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) & 0xffefffff;
        }
        else {
          piVar2 = (int *)__errno();
          iVar3 = *piVar2;
        }
      }
      goto LAB_300ea9f0;
    }
  }
LAB_300ea98c:
  iVar3 = 9;
LAB_300ea9f0:
  iosFdTableUnlock(iVar5);
  if (iVar3 != 0) {
    piVar2 = (int *)__errno();
    *piVar2 = iVar3;
    __fd2 = -1;
  }
  return __fd2;
}

/* ----------------------------------------------------------------
 * unmount @ 0x300EB118  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 7
 * Вызывает: errnoSet, iosDevCheck, iosDevDelete, iosDevFind, iosDrvIoctl, iosLock, iosUnlock
 * Константы: 0xFFFFFFFF, 0x300EB118
 * ---------------------------------------------------------------- */
undefined4 unmount(undefined4 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = iosDevFind(param_1,0);
  if (iVar2 == 0) {
    errnoSet(0x23);
    return 0xffffffff;
  }
  iosLock();
  if ((param_2 == 0) && (iVar3 = iosDevCheck(iVar2), iVar3 == -1)) {
    iosUnlock();
    errnoSet(0x10);
    return 0xffffffff;
  }
  sVar1 = *(short *)(iVar2 + 8);
  iosDevDelete(iVar2);
  iosUnlock();
  uVar4 = iosDrvIoctl((int)sVar1,0x27,iVar2);
  return uVar4;
}

/* ----------------------------------------------------------------
 * FUN_300eb198 @ 0x300EB198  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: iosRtpDevCloseOrInvalidate
 * Константы: 0x300EB198
 * Данные: DAT_300ebb64
 * ---------------------------------------------------------------- */
undefined4 FUN_300eb198(undefined4 param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 1;
  local_c = param_1;
  iosRtpDevCloseOrInvalidate(*DAT_300ebb64,&local_c);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300eb1c8 @ 0x300EB1C8  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 3
 * Вызывает: __errno, iosLock, iosUnlock
 * Вызывают: FUN_300eb3c4, FUN_300eb4c4, FUN_300eb5e0, FUN_300eb680, FUN_300eb70c, FUN_300eb798, FUN_300eb824, FUN_300eb8b0
 * Константы: 0x300EB1C8, 0xFFFFFFFF
 * Данные: DAT_300ebb68
 * ---------------------------------------------------------------- */
undefined4 FUN_300eb1c8(int param_1)

{
  undefined4 *puVar1;
  
  iosLock();
  if (*(int *)(param_1 + 0x18) != DAT_300ebb68) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    iosUnlock();
    return 0;
  }
  iosUnlock();
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 6;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300eb214 @ 0x300EB214  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 2
 * Вызывает: iosLock, iosUnlock
 * Вызывают: FUN_300eb3c4, FUN_300eb4c4, FUN_300eb5e0, FUN_300eb680, FUN_300eb70c, FUN_300eb798, FUN_300eb824, FUN_300eb8b0
 * Константы: 0x300EB214, 0xFFFFFFFE
 * Данные: DAT_300ebb68
 * ---------------------------------------------------------------- */
void FUN_300eb214(int param_1)

{
  int iVar1;
  
  iosLock();
  if (((*(int *)(param_1 + 0x10) < 1) ||
      (iVar1 = *(int *)(param_1 + 0x10) + -1, *(int *)(param_1 + 0x10) = iVar1, iVar1 < 1)) &&
     (*(int *)(param_1 + 0x18) == DAT_300ebb68)) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
    iosUnlock();
    if (*(code **)(param_1 + 0x1c) == (code *)0x0) {
      return;
    }
    (**(code **)(param_1 + 0x1c))(param_1);
    return;
  }
  iosUnlock();
  return;
}

/* ----------------------------------------------------------------
 * FUN_300eb28c @ 0x300EB28C  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 6
 * Вызывает: __errno, iosDevFind, strcmp, strncpy, sysClkRateGet, taskDelay
 * Вызывают: FUN_300eb378, FUN_300eb470, FUN_300eb57c, FUN_300eb92c, FUN_300eb994, FUN_300eb9fc, FUN_300eba64, FUN_300ebb08
 * Константы: 0xFFFFFFFF, 0x300EB28C
 * Данные: DAT_300ebaf4
 * ---------------------------------------------------------------- */
undefined4 FUN_300eb28c(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  char acStack_118 [256];
  
  uVar1 = sysClkRateGet();
  if (*(char **)(param_1 + 0xc) == (char *)0x0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 6;
    uVar1 = 0xffffffff;
  }
  else {
    strncpy(acStack_118,*(char **)(param_1 + 0xc),0x100);
    iVar3 = iosDevFind(acStack_118,0);
    *param_2 = iVar3;
    iVar4 = DAT_300ebaf4;
    while ((iVar3 == param_1 && (*(int *)(param_1 + 0x18) == iVar4))) {
      param_3 = param_3 + 1;
      if (0x3b < param_3) goto LAB_300eb354;
      taskDelay(uVar1);
      iVar3 = iosDevFind(acStack_118,0);
      *param_2 = iVar3;
    }
    if (((param_3 < 0x3c) && (*param_2 != 0)) &&
       (iVar4 = strcmp(acStack_118,*(char **)(*param_2 + 0xc)), iVar4 == 0)) {
      uVar1 = 0;
    }
    else {
LAB_300eb354:
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 6;
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300eb378 @ 0x300EB378  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300eb28c
 * Вызывают: FUN_300eb3c4
 * Константы: 0x300EB378, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300eb378(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  
  iVar1 = FUN_300eb28c(param_1,&local_14,0);
  if (iVar1 == 0) {
    uVar2 = (*(code *)**(undefined4 **)(local_14 + 0x18))(local_14,param_2,param_3);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300eb3c4 @ 0x300EB3C4  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300eb1c8, FUN_300eb214, FUN_300eb378, __errno, iosDevSuspend
 * Константы: 0x300EB3C4
 * Данные: DAT_300ebb00, DAT_300ebb6c
 * ---------------------------------------------------------------- */
int FUN_300eb3c4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_300eb1c8();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*DAT_300ebb00 + *(short *)(param_1 + 8) * 0x24))(param_1,param_2,param_3);
    FUN_300eb214(param_1);
    if ((iVar1 == -1) && (piVar2 = (int *)__errno(), *piVar2 == DAT_300ebb6c)) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0;
      iosDevSuspend(param_1);
      iVar1 = FUN_300eb378(param_1,param_2,param_3);
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300eb470 @ 0x300EB470  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300eb28c
 * Вызывают: FUN_300eb4c4
 * Константы: 0x300EB470, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300eb470(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  
  iVar1 = FUN_300eb28c(param_1,&local_18,0);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*(int *)(local_18 + 0x18) + 8))(local_18,param_2,param_3,param_4);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300eb4c4 @ 0x300EB4C4  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300eb1c8, FUN_300eb214, FUN_300eb470, __errno, iosDevSuspend
 * Константы: 0x300EB4C4
 * Данные: DAT_300ebb00, DAT_300ebb6c
 * ---------------------------------------------------------------- */
int FUN_300eb4c4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_300eb1c8();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(short *)(param_1 + 8) * 0x24 + *DAT_300ebb00 + 8))
                      (param_1,param_2,param_3,param_4);
    FUN_300eb214(param_1);
    if ((iVar1 == -1) && (piVar2 = (int *)__errno(), *piVar2 == DAT_300ebb6c)) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0;
      iosDevSuspend(param_1);
      iVar1 = FUN_300eb470(param_1,param_2,param_3,param_4);
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300eb57c @ 0x300EB57C  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300eb28c, __errno
 * Вызывают: FUN_300eb5e0
 * Константы: 0x300EB57C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300eb57c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int local_14;
  
  iVar1 = FUN_300eb28c(param_1,&local_14,0);
  if (iVar1 == 0) {
    if (param_1 == local_14) {
      uVar2 = (**(code **)(*(int *)(local_14 + 0x18) + 4))(local_14,param_2);
      return uVar2;
    }
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 6;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300eb5e0 @ 0x300EB5E0  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300eb1c8, FUN_300eb214, FUN_300eb57c, __errno, iosDevSuspend
 * Константы: 0x300EB5E0
 * Данные: DAT_300ebb00, DAT_300ebb6c
 * ---------------------------------------------------------------- */
int FUN_300eb5e0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_300eb1c8();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(short *)(param_1 + 8) * 0x24 + *DAT_300ebb00 + 4))(param_1,param_2);
    FUN_300eb214(param_1);
    if ((iVar1 == -1) && (piVar2 = (int *)__errno(), *piVar2 == DAT_300ebb6c)) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0;
      iosDevSuspend(param_1);
      iVar1 = FUN_300eb57c(param_1,param_2);
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300eb680 @ 0x300EB680  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300eb1c8, FUN_300eb214, __errno, iosDevSuspend
 * Константы: 0x300EB680
 * Данные: DAT_300ebb6c
 * ---------------------------------------------------------------- */
int FUN_300eb680(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_300eb1c8(*(undefined4 *)(param_1 + 0x40));
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x58) + 0x10))
                      (*(undefined4 *)(param_1 + 0x48),param_2,param_3);
    FUN_300eb214(*(undefined4 *)(param_1 + 0x40));
    if ((iVar1 == -1) && (piVar2 = (int *)__errno(), *piVar2 == DAT_300ebb6c)) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0xb;
      iosDevSuspend(*(undefined4 *)(param_1 + 0x40));
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300eb70c @ 0x300EB70C  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300eb1c8, FUN_300eb214, __errno, iosDevSuspend
 * Константы: 0x300EB70C
 * Данные: DAT_300ebb6c
 * ---------------------------------------------------------------- */
int FUN_300eb70c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_300eb1c8(*(undefined4 *)(param_1 + 0x40));
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x58) + 0x14))
                      (*(undefined4 *)(param_1 + 0x48),param_2,param_3);
    FUN_300eb214(*(undefined4 *)(param_1 + 0x40));
    if ((iVar1 == -1) && (piVar2 = (int *)__errno(), *piVar2 == DAT_300ebb6c)) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0xb;
      iosDevSuspend(*(undefined4 *)(param_1 + 0x40));
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300eb798 @ 0x300EB798  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300eb1c8, FUN_300eb214, __errno, iosDevSuspend
 * Константы: 0x300EB798
 * Данные: DAT_300ebb6c
 * ---------------------------------------------------------------- */
int FUN_300eb798(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_300eb1c8(*(undefined4 *)(param_1 + 0x40));
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x58) + 0x18))
                      (*(undefined4 *)(param_1 + 0x48),param_2,param_3);
    FUN_300eb214(*(undefined4 *)(param_1 + 0x40));
    if ((iVar1 == -1) && (piVar2 = (int *)__errno(), *piVar2 == DAT_300ebb6c)) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0xb;
      iosDevSuspend(*(undefined4 *)(param_1 + 0x40));
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300eb824 @ 0x300EB824  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300eb1c8, FUN_300eb214, __errno, iosDevSuspend
 * Константы: 0x300EB824
 * Данные: DAT_300ebb6c
 * ---------------------------------------------------------------- */
int FUN_300eb824(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_300eb1c8(*(undefined4 *)(param_1 + 0x40));
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x58) + 0x1c))
                      (*(undefined4 *)(param_1 + 0x48),param_2,param_3);
    FUN_300eb214(*(undefined4 *)(param_1 + 0x40));
    if ((iVar1 == -1) && (piVar2 = (int *)__errno(), *piVar2 == DAT_300ebb6c)) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0xb;
      iosDevSuspend(*(undefined4 *)(param_1 + 0x40));
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300eb8b0 @ 0x300EB8B0  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300eb1c8, FUN_300eb214, __errno, iosDevSuspend
 * Константы: 0x300EB8B0
 * Данные: DAT_300ebb6c
 * ---------------------------------------------------------------- */
int FUN_300eb8b0(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_300eb1c8(*(undefined4 *)(param_1 + 0x40));
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x58) + 0xc))(*(undefined4 *)(param_1 + 0x48));
    FUN_300eb214(*(undefined4 *)(param_1 + 0x40));
    if ((iVar1 == -1) && (piVar2 = (int *)__errno(), *piVar2 == DAT_300ebb6c)) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0xb;
      iosDevSuspend(*(undefined4 *)(param_1 + 0x40));
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300eb92c @ 0x300EB92C  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300eb28c
 * Константы: 0x300EB92C, 0xFFFFFFFF
 * Данные: DAT_300ebb00
 * ---------------------------------------------------------------- */
undefined4 FUN_300eb92c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  
  iVar1 = FUN_300eb28c(*(undefined4 *)(param_1 + 0x40),&local_14,0);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*(short *)(local_14 + 8) * 0x24 + *DAT_300ebb00 + 0x10))
                      (*(undefined4 *)(param_1 + 0x48),param_2,param_3);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300eb994 @ 0x300EB994  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300eb28c
 * Константы: 0x300EB994, 0xFFFFFFFF
 * Данные: DAT_300ebb00
 * ---------------------------------------------------------------- */
undefined4 FUN_300eb994(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  
  iVar1 = FUN_300eb28c(*(undefined4 *)(param_1 + 0x40),&local_14,0);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*(short *)(local_14 + 8) * 0x24 + *DAT_300ebb00 + 0x14))
                      (*(undefined4 *)(param_1 + 0x48),param_2,param_3);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300eb9fc @ 0x300EB9FC  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300eb28c
 * Константы: 0x300EB9FC, 0xFFFFFFFF
 * Данные: DAT_300ebb00
 * ---------------------------------------------------------------- */
undefined4 FUN_300eb9fc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  
  iVar1 = FUN_300eb28c(*(undefined4 *)(param_1 + 0x40),&local_14,0);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*(short *)(local_14 + 8) * 0x24 + *DAT_300ebb00 + 0x18))
                      (*(undefined4 *)(param_1 + 0x48),param_2,param_3);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300eba64 @ 0x300EBA64  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300eb28c
 * Константы: 0x300EBA64, 0xFFFFFFFF
 * Данные: DAT_300ebb00
 * ---------------------------------------------------------------- */
undefined4 FUN_300eba64(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  
  iVar1 = FUN_300eb28c(*(undefined4 *)(param_1 + 0x40),&local_14,0);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*(short *)(local_14 + 8) * 0x24 + *DAT_300ebb00 + 0x1c))
                      (*(undefined4 *)(param_1 + 0x48),param_2,param_3);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300ebb08 @ 0x300EBB08  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300eb28c
 * Константы: 0x300EBB08, 0xFFFFFFFF
 * Данные: DAT_300ebb70
 * ---------------------------------------------------------------- */
undefined4 FUN_300ebb08(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  iVar1 = FUN_300eb28c(*(undefined4 *)(param_1 + 0x40),&local_c,0);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*(short *)(local_c + 8) * 0x24 + *DAT_300ebb70 + 0xc))
                      (*(undefined4 *)(param_1 + 0x48));
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * pathParse @ 0x300EC4E4  (примерный размер ~252 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: bcopy
 * Константы: 0x300EC4E4
 * Данные: DAT_300ec938
 * ---------------------------------------------------------------- */
void pathParse(char *param_1,undefined4 *param_2,undefined1 *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  size_t __n;
  char *pcVar5;
  undefined1 *puVar6;
  
  iVar3 = 0;
  puVar4 = param_3;
  pcVar5 = param_1;
  if (*param_1 != '\0') {
    do {
      cVar1 = *pcVar5;
      while (((cVar1 != '/' && (*pcVar5 != '\\')) && (*pcVar5 != '\0'))) {
        pcVar5 = pcVar5 + 1;
        cVar1 = *pcVar5;
      }
      if (param_1 == pcVar5) {
        param_1 = param_1 + 1;
        pcVar5 = pcVar5 + 1;
      }
      else {
        __n = (int)pcVar5 - (int)param_1;
        bcopy(param_1,puVar4,__n);
        puVar4[__n] = 0;
        param_2[iVar3] = puVar4;
        puVar4 = puVar4 + __n + 1;
        param_1 = pcVar5;
        if (*pcVar5 == '/' || *pcVar5 == '\\') {
          param_1 = pcVar5 + 1;
        }
        iVar3 = iVar3 + 1;
        pcVar5 = param_1;
      }
    } while (*param_1 != '\0');
    if (iVar3 != 0) goto LAB_300ec5d0;
  }
  iVar2 = 2;
  puVar4 = DAT_300ec938;
  puVar6 = param_3;
  do {
    iVar2 = iVar2 + -1;
    *puVar6 = *puVar4;
    puVar6 = puVar6 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar2 != 0);
  *param_2 = param_3;
  iVar3 = iVar3 + 1;
LAB_300ec5d0:
  param_2[iVar3] = 0;
  return;
}

/* ----------------------------------------------------------------
 * pathCondense @ 0x300EC5E0  (примерный размер ~324 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: iosDevFind
 * Вызывают: chdir, ioDefPathCat, remove, rm
 * Константы: 0x300EC5E0
 * ---------------------------------------------------------------- */
void pathCondense(char *param_1)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  char *pcVar4;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *local_10;
  char *pcVar5;
  
  iosDevFind(param_1,&local_10);
  if (*param_1 == '/') {
    local_10 = param_1;
  }
  if (*local_10 == '/' || *local_10 == '\\') {
    *local_10 = '/';
    local_10 = local_10 + 1;
  }
  bVar3 = true;
  pcVar4 = local_10;
  pcVar7 = local_10;
  pcVar6 = local_10;
LAB_300ec708:
  while( true ) {
    pcVar5 = pcVar4;
    pcVar4 = pcVar5 + 1;
    cVar2 = *pcVar5;
    if (cVar2 == '\0') {
      *pcVar6 = '\0';
      return;
    }
    if ((cVar2 != '/') && (cVar2 != '\\')) break;
    bVar3 = true;
  }
  pcVar8 = pcVar6;
  if (bVar3) {
    if (cVar2 == '.') goto code_r0x300ec664;
    goto LAB_300ec6f0;
  }
  goto LAB_300ec704;
code_r0x300ec664:
  cVar1 = *pcVar4;
  if (((cVar1 != '\0') && (cVar1 != '/')) && (cVar1 != '\\')) {
    if ((cVar1 == '.') &&
       (((cVar1 = pcVar5[2], cVar1 == '\0' || (cVar1 == '/')) || (cVar1 == '\\')))) {
      pcVar4 = pcVar5 + 2;
      if (pcVar7 < pcVar6) {
        do {
          pcVar6 = pcVar6 + -1;
          if (pcVar6 <= pcVar7) break;
        } while (*pcVar6 != '/');
      }
      else {
        if (local_10 < pcVar6) {
          *pcVar6 = '/';
          pcVar6 = pcVar6 + 1;
        }
        *pcVar6 = '.';
        pcVar7 = pcVar6 + 2;
        pcVar6[1] = '.';
        pcVar6 = pcVar7;
      }
    }
    else {
LAB_300ec6f0:
      if (local_10 < pcVar6) {
        *pcVar6 = '/';
        pcVar6 = pcVar6 + 1;
      }
      bVar3 = false;
      pcVar8 = pcVar6;
LAB_300ec704:
      pcVar6 = pcVar8 + 1;
      *pcVar8 = cVar2;
    }
  }
  goto LAB_300ec708;
}

/* ----------------------------------------------------------------
 * pathBuild @ 0x300EC724  (примерный размер ~272 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: errnoSet, strcat, strlen
 * Константы: 0xFFFFFFFF, 0x300EC724
 * Данные: DAT_300ec93c
 * ---------------------------------------------------------------- */
undefined4 pathBuild(undefined4 *param_1,undefined4 *param_2,char *param_3)

{
  bool bVar1;
  size_t sVar2;
  size_t sVar3;
  char *__s;
  
  sVar2 = strlen(param_3);
  bVar1 = false;
  if (0x3ff < (int)sVar2) {
    errnoSet(0x1a);
    return 0xffffffff;
  }
  if (((0 < (int)sVar2) && (param_3[sVar2 - 1] != '/')) && (param_3[sVar2 - 1] != '\\')) {
    param_3[sVar2] = '/';
    (param_3 + sVar2)[1] = '\0';
    bVar1 = true;
  }
  if (param_1 != (undefined4 *)0x0) {
    do {
      __s = (char *)*param_1;
      if ((__s == (char *)0x0) || (param_1 == param_2)) break;
      if (*__s != '\0') {
        sVar3 = strlen(__s);
        sVar2 = sVar3 + sVar2 + 1;
        if (0x400 < (int)sVar2) {
          errnoSet(0x1a);
          return 0xffffffff;
        }
        strcat(param_3,__s);
        strcat(param_3,DAT_300ec93c);
        bVar1 = true;
      }
      param_1 = param_1 + 1;
    } while (param_1 != (undefined4 *)0x0);
  }
  if (bVar1) {
    sVar2 = strlen(param_3);
    param_3[sVar2 - 1] = '\0';
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ec834 @ 0x300EC834  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: rindex
 * Вызывают: pathLastNamePtr, pathSplit
 * Константы: 0x300EC834
 * ---------------------------------------------------------------- */
char * FUN_300ec834(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = rindex(param_1,0x2f);
  pcVar2 = rindex(param_1,0x5c);
  if (pcVar2 <= pcVar1) {
    pcVar2 = pcVar1;
  }
  return pcVar2;
}

/* ----------------------------------------------------------------
 * pathLastNamePtr @ 0x300EC870  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: FUN_300ec834
 * Вызывают: moduleFindByName, moduleIdFigure, moduleInfoGet, moduleNameGet, pathLastName
 * Константы: 0x300EC870
 * ---------------------------------------------------------------- */
int pathLastNamePtr(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_300ec834();
  if (iVar1 == 0) {
    return param_1;
  }
  return iVar1 + 1;
}

/* ----------------------------------------------------------------
 * pathLastName @ 0x300EC898  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: pathLastNamePtr
 * Константы: 0x300EC898
 * ---------------------------------------------------------------- */
void pathLastName(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = pathLastNamePtr();
  *param_2 = uVar1;
  return;
}

/* ----------------------------------------------------------------
 * pathSplit @ 0x300EC8AC  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300ec834, strcpy, strncpy
 * Вызывают: moduleInit
 * Константы: 0x300EC8AC
 * Данные: DAT_300ec940
 * ---------------------------------------------------------------- */
void pathSplit(char *param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  
  pcVar1 = DAT_300ec940;
  if (param_1 == (char *)0x0) {
    *param_3 = *DAT_300ec940;
    cVar3 = *pcVar1;
  }
  else {
    iVar2 = FUN_300ec834(param_1);
    if (iVar2 != 0) {
      strncpy(param_2,param_1,iVar2 - (int)param_1);
      param_2[iVar2 - (int)param_1] = '\0';
      strcpy(param_3,(char *)(iVar2 + 1));
      return;
    }
    strcpy(param_3,param_1);
    cVar3 = *DAT_300ec940;
  }
  *param_2 = cVar3;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ec944 @ 0x300EC944  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: __errno, bcopy, strlen
 * Вызывают: pathCat
 * Константы: 0x300EC944
 * ---------------------------------------------------------------- */
char * FUN_300ec944(char *param_1,char *param_2,int param_3)

{
  size_t sVar1;
  size_t __n;
  undefined4 *puVar2;
  
  sVar1 = strlen(param_1);
  __n = strlen(param_2);
  if ((int)(sVar1 + __n) < param_3) {
    bcopy(param_2,param_1 + sVar1,__n);
    param_1[__n + sVar1] = '\0';
    return param_1;
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = 0x1a;
  return (char *)0x0;
}

/* ----------------------------------------------------------------
 * pathCat @ 0x300EC9B0  (примерный размер ~376 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 7
 * Вызывает: FUN_300ec944, __errno, index, iosDevFind, strcpy, strlen, strncat
 * Вызывают: chdir, ioDefPathCat, ioFullFileNameGet, remove, rm
 * Константы: 0xFFFFFFFF, 0x300EC9B0
 * Данные: DAT_300ecb20, DAT_300ecb24
 * ---------------------------------------------------------------- */
undefined4 pathCat(byte *param_1,byte *param_2,char *param_3)

{
  size_t sVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int iVar4;
  byte *local_18;
  
  if ((param_2 == (byte *)0x0) || (*param_2 == 0)) {
    strcpy(param_3,(char *)param_1);
  }
  else {
    sVar1 = strlen((char *)param_2);
    if (0x3ff < sVar1) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 0x1a;
      return 0xffffffff;
    }
    if (((param_1 == (byte *)0x0) || (*param_1 == 0)) ||
       (iosDevFind(param_2,&local_18), local_18 != param_2)) {
      strcpy(param_3,(char *)param_2);
    }
    else {
      *param_3 = '\0';
      if ((*param_1 != 0x2f) && (iosDevFind(param_1,&local_18), local_18 != param_1)) {
        strncat(param_3,(char *)param_1,(int)local_18 - (int)param_1);
        param_1 = local_18;
      }
      pcVar3 = index(DAT_300ecb20,(uint)*param_2);
      if ((pcVar3 == (char *)0x0) && (*param_1 != 0)) {
        iVar4 = FUN_300ec944(param_3,param_1,0x400);
        if (iVar4 == 0) {
          return 0xffffffff;
        }
        sVar1 = strlen((char *)param_1);
        if ((param_1[sVar1 - 1] != 0x2f) &&
           (iVar4 = FUN_300ec944(param_3,DAT_300ecb24,0x400), iVar4 == 0)) {
          return 0xffffffff;
        }
      }
      iVar4 = FUN_300ec944(param_3,param_2,0x400);
      if (iVar4 == 0) {
        return 0xffffffff;
      }
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ptyDrv @ 0x300ED340  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: iosDrvInstall
 * Вызывают: FUN_30101f90, shellInOutBlockingOpen, usrIosExtraInit
 * Константы: 0x300ED340
 * Данные: DAT_300edcb4, DAT_300edcb8, DAT_300edcbc, DAT_300edcc0, DAT_300edcc4, DAT_300edcc8, DAT_300edccc, DAT_300edcd0
 * ---------------------------------------------------------------- */
int ptyDrv(void)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  
  piVar1 = DAT_300edcb4;
  if (DAT_300edcb4[3] == 0) {
    DAT_300edcb4[3] = 1;
    iVar2 = iosDrvInstall(DAT_300edcbc,0,DAT_300edcbc,DAT_300edcc8,DAT_300edcb8,DAT_300edcc0,
                          DAT_300edcc4);
    *piVar1 = iVar2;
    iVar2 = iosDrvInstall(DAT_300edcd0,0,DAT_300edcd0,DAT_300edcdc,DAT_300edccc,DAT_300edcd4,
                          DAT_300edcd8);
    piVar1[1] = iVar2;
    bVar3 = *piVar1 == -1;
    if ((!bVar3) && (bVar3 = iVar2 == -1, !bVar3)) {
      iVar2 = 0;
    }
    if (bVar3) {
      iVar2 = -1;
    }
    piVar1[2] = iVar2;
  }
  return piVar1[2];
}

/* ----------------------------------------------------------------
 * ptyDevCreate @ 0x300ED400  (примерный размер ~356 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 11
 * Вызывает: errnoSet, free, iosDevAdd, iosDevDelete, malloc, semBInit, semTerminate, strcat, strcpy, tyDevInit, tyDevTerminate
 * Вызывают: FUN_30101f90
 * Константы: 0x300ED400, 0xFFFFFFFF
 * Данные: DAT_300edcb4, DAT_300edce0, DAT_300edce4, DAT_300edce8, DAT_300edcec, DAT_300edcf0
 * ---------------------------------------------------------------- */
undefined4 ptyDevCreate(char *param_1,undefined4 param_2,undefined4 param_3)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  int iStack_4;
  
  iVar2 = -DAT_300edce0;
  *(int **)((int)&iStack_4 + iVar2) = DAT_300edcb4;
  if ((*DAT_300edcb4 < 1) || (DAT_300edcb4[1] < 1)) {
    errnoSet(6);
  }
  else {
    __ptr = malloc(0x390);
    if (__ptr != (void *)0x0) {
      *(undefined1 *)((int)__ptr + 0x2fc) = 0;
      *(undefined1 *)((int)__ptr + 0x2fd) = 0;
      *(undefined1 *)((int)__ptr + 0x2fe) = 0;
      *(undefined1 *)((int)__ptr + 0x2ff) = 0;
      iVar1 = tyDevInit(__ptr,param_2,param_3,DAT_300edce4);
      if (iVar1 == 0) {
        if ((code *)*DAT_300edce8 != (code *)0x0) {
          (*(code *)*DAT_300edce8)((int)__ptr + 0x300);
        }
        semBInit((int)__ptr + 0x294,1,0);
        strcpy(&stack0x00000000 + iVar2,param_1);
        strcat(&stack0x00000000 + iVar2,DAT_300edcec);
        iVar1 = iosDevAdd((int)__ptr + 0x270,(int)&stack0x00000000 + iVar2,
                          **(undefined4 **)((int)&iStack_4 + iVar2));
        if (iVar1 == 0) {
          *(undefined4 *)((int)__ptr + 0x290) = 0;
          strcpy(&stack0x00000000 + iVar2,param_1);
          strcat(&stack0x00000000 + iVar2,DAT_300edcf0);
          iVar2 = iosDevAdd(__ptr,(int)&stack0x00000000 + iVar2,
                            *(undefined4 *)(*(int *)((int)&iStack_4 + iVar2) + 4));
          if (iVar2 == 0) {
            return 0;
          }
          iosDevDelete((int)__ptr + 0x270);
        }
        tyDevTerminate(__ptr);
        semTerminate((int)__ptr + 0x294);
      }
      free(__ptr);
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * ptyDevRemove @ 0x300ED564  (примерный размер ~296 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 8
 * Вызывает: errnoSet, free, iosDevDelete, iosDevFind, semTerminate, strcat, strcpy, tyDevTerminate
 * Вызывают: FUN_30101f90, shellInOutBgndIoClose, shellInOutBlockingClose, shellInOutBlockingOpen
 * Константы: 0xFFFFFFFF, 0x300ED564
 * Данные: DAT_300edcb4, DAT_300edcec, DAT_300edcf0, DAT_300edcf4, DAT_300edcf8
 * ---------------------------------------------------------------- */
undefined4 ptyDevRemove(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *__ptr;
  int iVar3;
  bool bVar4;
  
  iVar1 = -DAT_300edcf4;
  *(undefined4 *)(&stack0x00000004 + iVar1) = 0;
  *(int **)(&stack0x00000008 + iVar1) = DAT_300edcb4;
  if ((*DAT_300edcb4 < 1) || (DAT_300edcb4[1] < 1)) {
    errnoSet(6);
    uVar2 = 0xffffffff;
  }
  else {
    strcpy(&stack0x0000000c + iVar1,param_1);
    strcat(&stack0x0000000c + iVar1,DAT_300edcf0);
    __ptr = (void *)iosDevFind(&stack0x0000000c + iVar1,&stack0x00000004 + iVar1);
    bVar4 = __ptr == (void *)0x0;
    if (!bVar4) {
      bVar4 = &stack0x0000000c + iVar1 == *(undefined1 **)(&stack0x00000004 + iVar1);
    }
    if (bVar4) {
      uVar2 = 0xffffffff;
    }
    else {
      strcpy(&stack0x0000000c + iVar1,param_1);
      strcat(&stack0x0000000c + iVar1,DAT_300edcec);
      iVar3 = iosDevFind(&stack0x0000000c + iVar1,&stack0x00000004 + iVar1);
      bVar4 = iVar3 == 0;
      if (!bVar4) {
        bVar4 = &stack0x0000000c + iVar1 == *(undefined1 **)(&stack0x00000004 + iVar1);
      }
      if (bVar4) {
        uVar2 = 0xffffffff;
      }
      else {
        iosDevDelete(iVar3);
        iosDevDelete(__ptr);
        tyDevTerminate(__ptr);
        semTerminate((int)__ptr + 0x294);
        if ((code *)*DAT_300edcf8 != (code *)0x0) {
          (*(code *)*DAT_300edcf8)((int)__ptr + 0x300);
        }
        free(__ptr);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300ed68c @ 0x300ED68C  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: __errno, atomic32Inc, strlen
 * Константы: 0x300ED68C
 * ---------------------------------------------------------------- */
int FUN_300ed68c(int param_1,char *param_2)

{
  size_t sVar1;
  undefined4 *puVar2;
  
  if ((param_2 != (char *)0x0) && (sVar1 = strlen(param_2), sVar1 != 0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x13;
    return -1;
  }
  *(undefined1 *)(param_1 + 0x2fe) = 0;
  *(undefined1 *)(param_1 + 0x2ff) = 0;
  atomic32Inc(param_1 + 0x210);
  return param_1;
}

/* ----------------------------------------------------------------
 * FUN_300ed6dc @ 0x300ED6DC  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: __errno, atomic32Inc, strlen
 * Константы: 0x300ED6DC
 * ---------------------------------------------------------------- */
int FUN_300ed6dc(int param_1,char *param_2)

{
  size_t sVar1;
  undefined4 *puVar2;
  
  if ((param_2 != (char *)0x0) && (sVar1 = strlen(param_2), sVar1 != 0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x13;
    return -1;
  }
  *(undefined1 *)(param_1 + 0x8c) = 0;
  *(undefined1 *)(param_1 + 0x8d) = 0;
  atomic32Inc(param_1 + 0x20);
  return param_1 + -0x270;
}

/* ----------------------------------------------------------------
 * FUN_300ed734 @ 0x300ED734  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: atomic32Dec, semGive
 * Константы: 0x300ED734
 * Данные: DAT_300edcfc
 * ---------------------------------------------------------------- */
undefined4 FUN_300ed734(int param_1)

{
  int iVar1;
  
  iVar1 = atomic32Dec(param_1 + 0x290);
  if (iVar1 + -1 < 1) {
    *(undefined1 *)(param_1 + 0x2fc) = 1;
    semGive(param_1 + 0x294);
    if ((code *)*DAT_300edcfc != (code *)0x0) {
      (*(code *)*DAT_300edcfc)(param_1 + 0x300,0);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ed794 @ 0x300ED794  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: atomic32Dec, tyIoctl
 * Константы: 0x300ED794
 * Данные: DAT_300edcfc
 * ---------------------------------------------------------------- */
undefined4 FUN_300ed794(int param_1)

{
  int iVar1;
  
  iVar1 = atomic32Dec(param_1 + 0x210);
  if (iVar1 + -1 < 1) {
    tyIoctl(param_1,0xe,0);
    *(undefined1 *)(param_1 + 0x2fe) = 1;
    if ((code *)*DAT_300edcfc != (code *)0x0) {
      (*(code *)*DAT_300edcfc)(param_1 + 0x180,0);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ed7fc @ 0x300ED7FC  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: rngNBytes, tyRead
 * Константы: 0x300ED7FC
 * Данные: DAT_300edcfc, DAT_300edd00
 * ---------------------------------------------------------------- */
undefined4 FUN_300ed7fc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(char *)(param_1 + 0x2fe) == '\0') ||
     (iVar1 = rngNBytes(*(undefined4 *)(param_1 + 0x20)), iVar1 != 0)) {
    uVar2 = tyRead(param_1,param_2,param_3);
    if ((*DAT_300edcfc != 0) &&
       (iVar1 = rngNBytes(*(undefined4 *)(param_1 + 0x20)), iVar1 < *DAT_300edd00)) {
      (*(code *)*DAT_300edcfc)(param_1 + 0x300,1);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300ed890 @ 0x300ED890  (примерный размер ~180 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: semTake, tyITx
 * Константы: 0x300ED890, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int FUN_300ed890(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 local_1c [4];
  
  iVar3 = 0;
  do {
    if (iVar3 < param_3) {
      puVar2 = (undefined1 *)(param_2 + iVar3 + -1);
      iVar3 = param_3 - iVar3;
      do {
        iVar1 = tyITx(param_1,local_1c);
        if (iVar1 != 0) break;
        iVar3 = iVar3 + -1;
        puVar2 = puVar2 + 1;
        *puVar2 = local_1c[0];
      } while (iVar3 != 0);
      iVar3 = param_3 - iVar3;
    }
    if ((*(char *)(param_1 + 0x2fc) != '\0') || (iVar3 != 0)) {
      return iVar3;
    }
    semTake(param_1 + 0x294,0xffffffff);
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300ed944 @ 0x300ED944  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, tyIRd
 * Константы: 0x300ED944
 * ---------------------------------------------------------------- */
int FUN_300ed944(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 0x2fd) != '\0') {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x20;
    return -1;
  }
  iVar4 = 0;
  if (0 < param_3) {
    puVar3 = (undefined1 *)(param_2 + -1);
    iVar4 = param_3;
    do {
      puVar3 = puVar3 + 1;
      iVar2 = tyIRd(param_1,*puVar3);
      if (iVar2 == -1) break;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar4 = param_3 - iVar4;
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * FUN_300ed9b8 @ 0x300ED9B8  (примерный размер ~284 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: tyIoctl
 * Константы: 0x300ED9B8
 * Данные: DAT_300edcfc, DAT_300edd04, DAT_300edd08
 * ---------------------------------------------------------------- */
int FUN_300ed9b8(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  
  if (param_2 != 0x1b) {
    if (0x1b < param_2) {
      if (param_2 == 0x1c) {
        pcVar2 = (code *)*DAT_300edd04;
      }
      else {
        if (param_2 != 0x1d) goto LAB_300edab4;
        pcVar2 = (code *)*DAT_300edd08;
      }
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(param_1,param_3);
      }
      return 0;
    }
    if (param_2 == 1) {
      iVar1 = tyIoctl(param_1,1,param_3);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (*(char *)(param_1 + 0x2fe) == '\0') {
        return 0;
      }
      return -1;
    }
    if (param_2 != 2) {
LAB_300edab4:
      iVar1 = tyIoctl(param_1,param_2,param_3);
      return iVar1;
    }
  }
  iVar1 = tyIoctl(param_1,param_2,param_3);
  if ((iVar1 == 0) && ((code *)*DAT_300edcfc != (code *)0x0)) {
    (*(code *)*DAT_300edcfc)(param_1 + 0x300,1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300edad4 @ 0x300EDAD4  (примерный размер ~404 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: tyIoctl
 * Константы: 0x300EDAD4, 0x02000000
 * Данные: DAT_300edcfc, DAT_300edd0c, DAT_300edd10, DAT_300edd14
 * ---------------------------------------------------------------- */
undefined4 FUN_300edad4(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_2 == 0x1c) {
    if ((code *)*DAT_300edd10 != (code *)0x0) {
      (*(code *)*DAT_300edd10)(param_1,param_3);
    }
  }
  else if (param_2 == 0x1d) {
    if ((code *)*DAT_300edd14 != (code *)0x0) {
      (*(code *)*DAT_300edd14)(param_1,param_3);
    }
  }
  else {
    if (param_2 != DAT_300edd0c) {
      uVar1 = tyIoctl(param_1,param_2,param_3);
      return uVar1;
    }
    if ((((param_3 & 2) != 0) &&
        (*(char *)(param_1 + 0x2fc) = (char)(param_3 & 1), (param_3 & 1) != 0)) &&
       ((code *)*DAT_300edcfc != (code *)0x0)) {
      (*(code *)*DAT_300edcfc)(param_1 + 0x300,0);
    }
    if ((((param_3 & 0x200) != 0) &&
        (uVar2 = (int)param_3 >> 8 & 1, *(char *)(param_1 + 0x2fd) = (char)uVar2, uVar2 != 0)) &&
       ((code *)*DAT_300edcfc != (code *)0x0)) {
      (*(code *)*DAT_300edcfc)(param_1 + 0x300,1);
    }
    if ((((param_3 & 0x20000) != 0) &&
        (uVar2 = (int)param_3 >> 0x10 & 1, *(char *)(param_1 + 0x2fe) = (char)uVar2, uVar2 != 0)) &&
       ((code *)*DAT_300edcfc != (code *)0x0)) {
      (*(code *)*DAT_300edcfc)(param_1 + 0x180,0);
    }
    if ((((param_3 & 0x2000000) != 0) &&
        (uVar2 = (int)param_3 >> 0x18 & 1, *(char *)(param_1 + 0x2ff) = (char)uVar2, uVar2 != 0)) &&
       ((code *)*DAT_300edcfc != (code *)0x0)) {
      (*(code *)*DAT_300edcfc)(param_1 + 0x180,1);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300edc68 @ 0x300EDC68  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: semGive
 * Константы: 0x300EDC68
 * Данные: DAT_300edcfc
 * ---------------------------------------------------------------- */
void FUN_300edc68(int param_1)

{
  if ((code *)*DAT_300edcfc != (code *)0x0) {
    (*(code *)*DAT_300edcfc)(param_1 + 0x300,0);
  }
  *(undefined1 *)(param_1 + 0x16a) = 0;
  semGive(param_1 + 0x294);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300edd18 @ 0x300EDD18  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: free, iosFdMaxFiles, malloc, semBInit
 * Вызывают: selectInit
 * Константы: 0xFFFFFFFF, 0x300EDD18
 * ---------------------------------------------------------------- */
undefined4 FUN_300edd18(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  void *__ptr;
  void *__ptr_00;
  void *pvVar4;
  
  iVar3 = iosFdMaxFiles();
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar2 = iVar3 + 0x1fU >> 5;
  iVar1 = uVar2 * 4;
  __ptr = malloc(0x90);
  __ptr_00 = malloc(uVar2 * 0xc);
  if (__ptr != (void *)0x0) {
    if (__ptr_00 != (void *)0x0) {
      *(void **)((int)__ptr + 0x78) = __ptr_00;
      pvVar4 = (void *)(iVar1 + (int)__ptr_00);
      *(void **)((int)__ptr + 0x7c) = pvVar4;
      *(void **)((int)__ptr + 0x80) = (void *)(iVar1 + (int)pvVar4);
      *(int *)((int)__ptr + 0x84) = iVar3;
      *(undefined4 *)((int)__ptr + 0x68) = 0;
      *(undefined4 *)((int)__ptr + 0x6c) = 0;
      *(undefined4 *)((int)__ptr + 0x70) = 0;
      *(undefined4 *)((int)__ptr + 0x74) = 0;
      iVar3 = semBInit(__ptr,0x21,0);
      if (iVar3 != 0) {
        free(__ptr_00);
        free(__ptr);
        return 0xffffffff;
      }
      *(void **)(param_1 + 0xdc) = __ptr;
      return 0;
    }
    free(__ptr);
  }
  if (__ptr_00 != (void *)0x0) {
    free(__ptr_00);
  }
  return 0xffffffff;
}

