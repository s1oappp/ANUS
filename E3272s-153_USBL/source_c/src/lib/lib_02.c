/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : lib — libc/математика/криптография/компрессия (AES, zlib-подобный QC_*)
 * Часть  : 2 (функций: 150, адреса 0x300B0FE8..0x300BEA98)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * sinh @ 0x300B0FE8  (примерный размер ~696 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 8
 * Вызывает: __adddf3, __divdf3, __muldf3, __subdf3, _d_fngt, exp, expm1, fabs
 * Константы: 0x300B0FE8, 0x7FFFFFFF
 * Данные: DAT_300b1274, DAT_300b1278, DAT_300b127c, DAT_300b1280, DAT_300b1284, DAT_300b1290, DAT_300b1294, DAT_300b1298
 * ---------------------------------------------------------------- */
double sinh(double __x)

{
  undefined4 uVar1;
  uint in_r0;
  int iVar2;
  undefined4 uVar3;
  uint in_r1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  uint uVar4;
  double dVar5;
  double extraout_d0;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  double in_stack_ffffffac;
  
  uVar4 = in_r1 & 0x7fffffff;
  if ((int)uVar4 < DAT_300b1274) {
    uVar1 = DAT_300b1278;
    if ((int)in_r1 < 0) {
      uVar1 = DAT_300b127c;
    }
    if ((int)uVar4 < DAT_300b1280) {
      if ((int)uVar4 < DAT_300b1284) {
        uVar6 = __adddf3();
        iVar2 = _d_fngt((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,DAT_300b1290);
        if (iVar2 == 0) {
          return extraout_d0;
        }
      }
      fabs(in_stack_ffffffac);
      expm1(in_stack_ffffffac);
      if ((int)uVar4 < DAT_300b1290) {
        uVar6 = __muldf3();
        uVar7 = __muldf3(in_r0,extraout_r1,in_r0,extraout_r1);
        uVar8 = __adddf3(in_r0,extraout_r1,0,DAT_300b1290);
        uVar7 = __divdf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                         (int)((ulonglong)uVar8 >> 0x20));
        uVar6 = __subdf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar7,
                         (int)((ulonglong)uVar7 >> 0x20));
        dVar5 = (double)__muldf3(0,uVar1,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
      }
      else {
        uVar6 = __adddf3();
        uVar6 = __divdf3(in_r0,extraout_r1,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
        uVar6 = __adddf3(in_r0,extraout_r1,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
        dVar5 = (double)__muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,uVar1);
      }
    }
    else {
      if ((int)uVar4 < DAT_300b1294) {
        fabs(in_stack_ffffffac);
        exp(in_stack_ffffffac);
      }
      else if (((int)uVar4 < (int)DAT_300b1298) ||
              ((uVar4 == DAT_300b1298 && (in_r0 <= DAT_300b129c)))) {
        fabs(in_stack_ffffffac);
        uVar3 = __muldf3();
        exp(in_stack_ffffffac);
        uVar6 = __muldf3(0,uVar1,uVar3,extraout_r1_00);
        dVar5 = (double)__muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar3,extraout_r1_00);
        return dVar5;
      }
      dVar5 = (double)__muldf3();
    }
  }
  else {
    dVar5 = (double)__adddf3();
  }
  return dVar5;
}

/* ----------------------------------------------------------------
 * tanh @ 0x300B12A0  (примерный размер ~400 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 6
 * Вызывает: __adddf3, __divdf3, __muldf3, __subdf3, expm1, fabs
 * Константы: 0x300B12A0, 0x7FFFFFFF, 0x3C800000, 0x80000000, 0x40000000
 * Данные: DAT_300b1424, DAT_300b1428, DAT_300b142c
 * ---------------------------------------------------------------- */
double tanh(double __x)

{
  int iVar1;
  undefined4 in_r0;
  undefined4 uVar2;
  uint in_r1;
  uint extraout_r1;
  uint uVar3;
  double in_d0;
  undefined8 uVar4;
  double in_stack_ffffffc4;
  
  iVar1 = DAT_300b1428;
  uVar3 = in_r1 & 0x7fffffff;
  if ((int)uVar3 < DAT_300b1424) {
    if ((int)uVar3 < DAT_300b142c) {
      if (uVar3 < 0x3c800000) {
        __adddf3(in_r0,in_r1,0,DAT_300b1428);
        in_d0 = (double)__muldf3();
      }
      else if ((int)uVar3 < DAT_300b1428) {
        fabs(in_stack_ffffffc4);
        uVar2 = __muldf3();
        expm1(in_stack_ffffffc4);
        uVar4 = __adddf3();
        in_d0 = (double)__divdf3(uVar2,extraout_r1 ^ 0x80000000,(int)uVar4,
                                 (int)((ulonglong)uVar4 >> 0x20));
      }
      else {
        fabs(in_stack_ffffffc4);
        __muldf3();
        expm1(in_stack_ffffffc4);
        uVar4 = __adddf3();
        uVar4 = __divdf3(0,0x40000000,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
        in_d0 = (double)__subdf3(0,DAT_300b1428,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
      }
    }
  }
  else if ((int)in_r1 < 0) {
    uVar4 = __divdf3(0,DAT_300b1428);
    in_d0 = (double)__subdf3((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,DAT_300b1428);
  }
  else {
    uVar4 = __divdf3(0,DAT_300b1428);
    in_d0 = (double)__adddf3((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,iVar1);
  }
  return in_d0;
}

/* ----------------------------------------------------------------
 * exp @ 0x300B1430  (примерный размер ~1548 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 8
 * Вызывает: __adddf3, __divdf3, __fixdfsi, __floatsidf, __muldf3, __subdf3, _d_fngt, _d_fnlt
 * Вызывают: cosh, sinh
 * Константы: 0x40000000, 0x300B1430, 0x7FFFFFFF, 0x00100000, 0x3E800000
 * Данные: DAT_300b19c0, DAT_300b19c4, DAT_300b19c8, DAT_300b19cc, DAT_300b19d0, DAT_300b19dc, DAT_300b19e0, DAT_300b19e8
 * ---------------------------------------------------------------- */
double exp(double __x)

{
  int in_r0;
  int iVar1;
  int iVar2;
  uint in_r1;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  double in_d0;
  double dVar9;
  double extraout_d0;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  int local_80;
  
  uVar11 = CONCAT44(in_r1,in_r0);
  uVar10 = CONCAT44(unaff_r9,unaff_r8);
  uVar12 = CONCAT44(unaff_r5,unaff_r4);
  iVar2 = (int)in_r1 >> 0x1f;
  uVar7 = in_r1 & 0x7fffffff;
  if (DAT_300b19c0 <= uVar7) {
    if (DAT_300b19c4 <= uVar7) {
      if (in_r0 == 0 && (uVar7 & DAT_300b19c8) == 0) {
        return in_d0;
      }
      dVar9 = (double)__adddf3();
      return dVar9;
    }
    iVar1 = _d_fngt(in_r0,in_r1,DAT_300b19cc,DAT_300b19c0);
    if (iVar1 == 0) {
      dVar9 = (double)__muldf3(*DAT_300b19d0,DAT_300b19d0[1],*DAT_300b19d0,DAT_300b19d0[1]);
      return dVar9;
    }
    iVar1 = _d_fnlt();
    if (iVar1 == 0) {
      dVar9 = (double)__muldf3(DAT_300b19d0[2],DAT_300b19d0[3],DAT_300b19d0[2],DAT_300b19d0[3]);
      return dVar9;
    }
  }
  if (DAT_300b19dc < uVar7) {
    if (uVar7 < DAT_300b19e0) {
      uVar10 = __subdf3();
      uVar12 = *(undefined8 *)(DAT_300b19e8 + iVar2 * -8);
      local_80 = iVar2 * 2 + 1;
    }
    else {
      uVar10 = __muldf3();
      puVar8 = (undefined4 *)(DAT_300b19f4 + iVar2 * -8);
      __adddf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),*puVar8,puVar8[1]);
      local_80 = __fixdfsi();
      uVar12 = __floatsidf();
      uVar3 = (undefined4)((ulonglong)uVar12 >> 0x20);
      __muldf3((int)uVar12,uVar3,DAT_300b19fc,DAT_300b19f8);
      uVar10 = __subdf3();
      uVar12 = __muldf3((int)uVar12,uVar3,DAT_300b1a04,DAT_300b1a00);
    }
    uVar11 = __subdf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar12,
                      (int)((ulonglong)uVar12 >> 0x20));
  }
  else if (uVar7 < DAT_300b1a08) {
    uVar10 = __adddf3();
    iVar2 = _d_fngt((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,DAT_300b1a0c);
    uVar12 = CONCAT44(unaff_r5,unaff_r4);
    uVar10 = CONCAT44(unaff_r9,unaff_r8);
    uVar11 = CONCAT44(in_r1,in_r0);
    if (iVar2 == 0) {
      dVar9 = (double)__adddf3();
      return dVar9;
    }
  }
  else {
    local_80 = 0;
  }
  uVar6 = (undefined4)((ulonglong)uVar11 >> 0x20);
  uVar5 = (undefined4)uVar11;
  uVar11 = __muldf3(uVar5,uVar6,uVar5,uVar6);
  uVar4 = (undefined4)((ulonglong)uVar11 >> 0x20);
  uVar3 = (undefined4)uVar11;
  uVar11 = __muldf3(uVar3,uVar4,DAT_300b1a14,DAT_300b1a10);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b1a1c,DAT_300b1a18);
  uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar4);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b1a24,DAT_300b1a20);
  uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar4);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b1a2c,DAT_300b1a28);
  uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar4);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b1a34,DAT_300b1a30);
  uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar4);
  uVar11 = __subdf3(uVar5,uVar6,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
  uVar4 = (undefined4)((ulonglong)uVar11 >> 0x20);
  uVar3 = (undefined4)uVar11;
  if (local_80 == 0) {
    uVar10 = __muldf3(uVar5,uVar6,uVar3,uVar4);
    uVar12 = __subdf3(uVar3,uVar4,0,0x40000000);
    uVar10 = __divdf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar12,
                      (int)((ulonglong)uVar12 >> 0x20));
    uVar10 = __subdf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar5,uVar6);
    dVar9 = (double)__subdf3(0,DAT_300b1a0c,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
  }
  else {
    uVar11 = __muldf3(uVar5,uVar6,uVar3,uVar4);
    uVar13 = __subdf3(0,0x40000000,uVar3,uVar4);
    uVar11 = __divdf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar13,
                      (int)((ulonglong)uVar13 >> 0x20));
    uVar12 = __subdf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar11,
                      (int)((ulonglong)uVar11 >> 0x20));
    uVar10 = __subdf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar10,
                      (int)((ulonglong)uVar10 >> 0x20));
    uVar10 = __subdf3(0,DAT_300b1a0c,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    dVar9 = extraout_d0;
    if (local_80 < -0x3fd) {
      dVar9 = (double)__muldf3((int)uVar10,
                               (int)((ulonglong)uVar10 >> 0x20) + local_80 * 0x100000 + 0x3e800000,
                               *DAT_300b1a38,DAT_300b1a38[1]);
    }
  }
  return dVar9;
}

/* ----------------------------------------------------------------
 * expm1 @ 0x300B1A3C  (примерный размер ~2308 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 8
 * Вызывает: __adddf3, __divdf3, __fixdfsi, __floatsidf, __muldf3, __subdf3, _d_fngt, _d_fnlt
 * Вызывают: cosh, sinh, tanh
 * Константы: 0xFFFFFFFF, 0x300B1A3C, 0x80000000, 0x7FFFFFFF, 0xC0000000, 0x40000000, 0xFFFFFFFE, 0x00100000
 * Данные: DAT_300b22ac, DAT_300b22b0, DAT_300b22b4, DAT_300b22b8, DAT_300b22c0, DAT_300b22c4, DAT_300b22d0, DAT_300b22d4
 * ---------------------------------------------------------------- */
double expm1(double __x)

{
  int in_r0;
  int iVar1;
  uint in_r1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  double in_d0;
  double dVar11;
  double extraout_d0;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  uint local_a4;
  
  uVar13 = CONCAT44(unaff_r11,unaff_r10);
  uVar14 = CONCAT44(in_r1,in_r0);
  uVar9 = in_r1 & 0x80000000;
  uVar10 = in_r1 & 0x7fffffff;
  if (DAT_300b22ac <= uVar10) {
    if (DAT_300b22b0 <= uVar10) {
      if (DAT_300b22b4 <= uVar10) {
        if (in_r0 == 0 && (uVar10 & DAT_300b22b8) == 0) {
          return in_d0;
        }
        dVar11 = (double)__adddf3();
        return dVar11;
      }
      iVar1 = _d_fngt(in_r0,in_r1,DAT_300b22c0,DAT_300b22b0);
      if (iVar1 == 0) {
        dVar11 = (double)__muldf3(*DAT_300b22c4,DAT_300b22c4[1],*DAT_300b22c4,DAT_300b22c4[1]);
        return dVar11;
      }
    }
    if (uVar9 != 0) {
      uVar12 = __adddf3();
      iVar1 = _d_fnlt((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0);
      if (iVar1 == 0) {
        return extraout_d0;
      }
    }
  }
  if (DAT_300b22d0 < uVar10) {
    if (uVar10 < DAT_300b22d4) {
      if (uVar9 == 0) {
        uVar13 = __subdf3();
        uVar12 = *DAT_300b22e0;
        local_a4 = 1;
      }
      else {
        uVar13 = __adddf3();
        uVar12 = CONCAT44(DAT_300b22e4,DAT_300b22e8);
        local_a4 = 0xffffffff;
      }
    }
    else {
      uVar4 = DAT_300b22ec;
      if (uVar9 != 0) {
        uVar4 = DAT_300b22f0;
      }
      uVar14 = __muldf3();
      __adddf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,uVar4);
      local_a4 = __fixdfsi();
      uVar14 = __floatsidf();
      uVar4 = (undefined4)((ulonglong)uVar14 >> 0x20);
      __muldf3((int)uVar14,uVar4,DAT_300b22dc,DAT_300b22d8);
      uVar13 = __subdf3();
      uVar12 = __muldf3((int)uVar14,uVar4,DAT_300b22e8,DAT_300b22fc);
    }
    uVar4 = (undefined4)((ulonglong)uVar12 >> 0x20);
    uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar14 = __subdf3((int)uVar13,uVar7,(int)uVar12,uVar4);
    uVar13 = __subdf3((int)uVar13,uVar7,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
    uVar13 = __subdf3((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar12,uVar4);
  }
  else {
    if (uVar10 < DAT_300b2300) {
      uVar14 = __adddf3(*DAT_300b22c4,DAT_300b22c4[1]);
      uVar13 = __adddf3();
      __subdf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar13,
               (int)((ulonglong)uVar13 >> 0x20));
      dVar11 = (double)__subdf3();
      return dVar11;
    }
    local_a4 = 0;
  }
  uVar8 = (undefined4)((ulonglong)uVar13 >> 0x20);
  uVar6 = (undefined4)((ulonglong)uVar14 >> 0x20);
  uVar5 = (undefined4)uVar14;
  uVar14 = __muldf3(uVar5,uVar6,0,DAT_300b22ec);
  uVar7 = (undefined4)((ulonglong)uVar14 >> 0x20);
  uVar12 = __muldf3(uVar5,uVar6,(int)uVar14,uVar7);
  uVar2 = (undefined4)((ulonglong)uVar12 >> 0x20);
  uVar4 = (undefined4)uVar12;
  uVar12 = __muldf3(uVar4,uVar2,DAT_300b2308,DAT_300b2304);
  uVar12 = __adddf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),DAT_300b2310,DAT_300b230c);
  uVar12 = __muldf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),uVar4,uVar2);
  uVar12 = __adddf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),DAT_300b2318,DAT_300b2314);
  uVar12 = __muldf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),uVar4,uVar2);
  uVar12 = __adddf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),DAT_300b2320,DAT_300b231c);
  uVar12 = __muldf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),uVar4,uVar2);
  uVar12 = __adddf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),DAT_300b2328,DAT_300b2324);
  uVar12 = __muldf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),uVar4,uVar2);
  uVar12 = __adddf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0,DAT_300b232c);
  uVar3 = (undefined4)((ulonglong)uVar12 >> 0x20);
  uVar14 = __muldf3((int)uVar12,uVar3,(int)uVar14,uVar7);
  uVar14 = __subdf3(0,DAT_300b2330,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
  uVar7 = (undefined4)((ulonglong)uVar14 >> 0x20);
  uVar15 = __muldf3(uVar5,uVar6,(int)uVar14,uVar7);
  uVar15 = __subdf3(0,DAT_300b2334,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
  uVar14 = __subdf3((int)uVar12,uVar3,(int)uVar14,uVar7);
  uVar14 = __divdf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar15,
                    (int)((ulonglong)uVar15 >> 0x20));
  uVar14 = __muldf3(uVar4,uVar2,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
  uVar7 = (undefined4)((ulonglong)uVar14 >> 0x20);
  if (local_a4 == 0) {
    uVar14 = __muldf3(uVar5,uVar6,(int)uVar14,uVar7);
    uVar14 = __subdf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uVar4,uVar2);
    dVar11 = (double)__subdf3(uVar5,uVar6,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
  }
  else {
    uVar14 = __subdf3((int)uVar14,uVar7,(int)uVar13,uVar8);
    uVar14 = __muldf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uVar5,uVar6);
    uVar14 = __subdf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar13,uVar8);
    uVar14 = __subdf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uVar4,uVar2);
    uVar4 = DAT_300b22ec;
    uVar2 = (undefined4)((ulonglong)uVar14 >> 0x20);
    uVar7 = (undefined4)uVar14;
    if (local_a4 == 0xffffffff) {
      uVar14 = __subdf3(uVar5,uVar6,uVar7,uVar2);
      uVar14 = __muldf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,uVar4);
      dVar11 = (double)__subdf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,uVar4);
    }
    else if (local_a4 == 1) {
      iVar1 = _d_fnlt(uVar5,uVar6,0,DAT_300b2338);
      if (iVar1 == 0) {
        uVar14 = __adddf3(uVar5,uVar6,0,DAT_300b22ec);
        uVar14 = __subdf3(uVar7,uVar2,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
        dVar11 = (double)__muldf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0xc0000000);
      }
      else {
        uVar14 = __subdf3(uVar5,uVar6,uVar7,uVar2);
        uVar14 = __muldf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0x40000000);
        dVar11 = (double)__adddf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,DAT_300b232c);
      }
    }
    else if ((local_a4 == 0xfffffffe || (int)(local_a4 + 2) < 0 != SCARRY4(local_a4,2)) ||
            (0x38 < (int)local_a4)) {
      uVar14 = __subdf3(uVar7,uVar2,uVar5,uVar6);
      uVar14 = __subdf3(0,DAT_300b232c,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
      dVar11 = (double)__subdf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20) + local_a4 * 0x100000,0
                                ,DAT_300b232c);
    }
    else {
      uVar4 = *DAT_300b233c;
      if ((int)local_a4 < 0x14) {
        iVar1 = DAT_300b232c - (0x200000 >> (local_a4 & 0xff));
        uVar14 = __subdf3(uVar7,uVar2,uVar5,uVar6);
        dVar11 = (double)__subdf3(uVar4,iVar1,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
      }
      else {
        uVar14 = __adddf3(uVar7,uVar2,uVar4);
        uVar14 = __subdf3(uVar5,uVar6,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
        dVar11 = (double)__adddf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,DAT_300b232c);
      }
    }
  }
  return dVar11;
}

/* ----------------------------------------------------------------
 * log @ 0x300B241C  (примерный размер ~2132 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 6
 * Вызывает: __adddf3, __divdf3, __floatsidf, __muldf3, __subdf3, _d_fne
 * Вызывают: log10
 * Константы: 0x00100000, 0x300B241C, 0x7FFFFFFF, 0x40000000
 * Данные: DAT_300b2bf4, DAT_300b2bf8, DAT_300b2bfc, DAT_300b2c00, DAT_300b2c04, DAT_300b2c08, DAT_300b2c0c, DAT_300b2c10
 * ---------------------------------------------------------------- */
double log(double __x)

{
  int in_r0;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint in_r1;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  double dVar15;
  double extraout_d0;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  uint local_74;
  int local_68;
  
  uVar16 = CONCAT44(in_r1,in_r0);
  local_68 = 0;
  if ((int)in_r1 < 0x100000) {
    if (in_r0 == 0 && (in_r1 & 0x7fffffff) == 0) {
      dVar15 = (double)__divdf3(0,DAT_300b2bf8,*DAT_300b2bf4,DAT_300b2bf4[1]);
      return dVar15;
    }
    if ((int)in_r1 < 0) {
      uVar16 = __subdf3();
      dVar15 = (double)__divdf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),*DAT_300b2bf4,
                                DAT_300b2bf4[1]);
      return dVar15;
    }
    local_68 = -0x36;
    uVar16 = __muldf3(in_r0,in_r1,0,DAT_300b2bfc);
  }
  local_74 = (uint)((ulonglong)uVar16 >> 0x20);
  uVar12 = (undefined4)uVar16;
  if ((int)local_74 < DAT_300b2c00) {
    uVar13 = local_74 & DAT_300b2c08;
    uVar1 = uVar13 + DAT_300b2c0c & 0x100000;
    iVar14 = ((local_68 + ((int)local_74 >> 0x14)) - DAT_300b2c04) + ((int)uVar1 >> 0x14);
    uVar16 = __subdf3(uVar12,uVar13 | uVar1 ^ DAT_300b2c10,0);
    uVar7 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar12 = (undefined4)uVar16;
    if ((int)(uVar13 + 2 & DAT_300b2c08) < 3) {
      iVar2 = _d_fne(uVar12,uVar7,*DAT_300b2bf4,DAT_300b2bf4[1]);
      if (iVar2 == 0) {
        dVar15 = extraout_d0;
        if (iVar14 != 0) {
          uVar16 = __floatsidf(iVar14);
          uVar12 = (undefined4)((ulonglong)uVar16 >> 0x20);
          uVar17 = __muldf3((int)uVar16,uVar12,DAT_300b2c18,DAT_300b2c14);
          uVar16 = __muldf3((int)uVar16,uVar12,DAT_300b2c20,DAT_300b2c1c);
          dVar15 = (double)__adddf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar17,
                                    (int)((ulonglong)uVar17 >> 0x20));
        }
      }
      else {
        uVar16 = __muldf3(uVar12,uVar7,uVar12,uVar7);
        uVar17 = __muldf3(uVar12,uVar7,DAT_300b2c28,DAT_300b2c24);
        uVar17 = __subdf3(0,DAT_300b2c2c,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
        uVar16 = __muldf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                          (int)((ulonglong)uVar16 >> 0x20));
        uVar3 = (undefined4)((ulonglong)uVar16 >> 0x20);
        if (iVar14 == 0) {
          dVar15 = (double)__subdf3(uVar12,uVar7,(int)uVar16,uVar3);
        }
        else {
          uVar17 = __floatsidf(iVar14);
          uVar4 = (undefined4)((ulonglong)uVar17 >> 0x20);
          uVar18 = __muldf3((int)uVar17,uVar4,DAT_300b2c18,DAT_300b2c14);
          uVar17 = __muldf3((int)uVar17,uVar4,DAT_300b2c20,DAT_300b2c1c);
          uVar16 = __subdf3((int)uVar16,uVar3,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
          uVar16 = __subdf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar12,uVar7);
          dVar15 = (double)__subdf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar16,
                                    (int)((ulonglong)uVar16 >> 0x20));
        }
      }
    }
    else {
      uVar16 = __adddf3(uVar12,uVar7,0,0x40000000);
      uVar16 = __divdf3(uVar12,uVar7,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
      uVar8 = (undefined4)((ulonglong)uVar16 >> 0x20);
      uVar3 = (undefined4)uVar16;
      uVar16 = __floatsidf(iVar14);
      uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
      uVar4 = (undefined4)uVar16;
      uVar16 = __muldf3(uVar3,uVar8,uVar3,uVar8);
      uVar10 = (undefined4)((ulonglong)uVar16 >> 0x20);
      uVar5 = (undefined4)uVar16;
      uVar1 = uVar13 - DAT_300b2c30;
      uVar16 = __muldf3(uVar5,uVar10,uVar5,uVar10);
      uVar11 = (undefined4)((ulonglong)uVar16 >> 0x20);
      uVar6 = (undefined4)uVar16;
      uVar13 = DAT_300b2c34 - uVar13;
      uVar16 = __muldf3(uVar6,uVar11,DAT_300b2c3c,DAT_300b2c38);
      uVar16 = __adddf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_300b2c44,DAT_300b2c40);
      uVar16 = __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar6,uVar11);
      uVar16 = __adddf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_300b2c4c,DAT_300b2c48);
      __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar6,uVar11);
      uVar16 = __muldf3(uVar6,uVar11,DAT_300b2c54,DAT_300b2c50);
      uVar16 = __adddf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_300b2c5c,DAT_300b2c58);
      uVar16 = __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar6,uVar11);
      uVar16 = __adddf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_300b2c64,DAT_300b2c60);
      uVar16 = __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar6,uVar11);
      uVar16 = __adddf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_300b2c6c,DAT_300b2c68);
      __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar5,uVar10);
      uVar16 = __adddf3();
      uVar6 = (undefined4)((ulonglong)uVar16 >> 0x20);
      uVar5 = (undefined4)uVar16;
      if ((int)(uVar1 | uVar13) < 1) {
        if (iVar14 == 0) {
          uVar16 = __subdf3(uVar12,uVar7,uVar5,uVar6);
          uVar16 = __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar3,uVar8);
          dVar15 = (double)__subdf3(uVar12,uVar7,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
          return dVar15;
        }
        uVar16 = __muldf3(uVar4,uVar9,DAT_300b2c18,DAT_300b2c14);
        uVar17 = __subdf3(uVar12,uVar7,uVar5,uVar6);
        uVar17 = __muldf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar3,uVar8);
        uVar18 = __muldf3(uVar4,uVar9,DAT_300b2c20,DAT_300b2c1c);
        uVar17 = __subdf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                          (int)((ulonglong)uVar18 >> 0x20));
        uVar17 = __subdf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar12,uVar7);
      }
      else {
        uVar16 = __muldf3(uVar12,uVar7,uVar12,uVar7);
        uVar16 = __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),0,DAT_300b2c2c);
        uVar11 = (undefined4)((ulonglong)uVar16 >> 0x20);
        uVar10 = (undefined4)uVar16;
        if (iVar14 == 0) {
          uVar16 = __adddf3(uVar10,uVar11,uVar5,uVar6);
          uVar16 = __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar3,uVar8);
          uVar16 = __subdf3(uVar10,uVar11,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
          dVar15 = (double)__subdf3(uVar12,uVar7,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
          return dVar15;
        }
        uVar16 = __muldf3(uVar4,uVar9,DAT_300b2c18,DAT_300b2c14);
        uVar17 = __adddf3(uVar10,uVar11,uVar5,uVar6);
        uVar17 = __muldf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar3,uVar8);
        uVar18 = __muldf3(uVar4,uVar9,DAT_300b2c20,DAT_300b2c1c);
        uVar17 = __adddf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                          (int)((ulonglong)uVar17 >> 0x20));
        uVar17 = __subdf3(uVar10,uVar11,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
        uVar17 = __subdf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar12,uVar7);
      }
      dVar15 = (double)__subdf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar17,
                                (int)((ulonglong)uVar17 >> 0x20));
    }
  }
  else {
    dVar15 = (double)__adddf3(uVar12,local_74,uVar12,local_74);
  }
  return dVar15;
}

/* ----------------------------------------------------------------
 * log10 @ 0x300B2C70  (примерный размер ~476 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 6
 * Вызывает: __adddf3, __divdf3, __floatsidf, __muldf3, __subdf3, log
 * Константы: 0x300B2C70, 0x00100000, 0x7FFFFFFF
 * Данные: DAT_300b2e18, DAT_300b2e1c, DAT_300b2e24, DAT_300b2e28, DAT_300b2e34, DAT_300b2e38, DAT_300b2e44, DAT_300b2e48
 * ---------------------------------------------------------------- */
double log10(double __x)

{
  int in_r0;
  uint in_r1;
  uint extraout_r1;
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  double in_stack_ffffffac;
  int local_44;
  
  local_44 = 0;
  if ((int)in_r1 < 0x100000) {
    if (in_r0 == 0 && (in_r1 & 0x7fffffff) == 0) {
      dVar3 = (double)__divdf3(0,DAT_300b2e1c,*DAT_300b2e18,DAT_300b2e18[1]);
      return dVar3;
    }
    if ((int)in_r1 < 0) {
      uVar4 = __subdf3();
      dVar3 = (double)__divdf3((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),*DAT_300b2e18,
                               DAT_300b2e18[1]);
      return dVar3;
    }
    local_44 = -0x36;
    __muldf3();
    in_r1 = extraout_r1;
  }
  if ((int)in_r1 < DAT_300b2e24) {
    iVar2 = (local_44 + ((int)in_r1 >> 0x14)) - DAT_300b2e28;
    uVar4 = __floatsidf(iVar2 - (iVar2 >> 0x1f));
    uVar1 = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar5 = __muldf3((int)uVar4,uVar1,DAT_300b2e38,DAT_300b2e34);
    log(in_stack_ffffffac);
    uVar6 = __muldf3();
    __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    __muldf3((int)uVar4,uVar1,DAT_300b2e48,DAT_300b2e44);
  }
  dVar3 = (double)__adddf3();
  return dVar3;
}

/* ----------------------------------------------------------------
 * modf @ 0x300B2E4C  (примерный размер ~368 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 2
 * Вызывает: __muldf3, __subdf3
 * Вызывают: FUN_300c4448, FUN_300c4638
 * Константы: 0x300B2E4C, 0x80000000, 0xFFFFFFFF
 * Данные: DAT_300b2fac, DAT_300b2fb0, DAT_300b2fb4
 * ---------------------------------------------------------------- */
double modf(double __x,double *__iptr)

{
  uint in_r1;
  uint uVar1;
  uint *in_r2;
  double in_d0;
  double extraout_d0;
  double dVar2;
  undefined8 uVar3;
  
  uVar1 = (DAT_300b2fac & (int)in_r1 >> 0x14) - DAT_300b2fb0;
  if ((int)uVar1 < 0x14) {
    if ((int)uVar1 < 0) {
      *in_r2 = 0;
      in_r2[1] = in_r1 & 0x80000000;
      return in_d0;
    }
    uVar1 = DAT_300b2fb4 >> (uVar1 & 0xff);
    if (__iptr == (double *)0x0 && (in_r1 & uVar1) == 0) {
      *in_r2 = (uint)__iptr;
      in_r2[1] = in_r1;
      return in_d0;
    }
    *in_r2 = 0;
    in_r2[1] = in_r1 & ~uVar1;
  }
  else {
    if (0x33 < (int)uVar1) {
      uVar3 = __muldf3();
      *(undefined8 *)in_r2 = uVar3;
      return extraout_d0;
    }
    uVar1 = 0xffffffff >> (uVar1 - 0x14 & 0xff);
    if (((uint)__iptr & uVar1) == 0) {
      *in_r2 = (uint)__iptr;
      in_r2[1] = in_r1;
      return in_d0;
    }
    *in_r2 = (uint)__iptr & ~uVar1;
    in_r2[1] = in_r1;
  }
  dVar2 = (double)__subdf3();
  return dVar2;
}

/* ----------------------------------------------------------------
 * fabs @ 0x300B31C8  (примерный размер ~8 байт)
 * Модуль: lib | Вызывают: 9 | Вызывает: 0
 * Вызывают: __ieee754_rem_pio2, __kernel_tan, asin, atan, atan2, cosh, pow, sinh, tanh
 * Константы: 0x300B31C8
 * ---------------------------------------------------------------- */
double fabs(double __x)

{
  double in_d0;
  
  return in_d0;
}

/* ----------------------------------------------------------------
 * pow @ 0x300B31D0  (примерный размер ~6024 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 10
 * Вызывает: __adddf3, __divdf3, __floatsidf, __muldf3, __subdf3, _d_fnge, _d_fngt, _dsqrt, fabs, scalbn
 * Константы: 0x7FFFFFFF, 0x00100000, 0x40000000, 0x300B31D0, 0x60000000, 0xE0000000
 * Данные: DAT_300b421c, DAT_300b4220, DAT_300b4224, DAT_300b4228, DAT_300b4364, DAT_300b4368, DAT_300b45b4, DAT_300b45b8
 * ---------------------------------------------------------------- */
double pow(double __x,double __y)

{
  int in_r0;
  int iVar1;
  uint in_r1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar4;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  uint in_r2;
  undefined4 uVar5;
  undefined4 uVar6;
  uint in_r3;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  double in_d0;
  double dVar15;
  double extraout_d0;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  ulonglong uVar19;
  undefined8 uVar20;
  longlong lVar21;
  double in_stack_fffffec4;
  uint local_134;
  uint local_130;
  int local_12c;
  int local_124;
  undefined4 local_dc;
  undefined4 local_d8;
  
  uVar13 = in_r1 & 0x7fffffff;
  uVar14 = in_r3 & 0x7fffffff;
  if (uVar14 == 0 && in_r2 == 0) {
    return in_d0;
  }
  if ((((int)DAT_300b4220 < (int)uVar13) ||
      (((uVar13 == DAT_300b4220 && (in_r0 != 0)) || ((int)DAT_300b4220 < (int)uVar14)))) ||
     ((uVar14 == DAT_300b4220 && (in_r2 != 0)))) {
    dVar15 = (double)__adddf3();
    return dVar15;
  }
  local_124 = 0;
  if ((int)in_r1 < 0) {
    if (DAT_300b4224 <= (int)uVar14) {
      local_124 = 2;
      goto LAB_300b3334;
    }
    if ((int)uVar14 < (int)DAT_300b421c) goto LAB_300b3334;
    iVar2 = DAT_300b4228 + ((int)uVar14 >> 0x14);
    if (0x14 < iVar2) {
      uVar3 = in_r2 >> (0x34U - iVar2 & 0xff);
      if (in_r2 == uVar3 << (0x34U - iVar2 & 0xff)) {
LAB_300b3328:
        local_124 = 2 - (uVar3 & 1);
      }
      goto LAB_300b3334;
    }
    if (in_r2 == 0) {
      uVar3 = (int)uVar14 >> (0x14U - iVar2 & 0xff);
      if (uVar14 == uVar3 << (0x14U - iVar2 & 0xff)) goto LAB_300b3328;
      goto LAB_300b33e8;
    }
  }
  else {
LAB_300b3334:
    if (in_r2 == 0) {
      if (uVar14 == DAT_300b4220) {
        if (in_r0 != 0 || uVar13 != DAT_300b421c) {
          return in_d0;
        }
        dVar15 = (double)__subdf3();
        return dVar15;
      }
LAB_300b33e8:
      if (uVar14 == DAT_300b421c) {
        if (-1 < (int)in_r3) {
          return in_d0;
        }
        dVar15 = (double)__divdf3(0,DAT_300b421c);
        return dVar15;
      }
      if (in_r3 == 0x40000000) goto LAB_300b4884;
      if ((in_r3 == DAT_300b4368) && (-1 < (int)in_r1)) {
        dVar15 = (double)_dsqrt();
        return dVar15;
      }
    }
  }
  iVar2 = in_r0;
  dVar15 = fabs(in_stack_fffffec4);
  uVar19 = CONCAT44(in_r1,iVar2) & 0x7fffffffffffffff;
  uVar16 = CONCAT44(extraout_r1,iVar2);
  if ((in_r0 == 0) && (((uVar13 == DAT_300b4220 || (uVar13 == 0)) || (uVar13 == DAT_300b421c)))) {
    if ((int)in_r3 < 0) {
      uVar16 = __divdf3(0,DAT_300b421c,iVar2,extraout_r1);
      dVar15 = extraout_d0;
    }
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    if (-1 < (int)in_r1) {
      return dVar15;
    }
    if (local_124 != 0 || uVar13 != DAT_300b421c) {
      return dVar15;
    }
    uVar16 = __subdf3((int)uVar16,uVar9,(int)uVar16,uVar9);
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    dVar15 = (double)__divdf3((int)uVar16,uVar9,(int)uVar16,uVar9);
    return dVar15;
  }
  if (local_124 == 0 && (int)in_r1 < 0) {
    uVar16 = __subdf3();
    uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
    dVar15 = (double)__divdf3((int)uVar16,uVar9,(int)uVar16,uVar9);
    return dVar15;
  }
  if (DAT_300b45b4 < (int)uVar14) {
    if (DAT_300b45b8 < (int)uVar14) {
      if ((int)uVar13 <= DAT_300b45bc) {
        if ((int)in_r3 < 0) {
          uVar9 = *DAT_300b45c0;
          uVar10 = DAT_300b45c0[1];
          uVar7 = DAT_300b45c0[1];
        }
        else {
          uVar9 = DAT_300b45c0[2];
          uVar10 = DAT_300b45c0[3];
          uVar7 = DAT_300b45c0[3];
        }
        dVar15 = (double)__muldf3(uVar9,uVar10,uVar9,uVar7);
        return dVar15;
      }
      if ((int)in_r3 < 1) {
        uVar9 = DAT_300b45c0[2];
        uVar10 = DAT_300b45c0[3];
        uVar7 = DAT_300b45c0[3];
      }
      else {
        uVar9 = *DAT_300b45c0;
        uVar10 = DAT_300b45c0[1];
        uVar7 = DAT_300b45c0[1];
      }
      dVar15 = (double)__muldf3(uVar9,uVar10,uVar9,uVar7);
      return dVar15;
    }
    if ((int)uVar13 < DAT_300b45bc) {
      if ((int)in_r3 < 0) {
        uVar9 = *DAT_300b45c0;
        uVar10 = DAT_300b45c0[1];
        uVar7 = DAT_300b45c0[1];
      }
      else {
        uVar9 = DAT_300b45c0[2];
        uVar10 = DAT_300b45c0[3];
        uVar7 = DAT_300b45c0[3];
      }
      dVar15 = (double)__muldf3(uVar9,uVar10,uVar9,uVar7);
      return dVar15;
    }
    if ((int)DAT_300b421c < (int)uVar13) {
      if ((int)in_r3 < 1) {
        uVar9 = DAT_300b45c0[2];
        uVar10 = DAT_300b45c0[3];
        uVar7 = DAT_300b45c0[3];
      }
      else {
        uVar9 = *DAT_300b45c0;
        uVar10 = DAT_300b45c0[1];
        uVar7 = DAT_300b45c0[1];
      }
      dVar15 = (double)__muldf3(uVar9,uVar10,uVar9,uVar7);
      return dVar15;
    }
    uVar16 = __subdf3();
    uVar10 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar9 = (undefined4)uVar16;
    uVar16 = __muldf3(uVar9,uVar10,uVar9,uVar10);
    uVar17 = __muldf3(uVar9,uVar10,0,DAT_300b4758);
    uVar17 = __subdf3(DAT_300b4760,DAT_300b475c,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
    uVar17 = __muldf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar9,uVar10);
    uVar17 = __subdf3(0,DAT_300b4368,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
    uVar16 = __muldf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                      (int)((ulonglong)uVar16 >> 0x20));
    uVar17 = __muldf3(uVar9,uVar10,0x60000000,DAT_300b4764);
    uVar7 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar18 = __muldf3(uVar9,uVar10,DAT_300b476c,DAT_300b4768);
    uVar16 = __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_300b4770,DAT_300b4764);
    uVar16 = __subdf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar16,
                      (int)((ulonglong)uVar16 >> 0x20));
    __adddf3((int)uVar17,uVar7,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
    uVar17 = __subdf3(0,extraout_r1_00,(int)uVar17,uVar7);
    uVar9 = extraout_r1_00;
  }
  else {
    iVar1 = 0;
    if (uVar13 < 0x100000) {
      uVar19 = __muldf3(iVar2,extraout_r1,0,DAT_300b4224);
      iVar1 = -0x35;
    }
    local_134 = (uint)(uVar19 >> 0x20);
    uVar9 = (undefined4)uVar19;
    local_12c = (iVar1 + ((int)local_134 >> 0x14)) - DAT_300b4894;
    local_134 = local_134 & DAT_300b4898;
    local_130 = local_134 | DAT_300b421c;
    if (DAT_300b489c < (int)local_134) {
      if ((int)local_134 < DAT_300b48a0) {
        local_134 = 1;
      }
      else {
        local_134 = 0;
        local_12c = local_12c + 1;
        local_130 = local_130 - 0x100000;
      }
    }
    else {
      local_134 = 0;
    }
    puVar12 = (undefined4 *)(DAT_300b48a4 + local_134 * 8);
    uVar5 = *puVar12;
    uVar8 = puVar12[1];
    uVar16 = __subdf3(uVar9,local_130);
    uVar7 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar17 = __adddf3(uVar9,local_130,uVar5,uVar8);
    uVar17 = __divdf3(0,DAT_300b421c,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
    uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar18 = __muldf3((int)uVar16,uVar7,(int)uVar17,uVar11);
    uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
    uVar10 = (undefined4)uVar18;
    uVar6 = *DAT_300b4364;
    iVar2 = ((int)local_130 >> 1 | 0x20000000U) + local_134 * 0x40000 + 0x80000;
    uVar18 = __subdf3(uVar6,iVar2,uVar5,uVar8);
    uVar18 = __subdf3(uVar9,local_130,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
    uVar20 = __muldf3(0,uVar4,uVar6,iVar2);
    uVar18 = __muldf3(0,uVar4,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
    uVar16 = __subdf3((int)uVar16,uVar7,(int)uVar20,(int)((ulonglong)uVar20 >> 0x20));
    uVar16 = __subdf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar18,
                      (int)((ulonglong)uVar18 >> 0x20));
    uVar16 = __muldf3((int)uVar17,uVar11,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
    uVar7 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar17 = __muldf3(uVar10,uVar4,uVar10,uVar4);
    uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar9 = (undefined4)uVar17;
    uVar17 = __muldf3(uVar9,uVar11,uVar9,uVar11);
    uVar18 = __muldf3(uVar9,uVar11,DAT_300b48ac,DAT_300b48a8);
    uVar18 = __adddf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),DAT_300b48b4,DAT_300b48b0);
    uVar18 = __muldf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar9,uVar11);
    uVar18 = __adddf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),DAT_300b48bc,DAT_300b48b8);
    uVar18 = __muldf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar9,uVar11);
    uVar18 = __adddf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),DAT_300b48c0,DAT_300b475c);
    uVar18 = __muldf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar9,uVar11);
    uVar18 = __adddf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),DAT_300b48c8,DAT_300b48c4);
    uVar18 = __muldf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar9,uVar11);
    uVar18 = __adddf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),DAT_300b48d0,DAT_300b48cc);
    uVar17 = __muldf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                      (int)((ulonglong)uVar17 >> 0x20));
    uVar18 = __adddf3(0,uVar4,uVar10,uVar4);
    uVar18 = __muldf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar16,uVar7);
    uVar17 = __adddf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                      (int)((ulonglong)uVar18 >> 0x20));
    uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar18 = __muldf3(0,uVar4);
    uVar5 = (undefined4)((ulonglong)uVar18 >> 0x20);
    uVar20 = __adddf3((int)uVar18,uVar5,(int)uVar17,uVar11);
    uVar9 = DAT_300b48d4;
    __adddf3((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),0,DAT_300b48d4);
    uVar20 = __subdf3(0,extraout_r1_01,0,uVar9);
    uVar18 = __subdf3((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar18,uVar5);
    uVar17 = __subdf3((int)uVar17,uVar11,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
    uVar18 = __muldf3(0,uVar4,0,extraout_r1_01);
    uVar9 = (undefined4)((ulonglong)uVar18 >> 0x20);
    uVar16 = __muldf3((int)uVar16,uVar7,0,extraout_r1_01);
    uVar17 = __muldf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar10,uVar4);
    uVar16 = __adddf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                      (int)((ulonglong)uVar16 >> 0x20));
    uVar10 = (undefined4)((ulonglong)uVar16 >> 0x20);
    __adddf3((int)uVar18,uVar9,(int)uVar16,uVar10);
    uVar17 = __subdf3(0,extraout_r1_02,(int)uVar18,uVar9);
    uVar16 = __subdf3((int)uVar16,uVar10,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
    uVar17 = __muldf3(0,extraout_r1_02,0xe0000000,DAT_300b48d8);
    uVar9 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar18 = __muldf3(0,extraout_r1_02,DAT_300b48e0,DAT_300b48dc);
    uVar16 = __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_300b48e4,DAT_300b48d8);
    __adddf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar18,
             (int)((ulonglong)uVar18 >> 0x20));
    uVar16 = __adddf3();
    uVar18 = __floatsidf(local_12c);
    uVar10 = (undefined4)((ulonglong)uVar18 >> 0x20);
    puVar12 = (undefined4 *)(DAT_300b48ec + local_134 * 8);
    uVar7 = *puVar12;
    uVar11 = puVar12[1];
    uVar20 = __adddf3((int)uVar17,uVar9,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
    uVar20 = __adddf3((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),uVar7,uVar11);
    __adddf3((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar18,uVar10);
    uVar18 = __subdf3(0,extraout_r1_03,(int)uVar18,uVar10);
    uVar18 = __subdf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar7,uVar11);
    uVar17 = __subdf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,uVar9);
    uVar9 = extraout_r1_03;
  }
  __subdf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar17,(int)((ulonglong)uVar17 >> 0x20)
          );
  local_dc = *DAT_300b48f0;
  local_d8 = DAT_300b48f0[1];
  if ((int)in_r1 < 0 && local_124 == 1) {
    local_dc = 0;
    local_d8 = DAT_300b48f4;
  }
  uVar16 = __subdf3();
  uVar16 = __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),0,uVar9);
  uVar17 = __muldf3();
  uVar16 = __adddf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                    (int)((ulonglong)uVar16 >> 0x20));
  uVar7 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar9 = (undefined4)uVar16;
  uVar16 = __muldf3(0);
  uVar11 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar10 = (undefined4)uVar16;
  lVar21 = __adddf3(uVar9,uVar7,uVar10,uVar11);
  uVar13 = (uint)((ulonglong)lVar21 >> 0x20);
  iVar2 = (int)lVar21;
  if ((int)uVar13 < (int)DAT_300b48f8) {
    if (DAT_300b4900 <= (int)(uVar13 & 0x7fffffff)) {
      if (iVar2 != 0 || uVar13 + DAT_300b4904 != 0) {
        __muldf3(local_dc,local_d8,DAT_300b45c0[2],DAT_300b45c0[3]);
        goto LAB_300b4884;
      }
      uVar17 = __subdf3(iVar2,uVar13,uVar10,uVar11);
      iVar2 = _d_fnge((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar9,uVar7);
      if (iVar2 == 0) {
        __muldf3(local_dc,local_d8,DAT_300b45c0[2],DAT_300b45c0[3]);
        goto LAB_300b4884;
      }
    }
  }
  else {
    if (iVar2 != 0 || uVar13 != DAT_300b48f8) {
      __muldf3(local_dc,local_d8,*DAT_300b45c0,DAT_300b45c0[1]);
      goto LAB_300b4884;
    }
    uVar17 = __subdf3(iVar2,uVar13,uVar10,uVar11);
    uVar18 = __adddf3(uVar9,uVar7,DAT_300b4770,DAT_300b48fc);
    iVar2 = _d_fngt((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                    (int)((ulonglong)uVar17 >> 0x20));
    if (iVar2 == 0) {
      __muldf3(local_dc,local_d8,*DAT_300b45c0,DAT_300b45c0[1]);
      goto LAB_300b4884;
    }
  }
  local_124 = 0;
  if (DAT_300b490c < (int)(uVar13 & 0x7fffffff)) {
    uVar13 = uVar13 + (0x100000 >> (DAT_300b4908 + ((int)(uVar13 & 0x7fffffff) >> 0x14) + 1U & 0xff)
                      );
    uVar14 = (DAT_300b4910 & (int)uVar13 >> 0x14) + DAT_300b4908;
    local_124 = (int)(uVar13 & DAT_300b4898 | 0x100000) >> (0x14 - uVar14 & 0xff);
    if (lVar21 < 0) {
      local_124 = -local_124;
    }
    uVar16 = __subdf3(uVar10,uVar11,*DAT_300b4914,uVar13 & ~((int)DAT_300b4898 >> (uVar14 & 0xff)));
  }
  uVar11 = (undefined4)((ulonglong)uVar16 >> 0x20);
  __adddf3(uVar9,uVar7,(int)uVar16,uVar11);
  uVar17 = __muldf3(0,extraout_r1_04,0,DAT_300b4918);
  uVar10 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar16 = __subdf3(0,extraout_r1_04,(int)uVar16,uVar11);
  uVar16 = __subdf3(uVar9,uVar7,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_300b4920,DAT_300b491c);
  uVar18 = __muldf3(0,extraout_r1_04,DAT_300b4928,DAT_300b4924);
  uVar16 = __adddf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar16,
                    (int)((ulonglong)uVar16 >> 0x20));
  uVar7 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar18 = __adddf3((int)uVar17,uVar10,(int)uVar16,uVar7);
  uVar11 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar9 = (undefined4)uVar18;
  uVar17 = __subdf3(uVar9,uVar11,(int)uVar17,uVar10);
  uVar16 = __subdf3((int)uVar16,uVar7,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
  uVar7 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar17 = __muldf3(uVar9,uVar11,uVar9,uVar11);
  uVar4 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar10 = (undefined4)uVar17;
  uVar17 = __muldf3(uVar10,uVar4,DAT_300b4930,DAT_300b492c);
  uVar17 = __adddf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),DAT_300b4938,DAT_300b4934);
  uVar17 = __muldf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar10,uVar4);
  uVar17 = __adddf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),DAT_300b4940,DAT_300b493c);
  uVar17 = __muldf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar10,uVar4);
  uVar17 = __adddf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),DAT_300b4948,DAT_300b4944);
  uVar17 = __muldf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar10,uVar4);
  uVar17 = __adddf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),DAT_300b4950,DAT_300b494c);
  uVar17 = __muldf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar10,uVar4);
  uVar17 = __subdf3(uVar9,uVar11,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
  uVar10 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar18 = __muldf3(uVar9,uVar11,(int)uVar17,uVar10);
  uVar17 = __subdf3((int)uVar17,uVar10,0,0x40000000);
  uVar17 = __divdf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                    (int)((ulonglong)uVar17 >> 0x20));
  uVar18 = __muldf3(uVar9,uVar11,(int)uVar16,uVar7);
  uVar16 = __adddf3((int)uVar16,uVar7,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar16 = __subdf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                    (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = __subdf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar11);
  uVar16 = __subdf3(0,DAT_300b4954,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  if ((int)((ulonglong)uVar16 >> 0x20) + local_124 * 0x100000 >> 0x14 < 1) {
    scalbn(in_stack_fffffec4,(int)uVar16);
  }
LAB_300b4884:
  dVar15 = (double)__muldf3();
  return dVar15;
}

/* ----------------------------------------------------------------
 * sqrt @ 0x300B4958  (примерный размер ~20 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: _dsqrt
 * Константы: 0x300B4958
 * ---------------------------------------------------------------- */
double sqrt(double __x)

{
  double dVar1;
  
  dVar1 = (double)_dsqrt();
  return dVar1;
}

/* ----------------------------------------------------------------
 * ceil @ 0x300B496C  (примерный размер ~392 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: __adddf3, _d_fngt
 * Константы: 0x300B496C
 * Данные: DAT_300b4adc, DAT_300b4ae0, DAT_300b4ae4, DAT_300b4ae8, DAT_300b4af0
 * ---------------------------------------------------------------- */
double ceil(double __x)

{
  uint in_r0;
  uint in_r1;
  uint uVar1;
  double in_d0;
  double extraout_d0;
  double extraout_d0_00;
  double extraout_d0_01;
  undefined8 uVar2;
  
  uVar1 = (DAT_300b4adc & (int)in_r1 >> 0x14) - DAT_300b4ae0;
  if ((int)uVar1 < 0x14) {
    if ((int)uVar1 < 0) {
      uVar2 = __adddf3(in_r0,in_r1,DAT_300b4ae8,DAT_300b4ae4);
      _d_fngt((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0);
      in_d0 = extraout_d0;
    }
    else if (in_r0 != 0 || (in_r1 & DAT_300b4af0 >> (uVar1 & 0xff)) != 0) {
      uVar2 = __adddf3(in_r0,in_r1,DAT_300b4ae8,DAT_300b4ae4);
      _d_fngt((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0);
      in_d0 = extraout_d0_00;
    }
  }
  else if ((int)uVar1 < 0x34) {
    if ((in_r0 & 0xffffffffU >> (uVar1 - 0x14 & 0xff)) != 0) {
      uVar2 = __adddf3(in_r0,in_r1,DAT_300b4ae8,DAT_300b4ae4);
      _d_fngt((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0);
      in_d0 = extraout_d0_01;
    }
  }
  else if (uVar1 == 0x400) {
    in_d0 = (double)__adddf3();
  }
  return in_d0;
}

/* ----------------------------------------------------------------
 * floor @ 0x300B4AF4  (примерный размер ~396 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 2
 * Вызывает: __adddf3, _d_fngt
 * Вызывают: __kernel_rem_pio2
 * Константы: 0x300B4AF4
 * Данные: DAT_300b4c68, DAT_300b4c6c, DAT_300b4c70, DAT_300b4c74, DAT_300b4c7c
 * ---------------------------------------------------------------- */
double floor(double __x)

{
  uint in_r0;
  uint in_r1;
  uint uVar1;
  double in_d0;
  double extraout_d0;
  double extraout_d0_00;
  double extraout_d0_01;
  undefined8 uVar2;
  
  uVar1 = (DAT_300b4c68 & (int)in_r1 >> 0x14) - DAT_300b4c6c;
  if ((int)uVar1 < 0x14) {
    if ((int)uVar1 < 0) {
      uVar2 = __adddf3(in_r0,in_r1,DAT_300b4c74,DAT_300b4c70);
      _d_fngt((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0);
      in_d0 = extraout_d0;
    }
    else if (in_r0 != 0 || (in_r1 & DAT_300b4c7c >> (uVar1 & 0xff)) != 0) {
      uVar2 = __adddf3(in_r0,in_r1,DAT_300b4c74,DAT_300b4c70);
      _d_fngt((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0);
      in_d0 = extraout_d0_00;
    }
  }
  else if ((int)uVar1 < 0x34) {
    if ((in_r0 & 0xffffffffU >> (uVar1 - 0x14 & 0xff)) != 0) {
      uVar2 = __adddf3(in_r0,in_r1,DAT_300b4c74,DAT_300b4c70);
      _d_fngt((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0);
      in_d0 = extraout_d0_01;
    }
  }
  else if (uVar1 == 0x400) {
    in_d0 = (double)__adddf3();
  }
  return in_d0;
}

/* ----------------------------------------------------------------
 * fmod @ 0x300B4C80  (примерный размер ~156 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: __subdf3, _drem, copysign
 * Константы: 0x80000000, 0x300B4C80, 0x7FFFFFFF
 * Данные: DAT_300b4d18
 * ---------------------------------------------------------------- */
double fmod(double __x,double __y)

{
  undefined4 in_r0;
  uint in_r1;
  uint extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 in_r2;
  double dVar1;
  double in_stack_ffffffc4;
  double in_stack_ffffffcc;
  
  dVar1 = _drem(in_stack_ffffffc4,in_stack_ffffffcc);
  if (((extraout_r1 & 0x7fffffff) < DAT_300b4d18) &&
     ((in_r1 & 0x80000000) != (extraout_r1 & 0x80000000))) {
    copysign(in_stack_ffffffc4,in_stack_ffffffcc);
    dVar1 = (double)__subdf3(in_r0,extraout_r1,in_r2,extraout_r1_00);
  }
  return dVar1;
}

/* ----------------------------------------------------------------
 * __ieee754_rem_pio2 @ 0x300B4D2C  (примерный размер ~1996 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 9
 * Вызывает: __adddf3, __fixdfsi, __floatsidf, __kernel_rem_pio2, __muldf3, __subdf3, _d_feq, _d_fne, fabs
 * Вызывают: cos, sin, tan
 * Константы: 0x80000000, 0x300B4D2C, 0x7FFFFFFF, 0x00100000, 0x2E000000
 * Данные: DAT_300b54a4, DAT_300b54a8, DAT_300b54ac, DAT_300b54b0, DAT_300b54b4, DAT_300b54b8, DAT_300b54bc, DAT_300b54c0
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

int __ieee754_rem_pio2(uint param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined4 in_stack_ffffff50;
  undefined4 in_stack_ffffff54;
  int local_a0;
  int local_9c;
  uint local_48 [6];
  undefined8 local_30;
  
  uVar7 = DAT_300b54f0;
  uVar10 = param_2 & 0x7fffffff;
  if ((int)uVar10 <= DAT_300b54a4) {
    *param_3 = param_1;
    param_3[1] = param_2;
    param_3[2] = 0;
    param_3[3] = 0;
    return 0;
  }
  if ((int)uVar10 < DAT_300b54a8) {
    if (0 < (int)param_2) {
      uVar11 = __subdf3();
      uVar6 = DAT_300b54b8;
      uVar7 = DAT_300b54b4;
      uVar3 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar2 = (undefined4)uVar11;
      if (uVar10 == DAT_300b54ac) {
        uVar11 = __subdf3(uVar2,uVar3,DAT_300b54bc,DAT_300b54b4);
        uVar6 = DAT_300b54c4;
        uVar7 = DAT_300b54c0;
        uVar2 = (undefined4)((ulonglong)uVar11 >> 0x20);
        uVar12 = __subdf3((int)uVar11,uVar2,DAT_300b54c4,DAT_300b54c0);
        *(undefined8 *)param_3 = uVar12;
        uVar11 = __subdf3((int)uVar11,uVar2,(int)uVar12,(int)((ulonglong)uVar12 >> 0x20));
      }
      else {
        uVar11 = __subdf3(uVar2,uVar3,DAT_300b54b8,DAT_300b54b4);
        *(undefined8 *)param_3 = uVar11;
        uVar11 = __subdf3(uVar2,uVar3,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
      }
      uVar11 = __subdf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar6,uVar7);
      *(undefined8 *)(param_3 + 2) = uVar11;
      return 1;
    }
    uVar11 = __adddf3(param_1,param_2,DAT_300b54b0,DAT_300b54ac);
    uVar6 = DAT_300b54b8;
    uVar7 = DAT_300b54b4;
    uVar3 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar2 = (undefined4)uVar11;
    if (uVar10 == DAT_300b54ac) {
      uVar11 = __adddf3(uVar2,uVar3,DAT_300b54bc,DAT_300b54b4);
      uVar6 = DAT_300b54c4;
      uVar7 = DAT_300b54c0;
      uVar2 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar12 = __adddf3((int)uVar11,uVar2,DAT_300b54c4,DAT_300b54c0);
      *(undefined8 *)param_3 = uVar12;
      uVar11 = __subdf3((int)uVar11,uVar2,(int)uVar12,(int)((ulonglong)uVar12 >> 0x20));
    }
    else {
      uVar11 = __adddf3(uVar2,uVar3,DAT_300b54b8,DAT_300b54b4);
      *(undefined8 *)param_3 = uVar11;
      uVar11 = __subdf3(uVar2,uVar3,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
    }
    uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar6,uVar7);
    *(undefined8 *)(param_3 + 2) = uVar11;
    return -1;
  }
  iVar9 = (int)uVar10 >> 0x14;
  if (DAT_300b54c8 < (int)uVar10) {
    if (DAT_300b54e8 <= (int)uVar10) {
      uVar11 = __subdf3(param_1,param_2,param_1,param_2);
      *(undefined8 *)(param_3 + 2) = uVar11;
      *(undefined8 *)param_3 = uVar11;
      return 0;
    }
    iVar9 = DAT_300b54ec + iVar9;
    iVar8 = uVar10 + iVar9 * -0x100000;
    local_a0 = 0;
    local_48[0] = param_1;
    local_48[1] = param_2;
    do {
      __fixdfsi(param_1,iVar8);
      uVar11 = __floatsidf();
      uVar10 = (uint)((ulonglong)uVar11 >> 0x20);
      local_48[local_a0 * 2 + 2] = (uint)uVar11;
      local_48[local_a0 * 2 + 3] = uVar10;
      uVar11 = __subdf3(param_1,iVar8,(uint)uVar11,uVar10);
      local_30 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,uVar7);
      iVar8 = (int)((ulonglong)local_30 >> 0x20);
      param_1 = (uint)local_30;
      local_a0 = local_a0 + 1;
    } while (local_a0 < 2);
    local_a0 = 3;
    iVar8 = _d_fne(param_1,iVar8,0);
    if (iVar8 == 0) {
      do {
        local_a0 = local_a0 + -1;
        iVar8 = _d_feq(local_48[local_a0 * 2],local_48[local_a0 * 2 + 1],0);
      } while (iVar8 != 0);
    }
    local_9c = __kernel_rem_pio2(local_48 + 2,param_3,iVar9,local_a0,2,DAT_300b54f4);
    goto LAB_300b5448;
  }
  fabs((double)CONCAT44(in_stack_ffffff54,in_stack_ffffff50));
  uVar11 = __muldf3();
  __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_300b54d4);
  local_9c = __fixdfsi();
  uVar11 = __floatsidf();
  uVar2 = (undefined4)((ulonglong)uVar11 >> 0x20);
  uVar7 = (undefined4)uVar11;
  uVar11 = __muldf3(uVar7,uVar2,DAT_300b54b0,DAT_300b54ac);
  uVar11 = __subdf3(param_1,extraout_r1,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
  uVar3 = (undefined4)((ulonglong)uVar11 >> 0x20);
  uVar6 = (undefined4)uVar11;
  uVar12 = __muldf3(uVar7,uVar2,DAT_300b54b8,DAT_300b54b4);
  if ((local_9c < 0x20) && (*(uint *)(DAT_300b54d8 + local_9c * 4) != uVar10)) {
LAB_300b5298:
    uVar13 = __subdf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
    *(undefined8 *)param_3 = uVar13;
  }
  else {
    uVar13 = __subdf3(uVar6,uVar3,(int)uVar12,(int)((ulonglong)uVar12 >> 0x20));
    *(undefined8 *)param_3 = uVar13;
    if (0x10 < (int)(iVar9 - (DAT_300b54dc & param_3[1] >> 0x14))) {
      uVar12 = __muldf3(uVar7,uVar2,DAT_300b54bc,DAT_300b54b4);
      uVar4 = (undefined4)((ulonglong)uVar12 >> 0x20);
      uVar11 = __subdf3(uVar6,uVar3,(int)uVar12,uVar4);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar1 = (undefined4)uVar11;
      uVar13 = __muldf3(uVar7,uVar2,DAT_300b54c4,DAT_300b54c0);
      uVar14 = __subdf3(uVar6,uVar3,uVar1,uVar5);
      uVar12 = __subdf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar12,uVar4);
      uVar12 = __subdf3((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar12,
                        (int)((ulonglong)uVar12 >> 0x20));
      uVar13 = __subdf3(uVar1,uVar5,(int)uVar12,(int)((ulonglong)uVar12 >> 0x20));
      *(undefined8 *)param_3 = uVar13;
      if (0x31 < (int)(iVar9 - (DAT_300b54dc & (uint)((ulonglong)uVar13 >> 0x34)))) {
        uVar12 = __muldf3(uVar7,uVar2,0x2e000000,DAT_300b54c0);
        uVar6 = (undefined4)((ulonglong)uVar12 >> 0x20);
        uVar11 = __subdf3(uVar1,uVar5,(int)uVar12,uVar6);
        uVar13 = __muldf3(uVar7,uVar2,DAT_300b54e4,DAT_300b54e0);
        uVar14 = __subdf3(uVar1,uVar5,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
        uVar12 = __subdf3((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar12,uVar6);
        uVar12 = __subdf3((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar12,
                          (int)((ulonglong)uVar12 >> 0x20));
        goto LAB_300b5298;
      }
    }
  }
  uVar11 = __subdf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),*param_3,param_3[1]);
  uVar11 = __subdf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                    (int)((ulonglong)uVar12 >> 0x20));
  *(undefined8 *)(param_3 + 2) = uVar11;
LAB_300b5448:
  if ((int)param_2 < 0) {
    *param_3 = *param_3;
    param_3[1] = param_3[1] ^ 0x80000000;
    param_3[2] = param_3[2];
    param_3[3] = param_3[3] ^ 0x80000000;
    local_9c = -local_9c;
  }
  return local_9c;
}

/* ----------------------------------------------------------------
 * __kernel_cos @ 0x300B54F8  (примерный размер ~908 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 4
 * Вызывает: __adddf3, __fixdfsi, __muldf3, __subdf3
 * Вызывают: cos, sin
 * Константы: 0x300B54F8, 0x7FFFFFFF, 0x3E400000, 0x00200000
 * Данные: DAT_300b5840, DAT_300b5844, DAT_300b5848, DAT_300b584c, DAT_300b5850, DAT_300b5854, DAT_300b5858, DAT_300b585c
 * ---------------------------------------------------------------- */
undefined4 __kernel_cos(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  
  uVar5 = param_2 & 0x7fffffff;
  if ((uVar5 < 0x3e400000) && (iVar1 = __fixdfsi(), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar6 = __muldf3(param_1,param_2,param_1,param_2);
    uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
    uVar2 = (undefined4)uVar6;
    uVar6 = __muldf3(uVar2,uVar3,DAT_300b5848,DAT_300b5844);
    uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300b5850,DAT_300b584c);
    uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
    uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300b5858,DAT_300b5854);
    uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
    uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300b5860,DAT_300b585c);
    uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
    uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300b5868,DAT_300b5864);
    uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
    uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300b5870,DAT_300b586c);
    uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
    uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
    if ((int)uVar5 < DAT_300b5874) {
      uVar7 = __muldf3(uVar2,uVar3,0,DAT_300b5878);
      uVar6 = __muldf3(uVar2,uVar3,(int)uVar6,uVar4);
      uVar8 = __muldf3(param_1,param_2,param_3,param_4);
      uVar6 = __subdf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar8,
                       (int)((ulonglong)uVar8 >> 0x20));
      uVar6 = __subdf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar6,
                       (int)((ulonglong)uVar6 >> 0x20));
      lVar9 = (ulonglong)DAT_300b5840 << 0x20;
    }
    else {
      iVar1 = DAT_300b5880;
      if ((int)uVar5 <= DAT_300b587c) {
        iVar1 = uVar5 - 0x200000;
      }
      uVar7 = __muldf3(uVar2,uVar3,0,DAT_300b5878);
      uVar7 = __subdf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,iVar1);
      lVar9 = __subdf3(0,DAT_300b5840,0,iVar1);
      uVar6 = __muldf3(uVar2,uVar3,(int)uVar6,uVar4);
      uVar8 = __muldf3(param_1,param_2,param_3,param_4);
      uVar6 = __subdf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar8,
                       (int)((ulonglong)uVar8 >> 0x20));
      uVar6 = __subdf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar6,
                       (int)((ulonglong)uVar6 >> 0x20));
    }
    uVar2 = __subdf3((int)lVar9,(int)((ulonglong)lVar9 >> 0x20),(int)uVar6,
                     (int)((ulonglong)uVar6 >> 0x20));
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * __kernel_sin @ 0x300B5884  (примерный размер ~708 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 4
 * Вызывает: __adddf3, __fixdfsi, __muldf3, __subdf3
 * Вызывают: cos, sin
 * Константы: 0x300B5884, 0x3E3FFFFF, 0x7FFFFFFF
 * Данные: DAT_300b5b14, DAT_300b5b18, DAT_300b5b1c, DAT_300b5b20, DAT_300b5b24, DAT_300b5b28, DAT_300b5b2c, DAT_300b5b30
 * ---------------------------------------------------------------- */
undefined4
__kernel_sin(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  if ((0x3e3fffff < (param_2 & 0x7fffffff)) ||
     (iVar1 = __fixdfsi(param_1,param_2,param_1,param_2), iVar1 != 0)) {
    uVar7 = __muldf3(param_1,param_2);
    uVar4 = (undefined4)((ulonglong)uVar7 >> 0x20);
    uVar2 = (undefined4)uVar7;
    uVar7 = __muldf3(uVar2,uVar4,param_1,param_2);
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    uVar3 = (undefined4)uVar7;
    uVar7 = __muldf3(uVar2,uVar4,DAT_300b5b18,DAT_300b5b14);
    uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300b5b20,DAT_300b5b1c);
    uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar4);
    uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300b5b28,DAT_300b5b24);
    uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar4);
    uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300b5b30,DAT_300b5b2c);
    uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar4);
    uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300b5b38,DAT_300b5b34);
    uVar6 = (undefined4)((ulonglong)uVar7 >> 0x20);
    if (param_5 == 0) {
      uVar7 = __muldf3(uVar2,uVar4,(int)uVar7,uVar6);
      uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300b5b40,DAT_300b5b3c);
      uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar3,uVar5);
      param_1 = __adddf3(param_1,param_2,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
    }
    else {
      uVar8 = __muldf3(param_3,param_4,0,DAT_300b5b44);
      uVar7 = __muldf3(uVar3,uVar5,(int)uVar7,uVar6);
      uVar7 = __subdf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,
                       (int)((ulonglong)uVar7 >> 0x20));
      uVar7 = __muldf3(uVar2,uVar4,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
      uVar8 = __muldf3(uVar3,uVar5,DAT_300b5b40,DAT_300b5b3c);
      uVar7 = __subdf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),param_3,param_4);
      uVar7 = __subdf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                       (int)((ulonglong)uVar8 >> 0x20));
      param_1 = __subdf3(param_1,param_2,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
    }
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * __kernel_tan @ 0x300B5B48  (примерный размер ~1880 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 7
 * Вызывает: __adddf3, __divdf3, __fixdfsi, __floatsidf, __muldf3, __subdf3, fabs
 * Вызывают: tan
 * Константы: 0x80000000, 0x300B5B48, 0x7FFFFFFF, 0x40000000
 * Данные: DAT_300b6218, DAT_300b621c, DAT_300b6220, DAT_300b6224, DAT_300b6228, DAT_300b622c, DAT_300b6230, DAT_300b6234
 * ---------------------------------------------------------------- */
int __kernel_tan(int param_1,uint param_2,undefined4 param_3,uint param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  double in_stack_ffffff74;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  uint local_4;
  
  uVar7 = CONCAT44(param_2,param_1);
  uVar6 = param_2 & 0x7fffffff;
  local_8 = param_3;
  local_4 = param_4;
  if ((int)uVar6 < DAT_300b6218) {
    iVar1 = __fixdfsi();
    uVar7 = CONCAT44(param_2,param_1);
    if (iVar1 == 0) {
      if ((uVar6 == 0 && param_1 == 0) && param_5 == -1) {
        fabs(in_stack_ffffff74);
        iVar1 = __divdf3(0,DAT_300b621c,param_1,extraout_r1);
        return iVar1;
      }
      if (param_5 == 1) {
        return param_1;
      }
      iVar1 = __divdf3(0,DAT_300b6220);
      return iVar1;
    }
  }
  else if (DAT_300b6224 <= (int)uVar6) {
    local_c = param_2;
    if ((int)param_2 < 0) {
      local_c = param_2 ^ 0x80000000;
      local_4 = param_4 ^ 0x80000000;
    }
    uVar7 = __subdf3(DAT_300b622c,DAT_300b6228,param_1,local_c);
    uVar8 = __subdf3(DAT_300b6234,DAT_300b6230,param_3,local_4);
    uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                     (int)((ulonglong)uVar8 >> 0x20));
    local_8 = 0;
    local_4 = 0;
  }
  local_c = (uint)((ulonglong)uVar7 >> 0x20);
  local_10 = (undefined4)uVar7;
  uVar7 = __muldf3(local_10,local_c);
  uVar4 = (undefined4)((ulonglong)uVar7 >> 0x20);
  uVar2 = (undefined4)uVar7;
  uVar7 = __muldf3(uVar2,uVar4,uVar2,uVar4);
  uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
  uVar3 = (undefined4)uVar7;
  uVar7 = __muldf3(uVar3,uVar5,DAT_300b623c,DAT_300b6238);
  uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300b6244,DAT_300b6240);
  uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar3,uVar5);
  uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300b624c,DAT_300b6248);
  uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar3,uVar5);
  uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300b6254,DAT_300b6250);
  uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar3,uVar5);
  uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300b625c,DAT_300b6258);
  uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar3,uVar5);
  uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300b6264,DAT_300b6260);
  uVar8 = __muldf3(uVar3,uVar5,DAT_300b626c,DAT_300b6268);
  uVar8 = __adddf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_300b6274,DAT_300b6270);
  uVar8 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar3,uVar5);
  uVar8 = __adddf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_300b627c,DAT_300b6278);
  uVar8 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar3,uVar5);
  uVar8 = __adddf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_300b6284,DAT_300b6280);
  uVar8 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar3,uVar5);
  uVar8 = __adddf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_300b628c,DAT_300b6288);
  uVar8 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar3,uVar5);
  uVar8 = __adddf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_300b6294,DAT_300b6290);
  uVar8 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar2,uVar4);
  uVar9 = __muldf3(uVar2,uVar4);
  uVar3 = (undefined4)((ulonglong)uVar9 >> 0x20);
  uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                   (int)((ulonglong)uVar8 >> 0x20));
  __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar9,uVar3);
  uVar7 = __adddf3();
  uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar4);
  uVar7 = __adddf3(local_8,local_4,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
  uVar8 = __muldf3((int)uVar9,uVar3,DAT_300b629c,DAT_300b6298);
  uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                   (int)((ulonglong)uVar8 >> 0x20));
  uVar3 = (undefined4)((ulonglong)uVar7 >> 0x20);
  uVar2 = (undefined4)uVar7;
  uVar7 = __adddf3(local_10,local_c,uVar2,uVar3);
  uVar4 = (undefined4)((ulonglong)uVar7 >> 0x20);
  iVar1 = (int)uVar7;
  if ((int)uVar6 < DAT_300b6224) {
    if (param_5 != 1) {
      uVar7 = __subdf3(0,uVar4,local_10,local_c);
      uVar7 = __subdf3(uVar2,uVar3,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
      uVar8 = __divdf3(0,DAT_300b6220,iVar1,uVar4);
      uVar2 = (undefined4)((ulonglong)uVar8 >> 0x20);
      uVar9 = __muldf3(0,uVar2,0,uVar4);
      uVar9 = __adddf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,DAT_300b621c);
      uVar7 = __muldf3(0,uVar2,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
      uVar7 = __adddf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),(int)uVar7,
                       (int)((ulonglong)uVar7 >> 0x20));
      uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,uVar2);
      iVar1 = __adddf3(0,uVar2,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
    }
  }
  else {
    uVar7 = __floatsidf(param_5);
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    uVar8 = __muldf3(iVar1,uVar4,iVar1,uVar4);
    uVar9 = __adddf3(iVar1,uVar4,(int)uVar7,uVar5);
    uVar8 = __divdf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar9,
                     (int)((ulonglong)uVar9 >> 0x20));
    uVar8 = __subdf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar2,uVar3);
    uVar8 = __subdf3(local_10,local_c,(int)uVar8,(int)((ulonglong)uVar8 >> 0x20));
    uVar8 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,0x40000000);
    uVar7 = __subdf3((int)uVar7,uVar5,(int)uVar8,(int)((ulonglong)uVar8 >> 0x20));
    uVar8 = __floatsidf(1 - ((int)param_2 >> 0x1e & 2U));
    iVar1 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,
                     (int)((ulonglong)uVar7 >> 0x20));
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * __kernel_rem_pio2 @ 0x300B62A0  (примерный размер ~3608 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 10
 * Вызывает: __adddf3, __div32, __fixdfsi, __floatsidf, __muldf3, __subdf3, _d_fne, _d_fnge, floor, scalbn
 * Вызывают: __ieee754_rem_pio2
 * Константы: 0x80000000, 0x300B62A0, 0x00FFFFFF, 0x01000000
 * Данные: DAT_300b7090, DAT_300b7094, DAT_300b7098, DAT_300b709c, DAT_300b70a4, DAT_300b70a8, DAT_300b70ac, DAT_300b70b0
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

uint __kernel_rem_pio2(int param_1,undefined8 *param_2,int param_3,int param_4,int param_5,
                      int param_6)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  double in_stack_fffffd3c;
  int local_2bc;
  int local_2b8;
  int local_2ac;
  uint local_2a4;
  int local_2a0;
  int local_29c;
  int local_298;
  int local_294;
  uint local_268 [19];
  uint auStack_21c [4];
  undefined4 local_20c;
  uint local_208;
  int aiStack_17c [42];
  undefined4 auStack_d4 [40];
  
  iVar13 = *(int *)(DAT_300b7090 + param_5 * 4);
  param_4 = param_4 + -1;
  iVar2 = __div32(param_3 + -3,0x18);
  local_298 = 0;
  if (-1 < iVar2) {
    local_298 = iVar2;
  }
  param_3 = param_3 - (local_298 * 0x18 + 0x18);
  local_2a4 = local_298 - param_4;
  local_2bc = 0;
  if (-1 < param_4 + iVar13) {
    do {
      if ((int)local_2a4 < 0) {
        uVar15 = *DAT_300b7094;
      }
      else {
        uVar15 = __floatsidf(*(undefined4 *)(param_6 + local_2a4 * 4));
      }
      auStack_d4[local_2bc * 2] = (int)uVar15;
      auStack_d4[local_2bc * 2 + 1] = (int)((ulonglong)uVar15 >> 0x20);
      local_2bc = local_2bc + 1;
      local_2a4 = local_2a4 + 1;
    } while (local_2bc <= param_4 + iVar13);
  }
  local_2bc = 0;
  iVar2 = iVar13;
  if (-1 < iVar13) {
    do {
      local_2a4 = 0;
      uVar15 = 0;
      uVar16 = 0;
      if (-1 < param_4) {
        do {
          puVar12 = (undefined4 *)(param_1 + local_2a4 * 8);
          iVar14 = (param_4 + local_2bc) - local_2a4;
          uVar16 = __muldf3(*puVar12,puVar12[1],auStack_d4[iVar14 * 2],auStack_d4[iVar14 * 2 + 1]);
          uVar15 = __adddf3((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(int)uVar16,
                            (int)((ulonglong)uVar16 >> 0x20));
          local_2a4 = local_2a4 + 1;
          uVar16 = uVar15;
        } while ((int)local_2a4 <= param_4);
      }
      aiStack_17c[local_2bc * 2 + 2] = (int)uVar16;
      aiStack_17c[local_2bc * 2 + 3] = (int)((ulonglong)uVar16 >> 0x20);
      local_2bc = local_2bc + 1;
    } while (local_2bc <= iVar13);
  }
  do {
    local_2bc = iVar2;
    uVar5 = DAT_300b709c;
    uVar4 = DAT_300b7098;
    local_2a4 = 0;
    iVar2 = aiStack_17c[local_2bc * 2 + 2];
    uVar15 = CONCAT44(aiStack_17c[local_2bc * 2 + 3],iVar2);
    for (iVar14 = local_2bc; 0 < iVar14; iVar14 = iVar14 + -1) {
      uVar10 = (undefined4)((ulonglong)uVar15 >> 0x20);
      __muldf3((int)uVar15,uVar10,0,uVar5);
      __fixdfsi();
      uVar16 = __floatsidf();
      uVar7 = (uint)((ulonglong)uVar16 >> 0x20);
      local_268[0] = uVar7;
      uVar17 = __muldf3((int)uVar16,uVar7,0,uVar4);
      __subdf3((int)uVar15,uVar10,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
      uVar3 = __fixdfsi();
      local_268[local_2a4 + 1] = uVar3;
      uVar15 = __adddf3(aiStack_17c[iVar14 * 2],aiStack_17c[iVar14 * 2 + 1],(int)uVar16,uVar7);
      iVar2 = (int)uVar15;
      local_2a4 = local_2a4 + 1;
    }
    scalbn(in_stack_fffffd3c,iVar2);
    __muldf3();
    floor(in_stack_fffffd3c);
    uVar15 = __muldf3();
    uVar15 = __subdf3(iVar2,extraout_r1,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
    local_2a4 = __fixdfsi();
    uVar16 = __floatsidf();
    uVar15 = __subdf3((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(int)uVar16,
                      (int)((ulonglong)uVar16 >> 0x20));
    uVar4 = (undefined4)((ulonglong)uVar15 >> 0x20);
    local_2ac = 0;
    if (param_3 < 1) {
      if (param_3 == 0) {
        local_2ac = (int)local_268[local_2bc] >> 0x17;
        goto LAB_300b66d8;
      }
      iVar2 = _d_fnge((int)uVar15,uVar4,0,DAT_300b70a4);
      if (iVar2 == 0) {
        local_2ac = 2;
        goto LAB_300b66d8;
      }
    }
    else {
      iVar2 = (int)local_268[local_2bc] >> (0x18U - param_3 & 0xff);
      local_2a4 = local_2a4 + iVar2;
      uVar3 = local_268[local_2bc] - (iVar2 << (0x18U - param_3 & 0xff));
      local_268[local_2bc] = uVar3;
      local_2ac = (int)uVar3 >> (0x17U - param_3 & 0xff);
LAB_300b66d8:
      if (0 < local_2ac) {
        local_2a4 = local_2a4 + 1;
        bVar1 = false;
        if (0 < local_2bc) {
          puVar6 = local_268;
          local_294 = local_2bc;
          do {
            puVar6 = puVar6 + 1;
            if (bVar1) {
              iVar2 = 0xffffff;
LAB_300b6740:
              *puVar6 = iVar2 - *puVar6;
            }
            else if (*puVar6 != 0) {
              bVar1 = true;
              iVar2 = 0x1000000;
              goto LAB_300b6740;
            }
            local_294 = local_294 + -1;
          } while (local_294 != 0);
        }
        if (0 < param_3) {
          if (param_3 == 1) {
            local_268[local_2bc] = local_268[local_2bc] & DAT_300b70a8;
          }
          else if (param_3 == 2) {
            local_268[local_2bc] = local_268[local_2bc] & DAT_300b70ac;
          }
        }
        if (local_2ac == 2) {
          uVar15 = __subdf3(0,DAT_300b70b0,(int)uVar15,uVar4);
          if (bVar1) {
            uVar4 = 0;
            scalbn(in_stack_fffffd3c,0);
            uVar15 = __subdf3((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),uVar4,extraout_r1_00);
          }
        }
      }
    }
    uVar4 = (undefined4)((ulonglong)uVar15 >> 0x20);
    iVar14 = (int)uVar15;
    iVar2 = _d_fne(iVar14,uVar4,0);
    if (iVar2 != 0) {
LAB_300b69d4:
      iVar2 = _d_fne(iVar14,uVar4,0);
      if (iVar2 == 0) {
        iVar2 = local_2bc + -1;
        if (local_268[local_2bc] == 0) {
          puVar6 = local_268 + local_2bc;
          local_2bc = local_2bc + -1;
          do {
            puVar6 = puVar6 + -1;
            local_2bc = local_2bc + -1;
            iVar2 = local_2bc;
          } while (*puVar6 == 0);
        }
      }
      else {
        scalbn(in_stack_fffffd3c,iVar14);
        uVar15 = CONCAT44(extraout_r1_01,iVar14);
        iVar2 = _d_fnge();
        if (iVar2 == 0) {
          __muldf3(iVar14,extraout_r1_01,0,DAT_300b709c);
          __fixdfsi();
          uVar15 = __floatsidf();
          uVar16 = __muldf3((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0,DAT_300b7098);
          __subdf3(iVar14,extraout_r1_01,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
          uVar3 = __fixdfsi();
          local_268[local_2bc + 1] = uVar3;
          local_2bc = local_2bc + 1;
        }
        uVar3 = __fixdfsi((int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
        local_268[local_2bc + 1] = uVar3;
        iVar2 = local_2bc;
      }
      local_2bc = iVar2;
      uVar5 = 0;
      scalbn(in_stack_fffffd3c,0);
      uVar4 = DAT_300b709c;
      uVar15 = CONCAT44(extraout_r1_02,uVar5);
      for (iVar2 = local_2bc; iVar14 = local_2bc, -1 < iVar2; iVar2 = iVar2 + -1) {
        uVar5 = (undefined4)((ulonglong)uVar15 >> 0x20);
        uVar16 = __floatsidf(local_268[iVar2 + 1]);
        uVar16 = __muldf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar15,uVar5);
        aiStack_17c[iVar2 * 2 + 2] = (int)uVar16;
        aiStack_17c[iVar2 * 2 + 3] = (int)((ulonglong)uVar16 >> 0x20);
        uVar15 = __muldf3((int)uVar15,uVar5,0,uVar4);
      }
      do {
        if (iVar14 < 0) {
          if (param_5 == 0) {
            uVar15 = 0;
            while( true ) {
              uVar3 = (uint)((ulonglong)uVar15 >> 0x20);
              if (local_2bc < 0) break;
              uVar15 = __adddf3((int)uVar15,uVar3,auStack_21c[local_2bc * 2 + 2],
                                auStack_21c[local_2bc * 2 + 3]);
              local_2bc = local_2bc + -1;
            }
            if (local_2ac == 0) {
              *param_2 = uVar15;
            }
            else {
              *(int *)param_2 = (int)uVar15;
              *(uint *)((int)param_2 + 4) = uVar3 ^ 0x80000000;
            }
          }
          else if ((param_5 == 1) || (param_5 == 2)) {
            uVar15 = 0;
            iVar2 = local_2bc;
            while( true ) {
              uVar3 = (uint)((ulonglong)uVar15 >> 0x20);
              uVar4 = (undefined4)uVar15;
              if (iVar2 < 0) break;
              uVar15 = __adddf3(uVar4,uVar3,auStack_21c[iVar2 * 2 + 2],auStack_21c[iVar2 * 2 + 3]);
              iVar2 = iVar2 + -1;
            }
            uVar7 = uVar3;
            if (local_2ac != 0) {
              uVar7 = uVar3 ^ 0x80000000;
            }
            *(undefined4 *)param_2 = uVar4;
            *(uint *)((int)param_2 + 4) = uVar7;
            uVar15 = __subdf3(auStack_21c[2],auStack_21c[3],uVar4,uVar3);
            local_29c = 1;
            if (0 < local_2bc) {
              do {
                uVar15 = __adddf3((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),
                                  auStack_21c[local_29c * 2 + 2],auStack_21c[local_29c * 2 + 3]);
                local_29c = local_29c + 1;
              } while (local_29c <= local_2bc);
            }
            if (local_2ac == 0) {
              param_2[1] = uVar15;
            }
            else {
              *(int *)(param_2 + 1) = (int)uVar15;
              *(uint *)((int)param_2 + 0xc) = (uint)((ulonglong)uVar15 >> 0x20) ^ 0x80000000;
            }
          }
          else {
            iVar2 = local_2bc;
            if (param_5 == 3) {
              for (; iVar13 = local_2bc, 0 < iVar2; iVar2 = iVar2 + -1) {
                uVar9 = auStack_21c[iVar2 * 2];
                uVar11 = auStack_21c[iVar2 * 2 + 1];
                uVar7 = auStack_21c[iVar2 * 2 + 2];
                uVar8 = auStack_21c[iVar2 * 2 + 3];
                uVar15 = __adddf3(uVar9,uVar11,uVar7,uVar8);
                uVar3 = (uint)((ulonglong)uVar15 >> 0x20);
                uVar16 = __subdf3(uVar9,uVar11,(uint)uVar15,uVar3);
                uVar16 = __adddf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar7,uVar8);
                auStack_21c[iVar2 * 2 + 2] = (uint)uVar16;
                auStack_21c[iVar2 * 2 + 3] = (uint)((ulonglong)uVar16 >> 0x20);
                auStack_21c[iVar2 * 2] = (uint)uVar15;
                auStack_21c[iVar2 * 2 + 1] = uVar3;
              }
              for (; 1 < iVar13; iVar13 = iVar13 + -1) {
                uVar9 = auStack_21c[iVar13 * 2];
                uVar11 = auStack_21c[iVar13 * 2 + 1];
                uVar7 = auStack_21c[iVar13 * 2 + 2];
                uVar8 = auStack_21c[iVar13 * 2 + 3];
                uVar15 = __adddf3(uVar9,uVar11,uVar7,uVar8);
                uVar3 = (uint)((ulonglong)uVar15 >> 0x20);
                uVar16 = __subdf3(uVar9,uVar11,(uint)uVar15,uVar3);
                uVar16 = __adddf3((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar7,uVar8);
                auStack_21c[iVar13 * 2 + 2] = (uint)uVar16;
                auStack_21c[iVar13 * 2 + 3] = (uint)((ulonglong)uVar16 >> 0x20);
                auStack_21c[iVar13 * 2] = (uint)uVar15;
                auStack_21c[iVar13 * 2 + 1] = uVar3;
              }
              uVar15 = 0;
              while( true ) {
                uVar3 = (uint)((ulonglong)uVar15 >> 0x20);
                if (local_2bc < 2) break;
                uVar15 = __adddf3((int)uVar15,uVar3,auStack_21c[local_2bc * 2 + 2],
                                  auStack_21c[local_2bc * 2 + 3]);
                local_2bc = local_2bc + -1;
              }
              if (local_2ac == 0) {
                *(uint *)param_2 = auStack_21c[2];
                *(uint *)((int)param_2 + 4) = auStack_21c[3];
                *(undefined4 *)(param_2 + 1) = local_20c;
                *(uint *)((int)param_2 + 0xc) = local_208;
              }
              else {
                *(uint *)param_2 = auStack_21c[2];
                *(uint *)((int)param_2 + 4) = auStack_21c[3] ^ 0x80000000;
                *(undefined4 *)(param_2 + 1) = local_20c;
                *(uint *)((int)param_2 + 0xc) = local_208 ^ 0x80000000;
                uVar3 = uVar3 ^ 0x80000000;
              }
              *(int *)(param_2 + 2) = (int)uVar15;
              *(uint *)((int)param_2 + 0x14) = uVar3;
            }
          }
          return local_2a4 & 7;
        }
        local_2b8 = 0;
        uVar15 = 0;
        uVar16 = 0;
        if (-1 < iVar13) {
          do {
            uVar16 = uVar15;
            if (local_2bc - iVar14 < local_2b8) break;
            puVar12 = (undefined4 *)(DAT_300b70b4 + local_2b8 * 8);
            uVar16 = __muldf3(*puVar12,puVar12[1],aiStack_17c[(iVar14 + local_2b8) * 2 + 2],
                              aiStack_17c[(iVar14 + local_2b8) * 2 + 3]);
            uVar15 = __adddf3((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(int)uVar16,
                              (int)((ulonglong)uVar16 >> 0x20));
            local_2b8 = local_2b8 + 1;
            uVar16 = uVar15;
          } while (local_2b8 <= iVar13);
        }
        auStack_21c[(local_2bc - iVar14) * 2 + 2] = (uint)uVar16;
        auStack_21c[(local_2bc - iVar14) * 2 + 3] = (uint)((ulonglong)uVar16 >> 0x20);
        iVar14 = iVar14 + -1;
      } while( true );
    }
    uVar3 = 0;
    if (iVar13 <= local_2bc + -1) {
      puVar6 = local_268 + local_2bc + 1;
      iVar2 = (local_2bc + -1) - iVar13;
      do {
        puVar6 = puVar6 + -1;
        iVar2 = iVar2 + -1;
        uVar3 = uVar3 | *puVar6;
      } while (-1 < iVar2);
      if (uVar3 != 0) goto LAB_300b69d4;
    }
    local_2a4 = 1;
    local_2ac = local_2bc;
    if (local_268[iVar13] == 0) {
      puVar6 = local_268 + iVar13;
      do {
        puVar6 = puVar6 + -1;
        local_2a4 = local_2a4 + 1;
      } while (*puVar6 == 0);
    }
    while (local_2ac = local_2ac + 1, local_2ac <= (int)(local_2bc + local_2a4)) {
      uVar15 = __floatsidf(*(undefined4 *)(param_6 + (local_298 + local_2ac) * 4));
      auStack_d4[(param_4 + local_2ac) * 2] = (int)uVar15;
      auStack_d4[(param_4 + local_2ac) * 2 + 1] = (int)((ulonglong)uVar15 >> 0x20);
      local_2a0 = 0;
      uVar15 = 0;
      uVar16 = 0;
      if (-1 < param_4) {
        do {
          puVar12 = (undefined4 *)(param_1 + local_2a0 * 8);
          iVar2 = (param_4 + local_2ac) - local_2a0;
          uVar16 = __muldf3(*puVar12,puVar12[1],auStack_d4[iVar2 * 2],auStack_d4[iVar2 * 2 + 1]);
          uVar15 = __adddf3((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(int)uVar16,
                            (int)((ulonglong)uVar16 >> 0x20));
          local_2a0 = local_2a0 + 1;
          uVar16 = uVar15;
        } while (local_2a0 <= param_4);
      }
      aiStack_17c[local_2ac * 2 + 2] = (int)uVar16;
      aiStack_17c[local_2ac * 2 + 3] = (int)((ulonglong)uVar16 >> 0x20);
    }
    iVar2 = local_2bc + local_2a4;
  } while( true );
}

/* ----------------------------------------------------------------
 * __negdf2 @ 0x300B70B8  (примерный размер ~8 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300B70B8
 * ---------------------------------------------------------------- */
void __negdf2(void)

{
  return;
}

/* ----------------------------------------------------------------
 * __negsf2 @ 0x300B70C0  (примерный размер ~8 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300B70C0, 0x80000000
 * ---------------------------------------------------------------- */
uint __negsf2(uint param_1)

{
  return param_1 ^ 0x80000000;
}

/* ----------------------------------------------------------------
 * __truncdfsf2 @ 0x300B70D8  (примерный размер ~452 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 4
 * Вызывает: __fpl_exception, __funder, __rt_fp_status_addr, _fp_trap
 * Вызывают: FUN_300c505c, FUN_3010cc3c
 * Константы: 0x00100000, 0x40000000, 0x80000000, 0x00800000, 0x20000000, 0x300B70D8, 0x300B9228, 0x7FFFFFFF
 * Данные: DAT_300b7294
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300b9228) */

uint __truncdfsf2(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  
  uVar5 = param_2 & 0x80000000;
  uVar2 = param_2 & 0x7fffffff;
  uVar4 = uVar2 ^ uVar2 << 1;
  if ((uVar4 & 0x7f000000) == 0 && (uVar4 & 0xe00000) == 0) {
    if ((param_2 & 0x100000) != 0) {
      if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
        return uVar5 - 0x800000 ^ 0x80000000;
      }
      if ((param_2 & 0x80000) != 0) {
        return DAT_300b7294;
      }
      uVar2 = __fpl_exception(param_1);
      return uVar2;
    }
    if (param_1 == 0 && uVar2 == 0) {
      return uVar5;
    }
    puVar1 = (uint *)__rt_fp_status_addr();
    if ((*puVar1 & 0x800) == 0) {
      uVar2 = 0x100000;
    }
    else {
      iVar6 = 0;
      if (uVar2 == 0) {
        uVar2 = param_1 >> 0xb;
        param_1 = param_1 << 0x15;
        iVar6 = -0x1500000;
      }
      if (uVar2 >> 5 == 0) {
        uVar2 = uVar2 << 0x10 | param_1 >> 0x10;
        param_1 = param_1 << 0x10;
        iVar6 = iVar6 + -0x1000000;
      }
      if (uVar2 >> 0xd == 0) {
        uVar2 = uVar2 << 8 | param_1 >> 0x18;
        param_1 = param_1 << 8;
        iVar6 = iVar6 + -0x800000;
      }
      if (uVar2 >> 0x11 == 0) {
        uVar2 = uVar2 << 4 | param_1 >> 0x1c;
        param_1 = param_1 << 4;
        iVar6 = iVar6 + -0x400000;
      }
      if (uVar2 >> 0x13 == 0) {
        uVar2 = uVar2 << 2 | param_1 >> 0x1e;
        param_1 = param_1 << 2;
        iVar6 = iVar6 + -0x200000;
      }
      if (uVar2 >> 0x14 == 0) {
        uVar2 = uVar2 << 1 | param_1 >> 0x1f;
        param_1 = param_1 << 1;
        iVar6 = iVar6 + -0x100000;
      }
      uVar2 = uVar2 + iVar6;
    }
  }
  iVar6 = -0x40000000;
  bVar8 = (bool)((byte)(param_1 >> 0x1c) & 1);
  bVar7 = (param_1 & 0xfffffff) == 0;
  if (!bVar8 || bVar7) {
    if (!bVar8) {
      if (bVar7) {
        iVar6 = 0;
      }
      goto LAB_300b7120;
    }
    iVar6 = (param_1 & 0x20000000) * 4 + -0x40000000;
    if (iVar6 < 0) goto LAB_300b7120;
  }
  iVar6 = 0x40000000;
  bVar7 = 0xdfffffff < param_1;
  param_1 = param_1 + 0x20000000;
  uVar2 = uVar2 + bVar7;
LAB_300b7120:
  iVar3 = uVar2 + 0xc8000000;
  if (0xfffff < iVar3) {
    if (iVar3 < 0xff00000) {
      return uVar5 | iVar3 * 8 | param_1 >> 0x1d;
    }
    uVar2 = __fpl_exception(param_1 & 0xe0000000,uVar2 + 0xf4000000 | uVar5);
    return uVar2;
  }
  uVar2 = uVar2 + 0xd4000000;
  puVar1 = (uint *)__rt_fp_status_addr();
  if ((*puVar1 & 0x800) != 0) {
    uVar2 = _fp_trap();
    return uVar2;
  }
  if ((int)uVar2 < 0x100000) {
    uVar2 = uVar2 & 0xffffff;
  }
  uVar2 = __funder(uVar5 | uVar2 << 3 | param_1 >> 0x1d,uVar2,iVar6);
  return uVar2;
}

/* ----------------------------------------------------------------
 * __fpl_dcheck_NaN2 @ 0x300B729C  (примерный размер ~64 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: __fpl_exception, __fpl_return_NaN
 * Константы: 0x00100000, 0x300B729C, 0xFFF00001, 0xFFF00000
 * ---------------------------------------------------------------- */
void __fpl_dcheck_NaN2(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 * 2 + 0x100000 + (uint)(param_1 != 0);
  uVar1 = uVar2;
  if (uVar2 < 0xfff00001) {
    uVar1 = param_4 * 2 + 0x100000 + (uint)(param_3 != 0);
  }
  if (0xfff00000 < uVar1) {
    __fpl_exception();
    return;
  }
  if (0xfffff < uVar2) {
    param_1 = param_3;
    param_2 = param_4;
  }
  __fpl_return_NaN(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * __cmpdf2 @ 0x300B7354  (примерный размер ~24 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: _dcmpeq
 * Константы: 0x300B7354, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4 __cmpdf2(void)

{
  undefined4 uVar1;
  undefined1 in_ZR;
  undefined1 in_CY;
  
  uVar1 = _dcmpeq();
  if (!(bool)in_CY) {
    uVar1 = 0xfffffffe;
  }
  if ((bool)in_ZR) {
    uVar1 = 0;
  }
  if ((bool)in_CY && !(bool)in_ZR) {
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * __fpl_dcmp_InfNaN @ 0x300B736C  (примерный размер ~92 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 2
 * Вызывает: __fpl_exception, __fpl_return_NaN
 * Вызывают: _dcmpeq, _dcmpge, _dcmple
 * Константы: 0xFFE00000, 0x00100000, 0x300B736C, 0xFFF00001, 0xFFF00000
 * Данные: DAT_300b73c4
 * ---------------------------------------------------------------- */
void __fpl_dcmp_InfNaN(int param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int in_r12;
  bool bVar3;
  bool bVar4;
  
  uVar1 = param_2 * 2;
  bVar3 = uVar1 == 0xffe00000 && param_1 == 0;
  if (uVar1 < 0xffe00000 || uVar1 == 0xffe00000 && param_1 == 0) {
    uVar1 = param_4 * 2;
    bVar3 = uVar1 == 0xffe00000;
  }
  bVar4 = bVar3;
  if (bVar3) {
    bVar4 = param_3 == 0;
  }
  if (!bVar3 && uVar1 < 0xffe00000 || bVar4) {
    if ((int)(param_2 | param_4) < 0) {
      return;
    }
    return;
  }
  if (in_r12 != DAT_300b73c4) {
    __fpl_exception();
    return;
  }
  uVar2 = param_2 * 2 + 0x100000 + (uint)(param_1 != 0);
  uVar1 = uVar2;
  if (uVar2 < 0xfff00001) {
    uVar1 = param_4 * 2 + 0x100000 + (uint)(param_3 != 0);
  }
  if (0xfff00000 < uVar1) {
    __fpl_exception();
    return;
  }
  if (0xfffff < uVar2) {
    param_1 = param_3;
    param_2 = param_4;
  }
  __fpl_return_NaN(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * __divdf3 @ 0x300B73E8  (примерный размер ~668 байт)
 * Модуль: lib | Вызывают: 16 | Вызывает: 5
 * Вызывает: __fpl_exception, __fpl_return_NaN, __rt_fp_status_addr, _fp_trapveneer, ddiv_mantissas
 * Вызывают: FUN_300c4638, FUN_300c505c, __kernel_tan, acos, asin, atan, atan2, cosh, exp, expm1
 *           ...
 * Константы: 0x7FFFFFFF, 0x80000000, 0x00100000, 0x00130000, 0x00140000, 0xFFFFFFFE, 0xC0000000, 0x04000000
 * Данные: DAT_300b7960
 * ---------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __divdf3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  ulonglong uVar14;
  
  if ((ram0x300b795c & ~(param_2 >> 4)) == 0 || (ram0x300b795c & ~(param_4 >> 4)) == 0) {
    uVar5 = param_2 * 2;
    uVar6 = ram0x300b795c * 0x20;
    bVar12 = uVar5 == uVar6;
    bVar11 = bVar12 && param_1 == 0;
    bVar13 = bVar12 || uVar6 <= uVar5;
    if (!bVar12 && uVar6 > uVar5 || bVar12 && param_1 == 0) {
      bVar13 = ram0x300b795c * 0x20 <= param_4 * 2;
      bVar11 = param_4 * 2 == ram0x300b795c * 0x20;
    }
    if (bVar11) {
      bVar11 = param_3 == 0;
      bVar13 = true;
    }
    if (bVar13 && !bVar11) {
      uVar6 = param_2 * 2 + 0x100000 + (uint)(param_1 != 0);
      uVar5 = uVar6;
      if (uVar6 < 0xfff00001) {
        uVar5 = param_4 * 2 + 0x100000 + (uint)(param_3 != 0);
      }
      if (0xfff00000 < uVar5) {
        uVar5 = __fpl_exception();
        return uVar5;
      }
      if (0xfffff < uVar6) {
        param_1 = param_3;
        param_2 = param_4;
      }
      uVar5 = __fpl_return_NaN(param_1,param_2);
      return uVar5;
    }
    if ((ram0x300b795c & ~(param_2 >> 4)) != 0) {
      return 0;
    }
    if ((ram0x300b795c & ~(param_4 >> 4)) != 0) {
      return param_1;
    }
LAB_300b7678:
    uVar5 = __fpl_exception();
    return uVar5;
  }
  uVar5 = ram0x300b795c & param_2 >> 4;
  uVar6 = uVar5 | (param_2 ^ param_4) >> 0x1f;
  uVar10 = ram0x300b795c & param_4 >> 4;
  if (uVar10 == 0 || (param_2 & ram0x300b795c << 4) == 0) {
    if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) {
      if (param_3 != 0 || (param_4 & 0x7fffffff) != 0) {
        return param_1;
      }
      goto LAB_300b7678;
    }
    if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) {
      uVar5 = __fpl_exception();
      return uVar5;
    }
    if (uVar10 == 0) {
      iVar9 = 0x10000;
      param_4 = param_4 & 0x7fffffff;
      if (param_4 == 0 && param_3 >> 0xc == 0) {
        param_3 = param_3 << 0x14;
        iVar9 = -0x130000;
      }
      uVar4 = param_3;
      if (param_4 == 0) {
        param_4 = param_3 >> 0xc;
        uVar4 = param_3 << 0x14;
        iVar9 = iVar9 + -0x140000;
      }
      uVar1 = 0;
      if (param_4 >> 5 == 0) {
        param_4 = param_4 << 0x10;
        uVar1 = 0x10;
      }
      if (param_4 >> 0xd == 0) {
        param_4 = param_4 << 8;
        uVar1 = uVar1 + 8;
      }
      if (param_4 >> 0x11 == 0) {
        param_4 = param_4 << 4;
        uVar1 = uVar1 + 4;
      }
      if (param_4 >> 0x13 == 0) {
        param_4 = param_4 << 2;
        uVar1 = uVar1 + 2;
      }
      if (param_4 >> 0x14 == 0) {
        param_4 = 0;
        uVar1 = uVar1 + 1;
      }
      uVar10 = iVar9 + uVar1 * -0x10000;
      param_3 = uVar4 << (uVar1 & 0xff);
      param_4 = param_4 | uVar4 >> (0x20 - uVar1 & 0xff);
    }
    if ((uVar5 & 0xfffffffe) == 0) {
      iVar9 = uVar6 + 0x10000;
      param_2 = param_2 & 0x7fffffff;
      if (param_2 == 0 && param_1 >> 0xc == 0) {
        param_1 = param_1 << 0x14;
        iVar9 = uVar6 - 0x130000;
      }
      uVar5 = param_1;
      if (param_2 == 0) {
        param_2 = param_1 >> 0xc;
        uVar5 = param_1 << 0x14;
        iVar9 = iVar9 + -0x140000;
      }
      uVar4 = 0;
      if (param_2 >> 5 == 0) {
        param_2 = param_2 << 0x10;
        uVar4 = 0x10;
      }
      if (param_2 >> 0xd == 0) {
        param_2 = param_2 << 8;
        uVar4 = uVar4 + 8;
      }
      if (param_2 >> 0x11 == 0) {
        param_2 = param_2 << 4;
        uVar4 = uVar4 + 4;
      }
      if (param_2 >> 0x13 == 0) {
        param_2 = param_2 << 2;
        uVar4 = uVar4 + 2;
      }
      if (param_2 >> 0x14 == 0) {
        param_2 = param_2 << 1;
        uVar4 = uVar4 + 1;
      }
      uVar6 = iVar9 + uVar4 * -0x10000;
      param_1 = uVar5 << (uVar4 & 0xff);
      param_2 = param_2 | uVar5 >> (0x20 - uVar4 & 0xff);
    }
  }
  iVar7 = uVar6 - uVar10;
  iVar8 = iVar7 + 0x3fc0000;
  uVar10 = param_4 << 0xb | param_3 >> 0x15;
  iVar9 = param_3 << 0xb;
  uVar14 = ddiv_mantissas(param_1 << 0xb,param_2 << 0xb | param_1 >> 0x15 | 0x80000000);
  uVar5 = (int)uVar14 << 0x15;
  uVar6 = (uint)(uVar14 >> 0xb);
  uVar10 = (int)((uVar14 >> 0xb) >> 0x20) + (uVar10 + (iVar8 >> 0x10)) * 0x100000 ^
           iVar7 * -0x80000000;
  if (uVar5 != 0) {
    bVar11 = SUB41(uVar5 >> 0x1f,0);
    if (bVar11) {
      if ((uVar14 & 0x3ff) == 0) {
        uVar4 = 0x80000000;
      }
      else {
        uVar4 = 0;
      }
      uVar1 = uVar6 + bVar11;
      uVar10 = uVar10 + CARRY4(uVar6,(uint)bVar11);
      uVar5 = 0x40000000;
      uVar6 = uVar1 & ~(uVar4 >> 0x1f);
      if ((uVar1 & uVar4 >> 0x1f) != 0) {
        uVar5 = 0xc0000000;
      }
    }
    else {
      uVar5 = 0xc0000000;
    }
  }
  if ((-1 < (int)(uVar10 ^ iVar7 * -0x80000000)) &&
     ((uVar10 & DAT_300b7960) != 0 && (DAT_300b7960 & ~uVar10) != 0)) {
    return uVar6;
  }
  bVar13 = SBORROW4(iVar8,0x4000000);
  bVar11 = iVar7 + -0x40000 < 0;
  if (iVar8 < 0x4000001) {
    uVar10 = uVar10 + 0x60000000;
  }
  if (bVar11 == bVar13) {
    uVar10 = uVar10 + 0xa0000000;
  }
  uVar4 = uVar5 | 0x14;
  if (bVar11 == bVar13) {
    uVar4 = uVar5 | 0x10000014;
  }
  if (iVar8 != 0x4000000 && bVar11 == bVar13) {
    uVar5 = __fpl_exception();
    return uVar5;
  }
  puVar2 = (uint *)__rt_fp_status_addr();
  if ((*puVar2 & 0x1000000) != 0) {
    return 0;
  }
  if ((*puVar2 & 0x800) == 0) {
    if ((int)uVar10 < 0) {
      uVar4 = uVar4 | 0x10000;
    }
    uVar5 = uVar10 & ~((uVar10 >> 0x14) << 0x14);
    iVar9 = -(uVar10 >> 0x14 & 0xfffff7ff);
    uVar1 = iVar9 + 0x601;
    uVar10 = uVar5 | 0x100000;
    if (uVar1 < 0x36) {
      if (uVar1 == 0x35) {
        uVar1 = 0;
        uVar3 = 0x80000000;
        if (uVar6 != 0 || (uVar5 & 0xfffff) != 0) {
          uVar3 = 0x80000001;
        }
      }
      else if (uVar1 < 0x15) {
        uVar3 = uVar6 << (0x20 - uVar1 & 0xff);
        uVar1 = uVar10 << (0x20 - uVar1 & 0xff) | uVar6 >> (uVar1 & 0xff);
      }
      else {
        uVar5 = iVar9 + 0x5e1;
        if (uVar1 < 0x20 || uVar5 == 0) {
          uVar1 = uVar10 << (-uVar5 & 0xff) | uVar6 >> (uVar1 & 0xff);
          uVar3 = uVar6 << (-uVar5 & 0xff);
        }
        else {
          uVar1 = uVar10 >> (uVar5 & 0xff);
          uVar3 = uVar10 << (0x20 - uVar5 & 0xff);
          if (uVar6 != 0) {
            uVar3 = uVar3 | 1;
          }
        }
      }
    }
    else {
      uVar3 = 1;
      uVar1 = 0;
    }
    if (uVar3 != 0) {
      if (SUB41(uVar3 >> 0x1f,0)) {
        if (((uVar3 & 0x7fffffff) == 0) && (-1 < (int)uVar4 >> 0x1e)) {
          if ((int)uVar4 >> 0x1e == 0) {
            uVar1 = uVar1 + 1 & 0xfffffffe;
          }
        }
        else {
          uVar1 = uVar1 + 1;
        }
      }
      puVar2 = (uint *)__rt_fp_status_addr();
      *puVar2 = *puVar2 | 8;
      return uVar1;
    }
    return uVar1;
  }
  uVar5 = _fp_trapveneer(uVar6,uVar10,iVar9);
  return uVar5;
}

/* ----------------------------------------------------------------
 * __fixdfsi @ 0x300B79EC  (примерный размер ~148 байт)
 * Модуль: lib | Вызывают: 8 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Вызывают: FUN_300c4638, __ieee754_rem_pio2, __kernel_cos, __kernel_rem_pio2, __kernel_sin, __kernel_tan, exp, expm1
 * Константы: 0x300B79EC, 0x80000000, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
uint __fixdfsi(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = (int)param_2 >> 0x14;
  uVar4 = param_2 << 0xb | param_1 >> 0x15;
  if (uVar1 != 0) {
    uVar4 = uVar4 | 0x80000000;
  }
  if ((int)uVar1 < 0) {
    if ((uVar1 & 0x7ff) == 0) {
      uVar4 = uVar4 & 0x7fffffff;
    }
    uVar2 = 0;
    iVar3 = (uVar1 & 0x7ff) - 0x380;
    uVar1 = 0x9e - iVar3;
    if (iVar3 < 0x9f) {
      if ((int)uVar1 < 0x100) {
        uVar2 = -(uVar4 >> (uVar1 & 0xff));
      }
      if ((int)uVar2 < 1) {
        return uVar2;
      }
    }
  }
  else {
    iVar3 = -(uVar1 - 0x380);
    uVar2 = iVar3 + 0x9e;
    if (uVar2 != 0 && (int)(uVar1 - 0x380) < 0x9f) {
      if (0xff < (int)uVar2) {
        param_2 = 0;
      }
      if (uVar2 == 0xff || iVar3 + -0x61 < 0 != SBORROW4(uVar2,0xff)) {
        param_2 = uVar4 >> (uVar2 & 0xff);
      }
      return param_2;
    }
  }
  uVar1 = __fpl_exception();
  return uVar1;
}

/* ----------------------------------------------------------------
 * __fixdfdi @ 0x300B7B14  (примерный размер ~180 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Вызывают: FUN_3010891c
 * Константы: 0x80000000, 0x300B7B14, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
undefined8 __fixdfdi(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  iVar1 = param_2 >> 0x14;
  uVar4 = param_2 << 0xb | param_1 >> 0x15;
  param_1 = param_1 << 0xb;
  if (iVar1 != 0) {
    uVar4 = uVar4 | 0x80000000;
  }
  if (iVar1 < 0) {
    if (iVar1 == -0x800) {
      uVar4 = uVar4 & 0x7fffffff;
    }
    uVar2 = 0x2e - (iVar1 + 0x3f0);
    if ((iVar1 + 0x3f0 < 0x2f) && ((uVar2 != 0 || (param_1 == 0 && uVar4 == 0x80000000)))) {
      if (0x4f < (int)uVar2) {
        uVar2 = 0x50;
      }
      param_1 = param_1 >> (uVar2 & 0xff);
      uVar3 = 0x20 - uVar2;
      if (uVar2 < 0x21 && uVar3 != 0) {
        param_1 = param_1 | uVar4 << (uVar3 & 0xff);
      }
      if (uVar2 >= 0x21 || uVar3 == 0) {
        param_1 = param_1 | uVar4 >> (-uVar3 & 0xff);
      }
      return CONCAT44(-((uVar4 >> (uVar2 & 0xff)) + (uint)(param_1 != 0)),-param_1);
    }
  }
  else {
    uVar2 = 0x3f0 - (iVar1 + -0x4e);
    if (uVar2 != 0 && iVar1 + -0x4e < 0x3f1) {
      if (0x4f < (int)uVar2) {
        uVar2 = 0x50;
      }
      param_1 = param_1 >> (uVar2 & 0xff);
      uVar3 = 0x20 - uVar2;
      if (uVar2 < 0x21 && uVar3 != 0) {
        param_1 = param_1 | uVar4 << (uVar3 & 0xff);
      }
      if (uVar2 >= 0x21 || uVar3 == 0) {
        param_1 = param_1 | uVar4 >> (-uVar3 & 0xff);
      }
      return CONCAT44(uVar4 >> (uVar2 & 0xff),param_1);
    }
  }
  uVar5 = __fpl_exception();
  return uVar5;
}

/* ----------------------------------------------------------------
 * __fixunsdfsi @ 0x300B7C7C  (примерный размер ~148 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x300B7C7C, 0x80000000, 0x40100000, 0x40000000, 0x00100000
 * ---------------------------------------------------------------- */
uint __fixunsdfsi(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = (int)param_2 >> 0x14;
  uVar4 = param_2 << 0xb | param_1 >> 0x15;
  if (iVar1 != 0) {
    uVar4 = uVar4 | 0x80000000;
  }
  if (iVar1 < 0) {
    if ((int)(param_2 + 0x40100000) < 0 != SCARRY4(param_2 + 0x40000000,0x100000)) {
      return 0;
    }
  }
  else {
    iVar2 = -(iVar1 + -0x380);
    uVar3 = iVar2 + 0x9e;
    if (iVar1 + -0x380 < 0x9f) {
      if (0xff < (int)uVar3) {
        param_2 = 0;
      }
      if (uVar3 == 0xff || iVar2 + -0x61 < 0 != SBORROW4(uVar3,0xff)) {
        param_2 = uVar4 >> (uVar3 & 0xff);
      }
      return param_2;
    }
  }
  uVar4 = __fpl_exception();
  return uVar4;
}

/* ----------------------------------------------------------------
 * __fixunsdfdi @ 0x300B7DA4  (примерный размер ~156 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x300B7DA4, 0x80000000, 0x40100000, 0x40000000, 0x00100000
 * ---------------------------------------------------------------- */
undefined8 __fixunsdfdi(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  iVar1 = param_2 >> 0x14;
  uVar5 = param_2 << 0xb | param_1 >> 0x15;
  if (iVar1 != 0) {
    uVar5 = uVar5 | 0x80000000;
  }
  if (iVar1 < 0) {
    if (param_2 + 0x40100000 < 0 != SCARRY4(param_2 + 0x40000000,0x100000)) {
      return 0;
    }
  }
  else {
    uVar3 = 0x3f0 - (iVar1 + -0x4e);
    if (iVar1 + -0x4e < 0x3f1) {
      if (0x4f < (int)uVar3) {
        uVar3 = 0x50;
      }
      uVar2 = (param_1 << 0xb) >> (uVar3 & 0xff);
      uVar4 = 0x20 - uVar3;
      if (uVar3 < 0x21 && uVar4 != 0) {
        uVar2 = uVar2 | uVar5 << (uVar4 & 0xff);
      }
      if (uVar3 >= 0x21 || uVar4 == 0) {
        uVar2 = uVar2 | uVar5 >> (-uVar4 & 0xff);
      }
      return CONCAT44(uVar5 >> (uVar3 & 0xff),uVar2);
    }
  }
  uVar6 = __fpl_exception();
  return uVar6;
}

/* ----------------------------------------------------------------
 * __dunder @ 0x300B8490  (примерный размер ~356 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 2
 * Вызывает: __rt_fp_status_addr, _fp_trapveneer
 * Вызывают: __adddf3, __subdf3, _drem, _drsb
 * Константы: 0x80000000, 0xFFFFFFFE, 0x300B8490, 0x01000000, 0xFFFFF7FF, 0x00100000, 0x80000001, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
longlong __dunder(uint param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint in_r12;
  bool bVar8;
  longlong lVar9;
  
  puVar2 = (uint *)__rt_fp_status_addr();
  if ((*puVar2 & 0x1000000) != 0) {
    return (ulonglong)(param_2 & 0x80000000) << 0x20;
  }
  if ((*puVar2 & 0x800) != 0) {
    lVar9 = _fp_trapveneer(param_1,param_2,param_3);
    return lVar9;
  }
  if ((int)param_2 < 0) {
    in_r12 = in_r12 | 0x10000;
  }
  uVar4 = param_2 & ~((param_2 >> 0x14) << 0x14);
  iVar1 = -(param_2 >> 0x14 & 0xfffff7ff);
  uVar6 = iVar1 + 0x601;
  uVar5 = uVar4 | 0x100000;
  if (uVar6 < 0x36) {
    if (uVar6 == 0x35) {
      uVar3 = 0;
      uVar5 = 0;
      uVar7 = 0x80000000;
      if (param_1 != 0 || (uVar4 & 0xfffff) != 0) {
        uVar7 = 0x80000001;
      }
    }
    else if (uVar6 < 0x15) {
      uVar7 = param_1 << (0x20 - uVar6 & 0xff);
      uVar3 = uVar5 << (0x20 - uVar6 & 0xff) | param_1 >> (uVar6 & 0xff);
      uVar5 = uVar5 >> (uVar6 & 0xff);
    }
    else {
      uVar4 = iVar1 + 0x5e1;
      if (uVar6 < 0x20 || uVar4 == 0) {
        uVar3 = uVar5 << (-uVar4 & 0xff) | param_1 >> (uVar6 & 0xff);
        uVar7 = param_1 << (-uVar4 & 0xff);
        uVar5 = 0;
      }
      else {
        uVar3 = uVar5 >> (uVar4 & 0xff);
        uVar7 = uVar5 << (0x20 - uVar4 & 0xff);
        if (param_1 != 0) {
          uVar7 = uVar7 | 1;
        }
        uVar5 = 0;
      }
    }
  }
  else {
    uVar7 = 1;
    uVar5 = 0;
    uVar3 = 0;
  }
  if ((in_r12 & 0x10000) != 0) {
    uVar5 = uVar5 | 0x80000000;
  }
  if (uVar7 == 0) {
    return CONCAT44(uVar5,uVar3);
  }
  if (SUB41(uVar7 >> 0x1f,0)) {
    if (((uVar7 & 0x7fffffff) == 0) && (-1 < (int)in_r12 >> 0x1e)) {
      if ((int)in_r12 >> 0x1e == 0) {
        uVar5 = uVar5 + (0xfffffffe < uVar3);
        uVar3 = uVar3 + 1 & 0xfffffffe;
      }
    }
    else {
      bVar8 = 0xfffffffe < uVar3;
      uVar3 = uVar3 + 1;
      uVar5 = uVar5 + bVar8;
    }
  }
  puVar2 = (uint *)__rt_fp_status_addr();
  *puVar2 = *puVar2 | 8;
  return CONCAT44(uVar5,uVar3);
}

/* ----------------------------------------------------------------
 * __dunder_d @ 0x300B85F4  (примерный размер ~204 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 2
 * Вызывает: __rt_fp_status_addr, _fp_trapveneer
 * Вызывают: __adddf3, __subdf3, _drem, _drsb
 * Константы: 0x00140000, 0x300B85F4, 0x01000000, 0x06000000, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
void __dunder_d(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = (uint *)__rt_fp_status_addr();
  if ((*puVar1 & 0x1000000) != 0) {
    return;
  }
  if ((*puVar1 & 0x800) != 0) {
    uVar3 = param_2 >> 0x1f | 0x6000000;
    param_2 = param_2 & 0x7fffffff;
    if (param_2 == 0 && param_1 >> 0xc == 0) {
      param_1 = param_1 << 0x14;
      uVar3 = uVar3 - 0x140000;
    }
    if (param_2 == 0) {
      param_2 = param_1 >> 0xc;
      param_1 = param_1 << 0x14;
      uVar3 = uVar3 - 0x140000;
    }
    uVar2 = 0;
    if (param_2 >> 5 == 0) {
      param_2 = param_2 << 0x10;
      uVar2 = 0x10;
    }
    if (param_2 >> 0xd == 0) {
      param_2 = param_2 << 8;
      uVar2 = uVar2 + 8;
    }
    if (param_2 >> 0x11 == 0) {
      param_2 = param_2 << 4;
      uVar2 = uVar2 + 4;
    }
    if (param_2 >> 0x13 == 0) {
      param_2 = param_2 << 2;
      uVar2 = uVar2 + 2;
    }
    if (param_2 >> 0x14 == 0) {
      param_2 = param_2 << 1;
      uVar2 = uVar2 + 1;
    }
    _fp_trapveneer(param_1 << (uVar2 & 0xff),
                   ((param_2 | param_1 >> (0x20 - uVar2 & 0xff)) ^ uVar3 * -0x80000000) +
                   (uVar3 + uVar2 * -0x10000 & 0xfffffffe) * 0x10);
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * __fpl_exception @ 0x300B86C0  (примерный размер ~356 байт)
 * Модуль: lib | Вызывают: 35 | Вызывает: 5
 * Вызывает: __fpl_cmpreturn, __fpl_return_NaN, __rt_fp_status_addr, _fp_trap, _fp_trapveneer
 * Вызывают: __adddf3, __addsf3, __divdf3, __divsf3, __fixdfdi, __fixdfsi, __fixsfdi, __fixsfsi, __fixunsdfdi, __fixunsdfsi
 *           ...
 * Константы: 0x80000000, 0x40000000, 0x300B86C0, 0x30000000, 0x20000000, 0x10000000, 0x08000000
 * Данные: DAT_300b8810, DAT_300b8820
 * ---------------------------------------------------------------- */
uint __fpl_exception(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint in_r12;
  
  if ((in_r12 & 0x10) == 0) {
    param_3 = param_2;
  }
  puVar1 = (uint *)__rt_fp_status_addr();
  uVar2 = *puVar1;
  if ((in_r12 & ~(uVar2 << 0x12) & 0x30000000) != 0) {
    in_r12 = in_r12 | 0x40000000;
  }
  *puVar1 = uVar2 | (in_r12 << 1) >> 0x1b;
  if ((in_r12 & 0xf) != 8) {
    in_r12 = in_r12 | (in_r12 & 0x70) << 3;
  }
  if ((in_r12 & 0x20000000) != 0) {
    if ((uVar2 & 0x800) == 0) {
      return param_1;
    }
    uVar2 = _fp_trapveneer(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  if ((in_r12 & 0x10000000) == 0) {
    if ((in_r12 & 0x40000000) != 0) {
      if ((uVar2 & 0x1000) == 0) {
        return param_1;
      }
      uVar2 = _fp_trapveneer(param_1,param_2,param_3,param_4);
      return uVar2;
    }
    if ((in_r12 & 0x8000000) == 0) {
      if ((uVar2 & 0x100) == 0) {
        if ((in_r12 & 0x80) == 0) {
          param_1 = param_1 & 0x80000000;
        }
        else {
          param_1 = param_2 & 0x80000000;
        }
        if ((in_r12 & 0x10) == 0) {
          uVar2 = DAT_300b8820 | param_1;
        }
        else {
          param_2 = uRam300b881c | param_1;
          uVar2 = uRam300b8818;
        }
        uVar2 = __fpl_return_NaN(uVar2,param_2,param_1,param_4);
        return uVar2;
      }
      uVar2 = _fp_trapveneer();
      return uVar2;
    }
    if ((uVar2 & 0x200) != 0) {
      uVar2 = _fp_trap();
      if ((in_r12 & 0xf) == 9) {
        uVar2 = __fpl_cmpreturn();
        return uVar2;
      }
      return uVar2;
    }
    if ((in_r12 & 0x10) == 0) {
      param_2 = param_1 ^ param_3;
    }
    else {
      param_2 = param_2 ^ param_4;
    }
  }
  else {
    if ((uVar2 & 0x400) != 0) {
      uVar2 = _fp_trapveneer();
      return uVar2;
    }
    if ((in_r12 & 0x80) == 0) {
      param_2 = param_1 & 0x80000000;
    }
    else {
      param_2 = param_2 & 0x80000000;
    }
  }
  uVar2 = uRam300b8800;
  if ((in_r12 & 0x10) == 0) {
    uVar2 = DAT_300b8810 | param_2 & 0x80000000;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * __extendsfdf2 @ 0x300B8824  (примерный размер ~116 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 6
 * Вызывает: __dflt_normalise, __fpl_cmpreturn, __fpl_return_NaN, __rt_fp_status_addr, _fp_trap, _fp_trapveneer
 * Вызывают: FUN_3010cbcc
 * Константы: 0x80000000, 0x00800000, 0x38000000, 0x40000000, 0x300B8824, 0x7F000000, 0x36800000, 0x00700000
 * Данные: DAT_300b8810, DAT_300b8820, DAT_300b8890, DAT_300b8894
 * ---------------------------------------------------------------- */
longlong __extendsfdf2(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  
  uVar5 = DAT_300b8890;
  if ((param_1 + 0x800000 & 0x7f000000) != 0) {
    iVar1 = (int)param_1 >> 3;
    if (-1 < iVar1) {
      return CONCAT44(iVar1 + 0x38000000,param_1 << 0x1d);
    }
    return CONCAT44(iVar1 + -0x38000000,param_1 << 0x1d);
  }
  if ((param_1 + 0x800000 & 0x800000) != 0) {
    if (param_1 << 1 == 0) {
      return (ulonglong)param_1 << 0x20;
    }
    lVar6 = __dflt_normalise(param_1 << 1,param_1 << 3,param_1 & 0x80000000,
                             (param_1 & 0x80000000) + 0x36800000);
    return lVar6;
  }
  uVar4 = param_1 << 9;
  if (uVar4 == 0) {
    return (ulonglong)(param_1 | 0x700000) << 0x20;
  }
  if ((int)uVar4 < 0) {
    return (ulonglong)DAT_300b8894 << 0x20;
  }
  if ((DAT_300b8890 & 0x10) == 0) {
    uVar4 = param_2;
  }
  puVar2 = (uint *)__rt_fp_status_addr();
  uVar3 = *puVar2;
  if ((uVar5 & ~(uVar3 << 0x12) & 0x30000000) != 0) {
    uVar5 = uVar5 | 0x40000000;
  }
  *puVar2 = uVar3 | (uVar5 << 1) >> 0x1b;
  if ((uVar5 & 0xf) != 8) {
    uVar5 = uVar5 | (uVar5 & 0x70) << 3;
  }
  if ((uVar5 & 0x20000000) == 0) {
    if ((uVar5 & 0x10000000) == 0) {
      if ((uVar5 & 0x40000000) != 0) {
        if ((uVar3 & 0x1000) != 0) {
          lVar6 = _fp_trapveneer(param_1,param_2,uVar4,param_4);
          return lVar6;
        }
        goto LAB_300b87a4;
      }
      if ((uVar5 & 0x8000000) == 0) {
        if ((uVar3 & 0x100) != 0) {
          lVar6 = _fp_trapveneer();
          return lVar6;
        }
        if ((uVar5 & 0x80) == 0) {
          param_1 = param_1 & 0x80000000;
        }
        else {
          param_1 = param_2 & 0x80000000;
        }
        if ((uVar5 & 0x10) == 0) {
          uVar5 = DAT_300b8820 | param_1;
        }
        else {
          param_2 = uRam300b881c | param_1;
          uVar5 = uRam300b8818;
        }
        lVar6 = __fpl_return_NaN(uVar5,param_2,param_1,param_4);
        return lVar6;
      }
      if ((uVar3 & 0x200) != 0) {
        lVar6 = _fp_trap();
        if ((uVar5 & 0xf) != 9) {
          return lVar6;
        }
        lVar6 = __fpl_cmpreturn();
        return lVar6;
      }
      if ((uVar5 & 0x10) == 0) {
        param_4 = param_1 ^ uVar4;
      }
      else {
        param_4 = param_2 ^ param_4;
      }
    }
    else {
      if ((uVar3 & 0x400) != 0) {
        lVar6 = _fp_trapveneer();
        return lVar6;
      }
      if ((uVar5 & 0x80) == 0) {
        param_4 = param_1 & 0x80000000;
      }
      else {
        param_4 = param_2 & 0x80000000;
      }
    }
    if ((uVar5 & 0x10) == 0) {
      uVar5 = DAT_300b8810 | param_4 & 0x80000000;
    }
    else {
      param_2 = uRam300b8804 | param_4 & 0x80000000;
      uVar5 = uRam300b8800;
    }
    return CONCAT44(param_2,uVar5);
  }
  if ((uVar3 & 0x800) != 0) {
    lVar6 = _fp_trapveneer(param_1,param_2,uVar4,param_4);
    return lVar6;
  }
LAB_300b87a4:
  return CONCAT44(param_2,param_1);
}

/* ----------------------------------------------------------------
 * __fpl_fcheck_NaN2 @ 0x300B8898  (примерный размер ~36 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 5
 * Вызывает: __fpl_cmpreturn, __fpl_return_NaN, __rt_fp_status_addr, _fp_trap, _fp_trapveneer
 * Вызывают: _fcmpeq
 * Константы: 0x80000000, 0x00800000, 0xFF800001, 0x40000000, 0x300B8898, 0x007FFFFF, 0x30000000, 0x20000000
 * Данные: DAT_300b8810, DAT_300b8820
 * ---------------------------------------------------------------- */
uint __fpl_fcheck_NaN2(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint in_r12;
  
  uVar3 = param_1 * 2 + 0x800000;
  uVar4 = param_2 * 2 + 0x800000;
  uVar2 = uVar3;
  if (uVar3 < 0xff800001) {
    uVar2 = uVar4;
  }
  if (uVar2 < 0xff800001) {
    if (0x7fffff < uVar3) {
      param_1 = param_2;
    }
    uVar2 = __fpl_return_NaN(param_1);
    return uVar2;
  }
  if ((in_r12 & 0x10) == 0) {
    uVar3 = param_2;
  }
  puVar1 = (uint *)__rt_fp_status_addr();
  uVar2 = *puVar1;
  if ((in_r12 & ~(uVar2 << 0x12) & 0x30000000) != 0) {
    in_r12 = in_r12 | 0x40000000;
  }
  *puVar1 = uVar2 | (in_r12 << 1) >> 0x1b;
  if ((in_r12 & 0xf) != 8) {
    in_r12 = in_r12 | (in_r12 & 0x70) << 3;
  }
  if ((in_r12 & 0x20000000) != 0) {
    if ((uVar2 & 0x800) == 0) {
      return param_1;
    }
    uVar2 = _fp_trapveneer(param_1,param_2,uVar3,uVar4);
    return uVar2;
  }
  if ((in_r12 & 0x10000000) == 0) {
    if ((in_r12 & 0x40000000) != 0) {
      if ((uVar2 & 0x1000) == 0) {
        return param_1;
      }
      uVar2 = _fp_trapveneer(param_1,param_2,uVar3,uVar4);
      return uVar2;
    }
    if ((in_r12 & 0x8000000) == 0) {
      if ((uVar2 & 0x100) == 0) {
        if ((in_r12 & 0x80) == 0) {
          param_1 = param_1 & 0x80000000;
        }
        else {
          param_1 = param_2 & 0x80000000;
        }
        if ((in_r12 & 0x10) == 0) {
          uVar2 = DAT_300b8820 | param_1;
        }
        else {
          param_2 = uRam300b881c | param_1;
          uVar2 = uRam300b8818;
        }
        uVar2 = __fpl_return_NaN(uVar2,param_2,param_1,uVar4);
        return uVar2;
      }
      uVar2 = _fp_trapveneer();
      return uVar2;
    }
    if ((uVar2 & 0x200) != 0) {
      uVar2 = _fp_trap();
      if ((in_r12 & 0xf) == 9) {
        uVar2 = __fpl_cmpreturn();
        return uVar2;
      }
      return uVar2;
    }
    if ((in_r12 & 0x10) == 0) {
      param_2 = param_1 ^ uVar3;
    }
    else {
      param_2 = param_2 ^ uVar4;
    }
  }
  else {
    if ((uVar2 & 0x400) != 0) {
      uVar2 = _fp_trapveneer();
      return uVar2;
    }
    if ((in_r12 & 0x80) == 0) {
      param_2 = param_1 & 0x80000000;
    }
    else {
      param_2 = param_2 & 0x80000000;
    }
  }
  uVar2 = uRam300b8800;
  if ((in_r12 & 0x10) == 0) {
    uVar2 = DAT_300b8810 | param_2 & 0x80000000;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * __cmpsf2 @ 0x300B8934  (примерный размер ~88 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: _fcmpeq
 * Константы: 0x300B8934, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4 __cmpsf2(void)

{
  undefined4 uVar1;
  undefined1 in_ZR;
  undefined1 in_CY;
  
  uVar1 = _fcmpeq();
  if (!(bool)in_CY) {
    uVar1 = 0xfffffffe;
  }
  if ((bool)in_ZR) {
    uVar1 = 0;
  }
  if ((bool)in_CY && !(bool)in_ZR) {
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * __divsf3 @ 0x300B899C  (примерный размер ~464 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 8
 * Вызывает: __fpl_cmpreturn, __fpl_exception, __fpl_normalise2, __fpl_return_NaN, __funder, __rt_fp_status_addr, _fp_trap, _fp_trapveneer
 * Вызывают: _frdiv
 * Константы: 0x00FF0000, 0x7FFFFFFF, 0x80000000, 0x00800000, 0x40000000, 0x7F800000, 0x00FC0000, 0xFF000001
 * Данные: DAT_300b8810, DAT_300b8820, DAT_300b8b64
 * ---------------------------------------------------------------- */
uint __divsf3(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  
  uVar3 = DAT_300b8b64;
  uVar6 = param_1 >> 7 & 0xff0000;
  bVar12 = uVar6 == 0;
  if (!bVar12) {
    param_4 = param_2 >> 7 & 0xff0000;
    bVar12 = param_4 == 0;
  }
  if (!bVar12) {
    bVar12 = uVar6 == 0xff0000;
  }
  if (!bVar12) {
    bVar12 = param_4 == 0xff0000;
  }
  if (bVar12) {
    uVar5 = param_2 >> 7 & 0xff0000;
    if ((int)(param_1 ^ param_2) < 0) {
      uVar6 = uVar6 | 0x100;
    }
    if (uVar6 < 0xff0000 && uVar5 < 0xff0000) {
      if ((param_2 & 0x7fffffff) == 0) {
        uVar3 = __fpl_exception();
        return uVar3;
      }
      if ((param_1 & 0x7fffffff) != 0) {
        uVar3 = __fpl_normalise2(param_1);
        return uVar3;
      }
      return uVar6 << 0x17;
    }
    uVar2 = param_1 * 2;
    if (uVar2 < 0xff000001) {
      uVar2 = param_2 * 2;
    }
    if (uVar2 < 0xff000001) {
      if ((param_1 & 0x7fffffff) != 0x7f800000 || (param_2 & 0x7fffffff) != 0x7f800000) {
        if ((param_2 & 0x7fffffff) == 0x7f800000) {
          param_1 = 0;
        }
        else {
          param_1 = param_1 & 0x7fffffff;
        }
        return param_1 | uVar6 << 0x17;
      }
      param_1 = uVar6 << 0x17;
    }
    else {
      uVar6 = param_1 * 2 + 0x800000;
      uVar5 = param_2 * 2 + 0x800000;
      uVar2 = uVar6;
      if (uVar6 < 0xff800001) {
        uVar2 = uVar5;
      }
      if (uVar2 < 0xff800001) {
        if (0x7fffff < uVar6) {
          param_1 = param_2;
        }
        uVar3 = __fpl_return_NaN(param_1);
        return uVar3;
      }
    }
    if ((DAT_300b8b64 & 0x10) == 0) {
      uVar6 = param_2;
    }
    puVar1 = (uint *)__rt_fp_status_addr();
    uVar2 = *puVar1;
    if ((uVar3 & ~(uVar2 << 0x12) & 0x30000000) != 0) {
      uVar3 = uVar3 | 0x40000000;
    }
    *puVar1 = uVar2 | (uVar3 << 1) >> 0x1b;
    if ((uVar3 & 0xf) != 8) {
      uVar3 = uVar3 | (uVar3 & 0x70) << 3;
    }
    if ((uVar3 & 0x20000000) != 0) {
      if ((uVar2 & 0x800) == 0) {
        return param_1;
      }
      uVar3 = _fp_trapveneer(param_1,param_2,uVar6,uVar5);
      return uVar3;
    }
    if ((uVar3 & 0x10000000) == 0) {
      if ((uVar3 & 0x40000000) != 0) {
        if ((uVar2 & 0x1000) == 0) {
          return param_1;
        }
        uVar3 = _fp_trapveneer(param_1,param_2,uVar6,uVar5);
        return uVar3;
      }
      if ((uVar3 & 0x8000000) == 0) {
        if ((uVar2 & 0x100) == 0) {
          if ((uVar3 & 0x80) == 0) {
            param_1 = param_1 & 0x80000000;
          }
          else {
            param_1 = param_2 & 0x80000000;
          }
          if ((uVar3 & 0x10) == 0) {
            uVar3 = DAT_300b8820 | param_1;
          }
          else {
            param_2 = uRam300b881c | param_1;
            uVar3 = uRam300b8818;
          }
          uVar3 = __fpl_return_NaN(uVar3,param_2,param_1,uVar5);
          return uVar3;
        }
        uVar3 = _fp_trapveneer();
        return uVar3;
      }
      if ((uVar2 & 0x200) != 0) {
        uVar6 = _fp_trap();
        if ((uVar3 & 0xf) == 9) {
          uVar3 = __fpl_cmpreturn();
          return uVar3;
        }
        return uVar6;
      }
      if ((uVar3 & 0x10) == 0) {
        param_2 = param_1 ^ uVar6;
      }
      else {
        param_2 = param_2 ^ uVar5;
      }
    }
    else {
      if ((uVar2 & 0x400) != 0) {
        uVar3 = _fp_trapveneer();
        return uVar3;
      }
      if ((uVar3 & 0x80) == 0) {
        param_2 = param_1 & 0x80000000;
      }
      else {
        param_2 = param_2 & 0x80000000;
      }
    }
    uVar6 = uRam300b8800;
    if ((uVar3 & 0x10) == 0) {
      uVar6 = DAT_300b8810 | param_2 & 0x80000000;
    }
    return uVar6;
  }
  if ((int)(param_1 ^ param_2) < 0) {
    uVar6 = uVar6 | 0x100;
  }
  uVar3 = param_1 & 0xffffff | 0x800000;
  uVar2 = param_2 & 0xffffff | 0x800000;
  bVar12 = uVar2 <= uVar3;
  uVar9 = (uint)*(byte *)(0x300b89cb - (uVar2 >> 0x11));
  uVar5 = -uVar2;
  iVar10 = uVar9 * 2;
  if (!bVar12) {
    uVar3 = uVar3 << 1;
  }
  iVar10 = uVar9 * 0x100 + (((int)(uVar5 * iVar10) >> 4) * iVar10 >> 0x15);
  uVar9 = iVar10 * (uVar3 >> 8) >> 0x14;
  uVar4 = uVar5 * uVar9 + uVar3 * 0x800;
  uVar7 = (uVar6 - param_4) + 0x7d0000;
  uVar3 = iVar10 * (uVar4 >> 8) >> 0x13;
  uVar6 = uVar5 * uVar3 + uVar4 * 0x1000;
  uVar11 = uVar7 & 0x100;
  uVar4 = uVar7 + ((int)uVar7 >> 0x10) + (uint)bVar12;
  bVar12 = CARRY4(uVar6,uVar5);
  if (bVar12) {
    uVar6 = uVar6 + uVar5;
  }
  if (uVar6 != 0) {
    uVar11 = uVar11 | 0x40000002;
  }
  bVar14 = CARRY4(uVar5,uVar6 * 2);
  bVar13 = uVar6 * 2 == uVar2;
  if (bVar14) {
    uVar11 = uVar11 | 0x40000001;
  }
  if (bVar13) {
    uVar11 = uVar11 | 4;
  }
  uVar3 = uVar3 + uVar9 * 0x1000 + (uint)bVar12 + uVar4 * 0x800000 + (uint)bVar14;
  if (!bVar13) {
    bVar14 = 0xfbffff < uVar4;
  }
  if (!bVar14) {
    return uVar3;
  }
  uVar6 = uVar3 * -0x80000000;
  uVar5 = uVar11 | 8 | uVar6;
  if (bVar13 || uVar4 == 0xfc0000) {
    uVar3 = uVar3 & 0xfffffffe;
  }
  if (uVar4 < 0xfc0000) {
    return uVar3;
  }
  if (-1 < (int)(uVar4 - 0xfc0000)) {
    if (uVar3 * 2 + 0x1000000 < 0xfe000000) {
      uVar3 = __fpl_exception(uVar3 + 0xa0000000,uVar11 & 0x40000000);
      return uVar3;
    }
    return uVar3;
  }
  if (0x2ffffff < uVar3 * 2 - 0x1000000) {
    bVar14 = (uVar11 & 4) == 0;
    bVar12 = !bVar14 && uVar6 == 0;
    if (bVar14 || uVar5 == 0xffffffff) {
      bVar12 = (uVar11 & 1) != 0;
    }
    if (bVar12) {
      uVar8 = 0x40000004;
    }
    else {
      uVar8 = 0xc0000004;
    }
    if ((uVar11 & 0x40000000) == 0) {
      uVar8 = 4;
    }
    uVar3 = __funder(uVar3 + 0x60000000,uVar5,uVar8);
    return uVar3;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * __fixsfsi @ 0x300B8BD4  (примерный размер ~88 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Вызывают: FUN_3010891c
 * Константы: 0x300B8BD4, 0x80000000, 0xCF000001, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
uint __fixsfsi(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (int)param_1 >> 0x17;
  uVar2 = param_1 << 8;
  if (uVar1 != 0) {
    uVar2 = uVar2 | 0x80000000;
  }
  if ((int)uVar1 < 0) {
    if (param_1 < 0xcf000001) {
      if ((uVar1 & 0xff) == 0) {
        uVar2 = uVar2 & 0x7fffffff;
      }
      return -(uVar2 >> (0x9e - (uVar1 & 0xff) & 0xff));
    }
  }
  else if (uVar1 < 0x9f && 0x9e - uVar1 != 0) {
    return uVar2 >> (0x9e - uVar1 & 0xff);
  }
  uVar2 = __fpl_exception();
  return uVar2;
}

/* ----------------------------------------------------------------
 * _ffix_r @ 0x300B8C2C  (примерный размер ~88 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x300B8C2C, 0x80000000, 0xCF000001, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
uint _ffix_r(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (int)param_1 >> 0x17;
  uVar2 = param_1 << 8;
  if (uVar1 != 0) {
    uVar2 = uVar2 | 0x80000000;
  }
  if ((int)uVar1 < 0) {
    if (param_1 < 0xcf000001) {
      if ((uVar1 & 0xff) == 0) {
        uVar2 = uVar2 & 0x7fffffff;
      }
      return -(uVar2 >> (0x9e - (uVar1 & 0xff) & 0xff));
    }
  }
  else if (uVar1 < 0x9f && 0x9e - uVar1 != 0) {
    return uVar2 >> (0x9e - uVar1 & 0xff);
  }
  uVar2 = __fpl_exception();
  return uVar2;
}

/* ----------------------------------------------------------------
 * __fixsfdi @ 0x300B8C84  (примерный размер ~124 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x300B8C84, 0x80000000, 0xDF000001, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
undefined8 __fixsfdi(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  uVar3 = (int)param_1 >> 0x17;
  uVar4 = param_1 << 8;
  if (uVar3 != 0) {
    uVar4 = uVar4 | 0x80000000;
  }
  if ((int)uVar3 < 0) {
    if (param_1 < 0xdf000001) {
      if ((uVar3 & 0xff) == 0) {
        uVar4 = uVar4 & 0x7fffffff;
      }
      iVar1 = -(uVar3 & 0xff);
      uVar3 = iVar1 + 0xbe;
      if (uVar3 < 0x20) {
        uVar2 = uVar4 << (0x20 - uVar3 & 0xff);
      }
      else {
        uVar2 = uVar4 >> (iVar1 + 0x9eU & 0xff);
      }
      return CONCAT44(-((uVar4 >> (uVar3 & 0xff)) + (uint)(uVar2 != 0)),-uVar2);
    }
  }
  else {
    uVar2 = -uVar3 + 0xbe;
    if (uVar3 < 0xbf && uVar2 != 0) {
      if (uVar2 < 0x20) {
        uVar3 = uVar4 << (0x20 - uVar2 & 0xff);
      }
      else {
        uVar3 = uVar4 >> (-uVar3 + 0x9e & 0xff);
      }
      return CONCAT44(uVar4 >> (uVar2 & 0xff),uVar3);
    }
  }
  uVar5 = __fpl_exception();
  return uVar5;
}

/* ----------------------------------------------------------------
 * __fixunssfsi @ 0x300B8D8C  (примерный размер ~92 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x300B8D8C, 0x80000000, 0x7F000000
 * ---------------------------------------------------------------- */
uint __fixunssfsi(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 >> 0x17;
  uVar2 = param_1 << 8;
  if (uVar1 != 0) {
    uVar2 = uVar2 | 0x80000000;
  }
  if ((int)uVar1 < 0) {
    if ((uint)(param_1 << 1) < 0x7f000000) {
      return 0;
    }
  }
  else if (uVar1 < 0x9f) {
    return uVar2 >> (0x9e - uVar1 & 0xff);
  }
  uVar2 = __fpl_exception();
  return uVar2;
}

/* ----------------------------------------------------------------
 * _ffixu_r @ 0x300B8DE8  (примерный размер ~92 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x300B8DE8, 0x80000000, 0x7F000000
 * ---------------------------------------------------------------- */
uint _ffixu_r(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 >> 0x17;
  uVar2 = param_1 << 8;
  if (uVar1 != 0) {
    uVar2 = uVar2 | 0x80000000;
  }
  if ((int)uVar1 < 0) {
    if ((uint)(param_1 << 1) < 0x7f000000) {
      return 0;
    }
  }
  else if (uVar1 < 0x9f) {
    return uVar2 >> (0x9e - uVar1 & 0xff);
  }
  uVar2 = __fpl_exception();
  return uVar2;
}

/* ----------------------------------------------------------------
 * __fixunssfdi @ 0x300B8E44  (примерный размер ~112 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x300B8E44, 0x80000000, 0x7F000000
 * ---------------------------------------------------------------- */
undefined8 __fixunssfdi(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar1 = param_1 >> 0x17;
  uVar3 = param_1 << 8;
  if (uVar1 != 0) {
    uVar3 = uVar3 | 0x80000000;
  }
  if ((int)uVar1 < 0) {
    if ((uint)(param_1 << 1) < 0x7f000000) {
      return 0;
    }
  }
  else {
    uVar2 = -uVar1 + 0xbe;
    if (uVar1 < 0xbf) {
      if (uVar2 < 0x20) {
        uVar1 = uVar3 << (0x20 - uVar2 & 0xff);
      }
      else {
        uVar1 = uVar3 >> (-uVar1 + 0x9e & 0xff);
      }
      return CONCAT44(uVar3 >> (uVar2 & 0xff),uVar1);
    }
  }
  uVar4 = __fpl_exception();
  return uVar4;
}

/* ----------------------------------------------------------------
 * __funder @ 0x300B8FE4  (примерный размер ~232 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 6
 * Вызывает: __fpl_cmpreturn, __fpl_exception, __fpl_return_NaN, __rt_fp_status_addr, _fp_trap, _fp_trapveneer
 * Вызывают: __divsf3, __mulsf3, __truncdfsf2
 * Константы: 0x80000000, 0x7FFFFFFF, 0x40000000, 0x300B8FE4, 0x01000000, 0xFFFFFEFF, 0x7FFFFFE7, 0x007FFFFF
 * Данные: DAT_300b8810, DAT_300b8820
 * ---------------------------------------------------------------- */
uint __funder(uint param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  puVar2 = (uint *)__rt_fp_status_addr();
  if ((*puVar2 & 0x1000000) != 0) {
    return param_1 & 0x80000000;
  }
  if ((*puVar2 & 0x800) != 0) {
    uVar5 = _fp_trapveneer();
    return uVar5;
  }
  uVar5 = 0xc1 - (param_1 & 0x80000000 | param_1 >> 0x17 & 0xfffffeff);
  if (0x17 < (uVar5 & 0x7fffffff)) {
    *puVar2 = *puVar2 | 8;
    if (SBORROW4(uVar5 & 0x7fffffff,-0x7fffffe7)) {
      uVar1 = uVar5 & 0x80000000;
    }
    else {
      uVar1 = (uVar5 & 0x80000000) + 1;
      if ((param_1 & 0x7fffff) == 0 && (param_3 & 0x80000000) == 0) {
        uVar1 = uVar5 & 0x80000000;
      }
    }
    uVar5 = __fpl_exception(uVar1);
    return uVar5;
  }
  uVar1 = param_1 << (0x20 - uVar5 & 0xff);
  uVar6 = 0x20 - (0x20 - uVar5);
  uVar5 = (param_1 & 0xffffff | 0x800000) >> (uVar6 & 0xff);
  uVar6 = uVar6 & 0x80000000;
  uVar3 = uVar5 | uVar6;
  if (uVar1 == 0) {
    if ((param_3 & 0x40000000) == 0) {
      return uVar3;
    }
    uVar1 = param_3;
    if ((param_3 & 0x10) == 0) {
      uVar1 = 0;
    }
    puVar2 = (uint *)__rt_fp_status_addr();
    uVar4 = *puVar2;
    if ((param_3 & ~(uVar4 << 0x12) & 0x30000000) != 0) {
      param_3 = param_3 | 0x40000000;
    }
    *puVar2 = uVar4 | (param_3 << 1) >> 0x1b;
    if ((param_3 & 0xf) != 8) {
      param_3 = param_3 | (param_3 & 0x70) << 3;
    }
    if ((param_3 & 0x20000000) != 0) {
      if ((uVar4 & 0x800) == 0) {
        return uVar3;
      }
      uVar5 = _fp_trapveneer(uVar3,0,uVar1,uVar6);
      return uVar5;
    }
    if ((param_3 & 0x10000000) == 0) {
      if ((param_3 & 0x40000000) != 0) {
        if ((uVar4 & 0x1000) == 0) {
          return uVar3;
        }
        uVar5 = _fp_trapveneer(uVar3,0,uVar1,uVar6);
        return uVar5;
      }
      if ((param_3 & 0x8000000) == 0) {
        if ((uVar4 & 0x100) == 0) {
          if ((param_3 & 0x80) != 0) {
            uVar3 = 0;
          }
          uVar3 = uVar3 & 0x80000000;
          if ((param_3 & 0x10) == 0) {
            uVar1 = DAT_300b8820 | uVar3;
            uVar5 = 0;
          }
          else {
            uVar5 = uRam300b881c | uVar3;
            uVar1 = uRam300b8818;
          }
          uVar5 = __fpl_return_NaN(uVar1,uVar5,uVar3,uVar6);
          return uVar5;
        }
        uVar5 = _fp_trapveneer();
        return uVar5;
      }
      if ((uVar4 & 0x200) != 0) {
        uVar5 = _fp_trap();
        if ((param_3 & 0xf) == 9) {
          uVar5 = __fpl_cmpreturn();
          return uVar5;
        }
        return uVar5;
      }
      if ((param_3 & 0x10) == 0) {
        uVar6 = uVar3 ^ uVar1;
      }
    }
    else {
      if ((uVar4 & 0x400) != 0) {
        uVar5 = _fp_trapveneer();
        return uVar5;
      }
      if ((param_3 & 0x80) == 0) {
        uVar6 = uVar5 & 0x80000000 | uVar6;
      }
      else {
        uVar6 = 0;
      }
    }
    uVar5 = uRam300b8800;
    if ((param_3 & 0x10) == 0) {
      uVar5 = DAT_300b8810 | uVar6 & 0x80000000;
    }
    return uVar5;
  }
  *puVar2 = *puVar2 | 8;
  if (SUB41(uVar1 >> 0x1f,0)) {
    if ((uVar1 & 0x7fffffff) == 0) {
      bVar7 = (bool)((byte)(param_3 >> 0x1e) & 1);
      if (!bVar7 || (int)param_3 < 0) {
        uVar3 = uVar3 + 1;
      }
      if (!bVar7) {
        uVar3 = uVar3 & 0xfffffffe;
      }
    }
    else {
      uVar3 = uVar3 + 1;
    }
  }
  uVar5 = __fpl_exception(uVar3);
  return uVar5;
}

/* ----------------------------------------------------------------
 * __funder_d @ 0x300B90CC  (примерный размер ~132 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 2
 * Вызывает: __rt_fp_status_addr, _fp_trapveneer
 * Вызывают: __addsf3, __subsf3, _frsb
 * Константы: 0x01000000, 0x00FF0000, 0xFC000000, 0x00800000, 0x300B90CC, 0x80000000, 0x60000000, 0x00F00000
 * ---------------------------------------------------------------- */
void __funder_d(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)__rt_fp_status_addr();
  if ((*puVar1 & 0x1000000) != 0) {
    return;
  }
  if ((*puVar1 & 0x800) != 0) {
    uVar2 = param_1 & 0x80000000 | 0x60000000;
    if ((param_1 & 0xff0000) == 0) {
      param_1 = param_1 << 8;
      uVar2 = uVar2 + 0xfc000000;
    }
    if ((param_1 & 0xff0000) == 0) {
      param_1 = param_1 << 8;
      uVar2 = uVar2 + 0xfc000000;
    }
    if ((param_1 & 0xf00000) == 0) {
      param_1 = param_1 << 4;
      uVar2 = uVar2 + 0xfe000000;
    }
    if ((param_1 & 0xc00000) == 0) {
      param_1 = param_1 << 2;
      uVar2 = uVar2 - 0x1000000;
    }
    if ((param_1 & 0x800000) == 0) {
      param_1 = param_1 << 1;
    }
    else {
      uVar2 = uVar2 + 0x800000;
    }
    _fp_trapveneer(param_1 & 0xff7fffff | uVar2,uVar2,param_3,param_4);
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * __32__ieee_status @ 0x300B9150  (примерный размер ~60 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: __rt_fp_status_addr
 * Константы: 0x300B9150
 * Данные: DAT_300b9188
 * ---------------------------------------------------------------- */
void __32__ieee_status(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar1 = ~DAT_300b9188;
  uVar2 = ~DAT_300b9188;
  puVar3 = (uint *)__rt_fp_status_addr();
  *puVar3 = *puVar3 & ~(param_1 & uVar2) ^ param_2 & uVar1;
  return;
}

/* ----------------------------------------------------------------
 * __fpl_return_NaN @ 0x300B918C  (примерный размер ~124 байт)
 * Модуль: lib | Вызывают: 18 | Вызывает: 1
 * Вызывает: __rt_fp_status_addr
 * Вызывают: __adddf3, __addsf3, __divdf3, __divsf3, __extendsfdf2, __fpl_dcheck_NaN2, __fpl_dcmp_InfNaN, __fpl_exception, __fpl_fcheck_NaN2, __funder
 *           ...
 * Константы: 0xFFFFFFFF, 0x80000000, 0x7FFFFFFF, 0x300B918C, 0x300B9244, 0x00100000, 0x0FFFFFFF, 0x30000000
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300b9244) */

ulonglong __fpl_return_NaN(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint in_r12;
  bool bVar6;
  
  uVar5 = in_r12 & 0xf;
  if (uVar5 == 9) {
    if ((in_r12 & 0x100000) == 0) {
      uVar5 = in_r12 & 0x80000;
      if (uVar5 != 0) {
        uVar5 = 1;
      }
      return CONCAT44(param_2,uVar5);
    }
    if ((in_r12 & 0xf0000) == 0) {
      puVar3 = (uint *)__rt_fp_status_addr();
      *puVar3 = *puVar3 & 0xfffffff | 0x30000000;
      return 0x3000000000000008;
    }
    return CONCAT44(in_r12,8) & 0xf0000ffffffff;
  }
  bVar6 = uVar5 == 8;
  if (bVar6) {
    uVar5 = in_r12 & 0x40;
  }
  if (!bVar6 || uVar5 != 0x40) {
    return CONCAT44(param_2,param_1);
  }
  if ((in_r12 & 0x10000) != 0) {
    return 0;
  }
  if ((in_r12 & 0x20) != 0) {
    uVar2 = 0xffffffff;
    uVar4 = 0xffffffff;
    if ((param_3 & 0x80000000) != 0) {
      uVar2 = 0;
      uVar4 = 0;
    }
    return CONCAT44(uVar4,uVar2);
  }
  if ((in_r12 & 0x10) == 0) {
    uVar1 = 0x7fffffff;
    uVar5 = param_2;
  }
  else {
    uVar5 = 0x7fffffff;
    uVar1 = 0xffffffff;
    param_1 = param_2;
  }
  if ((param_1 & 0x80000000) != 0) {
    uVar1 = ~uVar1;
    uVar5 = ~uVar5;
  }
  return CONCAT44(uVar5,uVar1);
}

/* ----------------------------------------------------------------
 * __fpl_cmpreturn @ 0x300B922C  (примерный размер ~128 байт)
 * Модуль: lib | Вызывают: 6 | Вызывает: 1
 * Вызывает: __rt_fp_status_addr
 * Вызывают: __divsf3, __extendsfdf2, __fpl_exception, __fpl_fcheck_NaN2, __funder, _fp_trapveneer
 * Константы: 0x300B922C, 0x00100000, 0x30000000, 0x0FFFFFFF
 * ---------------------------------------------------------------- */
ulonglong __fpl_cmpreturn(uint param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  uint in_r12;
  
  if ((in_r12 & 0x100000) == 0) {
    uVar2 = in_r12 & param_1 << 0x10;
    if (uVar2 != 0) {
      uVar2 = 1;
    }
    return CONCAT44(param_2,uVar2);
  }
  if ((in_r12 & 0xf0000) != 0) {
    if ((param_1 & 8) == 0) {
      return CONCAT44(param_2,2 - param_1);
    }
    return CONCAT44(in_r12,param_1) & 0xf0000ffffffff;
  }
  uVar2 = param_1 << 0x1d;
  if ((bool)((byte)(param_1 >> 3) & 1)) {
    uVar2 = uVar2 | 0x30000000;
  }
  puVar1 = (uint *)__rt_fp_status_addr();
  *puVar1 = *puVar1 & 0xfffffff | uVar2;
  return CONCAT44(uVar2,param_1);
}

/* ----------------------------------------------------------------
 * __adddf3 @ 0x300B92AC  (примерный размер ~464 байт)
 * Модуль: lib | Вызывают: 23 | Вызывает: 4
 * Вызывает: __dunder, __dunder_d, __fpl_exception, __fpl_return_NaN
 * Вызывают: FUN_300c4638, FUN_300c505c, __ieee754_rem_pio2, __kernel_cos, __kernel_rem_pio2, __kernel_sin, __kernel_tan, acos, asin, atan
 *           ...
 * Константы: 0x00100000, 0x80000000, 0x7FFFFFFF, 0xFFFFFFFE, 0x00200000, 0xFFDFFFFF, 0xA0000000, 0x300B92AC
 * Данные: DAT_300b9728
 * ---------------------------------------------------------------- */
uint __adddf3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  
  if ((DAT_300b9728 & ~(param_2 << 1)) == 0 || (DAT_300b9728 & ~(param_4 << 1)) == 0) {
    uVar6 = param_2 * 2 + (uint)(param_1 != 0);
    uVar10 = param_4 * 2 + (uint)(param_3 != 0);
    bVar12 = DAT_300b9728 <= uVar6;
    bVar11 = uVar6 == DAT_300b9728;
    if (!bVar12 || bVar11) {
      bVar12 = DAT_300b9728 <= uVar10;
      bVar11 = uVar10 == DAT_300b9728;
    }
    if (bVar12 && !bVar11) {
      uVar10 = param_2 * 2 + 0x100000 + (uint)(param_1 != 0);
      uVar6 = uVar10;
      if (uVar10 < 0xfff00001) {
        uVar6 = param_4 * 2 + 0x100000 + (uint)(param_3 != 0);
      }
      if (0xfff00000 < uVar6) {
        uVar6 = __fpl_exception();
        return uVar6;
      }
      if (0xfffff < uVar10) {
        param_1 = param_3;
        param_2 = param_4;
      }
      uVar6 = __fpl_return_NaN(param_1,param_2);
      return uVar6;
    }
    if (uVar6 == uVar10) {
      if ((int)(param_2 ^ param_4) < 0) {
        uVar6 = __fpl_exception();
        return uVar6;
      }
      return param_1;
    }
    if (uVar6 != DAT_300b9728) {
      return param_3;
    }
    return param_1;
  }
  if ((int)(param_2 ^ param_4) < 0) {
    param_4 = param_4 ^ 0x80000000;
    uVar6 = param_1 - param_3;
    if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
      uVar10 = param_2 - (param_4 + (param_3 > param_1)) ^ 0x80000000;
      bVar11 = CARRY4(param_3,uVar6);
      param_3 = param_3 + uVar6;
      param_4 = param_4 + uVar10 + (uint)bVar11;
      bVar11 = param_1 < uVar6;
      param_1 = param_1 - uVar6;
      param_2 = param_2 - (uVar10 + bVar11);
    }
    uVar6 = param_2 >> 0x14;
    uVar10 = uVar6 - (param_4 >> 0x14);
    if ((DAT_300b9728 & param_4 << 1) == 0) {
      if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
        if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) {
          return param_1;
        }
        goto LAB_300b96bc;
      }
      uVar8 = param_2 & ~(uVar6 << 0x14);
      if ((uVar6 & 0x7ff) == 0) {
        bVar11 = param_1 < param_3;
        param_1 = param_1 - param_3;
        param_2 = uVar8 - (param_4 + bVar11);
        goto LAB_300b96bc;
      }
      uVar10 = uVar10 - 1;
      iVar9 = -((param_4 & 0x7fffffff) + (uint)(param_3 != 0));
    }
    else {
      uVar8 = param_2 & ~(uVar6 << 0x14);
      iVar9 = ((int)DAT_300b9728 >> 1) -
              ((param_4 & ~((int)DAT_300b9728 >> 1)) + (uint)(param_3 != 0));
    }
    uVar4 = -param_3;
    uVar1 = 0x20 - uVar10;
    if (uVar10 < 0x21) {
      uVar3 = uVar4 >> (uVar10 & 0xff);
      uVar2 = param_1 + uVar3;
      uVar8 = uVar8 + (iVar9 >> (uVar10 & 0xff)) + (uint)CARRY4(param_1,uVar3);
      uVar10 = iVar9 << (uVar1 & 0xff);
      uVar3 = uVar2 + uVar10;
      bVar11 = CARRY4(uVar8,(uint)CARRY4(uVar2,uVar10));
      iVar9 = uVar8 + CARRY4(uVar2,uVar10);
    }
    else {
      param_3 = param_3 * -2;
      if (param_3 != 0) {
        param_3 = 1;
      }
      uVar4 = param_3 | (iVar9 * 2 + (uint)CARRY4(uVar4,uVar4)) * 2;
      uVar10 = uVar10 - 0x20;
      uVar1 = 0x1e - uVar10;
      if (0x1e < uVar10 || uVar1 == 0) {
        return param_1;
      }
      uVar10 = iVar9 >> (uVar10 & 0xff);
      uVar3 = param_1 + uVar10;
      bVar11 = uVar8 != 0 || uVar8 < CARRY4(param_1,uVar10);
      iVar9 = uVar8 - !CARRY4(param_1,uVar10);
    }
    if (-1 < iVar9) {
      iVar9 = uVar4 << (uVar1 & 0xff);
      if (-1 < iVar9) {
        return uVar3;
      }
      uVar3 = uVar3 + 1;
      if (uVar3 == 0 || iVar9 == -0x80000000) {
        if (uVar3 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = uVar3 & 0xfffffffe;
        }
        return uVar3;
      }
      return uVar3;
    }
    uVar10 = uVar1 + 1 & 0xff;
    bVar11 = uVar10 == 0 && bVar11 || uVar10 != 0 && (bool)((byte)(uVar4 >> 0x20 - uVar10) & 1);
    uVar8 = uVar3 * 2 + (uint)bVar11;
    iVar9 = iVar9 * 2 + (uint)(CARRY4(uVar3,uVar3) || CARRY4(uVar3 * 2,(uint)bVar11));
    uVar1 = iVar9 + uVar6 * 0x200000;
    bVar11 = (bool)((byte)(uVar1 >> 0x14) & 1);
    if (bVar11 && uVar1 >> 0x15 != 0) {
      uVar6 = -((int)(uVar4 << uVar10) >> 0x1f);
      uVar1 = uVar8 + uVar6;
      bVar11 = uVar1 == 0;
      if (!CARRY4(uVar8,uVar6)) {
        bVar11 = uVar4 << uVar10 == -0x80000000;
      }
      if (bVar11) {
        if (uVar1 == 0) {
          uVar1 = 0;
        }
        else {
          uVar1 = uVar1 & 0xfffffffe;
        }
        return uVar1;
      }
      return uVar1;
    }
    if (!bVar11) {
      iVar9 = iVar9 + 0x200000;
      if (iVar9 == 0 && uVar8 == 0) {
        return uVar8;
      }
      iVar5 = LZCOUNT(iVar9);
      if (iVar5 == 0x20) {
        iVar5 = LZCOUNT(uVar8) + 0x20;
      }
      uVar10 = iVar5 - 0xb;
      iVar7 = ((uVar6 & 0xfffff7ff) - 2) - uVar10;
      if (uVar10 < 0x20) {
        uVar6 = iVar9 << (uVar10 & 0xff) | uVar8 >> (0x20 - uVar10 & 0xff);
        uVar8 = uVar8 << (uVar10 & 0xff);
      }
      else {
        uVar6 = uVar8 << (iVar5 - 0x2bU & 0xff);
        uVar8 = 0;
      }
      if (iVar7 < 1) {
        uVar6 = __dunder(uVar8,uVar6 + (param_2 & 0x80000000) + iVar7 * 0x100000 + 0x60000000);
        return uVar6;
      }
      return uVar8;
    }
    param_1 = (uint)((byte)iVar9 & 1) << 0x1f | uVar8 >> 1;
    param_2 = (iVar9 >> 1) + uVar6 * 0x100000;
    goto LAB_300b96bc;
  }
  uVar6 = param_1 - param_3;
  iVar9 = param_2 - (param_4 + (param_3 > param_1));
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar11 = CARRY4(param_3,uVar6);
    param_3 = param_3 + uVar6;
    param_4 = param_4 + iVar9 + (uint)bVar11;
    bVar11 = param_1 < uVar6;
    param_1 = param_1 - uVar6;
    param_2 = param_2 - (iVar9 + (uint)bVar11);
  }
  uVar6 = param_2 >> 0x14;
  uVar10 = uVar6 - (param_4 >> 0x14);
  if ((DAT_300b9728 & param_4 << 1) == 0) {
    if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) {
      if ((uVar6 & 0x7ff) != 0) {
        return param_1;
      }
      if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) {
        return param_1;
      }
LAB_300b96bc:
      if (param_2 << 1 == 0 && param_1 == 0) {
        return param_1;
      }
      if (param_2 << 1 < 0x200000) {
        uVar6 = __dunder_d();
        return uVar6;
      }
      return param_1;
    }
    param_2 = param_2 & ~(uVar6 << 0x14);
    if ((uVar6 & 0x7ff) == 0) {
      bVar11 = CARRY4(param_1,param_3);
      param_1 = param_1 + param_3;
      param_2 = param_2 + param_4 + (uint)bVar11;
      goto LAB_300b96bc;
    }
    param_4 = param_4 & 0x7fffffff;
    uVar10 = uVar10 - 1;
  }
  else {
    param_2 = param_2 & ~(uVar6 << 0x14);
    param_4 = param_4 & ~DAT_300b9728 | 0x100000;
  }
  uVar8 = 0x20 - uVar10;
  if (uVar10 < 0x21) {
    uVar1 = param_3 >> (uVar10 & 0xff);
    bVar11 = CARRY4(param_1,uVar1);
    uVar1 = param_1 + uVar1;
    uVar4 = param_4 << (uVar8 & 0xff);
    param_1 = uVar1 + uVar4;
    uVar4 = param_2 + (param_4 >> (uVar10 & 0xff)) + (uint)bVar11 + (uint)CARRY4(uVar1,uVar4);
    if (0xfffff < uVar4) {
LAB_300b938c:
      uVar10 = (uVar4 + 0x100000 >> 1) + uVar6 * 0x100000;
      bVar11 = (bool)((byte)param_1 & 1);
      uVar6 = (uint)((byte)(uVar4 + 0x100000) & 1) << 0x1f | param_1 >> 1;
      if (!bVar11) {
LAB_300b93c4:
        if (0xffdfffff < uVar10 * 2) {
          uVar6 = __fpl_exception(uVar6,uVar10 + 0xa0000000);
          return uVar6;
        }
        return uVar6;
      }
      bVar12 = CARRY4(uVar6,(uint)bVar11);
      uVar6 = uVar6 + bVar11;
      uVar4 = uVar6;
      if (!bVar12) {
        uVar4 = param_3 << (uVar8 & 0xff);
      }
      if (uVar4 != 0) goto LAB_300b93c4;
      goto LAB_300b9340;
    }
    uVar10 = uVar4 + uVar6 * 0x100000;
  }
  else {
    param_3 = param_4 * 2 + (uint)(param_3 != 0);
    uVar10 = uVar10 - 0x20;
    bVar11 = uVar10 < 0x20;
    uVar8 = 0x1f - uVar10;
    if (bVar11) {
      param_4 = param_4 >> (uVar10 & 0xff);
      bVar11 = CARRY4(param_1,param_4);
      param_1 = param_1 + param_4;
    }
    else {
      uVar8 = 0;
    }
    uVar10 = param_2 + uVar6 * 0x100000 + (uint)bVar11;
    if (uVar6 != uVar10 >> 0x14) {
      uVar4 = uVar10 + uVar6 * -0x100000;
      goto LAB_300b938c;
    }
  }
  iVar9 = param_3 << (uVar8 & 0xff);
  if (-1 < iVar9) {
    return param_1;
  }
  uVar6 = param_1 + 1;
  uVar8 = uVar6;
  if (param_1 != 0xffffffff) {
    uVar8 = iVar9 << 1;
  }
  if (uVar8 != 0) {
    return uVar6;
  }
LAB_300b9340:
  if (uVar6 == 0) {
    uVar10 = uVar10 + 1;
    uVar6 = 0;
  }
  else {
    uVar6 = uVar6 & 0xfffffffe;
  }
  bVar11 = 0xffdfffff < uVar10 << 1;
  if (bVar11) {
    if (bVar11) {
      uVar10 = uVar10 + 0xa0000000;
    }
    uVar6 = __fpl_exception(uVar6,uVar10);
    return uVar6;
  }
  return uVar6;
}

/* ----------------------------------------------------------------
 * __subdf3 @ 0x300B94C0  (примерный размер ~632 байт)
 * Модуль: lib | Вызывают: 22 | Вызывает: 4
 * Вызывает: __dunder, __dunder_d, __fpl_exception, __fpl_return_NaN
 * Вызывают: __ieee754_rem_pio2, __kernel_cos, __kernel_rem_pio2, __kernel_sin, __kernel_tan, acos, asin, atan, atan2, cos
 *           ...
 * Константы: 0x00100000, 0x80000000, 0x7FFFFFFF, 0xFFFFFFFE, 0xFFF00001, 0xA0000000, 0x00200000, 0x300B94C0
 * Данные: DAT_300b9728
 * ---------------------------------------------------------------- */
ulonglong __subdf3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  ulonglong uVar13;
  
  if ((DAT_300b9728 & ~(param_2 << 1)) == 0 || (DAT_300b9728 & ~(param_4 << 1)) == 0) {
    uVar7 = param_2 * 2 + (uint)(param_1 != 0);
    uVar10 = param_4 * 2 + (uint)(param_3 != 0);
    bVar12 = DAT_300b9728 <= uVar7;
    bVar11 = uVar7 == DAT_300b9728;
    if (!bVar12 || bVar11) {
      bVar12 = DAT_300b9728 <= uVar10;
      bVar11 = uVar10 == DAT_300b9728;
    }
    if (bVar12 && !bVar11) {
      uVar10 = param_2 * 2 + 0x100000 + (uint)(param_1 != 0);
      uVar7 = uVar10;
      if (uVar10 < 0xfff00001) {
        uVar7 = param_4 * 2 + 0x100000 + (uint)(param_3 != 0);
      }
      if (uVar7 < 0xfff00001) {
        if (0xfffff < uVar10) {
          param_1 = param_3;
          param_2 = param_4;
        }
        uVar13 = __fpl_return_NaN(param_1,param_2);
        return uVar13;
      }
      uVar13 = __fpl_exception();
      return uVar13;
    }
    if (uVar7 == uVar10) {
      if ((int)(param_2 ^ param_4) < 0) {
        return CONCAT44(param_2,param_1);
      }
      uVar13 = __fpl_exception();
      return uVar13;
    }
    if (uVar7 == DAT_300b9728) {
      return CONCAT44(param_2,param_1);
    }
    return CONCAT44(param_4,param_3) ^ 0x8000000000000000;
  }
  if ((int)(param_2 ^ param_4) < 0) {
    param_4 = param_4 ^ 0x80000000;
    uVar7 = param_1 - param_3;
    iVar6 = param_2 - (param_4 + (param_3 > param_1));
    if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
      bVar11 = CARRY4(param_3,uVar7);
      param_3 = param_3 + uVar7;
      param_4 = param_4 + iVar6 + (uint)bVar11;
      bVar11 = param_1 < uVar7;
      param_1 = param_1 - uVar7;
      param_2 = param_2 - (iVar6 + (uint)bVar11);
    }
    uVar7 = param_2 >> 0x14;
    uVar10 = uVar7 - (param_4 >> 0x14);
    if ((DAT_300b9728 & param_4 << 1) == 0) {
      if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) {
        if ((uVar7 & 0x7ff) != 0) {
          return CONCAT44(param_2,param_1);
        }
        if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) {
          return CONCAT44(param_2,param_1);
        }
      }
      else {
        param_2 = param_2 & ~(uVar7 << 0x14);
        if ((uVar7 & 0x7ff) != 0) {
          param_4 = param_4 & 0x7fffffff;
          uVar10 = uVar10 - 1;
          goto LAB_300b9304;
        }
        bVar11 = CARRY4(param_1,param_3);
        param_1 = param_1 + param_3;
        param_2 = param_2 + param_4 + (uint)bVar11;
      }
      goto LAB_300b96bc;
    }
    param_2 = param_2 & ~(uVar7 << 0x14);
    param_4 = param_4 & ~DAT_300b9728 | 0x100000;
LAB_300b9304:
    uVar3 = 0x20 - uVar10;
    if (uVar10 < 0x21) {
      uVar9 = param_3 >> (uVar10 & 0xff);
      bVar11 = CARRY4(param_1,uVar9);
      uVar9 = param_1 + uVar9;
      uVar4 = param_4 << (uVar3 & 0xff);
      param_1 = uVar9 + uVar4;
      uVar4 = param_2 + (param_4 >> (uVar10 & 0xff)) + (uint)bVar11 + (uint)CARRY4(uVar9,uVar4);
      if (0xfffff < uVar4) {
LAB_300b938c:
        uVar10 = (uVar4 + 0x100000 >> 1) + uVar7 * 0x100000;
        bVar11 = (bool)((byte)param_1 & 1);
        uVar7 = (uint)((byte)(uVar4 + 0x100000) & 1) << 0x1f | param_1 >> 1;
        if (!bVar11) {
LAB_300b93c4:
          if (uVar10 * 2 < 0xffe00000) {
            return CONCAT44(uVar10,uVar7);
          }
          uVar13 = __fpl_exception(uVar7,uVar10 + 0xa0000000);
          return uVar13;
        }
        bVar12 = CARRY4(uVar7,(uint)bVar11);
        uVar7 = uVar7 + bVar11;
        uVar4 = uVar7;
        if (!bVar12) {
          uVar4 = param_3 << (uVar3 & 0xff);
        }
        if (uVar4 != 0) goto LAB_300b93c4;
        goto LAB_300b9340;
      }
      uVar10 = uVar4 + uVar7 * 0x100000;
    }
    else {
      param_3 = param_4 * 2 + (uint)(param_3 != 0);
      uVar10 = uVar10 - 0x20;
      bVar11 = uVar10 < 0x20;
      uVar3 = 0x1f - uVar10;
      if (bVar11) {
        param_4 = param_4 >> (uVar10 & 0xff);
        bVar11 = CARRY4(param_1,param_4);
        param_1 = param_1 + param_4;
      }
      else {
        uVar3 = 0;
      }
      uVar10 = param_2 + uVar7 * 0x100000 + (uint)bVar11;
      if (uVar7 != uVar10 >> 0x14) {
        uVar4 = uVar10 + uVar7 * -0x100000;
        goto LAB_300b938c;
      }
    }
    iVar6 = param_3 << (uVar3 & 0xff);
    if (-1 < iVar6) {
      return CONCAT44(uVar10,param_1);
    }
    uVar7 = param_1 + 1;
    uVar3 = uVar7;
    if (param_1 != 0xffffffff) {
      uVar3 = iVar6 << 1;
    }
    if (uVar3 != 0) {
      return CONCAT44(uVar10,uVar7);
    }
LAB_300b9340:
    if (uVar7 == 0) {
      uVar10 = uVar10 + 1;
      uVar7 = 0;
    }
    else {
      uVar7 = uVar7 & 0xfffffffe;
    }
    bVar11 = 0xffdfffff < uVar10 << 1;
    if (!bVar11) {
      return CONCAT44(uVar10,uVar7);
    }
    if (bVar11) {
      uVar10 = uVar10 + 0xa0000000;
    }
    uVar13 = __fpl_exception(uVar7,uVar10);
    return uVar13;
  }
  uVar7 = param_1 - param_3;
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    uVar10 = param_2 - (param_4 + (param_3 > param_1)) ^ 0x80000000;
    bVar11 = CARRY4(param_3,uVar7);
    param_3 = param_3 + uVar7;
    param_4 = param_4 + uVar10 + (uint)bVar11;
    bVar11 = param_1 < uVar7;
    param_1 = param_1 - uVar7;
    param_2 = param_2 - (uVar10 + bVar11);
  }
  uVar7 = param_2 >> 0x14;
  uVar10 = uVar7 - (param_4 >> 0x14);
  if ((DAT_300b9728 & param_4 << 1) == 0) {
    if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
      if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) goto LAB_300b96b0;
    }
    else {
      uVar3 = param_2 & ~(uVar7 << 0x14);
      if ((uVar7 & 0x7ff) != 0) {
        uVar10 = uVar10 - 1;
        iVar6 = -((param_4 & 0x7fffffff) + (uint)(param_3 != 0));
        goto LAB_300b9520;
      }
      bVar11 = param_1 < param_3;
      param_1 = param_1 - param_3;
      param_2 = uVar3 - (param_4 + bVar11);
    }
  }
  else {
    uVar3 = param_2 & ~(uVar7 << 0x14);
    iVar6 = ((int)DAT_300b9728 >> 1) -
            ((param_4 & ~((int)DAT_300b9728 >> 1)) + (uint)(param_3 != 0));
LAB_300b9520:
    uVar4 = -param_3;
    uVar9 = 0x20 - uVar10;
    if (uVar10 < 0x21) {
      uVar2 = uVar4 >> (uVar10 & 0xff);
      uVar1 = param_1 + uVar2;
      uVar3 = uVar3 + (iVar6 >> (uVar10 & 0xff)) + (uint)CARRY4(param_1,uVar2);
      uVar10 = iVar6 << (uVar9 & 0xff);
      uVar2 = uVar1 + uVar10;
      bVar11 = CARRY4(uVar3,(uint)CARRY4(uVar1,uVar10));
      iVar6 = uVar3 + CARRY4(uVar1,uVar10);
    }
    else {
      param_3 = param_3 * -2;
      if (param_3 != 0) {
        param_3 = 1;
      }
      uVar4 = param_3 | (iVar6 * 2 + (uint)CARRY4(uVar4,uVar4)) * 2;
      uVar10 = uVar10 - 0x20;
      uVar9 = 0x1e - uVar10;
      if (0x1e < uVar10 || uVar9 == 0) {
        return CONCAT44(uVar3 + uVar7 * 0x100000,param_1);
      }
      uVar10 = iVar6 >> (uVar10 & 0xff);
      uVar2 = param_1 + uVar10;
      bVar11 = uVar3 != 0 || uVar3 < CARRY4(param_1,uVar10);
      iVar6 = uVar3 - !CARRY4(param_1,uVar10);
    }
    if (-1 < iVar6) {
      iVar6 = iVar6 + uVar7 * 0x100000;
      iVar5 = uVar4 << (uVar9 & 0xff);
      if (-1 < iVar5) {
        return CONCAT44(iVar6,uVar2);
      }
      uVar2 = uVar2 + 1;
      if (uVar2 != 0 && iVar5 != -0x80000000) {
        return CONCAT44(iVar6,uVar2);
      }
      if (uVar2 == 0) {
        iVar6 = iVar6 + 1;
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 & 0xfffffffe;
      }
      return CONCAT44(iVar6,uVar2);
    }
    uVar10 = uVar9 + 1 & 0xff;
    bVar11 = uVar10 == 0 && bVar11 || uVar10 != 0 && (bool)((byte)(uVar4 >> 0x20 - uVar10) & 1);
    param_1 = uVar2 * 2 + (uint)bVar11;
    iVar6 = iVar6 * 2 + (uint)(CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar11));
    uVar3 = iVar6 + uVar7 * 0x200000;
    bVar11 = (bool)((byte)(uVar3 >> 0x14) & 1);
    if (bVar11 && uVar3 >> 0x15 != 0) {
      iVar6 = iVar6 + uVar7 * 0x100000;
      uVar7 = -((int)(uVar4 << uVar10) >> 0x1f);
      uVar3 = param_1 + uVar7;
      bVar11 = uVar3 == 0;
      if (!CARRY4(param_1,uVar7)) {
        bVar11 = uVar4 << uVar10 == -0x80000000;
      }
      if (!bVar11) {
        return CONCAT44(iVar6,uVar3);
      }
      if (uVar3 == 0) {
        iVar6 = iVar6 + 1;
        uVar3 = 0;
      }
      else {
        uVar3 = uVar3 & 0xfffffffe;
      }
      return CONCAT44(iVar6,uVar3);
    }
    if (!bVar11) {
      iVar6 = iVar6 + 0x200000;
      if (iVar6 != 0 || param_1 != 0) {
        iVar5 = LZCOUNT(iVar6);
        if (iVar5 == 0x20) {
          iVar5 = LZCOUNT(param_1) + 0x20;
        }
        uVar10 = iVar5 - 0xb;
        iVar8 = ((uVar7 & 0xfffff7ff) - 2) - uVar10;
        if (uVar10 < 0x20) {
          uVar7 = iVar6 << (uVar10 & 0xff) | param_1 >> (0x20 - uVar10 & 0xff);
          iVar6 = param_1 << (uVar10 & 0xff);
        }
        else {
          uVar7 = param_1 << (iVar5 - 0x2bU & 0xff);
          iVar6 = 0;
        }
        iVar5 = uVar7 + (param_2 & 0x80000000) + iVar8 * 0x100000;
        if (0 < iVar8) {
          return CONCAT44(iVar5,iVar6);
        }
        uVar13 = __dunder(iVar6,iVar5 + 0x60000000);
        return uVar13;
      }
      goto LAB_300b96b0;
    }
    param_1 = (uint)((byte)iVar6 & 1) << 0x1f | param_1 >> 1;
    param_2 = (iVar6 >> 1) + uVar7 * 0x100000;
  }
LAB_300b96bc:
  if (param_2 << 1 != 0 || param_1 != 0) {
    if (0x1fffff < param_2 << 1) {
      return CONCAT44(param_2,param_1);
    }
    uVar13 = __dunder_d();
    return uVar13;
  }
LAB_300b96b0:
  return (ulonglong)param_1;
}

/* ----------------------------------------------------------------
 * __floatsidf @ 0x300B9744  (примерный размер ~16 байт)
 * Модуль: lib | Вызывают: 13 | Вызывает: 0
 * Вызывают: FUN_300c4448, FUN_300c505c, FUN_301092d0, FUN_3010a8cc, __ieee754_rem_pio2, __kernel_rem_pio2, __kernel_tan, exp, expm1, log
 *           ...
 * Константы: 0x300B9744, 0x80000000, 0x40000000, 0x01F00000, 0x00100000
 * ---------------------------------------------------------------- */
ulonglong __floatsidf(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0x80000000;
  if (uVar2 != 0) {
    param_1 = -param_1;
  }
  iVar1 = param_1 << LZCOUNT(param_1);
  if (iVar1 == 0) {
    return (ulonglong)(uint)(iVar1 << 0x15);
  }
  return CONCAT44((uVar2 | 0x40000000) + 0x1f00000 + LZCOUNT(param_1) * -0x100000 + (iVar1 >> 0xb),
                  iVar1 << 0x15);
}

/* ----------------------------------------------------------------
 * __dflt_normalise @ 0x300B9754  (примерный размер ~32 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: __extendsfdf2, _d_utod
 * Константы: 0x300B9754, 0x01F00000, 0x00100000
 * ---------------------------------------------------------------- */
ulonglong __dflt_normalise(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = param_2 << LZCOUNT(param_2);
  if (iVar1 == 0) {
    return (ulonglong)(uint)(iVar1 << 0x15);
  }
  return CONCAT44(param_4 + 0x1f00000 + LZCOUNT(param_2) * -0x100000 + (iVar1 >> 0xb),iVar1 << 0x15)
  ;
}

/* ----------------------------------------------------------------
 * __floatdidf @ 0x300B977C  (примерный размер ~116 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3010891c
 * Константы: 0x300B977C, 0x80000000, 0x00200000, 0x42000000, 0x00300000, 0x00100000
 * ---------------------------------------------------------------- */
undefined8 __floatdidf(uint param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar3 = param_2 & 0x80000000;
  if ((int)uVar3 < 0) {
    bVar7 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(param_2 + bVar7);
  }
  if (param_2 != 0) {
    iVar4 = 0x20;
    uVar6 = param_2;
  }
  else {
    iVar4 = 0;
    uVar6 = param_1;
  }
  if (param_2 != 0 || param_1 != 0) {
    uVar5 = iVar4 - LZCOUNT(uVar6);
    uVar6 = uVar6 << LZCOUNT(uVar6) | param_1 >> (uVar5 & 0xff);
    param_1 = param_1 << (0x20 - uVar5 & 0xff);
    bVar2 = (byte)(param_1 >> 10);
    if ((param_1 & 0x3ff) == 0) {
      bVar2 = (byte)((param_1 & param_1 >> 1) >> 10);
    }
    param_1 = param_1 >> 0xb;
    uVar1 = uVar6 * 0x200000;
    return CONCAT44(((uVar3 | 0x42000000) - 0x300000) + uVar5 * 0x100000 + (uVar6 >> 0xb) +
                    (uint)(CARRY4(param_1,uVar1) || CARRY4(param_1 + uVar1,(uint)(bVar2 & 1))),
                    param_1 + uVar1 + (uint)(bVar2 & 1));
  }
  return CONCAT44(uVar6,param_1);
}

/* ----------------------------------------------------------------
 * __muldf3 @ 0x300B97F0  (примерный размер ~688 байт)
 * Модуль: lib | Вызывают: 23 | Вызывает: 4
 * Вызывает: __fpl_exception, __fpl_return_NaN, __rt_fp_status_addr, _fp_trapveneer
 * Вызывают: FUN_300c4448, FUN_300c4638, FUN_300c505c, __ieee754_rem_pio2, __kernel_cos, __kernel_rem_pio2, __kernel_sin, __kernel_tan, acos, asin
 *           ...
 * Константы: 0x7FFFFFFF, 0x00100000, 0x80000000, 0x00130000, 0x00140000, 0xFFFFFFFE, 0xC0000000, 0x04000000
 * Данные: DAT_300b9a94, DAT_300b9a98
 * ---------------------------------------------------------------- */
uint __muldf3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  
  if ((DAT_300b9a94 & ~(param_2 >> 4)) == 0 || (DAT_300b9a94 & ~(param_4 >> 4)) == 0) {
    uVar8 = param_2 * 2;
    uVar14 = DAT_300b9a94 * 0x20;
    bVar19 = uVar8 == uVar14;
    bVar18 = bVar19 && param_1 == 0;
    bVar20 = bVar19 || uVar14 <= uVar8;
    if (!bVar19 && uVar14 > uVar8 || bVar19 && param_1 == 0) {
      bVar20 = DAT_300b9a94 * 0x20 <= param_4 * 2;
      bVar18 = param_4 * 2 == DAT_300b9a94 * 0x20;
    }
    if (bVar18) {
      bVar18 = param_3 == 0;
      bVar20 = true;
    }
    if (!bVar20 || bVar18) {
      if (param_1 == 0 && (param_2 & 0x7fffffff) == 0 || param_3 == 0 && (param_4 & 0x7fffffff) == 0
         ) {
        uVar8 = __fpl_exception();
        return uVar8;
      }
      return 0;
    }
    uVar14 = param_2 * 2 + 0x100000 + (uint)(param_1 != 0);
    uVar8 = uVar14;
    if (uVar14 < 0xfff00001) {
      uVar8 = param_4 * 2 + 0x100000 + (uint)(param_3 != 0);
    }
    if (0xfff00000 < uVar8) {
      uVar8 = __fpl_exception();
      return uVar8;
    }
    if (0xfffff < uVar14) {
      param_1 = param_3;
      param_2 = param_4;
    }
    uVar8 = __fpl_return_NaN(param_1,param_2);
    return uVar8;
  }
  uVar14 = DAT_300b9a94 & param_2 >> 4;
  uVar15 = uVar14 | (param_2 ^ param_4) >> 0x1f;
  uVar8 = DAT_300b9a94 & param_4 >> 4;
  if (uVar8 == 0 || (param_2 & DAT_300b9a94 << 4) == 0) {
    if (param_1 == 0 && (param_2 & 0x7fffffff) == 0 || param_3 == 0 && (param_4 & 0x7fffffff) == 0)
    {
      return 0;
    }
    if (uVar8 == 0) {
      iVar16 = 0x10000;
      param_4 = param_4 & 0x7fffffff;
      if (param_4 == 0 && param_3 >> 0xc == 0) {
        param_3 = param_3 << 0x14;
        iVar16 = -0x130000;
      }
      uVar9 = param_3;
      if (param_4 == 0) {
        param_4 = param_3 >> 0xc;
        uVar9 = param_3 << 0x14;
        iVar16 = iVar16 + -0x140000;
      }
      uVar10 = 0;
      if (param_4 >> 5 == 0) {
        param_4 = param_4 << 0x10;
        uVar10 = 0x10;
      }
      if (param_4 >> 0xd == 0) {
        param_4 = param_4 << 8;
        uVar10 = uVar10 + 8;
      }
      if (param_4 >> 0x11 == 0) {
        param_4 = param_4 << 4;
        uVar10 = uVar10 + 4;
      }
      if (param_4 >> 0x13 == 0) {
        param_4 = param_4 << 2;
        uVar10 = uVar10 + 2;
      }
      if (param_4 >> 0x14 == 0) {
        param_4 = param_4 << 1;
        uVar10 = uVar10 + 1;
      }
      uVar8 = iVar16 + uVar10 * -0x10000;
      param_3 = uVar9 << (uVar10 & 0xff);
      param_4 = param_4 | uVar9 >> (0x20 - uVar10 & 0xff);
    }
    if ((uVar14 & 0xfffffffe) == 0) {
      iVar16 = uVar15 + 0x10000;
      param_2 = param_2 & 0x7fffffff;
      if (param_2 == 0 && param_1 >> 0xc == 0) {
        param_1 = param_1 << 0x14;
        iVar16 = uVar15 - 0x130000;
      }
      uVar14 = param_1;
      if (param_2 == 0) {
        param_2 = param_1 >> 0xc;
        uVar14 = param_1 << 0x14;
        iVar16 = iVar16 + -0x140000;
      }
      uVar9 = 0;
      if (param_2 >> 5 == 0) {
        param_2 = param_2 << 0x10;
        uVar9 = 0x10;
      }
      if (param_2 >> 0xd == 0) {
        param_2 = param_2 << 8;
        uVar9 = uVar9 + 8;
      }
      if (param_2 >> 0x11 == 0) {
        param_2 = param_2 << 4;
        uVar9 = uVar9 + 4;
      }
      if (param_2 >> 0x13 == 0) {
        param_2 = param_2 << 2;
        uVar9 = uVar9 + 2;
      }
      if (param_2 >> 0x14 == 0) {
        param_2 = param_2 << 1;
        uVar9 = uVar9 + 1;
      }
      uVar15 = iVar16 + uVar9 * -0x10000;
      param_1 = uVar14 << (uVar9 & 0xff);
      param_2 = param_2 | uVar14 >> (0x20 - uVar9 & 0xff);
    }
  }
  iVar16 = uVar15 + uVar8;
  iVar17 = iVar16 + -0x3fc0000;
  uVar8 = param_2 & ~(DAT_300b9a94 << 5) | 0x100000;
  uVar14 = param_4 & ~(DAT_300b9a94 << 5) | 0x100000;
  lVar1 = (ulonglong)param_3 * (ulonglong)uVar8;
  uVar11 = (uint)((ulonglong)lVar1 >> 0x20);
  lVar2 = (ulonglong)uVar14 * (ulonglong)param_1;
  uVar15 = (uint)((ulonglong)lVar2 >> 0x20);
  lVar4 = lVar1 + lVar2;
  uVar9 = (uint)((ulonglong)lVar4 >> 0x20);
  lVar3 = (ulonglong)uVar14 * (ulonglong)uVar8;
  uVar14 = (uint)lVar3;
  uVar12 = (uint)((ulonglong)param_3 * (ulonglong)param_1 >> 0x20);
  lVar5 = lVar4 + CONCAT44(uVar14,uVar12);
  uVar8 = (uint)lVar5;
  uVar10 = (uint)((ulonglong)lVar5 >> 0x20);
  uVar14 = (int)((ulonglong)lVar3 >> 0x20) +
           (uint)(CARRY4(uVar15,uVar11) ||
                 CARRY4(uVar15 + uVar11,(uint)CARRY4((uint)lVar2,(uint)lVar1))) +
           (uint)(CARRY4(uVar9,uVar14) || CARRY4(uVar9 + uVar14,(uint)CARRY4((uint)lVar4,uVar12)));
  if ((int)((ulonglong)param_3 * (ulonglong)param_1) != 0) {
    uVar8 = uVar8 | 1;
  }
  iVar13 = (0x1ff < uVar14) + 0x14;
  iVar7 = (iVar17 >> 0x10) + -4 + (uint)(0x1ff < uVar14);
  uVar11 = 0x20 - iVar13;
  uVar15 = uVar10 << (uVar11 & 0xff) | uVar8 >> iVar13;
  uVar9 = (uVar14 << (uVar11 & 0xff) | uVar10 >> iVar13) + iVar7 * 0x100000 ^ iVar16 * -0x80000000;
  uVar8 = uVar8 << (uVar11 & 0xff);
  if (uVar8 != 0) {
    bVar18 = SUB41(uVar8 >> 0x1f,0);
    if (bVar18) {
      if ((uVar8 & 0x7fffffff) == 0) {
        uVar14 = uVar14 | 0x80000000;
      }
      uVar10 = uVar15 + bVar18;
      uVar9 = uVar9 + CARRY4(uVar15,(uint)bVar18);
      uVar8 = 0x40000000;
      uVar15 = uVar10 & ~(uVar14 >> 0x1f);
      if ((uVar10 & uVar14 >> 0x1f) != 0) {
        uVar8 = 0xc0000000;
      }
    }
    else {
      uVar8 = 0xc0000000;
    }
  }
  if ((-1 < (int)(uVar9 ^ iVar16 * -0x80000000)) &&
     ((uVar9 & DAT_300b9a98) != 0 && (DAT_300b9a98 & ~uVar9) != 0)) {
    return uVar15;
  }
  bVar20 = SBORROW4(iVar17,0x4000000);
  bVar18 = iVar16 + -0x7fc0000 < 0;
  if (iVar17 < 0x4000001) {
    uVar9 = uVar9 + 0x60000000;
  }
  if (bVar18 == bVar20) {
    uVar9 = uVar9 + 0xa0000000;
  }
  uVar14 = uVar8 | 0x13;
  if (bVar18 == bVar20) {
    uVar14 = uVar8 | 0x10000013;
  }
  if (iVar17 != 0x4000000 && bVar18 == bVar20) {
    uVar8 = __fpl_exception();
    return uVar8;
  }
  puVar6 = (uint *)__rt_fp_status_addr();
  if ((*puVar6 & 0x1000000) != 0) {
    return 0;
  }
  if ((*puVar6 & 0x800) == 0) {
    if ((int)uVar9 < 0) {
      uVar14 = uVar14 | 0x10000;
    }
    uVar8 = uVar9 & ~((uVar9 >> 0x14) << 0x14);
    iVar16 = -(uVar9 >> 0x14 & 0xfffff7ff);
    uVar10 = iVar16 + 0x601;
    uVar9 = uVar8 | 0x100000;
    if (uVar10 < 0x36) {
      if (uVar10 == 0x35) {
        uVar10 = 0;
        uVar11 = 0x80000000;
        if (uVar15 != 0 || (uVar8 & 0xfffff) != 0) {
          uVar11 = 0x80000001;
        }
      }
      else if (uVar10 < 0x15) {
        uVar11 = uVar15 << (0x20 - uVar10 & 0xff);
        uVar10 = uVar9 << (0x20 - uVar10 & 0xff) | uVar15 >> (uVar10 & 0xff);
      }
      else {
        uVar8 = iVar16 + 0x5e1;
        if (uVar10 < 0x20 || uVar8 == 0) {
          uVar10 = uVar9 << (-uVar8 & 0xff) | uVar15 >> (uVar10 & 0xff);
          uVar11 = uVar15 << (-uVar8 & 0xff);
        }
        else {
          uVar10 = uVar9 >> (uVar8 & 0xff);
          uVar11 = uVar9 << (0x20 - uVar8 & 0xff);
          if (uVar15 != 0) {
            uVar11 = uVar11 | 1;
          }
        }
      }
    }
    else {
      uVar11 = 1;
      uVar10 = 0;
    }
    if (uVar11 != 0) {
      if (SUB41(uVar11 >> 0x1f,0)) {
        if (((uVar11 & 0x7fffffff) == 0) && (-1 < (int)uVar14 >> 0x1e)) {
          if ((int)uVar14 >> 0x1e == 0) {
            uVar10 = uVar10 + 1 & 0xfffffffe;
          }
        }
        else {
          uVar10 = uVar10 + 1;
        }
      }
      puVar6 = (uint *)__rt_fp_status_addr();
      *puVar6 = *puVar6 | 8;
      return uVar10;
    }
    return uVar10;
  }
  uVar8 = _fp_trapveneer(uVar15,uVar9,iVar7);
  return uVar8;
}

/* ----------------------------------------------------------------
 * __addsf3 @ 0x300B9AA0  (примерный размер ~324 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 5
 * Вызывает: __fpl_exception, __fpl_return_NaN, __funder_d, __rt_fp_status_addr, _fp_trapveneer
 * Константы: 0x80000000, 0x00800000, 0xFF000000, 0x7F800000, 0x7FFFFFFF, 0xFFFFFFFE, 0xFEFFFFFF, 0x300B9AA0
 * Данные: DAT_300b8820
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300b86f0) */
/* WARNING: Removing unreachable block (ram,0x300b8794) */
/* WARNING: Removing unreachable block (ram,0x300b87a0) */
/* WARNING: Removing unreachable block (ram,0x300b87c0) */
/* WARNING: Removing unreachable block (ram,0x300b8788) */
/* WARNING: Removing unreachable block (ram,0x300b8778) */
/* WARNING: Removing unreachable block (ram,0x300b9208) */
/* WARNING: Removing unreachable block (ram,0x300b9224) */
/* WARNING: Removing unreachable block (ram,0x300b9228) */
/* WARNING: Removing unreachable block (ram,0x300b8784) */
/* WARNING: Removing unreachable block (ram,0x300b878c) */
/* WARNING: Removing unreachable block (ram,0x300b8790) */
/* WARNING: Removing unreachable block (ram,0x300b8724) */
/* WARNING: Removing unreachable block (ram,0x300b871c) */
/* WARNING: Removing unreachable block (ram,0x300b87dc) */
/* WARNING: Removing unreachable block (ram,0x300b87e8) */
/* WARNING: Removing unreachable block (ram,0x300b8758) */
/* WARNING: Removing unreachable block (ram,0x300b8764) */
/* WARNING: Removing unreachable block (ram,0x300b87ac) */
/* WARNING: Removing unreachable block (ram,0x300b87b4) */
/* WARNING: Removing unreachable block (ram,0x300b87b0) */
/* WARNING: Removing unreachable block (ram,0x300b87b8) */
/* WARNING: Removing unreachable block (ram,0x300b87cc) */
/* WARNING: Removing unreachable block (ram,0x300b87d4) */
/* WARNING: Removing unreachable block (ram,0x300b8768) */
/* WARNING: Removing unreachable block (ram,0x300b8774) */
/* WARNING: Removing unreachable block (ram,0x300b87a4) */

uint __addsf3(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  
  if ((~(param_1 << 1) & 0xff000000) == 0 || (~(param_2 << 1) & 0xff000000) == 0) {
    uVar3 = param_1 * 2;
    if (0xff000000 < param_2 << 1 || 0xff000000 < uVar3) {
      uVar5 = param_1 * 2 + 0x800000;
      uVar7 = param_2 * 2 + 0x800000;
      uVar3 = uVar5;
      if (uVar5 < 0xff800001) {
        uVar3 = uVar7;
      }
      if (0xff800000 < uVar3) {
        puVar1 = (uint *)__rt_fp_status_addr();
        uVar3 = *puVar1;
        *puVar1 = uVar3 | 1;
        if ((uVar3 & 0x100) == 0) {
          uVar3 = __fpl_return_NaN(DAT_300b8820 | param_1 & 0x80000000,param_2,param_1 & 0x80000000,
                                   uVar7);
          return uVar3;
        }
        uVar3 = _fp_trapveneer();
        return uVar3;
      }
      if (0x7fffff < uVar5) {
        param_1 = param_2;
      }
      uVar3 = __fpl_return_NaN(param_1);
      return uVar3;
    }
    if (uVar3 == param_2 * 2) {
      if ((int)(param_1 ^ param_2) < 0) {
        uVar3 = __fpl_exception();
        return uVar3;
      }
      return param_1;
    }
    if (uVar3 != 0xff000000) {
      return param_2;
    }
    return param_1;
  }
  if ((int)(param_1 ^ param_2) < 0) {
    param_2 = param_2 ^ 0x80000000;
    if (param_1 < param_2) {
      uVar3 = param_1 - param_2 ^ 0x80000000;
      param_1 = param_1 - uVar3;
      param_2 = param_2 + uVar3;
    }
    uVar3 = param_1 >> 0x17;
    uVar5 = uVar3 - (param_2 >> 0x17);
    if ((param_2 & 0x7f800000) == 0) {
      param_2 = param_2 << 8;
      if (param_2 == 0) {
        param_2 = 0;
        if ((param_1 & 0x7fffffff) == 0) {
          param_1 = 0;
        }
        goto LAB_300b9b90;
      }
      param_1 = param_1 << 8;
      if ((uVar3 & 0xff) == 0) {
        uVar3 = uVar3 + 1;
      }
      else {
        param_1 = param_1 | 0x80000000;
        uVar5 = uVar5 - 1;
      }
    }
    else {
      param_1 = param_1 << 8 | 0x80000000;
      param_2 = param_2 << 8 | 0x80000000;
    }
    uVar7 = param_1 - (param_2 >> (uVar5 & 0xff));
    if ((int)uVar7 < 0) {
      bVar9 = (bool)((byte)(uVar7 >> 7) & 1);
      uVar3 = (uVar7 >> 8) + (uVar3 - 1) * 0x800000 + (uint)bVar9;
      if (!bVar9) {
        return uVar3;
      }
      if ((uVar7 & 0x7f) != 0) {
        return uVar3;
      }
    }
    else {
      bVar8 = (uVar3 & 0xfe) == 0;
      bVar9 = false;
      if (!bVar8) {
        param_1 = uVar7 * 2;
        bVar9 = (int)param_1 < 0;
        bVar8 = param_1 == 0;
      }
      if (!bVar9) {
        if (bVar8) {
          uVar7 = uVar7 >> 7;
          if (uVar7 != 0) {
            uVar3 = __funder_d(uVar7 >> (uVar3 & 0xff) | (uVar3 >> 8) << 0x1f,param_2,2);
            return uVar3;
          }
          return uVar7;
        }
        if (param_1 != 0) {
          param_1 = param_1 >> 2;
          uVar7 = uVar3 - LZCOUNT(param_1);
          uVar5 = 0x28U - LZCOUNT(param_1) & 0x1f;
          uVar5 = param_1 >> uVar5 | param_1 << 0x20 - uVar5;
          if ((uVar3 ^ uVar7) >> 8 != 0) {
            uVar3 = __funder_d(uVar5 >> (-uVar7 & 0xff) | (uVar3 >> 8) << 0x1f,param_2,2);
            return uVar3;
          }
          return uVar5 + uVar7 * 0x800000;
        }
        return 0;
      }
      bVar9 = (bool)((byte)(param_1 >> 7) & 1);
      uVar3 = ((int)param_1 >> 8) + uVar3 * 0x800000 + (uint)bVar9;
      if (!bVar9) {
        return uVar3;
      }
      if ((uVar7 & 0x3f) != 0) {
        return uVar3;
      }
    }
    if (param_2 << (0x20 - uVar5 & 0xff) == 0) {
      uVar3 = uVar3 & 0xfffffffe;
    }
    else {
      uVar3 = uVar3 - 1;
    }
    return uVar3;
  }
  iVar4 = param_1 - param_2;
  if (param_1 < param_2) {
    param_1 = param_1 - iVar4;
    param_2 = param_2 + iVar4;
  }
  uVar3 = param_1 >> 0x17;
  uVar5 = uVar3 - (param_2 >> 0x17);
  if ((param_2 & 0x7f800000) == 0) {
    param_2 = param_2 * 0x100;
    if (param_2 == 0) {
LAB_300b9b90:
      if ((uVar3 & 0xff) != 0) {
        return param_1;
      }
      if ((param_1 & 0x7fffffff) != 0) {
        uVar3 = __funder_d(param_1,param_2,1);
        return uVar3;
      }
      return param_1;
    }
    if ((uVar3 & 0xff) == 0) {
      uVar3 = param_1 * 0x100 + param_2 >> 8 | uVar3 << 0x17;
      if ((uVar3 & 0x800000) == 0) {
        uVar3 = __funder_d(uVar3,param_2,1);
        return uVar3;
      }
      return uVar3;
    }
    uVar5 = uVar5 - 1;
  }
  else {
    param_2 = param_2 << 8 | 0x80000000;
  }
  uVar2 = param_1 << 8 | 0x80000000;
  uVar7 = param_2 >> (uVar5 & 0xff);
  uVar6 = uVar2 + uVar7;
  if (CARRY4(uVar2,uVar7)) {
    uVar7 = (uint)CARRY4(uVar2,uVar7) << 0x1f | uVar6 >> 1;
    bVar9 = (bool)((byte)(uVar7 >> 7) & 1);
    uVar7 = uVar7 >> 8;
    uVar3 = uVar7 + uVar3 * 0x800000 + (uint)bVar9;
    if (bVar9) {
      uVar7 = uVar6 & 0xff;
    }
    uVar2 = uVar3 * 2;
    if (uVar7 != 0) {
      if (uVar7 != 0) {
        bVar9 = 0xfeffffff < uVar2;
      }
      if (!bVar9) {
        return uVar3;
      }
      goto LAB_300b9b20;
    }
  }
  else {
    bVar9 = (bool)((byte)(uVar6 >> 7) & 1);
    uVar3 = (uVar6 >> 8) + (uVar3 - 1) * 0x800000 + (uint)bVar9;
    if (!bVar9) {
      return uVar3;
    }
    uVar2 = uVar3 * 2;
    if ((uVar6 & 0x7f) != 0) {
      bVar9 = 0xfeffffff < uVar2;
    }
    if (!bVar9) {
      return uVar3;
    }
  }
  if (param_2 << (0x20 - uVar5 & 0xff) == 0) {
    uVar3 = uVar3 & 0xfffffffe;
  }
  if (uVar2 < 0xff000000) {
    return uVar3;
  }
LAB_300b9b20:
  uVar3 = __fpl_exception(uVar3 + 0xa0000000);
  return uVar3;
}

/* ----------------------------------------------------------------
 * __subsf3 @ 0x300B9C18  (примерный размер ~348 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 5
 * Вызывает: __fpl_exception, __fpl_return_NaN, __funder_d, __rt_fp_status_addr, _fp_trapveneer
 * Константы: 0x80000000, 0x00800000, 0xFF000000, 0x7F800000, 0x7FFFFFFF, 0xFFFFFFFE, 0xFEFFFFFF, 0x300B9C18
 * Данные: DAT_300b8820
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300b86f0) */
/* WARNING: Removing unreachable block (ram,0x300b8794) */
/* WARNING: Removing unreachable block (ram,0x300b87a0) */
/* WARNING: Removing unreachable block (ram,0x300b87c0) */
/* WARNING: Removing unreachable block (ram,0x300b8788) */
/* WARNING: Removing unreachable block (ram,0x300b8778) */
/* WARNING: Removing unreachable block (ram,0x300b9208) */
/* WARNING: Removing unreachable block (ram,0x300b9224) */
/* WARNING: Removing unreachable block (ram,0x300b9228) */
/* WARNING: Removing unreachable block (ram,0x300b8784) */
/* WARNING: Removing unreachable block (ram,0x300b878c) */
/* WARNING: Removing unreachable block (ram,0x300b8790) */
/* WARNING: Removing unreachable block (ram,0x300b8724) */
/* WARNING: Removing unreachable block (ram,0x300b871c) */
/* WARNING: Removing unreachable block (ram,0x300b87dc) */
/* WARNING: Removing unreachable block (ram,0x300b87e8) */
/* WARNING: Removing unreachable block (ram,0x300b8758) */
/* WARNING: Removing unreachable block (ram,0x300b8764) */
/* WARNING: Removing unreachable block (ram,0x300b87ac) */
/* WARNING: Removing unreachable block (ram,0x300b87b4) */
/* WARNING: Removing unreachable block (ram,0x300b87b0) */
/* WARNING: Removing unreachable block (ram,0x300b87b8) */
/* WARNING: Removing unreachable block (ram,0x300b87cc) */
/* WARNING: Removing unreachable block (ram,0x300b87d4) */
/* WARNING: Removing unreachable block (ram,0x300b8768) */
/* WARNING: Removing unreachable block (ram,0x300b8774) */
/* WARNING: Removing unreachable block (ram,0x300b87a4) */

uint __subsf3(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  
  if ((~(param_1 << 1) & 0xff000000) == 0 || (~(param_2 << 1) & 0xff000000) == 0) {
    uVar4 = param_1 * 2;
    if (0xff000000 < param_2 << 1 || 0xff000000 < uVar4) {
      uVar5 = param_1 * 2 + 0x800000;
      uVar7 = param_2 * 2 + 0x800000;
      uVar4 = uVar5;
      if (uVar5 < 0xff800001) {
        uVar4 = uVar7;
      }
      if (0xff800000 < uVar4) {
        puVar1 = (uint *)__rt_fp_status_addr();
        uVar4 = *puVar1;
        *puVar1 = uVar4 | 1;
        if ((uVar4 & 0x100) == 0) {
          uVar4 = __fpl_return_NaN(DAT_300b8820 | param_1 & 0x80000000,param_2,param_1 & 0x80000000,
                                   uVar7);
          return uVar4;
        }
        uVar4 = _fp_trapveneer();
        return uVar4;
      }
      if (0x7fffff < uVar5) {
        param_1 = param_2;
      }
      uVar4 = __fpl_return_NaN(param_1);
      return uVar4;
    }
    if (uVar4 == param_2 * 2) {
      if (-1 < (int)(param_1 ^ param_2)) {
        uVar4 = __fpl_exception();
        return uVar4;
      }
      return param_1;
    }
    if (uVar4 != 0xff000000) {
      return param_2 ^ 0x80000000;
    }
    return param_1;
  }
  if (-1 < (int)(param_1 ^ param_2)) {
    if (param_1 < param_2) {
      uVar4 = param_1 - param_2 ^ 0x80000000;
      param_1 = param_1 - uVar4;
      param_2 = param_2 + uVar4;
    }
    uVar4 = param_1 >> 0x17;
    uVar5 = uVar4 - (param_2 >> 0x17);
    if ((param_2 & 0x7f800000) == 0) {
      param_2 = param_2 << 8;
      if (param_2 == 0) {
        param_2 = 0;
        if ((param_1 & 0x7fffffff) == 0) {
          param_1 = 0;
        }
        goto LAB_300b9b90;
      }
      param_1 = param_1 << 8;
      if ((uVar4 & 0xff) == 0) {
        uVar4 = uVar4 + 1;
      }
      else {
        param_1 = param_1 | 0x80000000;
        uVar5 = uVar5 - 1;
      }
    }
    else {
      param_1 = param_1 << 8 | 0x80000000;
      param_2 = param_2 << 8 | 0x80000000;
    }
    uVar7 = param_1 - (param_2 >> (uVar5 & 0xff));
    if ((int)uVar7 < 0) {
      bVar8 = (bool)((byte)(uVar7 >> 7) & 1);
      uVar4 = (uVar7 >> 8) + (uVar4 - 1) * 0x800000 + (uint)bVar8;
      if (!bVar8) {
        return uVar4;
      }
      if ((uVar7 & 0x7f) != 0) {
        return uVar4;
      }
    }
    else {
      bVar9 = (uVar4 & 0xfe) == 0;
      bVar8 = false;
      if (!bVar9) {
        param_1 = uVar7 * 2;
        bVar8 = (int)param_1 < 0;
        bVar9 = param_1 == 0;
      }
      if (!bVar8) {
        if (bVar9) {
          uVar7 = uVar7 >> 7;
          if (uVar7 != 0) {
            uVar4 = __funder_d(uVar7 >> (uVar4 & 0xff) | (uVar4 >> 8) << 0x1f,param_2,2);
            return uVar4;
          }
          return uVar7;
        }
        if (param_1 != 0) {
          param_1 = param_1 >> 2;
          uVar7 = uVar4 - LZCOUNT(param_1);
          uVar5 = 0x28U - LZCOUNT(param_1) & 0x1f;
          uVar5 = param_1 >> uVar5 | param_1 << 0x20 - uVar5;
          if ((uVar4 ^ uVar7) >> 8 != 0) {
            uVar4 = __funder_d(uVar5 >> (-uVar7 & 0xff) | (uVar4 >> 8) << 0x1f,param_2,2);
            return uVar4;
          }
          return uVar5 + uVar7 * 0x800000;
        }
        return 0;
      }
      bVar8 = (bool)((byte)(param_1 >> 7) & 1);
      uVar4 = ((int)param_1 >> 8) + uVar4 * 0x800000 + (uint)bVar8;
      if (!bVar8) {
        return uVar4;
      }
      if ((uVar7 & 0x3f) != 0) {
        return uVar4;
      }
    }
    if (param_2 << (0x20 - uVar5 & 0xff) == 0) {
      uVar4 = uVar4 & 0xfffffffe;
    }
    else {
      uVar4 = uVar4 - 1;
    }
    return uVar4;
  }
  param_2 = param_2 ^ 0x80000000;
  iVar3 = param_1 - param_2;
  if (param_1 < param_2) {
    param_1 = param_1 - iVar3;
    param_2 = param_2 + iVar3;
  }
  uVar4 = param_1 >> 0x17;
  uVar5 = uVar4 - (param_2 >> 0x17);
  if ((param_2 & 0x7f800000) == 0) {
    param_2 = param_2 * 0x100;
    if (param_2 == 0) {
LAB_300b9b90:
      if ((uVar4 & 0xff) != 0) {
        return param_1;
      }
      if ((param_1 & 0x7fffffff) != 0) {
        uVar4 = __funder_d(param_1,param_2,1);
        return uVar4;
      }
      return param_1;
    }
    if ((uVar4 & 0xff) == 0) {
      uVar4 = param_1 * 0x100 + param_2 >> 8 | uVar4 << 0x17;
      if ((uVar4 & 0x800000) == 0) {
        uVar4 = __funder_d(uVar4,param_2,1);
        return uVar4;
      }
      return uVar4;
    }
    uVar5 = uVar5 - 1;
  }
  else {
    param_2 = param_2 << 8 | 0x80000000;
  }
  uVar2 = param_1 << 8 | 0x80000000;
  uVar7 = param_2 >> (uVar5 & 0xff);
  uVar6 = uVar2 + uVar7;
  if (CARRY4(uVar2,uVar7)) {
    uVar7 = (uint)CARRY4(uVar2,uVar7) << 0x1f | uVar6 >> 1;
    bVar8 = (bool)((byte)(uVar7 >> 7) & 1);
    uVar7 = uVar7 >> 8;
    uVar4 = uVar7 + uVar4 * 0x800000 + (uint)bVar8;
    if (bVar8) {
      uVar7 = uVar6 & 0xff;
    }
    uVar2 = uVar4 * 2;
    if (uVar7 != 0) {
      if (uVar7 != 0) {
        bVar8 = 0xfeffffff < uVar2;
      }
      if (!bVar8) {
        return uVar4;
      }
      goto LAB_300b9b20;
    }
  }
  else {
    bVar8 = (bool)((byte)(uVar6 >> 7) & 1);
    uVar4 = (uVar6 >> 8) + (uVar4 - 1) * 0x800000 + (uint)bVar8;
    if (!bVar8) {
      return uVar4;
    }
    uVar2 = uVar4 * 2;
    if ((uVar6 & 0x7f) != 0) {
      bVar8 = 0xfeffffff < uVar2;
    }
    if (!bVar8) {
      return uVar4;
    }
  }
  if (param_2 << (0x20 - uVar5 & 0xff) == 0) {
    uVar4 = uVar4 & 0xfffffffe;
  }
  if (uVar2 < 0xff000000) {
    return uVar4;
  }
LAB_300b9b20:
  uVar4 = __fpl_exception(uVar4 + 0xa0000000);
  return uVar4;
}

/* ----------------------------------------------------------------
 * __floatsisf @ 0x300B9D7C  (примерный размер ~12 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3010891c
 * Константы: 0x300B9D7C, 0x80000000, 0x40000000, 0x00800000, 0x0F800000, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
uint __floatsisf(uint param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = param_1 & 0x80000000;
  if (uVar2 != 0) {
    param_1 = -param_1;
  }
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 == 0) {
    return uVar1;
  }
  bVar3 = (bool)((byte)(uVar1 >> 7) & 1);
  uVar2 = (uVar2 | 0x40000000) + LZCOUNT(param_1) * -0x800000 + 0xf800000 + ((int)uVar1 >> 8) +
          (uint)bVar3;
  if ((uVar1 & 0x7f) != 0) {
    bVar3 = false;
  }
  if (bVar3) {
    uVar2 = uVar2 & 0xfffffffe;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * __fflt_normalise @ 0x300B9D88  (примерный размер ~40 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: _f_utof
 * Константы: 0x300B9D88, 0x00800000, 0x0F800000, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
uint __fflt_normalise(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 == 0) {
    return uVar1;
  }
  bVar3 = (bool)((byte)(uVar1 >> 7) & 1);
  uVar2 = param_3 + LZCOUNT(param_1) * -0x800000 + 0xf800000 + ((int)uVar1 >> 8) + (uint)bVar3;
  if ((uVar1 & 0x7f) != 0) {
    bVar3 = false;
  }
  if (bVar3) {
    uVar2 = uVar2 & 0xfffffffe;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * __floatdisf @ 0x300B9DB8  (примерный размер ~88 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300B9DB8, 0x80000000, 0x3F800000, 0x0F000000, 0x00800000, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
uint __floatdisf(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  uVar2 = param_2 & 0x80000000;
  if ((int)uVar2 < 0) {
    bVar5 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(param_2 + bVar5);
  }
  if (param_2 != 0) {
    iVar3 = 0x20;
    uVar1 = param_2;
  }
  else {
    iVar3 = 0;
    uVar1 = param_1;
  }
  if (param_2 != 0 || param_1 != 0) {
    uVar4 = iVar3 - LZCOUNT(uVar1);
    uVar1 = uVar1 << LZCOUNT(uVar1) | param_1 >> (uVar4 & 0xff);
    bVar5 = (bool)((byte)(uVar1 >> 7) & 1);
    uVar2 = (uVar2 | 0x3f800000) + 0xf000000 + uVar4 * 0x800000 + (uVar1 >> 8) + (uint)bVar5;
    if (param_1 << (0x20 - uVar4 & 0xff) != 0 || (uVar1 & 0x7f) != 0) {
      bVar5 = false;
    }
    if (bVar5) {
      uVar2 = uVar2 & 0xfffffffe;
    }
    return uVar2;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * __mulsf3 @ 0x300B9E10  (примерный размер ~292 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 6
 * Вызывает: __fpl_exception, __fpl_normalise2, __fpl_return_NaN, __funder, __rt_fp_status_addr, _fp_trapveneer
 * Константы: 0x00FF0000, 0x7FFFFFFF, 0x00800000, 0x80000000, 0x01000000, 0x00FC0000, 0xFF000001, 0x300B9E10
 * Данные: DAT_300b8820
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300b86f0) */
/* WARNING: Removing unreachable block (ram,0x300b8794) */
/* WARNING: Removing unreachable block (ram,0x300b87a0) */
/* WARNING: Removing unreachable block (ram,0x300b87c0) */
/* WARNING: Removing unreachable block (ram,0x300b8788) */
/* WARNING: Removing unreachable block (ram,0x300b8778) */
/* WARNING: Removing unreachable block (ram,0x300b9208) */
/* WARNING: Removing unreachable block (ram,0x300b9224) */
/* WARNING: Removing unreachable block (ram,0x300b9228) */
/* WARNING: Removing unreachable block (ram,0x300b8784) */
/* WARNING: Removing unreachable block (ram,0x300b878c) */
/* WARNING: Removing unreachable block (ram,0x300b8790) */
/* WARNING: Removing unreachable block (ram,0x300b8724) */
/* WARNING: Removing unreachable block (ram,0x300b871c) */
/* WARNING: Removing unreachable block (ram,0x300b87dc) */
/* WARNING: Removing unreachable block (ram,0x300b87e8) */
/* WARNING: Removing unreachable block (ram,0x300b8758) */
/* WARNING: Removing unreachable block (ram,0x300b8764) */
/* WARNING: Removing unreachable block (ram,0x300b87ac) */
/* WARNING: Removing unreachable block (ram,0x300b87b4) */
/* WARNING: Removing unreachable block (ram,0x300b87b0) */
/* WARNING: Removing unreachable block (ram,0x300b87b8) */
/* WARNING: Removing unreachable block (ram,0x300b87cc) */
/* WARNING: Removing unreachable block (ram,0x300b87d4) */
/* WARNING: Removing unreachable block (ram,0x300b8768) */
/* WARNING: Removing unreachable block (ram,0x300b8774) */
/* WARNING: Removing unreachable block (ram,0x300b87a4) */

uint __mulsf3(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  undefined1 *puVar12;
  bool bVar13;
  bool bVar14;
  
  uVar6 = param_1 >> 7 & 0xff0000;
  bVar13 = uVar6 == 0;
  if (!bVar13) {
    param_4 = param_2 >> 7 & 0xff0000;
    bVar13 = param_4 == 0;
  }
  if (!bVar13) {
    bVar13 = uVar6 == 0xff0000;
  }
  if (!bVar13) {
    bVar13 = param_4 == 0xff0000;
  }
  if (bVar13) {
    if ((int)(param_1 ^ param_2) < 0) {
      uVar6 = uVar6 | 0x100;
    }
    if (uVar6 < 0xff0000 && (param_2 >> 7 & 0xff0000) < 0xff0000) {
      if ((param_1 & 0x7fffffff) != 0 && (param_2 & 0x7fffffff) != 0) {
        uVar6 = __fpl_normalise2(param_1);
        return uVar6;
      }
      return uVar6 << 0x17;
    }
    uVar11 = param_1 * 2;
    if (uVar11 < 0xff000001) {
      uVar11 = param_2 * 2;
    }
    if (uVar11 < 0xff000001) {
      if ((param_1 & 0x7fffffff) == 0 || (param_2 & 0x7fffffff) == 0) {
        uVar6 = __fpl_exception(param_1);
        return uVar6;
      }
      return (uVar6 | 0xff) << 0x17;
    }
    uVar11 = param_1 * 2 + 0x800000;
    uVar10 = param_2 * 2 + 0x800000;
    uVar6 = uVar11;
    if (uVar11 < 0xff800001) {
      uVar6 = uVar10;
    }
    if (0xff800000 < uVar6) {
      puVar4 = (uint *)__rt_fp_status_addr();
      uVar6 = *puVar4;
      *puVar4 = uVar6 | 1;
      if ((uVar6 & 0x100) == 0) {
        uVar6 = __fpl_return_NaN(DAT_300b8820 | param_1 & 0x80000000,param_2,param_1 & 0x80000000,
                                 uVar10);
        return uVar6;
      }
      uVar6 = _fp_trapveneer();
      return uVar6;
    }
    if (0x7fffff < uVar11) {
      param_1 = param_2;
    }
    uVar6 = __fpl_return_NaN(param_1);
    return uVar6;
  }
  if ((int)(param_1 ^ param_2) < 0) {
    uVar6 = uVar6 | 0x100;
  }
  lVar3 = (ulonglong)(param_2 << 8 | 0x80000000) * (ulonglong)(param_1 << 8 | 0x80000000);
  uVar11 = (uint)((ulonglong)lVar3 >> 0x20);
  iVar7 = uVar6 + param_4 + -0x800000;
  if ((int)lVar3 != 0) {
    uVar11 = uVar11 | 1;
  }
  bVar13 = 0x7fffffff < uVar11;
  if (!bVar13) {
    uVar11 = uVar11 << 1;
  }
  iVar1 = iVar7 >> 0x10;
  uVar10 = (uint)bVar13;
  uVar8 = iVar7 + iVar1 + uVar10;
  bVar13 = (bool)((byte)(uVar11 >> 7) & 1);
  uVar6 = uVar11 >> 8;
  uVar5 = uVar6 + uVar8 * 0x800000 + (uint)bVar13;
  uVar2 = (uint)bVar13;
  puVar12 = &stack0x00000000 +
            uVar2 + (uint)bVar13 * 2 +
                    uVar6 * 2 + uVar10 * 0x1000000 + iVar1 * 0x1000000 + param_4 * 0x1000000;
  if (bVar13) {
    uVar6 = uVar11 & 0x7f;
  }
  if (uVar6 != 0) {
    bVar13 = 0xfbffff < uVar8;
  }
  if (!bVar13) {
    return uVar5;
  }
  if (uVar6 == 0 || uVar8 == 0xfc0000) {
    uVar5 = uVar5 & 0xfffffffe;
  }
  if (uVar8 < 0xfc0000) {
    return uVar5;
  }
  if (-1 < (int)(uVar8 - 0xfc0000)) {
    if (-1 < (int)((uVar5 + 0x800000) * 2)) {
      uVar6 = __fpl_exception(uVar5 + 0xa0000000);
      return uVar6;
    }
    return uVar5;
  }
  uVar6 = uVar5 * 2 - 0x1000000;
  if (0x2ffffff < uVar6) {
    bVar14 = (uVar11 & 0x7f) == 0;
    bVar13 = !bVar14;
    if (bVar13) {
      puVar12 = (undefined1 *)((uint)puVar12 >> 1 | uVar2 << 0x1f);
      bVar14 = puVar12 == (undefined1 *)0x0;
    }
    bVar13 = bVar13 && uVar2 != 0;
    if (bVar14) {
      bVar13 = -1 < (int)((uint)puVar12 >> 2 | (int)puVar12 << 0x1e);
    }
    if (bVar13) {
      uVar9 = 0x40000003;
    }
    else {
      uVar9 = 0xc0000003;
    }
    if ((uVar11 & 0xff) == 0) {
      uVar9 = 3;
    }
    uVar6 = __funder(uVar5 + 0x60000000,uVar6,uVar9);
    return uVar6;
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * __fpl_normalise2 @ 0x300B9F34  (примерный размер ~80 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: __divsf3, __mulsf3
 * Константы: 0x00FF0000, 0x300B9F34, 0x300B9F64, 0x300B9F80, 0x80000000
 * ---------------------------------------------------------------- */
void __fpl_normalise2(int param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE_00;
  
  uVar1 = param_1 << 8;
  if ((param_3 & 0xff0000) == 0) {
    param_3 = param_3 + LZCOUNT(uVar1) * -0x10000 + 0x10000;
    uVar1 = uVar1 << LZCOUNT(uVar1);
    if ((param_4 & 0xff0000) != 0) {
                    /* WARNING: Could not recover jumptable at 0x300b9f64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)();
      return;
    }
  }
  iVar2 = LZCOUNT(param_2 << 8);
                    /* WARNING: Could not recover jumptable at 0x300b9f80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)
            (uVar1 | 0x80000000,(param_2 << 8) << iVar2,param_3,param_4 + iVar2 * -0x10000 + 0x10000
            );
  return;
}

/* ----------------------------------------------------------------
 * absSymbols_Common @ 0x300B9F84  (примерный размер ~8 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300B9F84
 * ---------------------------------------------------------------- */
undefined4 absSymbols_Common(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * __assert @ 0x300B9F8C  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 8 | Вызывает: 2
 * Вызывает: abort, fdprintf
 * Вызывают: FUN_30116994, FUN_30116a34, FUN_30116c94, FUN_30116ed4, FUN_301176e0, FUN_30117bcc, tagCheckEvaluateAsserts, tagCheckModuleDel
 * Константы: 0x300B9F8C
 * Данные: DAT_300b9fa4
 * ---------------------------------------------------------------- */
void __assert(char *__assertion,char *__file,int __line)

{
  fdprintf(2,DAT_300b9fa4,__assertion);
  abort();
  return;
}

/* ----------------------------------------------------------------
 * isalnum @ 0x300B9FA8  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300B9FA8
 * Данные: DAT_300b9fc0
 * ---------------------------------------------------------------- */
int isalnum(int param_1)

{
  return *(byte *)(*DAT_300b9fc0 + (param_1 & 0xffU)) & 7;
}

/* ----------------------------------------------------------------
 * isalpha @ 0x300B9FC4  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300B9FC4
 * Данные: DAT_300b9fdc
 * ---------------------------------------------------------------- */
int isalpha(int param_1)

{
  return *(byte *)(*DAT_300b9fdc + (param_1 & 0xffU)) & 3;
}

/* ----------------------------------------------------------------
 * iscntrl @ 0x300B9FE0  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300B9FE0
 * Данные: DAT_300b9ff8
 * ---------------------------------------------------------------- */
int iscntrl(int param_1)

{
  return *(byte *)(*DAT_300b9ff8 + (param_1 & 0xffU)) & 0xa0;
}

/* ----------------------------------------------------------------
 * isdigit @ 0x300B9FFC  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300B9FFC
 * Данные: DAT_300ba014
 * ---------------------------------------------------------------- */
int isdigit(int param_1)

{
  return *(byte *)(*DAT_300ba014 + (param_1 & 0xffU)) & 4;
}

/* ----------------------------------------------------------------
 * isgraph @ 0x300BA018  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BA018
 * Данные: DAT_300ba030
 * ---------------------------------------------------------------- */
int isgraph(int param_1)

{
  return *(byte *)(*DAT_300ba030 + (param_1 & 0xffU)) & 0x17;
}

/* ----------------------------------------------------------------
 * islower @ 0x300BA034  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BA034
 * Данные: DAT_300ba04c
 * ---------------------------------------------------------------- */
int islower(int param_1)

{
  return *(byte *)(*DAT_300ba04c + (param_1 & 0xffU)) & 2;
}

/* ----------------------------------------------------------------
 * isprint @ 0x300BA050  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: exchMemShow
 * Константы: 0x300BA050
 * Данные: DAT_300ba068
 * ---------------------------------------------------------------- */
int isprint(int param_1)

{
  return *(byte *)(*DAT_300ba068 + (param_1 & 0xffU)) & 0x1f;
}

/* ----------------------------------------------------------------
 * ispunct @ 0x300BA06C  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BA06C
 * Данные: DAT_300ba084
 * ---------------------------------------------------------------- */
int ispunct(int param_1)

{
  return *(byte *)(*DAT_300ba084 + (param_1 & 0xffU)) & 0x10;
}

/* ----------------------------------------------------------------
 * isspace @ 0x300BA088  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BA088
 * Данные: DAT_300ba0a0
 * ---------------------------------------------------------------- */
int isspace(int param_1)

{
  return *(byte *)(*DAT_300ba0a0 + (param_1 & 0xffU)) & 0x28;
}

/* ----------------------------------------------------------------
 * isupper @ 0x300BA0A4  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BA0A4
 * Данные: DAT_300ba0bc
 * ---------------------------------------------------------------- */
int isupper(int param_1)

{
  return *(byte *)(*DAT_300ba0bc + (param_1 & 0xffU)) & 1;
}

/* ----------------------------------------------------------------
 * isxdigit @ 0x300BA0C0  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BA0C0
 * Данные: DAT_300ba0d8
 * ---------------------------------------------------------------- */
int isxdigit(int param_1)

{
  return *(byte *)(*DAT_300ba0d8 + (param_1 & 0xffU)) & 0x40;
}

/* ----------------------------------------------------------------
 * tolower @ 0x300BA0DC  (примерный размер ~24 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: strnicmp
 * Константы: 0x300BA0DC
 * Данные: DAT_300ba0f0
 * ---------------------------------------------------------------- */
int tolower(int __c)

{
  return (uint)*(byte *)(*DAT_300ba0f0 + (__c & 0xffU));
}

/* ----------------------------------------------------------------
 * toupper @ 0x300BA0F4  (примерный размер ~24 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BA0F4
 * Данные: DAT_300ba108
 * ---------------------------------------------------------------- */
int toupper(int __c)

{
  return (uint)*(byte *)(*DAT_300ba108 + (__c & 0xffU));
}

/* ----------------------------------------------------------------
 * fclose @ 0x300BA30C  (примерный размер ~216 байт)
 * Модуль: lib | Вызывают: 35 | Вызывает: 5
 * Вызывает: __errno, __sclose, __sflush, free, stdioFpDestroy
 * Вызывают: BSP_fclose, DR_NV_File_Close, FUN_30080798, FUN_30081f50, FUN_300827c0, FUN_3008b394, FUN_300bc118, HI6451_error_log_save, HI6451_record_startflag_save, HI6451_reset_log_save
 *           ...
 * Константы: 0x300BA30C
 * ---------------------------------------------------------------- */
int fclose(FILE *__stream)

{
  undefined4 *puVar1;
  int iVar2;
  char *__ptr;
  int iVar3;
  
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    if (*(ushort *)&__stream->_IO_write_end == 0) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = 9;
      return -1;
    }
    iVar3 = 0;
    if ((*(ushort *)&__stream->_IO_write_end & 8) != 0) {
      iVar3 = __sflush(__stream);
    }
    iVar2 = __sclose(__stream);
    if (iVar2 < 0) {
      iVar3 = -1;
    }
    if (((uint)__stream->_IO_write_end & 0x80) != 0) {
      free(__stream->_IO_buf_base);
    }
    __ptr = __stream->_IO_backup_base;
    if (__ptr != (char *)0x0) {
      if (&__stream->_fileno != (int *)__ptr) {
        free(__ptr);
      }
      __stream->_IO_backup_base = (char *)0x0;
    }
    if ((void *)__stream->_flags2 != (void *)0x0) {
      free((void *)__stream->_flags2);
      __stream->_flags2 = 0;
    }
    *(undefined2 *)&__stream->_IO_write_end = 0;
    stdioFpDestroy(__stream);
    return iVar3;
  }
  return -1;
}

/* ----------------------------------------------------------------
 * __sflush @ 0x300BA4CC  (примерный размер ~176 байт)
 * Модуль: lib | Вызывают: 8 | Вызывает: 1
 * Вызывает: __swrite
 * Вызывают: FUN_300bbb58, __srefill, fclose, fflush, freopen, fseek, setvbuf, ungetc
 * Константы: 0xFFFFFFFF, 0x300BA4CC
 * ---------------------------------------------------------------- */
undefined4 __sflush(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((*(int *)(param_1 + 4) == param_1) && (*(char *)(param_1 + 10) == 'f')) {
    if (((*(ushort *)(param_1 + 0x18) & 8) != 0) && (iVar4 = *(int *)(param_1 + 0x1c), iVar4 != 0))
    {
      iVar3 = *(int *)(param_1 + 0xc);
      *(int *)(param_1 + 0xc) = iVar4;
      iVar3 = iVar3 - iVar4;
      if ((*(ushort *)(param_1 + 0x18) & 3) == 0) {
        uVar2 = *(undefined4 *)(param_1 + 0x20);
      }
      else {
        uVar2 = 0;
      }
      *(undefined4 *)(param_1 + 0x14) = uVar2;
      for (; 0 < iVar3; iVar3 = iVar3 - iVar1) {
        iVar1 = __swrite(param_1,iVar4,iVar3);
        if (iVar1 < 1) {
          *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 0x40;
          return 0xffffffff;
        }
        iVar4 = iVar4 + iVar1;
      }
    }
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * fgets @ 0x300BA66C  (примерный размер ~284 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 3
 * Вызывает: __srefill, bcopy, memchr
 * Вызывают: cplusUserAsk
 * Константы: 0x300BA66C
 * ---------------------------------------------------------------- */
char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  int iVar2;
  void *pvVar3;
  char *__s_00;
  char *pcVar4;
  char *__n_00;
  size_t __n_01;
  char *__dest;
  
  if (((FILE *)__stream->_IO_read_ptr != __stream) ||
     (*(char *)((int)&__stream->_IO_read_end + 2) != 'f')) {
    return (char *)0x0;
  }
  if ((uint)__n < 2) {
    return (char *)0x0;
  }
  pcVar4 = (char *)(__n + -1);
  __dest = __s;
  do {
    pcVar1 = __stream->_IO_write_base;
    if (pcVar1 == (char *)0x0) {
      iVar2 = __srefill(__stream);
      if (iVar2 != 0) {
        if (__dest == __s) {
          return (char *)0x0;
        }
        break;
      }
      pcVar1 = __stream->_IO_write_base;
    }
    __s_00 = __stream->_IO_read_base;
    __n_00 = pcVar4;
    if (pcVar1 <= pcVar4) {
      __n_00 = pcVar1;
    }
    pvVar3 = memchr(__s_00,10,(size_t)__n_00);
    if (pvVar3 != (void *)0x0) {
      __n_01 = ((int)pvVar3 + 1) - (int)__s_00;
      __stream->_IO_write_base = __stream->_IO_write_base + -__n_01;
      __stream->_IO_read_base = (char *)((int)pvVar3 + 1);
      bcopy(__s_00,__dest,__n_01);
      __dest[__n_01] = '\0';
      return __s;
    }
    __stream->_IO_write_base = __stream->_IO_write_base + -(int)__n_00;
    __stream->_IO_read_base = __s_00 + (int)__n_00;
    bcopy(__s_00,__dest,(size_t)__n_00);
    __dest = __dest + (int)__n_00;
    pcVar4 = pcVar4 + -(int)__n_00;
  } while (pcVar4 != (char *)0x0);
  *__dest = '\0';
  return __s;
}

/* ----------------------------------------------------------------
 * __sflags @ 0x300BA7B4  (примерный размер ~264 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 1
 * Вызывает: __errno
 * Вызывают: fdopen, fopen, freopen
 * Константы: 0x300BA7B4
 * ---------------------------------------------------------------- */
undefined4 __sflags(char *param_1,uint *param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  bool bVar7;
  
  pcVar2 = param_1 + 1;
  cVar1 = *param_1;
  if (cVar1 == 'a') {
    uVar5 = 8;
    uVar4 = 0x208;
    uVar6 = 1;
  }
  else if (cVar1 == 'r') {
    uVar5 = 4;
    uVar4 = 0;
    uVar6 = uVar4;
  }
  else {
    if (cVar1 != 'w') {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0x16;
      return 0;
    }
    uVar5 = 8;
    uVar6 = 1;
    uVar4 = 0x600;
  }
  bVar7 = *pcVar2 == '+';
  if (!bVar7) {
    if (*pcVar2 != 'b') goto LAB_300ba838;
    bVar7 = param_1[2] == '+';
  }
  if (bVar7) {
    uVar5 = 0x10;
    uVar6 = 2;
  }
LAB_300ba838:
  *param_2 = uVar6 | uVar4;
  cVar1 = *pcVar2;
  if (((cVar1 != '+') && (cVar1 != 'b')) && (cVar1 != '\0')) {
    return 0;
  }
  if (*pcVar2 != '\0') {
    cVar1 = param_1[2];
    if (((cVar1 != '+') && (cVar1 != 'b')) && (cVar1 != '\0')) {
      return 0;
    }
    if ((param_1[2] != '\0') && (param_1[3] != '\0')) {
      return 0;
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * fopen @ 0x300BA8BC  (примерный размер ~164 байт)
 * Модуль: lib | Вызывают: 34 | Вызывает: 5
 * Вызывает: __sflags, __sseek, open, stdioFpCreate, stdioFpDestroy
 * Вызывают: BSP_fopen, DR_NV_File_Open, FUN_30080798, FUN_30081f50, FUN_300827c0, FUN_3008b498, FUN_3008b88c, HI6451_error_log_save, HI6451_record_startflag_save, HI6451_reset_log_save
 *           ...
 * Константы: 0x300BA8BC
 * Данные: DAT_300ba95c
 * ---------------------------------------------------------------- */
FILE * fopen(char *__filename,char *__modes)

{
  int iVar1;
  FILE *pFVar2;
  int iVar3;
  uint local_18;
  
  iVar1 = __sflags(__modes,&local_18);
  if (iVar1 == 0) {
    pFVar2 = (FILE *)0x0;
  }
  else {
    pFVar2 = (FILE *)stdioFpCreate();
    if (pFVar2 == (FILE *)0x0) {
      pFVar2 = (FILE *)0x0;
    }
    else {
      iVar3 = open(__filename,local_18,DAT_300ba95c);
      if (iVar3 < 0) {
        *(undefined2 *)&pFVar2->_IO_write_end = 0;
        stdioFpDestroy(pFVar2);
        pFVar2 = (FILE *)0x0;
      }
      else {
        *(short *)((int)&pFVar2->_IO_write_end + 2) = (short)iVar3;
        *(short *)&pFVar2->_IO_write_end = (short)iVar1;
        if ((local_18 & 8) != 0) {
          __sseek(pFVar2,0,2);
        }
      }
    }
  }
  return pFVar2;
}

/* ----------------------------------------------------------------
 * fputs @ 0x300BAA08  (примерный размер ~92 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: __sfvwrite, strlen
 * Константы: 0x300BAA08
 * ---------------------------------------------------------------- */
int fputs(char *__s,FILE *__stream)

{
  int iVar1;
  char *local_1c;
  size_t local_18;
  undefined1 *local_14;
  undefined4 local_10;
  size_t local_c;
  
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    local_1c = __s;
    local_18 = strlen(__s);
    local_10 = 1;
    local_14 = (undefined1 *)&local_1c;
    local_c = local_18;
    iVar1 = __sfvwrite(__stream,&local_14);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * fread @ 0x300BAA64  (примерный размер ~236 байт)
 * Модуль: lib | Вызывают: 16 | Вызывает: 3
 * Вызывает: __srefill, __udiv32, bcopy
 * Вызывают: BSP_fread, DR_NV_File_Read, FUN_3008b03c, FUN_3008b138, QC_gzgetlength, QC_gzread, TFUP_GetUnitHeadData, TFUP_ReadDataFromTF, dloadFromFsGetUnitHeadData, dloadFromFsReadDataFromFS
 *           ...
 * Константы: 0x300BAA64
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

size_t fread(void *__ptr,size_t __size,size_t __n,FILE *__stream)

{
  int iVar1;
  size_t sVar2;
  char *__n_00;
  char *pcVar3;
  char *__n_01;
  
  if ((__stream == (FILE *)0x0) || (__ptr == (void *)0x0)) {
    return 0;
  }
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    pcVar3 = (char *)(__size * __n);
    if (pcVar3 == (char *)0x0) {
      return 0;
    }
    __n_01 = pcVar3;
    if ((int)__stream->_IO_write_base < 0) {
      __stream->_IO_write_base = (char *)0x0;
    }
    do {
      __n_00 = __stream->_IO_write_base;
      if (__n_01 <= __n_00) {
        bcopy(__stream->_IO_read_base,__ptr,(size_t)__n_01);
        __stream->_IO_write_base = __stream->_IO_write_base + -(int)__n_01;
        __stream->_IO_read_base = __stream->_IO_read_base + (int)__n_01;
        return __n;
      }
      bcopy(__stream->_IO_read_base,__ptr,(size_t)__n_00);
      __ptr = (void *)((int)__ptr + (int)__n_00);
      __n_01 = __n_01 + -(int)__n_00;
      __stream->_IO_read_base = __stream->_IO_read_base + (int)__n_00;
      iVar1 = __srefill(__stream);
    } while (iVar1 == 0);
    sVar2 = __udiv32((int)pcVar3 - (int)__n_01,__size);
    return sVar2;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * __sfvwrite @ 0x300BB174  (примерный размер ~840 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 5
 * Вызывает: __swrite, __swsetup, bcopy, fflush, memchr
 * Вызывают: fputs, fwrite, puts
 * Константы: 0xFFFFFFFF, 0x300BB174
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

undefined4 __sfvwrite(FILE *param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  char *__n;
  char *__n_00;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  char *__n_01;
  int iVar6;
  char *__s;
  char *pcVar7;
  
  if (param_2[2] == 0) {
    return 0;
  }
  if (((((uint)param_1->_IO_write_end & 8) == 0) || (param_1->_IO_buf_base == (char *)0x0)) &&
     (iVar1 = __swsetup(param_1), iVar1 != 0)) {
    return 0xffffffff;
  }
  puVar3 = (undefined4 *)*param_2;
  __s = (char *)*puVar3;
  puVar4 = puVar3 + 2;
  __n_01 = (char *)puVar3[1];
  if (((uint)param_1->_IO_write_end & 2) == 0) {
    if (((uint)param_1->_IO_write_end & 1) == 0) {
      do {
        while (__n_01 == (char *)0x0) {
          puVar3 = puVar4 + 1;
          __s = (char *)*puVar4;
          puVar4 = puVar4 + 2;
          __n_01 = (char *)*puVar3;
        }
        pcVar7 = param_1->_IO_write_ptr;
        if (((uint)param_1->_IO_write_end & 0x200) == 0) {
          pcVar5 = param_1->_IO_read_base;
          if ((param_1->_IO_buf_base < pcVar5) && (pcVar7 < __n_01)) {
            bcopy(__s,pcVar5,(size_t)pcVar7);
            param_1->_IO_read_base = param_1->_IO_read_base + (int)pcVar7;
            iVar1 = fflush(param_1);
            if (iVar1 != 0) goto LAB_300bb49c;
          }
          else if (__n_01 < param_1->_IO_buf_end) {
            bcopy(__s,pcVar5,(size_t)__n_01);
            param_1->_IO_write_ptr = param_1->_IO_write_ptr + -(int)__n_01;
            param_1->_IO_read_base = param_1->_IO_read_base + (int)__n_01;
            pcVar7 = __n_01;
          }
          else {
            pcVar7 = (char *)__swrite(param_1,__s,param_1->_IO_buf_end);
            if ((int)pcVar7 < 1) goto LAB_300bb49c;
          }
        }
        else {
          if (__n_01 < pcVar7) {
            pcVar7 = __n_01;
          }
          bcopy(__s,param_1->_IO_read_base,(size_t)pcVar7);
          param_1->_IO_write_ptr = param_1->_IO_write_ptr + -(int)pcVar7;
          param_1->_IO_read_base = param_1->_IO_read_base + (int)pcVar7;
          pcVar7 = __n_01;
        }
        __s = __s + (int)pcVar7;
        iVar1 = param_2[2];
        __n_01 = __n_01 + -(int)pcVar7;
        param_2[2] = iVar1 - (int)pcVar7;
      } while (iVar1 - (int)pcVar7 != 0);
    }
    else {
      pcVar5 = (char *)0x0;
      pcVar7 = pcVar5;
      do {
        while (__n_01 == (char *)0x0) {
          puVar3 = puVar4 + 1;
          __s = (char *)*puVar4;
          pcVar5 = (char *)0x0;
          puVar4 = puVar4 + 2;
          __n_01 = (char *)*puVar3;
        }
        if (pcVar5 == (char *)0x0) {
          pvVar2 = memchr(__s,10,(size_t)__n_01);
          pcVar7 = __n_01;
          if (pvVar2 != (void *)0x0) {
            pcVar7 = (char *)((int)pvVar2 - (int)__s);
          }
          pcVar7 = pcVar7 + 1;
          pcVar5 = (char *)0x1;
        }
        __n = pcVar7;
        if (__n_01 < pcVar7) {
          __n = __n_01;
        }
        __n_00 = param_1->_IO_write_ptr + (int)param_1->_IO_buf_end;
        if ((param_1->_IO_buf_base < param_1->_IO_read_base) && ((int)__n_00 < (int)__n)) {
          bcopy(__s,param_1->_IO_read_base,(size_t)__n_00);
          param_1->_IO_read_base = param_1->_IO_read_base + (int)__n_00;
          iVar1 = fflush(param_1);
          __n = __n_00;
          if (iVar1 != 0) goto LAB_300bb49c;
        }
        else if ((int)__n < (int)param_1->_IO_buf_end) {
          bcopy(__s,param_1->_IO_read_base,(size_t)__n);
          param_1->_IO_write_ptr = param_1->_IO_write_ptr + -(int)__n;
          param_1->_IO_read_base = param_1->_IO_read_base + (int)__n;
        }
        else {
          __n = (char *)__swrite(param_1,__s);
          if ((int)__n < 1) goto LAB_300bb49c;
        }
        pcVar7 = pcVar7 + -(int)__n;
        if (pcVar7 == (char *)0x0) {
          iVar1 = fflush(param_1);
          if (iVar1 != 0) goto LAB_300bb49c;
          pcVar5 = (char *)0x0;
        }
        __s = __s + (int)__n;
        iVar1 = param_2[2];
        __n_01 = __n_01 + -(int)__n;
        param_2[2] = iVar1 - (int)__n;
      } while (iVar1 - (int)__n != 0);
    }
  }
  else {
    do {
      while (__n_01 == (char *)0x0) {
        puVar3 = puVar4 + 1;
        __s = (char *)*puVar4;
        puVar4 = puVar4 + 2;
        __n_01 = (char *)*puVar3;
      }
      pcVar7 = (char *)0x400;
      if (__n_01 < (char *)0x400) {
        pcVar7 = __n_01;
      }
      iVar1 = __swrite(param_1,__s,pcVar7);
      if (iVar1 < 1) {
LAB_300bb49c:
        *(ushort *)&param_1->_IO_write_end = *(ushort *)&param_1->_IO_write_end | 0x40;
        return 0xffffffff;
      }
      __s = __s + iVar1;
      iVar6 = param_2[2];
      __n_01 = __n_01 + -iVar1;
      param_2[2] = iVar6 - iVar1;
    } while (iVar6 - iVar1 != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * fwrite @ 0x300BB4BC  (примерный размер ~132 байт)
 * Модуль: lib | Вызывают: 19 | Вызывает: 2
 * Вызывает: __sfvwrite, __udiv32
 * Вызывают: BSP_fwrite, DR_NV_File_Write, FUN_30080798, FUN_30081f50, FUN_300827c0, FUN_3008c560, QC_gzsetparams, QC_gzwrite, dloadFromFsMainThread, dloadTFPro
 *           ...
 * Константы: 0x300BB4BC
 * ---------------------------------------------------------------- */
size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
  int iVar1;
  int iVar2;
  void *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  int local_14;
  
  local_1c = (undefined1 *)&local_24;
  if (((FILE *)__s->_IO_read_ptr == __s) && (*(char *)((int)&__s->_IO_read_end + 2) == 'f')) {
    iVar2 = __size * __n;
    local_18 = 1;
    local_24 = __ptr;
    local_20 = iVar2;
    local_14 = iVar2;
    iVar1 = __sfvwrite(__s,&local_1c);
    if (iVar1 != 0) {
      __n = __udiv32(iVar2 - local_14,__size);
    }
  }
  else {
    __n = 0;
  }
  return __n;
}

/* ----------------------------------------------------------------
 * gets @ 0x300BB64C  (примерный размер ~204 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: __srget, __stdin
 * Константы: 0x300BB64C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
char * gets(char *__s)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  byte *pbVar6;
  
  pcVar4 = __s;
  while( true ) {
    piVar1 = (int *)__stdin();
    iVar5 = *(int *)(*piVar1 + 4);
    piVar1 = (int *)__stdin();
    if (*piVar1 != iVar5) break;
    piVar1 = (int *)__stdin();
    if (*(char *)(*piVar1 + 10) != 'f') break;
    piVar1 = (int *)__stdin();
    iVar5 = *(int *)(*piVar1 + 0x10) + -1;
    *(int *)(*piVar1 + 0x10) = iVar5;
    if (iVar5 < 0) {
      puVar2 = (undefined4 *)__stdin();
      uVar3 = __srget(*puVar2);
    }
    else {
      piVar1 = (int *)__stdin();
      pbVar6 = *(byte **)(*piVar1 + 0xc);
      *(byte **)(*piVar1 + 0xc) = pbVar6 + 1;
      uVar3 = (uint)*pbVar6;
    }
    if (uVar3 == 10) goto LAB_300bb708;
    if (uVar3 == 0xffffffff) break;
    *pcVar4 = (char)uVar3;
    pcVar4 = pcVar4 + 1;
  }
  if (pcVar4 == __s) {
    return (char *)0x0;
  }
LAB_300bb708:
  *pcVar4 = '\0';
  return __s;
}

/* ----------------------------------------------------------------
 * __smakebuf @ 0x300BB74C  (примерный размер ~296 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 3
 * Вызывает: ioctl, isatty, malloc
 * Вызывают: __srefill, __swsetup, fseek
 * Константы: 0x300BB74C
 * ---------------------------------------------------------------- */
void __smakebuf(int param_1)

{
  void *pvVar1;
  int iVar2;
  size_t __size;
  bool bVar3;
  undefined1 auStack_58 [8];
  uint local_50;
  size_t local_2c;
  
  if ((*(ushort *)(param_1 + 0x18) & 2) != 0) {
    *(int *)(param_1 + 0x1c) = param_1 + 0x3b;
    *(int *)(param_1 + 0xc) = param_1 + 0x3b;
    *(undefined4 *)(param_1 + 0x20) = 1;
    return;
  }
  if (*(short *)(param_1 + 0x1a) < 0) {
    bVar3 = false;
    __size = 0x400;
  }
  else {
    iVar2 = ioctl((int)*(short *)(param_1 + 0x1a),0x40,auStack_58);
    if (iVar2 < 0) {
      bVar3 = true;
      __size = 0x400;
    }
    else {
      bVar3 = (local_50 & 0xf000) == 0x2000;
      __size = local_2c;
      if ((int)local_2c < 1) {
        __size = 0x400;
      }
      if ((local_50 & 0xf000) == 0x8000) {
        *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 0x400;
        *(size_t *)(param_1 + 0x44) = local_2c;
        goto LAB_300bb800;
      }
    }
  }
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 0x800;
LAB_300bb800:
  pvVar1 = malloc(__size);
  if (pvVar1 == (void *)0x0) {
    *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 2;
    *(int *)(param_1 + 0xc) = param_1 + 0x3b;
    *(int *)(param_1 + 0x1c) = param_1 + 0x3b;
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  else {
    *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 0x80;
    *(void **)(param_1 + 0xc) = pvVar1;
    *(void **)(param_1 + 0x1c) = pvVar1;
    *(size_t *)(param_1 + 0x20) = __size;
    if ((bVar3) && (iVar2 = isatty((int)*(short *)(param_1 + 0x1a)), iVar2 != 0)) {
      *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 1;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * putchar @ 0x300BB97C  (примерный размер ~312 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: __stdout, __swbuf
 * Константы: 0x300BB97C
 * ---------------------------------------------------------------- */
int putchar(int __c)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *pbVar4;
  
  piVar1 = (int *)__stdout();
  iVar3 = *(int *)(*piVar1 + 4);
  piVar1 = (int *)__stdout();
  if ((*piVar1 != iVar3) || (piVar1 = (int *)__stdout(), *(char *)(*piVar1 + 10) != 'f')) {
    return -1;
  }
  piVar1 = (int *)__stdout();
  iVar3 = *(int *)(*piVar1 + 0x14) + -1;
  *(int *)(*piVar1 + 0x14) = iVar3;
  if (-1 < iVar3) {
    piVar1 = (int *)__stdout();
    **(undefined1 **)(*piVar1 + 0xc) = (char)__c;
    piVar1 = (int *)__stdout();
    pbVar4 = *(byte **)(*piVar1 + 0xc);
    *(byte **)(*piVar1 + 0xc) = pbVar4 + 1;
    return (uint)*pbVar4;
  }
  piVar1 = (int *)__stdout();
  iVar3 = *(int *)(*piVar1 + 0x14);
  piVar1 = (int *)__stdout();
  if (*(int *)(*piVar1 + 0x24) <= iVar3) {
    piVar1 = (int *)__stdout();
    **(undefined1 **)(*piVar1 + 0xc) = (char)__c;
    piVar1 = (int *)__stdout();
    if (**(char **)(*piVar1 + 0xc) != '\n') {
      piVar1 = (int *)__stdout();
      pbVar4 = *(byte **)(*piVar1 + 0xc);
      *(byte **)(*piVar1 + 0xc) = pbVar4 + 1;
      return (uint)*pbVar4;
    }
    puVar2 = (undefined4 *)__stdout();
    iVar3 = __swbuf(10,*puVar2);
    return iVar3;
  }
  puVar2 = (undefined4 *)__stdout();
  iVar3 = __swbuf(__c,*puVar2);
  return iVar3;
}

/* ----------------------------------------------------------------
 * puts @ 0x300BBAF0  (примерный размер ~104 байт)
 * Модуль: lib | Вызывают: 67 | Вызывает: 3
 * Вызывает: __sfvwrite, __stdout, strlen
 * Вызывают: FUN_300cc684, FUN_300cc974, FUN_300ccc2c, FUN_300cd160, FUN_300cd2a8, FUN_300cd79c, FUN_300cdb24, FUN_300ce044, FUN_300cf1d0, FUN_300d266c
 *           ...
 * Константы: 0x300BBAF0
 * Данные: DAT_300bbb54
 * ---------------------------------------------------------------- */
int puts(char *__s)

{
  undefined4 *puVar1;
  int iVar2;
  char **local_24;
  undefined4 local_20;
  int local_1c;
  char *local_18;
  size_t local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = strlen(__s);
  local_10 = DAT_300bbb54;
  local_c = 1;
  local_1c = local_14 + 1;
  local_24 = &local_18;
  local_20 = 2;
  local_18 = __s;
  puVar1 = (undefined4 *)__stdout();
  iVar2 = __sfvwrite(*puVar1,&local_24);
  if (iVar2 == 0) {
    iVar2 = 10;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300bbb58 @ 0x300BBB58  (примерный размер ~36 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: __sflush
 * Вызывают: __srefill
 * Константы: 0x300BBB58
 * ---------------------------------------------------------------- */
undefined4 FUN_300bbb58(int param_1)

{
  undefined4 uVar1;
  
  if ((*(ushort *)(param_1 + 0x18) & 9) == 9) {
    uVar1 = __sflush();
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * __srefill @ 0x300BBB7C  (примерный размер ~336 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 6
 * Вызывает: FUN_300bbb58, __errno, __sflush, __smakebuf, __sread, free
 * Вызывают: __srget, fgets, fread, fseek
 * Константы: 0xFFFFFFFF, 0x300BBB7C
 * ---------------------------------------------------------------- */
undefined4 __srefill(int param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  ushort uVar4;
  void *__ptr;
  bool bVar5;
  
  *(undefined4 *)(param_1 + 0x10) = 0;
  uVar4 = *(ushort *)(param_1 + 0x18);
  if ((uVar4 & 0x20) != 0) {
    return 0xffffffff;
  }
  if ((uVar4 & 4) == 0) {
    if ((uVar4 & 0x10) == 0) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 9;
      return 0xffffffff;
    }
    if ((uVar4 & 8) != 0) {
      iVar3 = __sflush();
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xfff7;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 4;
  }
  else {
    __ptr = *(void **)(param_1 + 0x28);
    if (__ptr != (void *)0x0) {
      if ((void *)(param_1 + 0x38) != __ptr) {
        free(__ptr);
      }
      *(undefined4 *)(param_1 + 0x28) = 0;
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x34);
      if (*(int *)(param_1 + 0x34) != 0) {
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x30);
        return 0;
      }
    }
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    __smakebuf(param_1);
  }
  if ((*(ushort *)(param_1 + 0x18) & 3) != 0) {
    FUN_300bbb58(param_1);
  }
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x1c);
  iVar3 = __sread(param_1,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20));
  *(int *)(param_1 + 0x10) = iVar3;
  uVar4 = *(ushort *)(param_1 + 0x18) & 0xdfff;
  *(ushort *)(param_1 + 0x18) = uVar4;
  if (0 < iVar3) {
    return 0;
  }
  bVar5 = iVar3 == 0;
  if (bVar5) {
    iVar3 = 0x20;
  }
  uVar1 = (ushort)iVar3;
  if (!bVar5) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    uVar1 = 0x40;
  }
  *(ushort *)(param_1 + 0x18) = uVar4 | uVar1;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * __srget @ 0x300BBD20  (примерный размер ~64 байт)
 * Модуль: lib | Вызывают: 5 | Вызывает: 1
 * Вызывает: __srefill
 * Вызывают: BSP_MEM_Scan, fgetc, getc, getchar, gets
 * Константы: 0x300BBD20, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
uint __srget(int param_1)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = __srefill();
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    pbVar2 = *(byte **)(param_1 + 0xc);
    *(byte **)(param_1 + 0xc) = pbVar2 + 1;
    return (uint)*pbVar2;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * __sread @ 0x300BBF1C  (примерный размер ~64 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: read
 * Вызывают: __srefill
 * Константы: 0x300BBF1C
 * ---------------------------------------------------------------- */
ssize_t __sread(int param_1,void *param_2,size_t param_3)

{
  ssize_t sVar1;
  
  sVar1 = read((int)*(short *)(param_1 + 0x1a),param_2,param_3);
  if (sVar1 < 0) {
    *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xefff;
  }
  else {
    *(ssize_t *)(param_1 + 0x48) = sVar1 + *(int *)(param_1 + 0x48);
  }
  return sVar1;
}

/* ----------------------------------------------------------------
 * __swrite @ 0x300BBF5C  (примерный размер ~76 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 2
 * Вызывает: lseek, write
 * Вызывают: __sflush, __sfvwrite
 * Константы: 0x300BBF5C
 * ---------------------------------------------------------------- */
void __swrite(int param_1,void *param_2,size_t param_3)

{
  if ((*(ushort *)(param_1 + 0x18) & 0x100) != 0) {
    lseek((int)*(short *)(param_1 + 0x1a),0,2);
  }
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xefff;
  write((int)*(short *)(param_1 + 0x1a),param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * __sseek @ 0x300BBFA8  (примерный размер ~60 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 1
 * Вызывает: lseek
 * Вызывают: fopen, fseek, ftell
 * Константы: 0x300BBFA8
 * ---------------------------------------------------------------- */
__off_t __sseek(int param_1,__off_t param_2,int param_3)

{
  __off_t _Var1;
  
  _Var1 = lseek((int)*(short *)(param_1 + 0x1a),param_2,param_3);
  if (_Var1 == -1) {
    *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xefff;
  }
  else {
    *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 0x1000;
    *(__off_t *)(param_1 + 0x48) = _Var1;
  }
  return _Var1;
}

/* ----------------------------------------------------------------
 * __sclose @ 0x300BBFE4  (примерный размер ~56 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 1
 * Вызывает: close
 * Вызывают: fclose, freopen
 * Константы: 0x300BBFE4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 __sclose(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (int)*(short *)(param_1 + 0x1a);
  if ((iVar1 < 0) || (uVar2 = 0, 2 < iVar1)) {
    uVar2 = 0;
    iVar1 = close(iVar1);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * __stdin @ 0x300BC144  (примерный размер ~48 байт)
 * Модуль: lib | Вызывают: 7 | Вызывает: 1
 * Вызывает: FUN_300bc1cc
 * Вызывают: BSP_MEM_Scan, FUN_300bc1cc, cplusUserAsk, getchar, gets, scanf, shellInterpClex
 * Константы: 0x300BC144
 * Данные: DAT_300bc2e8
 * ---------------------------------------------------------------- */
int __stdin(void)

{
  if (*(int *)(*DAT_300bc2e8 + 0xf4) == 0) {
    FUN_300bc1cc(0);
  }
  return *DAT_300bc2e8 + 0xf4;
}

/* ----------------------------------------------------------------
 * __stdout @ 0x300BC174  (примерный размер ~44 байт)
 * Модуль: lib | Вызывают: 11 | Вызывает: 1
 * Вызывает: FUN_300bc1cc
 * Вызывают: FUN_300bc1cc, FUN_300f72a4, FUN_300f8b2c, FUN_3010c4f0, completionPathShow, completionSymShow, putchar, puts, shellCompletionPathnameGet, shellInterpClex
 *           ...
 * Константы: 0x300BC174
 * Данные: DAT_300bc2e8
 * ---------------------------------------------------------------- */
int __stdout(void)

{
  int *piVar1;
  
  piVar1 = DAT_300bc2e8;
  if (*(int *)(*DAT_300bc2e8 + 0xf8) == 0) {
    FUN_300bc1cc(1);
  }
  return *piVar1 + 0xf8;
}

/* ----------------------------------------------------------------
 * __stderr @ 0x300BC1A0  (примерный размер ~44 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 1
 * Вызывает: FUN_300bc1cc
 * Вызывают: FUN_300bc1cc, FUN_30106540, perror
 * Константы: 0x300BC1A0
 * Данные: DAT_300bc2e8
 * ---------------------------------------------------------------- */
int __stderr(void)

{
  int *piVar1;
  
  piVar1 = DAT_300bc2e8;
  if (*(int *)(*DAT_300bc2e8 + 0xfc) == 0) {
    FUN_300bc1cc(2);
  }
  return *piVar1 + 0xfc;
}

/* ----------------------------------------------------------------
 * FUN_300bc1cc @ 0x300BC1CC  (примерный размер ~220 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 6
 * Вызывает: __stderr, __stdin, __stdout, stdioFpCreate, taskCreateHookInit, taskDeleteHookAdd
 * Вызывают: __stderr, __stdin, __stdout, stdioFp
 * Константы: 0x300BC1CC, 0xFFFFFFFF
 * Данные: DAT_300bc2dc, DAT_300bc2e8, DAT_300bc2ec, DAT_300bc2f0
 * ---------------------------------------------------------------- */
undefined4 FUN_300bc1cc(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = stdioFpCreate();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  iVar3 = iVar2;
  if (param_1 == 0) {
    iVar3 = 4;
  }
  uVar1 = (undefined2)iVar3;
  if (param_1 != 0) {
    if (param_1 == 1) {
      uVar1 = 8;
    }
    else {
      if (param_1 != 2) goto LAB_300bc218;
      uVar1 = 10;
    }
  }
  *(undefined2 *)(iVar2 + 0x18) = uVar1;
LAB_300bc218:
  *(short *)(iVar2 + 0x1a) = (short)param_1;
  *(int *)(*DAT_300bc2e8 + param_1 * 4 + 0xf4) = iVar2;
  iVar3 = DAT_300bc2dc;
  if ((*(int *)(DAT_300bc2dc + 4) == 0) &&
     (((piVar4 = (int *)__stdout(), *piVar4 == iVar2 ||
       (piVar4 = (int *)__stdin(), *piVar4 == iVar2)) ||
      (piVar4 = (int *)__stderr(), *piVar4 == iVar2)))) {
    if (*DAT_300bc2ec == 0) {
      taskCreateHookInit();
    }
    taskDeleteHookAdd(DAT_300bc2f0);
    *(undefined4 *)(iVar3 + 4) = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * __swbuf @ 0x300BC5C4  (примерный размер ~220 байт)
 * Модуль: lib | Вызывают: 6 | Вызывает: 2
 * Вызывает: __swsetup, fflush
 * Вызывают: FUN_300bc8ec, FUN_300f72a4, FUN_300f8b2c, fputc, putc, putchar
 * Константы: 0xFFFFFFFF, 0x300BC5C4
 * ---------------------------------------------------------------- */
uint __swbuf(byte param_1,FILE *param_2)

{
  int iVar1;
  byte *pbVar2;
  
  param_2->_IO_write_ptr = param_2->_IO_save_base;
  if (((((uint)param_2->_IO_write_end & 8) == 0) || (param_2->_IO_buf_base == (char *)0x0)) &&
     (iVar1 = __swsetup(param_2), iVar1 != 0)) {
    return 0xffffffff;
  }
  iVar1 = (int)param_2->_IO_read_base - (int)param_2->_IO_buf_base;
  if ((int)param_2->_IO_buf_end <= iVar1) {
    iVar1 = fflush(param_2);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    iVar1 = 0;
  }
  param_2->_IO_write_ptr = param_2->_IO_write_ptr + -1;
  pbVar2 = (byte *)param_2->_IO_read_base;
  *pbVar2 = param_1;
  param_2->_IO_read_base = (char *)(pbVar2 + 1);
  if (((param_2->_IO_buf_end == (char *)(iVar1 + 1)) ||
      ((((uint)param_2->_IO_write_end & 1) != 0 && (param_1 == 10)))) &&
     (iVar1 = fflush(param_2), iVar1 != 0)) {
    return 0xffffffff;
  }
  return (uint)param_1;
}

/* ----------------------------------------------------------------
 * __swsetup @ 0x300BC6A0  (примерный размер ~200 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 2
 * Вызывает: __smakebuf, free
 * Вызывают: __sfvwrite, __swbuf, vfprintf
 * Константы: 0x300BC6A0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 __swsetup(int param_1)

{
  ushort uVar1;
  void *__ptr;
  undefined4 uVar2;
  
  uVar1 = *(ushort *)(param_1 + 0x18);
  if ((uVar1 & 8) == 0) {
    if ((uVar1 & 0x10) == 0) {
      return 0xffffffff;
    }
    if ((uVar1 & 4) != 0) {
      __ptr = *(void **)(param_1 + 0x28);
      if (__ptr != (void *)0x0) {
        if ((void *)(param_1 + 0x38) != __ptr) {
          free(__ptr);
        }
        *(undefined4 *)(param_1 + 0x28) = 0;
      }
      *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xffdb;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x1c);
    }
    *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 8;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    __smakebuf(param_1);
  }
  if ((*(ushort *)(param_1 + 0x18) & 1) == 0) {
    if ((*(ushort *)(param_1 + 0x18) & 2) == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x20);
    }
    else {
      uVar2 = 0;
    }
    *(undefined4 *)(param_1 + 0x14) = uVar2;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(int *)(param_1 + 0x24) = -*(int *)(param_1 + 0x20);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * fprintf @ 0x300BC9B0  (примерный размер ~64 байт)
 * Модуль: lib | Вызывают: 5 | Вызывает: 1
 * Вызывает: vfprintf
 * Вызывают: FUN_3008b498, FUN_3008b88c, FUN_30106540, HI6451_record_startflag_save, perror
 * Константы: 0x300BC9B0
 * ---------------------------------------------------------------- */
int fprintf(FILE *__stream,char *__format,...)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    uStack_8 = in_r2;
    uStack_4 = in_r3;
    iVar1 = vfprintf(__stream,__format,&uStack_8);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * abs @ 0x300BCAEC  (примерный размер ~20 байт)
 * Модуль: lib | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_30019514, FUN_300bf21c, FUN_3011423c, lstNStep, shellInternalSymTblFromRtpGet
 * Константы: 0x300BCAEC
 * ---------------------------------------------------------------- */
int abs(int __x)

{
  if (__x < 1) {
    __x = -__x;
  }
  return __x;
}

/* ----------------------------------------------------------------
 * atof @ 0x300BCB08  (примерный размер ~16 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: strtod
 * Константы: 0x300BCB08
 * ---------------------------------------------------------------- */
double atof(char *__nptr)

{
  double dVar1;
  
  dVar1 = strtod(__nptr,(char **)0x0);
  return dVar1;
}

/* ----------------------------------------------------------------
 * atoi @ 0x300BCB18  (примерный размер ~12 байт)
 * Модуль: lib | Вызывают: 6 | Вызывает: 1
 * Вызывает: strtol
 * Вызывают: ABB_ReadCfg, FUN_3000ed18, __getDstInfo, cplusUserAsk, localtime_r, mktime
 * Константы: 0x300BCB18
 * ---------------------------------------------------------------- */
int atoi(char *__nptr)

{
  long lVar1;
  
  lVar1 = strtol(__nptr,(char **)0x0,10);
  return lVar1;
}

/* ----------------------------------------------------------------
 * atol @ 0x300BCB24  (примерный размер ~12 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: strtol
 * Константы: 0x300BCB24
 * ---------------------------------------------------------------- */
long atol(char *__nptr)

{
  long lVar1;
  
  lVar1 = strtol(__nptr,(char **)0x0,10);
  return lVar1;
}

/* ----------------------------------------------------------------
 * bsearch @ 0x300BCB30  (примерный размер ~112 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BCB30
 * ---------------------------------------------------------------- */
void * bsearch(void *__key,void *__base,size_t __nmemb,size_t __size,__compar_fn_t __compar)

{
  int iVar1;
  void *pvVar2;
  
  if (__nmemb != 0) {
    do {
      pvVar2 = (void *)(__size * ((int)__nmemb >> 1) + (int)__base);
      iVar1 = (*__compar)(__key,pvVar2);
      if (iVar1 == 0) {
        return pvVar2;
      }
      if (0 < iVar1) {
        __base = (void *)((int)pvVar2 + __size);
        __nmemb = __nmemb - 1;
      }
      __nmemb = (int)__nmemb >> 1;
    } while (__nmemb != 0);
  }
  return (void *)0x0;
}

/* ----------------------------------------------------------------
 * div_r @ 0x300BCBA0  (примерный размер ~72 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: __div32
 * Вызывают: div
 * Константы: 0x300BCBA0
 * ---------------------------------------------------------------- */
void div_r(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __div32();
  *param_3 = iVar1;
  iVar2 = param_1 - iVar1 * param_2;
  param_3[1] = iVar2;
  if (-1 < param_1) {
    return;
  }
  if (iVar2 < 1) {
    return;
  }
  *param_3 = iVar1 + 1;
  param_3[1] = iVar2 - param_2;
  return;
}

/* ----------------------------------------------------------------
 * div @ 0x300BCBE8  (примерный размер ~52 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: div_r
 * Константы: 0x300BCBE8
 * Данные: DAT_300bcc18
 * ---------------------------------------------------------------- */
div_t div(int __numer,int __denom)

{
  undefined4 *puVar1;
  div_t dVar2;
  
  puVar1 = DAT_300bcc18;
  dVar2 = (div_t)div_r(__denom);
  *(undefined4 *)__numer = *puVar1;
  *(undefined4 *)(__numer + 4) = puVar1[1];
  return dVar2;
}

/* ----------------------------------------------------------------
 * labs @ 0x300BCC1C  (примерный размер ~20 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BCC1C
 * ---------------------------------------------------------------- */
long labs(long __x)

{
  if (__x < 1) {
    __x = -__x;
  }
  return __x;
}

/* ----------------------------------------------------------------
 * ldiv_r @ 0x300BCC30  (примерный размер ~72 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 1
 * Вызывает: __div32
 * Вызывают: __getTime, ldiv
 * Константы: 0x300BCC30
 * ---------------------------------------------------------------- */
void ldiv_r(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __div32();
  *param_3 = iVar1;
  iVar2 = param_1 - iVar1 * param_2;
  param_3[1] = iVar2;
  if (-1 < param_1) {
    return;
  }
  if (iVar2 < 1) {
    return;
  }
  *param_3 = iVar1 + 1;
  param_3[1] = iVar2 - param_2;
  return;
}

/* ----------------------------------------------------------------
 * ldiv @ 0x300BCC78  (примерный размер ~52 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: ldiv_r
 * Константы: 0x300BCC78
 * Данные: DAT_300bcca8
 * ---------------------------------------------------------------- */
ldiv_t ldiv(long __numer,long __denom)

{
  undefined4 *puVar1;
  ldiv_t lVar2;
  
  puVar1 = DAT_300bcca8;
  lVar2 = (ldiv_t)ldiv_r(__denom);
  *(undefined4 *)__numer = *puVar1;
  *(undefined4 *)(__numer + 4) = puVar1[1];
  return lVar2;
}

/* ----------------------------------------------------------------
 * qsort @ 0x300BD268  (примерный размер ~36 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300bcdbc, FUN_300bce74
 * Константы: 0x300BD268
 * ---------------------------------------------------------------- */
void qsort(void *__base,size_t __nmemb,size_t __size,__compar_fn_t __compar)

{
  if (1 < __nmemb) {
    if (__nmemb < 4) {
      FUN_300bcdbc();
    }
    else {
      FUN_300bce74();
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * rand @ 0x300BD28C  (примерный размер ~40 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BD28C
 * Данные: DAT_300bd2c4, DAT_300bd2c8, DAT_300bd2cc, DAT_300bd2d0
 * ---------------------------------------------------------------- */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int rand(void)

{
  uint uVar1;
  
  uVar1 = *DAT_300bd2c4 * DAT_300bd2cc + DAT_300bd2c8;
  *DAT_300bd2c4 = uVar1;
  return DAT_300bd2d0 & uVar1 >> 0x10;
}

/* ----------------------------------------------------------------
 * srand @ 0x300BD2B4  (примерный размер ~32 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BD2B4
 * Данные: DAT_300bd2c4
 * ---------------------------------------------------------------- */
void srand(uint __seed)

{
  *DAT_300bd2c4 = __seed;
  return;
}

/* ----------------------------------------------------------------
 * strtol @ 0x300BD2D4  (примерный размер ~428 байт)
 * Модуль: lib | Вызывают: 6 | Вызывает: 2
 * Вызывает: __errno, __udiv32
 * Вызывают: FUN_300f7ac8, FUN_300f81ac, FUN_30116e08, FUN_301173b0, atoi, atol
 * Константы: 0x300BD2D4, 0x7FFFFFFF
 * Данные: DAT_300bd47c
 * ---------------------------------------------------------------- */
long strtol(char *__nptr,char **__endptr,int __base)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar9;
  
  iVar6 = *DAT_300bd47c;
  bVar2 = false;
  pbVar8 = (byte *)__nptr;
  do {
    pbVar9 = pbVar8;
    pbVar8 = pbVar9 + 1;
    uVar11 = (uint)*pbVar9;
  } while ((*(byte *)(iVar6 + uVar11) & 0x28) != 0);
  if (uVar11 == 0x2d) {
    bVar2 = true;
  }
  else if (uVar11 != 0x2b) goto LAB_300bd328;
  uVar11 = (uint)*pbVar8;
  pbVar8 = pbVar9 + 2;
LAB_300bd328:
  if ((((__base == 0) || (__base == 0x10)) && (uVar11 == 0x30)) &&
     (*pbVar8 == 0x78 || *pbVar8 == 0x58)) {
    uVar11 = (uint)pbVar8[1];
    pbVar8 = pbVar8 + 2;
    __base = 0x10;
  }
  if (__base == 0) {
    __base = (uint)(uVar11 != 0x30) * 2 + 8;
  }
  uVar3 = bVar2 + 0x7fffffff;
  uVar4 = __udiv32(uVar3,__base);
  uVar10 = 0;
  iVar7 = 0;
  do {
    bVar1 = *(byte *)(iVar6 + uVar11);
    if ((bVar1 & 4) == 0) {
      if ((bVar1 & 3) == 0) {
LAB_300bd428:
        if (iVar7 < 0) {
          puVar5 = (undefined4 *)__errno();
          *puVar5 = 0x26;
          uVar10 = uVar3;
        }
        else if (bVar2) {
          uVar10 = -uVar10;
        }
        if (__endptr != (char **)0x0) {
          if (iVar7 != 0) {
            __nptr = (char *)(pbVar8 + -1);
          }
          *__endptr = __nptr;
        }
        return uVar10;
      }
      iVar12 = -((uint)((bVar1 & 1) == 0) * 0x20 + 0x37);
    }
    else {
      iVar12 = -0x30;
    }
    iVar12 = uVar11 + iVar12;
    if (__base <= iVar12) goto LAB_300bd428;
    if (((iVar7 < 0) || (uVar4 < uVar10)) ||
       ((uVar10 == uVar4 && ((int)(uVar3 - uVar4 * __base) < iVar12)))) {
      iVar7 = -1;
    }
    else {
      iVar7 = 1;
      uVar10 = uVar10 * __base + iVar12;
    }
    uVar11 = (uint)*pbVar8;
    pbVar8 = pbVar8 + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * strtoul @ 0x300BD480  (примерный размер ~404 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, __udiv32
 * Константы: 0xFFFFFFFF, 0x300BD480
 * Данные: DAT_300bd610
 * ---------------------------------------------------------------- */
ulong strtoul(char *__nptr,char **__endptr,int __base)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  ulong uVar9;
  uint uVar10;
  int iVar11;
  byte *pbVar8;
  
  iVar5 = *DAT_300bd610;
  bVar2 = false;
  pbVar7 = (byte *)__nptr;
  do {
    pbVar8 = pbVar7;
    pbVar7 = pbVar8 + 1;
    uVar10 = (uint)*pbVar8;
  } while ((*(byte *)(iVar5 + uVar10) & 0x28) != 0);
  if (uVar10 == 0x2d) {
    bVar2 = true;
  }
  else if (uVar10 != 0x2b) goto LAB_300bd4d0;
  uVar10 = (uint)*pbVar7;
  pbVar7 = pbVar8 + 2;
LAB_300bd4d0:
  if ((((__base == 0) || (__base == 0x10)) && (uVar10 == 0x30)) &&
     (*pbVar7 == 0x78 || *pbVar7 == 0x58)) {
    uVar10 = (uint)pbVar7[1];
    pbVar7 = pbVar7 + 2;
    __base = 0x10;
  }
  if (__base == 0) {
    __base = (uint)(uVar10 != 0x30) * 2 + 8;
  }
  uVar3 = __udiv32(0xffffffff,__base);
  uVar9 = 0;
  iVar6 = 0;
  do {
    bVar1 = *(byte *)(iVar5 + uVar10);
    if ((bVar1 & 4) == 0) {
      if ((bVar1 & 3) == 0) {
LAB_300bd5c0:
        if (iVar6 < 0) {
          uVar9 = 0xffffffff;
          puVar4 = (undefined4 *)__errno();
          *puVar4 = 0x26;
        }
        else if (bVar2) {
          uVar9 = -uVar9;
        }
        if (__endptr != (char **)0x0) {
          if (iVar6 != 0) {
            __nptr = (char *)(pbVar7 + -1);
          }
          *__endptr = __nptr;
        }
        return uVar9;
      }
      iVar11 = -((uint)((bVar1 & 1) == 0) * 0x20 + 0x37);
    }
    else {
      iVar11 = -0x30;
    }
    iVar11 = uVar10 + iVar11;
    if (__base <= iVar11) goto LAB_300bd5c0;
    if (((iVar6 < 0) || (uVar3 < uVar9)) ||
       ((uVar9 == uVar3 && ((int)(-1 - uVar3 * __base) < iVar11)))) {
      iVar6 = -1;
    }
    else {
      iVar6 = 1;
      uVar9 = uVar9 * __base + iVar11;
    }
    uVar10 = (uint)*pbVar7;
    pbVar7 = pbVar7 + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * strtod @ 0x300BD61C  (примерный размер ~876 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 5
 * Вызывает: __adddf3, __divdf3, __floatsidf, __muldf3, ldexp
 * Вызывают: atof
 * Константы: 0x300BD61C, 0x80000000
 * Данные: DAT_300bd974, DAT_300bd978, DAT_300bd97c, DAT_300bd980, DAT_300bd984
 * ---------------------------------------------------------------- */
double strtod(char *__nptr,char **__endptr)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  double dVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  longlong lVar14;
  double in_stack_ffffffb0;
  uint local_48;
  int local_44;
  int local_40;
  uint local_3c;
  
  if (__endptr != (char **)0x0) {
    *__endptr = __nptr;
  }
  iVar10 = *DAT_300bd974;
  do {
    pbVar7 = (byte *)__nptr;
    __nptr = (char *)(pbVar7 + 1);
    uVar8 = (uint)*pbVar7;
  } while ((*(byte *)(iVar10 + uVar8) & 0x28) != 0);
  bVar2 = false;
  if (uVar8 == 0x2b) {
LAB_300bd67c:
    pbVar6 = pbVar7 + 2;
    uVar8 = (uint)(byte)*__nptr;
  }
  else {
    pbVar6 = (byte *)__nptr;
    if (uVar8 == 0x2d) {
      bVar2 = true;
      goto LAB_300bd67c;
    }
  }
  bVar3 = false;
  local_44 = 0;
  local_48 = 0;
  uVar12 = 0;
  while ((*(byte *)(iVar10 + uVar8) & 4) != 0) {
    if (local_44 < 0x12) {
      if ((uVar8 != 0x30) || (local_44 != 0)) {
        uVar12 = __muldf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0,DAT_300bd978);
        uVar13 = __floatsidf(uVar8 - 0x30);
        uVar12 = __adddf3((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar12,
                          (int)((ulonglong)uVar12 >> 0x20));
        local_44 = local_44 + 1;
      }
    }
    else {
      local_48 = local_48 + 1;
    }
    bVar3 = true;
    uVar8 = (uint)*pbVar6;
    pbVar6 = pbVar6 + 1;
  }
  if (uVar8 == 0x2e) {
    bVar1 = *pbVar6;
    while( true ) {
      uVar8 = (uint)bVar1;
      pbVar6 = pbVar6 + 1;
      if ((*(byte *)(iVar10 + uVar8) & 4) == 0) break;
      if (local_44 < 0x12) {
        if ((uVar8 != 0x30) || (local_44 != 0)) {
          uVar12 = __muldf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0,DAT_300bd978);
          uVar13 = __floatsidf(uVar8 - 0x30);
          uVar12 = __adddf3((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar12,
                            (int)((ulonglong)uVar12 >> 0x20));
          local_44 = local_44 + 1;
        }
        local_48 = local_48 - 1;
      }
      bVar1 = *pbVar6;
      bVar3 = true;
    }
  }
  uVar5 = (uint)((ulonglong)uVar12 >> 0x20);
  if ((bVar3) && (__endptr != (char **)0x0)) {
    *__endptr = (char *)(pbVar6 + -1);
  }
  if (bVar2) {
    uVar5 = uVar5 ^ 0x80000000;
  }
  local_40 = 0;
  bVar3 = false;
  bVar2 = false;
  if ((uVar8 != 0x65) && (uVar8 != 0x45)) goto LAB_300bd8ac;
  uVar8 = (uint)*pbVar6;
  if (uVar8 == 0x2b) {
LAB_300bd824:
    pbVar7 = pbVar6 + 2;
    uVar8 = (uint)pbVar6[1];
  }
  else {
    pbVar7 = pbVar6 + 1;
    if (uVar8 == 0x2d) {
      bVar2 = true;
      goto LAB_300bd824;
    }
  }
  while ((*(byte *)(*DAT_300bd974 + uVar8) & 4) != 0) {
    if (local_40 < DAT_300bd97c) {
      local_40 = local_40 * 10 + uVar8 + -0x30;
    }
    bVar3 = true;
    uVar8 = (uint)*pbVar7;
    pbVar7 = pbVar7 + 1;
  }
  if (bVar2) {
    local_40 = -local_40;
  }
  local_48 = local_48 + local_40;
  if ((bVar3) && (__endptr != (char **)0x0)) {
    *__endptr = (char *)(pbVar7 + -1);
  }
LAB_300bd8ac:
  lVar14 = (ulonglong)DAT_300bd980 << 0x20;
  uVar8 = local_48;
  if ((int)local_48 < 1) {
    uVar8 = -local_48;
  }
  local_3c = DAT_300bd984;
  uVar9 = DAT_300bd984 + 0x50;
  while (uVar4 = (undefined4)((ulonglong)lVar14 >> 0x20), uVar8 != 0) {
    if ((uVar8 & 1) != 0) {
      lVar14 = __muldf3((int)lVar14,uVar4);
    }
    uVar8 = (int)uVar8 >> 1;
    if (local_3c < uVar9) {
      local_3c = local_3c + 8;
    }
  }
  if ((int)local_48 < 0) {
    iVar10 = __divdf3((int)uVar12,uVar5,(int)lVar14,uVar4);
  }
  else {
    iVar10 = __muldf3();
  }
  dVar11 = ldexp(in_stack_ffffffb0,iVar10);
  return dVar11;
}

/* ----------------------------------------------------------------
 * strcat @ 0x300BDA50  (примерный размер ~48 байт)
 * Модуль: lib | Вызывают: 35 | Вызывает: 0
 * Вызывают: BSP_DLOAD_GetDloadInfo, BSP_GetProductDloadName, BSP_GetProductInnerName, BSP_GetProductName, BSP_HwGetHwVersion, BSP_IpCfgModifyBootLine, DR_NV_GetFileAbsltPath, FUN_3001c6e8, FUN_300de458, FUN_3010c16c
 *           ...
 * Константы: 0x300BDA50
 * ---------------------------------------------------------------- */
char * strcat(char *__dest,char *__src)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = __dest;
  do {
    pcVar3 = pcVar2;
    pcVar2 = pcVar3 + 1;
  } while (*pcVar3 != '\0');
  do {
    cVar1 = *__src;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
    __src = __src + 1;
  } while (cVar1 != '\0');
  return __dest;
}

/* ----------------------------------------------------------------
 * strchr @ 0x300BDA80  (примерный размер ~40 байт)
 * Модуль: lib | Вызывают: 12 | Вызывает: 0
 * Вызывают: FUN_3000ed18, FUN_300f795c, FUN_300f7ac8, FUN_300f7c20, FUN_300f7d20, FUN_300f7dbc, FUN_300f7f08, dynFSFirstPacketHandle, ledHistFind, shellInternalStrToInt
 *           ...
 * Константы: 0x300BDA80
 * ---------------------------------------------------------------- */
char * strchr(char *__s,int __c)

{
  byte bVar1;
  
  do {
    if ((uint)(byte)*__s == (__c & 0xffU)) {
      return __s;
    }
    bVar1 = *__s;
    __s = (char *)((byte *)__s + 1);
  } while (bVar1 != 0);
  return (char *)0x0;
}

/* ----------------------------------------------------------------
 * strcmp @ 0x300BDAA8  (примерный размер ~56 байт)
 * Модуль: lib | Вызывают: 71 | Вызывает: 0
 * Вызывают: BSP_Flashless_HwGetVerMain, FUN_30024558, FUN_30024828, FUN_3002c4d0, FUN_3002c9a8, FUN_3002cb08, FUN_300a0434, FUN_300c92e0, FUN_300e6a90, FUN_300eb28c
 *           ...
 * Константы: 0x300BDAA8
 * ---------------------------------------------------------------- */
int strcmp(char *__s1,char *__s2)

{
  byte bVar1;
  
  do {
    if (*__s1 != *__s2) {
      return (uint)(byte)*__s1 - (uint)(byte)*__s2;
    }
    bVar1 = *__s1;
    __s1 = (char *)((byte *)__s1 + 1);
    __s2 = (char *)((byte *)__s2 + 1);
  } while (bVar1 != 0);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300bdae0 @ 0x300BDAE0  (примерный размер ~116 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: __strxfrm
 * Вызывают: strcoll
 * Константы: 0x300BDAE0
 * ---------------------------------------------------------------- */
int FUN_300bdae0(int param_1)

{
  int iVar1;
  
  do {
    *(int *)(param_1 + 0x28) = param_1;
    iVar1 = __strxfrm(param_1,param_1 + 0x20,0x20,param_1 + 0x2c);
    if ((iVar1 != 0) && (*(char *)(param_1 + iVar1 + -1) == '\0')) {
      return iVar1 + -1;
    }
    if ((**(char **)(param_1 + 0x20) == '\0') && (*(char *)(param_1 + 0x2c) == '\x10')) {
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x24);
    }
  } while (iVar1 == 0);
  return iVar1;
}

/* ----------------------------------------------------------------
 * strcpy @ 0x300BDC3C  (примерный размер ~32 байт)
 * Модуль: lib | Вызывают: 94 | Вызывает: 0
 * Вызывают: BSP_DLOAD_GetDloadInfo, BSP_IpCfgModifyBootLine, BSP_OM_GetVerTime, DR_NV_GetFileAbsltPath, FUN_3000c208, FUN_3001c6e8, FUN_300a03e0, FUN_300becdc, FUN_300bede0, FUN_300bee1c
 *           ...
 * Константы: 0x300BDC3C
 * ---------------------------------------------------------------- */
char * strcpy(char *__dest,char *__src)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = __dest;
  do {
    cVar1 = *__src;
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
    __src = __src + 1;
  } while (cVar1 != '\0');
  return __dest;
}

/* ----------------------------------------------------------------
 * strcspn @ 0x300BDC5C  (примерный размер ~60 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BDC5C
 * ---------------------------------------------------------------- */
size_t strcspn(char *__s,char *__reject)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar5;
  char *pcVar4;
  
  pcVar4 = __s;
  while( true ) {
    pcVar3 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar5 = __reject;
    if (cVar1 == '\0') break;
    while( true ) {
      cVar2 = *pcVar5;
      pcVar4 = pcVar3;
      if (cVar2 == '\0') break;
      pcVar5 = pcVar5 + 1;
      if (cVar1 == cVar2) goto LAB_300bdc8c;
    }
  }
LAB_300bdc8c:
  return (int)pcVar3 - (int)(__s + 1);
}

/* ----------------------------------------------------------------
 * strerrorIf @ 0x300BDC98  (примерный размер ~168 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: strerror_r
 * Константы: 0x300BDC98
 * Данные: DAT_300bddb4, DAT_300bddb8, DAT_300bddbc, DAT_300bddc0, DAT_300bddc4
 * ---------------------------------------------------------------- */
undefined4 strerrorIf(int param_1)

{
  undefined4 uVar1;
  undefined4 local_14;
  int local_10;
  undefined4 uStack_c;
  
  uVar1 = DAT_300bddb4;
  if (param_1 != 0) {
    if (((code *)*DAT_300bddb8 != (code *)0x0) && (*DAT_300bddbc != 0)) {
      (*(code *)*DAT_300bddb8)(*DAT_300bddbc,0,param_1,0,0,&local_14);
      (*(code *)*DAT_300bddc0)(local_14,&uStack_c);
      (*(code *)*DAT_300bddc4)(local_14,&local_10);
      if (local_10 == param_1) {
        return uStack_c;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * strerror_r @ 0x300BDD40  (примерный размер ~92 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 3
 * Вызывает: snprintf, strerrorIf, strlcpy
 * Вызывают: strerror
 * Константы: 0x300BDD40, 0xFFFFFFFF
 * Данные: DAT_300bddc8
 * ---------------------------------------------------------------- */
char * strerror_r(int __errnum,char *__buf,size_t __buflen)

{
  int iVar1;
  
  if (__buf == (char *)0x0) {
    return (char *)0xffffffff;
  }
  iVar1 = strerrorIf(__errnum);
  if (iVar1 == 0) {
    snprintf(__buf,0x100,DAT_300bddc8,__errnum);
  }
  else {
    strlcpy(__buf,iVar1,0x100);
  }
  return (char *)0x0;
}

/* ----------------------------------------------------------------
 * strerror @ 0x300BDD9C  (примерный размер ~52 байт)
 * Модуль: lib | Вызывают: 7 | Вызывает: 1
 * Вызывает: strerror_r
 * Вызывают: FUN_300f81ac, FUN_3011a5a0, QC_gzerror, perror, tipStart, usrStandaloneInit, xdelete
 * Константы: 0x300BDD9C
 * Данные: DAT_300bddcc
 * ---------------------------------------------------------------- */
char * strerror(int __errnum)

{
  char *pcVar1;
  size_t in_r2;
  
  pcVar1 = DAT_300bddcc;
  strerror_r(__errnum,DAT_300bddcc,in_r2);
  return pcVar1;
}

/* ----------------------------------------------------------------
 * strlen @ 0x300BDDD0  (примерный размер ~24 байт)
 * Модуль: lib | Вызывают: 185 | Вызывает: 0
 * Вызывают: ABB_ReadCfg, ATCommandHandle, ATCommandProcess, BSP_DLOAD_GetDloadVer, BSP_DLOAD_GetISOVer, BSP_DLOAD_GetProductId, BSP_GetProductDloadName, BSP_GetProductInnerName, BSP_GetProductName, BSP_HwGetHwVersion
 *           ...
 * Константы: 0x300BDDD0
 * ---------------------------------------------------------------- */
size_t strlen(char *__s)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = __s;
  do {
    pcVar2 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar2;
  } while (cVar1 != '\0');
  return (int)pcVar2 - (int)(__s + 1);
}

/* ----------------------------------------------------------------
 * strncmp @ 0x300BDE38  (примерный размер ~88 байт)
 * Модуль: lib | Вызывают: 30 | Вызывает: 0
 * Вызывают: FUN_30026f90, FUN_300de384, FUN_300e1b70, FUN_300f5790, FUN_300f7744, FUN_300fdaf4, FUN_300fe2bc, FUN_3010c4f0, FUN_3011ca68, TFUP_IdentifyFile
 *           ...
 * Константы: 0x300BDE38
 * ---------------------------------------------------------------- */
int strncmp(char *__s1,char *__s2,size_t __n)

{
  if (__n != 0) {
    do {
      if (*__s1 != *__s2) {
        return (uint)(byte)*__s1 - (uint)(byte)*__s2;
      }
    } while ((*__s1 != 0) &&
            (__n = __n - 1, __s1 = (char *)((byte *)__s1 + 1), __s2 = (char *)((byte *)__s2 + 1),
            __n != 0));
  }
  return 0;
}

/* ----------------------------------------------------------------
 * strpbrk @ 0x300BDEE0  (примерный размер ~64 байт)
 * Модуль: lib | Вызывают: 8 | Вызывает: 0
 * Вызывают: FUN_30100d80, FUN_3010c7c0, __getZoneInfo, shellInternalStrToInt, shellInternalStrToInt2, shellInternalStrTokenize, shellInternalSymbolsResolve, strtok_r
 * Константы: 0x300BDEE0
 * ---------------------------------------------------------------- */
char * strpbrk(char *__s,char *__accept)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  do {
    pcVar2 = __s;
    pcVar3 = __accept;
    if (*pcVar2 == '\0') {
      return (char *)0x0;
    }
    while( true ) {
      cVar1 = *pcVar3;
      __s = pcVar2 + 1;
      if (cVar1 == '\0') break;
      pcVar3 = pcVar3 + 1;
      if (cVar1 == *pcVar2) {
        return pcVar2;
      }
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * strrchr @ 0x300BDF20  (примерный размер ~40 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 0
 * Вызывают: FUN_300fe2bc, completionPathComplete, completionPathShow, shellInternalSymbolsResolve
 * Константы: 0x300BDF20
 * ---------------------------------------------------------------- */
char * strrchr(char *__s,int __c)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)0x0;
  do {
    if ((uint)(byte)*__s == (__c & 0xffU)) {
      pbVar2 = (byte *)__s;
    }
    bVar1 = *__s;
    __s = (char *)((byte *)__s + 1);
  } while (bVar1 != 0);
  return (char *)pbVar2;
}

/* ----------------------------------------------------------------
 * strspn @ 0x300BDF48  (примерный размер ~60 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: shellInternalStrTokenize, strtok_r
 * Константы: 0x300BDF48
 * ---------------------------------------------------------------- */
size_t strspn(char *__s,char *__accept)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar5 = __s;
  do {
    pcVar4 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar3 = __accept;
    cVar2 = cVar1;
    do {
      if (cVar2 == '\0') {
        return (int)pcVar4 - (int)(__s + 1);
      }
      cVar2 = *pcVar3;
      pcVar5 = pcVar4;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != cVar1);
  } while( true );
}

/* ----------------------------------------------------------------
 * strstr @ 0x300BDF84  (примерный размер ~104 байт)
 * Модуль: lib | Вызывают: 7 | Вызывает: 0
 * Вызывают: ABB_ReadCfg, BSP_IpCfgModifyBootLine, FUN_3000ed18, FUN_300a0434, FUN_300f7ac8, FUN_300f7c20, FUN_301204a4
 * Константы: 0x300BDF84
 * ---------------------------------------------------------------- */
char * strstr(char *__haystack,char *__needle)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (*__needle == '\0') {
    return __haystack;
  }
LAB_300bdf94:
  pcVar3 = __haystack;
  __haystack = pcVar3 + 1;
  cVar1 = *pcVar3;
  if (cVar1 != '\0') goto code_r0x300bdfa0;
  goto LAB_300bdfac;
code_r0x300bdfa0:
  if (cVar1 == *__needle) {
LAB_300bdfac:
    pcVar4 = __needle + 1;
    pcVar5 = __haystack;
    if (cVar1 == '\0') {
      return (char *)0x0;
    }
    do {
      cVar1 = *pcVar4;
      if (cVar1 == '\0') {
        return pcVar3;
      }
      cVar2 = *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 == cVar1);
  }
  goto LAB_300bdf94;
}

/* ----------------------------------------------------------------
 * strtok @ 0x300BDFEC  (примерный размер ~12 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 1
 * Вызывает: strtok_r
 * Вызывают: FUN_300f7d20, FUN_300f81ac
 * Константы: 0x300BDFEC
 * Данные: DAT_300bdff4
 * ---------------------------------------------------------------- */
char * strtok(char *__s,char *__delim)

{
  char *pcVar1;
  
  pcVar1 = strtok_r(__s,__delim,DAT_300bdff4);
  return pcVar1;
}

/* ----------------------------------------------------------------
 * strtok_r @ 0x300BDFF8  (примерный размер ~136 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 2
 * Вызывает: strpbrk, strspn
 * Вызывают: __getDstInfo, strtok
 * Константы: 0x300BDFF8
 * ---------------------------------------------------------------- */
char * strtok_r(char *__s,char *__delim,char **__save_ptr)

{
  size_t sVar1;
  char *pcVar2;
  char *__s_00;
  
  if ((__s == (char *)0x0) && (__s = *__save_ptr, __s == (char *)0x0)) {
    return (char *)0x0;
  }
  sVar1 = strspn(__s,__delim);
  __s_00 = __s + sVar1;
  if (*__s_00 != '\0') {
    pcVar2 = strpbrk(__s_00,__delim);
    *__save_ptr = pcVar2;
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
      *__save_ptr = pcVar2 + 1;
    }
    return __s_00;
  }
  *__save_ptr = (char *)0x0;
  return (char *)0x0;
}

/* ----------------------------------------------------------------
 * __strxfrm @ 0x300BE080  (примерный размер ~300 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300bdae0, strxfrm
 * Константы: 0x300BE080
 * Данные: DAT_300be274
 * ---------------------------------------------------------------- */
uint __strxfrm(int param_1,undefined4 *param_2,uint param_3,byte *param_4)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar5 = (uint)*param_4;
  pbVar6 = (byte *)*param_2;
  uVar9 = (uint)*(ushort *)(param_4 + 2);
  bVar2 = false;
  uVar3 = 0;
  while ((uVar5 < 0x10 && (iVar7 = *(int *)(DAT_300be274 + uVar5 * 4), iVar7 != 0))) {
    uVar1 = *(ushort *)(iVar7 + (uint)*pbVar6 * 2);
    uVar10 = (uint)uVar1;
    if (uVar10 == 0) break;
    uVar5 = (int)(uVar10 & 0xf00) >> 8;
    if ((uVar1 & 0x8000) != 0) {
      uVar9 = uVar9 & 0xff00 | uVar10 & 0xff;
    }
    if ((uVar1 & 0x1000) != 0) {
      uVar9 = (uVar9 << 0x10) >> 0x18 | uVar9 << 8;
    }
    uVar4 = uVar3;
    if ((uVar1 & 0x2000) != 0) {
      uVar8 = uVar9;
      if ((uVar1 & 0xff) != 0) {
        uVar8 = uVar10;
      }
      uVar4 = uVar3 + 1;
      *(char *)(param_1 + uVar3) = (char)uVar8;
      if (((uVar8 & 0xff) == 0) || (param_3 <= uVar4)) {
        bVar2 = true;
      }
    }
    if ((uVar1 & 0x4000) != 0) {
      if (*pbVar6 == 0) {
        bVar2 = true;
      }
      else {
        pbVar6 = pbVar6 + 1;
      }
    }
    uVar3 = uVar4;
    if (bVar2) {
      *param_2 = pbVar6;
      *param_4 = (byte)((uVar10 & 0xf00) >> 8);
      *(short *)(param_4 + 2) = (short)uVar9;
      return uVar4;
    }
  }
  *(undefined1 *)(param_1 + uVar3) = 0;
  *param_2 = pbVar6;
  *param_4 = 0x10;
  return uVar3 + 1;
}

/* ----------------------------------------------------------------
 * asctime_r @ 0x300BE3F0  (примерный размер ~32 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 1
 * Вызывает: strftime
 * Вызывают: asctime, ctime_r
 * Константы: 0x300BE3F0
 * Данные: DAT_300be43c
 * ---------------------------------------------------------------- */
char * asctime_r(tm *__tp,char *__buf)

{
  char *pcVar1;
  size_t *in_r2;
  
  pcVar1 = (char *)strftime(__buf,*in_r2,DAT_300be43c,__tp);
  return pcVar1;
}

/* ----------------------------------------------------------------
 * asctime @ 0x300BE410  (примерный размер ~52 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: asctime_r
 * Константы: 0x300BE410
 * Данные: DAT_300be440
 * ---------------------------------------------------------------- */
char * asctime(tm *__tp)

{
  char *pcVar1;
  
  pcVar1 = DAT_300be440;
  asctime_r(__tp,DAT_300be440);
  return pcVar1;
}

/* ----------------------------------------------------------------
 * ctime_r @ 0x300BE44C  (примерный размер ~36 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 2
 * Вызывает: asctime_r, localtime
 * Вызывают: ctime
 * Константы: 0x300BE44C
 * ---------------------------------------------------------------- */
char * ctime_r(time_t *__timer,char *__buf)

{
  tm *__tp;
  
  __tp = localtime(__timer);
  asctime_r(__tp,__buf);
  return __buf;
}

/* ----------------------------------------------------------------
 * ctime @ 0x300BE470  (примерный размер ~40 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: ctime_r
 * Константы: 0x300BE470
 * Данные: DAT_300be494
 * ---------------------------------------------------------------- */
char * ctime(time_t *__timer)

{
  char *pcVar1;
  
  pcVar1 = ctime_r(__timer,DAT_300be494);
  return pcVar1;
}

/* ----------------------------------------------------------------
 * __daysSinceEpoch @ 0x300BE498  (примерный размер ~136 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 1
 * Вызывает: __div32
 * Вызывают: __getTime, mktime
 * Константы: 0x300BE498
 * Данные: DAT_300be720, DAT_300be724
 * ---------------------------------------------------------------- */
int __daysSinceEpoch(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 0) {
    iVar1 = __div32(param_1 + -0x1e,100);
    iVar2 = __div32(param_1 + -0x1e,400);
    iVar1 = iVar1 - iVar2;
    iVar2 = -2;
  }
  else {
    iVar1 = __div32(param_1 + 0x45,100);
    iVar2 = __div32(param_1 + DAT_300be720,400);
    iVar1 = iVar1 - iVar2;
    iVar2 = 1;
  }
  iVar2 = __div32(param_1 + iVar2,4);
  return param_2 + ((param_1 * DAT_300be724 + iVar2) - iVar1);
}

/* ----------------------------------------------------------------
 * __julday @ 0x300BE520  (примерный размер ~112 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 1
 * Вызывает: __rem32
 * Вызывают: FUN_300be870, __getTime, mktime
 * Константы: 0x300BE520
 * Данные: DAT_300be728, DAT_300be72c
 * ---------------------------------------------------------------- */
int __julday(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  param_1 = param_1 + DAT_300be728;
  iVar2 = 0;
  iVar1 = __rem32(param_1,4);
  if ((((iVar1 == 0) && (iVar1 = __rem32(param_1,100), iVar1 != 0)) ||
      (iVar1 = __rem32(param_1,400), iVar1 == 0)) && (1 < param_2)) {
    iVar2 = 1;
  }
  return iVar2 + param_3 + *(int *)(DAT_300be72c + param_2 * 4);
}

/* ----------------------------------------------------------------
 * __getTime @ 0x300BE590  (примерный размер ~360 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 7
 * Вызывает: __daysSinceEpoch, __div32, __julday, __rem32, __udiv32, __urem32, ldiv_r
 * Вызывают: gmtime, gmtime_r, localtime_r
 * Константы: 0x300BE590
 * Данные: DAT_300be724, DAT_300be728, DAT_300be730, DAT_300be734
 * ---------------------------------------------------------------- */
undefined4 __getTime(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar1 = __udiv32(param_1,DAT_300be730);
  iVar2 = __urem32(param_1,DAT_300be730);
  if (iVar2 < 0) {
    iVar1 = iVar1 + -1;
    iVar2 = iVar2 + DAT_300be730;
  }
  iVar3 = __div32(iVar1,DAT_300be724);
  while (iVar4 = __daysSinceEpoch(iVar3,0), iVar1 < iVar4) {
    iVar3 = iVar3 + -1;
  }
  iVar4 = __rem32(iVar1 + 4,7);
  param_2[6] = iVar4;
  if (iVar4 < 0) {
    param_2[6] = iVar4 + 7;
  }
  iVar4 = __daysSinceEpoch(iVar3,0);
  iVar7 = (iVar3 + DAT_300be734) - DAT_300be728;
  iVar5 = __julday(iVar7,1,0);
  for (iVar3 = 0; (iVar5 <= iVar1 - iVar4 && (iVar3 < 0xb)); iVar3 = iVar3 + 1) {
    iVar5 = __julday(iVar7,iVar3 + 2,0);
  }
  param_2[5] = iVar7;
  param_2[4] = iVar3;
  iVar5 = __julday(iVar7,iVar3,0);
  param_2[3] = ((iVar1 - iVar4) - iVar5) + 1;
  iVar1 = __julday(iVar7,iVar3);
  param_2[7] = iVar1 + -1;
  uVar6 = __div32(iVar2,0xe10);
  param_2[2] = uVar6;
  uVar6 = __rem32(iVar2,0xe10);
  ldiv_r(uVar6,0x3c,&local_20);
  param_2[1] = local_20;
  *param_2 = local_1c;
  return 0;
}

/* ----------------------------------------------------------------
 * gmtime_r @ 0x300BE6F8  (примерный размер ~12 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: __getTime
 * Константы: 0x300BE6F8
 * ---------------------------------------------------------------- */
tm * gmtime_r(time_t *__timer,tm *__tp)

{
  tm *ptVar1;
  
  ptVar1 = (tm *)__getTime(*__timer,__tp,__timer);
  return ptVar1;
}

/* ----------------------------------------------------------------
 * gmtime @ 0x300BE704  (примерный размер ~56 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: __getTime
 * Константы: 0x300BE704
 * Данные: DAT_300be738
 * ---------------------------------------------------------------- */
tm * gmtime(time_t *__timer)

{
  tm *ptVar1;
  
  ptVar1 = DAT_300be738;
  __getTime(*__timer,DAT_300be738);
  return ptVar1;
}

/* ----------------------------------------------------------------
 * localtime_r @ 0x300BE73C  (примерный размер ~152 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 4
 * Вызывает: __getDstInfo, __getTime, __getZoneInfo, atoi
 * Вызывают: FUN_300d8710, FUN_301196f0, localtime
 * Константы: 0x300BE73C
 * Данные: DAT_300be7ec
 * ---------------------------------------------------------------- */
tm * localtime_r(time_t *__timer,tm *__tp)

{
  int iVar1;
  int iVar2;
  char acStack_2c [28];
  
  __getZoneInfo(acStack_2c,2,*DAT_300be7ec);
  iVar1 = atoi(acStack_2c);
  __getTime(*__timer + iVar1 * -0x3c,__tp);
  iVar1 = __getDstInfo(__tp,*DAT_300be7ec);
  __tp->tm_isdst = iVar1;
  if (iVar1 != 0) {
    iVar2 = atoi(acStack_2c);
    __getTime(iVar1 * 0xe10 + *__timer + iVar2 * -0x3c,__tp);
  }
  return (tm *)0x0;
}

/* ----------------------------------------------------------------
 * localtime @ 0x300BE7D4  (примерный размер ~32 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: localtime_r
 * Вызывают: ctime_r
 * Константы: 0x300BE7D4
 * Данные: DAT_300be7f0
 * ---------------------------------------------------------------- */
tm * localtime(time_t *__timer)

{
  tm *ptVar1;
  
  ptVar1 = DAT_300be7f0;
  localtime_r(__timer,DAT_300be7f0);
  return ptVar1;
}

/* ----------------------------------------------------------------
 * FUN_300be7f4 @ 0x300BE7F4  (примерный размер ~124 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: __div32
 * Вызывают: FUN_300be870
 * Константы: 0x300BE7F4
 * ---------------------------------------------------------------- */
void FUN_300be7f4(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __div32(*param_2,param_3);
  *param_1 = iVar1 + *param_1;
  iVar2 = *param_2;
  iVar1 = __div32(iVar2,param_3);
  iVar2 = iVar2 - param_3 * iVar1;
  *param_2 = iVar2;
  iVar1 = __div32(iVar2,param_3);
  if (-1 < iVar2 - param_3 * iVar1) {
    return;
  }
  *param_1 = *param_1 + -1;
  *param_2 = param_3 + *param_2;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300be870 @ 0x300BE870  (примерный размер ~552 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300be7f4, __julday, __rem32
 * Вызывают: mktime
 * Константы: 0x300BE870
 * Данные: DAT_300beb74, DAT_300beb78, DAT_300beb7c
 * ---------------------------------------------------------------- */
void FUN_300be870(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uStack_40;
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  int local_34;
  int local_30;
  int local_2c [4];
  
  iVar5 = 9;
  puVar6 = &uStack_40;
  puVar7 = param_1;
  do {
    iVar5 = iVar5 + -1;
    *puVar6 = *puVar7;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  } while (iVar5 != 0);
  FUN_300be7f4(auStack_3c,&uStack_40,0x3c);
  FUN_300be7f4(auStack_38,auStack_3c,0x3c);
  FUN_300be7f4(&local_34,auStack_38,0x18);
  FUN_300be7f4(local_2c,&local_30,0xc);
  iVar1 = __julday(local_2c[0],local_30,local_34);
  iVar5 = DAT_300beb74;
  iVar2 = local_2c[0];
  if (iVar1 < 1) {
    do {
      iVar8 = local_2c[0] + -1;
      iVar2 = __rem32(iVar8 + iVar5,4);
      if (((iVar2 != 0) || (iVar3 = __rem32(iVar8 + iVar5,100), iVar2 = DAT_300beb78, iVar3 == 0))
         && (iVar3 = __rem32(iVar8 + iVar5,400), iVar2 = DAT_300beb78, iVar3 != 0)) {
        iVar2 = DAT_300beb7c;
      }
      iVar1 = iVar1 + iVar2;
      local_2c[0] = iVar8;
    } while (iVar1 < 1);
  }
  else {
    while( true ) {
      iVar8 = __rem32(iVar2 + iVar5,4);
      if (((iVar8 != 0) || (iVar4 = __rem32(iVar2 + iVar5,100), iVar3 = DAT_300beb78, iVar4 == 0))
         && (iVar4 = __rem32(iVar2 + iVar5,400), iVar3 = DAT_300beb78, iVar4 != 0)) {
        iVar3 = DAT_300beb7c;
      }
      local_2c[0] = iVar2;
      if (iVar1 <= iVar3) break;
      if (((iVar8 != 0) || (iVar3 = __rem32(iVar2 + iVar5,100), iVar8 = DAT_300beb78, iVar3 == 0))
         && (iVar3 = __rem32(iVar2 + iVar5,400), iVar8 = DAT_300beb78, iVar3 != 0)) {
        iVar8 = DAT_300beb7c;
      }
      iVar1 = iVar1 - iVar8;
      iVar2 = iVar2 + 1;
    }
  }
  iVar5 = __julday(local_2c[0],1,0);
  for (local_30 = 0; (iVar5 < iVar1 && (local_30 < 0xb)); local_30 = local_30 + 1) {
    iVar5 = __julday(local_2c[0],local_30 + 2,0);
  }
  iVar5 = __julday(local_2c[0],local_30,0);
  local_34 = iVar1 - iVar5;
  local_2c[1] = 0;
  local_2c[2] = 0;
  iVar5 = 9;
  puVar6 = &uStack_40;
  do {
    iVar5 = iVar5 + -1;
    *param_1 = *puVar6;
    param_1 = param_1 + 1;
    puVar6 = puVar6 + 1;
  } while (iVar5 != 0);
  return;
}

/* ----------------------------------------------------------------
 * mktime @ 0x300BEA98  (примерный размер ~244 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_300be870, __daysSinceEpoch, __getDstInfo, __getZoneInfo, __julday, __rem32, atoi
 * Вызывают: FUN_300d8610
 * Константы: 0x300BEA98
 * Данные: DAT_300beb74, DAT_300beb80, DAT_300beb84, DAT_300beb88
 * ---------------------------------------------------------------- */
time_t mktime(tm *__tp)

{
  int iVar1;
  time_t tVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char acStack_2c [28];
  
  FUN_300be870();
  iVar4 = __tp->tm_sec;
  iVar5 = __tp->tm_min;
  iVar6 = __tp->tm_hour;
  iVar1 = __julday(__tp->tm_year,__tp->tm_mon,__tp->tm_mday);
  __tp->tm_yday = iVar1 + -1;
  if (__tp->tm_year + DAT_300beb74 < DAT_300beb80) {
    tVar2 = -1;
  }
  else {
    iVar1 = __daysSinceEpoch(__tp->tm_year + -0x46);
    iVar3 = __rem32(iVar1 + 4,7);
    __tp->tm_wday = iVar3;
    iVar4 = iVar1 * DAT_300beb88 + iVar6 * 0xe10 + iVar5 * 0x3c + iVar4;
    iVar1 = __getDstInfo(__tp,*DAT_300beb84);
    __tp->tm_isdst = iVar1;
    if (iVar1 != 0) {
      iVar4 = iVar4 + -0xe10;
      FUN_300be870(__tp);
    }
    __getZoneInfo(acStack_2c,2,*DAT_300beb84);
    iVar1 = atoi(acStack_2c);
    tVar2 = iVar1 * 0x3c + iVar4;
  }
  return tVar2;
}

