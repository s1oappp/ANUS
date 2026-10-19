/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : shell — командный интерпретатор VxWorks shell (C-интерпретатор, таблицы команд)
 * Часть  : 2 (функций: 150, адреса 0x3010A138..0x301127B8)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * FUN_3010a138 @ 0x3010A138  (примерный размер ~692 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 10
 * Вызывает: FUN_30106c34, FUN_3010889c, FUN_301088bc, FUN_3010891c, FUN_30108e10, __lsl64, __lsr64, __rem64, __urem64, bzero
 * Константы: 0x3010A138, 0xFFFFFFFF
 * Данные: DAT_3010a54c, DAT_3010a550, DAT_3010a554, DAT_3010a558
 * ---------------------------------------------------------------- */
void FUN_3010a138(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_108;
  undefined4 auStack_104 [9];
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined1 auStack_bc [36];
  uint local_98;
  uint local_94;
  int local_88;
  undefined1 auStack_74 [36];
  uint local_50;
  uint local_4c;
  int local_40;
  
  iVar1 = FUN_30108e10(auStack_74,param_2,param_5);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = FUN_30108e10(auStack_bc,param_4,param_5);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = FUN_3010889c(auStack_74);
  local_108 = FUN_3010889c(auStack_bc);
  iVar2 = FUN_301088bc(auStack_74);
  if ((((iVar2 == 0) || (iVar2 = FUN_301088bc(auStack_bc), iVar2 == 0)) || (iVar1 == 8)) ||
     (local_108 == 8)) {
    FUN_30106c34(DAT_3010a558,param_5,DAT_3010a554,param_3);
    return;
  }
  FUN_3010891c(auStack_74,7);
  FUN_3010891c(auStack_bc,7);
  bzero(auStack_104,0x44);
  local_d0 = 0xffffffff;
  if (param_3 == 0x3e) {
    local_e0 = __lsr64(local_50,local_4c,local_98);
LAB_3010a35c:
    local_d0 = 0;
    if (local_40 != 1) goto LAB_3010a380;
  }
  else {
    if (0x3e < param_3) {
      if (param_3 == 0x5e) {
        local_e0 = CONCAT44(local_4c ^ local_94,local_50 ^ local_98);
      }
      else {
        local_e0 = CONCAT44(local_e0._4_4_,(undefined4)local_e0);
        if (param_3 != 0x7c) goto LAB_3010a380;
        local_e0 = CONCAT44(local_4c | local_94,local_50 | local_98);
      }
      goto LAB_3010a35c;
    }
    if (param_3 != 0x25) {
      if (param_3 == 0x26) {
        local_e0 = CONCAT44(local_4c & local_94,local_50 & local_98);
      }
      else {
        if (param_3 != 0x3c) goto LAB_3010a380;
        local_e0 = __lsl64(local_50,local_4c,local_98);
      }
      goto LAB_3010a35c;
    }
    if (local_94 + local_98 == 0) {
      FUN_30106c34(DAT_3010a550,param_5,DAT_3010a54c);
      return;
    }
    local_d0 = 0;
    if ((local_40 != 1) && (local_88 != 1)) {
      local_e0 = __rem64(local_50,local_4c,local_98,local_94);
      goto LAB_3010a380;
    }
    local_e0 = __urem64(local_50,local_4c,local_98,local_94);
  }
  local_d0 = 1;
LAB_3010a380:
  local_d4 = 7;
  local_d8 = 2;
  if (local_108 <= iVar1) {
    local_108 = iVar1;
  }
  FUN_3010891c(auStack_104,local_108);
  local_c8 = 1;
  iVar1 = 0x11;
  puVar3 = auStack_104;
  do {
    iVar1 = iVar1 + -1;
    *param_1 = *puVar3;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar1 != 0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010a3ec @ 0x3010A3EC  (примерный размер ~168 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_3010891c, FUN_30108e10, FUN_301092d0, _d_feq
 * Константы: 0x3010A3EC
 * ---------------------------------------------------------------- */
void FUN_3010a3ec(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 param_6)

{
  int iVar1;
  undefined1 auStack_68 [36];
  undefined4 local_44;
  undefined4 local_40;
  
  if (param_5 == (undefined4 *)0x0) {
    FUN_301092d0();
    FUN_3010891c(param_1,4);
    param_1[0xd] = 1;
  }
  else {
    iVar1 = FUN_30108e10(auStack_68,param_2,param_6);
    if (iVar1 == 0) {
      FUN_3010891c(auStack_68,6);
      iVar1 = _d_feq(local_44,local_40,0);
      if (iVar1 == 0) {
        param_5 = param_4;
      }
      iVar1 = 0x11;
      do {
        iVar1 = iVar1 + -1;
        *param_1 = *param_5;
        param_1 = param_1 + 1;
        param_5 = param_5 + 1;
      } while (iVar1 != 0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010a494 @ 0x3010A494  (примерный размер ~536 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_3010889c, FUN_3010891c, FUN_30108e10, FUN_30108edc
 * Вызывают: FUN_3010a6ac
 * Константы: 0x3010A494, 0x3010A548
 * Данные: DAT_3010a55c, DAT_3010a560
 * ---------------------------------------------------------------- */
void FUN_3010a494(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_60 [36];
  undefined4 local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  
  iVar1 = FUN_30108edc(param_2,DAT_3010a55c,param_4);
  if ((iVar1 == 0) && (iVar1 = FUN_30108e10(auStack_60,param_3,param_4), iVar1 == 0)) {
    uVar2 = FUN_3010889c(param_2);
    if ((uVar2 == 0) || (local_24 != 0)) {
      uVar2 = FUN_3010889c(auStack_60);
      param_2[0xc] = local_30;
      param_2[0xd] = local_2c;
      param_2[0xe] = local_28;
      param_2[0xf] = local_24;
      param_2[0x10] = local_20;
    }
    FUN_3010891c(auStack_60,uVar2);
    if (uVar2 < 9) {
                    /* WARNING: Could not recover jumptable at 0x3010a548. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(DAT_3010a560 + uVar2 * 4))();
      return;
    }
    *(undefined4 *)param_2[9] = local_3c;
    iVar1 = 0x11;
    do {
      iVar1 = iVar1 + -1;
      *param_1 = *param_2;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (iVar1 != 0);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010a6ac @ 0x3010A6AC  (примерный размер ~344 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3010a494, bzero
 * Вызывают: FUN_3010a804
 * Константы: 0x3010A6AC, 0xFFFFFFFF, 0x3010A710
 * Данные: DAT_3010a718, DAT_3010a71c
 * ---------------------------------------------------------------- */
void FUN_3010a6ac(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 auStack_a4 [52];
  undefined4 local_70;
  undefined4 auStack_5c [17];
  
  iVar1 = 0x11;
  puVar2 = auStack_5c;
  puVar3 = param_2;
  do {
    iVar1 = iVar1 + -1;
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar1 != 0);
  bzero(auStack_a4,0x44);
  local_70 = 0xffffffff;
  if ((uint)(param_3 - DAT_3010a718) < 10) {
                    /* WARNING: Could not recover jumptable at 0x3010a710. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_3010a71c + (param_3 - DAT_3010a718) * 4))();
    return;
  }
  if (*(int *)(param_5 + 0x70) == 0) {
    FUN_3010a494(param_1,param_2,auStack_a4,param_5);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010a804 @ 0x3010A804  (примерный размер ~200 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_30108e10, FUN_30108edc, FUN_3010a6ac, bzero
 * Константы: 0xFFFFFFFF, 0x3010A804
 * Данные: DAT_3010ab48, DAT_3010ab4c
 * ---------------------------------------------------------------- */
void FUN_3010a804(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  undefined1 auStack_a4 [36];
  undefined4 local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined1 auStack_5c [52];
  undefined4 local_28;
  
  bzero(auStack_5c,0x44);
  local_28 = 0xffffffff;
  iVar1 = FUN_30108edc(param_2,DAT_3010ab48,param_5);
  if ((iVar1 == 0) &&
     ((param_3 == 0 || (iVar1 = FUN_30108e10(param_1,param_2,param_5), iVar1 == 0)))) {
    bzero(auStack_a4,0x44);
    local_70 = 0xffffffff;
    local_78 = 2;
    local_74 = 4;
    local_80 = param_4;
    FUN_3010a6ac(auStack_5c,param_2,DAT_3010ab4c,auStack_a4,param_5);
    if (param_3 == 0) {
      FUN_30108e10(param_1,auStack_5c,param_5);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010a8cc @ 0x3010A8CC  (примерный размер ~452 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 7
 * Вызывает: FUN_30106c34, FUN_301088bc, FUN_301088fc, FUN_3010891c, FUN_30108e10, __floatsidf, _d_feq
 * Константы: 0x3010A8CC, 0x80000000
 * Данные: DAT_3010ab50, DAT_3010ab54
 * ---------------------------------------------------------------- */
void FUN_3010a8cc(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  bool bVar4;
  undefined4 auStack_60 [9];
  undefined8 local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar1 = FUN_30108e10(auStack_60,param_3,param_4);
  if (iVar1 != 0) {
    return;
  }
  if (param_2 == 0x2b) {
    local_2c = 0;
  }
  else {
    if ((param_2 == 0x2d) || (param_2 == 0x21)) {
      iVar3 = 7;
      iVar1 = FUN_301088fc(auStack_60);
      if (iVar1 != 0) {
        iVar3 = 6;
      }
      FUN_3010891c(auStack_60,iVar3);
      if (iVar3 == 6) {
        if (param_2 == 0x2d) {
          local_3c._4_4_ = local_3c._4_4_ ^ 0x80000000;
LAB_3010a9ec:
          local_2c = 0;
        }
        else {
          iVar1 = _d_feq((uint)local_3c,local_3c._4_4_,0);
          local_3c = __floatsidf(iVar1 != 0);
        }
      }
      else {
        if (param_2 == 0x2d) {
          bVar4 = (uint)local_3c != 0;
          local_3c._0_4_ = -(uint)local_3c;
          local_3c._4_4_ = -(local_3c._4_4_ + bVar4);
        }
        else {
          local_3c._0_4_ = (uint)(local_3c._4_4_ == 0 && (uint)local_3c == 0);
          local_3c._4_4_ = 0;
        }
        if (param_2 == 0x2d) goto LAB_3010a9ec;
      }
      FUN_3010891c(auStack_60,local_30);
      goto LAB_3010aa64;
    }
    iVar1 = FUN_301088bc(auStack_60);
    if (iVar1 == 0) {
      FUN_30106c34(DAT_3010ab54,param_4,DAT_3010ab50);
      return;
    }
    FUN_3010891c(auStack_60,7);
    local_3c._0_4_ = ~(uint)local_3c;
    local_3c._4_4_ = ~local_3c._4_4_;
    FUN_3010891c(auStack_60,local_30);
    local_2c = 1;
  }
LAB_3010aa64:
  iVar1 = 0x11;
  puVar2 = auStack_60;
  do {
    iVar1 = iVar1 + -1;
    *param_1 = *puVar2;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar1 != 0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010aa90 @ 0x3010AA90  (примерный размер ~96 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_3010921c, bzero
 * Константы: 0x3010AA90, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void FUN_3010aa90(void *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  bzero(param_1,0x44);
  *(undefined4 *)((int)param_1 + 0x34) = 0xffffffff;
  if ((int)param_2[2] < 1) {
    uVar1 = *param_2;
  }
  else {
    uVar1 = 8;
  }
  uVar1 = FUN_3010921c(uVar1);
  *(undefined4 *)((int)param_1 + 0x24) = uVar1;
  *(undefined4 *)((int)param_1 + 0x2c) = 2;
  *(undefined4 *)((int)param_1 + 0x30) = 4;
  *(undefined4 *)((int)param_1 + 0x34) = 1;
  *(undefined4 *)((int)param_1 + 0x3c) = 1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010aaf0 @ 0x3010AAF0  (примерный размер ~276 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_30106c34, FUN_3010889c, FUN_30108e10, shellInternalFuncIntArgAdd
 * Константы: 0x3010AAF0, 0x3010AB44
 * Данные: DAT_3010ab58, DAT_3010ab5c, DAT_3010b1f0, DAT_3010b1f4, DAT_3010b1f8
 * ---------------------------------------------------------------- */
int FUN_3010aaf0(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_58 [36];
  undefined4 local_34;
  
  if (*(int *)(param_2 + 0x30) == 9) {
    FUN_30106c34(DAT_3010b1f0,param_3,DAT_3010ab58);
    iVar2 = -1;
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    iVar2 = FUN_30108e10(auStack_58);
    if (iVar2 == 0) {
      uVar1 = FUN_3010889c(auStack_58);
      if (uVar1 < 9) {
                    /* WARNING: Could not recover jumptable at 0x3010ab44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (**(code **)(DAT_3010ab5c + uVar1 * 4))();
        return iVar2;
      }
      iVar2 = shellInternalFuncIntArgAdd(uVar3,local_34);
      if (iVar2 == -1) {
        FUN_30106c34(DAT_3010b1f8,param_3,DAT_3010b1f4);
      }
    }
    else {
      iVar2 = -1;
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_3010ac04 @ 0x3010AC04  (примерный размер ~204 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_30106c34, FUN_301088bc, FUN_3010891c, bzero
 * Константы: 0x3010AC04, 0xFFFFFFFF
 * Данные: DAT_3010b1f0, DAT_3010b1fc, DAT_3010b200, DAT_3010b204
 * ---------------------------------------------------------------- */
void FUN_3010ac04(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int aiStack_54 [4];
  undefined4 local_44;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  bzero(aiStack_54,0x44);
  local_20 = 0xffffffff;
  if ((*(int *)(param_2 + 0x2c) != 1) && (*(int *)(param_2 + 0x30) != 9)) {
    iVar1 = FUN_301088bc(param_2);
    if (iVar1 == 0) {
      FUN_30106c34(DAT_3010b1f0,param_3,DAT_3010b204);
      return;
    }
    FUN_3010891c(param_2,8);
  }
  aiStack_54[2] = *(int *)(param_2 + 0x24);
  if (DAT_3010b1fc == *(int *)(param_2 + 0x24)) {
    aiStack_54[2] = DAT_3010b200;
  }
  local_44 = 4;
  local_24 = 4;
  local_28 = 2;
  iVar1 = 0x11;
  piVar2 = aiStack_54;
  do {
    iVar1 = iVar1 + -1;
    *param_1 = *piVar2;
    param_1 = param_1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 != 0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010acd0 @ 0x3010ACD0  (примерный размер ~304 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_30106c34, FUN_301088bc, FUN_3010891c, FUN_30108e10, FUN_3010921c, bzero
 * Константы: 0x3010ACD0, 0xFFFFFFFF
 * Данные: DAT_3010b1f0, DAT_3010b208, DAT_3010b20c
 * ---------------------------------------------------------------- */
void FUN_3010acd0(void *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_a4 [36];
  int local_80;
  undefined1 auStack_5c [36];
  int local_38;
  
  iVar1 = FUN_30108e10(auStack_a4,param_2,param_4);
  if ((iVar1 == 0) && (iVar1 = FUN_30108e10(auStack_5c,param_3,param_4), iVar1 == 0)) {
    iVar1 = FUN_301088bc(auStack_a4);
    uVar2 = DAT_3010b208;
    if ((iVar1 == 0) || (iVar1 = FUN_301088bc(auStack_5c), uVar2 = DAT_3010b20c, iVar1 == 0)) {
      FUN_30106c34(DAT_3010b1f0,param_4,uVar2);
    }
    else {
      FUN_3010891c(auStack_5c,4);
      FUN_3010891c(auStack_a4,8);
      if (*(int *)(param_2 + 0x38) < 2) {
        uVar2 = *(undefined4 *)(param_2 + 0x30);
      }
      else {
        uVar2 = 8;
      }
      iVar1 = FUN_3010921c(uVar2);
      bzero(param_1,0x44);
      *(undefined4 *)((int)param_1 + 0x34) = 0xffffffff;
      *(int *)((int)param_1 + 0x24) = local_38 * iVar1 + local_80;
      *(undefined4 *)((int)param_1 + 0x2c) = 1;
      *(undefined4 *)((int)param_1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
      *(undefined4 *)((int)param_1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
      iVar3 = *(int *)(param_2 + 0x38);
      *(int *)((int)param_1 + 0x38) = iVar3;
      iVar1 = *(int *)(param_2 + 0x3c);
      *(int *)((int)param_1 + 0x3c) = iVar1;
      *(undefined4 *)((int)param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
      if ((iVar1 != 0) && (0 < iVar3)) {
        *(int *)((int)param_1 + 0x38) = iVar3 + -1;
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010ae00 @ 0x3010AE00  (примерный размер ~272 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_30106c34, FUN_301088bc, FUN_3010891c, FUN_30108e10, bzero
 * Константы: 0x3010AE00, 0xFFFFFFFF
 * Данные: DAT_3010b1f0, DAT_3010b210, DAT_3010b214
 * ---------------------------------------------------------------- */
void FUN_3010ae00(void *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_a0 [36];
  int local_7c;
  undefined1 auStack_58 [36];
  int local_34;
  
  iVar1 = FUN_30108e10(auStack_a0,param_2,param_4);
  if ((iVar1 == 0) && (iVar1 = FUN_30108e10(auStack_58,param_3,param_4), iVar1 == 0)) {
    iVar1 = FUN_301088bc(auStack_a0);
    uVar3 = DAT_3010b210;
    if ((iVar1 == 0) || (iVar1 = FUN_301088bc(auStack_58), uVar3 = DAT_3010b214, iVar1 == 0)) {
      FUN_30106c34(DAT_3010b1f0,param_4,uVar3);
    }
    else {
      FUN_3010891c(auStack_58,4);
      FUN_3010891c(auStack_a0,8);
      bzero(param_1,0x44);
      *(undefined4 *)((int)param_1 + 0x34) = 0xffffffff;
      *(int *)((int)param_1 + 0x24) = local_7c + local_34;
      *(undefined4 *)((int)param_1 + 0x2c) = 1;
      *(undefined4 *)((int)param_1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
      *(undefined4 *)((int)param_1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
      iVar2 = *(int *)(param_2 + 0x38);
      *(int *)((int)param_1 + 0x38) = iVar2;
      iVar1 = *(int *)(param_2 + 0x3c);
      *(int *)((int)param_1 + 0x3c) = iVar1;
      *(undefined4 *)((int)param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
      if ((iVar1 != 0) && (0 < iVar2)) {
        *(int *)((int)param_1 + 0x38) = iVar2 + -1;
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * shellInterpCparse @ 0x3010AF10  (примерный размер ~3872 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_30106468, __stdout, fflush, shellInterpClex
 * Вызывают: FUN_3010c16c
 * Константы: 0xFFFFFFFE, 0xFFFFFFF8, 0x3010AF10, 0x3010B1E8
 * Данные: DAT_3010b218, DAT_3010b21c, DAT_3010b220, DAT_3010b224, DAT_3010b228, DAT_3010b22c, DAT_3010b230, DAT_3010b234
 * ---------------------------------------------------------------- */
undefined4 shellInterpCparse(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iStack_4;
  
  iVar1 = -DAT_3010b218;
  *(undefined1 **)(&stack0xffffffec + iVar1) = &stack0x00000098 + iVar1;
  *(undefined1 **)(&stack0xfffffff8 + iVar1) = &stack0x000000ec + iVar1;
  *(undefined4 *)(&stack0xfffffff0 + iVar1) = 0x28;
  *(undefined4 *)(&stack0xfffffff4 + iVar1) = 0;
  *(undefined4 *)((int)&iStack_4 + iVar1) = 0;
  *(undefined4 *)(&stack0xffffffe8 + iVar1) = 0xfffffffe;
  *(int *)(&stack0xffffffe4 + iVar1) = *(int *)(&stack0xffffffec + iVar1) + -2;
  puVar7 = *(undefined4 **)(&stack0xfffffff8 + iVar1);
  iVar6 = 0;
  puVar9 = &stack0xffffffdc + iVar1;
LAB_3010af60:
  while( true ) {
    iVar11 = *(int *)(&stack0xffffffe4 + iVar1);
    *(undefined2 **)(&stack0xffffffe4 + iVar1) = (undefined2 *)(iVar11 + 2);
    *(undefined2 *)(iVar11 + 2) = (short)iVar6;
    puVar10 = puVar9;
    if ((*(int *)(&stack0xffffffec + iVar1) + *(int *)(&stack0xfffffff0 + iVar1) * 2) - 2U <=
        *(uint *)(&stack0xffffffe4 + iVar1)) {
      uVar8 = *(undefined4 *)(&stack0xfffffff8 + iVar1);
      *(undefined4 *)(&stack0xfffffff8 + iVar1) = *(undefined4 *)(&stack0xffffffec + iVar1);
      iVar11 = (*(int *)(&stack0xffffffe4 + iVar1) - *(int *)(&stack0xffffffec + iVar1) >> 1) + 1;
      if (199 < *(int *)(&stack0xfffffff0 + iVar1)) {
        puVar7 = (undefined4 *)__stdout();
        fflush((FILE *)*puVar7);
        return 2;
      }
      iVar12 = *(int *)(&stack0xfffffff0 + iVar1);
      *(undefined4 *)(&stack0xfffffff0 + iVar1) = 200;
      if (iVar12 * 2 < 0xc9) {
        *(int *)(&stack0xfffffff0 + iVar1) = iVar12 * 2;
      }
      iVar12 = -(*(int *)(&stack0xfffffff0 + iVar1) * 2 + 0xfU & 0xfffffff8);
      *(undefined1 **)(&stack0xffffffec + iVar1) = puVar9 + iVar12 + 8;
      FUN_30106468(puVar9 + iVar12 + 8,*(undefined4 *)(&stack0xfffffff8 + iVar1),iVar11 * 2);
      iVar2 = -(*(int *)(&stack0xfffffff0 + iVar1) * 0x44 + 0xfU & 0xfffffff8);
      puVar10 = puVar9 + iVar2 + iVar12;
      *(undefined1 **)(&stack0xfffffff8 + iVar1) = puVar9 + iVar2 + iVar12 + 8;
      FUN_30106468(puVar9 + iVar2 + iVar12 + 8,uVar8,iVar11 * 0x44);
      *(int *)(&stack0xffffffe4 + iVar1) = *(int *)(&stack0xffffffec + iVar1) + iVar11 * 2 + -2;
      puVar7 = (undefined4 *)(*(int *)(&stack0xfffffff8 + iVar1) + iVar11 * 0x44 + -0x44);
      if ((*(int *)(&stack0xffffffec + iVar1) + *(int *)(&stack0xfffffff0 + iVar1) * 2) - 2U <=
          *(uint *)(&stack0xffffffe4 + iVar1)) {
        return 1;
      }
    }
    iVar11 = DAT_3010b220;
    iVar12 = (int)*(short *)(DAT_3010b21c + iVar6 * 2);
    puVar9 = puVar10;
    if (iVar12 != DAT_3010b220) break;
LAB_3010b188:
    uVar5 = (uint)*(short *)(DAT_3010b238 + iVar6 * 2);
    if (uVar5 != 0) goto LAB_3010b19c;
LAB_3010bd00:
    if (*(int *)(&stack0xfffffff4 + iVar1) == 0) {
      *(int *)((int)&iStack_4 + iVar1) = *(int *)((int)&iStack_4 + iVar1) + 1;
      puVar3 = (undefined4 *)__stdout();
      fflush((FILE *)*puVar3);
    }
    if (*(int *)(&stack0xfffffff4 + iVar1) == 3) {
      if (*(int *)(&stack0xffffffe8 + iVar1) == 0) {
        return 1;
      }
      *(undefined4 *)(&stack0xffffffe8 + iVar1) = 0xfffffffe;
    }
LAB_3010bd6c:
    iVar6 = (int)*(short *)(DAT_3010cc38 + iVar6 * 2);
    *(undefined4 *)(&stack0xfffffff4 + iVar1) = 3;
    if (((iVar6 == iVar11) || (iVar6 = iVar6 + 1, iVar6 < 0)) ||
       ((DAT_3010cc28 < iVar6 || (*(short *)(DAT_3010cc2c + iVar6 * 2) != 1)))) {
LAB_3010bd48:
      if (*(int *)(&stack0xffffffe4 + iVar1) == *(int *)(&stack0xffffffec + iVar1)) {
        return 1;
      }
      iVar6 = *(int *)(&stack0xffffffe4 + iVar1);
      puVar7 = puVar7 + -0x11;
      *(short **)(&stack0xffffffe4 + iVar1) = (short *)(iVar6 + -2);
      iVar6 = (int)*(short *)(iVar6 + -2);
      goto LAB_3010bd6c;
    }
    iVar12 = (int)*(short *)(DAT_3010cc30 + iVar6 * 2);
    if (iVar12 < 0) {
      if (iVar12 != iVar11) goto LAB_3010bdd0;
      goto LAB_3010bd48;
    }
    if (iVar12 == 0) goto LAB_3010bd48;
    if (iVar12 == 0x95) {
      return 0;
    }
    puVar7 = puVar7 + 0x11;
    iVar11 = 0x11;
    puVar3 = puVar7;
    puVar4 = (undefined4 *)(&stack0x00000054 + iVar1);
    do {
      iVar11 = iVar11 + -1;
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
      iVar6 = iVar12;
    } while (iVar11 != 0);
  }
  if (*(int *)(&stack0xffffffe8 + iVar1) == -2) {
    uVar8 = shellInterpClex(&stack0x00000054 + iVar1,param_1);
    *(undefined4 *)(&stack0xffffffe8 + iVar1) = uVar8;
  }
  if (*(int *)(&stack0xffffffe8 + iVar1) < 1) {
    uVar5 = 0;
    *(undefined4 *)(&stack0xffffffe8 + iVar1) = 0;
  }
  else if (DAT_3010b224 < *(uint *)(&stack0xffffffe8 + iVar1)) {
    uVar5 = 0x4f;
  }
  else {
    uVar5 = (uint)*(byte *)(DAT_3010b228 + *(int *)(&stack0xffffffe8 + iVar1));
  }
  iVar12 = iVar12 + uVar5;
  if (((iVar12 < 0) || (DAT_3010b22c < iVar12)) ||
     ((int)*(short *)(DAT_3010b230 + iVar12 * 2) != uVar5)) goto LAB_3010b188;
  iVar12 = (int)*(short *)(DAT_3010b234 + iVar12 * 2);
  if (-1 < iVar12) {
    if (iVar12 == 0) goto LAB_3010bd00;
    if (iVar12 == 0x95) {
      return 0;
    }
    if (*(int *)(&stack0xffffffe8 + iVar1) != 0) {
      *(undefined4 *)(&stack0xffffffe8 + iVar1) = 0xfffffffe;
    }
    puVar7 = puVar7 + 0x11;
    iVar6 = 0x11;
    puVar3 = puVar7;
    puVar4 = (undefined4 *)(&stack0x00000054 + iVar1);
    do {
      iVar6 = iVar6 + -1;
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar6 != 0);
    iVar6 = iVar12;
    if (*(int *)(&stack0xfffffff4 + iVar1) != 0) {
      *(int *)(&stack0xfffffff4 + iVar1) = *(int *)(&stack0xfffffff4 + iVar1) + -1;
    }
    goto LAB_3010af60;
  }
  if (iVar12 == iVar11) goto LAB_3010bd00;
LAB_3010bdd0:
  uVar5 = -iVar12;
LAB_3010b19c:
  iVar6 = (int)*(short *)(DAT_3010b23c + uVar5 * 2);
  if (0 < iVar6) {
    iVar11 = 0x11;
    puVar3 = (undefined4 *)(&stack0x0000000c + iVar1);
    puVar4 = puVar7 + iVar6 * -0x11 + 0x11;
    do {
      iVar11 = iVar11 + -1;
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar11 != 0);
  }
  if (uVar5 < 0x59) {
                    /* WARNING: Could not recover jumptable at 0x3010b1e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar8 = (**(code **)(DAT_3010b240 + uVar5 * 4))();
    return uVar8;
  }
  puVar7 = puVar7 + iVar6 * -0x11 + 0x11;
  *(int *)(&stack0xffffffe4 + iVar1) = *(int *)(&stack0xffffffe4 + iVar1) + iVar6 * -2;
  iVar6 = 0x11;
  puVar3 = puVar7;
  puVar4 = (undefined4 *)(&stack0x0000000c + iVar1);
  do {
    iVar6 = iVar6 + -1;
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar6 != 0);
  iVar11 = (int)*(short *)(DAT_3010cc20 + uVar5 * 2);
  iVar12 = (int)**(short **)(&stack0xffffffe4 + iVar1);
  iVar6 = *(short *)(DAT_3010cc24 + iVar11 * 2 + -0x6a) + iVar12;
  if ((-1 < iVar6) && (iVar6 <= DAT_3010cc28)) {
    iVar13 = (int)*(short *)(DAT_3010cc2c + iVar6 * 2);
    iVar2 = iVar13;
    if (iVar13 == iVar12) {
      iVar2 = DAT_3010cc30;
    }
    if (iVar13 == iVar12) {
      iVar6 = (int)*(short *)(iVar2 + iVar6 * 2);
      goto LAB_3010af60;
    }
  }
  iVar6 = (int)*(short *)(DAT_3010cc34 + iVar11 * 2 + -0x6a);
  goto LAB_3010af60;
}

/* ----------------------------------------------------------------
 * shellInterpCInit @ 0x3010BE30  (примерный размер ~72 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3010BE30
 * Данные: DAT_3010cca4, DAT_3010cca8, DAT_3010ccac, DAT_3010ccb0, DAT_3010ccb4, DAT_3010ccb8, DAT_3010ccbc, DAT_3010ccc0
 * ---------------------------------------------------------------- */
undefined4 shellInterpCInit(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = DAT_3010cca4;
  *(undefined4 *)(param_1 + 0x10) = DAT_3010cca8;
  *(undefined4 *)(param_1 + 0x18) = DAT_3010ccac;
  *(undefined4 *)(param_1 + 0x1c) = DAT_3010ccb0;
  *(undefined4 *)(param_1 + 0x20) = DAT_3010ccb4;
  *(undefined4 *)(param_1 + 0x14) = DAT_3010ccb8;
  *(undefined4 *)(param_1 + 0x24) = DAT_3010ccbc;
  *(undefined4 *)(param_1 + 8) = DAT_3010ccc0;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3010be78 @ 0x3010BE78  (примерный размер ~72 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: lstInit, shellMemCalloc
 * Вызывают: FUN_3010c468
 * Константы: 0x3010BE78, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_3010be78(int param_1)

{
  int iVar1;
  
  iVar1 = shellMemCalloc(1,0x17c);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(iVar1 + 0x44) = 0;
  lstInit(iVar1 + 0x38);
  *(undefined4 *)(iVar1 + 0x6c) = 0;
  *(int *)(param_1 + 0xc) = iVar1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3010bec0 @ 0x3010BEC0  (примерный размер ~144 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 5
 * Вызывает: semGive, semTake, shellInterpC_delete_buffer, shellMemAllRegFree, shellMemFree
 * Вызывают: FUN_3010bf50
 * Константы: 0x3010BEC0, 0xFFFFFFFF
 * Данные: DAT_3010ccc4, DAT_3010ccc8
 * ---------------------------------------------------------------- */
void FUN_3010bec0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  shellMemAllRegFree(1,1,DAT_3010ccc4,puVar2 + 0xe);
  iVar1 = DAT_3010ccc8;
  if (puVar2[4] != 0) {
    if (*(int *)(DAT_3010ccc8 + 4) != 0) {
      semTake(*(int *)(DAT_3010ccc8 + 4),0xffffffff);
    }
    *(undefined4 *)(iVar1 + 8) = puVar2[4];
    shellInterpC_delete_buffer();
    puVar2[4] = *(undefined4 *)(iVar1 + 8);
    if (*(int *)(iVar1 + 4) != 0) {
      semGive();
    }
  }
  shellMemFree(*puVar2);
  *puVar2 = 0;
  puVar2[0x1b] = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010bf50 @ 0x3010BF50  (примерный размер ~36 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3010bec0, shellMemFree
 * Вызывают: FUN_3010c468
 * Константы: 0x3010BF50
 * ---------------------------------------------------------------- */
void FUN_3010bf50(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  FUN_3010bec0();
  shellMemFree(uVar1);
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010bf74 @ 0x3010BF74  (примерный размер ~336 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: shellPrintErr, strlen
 * Вызывают: FUN_3010c0c4
 * Константы: 0xFFFFFFFF, 0x3010BF74
 * Данные: DAT_3010cccc, DAT_3010ccd0
 * ---------------------------------------------------------------- */
undefined4 FUN_3010bf74(char *param_1,int *param_2,int *param_3)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  
  sVar2 = strlen(param_1);
  if (sVar2 != 0) {
    sVar2 = strlen(param_1);
    pcVar4 = param_1 + sVar2;
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + -1;
      if (pcVar4 <= param_1) break;
    } while (*pcVar4 == ' ');
    *pcVar3 = '\0';
    for (; ((((param_1 < pcVar4 && (cVar1 = *pcVar4, cVar1 != ' ')) && (cVar1 != '<')) &&
            ((cVar1 != '>' && (cVar1 != ')')))) && ((cVar1 != ';' && (cVar1 != '\"'))));
        pcVar4 = pcVar4 + -1) {
    }
    pcVar3 = pcVar4 + 1;
    for (; (param_1 < pcVar4 && (*pcVar4 == ' ')); pcVar4 = pcVar4 + -1) {
    }
    if (*pcVar4 == '>') {
      if ((pcVar4 != param_1) && (pcVar4[-1] == '>')) {
        return 0;
      }
      if (*param_3 != 0) {
        shellPrintErr(0,DAT_3010cccc);
        return 0xffffffff;
      }
      *param_3 = (int)pcVar3;
    }
    else {
      if (*pcVar4 != '<') {
        return 0;
      }
      if ((pcVar4 != param_1) && (pcVar4[-1] == '<')) {
        return 0;
      }
      if (*param_2 != 0) {
        shellPrintErr(0,DAT_3010ccd0);
        return 0xffffffff;
      }
      *param_2 = (int)pcVar3;
    }
    *pcVar4 = '\0';
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3010c0c4 @ 0x3010C0C4  (примерный размер ~136 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3010bf74, strlen
 * Вызывают: FUN_3010c16c
 * Константы: 0x3010C0C4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_3010c0c4(char *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  
  *param_2 = 0;
  *param_3 = 0;
  iVar2 = FUN_3010bf74(param_1);
  if ((iVar2 != 0) || (iVar2 = FUN_3010bf74(param_1,param_2,param_3), iVar2 != 0)) {
    return 0xffffffff;
  }
  sVar3 = strlen(param_1);
  pcVar4 = param_1 + sVar3;
  do {
    pcVar1 = pcVar4;
    pcVar4 = pcVar1 + -1;
    if (pcVar4 < param_1) break;
  } while (*pcVar4 == ' ');
  *pcVar1 = '\0';
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3010c14c @ 0x3010C14C  (примерный размер ~32 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3010c16c
 * Константы: 0x3010C14C
 * ---------------------------------------------------------------- */
void FUN_3010c14c(int param_1)

{
  *(undefined4 *)(param_1 + 0x60) = 1;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined1 *)(param_1 + 0x78) = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010c16c @ 0x3010C16C  (примерный размер ~764 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 18
 * Вызывает: FUN_3010c0c4, FUN_3010c14c, __errno, printErrno, semGive, semTake, shellInOutRedirectClose, shellInOutRedirectOpen, shellInOutRedirectScript, shellInterpC_delete_buffer, shellInterpCparse, shellMemAllRegFree, shellMemFree, shellMemMalloc
 *           ...
 * Вызывают: FUN_3010c468
 * Константы: 0xFFFFFFFF, 0x3010C16C
 * Данные: DAT_3010ccc4, DAT_3010ccc8, DAT_3010ccd4, DAT_3010ccd8, DAT_3010ccdc, DAT_3010cce0, DAT_3010cce4, DAT_3010cce8
 * ---------------------------------------------------------------- */
undefined4 FUN_3010c16c(int param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_18;
  int local_14;
  
  puVar8 = *(undefined4 **)(param_1 + 0xc);
  FUN_3010c14c(puVar8);
  puVar8[0x17] = 1;
  sVar2 = strlen(param_2);
  pcVar3 = (char *)shellMemMalloc(sVar2 + 2);
  *puVar8 = pcVar3;
  if (pcVar3 != (char *)0x0) {
    strcpy(pcVar3,param_2);
    local_18 = 0;
    local_14 = 0;
    iVar4 = FUN_3010c0c4(*puVar8,&local_18,&local_14);
    if (iVar4 == 0) {
      iVar4 = shellInOutRedirectOpen(0,local_18,local_14,0,0,0);
      if (iVar4 != 0) {
        pcVar3 = (char *)*puVar8;
        if ((*pcVar3 == '\0') && (local_18 != 0)) {
          shellMemFree(pcVar3);
          *puVar8 = 0;
          uVar5 = shellInOutRedirectScript(0,iVar4);
          shellInOutRedirectClose(0,iVar4);
          return uVar5;
        }
        puVar8[0x1a] = 0;
        sVar2 = strlen(pcVar3);
        if (pcVar3[sVar2 - 1] != ';') {
          strcat(pcVar3,DAT_3010ccf0);
          puVar8[0x1a] = 1;
        }
        puVar8[0x1b] = iVar4;
        puVar8[4] = 0;
        puVar8[5] = 0;
        puVar8[9] = 1;
        puVar8[10] = 0;
        puVar8[1] = 0;
        puVar8[2] = 0;
        *(undefined1 *)(puVar8 + 0xd) = 0;
        puVar8[8] = 0;
        puVar8[7] = 0;
        puVar8[0xb] = 0;
        puVar8[0xc] = 0;
        puVar8[6] = 0;
        puVar8[3] = 0;
        iVar6 = shellInterpCparse(puVar8);
        iVar1 = DAT_3010ccc8;
        if (puVar8[4] != 0) {
          if (*(int *)(DAT_3010ccc8 + 4) != 0) {
            semTake(*(int *)(DAT_3010ccc8 + 4),0xffffffff);
          }
          *(undefined4 *)(iVar1 + 8) = puVar8[4];
          shellInterpC_delete_buffer();
          puVar8[4] = *(undefined4 *)(iVar1 + 8);
          if (*(int *)(iVar1 + 4) != 0) {
            semGive();
          }
        }
        shellMemFree(*puVar8);
        *puVar8 = 0;
        shellInOutRedirectClose(0,iVar4);
        shellMemAllRegFree(1,1,DAT_3010ccc4,puVar8 + 0xe);
        uVar5 = 0;
        if (iVar6 != 0) {
          uVar5 = DAT_3010ccf4;
        }
        shellMemAllRegFree(4,7,uVar5,puVar8 + 0xe);
        if (iVar6 != 0) {
          shellPrintErr(0,DAT_3010ccf8);
          if (*(char *)(puVar8 + 0x1e) == '\0') {
            shellPrintErr(0,DAT_3010ccfc);
          }
          else {
            shellPrintErr(0,DAT_3010cd00,puVar8 + 0x1e);
          }
          puVar7 = (undefined4 *)__errno();
          *puVar7 = puVar8[0x1d];
          return 0xffffffff;
        }
        return 0;
      }
      shellPrintErr(0,DAT_3010ccd8);
      if (local_18 != 0) {
        uVar5 = DAT_3010ccdc;
        if (local_14 == 0) {
          uVar5 = DAT_3010cce0;
        }
        shellPrintErr(0,DAT_3010cce4,local_18,uVar5);
      }
      if (local_14 != 0) {
        shellPrintErr(0,DAT_3010cce8,local_14);
      }
      shellPrintErr(0,DAT_3010ccec);
      printErrno(0);
    }
    else {
      shellPrintErr(0,DAT_3010ccd4);
    }
    shellMemFree(*puVar8);
    *puVar8 = 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_3010c468 @ 0x3010C468  (примерный размер ~136 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_3010be78, FUN_3010bf50, FUN_3010c16c
 * Константы: 0x3010C468, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_3010c468(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  iVar1 = FUN_3010be78();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar4 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(iVar4 + 0x44) = 1;
  iVar1 = FUN_3010c16c(param_1,param_2,0);
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(iVar4 + 0x4c);
    *param_3 = *(undefined4 *)(iVar4 + 0x48);
    param_3[1] = uVar2;
    uVar2 = *(undefined4 *)(iVar4 + 0x54);
    param_3[2] = *(undefined4 *)(iVar4 + 0x50);
    param_3[3] = uVar2;
    param_3[4] = *(undefined4 *)(iVar4 + 0x58);
  }
  FUN_3010bf50(param_1);
  *(undefined4 *)(param_1 + 0xc) = uVar3;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3010c4f0 @ 0x3010C4F0  (примерный размер ~720 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 19
 * Вызывает: __stdout, calloc, completionSymComplete, completionSymListGet, completionSymShow, fflush, free, lstDelete, lstFirst, lstFree, lstInit, lstNext, shellPrint, shellPromptPrint
 *           ...
 * Вызывают: FUN_3010c7c0
 * Константы: 0xFFFFFFFF, 0x3010C4F0
 * Данные: DAT_3010cd00, DAT_3010cd04, DAT_3010cd08, DAT_3010cd0c
 * ---------------------------------------------------------------- */
undefined4
FUN_3010c4f0(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,int param_5,
            char *param_6,uint param_7,int param_8)

{
  void *__ptr;
  int iVar1;
  void *pvVar2;
  int iVar3;
  char *__s;
  size_t sVar4;
  size_t sVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  byte *__s1;
  undefined4 local_40;
  undefined1 auStack_38 [12];
  undefined4 local_2c;
  
  local_40 = 0xffffffff;
  lstInit(auStack_38);
  local_2c = param_2;
  iVar1 = completionSymListGet(param_1,auStack_38);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  pvVar2 = (void *)lstFirst(auStack_38);
joined_r0x3010c550:
  __ptr = pvVar2;
  if (__ptr != (void *)0x0) {
    __s1 = *(byte **)((int)__ptr + 0xc);
    pvVar2 = (void *)lstNext(__ptr);
    if (((__s1 != (byte *)0x0) && (*(int *)((int)__ptr + 0x14) == 3)) && (*__s1 != 0)) {
      iVar1 = *DAT_3010cd04;
      do {
        uVar8 = (uint)*__s1;
        if (((*(byte *)(iVar1 + uVar8) & 7) == 0) && (uVar8 != 0x5f)) {
          iVar3 = strncmp((char *)__s1,DAT_3010cd08,2);
          if (iVar3 != 0) {
            if (uVar8 == 0x28) {
              *__s1 = 0;
            }
            else {
              lstDelete(auStack_38,__ptr);
              free(__ptr);
            }
            break;
          }
          __s1 = __s1 + 2;
        }
        else {
          __s1 = __s1 + 1;
        }
      } while (*__s1 != 0);
    }
    goto joined_r0x3010c550;
  }
  __s = (char *)calloc(2,param_7 + 1);
  if (__s == (char *)0x0) {
    lstFree(auStack_38);
    return 0xffffffff;
  }
  if ((param_8 != 0) || (iVar1 = completionSymShow(auStack_38), iVar1 == 1)) {
    iVar1 = completionSymComplete(auStack_38,__s,param_7);
  }
  lstFree(auStack_38);
  if ((iVar1 == 1) && (sVar4 = strlen(__s), sVar4 < param_7)) {
    strcat(__s,DAT_3010cd0c);
  }
  if (param_8 == 0) {
    if (iVar1 == 1) goto LAB_3010c6bc;
    if (iVar1 < 2) goto LAB_3010c7a4;
    shellPromptPrint(0);
    shellPrint(0,DAT_3010cd00,param_6);
    puVar6 = (undefined4 *)__stdout();
    fflush((FILE *)*puVar6);
  }
  else {
    if (iVar1 < 1) goto LAB_3010c7a4;
LAB_3010c6bc:
    strcpy(__s + param_7 + 1,param_6);
    strncpy(param_6 + param_4,__s,(param_7 - param_4) - 1);
    sVar4 = strlen(param_6);
    sVar5 = strlen(param_6);
    strncpy(param_6 + sVar5,__s + param_7 + 1 + param_5,(param_7 - sVar4) - 1);
    iVar3 = *DAT_3010cd04;
    while( true ) {
      iVar7 = *param_3;
      uVar8 = (uint)(byte)param_6[iVar7];
      if ((((*(byte *)(iVar3 + uVar8) & 7) == 0) && (uVar8 != 0x5f)) && (uVar8 != 0x3a)) break;
      *param_3 = iVar7 + 1;
    }
    if ((iVar1 == 1) && (uVar8 == 0x20)) {
      *param_3 = iVar7 + 1;
    }
  }
  local_40 = 0;
LAB_3010c7a4:
  free(__s);
  return local_40;
}

/* ----------------------------------------------------------------
 * FUN_3010c7c0 @ 0x3010C7C0  (примерный размер ~668 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_3010c4f0, free, malloc, shellCompletionPathnameGet, strcmp, strlen, strncpy, strpbrk
 * Константы: 0x3010C7C0
 * Данные: DAT_3010cd04, DAT_3010cd10, DAT_3010cd14, DAT_3010cd18, DAT_3010cd1c
 * ---------------------------------------------------------------- */
int FUN_3010c7c0(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,int *param_5
                ,int param_6)

{
  size_t sVar1;
  char *__dest;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  iVar7 = *param_5;
  sVar1 = strlen(param_3);
  iVar6 = iVar7;
  if (0 < iVar7) {
    pbVar5 = (byte *)(param_3 + iVar7);
    do {
      pbVar5 = pbVar5 + -1;
      uVar3 = (uint)*pbVar5;
      if ((((((*(byte *)(*DAT_3010cd04 + uVar3) & 7) == 0) && (uVar3 != 0x2f)) && (uVar3 != 0x5c))
          && ((uVar3 != 0x2e && (uVar3 != 0x5f)))) &&
         ((uVar3 != 0x2b && ((uVar3 != 0x3a && (uVar3 != 0x2d)))))) break;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if (iVar7 < (int)sVar1) {
    iVar4 = sVar1 - iVar7;
    pbVar5 = (byte *)(param_3 + iVar7 + -1);
    do {
      pbVar5 = pbVar5 + 1;
      uVar3 = (uint)*pbVar5;
      if (((((*(byte *)(*DAT_3010cd04 + uVar3) & 7) == 0) && (uVar3 != 0x2f)) && (uVar3 != 0x5c)) &&
         (((uVar3 != 0x2e && (uVar3 != 0x5f)) &&
          ((uVar3 != 0x2b && ((uVar3 != 0x3a && (uVar3 != 0x2d)))))))) break;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar7 = sVar1 - iVar4;
  }
  if (iVar7 == iVar6) {
    iVar4 = -1;
  }
  else {
    iVar4 = strcmp(DAT_3010cd10,param_3 + iVar6);
    bVar8 = iVar4 == 0;
    if (!bVar8) {
      iVar4 = strcmp(DAT_3010cd14,param_3 + iVar6);
      bVar8 = iVar4 == 0;
    }
    if (bVar8) {
      iVar4 = -1;
    }
    else {
      __dest = (char *)malloc((iVar7 - iVar6) + 1);
      if (__dest == (char *)0x0) {
        iVar4 = -1;
      }
      else {
        strncpy(__dest,param_3 + iVar6,iVar7 - iVar6);
        __dest[iVar7 - iVar6] = '\0';
        pcVar2 = strpbrk(__dest,DAT_3010cd18);
        if ((pcVar2 != (char *)0x0) ||
           (iVar4 = FUN_3010c4f0(*DAT_3010cd1c,__dest,param_5,iVar6,iVar7,param_3,param_4,
                                 param_6 == 9), iVar4 != 0)) {
          iVar4 = shellCompletionPathnameGet
                            (__dest,param_5,iVar6,iVar7,param_3,param_4,param_6 == 9);
        }
        free(__dest);
      }
    }
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * FUN_3010ca5c @ 0x3010CA5C  (примерный размер ~76 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3010CA5C
 * Данные: DAT_3010cd20
 * ---------------------------------------------------------------- */
void FUN_3010ca5c(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x30) < param_2) {
    *(int *)(param_1 + 0x24) = (int)*(short *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x30) = 4;
    (**(code **)(DAT_3010cd20 + 0x10))();
  }
  else if (param_2 < *(int *)(param_1 + 0x30)) {
    *(char *)(param_1 + 0x24) = (char)*(undefined2 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x30) = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010caa8 @ 0x3010CAA8  (примерный размер ~116 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3010CAA8
 * Данные: DAT_3010cd20
 * ---------------------------------------------------------------- */
void FUN_3010caa8(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x30) < param_2) {
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x24);
    iVar1 = 5;
  }
  else {
    if (*(int *)(param_1 + 0x30) <= param_2) {
      return;
    }
    *(short *)(param_1 + 0x24) = (short)*(undefined4 *)(param_1 + 0x24);
    iVar1 = 2;
  }
  *(int *)(param_1 + 0x30) = iVar1;
  (**(code **)(DAT_3010cd20 + iVar1 * 4))();
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010cb1c @ 0x3010CB1C  (примерный размер ~96 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3010CB1C
 * Данные: DAT_3010cd20
 * ---------------------------------------------------------------- */
void FUN_3010cb1c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x30) < param_2) {
    iVar2 = *(int *)(param_1 + 0x24);
    iVar1 = 7;
    *(int *)(param_1 + 0x24) = iVar2;
    *(int *)(param_1 + 0x28) = iVar2 >> 0x1f;
  }
  else {
    if (*(int *)(param_1 + 0x30) <= param_2) {
      return;
    }
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x24);
    iVar1 = 4;
  }
  *(int *)(param_1 + 0x30) = iVar1;
  (**(code **)(DAT_3010cd20 + iVar1 * 4))();
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010cb7c @ 0x3010CB7C  (примерный размер ~80 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: shellPrint
 * Константы: 0x3010CB7C
 * Данные: DAT_3010cd20, DAT_3010cd24
 * ---------------------------------------------------------------- */
void FUN_3010cb7c(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x30) < param_2) {
    shellPrint(0,*DAT_3010cd24);
  }
  else if (param_2 < *(int *)(param_1 + 0x30)) {
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x30) = 5;
    (**(code **)(DAT_3010cd20 + 0x14))();
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010cbcc @ 0x3010CBCC  (примерный размер ~112 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: __extendsfdf2, shellPrint
 * Константы: 0x3010CBCC
 * Данные: DAT_3010cd24
 * ---------------------------------------------------------------- */
void FUN_3010cbcc(int param_1,int param_2)

{
  undefined8 uVar1;
  
  if (*(int *)(param_1 + 0x30) < param_2) {
    uVar1 = __extendsfdf2(*(undefined4 *)(param_1 + 0x24));
    *(undefined8 *)(param_1 + 0x24) = uVar1;
    *(undefined4 *)(param_1 + 0x30) = 6;
    return;
  }
  if (*(int *)(param_1 + 0x30) <= param_2) {
    return;
  }
  shellPrint(0,*DAT_3010cd24);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010cc3c @ 0x3010CC3C  (примерный размер ~236 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: __truncdfsf2, shellPrint
 * Константы: 0x3010CC3C
 * Данные: DAT_3010cd24
 * ---------------------------------------------------------------- */
void FUN_3010cc3c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x30) < param_2) {
    shellPrint(0,*DAT_3010cd24);
  }
  else if (param_2 < *(int *)(param_1 + 0x30)) {
    uVar1 = __truncdfsf2(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x24) = uVar1;
    *(undefined4 *)(param_1 + 0x30) = 3;
  }
  return;
}

/* ----------------------------------------------------------------
 * shellInterpLibInit @ 0x3010CD28  (примерный размер ~100 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 4
 * Вызывает: lstInit, semMCreate, shellPrintErr, shellResourceReleaseHookAdd
 * Вызывают: shellLibInit
 * Константы: 0xFFFFFFFF, 0x3010CD28
 * Данные: DAT_3010d728, DAT_3010d72c, DAT_3010d730, DAT_3010d734
 * ---------------------------------------------------------------- */
undefined4 shellInterpLibInit(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_3010d728;
  lstInit(DAT_3010d728);
  iVar1 = semMCreate(0);
  *(int *)(iVar2 + 0xc) = iVar1;
  if (iVar1 == 0) {
    shellPrintErr(0,DAT_3010d72c);
    return 0xffffffff;
  }
  iVar2 = shellResourceReleaseHookAdd(DAT_3010d730);
  if (iVar2 != 0) {
    shellPrintErr(0,DAT_3010d734);
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellInterpNameGet @ 0x3010CD8C  (примерный размер ~104 байт)
 * Модуль: shell | Вызывают: 5 | Вызывает: 2
 * Вызывает: shellFromTaskGet, shellIdVerify
 * Вызывают: FUN_3010fc88, FUN_3010ff7c, shellInterpEvaluate, shellInterpPromptSet, shellPromptFmtSet
 * Константы: 0x3010CD8C
 * ---------------------------------------------------------------- */
undefined4 shellInterpNameGet(int param_1)

{
  int iVar1;
  
  iVar1 = shellIdVerify();
  if (iVar1 != 0) {
    return 0;
  }
  if ((param_1 == 0) && (param_1 = shellFromTaskGet(0), param_1 == 0)) {
    return 0;
  }
  if ((*(int *)(param_1 + 0xc) != 0) && (iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 8), iVar1 != 0))
  {
    return *(undefined4 *)(iVar1 + 8);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellInterpByNameFind @ 0x3010CDF4  (примерный размер ~88 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 5
 * Вызывает: lstFirst, lstNext, semGive, semTake, strcmp
 * Вызывают: FUN_3010ce4c
 * Константы: 0x3010CDF4, 0xFFFFFFFF
 * Данные: DAT_3010d728
 * ---------------------------------------------------------------- */
int shellInterpByNameFind(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_3010d728;
  semTake(*(undefined4 *)(DAT_3010d728 + 0xc),0xffffffff);
  iVar2 = lstFirst(iVar1);
  while ((iVar2 != 0 && (iVar3 = strcmp(*(char **)(iVar2 + 8),param_1), iVar3 != 0))) {
    iVar2 = lstNext(iVar2);
  }
  semGive(*(undefined4 *)(iVar1 + 0xc));
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_3010ce4c @ 0x3010CE4C  (примерный размер ~76 байт)
 * Модуль: shell | Вызывают: 4 | Вызывает: 1
 * Вызывает: shellInterpByNameFind
 * Вызывают: shellInterpCtxCreate, shellInterpPromptDftSet, shellInterpSet, shellPromptFmtDftSet
 * Константы: 0x3010CE4C
 * Данные: DAT_3010d738
 * ---------------------------------------------------------------- */
int FUN_3010ce4c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *DAT_3010d738;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else if (param_1 == 0) {
    if (param_2 != 0) {
      iVar1 = DAT_3010d738[1];
    }
  }
  else {
    iVar1 = shellInterpByNameFind();
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellInterpSet @ 0x3010CE98  (примерный размер ~52 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_3010ce4c
 * Вызывают: FUN_3010ff7c, shellInterpEvaluate
 * Константы: 0x3010CE98, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInterpSet(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_3010ce4c(param_2,0);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 0x10) = iVar1;
  return 0;
}

/* ----------------------------------------------------------------
 * shellInterpCtxCreate @ 0x3010CECC  (примерный размер ~404 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_3010ce4c, __errno, ledHistoryCreate, shellLineLenGet, shellMemCalloc, shellMemFree, shellMemStrdup, shellPrint
 * Вызывают: shellInterpSwitch
 * Константы: 0x3010CECC
 * Данные: DAT_3010d73c, DAT_3010d740, DAT_3010d744, DAT_3010d748
 * ---------------------------------------------------------------- */
int shellInterpCtxCreate(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar1 = shellMemCalloc(1,0x1c);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_3010d73c;
    iVar1 = 0;
  }
  else {
    iVar3 = FUN_3010ce4c(param_1,param_2);
    *(int *)(iVar1 + 8) = iVar3;
    if (iVar3 == 0) {
      shellMemFree(iVar1);
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_3010d740;
      iVar1 = 0;
    }
    else {
      if (*(int *)(iVar3 + 0x18) == 0) {
        shellPrint(0,DAT_3010d744,*(undefined4 *)(iVar3 + 8));
      }
      iVar3 = (**(code **)(*(int *)(iVar1 + 8) + 0xc))(iVar1);
      if (iVar3 == 0) {
        if (param_2 == 0) {
          iVar5 = *(int *)(*(int *)(iVar1 + 8) + 0x28);
          iVar3 = *(int *)(*(int *)(iVar1 + 8) + 0x24);
          if (iVar5 != 0) {
            iVar3 = iVar5;
          }
          iVar3 = shellMemStrdup(iVar3);
          *(int *)(iVar1 + 0x10) = iVar3;
          if (iVar3 == 0) {
            (**(code **)(*(int *)(iVar1 + 8) + 0x14))(iVar1);
            shellMemFree(iVar1);
            puVar2 = (undefined4 *)__errno();
            *puVar2 = DAT_3010d73c;
            iVar1 = 0;
          }
          else {
            uVar4 = shellLineLenGet();
            iVar3 = ledHistoryCreate(0x14,uVar4);
            *(int *)(iVar1 + 0x14) = iVar3;
            if (iVar3 == 0) {
              (**(code **)(*(int *)(iVar1 + 8) + 0x14))(iVar1);
              shellMemFree(*(undefined4 *)(iVar1 + 0x10));
              shellMemFree(iVar1);
              puVar2 = (undefined4 *)__errno();
              *puVar2 = DAT_3010d73c;
              iVar1 = 0;
            }
          }
        }
        else {
          *(undefined4 *)(iVar1 + 0x10) = 0;
          *(undefined4 *)(iVar1 + 0x14) = 0;
        }
      }
      else {
        shellMemFree(iVar1);
        puVar2 = (undefined4 *)__errno();
        *puVar2 = DAT_3010d748;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellInterpSwitch @ 0x3010D060  (примерный размер ~204 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 5
 * Вызывает: ledHistorySet, lstAdd, lstFirst, lstNext, shellInterpCtxCreate
 * Вызывают: FUN_3010ff7c, shellInterpEvaluate
 * Константы: 0x3010D060, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInterpSwitch(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    return 0;
  }
  if ((*(int *)(param_1 + 0xc) != 0) &&
     (*(int *)(*(int *)(param_1 + 0xc) + 8) == *(int *)(param_1 + 0x10))) {
    return 0;
  }
  iVar1 = lstFirst(param_1 + 0x28);
  if (iVar1 != 0) {
    do {
      if (*(int *)(iVar1 + 8) == *(int *)(param_1 + 0x10)) break;
      iVar1 = lstNext(iVar1);
    } while (iVar1 != 0);
    if (iVar1 != 0) goto LAB_3010d104;
  }
  iVar1 = shellInterpCtxCreate(*(undefined4 *)(*(int *)(param_1 + 0x10) + 8),0);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    return 0xffffffff;
  }
  lstAdd(param_1 + 0x28,iVar1);
LAB_3010d104:
  *(int *)(param_1 + 0xc) = iVar1;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (iVar1 != 0) {
    ledHistorySet(*(undefined4 *)(param_1 + 0x420),*(undefined4 *)(iVar1 + 0x14));
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellInterpEvaluate @ 0x3010D12C  (примерный размер ~404 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 11
 * Вызывает: __errno, shellConfigValueSet, shellConfigValueUnset, shellFromTaskGet, shellInterpNameGet, shellInterpSet, shellInterpSwitch, shellMemFree, shellMemStrdup, shellPrintErr, strcmp
 * Вызывают: shellInternalArgumentEval
 * Константы: 0xFFFFFFFF, 0x3010D12C
 * Данные: DAT_3010d73c, DAT_3010d740, DAT_3010d74c, DAT_3010d750, DAT_3010d754, DAT_3010d758, DAT_3010d75c, DAT_3010d760
 * ---------------------------------------------------------------- */
undefined4 shellInterpEvaluate(undefined4 param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  char *__s1;
  code *pcVar6;
  
  iVar1 = shellFromTaskGet(0);
  if (iVar1 == 0) {
    shellPrintErr(0,DAT_3010d74c);
    uVar2 = 0xffffffff;
  }
  else {
    iVar3 = shellInterpNameGet(iVar1);
    if ((iVar3 == 0) || (iVar3 = shellMemStrdup(iVar3), iVar3 != 0)) {
      iVar5 = shellInterpSet(iVar1,param_2);
      if (iVar5 == 0) {
        shellInterpSwitch(iVar1);
        __s1 = (char *)shellInterpNameGet(iVar1);
        iVar5 = strcmp(__s1,param_2);
        if (iVar5 == 0) {
          shellConfigValueSet(0,DAT_3010d75c,param_2);
          pcVar6 = *(code **)(*(int *)(*(int *)(iVar1 + 0xc) + 8) + 0x1c);
          if (pcVar6 == (code *)0x0) {
            shellPrintErr(0,DAT_3010d760,param_2);
            puVar4 = (undefined4 *)__errno();
            uVar2 = 0xffffffff;
            *puVar4 = DAT_3010d740;
          }
          else {
            uVar2 = (*pcVar6)(*(int *)(iVar1 + 0xc),param_1,param_3);
          }
          shellConfigValueUnset(0,DAT_3010d75c);
          shellInterpSet(iVar1,iVar3);
          shellInterpSwitch(iVar1);
          shellMemFree(iVar3);
        }
        else {
          shellMemFree(iVar3);
          uVar2 = 0xffffffff;
        }
      }
      else {
        shellMemFree(iVar3);
        if (param_2 == (char *)0x0) {
          shellPrintErr(0,DAT_3010d758);
        }
        else {
          shellPrintErr(0,DAT_3010d754,param_2);
        }
        uVar2 = 0xffffffff;
      }
    }
    else {
      shellPrintErr(0,DAT_3010d750);
      puVar4 = (undefined4 *)__errno();
      *puVar4 = DAT_3010d73c;
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellInterpRegister @ 0x3010D2C0  (примерный размер ~296 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 10
 * Вызывает: __errno, lstAdd, lstFirst, lstNext, semGive, semTake, shellMemCalloc, shellMemFree, shellPrint, strcmp
 * Вызывают: usrShellInit
 * Константы: 0xFFFFFFFF, 0x3010D2C0
 * Данные: DAT_3010d728, DAT_3010d738, DAT_3010d73c, DAT_3010d744, DAT_3010d764
 * ---------------------------------------------------------------- */
undefined4 shellInterpRegister(code *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = shellMemCalloc(1,0x2c);
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    iVar4 = (*param_1)(iVar2);
    if (iVar4 == 0) {
      if (*(int *)(iVar2 + 0x18) == 0) {
        shellPrint(0,DAT_3010d744,*(undefined4 *)(iVar2 + 8));
      }
      iVar4 = DAT_3010d728;
      semTake(*(undefined4 *)(DAT_3010d728 + 0xc),0xffffffff);
      for (iVar6 = lstFirst(iVar4); piVar1 = DAT_3010d738, iVar6 != 0; iVar6 = lstNext(iVar6)) {
        iVar7 = strcmp(*(char **)(iVar6 + 8),*(char **)(iVar2 + 8));
        if (iVar7 == 0) {
          shellMemFree(iVar2);
          puVar5 = (undefined4 *)__errno();
          *puVar5 = DAT_3010d764;
          semGive(*(undefined4 *)(iVar4 + 0xc));
          return 0xffffffff;
        }
      }
      if (*DAT_3010d738 == 0) {
        *DAT_3010d738 = iVar2;
      }
      if ((piVar1[1] == 0) && (*(int *)(iVar2 + 0x1c) != 0)) {
        piVar1[1] = iVar2;
      }
      lstAdd(iVar4,iVar2);
      semGive(*(undefined4 *)(iVar4 + 0xc));
      uVar3 = 0;
    }
    else {
      shellMemFree(iVar2);
      puVar5 = (undefined4 *)__errno();
      *puVar5 = DAT_3010d73c;
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * shellInterpCtxGet @ 0x3010D3E8  (примерный размер ~72 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: shellFromTaskGet, shellIdVerify
 * Константы: 0x3010D3E8
 * ---------------------------------------------------------------- */
undefined4 shellInterpCtxGet(int param_1)

{
  int iVar1;
  
  iVar1 = shellIdVerify();
  if (iVar1 != 0) {
    return 0;
  }
  if ((param_1 == 0) && (param_1 = shellFromTaskGet(0), param_1 == 0)) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0xc);
}

/* ----------------------------------------------------------------
 * shellInterpDefaultNameGet @ 0x3010D430  (примерный размер ~32 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_3010fc88, FUN_3010ff7c
 * Константы: 0x3010D430
 * Данные: DAT_3010d738
 * ---------------------------------------------------------------- */
undefined4 shellInterpDefaultNameGet(void)

{
  if (*DAT_3010d738 == 0) {
    return 0;
  }
  return *(undefined4 *)(*DAT_3010d738 + 8);
}

/* ----------------------------------------------------------------
 * shellInterpPromptGet @ 0x3010D450  (примерный размер ~68 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 0
 * Вызывают: shellPromptGet, shellPromptPrint
 * Константы: 0x3010D450
 * Данные: DAT_3010d768
 * ---------------------------------------------------------------- */
int shellInterpPromptGet(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    return *(int *)(param_1 + 0x10);
  }
  iVar2 = *(int *)(param_1 + 8);
  iVar1 = *(int *)(iVar2 + 0x28);
  if ((iVar1 == 0) && (*(int *)(iVar2 + 0x24) == 0)) {
    return DAT_3010d768;
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar2 + 0x24);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellInterpPromptSet @ 0x3010D494  (примерный размер ~308 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 9
 * Вызывает: __errno, lstFirst, lstNext, shellFromTaskGet, shellIdVerify, shellInterpNameGet, shellMemFree, shellMemStrdup, strcmp
 * Вызывают: BSP_PromptSet
 * Константы: 0xFFFFFFFF, 0x3010D494
 * Данные: DAT_3010d740, DAT_3010d76c
 * ---------------------------------------------------------------- */
undefined4 shellInterpPromptSet(int param_1,char *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = shellIdVerify();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_3010d76c;
    return 0xffffffff;
  }
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  if ((param_2 == (char *)0x0) &&
     (param_2 = (char *)shellInterpNameGet(param_1), param_2 == (char *)0x0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_3010d740;
    return 0xffffffff;
  }
  iVar1 = lstFirst(param_1 + 0x28);
  if (iVar1 != 0) {
    do {
      iVar3 = strcmp(*(char **)(*(int *)(iVar1 + 8) + 8),param_2);
      if (iVar3 == 0) break;
      iVar1 = lstNext(iVar1);
    } while (iVar1 != 0);
    if (iVar1 != 0) {
      if (param_3 == 0) {
        param_3 = *(int *)(*(int *)(iVar1 + 8) + 0x28);
        if (param_3 == 0) {
          param_3 = *(int *)(*(int *)(iVar1 + 8) + 0x24);
        }
        if (param_3 == 0) {
          puVar2 = (undefined4 *)__errno();
          *puVar2 = DAT_3010d740;
          return 0xffffffff;
        }
      }
      iVar3 = shellMemStrdup(param_3);
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      shellMemFree(*(undefined4 *)(iVar1 + 0x10));
      *(int *)(iVar1 + 0x10) = iVar3;
      return 0;
    }
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = DAT_3010d740;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInterpPromptDftSet @ 0x3010D5C8  (примерный размер ~104 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_3010ce4c, __errno, shellMemFree, shellMemStrdup
 * Константы: 0xFFFFFFFF, 0x3010D5C8
 * Данные: DAT_3010d740
 * ---------------------------------------------------------------- */
undefined4 shellInterpPromptDftSet(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = FUN_3010ce4c(param_1,0);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_3010d740;
    return 0xffffffff;
  }
  if (param_2 == 0) {
    param_2 = *(int *)(iVar1 + 0x24);
  }
  iVar3 = shellMemStrdup(param_2);
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  shellMemFree(*(undefined4 *)(iVar1 + 0x28));
  *(int *)(iVar1 + 0x28) = iVar3;
  return 0;
}

/* ----------------------------------------------------------------
 * shellInterpDelete @ 0x3010D630  (примерный размер ~136 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 5
 * Вызывает: ledHistoryFree, lstFirst, lstFree2, lstNext, shellMemFree
 * Вызывают: shellContextFinalize
 * Константы: 0x3010D630
 * Данные: DAT_3010d770
 * ---------------------------------------------------------------- */
void shellInterpDelete(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  for (iVar1 = lstFirst(param_1 + 0x28); iVar1 != 0; iVar1 = lstNext(iVar1)) {
    if (*(int *)(iVar1 + 0x14) != 0) {
      ledHistoryFree();
    }
    *(undefined4 *)(iVar1 + 0x14) = 0;
    pcVar2 = *(code **)(*(int *)(iVar1 + 8) + 0x14);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(iVar1);
    }
    shellMemFree(*(undefined4 *)(iVar1 + 0x10));
    *(undefined4 *)(iVar1 + 0x10) = 0;
  }
  lstFree2(param_1 + 0x28,DAT_3010d770);
  return;
}

/* ----------------------------------------------------------------
 * shellInterpRestart @ 0x3010D6B8  (примерный размер ~188 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: lstFirst, lstNext
 * Вызывают: shellTask
 * Константы: 0x3010D6B8
 * ---------------------------------------------------------------- */
void shellInterpRestart(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  for (iVar1 = lstFirst(param_1 + 0x28); iVar1 != 0; iVar1 = lstNext(iVar1)) {
    pcVar2 = *(code **)(*(int *)(iVar1 + 8) + 0x10);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(iVar1);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * shellResourceReleaseHookAdd @ 0x3010D774  (примерный размер ~84 байт)
 * Модуль: shell | Вызывают: 5 | Вызывает: 2
 * Вызывает: calloc, hookAddToTail
 * Вызывают: FUN_30111c28, ledLibInit, shellConfigLibInit, shellInterpLibInit, shellLibInit
 * Константы: 0x3010D774, 0xFFFFFFFF
 * Данные: DAT_3010e6e0
 * ---------------------------------------------------------------- */
undefined4
shellResourceReleaseHookAdd
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = DAT_3010e6e0;
  iVar4 = DAT_3010e6e0;
  if (*(int *)(DAT_3010e6e0 + 4) == 0) {
    pvVar2 = calloc(*(size_t *)(DAT_3010e6e0 + 0x10),4);
    *(void **)(iVar1 + 4) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      return 0xffffffff;
    }
  }
  uVar3 = hookAddToTail(param_1,*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 0x10),param_4,
                        iVar4);
  return uVar3;
}

/* ----------------------------------------------------------------
 * shellLibInit @ 0x3010D7C8  (примерный размер ~392 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 15
 * Вызывает: __errno, ledLibInit, lstInit, printErr, semMCreate, shellConfigLibInit, shellInterpLibInit, shellMemLibInit, shellPromptLibInit, shellResourceReleaseHookAdd, taskCreateHookAdd, taskCreateHookDelete, taskDeleteHookAdd, taskDeleteHookDelete
 *           ...
 * Вызывают: usrShellInit
 * Константы: 0xFFFFFFFF, 0x3010D7C8
 * Данные: DAT_3010e6e0, DAT_3010e6e4, DAT_3010e6e8, DAT_3010e7d4, DAT_3010e7d8, DAT_3010e7dc, DAT_3010e7e0, DAT_3010e7e4
 * ---------------------------------------------------------------- */
undefined4 shellLibInit(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar1 = shellMemLibInit();
  if ((((iVar1 == 0) && (iVar1 = shellConfigLibInit(), iVar1 == 0)) &&
      (iVar1 = ledLibInit(), iVar1 == 0)) &&
     ((iVar1 = shellPromptLibInit(), iVar1 == 0 &&
      (iVar2 = shellInterpLibInit(), iVar1 = DAT_3010e6e8, iVar2 == 0)))) {
    lstInit(DAT_3010e6e8);
    iVar2 = semMCreate(0);
    *(int *)(iVar1 + 0xc) = iVar2;
    iVar1 = DAT_3010e7d8;
    if (iVar2 == 0) {
      printErr(DAT_3010e7d4);
      uVar3 = 0xffffffff;
    }
    else {
      lstInit(DAT_3010e7d8);
      iVar2 = semMCreate(1);
      *(int *)(iVar1 + 0xc) = iVar2;
      uVar3 = DAT_3010e7e0;
      if (iVar2 == 0) {
        printErr(DAT_3010e7dc);
        uVar3 = 0xffffffff;
      }
      else {
        iVar1 = taskCreateHookAdd(DAT_3010e7e0);
        if ((iVar1 == 0) && (iVar1 = taskDeleteHookAdd(DAT_3010e7e4), iVar1 == 0)) {
          iVar1 = shellResourceReleaseHookAdd(DAT_3010e7f0);
          if (iVar1 == 0) {
            if (((*DAT_3010e6e0 == 0) && ((code *)*DAT_3010e7f8 != (code *)0x0)) &&
               (*DAT_3010e7fc == 0)) {
              (*(code *)*DAT_3010e7f8)(DAT_3010e800,DAT_3010e804);
              *DAT_3010e7fc = 1;
            }
            tyAbortFuncSet(DAT_3010e808);
            uVar3 = 0;
          }
          else {
            printErr(DAT_3010e7f4);
            uVar3 = 0xffffffff;
          }
        }
        else {
          printErr(DAT_3010e7e8);
          taskCreateHookDelete(uVar3);
          taskDeleteHookDelete(DAT_3010e7e4);
          puVar4 = (undefined4 *)__errno();
          *puVar4 = DAT_3010e7ec;
          uVar3 = 0xffffffff;
        }
      }
    }
  }
  else {
    printErr(DAT_3010e6e4);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * shellFirst @ 0x3010D950  (примерный размер ~8 байт)
 * Модуль: shell | Вызывают: 12 | Вызывает: 1
 * Вызывает: lstFirst
 * Вызывают: BSP_PromptSet, FUN_301150d4, FUN_30115590, shellDataFirst, shellInOutBlockingOnDataClose, shellInOutInputUniqueCheck, shellMemStringFree, shellMemStringShow, shellPrint, shellPrintErr
 *           ...
 * Константы: 0x3010D950
 * Данные: DAT_3010e6e8
 * ---------------------------------------------------------------- */
void shellFirst(void)

{
  lstFirst(DAT_3010e6e8);
  return;
}

/* ----------------------------------------------------------------
 * shellTaskDefaultOptionsGet @ 0x3010D958  (примерный размер ~224 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 1
 * Вызывает: coprocsDiscover
 * Вызывают: FUN_30110d64, shellBackgroundInit, shellGenericInit
 * Константы: 0x00FFFFFF, 0x3010D958
 * Данные: DAT_3010e6e0, DAT_3010e904, DAT_3010e908
 * ---------------------------------------------------------------- */
undefined4 shellTaskDefaultOptionsGet(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint local_34;
  uint local_30 [8];
  
  uVar1 = DAT_3010e6e0;
  local_34 = DAT_3010e6e0;
  if (*DAT_3010e904 == 0) {
    *(uint *)(DAT_3010e6e0 + 0x20) = *(uint *)(DAT_3010e6e0 + 0x20) & 0xffffff;
    iVar3 = 8;
    *DAT_3010e908 = *DAT_3010e908 & 0xffffff;
    puVar5 = &local_34;
    do {
      puVar5 = puVar5 + 1;
      *puVar5 = 0;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    coprocsDiscover(local_30);
    puVar5 = DAT_3010e908;
    puVar4 = &local_34;
    iVar3 = 8;
    do {
      puVar4 = puVar4 + 1;
      if (*puVar4 == 0) break;
      uVar2 = *puVar4;
      iVar3 = iVar3 + -1;
      *puVar5 = *puVar5 | uVar2;
      *(uint *)(local_34 + 0x20) = *(uint *)(local_34 + 0x20) | uVar2;
    } while (iVar3 != 0);
    *DAT_3010e904 = 1;
  }
  return *(undefined4 *)(uVar1 + 0x20);
}

/* ----------------------------------------------------------------
 * shellTaskDefaultPriorityGet @ 0x3010DA38  (примерный размер ~12 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3010DA38
 * Данные: DAT_3010e90c
 * ---------------------------------------------------------------- */
undefined4 shellTaskDefaultPriorityGet(void)

{
  return *DAT_3010e90c;
}

/* ----------------------------------------------------------------
 * FUN_3010da44 @ 0x3010DA44  (примерный размер ~64 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 3
 * Вызывает: lstDelete, lstLast, shellMemFree
 * Вызывают: shellContextFinalize, shellExec, shellTask
 * Константы: 0x3010DA44, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_3010da44(int param_1)

{
  int iVar1;
  
  iVar1 = lstLast(param_1 + 0x40);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  lstDelete(param_1 + 0x40,iVar1);
  shellMemFree(iVar1);
  return 0;
}

/* ----------------------------------------------------------------
 * shellContextListLock @ 0x3010DA84  (примерный размер ~36 байт)
 * Модуль: shell | Вызывают: 7 | Вызывает: 1
 * Вызывает: semTake
 * Вызывают: shellBackgroundInit, shellCompatibleSet, shellContextFinalize, shellContextInit, shellGenericInit, shellInOutInputUniqueCheck, shellRestart
 * Константы: 0xFFFFFFFF, 0x3010DA84
 * Данные: DAT_3010e6e8
 * ---------------------------------------------------------------- */
undefined4 shellContextListLock(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = semTake(*(undefined4 *)(DAT_3010e6e8 + 0xc),0xffffffff);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellContextListUnlock @ 0x3010DAA8  (примерный размер ~32 байт)
 * Модуль: shell | Вызывают: 7 | Вызывает: 1
 * Вызывает: semGive
 * Вызывают: shellBackgroundInit, shellCompatibleSet, shellContextFinalize, shellContextInit, shellGenericInit, shellInOutInputUniqueCheck, shellRestart
 * Константы: 0x3010DAA8, 0xFFFFFFFF
 * Данные: DAT_3010e6e8
 * ---------------------------------------------------------------- */
undefined4 shellContextListUnlock(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = semGive(*(undefined4 *)(DAT_3010e6e8 + 0xc));
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3010dac8 @ 0x3010DAC8  (примерный размер ~48 байт)
 * Модуль: shell | Вызывают: 4 | Вызывает: 4
 * Вызывает: shellInOutBgndClose, shellInOutBlockingClose, shellInOutInputHookUnset, shellInOutRedirectClose
 * Вызывают: FUN_3010ef1c, shellContextFinalize, shellRestart, shellTask
 * Константы: 0xFFFFFFFF, 0x3010DAC8
 * ---------------------------------------------------------------- */
void FUN_3010dac8(undefined4 param_1)

{
  shellInOutInputHookUnset();
  shellInOutBgndClose(param_1);
  shellInOutRedirectClose(param_1,0xffffffff);
  shellInOutBlockingClose(param_1,0xffffffff);
  return;
}

/* ----------------------------------------------------------------
 * shellContextFinalize @ 0x3010DAF8  (примерный размер ~372 байт)
 * Модуль: shell | Вызывают: 4 | Вызывает: 18
 * Вызывает: FUN_3010da44, FUN_3010dac8, errnoGet, errnoSet, ledClose, lstDelete, lstFind, lstFirst, lstNext, semDelete, semGive, semTake, shellContextListLock, shellContextListUnlock
 *           ...
 * Вызывают: FUN_30111020, shellBackgroundInit, shellGenericInit, shellRestart
 * Константы: 0x3010DAF8, 0xFFFFFFFF
 * Данные: DAT_3010e6e8, DAT_3010e7d8, DAT_3010eacc
 * ---------------------------------------------------------------- */
void shellContextFinalize(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = errnoGet();
  FUN_3010dac8(param_1);
  shellInterpDelete(param_1);
  shellDataAllRemove(param_1,1);
  if (((*(int *)(param_1 + 0x414) != 0) && ((code *)*DAT_3010eacc != (code *)0x0)) &&
     (*(int *)(param_1 + 300) != 0)) {
    (*(code *)*DAT_3010eacc)(param_1 + 100,param_1 + 200);
    *(undefined4 *)(param_1 + 300) = 0;
  }
  while (iVar3 = FUN_3010da44(param_1), iVar3 == 0) {
    taskDelay(1);
  }
  shellMemFree(*(undefined4 *)(param_1 + 0x50));
  shellMemFree(*(undefined4 *)(param_1 + 0x140));
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  shellMemFree(*(undefined4 *)(param_1 + 8));
  *(undefined4 *)(param_1 + 8) = 0;
  if (*(int *)(param_1 + 0x420) != 0) {
    ledClose(*(int *)(param_1 + 0x420));
  }
  *(undefined4 *)(param_1 + 0x420) = 0;
  uVar1 = DAT_3010e6e8;
  iVar3 = lstFind(DAT_3010e6e8,param_1);
  if (iVar3 != -1) {
    shellContextListLock();
    lstDelete(uVar1,param_1);
    shellContextListUnlock();
  }
  iVar3 = DAT_3010e7d8;
  semTake(*(undefined4 *)(DAT_3010e7d8 + 0xc),0xffffffff);
  iVar4 = lstFirst(iVar3);
  do {
    if (iVar4 == 0) {
LAB_3010dc44:
      semGive(*(undefined4 *)(iVar3 + 0xc));
      semDelete(*(undefined4 *)(param_1 + 0x410));
      shellMemFree(param_1);
      errnoSet(uVar2);
      return;
    }
    if (*(int *)(iVar4 + 0xc) == param_1) {
      *(undefined4 *)(iVar4 + 0xc) = 0;
      goto LAB_3010dc44;
    }
    iVar4 = lstNext(iVar4);
  } while( true );
}

/* ----------------------------------------------------------------
 * shellTaskDefaultStackSizeGet @ 0x3010DC6C  (примерный размер ~12 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3010DC6C
 * Данные: DAT_3010ec04
 * ---------------------------------------------------------------- */
undefined4 shellTaskDefaultStackSizeGet(void)

{
  return *DAT_3010ec04;
}

/* ----------------------------------------------------------------
 * shellTaskDefaultBaseNameGet @ 0x3010DC78  (примерный размер ~12 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3010DC78
 * Данные: DAT_3010ec08
 * ---------------------------------------------------------------- */
undefined4 shellTaskDefaultBaseNameGet(void)

{
  return *DAT_3010ec08;
}

/* ----------------------------------------------------------------
 * shellContextInit @ 0x3010DC84  (примерный размер ~668 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 16
 * Вызывает: __errno, errnoGet, errnoSet, lstCount, lstInit, printErr, semMCreate, shellContextListLock, shellContextListUnlock, shellMemCalloc, shellMemFree, shellMemStrdup, shellPrintErr, sprintf
 *           ...
 * Вызывают: shellBackgroundInit, shellGenericInit
 * Константы: 0x3010DC84, 0xFFFFFFFF
 * Данные: DAT_3010e6e0, DAT_3010e6e8, DAT_3010e7fc, DAT_3010e800, DAT_3010e804, DAT_3010ec04, DAT_3010ec08, DAT_3010ec0c
 * ---------------------------------------------------------------- */
int shellContextInit(int param_1,int param_2,char *param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char acStack_11c [256];
  
  uVar1 = errnoGet();
  if ((param_3 == (undefined1 *)0x0) || (iVar2 = taskNameToId(param_3), iVar2 == -1)) {
    errnoSet(uVar1);
    if (param_3 == (undefined1 *)0x0) {
      shellContextListLock();
      iVar2 = lstCount(DAT_3010e6e8);
      shellContextListUnlock();
      if (iVar2 == -1) {
        shellPrintErr(0,DAT_3010ec14,0xffffffff);
        puVar3 = (undefined4 *)__errno();
        *puVar3 = DAT_3010ec18;
        return 0;
      }
      iVar2 = iVar2 + -1;
      do {
        if (iVar2 == -1) {
          iVar2 = 0;
        }
        else {
          iVar2 = iVar2 + 1;
        }
        sprintf(acStack_11c,DAT_3010ec1c,*DAT_3010ec08,iVar2);
        iVar4 = taskNameToId(acStack_11c);
        param_3 = acStack_11c;
      } while (iVar4 != -1);
    }
    iVar2 = shellMemStrdup(param_3);
    if (iVar2 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = shellMemCalloc(1,DAT_3010ed14);
      if (iVar4 == 0) {
        shellMemFree(iVar2);
        iVar4 = 0;
      }
      else {
        *(int *)(iVar4 + 8) = iVar2;
        if (param_2 == 0) {
          param_2 = *DAT_3010ec04;
        }
        *(int *)(iVar4 + 0x41c) = param_2;
        *(undefined4 *)(iVar4 + 0x4c) = param_5;
        iVar5 = semMCreate(4);
        *(int *)(iVar4 + 0x410) = iVar5;
        if (iVar5 == 0) {
          printErr(DAT_3010ed18);
          shellMemFree(iVar2);
          shellMemFree(iVar4);
          iVar4 = 0;
        }
        else {
          if (param_1 != 0) {
            uVar1 = shellMemStrdup(param_1);
            *(undefined4 *)(iVar4 + 0x50) = uVar1;
            iVar5 = shellMemStrdup(param_1);
            *(int *)(iVar4 + 0x140) = iVar5;
            if ((*(int *)(iVar4 + 0x50) == 0) || (iVar5 == 0)) {
              shellMemFree(*(int *)(iVar4 + 0x50));
              shellMemFree(*(undefined4 *)(iVar4 + 0x140));
              shellMemFree(iVar4);
              shellMemFree(iVar2);
              return 0;
            }
          }
          lstInit(iVar4 + 0x28);
          *(undefined4 *)(iVar4 + 0xc) = 0;
          lstInit(iVar4 + 0x1c);
          *(undefined4 *)(iVar4 + 0x54) = *DAT_3010ed1c;
          *(undefined4 *)(iVar4 + 0x5c) = *DAT_3010ed20;
          *(undefined4 *)(iVar4 + 0x58) = *DAT_3010ed24;
          *(undefined4 *)(iVar4 + 0x60) = *DAT_3010ed28;
          if ((*DAT_3010e6e0 == 0) && (*DAT_3010e7fc != 0)) {
            strcpy((char *)(iVar4 + 100),DAT_3010e800);
            strcpy((char *)(iVar4 + 200),DAT_3010e804);
            *(undefined4 *)(iVar4 + 300) = 1;
          }
          iVar2 = 0x37;
          puVar3 = (undefined4 *)(iVar4 + 0x144);
          puVar6 = (undefined4 *)(iVar4 + 0x54);
          do {
            iVar2 = iVar2 + -1;
            *puVar3 = *puVar6;
            puVar3 = puVar3 + 1;
            puVar6 = puVar6 + 1;
          } while (iVar2 != 0);
        }
      }
    }
  }
  else {
    shellPrintErr(0,DAT_3010ec0c,param_3);
    puVar3 = (undefined4 *)__errno();
    *puVar3 = DAT_3010ec10;
    iVar4 = 0;
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * FUN_3010df20 @ 0x3010DF20  (примерный размер ~488 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 9
 * Вызывает: atomic32Dec, atomic32Inc, errnoSet, fdprintf, ioGlobalStdGet, ioTaskStdSet, ioctl, taskDelay, taskTcb
 * Вызывают: shellGenericInit
 * Константы: 0x3010DF20
 * Данные: DAT_3010eacc, DAT_3010ef84, DAT_3010ef88, DAT_3010ef8c, DAT_3010ef90, DAT_3010ef94
 * ---------------------------------------------------------------- */
int FUN_3010df20(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar4 = 0;
  if ((param_2 != 0) && (*param_1 != 0)) {
    uVar3 = 6;
    bVar5 = param_3 == 0;
    if (!bVar5) {
      iVar4 = ioGlobalStdGet(0);
      bVar5 = iVar4 == param_3;
    }
    if (bVar5) {
      uVar3 = 4;
    }
    iVar4 = taskTcb(0);
    local_2c = *(undefined4 *)(iVar4 + 0x104);
    uVar2 = *(undefined4 *)(iVar4 + 0x100);
    local_28 = *(undefined4 *)(iVar4 + 0x108);
    ioTaskStdSet(0,0,param_3);
    ioTaskStdSet(0,1,param_4);
    ioTaskStdSet(0,2,param_5);
    while ((iVar4 = ioctl(1,0xc,&local_30), iVar4 == 0 && (0 < local_30))) {
      taskDelay(1);
    }
    iVar4 = (*(code *)*param_1)(param_1[2],uVar3,param_1 + 4,0x50,param_1 + 0x1d,0x80);
    if (iVar4 == 0) {
      fdprintf(param_4,DAT_3010ef84);
    }
    ioTaskStdSet(0,0,uVar2);
    ioTaskStdSet(0,1,local_2c);
    ioTaskStdSet(0,2,local_28);
  }
  uVar3 = DAT_3010ef8c;
  if (*DAT_3010ef88 != -1) {
    iVar1 = atomic32Inc(DAT_3010ef8c);
    if (*DAT_3010ef88 <= iVar1) {
      atomic32Dec(uVar3);
      fdprintf(param_5,DAT_3010ef90);
      taskDelay(1);
      errnoSet(DAT_3010ef94);
      iVar4 = -1;
    }
  }
  if ((((param_2 != 0) && (*param_1 != 0)) && (iVar4 == 0)) &&
     ((code *)*DAT_3010eacc != (code *)0x0)) {
    (*(code *)*DAT_3010eacc)(param_1 + 4,param_1 + 0x1d);
    param_1[0x36] = 1;
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * shellGenericInit @ 0x3010E108  (примерный размер ~1068 байт)
 * Модуль: shell | Вызывают: 7 | Вызывает: 19
 * Вызывает: FUN_3010df20, __errno, ioGlobalStdGet, jobAdd, logFdAdd, logFdDelete, lstAdd, lstDelete, lstFirst, shellContextFinalize, shellContextInit, shellContextListLock, shellContextListUnlock, shellInOutInputUniqueCheck
 *           ...
 * Вызывают: BSP_LDScript, BSP_OM_ShellLock, FUN_30110c38, shellConsoleInit, shellRestart, shellSecureInit, usrShell
 * Константы: 0xFFFFFFFF, 0x3010E108
 * Данные: DAT_3010e6e0, DAT_3010e6e8, DAT_3010e90c, DAT_3010ec10, DAT_3010ed1c, DAT_3010ed20, DAT_3010ed24, DAT_3010ed28
 * ---------------------------------------------------------------- */
undefined4
shellGenericInit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 param_5,int param_6,int param_7,int param_8,int param_9)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  bool bVar12;
  int local_34;
  
  bVar2 = false;
  iVar5 = shellInOutInputUniqueCheck(param_7);
  piVar3 = DAT_3010e6e0;
  if (iVar5 == 0) {
    puVar6 = (undefined4 *)__errno();
    *puVar6 = DAT_3010ec10;
    return 0xffffffff;
  }
  if ((*DAT_3010e6e0 == 0) || (DAT_3010e6e0[2] == 0)) {
    bVar1 = false;
    iVar5 = shellContextInit(param_1,param_2,param_3,0,param_5);
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    *(int *)(iVar5 + 0x130) = param_7;
    *(int *)(iVar5 + 0x134) = param_8;
    *(int *)(iVar5 + 0x138) = param_9;
    iVar8 = DAT_3010f094;
    *(int *)(iVar5 + 0x414) = param_6;
    if (param_6 != 0) {
      bVar12 = param_7 == 0;
      if (!bVar12) {
        iVar7 = ioGlobalStdGet(0);
        bVar12 = iVar7 == param_7;
      }
      if (bVar12) {
        *(undefined4 *)(iVar5 + 0x58) = DAT_3010f098;
        *(int *)(iVar5 + 0x60) = iVar5;
      }
    }
    iVar7 = 0x37;
    puVar6 = (undefined4 *)(iVar5 + 0x144);
    puVar10 = (undefined4 *)(iVar5 + 0x54);
    do {
      iVar7 = iVar7 + -1;
      *puVar6 = *puVar10;
      puVar6 = puVar6 + 1;
      puVar10 = puVar10 + 1;
    } while (iVar7 != 0);
    iVar8 = FUN_3010df20(iVar5 + 0x144,*(undefined4 *)(iVar5 + iVar8),param_7,param_8,param_9);
    if (iVar8 == -1) {
      shellContextFinalize(iVar5);
      return 0xffffffff;
    }
    if (*piVar3 != 0) {
      piVar3[9] = param_7;
      piVar3[10] = param_8;
      piVar3[0xb] = param_9;
      piVar3[5] = 1;
    }
    shellContextListLock();
    uVar4 = DAT_3010e6e8;
    lstAdd(DAT_3010e6e8,iVar5);
    shellContextListUnlock();
    uVar11 = *DAT_3010e90c;
    uVar9 = shellTaskDefaultOptionsGet();
    iVar8 = taskCreate(*(undefined4 *)(iVar5 + 8),uVar11,uVar9,*(undefined4 *)(iVar5 + 0x41c),
                       DAT_3010f188,iVar5,0,0,0,0,0,0,0,0,0);
    if (iVar8 == -1) {
      shellContextListLock();
      lstDelete(uVar4,iVar5);
      shellContextListUnlock();
      shellContextFinalize(iVar5);
      return 0xffffffff;
    }
    if (piVar3[2] == 0) {
      piVar3[2] = iVar8;
    }
    bVar12 = param_7 == 0;
    if (!bVar12) {
      iVar7 = ioGlobalStdGet(0);
      bVar12 = iVar7 == param_7;
      if (!bVar12) {
        bVar12 = piVar3[2] == iVar8;
      }
    }
    if (bVar12) {
      *DAT_3010f18c = iVar8;
    }
    if ((param_8 != 1) && (iVar7 = ioGlobalStdGet(1), iVar7 != param_8)) {
      logFdDelete(param_8);
      iVar7 = logFdAdd(param_8);
      if (iVar7 == 0) {
        bVar1 = true;
      }
    }
    iVar7 = taskActivate(iVar8);
    if (iVar7 == -1) {
      if (bVar1) {
        logFdDelete(param_8);
      }
      if (*DAT_3010f18c == iVar8) {
        *DAT_3010f18c = 0;
      }
      if (piVar3[2] == iVar8) {
        piVar3[2] = 0;
      }
      shellContextListLock();
      lstDelete(uVar4,iVar5);
      shellContextListUnlock();
      shellContextFinalize(iVar5);
      return 0xffffffff;
    }
  }
  else {
    iVar5 = lstFirst(DAT_3010e6e8);
    puVar6 = DAT_3010f324;
    *DAT_3010f324 = *DAT_3010ed1c;
    puVar6[2] = *DAT_3010ed20;
    puVar6[1] = *DAT_3010ed24;
    puVar6[3] = *DAT_3010ed28;
    iVar8 = FUN_3010df20(puVar6,param_6,param_7,param_8,param_9);
    if (iVar8 == -1) {
      return 0xffffffff;
    }
    shellPrintErr(iVar5,DAT_3010f328);
    *DAT_3010f32c = param_6;
    piVar3[9] = param_7;
    piVar3[10] = param_8;
    piVar3[0xb] = param_9;
    piVar3[5] = 1;
    bVar2 = true;
    if ((param_8 != 1) && (iVar8 = ioGlobalStdGet(1), iVar8 != param_8)) {
      logFdDelete(param_8);
      logFdAdd(param_8);
    }
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(iVar5 + 8);
  }
  if ((*piVar3 != 0) && (bVar2)) {
    local_34 = 0;
    piVar3[0xf] = 1;
    iVar8 = jobAdd(DAT_3010f330,iVar5,0,0,0,0,0,&local_34);
    if ((iVar8 != 0) || (local_34 != 0)) {
      shellPrintErr(iVar5,DAT_3010f424);
      return 0xffffffff;
    }
  }
  taskDelay(1);
  return 0;
}

/* ----------------------------------------------------------------
 * shellConsoleInit @ 0x3010E534  (примерный размер ~112 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: ioGlobalStdGet, shellGenericInit
 * Константы: 0x3010E534
 * ---------------------------------------------------------------- */
void shellConsoleInit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = ioGlobalStdGet(2);
  uVar2 = ioGlobalStdGet(1);
  uVar3 = ioGlobalStdGet(0);
  shellGenericInit(param_1,param_2,param_3,param_4,1,0,uVar3,uVar2,uVar1);
  return;
}

/* ----------------------------------------------------------------
 * shellSecureInit @ 0x3010E5A4  (примерный размер ~56 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 1
 * Вызывает: shellGenericInit
 * Вызывают: shellParserControl
 * Константы: 0x3010E5A4
 * ---------------------------------------------------------------- */
void shellSecureInit(void)

{
  shellGenericInit();
  return;
}

/* ----------------------------------------------------------------
 * shellNext @ 0x3010E5DC  (примерный размер ~24 байт)
 * Модуль: shell | Вызывают: 19 | Вызывает: 1
 * Вызывает: lstNext
 * Вызывают: BSP_PromptSet, FUN_30111020, FUN_301150d4, FUN_30115590, shellAbort, shellDataFirst, shellDataNext, shellFromTaskGet, shellIdVerify, shellInOutBlockingOnDataClose
 *           ...
 * Константы: 0x3010E5DC
 * ---------------------------------------------------------------- */
void shellNext(int param_1)

{
  if (param_1 != 0) {
    lstNext(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * shellFromTaskGet @ 0x3010E5F4  (примерный размер ~76 байт)
 * Модуль: shell | Вызывают: 52 | Вызывает: 3
 * Вызывает: lstFirst, shellNext, taskIdSelf
 * Вызывают: FUN_30103378, FUN_3010ed74, FUN_3010fed0, FUN_30110b1c, FUN_30110e10, FUN_301125c4, shellAbort, shellBackgroundInit, shellBackgroundRead, shellConfigGet
 *           ...
 * Константы: 0x3010E5F4
 * Данные: DAT_3010e6e8, DAT_3010f4f8
 * ---------------------------------------------------------------- */
void shellFromTaskGet(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    param_1 = taskIdSelf();
  }
  iVar2 = lstFirst(DAT_3010e6e8);
  iVar1 = DAT_3010f4f8;
  if (iVar2 != 0) {
    do {
      if (*(int *)(iVar2 + iVar1) == param_1) {
        return;
      }
      iVar2 = shellNext();
    } while (iVar2 != 0);
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * shellBackgroundInit @ 0x3010E640  (примерный размер ~972 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 30
 * Вызывает: free, lstAdd, lstDelete, malloc, shellConfigGet, shellContextFinalize, shellContextInit, shellContextListLock, shellContextListUnlock, shellFromTaskGet, shellInOutBgndClose, shellInOutBgndIoClose, shellInOutBgndOpen, shellInOutBgndRegister
 *           ...
 * Константы: 0x3010E640
 * Данные: DAT_3010e6e0, DAT_3010e90c, DAT_3010f188, DAT_3010f640, DAT_3010f77c, DAT_3010f8ec
 * ---------------------------------------------------------------- */
int shellBackgroundInit(char *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  char *__s;
  size_t sVar5;
  char *__s_00;
  undefined4 uVar6;
  int __fd;
  int iVar7;
  undefined4 uVar8;
  ssize_t sVar9;
  undefined4 uVar10;
  undefined4 local_24;
  
  local_24 = 2;
  iVar1 = shellFromTaskGet(0);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else if (*DAT_3010e6e0 == 0) {
    sVar3 = strlen(param_2);
    iVar4 = shellInOutBgndOpen(sVar3 << 1,0x400);
    if (iVar4 == 0) {
      iVar2 = 0;
    }
    else {
      __s = (char *)shellConfigGet(iVar1);
      if (__s == (char *)0x0) {
        __s = (char *)malloc(10);
        if (__s == (char *)0x0) {
          shellInOutBgndIoClose(iVar4);
          return 0;
        }
        *__s = '\0';
      }
      if (param_1 == (char *)0x0) {
        __s_00 = (char *)shellMemStrdup(__s);
      }
      else {
        sVar3 = strlen(param_1);
        sVar5 = strlen(__s);
        __s_00 = (char *)shellMemMalloc(sVar5 + sVar3 + 0xe);
      }
      if (__s_00 == (char *)0x0) {
        free(__s);
        shellInOutBgndIoClose(iVar4);
        iVar2 = 0;
      }
      else {
        if (param_1 != (char *)0x0) {
          sprintf(__s_00,DAT_3010f640,__s,param_1);
        }
        free(__s);
        uVar6 = shellInOutSlavePtyGet(iVar4);
        __fd = shellInOutMasterPtyGet(iVar4);
        shellInOutGet(iVar1,0,0,&local_24);
        iVar2 = shellContextInit(__s_00,0,0,0,0);
        shellMemFree(__s_00);
        if (iVar2 == 0) {
          shellInOutBgndIoClose(iVar4);
          iVar2 = 0;
        }
        else {
          *(undefined4 *)(iVar2 + 0x130) = uVar6;
          *(undefined4 *)(iVar2 + 0x134) = uVar6;
          *(undefined4 *)(iVar2 + 0x138) = local_24;
          *(undefined4 *)(iVar2 + 0x430) = 1;
          shellContextListLock();
          uVar6 = DAT_3010f77c;
          lstAdd(DAT_3010f77c,iVar2);
          shellContextListUnlock();
          iVar7 = shellWorkingMemCtxDuplicate(iVar1,iVar2);
          if (iVar7 == 0) {
            shellInOutBgndRegister(iVar1,iVar2,iVar4);
            uVar10 = *DAT_3010e90c;
            uVar8 = shellTaskDefaultOptionsGet();
            iVar4 = taskSpawn(*(undefined4 *)(iVar2 + 8),uVar10,uVar8,*(undefined4 *)(iVar2 + 0x41c)
                              ,DAT_3010f188,iVar2,0,0,0,0,0,0,0,0,0);
            if (iVar4 == -1) {
              shellContextListLock();
              lstDelete(uVar6,iVar2);
              shellContextListUnlock();
              shellContextFinalize(iVar2);
              shellInOutBgndClose(iVar1);
              iVar2 = 0;
            }
            else {
              while (((iVar7 = taskIdVerify(iVar4), iVar7 == 0 &&
                      (iVar7 = taskIsSuspended(iVar4), iVar7 == 0)) &&
                     (iVar7 = taskIsPended(iVar4), iVar7 == 0))) {
                taskDelay(1);
              }
              iVar7 = taskIdVerify(iVar4);
              if ((iVar7 == 0) && (iVar4 = taskIsSuspended(iVar4), iVar4 != 0)) {
                shellInOutBgndClose(iVar1);
                iVar2 = 0;
              }
              else {
                sVar3 = strlen(param_2);
                sVar5 = write(__fd,param_2,sVar3);
                if (sVar5 == sVar3) {
                  if ((param_2[sVar3 - 1] != '\n') &&
                     (sVar9 = write(__fd,DAT_3010f8ec,1), sVar9 != 1)) {
                    shellInOutBgndClose(iVar1);
                    iVar2 = 0;
                  }
                }
                else {
                  shellInOutBgndClose(iVar1);
                  iVar2 = 0;
                }
              }
            }
          }
          else {
            shellContextListLock();
            lstDelete(uVar6,iVar2);
            shellContextListUnlock();
            shellContextFinalize(iVar2);
            shellInOutBgndClose(iVar1);
            iVar2 = 0;
          }
        }
      }
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * shellIdVerify @ 0x3010EA0C  (примерный размер ~104 байт)
 * Модуль: shell | Вызывают: 45 | Вызывает: 3
 * Вызывает: lstFirst, shellFromTaskGet, shellNext
 * Вызывают: FUN_30103378, FUN_3010367c, FUN_30103738, FUN_301125c4, shellBackgroundRead, shellCompatibleSet, shellConfigGet, shellConfigSet, shellConfigValueGet, shellConfigValueSet
 *           ...
 * Константы: 0xFFFFFFFF, 0x3010EA0C
 * Данные: DAT_3010f77c
 * ---------------------------------------------------------------- */
undefined4 shellIdVerify(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
    if (param_1 == 0) {
      return 0xffffffff;
    }
  }
  else if (param_1 == -1) {
    return 0xffffffff;
  }
  iVar1 = lstFirst(DAT_3010f77c);
  while( true ) {
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    if (iVar1 == param_1) break;
    iVar1 = shellNext();
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellBackgroundRead @ 0x3010EA74  (примерный размер ~608 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 12
 * Вызывает: bzero, malloc, read, realloc, select, shellFromTaskGet, shellIdVerify, shellInOutBgndClose, shellInOutBgndGet, shellInOutMasterPtyGet, shellMemRegister, shellMemUnregister
 * Константы: 0x3010EA74
 * Данные: DAT_3010f9d8, DAT_3010f9dc
 * ---------------------------------------------------------------- */
char * shellBackgroundRead(int param_1,undefined4 param_2)

{
  char cVar1;
  __time_t *p_Var2;
  int iVar3;
  char *__ptr;
  int iVar4;
  uint __fd;
  char *pcVar5;
  int iVar6;
  ssize_t sVar7;
  int iVar8;
  int iVar9;
  timeval local_130;
  fd_set afStack_128 [2];
  
  iVar3 = shellFromTaskGet(0);
  if (iVar3 == 0) {
    __ptr = (char *)0x0;
  }
  else {
    iVar4 = shellInOutBgndGet(iVar3);
    if (iVar4 == 0) {
      __ptr = (char *)0x0;
    }
    else {
      iVar9 = *(int *)(iVar3 + 0x14);
      if (iVar9 == 0) {
        shellInOutBgndClose(iVar3);
        __ptr = (char *)0x0;
      }
      else {
        __fd = shellInOutMasterPtyGet(iVar4);
        pcVar5 = (char *)malloc(DAT_3010f9d8);
        if (pcVar5 == (char *)0x0) {
          shellInOutBgndClose(iVar3);
          __ptr = (char *)0x0;
        }
        else {
          if (param_1 != 0) {
            shellMemRegister(pcVar5,param_2,1,param_1);
          }
          iVar8 = 0;
          *pcVar5 = '\0';
          p_Var2 = DAT_3010f9dc;
          iVar4 = 0x100;
          do {
            while( true ) {
              __ptr = pcVar5;
              local_130.tv_sec = *p_Var2;
              local_130.tv_usec = p_Var2[1];
              bzero(afStack_128,0x100);
              afStack_128[0].fds_bits[__fd >> 5] =
                   afStack_128[0].fds_bits[__fd >> 5] | 1 << (__fd & 0x1f);
              iVar6 = select(__fd + 1,afStack_128,(fd_set *)0x0,(fd_set *)0x0,&local_130);
              if (iVar6 == -1) goto LAB_3010ec74;
              pcVar5 = __ptr;
              if (iVar6 == 0) break;
              sVar7 = read(__fd,__ptr + iVar8,0x100);
              if ((sVar7 == -1) || (sVar7 == 0)) goto LAB_3010ec74;
              iVar8 = iVar8 + sVar7;
              __ptr[iVar8] = '\0';
              if ((uint)(iVar4 - iVar8) < 0x101) {
                iVar6 = iVar4 + 0x100;
                pcVar5 = (char *)realloc(__ptr,iVar4 + 0x101);
                if (pcVar5 == (char *)0x0) goto LAB_3010ec74;
                p_Var2 = DAT_3010f9dc;
                iVar4 = iVar6;
                if (param_1 != 0) {
                  shellMemUnregister(__ptr,param_1);
                  shellMemRegister(pcVar5,param_2,1,param_1);
                  p_Var2 = DAT_3010f9dc;
                }
              }
            }
            iVar6 = shellIdVerify(iVar9);
            p_Var2 = DAT_3010f9dc;
          } while (iVar6 == 0);
LAB_3010ec74:
          shellInOutBgndClose(iVar3);
          cVar1 = *__ptr;
          pcVar5 = __ptr;
          while (cVar1 != '\0') {
            if (*pcVar5 == '\n' || *pcVar5 == '\r') {
              *pcVar5 = ' ';
            }
            pcVar5 = pcVar5 + 1;
            cVar1 = *pcVar5;
          }
        }
      }
    }
  }
  return __ptr;
}

/* ----------------------------------------------------------------
 * shellLineLenGet @ 0x3010ECD4  (примерный размер ~120 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 3
 * Вызывает: shellConfigValueGet, shellInternalStrToInt32, shellPrintErr
 * Вызывают: shellExec, shellInterpCtxCreate
 * Константы: 0x3010ECD4
 * Данные: DAT_3010fc34, DAT_3010fc38, DAT_3010fc3c
 * ---------------------------------------------------------------- */
int shellLineLenGet(void)

{
  int iVar1;
  int local_8 [2];
  
  iVar1 = shellConfigValueGet(0,DAT_3010fc34);
  if (iVar1 != 0) {
    iVar1 = shellInternalStrToInt32(iVar1,local_8,0);
    if ((iVar1 == 0) && (0 < local_8[0])) {
      return local_8[0];
    }
    shellPrintErr(0,DAT_3010fc38,DAT_3010fc34);
  }
  return *DAT_3010fc3c;
}

/* ----------------------------------------------------------------
 * shellLoginInstall @ 0x3010ED4C  (примерный размер ~20 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3010ED4C
 * Данные: DAT_3010fc40, DAT_3010fc44
 * ---------------------------------------------------------------- */
void shellLoginInstall(undefined4 param_1,undefined4 param_2)

{
  *DAT_3010fc40 = param_1;
  *DAT_3010fc44 = param_2;
  return;
}

/* ----------------------------------------------------------------
 * shellLogoutInstall @ 0x3010ED60  (примерный размер ~20 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: shellParserControl
 * Константы: 0x3010ED60
 * Данные: DAT_3010fc48, DAT_3010fc4c
 * ---------------------------------------------------------------- */
void shellLogoutInstall(undefined4 param_1,undefined4 param_2)

{
  *DAT_3010fc48 = param_1;
  *DAT_3010fc4c = param_2;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010ed74 @ 0x3010ED74  (примерный размер ~88 байт)
 * Модуль: shell | Вызывают: 6 | Вызывает: 2
 * Вызывает: shellFromTaskGet, shellPrintErr
 * Вызывают: shellHistory, shellLock, shellLogout2, shellPromptSet, shellScriptAbort, shellScriptNoAbort
 * Константы: 0x3010ED74
 * Данные: DAT_3010f18c, DAT_3010fc50, DAT_3010fc54
 * ---------------------------------------------------------------- */
int FUN_3010ed74(int param_1)

{
  int iVar1;
  
  iVar1 = shellFromTaskGet(0);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = shellFromTaskGet(*DAT_3010f18c);
  if (iVar1 == 0) {
    if (param_1 == 0) {
      param_1 = *DAT_3010fc50;
    }
    shellPrintErr(0,*DAT_3010fc54,param_1);
    return 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellLogout2 @ 0x3010EDCC  (примерный размер ~252 байт)
 * Модуль: shell | Вызывают: 4 | Вызывает: 6
 * Вызывает: FUN_3010ed74, lstFirst, shellFromTaskGet, shellNext, shellPrintErr, taskSuspend
 * Вызывают: logout, shellExec, shellExitWrapper, shellLogout
 * Константы: 0xFFFFFFFF, 0x3010EDCC
 * Данные: DAT_3010f77c, DAT_3010fc50, DAT_3010fdd4
 * ---------------------------------------------------------------- */
undefined4 shellLogout2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == -1) {
    uVar3 = 0;
    for (iVar1 = lstFirst(DAT_3010f77c); iVar1 != 0; iVar1 = shellNext(iVar1)) {
      iVar2 = shellLogout2(iVar1,param_2);
      if (iVar2 != 0) {
        uVar3 = 0xffffffff;
      }
    }
  }
  else {
    if (param_1 == 0) {
      param_1 = shellFromTaskGet(0);
    }
    if (param_1 == 0) {
      param_1 = FUN_3010ed74(param_2);
    }
    if (param_1 == 0) {
      uVar3 = 0xffffffff;
    }
    else if (*(int *)(param_1 + 0x414) == 0) {
      if (param_2 == 0) {
        param_2 = *DAT_3010fc50;
      }
      shellPrintErr(param_1,DAT_3010fdd4,param_2);
      uVar3 = 0xffffffff;
    }
    else {
      if (*(code **)(param_1 + 0x148) != (code *)0x0) {
        uVar3 = *(undefined4 *)(param_1 + 0x424);
        (**(code **)(param_1 + 0x148))(*(undefined4 *)(param_1 + 0x150));
        taskSuspend(uVar3);
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * shellLogout @ 0x3010EEC8  (примерный размер ~8 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: shellLogout2
 * Константы: 0x3010EEC8
 * ---------------------------------------------------------------- */
void shellLogout(undefined4 param_1)

{
  shellLogout2(param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * shellTaskGet @ 0x3010EED0  (примерный размер ~76 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 2
 * Вызывает: shellFromTaskGet, shellIdVerify
 * Вызывают: shellInOutBgndClose, shellMemStringShow, shellRestart
 * Константы: 0x3010EED0
 * ---------------------------------------------------------------- */
int shellTaskGet(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if (*(int *)(param_1 + 0x424) != 0) {
    return *(int *)(param_1 + 0x424);
  }
  return -1;
}

/* ----------------------------------------------------------------
 * FUN_3010ef1c @ 0x3010EF1C  (примерный размер ~184 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 4
 * Вызывает: FUN_3010dac8, close, ioctl, taskDelete
 * Вызывают: FUN_3010f2f0, shellRestart, shellTerminate
 * Константы: 0x3010EF1C
 * Данные: DAT_3010fdd8
 * ---------------------------------------------------------------- */
void FUN_3010ef1c(int param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  FUN_3010dac8();
  if (*(int *)(param_1 + 0x430) != 0) {
    ioctl(*(int *)(param_1 + 0x134),0xe,0);
    close(*(int *)(param_1 + 0x134));
  }
  iVar1 = DAT_3010fdd8;
  iVar3 = 0;
  if (0 < *(int *)(DAT_3010fdd8 + 0x10)) {
    do {
      pcVar2 = *(code **)(*(int *)(iVar1 + 4) + iVar3 * 4);
      if (pcVar2 == (code *)0x0) break;
      (*pcVar2)(param_1,1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(iVar1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x42c) = 0;
  taskDelete(*(undefined4 *)(param_1 + 0x424));
  return;
}

/* ----------------------------------------------------------------
 * shellTerminate @ 0x3010EFD4  (примерный размер ~312 байт)
 * Модуль: shell | Вызывают: 4 | Вызывает: 5
 * Вызывает: FUN_3010ef1c, ioGlobalStdSet, shellIdVerify, shellRestart, taskIdSelf
 * Вызывают: BSP_OM_ShellLock, FUN_30110c38, shellParserControl, shellRestart
 * Константы: 0x3010EFD4
 * Данные: DAT_3010fdd8, DAT_3010ff44, DAT_3010ff48, DAT_3010ff4c
 * ---------------------------------------------------------------- */
void shellTerminate(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (((param_1 != 0) && (iVar2 = taskIdSelf(), iVar2 != *(int *)(param_1 + 0x424))) &&
     (iVar2 = shellIdVerify(param_1), iVar2 == 0)) {
    if (((*(int *)(param_1 + 0x414) != 0) && ((code *)*DAT_3010ff44 != (code *)0x0)) &&
       (*(int *)(param_1 + 300) != 0)) {
      (*(code *)*DAT_3010ff44)(param_1 + 100,param_1 + 200);
      *(undefined4 *)(param_1 + 300) = 0;
    }
    *(undefined4 *)(param_1 + 0x150) = 0;
    piVar1 = DAT_3010fdd8;
    if ((*DAT_3010fdd8 == 0) || (*DAT_3010ff48 == 0)) {
      FUN_3010ef1c(param_1);
      if (*piVar1 != 0) {
        if (2 < piVar1[6]) {
          ioGlobalStdSet(0,piVar1[6]);
        }
        if (2 < piVar1[3]) {
          ioGlobalStdSet(1,piVar1[3]);
        }
        if (2 < piVar1[7]) {
          ioGlobalStdSet(2,piVar1[7]);
        }
      }
    }
    else {
      *DAT_3010ff4c = 1;
      shellRestart(param_1);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * shellRestart @ 0x3010F10C  (примерный размер ~484 байт)
 * Модуль: shell | Вызывают: 4 | Вызывает: 16
 * Вызывает: FUN_3010dac8, FUN_3010ef1c, jobAdd, lstDelete, printErr, puts, shellContextFinalize, shellContextListLock, shellContextListUnlock, shellFromTaskGet, shellGenericInit, shellIdVerify, shellTaskGet, shellTerminate
 *           ...
 * Вызывают: FUN_3010f2f0, FUN_30110e10, shellExec, shellTerminate
 * Константы: 0xFFFFFFFF, 0x3010F10C
 * Данные: DAT_3010f330, DAT_3010f77c, DAT_3010fdd8, DAT_30110084, DAT_301101d4
 * ---------------------------------------------------------------- */
undefined4 shellRestart(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = 0;
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
    if (param_1 == 0) {
      return 0xffffffff;
    }
    iVar1 = jobAdd(DAT_3010f330,param_1,0,0,0,0,0,0);
    if ((iVar1 != 0) && (*(int *)(param_1 + 0x430) == 0)) {
      printErr(DAT_30110084);
      return 0xffffffff;
    }
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 == 0) {
    taskDelay(10);
    if ((*(int *)(param_1 + 0x14) != 0) &&
       (iVar1 = shellIdVerify(*(int *)(param_1 + 0x14)), iVar1 == 0)) {
      shellTerminate(*(undefined4 *)(param_1 + 0x14));
    }
    if (*(int *)(param_1 + 0x430) == 0) {
      FUN_3010dac8(param_1);
      iVar1 = DAT_3010fdd8;
      iVar4 = 0;
      if (0 < *(int *)(DAT_3010fdd8 + 0x10)) {
        do {
          pcVar2 = *(code **)(*(int *)(iVar1 + 4) + iVar4 * 4);
          if (pcVar2 == (code *)0x0) break;
          (*pcVar2)(param_1,1);
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(iVar1 + 0x10));
      }
      *(undefined4 *)(param_1 + 0x42c) = 1;
      iVar1 = shellTaskGet(param_1);
      if (iVar1 != -1) {
        shellTaskGet(param_1);
        iVar1 = taskRestart();
        if (iVar1 != -1) {
          return 0;
        }
      }
      puts(DAT_301101d4);
      shellContextListLock();
      lstDelete(DAT_3010f77c,param_1);
      shellContextListUnlock();
      iVar1 = shellGenericInit(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x41c),
                               *(undefined4 *)(param_1 + 8),0,*(undefined4 *)(param_1 + 0x4c),
                               *(undefined4 *)(param_1 + 0x414),*(undefined4 *)(param_1 + 0x130),
                               *(undefined4 *)(param_1 + 0x134),*(undefined4 *)(param_1 + 0x138));
      if (iVar1 == -1) {
        printErr(DAT_30110084);
        uVar3 = 0xffffffff;
      }
      shellContextFinalize(param_1);
    }
    else {
      FUN_3010ef1c();
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_3010f2f0 @ 0x3010F2F0  (примерный размер ~428 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 9
 * Вызывает: FUN_3010ef1c, ioTaskStdSet, ioctl, printErr, puts, shellRestart, taskResume, taskSuspend, taskTcb
 * Вызывают: shellAbort
 * Константы: 0x3010F2F0
 * Данные: DAT_3010f8ec, DAT_3010fdd8, DAT_30110370, DAT_30110374, DAT_30110378, DAT_3011037c, DAT_30110380
 * ---------------------------------------------------------------- */
undefined4 FUN_3010f2f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  int iVar6;
  
  ioctl(*(int *)(param_1 + 0x220),2,0);
  ioctl(*(int *)(param_1 + 0x224),2,0);
  if (*(int *)(param_1 + 0x430) != 0) {
    ioctl(*(int *)(param_1 + 0x220),0xe,0);
    ioctl(*(int *)(param_1 + 0x224),0xe,0);
    FUN_3010ef1c(param_1);
    return 0;
  }
  ioctl(*(int *)(param_1 + 0x228),2,0);
  iVar1 = taskTcb(0);
  uVar4 = *(undefined4 *)(iVar1 + 0x104);
  uVar3 = *(undefined4 *)(iVar1 + 0x108);
  ioTaskStdSet(0,1,*(undefined4 *)(param_1 + 0x224));
  ioTaskStdSet(0,2,*(undefined4 *)(param_1 + 0x228));
  printErr(DAT_3010f8ec);
  iVar1 = DAT_3010fdd8;
  iVar6 = 0;
  if (0 < *(int *)(DAT_3010fdd8 + 0x10)) {
    do {
      pcVar5 = *(code **)(*(int *)(iVar1 + 4) + iVar6 * 4);
      if (pcVar5 == (code *)0x0) break;
      (*pcVar5)(param_1,1);
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(iVar1 + 0x10));
  }
  if (*DAT_30110370 == 0) {
    puts(DAT_30110374);
  }
  else {
    iVar1 = taskSuspend(*(undefined4 *)(param_1 + 0x424));
    uVar2 = DAT_30110378;
    if (iVar1 == 0) {
      (*(code *)*DAT_30110370)(*(undefined4 *)(param_1 + 0x424),DAT_3011037c);
      iVar1 = taskResume(*(undefined4 *)(param_1 + 0x424));
      uVar2 = DAT_30110380;
      if (iVar1 == 0) goto LAB_3010f46c;
    }
    printErr(uVar2);
  }
LAB_3010f46c:
  ioTaskStdSet(0,1,uVar4);
  ioTaskStdSet(0,2,uVar3);
  uVar3 = shellRestart(param_1);
  return uVar3;
}

/* ----------------------------------------------------------------
 * shellAbort @ 0x3010F49C  (примерный размер ~204 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_3010f2f0, jobAdd, lstFirst, shellFromTaskGet, shellNext, taskIdSelf
 * Вызывают: FUN_30103738
 * Константы: 0x3010F49C, 0xFFFFFFFF
 * Данные: DAT_3010f77c, DAT_30110384, DAT_30110388
 * ---------------------------------------------------------------- */
undefined4 shellAbort(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    iVar2 = shellFromTaskGet(0);
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      jobAdd(DAT_30110384,iVar2,0,0,0,0,0,0);
      uVar3 = 0;
    }
  }
  else if (param_1 == -1) {
    iVar2 = lstFirst(DAT_3010f77c);
    iVar1 = DAT_30110388;
    for (; iVar2 != 0; iVar2 = shellNext(iVar2)) {
      iVar4 = taskIdSelf();
      if (iVar4 != *(int *)(iVar2 + iVar1)) {
        FUN_3010f2f0(iVar2);
      }
    }
    shellAbort(0);
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_3010f2f0(param_1);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * shellPromptSet @ 0x3010F568  (примерный размер ~188 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_3010ed74, __errno, shellPrintErr, shellPromptFmtDftSet, shellPromptFmtSet
 * Константы: 0x3010F568
 * Данные: DAT_3010fc50, DAT_3010fdd8, DAT_301104e0, DAT_301104e4, DAT_301104e8, DAT_301104ec, DAT_301104f0
 * ---------------------------------------------------------------- */
int shellPromptSet(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  if ((*DAT_3010fdd8 == 0) || (iVar1 = shellPromptFmtDftSet(DAT_301104e0,param_1), iVar1 == 0)) {
    iVar1 = FUN_3010ed74(0);
    if (iVar1 == 0) {
      return -1;
    }
    iVar1 = shellPromptFmtSet(iVar1,DAT_301104e0,param_1);
  }
  if (iVar1 == -1) {
    shellPrintErr(0,DAT_301104e4,*DAT_3010fc50);
    piVar2 = (int *)__errno();
    if (*piVar2 == DAT_301104e8) {
      shellPrintErr(0,DAT_301104ec);
    }
    else {
      puVar3 = (undefined4 *)__errno();
      shellPrintErr(0,DAT_301104f0,*puVar3);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellScriptAbort @ 0x3010F624  (примерный размер ~48 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3010ed74
 * Вызывают: usrModuleLoad
 * Константы: 0x3010F624, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellScriptAbort(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_3010ed74(0);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    *(undefined4 *)(iVar1 + 0x428) = 1;
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellScriptNoAbort @ 0x3010F654  (примерный размер ~44 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_3010ed74
 * Константы: 0x3010F654, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellScriptNoAbort(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_3010ed74(0);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    *(undefined4 *)(iVar1 + 0x428) = 0;
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellHistory @ 0x3010F680  (примерный размер ~64 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_3010ed74, ledControl
 * Константы: 0xFFFFFFFF, 0x3010F680
 * ---------------------------------------------------------------- */
undefined4 shellHistory(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_3010ed74(0);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  ledControl(*(undefined4 *)(iVar1 + 0x420),0xffffffff,0xffffffff,param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * shellLock @ 0x3010F6C0  (примерный размер ~72 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3010ed74
 * Вызывают: shellParserControl
 * Константы: 0x3010F6C0
 * Данные: DAT_3010fdd8
 * ---------------------------------------------------------------- */
undefined4 shellLock(int param_1)

{
  int iVar1;
  
  if (*DAT_3010fdd8 != 0) {
    iVar1 = FUN_3010ed74(0);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x434) == param_1)) {
      return 0;
    }
    *(int *)(iVar1 + 0x434) = param_1;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * shellFromNameGet @ 0x3010F708  (примерный размер ~28 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 2
 * Вызывает: shellFromTaskGet, taskNameToId
 * Вызывают: BSP_OM_ShellLock, shellDataFromNameAdd, shellDataFromNameGet
 * Константы: 0x3010F708
 * ---------------------------------------------------------------- */
void shellFromNameGet(void)

{
  int iVar1;
  
  iVar1 = taskNameToId();
  if (iVar1 != -1) {
    shellFromTaskGet(iVar1);
  }
  return;
}

/* ----------------------------------------------------------------
 * shellExitWrapper @ 0x3010F724  (примерный размер ~164 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 8
 * Вызывает: exit, ioctl, isatty, shellFromTaskGet, shellLogout2, shellPrint, taskDelay, taskSuspend
 * Константы: 0x3010F724
 * Данные: DAT_301106a4
 * ---------------------------------------------------------------- */
void shellExitWrapper(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = shellFromTaskGet(0);
  if (iVar1 == 0) {
    return;
  }
  shellPrint(iVar1,DAT_301106a4);
  taskDelay(1);
  iVar2 = isatty(*(int *)(iVar1 + 0x224));
  if (iVar2 != 0) {
    ioctl(*(int *)(iVar1 + 0x224),0x1b,0);
  }
  iVar2 = isatty(*(int *)(iVar1 + 0x228));
  if (iVar2 != 0) {
    ioctl(*(int *)(iVar1 + 0x228),0x1b,0);
  }
  if (*(int *)(iVar1 + 0x414) != 0) {
    shellLogout2(iVar1,0);
    taskSuspend(0);
  }
  exit(param_1);
  return;
}

/* ----------------------------------------------------------------
 * shellErrnoSet @ 0x3010F7C8  (примерный размер ~56 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: shellFromTaskGet, shellIdVerify
 * Вызывают: FUN_30108cb4
 * Константы: 0x3010F7C8
 * ---------------------------------------------------------------- */
void shellErrnoSet(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x418) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * shellErrnoGet @ 0x3010F800  (примерный размер ~60 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: shellFromTaskGet, shellIdVerify
 * Вызывают: FUN_30108cb4
 * Константы: 0x3010F800, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellErrnoGet(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  return *(undefined4 *)(param_1 + 0x418);
}

/* ----------------------------------------------------------------
 * shellCompatibleCheck @ 0x3010F83C  (примерный размер ~12 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 0
 * Вызывают: shellInOutGet, shellInOutSet
 * Константы: 0x3010F83C
 * Данные: DAT_3010fdd8
 * ---------------------------------------------------------------- */
undefined4 shellCompatibleCheck(void)

{
  return *DAT_3010fdd8;
}

/* ----------------------------------------------------------------
 * shellTaskIdDefault @ 0x3010F848  (примерный размер ~252 байт)
 * Модуль: shell | Вызывают: 10 | Вызывает: 6
 * Вызывает: lstFirst, shellDataAdd, shellDataGet, shellFromTaskGet, shellNext, taskIdDefault
 * Вызывают: FUN_30114978, FUN_30115590, FUN_30115680, FUN_3011b068, dbgTaskTraceCoreRtn, pc, taskIdFigure, taskRegsModify, ti, tw
 * Константы: 0x3010F848
 * Данные: DAT_301107e4, DAT_301107e8, DAT_301107ec
 * ---------------------------------------------------------------- */
undefined4 shellTaskIdDefault(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  
  if (((param_1 != 0) || (param_1 = shellFromTaskGet(0), param_1 != 0)) ||
     (param_1 = shellFromTaskGet(*DAT_301107e4), param_1 != 0)) {
    uVar2 = DAT_301107e8;
    if (param_2 != 0) {
      if (param_1 == -1) {
        for (iVar1 = lstFirst(DAT_301107e8); iVar1 != 0; iVar1 = shellNext(iVar1)) {
          shellDataAdd(iVar1,DAT_301107ec,param_2,0);
        }
        param_1 = lstFirst(uVar2);
      }
      else {
        shellDataAdd(param_1,DAT_301107ec,param_2,0);
      }
      taskIdDefault(param_2);
    }
    if ((param_1 != -1) && (iVar1 = shellDataGet(param_1,DAT_301107ec,&local_14), iVar1 == 0)) {
      return local_14;
    }
  }
  uVar2 = taskIdDefault(param_2);
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellCompatibleSet @ 0x3010F944  (примерный размер ~512 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 11
 * Вызывает: ioGlobalStdGet, ioTaskStdGet, jobAdd, lstCount, lstFirst, shellContextListLock, shellContextListUnlock, shellIdVerify, shellPrintErr, taskIdSelf, taskSuspend
 * Вызывают: FUN_3003ffc8
 * Константы: 0x3010F944
 * Данные: DAT_3010fdd8, DAT_3010ff48, DAT_301107e8, DAT_301108cc, DAT_301108d0, DAT_30110a50, DAT_30110a54
 * ---------------------------------------------------------------- */
void shellCompatibleSet(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = 0;
  if (param_1 == 0) {
    if (*DAT_3010fdd8 == 0) {
      return;
    }
  }
  else if (*DAT_3010fdd8 != 0) {
    return;
  }
  shellContextListLock();
  uVar2 = DAT_301107e8;
  iVar3 = lstCount(DAT_301107e8);
  if ((1 < iVar3) && (param_1 != 0)) {
    shellPrintErr(0,DAT_301108cc);
    shellContextListUnlock();
    return;
  }
  if ((*DAT_3010ff48 != 0) && (param_1 == 0)) {
    shellPrintErr(0,DAT_301108d0);
    shellContextListUnlock();
    return;
  }
  iVar3 = lstFirst(uVar2);
  iVar4 = shellIdVerify();
  piVar1 = DAT_3010fdd8;
  if (iVar4 == 0) {
    iVar5 = *(int *)(iVar3 + 0x424);
  }
  else {
    iVar3 = 0;
  }
  if ((param_1 == 0) || (*DAT_3010fdd8 != 0)) {
    *DAT_3010fdd8 = 0;
    if (iVar3 == 0) goto LAB_3010fb18;
    *DAT_30110a50 = 1;
  }
  else {
    *DAT_3010fdd8 = 1;
    iVar4 = ioGlobalStdGet(0);
    piVar1[0xc] = iVar4;
    iVar4 = ioGlobalStdGet(1);
    piVar1[0xd] = iVar4;
    iVar4 = ioGlobalStdGet(2);
    piVar1[0xe] = iVar4;
    if (iVar3 == 0) goto LAB_3010fb18;
    iVar4 = *(int *)(iVar3 + 0x220);
    iVar6 = *(int *)(iVar3 + 0x224);
    iVar7 = *(int *)(iVar3 + 0x228);
    if (iVar4 < 3) {
      iVar4 = ioTaskStdGet(*(undefined4 *)(iVar3 + 0x424),0);
    }
    if (iVar6 < 3) {
      iVar6 = ioTaskStdGet(*(undefined4 *)(iVar3 + 0x424),1);
    }
    if (iVar7 < 3) {
      iVar7 = ioTaskStdGet(*(undefined4 *)(iVar3 + 0x424),2);
    }
    piVar1[9] = iVar4;
    piVar1[10] = iVar6;
    piVar1[0xb] = iVar7;
    piVar1[5] = 1;
  }
  jobAdd(DAT_30110a54,iVar3,0,0,0,0,0,0);
LAB_3010fb18:
  shellContextListUnlock();
  if ((iVar3 != 0) && (iVar3 = taskIdSelf(), iVar3 == iVar5)) {
    taskSuspend(0);
  }
  return;
}

/* ----------------------------------------------------------------
 * shellTaskDefaultOptionsSet @ 0x3010FB44  (примерный размер ~80 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3003ffc8
 * Константы: 0x3010FB44
 * Данные: DAT_30110a58, DAT_30110a5c, DAT_30110a60, DAT_30110a64
 * ---------------------------------------------------------------- */
void shellTaskDefaultOptionsSet(int param_1)

{
  if ((*DAT_30110a58 == 0) && (param_1 != 0)) {
    *DAT_30110a5c = param_1;
    *DAT_30110a58 = 1;
  }
  if (param_1 == 0) {
    param_1 = *DAT_30110a5c;
    *DAT_30110a60 = 0;
  }
  *DAT_30110a64 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * shellTaskDefaultStackSizeSet @ 0x3010FB94  (примерный размер ~68 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3003ffc8
 * Константы: 0x3010FB94
 * Данные: DAT_30110a68, DAT_30110a6c, DAT_30110a70
 * ---------------------------------------------------------------- */
void shellTaskDefaultStackSizeSet(int param_1)

{
  if ((*DAT_30110a68 == 0) && (param_1 != 0)) {
    *DAT_30110a6c = param_1;
    *DAT_30110a68 = 1;
  }
  if (param_1 == 0) {
    param_1 = *DAT_30110a6c;
  }
  *DAT_30110a70 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * shellTaskDefaultPrioritySet @ 0x3010FBD8  (примерный размер ~68 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3003ffc8
 * Константы: 0x3010FBD8
 * Данные: DAT_30110a74, DAT_30110a78, DAT_30110a7c
 * ---------------------------------------------------------------- */
void shellTaskDefaultPrioritySet(int param_1)

{
  if ((*DAT_30110a74 == 0) && (param_1 != -1)) {
    *DAT_30110a78 = param_1;
    *DAT_30110a74 = 1;
  }
  if (param_1 == -1) {
    param_1 = *DAT_30110a78;
  }
  *DAT_30110a7c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * shellTaskDefaultBaseNameSet @ 0x3010FC1C  (примерный размер ~108 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3003ffc8
 * Константы: 0x3010FC1C
 * Данные: DAT_30110a80, DAT_30110b50, DAT_30110b54
 * ---------------------------------------------------------------- */
void shellTaskDefaultBaseNameSet(int param_1)

{
  if ((*DAT_30110a80 == 0) && (param_1 != 0)) {
    *DAT_30110b50 = param_1;
    *DAT_30110a80 = 1;
  }
  if (param_1 == 0) {
    param_1 = *DAT_30110b50;
  }
  *DAT_30110b54 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010fc88 @ 0x3010FC88  (примерный размер ~584 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 8
 * Вызывает: ledModeNameGet, shellConfigValueGet, shellConfigValueSet, shellInternalStrToInt, shellInterpDefaultNameGet, shellInterpNameGet, shellPrintErr, sprintf
 * Вызывают: FUN_3010ff7c
 * Константы: 0xFFFFFFFF, 0x3010FC88
 * Данные: DAT_30110b58, DAT_30110b5c, DAT_30110bec, DAT_30110bf0, DAT_30110bf4, DAT_30110bf8, DAT_30110bfc, DAT_30110ccc
 * ---------------------------------------------------------------- */
undefined4 FUN_3010fc88(int param_1)

{
  char *pcVar1;
  int iVar2;
  int local_28;
  int local_24;
  char acStack_20 [12];
  int local_14 [2];
  
  if ((*(int *)(param_1 + 0x420) != 0) &&
     ((pcVar1 = (char *)shellConfigValueGet(0,DAT_30110b58), pcVar1 == (char *)0x0 ||
      (*pcVar1 == '\0')))) {
    iVar2 = ledModeNameGet(*(undefined4 *)(param_1 + 0x420));
    if (iVar2 == 0) {
      shellPrintErr(0,DAT_30110b5c);
      return 0xffffffff;
    }
    shellConfigValueSet(0,DAT_30110b58,iVar2);
  }
  pcVar1 = (char *)shellConfigValueGet(0,DAT_30110bec);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    iVar2 = shellInterpNameGet(param_1);
    if ((iVar2 == 0) && (iVar2 = shellInterpDefaultNameGet(), iVar2 == 0)) {
      shellPrintErr(0,DAT_30110bf0);
      return 0xffffffff;
    }
    shellConfigValueSet(0,DAT_30110bec,iVar2);
  }
  pcVar1 = (char *)shellConfigValueGet(0,DAT_30110bf4);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    sprintf(acStack_20,DAT_30110bfc,*DAT_30110bf8);
    shellConfigValueSet(0,DAT_30110bf4,acStack_20);
  }
  pcVar1 = (char *)shellConfigValueGet(0,DAT_30110ccc);
  if ((((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) && (*(int *)(param_1 + 0x414) != 0)) &&
     (((iVar2 = shellInternalStrToInt(pcVar1,local_14,&local_28,&local_24,0), iVar2 != 1 ||
       ((local_28 != 4 && (local_28 != 5)))) || ((local_24 == 0 && (local_14[0] < 0)))))) {
    shellPrintErr(0,DAT_30110cd0);
    shellConfigValueSet(0,DAT_30110ccc,DAT_30110cd4);
  }
  iVar2 = shellConfigValueGet(0,DAT_30110cd8);
  if (iVar2 == 0) {
    shellConfigValueSet(0,DAT_30110cd8,DAT_30110cdc);
  }
  iVar2 = shellConfigValueGet(0,DAT_30110ce0);
  if (iVar2 == 0) {
    shellConfigValueSet(0,DAT_30110ce0,DAT_30110cdc);
  }
  iVar2 = shellConfigValueGet(0,DAT_30110ddc);
  if (iVar2 == 0) {
    shellConfigValueSet(0,DAT_30110ddc,DAT_30110de0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3010fed0 @ 0x3010FED0  (примерный размер ~172 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 4
 * Вызывает: __errno, ledModeSet, shellFromTaskGet, shellPrintErr
 * Вызывают: FUN_3010ff7c
 * Константы: 0xFFFFFFFF, 0x3010FED0
 * Данные: DAT_30110de4, DAT_30110de8, DAT_30110dec, DAT_30110df0, DAT_30110df4, DAT_30110df8
 * ---------------------------------------------------------------- */
undefined4 FUN_3010fed0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = shellFromTaskGet(0);
  if (iVar1 == 0) {
    shellPrintErr(0,*DAT_30110de4,*DAT_30110de8);
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30110dec;
    return 0xffffffff;
  }
  iVar1 = ledModeSet(*(undefined4 *)(iVar1 + 0x420),param_1);
  if (iVar1 != 0) {
    if (param_1 == 0) {
      shellPrintErr(0,DAT_30110df0);
    }
    else {
      shellPrintErr(0,DAT_30110df4,param_1);
    }
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30110df8;
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3010ff7c @ 0x3010FF7C  (примерный размер ~520 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 14
 * Вызывает: FUN_3010fc88, FUN_3010fed0, __errno, ledHistorySet, ledInactivityDelaySet, ledModeNameGet, shellConfigValueGet, shellConfigValueSet, shellInternalStrToInt, shellInterpDefaultNameGet, shellInterpNameGet, shellInterpSet, shellInterpSwitch, shellPrintErr
 * Вызывают: shellExec
 * Константы: 0xFFFFFFFF, 0x3010FF7C
 * Данные: DAT_30110b58, DAT_30110bec, DAT_30110ccc, DAT_30110f18, DAT_30110f1c, DAT_30110f20, DAT_30110f24, DAT_30110f28
 * ---------------------------------------------------------------- */
undefined4 FUN_3010ff7c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [8];
  undefined4 local_14 [2];
  
  iVar1 = FUN_3010fc88();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  uVar2 = shellConfigValueGet(0,DAT_30110bec);
  iVar1 = shellInterpSet(param_1,uVar2);
  if (iVar1 != 0) {
    iVar1 = shellInterpNameGet(param_1);
    iVar3 = shellConfigValueGet(0,DAT_30110bec);
    if (iVar3 == 0) {
      shellPrintErr(0,DAT_30110f1c);
    }
    else {
      uVar2 = shellConfigValueGet(0,DAT_30110bec);
      shellPrintErr(0,DAT_30110f18,uVar2);
    }
    if ((iVar1 == 0) && (iVar1 = shellInterpDefaultNameGet(), iVar1 == 0)) {
      shellPrintErr(0,DAT_30110f1c);
      return 0xffffffff;
    }
    shellConfigValueSet(0,DAT_30110bec,iVar1);
    shellInterpSet(param_1,iVar1);
  }
  iVar1 = shellInterpSwitch(param_1);
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 0x420) != 0) && (*(int *)(param_1 + 0x13c) != 0)) {
      shellConfigValueGet(0,DAT_30110b58);
      iVar1 = FUN_3010fed0();
      if (iVar1 != 0) {
        uVar2 = ledModeNameGet(*(undefined4 *)(param_1 + 0x420));
        shellConfigValueSet(0,DAT_30110b58,uVar2);
      }
      ledHistorySet(*(undefined4 *)(param_1 + 0x420),*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14)
                   );
      pcVar6 = (char *)shellConfigValueGet(0,DAT_30110ccc);
      if (((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) && (*(int *)(param_1 + 0x414) != 0)) {
        iVar1 = shellInternalStrToInt(pcVar6,local_14,auStack_1c,auStack_20,0);
        if (iVar1 != 1) {
          local_14[0] = 1;
        }
        ledInactivityDelaySet(*(undefined4 *)(param_1 + 0x420),local_14[0]);
      }
    }
    return 0;
  }
  piVar4 = (int *)__errno();
  if (*piVar4 == DAT_30110f20) {
    uVar5 = shellConfigValueGet(0,DAT_30110bec);
    uVar2 = DAT_30110f24;
  }
  else {
    piVar4 = (int *)__errno();
    if (*piVar4 != DAT_30110f28) {
      return 0xffffffff;
    }
    uVar5 = shellConfigValueGet(0,DAT_30110bec);
    uVar2 = DAT_30110f2c;
  }
  shellPrintErr(0,uVar2,uVar5);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_30110184 @ 0x30110184  (примерный размер ~84 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 3
 * Вызывает: lstAdd, shellMemMalloc, shellPrintErr
 * Вызывают: shellExec
 * Константы: 0x30110184
 * Данные: DAT_30111050
 * ---------------------------------------------------------------- */
undefined4 FUN_30110184(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = shellMemMalloc(param_2 + 0xd);
  if (iVar1 == 0) {
    shellPrintErr(0,DAT_30111050);
    return 0;
  }
  *(int *)(iVar1 + 8) = iVar1 + 0xc;
  lstAdd(param_1 + 0x40,iVar1);
  return *(undefined4 *)(iVar1 + 8);
}

/* ----------------------------------------------------------------
 * FUN_301101d8 @ 0x301101D8  (примерный размер ~76 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 1
 * Вызывает: strlen
 * Вызывают: FUN_30110224
 * Константы: 0x301101D8
 * Данные: DAT_30111054
 * ---------------------------------------------------------------- */
void FUN_301101d8(byte *param_1)

{
  size_t sVar1;
  byte *pbVar2;
  
  sVar1 = strlen((char *)param_1);
  pbVar2 = param_1 + (sVar1 - 1);
  if (param_1 <= pbVar2) {
    do {
      if ((*(byte *)(*DAT_30111054 + (uint)*pbVar2) & 0x28) == 0) break;
      pbVar2 = pbVar2 + -1;
    } while (param_1 <= pbVar2);
  }
  pbVar2[1] = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30110224 @ 0x30110224  (примерный размер ~320 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_301101d8, fioRdString, ioTaskStdGet, ledRead, shellPrint, shellPromptPrint, taskDelay
 * Вызывают: shellExec
 * Константы: 0x30110224
 * Данные: DAT_30111054, DAT_301111e8
 * ---------------------------------------------------------------- */
byte * FUN_30110224(int param_1,byte *param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  if (*(int *)(param_1 + 0x13c) == 0) {
    iVar2 = fioRdString(0);
    if (iVar2 == -1) {
      *param_4 = 3;
      return (byte *)0x0;
    }
    param_2[param_3] = 0;
    if (*(int *)(param_1 + 0x430) == 0) {
      shellPrint(0,DAT_301111e8,param_2);
    }
  }
  else {
    iVar2 = ioTaskStdGet(0,0);
    if (iVar2 == -1) {
      taskDelay(1);
      goto LAB_3011034c;
    }
    shellPromptPrint(param_1);
    iVar2 = ledRead(*(undefined4 *)(param_1 + 0x420),param_2,param_3);
    if (iVar2 == -1) {
      *param_4 = 2;
      return (byte *)0x0;
    }
    param_2[param_3] = 0;
  }
  iVar2 = 0;
  bVar1 = *(byte *)(*DAT_30111054 + (uint)*param_2);
  pbVar3 = param_2;
  while ((bVar1 & 0x28) != 0) {
    pbVar3 = pbVar3 + 1;
    iVar2 = iVar2 + 1;
    bVar1 = *(byte *)(*DAT_30111054 + (uint)*pbVar3);
  }
  if (((param_2[iVar2] != 0x23) && (param_2[iVar2] != 0)) &&
     (FUN_301101d8(param_2 + iVar2), param_2[iVar2] != 0)) {
    return param_2 + iVar2;
  }
LAB_3011034c:
  *param_4 = 1;
  return (byte *)0x0;
}

/* ----------------------------------------------------------------
 * shellExec @ 0x30110364  (примерный размер ~608 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 13
 * Вызывает: FUN_3010da44, FUN_3010ff7c, FUN_30110184, FUN_30110224, __errno, close, ioTaskStdGet, ledHistoryAdd, shellLineLenGet, shellLogout2, shellPrint, shellRestart, taskSuspend
 * Вызывают: shellInOutRedirectScript, shellTask
 * Константы: 0x30110364
 * Данные: DAT_30111304, DAT_30111308, DAT_3011130c, DAT_30111310
 * ---------------------------------------------------------------- */
int shellExec(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  code *pcVar7;
  undefined4 uVar8;
  int local_24;
  
  uVar2 = shellLineLenGet();
  iVar3 = FUN_30110184(param_1,uVar2);
  if (iVar3 == 0) {
    iVar4 = -1;
  }
  else {
    do {
      *(undefined4 *)(param_1 + 0x428) = 0;
      while( true ) {
        iVar4 = 0;
        iVar5 = FUN_3010ff7c(param_1);
        if (iVar5 != 0) goto LAB_30110598;
        puVar6 = (undefined4 *)__errno();
        uVar8 = *puVar6;
        puVar6 = (undefined4 *)__errno();
        *puVar6 = 0;
        iVar5 = FUN_30110224(param_1,iVar3,uVar2,&local_24);
        puVar6 = (undefined4 *)__errno();
        *puVar6 = uVar8;
        if (iVar5 != 0) break;
        if (local_24 != 1) {
          if (local_24 == 2) {
            FUN_3010da44(param_1);
            if (*(int *)(param_1 + 0x414) == 0) {
              iVar3 = shellRestart(param_1);
              if (iVar3 != 0) {
                taskSuspend(0);
              }
            }
            else {
              shellLogout2(param_1,0);
            }
          }
          goto LAB_301105b0;
        }
      }
      if (*(int *)(param_1 + 0x420) != 0) {
        ledHistoryAdd(*(undefined4 *)(*(int *)(param_1 + 0x420) + 8),iVar5);
      }
      piVar1 = DAT_30111304;
      if (((*DAT_30111304 == 0) && ((code *)*DAT_30111308 != (code *)0x0)) &&
         (*(int *)(param_1 + 0x21c) != 0)) {
        iVar4 = (*(code *)*DAT_30111308)(param_1 + 0x154,param_1 + 0x1b8);
        if (iVar4 != 0) {
          shellPrint(param_1,DAT_3011130c,param_1 + 0x154);
        }
      }
      iVar4 = 0;
      pcVar7 = *(code **)(*(int *)(*(int *)(param_1 + 0xc) + 8) + 0x18);
      if (((pcVar7 != (code *)0x0) &&
          (iVar4 = (*pcVar7)(*(int *)(param_1 + 0xc),iVar5,*(undefined4 *)(param_1 + 0x13c)),
          *piVar1 != 0)) && ((*(int *)(param_1 + 0x13c) == 0 && (iVar4 != 0)))) break;
      if (((code *)*DAT_30111310 != (code *)0x0) && (*(int *)(param_1 + 0x21c) != 0)) {
        (*(code *)*DAT_30111310)(param_1 + 0x154,param_1 + 0x1b8);
      }
      if (*(int *)(param_1 + 0x430) != 0) {
        iVar3 = ioTaskStdGet(0,1);
        close(iVar3);
        goto LAB_301105b0;
      }
    } while ((*(int *)(param_1 + 0x13c) != 0) || (*(int *)(param_1 + 0x428) == 0));
LAB_30110598:
    iVar4 = -1;
LAB_301105b0:
    FUN_3010da44(param_1);
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * shellTask @ 0x301105C4  (примерный размер ~1368 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 21
 * Вызывает: FUN_3010da44, FUN_3010dac8, ioGlobalStdGet, ioGlobalStdSet, ioctl, isatty, ledCompletionSet, ledOpen, shellConfigSet, shellDataRemove, shellExec, shellInOutInputHookSet, shellInOutSet, shellInterpRestart
 *           ...
 * Константы: 0xFFFFFFFF, 0x301105C4
 * Данные: DAT_30110a50, DAT_30111304, DAT_30111314, DAT_30111318, DAT_3011131c, DAT_30111320, DAT_30111324, DAT_30111328
 * ---------------------------------------------------------------- */
void shellTask(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  bool bVar8;
  _union_1051 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar7 = DAT_30111314;
  uVar2 = taskIdSelf();
  *(undefined4 *)(param_1 + 0x424) = uVar2;
  if ((*(int *)(param_1 + 0x4c) == 0) && (*(int *)(param_1 + 0x42c) != 0)) {
    *(undefined4 *)(param_1 + DAT_30111318) = 0;
    return;
  }
  *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x4c);
  FUN_3010dac8(param_1);
  while (iVar3 = FUN_3010da44(param_1), iVar3 == 0) {
    taskDelay(1);
  }
  shellDataRemove(param_1,DAT_3011131c,1);
  shellInterpRestart(param_1);
  iVar3 = DAT_30111304;
  if ((*(int *)(DAT_30111304 + 0x3c) != 0) || (*(int *)(DAT_30111304 + 0x14) != 0)) {
    uVar2 = ioGlobalStdGet(0);
    *(undefined4 *)(iVar3 + 0x18) = uVar2;
    uVar2 = ioGlobalStdGet(1);
    *(undefined4 *)(iVar3 + 0xc) = uVar2;
    uVar2 = ioGlobalStdGet(2);
    *(undefined4 *)(iVar3 + 0x1c) = uVar2;
  }
  iVar1 = DAT_30111318;
  if (*(int *)(iVar3 + 0x3c) == 0) {
    if (*DAT_3011132c != 0) {
      if (2 < *(int *)(iVar3 + 0x18)) {
        ioGlobalStdSet(0,*(int *)(iVar3 + 0x18));
      }
      if (2 < *(int *)(iVar3 + 0xc)) {
        ioGlobalStdSet(1,*(int *)(iVar3 + 0xc));
      }
      if (2 < *(int *)(iVar3 + 0x1c)) {
        ioGlobalStdSet(2,*(int *)(iVar3 + 0x1c));
      }
      *(undefined4 *)(iVar3 + 0x18) = 0xffffffff;
      *(undefined4 *)(iVar3 + 0xc) = 0xffffffff;
      *(undefined4 *)(iVar3 + 0x1c) = 0xffffffff;
      iVar4 = 0x37;
      puVar5 = (undefined4 *)(param_1 + 0x144);
      puVar6 = (undefined4 *)(param_1 + 0x324);
      do {
        iVar4 = iVar4 + -1;
        *puVar5 = *puVar6;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar4 != 0);
      iVar4 = 0x37;
      puVar5 = (undefined4 *)(param_1 + 0x54);
      puVar6 = (undefined4 *)(param_1 + 0x234);
      do {
        iVar4 = iVar4 + -1;
        *puVar5 = *puVar6;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar4 != 0);
      *(undefined4 *)(param_1 + 0x414) = *(undefined4 *)(param_1 + 0x40c);
      *DAT_30111328 = 0;
      *DAT_3011132c = 0;
      goto LAB_3011083c;
    }
  }
  else {
    iVar4 = 0x37;
    puVar5 = (undefined4 *)(param_1 + 0x324);
    puVar6 = (undefined4 *)(param_1 + 0x144);
    do {
      iVar4 = iVar4 + -1;
      *puVar5 = *puVar6;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar4 != 0);
    iVar4 = 0x37;
    puVar5 = (undefined4 *)(param_1 + 0x234);
    puVar6 = (undefined4 *)(param_1 + 0x54);
    do {
      iVar4 = iVar4 + -1;
      *puVar5 = *puVar6;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar4 != 0);
    *(undefined4 *)(param_1 + 0x40c) = *(undefined4 *)(param_1 + 0x414);
    iVar4 = 0x37;
    *(undefined4 *)(param_1 + 0x414) = *DAT_30111320;
    puVar5 = DAT_30111324;
    *(undefined4 *)(param_1 + 0x54) = *DAT_30111324;
    *(undefined4 *)(param_1 + 0x5c) = puVar5[2];
    *(undefined4 *)(param_1 + 0x58) = puVar5[1];
    *(undefined4 *)(param_1 + 0x60) = puVar5[3];
    puVar5 = (undefined4 *)(param_1 + 0x144);
    puVar6 = (undefined4 *)(param_1 + 0x54);
    do {
      iVar4 = iVar4 + -1;
      *puVar5 = *puVar6;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar4 != 0);
    *DAT_30111328 = 1;
    *(undefined4 *)(iVar3 + 0x3c) = 0;
LAB_3011083c:
    *(undefined4 *)(param_1 + iVar1) = 0;
  }
  if (*(int *)(iVar3 + 0x14) == 0) {
    if (*DAT_30110a50 == 0) goto LAB_30110974;
    uVar2 = ioGlobalStdGet(0);
    *(undefined4 *)(param_1 + 0x130) = uVar2;
    uVar2 = ioGlobalStdGet(1);
    *(undefined4 *)(param_1 + 0x134) = uVar2;
    uVar2 = ioGlobalStdGet(2);
    *(undefined4 *)(param_1 + 0x138) = uVar2;
    if (2 < *(int *)(iVar3 + 0x30)) {
      ioGlobalStdSet(0,*(int *)(iVar3 + 0x30));
    }
    if (2 < *(int *)(iVar3 + 0x34)) {
      ioGlobalStdSet(1,*(int *)(iVar3 + 0x34));
    }
    if (2 < *(int *)(iVar3 + 0x38)) {
      ioGlobalStdSet(2,*(int *)(iVar3 + 0x38));
    }
    *DAT_30110a50 = 0;
  }
  else {
    if (2 < *(int *)(iVar3 + 0x24)) {
      ioGlobalStdSet(0,*(int *)(iVar3 + 0x24));
    }
    if (2 < *(int *)(iVar3 + 0x28)) {
      ioGlobalStdSet(1,*(int *)(iVar3 + 0x28));
    }
    if (2 < *(int *)(iVar3 + 0x2c)) {
      ioGlobalStdSet(2,*(int *)(iVar3 + 0x2c));
    }
    *(undefined4 *)(param_1 + 0x130) = 0;
    *(undefined4 *)(param_1 + 0x134) = 1;
    *(undefined4 *)(param_1 + 0x138) = 2;
    *(undefined4 *)(iVar3 + 0x14) = 0;
  }
  *(undefined4 *)(param_1 + iVar1) = 0;
LAB_30110974:
  shellInOutSet(param_1,*(undefined4 *)(param_1 + 0x130),*(undefined4 *)(param_1 + 0x134),
                *(undefined4 *)(param_1 + 0x138));
  iVar3 = isatty(*(int *)(param_1 + 0x220));
  if ((iVar3 != 0) && (*(int *)(param_1 + 0x430) == 0)) {
    ioctl(*(int *)(param_1 + 0x220),0x1a,0);
    ioctl(*(int *)(param_1 + 0x220),3,0x7f);
  }
  shellInOutInputHookSet(param_1);
  if (*(int *)(param_1 + iVar1) != 0) {
    uVar2 = taskName(*(undefined4 *)(param_1 + iVar7));
    shellPrint(param_1,DAT_30111330,uVar2);
  }
  if (*(int *)(param_1 + 0x430) == 0) {
    shellPrint(param_1,DAT_30111334);
  }
  taskDelay(1);
  local_30 = DAT_30111338;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  iVar7 = 1;
  do {
    sigaction(iVar7,(sigaction *)&local_30,(sigaction *)0x0);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x40);
  bVar8 = *(int *)(param_1 + 0x13c) == 0;
  if (!bVar8) {
    if (*(int *)(param_1 + 0x420) == 0) {
      iVar7 = ledOpen(*(undefined4 *)(param_1 + 0x220),*(undefined4 *)(param_1 + 0x224),0);
      *(int *)(param_1 + 0x420) = iVar7;
      if (iVar7 == -1) {
        *(undefined4 *)(param_1 + 0x420) = 0;
        shellPrintErr(0,DAT_3011133c);
        return;
      }
      ledCompletionSet(iVar7,DAT_30111340);
    }
    bVar8 = *(int *)(param_1 + 0x13c) == 0;
  }
  if (bVar8) {
    *(undefined4 *)(param_1 + 0x434) = 1;
  }
  *(undefined4 *)(param_1 + iVar1) = 0;
  shellConfigSet(0,*(undefined4 *)(param_1 + 0x140));
  shellMemFree(*(undefined4 *)(param_1 + 0x140));
  *(undefined4 *)(param_1 + 0x140) = 0;
  shellExec(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30110b1c @ 0x30110B1C  (примерный размер ~156 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: ledDfltComplete, shellFromTaskGet
 * Константы: 0x30110B1C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4
FUN_30110b1c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  iVar1 = shellFromTaskGet(0);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    pcVar3 = *(code **)(*(int *)(*(int *)(iVar1 + 0xc) + 8) + 0x20);
    if (pcVar3 == (code *)0x0) {
      uVar2 = ledDfltComplete(param_1,param_2,param_3,param_4,param_5);
    }
    else {
      uVar2 = (*pcVar3)(*(int *)(iVar1 + 0xc),param_1,param_2,param_3,param_4,param_5);
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellFromTaskParentContextGet @ 0x30110BB8  (примерный размер ~128 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 5
 * Вызывает: lstFirst, lstNext, semGive, semTake, shellFromTaskGet
 * Вызывают: FUN_30110f80, shellOutputLock, shellOutputUnlock
 * Константы: 0x30110BB8, 0xFFFFFFFF
 * Данные: DAT_30111344
 * ---------------------------------------------------------------- */
int shellFromTaskParentContextGet(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = shellFromTaskGet();
  iVar1 = DAT_30111344;
  if (iVar2 == 0) {
    semTake(*(undefined4 *)(DAT_30111344 + 0xc),0xffffffff);
    iVar3 = lstFirst(iVar1);
    while (iVar3 != 0) {
      if (*(int *)(iVar3 + 8) == param_1) {
        if (*(int *)(iVar3 + 0xc) != 0) {
          iVar2 = *(int *)(iVar3 + 0xc);
        }
        break;
      }
      iVar3 = lstNext();
    }
    semGive(*(undefined4 *)(iVar1 + 0xc));
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_30110c38 @ 0x30110C38  (примерный размер ~300 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 10
 * Вызывает: errnoGet, ioTaskStdSet, printErr, shellGenericInit, shellMemFree, shellMemStrdup, shellTerminate, sysClkRateGet, taskDelay, taskIdVerify
 * Константы: 0x30110C38
 * Данные: DAT_30111348, DAT_3011134c
 * ---------------------------------------------------------------- */
undefined4 FUN_30110c38(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  uVar9 = 0;
  ioTaskStdSet(0,0,0);
  ioTaskStdSet(0,1,1);
  ioTaskStdSet(0,2,2);
  if (*(int *)(param_1 + 0x50) != 0) {
    uVar9 = shellMemStrdup(*(int *)(param_1 + 0x50));
  }
  uVar6 = *(undefined4 *)(param_1 + 0x41c);
  uVar2 = shellMemStrdup(*(undefined4 *)(param_1 + 8));
  uVar11 = *(undefined4 *)(param_1 + 0x138);
  uVar7 = *(undefined4 *)(param_1 + 0x4c);
  uVar8 = *(undefined4 *)(param_1 + 0x414);
  uVar5 = *(undefined4 *)(param_1 + 0x130);
  uVar4 = *(undefined4 *)(param_1 + 0x134);
  uVar10 = *(undefined4 *)(param_1 + 0x424);
  shellTerminate(param_1);
  while (iVar3 = taskIdVerify(uVar10), iVar1 = DAT_30111348, iVar3 == 0) {
    sysClkRateGet();
    taskDelay();
  }
  do {
    iVar3 = shellGenericInit(uVar9,uVar6,uVar2,0,uVar7,uVar8,uVar5,uVar4,uVar11);
    if (iVar3 == 0) goto LAB_30110d48;
    iVar3 = errnoGet();
  } while (iVar3 == iVar1);
  printErr(DAT_3011134c);
LAB_30110d48:
  shellMemFree(uVar9);
  shellMemFree(uVar2);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30110d64 @ 0x30110D64  (примерный размер ~172 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 3
 * Вызывает: shellTaskDefaultOptionsGet, taskSpawn, taskSuspend
 * Константы: 0x30110D64, 0xFFFFFFFF
 * Данные: DAT_30111350, DAT_30111354, DAT_30111358, DAT_3011135c
 * ---------------------------------------------------------------- */
undefined4 FUN_30110d64(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = *DAT_30111350;
  uVar4 = *DAT_30111354;
  uVar1 = shellTaskDefaultOptionsGet();
  iVar2 = taskSpawn(DAT_3011135c,uVar3,uVar1,uVar4,DAT_30111358,param_1,0,0,0,0,0,0,0,0,0);
  if (iVar2 == -1) {
    uVar1 = 0xffffffff;
  }
  else {
    taskSuspend(0);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30110e10 @ 0x30110E10  (примерный размер ~368 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 10
 * Вызывает: close, exit, shellFromTaskGet, shellInOutInitialGet, shellPrintErr, shellRestart, taskIdSelf, taskSuspend, taskTcb, trcStack
 * Константы: 0x30110E10
 * Данные: DAT_30111304, DAT_30111360, DAT_30111364, DAT_30111368, DAT_3011136c
 * ---------------------------------------------------------------- */
void FUN_30110e10(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_18;
  
  taskIdSelf();
  iVar1 = shellFromTaskGet();
  iVar3 = DAT_30111304;
  if (iVar1 != 0) {
    iVar5 = 0;
    if (0 < *(int *)(DAT_30111304 + 0x10)) {
      do {
        pcVar2 = *(code **)(*(int *)(iVar3 + 4) + iVar5 * 4);
        if (pcVar2 == (code *)0x0) break;
        (*pcVar2)(iVar1,0);
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(iVar3 + 0x10));
    }
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x430) != 0)) {
      iVar3 = shellInOutInitialGet(iVar1,0,&local_18,0);
      if (iVar3 == 0) {
        close(local_18);
      }
      exit(1);
    }
  }
  if (*DAT_30111360 != 0) {
    taskIdSelf();
    iVar3 = taskTcb();
    (*(code *)*DAT_30111360)(iVar3 + 0x1b4,0,0,0);
  }
  shellPrintErr(0,DAT_30111364);
  iVar3 = *(int *)(param_3 + 100);
  if (iVar3 == 0) {
    shellPrintErr(0,DAT_3011136c,param_1);
  }
  else {
    uVar4 = taskIdSelf();
    trcStack(iVar3,*DAT_30111368,uVar4);
  }
  if (iVar1 != 0) {
    shellRestart(iVar1);
  }
  taskSuspend(0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30110f80 @ 0x30110F80  (примерный размер ~160 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 8
 * Вызывает: __errno, ioTaskStdSet, lstAdd, semGive, semTake, shellFromTaskParentContextGet, shellMemMalloc, taskIdSelf
 * Константы: 0x30110F80, 0xFFFFFFFF
 * Данные: DAT_30111344
 * ---------------------------------------------------------------- */
void FUN_30110f80(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined4 *)__errno();
  uVar4 = *puVar1;
  taskIdSelf();
  iVar2 = shellFromTaskParentContextGet();
  if (iVar2 != 0) {
    ioTaskStdSet(param_1,0,*(undefined4 *)(iVar2 + 0x220));
    ioTaskStdSet(param_1,1,*(undefined4 *)(iVar2 + 0x224));
    ioTaskStdSet(param_1,2,*(undefined4 *)(iVar2 + 0x228));
    iVar3 = shellMemMalloc(0x10);
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 8) = param_1;
      *(int *)(iVar3 + 0xc) = iVar2;
      iVar2 = DAT_30111344;
      semTake(*(undefined4 *)(DAT_30111344 + 0xc),0xffffffff);
      lstAdd(iVar2,iVar3);
      semGive(*(undefined4 *)(iVar2 + 0xc));
    }
  }
  puVar1 = (undefined4 *)__errno();
  *puVar1 = uVar4;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30111020 @ 0x30111020  (примерный размер ~516 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 13
 * Вызывает: __errno, atomic32Dec, ioGlobalStdGet, ioGlobalStdSet, logFdDelete, lstDelete, lstFirst, lstNext, semGive, semTake, shellContextFinalize, shellMemFree, shellNext
 * Константы: 0x30111020, 0xFFFFFFFF
 * Данные: DAT_30111304, DAT_30111314, DAT_3011132c, DAT_30111344, DAT_30111370, DAT_30111374, DAT_30111378, DAT_3011137c
 * ---------------------------------------------------------------- */
void FUN_30111020(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  puVar2 = (undefined4 *)__errno();
  iVar4 = DAT_30111344;
  uVar5 = *puVar2;
  semTake(*(undefined4 *)(DAT_30111344 + 0xc),0xffffffff);
  for (iVar3 = lstFirst(iVar4); iVar3 != 0; iVar3 = lstNext(iVar3)) {
    if (*(int *)(iVar3 + 8) == param_1) {
      lstDelete(iVar4,iVar3);
      shellMemFree(iVar3);
      break;
    }
  }
  semGive(*(undefined4 *)(iVar4 + 0xc));
  iVar4 = lstFirst(DAT_30111370);
  iVar3 = DAT_30111314;
  piVar1 = DAT_30111304;
  do {
    DAT_30111304 = piVar1;
    if (iVar4 == 0) {
LAB_30111214:
      puVar2 = (undefined4 *)__errno();
      *puVar2 = uVar5;
      return;
    }
    if (*(int *)(iVar4 + iVar3) == param_1) {
      if (*(int *)(iVar4 + 0x42c) == 0) {
        if (*DAT_30111374 != -1) {
          atomic32Dec(DAT_30111378);
        }
        piVar1 = DAT_30111304;
        if ((*(int *)(iVar4 + iVar3) == DAT_30111304[2]) && (DAT_30111304[2] = 0, *piVar1 != 0)) {
          if (2 < piVar1[0xc]) {
            ioGlobalStdSet(0,piVar1[0xc]);
          }
          if (*(int *)(iVar4 + 0x13c) != 0) {
            if (2 < piVar1[0xd]) {
              ioGlobalStdSet(1,piVar1[0xd]);
            }
            if (2 < piVar1[0xe]) {
              ioGlobalStdSet(2,piVar1[0xe]);
            }
          }
        }
        if (*(int *)(iVar4 + iVar3) == *DAT_3011137c) {
          *DAT_3011137c = 0;
        }
        iVar6 = *(int *)(iVar4 + 0x134);
        iVar3 = ioGlobalStdGet(1);
        if ((iVar3 != iVar6) && (iVar6 != 1)) {
          logFdDelete(iVar6);
        }
        shellContextFinalize(iVar4);
      }
      else if (((*piVar1 != 0) && (*DAT_3011132c != 0)) &&
              (iVar4 = ioGlobalStdGet(1), iVar4 != piVar1[3])) {
        ioGlobalStdGet(1);
        logFdDelete();
      }
      goto LAB_30111214;
    }
    iVar4 = shellNext(iVar4);
    piVar1 = DAT_30111304;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_30111224 @ 0x30111224  (примерный размер ~176 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 4
 * Вызывает: semGive, semMGiveForce, shellInternalSymTblFromRtpGet, shellWorkingMemCtxCurrentGet
 * Константы: 0x30111224
 * Данные: DAT_30111370, DAT_30111380, DAT_30111384, DAT_30111388
 * ---------------------------------------------------------------- */
void FUN_30111224(int param_1,int param_2)

{
  int iVar1;
  
  if ((*DAT_30111380 == 0) ||
     (iVar1 = shellWorkingMemCtxCurrentGet(param_1), *DAT_30111384 == iVar1)) {
    iVar1 = *DAT_30111388;
  }
  else {
    if (iVar1 == 0) goto LAB_301112a0;
    iVar1 = shellInternalSymTblFromRtpGet(iVar1,0);
  }
  if (iVar1 != 0) {
    if (param_2 == 0) {
      semGive(iVar1 + 0x10);
    }
    else {
      semMGiveForce();
    }
  }
LAB_301112a0:
  if (param_2 == 0) {
    semGive(*(undefined4 *)(DAT_30111370 + 0xc));
    semGive(*(undefined4 *)(param_1 + 0x410));
  }
  else {
    semMGiveForce();
    semMGiveForce(*(undefined4 *)(param_1 + 0x410));
  }
  return;
}

/* ----------------------------------------------------------------
 * shellAbortHandledByShell @ 0x301112D4  (примерный размер ~28 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 1
 * Вызывает: tyAbortFuncGet
 * Вызывают: FUN_30103738
 * Константы: 0x301112D4
 * Данные: DAT_3011138c
 * ---------------------------------------------------------------- */
bool shellAbortHandledByShell(void)

{
  int iVar1;
  
  iVar1 = tyAbortFuncGet();
  return iVar1 == DAT_3011138c;
}

/* ----------------------------------------------------------------
 * shellMaxSessionsSet @ 0x301112F0  (примерный размер ~160 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3003ffc8
 * Константы: 0x301112F0
 * Данные: DAT_30111374
 * ---------------------------------------------------------------- */
void shellMaxSessionsSet(int param_1)

{
  if (param_1 < 0) {
    return;
  }
  *DAT_30111374 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * shellMemLibInit @ 0x30111390  (примерный размер ~160 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 5
 * Вызывает: free, malloc, memPartCreate, memPartOptionsGet, memPartOptionsSet
 * Вызывают: FUN_301007f0, shellLibInit, shellPromptFmtStrAdd
 * Константы: 0xFFFFFFFF, 0x30111390, 0xFFFFF9DF
 * Данные: DAT_30111bf8
 * ---------------------------------------------------------------- */
undefined4 shellMemLibInit(void)

{
  int *piVar1;
  void *__ptr;
  int iVar2;
  uint local_10;
  
  piVar1 = DAT_30111bf8;
  if (DAT_30111bf8[1] == 0) {
    __ptr = malloc(0x3000);
    if (__ptr == (void *)0x0) {
      return 0xffffffff;
    }
    iVar2 = memPartCreate(__ptr,0x3000);
    *piVar1 = iVar2;
    if (iVar2 == 0) {
      free(__ptr);
      return 0xffffffff;
    }
    iVar2 = memPartOptionsGet(iVar2,&local_10);
    if (iVar2 == 0) {
      memPartOptionsSet(*piVar1,local_10 & 0xfffff9df);
    }
    piVar1[1] = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30111430 @ 0x30111430  (примерный размер ~108 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 3
 * Вызывает: free, malloc, memPartAddToPool
 * Вызывают: shellMemMalloc, shellMemRealloc
 * Константы: 0xFFFFFFFF, 0x30111430
 * Данные: DAT_30111bf8
 * ---------------------------------------------------------------- */
undefined4 FUN_30111430(size_t param_1)

{
  void *__ptr;
  int iVar1;
  
  iVar1 = *DAT_30111bf8;
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  __ptr = malloc(param_1);
  if (__ptr == (void *)0x0) {
    return 0xffffffff;
  }
  iVar1 = memPartAddToPool(iVar1,__ptr,param_1);
  if (iVar1 == -1) {
    free(__ptr);
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellMemMalloc @ 0x3011149C  (примерный размер ~108 байт)
 * Модуль: shell | Вызывают: 25 | Вызывает: 2
 * Вызывает: FUN_30111430, memPartAlloc
 * Вызывают: FUN_30100868, FUN_30100920, FUN_30100c70, FUN_30100e2c, FUN_30101f90, FUN_30103f38, FUN_30106d84, FUN_3010c16c, FUN_30110184, FUN_30110f80
 *           ...
 * Константы: 0x3011149C
 * Данные: DAT_30111bf8
 * ---------------------------------------------------------------- */
int shellMemMalloc(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_30111bf8;
  if (*DAT_30111bf8 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = memPartAlloc(*DAT_30111bf8,param_1);
    if ((iVar2 == 0) && (iVar3 = FUN_30111430(0x1800), iVar3 == 0)) {
      iVar2 = memPartAlloc(*piVar1,param_1);
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * shellMemCalloc @ 0x30111508  (примерный размер ~48 байт)
 * Модуль: shell | Вызывают: 8 | Вызывает: 2
 * Вызывает: bzero, shellMemMalloc
 * Вызывают: FUN_30105988, FUN_3010be78, FUN_301124fc, shellContextInit, shellInternalArgStackAllocate, shellInternalOptGet, shellInterpCtxCreate, shellInterpRegister
 * Константы: 0x30111508
 * ---------------------------------------------------------------- */
void * shellMemCalloc(int param_1,int param_2)

{
  void *__s;
  
  __s = (void *)shellMemMalloc(param_2 * param_1);
  if (__s != (void *)0x0) {
    bzero(__s,param_2 * param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * shellMemRealloc @ 0x30111538  (примерный размер ~140 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_30111430, memPartRealloc, shellMemMalloc
 * Вызывают: FUN_3010661c, shellInternalSymbolsResolve
 * Константы: 0x30111538
 * Данные: DAT_30111bf8
 * ---------------------------------------------------------------- */
int shellMemRealloc(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_30111bf8;
  if (param_1 == 0) {
    iVar2 = shellMemMalloc(param_2);
  }
  else if (*DAT_30111bf8 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = memPartRealloc(*DAT_30111bf8,param_1,param_2);
    if ((iVar2 == 0) && (iVar3 = FUN_30111430(0x1800), iVar3 == 0)) {
      iVar2 = memPartRealloc(*piVar1,param_1,param_2);
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * shellMemFree @ 0x301115C4  (примерный размер ~36 байт)
 * Модуль: shell | Вызывают: 46 | Вызывает: 1
 * Вызывает: memPartFree
 * Вызывают: FUN_30100868, FUN_30100920, FUN_301009f4, FUN_30100c70, FUN_30101228, FUN_301015b8, FUN_30101f90, FUN_30103da4, FUN_30103f38, FUN_30105988
 *           ...
 * Константы: 0x301115C4
 * Данные: DAT_30111bf8
 * ---------------------------------------------------------------- */
void shellMemFree(undefined4 param_1)

{
  if (*DAT_30111bf8 != 0) {
    memPartFree(*DAT_30111bf8,param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_301115e8 @ 0x301115E8  (примерный размер ~56 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 2
 * Вызывает: lstFirst, lstNext
 * Вызывают: shellMemRegister, shellMemUnregister
 * Константы: 0x301115E8
 * ---------------------------------------------------------------- */
int FUN_301115e8(int param_1,undefined4 param_2)

{
  int iVar1;
  
  for (iVar1 = lstFirst(param_2); (iVar1 != 0 && (*(int *)(iVar1 + 8) != param_1));
      iVar1 = lstNext(iVar1)) {
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellMemRegister @ 0x30111620  (примерный размер ~120 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_301115e8, lstAdd, shellMemMalloc
 * Вызывают: shellBackgroundRead, shellMemRegMalloc
 * Константы: 0xFFFFFFFF, 0x30111620
 * ---------------------------------------------------------------- */
undefined4 shellMemRegister(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_301115e8(param_1,param_4);
  if (iVar1 != 0) {
    if (param_3 == 0) {
      return 0xffffffff;
    }
    if (iVar1 != 0) goto LAB_3011168c;
  }
  iVar1 = shellMemMalloc(0x10);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(iVar1 + 8) = param_1;
  lstAdd(param_4,iVar1);
LAB_3011168c:
  *(undefined4 *)(iVar1 + 0xc) = param_2;
  return 0;
}

/* ----------------------------------------------------------------
 * shellMemRegMalloc @ 0x30111698  (примерный размер ~72 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: shellMemMalloc, shellMemRegister
 * Вызывают: FUN_30106ce8
 * Константы: 0x30111698
 * ---------------------------------------------------------------- */
int shellMemRegMalloc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = shellMemMalloc();
  if ((iVar1 != 0) && (iVar2 = shellMemRegister(iVar1,param_2,1,param_3), iVar2 == 0)) {
    return iVar1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellMemUnregister @ 0x301116E0  (примерный размер ~80 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 3
 * Вызывает: FUN_301115e8, lstDelete, memPartFree
 * Вызывают: shellBackgroundRead, shellMemAllRegFree, shellMemRegFree
 * Константы: 0x301116E0, 0xFFFFFFFF
 * Данные: DAT_30111bf8
 * ---------------------------------------------------------------- */
undefined4 shellMemUnregister(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_301115e8();
  if (iVar1 != 0) {
    lstDelete(param_2,iVar1);
    if (*DAT_30111bf8 != 0) {
      memPartFree(*DAT_30111bf8,iVar1);
    }
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellMemRegFree @ 0x30111730  (примерный размер ~72 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: memPartFree, shellMemUnregister
 * Константы: 0x30111730
 * Данные: DAT_30111bf8
 * ---------------------------------------------------------------- */
void shellMemRegFree(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  iVar1 = shellMemUnregister(param_1,param_2);
  if (iVar1 != 0) {
    return;
  }
  if (*DAT_30111bf8 == 0) {
    return;
  }
  memPartFree(*DAT_30111bf8,param_1);
  return;
}

/* ----------------------------------------------------------------
 * shellMemAllRegFree @ 0x30111778  (примерный размер ~136 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 3
 * Вызывает: lstFirst, lstNext, shellMemUnregister
 * Вызывают: FUN_3010bec0, FUN_3010c16c, shellMemRegAllFree
 * Константы: 0x30111778
 * ---------------------------------------------------------------- */
void shellMemAllRegFree(uint param_1,uint param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = lstFirst(param_4);
  if (iVar1 != 0) {
    do {
      iVar2 = lstNext(iVar1);
      if ((param_2 & *(uint *)(iVar1 + 0xc)) == (param_1 & param_2)) {
        uVar3 = *(undefined4 *)(iVar1 + 8);
        shellMemUnregister(uVar3,param_4);
        if (param_3 != (code *)0x0) {
          (*param_3)(uVar3);
        }
      }
      iVar1 = iVar2;
    } while (iVar2 != 0);
  }
  return;
}

/* ----------------------------------------------------------------
 * shellMemRegAllFree @ 0x30111800  (примерный размер ~12 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: shellMemAllRegFree
 * Константы: 0x30111800
 * Данные: DAT_30111bfc
 * ---------------------------------------------------------------- */
void shellMemRegAllFree(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  shellMemAllRegFree(param_1,param_2,DAT_30111bfc,param_3);
  return;
}

/* ----------------------------------------------------------------
 * shellMemStringAdd @ 0x3011180C  (примерный размер ~224 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 9
 * Вызывает: __errno, lstAdd, lstInit, malloc, shellDataAdd, shellDataGet, shellMemMalloc, strcpy, strlen
 * Константы: 0x3011180C
 * Данные: DAT_30111c00, DAT_30111c04, DAT_30111c08
 * ---------------------------------------------------------------- */
undefined4 shellMemStringAdd(undefined4 param_1,char *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  void *pvVar5;
  undefined4 uVar6;
  int local_18;
  
  puVar1 = (undefined4 *)__errno();
  uVar6 = *puVar1;
  iVar2 = shellDataGet(param_1,DAT_30111c00,&local_18);
  if (iVar2 != 0) {
    piVar3 = (int *)__errno();
    if (*piVar3 != DAT_30111c04) {
      return 0;
    }
    puVar1 = (undefined4 *)__errno(*piVar3);
    *puVar1 = uVar6;
    local_18 = shellMemMalloc(0xc);
    if (((local_18 == 0) || (lstInit(), local_18 == 0)) ||
       (iVar2 = shellDataAdd(param_1,DAT_30111c00,local_18,DAT_30111c08), iVar2 != 0)) {
      return 0;
    }
  }
  sVar4 = strlen(param_2);
  pvVar5 = malloc(sVar4 + 0xd);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    *(char **)((int)pvVar5 + 8) = (char *)((int)pvVar5 + 0xc);
    strcpy((char *)((int)pvVar5 + 0xc),param_2);
    lstAdd(local_18,pvVar5);
    uVar6 = *(undefined4 *)((int)pvVar5 + 8);
  }
  return uVar6;
}

/* ----------------------------------------------------------------
 * FUN_301118ec @ 0x301118EC  (примерный размер ~112 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 3
 * Вызывает: lstFirst, lstNext, shellDataGet
 * Вызывают: shellMemStringFree, shellMemStringIsAllocated
 * Константы: 0x301118EC
 * Данные: DAT_30111c00
 * ---------------------------------------------------------------- */
int FUN_301118ec(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 local_10;
  
  iVar1 = shellDataGet(param_1,DAT_30111c00,&local_10);
  if (iVar1 == 0) {
    for (iVar1 = lstFirst(local_10);
        ((iVar1 != 0 && (param_2 != -1)) && (*(int *)(iVar1 + 8) != param_2));
        iVar1 = lstNext(iVar1)) {
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellMemStringIsAllocated @ 0x3011195C  (примерный размер ~24 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_301118ec
 * Константы: 0x3011195C
 * ---------------------------------------------------------------- */
bool shellMemStringIsAllocated(void)

{
  int iVar1;
  
  iVar1 = FUN_301118ec();
  return iVar1 != 0;
}

/* ----------------------------------------------------------------
 * shellMemStringFree @ 0x30111974  (примерный размер ~196 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_301118ec, free, lstDelete, shellDataGet, shellFirst, shellNext
 * Вызывают: dbgDynPrintfCommonRtn, strFree
 * Константы: 0xFFFFFFFF, 0x30111974
 * Данные: DAT_30111c00
 * ---------------------------------------------------------------- */
undefined4 shellMemStringFree(int param_1,int param_2)

{
  int iVar1;
  void *__ptr;
  undefined4 local_14;
  
  if (param_2 != 0) {
    if (param_1 == -1) {
      for (iVar1 = shellFirst(); iVar1 != 0; iVar1 = shellNext(iVar1)) {
        shellMemStringFree(iVar1,param_2);
      }
    }
    else {
      iVar1 = shellDataGet(param_1,DAT_30111c00,&local_14);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      __ptr = (void *)FUN_301118ec(param_1,param_2);
      if (__ptr == (void *)0x0) {
        return 0xffffffff;
      }
      do {
        lstDelete(local_14,__ptr);
        free(__ptr);
        __ptr = (void *)FUN_301118ec(param_1,param_2);
      } while (__ptr != (void *)0x0);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellMemStringShow @ 0x30111A38  (примерный размер ~340 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 12
 * Вызывает: lstCount, lstFirst, lstNext, shellDataGet, shellFirst, shellFromTaskGet, shellNext, shellPrint, shellTaskGet, strlen, strncpy, taskName
 * Вызывают: strFree
 * Константы: 0x30111A38
 * Данные: DAT_30111c00, DAT_30111c0c, DAT_30111c10, DAT_30111c14, DAT_30111c18, DAT_30111c1c, DAT_30111c20
 * ---------------------------------------------------------------- */
void shellMemStringShow(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  undefined4 local_44;
  char acStack_40 [39];
  undefined1 local_19;
  
  bVar1 = false;
  if (param_1 == -1) {
    bVar1 = true;
    param_1 = shellFirst();
  }
  else {
    if (param_1 != 0) goto LAB_30111a78;
    param_1 = shellFromTaskGet(0);
  }
  if (param_1 == 0) {
    return;
  }
LAB_30111a78:
  do {
    iVar2 = shellDataGet(param_1,DAT_30111c00,&local_44);
    if ((iVar2 == 0) && (iVar2 = lstCount(local_44), iVar2 != 0)) {
      shellTaskGet(param_1);
      uVar3 = taskName();
      shellPrint(0,DAT_30111c14,param_1,uVar3);
      for (iVar2 = lstFirst(local_44); iVar2 != 0; iVar2 = lstNext(iVar2)) {
        strncpy(acStack_40,*(char **)(iVar2 + 8),0x27);
        local_19 = 0;
        shellPrint(0,DAT_30111c18,*(undefined4 *)(iVar2 + 8),acStack_40);
        sVar4 = strlen(*(char **)(iVar2 + 8));
        uVar3 = DAT_30111c1c;
        if (sVar4 < 0x28) {
          uVar3 = DAT_30111c20;
        }
        shellPrint(0,uVar3);
      }
    }
    else {
      iVar2 = shellFromTaskGet(0);
      if (iVar2 == param_1) {
        shellPrint(0,DAT_30111c0c);
      }
      else {
        shellPrint(0,DAT_30111c10,param_1);
      }
    }
    if (bVar1) {
      param_1 = shellNext(param_1);
    }
    else {
      param_1 = 0;
    }
  } while (param_1 != 0);
  return;
}

/* ----------------------------------------------------------------
 * shellMemStrdup @ 0x30111B8C  (примерный размер ~60 байт)
 * Модуль: shell | Вызывают: 15 | Вызывает: 3
 * Вызывает: shellMemMalloc, strcpy, strlen
 * Вызывают: FUN_301009f4, FUN_30105988, FUN_30110c38, shellBackgroundInit, shellContextInit, shellInternalArgumentEval, shellInternalOptGet, shellInternalSymbolsResolve, shellInterpCtxCreate, shellInterpEvaluate
 *           ...
 * Константы: 0x30111B8C
 * ---------------------------------------------------------------- */
char * shellMemStrdup(char *param_1)

{
  size_t sVar1;
  char *__dest;
  
  sVar1 = strlen(param_1);
  __dest = (char *)shellMemMalloc(sVar1 + 1);
  if (__dest == (char *)0x0) {
    return (char *)0x0;
  }
  strcpy(__dest,param_1);
  return __dest;
}

/* ----------------------------------------------------------------
 * FUN_30111bc8 @ 0x30111BC8  (примерный размер ~96 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: lstFree2, memPartFree
 * Константы: 0x30111BC8
 * Данные: DAT_30111bf8, DAT_30111c24
 * ---------------------------------------------------------------- */
void FUN_30111bc8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  lstFree2(param_3,DAT_30111c24);
  if (*DAT_30111bf8 == 0) {
    return;
  }
  memPartFree(*DAT_30111bf8,param_3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30111c28 @ 0x30111C28  (примерный размер ~164 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 4
 * Вызывает: dllInit, semMCreate, shellPrintErr, shellResourceReleaseHookAdd
 * Вызывают: shellPromptFmtStrAdd, shellPromptLibInit
 * Константы: 0xFFFFFFFF, 0x30111C28
 * Данные: DAT_3011212c, DAT_30112130, DAT_30112134, DAT_30112138, DAT_3011213c, DAT_30112140
 * ---------------------------------------------------------------- */
undefined4 FUN_30111c28(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_30112130;
  piVar1 = DAT_3011212c;
  if (*DAT_3011212c == 0) {
    iVar2 = dllInit(DAT_30112130);
    if (iVar2 != 0) {
      shellPrintErr(0,DAT_30112134);
      return 0xffffffff;
    }
    iVar2 = semMCreate(0);
    *(int *)(iVar3 + 8) = iVar2;
    if (iVar2 == 0) {
      shellPrintErr(0,DAT_30112138);
      return 0xffffffff;
    }
    iVar3 = shellResourceReleaseHookAdd(DAT_3011213c);
    if (iVar3 != 0) {
      shellPrintErr(0,DAT_30112140);
      return 0xffffffff;
    }
    *piVar1 = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellPromptFmtStrAdd @ 0x30111CCC  (примерный размер ~184 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_30111c28, dllAdd, semGive, semTake, shellMemLibInit, shellMemMalloc
 * Вызывают: shellPromptLibInit
 * Константы: 0xFFFFFFFF, 0x30111CCC
 * Данные: DAT_30112130
 * ---------------------------------------------------------------- */
undefined4 shellPromptFmtStrAdd(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  
  FUN_30111c28();
  shellMemLibInit();
  piVar1 = DAT_30112130;
  semTake(DAT_30112130[2],0xffffffff);
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    do {
      if (piVar2[3] == param_1) break;
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    if (piVar2 != (int *)0x0) {
      if (param_3 == 0) {
        semGive(piVar1[2]);
        return 0xffffffff;
      }
      goto LAB_30111d70;
    }
  }
  piVar2 = (int *)shellMemMalloc(0x10);
  if (piVar2 == (int *)0x0) {
    semGive(piVar1[2]);
    return 0xffffffff;
  }
  piVar2[3] = param_1;
  dllAdd(piVar1,piVar2);
LAB_30111d70:
  semGive(piVar1[2]);
  piVar2[2] = param_2;
  return 0;
}

/* ----------------------------------------------------------------
 * shellPromptLibInit @ 0x30111D84  (примерный размер ~128 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_30111c28, shellPrintErr, shellPromptFmtStrAdd
 * Вызывают: shellLibInit
 * Константы: 0xFFFFFFFF, 0x30111D84
 * Данные: DAT_30112144, DAT_30112148, DAT_3011214c, DAT_30112150, DAT_30112154, DAT_30112158
 * ---------------------------------------------------------------- */
undefined4 shellPromptLibInit(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_30111c28();
  if (iVar1 == 0) {
    shellPromptFmtStrAdd(0x2f,DAT_30112144,0);
    shellPromptFmtStrAdd(0x68,DAT_30112148,0);
    shellPromptFmtStrAdd(0x6d,DAT_3011214c,0);
    shellPromptFmtStrAdd(0x25,DAT_30112150,0);
    iVar1 = shellPromptFmtStrAdd(0x6e,DAT_30112154,0);
    uVar2 = 0;
    if (iVar1 != 0) {
      shellPrintErr(0,DAT_30112158);
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellPromptGet @ 0x30111E04  (примерный размер ~52 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: shellFromTaskGet, shellInterpPromptGet
 * Константы: 0x30111E04
 * ---------------------------------------------------------------- */
undefined4 shellPromptGet(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = shellInterpPromptGet(*(undefined4 *)(param_1 + 0xc));
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30111e38 @ 0x30111E38  (примерный размер ~88 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Вызывают: shellPromptPrint
 * Константы: 0x30111E38, 0xFFFFFFFF
 * Данные: DAT_30112130
 * ---------------------------------------------------------------- */
undefined4 FUN_30111e38(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_30112130;
  semTake(DAT_30112130[2],0xffffffff);
  for (puVar2 = (undefined4 *)*puVar1; (puVar2 != (undefined4 *)0x0 && (puVar2[3] != param_1));
      puVar2 = (undefined4 *)*puVar2) {
  }
  semGive(puVar1[2]);
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  return puVar2[2];
}

/* ----------------------------------------------------------------
 * shellPromptPrint @ 0x30111E90  (примерный размер ~336 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 12
 * Вызывает: FUN_30111e38, shellFromTaskGet, shellIdVerify, shellInOutUse, shellInterpPromptGet, shellMemFree, shellMemStrdup, shellPrint, strchr, strlen, taskIdSelf, taskTcb
 * Вызывают: FUN_3010c4f0, FUN_30110224, shellCompletionPathnameGet
 * Константы: 0x30111E90
 * Данные: DAT_3011215c
 * ---------------------------------------------------------------- */
void shellPromptPrint(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  char *pcVar5;
  int iVar6;
  size_t sVar7;
  char *__s;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar2 = shellIdVerify(param_1);
  if (iVar2 == 0) {
    taskIdSelf();
    iVar2 = taskTcb();
    if (iVar2 != 0) {
      uVar8 = *(undefined4 *)(iVar2 + 0x100);
      uVar9 = *(undefined4 *)(iVar2 + 0x104);
      uVar10 = *(undefined4 *)(iVar2 + 0x108);
      shellInterpPromptGet(*(undefined4 *)(param_1 + 0xc));
      pcVar3 = (char *)shellMemStrdup();
      if (pcVar3 != (char *)0x0) {
        shellInOutUse(param_1);
        cVar1 = *pcVar3;
        __s = pcVar3;
        while (cVar1 != '\0') {
          if (*__s == '%') {
            pcVar4 = (code *)FUN_30111e38(__s[1]);
            if (pcVar4 != (code *)0x0) {
              (*pcVar4)(param_1);
            }
            __s = __s + 2;
          }
          else {
            pcVar5 = strchr(__s,0x25);
            if (pcVar5 != (char *)0x0) {
              *pcVar5 = '\0';
            }
            iVar6 = shellPrint(0,DAT_3011215c,__s);
            if (iVar6 < 0) break;
            sVar7 = strlen(__s);
            __s = __s + sVar7;
            if (pcVar5 != (char *)0x0) {
              *pcVar5 = '%';
            }
          }
          cVar1 = *__s;
        }
        shellMemFree(pcVar3);
        *(undefined4 *)(iVar2 + 0x100) = uVar8;
        *(undefined4 *)(iVar2 + 0x104) = uVar9;
        *(undefined4 *)(iVar2 + 0x108) = uVar10;
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * shellPromptFmtSet @ 0x30111FE0  (примерный размер ~4 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 9
 * Вызывает: __errno, lstFirst, lstNext, shellFromTaskGet, shellIdVerify, shellInterpNameGet, shellMemFree, shellMemStrdup, strcmp
 * Вызывают: shellPromptSet
 * Константы: 0xFFFFFFFF, 0x30111FE0
 * Данные: DAT_3010d740, DAT_3010d76c
 * ---------------------------------------------------------------- */
undefined4 shellPromptFmtSet(int param_1,char *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = shellIdVerify();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_3010d76c;
    return 0xffffffff;
  }
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  if ((param_2 == (char *)0x0) &&
     (param_2 = (char *)shellInterpNameGet(param_1), param_2 == (char *)0x0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_3010d740;
    return 0xffffffff;
  }
  iVar1 = lstFirst(param_1 + 0x28);
  if (iVar1 != 0) {
    do {
      iVar3 = strcmp(*(char **)(*(int *)(iVar1 + 8) + 8),param_2);
      if (iVar3 == 0) break;
      iVar1 = lstNext(iVar1);
    } while (iVar1 != 0);
    if (iVar1 != 0) {
      if (param_3 == 0) {
        param_3 = *(int *)(*(int *)(iVar1 + 8) + 0x28);
        if (param_3 == 0) {
          param_3 = *(int *)(*(int *)(iVar1 + 8) + 0x24);
        }
        if (param_3 == 0) {
          puVar2 = (undefined4 *)__errno();
          *puVar2 = DAT_3010d740;
          return 0xffffffff;
        }
      }
      iVar3 = shellMemStrdup(param_3);
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      shellMemFree(*(undefined4 *)(iVar1 + 0x10));
      *(int *)(iVar1 + 0x10) = iVar3;
      return 0;
    }
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = DAT_3010d740;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellPromptFmtDftSet @ 0x30111FE4  (примерный размер ~460 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_3010ce4c, __errno, shellMemFree, shellMemStrdup
 * Вызывают: shellPromptSet
 * Константы: 0xFFFFFFFF, 0x30111FE4
 * Данные: DAT_3010d740
 * ---------------------------------------------------------------- */
undefined4 shellPromptFmtDftSet(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = FUN_3010ce4c(param_1,0);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_3010d740;
    return 0xffffffff;
  }
  if (param_2 == 0) {
    param_2 = *(int *)(iVar1 + 0x24);
  }
  iVar3 = shellMemStrdup(param_2);
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  shellMemFree(*(undefined4 *)(iVar1 + 0x28));
  *(int *)(iVar1 + 0x28) = iVar3;
  return 0;
}

/* ----------------------------------------------------------------
 * shellParserControl @ 0x301121B0  (примерный размер ~532 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 15
 * Вызывает: fdprintf, free, ioctl, isatty, malloc, shellDataFirst, shellDataFromNameAdd, shellDataNext, shellDataRemove, shellLock, shellLogoutInstall, shellSecureInit, shellTerminate, sprintf
 *           ...
 * Константы: 0x301121B0, 0xFFFFFFFF
 * Данные: DAT_301123a4, DAT_301123a8, DAT_301123ac, DAT_301123b0, DAT_301123b4, DAT_301123b8, DAT_301123bc, DAT_301123c0
 * ---------------------------------------------------------------- */
undefined4 shellParserControl(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int *__ptr;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int *local_11c;
  undefined4 local_118;
  char acStack_114 [256];
  
  if (param_1 == 2) {
    uVar1 = 0;
  }
  else {
    if (param_1 == 0) {
      iVar2 = 0x100;
      pcVar3 = acStack_114;
      pcVar4 = DAT_301123a4;
      do {
        iVar2 = iVar2 + -1;
        *pcVar3 = *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (iVar2 != 0);
      iVar2 = shellLock(1);
      if (iVar2 == 0) {
        fdprintf(param_3,DAT_301123a8);
        taskDelay(1);
      }
      else {
        __ptr = (int *)malloc(0x110);
        if (__ptr == (int *)0x0) {
          shellLock(0);
        }
        else {
          *__ptr = param_2;
          sprintf(acStack_114,DAT_301123ac,DAT_301123b0,param_2);
          __ptr[2] = 0;
          __ptr[3] = param_3;
          __ptr[1] = param_4;
          iVar2 = isatty(param_3);
          if (iVar2 != 0) {
            ioctl(param_3,2,0);
          }
          shellLogoutInstall(DAT_301123b4,__ptr);
          iVar2 = shellSecureInit(*DAT_301123b8,0,acStack_114,&local_118,param_3,param_3,param_3);
          if (iVar2 == 0) {
            shellDataFromNameAdd(local_118,DAT_301123bc,__ptr,DAT_301123c0);
            return 0;
          }
          free(__ptr);
          shellLock(0);
        }
      }
    }
    else if (param_1 == 1) {
      local_11c = (int *)0x0;
      iVar2 = shellDataFirst(DAT_301123bc,&local_11c);
      if (iVar2 != 0) {
        do {
          if ((local_11c == (int *)0x0) || (*local_11c == param_2)) break;
          iVar2 = shellDataNext(DAT_301123bc,iVar2,&local_11c);
        } while (iVar2 != 0);
        if ((iVar2 != 0) && (local_11c != (int *)0x0)) {
          shellDataRemove(iVar2,DAT_301123bc,1);
          shellTerminate(iVar2);
          shellLock(0);
          return 0;
        }
      }
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_301123c4 @ 0x301123C4  (примерный размер ~56 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 1
 * Вызывает: shellMemMalloc
 * Вызывают: FUN_301123fc, shellWorkingMemCtxDuplicate
 * Константы: 0x301123C4
 * ---------------------------------------------------------------- */
int FUN_301123c4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = shellMemMalloc(0x14);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0xc) = param_1;
  *(undefined4 *)(iVar1 + 0x10) = param_2;
  *(undefined4 *)(iVar1 + 8) = param_3;
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_301123fc @ 0x301123FC  (примерный размер ~256 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 8
 * Вызывает: FUN_301123c4, FUN_301125c4, lstAdd, lstFirst, lstInsert, lstNext, semGive, semTake
 * Вызывают: FUN_301124fc, shellWorkingMemCtxAttach
 * Константы: 0xFFFFFFFF, 0x301123FC
 * Данные: DAT_30112e80
 * ---------------------------------------------------------------- */
undefined4 FUN_301123fc(undefined4 param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = FUN_301125c4();
  if ((iVar1 == 0) || (iVar2 = semTake(*(undefined4 *)(iVar1 + 0xc),0xffffffff), iVar2 != 0)) {
    return 0xffffffff;
  }
  for (iVar2 = lstFirst(iVar1); iVar2 != 0; iVar2 = lstNext(iVar2)) {
    iVar3 = *(int *)(iVar2 + 8);
    if (*(int *)(iVar2 + 0xc) == param_2) {
      semGive(*(undefined4 *)(iVar1 + 0xc));
      return 0xffffffff;
    }
  }
  iVar2 = 0;
  if (*DAT_30112e80 != param_2) {
    iVar2 = iVar3 + 1;
  }
  iVar3 = FUN_301123c4(param_2,param_3,iVar2);
  if (iVar3 == 0) {
    semGive(*(undefined4 *)(iVar1 + 0xc));
    return 0xffffffff;
  }
  if (*DAT_30112e80 == param_2) {
    lstInsert(iVar1,0,iVar3);
  }
  else {
    lstAdd(iVar1,iVar3);
  }
  if (param_4 != (int *)0x0) {
    *param_4 = iVar2;
  }
  semGive(*(undefined4 *)(iVar1 + 0xc));
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_301124fc @ 0x301124FC  (примерный размер ~200 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_301123fc, lstInit, semDelete, semMCreate, shellDataAdd, shellMemCalloc, shellMemFree
 * Вызывают: FUN_301125c4
 * Константы: 0xFFFFFFFF, 0x301124FC
 * Данные: DAT_30112e80, DAT_30112e84, DAT_30112e88
 * ---------------------------------------------------------------- */
undefined4 FUN_301124fc(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = shellMemCalloc(1,0x1c);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  lstInit(iVar2);
  puVar1 = DAT_30112e80;
  *(undefined4 *)(iVar2 + 0x10) = *DAT_30112e80;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  iVar3 = semMCreate(1);
  *(int *)(iVar2 + 0xc) = iVar3;
  if (iVar3 == 0) {
    shellMemFree(iVar2);
    return 0xffffffff;
  }
  iVar3 = shellDataAdd(param_1,DAT_30112e84,iVar2,DAT_30112e88);
  if (iVar3 != 0) {
    semDelete(*(undefined4 *)(iVar2 + 0xc));
    shellMemFree(iVar2);
    return 0xffffffff;
  }
  iVar2 = FUN_301123fc(param_1,*puVar1,1,0);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_301125c4 @ 0x301125C4  (примерный размер ~176 байт)
 * Модуль: shell | Вызывают: 12 | Вызывает: 5
 * Вызывает: FUN_301124fc, __errno, shellDataGet, shellFromTaskGet, shellIdVerify
 * Вызывают: FUN_301123fc, FUN_3011269c, FUN_30112964, shellWorkingMemCtxAttachedShow, shellWorkingMemCtxCurrentGet, shellWorkingMemCtxCurrentSet, shellWorkingMemCtxDetach, shellWorkingMemCtxDuplicate, shellWorkingMemCtxGet, shellWorkingMemCtxIdConvert
 *           ...
 * Константы: 0x301125C4
 * Данные: DAT_30112e84, DAT_30112e8c
 * ---------------------------------------------------------------- */
int FUN_301125c4(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  bool bVar5;
  int iStack_14;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    return 0;
  }
  puVar2 = (undefined4 *)__errno(0);
  uVar4 = *puVar2;
  iVar1 = shellDataGet(param_1,DAT_30112e84,&iStack_14);
  bVar5 = iVar1 == 0;
  if (!bVar5) {
    piVar3 = (int *)__errno();
    if (*piVar3 != DAT_30112e8c) {
      return 0;
    }
    puVar2 = (undefined4 *)__errno(*piVar3);
    *puVar2 = uVar4;
    iVar1 = FUN_301124fc(param_1);
    if (iVar1 != 0) {
      return 0;
    }
    iVar1 = shellDataGet(param_1,DAT_30112e84,&iStack_14);
    bVar5 = iVar1 == 0;
    if (!bVar5) {
      iVar1 = 0;
    }
  }
  if (bVar5) {
    iVar1 = iStack_14;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellWorkingMemCtxRtnSet @ 0x30112674  (примерный размер ~40 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_301125c4
 * Константы: 0x30112674, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellWorkingMemCtxRtnSet(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_301125c4();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(iVar1 + 0x18) = param_2;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3011269c @ 0x3011269C  (примерный размер ~112 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 5
 * Вызывает: FUN_301125c4, lstFirst, lstNext, semGive, semTake
 * Вызывают: shellWorkingMemCtxAttach, shellWorkingMemCtxGet
 * Константы: 0x3011269C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int FUN_3011269c(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_301125c4();
  if ((iVar1 != 0) && (iVar2 = semTake(*(undefined4 *)(iVar1 + 0xc),0xffffffff), iVar2 == 0)) {
    for (iVar2 = lstFirst(iVar1); (iVar2 != 0 && (*(int *)(iVar2 + 0xc) != param_2));
        iVar2 = lstNext(iVar2)) {
    }
    semGive(*(undefined4 *)(iVar1 + 0xc));
    return iVar2;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellWorkingMemCtxGet @ 0x3011270C  (примерный размер ~172 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_301125c4, FUN_3011269c
 * Вызывают: shellWorkingMemCtxAttachedShow
 * Константы: 0xFFFFFFFF, 0x3011270C
 * ---------------------------------------------------------------- */
undefined4
shellWorkingMemCtxGet
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  
  iVar1 = FUN_301125c4();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar3 = FUN_3011269c(param_1,param_2);
    if (iVar3 == 0) {
      uVar2 = 0xffffffff;
    }
    else if ((param_3 == 0) ||
            (((*(undefined4 **)(iVar1 + 0x18) != (undefined4 *)0x0 &&
              (pcVar4 = (code *)**(undefined4 **)(iVar1 + 0x18), pcVar4 != (code *)0x0)) &&
             (iVar1 = (*pcVar4)(param_2,param_3,param_4), iVar1 == 0)))) {
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = *(undefined4 *)(iVar3 + 0x10);
      }
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellWorkingMemCtxAttach @ 0x301127B8  (примерный размер ~128 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_301123fc, FUN_3011269c, __errno, shellFirst, shellNext
 * Константы: 0xFFFFFFFF, 0x301127B8
 * Данные: DAT_30112e90
 * ---------------------------------------------------------------- */
undefined4
shellWorkingMemCtxAttach
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  for (iVar1 = shellFirst(); iVar1 != 0; iVar1 = shellNext(iVar1)) {
    iVar2 = FUN_3011269c(iVar1,param_2);
    if (iVar2 != 0) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = DAT_30112e90;
      return 0xffffffff;
    }
  }
  iVar1 = FUN_301123fc(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  return 0;
}

