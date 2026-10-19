/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 9 (функций: 150, адреса 0x300C9C50..0x300D6774)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * fsmUnmountHookRun @ 0x300C9C50  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C9C50
 * Данные: DAT_300c9cc8
 * ---------------------------------------------------------------- */
void fsmUnmountHookRun(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 4;
  puVar1 = DAT_300c9cc8;
  do {
    puVar1 = puVar1 + 1;
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)(param_1);
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* ----------------------------------------------------------------
 * print64 @ 0x300C9CCC  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 4
 * Вызывает: __div64, __udiv32, __urem32, printf
 * Вызывают: print64Fine, print64Mult, print64Row
 * Константы: 0x300C9CCC
 * Данные: DAT_300c9f6c, DAT_300c9f70, DAT_300c9f74
 * ---------------------------------------------------------------- */
void print64(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  char cVar1;
  int iVar2;
  char *__format;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined8 uVar7;
  byte local_27 [3];
  
  uVar7 = CONCAT44(param_3,param_2);
  pbVar6 = local_27;
  if (param_5 == 0) {
    param_5 = 10;
  }
  bVar3 = 0x20;
  if (param_5 == 2) {
LAB_300c9d24:
    bVar3 = 0x2e;
  }
  else {
    if ((param_5 != 10) && (__format = DAT_300c9f6c, param_5 != 0x10)) goto LAB_300c9e14;
    if (param_5 == 0x10) goto LAB_300c9d24;
    if (param_5 == 10) {
      bVar3 = 0x2c;
    }
  }
  if (param_6 == 0) {
    param_6 = -1;
  }
  if (param_1 != 0) {
    printf(DAT_300c9f70,param_1);
  }
  if (param_3 + param_2 == 0) {
    printf(DAT_300c9f74);
  }
  else {
    local_27[0] = 0;
    iVar4 = 1;
    do {
      pbVar5 = pbVar6 + -1;
      cVar1 = __urem32((int)uVar7,param_5);
      *pbVar5 = cVar1 + 0x30U;
      if (0x39 < (byte)(cVar1 + 0x30U)) {
        *pbVar5 = cVar1 + 0x57;
      }
      iVar2 = __udiv32(iVar4,param_6);
      if (iVar4 == param_6 * iVar2) {
        pbVar6[-2] = bVar3;
        pbVar5 = pbVar6 + -2;
      }
      pbVar6 = pbVar5;
      uVar7 = __div64((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),param_5,0);
      iVar4 = iVar4 + 1;
    } while ((int)((ulonglong)uVar7 >> 0x20) + (int)uVar7 != 0);
    if (*pbVar6 == bVar3) {
      pbVar6 = pbVar6 + 1;
    }
    printf(DAT_300c9f70,pbVar6);
  }
  __format = DAT_300c9f70;
  param_5 = param_4;
  if (param_4 == 0) {
    return;
  }
LAB_300c9e14:
  printf(__format,param_5);
  return;
}

/* ----------------------------------------------------------------
 * print64Fine @ 0x300C9E20  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: print64
 * Вызывают: FUN_300dbe68, FUN_300dc11c, FUN_300dc4fc, dosFsShow
 * Константы: 0x300C9E20
 * ---------------------------------------------------------------- */
void print64Fine(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                int param_5)

{
  undefined4 uVar1;
  
  if (param_5 == 2) {
    uVar1 = 4;
  }
  else {
    uVar1 = 0;
    if (param_5 == 10) {
      uVar1 = 3;
    }
  }
  print64(param_1,param_2,param_3,param_4,param_5,uVar1);
  return;
}

/* ----------------------------------------------------------------
 * print64Row @ 0x300C9E68  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: print64
 * Константы: 0x300C9E68
 * ---------------------------------------------------------------- */
void print64Row(void)

{
  print64();
  return;
}

/* ----------------------------------------------------------------
 * print64Mult @ 0x300C9E8C  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: __div64, print64, printf
 * Вызывают: FUN_300dc4fc, dosFsShow
 * Константы: 0x00100000, 0x300C9E8C, 0xFFFFFFFF
 * Данные: DAT_300c9f70, DAT_300c9f78
 * ---------------------------------------------------------------- */
void print64Mult(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined1 in_CY;
  char in_OV;
  bool bVar4;
  longlong lVar5;
  
  iVar2 = DAT_300c9f78;
  lVar1 = CONCAT44(param_3,param_2);
  bVar4 = param_3 == 0;
  iVar3 = 0;
  if (bVar4) {
LAB_300c9ec0:
    if (bVar4) {
      in_CY = 0xfffff < param_2;
    }
    lVar5 = lVar1;
    if (!(bool)in_CY || bVar4 && param_2 == 0x100000) goto LAB_300c9f20;
  }
  else {
    lVar5 = CONCAT44(param_3,param_2);
    if (bVar4 || param_3 < 0 != (bool)in_OV) {
      lVar5 = lVar1;
      if (bVar4 || param_3 < 0 != (bool)in_OV) goto LAB_300c9f20;
      goto LAB_300c9ec0;
    }
  }
LAB_300c9ed0:
  do {
    if (*(int *)(iVar2 + iVar3 * 4 + 4) == 0) break;
    iVar3 = iVar3 + 1;
    lVar5 = __div64((int)lVar5,(int)((ulonglong)lVar5 >> 0x20),0x400,0);
    bVar4 = (int)((ulonglong)lVar5 >> 0x20) != 0;
    if (bVar4) {
      if (lVar5 < 0x100000000) break;
      if (0xffffffff < lVar5) goto LAB_300c9ed0;
    }
  } while (bVar4 || 0x100000 < (uint)lVar5);
LAB_300c9f20:
  print64(param_1,(int)lVar5,(int)((ulonglong)lVar5 >> 0x20),*(undefined4 *)(iVar2 + iVar3 * 4),10,3
         );
  if (param_4 != 0) {
    printf(DAT_300c9f70,param_4);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300c9f7c @ 0x300C9F7C  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: errnoSet, xbdIoctl
 * Вызывают: FUN_300ca014, FUN_300ca570
 * Константы: 0x300C9F7C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300c9f7c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = xbdIoctl(*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x2c),0x15,0);
  if ((iVar1 == 0x23) || (iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    errnoSet(iVar1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300c9fc0 @ 0x300C9FC0  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: lstAdd, lstDelete, semGive, semTake
 * Вызывают: FUN_300ca014, FUN_300ca3dc
 * Константы: 0xFFFFFFFF, 0x300C9FC0
 * Данные: DAT_300ca7b0, DAT_300ca7b4, DAT_300ca7b8
 * ---------------------------------------------------------------- */
void FUN_300c9fc0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_300ca7b0;
  semTake(*DAT_300ca7b0,0xffffffff);
  *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
  lstDelete(DAT_300ca7b4,param_1);
  lstAdd(DAT_300ca7b8,param_1);
  semGive(*puVar1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ca014 @ 0x300CA014  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300c9f7c, FUN_300c9fc0, errnoSet, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300CA014
 * Данные: DAT_300ca7bc, DAT_300ca7c0, DAT_300ca7c4
 * ---------------------------------------------------------------- */
undefined4 FUN_300ca014(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((param_1 != 0) && (iVar2 = *(int *)(param_1 + 0x10), iVar2 != 0)) &&
     (*(int *)(iVar2 + 0x20) == DAT_300ca7bc)) {
    semTake(*(undefined4 *)(param_1 + 8),0xffffffff);
    if (*(int *)(param_1 + 0xc) == 1) {
      FUN_300c9fc0(param_1);
      semGive(*(undefined4 *)(param_1 + 8));
      errnoSet(DAT_300ca7c4);
      return 0xffffffff;
    }
    semTake(*(undefined4 *)(iVar2 + 0x28),0xffffffff);
    uVar1 = FUN_300c9f7c(param_1);
    semGive(*(undefined4 *)(iVar2 + 0x28));
    FUN_300c9fc0(param_1);
    semGive(*(undefined4 *)(param_1 + 8));
    return uVar1;
  }
  errnoSet(DAT_300ca7c0);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * rawFsInit @ 0x300CA0C0  (примерный размер ~328 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 8
 * Вызывает: bzero, free, iosDrvInstall, lstAdd, malloc, semGive, semMCreate, semTake
 * Вызывают: rawFsDevInit, usrIosExtraInit
 * Константы: 0xFFFFFFFF, 0x300CA0C0
 * Данные: DAT_300ca7b0, DAT_300ca7b8, DAT_300ca7c8, DAT_300ca7cc, DAT_300ca7d0, DAT_300ca7d4, DAT_300ca7d8, DAT_300ca7dc
 * ---------------------------------------------------------------- */
undefined4 rawFsInit(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  void *__s;
  int iVar4;
  
  if (*DAT_300ca7c8 == -1) {
    if (param_1 < 1) {
      param_1 = 10;
    }
    iVar3 = iosDrvInstall(DAT_300ca7d0,0,DAT_300ca7d0,DAT_300ca7dc,DAT_300ca7cc,DAT_300ca7d4,
                          DAT_300ca7d8);
    *DAT_300ca7c8 = iVar3;
    if (iVar3 == -1) {
      return 0xffffffff;
    }
    iVar3 = semMCreate(*DAT_300ca7e0);
    piVar1 = DAT_300ca7b0;
    *DAT_300ca7b0 = iVar3;
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    semTake(iVar3,0xffffffff);
    __s = malloc(param_1 * 0x28);
    if (__s == (void *)0x0) {
      return 0xffffffff;
    }
    bzero(__s,param_1 * 0x28);
    iVar3 = 0;
    piVar1[1] = param_1;
    uVar2 = DAT_300ca7b8;
    if (0 < param_1) {
      do {
        *(undefined4 *)((int)__s + 0xc) = 0xffffffff;
        iVar4 = semMCreate(*DAT_300ca7e4);
        *(int *)((int)__s + 8) = iVar4;
        if (iVar4 == 0) {
          free(__s);
          return 0;
        }
        lstAdd(uVar2,__s);
        __s = (void *)((int)__s + 0x28);
        iVar3 = iVar3 + 1;
      } while (iVar3 < piVar1[1]);
    }
    piVar1[2] = (int)__s;
    semGive(*piVar1);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * rawFsDevInit @ 0x300CA208  (примерный размер ~468 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 20
 * Вызывает: bio_alloc, bio_free, bzero, erfHandlerRegister, erfHandlerUnregister, errnoSet, free, fsPathAddedEventRaise, iosDevDelCallback, iosDevReplaceExt, iosLock, iosUnlock, malloc, rawFsInit
 *           ...
 * Вызывают: FUN_300c9698
 * Константы: 0x300CA208
 * Данные: DAT_300ca7bc, DAT_300ca7c8, DAT_300ca7e8, DAT_300ca7ec, DAT_300ca7f0, DAT_300ca7f4, DAT_300ca7f8, DAT_300ca7fc
 * ---------------------------------------------------------------- */
void * rawFsDevInit(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *__s;
  
  iVar2 = rawFsInit(0);
  if ((iVar2 != -1) && (__s = malloc(0x74), __s != (void *)0x0)) {
    bzero(__s,0x74);
    *(undefined4 *)((int)__s + 0x20) = DAT_300ca7bc;
    *(undefined4 *)((int)__s + 0x2c) = param_2;
    iVar2 = xbdBlockSize(param_2,(int)__s + 100);
    if ((iVar2 == 0) && (iVar2 = xbdNBlocks(param_2,(int)__s + 0x68), iVar2 == 0)) {
      iVar2 = semMCreate(*DAT_300ca7e8);
      *(int *)((int)__s + 0x28) = iVar2;
      if (iVar2 != 0) {
        iVar2 = semBCreate(0,0);
        *(int *)((int)__s + 0x70) = iVar2;
        if (iVar2 != 0) {
          iVar2 = bio_alloc(param_2,1);
          *(int *)((int)__s + 0x44) = iVar2;
          if (iVar2 != 0) {
            iosLock();
            iVar2 = iosDevReplaceExt(__s,param_1,*DAT_300ca7c8);
            if (iVar2 == 0) {
              iosDevDelCallback(__s,DAT_300ca7ec);
              uVar1 = DAT_300ca7f0;
              iVar2 = erfHandlerRegister(*DAT_300ca7f4,*DAT_300ca7f8,DAT_300ca7f0,__s,0);
              if (iVar2 == 0) {
                iVar2 = erfHandlerRegister(*DAT_300ca7f4,*DAT_300ca7fc,uVar1,__s,0);
                if (iVar2 == 0) {
                  iosUnlock();
                  xbdIoctl(param_2,DAT_300ca800,0);
                  fsPathAddedEventRaise(param_1);
                  return __s;
                }
                erfHandlerUnregister(*DAT_300ca7f4,*DAT_300ca7f8,uVar1,__s);
              }
            }
            iosUnlock();
            bio_free(*(undefined4 *)((int)__s + 0x44));
          }
          semDelete(*(undefined4 *)((int)__s + 0x70));
        }
        semDelete(*(undefined4 *)((int)__s + 0x28));
      }
    }
    else {
      errnoSet(iVar2);
    }
    free(__s);
  }
  fsPathAddedEventRaise(param_1);
  return (void *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_300ca3dc @ 0x300CA3DC  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_300c9fc0, bio_free, free, lstFirst, lstNext, semDelete, semGive, semTake
 * Константы: 0x300CA3DC, 0xFFFFFFFF
 * Данные: DAT_300ca7b0, DAT_300ca7b4
 * ---------------------------------------------------------------- */
void FUN_300ca3dc(void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = DAT_300ca7b0;
  semTake(*DAT_300ca7b0,0xffffffff);
  iVar2 = lstFirst(DAT_300ca7b4);
  while (iVar3 = iVar2, iVar3 != 0) {
    iVar2 = lstNext(iVar3);
    if (*(void **)(iVar3 + 0x10) == param_1) {
      FUN_300c9fc0(iVar3);
    }
  }
  semGive(*puVar1);
  bio_free(*(undefined4 *)((int)param_1 + 0x44));
  semDelete(*(undefined4 *)((int)param_1 + 0x70));
  semDelete(*(undefined4 *)((int)param_1 + 0x28));
  free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ca46c @ 0x300CA46C  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: erfHandlerUnregister, iosDevDelete, iosDevSuspend
 * Константы: 0x300CA46C
 * Данные: DAT_300ca7f0, DAT_300ca7f4, DAT_300ca7f8, DAT_300ca7fc
 * ---------------------------------------------------------------- */
void FUN_300ca46c(uint param_1,uint param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  puVar3 = DAT_300ca7f8;
  puVar2 = DAT_300ca7f4;
  uVar1 = DAT_300ca7f0;
  if (param_1 != *DAT_300ca7f4) {
    return;
  }
  if ((param_2 != *DAT_300ca7f8) && (*DAT_300ca7fc != param_2)) {
    return;
  }
  if (*(int *)(param_4 + 0x2c) != param_3) {
    return;
  }
  erfHandlerUnregister((uint)*DAT_300ca7f4,(uint)*DAT_300ca7f8,DAT_300ca7f0,param_4);
  erfHandlerUnregister(*puVar2,*DAT_300ca7fc,uVar1,param_4);
  if (*puVar3 == param_2) {
    iosDevDelete();
  }
  else {
    iosDevSuspend(param_4);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ca508 @ 0x300CA508  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: errnoSet, lstAdd, lstGet, semGive, semTake
 * Вызывают: FUN_300caa84
 * Константы: 0x300CA508, 0xFFFFFFFF
 * Данные: DAT_300ca7b0, DAT_300ca7b4, DAT_300ca7b8, DAT_300ca804
 * ---------------------------------------------------------------- */
int FUN_300ca508(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_300ca7b0;
  semTake(*DAT_300ca7b0,0xffffffff);
  iVar2 = lstGet(DAT_300ca7b8);
  if (iVar2 == 0) {
    errnoSet(DAT_300ca804);
  }
  else {
    *(undefined4 *)(iVar2 + 0xc) = 0;
    lstAdd(DAT_300ca7b4,iVar2);
  }
  semGive(*puVar1);
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300ca570 @ 0x300CA570  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 5
 * Вызывает: FUN_300c9f7c, lstFirst, lstNext, semGive, semTake
 * Вызывают: FUN_300ca5e4, rawFsVolUnmount
 * Константы: 0xFFFFFFFF, 0x300CA570
 * Данные: DAT_300ca7b0, DAT_300ca7b4
 * ---------------------------------------------------------------- */
undefined4 FUN_300ca570(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = DAT_300ca7b0;
  semTake(*DAT_300ca7b0,0xffffffff);
  iVar2 = lstFirst(DAT_300ca7b4);
  while( true ) {
    if (iVar2 == 0) {
      semGive(*puVar1);
      return 0;
    }
    if ((*(int *)(iVar2 + 0x10) == param_1) && (iVar3 = FUN_300c9f7c(iVar2), iVar3 != 0)) break;
    iVar2 = lstNext(iVar2);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300ca5e4 @ 0x300CA5E4  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300ca570, semGive, semTake
 * Константы: 0x300CA5E4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300ca5e4(int param_1)

{
  undefined4 uVar1;
  
  semTake(*(undefined4 *)(param_1 + 0x28),0xffffffff);
  uVar1 = FUN_300ca570(param_1);
  semGive(*(undefined4 *)(param_1 + 0x28));
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300ca614 @ 0x300CA614  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: FUN_300ca6d8
 * Константы: 0x300CA614, 0xFFFFFFFF
 * Данные: DAT_300ca808
 * ---------------------------------------------------------------- */
undefined4 FUN_300ca614(int param_1,undefined4 param_2,int param_3)

{
  undefined1 in_CY;
  char in_OV;
  
  if (param_3 != 0) {
    if (param_3 < 0 != (bool)in_OV) goto LAB_300ca638;
    if (param_3 < 0 == (bool)in_OV) goto LAB_300ca648;
  }
  if (param_3 == 0) {
    in_CY = true;
  }
  if ((bool)in_CY) {
LAB_300ca648:
    *(undefined4 *)(param_1 + 0x18) = param_2;
    *(int *)(param_1 + 0x1c) = param_3;
    return 0;
  }
LAB_300ca638:
  errnoSet(DAT_300ca808);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * rawFsVolUnmount @ 0x300CA658  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300ca570, lstFirst, lstNext, semGive, semTake
 * Вызывают: FUN_300ca6d8
 * Константы: 0xFFFFFFFF, 0x300CA658
 * Данные: DAT_300ca7b0, DAT_300ca7b4
 * ---------------------------------------------------------------- */
undefined4 rawFsVolUnmount(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  semTake(*(undefined4 *)(param_1 + 0x28),0xffffffff);
  FUN_300ca570(param_1);
  puVar1 = DAT_300ca7b0;
  semTake(*DAT_300ca7b0,0xffffffff);
  for (iVar2 = lstFirst(DAT_300ca7b4); iVar2 != 0; iVar2 = lstNext(iVar2)) {
    if (*(int *)(iVar2 + 0x10) == param_1) {
      *(undefined4 *)(iVar2 + 0xc) = 1;
    }
  }
  semGive(*puVar1);
  semGive(*(undefined4 *)(param_1 + 0x28));
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ca6d8 @ 0x300CA6D8  (примерный размер ~940 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_300ca614, __div64, __errno, errnoSet, rawFsVolUnmount, semGive, semTake, xbdIoctl
 * Константы: 0xFFFFFFFF, 0x300CA6D8, 0x300CA7AC
 * Данные: DAT_300ca7bc, DAT_300ca7c0, DAT_300ca7c4, DAT_300ca80c, DAT_300ca810, DAT_300cb2bc
 * ---------------------------------------------------------------- */
undefined4 FUN_300ca6d8(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if (((param_1 == 0) || (iVar6 = *(int *)(param_1 + 0x10), iVar6 == 0)) ||
     (*(int *)(iVar6 + 0x20) != DAT_300ca7bc)) {
    errnoSet(DAT_300ca7c0);
    return 0xffffffff;
  }
  iVar1 = xbdIoctl(*(undefined4 *)(iVar6 + 0x2c),DAT_300ca80c,0);
  if ((iVar1 != 0) && (iVar1 != 0x23)) {
    piVar2 = (int *)__errno();
    *piVar2 = iVar1;
    return 0xffffffff;
  }
  semTake(*(undefined4 *)(param_1 + 8),0xffffffff);
  if (*(int *)(param_1 + 0xc) == 1) {
    semGive(*(undefined4 *)(param_1 + 8));
    errnoSet(DAT_300ca7c4);
    return 0xffffffff;
  }
  if (param_2 == 0x27) {
    uVar3 = rawFsVolUnmount(*(undefined4 *)(param_1 + 0x10));
    goto LAB_300caa70;
  }
  if ((int)param_2 < 0x28) {
    if (param_2 < 0x16) {
                    /* WARNING: Could not recover jumptable at 0x300ca7ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(DAT_300ca810 + param_2 * 4))();
      return uVar3;
    }
LAB_300caa40:
    iVar6 = xbdIoctl(*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x2c),param_2,param_3);
    if (iVar6 != 0) {
      errnoSet();
      uVar3 = 0xffffffff;
      goto LAB_300caa70;
    }
  }
  else {
    if (param_2 == 0x35) {
      uVar3 = FUN_300ca614(param_1,*param_3,param_3[1]);
      goto LAB_300caa70;
    }
    if ((int)param_2 < 0x36) {
      if (param_2 == 0x2b) {
        *param_3 = *(int *)(param_1 + 0x14);
      }
      else {
        if (param_2 != 0x34) goto LAB_300caa40;
        if (param_3 == (int *)0x0) goto LAB_300ca984;
        uVar5 = *(uint *)(param_1 + 0x18);
        uVar4 = *(uint *)(param_1 + 0x20);
        iVar1 = *(int *)(param_1 + 0x1c);
        iVar6 = *(int *)(param_1 + 0x24);
        *param_3 = uVar4 - uVar5;
        param_3[1] = iVar6 - (iVar1 + (uint)(uVar4 < uVar5));
      }
    }
    else {
      if (param_2 != 0x36) {
        if (param_2 == 0x40) {
          if (param_3 == (int *)0x0) {
            uVar3 = 0xffffffff;
          }
          else {
            uVar3 = 0;
            *param_3 = iVar6;
            param_3[1] = 1;
            param_3[2] = *(int *)(param_1 + 0x14);
            param_3[3] = 1;
            param_3[4] = 0;
            param_3[5] = 0;
            iVar1 = *(int *)(param_1 + 0x24);
            param_3[6] = *(int *)(param_1 + 0x20);
            param_3[7] = iVar1;
            param_3[8] = 0;
            param_3[9] = 0;
            param_3[10] = 0;
            param_3[0xb] = *(int *)(iVar6 + 100);
            iVar6 = __div64(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),0x200,0)
            ;
            param_3[0xc] = iVar6;
            *(undefined1 *)(param_3 + 0xd) = 0;
          }
          goto LAB_300caa70;
        }
        goto LAB_300caa40;
      }
      if (param_3 == (int *)0x0) {
LAB_300ca984:
        uVar3 = 0xffffffff;
        errnoSet(DAT_300cb2bc);
        goto LAB_300caa70;
      }
      iVar6 = *(int *)(param_1 + 0x1c);
      *param_3 = *(int *)(param_1 + 0x18);
      param_3[1] = iVar6;
    }
  }
  uVar3 = 0;
LAB_300caa70:
  semGive(*(undefined4 *)(param_1 + 8));
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300caa84 @ 0x300CAA84  (примерный размер ~288 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 7
 * Вызывает: FUN_300ca508, __errno, errnoSet, semGive, semTake, xbdIoctl, xbdSize
 * Константы: 0xFFFFFFFF, 0x300CAA84, 0xFFFFF9FF
 * Данные: DAT_300cb2bc, DAT_300cb2c0, DAT_300cb2c4, DAT_300cb2c8
 * ---------------------------------------------------------------- */
int FUN_300caa84(int param_1,char *param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x20) != DAT_300cb2c0)) {
    errnoSet(DAT_300cb2bc);
    return -1;
  }
  uVar4 = *(undefined4 *)(param_1 + 0x2c);
  iVar1 = xbdIoctl(uVar4,DAT_300cb2c4,0);
  if ((iVar1 != 0) && (iVar1 != 0x23)) {
    piVar2 = (int *)__errno();
    *piVar2 = iVar1;
    return -1;
  }
  if (*(int *)(param_1 + 0x6c) + *(int *)(param_1 + 0x68) == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 2;
    return -1;
  }
  if (*param_2 != '\0') {
    errnoSet(DAT_300cb2c8);
    return -1;
  }
  iVar1 = FUN_300ca508();
  if (iVar1 == 0) {
    return -1;
  }
  semTake(*(undefined4 *)(iVar1 + 8),0xffffffff);
  semTake(*(undefined4 *)(param_1 + 0x28),0xffffffff);
  semGive(*(undefined4 *)(param_1 + 0x28));
  *(uint *)(iVar1 + 0x14) = param_3 & 0xfffff9ff;
  *(int *)(iVar1 + 0x10) = param_1;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  xbdSize(uVar4,iVar1 + 0x20);
  semGive(*(undefined4 *)(iVar1 + 8));
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300caba4 @ 0x300CABA4  (примерный размер ~316 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: __div64, __rem64
 * Вызывают: FUN_300cad40, FUN_300cb00c
 * Константы: 0x300CABA4
 * ---------------------------------------------------------------- */
uint FUN_300caba4(int param_1,uint param_2,undefined8 *param_3,int *param_4,uint *param_5,
                 int *param_6,uint *param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  undefined8 uVar8;
  
  uVar3 = *(uint *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0x1c);
  uVar1 = *(uint *)(param_1 + 0x24);
  uVar6 = *(uint *)(*(int *)(param_1 + 0x10) + 100);
  uVar2 = iVar4 + ((int)param_2 >> 0x1f) + (uint)CARRY4(uVar3,param_2);
  bVar7 = uVar2 <= uVar1;
  if (uVar1 == uVar2) {
LAB_300cac08:
    if (uVar1 == uVar2) {
      bVar7 = uVar3 + param_2 <= *(uint *)(param_1 + 0x20);
    }
    if (bVar7) goto LAB_300cac18;
  }
  else if ((int)uVar2 <= (int)uVar1) {
    if ((int)uVar2 <= (int)uVar1) goto LAB_300cac18;
    goto LAB_300cac08;
  }
  param_2 = *(uint *)(param_1 + 0x20) - uVar3;
LAB_300cac18:
  if ((int)param_2 < 1) {
    param_2 = 0;
  }
  else {
    uVar8 = __div64(uVar3,iVar4,uVar6,0);
    *param_3 = uVar8;
    iVar4 = __rem64(uVar3,iVar4,uVar6,0);
    *param_4 = iVar4;
    uVar1 = uVar6 - iVar4;
    *param_5 = uVar1;
    if (param_2 < uVar1) {
      *param_5 = param_2;
      uVar1 = 0;
      *param_6 = 0;
    }
    else {
      uVar1 = param_2 - uVar1;
      *param_6 = 0;
      if (uVar6 <= uVar1) {
        iVar4 = 0;
        do {
          iVar5 = iVar4 + 1;
          iVar4 = iVar4 + 1;
          uVar1 = uVar1 - uVar6;
        } while (uVar6 <= uVar1);
        *param_6 = iVar5;
      }
    }
    *param_7 = uVar1;
  }
  return param_2;
}

/* ----------------------------------------------------------------
 * FUN_300cace0 @ 0x300CACE0  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: semTake, xbdStrategy
 * Вызывают: FUN_300cad40, FUN_300cb00c
 * Константы: 0x300CACE0, 0xFFFFFFFF
 * Данные: DAT_300cb2cc
 * ---------------------------------------------------------------- */
undefined4
FUN_300cace0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  *(undefined4 *)(param_2 + 4) = param_3;
  *(undefined4 *)(param_2 + 8) = param_4;
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_2 + 0x18) = 0;
  *(undefined4 *)(param_2 + 0x1c) = param_5;
  *(undefined4 *)(param_2 + 0x24) = DAT_300cb2cc;
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_2 + 0x2c) = 0;
  xbdStrategy(*(undefined4 *)(param_1 + 0x2c),param_2);
  semTake(*(undefined4 *)(param_1 + 0x70),0xffffffff);
  return *(undefined4 *)(param_2 + 0x18);
}

/* ----------------------------------------------------------------
 * FUN_300cad40 @ 0x300CAD40  (примерный размер ~588 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_300caba4, FUN_300cace0, __errno, bcopy, errnoSet, semGive, semTake, xbdIoctl
 * Константы: 0xFFFFFFFF, 0xFFFFFFFE, 0x300CAD40
 * Данные: DAT_300cb2bc, DAT_300cb2c0, DAT_300cb2c4, DAT_300cb2d0
 * ---------------------------------------------------------------- */
uint FUN_300cad40(int param_1,void *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  size_t local_40;
  size_t local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int local_2c;
  
  if (((param_1 == 0) || (iVar8 = *(int *)(param_1 + 0x10), iVar8 == 0)) ||
     (*(int *)(iVar8 + 0x20) != DAT_300cb2c0)) {
    errnoSet(DAT_300cb2bc);
    return 0xffffffff;
  }
  iVar4 = iVar8 + 0x34;
  iVar1 = xbdIoctl(*(undefined4 *)(iVar8 + 0x2c),DAT_300cb2c4,0);
  if ((iVar1 != 0) && (iVar1 != 0x23)) {
    piVar2 = (int *)__errno();
    *piVar2 = iVar1;
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0x14) & 3) == 1) {
    errnoSet(DAT_300cb2d0);
    return 0xffffffff;
  }
  semTake(*(undefined4 *)(param_1 + 8),0xffffffff);
  semTake(*(undefined4 *)(iVar8 + 0x28),0xffffffff);
  uVar3 = FUN_300caba4(param_1,param_3,&local_30,&local_34,&local_40,&local_38,&local_3c);
  if (uVar3 == 0) {
    uVar3 = 0;
    goto LAB_300caf68;
  }
  iVar1 = FUN_300cace0(iVar8,iVar4,local_30,local_2c,1);
  if (iVar1 == 0) {
    bcopy((void *)(*(int *)(iVar8 + 0x44) + local_34),param_2,local_40);
    iVar6 = local_2c + (uint)(0xfffffffe < local_30);
    param_2 = (void *)((int)param_2 + local_40);
    iVar7 = local_38;
    uVar5 = local_30;
    while (uVar5 = uVar5 + 1, iVar7 != 0) {
      iVar7 = iVar7 + -1;
      iVar1 = FUN_300cace0(iVar8,iVar4,uVar5,iVar6,1);
      if (iVar1 != 0) goto LAB_300caf2c;
      bcopy(*(void **)(iVar8 + 0x44),param_2,*(size_t *)(iVar8 + 100));
      iVar6 = iVar6 + (uint)(0xfffffffe < uVar5);
      param_2 = (void *)((int)param_2 + *(int *)(iVar8 + 100));
    }
    if (local_3c != 0) {
      iVar1 = FUN_300cace0(iVar8,iVar4,uVar5,iVar6,1);
      if (iVar1 != 0) goto LAB_300caf2c;
      bcopy(*(void **)(iVar8 + 0x44),param_2,local_3c);
    }
    uVar5 = *(uint *)(param_1 + 0x18);
    *(uint *)(param_1 + 0x18) = uVar5 + uVar3;
    *(uint *)(param_1 + 0x1c) =
         *(int *)(param_1 + 0x1c) + ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar5,uVar3);
  }
  else {
LAB_300caf2c:
    errnoSet(iVar1);
    uVar3 = 0xffffffff;
  }
LAB_300caf68:
  semGive(*(undefined4 *)(param_1 + 8));
  semGive(*(undefined4 *)(iVar8 + 0x28));
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300caf8c @ 0x300CAF8C  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: semTake, xbdStrategy
 * Вызывают: FUN_300cb00c
 * Константы: 0x300CAF8C, 0xFFFFFFFF
 * Данные: DAT_300cb2cc
 * ---------------------------------------------------------------- */
undefined4
FUN_300caf8c(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_2 + 4) = param_3;
  *(undefined4 *)(param_2 + 8) = param_4;
  *(undefined4 *)(param_2 + 0x10) = param_7;
  *(int *)(param_2 + 0xc) = *(int *)(param_1 + 100) * param_6;
  *(undefined4 *)(param_2 + 0x18) = 0;
  *(undefined4 *)(param_2 + 0x1c) = param_5;
  *(undefined4 *)(param_2 + 0x24) = DAT_300cb2cc;
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_2 + 0x2c) = 0;
  xbdStrategy(*(undefined4 *)(param_1 + 0x2c),param_2);
  semTake(*(undefined4 *)(param_1 + 0x70),0xffffffff);
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_2 + 0x10) = uVar1;
  return *(undefined4 *)(param_2 + 0x18);
}

/* ----------------------------------------------------------------
 * FUN_300cb00c @ 0x300CB00C  (примерный размер ~716 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 9
 * Вызывает: FUN_300caba4, FUN_300cace0, FUN_300caf8c, __errno, bcopy, errnoSet, semGive, semTake, xbdIoctl
 * Константы: 0xFFFFFFFF, 0x300CB00C, 0xFFFFFFFE
 * Данные: DAT_300cb2bc, DAT_300cb2c0, DAT_300cb2c4, DAT_300cb2d4
 * ---------------------------------------------------------------- */
uint FUN_300cb00c(int param_1,void *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint local_48;
  size_t local_44;
  int local_40;
  size_t local_3c [2];
  uint local_34;
  int local_30;
  uint local_2c;
  int local_28;
  
  if (((param_1 == 0) || (iVar7 = *(int *)(param_1 + 0x10), iVar7 == 0)) ||
     (*(int *)(iVar7 + 0x20) != DAT_300cb2c0)) {
    errnoSet(DAT_300cb2bc);
    return 0xffffffff;
  }
  iVar6 = iVar7 + 0x34;
  iVar1 = xbdIoctl(*(undefined4 *)(iVar7 + 0x2c),DAT_300cb2c4,0);
  if ((iVar1 != 0) && (iVar1 != 0x23)) {
    piVar2 = (int *)__errno();
    *piVar2 = iVar1;
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0x14) & 3) == 0) {
    errnoSet(DAT_300cb2d4);
    return 0xffffffff;
  }
  semTake(*(undefined4 *)(param_1 + 8),0xffffffff);
  semTake(*(undefined4 *)(iVar7 + 0x28),0xffffffff);
  uVar3 = FUN_300caba4(param_1,param_3,&local_2c,&local_40,&local_44,&local_48,local_3c);
  if (uVar3 == 0) {
    uVar3 = 0;
    goto LAB_300cb29c;
  }
  if (((local_40 == 0) && (*(size_t *)(iVar7 + 100) == local_44)) ||
     (iVar1 = FUN_300cace0(iVar7,iVar6,local_2c,local_28,1), iVar1 == 0)) {
    bcopy(param_2,(void *)(*(int *)(iVar7 + 0x44) + local_40),local_44);
    param_2 = (void *)((int)param_2 + local_44);
    iVar1 = FUN_300cace0(iVar7,iVar6,local_2c,local_28,2);
    if (iVar1 == 0) {
      uVar4 = local_2c + 1;
      iVar5 = local_28 + (uint)(0xfffffffe < local_2c);
      local_34 = uVar4;
      local_30 = iVar5;
      if (local_48 != 0) {
        iVar1 = FUN_300caf8c(iVar7,iVar6,uVar4,iVar5,2,local_48,param_2);
        param_2 = (void *)(local_48 * *(int *)(iVar7 + 100) + (int)param_2);
        if (iVar1 != 0) goto LAB_300cb270;
        uVar4 = local_34 + local_48;
        iVar5 = local_30 + (uint)CARRY4(local_34,local_48);
      }
      if (local_3c[0] == 0) {
LAB_300cb280:
        uVar4 = *(uint *)(param_1 + 0x18);
        *(uint *)(param_1 + 0x18) = uVar4 + uVar3;
        *(uint *)(param_1 + 0x1c) =
             *(int *)(param_1 + 0x1c) + ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar4,uVar3);
        goto LAB_300cb29c;
      }
      iVar1 = FUN_300cace0(iVar7,iVar6,uVar4,iVar5,1);
      if (iVar1 == 0) {
        bcopy(param_2,*(void **)(iVar7 + 0x44),local_3c[0]);
        iVar1 = FUN_300cace0(iVar7,iVar6,uVar4,iVar5,2);
        if (iVar1 == 0) goto LAB_300cb280;
      }
    }
  }
LAB_300cb270:
  errnoSet(iVar1);
  uVar3 = 0xffffffff;
LAB_300cb29c:
  semGive(*(undefined4 *)(param_1 + 8));
  semGive(*(undefined4 *)(iVar7 + 0x28));
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300cb2d8 @ 0x300CB2D8  (примерный размер ~264 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: __udiv32
 * Вызывают: FUN_300cb3e0
 * Константы: 0x300CB2D8
 * ---------------------------------------------------------------- */
int FUN_300cb2d8(int param_1,int param_2,undefined4 param_3,uint param_4,int *param_5,int *param_6,
                uint *param_7,int *param_8,int *param_9)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x44);
  iVar4 = param_2 - iVar5;
  iVar1 = __udiv32(iVar4,*(undefined4 *)(param_1 + 0x4c));
  *param_5 = iVar1 + 2;
  iVar2 = *(int *)(param_1 + 0x4c);
  iVar1 = __udiv32(iVar4,iVar2);
  iVar4 = iVar4 - iVar2 * iVar1;
  *param_6 = iVar4;
  uVar3 = *(int *)(param_1 + 0x4c) - iVar4;
  if (uVar3 < param_4) {
    *param_7 = uVar3;
    iVar5 = (param_2 + param_4) - iVar5;
    iVar1 = __udiv32(iVar5,*(undefined4 *)(param_1 + 0x4c));
    *param_8 = iVar1 + 2;
    iVar4 = *(int *)(param_1 + 0x4c);
    iVar2 = __udiv32(iVar5,iVar4);
    iVar5 = iVar5 - iVar4 * iVar2;
    if (iVar5 == 0) {
      *param_8 = iVar1 + 1;
      iVar5 = *(int *)(param_1 + 0x4c);
    }
    *param_9 = iVar5;
    iVar1 = (*param_8 - *param_5) + 1;
  }
  else {
    *param_7 = param_4;
    *param_8 = 0;
    iVar1 = 1;
    *param_9 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300cb3e0 @ 0x300CB3E0  (примерный размер ~256 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300cb2d8
 * Константы: 0x300CB3E0, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
void FUN_300cb3e0(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  bool bVar1;
  bool bVar2;
  
  bVar2 = param_3 == 0;
  bVar1 = param_3 == 0;
  if (bVar1) {
LAB_300cb420:
    if (bVar1) {
      bVar2 = param_2 <= *(uint *)(param_1 + 0x7c);
    }
    if (bVar2 && (!bVar1 || *(uint *)(param_1 + 0x7c) != param_2)) goto LAB_300cb438;
  }
  else if ((int)param_3 < 0) {
    if (0x7fffffff < param_3) goto LAB_300cb438;
    goto LAB_300cb420;
  }
  bVar2 = CARRY4(param_2,*(uint *)(param_1 + 0x80));
  param_2 = param_2 + *(uint *)(param_1 + 0x80);
  param_3 = param_3 + bVar2;
LAB_300cb438:
  FUN_300cb2d8(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}

/* ----------------------------------------------------------------
 * dosFsCacheLibInit @ 0x300CB4E0  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrIosExtraInit
 * Константы: 0x300CB4E0
 * Данные: DAT_300cc454, DAT_300cc458, DAT_300cc45c, DAT_300cc460, DAT_300cc464, DAT_300cc468, DAT_300cc46c, DAT_300cc470
 * ---------------------------------------------------------------- */
void dosFsCacheLibInit(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  *DAT_300cc458 = DAT_300cc454;
  *DAT_300cc460 = DAT_300cc45c;
  *DAT_300cc468 = DAT_300cc464;
  *DAT_300cc470 = DAT_300cc46c;
  *DAT_300cc474 = param_1;
  *DAT_300cc478 = param_2;
  *DAT_300cc47c = param_3;
  return;
}

/* ----------------------------------------------------------------
 * dosFsDefaultDataDirCacheSizeGet @ 0x300CB52C  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300CB52C
 * Данные: DAT_300cc474
 * ---------------------------------------------------------------- */
undefined4 dosFsDefaultDataDirCacheSizeGet(void)

{
  return *DAT_300cc474;
}

/* ----------------------------------------------------------------
 * dosFsDefaultFatCacheSizeGet @ 0x300CB538  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300CB538
 * Данные: DAT_300cc478
 * ---------------------------------------------------------------- */
undefined4 dosFsDefaultFatCacheSizeGet(void)

{
  return *DAT_300cc478;
}

/* ----------------------------------------------------------------
 * dosFsDefaultCacheSizeSet @ 0x300CB544  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300CB544
 * Данные: DAT_300cc474, DAT_300cc478
 * ---------------------------------------------------------------- */
void dosFsDefaultCacheSizeSet(undefined4 param_1,undefined4 param_2)

{
  *DAT_300cc474 = param_1;
  *DAT_300cc478 = param_2;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cb558 @ 0x300CB558  (примерный размер ~1372 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 14
 * Вызывает: __div32, __udiv32, __urem32, bzero, cacheDmaFree, cacheDmaMalloc, dllAdd, free, malloc, printf, semBCreate, semDelete, semMCreate, spinLockTaskInit
 * Вызывают: dosFsCacheCreate, dosFsCacheTune
 * Константы: 0xFFFFFFFF, 0x300CB558
 * Данные: DAT_300cc47c, DAT_300cc5e0, DAT_300cc5e4, DAT_300cc5e8, DAT_300cc5ec, DAT_300cc5f0, DAT_300cc6f0, DAT_300cc6f4
 * ---------------------------------------------------------------- */
undefined4
FUN_300cb558(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5,uint param_6)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 uVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  size_t *__s;
  size_t local_40;
  uint local_3c;
  uint local_34;
  undefined4 local_30;
  
  iVar10 = param_2 + param_3 * 0x84;
  uVar9 = *(uint *)(iVar10 + 0x104);
  __s = (size_t *)(iVar10 + 0xc4);
  bzero(__s,0x84);
  if (param_3 == 0) {
    if (*(int *)(param_2 + 0x74) == 2) {
      local_30 = *(undefined4 *)(param_2 + 0x78);
    }
    else {
      local_30 = *(undefined4 *)(*(int *)(param_2 + 0x2c) + 0x28);
    }
    *(undefined4 *)(iVar10 + 0x108) = local_30;
    *(undefined4 *)(iVar10 + 0x10c) = 0;
    uVar1 = *(ushort *)(param_2 + 0x5e);
    if (uVar9 == 0) {
      iVar3 = __div32(0x200,(uint)uVar1);
      *(int *)(iVar10 + 0x104) = iVar3;
      if (iVar3 == 0) {
        uVar9 = 1;
        goto LAB_300cb604;
      }
    }
    else {
LAB_300cb604:
      *(uint *)(iVar10 + 0x104) = uVar9;
    }
    uVar9 = (uint)uVar1 * *(int *)(iVar10 + 0x104);
LAB_300cb664:
    *(uint *)(iVar10 + 0x110) = uVar9;
  }
  else {
    if (uVar9 == 0) {
      uVar9 = 0x20;
    }
    *(uint *)(iVar10 + 0x104) = uVar9;
    iVar3 = *(int *)(param_2 + 0x30);
    *(undefined4 *)(iVar10 + 0x108) = 0;
    *(undefined4 *)(iVar10 + 0x10c) = 0;
    if (uVar9 <= (uint)*(byte *)(param_2 + 0x62) * *(int *)(param_2 + 0x50) + *(int *)(iVar3 + 0x58)
       ) goto LAB_300cb664;
    *(undefined4 *)(iVar10 + 0x110) = 1;
    *(undefined4 *)(iVar10 + 0x104) = 1;
  }
  *(undefined4 *)(iVar10 + 0x114) = DAT_300cc5e0;
  *(undefined4 *)(iVar10 + 0x118) = DAT_300cc5e4;
  if ((*(int *)(param_2 + 0x74) != 2) && (param_3 == 0)) {
    iVar8 = *(int *)(param_2 + 0x2c);
    iVar3 = *(int *)(param_2 + 0x78);
    if ((uint)(iVar3 - *(int *)(iVar8 + 0x28)) < (uint)*(ushort *)(param_2 + 0x5e)) {
      *(undefined4 *)(iVar10 + 0x114) = DAT_300cc5e8;
      *(undefined4 *)(iVar10 + 0x118) = DAT_300cc5ec;
      *(int *)(iVar10 + 0x140) = iVar3;
      *(int *)(iVar10 + 0x144) =
           *(int *)(iVar10 + 0x110) - (*(int *)(param_2 + 0x78) - *(int *)(iVar8 + 0x28));
    }
  }
  iVar3 = *(int *)(iVar10 + 0x110) * *(int *)(param_2 + 0x1fc);
  uVar9 = iVar3 + 0x164;
  if (param_6 < uVar9) {
    printf(DAT_300cc5f0,param_1,param_4);
    return 0;
  }
  uVar4 = __udiv32(param_6,iVar3 + 0x168);
  piVar2 = DAT_300cc47c;
  iVar8 = *DAT_300cc47c;
  if (iVar8 == 0) {
    if (7 < uVar4) goto LAB_300cb77c;
    local_40 = uVar9 * uVar4;
    uVar4 = __udiv32();
    local_3c = 0;
LAB_300cb7b4:
    uVar9 = uVar4;
    if (0xf < uVar4) {
      uVar9 = uVar4 - 3;
    }
  }
  else {
    if (uVar4 < 8) {
      printf(DAT_300cc6f0,uVar4,param_1,param_4);
      return 0;
    }
LAB_300cb77c:
    iVar3 = __urem32(param_6,iVar3 + 0x168);
    local_40 = param_6 - iVar3;
    local_3c = local_40 - uVar9 * uVar4 >> 2;
    if (iVar8 == 0) goto LAB_300cb7b4;
    uVar9 = uVar4;
    if (0xf < uVar4) {
      uVar9 = __udiv32(uVar4 * 3,5);
    }
  }
  *(uint *)(iVar10 + 0xec) = uVar9;
  if (param_5 == 0) {
    iVar3 = cacheDmaMalloc(local_40);
    *(int *)(iVar10 + 200) = iVar3;
    if (iVar3 == 0) {
      printf(DAT_300cc6f4,param_4,param_1);
      return 0xffffffff;
    }
    *(undefined4 *)(iVar10 + 0xe4) = 1;
  }
  else {
    *(undefined4 *)(iVar10 + 0xe4) = 0;
    *(int *)(iVar10 + 200) = param_5;
  }
  bzero(*(void **)(iVar10 + 200),local_40);
  *(uint *)(iVar10 + 0xe0) = local_3c;
  *__s = local_40;
  iVar3 = *(int *)(iVar10 + 200);
  pvVar7 = (void *)(uVar4 * 0x164 + iVar3);
  local_34 = uVar4;
  if (0 < (int)uVar4) {
    do {
      *(undefined4 *)(iVar3 + 8) = 0;
      *(undefined4 *)(iVar3 + 0x20) = 0;
      *(undefined4 *)(iVar3 + 0x14) = 0xffffffff;
      *(void **)(iVar3 + 0x24) = pvVar7;
      *(void **)(iVar3 + 0x38) = pvVar7;
      iVar8 = semBCreate(1,0);
      *(int *)(iVar3 + 0x58) = iVar8;
      if (iVar8 == 0) goto LAB_300cb9e8;
      *(undefined2 *)(iVar3 + 0x5c) = 0xffff;
      *(undefined2 *)(iVar3 + 0x5e) = 0xffff;
      bzero((void *)(iVar3 + 0x60),0x80);
      bzero((void *)(iVar3 + 0xe0),0x80);
      if (*piVar2 != 0) {
        pvVar5 = malloc(0x90);
        *(void **)(iVar3 + 0xc) = pvVar5;
        if (pvVar5 == (void *)0x0) goto LAB_300cb9e8;
        spinLockTaskInit(pvVar5,0);
        *(undefined4 *)(iVar3 + 0x10) = 0;
        *(undefined4 *)(iVar3 + 0x18) = 0;
        uVar6 = semBCreate(1,0);
        *(undefined4 *)(iVar3 + 0x1c) = uVar6;
      }
      dllAdd(iVar10 + 0xcc,iVar3);
      iVar3 = iVar3 + 0x164;
      pvVar7 = (void *)(*(int *)(iVar10 + 0x110) * *(int *)(param_2 + 0x1fc) + (int)pvVar7);
      local_34 = local_34 - 1;
    } while (local_34 != 0);
  }
  *(void **)(iVar10 + 0xdc) = pvVar7;
  bzero(pvVar7,*(int *)(iVar10 + 0xe0) << 2);
  *(uint *)(iVar10 + 0xf8) = uVar4;
  if (*piVar2 == 0) {
    *(undefined4 *)(iVar10 + 0x11c) = DAT_300cc8e8;
    *(undefined4 *)(iVar10 + 0x120) = DAT_300cc8ec;
    uVar6 = DAT_300cc8f0;
LAB_300cb9dc:
    *(undefined4 *)(iVar10 + 0x124) = uVar6;
    return 0;
  }
  pvVar7 = malloc(0x90);
  *(void **)(iVar10 + 0x128) = pvVar7;
  if (pvVar7 != (void *)0x0) {
    spinLockTaskInit(pvVar7,0);
    uVar6 = semMCreate(9);
    *(undefined4 *)(iVar10 + 300) = uVar6;
    iVar3 = semBCreate(1,0);
    *(int *)(iVar10 + 0x134) = iVar3;
    if ((*(int *)(iVar10 + 300) != 0) && (iVar3 != 0)) {
      *(undefined4 *)(iVar10 + 0x130) = *(undefined4 *)(iVar10 + 0xcc);
      *(undefined4 *)(iVar10 + 0x11c) = DAT_300cc8dc;
      *(undefined4 *)(iVar10 + 0x120) = DAT_300cc8e0;
      uVar6 = DAT_300cc8e4;
      goto LAB_300cb9dc;
    }
  }
LAB_300cb9e8:
  iVar8 = *(int *)(iVar10 + 200);
  iVar3 = uVar4 - local_34;
  if (0 < iVar3) {
    do {
      if (*(int *)(iVar8 + 0x58) != 0) {
        semDelete(*(int *)(iVar8 + 0x58));
      }
      if (*(void **)(iVar8 + 0xc) != (void *)0x0) {
        free(*(void **)(iVar8 + 0xc));
      }
      iVar8 = iVar8 + 0x164;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (*(int *)(iVar10 + 0xe4) != 0) {
    cacheDmaFree(*(undefined4 *)(iVar10 + 200));
  }
  if (*piVar2 != 0) {
    if (*(void **)(iVar10 + 0x128) != (void *)0x0) {
      free(*(void **)(iVar10 + 0x128));
    }
    if (*(int *)(iVar10 + 300) != 0) {
      semDelete(*(int *)(iVar10 + 300));
    }
    if (*(int *)(iVar10 + 0x134) != 0) {
      semDelete(*(int *)(iVar10 + 0x134));
    }
  }
  bzero(__s,0x84);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300cbab4 @ 0x300CBAB4  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: dosFsCacheCreate
 * Константы: 0x300CBAB4
 * Данные: DAT_300cca44, DAT_300cca48, DAT_300cca4c, DAT_300cca50, DAT_300cca54, DAT_300cca58, DAT_300cca5c
 * ---------------------------------------------------------------- */
void FUN_300cbab4(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0xc4) != 0) && (*(int *)(param_1 + 200) != 0)) {
    *(undefined4 *)(param_1 + 0xb8) = DAT_300cca44;
    *(undefined4 *)(param_1 + 0xbc) = DAT_300cca48;
    uVar1 = DAT_300cca4c;
    *(undefined4 *)(param_1 + 0xb4) = DAT_300cca4c;
    uVar2 = DAT_300cca50;
    *(undefined4 *)(param_1 + 0xc0) = DAT_300cca50;
    iVar3 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar3 + 0x20) = uVar1;
    *(undefined4 *)(iVar3 + 0x24) = uVar2;
  }
  if ((*(int *)(param_1 + 0x148) != 0) && (*(int *)(param_1 + 0x14c) != 0)) {
    iVar3 = *(int *)(param_1 + 0x30);
    *(undefined4 *)(iVar3 + 0x44) = DAT_300cca54;
    *(undefined4 *)(iVar3 + 0x48) = DAT_300cca58;
    *(undefined4 *)(iVar3 + 0x4c) = DAT_300cca5c;
  }
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x184) = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cbb4c @ 0x300CBB4C  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: semGive
 * Вызывают: FUN_300cbc28, FUN_300cbe88, FUN_300cd2a8, FUN_300ceaec, dosFsCacheTune
 * Константы: 0x300CBB4C
 * Данные: DAT_300cc47c, DAT_300cca60, DAT_300cca64, DAT_300cca68, DAT_300cca6c
 * ---------------------------------------------------------------- */
uint FUN_300cbb4c(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  code *unaff_r5;
  code *pcVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  pcVar2 = (code *)*DAT_300cc47c;
  pcVar3 = pcVar2;
  if (pcVar2 != (code *)0x0) {
    if ((param_3 == 0) && (param_4 == 0)) {
      semGive(*(undefined4 *)(param_1 + 700));
      return 0;
    }
    if (pcVar2 != (code *)0x0) {
      unaff_r5 = DAT_300cca64;
      pcVar3 = DAT_300cca60;
    }
  }
  if (pcVar2 == (code *)0x0) {
    unaff_r5 = DAT_300cca6c;
    pcVar3 = DAT_300cca68;
  }
  iVar5 = 0;
  if (-1 < param_2) {
    do {
      uVar1 = (*pcVar3)(param_1,iVar5,param_3 != 0 || param_4 != 0);
      uVar4 = uVar1 | uVar4;
      if (param_3 != 0) {
        (*unaff_r5)(param_1 + iVar5 * 0x84 + 0xc4);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= param_2);
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * FUN_300cbc28 @ 0x300CBC28  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300cbb4c, dosFsXbdIoctl, semGive, semTake
 * Константы: 0x300CBC28, 0xFFFFFFFF
 * Данные: DAT_300ccba8, DAT_300ccbac, DAT_300ccbb0, DAT_300ccbb4, DAT_300ccbb8, DAT_300ccbbc
 * ---------------------------------------------------------------- */
void FUN_300cbc28(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0xc4) == 0) || (*(int *)(param_1 + 200) == 0)) {
    if (*(int *)(param_1 + 0x148) == 0) {
      return;
    }
    if (*(int *)(param_1 + 0x14c) == 0) {
      return;
    }
  }
  iVar3 = semTake(*(undefined4 *)(param_1 + 0x1d0),0xffffffff);
  if (iVar3 != 0) {
    return;
  }
  FUN_300cbb4c(param_1,1,1,1);
  dosFsXbdIoctl(param_1,DAT_300ccba8,0);
  *(undefined4 *)(param_1 + 0xb8) = DAT_300ccbac;
  *(undefined4 *)(param_1 + 0xbc) = DAT_300ccbb0;
  uVar1 = DAT_300ccbb4;
  *(undefined4 *)(param_1 + 0xb4) = DAT_300ccbb4;
  uVar2 = DAT_300ccbb8;
  *(undefined4 *)(param_1 + 0xc0) = DAT_300ccbb8;
  iVar3 = *(int *)(param_1 + 0x30);
  *(undefined4 *)(iVar3 + 0x44) = uVar1;
  *(undefined4 *)(iVar3 + 0x48) = DAT_300ccbbc;
  *(undefined4 *)(iVar3 + 0x4c) = uVar2;
  iVar3 = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(iVar3 + 0x20) = uVar1;
  *(undefined4 *)(iVar3 + 0x24) = uVar2;
  semGive(*(undefined4 *)(param_1 + 0x1d0));
  return;
}

/* ----------------------------------------------------------------
 * dosFsCacheCreate @ 0x300CBCE8  (примерный размер ~416 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 11
 * Вызывает: FUN_300cb558, FUN_300cbab4, bzero, dosFsVolDescGet, dosFsXbdIoctl, printf, semBCreate, semGive, semTake, snprintf, taskSpawn
 * Константы: 0x300CBCE8, 0xFFFFFFFF
 * Данные: DAT_300cc47c, DAT_300ccba8, DAT_300ccbc0, DAT_300ccbc4, DAT_300cccbc, DAT_300cccc0, DAT_300cccc4, DAT_300cccc8
 * ---------------------------------------------------------------- */
int dosFsCacheCreate(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char acStack_40 [32];
  
  iVar6 = 0;
  iVar3 = 0x20;
  pcVar4 = acStack_40;
  pcVar5 = DAT_300ccbc0;
  do {
    iVar3 = iVar3 + -1;
    *pcVar4 = *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (iVar3 != 0);
  iVar3 = dosFsVolDescGet(param_1,0);
  if (iVar3 == 0) {
    printf(DAT_300ccbc4,param_1);
    iVar6 = -1;
  }
  else {
    iVar1 = semTake(*(undefined4 *)(iVar3 + 0x34),0xffffffff);
    if (iVar1 == -1) {
      iVar6 = -1;
    }
    else {
      if ((((*(int *)(iVar3 + 0xc4) == 0) && (*(int *)(iVar3 + 0x148) == 0)) &&
          (iVar6 = FUN_300cb558(param_1,iVar3,0,DAT_300cccbc,param_2,param_3), iVar6 == 0)) &&
         (iVar6 = FUN_300cb558(param_1,iVar3,1,DAT_300cccc0,param_4,param_5), iVar6 == 0)) {
        if (*DAT_300cc47c != 0) {
          bzero(acStack_40,0x20);
          snprintf(acStack_40,0x20,DAT_300cccc4,param_1 + 1);
          uVar2 = semBCreate(1,0);
          *(undefined4 *)(iVar3 + 700) = uVar2;
          uVar2 = taskSpawn(acStack_40,2,0,0x2000,DAT_300cccc8,iVar3,0,0,0,0,0,0,0,0,0);
          *(undefined4 *)(iVar3 + 0x2b8) = uVar2;
        }
        FUN_300cbab4(iVar3);
        dosFsXbdIoctl(iVar3,DAT_300ccba8,0);
      }
      semGive(*(undefined4 *)(iVar3 + 0x34));
    }
  }
  return iVar6;
}

/* ----------------------------------------------------------------
 * FUN_300cbe88 @ 0x300CBE88  (примерный размер ~504 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 10
 * Вызывает: FUN_300cbb4c, bzero, cacheDmaFree, dosFsXbdIoctl, free, printf, semDelete, semGive, semTake, taskDelete
 * Вызывают: dosFsCacheDelete
 * Константы: 0xFFFFFFFF, 0x300CBE88
 * Данные: DAT_300cc47c, DAT_300ccba8, DAT_300ccbac, DAT_300ccbb0, DAT_300ccbb4, DAT_300ccbb8, DAT_300ccbbc, DAT_300ccda4
 * ---------------------------------------------------------------- */
undefined4 FUN_300cbe88(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  void *__s;
  int iVar6;
  
  if (((*(int *)(param_1 + 0xc4) == 0) || (*(int *)(param_1 + 200) == 0)) &&
     ((*(int *)(param_1 + 0x148) == 0 || (*(int *)(param_1 + 0x14c) == 0)))) {
    printf(DAT_300ccda4,param_1);
    uVar3 = 0xffffffff;
  }
  else {
    iVar4 = semTake(*(undefined4 *)(param_1 + 0x34),0xffffffff);
    if (iVar4 == -1) {
      uVar3 = 0xffffffff;
    }
    else {
      iVar4 = semTake(*(undefined4 *)(param_1 + 0x1d0),0xffffffff);
      if (iVar4 == 0) {
        FUN_300cbb4c(param_1,1,1,1);
        piVar1 = DAT_300cc47c;
        __s = (void *)(param_1 + 0xc4);
        iVar4 = 2;
        do {
          iVar6 = *(int *)((int)__s + 4);
          uVar5 = 0;
          if (*(int *)((int)__s + 0x34) != 0) {
            do {
              if (*(int *)(iVar6 + 0x58) != 0) {
                semDelete();
              }
              if (*(void **)(iVar6 + 0xc) != (void *)0x0) {
                free(*(void **)(iVar6 + 0xc));
              }
              iVar6 = iVar6 + 0x164;
              uVar5 = uVar5 + 1;
            } while (uVar5 < *(uint *)((int)__s + 0x34));
          }
          if (*(int *)((int)__s + 0x20) != 0) {
            cacheDmaFree(*(undefined4 *)((int)__s + 4));
          }
          if (*piVar1 != 0) {
            if (*(void **)((int)__s + 100) != (void *)0x0) {
              free(*(void **)((int)__s + 100));
            }
            if (*(int *)((int)__s + 0x68) != 0) {
              semDelete(*(int *)((int)__s + 0x68));
            }
            if (*(int *)((int)__s + 0x70) != 0) {
              semDelete(*(int *)((int)__s + 0x70));
            }
          }
          bzero(__s,0x84);
          __s = (void *)((int)__s + 0x84);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if ((*piVar1 != 0) && (*(int *)(param_1 + 0x2b8) != 0)) {
          taskDelete(*(int *)(param_1 + 0x2b8));
        }
        *(undefined4 *)(param_1 + 0xb8) = DAT_300ccbac;
        *(undefined4 *)(param_1 + 0xbc) = DAT_300ccbb0;
        uVar3 = DAT_300ccbb4;
        *(undefined4 *)(param_1 + 0xb4) = DAT_300ccbb4;
        uVar2 = DAT_300ccbb8;
        *(undefined4 *)(param_1 + 0xc0) = DAT_300ccbb8;
        iVar4 = *(int *)(param_1 + 0x30);
        *(undefined4 *)(iVar4 + 0x44) = uVar3;
        *(undefined4 *)(iVar4 + 0x48) = DAT_300ccbbc;
        *(undefined4 *)(iVar4 + 0x4c) = uVar2;
        iVar4 = *(int *)(param_1 + 0x2c);
        *(undefined4 *)(iVar4 + 0x20) = uVar3;
        *(undefined4 *)(iVar4 + 0x24) = uVar2;
        dosFsXbdIoctl(param_1,DAT_300ccba8,0);
        semGive(*(undefined4 *)(param_1 + 0x1d0));
        semGive(*(undefined4 *)(param_1 + 0x34));
        uVar3 = 0;
      }
      else {
        uVar3 = 0xffffffff;
      }
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * dosFsCacheDelete @ 0x300CC080  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300cbe88, dosFsVolDescGet, printf
 * Константы: 0x300CC080, 0xFFFFFFFF
 * Данные: DAT_300ccbc4
 * ---------------------------------------------------------------- */
undefined4 dosFsCacheDelete(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = dosFsVolDescGet(param_1,0);
  if (iVar1 == 0) {
    printf(DAT_300ccbc4,param_1);
    return 0xffffffff;
  }
  uVar2 = FUN_300cbe88();
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300cc0c0 @ 0x300CC0C0  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 2
 * Вызывает: semTake, xbdStrategy
 * Вызывают: FUN_300cc684, FUN_300cc7c8, FUN_300cc974, FUN_300ccc2c, FUN_300cd160, FUN_300cefe8
 * Константы: 0xFFFFFFFF, 0x300CC0C0
 * Данные: DAT_300ccfd0
 * ---------------------------------------------------------------- */
undefined4
FUN_300cc0c0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  *(undefined4 *)(param_3 + 4) = param_4;
  *(undefined4 *)(param_3 + 8) = param_5;
  *(undefined4 *)(param_3 + 0xc) = param_6;
  *(undefined4 *)(param_3 + 0x1c) = param_7;
  *(undefined4 *)(param_3 + 0x24) = DAT_300ccfd0;
  *(undefined4 *)(param_3 + 0x28) = *(undefined4 *)(param_2 + 0x58);
  *(undefined4 *)(param_3 + 0x2c) = 0;
  *(undefined4 *)(param_3 + 0x18) = 0;
  *(undefined4 *)(param_3 + 0x14) = 0;
  xbdStrategy(*(undefined4 *)(param_1 + 0x28),param_3);
  iVar1 = semTake(*(undefined4 *)(param_3 + 0x28),0xffffffff);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_3 + 0x14) != 0) {
    return 0xffffffff;
  }
  return *(undefined4 *)(param_3 + 0x18);
}

/* ----------------------------------------------------------------
 * FUN_300cc150 @ 0x300CC150  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: atomic32Dec, semGive
 * Константы: 0x300CC150
 * ---------------------------------------------------------------- */
void FUN_300cc150(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(param_1 + 0x28);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x14) == 0) goto LAB_300cc178;
    iVar1 = -1;
  }
  *(int *)(iVar2 + 0x78) = iVar1;
LAB_300cc178:
  iVar1 = atomic32Dec(iVar2 + 0x74);
  if (iVar1 != 1) {
    return;
  }
  semGive(*(undefined4 *)(iVar2 + 0x70));
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cc194 @ 0x300CC194  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: atomic32Inc, xbdStrategy
 * Вызывают: FUN_300cf1d0
 * Константы: 0x300CC194
 * Данные: DAT_300cd0f4
 * ---------------------------------------------------------------- */
undefined4
FUN_300cc194(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  *(undefined4 *)(param_3 + 4) = param_4;
  *(undefined4 *)(param_3 + 8) = param_5;
  *(undefined4 *)(param_3 + 0xc) = param_6;
  *(undefined4 *)(param_3 + 0x1c) = param_7;
  *(undefined4 *)(param_3 + 0x24) = DAT_300cd0f4;
  *(int *)(param_3 + 0x28) = param_2;
  *(undefined4 *)(param_3 + 0x2c) = 0;
  *(undefined4 *)(param_3 + 0x18) = 0;
  *(undefined4 *)(param_3 + 0x14) = 0;
  atomic32Inc(param_2 + 0x74);
  xbdStrategy(*(undefined4 *)(param_1 + 0x28),param_3);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300cc1f4 @ 0x300CC1F4  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: __udiv32
 * Вызывают: FUN_300cc974
 * Константы: 0x300CC1F4
 * ---------------------------------------------------------------- */
void FUN_300cc1f4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  if (iVar3 == 0) {
    return;
  }
  iVar4 = *(int *)(param_2 + 0x14);
  iVar1 = __udiv32(iVar4,iVar3);
  iVar2 = *(int *)(param_1 + 0x18);
  iVar4 = iVar4 - iVar3 * iVar1;
  iVar3 = *(int *)(iVar2 + iVar4 * 4);
  if (iVar3 != 0) {
    *(int *)(param_2 + 8) = iVar3;
  }
  *(int *)(iVar2 + iVar4 * 4) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cc23c @ 0x300CC23C  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: __udiv32
 * Вызывают: FUN_300cc974, FUN_300ccfe8
 * Константы: 0x300CC23C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void FUN_300cc23c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  if ((iVar2 != 0) && (iVar3 = *(int *)(param_2 + 0x14), iVar3 != -1)) {
    iVar1 = __udiv32(iVar3,iVar2);
    iVar3 = iVar3 - iVar2 * iVar1;
    iVar2 = *(int *)(*(int *)(param_1 + 0x18) + iVar3 * 4);
    if (iVar2 != 0) {
      if (iVar2 == param_2) {
        *(undefined4 *)(*(int *)(param_1 + 0x18) + iVar3 * 4) = *(undefined4 *)(param_2 + 8);
      }
      else {
        do {
          iVar3 = iVar2;
          if (iVar3 == 0) goto LAB_300cc2c4;
          iVar2 = *(int *)(iVar3 + 8);
        } while (*(int *)(iVar3 + 8) != param_2);
        *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(param_2 + 8);
      }
    }
  }
LAB_300cc2c4:
  *(undefined4 *)(param_2 + 0x14) = 0xffffffff;
  *(undefined4 *)(param_2 + 0x20) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cc2dc @ 0x300CC2DC  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: __udiv32, spinLockTaskGive, spinLockTaskTake
 * Вызывают: FUN_300ccc2c
 * Константы: 0x300CC2DC
 * ---------------------------------------------------------------- */
void FUN_300cc2dc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  spinLockTaskTake(*(undefined4 *)(param_1 + 100));
  iVar2 = *(int *)(param_1 + 0x1c);
  iVar1 = __udiv32(param_3,iVar2);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar2 = param_3 - iVar2 * iVar1;
  iVar1 = *(int *)(iVar3 + iVar2 * 4);
  if (iVar1 != 0) {
    *(int *)(param_2 + 8) = iVar1;
  }
  *(int *)(iVar3 + iVar2 * 4) = param_2;
  *(int *)(param_2 + 0x14) = param_3;
  spinLockTaskGive(*(undefined4 *)(param_1 + 100));
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cc330 @ 0x300CC330  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: __udiv32, spinLockTaskGive, spinLockTaskTake
 * Вызывают: FUN_300ccc2c, FUN_300cd078
 * Константы: 0x300CC330, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void FUN_300cc330(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  spinLockTaskTake(*(undefined4 *)(param_1 + 100));
  iVar2 = *(int *)(param_1 + 0x1c);
  iVar1 = __udiv32(param_3,iVar2);
  param_3 = param_3 - iVar2 * iVar1;
  iVar1 = *(int *)(*(int *)(param_1 + 0x18) + param_3 * 4);
  if (iVar1 == param_2) {
    *(undefined4 *)(*(int *)(param_1 + 0x18) + param_3 * 4) = *(undefined4 *)(param_2 + 8);
  }
  else {
    do {
      iVar2 = iVar1;
      if (iVar2 == 0) goto LAB_300cc3a8;
      iVar1 = *(int *)(iVar2 + 8);
    } while (*(int *)(iVar2 + 8) != param_2);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(param_2 + 8);
  }
LAB_300cc3a8:
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0xffffffff;
  spinLockTaskGive(*(undefined4 *)(param_1 + 100));
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cc3c4 @ 0x300CC3C4  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: __udiv32, spinLockTaskGive, spinLockTaskTake
 * Вызывают: FUN_300cc508
 * Константы: 0x300CC3C4
 * ---------------------------------------------------------------- */
int FUN_300cc3c4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  spinLockTaskTake(*(undefined4 *)(param_1 + 100));
  iVar2 = *(int *)(param_1 + 0x1c);
  iVar1 = __udiv32(param_2,iVar2);
  iVar1 = *(int *)(*(int *)(param_1 + 0x18) + (param_2 - iVar2 * iVar1) * 4);
  while( true ) {
    if (iVar1 == 0) {
      spinLockTaskGive(*(undefined4 *)(param_1 + 100));
      return 0;
    }
    if (*(int *)(iVar1 + 0x14) == param_2) break;
    iVar1 = *(int *)(iVar1 + 8);
  }
  spinLockTaskGive(*(undefined4 *)(param_1 + 100));
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300cc434 @ 0x300CC434  (примерный размер ~212 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __udiv32
 * Константы: 0x300CC434
 * ---------------------------------------------------------------- */
undefined4 * FUN_300cc434(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  if (iVar2 == 0) {
    for (puVar3 = *(undefined4 **)(param_1 + 8); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      if (puVar3[5] == param_2) {
        return puVar3;
      }
    }
    for (piVar4 = *(int **)(param_1 + 0x10); piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      if (piVar4[5] == param_2) {
        return piVar4;
      }
    }
  }
  else {
    iVar1 = __udiv32(param_2,iVar2);
    for (puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x18) + (param_2 - iVar2 * iVar1) * 4);
        puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)puVar3[2]) {
      if (puVar3[5] == param_2) {
        return puVar3;
      }
    }
  }
  return (undefined4 *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_300cc508 @ 0x300CC508  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_300cc3c4, semGive, semTake, spinLockTaskGive, spinLockTaskTake, taskIdSelf
 * Вызывают: FUN_300ccc2c
 * Константы: 0x300CC508, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int FUN_300cc508(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  while( true ) {
    iVar1 = FUN_300cc3c4(param_1,param_2);
    if ((iVar1 == 0) || (param_3 == 0)) {
      return iVar1;
    }
    while (spinLockTaskTake(*(undefined4 *)(iVar1 + 0xc)), *(int *)(iVar1 + 0x10) != 0) {
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
      spinLockTaskGive(*(undefined4 *)(iVar1 + 0xc));
      semTake(*(undefined4 *)(iVar1 + 0x1c),0xffffffff);
    }
    uVar2 = taskIdSelf();
    *(undefined4 *)(iVar1 + 0x160) = uVar2;
    *(uint *)(iVar1 + 0x10) = param_3 | *(uint *)(iVar1 + 0x10);
    spinLockTaskGive(*(undefined4 *)(iVar1 + 0xc));
    if (*(int *)(iVar1 + 0x14) == param_2) break;
    spinLockTaskTake(*(undefined4 *)(iVar1 + 0xc));
    *(undefined4 *)(iVar1 + 0x160) = 0;
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & ~param_3;
    if (0 < *(int *)(iVar1 + 0x18)) {
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -1;
      semGive(*(undefined4 *)(iVar1 + 0x1c));
    }
    spinLockTaskGive(*(undefined4 *)(iVar1 + 0xc));
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300cc5fc @ 0x300CC5FC  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: bzero
 * Вызывают: FUN_300cc974, FUN_300ccc2c, FUN_300cd2a8, FUN_300ce044, FUN_300ceaec
 * Константы: 0x300CC5FC
 * ---------------------------------------------------------------- */
void FUN_300cc5fc(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_3 <= (int)param_2) {
    return;
  }
  do {
    uVar1 = 1 << (param_2 & 0x1f);
    iVar2 = param_1 + (param_2 >> 5) * 4;
    if ((*(uint *)(iVar2 + 0x60) & uVar1) == 0) {
      *(uint *)(iVar2 + 0x60) = *(uint *)(iVar2 + 0x60) | uVar1;
      iVar2 = *(short *)(param_1 + 0x5c) + -1;
      *(short *)(param_1 + 0x5c) = (short)iVar2;
      if (iVar2 * 0x10000 >> 0x10 == 0) {
        bzero((void *)(param_1 + 0x60),0x80);
        return;
      }
    }
    param_2 = param_2 + 1;
  } while ((int)param_2 < param_3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cc684 @ 0x300CC684  (примерный размер ~324 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: FUN_300cc0c0, bzero, puts
 * Вызывают: FUN_300cc7c8, FUN_300cefe8, FUN_300cf1d0
 * Константы: 0x300CC684, 0xFFFFFFFF
 * Данные: DAT_300cd680
 * ---------------------------------------------------------------- */
undefined4 FUN_300cc684(int param_1,int param_2,int param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  
  iVar2 = 0;
  uVar4 = (**(code **)(param_2 + 0x54))(param_2,*(undefined4 *)(param_3 + 0x14));
  uVar3 = param_4;
  do {
    for (; ((int)param_4 < param_5 &&
           ((*(uint *)(param_3 + (param_4 >> 5) * 4 + 0xe0) & 1 << (param_4 & 0x1f)) != 0));
        param_4 = param_4 + 1) {
      iVar2 = iVar2 + 1;
    }
    if (0 < iVar2) {
      iVar1 = *(int *)(param_1 + 0x1fc);
      *(uint *)(param_3 + 0x38) = uVar3 * iVar1 + *(int *)(param_3 + 0x38);
      iVar1 = FUN_300cc0c0(param_1,param_3,param_3 + 0x28,(uint)uVar4 + uVar3,
                           (int)((ulonglong)uVar4 >> 0x20) + ((int)uVar3 >> 0x1f) +
                           (uint)CARRY4((uint)uVar4,uVar3),iVar1 * iVar2,2);
      *(undefined4 *)(param_3 + 0x38) = *(undefined4 *)(param_3 + 0x24);
      if (iVar1 != 0) {
        puts(DAT_300cd680);
        return 0xffffffff;
      }
      iVar2 = *(short *)(param_3 + 0x5e) - iVar2;
      *(short *)(param_3 + 0x5e) = (short)iVar2;
      if (iVar2 * 0x10000 >> 0x10 == 0) {
        bzero((void *)(param_3 + 0xe0),0x80);
        return 0;
      }
      iVar2 = 0;
    }
    if (*(uint *)(param_2 + 0x4c) == param_4) {
      return 0;
    }
    param_4 = param_4 + 1;
    uVar3 = param_4;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300cc7c8 @ 0x300CC7C8  (примерный размер ~428 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 6
 * Вызывает: FUN_300cc0c0, FUN_300cc684, bzero, dllAdd, dllRemove, printf
 * Вызывают: FUN_300cc974, FUN_300cd2a8, FUN_300ce044
 * Константы: 0x300CC7C8, 0xFFFFFFFF
 * Данные: DAT_300cd7f8
 * ---------------------------------------------------------------- */
undefined4 FUN_300cc7c8(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int unaff_r5;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined8 uVar6;
  
  bVar1 = false;
  iVar4 = param_1 + param_2 * 0x84;
  bVar2 = false;
  do {
    piVar5 = *(int **)(iVar4 + 0xd4);
    do {
      if (piVar5 == (int *)0x0) {
        return 0;
      }
      piVar3 = (int *)*piVar5;
      if ((int)*(short *)((int)piVar5 + 0x5e) == *(int *)(iVar4 + 0x110)) {
        uVar6 = (**(code **)(iVar4 + 0x118))(iVar4 + 0xc4,piVar5[5]);
        unaff_r5 = FUN_300cc0c0(param_1,piVar5,piVar5 + 10,(int)uVar6,
                                (int)((ulonglong)uVar6 >> 0x20),
                                *(int *)(param_1 + 0x1fc) * *(int *)(iVar4 + 0x110),2);
        *(undefined2 *)((int)piVar5 + 0x5e) = 0;
        bzero(piVar5 + 0x38,0x80);
LAB_300cc8c0:
        if (unaff_r5 != 0) {
          printf(DAT_300cd7f8,piVar5[0x10]);
          return 0xffffffff;
        }
        bVar1 = false;
        piVar5[8] = 0;
        *(int *)(iVar4 + 0xe8) = *(int *)(iVar4 + 0xe8) + -1;
        dllRemove((undefined4 *)(iVar4 + 0xd4),piVar5);
        dllAdd(iVar4 + 0xcc,piVar5);
      }
      else {
        if ((param_3 != 0) || (bVar2)) {
          unaff_r5 = FUN_300cc684(param_1,iVar4 + 0xc4,piVar5,0,*(int *)(iVar4 + 0x110));
          bVar1 = true;
        }
        if (bVar1) goto LAB_300cc8c0;
      }
      piVar5 = piVar3;
    } while (piVar3 != (int *)0x0);
    if ((param_3 != 0) || (*(uint *)(iVar4 + 0xe8) <= *(uint *)(iVar4 + 0xec) >> 1)) {
      return 0;
    }
    bVar2 = true;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300cc974 @ 0x300CC974  (примерный размер ~696 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 9
 * Вызывает: FUN_300cc0c0, FUN_300cc1f4, FUN_300cc23c, FUN_300cc5fc, FUN_300cc7c8, bzero, dllInsert, dllRemove, puts
 * Константы: 0x300CC974
 * Данные: DAT_300cdb8c
 * ---------------------------------------------------------------- */
int FUN_300cc974(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  
  iVar5 = param_1 + param_2 * 0x84;
  iVar7 = *(int *)(iVar5 + 0xd0);
  iVar6 = iVar5 + 0xc4;
  if (iVar7 == 0) {
    iVar7 = FUN_300cc7c8(param_1,param_2,0);
    if (iVar7 == -1) {
      return 0;
    }
    iVar7 = *(int *)(iVar5 + 0xd0);
    if (iVar7 == 0) {
      return 0;
    }
  }
  if (*(int *)(iVar7 + 0x14) != -1) {
    FUN_300cc23c(iVar6,iVar7);
    *(int *)(iVar5 + 0xf0) = *(int *)(iVar5 + 0xf0) + -1;
  }
  *(short *)(iVar7 + 0x5c) = (short)*(undefined4 *)(iVar5 + 0x110);
  *(undefined2 *)(iVar7 + 0x5e) = 0;
  bzero((void *)(iVar7 + 0x60),0x80);
  bzero((void *)(iVar7 + 0xe0),0x80);
  if (param_4 == 0) goto LAB_300ccbd8;
  uVar9 = (**(code **)(iVar5 + 0x118))(iVar6,param_3);
  iVar1 = FUN_300cc0c0(param_1,iVar7,iVar7 + 0x28,(int)uVar9,(int)((ulonglong)uVar9 >> 0x20),
                       *(int *)(param_1 + 0x1fc) * *(int *)(iVar5 + 0x110),1);
  if (iVar1 == 0) {
    *(undefined2 *)(iVar7 + 0x5c) = 0;
    goto LAB_300ccbd8;
  }
  uVar9 = (**(code **)(iVar5 + 0x118))(iVar6,param_3);
  iVar1 = (int)((ulonglong)uVar9 >> 0x20);
  uVar4 = (uint)uVar9;
  uVar8 = *(uint *)(iVar5 + 0x110);
  iVar3 = iVar1 + ((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar4,uVar8) + -1 + (uint)(uVar4 + uVar8 != 0)
  ;
  uVar2 = ((*(int *)(param_1 + 100) + -2) * (uint)*(ushort *)(param_1 + 0x5e) +
          *(int *)(param_1 + 0x78)) - 1;
  if (iVar3 == 0) {
code_r0x300ccb30:
    if (iVar3 == 0 && (uVar4 + uVar8) - 1 <= uVar2) goto LAB_300ccbc8;
  }
  else if (iVar3 < 1) {
    if (iVar3 < 1) goto LAB_300ccbc8;
    goto code_r0x300ccb30;
  }
  iVar1 = FUN_300cc0c0(param_1,iVar7,iVar7 + 0x28,uVar4,iVar1,
                       *(int *)(param_1 + 0x1fc) * ((uVar2 - uVar4) + 1),1);
  if (iVar1 == 0) {
    FUN_300cc5fc(iVar7,0,(uVar2 - uVar4) + 1);
    *(short *)(iVar7 + 0x5c) = *(short *)(iVar7 + 0x5c) - (((short)uVar2 - (short)uVar9) + 1);
LAB_300ccbd8:
    *(undefined4 *)(iVar7 + 0x14) = param_3;
    FUN_300cc1f4(iVar6,iVar7);
    dllRemove(iVar5 + 0xcc,iVar7);
    dllInsert(iVar5 + 0xcc,0,iVar7);
    uVar4 = *(int *)(iVar5 + 0xf0) + 1;
    *(uint *)(iVar5 + 0xf0) = uVar4;
    if (*(uint *)(iVar5 + 0xf4) < uVar4) {
      *(uint *)(iVar5 + 0xf4) = uVar4;
    }
    return iVar7;
  }
LAB_300ccbc8:
  puts(DAT_300cdb8c);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ccc2c @ 0x300CCC2C  (примерный размер ~956 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 13
 * Вызывает: FUN_300cc0c0, FUN_300cc2dc, FUN_300cc330, FUN_300cc508, FUN_300cc5fc, bzero, puts, semGive, semTake, spinLockTaskGive, spinLockTaskTake, taskDelay, taskIdSelf
 * Константы: 0xFFFFFFFF, 0x300CCC2C
 * Данные: DAT_300cdfa8
 * ---------------------------------------------------------------- */
int * FUN_300ccc2c(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  undefined8 uVar11;
  
  iVar7 = param_1 + param_2 * 0x84;
  iVar8 = iVar7 + 0xc4;
  do {
    while( true ) {
      semTake(*(undefined4 *)(iVar7 + 300),0xffffffff);
      piVar2 = (int *)FUN_300cc508(iVar8,param_3,0);
      if (piVar2 == (int *)0x0) break;
      semGive(*(undefined4 *)(iVar7 + 300));
      while (spinLockTaskTake(piVar2[3]), piVar2[4] != 0) {
        piVar2[6] = piVar2[6] + 1;
        spinLockTaskGive(piVar2[3]);
        semTake(piVar2[7],0xffffffff);
      }
      iVar3 = taskIdSelf();
      piVar2[0x58] = iVar3;
      piVar2[4] = param_5 | piVar2[4];
      spinLockTaskGive(piVar2[3]);
      if (piVar2[5] == param_3) {
        return piVar2;
      }
      spinLockTaskTake(piVar2[3]);
      piVar2[0x58] = 0;
      piVar2[4] = piVar2[4] & ~param_5;
      if (0 < piVar2[6]) {
        piVar2[6] = piVar2[6] + -1;
        semGive(piVar2[7]);
      }
      spinLockTaskGive(piVar2[3]);
    }
    bVar1 = true;
    piVar2 = *(int **)(iVar7 + 0x130);
    while ((*(int **)(iVar7 + 0x130) != piVar2 || (bVar1))) {
      piVar9 = (int *)*piVar2;
      if (piVar9 == (int *)0x0) {
        piVar9 = *(int **)(iVar7 + 0xcc);
      }
      spinLockTaskTake(piVar2[3]);
      bVar1 = false;
      if (((piVar2[4] == 0) && (piVar2[8] != 1)) && (piVar2[6] < 1)) {
        iVar3 = taskIdSelf();
        piVar2[0x58] = iVar3;
        piVar2[4] = param_5 | piVar2[4];
        spinLockTaskGive(piVar2[3]);
        if (piVar2[5] != -1) {
          FUN_300cc330(iVar8,piVar2,piVar2[5]);
        }
        FUN_300cc2dc(iVar8,piVar2,param_3);
        iVar3 = *piVar2;
        *(int *)(iVar7 + 0x130) = iVar3;
        if (iVar3 == 0) {
          *(undefined4 *)(iVar7 + 0x130) = *(undefined4 *)(iVar7 + 0xcc);
        }
        semGive(*(undefined4 *)(iVar7 + 300));
        *(short *)(piVar2 + 0x17) = (short)*(undefined4 *)(iVar7 + 0x110);
        *(undefined2 *)((int)piVar2 + 0x5e) = 0;
        bzero(piVar2 + 0x18,0x80);
        bzero(piVar2 + 0x38,0x80);
        if (param_4 == 0) {
          return piVar2;
        }
        uVar11 = (**(code **)(iVar7 + 0x118))(iVar8,param_3);
        iVar3 = FUN_300cc0c0(param_1,piVar2,piVar2 + 10,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20)
                             ,*(int *)(param_1 + 0x1fc) * *(int *)(iVar7 + 0x110),1);
        if (iVar3 == 0) {
          sVar6 = 0;
          goto LAB_300ccfa0;
        }
        uVar11 = (**(code **)(iVar7 + 0x118))(iVar8,param_3);
        iVar8 = (int)((ulonglong)uVar11 >> 0x20);
        uVar4 = (uint)uVar11;
        uVar10 = *(uint *)(iVar7 + 0x110);
        iVar7 = iVar8 + ((int)uVar10 >> 0x1f) + (uint)CARRY4(uVar4,uVar10) + -1 +
                (uint)(uVar4 + uVar10 != 0);
        uVar5 = ((*(int *)(param_1 + 100) + -2) * (uint)*(ushort *)(param_1 + 0x5e) +
                *(int *)(param_1 + 0x78)) - 1;
        if (iVar7 == 0) {
code_r0x300ccf1c:
          if (iVar7 == 0 && (uVar4 + uVar10) - 1 <= uVar5) goto LAB_300ccfd4;
        }
        else if (iVar7 < 1) {
          if (iVar7 < 1) goto LAB_300ccfd4;
          goto code_r0x300ccf1c;
        }
        iVar7 = FUN_300cc0c0(param_1,piVar2,piVar2 + 10,uVar4,iVar8,
                             *(int *)(param_1 + 0x1fc) * ((uVar5 - uVar4) + 1),1);
        if (iVar7 == 0) {
          FUN_300cc5fc(piVar2,0,(uVar5 - uVar4) + 1);
          sVar6 = (short)piVar2[0x17] - (((short)uVar5 - (short)uVar11) + 1);
LAB_300ccfa0:
          *(short *)(piVar2 + 0x17) = sVar6;
          return piVar2;
        }
LAB_300ccfd4:
        puts(DAT_300cdfa8);
        return (int *)0x0;
      }
      spinLockTaskGive(piVar2[3]);
      piVar2 = piVar9;
    }
    *(undefined4 *)(iVar7 + 0x130) = *(undefined4 *)(iVar7 + 0xcc);
    semGive(*(undefined4 *)(iVar7 + 300));
    semGive(*(undefined4 *)(param_1 + 700));
    taskDelay(1);
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300ccfe8 @ 0x300CCFE8  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300cc23c, bzero, dllAdd, dllRemove
 * Константы: 0x300CCFE8
 * ---------------------------------------------------------------- */
void FUN_300ccfe8(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0x20) == 1) {
    dllRemove(param_1 + 0x10);
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
  }
  else {
    dllRemove(param_1 + 8);
  }
  dllAdd(param_1 + 8,param_2);
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -1;
  if (*(int *)(param_2 + 0x14) != -1) {
    FUN_300cc23c(param_1,param_2);
  }
  *(undefined2 *)(param_2 + 0x5c) = 0xffff;
  *(undefined2 *)(param_2 + 0x5e) = 0xffff;
  bzero((void *)(param_2 + 0x60),0x80);
  bzero((void *)(param_2 + 0xe0),0x80);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cd078 @ 0x300CD078  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300cc330, atomic32Dec, bzero
 * Вызывают: FUN_300cef14
 * Константы: 0x300CD078
 * ---------------------------------------------------------------- */
void FUN_300cd078(int param_1,int param_2)

{
  FUN_300cc330(param_1,param_2,*(undefined4 *)(param_2 + 0x14));
  *(undefined2 *)(param_2 + 0x5c) = 0xffff;
  *(undefined2 *)(param_2 + 0x5e) = 0xffff;
  bzero((void *)(param_2 + 0x60),0x80);
  bzero((void *)(param_2 + 0xe0),0x80);
  if (*(int *)(param_2 + 0x20) != 1) {
    return;
  }
  *(undefined4 *)(param_2 + 0x20) = 0;
  atomic32Dec(param_1 + 0x24);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cd0d0 @ 0x300CD0D0  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: bzero
 * Вызывают: FUN_300cd2a8, FUN_300cdb24, FUN_300ce044, FUN_300ceaec
 * Константы: 0x300CD0D0
 * ---------------------------------------------------------------- */
void FUN_300cd0d0(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  
  if (param_4 <= (int)param_3) {
    return;
  }
  do {
    uVar1 = 1 << (param_3 & 0x1f);
    iVar3 = param_2 + (param_3 >> 5) * 4;
    if ((*(uint *)(iVar3 + 0xe0) & uVar1) == 0) {
      *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | uVar1;
      sVar2 = *(short *)(param_2 + 0x5e) + 1;
      *(short *)(param_2 + 0x5e) = sVar2;
      if ((int)sVar2 == *(int *)(param_1 + 0x4c)) {
        bzero((void *)(param_2 + 0xe0),0x80);
        return;
      }
    }
    param_3 = param_3 + 1;
  } while ((int)param_3 < param_4);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cd160 @ 0x300CD160  (примерный размер ~328 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: FUN_300cc0c0, bzero, puts
 * Вызывают: FUN_300cd79c, FUN_300cdb24, FUN_300ce044
 * Константы: 0x300CD160, 0xFFFFFFFF
 * Данные: DAT_300ce1e0
 * ---------------------------------------------------------------- */
undefined4 FUN_300cd160(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  iVar3 = 0;
  uVar5 = (**(code **)(param_2 + 0x54))(param_2,*(undefined4 *)(param_3 + 0x14));
  uVar4 = param_4;
  do {
    while ((int)param_5 <= (int)param_4) {
LAB_300cd1e4:
      if (0 < iVar3) {
        iVar2 = *(int *)(param_1 + 0x1fc);
        *(uint *)(param_3 + 0x38) = uVar4 * iVar2 + *(int *)(param_3 + 0x38);
        iVar2 = FUN_300cc0c0(param_1,param_3,param_3 + 0x28,(uint)uVar5 + uVar4,
                             (int)((ulonglong)uVar5 >> 0x20) + ((int)uVar4 >> 0x1f) +
                             (uint)CARRY4((uint)uVar5,uVar4),iVar2 * iVar3,1);
        *(undefined4 *)(param_3 + 0x38) = *(undefined4 *)(param_3 + 0x24);
        if (iVar2 != 0) {
          puts(DAT_300ce1e0);
          return 0xffffffff;
        }
        iVar3 = *(short *)(param_3 + 0x5c) - iVar3;
        *(short *)(param_3 + 0x5c) = (short)iVar3;
        if (iVar3 * 0x10000 >> 0x10 == 0) {
          bzero((void *)(param_3 + 0x60),0x80);
          return 0;
        }
        iVar3 = 0;
      }
      if (param_4 == param_5) {
        return 0;
      }
      param_4 = param_4 + 1;
      uVar4 = param_4;
    }
    uVar1 = 1 << (param_4 & 0x1f);
    iVar2 = param_3 + (param_4 >> 5) * 4;
    if ((*(uint *)(iVar2 + 0x60) & uVar1) != 0) goto LAB_300cd1e4;
    param_4 = param_4 + 1;
    iVar3 = iVar3 + 1;
    *(uint *)(iVar2 + 0x60) = *(uint *)(iVar2 + 0x60) | uVar1;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300cd2a8 @ 0x300CD2A8  (примерный размер ~1268 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 16
 * Вызывает: FUN_300cbb4c, FUN_300cc5fc, FUN_300cc7c8, FUN_300cd0d0, __errno, atomic32Inc, bcopy, bzero, dllAdd, dllRemove, dosFsXbdBlkWrite, puts, semGive, semTake
 *           ...
 * Константы: 0xFFFFFFFF, 0x300CD2A8, 0xFFFFFFFD
 * Данные: DAT_300ce368, DAT_300ce468
 * ---------------------------------------------------------------- */
undefined4
FUN_300cd2a8(int param_1,uint param_2,uint param_3,uint param_4,int param_5,void *param_6,
            int param_7)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  int iVar7;
  bool bVar8;
  int local_60;
  int local_5c;
  int local_58;
  int *local_54;
  int local_50;
  int local_4c [2];
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  
  iVar7 = param_1 + 0xc4;
  if (*(int *)(param_1 + 0xc4) == 0) {
    uVar1 = dosFsXbdBlkWrite(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    return uVar1;
  }
  if (param_5 == 0) {
LAB_300cd324:
    if (param_5 == 0 && param_4 == 0) {
      return 0;
    }
  }
  else if (param_5 < 1) {
    if (param_5 < 1) {
      return 0;
    }
    goto LAB_300cd324;
  }
  local_44 = *(uint *)(param_1 + 500);
  local_40 = *(uint *)(param_1 + 0x1f8);
  bVar8 = param_3 <= local_40;
  if (local_40 == param_3) {
LAB_300cd354:
    if (local_40 == param_3) {
      bVar8 = param_2 <= local_44;
    }
    if (!bVar8) goto LAB_300cd39c;
  }
  else if ((int)local_40 < (int)param_3) {
    if ((int)local_40 < (int)param_3) goto LAB_300cd39c;
    goto LAB_300cd354;
  }
  local_3c = param_2 + param_4;
  local_38 = param_3 + param_5 + (uint)CARRY4(param_2,param_4);
  bVar8 = local_38 <= local_40;
  if (local_40 != local_38) {
    if ((int)local_40 < (int)local_38) goto LAB_300cd39c;
    if ((int)local_38 <= (int)local_40) goto LAB_300cd3b0;
  }
  if (local_40 == local_38) {
    bVar8 = local_3c <= local_44;
  }
  if (bVar8) {
LAB_300cd3b0:
    local_54 = DAT_300ce368;
    if ((*DAT_300ce368 == 0) &&
       (iVar3 = semTake(*(undefined4 *)(param_1 + 0x1d0),0xffffffff), iVar3 != 0)) {
      return 0xffffffff;
    }
    iVar4 = (**(code **)(param_1 + 0x114))
                      (iVar7,param_2,param_3,param_4,&local_50,&local_60,&local_5c,local_4c,
                       &local_58);
    iVar3 = local_50;
    while (iVar4 != 0) {
      iVar4 = iVar4 + -1;
      iVar5 = (**(code **)(param_1 + 0x11c))(iVar7,iVar3,2);
      if (iVar5 == 0) {
        atomic32Inc(param_1 + 0x100);
        iVar5 = (**(code **)(param_1 + 0x120))(param_1,0,iVar3,0,2);
        if (iVar5 == 0) {
          puts(DAT_300ce468);
          if (*local_54 == 0) {
            semGive(*(undefined4 *)(param_1 + 0x1d0));
          }
          return 0xffffffff;
        }
      }
      else {
        atomic32Inc(param_1 + 0xfc);
      }
      if ((iVar3 == local_50) && (*(int *)(param_1 + 0x110) != local_5c)) {
        sVar6 = *(int *)(param_1 + 0x1fc) * local_5c;
        bcopy(param_6,(void *)(local_60 * *(int *)(param_1 + 0x1fc) + *(int *)(iVar5 + 0x24)),sVar6)
        ;
        param_6 = (void *)((int)param_6 + sVar6);
        if (0 < *(short *)(iVar5 + 0x5c)) {
          FUN_300cc5fc(iVar5,local_60,local_60 + local_5c);
        }
        if ((int)*(short *)(iVar5 + 0x5e) != *(int *)(param_1 + 0x110)) {
          FUN_300cd0d0(iVar7,iVar5,local_60,local_60 + local_5c);
        }
      }
      else if ((iVar3 == local_4c[0]) && (*(int *)(param_1 + 0x110) != local_58)) {
        sVar6 = *(int *)(param_1 + 0x1fc) * local_58;
        bcopy(param_6,*(void **)(iVar5 + 0x24),sVar6);
        param_6 = (void *)((int)param_6 + sVar6);
        if (0 < *(short *)(iVar5 + 0x5c)) {
          FUN_300cc5fc(iVar5,0,local_58);
        }
        if ((int)*(short *)(iVar5 + 0x5e) != *(int *)(param_1 + 0x110)) {
          FUN_300cd0d0(iVar7,iVar5,0,local_58);
        }
      }
      else {
        sVar6 = *(int *)(param_1 + 0x1fc) * *(int *)(param_1 + 0x110);
        bcopy(param_6,*(void **)(iVar5 + 0x24),sVar6);
        param_6 = (void *)((int)param_6 + sVar6);
        *(undefined2 *)(iVar5 + 0x5c) = 0;
        *(short *)(iVar5 + 0x5e) = (short)*(undefined4 *)(param_1 + 0x110);
        bzero((void *)(iVar5 + 0x60),0x80);
        bzero((void *)(iVar5 + 0xe0),0x80);
      }
      if (*local_54 == 0) {
        if (*(int *)(iVar5 + 0x20) == 0) {
          *(undefined4 *)(iVar5 + 0x20) = 1;
          *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) + 1;
          dllRemove(param_1 + 0xcc,iVar5);
          dllAdd(param_1 + 0xd4,iVar5);
        }
      }
      else {
        if (*(int *)(iVar5 + 0x20) == 0) {
          *(undefined4 *)(iVar5 + 0x20) = 1;
          atomic32Inc(param_1 + 0xe8);
        }
        spinLockTaskTake(*(undefined4 *)(iVar5 + 0xc));
        *(undefined4 *)(iVar5 + 0x160) = 0;
        *(uint *)(iVar5 + 0x10) = *(uint *)(iVar5 + 0x10) & 0xfffffffd;
        if (0 < *(int *)(iVar5 + 0x18)) {
          *(int *)(iVar5 + 0x18) = *(int *)(iVar5 + 0x18) + -1;
          semGive(*(undefined4 *)(iVar5 + 0x1c));
        }
        spinLockTaskGive(*(undefined4 *)(iVar5 + 0xc));
      }
      iVar3 = iVar3 + 1;
    }
    if (param_7 == 2) {
      iVar7 = FUN_300cbb4c(param_1,1,0,1);
      if (iVar7 == -1) {
        if (*local_54 == 0) {
          semGive(*(undefined4 *)(param_1 + 0x1d0));
        }
        return 0xffffffff;
      }
    }
    else if (*(uint *)(param_1 + 0xec) <= *(uint *)(param_1 + 0xe8)) {
      if (*local_54 == 0) {
        iVar7 = FUN_300cc7c8(param_1,0,0);
        if (iVar7 == -1) {
          if (*local_54 == 0) {
            semGive(*(undefined4 *)(param_1 + 0x1d0));
          }
          return 0xffffffff;
        }
      }
      else {
        semGive(*(undefined4 *)(param_1 + 700));
      }
    }
    if (*local_54 == 0) {
      semGive(*(undefined4 *)(param_1 + 0x1d0));
    }
    return 0;
  }
LAB_300cd39c:
  puVar2 = (undefined4 *)__errno();
  *puVar2 = 0x16;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300cd79c @ 0x300CD79C  (примерный размер ~904 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 10
 * Вызывает: FUN_300cd160, __errno, atomic32Inc, bcopy, dosFsXbdBlkRead, puts, semGive, semTake, spinLockTaskGive, spinLockTaskTake
 * Константы: 0xFFFFFFFF, 0x300CD79C, 0xFFFFFFFE
 * Данные: DAT_300ce368, DAT_300ce95c
 * ---------------------------------------------------------------- */
undefined4
FUN_300cd79c(int param_1,uint param_2,uint param_3,uint param_4,int param_5,void *param_6)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *__src;
  int iVar6;
  size_t __n;
  int iVar7;
  bool bVar8;
  int local_60;
  int local_5c;
  int local_58;
  int *local_54;
  int local_50;
  int local_4c [2];
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  
  iVar6 = param_1 + 0xc4;
  if (*(int *)(param_1 + 0xc4) == 0) {
    uVar1 = dosFsXbdBlkRead(param_1,param_2,param_3,param_4,param_5,param_6);
    return uVar1;
  }
  if (param_5 == 0) {
LAB_300cd814:
    if (param_5 == 0 && param_4 == 0) {
      return 0;
    }
  }
  else if (param_5 < 1) {
    if (param_5 < 1) {
      return 0;
    }
    goto LAB_300cd814;
  }
  local_44 = *(uint *)(param_1 + 500);
  local_40 = *(uint *)(param_1 + 0x1f8);
  bVar8 = param_3 <= local_40;
  if (local_40 == param_3) {
LAB_300cd844:
    if (local_40 == param_3) {
      bVar8 = param_2 <= local_44;
    }
    if (!bVar8) goto LAB_300cd88c;
  }
  else if ((int)local_40 < (int)param_3) {
    if ((int)local_40 < (int)param_3) goto LAB_300cd88c;
    goto LAB_300cd844;
  }
  local_3c = param_2 + param_4;
  local_38 = param_3 + param_5 + (uint)CARRY4(param_2,param_4);
  bVar8 = local_38 <= local_40;
  if (local_40 != local_38) {
    if ((int)local_40 < (int)local_38) goto LAB_300cd88c;
    if ((int)local_38 <= (int)local_40) goto LAB_300cd8a0;
  }
  if (local_40 == local_38) {
    bVar8 = local_3c <= local_44;
  }
  if (bVar8) {
LAB_300cd8a0:
    local_54 = DAT_300ce368;
    if ((*DAT_300ce368 == 0) &&
       (iVar3 = semTake(*(undefined4 *)(param_1 + 0x1d0),0xffffffff), iVar3 != 0)) {
      return 0xffffffff;
    }
    iVar4 = (**(code **)(param_1 + 0x114))
                      (iVar6,param_2,param_3,param_4,&local_50,&local_60,&local_5c,local_4c,
                       &local_58);
    iVar3 = local_50;
    do {
      if (iVar4 == 0) {
        if (*local_54 == 0) {
          semGive(*(undefined4 *)(param_1 + 0x1d0));
        }
        return 0;
      }
      iVar4 = iVar4 + -1;
      iVar5 = (**(code **)(param_1 + 0x11c))(iVar6,iVar3,1);
      if (iVar5 == 0) {
        atomic32Inc(param_1 + 0x100);
        iVar5 = (**(code **)(param_1 + 0x120))(param_1,0,iVar3,1,1);
        if (iVar5 == 0) {
          puts(DAT_300ce95c);
          if (*local_54 == 0) {
            semGive(*(undefined4 *)(param_1 + 0x1d0));
          }
          return 0xffffffff;
        }
      }
      else {
        atomic32Inc(param_1 + 0xfc);
      }
      if ((iVar3 == local_50) && (*(int *)(param_1 + 0x110) != local_5c)) {
        if (0 < *(short *)(iVar5 + 0x5c)) {
          FUN_300cd160(param_1,iVar6,iVar5,local_60,local_60 + local_5c);
        }
        __n = *(int *)(param_1 + 0x1fc) * local_5c;
        __src = (void *)(local_60 * *(int *)(param_1 + 0x1fc) + *(int *)(iVar5 + 0x24));
      }
      else {
        if ((iVar3 == local_4c[0]) && (*(int *)(param_1 + 0x110) != local_58)) {
          iVar7 = local_58;
          if (0 < *(short *)(iVar5 + 0x5c)) {
            FUN_300cd160(param_1,iVar6,iVar5,0,local_58);
            iVar7 = local_58;
          }
        }
        else {
          if (0 < *(short *)(iVar5 + 0x5c)) {
            FUN_300cd160(param_1,iVar6,iVar5,0,*(undefined4 *)(param_1 + 0x110));
          }
          iVar7 = *(int *)(param_1 + 0x110);
        }
        __src = *(void **)(iVar5 + 0x24);
        __n = *(int *)(param_1 + 0x1fc) * iVar7;
      }
      bcopy(__src,param_6,__n);
      param_6 = (void *)((int)param_6 + __n);
      if (*local_54 != 0) {
        spinLockTaskTake(*(undefined4 *)(iVar5 + 0xc));
        *(undefined4 *)(iVar5 + 0x160) = 0;
        *(uint *)(iVar5 + 0x10) = *(uint *)(iVar5 + 0x10) & 0xfffffffe;
        if (0 < *(int *)(iVar5 + 0x18)) {
          *(int *)(iVar5 + 0x18) = *(int *)(iVar5 + 0x18) + -1;
          semGive(*(undefined4 *)(iVar5 + 0x1c));
        }
        spinLockTaskGive(*(undefined4 *)(iVar5 + 0xc));
      }
      iVar3 = iVar3 + 1;
    } while( true );
  }
LAB_300cd88c:
  puVar2 = (undefined4 *)__errno();
  *puVar2 = 0x16;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300cdb24 @ 0x300CDB24  (примерный размер ~1192 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 15
 * Вызывает: FUN_300cd0d0, FUN_300cd160, __errno, atomic32Dec, atomic32Inc, bcopy, dllAdd, dllRemove, dosFsXbdBlkWrite, dosFsXbdBytesRW, puts, semGive, semTake, spinLockTaskGive
 *           ...
 * Вызывают: FUN_300cdfcc, FUN_300ce008
 * Константы: 0xFFFFFFFF, 0x300CDB24
 * Данные: DAT_300ce368, DAT_300cec68
 * ---------------------------------------------------------------- */
undefined4
FUN_300cdb24(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,void *param_6
            ,size_t param_7,int param_8)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int unaff_r6;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  uint local_48;
  int *local_44;
  undefined4 local_40;
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  
  iVar7 = param_1 + param_2 * 0x84;
  piVar8 = (int *)(iVar7 + 0xc4);
  if (*piVar8 == 0) {
    uVar1 = dosFsXbdBytesRW(param_1,param_3,param_4,param_5,param_6,param_7,param_8);
    return uVar1;
  }
  if (((param_5 + param_7 <= *(uint *)(param_1 + 0x1fc)) && (-1 < param_5)) && (param_7 != 0)) {
    local_44 = DAT_300ce368;
    if ((*DAT_300ce368 == 0) &&
       (iVar3 = semTake(*(undefined4 *)(param_1 + 0x1d0),0xffffffff), iVar3 != 0)) {
      return 0xffffffff;
    }
    puVar9 = auStack_38;
    puVar10 = auStack_34;
    (**(code **)(iVar7 + 0x114))
              (piVar8,param_3,param_4,1,&local_40,&local_48,auStack_3c,puVar9,puVar10);
    if (param_8 == 0) {
      unaff_r6 = 0;
    }
    if (param_8 != 0) {
      unaff_r6 = 1;
    }
    uVar5 = unaff_r6 + 1;
    iVar3 = (**(code **)(iVar7 + 0x11c))(piVar8,local_40,uVar5);
    if (iVar3 == 0) {
      atomic32Inc(iVar7 + 0x100);
      iVar3 = (**(code **)(iVar7 + 0x120))(param_1,param_2,local_40,param_2 == 1,uVar5);
      if (iVar3 == 0) {
        puts(DAT_300cec68);
        if (*local_44 == 0) {
          semGive(*(undefined4 *)(param_1 + 0x1d0));
        }
        return 0xffffffff;
      }
    }
    else {
      atomic32Inc(iVar7 + 0xfc);
    }
    if (0 < *(short *)(iVar3 + 0x5c)) {
      FUN_300cd160(param_1,piVar8,iVar3,local_48,local_48 + 1);
    }
    if (param_8 == 0) {
      bcopy((void *)(local_48 * *(int *)(param_1 + 0x1fc) + *(int *)(iVar3 + 0x24) + param_5),
            param_6,param_7);
    }
    else if ((param_8 == 1) || (param_8 == 2)) {
      bcopy(param_6,(void *)(local_48 * *(int *)(param_1 + 0x1fc) + *(int *)(iVar3 + 0x24) + param_5
                            ),param_7);
      if ((int)*(short *)(iVar3 + 0x5e) != *(int *)(iVar7 + 0x110)) {
        FUN_300cd0d0(piVar8,iVar3,local_48,local_48 + 1);
      }
      if (*local_44 == 0) {
        if (*(int *)(iVar3 + 0x20) == 0) {
          *(undefined4 *)(iVar3 + 0x20) = 1;
          *(int *)(iVar7 + 0xe8) = *(int *)(iVar7 + 0xe8) + 1;
          dllRemove(iVar7 + 0xcc,iVar3);
          dllAdd(iVar7 + 0xd4,iVar3);
        }
      }
      else if (*(int *)(iVar3 + 0x20) == 0) {
        *(undefined4 *)(iVar3 + 0x20) = 1;
        atomic32Inc(iVar7 + 0xe8);
      }
      if ((param_8 == 2) &&
         (iVar4 = dosFsXbdBlkWrite(param_1,param_3,param_4,1,0,
                                   local_48 * *(int *)(param_1 + 0x1fc) + *(int *)(iVar3 + 0x24),2,
                                   puVar9,puVar10,param_3,param_4), iVar4 == -1)) {
        iVar4 = iVar3 + (local_48 >> 5) * 4;
        uVar6 = ~(1 << (local_48 & 0x1f));
        *(uint *)(iVar4 + 0x60) = *(uint *)(iVar4 + 0x60) & uVar6;
        *(short *)(iVar3 + 0x5c) = *(short *)(iVar3 + 0x5c) + 1;
        *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) & uVar6;
        iVar4 = *(short *)(iVar3 + 0x5e) + -1;
        *(short *)(iVar3 + 0x5e) = (short)iVar4;
        if (iVar4 * 0x10000 >> 0x10 == 0) {
          *(undefined4 *)(iVar3 + 0x20) = 0;
          atomic32Dec(iVar7 + 0xe8);
        }
        if (*local_44 != 0) {
          spinLockTaskTake(*(undefined4 *)(iVar3 + 0xc));
          *(undefined4 *)(iVar3 + 0x160) = 0;
          *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) & ~uVar5;
          if (0 < *(int *)(iVar3 + 0x18)) {
            *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + -1;
            semGive(*(undefined4 *)(iVar3 + 0x1c));
          }
          spinLockTaskGive(*(undefined4 *)(iVar3 + 0xc));
          if (*local_44 != 0) {
            return 0xffffffff;
          }
        }
        semGive(*(undefined4 *)(param_1 + 0x1d0));
        return 0xffffffff;
      }
    }
    if (*local_44 != 0) {
      spinLockTaskTake(*(undefined4 *)(iVar3 + 0xc));
      *(undefined4 *)(iVar3 + 0x160) = 0;
      *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) & ~uVar5;
      if (0 < *(int *)(iVar3 + 0x18)) {
        *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + -1;
        semGive(*(undefined4 *)(iVar3 + 0x1c));
      }
      spinLockTaskGive(*(undefined4 *)(iVar3 + 0xc));
      if (*(uint *)(iVar7 + 0xec) <= *(uint *)(iVar7 + 0xe8)) {
        semGive(*(undefined4 *)(param_1 + 700));
      }
      if (*local_44 != 0) {
        return 0;
      }
    }
    semGive(*(undefined4 *)(param_1 + 0x1d0));
    return 0;
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = 0x16;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300cdfcc @ 0x300CDFCC  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300cdb24
 * Константы: 0x300CDFCC
 * ---------------------------------------------------------------- */
void FUN_300cdfcc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  FUN_300cdb24(param_1,0,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ce008 @ 0x300CE008  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300cdb24
 * Константы: 0x300CE008
 * ---------------------------------------------------------------- */
void FUN_300ce008(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  FUN_300cdb24(param_1,1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ce044 @ 0x300CE044  (примерный размер ~2264 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 16
 * Вызывает: FUN_300cc5fc, FUN_300cc7c8, FUN_300cd0d0, FUN_300cd160, __errno, atomic32Inc, bcopy, bzero, dllAdd, dllRemove, dosFsXbdBlkCopy, puts, semGive, semTake
 *           ...
 * Константы: 0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFD, 0x300CE044
 * Данные: DAT_300ce368, DAT_300cf2e0
 * ---------------------------------------------------------------- */
undefined4
FUN_300ce044(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
            int param_7)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int unaff_r10;
  int iVar10;
  bool bVar11;
  int local_a4;
  int local_a0;
  int local_9c;
  int *local_98;
  int local_94;
  void *local_90;
  void *local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  uint local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int iStack_5c;
  int local_58;
  int local_54;
  int local_50;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  
  iVar5 = 0;
  local_9c = 0;
  local_90 = (void *)0x0;
  local_8c = (void *)0x0;
  piVar9 = (int *)(param_1 + 0x148);
  if (*piVar9 == 0) {
    uVar1 = dosFsXbdBlkCopy(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    return uVar1;
  }
  if (param_7 == 0) {
LAB_300ce0d4:
    if (param_7 == 0 && param_6 == 0) {
      return 0;
    }
  }
  else if (param_7 < 1) {
    if (param_7 < 1) {
      return 0;
    }
    goto LAB_300ce0d4;
  }
  local_48 = *(uint *)(param_1 + 500);
  local_44 = *(uint *)(param_1 + 0x1f8);
  bVar11 = param_3 <= local_44;
  if (local_44 == param_3) {
LAB_300ce108:
    if (local_44 == param_3) {
      bVar11 = param_2 <= local_48;
    }
    if (!bVar11) goto LAB_300ce138;
  }
  else if ((int)local_44 < (int)param_3) {
    if ((int)local_44 < (int)param_3) goto LAB_300ce138;
    goto LAB_300ce108;
  }
  bVar11 = param_5 <= local_44;
  if (local_44 == param_5) {
LAB_300ce130:
    if (local_44 == param_5) {
      bVar11 = param_4 <= local_48;
    }
    if (!bVar11) {
LAB_300ce138:
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 0x16;
      return 0xffffffff;
    }
  }
  else {
    if ((int)local_44 < (int)param_5) goto LAB_300ce138;
    if ((int)local_44 < (int)param_5) goto LAB_300ce130;
  }
  local_40 = param_2 + param_6;
  local_3c = param_3 + param_7 + (uint)CARRY4(param_2,param_6);
  bVar11 = local_3c <= local_44;
  if (local_44 == local_3c) {
LAB_300ce184:
    if (local_44 == local_3c) {
      bVar11 = local_40 <= local_48;
    }
    if (!bVar11) goto LAB_300ce1cc;
  }
  else if ((int)local_44 < (int)local_3c) {
    if ((int)local_44 < (int)local_3c) goto LAB_300ce1cc;
    goto LAB_300ce184;
  }
  local_40 = param_4 + param_6;
  local_3c = param_5 + param_7 + (uint)CARRY4(param_4,param_6);
  bVar11 = local_3c <= local_44;
  if (local_44 != local_3c) {
    if ((int)local_44 < (int)local_3c) goto LAB_300ce1cc;
    if ((int)local_3c <= (int)local_44) goto LAB_300ce1e4;
  }
  if (local_44 == local_3c) {
    bVar11 = local_40 <= local_48;
  }
  if (bVar11) {
LAB_300ce1e4:
    local_98 = DAT_300ce368;
    if ((*DAT_300ce368 == 0) &&
       (iVar3 = semTake(*(undefined4 *)(param_1 + 0x1d0),0xffffffff), iVar3 != 0)) {
      return 0xffffffff;
    }
    (**(code **)(param_1 + 0x198))
              (piVar9,param_2,param_3,param_6,&local_80,&local_68,&local_64,&local_60,&iStack_5c);
    iVar3 = local_80;
    local_88 = 0;
    (**(code **)(param_1 + 0x198))
              (piVar9,param_4,param_5,param_6,&local_7c,&local_a4,&local_78,&local_58,&local_74);
    local_a0 = local_7c;
    local_84 = 0;
    local_70 = 0;
    iVar6 = 0;
    iVar7 = 0;
    do {
      iVar8 = iVar7;
      if (local_88 != iVar3) {
        local_54 = 1;
        local_88 = iVar3;
        local_94 = (**(code **)(param_1 + 0x1a0))(piVar9,iVar3);
        if (local_94 == 0) {
          atomic32Inc(param_1 + 0x184);
          local_94 = (**(code **)(param_1 + 0x1a4))(param_1,1,iVar3,1,1);
          if (local_94 == 0) {
            puts(DAT_300cf2e0);
            if (*local_98 == 0) {
              semGive(*(undefined4 *)(param_1 + 0x1d0));
            }
            return 0xffffffff;
          }
        }
        else {
          atomic32Inc(param_1 + 0x180);
        }
        if (0 < *(short *)(local_94 + 0x5c)) {
          if (iVar3 == local_80) {
            iVar4 = local_68;
            iVar10 = local_68 + local_64;
          }
          else {
            iVar4 = 0;
            iVar10 = iStack_5c;
            if (iVar3 != local_60) {
              iVar10 = *(int *)(param_1 + 0x194);
            }
          }
          FUN_300cd160(param_1,piVar9,local_94,iVar4,iVar10);
        }
        if ((*local_98 != 0) && (iVar8 = local_94, iVar7 != 0)) {
          spinLockTaskTake(*(undefined4 *)(iVar7 + 0xc));
          *(undefined4 *)(iVar7 + 0x160) = 0;
          *(uint *)(iVar7 + 0x10) = *(uint *)(iVar7 + 0x10) & 0xfffffffe;
          if (0 < *(int *)(iVar7 + 0x18)) {
            *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + -1;
            semGive(*(undefined4 *)(iVar7 + 0x1c));
          }
          spinLockTaskGive(*(undefined4 *)(iVar7 + 0xc));
          iVar8 = local_94;
        }
      }
      if (local_54 != 0) {
        local_54 = 0;
        local_90 = *(void **)(local_94 + 0x24);
        if (iVar3 == local_80) {
          local_90 = (void *)(local_68 * *(int *)(param_1 + 0x1fc) + (int)local_90);
          iVar5 = local_64;
        }
        else {
          iVar5 = iStack_5c;
          if (iVar3 != local_60) {
            iVar5 = *(int *)(param_1 + 0x194);
          }
        }
      }
      iVar4 = iVar6;
      if (local_84 != local_a0) {
        local_84 = local_a0;
        local_50 = 1;
        unaff_r10 = (**(code **)(param_1 + 0x1a0))(piVar9,local_a0,2);
        if (unaff_r10 == 0) {
          atomic32Inc(param_1 + 0x184);
          unaff_r10 = (**(code **)(param_1 + 0x1a4))(param_1,1,local_a0,0,2);
          if (unaff_r10 == 0) {
            puts(DAT_300cf2e0);
            if (*local_98 == 0) {
              semGive(*(undefined4 *)(param_1 + 0x1d0));
            }
            return 0xffffffff;
          }
        }
        else {
          atomic32Inc(param_1 + 0x180);
        }
        if (local_a0 == local_7c) {
          if (0 < *(short *)(unaff_r10 + 0x5c)) {
            FUN_300cc5fc(unaff_r10,local_a4,local_a4 + local_78);
          }
          if ((int)*(short *)(unaff_r10 + 0x5e) != *(int *)(param_1 + 0x194)) {
            FUN_300cd0d0(piVar9,unaff_r10,local_a4,local_a4 + local_78);
          }
        }
        else if (local_a0 == local_58) {
          if (0 < *(short *)(unaff_r10 + 0x5c)) {
            FUN_300cc5fc(unaff_r10,0,local_74);
          }
          if ((int)*(short *)(unaff_r10 + 0x5e) != *(int *)(param_1 + 0x194)) {
            FUN_300cd0d0(piVar9,unaff_r10,0,local_74);
          }
        }
        else {
          *(undefined2 *)(unaff_r10 + 0x5c) = 0;
          *(short *)(unaff_r10 + 0x5e) = (short)*(undefined4 *)(param_1 + 0x194);
          bzero((void *)(unaff_r10 + 0x60),0x80);
          bzero((void *)(unaff_r10 + 0xe0),0x80);
        }
        if (*local_98 == 0) {
          if (*(int *)(unaff_r10 + 0x20) == 0) {
            *(undefined4 *)(unaff_r10 + 0x20) = 1;
            *(int *)(param_1 + 0x16c) = *(int *)(param_1 + 0x16c) + 1;
            dllRemove(param_1 + 0x150,unaff_r10);
            dllAdd(param_1 + 0x158,unaff_r10);
          }
        }
        else {
          if (*(int *)(unaff_r10 + 0x20) == 0) {
            *(undefined4 *)(unaff_r10 + 0x20) = 1;
            atomic32Inc(param_1 + 0x16c);
          }
          iVar4 = unaff_r10;
          if (iVar6 != 0) {
            spinLockTaskTake(*(undefined4 *)(iVar6 + 0xc));
            *(undefined4 *)(iVar6 + 0x160) = 0;
            *(uint *)(iVar6 + 0x10) = *(uint *)(iVar6 + 0x10) & 0xfffffffd;
            if (0 < *(int *)(iVar6 + 0x18)) {
              *(int *)(iVar6 + 0x18) = *(int *)(iVar6 + 0x18) + -1;
              semGive(*(undefined4 *)(iVar6 + 0x1c));
            }
            spinLockTaskGive(*(undefined4 *)(iVar6 + 0xc));
          }
        }
      }
      local_6c = *(int *)(param_1 + 0x1fc);
      if (local_50 != 0) {
        local_50 = 0;
        local_8c = *(void **)(unaff_r10 + 0x24);
        if (local_a0 == local_7c) {
          local_8c = (void *)(local_a4 * local_6c + (int)local_8c);
          local_9c = local_78;
        }
        else if (local_a0 == local_58) {
          local_9c = local_74;
        }
        else {
          local_9c = *(int *)(param_1 + 0x194);
        }
      }
      iVar6 = iVar5;
      if (iVar5 < local_9c) {
        iVar3 = iVar3 + 1;
        local_9c = local_9c - iVar5;
      }
      else {
        if (local_9c < iVar5) {
          iVar5 = iVar5 - local_9c;
          iVar6 = local_9c;
        }
        else {
          iVar3 = iVar3 + 1;
        }
        local_a0 = local_a0 + 1;
      }
      bcopy(local_90,local_8c,local_6c * iVar6);
      if (iVar3 == local_88) {
        if (local_a0 != local_84) goto LAB_300ce7cc;
      }
      else if (local_a0 == local_84) {
        local_8c = (void *)(iVar6 * *(int *)(param_1 + 0x1fc) + (int)local_8c);
      }
      else {
LAB_300ce7cc:
        if (iVar3 == local_88) {
          local_90 = (void *)(iVar6 * *(int *)(param_1 + 0x1fc) + (int)local_90);
        }
      }
      local_70 = local_70 + iVar6;
      iVar6 = iVar4;
      iVar7 = iVar8;
      if (param_7 == 0 && local_70 == param_6) {
        if (*local_98 != 0) {
          spinLockTaskTake(*(undefined4 *)(iVar8 + 0xc),param_7,local_70);
          *(undefined4 *)(iVar8 + 0x160) = 0;
          *(uint *)(iVar8 + 0x10) = *(uint *)(iVar8 + 0x10) & 0xfffffffe;
          if (0 < *(int *)(iVar8 + 0x18)) {
            *(int *)(iVar8 + 0x18) = *(int *)(iVar8 + 0x18) + -1;
            semGive(*(undefined4 *)(iVar8 + 0x1c));
          }
          spinLockTaskGive(*(undefined4 *)(iVar8 + 0xc));
          spinLockTaskTake(*(undefined4 *)(iVar4 + 0xc));
          *(undefined4 *)(iVar4 + 0x160) = 0;
          *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & 0xfffffffd;
          if (0 < *(int *)(iVar4 + 0x18)) {
            *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + -1;
            semGive(*(undefined4 *)(iVar4 + 0x1c));
          }
          spinLockTaskGive(*(undefined4 *)(iVar4 + 0xc));
        }
        if (*(uint *)(param_1 + 0x170) <= *(uint *)(param_1 + 0x16c)) {
          if (*local_98 == 0) {
            FUN_300cc7c8(param_1,1,0);
          }
          else {
            semGive(*(undefined4 *)(param_1 + 700));
          }
        }
        if (*local_98 == 0) {
          semGive(*(undefined4 *)(param_1 + 0x1d0));
        }
        return 0;
      }
    } while( true );
  }
LAB_300ce1cc:
  puVar2 = (undefined4 *)__errno();
  *puVar2 = 0x16;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300ce91c @ 0x300CE91C  (примерный размер ~464 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: semGive, spinLockTaskGive, spinLockTaskTake, xbdIoctl
 * Вызывают: FUN_300ceaec
 * Константы: 0x300CE91C, 0xFFFFFFF7
 * Данные: DAT_300cf8a4
 * ---------------------------------------------------------------- */
undefined4 FUN_300ce91c(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_38;
  int local_34;
  undefined4 local_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  
  local_24 = *param_2;
  local_20 = param_2[1];
  (**(code **)(param_1 + 0x114))
            (param_1 + 0xc4,local_24,local_20,param_2[2],&local_30,&local_38,&local_34,auStack_2c,
             auStack_28);
  iVar2 = (**(code **)(param_1 + 0x11c))(param_1 + 0xc4,local_30,8);
  if (iVar2 != 0) {
    uVar6 = *(uint *)(param_1 + 0x110);
    if (*(ushort *)(param_1 + 0x5e) == uVar6) {
LAB_300cea44:
      (**(code **)(param_1 + 0x124))(param_1 + 0xc4,iVar2);
    }
    else {
      uVar5 = local_38 + local_34;
      for (; local_38 < uVar5; local_38 = local_38 + 1) {
        uVar1 = 1 << (local_38 & 0x1f);
        iVar4 = iVar2 + (local_38 >> 5) * 4;
        if ((*(uint *)(iVar4 + 0x60) & uVar1) != 0) {
          *(uint *)(iVar4 + 0x60) = *(uint *)(iVar4 + 0x60) & ~uVar1;
          *(short *)(iVar2 + 0x5c) = *(short *)(iVar2 + 0x5c) + 1;
        }
        if ((*(uint *)(iVar4 + 0xe0) & uVar1) != 0) {
          *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) & ~uVar1;
          *(short *)(iVar2 + 0x5e) = *(short *)(iVar2 + 0x5e) + -1;
        }
        if ((int)*(short *)(iVar2 + 0x5c) == uVar6) goto LAB_300cea44;
      }
    }
    if (*DAT_300cf8a4 != 0) {
      spinLockTaskTake(*(undefined4 *)(iVar2 + 0xc));
      *(undefined4 *)(iVar2 + 0x160) = 0;
      *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) & 0xfffffff7;
      if (0 < *(int *)(iVar2 + 0x18)) {
        *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + -1;
        semGive(*(undefined4 *)(iVar2 + 0x1c));
      }
      spinLockTaskGive(*(undefined4 *)(iVar2 + 0xc));
    }
  }
  if (*(int *)(param_1 + 0xa4) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = xbdIoctl(*(undefined4 *)(param_1 + 0x28),0x47,param_2);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300ceaec @ 0x300CEAEC  (примерный размер ~1064 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 15
 * Вызывает: FUN_300cbb4c, FUN_300cc5fc, FUN_300cd0d0, FUN_300ce91c, atomic32Inc, bzero, dllAdd, dllRemove, dosFsXbdIoctl, errnoSet, semGive, semTake, spinLockTaskGive, spinLockTaskTake
 *           ...
 * Константы: 0x300CEAEC, 0xFFFFFFFF, 0xFFFFFFFD
 * Данные: DAT_300cf8a4, DAT_300cf8a8, DAT_300cf8ac, DAT_300cf8b0
 * ---------------------------------------------------------------- */
int FUN_300ceaec(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_34;
  undefined4 local_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  
  iVar2 = param_1 + param_2 * 0x84;
  piVar3 = (int *)(iVar2 + 0xc4);
  if (*piVar3 == 0) {
    iVar2 = dosFsXbdIoctl(param_1,param_3,param_4);
    return iVar2;
  }
  if (param_3 == DAT_300cf8a8) {
LAB_300ceb6c:
    if ((*DAT_300cf8a4 == 0) &&
       (iVar1 = semTake(*(undefined4 *)(param_1 + 0x1d0),0xffffffff), iVar1 != 0)) {
      return -1;
    }
  }
  else if (param_3 == DAT_300cf8a8 || param_3 < DAT_300cf8a8) {
    if ((param_3 == DAT_300cf8ac) || (param_3 == DAT_300cf8b0)) goto LAB_300ceb6c;
  }
  else if ((param_3 == 0x38) || (param_3 == 0x47)) goto LAB_300ceb6c;
  if (param_3 == DAT_300cf8a8) {
    (**(code **)(iVar2 + 0x114))
              (piVar3,param_4,0,1,&local_30,&local_34,auStack_2c,auStack_28,auStack_24);
    iVar1 = (**(code **)(iVar2 + 0x11c))(piVar3,local_30,2);
    if (iVar1 != 0) {
      atomic32Inc(iVar2 + 0xfc);
LAB_300ced20:
      bzero((void *)(local_34 * *(size_t *)(param_1 + 0x1fc) + *(int *)(iVar1 + 0x24)),
            *(size_t *)(param_1 + 0x1fc));
      if (0 < *(short *)(iVar1 + 0x5c)) {
        FUN_300cc5fc(iVar1,local_34,local_34 + 1);
      }
      if ((int)*(short *)(iVar1 + 0x5e) != *(int *)(iVar2 + 0x110)) {
        FUN_300cd0d0(piVar3,iVar1,local_34,local_34 + 1);
      }
      if (*DAT_300cf8a4 == 0) {
        if (*(int *)(iVar1 + 0x20) == 0) {
          *(undefined4 *)(iVar1 + 0x20) = 1;
          *(int *)(iVar2 + 0xe8) = *(int *)(iVar2 + 0xe8) + 1;
          dllRemove(iVar2 + 0xcc,iVar1);
          dllAdd(iVar2 + 0xd4,iVar1);
        }
      }
      else {
        if (*(int *)(iVar1 + 0x20) == 0) {
          *(undefined4 *)(iVar1 + 0x20) = 1;
          atomic32Inc(iVar2 + 0xe8);
        }
        spinLockTaskTake(*(undefined4 *)(iVar1 + 0xc));
        *(undefined4 *)(iVar1 + 0x160) = 0;
        *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffd;
        if (0 < *(int *)(iVar1 + 0x18)) {
          *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -1;
          semGive(*(undefined4 *)(iVar1 + 0x1c));
        }
        spinLockTaskGive(*(undefined4 *)(iVar1 + 0xc));
        if (*(uint *)(iVar2 + 0xec) <= *(uint *)(iVar2 + 0xe8)) {
          semGive(*(undefined4 *)(param_1 + 700));
        }
      }
      goto LAB_300cee30;
    }
    atomic32Inc(iVar2 + 0x100);
    iVar1 = (**(code **)(iVar2 + 0x120))(param_1,param_2,local_30,0,2);
    if (iVar1 != 0) goto LAB_300ced20;
  }
  else {
    if (param_3 == DAT_300cf8a8 || param_3 < DAT_300cf8a8) {
      if (param_3 != DAT_300cf8ac) {
        if (param_3 != DAT_300cf8b0) {
LAB_300cee38:
          iVar2 = xbdIoctl(*(undefined4 *)(param_1 + 0x28),param_3,param_4);
          if (iVar2 != 0) {
            errnoSet(iVar2);
            return -1;
          }
          return 0;
        }
        iVar2 = FUN_300cbb4c(param_1,1,1,1);
        goto LAB_300cee68;
      }
LAB_300cec00:
      iVar2 = FUN_300cbb4c(param_1,1,0,1);
      if (iVar2 == 0) {
        iVar2 = dosFsXbdIoctl(param_1,DAT_300cf8ac,0);
      }
      if (param_3 != 0x38) goto LAB_300cee68;
      iVar2 = xbdIoctl(*(undefined4 *)(param_1 + 0x28),0x38,param_4);
    }
    else {
      if (param_3 == 0x38) goto LAB_300cec00;
      if (param_3 != 0x47) goto LAB_300cee38;
      iVar2 = FUN_300ce91c(param_1,param_4);
    }
    if ((iVar2 == 0) || (iVar2 == 0x23)) {
LAB_300cee30:
      iVar2 = 0;
      goto LAB_300cee68;
    }
    errnoSet(iVar2);
  }
  iVar2 = -1;
LAB_300cee68:
  if (*DAT_300cf8a4 == 0) {
    semGive(*(undefined4 *)(param_1 + 0x1d0));
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300cef14 @ 0x300CEF14  (примерный размер ~212 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_300cd078, semGive, semTake, spinLockTaskGive, spinLockTaskTake, taskIdSelf
 * Константы: 0x300CEF14, 0xFFFFFFFF, 0xFFFFFFF7
 * ---------------------------------------------------------------- */
void FUN_300cef14(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  for (puVar2 = *(undefined4 **)(param_1 + 8); puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)*puVar2) {
    while (spinLockTaskTake(puVar2[3]), puVar2[4] != 0) {
      puVar2[6] = puVar2[6] + 1;
      spinLockTaskGive(puVar2[3]);
      semTake(puVar2[7],0xffffffff);
    }
    uVar1 = taskIdSelf();
    puVar2[0x58] = uVar1;
    puVar2[4] = puVar2[4] | 8;
    spinLockTaskGive(puVar2[3]);
    if (puVar2[5] != -1) {
      FUN_300cd078(param_1,puVar2);
    }
    spinLockTaskTake(puVar2[3]);
    puVar2[0x58] = 0;
    puVar2[4] = puVar2[4] & 0xfffffff7;
    if (0 < (int)puVar2[6]) {
      puVar2[6] = puVar2[6] + -1;
      semGive(puVar2[7]);
    }
    spinLockTaskGive(puVar2[3]);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cefe8 @ 0x300CEFE8  (примерный размер ~488 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 10
 * Вызывает: FUN_300cc0c0, FUN_300cc684, atomic32Dec, bzero, printf, semGive, spinLockTaskGive, spinLockTaskTake, taskDelay, taskIdSelf
 * Константы: 0xFFFFFFFB, 0x300CEFE8, 0xFFFFFFFF
 * Данные: DAT_300cf8b4
 * ---------------------------------------------------------------- */
undefined4 FUN_300cefe8(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  
  iVar4 = param_1 + param_2 * 0x84;
  iVar3 = 0;
  do {
    for (puVar5 = *(undefined4 **)(iVar4 + 0xcc); puVar5 != (undefined4 *)0x0;
        puVar5 = (undefined4 *)*puVar5) {
      spinLockTaskTake(puVar5[3]);
      if ((puVar5[4] == 0) && (puVar5[8] != 0)) {
        uVar1 = taskIdSelf();
        puVar5[0x58] = uVar1;
        puVar5[4] = puVar5[4] | 4;
        spinLockTaskGive(puVar5[3]);
        if ((int)*(short *)((int)puVar5 + 0x5e) == *(int *)(iVar4 + 0x110)) {
          uVar6 = (**(code **)(iVar4 + 0x118))(iVar4 + 0xc4,puVar5[5]);
          iVar2 = FUN_300cc0c0(param_1,puVar5,puVar5 + 10,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20)
                               ,*(int *)(param_1 + 0x1fc) * *(int *)(iVar4 + 0x110),2);
          *(undefined2 *)((int)puVar5 + 0x5e) = 0;
          bzero(puVar5 + 0x38,0x80);
        }
        else {
          iVar2 = FUN_300cc684(param_1,iVar4 + 0xc4,puVar5,0,*(int *)(iVar4 + 0x110));
        }
        if (iVar2 != 0) {
          printf(DAT_300cf8b4,puVar5[0x10]);
          spinLockTaskTake(puVar5[3]);
          puVar5[0x58] = 0;
          puVar5[4] = puVar5[4] & 0xfffffffb;
          if (0 < (int)puVar5[6]) {
            puVar5[6] = puVar5[6] + -1;
            semGive(puVar5[7]);
          }
          spinLockTaskGive(puVar5[3]);
          return 0xffffffff;
        }
        puVar5[8] = 0;
        atomic32Dec(iVar4 + 0xe8);
        spinLockTaskTake(puVar5[3]);
        puVar5[0x58] = 0;
        puVar5[4] = puVar5[4] & 0xfffffffb;
        if (0 < (int)puVar5[6]) {
          puVar5[6] = puVar5[6] + -1;
          semGive(puVar5[7]);
        }
      }
      spinLockTaskGive(puVar5[3]);
    }
    if ((*(int *)(iVar4 + 0xe8) < 1) || (1 < iVar3)) {
      return 0;
    }
    taskDelay(1);
    iVar3 = iVar3 + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300cf1d0 @ 0x300CF1D0  (примерный размер ~772 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 11
 * Вызывает: FUN_300cc194, FUN_300cc684, atomic32Dec, atomic32Get, bzero, puts, semGive, semTake, spinLockTaskGive, spinLockTaskTake, taskIdSelf
 * Вызывают: FUN_300cf4d4
 * Константы: 0xFFFFFFFB, 0xFFFFFFFF, 0x300CF1D0
 * Данные: DAT_300cf8b8, DAT_300cf8bc
 * ---------------------------------------------------------------- */
undefined4 FUN_300cf1d0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  
  iVar3 = param_1 + param_2 * 0x84;
  *(undefined4 *)(iVar3 + 0x138) = 0;
  *(undefined4 *)(iVar3 + 0x13c) = 0;
  iVar4 = iVar3 + 0xc4;
  for (puVar5 = *(undefined4 **)(iVar3 + 0xcc); puVar5 != (undefined4 *)0x0;
      puVar5 = (undefined4 *)*puVar5) {
    spinLockTaskTake(puVar5[3]);
    if (((puVar5[4] == 0) && (puVar5[8] != 0)) &&
       ((int)*(short *)((int)puVar5 + 0x5e) == *(int *)(iVar3 + 0x110))) {
      uVar2 = taskIdSelf();
      puVar5[0x58] = uVar2;
      puVar5[4] = puVar5[4] | 4;
      spinLockTaskGive(puVar5[3]);
      uVar6 = (**(code **)(iVar3 + 0x118))(iVar4,puVar5[5]);
      FUN_300cc194(param_1,iVar4,puVar5 + 10,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20),
                   *(int *)(param_1 + 0x1fc) * *(int *)(iVar3 + 0x110),2);
      puVar5[8] = 0xffffffff;
    }
    else {
      spinLockTaskGive(puVar5[3]);
    }
  }
  iVar1 = atomic32Get(iVar3 + 0x138);
  if (0 < iVar1) {
    semTake(*(undefined4 *)(iVar3 + 0x134),0xffffffff);
  }
  for (puVar5 = *(undefined4 **)(iVar3 + 0xcc); puVar5 != (undefined4 *)0x0;
      puVar5 = (undefined4 *)*puVar5) {
    if (puVar5[8] == -1) {
      if (*(int *)(iVar3 + 0x13c) == 0) {
        puVar5[8] = 0;
        atomic32Dec(iVar3 + 0xe8);
        *(undefined2 *)((int)puVar5 + 0x5e) = 0;
        bzero(puVar5 + 0x38,0x80);
      }
      else {
        puVar5[8] = 1;
      }
      spinLockTaskTake(puVar5[3]);
      puVar5[0x58] = 0;
      puVar5[4] = puVar5[4] & 0xfffffffb;
      if (0 < (int)puVar5[6]) {
        puVar5[6] = puVar5[6] + -1;
        semGive(puVar5[7]);
      }
      spinLockTaskGive(puVar5[3]);
    }
  }
  if (*(int *)(iVar3 + 0x13c) == 0) {
    if (*(uint *)(iVar3 + 0xec) >> 1 < *(uint *)(iVar3 + 0xe8)) {
      for (puVar5 = *(undefined4 **)(iVar3 + 0xcc); puVar5 != (undefined4 *)0x0;
          puVar5 = (undefined4 *)*puVar5) {
        spinLockTaskTake(puVar5[3]);
        if (((puVar5[4] == 0) && (puVar5[8] != 0)) &&
           ((int)*(short *)((int)puVar5 + 0x5e) != *(int *)(iVar3 + 0x110))) {
          uVar2 = taskIdSelf();
          puVar5[0x58] = uVar2;
          puVar5[4] = puVar5[4] | 4;
          spinLockTaskGive(puVar5[3]);
          iVar1 = FUN_300cc684(param_1,iVar4,puVar5,0,*(undefined4 *)(iVar3 + 0x110));
          if (iVar1 != 0) {
            puts(DAT_300cf8bc);
            spinLockTaskTake(puVar5[3]);
            puVar5[0x58] = 0;
            puVar5[4] = puVar5[4] & 0xfffffffb;
            if (0 < (int)puVar5[6]) {
              puVar5[6] = puVar5[6] + -1;
              semGive(puVar5[7]);
            }
            spinLockTaskGive(puVar5[3]);
            return puVar5[0x10];
          }
          puVar5[8] = 0;
          atomic32Dec(iVar3 + 0xe8);
          spinLockTaskTake(puVar5[3]);
          puVar5[0x58] = 0;
          puVar5[4] = puVar5[4] & 0xfffffffb;
          if (0 < (int)puVar5[6]) {
            puVar5[6] = puVar5[6] + -1;
            semGive(puVar5[7]);
          }
        }
        spinLockTaskGive(puVar5[3]);
      }
    }
    uVar2 = 0;
  }
  else {
    puts(DAT_300cf8b8);
    uVar2 = *(undefined4 *)(iVar3 + 0x13c);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300cf4d4 @ 0x300CF4D4  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300cf1d0, semTake
 * Константы: 0xFFFFFFFF, 0x300CF4D4
 * ---------------------------------------------------------------- */
void FUN_300cf4d4(int param_1)

{
  int iVar1;
  
  iVar1 = semTake(*(undefined4 *)(param_1 + 700),0xffffffff);
  if (iVar1 != -1) {
    do {
      iVar1 = 0;
      do {
        FUN_300cf1d0(param_1,iVar1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 2);
      iVar1 = semTake(*(undefined4 *)(param_1 + 700),0xffffffff);
    } while (iVar1 != -1);
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * dosFsCacheTune @ 0x300CF538  (примерный размер ~716 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 11
 * Вызывает: FUN_300cb558, FUN_300cbb4c, __div32, bzero, cacheDmaFree, dosFsVolDescGet, free, printf, semDelete, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300CF538
 * Данные: DAT_300cf8a4, DAT_300cf8c0, DAT_300cf8c4, DAT_300cf8c8
 * ---------------------------------------------------------------- */
int dosFsCacheTune(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *__s;
  uint local_30;
  uint local_4;
  
  iVar9 = -1;
  iVar3 = -1;
  if (param_1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar2 = dosFsVolDescGet(param_1,0);
    if (iVar2 == 0) {
      printf(DAT_300cf8c0,param_1);
      iVar1 = -1;
    }
    else {
      iVar1 = semTake(*(undefined4 *)(iVar2 + 0x34),0xffffffff);
      if (iVar1 == -1) {
        iVar1 = -1;
      }
      else {
        local_4 = param_2;
        if (0x400 < *(ushort *)(iVar2 + 0x5e) * param_2) {
          local_4 = __div32(0x400,(uint)*(ushort *)(iVar2 + 0x5e));
        }
        local_30 = param_3;
        if (0x400 < param_3) {
          local_30 = 0x400;
        }
        iVar5 = 0;
        iVar1 = iVar2 + 0xc4;
        do {
          uVar7 = local_30;
          if (iVar5 == 0) {
            uVar7 = local_4;
          }
          if ((iVar1 != 0) && (*(uint *)(iVar1 + 0x40) != uVar7)) {
            if ((iVar9 == -1) || (iVar5 < iVar9)) {
              iVar9 = iVar5;
            }
            if ((iVar3 == -1) || (iVar3 < iVar5)) {
              iVar3 = iVar5;
            }
          }
          iVar1 = iVar1 + 0x84;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 2);
        if ((iVar9 == -1) && (iVar3 == -1)) {
          semGive(*(undefined4 *)(iVar2 + 0x34));
          iVar1 = 0;
        }
        else {
          iVar1 = semTake(*(undefined4 *)(iVar2 + 0x1d0),0xffffffff);
          if (iVar1 == 0) {
            iVar1 = FUN_300cbb4c(iVar2,iVar3,1,1);
            if (iVar1 == -1) {
              semGive(*(undefined4 *)(iVar2 + 0x1d0));
              semGive(*(undefined4 *)(iVar2 + 0x34));
            }
            if (iVar9 <= iVar3) {
              __s = (undefined4 *)(iVar2 + iVar9 * 0x84 + 0xc4);
              do {
                iVar1 = __s[1];
                uVar6 = *__s;
                uVar7 = 0;
                if (__s[0xd] != 0) {
                  do {
                    if (*(int *)(iVar1 + 0x58) != 0) {
                      semDelete();
                    }
                    if (*(void **)(iVar1 + 0xc) != (void *)0x0) {
                      free(*(void **)(iVar1 + 0xc));
                    }
                    iVar1 = iVar1 + 0x164;
                    uVar7 = uVar7 + 1;
                  } while (uVar7 < (uint)__s[0xd]);
                }
                if (__s[8] == 0) {
                  uVar4 = __s[1];
                }
                else {
                  cacheDmaFree(__s[1]);
                  uVar4 = 0;
                }
                if (*DAT_300cf8a4 != 0) {
                  if ((void *)__s[0x19] != (void *)0x0) {
                    free((void *)__s[0x19]);
                  }
                  if (__s[0x1a] != 0) {
                    semDelete(__s[0x1a]);
                  }
                  if (__s[0x1c] != 0) {
                    semDelete(__s[0x1c]);
                  }
                }
                bzero(__s,0x84);
                if (iVar9 == 0) {
                  __s[0x10] = local_4;
                  uVar8 = DAT_300cf8c4;
                }
                else {
                  __s[0x10] = local_30;
                  uVar8 = DAT_300cf8c8;
                }
                iVar1 = FUN_300cb558(param_1,iVar2,iVar9,uVar8,uVar4,uVar6);
                __s = __s + 0x21;
                iVar9 = iVar9 + 1;
              } while (iVar9 <= iVar3);
            }
            semGive(*(undefined4 *)(iVar2 + 0x1d0));
            semGive(*(undefined4 *)(iVar2 + 0x34));
          }
          else {
            semGive(*(undefined4 *)(iVar2 + 0x34));
            iVar1 = -1;
          }
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * dosFsCacheInfo @ 0x300CF804  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: dosFsVolDescGet, printf, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300CF804
 * Данные: DAT_300cf8c0
 * ---------------------------------------------------------------- */
undefined4 dosFsCacheInfo(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  if (((param_2 == (undefined4 *)0x0) || (param_3 == (undefined4 *)0x0)) || (param_1 == 0)) {
    return 0xffffffff;
  }
  iVar1 = dosFsVolDescGet(param_1,0);
  if (iVar1 == 0) {
    printf(DAT_300cf8c0,param_1);
    return 0xffffffff;
  }
  iVar2 = semTake(*(undefined4 *)(iVar1 + 0x34),0xffffffff);
  if (iVar2 != -1) {
    if (iVar1 != -0xc4) {
      *param_2 = *(undefined4 *)(iVar1 + 0x104);
    }
    if (iVar1 != -0x148) {
      *param_3 = *(undefined4 *)(iVar1 + 0x188);
    }
    semGive(*(undefined4 *)(iVar1 + 0x34));
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300cf8cc @ 0x300CF8CC  (примерный размер ~356 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: dosfsHostToDisk32
 * Вызывают: FUN_300cfe1c, FUN_300d0060, FUN_300d02d8
 * Константы: 0xFFFFFFFF, 0x300CF8CC
 * Данные: DAT_300d099c
 * ---------------------------------------------------------------- */
undefined4 FUN_300cf8cc(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [8];
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  
  iVar7 = *param_1;
  iVar2 = *(int *)(param_1[1] + 0x10);
  iVar4 = *(int *)(iVar7 + 0x30);
  if ((iVar2 != 0) && (*(int *)(iVar4 + 0x80) != 0)) {
    iVar3 = 1;
    iVar6 = iVar2 + *(int *)(iVar7 + 0x50);
    if (1 < *(byte *)(iVar7 + 0x62)) {
      local_34 = 1;
      local_30 = 0;
      do {
        local_28 = 0;
        local_2c = iVar2;
        iVar1 = (**(code **)(iVar4 + 0x48))(iVar7,iVar2,0,iVar6,0,local_34,local_30);
        if (iVar1 != 0) {
          return 0xffffffff;
        }
        iVar3 = iVar3 + 1;
        iVar6 = iVar6 + *(int *)(iVar7 + 0x50);
      } while (iVar3 < (int)(uint)*(byte *)(iVar7 + 0x62));
    }
    cVar5 = ((*(uint *)(*param_1 + 0x9c) & 0xa0000) != 0) + '\x01';
    if (*(int *)(iVar7 + 0x74) == 2) {
      dosfsHostToDisk32(*(undefined4 *)(iVar4 + 0x60),auStack_40);
      dosfsHostToDisk32(*(undefined4 *)(iVar4 + 0x78),auStack_3c);
      iVar2 = (**(code **)(iVar4 + 0x44))(iVar7,1,0,0x1e8,auStack_40,8,cVar5);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
    if (cVar5 == '\x02') {
      (**(code **)(iVar4 + 0x4c))(iVar7,DAT_300d099c,0);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300cfa30 @ 0x300CFA30  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300CFA30
 * ---------------------------------------------------------------- */
void FUN_300cfa30(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  
  iVar2 = *(int *)(param_1 + 0x30);
  *(int *)(iVar2 + 0x80) = param_2;
  if (param_2 != 0) {
    uVar1 = 0;
    iVar3 = (uint)*(byte *)(iVar2 + 0x54) * *(int *)(param_1 + 0x50) + *(int *)(iVar2 + 0x58);
    if (*(int *)(param_1 + 0x50) != 0) {
      do {
        bVar5 = 0;
        iVar4 = uVar1 + *(int *)(iVar2 + 0x58);
        if (*(char *)(param_1 + 0x62) != '\0') {
          do {
            if (*(byte *)(*(int *)(param_1 + 0x30) + 0x54) != bVar5) {
              (**(code **)(iVar2 + 0x48))(param_1,iVar3,0,iVar4,0,1,0,iVar3,0);
            }
            bVar5 = bVar5 + 1;
            iVar4 = iVar4 + *(int *)(param_1 + 0x50);
          } while (bVar5 < *(byte *)(param_1 + 0x62));
        }
        uVar1 = uVar1 + 1;
        iVar3 = iVar3 + 1;
      } while (uVar1 < *(uint *)(param_1 + 0x50));
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300cfb0c @ 0x300CFB0C  (примерный размер ~256 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300cfc0c
 * Константы: 0xFFFFFFFF, 0x300CFB0C
 * Данные: DAT_300d0b60
 * ---------------------------------------------------------------- */
undefined4 FUN_300cfb0c(int param_1,undefined4 param_2,int param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined2 local_28;
  
  iVar5 = *(int *)(param_1 + 0x30);
  uVar7 = param_4 + (param_4 >> 1);
  iVar4 = param_3 * *(int *)(param_1 + 0x50) + *(int *)(iVar5 + 0x58) +
          (uVar7 >> *(sbyte *)(param_1 + 0x84));
  uVar7 = uVar7 & *(ushort *)(param_1 + 0x5c) - 1;
  uVar1 = *(ushort *)(param_1 + 0x5c) - uVar7;
  uVar6 = 2;
  if (uVar1 < 3) {
    uVar6 = uVar1;
  }
  iVar2 = (**(code **)(iVar5 + 0x44))(param_1,iVar4,0,uVar7,&local_28,uVar6,0);
  if (iVar2 == 0) {
    if ((uVar6 == 1) &&
       (iVar4 = (**(code **)(iVar5 + 0x44))(param_1,iVar4 + 1,0,0,(int)&local_28 + 1,1,0),
       iVar4 != 0)) {
      uVar3 = 0xffffffff;
    }
    else {
      if ((param_4 & 1) != 0) {
        local_28 = local_28 >> 4;
      }
      uVar3 = 0;
      *param_5 = DAT_300d0b60 & local_28;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300cfc0c @ 0x300CFC0C  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300cfb0c
 * Константы: 0x300CFC0C
 * ---------------------------------------------------------------- */
undefined4 FUN_300cfc0c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = FUN_300cfb0c(*param_1,param_1 + 0xe,param_2,param_3,&local_c);
  if (iVar1 == -1) {
    param_1[0xf] = 1;
    local_c = 1;
  }
  return local_c;
}

/* ----------------------------------------------------------------
 * FUN_300cfc5c @ 0x300CFC5C  (примерный размер ~448 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300cfe1c
 * Константы: 0xFFFFFFFF, 0x300CFC5C
 * ---------------------------------------------------------------- */
undefined4
FUN_300cfc5c(int param_1,undefined4 param_2,int param_3,uint param_4,uint param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte local_2c;
  byte local_2b [3];
  undefined4 local_28;
  
  iVar5 = *(int *)(param_1 + 0x30);
  uVar6 = param_4 + (param_4 >> 1);
  iVar4 = param_3 * *(int *)(param_1 + 0x50) + *(int *)(iVar5 + 0x58) +
          (uVar6 >> *(sbyte *)(param_1 + 0x84));
  uVar6 = uVar6 & *(ushort *)(param_1 + 0x5c) - 1;
  uVar1 = *(ushort *)(param_1 + 0x5c) - uVar6;
  uVar7 = 2;
  if (uVar1 < 3) {
    uVar7 = uVar1;
  }
  iVar2 = (**(code **)(iVar5 + 0x44))(param_1,iVar4,0,uVar6,&local_2c,uVar7,0);
  if (iVar2 == 0) {
    if ((uVar7 == 1) &&
       (iVar2 = (**(code **)(iVar5 + 0x44))(param_1,iVar4 + 1,0,0,local_2b,1,0), iVar2 != 0)) {
      uVar3 = 0xffffffff;
    }
    else {
      if ((param_4 & 1) == 0) {
        local_2c = (byte)param_5;
        local_2b[0] = local_2b[0] & 0xf0 | (byte)(param_5 >> 8) & 0xf;
      }
      else {
        local_2c = local_2c & 0xf | (byte)(param_5 << 4);
        local_2b[0] = (byte)(param_5 >> 4);
      }
      if ((*(uint *)(param_1 + 0x9c) & 0xa0000) == 0 && param_6 == 0) {
        local_28 = 1;
      }
      else {
        local_28 = 2;
      }
      iVar2 = (**(code **)(iVar5 + 0x44))(param_1,iVar4,0,uVar6,&local_2c,uVar7,local_28);
      if (iVar2 == 0) {
        if ((uVar7 == 1) &&
           (iVar4 = (**(code **)(iVar5 + 0x44))(param_1,iVar4 + 1,0,0,local_2b,1,local_28),
           iVar4 != 0)) {
          uVar3 = 0xffffffff;
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0xffffffff;
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300cfe1c @ 0x300CFE1C  (примерный размер ~228 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300cf8cc, FUN_300cfc5c
 * Константы: 0x300CFE1C
 * ---------------------------------------------------------------- */
int FUN_300cfe1c(int *param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_2c [3];
  
  iVar3 = *param_1;
  iVar1 = *(int *)(iVar3 + 0x30);
  iVar2 = param_2 * *(int *)(iVar3 + 0x50) + *(int *)(iVar1 + 0x58) +
          (param_3 + (param_3 >> 1) >> *(sbyte *)(iVar3 + 0x84));
  if ((*(int *)(param_1[1] + 0x10) != iVar2) && (*(byte *)(iVar1 + 0x54) == param_2)) {
    FUN_300cf8cc();
    *(int *)(param_1[1] + 0x10) = iVar2;
  }
  iVar2 = FUN_300cfc5c(iVar3,param_1 + 0xe,param_2,param_3,param_4,0);
  if (((iVar2 == 0) && (*(byte *)(iVar1 + 0x54) == param_2)) && (param_4 == 0)) {
    local_2c[2] = (int)*(ushort *)(iVar3 + 0x5e);
    local_2c[0] = (param_3 - 2) * local_2c[2] + *(int *)(iVar3 + 0x78);
    local_2c[1] = 0;
    (**(code **)(iVar3 + 0xc0))(iVar3,0x47,local_2c);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300cff00 @ 0x300CFF00  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300cff80
 * Константы: 0x300CFF00, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300cff00(int param_1,undefined4 param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x30) + 0x44))
                    (param_1,param_3 * *(int *)(param_1 + 0x50) +
                             *(int *)(*(int *)(param_1 + 0x30) + 0x58) +
                             ((uint)(param_4 << 1) >> *(sbyte *)(param_1 + 0x84)),0,
                     param_4 << 1 & *(ushort *)(param_1 + 0x5c) - 1,&uStack_1c,2,0);
  if (iVar1 == 0) {
    uVar2 = 0;
    *param_5 = (uint)CONCAT11(uStack_1b,uStack_1c);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300cff80 @ 0x300CFF80  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300cff00
 * Константы: 0x300CFF80
 * ---------------------------------------------------------------- */
undefined4 FUN_300cff80(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = FUN_300cff00(*param_1,param_1 + 0xe,param_2,param_3,&local_c);
  if (iVar1 == -1) {
    param_1[0xf] = 1;
    local_c = 1;
  }
  return local_c;
}

/* ----------------------------------------------------------------
 * FUN_300cffd0 @ 0x300CFFD0  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300d0060
 * Константы: 0x300CFFD0
 * ---------------------------------------------------------------- */
void FUN_300cffd0(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                 int param_6)

{
  undefined4 uVar1;
  undefined1 local_20;
  undefined1 local_1f;
  
  local_20 = (undefined1)param_5;
  local_1f = (undefined1)((uint)param_5 >> 8);
  if ((*(uint *)(param_1 + 0x9c) & 0xa0000) == 0 && param_6 == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  (**(code **)(*(int *)(param_1 + 0x30) + 0x44))
            (param_1,param_3 * *(int *)(param_1 + 0x50) + *(int *)(*(int *)(param_1 + 0x30) + 0x58)
                     + ((uint)(param_4 << 1) >> *(sbyte *)(param_1 + 0x84)),0,
             param_4 << 1 & *(ushort *)(param_1 + 0x5c) - 1,&local_20,2,uVar1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d0060 @ 0x300D0060  (примерный размер ~228 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300cf8cc, FUN_300cffd0
 * Константы: 0x300D0060
 * ---------------------------------------------------------------- */
int FUN_300d0060(int *param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_2c [3];
  
  iVar3 = *param_1;
  iVar2 = *(int *)(iVar3 + 0x30);
  iVar1 = param_2 * *(int *)(iVar3 + 0x50) + *(int *)(iVar2 + 0x58) +
          (param_3 >> (*(byte *)(iVar3 + 0x84) - 1 & 0xff));
  if ((*(int *)(param_1[1] + 0x10) != iVar1) && (*(byte *)(iVar2 + 0x54) == param_2)) {
    FUN_300cf8cc();
    *(int *)(param_1[1] + 0x10) = iVar1;
  }
  iVar1 = FUN_300cffd0(iVar3,param_1 + 0xe,param_2,param_3,param_4,0);
  if (((iVar1 == 0) && (*(byte *)(iVar2 + 0x54) == param_2)) && (param_4 == 0)) {
    local_2c[2] = (int)*(ushort *)(iVar3 + 0x5e);
    local_2c[0] = (param_3 - 2) * local_2c[2] + *(int *)(iVar3 + 0x78);
    local_2c[1] = 0;
    (**(code **)(iVar3 + 0xc0))(iVar3,0x47,local_2c);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300d0144 @ 0x300D0144  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300d01d8
 * Константы: 0x300D0144, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300d0144(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_1c;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x30) + 0x44))
                    (param_1,param_3 * *(int *)(param_1 + 0x50) +
                             *(int *)(*(int *)(param_1 + 0x30) + 0x58) +
                             ((uint)(param_4 << 2) >> *(sbyte *)(param_1 + 0x84)),0,
                     param_4 << 2 & *(ushort *)(param_1 + 0x5c) - 1,&local_1c,4,0);
  if (iVar1 == 0) {
    uVar2 = 0;
    *param_5 = local_1c;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300d01d8 @ 0x300D01D8  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300d0144
 * Константы: 0x300D01D8, 0x0FFFFFFF, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
uint FUN_300d01d8(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uStack_14;
  
  uVar2 = 0xfffffff;
  if (*(byte *)(*(int *)(*param_1 + 0x30) + 0x54) != param_2) {
    uVar2 = 0xffffffff;
  }
  iVar1 = FUN_300d0144(*param_1,param_1 + 0xe,param_2,param_3,&uStack_14);
  if (iVar1 == -1) {
    uStack_14 = 1;
    param_1[0xf] = 1;
  }
  else {
    uStack_14 = uStack_14 & uVar2;
  }
  return uStack_14;
}

/* ----------------------------------------------------------------
 * FUN_300d0238 @ 0x300D0238  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300d02d8
 * Константы: 0x300D0238
 * ---------------------------------------------------------------- */
void FUN_300d0238(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                 int param_6)

{
  undefined4 uVar1;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  
  local_20 = (undefined1)param_5;
  local_1f = (undefined1)((uint)param_5 >> 8);
  local_1e = (undefined1)((uint)param_5 >> 0x10);
  local_1d = (undefined1)((uint)param_5 >> 0x18);
  if ((*(uint *)(param_1 + 0x9c) & 0xa0000) == 0 && param_6 == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  (**(code **)(*(int *)(param_1 + 0x30) + 0x44))
            (param_1,param_3 * *(int *)(param_1 + 0x50) + *(int *)(*(int *)(param_1 + 0x30) + 0x58)
                     + ((uint)(param_4 << 2) >> *(sbyte *)(param_1 + 0x84)),0,
             param_4 << 2 & *(ushort *)(param_1 + 0x5c) - 1,&local_20,4,uVar1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d02d8 @ 0x300D02D8  (примерный размер ~320 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300cf8cc, FUN_300d0238
 * Константы: 0xFFFFFFFF, 0x300D02D8, 0x0FFFFFFF
 * ---------------------------------------------------------------- */
int FUN_300d02d8(int *param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_30 [3];
  
  iVar4 = *param_1;
  iVar2 = *(int *)(iVar4 + 0x30);
  uVar1 = 0xfffffff;
  if (*(byte *)(iVar2 + 0x54) == param_2) {
    if (param_4 == 0) {
      local_30[2] = (int)*(ushort *)(iVar4 + 0x5e);
      local_30[0] = (param_3 - 2) * local_30[2] + *(int *)(iVar4 + 0x78);
      local_30[1] = 0;
      (**(code **)(iVar4 + 0xc0))(iVar4,0x47,local_30);
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  iVar3 = param_2 * *(int *)(iVar4 + 0x50) + *(int *)(iVar2 + 0x58) +
          (param_3 >> (*(byte *)(iVar4 + 0x84) - 2 & 0xff));
  if ((*(int *)(param_1[1] + 0x10) != iVar3) && (uVar1 != 0xffffffff)) {
    FUN_300cf8cc(param_1);
    *(int *)(param_1[1] + 0x10) = iVar3;
  }
  iVar3 = FUN_300d0238(iVar4,param_1 + 0xe,param_2,param_3,param_4 & uVar1,0);
  if (((iVar3 == 0) && (*(byte *)(iVar2 + 0x54) == param_2)) && (param_4 == 0)) {
    local_30[2] = (int)*(ushort *)(iVar4 + 0x5e);
    local_30[0] = (param_3 - 2) * local_30[2] + *(int *)(iVar4 + 0x78);
    local_30[1] = 0;
    (**(code **)(iVar4 + 0xc0))(iVar4,0x47,local_30);
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_300d0418 @ 0x300D0418  (примерный размер ~372 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300d063c, FUN_300d0b9c
 * Константы: 0xFFFFFFFF, 0x300D0418
 * ---------------------------------------------------------------- */
undefined4 FUN_300d0418(int *param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint local_28;
  
  iVar3 = *param_1;
  uVar4 = param_1[0xd];
  iVar6 = param_1[1];
  iVar5 = *(int *)(iVar3 + 0x30);
  uVar8 = uVar4;
  if ((uVar4 < 2) || (*(uint *)(iVar5 + 0x5c) <= uVar4)) {
    if ((uVar4 == 0) && (param_1[0xc] == 0)) {
      uVar8 = *(uint *)(iVar6 + 0xc);
      param_1[7] = (uVar8 - 2) * (uint)*(ushort *)(iVar3 + 0x5e) + *(int *)(iVar3 + 0x78);
    }
    if (*(uint *)(iVar5 + 0x6c) < uVar8) {
      uVar8 = (**(code **)(iVar5 + 0x34))(param_1,*(undefined1 *)(iVar5 + 0x54));
    }
    if ((uVar8 < 2) || (*(uint *)(iVar5 + 0x5c) <= uVar8)) {
      param_1[0xd] = uVar8;
      return 0xffffffff;
    }
  }
  uVar2 = param_1[8];
  if ((uVar8 < uVar2) && (*(uint *)(iVar6 + 0xc) <= uVar8)) {
    uVar4 = uVar8 + param_2;
    uVar7 = uVar4;
    if (uVar2 <= uVar4) {
      uVar4 = *(uint *)(iVar5 + 0x70);
      uVar7 = uVar2;
    }
  }
  else {
    local_28 = *(uint *)(iVar5 + 0x5c);
    uVar7 = uVar8;
    if (uVar8 + param_2 <= local_28) {
      local_28 = uVar8 + param_2;
    }
    do {
      if (local_28 <= uVar7) break;
      uVar4 = (**(code **)(iVar5 + 0x34))(param_1,*(undefined1 *)(iVar5 + 0x54),uVar7);
      uVar7 = uVar7 + 1;
    } while (uVar4 == uVar7);
    if (param_1[0xf] == 1) {
      return 0xffffffff;
    }
  }
  param_1[0xd] = uVar4;
  param_1[0xc] = uVar7 - 1;
  uVar1 = *(ushort *)(iVar3 + 0x5e);
  iVar3 = (uVar8 - 2) * (uint)uVar1 + *(int *)(iVar3 + 0x78);
  param_1[7] = iVar3;
  param_1[6] = iVar3;
  param_1[9] = (uint)uVar1 * (uVar7 - uVar8);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300d058c @ 0x300D058C  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300d063c, FUN_300d0f68
 * Константы: 0xFFFFFFFF, 0x300D058C
 * ---------------------------------------------------------------- */
undefined4 FUN_300d058c(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*param_1 + 0x30);
  if (param_2 < (param_2 + param_3) - 1) {
    param_3 = param_2 + param_3;
    do {
      iVar1 = (**(code **)(iVar3 + 0x38))(param_1,*(undefined1 *)(iVar3 + 0x54),param_2,param_2 + 1)
      ;
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      param_2 = param_2 + 1;
      *(int *)(iVar3 + 0x60) = *(int *)(iVar3 + 0x60) + -1;
    } while (param_2 < param_3 - 1U);
  }
  iVar1 = (**(code **)(iVar3 + 0x38))
                    (param_1,*(undefined1 *)(iVar3 + 0x54),param_2,*(undefined4 *)(iVar3 + 0x70));
  if (iVar1 == 0) {
    uVar2 = 0;
    *(int *)(iVar3 + 0x60) = *(int *)(iVar3 + 0x60) + -1;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300d063c @ 0x300D063C  (примерный размер ~732 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_300d0418, FUN_300d058c, errnoSet, logMsg, semGive, semTake
 * Константы: 0x80000001, 0xFFFFFFFF, 0x300D063C, 0x80000000
 * Данные: DAT_300d16cc, DAT_300d16d0, DAT_300d16d4, DAT_300d16d8
 * ---------------------------------------------------------------- */
undefined4 FUN_300d063c(int *param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint local_34;
  int local_30;
  uint local_4;
  
  iVar10 = param_1[1];
  iVar11 = *param_1;
  iVar8 = *(int *)(iVar11 + 0x30);
  iVar2 = FUN_300d0418(param_1,*(undefined4 *)(iVar8 + 0x74));
  if (iVar2 == 0) {
    return 0;
  }
  if ((param_1[0xf] != 1) && ((param_2 & 0x80000000) != 0)) {
    uVar9 = param_1[0xc];
    local_4 = param_2;
    if (*(uint *)(iVar8 + 0x78) == 0) {
      local_4 = 0x80000001;
    }
    if (local_4 == 0x80000001) {
      iVar2 = 1;
    }
    else {
      iVar2 = *(int *)(iVar8 + 0x74);
    }
    uVar5 = uVar9;
    if (((((uint)param_1[0xd] <= *(uint *)(iVar8 + 0x6c)) && (uVar5 = 0, param_1[0xd] == 0)) &&
        (uVar9 == 0)) && (uVar5 = *(uint *)(iVar8 + 0x78), local_4 == 0x80000001)) {
      uVar5 = *(uint *)(iVar8 + 0x7c);
    }
    if (uVar5 == 0) {
      errnoSet(DAT_300d16cc);
      return 0xffffffff;
    }
    uVar4 = 0;
    local_34 = *(int *)(iVar8 + 0x5c) - 1;
    iVar6 = 0;
    semTake(*(undefined4 *)(iVar8 + 0x84),0xffffffff);
    local_30 = 2;
    uVar7 = uVar5;
    do {
      for (; uVar7 <= local_34; uVar7 = uVar7 + 1) {
        iVar3 = (**(code **)(iVar8 + 0x34))(param_1,*(undefined1 *)(iVar8 + 0x54),uVar7);
        if ((iVar3 == 1) && (param_1[0xf] == 1)) goto LAB_300d08fc;
        if (*(int *)(iVar8 + 100) == iVar3) {
          if (iVar6 == 0) {
            uVar4 = uVar7;
          }
          iVar6 = iVar6 + 1;
          if (iVar6 == iVar2) goto LAB_300d0828;
        }
        else {
          iVar6 = 0;
        }
      }
      local_34 = uVar5 - 1;
      uVar7 = 2;
      iVar6 = 0;
      local_30 = local_30 + -1;
    } while (local_30 != 0);
    if (uVar4 == 0) {
      errnoSet(DAT_300d16d0);
      if (0 < *DAT_300d16d4) {
        logMsg(DAT_300d16d8,1,2,3,4,5,6);
      }
    }
    else {
      *(undefined4 *)(iVar8 + 0x78) = 0;
      iVar2 = 1;
LAB_300d0828:
      iVar6 = FUN_300d058c(param_1,uVar4,iVar2);
      if (iVar6 == 0) {
        semGive(*(undefined4 *)(iVar8 + 0x84));
        if (uVar5 == uVar9) {
          iVar10 = (**(code **)(iVar8 + 0x38))(param_1,*(undefined1 *)(iVar8 + 0x54),uVar9,uVar4);
          if (iVar10 != 0) {
            return 0xffffffff;
          }
          if (param_1[8] != uVar4) goto LAB_300d08bc;
        }
        else {
          if (local_4 == 0x80000001) {
            *(uint *)(iVar8 + 0x7c) = uVar4 + 1;
          }
          else if (*(int *)(iVar8 + 0x78) != 0) {
            *(uint *)(iVar8 + 0x78) = uVar4 + iVar2;
          }
          *(uint *)(iVar10 + 0xc) = uVar4;
        }
        param_1[8] = uVar4 + iVar2;
LAB_300d08bc:
        param_1[0xd] = *(int *)(iVar8 + 0x70);
        param_1[0xc] = (uVar4 + iVar2) - 1;
        uVar1 = *(ushort *)(iVar11 + 0x5e);
        iVar8 = (uVar4 - 2) * (uint)uVar1 + *(int *)(iVar11 + 0x78);
        param_1[6] = iVar8;
        param_1[7] = iVar8;
        param_1[9] = (uint)uVar1 * iVar2;
        return 0;
      }
    }
LAB_300d08fc:
    semGive(*(undefined4 *)(iVar8 + 0x84));
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300d0918 @ 0x300D0918  (примерный размер ~644 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: __udiv32, __urem32, errnoSet
 * Константы: 0xFFFFFFFF, 0x300D0918
 * Данные: DAT_300d1788
 * ---------------------------------------------------------------- */
undefined4 FUN_300d0918(int *param_1,uint param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  iVar7 = *param_1;
  iVar6 = param_1[1];
  iVar8 = *(int *)(iVar7 + 0x30);
  if (param_2 == 0xffffffff) {
    uVar5 = *(uint *)(iVar6 + 0xc);
    param_1[8] = 0;
    if (uVar5 < 2) {
      errnoSet(DAT_300d1788);
      return 0xffffffff;
    }
    iVar2 = (*(int *)(iVar6 + 0xc) + -2) * (uint)*(ushort *)(iVar7 + 0x5e) + *(int *)(iVar7 + 0x78);
  }
  else {
    if (param_2 < *(uint *)(iVar7 + 0x78)) {
      errnoSet(DAT_300d1788);
      return 0xffffffff;
    }
    iVar2 = __udiv32(param_2 - *(uint *)(iVar7 + 0x78),*(undefined2 *)(iVar7 + 0x5e));
    uVar5 = iVar2 + 2;
    iVar2 = -1;
  }
  param_1[7] = iVar2;
  if (*(uint *)(iVar8 + 0x5c) <= uVar5) {
    errnoSet(DAT_300d1788);
    return 0xffffffff;
  }
  if (param_3 == 0) {
    bVar9 = param_2 == 0xffffffff;
    if (!bVar9) {
      iVar2 = __urem32(param_2 - *(int *)(iVar7 + 0x78),*(undefined2 *)(iVar7 + 0x5e));
      bVar9 = iVar2 == 0;
    }
    uVar3 = uVar5;
    if (bVar9) goto LAB_300d0a8c;
  }
  else if (param_3 != 1) {
    errnoSet(DAT_300d1788);
    return 0xffffffff;
  }
  uVar3 = (**(code **)(iVar8 + 0x34))(param_1,*(undefined1 *)(iVar8 + 0x54),uVar5);
  if (*(uint *)(iVar8 + 0x6c) < uVar3) {
    return 0;
  }
  if ((uVar3 < 2) || (*(uint *)(iVar8 + 0x5c) <= uVar3)) {
    return 0xffffffff;
  }
  iVar2 = (**(code **)(iVar8 + 0x38))
                    (param_1,*(undefined1 *)(iVar8 + 0x54),uVar5,*(undefined4 *)(iVar8 + 0x70));
  if (iVar2 != 0) {
    return 0xffffffff;
  }
LAB_300d0a8c:
  if ((uVar3 < (uint)param_1[8]) && (*(uint *)(iVar6 + 0xc) <= uVar3)) {
    param_1[8] = uVar3;
  }
  if (*(int *)(iVar8 + 0x78) == 0) {
    *(uint *)(iVar8 + 0x78) = uVar3;
  }
  if (uVar3 < *(uint *)(iVar8 + 0x7c)) {
    *(uint *)(iVar8 + 0x7c) = uVar3;
  }
  while ((1 < uVar3 && (uVar3 < *(uint *)(iVar8 + 0x5c)))) {
    uVar4 = (**(code **)(iVar8 + 0x34))(param_1,*(undefined1 *)(iVar8 + 0x54),uVar3);
    iVar6 = (**(code **)(iVar8 + 0x38))
                      (param_1,*(undefined1 *)(iVar8 + 0x54),uVar3,*(undefined4 *)(iVar8 + 100));
    if (iVar6 != 0) {
      return 0xffffffff;
    }
    *(int *)(iVar8 + 0x60) = *(int *)(iVar8 + 0x60) + 1;
    uVar3 = uVar4;
  }
  if (*(uint *)(iVar8 + 0x6c) < uVar3) {
    if (param_2 == 0xffffffff) {
      param_1[0xd] = 0;
      param_1[0xc] = 0;
      param_1[0xe] = 0;
      param_1[6] = 0;
      param_1[9] = 0;
    }
    else {
      param_1[0xd] = *(int *)(iVar8 + 0x70);
      uVar1 = *(ushort *)(iVar7 + 0x5e);
      iVar6 = __urem32(param_2 - *(int *)(iVar7 + 0x78),(uint)uVar1);
      param_1[9] = (uint)uVar1 - iVar6;
      param_1[0xc] = uVar5;
    }
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300d0b9c @ 0x300D0B9C  (примерный размер ~432 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300d0418, __udiv32
 * Константы: 0xFFFFFFFF, 0x300D0B9C
 * ---------------------------------------------------------------- */
undefined4 FUN_300d0b9c(int *param_1,uint param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar4 = *param_1;
  iVar6 = *(int *)(iVar4 + 0x30);
  if (param_2 == 0xffffffff) {
    param_1[0xd] = 0;
    param_1[0xc] = 0;
    param_1[0xe] = 0;
    param_1[6] = 0;
    param_1[9] = 0;
    uVar9 = *(uint *)(param_1[1] + 0xc);
    if (uVar9 == 0) {
      return 0;
    }
    if (uVar9 < 2) {
      return 0xffffffff;
    }
  }
  else {
    if (param_2 < *(uint *)(iVar4 + 0x78)) {
      return 0xffffffff;
    }
    uVar1 = *(ushort *)(iVar4 + 0x5e);
    iVar5 = param_2 - *(uint *)(iVar4 + 0x78);
    iVar2 = __udiv32(iVar5,(uint)uVar1);
    uVar9 = iVar2 + 2;
    param_3 = param_3 + (iVar5 - iVar2 * (uint)uVar1);
  }
  if (*(uint *)(iVar6 + 0x5c) <= uVar9) {
    return 0xffffffff;
  }
  uVar1 = *(ushort *)(iVar4 + 0x5e);
  uVar3 = __udiv32(param_3,(uint)uVar1);
  uVar8 = param_1[8];
  param_3 = param_3 - uVar3 * uVar1;
  uVar7 = uVar9;
  if ((uVar9 < uVar8) && (*(uint *)(param_1[1] + 0xc) <= uVar9)) {
    uVar7 = uVar3;
    if ((uVar8 - uVar9) - 1 <= uVar3) {
      uVar7 = (uVar8 - uVar9) - 1;
    }
    uVar9 = uVar9 + uVar7;
    uVar3 = uVar3 - uVar7;
    uVar7 = uVar9;
  }
  while( true ) {
    if (uVar3 == 0) {
      param_1[0xd] = uVar9;
      iVar6 = FUN_300d0418(param_1,*(undefined4 *)(iVar6 + 0x74));
      if (iVar6 == 0) {
        param_1[7] = (uVar7 - 2) * (uint)*(ushort *)(iVar4 + 0x5e) + *(int *)(iVar4 + 0x78);
        param_1[6] = param_3 + param_1[6];
        param_1[9] = param_1[9] - param_3;
        return 0;
      }
      return 0xffffffff;
    }
    uVar8 = (**(code **)(iVar6 + 0x34))(param_1,*(undefined1 *)(iVar6 + 0x54),uVar9);
    if ((uVar8 < 2) || (*(uint *)(iVar6 + 0x5c) <= uVar8)) break;
    if (uVar8 != uVar9 + 1) {
      uVar7 = uVar8;
    }
    uVar3 = uVar3 - 1;
    uVar9 = uVar8;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300d0d4c @ 0x300D0D4C  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: __lsl64, __mul64
 * Вызывают: fat16VolMount
 * Константы: 0x300D0D4C
 * ---------------------------------------------------------------- */
void FUN_300d0d4c(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  
  iVar2 = *param_1;
  iVar5 = *(int *)(iVar2 + 0x30);
  iVar3 = *(int *)(iVar5 + 0x60);
  if (iVar3 == -1) {
    iVar3 = 0;
    uVar4 = 2;
    if (2 < *(uint *)(iVar5 + 0x5c)) {
      do {
        iVar1 = (**(code **)(iVar5 + 0x34))(param_1,*(undefined1 *)(iVar5 + 0x54),uVar4);
        if ((iVar1 == 1) && (param_1[0xf] == 1)) {
          return;
        }
        if (*(int *)(iVar5 + 100) == iVar1) {
          iVar3 = iVar3 + 1;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(iVar5 + 0x5c));
    }
    *(int *)(iVar5 + 0x60) = iVar3;
  }
  uVar6 = __mul64(iVar3,0,*(undefined2 *)(iVar2 + 0x5e),0);
  __lsl64((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),*(undefined1 *)(iVar2 + 0x84));
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d0df8 @ 0x300D0DF8  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoSet
 * Константы: 0xFFFFFFFF, 0x300D0DF8
 * Данные: DAT_300d16cc
 * ---------------------------------------------------------------- */
undefined4 FUN_300d0df8(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1[1] + 0xc);
  iVar2 = *(int *)(*param_1 + 0x30);
  if (uVar3 == 0) {
    return 0;
  }
  if ((1 < uVar3) && (uVar3 < *(uint *)(iVar2 + 0x5c))) {
    do {
      uVar1 = (**(code **)(iVar2 + 0x34))(param_1,*(undefined1 *)(iVar2 + 0x54),uVar3);
      uVar3 = uVar3 + 1;
    } while (uVar3 == uVar1);
    if (param_1[0xf] == 1) {
      return 0xffffffff;
    }
    param_1[8] = uVar3;
    if (*(uint *)(iVar2 + 0x6c) < uVar1) {
      return 0;
    }
    if ((1 < uVar1) && (uVar1 < *(uint *)(iVar2 + 0x5c))) {
      return 0xffffffff;
    }
  }
  errnoSet(DAT_300d16cc);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300d0ea8 @ 0x300D0EA8  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300d0f68, FUN_300d10b4
 * Константы: 0x300D0EA8
 * ---------------------------------------------------------------- */
uint FUN_300d0ea8(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = 2;
  uVar7 = 0;
  iVar5 = *(int *)(*param_1 + 0x30);
  iVar2 = 0;
  uVar4 = 0;
  uVar6 = 2;
  if (2 < *(uint *)(iVar5 + 0x5c)) {
    do {
      iVar1 = (**(code **)(iVar5 + 0x34))(param_1,*(undefined1 *)(iVar5 + 0x54),uVar6);
      if ((iVar1 == 1) && (param_1[0xf] == 1)) {
        return 0;
      }
      if (*(int *)(iVar5 + 100) == iVar1) {
        uVar7 = uVar7 + 1;
      }
      else {
        if (uVar4 < uVar7) {
          uVar4 = uVar7;
          iVar2 = iVar3;
        }
        iVar3 = uVar6 + 1;
        uVar7 = 0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(iVar5 + 0x5c));
  }
  if (uVar4 < uVar7) {
    uVar4 = uVar7;
    iVar2 = iVar3;
  }
  *param_2 = iVar2;
  return uVar4;
}

/* ----------------------------------------------------------------
 * FUN_300d0f68 @ 0x300D0F68  (примерный размер ~332 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_300d058c, FUN_300d0ea8, __udiv32, errnoSet, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300D0F68
 * Данные: DAT_300d16d0, DAT_300d178c
 * ---------------------------------------------------------------- */
undefined4 FUN_300d0f68(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int local_24;
  
  iVar3 = param_1[1];
  iVar7 = *(int *)(*param_1 + 0x30);
  if (param_2 == -1) {
    semTake(*(undefined4 *)(iVar7 + 0x84),0xffffffff);
    uVar1 = FUN_300d0ea8(param_1,&local_24);
    iVar4 = local_24;
    if (uVar1 == 0) {
      errnoSet(DAT_300d16d0);
      goto LAB_300d10a0;
    }
  }
  else {
    uVar1 = __udiv32(param_2 + (uint)*(ushort *)(*param_1 + 0x5e) + -1);
    iVar4 = 2;
    uVar6 = 0;
    semTake(*(undefined4 *)(iVar7 + 0x84),0xffffffff);
    uVar5 = 2;
    if (2 < *(uint *)(iVar7 + 0x5c)) {
      do {
        iVar2 = (**(code **)(iVar7 + 0x34))(param_1,*(undefined1 *)(iVar7 + 0x54),uVar5);
        if ((iVar2 == 1) && (param_1[0xf] == 1)) goto LAB_300d10a0;
        if (*(int *)(iVar7 + 100) == iVar2) {
          uVar6 = uVar6 + 1;
          if (uVar6 == uVar1) goto LAB_300d106c;
        }
        else {
          iVar4 = uVar5 + 1;
          uVar6 = 0;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(iVar7 + 0x5c));
    }
    if (uVar6 < uVar1) {
      errnoSet(DAT_300d178c);
      goto LAB_300d10a0;
    }
  }
LAB_300d106c:
  iVar2 = FUN_300d058c(param_1,iVar4,uVar1);
  if (iVar2 == 0) {
    semGive(*(undefined4 *)(iVar7 + 0x84));
    *(int *)(iVar3 + 0xc) = iVar4;
    param_1[8] = iVar4 + uVar1;
    return 0;
  }
LAB_300d10a0:
  semGive(*(undefined4 *)(iVar7 + 0x84));
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300d10b4 @ 0x300D10B4  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300d0ea8
 * Константы: 0x300D10B4
 * ---------------------------------------------------------------- */
int FUN_300d10b4(int *param_1)

{
  int iVar1;
  undefined1 auStack_c [4];
  
  iVar1 = FUN_300d0ea8(param_1,auStack_c);
  return (uint)*(ushort *)(*param_1 + 0x5e) * iVar1;
}

/* ----------------------------------------------------------------
 * fat16ClustValueSet @ 0x300D10DC  (примерный размер ~460 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: bfill
 * Константы: 0xFFFFFFFF, 0x300D10DC
 * ---------------------------------------------------------------- */
undefined4 fat16ClustValueSet(int *param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_6c [64];
  
  iVar3 = *param_1;
  uVar8 = *(uint *)(iVar3 + 0x9c);
  iVar5 = *(int *)(iVar3 + 0x30);
  iVar1 = param_4;
  if (param_4 != 0x10) {
    iVar1 = param_5;
    if (param_4 < 0x11) {
      if (param_4 == 1) {
        iVar1 = *(int *)(iVar5 + 100);
      }
      else if (param_4 == 2) {
        iVar1 = *(int *)(iVar5 + 0x70);
      }
      else if (param_4 == 4) {
        iVar1 = *(int *)(iVar5 + 0x6c);
      }
      else if (param_4 != 8) {
        iVar1 = param_4;
      }
    }
    else if (param_4 == 0x20) {
      iVar1 = *(int *)(iVar5 + 0x68);
    }
    else if ((param_4 != 0x40) && (iVar1 = param_4, param_4 == 0x80)) {
      uVar6 = param_2 * *(int *)(iVar3 + 0x50) + *(int *)(iVar5 + 0x58);
      bfill(auStack_6c,0x40,param_5);
      uVar4 = 0;
      uVar7 = uVar6;
      if (*(short *)(*param_1 + 0x5c) != 0) {
        do {
          iVar1 = (**(code **)(iVar5 + 0x44))
                            (iVar3,uVar6,0,uVar4,auStack_6c,0x40,((uVar8 & 0xa0000) != 0) + '\x01');
          if (iVar1 != 0) {
            return 0xffffffff;
          }
          uVar4 = uVar4 + 0x40;
        } while (uVar4 < *(ushort *)(*param_1 + 0x5c));
      }
      do {
        uVar7 = uVar7 + 1;
        if (uVar6 + *(int *)(iVar3 + 0x50) <= uVar7) {
          return 0;
        }
        iVar1 = (**(code **)(iVar5 + 0x48))(iVar3,uVar6,0,uVar7,0,1,0);
      } while (iVar1 == 0);
      return 0xffffffff;
    }
  }
  uVar2 = (**(code **)(iVar5 + 0x38))(param_1,param_2,param_3,iVar1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * fat16ClustValueGet @ 0x300D12A8  (примерный размер ~336 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300D12A8, 0x0FFFFFFF
 * Данные: DAT_300d1790
 * ---------------------------------------------------------------- */
undefined4 fat16ClustValueGet(int *param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*param_1 + 0x30);
  param_3 = param_3 & 0xfffffff;
  if (param_3 == 0) {
    uVar1 = 1;
  }
  else if (*(uint *)(iVar2 + 0x6c) < param_3) {
    uVar1 = 2;
  }
  else if (*(uint *)(iVar2 + 0x6c) == param_3) {
    uVar1 = 4;
  }
  else if (param_3 < *(uint *)(iVar2 + 0x68)) {
    if ((param_3 < 2) || (*(uint *)(*param_1 + 100) <= param_3)) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = (**(code **)(iVar2 + 0x34))(param_1);
      *param_4 = uVar1;
      uVar1 = DAT_300d1790;
      if (param_1[0xf] != 1) {
        uVar1 = 8;
      }
    }
  }
  else {
    uVar1 = 0x20;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300d13f8 @ 0x300D13F8  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: fat16VolMount
 * Константы: 0x300D13F8, 0x300D13B0
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300d13b0) */
/* WARNING: Type propagation algorithm not settling */

void FUN_300d13f8(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint local_1c [2];
  
  *(undefined4 *)(param_1 + 0xb0) = 0;
  iVar3 = *(int *)(param_1 + 0x30);
  local_1c[1] = 0;
  if (((*(int *)(iVar3 + 0x50) != 0) &&
      (iVar1 = (**(code **)(iVar3 + 0x3c))(param_1,local_1c + 1,0,1,local_1c), iVar1 != -1)) &&
     (uVar2 = local_1c[0] | *(uint *)(iVar3 + 0x50), uVar2 != local_1c[0])) {
    (**(code **)(iVar3 + 0x40))(param_1,local_1c + 1,0,1,uVar2,1);
  }
  return;
}

/* ----------------------------------------------------------------
 * fat16VolMount @ 0x300D1408  (примерный размер ~844 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_300d0d4c, FUN_300d13f8, __udiv32, bzero, dosFsXbdBytesRW, dosfsDiskToHost32, memPartRealloc, semMCreate
 * Константы: 0xFFFFFFFF, 0x300D1408, 0x08000000, 0x0FFFFFF0, 0x0FFFFFF7, 0x0FFFFFFF
 * Данные: DAT_300d1794, DAT_300d1798, DAT_300d179c, DAT_300d17a0, DAT_300d17a4, DAT_300d17a8, DAT_300d17ac, DAT_300d17b0
 * ---------------------------------------------------------------- */
undefined4 fat16VolMount(int param_1)

{
  undefined4 *__s;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  code *pcVar8;
  undefined1 auStack_70 [4];
  undefined1 auStack_6c [8];
  int local_64 [18];
  
  iVar4 = 0x12;
  piVar6 = local_64;
  piVar7 = DAT_300d1794;
  do {
    iVar4 = iVar4 + -1;
    *piVar6 = *piVar7;
    piVar6 = piVar6 + 1;
    piVar7 = piVar7 + 1;
  } while (iVar4 != 0);
  if (((*(int *)(param_1 + 0x30) != 0) &&
      (pcVar8 = *(code **)(*(int *)(param_1 + 0x30) + 0x1c), DAT_300d1798 != pcVar8)) &&
     (pcVar8 != (code *)0x0)) {
    (*pcVar8)(param_1);
  }
  iVar5 = *(int *)(param_1 + 0x30);
  __s = (undefined4 *)memPartRealloc(*DAT_300d179c,iVar5,0x88);
  *(undefined4 **)(param_1 + 0x30) = __s;
  iVar4 = 0;
  if (__s == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  if (iVar5 != 0) {
    iVar4 = __s[0x21];
  }
  bzero(__s,0x88);
  local_64[0] = param_1;
  iVar1 = __udiv32(*(int *)(param_1 + 0x58) - *(int *)(param_1 + 0x78),
                   *(undefined2 *)(param_1 + 0x5e));
  __s[0x17] = iVar1 + 2;
  *(int *)(param_1 + 100) = iVar1 + 2;
  iVar1 = *(int *)(param_1 + 0x74);
  if (iVar1 == 2) {
    iVar1 = dosFsXbdBytesRW(param_1,1,0,0x1e8,auStack_70,8,0);
    if (iVar1 != 0) goto LAB_300d1740;
    uVar2 = dosfsDiskToHost32(auStack_70);
    __s[0x18] = uVar2;
    uVar3 = dosfsDiskToHost32(auStack_6c);
    __s[0x1e] = uVar3;
    if ((uVar3 < 2) || ((uint)__s[0x17] <= uVar3)) {
      __s[0x1e] = 2;
    }
    __s[0xf] = DAT_300d17a0;
    __s[0x10] = DAT_300d17a4;
    __s[0xd] = DAT_300d17a8;
    __s[0xe] = DAT_300d17ac;
    __s[0x14] = 0x8000000;
    __s[0x1a] = 0xffffff0;
    __s[0x1b] = 0xffffff7;
    uVar2 = 0xfffffff;
  }
  else {
    __s[0x18] = 0xffffffff;
    __s[0x1e] = 2;
    if (iVar1 == 1) {
      __s[0xf] = DAT_300d17b0;
      __s[0x10] = DAT_300d17b4;
      __s[0xd] = DAT_300d17b8;
      __s[0xe] = DAT_300d17bc;
      __s[0x14] = 0x8000;
      __s[0x1a] = DAT_300d17c0;
      __s[0x1b] = DAT_300d17c4;
      uVar2 = DAT_300d17c8;
    }
    else {
      if (iVar1 != 0) goto LAB_300d1740;
      __s[0xf] = DAT_300d17cc;
      __s[0x10] = DAT_300d17d0;
      __s[0xd] = DAT_300d17d4;
      __s[0xe] = DAT_300d17d8;
      __s[0x14] = 0;
      __s[0x1a] = 0xff0;
      __s[0x1b] = DAT_300d17dc;
      uVar2 = DAT_300d17e0;
    }
  }
  __s[0x1c] = uVar2;
  __s[7] = DAT_300d1798;
  *__s = DAT_300d17e4;
  __s[1] = DAT_300d17e8;
  __s[8] = *DAT_300d17ec;
  __s[2] = DAT_300d17f0;
  __s[3] = DAT_300d17f4;
  __s[5] = DAT_300d17f8;
  __s[6] = DAT_300d17fc;
  __s[4] = DAT_300d1800;
  __s[9] = DAT_300d1804;
  __s[10] = DAT_300d1808;
  __s[0xb] = DAT_300d180c;
  __s[0xc] = DAT_300d1810;
  __s[0x11] = DAT_300d1814;
  __s[0x12] = DAT_300d1818;
  __s[0x13] = DAT_300d181c;
  __s[0x16] = (uint)*(ushort *)(param_1 + 0x60);
  *(undefined1 *)(__s + 0x15) = 0;
  iVar1 = __udiv32(__s[0x17],*DAT_300d1820);
  __s[0x1d] = iVar1 + 1;
  __s[0x19] = 0;
  __s[0x20] = (uint)(*(int *)(param_1 + 0xac) == 0);
  if (iVar5 == 0) {
    iVar4 = semMCreate(0xd);
  }
  __s[0x21] = iVar4;
  if (iVar4 != 0) {
    __s[0x1f] = 2;
    FUN_300d0d4c(local_64);
    *(undefined4 *)(param_1 + 0xb0) = DAT_300d1824;
    return 0;
  }
LAB_300d1740:
  FUN_300d13f8(param_1);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * dosFsFatInit @ 0x300D1754  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: dosFsHdlrInstall
 * Вызывают: FUN_3003fb10
 * Константы: 0x300D1754
 * Данные: DAT_300d1828, DAT_300d182c
 * ---------------------------------------------------------------- */
void dosFsFatInit(void)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 0xff;
  local_c = DAT_300d1828;
  local_8 = 0;
  dosFsHdlrInstall(DAT_300d182c,&local_10);
  return;
}

/* ----------------------------------------------------------------
 * dosfsHostToDisk32 @ 0x300D1830  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300cf8cc, FUN_300da18c
 * Константы: 0x300D1830
 * ---------------------------------------------------------------- */
void dosfsHostToDisk32(undefined4 param_1,undefined1 *param_2)

{
  *param_2 = (char)param_1;
  param_2[1] = (char)((uint)param_1 >> 8);
  param_2[2] = (char)((uint)param_1 >> 0x10);
  param_2[3] = (char)((uint)param_1 >> 0x18);
  return;
}

/* ----------------------------------------------------------------
 * dosfsHostToDisk16 @ 0x300D1850  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300d8710, FUN_300da18c, FUN_300da31c
 * Константы: 0x300D1850
 * ---------------------------------------------------------------- */
void dosfsHostToDisk16(undefined4 param_1,undefined1 *param_2)

{
  *param_2 = (char)param_1;
  param_2[1] = (char)((uint)param_1 >> 8);
  return;
}

/* ----------------------------------------------------------------
 * dosfsDiskToHost32 @ 0x300D1860  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 0
 * Вызывают: FUN_300d266c, FUN_300d83bc, FUN_300db20c, dosFsVolIsFat12, dosVDirReaddirPlus, fat16VolMount
 * Константы: 0x300D1860, 0x01000000
 * ---------------------------------------------------------------- */
int dosfsDiskToHost32(byte *param_1)

{
  return (uint)param_1[3] * 0x1000000 + (uint)param_1[2] * 0x10000 + (uint)param_1[1] * 0x100 +
         (uint)*param_1;
}

/* ----------------------------------------------------------------
 * dosfsDiskToHost16 @ 0x300D1884  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_300d266c, FUN_300d83bc, FUN_300d8610, FUN_300db20c, dosFsVolIsFat12
 * Константы: 0x300D1884
 * ---------------------------------------------------------------- */
short dosfsDiskToHost16(byte *param_1)

{
  return (ushort)*param_1 + (ushort)param_1[1] * 0x100;
}

/* ----------------------------------------------------------------
 * dosFsVolDescGet @ 0x300D189C  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 11 | Вызывает: 2
 * Вызывает: errnoSet, iosDevFind
 * Вызывают: dosFsCacheCreate, dosFsCacheDelete, dosFsCacheInfo, dosFsCacheShow, dosFsCacheTune, dosFsMonitorDevCreate, dosFsShow, dosFsTCacheShow, dosFsVolUnmount, dosFsVolumeOptionsGet
 *           ...
 * Константы: 0x300D189C
 * Данные: DAT_300d2880, DAT_300d2884
 * ---------------------------------------------------------------- */
uint dosFsVolDescGet(uint param_1,uint *param_2)

{
  uint uVar1;
  uint in_r12;
  uint uVar2;
  bool bVar3;
  uint uStack_10;
  
  if (param_2 == (uint *)0x0) {
    param_2 = &uStack_10;
  }
  *param_2 = 0;
  if (param_1 != 0) {
    uVar1 = iosDevFind(param_1,param_2);
    if ((uVar1 != 0) && (uVar2 = *param_2, uVar2 != param_1)) {
      bVar3 = (uVar1 & 3) == 0;
      if (bVar3) {
        uVar2 = *(uint *)(uVar1 + 0x20);
        in_r12 = DAT_300d2880;
      }
      if (bVar3 && uVar2 == in_r12) {
        return uVar1;
      }
    }
    if (((param_1 & 3) == 0) && (*(uint *)(param_1 + 0x20) == DAT_300d2880)) {
      return param_1;
    }
  }
  errnoSet(DAT_300d2884);
  return 0;
}

/* ----------------------------------------------------------------
 * dosFsVolumeOptionsSet @ 0x300D1928  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: dosFsVolDescGet, errnoSet, printf, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300D1928, 0xFFFFFFFE
 * Данные: DAT_300d2888, DAT_300d288c
 * ---------------------------------------------------------------- */
uint dosFsVolumeOptionsSet(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = dosFsVolDescGet(param_1,0);
  if (iVar1 == 0) {
    if ((*DAT_300d2888 != 0) && (*DAT_300d2888 < 2)) {
      printf(DAT_300d288c,param_1);
    }
    return 0xffffffff;
  }
  if ((param_2 & 0xfffffffe) != 0) {
    errnoSet(0x16);
    return 0xffffffff;
  }
  iVar2 = semTake(*(undefined4 *)(iVar1 + 0x34),0xffffffff);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  *(uint *)(iVar1 + 0x1cc) = param_2;
  semGive(*(undefined4 *)(iVar1 + 0x34));
  return param_2;
}

/* ----------------------------------------------------------------
 * dosFsVolumeOptionsGet @ 0x300D19C4  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: dosFsVolDescGet, printf
 * Константы: 0x300D19C4, 0xFFFFFFFF
 * Данные: DAT_300d2888, DAT_300d288c
 * ---------------------------------------------------------------- */
undefined4 dosFsVolumeOptionsGet(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = dosFsVolDescGet(param_1,0);
  if (iVar1 == 0) {
    if ((*DAT_300d2888 != 0) && (*DAT_300d2888 < 2)) {
      printf(DAT_300d288c,param_1);
    }
    return 0xffffffff;
  }
  return *(undefined4 *)(iVar1 + 0x1cc);
}

/* ----------------------------------------------------------------
 * dosSetVolCaseSens @ 0x300D1A18  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoSet
 * Константы: 0x300D1A18
 * Данные: DAT_300d2880, DAT_300d2884
 * ---------------------------------------------------------------- */
undefined4 dosSetVolCaseSens(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (((param_1 & 3) == 0) && (*(int *)(param_1 + 0x20) == DAT_300d2880)) {
    *(undefined4 *)(param_1 + 0x98) = param_2;
    uVar1 = 1;
  }
  else {
    errnoSet(DAT_300d2884);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300d1a4c @ 0x300D1A4C  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 2
 * Вызывает: __div32, semTake
 * Вызывают: FUN_300d370c, FUN_300d3bd8, FUN_300d439c, FUN_300d5c80, FUN_300d5d2c, dosFsClose, dosFsIoctl, dosFsOpen
 * Константы: 0x300D1A4C
 * ---------------------------------------------------------------- */
void FUN_300d1a4c(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = __div32(param_1[1] - *(int *)(iVar2 + 0x40),0x44);
  semTake(*(undefined4 *)(*(int *)(iVar2 + 0x44) + iVar1 * 4),param_2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d1a80 @ 0x300D1A80  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 2
 * Вызывает: __div32, semGive
 * Вызывают: FUN_300d370c, FUN_300d3bd8, FUN_300d439c, FUN_300d5c80, FUN_300d5d2c, dosFsClose, dosFsIoctl, dosFsOpen
 * Константы: 0x300D1A80
 * ---------------------------------------------------------------- */
void FUN_300d1a80(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = __div32(param_1[1] - *(int *)(iVar2 + 0x40),0x44);
  semGive(*(undefined4 *)(*(int *)(iVar2 + 0x44) + iVar1 * 4));
  return;
}

/* ----------------------------------------------------------------
 * dosFsVolUnmount @ 0x300D1AAC  (примерный размер ~308 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: dosFsVolDescGet, semGive, semTake
 * Вызывают: FUN_300d2d68
 * Константы: 0xFFFFFFFF, 0x300D1AAC
 * Данные: DAT_300d2aec, DAT_300d2af0, DAT_300d2af4
 * ---------------------------------------------------------------- */
undefined4 dosFsVolUnmount(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = dosFsVolDescGet(param_1,0);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else if (*(int *)(iVar1 + 0x24) == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar3 = semTake(*(undefined4 *)(iVar1 + 0x34),0xffffffff);
    if (iVar3 == -1) {
      uVar2 = 0xffffffff;
    }
    else {
      iVar3 = 0;
      if (*(short *)(iVar1 + 0x7c) != 0) {
        iVar5 = 0;
        do {
          if (*(int *)(*(int *)(iVar1 + 0x3c) + iVar5 + 0x44) != 0) {
            (**(code **)(*(int *)(iVar1 + 0x30) + 0x24))();
            iVar4 = *(int *)(*(int *)(iVar1 + 0x3c) + iVar5 + 4);
            *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) | 2;
          }
          iVar5 = iVar5 + 0x48;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)*(ushort *)(iVar1 + 0x7c));
      }
      *(undefined2 *)(iVar1 + 0x7e) = 0;
      (**(code **)(*(int *)(iVar1 + 0x30) + 0x1c))(iVar1);
      (**(code **)(iVar1 + 0xc0))(iVar1,DAT_300d2aec,0xffffffff);
      (**(code **)(iVar1 + 0xc0))(iVar1,DAT_300d2af0,0);
      if ((code *)*DAT_300d2af4 != (code *)0x0) {
        (*(code *)*DAT_300d2af4)(iVar1);
      }
      *(undefined4 *)(iVar1 + 0x24) = 0;
      semGive(*(undefined4 *)(iVar1 + 0x34));
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * dosFsChkDsk @ 0x300D1BE0  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: errnoSet, logMsg
 * Вызывают: FUN_300d5b4c
 * Константы: 0xFFFFFFFF, 0x300D1BE0
 * Данные: DAT_300d2aec, DAT_300d2af0, DAT_300d2af8, DAT_300d2afc, DAT_300d2b00, DAT_300d2b04
 * ---------------------------------------------------------------- */
undefined4 dosFsChkDsk(int *param_1,uint param_2)

{
  undefined4 uVar1;
  byte bVar2;
  undefined1 uVar3;
  code *pcVar4;
  int iVar5;
  
  pcVar4 = (code *)*DAT_300d2af8;
  iVar5 = *param_1;
  if (pcVar4 == (code *)0x0) {
    errnoSet(DAT_300d2afc);
    if (*DAT_300d2b00 != 0) {
      logMsg(DAT_300d2b04,0,0,0,0,0,0);
    }
    uVar1 = 0xffffffff;
  }
  else {
    if ((param_2 & 2) == 0) {
      bVar2 = (byte)param_2 | 1;
    }
    else {
      bVar2 = (byte)param_2 & 0xfe;
    }
    *(byte *)(iVar5 + 0x8e) = bVar2;
    uVar3 = 0;
    if ((param_2 >> 8 & 0xff) != 0xff) {
      uVar3 = (char)(param_2 >> 8);
    }
    *(undefined1 *)(iVar5 + 0x8f) = uVar3;
    uVar1 = (*pcVar4)();
    (**(code **)(iVar5 + 0xc0))(iVar5,DAT_300d2aec,0xffffffff);
    (**(code **)(iVar5 + 0xc0))(iVar5,DAT_300d2af0,0);
    *(undefined1 *)(iVar5 + 0x8e) = 0;
    *(undefined1 *)(iVar5 + 0x8f) = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300d1ccc @ 0x300D1CCC  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: FUN_300d266c
 * Константы: 0x300D1CCC
 * Данные: DAT_300d2b00, DAT_300d2c3c, DAT_300d2c40
 * ---------------------------------------------------------------- */
void FUN_300d1ccc(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (param_1 <= *DAT_300d2b00) {
    if (param_4 == 0) {
      param_4 = DAT_300d2c3c;
    }
    logMsg(DAT_300d2c40,param_2,param_3,param_4,0,0,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * dosFsVolIsFat12 @ 0x300D1D14  (примерный размер ~516 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: __udiv32, bcmp, dosfsDiskToHost16, dosfsDiskToHost32, strlen
 * Вызывают: FUN_300d266c
 * Константы: 0xFFFFFFFF, 0x300D1D14
 * Данные: DAT_300d2c44, DAT_300d2c48, DAT_300d2d40, DAT_300d2dfc
 * ---------------------------------------------------------------- */
uint dosFsVolIsFat12(int param_1)

{
  char cVar1;
  bool bVar2;
  char *__s;
  char *__s_00;
  uint uVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  __s_00 = DAT_300d2c48;
  __s = DAT_300d2c44;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar3 = dosfsDiskToHost16(param_1 + 0x13);
  uVar3 = uVar3 & 0xffff;
  if ((uVar3 == 0) && (uVar3 = dosfsDiskToHost32(param_1 + 0x20), uVar3 == 0)) {
    return 0xffffffff;
  }
  sVar4 = strlen(__s);
  iVar5 = bcmp((void *)(param_1 + 3),__s,sVar4);
  if (iVar5 != 0) {
    sVar4 = strlen(__s_00);
    iVar5 = bcmp((void *)(param_1 + 3),__s_00,sVar4);
    if (iVar5 != 0) {
      bVar2 = false;
      goto LAB_300d1dc0;
    }
  }
  bVar2 = true;
LAB_300d1dc0:
  iVar5 = bcmp((void *)(param_1 + 3),DAT_300d2d40,5);
  if (iVar5 == 0) {
    iVar5 = 0x40;
  }
  else {
    iVar5 = 0x20;
  }
  uVar6 = dosfsDiskToHost16(param_1 + 0xb);
  uVar6 = uVar6 & 0xffff;
  if (uVar6 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar7 = dosfsDiskToHost16(param_1 + 0x11);
    uVar7 = uVar7 & 0xffff;
    if (uVar7 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      cVar1 = *(char *)(param_1 + 0xd);
      if (cVar1 == '\0') {
        uVar3 = 0xffffffff;
      }
      else {
        uVar10 = (uint)*(byte *)(param_1 + 0x10);
        if (uVar10 == 0) {
          uVar3 = 0xffffffff;
        }
        else {
          uVar8 = dosfsDiskToHost16(param_1 + 0xe);
          uVar9 = dosfsDiskToHost16(param_1 + 0x16);
          uVar9 = uVar9 & 0xffff;
          if (uVar9 == 0) {
            uVar3 = 0xffffffff;
          }
          else if (bVar2) {
            iVar5 = __udiv32(iVar5 * uVar7 + uVar6 + -1,uVar6);
            iVar5 = __udiv32(uVar3 - (iVar5 + uVar10 * uVar9 + (uVar8 & 0xffff)),cVar1);
            if (DAT_300d2dfc < iVar5 + 2U) {
              uVar3 = 0;
            }
            else {
              uVar3 = 1;
            }
          }
          else {
            iVar5 = __udiv32(uVar7 * iVar5 + uVar6 + -1,uVar6);
            uVar3 = __udiv32(uVar3 - (uVar10 * uVar9 + iVar5 + (uVar8 & 0xffff)),cVar1);
            uVar3 = (uint)(uVar3 < DAT_300d2dfc);
          }
        }
      }
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300d1f18 @ 0x300D1F18  (примерный размер ~216 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 3
 * Вызывает: logMsg, semGive, semTake
 * Вызывают: FUN_300d20d4, FUN_300d348c, dosFsXbdBlkCopy, dosFsXbdBlkRead, dosFsXbdBlkWrite
 * Константы: 0xFFFFFFFF, 0x300D1F18
 * Данные: DAT_300d2b00, DAT_300d2ef8, DAT_300d2efc, DAT_300d2f00
 * ---------------------------------------------------------------- */
int FUN_300d1f18(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = semTake(*(undefined4 *)(param_1 + 0x200),0xffffffff);
  if (iVar1 == -1) {
    iVar1 = 0;
  }
  else {
    iVar1 = semTake(*(undefined4 *)(param_1 + 0x204),0xffffffff);
    if (iVar1 == -1) {
      semGive(*(undefined4 *)(param_1 + 0x200));
      iVar1 = 0;
    }
    else if (*(ushort *)(param_1 + 0x208) == DAT_300d2ef8) {
      semGive(*(undefined4 *)(param_1 + 0x200));
      semGive(*(undefined4 *)(param_1 + 0x204));
      if (*DAT_300d2b00 != 0) {
        logMsg(DAT_300d2efc,0,0,0,0,0,0);
      }
      iVar1 = 0;
    }
    else {
      iVar2 = param_1 + (uint)*(ushort *)(param_1 + 0x208) * 0x38;
      iVar1 = iVar2 + 0x20c;
      *(undefined2 *)(param_1 + 0x208) = *(undefined2 *)(iVar2 + DAT_300d2f00);
      semGive(*(undefined4 *)(param_1 + 0x204));
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300d1ff0 @ 0x300D1FF0  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Вызывают: FUN_300d20d4, FUN_300d348c, dosFsXbdBlkCopy, dosFsXbdBlkRead, dosFsXbdBlkWrite
 * Константы: 0xFFFFFFFF, 0x300D1FF0
 * ---------------------------------------------------------------- */
undefined4 FUN_300d1ff0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = semTake(*(undefined4 *)(param_1 + 0x204),0xffffffff);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  *(undefined2 *)(param_2 + 0x36) = *(undefined2 *)(param_1 + 0x208);
  *(undefined2 *)(param_1 + 0x208) = *(undefined2 *)(param_2 + 0x34);
  semGive(*(undefined4 *)(param_1 + 0x200));
  semGive(*(undefined4 *)(param_1 + 0x204));
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300d204c @ 0x300D204C  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 2
 * Вызывает: semTake, xbdStrategy
 * Вызывают: FUN_300d20d4, dosFsXbdBlkCopy, dosFsXbdBlkRead, dosFsXbdBlkWrite
 * Константы: 0xFFFFFFFF, 0x300D204C
 * Данные: DAT_300d3018
 * ---------------------------------------------------------------- */
undefined4
FUN_300d204c(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 4) = param_3;
  *(undefined4 *)(param_2 + 8) = param_4;
  *(undefined4 *)(param_2 + 0xc) = param_5;
  *(undefined4 *)(param_2 + 0x1c) = param_6;
  *(undefined4 *)(param_2 + 0x24) = DAT_300d3018;
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_2 + 0x2c) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
  xbdStrategy(*(undefined4 *)(param_1 + 0x28),param_2);
  iVar1 = semTake(*(undefined4 *)(param_2 + 0x28),0xffffffff);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_2 + 0x14) != 0) {
    return 0xffffffff;
  }
  return *(undefined4 *)(param_2 + 0x18);
}

/* ----------------------------------------------------------------
 * FUN_300d20d4 @ 0x300D20D4  (примерный размер ~376 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 7
 * Вызывает: FUN_300d1f18, FUN_300d1ff0, FUN_300d204c, __errno, bcopy, errnoSet, xbdIoctl
 * Вызывают: dosFsXbdBlkCopy, dosFsXbdBlkRead, dosFsXbdBytesRW, dosFsXbdIoctl
 * Константы: 0x300D20D4
 * Данные: DAT_300d31c8
 * ---------------------------------------------------------------- */
int FUN_300d20d4(int param_1,undefined4 param_2,undefined4 param_3,void *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  void *__dest;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = 0;
  iVar1 = FUN_300d1f18();
  if (iVar1 == 0) {
    iVar4 = -1;
  }
  else {
    __dest = *(void **)(iVar1 + 0x10);
    if ((param_5 == 1) || (param_5 == 2)) {
      if ((*(uint *)(param_1 + 0x1cc) & 1) == 0) {
        bcopy(param_4,__dest,*(size_t *)(param_1 + 0x1fc));
      }
      else {
        *(void **)(iVar1 + 0x10) = param_4;
      }
      iVar2 = FUN_300d204c(param_1,iVar1,param_2,param_3,*(undefined4 *)(param_1 + 0x1fc),2);
      if (iVar2 != 0) {
        if (iVar2 != -1) {
          errnoSet(iVar2);
        }
        iVar4 = -1;
      }
    }
    else {
      if ((*(uint *)(param_1 + 0x1cc) & 1) != 0) {
        *(void **)(iVar1 + 0x10) = param_4;
      }
      iVar2 = FUN_300d204c(param_1,iVar1,param_2,param_3,*(undefined4 *)(param_1 + 0x1fc),1);
      if (iVar2 != 0) {
        if (iVar2 != -1) {
          errnoSet();
        }
        iVar4 = -1;
      }
      if ((*(uint *)(param_1 + 0x1cc) & 1) == 0) {
        bcopy(*(void **)(iVar1 + 0x10),param_4,*(size_t *)(param_1 + 0x1fc));
      }
    }
    *(void **)(iVar1 + 0x10) = __dest;
    FUN_300d1ff0(param_1,iVar1);
    if ((iVar4 == 0) && (param_5 == 2)) {
      puVar3 = (undefined4 *)__errno();
      uVar5 = *puVar3;
      xbdIoctl(*(undefined4 *)(param_1 + 0x28),DAT_300d31c8,0);
      puVar3 = (undefined4 *)__errno();
      *puVar3 = uVar5;
    }
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * dosFsXbdBytesRW @ 0x300D224C  (примерный размер ~1056 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 5
 * Вызывает: FUN_300d20d4, __errno, bcopy, semGive, semTake
 * Вызывают: FUN_300cdb24, FUN_300d266c, FUN_300db20c, fat16VolMount
 * Константы: 0xFFFFFFFF, 0x300D224C
 * Данные: DAT_300d2884
 * ---------------------------------------------------------------- */
undefined4
dosFsXbdBytesRW(int param_1,uint param_2,uint param_3,int param_4,void *param_5,size_t param_6,
               int param_7)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  int iVar7;
  undefined4 uVar8;
  uint *puVar9;
  int iVar10;
  void *__src;
  bool bVar11;
  bool bVar12;
  
  if (((param_7 != 0) && (param_7 != 1)) && (param_7 != 2)) {
    return 0xffffffff;
  }
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300d2884;
    return 0xffffffff;
  }
  uVar3 = *(uint *)(param_1 + 0x1f8);
  bVar12 = param_3 <= uVar3;
  bVar11 = uVar3 == param_3;
  if (bVar11) {
LAB_300d22d4:
    if (bVar11) {
      bVar12 = param_2 <= *(uint *)(param_1 + 500);
    }
    if (!bVar12 || bVar11 && *(uint *)(param_1 + 500) == param_2) {
LAB_300d22dc:
      puVar1 = (undefined4 *)__errno();
      *puVar1 = 0x16;
      return 0xffffffff;
    }
  }
  else {
    if ((int)uVar3 <= (int)param_3) goto LAB_300d22dc;
    if ((int)uVar3 <= (int)param_3) goto LAB_300d22d4;
  }
  if (((*(uint *)(param_1 + 0x1fc) < param_4 + param_6) || (param_4 < 0)) || (param_6 == 0)) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    return 0xffffffff;
  }
  iVar2 = semTake(*(undefined4 *)(param_1 + 0x1d0),0xffffffff);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  piVar5 = (int *)(param_1 + 0x1d4);
  iVar2 = 1;
  do {
    if (*piVar5 == 0) {
      semGive(*(undefined4 *)(param_1 + 0x1d0));
      return 0xffffffff;
    }
    piVar5 = piVar5 + 5;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = *(int *)(param_1 + 0x1e8);
  if ((iVar2 == -1) ||
     (iVar10 = iVar2 * 0x14 + param_1,
     *(uint *)(iVar10 + 0x1e0) != param_3 || *(uint *)(iVar10 + 0x1dc) != param_2)) {
    iVar2 = 0;
    puVar6 = (uint *)(param_1 + 0x1dc);
    puVar9 = puVar6;
    do {
      if (puVar9[1] == param_3 && *puVar9 == param_2) goto LAB_300d2564;
      puVar9 = puVar9 + 5;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 1);
    iVar10 = 0;
    do {
      iVar2 = iVar10;
      if (puVar6[1] == 0xffffffff && *puVar6 == 0xffffffff) break;
      puVar6 = puVar6 + 5;
      iVar10 = iVar10 + 1;
      iVar2 = -1;
    } while (iVar10 < 1);
    if (iVar2 == -1) {
      iVar2 = 0;
    }
    iVar7 = iVar2 * 0x14 + param_1;
    iVar4 = *(int *)(iVar7 + 0x1e0);
    iVar10 = *(int *)(iVar7 + 0x1dc);
    if ((iVar4 != -1 || iVar10 != -1) && (*(int *)(iVar7 + 0x1e4) != 0)) {
      *(undefined4 *)(iVar7 + 0x1dc) = 0xffffffff;
      *(undefined4 *)(iVar7 + 0x1e0) = 0xffffffff;
      *(undefined4 *)(iVar7 + 0x1e4) = 0;
      iVar10 = FUN_300d20d4(param_1,iVar10,iVar4,*(undefined4 *)(iVar7 + 0x1d4),1);
      if (iVar10 == -1) {
        semGive(*(undefined4 *)(param_1 + 0x1d0));
        return 0xffffffff;
      }
    }
    if (*(int *)(iVar7 + 0x1e4) == 0) {
      if (((param_7 == 0) || (*(size_t *)(param_1 + 0x1fc) != param_6)) &&
         (iVar10 = FUN_300d20d4(param_1,param_2,param_3,*(undefined4 *)(iVar7 + 0x1d4),0),
         iVar10 == -1)) {
        semGive(*(undefined4 *)(param_1 + 0x1d0));
        return 0xffffffff;
      }
      *(uint *)(iVar7 + 0x1dc) = param_2;
      *(uint *)(iVar7 + 0x1e0) = param_3;
      *(undefined4 *)(iVar7 + 0x1e4) = 0;
    }
  }
  else {
LAB_300d2564:
    *(int *)(param_1 + 0x1f0) = *(int *)(param_1 + 0x1f0) + 1;
  }
  iVar10 = iVar2 * 0x14 + param_1;
  *(int *)(param_1 + 0x1ec) = *(int *)(param_1 + 0x1ec) + 1;
  __src = (void *)(*(int *)(iVar10 + 0x1d4) + param_4);
  if (param_7 == 0) {
    bcopy(__src,param_5,param_6);
  }
  else {
    if (param_7 == 1) {
      bcopy(param_5,__src,param_6);
      uVar8 = 1;
    }
    else {
      if (param_7 != 2) goto LAB_300d264c;
      bcopy(param_5,__src,param_6);
      iVar4 = FUN_300d20d4(param_1,param_2,param_3,*(undefined4 *)(iVar10 + 0x1d4),2);
      if (iVar4 == -1) {
        semGive(*(undefined4 *)(param_1 + 0x1d0));
        return 0xffffffff;
      }
      *(uint *)(iVar10 + 0x1dc) = param_2;
      *(uint *)(iVar10 + 0x1e0) = param_3;
      uVar8 = 0;
    }
    *(undefined4 *)(iVar10 + 0x1e4) = uVar8;
  }
LAB_300d264c:
  *(int *)(param_1 + 0x1e8) = iVar2;
  semGive(*(undefined4 *)(param_1 + 0x1d0));
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300d266c @ 0x300D266C  (примерный размер ~1788 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 15
 * Вызывает: FUN_300d1ccc, __udiv32, bcopy, dosFsVolIsFat12, dosFsXbdBytesRW, dosfsDiskToHost16, dosfsDiskToHost32, errnoGet, errnoSet, ffsMsb, logMsg, memcmp, puts, xbdBlockSize
 *           ...
 * Вызывают: FUN_300d2d68
 * Константы: 0xFFFFFFFF, 0x300D266C, 0x7FFFFFFF
 * Данные: DAT_300d2b00, DAT_300d361c, DAT_300d3620, DAT_300d3624, DAT_300d3730, DAT_300d3734, DAT_300d3738, DAT_300d373c
 * ---------------------------------------------------------------- */
undefined4 FUN_300d266c(int param_1)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  undefined1 *puVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  bool bVar12;
  bool bVar13;
  uint local_238;
  uint local_234 [2];
  uint local_22c;
  uint local_228;
  undefined1 auStack_224 [12];
  char local_218 [11];
  undefined1 auStack_20d [2];
  byte local_20b;
  undefined1 auStack_20a [2];
  char local_208;
  undefined1 auStack_205 [3];
  undefined1 auStack_202 [6];
  undefined1 auStack_1fc [4];
  undefined1 auStack_1f8 [4];
  undefined1 auStack_1f4 [18];
  undefined1 auStack_1e2 [456];
  char local_1a;
  char local_19;
  
  iVar6 = 0x200;
  pcVar7 = local_218;
  pcVar9 = DAT_300d361c;
  do {
    iVar6 = iVar6 + -1;
    *pcVar7 = *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (iVar6 != 0);
  iVar6 = 9;
  puVar8 = auStack_224;
  puVar10 = DAT_300d3620;
  do {
    iVar6 = iVar6 + -1;
    *puVar8 = *puVar10;
    puVar8 = puVar8 + 1;
    puVar10 = puVar10 + 1;
  } while (iVar6 != 0);
  *(undefined4 *)(param_1 + 0x48) = 0;
  iVar6 = xbdNBlocks(*(undefined4 *)(param_1 + 0x28),&local_22c);
  if (iVar6 != 0) {
    return 0xffffffff;
  }
  iVar6 = xbdBlockSize(*(undefined4 *)(param_1 + 0x28),local_234);
  if (iVar6 != 0) {
    return 0xffffffff;
  }
  if ((local_234[0] < 0x20) || ((local_234[0] & local_234[0] - 1) != 0)) {
    if (*DAT_300d2b00 != 0) {
      logMsg(DAT_300d3624,0,0,0,0,0,0);
    }
    goto LAB_300d2d44;
  }
  local_238 = 0x200;
  if (local_234[0] < 0x201) {
    local_238 = local_234[0];
  }
  iVar6 = dosFsXbdBytesRW(param_1,*(undefined4 *)(param_1 + 0x48),0,0,local_218,local_238,0);
  if (iVar6 == -1) {
    if ((*DAT_300d2b00 != 0) && (logMsg(DAT_300d3730,0,0,0,0,0,0), *DAT_300d2b00 != 0)) {
      logMsg(DAT_300d3734,0,0,0,0,0,0);
    }
    goto LAB_300d2d44;
  }
  if ((local_218[0] != -0x17) && (local_218[0] != -0x15)) {
    FUN_300d1ccc(1,0,local_218[0],0,DAT_300d3738);
    goto LAB_300d2d44;
  }
  iVar6 = dosFsXbdBytesRW(param_1,*(undefined4 *)(param_1 + 0x48),0,local_234[0] - 2,&local_238,2,0)
  ;
  if (iVar6 == -1) {
    if (*DAT_300d2b00 != 0) {
      logMsg(DAT_300d373c,0,0,0,0,0,0);
    }
    goto LAB_300d2d44;
  }
  local_238 = dosfsDiskToHost16(&local_238);
  local_238 = local_238 & 0xffff;
  if ((local_238 != DAT_300d37ec) && ((local_1a != 'U' || (local_19 != -0x56)))) {
    FUN_300d1ccc(1,local_234[0] - 2,local_238,DAT_300d37f4,DAT_300d37f0);
    goto LAB_300d2d44;
  }
  uVar2 = dosfsDiskToHost16(auStack_20d);
  local_238 = (uint)uVar2;
  *(ushort *)(param_1 + 0x5c) = uVar2;
  if (local_238 != local_234[0]) {
    FUN_300d1ccc(1,0xb,local_238,0,DAT_300d37f8);
    if (*DAT_300d2b00 != 0) {
      logMsg(DAT_300d37fc,local_234[0],local_238,0,0,0,0);
    }
    goto LAB_300d2d44;
  }
  cVar1 = ffsMsb(local_234[0]);
  *(char *)(param_1 + 0x84) = cVar1 + -1;
  local_238 = dosfsDiskToHost16(auStack_205);
  local_238 = local_238 & 0xffff;
  if ((local_238 == 0) && (local_238 = dosfsDiskToHost32(auStack_1f8), local_238 == 0)) {
    FUN_300d1ccc(1,0x20,0,0,DAT_300d3924);
    goto LAB_300d2d44;
  }
  *(uint *)(param_1 + 0x58) = local_238;
  if (local_228 != 0 || local_238 != local_22c) {
    bVar13 = local_228 == 0;
    bVar12 = local_228 == 0;
    if (bVar12) {
LAB_300d29fc:
      if (bVar12) {
        bVar13 = local_22c <= local_238;
      }
      if (bVar13 && (!bVar12 || local_238 != local_22c)) {
LAB_300d2a04:
        *(uint *)(param_1 + 0x58) = local_22c;
      }
    }
    else {
      if (0x7fffffff < local_228) goto LAB_300d2a04;
      if ((int)local_228 < 0) goto LAB_300d29fc;
    }
    if (9 < *DAT_300d2b00) {
      logMsg(DAT_300d3928,local_238,local_22c,0,0,0,0);
    }
  }
  *(ushort *)(param_1 + 0x5e) = (ushort)local_20b;
  if (local_20b == 0) {
    FUN_300d1ccc(1,0xd,0,0,DAT_300d392c);
LAB_300d2d44:
    iVar6 = errnoGet();
    if (iVar6 == 0) {
      errnoSet(DAT_300d3cc4);
    }
    return 0xffffffff;
  }
  *(char *)(param_1 + 0x62) = local_208;
  if (local_208 == '\0') {
    FUN_300d1ccc(1,0x10,0,0,DAT_300d3930);
    goto LAB_300d2d44;
  }
  uVar4 = dosfsDiskToHost16(auStack_1fc);
  *(uint *)(param_1 + 0x54) = uVar4 & 0xffff;
  sVar3 = dosfsDiskToHost16(auStack_20a);
  *(short *)(param_1 + 0x60) = sVar3;
  if (sVar3 == 0) {
    FUN_300d1ccc(1,0xe,0,0,DAT_300d3a44);
    goto LAB_300d2d44;
  }
  uVar4 = dosfsDiskToHost16(auStack_202);
  uVar4 = uVar4 & 0xffff;
  *(uint *)(param_1 + 0x50) = uVar4;
  if (uVar4 == 0) {
    *(undefined4 *)(param_1 + 0x74) = 2;
    iVar6 = dosfsDiskToHost32(auStack_1f4);
    *(int *)(param_1 + 0x50) = iVar6;
    if (iVar6 == 0) {
      FUN_300d1ccc(1,0x24,0,DAT_300d3b74,DAT_300d3b70);
      goto LAB_300d2d44;
    }
    *(undefined2 *)(param_1 + 0x80) = 0x43;
    uVar2 = 0x47;
    goto LAB_300d2cec;
  }
  uVar5 = __udiv32(0x20000,*(undefined2 *)(param_1 + 0x5c));
  if (uVar5 < uVar4) {
    FUN_300d1ccc(1,0x16,uVar4,0,DAT_300d3a48);
    if (*DAT_300d3a4c != 0) {
      logMsg(DAT_300d3a50,*(undefined4 *)(param_1 + 0x50),*(undefined2 *)(param_1 + 0x5c),0,0,0,0);
    }
    goto LAB_300d2d44;
  }
  bcopy(auStack_1e2,auStack_224,8);
  local_238 = dosFsVolIsFat12(local_218);
  if (local_238 == 0xffffffff) {
    if (*DAT_300d3a4c != 0) {
      logMsg(DAT_300d3b58,0,0,0,0,0,0);
    }
    goto LAB_300d2d44;
  }
  if (local_238 == 1) {
    iVar6 = memcmp(auStack_224,DAT_300d3b5c,9);
    if (iVar6 == 0) {
      *(undefined4 *)(param_1 + 0x74) = 1;
      if ((*DAT_300d3b60 != 0) && (*DAT_300d3b60 < 2)) {
        puts(DAT_300d3b64);
      }
    }
    else {
      uVar11 = 0;
LAB_300d2c90:
      *(undefined4 *)(param_1 + 0x74) = uVar11;
    }
  }
  else {
    iVar6 = memcmp(auStack_224,DAT_300d3b68,9);
    if (iVar6 != 0) {
      uVar11 = 1;
      goto LAB_300d2c90;
    }
    *(undefined4 *)(param_1 + 0x74) = 0;
    if ((*DAT_300d3b60 != 0) && (*DAT_300d3b60 < 2)) {
      puts(DAT_300d3b6c);
    }
  }
  *(undefined2 *)(param_1 + 0x80) = 0x27;
  uVar2 = 0x2b;
LAB_300d2cec:
  *(ushort *)(param_1 + 0x82) = uVar2;
  *(uint *)(param_1 + 0x78) =
       *(int *)(param_1 + 0x50) * (uint)*(byte *)(param_1 + 0x62) +
       (uint)*(ushort *)(param_1 + 0x60);
  uVar11 = dosfsDiskToHost32(local_218 + *(ushort *)(param_1 + 0x80));
  *(undefined4 *)(param_1 + 0x4c) = uVar11;
  bcopy(local_218 + uVar2,(void *)(param_1 + 0x68),0xb);
  *(undefined1 *)(param_1 + 0x73) = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300d2d68 @ 0x300D2D68  (примерный размер ~332 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_300d266c, dosFsVolUnmount, errnoGet, errnoSet, semGive, semTake
 * Вызывают: FUN_300d5c58, dosFsDevCreate
 * Константы: 0xFFFFFFFF, 0x300D2D68
 * Данные: DAT_300d3cc4, DAT_300d3cc8, DAT_300d3ccc, DAT_300d3cd0, DAT_300d3cd4
 * ---------------------------------------------------------------- */
undefined4 FUN_300d2d68(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = errnoGet();
  if ((param_1 == 0) || (*(int *)(param_1 + 0x20) != DAT_300d3cc8)) {
    errnoSet(DAT_300d3ccc);
  }
  else {
    iVar2 = semTake(*(undefined4 *)(param_1 + 0x34),0xffffffff);
    if (iVar2 != -1) {
      if (*(int *)(param_1 + 0x24) != 0) {
        dosFsVolUnmount(param_1);
      }
      *(undefined4 *)(param_1 + 0x24) = 0;
      errnoSet();
      iVar2 = FUN_300d266c(param_1);
      if (iVar2 == -1) {
        iVar2 = errnoGet();
        if (iVar2 == 0) {
          errnoSet(DAT_300d3cc4);
        }
      }
      else {
        iVar4 = 4;
        iVar2 = DAT_300d3cd0;
        do {
          if ((*(code **)(iVar2 + 4) != (code *)0x0) &&
             (iVar3 = (**(code **)(iVar2 + 4))(param_1,*(undefined4 *)(iVar2 + 8)), iVar3 == 0))
          break;
          iVar2 = iVar2 + 0xc;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (iVar4 != 0) {
          iVar4 = 4;
          iVar2 = DAT_300d3cd4;
          do {
            if ((*(code **)(iVar2 + 4) != (code *)0x0) &&
               (iVar3 = (**(code **)(iVar2 + 4))(param_1,*(undefined4 *)(iVar2 + 8)), iVar3 == 0)) {
              errnoSet(uVar1);
              *(undefined4 *)(param_1 + 0x24) = 1;
              return 0;
            }
            iVar2 = iVar2 + 0xc;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
      }
      semGive(*(undefined4 *)(param_1 + 0x34));
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * dosFsFdFree @ 0x300D2EB4  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Вызывают: dosFsClose, dosFsOpen, dosFsShow
 * Константы: 0x300D2EB4, 0xFFFFFFFF
 * Данные: DAT_300d2ef8
 * ---------------------------------------------------------------- */
void dosFsFdFree(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  semTake(*(undefined4 *)(iVar1 + 0x34),0xffffffff);
  *(short *)(param_1[1] + 0x40) = *(short *)(param_1[1] + 0x40) + (short)DAT_300d2ef8;
  param_1[0x11] = 0;
  semGive(*(undefined4 *)(iVar1 + 0x34));
  return;
}

/* ----------------------------------------------------------------
 * dosFsFdGet @ 0x300D2F04  (примерный размер ~292 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: bzero, errnoSet, semGive, semTake
 * Вызывают: dosFsOpen, dosFsShow
 * Константы: 0x300D2F04, 0xFFFFFFFF
 * Данные: DAT_300d3ef4
 * ---------------------------------------------------------------- */
int * dosFsFdGet(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  void *pvVar5;
  void *pvVar6;
  void *__s;
  int *__s_00;
  
  __s_00 = (int *)0x0;
  iVar2 = semTake(*(undefined4 *)(param_1 + 0x34),0xffffffff);
  if (iVar2 == -1) {
    return (int *)0x0;
  }
  piVar3 = *(int **)(param_1 + 0x3c);
  if (piVar3 < piVar3 + (uint)*(ushort *)(param_1 + 0x7c) * 0x12) {
    piVar4 = piVar3 + (uint)*(ushort *)(param_1 + 0x7c) * 0x12;
    do {
      piVar1 = piVar3;
      if (piVar3[0x11] == 0) break;
      piVar3 = piVar3 + 0x12;
      piVar1 = __s_00;
    } while (piVar3 < piVar4);
    __s_00 = piVar1;
    if (__s_00 != (int *)0x0) {
      bzero(__s_00,0x48);
      *__s_00 = param_1;
      __s_00[0x11] = 1;
      *(short *)(param_1 + 0x7e) = *(short *)(param_1 + 0x7e) + 1;
      pvVar5 = *(void **)(param_1 + 0x40);
      __s = (void *)0x0;
      if (pvVar5 < (void *)((int)pvVar5 + (uint)*(ushort *)(param_1 + 0x7c) * 0x44)) {
        pvVar6 = (void *)((int)pvVar5 + (uint)*(ushort *)(param_1 + 0x7c) * 0x44);
        do {
          __s = pvVar5;
          if (*(short *)((int)pvVar5 + 0x40) == 0) break;
          pvVar5 = (void *)((int)pvVar5 + 0x44);
          __s = (void *)0x0;
        } while (pvVar5 < pvVar6);
      }
      bzero(__s,0x44);
      *(undefined2 *)((int)__s + 0x40) = 1;
      __s_00[1] = (int)__s;
      goto LAB_300d3010;
    }
  }
  errnoSet(DAT_300d3ef4);
LAB_300d3010:
  semGive(*(undefined4 *)(param_1 + 0x34));
  return __s_00;
}

/* ----------------------------------------------------------------
 * FUN_300d3028 @ 0x300D3028  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: bzero, semGive, semTake
 * Вызывают: dosFsOpen
 * Константы: 0x300D3028, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void FUN_300d3028(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  iVar3 = *param_1;
  iVar2 = param_1[1];
  pvVar4 = *(void **)(iVar3 + 0x40);
  semTake(*(undefined4 *)(iVar3 + 0x34),0xffffffff);
  uVar1 = (uint)*(ushort *)(iVar3 + 0x7c);
  do {
    if (uVar1 == 0) {
LAB_300d30cc:
      semGive(*(undefined4 *)(iVar3 + 0x34));
      return;
    }
    if ((((*(short *)((int)pvVar4 + 0x40) != 0) && ((void *)param_1[1] != pvVar4)) &&
        ((*(uint *)((int)pvVar4 + 8) & 3) == 0)) &&
       ((*(int *)((int)pvVar4 + 0x18) == *(int *)(iVar2 + 0x18) &&
        (*(int *)((int)pvVar4 + 0x1c) == *(int *)(iVar2 + 0x1c))))) {
      bzero((void *)param_1[1],0x44);
      param_1[1] = (int)pvVar4;
      *(short *)((int)pvVar4 + 0x40) = *(short *)((int)pvVar4 + 0x40) + 1;
      goto LAB_300d30cc;
    }
    pvVar4 = (void *)((int)pvVar4 + 0x44);
    uVar1 = uVar1 - 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300d30d8 @ 0x300D30D8  (примерный размер ~948 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: __asr64
 * Вызывают: FUN_300d348c, FUN_300d370c, FUN_300d39e8, FUN_300d5d2c, dosFsClose
 * Константы: 0xFFFFFFFF, 0x300D30D8, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300d30d8(int *param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint *puVar12;
  int iVar13;
  bool bVar14;
  bool bVar15;
  uint local_8;
  uint local_4;
  
  puVar12 = (uint *)param_1[1];
  uVar11 = 0xffffffff;
  uVar4 = *puVar12;
  uVar5 = puVar12[1];
  param_1[4] = 0;
  param_1[5] = 0;
  if ((param_1[3] == param_3 && param_1[2] == param_2) && (param_1[6] != 0)) {
    return 0;
  }
  if ((*(byte *)((int)puVar12 + 0x42) & 0x10) != 0) {
    *puVar12 = 0xffffffff;
    puVar12[1] = 0x7fffffff;
  }
  uVar6 = puVar12[1];
  bVar15 = param_3 <= uVar6;
  local_8 = param_2;
  local_4 = param_3;
  if (uVar6 == param_3) {
LAB_300d3178:
    if (uVar6 == param_3) {
      bVar15 = param_2 <= *puVar12;
    }
    if (!bVar15) {
LAB_300d3180:
      param_1[4] = param_2;
      param_1[5] = param_3;
      if (param_1[6] != 0) {
        return 0;
      }
      local_8 = param_1[2];
      local_4 = param_1[3];
    }
  }
  else {
    if ((int)uVar6 < (int)param_3) goto LAB_300d3180;
    if ((int)uVar6 < (int)param_3) goto LAB_300d3178;
  }
  uVar6 = param_1[6];
  if (uVar6 != 0) {
    uVar7 = param_1[2];
    if ((param_1[3] + uVar7 != 0) && (param_1[9] == 0)) {
      param_1[9] = 1;
      uVar6 = uVar6 - 1;
      param_1[6] = uVar6;
      uVar10 = 1 << *(sbyte *)(*param_1 + 0x84);
      param_1[2] = uVar7 - uVar10;
      param_1[3] = param_1[3] - (uint)(uVar7 < uVar10);
    }
  }
  uVar10 = puVar12[1];
  uVar7 = *puVar12;
  if (uVar10 + uVar7 != 0) {
    bVar15 = uVar7 != 0;
    uVar7 = uVar7 - 1;
    uVar10 = (uVar10 - 1) + (uint)bVar15;
  }
  bVar15 = local_4 <= uVar10;
  bVar14 = uVar10 == local_4;
  uVar8 = local_8;
  uVar9 = local_4;
  if (bVar14) {
LAB_300d324c:
    if (bVar14) {
      bVar15 = local_8 <= uVar7;
    }
    if (!bVar15 || bVar14 && uVar7 == local_8) {
LAB_300d3254:
      uVar8 = uVar7;
      uVar9 = uVar10;
    }
  }
  else {
    if ((int)uVar10 <= (int)local_4) goto LAB_300d3254;
    if ((int)uVar10 <= (int)local_4) goto LAB_300d324c;
  }
  if (uVar6 == 0) {
    uVar2 = __asr64(uVar8,uVar9,*(undefined1 *)(*param_1 + 0x84));
    iVar13 = -1;
LAB_300d33d4:
    iVar13 = (**(code **)(*(int *)(*param_1 + 0x30) + 0xc))(param_1,iVar13,uVar2);
    if (iVar13 == -1) goto LAB_300d3464;
  }
  else {
    uVar7 = param_1[3];
    uVar10 = param_1[2];
    bVar15 = uVar9 <= uVar7;
    bVar14 = uVar7 == uVar9;
    if (bVar14) {
LAB_300d32b4:
      if (bVar14) {
        bVar15 = uVar8 <= uVar10;
      }
      if (bVar15 && (!bVar14 || uVar10 != uVar8)) goto LAB_300d32bc;
LAB_300d3360:
      uVar1 = *(undefined1 *)(*param_1 + 0x84);
      iVar13 = __asr64(uVar10,uVar7);
      iVar3 = __asr64(uVar8,uVar9,uVar1);
      uVar2 = iVar3 - iVar13;
      if ((uint)param_1[9] <= uVar2) {
        iVar13 = param_1[6];
        goto LAB_300d33d4;
      }
      param_1[9] = param_1[9] - uVar2;
      param_1[6] = uVar6 + uVar2;
    }
    else {
      if ((int)uVar7 <= (int)uVar9) {
        if ((int)uVar9 < (int)uVar7) goto LAB_300d32b4;
        goto LAB_300d3360;
      }
LAB_300d32bc:
      uVar1 = *(undefined1 *)(*param_1 + 0x84);
      uVar2 = __asr64(uVar8,uVar9);
      iVar13 = __asr64(uVar10,uVar7,uVar1);
      uVar7 = iVar13 - uVar2;
      if (((param_1[7] == 0) || (uVar6 <= uVar7)) || (uVar6 - uVar7 < (uint)param_1[7])) {
        param_1[8] = 0;
        iVar13 = -1;
        goto LAB_300d33d4;
      }
      param_1[9] = uVar7 + param_1[9];
      param_1[6] = uVar6 - uVar7;
    }
  }
  param_1[2] = local_8;
  param_1[3] = local_4;
  uVar11 = 0;
  if ((uVar9 != local_4 || uVar8 != local_8) &&
     (uVar6 = *(ushort *)(*param_1 + 0x5c) - 1,
     (local_4 & (int)uVar6 >> 0x1f) + (local_8 & uVar6) == 0)) {
    param_1[9] = param_1[9] + -1;
    param_1[6] = param_1[6] + 1;
  }
LAB_300d3464:
  puVar12 = (uint *)param_1[1];
  *puVar12 = uVar4;
  puVar12[1] = uVar5;
  return uVar11;
}

/* ----------------------------------------------------------------
 * FUN_300d348c @ 0x300D348C  (примерный размер ~640 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_300d1f18, FUN_300d1ff0, FUN_300d30d8, bzero
 * Вызывают: FUN_300d370c, FUN_300d5d2c
 * Константы: 0xFFFFFFFF, 0x300D348C, 0x80000000
 * Данные: DAT_300d4558
 * ---------------------------------------------------------------- */
undefined4 FUN_300d348c(int *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  void *__s;
  bool bVar10;
  bool bVar11;
  
  iVar5 = *param_1;
  uVar2 = param_1[4];
  iVar3 = param_1[5];
  iVar1 = FUN_300d30d8(param_1,*(undefined4 *)param_1[1],((undefined4 *)param_1[1])[1]);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  uVar4 = uVar2 - param_1[2];
  uVar2 = iVar3 - (param_1[3] + (uint)(uVar2 < (uint)param_1[2]));
  uVar9 = param_1[2] & *(ushort *)(iVar5 + 0x5c) - 1;
  if (uVar9 == 0) goto LAB_300d35fc;
  iVar1 = FUN_300d1f18(iVar5);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  __s = *(void **)(iVar1 + 0x10);
  uVar8 = *(ushort *)(iVar5 + 0x5c) - uVar9;
  uVar6 = (int)uVar8 >> 0x1f;
  bVar11 = uVar2 <= uVar6;
  bVar10 = uVar6 == uVar2;
  uVar7 = uVar8;
  if (bVar10) {
LAB_300d3544:
    if (bVar10) {
      bVar11 = uVar4 <= uVar8;
    }
    if (bVar11 && (!bVar10 || uVar8 != uVar4)) {
LAB_300d354c:
      uVar7 = uVar4;
    }
  }
  else {
    if (!bVar10 && (int)uVar2 <= (int)uVar6) goto LAB_300d354c;
    if ((int)uVar2 < (int)uVar6) goto LAB_300d3544;
  }
  bzero(__s,uVar7);
  (**(code **)(iVar5 + 0xb4))
            (iVar5,param_1[6],0,uVar9,__s,uVar7,((*(uint *)(iVar5 + 0x9c) & 0xc0000) != 0) + '\x01')
  ;
  if (uVar7 == uVar8) {
    param_1[6] = param_1[6] + 1;
    param_1[9] = param_1[9] + -1;
  }
  bVar11 = uVar4 < uVar7;
  uVar4 = uVar4 - uVar7;
  uVar2 = uVar2 - (((int)uVar7 >> 0x1f) + (uint)bVar11);
  uVar9 = param_1[2];
  param_1[2] = uVar9 + uVar7;
  param_1[3] = param_1[3] + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar9,uVar7);
  FUN_300d1ff0(iVar5,iVar1,uVar7);
LAB_300d35fc:
  iVar1 = uVar2 + uVar4;
  do {
    if (iVar1 == 0) {
      return 0;
    }
    if ((param_1[9] == 0) &&
       (iVar1 = (*(code *)**(undefined4 **)(iVar5 + 0x30))(param_1,param_2), iVar1 == -1)) {
      return 0xffffffff;
    }
    iVar1 = (**(code **)(iVar5 + 0xc0))(iVar5,DAT_300d4558,param_1[6]);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    uVar6 = (uint)*(ushort *)(iVar5 + 0x5c);
    bVar11 = uVar2 == 0;
    bVar10 = uVar2 == 0;
    uVar9 = uVar4;
    if (bVar10) {
LAB_300d3684:
      if (bVar10) {
        bVar11 = uVar4 <= uVar6;
      }
      if (!bVar11 || bVar10 && uVar6 == uVar4) {
LAB_300d368c:
        param_1[6] = param_1[6] + 1;
        param_1[9] = param_1[9] + -1;
        uVar9 = uVar6;
      }
    }
    else {
      if (-1 < (int)uVar2) goto LAB_300d368c;
      if (uVar2 < 0x80000000) goto LAB_300d3684;
    }
    uVar6 = param_1[2];
    bVar11 = uVar4 < uVar9;
    uVar4 = uVar4 - uVar9;
    uVar2 = uVar2 - (((int)uVar9 >> 0x1f) + (uint)bVar11);
    iVar1 = uVar2 + uVar4;
    param_1[2] = uVar6 + uVar9;
    param_1[3] = param_1[3] + ((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar6,uVar9);
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300d370c @ 0x300D370C  (примерный размер ~732 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300d1a4c, FUN_300d1a80, FUN_300d30d8, FUN_300d348c, errnoSet
 * Вызывают: dosFsOpen
 * Константы: 0xFFFFFFFF, 0x300D370C, 0x80000000
 * Данные: DAT_300d4660, DAT_300d4664
 * ---------------------------------------------------------------- */
int FUN_300d370c(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  bool bVar8;
  bool bVar9;
  uint local_2c;
  uint local_28;
  
  puVar7 = (uint *)param_1[1];
  iVar6 = *param_1;
  if ((*(byte *)((int)puVar7 + 0x42) & 0x10) != 0) {
    errnoSet(DAT_300d4660);
    return -1;
  }
  if (puVar7[1] == param_3 && *puVar7 == param_2) {
    return 0;
  }
  if ((param_1[0x10] & 2U) == 0) {
    errnoSet(DAT_300d4664);
    return -1;
  }
  iVar1 = FUN_300d1a4c(param_1,0xffffffff);
  if (iVar1 == -1) {
    return -1;
  }
  local_2c = param_1[2];
  local_28 = param_1[3];
  uVar3 = puVar7[1];
  bVar9 = param_3 <= uVar3;
  bVar8 = uVar3 == param_3;
  if (bVar8) {
LAB_300d37c8:
    if (bVar8) {
      bVar9 = param_2 <= *puVar7;
    }
    if (bVar9 && (!bVar8 || *puVar7 != param_2)) goto LAB_300d37d0;
LAB_300d3934:
    iVar2 = param_1[4];
    iVar5 = param_1[5];
    param_1[4] = param_2;
    param_1[5] = param_3;
    iVar1 = FUN_300d348c(param_1,0x80000000);
    if (iVar1 != 0) {
      param_1[4] = iVar2;
      param_1[5] = iVar5;
      goto LAB_300d39c4;
    }
    *puVar7 = param_2;
    puVar7[1] = param_3;
    iVar6 = (**(code **)(*(int *)(iVar6 + 0x2c) + 8))(param_1,6,0);
    if (iVar6 != 0) goto LAB_300d39c4;
  }
  else {
    if ((int)uVar3 <= (int)param_3) {
      if ((int)param_3 < (int)uVar3) goto LAB_300d37c8;
      goto LAB_300d3934;
    }
LAB_300d37d0:
    bVar9 = param_3 <= local_28;
    bVar8 = local_28 == param_3;
    uVar3 = param_2;
    uVar4 = param_3;
    if (bVar8) {
LAB_300d37e0:
      if (bVar8) {
        bVar9 = param_2 <= local_2c;
      }
      if (!bVar9 || bVar8 && local_2c == param_2) {
LAB_300d37e8:
        uVar3 = local_2c;
        uVar4 = local_28;
      }
    }
    else {
      if ((int)local_28 <= (int)param_3) goto LAB_300d37e8;
      if ((int)local_28 <= (int)param_3) goto LAB_300d37e0;
    }
    local_2c = uVar3;
    local_28 = uVar4;
    if (param_3 + param_2 == 0) {
      iVar1 = FUN_300d30d8(param_1,0);
      if ((iVar1 != 0) ||
         ((puVar7[3] != 0 &&
          (iVar1 = (**(code **)(*(int *)(iVar6 + 0x30) + 8))(param_1,0xffffffff,0), iVar1 != 0))))
      goto LAB_300d39c4;
      *puVar7 = param_2;
      puVar7[1] = param_3;
      puVar7[3] = 0;
      iVar6 = (**(code **)(*(int *)(iVar6 + 0x2c) + 8))(param_1,6);
    }
    else {
      iVar1 = FUN_300d30d8(param_1,param_2 - 1,(param_3 - 1) + (uint)(param_2 != 0));
      if (iVar1 != 0) goto LAB_300d39c4;
      *puVar7 = param_2;
      puVar7[1] = param_3;
      iVar2 = (**(code **)(*(int *)(iVar6 + 0x2c) + 8))(param_1,6,0);
      if (iVar2 != 0) goto LAB_300d39c4;
      iVar1 = (**(code **)(*(int *)(iVar6 + 0x30) + 8))(param_1,param_1[6],1);
      iVar6 = iVar1;
    }
    if (iVar6 != 0) goto LAB_300d39c4;
    param_1[4] = 0;
    param_1[5] = 0;
  }
  iVar1 = FUN_300d30d8(param_1,local_2c,local_28);
  if (iVar1 != -1) {
    *(undefined1 *)((int)param_1 + 0x2d) = 1;
    FUN_300d1a80(param_1);
    return 0;
  }
LAB_300d39c4:
  FUN_300d30d8(param_1,local_2c,local_28);
  FUN_300d1a80(param_1);
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300d39e8 @ 0x300D39E8  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300d30d8, __asr64, errnoSet
 * Константы: 0x300D39E8, 0xFFFFFFFE, 0xFFFFFFFF
 * Данные: DAT_300d3ccc
 * ---------------------------------------------------------------- */
undefined4 FUN_300d39e8(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  
  uVar5 = *(uint *)(param_2 + 4);
  uVar6 = uVar5 & 0xfffffffe;
  iVar1 = (int)uVar5 >> 0x1f;
  if (param_1[3] == iVar1 && param_1[2] == uVar6) {
    return 0;
  }
  if (*(int *)(param_1[1] + 0x14) != -1) {
LAB_300d3ac0:
    uVar2 = FUN_300d30d8(param_1,uVar6,iVar1);
    return uVar2;
  }
  iVar3 = *param_1;
  iVar4 = *(int *)(iVar3 + 0x2c);
  if (*(int *)(iVar4 + 0x2c) == 0) goto LAB_300d3ac0;
  bVar8 = -1 < (int)uVar5;
  bVar7 = -1 < (int)uVar5;
  uVar5 = *(int *)(iVar4 + 0x2c) << *(sbyte *)(iVar3 + 0x84);
  if (!bVar7) {
    if (bVar7 || 0 < iVar1) goto LAB_300d3a78;
    if (!bVar7 && 0 >= iVar1) goto LAB_300d3a88;
  }
  if (bVar7) {
    bVar8 = uVar6 <= uVar5;
  }
  if (bVar8 && (!bVar7 || uVar5 != uVar6)) {
LAB_300d3a88:
    param_1[2] = uVar6;
    param_1[3] = iVar1;
    iVar1 = __asr64(uVar6,iVar1,*(undefined1 *)(iVar3 + 0x84));
    param_1[6] = iVar1 + *(int *)(iVar4 + 0x28);
    param_1[9] = *(int *)(iVar4 + 0x2c) - iVar1;
    return 0;
  }
LAB_300d3a78:
  errnoSet(DAT_300d3ccc);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300d3ad8 @ 0x300D3AD8  (примерный размер ~256 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: FUN_300d3bd8
 * Константы: 0xFFFFFFFF, 0x300D3AD8
 * Данные: DAT_300d4b68
 * ---------------------------------------------------------------- */
undefined4 FUN_300d3ad8(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int aiStack_168 [18];
  undefined1 auStack_120 [4];
  undefined4 local_11c;
  int local_118;
  
  iVar4 = *(int *)(*param_1 + 0x2c);
  iVar1 = 0x12;
  piVar2 = aiStack_168;
  piVar3 = param_1;
  do {
    iVar1 = iVar1 + -1;
    *piVar2 = *piVar3;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar1 != 0);
  if (*(int *)(param_1[1] + 0x14) != -1) {
    local_11c = 0;
    local_118 = 0;
    iVar1 = (**(code **)(iVar4 + 4))(aiStack_168,auStack_120);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    iVar1 = (**(code **)(iVar4 + 4))(aiStack_168,auStack_120,0);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    iVar1 = (**(code **)(iVar4 + 4))(aiStack_168,auStack_120,0);
    if (iVar1 == -1) {
      return 0;
    }
    if (local_118 != 0) {
      return 0;
    }
  }
  errnoSet(DAT_300d4b68);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300d3bd8 @ 0x300D3BD8  (примерный размер ~324 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_300d1a4c, FUN_300d1a80, FUN_300d3ad8, errnoSet, semGive, semTake
 * Вызывают: FUN_300d3f80
 * Константы: 0xFFFFFFFF, 0x300D3BD8
 * Данные: DAT_300d3ccc, DAT_300d4b6c
 * ---------------------------------------------------------------- */
undefined4 FUN_300d3bd8(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *param_1;
  uVar3 = 0xffffffff;
  bVar1 = false;
  iVar2 = FUN_300d1a4c(param_1,0xffffffff);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  if (param_1[0x11] == 0) {
    errnoSet(DAT_300d3ccc);
    goto LAB_300d3d08;
  }
  if ((*(uint *)(param_1[1] + 8) & 2) != 0) {
    errnoSet(DAT_300d4b6c);
    goto LAB_300d3d08;
  }
  if ((*(uint *)(param_1[1] + 8) & 1) == 0) {
    iVar2 = semTake(*(undefined4 *)(iVar4 + 0x34),0xffffffff);
    if (iVar2 == -1) goto LAB_300d3d08;
    bVar1 = true;
    if (((*(byte *)(param_1[1] + 0x42) & 0x10) == 0) || (iVar2 = FUN_300d3ad8(param_1), iVar2 != -1)
       ) {
      iVar2 = (**(code **)(*(int *)(iVar4 + 0x2c) + 8))(param_1,0x100,0);
      if (iVar2 != -1) {
        iVar2 = param_1[1];
        *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | 1;
        if ((*(int *)(iVar2 + 0xc) == 0) ||
           (iVar2 = (**(code **)(*(int *)(iVar4 + 0x30) + 8))(param_1,0xffffffff,0), iVar2 != -1))
        goto LAB_300d3cf4;
      }
      goto LAB_300d3cf8;
    }
  }
  else {
LAB_300d3cf4:
    uVar3 = 0;
LAB_300d3cf8:
    if (!bVar1) goto LAB_300d3d08;
  }
  semGive(*(undefined4 *)(iVar4 + 0x34));
LAB_300d3d08:
  FUN_300d1a80(param_1);
  return uVar3;
}

/* ----------------------------------------------------------------
 * dosFsClose @ 0x300D3D1C  (примерный размер ~612 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 7
 * Вызывает: FUN_300d1a4c, FUN_300d1a80, FUN_300d30d8, __errno, dosFsFdFree, errnoSet, time
 * Вызывают: FUN_300d3f80, FUN_300d439c, FUN_300d4a88, FUN_300d5b4c, FUN_300d5c80, dosFsShow
 * Константы: 0xFFFFFFFF, 0x300D3D1C, 0xFFFFFFFB
 * Данные: DAT_300d4b6c, DAT_300d4ca4, DAT_300d4ca8, DAT_300d4cac, DAT_300d4cb0, DAT_300d4d14
 * ---------------------------------------------------------------- */
undefined4 dosFsClose(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  time_t tVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  
  uVar7 = 0xffffffff;
  bVar1 = false;
  if ((((param_1 == (int *)0x0) || (param_1 == (int *)0xffffffff)) || (param_1[0x11] == 0)) ||
     (iVar9 = *param_1, *(int *)(iVar9 + 0x20) != DAT_300d4ca4)) {
    errnoSet(DAT_300d4ca8);
    return 0xffffffff;
  }
  piVar8 = (int *)param_1[1];
  iVar2 = FUN_300d1a4c(param_1,0xffffffff);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  uVar6 = piVar8[2];
  if ((uVar6 & 2) != 0) {
    errnoSet(DAT_300d4b6c);
    uVar7 = 0xffffffff;
    goto LAB_300d3f38;
  }
  if (*(short *)(iVar9 + 0x7e) != 0) {
    *(short *)(iVar9 + 0x7e) = *(short *)(iVar9 + 0x7e) + (short)DAT_300d4cac;
  }
  if ((uVar6 & 1) == 0) {
    if ((*(byte *)((int)piVar8 + 0x42) & 0x10) == 0) {
      if (*(int *)(iVar9 + 0x94) == 0) {
        *(undefined1 *)(param_1 + 0xb) = 0;
      }
      iVar2 = param_1[0xb];
      if (((char)iVar2 == '\0') && (*(char *)((int)param_1 + 0x2d) == '\0')) {
LAB_300d3e70:
        if (((piVar8[2] & 4U) != 0) && ((short)piVar8[0x10] == 1)) {
LAB_300d3e88:
          if ((short)piVar8[0x10] == 1) {
            iVar2 = *piVar8;
            if (piVar8[1] + iVar2 == 0) {
              iVar5 = 0;
              iVar2 = iVar5;
            }
            else {
              iVar5 = iVar2 + -1;
              iVar2 = piVar8[1] + -1 + (uint)(iVar2 != 0);
            }
            iVar2 = FUN_300d30d8(param_1,iVar5,iVar2);
            if (iVar2 == -1) goto LAB_300d3f1c;
            if (param_1[6] != 0) {
              (**(code **)(*(int *)(iVar9 + 0x30) + 8))(param_1,param_1[6],1);
              piVar8[2] = piVar8[2] & 0xfffffffb;
            }
          }
          bVar1 = true;
          *(undefined1 *)((int)param_1 + 0x2d) = 0;
        }
        goto LAB_300d3f18;
      }
      tVar4 = time((time_t *)0x0);
      iVar2 = (**(code **)(*(int *)(iVar9 + 0x2c) + 8))
                        (param_1,((char)iVar2 == '\0') * '\x02' + '\x04',tVar4);
      if (iVar2 != -1) {
        *(undefined1 *)(param_1 + 0xb) = 0;
        if (*(char *)((int)param_1 + 0x2d) == '\0') goto LAB_300d3e70;
        goto LAB_300d3e88;
      }
    }
    else {
      bVar1 = true;
LAB_300d3f18:
      uVar7 = 0;
    }
LAB_300d3f1c:
    if (!bVar1) goto LAB_300d3f38;
  }
  else {
    puVar3 = (undefined4 *)__errno();
    bVar1 = true;
    *puVar3 = DAT_300d4cb0;
  }
  (**(code **)(*(int *)(iVar9 + 0x30) + 0x24))(param_1);
LAB_300d3f38:
  FUN_300d1a80(param_1);
  dosFsFdFree(param_1);
  if ((*(short *)(iVar9 + 0x7e) == 0) || (bVar1)) {
    (**(code **)(iVar9 + 0xc0))(iVar9,DAT_300d4d14,0);
  }
  return uVar7;
}

/* ----------------------------------------------------------------
 * FUN_300d3f80 @ 0x300D3F80  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300d3bd8, dosFsClose, dosFsOpen, errnoGet, errnoSet
 * Константы: 0x300D3F80, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300d3f80(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = dosFsOpen(param_1,param_2,1,0);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  uVar2 = FUN_300d3bd8(iVar1);
  uVar3 = errnoGet();
  dosFsClose(iVar1);
  errnoSet(uVar3);
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300d3fd4 @ 0x300D3FD4  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __div64, bzero
 * Константы: 0x300D3FD4
 * Данные: DAT_300d4d18, DAT_300d4d1c
 * ---------------------------------------------------------------- */
void FUN_300d3fd4(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  puVar4 = (uint *)param_1[1];
  iVar3 = *param_1;
  bzero(param_2,0x48);
  *param_2 = iVar3;
  param_2[3] = 1;
  uVar5 = *puVar4;
  uVar6 = puVar4[1];
  param_2[6] = uVar5;
  param_2[7] = uVar6;
  iVar1 = (uint)*(ushort *)(iVar3 + 0x5e) << *(sbyte *)(iVar3 + 0x84);
  param_2[0xb] = iVar1;
  if (iVar1 != 0) {
    uVar7 = iVar1 - 1;
    iVar2 = __div64(uVar5 + uVar7,uVar6 + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar5,uVar7),iVar1,
                    iVar1 >> 0x1f);
    param_2[0xc] = iVar2;
    *(undefined1 *)(param_2 + 0xd) = *(undefined1 *)((int)puVar4 + 0x42);
    uVar5 = DAT_300d4d18;
    param_2[2] = DAT_300d4d18;
    uVar6 = DAT_300d4d1c;
    if ((*(byte *)((int)puVar4 + 0x42) & 1) != 0) {
      param_2[2] = DAT_300d4d1c;
      uVar5 = uVar6;
    }
    if ((*(byte *)((int)puVar4 + 0x42) & 0x10) == 0) {
      param_2[2] = uVar5 | 0x8000;
    }
    else {
      param_2[2] = uVar5 | 0x4000;
      param_2[6] = iVar1;
      param_2[7] = iVar1 >> 0x1f;
    }
    (**(code **)(*(int *)(iVar3 + 0x2c) + 0xc))(param_1,param_2);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d40c8 @ 0x300D40C8  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __asr64, __div64
 * Константы: 0xFFFFFFFF, 0x300D40C8
 * ---------------------------------------------------------------- */
void FUN_300d40c8(int *param_1,undefined4 *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  
  *param_2 = 0;
  iVar3 = *param_1;
  uVar1 = *(ushort *)(iVar3 + 0x5e);
  param_2[1] = (uint)uVar1 << *(sbyte *)(iVar3 + 0x84);
  param_2[2] = *(undefined4 *)(iVar3 + 100);
  if (uVar1 != 0) {
    uVar4 = (**(code **)(*(int *)(iVar3 + 0x30) + 0x10))(param_1);
    iVar3 = *param_1;
    uVar4 = __asr64((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),*(undefined1 *)(iVar3 + 0x84));
    uVar2 = __div64((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),*(undefined2 *)(iVar3 + 0x5e),0);
    param_2[3] = uVar2;
  }
  param_2[4] = param_2[3];
  param_2[5] = 0xffffffff;
  param_2[6] = 0xffffffff;
  param_2[7] = *(undefined4 *)(*param_1 + 0x4c);
  param_2[8] = 0;
  return;
}

/* ----------------------------------------------------------------
 * dosPathParse @ 0x300D4164  (примерный размер ~328 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: FUN_300d42ac, FUN_300dada0
 * Константы: 0x300D4164
 * Данные: DAT_300d4d20, DAT_300d4d24
 * ---------------------------------------------------------------- */
int dosPathParse(char *param_1,undefined4 *param_2,uint param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  *param_2 = 0;
  cVar1 = *param_1;
  iVar3 = 0;
  while (cVar1 != '\0') {
    cVar1 = *param_1;
    if ((cVar1 == '/') || (cVar1 == '\\')) {
LAB_300d41b8:
      param_1 = param_1 + 1;
      iVar4 = iVar3;
    }
    else if (cVar1 == '.') {
      cVar1 = param_1[1];
      if (((cVar1 == '\0') || (cVar1 == '/')) || (cVar1 == '\\')) goto LAB_300d41b8;
      if ((cVar1 != '.') ||
         (((cVar1 = param_1[2], cVar1 != '\0' && (cVar1 != '/')) && (cVar1 != '\\'))))
      goto LAB_300d41f4;
      if (iVar3 != 0) {
        iVar3 = iVar3 + -1;
      }
      param_1 = param_1 + 2;
      iVar4 = iVar3;
    }
    else {
LAB_300d41f4:
      if (param_3 <= iVar3 + 1U) break;
      param_2[iVar3 * 2] = param_1;
      pcVar2 = (char *)0x0;
      param_2[iVar3 * 2 + 2] = 0;
      if (*param_1 == '/') {
LAB_300d4258:
        errnoSet(DAT_300d4d20);
        return -1;
      }
      do {
        cVar1 = *param_1;
        if ((cVar1 == '\\') || (cVar1 == '\0')) break;
        if ((cVar1 != '.') && (cVar1 != ' ')) {
          pcVar2 = param_1;
        }
        param_1 = param_1 + 1;
      } while (*param_1 != '/');
      if (pcVar2 == (char *)0x0) goto LAB_300d4258;
      iVar4 = iVar3 + 1;
      *(short *)(param_2 + iVar3 * 2 + 1) = ((short)pcVar2 - (short)param_2[iVar3 * 2]) + 1;
    }
    iVar3 = iVar4;
    cVar1 = *param_1;
  }
  if (*param_1 == '\0') {
    return iVar3;
  }
  errnoSet(DAT_300d4d24);
  return -1;
}

/* ----------------------------------------------------------------
 * FUN_300d42ac @ 0x300D42AC  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: dosPathParse, errnoSet, memcmp, strncasecmp
 * Вызывают: FUN_300d439c
 * Константы: 0xFFFFFFFF, 0x300D42AC
 * Данные: DAT_300d4ca8
 * ---------------------------------------------------------------- */
undefined4 FUN_300d42ac(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint __n;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_7e8;
  ushort local_7e4 [498];
  undefined4 local_400;
  ushort local_3fc [498];
  
  puVar5 = &local_7e8;
  iVar1 = dosPathParse(param_2,&local_7e8,0x7d);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar3 = dosPathParse(param_3,&local_400,0x7d);
    if (iVar3 == -1) {
      uVar2 = 0xffffffff;
    }
    else {
      if (iVar1 < iVar3) {
        iVar3 = 0;
        if (0 < iVar1) {
          puVar6 = &local_400;
          iVar3 = iVar1;
          do {
            __n = (uint)*(ushort *)(puVar5 + 1);
            if (*(ushort *)(puVar6 + 1) != __n) break;
            if (*(int *)(param_1 + 0x98) == 0) {
              iVar4 = strncasecmp((char *)*puVar5,(char *)*puVar6,__n);
            }
            else {
              iVar4 = memcmp((char *)*puVar5,(char *)*puVar6,__n);
            }
            if (iVar4 != 0) break;
            puVar5 = puVar5 + 2;
            puVar6 = puVar6 + 2;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          iVar3 = iVar1 - iVar3;
        }
        if (iVar3 == iVar1) {
          errnoSet(DAT_300d4ca8);
          return 0xffffffff;
        }
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300d439c @ 0x300D439C  (примерный размер ~924 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 10
 * Вызывает: FUN_300d1a4c, FUN_300d1a80, FUN_300d42ac, dosFsClose, dosFsIoctl, dosFsOpen, errnoGet, errnoSet, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300D439C
 * Данные: DAT_300d4660, DAT_300d4ca8, DAT_300d4d28, DAT_300d4d2c, DAT_300d4d30
 * ---------------------------------------------------------------- */
int FUN_300d439c(int *param_1,undefined4 param_2,char *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 auStack_9c [12];
  undefined1 auStack_6c [32];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  
  iVar8 = param_1[1];
  iVar9 = -1;
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    errnoSet(2);
    iVar9 = -1;
  }
  else {
    iVar10 = *param_1;
    if (param_4 == 0) {
      iVar1 = dosFsOpen(iVar10,param_3,(uint)(*(int *)(iVar10 + 0x98) != 0) << 0x11,0);
      if (iVar1 != -1) {
        dosFsClose(iVar1);
        errnoSet(DAT_300d4d28);
        return -1;
      }
      errnoSet(0);
    }
    iVar1 = (**(code **)(*(int *)(iVar10 + 0x2c) + 0xc))(param_1,auStack_6c);
    if (iVar1 == -1) {
      iVar9 = -1;
    }
    else if (((*(byte *)(param_1[1] + 0x42) & 0x10) == 0) ||
            (iVar1 = FUN_300d42ac(iVar10,param_2,param_3), iVar1 != -1)) {
      while( true ) {
        iVar1 = dosFsOpen(iVar10,param_3,(uint)(*(int *)(iVar10 + 0x98) != 0) << 0x11 | DAT_300d4d2c
                          ,0);
        if (iVar1 == -1) {
          return -1;
        }
        iVar2 = FUN_300d1a4c(iVar1,0xffffffff);
        if (iVar2 == -1) {
          dosFsClose(iVar1);
          return -1;
        }
        semTake(*(undefined4 *)(iVar10 + 0x34),0xffffffff);
        iVar2 = *(int *)(iVar1 + 4);
        if (iVar2 == iVar8) {
          semGive(*(undefined4 *)(iVar10 + 0x34));
          FUN_300d1a80(iVar1);
          dosFsClose(iVar1);
          errnoSet(DAT_300d4ca8);
          return -1;
        }
        if ((*(int *)(iVar10 + 0x24) == 0) || (uVar3 = *(uint *)(iVar2 + 8), (uVar3 & 2) != 0)) {
          errnoSet(DAT_300d4d30);
          goto LAB_300d46ec;
        }
        if ((uVar3 & 1) == 0) break;
        semGive(*(undefined4 *)(iVar10 + 0x34));
        FUN_300d1a80(iVar1);
      }
      if ((*(byte *)(iVar2 + 0x42) & 0x10) == 0) {
        *(uint *)(iVar2 + 8) = uVar3 | 1;
        iVar5 = 0xb;
        puVar6 = auStack_9c;
        puVar7 = (undefined4 *)(iVar8 + 0x14);
        do {
          iVar5 = iVar5 + -1;
          *puVar6 = *puVar7;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar5 != 0);
        iVar5 = 0xb;
        puVar6 = (undefined4 *)(iVar8 + 0x14);
        puVar7 = (undefined4 *)(iVar2 + 0x14);
        do {
          iVar5 = iVar5 + -1;
          *puVar6 = *puVar7;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar5 != 0);
        iVar5 = (**(code **)(*(int *)(iVar10 + 0x2c) + 8))(param_1,1,local_44);
        if (((iVar5 == -1) ||
            (iVar5 = (**(code **)(*(int *)(iVar10 + 0x2c) + 8))(param_1,2,local_48), iVar5 == -1))
           || (iVar5 = (**(code **)(*(int *)(iVar10 + 0x2c) + 8))(param_1,4,local_4c), iVar5 == -1))
        {
          iVar2 = 0xb;
          puVar6 = (undefined4 *)(iVar8 + 0x14);
          puVar7 = auStack_9c;
          do {
            iVar2 = iVar2 + -1;
            *puVar6 = *puVar7;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          } while (iVar2 != 0);
        }
        else {
          iVar9 = 0xb;
          puVar6 = (undefined4 *)(iVar8 + 0x14);
          puVar7 = auStack_9c;
          do {
            iVar9 = iVar9 + -1;
            *puVar6 = *puVar7;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          } while (iVar9 != 0);
          (**(code **)(*(int *)(iVar10 + 0x2c) + 8))(param_1,0x100,0);
          iVar9 = 0xb;
          puVar6 = (undefined4 *)(iVar8 + 0x14);
          puVar7 = (undefined4 *)(iVar2 + 0x14);
          do {
            iVar9 = iVar9 + -1;
            *puVar6 = *puVar7;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          } while (iVar9 != 0);
          if (*(int *)(iVar2 + 0xc) != 0) {
            (**(code **)(*(int *)(iVar10 + 0x30) + 8))(iVar1,0xffffffff,0);
          }
          iVar9 = 0;
        }
      }
      else {
        errnoSet(DAT_300d4660);
      }
LAB_300d46ec:
      semGive(*(undefined4 *)(iVar10 + 0x34));
      FUN_300d1a80(iVar1);
      uVar4 = errnoGet();
      dosFsClose(iVar1);
      errnoSet(uVar4);
      if (iVar9 == 0) {
        dosFsIoctl(param_1,2,0xffffffff);
      }
    }
    else {
      iVar9 = -1;
    }
  }
  return iVar9;
}

/* ----------------------------------------------------------------
 * FUN_300d4738 @ 0x300D4738  (примерный размер ~288 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300D4738
 * Данные: DAT_300d4d14
 * ---------------------------------------------------------------- */
undefined4 FUN_300d4738(int param_1,uint param_2)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar5;
  
  uVar4 = 0;
  semTake(*(undefined4 *)(param_1 + 0x34),0xffffffff);
  bVar5 = param_2 == 0xffffffff;
  if (bVar5) {
    param_2 = 0;
  }
  bVar1 = (byte)param_2;
  if (bVar5) {
    *(byte *)(param_1 + 0x8c) = bVar1;
    *(byte *)(param_1 + 0x8d) = bVar1;
    *(uint *)(param_1 + 0x9c) = param_2;
  }
  else {
    if ((param_2 & 0xff) == 4) {
      *(undefined1 *)(param_1 + 0x8c) = 0;
    }
    else {
      uVar3 = param_2 & 0xff00;
      *(byte *)(param_1 + 0x8c) = ((param_2 & 0xff) == 2) + 1U | bVar1 & 8;
      bVar5 = uVar3 == 0x100;
      if ((!bVar5) && (bVar5 = uVar3 == 0x200, !bVar5)) {
        bVar5 = uVar3 == 0xff00;
      }
      if (bVar5) {
        uVar2 = (undefined1)(param_2 >> 8);
      }
      else {
        uVar2 = 2;
      }
      *(undefined1 *)(param_1 + 0x8d) = uVar2;
    }
    if ((param_2 & 0xf0000) != *(uint *)(param_1 + 0x9c)) {
      if ((*(uint *)(param_1 + 0x9c) == 0) &&
         (((*(int *)(param_1 + 200) != 0 && (*(int *)(param_1 + 0xc4) != 0)) ||
          ((*(int *)(param_1 + 0x14c) != 0 && (*(int *)(param_1 + 0x148) != 0)))))) {
        uVar4 = (**(code **)(param_1 + 0xc0))(param_1,DAT_300d4d14,0);
      }
      *(uint *)(param_1 + 0x9c) = param_2 & 0xf0000;
    }
    param_2 = (int)param_2 >> 0x14 & 1;
  }
  *(uint *)(param_1 + 0xa0) = param_2;
  semGive(*(undefined4 *)(param_1 + 0x34));
  return uVar4;
}

/* ----------------------------------------------------------------
 * FUN_300d4858 @ 0x300D4858  (примерный размер ~560 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __asr64, errnoSet
 * Константы: 0xFFFFFFFF, 0x300D4858
 * Данные: DAT_300d4ca8, DAT_300d4d34, DAT_300d4d38, DAT_300d4d3c
 * ---------------------------------------------------------------- */
undefined4 FUN_300d4858(int *param_1,uint *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int *piVar9;
  
  iVar3 = *param_1;
  iVar4 = *(int *)(param_1[1] + 0xc);
  if (param_2 == (uint *)0x0) {
    errnoSet(DAT_300d4ca8);
    uVar2 = 0xffffffff;
  }
  else {
    uVar7 = param_2[1];
    uVar5 = *param_2;
    if (uVar7 + uVar5 == 0) {
      errnoSet(DAT_300d4d34);
      uVar2 = 0xffffffff;
    }
    else if ((*(byte *)(param_1[1] + 0x42) & 0x10) == 0) {
      if ((param_1[0x10] & 2U) == 0) {
        errnoSet(DAT_300d4d3c);
        uVar2 = 0xffffffff;
      }
      else {
        if (uVar7 == 0xffffffff && uVar5 == 0xffffffff) {
          uVar2 = 0xffffffff;
        }
        else {
          iVar6 = uVar5 + *(ushort *)(iVar3 + 0x5c);
          uVar2 = __asr64(iVar6 + -1,
                          uVar7 + CARRY4(uVar5,(uint)*(ushort *)(iVar3 + 0x5c)) + -1 +
                          (uint)(iVar6 != 0),*(undefined1 *)(iVar3 + 0x84));
        }
        iVar6 = (**(code **)(*(int *)(iVar3 + 0x30) + 0x14))(param_1,uVar2);
        if (iVar6 == -1) {
          uVar2 = 0xffffffff;
        }
        else {
          uVar5 = param_2[1];
          uVar7 = *param_2;
          puVar8 = (uint *)param_1[1];
          if (uVar5 == 0xffffffff && uVar7 == 0xffffffff) {
            uVar7 = (uint)*(ushort *)(iVar3 + 0x5e) * (param_1[8] - puVar8[3]) <<
                    *(sbyte *)(iVar3 + 0x84);
            uVar5 = (int)uVar7 >> 0x1f;
          }
          *puVar8 = uVar7;
          puVar8[1] = uVar5;
          iVar6 = (**(code **)(*(int *)(iVar3 + 0x2c) + 8))(param_1,0,0);
          if (iVar6 == -1) {
            uVar2 = 0xffffffff;
          }
          else {
            if (iVar4 != 0) {
              uVar2 = *(undefined4 *)(param_1[1] + 0xc);
              *(int *)(param_1[1] + 0xc) = iVar4;
              (**(code **)(*(int *)(iVar3 + 0x30) + 8))(param_1,0xffffffff,0);
              iVar6 = param_1[1];
              iVar4 = 1;
              *(undefined4 *)(iVar6 + 0xc) = uVar2;
              uVar1 = *(ushort *)(iVar6 + 0x40);
              piVar9 = *(int **)(*param_1 + 0x3c);
              if (1 < uVar1) {
                do {
                  if (((piVar9[0x11] != 0) && (piVar9 != param_1)) && (piVar9[1] == iVar6)) {
                    iVar4 = iVar4 + 1;
                    piVar9[4] = piVar9[2];
                    piVar9[5] = piVar9[3];
                    piVar9[2] = 0;
                    piVar9[3] = 0;
                    piVar9[9] = 0;
                    piVar9[6] = 0;
                  }
                  piVar9 = piVar9 + 0x12;
                } while (iVar4 < (int)(uint)uVar1);
              }
            }
            iVar3 = (**(code **)(*(int *)(iVar3 + 0x30) + 0xc))(param_1,0xffffffff,0);
            if (iVar3 == -1) {
              uVar2 = 0xffffffff;
            }
            else {
              uVar2 = 0;
            }
          }
        }
      }
    }
    else {
      errnoSet(DAT_300d4d38);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300d4a88 @ 0x300D4A88  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: dosFsClose, dosFsOpen, errnoSet, ioFullFileNameGet
 * Константы: 0x300D4A88, 0xFFFFFFFF
 * Данные: DAT_300d4d40, DAT_300d4d44
 * ---------------------------------------------------------------- */
undefined4 FUN_300d4a88(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_4 [4];
  
  iVar2 = -DAT_300d4d40;
  iVar1 = ioFullFileNameGet(param_2,&stack0xfffffff8 + iVar2,auStack_4 + iVar2);
  if (iVar1 == 0) {
    if (*(int *)(&stack0xfffffff8 + iVar2) == param_1) {
      iVar2 = dosFsOpen(param_1,auStack_4 + iVar2,0xa00,0x4000);
      if (iVar2 != -1) {
        dosFsClose(iVar2);
        return 0;
      }
    }
    else {
      errnoSet(DAT_300d4d44);
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * dosFsIoctl @ 0x300D4B08  (примерный размер ~3344 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 4
 * Вызывает: FUN_300d1a4c, FUN_300d1a80, errnoSet, xbdIoctl
 * Вызывают: FUN_300d439c, FUN_300d6578, dosFsOpen, dosFsShow
 * Константы: 0xFFFFFFFF, 0x300D4B08, 0x300D4D10
 * Данные: DAT_300d4ca4, DAT_300d4ca8, DAT_300d4d14, DAT_300d4d48, DAT_300d4d4c, DAT_300d4d50, DAT_300d4d54, DAT_300d4d58
 * ---------------------------------------------------------------- */
undefined4 dosFsIoctl(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if (((param_1 == (int *)0x0) || (param_1 == (int *)0xffffffff)) ||
     (iVar2 = *param_1, *(int *)(iVar2 + 0x20) != DAT_300d4ca4)) {
    errnoSet(DAT_300d4ca8,param_2,0);
    return 0xffffffff;
  }
  iVar1 = xbdIoctl(*(undefined4 *)(iVar2 + 0x28),DAT_300d4d48,0);
  if ((iVar1 != 0) && (iVar1 != 0x23)) {
    errnoSet();
    return 0xffffffff;
  }
  if ((*(int *)(iVar2 + 0x2b4) != 0) &&
     (((((param_2 == 0x2c || (param_2 == 0xf)) ||
        ((param_2 == 0x2a || (((param_2 == 0x37 || (param_2 == 0x24)) || (param_2 == 0x3b)))))) ||
       ((param_2 == 0x31 || (param_2 == 0x23)))) ||
      ((param_2 == 0x22 ||
       (((param_2 == 0x20 || (param_2 == 0x1f)) || ((param_2 == 10 || (param_2 == 0x2f)))))))))) {
    errnoSet(0x1e);
    return 0xffffffff;
  }
  iVar1 = FUN_300d1a4c(param_1,0xffffffff);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  if (param_1[0x11] == 0) {
    errnoSet(DAT_300d6340);
  }
  else if ((*(int *)(iVar2 + 0x24) == 0) || ((*(uint *)(param_1[1] + 8) & 2) != 0)) {
    errnoSet(DAT_300d4d4c);
  }
  else if ((*(uint *)(param_1[1] + 8) & 1) == 0) {
    if (param_2 != DAT_300d4d54) {
      if ((int)DAT_300d4d54 < (int)param_2) {
        if (param_2 < 0x49) {
                    /* WARNING: Could not recover jumptable at 0x300d4d10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (**(code **)(DAT_300d4d60 + param_2 * 4))(iVar1);
          return uVar3;
        }
      }
      else if (((param_2 == DAT_300d4d14) || (param_2 == DAT_300d4d58)) || (param_2 == DAT_300d4d5c)
              ) {
        uVar3 = 0xffffffff;
        errnoSet(DAT_300d6340);
        goto LAB_300d57fc;
      }
      FUN_300d1a80(param_1);
      iVar2 = xbdIoctl(*(undefined4 *)(iVar2 + 0x28),param_2,param_3);
      if (iVar2 != 0) {
        errnoSet(iVar2);
        return 0xffffffff;
      }
      return 0;
    }
    uVar3 = (**(code **)(iVar2 + 0xc0))(iVar2,0x38,param_3);
  }
  else {
    errnoSet(DAT_300d4d50);
  }
LAB_300d57fc:
  FUN_300d1a80(param_1);
  return uVar3;
}

/* ----------------------------------------------------------------
 * dosFsOpen @ 0x300D5818  (примерный размер ~820 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 14
 * Вызывает: FUN_300d1a4c, FUN_300d1a80, FUN_300d3028, FUN_300d370c, FUN_300d5c58, dosFsFdFree, dosFsFdGet, dosFsIoctl, errnoGet, errnoSet, semGive, semTake, strlen, xbdIoctl
 * Вызывают: FUN_300d3f80, FUN_300d439c, FUN_300d4a88, FUN_300d5b4c, FUN_300d5c80, dosFsShow
 * Константы: 0xFFFFFFFF, 0x300D5818, 0xFFFFFBFF
 * Данные: DAT_300d633c, DAT_300d6340, DAT_300d67dc, DAT_300d67e0, DAT_300d67e4, DAT_300d67e8, DAT_300d69c8, DAT_300d69cc
 * ---------------------------------------------------------------- */
int dosFsOpen(int param_1,char *param_2,uint param_3,uint param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  size_t sVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = 0;
  bVar2 = false;
  bVar3 = true;
  if (((param_1 == 0) || (*(int *)(param_1 + 0x20) != DAT_300d67dc)) || ((param_3 & 3) == 3)) {
    errnoSet(DAT_300d6340);
    return -1;
  }
  uVar7 = param_3 + 1;
  if ((param_2 == (char *)0x0) || (sVar4 = strlen(param_2), 0x400 < sVar4)) {
    errnoSet(DAT_300d67e0);
    return -1;
  }
  iVar5 = semTake(*(undefined4 *)(param_1 + 0x34),0xffffffff);
  if (iVar5 == -1) {
    return -1;
  }
  iVar5 = xbdIoctl(*(undefined4 *)(param_1 + 0x28),DAT_300d67e4,0);
  if ((iVar5 != 0) && (iVar5 != 0x23)) {
    errnoSet(iVar5);
    semGive(*(undefined4 *)(param_1 + 0x34));
    return -1;
  }
  bVar1 = true;
  uVar8 = uVar7;
  if ((*(int *)(param_1 + 0x24) == 0) && (iVar5 = FUN_300d5c58(param_1), iVar5 == -1)) {
LAB_300d5ae0:
    semGive(*(undefined4 *)(param_1 + 0x34));
LAB_300d5ae8:
    if (!bVar2) goto LAB_300d5af8;
  }
  else {
    if ((*(int *)(param_1 + 0x2b4) != 0) && ((param_3 & DAT_300d67e8) != 0)) {
      semGive(*(undefined4 *)(param_1 + 0x34));
      errnoSet(0x1e);
      return -1;
    }
    if ((param_4 & 0xf000) == 0x4000) {
      uVar8 = uVar7 & 0xfffffbff;
      if ((uVar7 & 0x200) != 0) {
        uVar8 = uVar8 | 0x800;
      }
    }
    else {
      param_4 = 0x8000;
    }
    iVar9 = dosFsFdGet(param_1);
    if (iVar9 == 0) {
LAB_300d5ad8:
      if (bVar1) goto LAB_300d5ae0;
      goto LAB_300d5ae8;
    }
    uVar6 = errnoGet();
    errnoSet(0);
    iVar5 = (*(code *)**(undefined4 **)(param_1 + 0x2c))(iVar9,param_2,uVar8,param_4);
    if (iVar5 == -1) {
      iVar5 = errnoGet();
      if (iVar5 == 0) {
LAB_300d5a78:
        errnoSet(DAT_300d69cc);
      }
      goto LAB_300d5ad8;
    }
    errnoSet(uVar6);
    FUN_300d3028(iVar9);
    if (((*(byte *)(*(int *)(iVar9 + 4) + 0x42) & 1) != 0) && ((uVar8 & 2) != 0)) {
      errnoSet(DAT_300d633c);
      goto LAB_300d5ad8;
    }
    *(uint *)(iVar9 + 0x40) = uVar8;
    semGive(*(undefined4 *)(param_1 + 0x34));
    bVar1 = false;
    if ((((uVar8 & 0x200) != 0) && ((param_4 & 0xf000) != 0x4000)) &&
       ((*(byte *)(*(int *)(iVar9 + 4) + 0x42) & 0x10) != 0)) {
      errnoSet(DAT_300d69c8);
      goto LAB_300d5ae8;
    }
    if ((uVar8 & 0x10400) == 0) {
LAB_300d5ad0:
      bVar3 = false;
      goto LAB_300d5ad8;
    }
    iVar5 = FUN_300d1a4c(iVar9,0xffffffff);
    if (iVar5 == -1) goto LAB_300d5ae8;
    bVar2 = true;
    if (*(int *)(iVar9 + 0x44) != 0) {
      if ((*(uint *)(*(int *)(iVar9 + 4) + 8) & 3) != 0) goto LAB_300d5a78;
      if ((uVar8 & 0x400) != 0) {
        uVar6 = *(undefined4 *)(iVar9 + 0x40);
        *(undefined4 *)(iVar9 + 0x40) = 3;
        iVar5 = FUN_300d370c(iVar9,0);
        *(undefined4 *)(iVar9 + 0x40) = uVar6;
        if (iVar5 == -1) goto LAB_300d5af0;
      }
      if ((uVar8 & 0x10000) != 0) {
        (**(code **)(*(int *)(param_1 + 0x30) + 4))(iVar9);
      }
      goto LAB_300d5ad0;
    }
    errnoSet(DAT_300d6340);
  }
LAB_300d5af0:
  FUN_300d1a80(iVar9);
LAB_300d5af8:
  if (bVar3) {
    if (iVar9 != 0) {
      dosFsFdFree(iVar9);
    }
    return -1;
  }
  if ((uVar8 & 0x2000) != 0) {
    dosFsIoctl(iVar9,0x15,0xffffffff);
  }
  if ((param_3 & 0x200) != 0) {
    *(undefined1 *)(iVar9 + 0x2d) = 1;
    return iVar9;
  }
  return iVar9;
}

/* ----------------------------------------------------------------
 * FUN_300d5b4c @ 0x300D5B4C  (примерный размер ~268 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: dosFsChkDsk, dosFsClose, dosFsOpen, semGive
 * Вызывают: FUN_300d5c58, dosFsDevCreate
 * Константы: 0x300D5B4C, 0xFFFFFFFD, 0xFFFFFFFF
 * Данные: DAT_300d64f4, DAT_300d6b28, DAT_300d6b2c
 * ---------------------------------------------------------------- */
undefined4 FUN_300d5b4c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = -1;
  if (((((*DAT_300d64f4 == 0) || (*(char *)(param_1 + 0x8c) == '\0')) ||
       (*(char *)(param_1 + 0x8e) != '\0')) ||
      ((iVar3 = dosFsOpen(param_1,DAT_300d6b28,0,0), iVar3 == -1 ||
       (iVar1 = dosFsChkDsk(iVar3,*(undefined2 *)(param_1 + 0x8c)), iVar1 == 0)))) ||
     ((*(byte *)(param_1 + 0x8c) & 2) == 0)) {
    if ((code *)*DAT_300d6b2c != (code *)0x0) {
      (*(code *)*DAT_300d6b2c)(param_1);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  if (iVar3 != -1) {
    *(uint *)(*(int *)(iVar3 + 4) + 8) = *(uint *)(*(int *)(iVar3 + 4) + 8) & 0xfffffffd;
    dosFsClose(iVar3);
  }
  if ((*(int *)(param_1 + 0x24) != 0) && (*(code **)(param_1 + 0xb0) != (code *)0x0)) {
    (**(code **)(param_1 + 0xb0))(param_1);
  }
  semGive(*(undefined4 *)(param_1 + 0x34));
  if (*(int *)(param_1 + 0x24) == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300d5c58 @ 0x300D5C58  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300d2d68, FUN_300d5b4c
 * Вызывают: dosFsOpen
 * Константы: 0x300D5C58, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300d5c58(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_300d2d68();
  if (iVar1 == 0) {
    uVar2 = FUN_300d5b4c(param_1);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300d5c80 @ 0x300D5C80  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_300d1a4c, FUN_300d1a80, dosFsClose, dosFsOpen, errnoSet, time
 * Константы: 0x300D5C80, 0xFFFFFFFF
 * Данные: DAT_300d69cc
 * ---------------------------------------------------------------- */
int FUN_300d5c80(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  time_t tVar3;
  
  iVar1 = dosFsOpen(param_1,param_2,param_3 | 0x600,0x8000);
  if (iVar1 != -1) {
    iVar2 = FUN_300d1a4c(iVar1,0xffffffff);
    if (iVar2 == -1) {
      dosFsClose(iVar1);
      iVar1 = -1;
    }
    else {
      if ((*(int *)(iVar1 + 0x44) == 0) || ((*(uint *)(*(int *)(iVar1 + 4) + 8) & 3) != 0)) {
        errnoSet(DAT_300d69cc);
        iVar1 = -1;
      }
      else {
        tVar3 = time((time_t *)0x0);
        (**(code **)(*(int *)(param_1 + 0x2c) + 8))(iVar1,7,tVar3);
      }
      FUN_300d1a80(iVar1);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300d5d2c @ 0x300D5D2C  (примерный размер ~2124 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_300d1a4c, FUN_300d1a80, FUN_300d30d8, FUN_300d348c, errnoGet, errnoSet, xbdIoctl
 * Вызывают: FUN_300d6578
 * Константы: 0xFFFFFFFF, 0x300D5D2C, 0x80000000
 * Данные: DAT_300d5e84, DAT_300d633c, DAT_300d6340, DAT_300d6610, DAT_300d67dc, DAT_300d67e4, DAT_300d6e18, DAT_300d6e1c
 * ---------------------------------------------------------------- */
int FUN_300d5d2c(int *param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  bool bVar11;
  bool bVar12;
  int local_4c;
  int local_c;
  uint local_8;
  int local_4;
  
  bVar1 = true;
  if (((param_1 == (int *)0x0) || (param_1 == (int *)0xffffffff)) ||
     (iVar9 = *param_1, *(int *)(iVar9 + 0x20) != DAT_300d67dc)) {
    errnoSet(DAT_300d6340);
    return -1;
  }
  puVar10 = (uint *)param_1[1];
  iVar2 = xbdIoctl(*(undefined4 *)(iVar9 + 0x28),DAT_300d67e4,0);
  if ((iVar2 != 0) && (iVar2 != 0x23)) {
    errnoSet();
    return -1;
  }
  if (*(int *)(*param_1 + 0x24) == 0) {
    errnoSet(DAT_300d6610);
    return -1;
  }
  iVar2 = FUN_300d1a4c(param_1,0xffffffff);
  if (iVar2 == -1) {
    return -1;
  }
  if ((*(byte *)((int)puVar10 + 0x42) & 0x10) != 0) {
    FUN_300d1a80(param_1);
    errnoSet(DAT_300d5e84);
    return -1;
  }
  if (param_3 == 0) {
    FUN_300d1a80(param_1);
    return 0;
  }
  local_8 = param_3;
  local_4 = param_4;
  if (param_1[0x11] == 0) {
    errnoSet(DAT_300d6340);
LAB_300d64ac:
    uVar5 = param_3;
    if (local_4 != 1) {
LAB_300d64b8:
      if (local_4 != 2) goto LAB_300d6544;
    }
  }
  else {
    if ((puVar10[2] & 2) != 0) {
      errnoSet(DAT_300d6610);
      goto LAB_300d64ac;
    }
    if ((puVar10[2] & 1) != 0) {
      errnoSet(DAT_300d6e18);
      goto LAB_300d64ac;
    }
    uVar5 = param_1[5];
    uVar4 = param_1[4];
    if (uVar5 + uVar4 != 0) {
      uVar7 = puVar10[1];
      bVar12 = uVar5 <= uVar7;
      if (uVar7 == uVar5) {
LAB_300d5eb8:
        if (uVar7 == uVar5) {
          bVar12 = uVar4 <= *puVar10;
        }
        if (!bVar12) goto LAB_300d5ed8;
      }
      else if ((int)uVar7 < (int)uVar5) {
        if ((int)uVar7 < (int)uVar5) goto LAB_300d5ed8;
        goto LAB_300d5eb8;
      }
      iVar2 = FUN_300d30d8(param_1,uVar4,uVar5);
      if (iVar2 == -1) goto LAB_300d64ac;
    }
LAB_300d5ed8:
    uVar4 = (int)param_3 >> 0x1f;
    uVar5 = param_3;
    if (param_4 != 1) {
      if ((param_1[0x10] & 2U) == 0) {
        errnoSet(DAT_300d633c);
      }
      else {
        if (*(int *)(*(int *)(iVar9 + 0x2c) + 0x38) != 1) {
          uVar7 = param_1[2];
          iVar2 = param_1[3];
          iVar8 = iVar2 + uVar4 + (uint)CARRY4(uVar7,param_3);
          if ((iVar8 >> 0x1f) + iVar8 != 0) {
            uVar6 = -iVar2;
            bVar12 = uVar6 <= uVar4;
            bVar11 = (int)(uVar4 + iVar2) < 0;
            if (uVar4 == uVar6) {
LAB_300d6040:
              if (uVar4 == uVar6) {
                bVar12 = -uVar7 - 1 <= param_3;
              }
              if (bVar12) {
LAB_300d6048:
                local_8 = -uVar7 - 1;
              }
            }
            else {
              if (bVar11 == SBORROW4(uVar4,uVar6)) goto LAB_300d6048;
              if (bVar11 == SBORROW4(uVar4,uVar6)) goto LAB_300d6040;
            }
            if ((int)local_8 < 2) goto LAB_300d6060;
          }
        }
        local_4c = ((int)local_8 <=
                   (int)((uint)*(ushort *)(iVar9 + 0x5e) << *(sbyte *)(iVar9 + 0x84))) + 0x80000000;
        if (((param_1[0x10] & 8U) == 0) ||
           (iVar2 = FUN_300d30d8(param_1,*puVar10,puVar10[1]), iVar2 != -1)) {
          if ((param_1[5] + param_1[4] != 0) &&
             (iVar2 = FUN_300d348c(param_1,local_4c), iVar2 == -1)) goto LAB_300d64ac;
          local_4 = ((*(uint *)(iVar9 + 0x9c) & 0xc0000) != 0) + 1;
          puVar10[2] = puVar10[2] | 4;
          *(undefined1 *)((int)param_1 + 0x2d) = 1;
          *(undefined1 *)(param_1 + 0xb) = 0;
          bVar1 = false;
LAB_300d611c:
          uVar4 = puVar10[3];
          if ((param_1[9] == 0) &&
             (iVar2 = (*(code *)**(undefined4 **)(iVar9 + 0x30))(param_1,local_4c), iVar2 == -1)) {
            iVar2 = errnoGet();
            if (iVar2 == DAT_300d70f8) {
              bVar1 = true;
            }
          }
          else if ((uVar4 == 0) &&
                  (iVar2 = (**(code **)(*(int *)(iVar9 + 0x2c) + 8))(param_1,0,0), iVar2 == -1)) {
            puVar10[2] = puVar10[2] | 2;
            *(short *)(*param_1 + 0x7e) = *(short *)(*param_1 + 0x7e) + (short)DAT_300d70fc;
          }
          else {
            uVar4 = param_1[2] & *(ushort *)(iVar9 + 0x5c) - 1;
            uVar5 = local_8;
            local_c = param_2;
            if (uVar4 != 0) {
              uVar7 = *(ushort *)(iVar9 + 0x5c) - uVar4;
              if (local_8 < uVar7) {
                uVar7 = local_8;
              }
              iVar2 = (**(code **)(iVar9 + 0xb4))(iVar9,param_1[6],0,uVar4,param_2,uVar7,local_4);
              param_3 = local_8;
              if (iVar2 == -1) goto LAB_300d64ac;
              local_c = param_2 + uVar7;
              uVar5 = local_8 - uVar7;
              uVar4 = param_1[2] + uVar7;
              uVar7 = param_1[3] + (uint)CARRY4(param_1[2],uVar7);
              param_1[2] = uVar4;
              param_1[3] = uVar7;
              uVar6 = *(ushort *)(iVar9 + 0x5c) - 1;
              if ((uVar7 & (int)uVar6 >> 0x1f) + (uVar4 & uVar6) == 0) {
                param_1[6] = param_1[6] + 1;
                param_1[9] = param_1[9] + -1;
              }
            }
            for (; param_3 = uVar5, *(ushort *)(iVar9 + 0x5c) <= uVar5; uVar5 = uVar5 - uVar7) {
              if ((param_1[9] == 0) &&
                 (iVar2 = (*(code *)**(undefined4 **)(iVar9 + 0x30))(param_1,local_4c), iVar2 == -1)
                 ) goto LAB_300d64ac;
              if (uVar5 >> *(sbyte *)(iVar9 + 0x84) < (uint)param_1[9]) {
                uVar4 = uVar5 >> *(sbyte *)(iVar9 + 0x84);
              }
              else {
                uVar4 = param_1[9];
              }
              if (local_4 == 0) {
                iVar2 = (**(code **)(iVar9 + 0xbc))(iVar9,param_1[6],0,uVar4,0,local_c);
                if (iVar2 == -1) goto LAB_300d6544;
              }
              else {
                iVar2 = (**(code **)(iVar9 + 0xb8))(iVar9,param_1[6],0,uVar4,0,local_c,local_4);
                if (iVar2 == -1) goto LAB_300d64ac;
              }
              uVar7 = uVar4 << *(sbyte *)(iVar9 + 0x84);
              local_c = local_c + uVar7;
              uVar6 = param_1[2];
              param_1[2] = uVar6 + uVar7;
              param_1[3] = param_1[3] + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar6,uVar7);
              param_1[6] = uVar4 + param_1[6];
              param_1[9] = param_1[9] - uVar4;
            }
            if (uVar5 == 0) goto LAB_300d64a4;
            if ((param_1[9] != 0) ||
               (iVar2 = (*(code *)**(undefined4 **)(iVar9 + 0x30))(param_1,local_4c), iVar2 != -1))
            {
              uVar7 = param_1[3];
              uVar4 = puVar10[1];
              bVar12 = uVar7 <= uVar4;
              bVar11 = uVar4 == uVar7;
              if (bVar11) {
LAB_300d6428:
                if (bVar11) {
                  bVar12 = (uint)param_1[2] <= *puVar10;
                }
                if (!bVar12 || bVar11 && *puVar10 == param_1[2]) {
LAB_300d6430:
                  iVar2 = (**(code **)(iVar9 + 0xc0))(iVar9,DAT_300d736c,param_1[6]);
                  if (iVar2 == -1) goto LAB_300d64ac;
                }
              }
              else {
                if ((int)uVar4 <= (int)uVar7) goto LAB_300d6430;
                if ((int)uVar4 <= (int)uVar7) goto LAB_300d6428;
              }
              iVar2 = (**(code **)(iVar9 + 0xb4))(iVar9,param_1[6],0,0,local_c,uVar5,local_4);
              if (iVar2 != -1) {
                uVar4 = param_1[2];
                param_3 = 0;
                param_1[2] = uVar4 + uVar5;
                param_1[3] = param_1[3] + (uint)CARRY4(uVar4,uVar5);
                goto LAB_300d64a4;
              }
            }
          }
          goto LAB_300d64ac;
        }
      }
      goto LAB_300d64b8;
    }
    if ((param_1[0x10] & 1U) != 0) {
      if (param_1[5] + param_1[4] == 0) {
        uVar6 = param_1[3];
        uVar7 = param_1[2];
        uVar5 = puVar10[1];
        bVar12 = uVar6 <= uVar5;
        if (uVar5 == uVar6) {
LAB_300d5f30:
          if (uVar5 == uVar6) {
            bVar12 = uVar7 <= *puVar10;
          }
          if (!bVar12) goto LAB_300d6060;
        }
        else if ((int)uVar5 < (int)uVar6) {
          if ((int)uVar5 < (int)uVar6) goto LAB_300d6060;
          goto LAB_300d5f30;
        }
        if (puVar10[1] != uVar6 || *puVar10 != uVar7) {
          local_4 = 0;
          local_4c = 0;
          *(undefined1 *)(param_1 + 0xb) = 1;
          uVar3 = *puVar10;
          uVar5 = puVar10[1] - (uVar6 + (uVar3 < uVar7));
          bVar12 = uVar5 <= uVar4;
          if (uVar4 == uVar5) {
LAB_300d5fa8:
            if (uVar4 == uVar5) {
              bVar12 = uVar3 - uVar7 <= param_3;
            }
            if (!bVar12) goto LAB_300d611c;
          }
          else if ((int)uVar4 < (int)uVar5) {
            if ((int)uVar4 < (int)uVar5) goto LAB_300d611c;
            goto LAB_300d5fa8;
          }
          local_8 = uVar3 - uVar7;
          goto LAB_300d611c;
        }
      }
      else {
LAB_300d6060:
        errnoSet(DAT_300d6fa4);
      }
LAB_300d64a4:
      bVar1 = false;
      goto LAB_300d64ac;
    }
    errnoSet(DAT_300d6e1c);
  }
  if (local_8 <= uVar5) goto LAB_300d6544;
  uVar7 = param_1[3];
  uVar4 = puVar10[1];
  bVar12 = uVar7 <= uVar4;
  if (uVar4 == uVar7) {
LAB_300d650c:
    if (uVar4 == uVar7) {
      bVar12 = (uint)param_1[2] <= *puVar10;
    }
    if (!bVar12) {
LAB_300d6514:
      *puVar10 = param_1[2];
      puVar10[1] = uVar7;
    }
  }
  else {
    if ((int)uVar4 < (int)uVar7) goto LAB_300d6514;
    if ((int)uVar4 < (int)uVar7) goto LAB_300d650c;
  }
  (**(code **)(*(int *)(iVar9 + 0x2c) + 8))(param_1,6,0);
  *(undefined1 *)((int)param_1 + 0x2d) = 0;
LAB_300d6544:
  FUN_300d1a80(param_1);
  if (bVar1) {
    iVar9 = -1;
  }
  else {
    iVar9 = local_8 - uVar5;
  }
  return iVar9;
}

/* ----------------------------------------------------------------
 * FUN_300d6578 @ 0x300D6578  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300d5d2c, dosFsIoctl, errnoSet
 * Константы: 0x300D6578, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int FUN_300d6578(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(int *)(*param_1 + 0x2b4) != 0) {
    errnoSet(0x1e);
    return -1;
  }
  iVar1 = FUN_300d5d2c(param_1,param_2,param_3,2);
  if ((iVar1 != -1) && ((param_1[0x10] & 0x2000U) != 0)) {
    dosFsIoctl(param_1,0x15,0xffffffff);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * dosFsLastAccessDateEnable @ 0x300D65E4  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x300D65E4
 * Данные: DAT_300d67dc
 * ---------------------------------------------------------------- */
undefined4 dosFsLastAccessDateEnable(uint param_1,int param_2)

{
  if ((param_1 & 3) != 0) {
    return 0xffffffff;
  }
  if ((*(int *)(param_1 + 0x20) == DAT_300d67dc) && ((param_2 == 1 || (param_2 == 0)))) {
    *(int *)(param_1 + 0x94) = param_2;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * dosFsLibInit @ 0x300D6630  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: iosDrvInstall
 * Вызывают: FUN_3003fb10
 * Константы: 0x300D6630, 0xFFFFFFFF
 * Данные: DAT_300d75dc, DAT_300d75e0, DAT_300d75e4, DAT_300d75e8, DAT_300d75ec, DAT_300d75f0, DAT_300d75f4, DAT_300d75f8
 * ---------------------------------------------------------------- */
undefined4 dosFsLibInit(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*DAT_300d75dc == -1) {
    iVar3 = iosDrvInstall(DAT_300d75ec,DAT_300d75f0,DAT_300d75f4,DAT_300d75f8,DAT_300d75e0,
                          DAT_300d75e4,DAT_300d75e8);
    *DAT_300d75dc = iVar3;
    puVar1 = DAT_300d75fc;
    *DAT_300d75fc = param_1;
    puVar1[1] = param_2;
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
 * FUN_300d66b0 @ 0x300D66B0  (примерный размер ~196 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: memPartAlloc, memPartFree, xbdBlockSize
 * Вызывают: dosFsDevCreate
 * Константы: 0xFFFFFFFF, 0x300D66B0
 * Данные: DAT_300d7600
 * ---------------------------------------------------------------- */
undefined4 FUN_300d66b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_28;
  
  iVar1 = xbdBlockSize(*(undefined4 *)(param_1 + 0x28),&local_28);
  if (iVar1 == 0) {
    iVar3 = 1;
    iVar1 = param_1;
    while( true ) {
      iVar2 = memPartAlloc(*DAT_300d7600,local_28);
      *(int *)(iVar1 + 0x1d4) = iVar2;
      if (iVar2 == 0) break;
      *(undefined4 *)(iVar1 + 0x1dc) = 0xffffffff;
      *(undefined4 *)(iVar1 + 0x1e0) = 0xffffffff;
      *(undefined4 *)(iVar1 + 0x1d8) = local_28;
      *(undefined4 *)(iVar1 + 0x1e4) = 0;
      iVar3 = iVar3 + -1;
      iVar1 = iVar1 + 0x14;
      if (iVar3 == 0) {
        return 0;
      }
    }
    piVar4 = (int *)(param_1 + 0x1d4);
    iVar1 = 1;
    do {
      if (*piVar4 != 0) {
        memPartFree(*DAT_300d7600,*piVar4);
      }
      piVar4 = piVar4 + 5;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * dosFsDevCreate @ 0x300D6774  (примерный размер ~1548 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 22
 * Вызывает: FUN_300d2d68, FUN_300d5b4c, FUN_300d66b0, bio_alloc, bio_free, bzero, errnoSet, fsPathAddedEventRaise, iosDevDelCallback, iosDevReplaceExt, iosLock, iosUnlock, logMsg, memPartAlloc
 *           ...
 * Вызывают: dosFsMonitorDevCreate
 * Константы: 0xFFFFFFFF, 0x300D6774
 * Данные: DAT_300d70fc, DAT_300d75dc, DAT_300d7600, DAT_300d76f4, DAT_300d76f8, DAT_300d77b8, DAT_300d77bc, DAT_300d77c0
 * ---------------------------------------------------------------- */
undefined4 dosFsDevCreate(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  short sVar1;
  void *__s;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined1 uVar6;
  uint uVar7;
  uint uVar8;
  void *pvVar9;
  bool bVar10;
  uint local_58;
  undefined1 auStack_54 [28];
  uint local_38;
  
  if (*DAT_300d75dc == -1) goto LAB_300d6d40;
  if (param_2 == 0) {
    if (*DAT_300d76f4 == 0) {
      return 0xffffffff;
    }
    logMsg(DAT_300d76f8,0,0,0,0,0,0);
    goto LAB_300d6d40;
  }
  __s = (void *)memPartAlloc(*DAT_300d7600,0x2c0);
  if (__s == (void *)0x0) goto LAB_300d6d40;
  bzero(__s,0x2c0);
  *(int *)((int)__s + 0x28) = param_2;
  iVar2 = xbdBlockSize(param_2,(int)__s + 0x1fc);
  if ((iVar2 == 0) &&
     (iVar2 = xbdNBlocks(*(undefined4 *)((int)__s + 0x28),(int)__s + 500), iVar2 == 0)) {
    bzero(auStack_54,0x30);
    iVar2 = xbdIoctl(*(undefined4 *)((int)__s + 0x28),DAT_300d77b8,auStack_54);
    *(uint *)((int)__s + 0x2b4) = local_38 & 1;
    local_58 = local_38 >> 1 & 1;
    if (iVar2 != 0) {
      xbdIoctl(*(undefined4 *)((int)__s + 0x28),0x46,&local_58);
    }
    *(uint *)((int)__s + 0xa4) = (uint)(local_58 == 1);
    iVar2 = semMCreate(*DAT_300d77bc);
    *(int *)((int)__s + 0x204) = iVar2;
    if (iVar2 != 0) {
      iVar2 = semCCreate(1,3);
      *(int *)((int)__s + 0x200) = iVar2;
      if (iVar2 != 0) {
        iVar2 = 0;
        pvVar9 = __s;
        do {
          *(short *)((int)pvVar9 + 0x240) = (short)iVar2;
          sVar1 = (short)DAT_300d70fc;
          if (iVar2 != 2) {
            sVar1 = (short)iVar2 + 1;
          }
          *(short *)((int)pvVar9 + DAT_300d77c0) = sVar1;
          iVar3 = semBCreate(1,0);
          *(int *)((int)pvVar9 + 0x23c) = iVar3;
          if (iVar3 == 0) goto LAB_300d6d20;
          pvVar9 = (void *)((int)pvVar9 + 0x38);
          iVar2 = iVar2 + 1;
        } while (iVar2 < 3);
        piVar4 = (int *)((int)__s + 0x21c);
        iVar2 = 3;
        do {
          iVar3 = bio_alloc(param_2,*DAT_300d7894);
          *piVar4 = iVar3;
          if (iVar3 == 0) goto LAB_300d6d00;
          piVar4 = piVar4 + 0xe;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        *(undefined2 *)((int)__s + 0x208) = 0;
        iVar2 = FUN_300d66b0(__s);
        if (iVar2 != -1) {
          *(undefined4 *)((int)__s + 0x1ec) = 0;
          *(undefined4 *)((int)__s + 0x1f0) = 0;
          *(undefined4 *)((int)__s + 0x1e8) = 0xffffffff;
          iVar2 = semMCreate(0xd);
          *(int *)((int)__s + 0x1d0) = iVar2;
          if (iVar2 != 0) {
            iVar2 = semMCreate(*DAT_300d77bc);
            *(int *)((int)__s + 0x34) = iVar2;
            if (iVar2 != 0) {
              iVar2 = semMCreate(*DAT_300d77bc);
              *(int *)((int)__s + 0x38) = iVar2;
              if (iVar2 != 0) {
                if (param_3 == 0) {
                  param_3 = 0x14;
                }
                uVar7 = param_3 + 2;
                pvVar9 = (void *)memPartAlloc(*DAT_300d7600,uVar7 * 0x48);
                *(void **)((int)__s + 0x3c) = pvVar9;
                if (pvVar9 != (void *)0x0) {
                  bzero(pvVar9,uVar7 * 0x48);
                  pvVar9 = (void *)memPartAlloc(*DAT_300d7600,uVar7 * 0x44);
                  *(void **)((int)__s + 0x40) = pvVar9;
                  if (pvVar9 != (void *)0x0) {
                    bzero(pvVar9,uVar7 * 0x44);
                    pvVar9 = (void *)memPartAlloc(*DAT_300d7600,uVar7 * 4);
                    *(void **)((int)__s + 0x44) = pvVar9;
                    if (pvVar9 != (void *)0x0) {
                      bzero(pvVar9,uVar7 * 4);
                      *(short *)((int)__s + 0x7c) = (short)uVar7;
                      uVar8 = 0;
                      if ((uVar7 & 0xffff) != 0) {
                        do {
                          iVar2 = semMCreate(*DAT_300d77bc);
                          if (iVar2 == 0) goto joined_r0x300d6c44;
                          *(int *)(*(int *)((int)__s + 0x44) + uVar8 * 4) = iVar2;
                          uVar8 = uVar8 + 1;
                        } while (uVar8 < *(ushort *)((int)__s + 0x7c));
                      }
                      *(undefined4 *)((int)__s + 0x20) = DAT_300d7a58;
                      *(undefined4 *)((int)__s + 0x24) = 0;
                      *(undefined4 *)((int)__s + 0x94) = 0;
                      *(undefined4 *)((int)__s + 0x98) = 0;
                      if (param_4 != 0xffffffff) {
                        if ((param_4 & 0xff) != 4) {
                          uVar7 = param_4 & 0xff00;
                          *(byte *)((int)__s + 0x8c) =
                               ((byte)((int)param_4 >> 1) & 1) + 1 | (byte)param_4 & 8;
                          bVar10 = uVar7 == 0x100;
                          if ((!bVar10) && (bVar10 = uVar7 == 0x200, !bVar10)) {
                            bVar10 = uVar7 == 0xff00;
                          }
                          if (bVar10) {
                            uVar6 = (undefined1)(param_4 >> 8);
                          }
                          else {
                            uVar6 = 2;
                          }
                          *(undefined1 *)((int)__s + 0x8d) = uVar6;
                        }
                        if (param_4 != 0xffffffff) {
                          *(uint *)((int)__s + 0x9c) = param_4 & 0xf0000;
                          *(uint *)((int)__s + 0xa0) = (int)param_4 >> 0x14 & 1;
                          *(uint *)((int)__s + 0xac) = (int)param_4 >> 0x15 & 1;
                        }
                      }
                      *(undefined4 *)((int)__s + 0xb8) = DAT_300d7a5c;
                      *(undefined4 *)((int)__s + 0xbc) = DAT_300d7a60;
                      *(undefined4 *)((int)__s + 0xb4) = DAT_300d7a64;
                      *(undefined4 *)((int)__s + 0xc0) = DAT_300d7a68;
                      iVar2 = FUN_300d2d68(__s);
                      if (iVar2 == -1) {
LAB_300d6be4:
                        if (*DAT_300d76f4 != 0) {
                          logMsg(DAT_300d7b6c,__s,0,0,0,0,0);
                        }
                      }
                      else {
                        iosLock();
                        iVar2 = iosDevReplaceExt(__s,param_1,*DAT_300d75dc);
                        if (iVar2 != -1) {
                          iosDevDelCallback(__s,DAT_300d7a6c);
                          iosUnlock();
                          iVar2 = FUN_300d5b4c(__s);
                          if (iVar2 != -1) {
                            xbdIoctl(param_2,DAT_300d7b70,0);
                            fsPathAddedEventRaise(param_1);
                            return 0;
                          }
                          goto LAB_300d6be4;
                        }
                        *(undefined4 *)((int)__s + 0x20) = 0xffffffff;
                        iosUnlock();
                      }
                      uVar8 = (uint)*(ushort *)((int)__s + 0x7c);
joined_r0x300d6c44:
                      while (uVar8 != 0) {
                        uVar8 = uVar8 - 1;
                        semDelete(*(undefined4 *)(*(int *)((int)__s + 0x44) + uVar8 * 4));
                      }
                      memPartFree(*DAT_300d7600,*(undefined4 *)((int)__s + 0x44));
                    }
                    memPartFree(*DAT_300d7600,*(undefined4 *)((int)__s + 0x40));
                  }
                  memPartFree(*DAT_300d7600,*(undefined4 *)((int)__s + 0x3c));
                }
                semDelete(*(undefined4 *)((int)__s + 0x38));
              }
              semDelete(*(undefined4 *)((int)__s + 0x34));
            }
            semDelete(*(undefined4 *)((int)__s + 0x1d0));
          }
          iVar2 = 0;
          do {
            iVar3 = *(int *)((int)__s + iVar2 * 0x14 + 0x1d4);
            if (iVar3 != 0) {
              memPartFree(*DAT_300d7600,iVar3);
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < 1);
        }
        puVar5 = (undefined4 *)((int)__s + 0x1e4);
        iVar2 = 3;
        do {
          puVar5 = puVar5 + 0xe;
          bio_free(*puVar5);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
LAB_300d6d00:
        puVar5 = (undefined4 *)((int)__s + 0x204);
        iVar2 = 3;
        do {
          puVar5 = puVar5 + 0xe;
          semDelete(*puVar5);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
LAB_300d6d20:
        semDelete(*(undefined4 *)((int)__s + 0x200));
      }
      semDelete(*(undefined4 *)((int)__s + 0x204));
    }
  }
  else {
    errnoSet(iVar2);
  }
  memPartFree(*DAT_300d7600,__s);
LAB_300d6d40:
  if (*DAT_300d76f4 != 0) {
    logMsg(DAT_300d7c7c,0,0,0,0,0,0);
  }
  return 0xffffffff;
}

