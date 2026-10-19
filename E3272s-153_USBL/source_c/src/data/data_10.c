/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 10 (функций: 150, адреса 0x300D6D80..0x300E3900)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * dosFsDevDelete @ 0x300D6D80  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: __errno, errnoSet, intContext, iosDevDelete
 * Вызывают: dosFsMonitorDevCreate
 * Константы: 0xFFFFFFFF, 0x300D6D80
 * Данные: DAT_300d7a58, DAT_300d7c80, DAT_300d7c84
 * ---------------------------------------------------------------- */
undefined4 dosFsDevDelete(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = intContext();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_300d7c80;
    return 0xffffffff;
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) == DAT_300d7a58)) {
    iosDevDelete(param_1);
    return 0;
  }
  errnoSet(DAT_300d7c84);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300d6de0 @ 0x300D6DE0  (примерный размер ~456 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: bio_free, memPartFree, semDelete, semTake
 * Константы: 0x300D6DE0, 0xFFFFFFFF
 * Данные: DAT_300d7600, DAT_300d7c88
 * ---------------------------------------------------------------- */
void FUN_300d6de0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  semTake(*(undefined4 *)(param_1 + 0x34),0xffffffff);
  if (((code *)*DAT_300d7c88 != (code *)0x0) &&
     ((*(int *)(param_1 + 0xc4) != 0 || (*(int *)(param_1 + 0x148) != 0)))) {
    (*(code *)*DAT_300d7c88)(param_1);
  }
  semDelete(*(undefined4 *)(param_1 + 0x1d0));
  piVar2 = (int *)(param_1 + 0x1d4);
  iVar4 = 1;
  do {
    if (*piVar2 != 0) {
      memPartFree(*DAT_300d7600,*piVar2);
    }
    piVar2 = piVar2 + 5;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar5 = 0;
  if (*(short *)(param_1 + 0x7c) != 0) {
    do {
      semDelete(*(undefined4 *)(*(int *)(param_1 + 0x44) + uVar5 * 4));
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(ushort *)(param_1 + 0x7c));
  }
  puVar1 = DAT_300d7600;
  memPartFree(*DAT_300d7600,*(undefined4 *)(param_1 + 0x44));
  memPartFree(*puVar1,*(undefined4 *)(param_1 + 0x40));
  memPartFree(*puVar1,*(undefined4 *)(param_1 + 0x3c));
  semDelete(*(undefined4 *)(param_1 + 0x38));
  puVar3 = (undefined4 *)(param_1 + 0x1e4);
  iVar4 = 3;
  do {
    puVar3 = puVar3 + 0xe;
    bio_free(*puVar3);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar3 = (undefined4 *)(param_1 + 0x204);
  iVar4 = 3;
  do {
    puVar3 = puVar3 + 0xe;
    semDelete(*puVar3);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  semDelete(*(undefined4 *)(param_1 + 0x200));
  semDelete(*(undefined4 *)(param_1 + 0x204));
  if (*(int *)(param_1 + 0x30) != 0) {
    semDelete(*(undefined4 *)(*(int *)(param_1 + 0x30) + 0x84));
    memPartFree(*puVar1,*(undefined4 *)(param_1 + 0x30));
  }
  iVar4 = *(int *)(param_1 + 0x2c);
  if (iVar4 != 0) {
    if (*(int *)(iVar4 + 0x30) != 0) {
      memPartFree(*puVar1,*(int *)(iVar4 + 0x30));
      if (*(int *)(iVar4 + 0x34) != 0) {
        semDelete(*(int *)(iVar4 + 0x34));
      }
    }
    memPartFree(*puVar1,*(undefined4 *)(param_1 + 0x2c));
  }
  semDelete(*(undefined4 *)(param_1 + 0x34));
  memPartFree(*puVar1,param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d6fa8 @ 0x300D6FA8  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: erfHandlerUnregister, iosDevDelete, iosDevSuspend
 * Константы: 0x300D6FA8
 * Данные: DAT_300d7ec4, DAT_300d7ec8, DAT_300d7ecc, DAT_300d7ed0
 * ---------------------------------------------------------------- */
void FUN_300d6fa8(uint param_1,uint param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  uVar1 = DAT_300d7ed0;
  if (param_1 != *DAT_300d7ec4) {
    return;
  }
  if ((param_2 != *DAT_300d7ec8) && (*DAT_300d7ecc != param_2)) {
    return;
  }
  if (*(int *)(param_4 + 0x28) != param_3) {
    return;
  }
  erfHandlerUnregister((uint)*DAT_300d7ec4,(uint)*DAT_300d7ec8,DAT_300d7ed0,param_4);
  erfHandlerUnregister(*DAT_300d7ec4,*DAT_300d7ecc,uVar1,param_4);
  if (*DAT_300d7ec8 == param_2) {
    iosDevDelete();
  }
  else {
    iosDevSuspend(param_4);
  }
  return;
}

/* ----------------------------------------------------------------
 * dosFsMonitorDevCreate @ 0x300D7050  (примерный размер ~316 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: close, dosFsDevCreate, dosFsDevDelete, dosFsVolDescGet, erfHandlerRegister, open
 * Константы: 0xFFFFFFFF, 0x300D7050
 * Данные: DAT_300d75fc, DAT_300d7ec4, DAT_300d7ec8, DAT_300d7ecc, DAT_300d7ed0, DAT_300d7ffc, DAT_300d8000, DAT_300d8004
 * ---------------------------------------------------------------- */
undefined4 dosFsMonitorDevCreate(undefined4 param_1,char *param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int __fd;
  
  iVar2 = dosFsDevCreate(param_2,param_1,*DAT_300d75fc,DAT_300d75fc[1]);
  if (iVar2 == 0) {
    if (((code *)*DAT_300d7ffc != (code *)0x0) && ((*DAT_300d8000 != 0 || (*DAT_300d8004 != 0)))) {
      (*(code *)*DAT_300d7ffc)(param_2,0,*DAT_300d8000,0,*DAT_300d8004);
    }
    iVar2 = dosFsVolDescGet(param_2,0);
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      __fd = open(param_2,0,DAT_300d8008);
      if (__fd < 0) {
        dosFsDevDelete(iVar2);
        uVar3 = 0xffffffff;
      }
      else {
        close(__fd);
        uVar3 = DAT_300d7ed0;
        puVar1 = DAT_300d7ec4;
        erfHandlerRegister(*DAT_300d7ec4,*DAT_300d7ec8,DAT_300d7ed0,iVar2,0);
        erfHandlerRegister(*puVar1,*DAT_300d7ecc,uVar3,iVar2,0);
        uVar3 = 0;
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * dosFsDiskProbe @ 0x300D718C  (примерный размер ~316 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: bio_alloc, bio_free, bzero, semBCreate, semDelete, semTake, xbdBlockSize, xbdStrategy
 * Константы: 0xFFFFFFFF, 0x300D718C
 * Данные: DAT_300d812c
 * ---------------------------------------------------------------- */
byte * dosFsDiskProbe(undefined4 param_1)

{
  byte *pbVar1;
  bool bVar2;
  int local_44 [2];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  byte *local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_18;
  int local_14;
  
  pbVar1 = (byte *)xbdBlockSize(param_1,local_44);
  if (pbVar1 != (byte *)0x0) {
    return pbVar1;
  }
  bzero(&local_3c,0x30);
  local_2c = (byte *)bio_alloc(param_1,1);
  if (local_2c == (byte *)0x0) {
    return (byte *)0xffffffff;
  }
  local_14 = semBCreate(1,0);
  if (local_14 == 0) {
    bio_free(local_2c);
    return (byte *)0xffffffff;
  }
  local_38 = 0;
  local_34 = 0;
  local_30 = local_44[0];
  local_24 = 0;
  local_20 = 1;
  local_18 = DAT_300d812c;
  local_3c = param_1;
  xbdStrategy(param_1,&local_3c);
  semTake(local_14,0xffffffff);
  bVar2 = local_28 == 0;
  pbVar1 = (byte *)0x0;
  if (((bVar2) && (bVar2 = local_24 == 0, bVar2)) &&
     ((pbVar1 = (byte *)(uint)*local_2c, pbVar1 == (byte *)0xe9 ||
      (bVar2 = pbVar1 == (byte *)0xeb, bVar2)))) {
    pbVar1 = local_2c + local_44[0];
    if ((pbVar1[-2] == 0x55) && (bVar2 = pbVar1[-1] == 0xaa, bVar2)) goto LAB_300d72a8;
    bVar2 = local_2c[0x1fe] == 0x55;
    if (bVar2) {
      bVar2 = local_2c[0x1ff] == 0xaa;
    }
  }
  if (!bVar2) {
    pbVar1 = (byte *)0xffffffff;
  }
LAB_300d72a8:
  if (bVar2) {
    pbVar1 = (byte *)0x0;
  }
  bio_free(local_2c);
  semDelete(local_14);
  return pbVar1;
}

/* ----------------------------------------------------------------
 * dosFsHdlrInstall @ 0x300D72C8  (примерный размер ~388 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: dosFsFatInit, dosVDirLibInit
 * Константы: 0x300D72C8
 * Данные: DAT_300d76f4, DAT_300d8208, DAT_300d820c, DAT_300d8210, DAT_300d8214, DAT_300d8364
 * ---------------------------------------------------------------- */
int dosFsHdlrInstall(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_20;
  uint local_1c;
  uint local_18;
  
  iVar3 = -1;
  if (param_2 == (uint *)0x0) {
    if (*DAT_300d76f4 != 0) {
      logMsg(DAT_300d8208,0,0,0,0,0,0);
    }
    iVar3 = -1;
  }
  else if ((DAT_300d820c == param_1) || (DAT_300d8210 == param_1)) {
    local_20 = *param_2;
    iVar2 = 4;
    local_1c = param_2[1];
    local_18 = param_2[2];
    do {
      uVar1 = *param_1;
      if ((uVar1 == 0) || (local_20 < uVar1)) {
        uVar4 = param_1[1];
        iVar3 = 0;
        uVar5 = param_1[2];
        *param_1 = local_20;
        param_1[1] = local_1c;
        param_1[2] = local_18;
        local_20 = uVar1;
        local_1c = uVar4;
        local_18 = uVar5;
      }
      param_1 = param_1 + 3;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if ((iVar3 == -1) && (*DAT_300d76f4 != 0)) {
      logMsg(DAT_300d8364,0,0,0,0,0,0);
    }
  }
  else {
    if (*DAT_300d76f4 != 0) {
      logMsg(DAT_300d8214,0,0,0,0,0,0);
    }
    iVar3 = -1;
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * dosFsXbdBlkRead @ 0x300D744C  (примерный размер ~1020 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 9
 * Вызывает: FUN_300d1f18, FUN_300d1ff0, FUN_300d204c, FUN_300d20d4, __errno, bcopy, errnoSet, semGive, semTake
 * Вызывают: FUN_300cd79c
 * Константы: 0xFFFFFFFF, 0x300D744C
 * Данные: DAT_300d7894, DAT_300d7c84
 * ---------------------------------------------------------------- */
undefined4
dosFsXbdBlkRead(int param_1,uint param_2,int param_3,uint param_4,uint param_5,void *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  size_t __n;
  undefined4 uVar6;
  bool bVar7;
  undefined8 uVar8;
  undefined4 local_4c;
  uint local_8;
  uint local_4;
  
  local_4 = param_5;
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300d7c84;
    return 0xffffffff;
  }
  if (param_5 == 0) {
LAB_300d74b0:
    if (param_5 == 0 && param_4 == 0) {
      return 0;
    }
  }
  else {
    if ((int)param_5 < 1) {
      return 0;
    }
    if ((int)param_5 < 1) goto LAB_300d74b0;
  }
  uVar3 = *(uint *)(param_1 + 500) - param_2;
  uVar4 = *(int *)(param_1 + 0x1f8) - (param_3 + (uint)(*(uint *)(param_1 + 500) < param_2));
  bVar7 = param_5 <= uVar4;
  if (uVar4 == param_5) {
LAB_300d7504:
    if (uVar4 == param_5) {
      bVar7 = param_4 <= uVar3;
    }
    if (!bVar7) {
LAB_300d750c:
      puVar1 = (undefined4 *)__errno();
      *puVar1 = 0x16;
      return 0xffffffff;
    }
  }
  else {
    if ((int)uVar4 < (int)param_5) goto LAB_300d750c;
    if ((int)uVar4 < (int)param_5) goto LAB_300d7504;
  }
  iVar2 = semTake(*(undefined4 *)(param_1 + 0x1d0),0xffffffff,uVar3,uVar4);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 0x1ec) = *(int *)(param_1 + 0x1ec) + 1;
  iVar5 = 1;
  iVar2 = param_1;
  do {
    uVar3 = *(uint *)(iVar2 + 0x1dc);
    uVar4 = *(int *)(iVar2 + 0x1e0) - (param_3 + (uint)(uVar3 < param_2));
    bVar7 = param_5 <= uVar4;
    if (uVar4 == param_5) {
      bVar7 = param_4 <= uVar3 - param_2;
    }
    uVar4 = param_5;
    if (!bVar7) {
      uVar4 = 0;
      if (param_5 == 0 && param_4 == 1) {
        bcopy(*(void **)(iVar2 + 0x1d4),param_6,*(size_t *)(param_1 + 0x1fc));
        *(int *)(param_1 + 0x1f0) = *(int *)(param_1 + 0x1f0) + 1;
        semGive(*(undefined4 *)(param_1 + 0x1d0));
        return 0;
      }
      if (*(int *)(iVar2 + 0x1e4) != 0) {
        uVar8 = FUN_300d20d4(param_1,uVar3,*(int *)(iVar2 + 0x1e0),*(undefined4 *)(iVar2 + 0x1d4),1)
        ;
        uVar4 = (uint)((ulonglong)uVar8 >> 0x20);
        if ((int)uVar8 != 0) {
          semGive(*(undefined4 *)(param_1 + 0x1d0));
          return 0xffffffff;
        }
        *(undefined4 *)(iVar2 + 0x1e4) = 0;
      }
    }
    local_4c = 0;
    iVar2 = iVar2 + 0x14;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  semGive(*(undefined4 *)(param_1 + 0x1d0),uVar4);
  iVar2 = FUN_300d1f18(param_1);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0x1cc) & 1) != 0) {
    uVar6 = *(undefined4 *)(iVar2 + 0x10);
    *(void **)(iVar2 + 0x10) = param_6;
    iVar5 = FUN_300d204c(param_1,iVar2,param_2,param_3,*(int *)(param_1 + 0x1fc) * param_4,1);
    if (iVar5 != 0) {
      if (iVar5 != -1) {
        errnoSet(iVar5);
      }
      local_4c = 0xffffffff;
    }
    *(undefined4 *)(iVar2 + 0x10) = uVar6;
    goto LAB_300d7828;
  }
  uVar3 = 0;
  local_8 = param_4;
  if (param_5 == 0) {
LAB_300d771c:
    if (param_5 == 0 && param_4 == 0) goto LAB_300d7828;
  }
  else if ((int)param_5 < 1) {
    if ((int)param_5 < 1) goto LAB_300d7828;
    goto LAB_300d771c;
  }
LAB_300d7724:
  do {
    uVar4 = *DAT_300d7894;
    bVar7 = local_4 == 0;
    if (local_4 == 0) {
LAB_300d7750:
      if (local_4 == 0) {
        bVar7 = local_8 <= uVar4;
      }
      if (bVar7) {
LAB_300d7758:
        uVar4 = local_8;
      }
    }
    else {
      if ((int)local_4 < 1) goto LAB_300d7758;
      if ((int)local_4 < 1) goto LAB_300d7750;
    }
    __n = *(int *)(param_1 + 0x1fc) * uVar4;
    iVar5 = FUN_300d204c(param_1,iVar2,param_2 + uVar3,param_3 + (uint)CARRY4(param_2,uVar3),__n,1);
    if (iVar5 != 0) {
      if (iVar5 != -1) {
        errnoSet();
      }
      local_4c = 0xffffffff;
      break;
    }
    bcopy(*(void **)(iVar2 + 0x10),param_6,__n);
    bVar7 = local_8 < uVar4;
    local_8 = local_8 - uVar4;
    local_4 = local_4 - bVar7;
    param_6 = (void *)((int)param_6 + __n);
    uVar3 = uVar3 + uVar4;
    if (local_4 != 0) {
      if ((int)local_4 < 1) break;
      if (0 < (int)local_4) goto LAB_300d7724;
    }
  } while (local_4 != 0 || local_8 != 0);
LAB_300d7828:
  FUN_300d1ff0(param_1,iVar2);
  return local_4c;
}

/* ----------------------------------------------------------------
 * dosFsXbdBlkWrite @ 0x300D7848  (примерный размер ~992 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 9
 * Вызывает: FUN_300d1f18, FUN_300d1ff0, FUN_300d204c, __errno, bcopy, errnoSet, semGive, semTake, xbdIoctl
 * Вызывают: FUN_300cd2a8, FUN_300cdb24
 * Константы: 0xFFFFFFFF, 0x300D7848
 * Данные: DAT_300d7c84, DAT_300d83a8, DAT_300d83ac
 * ---------------------------------------------------------------- */
int dosFsXbdBlkWrite(int param_1,uint param_2,int param_3,uint param_4,uint param_5,void *param_6,
                    int param_7)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  size_t __n;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  undefined8 uVar8;
  int local_4c;
  int local_48;
  uint local_8;
  uint local_4;
  
  local_4 = param_5;
  local_4c = 0;
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300d7c84;
    return -1;
  }
  if (param_5 == 0) {
LAB_300d78b0:
    if (param_5 == 0 && param_4 == 0) {
      return 0;
    }
  }
  else {
    if ((int)param_5 < 1) {
      return 0;
    }
    if ((int)param_5 < 1) goto LAB_300d78b0;
  }
  uVar3 = *(uint *)(param_1 + 500) - param_2;
  uVar4 = *(int *)(param_1 + 0x1f8) - (param_3 + (uint)(*(uint *)(param_1 + 500) < param_2));
  bVar7 = param_5 <= uVar4;
  if (uVar4 == param_5) {
LAB_300d7904:
    if (uVar4 == param_5) {
      bVar7 = param_4 <= uVar3;
    }
    if (!bVar7) {
LAB_300d790c:
      puVar1 = (undefined4 *)__errno();
      *puVar1 = 0x16;
      return -1;
    }
  }
  else {
    if ((int)uVar4 < (int)param_5) goto LAB_300d790c;
    if ((int)uVar4 < (int)param_5) goto LAB_300d7904;
  }
  uVar8 = semTake(*(undefined4 *)(param_1 + 0x1d0),0xffffffff,uVar3,uVar4);
  uVar3 = (uint)((ulonglong)uVar8 >> 0x20);
  if ((int)uVar8 != 0) {
    return -1;
  }
  *(int *)(param_1 + 0x1ec) = *(int *)(param_1 + 0x1ec) + 1;
  local_48 = 1;
  iVar5 = param_1;
  do {
    if (*(int *)(iVar5 + 0x1d4) != 0) {
      uVar3 = *(uint *)(iVar5 + 0x1e0);
      uVar4 = *(uint *)(iVar5 + 0x1dc);
      if (uVar3 != 0xffffffff || uVar4 != 0xffffffff) {
        uVar3 = uVar3 - (param_3 + (uint)(uVar4 < param_2));
        bVar7 = param_5 <= uVar3;
        if (uVar3 == param_5) {
          bVar7 = param_4 <= uVar4 - param_2;
        }
        if (!bVar7) {
          *(undefined4 *)(iVar5 + 0x1dc) = 0xffffffff;
          *(undefined4 *)(iVar5 + 0x1e0) = 0xffffffff;
          *(undefined4 *)(iVar5 + 0x1e4) = 0;
        }
      }
    }
    iVar5 = iVar5 + 0x14;
    local_48 = local_48 + -1;
  } while (local_48 != 0);
  semGive(*(undefined4 *)(param_1 + 0x1d0),uVar3);
  iVar5 = FUN_300d1f18(param_1);
  if (iVar5 == 0) {
    return -1;
  }
  if ((*(uint *)(param_1 + 0x1cc) & 1) != 0) {
    uVar6 = *(undefined4 *)(iVar5 + 0x10);
    *(void **)(iVar5 + 0x10) = param_6;
    iVar2 = FUN_300d204c(param_1,iVar5,param_2,param_3,*(int *)(param_1 + 0x1fc) * param_4,2);
    *(undefined4 *)(iVar5 + 0x10) = uVar6;
    if (iVar2 != 0) {
joined_r0x300d7b58:
      if (iVar2 != -1) {
        errnoSet();
      }
      local_4c = -1;
    }
    goto LAB_300d7bc8;
  }
  uVar3 = 0;
  local_8 = param_4;
  if (param_5 == 0) {
LAB_300d7ac0:
    if (param_5 == 0 && param_4 == 0) goto LAB_300d7bc8;
  }
  else if ((int)param_5 < 1) {
    if ((int)param_5 < 1) goto LAB_300d7bc8;
    goto LAB_300d7ac0;
  }
LAB_300d7ac8:
  do {
    uVar4 = *DAT_300d83a8;
    bVar7 = local_4 == 0;
    if (local_4 == 0) {
LAB_300d7af4:
      if (local_4 == 0) {
        bVar7 = local_8 <= uVar4;
      }
      if (bVar7) {
LAB_300d7afc:
        uVar4 = local_8;
      }
    }
    else {
      if ((int)local_4 < 1) goto LAB_300d7afc;
      if ((int)local_4 < 1) goto LAB_300d7af4;
    }
    __n = *(int *)(param_1 + 0x1fc) * uVar4;
    bcopy(param_6,*(void **)(iVar5 + 0x10),__n);
    iVar2 = FUN_300d204c(param_1,iVar5,param_2 + uVar3,param_3 + (uint)CARRY4(param_2,uVar3),__n,2);
    if (iVar2 != 0) goto joined_r0x300d7b58;
    bVar7 = local_8 < uVar4;
    local_8 = local_8 - uVar4;
    local_4 = local_4 - bVar7;
    uVar3 = uVar3 + uVar4;
    param_6 = (void *)((int)param_6 + __n);
    if (local_4 != 0) {
      if ((int)local_4 < 1) break;
      if (0 < (int)local_4) goto LAB_300d7ac8;
    }
  } while (local_4 != 0 || local_8 != 0);
LAB_300d7bc8:
  FUN_300d1ff0(param_1,iVar5);
  if (local_4c != 0) {
    return local_4c;
  }
  if (param_7 == 2) {
    puVar1 = (undefined4 *)__errno();
    uVar6 = *puVar1;
    xbdIoctl(*(undefined4 *)(param_1 + 0x28),DAT_300d83ac,0);
    puVar1 = (undefined4 *)__errno();
    *puVar1 = uVar6;
    return 0;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * dosFsXbdBlkCopy @ 0x300D7C28  (примерный размер ~864 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_300d1f18, FUN_300d1ff0, FUN_300d204c, FUN_300d20d4, __errno, errnoSet, semGive, semTake
 * Вызывают: FUN_300ce044
 * Константы: 0xFFFFFFFF, 0x300D7C28
 * Данные: DAT_300d83a8
 * ---------------------------------------------------------------- */
undefined4
dosFsXbdBlkCopy(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
               uint param_7)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  ulonglong uVar10;
  int local_54;
  uint local_50;
  undefined4 local_4c;
  
  if (param_7 == 0) {
LAB_300d7c6c:
    if (param_7 == 0 && param_6 == 0) {
      return 0;
    }
  }
  else {
    if ((int)param_7 < 1) {
      return 0;
    }
    if ((int)param_7 < 1) goto LAB_300d7c6c;
  }
  uVar5 = *(uint *)(param_1 + 500) - param_6;
  iVar6 = param_7 + (*(uint *)(param_1 + 500) < param_6);
  uVar3 = *(int *)(param_1 + 0x1f8) - iVar6;
  if (((*(int *)(param_1 + 0x1f8) != iVar6) && ((int)uVar3 < 0)) && ((int)uVar3 < 0))
  goto LAB_300d7cfc;
  bVar9 = uVar3 <= param_3;
  bVar8 = param_3 == uVar3;
  if (bVar8) {
LAB_300d7cd4:
    if (bVar8) {
      bVar9 = uVar5 <= param_2;
    }
    if (bVar9 && (!bVar8 || param_2 != uVar5)) goto LAB_300d7cfc;
  }
  else if ((int)uVar3 < (int)param_3) {
    if (!bVar8 && (int)uVar3 <= (int)param_3) goto LAB_300d7cfc;
    goto LAB_300d7cd4;
  }
  bVar9 = uVar3 <= param_5;
  bVar8 = param_5 == uVar3;
  if (bVar8) {
LAB_300d7cf4:
    if (bVar8) {
      bVar9 = uVar5 <= param_4;
    }
    if (bVar9 && (!bVar8 || param_4 != uVar5)) {
LAB_300d7cfc:
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 0x16;
      return 0xffffffff;
    }
  }
  else {
    if ((int)uVar3 < (int)param_5) goto LAB_300d7cfc;
    if ((int)uVar3 < (int)param_5) goto LAB_300d7cf4;
  }
  uVar10 = semTake(*(undefined4 *)(param_1 + 0x1d0),0xffffffff);
  uVar1 = uVar10 & 0xffffffff00000000;
  if ((int)uVar10 != 0) {
    return 0xffffffff;
  }
  local_54 = 1;
  iVar6 = param_1;
  do {
    local_4c = (undefined4)uVar1;
    if (*(int *)(iVar6 + 0x1d4) != 0) {
      iVar4 = *(int *)(iVar6 + 0x1e0);
      uVar3 = *(uint *)(iVar6 + 0x1dc);
      uVar1 = CONCAT44(0xffffffff,local_4c);
      if (iVar4 != -1 || uVar3 != 0xffffffff) {
        uVar5 = iVar4 - (param_3 + (uVar3 < param_2));
        uVar1 = CONCAT44(uVar5,local_4c);
        uVar10 = CONCAT44(uVar5,local_4c);
        bVar9 = param_7 <= uVar5;
        if (uVar5 == param_7) {
          bVar9 = param_6 <= uVar3 - param_2;
        }
        if ((bVar9) || (*(int *)(iVar6 + 0x1e4) == 0)) {
          uVar5 = iVar4 - (param_5 + (uVar3 < param_4));
          bVar9 = param_7 <= uVar5;
          if (uVar5 == param_7) {
            bVar9 = param_6 <= uVar3 - param_4;
          }
          if (bVar9) goto LAB_300d7dfc;
          *(undefined4 *)(iVar6 + 0x1dc) = 0xffffffff;
          *(undefined4 *)(iVar6 + 0x1e0) = 0xffffffff;
        }
        else {
          uVar10 = FUN_300d20d4(param_1,uVar3,iVar4,*(int *)(iVar6 + 0x1d4),1);
          if ((int)uVar10 == -1) {
            semGive(*(undefined4 *)(param_1 + 0x1d0));
            return 0xffffffff;
          }
        }
        *(undefined4 *)(iVar6 + 0x1e4) = 0;
        uVar1 = uVar10;
      }
    }
LAB_300d7dfc:
    local_4c = (undefined4)uVar1;
    iVar6 = iVar6 + 0x14;
    local_54 = local_54 + -1;
  } while (local_54 != 0);
  iVar6 = FUN_300d1f18(param_1,(int)(uVar1 >> 0x20));
  if (iVar6 == 0) {
    return 0xffffffff;
  }
  uVar3 = 0;
  if (param_7 == 0) {
LAB_300d7e40:
    if (param_7 == 0 && param_6 == 0) goto LAB_300d7f60;
  }
  else if ((int)param_7 < 1) {
    if ((int)param_7 < 1) goto LAB_300d7f60;
    goto LAB_300d7e40;
  }
LAB_300d7e48:
  do {
    local_50 = *DAT_300d83a8;
    bVar9 = param_7 == 0;
    if (param_7 == 0) {
LAB_300d7e68:
      if (param_7 == 0) {
        bVar9 = param_6 <= local_50;
      }
      if (bVar9) {
LAB_300d7e70:
        local_50 = param_6;
      }
    }
    else {
      if ((int)param_7 < 1) goto LAB_300d7e70;
      if ((int)param_7 < 1) goto LAB_300d7e68;
    }
    iVar7 = *(int *)(param_1 + 0x1fc) * local_50;
    iVar4 = FUN_300d204c(param_1,iVar6,param_2 + uVar3,param_3 + CARRY4(param_2,uVar3),iVar7,1);
    if ((iVar4 != 0) ||
       (iVar4 = FUN_300d204c(param_1,iVar6,param_4 + uVar3,param_5 + CARRY4(param_4,uVar3),iVar7,2),
       iVar4 != 0)) {
      if (iVar4 != -1) {
        errnoSet();
      }
      local_4c = 0xffffffff;
      break;
    }
    bVar9 = param_6 < local_50;
    param_6 = param_6 - local_50;
    param_7 = param_7 - bVar9;
    uVar3 = uVar3 + local_50;
    if (param_7 != 0) {
      if ((int)param_7 < 1) break;
      if (0 < (int)param_7) goto LAB_300d7e48;
    }
  } while (param_7 != 0 || param_6 != 0);
LAB_300d7f60:
  semGive(*(undefined4 *)(param_1 + 0x1d0));
  FUN_300d1ff0(param_1,iVar6);
  return local_4c;
}

/* ----------------------------------------------------------------
 * FUN_300d7f88 @ 0x300D7F88  (примерный размер ~264 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: xbdIoctl
 * Вызывают: dosFsXbdIoctl
 * Константы: 0xFFFFFFFF, 0x300D7F88
 * ---------------------------------------------------------------- */
int FUN_300d7f88(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  iVar5 = 1;
  iVar6 = param_1;
  do {
    if (*(int *)(iVar6 + 0x1d4) != 0) {
      uVar4 = *(uint *)(iVar6 + 0x1e0);
      bVar7 = uVar2 <= uVar4;
      if (uVar4 == uVar2) {
LAB_300d7fe8:
        if (uVar4 == uVar2) {
          bVar7 = uVar1 <= *(uint *)(iVar6 + 0x1dc);
        }
        if (!bVar7) goto LAB_300d8050;
      }
      else if ((int)uVar4 < (int)uVar2) {
        if ((int)uVar4 < (int)uVar2) goto LAB_300d8050;
        goto LAB_300d7fe8;
      }
      uVar3 = uVar2 + CARRY4(uVar1,param_2[2]);
      bVar7 = uVar3 <= uVar4;
      if (uVar4 == uVar3) {
LAB_300d8030:
        if (uVar4 == uVar3) {
          bVar7 = uVar1 + param_2[2] <= *(uint *)(iVar6 + 0x1dc);
        }
        if (bVar7) goto LAB_300d8050;
      }
      else if ((int)uVar3 <= (int)uVar4) {
        if ((int)uVar3 <= (int)uVar4) goto LAB_300d8050;
        goto LAB_300d8030;
      }
      *(undefined4 *)(iVar6 + 0x1dc) = 0xffffffff;
      *(undefined4 *)(iVar6 + 0x1e0) = 0xffffffff;
      *(undefined4 *)(iVar6 + 0x1e4) = 0;
    }
LAB_300d8050:
    iVar6 = iVar6 + 0x14;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      bVar7 = *(int *)(param_1 + 0xa4) == 0;
      if (!bVar7) {
        iVar6 = xbdIoctl(*(undefined4 *)(param_1 + 0x28),0x47,param_2);
        bVar7 = iVar6 == 0x23;
      }
      if (bVar7) {
        iVar6 = 0;
      }
      return iVar6;
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * dosFsXbdIoctl @ 0x300D8090  (примерный размер ~812 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 7
 * Вызывает: FUN_300d20d4, FUN_300d7f88, bzero, errnoSet, semGive, semTake, xbdIoctl
 * Вызывают: FUN_300cbc28, FUN_300cbe88, FUN_300ceaec, dosFsCacheCreate
 * Константы: 0xFFFFFFFF, 0x300D8090
 * Данные: DAT_300d83b0, DAT_300d83b4, DAT_300d83b8
 * ---------------------------------------------------------------- */
int dosFsXbdIoctl(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (param_2 == DAT_300d83b0) {
LAB_300d80e8:
    iVar3 = semTake(*(undefined4 *)(param_1 + 0x1d0),0xffffffff);
    if (iVar3 == -1) {
      return -1;
    }
  }
  else if (param_2 == DAT_300d83b0 || param_2 < DAT_300d83b0) {
    if ((param_2 == DAT_300d83b4) || (param_2 == DAT_300d83b8)) goto LAB_300d80e8;
  }
  else if ((param_2 == 0x38) || (param_2 == 0x47)) goto LAB_300d80e8;
  if (param_2 == DAT_300d83b0) {
    if (*(int *)(param_1 + 0x1d4) != 0) {
      if (((*(int *)(param_1 + 0x1e0) != -1 || *(int *)(param_1 + 0x1dc) != -1) &&
          ((*(int *)(param_1 + 0x1e4) >> 0x1f) + *(int *)(param_1 + 0x1e4) != 0)) &&
         (iVar2 = FUN_300d20d4(param_1,*(int *)(param_1 + 0x1dc),*(int *)(param_1 + 0x1e0),
                               *(int *)(param_1 + 0x1d4),1), iVar2 == -1)) goto LAB_300d8394;
    }
    if (*(void **)(param_1 + 0x1d4) != (void *)0x0) {
      bzero(*(void **)(param_1 + 0x1d4),*(size_t *)(param_1 + 0x1d8));
      *(undefined4 *)(param_1 + 0x1dc) = param_3;
      *(undefined4 *)(param_1 + 0x1e0) = 0;
      *(undefined4 *)(param_1 + 0x1e4) = 1;
    }
    goto LAB_300d8394;
  }
  if (param_2 == DAT_300d83b0 || param_2 < DAT_300d83b0) {
    if (param_2 != DAT_300d83b4) {
      if (param_2 == DAT_300d83b8) {
        iVar1 = 1;
        iVar3 = param_1;
        do {
          if (((*(int *)(iVar3 + 0x1d4) != 0) &&
              (*(int *)(iVar3 + 0x1e0) != -1 || *(int *)(iVar3 + 0x1dc) != -1)) &&
             (((*(int *)(iVar3 + 0x1e4) >> 0x1f) + *(int *)(iVar3 + 0x1e4) != 0 &&
              (iVar2 = FUN_300d20d4(param_1,*(undefined4 *)(iVar3 + 0x1dc),
                                    *(undefined4 *)(iVar3 + 0x1e0),*(int *)(iVar3 + 0x1d4),1),
              iVar2 == -1)))) break;
          *(undefined4 *)(iVar3 + 0x1dc) = 0xffffffff;
          *(undefined4 *)(iVar3 + 0x1e0) = 0xffffffff;
          *(undefined4 *)(iVar3 + 0x1e4) = 0;
          iVar1 = iVar1 + -1;
          iVar3 = iVar3 + 0x14;
        } while (iVar1 != 0);
        goto LAB_300d8394;
      }
LAB_300d8368:
      iVar2 = xbdIoctl(*(undefined4 *)(param_1 + 0x28),param_2,param_3);
      if (iVar2 == 0) {
        return 0;
      }
      errnoSet(iVar2);
      return -1;
    }
LAB_300d8150:
    iVar1 = 1;
    iVar3 = param_1;
    do {
      if (*(int *)(iVar3 + 0x1d4) != 0) {
        if (((*(int *)(iVar3 + 0x1e0) != -1 || *(int *)(iVar3 + 0x1dc) != -1) &&
            ((*(int *)(iVar3 + 0x1e4) >> 0x1f) + *(int *)(iVar3 + 0x1e4) != 0)) &&
           (iVar2 = FUN_300d20d4(param_1,*(int *)(iVar3 + 0x1dc),*(int *)(iVar3 + 0x1e0),
                                 *(int *)(iVar3 + 0x1d4),1), iVar2 == 0)) {
          *(undefined4 *)(iVar3 + 0x1e4) = 0;
        }
      }
      iVar3 = iVar3 + 0x14;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (param_2 != 0x38) goto LAB_300d8394;
    iVar2 = xbdIoctl(*(undefined4 *)(param_1 + 0x28),0x38,param_3);
  }
  else {
    if (param_2 == 0x38) goto LAB_300d8150;
    if (param_2 != 0x47) goto LAB_300d8368;
    iVar2 = FUN_300d7f88(param_1,param_3);
  }
  if ((iVar2 == 0) || (iVar2 == 0x23)) {
    iVar2 = 0;
  }
  else {
    errnoSet(iVar2);
    iVar2 = -1;
  }
LAB_300d8394:
  semGive(*(undefined4 *)(param_1 + 0x1d0));
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300d83bc @ 0x300D83BC  (примерный размер ~428 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 3
 * Вызывает: bzero, dosfsDiskToHost16, dosfsDiskToHost32
 * Вызывают: FUN_300d9f14, FUN_300da31c, FUN_300da684, FUN_300dada0, FUN_300daffc, dosVDirReaddirPlus
 * Константы: 0xFFFFFFFF, 0x300D83BC
 * ---------------------------------------------------------------- */
void FUN_300d83bc(int *param_1,int param_2,undefined4 *param_3)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar6 = param_1[1];
  iVar5 = *(int *)(*param_1 + 0x2c);
  bzero((undefined4 *)(iVar6 + 0x14),0x2c);
  if (param_2 == 0) {
    iVar4 = param_1[1];
    *(undefined4 *)(iVar4 + 0x14) = 0xffffffff;
    *(undefined4 *)(iVar6 + 0x18) = 0xffffffff;
    *(undefined4 *)(iVar6 + 0x1c) = 0xffffffff;
    param_1[6] = *(int *)(iVar5 + 0x28);
    param_1[9] = *(int *)(iVar5 + 0x2c);
    param_1[7] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    *(undefined1 *)(iVar4 + 0x42) = 0x10;
    *(undefined4 *)(param_1[1] + 0xc) = *(undefined4 *)(iVar5 + 0x4c);
    param_1[10] = 0;
  }
  else {
    iVar4 = param_1[1];
    *(undefined4 *)(iVar6 + 0x14) = *(undefined4 *)(iVar4 + 0xc);
    *(int *)(iVar6 + 0x18) = param_1[6];
    *(int *)(iVar6 + 0x1c) = param_1[2];
    *(int *)(iVar6 + 0x28) = param_1[10];
    if (param_3 != (undefined4 *)0x0) {
      *(undefined4 *)(iVar6 + 0x20) = *param_3;
      *(undefined4 *)(iVar6 + 0x24) = param_3[1];
    }
    param_1[10] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[9] = 0;
    *(undefined1 *)(iVar4 + 0x42) = *(undefined1 *)(param_2 + (uint)*(byte *)(iVar5 + 0x3f));
    if (*(int *)(*param_1 + 0x74) == 2) {
      iVar6 = dosfsDiskToHost16(param_2 + (uint)*(byte *)(iVar5 + 0x47));
      iVar6 = iVar6 << 0x10;
    }
    else {
      iVar6 = 0;
    }
    uVar2 = dosfsDiskToHost16(param_2 + (uint)*(byte *)(iVar5 + 0x46));
    *(uint *)(param_1[1] + 0xc) = (uVar2 & 0xffff) + iVar6;
    uVar3 = dosfsDiskToHost32(param_2 + (uint)*(byte *)(iVar5 + 0x48));
    puVar7 = (undefined4 *)param_1[1];
    *puVar7 = uVar3;
    puVar7[1] = 0;
    if (*(byte *)(iVar5 + 0x49) != 0xff) {
      uVar2 = dosfsDiskToHost32(param_2 + (uint)*(byte *)(iVar5 + 0x49));
      bVar1 = *(byte *)(iVar5 + 0x4a);
      *puVar7 = uVar3;
      puVar7[1] = uVar2 & ~(-1 << ((bVar1 & 0x1f) << 3));
    }
  }
  bzero(param_1 + 0xc,0x10);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d8568 @ 0x300D8568  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300d961c, FUN_300da31c
 * Константы: 0x300D8568, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void FUN_300d8568(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*param_1 + 0x2c);
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[9] = 0;
  param_1[6] = 0;
  if ((*(int *)(param_1[1] + 0x14) == -1) && (iVar2 = *(int *)(iVar1 + 0x2c), iVar2 != 0)) {
    param_1[6] = *(int *)(iVar1 + 0x28);
    param_1[9] = iVar2;
  }
  else {
    (**(code **)(*(int *)(*param_1 + 0x30) + 0xc))(param_1,0xffffffff,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d85d4 @ 0x300D85D4  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300d9028, FUN_300d91ec
 * Константы: 0x300D85D4
 * ---------------------------------------------------------------- */
uint FUN_300d85d4(int param_1)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  uVar3 = 0;
  pbVar2 = (byte *)(param_1 + -1);
  iVar1 = 0xb;
  do {
    pbVar2 = pbVar2 + 1;
    iVar1 = iVar1 + -1;
    uVar3 = ((uVar3 & 0xff) >> 1 | (uVar3 & 1) << 7) + (uint)*pbVar2;
  } while (iVar1 != 0);
  return uVar3 & 0xff;
}

/* ----------------------------------------------------------------
 * FUN_300d8610 @ 0x300D8610  (примерный размер ~256 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: dosfsDiskToHost16, mktime
 * Вызывают: FUN_300daf70, dosVDirReaddirPlus
 * Константы: 0x300D8610
 * Данные: DAT_300d95e8
 * ---------------------------------------------------------------- */
void FUN_300d8610(int param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  int local_34 [4];
  int local_24;
  int local_20;
  
  iVar3 = 9;
  piVar4 = local_34;
  puVar5 = DAT_300d95e8;
  do {
    iVar3 = iVar3 + -1;
    *piVar4 = *puVar5;
    piVar4 = piVar4 + 1;
    puVar5 = puVar5 + 1;
  } while (iVar3 != 0);
  uVar6 = 0;
  uVar2 = 0;
  if (param_3 == 1) {
    bVar1 = *(byte *)(param_1 + 0x40);
    iVar3 = 0x41;
  }
  else {
    if (param_3 == 2) {
      uVar6 = (uint)*(byte *)(param_1 + 0x42);
      uVar2 = (uint)*(byte *)(param_1 + 0x43);
      goto LAB_300d8684;
    }
    if (param_3 != 4) goto LAB_300d8684;
    bVar1 = *(byte *)(param_1 + 0x44);
    iVar3 = 0x45;
  }
  uVar6 = (uint)bVar1;
  uVar2 = (uint)*(byte *)(param_1 + iVar3);
LAB_300d8684:
  if (uVar2 != 0xff) {
    uVar2 = dosfsDiskToHost16(param_2 + uVar2);
    local_34[3] = uVar2 & 0x1f;
    local_24 = ((int)(uVar2 & 0xffff) >> 5 & 0xfU) - 1;
    local_20 = ((int)(uVar2 & 0xffff) >> 9) + 0x50;
  }
  if (uVar6 != 0xff) {
    uVar2 = dosfsDiskToHost16(param_2 + uVar6);
    local_34[0] = (uVar2 & 0x1f) << 1;
    local_34[2] = (int)(uVar2 & 0xffff) >> 0xb;
    local_34[1] = (int)(uVar2 & 0xffff) >> 5 & 0x3f;
  }
  mktime((tm *)local_34);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d8710 @ 0x300D8710  (примерный размер ~420 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: dosfsHostToDisk16, localtime_r
 * Вызывают: FUN_300da18c, FUN_300da31c
 * Константы: 0x300D8710
 * ---------------------------------------------------------------- */
void FUN_300d8710(int param_1,int param_2,uint param_3,time_t param_4)

{
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3c;
  undefined1 local_3b;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  int local_28;
  int local_24;
  time_t local_4;
  
  local_4 = param_4;
  localtime_r(&local_4,(tm *)&local_38);
  dosfsHostToDisk16((local_38 >> 1 | local_34 << 5 | local_30 << 0xb) & 0xffff,&local_40);
  if (local_24 < 0x50) {
    local_24 = 0x50;
  }
  dosfsHostToDisk16((local_2c | local_28 * 0x20 + 0x20U | local_24 * 0x200 + 0x6000U) & 0xffff,
                    &local_3c);
  if (((param_3 & 1) != 0) && (*(char *)(param_1 + 0x41) != -1)) {
    *(undefined1 *)(param_2 + (uint)*(byte *)(param_1 + 0x40)) = local_40;
    *(undefined1 *)(param_2 + (uint)*(byte *)(param_1 + 0x40) + 1) = local_3f;
    *(undefined1 *)(param_2 + (uint)*(byte *)(param_1 + 0x41)) = local_3c;
    *(undefined1 *)(param_2 + (uint)*(byte *)(param_1 + 0x41) + 1) = local_3b;
  }
  if (((param_3 & 2) != 0) && (*(char *)(param_1 + 0x43) != -1)) {
    *(undefined1 *)(param_2 + (uint)*(byte *)(param_1 + 0x42)) = local_40;
    *(undefined1 *)(param_2 + (uint)*(byte *)(param_1 + 0x42) + 1) = local_3f;
    *(undefined1 *)(param_2 + (uint)*(byte *)(param_1 + 0x43)) = local_3c;
    *(undefined1 *)(param_2 + (uint)*(byte *)(param_1 + 0x43) + 1) = local_3b;
  }
  if (((param_3 & 4) != 0) && (*(char *)(param_1 + 0x45) != -1)) {
    if (*(byte *)(param_1 + 0x44) != 0xff) {
      *(undefined1 *)(param_2 + (uint)*(byte *)(param_1 + 0x44)) = local_40;
      *(undefined1 *)(param_2 + (uint)*(byte *)(param_1 + 0x44) + 1) = local_3f;
    }
    *(undefined1 *)(param_2 + (uint)*(byte *)(param_1 + 0x45)) = local_3c;
    *(undefined1 *)(param_2 + (uint)*(byte *)(param_1 + 0x45) + 1) = local_3b;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d88b4 @ 0x300D88B4  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: bcmp
 * Вызывают: FUN_300d8a20, FUN_300d91ec
 * Константы: 0x300D88B4
 * Данные: DAT_300d98ac, DAT_300d98b0, DAT_300d98b4
 * ---------------------------------------------------------------- */
undefined4 FUN_300d88b4(char *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  
  bVar1 = false;
  if (*param_1 == ' ') {
    return 0;
  }
  if ((*param_1 != '.') ||
     ((iVar2 = bcmp(param_1,DAT_300d98ac,0xb), iVar2 != 0 &&
      (iVar2 = bcmp(param_1,DAT_300d98b0,0xb), iVar2 != 0)))) {
    iVar2 = 0;
    pbVar4 = (byte *)(param_1 + -1);
    do {
      pbVar4 = pbVar4 + 1;
      uVar3 = (uint)*pbVar4;
      if (uVar3 == 0x20) {
        bVar1 = true;
      }
      else {
        if (bVar1) {
          return 0;
        }
        if (uVar3 < 0x80) {
          if (param_2 == 0) {
            if (uVar3 == 0x7c) {
              return 0;
            }
            if (*(byte *)(DAT_300d98b4 + uVar3) != uVar3) {
              return 0;
            }
            bVar5 = true;
          }
          else {
            bVar5 = *(char *)(DAT_300d98b4 + uVar3) != '|';
          }
          if (!bVar5) {
            return 0;
          }
        }
      }
      if (iVar2 == 7) {
        bVar1 = false;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xb);
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300d89a8 @ 0x300D89A8  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300d8a20
 * Константы: 0x300D89A8
 * Данные: DAT_300d98b4
 * ---------------------------------------------------------------- */
void FUN_300d89a8(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  
  iVar5 = 0;
  if (0 < param_4) {
    pbVar3 = (byte *)(param_3 + -1);
    pbVar2 = (byte *)(param_1 + -1);
    iVar4 = param_4;
    do {
      pbVar3 = pbVar3 + 1;
      bVar6 = *pbVar3;
      if (bVar6 < 0x80) {
        bVar6 = *(byte *)(DAT_300d98b4 + (uint)bVar6);
      }
      pbVar2 = pbVar2 + 1;
      *pbVar2 = bVar6;
      iVar4 = iVar4 + -1;
      iVar5 = param_4;
    } while (iVar4 != 0);
  }
  if (iVar5 < param_2) {
    puVar1 = (undefined1 *)(param_1 + iVar5 + -1);
    param_2 = param_2 - iVar5;
    do {
      puVar1 = puVar1 + 1;
      *puVar1 = 0x20;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d8a20 @ 0x300D8A20  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300d88b4, FUN_300d89a8
 * Вызывают: FUN_300d8c74
 * Константы: 0x300D8A20
 * Данные: DAT_300d99c0, DAT_300d99c4, DAT_300d99c8, DAT_300d99cc
 * ---------------------------------------------------------------- */
undefined4 FUN_300d8a20(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((int)param_2 < 0) {
    param_2 = (uint)*(ushort *)(param_1 + 4);
    iVar3 = 0;
  }
  else {
    iVar3 = (*(ushort *)(param_1 + 4) - param_2) + -1;
  }
  if ((param_2 - 1 < 8) && (iVar3 < 4)) {
    iVar2 = param_1 + DAT_300d99c0;
    FUN_300d89a8(iVar2,8,param_1 + DAT_300d99c4,param_2);
    FUN_300d89a8(param_1 + DAT_300d99cc,3,param_1 + param_2 + DAT_300d99c8,iVar3);
    *(undefined1 *)(param_1 + 0x52a) = 0;
    uVar1 = FUN_300d88b4(iVar2);
    return uVar1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300d8abc @ 0x300D8ABC  (примерный размер ~268 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300d8c74
 * Константы: 0x300D8ABC
 * Данные: DAT_300d99c4, DAT_300d99d0, DAT_300d99d4
 * ---------------------------------------------------------------- */
undefined4 FUN_300d8abc(int param_1,uint param_2)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  if ((int)param_2 < 0) {
    param_2 = (uint)*(ushort *)(param_1 + 4);
    iVar1 = 0;
  }
  else {
    iVar1 = (*(ushort *)(param_1 + 4) - param_2) + -1;
  }
  uVar3 = 0;
  if ((param_2 - 1 < 8) && (iVar1 < 4)) {
    uVar4 = 0;
    if (0 < (int)param_2) {
      pbVar2 = (byte *)(param_1 + DAT_300d99d4);
      uVar4 = param_2;
      do {
        pbVar2 = pbVar2 + 1;
        if ((*(byte *)(*DAT_300d99d0 + (uint)*pbVar2) & 2) == 0) break;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      uVar4 = param_2 - uVar4;
    }
    if ((uVar4 == param_2) && (param_2 != 0)) {
      *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) | 0x800;
      uVar3 = 1;
    }
    iVar5 = 0;
    if (0 < iVar1) {
      pbVar2 = (byte *)(param_1 + param_2 + DAT_300d99c4);
      iVar5 = iVar1;
      do {
        pbVar2 = pbVar2 + 1;
        if ((*(byte *)(*DAT_300d99d0 + (uint)*pbVar2) & 2) == 0) break;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      iVar5 = iVar1 - iVar5;
    }
    if ((iVar5 == iVar1) && (iVar1 != 0)) {
      uVar3 = 1;
      *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) | 0x1000;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300d8bc8 @ 0x300D8BC8  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: bcopy
 * Вызывают: FUN_300d9428
 * Константы: 0x300D8BC8
 * Данные: DAT_300d98b4, DAT_300d9bdc, DAT_300d9be0
 * ---------------------------------------------------------------- */
size_t FUN_300d8bc8(void *param_1,void *param_2,size_t param_3,int param_4)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  size_t sVar4;
  
  bcopy(param_2,param_1,param_3);
  if (0 < (int)param_3) {
    pcVar2 = (char *)((int)param_1 + param_3);
    do {
      pcVar2 = pcVar2 + -1;
      if (*pcVar2 != ' ') break;
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  if (0 < (int)param_3) {
    pbVar3 = (byte *)((int)param_1 + -1);
    sVar4 = param_3;
    do {
      pbVar3 = pbVar3 + 1;
      if (*pbVar3 < 0x80) {
        bVar1 = *(byte *)(DAT_300d98b4 + (uint)*pbVar3);
        if (bVar1 != 0x7c) {
          if ((*DAT_300d9bdc != 0) && (param_4 != 0)) {
            bVar1 = *(byte *)(*DAT_300d9be0 + (uint)bVar1);
          }
          *pbVar3 = bVar1;
        }
      }
      sVar4 = sVar4 - 1;
    } while (sVar4 != 0);
  }
  return param_3;
}

/* ----------------------------------------------------------------
 * FUN_300d8c74 @ 0x300D8C74  (примерный размер ~648 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300d8a20, FUN_300d8abc, __div32, bcopy
 * Вызывают: FUN_300d9f14
 * Константы: 0x300D8C74
 * Данные: DAT_300d98b4, DAT_300d99c4, DAT_300d99d4, DAT_300d9bdc, DAT_300d9be8, DAT_300d9bec, DAT_300d9bf0, DAT_300d9d38
 * ---------------------------------------------------------------- */
void FUN_300d8c74(undefined2 *param_1,undefined4 *param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  ushort uVar11;
  void *__dest;
  bool bVar12;
  bool bVar13;
  
  iVar7 = DAT_300d99c4;
  uVar10 = (uint)*(ushort *)(param_2 + 1);
  bVar13 = SBORROW4(uVar10,0x30c);
  iVar2 = uVar10 - 0x30c;
  bVar12 = uVar10 == 0x30c;
  iVar8 = 0;
  if (uVar10 < 0x30d) {
    if (param_3 == 0) {
      bVar13 = SBORROW4(uVar10,0xff);
      iVar2 = uVar10 - 0xff;
      bVar12 = uVar10 == 0xff;
      goto LAB_300d8cac;
    }
  }
  else {
LAB_300d8cac:
    if (!bVar12 && iVar2 < 0 == bVar13) {
      return;
    }
  }
  __dest = (void *)((int)param_1 + DAT_300d99c4);
  bcopy((void *)*param_2,__dest,uVar10);
  *(undefined1 *)((int)param_1 + iVar7 + (uint)*(ushort *)(param_2 + 1)) = 0;
  uVar11 = *(ushort *)(param_2 + 1);
  param_1[2] = uVar11;
  if (param_3 == 0) {
    iVar2 = uVar11 + 1;
    puVar3 = param_1 + 3;
    pbVar9 = (byte *)((int)param_1 + DAT_300d99d4);
    do {
      pbVar9 = pbVar9 + 1;
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + 1;
      *puVar3 = (ushort)*pbVar9;
    } while (iVar2 != 0);
  }
  else {
    if ((code *)*DAT_300d9be8 == (code *)0x0) {
      return;
    }
    iVar2 = (*(code *)*DAT_300d9be8)(__dest,param_1 + 4,DAT_300d9bec,1);
    if (iVar2 < 1) {
      return;
    }
    if (iVar2 < 0x101) {
      __dest = (void *)(iVar2 + DAT_300d9bf0);
    }
    uVar11 = (ushort)__dest;
    if (0x100 < iVar2) {
      return;
    }
  }
  param_1[1] = uVar11;
  iVar6 = 0;
  bVar12 = false;
  iVar2 = -1;
  bVar13 = false;
  iVar4 = 0;
  if ((ushort)param_1[2] == 0) {
LAB_300d8e30:
    iVar7 = FUN_300d8a20(param_1,iVar2);
  }
  else {
    do {
      uVar10 = (uint)*(byte *)((int)param_1 + iVar7 + iVar4);
      if (uVar10 < 0x80) {
        if (uVar10 == 0x2e) {
          iVar6 = iVar6 + 1;
          uVar5 = 0x2e;
          iVar2 = iVar4;
        }
        else {
          uVar5 = (uint)*(byte *)(DAT_300d98b4 + uVar10);
        }
        if (*(char *)(DAT_300d9d38 + uVar10) == '|') {
          return;
        }
        if (uVar5 == 0x7c) goto LAB_300d8df8;
        if (uVar5 != uVar10) {
          bVar13 = true;
        }
      }
      else if (param_3 != 0) {
LAB_300d8df8:
        bVar12 = true;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)(ushort)param_1[2]);
    if ((iVar6 < 2) && (!bVar12)) goto LAB_300d8e30;
    iVar7 = 0;
  }
  param_1[3] = 0;
  uVar11 = (ushort)bVar12;
  if (bVar12) {
    param_1[3] = uVar11;
  }
  if (bVar13) {
    uVar11 = uVar11 | 2;
    param_1[3] = uVar11;
  }
  if (iVar7 == 0) {
LAB_300d8e90:
    if (*DAT_300d9bdc == 0) goto LAB_300d8ebc;
    if ((iVar7 == 0) || ((bVar13 && (iVar8 == 0)))) goto LAB_300d8ed4;
  }
  else {
    param_1[3] = uVar11 | 8;
    if (*DAT_300d9bdc != 0) {
      iVar8 = FUN_300d8abc(param_1,iVar2);
      goto LAB_300d8e90;
    }
LAB_300d8ebc:
    if ((iVar7 == 0) || (bVar13)) {
LAB_300d8ed4:
      uVar1 = __div32((ushort)param_1[1] + 0xc,0xd);
      goto LAB_300d8ee8;
    }
  }
  uVar1 = 0;
LAB_300d8ee8:
  *param_1 = uVar1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d8efc @ 0x300D8EFC  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300d9428
 * Константы: 0x300D8EFC
 * Данные: DAT_300d99c4, DAT_300d99d4, DAT_300d9bf0, DAT_300d9eb4, DAT_300d9eb8
 * ---------------------------------------------------------------- */
undefined4 FUN_300d8efc(int param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  ushort uVar3;
  undefined2 *puVar4;
  
  if (param_2 == 0) {
    if ((*(ushort *)(param_1 + 6) & 0x10) != 0) {
      return 0;
    }
    puVar4 = (undefined2 *)(param_1 + 6);
    iVar1 = 0;
    puVar2 = (undefined1 *)(param_1 + DAT_300d99d4);
    do {
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
      *puVar2 = (char)*puVar4;
      uVar3 = *(ushort *)(param_1 + 2);
      iVar1 = iVar1 + 1;
    } while (iVar1 <= (int)(uint)uVar3);
  }
  else {
    if ((code *)*DAT_300d9eb4 == (code *)0x0) {
      return 0;
    }
    iVar1 = (*(code *)*DAT_300d9eb4)(param_1 + 8,1,param_1 + DAT_300d99c4,DAT_300d9eb8);
    if (iVar1 < 1) {
      *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) | 0x40;
      return 0;
    }
    uVar3 = (short)iVar1 + (short)DAT_300d9bf0;
  }
  *(ushort *)(param_1 + 4) = uVar3;
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300d8fc4 @ 0x300D8FC4  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: __urem32, sprintf
 * Вызывают: FUN_300da31c
 * Константы: 0x300D8FC4
 * Данные: DAT_300d99c0, DAT_300d9ebc, DAT_300d9ec0
 * ---------------------------------------------------------------- */
void FUN_300d8fc4(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)(param_1 + DAT_300d99c0);
  *puVar2 = 0x20;
  puVar2[1] = 0;
  iVar1 = __urem32(param_2,DAT_300d9ebc);
  sprintf(puVar2 + 2,DAT_300d9ec0,DAT_300d9ebc - iVar1);
  puVar2[8] = 0x2f;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) | 0x20;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d9028 @ 0x300D9028  (примерный размер ~452 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300d85d4, bcopy, bfill, bzero
 * Вызывают: FUN_300da31c
 * Константы: 0x300D9028
 * Данные: DAT_300d99c0, DAT_300d9bdc, DAT_300da024, DAT_300da028, DAT_300da02c, DAT_300da030
 * ---------------------------------------------------------------- */
byte * FUN_300d9028(void *param_1,ushort *param_2)

{
  ushort uVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  byte *__dest;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  
  uVar9 = 0;
  bzero(param_1,(uint)*param_2 * 0x20 + 0x20);
  __dest = (byte *)((int)param_1 + (uint)*param_2 * 0x20);
  bcopy((void *)((int)param_2 + DAT_300d99c0),__dest,0xb);
  if (*DAT_300d9bdc != 0) {
    __dest[0xc] = 0;
    if ((param_2[3] & 0x800) != 0) {
      iVar8 = 8;
      __dest[0xc] = 8;
      iVar4 = *DAT_300da024;
      pbVar10 = (byte *)((int)param_2 + DAT_300da028);
      do {
        pbVar10 = pbVar10 + 1;
        iVar8 = iVar8 + -1;
        *pbVar10 = *(byte *)(iVar4 + (uint)*pbVar10);
      } while (iVar8 != 0);
      uVar9 = 8;
    }
    if (((param_2[3] & 0x1000) != 0) && (__dest[0xc] = __dest[0xc] | 0x10, uVar9 < 3)) {
      iVar4 = *DAT_300da024;
      pbVar10 = (byte *)((int)param_2 + DAT_300da02c + uVar9);
      iVar8 = 3 - uVar9;
      do {
        pbVar10 = pbVar10 + 1;
        iVar8 = iVar8 + -1;
        *pbVar10 = *(byte *)(iVar4 + (uint)*pbVar10);
      } while (iVar8 != 0);
    }
  }
  if (*__dest == 0xe5) {
    *__dest = 5;
  }
  uVar1 = *param_2;
  if (uVar1 != 0) {
    bVar2 = FUN_300d85d4(__dest);
    iVar4 = (uint)uVar1 * 0xd - (param_2[1] + 1);
    if (0 < iVar4) {
      bfill(param_2 + param_2[1] + 5,iVar4 * 2,0xff);
    }
    iVar4 = DAT_300da030;
    puVar5 = param_2 + 4;
    iVar8 = 1;
    pbVar10 = __dest;
    pbVar3 = __dest;
    if (*param_2 != 0) {
      do {
        pbVar10 = pbVar3 + -0x20;
        *pbVar10 = (byte)iVar8;
        pbVar3[-0x15] = 0xf;
        pbVar3[-0x13] = bVar2;
        pbVar3 = (byte *)(iVar4 + -1);
        iVar7 = 0xd;
        puVar6 = puVar5;
        do {
          pbVar3 = pbVar3 + 1;
          puVar5 = puVar6 + 1;
          uVar1 = *puVar6;
          pbVar10[*pbVar3] = (byte)uVar1;
          iVar7 = iVar7 + -1;
          pbVar10[*pbVar3 + 1] = (byte)(uVar1 >> 8);
          puVar6 = puVar5;
        } while (iVar7 != 0);
        iVar8 = iVar8 + 1;
        pbVar3 = pbVar10;
      } while (iVar8 <= (int)(uint)*param_2);
    }
    *pbVar10 = *pbVar10 | 0x40;
  }
  return __dest;
}

/* ----------------------------------------------------------------
 * FUN_300d91ec @ 0x300D91EC  (примерный размер ~572 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300d85d4, FUN_300d88b4, __div32, bcopy
 * Вызывают: FUN_300d9ac4
 * Константы: 0xFFFFFFFF, 0x300D91EC
 * Данные: DAT_300d99c0, DAT_300d9bdc, DAT_300d9bf0, DAT_300da2d4
 * ---------------------------------------------------------------- */
undefined4 FUN_300d91ec(undefined2 *param_1,int param_2,int param_3)

{
  ushort uVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  void *__dest;
  ushort uVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  byte *__src;
  ushort *puVar9;
  undefined4 local_28;
  
  if (param_3 < 0) {
    return 0xffffffff;
  }
  __src = (byte *)(param_2 + param_3 * 0x20);
  __dest = (void *)((int)param_1 + DAT_300d99c0);
  bcopy(__src,__dest,0xb);
  if (*(char *)((int)param_1 + 0x51f) == '\x05') {
    *(undefined1 *)((int)param_1 + 0x51f) = 0xe5;
  }
  *(undefined1 *)(param_1 + 0x295) = 0;
  iVar3 = FUN_300d88b4(__dest,1);
  local_28 = 0xffffffff;
  if (iVar3 != 0) {
    local_28 = 0;
  }
  *param_1 = (short)param_3;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar5 = (ushort)(((uint)(iVar3 != 0) << 0x10) >> 0xd);
  param_1[3] = uVar5;
  if (*DAT_300d9bdc != 0) {
    if (param_3 != 0) goto LAB_300d92d8;
    if (iVar3 == 0) {
      return local_28;
    }
    if ((__src[0xc] & 8) != 0) {
      uVar5 = uVar5 | 0x800;
      param_1[3] = uVar5;
    }
    if ((__src[0xc] & 0x10) == 0) {
      return local_28;
    }
    uVar5 = uVar5 | 0x1000;
    param_1[3] = uVar5;
  }
  if (param_3 == 0) {
    return local_28;
  }
LAB_300d92d8:
  if (param_3 < 0x15) {
    bVar2 = FUN_300d85d4(__src);
    uVar5 = 0;
    iVar3 = -1;
    bVar7 = 0;
    puVar9 = param_1 + 4;
    uVar8 = 1;
    pbVar4 = __src;
    if (0 < param_3) {
      do {
        __src = pbVar4 + -0x20;
        if (pbVar4[-0x15] != 0xf) {
          uVar5 = uVar5 | 0x100;
        }
        if ((*__src & 0x1f) != uVar8) {
          uVar5 = uVar5 | 0x200;
        }
        if (pbVar4[-0x13] != bVar2) {
          uVar5 = uVar5 | 0x80;
        }
        iVar6 = 0xd;
        pbVar4 = DAT_300da2d4;
        do {
          pbVar4 = pbVar4 + 1;
          uVar1 = CONCAT11(__src[*pbVar4 + 1],__src[*pbVar4]);
          if (iVar3 < 0) {
            bVar7 = bVar7 | __src[*pbVar4 + 1];
            if (uVar1 == 0) {
              iVar3 = (int)puVar9 - (int)(param_1 + 4) >> 1;
            }
          }
          else if (uVar1 != DAT_300d9bf0) {
            uVar5 = uVar5 | 0x40;
          }
          *puVar9 = uVar1;
          puVar9 = puVar9 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        uVar8 = uVar8 + 1;
        pbVar4 = __src;
      } while ((int)uVar8 <= param_3);
    }
    if ((*__src & 0x40) == 0) {
      uVar5 = uVar5 | 0x200;
    }
    if (iVar3 < 0) {
      iVar3 = param_3 * 0xd;
      param_1[param_3 * 0xd + 4] = 0;
    }
    iVar6 = __div32(iVar3 + 0xc,0xd);
    if (iVar6 < param_3) {
      uVar5 = uVar5 | 0x40;
    }
    param_1[1] = (short)iVar3;
    if (bVar7 != 0) {
      param_1[3] = param_1[3] | 0x10;
    }
    param_1[3] = param_1[3] | uVar5;
    if (uVar5 == 0) {
      local_28 = 0;
    }
  }
  else {
    param_1[3] = uVar5 | 0x400;
  }
  return local_28;
}

/* ----------------------------------------------------------------
 * FUN_300d9428 @ 0x300D9428  (примерный размер ~300 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: FUN_300d8bc8, FUN_300d8efc, printf
 * Вызывают: FUN_300d9ac4, FUN_300da684, dosVDirReaddirPlus
 * Константы: 0x300D9428
 * Данные: DAT_300d99c0, DAT_300d99c4, DAT_300d99cc, DAT_300da41c, DAT_300da420
 * ---------------------------------------------------------------- */
void FUN_300d9428(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if (((param_3 == 0) && (*(short *)(param_2 + 2) != 0)) &&
     ((*(ushort *)(param_2 + 6) & 0x7c0) == 0)) {
    iVar1 = FUN_300d8efc(param_2,*(undefined4 *)(param_1 + 0xa0));
    if (iVar1 != 0) {
      *(ushort *)(param_2 + 6) = *(ushort *)(param_2 + 6) | 4;
      return;
    }
    if (((*(ushort *)(param_2 + 6) & 0x10) != 0) && (*(int *)(param_1 + 0xa8) == 0)) {
      if ((*DAT_300da41c != 0) && (*DAT_300da41c < 2)) {
        printf(DAT_300da420,*(undefined4 *)(param_1 + 0xc));
      }
      *(undefined4 *)(param_1 + 0xa8) = 1;
    }
  }
  iVar2 = param_2 + DAT_300d99c4;
  iVar1 = FUN_300d8bc8(iVar2,param_2 + DAT_300d99c0,8);
  puVar3 = (undefined1 *)(iVar2 + iVar1);
  iVar1 = FUN_300d8bc8(puVar3 + 1,param_2 + DAT_300d99cc,3);
  if (iVar1 < 1) {
    *puVar3 = 0;
    return;
  }
  *puVar3 = 0x2e;
  (puVar3 + 1)[iVar1] = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300d9554 @ 0x300D9554  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300d97b0, FUN_300da31c
 * Константы: 0xFFFFFFFF, 0x300D9554, 0x7FFFFFFF
 * Данные: DAT_300da544
 * ---------------------------------------------------------------- */
undefined4 FUN_300d9554(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = -0x7fffffff;
  if (param_2 == 0) {
    iVar4 = 0;
  }
  iVar1 = (*(code *)**(undefined4 **)(*param_1 + 0x30))(param_1,iVar4);
  uVar2 = DAT_300da544;
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    if ((iVar4 != 0) && (uVar3 = param_1[6], uVar3 < uVar3 + param_1[9])) {
      do {
        iVar4 = (**(code **)(*(int *)(*param_1 + 0x2c) + 0x24))(*param_1,uVar2,uVar3);
        if (iVar4 == -1) {
          return 0xffffffff;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)(param_1[6] + param_1[9]));
    }
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300d961c @ 0x300D961C  (примерный размер ~404 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: FUN_300d8568
 * Вызывают: FUN_300d9ac4, FUN_300da18c, FUN_300daf70, FUN_300daffc
 * Константы: 0x300D961C
 * ---------------------------------------------------------------- */
undefined4 FUN_300d961c(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_6c [6];
  undefined4 local_54;
  undefined4 local_44;
  
  iVar8 = *param_1;
  iVar7 = param_1[1];
  iVar3 = *(int *)(iVar8 + 0x2c);
  uVar4 = (uint)*(byte *)(iVar3 + 0x3c);
  local_54 = 0;
  local_6c[2] = 0;
  local_6c[3] = 0;
  local_6c[0] = 0;
  if (param_3 == 3) {
    iVar8 = 0x12;
    piVar2 = local_6c;
    do {
      iVar8 = iVar8 + -1;
      *piVar2 = *param_1;
      piVar2 = piVar2 + 1;
      param_1 = param_1 + 1;
    } while (iVar8 != 0);
    local_54 = *(undefined4 *)(iVar7 + 0x18);
    local_6c[2] = *(uint *)(iVar7 + 0x1c);
    local_6c[3] = local_6c[2] >> 0x1f;
    local_44 = *(undefined4 *)(iVar7 + 0x28);
  }
  else if (param_3 != 1) {
    if (param_3 == 0) {
      FUN_300d8568(param_1);
    }
    else if (param_3 == 2) {
      uVar5 = param_1[2] + uVar4;
      uVar6 = param_1[3] + (uint)CARRY4(param_1[2],uVar4);
      param_1[2] = uVar5;
      param_1[3] = uVar6;
      uVar9 = *(ushort *)(iVar8 + 0x5c) - 1;
      if ((uVar6 & (int)uVar9 >> 0x1f) + (uVar5 & uVar9) == 0) {
        param_1[6] = param_1[6] + 1;
        param_1[9] = param_1[9] + -1;
      }
    }
    if (param_1[9] == 0) {
      iVar7 = (*(code *)**(undefined4 **)(iVar8 + 0x30))(param_1,0);
      if (iVar7 == -1) {
        return 1;
      }
      param_1[10] = 0;
    }
    iVar7 = 0x12;
    piVar2 = local_6c;
    do {
      iVar7 = iVar7 + -1;
      *piVar2 = *param_1;
      piVar2 = piVar2 + 1;
      param_1 = param_1 + 1;
    } while (iVar7 != 0);
  }
  iVar3 = (**(code **)(iVar3 + 0x20))
                    (local_6c[0],local_54,0,local_6c[2] & *(ushort *)(local_6c[0] + 0x5c) - 1,
                     param_2,uVar4,0);
  if (iVar3 == -1) {
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300d97b0 @ 0x300D97B0  (примерный размер ~264 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: FUN_300d9554
 * Вызывают: FUN_300d98b8, FUN_300d9a30, FUN_300da31c, FUN_300daffc
 * Константы: 0xFFFFFFFF, 0x300D97B0, 0xFFFFFFDF
 * ---------------------------------------------------------------- */
undefined4 FUN_300d97b0(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = *param_1;
  if ((param_4 & 2) != 0) {
    uVar3 = param_1[2] + 0x20;
    uVar4 = param_1[3] + (uint)(0xffffffdf < (uint)param_1[2]);
    param_1[2] = uVar3;
    param_1[3] = uVar4;
    uVar6 = *(ushort *)(iVar5 + 0x5c) - 1;
    if ((uVar4 & (int)uVar6 >> 0x1f) + (uVar3 & uVar6) == 0) {
      param_1[6] = param_1[6] + 1;
      param_1[9] = param_1[9] + -1;
    }
  }
  if ((param_1[9] == 0) && (iVar1 = FUN_300d9554(param_1,param_4 & 0x80), iVar1 == -1)) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar5 = (**(code **)(*(int *)(iVar5 + 0x2c) + 0x20))
                      (iVar5,param_1[6],0,param_1[2] & *(ushort *)(iVar5 + 0x5c) - 1,param_3,param_2
                       ,((*(uint *)(iVar5 + 0x9c) & 0x90000) != 0) + '\x01');
    if (iVar5 == -1) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300d98b8 @ 0x300D98B8  (примерный размер ~376 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: FUN_300d97b0, bzero
 * Вызывают: FUN_300da18c, FUN_300da684, dosVDirReaddirPlus
 * Константы: 0xFFFFFFFF, 0x300D98B8
 * ---------------------------------------------------------------- */
undefined4 FUN_300d98b8(int param_1,uint *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte local_d0 [11];
  char local_c5;
  undefined1 auStack_ac [12];
  undefined4 local_a0;
  int local_64;
  undefined1 *local_60;
  uint local_5c;
  int local_58;
  uint local_4c;
  int iStack_40;
  
  iVar2 = *(int *)(param_1 + 0x2c);
  bzero(&local_64,0x48);
  bzero(auStack_ac,0x44);
  local_60 = auStack_ac;
  local_4c = *param_2;
  local_5c = param_2[1];
  local_58 = (int)local_5c >> 0x1f;
  local_a0 = 0xffffffff;
  local_64 = param_1;
  if (local_4c < *(uint *)(param_1 + 0x78)) {
    iStack_40 = *(uint *)(param_1 + 0x78) - local_4c;
  }
  else {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x30) + 0xc))(&local_64,local_4c,0);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
  }
  if (param_3 == 0) {
    iVar2 = (**(code **)(iVar2 + 0x20))
                      (param_1,local_4c,0,local_5c & *(ushort *)(param_1 + 0x5c) - 1,local_d0,0x20,0
                      );
    if (iVar2 == -1) {
      return 0xffffffff;
    }
    if ((local_c5 != '\x0f') || ((local_d0[0] & 0x40) == 0)) {
      return 0xffffffff;
    }
    param_3 = (local_d0[0] & 0x1f) + 1;
  }
  local_d0[0] = 0xe5;
  uVar3 = 1;
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    iVar2 = FUN_300d97b0(&local_64,1,local_d0,uVar3);
    if (iVar2 == -1) break;
    uVar3 = 2;
    param_3 = param_3 + -1;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300d9a30 @ 0x300D9A30  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300d97b0
 * Вызывают: FUN_300da31c
 * Константы: 0x300D9A30, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300d9a30(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 1;
  iVar3 = 0;
  if (0 < param_3) {
    do {
      iVar1 = FUN_300d97b0(param_1,0x20,param_2,uVar2 | (uint)(param_4 != 0) << 7);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      if (iVar3 == 0) {
        *param_5 = *(undefined4 *)(param_1 + 0x18);
        param_5[1] = *(undefined4 *)(param_1 + 8);
      }
      uVar2 = 2;
      param_2 = param_2 + 0x20;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300d9ac4 @ 0x300D9AC4  (примерный размер ~916 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: FUN_300d91ec, FUN_300d9428, FUN_300d961c
 * Вызывают: FUN_300d9f14, FUN_300da684, dosVDirReaddirPlus
 * Константы: 0x300D9AC4
 * Данные: DAT_300dac0c
 * ---------------------------------------------------------------- */
char FUN_300d9ac4(undefined4 *param_1,byte *param_2,int param_3,undefined4 *param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint local_44;
  undefined4 local_3c;
  undefined4 local_2c;
  int local_28;
  
  uVar13 = *param_1;
  iVar6 = FUN_300d961c(param_1,param_2,(uint)(param_3 == 0) << 1);
  uVar8 = param_1[6];
  *param_4 = uVar8;
  uVar12 = param_1[2];
  param_4[1] = uVar12;
  if (iVar6 != 0) {
    param_4[2] = uVar8;
    param_4[3] = uVar12;
    return (iVar6 != 1) * '\x02' + '\x05';
  }
  local_44 = 0;
  bVar1 = *param_2;
  uVar7 = (uint)bVar1;
  if (uVar7 == 0xe5) {
    cVar5 = '\0';
  }
  else if (uVar7 == 0) {
    cVar5 = '\x06';
  }
  else {
    bVar2 = param_2[0xb];
    if (bVar2 == 0xf) {
      if ((bVar1 & 0x40) != 0) {
        local_44 = uVar7 & 0x1f;
        if (local_44 - 1 < 0x14) {
          cVar5 = '\x02';
          goto LAB_300d9c24;
        }
        if ((bVar1 & 0x1f) != 0) {
          cVar5 = '\x03';
          goto LAB_300d9c24;
        }
      }
    }
    else {
      if ((bVar2 & 8) != 0) {
        cVar5 = '\x01';
        goto LAB_300d9c24;
      }
      if (((((bVar2 == 0) || (bVar2 == 1)) || (bVar2 == 2)) || ((bVar2 == 4 || (bVar2 == 0x10)))) ||
         (bVar2 == 0x20)) {
        cVar5 = '\x02';
        iVar6 = FUN_300d91ec(param_5,param_2,0);
        if (iVar6 != -1) {
          FUN_300d9428(uVar13,param_5,0);
          goto LAB_300d9c24;
        }
      }
    }
    cVar5 = '\x04';
  }
LAB_300d9c24:
  uVar7 = local_44;
  uVar9 = param_4[1];
  local_2c = *param_4;
  if (local_44 == 0) {
    param_4[2] = local_2c;
    param_4[3] = uVar9;
    if ((param_2[0xc] & 8) != 0) {
      iVar6 = 8;
      iVar11 = *DAT_300dac0c;
      pbVar10 = param_2 + -1;
      do {
        pbVar10 = pbVar10 + 1;
        iVar6 = iVar6 + -1;
        *pbVar10 = *(byte *)(iVar11 + (uint)*pbVar10);
      } while (iVar6 != 0);
    }
    if ((param_2[0xc] & 0x10) != 0) {
      param_2 = param_2 + 7;
      iVar6 = *DAT_300dac0c;
      iVar11 = 3;
      do {
        param_2 = param_2 + 1;
        iVar11 = iVar11 + -1;
        *param_2 = *(byte *)(iVar6 + (uint)*param_2);
      } while (iVar11 != 0);
    }
  }
  else {
    local_28 = param_4[1];
    local_3c = param_1[9];
    local_44 = 0x14;
    bVar3 = false;
    pbVar10 = param_2;
    while( true ) {
      uVar7 = uVar7 - 1;
      bVar4 = false;
      if ((int)local_44 < 1) {
        bVar3 = true;
      }
      else {
        pbVar10 = pbVar10 + 0x20;
        local_44 = local_44 + -1;
      }
      iVar6 = FUN_300d961c(param_1,pbVar10,2);
      if (iVar6 != 0) {
        cVar5 = '\x04';
        goto LAB_300d9dfc;
      }
      bVar1 = *pbVar10;
      if ((bVar1 == 0xe5) || (bVar1 == 0)) break;
      if (pbVar10[0xb] != 0xf) {
        if (uVar7 != 0 || bVar3) {
          cVar5 = '\x03';
        }
        iVar6 = FUN_300d91ec(param_5,param_2,((uint)param_1[2] >> 5) - (uVar9 >> 5));
        if (iVar6 == -1) {
          cVar5 = '\x04';
        }
        else {
          FUN_300d9428(uVar13,param_5,0);
          if ((*(ushort *)(param_5 + 6) & 0x7c0) != 0) {
            cVar5 = '\x03';
          }
        }
        local_2c = param_1[6];
        local_28 = param_1[2];
        goto LAB_300d9dfc;
      }
      if ((bVar1 & 0x40) != 0) break;
      local_28 = param_1[2];
      local_2c = param_1[6];
      local_3c = param_1[9];
    }
    bVar4 = true;
    cVar5 = '\x04';
LAB_300d9dfc:
    param_4[2] = local_2c;
    param_4[3] = local_28;
    if (bVar4) {
      param_1[2] = local_28;
      param_1[3] = local_28 >> 0x1f;
      param_1[6] = local_2c;
      param_1[9] = local_3c;
      param_4[2] = 0;
      param_4[3] = param_4[3] + -0x20;
    }
  }
  return cVar5;
}

/* ----------------------------------------------------------------
 * FUN_300d9e58 @ 0x300D9E58  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300d9f14
 * Константы: 0x300D9E58
 * Данные: DAT_300da024
 * ---------------------------------------------------------------- */
undefined4 FUN_300d9e58(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 0;
  if (param_4 == 0) {
    while( true ) {
      uVar2 = (uint)*(byte *)(param_1 + iVar1);
      uVar3 = (uint)*(byte *)(param_2 + iVar1);
      if (param_3 == 0) {
        uVar2 = (uint)*(byte *)(*DAT_300da024 + uVar2);
        uVar3 = (uint)*(byte *)(*DAT_300da024 + uVar3);
      }
      if (uVar2 != uVar3) {
        return 0;
      }
      if (uVar2 == 0) break;
      iVar1 = iVar1 + 1;
    }
  }
  else {
    while( true ) {
      uVar3 = (uint)*(byte *)(param_1 + iVar1);
      uVar2 = (uint)*(byte *)(param_2 + iVar1);
      if (param_3 == 0) {
        if (uVar3 < 0x80) {
          uVar3 = (uint)*(byte *)(*DAT_300da024 + uVar3);
        }
        if (uVar2 < 0x80) {
          uVar2 = (uint)*(byte *)(*DAT_300da024 + uVar2);
        }
      }
      if (uVar3 != uVar2) {
        return 0;
      }
      if (uVar3 == 0) break;
      iVar1 = iVar1 + 1;
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300d9f14 @ 0x300D9F14  (примерный размер ~632 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300d83bc, FUN_300d8c74, FUN_300d9ac4, FUN_300d9e58, errnoSet
 * Вызывают: FUN_300dada0
 * Константы: 0xFFFFFFFF, 0x300D9F14
 * Данные: DAT_300daf04, DAT_300daf08, DAT_300db03c, DAT_300db040
 * ---------------------------------------------------------------- */
undefined4 FUN_300d9f14(int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  ushort *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 local_48;
  uint local_44;
  undefined4 uStack_40;
  uint local_3c;
  undefined4 local_38;
  uint local_34;
  uint local_2c;
  
  iVar9 = *(int *)(*param_1 + 0x2c);
  uVar6 = *(undefined4 *)(*param_1 + 0xa0);
  puVar8 = *(ushort **)(iVar9 + 0x30);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
  }
  iVar4 = FUN_300d8c74(puVar8,param_2,uVar6);
  if (iVar4 == 0) {
    iVar4 = 0;
    local_48 = 0;
    local_44 = 0;
    uVar3 = *puVar8;
    uVar7 = 1;
    iVar11 = (int)puVar8 + DAT_300daf04;
    iVar10 = (int)puVar8 + DAT_300daf08;
    while (iVar5 = FUN_300d9ac4(param_1,iVar11,uVar7,&local_38,iVar10,uVar6), iVar5 != 7) {
      uVar1 = local_2c >> 5;
      uVar2 = local_34 >> 5;
      if (param_3 != (undefined4 *)0x0) {
        if ((iVar5 == 0) || (iVar5 == 6)) {
          if (iVar4 < 1) {
            iVar4 = 1;
            local_48 = local_38;
            local_44 = local_34;
          }
          else {
            iVar4 = iVar4 + 1;
          }
        }
        if (iVar5 != 0) {
          if (((int)(uVar3 + 1) <= iVar4) && ((param_3[2] == 0 || (iVar4 < (int)param_3[2])))) {
            *param_3 = local_48;
            param_3[1] = local_44;
            param_3[2] = iVar4;
            param_3[3] = local_44 >> 5;
          }
          if (iVar5 == 5) goto LAB_300da10c;
          if (iVar5 != 6) {
            iVar4 = 0;
          }
        }
      }
      if ((iVar5 == 5) || (iVar5 == 6)) {
LAB_300da10c:
        if (param_3 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        if (param_3[2] != 0) {
          return 0xffffffff;
        }
        if (iVar4 == 0) {
          local_48 = local_38;
          local_44 = local_34;
        }
        param_3[3] = local_44 >> 5;
        if ((*(int *)(param_1[1] + 0x14) == -1) &&
           (*(uint *)(iVar9 + 0x50) < (local_44 >> 5) + uVar3 + 1)) {
          return 0xffffffff;
        }
        if (iVar4 < 1) {
          return 0xffffffff;
        }
        *param_3 = local_48;
        param_3[1] = local_44;
        return 0xffffffff;
      }
      if (((iVar5 == 2) || (iVar5 == 3)) &&
         (iVar5 = FUN_300d9e58((int)puVar8 + DAT_300db03c,(int)puVar8 + DAT_300db040,param_4,uVar6),
         iVar5 != 0)) {
        if (uVar2 < uVar1) {
          uStack_40 = local_38;
        }
        else {
          local_34 = 0;
          uStack_40 = 0;
        }
        local_3c = local_34;
        FUN_300d83bc(param_1,iVar11 + (uVar1 - uVar2) * 0x20,&uStack_40);
        return 0;
      }
      uVar7 = 0;
    }
  }
  else {
    errnoSet(iVar4);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300da18c @ 0x300DA18C  (примерный размер ~400 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_300d8710, FUN_300d961c, FUN_300d98b8, dosfsHostToDisk16, dosfsHostToDisk32, time
 * Вызывают: FUN_300da31c
 * Константы: 0x300DA18C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300da18c(int *param_1,uint param_2,time_t param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  int local_4c;
  undefined4 local_48;
  undefined1 auStack_44 [32];
  
  iVar4 = *param_1;
  iVar5 = *(int *)(iVar4 + 0x2c);
  if (param_3 == 0) {
    param_3 = time((time_t *)0x0);
  }
  iVar1 = param_1[1];
  if (*(int *)(iVar1 + 0x14) == -1) {
    if ((param_2 & 2) != 0) {
      *(time_t *)(iVar5 + 0x54) = param_3;
    }
    uVar2 = 0;
  }
  else if ((param_2 & 0x100) == 0) {
    iVar4 = FUN_300d961c(param_1,auStack_44,3);
    if (iVar4 == 0) {
      dosfsHostToDisk16(*(uint *)(param_1[1] + 0xc) & 0xffff,auStack_44 + *(byte *)(iVar5 + 0x46));
      dosfsHostToDisk16(*(undefined2 *)(param_1[1] + 0xe),auStack_44 + *(byte *)(iVar5 + 0x47));
      puVar3 = (undefined4 *)param_1[1];
      auStack_44[*(byte *)(iVar5 + 0x3f)] = *(undefined1 *)((int)puVar3 + 0x42);
      dosfsHostToDisk32(*puVar3,auStack_44 + *(byte *)(iVar5 + 0x48));
      FUN_300d8710(iVar5,auStack_44,param_2,param_3);
      iVar4 = *param_1;
      uVar2 = (**(code **)(iVar5 + 0x20))
                        (iVar4,*(undefined4 *)(param_1[1] + 0x18),0,
                         *(uint *)(param_1[1] + 0x1c) & *(ushort *)(iVar4 + 0x5c) - 1,auStack_44,
                         *(undefined1 *)(iVar5 + 0x3c),
                         ((*(uint *)(iVar4 + 0x9c) & 0x90000) != 0) + '\x01');
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    local_4c = *(int *)(iVar1 + 0x20);
    bVar6 = local_4c != 0;
    if (bVar6) {
      local_48 = *(undefined4 *)(iVar1 + 0x24);
    }
    else {
      local_4c = *(int *)(iVar1 + 0x18);
      local_48 = *(undefined4 *)(iVar1 + 0x1c);
    }
    uVar2 = FUN_300d98b8(iVar4,&local_4c,!bVar6);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300da31c @ 0x300DA31C  (примерный размер ~872 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 13
 * Вызывает: FUN_300d83bc, FUN_300d8568, FUN_300d8710, FUN_300d8fc4, FUN_300d9028, FUN_300d9554, FUN_300d97b0, FUN_300d9a30, FUN_300da18c, bcopy, dosfsHostToDisk16, errnoSet, time
 * Вызывают: FUN_300dada0
 * Константы: 0xFFFFFFFF, 0x300DA31C
 * Данные: DAT_300daf04, DAT_300db2b4, DAT_300db2b8, DAT_300db45c, DAT_300db460
 * ---------------------------------------------------------------- */
undefined4 FUN_300da31c(int *param_1,uint param_2,int *param_3)

{
  undefined4 uVar1;
  void *__dest;
  time_t tVar2;
  undefined2 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  ushort *puVar10;
  int iVar11;
  int local_2c;
  int local_28;
  
  iVar6 = *param_1;
  iVar7 = param_1[1];
  iVar9 = *(int *)(iVar6 + 0x2c);
  puVar10 = *(ushort **)(iVar9 + 0x30);
  if ((*(byte *)(iVar7 + 0x42) & 1) == 0) {
    if (((param_2 & 0xf000) == 0x8000) || ((param_2 & 0xf000) == 0x4000)) {
      iVar11 = *(int *)(iVar7 + 0x14);
      uVar8 = (uint)*puVar10;
      if ((puVar10[3] & 8) == 0) {
        FUN_300d8fc4(puVar10,uVar8 + param_3[3],*(undefined4 *)(iVar6 + 0xa0));
      }
      iVar4 = (int)puVar10 + DAT_300daf04;
      __dest = (void *)FUN_300d9028(iVar4,puVar10);
      tVar2 = time((time_t *)0x0);
      FUN_300d8710(iVar9,__dest,7,tVar2);
      local_2c = *param_3;
      local_28 = param_3[1];
      if (local_2c == 0) {
        if ((*(int *)(param_1[1] + 0x14) == -1) && (*(int *)(iVar9 + 0x50) != -1)) {
          errnoSet(DAT_300db45c);
          return 0xffffffff;
        }
      }
      else {
        if ((*(int *)(param_1[1] + 0x14) == -1) && (*(uint *)(iVar9 + 0x50) < 0xffffffff)) {
          param_1[9] = param_1[9] + (param_1[6] - local_2c);
          param_1[6] = local_2c;
        }
        else {
          iVar6 = (**(code **)(*(int *)(iVar6 + 0x30) + 0xc))(param_1,local_2c,0);
          if (iVar6 == -1) {
            return 0xffffffff;
          }
        }
        param_1[2] = local_28;
        param_1[3] = local_28 >> 0x1f;
      }
      iVar6 = FUN_300d9a30(param_1,iVar4,uVar8 + 1);
      if (iVar6 == -1) {
        uVar1 = 0xffffffff;
      }
      else {
        tVar2 = time((time_t *)0x0);
        FUN_300da18c(param_1,2,tVar2);
        piVar5 = (int *)0x0;
        if (uVar8 != 0) {
          piVar5 = &local_2c;
        }
        FUN_300d83bc(param_1,__dest,piVar5);
        if ((param_2 & 0xf000) != 0x8000) {
          *(undefined1 *)(param_1[1] + 0x42) = 0x10;
          iVar6 = FUN_300d9554(param_1,0x80);
          if (iVar6 == -1) {
            FUN_300da18c(param_1,0x100,0);
            return 0xffffffff;
          }
          bcopy(DAT_300db460,__dest,0xb);
          *(undefined1 *)((int)__dest + 0xb) = 0x10;
          dosfsHostToDisk16(*(uint *)(param_1[1] + 0xc) & 0xffff,
                            (int)__dest + (uint)*(byte *)(iVar9 + 0x46));
          dosfsHostToDisk16(*(undefined2 *)(param_1[1] + 0xe),
                            (int)__dest + (uint)*(byte *)(iVar9 + 0x47));
          iVar6 = FUN_300d97b0(param_1,0x20,__dest,1);
          if (iVar6 == -1) {
            return 0xffffffff;
          }
          *(undefined1 *)((int)__dest + 1) = 0x2e;
          if (iVar11 == -1) {
            dosfsHostToDisk16(0,(int)__dest + (uint)*(byte *)(iVar9 + 0x46));
            uVar3 = 0;
          }
          else {
            dosfsHostToDisk16(*(uint *)(iVar7 + 0x14) & 0xffff,
                              (int)__dest + (uint)*(byte *)(iVar9 + 0x46));
            uVar3 = *(undefined2 *)(iVar7 + 0x16);
          }
          dosfsHostToDisk16(uVar3,(int)__dest + (uint)*(byte *)(iVar9 + 0x47));
          iVar6 = FUN_300d97b0(param_1,0x20,__dest,0x82);
          if (iVar6 == -1) {
            return 0xffffffff;
          }
          iVar6 = FUN_300da18c(param_1,0,0);
          if (iVar6 == -1) {
            return 0xffffffff;
          }
          FUN_300d8568(param_1);
        }
        uVar1 = 0;
      }
    }
    else {
      errnoSet(DAT_300db2b8);
      uVar1 = 0xffffffff;
    }
  }
  else {
    errnoSet(DAT_300db2b4);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300da684 @ 0x300DA684  (примерный размер ~724 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 10
 * Вызывает: FUN_300d83bc, FUN_300d9428, FUN_300d98b8, FUN_300d9ac4, __rem64, errnoSet, logMsg, semGive, semTake, strcpy
 * Константы: 0xFFFFFFFF, 0x300DA684
 * Данные: DAT_300daf04, DAT_300daf08, DAT_300db040, DAT_300db2b8, DAT_300db5ec, DAT_300db5f0
 * ---------------------------------------------------------------- */
undefined4 FUN_300da684(int *param_1,int param_2,int *param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 local_44;
  uint local_40;
  undefined8 local_3c;
  undefined4 uStack_34;
  uint local_30;
  uint local_28;
  undefined4 *puVar6;
  
  iVar8 = *param_1;
  iVar13 = *(int *)(iVar8 + 0x2c);
  iVar11 = *(int *)(iVar13 + 0x30);
  if (param_3 != (int *)0x0) {
    param_3[1] = 0;
  }
  if (*(int *)(param_2 + 4) == -1) {
    *(undefined4 *)(param_2 + 8) = 1;
  }
  else {
    local_3c._0_4_ = param_1[2];
    local_3c._4_4_ = param_1[3];
    local_3c = __rem64((int)local_3c,local_3c._4_4_,0x20,0);
    if ((int)((ulonglong)local_3c >> 0x20) + (int)local_3c != 0) {
      errnoSet(DAT_300db2b8);
      return 0xffffffff;
    }
    iVar2 = semTake(*(undefined4 *)(iVar13 + 0x34),0xffffffff);
    if (iVar2 == -1) {
      return 0xffffffff;
    }
    uVar10 = 0;
    local_44 = 0;
    local_40 = 0;
    uVar7 = 0;
    bVar1 = true;
    do {
      uVar15 = *(undefined4 *)(iVar8 + 0xa0);
      iVar14 = iVar11 + DAT_300daf08;
      iVar2 = FUN_300d9ac4(param_1,iVar11 + DAT_300daf04);
      if (iVar2 == 7) {
        semGive(*(undefined4 *)(iVar13 + 0x34));
        return 0xffffffff;
      }
      if ((iVar2 == 5) || (iVar2 == 6)) break;
      uVar7 = local_28 >> 5;
      uVar10 = local_30 >> 5;
      if (iVar2 == 2) {
        if (uVar10 < uVar7) {
          local_44 = uStack_34;
          local_40 = local_30;
        }
LAB_300da83c:
        bVar1 = false;
      }
      else {
        if (iVar2 == 3) {
          if ((param_3 != (int *)0x0) && (param_3[1] = param_3[1] + 1, *param_3 != 0)) {
            iVar2 = uVar7 - uVar10;
LAB_300da830:
            FUN_300d98b8(iVar8,&uStack_34,iVar2);
          }
          goto LAB_300da83c;
        }
        if (iVar2 == 4) {
          if ((param_3 != (int *)0x0) && (param_3[1] = param_3[1] + 1, *param_3 != 0)) {
            iVar2 = (uVar7 - uVar10) + 1;
            goto LAB_300da830;
          }
          goto LAB_300da83c;
        }
      }
    } while (bVar1);
    if (bVar1) {
      *(undefined4 *)(param_2 + 4) = 0xffffffff;
      *(undefined4 *)(param_2 + 8) = 1;
    }
    else {
      *(uint *)(param_2 + 4) = param_1[2] | 1;
      iVar2 = DAT_300db040;
      if (0xff < *(ushort *)(iVar11 + 0x530)) {
        if (9 < *DAT_300db5ec) {
          iVar14 = 0;
          uVar15 = 0;
          logMsg(DAT_300db5f0,iVar11 + DAT_300db040,0,0,0,0,0);
        }
        FUN_300d9428(iVar8,iVar11 + DAT_300daf08,1);
      }
      strcpy((char *)(param_2 + 0x10),(char *)(iVar11 + iVar2));
      if (param_3 != (int *)0x0) {
        piVar12 = (int *)param_3[2];
        iVar8 = 0x12;
        puVar9 = (undefined4 *)piVar12[1];
        piVar3 = piVar12;
        piVar4 = param_1;
        do {
          iVar8 = iVar8 + -1;
          *piVar3 = *piVar4;
          piVar3 = piVar3 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar8 != 0);
        piVar12[1] = (int)puVar9;
        iVar8 = 0x11;
        puVar5 = (undefined4 *)param_1[1];
        do {
          puVar6 = puVar5 + 1;
          iVar8 = iVar8 + -1;
          *puVar9 = *puVar5;
          puVar9 = puVar9 + 1;
          puVar5 = puVar6;
        } while (iVar8 != 0);
        FUN_300d83bc(piVar12,iVar11 + DAT_300daf04 + (uVar7 - uVar10) * 0x20,&local_44,puVar6,iVar14
                     ,uVar15);
      }
    }
    semGive(*(undefined4 *)(iVar13 + 0x34));
  }
  return 0;
}

/* ----------------------------------------------------------------
 * dosVDirReaddirPlus @ 0x300DA958  (примерный размер ~1096 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 14
 * Вызывает: FUN_300d83bc, FUN_300d8610, FUN_300d9428, FUN_300d98b8, FUN_300d9ac4, __div64, __rem64, bzero, dosfsDiskToHost32, errnoSet, logMsg, semGive, semTake, strcpy
 * Константы: 0xFFFFFFFF, 0x300DA958
 * Данные: DAT_300daf04, DAT_300daf08, DAT_300db040, DAT_300db2b8, DAT_300db5ec, DAT_300db5f0, DAT_300db5f4, DAT_300db5f8
 * ---------------------------------------------------------------- */
undefined4 dosVDirReaddirPlus(uint *param_1,uint *param_2,int *param_3)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  uint *puVar14;
  int iVar15;
  uint uVar16;
  undefined4 local_4c;
  uint local_48;
  undefined8 local_44;
  undefined8 local_3c;
  undefined4 uStack_34;
  uint local_30;
  uint local_28;
  
  uVar16 = *param_1;
  iVar15 = *(int *)(uVar16 + 0x2c);
  iVar8 = *(int *)(iVar15 + 0x30);
  if (param_3 != (int *)0x0) {
    param_3[1] = 0;
  }
  if (*param_2 == 0xffffffff) {
    param_2[2] = 1;
  }
  else {
    local_44._0_4_ = param_1[2];
    local_44._4_4_ = param_1[3];
    local_3c._0_4_ = (uint)local_44;
    local_3c._4_4_ = local_44._4_4_;
    local_44 = __rem64((uint)local_44,local_44._4_4_,0x20,0);
    if ((int)((ulonglong)local_44 >> 0x20) + (int)local_44 != 0) {
      errnoSet(DAT_300db2b8);
      return 0xffffffff;
    }
    iVar4 = semTake(*(undefined4 *)(iVar15 + 0x34),0xffffffff);
    if (iVar4 == -1) {
      return 0xffffffff;
    }
    uVar9 = 0;
    local_4c = 0;
    local_48 = 0;
    uVar10 = 0;
    bVar2 = true;
    if (*param_2 == 0) {
      uVar13 = 1;
    }
    else {
      uVar13 = 0;
    }
    do {
      iVar4 = FUN_300d9ac4(param_1,iVar8 + DAT_300daf04,uVar13,&uStack_34,iVar8 + DAT_300daf08,
                           *(undefined4 *)(uVar16 + 0xa0));
      if (iVar4 == 7) {
        semGive(*(undefined4 *)(iVar15 + 0x34));
        return 0xffffffff;
      }
      if ((iVar4 == 5) || (iVar4 == 6)) break;
      uVar9 = local_30 >> 5;
      uVar10 = local_28 >> 5;
      if (iVar4 == 2) {
        if (uVar9 < uVar10) {
          local_4c = uStack_34;
          local_48 = local_30;
        }
LAB_300dab28:
        bVar2 = false;
      }
      else {
        if (iVar4 == 3) {
          if ((param_3 != (int *)0x0) && (param_3[1] = param_3[1] + 1, *param_3 != 0)) {
            iVar4 = uVar10 - uVar9;
LAB_300dab1c:
            FUN_300d98b8(uVar16,&uStack_34,iVar4);
          }
          goto LAB_300dab28;
        }
        if (iVar4 == 4) {
          if ((param_3 != (int *)0x0) && (param_3[1] = param_3[1] + 1, *param_3 != 0)) {
            iVar4 = (uVar10 - uVar9) + 1;
            goto LAB_300dab1c;
          }
          goto LAB_300dab28;
        }
      }
      uVar13 = 0;
    } while (bVar2);
    if (bVar2) {
      *param_2 = 0xffffffff;
      param_2[2] = 1;
    }
    else {
      *param_2 = param_1[2] | 1;
      iVar4 = DAT_300db040;
      if (0xff < *(ushort *)(iVar8 + 0x530)) {
        if (9 < *DAT_300db5ec) {
          logMsg(DAT_300db5f0,iVar8 + DAT_300db040,0,0,0,0,0);
        }
        FUN_300d9428(uVar16,iVar8 + DAT_300daf08,1);
      }
      strcpy((char *)(param_2 + 4),(char *)(iVar8 + iVar4));
      iVar8 = iVar8 + DAT_300daf04;
      iVar4 = (uVar10 - uVar9) * 0x20;
      iVar11 = iVar8 + iVar4;
      bzero(param_2 + 0x45,0x48);
      param_2[0x45] = *param_1;
      param_2[0x48] = 1;
      local_3c._0_4_ = dosfsDiskToHost32(iVar11 + 0x1c);
      local_44._4_4_ = 0;
      param_2[0x4b] = (uint)local_3c;
      param_2[0x4c] = 0;
      uVar16 = (uint)*(ushort *)(*param_1 + 0x5e) << *(sbyte *)(*param_1 + 0x84);
      param_2[0x50] = uVar16;
      local_3c._4_4_ = 0;
      local_44._0_4_ = (uint)local_3c;
      local_44 = __div64((uint)local_3c,0,uVar16,(int)uVar16 >> 0x1f);
      param_2[0x51] = (uint)local_44;
      bVar1 = *(byte *)(iVar11 + 0xb);
      *(byte *)(param_2 + 0x52) = bVar1;
      uVar10 = DAT_300db5f4;
      param_2[0x47] = DAT_300db5f4;
      uVar3 = DAT_300db5f8;
      if ((bVar1 & 1) != 0) {
        param_2[0x47] = DAT_300db5f8;
        uVar10 = uVar3;
      }
      if ((bVar1 & 0x10) == 0) {
        param_2[0x47] = uVar10 | 0x8000;
      }
      else {
        param_2[0x47] = uVar10 | 0x4000;
        param_2[0x4b] = uVar16;
        param_2[0x4c] = (int)uVar16 >> 0x1f;
      }
      local_3c = local_44;
      if (*(int *)(param_1[1] + 0x14) == -1) {
        param_2[0x4e] = *(uint *)(iVar15 + 0x54);
      }
      else {
        uVar16 = FUN_300d8610(iVar15,iVar11,1);
        param_2[0x4f] = uVar16;
        uVar16 = FUN_300d8610(iVar15,iVar11,2);
        param_2[0x4e] = uVar16;
        uVar16 = FUN_300d8610(iVar15,iVar11,4);
        param_2[0x4d] = uVar16;
      }
      param_2[0x46] = uVar9 * 0x20 - 0x20 | 1;
      if (param_3 != (int *)0x0) {
        puVar14 = (uint *)param_3[2];
        iVar11 = 0x12;
        puVar12 = (undefined4 *)puVar14[1];
        puVar5 = puVar14;
        puVar6 = param_1;
        do {
          iVar11 = iVar11 + -1;
          *puVar5 = *puVar6;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        } while (iVar11 != 0);
        puVar14[1] = (uint)puVar12;
        iVar11 = 0x11;
        puVar7 = (undefined4 *)param_1[1];
        do {
          iVar11 = iVar11 + -1;
          *puVar12 = *puVar7;
          puVar12 = puVar12 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar11 != 0);
        FUN_300d83bc(puVar14,iVar8 + iVar4,&local_4c);
      }
    }
    semGive(*(undefined4 *)(iVar15 + 0x34));
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300dada0 @ 0x300DADA0  (примерный размер ~464 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_300d83bc, FUN_300d9f14, FUN_300da31c, dosPathParse, errnoGet, errnoSet, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300DADA0
 * Данные: DAT_300db5fc, DAT_300db600, DAT_300db604
 * ---------------------------------------------------------------- */
undefined4 FUN_300dada0(int *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  undefined1 auStack_41c [16];
  undefined1 auStack_40c [1000];
  
  iVar5 = *(int *)(*param_1 + 0x2c);
  uVar2 = dosPathParse(param_2,auStack_40c,0x7d);
  if (uVar2 == 0xffffffff) {
    return 0xffffffff;
  }
  FUN_300d83bc(param_1,0,0);
  iVar3 = semTake(*(undefined4 *)(iVar5 + 0x34),0xffffffff);
  if (iVar3 == -1) {
    return 0xffffffff;
  }
  uVar4 = errnoGet();
  errnoSet(0);
  bVar1 = false;
  uVar6 = 0;
  if (uVar2 != 0) {
    do {
      if ((*(byte *)(param_1[1] + 0x42) & 0x10) == 0) break;
      if (uVar6 != 0) {
        semGive(*(undefined4 *)(iVar5 + 0x34));
        iVar3 = semTake(*(undefined4 *)(iVar5 + 0x34),0xffffffff);
        if (iVar3 == -1) {
          return 0xffffffff;
        }
      }
      if (uVar6 + 1 == uVar2) {
        bVar1 = true;
      }
      iVar3 = FUN_300d9f14(param_1,auStack_40c + uVar6 * 8);
      if (iVar3 == -1) {
        iVar3 = errnoGet();
        if (iVar3 != 0) {
          semGive(*(undefined4 *)(iVar5 + 0x34));
          return 0xffffffff;
        }
        break;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar2);
  }
  iVar3 = errnoGet();
  if (iVar3 == 0) {
    errnoSet(uVar4);
  }
  if (uVar6 == uVar2) {
    uVar4 = DAT_300db5fc;
    if ((param_3 & 0xa00) != 0xa00) {
      uVar4 = 0;
      goto LAB_300daf58;
    }
  }
  else {
    bVar7 = (*(byte *)(param_1[1] + 0x42) & 0x10) == 0;
    if (!bVar7) {
      if ((bVar1) && ((param_3 & 0x200) != 0)) {
        uVar4 = FUN_300da31c(param_1,param_4,auStack_41c);
        goto LAB_300daf58;
      }
      bVar7 = (*(byte *)(param_1[1] + 0x42) & 0x10) == 0;
    }
    uVar4 = DAT_300db600;
    if (!bVar7) {
      uVar4 = DAT_300db604;
    }
  }
  errnoSet(uVar4);
  uVar4 = 0xffffffff;
LAB_300daf58:
  semGive(*(undefined4 *)(iVar5 + 0x34));
  return uVar4;
}

/* ----------------------------------------------------------------
 * FUN_300daf70 @ 0x300DAF70  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300d8610, FUN_300d961c
 * Константы: 0x300DAF70, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300daf70(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_2c [32];
  
  iVar3 = *(int *)(*param_1 + 0x2c);
  if (*(int *)(param_1[1] + 0x14) == -1) {
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(iVar3 + 0x54);
  }
  else {
    iVar1 = FUN_300d961c(param_1,auStack_2c,3);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    uVar2 = FUN_300d8610(iVar3,auStack_2c,1);
    *(undefined4 *)(param_2 + 0x28) = uVar2;
    uVar2 = FUN_300d8610(iVar3,auStack_2c,2);
    *(undefined4 *)(param_2 + 0x24) = uVar2;
    uVar2 = FUN_300d8610(iVar3,auStack_2c,4);
    *(undefined4 *)(param_2 + 0x20) = uVar2;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300daffc @ 0x300DAFFC  (примерный размер ~456 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_300d83bc, FUN_300d961c, FUN_300d97b0, bcopy, bfill, bzero, errnoSet, strlen
 * Константы: 0xFFFFFFFF, 0x300DAFFC
 * Данные: DAT_300db2b8, DAT_300db45c, DAT_300db608
 * ---------------------------------------------------------------- */
undefined4 FUN_300daffc(int param_1,char *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  byte local_cc [32];
  undefined1 auStack_ac [72];
  int local_64;
  undefined1 *local_60;
  
  iVar5 = *(int *)(param_1 + 0x2c);
  if ((param_2 == (char *)0x0) && (param_2 = DAT_300db608, param_3 != 0x22)) {
    errnoSet(DAT_300db2b8);
    uVar1 = 0xffffffff;
  }
  else {
    local_60 = auStack_ac;
    local_64 = param_1;
    FUN_300d83bc(&local_64,0,0);
    uVar4 = 0;
    uVar1 = 0;
    while (((iVar2 = FUN_300d961c(&local_64,local_cc,uVar1), iVar2 == 0 && (local_cc[0] != 0)) &&
           ((local_cc[*(byte *)(iVar5 + 0x3f)] == 0xf ||
            ((local_cc[*(byte *)(iVar5 + 0x3f)] & 8) == 0))))) {
      uVar4 = uVar4 + 1;
      uVar1 = 2;
    }
    if (param_3 == 0x21) {
      if ((iVar2 != 0) || (local_cc[0] == 0)) {
        bcopy((void *)(param_1 + 0x68),local_cc,0xb);
      }
      bcopy(local_cc,param_2,0xb);
      param_2 = param_2 + 0xb;
      iVar5 = 0xb;
      do {
        if (param_2[-1] != ' ') break;
        param_2 = param_2 + -1;
        *param_2 = '\0';
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      uVar1 = 0;
    }
    else if ((iVar2 == 0) || (uVar4 < *(uint *)(iVar5 + 0x50))) {
      bzero(local_cc,0x20);
      bfill(local_cc,(uint)*(byte *)(iVar5 + 0x3d) + (uint)*(byte *)(iVar5 + 0x3e),0x20);
      sVar3 = strlen(param_2);
      if (sVar3 < 0xc) {
        sVar3 = strlen(param_2);
      }
      else {
        sVar3 = 0xb;
      }
      bcopy(param_2,local_cc,sVar3);
      local_cc[*(byte *)(iVar5 + 0x3f)] = 8;
      uVar1 = FUN_300d97b0(&local_64,0x20,local_cc,0x81);
    }
    else {
      errnoSet(DAT_300db45c);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300db1c4 @ 0x300DB1C4  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: memPartFree, semGive, semTake
 * Константы: 0x300DB1C4, 0xFFFFFFFF
 * Данные: DAT_300db60c
 * ---------------------------------------------------------------- */
void FUN_300db1c4(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 == 0) {
    return;
  }
  semTake(*(undefined4 *)(iVar1 + 0x34),0xffffffff);
  if (*(int *)(iVar1 + 0x30) != 0) {
    memPartFree(*DAT_300db60c);
    *(undefined4 *)(iVar1 + 0x30) = 0;
  }
  semGive(*(undefined4 *)(iVar1 + 0x34));
  return;
}

/* ----------------------------------------------------------------
 * FUN_300db20c @ 0x300DB20C  (примерный размер ~940 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 12
 * Вызывает: __udiv32, bcmp, bzero, dosFsXbdBytesRW, dosfsDiskToHost16, dosfsDiskToHost32, errnoSet, logMsg, memPartAlloc, memPartRealloc, semMCreate, time
 * Константы: 0xFFFFFFFF, 0x300DB20C
 * Данные: DAT_300db5ec, DAT_300db60c, DAT_300db610, DAT_300db614, DAT_300db618, DAT_300db61c, DAT_300db620, DAT_300db624
 * ---------------------------------------------------------------- */
undefined4 FUN_300db20c(int param_1)

{
  int iVar1;
  void *__s;
  undefined4 uVar2;
  uint uVar3;
  time_t tVar4;
  undefined2 uVar5;
  code *pcVar6;
  undefined4 *puVar7;
  undefined1 auStack_a0 [3];
  undefined1 auStack_9d [14];
  undefined1 auStack_8f [27];
  undefined1 auStack_74 [84];
  
  if (*(ushort *)(param_1 + 0x5c) < 0x81) {
    uVar5 = *(undefined2 *)(param_1 + 0x5c);
  }
  else {
    uVar5 = 0x80;
  }
  iVar1 = dosFsXbdBytesRW(param_1,*(undefined4 *)(param_1 + 0x48),0,0,auStack_a0,uVar5,0);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    pcVar6 = *(code **)(*(int *)(param_1 + 0x2c) + 0x18);
    if (DAT_300db610 == pcVar6) goto LAB_300db2c4;
    if (pcVar6 != (code *)0x0) {
      (*pcVar6)(param_1);
    }
  }
  __s = (void *)memPartRealloc(*DAT_300db60c,*(undefined4 *)(param_1 + 0x2c),0x58);
  *(void **)(param_1 + 0x2c) = __s;
  if (__s == (void *)0x0) {
    return 0xffffffff;
  }
  bzero(__s,0x58);
LAB_300db2c4:
  puVar7 = *(undefined4 **)(param_1 + 0x2c);
  iVar1 = bcmp(auStack_9d,DAT_300db614,5);
  if (iVar1 == 0) {
    if (*DAT_300db5ec != 0) {
      logMsg(DAT_300db618,0,0,0,0,0,0);
    }
    errnoSet(DAT_300db61c);
    uVar2 = 0xffffffff;
  }
  else {
    puVar7[0xe] = 0;
    *(undefined1 *)(puVar7 + 0xf) = 0x20;
    *(undefined1 *)((int)puVar7 + 0x3d) = 8;
    *(undefined1 *)((int)puVar7 + 0x3e) = 3;
    *(undefined1 *)((int)puVar7 + 0x3f) = 0xb;
    *(undefined1 *)(puVar7 + 0x10) = 0xe;
    *(undefined1 *)((int)puVar7 + 0x41) = 0x10;
    *(undefined1 *)(puVar7 + 0x11) = 0xff;
    *(undefined1 *)((int)puVar7 + 0x45) = 0x12;
    *(undefined1 *)((int)puVar7 + 0x42) = 0x16;
    *(undefined1 *)((int)puVar7 + 0x43) = 0x18;
    *(undefined1 *)((int)puVar7 + 0x46) = 0x1a;
    *(undefined1 *)((int)puVar7 + 0x47) = 0x14;
    *(undefined1 *)(puVar7 + 0x12) = 0x1c;
    *(undefined1 *)((int)puVar7 + 0x49) = 0xff;
    *(undefined1 *)((int)puVar7 + 0x4a) = 0xff;
    if ((int)((uint)*(ushort *)(param_1 + 0x5e) << *(sbyte *)(param_1 + 0x84)) < 0x20) {
      if (*DAT_300db5ec != 0) {
        logMsg(DAT_300db620,(uint)*(ushort *)(param_1 + 0x5e) << *(sbyte *)(param_1 + 0x84),0x20,0,0
               ,0,0);
      }
      errnoSet(DAT_300db624);
      uVar2 = 0xffffffff;
    }
    else {
      if (*(int *)(param_1 + 0x74) == 2) {
        uVar3 = dosfsDiskToHost32(auStack_74);
        puVar7[0x13] = uVar3;
        if (uVar3 < 2) {
          if (*DAT_300db5ec != 0) {
            logMsg(DAT_300db628,uVar3,0,0,0,0,0);
          }
          errnoSet(DAT_300db624);
          return 0xffffffff;
        }
        puVar7[10] = 0;
        puVar7[0xb] = 0;
        puVar7[0x14] = 0xffffffff;
      }
      else {
        uVar3 = dosfsDiskToHost16(auStack_8f);
        uVar3 = uVar3 & 0xffff;
        puVar7[0x14] = uVar3;
        if (uVar3 == 0) {
          if (*DAT_300db5ec != 0) {
            logMsg(DAT_300db62c,0,0,0,0,0,0);
          }
          errnoSet(DAT_300db624);
          return 0xffffffff;
        }
        puVar7[0x13] = 0;
        iVar1 = __udiv32(uVar3 * *(byte *)(puVar7 + 0xf) + (uint)*(ushort *)(param_1 + 0x5c) + -1);
        puVar7[0xb] = iVar1;
        puVar7[10] = *(undefined4 *)(param_1 + 0x78);
        *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + iVar1;
      }
      tVar4 = time((time_t *)0x0);
      puVar7[0x15] = tVar4;
      *puVar7 = DAT_300db630;
      puVar7[1] = DAT_300db634;
      puVar7[2] = DAT_300db638;
      puVar7[3] = DAT_300db63c;
      puVar7[4] = DAT_300db640;
      puVar7[5] = 0;
      puVar7[6] = DAT_300db610;
      puVar7[7] = *DAT_300db644;
      puVar7[8] = DAT_300db648;
      puVar7[9] = DAT_300db64c;
      if (puVar7[0xc] == 0) {
        iVar1 = memPartAlloc(*DAT_300db60c,DAT_300db650);
        puVar7[0xc] = iVar1;
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        uVar2 = semMCreate(*DAT_300db654);
        puVar7[0xd] = uVar2;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * dosVDirLibInit @ 0x300DB5B8  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: dosFsHdlrInstall
 * Вызывают: FUN_3003fb10
 * Константы: 0x300DB5B8
 * Данные: DAT_300db658, DAT_300db65c
 * ---------------------------------------------------------------- */
void dosVDirLibInit(void)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 1;
  local_c = DAT_300db658;
  local_8 = 0;
  dosFsHdlrInstall(DAT_300db65c,&local_10);
  return;
}

/* ----------------------------------------------------------------
 * dosFsShowInit @ 0x300DB660  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrIosExtraInit
 * Константы: 0x300DB660
 * Данные: DAT_300dc630, DAT_300dc634, DAT_300dc638, DAT_300dc63c, DAT_300dc640, DAT_300dc644, DAT_300dc648, DAT_300dc64c
 * ---------------------------------------------------------------- */
void dosFsShowInit(void)

{
  *DAT_300dc634 = DAT_300dc630;
  *DAT_300dc63c = DAT_300dc638;
  *DAT_300dc644 = DAT_300dc640;
  *DAT_300dc64c = DAT_300dc648;
  return;
}

/* ----------------------------------------------------------------
 * dosFsShow @ 0x300DB694  (примерный размер ~2004 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 10
 * Вызывает: dosFsClose, dosFsFdFree, dosFsFdGet, dosFsIoctl, dosFsOpen, dosFsVolDescGet, print64Fine, print64Mult, printf, puts
 * Вызывают: TFUP_dosFsDevCreate, sdmmcGetDosFsDevName
 * Константы: 0x300DB694, 0xFFFFFFFF
 * Данные: DAT_300dc650, DAT_300dc654, DAT_300dc658, DAT_300dc65c, DAT_300dc660, DAT_300dc664, DAT_300dc668, DAT_300dc6fc
 * ---------------------------------------------------------------- */
undefined4 dosFsShow(undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  code *pcVar11;
  int iVar12;
  undefined4 uVar13;
  char local_2c [12];
  
  iVar3 = 0xc;
  pcVar2 = local_2c;
  pcVar5 = DAT_300dc650;
  do {
    iVar3 = iVar3 + -1;
    *pcVar2 = *pcVar5;
    pcVar2 = pcVar2 + 1;
    pcVar5 = pcVar5 + 1;
  } while (iVar3 != 0);
  iVar3 = dosFsVolDescGet(param_1,0);
  if (iVar3 == 0) {
    if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
      puts(DAT_300dc658);
    }
    return 0xffffffff;
  }
  iVar1 = dosFsOpen(iVar3,DAT_300dc65c,0,0);
  if (iVar1 != -1) {
    dosFsClose(iVar1);
  }
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    printf(DAT_300dc660,iVar3,*(undefined4 *)(iVar3 + 0x28));
  }
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    printf(DAT_300dc664);
  }
  if (*(byte *)(iVar3 + 0x8c) == 0) {
    if ((*DAT_300dc654 == 0) || (pcVar2 = DAT_300dc668, 1 < *DAT_300dc654)) goto LAB_300db844;
  }
  else {
    if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
      uVar13 = DAT_300dc6fc;
      if ((*(byte *)(iVar3 + 0x8c) & 1) == 0) {
        uVar13 = DAT_300dc700;
      }
      printf(DAT_300dc704,uVar13);
    }
    if ((((*(byte *)(iVar3 + 0x8c) & 8) != 0) && (*DAT_300dc654 != 0)) && (*DAT_300dc654 < 2)) {
      printf(DAT_300dc708);
    }
    if ((*DAT_300dc654 == 0) || (1 < *DAT_300dc654)) goto LAB_300db844;
    pcVar2 = DAT_300dc70c;
    if ((*(char *)(iVar3 + 0x8d) != -1) &&
       (pcVar2 = DAT_300dc710, *(char *)(iVar3 + 0x8d) != '\x01')) {
      pcVar2 = DAT_300dc714;
    }
  }
  puts(pcVar2);
LAB_300db844:
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    printf(DAT_300dc718);
  }
  if (*(uint *)(iVar3 + 0x9c) == 0) {
    if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
      puts(DAT_300dc7b0);
    }
  }
  else {
    if ((((*(uint *)(iVar3 + 0x9c) & 0x10000) != 0) && (*DAT_300dc654 != 0)) && (*DAT_300dc654 < 2))
    {
      printf(DAT_300dc7b4);
    }
    if ((((*(uint *)(iVar3 + 0x9c) & 0x20000) != 0) && (*DAT_300dc654 != 0)) && (*DAT_300dc654 < 2))
    {
      printf(DAT_300dc7b8);
    }
    if ((((*(uint *)(iVar3 + 0x9c) & 0x40000) != 0) && (*DAT_300dc654 != 0)) && (*DAT_300dc654 < 2))
    {
      printf(DAT_300dc7bc);
    }
    if ((((*(uint *)(iVar3 + 0x9c) & 0x80000) != 0) && (*DAT_300dc654 != 0)) && (*DAT_300dc654 < 2))
    {
      printf(DAT_300dc7c0);
    }
    if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
      printf(DAT_300dc7c4,*(undefined4 *)(iVar3 + 0x9c));
    }
  }
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    printf(DAT_300dc7c8);
  }
  pcVar2 = DAT_300dc7d0;
  if ((*(uint *)(iVar3 + 0x1cc) & 1) != 0) {
    pcVar2 = DAT_300dc7cc;
  }
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    puts(pcVar2);
  }
  uVar6 = *(uint *)(iVar3 + 0x3c);
  iVar1 = (uint)*(ushort *)(iVar3 + 0x7c) * 0x48;
  iVar4 = *(int *)(iVar3 + 0x40);
  iVar12 = 0;
  iVar10 = 0;
  iVar7 = 0;
  iVar8 = 0;
  if (uVar6 < uVar6 + iVar1) {
    uVar9 = uVar6 + iVar1;
    do {
      iVar8 = iVar8 + (uint)(*(int *)(uVar6 + 0x44) != 0);
      if (*(short *)(iVar4 + 0x40) != 0) {
        iVar7 = iVar7 + 1;
        if ((*(uint *)(iVar4 + 8) & 2) == 0) {
          if ((*(uint *)(iVar4 + 8) & 1) != 0) {
            iVar10 = iVar10 + 1;
          }
        }
        else {
          iVar12 = iVar12 + 1;
        }
      }
      uVar6 = uVar6 + 0x48;
      iVar4 = iVar4 + 0x44;
    } while (uVar6 < uVar9);
  }
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    printf(DAT_300dc7d4,(uint)*(ushort *)(iVar3 + 0x7c));
  }
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    printf(DAT_300dc7d8,iVar8);
  }
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    printf(DAT_300dc7dc,iVar7);
  }
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    printf(DAT_300dc7e0,iVar10);
  }
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    printf(DAT_300dc7e4,iVar12);
  }
  iVar1 = *DAT_300dc654;
  if (*(int *)(iVar3 + 0x24) == 0) {
    if ((iVar1 != 0) && (iVar1 < 2)) {
      puts(DAT_300dc7e8);
    }
  }
  else {
    if ((iVar1 != 0) && (iVar1 < 2)) {
      puts(DAT_300dc7ec);
    }
    iVar1 = dosFsFdGet(iVar3);
    if (iVar1 != 0) {
      dosFsIoctl(iVar1,0x21,local_2c);
      dosFsFdFree(iVar1);
    }
    if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
      pcVar2 = DAT_300dc7f0;
      if (local_2c[0] != '\0') {
        pcVar2 = local_2c;
      }
      printf(DAT_300dc7f4,pcVar2,iVar3 + 0x68);
    }
    if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
      printf(DAT_300dc7f8,*(undefined4 *)(iVar3 + 0x4c));
    }
    print64Fine(DAT_300dc7fc,*(undefined4 *)(iVar3 + 0x58),0,DAT_300dc800,10);
    print64Mult(DAT_300dc804,*(undefined2 *)(iVar3 + 0x5c),0,DAT_300dc800,10);
    print64Mult(DAT_300dc808,*(undefined2 *)(iVar3 + 0x5e),0,DAT_300dc800,10);
    print64Mult(DAT_300dc80c,*(undefined2 *)(iVar3 + 0x60),0,DAT_300dc800,10);
    if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
      uVar13 = DAT_300dc810;
      if ((*(int *)(iVar3 + 0x74) != 0) && (uVar13 = DAT_300dc814, *(int *)(iVar3 + 0x74) != 1)) {
        uVar13 = DAT_300dc818;
      }
      printf(DAT_300dc81c,uVar13);
    }
    print64Mult(DAT_300dc820,*(undefined4 *)(iVar3 + 0x50),0,DAT_300dc800,10);
    if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
      printf(DAT_300dc824,(uint)*(byte *)(iVar3 + 0x62));
    }
    print64Mult(DAT_300dc828,*(undefined4 *)(iVar3 + 0x54),0,DAT_300dc800,10);
    print64Mult(DAT_300dc82c,*(undefined4 *)(iVar3 + 0x78),0,DAT_300dc800,10);
    if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
      uVar13 = DAT_300dc830;
      if (*(int *)(iVar3 + 0x94) != 0) {
        uVar13 = DAT_300dc834;
      }
      printf(DAT_300dc838,uVar13);
    }
  }
  if ((*(int *)(iVar3 + 0x2c) != 0) &&
     (pcVar11 = *(code **)(*(int *)(iVar3 + 0x2c) + 0x1c), pcVar11 != (code *)0x0)) {
    (*pcVar11)(iVar3);
  }
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    puts(DAT_300dc7d0);
  }
  if ((*(int *)(iVar3 + 0x30) != 0) &&
     (pcVar11 = *(code **)(*(int *)(iVar3 + 0x30) + 0x20), pcVar11 != (code *)0x0)) {
    (*pcVar11)(iVar3);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300dbe68 @ 0x300DBE68  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: print64Fine, printf, puts
 * Константы: 0x300DBE68
 * Данные: DAT_300dc654, DAT_300dc83c, DAT_300dc840, DAT_300dc844, DAT_300dc848, DAT_300dc84c, DAT_300dc850
 * ---------------------------------------------------------------- */
void FUN_300dbe68(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined8 uVar6;
  int local_5c [18];
  
  piVar1 = DAT_300dc654;
  iVar5 = *(int *)(param_1 + 0x30);
  iVar2 = 0x12;
  piVar3 = local_5c;
  piVar4 = DAT_300dc83c;
  do {
    iVar2 = iVar2 + -1;
    *piVar3 = *piVar4;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar2 != 0);
  local_5c[0] = param_1;
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    puts(DAT_300dc840);
  }
  iVar2 = *piVar1;
  if ((iVar2 != 0) && (iVar2 < 2)) {
    puts(DAT_300dc844);
  }
  iVar2 = *piVar1;
  if ((iVar2 != 0) && (iVar2 < 2)) {
    printf(DAT_300dc848,*(undefined4 *)(iVar5 + 0x74));
  }
  uVar6 = (**(code **)(iVar5 + 0x10))(local_5c);
  print64Fine(DAT_300dc84c,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300dc850,10);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300dbf30 @ 0x300DBF30  (примерный размер ~260 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: printf, puts
 * Константы: 0x300DBF30
 * Данные: DAT_300dc654, DAT_300dc854, DAT_300dc858, DAT_300dc85c, DAT_300dc860, DAT_300dc864, DAT_300dc868, DAT_300dc86c
 * ---------------------------------------------------------------- */
void FUN_300dbf30(int param_1)

{
  int *piVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_300dc654;
  iVar3 = *(int *)(param_1 + 0x2c);
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    puts(DAT_300dc854);
  }
  if ((*piVar1 != 0) && (*piVar1 < 2)) {
    uVar2 = DAT_300dc858;
    if (*(int *)(param_1 + 0xa0) == 0) {
      uVar2 = DAT_300dc85c;
    }
    printf(DAT_300dc860,uVar2);
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    return;
  }
  if (*(int *)(iVar3 + 0x28) == 0) {
    if (*piVar1 == 0) {
      return;
    }
    if (1 < *piVar1) {
      return;
    }
    uVar2 = *(undefined4 *)(iVar3 + 0x4c);
    __format = DAT_300dc870;
  }
  else {
    if ((*piVar1 != 0) && (*piVar1 < 2)) {
      printf(DAT_300dc864,*(int *)(iVar3 + 0x28));
    }
    if ((*piVar1 != 0) && (*piVar1 < 2)) {
      printf(DAT_300dc868,*(undefined4 *)(iVar3 + 0x2c));
    }
    if (*piVar1 == 0) {
      return;
    }
    if (1 < *piVar1) {
      return;
    }
    uVar2 = *(undefined4 *)(iVar3 + 0x50);
    __format = DAT_300dc86c;
  }
  printf(__format,uVar2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300dc034 @ 0x300DC034  (примерный размер ~232 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x300DC034
 * Данные: DAT_300dc654, DAT_300dc874, DAT_300dc878, DAT_300dc87c, DAT_300dc880, DAT_300dc884, DAT_300dc888, DAT_300dc88c
 * ---------------------------------------------------------------- */
void FUN_300dc034(int param_1)

{
  int *piVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_300dc654;
  iVar3 = *(int *)(param_1 + 0x2c);
  if (*(int *)(param_1 + 0x24) == 0) {
    return;
  }
  if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
    uVar2 = DAT_300dc874;
    if (*(int *)(iVar3 + 0x38) != 0) {
      uVar2 = DAT_300dc878;
    }
    printf(DAT_300dc87c,uVar2);
  }
  if (*(int *)(iVar3 + 0x28) == 0) {
    if (*piVar1 == 0) {
      return;
    }
    if (1 < *piVar1) {
      return;
    }
    uVar2 = *(undefined4 *)(iVar3 + 0x4c);
    __format = DAT_300dc88c;
  }
  else {
    if ((*piVar1 != 0) && (*piVar1 < 2)) {
      printf(DAT_300dc880);
    }
    if ((*piVar1 != 0) && (*piVar1 < 2)) {
      printf(DAT_300dc884,*(undefined4 *)(iVar3 + 0x2c));
    }
    if (*piVar1 == 0) {
      return;
    }
    if (1 < *piVar1) {
      return;
    }
    uVar2 = *(undefined4 *)(iVar3 + 0x50);
    __format = DAT_300dc888;
  }
  printf(__format,uVar2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300dc11c @ 0x300DC11C  (примерный размер ~776 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: __udiv32, print64Fine, printf, puts
 * Вызывают: dosFsCacheShow
 * Константы: 0x300DC11C
 * Данные: DAT_300dc654, DAT_300dc800, DAT_300dc890, DAT_300dc894, DAT_300dc898, DAT_300dc89c, DAT_300dc8a0, DAT_300dc8a4
 * ---------------------------------------------------------------- */
void FUN_300dc11c(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar2 = 0;
  iVar3 = 0;
  if ((*param_4 == 0) || (param_4[1] == 0)) {
    if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
      printf(DAT_300dc890,param_2);
    }
  }
  else {
    iVar6 = param_4[0xe];
    uVar5 = 0;
    if (iVar6 + param_4[0xf] != 0) {
      uVar5 = __udiv32(iVar6 * 100,iVar6 + param_4[0xf]);
    }
    piVar1 = DAT_300dc654;
    if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
      printf(DAT_300dc894,param_2,*param_4,param_4[0xd],param_4[1],iVar6,param_4[0xf],uVar5,
             param_4[0xb],param_4[0xc]);
    }
    if (param_1 != 0) {
      if ((*piVar1 != 0) && (*piVar1 < 2)) {
        printf(DAT_300dc898,param_2);
      }
      if (param_4[7] != 0) {
        do {
          iVar6 = *(int *)(param_4[6] + uVar2 * 4);
          if (iVar6 != 0) {
            if ((*piVar1 != 0) && (*piVar1 < 2)) {
              printf(DAT_300dc89c,uVar2);
            }
            print64Fine(DAT_300dc8a0,*(undefined4 *)(iVar6 + 0x14),0,DAT_300dc800,0x10);
            for (; iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
              if (*(int *)(iVar6 + 8) != 0) {
                if ((*piVar1 != 0) && (*piVar1 < 2)) {
                  printf(DAT_300dc8a4);
                }
                print64Fine(DAT_300dc8a0,*(undefined4 *)(*(int *)(iVar6 + 8) + 0x14),0,DAT_300dc800,
                            0x10);
              }
            }
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < (uint)param_4[7]);
      }
      if ((*piVar1 != 0) && (*piVar1 < 2)) {
        printf(DAT_300dc8a8,param_2);
      }
      for (puVar4 = (undefined4 *)param_4[2]; puVar4 != (undefined4 *)0x0;
          puVar4 = (undefined4 *)*puVar4) {
        if (puVar4[5] == -1) {
          iVar3 = iVar3 + 1;
        }
        else {
          print64Fine(DAT_300dc8ac,puVar4[5],0,DAT_300dc8b0,0x10);
        }
      }
      if ((*piVar1 != 0) && (*piVar1 < 2)) {
        printf(DAT_300dc8b4,iVar3);
      }
      if ((*piVar1 != 0) && (*piVar1 < 2)) {
        puts(DAT_300dc8b8);
      }
      for (puVar4 = (undefined4 *)param_4[4]; puVar4 != (undefined4 *)0x0;
          puVar4 = (undefined4 *)*puVar4) {
        if (puVar4[5] == -1) {
          if ((*piVar1 != 0) && (*piVar1 < 2)) {
            printf(DAT_300dc8bc);
          }
        }
        else {
          print64Fine(DAT_300dc8ac,puVar4[5],0,DAT_300dc8b0,0x10);
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * dosFsCacheShow @ 0x300DC424  (примерный размер ~216 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300dc11c, dosFsVolDescGet, printf, puts
 * Константы: 0x300DC424
 * Данные: DAT_300dc654, DAT_300dc8c0, DAT_300dc8c4, DAT_300dc8c8, DAT_300dc8cc, DAT_300dc8d0, DAT_300dc8d4
 * ---------------------------------------------------------------- */
void dosFsCacheShow(undefined4 param_1,undefined4 param_2)

{
  char *__s;
  int *piVar1;
  int iVar2;
  
  iVar2 = dosFsVolDescGet(param_1,0);
  piVar1 = DAT_300dc654;
  if (iVar2 == 0) {
    if (*DAT_300dc654 == 0) {
      return;
    }
    if (1 < *DAT_300dc654) {
      return;
    }
    puts(DAT_300dc8c0);
  }
  else {
    if ((*DAT_300dc654 != 0) && (*DAT_300dc654 < 2)) {
      printf(DAT_300dc8c4,param_1);
    }
    __s = DAT_300dc8cc;
    if ((*(uint *)(iVar2 + 0x1cc) & 1) != 0) {
      __s = DAT_300dc8c8;
    }
    if ((*piVar1 != 0) && (*piVar1 < 2)) {
      puts(__s);
    }
    FUN_300dc11c(param_2,DAT_300dc8d0,iVar2,iVar2 + 0xc4);
    FUN_300dc11c(param_2,DAT_300dc8d4,iVar2,iVar2 + 0x148);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300dc4fc @ 0x300DC4FC  (примерный размер ~444 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: __lsl64, __mul64, print64Fine, print64Mult
 * Константы: 0x300DC4FC
 * Данные: DAT_300dc800, DAT_300dc850, DAT_300dc8d8, DAT_300dc8dc, DAT_300dc8e0, DAT_300dc8e4, DAT_300dc8e8, DAT_300dc8ec
 * ---------------------------------------------------------------- */
void FUN_300dc4fc(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar2 = *param_1;
  iVar3 = *(int *)(iVar2 + 0x88);
  if (*(char *)(iVar2 + 0x8f) != '\0') {
    print64Fine(DAT_300dc8d8,*(undefined4 *)(iVar2 + 100),0,DAT_300dc800,10);
    print64Fine(DAT_300dc8dc,*(undefined4 *)(iVar3 + 0x138),0,DAT_300dc800,10);
    print64Fine(DAT_300dc8e0,*(undefined4 *)(iVar3 + 0x13c),0,DAT_300dc800,10);
    uVar4 = __mul64(*(undefined4 *)(iVar3 + 0x138),0,*(undefined2 *)(iVar2 + 0x5e),0);
    uVar4 = __lsl64((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),*(undefined1 *)(iVar2 + 0x84));
    print64Mult(DAT_300dc8e4,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20),DAT_300dc800,10);
    uVar1 = (**(code **)(*(int *)(iVar2 + 0x30) + 0x18))(param_1);
    uVar4 = __lsl64(uVar1,0,*(undefined1 *)(iVar2 + 0x84));
    print64Fine(DAT_300dc8e8,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20),DAT_300dc850,10);
    print64Fine(DAT_300dc8ec,*(undefined4 *)(iVar3 + 0x130),0,DAT_300dc800,10);
    print64Fine(DAT_300dc8f0,*(undefined4 *)(iVar3 + 300),0,DAT_300dc800,10);
    print64Mult(DAT_300dc8f4,*(undefined4 *)(iVar3 + 0x118),*(undefined4 *)(iVar3 + 0x11c),
                DAT_300dc800,10);
    print64Fine(DAT_300dc8f8,*(undefined4 *)(iVar3 + 0x134),0,DAT_300dc800,10);
    print64Mult(DAT_300dc8fc,*(undefined4 *)(iVar3 + 0x120),*(undefined4 *)(iVar3 + 0x124),
                DAT_300dc800,10);
  }
  return;
}

/* ----------------------------------------------------------------
 * dosFsTCacheShow @ 0x300DC6B8  (примерный размер ~604 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: __udiv32, dosFsVolDescGet, printf, puts
 * Константы: 0x300DC6B8
 * Данные: DAT_300dc900, DAT_300dc904, DAT_300dc908, DAT_300dc90c, DAT_300dc910
 * ---------------------------------------------------------------- */
void dosFsTCacheShow(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar2 = dosFsVolDescGet(param_1,0);
  piVar1 = DAT_300dc900;
  if (iVar2 == 0) {
    if (*DAT_300dc900 == 0) {
      return;
    }
    if (1 < *DAT_300dc900) {
      return;
    }
    puts(DAT_300dc904);
  }
  else {
    if ((*DAT_300dc900 != 0) && (*DAT_300dc900 < 2)) {
      printf(DAT_300dc908,param_1);
    }
    iVar4 = *piVar1;
    if ((iVar4 != 0) && (iVar4 < 2)) {
      printf(DAT_300dc90c,1);
    }
    iVar4 = *piVar1;
    if (iVar4 == 0) {
      return;
    }
    if (1 < iVar4) {
      return;
    }
    iVar4 = *(int *)(iVar2 + 0x1f0);
    uVar5 = *(undefined4 *)(iVar2 + 0x1ec);
    uVar3 = __udiv32(iVar4 * 100,uVar5);
    printf(DAT_300dc910,uVar5,iVar4,uVar3);
  }
  return;
}

/* ----------------------------------------------------------------
 * partLibCreate @ 0x300DC914  (примерный размер ~1396 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 12
 * Вызывает: __errno, __mul64, __udiv32, bzero, free, ioctl, lseek, malloc, printErr, printf, read, write
 * Вызывают: xbdCreatePartition
 * Константы: 0xFFFFFFFF, 0x300DC914, 0x00400000
 * Данные: DAT_300dd8cc, DAT_300dd8d0, DAT_300dd8d4, DAT_300dd8d8, DAT_300dd8dc, DAT_300dd8e0, DAT_300dd8e4
 * ---------------------------------------------------------------- */
undefined4 partLibCreate(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  void *__s;
  undefined4 uVar5;
  __off_t _Var6;
  size_t sVar7;
  int iVar8;
  undefined4 *puVar9;
  byte bVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  undefined8 uVar14;
  int local_ac;
  int local_a8;
  undefined8 local_8c;
  int local_84 [3];
  int local_78;
  uint local_74;
  size_t local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60 [5];
  int local_4c;
  int local_3c;
  int local_2c;
  
  iVar8 = 0x10;
  puVar2 = &local_68;
  puVar9 = DAT_300dd8cc;
  do {
    iVar8 = iVar8 + -1;
    *puVar2 = *puVar9;
    puVar2 = puVar2 + 1;
    puVar9 = puVar9 + 1;
  } while (iVar8 != 0);
  iVar8 = ioctl(param_1,DAT_300dd8d0,local_84);
  uVar13 = DAT_300dd8d8;
  if (iVar8 != 0) {
    return 0xffffffff;
  }
  local_ac = local_78;
  if (local_78 == 0) {
    local_ac = 1;
  }
  local_a8 = local_84[0] * local_ac;
  if (local_74 < (uint)(local_ac * 4)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x16;
    printf(DAT_300dd8d4,local_74);
    return 0xffffffff;
  }
  if (0x3e < local_ac - 1U) {
    local_ac = 0x40;
    local_a8 = local_84[0] << 6;
  }
  if (local_a8 == 0) {
    local_a8 = local_ac;
  }
  uVar3 = __udiv32(local_74,local_a8);
  while (uVar13 < uVar3) {
    local_a8 = local_a8 << 1;
    uVar3 = __udiv32(local_74);
  }
  iVar4 = __udiv32(local_74,local_ac);
  iVar12 = iVar4 + -1;
  iVar8 = iVar12;
  if (param_2 == 2) {
LAB_300dcaa4:
    uVar14 = __udiv32(iVar12,100);
    local_4c = param_3 * (int)uVar14;
    iVar12 = iVar8 - local_4c;
  }
  else {
    if (2 < param_2) {
      if (param_2 != 3) {
        if (param_2 != 4) goto LAB_300dcadc;
        local_2c = __udiv32(iVar12,100);
        local_2c = param_5 * local_2c;
        iVar8 = iVar12 - local_2c;
      }
      local_3c = __udiv32(iVar12,100);
      local_3c = param_4 * local_3c;
      iVar8 = iVar8 - local_3c;
      goto LAB_300dcaa4;
    }
    uVar14 = CONCAT44(2,iVar4);
    if ((param_2 != 0) && (uVar14 = CONCAT44(2,iVar4), param_2 != 1)) goto LAB_300dcadc;
  }
  if (iVar12 == 0) {
    puVar2 = (undefined4 *)__errno((int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
    *puVar2 = 0x16;
    return 0xffffffff;
  }
  local_60[1] = iVar12;
LAB_300dcadc:
  sVar7 = local_6c;
  iVar4 = 1;
  piVar11 = &local_68;
  iVar8 = 4;
  do {
    iVar12 = piVar11[3];
    if (iVar12 != 0) {
      *piVar11 = local_ac * iVar4;
      iVar4 = iVar4 + iVar12;
      uVar13 = iVar12 * local_ac;
      piVar11[1] = uVar13;
      if (uVar13 < 0x400000) {
        if (uVar13 < 0x10000) {
          if (uVar13 < DAT_300dd8dc) {
            iVar12 = 1;
          }
          else {
            iVar12 = 4;
          }
        }
        else {
          iVar12 = 6;
        }
      }
      else {
        iVar12 = 0xc;
      }
      piVar11[2] = iVar12;
    }
    piVar11 = piVar11 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  __s = malloc(local_6c);
  if (__s == (void *)0x0) {
    printErr(DAT_300dd8e0);
    uVar5 = 0xffffffff;
  }
  else {
    bzero(__s,sVar7);
    puVar2 = &local_68;
    iVar8 = 4;
    do {
      if (puVar2[3] != 0) {
        uVar14 = __mul64(*puVar2,0);
        local_8c = uVar14;
        iVar4 = ioctl(param_1,0x35,&local_8c,(int)((ulonglong)uVar14 >> 0x20));
        if (iVar4 == -1) {
          return 0xffffffff;
        }
        write(param_1,__s,local_6c);
      }
      puVar2 = puVar2 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    _Var6 = lseek(param_1,0,0);
    if (_Var6 == 0) {
      uVar13 = read(param_1,__s,local_6c);
      if (local_6c == uVar13) {
        *(undefined1 *)((int)__s + 0x1fe) = 0x55;
        *(undefined1 *)((int)__s + 0x1ff) = 0xaa;
        if (0x200 < local_6c) {
          *(undefined1 *)((int)__s + (local_6c - 2)) = 0x55;
          *(undefined1 *)((int)__s + (local_6c - 1)) = 0xaa;
        }
        uVar13 = 0;
        piVar11 = &local_68;
        do {
          iVar8 = DAT_300dd8e4 + uVar13 * 0x10;
          *(char *)((int)__s + iVar8) = (uVar13 == 0) << 7;
          *(char *)((int)__s + iVar8 + 4) = (char)piVar11[2];
          *(char *)((int)__s + iVar8 + 0xc) = (char)piVar11[1];
          *(char *)((int)__s + iVar8 + 0xd) = (char)((uint)piVar11[1] >> 8);
          *(char *)((int)__s + iVar8 + 0xe) = (char)*(undefined2 *)((int)piVar11 + 6);
          *(undefined1 *)((int)__s + iVar8 + 0xf) = *(undefined1 *)((int)piVar11 + 7);
          *(char *)((int)__s + iVar8 + 8) = (char)*piVar11;
          *(char *)((int)__s + iVar8 + 9) = (char)((uint)*piVar11 >> 8);
          *(char *)((int)__s + iVar8 + 10) = (char)*(undefined2 *)((int)piVar11 + 2);
          *(undefined1 *)((int)__s + iVar8 + 0xb) = *(undefined1 *)((int)piVar11 + 3);
          if (piVar11[1] == 0) {
            bVar10 = 0;
            cVar1 = '\0';
            iVar4 = 0;
          }
          else {
            iVar12 = *piVar11;
            iVar4 = __udiv32(iVar12,local_a8);
            cVar1 = __udiv32(iVar12 - local_a8 * iVar4,local_ac);
            bVar10 = (((char)iVar12 - (char)(local_a8 * iVar4)) - (char)local_ac * cVar1) + 1;
          }
          *(char *)((int)__s + iVar8 + 3) = (char)iVar4;
          *(byte *)((int)__s + iVar8 + 2) = bVar10 | (byte)(iVar4 >> 2) & 0xc0;
          *(char *)((int)__s + iVar8 + 1) = cVar1;
          if (piVar11[1] == 0) {
            bVar10 = 0;
            cVar1 = '\0';
            iVar4 = 0;
          }
          else {
            iVar12 = *piVar11 + piVar11[1] + -1;
            iVar4 = __udiv32(iVar12,local_a8);
            cVar1 = __udiv32(iVar12 - local_a8 * iVar4,local_ac);
            bVar10 = (((char)iVar12 - (char)(local_a8 * iVar4)) - (char)local_ac * cVar1) + 1;
          }
          uVar13 = uVar13 + 1;
          *(char *)((int)__s + iVar8 + 7) = (char)iVar4;
          *(byte *)((int)__s + iVar8 + 6) = bVar10 | (byte)(iVar4 >> 2) & 0xc0;
          *(char *)((int)__s + iVar8 + 5) = cVar1;
          piVar11 = piVar11 + 4;
        } while (uVar13 < 4);
        _Var6 = lseek(param_1,0,0);
        if (_Var6 == 0) {
          sVar7 = write(param_1,__s,local_6c);
          if (local_6c == sVar7) {
            free(__s);
            uVar5 = 0;
          }
          else {
            free(__s);
            uVar5 = 0xffffffff;
          }
        }
        else {
          free(__s);
          uVar5 = 0xffffffff;
        }
      }
      else {
        free(__s);
        uVar5 = 0xffffffff;
      }
    }
    else {
      free(__s);
      uVar5 = 0xffffffff;
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * xbdCreatePartition @ 0x300DCE88  (примерный размер ~372 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 9
 * Вызывает: __errno, close, fsPathAddedEventSetup, fsWaitForPath, fsmNameMap, ioctl, open, partLibCreate, sprintf
 * Константы: 0x300DCE88
 * Данные: DAT_300dd8e8, DAT_300dd8ec, DAT_300dd8f0, DAT_300dd8f4
 * ---------------------------------------------------------------- */
int xbdCreatePartition(char *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_54 [8];
  undefined1 auStack_4c [12];
  char acStack_40 [12];
  char acStack_34 [24];
  
  if (param_2 < 5) {
    if (param_2 == 0) {
      param_2 = 1;
    }
    iVar2 = open(param_1,0,0);
    if (iVar2 < 0) {
      iVar2 = -1;
    }
    else {
      iVar3 = ioctl(iVar2,DAT_300dd8e8,auStack_4c);
      if (iVar3 == 0) {
        fsmNameMap(auStack_4c,acStack_34);
        fsPathAddedEventSetup(auStack_54,acStack_34);
        iVar3 = ioctl(iVar2,DAT_300dd8ec,2);
        if (iVar3 == 0) {
          fsWaitForPath(auStack_54);
          close(iVar2);
          iVar3 = open(acStack_34,2,0);
          if (iVar3 < 0) {
            iVar2 = -1;
          }
          else {
            iVar2 = partLibCreate(iVar3,param_2,param_3,param_4,param_5);
            if (iVar2 == 0) {
              sprintf(acStack_40,DAT_300dd8f0,acStack_34,param_2);
              fsmNameMap(acStack_40,acStack_34);
              fsPathAddedEventSetup(auStack_54,acStack_34);
              iVar4 = ioctl(iVar3,DAT_300dd8f4,2);
              if (iVar4 == -1) {
                close(iVar3);
                return -1;
              }
              fsWaitForPath(auStack_54);
            }
            close(iVar3);
          }
        }
        else {
          iVar2 = -1;
        }
      }
      else {
        iVar2 = -1;
      }
    }
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    iVar2 = -1;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * partLibCreateSz @ 0x300DCFFC  (примерный размер ~1332 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 12
 * Вызывает: __errno, __mul64, __udiv32, bzero, free, ioctl, lseek, malloc, printErr, printf, read, write
 * Вызывают: xbdCreatePartitionSz
 * Константы: 0xFFFFFFFF, 0x300DCFFC, 0x00400000
 * Данные: DAT_300dd8d0, DAT_300dd8d4, DAT_300dd8d8, DAT_300dd8dc, DAT_300dd8e0, DAT_300dd8e4, DAT_300dd8f8
 * ---------------------------------------------------------------- */
undefined4
partLibCreateSz(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  void *__s;
  undefined4 uVar5;
  __off_t _Var6;
  size_t sVar7;
  int iVar8;
  undefined4 *puVar9;
  byte bVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined8 uVar15;
  int local_ac;
  char local_a8;
  undefined8 local_8c;
  int local_84 [3];
  int local_78;
  uint local_74;
  size_t local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60 [5];
  int local_4c;
  int local_3c;
  int local_2c;
  
  iVar8 = 0x10;
  puVar2 = &local_68;
  puVar9 = DAT_300dd8f8;
  do {
    iVar8 = iVar8 + -1;
    *puVar2 = *puVar9;
    puVar2 = puVar2 + 1;
    puVar9 = puVar9 + 1;
  } while (iVar8 != 0);
  iVar8 = ioctl(param_1,DAT_300dd8d0,local_84);
  uVar14 = DAT_300dd8d8;
  if (iVar8 != 0) {
    return 0xffffffff;
  }
  if (local_78 == 0) {
    local_78 = 1;
  }
  local_ac = local_84[0] * local_78;
  if (local_74 < (uint)(local_78 * 4)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x16;
    printf(DAT_300dd8d4,local_74);
    return 0xffffffff;
  }
  iVar8 = local_78;
  if (0x3e < local_78 - 1U) {
    iVar8 = 0x40;
    local_ac = local_84[0] << 6;
  }
  if (local_ac == 0) {
    local_ac = iVar8;
  }
  while (uVar3 = __udiv32(local_74,local_ac), uVar14 < uVar3) {
    local_ac = local_ac << 1;
  }
  iVar4 = __udiv32(local_74,iVar8);
  iVar13 = iVar4 + -1;
  if (param_2 == 2) {
LAB_300dd160:
    uVar15 = __udiv32(param_3,iVar8);
    local_4c = (int)uVar15;
    iVar13 = iVar13 - (int)uVar15;
  }
  else {
    if (2 < param_2) {
      if (param_2 != 3) {
        if (param_2 != 4) goto LAB_300dd194;
        local_2c = __udiv32(param_5,iVar8);
        iVar13 = iVar13 - local_2c;
      }
      local_3c = __udiv32(param_4,iVar8);
      iVar13 = iVar13 - local_3c;
      goto LAB_300dd160;
    }
    uVar15 = CONCAT44(2,iVar4);
    if ((param_2 != 0) && (uVar15 = CONCAT44(2,iVar4), param_2 != 1)) goto LAB_300dd194;
  }
  if (iVar13 == 0) {
    puVar2 = (undefined4 *)__errno((int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
    *puVar2 = 0x16;
    return 0xffffffff;
  }
  local_60[1] = iVar13;
LAB_300dd194:
  sVar7 = local_6c;
  iVar13 = 1;
  piVar11 = &local_68;
  iVar4 = 4;
  do {
    iVar12 = piVar11[3];
    if (iVar12 != 0) {
      *piVar11 = iVar8 * iVar13;
      uVar14 = iVar12 * iVar8;
      piVar11[1] = uVar14;
      iVar13 = iVar13 + iVar12;
      if (uVar14 < 0x400000) {
        if (uVar14 < 0x10000) {
          if (uVar14 < DAT_300dd8dc) {
            iVar12 = 1;
          }
          else {
            iVar12 = 4;
          }
        }
        else {
          iVar12 = 6;
        }
      }
      else {
        iVar12 = 0xc;
      }
      piVar11[2] = iVar12;
    }
    piVar11 = piVar11 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  __s = malloc(local_6c);
  if (__s == (void *)0x0) {
    printErr(DAT_300dd8e0);
    uVar5 = 0xffffffff;
  }
  else {
    bzero(__s,sVar7);
    puVar2 = &local_68;
    iVar4 = 4;
    do {
      if (puVar2[3] != 0) {
        uVar15 = __mul64(*puVar2,0);
        local_8c = uVar15;
        iVar13 = ioctl(param_1,0x35,&local_8c,(int)((ulonglong)uVar15 >> 0x20));
        if (iVar13 == -1) {
          return 0xffffffff;
        }
        write(param_1,__s,local_6c);
      }
      puVar2 = puVar2 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    _Var6 = lseek(param_1,0,0);
    if (_Var6 == 0) {
      uVar14 = read(param_1,__s,local_6c);
      if (local_6c == uVar14) {
        *(undefined1 *)((int)__s + 0x1fe) = 0x55;
        *(undefined1 *)((int)__s + 0x1ff) = 0xaa;
        if (0x200 < local_6c) {
          *(undefined1 *)((int)__s + (local_6c - 2)) = 0x55;
          *(undefined1 *)((int)__s + (local_6c - 1)) = 0xaa;
        }
        uVar14 = 0;
        piVar11 = &local_68;
        do {
          iVar4 = DAT_300dd8e4 + uVar14 * 0x10;
          *(char *)((int)__s + iVar4) = (uVar14 == 0) << 7;
          *(char *)((int)__s + iVar4 + 4) = (char)piVar11[2];
          *(char *)((int)__s + iVar4 + 0xc) = (char)piVar11[1];
          *(char *)((int)__s + iVar4 + 0xd) = (char)((uint)piVar11[1] >> 8);
          *(char *)((int)__s + iVar4 + 0xe) = (char)*(undefined2 *)((int)piVar11 + 6);
          *(undefined1 *)((int)__s + iVar4 + 0xf) = *(undefined1 *)((int)piVar11 + 7);
          *(char *)((int)__s + iVar4 + 8) = (char)*piVar11;
          *(char *)((int)__s + iVar4 + 9) = (char)((uint)*piVar11 >> 8);
          *(char *)((int)__s + iVar4 + 10) = (char)*(undefined2 *)((int)piVar11 + 2);
          *(undefined1 *)((int)__s + iVar4 + 0xb) = *(undefined1 *)((int)piVar11 + 3);
          if (piVar11[1] == 0) {
            bVar10 = 0;
            local_a8 = '\0';
            iVar13 = 0;
          }
          else {
            iVar12 = *piVar11;
            iVar13 = __udiv32(iVar12,local_ac);
            local_a8 = __udiv32(iVar12 - local_ac * iVar13,iVar8);
            bVar10 = (((char)iVar12 - (char)(local_ac * iVar13)) - (char)iVar8 * local_a8) + 1;
          }
          *(char *)((int)__s + iVar4 + 3) = (char)iVar13;
          *(byte *)((int)__s + iVar4 + 2) = bVar10 | (byte)(iVar13 >> 2) & 0xc0;
          *(char *)((int)__s + iVar4 + 1) = local_a8;
          if (piVar11[1] == 0) {
            bVar10 = 0;
            cVar1 = '\0';
            iVar13 = 0;
          }
          else {
            iVar12 = *piVar11 + piVar11[1] + -1;
            iVar13 = __udiv32(iVar12,local_ac);
            cVar1 = __udiv32(iVar12 - local_ac * iVar13,iVar8);
            bVar10 = (((char)iVar12 - (char)(local_ac * iVar13)) - (char)iVar8 * cVar1) + 1;
          }
          uVar14 = uVar14 + 1;
          *(char *)((int)__s + iVar4 + 7) = (char)iVar13;
          *(byte *)((int)__s + iVar4 + 6) = bVar10 | (byte)(iVar13 >> 2) & 0xc0;
          *(char *)((int)__s + iVar4 + 5) = cVar1;
          piVar11 = piVar11 + 4;
        } while (uVar14 < 4);
        _Var6 = lseek(param_1,0,0);
        if (_Var6 == 0) {
          sVar7 = write(param_1,__s,local_6c);
          if (local_6c == sVar7) {
            free(__s);
            uVar5 = 0;
          }
          else {
            free(__s);
            uVar5 = 0xffffffff;
          }
        }
        else {
          free(__s);
          uVar5 = 0xffffffff;
        }
      }
      else {
        free(__s);
        uVar5 = 0xffffffff;
      }
    }
    else {
      free(__s);
      uVar5 = 0xffffffff;
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * xbdCreatePartitionSz @ 0x300DD530  (примерный размер ~972 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 11
 * Вызывает: __div64, __errno, __mul64, close, fsPathAddedEventSetup, fsWaitForPath, fsmNameMap, ioctl, open, partLibCreateSz, sprintf
 * Константы: 0x300DD530, 0x300DD70C, 0x300DD710
 * Данные: DAT_300dd8d0, DAT_300dd8e8, DAT_300dd8ec, DAT_300dd8f0, DAT_300dd8f4
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300dd70c) */
/* WARNING: Removing unreachable block (ram,0x300dd710) */

int xbdCreatePartitionSz(char *param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  int local_b0;
  int local_a8;
  undefined1 auStack_9c [12];
  undefined8 local_90;
  uint local_88;
  undefined4 local_84;
  undefined1 auStack_80 [12];
  char acStack_74 [12];
  char acStack_68 [24];
  undefined1 auStack_50 [16];
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  int local_c;
  
  local_b0 = 0;
  if (4 < param_2) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    return -1;
  }
  local_c = param_2;
  if (param_2 == 0) {
    local_c = 1;
  }
  if (local_c != 2) {
    if (local_c != 3) {
      if (local_c != 4) goto LAB_300dd620;
      if (param_5 == 0) {
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 0x16;
        return -1;
      }
      local_b0 = param_5;
    }
    if (param_4 == 0) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = 0x16;
      return -1;
    }
    local_b0 = local_b0 + param_4;
  }
  if (param_3 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    return -1;
  }
  local_b0 = local_b0 + param_3;
LAB_300dd620:
  iVar2 = open(param_1,0,0);
  if (iVar2 < 0) {
    local_a8 = -1;
  }
  else {
    iVar3 = ioctl(iVar2,DAT_300dd8e8,auStack_80);
    if (iVar3 == 0) {
      fsmNameMap(auStack_80,acStack_68);
      fsPathAddedEventSetup(auStack_9c,acStack_68);
      iVar3 = ioctl(iVar2,DAT_300dd8ec,2);
      if (iVar3 == 0) {
        fsWaitForPath(auStack_9c);
        close(iVar2);
        iVar2 = open(acStack_68,2,0);
        if (iVar2 < 0) {
          local_a8 = -1;
        }
        else {
          iVar3 = ioctl(iVar2,DAT_300dd8d0,auStack_50);
          if (iVar3 == 0) {
            if (local_38 < 0x400) {
              local_90._0_4_ = local_38;
              local_90._4_4_ = 0;
              local_88 = 0x400;
              local_84 = 0;
              local_90 = __div64(0x400,0,local_38,0);
              uVar7 = __div64(local_40,local_3c,(int)local_90,(int)((ulonglong)local_90 >> 0x20));
            }
            else {
              local_90._0_4_ = 0x400;
              local_90._4_4_ = 0;
              local_88 = local_38;
              local_84 = 0;
              local_90 = __div64(local_38,0);
              uVar7 = __mul64(local_40,local_3c,(int)local_90,(int)((ulonglong)local_90 >> 0x20));
            }
            iVar3 = __div64((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0x400,0);
            if (local_b0 < iVar3) {
              uVar4 = __div64(param_3 << 0x14,(param_3 << 0x14) >> 0x1f,local_38,0);
              uVar5 = __div64(param_4 << 0x14,(param_4 << 0x14) >> 0x1f,local_38,0);
              uVar6 = __div64(param_5 << 0x14,(param_5 << 0x14) >> 0x1f,local_38,0);
              local_a8 = partLibCreateSz(iVar2,local_c,uVar4,uVar5,uVar6);
              if (local_a8 == 0) {
                sprintf(acStack_74,DAT_300dd8f0,acStack_68,local_c);
                fsmNameMap(acStack_74,acStack_68);
                fsPathAddedEventSetup(auStack_9c,acStack_68);
                iVar3 = ioctl(iVar2,DAT_300dd8f4,2);
                if (iVar3 == -1) {
                  close(iVar2);
                  return -1;
                }
                fsWaitForPath(auStack_9c);
                local_a8 = 0;
              }
              close(iVar2);
            }
            else {
              close(iVar2);
              local_a8 = -1;
            }
          }
          else {
            close(iVar2);
            local_a8 = -1;
          }
        }
      }
      else {
        local_a8 = -1;
      }
    }
    else {
      close(iVar2);
      local_a8 = -1;
    }
  }
  return local_a8;
}

/* ----------------------------------------------------------------
 * xbdBlkDevLibInit @ 0x300DD8FC  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrIosExtraInit
 * Константы: 0x300DD8FC
 * Данные: DAT_300ddf88, DAT_300ddf8c
 * ---------------------------------------------------------------- */
undefined4 xbdBlkDevLibInit(undefined4 param_1,undefined4 param_2)

{
  *DAT_300ddf88 = param_1;
  *DAT_300ddf8c = param_2;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300dd914 @ 0x300DD914  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: xbdBlkDevCreate
 * Константы: 0x300DD914
 * ---------------------------------------------------------------- */
bool FUN_300dd914(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (*(code **)(param_1 + 0x10) == (code *)0x0) {
    bVar2 = true;
  }
  else {
    iVar1 = (**(code **)(param_1 + 0x10))(param_1);
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x30) == 0) {
        bVar2 = true;
      }
      else {
        *(undefined4 *)(param_1 + 0x30) = 0;
        (**(code **)(param_1 + 0x10))(param_1);
        bVar2 = *(int *)(param_1 + 0x30) == 0;
      }
    }
    else {
      bVar2 = false;
    }
  }
  return bVar2;
}

/* ----------------------------------------------------------------
 * xbdBlkDevCreate @ 0x300DD994  (примерный размер ~456 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 11
 * Вызывает: FUN_300dd914, erfEventRaise, erfHandlerRegister, free, malloc, semBCreate, semDelete, semMCreate, strncpy, taskSpawn, xbdAttach
 * Вызывают: TFUP_dosFsDevCreate, xbdBlkDevCreateSync
 * Константы: 0x300DD994
 * Данные: DAT_300ddf88, DAT_300ddf8c, DAT_300ddf90, DAT_300ddf94, DAT_300ddf98, DAT_300ddf9c, DAT_300ddfa0, DAT_300ddfa4
 * ---------------------------------------------------------------- */
undefined4 xbdBlkDevCreate(int param_1,char *param_2)

{
  void *__ptr;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  
  __ptr = malloc(0x60);
  if (__ptr == (void *)0x0) {
    return 0;
  }
  iVar1 = semMCreate(9);
  *(int *)((int)__ptr + 0x30) = iVar1;
  if (iVar1 == 0) goto LAB_300ddb48;
  iVar1 = semBCreate(1,0);
  *(int *)((int)__ptr + 0x38) = iVar1;
  if (iVar1 != 0) {
    iVar1 = semBCreate(1,0);
    *(int *)((int)__ptr + 0x5c) = iVar1;
    if (iVar1 != 0) {
      strncpy((char *)((int)__ptr + 0x44),param_2,10);
      *(undefined4 *)((int)__ptr + 0x50) = 0;
      *(undefined4 *)((int)__ptr + 0x54) = 0;
      *(int *)((int)__ptr + 0x3c) = param_1;
      *(undefined4 *)((int)__ptr + 0x58) = 0;
      iVar1 = erfHandlerRegister(*DAT_300ddf90,*DAT_300ddf94,DAT_300ddf98,__ptr,0);
      if (iVar1 == 0) {
        if (*DAT_300ddf8c == 0) {
          iVar1 = taskSpawn(DAT_300ddfa0,*DAT_300ddf88,0,0x1000,DAT_300ddf9c,__ptr,0,0,0,0,0,0,0,0,0
                           );
          *(int *)((int)__ptr + 0x34) = iVar1;
          if (iVar1 == -1) goto LAB_300ddb30;
        }
        *(undefined4 *)(param_1 + 0x30) = 0;
        *(undefined4 *)((int)__ptr + 0x40) = 0;
        iVar1 = FUN_300dd914(param_1);
        *(int *)((int)__ptr + 0x40) = iVar1;
        if (iVar1 == 0) {
          uVar2 = 0;
          uVar3 = 0x200;
        }
        else {
          uVar2 = *(undefined4 *)(param_1 + 0x18);
          uVar3 = *(undefined4 *)(param_1 + 0x1c);
        }
        iVar1 = xbdAttach(__ptr,DAT_300ddfa4,param_2,uVar3,uVar2,0,&local_20);
        if (iVar1 == 0) {
          erfEventRaise(*DAT_300ddf90,*DAT_300ddfa8,0,local_20,0);
          return local_20;
        }
      }
LAB_300ddb30:
      semDelete(*(undefined4 *)((int)__ptr + 0x5c));
    }
    semDelete(*(undefined4 *)((int)__ptr + 0x38));
  }
  semDelete(*(undefined4 *)((int)__ptr + 0x30));
LAB_300ddb48:
  free(__ptr);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ddb5c @ 0x300DDB5C  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300ddd0c, FUN_300dddf8, xbdBlkDevDelete
 * Константы: 0x300DDB5C
 * ---------------------------------------------------------------- */
int FUN_300ddb5c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x50);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(iVar1 + 0x2c);
    *(undefined4 *)(iVar1 + 0x2c) = 0;
    if (*(int *)(param_1 + 0x50) == 0) {
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300ddb94 @ 0x300DDB94  (примерный размер ~320 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: __errno, __udiv32, bio_done
 * Вызывают: FUN_300ddd0c, FUN_300de180
 * Константы: 0x300DDB94
 * ---------------------------------------------------------------- */
void FUN_300ddb94(int param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  bool bVar13;
  undefined8 uVar14;
  
  uVar4 = *(uint *)(param_1 + 0x20);
  uVar5 = *(uint *)(param_1 + 0x24);
  uVar14 = *(undefined8 *)(param_1 + 0x20);
  iVar11 = *(int *)(param_1 + 0x1c);
  iVar10 = *(int *)(param_1 + 0x3c);
  uVar1 = __udiv32(*(undefined4 *)(param_2 + 0xc),iVar11);
  uVar8 = *(uint *)(param_2 + 8);
  uVar7 = *(uint *)(param_2 + 4);
  bVar13 = uVar5 <= uVar8;
  iVar9 = 0;
  if (uVar8 == uVar5) {
LAB_300ddbec:
    if (uVar8 == uVar5) {
      bVar13 = uVar4 <= uVar7;
    }
    if (!bVar13) {
LAB_300ddc04:
      uVar6 = uVar8 + CARRY4(uVar1,uVar7);
      bVar13 = uVar5 <= uVar6;
      bVar12 = uVar6 == uVar5;
      if (bVar12) {
LAB_300ddc2c:
        if (bVar12) {
          bVar13 = uVar4 <= uVar1 + uVar7;
        }
        if (bVar13 && (!bVar12 || uVar1 + uVar7 != uVar4)) {
LAB_300ddc34:
          uVar1 = uVar4 - uVar7;
          iVar9 = uVar5 - (uVar8 + (uVar4 < uVar7));
        }
      }
      else {
        if (!bVar12 && (int)uVar5 <= (int)uVar6) goto LAB_300ddc34;
        if ((int)uVar5 < (int)uVar6) goto LAB_300ddc2c;
      }
      *(uint *)(param_2 + 0xc) = iVar11 * uVar1;
      if (iVar9 + uVar1 == 0) {
        uVar3 = 0;
        *(undefined4 *)(param_2 + 0xc) = 0;
        goto LAB_300ddcc4;
      }
      if ((*(uint *)(param_2 + 0x1c) & 1) == 0) {
        if ((*(uint *)(param_2 + 0x1c) & 2) != 0) {
          iVar9 = 4;
          goto LAB_300ddc78;
        }
      }
      else {
        iVar9 = 0;
LAB_300ddc78:
        uVar14 = (**(code **)(iVar10 + iVar9))(iVar10,uVar7,uVar1,*(undefined4 *)(param_2 + 0x10));
        if ((int)uVar14 == 0) {
          uVar3 = 0;
          goto LAB_300ddcc4;
        }
      }
      *(undefined4 *)(param_2 + 0xc) = 0;
      uVar14 = __errno((int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
      if (*(int *)uVar14 == 6) {
        uVar3 = 6;
      }
      else {
        puVar2 = (undefined4 *)__errno(*(int *)uVar14,(int)((ulonglong)uVar14 >> 0x20));
        uVar3 = *puVar2;
      }
      goto LAB_300ddcc4;
    }
  }
  else if ((int)uVar8 < (int)uVar5) {
    if ((int)uVar5 <= (int)uVar8) goto LAB_300ddbec;
    goto LAB_300ddc04;
  }
  *(undefined4 *)(param_2 + 0xc) = 0;
  uVar3 = 0x1c;
LAB_300ddcc4:
  bio_done(param_2,uVar3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ddcd4 @ 0x300DDCD4  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300ddd0c
 * Константы: 0x300DDCD4
 * ---------------------------------------------------------------- */
int FUN_300ddcd4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x50);
  iVar2 = 200;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x20);
    while (iVar1 = *(int *)(iVar1 + 0x2c), iVar1 != 0) {
      if (*(int *)(iVar1 + 0x20) < iVar2) {
        iVar2 = *(int *)(iVar1 + 0x20);
      }
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300ddd0c @ 0x300DDD0C  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_300ddb5c, FUN_300ddb94, FUN_300ddcd4, semGive, semTake, taskPrioritySet
 * Константы: 0xFFFFFFFF, 0x300DDD0C
 * Данные: DAT_300ddf88
 * ---------------------------------------------------------------- */
undefined4 FUN_300ddd0c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x38);
  while (iVar1 = semTake(uVar2,0xffffffff), iVar1 == 0) {
    while( true ) {
      semTake(*(undefined4 *)(param_1 + 0x30),0xffffffff);
      iVar1 = FUN_300ddcd4(param_1);
      if (*DAT_300ddf88 < iVar1) {
        *DAT_300ddf88 = iVar1;
        taskPrioritySet(0,iVar1);
      }
      iVar1 = FUN_300ddb5c(param_1);
      semGive(*(undefined4 *)(param_1 + 0x30));
      if (iVar1 == 0) break;
      FUN_300ddb94(param_1,iVar1);
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300ddd9c @ 0x300DDD9C  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300dddf8, FUN_300ddf10, FUN_300de180
 * Константы: 0xFFFFFFFF, 0x300DDD9C
 * ---------------------------------------------------------------- */
undefined4 FUN_300ddd9c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x3c);
  if (*(code **)(iVar4 + 0x10) == (code *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(iVar4 + 0x10))(iVar4);
  }
  iVar3 = *(int *)(iVar4 + 0x30);
  *(undefined4 *)(iVar4 + 0x30) = 0;
  if (iVar1 == 0) {
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
 * FUN_300dddf8 @ 0x300DDDF8  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 9
 * Вызывает: FUN_300ddb5c, FUN_300ddd9c, bio_done, devUnmap, erfEventRaise, semGive, semTake, xbdAttach, xbdDetach
 * Вызывают: FUN_300ddf10, FUN_300de180
 * Константы: 0x300DDDF8, 0xFFFFFFFF
 * Данные: DAT_300ddf90, DAT_300ddfa4, DAT_300ddfa8, DAT_300ddfac
 * ---------------------------------------------------------------- */
int FUN_300dddf8(undefined4 *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20;
  
  puVar1 = DAT_300ddf90;
  iVar3 = param_1[0xf];
  erfEventRaise(*DAT_300ddf90,*DAT_300ddfac,0,*param_1,0);
  xbdDetach(param_1);
  devUnmap(param_1);
  semTake(param_1[0xc],0xffffffff);
  while (iVar2 = FUN_300ddb5c(param_1), iVar2 != 0) {
    bio_done(iVar2,6);
  }
  semGive(param_1[0xc]);
  iVar2 = FUN_300ddd9c(param_1);
  if (iVar2 != 0) {
    iVar3 = xbdAttach(param_1,DAT_300ddfa4,param_1 + 0x11,0x200,0,0,&local_20);
  }
  else {
    iVar3 = xbdAttach(param_1,DAT_300ddfa4,param_1 + 0x11,*(undefined4 *)(iVar3 + 0x1c),
                      *(undefined4 *)(iVar3 + 0x18),0,&local_20);
  }
  param_1[0x10] = (uint)(iVar2 == 0);
  if (iVar3 == 0) {
    erfEventRaise(*puVar1,*DAT_300ddfa8,0,local_20,0);
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_300ddf10 @ 0x300DDF10  (примерный размер ~624 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300ddd9c, FUN_300dddf8, __errno
 * Константы: 0x300DDF10, 0x300DDF84
 * Данные: DAT_300ddfb0, DAT_300ddfb4, DAT_300ddfb8
 * ---------------------------------------------------------------- */
undefined4 FUN_300ddf10(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  code *pcVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x3c);
  iVar1 = FUN_300ddd9c();
  if (*(int *)(param_1 + 0x40) == 0) {
    if ((iVar1 != -1) || (iVar1 = FUN_300ddd9c(param_1), iVar1 != 0)) goto LAB_300ddf70;
  }
  else if (iVar1 != -1) {
LAB_300ddf70:
    if ((uint)(param_2 - DAT_300ddfb4) < 7) {
                    /* WARNING: Could not recover jumptable at 0x300ddf84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300ddfb8 + (param_2 - DAT_300ddfb4) * 4))();
      return uVar2;
    }
    pcVar5 = *(code **)(iVar6 + 8);
    if (pcVar5 != (code *)0x0) {
      iVar1 = (*pcVar5)(iVar6,param_2,param_3);
      if (iVar1 == 0) {
        return 0;
      }
      piVar3 = (int *)__errno(iVar1);
      if (*piVar3 != 0) {
        puVar4 = (undefined4 *)__errno();
        return *puVar4;
      }
    }
    return 0x23;
  }
  FUN_300dddf8(param_1);
  return DAT_300ddfb0;
}

/* ----------------------------------------------------------------
 * FUN_300de180 @ 0x300DE180  (примерный размер ~312 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_300ddb94, FUN_300ddd9c, FUN_300dddf8, __errno, bio_done, semGive, semTake, taskPrioritySet
 * Константы: 0x300DE180, 0xFFFFFFFF
 * Данные: DAT_300de448, DAT_300de44c, DAT_300de450
 * ---------------------------------------------------------------- */
undefined4 FUN_300de180(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = FUN_300ddd9c();
  if (*(int *)(param_1 + 0x40) == 0) {
    if ((iVar2 == -1) && (iVar2 = FUN_300ddd9c(param_1), iVar2 == 0)) {
      FUN_300dddf8(param_1);
      uVar1 = DAT_300de448;
      bio_done(param_2,DAT_300de448);
      return uVar1;
    }
  }
  else if (iVar2 == -1) {
    FUN_300dddf8(param_1);
    uVar1 = DAT_300de448;
    bio_done(param_2,DAT_300de448);
    return uVar1;
  }
  iVar2 = semTake(*(undefined4 *)(param_1 + 0x30),0xffffffff);
  if (iVar2 != 0) {
    puVar3 = (undefined4 *)__errno();
    return *puVar3;
  }
  if (*DAT_300de44c == 0) {
    iVar2 = *(int *)(param_2 + 0x20);
    if (iVar2 < *DAT_300de450) {
      *DAT_300de450 = iVar2;
      taskPrioritySet(*(undefined4 *)(param_1 + 0x34),iVar2);
    }
    if (param_2 != 0) {
      do {
        iVar2 = *(int *)(param_2 + 0x2c);
        *(undefined4 *)(param_2 + 0x2c) = 0;
        if (*(int *)(param_1 + 0x54) == 0) {
          *(int *)(param_1 + 0x50) = param_2;
        }
        else {
          *(int *)(*(int *)(param_1 + 0x54) + 0x2c) = param_2;
        }
        *(int *)(param_1 + 0x54) = param_2;
        param_2 = iVar2;
      } while (iVar2 != 0);
    }
    semGive(*(undefined4 *)(param_1 + 0x38));
  }
  else {
    FUN_300ddb94(param_1,param_2);
  }
  semGive(*(undefined4 *)(param_1 + 0x30));
  return 0;
}

/* ----------------------------------------------------------------
 * xbdBlkDevDelete @ 0x300DE2B8  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 11
 * Вызывает: FUN_300ddb5c, bio_done, devMap, devUnmap, erfEventRaise, free, semDelete, semTake, sysClkRateGet, taskDelay, xbdDetach
 * Вызывают: TFUP_dosFsDevDelete, sdmmcExit
 * Константы: 0xFFFFFFFF, 0x300DE2B8
 * Данные: DAT_300de430, DAT_300de434
 * ---------------------------------------------------------------- */
undefined4 xbdBlkDevDelete(undefined4 param_1,undefined4 *param_2)

{
  void *__ptr;
  undefined4 uVar1;
  int iVar2;
  
  __ptr = (void *)devMap();
  if (__ptr == (void *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    semTake(*(undefined4 *)((int)__ptr + 0x30),0xffffffff);
    semDelete(*(undefined4 *)((int)__ptr + 0x38));
    sysClkRateGet();
    taskDelay();
    xbdDetach(__ptr);
    devUnmap(__ptr);
    while (iVar2 = FUN_300ddb5c(__ptr), iVar2 != 0) {
      bio_done(iVar2,6);
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)((int)__ptr + 0x3c);
    }
    semDelete(*(undefined4 *)((int)__ptr + 0x5c));
    semDelete(*(undefined4 *)((int)__ptr + 0x30));
    *(undefined4 *)((int)__ptr + 0x30) = 0;
    *(undefined4 *)((int)__ptr + 0x38) = 0;
    free(__ptr);
    erfEventRaise(*DAT_300de430,*DAT_300de434,1,param_1,0);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300de384 @ 0x300DE384  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: erfHandlerUnregister, semGive, strncmp
 * Константы: 0x300DE384
 * Данные: DAT_300de430, DAT_300de444, DAT_300de454
 * ---------------------------------------------------------------- */
void FUN_300de384(uint param_1,uint param_2,char *param_3,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  uVar1 = *DAT_300de430;
  if (param_1 != uVar1) {
    return;
  }
  uVar2 = *DAT_300de444;
  if (param_2 != uVar2) {
    return;
  }
  iVar3 = strncmp(param_3,(char *)(param_4 + 8),10);
  if (iVar3 != 0) {
    return;
  }
  erfHandlerUnregister((uint)uVar1,(uint)uVar2,DAT_300de454,param_4);
  semGive(*(undefined4 *)(param_4 + 0x5c));
  return;
}

/* ----------------------------------------------------------------
 * xbdBlkDevCreateSync @ 0x300DE3F0  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: devMap, devUnmap, semTake, xbdBlkDevCreate
 * Константы: 0x300DE3F0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 xbdBlkDevCreateSync(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = xbdBlkDevCreate();
  iVar2 = devMap();
  if (iVar2 == 0) {
    return 0;
  }
  semTake(*(undefined4 *)(iVar2 + 0x5c),0xffffffff);
  devUnmap(iVar2);
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300de458 @ 0x300DE458  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: snprintf, strcat, strcpy, strlen
 * Вызывают: FUN_300de834, xbdPartitionDevCreate
 * Константы: 0x300DE458
 * Данные: DAT_300df1ac
 * ---------------------------------------------------------------- */
undefined4 FUN_300de458(char *param_1,undefined4 param_2,char *param_3)

{
  size_t sVar1;
  char acStack_14 [8];
  
  strcpy(param_3,param_1);
  snprintf(acStack_14,5,DAT_300df1ac,param_2);
  sVar1 = strlen(acStack_14);
  param_3[9 - sVar1] = '\0';
  strcat(param_3,acStack_14);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300de4b8 @ 0x300DE4B8  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: semTake, xbdStrategy
 * Вызывают: FUN_300de834
 * Константы: 0xFFFFFFFF, 0x300DE4B8
 * Данные: DAT_300df1b0, DAT_300df1b4
 * ---------------------------------------------------------------- */
undefined4 FUN_300de4b8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + DAT_300df1b0);
  uVar1 = *(undefined4 *)(param_1 + 8);
  *puVar3 = uVar1;
  puVar3[1] = param_2;
  puVar3[2] = param_3;
  puVar3[3] = *(undefined4 *)(param_1 + 0x28);
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[7] = 1;
  puVar3[9] = DAT_300df1b4;
  puVar3[10] = *(undefined4 *)(param_1 + 4);
  puVar3[0xb] = 0;
  xbdStrategy(uVar1,puVar3);
  iVar2 = semTake(*(undefined4 *)(param_1 + 4),0xffffffff);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  return puVar3[6];
}

/* ----------------------------------------------------------------
 * FUN_300de53c @ 0x300DE53C  (примерный размер ~400 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300de834
 * Константы: 0x300DE53C, 0x300DE624, 0x300DE628, 0x300DE64C, 0x300DE650, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300de624) */
/* WARNING: Removing unreachable block (ram,0x300de628) */
/* WARNING: Removing unreachable block (ram,0x300de64c) */
/* WARNING: Removing unreachable block (ram,0x300de650) */

int FUN_300de53c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  
  uVar2 = *(uint *)(param_1 + 0x680);
  uVar3 = *(uint *)(param_1 + 0x684);
  iVar4 = 0;
  iVar5 = 0x18;
  do {
    iVar6 = param_1 + iVar5 * 0x40;
    if (*(int *)(iVar6 + 0x44) != 0) {
      uVar7 = *(uint *)(iVar6 + 0x40);
      uVar1 = (uVar7 + *(int *)(iVar6 + 0x44)) - 1;
      bVar11 = uVar3 == 0;
      bVar10 = uVar3 == 0;
      if (bVar10) {
LAB_300de5b0:
        if (bVar10) {
          bVar11 = uVar2 <= uVar1;
        }
        if (bVar11 && (!bVar10 || uVar1 != uVar2)) {
LAB_300de5b8:
          *(uint *)(iVar6 + 0x44) = (uVar2 - uVar7) + 1;
        }
      }
      else {
        if (0x7fffffff < uVar3) goto LAB_300de5b8;
        if ((int)uVar3 < 0) goto LAB_300de5b0;
      }
      iVar8 = iVar5 + 1;
      if (iVar8 < 0x19) {
        iVar9 = param_1 + iVar8 * 0x40 + 0xc;
        iVar8 = 0x19 - iVar8;
        do {
          if (((*(int *)(iVar9 + 0x38) != 0) && (*(uint *)(iVar9 + 0x34) <= uVar1)) &&
             (uVar7 <= (*(uint *)(iVar9 + 0x34) + *(int *)(iVar9 + 0x38)) - 1)) break;
          iVar9 = iVar9 + 0x40;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        if (0x18 < 0x19 - iVar8) goto LAB_300de674;
      }
      else {
LAB_300de674:
        bVar11 = uVar3 == 0;
        bVar10 = uVar3 == 0;
        if (bVar10) {
LAB_300de694:
          if (bVar10) {
            bVar11 = uVar2 <= uVar7;
          }
          if (!bVar11 || bVar10 && uVar7 == uVar2) {
LAB_300de6ac:
            iVar4 = iVar4 + 1;
            goto LAB_300de6b0;
          }
        }
        else if (-1 < (int)uVar3) {
          if ((int)uVar3 < 0) goto LAB_300de694;
          goto LAB_300de6ac;
        }
      }
      *(undefined4 *)(iVar6 + 0x44) = 0;
      *(undefined4 *)(iVar6 + 0x40) = 0;
    }
LAB_300de6b0:
    iVar5 = iVar5 + -1;
    if (iVar5 < 1) {
      return iVar4;
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300de6cc @ 0x300DE6CC  (примерный размер ~360 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300de834
 * Вызывают: FUN_300de834
 * Константы: 0x300DE6CC
 * ---------------------------------------------------------------- */
int FUN_300de6cc(int param_1,int param_2,int *param_3,int param_4,int param_5,int param_6,
                undefined4 param_7)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar4 = 4;
  do {
    if (0x18 < *param_3) {
      *param_3 = 0x18;
      break;
    }
    *(uint *)(param_2 + 8) =
         (uint)*(byte *)(param_2 + 10) << 0x10 | (uint)*(byte *)(param_2 + 0xb) << 0x18 |
         (uint)*(byte *)(param_2 + 9) << 8 | (uint)*(byte *)(param_2 + 8);
    uVar2 = (uint)*(byte *)(param_2 + 0xe) << 0x10 | (uint)*(byte *)(param_2 + 0xf) << 0x18 |
            (uint)*(byte *)(param_2 + 0xd) << 8 | (uint)*(byte *)(param_2 + 0xc);
    *(uint *)(param_2 + 0xc) = uVar2;
    if (uVar2 != 0) {
      iVar5 = iVar5 + 1;
      iVar6 = param_1 + *param_3 * 0x40;
      *(uint *)(iVar6 + 0x84) = uVar2;
      cVar1 = *(char *)(param_2 + 4);
      *(char *)(iVar6 + 0x88) = cVar1;
      if ((cVar1 == '\x05') || (cVar1 == '\x0f')) {
        iVar3 = param_6 + *(int *)(param_2 + 8);
        *(int *)(iVar6 + 0x80) = iVar3;
        if (param_5 + param_4 == 0) {
          param_7 = 0;
          param_6 = iVar3;
        }
        iVar3 = FUN_300de834(param_1,0,param_3,iVar3,0,param_6,param_7);
        if (iVar3 != 2) goto LAB_300de810;
        *(int *)(iVar6 + 0x80) = param_4 + *(int *)(param_2 + 8);
        *(undefined4 *)(iVar6 + 0x84) = *(undefined4 *)(param_2 + 0xc);
        *(undefined1 *)(iVar6 + 0x88) = *(undefined1 *)(param_2 + 4);
      }
      else {
        *(int *)(iVar6 + 0x80) = param_4 + *(int *)(param_2 + 8);
      }
      *param_3 = *param_3 + 1;
    }
LAB_300de810:
    param_2 = param_2 + 0x10;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return (uint)(iVar5 == 0) << 1;
}

/* ----------------------------------------------------------------
 * FUN_300de834 @ 0x300DE834  (примерный размер ~380 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_300de458, FUN_300de4b8, FUN_300de53c, FUN_300de6cc, bcopy, erfEventRaise, xbdAttach
 * Вызывают: FUN_300de6cc, xbdPartitionDevCreate
 * Константы: 0x300DE834
 * Данные: DAT_300df1b8, DAT_300df1bc, DAT_300df1c0, DAT_300df1c4, DAT_300df1c8, DAT_300df1cc
 * ---------------------------------------------------------------- */
int FUN_300de834(int param_1,int param_2,int *param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  bool bVar6;
  undefined4 local_74;
  undefined1 auStack_70 [12];
  undefined1 auStack_64 [64];
  
  iVar1 = FUN_300de4b8(param_1,param_4,param_5);
  bVar6 = iVar1 == 0;
  if (bVar6) {
    pcVar4 = (char *)(*(int *)(param_1 + 0x65c) + DAT_300df1b8);
    if (*pcVar4 != 'U') {
      return 2;
    }
    if (pcVar4[1] != -0x56) {
      return 2;
    }
    bcopy((void *)(*(int *)(param_1 + 0x65c) + DAT_300df1bc),auStack_64,0x40);
    iVar1 = FUN_300de6cc(param_1,auStack_64,param_3,param_4,param_5,param_6,param_7);
    bVar6 = iVar1 == 0;
  }
  if (bVar6) {
    if (param_2 != 0) {
      iVar2 = FUN_300de53c(param_1);
      *param_3 = iVar2;
      iVar1 = DAT_300df1c0;
      if (iVar2 == 0) {
        return 2;
      }
      iVar5 = 1;
      *(undefined4 *)(param_1 + DAT_300df1c0) = 0;
      iVar2 = param_1 + 0x4c;
      do {
        if (*(int *)(iVar2 + 0x38) != 0) {
          FUN_300de458(param_2,iVar5,auStack_70);
          iVar3 = xbdAttach(iVar2,DAT_300df1c4,auStack_70,*(undefined4 *)(param_1 + 0x67c),
                            *(undefined4 *)(iVar2 + 0x38),0,&local_74);
          if (iVar3 != 0) break;
          *(int *)(param_1 + iVar1) = *(int *)(param_1 + iVar1) + 1;
          erfEventRaise(*DAT_300df1c8,*DAT_300df1cc,0,local_74,0);
        }
        iVar2 = iVar2 + 0x40;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x19);
    }
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * xbdPartitionDevCreate @ 0x300DE9B0  (примерный размер ~656 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 18
 * Вызывает: FUN_300de458, FUN_300de834, bio_alloc, bio_free, devName, erfEventRaise, erfHandlerRegister, erfHandlerUnregister, free, malloc, semBCreate, semDelete, semGive, semMCreate
 *           ...
 * Вызывают: FUN_300c9698
 * Константы: 0x300DE9B0, 0xFFFFFFFF
 * Данные: DAT_300df1c4, DAT_300df1c8, DAT_300df1cc, DAT_300df1d0, DAT_300df1d4, DAT_300df1d8, DAT_300df1dc, DAT_300df1e0
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

undefined4 xbdPartitionDevCreate(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *__ptr;
  int iVar3;
  int *piVar4;
  undefined4 local_48;
  int local_44 [3];
  int local_38;
  undefined1 auStack_34 [12];
  undefined1 auStack_28 [12];
  
  iVar2 = xbdBlockSize(param_1,local_44);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = xbdNBlocks(param_1,local_44 + 2);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = devName(param_1,auStack_34);
  if (iVar2 != 0) {
    return 0;
  }
  __ptr = (int *)malloc(DAT_300df1d0);
  if (__ptr == (int *)0x0) {
    return 0;
  }
  iVar2 = semMCreate(9);
  *__ptr = iVar2;
  if (iVar2 == 0) goto LAB_300dec2c;
  iVar2 = semTake(iVar2,0xffffffff);
  if (iVar2 != -1) {
    iVar2 = semBCreate(1,0);
    __ptr[1] = iVar2;
    if (iVar2 != 0) {
      __ptr[2] = param_1;
      __ptr[0x19f] = local_44[0];
      __ptr[0x1a0] = local_44[2];
      __ptr[0x1a1] = local_38;
      uVar1 = DAT_300df1d4;
      iVar2 = erfHandlerRegister(*DAT_300df1c8,*DAT_300df1d8,DAT_300df1d4,__ptr,0);
      if ((iVar2 != -1) &&
         (iVar2 = erfHandlerRegister(*DAT_300df1c8,*DAT_300df1dc,uVar1,__ptr,0), iVar2 != -1)) {
        iVar3 = bio_alloc(param_1,1);
        iVar2 = DAT_300df1e0;
        __ptr[0x197] = iVar3;
        if (iVar3 != 0) {
          iVar3 = 0x19;
          piVar4 = __ptr;
          do {
            piVar4[0xf] = (int)__ptr;
            piVar4[0x11] = 0;
            piVar4[0x10] = 0;
            *(undefined1 *)(piVar4 + 0x12) = 0;
            iVar3 = iVar3 + -1;
            piVar4 = piVar4 + 0x10;
          } while (iVar3 != 0);
          __ptr[0x11] = local_44[2];
          FUN_300de458(auStack_34,0,auStack_28);
          iVar3 = xbdAttach(__ptr + 3,DAT_300df1c4,auStack_28,local_44[0],local_44[2],local_38,
                            &local_48);
          if (iVar3 == 0) {
            local_44[1] = 0;
            if (local_38 + local_44[2] != 0) {
              iVar3 = FUN_300de834(__ptr,auStack_34,local_44 + 1,0,0,0,0);
              if (iVar3 == 0) goto LAB_300debc4;
              if (iVar3 != 2) goto LAB_300debd4;
            }
            __ptr[0x1a2] = 1;
            erfEventRaise(*DAT_300df1c8,*DAT_300df1cc,0,local_48,0);
LAB_300debc4:
            semGive(*__ptr);
            return local_48;
          }
LAB_300debd4:
          bio_free(*(undefined4 *)((int)__ptr + iVar2));
        }
        semDelete(__ptr[1]);
      }
      erfHandlerUnregister(*DAT_300df1c8,*DAT_300df1d8,uVar1,__ptr);
      erfHandlerUnregister(*DAT_300df1c8,*DAT_300df1dc,uVar1,__ptr);
    }
  }
  semGive(*__ptr);
  semDelete(*__ptr);
LAB_300dec2c:
  free(__ptr);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300dec40 @ 0x300DEC40  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: bio_free, free, logMsg, semDelete, semTake
 * Вызывают: FUN_300decb0
 * Константы: 0x300DEC40, 0xFFFFFFFF
 * Данные: DAT_300df1e4
 * ---------------------------------------------------------------- */
void FUN_300dec40(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = semTake(*param_1,0xffffffff);
  if (iVar1 == -1) {
    logMsg(DAT_300df1e4,0,0,0,0,0,0);
  }
  else {
    bio_free(param_1[0x197]);
    semDelete(param_1[1]);
    semDelete(*param_1);
    free(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300decb0 @ 0x300DECB0  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300dec40, devUnmap, erfEventRaise, erfHandlerUnregister, xbdDetach
 * Константы: 0x300DECB0
 * Данные: DAT_300df1c8, DAT_300df1d4, DAT_300df1d8, DAT_300df1dc
 * ---------------------------------------------------------------- */
void FUN_300decb0(uint param_1,uint param_2,int param_3,int param_4)

{
  ushort *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = DAT_300df1d4;
  puVar1 = DAT_300df1c8;
  if ((param_1 == *DAT_300df1c8) &&
     (((param_2 == *DAT_300df1d8 || (*DAT_300df1dc == param_2)) &&
      (*(int *)(param_4 + 8) == param_3)))) {
    erfHandlerUnregister((uint)*DAT_300df1c8,(uint)*DAT_300df1d8,DAT_300df1d4,param_4);
    erfHandlerUnregister(*puVar1,*DAT_300df1dc,uVar2,param_4);
    iVar3 = 0;
    iVar4 = param_4;
    do {
      if ((*(int *)(iVar4 + 0x44) != 0) || (iVar3 == 0)) {
        erfEventRaise(*puVar1,param_2,1,*(undefined4 *)(iVar4 + 0xc),0);
        xbdDetach(iVar4 + 0xc);
        devUnmap(iVar4 + 0xc);
      }
      iVar4 = iVar4 + 0x40;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x19);
    FUN_300dec40(param_4);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300deda4 @ 0x300DEDA4  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: __udiv32, bio_done, semGive, semTake, xbdStrategy
 * Константы: 0xFFFFFFFF, 0x300DEDA4
 * ---------------------------------------------------------------- */
undefined4 FUN_300deda4(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  iVar10 = *(int *)(param_1 + 0x1c);
  uVar5 = *(uint *)(param_1 + 0x20);
  uVar6 = *(uint *)(param_1 + 0x24);
  iVar1 = semTake(**(undefined4 **)(param_1 + 0x30),0xffffffff);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    if (param_2 != 0) {
      do {
        iVar9 = *(int *)(param_2 + 0x2c);
        *(undefined4 *)(param_2 + 0x2c) = 0;
        uVar3 = __udiv32(*(undefined4 *)(param_2 + 0xc),iVar10);
        iVar1 = 0;
        uVar8 = *(uint *)(param_2 + 8);
        uVar7 = *(uint *)(param_2 + 4);
        bVar11 = uVar6 <= uVar8;
        if (uVar8 == uVar6) {
LAB_300dee24:
          if (uVar8 == uVar6) {
            bVar11 = uVar5 <= uVar7;
          }
          if (bVar11) goto LAB_300dee2c;
LAB_300dee44:
          uVar4 = uVar8 + CARRY4(uVar3,uVar7);
          bVar11 = uVar6 <= uVar4;
          if (uVar4 == uVar6) {
LAB_300dee64:
            if (uVar4 == uVar6) {
              bVar11 = uVar5 <= uVar3 + uVar7;
            }
            if (bVar11) {
LAB_300dee6c:
              uVar3 = uVar5 - uVar7;
              iVar1 = uVar6 - (uVar8 + (uVar5 < uVar7));
            }
          }
          else {
            if ((int)uVar6 <= (int)uVar4) goto LAB_300dee6c;
            if ((int)uVar6 <= (int)uVar4) goto LAB_300dee64;
          }
          if (iVar1 + uVar3 == 0) {
            *(undefined4 *)(param_2 + 0xc) = 0;
            bio_done(param_2);
          }
          else {
            *(uint *)(param_2 + 0xc) = iVar10 * uVar3;
            uVar3 = *(uint *)(param_1 + 0x34);
            *(uint *)(param_2 + 4) = uVar7 + uVar3;
            *(uint *)(param_2 + 8) = uVar8 + CARRY4(uVar7,uVar3);
            xbdStrategy(*(undefined4 *)(*(int *)(param_1 + 0x30) + 8),param_2);
          }
        }
        else {
          if ((int)uVar8 < (int)uVar6) {
            if ((int)uVar6 <= (int)uVar8) goto LAB_300dee24;
            goto LAB_300dee44;
          }
LAB_300dee2c:
          *(undefined4 *)(param_2 + 0xc) = 0;
          bio_done(param_2,0x1c);
        }
        param_2 = iVar9;
      } while (iVar9 != 0);
    }
    semGive(**(undefined4 **)(param_1 + 0x30));
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300deef8 @ 0x300DEEF8  (примерный размер ~636 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: __div64, erfEventRaise, semGive, semTake, xbdIoctl
 * Константы: 0x300DEEF8, 0xFFFFFFFF
 * Данные: DAT_300df1c8, DAT_300df1cc, DAT_300df1d8, DAT_300df1e8, DAT_300df1ec, DAT_300df1f0, DAT_300df1f4, DAT_300df1f8
 * ---------------------------------------------------------------- */
int FUN_300deef8(undefined4 *param_1,int param_2,uint *param_3)

{
  undefined2 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  bool bVar9;
  undefined8 uVar10;
  uint local_50;
  int local_4c;
  uint local_48;
  uint local_40 [3];
  uint local_34;
  uint local_28;
  
  iVar2 = semTake(*(undefined4 *)param_1[0xc],0xffffffff);
  puVar1 = DAT_300df1c8;
  if (iVar2 == -1) {
    return -1;
  }
  if (param_2 == DAT_300df1e8) {
LAB_300def8c:
    uVar8 = *param_1;
    iVar2 = param_2;
    if ((-1 < (int)param_3) && ((int)param_3 < 2)) {
      erfEventRaise(*DAT_300df1c8,*DAT_300df1d8,0,uVar8,0);
      puVar5 = DAT_300df1cc;
      if ((param_2 == DAT_300df1e8) || (puVar5 = DAT_300df200, param_2 == DAT_300df1f4)) {
        erfEventRaise(*puVar1,*puVar5,0,uVar8,0);
      }
      iVar4 = 0;
      goto LAB_300df15c;
    }
  }
  else if (param_2 == DAT_300df1e8 || param_2 < DAT_300df1e8) {
    if (param_2 == DAT_300df1ec) {
      iVar4 = xbdIoctl(*(undefined4 *)(param_1[0xc] + 8),DAT_300df1ec,local_40);
      if (iVar4 == 0) {
        param_3[6] = local_28;
        *param_3 = local_40[0];
        param_3[3] = local_34;
        uVar3 = param_1[8];
        uVar6 = param_1[9];
        param_3[4] = uVar3;
        param_3[5] = uVar6;
        uVar10 = __div64(uVar3,uVar6,local_40[0],0);
        uVar10 = __div64((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),local_34,0);
        *(undefined8 *)(param_3 + 1) = uVar10;
      }
      goto LAB_300df15c;
    }
    iVar2 = DAT_300df1f0;
    if ((param_2 != DAT_300df1f0) && (iVar2 = param_2, param_2 == DAT_300df1f4)) goto LAB_300def8c;
  }
  else {
    iVar2 = DAT_300df1f8;
    if (param_2 != DAT_300df1f8) {
      if (param_2 == DAT_300df1fc) {
        iVar4 = 0;
        iVar7 = *(int *)(param_1[0xc] + 0x688);
        if ((iVar7 < 1) ||
           (iVar7 = iVar7 + -1, *(int *)(param_1[0xc] + 0x688) = iVar7, iVar2 = param_2, iVar7 != 0)
           ) goto LAB_300df15c;
      }
      else {
        iVar2 = param_2;
        if (param_2 == 0x47) {
          uVar3 = *param_3;
          uVar6 = param_1[0xd];
          bVar9 = CARRY4(uVar3,uVar6);
          local_50 = uVar3 + uVar6;
          local_4c = param_3[1] + (uint)bVar9;
          local_48 = param_3[2];
          if (local_4c == 0) {
LAB_300df0ec:
            if (local_4c == 0) {
              bVar9 = uVar6 + param_1[0xe] <= local_50;
            }
            if (!bVar9) {
LAB_300df0f4:
              iVar2 = param_3[1] + (uint)CARRY4(*param_3,param_3[2]);
              if (iVar2 == 0) {
LAB_300df128:
                if (iVar2 == 0 && *param_3 + param_3[2] < uVar6 + param_1[0xe]) {
LAB_300df138:
                  param_3 = &local_50;
                  iVar2 = param_2;
                  goto LAB_300df14c;
                }
              }
              else if (iVar2 < 0) {
                if (iVar2 >= 0) goto LAB_300df128;
                goto LAB_300df138;
              }
            }
          }
          else {
            if (local_4c < 0 != SCARRY4(uVar3,uVar6)) goto LAB_300df0f4;
            if (local_4c < 0 != SCARRY4(uVar3,uVar6)) goto LAB_300df0ec;
          }
          iVar4 = 0x16;
          goto LAB_300df15c;
        }
      }
    }
  }
LAB_300df14c:
  iVar4 = xbdIoctl(*(undefined4 *)(param_1[0xc] + 8),iVar2,param_3);
LAB_300df15c:
  semGive(*(undefined4 *)param_1[0xc]);
  return iVar4;
}

/* ----------------------------------------------------------------
 * FUN_300df174 @ 0x300DF174  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: xbdDump
 * Константы: 0x300DF174
 * ---------------------------------------------------------------- */
void FUN_300df174(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  xbdDump(*(undefined4 *)(*(int *)(param_1 + 0x30) + 8),param_2 + *(uint *)(param_1 + 0x34),
          param_3 + (uint)CARRY4(param_2,*(uint *)(param_1 + 0x34)),param_4,param_5);
  return;
}

/* ----------------------------------------------------------------
 * xbdRamDiskDevCreate @ 0x300DF204  (примерный размер ~432 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 14
 * Вызывает: __errno, __udiv32, bzero, erfEventRaise, free, fsPathAddedEventSetup, fsWaitForPath, fsmNameMap, malloc, semDelete, semMCreate, sprintf, strlen, xbdAttach
 * Константы: 0x300DF204
 * Данные: DAT_300df3e4, DAT_300df3e8, DAT_300df3ec, DAT_300df3f0, DAT_300df3f4
 * ---------------------------------------------------------------- */
undefined4 xbdRamDiskDevCreate(size_t param_1,int param_2,int param_3,char *param_4)

{
  undefined4 *puVar1;
  size_t sVar2;
  void *__ptr;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined2 uVar6;
  undefined4 local_60;
  undefined1 auStack_5c [8];
  undefined1 auStack_54 [24];
  char acStack_3c [24];
  
  if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    local_60 = 0;
  }
  else {
    sVar2 = strlen(param_4);
    if ((uint)(param_3 == 0) * 2 + 7 < sVar2) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = 0x16;
      local_60 = 0;
    }
    else {
      __ptr = malloc(param_2 + 0x47);
      if (__ptr == (void *)0x0) {
        local_60 = 0;
      }
      else {
        iVar3 = semMCreate(9);
        *(int *)((int)__ptr + 0x30) = iVar3;
        if (iVar3 == 0) {
          free(__ptr);
          local_60 = 0;
        }
        else {
          bzero((void *)((int)__ptr + 0x44),param_1);
          *(size_t *)((int)__ptr + 0x34) = param_1;
          uVar4 = __udiv32(param_2,param_1);
          *(undefined4 *)((int)__ptr + 0x38) = uVar4;
          if (param_3 == 0) {
            uVar6 = *DAT_300df3e8;
          }
          else {
            uVar6 = *DAT_300df3e4;
          }
          *(undefined2 *)((int)__ptr + 0x3c) = uVar6;
          *(undefined4 *)((int)__ptr + 0x40) = 0;
          iVar3 = xbdAttach(__ptr,DAT_300df3ec,param_4,param_1,uVar4,0,&local_60);
          if (iVar3 == 0) {
            if (param_3 != 0) {
              sprintf(acStack_3c,DAT_300df3f0,param_4);
              fsmNameMap(acStack_3c,auStack_54);
              fsPathAddedEventSetup(auStack_5c,auStack_54);
            }
            erfEventRaise(*DAT_300df3f4,*(undefined2 *)((int)__ptr + 0x3c),1,local_60,0);
            if (param_3 != 0) {
              fsWaitForPath(auStack_5c);
            }
          }
          else {
            piVar5 = (int *)__errno();
            *piVar5 = iVar3;
            semDelete(*(undefined4 *)((int)__ptr + 0x30));
            free(__ptr);
            local_60 = 0;
          }
        }
      }
    }
  }
  return local_60;
}

/* ----------------------------------------------------------------
 * FUN_300df3b4 @ 0x300DF3B4  (примерный размер ~388 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300DF3B4, 0x300DF3E0
 * Данные: DAT_300df3f8, DAT_300df3fc
 * ---------------------------------------------------------------- */
undefined4 FUN_300df3b4(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((uint)(param_2 - DAT_300df3f8) < 7) {
                    /* WARNING: Could not recover jumptable at 0x300df3e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_300df3fc + (param_2 - DAT_300df3f8) * 4))();
    return uVar1;
  }
  return 0x23;
}

/* ----------------------------------------------------------------
 * FUN_300df538 @ 0x300DF538  (примерный размер ~352 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: __udiv32, bcopy, bio_done, semGive, semTake
 * Вызывают: FUN_300df698
 * Константы: 0x300DF538, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300df538(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  void *__src;
  void *__dest;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  
  uVar4 = *(uint *)(param_1 + 0x20);
  uVar5 = *(uint *)(param_1 + 0x24);
  iVar9 = *(int *)(param_1 + 0x1c);
  iVar1 = semTake(*(undefined4 *)(param_1 + 0x30),0xffffffff);
  if (iVar1 == 0) {
    for (; param_2 != 0; param_2 = *(int *)(param_2 + 0x2c)) {
      uVar3 = __udiv32(*(undefined4 *)(param_2 + 0xc),iVar9);
      uVar8 = *(uint *)(param_2 + 8);
      uVar7 = *(uint *)(param_2 + 4);
      bVar11 = uVar5 <= uVar8;
      iVar1 = 0;
      if (uVar8 == uVar5) {
LAB_300df5c8:
        if (uVar8 == uVar5) {
          bVar11 = uVar4 <= uVar7;
        }
        if (bVar11) goto LAB_300df5d0;
LAB_300df5e0:
        uVar6 = uVar8 + CARRY4(uVar3,uVar7);
        bVar11 = uVar5 <= uVar6;
        bVar10 = uVar6 == uVar5;
        if (bVar10) {
LAB_300df608:
          if (bVar10) {
            bVar11 = uVar4 <= uVar3 + uVar7;
          }
          if (bVar11 && (!bVar10 || uVar3 + uVar7 != uVar4)) {
LAB_300df610:
            uVar3 = uVar4 - uVar7;
            iVar1 = uVar5 - (uVar8 + (uVar4 < uVar7));
          }
        }
        else {
          if (!bVar10 && (int)uVar5 <= (int)uVar6) goto LAB_300df610;
          if ((int)uVar5 < (int)uVar6) goto LAB_300df608;
        }
        *(uint *)(param_2 + 0xc) = iVar9 * uVar3;
        if (iVar1 + uVar3 == 0) {
          *(undefined4 *)(param_2 + 0xc) = 0;
        }
        else {
          if ((*(uint *)(param_2 + 0x1c) & 1) == 0) {
            if ((*(uint *)(param_2 + 0x1c) & 2) == 0) goto LAB_300df66c;
            __src = *(void **)(param_2 + 0x10);
            __dest = (void *)(uVar7 * iVar9 + param_1 + 0x44);
          }
          else {
            __dest = *(void **)(param_2 + 0x10);
            __src = (void *)(uVar7 * iVar9 + param_1 + 0x44);
          }
          bcopy(__src,__dest,iVar9 * uVar3);
        }
LAB_300df66c:
        uVar2 = 0;
      }
      else {
        if ((int)uVar8 < (int)uVar5) {
          if ((int)uVar5 <= (int)uVar8) goto LAB_300df5c8;
          goto LAB_300df5e0;
        }
LAB_300df5d0:
        *(undefined4 *)(param_2 + 0xc) = 0;
        uVar2 = 0x1c;
      }
      bio_done(param_2,uVar2);
    }
    semGive(*(undefined4 *)(param_1 + 0x30));
    uVar2 = 0;
  }
  else {
    for (; param_2 != 0; param_2 = *(int *)(param_2 + 0x2c)) {
      bio_done(param_2,6);
    }
    uVar2 = 6;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300df698 @ 0x300DF698  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300df538
 * Константы: 0x300DF698
 * ---------------------------------------------------------------- */
undefined4
FUN_300df698(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_3c = *param_1;
  local_30 = param_5;
  local_24 = 0;
  local_20 = 2;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_38 = param_2;
  local_34 = param_3;
  local_2c = param_4;
  FUN_300df538(param_1,&local_3c);
  return local_24;
}

/* ----------------------------------------------------------------
 * xbdRamDiskDevDelete @ 0x300DF6F0  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 7
 * Вызывает: devMap, devUnmap, erfEventRaise, free, semDelete, semTake, xbdDetach
 * Константы: 0xFFFFFFFF, 0x300DF6F0
 * Данные: DAT_300df774, DAT_300df778
 * ---------------------------------------------------------------- */
undefined4 xbdRamDiskDevDelete(undefined4 param_1)

{
  void *__ptr;
  undefined4 uVar1;
  
  __ptr = (void *)devMap();
  if (__ptr == (void *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    semTake(*(undefined4 *)((int)__ptr + 0x30),0xffffffff);
    xbdDetach(__ptr);
    devUnmap(__ptr);
    semDelete(*(undefined4 *)((int)__ptr + 0x30));
    *(undefined4 *)((int)__ptr + 0x30) = 0;
    free(__ptr);
    erfEventRaise(*DAT_300df774,*DAT_300df778,1,param_1,0);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * classLibInit @ 0x300DF788  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrInit
 * Константы: 0x300DF788
 * Данные: DAT_300df968
 * ---------------------------------------------------------------- */
undefined4 classLibInit(void)

{
  if ((code *)*DAT_300df968 != (code *)0x0) {
    (*(code *)*DAT_300df968)();
  }
  return 0;
}

/* ----------------------------------------------------------------
 * classInit @ 0x300DF7B0  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 1
 * Вызывает: handleInit
 * Вызывают: iosInit, kernelBaseInit, memPartLibInit, msgQLibInit, semLibInit, taskLibInit, vmBaseLibInit, wdLibInit
 * Константы: 0x300DF7B0
 * Данные: DAT_300df96c, DAT_300df970, DAT_300df974
 * ---------------------------------------------------------------- */
undefined4
classInit(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
         undefined4 param_6,undefined4 param_7,int param_8,int param_9,undefined4 param_10)

{
  if ((code *)*DAT_300df96c != (code *)0x0) {
    (*(code *)*DAT_300df96c)(param_1,param_9);
  }
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x20) = param_4;
  *(undefined4 *)(param_1 + 0x24) = param_5;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_6;
  *(undefined4 *)(param_1 + 0x2c) = param_7;
  if (param_8 == 0) {
    param_8 = *DAT_300df970;
  }
  *(int *)(param_1 + 0x34) = param_8;
  *(int *)(param_1 + 0x38) = param_9;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x3c) = param_10;
  handleInit(param_1,0x69);
  *(int *)(DAT_300df974 + param_9 * 4) = param_1;
  return 0;
}

/* ----------------------------------------------------------------
 * classCreateConnect @ 0x300DF868  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300DF868, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 classCreateConnect(int param_1,undefined4 param_2)

{
  if ((*(int *)(param_1 + 4) == param_1) && (*(char *)(param_1 + 10) == 'i')) {
    *(undefined4 *)(param_1 + 0x20) = param_2;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * classOpenConnect @ 0x300DF894  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300DF894, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 classOpenConnect(int param_1,undefined4 param_2)

{
  if ((*(int *)(param_1 + 4) == param_1) && (*(char *)(param_1 + 10) == 'i')) {
    *(undefined4 *)(param_1 + 0x24) = param_2;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * classDestroyConnect @ 0x300DF8C0  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300DF8C0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 classDestroyConnect(int param_1,undefined4 param_2)

{
  if ((*(int *)(param_1 + 4) == param_1) && (*(char *)(param_1 + 10) == 'i')) {
    *(undefined4 *)(param_1 + 0x14) = param_2;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * classShowConnect @ 0x300DF8EC  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: taskShowInit
 * Константы: 0x300DF8EC, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 classShowConnect(int param_1,undefined4 param_2)

{
  if ((*(int *)(param_1 + 4) == param_1) && (*(char *)(param_1 + 10) == 'i')) {
    *(undefined4 *)(param_1 + 0x18) = param_2;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * classMemPartIdSet @ 0x300DF918  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: objVerify
 * Константы: 0x300DF918, 0xFFFFFFFF
 * Данные: DAT_300df978
 * ---------------------------------------------------------------- */
undefined4 classMemPartIdSet(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (((*(int *)(param_1 + 4) == param_1) && (*(char *)(param_1 + 10) == 'i')) &&
     (iVar1 = objVerify(param_2,*DAT_300df978), iVar1 == 0)) {
    *(undefined4 *)(param_1 + 0x34) = param_2;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * coprocLibInit @ 0x300E07AC  (примерный размер ~428 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 10
 * Вызывает: calloc, coprocDescriptorsInit, coprocsDiscover, errnoSet, free, taskCreateHookAdd, taskCreateHookDelete, taskDeleteHookAdd, taskDeleteHookDelete, taskSwapHookAdd
 * Вызывают: usrIosCoreInit
 * Константы: 0x300E07AC, 0xFFFFFFFF
 * Данные: DAT_300e0fc0, DAT_300e0fc4, DAT_300e0fc8, DAT_300e0fcc, DAT_300e0fd0, DAT_300e0fd4, DAT_300e0fd8, DAT_300e0fdc
 * ---------------------------------------------------------------- */
undefined4 coprocLibInit(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  size_t __nmemb;
  int iStack_30;
  int local_2c [8];
  
  piVar5 = &iStack_30;
  iVar7 = 8;
  piVar3 = piVar5;
  do {
    piVar3 = piVar3 + 1;
    *piVar3 = 0;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  coprocsDiscover(local_2c);
  __nmemb = 0;
  iVar7 = 8;
  piVar3 = piVar5;
  do {
    piVar3 = piVar3 + 1;
    if (*piVar3 == 0) break;
    __nmemb = __nmemb + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if (__nmemb == 0) {
    uVar2 = 0;
  }
  else {
    piVar3 = (int *)calloc(__nmemb,0x58);
    *DAT_300e0fc0 = piVar3;
    if (piVar3 == (int *)0x0) {
      errnoSet(DAT_300e0fc4);
    }
    else {
      iVar7 = 0;
      if (0 < (int)__nmemb) {
        do {
          piVar5 = piVar5 + 1;
          piVar3[1] = *piVar5;
          if (iVar7 + 1 < (int)__nmemb) {
            *piVar3 = (int)(piVar3 + 0x16);
          }
          piVar3 = piVar3 + 0x16;
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)__nmemb);
      }
      coprocDescriptorsInit(*DAT_300e0fc0);
      puVar6 = DAT_300e0fc0;
      while (uVar2 = DAT_300e0fd0, puVar6 = (undefined4 *)*puVar6, puVar6 != (undefined4 *)0x0) {
        if ((((code *)puVar6[0xd] != (code *)0x0) &&
            (iVar7 = (*(code *)puVar6[0xd])(), uVar4 = DAT_300e0fc8, iVar7 == -1)) ||
           (((code *)puVar6[6] != (code *)0x0 &&
            (iVar7 = (*(code *)puVar6[6])(), uVar4 = DAT_300e0fcc, iVar7 == -1))))
        goto LAB_300e0930;
      }
      iVar7 = taskCreateHookAdd(DAT_300e0fd0);
      uVar1 = DAT_300e0fd4;
      uVar4 = DAT_300e0fdc;
      if (iVar7 != -1) {
        iVar7 = taskDeleteHookAdd(DAT_300e0fd4);
        if (iVar7 != -1) {
          iVar7 = taskSwapHookAdd(DAT_300e0fd8);
          if (iVar7 != -1) {
            return 0;
          }
          taskDeleteHookDelete(uVar1);
        }
        taskCreateHookDelete(uVar2);
        uVar4 = DAT_300e0fdc;
      }
LAB_300e0930:
      errnoSet(uVar4);
      free((void *)*DAT_300e0fc0);
      *DAT_300e0fc0 = 0;
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * coprocTaskCreateHook @ 0x300E0958  (примерный размер ~428 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: bzero, errnoOfTaskSet, taskStackAllot, taskSwapHookAttach
 * Константы: 0x300E0958, 0xFF000000, 0x01000000, 0xFFFFFFF0
 * Данные: DAT_300e0fc0, DAT_300e0fc4, DAT_300e0fd8, DAT_300e0fe0, DAT_300e0fe4
 * ---------------------------------------------------------------- */
void coprocTaskCreateHook(int param_1)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  void *__s;
  int *piVar7;
  
  if (param_1 == 0) {
    errnoOfTaskSet(0,DAT_300e0fe0);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x98) & 0xff000000;
    if (uVar1 != 0) {
      iVar4 = 1;
      uVar5 = 0x1000000;
      iVar6 = 8;
      do {
        iVar6 = iVar6 + -1;
        iVar4 = iVar4 + (uint)((uVar1 & uVar5) != 0);
        uVar5 = uVar5 << 1;
      } while (iVar6 != 0);
      iVar6 = taskStackAllot(param_1,iVar4 * 0xc + 0xc);
      if (iVar6 == 0) {
        errnoOfTaskSet(param_1,DAT_300e0fc4);
      }
      else {
        __s = (void *)(iVar6 + 0xfU & 0xfffffff0);
        bzero(__s,iVar4 * 0xc);
        *(void **)(param_1 + 0xf0) = __s;
        iVar6 = 0;
        piVar7 = DAT_300e0fc0;
        while (piVar7 = (int *)*piVar7, piVar7 != (int *)0x0) {
          if ((piVar7[1] & *(uint *)(param_1 + 0x98)) != 0) {
            if ((code *)piVar7[4] != (code *)0x0) {
              iVar2 = (*(code *)piVar7[4])(param_1);
              if (iVar2 == 0) {
                errnoOfTaskSet(param_1,DAT_300e0fc4);
                if (0 < iVar4) {
                  iVar6 = 0;
                  do {
                    iVar2 = *(int *)(*(int *)(param_1 + 0xf0) + iVar6);
                    if ((iVar2 != 0) &&
                       (pcVar3 = *(code **)(*(int *)(*(int *)(param_1 + 0xf0) + iVar6 + 4) + 0x14),
                       pcVar3 != (code *)0x0)) {
                      (*pcVar3)(iVar2);
                    }
                    iVar6 = iVar6 + 0xc;
                    iVar4 = iVar4 + -1;
                  } while (iVar4 != 0);
                }
                *(undefined4 *)(param_1 + 0xf0) = 0;
                return;
              }
              *(int *)(*(int *)(param_1 + 0xf0) + iVar6 * 0xc) = iVar2;
            }
            iVar2 = iVar6 * 0xc + *(int *)(param_1 + 0xf0);
            *(int **)(iVar2 + 4) = piVar7;
            *(int *)(iVar2 + 8) = param_1;
            iVar6 = iVar6 + 1;
          }
        }
        taskSwapHookAttach(DAT_300e0fd8,param_1,1,*DAT_300e0fe4 != 0);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * coprocTaskDeleteHook @ 0x300E0B04  (примерный размер ~208 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: errnoSet, intCpuLock, intCpuUnlock, taskSwapHookDetach
 * Константы: 0x300E0B04, 0xFF000000
 * Данные: DAT_300e0fd8, DAT_300e0fe0, DAT_300e0fe4
 * ---------------------------------------------------------------- */
void coprocTaskDeleteHook(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 == 0) {
    errnoSet(DAT_300e0fe0);
  }
  else if (((*(uint *)(param_1 + 0x98) & 0xff000000) != 0) &&
          (piVar2 = *(int **)(param_1 + 0xf0), piVar2 != (int *)0x0)) {
    taskSwapHookDetach(DAT_300e0fd8,param_1,1,*DAT_300e0fe4 != 0);
    *(undefined4 *)(param_1 + 0xf0) = 0;
    for (; iVar3 = piVar2[1], iVar3 != 0; piVar2 = piVar2 + 3) {
      iVar1 = *piVar2;
      if ((iVar1 != 0) && (*(int *)(iVar3 + 0x14) != 0)) {
        intCpuLock();
        if ((*(int *)(iVar3 + 0x48) != 0) && (*(int *)(*(int *)(iVar3 + 0x48) + 8) == param_1)) {
          *(undefined4 *)(iVar3 + 0x48) = 0;
        }
        intCpuUnlock();
        (**(code **)(iVar3 + 0x14))(iVar1);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * coprocSave @ 0x300E0BD4  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: coprocTaskSwapHook
 * Константы: 0xFF000000, 0x300E0BD4
 * Данные: DAT_300e0fc0
 * ---------------------------------------------------------------- */
void coprocSave(uint param_1)

{
  int *piVar1;
  
  param_1 = param_1 & 0xff000000;
  piVar1 = DAT_300e0fc0;
  if (param_1 == 0) {
    param_1 = 0xff000000;
  }
  while (piVar1 = (int *)*piVar1, piVar1 != (int *)0x0) {
    if ((((param_1 & piVar1[1]) != 0) && ((undefined4 *)piVar1[0x12] != (undefined4 *)0x0)) &&
       ((code *)piVar1[8] != (code *)0x0)) {
      (*(code *)piVar1[8])(*(undefined4 *)piVar1[0x12]);
      piVar1[0x12] = 0;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * coprocTaskSwapHook @ 0x300E0C3C  (примерный размер ~380 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: coprocSave
 * Константы: 0x300E0C3C
 * ---------------------------------------------------------------- */
void coprocTaskSwapHook(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x94) != *(int *)(param_2 + 0x94)) {
    coprocSave(0);
  }
  piVar3 = *(int **)(param_2 + 0xf0);
  if (piVar3 != (int *)0x0) {
    for (; iVar2 = piVar3[1], iVar2 != 0; piVar3 = piVar3 + 3) {
      piVar1 = *(int **)(iVar2 + 0x48);
      if ((piVar1 != piVar3) && (*piVar3 != 0)) {
        if ((piVar1 != (int *)0x0) && (*(code **)(iVar2 + 0x20) != (code *)0x0)) {
          (**(code **)(iVar2 + 0x20))(*piVar1);
        }
        if (*(code **)(iVar2 + 0x24) != (code *)0x0) {
          (**(code **)(iVar2 + 0x24))(*piVar3);
          *(int **)(iVar2 + 0x48) = piVar3;
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * coprocEnable @ 0x300E0DB8  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoSet
 * Константы: 0xFF000000, 0xFFFFFFFF, 0x300E0DB8, 0x300E0D70, 0x300E0D50, 0x300E0D04, 0x300E0D0C, 0x00FFFFFF
 * Данные: DAT_300e0fc0, DAT_300e0fcc, DAT_300e0fe8
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300e0d70) */
/* WARNING: Removing unreachable block (ram,0x300e0d50) */
/* WARNING: Removing unreachable block (ram,0x300e0d04) */
/* WARNING: Removing unreachable block (ram,0x300e0d0c) */

undefined4 coprocEnable(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar1 = DAT_300e0fcc;
  uVar3 = 0;
  if ((param_1 & 0xffffff) == 0) {
    param_1 = param_1 & 0xff000000;
    piVar4 = DAT_300e0fc0;
    if (param_1 == 0) {
      param_1 = 0xff000000;
    }
    while (piVar4 = (int *)*piVar4, piVar4 != (int *)0x0) {
      if ((((param_1 & piVar4[1]) != 0) && ((code *)piVar4[6] != (code *)0x0)) &&
         (iVar2 = (*(code *)piVar4[6])(), iVar2 == -1)) {
        errnoSet(uVar1);
        uVar3 = 0xffffffff;
      }
    }
  }
  else {
    errnoSet(DAT_300e0fe8);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * coprocDisable @ 0x300E0DC4  (примерный размер ~320 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoSet
 * Константы: 0xFF000000, 0xFFFFFFFF, 0x300E0DC4, 0x300E0D48, 0x300E0D6C, 0x300E0D0C, 0x00FFFFFF
 * Данные: DAT_300e0fc0, DAT_300e0fcc, DAT_300e0fe8
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300e0d48) */
/* WARNING: Removing unreachable block (ram,0x300e0d6c) */
/* WARNING: Removing unreachable block (ram,0x300e0d0c) */

undefined4 coprocDisable(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar3 = 0;
  if ((param_1 & 0xffffff) == 0) {
    param_1 = param_1 & 0xff000000;
    if (param_1 == 0) {
      param_1 = 0xff000000;
    }
    iVar2 = DAT_300e0fcc + 1;
    piVar4 = DAT_300e0fc0;
    while (piVar4 = (int *)*piVar4, piVar4 != (int *)0x0) {
      if ((((param_1 & piVar4[1]) != 0) && ((code *)piVar4[7] != (code *)0x0)) &&
         (iVar1 = (*(code *)piVar4[7])(), iVar1 == -1)) {
        errnoSet(iVar2);
        uVar3 = 0xffffffff;
      }
    }
  }
  else {
    errnoSet(DAT_300e0fe8);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * coprocTaskRegsGet @ 0x300E0F04  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: bcopy, errnoSet, ffsMsb, taskTcb
 * Вызывают: coprocCtxReplicate, coprocMRegs
 * Константы: 0x300E0F04, 0x300E0EBC, 0x300E0ED0, 0x300E0DF8, 0x300E0DFC, 0x300E0E00, 0x00FFFFFF, 0xFFFFFFFF
 * Данные: DAT_300e0fe8, DAT_300e0fec
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300e0ebc) */
/* WARNING: Removing unreachable block (ram,0x300e0ed0) */
/* WARNING: Removing unreachable block (ram,0x300e0df8) */
/* WARNING: Removing unreachable block (ram,0x300e0dfc) */
/* WARNING: Removing unreachable block (ram,0x300e0e00) */

undefined4 coprocTaskRegsGet(undefined4 param_1,uint param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  iVar2 = taskTcb(param_1);
  uVar4 = DAT_300e0fe8;
  if ((((param_3 != (void *)0x0) && (iVar2 != 0)) && ((param_2 & 0xffffff) == 0)) &&
     ((iVar3 = ffsMsb(param_2), uVar4 = DAT_300e0fe8, (param_2 & ~(1 << (iVar3 - 1U & 0xff))) == 0
      && (puVar5 = *(undefined4 **)(iVar2 + 0xf0), uVar4 = DAT_300e0fec, puVar5 != (undefined4 *)0x0
         )))) {
    iVar2 = puVar5[1];
    while (uVar4 = DAT_300e0fe8, iVar2 != 0) {
      if (*(uint *)(iVar2 + 4) == param_2) {
        if ((void *)*puVar5 != (void *)0x0) {
          if (*(code **)(iVar2 + 0x28) == (code *)0x0) {
            bcopy((void *)*puVar5,param_3,*(size_t *)(iVar2 + 8));
          }
          else {
            (**(code **)(iVar2 + 0x28))();
          }
          return 0;
        }
        break;
      }
      piVar1 = puVar5 + 4;
      puVar5 = puVar5 + 3;
      iVar2 = *piVar1;
    }
  }
  errnoSet(uVar4);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * coprocTaskRegsSet @ 0x300E0F18  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: bcopy, errnoSet, ffsMsb, taskTcb
 * Константы: 0x300E0F18, 0x300E0DFC, 0x300E0E98, 0x300E0EAC, 0x00FFFFFF, 0xFFFFFFFF
 * Данные: DAT_300e0fe8, DAT_300e0fec
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300e0dfc) */
/* WARNING: Removing unreachable block (ram,0x300e0e98) */
/* WARNING: Removing unreachable block (ram,0x300e0eac) */

undefined4 coprocTaskRegsSet(undefined4 param_1,uint param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  iVar2 = taskTcb(param_1);
  uVar4 = DAT_300e0fe8;
  if ((((param_3 != (void *)0x0) && (iVar2 != 0)) && ((param_2 & 0xffffff) == 0)) &&
     ((iVar3 = ffsMsb(param_2), uVar4 = DAT_300e0fe8, (param_2 & ~(1 << (iVar3 - 1U & 0xff))) == 0
      && (puVar5 = *(undefined4 **)(iVar2 + 0xf0), uVar4 = DAT_300e0fec, puVar5 != (undefined4 *)0x0
         )))) {
    iVar2 = puVar5[1];
    while (uVar4 = DAT_300e0fe8, iVar2 != 0) {
      if (*(uint *)(iVar2 + 4) == param_2) {
        if ((void *)*puVar5 != (void *)0x0) {
          if (*(code **)(iVar2 + 0x2c) == (code *)0x0) {
            bcopy(param_3,(void *)*puVar5,*(size_t *)(iVar2 + 8));
          }
          else {
            (**(code **)(iVar2 + 0x2c))();
          }
          return 0;
        }
        break;
      }
      piVar1 = puVar5 + 4;
      puVar5 = puVar5 + 3;
      iVar2 = *piVar1;
    }
  }
  errnoSet(uVar4);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * coprocShowOnDebug @ 0x300E0F2C  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFF000000, 0x300E0F2C
 * Данные: DAT_300e0fc0
 * ---------------------------------------------------------------- */
uint coprocShowOnDebug(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  param_2 = param_2 & 0xff000000;
  if (param_2 == 0) {
    param_2 = 0xff000000;
  }
  uVar2 = 0;
  for (puVar3 = (undefined4 *)*DAT_300e0fc0; puVar3 != (undefined4 *)0x0;
      puVar3 = (undefined4 *)*puVar3) {
    if ((param_2 & puVar3[1]) != 0) {
      uVar1 = puVar3[0x13];
      puVar3[0x13] = param_1;
      uVar2 = uVar2 | uVar1;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * coprocCtxStorageSizeGet @ 0x300E0F74  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFF000000, 0x300E0F74
 * Данные: DAT_300e0fc0
 * ---------------------------------------------------------------- */
int coprocCtxStorageSizeGet(uint param_1)

{
  int iVar1;
  int *piVar2;
  
  param_1 = param_1 & 0xff000000;
  if (param_1 == 0) {
    param_1 = 0xff000000;
  }
  piVar2 = (int *)*DAT_300e0fc0;
  iVar1 = 0;
  if (piVar2 != (int *)0x0) {
    do {
      if ((param_1 & piVar2[1]) != 0) {
        iVar1 = iVar1 + piVar2[2] + 0xc;
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    if (0 < iVar1) {
      iVar1 = iVar1 + 0x18;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * coprocShowInit @ 0x300E0FF0  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300E0FF0
 * Данные: DAT_300e14dc, DAT_300e14e0, DAT_300e14e4, DAT_300e14e8
 * ---------------------------------------------------------------- */
void coprocShowInit(void)

{
  *DAT_300e14e0 = DAT_300e14dc;
  *DAT_300e14e8 = DAT_300e14e4;
  return;
}

/* ----------------------------------------------------------------
 * getSymNames @ 0x300E100C  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: cplusDemangle, sprintf
 * Вызывают: coprocShow
 * Константы: 0x300E100C
 * Данные: DAT_300e14ec, DAT_300e14f0, DAT_300e14f4, DAT_300e14f8, DAT_300e14fc, DAT_300e1500, DAT_300e1504, DAT_300e1508
 * ---------------------------------------------------------------- */
void getSymNames(int param_1,int param_2)

{
  char *__format;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  char *__s;
  int iVar4;
  undefined4 local_224;
  undefined4 local_220;
  int local_21c;
  undefined1 auStack_218 [512];
  
  if ((((param_2 != 0) && (param_1 != 0)) && (*DAT_300e14ec != 0)) && (*DAT_300e14f0 != 0)) {
    iVar4 = 0;
    piVar3 = (int *)(param_2 + -4);
    do {
      piVar3 = piVar3 + 1;
      if (*piVar3 == 0) {
        sprintf((char *)(iVar4 * 0x28 + param_1),DAT_300e14f4,DAT_300e14f8,DAT_300e14fc);
      }
      else {
        __s = (char *)(iVar4 * 0x28 + param_1);
        iVar1 = (*(code *)*DAT_300e14f0)(*DAT_300e14ec,0,*piVar3,0,0,&local_224);
        if (((iVar1 == 0) && (iVar1 = (*(code *)*DAT_300e1500)(local_224,&local_220), iVar1 == 0))
           && (iVar1 = (*(code *)*DAT_300e1504)(local_224,&local_21c), iVar1 == 0)) {
          uVar2 = cplusDemangle(local_220,auStack_218,0x200);
          iVar1 = sprintf(__s,DAT_300e1508,uVar2);
          __format = DAT_300e150c;
          if (*piVar3 == local_21c) {
            __format = DAT_300e1510;
          }
          sprintf(__s + iVar1,__format);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xc);
  }
  return;
}

/* ----------------------------------------------------------------
 * coprocShow @ 0x300E1160  (примерный размер ~276 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: getSymNames, printf
 * Константы: 0x300E1160
 * Данные: DAT_300e1514, DAT_300e1520, DAT_300e1524, DAT_300e1528, DAT_300e152c, DAT_300e1530, DAT_300e1534, DAT_300e1538
 * ---------------------------------------------------------------- */
void coprocShow(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 auStack_224 [40];
  undefined1 local_1fc [40];
  undefined1 auStack_1d4 [40];
  undefined1 auStack_1ac [40];
  undefined1 auStack_184 [40];
  undefined1 auStack_15c [40];
  undefined1 auStack_134 [40];
  undefined1 auStack_10c [40];
  undefined1 auStack_e4 [40];
  undefined1 auStack_bc [40];
  undefined1 auStack_94 [40];
  undefined1 auStack_6c [40];
  undefined1 auStack_44 [40];
  
  puVar1 = auStack_224;
  iVar2 = 0xc;
  do {
    puVar1 = puVar1 + 0x28;
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  for (puVar3 = (undefined4 *)*DAT_300e1514; puVar3 != (undefined4 *)0x0;
      puVar3 = (undefined4 *)*puVar3) {
    if ((code *)puVar3[0xf] != (code *)0x0) {
      (*(code *)puVar3[0xf])();
    }
    getSymNames(local_1fc,puVar3 + 4);
    printf(DAT_300e1520,puVar3[1]);
    printf(DAT_300e1524,puVar3[2]);
    printf(DAT_300e1528,local_1fc,auStack_1d4);
    printf(DAT_300e152c,auStack_1ac,auStack_184);
    printf(DAT_300e1530,auStack_15c,auStack_134);
    printf(DAT_300e1534,auStack_10c,auStack_e4);
    printf(DAT_300e1538,auStack_bc,auStack_94);
    printf(DAT_300e153c,auStack_6c,auStack_44);
  }
  return;
}

/* ----------------------------------------------------------------
 * coprocTaskRegsShow @ 0x300E1274  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: printf, puts, taskTcb
 * Константы: 0xFF000000, 0x300E1274
 * Данные: DAT_300e1540, DAT_300e1544
 * ---------------------------------------------------------------- */
void coprocTaskRegsShow(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    puts(DAT_300e1540);
  }
  else {
    puVar2 = *(undefined4 **)(iVar1 + 0xf0);
    if (puVar2 == (undefined4 *)0x0) {
      printf(DAT_300e1544);
    }
    else {
      param_2 = param_2 & 0xff000000;
      if (param_2 == 0) {
        param_2 = 0xff000000;
      }
      for (; iVar1 = puVar2[1], iVar1 != 0; puVar2 = puVar2 + 3) {
        if (((param_2 & *(uint *)(iVar1 + 4)) != 0) && (*(code **)(iVar1 + 0x38) != (code *)0x0)) {
          (**(code **)(iVar1 + 0x38))(*puVar2);
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * coprocRegListShow @ 0x300E1300  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: taskRegsModify
 * Константы: 0x300E1300
 * Данные: DAT_300e1514
 * ---------------------------------------------------------------- */
void coprocRegListShow(void)

{
  int *piVar1;
  
  piVar1 = DAT_300e1514;
  while (piVar1 = (int *)*piVar1, piVar1 != (int *)0x0) {
    if ((code *)piVar1[0x11] != (code *)0x0) {
      (*(code *)piVar1[0x11])();
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * coprocCtxReplicate @ 0x300E133C  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: coprocTaskRegsGet, errnoSet, ffsMsb, free, memalign
 * Вызывают: coprocMRegs
 * Константы: 0x300E133C
 * Данные: DAT_300e1514, DAT_300e1548, DAT_300e154c
 * ---------------------------------------------------------------- */
void * coprocCtxReplicate(undefined4 param_1,uint param_2)

{
  int iVar1;
  void *__ptr;
  int *piVar2;
  
  iVar1 = ffsMsb(param_2);
  if ((param_2 == 0) || (piVar2 = DAT_300e1514, (param_2 & ~(1 << (iVar1 - 1U & 0xff))) != 0)) {
    errnoSet(DAT_300e1548);
  }
  else {
    do {
      piVar2 = (int *)*piVar2;
      if (piVar2 == (int *)0x0) {
        return (void *)0x0;
      }
    } while (piVar2[1] != param_2);
    __ptr = (void *)memalign(piVar2[3],piVar2[2]);
    if (__ptr == (void *)0x0) {
      errnoSet(DAT_300e154c);
    }
    else {
      iVar1 = coprocTaskRegsGet(param_1,param_2,__ptr);
      if (iVar1 != -1) {
        return __ptr;
      }
      free(__ptr);
    }
  }
  return (void *)0x0;
}

/* ----------------------------------------------------------------
 * coprocMRegs @ 0x300E13E8  (примерный размер ~360 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: coprocCtxReplicate, coprocTaskRegsGet, free
 * Вызывают: taskRegsModify
 * Константы: 0x300E13E8
 * Данные: DAT_300e1514
 * ---------------------------------------------------------------- */
int coprocMRegs(int param_1,undefined4 param_2,int *param_3)

{
  void *__ptr;
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = *(uint *)(param_1 + 0x98);
  iVar2 = 0;
  if (uVar1 == 0) {
    iVar2 = 0;
  }
  else {
    for (piVar3 = (int *)*DAT_300e1514; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      if ((uVar1 & piVar3[1]) != 0) {
        __ptr = (void *)coprocCtxReplicate(param_1,piVar3[1]);
        if (__ptr == (void *)0x0) {
          return -1;
        }
        iVar2 = coprocTaskRegsGet(param_1,piVar3[1],__ptr);
        if ((iVar2 == -1) ||
           (((code *)piVar3[0x10] != (code *)0x0 &&
            ((iVar2 = (*(code *)piVar3[0x10])(param_1,__ptr,param_2,param_3), iVar2 == -1 ||
             (*param_3 == 1)))))) {
          free(__ptr);
          return iVar2;
        }
        free(__ptr);
      }
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300e1550 @ 0x300E1550  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: bootStringToStruct
 * Вызывают: edrSystemDebugModeInit
 * Константы: 0x300E1550
 * Данные: DAT_300e1628
 * ---------------------------------------------------------------- */
uint FUN_300e1550(void)

{
  char *pcVar1;
  int iVar2;
  undefined1 auStack_2bc [684];
  int iStack_10;
  
  pcVar1 = (char *)bootStringToStruct(*DAT_300e1628,auStack_2bc);
  iVar2 = 0;
  if ((pcVar1 != (char *)0x0) && (*pcVar1 == '\0')) {
    iVar2 = iStack_10;
  }
  return iVar2 >> 10 & 1;
}

/* ----------------------------------------------------------------
 * putenv @ 0x300E1C10  (примерный размер ~540 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 10
 * Вызывает: FUN_300e1b70, bzero, free, malloc, realloc, semMGiveScalable, semMTakeScalable, strcpy, strlen, taskTcb
 * Константы: 0x300E1C10, 0xFFFFFFFF
 * Данные: DAT_300e1fcc, DAT_300e1fd0, DAT_300e1fe8, DAT_300e1fec
 * ---------------------------------------------------------------- */
int putenv(char *__string)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  size_t sVar7;
  void *pvVar8;
  int iVar9;
  char *pcVar10;
  
  iVar4 = taskTcb(0);
  uVar3 = DAT_300e1fec;
  cVar1 = *__string;
  pcVar10 = __string;
  while ((((cVar1 != ' ' && (cVar1 = *pcVar10, cVar1 != '\t')) && (cVar1 != '=')) && (cVar1 != '\0')
         )) {
    pcVar10 = pcVar10 + 1;
    cVar1 = *pcVar10;
  }
  bVar2 = false;
  iVar5 = semMTakeScalable(*DAT_300e1fe8,0xffffffff,DAT_300e1fec);
  if (iVar5 == -1) {
    iVar4 = -1;
  }
  else {
    puVar6 = (undefined4 *)FUN_300e1b70(__string,(int)pcVar10 - (int)__string);
    if (puVar6 == (undefined4 *)0x0) {
      pvVar8 = *(void **)(iVar4 + 0x10c);
      if (pvVar8 == (void *)0x0) {
        pvVar8 = (void *)*DAT_300e1fcc;
        iVar9 = *DAT_300e1fd0;
        iVar5 = DAT_300e1fd0[1];
        puVar6 = (undefined4 *)((int)pvVar8 + iVar9 * 4);
      }
      else {
        iVar9 = *(int *)(iVar4 + 0x114);
        iVar5 = *(int *)(iVar4 + 0x110);
        puVar6 = (undefined4 *)((int)pvVar8 + iVar9 * 4);
      }
      bVar2 = true;
      if (iVar5 == iVar9) {
        pvVar8 = realloc(pvVar8,iVar5 * 4 + 200);
        if (pvVar8 == (void *)0x0) {
          semMGiveScalable(*DAT_300e1fe8,uVar3);
          return -1;
        }
        bzero((void *)((int)pvVar8 + iVar5 * 4),200);
        if (*(int *)(iVar4 + 0x10c) == 0) {
          *DAT_300e1fcc = pvVar8;
          DAT_300e1fd0[1] = DAT_300e1fd0[1] + 0x32;
        }
        else {
          *(void **)(iVar4 + 0x10c) = pvVar8;
          *(int *)(iVar4 + 0x110) = *(int *)(iVar4 + 0x110) + 0x32;
        }
        puVar6 = (undefined4 *)((int)pvVar8 + iVar9 * 4);
      }
    }
    else {
      free((void *)*puVar6);
    }
    sVar7 = strlen(__string);
    pcVar10 = (char *)malloc(sVar7 + 1);
    *puVar6 = pcVar10;
    if (pcVar10 == (char *)0x0) {
      semMGiveScalable(*DAT_300e1fe8,uVar3);
      iVar4 = -1;
    }
    else {
      if (bVar2) {
        if (*(int *)(iVar4 + 0x10c) == 0) {
          *DAT_300e1fd0 = *DAT_300e1fd0 + 1;
        }
        else {
          *(int *)(iVar4 + 0x114) = *(int *)(iVar4 + 0x114) + 1;
        }
      }
      strcpy(pcVar10,__string);
      semMGiveScalable(*DAT_300e1fe8,uVar3);
      iVar4 = 0;
    }
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * getenv @ 0x300E1E2C  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_300e1b70, semMGiveScalable, semMTakeScalable, strlen
 * Вызывают: __getDstInfo, __getZoneInfo
 * Константы: 0x300E1E2C, 0xFFFFFFFF
 * Данные: DAT_300e1fe8, DAT_300e1fec
 * ---------------------------------------------------------------- */
char * getenv(char *__name)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  size_t sVar5;
  int *piVar6;
  char *pcVar7;
  
  uVar3 = DAT_300e1fec;
  puVar2 = DAT_300e1fe8;
  iVar4 = semMTakeScalable(*DAT_300e1fe8,0xffffffff,DAT_300e1fec);
  if (iVar4 == -1) {
    return (char *)0x0;
  }
  sVar5 = strlen(__name);
  piVar6 = (int *)FUN_300e1b70(__name,sVar5);
  if (piVar6 == (int *)0x0) {
    semMGiveScalable(*puVar2,uVar3);
    return (char *)0x0;
  }
  sVar5 = strlen(__name);
  for (pcVar7 = (char *)(*piVar6 + sVar5);
      ((cVar1 = *pcVar7, cVar1 == ' ' || (cVar1 == '\t')) || (cVar1 == '=')); pcVar7 = pcVar7 + 1) {
  }
  semMGiveScalable(*puVar2,uVar3);
  return pcVar7;
}

/* ----------------------------------------------------------------
 * jobExcAdd @ 0x300E2278  (примерный размер ~196 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: semGive
 * Вызывают: FUN_30103738, FUN_301158ec, excJobAdd, jobAdd, vxdbgBpMsgPost
 * Константы: 0x300E2278, 0xFFFFFFFF
 * Данные: DAT_300e251c, DAT_300e2524, DAT_300e2550, DAT_300e2554
 * ---------------------------------------------------------------- */
undefined4
jobExcAdd(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
         undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(DAT_300e2550 + (uint)DAT_300e251c[2] * 0x1c);
  uVar1 = DAT_300e251c[2] + 1 & DAT_300e251c[1];
  if (uVar1 == *DAT_300e251c) {
    *DAT_300e2554 = *DAT_300e2554 + 1;
    uVar2 = 0xffffffff;
  }
  else {
    DAT_300e251c[2] = uVar1;
    *puVar3 = param_1;
    puVar3[1] = param_2;
    puVar3[2] = param_3;
    puVar3[3] = param_4;
    puVar3[4] = param_5;
    puVar3[5] = param_6;
    puVar3[6] = param_7;
    uVar2 = semGive(DAT_300e2524);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * jobAdd @ 0x300E233C  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 2
 * Вызывает: intContext, jobExcAdd
 * Вызывают: shellAbort, shellCompatibleSet, shellGenericInit, shellRestart
 * Константы: 0x300E233C
 * Данные: DAT_300e2558
 * ---------------------------------------------------------------- */
void jobAdd(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  
  iVar1 = intContext();
  if ((iVar1 == 0) && ((code *)*DAT_300e2558 != (code *)0x0)) {
    (*(code *)*DAT_300e2558)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    jobExcAdd(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}

/* ----------------------------------------------------------------
 * handleInit @ 0x300E256C  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 9 | Вызывает: 0
 * Вызывают: classInit, hashTblInit, moduleInit, moduleLibInit, moduleSectionRegister, objCoreInit, stdioFpCreate, symTblCreate, vfprintf
 * Константы: 0x300E256C
 * ---------------------------------------------------------------- */
undefined4 handleInit(undefined4 *param_1,undefined1 param_2)

{
  param_1[1] = param_1;
  *(undefined1 *)((int)param_1 + 10) = param_2;
  *param_1 = 0;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * handleTerminate @ 0x300E2588  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 0
 * Вызывают: hashTblDestroy, moduleDescDestroy, moduleSectionDescFree, stdioFpDestroy, symTblDelete, vfprintf
 * Константы: 0x300E2588
 * ---------------------------------------------------------------- */
undefined4 handleTerminate(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 10) = 0xff;
  return 0;
}

/* ----------------------------------------------------------------
 * handleVerify @ 0x300E25A0  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: handleShow
 * Константы: 0x300E25A0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 handleVerify(int param_1,int param_2)

{
  if ((*(int *)(param_1 + 4) == param_1) && (*(char *)(param_1 + 10) == param_2)) {
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * handleTypeGet @ 0x300E25C8  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300E25C8
 * ---------------------------------------------------------------- */
int handleTypeGet(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) != param_1) {
    return -1;
  }
  iVar1 = (int)*(char *)(param_1 + 10);
  if (((0 < iVar1) && (iVar1 < 0x70)) && (0x4d < iVar1 - 0x16U)) {
    return iVar1;
  }
  return -1;
}

/* ----------------------------------------------------------------
 * handleContextGetBase @ 0x300E2614  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: handleContextGet
 * Константы: 0x300E2614
 * ---------------------------------------------------------------- */
void handleContextGetBase(undefined4 *param_1,undefined4 *param_2,uint *param_3)

{
  *param_2 = *param_1;
  *param_3 = (uint)*(byte *)((int)param_1 + 0xb);
  return;
}

/* ----------------------------------------------------------------
 * handleContextGet @ 0x300E2628  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: handleContextGetBase
 * Вызывают: objContextGet
 * Константы: 0xFFFFFFFF, 0x300E2628
 * ---------------------------------------------------------------- */
undefined4 handleContextGet(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) == param_1) {
    iVar2 = (int)*(char *)(param_1 + 10);
    if (((iVar2 < 1) || (0x6f < iVar2)) || (iVar2 - 0x16U < 0x4e)) {
      uVar1 = 0xffffffff;
    }
    else {
      handleContextGetBase();
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * handleContextSet @ 0x300E2674  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: objContextSet
 * Константы: 0xFFFFFFFF, 0x300E2674
 * ---------------------------------------------------------------- */
undefined4 handleContextSet(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((undefined4 *)param_1[1] == param_1) {
    iVar2 = (int)*(char *)((int)param_1 + 10);
    if (((iVar2 < 1) || (0x6f < iVar2)) || (iVar2 - 0x16U < 0x4e)) {
      uVar1 = 0xffffffff;
    }
    else if (param_3 < 5) {
      *param_1 = param_2;
      *(char *)((int)param_1 + 0xb) = (char)param_3;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * handleShowConnect @ 0x300E26E0  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: moduleShowInit, symShowInit
 * Константы: 0x300E26E0, 0xFFFFFFFF
 * Данные: DAT_300e277c
 * ---------------------------------------------------------------- */
undefined4 handleShowConnect(int param_1,undefined4 param_2)

{
  if (0xb < param_1 - 100U) {
    return 0xffffffff;
  }
  *(undefined4 *)(DAT_300e277c + param_1 * 4) = param_2;
  return 0;
}

/* ----------------------------------------------------------------
 * handleShow @ 0x300E2704  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: handleVerify, puts
 * Вызывают: lkup
 * Константы: 0xFFFFFFFF, 0x300E2704
 * Данные: DAT_300e277c, DAT_300e2780
 * ---------------------------------------------------------------- */
undefined4 handleShow(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  iVar1 = handleVerify(param_1,(int)*(char *)(param_1 + 10));
  if (iVar1 == 0) {
    if ((int)*(char *)(param_1 + 10) - 100U < 0xc) {
      pcVar3 = *(code **)(DAT_300e277c + *(char *)(param_1 + 10) * 4);
      if (pcVar3 == (code *)0x0) {
        puts(DAT_300e2780);
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = (*pcVar3)(param_1,param_2);
      }
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
 * hashLibInit @ 0x300E2784  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrKernelExtraInit
 * Константы: 0x300E2784
 * ---------------------------------------------------------------- */
undefined4 hashLibInit(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * hashTblInit @ 0x300E278C  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: handleInit, sllInit
 * Вызывают: hashTblCreate
 * Константы: 0xFFFFFFFF, 0x300E278C
 * ---------------------------------------------------------------- */
undefined4
hashTblInit(int param_1,int param_2,uint param_3,int param_4,int param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
  if (((-1 < (int)param_3) && (param_1 != 0)) && (param_2 != 0)) {
    if ((param_4 != 0) && (param_5 != 0)) {
      iVar1 = 1 << (param_3 & 0xff);
      *(int *)(param_1 + 0xc) = iVar1;
      *(int *)(param_1 + 0x10) = param_4;
      *(int *)(param_1 + 0x14) = param_5;
      *(undefined4 *)(param_1 + 0x18) = param_6;
      *(int *)(param_1 + 0x1c) = param_2;
      iVar2 = 0;
      if (0 < iVar1) {
        do {
          sllInit(*(int *)(param_1 + 0x1c) + iVar2 * 8);
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 0xc));
      }
      handleInit(param_1,100);
      return 0;
    }
    return 0xffffffff;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * hashTblCreate @ 0x300E2830  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: hashTblInit, malloc
 * Вызывают: symTblCreate
 * Константы: 0x300E2830
 * ---------------------------------------------------------------- */
void * hashTblCreate(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  
  if ((int)param_1 < 0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = malloc((1 << (param_1 & 0xff)) * 8 + 0x20);
    if (pvVar1 != (void *)0x0) {
      hashTblInit(pvVar1,(int)pvVar1 + 0x20,param_1,param_2,param_3,param_4);
    }
  }
  return pvVar1;
}

/* ----------------------------------------------------------------
 * hashTblDestroy @ 0x300E2898  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: free, handleTerminate
 * Вызывают: hashTblDelete, hashTblTerminate, symTblDelete
 * Константы: 0x300E2898, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 hashTblDestroy(void *param_1,int param_2)

{
  if ((*(void **)((int)param_1 + 4) == param_1) && (*(char *)((int)param_1 + 10) == 'd')) {
    handleTerminate();
    if (param_2 != 0) {
      free(param_1);
    }
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * hashTblDelete @ 0x300E28E4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: hashTblDestroy
 * Вызывают: symTblCreate
 * Константы: 0x300E28E4
 * ---------------------------------------------------------------- */
void hashTblDelete(undefined4 param_1)

{
  hashTblDestroy(param_1,1);
  return;
}

/* ----------------------------------------------------------------
 * hashTblTerminate @ 0x300E28EC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: hashTblDestroy
 * Константы: 0x300E28EC
 * ---------------------------------------------------------------- */
void hashTblTerminate(undefined4 param_1)

{
  hashTblDestroy(param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * hashTblPut @ 0x300E28F4  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: sllPutAtHead
 * Вызывают: symTblAdd
 * Константы: 0x300E28F4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 hashTblPut(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = *(int *)(param_1 + 4) == param_1;
  if (bVar3) {
    bVar3 = *(char *)(param_1 + 10) == 'd';
  }
  if (bVar3) {
    iVar2 = (**(code **)(param_1 + 0x14))
                      (*(undefined4 *)(param_1 + 0xc),param_2,*(undefined4 *)(param_1 + 0x18));
    sllPutAtHead(*(int *)(param_1 + 0x1c) + iVar2 * 8,param_2);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * hashTblFind @ 0x300E2950  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: symFindSymbol, symTblAdd, symTblRemove
 * Константы: 0x300E2950
 * ---------------------------------------------------------------- */
int * hashTblFind(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  if ((*(int *)(param_1 + 4) == param_1) && (*(char *)(param_1 + 10) == 'd')) {
    iVar1 = (**(code **)(param_1 + 0x14))
                      (*(undefined4 *)(param_1 + 0xc),param_2,*(undefined4 *)(param_1 + 0x18));
    piVar2 = *(int **)(*(int *)(param_1 + 0x1c) + iVar1 * 8);
    while ((piVar2 != (int *)0x0 &&
           (iVar1 = (**(code **)(param_1 + 0x10))(param_2,piVar2,param_3), iVar1 == 0))) {
      piVar2 = (int *)*piVar2;
    }
  }
  else {
    piVar2 = (int *)0x0;
  }
  return piVar2;
}

/* ----------------------------------------------------------------
 * hashTblRemove @ 0x300E29E4  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: sllPrevious, sllRemove
 * Вызывают: symTblRemove, symTblSymSetRemove
 * Константы: 0x300E29E4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 hashTblRemove(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = *(int *)(param_1 + 4) == param_1;
  if (bVar3) {
    bVar3 = *(char *)(param_1 + 10) == 'd';
  }
  if (bVar3) {
    iVar2 = (**(code **)(param_1 + 0x14))
                      (*(undefined4 *)(param_1 + 0xc),param_2,*(undefined4 *)(param_1 + 0x18));
    uVar1 = sllPrevious(*(int *)(param_1 + 0x1c) + iVar2 * 8,param_2);
    sllRemove(*(int *)(param_1 + 0x1c) + iVar2 * 8,param_2,uVar1);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * hashTblEach @ 0x300E2A58  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: sllEach
 * Вызывают: symEach
 * Константы: 0x300E2A58
 * ---------------------------------------------------------------- */
int hashTblEach(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if ((*(int *)(param_1 + 4) == param_1) && (*(char *)(param_1 + 10) == 'd')) {
    iVar2 = 0;
    if (*(int *)(param_1 + 0xc) < 1) {
      return iVar1;
    }
    do {
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = sllEach(*(int *)(param_1 + 0x1c) + iVar2 * 8,param_2,param_3);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0xc));
    return iVar1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * hashFuncIterScale @ 0x300E2AD8  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300E2AD8
 * ---------------------------------------------------------------- */
uint hashFuncIterScale(int param_1,int param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  
  pbVar2 = *(byte **)(param_2 + 4);
  uVar3 = 0;
  bVar1 = *pbVar2;
  while (bVar1 != 0) {
    bVar1 = *pbVar2;
    pbVar2 = pbVar2 + 1;
    uVar3 = uVar3 * param_3 + (uint)bVar1;
    bVar1 = *pbVar2;
  }
  return uVar3 & param_1 - 1U;
}

/* ----------------------------------------------------------------
 * hashFuncModulo @ 0x300E2B14  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __div32
 * Константы: 0x300E2B14
 * ---------------------------------------------------------------- */
uint hashFuncModulo(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 4);
  iVar1 = __div32(iVar2,param_3);
  return iVar2 - param_3 * iVar1 & param_1 - 1U;
}

/* ----------------------------------------------------------------
 * hashFuncMultiply @ 0x300E2B44  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: ffsMsb
 * Константы: 0x300E2B44
 * ---------------------------------------------------------------- */
uint hashFuncMultiply(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 4);
  iVar1 = ffsMsb();
  return iVar2 * param_3 >> (0x21U - iVar1 & 0xff) & param_1 - 1U;
}

/* ----------------------------------------------------------------
 * hashKeyCmp @ 0x300E2B6C  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300E2B6C
 * ---------------------------------------------------------------- */
bool hashKeyCmp(int param_1,int param_2)

{
  return *(int *)(param_1 + 4) == *(int *)(param_2 + 4);
}

/* ----------------------------------------------------------------
 * hashKeyStrCmp @ 0x300E2B84  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: strcmp
 * Константы: 0x300E2B84
 * ---------------------------------------------------------------- */
bool hashKeyStrCmp(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)(param_1 + 4),*(char **)(param_2 + 4));
  return iVar1 == 0;
}

/* ----------------------------------------------------------------
 * jobLibInit @ 0x300E2D3C  (примерный размер ~212 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: semBInit, semMInit, taskSpawn
 * Вызывают: usrIosExtraInit
 * Константы: 0xFFFFFFFF, 0x300E2D3C
 * Данные: DAT_300e30e0, DAT_300e30e4, DAT_300e30e8, DAT_300e30ec, DAT_300e30f0, DAT_300e30f4, DAT_300e30f8, DAT_300e30fc
 * ---------------------------------------------------------------- */
undefined4 jobLibInit(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = semMInit(DAT_300e30e0,0x2d);
  if (iVar1 == 0) {
    iVar1 = semMInit(DAT_300e30e4,0x29);
    if (iVar1 == 0) {
      iVar1 = semBInit(DAT_300e30e8,0x21,0);
      if (iVar1 == 0) {
        iVar1 = taskSpawn(DAT_300e30f0,0,DAT_300e30f4,param_1,DAT_300e30ec,0,0,0,0,0,0,0,0,0,0);
        *DAT_300e30f8 = iVar1;
        if (iVar1 == -1) {
          uVar2 = 0xffffffff;
        }
        else {
          *DAT_300e3100 = DAT_300e30fc;
          *DAT_300e3104 = 1;
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0xffffffff;
      }
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
 * FUN_300e2e10 @ 0x300E2E10  (примерный размер ~504 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 12
 * Вызывает: __errno, edrErrorInjectStub, edrKernelFatalPolicyHandler, errnoSet, intContext, semGive, semMTakeByProxy, semTake, snprintf, taskPriorityGet, taskPrioritySet, taskUnsafe
 * Константы: 0xFFFFFFFF, 0x300E2E10, 0x04000000
 * Данные: DAT_300e30e0, DAT_300e30e4, DAT_300e30e8, DAT_300e30f8, DAT_300e3104, DAT_300e3108, DAT_300e310c, DAT_300e3110
 * ---------------------------------------------------------------- */
undefined4
FUN_300e2e10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  char acStack_8c [100];
  
  iVar2 = intContext();
  uVar3 = DAT_300e30e0;
  if (iVar2 == 0) {
    if (*DAT_300e3104 == 0) {
      errnoSet(0x16);
      uVar3 = 0xffffffff;
    }
    else {
      iVar4 = semTake(DAT_300e30e0,0xffffffff);
      iVar2 = DAT_300e30e4;
      if (iVar4 == -1) {
        uVar3 = 0xffffffff;
      }
      else {
        iVar4 = semTake(DAT_300e30e4,0xffffffff);
        puVar1 = DAT_300e310c;
        if (iVar4 == -1) {
          semGive(uVar3);
          uVar3 = 0xffffffff;
        }
        else {
          *DAT_300e310c = param_1;
          puVar1[1] = param_2;
          puVar1[2] = param_3;
          puVar1[3] = param_4;
          puVar1[4] = param_5;
          puVar1[5] = param_6;
          puVar1[6] = param_7;
          puVar1[9] = param_8;
          iVar4 = *DAT_300e3110;
          puVar1[7] = iVar4;
          taskPriorityGet(iVar4,puVar1 + 8);
          puVar5 = DAT_300e30f8;
          taskPrioritySet(*DAT_300e30f8,puVar1[8]);
          *(int *)(*DAT_300e3110 + 0xac) = *(int *)(*DAT_300e3110 + 0xac) + 1;
          semGive(iVar2);
          iVar4 = semMTakeByProxy(iVar2,*puVar5);
          if (iVar4 != 0) {
            puVar5 = (undefined4 *)__errno();
            snprintf(acStack_8c,100,DAT_300e3114,*puVar5,*(int *)(iVar2 + 0x54),
                     *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0x7c),puVar1[7],puVar1[8]);
            edrErrorInjectStub(0x11,DAT_300e3118,DAT_300e311c,0,0,0,acStack_8c);
            edrKernelFatalPolicyHandler(0);
          }
          semGive(uVar3);
          semGive(DAT_300e30e8);
          if ((param_8 != 0) && ((code *)*DAT_300e3120 != (code *)0x0)) {
            (*(code *)*DAT_300e3120)(0x4000000,0,0xffffffff,0);
          }
          taskUnsafe();
          uVar3 = 0;
        }
      }
    }
  }
  else {
    errnoSet(DAT_300e3108);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300e3008 @ 0x300E3008  (примерный размер ~292 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: __errno, objVerify, semGive, semTake, taskPrioritySet
 * Константы: 0x300E3008, 0xFFFFFFFF, 0x04000000
 * Данные: DAT_300e30e4, DAT_300e30e8, DAT_300e310c, DAT_300e3110, DAT_300e3124, DAT_300e3128
 * ---------------------------------------------------------------- */
void FUN_300e3008(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  piVar3 = DAT_300e3110;
  *(int *)(*DAT_300e3110 + 0xac) = *(int *)(*DAT_300e3110 + 0xac) + 1;
  puVar2 = DAT_300e310c;
  uVar1 = DAT_300e30e8;
  do {
    semTake(uVar1,0xffffffff);
    uVar4 = (*(code *)*puVar2)(puVar2[1],puVar2[2],puVar2[3],puVar2[4],puVar2[5],puVar2[6]);
    puVar5 = (undefined4 *)__errno();
    *puVar5 = 0;
    taskPrioritySet(*piVar3,0);
    if ((puVar2[9] != 0) && (iVar6 = objVerify(puVar2[7],*DAT_300e3124), iVar6 == 0)) {
      *(undefined4 *)puVar2[9] = uVar4;
      if ((code *)*DAT_300e3128 != (code *)0x0) {
        (*(code *)*DAT_300e3128)(puVar2[7],0x4000000);
      }
    }
    semGive(DAT_300e30e4);
  } while( true );
}

/* ----------------------------------------------------------------
 * objLibInit @ 0x300E3708  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: objArchLibInit
 * Вызывают: usrInit
 * Константы: 0x300E3708
 * Данные: DAT_300e3fa0
 * ---------------------------------------------------------------- */
void objLibInit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_300e3fa0;
  *DAT_300e3fa0 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  puVar1[3] = param_4;
  objArchLibInit();
  return;
}

/* ----------------------------------------------------------------
 * objGenericVerify @ 0x300E3734  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 2
 * Вызывает: errnoSet, objVerify
 * Вызывают: objClassTypeGet, objContextGet, objContextSet, objNameGet, objNameLenGet, objNamePtrGet, objNamePtrSet, objShow
 * Константы: 0xFFFFFFFF, 0x300E3734
 * Данные: DAT_300e3fa4
 * ---------------------------------------------------------------- */
undefined4 objGenericVerify(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (int)*(char *)(param_1 + 10);
  if ((iVar3 == 0) || (0x15 < iVar3)) {
    errnoSet(DAT_300e3fa4);
    uVar1 = 0xffffffff;
  }
  else if (*(int *)(param_1 + 4) == param_1) {
    iVar2 = *(int *)(param_1 + 0x30);
    if ((*(int *)(iVar2 + 4) == iVar2) && (*(char *)(iVar2 + 10) == 'i')) {
      if (iVar3 == *(int *)(iVar2 + 0x38)) {
        iVar3 = objVerify();
        if (iVar3 == 0) {
          uVar1 = 0;
        }
        else {
          uVar1 = 0xffffffff;
        }
      }
      else {
        errnoSet(DAT_300e3fa4);
        uVar1 = 0xffffffff;
      }
    }
    else {
      errnoSet(DAT_300e3fa4);
      uVar1 = 0xffffffff;
    }
  }
  else {
    errnoSet(DAT_300e3fa4);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * objShow @ 0x300E37D4  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: errnoSet, objGenericVerify
 * Вызывают: objectShow
 * Константы: 0xFFFFFFFF, 0x300E37D4
 * Данные: DAT_300e3fa8
 * ---------------------------------------------------------------- */
undefined4 objShow(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  
  iVar3 = *(int *)(param_1 + 0x30);
  iVar1 = objGenericVerify();
  if (iVar1 == 0) {
    pcVar4 = *(code **)(iVar3 + 0x18);
    if (pcVar4 == (code *)0x0) {
      errnoSet(DAT_300e3fa8);
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = (*pcVar4)(param_1,param_2);
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * objAllocExtra @ 0x300E3830  (примерный размер ~208 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 3
 * Вызывает: __errno, errnoSet, intContext
 * Вызывают: msgQCreate, objAlloc, semRWCreate, taskCreateWithGuard
 * Константы: 0x300E3830
 * Данные: DAT_300e3fa0, DAT_300e3fac, DAT_300e3fb0
 * ---------------------------------------------------------------- */
int objAllocExtra(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  code *pcVar3;
  
  iVar1 = intContext();
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 4) == param_1) && (*(char *)(param_1 + 10) == 'i')) {
      pcVar3 = *(code **)(param_1 + 0x28);
      if (pcVar3 == (code *)0x0) {
        pcVar3 = (code *)*DAT_300e3fa0;
        if (pcVar3 == (code *)0x0) {
          errnoSet(DAT_300e3fb0);
          return 0;
        }
        iVar1 = DAT_300e3fa0[2];
      }
      else {
        iVar1 = *(int *)(param_1 + 0x34);
      }
      iVar1 = (*pcVar3)(iVar1,param_2 + *(int *)(param_1 + 0xc));
      if (iVar1 == 0) {
        return 0;
      }
      if (param_3 == (int *)0x0) {
        return iVar1;
      }
      *param_3 = iVar1 + *(int *)(param_1 + 0xc);
      return iVar1;
    }
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_300e3fac;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * objAlloc @ 0x300E3900  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: objAllocExtra
 * Вызывают: memPartCreate, semBCreate, semCCreate, semMCreate, wdCreate
 * Константы: 0x300E3900
 * ---------------------------------------------------------------- */
void objAlloc(undefined4 param_1)

{
  objAllocExtra(param_1,0,0);
  return;
}

