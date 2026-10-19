/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : kernel — ядро VxWorks 6.8: задачи, семафоры, очереди, прерывания, память, планировщик
 * Часть  : 5 (функций: 150, адреса 0x300F1874..0x3011EE8C)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * FUN_300f1874 @ 0x300F1874  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F1874
 * Данные: DAT_300f1a6c
 * ---------------------------------------------------------------- */
void FUN_300f1874(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (((code *)*DAT_300f1a6c != (code *)0x0) && ((*(uint *)(param_1 + 0xbc) & 0x80) != 0)) {
    (*(code *)*DAT_300f1a6c)(param_4,param_3,param_2,param_1,0,0,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * memOptionsSet @ 0x300F18D4  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: memPartOptionsSet
 * Константы: 0x300F18D4
 * Данные: DAT_300f1a40
 * ---------------------------------------------------------------- */
void memOptionsSet(undefined4 param_1)

{
  memPartOptionsSet(*DAT_300f1a40,param_1);
  return;
}

/* ----------------------------------------------------------------
 * memOptionsGet @ 0x300F18E4  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: memPartOptionsGet
 * Константы: 0x300F18E4
 * Данные: DAT_300f1a40
 * ---------------------------------------------------------------- */
void memOptionsGet(undefined4 param_1)

{
  memPartOptionsGet(*DAT_300f1a40,param_1);
  return;
}

/* ----------------------------------------------------------------
 * memPartHooksInstall @ 0x300F18F4  (примерный размер ~92 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: objVerify
 * Константы: 0x300F18F4, 0xFFFFFFFF
 * Данные: DAT_300f1a34
 * ---------------------------------------------------------------- */
undefined4
memPartHooksInstall(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = objVerify(param_1,*DAT_300f1a34), iVar1 == 0)) {
    *(undefined4 *)(param_1 + 0xd8) = param_2;
    *(undefined4 *)(param_1 + 200) = param_3;
    *(undefined4 *)(param_1 + 0xcc) = param_4;
    *(undefined4 *)(param_1 + 0xd0) = param_5;
    *(undefined4 *)(param_1 + 0xd4) = param_6;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * memPartBlockValidate @ 0x300F1950  (примерный размер ~292 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x300F1950, 0xFFFFFFFE
 * Данные: DAT_300f1a4c, DAT_300f1a64
 * ---------------------------------------------------------------- */
undefined4 memPartBlockValidate(int param_1,int param_2)

{
  int *piVar1;
  
  if (((param_2 - 0x10U & 3) != 0) || (*(int *)(param_2 + -8) != param_1)) {
    return 0xffffffff;
  }
  if ((*DAT_300f1a4c != 0) &&
     ((((piVar1 = (int *)(((param_2 - 0x10U) + (*(uint *)(param_2 + -0xc) & 0xfffffffe)) -
                         *DAT_300f1a4c), ((uint)piVar1 & 3) != 0 ||
        (*(int *)(param_2 + -4) != DAT_300f1a64)) || (piVar1[3] != DAT_300f1a64)) ||
      (((piVar1[2] != DAT_300f1a64 || (piVar1[1] != DAT_300f1a64)) || (*piVar1 != DAT_300f1a64))))))
  {
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * memPartInsertFree @ 0x300F1A74  (примерный размер ~164 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 2
 * Вызывает: avlUintInsert, avlUintSearch
 * Вызывают: FUN_300f1b90, FUN_300f1e5c, FUN_300f2884, memPartReallocInternal
 * Константы: 0x300F1A74
 * ---------------------------------------------------------------- */
void memPartInsertFree(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = avlUintSearch(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_2 + 4));
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x48);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(iVar1 + 0x10);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(param_2 + 4);
    *(int *)(iVar1 + 0x14) = param_2;
    *(int *)(iVar1 + 0x10) = param_2;
    *(int *)(param_2 + 0xc) = iVar1 + 8;
    *(int *)(param_2 + 8) = iVar1 + 8;
    avlUintInsert(param_1 + 0x40);
  }
  else {
    *(int *)(param_2 + 8) = iVar1 + 8;
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar1 + 0x14);
    *(int *)(iVar1 + 0x14) = param_2;
    *(int *)(*(int *)(param_2 + 0xc) + 8) = param_2;
  }
  *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + 1;
  *(uint *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + (*(uint *)(param_2 + 4) >> 1);
  return;
}

/* ----------------------------------------------------------------
 * memPartDeleteFree @ 0x300F1B18  (примерный размер ~120 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 1
 * Вызывает: avlUintDelete
 * Вызывают: FUN_300f1b90, FUN_300f2884, memPartReallocInternal
 * Константы: 0x300F1B18
 * ---------------------------------------------------------------- */
void memPartDeleteFree(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0xc) == *(int *)(param_2 + 8)) {
    iVar1 = avlUintDelete(param_1 + 0x40,*(undefined4 *)(param_2 + 4));
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 0x48);
      *(int *)(param_1 + 0x48) = iVar1;
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
    }
  }
  else {
    *(int *)(*(int *)(param_2 + 0xc) + 8) = *(int *)(param_2 + 8);
    *(undefined4 *)(*(int *)(param_2 + 8) + 0xc) = *(undefined4 *)(param_2 + 0xc);
  }
  *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + -1;
  *(uint *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) - (*(uint *)(param_2 + 4) >> 1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f1b90 @ 0x300F1B90  (примерный размер ~524 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: avlUintSuccessorGet, memPartDeleteFree, memPartInsertFree
 * Вызывают: FUN_300f2514, sizeNodesAlloc
 * Константы: 0xFFFFFFFE, 0xFFFFFFFC, 0x300F1B90
 * Данные: DAT_300f2af4, DAT_300f2d00
 * ---------------------------------------------------------------- */
uint * FUN_300f1b90(uint param_1,uint param_2,int param_3,uint *param_4)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  
  iVar5 = *DAT_300f2af4;
  if (iVar5 + 0x20U < 0x10) {
    iVar2 = 0x10;
  }
  else {
    iVar2 = iVar5 + 0x20;
  }
  uVar9 = param_2 + iVar5 + 0x13;
  uVar6 = uVar9 & 0xfffffffc;
  uVar7 = uVar6;
  if (param_3 != 4) {
    uVar7 = iVar2 + uVar6 + param_3;
  }
  uVar4 = 0;
  if (uVar7 < param_2) {
    puVar1 = (uint *)0x0;
  }
  else {
    iVar5 = avlUintSuccessorGet(*(undefined4 *)(param_1 + 0x40),uVar7 - 1);
    if (iVar5 == 0) {
      puVar1 = (uint *)0x0;
    }
    else {
      puVar8 = *(uint **)(iVar5 + 0x10);
      memPartDeleteFree(param_1,puVar8);
      puVar3 = (uint *)((int)puVar8 + (puVar8[1] & 0xfffffffe));
      puVar1 = puVar8;
      if ((param_3 != 4) && (((uint)(puVar8 + 4) & param_3 - 1U) != 0)) {
        uVar7 = (int)(puVar8 + 4) + iVar2 + param_3 + -1 & ~(param_3 - 1U);
        puVar1 = (uint *)(uVar7 - 0x10);
        *(uint *)(uVar7 - 0xc) = uVar6 | 1;
        puVar8[1] = (int)puVar1 - (int)puVar8;
        *puVar1 = (int)puVar1 - (int)puVar8 & 0xfffffffe;
        memPartInsertFree(param_1,puVar8);
        uVar4 = 1;
      }
      if ((uint)((int)puVar3 - (int)puVar1) < uVar6 + iVar2) {
        puVar3[1] = puVar3[1] & 0xfffffffe;
        *puVar3 = (int)puVar3 - (int)puVar1;
        puVar1[1] = uVar4 | (int)puVar3 - (int)puVar1;
      }
      else {
        puVar1[1] = uVar6 | uVar4;
        puVar8 = (uint *)((int)puVar1 + (uVar9 & 0xfffffffc));
        puVar8[1] = (int)puVar3 - (int)puVar8;
        *puVar8 = uVar6;
        *puVar3 = (int)puVar3 - (int)puVar8;
        memPartInsertFree(param_1);
      }
      puVar1[2] = param_1;
      uVar7 = puVar1[1];
      *param_4 = uVar7 & 0xfffffffe;
      uVar6 = *(uint *)(param_1 + 0xf4);
      uVar7 = uVar7 >> 1;
      *(uint *)(param_1 + 0xf4) = uVar6 + uVar7;
      *(uint *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + (uint)CARRY4(uVar6,uVar7);
      uVar7 = *(uint *)(param_1 + 0xec);
      *(uint *)(param_1 + 0xec) = uVar7 + 1;
      *(uint *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + (uint)(0xfffffffe < uVar7);
      uVar7 = DAT_300f2d00;
      if (*DAT_300f2af4 != 0) {
        puVar3 = (uint *)((int)puVar1 + ((puVar1[1] & 0xfffffffe) - *DAT_300f2af4));
        puVar1[3] = DAT_300f2d00;
        *puVar3 = uVar7;
        puVar3[1] = uVar7;
        puVar3[2] = uVar7;
        puVar3[3] = uVar7;
      }
      puVar1 = puVar1 + 4;
    }
  }
  return puVar1;
}

/* ----------------------------------------------------------------
 * memPartInit @ 0x300F1FD8  (примерный размер ~192 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 5
 * Вызывает: FUN_300f1e5c, bfill, objCoreInit, semMInit, sllInit
 * Вызывают: memPartCreate, memPartLibInit
 * Константы: 0x300F1FD8, 0xFFFFFFFF
 * Данные: DAT_300f2e64, DAT_300f2e68, DAT_300f2e6c, DAT_300f2e70, DAT_300f2e74, DAT_300f2e78, DAT_300f2e7c
 * ---------------------------------------------------------------- */
undefined4 memPartInit(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  bfill(param_1,0x108,0);
  *(undefined4 *)(param_1 + 0xbc) = *DAT_300f2e64;
  sllInit(param_1 + 0xc0);
  iVar1 = semMInit(param_1 + 0x50,0xd);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    objCoreInit(param_1,*DAT_300f2e68);
    if ((code *)*DAT_300f2e6c != (code *)0x0) {
      (*(code *)*DAT_300f2e6c)(param_1,DAT_300f2e78,DAT_300f2e7c,*DAT_300f2e74,*DAT_300f2e70);
    }
    if (param_2 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_300f1e5c(param_1,param_2,param_3);
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * memPartLibInit @ 0x300F2098  (примерный размер ~256 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 6
 * Вызывает: classInit, edrErrorInjectStub, edrInitFatalPolicyHandler, memPartInit, strcpy, strlen
 * Вызывают: memInit, usrRoot
 * Константы: 0x300F2098, 0xFFFFFFFF
 * Данные: DAT_300f2e68, DAT_300f2e6c, DAT_300f2e70, DAT_300f2e80, DAT_300f2e84, DAT_300f2e88, DAT_300f2e8c, DAT_300f2e90
 * ---------------------------------------------------------------- */
undefined4 memPartLibInit(undefined4 param_1,undefined4 param_2)

{
  char *__src;
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  int iVar4;
  
  __src = DAT_300f2e80;
  iVar4 = DAT_300f2e6c;
  if (*(int *)(DAT_300f2e6c + 4) == 0) {
    iVar1 = classInit(*DAT_300f2e68,0x108,DAT_300f2e84,0,0,0,0,0,0xe,0);
    if (iVar1 == 0) {
      *DAT_300f2e70 = 4;
      iVar1 = memPartInit(DAT_300f2e88,param_1,param_2);
      if (iVar1 != -1) {
        *(undefined4 *)(iVar4 + 4) = 1;
        goto LAB_300f2130;
      }
    }
    strcpy((char *)*DAT_300f2e8c,__src);
    iVar4 = *DAT_300f2e8c;
    sVar3 = strlen(__src);
    *DAT_300f2e8c = iVar4 + sVar3;
    edrErrorInjectStub(0x31,DAT_300f2e90,DAT_300f2e94,0,0,0,__src);
    edrInitFatalPolicyHandler(0);
    uVar2 = 0xffffffff;
  }
  else {
LAB_300f2130:
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300f2198 @ 0x300F2198  (примерный размер ~232 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 8
 * Вызывает: __errno, objCoreInvalidate, objCoreTerminate, objFree, objVerify, semMTake, semTerminate, taskCpuUnlock
 * Вызывают: memPartCreate, memPartDelete
 * Константы: 0xFFFFFFFF, 0x300F2198
 * Данные: DAT_300f2e68, DAT_300f2e98, DAT_300f2e9c
 * ---------------------------------------------------------------- */
code * FUN_300f2198(uint param_1,int param_2)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  bool bVar4;
  
  if ((param_1 & 1) == 0) {
    *(int *)(*DAT_300f2e9c + 0x7c) = *(int *)(*DAT_300f2e9c + 0x7c) + 1;
    iVar3 = objVerify(param_1,*DAT_300f2e68);
    if (iVar3 == 0) {
      objCoreInvalidate(param_1);
      taskCpuUnlock();
      iVar3 = semMTake(param_1 + 0x50,0xffffffff);
      if (iVar3 == -1) {
        pcVar2 = (code *)0xffffffff;
      }
      else {
        semTerminate(param_1 + 0x50);
        objCoreTerminate(param_1);
        pcVar2 = *(code **)(param_1 + 0xd4);
        if (pcVar2 != (code *)0x0) {
          pcVar2 = (code *)(*pcVar2)(param_1,*(undefined4 *)(param_1 + 0xd8));
        }
        bVar4 = param_2 == 0;
        if (!bVar4) {
          pcVar2 = (code *)objFree(*DAT_300f2e68,param_1);
          bVar4 = pcVar2 == (code *)0x0;
          if (!bVar4) {
            pcVar2 = (code *)0xffffffff;
          }
        }
        if (bVar4) {
          pcVar2 = (code *)0x0;
        }
      }
    }
    else {
      taskCpuUnlock();
      pcVar2 = (code *)0xffffffff;
    }
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300f2e98;
    pcVar2 = (code *)0xffffffff;
  }
  return pcVar2;
}

/* ----------------------------------------------------------------
 * memPartCreate @ 0x300F2280  (примерный размер ~88 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300f2198, memPartInit, objAlloc
 * Вызывают: shellMemLibInit
 * Константы: 0x300F2280
 * Данные: DAT_300f2e68
 * ---------------------------------------------------------------- */
int memPartCreate(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = objAlloc(*DAT_300f2e68);
  if ((iVar1 != 0) && (iVar2 = memPartInit(iVar1,param_1,param_2), iVar2 == -1)) {
    FUN_300f2198(iVar1,1);
    return 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * memPartDelete @ 0x300F22D8  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300f2198
 * Константы: 0x300F22D8
 * ---------------------------------------------------------------- */
void memPartDelete(undefined4 param_1)

{
  FUN_300f2198(param_1,1);
  return;
}

/* ----------------------------------------------------------------
 * memPartVerifiedLock @ 0x300F22E0  (примерный размер ~116 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 3
 * Вызывает: objVerify, semMTake, taskCpuUnlock
 * Вызывают: memPartAddToPool, memPartFindMax, memPartInfoGet
 * Константы: 0xFFFFFFFF, 0x300F22E0
 * Данные: DAT_300f2e68, DAT_300f2e9c
 * ---------------------------------------------------------------- */
undefined4 memPartVerifiedLock(int param_1)

{
  int iVar1;
  
  *(int *)(*DAT_300f2e9c + 0x7c) = *(int *)(*DAT_300f2e9c + 0x7c) + 1;
  if ((param_1 != 0) && (iVar1 = objVerify(param_1,*DAT_300f2e68), iVar1 == 0)) {
    iVar1 = semMTake(param_1 + 0x50,0xffffffff);
    if (iVar1 != 0) {
      taskCpuUnlock();
      return 0xffffffff;
    }
    taskCpuUnlock();
    return 0;
  }
  taskCpuUnlock();
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * memPartAddToPool @ 0x300F2354  (примерный размер ~188 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_300f1e5c, __errno, memPartVerifiedLock, semMGive
 * Вызывают: FUN_30111430, memAddToPool
 * Константы: 0xFFFFFFFF, 0x300F2354
 * Данные: DAT_300f2ea0, DAT_300f2ea4, DAT_300f2ea8, DAT_300f2eac
 * ---------------------------------------------------------------- */
undefined4 memPartAddToPool(uint param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 & 1) == 0) {
    if (param_2 == 0) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = DAT_300f2eac;
      uVar2 = 0xffffffff;
    }
    else {
      iVar3 = memPartVerifiedLock(param_1);
      if (iVar3 == 0) {
        uVar2 = FUN_300f1e5c(param_1,param_2,param_3);
        semMGive(param_1 + 0x50);
      }
      else {
        uVar2 = 0xffffffff;
      }
    }
  }
  else if ((code *)*DAT_300f2ea0 == (code *)0x0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300f2ea4;
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (*(code *)*DAT_300f2ea0)(param_1 + *DAT_300f2ea8,param_2,param_3);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * memPartEdrErrorInject @ 0x300F2410  (примерный размер ~260 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 5
 * Вызывает: __errno, edrErrorInjectStub, edrKernelFatalPolicyHandler, setjmp, sprintf
 * Вызывают: FUN_300f2514, FUN_300f2884, memPartReallocInternal
 * Константы: 0x300F2410
 * Данные: DAT_300f2e90, DAT_300f2eb0, DAT_300f2eb4, DAT_300f2eb8
 * ---------------------------------------------------------------- */
void memPartEdrErrorInject(int param_1,char *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 *puVar4;
  ulong *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  __jmp_buf_tag *p_Var9;
  int iVar10;
  __jmp_buf_tag _Stack_100;
  
  puVar5 = _Stack_100.__saved_mask.__val + 0x12;
  iVar10 = 0x3c;
  puVar7 = DAT_300f2eb0;
  do {
    puVar6 = puVar7 + 1;
    uVar2 = *puVar7;
    iVar10 = iVar10 + -1;
    puVar7 = puVar7 + 2;
    uVar3 = *puVar6;
    puVar6 = (undefined1 *)((int)puVar5 + 1);
    *(undefined1 *)puVar5 = uVar2;
    puVar5 = (ulong *)((int)puVar5 + 2);
    *puVar6 = uVar3;
  } while (iVar10 != 0);
  p_Var9 = (__jmp_buf_tag *)0x0;
  puVar4 = (undefined4 *)__errno();
  uVar8 = *puVar4;
  iVar10 = setjmp(&_Stack_100);
  if (iVar10 == 0) {
    p_Var9 = &_Stack_100;
  }
  sprintf((char *)(_Stack_100.__saved_mask.__val + 0x12),param_2);
  if (param_4 == 0) {
    uVar1 = *(uint *)(param_1 + 0xbc) >> 10;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0xbc) >> 0xc;
  }
  puVar5 = _Stack_100.__saved_mask.__val + 0x12;
  if ((uVar1 & 1) == 0) {
    edrErrorInjectStub(0x13,DAT_300f2e90,DAT_300f2eb8,p_Var9,0,0,puVar5);
  }
  else {
    edrErrorInjectStub(0x11,DAT_300f2e90,DAT_300f2eb4,p_Var9,0,0,puVar5);
    edrKernelFatalPolicyHandler(0);
  }
  puVar4 = (undefined4 *)__errno();
  *puVar4 = uVar8;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f2514 @ 0x300F2514  (примерный размер ~372 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 8
 * Вызывает: FUN_300f1b90, __errno, errnoSet, memPartEdrErrorInject, semMGive, semMTake, sizeNodesAlloc, taskSuspend
 * Вызывают: malloc, memPartAlignedAlloc, memPartAlloc, realloc
 * Константы: 0x300F2514, 0xFFFFFFFF
 * Данные: DAT_300f2e70, DAT_300f2e9c, DAT_300f2ebc, DAT_300f2ec0, DAT_300f2ec4, DAT_300f2ec8
 * ---------------------------------------------------------------- */
int FUN_300f2514(int param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint local_18;
  
  if ((param_3 & param_3 - 1) == 0) {
    if (param_2 == 0) {
      param_2 = 1;
    }
    uVar2 = *DAT_300f2e70;
    if (uVar2 <= param_3) {
      uVar2 = param_3;
    }
    iVar3 = semMTake(param_1 + 0x50,0xffffffff);
    if (iVar3 == 0) {
      iVar3 = sizeNodesAlloc(param_1,0,0);
      if ((iVar3 == 0) && (iVar3 = FUN_300f1b90(param_1,param_2,uVar2,&local_18), iVar3 != 0)) {
        iVar4 = *(int *)(param_1 + 0xe8) + (local_18 >> 1);
        *(int *)(param_1 + 0xe8) = iVar4;
        *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0xe4) + 1;
        if (*(uint *)(param_1 + 0xfc) < (uint)(iVar4 + *(int *)(param_1 + 0x104))) {
          *(int *)(param_1 + 0xfc) = iVar4 + *(int *)(param_1 + 0x104);
        }
        semMGive(param_1 + 0x50);
        return iVar3;
      }
      semMGive(param_1 + 0x50);
      if ((code *)*DAT_300f2ec0 != (code *)0x0) {
        (*(code *)*DAT_300f2ec0)(param_1,param_2,uVar2);
      }
      errnoSet(DAT_300f2ec4);
      if ((*(uint *)(param_1 + 0xbc) & 0x600) != 0) {
        memPartEdrErrorInject(param_1,*DAT_300f2ec8,0,0,param_2,uVar2);
      }
      if (((*(uint *)(param_1 + 0xbc) & 0x40) != 0) && ((*(uint *)(*DAT_300f2e9c + 0x98) & 2) == 0))
      {
        taskSuspend(0);
      }
    }
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300f2ebc;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * memPartAlignedAlloc @ 0x300F2688  (примерный размер ~128 байт)
 * Модуль: kernel | Вызывают: 12 | Вызывает: 2
 * Вызывает: FUN_300f2514, objVerify
 * Вызывают: FUN_300ac1fc, FUN_300ac39c, FUN_300ad5ec, FUN_30121134, cacheAimArch7DmaMalloc, cacheDmaMalloc, calloc, loadShareTgtMemAlign, memalign, taskInit
 *           ...
 * Константы: 0x300F2688
 * Данные: DAT_300f2e68
 * ---------------------------------------------------------------- */
undefined4 memPartAlignedAlloc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (iVar1 = objVerify(param_1,*DAT_300f2e68), iVar1 != 0)) {
    uVar2 = 0;
  }
  else if (*(code **)(param_1 + 200) == (code *)0x0) {
    uVar2 = FUN_300f2514(param_1,param_2,param_3);
  }
  else {
    uVar2 = (**(code **)(param_1 + 200))(param_1,*(undefined4 *)(param_1 + 0xd8),param_2,param_3);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * memPartAlloc @ 0x300F2708  (примерный размер ~216 байт)
 * Модуль: kernel | Вызывают: 24 | Вызывает: 3
 * Вызывает: FUN_300f2514, __errno, objVerify
 * Вызывают: FUN_300ad69c, FUN_300d66b0, FUN_300db20c, FUN_300e463c, FUN_30121134, chdir, creat, dosFsDevCreate, fsmNameInstall, fsmProbeInstall
 *           ...
 * Константы: 0x300F2708
 * Данные: DAT_300f2e68, DAT_300f2e70, DAT_300f2ea4, DAT_300f2ea8, DAT_300f2ecc
 * ---------------------------------------------------------------- */
undefined4 memPartAlloc(uint param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 & 1) == 0) {
    uVar2 = *DAT_300f2e70;
    if ((param_1 == 0) || (iVar3 = objVerify(param_1,*DAT_300f2e68), iVar3 != 0)) {
      uVar2 = 0;
    }
    else if (*(code **)(param_1 + 200) == (code *)0x0) {
      uVar2 = FUN_300f2514(param_1,param_2,uVar2);
    }
    else {
      uVar2 = (**(code **)(param_1 + 200))(param_1,*(undefined4 *)(param_1 + 0xd8),param_2,uVar2);
    }
  }
  else if ((code *)*DAT_300f2ecc == (code *)0x0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300f2ea4;
    uVar2 = 0;
  }
  else {
    uVar2 = (*(code *)*DAT_300f2ecc)(param_1 + *DAT_300f2ea8,param_2);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * memPartBlockIsValid @ 0x300F27E0  (примерный размер ~164 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300f2884, memPartReallocInternal
 * Константы: 0x300F27E0, 0xFFFFFFFE
 * Данные: DAT_300f2af4
 * ---------------------------------------------------------------- */
undefined4 memPartBlockIsValid(int param_1,uint *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((((((uint)param_2 & 3) == 0) && (uVar2 = param_2[1], (uVar2 & ~(uint)(param_3 == 0) & 3) == 0)
       ) && (uVar2 >> 1 <= *(uint *)(param_1 + 0xb8))) &&
     (((*DAT_300f2af4 + 0x10U < uVar2 &&
       (uVar2 = uVar2 & 0xfffffffe, (*(uint *)((int)param_2 + uVar2 + 4) & 1) == param_3)) &&
      ((uVar2 == *(uint *)((int)param_2 + uVar2) && ((*param_2 & 3) == 0)))))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300f2884 @ 0x300F2884  (примерный размер ~532 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 10
 * Вызывает: __errno, memPartBlockIsValid, memPartDeleteFree, memPartEdrErrorInject, memPartInsertFree, semMGive, semMTake, sizeNodesAlloc, taskCpuUnlock, taskSuspend
 * Вызывают: free, loadShareTgtMemFree, memPartFree, realloc
 * Константы: 0xFFFFFFFF, 0x300F2884, 0xFFFFFFFE
 * Данные: DAT_300f2e9c, DAT_300f2ed0, DAT_300f2ed4, DAT_300f2ed8, DAT_300f2edc, DAT_300f2ee0
 * ---------------------------------------------------------------- */
undefined4 FUN_300f2884(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  
  if (param_2 != 0) {
    piVar7 = (int *)(param_2 + -0x10);
    *(int *)(*DAT_300f2e9c + 0x7c) = *(int *)(*DAT_300f2e9c + 0x7c) + 1;
    if (((*(uint *)(param_1 + 0xbc) & 0x10) != 0) &&
       (iVar2 = memPartBlockIsValid(param_1,piVar7,0), uVar1 = DAT_300f2ed0, iVar2 == 0)) {
      taskCpuUnlock();
      puVar3 = (undefined4 *)__errno();
      *puVar3 = DAT_300f2ed4;
      if ((code *)*DAT_300f2ed8 != (code *)0x0) {
        (*(code *)*DAT_300f2ed8)(param_1,param_2,uVar1,*DAT_300f2edc);
      }
      if ((*(uint *)(param_1 + 0xbc) & 0x1800) != 0) {
        memPartEdrErrorInject(param_1,*DAT_300f2edc,uVar1,param_2,0,0);
      }
      if (((*(uint *)(param_1 + 0xbc) & 0x100) != 0) && ((*(uint *)(*DAT_300f2e9c + 0x98) & 2) == 0)
         ) {
        taskSuspend(0);
      }
      return 0xffffffff;
    }
    iVar2 = semMTake(param_1 + 0x50,0xffffffff);
    if (iVar2 != 0) {
      taskCpuUnlock();
      return 0xffffffff;
    }
    taskCpuUnlock();
    if (*(int *)(param_2 + -8) != param_1) {
      semMGive(param_1 + 0x50);
      puVar3 = (undefined4 *)__errno();
      *puVar3 = DAT_300f2ee0;
      return 0xffffffff;
    }
    iVar2 = sizeNodesAlloc(param_1,0,0);
    if (iVar2 == -1) {
      semMGive(param_1 + 0x50);
      return 0xffffffff;
    }
    uVar5 = *(uint *)(param_2 + -0xc);
    piVar4 = (int *)((int)piVar7 + (uVar5 & 0xfffffffe));
    if ((uVar5 & 1) != 0) {
      piVar7 = (int *)((int)piVar7 - *piVar7);
      memPartDeleteFree(param_1,piVar7);
    }
    piVar6 = (int *)((int)piVar4 + (piVar4[1] & 0xfffffffeU));
    if ((piVar6[1] & 1U) != 0) {
      memPartDeleteFree(param_1,piVar4);
      piVar4 = piVar6;
    }
    piVar7[1] = (int)piVar4 - (int)piVar7;
    *piVar4 = (int)piVar4 - (int)piVar7;
    piVar4[1] = piVar4[1] | 1;
    memPartInsertFree(param_1,piVar7);
    *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0xe4) + -1;
    *(uint *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) - (uVar5 >> 1);
    semMGive(param_1 + 0x50);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * memPartFree @ 0x300F2A98  (примерный размер ~196 байт)
 * Модуль: kernel | Вызывают: 40 | Вызывает: 3
 * Вызывает: FUN_300f2884, __errno, objVerify
 * Вызывают: FUN_300ac6ac, FUN_300ad69c, FUN_300ad768, FUN_300d66b0, FUN_300d6de0, FUN_300db1c4, FUN_300e43ec, FUN_30111bc8, FUN_30121134, bio_free
 *           ...
 * Константы: 0xFFFFFFFF, 0x300F2A98
 * Данные: DAT_300f2e68, DAT_300f2ea4, DAT_300f2ea8, DAT_300f2ee4
 * ---------------------------------------------------------------- */
undefined4 memPartFree(uint param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 & 1) == 0) {
    if ((param_1 == 0) || (iVar3 = objVerify(param_1,*DAT_300f2e68), iVar3 != 0)) {
      uVar2 = 0xffffffff;
    }
    else if (*(code **)(param_1 + 0xcc) == (code *)0x0) {
      uVar2 = FUN_300f2884(param_1,param_2);
    }
    else {
      uVar2 = (**(code **)(param_1 + 0xcc))(param_1,*(undefined4 *)(param_1 + 0xd8),param_2);
    }
  }
  else if ((code *)*DAT_300f2ee4 == (code *)0x0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300f2ea4;
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (*(code *)*DAT_300f2ee4)(param_1 + *DAT_300f2ea8,param_2);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * memAddToPool @ 0x300F2B5C  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: memPartAddToPool
 * Вызывают: FUN_30128940
 * Константы: 0x300F2B5C
 * Данные: DAT_300f2ee8
 * ---------------------------------------------------------------- */
void memAddToPool(undefined4 param_1,undefined4 param_2)

{
  memPartAddToPool(*DAT_300f2ee8,param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * memPartCreateHookSet @ 0x300F2DFC  (примерный размер ~72 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F2DFC, 0xFFFFFFFF
 * Данные: DAT_300f2e6c, DAT_300f2ef0
 * ---------------------------------------------------------------- */
undefined4 memPartCreateHookSet(int param_1,int param_2)

{
  if ((param_1 != 0) && (*DAT_300f2e6c != 0)) {
    return 0xffffffff;
  }
  *DAT_300f2ef0 = (uint)(param_2 != 0) << 4;
  *DAT_300f2e6c = param_1;
  return 0;
}

/* ----------------------------------------------------------------
 * memBlockSizeGet @ 0x300F2E44  (примерный размер ~176 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: cacheAimArch7DmaFree
 * Константы: 0x300F2E44, 0xFFFFFFFE
 * Данные: DAT_300f2ef0
 * ---------------------------------------------------------------- */
int memBlockSizeGet(int param_1)

{
  return (*(uint *)(param_1 + -0xc) & 0xfffffffe) - (*DAT_300f2ef0 + 0x10);
}

/* ----------------------------------------------------------------
 * symLibInit @ 0x300F46E8  (примерный размер ~152 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrKernelExtraInit
 * Константы: 0x300F46E8
 * Данные: DAT_300f55d0, DAT_300f55d4, DAT_300f55d8, DAT_300f55dc, DAT_300f55e0, DAT_300f55e4, DAT_300f55e8, DAT_300f55ec
 * ---------------------------------------------------------------- */
undefined4 symLibInit(void)

{
  *DAT_300f55d4 = DAT_300f55d0;
  *DAT_300f55dc = DAT_300f55d8;
  *DAT_300f55e4 = DAT_300f55e0;
  *DAT_300f55ec = DAT_300f55e8;
  *DAT_300f55f4 = DAT_300f55f0;
  *DAT_300f55fc = DAT_300f55f8;
  *DAT_300f5604 = DAT_300f5600;
  *DAT_300f560c = DAT_300f5608;
  *DAT_300f5614 = DAT_300f5610;
  *DAT_300f561c = DAT_300f5618;
  *DAT_300f5624 = DAT_300f5620;
  *DAT_300f562c = DAT_300f5628;
  return 0;
}

/* ----------------------------------------------------------------
 * symTblCreate @ 0x300F4780  (примерный размер ~184 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: handleInit, hashTblCreate, hashTblDelete, memPartAlloc, memPartFree, semMInit
 * Вызывают: usrSysSymTblInit
 * Константы: 0x300F4780
 * Данные: DAT_300f5630, DAT_300f5634, DAT_300f5638, DAT_300f563c
 * ---------------------------------------------------------------- */
int symTblCreate(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = memPartAlloc(param_3,0x84);
  if (iVar1 != 0) {
    iVar2 = hashTblCreate(param_1,DAT_300f5630,DAT_300f5634,DAT_300f5638);
    *(int *)(iVar1 + 0xc) = iVar2;
    if (iVar2 == 0) {
      memPartFree(param_3,iVar1);
      return 0;
    }
    iVar2 = semMInit(iVar1 + 0x10,*DAT_300f563c);
    if (iVar2 != 0) {
      hashTblDelete(*(undefined4 *)(iVar1 + 0xc));
      memPartFree(param_3,iVar1);
      return 0;
    }
    *(undefined4 *)(iVar1 + 0x7c) = param_2;
    *(undefined4 *)(iVar1 + 0x80) = 0;
    *(undefined4 *)(iVar1 + 0x78) = param_3;
    handleInit(iVar1,0x65);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300f4838 @ 0x300F4838  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 10 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: FUN_300f4ad0, symEach, symFindByNameAndType, symFindByValueAndType, symFindSymbol, symFree, symTblAdd, symTblDelete, symTblRemove, symTblSymSetRemove
 * Константы: 0x300F4838, 0xFFFFFFFF
 * Данные: DAT_300f5640
 * ---------------------------------------------------------------- */
undefined4 FUN_300f4838(int param_1)

{
  undefined4 uVar1;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 4) != param_1)) || (*(char *)(param_1 + 10) != 'e')) {
    errnoSet(DAT_300f5640);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * symTblDelete @ 0x300F4874  (примерный размер ~140 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_300f4838, errnoSet, handleTerminate, hashTblDestroy, memPartFree, semGive, semTake, semTerminate
 * Вызывают: symTblShutdown
 * Константы: 0xFFFFFFFF, 0x300F4874
 * Данные: DAT_300f5644
 * ---------------------------------------------------------------- */
undefined4 symTblDelete(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_300f4838();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = semTake(param_1 + 0x10,0xffffffff);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (0 < *(int *)(param_1 + 0x80)) {
    semGive(param_1 + 0x10);
    errnoSet(DAT_300f5644);
    return 0xffffffff;
  }
  semTerminate(param_1 + 0x10);
  handleTerminate(param_1);
  hashTblDestroy(*(undefined4 *)(param_1 + 0xc),1);
  memPartFree(*(undefined4 *)(param_1 + 0x78),param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * symFree @ 0x300F4900  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 2
 * Вызывает: FUN_300f4838, free
 * Вызывают: symRegister, symRemove, symTblSymSetRemove
 * Константы: 0x300F4900, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 symFree(undefined4 param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_300f4838();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  free(param_2);
  return 0;
}

/* ----------------------------------------------------------------
 * symTblSymSetRemove @ 0x300F492C  (примерный размер ~324 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300f4838, hashTblRemove, semGive, semTake, symFree
 * Вызывают: symTblShutdown
 * Константы: 0xFFFFFFFF, 0x300F492C
 * ---------------------------------------------------------------- */
undefined4 symTblSymSetRemove(int param_1,int param_2,byte param_3,byte param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
  
  uVar4 = 0;
  puVar3 = (undefined4 *)0x0;
  bVar1 = false;
  iVar2 = FUN_300f4838();
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  iVar2 = semTake(param_1 + 0x10,0xffffffff);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  puVar5 = (undefined4 *)**(undefined4 **)(*(int *)(param_1 + 0xc) + 0x1c);
  if (*(int *)(*(int *)(param_1 + 0xc) + 0xc) != 0) {
    do {
      if (puVar5 == (undefined4 *)0x0) {
        uVar4 = uVar4 + 1;
        bVar1 = false;
        if (*(uint *)(*(int *)(param_1 + 0xc) + 0xc) == uVar4) break;
      }
      else {
        puVar3 = (undefined4 *)*puVar5;
        if ((param_2 == 0) || (puVar5[3] == param_2)) {
          if ((param_4 & *(byte *)((int)puVar5 + 0x12)) == (param_3 & param_4)) {
            iVar2 = hashTblRemove(*(undefined4 *)(param_1 + 0xc),puVar5);
            if (iVar2 != 0) {
              semGive(param_1 + 0x10);
              return 0xffffffff;
            }
            symFree(param_1,puVar5);
            *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + -1;
          }
          else {
            bVar1 = true;
          }
        }
      }
      if ((param_2 != 0) || (bVar6 = !bVar1, !bVar6)) {
        bVar6 = puVar5 == (undefined4 *)0x0;
      }
      puVar5 = puVar3;
      if (bVar6) {
        puVar5 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0xc) + 0x1c) + uVar4 * 8);
      }
    } while (uVar4 < *(uint *)(*(int *)(param_1 + 0xc) + 0xc));
  }
  semGive(param_1 + 0x10);
  return 0;
}

/* ----------------------------------------------------------------
 * symTblShutdown @ 0x300F4A70  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: symTblDelete, symTblSymSetRemove
 * Константы: 0x300F4A70, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 symTblShutdown(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = symTblSymSetRemove(param_1,0,0,0);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  uVar2 = symTblDelete(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300f4aa4 @ 0x300F4AA4  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300f4ad0
 * Константы: 0x300F4AA4
 * ---------------------------------------------------------------- */
undefined4
FUN_300f4aa4(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,undefined2 param_5
            ,undefined4 param_6)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined1 *)(param_1 + 0x12) = param_4;
  *(undefined2 *)(param_1 + 0x10) = param_5;
  *(undefined4 *)(param_1 + 0xc) = param_6;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f4ad0 @ 0x300F4AD0  (примерный размер ~176 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_300f4838, FUN_300f4aa4, errnoSet, malloc, strlen, strncpy
 * Вызывают: symRegister
 * Константы: 0x300F4AD0
 * Данные: DAT_300f5648
 * ---------------------------------------------------------------- */
void * FUN_300f4ad0(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4,
                   undefined2 param_5,undefined4 param_6)

{
  void *pvVar1;
  int iVar2;
  size_t __n;
  char *__dest;
  
  if (param_2 == (char *)0x0) {
    errnoSet(DAT_300f5648);
    pvVar1 = (void *)0x0;
  }
  else {
    iVar2 = FUN_300f4838();
    if (iVar2 == 0) {
      __n = strlen(param_2);
      pvVar1 = malloc(__n + 0x15);
      if (pvVar1 == (void *)0x0) {
        pvVar1 = (void *)0x0;
      }
      else {
        __dest = (char *)((int)pvVar1 + 0x14);
        __dest[__n] = '\0';
        strncpy(__dest,param_2,__n);
        FUN_300f4aa4(pvVar1,__dest,param_3,param_4,param_5,param_6);
      }
    }
    else {
      pvVar1 = (void *)0x0;
    }
  }
  return pvVar1;
}

/* ----------------------------------------------------------------
 * symTblAdd @ 0x300F4B80  (примерный размер ~184 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_300f4838, errnoSet, hashTblFind, hashTblPut, semGive, semTake
 * Вызывают: FUN_30040538, symRegister
 * Константы: 0xFFFFFFFF, 0x300F4B80
 * Данные: DAT_300f564c
 * ---------------------------------------------------------------- */
undefined4 symTblAdd(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_300f4838();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = semTake(param_1 + 0x10,0xffffffff);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if ((*(int *)(param_1 + 0x7c) == 0) &&
     (iVar1 = hashTblFind(*(undefined4 *)(param_1 + 0xc),param_2,0xff), iVar1 != 0)) {
    semGive(param_1 + 0x10);
    errnoSet(DAT_300f564c);
    return 0xffffffff;
  }
  iVar1 = hashTblPut(*(undefined4 *)(param_1 + 0xc),param_2);
  if (iVar1 != 0) {
    semGive(param_1 + 0x10);
    return 0xffffffff;
  }
  *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
  semGive(param_1 + 0x10);
  return 0;
}

/* ----------------------------------------------------------------
 * symRegister @ 0x300F4C38  (примерный размер ~172 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 3
 * Вызывает: FUN_300f4ad0, symFree, symTblAdd
 * Вызывают: FUN_300fbbc0, shellInternalKernelSymbolCreate, symAdd
 * Константы: 0x300F4C38
 * Данные: DAT_300f5650, DAT_300f5654
 * ---------------------------------------------------------------- */
int symRegister(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined2 param_5,int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_6;
  iVar1 = FUN_300f4ad0();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar2 = symTblAdd(param_1,iVar1,param_3,param_4,param_5,iVar2);
    if (iVar2 == 0) {
      if ((((param_7 != 0) && (param_6 == -1)) && ((code *)*DAT_300f5650 != (code *)0x0)) &&
         (*DAT_300f5654 == param_1)) {
        (*(code *)*DAT_300f5650)(iVar1,param_1);
      }
    }
    else {
      symFree(param_1,iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * symAdd @ 0x300F4CE4  (примерный размер ~56 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: symRegister
 * Константы: 0x300F4CE4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 symAdd(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = symRegister();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * symTblRemove @ 0x300F4D1C  (примерный размер ~168 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_300f4838, errnoSet, hashTblFind, hashTblRemove, semGive, semTake
 * Вызывают: symRemove
 * Константы: 0xFFFFFFFF, 0x300F4D1C
 * Данные: DAT_300f5658, DAT_300f565c
 * ---------------------------------------------------------------- */
undefined4 symTblRemove(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_300f4838();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = semTake(param_1 + 0x10,0xffffffff);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = hashTblFind(*(undefined4 *)(param_1 + 0xc),param_2,DAT_300f5658);
  if (iVar1 == 0) {
    semGive(param_1 + 0x10);
    errnoSet(DAT_300f565c);
    return 0xffffffff;
  }
  iVar1 = hashTblRemove(*(undefined4 *)(param_1 + 0xc),iVar1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + -1;
  semGive(param_1 + 0x10);
  return 0;
}

/* ----------------------------------------------------------------
 * symFindSymbol @ 0x300F4DC4  (примерный размер ~636 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 7
 * Вызывает: FUN_300f4838, errnoSet, hashTblFind, memcmp, rindex, semGive, semTake
 * Вызывают: FUN_300fba98, symByValueAndTypeFind, symFindByNameAndType, symFindByValueAndType, symRemove
 * Константы: 0xFFFFFFFF, 0x300F4DC4
 * Данные: DAT_300f565c, DAT_300f5660, DAT_300f5664, DAT_300f5668, DAT_300f566c, DAT_300f5670, DAT_300f5674
 * ---------------------------------------------------------------- */
undefined4
symFindSymbol(int param_1,int param_2,uint param_3,byte param_4,uint param_5,int *param_6)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *local_40;
  undefined1 auStack_3c [4];
  int local_38;
  byte local_2a;
  
  uVar5 = 0;
  local_40 = (undefined4 *)0x0;
  iVar1 = FUN_300f4838();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (param_6 == (int *)0x0) {
    errnoSet(DAT_300f5660);
    return 0xffffffff;
  }
  if (param_2 == 0) {
    iVar1 = semTake(param_1 + 0x10,0xffffffff);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    iVar1 = 0;
    if (0 < *(int *)(*(int *)(param_1 + 0xc) + 0xc)) {
      do {
        for (puVar7 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0xc) + 0x1c) + iVar1 * 8);
            puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {
          if ((((((param_5 & *(byte *)((int)puVar7 + 0x12)) == (param_4 & param_5)) &&
                (puVar7[2] == param_3)) &&
               ((pcVar2 = rindex((char *)puVar7[1],0x5f), pcVar2 == (char *)0x0 ||
                ((((iVar3 = memcmp(pcVar2,DAT_300f5664,6), iVar3 != 0 &&
                   (iVar3 = memcmp(pcVar2,DAT_300f5668,6), iVar3 != 0)) &&
                  (iVar3 = memcmp(pcVar2,DAT_300f566c,5), iVar3 != 0)) &&
                 (iVar3 = memcmp(pcVar2,DAT_300f5670,0xb), iVar3 != 0)))))) &&
              ((pcVar2 = rindex((char *)puVar7[1],0x2e), pcVar2 == (char *)0x0 ||
               (iVar3 = memcmp(pcVar2,DAT_300f5674,3), iVar3 != 0)))) &&
             ((*(byte *)((int)puVar7 + 0x12) & 2) == 0)) {
            *param_6 = (int)puVar7;
            goto LAB_300f5024;
          }
          if ((((param_5 & *(byte *)((int)puVar7 + 0x12)) == (param_4 & param_5)) &&
              (uVar6 = puVar7[2], uVar6 <= param_3)) &&
             ((uVar5 < uVar6 && ((*(byte *)((int)puVar7 + 0x12) & 2) == 0)))) {
            uVar5 = uVar6;
            local_40 = puVar7;
          }
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(*(int *)(param_1 + 0xc) + 0xc));
      if ((uVar5 != 0) && (local_40 != (undefined4 *)0x0)) {
        *param_6 = (int)local_40;
LAB_300f5024:
        semGive(param_1 + 0x10);
        goto LAB_300f502c;
      }
    }
    semGive(param_1 + 0x10);
    errnoSet(DAT_300f565c);
    uVar4 = 0xffffffff;
  }
  else {
    local_38 = param_2;
    local_2a = param_4;
    iVar1 = semTake(param_1 + 0x10,0xffffffff);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    iVar1 = hashTblFind(*(undefined4 *)(param_1 + 0xc),auStack_3c,param_5);
    semGive(param_1 + 0x10);
    if (iVar1 == 0) {
      errnoSet(DAT_300f565c);
      return 0xffffffff;
    }
    *param_6 = iVar1;
LAB_300f502c:
    uVar4 = 0;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * symRemove @ 0x300F5040  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: symFindSymbol, symFree, symTblRemove
 * Константы: 0xFFFFFFFF, 0x300F5040
 * ---------------------------------------------------------------- */
undefined4 symRemove(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  iVar1 = symFindSymbol(param_1,param_2,0,param_3,0xff,&local_c);
  if (iVar1 == 0) {
    iVar1 = symTblRemove(param_1,local_c);
    if (iVar1 == 0) {
      uVar2 = symFree(param_1,local_c);
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
 * symFindByNameAndType @ 0x300F50A0  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300f4838, symFindSymbol
 * Вызывают: symFindByName
 * Константы: 0xFFFFFFFF, 0x300F50A0
 * ---------------------------------------------------------------- */
undefined4
symFindByNameAndType
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4,
          undefined1 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int local_20;
  
  local_20 = 0;
  iVar1 = FUN_300f4838();
  if (iVar1 == 0) {
    iVar1 = symFindSymbol(param_1,param_2,0,param_5,param_6,&local_20);
    if (iVar1 == -1) {
      uVar2 = 0xffffffff;
    }
    else {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(local_20 + 8);
      }
      if (param_4 != (undefined1 *)0x0) {
        *param_4 = *(undefined1 *)(local_20 + 0x12);
      }
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * symFindByName @ 0x300F5130  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 1
 * Вызывает: symFindByNameAndType
 * Вызывают: FUN_30103f38, FUN_301040fc, FUN_301044b0, symByCNameFind
 * Константы: 0x300F5130
 * ---------------------------------------------------------------- */
void symFindByName(void)

{
  symFindByNameAndType();
  return;
}

/* ----------------------------------------------------------------
 * symByCNameFind @ 0x300F5150  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: free, malloc, strcpy, strlen, symFindByName
 * Константы: 0x300F5150, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 symByCNameFind(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  size_t sVar2;
  undefined1 *__ptr;
  undefined4 uVar3;
  
  iVar1 = symFindByName();
  if (iVar1 != -1) {
    return 0;
  }
  sVar2 = strlen(param_2);
  __ptr = (undefined1 *)malloc(sVar2 + 2);
  if (__ptr == (undefined1 *)0x0) {
    return 0xffffffff;
  }
  *__ptr = 0x5f;
  strcpy(__ptr + 1,param_2);
  uVar3 = symFindByName(param_1,__ptr,param_3,param_4);
  free(__ptr);
  return uVar3;
}

/* ----------------------------------------------------------------
 * symByValueAndTypeFind @ 0x300F51D8  (примерный размер ~188 байт)
 * Модуль: kernel | Вызывают: 9 | Вызывает: 4
 * Вызывает: malloc, strlen, strncpy, symFindSymbol
 * Вызывают: FUN_3011423c, FUN_30114ebc, FUN_301159dc, FUN_3011b4e0, dbgCallPrint, exchTrcPrint, printErrno, shellInternalSymTblFromRtpGet, symByValueFind
 * Константы: 0xFFFFFFFF, 0x300F51D8
 * ---------------------------------------------------------------- */
undefined4
symByValueAndTypeFind
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
          undefined1 *param_5,undefined1 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  size_t sVar4;
  char *__dest;
  int local_1c;
  
  local_1c = 0;
  if (param_3 == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar3 = symFindSymbol(param_1,0,param_2,param_6,param_7,&local_1c);
    iVar1 = local_1c;
    if (iVar3 == 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(local_1c + 8);
      }
      if (param_5 != (undefined1 *)0x0) {
        *param_5 = *(undefined1 *)(local_1c + 0x12);
      }
      sVar4 = strlen(*(char **)(local_1c + 4));
      __dest = (char *)malloc(sVar4 + 1);
      *param_3 = __dest;
      if (__dest == (char *)0x0) {
        uVar2 = 0xffffffff;
      }
      else {
        strncpy(__dest,*(char **)(iVar1 + 4),sVar4 + 1);
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * symByValueFind @ 0x300F5294  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: symByValueAndTypeFind
 * Вызывают: FUN_300f5e28, shellInternalSymbolDisplay
 * Константы: 0x300F5294
 * ---------------------------------------------------------------- */
void symByValueFind(void)

{
  symByValueAndTypeFind();
  return;
}

/* ----------------------------------------------------------------
 * symFindByValueAndType @ 0x300F52BC  (примерный размер ~188 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300f4838, strncpy, symFindSymbol
 * Вызывают: symFindByValue
 * Константы: 0xFFFFFFFF, 0x300F52BC
 * Данные: DAT_300f5678
 * ---------------------------------------------------------------- */
undefined4
symFindByValueAndType
          (undefined4 param_1,undefined4 param_2,char *param_3,undefined4 *param_4,
          undefined1 *param_5,undefined1 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  int local_24;
  
  local_24 = 0;
  iVar1 = FUN_300f4838();
  if (iVar1 == 0) {
    iVar1 = symFindSymbol(param_1,0,param_2,param_6,param_7,&local_24);
    if (iVar1 == 0) {
      strncpy(param_3,*(char **)(local_24 + 4),DAT_300f5678);
      if (param_3[0x100] != '\0') {
        param_3[0x100] = '\0';
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(local_24 + 8);
      }
      if (param_5 != (undefined1 *)0x0) {
        *param_5 = *(undefined1 *)(local_24 + 0x12);
      }
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
 * symFindByValue @ 0x300F5378  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: symFindByValueAndType
 * Константы: 0x300F5378
 * ---------------------------------------------------------------- */
void symFindByValue(void)

{
  symFindByValueAndType();
  return;
}

/* ----------------------------------------------------------------
 * symEach @ 0x300F53A0  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 4
 * Вызывает: FUN_300f4838, hashTblEach, semGive, semTake
 * Вызывают: FUN_30103ffc, FUN_30104058, cplusLoadFixup, lkAddrInternal, symListGet, symName, symShow
 * Константы: 0x300F53A0, 0xFFFFFFFF
 * Данные: DAT_300f567c
 * ---------------------------------------------------------------- */
undefined4 symEach(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = FUN_300f4838();
  if (iVar1 == 0) {
    local_18 = param_2;
    local_14 = param_3;
    iVar1 = semTake(param_1 + 0x10,0xffffffff);
    if (iVar1 == 0) {
      uVar2 = hashTblEach(*(undefined4 *)(param_1 + 0xc),DAT_300f567c,&local_18);
      semGive(param_1 + 0x10);
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
 * FUN_300f540c @ 0x300F540C  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F540C
 * ---------------------------------------------------------------- */
void FUN_300f540c(int param_1,undefined4 *param_2)

{
  (*(code *)*param_2)(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                      *(undefined1 *)(param_1 + 0x12),param_2[1],*(undefined2 *)(param_1 + 0x10),
                      param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f544c @ 0x300F544C  (примерный размер ~80 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: ffsMsb
 * Константы: 0x300F544C
 * ---------------------------------------------------------------- */
uint FUN_300f544c(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  
  pbVar3 = *(byte **)(param_2 + 4);
  iVar4 = 0;
  bVar1 = *pbVar3;
  while (bVar1 != 0) {
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
    iVar4 = iVar4 + (uint)bVar1;
    bVar1 = *pbVar3;
  }
  iVar2 = ffsMsb(param_1);
  return param_3 * iVar4 >> (0x21U - iVar2 & 0xff) & param_1 - 1U;
}

/* ----------------------------------------------------------------
 * FUN_300f549c @ 0x300F549C  (примерный размер ~104 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: strcmp
 * Константы: 0x300F549C
 * Данные: DAT_300f5658
 * ---------------------------------------------------------------- */
bool FUN_300f549c(int param_1,int param_2,uint param_3)

{
  int iVar1;
  bool bVar2;
  
  if (param_3 != DAT_300f5658) {
    bVar2 = (param_3 & *(byte *)(param_2 + 0x12)) == (param_3 & *(byte *)(param_1 + 0x12));
    if (bVar2) {
      iVar1 = strcmp(*(char **)(param_1 + 4),*(char **)(param_2 + 4));
      bVar2 = iVar1 == 0;
    }
    return bVar2;
  }
  return param_1 == param_2;
}

/* ----------------------------------------------------------------
 * symName @ 0x300F5504  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: symEach
 * Константы: 0x300F5504
 * Данные: DAT_300f5680
 * ---------------------------------------------------------------- */
undefined4 symName(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_18 [4];
  undefined4 local_14;
  undefined4 local_10;
  
  local_14 = 0;
  local_10 = param_2;
  symEach(param_1,DAT_300f5680,auStack_18);
  return local_14;
}

/* ----------------------------------------------------------------
 * symNameGet @ 0x300F5558  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrStandaloneInit
 * Константы: 0x300F5558, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 symNameGet(int param_1,undefined4 *param_2)

{
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(param_1 + 4);
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * symValueGet @ 0x300F5580  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F5580, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 symValueGet(int param_1,undefined4 *param_2)

{
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(param_1 + 8);
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * symTypeGet @ 0x300F55A8  (примерный размер ~220 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F55A8, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 symTypeGet(int param_1,undefined1 *param_2)

{
  if ((param_1 != 0) && (param_2 != (undefined1 *)0x0)) {
    *param_2 = *(undefined1 *)(param_1 + 0x12);
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * symShowInit @ 0x300F5684  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: handleShowConnect
 * Вызывают: usrShowInit
 * Константы: 0x300F5684
 * Данные: DAT_300f5b74
 * ---------------------------------------------------------------- */
void symShowInit(void)

{
  handleShowConnect(0x65,DAT_300f5b74);
  return;
}

/* ----------------------------------------------------------------
 * symShow @ 0x300F5690  (примерный размер ~256 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: errnoSet, printf, symEach
 * Константы: 0x300F5690, 0xFFFFFFFF
 * Данные: DAT_300f5b78, DAT_300f5b7c, DAT_300f5b80, DAT_300f5b84, DAT_300f5b88, DAT_300f5b8c, DAT_300f5b90, DAT_300f5b94
 * ---------------------------------------------------------------- */
undefined4 symShow(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 4) == param_1)) && (*(char *)(param_1 + 10) == 'e')) {
    if (param_2 == 0) {
      printf(DAT_300f5b80,DAT_300f5b84,*(undefined4 *)(param_1 + 0x80));
      printf(DAT_300f5b88,DAT_300f5b8c,param_1 + 0x10);
      printf(DAT_300f5b88,DAT_300f5b90,*(undefined4 *)(param_1 + 0xc));
      printf(DAT_300f5b88,DAT_300f5b94,*(undefined4 *)(param_1 + 0x78));
      uVar1 = DAT_300f5b98;
      if (*(int *)(param_1 + 0x7c) == 0) {
        uVar1 = DAT_300f5b9c;
      }
      printf(DAT_300f5ba0,DAT_300f5ba4,uVar1);
    }
    else {
      uVar1 = DAT_300f5ba8;
      if ((*DAT_300f5b78 == param_1) || (uVar1 = DAT_300f5bac, *DAT_300f5b78 != param_1)) {
        symEach(param_1,uVar1);
        *DAT_300f5bb0 = 0;
      }
      else {
        symEach(param_1,DAT_300f5bb4);
      }
    }
    return 0;
  }
  errnoSet(DAT_300f5b7c);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300f5790 @ 0x300F5790  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 2
 * Вызывает: strlen, strncmp
 * Вызывают: FUN_300f57f0, FUN_300f58d8, FUN_300f5a30
 * Константы: 0x300F5790
 * ---------------------------------------------------------------- */
char * FUN_300f5790(char *param_1,char *param_2)

{
  size_t __n;
  size_t sVar1;
  int iVar2;
  int iVar3;
  
  __n = strlen(param_2);
  sVar1 = strlen(param_1);
  iVar3 = sVar1 - __n;
  while( true ) {
    if (iVar3 < 0) {
      return (char *)0x0;
    }
    iVar2 = strncmp(param_1,param_2,__n);
    if (iVar2 == 0) break;
    param_1 = param_1 + 1;
    iVar3 = iVar3 + -1;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * FUN_300f57f0 @ 0x300F57F0  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300f5790, cplusDemangle, printf
 * Константы: 0x300F57F0
 * Данные: DAT_300f5bb8, DAT_300f5bbc
 * ---------------------------------------------------------------- */
undefined4 FUN_300f57f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_110 [260];
  
  if ((param_4 == 0) || (iVar1 = FUN_300f5790(param_1,param_4), iVar1 != 0)) {
    uVar2 = cplusDemangle(param_1,auStack_110,DAT_300f5bb8);
    printf(DAT_300f5bbc,uVar2,param_2);
  }
  return 1;
}

/* ----------------------------------------------------------------
 * symTypeToStringConvert @ 0x300F5850  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300f58d8, FUN_300f5a30, FUN_3011cbc4
 * Константы: 0x300F5850
 * Данные: DAT_300f5bc0
 * ---------------------------------------------------------------- */
undefined4 symTypeToStringConvert(uint param_1)

{
  int iVar1;
  
  if ((param_1 & 0x20) == 0) {
    if ((param_1 & 4) != 0) {
      return DAT_300f5bc0[1];
    }
    if ((param_1 & 8) != 0) {
      return DAT_300f5bc0[2];
    }
    if ((param_1 & 0x10) != 0) {
      return DAT_300f5bc0[3];
    }
    if ((param_1 & 2) != 0) {
      return DAT_300f5bc0[4];
    }
    if ((param_1 & 1) != 0) {
      return *DAT_300f5bc0;
    }
    iVar1 = 0x18;
  }
  else {
    iVar1 = 0x14;
  }
  return *(undefined4 *)((int)DAT_300f5bc0 + iVar1);
}

/* ----------------------------------------------------------------
 * FUN_300f58d8 @ 0x300F58D8  (примерный размер ~344 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 9
 * Вызывает: FUN_300f5790, __udiv32, cplusDemangle, fioRdString, moduleIdVerify, printf, puts, sprintf, symTypeToStringConvert
 * Константы: 0x300F58D8
 * Данные: DAT_300f5bb0, DAT_300f5bb8, DAT_300f5bc4, DAT_300f5bc8, DAT_300f5bcc, DAT_300f5bd0, DAT_300f5bd4, DAT_300f5bd8
 * ---------------------------------------------------------------- */
undefined4
FUN_300f58d8(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5,
            int param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char local_224 [4];
  int *local_220;
  char local_21c [256];
  undefined1 auStack_11c [260];
  
  iVar5 = *(int *)(param_6 + 0xc);
  if ((((iVar5 == 0) || (iVar5 == -1)) || (iVar5 == -2)) ||
     ((iVar5 == -3 || (iVar1 = moduleIdVerify(iVar5), iVar1 != 0)))) {
    local_21c[0] = '\0';
  }
  else {
    sprintf(local_21c,DAT_300f5bc4,iVar5 + 0x18);
  }
  if ((param_4 == 0) || (iVar5 = FUN_300f5790(param_1,param_4), iVar5 != 0)) {
    uVar2 = cplusDemangle(param_1,auStack_11c,DAT_300f5bb8);
    uVar3 = symTypeToStringConvert(param_3);
    printf(DAT_300f5bc8,uVar2,param_2,uVar3,local_21c);
    if ((param_3 & 0x40) != 0) {
      printf(DAT_300f5bcc);
    }
    puts(DAT_300f5bd0);
    iVar5 = *DAT_300f5bd4;
    if (iVar5 != 0) {
      local_220 = DAT_300f5bb0;
      iVar4 = *DAT_300f5bb0 + 1;
      *DAT_300f5bb0 = iVar4;
      iVar1 = __udiv32(iVar4,iVar5);
      if (iVar4 == iVar5 * iVar1) {
        printf(DAT_300f5bd8);
        fioRdString(0,local_224,1);
        if (local_224[0] == 'q' || local_224[0] == 'Q') {
          return 0;
        }
      }
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300f5a30 @ 0x300F5A30  (примерный размер ~436 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_300f5790, __udiv32, cplusDemangle, fioRdString, printf, puts, sprintf, symTypeToStringConvert
 * Константы: 0x300F5A30
 * Данные: DAT_300f5bb0, DAT_300f5bb8, DAT_300f5bc8, DAT_300f5bcc, DAT_300f5bd0, DAT_300f5bd4, DAT_300f5bd8, DAT_300f5bdc
 * ---------------------------------------------------------------- */
undefined4
FUN_300f5a30(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5,
            int param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char local_220 [4];
  int *local_21c;
  char local_218 [256];
  undefined1 auStack_118 [260];
  
  if (*(int *)(param_6 + 0xc) == 0) {
    pcVar5 = local_218;
    iVar1 = 6;
    pcVar6 = DAT_300f5bdc;
    do {
      iVar1 = iVar1 + -1;
      *pcVar5 = *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (iVar1 != 0);
  }
  else {
    sprintf(local_218,DAT_300f5be0);
  }
  if ((param_4 == 0) || (iVar1 = FUN_300f5790(param_1,param_4), iVar1 != 0)) {
    uVar2 = cplusDemangle(param_1,auStack_118,DAT_300f5bb8);
    uVar3 = symTypeToStringConvert(param_3);
    printf(DAT_300f5bc8,uVar2,param_2,uVar3,local_218);
    if ((param_3 & 0x40) != 0) {
      printf(DAT_300f5bcc);
    }
    puts(DAT_300f5bd0);
    iVar1 = *DAT_300f5bd4;
    if (iVar1 != 0) {
      local_21c = DAT_300f5bb0;
      iVar7 = *DAT_300f5bb0 + 1;
      *DAT_300f5bb0 = iVar7;
      iVar4 = __udiv32(iVar7,iVar1);
      if (iVar7 == iVar1 * iVar4) {
        printf(DAT_300f5bd8);
        fioRdString(0,local_220,1);
        if (local_220[0] == 'q' || local_220[0] == 'Q') {
          return 0;
        }
      }
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300f5be4 @ 0x300F5BE4  (примерный размер ~116 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300f5c58, FUN_300f5e28
 * Константы: 0x300F5BE4, 0x300F5BF4
 * Данные: DAT_300f5bf8
 * ---------------------------------------------------------------- */
undefined4 FUN_300f5be4(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x300f5bf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_300f5bf8 + param_1 * 4))();
    return uVar1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f5c58 @ 0x300F5C58  (примерный размер ~464 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300f5be4, __errno, vxMemProbe
 * Вызывают: FUN_300f5e28
 * Константы: 0xFF00FFFF, 0x300F5C58, 0xFFFFFFFF
 * Данные: DAT_300f6338, DAT_300f633c, DAT_300f6340, DAT_300f6344
 * ---------------------------------------------------------------- */
undefined4 FUN_300f5c58(int param_1,uint *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  int local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  
  iVar1 = vxMemProbe(*(int *)(param_1 + 0xa8) + 8,0,4,&local_24);
  if (iVar1 == 0) {
    puVar4 = (uint *)(local_24 + -0x38);
    iVar1 = vxMemProbe(puVar4,0,4,&local_20);
    if (iVar1 == 0) {
      uVar5 = *puVar4;
      uVar3 = DAT_300f633c;
      if ((int)puVar4 - *DAT_300f6338 ==
          ((uVar5 >> 8 | uVar5 << 0x18) ^
          ((uVar5 ^ (uVar5 >> 0x10 | uVar5 << 0x10)) & 0xff00ffff) >> 8)) goto LAB_300f5d50;
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300f6340;
    }
    puVar4 = (uint *)(local_24 + -0x14);
    iVar1 = vxMemProbe(puVar4,0,4,&local_20);
    if (iVar1 == 0) {
      uVar5 = *puVar4;
      uVar3 = DAT_300f6344;
      if ((int)puVar4 - *DAT_300f6338 ==
          ((uVar5 >> 8 | uVar5 << 0x18) ^
          ((uVar5 ^ (uVar5 >> 0x10 | uVar5 << 0x10)) & 0xff00ffff) >> 8)) {
LAB_300f5d50:
        *param_2 = local_20 | 1;
        *param_3 = uVar3;
        return 0;
      }
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300f6340;
    }
  }
  iVar1 = vxMemProbe(*(int *)(param_1 + 0xa8) + 8,0,4,&local_24);
  if (iVar1 == 0) {
    puVar4 = (uint *)(local_24 + -0xc);
    iVar1 = vxMemProbe(puVar4,0,4,&local_1c);
    if ((iVar1 == 0) && (iVar1 = vxMemProbe(local_24 + -8,0,4,&local_18), iVar1 == 0)) {
      uVar5 = *puVar4;
      if ((int)puVar4 - *DAT_300f6338 ==
          ((uVar5 >> 8 | uVar5 << 0x18) ^
          ((uVar5 ^ (uVar5 >> 0x10 | uVar5 << 0x10)) & 0xff00ffff) >> 8)) {
        *param_2 = local_1c | 1;
        uVar3 = FUN_300f5be4(local_18);
        *param_3 = uVar3;
        return 0;
      }
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300f6340;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300f5e28 @ 0x300F5E28  (примерный размер ~888 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 20
 * Вызывает: FUN_300f5be4, FUN_300f5c58, cplusDemangle, free, objVerify, objectShow, printf, puts, shellInternalSymTblFromTaskGet, sprintf, symByValueFind, taskCont, taskInfoGet, taskIsPended
 *           ...
 * Вызывают: taskWaitShowCoreRtn
 * Константы: 0x300F5E28
 * Данные: DAT_300f6348, DAT_300f634c, DAT_300f6350, DAT_300f6354, DAT_300f6358, DAT_300f635c, DAT_300f6360, DAT_300f6364
 * ---------------------------------------------------------------- */
bool FUN_300f5e28(undefined4 param_1,int *param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  undefined1 auStack_34c [4];
  void *local_348;
  int local_344;
  int local_340;
  char *local_33c;
  int local_338;
  char local_334 [12];
  char acStack_328 [12];
  char acStack_31c [12];
  char acStack_310 [12];
  undefined1 auStack_304 [60];
  int iStack_2c8;
  undefined1 auStack_2bc [16];
  int local_2ac;
  undefined4 local_288;
  undefined1 auStack_278 [72];
  undefined1 auStack_230 [260];
  undefined1 auStack_12c [260];
  
  local_344 = 0;
  pcVar9 = acStack_310;
  bVar2 = false;
  local_334[0] = '\0';
  iVar3 = taskStatusString(param_1,local_334);
  if ((iVar3 != 0) && (local_334[0] == '\0')) {
LAB_300f6178:
    return param_2[2] != 0;
  }
  iVar3 = taskIsReady(param_1);
  if ((iVar3 == 0) && (iVar3 = taskIsStopped(param_1), iVar3 == 0)) {
    iVar3 = taskStopForce(param_1);
    if (iVar3 == -1) goto LAB_300f6178;
    bVar2 = true;
  }
  iVar3 = taskInfoGet(param_1,auStack_2bc);
  if (iVar3 != 0) goto LAB_300f6178;
  iVar3 = taskIsPended(param_1);
  pcVar7 = DAT_300f6348;
  if (iVar3 == 0) {
LAB_300f5fbc:
    local_338 = 0;
    pcVar9 = DAT_300f6370;
    pcVar5 = pcVar7;
  }
  else {
    iVar3 = taskTcb(param_1);
    if (iVar3 == 0) goto LAB_300f6178;
    iVar8 = *(int *)(iVar3 + 0xa8);
    iVar10 = iVar8 + -0x44;
    iVar4 = objVerify(iVar10,*DAT_300f634c);
    if (iVar4 == 0) {
      bVar1 = *(byte *)(iVar8 + -4);
      pcVar5 = (char *)FUN_300f5be4((uint)bVar1);
      if (pcVar5 == (char *)0x0) {
        sprintf(acStack_31c,DAT_300f6350,(uint)bVar1);
        pcVar5 = acStack_31c;
      }
      goto LAB_300f5fcc;
    }
    iVar4 = objVerify(iVar8 + -0x4c,*DAT_300f6354);
    iVar10 = iVar8 + -0x4c;
    pcVar5 = DAT_300f6358;
    if ((iVar4 == 0) ||
       (iVar4 = objVerify(iVar8 + -0x68,*DAT_300f6354), iVar10 = iVar8 + -0x68,
       pcVar5 = DAT_300f635c, iVar4 == 0)) goto LAB_300f5fcc;
    pcVar7 = DAT_300f6364;
    if ((*(int *)(iVar3 + 0xa8) == DAT_300f6360) ||
       (local_33c = acStack_31c, iVar3 = FUN_300f5c58(iVar3,&local_338,&local_33c),
       pcVar9 = DAT_300f6368, pcVar7 = DAT_300f636c, pcVar5 = local_33c, iVar3 != 0))
    goto LAB_300f5fbc;
  }
  local_344 = 1;
  iVar10 = local_338;
LAB_300f5fcc:
  iVar3 = local_2ac;
  iVar4 = taskRegsGet(param_1,auStack_304);
  if (iVar4 == 0) {
    iVar3 = iStack_2c8;
  }
  if (bVar2) {
    taskCont(param_1);
  }
  iVar3 = shellInternalSymTblFromTaskGet(param_1,iVar3);
  if (iVar3 == 0) {
    sprintf(acStack_328,DAT_300f6374,local_2ac);
    if (local_344 == 0) {
      pcVar9 = DAT_300f6368;
    }
  }
  else {
    local_348 = (void *)0x0;
    iVar4 = symByValueFind(iVar3,local_2ac,&local_348,&local_340,auStack_34c);
    pcVar7 = DAT_300f6374;
    if (iVar4 == 0 && local_2ac == local_340) {
      cplusDemangle(local_348,auStack_230,DAT_300f6378);
      pcVar7 = DAT_300f637c;
    }
    sprintf(acStack_328,pcVar7);
    free(local_348);
    if (local_344 == 0) {
      local_348 = (void *)0x0;
      iVar3 = symByValueFind(iVar3,iVar10,&local_348,&local_340,auStack_34c);
      pcVar7 = DAT_300f6368;
      if ((iVar3 == 0) && (local_340 == iVar10)) {
        uVar6 = cplusDemangle(local_348,auStack_12c,DAT_300f6378);
        sprintf(acStack_310,DAT_300f6380,uVar6);
        pcVar7 = pcVar9;
      }
      free(local_348);
      pcVar9 = pcVar7;
    }
  }
  printf(DAT_300f6384,auStack_278,acStack_328,param_1,local_334,local_288,pcVar5,iVar10,pcVar9);
  if ((*param_2 != 0) && (iVar10 != 0)) {
    puts(DAT_300f6370);
    objectShow(iVar10,1,param_2[1]);
  }
  return true;
}

/* ----------------------------------------------------------------
 * taskWaitShowCoreRtn @ 0x300F61A0  (примерный размер ~288 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 9
 * Вызывает: FUN_300f5e28, printErr, printf, puts, taskEach, taskIdListGet, taskIdListSort, taskIdSelf, taskListCount
 * Вызывают: FUN_3011b068, taskWaitShow, tw
 * Константы: 0xFFFFFFFF, 0x300F61A0
 * Данные: DAT_300f6388, DAT_300f638c, DAT_300f6390, DAT_300f6394, DAT_300f6398, DAT_300f639c
 * ---------------------------------------------------------------- */
undefined4 taskWaitShowCoreRtn(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 auStack_4 [4];
  
  iVar3 = -DAT_300f6388;
  *(undefined4 *)(&stack0xfffffff0 + iVar3) = param_2;
  *(undefined4 *)(&stack0xfffffff4 + iVar3) = param_4;
  *(undefined4 *)(&stack0xfffffff8 + iVar3) = 0;
  puts(DAT_300f638c);
  if (param_1 == 0) {
    if (param_3 == 0) {
      param_3 = taskIdSelf();
    }
    iVar3 = FUN_300f5e28(param_3,&stack0xfffffff0 + iVar3);
    if (iVar3 == 0) {
      return 0xffffffff;
    }
  }
  else {
    iVar2 = taskListCount(*DAT_300f6390);
    if (iVar2 < 0x1f5) {
      iVar2 = taskIdListGet(auStack_4 + iVar3,500);
      if (iVar2 == 0) {
        printErr(DAT_300f6394,param_4);
        return 0xffffffff;
      }
      taskIdListSort(auStack_4 + iVar3,iVar2);
      if (0 < iVar2) {
        puVar4 = (undefined4 *)(&stack0xfffffff8 + iVar3);
        do {
          puVar4 = puVar4 + 1;
          FUN_300f5e28(*puVar4,&stack0xfffffff0 + iVar3);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    else {
      printf(DAT_300f6398,500);
      uVar1 = DAT_300f639c;
      *(undefined4 *)(&stack0xfffffff8 + iVar3) = 1;
      taskEach(DAT_300f639c,&stack0xfffffff0 + iVar3,0);
      taskEach(uVar1,&stack0xfffffff0 + iVar3,1);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * taskWaitShow @ 0x300F62C0  (примерный размер ~232 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: printErr, taskIdSelf, taskIdVerify, taskWaitShowCoreRtn
 * Константы: 0x300F62C0, 0xFFFFFFFF
 * Данные: DAT_300f63a0, DAT_300f63a4
 * ---------------------------------------------------------------- */
undefined4 taskWaitShow(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    param_1 = taskIdSelf();
  }
  iVar1 = taskIdVerify(param_1);
  if (iVar1 == 0) {
    uVar2 = taskWaitShowCoreRtn(0,param_2 == 1,param_1,DAT_300f63a4);
    return uVar2;
  }
  printErr(DAT_300f63a0);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * cplusLoadFixup @ 0x300F9074  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: cplusCallCtors, cplusXtorGet, symEach
 * Вызывают: FUN_300fb05c
 * Константы: 0xFFFFFFFF, 0x300F9074
 * Данные: DAT_300f914c, DAT_300f9160
 * ---------------------------------------------------------------- */
undefined4 cplusLoadFixup(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_300f914c;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x534) = 0;
  *(undefined4 *)(param_1 + 0x538) = 0;
  symEach(param_2,DAT_300f9160,param_1);
  if ((*(int *)(param_1 + 0x534) != 0) &&
     (((iVar2 = cplusXtorGet(), iVar2 == 1 && (param_3 != 1)) || (param_3 == 0)))) {
    cplusCallCtors(*(undefined4 *)(param_1 + iVar1));
  }
  return 0;
}

/* ----------------------------------------------------------------
 * cplusUnloadFixup @ 0x300F90FC  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: cplusCallDtors, cplusXtorGet
 * Константы: 0x300F90FC
 * Данные: DAT_300f9164
 * ---------------------------------------------------------------- */
undefined4 cplusUnloadFixup(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_300f9164;
  if (((param_1 != 0) && (*(int *)(param_1 + 0x538) != 0)) &&
     (((iVar2 = cplusXtorGet(), iVar2 == 1 && (param_2 != 1)) || (param_2 == 0)))) {
    cplusCallDtors(*(undefined4 *)(param_1 + iVar1));
  }
  return 0;
}

/* ----------------------------------------------------------------
 * moduleUndefSymAdd @ 0x300FBA6C  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: printErr
 * Вызывают: loadUndefinedSymbolProcess
 * Константы: 0x300FBA6C
 * Данные: DAT_300fbe2c
 * ---------------------------------------------------------------- */
undefined4 moduleUndefSymAdd(int param_1,undefined4 param_2)

{
  printErr(DAT_300fbe2c,param_1,param_2);
  *(int *)(param_1 + 0x544) = *(int *)(param_1 + 0x544) + 1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300fba98 @ 0x300FBA98  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: errnoGet, errnoSet, symFindSymbol
 * Вызывают: FUN_300fbbc0, loadUndefinedSymbolProcess
 * Константы: 0x300FBA98
 * Данные: DAT_300fbe0c
 * ---------------------------------------------------------------- */
undefined4 FUN_300fba98(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  
  uVar1 = errnoGet();
  iVar2 = symFindSymbol(*DAT_300fbe0c,param_1,0,1,1,&local_10);
  if (iVar2 == 0) {
    errnoSet(uVar1);
  }
  else {
    errnoSet(uVar1);
    local_10 = 0;
  }
  return local_10;
}

/* ----------------------------------------------------------------
 * FUN_300fbaf8 @ 0x300FBAF8  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300fbbc0, loadUndefinedSymbolProcess
 * Константы: 0x300FBAF8
 * ---------------------------------------------------------------- */
undefined4 FUN_300fbaf8(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 8);
  *(undefined1 *)(param_2 + 1) = *(undefined1 *)(param_1 + 0x12);
  param_2[2] = param_1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300fbb14 @ 0x300FBB14  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300fbbc0
 * Константы: 0x300FBB14
 * ---------------------------------------------------------------- */
bool FUN_300fbb14(uint param_1,int param_2,uint param_3)

{
  if ((param_1 & 0x10000) != 0) {
    return (param_3 & 0x10000) == 0;
  }
  if ((((param_1 & 0x20) != 0) && ((*(byte *)(param_2 + 0x12) & 4) != 4)) &&
     (((param_3 & 0x400) != 0 || (((param_3 & 0x200) != 0 && (*(int *)(param_2 + 0xc) != 0)))))) {
    return true;
  }
  return false;
}

/* ----------------------------------------------------------------
 * FUN_300fbb74 @ 0x300FBB74  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300fbbc0
 * Константы: 0x300FBB74
 * Данные: DAT_300fbdec
 * ---------------------------------------------------------------- */
bool FUN_300fbb74(uint param_1,uint param_2)

{
  uint uVar1;
  
  if ((param_1 & 0x20) == 0) {
    uVar1 = param_2 & 4;
    if ((param_1 & 1) != 0) {
      uVar1 = param_2 & 8;
    }
    if (uVar1 == 0) {
      return false;
    }
  }
  if ((param_1 & 2) == 0) {
    return true;
  }
  return *DAT_300fbdec != 0;
}

/* ----------------------------------------------------------------
 * FUN_300fbbc0 @ 0x300FBBC0  (примерный размер ~372 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 8
 * Вызывает: FUN_300fba98, FUN_300fbaf8, FUN_300fbb14, FUN_300fbb74, loadShareTgtMemAlign, loadShareTgtMemSet, printErr, symRegister
 * Вызывают: loadCommonSymbolProcess, loadDefinedSymbolProcess
 * Константы: 0xFFFFFFFF, 0x300FBBC0, 0xFFFFFFFE
 * Данные: DAT_300fbe0c, DAT_300fbe30
 * ---------------------------------------------------------------- */
undefined4
FUN_300fbbc0(undefined4 param_1,void *param_2,size_t param_3,undefined4 param_4,uint param_5,
            undefined4 *param_6,int param_7,uint param_8)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (((param_5 & 1) != 0) && (iVar4 = FUN_300fba98(), iVar4 != 0)) {
    iVar1 = FUN_300fbb14(param_5,iVar4,param_8);
    if (iVar1 == 0) {
      iVar4 = 0;
    }
    else if (iVar1 == 1) {
      uVar2 = FUN_300fbaf8(iVar4,param_6);
      return uVar2;
    }
  }
  if ((param_5 & 0x20) != 0) {
    if ((param_8 & 0x40) == 0) {
      param_2 = (void *)loadShareTgtMemAlign(param_4,param_3);
      if (param_2 == (void *)0x0) {
        return 0xffffffff;
      }
      loadShareTgtMemSet(param_2,0,param_3);
    }
    else {
      param_2 = (void *)0xffffffff;
      printErr(DAT_300fbe30,param_1);
    }
    *(size_t *)(param_7 + 0x53c) = param_3 + *(int *)(param_7 + 0x53c);
  }
  iVar1 = param_7;
  if ((param_8 & 0x60) == 0x60) {
    iVar1 = 0;
  }
  iVar3 = FUN_300fbb74(param_5 & 0xff,param_8);
  if (iVar3 != 0) {
    if (((param_5 & 0x20) != 0) && ((param_8 & 8) == 0)) {
      param_5 = param_5 & 0xfffffffe;
    }
    iVar4 = symRegister(*DAT_300fbe0c,param_1,param_2,param_5 & 0xff,
                        *(undefined2 *)(param_7 + 0x530),iVar1,0);
    if (iVar4 == 0) {
      return 0xffffffff;
    }
  }
  *param_6 = param_2;
  *(char *)(param_6 + 1) = (char)param_5;
  param_6[2] = iVar4;
  return 0;
}

/* ----------------------------------------------------------------
 * moduleLibInit @ 0x300FC200  (примерный размер ~264 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: bzero, dllInit, handleInit, malloc, moduleShowInit, semMCreate
 * Вызывают: usrLoaderInit
 * Константы: 0x300FC200, 0xFFFFFFFF
 * Данные: DAT_300fd13c, DAT_300fd140, DAT_300fd254, DAT_300fd258, DAT_300fd25c, DAT_300fd260, DAT_300fd264, DAT_300fd268
 * ---------------------------------------------------------------- */
undefined4 moduleLibInit(void)

{
  int iVar1;
  void *__s;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_300fd13c;
  if (*(int *)(DAT_300fd13c + 4) == 0) {
    __s = malloc(0x34);
    *DAT_300fd140 = (int)__s;
    if (__s == (void *)0x0) {
      return 0xffffffff;
    }
    bzero(__s,0x34);
    uVar2 = semMCreate(4);
    *(undefined4 *)(*DAT_300fd140 + 0x14) = uVar2;
    dllInit(*DAT_300fd140 + 0xc);
    uVar2 = semMCreate(4);
    *(undefined4 *)(*DAT_300fd140 + 0x18) = uVar2;
    uVar2 = semMCreate(4);
    *(undefined4 *)(*DAT_300fd140 + 0x1c) = uVar2;
    uVar2 = semMCreate(4);
    *(undefined4 *)(*DAT_300fd140 + 0x28) = uVar2;
    dllInit(*DAT_300fd140 + 0x20);
    iVar3 = *DAT_300fd140;
    *(undefined4 *)(iVar3 + 0x2c) = 1;
    handleInit(iVar3,0x6a);
    *DAT_300fd258 = DAT_300fd254;
    *DAT_300fd260 = DAT_300fd25c;
    *DAT_300fd268 = DAT_300fd264;
    *(undefined4 *)(iVar1 + 4) = 1;
    moduleShowInit();
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300fc308 @ 0x300FC308  (примерный размер ~172 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: dllInsert, errnoSet
 * Вызывают: moduleInit
 * Константы: 0x300FC308, 0xFFFFFFFF
 * Данные: DAT_300fd140, DAT_300fd26c
 * ---------------------------------------------------------------- */
undefined4 FUN_300fc308(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = *(int *)(*DAT_300fd140 + 0xc);
  if (iVar2 != 0) {
    iVar3 = iVar2 + -0xc;
  }
  if (iVar3 != 0) {
    do {
      iVar2 = *(int *)(iVar3 + 0xc);
      iVar1 = 0;
      if (iVar2 != 0) {
        iVar1 = iVar2 + -0xc;
      }
      if (iVar1 == 0) goto LAB_300fc39c;
      if (*(ushort *)(iVar3 + 0x530) + 1 < (uint)*(ushort *)(iVar1 + 0x530)) {
        dllInsert(*DAT_300fd140 + 0xc,iVar3 + 0xc,param_1 + 0xc);
        *(short *)(param_1 + 0x530) = *(short *)(iVar3 + 0x530) + 1;
        break;
      }
      iVar3 = 0;
      if (iVar2 != 0) {
        iVar3 = iVar2 + -0xc;
      }
    } while (iVar3 != 0);
    if (iVar1 != 0) {
      return 0;
    }
  }
LAB_300fc39c:
  errnoSet(DAT_300fd26c);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * moduleFindByName @ 0x300FC3B4  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 4
 * Вызывает: pathLastNamePtr, semGive, semTake, strcmp
 * Вызывают: cplusCtors, cplusDtors, moduleInit
 * Константы: 0x300FC3B4, 0xFFFFFFFF
 * Данные: DAT_300fd140
 * ---------------------------------------------------------------- */
int moduleFindByName(void)

{
  int *piVar1;
  int *piVar2;
  char *__s2;
  char *__s1;
  int iVar3;
  int iVar4;
  
  __s2 = (char *)pathLastNamePtr();
  piVar2 = DAT_300fd140;
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x14),0xffffffff);
  if (*(int *)(*piVar2 + 0x10) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(*piVar2 + 0x10) + -0xc;
  }
  while( true ) {
    if (iVar4 == 0) {
      semGive(*(undefined4 *)(*piVar2 + 0x14));
      return 0;
    }
    __s1 = (char *)pathLastNamePtr(*(undefined4 *)(iVar4 + 0x14));
    iVar3 = strcmp(__s1,__s2);
    if (iVar3 == 0) break;
    piVar1 = (int *)(iVar4 + 0x10);
    iVar4 = 0;
    if (*piVar1 != 0) {
      iVar4 = *piVar1 + -0xc;
    }
  }
  semGive(*(undefined4 *)(*piVar2 + 0x14));
  return iVar4;
}

/* ----------------------------------------------------------------
 * moduleInit @ 0x300FC444  (примерный размер ~412 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 10
 * Вызывает: FUN_300fc308, dllAdd, dllInit, handleInit, moduleFindByName, pathSplit, puts, semGive, semTake, strcpy
 * Вызывают: moduleCreate
 * Константы: 0xFFFFFFFF, 0x300FC444
 * Данные: DAT_300fd13c, DAT_300fd140, DAT_300fd384, DAT_300fd388, DAT_300fd38c, DAT_300fd390, DAT_300fd460, DAT_300fd464
 * ---------------------------------------------------------------- */
undefined4 moduleInit(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  ushort *puVar1;
  int *piVar2;
  ushort uVar3;
  char *__dest;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  
  __dest = (char *)(param_1 + DAT_300fd384);
  *(char **)(param_1 + 0x14) = __dest;
  strcpy(__dest,param_2);
  pathSplit(*(undefined4 *)(param_1 + 0x14),param_1 + DAT_300fd388,param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x518) = param_4;
  *(undefined4 *)(param_1 + 0x52c) = param_3;
  *(undefined4 *)(param_1 + 0x53c) = 0;
  *(undefined4 *)(param_1 + 0x544) = 0;
  iVar4 = dllInit(param_1 + DAT_300fd38c);
  if (iVar4 == 0) {
    iVar4 = dllInit(param_1 + DAT_300fd390);
    if (iVar4 == 0) {
      handleInit(param_1,0x68);
      piVar2 = DAT_300fd140;
      semTake(*(undefined4 *)(*DAT_300fd140 + 0x14),0xffffffff);
      iVar4 = moduleFindByName(param_1 + 0x18);
      if (iVar4 != 0) {
        *(uint *)(iVar4 + 0x518) = *(uint *)(iVar4 + 0x518) | 0x10000;
      }
      puVar1 = DAT_300fd13c;
      iVar7 = *piVar2;
      iVar4 = 0;
      iVar6 = *(int *)(iVar7 + 0x10);
      if (iVar6 != 0) {
        iVar4 = iVar6 + -0xc;
      }
      if (iVar4 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = *(short *)(iVar4 + 0x530) + 1;
      }
      *DAT_300fd13c = uVar3;
      if ((int)(uint)uVar3 < DAT_300fd460) {
        *(ushort *)(param_1 + 0x530) = uVar3;
        *puVar1 = uVar3 + 1;
        dllAdd(iVar7 + 0xc,param_1 + 0xc);
      }
      else {
        iVar4 = FUN_300fc308(param_1);
        if (iVar4 != 0) {
          puts(DAT_300fd464);
          return 0xffffffff;
        }
      }
      semGive(*(undefined4 *)(*piVar2 + 0x14));
      semTake(*(undefined4 *)(*piVar2 + 0x28),0xffffffff);
      for (puVar8 = *(undefined4 **)(*piVar2 + 0x20); puVar8 != (undefined4 *)0x0;
          puVar8 = (undefined4 *)*puVar8) {
        (*(code *)puVar8[2])(param_1);
      }
      semGive(*(undefined4 *)(*piVar2 + 0x28));
      uVar5 = 0;
    }
    else {
      uVar5 = 0xffffffff;
    }
  }
  else {
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * moduleCreate @ 0x300FC5E0  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 5
 * Вызывает: bzero, free, malloc, moduleInit, strlen
 * Вызывают: FUN_300fb05c
 * Константы: 0x300FC5E0
 * Данные: DAT_300fd50c
 * ---------------------------------------------------------------- */
void * moduleCreate(char *param_1,undefined4 param_2,undefined4 param_3)

{
  size_t sVar1;
  void *__s;
  int iVar2;
  
  iVar2 = DAT_300fd50c;
  sVar1 = strlen(param_1);
  __s = malloc(sVar1 + iVar2);
  if (__s == (void *)0x0) {
    return (void *)0x0;
  }
  sVar1 = strlen(param_1);
  bzero(__s,sVar1 + iVar2);
  iVar2 = moduleInit(__s,param_1,param_2,param_3);
  if (iVar2 != 0) {
    free(__s);
    return (void *)0x0;
  }
  return __s;
}

/* ----------------------------------------------------------------
 * FUN_300fc65c @ 0x300FC65C  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: dllGet, semGive, semTake
 * Вызывают: moduleDescDestroy, moduleSegGet
 * Константы: 0x300FC65C, 0xFFFFFFFF
 * Данные: DAT_300fd140, DAT_300fd390
 * ---------------------------------------------------------------- */
undefined4 FUN_300fc65c(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_300fd140;
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x1c),0xffffffff);
  uVar2 = dllGet(param_1 + DAT_300fd390);
  semGive(*(undefined4 *)(*piVar1 + 0x1c));
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300fc69c @ 0x300FC69C  (примерный размер ~72 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: dllGet, semGive, semTake
 * Вызывают: moduleDescDestroy, moduleSectionDescGet
 * Константы: 0x300FC69C, 0xFFFFFFFF
 * Данные: DAT_300fd140, DAT_300fd38c
 * ---------------------------------------------------------------- */
int FUN_300fc69c(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_300fd140;
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x18),0xffffffff);
  iVar2 = dllGet(param_1 + DAT_300fd38c);
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar3 = iVar2 + -0xc;
  }
  semGive(*(undefined4 *)(*piVar1 + 0x18));
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_300fc6e4 @ 0x300FC6E4  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: moduleNextSectionGet, moduleSectionChecksumSet, moduleSectionDescFree
 * Константы: 0x300FC6E4, 0xFFFFFFFF
 * Данные: DAT_300fd510
 * ---------------------------------------------------------------- */
undefined4 FUN_300fc6e4(int param_1)

{
  undefined4 uVar1;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 4) != param_1)) || (*(char *)(param_1 + 10) != 'l')) {
    errnoSet(DAT_300fd510);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * moduleSectionDescFree @ 0x300FC720  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300fc6e4, free, handleTerminate
 * Вызывают: moduleDescDestroy
 * Константы: 0x300FC720, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 moduleSectionDescFree(void *param_1)

{
  int iVar1;
  
  iVar1 = FUN_300fc6e4();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  handleTerminate(param_1);
  free(param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * moduleIdVerify @ 0x300FC754  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 11 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: FUN_300f58d8, moduleDescDestroy, moduleFirstSectionGet, moduleFlagsGet, moduleInfoGet, moduleNameGet, moduleSectionDescGet, moduleSectionRegister, moduleSegAdd, moduleSegFirst
 *           ...
 * Константы: 0x300FC754, 0xFFFFFFFF
 * Данные: DAT_300fd514
 * ---------------------------------------------------------------- */
undefined4 moduleIdVerify(int param_1)

{
  undefined4 uVar1;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 4) != param_1)) || (*(char *)(param_1 + 10) != 'h')) {
    errnoSet(DAT_300fd514);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * moduleDescDestroy @ 0x300FC790  (примерный размер ~224 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 9
 * Вызывает: FUN_300fc65c, FUN_300fc69c, dllRemove, free, handleTerminate, moduleIdVerify, moduleSectionDescFree, semGive, semTake
 * Вызывают: moduleDelete
 * Константы: 0xFFFFFFFF, 0x300FC790
 * Данные: DAT_300fd140
 * ---------------------------------------------------------------- */
undefined4 moduleDescDestroy(void *param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  void *__ptr;
  
  piVar2 = DAT_300fd140;
  bVar1 = false;
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x14),0xffffffff);
  iVar3 = moduleIdVerify(param_1);
  if (iVar3 != 0) {
    semGive(*(undefined4 *)(*piVar2 + 0x14));
    return 0xffffffff;
  }
  handleTerminate(param_1);
  dllRemove(*piVar2 + 0xc,(int)param_1 + 0xc);
  semGive(*(undefined4 *)(*piVar2 + 0x14));
  while (__ptr = (void *)FUN_300fc65c(param_1), __ptr != (void *)0x0) {
    free(__ptr);
  }
  iVar3 = FUN_300fc69c(param_1);
  while (iVar3 != 0) {
    iVar3 = moduleSectionDescFree();
    if (iVar3 == -1) {
      bVar1 = true;
    }
    iVar3 = FUN_300fc69c(param_1);
  }
  if (bVar1) {
    return 0xffffffff;
  }
  if (param_2 != 0) {
    free(param_1);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * moduleDelete @ 0x300FC870  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: moduleDescDestroy
 * Константы: 0x300FC870
 * ---------------------------------------------------------------- */
void moduleDelete(undefined4 param_1)

{
  moduleDescDestroy(param_1,1);
  return;
}

/* ----------------------------------------------------------------
 * moduleIdFigure @ 0x300FC878  (примерный размер ~256 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 6
 * Вызывает: errnoSet, pathLastNamePtr, semGive, semTake, strcmp, vxMemProbe
 * Вызывают: moduleShow, reld
 * Константы: 0x300FC878, 0xFFFFFFFF
 * Данные: DAT_300fd140, DAT_300fd518
 * ---------------------------------------------------------------- */
char * moduleIdFigure(char *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  undefined1 auStack_1c [4];
  
  piVar2 = DAT_300fd140;
  if (param_1 != (char *)0x0) {
    semTake(*(undefined4 *)(*DAT_300fd140 + 0x14),0xffffffff);
    iVar3 = 0;
    do {
      iVar5 = *(int *)(*piVar2 + 0x10);
      if (iVar5 == 0) {
        pcVar6 = (char *)0x0;
      }
      else {
        pcVar6 = (char *)(iVar5 + -0xc);
      }
      while (pcVar6 != (char *)0x0) {
        if (iVar3 == 0) {
          if (pcVar6 == param_1) goto LAB_300fc91c;
        }
        else {
          iVar5 = vxMemProbe(param_1,0,4,auStack_1c);
          if (iVar5 != 0) break;
          pcVar4 = *(char **)(pcVar6 + 0x14);
          iVar5 = strcmp(pcVar4,param_1);
          if (iVar5 == 0) {
LAB_300fc91c:
            semGive(*(undefined4 *)(*piVar2 + 0x14));
            return pcVar6;
          }
          pcVar4 = (char *)pathLastNamePtr(pcVar4);
          iVar5 = strcmp(pcVar4,param_1);
          if (iVar5 == 0) goto LAB_300fc91c;
        }
        piVar1 = (int *)(pcVar6 + 0x10);
        pcVar6 = (char *)0x0;
        if (*piVar1 != 0) {
          pcVar6 = (char *)(*piVar1 + -0xc);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    semGive(*(undefined4 *)(*DAT_300fd140 + 0x14));
  }
  errnoSet(DAT_300fd518);
  return (char *)0x0;
}

/* ----------------------------------------------------------------
 * moduleSectionRegister @ 0x300FC978  (примерный размер ~228 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 8
 * Вызывает: dllAdd, handleInit, malloc, moduleIdVerify, semGive, semTake, strcpy, strlen
 * Вызывают: FUN_300f9e94, loadSegmentsAllocate
 * Константы: 0x300FC978, 0xFFFFFFFF
 * Данные: DAT_300fd140, DAT_300fd38c
 * ---------------------------------------------------------------- */
void * moduleSectionRegister
                 (int param_1,char *param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  size_t sVar3;
  void *pvVar4;
  
  iVar2 = moduleIdVerify();
  if (iVar2 != 0) {
    return (void *)0x0;
  }
  sVar3 = strlen(param_2);
  pvVar4 = malloc(sVar3 + 0x31);
  if (pvVar4 == (void *)0x0) {
    return (void *)0x0;
  }
  *(undefined2 *)((int)pvVar4 + 0x2c) = 0;
  if (param_4 == -1) {
    *(undefined4 *)((int)pvVar4 + 0x18) = 0;
    *(undefined4 *)((int)pvVar4 + 0x1c) = 0;
    param_6 = 2;
  }
  else {
    *(int *)((int)pvVar4 + 0x18) = param_4;
    *(undefined4 *)((int)pvVar4 + 0x1c) = param_5;
  }
  *(undefined4 *)((int)pvVar4 + 0x24) = param_6;
  *(char **)((int)pvVar4 + 0x14) = (char *)((int)pvVar4 + 0x30);
  strcpy((char *)((int)pvVar4 + 0x30),param_2);
  *(undefined4 *)((int)pvVar4 + 0x20) = param_3;
  *(undefined4 *)((int)pvVar4 + 0x28) = param_7;
  handleInit(pvVar4,0x6c);
  piVar1 = DAT_300fd140;
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x18),0xffffffff);
  dllAdd(param_1 + DAT_300fd38c,(int)pvVar4 + 0xc);
  semGive(*(undefined4 *)(*piVar1 + 0x18));
  return pvVar4;
}

/* ----------------------------------------------------------------
 * FUN_300fca5c @ 0x300FCA5C  (примерный размер ~152 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300fd27c, moduleSectionChecksumSet
 * Константы: 0x300FCA5C
 * Данные: DAT_300fd460
 * ---------------------------------------------------------------- */
undefined8 FUN_300fca5c(ushort *param_1,int param_2)

{
  bool bVar1;
  ushort *puVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  bVar1 = false;
  puVar2 = param_1;
  if ((((uint)param_1 & 1) != 0) && (0 < param_2)) {
    puVar2 = (ushort *)((int)param_1 + 1);
    uVar5 = (uint)(byte)*param_1;
    param_2 = param_2 + -1;
    bVar1 = true;
  }
  if (1 < param_2) {
    puVar3 = puVar2;
    iVar4 = param_2 + -1;
    do {
      param_2 = iVar4;
      puVar2 = puVar3 + 1;
      iVar4 = param_2 + -2;
      uVar5 = uVar5 + *puVar3;
      puVar3 = puVar2;
    } while (0 < iVar4);
    param_2 = param_2 + -1;
  }
  if (0 < param_2) {
    uVar5 = uVar5 + (uint)(byte)*puVar2 * 0x100;
  }
  uVar5 = (uVar5 & 0xffff) + (uVar5 >> 0x10);
  uVar5 = (uVar5 & 0xffff) + (uVar5 >> 0x10);
  if (bVar1) {
    uVar5 = uVar5 >> 8 & 0xff | (uVar5 & 0xff) << 8;
  }
  return CONCAT44(DAT_300fd460,~uVar5);
}

/* ----------------------------------------------------------------
 * moduleSectionChecksumSet @ 0x300FCAF4  (примерный размер ~116 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300fc6e4, FUN_300fca5c
 * Вызывают: FUN_300f9e30
 * Константы: 0x300FCAF4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 moduleSectionChecksumSet(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = FUN_300fc6e4();
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  if ((*(int *)(param_1 + 0x18) == 0) || (*(int *)(param_1 + 0x1c) < 1)) {
    *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 2;
  }
  if (((*(uint *)(param_1 + 0x24) & 2) == 0) && (*(int *)(param_1 + 0x20) != 4)) {
    uVar1 = FUN_300fca5c(*(int *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
  }
  else {
    uVar1 = 0;
  }
  *(undefined2 *)(param_1 + 0x2c) = uVar1;
  return 0;
}

/* ----------------------------------------------------------------
 * moduleSegAdd @ 0x300FCB68  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 5
 * Вызывает: dllAdd, malloc, moduleIdVerify, semGive, semTake
 * Вызывают: FUN_300f9e94, loadSegmentsAllocate
 * Константы: 0xFFFFFFFF, 0x300FCB68
 * Данные: DAT_300fd140, DAT_300fd390
 * ---------------------------------------------------------------- */
undefined4
moduleSegAdd(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = moduleIdVerify();
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  pvVar3 = malloc(0x18);
  if (pvVar3 == (void *)0x0) {
    return 0xffffffff;
  }
  *(undefined4 *)((int)pvVar3 + 8) = param_3;
  *(undefined4 *)((int)pvVar3 + 0xc) = param_4;
  *(undefined4 *)((int)pvVar3 + 0x10) = param_2;
  *(undefined4 *)((int)pvVar3 + 0x14) = param_5;
  piVar1 = DAT_300fd140;
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x1c),0xffffffff);
  dllAdd(param_1 + DAT_300fd390,pvVar3);
  semGive(*(undefined4 *)(*piVar1 + 0x1c));
  return 0;
}

/* ----------------------------------------------------------------
 * moduleSegGet @ 0x300FCBF8  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300fc65c, moduleIdVerify
 * Константы: 0x300FCBF8
 * ---------------------------------------------------------------- */
undefined4 moduleSegGet(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = moduleIdVerify();
  if (iVar1 != 0) {
    return 0;
  }
  uVar2 = FUN_300fc65c(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * moduleSectionDescGet @ 0x300FCC20  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300fc69c, moduleIdVerify
 * Константы: 0x300FCC20
 * ---------------------------------------------------------------- */
undefined4 moduleSectionDescGet(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = moduleIdVerify();
  if (iVar1 != 0) {
    return 0;
  }
  uVar2 = FUN_300fc69c(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * moduleSegFirst @ 0x300FCC48  (примерный размер ~72 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: moduleIdVerify, semGive, semTake
 * Вызывают: moduleSegEach, moduleSegInfoGet
 * Константы: 0x300FCC48, 0xFFFFFFFF
 * Данные: DAT_300fd140
 * ---------------------------------------------------------------- */
undefined4 moduleSegFirst(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = moduleIdVerify();
  piVar1 = DAT_300fd140;
  if (iVar2 != 0) {
    return 0;
  }
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x1c),0xffffffff);
  uVar3 = *(undefined4 *)(param_1 + 0x524);
  semGive(*(undefined4 *)(*piVar1 + 0x1c));
  return uVar3;
}

/* ----------------------------------------------------------------
 * moduleSegNext @ 0x300FCC90  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Вызывают: moduleSegEach, moduleSegInfoGet
 * Константы: 0x300FCC90, 0xFFFFFFFF
 * Данные: DAT_300fd140
 * ---------------------------------------------------------------- */
undefined4 moduleSegNext(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_300fd140;
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x1c),0xffffffff);
  uVar2 = *param_1;
  semGive(*(undefined4 *)(*piVar1 + 0x1c));
  return uVar2;
}

/* ----------------------------------------------------------------
 * moduleSegEach @ 0x300FCCC4  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: moduleSegFirst, moduleSegNext, semGive, semTake
 * Константы: 0x300FCCC4, 0xFFFFFFFF
 * Данные: DAT_300fd140
 * ---------------------------------------------------------------- */
int moduleSegEach(undefined4 param_1,code *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_300fd140;
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x1c),0xffffffff);
  iVar2 = moduleSegFirst(param_1);
  while( true ) {
    if (iVar2 == 0) {
      semGive(*(undefined4 *)(*piVar1 + 0x1c));
      return 0;
    }
    iVar3 = (*param_2)(iVar2,param_1,param_3);
    if (iVar3 == 0) break;
    iVar2 = moduleSegNext(iVar2);
  }
  semGive(*(undefined4 *)(*piVar1 + 0x1c));
  return iVar2;
}

/* ----------------------------------------------------------------
 * moduleFirstSectionGet @ 0x300FCD54  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: moduleIdVerify, semGive, semTake
 * Вызывают: FUN_300fd2bc
 * Константы: 0x300FCD54, 0xFFFFFFFF
 * Данные: DAT_300fd140
 * ---------------------------------------------------------------- */
int moduleFirstSectionGet(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = moduleIdVerify();
  piVar1 = DAT_300fd140;
  if (iVar2 != 0) {
    return 0;
  }
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x18),0xffffffff);
  iVar2 = 0;
  if (*(int *)(param_1 + 0x51c) != 0) {
    iVar2 = *(int *)(param_1 + 0x51c) + -0xc;
  }
  semGive(*(undefined4 *)(*piVar1 + 0x18));
  return iVar2;
}

/* ----------------------------------------------------------------
 * moduleNextSectionGet @ 0x300FCDA8  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300fc6e4, semGive, semTake
 * Вызывают: FUN_300fd2bc
 * Константы: 0x300FCDA8, 0xFFFFFFFF
 * Данные: DAT_300fd140
 * ---------------------------------------------------------------- */
int moduleNextSectionGet(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = FUN_300fc6e4();
  piVar1 = DAT_300fd140;
  if (iVar2 != 0) {
    return 0;
  }
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x18),0xffffffff);
  iVar2 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar2 = *(int *)(param_1 + 0xc) + -0xc;
  }
  semGive(*(undefined4 *)(*piVar1 + 0x18));
  return iVar2;
}

/* ----------------------------------------------------------------
 * moduleCreateHookAdd @ 0x300FCDFC  (примерный размер ~148 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: dllAdd, dllInit, malloc, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300FCDFC
 * Данные: DAT_300fd140
 * ---------------------------------------------------------------- */
undefined4 moduleCreateHookAdd(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  
  piVar1 = DAT_300fd140;
  if (*(int *)(*DAT_300fd140 + 0x2c) == 0) {
    iVar2 = dllInit(*DAT_300fd140 + 0x20);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(*piVar1 + 0x2c) = 1;
  }
  pvVar3 = malloc(0xc);
  if (pvVar3 == (void *)0x0) {
    return 0xffffffff;
  }
  *(undefined4 *)((int)pvVar3 + 8) = param_1;
  semTake(*(undefined4 *)(*piVar1 + 0x28),0xffffffff);
  dllAdd(*piVar1 + 0x20,pvVar3);
  semGive(*(undefined4 *)(*piVar1 + 0x28));
  return 0;
}

/* ----------------------------------------------------------------
 * moduleCreateHookDelete @ 0x300FCE90  (примерный размер ~88 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: dllRemove, errnoSet, free
 * Константы: 0x300FCE90, 0xFFFFFFFF
 * Данные: DAT_300fd140, DAT_300fd51c
 * ---------------------------------------------------------------- */
undefined4 moduleCreateHookDelete(int param_1)

{
  undefined4 *__ptr;
  
  __ptr = *(undefined4 **)(*DAT_300fd140 + 0x20);
  while( true ) {
    if (__ptr == (undefined4 *)0x0) {
      errnoSet(DAT_300fd51c);
      return 0xffffffff;
    }
    if (__ptr[2] == param_1) break;
    __ptr = (undefined4 *)*__ptr;
  }
  dllRemove(*DAT_300fd140 + 0x20,__ptr);
  free(__ptr);
  return 0;
}

/* ----------------------------------------------------------------
 * moduleFindByNameAndPath @ 0x300FCEE8  (примерный размер ~156 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: semGive, semTake, strcmp
 * Константы: 0x300FCEE8, 0xFFFFFFFF
 * Данные: DAT_300fd140, DAT_300fd388
 * ---------------------------------------------------------------- */
int moduleFindByNameAndPath(char *param_1,char *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_300fd140;
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x14),0xffffffff);
  iVar3 = *piVar1;
  if (*(int *)(iVar3 + 0x10) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar3 + 0x10) + -0xc;
  }
  while( true ) {
    if (iVar4 == 0) {
      semGive(*(undefined4 *)(iVar3 + 0x14));
      return 0;
    }
    iVar2 = strcmp((char *)(iVar4 + 0x18),param_1);
    if ((iVar2 == 0) && (iVar2 = strcmp((char *)(iVar4 + DAT_300fd388),param_2), iVar2 == 0)) break;
    piVar1 = (int *)(iVar4 + 0x10);
    iVar4 = 0;
    if (*piVar1 != 0) {
      iVar4 = *piVar1 + -0xc;
    }
  }
  semGive(*(undefined4 *)(iVar3 + 0x14));
  return iVar4;
}

/* ----------------------------------------------------------------
 * moduleEach @ 0x300FCF84  (примерный размер ~156 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Вызывают: cplusCtors, cplusDtors
 * Константы: 0x300FCF84, 0xFFFFFFFF
 * Данные: DAT_300fd140
 * ---------------------------------------------------------------- */
int moduleEach(code *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = DAT_300fd140;
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x14),0xffffffff);
  if (*(int *)(*piVar2 + 0x10) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(*piVar2 + 0x10) + -0xc;
  }
  while( true ) {
    if (iVar4 == 0) {
      semGive(*(undefined4 *)(*piVar2 + 0x14));
      return 0;
    }
    iVar3 = (*param_1)(iVar4,param_2);
    if (iVar3 == 0) break;
    piVar1 = (int *)(iVar4 + 0x10);
    iVar4 = 0;
    if (*piVar1 != 0) {
      iVar4 = *piVar1 + -0xc;
    }
  }
  semGive(*(undefined4 *)(*piVar2 + 0x14));
  return iVar4;
}

/* ----------------------------------------------------------------
 * moduleFindByGroup @ 0x300FD020  (примерный размер ~132 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Константы: 0x300FD020, 0xFFFFFFFF
 * Данные: DAT_300fd140
 * ---------------------------------------------------------------- */
int moduleFindByGroup(uint param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_300fd140;
  iVar2 = semTake(*(undefined4 *)(*DAT_300fd140 + 0x14),0xffffffff);
  if (iVar2 != -1) {
    iVar2 = *piVar1;
    iVar3 = 0;
    if (*(int *)(iVar2 + 0x10) != 0) {
      iVar3 = *(int *)(iVar2 + 0x10) + -0xc;
    }
    while (iVar3 != 0) {
      if (*(ushort *)(iVar3 + 0x530) == param_1) {
        semGive(*(undefined4 *)(iVar2 + 0x14));
        return iVar3;
      }
      piVar1 = (int *)(iVar3 + 0x10);
      iVar3 = 0;
      if (*piVar1 != 0) {
        iVar3 = *piVar1 + -0xc;
      }
    }
    semGive(*(undefined4 *)(iVar2 + 0x14));
  }
  return 0;
}

/* ----------------------------------------------------------------
 * moduleIdListGet @ 0x300FD0A4  (примерный размер ~116 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Константы: 0x300FD0A4, 0xFFFFFFFF
 * Данные: DAT_300fd140
 * ---------------------------------------------------------------- */
int moduleIdListGet(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_300fd140;
  semTake(*(undefined4 *)(*DAT_300fd140 + 0x14),0xffffffff);
  iVar2 = *piVar1;
  iVar3 = *(int *)(iVar2 + 0xc);
  iVar4 = 0;
  if (iVar3 != 0) {
    iVar4 = iVar3 + -0xc;
  }
  iVar3 = 0;
  while ((iVar4 != 0 && (iVar3 < param_2))) {
    *(int *)(param_1 + iVar3 * 4) = iVar4;
    piVar1 = (int *)(iVar4 + 0xc);
    iVar3 = iVar3 + 1;
    iVar4 = 0;
    if (*piVar1 != 0) {
      iVar4 = *piVar1 + -0xc;
    }
  }
  semGive(*(undefined4 *)(iVar2 + 0x14));
  return iVar3;
}

/* ----------------------------------------------------------------
 * moduleSegInfoGet @ 0x300FD118  (примерный размер ~224 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 3
 * Вызывает: bzero, moduleSegFirst, moduleSegNext
 * Вызывают: FUN_300fd54c, loadModuleAt, moduleInfoGet
 * Константы: 0x300FD118
 * ---------------------------------------------------------------- */
undefined4 moduleSegInfoGet(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  bzero(param_2,0x24);
  for (iVar1 = moduleSegFirst(param_1); iVar1 != 0; iVar1 = moduleSegNext(iVar1)) {
    iVar3 = *(int *)(iVar1 + 0x10);
    if (iVar3 == 2) {
      param_2[3] = *(undefined4 *)(iVar1 + 0xc);
      param_2[6] = *(undefined4 *)(iVar1 + 0x14);
      if (*(int *)(iVar1 + 0xc) == 0) {
        *param_2 = 0;
      }
      else {
        *param_2 = *(undefined4 *)(iVar1 + 8);
      }
    }
    else if (iVar3 == 4) {
      param_2[4] = *(undefined4 *)(iVar1 + 0xc);
      param_2[7] = *(undefined4 *)(iVar1 + 0x14);
      if (*(int *)(iVar1 + 0xc) == 0) {
        param_2[1] = 0;
      }
      else {
        param_2[1] = *(undefined4 *)(iVar1 + 8);
      }
    }
    else if (iVar3 == 8) {
      param_2[5] = *(undefined4 *)(iVar1 + 0xc);
      param_2[8] = *(undefined4 *)(iVar1 + 0x14);
      if (*(int *)(iVar1 + 0xc) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined4 *)(iVar1 + 8);
      }
      param_2[2] = uVar2;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * moduleInfoGet @ 0x300FD1F8  (примерный размер ~132 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: moduleIdVerify, moduleSegInfoGet, pathLastNamePtr, strncpy
 * Константы: 0x300FD1F8, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 moduleInfoGet(int param_1,char *param_2)

{
  int iVar1;
  char *__src;
  undefined4 uVar2;
  
  iVar1 = moduleIdVerify();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  __src = (char *)pathLastNamePtr(*(undefined4 *)(param_1 + 0x14));
  strncpy(param_2,__src,0xff);
  param_2[0xfe] = '\0';
  *(undefined4 *)(param_2 + 0x100) = *(undefined4 *)(param_1 + 0x52c);
  *(uint *)(param_2 + 0x104) = (uint)*(ushort *)(param_1 + 0x530);
  uVar2 = moduleSegInfoGet(param_1,param_2 + 0x108);
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300fd27c @ 0x300FD27C  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300fca5c, errnoSet
 * Вызывают: FUN_300fd2bc
 * Константы: 0x300FD27C
 * Данные: DAT_300fd520
 * ---------------------------------------------------------------- */
undefined4 FUN_300fd27c(int param_1)

{
  short sVar1;
  
  sVar1 = FUN_300fca5c(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
  if (sVar1 != *(short *)(param_1 + 0x2c)) {
    errnoSet(DAT_300fd520);
    return 0;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300fd2bc @ 0x300FD2BC  (примерный размер ~488 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300fd27c, moduleFirstSectionGet, moduleNextSectionGet, printErr
 * Вызывают: moduleCheck
 * Константы: 0x300FD2BC
 * Данные: DAT_300fd524, DAT_300fd528, DAT_300fd52c, DAT_300fd530, DAT_300fd534, DAT_300fd538
 * ---------------------------------------------------------------- */
undefined4 FUN_300fd2bc(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  
  if (param_2 == 0) {
    param_2 = 2;
  }
  iVar1 = moduleFirstSectionGet(param_1);
  iVar7 = 1;
  iVar6 = 1;
  iVar5 = 1;
  iVar4 = 1;
  uVar8 = 1;
  iVar3 = 1;
  while (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x20);
    iVar9 = iVar3;
    if ((((((iVar2 == 2) && ((param_2 & 2) != 0)) || ((iVar2 == 3 && ((param_2 & 4) != 0)))) ||
         ((iVar2 == 4 && ((param_2 & 8) != 0)))) || ((iVar2 == 1 && ((param_2 & 0x10) != 0)))) &&
       (((*(uint *)(iVar1 + 0x24) & 2) == 0 && (iVar2 = FUN_300fd27c(iVar1), iVar2 == 0)))) {
      if ((param_2 & 1) == 0) {
        iVar2 = *(int *)(iVar1 + 0x20);
        if (iVar2 == 2) {
          iVar3 = iVar7;
          iVar7 = iVar7 + 1;
          uVar8 = DAT_300fd524;
        }
        else if (iVar2 == 3) {
          iVar3 = iVar6;
          iVar6 = iVar6 + 1;
          uVar8 = DAT_300fd528;
        }
        else if (iVar2 == 4) {
          iVar3 = iVar5;
          iVar5 = iVar5 + 1;
          uVar8 = DAT_300fd52c;
        }
        else if (iVar2 == 1) {
          iVar3 = iVar4;
          iVar4 = iVar4 + 1;
          uVar8 = DAT_300fd530;
        }
        else {
          iVar9 = iVar3 + 1;
          uVar8 = DAT_300fd534;
        }
        printErr(DAT_300fd538,uVar8,iVar3,*(undefined4 *)(iVar1 + 0x18),
                 *(undefined4 *)(param_1 + 0x14));
      }
      uVar8 = 0;
    }
    iVar1 = moduleNextSectionGet(iVar1);
    iVar3 = iVar9;
  }
  return uVar8;
}

/* ----------------------------------------------------------------
 * moduleCheck @ 0x300FD4A4  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300fd2bc, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300FD4A4
 * Данные: DAT_300fd53c
 * ---------------------------------------------------------------- */
undefined4 moduleCheck(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar3 = *DAT_300fd53c;
  semTake(*(undefined4 *)(iVar3 + 0x14),0xffffffff);
  iVar5 = 0;
  if (*(int *)(iVar3 + 0x10) != 0) {
    iVar5 = *(int *)(iVar3 + 0x10) + -0xc;
  }
  uVar4 = 0;
  while (iVar5 != 0) {
    iVar2 = FUN_300fd2bc(iVar5,param_1);
    if (iVar2 == 0) {
      uVar4 = 0xffffffff;
    }
    piVar1 = (int *)(iVar5 + 0x10);
    iVar5 = 0;
    if (*piVar1 != 0) {
      iVar5 = *piVar1 + -0xc;
    }
  }
  semGive(*(undefined4 *)(iVar3 + 0x14));
  return uVar4;
}

/* ----------------------------------------------------------------
 * moduleNameGet @ 0x300FD4B4  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: moduleIdVerify, pathLastNamePtr
 * Константы: 0x300FD4B4
 * ---------------------------------------------------------------- */
undefined4 moduleNameGet(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = moduleIdVerify();
  if (iVar1 != 0) {
    return 0;
  }
  uVar2 = pathLastNamePtr(*(undefined4 *)(param_1 + 0x14));
  return uVar2;
}

/* ----------------------------------------------------------------
 * moduleFlagsGet @ 0x300FD4DC  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: moduleIdVerify
 * Константы: 0x300FD4DC
 * ---------------------------------------------------------------- */
undefined4 moduleFlagsGet(int param_1)

{
  int iVar1;
  
  iVar1 = moduleIdVerify();
  if (iVar1 != 0) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x518);
}

/* ----------------------------------------------------------------
 * moduleShowInit @ 0x300FD540  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: handleShowConnect
 * Вызывают: moduleLibInit
 * Константы: 0x300FD540
 * Данные: DAT_300fd7d4
 * ---------------------------------------------------------------- */
void moduleShowInit(void)

{
  handleShowConnect(0x6a,DAT_300fd7d4);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300fd54c @ 0x300FD54C  (примерный размер ~480 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: moduleSegInfoGet, printErr, printf, puts, sprintf, strlen
 * Вызывают: moduleShow
 * Константы: 0x300FD54C, 0xFFFFFFFF
 * Данные: DAT_300fd7d8, DAT_300fd7dc, DAT_300fd7e0, DAT_300fd7e4, DAT_300fd7e8, DAT_300fd7ec, DAT_300fd7f0, DAT_300fd7f4
 * ---------------------------------------------------------------- */
undefined4 FUN_300fd54c(int param_1,uint param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char acStack_58 [12];
  char acStack_4c [12];
  char acStack_40 [12];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  pcVar6 = DAT_300fd7d8;
  iVar3 = 0xb;
  pcVar4 = acStack_58;
  pcVar5 = DAT_300fd7dc;
  do {
    iVar3 = iVar3 + -1;
    *pcVar4 = *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (iVar3 != 0);
  iVar3 = 0xb;
  pcVar4 = acStack_4c;
  pcVar5 = DAT_300fd7e0;
  do {
    iVar3 = iVar3 + -1;
    *pcVar4 = *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (iVar3 != 0);
  iVar3 = 0xb;
  pcVar4 = acStack_40;
  pcVar5 = DAT_300fd7e4;
  do {
    iVar3 = iVar3 + -1;
    *pcVar4 = *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (iVar3 != 0);
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    if ((param_2 & 4) != 0) {
      param_1 = param_1 + -0xc;
    }
    if ((*(uint *)(param_1 + 0x518) & 0x10) == 0) {
      if (((param_2 & 1) != 0) && (sVar2 = strlen((char *)(param_1 + 0x18)), 0xf < sVar2)) {
        pcVar6 = DAT_300fd7e8;
      }
      iVar3 = moduleSegInfoGet(param_1,&local_34);
      if (iVar3 != 0) {
        printErr(DAT_300fd7ec,param_1);
        return 0;
      }
      if (local_28 != 0) {
        sprintf(acStack_58,DAT_300fd7f0,local_34);
      }
      if (local_24 != 0) {
        sprintf(acStack_4c,DAT_300fd7f0,local_30);
      }
      if (local_20 != 0) {
        sprintf(acStack_40,DAT_300fd7f0,local_2c);
      }
      printf(pcVar6,param_1 + 0x18,param_1,(uint)*(ushort *)(param_1 + 0x530),acStack_58,acStack_4c,
             acStack_40);
      if ((param_2 & 8) != 0) {
        printf(DAT_300fd7f4,local_28);
        printf(DAT_300fd7f8,local_24);
        printf(DAT_300fd7fc,local_20);
        printf(DAT_300fd800,local_28 + local_24 + local_20);
      }
      if ((param_2 & 9) == 9) {
        pcVar6 = (char *)(param_1 + DAT_300fd804);
        sVar2 = strlen(pcVar6);
        if (sVar2 == 0) {
          puts(DAT_300fd80c);
        }
        else {
          printf(DAT_300fd808,pcVar6);
        }
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * moduleShow @ 0x300FD72C  (примерный размер ~248 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 7
 * Вызывает: FUN_300fd54c, dllEach, moduleIdFigure, printf, puts, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300FD72C
 * Данные: DAT_300fd810, DAT_300fd814, DAT_300fd818, DAT_300fd81c, DAT_300fd820
 * ---------------------------------------------------------------- */
undefined4 moduleShow(int param_1,uint param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = moduleIdFigure(param_1);
    if (iVar1 == 0) {
      puts(DAT_300fd810);
      return 0xffffffff;
    }
  }
  printf(DAT_300fd818,*DAT_300fd814);
  if (iVar1 == 0) {
    semTake(*(undefined4 *)(*DAT_300fd81c + 0x14),0xffffffff);
    dllEach(*DAT_300fd81c + 0xc,DAT_300fd820,param_2 | 4);
    semGive(*(undefined4 *)(*DAT_300fd81c + 0x14));
  }
  else {
    FUN_300fd54c(iVar1,param_2 | 8);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * dbgInit @ 0x30113FFC  (примерный размер ~208 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: _dbgArchInit, semMInit, vxdbgClntRegister, vxdbgHookAdd
 * Вызывают: usrShellInit
 * Константы: 0xFFFFFFFF, 0x30113FFC
 * Данные: DAT_30114fc8, DAT_30114fcc, DAT_30114fd0, DAT_30114fd4, DAT_30114fd8, DAT_30114fdc, DAT_30114fe0, DAT_30114fe4
 * ---------------------------------------------------------------- */
undefined4 dbgInit(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_30114fc8;
  if (*(int *)(DAT_30114fc8 + 0x24) == 0) {
    iVar3 = semMInit(DAT_30114fcc,5);
    if (iVar3 != 0) {
      return 0xffffffff;
    }
    iVar3 = vxdbgClntRegister(2);
    *DAT_30114fd0 = iVar3;
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    _dbgArchInit(iVar3);
    uVar2 = DAT_30114fd4;
    vxdbgHookAdd(*DAT_30114fd0,2,DAT_30114fd4);
    vxdbgHookAdd(*DAT_30114fd0,1,uVar2);
    vxdbgHookAdd(*DAT_30114fd0,8,DAT_30114fd8);
    *DAT_30114fe0 = DAT_30114fdc;
    *DAT_30114fe8 = DAT_30114fe4;
    *DAT_30114ff0 = DAT_30114fec;
    *(undefined4 *)(iVar1 + 0x24) = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * dbgHelp @ 0x301140CC  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x301140CC
 * Данные: DAT_30114ff4, DAT_30114ff8, DAT_30114ffc
 * ---------------------------------------------------------------- */
void dbgHelp(void)

{
  printf(DAT_30114ff8,*DAT_30114ff4);
  printf(DAT_30114ff8,*DAT_30114ffc);
  return;
}

/* ----------------------------------------------------------------
 * dbgBpEpCoreRtn @ 0x301140F4  (примерный размер ~328 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 4
 * Вызывает: __errno, printErr, taskIdVerify, vxdbgBpAdd
 * Вызывают: FUN_30114598, dbgDynPrintfCommonRtn
 * Константы: 0xFFFFFFFF, 0x301140F4
 * Данные: DAT_30114fc8, DAT_30114fd0, DAT_30115000, DAT_30115004, DAT_30115100, DAT_30115104, DAT_30115108, DAT_3011510c
 * ---------------------------------------------------------------- */
undefined4
dbgBpEpCoreRtn(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
              int param_9,undefined4 param_10)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 auStack_24 [4];
  
  puVar6 = auStack_24;
  iVar3 = param_9;
  uVar4 = param_1;
  iVar1 = vxdbgBpAdd(*DAT_30114fd0);
  if (iVar1 == -1) {
    piVar2 = (int *)__errno();
    iVar1 = *piVar2;
    if (iVar1 == DAT_30115000) {
      printErr(DAT_30115120);
      uVar4 = 0xffffffff;
    }
    else if (iVar1 == DAT_30115004) {
      uVar5 = DAT_30115110;
      if (param_9 == 0) {
        uVar5 = DAT_30115114;
      }
      printErr(uVar5,param_10,param_1,param_4,param_8,iVar3,uVar4,param_5,param_7,puVar6);
      uVar4 = 0xffffffff;
    }
    else if (iVar1 == DAT_30115100) {
      if ((*param_2 == 0) || (iVar3 = taskIdVerify(*param_2), iVar3 != 0)) {
        uVar4 = DAT_30115108;
        if (*param_2 == 0) {
          uVar4 = DAT_3011510c;
        }
      }
      else {
        uVar4 = *DAT_30114fc8;
      }
      printErr(uVar4,param_10);
      uVar4 = 0xffffffff;
    }
    else if (iVar1 == DAT_30115104) {
      uVar5 = DAT_30115118;
      if (param_9 == 0) {
        uVar5 = *DAT_3011511c;
      }
      printErr(uVar5,param_10,iVar1,param_4,param_8,iVar3,uVar4,param_5,param_7,puVar6);
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = 0xffffffff;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * FUN_3011423c @ 0x3011423C  (примерный размер ~280 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 4
 * Вызывает: abs, cplusDemangle, free, symByValueAndTypeFind
 * Вызывают: FUN_30115590, dbgBpListPrint
 * Константы: 0x3011423C
 * Данные: DAT_30115124, DAT_30115128, DAT_3011512c, DAT_30115210, DAT_30115214, DAT_30115218, DAT_3011521c, DAT_30115220
 * ---------------------------------------------------------------- */
void FUN_3011423c(undefined4 param_1,int param_2,int param_3,int param_4)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int __x;
  code *pcVar6;
  undefined1 auStack_128 [4];
  void *local_124;
  int iStack_120;
  undefined1 auStack_11c [260];
  
  local_124 = (void *)0x0;
  pcVar6 = DAT_30115124;
  if (param_2 == 2) {
    pcVar6 = DAT_30115128;
  }
  (*pcVar6)(param_1,DAT_3011512c,param_3);
  __x = 0;
  if ((param_4 != 0) &&
     (iVar2 = symByValueAndTypeFind(param_4,param_3,&local_124,&iStack_120,auStack_128,0,0),
     iVar2 == 0)) {
    __x = param_3 - iStack_120;
  }
  pvVar1 = local_124;
  uVar5 = DAT_30115220;
  if (((local_124 != (void *)0x0) && (uVar3 = abs(__x), uVar5 = DAT_30115220, uVar3 < DAT_30115210))
     && (uVar4 = cplusDemangle(pvVar1,auStack_11c,0x100), uVar5 = DAT_30115214, __x != 0)) {
    (*pcVar6)(param_1,DAT_30115218,uVar4);
    uVar5 = DAT_3011521c;
  }
  (*pcVar6)(param_1,uVar5);
  free(local_124);
  return;
}

/* ----------------------------------------------------------------
 * dbgBpListPrint @ 0x30114354  (примерный размер ~580 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_3011423c, lstFirst, lstNext, printf, puts, shellInternalSymTblFromRtpGet, taskTcb
 * Вызывают: FUN_30114598
 * Константы: 0x30114354
 * Данные: DAT_30114fd0, DAT_30115224, DAT_30115228, DAT_301152fc, DAT_30115300, DAT_30115304, DAT_30115308, DAT_3011530c
 * ---------------------------------------------------------------- */
undefined4 dbgBpListPrint(int *param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  bVar2 = true;
  iVar3 = lstFirst(DAT_30115228);
  if (iVar3 != 0) {
    do {
      iVar6 = *param_1;
      if ((((iVar6 == 0) || (iVar5 = *(int *)(iVar3 + 0x14), iVar5 == 0)) ||
          (((param_1[1] & 1U) != 0 && (((*(uint *)(iVar3 + 0x18) & 1) != 0 && (iVar5 == iVar6))))))
         || (((param_1[1] & 2U) != 0 &&
             ((((*(uint *)(iVar3 + 0x18) & 2) != 0 && (iVar5 == iVar6)) ||
              (((*(uint *)(iVar3 + 0x18) & 1) != 0 && (*(int *)(iVar5 + 0x94) == iVar6)))))))) {
        if (bVar2) {
          if (param_2 == 0) {
            printf(DAT_301152fc);
          }
          puts(DAT_30115300);
          if (param_2 == 0) {
            printf(DAT_30115304);
          }
          puts(DAT_30115308);
        }
        if (param_2 == 0) {
          printf(DAT_3011530c,*(undefined4 *)(iVar3 + 8));
        }
        iVar6 = *(int *)(iVar3 + 0x14);
        if (iVar6 == 0) {
          uVar7 = *DAT_30115310;
        }
        else {
          iVar5 = iVar6;
          if (((*(uint *)(iVar3 + 0x18) & 2) == 0) &&
             (iVar5 = 0, (*(uint *)(iVar3 + 0x18) & 1) != 0)) {
            iVar6 = taskTcb(iVar6);
            iVar5 = *(int *)(iVar6 + 0x94);
          }
          uVar7 = shellInternalSymTblFromRtpGet(iVar5,*(undefined4 *)(iVar3 + 0xc));
        }
        FUN_3011423c(0,1,*(undefined4 *)(iVar3 + 0xc),uVar7);
        iVar5 = *(int *)(iVar3 + 0x14);
        pcVar4 = DAT_30115314;
        uVar7 = DAT_30115318;
        iVar6 = DAT_3011531c;
        if (((iVar5 == 0) ||
            (pcVar4 = DAT_30115328, uVar7 = DAT_30115320, iVar6 = iVar5,
            (*(uint *)(iVar3 + 0x18) & 1) != 0)) ||
           (uVar7 = DAT_30115324, (*(uint *)(iVar3 + 0x18) & 2) != 0)) {
          printf(pcVar4,uVar7,iVar6,*(undefined4 *)(iVar3 + 0x24));
        }
        pcVar4 = DAT_3011532c;
        if (((*(uint *)(iVar3 + 0x2c) & 4) == 0) &&
           (pcVar4 = DAT_30115330, (*(uint *)(iVar3 + 0x2c) & 0x10) == 0)) {
          pcVar4 = DAT_30115334;
        }
        printf(pcVar4);
        pcVar4 = DAT_30115338;
        if ((*(uint *)(iVar3 + 0x2c) & 2) == 0) {
          pcVar4 = DAT_3011533c;
        }
        printf(pcVar4);
        printf(DAT_30115340);
        pcVar4 = DAT_301153fc;
        if (((*(int *)(iVar3 + 0x1c) != *DAT_30114fd0) ||
            (bVar1 = *(byte *)(iVar3 + 0x22), pcVar4 = DAT_30115400, (bVar1 & 2) == 2)) ||
           ((pcVar4 = DAT_30115404, (bVar1 & 4) == 4 || (pcVar4 = DAT_30115408, (bVar1 & 1) == 1))))
        {
          printf(pcVar4);
        }
        bVar2 = false;
        puts(DAT_30115224);
      }
      iVar3 = lstNext(iVar3);
    } while (iVar3 != 0);
    if (!bVar2) {
      return 0;
    }
  }
  puts(DAT_3011540c);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30114598 @ 0x30114598  (примерный размер ~244 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 4
 * Вызывает: dbgBpEpCoreRtn, dbgBpListPrint, printErr, taskIdFigure
 * Вызывают: FUN_3011468c, bh
 * Константы: 0xFFFFFFFF, 0x30114598
 * Данные: DAT_30115410, DAT_30115538
 * ---------------------------------------------------------------- */
undefined4
FUN_30114598(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6,
            int param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int local_2c [2];
  
  local_2c[0] = 0;
  if (param_2 != 0) {
    local_2c[0] = taskIdFigure(param_2);
  }
  uVar2 = 0;
  if (local_2c[0] == -1) {
    printErr(*DAT_30115410,param_9);
    uVar2 = 0xffffffff;
  }
  else {
    local_2c[1] = 1;
    if (param_1 == 0) {
      dbgBpListPrint(local_2c,1);
      uVar2 = 0;
    }
    else if (param_7 == 0) {
      if (param_6 == 0) {
        if (param_5 == 0) {
          uVar1 = 6;
        }
        else {
          uVar1 = 1;
          uVar2 = 2;
        }
      }
      else {
        uVar1 = 4;
      }
      uVar2 = dbgBpEpCoreRtn(param_1,local_2c,0,uVar1,uVar2,0,param_3,param_4,param_5,param_9);
    }
    else {
      printErr(DAT_30115538,param_9);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3011468c @ 0x3011468C  (примерный размер ~104 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_30114598, shellOutputLock, shellOutputUnlock
 * Константы: 0x3011468C
 * Данные: DAT_3011553c
 * ---------------------------------------------------------------- */
undefined4 FUN_3011468c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  shellOutputLock(0);
  uVar1 = FUN_30114598(param_1,param_2,param_3,0,0,param_4,0,0,DAT_3011553c);
  shellOutputUnlock(0);
  return uVar1;
}

/* ----------------------------------------------------------------
 * dbgDisassemble @ 0x30115178  (примерный размер ~460 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_30114ebc, FUN_301150d4, __errno, errnoGet, errnoSet, printErr, shellDataAdd, shellDataGet
 * Константы: 0x30115178, 0xFFFFFFFF, 0xFFFFFFFC
 * Данные: DAT_30116048, DAT_3011604c, DAT_30116050, DAT_30116054, DAT_30116158
 * ---------------------------------------------------------------- */
undefined4 dbgDisassemble(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  uint local_8;
  int local_4;
  
  local_8 = param_1;
  local_4 = param_2;
  uVar3 = errnoGet();
  iVar1 = DAT_30116048;
  uVar2 = local_8;
  if (((local_8 == 0) &&
      (iVar4 = shellDataGet(0,*(undefined4 *)(DAT_30116048 + 0x14),&local_8), uVar2 = local_8,
      iVar4 != 0)) &&
     ((piVar5 = (int *)__errno(), *piVar5 == DAT_3011604c ||
      (uVar2 = *(uint *)(iVar1 + 0x1c), *(uint *)(iVar1 + 0x1c) == DAT_30116050)))) {
    errnoSet(uVar3);
    printErr(DAT_30116054,param_4);
    uVar3 = 0xffffffff;
  }
  else {
    local_8 = uVar2;
    iVar1 = DAT_30116048;
    if (((local_4 != 0) &&
        (iVar4 = shellDataAdd(0,*(undefined4 *)(DAT_30116048 + 0x20),local_4,0), iVar4 != 0)) &&
       (piVar5 = (int *)__errno(), *piVar5 == DAT_30116158)) {
      *(int *)(iVar1 + 0x2c) = local_4;
    }
    iVar4 = shellDataGet(0,*(undefined4 *)(iVar1 + 0x20),&local_4);
    if (iVar4 != 0) {
      local_4 = *(int *)(iVar1 + 0x2c);
      errnoSet(uVar3);
    }
    local_8 = local_8 & 0xfffffffc;
    uVar3 = FUN_30114ebc(0,local_8,local_4,param_3,param_4);
    FUN_301150d4(0,uVar3);
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * dbgStackTrace @ 0x30115344  (примерный размер ~412 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 10
 * Вызывает: printErr, taskCont, taskIdSelf, taskIdVerify, taskIsStopped, taskIsSuspended, taskRegsGet, taskStop, taskTcb, trcStack
 * Вызывают: dbgTaskTraceCoreRtn
 * Константы: 0xFFFFFFFF, 0x30115344
 * Данные: DAT_30116048, DAT_30116160, DAT_30116164, DAT_30116168, DAT_3011616c, DAT_30116170, DAT_30116174
 * ---------------------------------------------------------------- */
undefined4 dbgStackTrace(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_5c [72];
  
  bVar1 = false;
  iVar4 = 0;
  if ((param_1 == 0) || (iVar2 = taskIdSelf(), iVar2 == param_1)) {
    printErr(DAT_30116160,param_2);
    uVar3 = 0xffffffff;
  }
  else {
    iVar2 = taskIdVerify(param_1);
    if (iVar2 == 0) {
      iVar2 = taskIsStopped(param_1);
      if ((iVar2 == 0) && (iVar2 = taskIsSuspended(param_1), iVar2 == 0)) {
        iVar2 = taskStop(param_1);
        if (iVar2 != 0) {
          if ((*(uint *)(param_1 + 0x98) & 2) == 0) {
            printErr(DAT_30116168,param_2,param_1);
          }
          else {
            printErr(DAT_30116164,param_2);
          }
          return 0xffffffff;
        }
        bVar1 = true;
      }
      taskRegsGet(param_1,auStack_5c);
      if (*DAT_3011616c != 0) {
        iVar4 = taskTcb(param_1);
        iVar4 = (*(code *)*DAT_3011616c)(*(undefined4 *)(iVar4 + 0x94),0);
        if (iVar4 == 0) {
          printErr(DAT_30116170,param_2,param_1);
          return 0xffffffff;
        }
      }
      trcStack(auStack_5c,DAT_30116174,param_1);
      if ((code *)*DAT_3011616c != (code *)0x0) {
        (*(code *)*DAT_3011616c)(iVar4,0);
      }
      if (bVar1) {
        taskCont(param_1);
      }
      uVar3 = 0;
    }
    else {
      printErr(*DAT_30116048,param_2,param_1);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * dbgTaskTraceCoreRtn @ 0x301154E0  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: dbgStackTrace, shellTaskIdDefault
 * Вызывают: tt
 * Константы: 0x301154E0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 dbgTaskTraceCoreRtn(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = dbgStackTrace();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  shellTaskIdDefault(0,param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * dbgCallPrint @ 0x30115AA4  (примерный размер ~708 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: cplusDemangle, free, printErr, shellInternalSymTblFromTaskGet, symByValueAndTypeFind
 * Константы: 0x30115AA4
 * Данные: DAT_301161b4, DAT_301161b8, DAT_301161bc, DAT_301161c0, DAT_301161c4, DAT_301161c8, DAT_301161cc, DAT_301161d0
 * ---------------------------------------------------------------- */
void dbgCallPrint(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined1 auStack_130 [4];
  void *local_12c;
  int local_128;
  undefined1 auStack_124 [260];
  
  printErr(DAT_301161b4,param_1);
  if (param_6 == 0) {
    iVar2 = shellInternalSymTblFromTaskGet(param_5,param_1);
  }
  else {
    iVar2 = *DAT_301161b8;
  }
  local_12c = (void *)0x0;
  if ((iVar2 == 0) ||
     (iVar2 = symByValueAndTypeFind(iVar2,param_1,&local_12c,&local_128,auStack_130,0,0), iVar2 != 0
     )) {
    printErr(DAT_301161c4);
  }
  else {
    uVar3 = cplusDemangle(local_12c,auStack_124,DAT_301161bc);
    printErr(DAT_301161c0,uVar3,param_1 - local_128);
  }
  free(local_12c);
  local_12c = (void *)0x0;
  if (param_6 == 0) {
    iVar2 = shellInternalSymTblFromTaskGet(param_5,param_2);
  }
  else {
    iVar2 = *DAT_301161b8;
  }
  uVar3 = DAT_301161cc;
  if (((iVar2 != 0) &&
      (iVar2 = symByValueAndTypeFind(iVar2,param_2,&local_12c,&local_128,auStack_130,0,0),
      uVar3 = DAT_301161cc, iVar2 == 0)) && (local_128 == param_2)) {
    param_2 = cplusDemangle(local_12c,auStack_124,DAT_301161bc);
    uVar3 = DAT_301161c8;
  }
  printErr(uVar3,param_2);
  free(local_12c);
  bVar1 = false;
  local_12c = (void *)0x0;
  if ((param_3 == 0) && (iVar2 = *DAT_301161d0, iVar2 != 0)) {
    bVar1 = true;
    printErr(DAT_301161d4);
    param_3 = iVar2;
  }
  if (param_6 == 0) {
    iVar2 = shellInternalSymTblFromTaskGet(param_5,0);
  }
  else {
    iVar2 = *DAT_301161b8;
  }
  iVar6 = 0;
  if (0 < param_3) {
    piVar5 = (int *)(param_4 + -4);
    do {
      if (0 < iVar6) {
        printErr(DAT_301161d8);
      }
      piVar5 = piVar5 + 1;
      if (*piVar5 == 0) {
        printErr(DAT_301161dc);
      }
      else {
        if (((iVar2 == 0) ||
            (iVar4 = symByValueAndTypeFind(iVar2,*piVar5,&local_12c,&local_128,auStack_130,0,0),
            iVar4 != 0)) || (*piVar5 != local_128)) {
          iVar4 = *piVar5;
          uVar3 = DAT_301161e4;
        }
        else {
          iVar4 = cplusDemangle(local_12c,auStack_124,4);
          uVar3 = DAT_301161e0;
        }
        printErr(uVar3,iVar4);
      }
      free(local_12c);
      local_12c = (void *)0x0;
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_3);
  }
  if (bVar1) {
    printErr(DAT_301161e8);
  }
  printErr(DAT_301161ec);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30115d68 @ 0x30115D68  (примерный размер ~592 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 7
 * Вызывает: memcpy, snprintf, taskIdSelf, vxdbgBpMsgDrop, vxdbgBpMsgGet, vxdbgBpMsgPost, vxdbgBpMsgQHdlrIsRunning
 * Константы: 0x30115D68
 * Данные: DAT_30116048, DAT_301161f0
 * ---------------------------------------------------------------- */
void FUN_30115d68(uint *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *__s;
  uint uVar4;
  size_t __n;
  undefined1 uVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar8 = 0;
  uVar2 = taskIdSelf();
  iVar1 = DAT_30116048;
  iVar3 = vxdbgBpMsgQHdlrIsRunning(*(undefined4 *)(DAT_30116048 + 4));
  if ((iVar3 == 0) && (__s = (char *)vxdbgBpMsgGet(*(undefined4 *)(iVar1 + 4)), __s != (char *)0x0))
  {
    uVar6 = 0;
    puVar7 = param_1;
    if (*param_1 != 0) {
      do {
        uVar4 = puVar7[2];
        uVar5 = 0;
        if (((uVar4 == 0) || (uVar4 == 5)) || (uVar4 == 1)) {
          __n = 4;
        }
        else if (uVar4 == 2) {
          __n = 8;
        }
        else {
          if (uVar4 != 6) {
            vxdbgBpMsgDrop(*(undefined4 *)(iVar1 + 4));
            return;
          }
          __n = 2;
        }
        memcpy(&local_38,(void *)puVar7[3],__n);
        if (uVar6 + 1 < *param_1) {
          uVar5 = *(undefined1 *)puVar7[7];
          *(undefined1 *)puVar7[7] = 0;
        }
        if (puVar7[2] == 0) {
          iVar3 = snprintf(__s + iVar8,100 - iVar8,(char *)puVar7[4],local_38);
          iVar8 = iVar3 + iVar8;
        }
        if (puVar7[2] == 6) {
          iVar3 = snprintf(__s + iVar8,100 - iVar8,(char *)puVar7[4],(int)(short)local_38);
          iVar8 = iVar3 + iVar8;
        }
        uVar4 = puVar7[2];
        if (uVar4 == 5) {
          iVar3 = snprintf(__s + iVar8,100 - iVar8,(char *)puVar7[4],local_38);
LAB_30115f10:
          iVar8 = iVar3 + iVar8;
        }
        else {
          if (uVar4 == 1) {
            iVar3 = snprintf(__s + iVar8,100 - iVar8,(char *)puVar7[4],local_38);
            goto LAB_30115f10;
          }
          if (uVar4 == 2) {
            local_30 = local_38;
            local_2c = local_34;
            iVar3 = snprintf(__s + iVar8,100 - iVar8,(char *)puVar7[4],local_38,local_34);
            goto LAB_30115f10;
          }
        }
        if (uVar6 + 1 < *param_1) {
          *(undefined1 *)puVar7[7] = uVar5;
        }
        __s[99] = '\0';
        if (100U - iVar8 < 2) break;
        uVar6 = uVar6 + 1;
        puVar7 = puVar7 + 3;
      } while (uVar6 < *param_1);
    }
    if (*param_1 == 0) {
      snprintf(__s,100,(char *)param_1[1]);
    }
    iVar3 = 1;
    if (*DAT_301161f0 != 0) {
      iVar3 = (uint)(*DAT_301161f0 == 1) << 1;
    }
    vxdbgBpMsgPost(*(undefined4 *)(iVar1 + 4),iVar3,uVar2,*(undefined4 *)(param_2 + 0x3c));
  }
  return;
}

/* ----------------------------------------------------------------
 * dbgDynPrintfCommonRtn @ 0x30115FB8  (примерный размер ~1248 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 10
 * Вызывает: calloc, dbgBpEpCoreRtn, free, semGive, semTake, shellMemStringFree, shellPrintErr, strcpy, strlen, vxdbgBpMsgQCreate
 * Вызывают: dprintf, hdprintf
 * Константы: 0xFFFFFFFF, 0x30115FB8, 0x30116414, 0x30116418, 0x301160E4, 0xFFFFFFFC, 0x30116154
 * Данные: DAT_30116048, DAT_301161f4, DAT_301161f8, DAT_301161fc, DAT_30116204, DAT_3011663c, DAT_30116640
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x30116414) */
/* WARNING: Removing unreachable block (ram,0x30116418) */
/* WARNING: Removing unreachable block (ram,0x301160e4) */

int dbgDynPrintfCommonRtn
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,char *param_7,int param_8,undefined4 param_9)

{
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  undefined4 *__ptr;
  char *pcVar5;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar1 = DAT_301161f4;
  __ptr = (undefined4 *)0x0;
  local_c = param_2;
  local_8 = param_3;
  local_4 = param_4;
  semTake(DAT_301161f4,0xffffffff);
  iVar4 = DAT_30116048;
  if (*(int *)(DAT_30116048 + 4) == 0) {
    iVar2 = vxdbgBpMsgQCreate(100,100,DAT_301161f8);
    *(int *)(iVar4 + 4) = iVar2;
    if (iVar2 != 0) goto LAB_30116058;
    shellPrintErr(0,DAT_301161fc,param_9);
    semGive(uVar1);
  }
  else {
LAB_30116058:
    semGive(uVar1);
    sVar3 = strlen(param_7);
    __ptr = (undefined4 *)calloc(1,sVar3 + 0x69);
    if (__ptr == (undefined4 *)0x0) {
      shellPrintErr(0,DAT_301161fc,param_9);
    }
    else {
      __ptr[1] = __ptr + 0x1a;
      strcpy((char *)(__ptr + 0x1a),param_7);
      pcVar5 = (char *)__ptr[1];
      if (*pcVar5 != '\0') {
        do {
          if (*pcVar5 == '%') break;
          pcVar5 = pcVar5 + 1;
        } while (*pcVar5 != '\0');
        if (*pcVar5 != '\0') {
          __ptr[3] = *(undefined4 *)((param_8 + 7U & 0xfffffffc) - 4);
          __ptr[2] = 0xffffffff;
          __ptr[4] = pcVar5;
          if ((byte)pcVar5[1] - 0x23 < 0x56) {
                    /* WARNING: Could not recover jumptable at 0x30116154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            iVar4 = (**(code **)(DAT_30116204 + ((byte)pcVar5[1] - 0x23) * 4))();
            return iVar4;
          }
          pcVar5[2] = '\0';
          shellPrintErr(0,DAT_3011663c,param_9,__ptr[4]);
          goto LAB_30116464;
        }
      }
      *__ptr = 0;
      iVar4 = dbgBpEpCoreRtn(param_1,&local_c,param_5,1,4,local_4,param_6,DAT_30116640,__ptr,param_9
                            );
      if (iVar4 == 0) goto LAB_30116478;
    }
  }
LAB_30116464:
  iVar4 = -1;
  if (__ptr != (undefined4 *)0x0) {
    free(__ptr);
  }
LAB_30116478:
  shellMemStringFree(0,param_7);
  return iVar4;
}

/* ----------------------------------------------------------------
 * ioHelp @ 0x3011AD80  (примерный размер ~300 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: __rem32, printf, puts, read
 * Константы: 0x3011AD80
 * Данные: DAT_3011aea0, DAT_3011aea4, DAT_3011aea8
 * ---------------------------------------------------------------- */
void ioHelp(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char local_10 [4];
  
  puts(DAT_3011aea0);
  iVar2 = 0;
  iVar3 = *DAT_3011aea4;
  piVar1 = DAT_3011aea4;
  while (iVar3 != 0) {
    iVar3 = __rem32(iVar2 + 1,0x14);
    if (iVar3 == 0) {
      printf(DAT_3011aea8);
      read(0,local_10,1);
      if ((local_10[0] == 'q') || (local_10[0] == 'Q')) break;
      puts(DAT_3011aea0);
    }
    puts((char *)*piVar1);
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + 1;
    iVar3 = *piVar1;
  }
  puts(DAT_3011aea0);
  return;
}

/* ----------------------------------------------------------------
 * taskIdFigure @ 0x3011AFDC  (примерный размер ~140 байт)
 * Модуль: kernel | Вызывают: 33 | Вызывает: 5
 * Вызывает: shellTaskIdDefault, sprintf, taskIdVerify, taskNameToId, vxMemProbe
 * Вызывают: FUN_30114598, FUN_30114978, FUN_3011b068, FUN_3011b4e0, FUN_3011b934, bd, bdall, cpsr, dprintf, hdprintf
 *           ...
 * Константы: 0x3011AFDC
 * Данные: DAT_3011bf94
 * ---------------------------------------------------------------- */
int taskIdFigure(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_18 [4];
  char acStack_14 [12];
  
  if (param_1 == 0) {
    iVar1 = shellTaskIdDefault(0,0);
  }
  else {
    iVar2 = taskIdVerify(param_1);
    iVar1 = param_1;
    if (iVar2 != 0) {
      sprintf(acStack_14,DAT_3011bf94,param_1);
      iVar1 = taskNameToId(acStack_14);
      if (iVar1 == -1) {
        iVar1 = vxMemProbe(param_1,0,1,auStack_18);
        if (iVar1 == 0) {
          iVar1 = taskNameToId(param_1);
        }
        else {
          iVar1 = -1;
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3011b068 @ 0x3011B068  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: printErr, shellTaskIdDefault, taskIdFigure, taskIdVerify, taskWaitShowCoreRtn
 * Константы: 0x3011B068
 * Данные: DAT_3011bf98, DAT_3011bf9c
 * ---------------------------------------------------------------- */
void FUN_3011b068(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1;
  iVar2 = 0;
  if (param_1 != 0) {
    iVar1 = taskIdFigure();
    if ((iVar1 == -1) || (iVar2 = taskIdVerify(iVar1), iVar2 != 0)) {
      printErr(*DAT_3011bf98,DAT_3011bf98[5]);
      return;
    }
    iVar1 = shellTaskIdDefault(0,iVar1);
    iVar2 = iVar1;
  }
  if (param_1 != 0) {
    iVar1 = 0;
  }
  if (param_1 == 0) {
    iVar1 = 1;
  }
  taskWaitShowCoreRtn(iVar1,0,iVar2,*DAT_3011bf9c);
  return;
}

/* ----------------------------------------------------------------
 * memoryModify @ 0x3011BDE8  (примерный размер ~976 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 12
 * Вызывает: FUN_3011bc2c, __errno, errnoGet, errnoSet, fioRdString, printErr, printf, puts, shellDataAdd, shellDataGet, vxdbgMemRead, vxdbgMemWrite
 * Константы: 0x3011BDE8, 0xFFFFFFFF
 * Данные: DAT_3011bf98, DAT_3011cb00, DAT_3011ccb0, DAT_3011ccb4, DAT_3011ccb8, DAT_3011ccbc, DAT_3011ccc0, DAT_3011ccc4
 * ---------------------------------------------------------------- */
undefined4 memoryModify(ushort *param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 unaff_r10;
  ushort *puVar8;
  byte *pbVar9;
  undefined1 local_ac [2];
  undefined2 uStack_aa;
  int local_a8;
  int local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  ushort local_94 [6];
  undefined4 local_88;
  undefined4 local_84;
  byte local_7c;
  byte local_7b [79];
  undefined1 local_2c;
  ushort *local_8;
  int local_4;
  
  local_8 = param_1;
  local_4 = param_2;
  uVar3 = errnoGet();
  puVar8 = local_8;
  if (((local_8 == (ushort *)0x0) &&
      (iVar4 = shellDataGet(0,DAT_3011ccb0,&local_8), puVar8 = local_8, iVar4 != 0)) &&
     ((piVar5 = (int *)__errno(), *piVar5 == DAT_3011ccb4 ||
      (puVar8 = (ushort *)*DAT_3011ccb8, (ushort *)*DAT_3011ccb8 == DAT_3011ccbc)))) {
    errnoSet(uVar3);
    printErr(DAT_3011ccc0,param_3);
    return 0xffffffff;
  }
  local_8 = puVar8;
  local_a8 = DAT_3011bf98;
  local_a4 = DAT_3011bf98;
  if (local_4 != 0) {
    if ((((local_4 != 1) && (local_4 != 2)) && (local_4 != 4)) && (local_4 != 8)) {
      printf(DAT_3011ccc4,local_4);
      local_4 = 1;
    }
    if (((local_4 != 0) && (iVar4 = shellDataAdd(0,DAT_3011cd68,local_4,0), iVar4 != 0)) &&
       (piVar5 = (int *)__errno(), *piVar5 == DAT_3011cd6c)) {
      *(int *)(local_a4 + 0x18) = local_4;
    }
  }
  iVar4 = shellDataGet(0,DAT_3011cd68,&local_4);
  if (iVar4 != 0) {
    errnoSet(uVar3);
    local_4 = *(int *)(local_a8 + 0x18);
  }
  iVar2 = DAT_3011cd70;
  local_8 = (ushort *)((uint)local_8 & ~(local_4 - 1U));
  iVar4 = local_4 << 1;
  do {
    puVar8 = local_8;
    if (*(int *)(iVar2 + 0xc) != 0) {
      vxdbgMemRead(local_8,local_94,local_4,local_4);
      puVar8 = local_94;
    }
    if (local_4 == 1) {
      printf(DAT_3011ceb8,local_8,(uint)(byte)*puVar8);
    }
    else if (local_4 == 2) {
      printf(DAT_3011cebc,local_8,(uint)*puVar8);
    }
    else if (local_4 == 4) {
      printf(DAT_3011cec0,local_8,*(undefined4 *)puVar8);
    }
    else if (local_4 == 8) {
      printf(DAT_3011cec4,local_8,*(undefined4 *)puVar8,*(undefined4 *)(puVar8 + 2));
    }
    else {
      printf(DAT_3011ceb8,local_8,(uint)(byte)*puVar8);
      iVar4 = 2;
    }
    iVar6 = fioRdString(0,&local_7c,0x50);
    if (iVar6 == -1) goto LAB_3011c174;
    local_2c = 0;
    pbVar9 = &local_7c;
    bVar1 = *(byte *)(*DAT_3011cb00 + (uint)local_7c);
    while ((bVar1 & 0x28) != 0) {
      pbVar9 = pbVar9 + 1;
      bVar1 = *(byte *)(*DAT_3011cb00 + (uint)*pbVar9);
    }
    local_a0 = unaff_r10;
    if (*pbVar9 != 0) {
      iVar6 = FUN_3011bc2c(pbVar9,0,0,&local_9c,&local_a0,iVar4);
      if (iVar6 != 0) {
LAB_3011c174:
        puts(DAT_3011cfe8);
        shellDataAdd(0,DAT_3011ccb0,local_8,0);
        *(ushort **)(local_a4 + 0xc) = local_8;
        return 0;
      }
      if (local_4 == 1) {
LAB_3011c150:
        local_ac[0] = (undefined1)local_a0;
        puVar7 = (undefined4 *)local_ac;
      }
      else if (local_4 == 2) {
        uStack_aa = (undefined2)local_a0;
        puVar7 = (undefined4 *)&uStack_aa;
      }
      else if (local_4 == 4) {
        uStack_98 = local_a0;
        puVar7 = &uStack_98;
      }
      else {
        if (local_4 != 8) goto LAB_3011c150;
        puVar7 = &local_88;
        local_88 = local_a0;
        local_84 = local_9c;
      }
      vxdbgMemWrite(puVar7,local_8);
    }
    local_8 = (ushort *)((int)local_8 + local_4);
    unaff_r10 = local_a0;
  } while( true );
}

/* ----------------------------------------------------------------
 * memoryDump @ 0x3011C1B8  (примерный размер ~1512 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 13
 * Вызывает: __div32, __errno, bfill, errnoGet, errnoSet, free, memalign, printErr, printf, puts, shellDataAdd, shellDataGet, vxdbgMemRead
 * Вызывают: FUN_3011c7a0
 * Константы: 0xFFFFFFFF, 0x3011C1B8, 0xFFFFFFF0
 * Данные: DAT_3011cb00, DAT_3011ccb4, DAT_3011ccbc, DAT_3011ccc0, DAT_3011ccc4, DAT_3011cd6c, DAT_3011cd70, DAT_3011cff0
 * ---------------------------------------------------------------- */
undefined4 memoryDump(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  char *__format;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  uint *__ptr;
  uint *puVar10;
  int iVar11;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  byte abStack_44 [16];
  undefined1 local_34;
  uint *local_c;
  int local_8;
  int local_4;
  
  __ptr = (uint *)0x0;
  iVar11 = 0;
  local_34 = 0;
  local_c = param_1;
  local_8 = param_2;
  local_4 = param_3;
  uVar3 = errnoGet();
  puVar10 = local_c;
  if (((local_c == (uint *)0x0) &&
      (iVar4 = shellDataGet(0,DAT_3011cff0,&local_c), puVar10 = local_c, iVar4 != 0)) &&
     ((piVar5 = (int *)__errno(), *piVar5 == DAT_3011ccb4 ||
      (puVar10 = (uint *)*DAT_3011d09c, (uint *)*DAT_3011d09c == DAT_3011ccbc)))) {
    errnoSet(uVar3);
    printErr(DAT_3011ccc0,param_4);
    uVar3 = 0xffffffff;
  }
  else {
    local_c = puVar10;
    if ((((local_4 != 0) && (local_4 != 1)) && (local_4 != 2)) && ((local_4 != 4 && (local_4 != 8)))
       ) {
      printf(DAT_3011ccc4,local_4);
      local_4 = 1;
    }
    if (local_8 < 0) {
      printErr(DAT_3011d17c,param_4);
      uVar3 = 0xffffffff;
    }
    else {
      if (((local_4 != 0) && (iVar4 = shellDataAdd(0,DAT_3011d180,local_4,0), iVar4 != 0)) &&
         (piVar5 = (int *)__errno(), *piVar5 == DAT_3011cd6c)) {
        *DAT_3011d184 = local_4;
      }
      iVar4 = shellDataGet(0,DAT_3011d180,&local_4);
      if (iVar4 != 0) {
        errnoSet(uVar3);
        local_4 = *DAT_3011d184;
      }
      if (((local_8 != 0) && (iVar4 = shellDataAdd(0,DAT_3011d188,local_8,0), iVar4 != 0)) &&
         (piVar5 = (int *)__errno(), *piVar5 == DAT_3011cd6c)) {
        *DAT_3011d18c = local_8;
      }
      iVar4 = shellDataGet(0,DAT_3011d188,&local_8);
      if (iVar4 != 0) {
        errnoSet(uVar3);
        local_8 = *DAT_3011d18c;
      }
      local_c = (uint *)((uint)local_c & ~(local_4 - 1U));
      bfill(abStack_44,0x10,0x2e);
      puts(DAT_3011d2bc);
      printf(DAT_3011d2c0,(uint)local_c & 0xfffffff0);
      iVar4 = 0;
      iVar6 = __div32((uint)local_c & 0xf,local_4);
      if (0 < iVar6) {
        do {
          printf(DAT_3011d2c4,local_4 << 1,DAT_3011d2c8);
          bfill(abStack_44 + iVar4 * local_4,local_4 << 1,0x20);
          iVar4 = iVar4 + 1;
          iVar6 = __div32((uint)local_c & 0xf,local_4);
        } while (iVar4 < iVar6);
      }
      iVar1 = DAT_3011cd70;
      puVar10 = local_c;
      iVar6 = DAT_3011d3b4;
      if (*(int *)(DAT_3011cd70 + 0xc) != 0) {
        iVar11 = *DAT_3011d18c;
        if (local_8 <= iVar11) {
          iVar11 = local_8;
        }
        iVar11 = local_4 * iVar11;
        __ptr = (uint *)memalign(8,iVar11);
        if (__ptr == (uint *)0x0) {
          printErr(DAT_3011d2cc,param_4);
          return 0xffffffff;
        }
        vxdbgMemRead(local_c,__ptr,iVar11,local_4);
        puVar10 = __ptr;
        iVar6 = DAT_3011d3b4;
      }
      for (; iVar2 = DAT_3011d3b4, DAT_3011d3b4 = iVar6, 0 < local_8; local_8 = local_8 + -1) {
        iVar6 = __div32(0x10,local_4);
        if (iVar6 == iVar4) {
          printf(DAT_3011d3b8,abStack_44,local_c);
          bfill(abStack_44,0x10,0x2e);
          iVar4 = 0;
        }
        if ((*(int *)(iVar1 + 0xc) != 0) && (iVar11 == 0)) {
          iVar11 = local_8;
          if (*(int *)(iVar2 + 4) < local_8) {
            iVar11 = *(int *)(iVar2 + 4);
          }
          iVar11 = local_4 * iVar11;
          vxdbgMemRead(local_c,__ptr,iVar11,local_4);
          puVar10 = __ptr;
        }
        if (local_4 == 2) {
          local_54 = (uint)(ushort)*puVar10;
          __format = DAT_3011d480;
LAB_3011c65c:
          local_50 = 0;
          printf(__format,local_54);
        }
        else {
          if (local_4 == 4) {
            local_54 = *puVar10;
            __format = DAT_3011d484;
            goto LAB_3011c65c;
          }
          if (local_4 != 8) {
            local_54 = (uint)(byte)*puVar10;
            __format = DAT_3011d48c;
            goto LAB_3011c65c;
          }
          local_54 = *puVar10;
          local_50 = puVar10[1];
          local_4c = local_54;
          local_48 = local_50;
          printf(DAT_3011d488);
        }
        printf(DAT_3011d2c8);
        iVar6 = local_4;
        puVar7 = &local_54;
        iVar9 = 0;
        if (0 < local_4) {
          do {
            uVar8 = (uint)(byte)*puVar7;
            if ((uVar8 == 0x20) ||
               ((uVar8 < 0x80 && ((*(byte *)(*DAT_3011cb00 + uVar8) & 0x1f) != 0)))) {
              abStack_44[iVar4 * iVar6 + iVar9] = (byte)*puVar7;
            }
            puVar7 = (uint *)((int)puVar7 + 1);
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar6);
        }
        iVar4 = iVar4 + 1;
        local_c = (uint *)((int)local_c + iVar6);
        iVar11 = iVar11 - iVar6;
        puVar10 = (uint *)((int)puVar10 + iVar6);
        iVar6 = DAT_3011d3b4;
        DAT_3011d3b4 = iVar2;
      }
      iVar11 = __div32(0x10,local_4);
      if (iVar4 < iVar11) {
        do {
          printf(DAT_3011d2c4,local_4 << 1,DAT_3011d2c8);
          iVar4 = iVar4 + 1;
          iVar11 = __div32(0x10,local_4);
        } while (iVar4 < iVar11);
      }
      printf(DAT_3011d5dc,abStack_44);
      shellDataAdd(0,DAT_3011cff0,local_c,0);
      *(uint **)(iVar2 + 0x10) = local_c;
      if (*(int *)(iVar1 + 0xc) != 0) {
        free(__ptr);
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_3011c7a0 @ 0x3011C7A0  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: memoryDump
 * Вызывают: BSP_OM_MemPrint
 * Константы: 0x3011C7A0
 * ---------------------------------------------------------------- */
void FUN_3011c7a0(void)

{
  memoryDump();
  return;
}

/* ----------------------------------------------------------------
 * usrModuleLoad @ 0x3011C7A8  (примерный размер ~148 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: __errno, loadModule, printErr, shellScriptAbort
 * Вызывают: ld
 * Константы: 0x3011C7A8
 * Данные: DAT_3011d5e4, DAT_3011d5e8, DAT_3011d5ec, DAT_3011d670, DAT_3011d674
 * ---------------------------------------------------------------- */
int usrModuleLoad(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = loadModule();
  if (iVar1 == 0) {
    piVar2 = (int *)__errno();
    if (*piVar2 == DAT_3011d5e4) {
      printErr(DAT_3011d5ec,param_4);
    }
    else if (*piVar2 == DAT_3011d5e8) {
      printErr(DAT_3011d670,param_4);
    }
    else {
      puVar3 = (undefined4 *)__errno();
      printErr(DAT_3011d674,param_4,*puVar3);
    }
    if (param_3 == 0) {
      shellScriptAbort();
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * taskRegsModify @ 0x3011CF28  (примерный размер ~536 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 11
 * Вызывает: changeReg, coprocMRegs, coprocRegListShow, printErr, printf, puts, shellTaskIdDefault, substrcmp, taskIdVerify, taskRegsGet, taskRegsSet
 * Вызывают: mRegs
 * Константы: 0xFFFFFFFF, 0x3011CF28
 * Данные: DAT_3011d3b4, DAT_3011d6c0, DAT_3011d6c4, DAT_3011d6c8, DAT_3011d6cc, DAT_3011d6d0, DAT_3011d6d4
 * ---------------------------------------------------------------- */
undefined4 taskRegsModify(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int local_6c;
  undefined1 auStack_68 [72];
  
  iVar2 = taskIdVerify(param_2);
  if (iVar2 == 0) {
    uVar3 = shellTaskIdDefault(0,param_2);
    iVar2 = taskRegsGet(uVar3,auStack_68);
    piVar5 = DAT_3011d6c4;
    if (iVar2 == 0) {
      if (param_1 == 0) {
        bVar1 = false;
        iVar2 = *DAT_3011d6c4;
        while (iVar2 != 0) {
          iVar2 = changeReg(*piVar5,auStack_68 + piVar5[1],4);
          if (iVar2 == -1) {
            bVar1 = true;
            break;
          }
          piVar5 = piVar5 + 2;
          iVar2 = *piVar5;
        }
        taskRegsSet(uVar3,auStack_68);
        if (!bVar1) {
          uVar3 = coprocMRegs(uVar3,0,&local_6c);
          return uVar3;
        }
      }
      else {
        local_6c = 0;
        iVar2 = *DAT_3011d6c4;
        piVar4 = DAT_3011d6c4;
        while (iVar2 != 0) {
          iVar2 = substrcmp(*piVar4,param_1);
          if (iVar2 != 0) {
            local_6c = 1;
            iVar2 = changeReg(*piVar4,auStack_68 + piVar4[1],4);
            if (iVar2 == -1) {
              return 0xffffffff;
            }
            taskRegsSet(uVar3,auStack_68);
            goto LAB_3011d134;
          }
          piVar4 = piVar4 + 2;
          iVar2 = *piVar4;
        }
        local_6c = 0;
        coprocMRegs(uVar3,param_1,&local_6c);
        if (local_6c == 0) {
          printf(DAT_3011d6c8,param_3,param_1);
          puts(DAT_3011d6cc);
          iVar2 = *piVar5;
          while (iVar2 != 0) {
            printf(DAT_3011d6d0,*piVar5);
            piVar5 = piVar5 + 2;
            iVar2 = *piVar5;
          }
          puts(DAT_3011d6d4);
          coprocRegListShow();
          return 0xffffffff;
        }
      }
LAB_3011d134:
      uVar3 = 0;
    }
    else {
      printErr(DAT_3011d6c0,param_3,uVar3);
      uVar3 = 0xffffffff;
    }
  }
  else {
    printErr(*DAT_3011d3b4,param_3);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * avlUintInsert @ 0x3011D900  (примерный размер ~160 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3011d754
 * Вызывают: memPartInsertFree
 * Константы: 0xFFFFFFFF, 0x3011D900
 * ---------------------------------------------------------------- */
undefined4 avlUintInsert(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_78 [28];
  
  if ((param_2 == (undefined4 *)0x0) || (param_1 == (undefined4 *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar2 = param_2[3];
    iVar3 = 0;
    do {
      puVar4 = (undefined4 *)*param_1;
      if (puVar4 == (undefined4 *)0x0) break;
      local_78[iVar3] = param_1;
      iVar3 = iVar3 + 1;
      if (puVar4[3] == uVar2) {
        return 0xffffffff;
      }
      if ((uint)puVar4[3] <= uVar2) {
        puVar4 = puVar4 + 1;
      }
      param_1 = puVar4;
    } while (iVar3 < 0x1c);
    if (iVar3 == 0x1c) {
      uVar1 = 0xffffffff;
    }
    else {
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = 1;
      *param_1 = param_2;
      FUN_3011d754(local_78,iVar3);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * avlUintDelete @ 0x3011D9A0  (примерный размер ~256 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3011d754
 * Вызывают: memPartDeleteFree
 * Константы: 0x3011D9A0
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

int * avlUintDelete(int *param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int aiStack_84 [29];
  
  iVar4 = 0;
  do {
    iVar3 = iVar4;
    piVar5 = (int *)*param_1;
    if (piVar5 == (int *)0x0) {
      return (int *)0;
    }
    aiStack_84[iVar3 + 1] = (int)param_1;
    iVar4 = iVar3 + 1;
    if (piVar5[3] == param_2) break;
    param_1 = piVar5;
    if ((uint)piVar5[3] <= param_2) {
      param_1 = piVar5 + 1;
    }
  } while (iVar4 < 0x1c);
  if (iVar4 == 0x1c) {
    piVar5 = (int *)0x0;
  }
  else {
    if (*piVar5 == 0) {
      *param_1 = piVar5[1];
      iVar4 = iVar3;
    }
    else {
      piVar1 = piVar5;
      piVar6 = piVar5;
      if (iVar4 < 0x1c) {
        piVar2 = aiStack_84 + iVar4;
        iVar4 = 0x1c - iVar4;
        do {
          piVar6 = (int *)*piVar1;
          if (piVar6[1] == 0) break;
          piVar2 = piVar2 + 1;
          *piVar2 = (int)piVar1;
          piVar1 = piVar6 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        iVar4 = 0x1c - iVar4;
        if (iVar4 == 0x1c) {
          return (int *)0;
        }
      }
      *piVar1 = *piVar6;
      *piVar6 = *piVar5;
      piVar6[1] = piVar5[1];
      piVar6[2] = piVar5[2];
      *param_1 = (int)piVar6;
      aiStack_84[iVar3 + 2] = (int)piVar6;
    }
    FUN_3011d754(aiStack_84 + 1,iVar4);
  }
  return piVar5;
}

/* ----------------------------------------------------------------
 * avlUintSearch @ 0x3011DAA0  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: memPartInsertFree
 * Константы: 0x3011DAA0
 * ---------------------------------------------------------------- */
undefined4 * avlUintSearch(undefined4 *param_1,uint param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    do {
      if (param_1[3] == param_2) {
        return param_1;
      }
      if (param_2 < (uint)param_1[3]) {
        param_1 = (undefined4 *)*param_1;
      }
      else {
        param_1 = (undefined4 *)param_1[1];
      }
    } while (param_1 != (undefined4 *)0x0);
  }
  return (undefined4 *)0x0;
}

/* ----------------------------------------------------------------
 * avlUintSuccessorGet @ 0x3011DAE4  (примерный размер ~92 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300f1b90
 * Константы: 0x3011DAE4
 * ---------------------------------------------------------------- */
int * avlUintSuccessorGet(int *param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  piVar1 = (int *)0x0;
  piVar2 = piVar1;
  if (param_1 != (int *)0x0) {
    do {
      uVar3 = param_1[3];
      piVar1 = param_1;
      while (uVar3 <= param_2) {
        piVar1 = (int *)piVar1[1];
        if (piVar1 == (int *)0x0) {
          return piVar2;
        }
        uVar3 = piVar1[3];
      }
      param_1 = (int *)*piVar1;
      piVar2 = piVar1;
    } while (param_1 != (int *)0x0);
  }
  return piVar1;
}

/* ----------------------------------------------------------------
 * avlUintPredecessorGet @ 0x3011DB40  (примерный размер ~92 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011DB40
 * ---------------------------------------------------------------- */
int * avlUintPredecessorGet(int *param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  piVar1 = (int *)0x0;
  piVar2 = piVar1;
  if (param_1 != (int *)0x0) {
    do {
      uVar3 = param_1[3];
      piVar1 = param_1;
      while (param_2 <= uVar3) {
        piVar1 = (int *)*piVar1;
        if (piVar1 == (int *)0x0) {
          return piVar2;
        }
        uVar3 = piVar1[3];
      }
      param_1 = (int *)piVar1[1];
      piVar2 = piVar1;
    } while (param_1 != (int *)0x0);
  }
  return piVar1;
}

/* ----------------------------------------------------------------
 * avlUintMinimumGet @ 0x3011DB9C  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011DB9C
 * ---------------------------------------------------------------- */
int * avlUintMinimumGet(int *param_1)

{
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  if (*param_1 == 0) {
    return param_1;
  }
  do {
    param_1 = (int *)*param_1;
  } while (*param_1 != 0);
  return param_1;
}

/* ----------------------------------------------------------------
 * avlUintMaximumGet @ 0x3011DBCC  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: memPartFindMax, memPartInfoGet
 * Константы: 0x3011DBCC
 * ---------------------------------------------------------------- */
int avlUintMaximumGet(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 4) == 0) {
    return param_1;
  }
  do {
    param_1 = *(int *)(param_1 + 4);
  } while (*(int *)(param_1 + 4) != 0);
  return param_1;
}

/* ----------------------------------------------------------------
 * avlUintTreeWalk @ 0x3011DBFC  (примерный размер ~412 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x3011DBFC, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4
avlUintTreeWalk(int *param_1,code *param_2,undefined4 param_3,code *param_4,undefined4 param_5,
               code *param_6,undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *local_104 [56];
  
  uVar4 = 0;
  if (param_1 != (int *)0x0) {
    piVar3 = param_1;
    if ((param_2 != (code *)0x0) || (param_4 != (code *)0x0)) {
      do {
        for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
          if ((param_2 != (code *)0x0) && (iVar2 = (*param_2)(piVar3,param_3), iVar2 == -1)) {
            return 0xffffffff;
          }
          local_104[uVar4] = piVar3;
          uVar4 = uVar4 + 1;
          if (uVar4 == 0x1c) {
            return 0xffffffff;
          }
        }
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        piVar3 = (int *)local_104[uVar4][1];
        if ((param_4 != (code *)0x0) && (iVar2 = (*param_4)(local_104[uVar4],param_5), iVar2 == -1))
        {
          return 0xffffffff;
        }
      } while (uVar4 < 0x38);
    }
    if (param_6 != (code *)0x0) {
      local_104[0] = param_1;
      iVar2 = 1;
      while (iVar2 != 0) {
        iVar2 = iVar2 + -1;
        piVar3 = local_104[iVar2];
        while (piVar1 = (int *)((uint)piVar3 & 0xfffffffe), ((uint)piVar3 & 1) == 0) {
          local_104[iVar2] = (int *)((uint)piVar1 | 1);
          iVar5 = iVar2 + 1;
          if (0x37 < iVar2 + 3U) {
            return 0xffffffff;
          }
          if ((int *)piVar1[1] != (int *)0x0) {
            local_104[iVar5] = (int *)piVar1[1];
            iVar5 = iVar2 + 2;
          }
          if ((int *)*piVar1 != (int *)0x0) {
            local_104[iVar5] = (int *)*piVar1;
            iVar5 = iVar5 + 1;
          }
          if (iVar5 == 0) {
            return 0;
          }
          iVar2 = iVar5 + -1;
          piVar3 = local_104[iVar2];
        }
        iVar5 = (*param_6)(piVar1,param_7);
        if (iVar5 == -1) {
          return 0xffffffff;
        }
      }
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * qFifoInit @ 0x3011EE08  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllInit
 * Константы: 0x3011EE08, 0xFFFFFFFC
 * ---------------------------------------------------------------- */
undefined4 qFifoInit(int param_1,uint param_2)

{
  dllInit();
  if ((param_2 & 0xfffffffc) != 0) {
    param_2 = 0;
  }
  *(uint *)(param_1 + 8) = param_2;
  return 0;
}

/* ----------------------------------------------------------------
 * qFifoPut @ 0x3011EE30  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: dllAdd, dllInsert
 * Константы: 0x3011EE30
 * ---------------------------------------------------------------- */
void qFifoPut(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 == -1) {
    dllInsert(param_1,0,param_2);
  }
  else {
    dllAdd();
  }
  return;
}

/* ----------------------------------------------------------------
 * qFifoRestore @ 0x3011EE54  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllInsert
 * Константы: 0x3011EE54
 * ---------------------------------------------------------------- */
void qFifoRestore(undefined4 param_1,undefined4 param_2)

{
  dllInsert(param_1,0,param_2);
  return;
}

/* ----------------------------------------------------------------
 * qFifoGet @ 0x3011EE60  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllGet
 * Константы: 0x3011EE60
 * ---------------------------------------------------------------- */
void qFifoGet(int *param_1)

{
  if (*param_1 != 0) {
    dllGet(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * qFifoRemove @ 0x3011EE7C  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllRemove
 * Константы: 0x3011EE7C
 * ---------------------------------------------------------------- */
undefined4 qFifoRemove(void)

{
  dllRemove();
  return 0;
}

/* ----------------------------------------------------------------
 * qFifoInfo @ 0x3011EE8C  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllCount
 * Константы: 0x3011EE8C
 * ---------------------------------------------------------------- */
int qFifoInfo(undefined4 *param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    iVar2 = dllCount();
  }
  else {
    while ((piVar3 != (int *)0x0 && (param_3 = param_3 + -1, -1 < param_3))) {
      *piVar1 = (int)piVar3;
      piVar3 = (int *)*piVar3;
      piVar1 = piVar1 + 1;
    }
    iVar2 = (int)piVar1 - (int)param_2 >> 2;
  }
  return iVar2;
}

