/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 12 (функций: 150, адреса 0x300EDF24..0x300FBE34)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * selTaskDeleteHookAdd @ 0x300EDF24  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskDeleteHookAdd
 * Вызывают: usrRoot
 * Константы: 0x300EDF24
 * Данные: DAT_300eedb8, DAT_300eedc8, DAT_300eeed8
 * ---------------------------------------------------------------- */
void selTaskDeleteHookAdd(void)

{
  int iVar1;
  
  iVar1 = taskDeleteHookAdd(DAT_300eedc8);
  if ((iVar1 != 0) && ((code *)*DAT_300eedb8 != (code *)0x0)) {
    (*(code *)*DAT_300eedb8)(DAT_300eeed8,0,0,0,0,0,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300edf80 @ 0x300EDF80  (примерный размер ~196 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: ioctl
 * Вызывают: FUN_300eeb94, select
 * Константы: 0xFFFFFFFF, 0x300EDF80
 * ---------------------------------------------------------------- */
undefined4 FUN_300edf80(int param_1,int param_2,ulong param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint __fd;
  
  uVar5 = 0;
  *(undefined2 *)(param_4 + 0x12) = 0;
  __fd = 0;
  if (0 < param_2) {
    do {
      iVar1 = (__fd >> 5) * 4;
      uVar3 = *(uint *)(param_1 + iVar1);
      if (uVar3 == 0) {
        __fd = __fd + 0x1f;
      }
      else {
        uVar2 = 1 << (__fd & 0x1f);
        if ((uVar3 & uVar2) != 0) {
          *(short *)(param_4 + 0x10) = (short)__fd;
          iVar4 = ioctl(__fd,param_3,param_4);
          if ((iVar4 != 0) && (uVar5 = 0xffffffff, param_5 != 0)) {
            return 0xffffffff;
          }
          if (*(short *)(param_4 + 0x12) != 0) {
            puVar6 = (uint *)(*(int *)(param_4 + 0x18) + iVar1);
            *puVar6 = *puVar6 | uVar2;
            *(undefined2 *)(param_4 + 0x12) = 0;
          }
        }
      }
      __fd = __fd + 1;
    } while ((int)__fd < param_2);
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * selWakeup @ 0x300EE828  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 2
 * Вызывает: objVerify, semGive
 * Вызывают: FUN_300ed06c, FUN_300eecf8, FUN_300eedcc, FUN_300eee5c, selWakeupAll
 * Константы: 0x300EE828
 * Данные: DAT_300eeefc
 * ---------------------------------------------------------------- */
void selWakeup(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  iVar1 = objVerify(*(undefined4 *)(param_1 + 0xc),*DAT_300eeefc);
  if (iVar1 != 0) {
    return;
  }
  if (*(int *)(*(int *)(param_1 + 0xc) + 0xdc) == 0) {
    return;
  }
  *(undefined2 *)(param_1 + 0x12) = 1;
  semGive();
  return;
}

/* ----------------------------------------------------------------
 * selWakeupAll @ 0x300EE870  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 7
 * Вызывает: intContext, lstCount, lstFirst, lstNext, selWakeup, semGive, semTake
 * Вызывают: FUN_300ecefc, FUN_300ecf38, FUN_300ed06c
 * Константы: 0x300EE870, 0xFFFFFFFF
 * Данные: DAT_300eed94, DAT_300eef00
 * ---------------------------------------------------------------- */
void selWakeupAll(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = lstCount(param_1 + 0x84);
  if (iVar1 != 0) {
    iVar1 = intContext();
    if ((iVar1 == 0) || ((code *)*DAT_300eef00 == (code *)0x0)) {
      semTake(param_1,0xffffffff);
      for (iVar1 = lstFirst(param_1 + 0x84); iVar1 != 0; iVar1 = lstNext(iVar1)) {
        if (*(int *)(iVar1 + 0x14) == param_2) {
          selWakeup(iVar1);
        }
      }
      semGive(param_1);
    }
    else {
      (*(code *)*DAT_300eef00)(DAT_300eed94,param_1,param_2,0,0,0,0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * selNodeAdd @ 0x300EE928  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 5
 * Вызывает: lstAdd, lstCount, malloc, semGive, semTake
 * Вызывают: FUN_300ed06c, FUN_300eecf8, FUN_300eedcc, FUN_300eee5c
 * Константы: 0xFFFFFFFF, 0x300EE928
 * ---------------------------------------------------------------- */
undefined4 selNodeAdd(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  semTake(param_1,0xffffffff);
  iVar1 = lstCount(param_1 + 0x84);
  if (iVar1 == 0) {
    puVar4 = (undefined4 *)(param_1 + 0x68);
  }
  else {
    puVar4 = (undefined4 *)malloc(0x1c);
  }
  if (puVar4 != (undefined4 *)0x0) {
    iVar2 = 7;
    puVar3 = puVar4;
    do {
      iVar2 = iVar2 + -1;
      *puVar3 = *param_2;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    } while (iVar2 != 0);
    puVar4[2] = (uint)(iVar1 == 0);
    lstAdd(param_1 + 0x84,puVar4);
    semGive(param_1);
    return 0;
  }
  semGive(param_1);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * selNodeDelete @ 0x300EE9BC  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: free, lstDelete, lstFirst, lstNext, semGive, semTake
 * Вызывают: FUN_300ed06c, pipeDevDelete
 * Константы: 0xFFFFFFFF, 0x300EE9BC
 * ---------------------------------------------------------------- */
undefined4 selNodeDelete(int param_1,int param_2)

{
  void *__ptr;
  void *pvVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  semTake(param_1,0xffffffff);
  pvVar1 = (void *)lstFirst(param_1 + 0x84);
  while (__ptr = pvVar1, __ptr != (void *)0x0) {
    pvVar1 = (void *)lstNext(__ptr);
    if ((*(int *)((int)__ptr + 0xc) == *(int *)(param_2 + 0xc)) &&
       (*(int *)((int)__ptr + 0x14) == *(int *)(param_2 + 0x14))) {
      lstDelete(param_1 + 0x84,__ptr);
      if ((*(short *)((int)__ptr + 0x12) != 0) && (*(int *)((int)__ptr + 0x18) != 0)) {
        puVar2 = (uint *)(*(int *)((int)__ptr + 0x18) +
                         (uint)(*(ushort *)((int)__ptr + 0x10) >> 5) * 4);
        *puVar2 = *puVar2 | 1 << (*(ushort *)((int)__ptr + 0x10) & 0x1f);
      }
      if (*(int *)((int)__ptr + 8) == 0) {
        free(__ptr);
      }
      iVar3 = iVar3 + 1;
    }
  }
  semGive(param_1);
  uVar4 = 0;
  if (iVar3 == 0) {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * selWakeupListInit @ 0x300EEA98  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: lstInit, semMInit
 * Вызывают: pipeDevCreate
 * Константы: 0x300EEA98
 * Данные: DAT_300eef04
 * ---------------------------------------------------------------- */
void selWakeupListInit(int param_1)

{
  lstInit(param_1 + 0x84);
  semMInit(param_1,*DAT_300eef04);
  *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | 0x20;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300eeac8 @ 0x300EEAC8  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: objVerify, semGive
 * Вызывают: selWakeupListTerm
 * Константы: 0x300EEAC8
 * Данные: DAT_300eeefc
 * ---------------------------------------------------------------- */
void FUN_300eeac8(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  iVar1 = objVerify(*(undefined4 *)(param_1 + 0xc),*DAT_300eeefc);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0xdc);
  if (iVar1 == 0) {
    return;
  }
  *(undefined4 *)(iVar1 + 0x8c) = 1;
  semGive(iVar1);
  return;
}

/* ----------------------------------------------------------------
 * selWakeupListTerm @ 0x300EEB14  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_300eeac8, free, lstDelete, lstFirst, lstNext, semTake, semTerminate
 * Вызывают: pipeDevCreate, pipeDevDelete
 * Константы: 0x300EEB14, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void selWakeupListTerm(int param_1)

{
  void *__ptr;
  void *pvVar1;
  
  semTake(param_1,0xffffffff);
  pvVar1 = (void *)lstFirst(param_1 + 0x84);
  while (__ptr = pvVar1, __ptr != (void *)0x0) {
    pvVar1 = (void *)lstNext(__ptr);
    FUN_300eeac8(__ptr);
    lstDelete(param_1 + 0x84,__ptr);
    if (*(int *)((int)__ptr + 8) == 0) {
      free(__ptr);
    }
  }
  semTerminate(param_1);
  return;
}

/* ----------------------------------------------------------------
 * selWakeupListLen @ 0x300EEB84  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: lstCount
 * Вызывают: pipeDevDelete
 * Константы: 0x300EEB84
 * ---------------------------------------------------------------- */
void selWakeupListLen(int param_1)

{
  lstCount(param_1 + 0x84);
  return;
}

/* ----------------------------------------------------------------
 * selWakeupType @ 0x300EEB8C  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EEB8C
 * ---------------------------------------------------------------- */
undefined4 selWakeupType(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}

/* ----------------------------------------------------------------
 * FUN_300eeb94 @ 0x300EEB94  (примерный размер ~356 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300edf80, FUN_300ee694, free, semTerminate, taskIdSelf
 * Константы: 0x300EEB94
 * ---------------------------------------------------------------- */
void FUN_300eeb94(int param_1)

{
  int iVar1;
  void *__ptr;
  bool bVar2;
  undefined1 auStack_2c [12];
  int local_20;
  undefined4 local_18;
  
  __ptr = *(void **)(param_1 + 0xdc);
  *(undefined4 *)(param_1 + 0xdc) = 0;
  if (__ptr != (void *)0x0) {
    *(undefined4 *)(param_1 + 0xdc) = 0;
    iVar1 = taskIdSelf();
    bVar2 = iVar1 != param_1;
    if (*(int *)((int)__ptr + 0x68) == 1) {
      local_18 = 0;
      local_20 = param_1;
      if (bVar2) {
        FUN_300ee694(param_1,*(undefined4 *)((int)__ptr + 0x78),*(undefined4 *)((int)__ptr + 0x88),
                     0x1d,auStack_2c,0);
      }
      else {
        FUN_300edf80(*(undefined4 *)((int)__ptr + 0x78),*(undefined4 *)((int)__ptr + 0x88),0x1d,
                     auStack_2c,0);
      }
      local_18 = 1;
      if (bVar2) {
        FUN_300ee694(param_1,*(undefined4 *)((int)__ptr + 0x78),*(undefined4 *)((int)__ptr + 0x88),
                     0x1d,auStack_2c,0);
      }
      else {
        FUN_300edf80(*(undefined4 *)((int)__ptr + 0x7c),*(undefined4 *)((int)__ptr + 0x88),0x1d,
                     auStack_2c,0);
      }
      local_18 = 2;
      if (bVar2) {
        FUN_300ee694(param_1,*(undefined4 *)((int)__ptr + 0x78),*(undefined4 *)((int)__ptr + 0x88),
                     0x1d,auStack_2c,0);
      }
      else {
        FUN_300edf80(*(undefined4 *)((int)__ptr + 0x80),*(undefined4 *)((int)__ptr + 0x88),0x1d,
                     auStack_2c,0);
      }
    }
    semTerminate(__ptr);
    free(*(void **)((int)__ptr + 0x78));
    free(__ptr);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300eecf8 @ 0x300EECF8  (примерный размер ~212 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: rngFreeBytes, rngNBytes, selNodeAdd, selWakeup
 * Константы: 0x300EECF8
 * ---------------------------------------------------------------- */
void FUN_300eecf8(int param_1,int param_2)

{
  int iVar1;
  
  selNodeAdd(param_1 + 0x180);
  if ((*(int *)(param_2 + 0x14) == 0) &&
     (iVar1 = rngNBytes(*(undefined4 *)(param_1 + 0x20)), 0 < iVar1)) {
    selWakeup(param_2);
  }
  if (*(int *)(param_2 + 0x14) != 1) {
    return;
  }
  iVar1 = rngFreeBytes(*(undefined4 *)(param_1 + 0xfc));
  if (iVar1 < 1) {
    return;
  }
  selWakeup(param_2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300eedcc @ 0x300EEDCC  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: rngFreeBytes, rngNBytes, selNodeAdd, selWakeup
 * Константы: 0x300EEDCC
 * ---------------------------------------------------------------- */
void FUN_300eedcc(int param_1,int param_2)

{
  int iVar1;
  
  selNodeAdd(param_1 + 0x300);
  if ((*(int *)(param_2 + 0x14) == 0) &&
     (((iVar1 = rngNBytes(*(undefined4 *)(param_1 + 0xfc)), 0 < iVar1 ||
       (*(char *)(param_1 + 0x2fc) != '\0')) && (*(char *)(param_1 + 0x16b) == '\0')))) {
    selWakeup(param_2);
  }
  if (*(int *)(param_2 + 0x14) != 1) {
    return;
  }
  iVar1 = rngFreeBytes(*(undefined4 *)(param_1 + 0x20));
  if ((iVar1 < 1) && (*(char *)(param_1 + 0x2fd) == '\0')) {
    return;
  }
  selWakeup(param_2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300eee5c @ 0x300EEE5C  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: rngFreeBytes, rngNBytes, selNodeAdd, selWakeup
 * Константы: 0x300EEE5C
 * ---------------------------------------------------------------- */
void FUN_300eee5c(int param_1,int param_2)

{
  int iVar1;
  
  selNodeAdd(param_1 + 0x180);
  if ((*(int *)(param_2 + 0x14) == 0) &&
     ((iVar1 = rngNBytes(*(undefined4 *)(param_1 + 0x20)), 0 < iVar1 ||
      (*(char *)(param_1 + 0x2fe) != '\0')))) {
    selWakeup(param_2);
  }
  if (*(int *)(param_2 + 0x14) != 1) {
    return;
  }
  iVar1 = rngFreeBytes(*(undefined4 *)(param_1 + 0xfc));
  if ((iVar1 < 1) && (*(char *)(param_1 + 0x2ff) == '\0')) {
    return;
  }
  selWakeup(param_2);
  return;
}

/* ----------------------------------------------------------------
 * ttyDrv @ 0x300EEF08  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: iosDrvInstall
 * Вызывают: usrIosCoreInit, usrSerialInit
 * Константы: 0x300EEF08, 0xFFFFFFFF
 * Данные: DAT_300ef1cc, DAT_300ef1d0, DAT_300ef1d4, DAT_300ef1d8, DAT_300ef1dc, DAT_300ef1e0
 * ---------------------------------------------------------------- */
undefined4 ttyDrv(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_300ef1cc;
  if (*DAT_300ef1cc < 1) {
    iVar3 = iosDrvInstall(DAT_300ef1d4,0,DAT_300ef1d4,DAT_300ef1e0,DAT_300ef1d0,DAT_300ef1d8,
                          DAT_300ef1dc);
    *piVar1 = iVar3;
    uVar2 = 0;
    if (iVar3 == -1) {
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * ttyDevCreate @ 0x300EEF78  (примерный размер ~272 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: errnoSet, free, iosDevAdd, malloc, tyDevInit
 * Вызывают: usrSerialInit
 * Константы: 0xFFFFFFFF, 0x300EEF78
 * Данные: DAT_300ef1cc, DAT_300ef1e4, DAT_300ef1e8, DAT_300ef1ec, DAT_300ef1f0
 * ---------------------------------------------------------------- */
undefined4 ttyDevCreate(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  void *__ptr;
  int iVar3;
  
  piVar1 = DAT_300ef1cc;
  if (*DAT_300ef1cc < 1) {
    errnoSet(6);
    uVar2 = 0xffffffff;
  }
  else if (param_2 == (int *)0xffffffff || param_2 == (int *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    __ptr = malloc(0x274);
    if (__ptr == (void *)0x0) {
      uVar2 = 0xffffffff;
    }
    else {
      iVar3 = tyDevInit(__ptr,param_3,param_4,DAT_300ef1e4);
      if (iVar3 == 0) {
        *(int **)((int)__ptr + 0x270) = param_2;
        (**(code **)(*param_2 + 8))(param_2,1,DAT_300ef1e8,__ptr);
        (**(code **)(*param_2 + 8))(param_2,2,DAT_300ef1ec,__ptr);
        (**(code **)*param_2)(param_2,DAT_300ef1f0,2);
        uVar2 = iosDevAdd(__ptr,param_1,*piVar1);
      }
      else {
        free(__ptr);
        uVar2 = 0xffffffff;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300ef088 @ 0x300EF088  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EF088
 * Данные: DAT_300ef1f4
 * ---------------------------------------------------------------- */
int FUN_300ef088(int param_1,undefined4 param_2,int param_3)

{
  *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x210) + 1;
  *(int *)(param_1 + 0x228) = param_3 + 1;
  (**(code **)**(undefined4 **)(param_1 + 0x270))(*(undefined4 **)(param_1 + 0x270),DAT_300ef1f4,0);
  return param_1;
}

/* ----------------------------------------------------------------
 * FUN_300ef0d0 @ 0x300EF0D0  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EF0D0
 * Данные: DAT_300ef1f8
 * ---------------------------------------------------------------- */
undefined4 FUN_300ef0d0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x210) + -1;
  *(int *)(param_1 + 0x210) = iVar1;
  if (iVar1 == 0) {
    (**(code **)**(undefined4 **)(param_1 + 0x270))
              (*(undefined4 **)(param_1 + 0x270),DAT_300ef1f8,0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ef114 @ 0x300EF114  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: tyIoctl
 * Константы: 0x300EF114
 * Данные: DAT_300ef1fc
 * ---------------------------------------------------------------- */
int FUN_300ef114(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 == 4) {
    iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x270))
                      (*(undefined4 **)(param_1 + 0x270),DAT_300ef1fc,param_3);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = -1;
    }
  }
  else {
    iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x270))
                      (*(undefined4 **)(param_1 + 0x270),param_2,param_3);
    if (iVar1 == 0x47) {
      iVar1 = tyIoctl(param_1,param_2,param_3);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300ef1a8 @ 0x300EF1A8  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300EF1A8
 * ---------------------------------------------------------------- */
void FUN_300ef1a8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x270) + 4))();
  return;
}

/* ----------------------------------------------------------------
 * valloc @ 0x300F1214  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, memPartAlignedAlloc
 * Константы: 0x300F1214
 * Данные: DAT_300f1a40, DAT_300f1a44, DAT_300f1a48
 * ---------------------------------------------------------------- */
void * valloc(size_t __size)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  
  if ((*(code **)(DAT_300f1a44 + 0x20) == (code *)0x0) ||
     (iVar1 = (**(code **)(DAT_300f1a44 + 0x20))(), iVar1 == -1)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_300f1a48;
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = (void *)memPartAlignedAlloc(*DAT_300f1a40,__size,iVar1);
  }
  return pvVar3;
}

/* ----------------------------------------------------------------
 * sizeNodesAlloc @ 0x300F1D9C  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: FUN_300f1b90
 * Вызывают: FUN_300f1e5c, FUN_300f2514, FUN_300f2884, memPartReallocInternal
 * Константы: 0x300F1D9C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 sizeNodesAlloc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint local_10;
  
  if (param_3 == 0) {
    param_3 = 8;
  }
  if (*(uint *)(param_1 + 0x4c) < 4) {
    if (param_2 == 0) {
      param_2 = FUN_300f1b90(param_1,param_3 * 0x18,4,&local_10);
      if (param_2 == 0) {
        return 0xffffffff;
      }
      *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + (local_10 >> 1);
      *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;
    }
    iVar1 = param_2;
    if (param_3 != 1) {
      iVar2 = param_3 + -1;
      do {
        *(int *)(iVar1 + 0x10) = iVar1 + 0x18;
        iVar1 = iVar1 + 0x18;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(int *)(param_1 + 0x48) = param_2;
    *(int *)(param_1 + 0x4c) = param_3 + *(int *)(param_1 + 0x4c);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f1e5c @ 0x300F1E5C  (примерный размер ~380 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: __errno, memPartInsertFree, sizeNodesAlloc, sllPutAtTail
 * Вызывают: memPartAddToPool, memPartInit
 * Константы: 0xFFFFFFFC, 0xFFFFFFFF, 0xFFFFFFFE, 0x300F1E5C
 * Данные: DAT_300f2af4, DAT_300f2e60
 * ---------------------------------------------------------------- */
undefined4 FUN_300f1e5c(uint param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  
  uVar3 = param_2 + 3U & 0xfffffffc;
  if (uVar3 - param_2 < param_3) {
    param_3 = param_3 - (uVar3 - param_2);
  }
  else {
    param_3 = 0;
  }
  iVar7 = 0;
  if (*(int *)(param_1 + 0xb8) == 0) {
    iVar7 = 8;
  }
  else {
    iVar5 = sizeNodesAlloc(param_1,0,0);
    if (iVar5 != 0) {
      iVar7 = 1;
    }
  }
  param_3 = param_3 & 0xfffffffc;
  if (iVar7 * 0x18 + 0x78U <= param_3) {
    *(uint *)(uVar3 + 4) = param_3;
    puVar1 = (undefined4 *)(uVar3 + 8);
    iVar5 = param_3 - 8;
    if (iVar7 != 0) {
      iVar2 = sizeNodesAlloc(param_1,uVar3 + 8,iVar7);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      puVar1 = puVar1 + iVar7 * 6;
      iVar5 = iVar5 + iVar7 * -0x18;
      *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + (iVar7 * 0x18 + 8U >> 1);
      *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;
    }
    iVar7 = *DAT_300f2af4;
    *(uint *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + ((uint)(iVar5 - (iVar7 * 3 + 0x30)) >> 1)
    ;
    uVar8 = iVar7 + 0x10;
    *puVar1 = 0;
    puVar1[1] = uVar8;
    puVar1[2] = param_1;
    puVar4 = (uint *)((int)puVar1 + (uVar8 & 0xfffffffe));
    *puVar4 = uVar8;
    puVar6 = (uint *)((int)puVar1 + (iVar5 - (iVar7 * 2 + 0x20)));
    *puVar6 = (int)puVar6 - (int)puVar4;
    puVar4[1] = (int)puVar6 - (int)puVar4;
    puVar6[1] = uVar8 | 1;
    puVar6[2] = param_1;
    puVar6 = (uint *)((int)puVar6 + (uVar8 & 0xfffffffe));
    puVar6[1] = uVar8;
    *puVar6 = uVar8;
    puVar6[2] = param_1;
    memPartInsertFree(param_1,puVar4);
    sllPutAtTail(param_1 + 0xc0,uVar3);
    return 0;
  }
  puVar1 = (undefined4 *)__errno();
  *puVar1 = DAT_300f2e60;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * cfree @ 0x300F2DEC  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: memPartFree
 * Константы: 0x300F2DEC
 * Данные: DAT_300f2ee8
 * ---------------------------------------------------------------- */
void cfree(void *__ptr)

{
  memPartFree(*DAT_300f2ee8,__ptr);
  return;
}

/* ----------------------------------------------------------------
 * vmBaseLibInit @ 0x300F2EF4  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: classInit, objCoreInit, semMInit
 * Вызывают: usrMmuInit
 * Константы: 0x300F2EF4, 0xFFFFFFFF
 * Данные: DAT_300f3e38, DAT_300f3e3c, DAT_300f3e40, DAT_300f3e44, DAT_300f3e48, DAT_300f3e4c, DAT_300f3e50, DAT_300f3e54
 * ---------------------------------------------------------------- */
undefined4 vmBaseLibInit(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(DAT_300f3e38 + 4) == 0) {
    uVar2 = (**(code **)(DAT_300f3e3c + 0x24))();
    *DAT_300f3e40 = uVar2;
    iVar3 = classInit(DAT_300f3e44,0xb4,0,0,0,0,0,0,0xc,0);
    iVar1 = DAT_300f3e4c;
    if (iVar3 == -1) {
      return 0xffffffff;
    }
    objCoreInit(DAT_300f3e4c,*DAT_300f3e48);
    semMInit(iVar1 + 0x44,*DAT_300f3e50);
    *(int *)(*DAT_300f3e54 + 0x44) = iVar1;
    *DAT_300f3e5c = DAT_300f3e58;
    if (*DAT_300f3e60 == 0) {
      *DAT_300f3e60 = 0x20;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * vmCurrentGet @ 0x300F3048  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300ac2dc
 * Константы: 0x300F3048
 * Данные: DAT_300f3f58
 * ---------------------------------------------------------------- */
undefined4 vmCurrentGet(void)

{
  return *(undefined4 *)(*(int *)(*DAT_300f3f58 + 0x90) + 0x44);
}

/* ----------------------------------------------------------------
 * vmStateSet @ 0x300F305C  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 4
 * Вызывает: __errno, __udiv32, convertAttrFromArchIndepToDep, objVerify
 * Вызывают: FUN_300f36ec, FUN_300f3b24, vmBaseStateSet, vmTextProtect
 * Константы: 0xFFFFFFFF, 0x300F305C
 * Данные: DAT_300f3e3c, DAT_300f3e40, DAT_300f3e48, DAT_300f3f58, DAT_300f3f5c
 * ---------------------------------------------------------------- */
undefined4 vmStateSet(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_1 == 0) {
    param_1 = *(int *)(*(int *)(*DAT_300f3f58 + 0x90) + 0x44);
  }
  iVar2 = objVerify(param_1,*DAT_300f3e48);
  piVar1 = DAT_300f3e40;
  if (iVar2 == 0) {
    if (((param_2 & *DAT_300f3e40 - 1U) == 0) && ((param_3 & *DAT_300f3e40 - 1U) == 0)) {
      iVar2 = convertAttrFromArchIndepToDep(param_4,param_5,&local_20,&local_1c);
      if (iVar2 == -1) {
        uVar3 = 0xffffffff;
      }
      else {
        uVar3 = __udiv32(param_3,*piVar1);
        uVar3 = (**(code **)(DAT_300f3e3c + 0xc))
                          (*(undefined4 *)(param_1 + 0x40),param_2,uVar3,local_20,local_1c,0);
      }
    }
    else {
      puVar4 = (undefined4 *)__errno();
      *puVar4 = DAT_300f3f5c;
      uVar3 = 0xffffffff;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * vmBaseStateSet @ 0x300F3148  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: vmStateSet
 * Константы: 0x300F3148
 * ---------------------------------------------------------------- */
void vmBaseStateSet(void)

{
  vmStateSet();
  return;
}

/* ----------------------------------------------------------------
 * convertAttrFromArchDepToIndep @ 0x300F3164  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: vmContigBlockEach, vmInfoGet, vmStateGet
 * Константы: 0x300F3164
 * Данные: DAT_300f3e3c, DAT_300f4010, DAT_300f4014, DAT_300f4018, DAT_300f401c
 * ---------------------------------------------------------------- */
undefined4 convertAttrFromArchDepToIndep(uint param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint local_1c;
  
  iVar3 = 0;
  local_1c = 0;
  iVar2 = *DAT_300f4010;
  puVar1 = (uint *)(*DAT_300f4014 + -4);
  do {
    puVar1 = puVar1 + 1;
    if ((param_1 & *(uint *)(iVar2 + 4)) == *puVar1) {
      local_1c = local_1c | iVar3 << 1 | 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x20);
  iVar3 = 0;
  puVar1 = (uint *)(*DAT_300f4018 + -4);
  do {
    puVar1 = puVar1 + 1;
    if ((param_1 & *(uint *)(iVar2 + 0x10)) == *puVar1) {
      local_1c = local_1c | iVar3 << 7;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  iVar3 = 0;
  puVar1 = (uint *)(*DAT_300f401c + -4);
  do {
    puVar1 = puVar1 + 1;
    if ((param_1 & *(uint *)(iVar2 + 8)) == *puVar1) {
      local_1c = local_1c | iVar3 << 6;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  if (*(code **)(DAT_300f3e3c + 0x2c) != (code *)0x0) {
    (**(code **)(DAT_300f3e3c + 0x2c))(param_1,&local_1c,0,0,0);
  }
  *param_2 = local_1c;
  return 0;
}

/* ----------------------------------------------------------------
 * vmStateGet @ 0x300F327C  (примерный размер ~196 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: __errno, convertAttrFromArchDepToIndep, objVerify
 * Вызывают: FUN_300f3b24, exchRegsShow, vmInfoGet
 * Константы: 0xFFFFFFFF, 0x300F327C
 * Данные: DAT_300f3e3c, DAT_300f3e40, DAT_300f3e48, DAT_300f3f58, DAT_300f3f5c
 * ---------------------------------------------------------------- */
undefined4 vmStateGet(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_14;
  
  if (param_1 == 0) {
    param_1 = *(int *)(*(int *)(*DAT_300f3f58 + 0x90) + 0x44);
  }
  iVar1 = objVerify(param_1,*DAT_300f3e48);
  if (iVar1 == 0) {
    if ((param_2 & *DAT_300f3e40 - 1U) == 0) {
      iVar1 = (**(code **)(DAT_300f3e3c + 0x10))(*(undefined4 *)(param_1 + 0x40),param_2,&local_14);
      if (iVar1 == -1) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = convertAttrFromArchDepToIndep(local_14,param_3);
      }
    }
    else {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = DAT_300f3f5c;
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * vmPageSizeGet @ 0x300F3340  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: exchRegsShow
 * Константы: 0x300F3340
 * Данные: DAT_300f3e3c
 * ---------------------------------------------------------------- */
void vmPageSizeGet(void)

{
  (**(code **)(DAT_300f3e3c + 0x24))();
  return;
}

/* ----------------------------------------------------------------
 * vmBasePageSizeGet @ 0x300F3358  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F3358
 * Данные: DAT_300f3e3c
 * ---------------------------------------------------------------- */
void vmBasePageSizeGet(void)

{
  (**(code **)(DAT_300f3e3c + 0x24))();
  return;
}

/* ----------------------------------------------------------------
 * vmTranslate @ 0x300F3370  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: objVerify
 * Константы: 0x300F3370, 0xFFFFFFFF
 * Данные: DAT_300f3e3c, DAT_300f3e48, DAT_300f3f58
 * ---------------------------------------------------------------- */
undefined4 vmTranslate(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    param_1 = *(int *)(*(int *)(*DAT_300f3f58 + 0x90) + 0x44);
  }
  iVar1 = objVerify(param_1,*DAT_300f3e48);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(DAT_300f3e3c + 0x1c))(*(undefined4 *)(param_1 + 0x40),param_2,param_3);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * vmPhysTranslate @ 0x300F33D8  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: objVerify
 * Константы: 0x300F33D8, 0xFFFFFFFF
 * Данные: DAT_300f3e3c, DAT_300f3e48, DAT_300f3f58
 * ---------------------------------------------------------------- */
undefined4 vmPhysTranslate(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    param_1 = *(int *)(*(int *)(*DAT_300f3f58 + 0x90) + 0x44);
  }
  iVar1 = objVerify(param_1,*DAT_300f3e48);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(DAT_300f3e3c + 0x28))
                      (*(undefined4 *)(param_1 + 0x40),param_2,param_3,param_4);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * vmPgMap @ 0x300F3448  (примерный размер ~452 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: __errno, __udiv32, convertAttrFromArchIndepToDep, objVerify, semGive, semTake
 * Вызывают: vmMap, vmPageMap
 * Константы: 0xFFFFFFFF, 0x300F3448
 * Данные: DAT_300f3e3c, DAT_300f3e40, DAT_300f3e48, DAT_300f3f58, DAT_300f3f5c, DAT_300f4020, DAT_300f4024, DAT_300f4028
 * ---------------------------------------------------------------- */
undefined4
vmPgMap(int param_1,uint param_2,uint param_3,undefined4 param_4,uint param_5,int param_6,
       uint param_7,uint param_8)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_34;
  undefined1 auStack_30 [4];
  uint local_2c;
  undefined4 local_28;
  
  if (param_1 == 0) {
    param_1 = *(int *)(*(int *)(*DAT_300f3f58 + 0x90) + 0x44);
  }
  uVar5 = 0xffffffff;
  iVar2 = objVerify(param_1,*DAT_300f3e48);
  piVar1 = DAT_300f3e40;
  if (iVar2 == 0) {
    iVar2 = *DAT_300f3e40;
    if ((((param_2 & iVar2 - 1U) == 0) && ((param_5 & iVar2 - 1U) == 0)) &&
       ((*DAT_300f4020 != 0 || ((param_3 & iVar2 - 1U) == 0)))) {
      if ((code *)*DAT_300f4024 == (code *)0x0) {
        if (param_6 != 0) {
          puVar3 = (undefined4 *)__errno();
          *puVar3 = DAT_300f402c;
          return 0xffffffff;
        }
      }
      else {
        local_2c = param_3;
        local_28 = param_4;
        iVar2 = (*(code *)*DAT_300f4024)(param_3,param_4,param_5,param_6);
        if (iVar2 == -1) {
          if (param_6 == 0) {
            return 0xffffffff;
          }
          puVar3 = (undefined4 *)__errno();
          *puVar3 = DAT_300f4028;
          return 0xffffffff;
        }
      }
      iVar2 = semTake(param_1 + 0x44,0xffffffff);
      if (iVar2 != -1) {
        iVar2 = convertAttrFromArchIndepToDep
                          (param_7 | ~param_7 & DAT_300f4030,
                           ~param_7 & DAT_300f4034 | param_7 & param_8,auStack_30,&local_34);
        if (iVar2 == -1) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar4 = __udiv32(param_5,*piVar1);
          iVar2 = (**(code **)(DAT_300f3e3c + 0x14))
                            (*(undefined4 *)(param_1 + 0x40),param_2,param_3,param_4,uVar4,0,
                             local_34);
          if (iVar2 == 0) {
            uVar5 = 0;
          }
          semGive(param_1 + 0x44);
        }
      }
    }
    else {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = DAT_300f3f5c;
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * vmMap @ 0x300F360C  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: vmPgMap
 * Константы: 0x300F360C
 * ---------------------------------------------------------------- */
void vmMap(void)

{
  vmPgMap();
  return;
}

/* ----------------------------------------------------------------
 * vmPageMap @ 0x300F3638  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: vmPgMap
 * Константы: 0x300F3638
 * ---------------------------------------------------------------- */
void vmPageMap(void)

{
  vmPgMap();
  return;
}

/* ----------------------------------------------------------------
 * vmTextProtect @ 0x300F366C  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, vmStateSet
 * Константы: 0x300F366C, 0xFFFFFFFF
 * Данные: DAT_300f3e38, DAT_300f3e40, DAT_300f4038, DAT_300f403c, DAT_300f4040
 * ---------------------------------------------------------------- */
undefined4 vmTextProtect(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (*(int *)(DAT_300f3e38 + 4) == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300f4038;
    uVar2 = 0xffffffff;
  }
  else {
    *(undefined4 *)(DAT_300f3e38 + 0xc) = 1;
    if (param_1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar3 = (*DAT_300f3e40 + DAT_300f403c) - 1U & ~(*DAT_300f3e40 - 1U);
      uVar2 = vmStateSet(0,uVar3,DAT_300f4040 - uVar3,0x3f,5);
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300f36ec @ 0x300F36EC  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: vmStateSet
 * Константы: 0x300F36EC, 0xFFFFFFFF
 * Данные: DAT_300f3e38, DAT_300f3e40
 * ---------------------------------------------------------------- */
undefined4 FUN_300f36ec(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (*(int *)(DAT_300f3e38 + 0xc) != 0) {
    uVar1 = vmStateSet(0,param_1,*DAT_300f3e40,0x3f,(param_2 == 0) * '\x02' + '\x05');
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * vmBufferWrite @ 0x300F3748  (примерный размер ~256 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: objVerify, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300F3748
 * Данные: DAT_300f3e3c, DAT_300f3e40, DAT_300f3e48, DAT_300f3e60, DAT_300f3f58
 * ---------------------------------------------------------------- */
undefined4 vmBufferWrite(int param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    param_1 = *(int *)(*(int *)(*DAT_300f3f58 + 0x90) + 0x44);
  }
  bVar1 = false;
  iVar2 = objVerify(param_1,*DAT_300f3e48);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  if (param_4 <= *DAT_300f3e60) {
    iVar2 = *DAT_300f3e40;
    uVar4 = (param_2 + iVar2) - 1 & ~(iVar2 - 1U);
    if (((uVar4 == param_2) || (param_4 <= uVar4 - param_2)) &&
       ((uVar4 = (param_3 + iVar2) - 1 & ~(iVar2 - 1U), uVar4 == param_3 ||
        (param_4 <= uVar4 - param_3)))) goto LAB_300f3808;
  }
  iVar2 = semTake(param_1 + 0x44,0xffffffff);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  bVar1 = true;
LAB_300f3808:
  uVar3 = (**(code **)(DAT_300f3e3c + 0x34))
                    (*(undefined4 *)(param_1 + 0x40),param_2,param_3,param_4);
  if (bVar1) {
    semGive(param_1 + 0x44);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * vmPageOptimize @ 0x300F3848  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: __errno, __udiv32, objVerify, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300F3848
 * Данные: DAT_300f3e3c, DAT_300f3e40, DAT_300f3e48, DAT_300f3f58, DAT_300f3f5c, DAT_300f4044
 * ---------------------------------------------------------------- */
undefined4 vmPageOptimize(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = DAT_300f3e3c;
  uVar5 = 0xffffffff;
  if (*(int *)(DAT_300f3e3c + 0x30) == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = DAT_300f4044;
  }
  else {
    if (param_1 == 0) {
      param_1 = *(int *)(*(int *)(*DAT_300f3f58 + 0x90) + 0x44);
    }
    iVar4 = objVerify(param_1,*DAT_300f3e48);
    piVar2 = DAT_300f3e40;
    if (iVar4 == 0) {
      if (((param_2 & *DAT_300f3e40 - 1U) == 0) && ((param_3 & *DAT_300f3e40 - 1U) == 0)) {
        iVar4 = semTake(param_1 + 0x44,0xffffffff);
        if (iVar4 != -1) {
          uVar5 = __udiv32(param_3,*piVar2);
          uVar5 = (**(code **)(iVar1 + 0x30))(*(undefined4 *)(param_1 + 0x40),param_2,uVar5,param_4)
          ;
          semGive(param_1 + 0x44);
        }
      }
      else {
        puVar3 = (undefined4 *)__errno();
        *puVar3 = DAT_300f3f5c;
      }
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * vmPageLock @ 0x300F393C  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: __errno, __udiv32, objVerify, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300F393C
 * Данные: DAT_300f3e3c, DAT_300f3e40, DAT_300f3e48, DAT_300f3f58, DAT_300f3f5c, DAT_300f4044
 * ---------------------------------------------------------------- */
undefined4 vmPageLock(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = DAT_300f3e3c;
  uVar5 = 0xffffffff;
  if (*(int *)(DAT_300f3e3c + 0x38) == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = DAT_300f4044;
  }
  else {
    if (param_1 == 0) {
      param_1 = *(int *)(*(int *)(*DAT_300f3f58 + 0x90) + 0x44);
    }
    iVar4 = objVerify(param_1,*DAT_300f3e48);
    piVar2 = DAT_300f3e40;
    if (iVar4 == 0) {
      if (((param_2 & *DAT_300f3e40 - 1U) == 0) && ((param_3 & *DAT_300f3e40 - 1U) == 0)) {
        iVar4 = semTake(param_1 + 0x44,0xffffffff);
        if (iVar4 != -1) {
          uVar5 = __udiv32(param_3,*piVar2);
          uVar5 = (**(code **)(iVar1 + 0x38))(*(undefined4 *)(param_1 + 0x40),param_2,uVar5,param_4)
          ;
          semGive(param_1 + 0x44);
        }
      }
      else {
        puVar3 = (undefined4 *)__errno();
        *puVar3 = DAT_300f3f5c;
      }
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * vmPageUnlock @ 0x300F3A30  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: __errno, objVerify, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300F3A30
 * Данные: DAT_300f3e3c, DAT_300f3e40, DAT_300f3e48, DAT_300f3f58, DAT_300f3f5c, DAT_300f4044
 * ---------------------------------------------------------------- */
undefined4 vmPageUnlock(int param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = DAT_300f3e3c;
  uVar4 = 0xffffffff;
  if (*(int *)(DAT_300f3e3c + 0x3c) == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_300f4044;
  }
  else {
    if (param_1 == 0) {
      param_1 = *(int *)(*(int *)(*DAT_300f3f58 + 0x90) + 0x44);
    }
    iVar3 = objVerify(param_1,*DAT_300f3e48);
    if (iVar3 == 0) {
      if ((param_2 & *DAT_300f3e40 - 1U) == 0) {
        iVar3 = semTake(param_1 + 0x44,0xffffffff);
        if (iVar3 != -1) {
          uVar4 = (**(code **)(iVar1 + 0x3c))(*(undefined4 *)(param_1 + 0x40),param_2,0);
          semGive(param_1 + 0x44);
        }
      }
      else {
        puVar2 = (undefined4 *)__errno();
        *puVar2 = DAT_300f3f5c;
      }
    }
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * vmMaxPhysBitsGet @ 0x300F3AF8  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F3AF8
 * Данные: DAT_300f3e3c
 * ---------------------------------------------------------------- */
undefined4 vmMaxPhysBitsGet(void)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_300f3e3c + 0x40) == (code *)0x0) {
    uVar1 = 0x20;
  }
  else {
    uVar1 = (**(code **)(DAT_300f3e3c + 0x40))();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300f3b24 @ 0x300F3B24  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: vmStateGet, vmStateSet
 * Вызывают: vmInfoGet
 * Константы: 0x300F3B24
 * Данные: DAT_300f3e40
 * ---------------------------------------------------------------- */
undefined4 FUN_300f3b24(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_10;
  
  puVar1 = DAT_300f3e40;
  uVar3 = 0;
  iVar2 = vmStateSet(0,param_1,*DAT_300f3e40,0x3f,3);
  if (iVar2 != -1) {
    iVar2 = vmStateGet(0,param_1,&local_10);
    if ((iVar2 != -1) && ((local_10 & 4) == 0)) {
      uVar3 = 1;
    }
    vmStateSet(0,param_1,*puVar1,0x3f,7);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * vmInfoGet @ 0x300F3BB0  (примерный размер ~300 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300f3b24, convertAttrFromArchDepToIndep, memPartAlignedAlloc, memPartFree, vmStateGet
 * Константы: 0x300F3BB0, 0xFFFFFFFF
 * Данные: DAT_300f3e38, DAT_300f3e3c, DAT_300f3e40, DAT_300f4018, DAT_300f4048, DAT_300f404c
 * ---------------------------------------------------------------- */
undefined4 vmInfoGet(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  uint local_1c;
  undefined4 local_18;
  
  puVar2 = DAT_300f4048;
  uVar4 = 0;
  bVar5 = param_1 == (undefined4 *)0x0;
  local_1c = 0;
  local_18 = 0;
  if (!bVar5) {
    bVar5 = *(int *)(DAT_300f3e38 + 4) == 0;
  }
  if (bVar5) {
    uVar4 = 0xffffffff;
  }
  else {
    if (DAT_300f4048[2] == 0) {
      convertAttrFromArchDepToIndep
                (*(undefined4 *)(*DAT_300f4018 + *(int *)(*DAT_300f4018 + 0x40) * 4),&local_1c);
      puVar1 = DAT_300f3e40;
      iVar3 = memPartAlignedAlloc(*DAT_300f404c,*DAT_300f3e40,*DAT_300f3e40);
      if (iVar3 != 0) {
        vmStateGet(0,iVar3,&local_18);
        uVar4 = FUN_300f3b24(iVar3);
        memPartFree(*DAT_300f404c,iVar3);
      }
      puVar2[4] = local_1c & 0xf80;
      puVar2[3] = local_18;
      *puVar2 = uVar4;
      puVar2[1] = (uint)(*(int *)(DAT_300f3e3c + 0x30) != 0);
      puVar2[2] = *puVar1;
    }
    uVar4 = 0;
    *param_1 = *puVar2;
    param_1[1] = puVar2[1];
    param_1[2] = puVar2[2];
    param_1[3] = puVar2[3];
    param_1[4] = puVar2[4];
    param_1[5] = puVar2[5];
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * vmKernelContextIdGet @ 0x300F3CDC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F3CDC
 * Данные: DAT_300f3e4c
 * ---------------------------------------------------------------- */
undefined4 vmKernelContextIdGet(void)

{
  return DAT_300f3e4c;
}

/* ----------------------------------------------------------------
 * vmContigBlockEach @ 0x300F3CE4  (примерный размер ~876 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: __errno, convertAttrFromArchDepToIndep, objVerify
 * Константы: 0xFFFFFFFF, 0x300F3CE4
 * Данные: DAT_300f3e3c, DAT_300f3e40, DAT_300f3e48, DAT_300f3f58
 * ---------------------------------------------------------------- */
undefined4
vmContigBlockEach(int param_1,uint param_2,int param_3,uint param_4,code *param_5,undefined4 param_6
                 )

{
  bool bVar1;
  bool bVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  bool bVar18;
  uint local_60;
  uint local_4c;
  int local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  int local_34;
  int local_c;
  
  local_60 = 0;
  local_c = param_1;
  if (param_1 == 0) {
    local_c = *(int *)(*(int *)(*DAT_300f3f58 + 0x90) + 0x44);
  }
  iVar4 = objVerify(local_c,*DAT_300f3e48);
  puVar3 = DAT_300f3e40;
  if (iVar4 == 0) {
    bVar2 = false;
    bVar18 = true;
    iVar13 = -1;
    uVar11 = 0xffffffff;
    param_2 = param_2 & ~(*DAT_300f3e40 - 1);
    uVar15 = 0;
    iVar4 = -1;
    uVar9 = 0xffffffff;
    puVar6 = (undefined4 *)__errno();
    local_40 = *puVar6;
    uVar17 = param_2;
    iVar8 = param_3;
    if (param_3 != 0) {
      do {
        local_48 = iVar8;
        iVar8 = DAT_300f3e3c;
        bVar1 = true;
        iVar7 = (**(code **)(DAT_300f3e3c + 0x1c))(*(undefined4 *)(local_c + 0x40),uVar17,&local_38)
        ;
        if (iVar7 == 0) {
          if (param_4 != 0) {
            iVar8 = (**(code **)(iVar8 + 0x10))(*(undefined4 *)(local_c + 0x40),uVar17,&local_3c);
            if (iVar8 == 0) {
              local_4c = local_60;
              iVar8 = convertAttrFromArchDepToIndep(local_3c,&local_4c);
              local_60 = local_4c;
              if (iVar8 == 0) goto LAB_300f3e78;
            }
            goto LAB_300f3e1c;
          }
LAB_300f3e78:
          uVar10 = local_38;
          iVar7 = local_34;
          uVar12 = local_38;
          iVar8 = local_34;
          uVar14 = uVar17;
          uVar16 = local_60;
          if (!bVar18) {
            bVar18 = local_34 == iVar13 && local_38 == uVar11;
            uVar12 = uVar11;
            iVar8 = iVar13;
            if (local_34 == iVar13 && local_38 == uVar11) {
              uVar10 = uVar9;
              iVar7 = iVar4;
              uVar14 = param_2;
              uVar16 = uVar15;
              if (param_4 == 0) goto LAB_300f3edc;
              bVar18 = (local_60 & param_4) == (uVar15 & param_4);
            }
            uVar10 = uVar9;
            iVar7 = iVar4;
            uVar14 = param_2;
            uVar16 = uVar15;
            if (!bVar18) {
              bVar2 = true;
            }
          }
LAB_300f3edc:
          bVar18 = false;
          if (bVar2) goto LAB_300f3ef0;
        }
        else {
LAB_300f3e1c:
          bVar1 = !bVar18;
          bVar18 = true;
          uVar10 = uVar9;
          iVar7 = iVar4;
          uVar14 = param_2;
          uVar16 = uVar15;
LAB_300f3ef0:
          if ((bVar1) &&
             (iVar4 = (*param_5)(uVar14,uVar17 - uVar14,uVar10,iVar7,uVar16,param_6), iVar4 == -1))
          {
            return 0xffffffff;
          }
          bVar2 = false;
          uVar10 = local_38;
          iVar7 = local_34;
          uVar12 = local_38;
          iVar8 = local_34;
          uVar14 = uVar17;
          uVar16 = local_60;
        }
        uVar9 = *puVar3;
        uVar11 = uVar12 + uVar9;
        iVar13 = iVar8 + ((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar12,uVar9);
        local_48 = local_48 + -1;
        uVar17 = uVar17 + uVar9;
        uVar9 = uVar10;
        iVar4 = iVar7;
        param_2 = uVar14;
        uVar15 = uVar16;
        iVar8 = local_48;
      } while (local_48 != 0);
      if ((!bVar18) &&
         (iVar4 = (*param_5)(uVar14,uVar17 - uVar14,uVar10,iVar7,uVar16,param_6), iVar4 == -1)) {
        return 0xffffffff;
      }
    }
    puVar6 = (undefined4 *)__errno();
    *puVar6 = local_40;
    uVar5 = 0;
  }
  else {
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * convertAttrFromArchIndepToDep @ 0x300F4050  (примерный размер ~560 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: __errno
 * Вызывают: vmBaseGlobalMapInit, vmGlobalMapInit, vmPgMap, vmStateSet
 * Константы: 0xFFFFFFFF, 0x300F4050
 * Данные: DAT_300f450c, DAT_300f4510, DAT_300f4514, DAT_300f4518, DAT_300f451c, DAT_300f4520, DAT_300f4524, DAT_300f4528
 * ---------------------------------------------------------------- */
undefined4
convertAttrFromArchIndepToDep(uint param_1,uint param_2,undefined4 *param_3,uint *param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint local_1c;
  undefined4 local_18;
  
  bVar1 = false;
  local_18 = 0;
  local_1c = 0;
  uVar5 = local_1c;
  if ((param_1 & 0x3f) == 0x3f) {
    bVar1 = true;
    uVar5 = *(uint *)(*DAT_300f450c + (param_2 >> 1 & 0x1f) * 4);
    if ((*DAT_300f4510 == uVar5) || ((~param_2 & 1) != 0)) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300f4514;
      return 0xffffffff;
    }
  }
  local_1c = uVar5;
  if ((param_1 & 0xf80) == 0xf80) {
    bVar1 = true;
    if (((param_2 & 0x800) != 0) && ((param_2 & 0x180) != 0)) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300f4514;
      return 0xffffffff;
    }
    uVar5 = 0;
    if ((param_2 & 0x800) != 0) {
      uVar5 = *(uint *)(*DAT_300f4518 + 0x40);
    }
    if (*DAT_300f4510 == uVar5) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300f4514;
      return 0xffffffff;
    }
    if ((param_2 & 0x780) != 0) {
      uVar5 = uVar5 + (param_2 >> 7 & 0xf);
    }
    uVar5 = *(uint *)(*DAT_300f4518 + uVar5 * 4);
    if (*DAT_300f4510 == uVar5) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300f4514;
      return 0xffffffff;
    }
    local_1c = local_1c | uVar5;
  }
  if ((param_1 & 0x40) != 0) {
    bVar1 = true;
    uVar5 = *(uint *)(*DAT_300f451c + (param_2 >> 6 & 1) * 4);
    if (*DAT_300f4510 == uVar5) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300f4520;
      return 0xffffffff;
    }
    local_1c = local_1c | uVar5;
  }
  if (bVar1) {
    local_18 = *(undefined4 *)(*DAT_300f4524 + (param_1 >> 5 & 7) * 4);
  }
  if (((param_1 & 0xff000) == 0xff000) || (bVar1)) {
    if ((*(code **)(DAT_300f4528 + 0x2c) == (code *)0x0) ||
       (iVar3 = (**(code **)(DAT_300f4528 + 0x2c))(param_2,&local_1c,param_1,&local_18,1),
       iVar3 != -1)) {
      uVar4 = 0;
      *param_3 = local_18;
      *param_4 = local_1c;
    }
    else {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300f4514;
      uVar4 = 0xffffffff;
    }
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_300f4514;
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * vmGlobalMapInit @ 0x300F4280  (примерный размер ~648 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: __errno, __udiv32, convertAttrFromArchIndepToDep, sprintf
 * Вызывают: usrMmuInit
 * Константы: 0xFFFFFFFF, 0x300F4280
 * Данные: DAT_300f4518, DAT_300f4528, DAT_300f452c, DAT_300f4530, DAT_300f4534, DAT_300f4538, DAT_300f453c, DAT_300f4540
 * ---------------------------------------------------------------- */
int vmGlobalMapInit(uint *param_1,int param_2,int param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  char *__s;
  uint uVar6;
  int iVar7;
  undefined4 local_2c;
  undefined1 auStack_28 [4];
  
  piVar1 = DAT_300f452c;
  puVar3 = DAT_300f4528;
  iVar2 = (*(code *)DAT_300f4528[9])();
  *piVar1 = iVar2;
  iVar2 = 3;
  if ((param_4 & 1) == 0) {
    iVar2 = ((int)param_4 >> 1 & 1U) + 1;
  }
  *(int *)(*DAT_300f4518 + 0x40) = iVar2;
  iVar2 = (*(code *)*puVar3)();
  *(int *)(DAT_300f4530 + 0x40) = iVar2;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    if (0 < param_2) {
      do {
        if (param_1[2] != 0xffffffff || param_1[1] != 0xffffffff) {
          iVar7 = *piVar1;
          if (((*param_1 & iVar7 - 1U) != 0) ||
             ((((param_1[1] & iVar7 - 1U) != 0 && (*DAT_300f4534 == 0)) ||
              ((param_1[3] & iVar7 - 1U) != 0)))) {
            puVar3 = (undefined4 *)__errno(0xffffffff);
            *puVar3 = DAT_300f4538;
            return 0;
          }
          uVar5 = param_1[4];
          iVar7 = convertAttrFromArchIndepToDep
                            (~uVar5 & DAT_300f453c | uVar5,
                             ~uVar5 & DAT_300f4540 | uVar5 & param_1[5],auStack_28,&local_2c);
          if (iVar7 == -1) {
            __s = (char *)*DAT_300f4544;
            iVar2 = sprintf(__s,DAT_300f4548,iVar2);
            *DAT_300f4544 = __s + iVar2;
            return 0;
          }
          uVar6 = param_1[2];
          uVar5 = param_1[1];
          uVar4 = __udiv32(param_1[3],*piVar1);
          iVar7 = (*(code *)puVar3[6])(*param_1,uVar5,uVar6,uVar4,0,local_2c);
          if (iVar7 == -1) {
            return 0;
          }
          if (((code *)*DAT_300f454c != (code *)0x0) &&
             (iVar7 = (*(code *)*DAT_300f454c)(param_1[1],param_1[2],param_1[3],0), iVar7 == -1)) {
            return 0;
          }
        }
        param_1 = param_1 + 6;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_2);
    }
    (*(code *)puVar3[8])(*(undefined4 *)(DAT_300f4530 + 0x40));
    *DAT_300f4550 = 1;
    if ((code *)*DAT_300f4554 != (code *)0x0) {
      (*(code *)*DAT_300f4554)();
    }
    if ((code *)*DAT_300f4558 != (code *)0x0) {
      (*(code *)*DAT_300f4558)();
    }
    iVar2 = DAT_300f4530;
    if ((param_3 != 0) && (iVar7 = (*(code *)puVar3[2])(1), iVar2 = DAT_300f4530, iVar7 == -1)) {
      iVar2 = 0;
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * vmBaseGlobalMapInit @ 0x300F4508  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: __errno, __udiv32, convertAttrFromArchIndepToDep, sprintf
 * Константы: 0xFFFFFFFF, 0x300F4508
 * Данные: DAT_300f4518, DAT_300f4528, DAT_300f452c, DAT_300f4530, DAT_300f4534, DAT_300f4538, DAT_300f453c, DAT_300f4540
 * ---------------------------------------------------------------- */
int vmBaseGlobalMapInit(uint *param_1,int param_2,int param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  char *__s;
  uint uVar6;
  int iVar7;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  
  piVar1 = DAT_300f452c;
  puVar3 = DAT_300f4528;
  iVar2 = (*(code *)DAT_300f4528[9])();
  *piVar1 = iVar2;
  iVar2 = 3;
  if ((param_4 & 1) == 0) {
    iVar2 = ((int)param_4 >> 1 & 1U) + 1;
  }
  *(int *)(*DAT_300f4518 + 0x40) = iVar2;
  iVar2 = (*(code *)*puVar3)();
  *(int *)(DAT_300f4530 + 0x40) = iVar2;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    if (0 < param_2) {
      do {
        if (param_1[2] != 0xffffffff || param_1[1] != 0xffffffff) {
          iVar7 = *piVar1;
          if (((*param_1 & iVar7 - 1U) != 0) ||
             ((((param_1[1] & iVar7 - 1U) != 0 && (*DAT_300f4534 == 0)) ||
              ((param_1[3] & iVar7 - 1U) != 0)))) {
            puVar3 = (undefined4 *)__errno(0xffffffff);
            *puVar3 = DAT_300f4538;
            return 0;
          }
          uVar5 = param_1[4];
          iVar7 = convertAttrFromArchIndepToDep
                            (~uVar5 & DAT_300f453c | uVar5,
                             ~uVar5 & DAT_300f4540 | uVar5 & param_1[5],auStack_28,&uStack_2c);
          if (iVar7 == -1) {
            __s = (char *)*DAT_300f4544;
            iVar2 = sprintf(__s,DAT_300f4548,iVar2);
            *DAT_300f4544 = __s + iVar2;
            return 0;
          }
          uVar6 = param_1[2];
          uVar5 = param_1[1];
          uVar4 = __udiv32(param_1[3],*piVar1);
          iVar7 = (*(code *)puVar3[6])(*param_1,uVar5,uVar6,uVar4,0,uStack_2c);
          if (iVar7 == -1) {
            return 0;
          }
          if (((code *)*DAT_300f454c != (code *)0x0) &&
             (iVar7 = (*(code *)*DAT_300f454c)(param_1[1],param_1[2],param_1[3],0), iVar7 == -1)) {
            return 0;
          }
        }
        param_1 = param_1 + 6;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_2);
    }
    (*(code *)puVar3[8])(*(undefined4 *)(DAT_300f4530 + 0x40));
    *DAT_300f4550 = 1;
    if ((code *)*DAT_300f4554 != (code *)0x0) {
      (*(code *)*DAT_300f4554)();
    }
    if ((code *)*DAT_300f4558 != (code *)0x0) {
      (*(code *)*DAT_300f4558)();
    }
    iVar2 = DAT_300f4530;
    if ((param_3 != 0) && (iVar7 = (*(code *)puVar3[2])(1), iVar2 = DAT_300f4530, iVar7 == -1)) {
      iVar2 = 0;
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * trcStack @ 0x300F455C  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: trcStackTrace
 * Вызывают: FUN_30110e10, dbgStackTrace
 * Константы: 0x300F455C
 * Данные: DAT_300f46c0, DAT_300f46c4
 * ---------------------------------------------------------------- */
void trcStack(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 local_74;
  undefined4 local_70;
  int local_64;
  undefined4 local_60;
  undefined1 *local_5c;
  undefined4 local_58;
  undefined1 auStack_54 [84];
  
  if (param_2 == 0) {
    param_2 = DAT_300f46c0;
  }
  local_74 = DAT_300f46c4;
  local_60 = 0x14;
  local_5c = auStack_54;
  local_58 = 1;
  local_70 = param_3;
  local_64 = param_2;
  trcStackTrace(param_1,&local_74);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f45a4 @ 0x300F45A4  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F45A4
 * Данные: DAT_300f46c8, DAT_300f46cc, DAT_300f46d0, DAT_300f46d4, DAT_300f46d8, DAT_300f46dc, DAT_300f46e0, DAT_300f46e4
 * ---------------------------------------------------------------- */
void FUN_300f45a4(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar2 = DAT_300f46c8;
  bVar1 = false;
  if ((code *)*DAT_300f46c8 != (code *)0x0) {
    (*(code *)*DAT_300f46c8)(DAT_300f46cc,param_1,param_2);
    if ((param_3 == 0) && (iVar4 = *DAT_300f46d0, iVar4 != 0)) {
      bVar1 = true;
      (*(code *)*puVar2)(DAT_300f46d4);
      param_3 = iVar4;
    }
    iVar4 = 0;
    if (0 < param_3) {
      puVar3 = (undefined4 *)(param_4 + -4);
      do {
        if (iVar4 != 0) {
          (*(code *)*puVar2)(DAT_300f46d8);
        }
        puVar3 = puVar3 + 1;
        (*(code *)*puVar2)(DAT_300f46dc,*puVar3);
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_3);
    }
    if (bVar1) {
      (*(code *)*puVar2)(DAT_300f46e0);
    }
    (*(code *)*puVar2)(DAT_300f46e4);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f4690 @ 0x300F4690  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F4690
 * ---------------------------------------------------------------- */
undefined4 FUN_300f4690(void)

{
  code *in_stack_00000008;
  
  (*in_stack_00000008)();
  return 0;
}

/* ----------------------------------------------------------------
 * timexInit @ 0x300F63A8  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrToolsInit
 * Константы: 0x300F63A8
 * ---------------------------------------------------------------- */
void timexInit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f63ac @ 0x300F63AC  (примерный размер ~448 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: cplusDemangle, printf, puts
 * Вызывают: timexShow
 * Константы: 0x300F63AC
 * Данные: DAT_300f6cd4, DAT_300f6cd8, DAT_300f6cdc, DAT_300f6ce0, DAT_300f6ce4, DAT_300f6ce8, DAT_300f6cec, DAT_300f6cf0
 * ---------------------------------------------------------------- */
void FUN_300f63ac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *__format;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_134;
  undefined4 local_130;
  int local_12c;
  undefined1 auStack_128 [260];
  
  iVar4 = 0;
  iVar5 = 0;
  iVar6 = 0;
  do {
    if (DAT_300f6cd4 != *(int *)(param_1 + iVar6)) {
      iVar4 = iVar4 + 1;
      if ((((((code *)*DAT_300f6cd8 == (code *)0x0) || (*DAT_300f6cdc == 0)) || (*DAT_300f6ce0 == 0)
           ) || ((iVar1 = (*(code *)*DAT_300f6cd8)
                                    (*DAT_300f6ce4,0,*(int *)(param_1 + iVar6),0,0,&local_134),
                 iVar1 != 0 || (iVar1 = (*(code *)*DAT_300f6cdc)(local_134,&local_130), iVar1 != 0))
                )) || (iVar1 = (*(code *)*DAT_300f6ce0)(local_134,&local_12c), iVar1 != 0)) {
        printf(DAT_300f6ce8,iVar5,*(undefined4 *)(param_1 + iVar6));
      }
      else {
        iVar1 = *(int *)(param_1 + iVar6) - local_12c;
        uVar2 = cplusDemangle(local_130,auStack_128,DAT_300f6cec);
        if (iVar1 == 0) {
          printf(DAT_300f6cf0,iVar5,uVar2);
        }
        else {
          printf(DAT_300f6cf4,iVar5,uVar2,iVar1);
        }
      }
      iVar1 = 0;
      piVar3 = (int *)(param_1 + iVar6);
      do {
        if (iVar1 != 0) {
          printf(DAT_300f6cf8);
        }
        piVar3 = piVar3 + 1;
        iVar7 = *piVar3;
        if ((iVar7 < -9) || (__format = DAT_300f6cfc, 9 < iVar7)) {
          __format = DAT_300f6d00;
        }
        printf(__format,iVar7);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 8);
      puts(DAT_300f6d04);
    }
    iVar6 = iVar6 + 0x24;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 4);
  if (iVar4 == 0) {
    puts(DAT_300f6d08);
  }
  return;
}

/* ----------------------------------------------------------------
 * timexShow @ 0x300F656C  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 3
 * Вызывает: FUN_300f63ac, printf, puts
 * Вызывают: timexClear, timexFunc, timexPost, timexPre
 * Константы: 0x300F656C
 * Данные: DAT_300f6d0c, DAT_300f6d10, DAT_300f6d14, DAT_300f6d18, DAT_300f6d1c, DAT_300f6d20, DAT_300f6d24
 * ---------------------------------------------------------------- */
void timexShow(void)

{
  printf(DAT_300f6d0c);
  puts(DAT_300f6d10);
  FUN_300f63ac(DAT_300f6d14);
  puts(DAT_300f6d18);
  FUN_300f63ac(DAT_300f6d1c);
  puts(DAT_300f6d20);
  FUN_300f63ac(DAT_300f6d24);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f65ac @ 0x300F65AC  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: bcopy
 * Вызывают: timex, timexClear, timexN
 * Константы: 0x300F65AC
 * Данные: DAT_300f6d14, DAT_300f6d1c, DAT_300f6d24, DAT_300f6d28
 * ---------------------------------------------------------------- */
void FUN_300f65ac(void)

{
  void *__src;
  
  __src = DAT_300f6d28;
  bcopy(DAT_300f6d28,DAT_300f6d14,0x90);
  bcopy(__src,DAT_300f6d1c,0x90);
  bcopy(__src,DAT_300f6d24,0x90);
  return;
}

/* ----------------------------------------------------------------
 * timexClear @ 0x300F65E8  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300f65ac, timexShow
 * Константы: 0x300F65E8
 * ---------------------------------------------------------------- */
void timexClear(void)

{
  FUN_300f65ac();
  timexShow();
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f65f8 @ 0x300F65F8  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: timex, timexFunc, timexN, timexPost, timexPre
 * Константы: 0x300F65F8
 * Данные: DAT_300f6cd4, DAT_300f6d2c
 * ---------------------------------------------------------------- */
void FUN_300f65f8(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11)

{
  if (param_3 == 0) {
    param_3 = DAT_300f6cd4;
  }
  if ((-1 < param_2) && (param_2 < 4)) {
    *(int *)(param_1 + param_2 * 0x24) = param_3;
    param_1 = param_1 + param_2 * 0x24;
    *(undefined4 *)(param_1 + 4) = param_4;
    *(undefined4 *)(param_1 + 8) = param_5;
    *(undefined4 *)(param_1 + 0xc) = param_6;
    *(undefined4 *)(param_1 + 0x10) = param_7;
    *(undefined4 *)(param_1 + 0x14) = param_8;
    *(undefined4 *)(param_1 + 0x18) = param_9;
    *(undefined4 *)(param_1 + 0x1c) = param_10;
    *(undefined4 *)(param_1 + 0x20) = param_11;
    return;
  }
  printf(DAT_300f6d2c,3);
  return;
}

/* ----------------------------------------------------------------
 * timexFunc @ 0x300F6678  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300f65f8, timexShow
 * Константы: 0x300F6678
 * Данные: DAT_300f6d1c
 * ---------------------------------------------------------------- */
void timexFunc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
              undefined4 param_9,undefined4 param_10)

{
  FUN_300f65f8(DAT_300f6d1c,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
               param_10);
  timexShow();
  return;
}

/* ----------------------------------------------------------------
 * timexHelp @ 0x300F66D8  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: puts
 * Константы: 0x300F66D8
 * Данные: DAT_300f6d30, DAT_300f6d34
 * ---------------------------------------------------------------- */
void timexHelp(void)

{
  int *piVar1;
  
  puts(DAT_300f6d30);
  piVar1 = DAT_300f6d34;
  if (*DAT_300f6d34 == 0) {
    return;
  }
  do {
    puts((char *)*piVar1);
    piVar1 = piVar1 + 1;
  } while (*piVar1 != 0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f6710 @ 0x300F6710  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300f687c
 * Константы: 0x300F6710
 * ---------------------------------------------------------------- */
void FUN_300f6710(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 4;
  do {
    (*(code *)*param_1)(param_1[1],param_1[2],param_1[3],param_1[4],param_1[5],param_1[6],param_1[7]
                        ,param_1[8]);
    param_1 = param_1 + 9;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f6770 @ 0x300F6770  (примерный размер ~268 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: __div32, sysClkRateGet
 * Вызывают: FUN_300f687c
 * Константы: 0x300F6770
 * Данные: DAT_300f6d38
 * ---------------------------------------------------------------- */
void FUN_300f6770(int param_1,undefined4 param_2,int *param_3,int *param_4,int *param_5,
                 undefined4 *param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  *param_3 = 0;
  iVar3 = 1;
  uVar1 = sysClkRateGet();
  uVar1 = __div32(param_1,uVar1);
  iVar2 = __div32(uVar1,param_2);
  *param_4 = iVar2;
  while ((*param_3 < 2 && (*param_4 < 100))) {
    iVar3 = iVar3 * 1000;
    *param_3 = *param_3 + 1;
    uVar1 = sysClkRateGet();
    uVar1 = __div32(iVar3 * param_1,uVar1);
    iVar2 = __div32(uVar1,param_2);
    *param_4 = iVar2;
  }
  if ((*param_3 == 2) &&
     (iVar2 = *DAT_300f6d38, iVar4 = *param_4, *param_4 = iVar4 - iVar2, iVar4 - iVar2 < 0)) {
    *param_4 = 0;
  }
  uVar1 = sysClkRateGet();
  uVar1 = __div32(iVar3,uVar1);
  iVar2 = __div32(uVar1,param_2);
  *param_5 = iVar2;
  uVar1 = 100;
  if (*param_4 != 0) {
    uVar1 = __div32(iVar2 * 100,*param_4);
  }
  *param_6 = uVar1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f687c @ 0x300F687C  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_300f6710, FUN_300f6770, tickGet
 * Вызывают: FUN_300f6900, timex
 * Константы: 0x300F687C
 * ---------------------------------------------------------------- */
void FUN_300f687c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  
  FUN_300f6710(param_2);
  iVar1 = tickGet();
  iVar2 = param_1;
  if (0 < param_1) {
    do {
      FUN_300f6710(param_3);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = tickGet();
  FUN_300f6710(param_4);
  FUN_300f6770(iVar2 - iVar1,param_1,param_5,param_6,param_7,param_8);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f6900 @ 0x300F6900  (примерный размер ~180 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: FUN_300f687c, __div32
 * Вызывают: FUN_300f69b4, timexN
 * Константы: 0x300F6900
 * Данные: DAT_300f6d3c
 * ---------------------------------------------------------------- */
void FUN_300f6900(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                 undefined4 param_5,int *param_6,undefined4 param_7,int *param_8)

{
  int iVar1;
  
  iVar1 = 1;
  while( true ) {
    FUN_300f687c(iVar1,param_1,param_2,param_3,param_5,param_6,param_7,param_8);
    if ((*param_8 < 3) || ((DAT_300f6d3c <= iVar1 && (*param_6 < 1)))) break;
    iVar1 = __div32(*param_8 * iVar1,2);
  }
  *param_4 = iVar1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f69b4 @ 0x300F69B4  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_300f6900
 * Вызывают: timex, timexN
 * Константы: 0x300F69B4
 * Данные: DAT_300f6d28, DAT_300f6d38
 * ---------------------------------------------------------------- */
void FUN_300f69b4(void)

{
  undefined4 *puVar1;
  undefined4 local_1c;
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  
  puVar1 = DAT_300f6d38;
  *DAT_300f6d38 = 0;
  FUN_300f6900(DAT_300f6d28,DAT_300f6d28,DAT_300f6d28,auStack_c,auStack_18,&local_1c,auStack_14,
               auStack_10);
  *puVar1 = local_1c;
  return;
}

/* ----------------------------------------------------------------
 * timex @ 0x300F6A18  (примерный размер ~272 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300f65ac, FUN_300f65f8, FUN_300f687c, FUN_300f69b4, printErr
 * Константы: 0x300F6A18
 * Данные: DAT_300f6d14, DAT_300f6d1c, DAT_300f6d24, DAT_300f6d38, DAT_300f6d40, DAT_300f6d44, DAT_300f6d48, DAT_300f6d4c
 * ---------------------------------------------------------------- */
void timex(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 uVar1;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar1 = DAT_300f6d1c;
  if (param_1 != 0) {
    FUN_300f65ac();
    FUN_300f65f8(uVar1,0,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  if (*DAT_300f6d38 == 0) {
    FUN_300f69b4();
  }
  FUN_300f687c(1,DAT_300f6d14,uVar1,DAT_300f6d24,&local_30,&local_2c,&local_28,&local_34);
  if (local_34 < 0x33) {
    printErr(DAT_300f6d54,local_2c,local_28,local_34,*(undefined4 *)(DAT_300f6d50 + local_30 * 4));
  }
  else {
    printErr(DAT_300f6d40);
    printErr(DAT_300f6d44);
    printErr(DAT_300f6d48);
    printErr(DAT_300f6d4c);
  }
  return;
}

/* ----------------------------------------------------------------
 * timexN @ 0x300F6B28  (примерный размер ~232 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300f65ac, FUN_300f65f8, FUN_300f6900, FUN_300f69b4, printErr
 * Константы: 0x300F6B28
 * Данные: DAT_300f6d14, DAT_300f6d1c, DAT_300f6d24, DAT_300f6d38, DAT_300f6d50, DAT_300f6d58
 * ---------------------------------------------------------------- */
void timexN(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
           undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 uVar1;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar1 = DAT_300f6d1c;
  if (param_1 != 0) {
    FUN_300f65ac();
    FUN_300f65f8(uVar1,0,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  if (*DAT_300f6d38 == 0) {
    FUN_300f69b4();
  }
  FUN_300f6900(DAT_300f6d14,uVar1,DAT_300f6d24,&local_2c,&local_38,&local_34,&local_30,&local_28);
  printErr(DAT_300f6d58,local_2c,local_34,local_30,local_28,
           *(undefined4 *)(DAT_300f6d50 + local_38 * 4));
  return;
}

/* ----------------------------------------------------------------
 * timexPost @ 0x300F6C10  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300f65f8, timexShow
 * Константы: 0x300F6C10
 * Данные: DAT_300f6d24
 * ---------------------------------------------------------------- */
void timexPost(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
              undefined4 param_9,undefined4 param_10)

{
  FUN_300f65f8(DAT_300f6d24,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
               param_10);
  timexShow();
  return;
}

/* ----------------------------------------------------------------
 * timexPre @ 0x300F6C70  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300f65f8, timexShow
 * Константы: 0x300F6C70
 * Данные: DAT_300f6d14
 * ---------------------------------------------------------------- */
void timexPre(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
             undefined4 param_9,undefined4 param_10)

{
  FUN_300f65f8(DAT_300f6d14,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
               param_10);
  timexShow();
  return;
}

/* ----------------------------------------------------------------
 * tipLibInit @ 0x300F6D5C  (примерный размер ~328 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: fdprintf, lstInit, semMCreate, strdup
 * Вызывают: usrTipInit
 * Константы: 0x300F6D5C
 * Данные: DAT_300f7cd0, DAT_300f7cd4, DAT_300f7cd8, DAT_300f7cdc, DAT_300f7ce0, DAT_300f7ce4, DAT_300f7ce8, DAT_300f7cec
 * ---------------------------------------------------------------- */
void tipLibInit(char *param_1,char *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  iVar5 = DAT_300f7cd4;
  iVar1 = DAT_300f7cd0;
  if (*(int *)(DAT_300f7cd0 + 0xc) == 0) {
    lstInit(DAT_300f7cd4);
    iVar2 = DAT_300f7cd8;
    lstInit(DAT_300f7cd8);
    iVar4 = semMCreate(4);
    *(int *)(iVar5 + 0xc) = iVar4;
    if (iVar4 == 0) {
      fdprintf(2,DAT_300f7cdc,DAT_300f7ce0);
    }
    else {
      iVar5 = semMCreate(4);
      *(int *)(iVar2 + 0xc) = iVar5;
      if (iVar5 == 0) {
        fdprintf(2,DAT_300f7cdc,DAT_300f7ce4);
      }
      else {
        if (param_1 != (char *)0x0) {
          pcVar6 = strdup(param_1);
          *DAT_300f7ce8 = pcVar6;
          if (pcVar6 == (char *)0x0) {
            fdprintf(2,DAT_300f7cec,DAT_300f7cf0);
            return;
          }
        }
        if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
          *DAT_300f7cf4 = *param_2;
        }
        *DAT_300f7cfc = DAT_300f7cf8;
        puVar3 = DAT_300f7d00;
        *DAT_300f7d00 = *param_3;
        puVar3[1] = param_3[1];
        puVar3[2] = param_3[2];
        puVar3[3] = param_3[3];
        puVar3[5] = param_3[5];
        puVar3[4] = param_3[4];
        puVar3[6] = param_3[6];
        puVar3[7] = param_3[7];
        puVar3[8] = param_3[8];
        *(undefined4 *)(iVar1 + 0xc) = 1;
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f6ea4 @ 0x300F6EA4  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 4
 * Вызывает: errnoGet, errnoSet, fdprintf, write
 * Вызывают: FUN_300f6f30, FUN_300f7094, FUN_300f72a4
 * Константы: 0xFFFFFFFF, 0x300F6EA4
 * Данные: DAT_300f7e28
 * ---------------------------------------------------------------- */
undefined4 FUN_300f6ea4(int param_1,void *param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = errnoGet();
  errnoSet(0);
  while( true ) {
    while (uVar2 = write(param_1,param_2,param_3), uVar2 == 0xffffffff) {
      iVar3 = errnoGet();
      if (iVar3 != 4) {
        fdprintf(2,DAT_300f7e28,param_4);
        return 0xffffffff;
      }
    }
    if (param_3 <= uVar2) break;
    param_2 = (void *)((int)param_2 + uVar2);
    param_3 = param_3 - uVar2;
  }
  errnoSet(uVar1);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f6f30 @ 0x300F6F30  (примерный размер ~356 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300f6ea4, memchr, read, strlen
 * Вызывают: FUN_300f720c
 * Константы: 0xFFFFFFFF, 0x300F6F30
 * Данные: DAT_300f7ed0, DAT_300f7ed4
 * ---------------------------------------------------------------- */
undefined4 FUN_300f6f30(int param_1,int param_2)

{
  size_t __n;
  size_t sVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  void *__s;
  
  __n = read(*(int *)(param_2 + 8),*(void **)(param_2 + 0x18),*(size_t *)(param_2 + 0x20));
  if ((int)__n < 1) {
    return 0xffffffff;
  }
  __s = *(void **)(param_2 + 0x18);
  if (*(int *)(param_2 + 0x34) != 0) {
    pcVar5 = *(char **)(param_2 + 0x10);
    sVar1 = strlen(pcVar5);
    iVar2 = FUN_300f6ea4(1,pcVar5,sVar1,DAT_300f7ed0);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(param_2 + 0x34) = 0;
  }
  while( true ) {
    pvVar3 = memchr(__s,10,__n);
    if (pvVar3 == (void *)0x0) {
      iVar2 = FUN_300f6ea4(1,__s,__n,DAT_300f7ed0);
      if (iVar2 == 0) {
        return 0;
      }
      return 0xffffffff;
    }
    iVar4 = (int)pvVar3 + (1 - (int)__s);
    iVar2 = FUN_300f6ea4(1,__s,iVar4,DAT_300f7ed0);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0x24) != 0) {
      pcVar5 = (char *)*DAT_300f7ed4;
      sVar1 = strlen(pcVar5);
      iVar2 = FUN_300f6ea4(1,pcVar5,sVar1,DAT_300f7ed0);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
    pcVar5 = *(char **)(param_2 + 0x10);
    sVar1 = strlen(pcVar5);
    iVar2 = FUN_300f6ea4(1,pcVar5,sVar1,DAT_300f7ed0);
    if (iVar2 != 0) break;
    __s = (void *)((int)pvVar3 + 1);
    __n = __n - iVar4;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300f7094 @ 0x300F7094  (примерный размер ~376 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_300f6ea4, fdprintf, memchr, memmove, read, realloc, strlen
 * Вызывают: FUN_300f720c
 * Константы: 0xFFFFFFFF, 0x300F7094
 * Данные: DAT_300f7ed0, DAT_300f7ed4, DAT_300f813c
 * ---------------------------------------------------------------- */
undefined4 FUN_300f7094(int param_1,int param_2)

{
  ssize_t sVar1;
  size_t sVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  size_t sVar7;
  
  sVar1 = read(*(int *)(param_2 + 8),(void *)(*(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x1c)),
               *(int *)(param_2 + 0x20) - *(int *)(param_2 + 0x1c));
  if (sVar1 < 1) {
    return 0xffffffff;
  }
  sVar7 = sVar1 + *(int *)(param_2 + 0x1c);
  *(size_t *)(param_2 + 0x1c) = sVar7;
  while( true ) {
    pvVar4 = memchr(*(void **)(param_2 + 0x18),10,sVar7);
    if (pvVar4 == (void *)0x0) {
      if (*(int *)(param_2 + 0x1c) == *(int *)(param_2 + 0x20)) {
        sVar7 = *(int *)(param_2 + 0x20) << 1;
        pvVar4 = realloc(*(void **)(param_2 + 0x18),sVar7);
        *(void **)(param_2 + 0x18) = pvVar4;
        if (pvVar4 == (void *)0x0) {
          fdprintf(2,DAT_300f813c);
          return 0xffffffff;
        }
        *(size_t *)(param_2 + 0x20) = sVar7;
      }
      return 0;
    }
    pcVar6 = *(char **)(param_2 + 0x10);
    iVar5 = (int)pvVar4 + (1 - *(int *)(param_2 + 0x18));
    sVar2 = strlen(pcVar6);
    iVar3 = FUN_300f6ea4(1,pcVar6,sVar2,DAT_300f7ed0);
    if (iVar3 != 0) {
      return 0xffffffff;
    }
    iVar3 = FUN_300f6ea4(1,*(undefined4 *)(param_2 + 0x18),iVar5,DAT_300f7ed0);
    if (iVar3 != 0) break;
    if (*(int *)(param_1 + 0x24) != 0) {
      pcVar6 = (char *)*DAT_300f7ed4;
      sVar2 = strlen(pcVar6);
      iVar3 = FUN_300f6ea4(1,pcVar6,sVar2,DAT_300f7ed0);
      if (iVar3 != 0) {
        return 0xffffffff;
      }
    }
    sVar7 = sVar7 - iVar5;
    memmove(*(void **)(param_2 + 0x18),(void *)((int)pvVar4 + 1),sVar7);
    *(size_t *)(param_2 + 0x1c) = sVar7;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300f720c @ 0x300F720C  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300f6f30, FUN_300f7094, strlen
 * Вызывают: tipStart
 * Константы: 0x300F720C
 * ---------------------------------------------------------------- */
void FUN_300f720c(undefined4 param_1,int param_2)

{
  size_t sVar1;
  
  if (((*(uint *)(param_2 + 0x2c) & 4) == 0) &&
     (sVar1 = strlen(*(char **)(param_2 + 0x10)), sVar1 != 0)) {
    FUN_300f7094(param_1,param_2);
  }
  else {
    FUN_300f6f30(param_1,param_2);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f7254 @ 0x300F7254  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: fdprintf
 * Вызывают: FUN_300f72a4
 * Константы: 0x300F7254, 0xFFFFFFFF
 * Данные: DAT_300f8140, DAT_300f8144
 * ---------------------------------------------------------------- */
undefined4 FUN_300f7254(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = 4;
  pbVar3 = DAT_300f8140;
  do {
    if (*pbVar3 == param_3) {
      uVar1 = (**(code **)(pbVar3 + 8))();
      return uVar1;
    }
    pbVar3 = pbVar3 + 0xc;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  fdprintf(2,DAT_300f8144);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300f72a4 @ 0x300F72A4  (примерный размер ~596 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_300f6ea4, FUN_300f7254, __stdout, __swbuf, fdprintf, fflush, read
 * Вызывают: tipStart
 * Константы: 0xFFFFFFFF, 0x300F72A4
 * Данные: DAT_300f7cd0, DAT_300f7cf4, DAT_300f8230, DAT_300f8234, DAT_300f83c0, DAT_300f83c4, DAT_300f83c8
 * ---------------------------------------------------------------- */
undefined4 FUN_300f72a4(int param_1,int param_2)

{
  ssize_t sVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  char local_18 [4];
  char *local_14;
  char *local_10;
  
  sVar1 = read(0,local_18,1);
  if (sVar1 != 1) {
    fdprintf(2,DAT_300f8230);
    return 0xffffffff;
  }
  if (*DAT_300f7cf4 != local_18[0]) {
LAB_300f7444:
    local_14 = DAT_300f7cd0;
    if (*(int *)(DAT_300f7cd0 + 8) == 1) {
      if (*(int *)(param_2 + 0x24) == 0) {
        fdprintf(1,DAT_300f83c4,local_18[0]);
      }
      else {
        fdprintf(1,DAT_300f83c0,*(undefined4 *)(DAT_300f7cd0 + 4));
      }
      FUN_300f7254(param_1,param_2 + 0x10,local_18[0]);
      *local_14 = '\0';
      local_14[8] = '\0';
      local_14[9] = '\0';
      local_14[10] = '\0';
      local_14[0xb] = '\0';
    }
    else if ((*(uint *)(param_1 + 0x2c) & 0xc) == 4) {
      iVar4 = FUN_300f6ea4(*(undefined4 *)(param_1 + 8),local_18,1,DAT_300f83c8);
      if (iVar4 != 0) {
        return 0xffffffff;
      }
      *local_14 = local_18[0];
    }
    return 0;
  }
  local_10 = DAT_300f7cd0;
  if ((*DAT_300f7cd0 != '\n') && (*DAT_300f7cd0 != '\0')) goto LAB_300f7444;
  if (*(int *)(param_2 + 0x24) != 0) {
    fdprintf(1,DAT_300f8234,*(undefined4 *)(DAT_300f7cd0 + 4));
  }
  piVar2 = (int *)__stdout();
  iVar4 = *(int *)(*piVar2 + 4);
  piVar2 = (int *)__stdout();
  if ((*piVar2 != iVar4) || (piVar2 = (int *)__stdout(), *(char *)(*piVar2 + 10) != 'f'))
  goto LAB_300f741c;
  piVar2 = (int *)__stdout();
  iVar4 = *(int *)(*piVar2 + 0x14) + -1;
  *(int *)(*piVar2 + 0x14) = iVar4;
  if (iVar4 < 0) {
    piVar2 = (int *)__stdout();
    iVar4 = *(int *)(*piVar2 + 0x14);
    piVar2 = (int *)__stdout();
    if (iVar4 < *(int *)(*piVar2 + 0x24)) {
      puVar3 = (undefined4 *)__stdout();
      __swbuf(local_18[0],*puVar3);
      goto LAB_300f741c;
    }
    piVar2 = (int *)__stdout();
    **(char **)(*piVar2 + 0xc) = local_18[0];
    piVar2 = (int *)__stdout();
    if (**(char **)(*piVar2 + 0xc) == '\n') {
      puVar3 = (undefined4 *)__stdout();
      __swbuf(10,*puVar3);
      goto LAB_300f741c;
    }
  }
  else {
    piVar2 = (int *)__stdout();
    **(char **)(*piVar2 + 0xc) = local_18[0];
  }
  piVar2 = (int *)__stdout();
  *(int *)(*piVar2 + 0xc) = *(int *)(*piVar2 + 0xc) + 1;
LAB_300f741c:
  puVar3 = (undefined4 *)__stdout();
  fflush((FILE *)*puVar3);
  *local_10 = local_18[0];
  local_10[8] = '\x01';
  local_10[9] = '\0';
  local_10[10] = '\0';
  local_10[0xb] = '\0';
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f74f8 @ 0x300F74F8  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: fdprintf, ioctl
 * Вызывают: FUN_300f7564
 * Константы: 0x300F74F8
 * Данные: DAT_300f7d00, DAT_300f83cc
 * ---------------------------------------------------------------- */
void FUN_300f74f8(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xc) != -1) && (iVar1 = ioctl(0,3), iVar1 == -1)) {
    fdprintf(2,DAT_300f83cc);
  }
  if ((*(int *)(param_1 + 0x20) != 0) && (*(code **)(DAT_300f7d00 + 4) != (code *)0x0)) {
    (**(code **)(DAT_300f7d00 + 4))(*(undefined4 *)(param_1 + 0x1c));
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f7564 @ 0x300F7564  (примерный размер ~480 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 13
 * Вызывает: FUN_300f74f8, close, fdprintf, free, lstCount, lstDelete, lstFirst, lstFree, lstNext, semGive, semTake, strcmp, taskDeleteHookDelete
 * Вызывают: tipStart
 * Константы: 0xFFFFFFFF, 0x300F7564
 * Данные: DAT_300f7cd4, DAT_300f7cd8, DAT_300f7ed4, DAT_300f8234, DAT_300f851c, DAT_300f8628, DAT_300f862c, DAT_300f8630
 * ---------------------------------------------------------------- */
void FUN_300f7564(void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)((int)param_1 + 0x24) != 0) {
    fdprintf(1,DAT_300f8234,*DAT_300f7ed4);
  }
  iVar2 = lstFirst((int)param_1 + 0x10);
  iVar1 = DAT_300f7cd4;
  do {
    if (iVar2 == 0) {
      lstFree((int)param_1 + 0x10);
      if (param_2 != 0) {
        FUN_300f74f8(param_1);
      }
      iVar1 = DAT_300f7cd8;
      semTake(*(undefined4 *)(DAT_300f7cd8 + 0xc),0xffffffff);
      iVar2 = lstCount(iVar1);
      if ((iVar2 == 1) && (iVar2 = taskDeleteHookDelete(DAT_300f8628), iVar2 != 0)) {
        fdprintf(2,DAT_300f862c,DAT_300f8630);
      }
      lstDelete(iVar1,param_1);
      semGive(*(undefined4 *)(iVar1 + 0xc));
      free(param_1);
      return;
    }
    if ((*(int *)(iVar2 + 8) != -1) && ((*(uint *)(iVar2 + 0x2c) & 8) == 0)) {
      close(*(int *)(iVar2 + 8));
      fdprintf(1,DAT_300f851c,*(undefined4 *)(iVar2 + 0x14));
    }
    semTake(*(undefined4 *)(iVar1 + 0xc),0xffffffff);
    for (iVar3 = lstFirst(iVar1); iVar3 != 0; iVar3 = lstNext(iVar3)) {
      iVar4 = strcmp((char *)(iVar3 + 8),*(char **)(iVar2 + 0xc));
      if (iVar4 == 0) {
        lstDelete(iVar1,iVar3);
        break;
      }
    }
    semGive(*(undefined4 *)(iVar1 + 0xc));
    free(*(void **)(iVar2 + 0xc));
    free(*(void **)(iVar2 + 0x10));
    if (*(void **)(iVar2 + 0xc) != *(void **)(iVar2 + 0x14)) {
      free(*(void **)(iVar2 + 0x14));
    }
    free(*(void **)(iVar2 + 0x18));
    iVar2 = lstNext(iVar2);
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300f7744 @ 0x300F7744  (примерный размер ~536 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: calloc, fdprintf, free, malloc, sprintf, strcpy, strlen, strncmp
 * Вызывают: FUN_300f7f08
 * Константы: 0x300F7744, 0xFFFFFFFF
 * Данные: DAT_300f7d00, DAT_300f8634, DAT_300f8638, DAT_300f863c, DAT_300f873c, DAT_300f8740, DAT_300f8744, DAT_300f8748
 * ---------------------------------------------------------------- */
void * FUN_300f7744(char *param_1,char *param_2,char *param_3,undefined4 param_4)

{
  void *__ptr;
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  void *pvVar4;
  size_t sVar5;
  char *__s;
  undefined4 uVar6;
  
  __ptr = calloc(1,0x38);
  if (__ptr == (void *)0x0) {
    fdprintf(2,DAT_300f8634,DAT_300f8638);
    return (void *)0x0;
  }
  *(undefined4 *)((int)__ptr + 8) = 0xffffffff;
  *(undefined4 *)((int)__ptr + 0x30) = 0;
  *(undefined4 *)((int)__ptr + 0x24) = param_4;
  *(undefined4 *)((int)__ptr + 0x1c) = 0;
  *(undefined4 *)((int)__ptr + 0x34) = 1;
  iVar1 = strncmp(param_1,DAT_300f863c,4);
  if (iVar1 == 0) {
    if (*(int *)(DAT_300f7d00 + 0x18) == 0) {
      fdprintf(2,DAT_300f873c,param_1);
      goto LAB_300f791c;
    }
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  *(undefined4 *)((int)__ptr + 0x28) = uVar6;
  sVar2 = strlen(param_1);
  pcVar3 = (char *)malloc(sVar2 + 1);
  *(char **)((int)__ptr + 0xc) = pcVar3;
  if (pcVar3 == (char *)0x0) {
    fdprintf(2,DAT_300f8634,DAT_300f8740);
  }
  else {
    strcpy(pcVar3,param_1);
    pvVar4 = calloc(1,0x400);
    *(void **)((int)__ptr + 0x18) = pvVar4;
    if (pvVar4 == (void *)0x0) {
      fdprintf(2,DAT_300f8634,DAT_300f8744);
    }
    else {
      *(undefined4 *)((int)__ptr + 0x20) = 0x400;
      if (param_2 != (char *)0x0) {
        sVar2 = strlen(param_2);
        pcVar3 = (char *)malloc(sVar2 + 1);
        *(char **)((int)__ptr + 0x10) = pcVar3;
        if (pcVar3 == (char *)0x0) {
          fdprintf(2,DAT_300f8634,DAT_300f8748);
          goto LAB_300f7914;
        }
        strcpy(pcVar3,param_2);
      }
      if (param_3 == (char *)0x0) {
        *(undefined4 *)((int)__ptr + 0x14) = *(undefined4 *)((int)__ptr + 0xc);
        return __ptr;
      }
      sVar2 = strlen(param_3);
      __s = *(char **)((int)__ptr + 0xc);
      sVar5 = strlen(__s);
      pcVar3 = (char *)malloc(sVar5 + sVar2 + 4);
      *(char **)((int)__ptr + 0x14) = pcVar3;
      if (pcVar3 != (char *)0x0) {
        sprintf(pcVar3,DAT_300f87f8,param_3,__s);
        return __ptr;
      }
      fdprintf(2,DAT_300f8634,DAT_300f874c);
    }
  }
LAB_300f7914:
  if (__ptr == (void *)0x0) {
    return (void *)0x0;
  }
LAB_300f791c:
  free(*(void **)((int)__ptr + 0x10));
  free(*(void **)((int)__ptr + 0xc));
  if (*(void **)((int)__ptr + 0xc) != *(void **)((int)__ptr + 0x14)) {
    free(*(void **)((int)__ptr + 0x14));
  }
  free(*(void **)((int)__ptr + 0x18));
  free(__ptr);
  return (void *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_300f795c @ 0x300F795C  (примерный размер ~364 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: memcmp, memmove, strchr, strcpy, strlen
 * Вызывают: FUN_300f7f08
 * Константы: 0x300F795C
 * Данные: DAT_300f8944, DAT_300f8948, DAT_300f894c, DAT_300f8950, DAT_300f8954, DAT_300f8958, DAT_300f895c, DAT_300f8960
 * ---------------------------------------------------------------- */
void FUN_300f795c(char *param_1,uint param_2)

{
  bool bVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  
  bVar1 = false;
  if (param_1 == (char *)0x0) {
    return;
  }
  pcVar2 = strchr(param_1,0x5c);
  if (pcVar2 != (char *)0x0) {
    do {
      if ((pcVar2[1] != 'e') && (pcVar2[1] != 'E')) break;
      bVar1 = true;
      *pcVar2 = '\x1b';
      sVar3 = strlen(param_1);
      memmove(pcVar2 + 1,pcVar2 + 2,(size_t)(param_1 + (sVar3 - (int)pcVar2) + 2));
      pcVar2 = strchr(param_1,0x5c);
    } while (pcVar2 != (char *)0x0);
    if (bVar1) {
      return;
    }
  }
  iVar4 = memcmp(param_1,DAT_300f8944,4);
  pcVar2 = DAT_300f8948;
  if ((((iVar4 != 0) && (iVar4 = memcmp(param_1,DAT_300f894c,6), pcVar2 = DAT_300f8950, iVar4 != 0))
      && (iVar4 = memcmp(param_1,DAT_300f8954,7), pcVar2 = DAT_300f8958, iVar4 != 0)) &&
     (((iVar4 = memcmp(param_1,DAT_300f895c,5), pcVar2 = DAT_300f8960, iVar4 != 0 &&
       (iVar4 = memcmp(param_1,DAT_300f8964,8), pcVar2 = DAT_300f8968, iVar4 != 0)) &&
      (iVar4 = memcmp(param_1,DAT_300f896c,5), pcVar2 = DAT_300f8970, iVar4 != 0)))) {
    return;
  }
  sVar3 = strlen(pcVar2);
  if (sVar3 <= param_2) {
    strcpy(param_1,pcVar2);
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f7ac8 @ 0x300F7AC8  (примерный размер ~344 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: strchr, strcpy, strlen, strstr, strtol
 * Вызывают: FUN_300f7f08
 * Константы: 0xFFFFFFFF, 0x300F7AC8
 * Данные: DAT_300f8a10
 * ---------------------------------------------------------------- */
undefined4 FUN_300f7ac8(char *param_1,char *param_2,long *param_3,char *param_4,uint param_5)

{
  undefined4 uVar1;
  char *pcVar2;
  size_t sVar3;
  char *pcVar4;
  long lVar5;
  char cVar6;
  char *local_24;
  
  cVar6 = '\0';
  if (((param_4 == (char *)0x0) || (param_3 == (long *)0x0)) && (param_2 != (char *)0x0)) {
    pcVar2 = param_1;
    if (param_1 == (char *)0x0) {
      uVar1 = 0;
    }
    else {
      while (pcVar2 = strstr(pcVar2,param_2), pcVar2 != (char *)0x0) {
        if (((pcVar2 == param_1) || ((byte)pcVar2[-1] == 0x23)) ||
           ((*(byte *)(*DAT_300f8a10 + (uint)(byte)pcVar2[-1]) & 0x28) != 0)) {
          sVar3 = strlen(param_2);
          pcVar2 = pcVar2 + sVar3;
          pcVar4 = strchr(pcVar2,0x23);
          if (pcVar4 != (char *)0x0) {
            cVar6 = *pcVar4;
            *pcVar4 = '\0';
          }
          if (param_4 == (char *)0x0) {
            if (((param_3 == (long *)0x0) ||
                ((lVar5 = strtol(pcVar2,&local_24,0), lVar5 == 0 && (local_24 == pcVar2)))) ||
               (*local_24 != '\0')) {
              uVar1 = 0xffffffff;
            }
            else {
              *param_3 = lVar5;
              uVar1 = 1;
            }
          }
          else {
            sVar3 = strlen(pcVar2);
            if (param_5 < sVar3 + 1) {
              return 0xffffffff;
            }
            strcpy(param_4,pcVar2);
            uVar1 = 1;
          }
          if (cVar6 == '\0') {
            return uVar1;
          }
          *pcVar4 = cVar6;
          return uVar1;
        }
        pcVar2 = pcVar2 + 1;
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300f7c20 @ 0x300F7C20  (примерный размер ~256 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: memmove, strchr, strlen, strstr
 * Вызывают: FUN_300f7f08
 * Константы: 0x300F7C20
 * Данные: DAT_300f8a10
 * ---------------------------------------------------------------- */
void FUN_300f7c20(char *param_1,char *param_2)

{
  size_t sVar1;
  char *__s;
  char *pcVar2;
  int iVar3;
  
  if (param_1 == (char *)0x0) {
    return;
  }
  sVar1 = strlen(param_1);
  __s = strstr(param_1,param_2);
  if (__s == (char *)0x0) {
    return;
  }
  iVar3 = *DAT_300f8a10;
  while (((__s != param_1 && ((byte)__s[-1] != 0x23)) &&
         ((*(byte *)(iVar3 + (uint)(byte)__s[-1]) & 0x28) == 0))) {
    __s = strstr(__s + 1,param_2);
    if (__s == (char *)0x0) {
      return;
    }
  }
  pcVar2 = strchr(__s,0x23);
  if (pcVar2 != (char *)0x0) {
    memmove(__s,pcVar2 + 1,(size_t)(param_1 + ((sVar1 + 1) - (int)(pcVar2 + 1))));
    return;
  }
  if (__s == param_1) {
    *__s = '\0';
    return;
  }
  __s[-1] = '\0';
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f7d20 @ 0x300F7D20  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: strchr, strcmp, strtok
 * Вызывают: FUN_300f7dbc
 * Константы: 0x300F7D20
 * Данные: DAT_300f8c44
 * ---------------------------------------------------------------- */
char * FUN_300f7d20(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar1 = strchr(param_1,0x23);
  if (pcVar1 == (char *)0x0) {
    return (char *)0x0;
  }
  *pcVar1 = '\0';
  pcVar2 = strtok(param_1,DAT_300f8c44);
  if (pcVar2 != (char *)0x0) {
    iVar3 = strcmp(pcVar2,param_2);
    while( true ) {
      if (iVar3 == 0) {
        return pcVar1 + 1;
      }
      pcVar2 = strtok((char *)0x0,DAT_300f8c44);
      if (pcVar2 == (char *)0x0) break;
      iVar3 = strcmp(pcVar2,param_2);
    }
  }
  return (char *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_300f7dbc @ 0x300F7DBC  (примерный размер ~332 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_300f7d20, fdprintf, free, strchr, strcpy, strdup, strlen
 * Вызывают: FUN_300f7f08
 * Константы: 0x300F7DBC, 0xFFFFFFFF
 * Данные: DAT_300f8c48, DAT_300f8d64, DAT_300f8d68
 * ---------------------------------------------------------------- */
undefined4 FUN_300f7dbc(char *param_1,char *param_2,uint param_3)

{
  bool bVar1;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  
  pcVar5 = (char *)*DAT_300f8c48;
  bVar1 = false;
  if ((((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) && (param_1 != (char *)0x0)) &&
     (*param_1 != '\0')) {
    pcVar5 = strdup(pcVar5);
    if (pcVar5 == (char *)0x0) {
      fdprintf(2,DAT_300f8d64,DAT_300f8d68);
    }
    else {
      uVar6 = 0;
      sVar2 = strlen(pcVar5);
      if (sVar2 != 0) {
        pcVar4 = pcVar5 + -1;
        do {
          pcVar4 = pcVar4 + 1;
          if (*pcVar4 == '\n') {
            *pcVar4 = '|';
          }
          uVar6 = uVar6 + 1;
          sVar2 = strlen(pcVar5);
        } while (uVar6 < sVar2);
      }
      pcVar4 = pcVar5;
      if (pcVar5 != (char *)0x0) {
        while( true ) {
          pcVar3 = strchr(pcVar4,0x7c);
          if (pcVar3 != (char *)0x0) {
            *pcVar3 = '\0';
          }
          pcVar4 = (char *)FUN_300f7d20(pcVar4,param_1);
          if ((pcVar4 != (char *)0x0) && (sVar2 = strlen(pcVar4), sVar2 <= param_3)) break;
          if ((pcVar3 == (char *)0x0) || (pcVar4 = pcVar3 + 1, pcVar4 == (char *)0x0))
          goto LAB_300f7ee8;
        }
        bVar1 = true;
        strcpy(param_2,pcVar4);
      }
LAB_300f7ee8:
      free(pcVar5);
      if (bVar1) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300f7f08 @ 0x300F7F08  (примерный размер ~452 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 11
 * Вызывает: FUN_300f7744, FUN_300f795c, FUN_300f7ac8, FUN_300f7c20, FUN_300f7dbc, fdprintf, free, lstAdd, strchr, strdup, strlen
 * Вызывают: tipStart
 * Константы: 0x300F7F08, 0xFFFFFFFF, 0xFFFFFFFC
 * Данные: DAT_300f8d64, DAT_300f8e20, DAT_300f8e24, DAT_300f8e28, DAT_300f8e2c, DAT_300f8e30, DAT_300f8f0c
 * ---------------------------------------------------------------- */
undefined4 FUN_300f7f08(int param_1,char *param_2,uint param_3)

{
  int iVar1;
  char *__ptr;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  size_t sVar6;
  undefined4 uVar7;
  int iVar8;
  char *__s;
  
  iVar1 = -DAT_300f8e20;
  iVar8 = 0;
  if (param_2 != (char *)0x0) {
    do {
      __ptr = strdup(param_2);
      if (__ptr == (char *)0x0) {
        fdprintf(2,DAT_300f8d64,DAT_300f8e24);
        return 0xffffffff;
      }
      iVar2 = FUN_300f7dbc(__ptr,&stack0x0000004c + iVar1,0x400);
      __s = __ptr;
      if (iVar2 == 0) {
        __s = &stack0x0000004c + iVar1;
      }
      *(undefined4 *)(&stack0xffffffe0 + iVar1) = 0x32;
      iVar3 = FUN_300f7ac8(__s,DAT_300f8e28,0,&stack0x00000018 + iVar1);
      if (iVar3 == 0 || iVar3 == -1) {
        uVar4 = 2;
        uVar7 = DAT_300f8e2c;
LAB_300f8090:
        fdprintf(uVar4,uVar7,__s);
      }
      else {
        FUN_300f7c20(__s,DAT_300f8e28);
        *(undefined4 *)(&stack0xffffffe0 + iVar1) = 0x32;
        iVar3 = FUN_300f7ac8(__s,DAT_300f8e30,0,&stack0xffffffe4 + iVar1);
        if (iVar3 == 0 || iVar3 == -1) {
          (&stack0xffffffe4)[iVar1] = 0;
        }
        else {
          FUN_300f795c(&stack0xffffffe4 + iVar1,0x32);
          FUN_300f7c20(__s,DAT_300f8e30);
          pcVar5 = strchr(&stack0xffffffe4 + iVar1,0x1b);
          if ((pcVar5 != (char *)0x0) && (*(int *)(param_1 + 0x24) == 0)) {
            *(undefined4 *)(param_1 + 0x24) = 1;
          }
        }
        pcVar5 = (char *)0x0;
        if (iVar2 == 0) {
          pcVar5 = __ptr;
        }
        iVar3 = iVar8 + 1;
        iVar2 = FUN_300f7744(&stack0x00000018 + iVar1,&stack0xffffffe4 + iVar1,pcVar5,iVar3);
        if (iVar2 != 0) {
          lstAdd(param_1 + 0x10,iVar2);
          sVar6 = strlen(__s);
          iVar8 = iVar3;
          if (sVar6 != 0) {
            uVar4 = 1;
            uVar7 = DAT_300f8f0c;
            goto LAB_300f8090;
          }
        }
      }
      free(__ptr);
      param_3 = param_3 + 7 & 0xfffffffc;
      param_2 = *(char **)(param_3 - 4);
    } while (param_2 != (char *)0x0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f80cc @ 0x300F80CC  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: fdprintf, lstInit, malloc, taskIdSelf
 * Вызывают: tipStart
 * Константы: 0x300F80CC, 0xFFFFFFFF
 * Данные: DAT_300f8634, DAT_300f8f10, DAT_300f8f14
 * ---------------------------------------------------------------- */
void * FUN_300f80cc(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = malloc(0x28);
  if (pvVar1 == (void *)0x0) {
    fdprintf(2,DAT_300f8634,DAT_300f8f10);
    pvVar1 = (void *)0x0;
  }
  else {
    lstInit((int)pvVar1 + 0x10);
    *(undefined4 *)((int)pvVar1 + 0xc) = 0xffffffff;
    uVar2 = taskIdSelf();
    *(undefined4 *)((int)pvVar1 + 8) = uVar2;
    if ((code *)*DAT_300f8f14 == (code *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (*(code *)*DAT_300f8f14)(0);
    }
    *(undefined4 *)((int)pvVar1 + 0x1c) = uVar2;
    *(undefined4 *)((int)pvVar1 + 0x20) = 0;
    *(undefined4 *)((int)pvVar1 + 0x24) = 0;
  }
  return pvVar1;
}

/* ----------------------------------------------------------------
 * FUN_300f8168 @ 0x300F8168  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: fdprintf, open
 * Вызывают: FUN_300f8454
 * Константы: 0x300F8168, 0xFFFFFFFF
 * Данные: DAT_300f8f18
 * ---------------------------------------------------------------- */
undefined4 FUN_300f8168(int param_1)

{
  int iVar1;
  
  iVar1 = open(*(char **)(param_1 + 0xc),2,0);
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 == -1) {
    fdprintf(2,DAT_300f8f18,*(undefined4 *)(param_1 + 0xc));
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f81ac @ 0x300F81AC  (примерный размер ~680 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 9
 * Вызывает: close, errnoGet, fdprintf, free, memset, strdup, strerror, strtok, strtol
 * Вызывают: FUN_300f8454
 * Константы: 0x300F81AC, 0xFFFFFFFF
 * Данные: DAT_300f8d64, DAT_300f8f14, DAT_300f8f1c, DAT_300f8f20, DAT_300f8f24, DAT_300f8f28, DAT_300f8f2c, DAT_300f8f30
 * ---------------------------------------------------------------- */
undefined4 FUN_300f81ac(int param_1)

{
  char *__s;
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 uStack_28;
  undefined1 local_27;
  ushort local_26;
  int local_24;
  
  __s = strdup(*(char **)(param_1 + 0xc));
  if (__s == (char *)0x0) {
    fdprintf(2,DAT_300f8d64,DAT_300f8f1c);
  }
  else {
    strtok(__s,DAT_300f8f20);
    pcVar1 = strtok((char *)0x0,DAT_300f8f20);
    pcVar2 = strtok((char *)0x0,DAT_300f8f20);
    if ((pcVar1 == (char *)0x0) || (pcVar2 == (char *)0x0)) {
      fdprintf(2,DAT_300f8f24,*(undefined4 *)(param_1 + 0xc));
    }
    else {
      uVar3 = strtol(pcVar2,&local_38,0);
      if (((uVar3 == 0) && (local_38 == pcVar2)) || (*local_38 != '\0')) {
        fdprintf(2,DAT_300f8f28,pcVar2);
      }
      else {
        memset(&uStack_28,0,0x10);
        iVar5 = DAT_300f8f14;
        if ((*(code **)(DAT_300f8f14 + 0xc) == (code *)0x0) ||
           (iVar4 = (**(code **)(DAT_300f8f14 + 0xc))(pcVar1), iVar4 == 0)) {
          iVar4 = (**(code **)(iVar5 + 0x10))(pcVar1);
          if (iVar4 == -1) {
            iVar5 = errnoGet();
            pcVar2 = strerror(iVar5);
            fdprintf(2,DAT_300f8f2c,pcVar1,pcVar2);
            goto LAB_300f8440;
          }
        }
        else {
          local_24 = *(int *)**(undefined4 **)(iVar4 + 0x10);
          iVar4 = local_24;
          if (*(code **)(iVar5 + 0x14) != (code *)0x0) {
            (**(code **)(iVar5 + 0x14))();
            iVar4 = local_24;
          }
        }
        local_24 = iVar4;
        local_27 = 2;
        local_26 = (ushort)(byte)(uVar3 >> 8) | (ushort)((uVar3 & 0xff) << 8);
        iVar4 = (**(code **)(iVar5 + 0x18))(2,1,0);
        if (iVar4 == -1) {
          iVar5 = errnoGet();
          pcVar1 = strerror(iVar5);
          fdprintf(2,DAT_300f8f30,pcVar1);
        }
        else {
          iVar6 = (**(code **)(iVar5 + 0x1c))(iVar4,&uStack_28,0x10);
          if (iVar6 == 0) {
            local_30 = 1;
            local_2c = 0;
            (**(code **)(iVar5 + 0x20))(iVar4,DAT_300f8f38,0x80,&local_30,8);
            local_34 = 1;
            (**(code **)(iVar5 + 0x20))(iVar4,6,1,&local_34,4);
            *(int *)(param_1 + 8) = iVar4;
            free(__s);
            return 0;
          }
          iVar5 = errnoGet();
          pcVar1 = strerror(iVar5);
          fdprintf(2,DAT_300f8f34,pcVar1);
          close(iVar4);
        }
      }
    }
  }
LAB_300f8440:
  free(__s);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300f8454 @ 0x300F8454  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300f8168, FUN_300f81ac
 * Вызывают: FUN_300f8488
 * Константы: 0x300F8454, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300f8454(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x2c) & 8) == 0) {
    if (*(int *)(param_1 + 0x28) == 1) {
      uVar1 = FUN_300f81ac();
    }
    else {
      uVar1 = FUN_300f8168();
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300f8488 @ 0x300F8488  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300f8454, fdprintf, lstFirst, lstNext
 * Вызывают: tipStart
 * Константы: 0x300F8488
 * Данные: DAT_300f8f3c, DAT_300f8f40, DAT_300f8f44
 * ---------------------------------------------------------------- */
undefined4 FUN_300f8488(void)

{
  int iVar1;
  int iVar2;
  
  for (iVar1 = lstFirst(); iVar1 != 0; iVar1 = lstNext(iVar1)) {
    iVar2 = FUN_300f8454(iVar1);
    if (iVar2 == -1) {
      *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) | 8;
    }
    else {
      fdprintf(1,DAT_300f8f3c,*(undefined4 *)(iVar1 + 0x14));
    }
  }
  fdprintf(1,DAT_300f8f44,*DAT_300f8f40);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f84f8 @ 0x300F84F8  (примерный размер ~228 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 9
 * Вызывает: fdprintf, lstAdd, lstFirst, lstNext, malloc, semGive, semTake, strcmp, strcpy
 * Вызывают: tipStart
 * Константы: 0xFFFFFFFF, 0x300F84F8
 * Данные: DAT_300f8634, DAT_300f8f48, DAT_300f8f4c, DAT_300f8f50
 * ---------------------------------------------------------------- */
undefined4 FUN_300f84f8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  
  iVar2 = lstFirst(param_1 + 0x10);
  iVar1 = DAT_300f8f48;
  semTake(*(undefined4 *)(DAT_300f8f48 + 0xc),0xffffffff);
  do {
    if (iVar2 == 0) {
      semGive(*(undefined4 *)(iVar1 + 0xc));
      return 0;
    }
    for (iVar3 = lstFirst(iVar1); iVar3 != 0; iVar3 = lstNext(iVar3)) {
      iVar4 = strcmp(*(char **)(iVar2 + 0xc),(char *)(iVar3 + 8));
      if (iVar4 == 0) {
        fdprintf(1,DAT_300f8f4c,*(undefined4 *)(iVar2 + 0x14));
        *(undefined4 *)(iVar2 + 0x2c) = 8;
        goto LAB_300f85b8;
      }
    }
    pvVar5 = malloc(0x3c);
    if (pvVar5 == (void *)0x0) {
      fdprintf(2,DAT_300f8634,DAT_300f8f50);
      semGive(*(undefined4 *)(iVar1 + 0xc));
      return 0xffffffff;
    }
    strcpy((char *)((int)pvVar5 + 8),*(char **)(iVar2 + 0xc));
    lstAdd(iVar1,pvVar5);
LAB_300f85b8:
    iVar2 = lstNext(iVar2);
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300f85dc @ 0x300F85DC  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: fdprintf, ioctl
 * Вызывают: tipStart
 * Константы: 0x300F85DC, 0xFFFFFFFF
 * Данные: DAT_300f8f14, DAT_300f8f54
 * ---------------------------------------------------------------- */
undefined4 FUN_300f85dc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ioctl(0,0x13,0);
  *(int *)(param_1 + 0xc) = iVar1;
  iVar1 = ioctl(0,3,0x1e);
  if (iVar1 == -1) {
    fdprintf(2,DAT_300f8f54);
    uVar2 = 0xffffffff;
  }
  else {
    if (*(int *)(param_1 + 0x1c) != 0) {
      if (*(code **)(DAT_300f8f14 + 8) != (code *)0x0) {
        (**(code **)(DAT_300f8f14 + 8))();
      }
      *(undefined4 *)(param_1 + 0x20) = 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300f8680 @ 0x300F8680  (примерный размер ~228 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: fdprintf, lstFirst, lstNext
 * Вызывают: FUN_300f8b2c, tipStart
 * Константы: 0x300F8680, 0xFFFFFFFD, 0xFFFFFFFB
 * Данные: DAT_300f8f58, DAT_300f8f5c
 * ---------------------------------------------------------------- */
void FUN_300f8680(undefined4 param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  
  for (iVar1 = lstFirst(); iVar1 != 0; iVar1 = lstNext(iVar1)) {
    if (((*(uint *)(iVar1 + 0x2c) & 8) == 0) &&
       ((*(int *)(iVar1 + 0x24) == param_2 || (param_2 == -1)))) {
      if (((param_3 & 2) != 0) &&
         (*(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) | 2, param_4 != 0)) {
        fdprintf(1,DAT_300f8f58,*(int *)(iVar1 + 0x24),*(undefined4 *)(iVar1 + 0x14));
      }
      if ((param_3 & 4) != 0) {
        *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xfffffffd;
      }
      if ((param_3 & 8) != 0) {
        *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) | 4;
        *(undefined4 *)(iVar1 + 0x34) = 1;
        if (param_4 != 0) {
          fdprintf(1,DAT_300f8f5c,*(undefined4 *)(iVar1 + 0x24),*(undefined4 *)(iVar1 + 0x14));
        }
      }
      if ((param_3 & 0x10) != 0) {
        *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xfffffffb;
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * tipStart @ 0x300F8764  (примерный размер ~736 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 21
 * Вызывает: FUN_300f720c, FUN_300f72a4, FUN_300f7564, FUN_300f7f08, FUN_300f80cc, FUN_300f8488, FUN_300f84f8, FUN_300f85dc, FUN_300f8680, bzero, errnoGet, fdprintf, lstAdd, lstCount
 *           ...
 * Константы: 0x300F8764, 0xFFFFFFFF
 * Данные: DAT_300f8f60, DAT_300f8f64, DAT_300f8f68, DAT_300f8f6c, DAT_300f8f70, DAT_300f8f74, DAT_300f8f78, DAT_300f8f7c
 * ---------------------------------------------------------------- */
void tipStart(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  fd_set local_114 [2];
  
  if (param_1 == 0) {
    fdprintf(2,DAT_300f8f60);
  }
  else {
    iVar1 = FUN_300f80cc();
    iVar3 = DAT_300f8f64;
    if (iVar1 != 0) {
      semTake(*(undefined4 *)(DAT_300f8f64 + 0xc),0xffffffff);
      lstAdd(iVar3,iVar1);
      iVar2 = lstCount(iVar3);
      if ((iVar2 == 1) && (iVar2 = taskDeleteHookAdd(DAT_300f8f68), iVar2 != 0)) {
        fdprintf(2,DAT_300f8f6c,DAT_300f8f70);
        semGive(*(undefined4 *)(iVar3 + 0xc));
      }
      else {
        semGive(*(undefined4 *)(iVar3 + 0xc));
        iVar3 = FUN_300f7f08(iVar1,param_1,param_2);
        if ((iVar3 != -1) && (iVar3 = FUN_300f84f8(iVar1), iVar3 != -1)) {
          iVar3 = lstCount(iVar1 + 0x10);
          if (iVar3 == 0) {
            fdprintf(2,DAT_300f8f74);
          }
          else {
            iVar3 = FUN_300f8488(iVar1 + 0x10);
            if ((iVar3 == 0) && (iVar3 = FUN_300f85dc(iVar1), iVar3 == 0)) {
              iVar3 = lstFirst(iVar1 + 0x10);
              FUN_300f8680(iVar1 + 0x10,1,10,1);
              while( true ) {
                bzero(local_114,0x100);
                local_114[0].fds_bits[0] = local_114[0].fds_bits[0] | 1;
                iVar2 = lstFirst(iVar1 + 0x10);
                while (iVar2 != 0) {
                  uVar6 = *(uint *)(iVar2 + 0x2c);
                  if ((uVar6 & 8) == 0) {
                    if ((uVar6 & 2) != 0) {
                      local_114[0].fds_bits[*(uint *)(iVar2 + 8) >> 5] =
                           local_114[0].fds_bits[*(uint *)(iVar2 + 8) >> 5] |
                           1 << (*(uint *)(iVar2 + 8) & 0x1f);
                    }
                    if ((uVar6 & 4) != 0) {
                      iVar3 = iVar2;
                    }
                  }
                  iVar2 = lstNext();
                }
                iVar2 = select(0x800,local_114,(fd_set *)0x0,(fd_set *)0x0,(timeval *)0x0);
                if ((iVar2 == 0) || (iVar2 == -1)) break;
                if (((local_114[0].fds_bits[0] & 1U) != 0) &&
                   ((iVar2 = FUN_300f72a4(iVar3,iVar1), iVar2 == -1 || (*(int *)(iVar3 + 0x30) != 0)
                    ))) goto LAB_300f8a2c;
                for (iVar2 = lstFirst(iVar1 + 0x10); iVar2 != 0; iVar2 = lstNext(iVar2)) {
                  if ((((*(uint *)(iVar2 + 0x2c) & 8) == 0) &&
                      ((local_114[0].fds_bits[*(uint *)(iVar2 + 8) >> 5] &
                       1 << (*(uint *)(iVar2 + 8) & 0x1f)) != 0)) &&
                     (iVar4 = FUN_300f720c(iVar1,iVar2), iVar4 == -1)) {
                    fdprintf(1,DAT_300f8f78,*(undefined4 *)(iVar2 + 0x14));
                    *(undefined4 *)(iVar2 + 0x2c) = 8;
                  }
                }
              }
              iVar3 = errnoGet();
              pcVar5 = strerror(iVar3);
              fdprintf(2,DAT_300f8f7c,pcVar5);
            }
          }
        }
      }
LAB_300f8a2c:
      FUN_300f7564(iVar1,1);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300f8a44 @ 0x300F8A44  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300F8A44
 * ---------------------------------------------------------------- */
undefined4 FUN_300f8a44(int param_1)

{
  *(undefined4 *)(param_1 + 0x30) = 1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f8a54 @ 0x300F8A54  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: fdprintf, lstFirst, lstNext
 * Вызывают: FUN_300f8b2c
 * Константы: 0x300F8A54
 * Данные: DAT_300f8f80, DAT_300f8f84, DAT_300f8f88, DAT_300f8f8c, DAT_300f8f90, DAT_300f8f94
 * ---------------------------------------------------------------- */
undefined4 FUN_300f8a54(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = lstFirst(param_2);
  fdprintf(1,DAT_300f8f80);
  for (; iVar1 != 0; iVar1 = lstNext(iVar1)) {
    uVar2 = DAT_300f8f84;
    if ((*(uint *)(iVar1 + 0x2c) & 4) == 0) {
      uVar2 = DAT_300f8f88;
    }
    uVar3 = DAT_300f8f8c;
    if (((int)*(uint *)(iVar1 + 0x2c) >> 3 & 1U) == 0) {
      uVar3 = DAT_300f8f90;
    }
    fdprintf(1,DAT_300f8f94,uVar2,*(undefined4 *)(iVar1 + 0x24),*(undefined4 *)(iVar1 + 0x14),uVar3)
    ;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f8ad8 @ 0x300F8AD8  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: fdprintf
 * Константы: 0x300F8AD8
 * Данные: DAT_300f8f40, DAT_300f8f98, DAT_300f8f9c, DAT_300f8fa0
 * ---------------------------------------------------------------- */
undefined4 FUN_300f8ad8(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  fdprintf(1,DAT_300f8f98);
  iVar1 = 4;
  puVar2 = DAT_300f8f9c;
  do {
    fdprintf(1,DAT_300f8fa0,*DAT_300f8f40,*puVar2,*(undefined4 *)(puVar2 + 4));
    puVar2 = puVar2 + 0xc;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f8b2c @ 0x300F8B2C  (примерный размер ~1176 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 10
 * Вызывает: FUN_300f8680, FUN_300f8a54, __stdout, __swbuf, fdprintf, fflush, lstCount, memcmp, read, sscanf
 * Константы: 0xFFFFFFFF, 0x300F8B2C
 * Данные: DAT_300f8fa4, DAT_300f8fa8, DAT_300f8fac, DAT_300f8fb0, DAT_300f8fb4, DAT_300f8fb8, DAT_300f8fbc, DAT_300f8fc0
 * ---------------------------------------------------------------- */
undefined4 FUN_300f8b2c(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char local_30 [4];
  uint local_2c;
  char local_28 [12];
  
  uVar1 = lstCount(param_2);
LAB_300f8b48:
  do {
    iVar4 = 0;
    FUN_300f8a54(param_1,param_2,0);
    fdprintf(1,DAT_300f8fa4,DAT_300f8fa8,DAT_300f8fac);
    puVar2 = (undefined4 *)__stdout();
    fflush((FILE *)*puVar2);
    while( true ) {
      read(0,local_30,1);
      piVar3 = (int *)__stdout();
      iVar5 = *(int *)(*piVar3 + 4);
      piVar3 = (int *)__stdout();
      if ((*piVar3 == iVar5) && (piVar3 = (int *)__stdout(), *(char *)(*piVar3 + 10) == 'f')) {
        piVar3 = (int *)__stdout();
        iVar5 = *(int *)(*piVar3 + 0x14) + -1;
        *(int *)(*piVar3 + 0x14) = iVar5;
        if (iVar5 < 0) {
          piVar3 = (int *)__stdout();
          iVar5 = *(int *)(*piVar3 + 0x14);
          piVar3 = (int *)__stdout();
          if (iVar5 < *(int *)(*piVar3 + 0x24)) {
            puVar2 = (undefined4 *)__stdout();
            __swbuf(local_30[0],*puVar2);
          }
          else {
            piVar3 = (int *)__stdout();
            **(char **)(*piVar3 + 0xc) = local_30[0];
            piVar3 = (int *)__stdout();
            if (**(char **)(*piVar3 + 0xc) == '\n') {
              puVar2 = (undefined4 *)__stdout();
              __swbuf(10,*puVar2);
            }
            else {
              piVar3 = (int *)__stdout();
              *(int *)(*piVar3 + 0xc) = *(int *)(*piVar3 + 0xc) + 1;
            }
          }
        }
        else {
          piVar3 = (int *)__stdout();
          **(char **)(*piVar3 + 0xc) = local_30[0];
          piVar3 = (int *)__stdout();
          *(int *)(*piVar3 + 0xc) = *(int *)(*piVar3 + 0xc) + 1;
        }
      }
      puVar2 = (undefined4 *)__stdout();
      fflush((FILE *)*puVar2);
      if ((local_30[0] == '\n') && (iVar4 == 0)) goto LAB_300f8b48;
      if (local_30[0] == '\n') goto LAB_300f8dec;
      if (iVar4 == 9) break;
      local_28[iVar4] = local_30[0];
      iVar4 = iVar4 + 1;
    }
    piVar3 = (int *)__stdout();
    iVar5 = *(int *)(*piVar3 + 4);
    piVar3 = (int *)__stdout();
    if ((*piVar3 == iVar5) && (piVar3 = (int *)__stdout(), *(char *)(*piVar3 + 10) == 'f')) {
      piVar3 = (int *)__stdout();
      iVar5 = *(int *)(*piVar3 + 0x14) + -1;
      *(int *)(*piVar3 + 0x14) = iVar5;
      if (iVar5 < 0) {
        piVar3 = (int *)__stdout();
        iVar5 = *(int *)(*piVar3 + 0x14);
        piVar3 = (int *)__stdout();
        if (*(int *)(*piVar3 + 0x24) <= iVar5) {
          piVar3 = (int *)__stdout();
          **(undefined1 **)(*piVar3 + 0xc) = 10;
          piVar3 = (int *)__stdout();
          if (**(char **)(*piVar3 + 0xc) != '\n') {
            piVar3 = (int *)__stdout();
            *(int *)(*piVar3 + 0xc) = *(int *)(*piVar3 + 0xc) + 1;
            goto LAB_300f8de0;
          }
        }
        puVar2 = (undefined4 *)__stdout();
        __swbuf(10,*puVar2);
      }
      else {
        piVar3 = (int *)__stdout();
        **(undefined1 **)(*piVar3 + 0xc) = 10;
        piVar3 = (int *)__stdout();
        *(int *)(*piVar3 + 0xc) = *(int *)(*piVar3 + 0xc) + 1;
      }
    }
LAB_300f8de0:
    puVar2 = (undefined4 *)__stdout();
    fflush((FILE *)*puVar2);
LAB_300f8dec:
    local_28[iVar4] = '\0';
    iVar4 = memcmp(local_28,DAT_300f8fac,2);
    if (iVar4 == 0) {
      fdprintf(1,DAT_300f8fb0);
      return 0;
    }
    iVar4 = memcmp(local_28,DAT_300f8fa8,4);
    if (iVar4 == 0) {
      FUN_300f8680(param_2,*(undefined4 *)(param_1 + 0x24),0x10,0);
      FUN_300f8680(param_2,0xffffffff,2,0);
      fdprintf(1,DAT_300f8fb4);
      return 0;
    }
    iVar4 = sscanf(local_28,DAT_300f8fb8,&local_2c);
    if (iVar4 == 1) {
      if ((local_2c <= uVar1) && (local_2c != 0)) {
        FUN_300f8680(param_2,0xffffffff,0x14,1);
        FUN_300f8680(param_2,local_2c,10,1);
        return 0;
      }
      fdprintf(2,DAT_300f8fc0,local_2c);
    }
    else {
      fdprintf(2,DAT_300f8fbc,local_28);
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300f8fc4 @ 0x300F8FC4  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: memcmp
 * Константы: 0x300F8FC4
 * Данные: DAT_300f914c, DAT_300f9150, DAT_300f9154, DAT_300f9158, DAT_300f915c
 * ---------------------------------------------------------------- */
undefined4
FUN_300f8fc4(void *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            int param_6)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = DAT_300f914c;
  if (*(int *)(param_6 + 0xc) == param_4) {
    iVar2 = memcmp(param_1,DAT_300f9150,8);
    bVar3 = iVar2 == 0;
    if (!bVar3) {
      iVar2 = memcmp(param_1,DAT_300f9154,7);
      bVar3 = iVar2 == 0;
    }
    if (bVar3) {
      *(undefined4 *)(param_4 + iVar1) = param_2;
    }
    else {
      iVar2 = memcmp(param_1,DAT_300f9158,8);
      bVar3 = iVar2 == 0;
      if (!bVar3) {
        iVar2 = memcmp(param_1,DAT_300f915c,7);
        bVar3 = iVar2 == 0;
      }
      if (bVar3) {
        *(undefined4 *)(param_4 + 0x538) = param_2;
      }
    }
  }
  if ((*(int *)(param_4 + iVar1) != 0) && (*(int *)(param_4 + 0x538) != 0)) {
    return 0;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * loadElfInit @ 0x300F9168  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrLoaderInit
 * Константы: 0x300F9168, 0xFFFFFFFF
 * Данные: DAT_300fa12c, DAT_300fa130, DAT_300fa134
 * ---------------------------------------------------------------- */
code * loadElfInit(void)

{
  code *pcVar1;
  bool bVar2;
  
  *DAT_300fa130 = DAT_300fa12c;
  pcVar1 = (code *)*DAT_300fa134;
  bVar2 = pcVar1 == (code *)0x0;
  if (!bVar2) {
    pcVar1 = (code *)(*pcVar1)();
    bVar2 = pcVar1 == (code *)0x0;
    if (!bVar2) {
      pcVar1 = (code *)0xffffffff;
    }
  }
  if (bVar2) {
    pcVar1 = (code *)0x0;
  }
  return pcVar1;
}

/* ----------------------------------------------------------------
 * FUN_300f91a4 @ 0x300F91A4  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: free, loadModuleSeek, loadModuleStringRead, malloc
 * Вызывают: FUN_300fa0b8
 * Константы: 0x300F91A4
 * ---------------------------------------------------------------- */
void * FUN_300f91a4(undefined4 param_1,int param_2,int param_3)

{
  void *__ptr;
  int iVar1;
  size_t __size;
  
  param_2 = (uint)*(ushort *)(param_3 + 0x32) * 0x28 + param_2;
  __size = *(size_t *)(param_2 + 0x14);
  __ptr = malloc(__size);
  if (__ptr == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = loadModuleSeek(param_1,*(undefined4 *)(param_2 + 0x10),0);
  if ((iVar1 != -1) && (iVar1 = loadModuleStringRead(param_1,__ptr,__size), iVar1 != -1)) {
    return __ptr;
  }
  free(__ptr);
  return (void *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_300f9220 @ 0x300F9220  (примерный размер ~352 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: printErr
 * Вызывают: FUN_300fa0b8
 * Константы: 0x300F9220, 0xFFFFFFFF
 * Данные: DAT_300fa138, DAT_300fa244, DAT_300fa248, DAT_300fa24c, DAT_300fa250
 * ---------------------------------------------------------------- */
undefined4 FUN_300f9220(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_24;
  int local_20;
  int local_1c;
  
  local_24 = *DAT_300fa138;
  local_20 = DAT_300fa138[1];
  iVar2 = 0;
  local_1c = DAT_300fa138[2];
  iVar3 = 0;
  if (0 < param_2) {
    do {
      if (*param_1 == 1) {
        iVar2 = iVar2 + 1;
        if ((param_1[6] & 1U) == 0) {
          if ((param_1[6] & 6U) == 0) {
            printErr(DAT_300fa250,iVar3);
            goto LAB_300f9348;
          }
          if (param_1[4] == 0) {
            if (local_1c != 0) {
              printErr(DAT_300fa248);
            }
            iVar1 = **(int **)*param_3;
            *(undefined4 *)(iVar1 + 0xc) = 8;
            local_1c = 1;
          }
          else {
            if (local_20 != 0) {
              printErr(DAT_300fa24c);
            }
            iVar1 = *(int *)*param_3;
            *(undefined4 *)(iVar1 + 0xc) = 4;
            local_20 = 1;
          }
        }
        else {
          if (local_24 != 0) {
            printErr(DAT_300fa244);
          }
          iVar1 = *param_3;
          *(undefined4 *)(iVar1 + 0xc) = 2;
          local_24 = 1;
        }
        *(int *)(iVar1 + 0x10) = param_1[2];
        *(int *)(iVar1 + 0x14) = param_1[5];
        *(int *)(iVar1 + 0x18) = param_1[1];
      }
LAB_300f9348:
      param_1 = param_1 + 8;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2);
    if ((iVar2 < 4) && (iVar2 != 0)) {
      return 0;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300f9380 @ 0x300F9380  (примерный размер ~316 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: loadModuleValueRead
 * Вызывают: FUN_300f9570
 * Константы: 0xFF00FFFF, 0x300F9380, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300f9380(undefined4 param_1,uint *param_2,int param_3)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  
  iVar1 = loadModuleValueRead(param_1,param_2,4);
  if ((((iVar1 != -1) && (iVar1 = loadModuleValueRead(param_1,param_2 + 1,4), iVar1 != -1)) &&
      (iVar1 = loadModuleValueRead(param_1,param_2 + 2,4), iVar1 != -1)) &&
     (((iVar1 = loadModuleValueRead(param_1,param_2 + 3,1), iVar1 != -1 &&
       (iVar1 = loadModuleValueRead(param_1,(int)param_2 + 0xd,1), iVar1 != -1)) &&
      (iVar1 = loadModuleValueRead(param_1,(int)param_2 + 0xe,2), iVar1 != -1)))) {
    if (param_3 == 0) {
      uVar3 = *param_2;
    }
    else {
      uVar3 = *param_2;
      uVar3 = (uVar3 >> 8 | uVar3 << 0x18) ^
              ((uVar3 ^ (uVar3 >> 0x10 | uVar3 << 0x10)) & 0xff00ffff) >> 8;
    }
    *param_2 = uVar3;
    if (param_3 == 0) {
      uVar3 = param_2[1];
    }
    else {
      uVar3 = param_2[1];
      uVar3 = (uVar3 >> 8 | uVar3 << 0x18) ^
              ((uVar3 ^ (uVar3 >> 0x10 | uVar3 << 0x10)) & 0xff00ffff) >> 8;
    }
    param_2[1] = uVar3;
    if (param_3 == 0) {
      uVar3 = param_2[2];
    }
    else {
      uVar3 = param_2[2];
      uVar3 = (uVar3 >> 8 | uVar3 << 0x18) ^
              ((uVar3 ^ (uVar3 >> 0x10 | uVar3 << 0x10)) & 0xff00ffff) >> 8;
    }
    param_2[2] = uVar3;
    uVar2 = *(ushort *)((int)param_2 + 0xe);
    if (param_3 != 0) {
      uVar2 = uVar2 >> 8 | (ushort)((uVar2 & 0xff) << 8);
    }
    *(ushort *)((int)param_2 + 0xe) = uVar2;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300f94bc @ 0x300F94BC  (примерный размер ~180 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300f9570
 * Константы: 0x300F94BC
 * Данные: DAT_300fa47c, DAT_300fa480
 * ---------------------------------------------------------------- */
undefined4 FUN_300f94bc(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = (uint)*(ushort *)(param_1 + 0xe);
  if (uVar1 == DAT_300fa47c) {
    uVar2 = 0x20;
  }
  else if (uVar1 == DAT_300fa480) {
    uVar2 = 2;
  }
  else {
    param_2 = param_2 + uVar1 * 0x28;
    if (*(int *)(param_2 + 4) == 1) {
      if ((*(uint *)(param_2 + 8) & 6) == 6) {
        return 4;
      }
      if ((*(uint *)(param_2 + 8) & 3) == 3) {
        return 8;
      }
      uVar3 = 8;
    }
    else {
      if (*(int *)(param_2 + 4) != 8) {
        return 0;
      }
      uVar3 = 0x10;
    }
    uVar2 = 0;
    if ((*(uint *)(param_2 + 8) & 2) != 0) {
      uVar2 = uVar3;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300f9570 @ 0x300F9570  (примерный размер ~684 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_300f9380, FUN_300f94bc, loadCommonSymbolProcess, loadDefinedSymbolProcess, loadModuleSeek, loadUndefinedSymbolProcess, memcmp
 * Вызывают: FUN_300f981c
 * Константы: 0xFFFFFFFF, 0x300F9570
 * Данные: DAT_300fa47c, DAT_300fa480, DAT_300fa574, DAT_300fa578
 * ---------------------------------------------------------------- */
undefined4
FUN_300f9570(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,
            undefined4 param_5,int param_6,int param_7,int param_8,uint param_9,undefined4 param_10,
            undefined4 *param_11,undefined4 param_12)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  void *__s1;
  int iVar6;
  bool bVar7;
  uint local_48;
  uint local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  byte local_30;
  ushort local_2e;
  
  iVar1 = loadModuleSeek(param_1,param_5,0);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar4 = 0;
    *param_11 = 0;
    if (param_9 != 0) {
      do {
        local_48 = 0;
        iVar1 = FUN_300f9380(param_1,&local_3c,param_12);
        if (iVar1 == -1) {
          return 0xffffffff;
        }
        __s1 = (void *)(param_8 + local_3c);
        iVar1 = memcmp(__s1,DAT_300fa574,0xf);
        bVar7 = iVar1 == 0;
        if (bVar7) {
LAB_300f9634:
          if (bVar7) {
            iVar1 = 0;
LAB_300f97a8:
            *(int *)(param_7 + uVar4 * 0xc) = iVar1;
            iVar1 = param_7 + uVar4 * 0xc;
            *(undefined1 *)(iVar1 + 4) = 0;
            *(undefined4 *)(iVar1 + 8) = 0;
          }
          else {
            iVar6 = param_7 + uVar4 * 0xc;
            iVar1 = loadUndefinedSymbolProcess(__s1,iVar6,param_2);
            if (iVar1 != 0) {
              return 0xffffffff;
            }
            if (*(char *)(iVar6 + 4) == '\0') {
              *param_11 = 1;
            }
          }
        }
        else {
          uVar5 = (uint)local_2e;
          if (uVar5 == 0) {
            bVar7 = (int)(uint)local_30 >> 4 == 0;
            goto LAB_300f9634;
          }
          if (uVar5 != DAT_300fa47c) {
            local_48 = FUN_300f94bc(&local_3c,param_10,uVar5);
            iVar1 = (int)(uint)local_30 >> 4;
            if (iVar1 == 1) {
              uVar3 = 1;
LAB_300f96ec:
              local_48 = local_48 | uVar3;
            }
            else {
              if (iVar1 != 2) {
                uVar3 = 0x40;
                goto LAB_300f96ec;
              }
              local_48 = local_48 | 0x10001;
            }
            if (((param_3 & 0x20) == 0) && (uVar5 != DAT_300fa480)) {
              iVar1 = *(int *)(param_6 + uVar5 * 4);
              if (iVar1 == 0) {
                local_48 = 0;
                goto LAB_300f9724;
              }
              local_40 = *(int *)(iVar1 + 0x1c);
            }
            else {
LAB_300f9724:
              local_40 = 0;
            }
            local_44 = local_30 & 0xf;
            local_40 = local_40 + local_38;
            if (((code *)*DAT_300fa578 != (code *)0x0) &&
               (iVar1 = (*(code *)*DAT_300fa578)
                                  (__s1,&local_40,&local_44,&local_3c,&local_48,param_6,param_2,
                                   param_3,param_4), iVar1 != 0)) {
              return 0xffffffff;
            }
            if ((local_44 == 1) || (iVar1 = local_40, local_44 == 2)) {
              iVar1 = loadDefinedSymbolProcess
                                (__s1,local_40,local_48,param_7 + uVar4 * 0xc,param_2,param_3);
              if (iVar1 != 0) {
                return 0xffffffff;
              }
              goto LAB_300f97f8;
            }
            goto LAB_300f97a8;
          }
          iVar1 = loadCommonSymbolProcess
                            (__s1,local_34,local_38,param_7 + uVar4 * 0xc,param_2,param_3);
          if (iVar1 != 0) {
            return 0xffffffff;
          }
        }
LAB_300f97f8:
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_9);
    }
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300f981c @ 0x300F981C  (примерный размер ~284 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300f9570, free, loadModuleSeek, loadModuleStringRead, malloc
 * Вызывают: FUN_300fa0b8
 * Константы: 0xFFFFFFFF, 0x300F981C
 * ---------------------------------------------------------------- */
undefined4
FUN_300f981c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,int param_7,int param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11)

{
  void *__ptr;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = *(undefined4 *)(param_8 + 0x10);
  iVar3 = param_7 + *(int *)(param_8 + 0x18) * 0x28;
  __ptr = malloc(*(size_t *)(iVar3 + 0x14));
  if (__ptr == (void *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = loadModuleSeek(param_6,*(undefined4 *)(iVar3 + 0x10),0);
    if (iVar1 == -1) {
      free(__ptr);
      uVar2 = 0xffffffff;
    }
    else {
      iVar3 = loadModuleStringRead(param_6,__ptr,*(undefined4 *)(iVar3 + 0x14));
      if (iVar3 == -1) {
        free(__ptr);
        uVar2 = 0xffffffff;
      }
      else {
        iVar3 = FUN_300f9570(param_6,param_1,param_2,param_3,uVar2,param_4,param_5,__ptr,param_9,
                             param_7,param_10,param_11);
        if (iVar3 == 0) {
          free(__ptr);
          uVar2 = 0;
        }
        else {
          free(__ptr);
          uVar2 = 0xffffffff;
        }
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300f9938 @ 0x300F9938  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300f9964, FUN_300f9b38
 * Константы: 0x300F9938
 * ---------------------------------------------------------------- */
uint FUN_300f9938(int param_1)

{
  if ((*(int *)(param_1 + 4) != 1) && (*(int *)(param_1 + 4) != 8)) {
    return 0;
  }
  return *(uint *)(param_1 + 8) >> 1 & 1;
}

/* ----------------------------------------------------------------
 * FUN_300f9964 @ 0x300F9964  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300f9938, elfArchReloc
 * Вызывают: FUN_300fa0b8
 * Константы: 0x300F9964, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4
FUN_300f9964(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_3;
  if (param_4 != 0) {
    do {
      if ((*(int *)(iVar2 + 4) == 9) || (*(int *)(iVar2 + 4) == 4)) {
        iVar3 = *(int *)(iVar2 + 0x1c);
        iVar1 = FUN_300f9938(param_3 + iVar3 * 0x28);
        if ((iVar1 != 0) &&
           (iVar1 = elfArchReloc(*(undefined4 *)(param_2 + 0x540),param_1,iVar2,
                                 *(undefined4 *)(*(int *)(param_5 + iVar3 * 4) + 0x1c),0,0,param_6),
           iVar1 != 0)) {
          return 0xffffffff;
        }
      }
      param_4 = param_4 + -1;
      iVar2 = iVar2 + 0x28;
    } while (param_4 != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f9a0c @ 0x300F9A0C  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: calloc, malloc
 * Вызывают: FUN_300fa0b8
 * Константы: 0xFFFFFFFF, 0x300F9A0C
 * ---------------------------------------------------------------- */
undefined4 FUN_300f9a0c(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  void *pvVar1;
  uint __nmemb;
  
  __nmemb = (uint)*(ushort *)(param_1 + 0x30);
  if (__nmemb != 0) {
    pvVar1 = calloc(__nmemb,4);
    *param_4 = pvVar1;
    if (pvVar1 == (void *)0x0) {
      return 0xffffffff;
    }
    if (__nmemb != 0) {
      pvVar1 = malloc(__nmemb * 0x28);
      *param_3 = pvVar1;
      if (pvVar1 == (void *)0x0) {
        return 0xffffffff;
      }
      goto LAB_300f9a80;
    }
  }
  *param_3 = 0;
LAB_300f9a80:
  if (*(ushort *)(param_1 + 0x2c) == 0) {
    *param_2 = 0;
  }
  else {
    pvVar1 = malloc((uint)*(ushort *)(param_1 + 0x2c) << 5);
    *param_2 = pvVar1;
    if (pvVar1 == (void *)0x0) {
      return 0xffffffff;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f9abc @ 0x300F9ABC  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300f9b38
 * Константы: 0x300F9ABC
 * ---------------------------------------------------------------- */
uint FUN_300f9abc(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 8);
    if (*(int *)(param_1 + 4) == 1) {
      if ((uVar1 & 6) == 6) {
        return 2;
      }
      if ((uVar1 & 3) != 3) {
        return (uint)((uVar1 & 7) == 2);
      }
      return 3;
    }
    if ((*(int *)(param_1 + 4) == 8) && ((uVar1 & 2) != 0)) {
      return (uVar1 & 1) << 2;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f9b38 @ 0x300F9B38  (примерный размер ~392 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_300f9938, FUN_300f9abc, malloc, memset, printErr, sllPutAtTail
 * Вызывают: FUN_300fa0b8
 * Константы: 0x300F9B38, 0xFFFFFFFF
 * Данные: DAT_300fa57c
 * ---------------------------------------------------------------- */
undefined4 FUN_300f9b38(int *param_1,int param_2,int param_3,int param_4,int *param_5,uint param_6)

{
  int iVar1;
  void *__s;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_2) {
    do {
      iVar1 = FUN_300f9938(param_1);
      if (iVar1 != 0) {
        iVar1 = *param_1;
        __s = malloc(0x2c);
        if (__s == (void *)0x0) {
          return 0xffffffff;
        }
        memset(__s,0,0x2c);
        *(int *)((int)__s + 0xc) = param_1[4];
        *(int *)((int)__s + 0x10) = param_1[5];
        *(int *)((int)__s + 0x14) = param_1[8];
        if ((param_6 & 0x20) == 0) {
          iVar2 = -1;
        }
        else {
          iVar2 = param_1[3];
        }
        *(int *)((int)__s + 0x1c) = iVar2;
        *(void **)(param_3 + iVar3 * 4) = __s;
        *(int *)((int)__s + 4) = param_4 + iVar1;
        iVar2 = FUN_300f9abc(param_1);
        if (iVar2 == 2) {
          *(undefined4 *)((int)__s + 8) = 2;
          sllPutAtTail(*param_5 + 4,__s);
        }
        else if (iVar2 < 3) {
          if (iVar2 == 0) {
            printErr(DAT_300fa57c,param_4 + iVar1,param_1[2]);
          }
          else if (iVar2 == 1) {
            *(undefined4 *)((int)__s + 8) = 1;
            sllPutAtTail(*param_5 + 4,__s);
          }
        }
        else if (iVar2 == 3) {
          *(undefined4 *)((int)__s + 8) = 3;
          sllPutAtTail(*(int *)*param_5 + 4,__s);
        }
        else if (iVar2 == 4) {
          *(undefined4 *)((int)__s + 8) = 4;
          sllPutAtTail(**(int **)*param_5 + 4,__s);
        }
      }
      param_1 = param_1 + 10;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f9cc0 @ 0x300F9CC0  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300fa0b8
 * Константы: 0x300F9CC0
 * ---------------------------------------------------------------- */
int FUN_300f9cc0(int param_1,int param_2)

{
  if (0 < param_2) {
    do {
      if (*(int *)(param_1 + 4) == 2) {
        return param_1;
      }
      param_1 = param_1 + 0x28;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300f9ce8 @ 0x300F9CE8  (примерный размер ~328 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300fa0b8
 * Константы: 0xFFFFFFFF, 0x300F9CE8
 * Данные: DAT_300fa580, DAT_300fa584
 * ---------------------------------------------------------------- */
undefined4 FUN_300f9ce8(undefined4 *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  uVar2 = 0;
  if ((param_3 & 0x20) == 0) {
    for (puVar3 = (undefined4 *)*param_1; iVar1 = DAT_300fa580, puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      if (((puVar3[3] == 2) && (*(int *)(param_2 + 4) == -1)) && (*(int *)(DAT_300fa580 + 0xc) != 0)
         ) {
        bVar8 = *(int *)(DAT_300fa580 + 0x14) == 0;
        if (!bVar8) {
          if (*(code **)(DAT_300fa580 + 0x20) == (code *)0x0) {
            iVar4 = -1;
          }
          else {
            iVar4 = (**(code **)(DAT_300fa580 + 0x20))(param_1);
          }
          pcVar5 = *(code **)(iVar1 + 0x20);
          if (pcVar5 == (code *)0x0) {
            iVar6 = -1;
          }
          else {
            iVar6 = (*pcVar5)();
          }
          param_1 = (undefined4 *)
                    (**(code **)(iVar1 + 0x14))
                              (0,puVar3[4],(puVar3[5] + iVar4) - 1U & ~(iVar6 - 1U),0x3f,5);
          bVar8 = param_1 == (undefined4 *)0xffffffff;
        }
        if (bVar8) {
          uVar2 = 0xffffffff;
        }
      }
      for (puVar7 = (undefined4 *)puVar3[1]; puVar7 != (undefined4 *)0x0;
          puVar7 = (undefined4 *)*puVar7) {
        if (((puVar7[2] == 2) && (puVar7[4] != 0)) &&
           (*(code **)(DAT_300fa584 + 0x1c) != (code *)0x0)) {
          param_1 = (undefined4 *)(**(code **)(DAT_300fa584 + 0x1c))(puVar7[7],puVar7[4]);
        }
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300f9e30 @ 0x300F9E30  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: moduleSectionChecksumSet
 * Вызывают: FUN_300fa0b8
 * Константы: 0x300F9E30, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300f9e30(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = 0;
  if (((param_3 & 0x40) != 0) && (*(int *)(param_1 + 0xc) != 1)) {
    return 0;
  }
  while (param_2 = (int *)*param_2, param_2 != (int *)0x0) {
    for (puVar3 = (undefined4 *)param_2[1]; puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      iVar1 = moduleSectionChecksumSet(puVar3[10]);
      if (iVar1 != 0) {
        uVar2 = 0xffffffff;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300f9e94 @ 0x300F9E94  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: moduleSectionRegister, moduleSegAdd
 * Вызывают: FUN_300fa0b8
 * Константы: 0xFFFFFFFF, 0x300F9E94
 * ---------------------------------------------------------------- */
undefined4 FUN_300f9e94(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_2 = (undefined4 *)*param_2;
  do {
    if (param_2 == (undefined4 *)0x0) {
      return 0;
    }
    for (puVar2 = (undefined4 *)param_2[1]; puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      iVar1 = moduleSegAdd(param_1,param_2[3],param_2[4],param_2[5],0);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      iVar1 = moduleSectionRegister
                        (param_1,puVar2[1],puVar2[2],puVar2[7],puVar2[4],puVar2[6],puVar2[5]);
      puVar2[10] = iVar1;
      if (iVar1 == 0) {
        return 0xffffffff;
      }
    }
    param_2 = (undefined4 *)*param_2;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300f9f34 @ 0x300F9F34  (примерный размер ~388 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: loadElfSectionHeaderCheck, loadModuleSeek, loadModuleValueRead
 * Вызывают: FUN_300fa0b8
 * Константы: 0xFFFFFFFF, 0x300F9F34
 * ---------------------------------------------------------------- */
undefined4 FUN_300f9f34(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = loadModuleSeek(param_1,param_3,0);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  iVar1 = 0;
  if (0 < param_4) {
    do {
      if (iVar3 == 0) {
        iVar2 = loadModuleValueRead(param_1,param_2,4);
        if ((((((iVar2 == -1) || (iVar2 = loadModuleValueRead(param_1,param_2 + 4,4), iVar2 == -1))
              || (iVar2 = loadModuleValueRead(param_1,param_2 + 8,4), iVar2 == -1)) ||
             ((iVar2 = loadModuleValueRead(param_1,param_2 + 0xc,4), iVar2 == -1 ||
              (iVar2 = loadModuleValueRead(param_1,param_2 + 0x10,4), iVar2 == -1)))) ||
            ((iVar2 = loadModuleValueRead(param_1,param_2 + 0x14,4), iVar2 == -1 ||
             ((iVar2 = loadModuleValueRead(param_1,param_2 + 0x18,4), iVar2 == -1 ||
              (iVar2 = loadModuleValueRead(param_1,param_2 + 0x1c,4), iVar2 == -1)))))) ||
           ((iVar2 = loadModuleValueRead(param_1,param_2 + 0x20,4), iVar2 == -1 ||
            (iVar2 = loadModuleValueRead(param_1,param_2 + 0x24,4), iVar2 == -1)))) {
          iVar3 = -1;
          goto LAB_300fa070;
        }
      }
      else {
LAB_300fa070:
        if (iVar3 == -1) {
          return 0xffffffff;
        }
      }
      iVar2 = loadElfSectionHeaderCheck(param_2,iVar1);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      param_2 = param_2 + 0x28;
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_4);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300fa0b8 @ 0x300FA0B8  (примерный размер ~1248 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 24
 * Вызывает: FUN_300f91a4, FUN_300f9220, FUN_300f981c, FUN_300f9964, FUN_300f9a0c, FUN_300f9b38, FUN_300f9cc0, FUN_300f9ce8, FUN_300f9e30, FUN_300f9e94, FUN_300f9f34, __udiv32, calloc, errnoSet
 *           ...
 * Константы: 0x300FA0B8, 0xFFFFFFFF
 * Данные: DAT_300fa588, DAT_300fa58c, DAT_300fa590, DAT_300fa594
 * ---------------------------------------------------------------- */
int FUN_300fa0b8(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *__ptr;
  void *__ptr_00;
  void *__ptr_01;
  undefined4 local_84;
  void *local_80;
  void *local_7c;
  code *local_78;
  code *local_74;
  void *local_70;
  void *local_6c;
  size_t local_68;
  undefined1 auStack_64 [8];
  undefined1 auStack_5c [16];
  short local_4c;
  undefined4 local_40;
  undefined4 local_3c;
  short local_30;
  ushort local_2c;
  
  local_80 = (void *)0x0;
  __ptr_01 = (void *)0x0;
  __ptr_00 = (void *)0x0;
  local_84 = 0;
  memset(auStack_64,0,8);
  __ptr = (void *)0x0;
  local_7c = (void *)0x0;
  iVar1 = loadElfFileHeaderReadAndCheck(param_1,auStack_5c,&local_84,(param_2 & 0x80) != 0);
  if (iVar1 != 0) {
LAB_300fa2b0:
    iVar1 = -1;
    goto LAB_300fa4e0;
  }
  if ((local_4c == 2) && ((param_2 & 0x20) == 0)) {
    errnoSet(DAT_300fa588);
    printErr(DAT_300fa58c);
    return -1;
  }
  iVar1 = loadSegInfoDescAllocate(auStack_64,param_2,param_3,param_4);
  if (iVar1 == -1) {
    return -1;
  }
  local_70 = (void *)0x0;
  local_6c = (void *)0x0;
  iVar1 = FUN_300f9a0c(auStack_5c,&local_80,&local_6c,&local_70);
  __ptr_01 = local_6c;
  __ptr_00 = local_70;
  if (((iVar1 != 0) ||
      ((local_30 != 0 &&
       (iVar1 = loadElfProgramHeaderTableReadAndCheck(param_1,local_80,local_40,local_30,local_84),
       iVar1 != 0)))) ||
     ((local_2c != 0 &&
      (iVar1 = FUN_300f9f34(param_1,__ptr_01,local_3c,local_2c,local_84), iVar1 != 0))))
  goto LAB_300fa4e0;
  iVar2 = FUN_300f9cc0(__ptr_01,local_2c);
  if ((iVar2 == 0) && ((param_2 & 0x20) == 0)) {
    errnoSet(DAT_300fa590);
    iVar1 = -1;
    goto LAB_300fa4e0;
  }
  local_7c = (void *)FUN_300f91a4(param_1,__ptr_01,auStack_5c);
  if ((local_7c == (void *)0x0) ||
     (iVar3 = loadModuleTagsCheck(param_1,param_5,__ptr_01,local_2c,__ptr_00,local_7c,param_2),
     iVar3 != 0)) goto LAB_300fa2b0;
  local_68 = (size_t)local_2c;
  if (local_68 == 0) {
    if (((param_2 & 0x20) == 0) || (iVar1 = FUN_300f9220(local_80,local_30,auStack_64), iVar1 == -1)
       ) goto LAB_300fa4e0;
LAB_300fa348:
    if ((param_2 & 0x20) == 0) goto LAB_300fa350;
    iVar1 = FUN_300f9e94(param_5,auStack_64);
  }
  else {
    iVar1 = FUN_300f9b38(__ptr_01,local_68,__ptr_00,local_7c,auStack_64,param_2);
    if (iVar1 == -1) goto LAB_300fa4e0;
    if ((param_2 & 0x20) != 0) {
      if ((*(int *)(param_1 + 0xc) != 1) &&
         (iVar3 = FUN_300f9220(local_80,local_30,auStack_64), iVar3 != 0)) goto LAB_300fa4e0;
      goto LAB_300fa348;
    }
LAB_300fa350:
    iVar1 = loadSegmentsAllocate(param_5,param_2,auStack_64);
  }
  if ((iVar1 == 0) && (iVar1 = loadSectionsInstall(param_1,param_2,auStack_64), iVar1 == 0)) {
    if (iVar2 != 0) {
      local_68 = __udiv32(*(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x24));
      __ptr = calloc(local_68,0xc);
      if ((__ptr == (void *)0x0) ||
         (iVar1 = FUN_300f981c(param_5,param_2,auStack_5c,__ptr_00,__ptr,param_1,__ptr_01,iVar2,
                               local_68,param_6,local_84), iVar1 != 0)) goto LAB_300fa4e0;
    }
    if ((((param_2 & 0x60) != 0) ||
        (iVar1 = FUN_300f9964(param_1,param_5,__ptr_01,local_2c,__ptr_00,__ptr), iVar1 == 0)) &&
       (((local_78 = (code *)*DAT_300fa594, local_78 == (code *)0x0 ||
         (iVar1 = (*local_78)(param_5,param_2,local_84,param_1,auStack_64,__ptr_00,__ptr,0),
         iVar1 != -1)) && (iVar1 = FUN_300f9ce8(auStack_64,param_3,param_2), iVar1 == 0)))) {
      iVar1 = FUN_300f9e30(param_1,auStack_64,param_2);
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
    }
  }
LAB_300fa4e0:
  local_74 = (code *)*DAT_300fa594;
  if ((local_74 != (code *)0x0) && (iVar1 == -1)) {
    (*local_74)(param_5,param_2,local_84,param_1,auStack_64,__ptr_00,__ptr,0xffffffff);
  }
  free(local_80);
  free(__ptr_01);
  free(__ptr_00);
  free(__ptr);
  free(local_7c);
  loadSegInfoDescFree(auStack_64);
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300fa598 @ 0x300FA598  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: loadElfProgramHeaderTableReadAndCheck
 * Константы: 0x300FA598, 0xFFFFFFFF
 * Данные: DAT_300fab30
 * ---------------------------------------------------------------- */
undefined4 FUN_300fa598(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x1c) & *(uint *)(param_1 + 0x1c) - 1) == 0) {
    uVar1 = 0;
  }
  else {
    errnoSet(DAT_300fab30);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300fa5c4 @ 0x300FA5C4  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: elfArchVerify, errnoSet
 * Вызывают: loadElfFileHeaderReadAndCheck
 * Константы: 0xFFFFFFFF, 0x300FA5C4
 * Данные: DAT_300fab34
 * ---------------------------------------------------------------- */
char * FUN_300fa5c4(char *param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  bool bVar2;
  
  if ((((*param_1 != '\x7f') || (param_1[1] != 'E')) || (param_1[2] != 'L')) ||
     ((param_1[3] != 'F' || (param_1[4] != '\x01')))) {
    errnoSet(DAT_300fab34);
    return (char *)0xffffffff;
  }
  if (param_1[5] != '\x01') {
    errnoSet(DAT_300fab34);
    return (char *)0xffffffff;
  }
  if (*(short *)(param_1 + 0x28) != 0x34) {
    errnoSet(DAT_300fab34);
    return (char *)0xffffffff;
  }
  sVar1 = *(short *)(param_1 + 0x10);
  if (sVar1 == 1) {
LAB_300fa678:
    if (sVar1 == 2) goto LAB_300fa680;
  }
  else {
    if (sVar1 != 2) {
      if (sVar1 != 3) {
        errnoSet(DAT_300fab34);
        return (char *)0xffffffff;
      }
      goto LAB_300fa678;
    }
LAB_300fa680:
    if (*(short *)(param_1 + 0x2c) == 0) goto LAB_300fa6d0;
  }
  if ((((*(short *)(param_1 + 0x2c) == 0) || (*(int *)(param_1 + 0x1c) != 0)) &&
      ((*(short *)(param_1 + 0x30) == 0 || (*(int *)(param_1 + 0x20) != 0)))) &&
     ((sVar1 != 2 || (*(short *)(param_1 + 0x2a) == 0x20)))) {
    if (*(short *)(param_1 + 0x2e) != 0x28) {
      errnoSet(DAT_300fab34);
      return (char *)0xffffffff;
    }
    bVar2 = param_3 == 0;
    if (bVar2) {
      param_1 = (char *)elfArchVerify();
      bVar2 = param_1 == (char *)0x0;
      if (bVar2) {
        param_1 = (char *)0xffffffff;
      }
    }
    if (bVar2) {
      return param_1;
    }
    return (char *)0x0;
  }
LAB_300fa6d0:
  errnoSet(DAT_300fab34);
  return (char *)0xffffffff;
}

/* ----------------------------------------------------------------
 * loadElfFileHeaderReadAndCheck @ 0x300FA718  (примерный размер ~432 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300fa5c4, errnoSet, loadModuleStringRead, loadModuleValueRead
 * Вызывают: FUN_300fa0b8
 * Константы: 0xFFFFFFFF, 0x300FA718
 * Данные: DAT_300fab34, DAT_300fab38
 * ---------------------------------------------------------------- */
undefined4
loadElfFileHeaderReadAndCheck(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 == 0) {
    errnoSet(DAT_300fab38);
    return 0xffffffff;
  }
  iVar1 = loadModuleStringRead(param_1,param_2,0x10);
  if (((((iVar1 == -1) || (iVar1 = loadModuleValueRead(param_1,param_2 + 0x10,2), iVar1 == -1)) ||
       (iVar1 = loadModuleValueRead(param_1,param_2 + 0x12,2), iVar1 == -1)) ||
      ((((iVar1 = loadModuleValueRead(param_1,param_2 + 0x14,4), iVar1 == -1 ||
         (iVar1 = loadModuleValueRead(param_1,param_2 + 0x18,4), iVar1 == -1)) ||
        ((iVar1 = loadModuleValueRead(param_1,param_2 + 0x1c,4), iVar1 == -1 ||
         ((iVar1 = loadModuleValueRead(param_1,param_2 + 0x20,4), iVar1 == -1 ||
          (iVar1 = loadModuleValueRead(param_1,param_2 + 0x24,4), iVar1 == -1)))))) ||
       (iVar1 = loadModuleValueRead(param_1,param_2 + 0x28,2), iVar1 == -1)))) ||
     ((((iVar1 = loadModuleValueRead(param_1,param_2 + 0x2a,2), iVar1 == -1 ||
        (iVar1 = loadModuleValueRead(param_1,param_2 + 0x2c,2), iVar1 == -1)) ||
       (iVar1 = loadModuleValueRead(param_1,param_2 + 0x2e,2), iVar1 == -1)) ||
      ((iVar1 = loadModuleValueRead(param_1,param_2 + 0x30,2), iVar1 == -1 ||
       (iVar1 = loadModuleValueRead(param_1,param_2 + 0x32,2), iVar1 == -1)))))) {
    errnoSet(DAT_300fab34);
  }
  else {
    iVar1 = FUN_300fa5c4(param_2,param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * loadElfRelaEntryRead @ 0x300FA8C8  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: errnoSet, loadModuleValueRead
 * Вызывают: elfArchReloc
 * Константы: 0xFFFFFFFF, 0x300FA8C8
 * Данные: DAT_300fab3c
 * ---------------------------------------------------------------- */
undefined4 loadElfRelaEntryRead(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = loadModuleValueRead(param_1,param_2,4);
  if (iVar1 == -1) {
    errnoSet(DAT_300fab3c);
    return 0xffffffff;
  }
  iVar1 = loadModuleValueRead(param_1,param_2 + 4,4);
  if (iVar1 == -1) {
    errnoSet(DAT_300fab3c);
    return 0xffffffff;
  }
  iVar1 = loadModuleValueRead(param_1,param_2 + 8,4);
  if (iVar1 == -1) {
    errnoSet(DAT_300fab3c);
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * loadElfRelEntryRead @ 0x300FA94C  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: errnoSet, loadModuleValueRead
 * Константы: 0xFFFFFFFF, 0x300FA94C
 * Данные: DAT_300fab3c
 * ---------------------------------------------------------------- */
undefined4 loadElfRelEntryRead(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = loadModuleValueRead(param_1,param_2,4);
  if (iVar1 == -1) {
    errnoSet(DAT_300fab3c);
    return 0xffffffff;
  }
  iVar1 = loadModuleValueRead(param_1,param_2 + 4,4);
  if (iVar1 == -1) {
    errnoSet(DAT_300fab3c);
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * loadElfProgramHeaderTableReadAndCheck @ 0x300FA9A8  (примерный размер ~348 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300fa598, loadModuleSeek, loadModuleValueRead
 * Вызывают: FUN_300fa0b8
 * Константы: 0xFFFFFFFF, 0x300FA9A8
 * ---------------------------------------------------------------- */
undefined4
loadElfProgramHeaderTableReadAndCheck(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = loadModuleSeek(param_1,param_3,0);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  iVar1 = 0;
  if (0 < param_4) {
    do {
      iVar2 = loadModuleValueRead(param_1,param_2,4);
      if (iVar2 == -1) {
        iVar3 = -1;
      }
      if (iVar3 == 0) {
        iVar2 = loadModuleValueRead(param_1,param_2 + 4,4);
        if ((((iVar2 == -1) || (iVar2 = loadModuleValueRead(param_1,param_2 + 8,4), iVar2 == -1)) ||
            (iVar2 = loadModuleValueRead(param_1,param_2 + 0xc,4), iVar2 == -1)) ||
           (((iVar2 = loadModuleValueRead(param_1,param_2 + 0x10,4), iVar2 == -1 ||
             (iVar2 = loadModuleValueRead(param_1,param_2 + 0x14,4), iVar2 == -1)) ||
            ((iVar2 = loadModuleValueRead(param_1,param_2 + 0x18,4), iVar2 == -1 ||
             (iVar2 = loadModuleValueRead(param_1,param_2 + 0x1c,4), iVar2 == -1)))))) {
          iVar3 = -1;
          goto LAB_300faab8;
        }
      }
      else {
LAB_300faab8:
        if (iVar3 == -1) {
          return 0xffffffff;
        }
      }
      iVar2 = FUN_300fa598(param_2,iVar1);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      param_2 = param_2 + 0x20;
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_4);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * loadElfSectionHeaderCheck @ 0x300FAB04  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: FUN_300f9f34
 * Константы: 0x300FAB04, 0xFFFFFFFF
 * Данные: DAT_300fab40
 * ---------------------------------------------------------------- */
undefined4 loadElfSectionHeaderCheck(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x20) & *(uint *)(param_1 + 0x20) - 1) == 0) {
    uVar1 = 0;
  }
  else {
    errnoSet(DAT_300fab40);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * loadModuleInfoInit @ 0x300FAB44  (примерный размер ~260 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: bzero, calloc, errnoSet, free, lseek, strdup
 * Вызывают: loadModuleInfoFromFd, loadModuleInfoFromFilenameOpen
 * Константы: 0xFFFFFFFF, 0x300FAB44
 * Данные: DAT_300fafc0, DAT_300fafc4
 * ---------------------------------------------------------------- */
undefined4 loadModuleInfoInit(int *param_1,int param_2,char *param_3,int param_4)

{
  __off_t _Var1;
  char *pcVar2;
  void *pvVar3;
  size_t __size;
  
  if ((param_2 != 0) && (_Var1 = lseek(param_2,0,0), _Var1 == -1)) {
    return 0xffffffff;
  }
  bzero(param_1,0x24);
  *param_1 = param_2;
  if (param_4 == 0) {
    if (param_3 != (char *)0x0) {
      pcVar2 = strdup(param_3);
      param_1[1] = (int)pcVar2;
      if (pcVar2 == (char *)0x0) {
        return 0xffffffff;
      }
    }
  }
  else {
    if (param_4 != 1) {
      errnoSet(DAT_300fafc0);
      return 0xffffffff;
    }
    param_1[1] = (int)param_3;
  }
  param_1[2] = param_4;
  param_1[3] = 0;
  __size = *DAT_300fafc4;
  if (__size == 0) {
    param_1[4] = 0;
  }
  else {
    pvVar3 = calloc(1,__size);
    param_1[4] = (int)pvVar3;
    if (pvVar3 == (void *)0x0) {
      free((void *)param_1[1]);
      return 0xffffffff;
    }
  }
  param_1[7] = __size;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * loadModuleInfoRelease @ 0x300FAC48  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: close, free
 * Вызывают: loadModuleAt, loadModuleInfoFromFilenameClose
 * Константы: 0x300FAC48, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4
loadModuleInfoRelease(int param_1,void *param_2,int param_3,undefined4 param_4,void *param_5)

{
  int iVar1;
  
  free(param_5);
  if (param_3 == 0) {
    free(param_2);
  }
  else if ((param_3 == 1) && (iVar1 = close(param_1), iVar1 != 0)) {
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * loadModuleInfoFromFilenameOpen @ 0x300FACB0  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: errnoSet, loadModuleInfoInit, open
 * Константы: 0xFFFFFFFF, 0x300FACB0
 * Данные: DAT_300fafc0
 * ---------------------------------------------------------------- */
undefined4 loadModuleInfoFromFilenameOpen(char *param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    errnoSet(DAT_300fafc0);
    return 0xffffffff;
  }
  iVar1 = open(param_1,0,0);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  iVar1 = loadModuleInfoInit(param_2,iVar1,param_1,1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * loadModuleInfoFromFilenameClose @ 0x300FAD2C  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: loadModuleInfoRelease
 * Константы: 0x300FAD2C
 * ---------------------------------------------------------------- */
void loadModuleInfoFromFilenameClose(undefined4 *param_1)

{
  loadModuleInfoRelease
            (*param_1,param_1[1],param_1[2],param_1[3],param_1[4],param_1[5],param_1[6],param_1[7],
             param_1[8]);
  return;
}

/* ----------------------------------------------------------------
 * loadModuleInfoFromFd @ 0x300FAD80  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: ioctl, loadModuleInfoInit
 * Вызывают: loadModuleAt, loadSysSymTblLoad
 * Константы: 0xFFFFFFFF, 0x300FAD80
 * Данные: DAT_300fafc8
 * ---------------------------------------------------------------- */
undefined4 loadModuleInfoFromFd(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = -DAT_300fafc8;
  if (param_1 == -1) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = ioctl(param_1,0x12,&stack0xfffffff4 + iVar3);
    if (iVar2 == -1) {
      uVar1 = 0xffffffff;
    }
    else {
      iVar3 = loadModuleInfoInit(param_2,param_1,&stack0xfffffff4 + iVar3,0);
      if (iVar3 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * loadModuleSeek @ 0x300FADE8  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 9 | Вызывает: 2
 * Вызывает: errnoSet, lseek
 * Вызывают: FUN_300f91a4, FUN_300f9570, FUN_300f981c, FUN_300f9f34, FUN_300fbeac, elfArchReloc, loadElfProgramHeaderTableReadAndCheck, loadModuleAt, loadSectionsInstall
 * Константы: 0x300FADE8
 * Данные: DAT_300fafc0
 * ---------------------------------------------------------------- */
__off_t loadModuleSeek(int *param_1,__off_t param_2,int param_3)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (param_3 == 0)) {
    iVar1 = param_2 - param_1[8];
    if ((param_1[5] < iVar1) || (iVar1 < 0)) {
      param_1[5] = 0;
      param_1[6] = 0;
      param_2 = lseek(*param_1,param_2,0);
      if (param_2 == -1) {
        return -1;
      }
      param_1[8] = param_2;
    }
    else {
      param_1[6] = iVar1;
    }
    return param_2;
  }
  errnoSet(DAT_300fafc0);
  return -1;
}

/* ----------------------------------------------------------------
 * loadModuleStringRead @ 0x300FAE6C  (примерный размер ~336 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 4
 * Вызывает: bcopy, errnoSet, fioRead, read
 * Вызывают: FUN_300f91a4, FUN_300f981c, FUN_300fbeac, loadElfFileHeaderReadAndCheck
 * Константы: 0xFFFFFFFF, 0x300FAE6C
 * Данные: DAT_300fafc0
 * ---------------------------------------------------------------- */
undefined4 loadModuleStringRead(int *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint __n;
  
  if ((param_1 == (int *)0x0) || (*param_1 == -1)) {
    errnoSet(DAT_300fafc0);
    return 0xffffffff;
  }
  if (param_3 != 0) {
    uVar1 = param_1[6];
    uVar2 = param_1[5];
    if (uVar1 < uVar2) {
      __n = param_3;
      if (uVar2 - uVar1 < param_3) {
        __n = uVar2 - uVar1;
      }
      bcopy((void *)(param_1[4] + uVar1),param_2,__n);
      param_2 = (void *)((int)param_2 + __n);
      param_3 = param_3 - __n;
      param_1[6] = __n + param_1[6];
    }
    if (param_3 < (uint)param_1[7]) {
      if (param_3 != 0) {
        uVar1 = read(*param_1,(void *)param_1[4],param_1[7]);
        param_1[6] = 0;
        param_1[8] = param_1[8] + param_1[5];
        if (uVar1 == 0xffffffff) {
          param_1[5] = 0;
          return 0xffffffff;
        }
        param_1[5] = uVar1;
        if (uVar1 < param_3) {
          return 0xffffffff;
        }
        bcopy((void *)param_1[4],param_2,param_3);
        param_1[6] = param_3;
      }
    }
    else {
      param_1[5] = 0;
      param_1[6] = 0;
      uVar1 = fioRead(*param_1,param_2,param_3);
      if (uVar1 != param_3) {
        return 0xffffffff;
      }
      param_1[8] = param_3 + param_1[8];
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * loadModuleValueRead @ 0x300FAFBC  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 4
 * Вызывает: bcopy, errnoSet, fioRead, read
 * Вызывают: FUN_300f9380, FUN_300f9f34, loadElfFileHeaderReadAndCheck, loadElfProgramHeaderTableReadAndCheck, loadElfRelEntryRead, loadElfRelaEntryRead, loadSectionsInstall
 * Константы: 0xFFFFFFFF, 0x300FAFBC
 * Данные: DAT_300fafc0
 * ---------------------------------------------------------------- */
undefined4 loadModuleValueRead(int *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint __n;
  
  if ((param_1 == (int *)0x0) || (*param_1 == -1)) {
    errnoSet(DAT_300fafc0);
    return 0xffffffff;
  }
  if (param_3 != 0) {
    uVar1 = param_1[6];
    uVar2 = param_1[5];
    if (uVar1 < uVar2) {
      __n = param_3;
      if (uVar2 - uVar1 < param_3) {
        __n = uVar2 - uVar1;
      }
      bcopy((void *)(param_1[4] + uVar1),param_2,__n);
      param_2 = (void *)((int)param_2 + __n);
      param_3 = param_3 - __n;
      param_1[6] = __n + param_1[6];
    }
    if (param_3 < (uint)param_1[7]) {
      if (param_3 != 0) {
        uVar1 = read(*param_1,(void *)param_1[4],param_1[7]);
        param_1[6] = 0;
        param_1[8] = param_1[8] + param_1[5];
        if (uVar1 == 0xffffffff) {
          param_1[5] = 0;
          return 0xffffffff;
        }
        param_1[5] = uVar1;
        if (uVar1 < param_3) {
          return 0xffffffff;
        }
        bcopy((void *)param_1[4],param_2,param_3);
        param_1[6] = param_3;
      }
    }
    else {
      param_1[5] = 0;
      param_1[6] = 0;
      uVar1 = fioRead(*param_1,param_2,param_3);
      if (uVar1 != param_3) {
        return 0xffffffff;
      }
      param_1[8] = param_3 + param_1[8];
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * loadLibInit @ 0x300FAFCC  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrLoaderInit
 * Константы: 0x300FAFCC
 * Данные: DAT_300fbdec
 * ---------------------------------------------------------------- */
undefined4 loadLibInit(undefined4 param_1)

{
  *DAT_300fbdec = param_1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300fafdc @ 0x300FAFDC  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: FUN_300fb05c
 * Константы: 0xFFFFFFFF, 0x300FAFDC
 * Данные: DAT_300fbdf0, DAT_300fbdf4, DAT_300fbdf8
 * ---------------------------------------------------------------- */
undefined4 FUN_300fafdc(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 & DAT_300fbdf0) == 0) {
    if (((((param_1 & 6) == 6) || ((param_1 & 10) == 10)) || ((param_1 & 0xe) == 0xe)) ||
       ((((param_1 & 0x500) == 0x500 || ((param_1 & 0x300) == 0x300)) ||
        ((param_1 & 0x30000) == 0x30000)))) {
      errnoSet(DAT_300fbdf8);
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    errnoSet(DAT_300fbdf4);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300fb05c @ 0x300FB05C  (примерный размер ~536 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 8
 * Вызывает: FUN_300fafdc, cplusLoadFixup, errnoGet, errnoSet, moduleCreate, printErr, taskSafe, taskUnsafe
 * Вызывают: loadModuleAt, loadSysSymTblLoad
 * Константы: 0x300FB05C
 * Данные: DAT_300fbdfc, DAT_300fbe00, DAT_300fbe04, DAT_300fbe08, DAT_300fbe0c, DAT_300fbe10, DAT_300fbe14, DAT_300fbe18
 * ---------------------------------------------------------------- */
int FUN_300fb05c(int param_1,uint param_2,int *param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  int local_28;
  
  uVar3 = 2;
  local_28 = 0;
  uVar4 = 0;
  *param_3 = 0;
  if (param_2 == 0) {
    param_2 = 8;
    iVar1 = param_1;
  }
  else {
    iVar1 = FUN_300fafdc(param_2);
    if (iVar1 != 0) {
      return -1;
    }
  }
  if (*DAT_300fbdfc == 0) {
    errnoSet(DAT_300fbe00);
    return -1;
  }
  if (param_1 == 0) {
    printErr(DAT_300fbe04);
    return -1;
  }
  taskSafe(iVar1);
  iVar1 = moduleCreate(*(undefined4 *)(param_1 + 4),0,param_2);
  *param_3 = iVar1;
  if (iVar1 == 0) {
    taskUnsafe();
    return -1;
  }
  iVar1 = (*(code *)*DAT_300fbdfc)(param_1,param_2,param_5,param_4,iVar1,&local_28);
  if (iVar1 == -1) {
    uVar4 = errnoGet();
  }
  if ((code *)*DAT_300fbe08 != (code *)0x0) {
    (*(code *)*DAT_300fbe08)(*param_3,param_2);
  }
  if (iVar1 == 0) {
    if (((param_2 & 0x20) != 0) || (*(int *)(param_1 + 0xc) == 1)) goto LAB_300fb224;
    bVar5 = local_28 == 0;
    if (bVar5) {
      if ((param_2 & 0x1000) != 0) {
        uVar3 = 0;
      }
      bVar5 = (param_2 & 0x2000) == 0;
    }
    if (!bVar5) {
      uVar3 = 1;
    }
    iVar2 = cplusLoadFixup(*param_3,*DAT_300fbe0c,uVar3);
    if (iVar2 != 0) {
      uVar4 = errnoGet();
      iVar1 = -1;
    }
  }
  if (iVar1 == -1) {
    if ((code *)*DAT_300fbe10 != (code *)0x0) {
      (*(code *)*DAT_300fbe10)(*param_3,0);
    }
    *param_3 = 0;
    taskUnsafe();
    errnoSet(uVar4);
    return -1;
  }
LAB_300fb224:
  if (local_28 != 0) {
    iVar1 = -1;
    uVar4 = DAT_300fbe14;
  }
  taskUnsafe();
  if ((code *)*DAT_300fbe18 != (code *)0x0) {
    (*(code *)*DAT_300fbe18)(*param_3);
  }
  if (iVar1 == -1) {
    errnoSet(uVar4);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300fb274 @ 0x300FB274  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: loadModuleAt, loadSysSymTblLoad
 * Константы: 0xFFFFFFFF, 0x300FB274
 * ---------------------------------------------------------------- */
void FUN_300fb274(int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  bool bVar2;
  
  *param_4 = 2;
  bVar2 = param_1 == (int *)0x0;
  if (bVar2) {
    param_4[1] = 0xffffffff;
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
    param_4[1] = iVar1;
    bVar2 = iVar1 == -1;
    if (!bVar2) {
      iVar1 = 1;
    }
  }
  if (bVar2) {
    iVar1 = 0;
  }
  param_4[2] = iVar1;
  param_4[3] = 4;
  bVar2 = param_2 == (int *)0x0;
  if (bVar2) {
    param_4[4] = 0xffffffff;
    iVar1 = 0;
  }
  else {
    iVar1 = *param_2;
    param_4[4] = iVar1;
    bVar2 = iVar1 == -1;
    if (!bVar2) {
      iVar1 = 1;
    }
  }
  if (bVar2) {
    iVar1 = 0;
  }
  param_4[5] = iVar1;
  param_4[6] = 8;
  bVar2 = param_3 == (int *)0x0;
  if (bVar2) {
    param_4[7] = 0xffffffff;
    iVar1 = 0;
  }
  else {
    iVar1 = *param_3;
    param_4[7] = iVar1;
    bVar2 = iVar1 == -1;
    if (!bVar2) {
      iVar1 = 1;
    }
  }
  if (bVar2) {
    iVar1 = 0;
  }
  param_4[8] = iVar1;
  return;
}

/* ----------------------------------------------------------------
 * loadModuleAt @ 0x300FB308  (примерный размер ~396 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_300fb05c, FUN_300fb274, errnoGet, errnoSet, loadModuleInfoFromFd, loadModuleInfoRelease, loadModuleSeek, moduleSegInfoGet
 * Вызывают: loadModule
 * Константы: 0x300FB308
 * Данные: DAT_300fbe1c
 * ---------------------------------------------------------------- */
int loadModuleAt(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5
                )

{
  int iVar1;
  undefined4 uVar2;
  int local_8c;
  undefined1 auStack_88 [4];
  undefined4 local_84;
  undefined4 local_78;
  undefined4 local_6c;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  
  uVar2 = 0;
  if (param_1 == -1) {
    errnoSet(DAT_300fbe1c);
    local_8c = 0;
  }
  else {
    iVar1 = loadModuleInfoFromFd(param_1,&local_64);
    if (iVar1 == 0) {
      iVar1 = loadModuleSeek(&local_64,0,0);
      if (iVar1 == -1) {
        local_8c = 0;
      }
      else {
        if (param_2 == -1) {
          param_2 = 2;
        }
        else if (param_2 == 0) {
          param_2 = 8;
        }
        else if (param_2 == 1) {
          param_2 = 0xc;
        }
        FUN_300fb274(param_3,param_4,param_5,auStack_88);
        local_58 = 5;
        iVar1 = FUN_300fb05c(&local_64,param_2,&local_8c,3,auStack_88);
        if (iVar1 != 0) {
          uVar2 = errnoGet();
        }
        if (local_8c != 0) {
          moduleSegInfoGet(local_8c,&local_40);
          local_84 = local_40;
          local_78 = local_3c;
          local_6c = local_38;
        }
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = local_84;
        }
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = local_78;
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = local_6c;
        }
        loadModuleInfoRelease
                  (local_64,local_60,local_5c,local_58,local_54,local_50,local_4c,local_48,local_44)
        ;
        if (iVar1 != 0) {
          errnoSet(uVar2);
          local_8c = 0;
        }
      }
    }
    else {
      local_8c = 0;
    }
  }
  return local_8c;
}

/* ----------------------------------------------------------------
 * loadModule @ 0x300FB494  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: loadModuleAt
 * Вызывают: reld, usrModuleLoad
 * Константы: 0x300FB494, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void loadModule(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_8 [2];
  
  local_8[0] = 0xffffffff;
  loadModuleAt(param_1,param_2,local_8,local_8,local_8);
  return;
}

/* ----------------------------------------------------------------
 * loadSysSymTblLoad @ 0x300FB4C0  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300fb05c, FUN_300fb274, loadModuleInfoFromFd
 * Константы: 0xFFFFFFFF, 0x300FB4C0
 * Данные: DAT_300fbe20
 * ---------------------------------------------------------------- */
undefined4 loadSysSymTblLoad(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_54;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  undefined1 auStack_2c [36];
  
  iVar1 = loadModuleInfoFromFd(param_1,auStack_50);
  if (iVar1 == 0) {
    local_44 = 1;
    FUN_300fb274(0,0,0,auStack_2c);
    FUN_300fb05c(auStack_50,(uint)(param_2 != 0) * 4 + 8 | DAT_300fbe20,&local_54,3,auStack_2c);
    if (local_54 == 0) {
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
 * loadSegInfoDescAllocate @ 0x300FB548  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: calloc, sllInit, sllPutAtTail
 * Вызывают: FUN_300fa0b8
 * Константы: 0x300FB548, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4
loadSegInfoDescAllocate(undefined4 param_1,undefined4 param_2,undefined4 *param_3,size_t param_4)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  pvVar1 = calloc(param_4,0x2c);
  if (pvVar1 == (void *)0x0) {
    return 0xffffffff;
  }
  sllInit(param_1);
  if (param_4 != 0) {
    do {
      sllPutAtTail(param_1,pvVar1);
      sllInit((int)pvVar1 + 4);
      param_4 = param_4 - 1;
      *(undefined4 *)((int)pvVar1 + 0xc) = *param_3;
      puVar2 = param_3 + 2;
      *(undefined4 *)((int)pvVar1 + 0x10) = param_3[1];
      param_3 = param_3 + 3;
      *(undefined4 *)((int)pvVar1 + 0x24) = *puVar2;
      pvVar1 = (void *)((int)pvVar1 + 0x2c);
    } while (param_4 != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * loadSegInfoDescFree @ 0x300FB5C8  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: free, sllGet
 * Вызывают: FUN_300fa0b8
 * Константы: 0x300FB5C8
 * ---------------------------------------------------------------- */
undefined4 loadSegInfoDescFree(undefined4 *param_1)

{
  void *__ptr;
  undefined4 *puVar1;
  
  if ((param_1 != (undefined4 *)0x0) &&
     (param_1 = (undefined4 *)*param_1, puVar1 = param_1, param_1 != (undefined4 *)0x0)) {
    do {
      while (__ptr = (void *)sllGet(puVar1 + 1), __ptr != (void *)0x0) {
        free(__ptr);
      }
      puVar1 = (undefined4 *)*puVar1;
    } while (puVar1 != (undefined4 *)0x0);
    if (param_1 != (undefined4 *)0x0) {
      free(param_1);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * loadSegmentsAllocate @ 0x300FB620  (примерный размер ~932 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: errnoSet, loadShareTgtMemAlign, moduleSectionRegister, moduleSegAdd
 * Вызывают: FUN_300fa0b8
 * Константы: 0xFFFFFFFF, 0x300FB620, 0xFFFFFFFC
 * Данные: DAT_300fbe24, DAT_300fbe28
 * ---------------------------------------------------------------- */
undefined4 loadSegmentsAllocate(undefined4 param_1,uint param_2,int *param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 *puVar18;
  
  if (*(code **)(DAT_300fbe24 + 0x20) == (code *)0x0) {
    uVar15 = 0xffffffff;
  }
  else {
    uVar15 = (**(code **)(DAT_300fbe24 + 0x20))();
  }
  uVar17 = 0;
  bVar3 = false;
  piVar8 = (int *)*param_3;
  uVar10 = 0;
  uVar16 = 0;
  for (piVar12 = piVar8; piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {
    uVar11 = 4;
    piVar12[8] = 4;
    uVar6 = uVar16;
    uVar13 = uVar10;
    if (piVar12[9] == 0) {
      piVar12[10] = 0;
      for (puVar5 = (undefined4 *)piVar12[1]; puVar5 != (undefined4 *)0x0;
          puVar5 = (undefined4 *)*puVar5) {
        uVar13 = puVar5[5];
        if ((uVar13 != 0) && (uVar11 < uVar13)) {
          uVar11 = uVar13;
        }
        if (puVar5[4] != 0) {
          piVar12[10] = 1;
        }
      }
      iVar14 = piVar12[3];
      if (((iVar14 == 2) && (*(int *)(DAT_300fbe24 + 0xc) != 0)) && (piVar12[4] == -1)) {
        bVar3 = true;
      }
      piVar12[8] = uVar11;
      uVar13 = uVar11;
      if (((iVar14 != 2) && (uVar6 = uVar11, uVar13 = uVar10, iVar14 != 4)) &&
         (uVar6 = uVar16, iVar14 == 8)) {
        uVar17 = uVar11;
      }
    }
    uVar10 = uVar13;
    uVar16 = uVar6;
  }
  uVar6 = 0;
  bVar1 = false;
  iVar14 = 0;
  bVar2 = false;
  if ((bVar3) && (uVar15 == 0xffffffff)) {
    uVar4 = 0xffffffff;
  }
  else {
    if (uVar17 <= uVar16) {
      uVar17 = uVar16;
    }
    if ((bVar3) && (uVar17 < uVar15)) {
      uVar17 = uVar15;
    }
    uVar16 = uVar17;
    if (uVar17 <= uVar10) {
      uVar16 = uVar10;
    }
    if ((bVar3) && (uVar16 < uVar15)) {
      uVar16 = uVar15;
    }
    for (; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
      uVar10 = uVar16;
      if ((piVar8[3] == 2) || (uVar10 = uVar17, piVar8[3] == 4)) {
        piVar8[8] = uVar10;
      }
      if ((piVar8[9] == 0) && (piVar8[10] != 0)) {
        uVar6 = (uVar6 + piVar8[8]) - 1 & ~(piVar8[8] - 1U);
      }
      iVar9 = 0;
      for (puVar5 = (undefined4 *)piVar8[1]; puVar5 != (undefined4 *)0x0;
          puVar5 = (undefined4 *)*puVar5) {
        iVar7 = puVar5[5];
        if (iVar7 == 0) {
          uVar10 = iVar9 + 3U & 0xfffffffc;
        }
        else {
          uVar10 = (iVar9 + iVar7) - 1U & ~(iVar7 - 1U);
        }
        puVar5[8] = uVar10;
        iVar9 = uVar10 + puVar5[4];
      }
      piVar8[5] = iVar9;
      if ((((param_2 & 0x40) != 0) && (iVar9 != 0)) && (piVar8[4] == -1)) {
        errnoSet(DAT_300fbe28);
        return 0xffffffff;
      }
      if (piVar8[9] == 0) {
        piVar8[7] = uVar6;
        if ((bVar3) && (piVar8[3] == 2)) {
          uVar6 = uVar6 + ((uVar15 + iVar9) - 1 & ~(uVar15 - 1));
        }
        else {
          uVar6 = uVar6 + iVar9;
        }
      }
    }
    if ((uVar6 == 0) || (iVar14 = loadShareTgtMemAlign(uVar16), iVar14 != 0)) {
      for (puVar5 = (undefined4 *)*param_3; puVar5 != (undefined4 *)0x0;
          puVar5 = (undefined4 *)*puVar5) {
        if (puVar5[9] == 0) {
          puVar5[4] = iVar14 + puVar5[7];
          if (bVar2) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
            bVar2 = bVar1;
          }
        }
        iVar7 = puVar5[4];
        iVar9 = moduleSegAdd(param_1,puVar5[3],iVar7,puVar5[5],bVar1);
        if (iVar9 != 0) {
          return 0xffffffff;
        }
        for (puVar18 = (undefined4 *)puVar5[1]; puVar18 != (undefined4 *)0x0;
            puVar18 = (undefined4 *)*puVar18) {
          iVar9 = iVar7 + puVar18[8];
          puVar18[7] = iVar9;
          iVar9 = moduleSectionRegister
                            (param_1,puVar18[1],puVar18[2],iVar9,puVar18[4],puVar18[6],puVar18[5]);
          puVar18[10] = iVar9;
          if (iVar9 == 0) {
            return 0xffffffff;
          }
        }
      }
      uVar4 = 0;
    }
    else {
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * loadSectionsInstall @ 0x300FB9C4  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: loadModuleSeek, loadModuleValueRead, loadShareTgtMemSet
 * Вызывают: FUN_300fa0b8
 * Константы: 0xFFFFFFFF, 0x300FB9C4
 * ---------------------------------------------------------------- */
undefined4 loadSectionsInstall(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_2 & 0x40) == 0) {
    for (param_3 = (undefined4 *)*param_3; param_3 != (undefined4 *)0x0;
        param_3 = (undefined4 *)*param_3) {
      for (puVar2 = (undefined4 *)param_3[1]; puVar2 != (undefined4 *)0x0;
          puVar2 = (undefined4 *)*puVar2) {
        if (puVar2[2] == 4) {
          if ((param_2 & 0x40) == 0) {
            loadShareTgtMemSet((void *)puVar2[7],0,puVar2[4]);
          }
        }
        else {
          iVar1 = loadModuleSeek(param_1,puVar2[3],0);
          if (iVar1 == -1) {
            return 0xffffffff;
          }
          iVar1 = loadModuleValueRead(param_1,puVar2[7],puVar2[4]);
          if (iVar1 != 0) {
            return 0xffffffff;
          }
        }
      }
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * loadDefinedSymbolProcess @ 0x300FBD34  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300fbbc0
 * Вызывают: FUN_300f9570
 * Константы: 0x300FBD34
 * ---------------------------------------------------------------- */
void loadDefinedSymbolProcess(void)

{
  FUN_300fbbc0();
  return;
}

/* ----------------------------------------------------------------
 * loadCommonSymbolProcess @ 0x300FBD68  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300fbbc0
 * Вызывают: FUN_300f9570
 * Константы: 0x300FBD68
 * ---------------------------------------------------------------- */
void loadCommonSymbolProcess
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  FUN_300fbbc0(param_1,0,param_2,param_3,0x31,param_4,param_5,param_6);
  return;
}

/* ----------------------------------------------------------------
 * loadUndefinedSymbolProcess @ 0x300FBDA4  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300fba98, FUN_300fbaf8, moduleUndefSymAdd
 * Вызывают: FUN_300f9570
 * Константы: 0x300FBDA4
 * ---------------------------------------------------------------- */
void loadUndefinedSymbolProcess(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_300fba98();
  if (iVar1 == 0) {
    moduleUndefSymAdd(param_3,param_1);
    *param_2 = 0;
    *(undefined1 *)(param_2 + 1) = 0;
    param_2[2] = 0;
    return;
  }
  FUN_300fbaf8(iVar1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300fbe34 @ 0x300FBE34  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: snprintf, strncpy, tagCheckModuleAdd
 * Вызывают: FUN_300fbfdc
 * Константы: 0x300FBE34, 0xFFFFFFFF
 * Данные: DAT_300fc1cc, DAT_300fc1d0
 * ---------------------------------------------------------------- */
undefined4 FUN_300fbe34(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_8c [127];
  undefined1 local_d;
  
  if (*(int *)(param_2 + 0xc) == 1) {
    strncpy(acStack_8c,DAT_300fc1cc,0x80);
  }
  else if (*(int *)(param_2 + 0xc) == 2) {
    snprintf(acStack_8c,0x80,DAT_300fc1d0,param_1 + 0x18,param_1);
  }
  local_d = 0;
  iVar1 = tagCheckModuleAdd(acStack_8c);
  *(int *)(param_2 + 4) = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

