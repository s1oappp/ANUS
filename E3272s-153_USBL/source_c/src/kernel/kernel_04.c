/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : kernel — ядро VxWorks 6.8: задачи, семафоры, очереди, прерывания, память, планировщик
 * Часть  : 4 (функций: 150, адреса 0x300E8850..0x300F1820)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * ioDefPathCat @ 0x300E8850  (примерный размер ~324 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 10
 * Вызывает: errnoSet, iosDevFind, iosRtpDefPathSet, memPartAlloc, memPartFree, memcmp, pathCat, pathCondense, strcat, strlen
 * Вызывают: cd
 * Константы: 0x300E8850, 0xFFFFFFFF
 * Данные: DAT_300e8b80, DAT_300e8b84, DAT_300e8b8c
 * ---------------------------------------------------------------- */
undefined4 ioDefPathCat(char *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  char *__dest;
  int iVar3;
  size_t sVar4;
  undefined4 uVar5;
  bool bVar6;
  char *local_18;
  
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
      iosDevFind(__dest,&local_18);
      if (local_18 != __dest) {
LAB_300e894c:
        uVar5 = iosRtpDefPathSet(*(undefined4 *)(*piVar2 + 0x94),__dest);
        memPartFree(*puVar1,__dest);
        return uVar5;
      }
      sVar4 = strlen(param_1);
      if (param_1[sVar4 - 1] == '.') {
        strcat(__dest,DAT_300e8b8c);
        iosDevFind(__dest,&local_18);
        if (local_18 != __dest) goto LAB_300e894c;
      }
      errnoSet(0x13);
    }
    memPartFree(*puVar1,__dest);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * ioDefPathSetInternal @ 0x300E8A30  (примерный размер ~296 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: __errno, close, ioctl, open, strcpy, strlen
 * Вызывают: ioDefPathSet
 * Константы: 0xFFFFFFFF, 0x300E8A30
 * Данные: DAT_300e8b90
 * ---------------------------------------------------------------- */
undefined4 ioDefPathSetInternal(int param_1,char *param_2)

{
  size_t sVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int __fd;
  int iVar4;
  undefined1 auStack_58 [8];
  uint local_50;
  
  sVar1 = strlen(param_2);
  if ((param_1 == 0) || (*(int *)(param_1 + 0xd4) == 0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x16;
    uVar3 = 0xffffffff;
  }
  else if (*(uint *)(param_1 + 0xd8) < sVar1 + 1) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x1a;
    uVar3 = 0xffffffff;
  }
  else {
    if ((*DAT_300e8b90 == 0) && (*param_2 != '\0')) {
      __fd = open(param_2,0,0);
      if (__fd == -1) {
        puVar2 = (undefined4 *)__errno();
        *puVar2 = 0x13;
        return 0xffffffff;
      }
      iVar4 = ioctl(__fd,0x40,auStack_58);
      if (iVar4 == -1) {
        puVar2 = (undefined4 *)__errno();
        *puVar2 = 0x13;
        close(__fd);
        return 0xffffffff;
      }
      close(__fd);
      if ((local_50 & 0xf000) != 0x4000) {
        puVar2 = (undefined4 *)__errno();
        *puVar2 = 0x16;
        return 0xffffffff;
      }
    }
    strcpy(*(char **)(param_1 + 0xd4),param_2);
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * ioDefPathSet @ 0x300E8B58  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: ioDefPathSetInternal
 * Константы: 0x300E8B58
 * Данные: DAT_300e8b84
 * ---------------------------------------------------------------- */
void ioDefPathSet(undefined4 param_1)

{
  ioDefPathSetInternal(*(undefined4 *)(*DAT_300e8b84 + 0x94),param_1);
  return;
}

/* ----------------------------------------------------------------
 * ioDefPathGet @ 0x300E8B6C  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: strcpy
 * Вызывают: pwd
 * Константы: 0x300E8B6C
 * Данные: DAT_300e8b84
 * ---------------------------------------------------------------- */
void ioDefPathGet(char *param_1)

{
  strcpy(param_1,*(char **)(*(int *)(*DAT_300e8b84 + 0x94) + 0xd4));
  return;
}

/* ----------------------------------------------------------------
 * ioPxCreateOrOpen @ 0x300E8C8C  (примерный размер ~284 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, iosRtpFdReserveCntrl
 * Константы: 0x300E8C8C
 * Данные: DAT_300e8d98, DAT_300e8d9c, DAT_300e8da0, DAT_300e8da4
 * ---------------------------------------------------------------- */
int ioPxCreateOrOpen(int param_1,undefined4 *param_2,uint param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  
  if (((param_1 == 0) && (*DAT_300e8d98 != *(int *)(*DAT_300e8d9c + 0x94))) &&
     ((param_3 & 0x40000) != 0)) {
    iVar1 = iosRtpFdReserveCntrl();
    *param_4 = iVar1;
    bVar3 = iVar1 == -1;
    if (bVar3) {
      if ((*DAT_300e8da0 == 0) || ((code *)*DAT_300e8da4 == (code *)0x0)) {
        puVar2 = (undefined4 *)__errno();
        *puVar2 = 0x17;
        return -1;
      }
      iVar1 = (*(code *)*DAT_300e8da4)(*(undefined4 *)(*DAT_300e8d9c + 0x94));
      iVar1 = (*(code *)*DAT_300e8da0)(*(undefined4 *)(*DAT_300e8d9c + 0x94),iVar1 + 1);
      if (iVar1 != 0) {
        puVar2 = (undefined4 *)__errno();
        *puVar2 = 0x17;
        return -1;
      }
      iVar1 = iosRtpFdReserveCntrl(*(undefined4 *)(*DAT_300e8d9c + 0x94));
      *param_4 = iVar1;
      bVar3 = iVar1 == -1;
      if (bVar3) {
        iVar1 = -1;
      }
    }
    if (!bVar3) {
      *param_2 = 0x40000;
      iVar1 = 0;
    }
    return iVar1;
  }
  return -1;
}

/* ----------------------------------------------------------------
 * iosDevMatch @ 0x300E8DA8  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 2
 * Вызывает: strlen, strncmp
 * Вызывают: iosDevAdd, iosDevFind, iosDevReplaceExt
 * Константы: 0x300E8DA8
 * Данные: DAT_300e9d64
 * ---------------------------------------------------------------- */
int iosDevMatch(char *param_1)

{
  size_t __n;
  int iVar1;
  int *piVar2;
  size_t sVar3;
  char *__s;
  int *piVar4;
  
  piVar2 = (int *)0;
  sVar3 = 0;
  piVar4 = DAT_300e9d64;
  while (piVar4 = (int *)*piVar4, piVar4 != (int *)0x0) {
    __s = (char *)piVar4[3];
    __n = strlen(__s);
    iVar1 = strncmp(__s,param_1,__n);
    if ((iVar1 == 0) && ((int)sVar3 < (int)__n)) {
      piVar2 = piVar4;
      sVar3 = __n;
    }
  }
  return (int)piVar2;
}

/* ----------------------------------------------------------------
 * iosLock @ 0x300E8E0C  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 16 | Вызывает: 2
 * Вызывает: __errno, semTake
 * Вызывают: FUN_300eb1c8, FUN_300eb214, dosFsDevCreate, iosDevAdd, iosDevDelCallback, iosDevDelDrv, iosDevDelete, iosDevFind, iosDevReplace, iosDevResume
 *           ...
 * Константы: 0x300E8E0C, 0xFFFFFFFF
 * Данные: DAT_300e9d68
 * ---------------------------------------------------------------- */
int iosLock(void)

{
  int iVar1;
  int *piVar2;
  
  do {
    iVar1 = semTake(*DAT_300e9d68,0xffffffff);
    if (iVar1 != -1) {
      return iVar1;
    }
    piVar2 = (int *)__errno();
  } while (*piVar2 == 4);
  return -1;
}

/* ----------------------------------------------------------------
 * iosUnlock @ 0x300E8E4C  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 10 | Вызывает: 1
 * Вызывает: semGive
 * Вызывают: FUN_300eb1c8, FUN_300eb214, dosFsDevCreate, iosDevDelCallback, iosDevReplace, iosDevResume, iosDevSuspend, iosDrvIoctlMemValSet, rawFsDevInit, unmount
 * Константы: 0x300E8E4C
 * Данные: DAT_300e9d68
 * ---------------------------------------------------------------- */
void iosUnlock(void)

{
  semGive(*DAT_300e9d68);
  return;
}

/* ----------------------------------------------------------------
 * iosDevAdd @ 0x300E8E58  (примерный размер ~344 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 11
 * Вызывает: __errno, dllAdd, errnoSet, iosDevMatch, iosLock, memPartAlloc, memPartFree, semGive, strcmp, strcpy, strlen
 * Вызывают: FUN_30060740, iosInit, iosPxLibInit, pipeDevCreate, ptyDevCreate, ttyDevCreate, yaffsDevCreate
 * Константы: 0xFFFFFFFF, 0x300E8E58
 * Данные: DAT_300e9d64, DAT_300e9d68, DAT_300e9d6c, DAT_300e9d70, DAT_300e9e80
 * ---------------------------------------------------------------- */
undefined4 iosDevAdd(int param_1,char *param_2,int param_3)

{
  undefined4 *puVar1;
  size_t sVar2;
  char *__dest;
  int iVar3;
  
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 0;
  if (((((param_1 == 0) || (param_2 == (char *)0x0)) || (*param_2 == '\0')) ||
      ((param_3 < 0 || (*DAT_300e9d6c <= param_3)))) ||
     (*(int *)(*DAT_300e9d70 + param_3 * 0x24 + 0x20) == 0)) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    return 0xffffffff;
  }
  sVar2 = strlen(param_2);
  __dest = (char *)memPartAlloc(*DAT_300e9e80,sVar2 + 1);
  if (__dest == (char *)0x0) {
    return 0xffffffff;
  }
  strcpy(__dest,param_2);
  iosLock();
  iVar3 = iosDevMatch(param_2);
  if ((iVar3 != 0) && (iVar3 = strcmp(*(char **)(iVar3 + 0xc),param_2), iVar3 == 0)) {
    semGive(*DAT_300e9d68);
    errnoSet(0x16);
    memPartFree(*DAT_300e9e80,__dest);
    return 0xffffffff;
  }
  *(char **)(param_1 + 0xc) = __dest;
  *(short *)(param_1 + 8) = (short)param_3;
  *(int *)(param_1 + 0x18) = *DAT_300e9d70 + param_3 * 0x24;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  dllAdd(DAT_300e9d64,param_1);
  semGive(*DAT_300e9d68);
  return 0;
}

/* ----------------------------------------------------------------
 * iosDevDelDrv @ 0x300E8FB0  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: iosLock, semGive
 * Вызывают: iosDevDelete, iosDrvRemove
 * Константы: 0x300E8FB0, 0xFFFFFFFE
 * Данные: DAT_300e9d68
 * ---------------------------------------------------------------- */
undefined4 iosDevDelDrv(int param_1)

{
  iosLock();
  if ((*(uint *)(param_1 + 0x14) & 1) == 0) {
    semGive(*DAT_300e9d68);
  }
  else {
    if (0 < *(int *)(param_1 + 0x10)) {
      semGive(*DAT_300e9d68);
      return 1;
    }
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
    semGive(*DAT_300e9d68);
    if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
      (**(code **)(param_1 + 0x1c))(param_1);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * iosDevDelete @ 0x300E9038  (примерный размер ~292 байт)
 * Модуль: kernel | Вызывают: 12 | Вызывает: 6
 * Вызывает: __errno, dllRemove, iosDevDelDrv, iosLock, memPartFree, semGive
 * Вызывают: FUN_3005faa4, FUN_300624c4, FUN_300ca46c, FUN_300d6fa8, dosFsDevDelete, iosDevReplaceExt, iosInit, pipeDevDelete, ptyDevCreate, ptyDevRemove
 *           ...
 * Константы: 0xFFFFFFFF, 0x300E9038
 * Данные: DAT_300e9d64, DAT_300e9d68, DAT_300e9d6c, DAT_300e9d70, DAT_300e9e80, DAT_300e9f88, DAT_300e9f8c, DAT_300e9f90
 * ---------------------------------------------------------------- */
undefined4 iosDevDelete(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iosLock();
  if (((param_1 == 0) || (iVar3 = *(int *)(param_1 + 0x18), DAT_300e9f88 == iVar3)) ||
     (*(int *)(param_1 + 0xc) == 0)) {
    semGive(*DAT_300e9d68);
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    return 0xffffffff;
  }
  iVar2 = (int)*(short *)(param_1 + 8);
  if (((-1 < iVar2) && (iVar2 < *DAT_300e9d6c)) &&
     ((iVar2 * 0x24 + *DAT_300e9d70 == iVar3 ||
      ((*DAT_300e9f8c == iVar3 || (*DAT_300e9f90 == iVar3)))))) {
    *(int *)(param_1 + 0x18) = DAT_300e9f88;
    (*(code *)*DAT_300ea070)(param_1);
    dllRemove(DAT_300e9d64,param_1);
    uVar4 = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0xc) = 0;
    semGive(*DAT_300e9d68);
    memPartFree(*DAT_300e9e80,uVar4);
    uVar4 = iosDevDelDrv(param_1);
    return uVar4;
  }
  semGive(*DAT_300e9d68);
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 0x16;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * iosDevFind @ 0x300E915C  (примерный размер ~192 байт)
 * Модуль: kernel | Вызывают: 16 | Вызывает: 5
 * Вызывает: errnoSet, iosDevMatch, iosLock, semGive, strlen
 * Вызывают: FUN_300eb28c, chdir, creat, dosFsVolDescGet, ioDefPathCat, ioFullFileNameGet, iosInit, open, pathCat, pathCondense
 *           ...
 * Константы: 0x300E915C
 * Данные: DAT_300e9d68, DAT_300ea074
 * ---------------------------------------------------------------- */
int iosDevFind(char *param_1,undefined4 *param_2)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  
  iosLock();
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    iVar1 = 0;
  }
  else {
    iVar1 = iosDevMatch(param_1);
  }
  if (iVar1 == 0) {
    pcVar3 = *(char **)(*(int *)(*DAT_300ea074 + 0x94) + 0xd4);
    if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {
      iVar1 = 0;
    }
    else {
      iVar1 = iosDevMatch(pcVar3);
    }
    if (param_2 == (undefined4 *)0x0) goto LAB_300e91f8;
  }
  else {
    if (param_2 == (undefined4 *)0x0) goto LAB_300e91f8;
    sVar2 = strlen(*(char **)(iVar1 + 0xc));
    param_1 = param_1 + sVar2;
  }
  *param_2 = param_1;
LAB_300e91f8:
  semGive(*DAT_300e9d68);
  if (iVar1 == 0) {
    errnoSet(0x13);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * iosFdEntryGet @ 0x300E921C  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 2
 * Вызывает: __errno, poolItemGet
 * Вызывают: creat, iosFdNew, iosInit, open
 * Константы: 0x300E921C
 * Данные: DAT_300ea1a0
 * ---------------------------------------------------------------- */
int iosFdEntryGet(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = poolItemGet(*DAT_300ea1a0);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x17;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * iosFdTableLock @ 0x300E924C  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 18 | Вызывает: 2
 * Вызывает: __errno, semTake
 * Вызывают: FUN_300c906c, FUN_300e9c40, FUN_300eaea0, FUN_300eb060, FUN_300ee694, dup, dup2, iosFdMap, iosRtpDevCloseOrInvalidate, iosRtpFdEntryMap
 *           ...
 * Константы: 0x300E924C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int iosFdTableLock(int param_1)

{
  int iVar1;
  int *piVar2;
  
  do {
    iVar1 = semTake(*(undefined4 *)(param_1 + 200),0xffffffff);
    if (iVar1 != -1) {
      return iVar1;
    }
    piVar2 = (int *)__errno();
  } while (*piVar2 == 4);
  return -1;
}

/* ----------------------------------------------------------------
 * iosFdTableUnlock @ 0x300E928C  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 11 | Вызывает: 1
 * Вызывает: semGive
 * Вызывают: FUN_300c906c, FUN_300eaea0, FUN_300eb060, FUN_300ee694, dup, dup2, iosRtpFdReserveCntrl, iosRtpFdTableSizeGet, iosRtpFdTblEntryGet, iosRtpIoTableSizeGet
 *           ...
 * Константы: 0x300E928C
 * ---------------------------------------------------------------- */
void iosFdTableUnlock(int param_1)

{
  semGive(*(undefined4 *)(param_1 + 200),param_1);
  return;
}

/* ----------------------------------------------------------------
 * iosRtpFdReserve @ 0x300E9298  (примерный размер ~112 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 3
 * Вызывает: __errno, iosFdTableLock, semGive
 * Вызывают: creat, dup, iosFdNew, iosInit, open
 * Константы: 0xFFFFFFFF, 0x300E9298
 * ---------------------------------------------------------------- */
uint iosRtpFdReserve(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0xffffffff;
  iosFdTableLock();
  piVar2 = *(int **)(param_1 + 0xcc);
  uVar3 = 0;
  if (*(uint *)(param_1 + 0xd0) != 0) {
    do {
      if (*piVar2 == 0) {
        *piVar2 = -1;
        uVar4 = uVar3;
        break;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0xd0));
  }
  semGive(*(undefined4 *)(param_1 + 200));
  if (uVar4 == 0xffffffff) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x18;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * iosInit @ 0x300E9308  (примерный размер ~784 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 15
 * Вызывает: bzero, classInit, dllInit, iosDevAdd, iosDevDelete, iosDevFind, iosDrvInit, iosFdEntryGet, iosRtpFdReserve, memPartAlloc, memPartFree, objCoreInit, objNamePtrSet, poolCreate
 *           ...
 * Вызывают: usrIosCoreInit
 * Константы: 0xFFFFFFFF, 0x300E9308
 * Данные: DAT_300e9d64, DAT_300e9d68, DAT_300e9d6c, DAT_300e9d70, DAT_300e9e80, DAT_300ea1a0, DAT_300ea2a0, DAT_300ea2a4
 * ---------------------------------------------------------------- */
undefined4 iosInit(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined1 auStack_18 [4];
  
  *DAT_300e9d6c = param_1;
  *DAT_300ea2a0 = param_2;
  *DAT_300ea2a4 = 0;
  puVar3 = DAT_300e9e80;
  pvVar4 = (void *)memPartAlloc(*DAT_300e9e80,param_2 << 2);
  *DAT_300ea2a8 = pvVar4;
  if (pvVar4 == (void *)0x0) {
    return 0xffffffff;
  }
  bzero(pvVar4,param_2 << 2);
  iVar8 = *DAT_300ea2ac;
  iVar5 = semMCreate(0xd);
  *(int *)(iVar8 + 200) = iVar5;
  if (iVar5 == 0) {
    return 0xffffffff;
  }
  iVar5 = poolCreate(DAT_300ea2b0,0x5c,4,*DAT_300ea2a0,*DAT_300ea2a0,0,1);
  *DAT_300ea1a0 = iVar5;
  if (iVar5 == 0) {
    return 0xffffffff;
  }
  iVar5 = *DAT_300e9d6c;
  pvVar4 = (void *)memPartAlloc(*puVar3,iVar5 * 0x24);
  puVar2 = DAT_300e9d70;
  *DAT_300e9d70 = pvVar4;
  if (pvVar4 == (void *)0x0) {
    return 0xffffffff;
  }
  bzero(pvVar4,iVar5 * 0x24);
  piVar1 = DAT_300e9d68;
  if (*DAT_300e9d68 == 0) {
    iVar5 = semMCreate(*DAT_300ea2b4);
    *piVar1 = iVar5;
    if (iVar5 == 0) goto LAB_300e94a8;
  }
  dllInit(DAT_300e9d64);
  iosDrvInit(*puVar2,0);
  iosDevAdd(DAT_300ea2f4,param_3,0);
  uVar6 = DAT_300ea2f8;
  if ((*piVar1 != 0) &&
     (iVar5 = classInit(DAT_300ea2f8,0x5c,DAT_300ea2fc,0,0,0,0,0,8,1), iVar5 == 0)) {
    *DAT_300ea300 = 1;
    *DAT_300ea308 = DAT_300ea304;
    *DAT_300ea310 = DAT_300ea30c;
    iVar5 = iosFdEntryGet();
    *DAT_300ea314 = iVar5;
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    objCoreInit(iVar5,uVar6);
    objNamePtrSet(*DAT_300ea314,0);
    uVar6 = iosDevFind(DAT_300ea318,auStack_18);
    *(undefined4 *)(*DAT_300ea314 + 0x40) = uVar6;
    iVar5 = *DAT_300ea314;
    *(undefined4 *)(iVar5 + 0x44) = 0;
    *(undefined4 *)(iVar5 + 0x54) = *puVar2;
    *(undefined4 *)(iVar5 + 0x4c) = 10;
    iVar5 = *DAT_300ea2ac;
    *(undefined4 *)(iVar5 + 0xcc) = *DAT_300ea2a8;
    *(int *)(iVar5 + 0xd0) = *DAT_300ea2a0;
    puVar7 = (undefined1 *)memPartAlloc(*puVar3,0x400);
    iVar5 = *DAT_300ea2ac;
    *(undefined1 **)(iVar5 + 0xd4) = puVar7;
    if (puVar7 != (undefined1 *)0x0) {
      *(undefined4 *)(iVar5 + 0xd8) = 0x400;
      *puVar7 = 0;
      iosRtpFdReserve(*DAT_300ea2ac);
      iosRtpFdReserve(*DAT_300ea2ac);
      iosRtpFdReserve(*DAT_300ea2ac);
      *DAT_300ea320 = DAT_300ea31c;
      return 0;
    }
    return 0xffffffff;
  }
LAB_300e94a8:
  memPartFree(*puVar3,*DAT_300ea2a8);
  memPartFree(*puVar3,*puVar2);
  if (*piVar1 != 0) {
    iosDevDelete(DAT_300ea2f4);
  }
  *DAT_300ea2a8 = 0;
  *puVar2 = 0;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * iosDrvInstall @ 0x300E9618  (примерный размер ~224 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 3
 * Вызывает: errnoSet, iosLock, semGive
 * Вызывают: FUN_300624c4, dosFsLibInit, pipeDrv, ptyDrv, rawFsInit, ttyDrv, yaffsDrv
 * Константы: 0x300E9618
 * Данные: DAT_300e9d68, DAT_300e9d6c, DAT_300e9d70, DAT_300ea324
 * ---------------------------------------------------------------- */
int iosDrvInstall(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  piVar3 = local_30;
  local_20 = param_5;
  local_1c = param_6;
  local_18 = param_7;
  local_14 = param_7;
  local_30[0] = param_1;
  local_30[1] = param_2;
  local_30[2] = param_3;
  local_30[3] = param_4;
  iosLock();
  iVar5 = *DAT_300e9d6c;
  if (1 < iVar5) {
    iVar4 = iVar5 + -1;
    piVar1 = (int *)*DAT_300e9d70;
    do {
      if (piVar1[0x11] == 0) {
        piVar1[0x11] = 1;
        iVar7 = 8;
        piVar1 = piVar1 + 9;
        piVar2 = DAT_300ea324;
        do {
          iVar6 = *piVar3;
          if (iVar6 == 0) {
            iVar6 = *piVar2;
          }
          *piVar1 = iVar6;
          piVar2 = piVar2 + 1;
          piVar3 = piVar3 + 1;
          iVar7 = iVar7 + -1;
          piVar1 = piVar1 + 1;
        } while (iVar7 != 0);
        semGive(*DAT_300e9d68);
        return iVar5 - iVar4;
      }
      iVar4 = iVar4 + -1;
      piVar1 = piVar1 + 9;
    } while (iVar4 != 0);
  }
  errnoSet(0xc);
  semGive(*DAT_300e9d68);
  return -1;
}

/* ----------------------------------------------------------------
 * iosDrvRemove @ 0x300E96F8  (примерный размер ~300 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: __errno, dllRemove, iosDevDelDrv, iosLock, memPartFree, semGive
 * Вызывают: yaffsDrvUninstall
 * Константы: 0x300E96F8, 0xFFFFFFFF
 * Данные: DAT_300e9d64, DAT_300e9d68, DAT_300e9d6c, DAT_300e9d70, DAT_300e9e80, DAT_300e9f88, DAT_300ea070, DAT_300ea328
 * ---------------------------------------------------------------- */
undefined4 iosDrvRemove(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  uVar5 = 0;
  if (((param_1 < 1) || (*DAT_300e9d6c <= param_1)) || ((param_2 != 1 && (param_2 != 0)))) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x16;
    uVar5 = 0xffffffff;
  }
  else {
    puVar2 = (undefined4 *)(*DAT_300e9d70 + param_1 * 0x24);
    if (param_2 == 0) {
      pcVar4 = (code *)*DAT_300ea070;
    }
    else {
      pcVar4 = (code *)*DAT_300ea328;
    }
    iosLock();
    puVar1 = DAT_300e9d64;
    for (puVar6 = (undefined4 *)*DAT_300e9d64; puVar6 != (undefined4 *)0x0;
        puVar6 = (undefined4 *)*puVar6) {
      if (*(short *)(puVar6 + 2) == param_1) {
        puVar6[6] = DAT_300e9f88;
        (*pcVar4)(puVar6);
        dllRemove(puVar1,puVar6);
        memPartFree(*DAT_300e9e80,puVar6[3]);
        puVar6[3] = 0;
        iVar3 = iosDevDelDrv(puVar6);
        if (iVar3 == 1) {
          uVar5 = 1;
        }
      }
    }
    puVar2[8] = 0;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    semGive(*DAT_300e9d68);
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * iosFdEntryReturn @ 0x300E9824  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 1
 * Вызывает: poolItemReturn
 * Вызывают: creat, iosRtpFdUnmap2, open
 * Константы: 0x300E9824
 * Данные: DAT_300ea1a0
 * ---------------------------------------------------------------- */
undefined4 iosFdEntryReturn(int param_1)

{
  if (param_1 != 0) {
    poolItemReturn(*DAT_300ea1a0,param_1);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * iosRtpFdUnmap2 @ 0x300E9848  (примерный размер ~388 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 8
 * Вызывает: __errno, iosFdEntryReturn, iosFdTableLock, objCoreInvalidate, objCoreTerminate, semGive, taskCpuUnlock, taskUnsafe
 * Вызывают: creat, dup2, iosClose, iosFdFree, iosFdNew, iosRtpDevCloseOrInvalidate, open
 * Константы: 0x300E9848, 0xFFFFFFFF
 * Данные: DAT_300ea074, DAT_300ea32c
 * ---------------------------------------------------------------- */
undefined4 iosRtpFdUnmap2(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = *(int *)(param_1 + 0xcc);
  uVar3 = 0xffffffff;
  iosFdTableLock();
  if ((-1 < (int)param_2) && (uVar1 = *(uint *)(param_1 + 0xd0), param_2 < uVar1)) {
    piVar6 = (int *)(iVar5 + param_2 * 4);
    iVar5 = *piVar6;
    if ((iVar5 != 0) && (iVar5 != -2)) {
      if ((((iVar5 == -1) || (*DAT_300ea32c == 0)) || ((*(uint *)(iVar5 + 0x50) & 0x40000) == 0)) ||
         (param_2 + 1 != uVar1)) {
        if (param_2 + 1 < uVar1) {
          param_3 = 0;
        }
        if ((param_3 & 0x40000) != 0) goto LAB_300e98e8;
        iVar4 = 0;
      }
      else {
LAB_300e98e8:
        iVar4 = -2;
      }
      *piVar6 = iVar4;
      if (iVar5 == -1) {
        uVar3 = 0;
      }
      else {
        *(int *)(*DAT_300ea074 + 0x7c) = *(int *)(*DAT_300ea074 + 0x7c) + 1;
        *(int *)(iVar5 + 0x4c) = *(int *)(iVar5 + 0x4c) + -1;
        taskCpuUnlock();
        if (*(int *)(iVar5 + 0x4c) < 1) {
          semGive(*(undefined4 *)(param_1 + 200));
          uVar3 = (**(code **)(*(int *)(iVar5 + 0x54) + 0xc))(*(undefined4 *)(iVar5 + 0x44));
          iosFdTableLock(param_1);
        }
        else {
          uVar3 = 0;
        }
        if (*(int *)(iVar5 + 0x4c) < 1) {
          objCoreInvalidate(iVar5);
          *(int *)(*DAT_300ea074 + 0xac) = *(int *)(*DAT_300ea074 + 0xac) + 1;
          semGive(*(undefined4 *)(param_1 + 200));
          objCoreTerminate(iVar5);
          taskUnsafe();
          iosFdEntryReturn(iVar5);
          iosFdTableLock(param_1);
        }
      }
      goto LAB_300e99b8;
    }
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = 9;
LAB_300e99b8:
  semGive(*(undefined4 *)(param_1 + 200));
  return uVar3;
}

/* ----------------------------------------------------------------
 * iosRtpDevCloseOrInvalidate @ 0x300E99CC  (примерный размер ~172 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 3
 * Вызывает: iosFdTableLock, iosRtpFdUnmap2, semGive
 * Вызывают: FUN_300e9a78, FUN_300e9aac, FUN_300ead10, FUN_300eb198
 * Константы: 0x300E99CC
 * Данные: DAT_300e9f88
 * ---------------------------------------------------------------- */
undefined4 iosRtpDevCloseOrInvalidate(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iosFdTableLock();
  iVar2 = *(int *)(param_1 + 0xd0);
  iVar1 = *(int *)(param_1 + 0xcc);
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = *(int *)(iVar1 + iVar4 * 4);
      if ((((iVar3 != 0) && (iVar3 != -1)) && (iVar3 != -2)) && (*(int *)(iVar3 + 0x40) == *param_2)
         ) {
        if (param_2[1] == 0) {
          *(undefined4 *)(iVar3 + 0x54) = DAT_300e9f88;
        }
        else {
          semGive(*(undefined4 *)(param_1 + 200));
          iosRtpFdUnmap2(param_1,iVar4,0);
          iosFdTableLock(param_1);
          iVar1 = *(int *)(param_1 + 0xcc);
          iVar2 = *(int *)(param_1 + 0xd0);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  semGive(*(undefined4 *)(param_1 + 200));
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300e9a78 @ 0x300E9A78  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: iosRtpDevCloseOrInvalidate
 * Константы: 0x300E9A78
 * Данные: DAT_300ea074
 * ---------------------------------------------------------------- */
undefined4 FUN_300e9a78(undefined4 param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 1;
  local_c = param_1;
  iosRtpDevCloseOrInvalidate(*(undefined4 *)(*DAT_300ea074 + 0x94),&local_c);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300e9aac @ 0x300E9AAC  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: iosRtpDevCloseOrInvalidate
 * Константы: 0x300E9AAC
 * Данные: DAT_300ea074
 * ---------------------------------------------------------------- */
undefined4 FUN_300e9aac(undefined4 param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = param_1;
  iosRtpDevCloseOrInvalidate(*(undefined4 *)(*DAT_300ea074 + 0x94),&local_c);
  return 0;
}

/* ----------------------------------------------------------------
 * iosRtpFdInvalid @ 0x300E9AE0  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: iosFdTableLock, semGive
 * Константы: 0x300E9AE0
 * Данные: DAT_300e9f88
 * ---------------------------------------------------------------- */
void iosRtpFdInvalid(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iosFdTableLock();
  iVar2 = *(int *)(param_1 + 0xd0);
  if (0 < iVar2) {
    piVar1 = (int *)(*(int *)(param_1 + 0xcc) + -4);
    do {
      piVar1 = piVar1 + 1;
      iVar3 = *piVar1;
      if ((((iVar3 != 0) && (iVar3 != -1)) && (iVar3 != -2)) && (*(int *)(iVar3 + 0x40) == param_2))
      {
        *(undefined4 *)(iVar3 + 0x54) = DAT_300e9f88;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  semGive(*(undefined4 *)(param_1 + 200));
  return;
}

/* ----------------------------------------------------------------
 * iosClose @ 0x300E9B4C  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: ioTaskStdGet, iosRtpFdUnmap2
 * Вызывают: FUN_300e9c40, close
 * Константы: 0x300E9B4C
 * Данные: DAT_300ea074, DAT_300ea2ac
 * ---------------------------------------------------------------- */
void iosClose(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_300ea074;
  if (((*(int *)(*DAT_300ea074 + 0x94) == *DAT_300ea2ac) && (-1 < param_1)) && (param_1 < 3)) {
    param_1 = ioTaskStdGet(0);
  }
  iosRtpFdUnmap2(*(undefined4 *)(*piVar1 + 0x94),param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * iosFdMap @ 0x300E9BA0  (примерный размер ~160 байт)
 * Модуль: kernel | Вызывают: 13 | Вызывает: 4
 * Вызывает: __errno, ioTaskStdGet, iosFdTableLock, semGive
 * Вызывают: FUN_300e9c40, dup, dup2, ioGlobalStdSet, ioTaskStdSet, iosFdDevFind, iosFdDrvValue, iosFdSet, iosFdShow, iosFdValue
 *           ...
 * Константы: 0x300E9BA0
 * Данные: DAT_300ea074, DAT_300ea2ac
 * ---------------------------------------------------------------- */
int iosFdMap(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*DAT_300ea074 + 0x94);
  if (((*DAT_300ea2ac == iVar2) && (-1 < (int)param_1)) && ((int)param_1 < 3)) {
    param_1 = ioTaskStdGet(0,param_1);
  }
  iosFdTableLock(iVar2);
  if ((((int)param_1 < 0) || (*(uint *)(iVar2 + 0xd0) <= param_1)) ||
     ((iVar3 = *(int *)(*(int *)(iVar2 + 0xcc) + param_1 * 4), iVar3 == 0 ||
      ((iVar3 == -1 || (iVar3 == -2)))))) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 9;
    iVar3 = 0;
  }
  semGive(*(undefined4 *)(iVar2 + 200));
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_300e9c40 @ 0x300E9C40  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: iosClose, iosFdMap, iosFdTableLock, semGive
 * Константы: 0x300E9C40
 * Данные: DAT_300ea074
 * ---------------------------------------------------------------- */
uint FUN_300e9c40(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = 0;
  iVar5 = *(int *)(*DAT_300ea074 + 0x94);
  iosFdTableLock(iVar5);
  iVar4 = *(int *)(iVar5 + 0xd0);
  iVar6 = 0;
  if (0 < iVar4) {
    do {
      iVar1 = iosFdMap(iVar6);
      if (iVar1 == param_1) {
        semGive(*(undefined4 *)(iVar5 + 200));
        uVar2 = iosClose(iVar6);
        uVar3 = uVar2 | uVar3;
        iosFdTableLock(iVar5);
        iVar4 = *(int *)(iVar5 + 0xd0);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar4);
  }
  semGive(*(undefined4 *)(iVar5 + 200));
  return uVar3;
}

/* ----------------------------------------------------------------
 * iosFdValue @ 0x300E9CBC  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: iosFdMap
 * Вызывают: fdopen
 * Константы: 0x300E9CBC, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 iosFdValue(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = iosFdMap();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x44);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * iosFdDrvValue @ 0x300E9CD8  (примерный размер ~92 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, iosFdMap
 * Константы: 0xFFFFFFFF, 0x300E9CD8
 * Данные: DAT_300e9f88
 * ---------------------------------------------------------------- */
undefined4 iosFdDrvValue(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = iosFdMap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if ((*(int *)(iVar1 + 0x54) != DAT_300e9f88) &&
     (*(short *)(*(int *)(iVar1 + 0x40) + 8) == param_2)) {
    return *(undefined4 *)(iVar1 + 0x44);
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = 6;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * iosCreate @ 0x300E9D34  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: creat
 * Константы: 0x300E9D34
 * ---------------------------------------------------------------- */
void iosCreate(int param_1)

{
  (*(code *)**(undefined4 **)(param_1 + 0x18))();
  return;
}

/* ----------------------------------------------------------------
 * iosDelete @ 0x300E9D4C  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: remove, rm
 * Константы: 0x300E9D4C
 * ---------------------------------------------------------------- */
void iosDelete(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x18) + 4))();
  return;
}

/* ----------------------------------------------------------------
 * iosOpen @ 0x300E9D78  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: open
 * Константы: 0x300E9D78
 * ---------------------------------------------------------------- */
void iosOpen(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x18) + 8))();
  return;
}

/* ----------------------------------------------------------------
 * iosRead @ 0x300E9D98  (примерный размер ~72 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: iosFdMap
 * Вызывают: readv
 * Константы: 0x300E9D98, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 iosRead(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = iosFdMap();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x54) + 0x10))
                      (*(undefined4 *)(iVar1 + 0x44),param_2,param_3);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * iosWrite @ 0x300E9DE0  (примерный размер ~72 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: iosFdMap
 * Вызывают: writev
 * Константы: 0x300E9DE0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 iosWrite(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = iosFdMap();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x54) + 0x14))
                      (*(undefined4 *)(iVar1 + 0x44),param_2,param_3);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * iosFdEntryIoctl @ 0x300E9E28  (примерный размер ~416 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 4
 * Вызывает: errnoSet, objNamePtrGet, strcpy, strlen
 * Вызывают: FUN_300ee694, iosIoctlInternal
 * Константы: 0xFFFFFFFF, 0x300E9E28
 * Данные: DAT_300ea330, DAT_300ea334, DAT_300ea338, DAT_300ea33c
 * ---------------------------------------------------------------- */
undefined4 iosFdEntryIoctl(int param_1,int param_2,int *param_3,int param_4)

{
  char *__s;
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  code *pcVar4;
  
  if (param_2 == 0x12) {
    __s = (char *)objNamePtrGet(param_1);
    if (__s == (char *)0x0) {
      uVar1 = 0xffffffff;
    }
    else {
      if ((param_4 == 1) && (pcVar4 = (code *)*DAT_300ea330, pcVar4 != (code *)0x0)) {
        sVar2 = strlen(__s);
        iVar3 = (*pcVar4)(param_3,sVar2 + 1,2);
        if (iVar3 == -1) {
          errnoSet(DAT_300ea334);
          return 0xffffffff;
        }
      }
      if (param_3 != (int *)0x0) {
        strcpy((char *)param_3,__s);
      }
      uVar1 = 0;
    }
  }
  else if ((((param_2 == 0x2f) || (param_2 == 10)) || (param_2 == 0x3a)) ||
          ((param_2 == 0x3b || (param_2 == 0x20)))) {
    if ((code *)*DAT_300ea338 == (code *)0x0) {
      errnoSet(0x23);
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = (*(code *)*DAT_300ea338)(param_1,param_2,param_3,param_4);
    }
  }
  else if ((param_2 == 0x3e) && ((*param_3 == 1 || (*param_3 == 2)))) {
    if ((code *)*DAT_300ea33c == (code *)0x0) {
      errnoSet(0x23);
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = (*(code *)*DAT_300ea33c)(param_1,param_3);
    }
  }
  else {
    uVar1 = (**(code **)(*(int *)(param_1 + 0x54) + (uint)(param_4 == 1) * 4 + 0x18))
                      (*(undefined4 *)(param_1 + 0x44),param_2,param_3);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * iosIoctlInternal @ 0x300E9FC8  (примерный размер ~160 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: iosFdEntryIoctl, iosFdMap
 * Вызывают: ioctl, iosIoctl
 * Константы: 0x300E9FC8
 * Данные: DAT_300ea340
 * ---------------------------------------------------------------- */
int iosIoctlInternal(undefined4 param_1,int param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = iosFdMap();
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = iosFdEntryIoctl(iVar1,param_2,param_3,param_4);
    if ((((param_2 == 0x2a) || (param_2 == 0x37)) && (iVar1 == 0)) &&
       ((code *)*DAT_300ea340 != (code *)0x0)) {
      if (param_2 == 0x2a) {
        iVar3 = (int)param_3 >> 0x1f;
        piVar2 = param_3;
      }
      else {
        piVar2 = (int *)*param_3;
        iVar3 = param_3[1];
      }
      (*(code *)*DAT_300ea340)(param_1,piVar2,iVar3);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * iosIoctl @ 0x300EA068  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: iosIoctlInternal
 * Константы: 0x300EA068
 * ---------------------------------------------------------------- */
void iosIoctl(void)

{
  iosIoctlInternal();
  return;
}

/* ----------------------------------------------------------------
 * iosDrvIoctl @ 0x300EA078  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: unmount
 * Константы: 0x300EA078, 0xFFFFFFFF
 * Данные: DAT_300ea344
 * ---------------------------------------------------------------- */
undefined4 iosDrvIoctl(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = *(code **)(param_1 * 0x24 + *DAT_300ea344 + 0x18);
  if (pcVar1 == (code *)0x0) {
    errnoSet(0x23);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (*pcVar1)(0);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * iosFdEntrySet @ 0x300EA0BC  (примерный размер ~152 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: objNamePtrSet, objNameSet, strcmp
 * Вызывают: iosFdSet, iosRtpFdSetup
 * Константы: 0x300EA0BC
 * Данные: DAT_300ea320
 * ---------------------------------------------------------------- */
undefined4 iosFdEntrySet(undefined4 param_1,int param_2,char *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  char *__s2;
  
  if (param_3 == (char *)0x0) {
    uVar1 = objNamePtrSet(param_1,0);
  }
  else {
    __s2 = *(char **)(param_2 + 0xc);
    if ((__s2 == (char *)0x0) || (iVar2 = strcmp(param_3,__s2), iVar2 != 0)) {
      uVar1 = objNameSet(param_1,param_3);
    }
    else {
      uVar1 = objNamePtrSet(param_1,__s2);
    }
  }
  (*(code *)*DAT_300ea320)(param_1,param_2,param_4);
  return uVar1;
}

/* ----------------------------------------------------------------
 * iosNonRmvFdEntrySet @ 0x300EA154  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EA154
 * Данные: DAT_300ea344, DAT_300ea348
 * ---------------------------------------------------------------- */
void iosNonRmvFdEntrySet(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  *(int *)(param_1 + 0x40) = param_2;
  *(undefined4 *)(param_1 + 0x44) = param_3;
  iVar1 = DAT_300ea348;
  if (*(int *)(param_2 + 0x18) != DAT_300ea348) {
    iVar1 = *DAT_300ea344 + *(short *)(param_2 + 8) * 0x24;
  }
  *(int *)(param_1 + 0x54) = iVar1;
  return;
}

/* ----------------------------------------------------------------
 * iosFdMaxFiles @ 0x300EA194  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300edd18, iosFdShow, select
 * Константы: 0x300EA194
 * Данные: DAT_300ea34c
 * ---------------------------------------------------------------- */
undefined4 iosFdMaxFiles(void)

{
  return *(undefined4 *)(*(int *)(*DAT_300ea34c + 0x94) + 0xd0);
}

/* ----------------------------------------------------------------
 * iosRtpFdEntryMap @ 0x300EA1B0  (примерный размер ~152 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 3
 * Вызывает: iosFdTableLock, semGive, taskCpuUnlock
 * Вызывают: dup, dup2, iosRtpFdSetup
 * Константы: 0x300EA1B0, 0xFFFFFFFF
 * Данные: DAT_300ea34c
 * ---------------------------------------------------------------- */
undefined4 iosRtpFdEntryMap(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  iosFdTableLock();
  piVar1 = DAT_300ea34c;
  *(int *)(*DAT_300ea34c + 0x7c) = *(int *)(*DAT_300ea34c + 0x7c) + 1;
  *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
  taskCpuUnlock();
  piVar2 = (int *)(*(int *)(param_1 + 0xcc) + param_2 * 4);
  iVar3 = *piVar2;
  if (iVar3 == 0 || iVar3 == -1) {
    *piVar2 = param_3;
    uVar4 = 0;
  }
  else {
    *(int *)(*piVar1 + 0x7c) = *(int *)(*piVar1 + 0x7c) + 1;
    *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + -1;
    taskCpuUnlock();
    uVar4 = 0xffffffff;
  }
  semGive(*(undefined4 *)(param_1 + 200));
  return uVar4;
}

/* ----------------------------------------------------------------
 * iosRtpFdSetup @ 0x300EA248  (примерный размер ~264 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 4
 * Вызывает: iosFdEntrySet, iosRtpFdEntryMap, objCoreInit, taskCpuUnlock
 * Вызывают: creat, iosFdNew, open
 * Константы: 0x300EA248
 * Данные: DAT_300ea2f8, DAT_300ea34c
 * ---------------------------------------------------------------- */
undefined4
iosRtpFdSetup(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6)

{
  objCoreInit(param_2,DAT_300ea2f8);
  *(ushort *)(param_2 + 8) = *(ushort *)(param_2 + 8) | 0x20;
  iosFdEntrySet(param_2,param_4,param_5,param_6);
  *(undefined4 *)(param_2 + 0x4c) = 1;
  iosRtpFdEntryMap(param_1,param_3,param_2);
  *(int *)(*DAT_300ea34c + 0x7c) = *(int *)(*DAT_300ea34c + 0x7c) + 1;
  *(int *)(param_2 + 0x4c) = *(int *)(param_2 + 0x4c) + -1;
  taskCpuUnlock();
  return 0;
}

/* ----------------------------------------------------------------
 * iosFdDevFind @ 0x300EA350  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: iosFdMap
 * Константы: 0x300EA350
 * ---------------------------------------------------------------- */
undefined4 iosFdDevFind(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = iosFdMap();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x40);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * iosFdFree @ 0x300EA36C  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: iosRtpFdUnmap2
 * Константы: 0x300EA36C
 * Данные: DAT_300ea4d8
 * ---------------------------------------------------------------- */
void iosFdFree(undefined4 param_1)

{
  iosRtpFdUnmap2(*(undefined4 *)(*DAT_300ea4d8 + 0x94),param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * iosFdSet @ 0x300EA384  (примерный размер ~56 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: iosFdEntrySet, iosFdMap
 * Константы: 0x300EA384, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 iosFdSet(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = iosFdMap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  uVar2 = iosFdEntrySet(iVar1,param_2,param_3,param_4);
  return uVar2;
}

/* ----------------------------------------------------------------
 * iosFdNew @ 0x300EA3BC  (примерный размер ~148 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: iosFdEntryGet, iosRtpFdReserve, iosRtpFdSetup, iosRtpFdUnmap2
 * Константы: 0x300EA3BC
 * Данные: DAT_300ea4d8
 * ---------------------------------------------------------------- */
int iosFdNew(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = iosRtpFdReserve(*(undefined4 *)(*DAT_300ea4d8 + 0x94));
  if (iVar1 == -1) {
    iVar1 = -1;
  }
  else {
    iVar2 = iosFdEntryGet();
    if (iVar2 == 0) {
      iosRtpFdUnmap2(*(undefined4 *)(*DAT_300ea4d8 + 0x94),iVar1,0);
      iVar1 = -1;
    }
    else {
      iosRtpFdSetup(*(undefined4 *)(*DAT_300ea4d8 + 0x94),iVar2,iVar1,param_1,param_2,param_3);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * iosNextDevGet @ 0x300EA450  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EA450
 * Данные: DAT_300ea4dc
 * ---------------------------------------------------------------- */
undefined4 iosNextDevGet(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return *DAT_300ea4dc;
  }
  return *param_1;
}

/* ----------------------------------------------------------------
 * iosRtpFdTblEntryGet @ 0x300EA470  (примерный размер ~112 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: __errno, iosFdTableLock, iosFdTableUnlock
 * Вызывают: FUN_300ee694, iosRtpFdShow
 * Константы: 0x300EA470
 * ---------------------------------------------------------------- */
int iosRtpFdTblEntryGet(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iosFdTableLock();
  if (((((int)param_2 < 0) || (*(uint *)(param_1 + 0xd0) <= param_2)) ||
      (iVar2 = *(int *)(*(int *)(param_1 + 0xcc) + param_2 * 4), iVar2 == 0)) ||
     ((iVar2 == -1 || (iVar2 == -2)))) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 9;
    iVar2 = 0;
  }
  iosFdTableUnlock(param_1);
  return iVar2;
}

/* ----------------------------------------------------------------
 * iosPathLibInit @ 0x300EA4E0  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrIosCoreInit
 * Константы: 0x300EA4E0
 * Данные: DAT_300ea788, DAT_300ea78c
 * ---------------------------------------------------------------- */
void iosPathLibInit(void)

{
  *DAT_300ea78c = DAT_300ea788;
  return;
}

/* ----------------------------------------------------------------
 * iosPathFdEntryIoctl @ 0x300EA4F0  (примерный размер ~548 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: errnoSet, ioFullFileNameGet, memPartAlloc, memPartFree, objNamePtrGet
 * Константы: 0xFFFFFFFF, 0x300EA4F0
 * Данные: DAT_300ea790, DAT_300ea794, DAT_300ea798, DAT_300ea79c
 * ---------------------------------------------------------------- */
undefined4 iosPathFdEntryIoctl(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  code *in_r12;
  int local_20;
  
  if (((param_2 == 0x2f) || (param_2 == 10)) || (param_2 == 0x3a)) {
    if (((param_4 == 1) && (pcVar6 = (code *)*DAT_300ea790, pcVar6 != (code *)0x0)) &&
       (iVar2 = (*pcVar6)(param_3,1,1), in_r12 = pcVar6, iVar2 == -1)) {
      errnoSet(DAT_300ea794);
      return 0xffffffff;
    }
    iVar2 = DAT_300ea79c;
    if (param_2 == 0x3a) {
      in_r12 = (code *)0x0;
    }
    if (param_2 != 0x3a) {
      in_r12 = (code *)0x1;
    }
    iVar3 = memPartAlloc(*DAT_300ea798,DAT_300ea79c + (int)in_r12 * 0x400);
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    iVar4 = ioFullFileNameGet(param_3,&local_20,iVar3);
    if (iVar4 != 0) {
      memPartFree(*DAT_300ea798,iVar3);
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0x40) != local_20) {
      memPartFree(*DAT_300ea798,iVar3);
      errnoSet(0x12);
      return 0xffffffff;
    }
    iVar4 = iVar3;
    if (param_2 == 0x3a) {
      *(undefined4 *)(iVar3 + 0x400) = 0;
    }
    else {
      *(int *)(iVar3 + 0x400) = iVar3 + iVar2;
      uVar5 = objNamePtrGet(param_1);
      iVar2 = ioFullFileNameGet(uVar5,&local_20,iVar3 + iVar2);
      if (iVar2 != 0) {
        memPartFree(*DAT_300ea798,iVar3);
        return 0xffffffff;
      }
    }
  }
  else if ((param_2 == 0x3b) || (iVar3 = param_3, iVar4 = 0, param_2 == 0x20)) {
    if (param_3 == 0) {
      param_3 = objNamePtrGet(param_1);
    }
    puVar1 = DAT_300ea798;
    iVar3 = memPartAlloc(*DAT_300ea798,0x400);
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    iVar2 = ioFullFileNameGet(param_3,&local_20,iVar3);
    iVar4 = iVar3;
    if (iVar2 != 0) {
      memPartFree(*puVar1,iVar3);
      return 0xffffffff;
    }
  }
  uVar5 = (**(code **)(*(int *)(param_1 + 0x54) + (uint)(param_4 == 1) * 4 + 0x18))
                    (*(undefined4 *)(param_1 + 0x44),param_2,iVar3);
  if (iVar4 != 0) {
    memPartFree(*DAT_300ea798,iVar4);
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * iosRtpDefPathGet @ 0x300EA714  (примерный размер ~112 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: __errno, bcopy, strlen
 * Константы: 0xFFFFFFFF, 0x300EA714
 * ---------------------------------------------------------------- */
undefined4 iosRtpDefPathGet(int param_1,void *param_2,uint param_3)

{
  size_t sVar1;
  undefined4 *puVar2;
  char *__s;
  
  __s = *(char **)(param_1 + 0xd4);
  sVar1 = strlen(__s);
  if ((param_2 != (void *)0x0) && (param_3 != 0)) {
    if (param_3 < sVar1 + 1) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 0x26;
      return 0xffffffff;
    }
    bcopy(__s,param_2,sVar1 + 1);
    return 0;
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = 0x16;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * iosRtpDefPathSet @ 0x300EA784  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 6
 * Вызывает: __errno, close, ioctl, open, strcpy, strlen
 * Вызывают: chdir, ioDefPathCat
 * Константы: 0xFFFFFFFF, 0x300EA784
 * Данные: DAT_300e8b90
 * ---------------------------------------------------------------- */
undefined4 iosRtpDefPathSet(int param_1,char *param_2)

{
  size_t sVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int __fd;
  int iVar4;
  undefined1 auStack_58 [8];
  uint uStack_50;
  
  sVar1 = strlen(param_2);
  if ((param_1 == 0) || (*(int *)(param_1 + 0xd4) == 0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x16;
    uVar3 = 0xffffffff;
  }
  else if (*(uint *)(param_1 + 0xd8) < sVar1 + 1) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x1a;
    uVar3 = 0xffffffff;
  }
  else {
    if ((*DAT_300e8b90 == 0) && (*param_2 != '\0')) {
      __fd = open(param_2,0,0);
      if (__fd == -1) {
        puVar2 = (undefined4 *)__errno();
        *puVar2 = 0x13;
        return 0xffffffff;
      }
      iVar4 = ioctl(__fd,0x40,auStack_58);
      if (iVar4 == -1) {
        puVar2 = (undefined4 *)__errno();
        *puVar2 = 0x13;
        close(__fd);
        return 0xffffffff;
      }
      close(__fd);
      if ((uStack_50 & 0xf000) != 0x4000) {
        puVar2 = (undefined4 *)__errno();
        *puVar2 = 0x16;
        return 0xffffffff;
      }
    }
    strcpy(*(char **)(param_1 + 0xd4),param_2);
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * iosPxLibInit @ 0x300EA7A0  (примерный размер ~172 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: bzero, iosDevAdd, malloc
 * Вызывают: usrIosCoreInit
 * Константы: 0xFFFFFFFF, 0x300EA7A0
 * Данные: DAT_300eaaf8, DAT_300eaafc, DAT_300eab00, DAT_300eab04, DAT_300eab08, DAT_300eab0c, DAT_300eab10, DAT_300eab14
 * ---------------------------------------------------------------- */
undefined4 iosPxLibInit(int param_1)

{
  void *__s;
  
  if (*DAT_300eaaf8 != 0) {
    return 0xffffffff;
  }
  *DAT_300eaafc = param_1;
  *DAT_300eab04 = DAT_300eab00;
  *DAT_300eab0c = DAT_300eab08;
  if (param_1 != 0) {
    __s = malloc(0x20);
    if (__s == (void *)0x0) {
      return 0xffffffff;
    }
    bzero(__s,0x20);
    iosDevAdd(__s,DAT_300eab10,0);
    *DAT_300eab18 = DAT_300eab14;
    *DAT_300eab20 = DAT_300eab1c;
    *DAT_300eab28 = DAT_300eab24;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * iosRtpFdReserveCntrl @ 0x300EAA14  (примерный размер ~284 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: __errno, iosFdTableLock, iosFdTableUnlock
 * Вызывают: ioPxCreateOrOpen
 * Константы: 0x300EAA14
 * ---------------------------------------------------------------- */
int iosRtpFdReserveCntrl(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  
  iosFdTableLock();
  iVar2 = *(int *)(param_1 + 0xd0) + -1;
  piVar5 = (int *)(*(int *)(param_1 + 0xcc) + iVar2 * 4);
  iVar4 = *piVar5;
  iVar1 = -1;
  if (iVar4 == 0 || iVar4 == -2) {
    *piVar5 = -1;
    iVar1 = iVar2;
  }
  iosFdTableUnlock(param_1);
  if (iVar1 == -1) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 0x18;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * iosRmvLibInit @ 0x300EAB30  (примерный размер ~104 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrIosCoreInit
 * Константы: 0x300EAB30
 * Данные: DAT_300ebad0, DAT_300ebad4, DAT_300ebad8, DAT_300ebadc, DAT_300ebae0, DAT_300ebae4, DAT_300ebae8, DAT_300ebaec
 * ---------------------------------------------------------------- */
undefined4 iosRmvLibInit(void)

{
  if (*DAT_300ebad0 == 0) {
    *DAT_300ebad0 = 1;
    *DAT_300ebad8 = DAT_300ebad4;
    *DAT_300ebae0 = DAT_300ebadc;
    *DAT_300ebae8 = DAT_300ebae4;
    *DAT_300ebaf0 = DAT_300ebaec;
    *DAT_300ebaf8 = DAT_300ebaf4;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * iosDevReplaceExt @ 0x300EAB98  (примерный размер ~324 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 9
 * Вызывает: __errno, dllAdd, iosDevDelete, iosDevMatch, memPartAlloc, memPartFree, strcmp, strcpy, strlen
 * Вызывают: dosFsDevCreate, iosDevReplace, rawFsDevInit
 * Константы: 0xFFFFFFFF, 0x300EAB98
 * Данные: DAT_300ebafc, DAT_300ebb00, DAT_300ebb04, DAT_300ebb60
 * ---------------------------------------------------------------- */
undefined4 iosDevReplaceExt(int param_1,char *param_2,int param_3)

{
  undefined4 *puVar1;
  size_t sVar2;
  char *__dest;
  int iVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 0;
  if (((((param_1 == 0) || (param_2 == (char *)0x0)) || (*param_2 == '\0')) ||
      ((param_3 < 0 || (*DAT_300ebafc <= param_3)))) ||
     (*(int *)(*DAT_300ebb00 + param_3 * 0x24 + 0x20) == 0)) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    return 0xffffffff;
  }
  sVar2 = strlen(param_2);
  __dest = (char *)memPartAlloc(*DAT_300ebb04,sVar2 + 1);
  if (__dest == (char *)0x0) {
    return 0xffffffff;
  }
  strcpy(__dest,param_2);
  iVar3 = iosDevMatch(param_2);
  if (((iVar3 != 0) && (iVar4 = strcmp(*(char **)(iVar3 + 0xc),param_2), iVar4 == 0)) &&
     (iVar3 = iosDevDelete(iVar3), iVar3 == -1)) {
    memPartFree(*DAT_300ebb04,__dest);
    return 0xffffffff;
  }
  *(char **)(param_1 + 0xc) = __dest;
  *(short *)(param_1 + 8) = (short)param_3;
  *(int *)(param_1 + 0x18) = *DAT_300ebb00 + param_3 * 0x24;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  dllAdd(DAT_300ebb60,param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * iosDevReplace @ 0x300EACDC  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: iosDevReplaceExt, iosLock, iosUnlock
 * Константы: 0x300EACDC
 * ---------------------------------------------------------------- */
undefined4 iosDevReplace(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  iosLock();
  uVar1 = iosDevReplaceExt(param_1,param_2,param_3);
  iosUnlock();
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300ead10 @ 0x300EAD10  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: iosRtpDevCloseOrInvalidate
 * Константы: 0x300EAD10
 * Данные: DAT_300ebb64
 * ---------------------------------------------------------------- */
undefined4 FUN_300ead10(undefined4 param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = param_1;
  iosRtpDevCloseOrInvalidate(*DAT_300ebb64,&local_c);
  return 0;
}

/* ----------------------------------------------------------------
 * iosRmvFdEntrySet @ 0x300EAD40  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EAD40
 * Данные: DAT_300ebaec, DAT_300ebaf4, DAT_300ebb00, DAT_300ebb68
 * ---------------------------------------------------------------- */
void iosRmvFdEntrySet(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_300ebb68;
  iVar3 = DAT_300ebaec;
  iVar2 = *(int *)(param_2 + 0x18);
  if (DAT_300ebaec == iVar2) {
    *(int *)(param_1 + 0x40) = param_2;
    *(int *)(param_1 + 0x44) = param_1;
    *(undefined4 *)(param_1 + 0x48) = param_3;
    *(int *)(param_1 + 0x54) = iVar3;
    iVar3 = 0x58;
  }
  else {
    if (DAT_300ebb68 == iVar2 || DAT_300ebaf4 == iVar2) {
      *(int *)(param_1 + 0x40) = param_2;
      *(undefined4 *)(param_1 + 0x44) = param_3;
      *(int *)(param_1 + 0x54) = iVar1;
      return;
    }
    *(int *)(param_1 + 0x40) = param_2;
    *(undefined4 *)(param_1 + 0x44) = param_3;
    iVar3 = 0x54;
  }
  *(int *)(param_1 + iVar3) = *DAT_300ebb00 + *(short *)(param_2 + 8) * 0x24;
  return;
}

/* ----------------------------------------------------------------
 * iosDevSuspend @ 0x300EADC8  (примерный размер ~216 байт)
 * Модуль: kernel | Вызывают: 10 | Вызывает: 3
 * Вызывает: __errno, iosLock, iosUnlock
 * Вызывают: FUN_300ca46c, FUN_300d6fa8, FUN_300eb3c4, FUN_300eb4c4, FUN_300eb5e0, FUN_300eb680, FUN_300eb70c, FUN_300eb798, FUN_300eb824, FUN_300eb8b0
 * Константы: 0xFFFFFFFF, 0x300EADC8
 * Данные: DAT_300ebae8, DAT_300ebaec, DAT_300ebaf4, DAT_300ebafc, DAT_300ebb00, DAT_300ebb68
 * ---------------------------------------------------------------- */
undefined4 iosDevSuspend(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iosLock();
  if ((param_1 == 0) || (iVar4 = *(int *)(param_1 + 0x18), DAT_300ebb68 == iVar4)) {
    iosUnlock();
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  else {
    if (DAT_300ebaf4 != iVar4) {
      iVar3 = (int)*(short *)(param_1 + 8);
      if ((((iVar3 < 0) || (*DAT_300ebafc <= iVar3)) || (*(int *)(param_1 + 0xc) == 0)) ||
         ((iVar3 * 0x24 + *DAT_300ebb00 != iVar4 && (DAT_300ebaec != iVar4)))) {
        iosUnlock();
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 0x16;
        return 0xffffffff;
      }
      *(int *)(param_1 + 0x18) = DAT_300ebaf4;
      (*(code *)*DAT_300ebae8)(param_1);
    }
    iosUnlock();
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300eaea0 @ 0x300EAEA0  (примерный размер ~152 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: iosFdTableLock, iosFdTableUnlock
 * Вызывают: iosDevResume
 * Константы: 0x300EAEA0
 * Данные: DAT_300ebaec, DAT_300ebb00
 * ---------------------------------------------------------------- */
undefined4 FUN_300eaea0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iosFdTableLock();
  iVar3 = *(int *)(param_1 + 0xd0);
  if (0 < iVar3) {
    piVar1 = (int *)(*(int *)(param_1 + 0xcc) + -4);
    do {
      piVar1 = piVar1 + 1;
      iVar4 = *piVar1;
      if ((((iVar4 != 0) && (iVar4 != -1)) && (iVar4 != -2)) && (*(int *)(iVar4 + 0x40) == param_2))
      {
        iVar2 = DAT_300ebaec;
        if ((*(uint *)(param_2 + 0x14) & 1) == 0) {
          iVar2 = *DAT_300ebb00 + *(short *)(param_2 + 8) * 0x24;
        }
        *(int *)(iVar4 + 0x54) = iVar2;
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  iosFdTableUnlock(param_1);
  return 1;
}

/* ----------------------------------------------------------------
 * iosDevResume @ 0x300EAF38  (примерный размер ~168 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300eaea0, __errno, iosLock, iosUnlock
 * Константы: 0x300EAF38, 0xFFFFFFFF
 * Данные: DAT_300ebaec, DAT_300ebaf4, DAT_300ebafc, DAT_300ebb00, DAT_300ebb64
 * ---------------------------------------------------------------- */
undefined4 iosDevResume(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iosLock();
  if ((((param_1 != 0) && (iVar2 = (int)*(short *)(param_1 + 8), -1 < iVar2)) &&
      (iVar2 < *DAT_300ebafc)) &&
     ((*(int *)(param_1 + 0x18) == DAT_300ebaf4 && (*(int *)(param_1 + 0xc) != 0)))) {
    iVar3 = DAT_300ebaec;
    if ((*(uint *)(param_1 + 0x14) & 1) == 0) {
      iVar3 = iVar2 * 0x24 + *DAT_300ebb00;
    }
    *(int *)(param_1 + 0x18) = iVar3;
    FUN_300eaea0(*DAT_300ebb64,param_1);
    iosUnlock();
    return 0;
  }
  iosUnlock();
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 0x16;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * iosDevDelCallback @ 0x300EAFE0  (примерный размер ~128 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: __errno, iosLock, iosUnlock
 * Вызывают: dosFsDevCreate, rawFsDevInit
 * Константы: 0x300EAFE0, 0xFFFFFFFF
 * Данные: DAT_300ebaec, DAT_300ebaf4, DAT_300ebb68
 * ---------------------------------------------------------------- */
undefined4 iosDevDelCallback(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  iosLock();
  if ((((param_1 != 0) && ((*(uint *)(param_1 + 0x14) & 1) == 0)) &&
      (DAT_300ebaf4 != *(int *)(param_1 + 0x18))) && (DAT_300ebb68 != *(int *)(param_1 + 0x18))) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 1;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x1c) = param_2;
    *(undefined4 *)(param_1 + 0x18) = DAT_300ebaec;
    iosUnlock();
    return 0;
  }
  iosUnlock();
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 0x16;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300eb060 @ 0x300EB060  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: iosFdTableLock, iosFdTableUnlock
 * Вызывают: iosDevCheck
 * Константы: 0x300EB060
 * ---------------------------------------------------------------- */
bool FUN_300eb060(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  param_2[1] = 0;
  iosFdTableLock();
  iVar2 = *(int *)(param_1 + 0xd0);
  if (0 < iVar2) {
    piVar1 = (int *)(*(int *)(param_1 + 0xcc) + -4);
    do {
      piVar1 = piVar1 + 1;
      iVar3 = *piVar1;
      if ((((iVar3 != 0) && (iVar3 != -1)) && (iVar3 != -2)) && (*(int *)(iVar3 + 0x40) == *param_2)
         ) {
        param_2[1] = -1;
        break;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iosFdTableUnlock(param_1);
  return param_2[1] == 0;
}

/* ----------------------------------------------------------------
 * iosDevCheck @ 0x300EB0E8  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300eb060
 * Вызывают: unmount
 * Константы: 0x300EB0E8
 * Данные: DAT_300ebb64
 * ---------------------------------------------------------------- */
undefined4 iosDevCheck(undefined4 param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = param_1;
  FUN_300eb060(*DAT_300ebb64,&local_c);
  return local_8;
}

/* ----------------------------------------------------------------
 * iosRtpLibInit @ 0x300EBB74  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrIosCoreInit
 * Константы: 0x300EBB74
 * ---------------------------------------------------------------- */
void iosRtpLibInit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * iosRtpFdTableGet @ 0x300EBB78  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EBB78
 * ---------------------------------------------------------------- */
undefined4 iosRtpFdTableGet(int param_1)

{
  return *(undefined4 *)(param_1 + 0xcc);
}

/* ----------------------------------------------------------------
 * iosRtpIoTableSizeSet @ 0x300EBB80  (примерный размер ~204 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: bcopy, bzero, iosFdTableLock, iosFdTableUnlock, memPartAlloc, memPartFree
 * Вызывают: iosRtpTableSizeSet
 * Константы: 0x300EBB80, 0xFFFFFFFF
 * Данные: DAT_300ebcd0
 * ---------------------------------------------------------------- */
undefined4 iosRtpIoTableSizeSet(int param_1,uint param_2)

{
  void *__s;
  void *__src;
  uint uVar1;
  
  iosFdTableLock();
  uVar1 = *(uint *)(param_1 + 0xd0);
  __s = (void *)0x0;
  if (uVar1 < param_2) {
    iosFdTableUnlock(param_1);
    __s = (void *)memPartAlloc(*DAT_300ebcd0,param_2 << 2);
    if (__s == (void *)0x0) {
      return 0xffffffff;
    }
    iosFdTableLock(param_1);
    __src = *(void **)(param_1 + 0xcc);
    if (uVar1 < param_2) {
      bzero(__s,param_2 << 2);
      if (*(int *)((int)__src + uVar1 * 4 + -4) == -2) {
        *(undefined4 *)((int)__src + uVar1 * 4 + -4) = 0;
      }
      bcopy(__src,__s,uVar1 << 2);
      *(void **)(param_1 + 0xcc) = __s;
      *(uint *)(param_1 + 0xd0) = param_2;
      __s = __src;
    }
  }
  iosFdTableUnlock(param_1);
  if (__s != (void *)0x0) {
    memPartFree(*DAT_300ebcd0,__s);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * iosRtpTableSizeSet @ 0x300EBC4C  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: iosRtpIoTableSizeSet
 * Константы: 0x300EBC4C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 iosRtpTableSizeSet(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 3) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = iosRtpIoTableSizeSet();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * iosRtpIoTableSizeGet @ 0x300EBC68  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: iosFdTableLock, iosFdTableUnlock
 * Вызывают: fcntl_dup
 * Константы: 0x300EBC68
 * Данные: DAT_300ebcd4
 * ---------------------------------------------------------------- */
int iosRtpIoTableSizeGet(int param_1)

{
  int iVar1;
  int iVar2;
  
  iosFdTableLock();
  iVar2 = *(int *)(param_1 + 0xd0);
  iVar1 = *(int *)(*(int *)(param_1 + 0xcc) + iVar2 * 4 + -4);
  if ((iVar1 == -2) ||
     ((((iVar1 != 0 && (iVar1 != -1)) && (*DAT_300ebcd4 != 0)) &&
      ((*(uint *)(iVar1 + 0x50) & 0x40000) != 0)))) {
    iVar2 = iVar2 + -1;
  }
  iosFdTableUnlock(param_1);
  return iVar2;
}

/* ----------------------------------------------------------------
 * iosRtpFdTableSizeGet @ 0x300EBCCC  (примерный размер ~292 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: iosFdTableLock, iosFdTableUnlock
 * Константы: 0x300EBCCC
 * Данные: DAT_300ebcd4
 * ---------------------------------------------------------------- */
int iosRtpFdTableSizeGet(int param_1)

{
  int iVar1;
  int iVar2;
  
  iosFdTableLock();
  iVar2 = *(int *)(param_1 + 0xd0);
  iVar1 = *(int *)(*(int *)(param_1 + 0xcc) + iVar2 * 4 + -4);
  if ((iVar1 == -2) ||
     ((((iVar1 != 0 && (iVar1 != -1)) && (*DAT_300ebcd4 != 0)) &&
      ((*(uint *)(iVar1 + 0x50) & 0x40000) != 0)))) {
    iVar2 = iVar2 + -1;
  }
  iosFdTableUnlock(param_1);
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300ebdf0 @ 0x300EBDF0  (примерный размер ~116 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: __errno
 * Константы: 0x300EBDF0, 0xFFFFFFFF
 * Данные: DAT_300ebf70, DAT_300ebf74
 * ---------------------------------------------------------------- */
undefined4 FUN_300ebdf0(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (param_2 == 1) {
    if (((code *)*DAT_300ebf70 == (code *)0x0) ||
       (iVar1 = (*(code *)*DAT_300ebf70)(param_3,4,2), uVar3 = DAT_300ebf74, iVar1 != -1)) {
      *param_3 = 0;
      return 0;
    }
  }
  else {
    uVar3 = 0x23;
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = uVar3;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * iosDrvIoctlMemValSet @ 0x300EBE64  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: iosLock, iosUnlock
 * Константы: 0x300EBE64, 0xFFFFFFFF
 * Данные: DAT_300ebf78, DAT_300ebf7c
 * ---------------------------------------------------------------- */
undefined4 iosDrvIoctlMemValSet(int param_1,undefined4 param_2)

{
  iosLock();
  if ((0 < param_1) && (param_1 < *DAT_300ebf78)) {
    *(undefined4 *)(param_1 * 0x24 + *DAT_300ebf7c + 0x1c) = param_2;
    iosUnlock();
    return 0;
  }
  iosUnlock();
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * iosDrvInit @ 0x300EBEB8  (примерный размер ~240 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: iosInit
 * Константы: 0x300EBEB8
 * Данные: DAT_300ebf80, DAT_300ebf84, DAT_300ebf88, DAT_300ebf8c, DAT_300ebf90, DAT_300ebf94, DAT_300ebf98, DAT_300ebf9c
 * ---------------------------------------------------------------- */
void iosDrvInit(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  puVar2 = DAT_300ebf84;
  uVar1 = DAT_300ebf80;
  DAT_300ebf84[2] = DAT_300ebf80;
  *puVar2 = uVar1;
  puVar2[1] = uVar1;
  puVar2[5] = uVar1;
  puVar2[4] = uVar1;
  puVar2[6] = DAT_300ebf88;
  puVar2[7] = DAT_300ebf8c;
  puVar2[3] = uVar1;
  uVar1 = DAT_300ebf94;
  puVar4 = DAT_300ebf90;
  DAT_300ebf90[2] = DAT_300ebf94;
  *puVar4 = uVar1;
  puVar4[1] = uVar1;
  puVar4[5] = uVar1;
  puVar4[4] = uVar1;
  puVar4[6] = uVar1;
  puVar4[7] = uVar1;
  uVar1 = DAT_300ebf98;
  puVar4[3] = DAT_300ebf98;
  puVar4 = (undefined4 *)(param_1 + param_2 * 0x24);
  puVar4[5] = DAT_300ebf9c;
  puVar4[2] = DAT_300ebfa0;
  uVar3 = DAT_300ebfa4;
  puVar4[6] = DAT_300ebfa4;
  puVar4[7] = uVar3;
  *puVar4 = *puVar2;
  puVar4[1] = puVar2[1];
  puVar4[4] = puVar2[4];
  puVar4[3] = uVar1;
  puVar4[8] = 1;
  return;
}

/* ----------------------------------------------------------------
 * iosShowInit @ 0x300EBFA8  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EBFA8
 * ---------------------------------------------------------------- */
void iosShowInit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * iosDrvShow @ 0x300EBFAC  (примерный размер ~328 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x300EBFAC
 * Данные: DAT_300ec454, DAT_300ec458, DAT_300ec45c, DAT_300ec460, DAT_300ec464, DAT_300ec468, DAT_300ec46c, DAT_300ec470
 * ---------------------------------------------------------------- */
void iosDrvShow(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  printf(DAT_300ec468,DAT_300ec46c,DAT_300ec470,DAT_300ec474,DAT_300ec454,DAT_300ec458,DAT_300ec45c,
         DAT_300ec460,DAT_300ec464);
  iVar7 = 0;
  if (0 < *DAT_300ec478) {
    iVar8 = 0;
    do {
      iVar9 = *DAT_300ec47c;
      if (*(int *)(iVar9 + iVar8 + 0x20) != 0) {
        iVar1 = *(int *)(iVar9 + iVar8);
        if (*DAT_300ec480 == iVar1) {
          iVar1 = 0;
        }
        iVar6 = *(int *)(iVar9 + iVar8 + 4);
        if (DAT_300ec480[1] == iVar6) {
          iVar6 = 0;
        }
        iVar5 = *(int *)(iVar9 + iVar8 + 8);
        if (DAT_300ec480[2] == iVar5) {
          iVar5 = 0;
        }
        iVar2 = *(int *)(iVar9 + iVar8 + 0xc);
        if (DAT_300ec480[3] == iVar2) {
          iVar2 = 0;
        }
        iVar3 = *(int *)(iVar9 + iVar8 + 0x10);
        if (DAT_300ec480[4] == iVar3) {
          iVar3 = 0;
        }
        iVar4 = *(int *)(iVar9 + iVar8 + 0x14);
        if (DAT_300ec480[5] == iVar4) {
          iVar4 = 0;
        }
        iVar9 = *(int *)(iVar9 + iVar8 + 0x18);
        if (DAT_300ec480[6] == iVar9) {
          iVar9 = 0;
        }
        printf(DAT_300ec484,iVar7,iVar1,iVar6,iVar5,iVar2,iVar3,iVar4,iVar9);
      }
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x24;
    } while (iVar7 < *DAT_300ec478);
  }
  return;
}

/* ----------------------------------------------------------------
 * iosDevShow @ 0x300EC0F4  (примерный размер ~80 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x300EC0F4
 * Данные: DAT_300ec46c, DAT_300ec488, DAT_300ec48c, DAT_300ec490, DAT_300ec494, DAT_300ec498, DAT_300ec49c
 * ---------------------------------------------------------------- */
void iosDevShow(void)

{
  char *__format;
  int *piVar1;
  
  printf(DAT_300ec488,DAT_300ec46c,DAT_300ec48c);
  piVar1 = DAT_300ec490;
  while (piVar1 = (int *)*piVar1, piVar1 != (int *)0x0) {
    __format = DAT_300ec498;
    if (piVar1[6] != *DAT_300ec494) {
      __format = DAT_300ec49c;
    }
    printf(__format,(int)*(short *)(piVar1 + 2),piVar1[3]);
  }
  return;
}

/* ----------------------------------------------------------------
 * iosFdShow @ 0x300EC144  (примерный размер ~460 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 8
 * Вызывает: ioGlobalStdGet, iosFdMap, iosFdMaxFiles, objNamePtrGet, printf, strcat, strcpy, strlen
 * Константы: 0x300EC144
 * Данные: DAT_300ec46c, DAT_300ec48c, DAT_300ec494, DAT_300ec4a0, DAT_300ec4a4, DAT_300ec4a8, DAT_300ec4ac, DAT_300ec4b0
 * ---------------------------------------------------------------- */
void iosFdShow(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  size_t sVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  
  iVar1 = -DAT_300ec4a0;
  printf(DAT_300ec4a4,DAT_300ec4a8,DAT_300ec48c,DAT_300ec46c);
  uVar13 = 3;
  uVar3 = iosFdMaxFiles();
  if (3 < uVar3) {
    do {
      iVar4 = iosFdMap(uVar13);
      if (iVar4 != 0) {
        uVar3 = ioGlobalStdGet(0);
        iVar10 = DAT_300ec4ac;
        if (uVar3 != uVar13) {
          iVar10 = DAT_300ec4b0;
        }
        uVar3 = ioGlobalStdGet(1);
        iVar11 = DAT_300ec4b4;
        if (uVar3 != uVar13) {
          iVar11 = DAT_300ec4b0;
        }
        uVar3 = ioGlobalStdGet(2);
        iVar12 = DAT_300ec4b8;
        if (uVar3 != uVar13) {
          iVar12 = DAT_300ec4b0;
        }
        pcVar5 = (char *)objNamePtrGet(iVar4);
        iVar2 = DAT_300ec4bc;
        if (pcVar5 == (char *)0x0) {
          puVar9 = &stack0xfffffff0 + iVar1;
          iVar7 = 10;
          puVar8 = DAT_300ec4c0;
          do {
            iVar7 = iVar7 + -1;
            *puVar9 = *puVar8;
            puVar9 = puVar9 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar7 != 0);
        }
        else {
          iVar7 = *(int *)(*(int *)(iVar4 + 0x40) + 0x18);
          if (*DAT_300ec494 == iVar7) {
            puVar9 = &stack0xfffffff0 + iVar1;
            iVar7 = 0x10;
            puVar8 = DAT_300ec4c4;
            do {
              iVar7 = iVar7 + -1;
              *puVar9 = *puVar8;
              puVar9 = puVar9 + 1;
              puVar8 = puVar8 + 1;
            } while (iVar7 != 0);
          }
          else {
            if ((DAT_300ec4bc != iVar7) && (*(int *)(iVar4 + 0x54) != DAT_300ec4bc)) {
              strcpy(&stack0xfffffff0 + iVar1,pcVar5);
              goto LAB_300ec28c;
            }
            puVar9 = &stack0xfffffff0 + iVar1;
            iVar7 = 0xe;
            puVar8 = DAT_300ec4c8;
            do {
              iVar7 = iVar7 + -1;
              *puVar9 = *puVar8;
              puVar9 = puVar9 + 1;
              puVar8 = puVar8 + 1;
            } while (iVar7 != 0);
          }
          strcat(&stack0xfffffff0 + iVar1,pcVar5);
        }
LAB_300ec28c:
        sVar6 = strlen(&stack0xfffffff0 + iVar1);
        if (*(int *)(iVar4 + 0x54) == iVar2) {
          pcVar5 = DAT_300ec4cc;
          if (0x26 < (int)sVar6) {
            pcVar5 = DAT_300ec4d0;
          }
          *(int *)(&stack0xffffffe4 + iVar1) = iVar11;
          *(int *)(&stack0xffffffe8 + iVar1) = iVar12;
        }
        else {
          pcVar5 = DAT_300ec4d4;
          if (0x26 < (int)sVar6) {
            pcVar5 = DAT_300ec4d8;
          }
          *(int *)(&stack0xffffffe8 + iVar1) = iVar11;
          *(int *)(&stack0xffffffec + iVar1) = iVar12;
          *(int *)(&stack0xffffffe4 + iVar1) = iVar10;
          iVar10 = (int)*(short *)(*(int *)(iVar4 + 0x40) + 8);
        }
        printf(pcVar5,uVar13,&stack0xfffffff0 + iVar1,iVar10);
      }
      uVar13 = uVar13 + 1;
      uVar3 = iosFdMaxFiles();
    } while (uVar13 < uVar3);
  }
  return;
}

/* ----------------------------------------------------------------
 * iosRtpFdShow @ 0x300EC310  (примерный размер ~468 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 6
 * Вызывает: __errno, iosRtpFdTblEntryGet, objNamePtrGet, printf, strcat, strcpy
 * Константы: 0x300EC310
 * Данные: DAT_300ec494, DAT_300ec4bc, DAT_300ec4c0, DAT_300ec4c4, DAT_300ec4c8, DAT_300ec4dc, DAT_300ec4e0
 * ---------------------------------------------------------------- */
undefined4 iosRtpFdShow(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  char local_414 [1024];
  
  if (param_1 == 0) {
    param_1 = *(int *)(*DAT_300ec4dc + 0x94);
  }
  iVar7 = *(int *)(param_1 + 0xd0);
  iVar8 = 0;
  if (0 < iVar7) {
    do {
      iVar1 = iosRtpFdTblEntryGet(param_1,iVar8);
      if (iVar1 != 0) {
        pcVar2 = (char *)objNamePtrGet(iVar1);
        if (pcVar2 == (char *)0x0) {
          iVar4 = 10;
          puVar5 = DAT_300ec4c0;
          pcVar2 = local_414;
          do {
            iVar4 = iVar4 + -1;
            *pcVar2 = *puVar5;
            pcVar2 = pcVar2 + 1;
            puVar5 = puVar5 + 1;
          } while (iVar4 != 0);
        }
        else {
          iVar4 = *(int *)(*(int *)(iVar1 + 0x40) + 0x18);
          if (*DAT_300ec494 == iVar4) {
            iVar4 = 0x10;
            puVar5 = DAT_300ec4c4;
            pcVar6 = local_414;
            do {
              iVar4 = iVar4 + -1;
              *pcVar6 = *puVar5;
              pcVar6 = pcVar6 + 1;
              puVar5 = puVar5 + 1;
            } while (iVar4 != 0);
          }
          else {
            if ((DAT_300ec4bc != iVar4) && (*(int *)(iVar1 + 0x54) != DAT_300ec4bc)) {
              strcpy(local_414,pcVar2);
              goto LAB_300ec418;
            }
            iVar4 = 0xe;
            puVar5 = DAT_300ec4c8;
            pcVar6 = local_414;
            do {
              iVar4 = iVar4 + -1;
              *pcVar6 = *puVar5;
              pcVar6 = pcVar6 + 1;
              puVar5 = puVar5 + 1;
            } while (iVar4 != 0);
          }
          strcat(local_414,pcVar2);
        }
LAB_300ec418:
        printf(DAT_300ec4e0,iVar8,iVar1,local_414);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar7);
  }
  puVar3 = (undefined4 *)__errno();
  *puVar3 = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * pipeDrv @ 0x300ECB28  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: iosDrvInstall
 * Вызывают: usrIosExtraInit
 * Константы: 0xFFFFFFFF, 0x300ECB28
 * Данные: DAT_300ed308, DAT_300ed30c, DAT_300ed310, DAT_300ed314, DAT_300ed318, DAT_300ed31c
 * ---------------------------------------------------------------- */
int * pipeDrv(void)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  
  piVar1 = DAT_300ed308;
  bVar3 = *DAT_300ed308 == -1;
  piVar2 = DAT_300ed308;
  if (bVar3) {
    piVar2 = (int *)iosDrvInstall(0,0,DAT_300ed318,DAT_300ed31c,DAT_300ed30c,DAT_300ed310,
                                  DAT_300ed314);
    bVar3 = piVar2 == (int *)0xffffffff;
    *piVar1 = (int)piVar2;
    if (bVar3) {
      piVar2 = (int *)0xffffffff;
    }
  }
  if (!bVar3) {
    piVar2 = (int *)0x0;
  }
  return piVar2;
}

/* ----------------------------------------------------------------
 * pipeDevCreate @ 0x300ECB8C  (примерный размер ~352 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 10
 * Вызывает: __errno, errnoSet, intContext, iosDevAdd, memPartAlloc, memPartFree, msgQCreate, msgQDelete, selWakeupListInit, selWakeupListTerm
 * Константы: 0xFFFFFFFF, 0x300ECB8C
 * Данные: DAT_300ed308, DAT_300ed320, DAT_300ed324, DAT_300ed328
 * ---------------------------------------------------------------- */
undefined4 pipeDevCreate(char *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = intContext();
  piVar1 = DAT_300ed308;
  if (iVar2 == 0) {
    if (*DAT_300ed308 == -1) {
      errnoSet(6);
      uVar4 = 0xffffffff;
    }
    else if ((((param_1 == (char *)0x0) || (*param_1 == '\0')) || (param_2 < 1)) || (param_3 < 1)) {
      errnoSet(0x16);
      uVar4 = 0xffffffff;
    }
    else {
      iVar2 = memPartAlloc(*DAT_300ed324,0xc0);
      if (iVar2 == 0) {
        uVar4 = 0xffffffff;
      }
      else {
        *(int *)(iVar2 + 0x24) = param_2;
        *(int *)(iVar2 + 0x28) = param_3;
        *(undefined4 *)(iVar2 + 0xbc) = 0;
        iVar5 = msgQCreate(param_2,param_3,*DAT_300ed328);
        *(int *)(iVar2 + 0x20) = iVar5;
        if (iVar5 == 0) {
          memPartFree(*DAT_300ed324,iVar2);
          uVar4 = 0xffffffff;
        }
        else {
          *(ushort *)(iVar5 + 8) = *(ushort *)(iVar5 + 8) | 0x20;
          selWakeupListInit(iVar2 + 0x2c);
          iVar5 = iosDevAdd(iVar2,param_1,*piVar1);
          if (iVar5 == 0) {
            uVar4 = 0;
          }
          else {
            selWakeupListTerm(iVar2 + 0x2c);
            msgQDelete(*(undefined4 *)(iVar2 + 0x20));
            memPartFree(*DAT_300ed324,iVar2);
            uVar4 = 0xffffffff;
          }
        }
      }
    }
  }
  else {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = DAT_300ed320;
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * pipeDevDelete @ 0x300ECCEC  (примерный размер ~420 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 12
 * Вызывает: __errno, intContext, iosDevDelete, iosDevFind, lstFirst, lstFree, lstNext, memPartFree, msgQDelete, selNodeDelete, selWakeupListLen, selWakeupListTerm
 * Константы: 0xFFFFFFFF, 0x300ECCEC
 * Данные: DAT_300ed308, DAT_300ed320, DAT_300ed324
 * ---------------------------------------------------------------- */
undefined4 pipeDevDelete(char *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_14;
  
  local_14 = 0;
  iVar2 = intContext();
  piVar1 = DAT_300ed308;
  if (iVar2 == 0) {
    if (*DAT_300ed308 == -1) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 6;
      uVar4 = 0xffffffff;
    }
    else if ((((param_2 == 1) || (param_2 == 0)) && (param_1 != (char *)0x0)) && (*param_1 != '\0'))
    {
      iVar2 = iosDevFind(param_1,&local_14);
      if ((iVar2 == 0) || ((int)*(short *)(iVar2 + 8) != *piVar1)) {
        puVar3 = (undefined4 *)__errno();
        *puVar3 = 0x13;
        uVar4 = 0xffffffff;
      }
      else {
        if (param_2 == 0) {
          if (*(int *)(iVar2 + 0xbc) != 0) {
            puVar3 = (undefined4 *)__errno();
            *puVar3 = 0x18;
            return 0xffffffff;
          }
          iVar5 = selWakeupListLen(iVar2 + 0x2c);
          if (iVar5 != 0) {
            puVar3 = (undefined4 *)__errno();
            *puVar3 = 0x10;
            return 0xffffffff;
          }
        }
        iosDevDelete(iVar2);
        if ((param_2 != 0) && (iVar5 = selWakeupListLen(iVar2 + 0x2c), iVar5 != 0)) {
          iVar5 = lstFirst(iVar2 + 0x2c);
          do {
            selNodeDelete(iVar2 + 0x2c,iVar5);
            iVar5 = lstNext(iVar5);
          } while (iVar5 != 0);
          lstFree(iVar2 + 0x2c);
        }
        selWakeupListTerm(iVar2 + 0x2c);
        msgQDelete(*(undefined4 *)(iVar2 + 0x20));
        memPartFree(*DAT_300ed324,iVar2);
        uVar4 = 0;
      }
    }
    else {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0x16;
      uVar4 = 0xffffffff;
    }
  }
  else {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = DAT_300ed320;
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * FUN_300ece90 @ 0x300ECE90  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: errnoSet, strlen
 * Константы: 0x300ECE90
 * ---------------------------------------------------------------- */
int FUN_300ece90(int param_1,char *param_2)

{
  size_t sVar1;
  
  if ((param_2 != (char *)0x0) && (sVar1 = strlen(param_2), sVar1 != 0)) {
    errnoSet(0x13);
    return -1;
  }
  *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + 1;
  return param_1;
}

/* ----------------------------------------------------------------
 * FUN_300ecefc @ 0x300ECEFC  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: msgQReceive, selWakeupAll
 * Константы: 0x300ECEFC, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int FUN_300ecefc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = msgQReceive(*(undefined4 *)(param_1 + 0x20),param_2,param_3,0xffffffff);
  if (iVar1 == -1) {
    return -1;
  }
  selWakeupAll(param_1 + 0x2c,1);
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300ecf38 @ 0x300ECF38  (примерный размер ~200 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 6
 * Вызывает: intContext, msgQSend, selWakeupAll, semGive, semTake, taskCpuUnlock
 * Константы: 0xFFFFFFFF, 0x300ECF38
 * Данные: DAT_300ed32c
 * ---------------------------------------------------------------- */
undefined4 FUN_300ecf38(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = intContext();
  if (iVar1 == 0) {
    *(int *)(*DAT_300ed32c + 0x7c) = *(int *)(*DAT_300ed32c + 0x7c) + 1;
  }
  intContext();
  iVar1 = msgQSend(*(undefined4 *)(param_1 + 0x20),param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = intContext();
    if (iVar1 == 0) {
      semTake(param_1 + 0x2c,0xffffffff);
      taskCpuUnlock();
    }
    selWakeupAll(param_1 + 0x2c,0);
    iVar1 = intContext();
    if (iVar1 == 0) {
      semGive(param_1 + 0x2c);
    }
  }
  else {
    iVar1 = intContext();
    if (iVar1 == 0) {
      taskCpuUnlock();
    }
    param_3 = 0xffffffff;
  }
  return param_3;
}

/* ----------------------------------------------------------------
 * FUN_300ed000 @ 0x300ED000  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: bzero, errnoSet
 * Вызывают: FUN_300ed06c
 * Константы: 0x300ED000, 0xFFFFFFFF
 * Данные: DAT_300ed330
 * ---------------------------------------------------------------- */
undefined4 FUN_300ed000(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    errnoSet(0x16);
    return 0xffffffff;
  }
  bzero(param_2,0x48);
  *param_2 = param_1;
  param_2[3] = *(int *)(param_1 + 0xbc);
  iVar1 = *(int *)(param_1 + 0x28) * *(int *)(param_1 + 0x24);
  param_2[6] = iVar1;
  param_2[7] = iVar1 >> 0x1f;
  param_2[2] = param_2[2] | DAT_300ed330;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ed06c @ 0x300ED06C  (примерный размер ~724 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 12
 * Вызывает: FUN_300ed000, bzero, errnoSet, msgQInfoGet, msgQNumMsgs, msgQReceive, selNodeAdd, selNodeDelete, selWakeup, selWakeupAll, taskCpuLock, taskCpuUnlock
 * Константы: 0x300ED06C
 * Данные: DAT_300ed334, DAT_300ed338, DAT_300ed33c
 * ---------------------------------------------------------------- */
int FUN_300ed06c(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  undefined1 auStack_54 [8];
  undefined1 auStack_4c [8];
  undefined1 auStack_44 [36];
  undefined4 local_20;
  int *local_18;
  
  piVar1 = DAT_300ed334;
  if (param_2 == 0x1d) {
    if (*DAT_300ed334 != 0) {
      (*(code *)*DAT_300ed338)(auStack_54);
      (*(code *)*piVar1)(3,auStack_54,auStack_4c);
    }
    iVar2 = selNodeDelete(param_1 + 0x2c,param_3);
    pcVar3 = (code *)*piVar1;
    if (pcVar3 == (code *)0x0) {
      return iVar2;
    }
    (*pcVar3)(3,auStack_4c,0);
    return iVar2;
  }
  if (param_2 < 0x1e) {
    if (param_2 == 1) {
      bzero(auStack_44,0x30);
      local_20 = 1;
      *param_3 = 0;
      local_18 = param_3;
      iVar2 = msgQInfoGet(*(undefined4 *)(param_1 + 0x20),auStack_44);
      return iVar2;
    }
    if (param_2 == 2) {
      taskCpuLock();
      do {
        iVar2 = msgQReceive(*(undefined4 *)(param_1 + 0x20),0,0,0);
      } while (iVar2 != -1);
      taskCpuUnlock();
      selWakeupAll(param_1 + 0x2c,1);
      return 0;
    }
    if (param_2 == 0x11) {
      iVar2 = msgQNumMsgs(*(undefined4 *)(param_1 + 0x20));
      *param_3 = iVar2;
      return 0;
    }
    if (param_2 == 0x1c) {
      if (*DAT_300ed334 != 0) {
        (*(code *)*DAT_300ed338)(auStack_54);
        (*(code *)*DAT_300ed334)(3,auStack_54,auStack_4c);
      }
      iVar2 = selNodeAdd(param_1 + 0x2c,param_3);
      if ((code *)*DAT_300ed334 != (code *)0x0) {
        (*(code *)*DAT_300ed334)(3,auStack_4c,0);
      }
      if (iVar2 != 0) {
        return iVar2;
      }
      if (param_3[5] == 0) {
        iVar2 = msgQNumMsgs(*(undefined4 *)(param_1 + 0x20));
        if (iVar2 < 1) {
          return 0;
        }
      }
      else {
        if (param_3[5] != 1) {
          return 0;
        }
        iVar2 = msgQNumMsgs(*(undefined4 *)(param_1 + 0x20));
        if (*(int *)(param_1 + 0x24) <= iVar2) {
          return 0;
        }
      }
      selWakeup(param_3);
      return 0;
    }
  }
  else {
    if (param_2 == 0x3d) {
      if (*param_3 != 0xc) {
        errnoSet(0x16);
        return -1;
      }
      *param_3 = -1;
      return 0;
    }
    if (param_2 == 0x3e) {
      if (*param_3 == 3) {
        *(uint *)param_3[1] = 2;
        return 0;
      }
      if ((*(uint *)param_3[1] & DAT_300ed33c) != 0) {
        return 0;
      }
      return -1;
    }
    if (param_2 == 0x40) {
      iVar2 = FUN_300ed000(param_1,param_3);
      return iVar2;
    }
  }
  errnoSet(0x23);
  return -1;
}

/* ----------------------------------------------------------------
 * selectInit @ 0x300EDDF4  (примерный размер ~304 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300edd18, __errno, taskCreateHookAdd
 * Вызывают: usrIosCoreInit
 * Константы: 0x300EDDF4
 * Данные: DAT_300eed64, DAT_300eed68, DAT_300eed6c, DAT_300eed70, DAT_300eed74, DAT_300eed78, DAT_300eed7c, DAT_300eed80
 * ---------------------------------------------------------------- */
void selectInit(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  
  *DAT_300eed68 = DAT_300eed64;
  *DAT_300eed70 = DAT_300eed6c;
  *DAT_300eed78 = DAT_300eed74;
  *DAT_300eed80 = DAT_300eed7c;
  *DAT_300eed88 = DAT_300eed84;
  *DAT_300eed90 = DAT_300eed8c;
  *DAT_300eed98 = DAT_300eed94;
  *DAT_300eeda0 = DAT_300eed9c;
  *DAT_300eeda8 = DAT_300eeda4;
  *DAT_300eedb0 = DAT_300eedac;
  iVar1 = taskCreateHookAdd(DAT_300eedb4);
  if (iVar1 == 0) {
    if (*(int *)(*DAT_300eedc0 + 0xdc) != 0) {
      return;
    }
    iVar1 = FUN_300edd18(*DAT_300eedc0);
    if (iVar1 != -1) {
      return;
    }
    if (*DAT_300eedb8 == 0) {
      return;
    }
    puVar2 = (undefined4 *)__errno();
    uVar4 = *puVar2;
    pcVar5 = (code *)*DAT_300eedb8;
    uVar3 = DAT_300eedc4;
  }
  else {
    pcVar5 = (code *)*DAT_300eedb8;
    if (pcVar5 == (code *)0x0) {
      return;
    }
    uVar4 = 0;
    uVar3 = DAT_300eedbc;
  }
  (*pcVar5)(uVar3,uVar4,0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * select @ 0x300EE044  (примерный размер ~1616 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 13
 * Вызывает: FUN_300edf80, __errno, __udiv32, bcopy, bzero, errnoGet, errnoSet, free, iosFdMaxFiles, malloc, semTake, sysClkRateGet, taskUnsafe
 * Вызывают: BSP_OsWait, FUN_30112ec0, shellBackgroundRead, shellInOutBlockingBlock, tipStart
 * Константы: 0x7FFFFFFF, 0x300EE044, 0xFFFFFFFF
 * Данные: DAT_300eedc0, DAT_300eeee8, DAT_300eeeec, DAT_300eeef0, DAT_300eeef4
 * ---------------------------------------------------------------- */
int select(int __nfds,fd_set *__readfds,fd_set *__writefds,fd_set *__exceptfds,timeval *__timeout)

{
  size_t __n;
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  int iVar11;
  undefined1 auStack_44 [12];
  int local_38;
  undefined2 local_32;
  undefined4 local_30;
  fd_set *local_2c;
  
  iVar11 = 0;
  iVar9 = *(int *)(*DAT_300eedc0 + 0xdc);
  iVar1 = iosFdMaxFiles();
  if (iVar9 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_300eeee8;
    return -1;
  }
  if (__nfds == 0x800) {
    __nfds = iVar1;
  }
  if ((__nfds < 0) || (iVar1 < __nfds)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_300eeeec;
    return -1;
  }
  if (*(int *)(iVar9 + 0x84) < __nfds) {
    uVar8 = iVar1 + 0x1fU >> 5;
    *(undefined4 *)(iVar9 + 0x84) = 0;
    free(*(void **)(iVar9 + 0x78));
    pvVar3 = malloc(uVar8 * 0xc);
    if (pvVar3 == (void *)0x0) {
      return -1;
    }
    *(void **)(iVar9 + 0x78) = pvVar3;
    *(void **)(iVar9 + 0x7c) = (void *)((int)pvVar3 + uVar8 * 4);
    *(void **)(iVar9 + 0x80) = (void *)(uVar8 * 8 + (int)pvVar3);
    *(int *)(iVar9 + 0x84) = iVar1;
  }
  __n = (__nfds + 0x1fU >> 5) << 2;
  if (__readfds == (fd_set *)0x0) {
    bzero(*(void **)(iVar9 + 0x78),__n);
  }
  else {
    bcopy(__readfds,*(void **)(iVar9 + 0x78),__n);
  }
  if (__writefds == (fd_set *)0x0) {
    bzero(*(void **)(iVar9 + 0x7c),__n);
  }
  else {
    bcopy(__writefds,*(void **)(iVar9 + 0x7c),__n);
  }
  if (__exceptfds == (fd_set *)0x0) {
    bzero(*(void **)(iVar9 + 0x80),__n);
  }
  else {
    bcopy(__exceptfds,*(void **)(iVar9 + 0x80),__n);
  }
  uVar8 = 0;
  if (__timeout != (timeval *)0x0) {
    iVar1 = sysClkRateGet();
    iVar6 = __timeout->tv_sec;
    uVar7 = iVar6 * iVar1;
    if ((iVar1 == 0) || (iVar4 = __udiv32(uVar7,iVar1), iVar4 == iVar6)) {
      uVar8 = uVar7;
      if (0 < __timeout->tv_usec) {
        uVar5 = __udiv32(DAT_300eeef0,iVar1);
        iVar1 = __udiv32(__timeout->tv_usec,uVar5);
        uVar8 = iVar1 + uVar7 + 1;
        if (uVar8 < uVar7) goto LAB_300ee224;
      }
    }
    else {
LAB_300ee224:
      uVar8 = 0x7fffffff;
    }
  }
  *(fd_set **)(iVar9 + 0x6c) = __readfds;
  *(fd_set **)(iVar9 + 0x70) = __writefds;
  *(fd_set **)(iVar9 + 0x74) = __exceptfds;
  *(undefined4 *)(iVar9 + 0x8c) = 0;
  puVar2 = (undefined4 *)__errno();
  uVar5 = *puVar2;
  semTake(iVar9,0);
  puVar2 = (undefined4 *)__errno();
  *puVar2 = uVar5;
  local_38 = *DAT_300eedc0;
  local_32 = 0;
  if (__readfds != (fd_set *)0x0) {
    bzero(__readfds,__n);
  }
  if (__writefds != (fd_set *)0x0) {
    bzero(__writefds,__n);
  }
  if (__exceptfds != (fd_set *)0x0) {
    bzero(__exceptfds,__n);
  }
  iVar1 = 0;
  *(int *)(*DAT_300eedc0 + 0xac) = *(int *)(*DAT_300eedc0 + 0xac) + 1;
  if (__readfds == (fd_set *)0x0) {
LAB_300ee304:
    if (__writefds != (fd_set *)0x0) {
      local_30 = 1;
      local_2c = __writefds;
      iVar6 = FUN_300edf80(*(undefined4 *)(iVar9 + 0x7c),__nfds,0x1c,auStack_44,1);
      if (iVar6 != 0) {
        iVar1 = -1;
      }
    }
    if ((iVar1 == -1) || (__exceptfds == (fd_set *)0x0)) goto LAB_300ee380;
    local_30 = 2;
    local_2c = __exceptfds;
    iVar6 = FUN_300edf80(*(undefined4 *)(iVar9 + 0x80),__nfds,0x1c,auStack_44,1);
    bVar10 = iVar6 == 0;
  }
  else {
    local_30 = 0;
    local_2c = __readfds;
    iVar6 = FUN_300edf80(*(undefined4 *)(iVar9 + 0x78),__nfds,0x1c,auStack_44,1);
    bVar10 = iVar6 == 0;
    if (bVar10) goto LAB_300ee304;
  }
  if (!bVar10) {
    iVar1 = -1;
  }
LAB_300ee380:
  if (iVar1 == 0) {
    if (__timeout == (timeval *)0x0) {
      uVar8 = 0xffffffff;
    }
    else if (0x7fffffff < uVar8) {
      uVar8 = 0x7fffffff;
    }
    *(int *)(iVar9 + 0x88) = __nfds;
    *(undefined4 *)(iVar9 + 0x68) = 1;
    taskUnsafe();
    iVar1 = semTake(iVar9,uVar8);
    if ((iVar1 == -1) && (iVar6 = errnoGet(), iVar6 == 4)) {
      errnoSet(4);
      iVar11 = -1;
    }
    else {
      iVar6 = 0;
      *(int *)(*DAT_300eedc0 + 0xac) = *(int *)(*DAT_300eedc0 + 0xac) + 1;
      if (__readfds != (fd_set *)0x0) {
        local_30 = 0;
        iVar4 = FUN_300edf80(*(undefined4 *)(iVar9 + 0x78),__nfds,0x1d,auStack_44,0,iVar11,iVar1);
        if (iVar4 != 0) {
          iVar6 = -1;
        }
      }
      if (__writefds != (fd_set *)0x0) {
        local_30 = 1;
        iVar4 = FUN_300edf80(*(undefined4 *)(iVar9 + 0x7c),__nfds,0x1d,auStack_44,0,iVar11,iVar1);
        if (iVar4 != 0) {
          iVar6 = -1;
        }
      }
      if (__exceptfds != (fd_set *)0x0) {
        local_30 = 2;
        iVar1 = FUN_300edf80(*(undefined4 *)(iVar9 + 0x80),__nfds,0x1d,auStack_44,0,iVar11,iVar1);
        if (iVar1 != 0) {
          iVar6 = -1;
        }
      }
      iVar1 = *(int *)(iVar9 + 0x8c);
      *(undefined4 *)(iVar9 + 0x68) = 0;
      taskUnsafe();
      if ((iVar1 == 0) && (iVar6 == 0)) {
        if ((__readfds != (fd_set *)0x0) && (uVar8 = 0, 0 < __nfds)) {
          do {
            if (__readfds->fds_bits[uVar8 >> 5] == 0) {
              uVar8 = uVar8 + 0x1f;
            }
            else if ((__readfds->fds_bits[uVar8 >> 5] & 1 << (uVar8 & 0x1f)) != 0) {
              iVar11 = iVar11 + 1;
            }
            uVar8 = uVar8 + 1;
          } while ((int)uVar8 < __nfds);
        }
        if ((__writefds != (fd_set *)0x0) && (uVar8 = 0, 0 < __nfds)) {
          do {
            if (__writefds->fds_bits[uVar8 >> 5] == 0) {
              uVar8 = uVar8 + 0x1f;
            }
            else if ((__writefds->fds_bits[uVar8 >> 5] & 1 << (uVar8 & 0x1f)) != 0) {
              iVar11 = iVar11 + 1;
            }
            uVar8 = uVar8 + 1;
          } while ((int)uVar8 < __nfds);
        }
        if ((__exceptfds != (fd_set *)0x0) && (uVar8 = 0, 0 < __nfds)) {
          do {
            if (__exceptfds->fds_bits[uVar8 >> 5] == 0) {
              uVar8 = uVar8 + 0x1f;
            }
            else if ((__exceptfds->fds_bits[uVar8 >> 5] & 1 << (uVar8 & 0x1f)) != 0) {
              iVar11 = iVar11 + 1;
            }
            uVar8 = uVar8 + 1;
          } while ((int)uVar8 < __nfds);
        }
      }
      else {
        errnoSet(9);
        iVar11 = -1;
      }
    }
  }
  else {
    iVar1 = errnoGet();
    if (__readfds != (fd_set *)0x0) {
      local_30 = 0;
      FUN_300edf80(*(undefined4 *)(iVar9 + 0x78),__nfds,0x1d,auStack_44,0);
    }
    if (__writefds != (fd_set *)0x0) {
      local_30 = 1;
      FUN_300edf80(*(undefined4 *)(iVar9 + 0x7c),__nfds,0x1d,auStack_44,0);
    }
    if (__exceptfds != (fd_set *)0x0) {
      local_30 = 2;
      FUN_300edf80(*(undefined4 *)(iVar9 + 0x80),__nfds,0x1d,auStack_44,0);
    }
    taskUnsafe();
    if (iVar1 == 0x23) {
      errnoSet(DAT_300eeef4);
    }
    iVar11 = -1;
  }
  return iVar11;
}

/* ----------------------------------------------------------------
 * FUN_300ee694 @ 0x300EE694  (примерный размер ~404 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: __errno, ioTaskStdGet, iosFdEntryIoctl, iosFdTableLock, iosFdTableUnlock, iosRtpFdTblEntryGet
 * Вызывают: FUN_300eeb94
 * Константы: 0xFFFFFFFF, 0x300EE694
 * Данные: DAT_300eeef8
 * ---------------------------------------------------------------- */
undefined4
FUN_300ee694(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar3 = 0;
  *(undefined2 *)(param_5 + 0x12) = 0;
  uVar6 = 0;
  if (0 < param_3) {
    do {
      uVar4 = *(uint *)(param_2 + (uVar6 >> 5) * 4);
      if (uVar4 == 0) {
        uVar6 = uVar6 + 0x1f;
      }
      else if ((uVar4 & 1 << (uVar6 & 0x1f)) != 0) {
        *(short *)(param_5 + 0x10) = (short)uVar6;
        if (((*DAT_300eeef8 == *(int *)(param_1 + 0x94)) && (-1 < (int)uVar6)) && ((int)uVar6 < 3))
        {
          uVar6 = ioTaskStdGet(param_1,uVar6);
          iosFdTableLock(*(undefined4 *)(param_1 + 0x94));
          if ((((int)uVar6 < 0) || (*(uint *)(*DAT_300eeef8 + 0xd0) <= uVar6)) ||
             ((iVar5 = *(int *)(*(int *)(*DAT_300eeef8 + 0xcc) + uVar6 * 4), iVar5 == 0 ||
              ((iVar5 == -1 || (iVar5 == -2)))))) {
            puVar1 = (undefined4 *)__errno();
            *puVar1 = 9;
            iVar5 = 0;
          }
          iosFdTableUnlock(*(undefined4 *)(param_1 + 0x94));
        }
        else {
          iVar5 = iosRtpFdTblEntryGet(*(int *)(param_1 + 0x94),uVar6);
        }
        if (iVar5 == 0) {
          uVar3 = 0xffffffff;
          if (param_6 != 0) {
            return 0xffffffff;
          }
        }
        else {
          iVar5 = iosFdEntryIoctl(iVar5,param_4,param_5,0);
          if ((iVar5 != 0) && (uVar3 = 0xffffffff, param_6 != 0)) {
            return 0xffffffff;
          }
          if (*(short *)(param_5 + 0x12) != 0) {
            puVar2 = (uint *)(*(int *)(param_5 + 0x18) + (uVar6 >> 5) * 4);
            *puVar2 = *puVar2 | 1 << (uVar6 & 0x1f);
            *(undefined2 *)(param_5 + 0x12) = 0;
          }
        }
      }
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < param_3);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * tyLibInit @ 0x300EF200  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrIosCoreInit
 * Константы: 0x300EF200, 0xFFFFFFFF
 * Данные: DAT_300ef73c
 * ---------------------------------------------------------------- */
undefined4 tyLibInit(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_300ef73c;
  if ((((param_2 < param_1) && (0 < param_3)) && (param_1 < 100)) && (0 < param_2)) {
    *(int *)(DAT_300ef73c + 0xc) = param_1;
    *(int *)(iVar1 + 0x10) = param_2;
    *(int *)(iVar1 + 0x18) = param_3;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300ef24c @ 0x300EF24C  (примерный размер ~168 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 2
 * Вызывает: spinLockIsrGive, spinLockIsrTake
 * Вызывают: FUN_300ef2f4, tyIRd, tyRead, tyXoffHookSet
 * Константы: 0x300EF24C
 * Данные: DAT_300ef740
 * ---------------------------------------------------------------- */
void FUN_300ef24c(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = param_1 + 0x22c;
  spinLockIsrTake(iVar1);
  if (*(byte *)(param_1 + 0xf6) != param_2) {
    *(char *)(param_1 + 0xf6) = (char)param_2;
    if (*(int *)(param_1 + 0x220) != 0) {
      spinLockIsrGive(iVar1);
      (**(code **)(param_1 + 0x220))(*(undefined4 *)(param_1 + 0x224),param_2);
      return;
    }
    *(undefined1 *)(param_1 + 0xf7) = 1;
    if (*(char *)(param_1 + 0x16a) == '\0') {
      *(undefined1 *)(param_1 + DAT_300ef740) = 1;
      spinLockIsrGive(iVar1);
      (**(code **)(param_1 + 0x174))(param_1);
      return;
    }
  }
  spinLockIsrGive(iVar1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ef2f4 @ 0x300EF2F4  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300ef24c, __errno, rngFlush, semGive, semTake
 * Вызывают: tyDevInit
 * Константы: 0x300EF2F4, 0xFFFFFFFF
 * Данные: DAT_300ef744
 * ---------------------------------------------------------------- */
void FUN_300ef2f4(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  semTake(param_1 + 0x8c,0xffffffff);
  *(undefined1 *)(param_1 + 0xf8) = 1;
  rngFlush(*(undefined4 *)(param_1 + 0x20));
  puVar1 = (undefined4 *)__errno();
  uVar3 = *puVar1;
  semTake(param_1 + 0x24,0);
  piVar2 = (int *)__errno();
  if (*piVar2 == DAT_300ef744) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = uVar3;
  }
  *(undefined1 *)(param_1 + 0x170) = 0;
  *(undefined1 *)(param_1 + 0x171) = 0;
  FUN_300ef24c(param_1,0);
  *(undefined1 *)(param_1 + 0xf8) = 0;
  semGive(param_1 + 0x8c);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ef370 @ 0x300EF370  (примерный размер ~120 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: rngFlush, semGive, semTake
 * Вызывают: tyDevInit
 * Константы: 0x300EF370, 0xFFFFFFFF
 * Данные: DAT_300ef748, DAT_300ef74c
 * ---------------------------------------------------------------- */
void FUN_300ef370(int param_1)

{
  int iVar1;
  
  semTake(param_1 + 0x8c,0xffffffff);
  iVar1 = DAT_300ef748;
  *(undefined1 *)(param_1 + DAT_300ef748) = 1;
  rngFlush(*(undefined4 *)(param_1 + 0xfc));
  if ((code *)*DAT_300ef74c != (code *)0x0) {
    (*(code *)*DAT_300ef74c)(param_1 + 0x180,1);
  }
  semGive(param_1 + 0x100);
  *(undefined1 *)(param_1 + iVar1) = 0;
  semGive(param_1 + 0x8c);
  return;
}

/* ----------------------------------------------------------------
 * tyDevInit @ 0x300EF3E8  (примерный размер ~296 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 8
 * Вызывает: FUN_300ef2f4, FUN_300ef370, __div32, bzero, rngCreate, semBInit, semMInit, spinLockIsrInit
 * Вызывают: ptyDevCreate, ttyDevCreate
 * Константы: 0xFFFFFFFF, 0x300EF3E8
 * Данные: DAT_300ef73c, DAT_300ef750, DAT_300ef754
 * ---------------------------------------------------------------- */
undefined4 tyDevInit(void *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  bzero(param_1,0x270);
  iVar1 = rngCreate(param_3);
  *(int *)((int)param_1 + 0xfc) = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = 0xff;
    if (0xfe < param_2) {
      iVar1 = param_2;
    }
    iVar3 = rngCreate(iVar1 + 1);
    *(int *)((int)param_1 + 0x20) = iVar3;
    if (iVar3 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      *(undefined4 *)((int)param_1 + 0x174) = param_4;
      iVar3 = DAT_300ef73c;
      uVar2 = __div32((100 - *(int *)(DAT_300ef73c + 0xc)) * iVar1 + 99,100);
      *(undefined4 *)((int)param_1 + 0x214) = uVar2;
      uVar2 = __div32((100 - *(int *)(iVar3 + 0x10)) * iVar1 + 99,100);
      *(undefined4 *)((int)param_1 + 0x218) = uVar2;
      *(undefined4 *)((int)param_1 + 0x21c) = *(undefined4 *)(iVar3 + 0x18);
      *(undefined4 *)((int)param_1 + 0x220) = 0;
      semBInit((int)param_1 + 0x24,1);
      semBInit((int)param_1 + 0x100,1,0);
      semMInit((int)param_1 + 0x8c,*DAT_300ef750);
      spinLockIsrInit((int)param_1 + 0x22c,0);
      if ((code *)*DAT_300ef754 != (code *)0x0) {
        (*(code *)*DAT_300ef754)((int)param_1 + 0x180);
      }
      FUN_300ef2f4(param_1);
      FUN_300ef370(param_1);
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * tyDevRemove @ 0x300EF510  (примерный размер ~160 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: rngDelete, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300EF510
 * Данные: DAT_300ef758
 * ---------------------------------------------------------------- */
undefined4 tyDevRemove(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    uVar1 = 0xffffffff;
  }
  else if (*(int *)(param_1 + 0xfc) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    semTake(param_1 + 0x8c,0xffffffff);
    *(undefined1 *)(param_1 + 0xf8) = 1;
    *(undefined1 *)(param_1 + 0x16d) = 1;
    if (*(int *)(param_1 + 0x20) != 0) {
      rngDelete();
    }
    if (*(int *)(param_1 + 0xfc) != 0) {
      rngDelete();
    }
    semGive(param_1 + 0x8c);
    if ((code *)*DAT_300ef758 != (code *)0x0) {
      (*(code *)*DAT_300ef758)(param_1 + 0x180);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * tyDevTerminate @ 0x300EF5B0  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: rngDelete, semTake, semTerminate
 * Вызывают: ptyDevCreate, ptyDevRemove
 * Константы: 0x300EF5B0, 0xFFFFFFFF
 * Данные: DAT_300ef758
 * ---------------------------------------------------------------- */
undefined4 tyDevTerminate(int param_1)

{
  semTake(param_1 + 0x8c,0xffffffff);
  if (*(int *)(param_1 + 0x20) != 0) {
    rngDelete();
  }
  if (*(int *)(param_1 + 0xfc) != 0) {
    rngDelete();
  }
  semTerminate(param_1 + 0x24);
  semTerminate(param_1 + 0x100);
  semTerminate(param_1 + 0x8c);
  if ((code *)*DAT_300ef758 != (code *)0x0) {
    (*(code *)*DAT_300ef758)(param_1 + 0x180);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * tyAbortFuncSet @ 0x300EF62C  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: shellLibInit
 * Константы: 0x300EF62C
 * Данные: DAT_300ef75c
 * ---------------------------------------------------------------- */
void tyAbortFuncSet(undefined4 param_1)

{
  *DAT_300ef75c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * tyAbortFuncGet @ 0x300EF638  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: shellAbortHandledByShell
 * Константы: 0x300EF638
 * Данные: DAT_300ef75c
 * ---------------------------------------------------------------- */
undefined4 tyAbortFuncGet(void)

{
  return *DAT_300ef75c;
}

/* ----------------------------------------------------------------
 * tyAbortSet @ 0x300EF644  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EF644
 * Данные: DAT_300ef73c
 * ---------------------------------------------------------------- */
void tyAbortSet(undefined1 param_1)

{
  *DAT_300ef73c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * tyAbortGet @ 0x300EF650  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30103738, shellInOutBgndClose
 * Константы: 0x300EF650
 * Данные: DAT_300ef73c
 * ---------------------------------------------------------------- */
undefined1 tyAbortGet(void)

{
  return *DAT_300ef73c;
}

/* ----------------------------------------------------------------
 * tyBackspaceSet @ 0x300EF65C  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EF65C
 * Данные: DAT_300ef760
 * ---------------------------------------------------------------- */
void tyBackspaceSet(undefined1 param_1)

{
  *DAT_300ef760 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * tyDeleteLineSet @ 0x300EF668  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EF668
 * Данные: DAT_300ef764
 * ---------------------------------------------------------------- */
void tyDeleteLineSet(undefined1 param_1)

{
  *DAT_300ef764 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * tyEOFSet @ 0x300EF674  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EF674
 * Данные: DAT_300ef768
 * ---------------------------------------------------------------- */
void tyEOFSet(undefined1 param_1)

{
  *DAT_300ef768 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * tyEOFGet @ 0x300EF680  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EF680
 * Данные: DAT_300ef768
 * ---------------------------------------------------------------- */
undefined1 tyEOFGet(void)

{
  return *DAT_300ef768;
}

/* ----------------------------------------------------------------
 * tyMonitorTrapSet @ 0x300EF68C  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EF68C
 * Данные: DAT_300ef76c
 * ---------------------------------------------------------------- */
void tyMonitorTrapSet(undefined1 param_1)

{
  *DAT_300ef76c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ef698 @ 0x300EF698  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: spinLockIsrGive, spinLockIsrTake
 * Вызывают: tyIRd
 * Константы: 0x300EF698
 * Данные: DAT_300ef740
 * ---------------------------------------------------------------- */
void FUN_300ef698(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = param_1 + 0x22c;
  spinLockIsrTake(iVar1);
  if (((*(byte *)(param_1 + 0x16b) == param_2) ||
      (*(char *)(param_1 + 0x16b) = (char)param_2, param_2 != 0)) ||
     (*(char *)(param_1 + 0x16a) != '\0')) {
    spinLockIsrGive(iVar1);
  }
  else {
    *(undefined1 *)(param_1 + DAT_300ef740) = 1;
    spinLockIsrGive(iVar1);
    (**(code **)(param_1 + 0x174))(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * tyIoctl @ 0x300EF714  (примерный размер ~1240 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: FUN_300ed794, FUN_300ed9b8, FUN_300edad4, FUN_300ef114
 * Константы: 0x300EF714, 0x300EF738, 0xFFFFFFFF
 * Данные: DAT_300ef770
 * ---------------------------------------------------------------- */
undefined4 tyIoctl(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x41) {
                    /* WARNING: Could not recover jumptable at 0x300ef738. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_300ef770 + param_2 * 4))();
    return uVar1;
  }
  errnoSet(0x23);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300efbec @ 0x300EFBEC  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: spinLockIsrGive, spinLockIsrTake
 * Вызывают: tyIRd, tyWrite
 * Константы: 0x300EFBEC
 * Данные: DAT_300f079c
 * ---------------------------------------------------------------- */
void FUN_300efbec(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_300f079c;
  if (*(char *)(param_1 + 0x16a) == '\0') {
    iVar2 = param_1 + 0x22c;
    spinLockIsrTake(iVar2);
    if (*(char *)(param_1 + 0x16a) == '\0') {
      *(undefined1 *)(param_1 + iVar1) = 1;
      spinLockIsrGive(iVar2);
      (**(code **)(param_1 + 0x174))(param_1);
    }
    else {
      spinLockIsrGive(iVar2);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * tyWrite @ 0x300EFC58  (примерный размер ~292 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_300efbec, errnoSet, rngBufPut, rngFreeBytes, semGive, semTake, taskSafe, taskUnsafe
 * Константы: 0xFFFFFFFF, 0x300EFC58
 * Данные: DAT_300f07a0, DAT_300f07a4
 * ---------------------------------------------------------------- */
int tyWrite(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  taskSafe();
  iVar3 = param_1 + 0x100;
  iVar4 = param_3;
  while( true ) {
    if (iVar4 < 1) {
      taskUnsafe();
      return param_3;
    }
    iVar1 = semTake(iVar3,0xffffffff);
    if (iVar1 != 0) {
      errnoSet(6);
      taskUnsafe();
      return -1;
    }
    iVar2 = semTake(param_1 + 0x8c,0xffffffff);
    iVar1 = DAT_300f07a4;
    if (iVar2 != 0) {
      errnoSet(6);
      semGive(iVar3);
      taskUnsafe();
      return -1;
    }
    if (*(short *)(param_1 + 0x168) != 0) break;
    *(undefined1 *)(param_1 + DAT_300f07a4) = 1;
    iVar2 = rngBufPut(*(undefined4 *)(param_1 + 0xfc),param_2,iVar4);
    *(undefined1 *)(param_1 + iVar1) = 0;
    FUN_300efbec(param_1);
    iVar4 = iVar4 - iVar2;
    param_2 = param_2 + iVar2;
    iVar1 = rngFreeBytes(*(undefined4 *)(param_1 + 0xfc));
    if (0 < iVar1) {
      semGive(iVar3);
    }
    semGive(param_1 + 0x8c);
  }
  *(short *)(param_1 + 0x168) = *(short *)(param_1 + 0x168) + (short)DAT_300f07a0;
  semGive(param_1 + 0x8c);
  errnoSet(0x48);
  taskUnsafe();
  return param_3 - iVar4;
}

/* ----------------------------------------------------------------
 * tyRead @ 0x300EFD7C  (примерный размер ~440 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_300ef24c, errnoSet, rngBufGet, rngFreeBytes, rngIsEmpty, semGive, semTake
 * Вызывают: FUN_300ed7fc
 * Константы: 0xFFFFFFFF, 0x300EFD7C
 * Данные: DAT_300f0784, DAT_300f07a0, DAT_300f07a8
 * ---------------------------------------------------------------- */
uint tyRead(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  while( true ) {
    iVar1 = semTake(param_1 + 0x24,0xffffffff);
    if (iVar1 != 0) {
      errnoSet(6);
      return 0xffffffff;
    }
    iVar1 = semTake(param_1 + 0x8c,0xffffffff);
    if (iVar1 != 0) {
      errnoSet(6);
      semGive(param_1 + 0x24);
      return 0xffffffff;
    }
    if (*(short *)(param_1 + 0xf4) != 0) {
      *(short *)(param_1 + 0xf4) = *(short *)(param_1 + 0xf4) + (short)DAT_300f07a0;
      semGive(param_1 + 0x8c);
      errnoSet(0x48);
      return 0;
    }
    piVar4 = *(int **)(param_1 + 0x20);
    iVar2 = rngIsEmpty(piVar4);
    iVar3 = DAT_300f07a8;
    iVar1 = DAT_300f0784;
    if (iVar2 == 0) break;
    semGive(param_1 + 0x8c);
  }
  if ((*(ushort *)(param_1 + DAT_300f0784) & 0x40) == 0) {
    param_3 = rngBufGet(piVar4,param_2,param_3);
  }
  else {
    if ((*(char *)(param_1 + 0x171) == '\0') && (iVar2 = piVar4[1], *piVar4 != iVar2)) {
      *(undefined1 *)(param_1 + 0x171) = *(undefined1 *)(piVar4[3] + iVar2);
      iVar2 = iVar2 + 1;
      if (piVar4[2] == iVar2) {
        iVar2 = 0;
      }
      piVar4[1] = iVar2;
    }
    if ((int)(uint)*(byte *)(param_1 + iVar3) < (int)param_3) {
      param_3 = (uint)*(byte *)(param_1 + iVar3);
    }
    rngBufGet(piVar4,param_2,param_3);
    *(char *)(param_1 + iVar3) = *(char *)(param_1 + iVar3) - (char)param_3;
  }
  if (((*(ushort *)(param_1 + iVar1) & 4) != 0) && (*(char *)(param_1 + 0xf6) != '\0')) {
    iVar3 = rngFreeBytes(piVar4);
    if ((*(ushort *)(param_1 + iVar1) & 0x40) != 0) {
      iVar3 = iVar3 - (*(byte *)(param_1 + 0x170) + 1);
    }
    if (*(int *)(param_1 + 0x218) < iVar3) {
      FUN_300ef24c(param_1,0);
    }
  }
  iVar1 = rngIsEmpty(piVar4);
  if (iVar1 == 0) {
    semGive(param_1 + 0x24);
  }
  semGive(param_1 + 0x8c);
  return param_3;
}

/* ----------------------------------------------------------------
 * tyITx @ 0x300EFF34  (примерный размер ~472 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: intContext, rngFreeBytes, semGive, semTake
 * Вызывают: FUN_300ed890
 * Константы: 0xFFFFFFFF, 0x300EFF34
 * Данные: DAT_300f0784, DAT_300f0788, DAT_300f07ac
 * ---------------------------------------------------------------- */
undefined4 tyITx(int param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0xfc);
  iVar1 = intContext();
  if (iVar1 == 0) {
    semTake(param_1 + 0x8c,0xffffffff);
  }
  if (*(char *)(param_1 + 0xf7) != '\0') {
    *(undefined1 *)(param_1 + 0xf7) = 0;
    *param_2 = (*(char *)(param_1 + 0xf6) != '\0') * '\x02' + '\x11';
    iVar1 = DAT_300f0788;
    if (*(char *)(param_1 + 0xf6) != '\0') {
      if (*(int *)(DAT_300f0788 + 0x14) < *(int *)(DAT_300f0788 + 4)) {
        *(int *)(DAT_300f0788 + 0x14) = *(int *)(DAT_300f0788 + 4);
      }
      *(undefined4 *)(iVar1 + 4) = 0;
    }
    goto LAB_300f00dc;
  }
  if ((*(char *)(param_1 + 0x16b) == '\0') && (*(char *)(param_1 + 0x16d) == '\0')) {
    if (*(char *)(param_1 + 0x16c) == '\0') {
      iVar1 = piVar3[1];
      if (*piVar3 == iVar1) goto LAB_300f0074;
      *param_2 = *(char *)(piVar3[3] + iVar1);
      iVar1 = iVar1 + 1;
      if (piVar3[2] == iVar1) {
        iVar1 = 0;
      }
      piVar3[1] = iVar1;
      *(undefined1 *)(param_1 + 0x16a) = 1;
      if (((*(ushort *)(param_1 + DAT_300f0784) & 2) != 0) && (*param_2 == '\n')) {
        *param_2 = '\r';
        *(undefined1 *)(param_1 + 0x16c) = 1;
      }
    }
    else {
      *param_2 = '\n';
      *(undefined1 *)(param_1 + 0x16c) = 0;
      *(undefined1 *)(param_1 + 0x16a) = 1;
    }
    iVar1 = rngFreeBytes(piVar3);
    if (*(int *)(param_1 + 0x21c) <= iVar1) {
      iVar1 = intContext();
      if (iVar1 == 0) {
        semGive(param_1 + 0x8c);
      }
      if ((code *)*DAT_300f07ac != (code *)0x0) {
        (*(code *)*DAT_300f07ac)(param_1 + 0x180,1);
      }
      semGive(param_1 + 0x100);
      return 0;
    }
  }
  else {
LAB_300f0074:
    *(undefined1 *)(param_1 + 0x16a) = 0;
  }
LAB_300f00dc:
  if (*(char *)(param_1 + 0x16a) == '\0') {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  iVar1 = intContext();
  if (iVar1 == 0) {
    semGive(param_1 + 0x8c);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * tyIRd @ 0x300F010C  (примерный размер ~1552 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 12
 * Вызывает: FUN_300ef24c, FUN_300ef698, FUN_300efbec, intContext, reboot, rngBufPut, rngFreeBytes, rngMoveAhead, rngNBytes, rngPutAhead, semGive, semTake
 * Вызывают: FUN_300ed944
 * Константы: 0x300F010C, 0xFFFFFFFF
 * Данные: DAT_300f0784, DAT_300f0788, DAT_300f07ac, DAT_300f07b0, DAT_300f07b4, DAT_300f07b8, DAT_300f07bc, DAT_300f07c0
 * ---------------------------------------------------------------- */
int tyIRd(int param_1,uint param_2)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  char cVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  bool bVar11;
  bool bVar12;
  
  iVar7 = DAT_300f0784;
  iVar8 = 0;
  uVar3 = *(ushort *)(param_1 + DAT_300f0784);
  bVar12 = false;
  if ((*(code **)(param_1 + 0x178) != (code *)0x0) &&
     (iVar6 = (**(code **)(param_1 + 0x178))(*(undefined4 *)(param_1 + 0x17c)), iVar6 == 1)) {
    return 0;
  }
  iVar6 = intContext();
  if (iVar6 == 0) {
    semTake(param_1 + 0x8c,0xffffffff);
  }
  pbVar5 = DAT_300f0788;
  if (*(char *)(param_1 + 0xf8) != '\0') {
    iVar7 = intContext();
    if (iVar7 == 0) {
      semGive(param_1 + 0x8c);
    }
    return -1;
  }
  if ((uVar3 & 8) != 0) {
    param_2 = param_2 & 0x7f;
  }
  if (((*DAT_300f0788 == param_2) && ((uVar3 & 0x20) != 0)) && (*(int *)(DAT_300f0788 + 8) != 0)) {
    iVar7 = intContext();
    if (iVar7 == 0) {
      semGive(param_1 + 0x8c);
    }
    (**(code **)(pbVar5 + 8))();
    goto LAB_300f0704;
  }
  if ((DAT_300f0788[1] == param_2) && ((uVar3 & 0x10) != 0)) {
    iVar7 = intContext();
    if (iVar7 == 0) {
      semGive(param_1 + 0x8c);
    }
    if ((code *)*DAT_300f07b0 == (code *)0x0) {
      reboot(0);
    }
    else {
      (*(code *)*DAT_300f07b0)(DAT_300f07b4,0,0,0,0,0,0,0);
    }
    goto LAB_300f0704;
  }
  if (((param_2 == 0x13) || (param_2 == 0x11)) && ((uVar3 & 4) != 0)) {
    iVar7 = intContext();
    if (iVar7 == 0) {
      semGive(param_1 + 0x8c);
    }
    FUN_300ef698(param_1,param_2 == 0x13);
    goto LAB_300f0704;
  }
  if (*(char *)(param_1 + 0xf6) != '\0') {
    *(int *)(DAT_300f0788 + 4) = *(int *)(DAT_300f0788 + 4) + 1;
  }
  if (((uVar3 & 2) != 0) && (param_2 == 0xd)) {
    param_2 = 10;
  }
  piVar10 = *(int **)(param_1 + 0x20);
  bVar11 = false;
  cVar4 = (char)param_2;
  if ((uVar3 & 0x40) == 0) {
    iVar6 = *piVar10;
    if (piVar10[1] + -1 == iVar6) {
LAB_300f0310:
      iVar8 = -1;
    }
    else {
      if (piVar10[2] + -1 == iVar6) {
        if (piVar10[1] == 0) goto LAB_300f0310;
        *(char *)(piVar10[3] + iVar6) = cVar4;
        iVar6 = 0;
      }
      else {
        *(char *)(piVar10[3] + iVar6) = cVar4;
        iVar6 = *piVar10 + 1;
      }
      *piVar10 = iVar6;
    }
    iVar6 = rngNBytes(piVar10);
    bVar11 = iVar6 == 1;
  }
  else {
    iVar6 = rngFreeBytes(piVar10);
    if (*DAT_300f07b8 == param_2) {
      bVar12 = *(char *)(param_1 + 0x170) == '\0';
      if (bVar12) {
        iVar8 = -1;
      }
      else {
        *(char *)(param_1 + 0x170) = *(char *)(param_1 + 0x170) + -1;
      }
    }
    else if (*DAT_300f07bc == param_2) {
      *(undefined1 *)(param_1 + 0x170) = 0;
    }
    else if (*DAT_300f07c0 == param_2) {
      if (iVar6 < 1) {
LAB_300f044c:
        iVar8 = -1;
      }
      else {
LAB_300f0418:
        bVar11 = true;
        rngPutAhead(piVar10,*(undefined1 *)(param_1 + 0x170),0);
        rngMoveAhead(piVar10,*(byte *)(param_1 + 0x170) + 1);
        *(undefined1 *)(param_1 + 0x170) = 0;
      }
    }
    else {
      if (iVar6 < 2) goto LAB_300f044c;
      bVar1 = *(byte *)(param_1 + 0x170);
      if ((iVar6 < (int)(bVar1 + 3)) || (0xfd < bVar1)) {
        iVar8 = -1;
      }
      else {
        *(byte *)(param_1 + 0x170) = bVar1 + 1;
      }
      if (iVar8 == -1) {
        if (param_2 != 10) goto LAB_300f0450;
        cVar2 = *(char *)(param_1 + 0x170);
        *(char *)(param_1 + 0x170) = cVar2 + '\x01';
        if (cVar2 == '\0') goto LAB_300f0418;
      }
      rngPutAhead(piVar10,param_2,*(undefined1 *)(param_1 + 0x170));
      if (param_2 == 10) goto LAB_300f0418;
    }
  }
LAB_300f0450:
  if (((((uVar3 & 1) == 0) || (iVar8 == -1)) || (*(char *)(param_1 + 0x16e) != '\0')) ||
     (*(char *)(param_1 + 0x16d) != '\0')) {
    iVar6 = intContext();
    if (iVar6 == 0) {
      semGive(param_1 + 0x8c);
    }
  }
  else {
    piVar10 = *(int **)(param_1 + 0xfc);
    if ((uVar3 & 0x40) == 0) {
      iVar6 = *piVar10;
      if (piVar10[1] + -1 != iVar6) {
        if (piVar10[2] + -1 == iVar6) {
LAB_300f0600:
          if (piVar10[1] == 0) goto LAB_300f0634;
          *(char *)(piVar10[3] + iVar6) = cVar4;
          iVar6 = 0;
        }
        else {
LAB_300f0620:
          *(char *)(piVar10[3] + iVar6) = (char)param_2;
          iVar6 = *piVar10 + 1;
        }
LAB_300f0630:
        *piVar10 = iVar6;
      }
    }
    else if (*DAT_300f07bc == param_2) {
      iVar6 = *piVar10;
      if (piVar10[1] + -1 != iVar6) {
        if (piVar10[2] + -1 != iVar6) {
          param_2 = 10;
          goto LAB_300f0620;
        }
        if (piVar10[1] != 0) {
          *(undefined1 *)(piVar10[3] + iVar6) = 10;
          iVar6 = 0;
          goto LAB_300f0630;
        }
      }
    }
    else if (*DAT_300f07b8 == param_2) {
      rngBufPut(piVar10,DAT_300f07c4,3);
    }
    else if (((int)param_2 < 0x20) && (param_2 != 10)) {
      iVar6 = *piVar10;
      if (piVar10[1] + -1 != iVar6) {
        if (piVar10[2] + -1 == iVar6) {
          if (piVar10[1] == 0) goto LAB_300f0570;
          *(undefined1 *)(piVar10[3] + iVar6) = 0x5e;
          iVar6 = 0;
        }
        else {
          *(undefined1 *)(piVar10[3] + iVar6) = 0x5e;
          iVar6 = *piVar10 + 1;
        }
        *piVar10 = iVar6;
      }
LAB_300f0570:
      iVar6 = *piVar10;
      if (piVar10[1] + -1 != iVar6) {
        if (piVar10[2] + -1 != iVar6) {
          param_2 = param_2 + 0x40;
          goto LAB_300f0620;
        }
        if (piVar10[1] != 0) {
          *(char *)(piVar10[3] + iVar6) = cVar4 + '@';
          iVar6 = 0;
          goto LAB_300f0630;
        }
      }
    }
    else {
      iVar6 = *piVar10;
      if (piVar10[1] + -1 != iVar6) {
        if (piVar10[2] + -1 == iVar6) goto LAB_300f0600;
        goto LAB_300f0620;
      }
    }
LAB_300f0634:
    iVar6 = intContext();
    if (iVar6 == 0) {
      semGive(param_1 + 0x8c);
    }
    FUN_300efbec(param_1);
  }
  if ((uVar3 & 0x44) == 4) {
    iVar6 = rngFreeBytes(*(undefined4 *)(param_1 + 0x20));
    if ((*(ushort *)(param_1 + iVar7) & 0x40) != 0) {
      iVar6 = iVar6 - (*(byte *)(param_1 + 0x170) + 1);
    }
    if (*(char *)(param_1 + 0xf6) == '\0') {
      if (iVar6 < *(int *)(param_1 + 0x214)) {
        uVar9 = 1;
LAB_300f06c4:
        FUN_300ef24c(param_1,uVar9);
      }
    }
    else if (*(int *)(param_1 + 0x218) < iVar6) {
      uVar9 = 0;
      goto LAB_300f06c4;
    }
  }
  if (bVar11) {
    if ((code *)*DAT_300f07ac != (code *)0x0) {
      (*(code *)*DAT_300f07ac)(param_1 + 0x180,0);
    }
    semGive(param_1 + 0x24);
  }
LAB_300f0704:
  if (bVar12) {
    iVar8 = 0;
  }
  return iVar8;
}

/* ----------------------------------------------------------------
 * tyXoffHookSet @ 0x300F071C  (примерный размер ~172 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300ef24c, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300F071C
 * ---------------------------------------------------------------- */
undefined4 tyXoffHookSet(int param_1,code *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    semTake(param_1 + 0x8c,0xffffffff);
    FUN_300ef24c(param_1,0);
    semGive(param_1 + 0x8c);
    (*param_2)(param_3,0);
    *(code **)(param_1 + 0x220) = param_2;
    *(undefined4 *)(param_1 + 0x224) = param_3;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheLibInit @ 0x300F07C8  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrInit
 * Константы: 0x300F07C8, 0xFFFFFFFF
 * Данные: DAT_300f0da0, DAT_300f0da4, DAT_300f0da8
 * ---------------------------------------------------------------- */
undefined4 cacheLibInit(void)

{
  undefined4 uVar1;
  
  *DAT_300f0da4 = DAT_300f0da0;
  if ((code *)*DAT_300f0da8 == (code *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (*(code *)*DAT_300f0da8)();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheEnable @ 0x300F0808  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrCacheEnable
 * Константы: 0x300F0808, 0xFFFFFFFF
 * Данные: DAT_300f0dac
 * ---------------------------------------------------------------- */
undefined4 cacheEnable(void)

{
  undefined4 uVar1;
  
  if ((code *)*DAT_300f0dac == (code *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (*(code *)*DAT_300f0dac)();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheDisable @ 0x300F083C  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F083C, 0xFFFFFFFF
 * Данные: DAT_300f0dac
 * ---------------------------------------------------------------- */
undefined4 cacheDisable(void)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_300f0dac + 4) == (code *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (**(code **)(DAT_300f0dac + 4))();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheLock @ 0x300F0870  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F0870, 0xFFFFFFFF
 * Данные: DAT_300f0dac
 * ---------------------------------------------------------------- */
undefined4 cacheLock(void)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_300f0dac + 8) == (code *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (**(code **)(DAT_300f0dac + 8))();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheUnlock @ 0x300F08A4  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F08A4, 0xFFFFFFFF
 * Данные: DAT_300f0dac
 * ---------------------------------------------------------------- */
undefined4 cacheUnlock(void)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_300f0dac + 0xc) == (code *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (**(code **)(DAT_300f0dac + 0xc))();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheFlush @ 0x300F08D8  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 14 | Вызывает: 0
 * Вызывают: BSP_OM_SoftReboot, BSP_WDT_reboot_direct, FUN_300067b0, FUN_30006964, FUN_30060b5c, FUN_30060dd0, FUN_300ac018, FUN_300ac984, IDMAC_NoCopySend, cacheForeignFlush
 *           ...
 * Константы: 0x300F08D8
 * Данные: DAT_300f0dac
 * ---------------------------------------------------------------- */
undefined4 cacheFlush(void)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_300f0dac + 0x10) == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_300f0dac + 0x10))();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheInvalidate @ 0x300F0908  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 14 | Вызывает: 0
 * Вызывают: BSP_MEM_DumpBlock, BSP_SFree, FUN_30006ba8, FUN_3005fcf8, FUN_300ac018, FUN_300ac984, FUN_300ad138, FUN_300ae500, FUN_300ae598, FUN_300ae9dc
 *           ...
 * Константы: 0x300F0908
 * Данные: DAT_300f0dac
 * ---------------------------------------------------------------- */
undefined4 cacheInvalidate(void)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_300f0dac + 0x14) == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_300f0dac + 0x14))();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheClear @ 0x300F0938  (примерный размер ~132 байт)
 * Модуль: kernel | Вызывают: 8 | Вызывает: 1
 * Вызывает: cacheInvalidate
 * Вызывают: FUN_300ac018, FUN_300ac984, FUN_300ad138, FUN_300ae500, FUN_300ae598, FUN_300ae9dc, cacheForeignClear, cacheForeignInvalidate
 * Константы: 0x300F0938
 * Данные: DAT_300f0dac
 * ---------------------------------------------------------------- */
int cacheClear(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(code **)(DAT_300f0dac + 0x18) == (code *)0x0) {
    if ((*(code **)(DAT_300f0dac + 0x10) == (code *)0x0) ||
       (iVar1 = (**(code **)(DAT_300f0dac + 0x10))(param_1,param_2,param_3), iVar1 == 0)) {
      iVar1 = cacheInvalidate(param_1,param_2,param_3);
    }
  }
  else {
    iVar1 = (**(code **)(DAT_300f0dac + 0x18))(param_1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * cachePipeFlush @ 0x300F09BC  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: sysToMonitor
 * Константы: 0x300F09BC
 * Данные: DAT_300f0dac
 * ---------------------------------------------------------------- */
void cachePipeFlush(void)

{
  if (*(code **)(DAT_300f0dac + 0x20) != (code *)0x0) {
    (**(code **)(DAT_300f0dac + 0x20))();
  }
  return;
}

/* ----------------------------------------------------------------
 * cacheTextLocalUpdate @ 0x300F09E4  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: cacheTextUpdate
 * Константы: 0x300F09E4, 0xFFFFFFFF
 * Данные: DAT_300f0dac
 * ---------------------------------------------------------------- */
undefined4 cacheTextLocalUpdate(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == -1) {
    uVar1 = 0xffffffff;
  }
  else if (*(code **)(DAT_300f0dac + 0x1c) == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_300f0dac + 0x1c))();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheTextUpdate @ 0x300F0A24  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cacheTextLocalUpdate
 * Константы: 0x300F0A24, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 cacheTextUpdate(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == -1) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = cacheTextLocalUpdate();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheDmaMalloc @ 0x300F0A40  (примерный размер ~88 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 2
 * Вызывает: malloc, memPartAlignedAlloc
 * Вызывают: FUN_300cb558, IDMAC_alloc_consistent_dmaable_memory, bio_alloc, os_dma_alloc, sdmmcISRInit
 * Константы: 0x300F0A40, 0xFFFFFFE0
 * Данные: DAT_300f0db0, DAT_300f0db4, DAT_300f0db8
 * ---------------------------------------------------------------- */
void cacheDmaMalloc(size_t param_1)

{
  if ((code *)*DAT_300f0db0 == (code *)0x0) {
    if (*DAT_300f0db4 == 0) {
      malloc(param_1);
    }
    else {
      memPartAlignedAlloc(*DAT_300f0db8,param_1 + 0x1f & 0xffffffe0,0x20);
    }
  }
  else {
    (*(code *)*DAT_300f0db0)();
  }
  return;
}

/* ----------------------------------------------------------------
 * cacheDmaFree @ 0x300F0A98  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 2
 * Вызывает: free, memPartFree
 * Вызывают: FUN_300cb558, FUN_300cbe88, IDMAC_free_consistent_dmaable_memory, dosFsCacheTune, os_dma_free
 * Константы: 0x300F0A98
 * Данные: DAT_300f0db4, DAT_300f0db8, DAT_300f0dbc
 * ---------------------------------------------------------------- */
undefined4 cacheDmaFree(void *param_1)

{
  undefined4 uVar1;
  
  if ((code *)*DAT_300f0dbc == (code *)0x0) {
    if (*DAT_300f0db4 == 0) {
      free(param_1);
      uVar1 = 0;
    }
    else {
      uVar1 = memPartFree(*DAT_300f0db8,param_1);
    }
  }
  else {
    uVar1 = (*(code *)*DAT_300f0dbc)();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheFuncsSet @ 0x300F0AEC  (примерный размер ~280 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300ad138, cacheAimArch7DDisable, cacheAimArch7DEnable
 * Константы: 0x300F0AEC
 * Данные: DAT_300f0dac, DAT_300f0db0, DAT_300f0db4, DAT_300f0dbc, DAT_300f0dc0, DAT_300f0dc4, DAT_300f0dc8, DAT_300f0dcc
 * ---------------------------------------------------------------- */
void cacheFuncsSet(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar4 = DAT_300f0dc8;
  puVar2 = DAT_300f0dc4;
  iVar1 = DAT_300f0dac;
  if ((*DAT_300f0db4 == 0) || (uVar3 = *DAT_300f0dc0, (uVar3 & 0x10) != 0)) {
    *DAT_300f0dc8 = *DAT_300f0dc4;
    puVar4[1] = puVar2[1];
    puVar4[2] = puVar2[2];
    puVar4[3] = puVar2[3];
    puVar4 = puVar2;
  }
  else {
    DAT_300f0dc8[1] = *(undefined4 *)(DAT_300f0dac + 0x14);
    if ((uVar3 & 1) == 0) {
      uVar5 = *(undefined4 *)(iVar1 + 0x10);
    }
    else {
      uVar5 = 0;
    }
    *puVar4 = uVar5;
    puVar2 = DAT_300f0dd0;
    if (*DAT_300f0dcc != 0) {
      *DAT_300f0dd0 = 0;
      puVar2[1] = 0;
      *DAT_300f0db0 = *(undefined4 *)(iVar1 + 0x24);
      uVar5 = *(undefined4 *)(iVar1 + 0x28);
      goto LAB_300f0bbc;
    }
  }
  puVar2 = DAT_300f0dd0;
  *DAT_300f0dd0 = *puVar4;
  puVar2[1] = puVar4[1];
  puVar2[2] = puVar4[2];
  puVar2[3] = puVar4[3];
  uVar5 = 0;
  *DAT_300f0db0 = 0;
LAB_300f0bbc:
  *DAT_300f0dbc = uVar5;
  puVar2 = DAT_300f0dd0;
  iVar1 = DAT_300f0dac;
  if (*DAT_300f0dcc == 0) {
    DAT_300f0dd0[3] = 0;
    puVar2[2] = 0;
    return;
  }
  DAT_300f0dd0[2] = *(undefined4 *)(DAT_300f0dac + 0x2c);
  puVar2[3] = *(undefined4 *)(iVar1 + 0x30);
  return;
}

/* ----------------------------------------------------------------
 * cacheDrvFlush @ 0x300F0C04  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F0C04
 * ---------------------------------------------------------------- */
undefined4 cacheDrvFlush(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if ((code *)*param_1 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)*param_1)(1);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheDrvInvalidate @ 0x300F0C34  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F0C34
 * ---------------------------------------------------------------- */
undefined4 cacheDrvInvalidate(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 4) == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_1 + 4))(1);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * cacheDrvVirtToPhys @ 0x300F0C64  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F0C64
 * ---------------------------------------------------------------- */
undefined4 cacheDrvVirtToPhys(int param_1,undefined4 param_2)

{
  if (*(code **)(param_1 + 8) != (code *)0x0) {
    param_2 = (**(code **)(param_1 + 8))(param_2);
  }
  return param_2;
}

/* ----------------------------------------------------------------
 * cacheDrvPhysToVirt @ 0x300F0C90  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F0C90
 * ---------------------------------------------------------------- */
undefined4 cacheDrvPhysToVirt(int param_1,undefined4 param_2)

{
  if (*(code **)(param_1 + 0xc) != (code *)0x0) {
    param_2 = (**(code **)(param_1 + 0xc))(param_2);
  }
  return param_2;
}

/* ----------------------------------------------------------------
 * cacheForeignFlush @ 0x300F0CBC  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cacheFlush
 * Константы: 0x300F0CBC, 0xFFFFFFFF
 * Данные: DAT_300f0dac
 * ---------------------------------------------------------------- */
void cacheForeignFlush(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5)

{
  if (*(code **)(DAT_300f0dac + 0x34) == (code *)0x0) {
    cacheFlush(param_1,0,0xffffffff);
  }
  else {
    (**(code **)(DAT_300f0dac + 0x34))(param_1,param_2,param_3,param_4,param_5);
  }
  return;
}

/* ----------------------------------------------------------------
 * cacheForeignClear @ 0x300F0D08  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cacheClear
 * Константы: 0x300F0D08, 0xFFFFFFFF
 * Данные: DAT_300f0dac
 * ---------------------------------------------------------------- */
void cacheForeignClear(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5)

{
  if (*(code **)(DAT_300f0dac + 0x3c) == (code *)0x0) {
    cacheClear(param_1,0,0xffffffff);
  }
  else {
    (**(code **)(DAT_300f0dac + 0x3c))(param_1,param_2,param_3,param_4,param_5);
  }
  return;
}

/* ----------------------------------------------------------------
 * cacheForeignInvalidate @ 0x300F0D54  (примерный размер ~128 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: cacheClear
 * Константы: 0x300F0D54, 0xFFFFFFFF
 * Данные: DAT_300f0dac
 * ---------------------------------------------------------------- */
void cacheForeignInvalidate
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  if (*(code **)(DAT_300f0dac + 0x38) == (code *)0x0) {
    cacheClear(param_1,0,0xffffffff);
  }
  else {
    (**(code **)(DAT_300f0dac + 0x38))(param_1,param_2,param_3,param_4,param_5);
  }
  return;
}

/* ----------------------------------------------------------------
 * memInfoInit @ 0x300F0DD4  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrRoot
 * Константы: 0x300F0DD4
 * ---------------------------------------------------------------- */
undefined4 memInfoInit(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * memPartInfoGet @ 0x300F0DDC  (примерный размер ~184 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: avlUintMaximumGet, memPartVerifiedLock, semMGive
 * Вызывают: max_freeblock_size_get, memInfoGet
 * Константы: 0xFFFFFFFF, 0x300F0DDC
 * Данные: DAT_300f0ffc
 * ---------------------------------------------------------------- */
undefined4 memPartInfoGet(uint param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    return 0xffffffff;
  }
  if ((param_1 & 1) != 0) {
    return 0xffffffff;
  }
  iVar1 = memPartVerifiedLock(param_1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = avlUintMaximumGet(*(undefined4 *)(param_1 + 0x40));
  *param_2 = *(int *)(param_1 + 0xe0) << 1;
  param_2[1] = *(int *)(param_1 + 0xdc);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0xc) - (*DAT_300f0ffc + 0x10);
  }
  param_2[2] = iVar1;
  param_2[3] = *(int *)(param_1 + 0xe8) << 1;
  param_2[4] = *(int *)(param_1 + 0xe4);
  param_2[5] = *(int *)(param_1 + 0xfc) << 1;
  semMGive(param_1 + 0x50);
  return 0;
}

/* ----------------------------------------------------------------
 * memPartFindMax @ 0x300F0E94  (примерный размер ~156 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: __errno, avlUintMaximumGet, memPartVerifiedLock, semMGive
 * Вызывают: memFindMax
 * Константы: 0x300F0E94
 * Данные: DAT_300f0ffc, DAT_300f1000, DAT_300f1004, DAT_300f1008
 * ---------------------------------------------------------------- */
int memPartFindMax(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((param_1 & 1) == 0) {
    iVar2 = memPartVerifiedLock();
    if (iVar2 == 0) {
      iVar2 = avlUintMaximumGet(*(undefined4 *)(param_1 + 0x40));
      if (iVar2 != 0) {
        iVar3 = *(int *)(iVar2 + 0xc) - (*DAT_300f0ffc + 0x10);
      }
      semMGive(param_1 + 0x50);
    }
    else {
      iVar3 = -1;
    }
  }
  else if ((code *)*DAT_300f1000 == (code *)0x0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300f1004;
    iVar3 = -1;
  }
  else {
    iVar3 = (*(code *)*DAT_300f1000)(param_1 + *DAT_300f1008);
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * memInfoGet @ 0x300F0F30  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: memPartInfoGet
 * Вызывают: heapInfoGet
 * Константы: 0x300F0F30
 * Данные: DAT_300f100c
 * ---------------------------------------------------------------- */
void memInfoGet(undefined4 param_1)

{
  memPartInfoGet(*DAT_300f100c,param_1);
  return;
}

/* ----------------------------------------------------------------
 * memFindMax @ 0x300F0F40  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: memPartFindMax
 * Константы: 0x300F0F40
 * Данные: DAT_300f100c
 * ---------------------------------------------------------------- */
void memFindMax(void)

{
  memPartFindMax(*DAT_300f100c);
  return;
}

/* ----------------------------------------------------------------
 * memPartFreeListWalk @ 0x300F0F4C  (примерный размер ~204 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x300F0F4C
 * Данные: DAT_300f1010, DAT_300f1014
 * ---------------------------------------------------------------- */
undefined4 memPartFreeListWalk(int param_1,int param_2,code *param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_28;
  
  local_28 = 1;
  if (param_2 == 1) {
    uVar4 = 0xffffffff;
    pcVar1 = DAT_300f1010;
  }
  else {
    uVar4 = 0;
    pcVar1 = DAT_300f1014;
  }
  do {
    iVar3 = (*pcVar1)(*(undefined4 *)(param_1 + 0x40),uVar4);
    if (iVar3 == 0) {
      return 0;
    }
    iVar5 = *(int *)(iVar3 + 0x10);
    uVar4 = *(undefined4 *)(iVar3 + 0xc);
    iVar3 = *(int *)(iVar5 + 0xc);
    do {
      iVar2 = (*param_3)(iVar5,uVar4,param_4,&local_28);
      if (iVar2 == -1) {
        return 0xffffffff;
      }
      if (local_28 == 0) {
        return 0;
      }
      iVar5 = *(int *)(iVar5 + 8);
    } while (iVar5 != iVar3);
  } while( true );
}

/* ----------------------------------------------------------------
 * memInit @ 0x300F1018  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: memPartLibInit
 * Вызывают: usrRoot
 * Константы: 0x300F1018
 * Данные: DAT_300f19ec, DAT_300f19f0, DAT_300f19f4, DAT_300f19f8, DAT_300f19fc, DAT_300f1a00, DAT_300f1a04, DAT_300f1a08
 * ---------------------------------------------------------------- */
void memInit(undefined4 param_1,undefined4 param_2,uint param_3)

{
  *DAT_300f19f0 = DAT_300f19ec;
  *DAT_300f19f8 = DAT_300f19f4;
  *DAT_300f1a00 = DAT_300f19fc;
  *DAT_300f1a08 = DAT_300f1a04;
  *DAT_300f1a10 = DAT_300f1a0c;
  *DAT_300f1a18 = DAT_300f1a14;
  if ((param_3 & DAT_300f1a1c) != 0) {
    param_3 = 0xbb0;
  }
  *DAT_300f1a20 = param_3;
  memPartLibInit();
  return;
}

/* ----------------------------------------------------------------
 * memPartOptionsSet @ 0x300F1078  (примерный размер ~244 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: __errno, objVerify, taskCpuUnlock
 * Вызывают: memOptionsSet, shellMemLibInit
 * Константы: 0xFFFFFFFF, 0x300F1078
 * Данные: DAT_300f1a1c, DAT_300f1a24, DAT_300f1a28, DAT_300f1a2c, DAT_300f1a30, DAT_300f1a34
 * ---------------------------------------------------------------- */
undefined4 memPartOptionsSet(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 & 1) == 0) {
    if ((param_2 & DAT_300f1a1c) == 0) {
      if ((param_2 & 0xf) != 0) {
        if ((param_2 & 1) != 0) {
          param_2 = param_2 | 0x20;
        }
        if ((param_2 & 2) != 0) {
          param_2 = param_2 | 0x60;
        }
        if ((param_2 & 4) != 0) {
          param_2 = param_2 | 0x80;
        }
        if ((param_2 & 8) != 0) {
          param_2 = param_2 | 0x180;
        }
      }
      if ((param_2 & 0x1980) != 0) {
        param_2 = param_2 | 0x10;
      }
      *(int *)(*DAT_300f1a30 + 0x7c) = *(int *)(*DAT_300f1a30 + 0x7c) + 1;
      if ((param_1 == 0) || (iVar3 = objVerify(param_1,*DAT_300f1a34), iVar3 != 0)) {
        taskCpuUnlock();
        uVar2 = 0xffffffff;
      }
      else {
        *(uint *)(param_1 + 0xbc) = param_2;
        taskCpuUnlock();
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else if ((code *)*DAT_300f1a24 == (code *)0x0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300f1a28;
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (*(code *)*DAT_300f1a24)(param_1 + *DAT_300f1a2c,param_2);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * memPartOptionsGet @ 0x300F116C  (примерный размер ~152 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: __errno, objVerify, taskCpuUnlock
 * Вызывают: memOptionsGet, shellMemLibInit
 * Константы: 0xFFFFFFFF, 0x300F116C
 * Данные: DAT_300f1a30, DAT_300f1a34, DAT_300f1a38, DAT_300f1a3c
 * ---------------------------------------------------------------- */
undefined4 memPartOptionsGet(uint param_1,uint *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((param_1 & 1) != 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300f1a38;
    return 0xffffffff;
  }
  if (param_2 == (uint *)0x0) {
    return 0xffffffff;
  }
  *(int *)(*DAT_300f1a30 + 0x7c) = *(int *)(*DAT_300f1a30 + 0x7c) + 1;
  if ((param_1 != 0) && (iVar2 = objVerify(param_1,*DAT_300f1a34), iVar2 == 0)) {
    *param_2 = *(uint *)(param_1 + 0xbc) & DAT_300f1a3c;
    taskCpuUnlock();
    return 0;
  }
  taskCpuUnlock();
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * memalign @ 0x300F1204  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 18 | Вызывает: 1
 * Вызывает: memPartAlignedAlloc
 * Вызывают: FUN_30005b50, FUN_30060598, IDMAC_alloc_memory, coprocCtxReplicate, dloadUSBSend, memoryDump, sd_mmc_blk_read, sd_mmc_blk_read_fixed, sd_mmc_blk_read_increase, sd_mmc_blk_rw
 *           ...
 * Константы: 0x300F1204
 * Данные: DAT_300f1a40
 * ---------------------------------------------------------------- */
void memalign(undefined4 param_1,undefined4 param_2)

{
  memPartAlignedAlloc(*DAT_300f1a40,param_2,param_1);
  return;
}

/* ----------------------------------------------------------------
 * memPartReallocInternal @ 0x300F1274  (примерный размер ~1244 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 13
 * Вызывает: __errno, bcopy, memPartAlloc, memPartBlockIsValid, memPartDeleteFree, memPartEdrErrorInject, memPartFree, memPartInsertFree, semMGive, semMTake, sizeNodesAlloc, taskCpuUnlock, taskSuspend
 * Вызывают: memPartRealloc
 * Константы: 0xFFFFFFFE, 0xFFFFFFFC, 0x300F1274, 0xFFFFFFFF
 * Данные: DAT_300f1a10, DAT_300f1a30, DAT_300f1a4c, DAT_300f1a50, DAT_300f1a54, DAT_300f1a58, DAT_300f1a5c, DAT_300f1a60
 * ---------------------------------------------------------------- */
void * memPartReallocInternal(int param_1,void *param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint extraout_r1;
  uint extraout_r1_00;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  size_t local_3c;
  
  bVar2 = true;
  bVar1 = false;
  if (param_2 == (void *)0x0) {
    pvVar4 = (void *)memPartAlloc(param_1,param_3);
    return pvVar4;
  }
  if (param_3 == 0) {
    memPartFree();
    return (void *)0x0;
  }
  uVar14 = param_3 + *DAT_300f1a4c + 0x13;
  uVar13 = uVar14 & 0xfffffffc;
  if (uVar13 < param_3) {
    iVar5 = memPartFree();
    if (iVar5 == 0) {
      puVar6 = (undefined4 *)__errno();
      *puVar6 = DAT_300f1a50;
    }
    return (void *)0x0;
  }
  iVar5 = (int)param_2 + -0x10;
  *(int *)(*DAT_300f1a30 + 0x7c) = *(int *)(*DAT_300f1a30 + 0x7c) + 1;
  if (((*(uint *)(param_1 + 0xbc) & 0x10) != 0) &&
     (iVar7 = memPartBlockIsValid(param_1,iVar5,0), uVar3 = DAT_300f1a54, iVar7 == 0)) {
    taskCpuUnlock();
    puVar6 = (undefined4 *)__errno();
    *puVar6 = DAT_300f1a58;
    if ((code *)*DAT_300f1a10 != (code *)0x0) {
      (*(code *)*DAT_300f1a10)(param_1,param_2,uVar3,*DAT_300f1a5c);
    }
    if ((*(uint *)(param_1 + 0xbc) & 0x1800) != 0) {
      memPartEdrErrorInject(param_1,*DAT_300f1a5c,uVar3,param_2,0,0);
    }
    if (((*(uint *)(param_1 + 0xbc) & 0x100) != 0) && ((*(uint *)(*DAT_300f1a30 + 0x98) & 2) == 0))
    {
      taskSuspend(0);
    }
    return (void *)0x0;
  }
  iVar7 = semMTake(param_1 + 0x50,0xffffffff);
  if (iVar7 != 0) {
    taskCpuUnlock();
    return (void *)0x0;
  }
  taskCpuUnlock();
  if (*(int *)((int)param_2 + -8) != param_1) {
    semMGive(param_1 + 0x50);
    puVar6 = (undefined4 *)__errno();
    *puVar6 = DAT_300f1a60;
    return (void *)0x0;
  }
  iVar7 = sizeNodesAlloc(param_1,0,0);
  if (iVar7 == -1) {
    semMGive(param_1 + 0x50);
    return (void *)0x0;
  }
  uVar8 = *(uint *)((int)param_2 + -0xc) & 0xfffffffe;
  puVar11 = (uint *)(iVar5 + uVar8);
  puVar10 = (uint *)((int)puVar11 + (puVar11[1] & 0xfffffffe));
  pvVar4 = param_2;
  if (uVar8 < uVar13) {
    if (((puVar10[1] & 1) == 0) || (*puVar10 + *puVar11 < uVar13)) {
      semMGive(param_1 + 0x50);
      pvVar4 = (void *)memPartAlloc(param_1,param_3);
      if (pvVar4 == (void *)0x0) {
        return (void *)0x0;
      }
      uVar13 = (*(uint *)((int)param_2 + -0xc) & 0xfffffffe) - (*DAT_300f1a4c + 0x10);
      local_3c = param_3;
      if (uVar13 < param_3) {
        local_3c = uVar13;
      }
      bcopy(param_2,pvVar4,local_3c);
      memPartFree(param_1,param_2);
      bVar2 = false;
      uVar8 = extraout_r1;
      goto LAB_300f16d0;
    }
    memPartDeleteFree(param_1,puVar11);
    *(uint *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) + (puVar11[1] >> 1);
    uVar8 = *(int *)(param_1 + 0xf8) + (uint)CARRY4(*(uint *)(param_1 + 0xf4),puVar11[1] >> 1);
    *(uint *)(param_1 + 0xf4) = *(uint *)(param_1 + 0xf4) + (puVar11[1] >> 1);
    *(uint *)(param_1 + 0xf8) = uVar8;
    if (*DAT_300f1a4c + 0x20U < 0x10) {
      iVar7 = 0x10;
    }
    else {
      iVar7 = *DAT_300f1a4c + 0x20;
    }
    if ((uint)((int)puVar10 - iVar5) < uVar13 + iVar7) {
      puVar10[1] = puVar10[1] & 0xfffffffe;
      *puVar10 = (int)puVar10 - iVar5;
      *(uint *)((int)param_2 + -0xc) = (int)puVar10 - iVar5 | *(uint *)((int)param_2 + -0xc) & 1;
    }
    else {
      *(uint *)((int)param_2 + -0xc) = uVar13 | *(uint *)((int)param_2 + -0xc) & 1;
      puVar11 = (uint *)(iVar5 + (uVar14 & 0xfffffffc));
      puVar11[1] = (int)puVar10 - (int)puVar11;
      *puVar11 = uVar13;
      *puVar10 = (int)puVar10 - (int)puVar11;
      memPartInsertFree(param_1,puVar11);
      *(uint *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) - (puVar11[1] >> 1);
      uVar8 = *(int *)(param_1 + 0xf8) - (uint)(*(uint *)(param_1 + 0xf4) < puVar11[1] >> 1);
      *(uint *)(param_1 + 0xf4) = *(uint *)(param_1 + 0xf4) - (puVar11[1] >> 1);
      *(uint *)(param_1 + 0xf8) = uVar8;
    }
LAB_300f16d8:
    uVar3 = DAT_300f1a64;
    if (*DAT_300f1a4c != 0) {
      puVar6 = (undefined4 *)
               ((iVar5 + (*(uint *)((int)param_2 + -0xc) & 0xfffffffe)) - *DAT_300f1a4c);
      *puVar6 = DAT_300f1a64;
      puVar6[1] = uVar3;
      puVar6[2] = uVar3;
      puVar6[3] = uVar3;
    }
  }
  else {
    if (*DAT_300f1a4c + 0x20U < 0x10) {
      iVar7 = 0x10;
    }
    else {
      iVar7 = *DAT_300f1a4c + 0x20;
    }
    if (uVar8 <= uVar13 + iVar7) goto LAB_300f1718;
    *(uint *)((int)param_2 + -0xc) = uVar13 | *(uint *)((int)param_2 + -0xc) & 1;
    puVar9 = (uint *)(iVar5 + (uVar14 & 0xfffffffc));
    puVar12 = puVar11;
    if ((puVar10[1] & 1) != 0) {
      memPartDeleteFree(param_1,puVar11);
      puVar12 = puVar10;
    }
    *puVar9 = uVar13;
    puVar9[1] = (int)puVar12 - (int)puVar9;
    *puVar12 = (int)puVar12 - (int)puVar9;
    puVar12[1] = puVar12[1] | 1;
    memPartInsertFree(param_1,puVar9);
    bVar1 = true;
    *(uint *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) - ((uint)((int)puVar11 - (int)puVar9) >> 1)
    ;
    uVar8 = extraout_r1_00;
LAB_300f16d0:
    if (bVar1) goto LAB_300f16d8;
  }
  param_2 = pvVar4;
  if (!bVar2) {
    return pvVar4;
  }
LAB_300f1718:
  if (*(uint *)(param_1 + 0xfc) < (uint)(*(int *)(param_1 + 0xe8) + *(int *)(param_1 + 0x104))) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xe8) + *(int *)(param_1 + 0x104);
  }
  semMGive(param_1 + 0x50,uVar8);
  return param_2;
}

/* ----------------------------------------------------------------
 * memPartRealloc @ 0x300F1750  (примерный размер ~208 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 3
 * Вызывает: __errno, memPartReallocInternal, objVerify
 * Вызывают: FUN_300db20c, fat16VolMount, shellMemRealloc
 * Константы: 0x300F1750
 * Данные: DAT_300f1a28, DAT_300f1a2c, DAT_300f1a34, DAT_300f1a68
 * ---------------------------------------------------------------- */
undefined4 memPartRealloc(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 & 1) == 0) {
    if ((param_1 == 0) || (iVar3 = objVerify(param_1,*DAT_300f1a34), iVar3 != 0)) {
      uVar2 = 0;
    }
    else if (*(code **)(param_1 + 0xd0) == (code *)0x0) {
      uVar2 = memPartReallocInternal(param_1,param_2,param_3);
    }
    else {
      uVar2 = (**(code **)(param_1 + 0xd0))(param_1,*(undefined4 *)(param_1 + 0xd8),param_2,param_3)
      ;
    }
  }
  else if ((code *)*DAT_300f1a68 == (code *)0x0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300f1a28;
    uVar2 = 0;
  }
  else {
    uVar2 = (*(code *)*DAT_300f1a68)(param_1 + *DAT_300f1a2c,param_2,param_3);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300f1820 @ 0x300F1820  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F1820
 * Данные: DAT_300f1a6c, DAT_300f1a70
 * ---------------------------------------------------------------- */
void FUN_300f1820(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (((code *)*DAT_300f1a6c != (code *)0x0) && ((*(uint *)(param_1 + 0xbc) & 0x20) != 0)) {
    (*(code *)*DAT_300f1a6c)(*DAT_300f1a70,param_2,param_3,param_1,0,0,0);
  }
  return;
}

