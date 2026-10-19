/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 8 (функций: 150, адреса 0x300B8D00..0x300C9C20)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * _ll_sfrom_f_r @ 0x300B8D00  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x300B8D00, 0x80000000, 0xDF000001, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
undefined8 _ll_sfrom_f_r(uint param_1)

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
 * _ll_ufrom_f_r @ 0x300B8EB4  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x300B8EB4, 0x80000000, 0x7F000000
 * ---------------------------------------------------------------- */
undefined8 _ll_ufrom_f_r(int param_1)

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
 * _fcmpge @ 0x300B8F14  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Вызывают: _f_fge, _f_fgt
 * Константы: 0xFF000001, 0x00800000, 0x300B8F14
 * ---------------------------------------------------------------- */
void _fcmpge(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_1 | param_2;
  if ((int)uVar1 < 0) {
    if ((int)(uVar1 + 0x800000) < 0) {
      return;
    }
    param_1 = param_1 * 2;
    if (param_1 < 0xff000001) {
      param_1 = param_2 * 2;
    }
    if (param_1 < 0xff000001) {
      return;
    }
  }
  else {
    if (-1 < (int)(uVar1 + 0x800000)) {
      return;
    }
    param_1 = param_1 * 2;
    if (param_1 < 0xff000001) {
      param_1 = param_2 * 2;
    }
    if (param_1 < 0xff000001) {
      return;
    }
  }
  __fpl_exception();
  return;
}

/* ----------------------------------------------------------------
 * _fcmple @ 0x300B8F7C  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Вызывают: _f_fle, _f_flt
 * Константы: 0xFF000001, 0x00800000, 0x300B8F7C
 * ---------------------------------------------------------------- */
void _fcmple(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_1 | param_2;
  if ((int)uVar1 < 0) {
    if ((int)(uVar1 + 0x800000) < 0) {
      return;
    }
    param_1 = param_1 * 2;
    if (param_1 < 0xff000001) {
      param_1 = param_2 * 2;
    }
    if (param_1 < 0xff000001) {
      return;
    }
  }
  else {
    if (-1 < (int)(uVar1 + 0x800000)) {
      return;
    }
    param_1 = param_1 * 2;
    if (param_1 < 0xff000001) {
      param_1 = param_2 * 2;
    }
    if (param_1 < 0xff000001) {
      return;
    }
  }
  __fpl_exception();
  return;
}

/* ----------------------------------------------------------------
 * _fp_trapveneer @ 0x300B9208  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 15 | Вызывает: 2
 * Вызывает: __fpl_cmpreturn, _fp_trap
 * Вызывают: __addsf3, __divdf3, __divsf3, __dunder, __dunder_d, __extendsfdf2, __fpl_exception, __fpl_fcheck_NaN2, __funder, __funder_d
 *           ...
 * Константы: 0x300B9208
 * ---------------------------------------------------------------- */
void _fp_trapveneer(void)

{
  uint in_r12;
  
  _fp_trap();
  if ((in_r12 & 0xf) != 9) {
    return;
  }
  __fpl_cmpreturn();
  return;
}

/* ----------------------------------------------------------------
 * _drsb @ 0x300B947C  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: __dunder, __dunder_d, __fpl_exception, __fpl_return_NaN
 * Константы: 0x00100000, 0x80000000, 0x7FFFFFFF, 0xFFFFFFFE, 0xFFF00001, 0xA0000000, 0x00200000, 0x300B947C
 * Данные: DAT_300b9728
 * ---------------------------------------------------------------- */
ulonglong _drsb(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  ulonglong uVar14;
  
  if ((DAT_300b9728 & ~(param_2 << 1)) == 0 || (DAT_300b9728 & ~(param_4 << 1)) == 0) {
    uVar3 = param_4 * 2 + (uint)(param_3 != 0);
    uVar8 = param_2 * 2 + (uint)(param_1 != 0);
    bVar13 = DAT_300b9728 <= uVar3;
    bVar12 = uVar3 == DAT_300b9728;
    if (!bVar13 || bVar12) {
      bVar13 = DAT_300b9728 <= uVar8;
      bVar12 = uVar8 == DAT_300b9728;
    }
    if (bVar13 && !bVar12) {
      uVar8 = param_4 * 2 + 0x100000 + (uint)(param_3 != 0);
      uVar3 = uVar8;
      if (uVar8 < 0xfff00001) {
        uVar3 = param_2 * 2 + 0x100000 + (uint)(param_1 != 0);
      }
      if (uVar3 < 0xfff00001) {
        if (0xfffff < uVar8) {
          param_3 = param_1;
          param_4 = param_2;
        }
        uVar14 = __fpl_return_NaN(param_3,param_4);
        return uVar14;
      }
      uVar14 = __fpl_exception();
      return uVar14;
    }
    if (uVar3 == uVar8) {
      if ((int)(param_4 ^ param_2) < 0) {
        return CONCAT44(param_4,param_3);
      }
      uVar14 = __fpl_exception();
      return uVar14;
    }
    if (uVar3 == DAT_300b9728) {
      return CONCAT44(param_4,param_3);
    }
    return CONCAT44(param_2,param_1) ^ 0x8000000000000000;
  }
  uVar3 = param_2 ^ 0x80000000;
  if ((int)(param_2 ^ param_4) < 0) {
    uVar8 = param_1 - param_3;
    iVar7 = uVar3 - (param_4 + (param_3 > param_1));
    if (uVar3 <= param_4 && (uint)(param_3 <= param_1) <= uVar3 - param_4) {
      bVar12 = CARRY4(param_3,uVar8);
      param_3 = param_3 + uVar8;
      param_4 = param_4 + iVar7 + (uint)bVar12;
      bVar12 = param_1 < uVar8;
      param_1 = param_1 - uVar8;
      uVar3 = uVar3 - (iVar7 + (uint)bVar12);
    }
    uVar8 = uVar3 >> 0x14;
    uVar11 = uVar8 - (param_4 >> 0x14);
    if ((DAT_300b9728 & param_4 << 1) == 0) {
      if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) {
        if ((uVar8 & 0x7ff) != 0) {
          return CONCAT44(uVar3,param_1);
        }
        if (param_1 == 0 && (uVar3 & 0x7fffffff) == 0) {
          return CONCAT44(uVar3,param_1);
        }
      }
      else {
        uVar3 = uVar3 & ~(uVar8 << 0x14);
        if ((uVar8 & 0x7ff) != 0) {
          param_4 = param_4 & 0x7fffffff;
          uVar11 = uVar11 - 1;
          goto LAB_300b9304;
        }
        bVar12 = CARRY4(param_1,param_3);
        param_1 = param_1 + param_3;
        uVar3 = uVar3 + param_4 + (uint)bVar12;
      }
      goto LAB_300b96bc;
    }
    uVar3 = uVar3 & ~(uVar8 << 0x14);
    param_4 = param_4 & ~DAT_300b9728 | 0x100000;
LAB_300b9304:
    uVar4 = 0x20 - uVar11;
    if (uVar11 < 0x21) {
      uVar10 = param_3 >> (uVar11 & 0xff);
      bVar12 = CARRY4(param_1,uVar10);
      uVar10 = param_1 + uVar10;
      uVar5 = param_4 << (uVar4 & 0xff);
      param_1 = uVar10 + uVar5;
      uVar11 = uVar3 + (param_4 >> (uVar11 & 0xff)) + (uint)bVar12 + (uint)CARRY4(uVar10,uVar5);
      if (0xfffff < uVar11) {
LAB_300b938c:
        uVar3 = (uVar11 + 0x100000 >> 1) + uVar8 * 0x100000;
        bVar12 = (bool)((byte)param_1 & 1);
        uVar8 = (uint)((byte)(uVar11 + 0x100000) & 1) << 0x1f | param_1 >> 1;
        if (!bVar12) {
LAB_300b93c4:
          if (uVar3 * 2 < 0xffe00000) {
            return CONCAT44(uVar3,uVar8);
          }
          uVar14 = __fpl_exception(uVar8,uVar3 + 0xa0000000);
          return uVar14;
        }
        bVar13 = CARRY4(uVar8,(uint)bVar12);
        uVar8 = uVar8 + bVar12;
        uVar11 = uVar8;
        if (!bVar13) {
          uVar11 = param_3 << (uVar4 & 0xff);
        }
        if (uVar11 != 0) goto LAB_300b93c4;
        goto LAB_300b9340;
      }
      uVar3 = uVar11 + uVar8 * 0x100000;
    }
    else {
      param_3 = param_4 * 2 + (uint)(param_3 != 0);
      uVar11 = uVar11 - 0x20;
      bVar12 = uVar11 < 0x20;
      uVar4 = 0x1f - uVar11;
      if (bVar12) {
        param_4 = param_4 >> (uVar11 & 0xff);
        bVar12 = CARRY4(param_1,param_4);
        param_1 = param_1 + param_4;
      }
      else {
        uVar4 = 0;
      }
      uVar3 = uVar3 + uVar8 * 0x100000 + (uint)bVar12;
      if (uVar8 != uVar3 >> 0x14) {
        uVar11 = uVar3 + uVar8 * -0x100000;
        goto LAB_300b938c;
      }
    }
    iVar7 = param_3 << (uVar4 & 0xff);
    if (-1 < iVar7) {
      return CONCAT44(uVar3,param_1);
    }
    uVar8 = param_1 + 1;
    uVar11 = uVar8;
    if (param_1 != 0xffffffff) {
      uVar11 = iVar7 << 1;
    }
    if (uVar11 != 0) {
      return CONCAT44(uVar3,uVar8);
    }
LAB_300b9340:
    if (uVar8 == 0) {
      uVar3 = uVar3 + 1;
      uVar8 = 0;
    }
    else {
      uVar8 = uVar8 & 0xfffffffe;
    }
    bVar12 = 0xffdfffff < uVar3 << 1;
    if (!bVar12) {
      return CONCAT44(uVar3,uVar8);
    }
    if (bVar12) {
      uVar3 = uVar3 + 0xa0000000;
    }
    uVar14 = __fpl_exception(uVar8,uVar3);
    return uVar14;
  }
  param_4 = param_4 ^ 0x80000000;
  uVar8 = param_1 - param_3;
  if (uVar3 <= param_4 && (uint)(param_3 <= param_1) <= uVar3 - param_4) {
    uVar11 = uVar3 - (param_4 + (param_3 > param_1)) ^ 0x80000000;
    bVar12 = CARRY4(param_3,uVar8);
    param_3 = param_3 + uVar8;
    param_4 = param_4 + uVar11 + (uint)bVar12;
    bVar12 = param_1 < uVar8;
    param_1 = param_1 - uVar8;
    uVar3 = uVar3 - (uVar11 + bVar12);
  }
  uVar8 = uVar3 >> 0x14;
  uVar11 = uVar8 - (param_4 >> 0x14);
  if ((DAT_300b9728 & param_4 << 1) == 0) {
    if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
      if (param_1 == 0 && (uVar3 & 0x7fffffff) == 0) goto LAB_300b96b0;
    }
    else {
      uVar4 = uVar3 & ~(uVar8 << 0x14);
      if ((uVar8 & 0x7ff) != 0) {
        uVar11 = uVar11 - 1;
        iVar7 = -((param_4 & 0x7fffffff) + (uint)(param_3 != 0));
        goto LAB_300b9520;
      }
      bVar12 = param_1 < param_3;
      param_1 = param_1 - param_3;
      uVar3 = uVar4 - (param_4 + bVar12);
    }
  }
  else {
    uVar4 = uVar3 & ~(uVar8 << 0x14);
    iVar7 = ((int)DAT_300b9728 >> 1) -
            ((param_4 & ~((int)DAT_300b9728 >> 1)) + (uint)(param_3 != 0));
LAB_300b9520:
    uVar5 = -param_3;
    uVar10 = 0x20 - uVar11;
    if (uVar11 < 0x21) {
      uVar2 = uVar5 >> (uVar11 & 0xff);
      uVar1 = param_1 + uVar2;
      uVar4 = uVar4 + (iVar7 >> (uVar11 & 0xff)) + (uint)CARRY4(param_1,uVar2);
      uVar11 = iVar7 << (uVar10 & 0xff);
      uVar2 = uVar1 + uVar11;
      bVar12 = CARRY4(uVar4,(uint)CARRY4(uVar1,uVar11));
      iVar7 = uVar4 + CARRY4(uVar1,uVar11);
    }
    else {
      param_3 = param_3 * -2;
      if (param_3 != 0) {
        param_3 = 1;
      }
      uVar5 = param_3 | (iVar7 * 2 + (uint)CARRY4(uVar5,uVar5)) * 2;
      uVar11 = uVar11 - 0x20;
      uVar10 = 0x1e - uVar11;
      if (0x1e < uVar11 || uVar10 == 0) {
        return CONCAT44(uVar4 + uVar8 * 0x100000,param_1);
      }
      uVar11 = iVar7 >> (uVar11 & 0xff);
      uVar2 = param_1 + uVar11;
      bVar12 = uVar4 != 0 || uVar4 < CARRY4(param_1,uVar11);
      iVar7 = uVar4 - !CARRY4(param_1,uVar11);
    }
    if (-1 < iVar7) {
      iVar7 = iVar7 + uVar8 * 0x100000;
      iVar6 = uVar5 << (uVar10 & 0xff);
      if (-1 < iVar6) {
        return CONCAT44(iVar7,uVar2);
      }
      uVar2 = uVar2 + 1;
      if (uVar2 != 0 && iVar6 != -0x80000000) {
        return CONCAT44(iVar7,uVar2);
      }
      if (uVar2 == 0) {
        iVar7 = iVar7 + 1;
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 & 0xfffffffe;
      }
      return CONCAT44(iVar7,uVar2);
    }
    uVar11 = uVar10 + 1 & 0xff;
    bVar12 = uVar11 == 0 && bVar12 || uVar11 != 0 && (bool)((byte)(uVar5 >> 0x20 - uVar11) & 1);
    param_1 = uVar2 * 2 + (uint)bVar12;
    iVar7 = iVar7 * 2 + (uint)(CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar12));
    uVar4 = iVar7 + uVar8 * 0x200000;
    bVar12 = (bool)((byte)(uVar4 >> 0x14) & 1);
    if (bVar12 && uVar4 >> 0x15 != 0) {
      iVar7 = iVar7 + uVar8 * 0x100000;
      uVar3 = -((int)(uVar5 << uVar11) >> 0x1f);
      uVar8 = param_1 + uVar3;
      bVar12 = uVar8 == 0;
      if (!CARRY4(param_1,uVar3)) {
        bVar12 = uVar5 << uVar11 == -0x80000000;
      }
      if (!bVar12) {
        return CONCAT44(iVar7,uVar8);
      }
      if (uVar8 == 0) {
        iVar7 = iVar7 + 1;
        uVar8 = 0;
      }
      else {
        uVar8 = uVar8 & 0xfffffffe;
      }
      return CONCAT44(iVar7,uVar8);
    }
    if (!bVar12) {
      iVar7 = iVar7 + 0x200000;
      if (iVar7 != 0 || param_1 != 0) {
        iVar6 = LZCOUNT(iVar7);
        if (iVar6 == 0x20) {
          iVar6 = LZCOUNT(param_1) + 0x20;
        }
        uVar11 = iVar6 - 0xb;
        iVar9 = ((uVar8 & 0xfffff7ff) - 2) - uVar11;
        if (uVar11 < 0x20) {
          uVar8 = iVar7 << (uVar11 & 0xff) | param_1 >> (0x20 - uVar11 & 0xff);
          iVar7 = param_1 << (uVar11 & 0xff);
        }
        else {
          uVar8 = param_1 << (iVar6 - 0x2bU & 0xff);
          iVar7 = 0;
        }
        iVar6 = uVar8 + (uVar3 & 0x80000000) + iVar9 * 0x100000;
        if (0 < iVar9) {
          return CONCAT44(iVar6,iVar7);
        }
        uVar14 = __dunder(iVar7,iVar6 + 0x60000000);
        return uVar14;
      }
      goto LAB_300b96b0;
    }
    param_1 = (uint)((byte)iVar7 & 1) << 0x1f | param_1 >> 1;
    uVar3 = (iVar7 >> 1) + uVar8 * 0x100000;
  }
LAB_300b96bc:
  if (uVar3 << 1 != 0 || param_1 != 0) {
    if (0x1fffff < uVar3 << 1) {
      return CONCAT44(uVar3,param_1);
    }
    uVar14 = __dunder_d();
    return uVar14;
  }
LAB_300b96b0:
  return (ulonglong)param_1;
}

/* ----------------------------------------------------------------
 * _d_utod @ 0x300B9738  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: __dflt_normalise
 * Вызывают: difftime
 * Константы: 0x300B9738, 0x40000000
 * ---------------------------------------------------------------- */
void _d_utod(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  __dflt_normalise(param_1,param_1,param_3,0x40000000);
  return;
}

/* ----------------------------------------------------------------
 * _d_ulltod @ 0x300B9774  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300B9774, 0x00200000, 0x00100000, 0x41D00000
 * ---------------------------------------------------------------- */
undefined8 _d_ulltod(uint param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_2 != 0) {
    iVar3 = 0x20;
    uVar5 = param_2;
  }
  else {
    iVar3 = 0;
    uVar5 = param_1;
  }
  if (param_2 != 0 || param_1 != 0) {
    uVar4 = iVar3 - LZCOUNT(uVar5);
    uVar5 = uVar5 << LZCOUNT(uVar5) | param_1 >> (uVar4 & 0xff);
    param_1 = param_1 << (0x20 - uVar4 & 0xff);
    bVar2 = (byte)(param_1 >> 10);
    if ((param_1 & 0x3ff) == 0) {
      bVar2 = (byte)((param_1 & param_1 >> 1) >> 10);
    }
    param_1 = param_1 >> 0xb;
    uVar1 = uVar5 * 0x200000;
    return CONCAT44(uVar4 * 0x100000 + 0x41d00000 + (uVar5 >> 0xb) +
                    (uint)(CARRY4(param_1,uVar1) || CARRY4(param_1 + uVar1,(uint)(bVar2 & 1))),
                    param_1 + uVar1 + (uint)(bVar2 & 1));
  }
  return CONCAT44(uVar5,param_1);
}

/* ----------------------------------------------------------------
 * _frsb @ 0x300B9BE4  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: __fpl_exception, __fpl_return_NaN, __funder_d, __rt_fp_status_addr, _fp_trapveneer
 * Константы: 0x80000000, 0x00800000, 0xFF000000, 0x7F800000, 0x7FFFFFFF, 0xFFFFFFFE, 0xFEFFFFFF, 0x300B9BE4
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

uint _frsb(uint param_1,uint param_2)

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
    uVar4 = param_2 * 2;
    if (0xff000000 < param_1 << 1 || 0xff000000 < uVar4) {
      uVar5 = param_2 * 2 + 0x800000;
      uVar7 = param_1 * 2 + 0x800000;
      uVar4 = uVar5;
      if (uVar5 < 0xff800001) {
        uVar4 = uVar7;
      }
      if (0xff800000 < uVar4) {
        puVar1 = (uint *)__rt_fp_status_addr();
        uVar4 = *puVar1;
        *puVar1 = uVar4 | 1;
        if ((uVar4 & 0x100) == 0) {
          uVar4 = __fpl_return_NaN(DAT_300b8820 | param_2 & 0x80000000,param_1,param_2 & 0x80000000,
                                   uVar7);
          return uVar4;
        }
        uVar4 = _fp_trapveneer();
        return uVar4;
      }
      if (0x7fffff < uVar5) {
        param_2 = param_1;
      }
      uVar4 = __fpl_return_NaN(param_2);
      return uVar4;
    }
    if (uVar4 == param_1 * 2) {
      if (-1 < (int)(param_2 ^ param_1)) {
        uVar4 = __fpl_exception();
        return uVar4;
      }
      return param_2;
    }
    if (uVar4 != 0xff000000) {
      return param_1 ^ 0x80000000;
    }
    return param_2;
  }
  param_1 = param_1 ^ 0x80000000;
  if ((int)(param_1 ^ param_2) < 0) {
    param_2 = param_2 ^ 0x80000000;
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
 * _f_utof @ 0x300B9D74  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fflt_normalise
 * Константы: 0x300B9D74, 0x40000000
 * ---------------------------------------------------------------- */
void _f_utof(undefined4 param_1,undefined4 param_2)

{
  __fflt_normalise(param_1,param_2,0x40000000);
  return;
}

/* ----------------------------------------------------------------
 * _f_ulltof @ 0x300B9DB0  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300B9DB0, 0x00800000, 0x4E800000, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
uint _f_ulltof(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
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
    uVar2 = uVar1 << LZCOUNT(uVar1) | param_1 >> (uVar4 & 0xff);
    bVar5 = (bool)((byte)(uVar2 >> 7) & 1);
    uVar1 = uVar4 * 0x800000 + 0x4e800000 + (uVar2 >> 8) + (uint)bVar5;
    if (param_1 << (0x20 - uVar4 & 0xff) != 0 || (uVar2 & 0x7f) != 0) {
      bVar5 = false;
    }
    if (bVar5) {
      uVar1 = uVar1 & 0xfffffffe;
    }
    return uVar1;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * localeconv @ 0x300BA10C  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BA10C
 * Данные: DAT_300ba114
 * ---------------------------------------------------------------- */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lconv * localeconv(void)

{
  return DAT_300ba114;
}

/* ----------------------------------------------------------------
 * setlocale @ 0x300BA118  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: memcmp, strcmp
 * Константы: 0x300BA118
 * Данные: DAT_300ba16c, DAT_300ba170
 * ---------------------------------------------------------------- */
char * setlocale(int __category,char *__locale)

{
  int iVar1;
  
  if (((__locale != (char *)0x0) && (iVar1 = strcmp(__locale,(char *)*DAT_300ba16c), iVar1 != 0)) &&
     (iVar1 = memcmp(__locale,DAT_300ba170,1), iVar1 != 0)) {
    return (char *)0x0;
  }
  return (char *)*DAT_300ba16c;
}

/* ----------------------------------------------------------------
 * _setjmpSetup @ 0x300BA174  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: setjmp, sigsetjmp
 * Константы: 0x300BA174
 * Данные: DAT_300ba2d0, DAT_300ba2d4, DAT_300ba2d8
 * ---------------------------------------------------------------- */
void _setjmpSetup(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = *DAT_300ba2d0;
  puVar3 = (uint *)(param_1 + 0x5c);
  *(uint *)(param_1 + 0x5c) = uVar4;
  if (param_2 != 0) {
    if (*(int *)(uVar4 + 0x94) == *DAT_300ba2d4) {
      iVar1 = *(int *)(uVar4 + 0xd8);
      if (iVar1 != 0) {
        *puVar3 = uVar4 | 1;
        uVar2 = *(undefined4 *)(iVar1 + 0x618);
        *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(iVar1 + 0x614);
        *(undefined4 *)(param_1 + 0x58) = uVar2;
      }
    }
    else if (((code *)*DAT_300ba2d8 != (code *)0x0) &&
            (iVar1 = (*(code *)*DAT_300ba2d8)(1,0), iVar1 != -1)) {
      *puVar3 = *puVar3 | 1;
    }
  }
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(uVar4 + 0x6c);
  return;
}

/* ----------------------------------------------------------------
 * longjmp @ 0x300BA21C  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: _sigCtxLoad, _sigCtxRtnValSet, taskSuspend
 * Константы: 0x300BA21C, 0xFFFFFFFE
 * Данные: DAT_300ba2d0, DAT_300ba2dc, DAT_300ba2e0
 * ---------------------------------------------------------------- */
void longjmp(__jmp_buf_tag *__env,int __val)

{
  uint uVar1;
  
  uVar1 = *DAT_300ba2d0;
  if (((__env->__saved_mask).__val[0x10] & 0xfffffffe) != uVar1) {
    taskSuspend(0);
  }
  if ((code *)*DAT_300ba2dc != (code *)0x0) {
    (*(code *)*DAT_300ba2dc)((__env->__saved_mask).__val[6]);
  }
  if ((((__env->__saved_mask).__val[0x10] & 1) != 0) && ((code *)*DAT_300ba2e0 != (code *)0x0)) {
    (*(code *)*DAT_300ba2e0)(3,(__env->__saved_mask).__val + 0xe,0);
  }
  *(ulong *)(uVar1 + 0x6c) = (__env->__saved_mask).__val[0xb];
  if (__val == 0) {
    __val = 1;
  }
  _sigCtxRtnValSet(__env,__val);
  _sigCtxLoad(__env);
  return;
}

/* ----------------------------------------------------------------
 * clearerr @ 0x300BA2E4  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BA2E4
 * ---------------------------------------------------------------- */
void clearerr(FILE *__stream)

{
  if ((FILE *)__stream->_IO_read_ptr != __stream) {
    return;
  }
  if (*(char *)((int)&__stream->_IO_read_end + 2) != 'f') {
    return;
  }
  *(ushort *)&__stream->_IO_write_end = *(ushort *)&__stream->_IO_write_end & 0xff9f;
  return;
}

/* ----------------------------------------------------------------
 * fdopen @ 0x300BA3E4  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: __sflags, iosFdValue, stdioFpCreate
 * Вызывают: FUN_3008b498, FUN_3008b88c
 * Константы: 0x300BA3E4
 * ---------------------------------------------------------------- */
FILE * fdopen(int __fd,char *__modes)

{
  int iVar1;
  FILE *pFVar2;
  uint local_14;
  
  iVar1 = iosFdValue();
  if (iVar1 == -1) {
    pFVar2 = (FILE *)0x0;
  }
  else {
    iVar1 = __sflags(__modes,&local_14);
    if (iVar1 == 0) {
      pFVar2 = (FILE *)0x0;
    }
    else {
      pFVar2 = (FILE *)stdioFpCreate();
      if (pFVar2 == (FILE *)0x0) {
        pFVar2 = (FILE *)0x0;
      }
      else {
        *(ushort *)&pFVar2->_IO_write_end = (ushort)iVar1;
        if ((local_14 & 8) != 0) {
          *(ushort *)&pFVar2->_IO_write_end = (ushort)iVar1 | 0x100;
        }
        *(short *)((int)&pFVar2->_IO_write_end + 2) = (short)__fd;
      }
    }
  }
  return pFVar2;
}

/* ----------------------------------------------------------------
 * feof @ 0x300BA45C  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BA45C
 * ---------------------------------------------------------------- */
int feof(FILE *__stream)

{
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    return (uint)(((uint)__stream->_IO_write_end & 0x20) != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ferror @ 0x300BA494  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BA494
 * ---------------------------------------------------------------- */
int ferror(FILE *__stream)

{
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    return (uint)(((uint)__stream->_IO_write_end & 0x40) != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * fflush @ 0x300BA57C  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 11 | Вызывает: 2
 * Вызывает: __errno, __sflush
 * Вызывают: FUN_300f72a4, FUN_300f8b2c, FUN_3010c4f0, QC_gzflush, __sfvwrite, __swbuf, completionPathShow, completionSymShow, shellCompletionPathnameGet, shellInterpCparse
 *           ...
 * Константы: 0x300BA57C
 * ---------------------------------------------------------------- */
int fflush(FILE *__stream)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    if ((__stream == (FILE *)0x0) || (((uint)__stream->_IO_write_end & 8) == 0)) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = 9;
      iVar2 = -1;
    }
    else {
      iVar2 = __sflush();
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * fgetc @ 0x300BA5D4  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __srget
 * Константы: 0x300BA5D4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int fgetc(FILE *__stream)

{
  uint uVar1;
  char *pcVar2;
  
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    pcVar2 = __stream->_IO_write_base;
    __stream->_IO_write_base = pcVar2 + -1;
    if ((int)(pcVar2 + -1) < 0) {
      uVar1 = __srget();
    }
    else {
      uVar1 = (uint)(byte)*__stream->_IO_read_base;
      __stream->_IO_read_base = __stream->_IO_read_base + 1;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * fgetpos @ 0x300BA62C  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: ftell
 * Константы: 0x300BA62C
 * ---------------------------------------------------------------- */
int fgetpos(FILE *__stream,fpos_t *__pos)

{
  long lVar1;
  
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    lVar1 = ftell(__stream);
    __pos->__pos = lVar1;
    return (uint)(lVar1 == -1);
  }
  return -1;
}

/* ----------------------------------------------------------------
 * fileno @ 0x300BA788  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BA788
 * ---------------------------------------------------------------- */
int fileno(FILE *__stream)

{
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    return (int)*(short *)((int)&__stream->_IO_write_end + 2);
  }
  return -1;
}

/* ----------------------------------------------------------------
 * fputc @ 0x300BA960  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: __swbuf
 * Вызывают: FUN_3008caa0
 * Константы: 0x300BA960, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int fputc(int __c,FILE *__stream)

{
  char *pcVar1;
  uint uVar2;
  
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    pcVar1 = __stream->_IO_write_ptr + -1;
    __stream->_IO_write_ptr = pcVar1;
    if ((int)pcVar1 < 0) {
      if ((int)pcVar1 < (int)__stream->_IO_save_base) {
        uVar2 = __swbuf();
      }
      else {
        *__stream->_IO_read_base = (char)__c;
        if ((__c & 0xffU) == 10) {
          uVar2 = __swbuf(10);
        }
        else {
          uVar2 = (uint)(byte)*__stream->_IO_read_base;
          __stream->_IO_read_base = __stream->_IO_read_base + 1;
        }
      }
    }
    else {
      *__stream->_IO_read_base = (char)__c;
      uVar2 = (uint)(byte)*__stream->_IO_read_base;
      __stream->_IO_read_base = __stream->_IO_read_base + 1;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * freopen @ 0x300BAB50  (примерный размер ~480 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: __errno, __sclose, __sflags, __sflush, fclose, free, open, stdioFpDestroy
 * Константы: 0x300BAB50
 * Данные: DAT_300bad2c
 * ---------------------------------------------------------------- */
FILE * freopen(char *__filename,char *__modes,FILE *__stream)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  char *__ptr;
  bool bVar6;
  int local_20;
  
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    iVar1 = __sflags(__modes,&local_20);
    if (iVar1 != 0) {
      if (((uint)__stream->_IO_write_end & 8) != 0) {
        __sflush(__stream);
      }
      bVar6 = -1 < *(short *)((int)&__stream->_IO_write_end + 2);
      if (!bVar6) {
        __sclose(__stream);
      }
      uVar5 = DAT_300bad2c;
      iVar2 = open(__filename,local_20,DAT_300bad2c);
      if (((iVar2 < 0) && (bVar6)) &&
         ((piVar3 = (int *)__errno(), *piVar3 == 0x17 ||
          (piVar3 = (int *)__errno(), *piVar3 == 0x18)))) {
        __sclose(__stream);
        bVar6 = false;
        iVar2 = open(__filename,local_20,uVar5);
      }
      puVar4 = (undefined4 *)__errno();
      uVar5 = *puVar4;
      if (bVar6) {
        __sclose(__stream);
      }
      if (((uint)__stream->_IO_write_end & 0x80) != 0) {
        free(__stream->_IO_buf_base);
      }
      __stream->_IO_write_ptr = (char *)0x0;
      __stream->_IO_write_base = (char *)0x0;
      __stream->_IO_read_base = (char *)0x0;
      __stream->_IO_buf_base = (char *)0x0;
      __stream->_IO_buf_end = (char *)0x0;
      __stream->_IO_save_base = (char *)0x0;
      __ptr = __stream->_IO_backup_base;
      if (__ptr != (char *)0x0) {
        if (&__stream->_fileno != (int *)__ptr) {
          free(__ptr);
        }
        __stream->_IO_backup_base = (char *)0x0;
      }
      __stream->_IO_save_end = (char *)0x0;
      if ((void *)__stream->_flags2 != (void *)0x0) {
        free((void *)__stream->_flags2);
        __stream->_flags2 = 0;
      }
      __stream->_old_offset = 0;
      if ((iVar2 < 0) && (*(short *)&__stream->_IO_write_end != 0)) {
        *(undefined2 *)&__stream->_IO_write_end = 0;
        stdioFpDestroy(__stream);
        puVar4 = (undefined4 *)__errno();
        *puVar4 = uVar5;
        __stream = (FILE *)0x0;
      }
      else {
        *(short *)&__stream->_IO_write_end = (short)iVar1;
        *(short *)((int)&__stream->_IO_write_end + 2) = (short)iVar2;
      }
      return __stream;
    }
    fclose(__stream);
    return (FILE *)0x0;
  }
  return (FILE *)0x0;
}

/* ----------------------------------------------------------------
 * fseek @ 0x300BAD30  (примерный размер ~920 байт)
 * Модуль: data | Вызывают: 17 | Вызывает: 7
 * Вызывает: __errno, __sflush, __smakebuf, __srefill, __sseek, free, ioctl
 * Вызывают: BSP_fseek, DR_NV_File_Seek, FUN_3008b88c, QC_gzgetlength, QC_gzrewind, QC_gzseek, TFUP_GetUnitHeadData, TFUP_LogFsInit, TFUP_LogPrintf, TFUP_ReadDataFromTF
 *           ...
 * Константы: 0xFFFFFFFF, 0x300BAD30
 * Данные: DAT_300bb0c4
 * ---------------------------------------------------------------- */
int fseek(FILE *__stream,long __off,int __whence)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  char *pcVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  undefined1 auStack_64 [8];
  uint local_5c;
  int local_4c;
  undefined4 local_38;
  
  if (((FILE *)__stream->_IO_read_ptr != __stream) ||
     (*(char *)((int)&__stream->_IO_read_end + 2) != 'f')) {
    return -1;
  }
  if (__whence == 0) {
LAB_300bae04:
    puVar7 = (undefined1 *)0x0;
    iVar5 = 0;
  }
  else {
    if (__whence != 1) {
      if (__whence != 2) {
        puVar2 = (undefined4 *)__errno();
        *puVar2 = 0x16;
        return -1;
      }
      goto LAB_300bae04;
    }
    if (((uint)__stream->_IO_write_end & 0x1000) == 0) {
      puVar7 = (undefined1 *)__sseek(__stream,0,1);
      if (puVar7 == (undefined1 *)0xffffffff) {
        return -1;
      }
    }
    else {
      puVar7 = (undefined1 *)__stream->_lock;
    }
    if (((uint)__stream->_IO_write_end & 4) == 0) {
      if ((((uint)__stream->_IO_write_end & 8) != 0) && (__stream->_IO_read_base != (char *)0x0)) {
        puVar7 = puVar7 + ((int)__stream->_IO_read_base - (int)__stream->_IO_buf_base);
      }
    }
    else {
      puVar7 = puVar7 + -(int)__stream->_IO_write_base;
      if (__stream->_IO_backup_base != (char *)0x0) {
        puVar7 = puVar7 + -(int)__stream->_chain;
      }
    }
    __off = (long)(puVar7 + __off);
    __whence = 0;
    iVar5 = 1;
  }
  if (__stream->_IO_buf_base == (char *)0x0) {
    __smakebuf(__stream);
  }
  if (((int)*(short *)&__stream->_IO_write_end & DAT_300bb0c4) == 0) {
    puVar3 = (undefined1 *)ioctl((int)*(short *)((int)&__stream->_IO_write_end + 2),0x40,auStack_64)
    ;
    uVar1 = *(ushort *)&__stream->_IO_write_end;
    if ((uVar1 & 0x400) == 0) {
      if (((*(short *)((int)&__stream->_IO_write_end + 2) < 0) || (puVar3 != (undefined1 *)0x0)) ||
         ((local_5c & 0xf000) != 0x8000)) {
        *(ushort *)&__stream->_IO_write_end = uVar1 | 0x800;
        goto LAB_300bb044;
      }
      __stream->_cur_column = (undefined2)local_38;
      __stream->_vtable_offset = local_38._2_1_;
      __stream->_shortbuf[0] = local_38._3_1_;
      *(ushort *)&__stream->_IO_write_end = uVar1 | 0x400;
    }
    puVar4 = (undefined1 *)__off;
    if (__whence != 0) {
      if (puVar3 != (undefined1 *)0x0) goto LAB_300bb044;
      puVar4 = (undefined1 *)(__off + local_4c);
    }
    if (iVar5 == 0) {
      if (((uint)__stream->_IO_write_end & 0x1000) == 0) {
        puVar3 = (undefined1 *)__sseek(__stream,0,1);
        puVar7 = puVar3;
        if (puVar3 == (undefined1 *)0xffffffff) goto LAB_300bb044;
      }
      else {
        puVar7 = (undefined1 *)__stream->_lock;
      }
      bVar11 = __stream->_IO_backup_base == (char *)0x0;
      puVar7 = puVar7 + -(int)__stream->_IO_write_base;
      if (!bVar11) {
        puVar7 = puVar7 + -(int)__stream->_chain;
        goto LAB_300baf10;
      }
    }
    else {
LAB_300baf10:
      bVar11 = __stream->_IO_backup_base == (char *)0x0;
      if (!bVar11) {
        puVar3 = (undefined1 *)0x34;
        iVar5 = (int)__stream->_markers - (int)__stream->_IO_buf_base;
      }
    }
    if (bVar11) {
      puVar3 = &DataAbort;
      iVar5 = (int)__stream->_IO_read_base - (int)__stream->_IO_buf_base;
    }
    iVar10 = *(int *)(puVar3 + (int)(__stream->_shortbuf + -0x47));
    iVar8 = (int)puVar7 - iVar5;
    if (((((uint)__stream->_IO_write_end & 0x2000) == 0) && (iVar8 <= (int)puVar4)) &&
       (puVar4 < (undefined1 *)(iVar8 + iVar5 + iVar10))) {
      __stream->_IO_read_base = __stream->_IO_buf_base + ((int)puVar4 - iVar8);
      __stream->_IO_write_base = (char *)((iVar5 + iVar10) - ((int)puVar4 - iVar8));
      pcVar6 = __stream->_IO_backup_base;
      if (pcVar6 != (char *)0x0) {
        if (&__stream->_fileno != (int *)pcVar6) {
          free(pcVar6);
        }
        __stream->_IO_backup_base = (char *)0x0;
      }
      goto LAB_300bb0ac;
    }
    uVar9 = (uint)puVar4 & ~(*(int *)&__stream->_cur_column - 1U);
    iVar5 = __sseek(__stream,uVar9,0);
    if (iVar5 != -1) {
      __stream->_IO_write_base = (char *)0x0;
      pcVar6 = __stream->_IO_backup_base;
      if (pcVar6 != (char *)0x0) {
        if (&__stream->_fileno != (int *)pcVar6) {
          free(pcVar6);
        }
        __stream->_IO_backup_base = (char *)0x0;
      }
      *(ushort *)&__stream->_IO_write_end = *(ushort *)&__stream->_IO_write_end & 0xffdf;
      pcVar6 = puVar4 + -uVar9;
      if (pcVar6 == (char *)0x0) {
        return 0;
      }
      iVar5 = __srefill(__stream);
      if ((iVar5 == 0) && (pcVar6 <= __stream->_IO_write_base)) {
        __stream->_IO_read_base = __stream->_IO_read_base + (int)pcVar6;
        __stream->_IO_write_base = __stream->_IO_write_base + -(int)pcVar6;
        return 0;
      }
    }
  }
LAB_300bb044:
  iVar5 = __sflush(__stream);
  if ((iVar5 != 0) || (iVar5 = __sseek(__stream,__off,__whence), iVar5 == -1)) {
    return -1;
  }
  pcVar6 = __stream->_IO_backup_base;
  if (pcVar6 != (char *)0x0) {
    if (&__stream->_fileno != (int *)pcVar6) {
      free(pcVar6);
    }
    __stream->_IO_backup_base = (char *)0x0;
  }
  __stream->_IO_read_base = __stream->_IO_buf_base;
  __stream->_IO_write_base = (char *)0x0;
LAB_300bb0ac:
  *(ushort *)&__stream->_IO_write_end = *(ushort *)&__stream->_IO_write_end & 0xffdf;
  return 0;
}

/* ----------------------------------------------------------------
 * fsetpos @ 0x300BB0C8  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: fseek
 * Константы: 0x300BB0C8
 * ---------------------------------------------------------------- */
int fsetpos(FILE *__stream,fpos_t *__pos)

{
  int iVar1;
  
  iVar1 = fseek(__stream,__pos->__pos,0);
  return iVar1;
}

/* ----------------------------------------------------------------
 * ftell @ 0x300BB0D4  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 13 | Вызывает: 1
 * Вызывает: __sseek
 * Вызывают: BSP_ftell, FUN_3008b498, FUN_3008b88c, HI6451_record_startflag_save, TFUP_GetUnitHeadData, TFUP_LogFsInit, TFUP_LogPrintf, TFUP_ValidateCRCWithLic, dloadFromFsGetUnitHeadData, dloadRecord
 *           ...
 * Константы: 0x300BB0D4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
long ftell(FILE *__stream)

{
  _IO_lock_t *p_Var1;
  int iVar2;
  
  if (((FILE *)__stream->_IO_read_ptr != __stream) ||
     (*(char *)((int)&__stream->_IO_read_end + 2) != 'f')) {
    return -1;
  }
  if (((uint)__stream->_IO_write_end & 0x1000) == 0) {
    p_Var1 = (_IO_lock_t *)__sseek(__stream,0,1);
    if (p_Var1 == (_IO_lock_t *)0xffffffff) {
      return -1;
    }
  }
  else {
    p_Var1 = __stream->_lock;
  }
  if (((uint)__stream->_IO_write_end & 4) != 0) {
    iVar2 = (int)p_Var1 - (int)__stream->_IO_write_base;
    if (__stream->_IO_backup_base == (char *)0x0) {
      return iVar2;
    }
    return iVar2 - (int)__stream->_chain;
  }
  if (((uint)__stream->_IO_write_end & 8) == 0) {
    return (long)p_Var1;
  }
  if (__stream->_IO_read_base == (char *)0x0) {
    return (long)p_Var1;
  }
  return (int)p_Var1 + ((int)__stream->_IO_read_base - (int)__stream->_IO_buf_base);
}

/* ----------------------------------------------------------------
 * getc @ 0x300BB540  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __srget
 * Константы: 0x300BB540, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int getc(FILE *__stream)

{
  uint uVar1;
  char *pcVar2;
  
  if (((FILE *)__stream->_IO_read_ptr != __stream) ||
     (*(char *)((int)&__stream->_IO_read_end + 2) != 'f')) {
    return -1;
  }
  pcVar2 = __stream->_IO_write_base;
  __stream->_IO_write_base = pcVar2 + -1;
  if ((int)(pcVar2 + -1) < 0) {
    uVar1 = __srget(__stream);
  }
  else {
    uVar1 = (uint)(byte)*__stream->_IO_read_base;
    __stream->_IO_read_base = __stream->_IO_read_base + 1;
  }
  if (uVar1 != 0xffffffff) {
    return uVar1;
  }
  *(ushort *)&__stream->_IO_write_end = *(ushort *)&__stream->_IO_write_end | 0x20;
  return -1;
}

/* ----------------------------------------------------------------
 * getchar @ 0x300BB5B0  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __srget, __stdin
 * Константы: 0x300BB5B0
 * ---------------------------------------------------------------- */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getchar(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *pbVar4;
  
  piVar1 = (int *)__stdin();
  iVar3 = *(int *)(*piVar1 + 4);
  piVar1 = (int *)__stdin();
  if ((*piVar1 == iVar3) && (piVar1 = (int *)__stdin(), *(char *)(*piVar1 + 10) == 'f')) {
    piVar1 = (int *)__stdin();
    iVar3 = *(int *)(*piVar1 + 0x10) + -1;
    *(int *)(*piVar1 + 0x10) = iVar3;
    if (iVar3 < 0) {
      puVar2 = (undefined4 *)__stdin();
      iVar3 = __srget(*puVar2);
      return iVar3;
    }
    piVar1 = (int *)__stdin();
    pbVar4 = *(byte **)(*piVar1 + 0xc);
    *(byte **)(*piVar1 + 0xc) = pbVar4 + 1;
    return (uint)*pbVar4;
  }
  return -1;
}

/* ----------------------------------------------------------------
 * getw @ 0x300BB718  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: fread
 * Константы: 0x300BB718
 * ---------------------------------------------------------------- */
int getw(FILE *__stream)

{
  size_t sVar1;
  int aiStack_8 [2];
  
  sVar1 = fread(aiStack_8,4,1,__stream);
  if (sVar1 != 1) {
    aiStack_8[0] = -1;
  }
  return aiStack_8[0];
}

/* ----------------------------------------------------------------
 * perror @ 0x300BB874  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 4
 * Вызывает: __errno, __stderr, fprintf, strerror
 * Вызывают: FUN_3011a5a0, attrib, chkdsk, cp, mv, xattrib, xcopy, xdelete
 * Константы: 0x300BB874
 * Данные: DAT_300bb8cc, DAT_300bb8d0
 * ---------------------------------------------------------------- */
void perror(char *__s)

{
  undefined4 *puVar1;
  int *piVar2;
  char *pcVar3;
  
  if ((__s != (char *)0x0) && (*__s != '\0')) {
    puVar1 = (undefined4 *)__stderr();
    fprintf((FILE *)*puVar1,DAT_300bb8cc,__s);
  }
  piVar2 = (int *)__errno();
  pcVar3 = strerror(*piVar2);
  puVar1 = (undefined4 *)__stderr();
  fprintf((FILE *)*puVar1,DAT_300bb8d0,pcVar3);
  return;
}

/* ----------------------------------------------------------------
 * putc @ 0x300BB8D4  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __swbuf
 * Константы: 0x300BB8D4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int putc(int __c,FILE *__stream)

{
  char *pcVar1;
  uint uVar2;
  
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    pcVar1 = __stream->_IO_write_ptr + -1;
    __stream->_IO_write_ptr = pcVar1;
    if ((int)pcVar1 < 0) {
      if ((int)pcVar1 < (int)__stream->_IO_save_base) {
        uVar2 = __swbuf();
      }
      else {
        *__stream->_IO_read_base = (char)__c;
        if ((__c & 0xffU) == 10) {
          uVar2 = __swbuf(10);
        }
        else {
          uVar2 = (uint)(byte)*__stream->_IO_read_base;
          __stream->_IO_read_base = __stream->_IO_read_base + 1;
        }
      }
    }
    else {
      *__stream->_IO_read_base = (char)__c;
      uVar2 = (uint)(byte)*__stream->_IO_read_base;
      __stream->_IO_read_base = __stream->_IO_read_base + 1;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * putw @ 0x300BBAB4  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: fwrite
 * Константы: 0x300BBAB4
 * ---------------------------------------------------------------- */
int putw(int __w,FILE *__stream)

{
  size_t sVar1;
  int local_4;
  
  local_4 = __w;
  sVar1 = fwrite(&local_4,4,1,__stream);
  if (sVar1 != 1) {
    local_4 = -1;
  }
  return local_4;
}

/* ----------------------------------------------------------------
 * rewind @ 0x300BBCCC  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: fseek
 * Вызывают: TFUP_ValidateCRCWithLic
 * Константы: 0x300BBCCC
 * ---------------------------------------------------------------- */
void rewind(FILE *__stream)

{
  if ((FILE *)__stream->_IO_read_ptr != __stream) {
    return;
  }
  if (*(char *)((int)&__stream->_IO_read_end + 2) != 'f') {
    return;
  }
  fseek(__stream,0,0);
  if ((FILE *)__stream->_IO_read_ptr != __stream) {
    return;
  }
  if (*(char *)((int)&__stream->_IO_read_end + 2) != 'f') {
    return;
  }
  *(ushort *)&__stream->_IO_write_end = *(ushort *)&__stream->_IO_write_end & 0xff9f;
  return;
}

/* ----------------------------------------------------------------
 * setbuf @ 0x300BBD60  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: setvbuf
 * Константы: 0x300BBD60
 * ---------------------------------------------------------------- */
void setbuf(FILE *__stream,char *__buf)

{
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    setvbuf(__stream,__buf,(uint)(__buf == (char *)0x0) << 1,0x400);
  }
  return;
}

/* ----------------------------------------------------------------
 * setbuffer @ 0x300BBD98  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: setvbuf
 * Константы: 0x300BBD98
 * ---------------------------------------------------------------- */
void setbuffer(FILE *__stream,char *__buf,size_t __size)

{
  if ((FILE *)__stream->_IO_read_ptr != __stream) {
    return;
  }
  if (*(char *)((int)&__stream->_IO_read_end + 2) == 'f') {
    setvbuf(__stream,__buf,(uint)(__buf == (char *)0x0) << 1,__size);
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * setlinebuf @ 0x300BBDD4  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: setvbuf
 * Константы: 0x300BBDD4
 * ---------------------------------------------------------------- */
void setlinebuf(FILE *__stream)

{
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    setvbuf(__stream,(char *)0x0,1,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * setvbuf @ 0x300BBE10  (примерный размер ~268 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: __sflush, free
 * Вызывают: setbuf, setbuffer, setlinebuf
 * Константы: 0x300BBE10
 * ---------------------------------------------------------------- */
int setvbuf(FILE *__stream,char *__buf,int __modes,size_t __n)

{
  ushort uVar1;
  char *pcVar2;
  
  if (((FILE *)__stream->_IO_read_ptr != __stream) ||
     (*(char *)((int)&__stream->_IO_read_end + 2) != 'f')) {
    return -1;
  }
  if ((((__modes != 0) && (__modes != 1)) && (__modes != 2)) || ((int)__n < 0)) {
    return -1;
  }
  __sflush(__stream);
  __stream->_IO_write_base = (char *)0x0;
  __stream->_IO_save_base = (char *)0x0;
  if (((uint)__stream->_IO_write_end & 0x80) != 0) {
    free(__stream->_IO_buf_base);
  }
  uVar1 = *(ushort *)&__stream->_IO_write_end & 0xff7c;
  *(ushort *)&__stream->_IO_write_end = uVar1;
  if (__modes == 0) {
LAB_300bbeec:
    __stream->_IO_read_base = __buf;
    __stream->_IO_buf_base = __buf;
    pcVar2 = (char *)__n;
  }
  else {
    if (__modes == 1) {
      *(ushort *)&__stream->_IO_write_end = uVar1 | 1;
      __stream->_IO_save_base = (char *)-__n;
      goto LAB_300bbeec;
    }
    if (__modes != 2) goto LAB_300bbefc;
    *(ushort *)&__stream->_IO_write_end = uVar1 | 2;
    pcVar2 = (char *)((int)&__stream->_fileno + 3);
    __stream->_IO_read_base = pcVar2;
    __stream->_IO_buf_base = pcVar2;
    pcVar2 = (char *)0x1;
  }
  __stream->_IO_buf_end = pcVar2;
LAB_300bbefc:
  if (((uint)__stream->_IO_write_end & 8) != 0) {
    if (((uint)__stream->_IO_write_end & 3) != 0) {
      __n = 0;
    }
    __stream->_IO_write_ptr = (char *)__n;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * stdioInit @ 0x300BC01C  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: stdioFpCreate, usrIosExtraInit
 * Константы: 0x300BC01C
 * Данные: DAT_300bc2dc, DAT_300bc2e0, DAT_300bc2e4
 * ---------------------------------------------------------------- */
undefined4 stdioInit(void)

{
  int *piVar1;
  
  piVar1 = DAT_300bc2dc;
  if (*DAT_300bc2dc == 0) {
    *DAT_300bc2e4 = DAT_300bc2e0;
    *piVar1 = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * stdioFpCreate @ 0x300BC050  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: handleInit, malloc, stdioInit
 * Вызывают: FUN_300bc1cc, fdopen, fopen
 * Константы: 0x300BC050
 * Данные: DAT_300bc2e8
 * ---------------------------------------------------------------- */
void * stdioFpCreate(void)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = (void *)0x0;
  iVar1 = stdioInit();
  if ((iVar1 == 0) && (pvVar2 = malloc(0x50), pvVar2 != (void *)0x0)) {
    *(undefined4 *)((int)pvVar2 + 0xc) = 0;
    *(undefined4 *)((int)pvVar2 + 0x10) = 0;
    *(undefined4 *)((int)pvVar2 + 0x14) = 0;
    *(undefined2 *)((int)pvVar2 + 0x18) = 1;
    *(undefined2 *)((int)pvVar2 + 0x1a) = 0xffff;
    *(undefined4 *)((int)pvVar2 + 0x1c) = 0;
    *(undefined4 *)((int)pvVar2 + 0x20) = 0;
    *(undefined4 *)((int)pvVar2 + 0x24) = 0;
    *(undefined4 *)((int)pvVar2 + 0x28) = 0;
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
    *(undefined4 *)((int)pvVar2 + 0x3c) = 0;
    *(undefined4 *)((int)pvVar2 + 0x40) = 0;
    *(undefined4 *)((int)pvVar2 + 0x44) = 0;
    *(undefined4 *)((int)pvVar2 + 0x48) = 0;
    *(undefined4 *)((int)pvVar2 + 0x4c) = *DAT_300bc2e8;
    handleInit(pvVar2,0x66);
  }
  return pvVar2;
}

/* ----------------------------------------------------------------
 * stdioFpDestroy @ 0x300BC0DC  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: free, handleTerminate
 * Вызывают: fclose, fopen, freopen
 * Константы: 0x300BC0DC, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 stdioFpDestroy(void *param_1)

{
  if ((*(void **)((int)param_1 + 4) == param_1) && (*(char *)((int)param_1 + 10) == 'f')) {
    handleTerminate();
    free(param_1);
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300bc118 @ 0x300BC118  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: fclose
 * Константы: 0x300BC118
 * ---------------------------------------------------------------- */
void FUN_300bc118(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 0xf0);
  iVar2 = 3;
  do {
    puVar1 = puVar1 + 1;
    if ((FILE *)*puVar1 != (FILE *)0x0) {
      fclose((FILE *)*puVar1);
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* ----------------------------------------------------------------
 * stdioFp @ 0x300BC2A8  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300bc1cc
 * Константы: 0x300BC2A8
 * Данные: DAT_300bc2e8
 * ---------------------------------------------------------------- */
undefined4 stdioFp(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_300bc2e8;
  if (*(int *)(*DAT_300bc2e8 + param_1 * 4 + 0xf4) == 0) {
    FUN_300bc1cc();
  }
  return *(undefined4 *)(*piVar1 + param_1 * 4 + 0xf4);
}

/* ----------------------------------------------------------------
 * tmpnam @ 0x300BC2F4  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: strlen
 * Константы: 0x300BC2F4
 * Данные: DAT_300bc388, DAT_300bc38c, DAT_300bc390
 * ---------------------------------------------------------------- */
char * tmpnam(char *__s)

{
  char *pcVar1;
  size_t sVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  if (__s == (char *)0x0) {
    __s = DAT_300bc388;
  }
  iVar5 = 4;
  pcVar1 = __s;
  pcVar3 = DAT_300bc38c;
  do {
    iVar5 = iVar5 + -1;
    *pcVar1 = *pcVar3;
    pcVar1 = pcVar1 + 1;
    pcVar3 = pcVar3 + 1;
  } while (iVar5 != 0);
  sVar2 = strlen(__s);
  pcVar1 = __s + sVar2 + 5;
  *pcVar1 = '\0';
  uVar4 = *DAT_300bc390 + 1;
  *DAT_300bc390 = (ushort)uVar4;
  iVar5 = 4;
  do {
    iVar5 = iVar5 + -1;
    pcVar1 = pcVar1 + -1;
    *pcVar1 = ((byte)uVar4 & 7) + 0x30;
    uVar4 = (uVar4 << 0x10) >> 0x13;
  } while (-1 < iVar5);
  return __s;
}

/* ----------------------------------------------------------------
 * tmpfile @ 0x300BC394  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BC394
 * ---------------------------------------------------------------- */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * tmpfile(void)

{
  return (FILE *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_300bc39c @ 0x300BC39C  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: bcopy, malloc, realloc
 * Вызывают: ungetc
 * Константы: 0xFFFFFFFF, 0x300BC39C
 * Данные: DAT_300bc5c0
 * ---------------------------------------------------------------- */
undefined4 FUN_300bc39c(int param_1)

{
  void *pvVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  size_t __n;
  
  if ((void *)(param_1 + 0x38) == *(void **)(param_1 + 0x28)) {
    pvVar1 = malloc(0x400);
    if (pvVar1 == (void *)0x0) {
      return 0xffffffff;
    }
    *(void **)(param_1 + 0x28) = pvVar1;
    *(undefined4 *)(param_1 + 0x2c) = 0x400;
    puVar4 = (undefined1 *)(param_1 + 0x3b);
    iVar3 = 2;
    iVar5 = (int)pvVar1 + DAT_300bc5c0;
    puVar2 = (undefined1 *)(iVar5 + 3);
    do {
      puVar4 = puVar4 + -1;
      iVar3 = iVar3 + -1;
      puVar2 = puVar2 + -1;
      *puVar2 = *puVar4;
    } while (-1 < iVar3);
    *(int *)(param_1 + 0xc) = iVar5;
  }
  else {
    __n = *(size_t *)(param_1 + 0x2c);
    pvVar1 = realloc(*(void **)(param_1 + 0x28),__n << 1);
    if (pvVar1 == (void *)0x0) {
      return 0xffffffff;
    }
    bcopy(pvVar1,(void *)((int)pvVar1 + __n),__n);
    *(size_t *)(param_1 + 0xc) = (int)pvVar1 + __n;
    *(void **)(param_1 + 0x28) = pvVar1;
    *(size_t *)(param_1 + 0x2c) = __n << 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ungetc @ 0x300BC464  (примерный размер ~352 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: FUN_300bc39c, __sflush
 * Вызывают: fscanf, scanf
 * Константы: 0x300BC464
 * ---------------------------------------------------------------- */
int ungetc(int __c,FILE *__stream)

{
  int iVar1;
  char *pcVar2;
  
  if (((FILE *)__stream->_IO_read_ptr != __stream) ||
     (*(char *)((int)&__stream->_IO_read_end + 2) != 'f')) {
    return -1;
  }
  if (__c == -1) {
    return -1;
  }
  pcVar2 = __stream->_IO_write_end;
  if (((uint)pcVar2 & 4) == 0) {
    if (((uint)pcVar2 & 0x10) == 0) {
      return -1;
    }
    if (((uint)pcVar2 & 8) != 0) {
      iVar1 = __sflush(__stream);
      if (iVar1 != 0) {
        return -1;
      }
      *(ushort *)&__stream->_IO_write_end = *(ushort *)&__stream->_IO_write_end & 0xfff7;
      __stream->_IO_write_ptr = (char *)0x0;
      __stream->_IO_save_base = (char *)0x0;
    }
    *(ushort *)&__stream->_IO_write_end = *(ushort *)&__stream->_IO_write_end | 4;
  }
  if (__stream->_IO_backup_base == (char *)0x0) {
    if (((__stream->_IO_buf_base == (char *)0x0) ||
        (pcVar2 = __stream->_IO_read_base, pcVar2 <= __stream->_IO_buf_base)) ||
       ((uint)(byte)pcVar2[-1] != (__c & 0xffU))) {
      __stream->_chain = (_IO_FILE *)__stream->_IO_write_base;
      __stream->_markers = (_IO_marker *)__stream->_IO_read_base;
      __stream->_IO_backup_base = (char *)&__stream->_fileno;
      __stream->_IO_save_end = (char *)0x3;
      *(char *)((int)&__stream->_fileno + 2) = (char)__c;
      __stream->_IO_read_base = (char *)((int)&__stream->_fileno + 2);
      pcVar2 = (char *)0x1;
      goto LAB_300bc5b4;
    }
    __stream->_IO_read_base = pcVar2 + -1;
  }
  else {
    if (((int)__stream->_IO_save_end <= (int)__stream->_IO_write_base) &&
       (iVar1 = FUN_300bc39c(__stream), iVar1 != 0)) {
      return -1;
    }
    pcVar2 = __stream->_IO_read_base;
    __stream->_IO_read_base = pcVar2 + -1;
    pcVar2[-1] = (char)__c;
  }
  pcVar2 = __stream->_IO_write_base + 1;
LAB_300bc5b4:
  __stream->_IO_write_base = pcVar2;
  return __c & 0xffU;
}

/* ----------------------------------------------------------------
 * vfprintf @ 0x300BC768  (примерный размер ~388 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 5
 * Вызывает: __swsetup, fflush, fioFormatV, handleInit, handleTerminate
 * Вызывают: TFUP_LogPrintf, fprintf
 * Константы: 0x300BC768
 * Данные: DAT_300bc9ac
 * ---------------------------------------------------------------- */
int vfprintf(FILE *__s,char *__format,__gnuc_va_list __arg)

{
  int iVar1;
  int iVar2;
  FILE aFStack_464 [7];
  
  if (((FILE *)__s->_IO_read_ptr == __s) && (*(char *)((int)&__s->_IO_read_end + 2) == 'f')) {
    if (((((uint)__s->_IO_write_end & 8) == 0) || (__s->_IO_buf_base == (char *)0x0)) &&
       (iVar1 = __swsetup(__s), iVar1 != 0)) {
      iVar1 = -1;
    }
    else if (((*(ushort *)&__s->_IO_write_end & 0x1a) == 10) &&
            (-1 < *(short *)((int)&__s->_IO_write_end + 2))) {
      aFStack_464[0]._IO_write_end._0_2_ = *(ushort *)&__s->_IO_write_end & 0xfffd;
      aFStack_464[0]._IO_write_end._2_2_ = *(undefined2 *)((int)&__s->_IO_write_end + 2);
      aFStack_464[0]._IO_read_base = (char *)&aFStack_464[0]._offset;
      aFStack_464[0]._IO_write_ptr = (char *)0x400;
      aFStack_464[0]._IO_buf_end = (char *)0x400;
      aFStack_464[0]._IO_save_base = (char *)0x0;
      aFStack_464[0]._IO_write_base = (char *)0x0;
      aFStack_464[0]._IO_backup_base = (char *)0x0;
      aFStack_464[0]._IO_save_end = (char *)0x0;
      aFStack_464[0]._flags2 = 0;
      aFStack_464[0]._old_offset = 0;
      aFStack_464[0]._IO_buf_base = aFStack_464[0]._IO_read_base;
      handleInit(aFStack_464,0x66);
      iVar1 = fioFormatV(__format,__arg,DAT_300bc9ac,aFStack_464);
      if ((-1 < iVar1) && (iVar2 = fflush(aFStack_464), iVar2 != 0)) {
        iVar1 = -1;
      }
      if (((ushort)aFStack_464[0]._IO_write_end & 0x40) != 0) {
        *(ushort *)&__s->_IO_write_end = *(ushort *)&__s->_IO_write_end | 0x40;
      }
      handleTerminate(aFStack_464);
    }
    else {
      iVar1 = fioFormatV(__format,__arg,DAT_300bc9ac,__s);
      if (((FILE *)__s->_IO_read_ptr == __s) &&
         ((*(char *)((int)&__s->_IO_read_end + 2) == 'f' && (((uint)__s->_IO_write_end & 0x40) != 0)
          ))) {
        iVar1 = -1;
      }
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300bc8ec @ 0x300BC8EC  (примерный размер ~196 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __swbuf
 * Константы: 0x300BC8EC
 * ---------------------------------------------------------------- */
undefined4 FUN_300bc8ec(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_2) {
    do {
      if ((*(int *)(param_3 + 4) == param_3) && (*(char *)(param_3 + 10) == 'f')) {
        iVar2 = *(int *)(param_3 + 0x14) + -1;
        *(int *)(param_3 + 0x14) = iVar2;
        if (iVar2 < 0) {
          if (iVar2 < *(int *)(param_3 + 0x24)) {
            __swbuf(*(undefined1 *)(param_1 + iVar3),param_3);
          }
          else {
            cVar1 = *(char *)(param_1 + iVar3);
            **(char **)(param_3 + 0xc) = cVar1;
            if (cVar1 != '\n') {
              iVar2 = *(int *)(param_3 + 0xc);
              goto LAB_300bc990;
            }
            __swbuf(10,param_3);
          }
        }
        else {
          **(undefined1 **)(param_3 + 0xc) = *(undefined1 *)(param_1 + iVar3);
          iVar2 = *(int *)(param_3 + 0xc);
LAB_300bc990:
          *(int *)(param_3 + 0xc) = iVar2 + 1;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * fscanf @ 0x300BC9F0  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: fioScanV, ungetc
 * Константы: 0x300BC9F0
 * Данные: DAT_300bca70
 * ---------------------------------------------------------------- */
int fscanf(FILE *__stream,char *__format,...)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  int local_24;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (((FILE *)__stream->_IO_read_ptr == __stream) &&
     (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
    uStack_8 = in_r2;
    uStack_4 = in_r3;
    iVar1 = fioScanV(__format,DAT_300bca70,__stream,&local_24,&uStack_8);
    if (local_24 != -1) {
      ungetc(local_24,__stream);
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * scanf @ 0x300BCA74  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: __stdin, fioScanV, ungetc
 * Константы: 0x300BCA74
 * Данные: DAT_300bcad4
 * ---------------------------------------------------------------- */
int scanf(char *__format,...)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  int local_20;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = in_r1;
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  puVar1 = (undefined4 *)__stdin();
  iVar2 = fioScanV(__format,DAT_300bcad4,*puVar1,&local_20,&uStack_c);
  if (local_20 != -1) {
    puVar1 = (undefined4 *)__stdin();
    ungetc(local_20,(FILE *)*puVar1);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * abort @ 0x300BCAD8  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: exit, raise
 * Вызывают: __assert
 * Константы: 0x300BCAD8
 * ---------------------------------------------------------------- */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  raise(6);
  exit(1);
  return;
}

/* ----------------------------------------------------------------
 * atexit @ 0x300BCB00  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BCB00
 * ---------------------------------------------------------------- */
int atexit(__func *__func)

{
  return -1;
}

/* ----------------------------------------------------------------
 * mblen @ 0x300BCCAC  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: strcmp
 * Константы: 0x300BCCAC
 * ---------------------------------------------------------------- */
int mblen(char *__s,size_t __n)

{
  int iVar1;
  
  iVar1 = strcmp(__s,(char *)0x0);
  if (((iVar1 == 0) && (__n == 0)) && (*__s == '\0')) {
    return -1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * mbtowc @ 0x300BCCEC  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: strcmp
 * Константы: 0x300BCCEC
 * ---------------------------------------------------------------- */
int mbtowc(wchar_t *__pwc,char *__s,size_t __n)

{
  int iVar1;
  
  iVar1 = strcmp(__s,(char *)0x0);
  if (((iVar1 == 0) && (__n == 0)) && (*__s == '\0')) {
    return -1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * wctomb @ 0x300BCD30  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: strcmp
 * Константы: 0x300BCD30
 * ---------------------------------------------------------------- */
int wctomb(char *__s,wchar_t __wchar)

{
  int iVar1;
  
  iVar1 = strcmp(__s,(char *)0x0);
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * mbstowcs @ 0x300BCD4C  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: strcmp
 * Константы: 0x300BCD4C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
size_t mbstowcs(wchar_t *__pwcs,char *__s,size_t __n)

{
  int iVar1;
  
  iVar1 = strcmp(__s,(char *)0x0);
  if (((iVar1 == 0) && (__n == 0)) && (*__s == '\0')) {
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * wcstombs @ 0x300BCD90  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BCD90, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
size_t wcstombs(char *__s,wchar_t *__pwcs,size_t __n)

{
  if (((__pwcs != (wchar_t *)0x0) && (__n != 0)) && ((short)*__pwcs != 0)) {
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300bcdbc @ 0x300BCDBC  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300bce74, qsort
 * Константы: 0x300BCDBC
 * ---------------------------------------------------------------- */
void FUN_300bcdbc(undefined1 *param_1,int param_2,int param_3,code *param_4)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  
  puVar7 = param_1 + param_3;
  do {
    puVar6 = puVar7;
    if (param_1 + param_2 * param_3 <= puVar7) {
      return;
    }
    do {
      puVar6 = puVar6 + -param_3;
      if (puVar6 < param_1) break;
      iVar3 = (*param_4)(puVar7,puVar6);
    } while (iVar3 < 0);
    if (puVar6 + param_3 == puVar7) {
      puVar7 = puVar7 + param_3;
    }
    else {
      iVar3 = param_3;
      if (param_3 != 0) {
        do {
          uVar1 = *puVar7;
          puVar2 = puVar7 + -param_3;
          puVar5 = puVar7;
          while (puVar4 = puVar2, puVar6 + param_3 <= puVar4) {
            *puVar5 = *puVar4;
            puVar5 = puVar4;
            puVar2 = puVar4 + -param_3;
          }
          *puVar5 = uVar1;
          puVar7 = puVar7 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300bce74 @ 0x300BCE74  (примерный размер ~1012 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300bcdbc, __div32
 * Вызывают: qsort
 * Константы: 0x300BCE74
 * ---------------------------------------------------------------- */
void FUN_300bce74(undefined1 *param_1,int param_2,int param_3,code *param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  bool bVar13;
  
LAB_300bce8c:
  do {
    puVar10 = param_1 + param_3 * (param_2 >> 1);
    puVar8 = param_1 + param_3 * (param_2 + -1);
    if (5 < param_2) {
      iVar2 = (*param_4)(param_1,puVar10);
      iVar3 = (*param_4)(puVar10,puVar8);
      puVar7 = puVar10;
      if (iVar2 < 0) {
        if ((0 < iVar3) && (iVar2 = (*param_4)(param_1,puVar8), puVar7 = param_1, iVar2 < 0)) {
LAB_300bcf30:
          puVar7 = puVar8;
        }
      }
      else if (((0 < iVar2) && (iVar3 < 0)) &&
              (iVar2 = (*param_4)(param_1,puVar8), puVar7 = param_1, 0 < iVar2)) goto LAB_300bcf30;
      iVar2 = param_3;
      if (puVar7 != puVar10) {
        do {
          uVar1 = *puVar7;
          iVar2 = iVar2 + -1;
          *puVar7 = *puVar10;
          puVar7 = puVar7 + 1;
          puVar11 = puVar10 + 1;
          *puVar10 = uVar1;
          puVar10 = puVar11;
        } while (iVar2 != 0);
        puVar10 = puVar11 + -param_3;
      }
    }
    bVar13 = false;
    puVar7 = param_1;
    while( true ) {
      while ((puVar11 = puVar8, puVar7 < puVar10 && (iVar2 = (*param_4)(puVar7,puVar10), iVar2 < 1))
            ) {
        puVar7 = puVar7 + param_3;
      }
      for (; iVar2 = param_3, puVar9 = puVar7, puVar10 < puVar11; puVar11 = puVar11 + -param_3) {
        iVar3 = (*param_4)(puVar10,puVar11);
        if (0 < iVar3) {
          bVar13 = puVar7 == puVar10;
          puVar4 = puVar11;
          puVar6 = puVar7 + param_3;
          puVar12 = puVar10;
          puVar10 = puVar11;
          puVar8 = puVar11;
          if (bVar13) goto LAB_300bd00c;
          goto LAB_300bd004;
        }
      }
      puVar4 = puVar10;
      puVar6 = puVar7;
      puVar12 = puVar7;
      if (puVar7 == puVar10) break;
LAB_300bd004:
      puVar8 = puVar11 + -param_3;
      puVar11 = puVar4;
      puVar10 = puVar12;
LAB_300bd00c:
      do {
        puVar7 = puVar6;
        uVar1 = *puVar9;
        iVar2 = iVar2 + -1;
        *puVar9 = *puVar11;
        *puVar11 = uVar1;
        puVar11 = puVar11 + 1;
        puVar9 = puVar9 + 1;
        puVar6 = puVar7;
      } while (iVar2 != 0);
      bVar13 = true;
    }
    iVar2 = param_2;
    if (!bVar13) goto LAB_300bd254;
    iVar2 = __div32((int)puVar10 - (int)param_1,param_3);
    puVar10 = puVar10 + param_3;
    param_2 = (param_2 - iVar2) + -1;
    if (param_2 < iVar2) {
      if (param_2 < 4) {
        if (1 < param_2) {
          if (param_2 == 2) {
            puVar8 = puVar10 + param_3;
            iVar5 = (*param_4)(puVar8,puVar10);
            iVar3 = param_3;
            if (iVar5 < 0) {
              do {
                uVar1 = *puVar8;
                iVar3 = iVar3 + -1;
                *puVar8 = *puVar10;
                puVar8 = puVar8 + 1;
                *puVar10 = uVar1;
                puVar10 = puVar10 + 1;
              } while (iVar3 != 0);
            }
          }
          else {
            FUN_300bcdbc(puVar10,param_2,param_3,param_4);
          }
        }
        param_2 = iVar2;
        if (iVar2 < 4) {
          if (iVar2 < 2) {
            return;
          }
          if (iVar2 == 2) {
            puVar10 = param_1 + param_3;
            iVar2 = (*param_4)(puVar10,param_1);
            if (iVar2 < 0) {
              do {
                uVar1 = *puVar10;
                param_3 = param_3 + -1;
                *puVar10 = *param_1;
                puVar10 = puVar10 + 1;
                *param_1 = uVar1;
                param_1 = param_1 + 1;
              } while (param_3 != 0);
              return;
            }
            return;
          }
          goto LAB_300bd254;
        }
      }
      else {
        FUN_300bce74(puVar10,param_2,param_3,param_4);
        param_2 = iVar2;
      }
      goto LAB_300bce8c;
    }
    if (iVar2 < 4) {
      if (1 < iVar2) {
        if (iVar2 == 2) {
          puVar8 = param_1 + param_3;
          iVar3 = (*param_4)(puVar8,param_1);
          iVar2 = param_3;
          if (iVar3 < 0) {
            do {
              uVar1 = *puVar8;
              iVar2 = iVar2 + -1;
              *puVar8 = *param_1;
              puVar8 = puVar8 + 1;
              *param_1 = uVar1;
              param_1 = param_1 + 1;
            } while (iVar2 != 0);
          }
        }
        else {
          FUN_300bcdbc(param_1,iVar2,param_3,param_4);
        }
      }
      param_1 = puVar10;
      if (param_2 < 4) {
        if (param_2 < 2) {
          return;
        }
        iVar2 = param_2;
        if (param_2 == 2) {
          puVar8 = puVar10 + param_3;
          iVar2 = (*param_4)(puVar8,puVar10);
          if (-1 < iVar2) {
            return;
          }
          do {
            uVar1 = *puVar8;
            param_3 = param_3 + -1;
            *puVar8 = *puVar10;
            puVar8 = puVar8 + 1;
            *puVar10 = uVar1;
            puVar10 = puVar10 + 1;
          } while (param_3 != 0);
          return;
        }
LAB_300bd254:
        FUN_300bcdbc(param_1,iVar2,param_3,param_4);
        return;
      }
    }
    else {
      FUN_300bce74(param_1,iVar2,param_3,param_4);
      param_1 = puVar10;
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * system @ 0x300BD614  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BD614
 * ---------------------------------------------------------------- */
int system(char *__command)

{
  return 0;
}

/* ----------------------------------------------------------------
 * strcoll @ 0x300BDB54  (примерный размер ~232 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300bdae0, memcmp
 * Константы: 0x300BDB54
 * Данные: DAT_300bdc38
 * ---------------------------------------------------------------- */
int strcoll(char *__s1,char *__s2)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  uint __n;
  uint uVar5;
  undefined1 auStack_7c [32];
  char *local_5c;
  char *local_58;
  void *local_54;
  undefined1 local_50;
  undefined2 local_4e;
  undefined1 auStack_4c [32];
  char *local_2c;
  char *local_28;
  void *local_24;
  undefined1 local_20;
  undefined2 local_1e;
  
  uVar4 = 0;
  local_50 = *DAT_300bdc38;
  uVar5 = 0;
  local_4e = *(undefined2 *)(DAT_300bdc38 + 2);
  local_5c = __s1;
  local_58 = __s1;
  local_2c = __s2;
  local_28 = __s2;
  local_20 = local_50;
  local_1e = local_4e;
  while( true ) {
    if (uVar4 == 0) {
      uVar4 = FUN_300bdae0(auStack_7c);
    }
    if (uVar5 == 0) {
      uVar5 = FUN_300bdae0(auStack_4c);
    }
    pvVar2 = local_24;
    pvVar1 = local_54;
    __n = uVar4;
    if (uVar5 <= uVar4) {
      __n = uVar5;
    }
    if (__n == 0) break;
    iVar3 = memcmp(local_54,local_24,__n);
    if (iVar3 != 0) {
      return iVar3;
    }
    local_54 = (void *)((int)pvVar1 + __n);
    local_24 = (void *)((int)pvVar2 + __n);
    uVar4 = uVar4 - __n;
    uVar5 = uVar5 - __n;
  }
  if (uVar4 == uVar5) {
    iVar3 = 0;
  }
  else if (uVar5 == 0) {
    iVar3 = 1;
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * strncat @ 0x300BDDE8  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: QC_gzerror, pathCat
 * Константы: 0x300BDDE8
 * ---------------------------------------------------------------- */
char * strncat(char *__dest,char *__src,size_t __n)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = __dest;
  if (__n != 0) {
    do {
      pcVar3 = pcVar2;
      pcVar2 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    do {
      cVar1 = *__src;
      *pcVar3 = cVar1;
      pcVar3 = pcVar3 + 1;
      if (cVar1 == '\0') break;
      __n = __n - 1;
      __src = __src + 1;
    } while (__n != 0);
    if (__n == 0) {
      *pcVar3 = '\0';
    }
  }
  return __dest;
}

/* ----------------------------------------------------------------
 * strncpy @ 0x300BDE90  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 67 | Вызывает: 0
 * Вызывают: ABB_ReadCfg, BSP_DLOAD_GetProductId, BSP_InitBspVersion, CvTaskNameget, FUN_3000ed18, FUN_3001c6e8, FUN_30020c34, FUN_30020c58, FUN_3008b498, FUN_3008b88c
 *           ...
 * Константы: 0x300BDE90
 * ---------------------------------------------------------------- */
char * strncpy(char *__dest,char *__src,size_t __n)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = __dest;
  if (__n != 0) {
    do {
      cVar1 = *__src;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
      if (cVar1 == '\0') {
        while (__n = __n - 1, __n != 0) {
          *pcVar2 = '\0';
          pcVar2 = pcVar2 + 1;
        }
        return __dest;
      }
      __n = __n - 1;
      __src = __src + 1;
    } while (__n != 0);
  }
  return __dest;
}

/* ----------------------------------------------------------------
 * strxfrm @ 0x300BE1AC  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __strxfrm
 * Константы: 0x300BE1AC
 * ---------------------------------------------------------------- */
size_t strxfrm(char *__dest,char *__src,size_t __n)

{
  int iVar1;
  uint uVar2;
  char *local_3c;
  undefined1 local_38 [2];
  undefined2 local_36;
  undefined1 auStack_34 [32];
  
  uVar2 = 0;
  local_38[0] = 0;
  local_36 = 0;
  local_3c = __src;
  if (__n != 0) {
    do {
      iVar1 = __strxfrm(__dest,&local_3c,uVar2 - __n,local_38);
      __dest = __dest + iVar1;
      uVar2 = uVar2 + iVar1;
      if ((iVar1 != 0) && (__dest[-1] == '\0')) goto LAB_300be268;
      if (*local_3c == '\0') {
        local_3c = __src;
      }
    } while (uVar2 < __n);
  }
  while( true ) {
    iVar1 = __strxfrm(auStack_34,&local_3c,0x20,local_38);
    uVar2 = uVar2 + iVar1;
    if ((iVar1 != 0) && (auStack_34[iVar1 + -1] == '\0')) break;
    if (*local_3c == '\0') {
      local_3c = __src;
    }
  }
LAB_300be268:
  return uVar2 - 1;
}

/* ----------------------------------------------------------------
 * strlcpy @ 0x300BE278  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: strerror_r
 * Константы: 0x300BE278
 * ---------------------------------------------------------------- */
char * strlcpy(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  
  pcVar2 = param_2;
  iVar4 = param_3;
  if (param_3 == 0) {
LAB_300be2b0:
    if (iVar4 != 0) goto LAB_300be2d0;
  }
  else {
    iVar4 = param_3 + -1;
    pcVar3 = param_2;
    if (iVar4 != 0) {
      do {
        pcVar2 = pcVar3 + 1;
        cVar1 = *pcVar3;
        *param_1 = cVar1;
        param_1 = param_1 + 1;
        if (cVar1 == '\0') break;
        iVar4 = iVar4 + -1;
        pcVar3 = pcVar2;
      } while (iVar4 != 0);
      goto LAB_300be2b0;
    }
  }
  pcVar3 = pcVar2;
  if (param_3 != 0) {
    *param_1 = '\0';
  }
  do {
    pcVar2 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar2;
  } while (cVar1 != '\0');
LAB_300be2d0:
  return pcVar2 + (-1 - (int)param_2);
}

/* ----------------------------------------------------------------
 * strdup @ 0x300BE2E0  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 3
 * Вызывает: malloc, strcpy, strlen
 * Вызывают: FUN_300f7dbc, FUN_300f7f08, FUN_300f81ac, loadModuleInfoInit, tagCheckModuleAdd, tipLibInit, vxdbgBpMsgQCreate
 * Константы: 0x300BE2E0
 * ---------------------------------------------------------------- */
char * strdup(char *__s)

{
  size_t sVar1;
  char *__dest;
  
  if (__s == (char *)0x0) {
    return (char *)0x0;
  }
  sVar1 = strlen(__s);
  __dest = (char *)malloc(sVar1 + 1);
  if (__dest == (char *)0x0) {
    return (char *)0x0;
  }
  strcpy(__dest,__s);
  return __dest;
}

/* ----------------------------------------------------------------
 * strcasecmp @ 0x300BE330  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BE330
 * Данные: DAT_300be394
 * ---------------------------------------------------------------- */
int strcasecmp(char *__s1,char *__s2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *DAT_300be394;
  iVar1 = (uint)*(byte *)(iVar2 + (uint)(byte)*__s1) - (uint)*(byte *)(iVar2 + (uint)(byte)*__s2);
  while ((iVar1 == 0 && (*__s1 != 0))) {
    __s1 = (char *)((byte *)__s1 + 1);
    __s2 = (char *)((byte *)__s2 + 1);
    iVar1 = (uint)*(byte *)(iVar2 + (uint)(byte)*__s1) - (uint)*(byte *)(iVar2 + (uint)(byte)*__s2);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * strncasecmp @ 0x300BE398  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300d42ac
 * Константы: 0x300BE398
 * Данные: DAT_300be3ec
 * ---------------------------------------------------------------- */
int strncasecmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
  if (__n != 0) {
    do {
      iVar1 = (uint)*(byte *)(*DAT_300be3ec + (uint)(byte)*__s1) -
              (uint)*(byte *)(*DAT_300be3ec + (uint)(byte)*__s2);
      if (iVar1 != 0) {
        return iVar1;
      }
      if ((byte)*__s1 == 0) {
        return 0;
      }
      __s1 = (char *)((byte *)__s1 + 1);
      __s2 = (char *)((byte *)__s2 + 1);
      __n = __n - 1;
    } while (__n != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * time @ 0x300BF628  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 1
 * Вызывает: clock_gettime
 * Вызывают: FUN_300d5c80, FUN_300da18c, FUN_300da31c, FUN_300db20c, FUN_301196f0, copy, dosFsClose
 * Константы: 0x300BF628
 * ---------------------------------------------------------------- */
time_t time(time_t *__timer)

{
  int iVar1;
  timespec local_10;
  
  iVar1 = clock_gettime(0,&local_10);
  if (iVar1 == 0) {
    if (__timer != (time_t *)0x0) {
      *__timer = local_10.tv_sec;
    }
  }
  else {
    local_10.tv_sec = -1;
  }
  return local_10.tv_sec;
}

/* ----------------------------------------------------------------
 * difftime @ 0x300BF668  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __subdf3, _d_utod
 * Константы: 0x300BF668
 * ---------------------------------------------------------------- */
double difftime(time_t __time1,time_t __time0)

{
  double dVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = _d_utod(__time0);
  uVar3 = _d_utod(__time1);
  dVar1 = (double)__subdf3((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar2,
                           (int)((ulonglong)uVar2 >> 0x20));
  return dVar1;
}

/* ----------------------------------------------------------------
 * _d_cmp @ 0x300BF6AC  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x7FFFFFFF, 0x300BF6AC
 * Данные: DAT_300bf7bc, DAT_300bf7c0
 * ---------------------------------------------------------------- */
int _d_cmp(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  bool bVar2;
  
  if ((((DAT_300bf7bc & param_2 >> 0x14) == DAT_300bf7bc) &&
      ((param_2 & DAT_300bf7c0) + param_1 != 0)) ||
     (((DAT_300bf7bc & param_4 >> 0x14) == DAT_300bf7bc && ((param_4 & DAT_300bf7c0) + param_3 != 0)
      ))) {
    iVar1 = 3;
  }
  else {
    if ((int)param_2 < 0) {
      bVar2 = param_1 != 0;
      param_1 = -param_1;
      param_2 = -((param_2 & 0x7fffffff) + (uint)bVar2);
    }
    if ((int)param_4 < 0) {
      bVar2 = param_3 != 0;
      param_3 = -param_3;
      param_4 = -((param_4 & 0x7fffffff) + (uint)bVar2);
    }
    if ((int)param_2 < (int)param_4) {
      iVar1 = 1;
    }
    else if ((int)param_4 < (int)param_2) {
      iVar1 = 2;
    }
    else if (param_1 < param_3) {
      iVar1 = 1;
    }
    else {
      iVar1 = (uint)(param_3 < param_1) << 1;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * _d_cmpe @ 0x300BF7C4  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x7FFFFFFF, 0x300BF7C4
 * Данные: DAT_300bf8d4, DAT_300bf8d8
 * ---------------------------------------------------------------- */
int _d_cmpe(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  bool bVar2;
  
  if ((((DAT_300bf8d4 & param_2 >> 0x14) == DAT_300bf8d4) &&
      ((param_2 & DAT_300bf8d8) + param_1 != 0)) ||
     (((DAT_300bf8d4 & param_4 >> 0x14) == DAT_300bf8d4 && ((param_4 & DAT_300bf8d8) + param_3 != 0)
      ))) {
    iVar1 = 3;
  }
  else {
    if ((int)param_2 < 0) {
      bVar2 = param_1 != 0;
      param_1 = -param_1;
      param_2 = -((param_2 & 0x7fffffff) + (uint)bVar2);
    }
    if ((int)param_4 < 0) {
      bVar2 = param_3 != 0;
      param_3 = -param_3;
      param_4 = -((param_4 & 0x7fffffff) + (uint)bVar2);
    }
    if ((int)param_2 < (int)param_4) {
      iVar1 = 1;
    }
    else if ((int)param_4 < (int)param_2) {
      iVar1 = 2;
    }
    else if (param_1 < param_3) {
      iVar1 = 1;
    }
    else {
      iVar1 = (uint)(param_3 < param_1) << 1;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sfpDoubleSetup @ 0x300BFBB8  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __ff1ll, __lsl64
 * Константы: 0x300BFBB8, 0xFFFFFFFF, 0x00100000
 * Данные: DAT_300bfc9c, DAT_300bfca0, DAT_300bfca4, DAT_300bfca8
 * ---------------------------------------------------------------- */
int sfpDoubleSetup(int param_1,uint param_2,uint *param_3,int *param_4,int *param_5,
                  undefined4 *param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  uint local_30;
  
  local_30 = param_2 >> 0x1f;
  uVar2 = DAT_300bfc9c & param_2 >> 0x14;
  param_2 = param_2 & DAT_300bfca0;
  if (uVar2 == DAT_300bfc9c) {
    *param_6 = 1;
  }
  else {
    iVar1 = param_1;
    if (uVar2 == 0) {
      if (param_2 + param_1 == 0) {
        local_30 = 0;
        iVar3 = 0;
      }
      else {
        iVar1 = __ff1ll(param_1,param_2,0xffffffff);
        iVar3 = DAT_300bfca4 - (iVar1 + -0xb);
        uVar4 = __lsl64(param_1,param_2);
        param_2 = (uint)((ulonglong)uVar4 >> 0x20);
        iVar1 = (int)uVar4;
      }
    }
    else {
      param_2 = param_2 | 0x100000;
      iVar3 = uVar2 - DAT_300bfca8;
    }
    *param_3 = local_30;
    param_1 = 0;
    *param_4 = iVar3;
    *param_5 = iVar1;
    param_5[1] = param_2;
    *param_6 = 0;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * _f_cmp @ 0x300BFCAC  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x80000000, 0x7FFFFFFF, 0x300BFCAC
 * Данные: DAT_300bfd34
 * ---------------------------------------------------------------- */
int _f_cmp(uint param_1,uint param_2)

{
  if ((((param_1 >> 0x17 & 0xff) == 0xff) && ((param_1 & DAT_300bfd34) != 0)) ||
     (((param_2 >> 0x17 & 0xff) == 0xff && ((param_2 & DAT_300bfd34) != 0)))) {
    return 3;
  }
  if ((param_1 & 0x80000000) != 0) {
    param_1 = -(param_1 & 0x7fffffff);
  }
  if ((param_2 & 0x80000000) != 0) {
    param_2 = -(param_2 & 0x7fffffff);
  }
  if ((int)param_2 <= (int)param_1) {
    return (uint)((int)param_2 < (int)param_1) << 1;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * _f_cmpe @ 0x300BFD38  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x80000000, 0x7FFFFFFF, 0x300BFD38
 * Данные: DAT_300bfdc0
 * ---------------------------------------------------------------- */
int _f_cmpe(uint param_1,uint param_2)

{
  if ((((param_1 >> 0x17 & 0xff) == 0xff) && ((param_1 & DAT_300bfdc0) != 0)) ||
     (((param_2 >> 0x17 & 0xff) == 0xff && ((param_2 & DAT_300bfdc0) != 0)))) {
    return 3;
  }
  if ((param_1 & 0x80000000) != 0) {
    param_1 = -(param_1 & 0x7fffffff);
  }
  if ((param_2 & 0x80000000) != 0) {
    param_2 = -(param_2 & 0x7fffffff);
  }
  if ((int)param_2 <= (int)param_1) {
    return (uint)((int)param_2 < (int)param_1) << 1;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * sfpFloatSetup @ 0x300BFDC4  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __ff1l
 * Константы: 0x300BFDC4, 0x00800000
 * Данные: DAT_300bfe60
 * ---------------------------------------------------------------- */
uint sfpFloatSetup(uint param_1,uint *param_2,int *param_3,uint *param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_1 >> 0x17 & 0xff;
  uVar4 = param_1 >> 0x1f;
  uVar5 = param_1 & DAT_300bfe60;
  if (uVar1 != 0xff) {
    if (uVar1 == 0) {
      if (uVar5 == 0) {
        uVar4 = 0;
        iVar3 = 0;
        uVar5 = 0;
      }
      else {
        iVar2 = __ff1l(uVar5);
        iVar3 = -0x7e - (iVar2 - 8U);
        uVar5 = uVar5 << (iVar2 - 8U & 0xff);
      }
    }
    else {
      uVar5 = uVar5 | 0x800000;
      iVar3 = uVar1 - 0x7f;
    }
    *param_2 = uVar4;
    *param_3 = iVar3;
    *param_4 = uVar5;
    *param_5 = 0;
    return 0;
  }
  *param_5 = 1;
  return param_1;
}

/* ----------------------------------------------------------------
 * _fp_round @ 0x300BFE64  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BFE64
 * Данные: DAT_300bfe94
 * ---------------------------------------------------------------- */
longlong _fp_round(int param_1)

{
  if ((param_1 < 0) || (3 < param_1)) {
    param_1 = *DAT_300bfe94;
  }
  else {
    *DAT_300bfe94 = param_1;
  }
  return (longlong)param_1;
}

/* ----------------------------------------------------------------
 * sfpDoubleNormalize @ 0x300BFE98  (примерный размер ~700 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: __ff1ll, __lsl64, __lsr64
 * Константы: 0x300BFE98, 0xFFEFFFFF, 0x7FFFFFFF, 0xFFFFFFFE, 0x00100000
 * Данные: DAT_300c0398, DAT_300c039c, DAT_300c03a0
 * ---------------------------------------------------------------- */
uint sfpDoubleNormalize(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                       int param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  int local_3c;
  int local_4;
  
  uVar6 = CONCAT44(param_6,param_5);
  uVar5 = CONCAT44(param_4,param_3);
  iVar1 = __ff1ll(param_3,param_4);
  iVar1 = iVar1 + -0xb;
  local_4 = param_2 + (DAT_300c0398 - iVar1);
  local_3c = iVar1;
  if (local_4 < 1) {
    local_3c = iVar1 + local_4 + -1;
    if (iVar1 + local_4 + 0x41 < 0 != SCARRY4(local_3c,0x42)) {
      return 0;
    }
    local_4 = 0;
  }
  if (local_3c < 1) {
    if (local_3c < 0) {
      uVar3 = (uint)(param_6 != 0 || param_5 != 0);
      if (local_3c == -0x40 || local_3c + 0x40 < 0 != SCARRY4(local_3c,0x40)) {
        uVar7 = __lsr64(param_3,param_4,-0x40 - local_3c);
        uVar6 = CONCAT44((int)((ulonglong)uVar7 >> 0x20),uVar3 | (uint)uVar7);
        uVar5 = 0;
      }
      else {
        uVar7 = __lsl64(param_3,param_4,local_3c + 0x40,iVar1);
        uVar6 = CONCAT44((int)((ulonglong)uVar7 >> 0x20),uVar3 | (uint)uVar7);
        uVar5 = __lsr64(param_3,param_4,-local_3c);
      }
    }
  }
  else if (local_3c < 0x40) {
    uVar5 = __lsl64(param_3,param_4,local_3c,iVar1);
    uVar6 = __lsr64(param_5,param_6,0x40 - local_3c);
    uVar5 = uVar5 | uVar6;
    uVar6 = __lsl64(param_5,param_6,local_3c);
  }
  else {
    uVar5 = __lsl64(param_5,param_6,local_3c + -0x40,iVar1);
    uVar6 = 0;
  }
  uVar3 = (uint)uVar5;
  uVar2 = (uint)(uVar5 >> 0x20) & 0xffefffff;
  iVar1 = *DAT_300c039c;
  if (iVar1 == 0) {
    if ((uVar6 & 0x8000000000000000) == 0) goto LAB_300c00e8;
    if (((uint)(uVar6 >> 0x20) & 0x7fffffff) + (int)uVar6 == 0) {
      uVar5 = uVar5 & 1;
      goto joined_r0x300c00a4;
    }
  }
  else {
    if (iVar1 == 2) {
      if (param_1 != 0) goto LAB_300c00e8;
    }
    else if ((iVar1 != 3) || (param_1 == 0)) goto LAB_300c00e8;
    uVar5 = uVar6 & 0x8000000000000000;
joined_r0x300c00a4:
    if (uVar5 == 0) goto LAB_300c00e8;
  }
  bVar4 = 0xfffffffe < uVar3;
  uVar3 = uVar3 + 1;
  uVar2 = uVar2 + bVar4;
LAB_300c00e8:
  if ((uVar2 & 0x100000) != 0) {
    uVar3 = 0;
    local_4 = local_4 + 1;
  }
  if (DAT_300c03a0 <= local_4) {
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * sfpDoubleNormalize2 @ 0x300C0154  (примерный размер ~592 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: __ff1ll, __lsl64, __lsr64
 * Вызывают: __POL
 * Константы: 0xFFFFFFFE, 0x300C0154, 0xFFEFFFFF, 0x7FFFFFFF, 0x00100000
 * Данные: DAT_300c039c, DAT_300c03a0
 * ---------------------------------------------------------------- */
uint sfpDoubleNormalize2(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  int local_30;
  int local_4;
  
  uVar5 = CONCAT44(param_4,param_3);
  uVar6 = 0;
  local_30 = __ff1ll(param_3,param_4);
  local_30 = local_30 + -0xb;
  local_4 = param_2 - local_30;
  if (local_4 < 1) {
    local_4 = local_30 + local_4;
    local_30 = local_4 + -1;
    if (local_4 + 0x41 < 0 != SCARRY4(local_30,0x42)) {
      return 0;
    }
    local_4 = 0;
  }
  if (local_30 < 1) {
    if (local_30 < 0) {
      if (local_30 == -0x40 || local_30 + 0x40 < 0 != SCARRY4(local_30,0x40)) {
        uVar6 = __lsr64(param_3,param_4,-0x40 - local_30);
        uVar5 = 0;
      }
      else {
        uVar6 = __lsl64(param_3,param_4,local_30 + 0x40);
        uVar5 = __lsr64(param_3,param_4,-local_30);
      }
    }
  }
  else {
    uVar6 = 0;
    if (local_30 < 0x40) {
      uVar5 = __lsl64(param_3,param_4,local_30);
    }
    else {
      uVar5 = 0;
      uVar6 = 0;
    }
  }
  uVar2 = (uint)uVar5;
  uVar3 = (uint)(uVar5 >> 0x20) & 0xffefffff;
  iVar1 = *DAT_300c039c;
  if (iVar1 == 0) {
    if (((uVar6 & 0x8000000000000000) != 0) &&
       ((((uint)(uVar6 >> 0x20) & 0x7fffffff) + (int)uVar6 != 0 || ((uVar5 & 1) != 0)))) {
      bVar4 = 0xfffffffe < uVar2;
      uVar2 = uVar2 + 1;
      uVar3 = uVar3 + bVar4;
    }
  }
  else if (iVar1 == 2) {
    if ((param_1 == 0) && ((uVar6 & 0x8000000000000000) != 0)) {
      bVar4 = 0xfffffffe < uVar2;
      uVar2 = uVar2 + 1;
      uVar3 = uVar3 + bVar4;
    }
  }
  else if (((iVar1 == 3) && (param_1 != 0)) && ((uVar6 & 0x8000000000000000) != 0)) {
    bVar4 = 0xfffffffe < uVar2;
    uVar2 = uVar2 + 1;
    uVar3 = uVar3 + bVar4;
  }
  if ((uVar3 & 0x100000) != 0) {
    uVar2 = 0;
    local_4 = local_4 + 1;
  }
  if (DAT_300c03a0 <= local_4) {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * sfpFloatNormalize @ 0x300C03A4  (примерный размер ~352 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __ff1l
 * Константы: 0x80000000, 0x300C03A4, 0xFF7FFFFF, 0x7FFFFFFF, 0x00800000
 * Данные: DAT_300c04fc, DAT_300c0500
 * ---------------------------------------------------------------- */
uint sfpFloatNormalize(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = __ff1l(param_3);
  uVar2 = iVar1 - 8;
  param_2 = param_2 + (0x7f - uVar2);
  if (param_2 < 1) {
    param_2 = uVar2 + param_2;
    uVar2 = param_2 - 1;
    if (param_2 + 0x21 < 0 != SCARRY4(uVar2,0x22)) {
      return param_1 << 0x1f;
    }
    param_2 = 0;
  }
  if ((int)uVar2 < 1) {
    if ((int)uVar2 < 0) {
      if ((int)uVar2 < -0x1f) {
        param_4 = (uint)(param_4 != 0) | param_3 >> (-uVar2 - 0x20 & 0xff);
        param_3 = 0;
      }
      else {
        param_4 = (uint)(param_4 != 0) | param_3 << (uVar2 + 0x20 & 0xff);
        param_3 = param_3 >> (-uVar2 & 0xff);
      }
    }
  }
  else if ((int)uVar2 < 0x20) {
    param_3 = param_4 >> (0x20 - uVar2 & 0xff) | param_3 << (uVar2 & 0xff);
    param_4 = param_4 << (uVar2 & 0xff);
  }
  else {
    param_3 = param_4 << (uVar2 - 0x20 & 0xff);
    param_4 = 0;
  }
  iVar1 = *DAT_300c04fc;
  uVar2 = param_3 & 0xff7fffff;
  if (iVar1 == 0) {
    if ((param_4 & 0x80000000) == 0) goto LAB_300c04d0;
    if ((param_4 & 0x7fffffff) == 0) {
      param_4 = param_3 & 1;
      goto joined_r0x300c04a0;
    }
  }
  else {
    if (iVar1 != 2) {
      if (((iVar1 == 3) && (param_1 != 0)) && ((param_4 & 0x80000000) != 0)) {
        uVar2 = uVar2 + 1;
      }
      goto LAB_300c04d0;
    }
    if (param_1 != 0) goto LAB_300c04d0;
    param_4 = param_4 & 0x80000000;
joined_r0x300c04a0:
    if (param_4 == 0) goto LAB_300c04d0;
  }
  uVar2 = uVar2 + 1;
LAB_300c04d0:
  if ((uVar2 & 0x800000) != 0) {
    param_2 = param_2 + 1;
    uVar2 = 0;
  }
  if (param_2 < 0xff) {
    uVar2 = param_2 << 0x17 | param_1 << 0x1f | uVar2;
  }
  else {
    uVar2 = DAT_300c0500 | param_1 << 0x1f;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * _STI__07__diab_atomic_init @ 0x300C19B8  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __diab_alloc_mutex
 * Константы: 0x300C19B8
 * Данные: DAT_300c19f0
 * ---------------------------------------------------------------- */
void _STI__07__diab_atomic_init(void)

{
  undefined4 uVar1;
  
  uVar1 = __diab_alloc_mutex();
  *DAT_300c19f0 = uVar1;
  return;
}

/* ----------------------------------------------------------------
 * devInit @ 0x300C1DF0  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300c1a54
 * Вызывают: usrIosExtraInit
 * Константы: 0x300C1DF0, 0xFFFFFFFF
 * Данные: DAT_300c1ff4
 * ---------------------------------------------------------------- */
undefined4 devInit(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_300c1a54();
  *DAT_300c1ff4 = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * devAttach @ 0x300C1E10  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300c1b30, semGive, semTake, strncpy
 * Вызывают: xbdAttach
 * Константы: 0x300C1E10, 0xFFFFFFFF
 * Данные: DAT_300c1ff4
 * ---------------------------------------------------------------- */
undefined4 devAttach(undefined4 *param_1,char *param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  strncpy((char *)(param_1 + 2),param_2,10);
  param_1[1] = param_3;
  piVar1 = DAT_300c1ff4;
  semTake(*(undefined4 *)(*DAT_300c1ff4 + 8),0xffffffff);
  iVar3 = *piVar1;
  uVar2 = FUN_300c1b30(iVar3,param_1,param_1);
  semGive(*(undefined4 *)(iVar3 + 8));
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *param_1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * devDetach @ 0x300C1E88  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300c1c1c, semGive, semTake
 * Константы: 0x300C1E88, 0xFFFFFFFF
 * Данные: DAT_300c1ff4
 * ---------------------------------------------------------------- */
undefined4 devDetach(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_300c1ff4;
  semTake(*(undefined4 *)(*DAT_300c1ff4 + 8),0xffffffff);
  iVar3 = *piVar1;
  uVar2 = FUN_300c1c1c(iVar3,*param_1);
  semGive(*(undefined4 *)(iVar3 + 8));
  return uVar2;
}

/* ----------------------------------------------------------------
 * devMap @ 0x300C1ED8  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 9 | Вызывает: 3
 * Вызывает: FUN_300c1cac, semGive, semTake
 * Вызывают: devName, xbdBlkDevCreateSync, xbdBlkDevDelete, xbdBlockSize, xbdIoctl, xbdNBlocks, xbdRamDiskDevDelete, xbdSize, xbdStrategy
 * Константы: 0x300C1ED8, 0xFFFFFFFF
 * Данные: DAT_300c1ff4
 * ---------------------------------------------------------------- */
undefined4 devMap(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_300c1ff4;
  semTake(*(undefined4 *)(*DAT_300c1ff4 + 8),0xffffffff);
  uVar2 = FUN_300c1cac(*piVar1,param_1);
  semGive(*(undefined4 *)(*piVar1 + 8));
  return uVar2;
}

/* ----------------------------------------------------------------
 * devMapUnsafe @ 0x300C1F2C  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300c1cac
 * Вызывают: xbdDump
 * Константы: 0x300C1F2C
 * Данные: DAT_300c1ff4
 * ---------------------------------------------------------------- */
void devMapUnsafe(undefined4 param_1)

{
  FUN_300c1cac(*DAT_300c1ff4,param_1);
  return;
}

/* ----------------------------------------------------------------
 * devUnmap @ 0x300C1F44  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 11 | Вызывает: 3
 * Вызывает: FUN_300c1d44, semGive, semTake
 * Вызывают: FUN_300dddf8, FUN_300decb0, devName, xbdBlkDevCreateSync, xbdBlkDevDelete, xbdBlockSize, xbdIoctl, xbdNBlocks, xbdRamDiskDevDelete, xbdSize
 *           ...
 * Константы: 0x300C1F44, 0xFFFFFFFF
 * Данные: DAT_300c1ff4
 * ---------------------------------------------------------------- */
undefined4 devUnmap(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_300c1ff4;
  semTake(*(undefined4 *)(*DAT_300c1ff4 + 8),0xffffffff);
  iVar2 = *piVar1;
  FUN_300c1d44(iVar2,param_1);
  semGive(*(undefined4 *)(iVar2 + 8));
  return 0;
}

/* ----------------------------------------------------------------
 * devUnmapUnsafe @ 0x300C1F90  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300c1d44
 * Вызывают: xbdDump
 * Константы: 0x300C1F90
 * Данные: DAT_300c1ff4
 * ---------------------------------------------------------------- */
undefined4 devUnmapUnsafe(undefined4 param_1)

{
  FUN_300c1d44(*DAT_300c1ff4,param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * devName @ 0x300C1FAC  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: devMap, devUnmap, strncpy
 * Вызывают: FUN_300c9698, xbdPartitionDevCreate
 * Константы: 0x300C1FAC, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 devName(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = devMap();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    strncpy(param_2,(char *)(iVar1 + 8),10);
    devUnmap(iVar1);
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300c1ff8 @ 0x300C1FF8  (примерный размер ~416 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 5
 * Вызывает: errnoSet, free, malloc, semCCreate, taskSpawn
 * Вызывают: erfCategoryQueueCreate, erfLibInit
 * Константы: 0xFFFFFFFF, 0x300C1FF8
 * Данные: DAT_300c2d14, DAT_300c2d18, DAT_300c2d1c, DAT_300c2d20, DAT_300c2d24, DAT_300c2d28, DAT_300c2d2c, DAT_300c2d30
 * ---------------------------------------------------------------- */
short * FUN_300c1ff8(int param_1,uint param_2,int param_3)

{
  short *__ptr;
  int iVar1;
  undefined1 *puVar2;
  short *psVar3;
  undefined1 *puVar4;
  undefined1 local_2c [8];
  char local_24;
  
  psVar3 = (short *)0x0;
  if ((param_1 < 1) || (0xff < param_2)) {
    errnoSet(DAT_300c2d14);
    return (short *)0xffffffff;
  }
  __ptr = (short *)malloc(param_1 * 0xc + 0x1c);
  if (__ptr == (short *)0x0) {
    errnoSet(DAT_300c2d30);
    psVar3 = (short *)0xffffffff;
LAB_300c2180:
    if (psVar3 != (short *)0xffffffff) {
      return __ptr;
    }
  }
  else {
    iVar1 = semCCreate(0,0);
    *(int *)(__ptr + 4) = iVar1;
    if (iVar1 != 0) {
      *__ptr = (short)param_1 + 1;
      __ptr[1] = 0;
      __ptr[2] = 0;
      if (param_3 == -1) {
        puVar4 = local_2c;
        iVar1 = 9;
        puVar2 = DAT_300c2d18;
        do {
          iVar1 = iVar1 + -1;
          *puVar4 = *puVar2;
          puVar4 = puVar4 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar1 != 0);
      }
      else if (param_3 < 10) {
        puVar4 = local_2c;
        iVar1 = 10;
        puVar2 = DAT_300c2d1c;
        do {
          iVar1 = iVar1 + -1;
          *puVar4 = *puVar2;
          puVar4 = puVar4 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar1 != 0);
        local_24 = local_24 + (char)param_3;
      }
      else {
        puVar4 = local_2c;
        iVar1 = 10;
        puVar2 = DAT_300c2d20;
        do {
          iVar1 = iVar1 + -1;
          *puVar4 = *puVar2;
          puVar4 = puVar4 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar1 != 0);
        local_24 = local_24 + (char)param_3 + -10;
      }
      iVar1 = taskSpawn(local_2c,param_2,*DAT_300c2d28,*DAT_300c2d2c,DAT_300c2d24,__ptr,0,0,0,0,0,0,
                        0,0,0);
      *(int *)(__ptr + 6) = iVar1;
      if (iVar1 != -1) goto LAB_300c2180;
    }
    psVar3 = (short *)0xffffffff;
    free(__ptr);
  }
  return psVar3;
}

/* ----------------------------------------------------------------
 * erfLibInit @ 0x300C2198  (примерный размер ~632 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300c1ff8, errnoSet, malloc, semMCreate, spinLockIsrInit
 * Вызывают: usrIosExtraInit
 * Константы: 0xFFFFFFFF, 0x300C2198
 * Данные: DAT_300c2d30, DAT_300c2d34, DAT_300c2d38, DAT_300c2d3c, DAT_300c2d40, DAT_300c2d44, DAT_300c2d48, DAT_300c2d4c
 * ---------------------------------------------------------------- */
undefined4 erfLibInit(short param_1,short param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int *piVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  uVar5 = 0;
  if (*DAT_300c2d34 == '\0') {
    *DAT_300c2d34 = '\x01';
    puVar2 = DAT_300c2d38;
    *DAT_300c2d38 = param_1 + 1U;
    *DAT_300c2d3c = param_2 + 3U;
    *DAT_300c2d40 = param_1;
    *DAT_300c2d44 = param_2;
    *DAT_300c2d48 = 0;
    iVar7 = (uint)(ushort)(param_2 + 3U) * (uint)(ushort)(param_1 + 1U);
    spinLockIsrInit(DAT_300c2d4c,0);
    pvVar4 = malloc(iVar7 * 4);
    *DAT_300c2d50 = pvVar4;
    if (pvVar4 == (void *)0x0) {
      errnoSet(DAT_300c2d30);
      uVar5 = 0xffffffff;
    }
    else {
      uVar9 = 0;
      if (0 < iVar7) {
        do {
          *(undefined4 *)((int)pvVar4 + uVar9 * 4) = 0;
          uVar9 = uVar9 + 1 & 0xffff;
        } while ((int)uVar9 < iVar7);
      }
    }
    uVar1 = *puVar2;
    pvVar4 = malloc((uint)uVar1 << 2);
    piVar3 = DAT_300c2d54;
    *DAT_300c2d54 = (int)pvVar4;
    if (pvVar4 == (void *)0x0) {
      errnoSet(DAT_300c2d30);
      uVar5 = 0xffffffff;
    }
    else {
      uVar9 = 0;
      if (uVar1 != 0) {
        do {
          iVar6 = *piVar3;
          iVar7 = semMCreate(9);
          *(int *)(iVar6 + uVar9 * 4) = iVar7;
          if (iVar7 == 0) {
            errnoSet(DAT_300c2d58);
            uVar5 = 0xffffffff;
          }
          uVar9 = uVar9 + 1 & 0xffff;
        } while (uVar9 < *puVar2);
      }
    }
    iVar7 = semMCreate(9);
    *DAT_300c2d5c = iVar7;
    if (iVar7 == 0) {
      errnoSet(DAT_300c2d58);
      uVar5 = 0xffffffff;
    }
    uVar9 = (uint)*puVar2;
    pvVar4 = malloc(uVar9 << 1);
    *DAT_300c2d60 = pvVar4;
    if (pvVar4 == (void *)0x0) {
      errnoSet(DAT_300c2d30);
      uVar5 = 0xffffffff;
    }
    else {
      uVar8 = 0;
      if (uVar9 != 0) {
        do {
          *(undefined2 *)((int)pvVar4 + uVar8 * 2) = 0;
          uVar8 = uVar8 + 1 & 0xffff;
        } while (uVar8 < uVar9);
      }
    }
    iVar7 = FUN_300c1ff8(*DAT_300c2d68,*DAT_300c2d64,0xffffffff);
    *DAT_300c2d6c = iVar7;
    if (iVar7 == -1) {
      errnoSet(DAT_300c2d58);
      uVar5 = 0xffffffff;
      *DAT_300c2d6c = 0;
    }
    uVar9 = (uint)*puVar2;
    pvVar4 = malloc(uVar9 << 2);
    *DAT_300c2d70 = pvVar4;
    if (pvVar4 == (void *)0x0) {
      errnoSet(DAT_300c2d30);
      uVar5 = 0xffffffff;
    }
    else {
      uVar8 = 0;
      if (uVar9 != 0) {
        do {
          *(undefined4 *)((int)pvVar4 + uVar8 * 4) = 0;
          uVar8 = uVar8 + 1 & 0xffff;
        } while (uVar8 < uVar9);
      }
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * FUN_300c2410 @ 0x300C2410  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: erfHandlerRegister
 * Константы: 0x300C2410
 * Данные: DAT_300c2d3c, DAT_300c2d50
 * ---------------------------------------------------------------- */
undefined4 FUN_300c2410(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *DAT_300c2d50;
  iVar1 = (param_1 * (uint)*DAT_300c2d3c + param_2) * 4;
  *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)(iVar2 + iVar1);
  *(int *)(iVar2 + iVar1) = param_3;
  return 0;
}

/* ----------------------------------------------------------------
 * erfHandlerRegister @ 0x300C243C  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 5
 * Вызывает: FUN_300c2410, errnoSet, malloc, semGive, semTake
 * Вызывают: dosFsMonitorDevCreate, fsMonitorInit, fsPathAddedEventSetup, rawFsDevInit, xbdBlkDevCreate, xbdPartitionDevCreate
 * Константы: 0xFFFFFFFF, 0x300C243C
 * Данные: DAT_300c2d14, DAT_300c2d30, DAT_300c2d38, DAT_300c2d3c, DAT_300c2d54
 * ---------------------------------------------------------------- */
undefined4
erfHandlerRegister(int param_1,int param_2,int param_3,undefined4 param_4,undefined2 param_5)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  
  if (((param_1 < (int)(uint)*DAT_300c2d38) && (param_2 < (int)(uint)*DAT_300c2d3c)) &&
     (param_3 != 0)) {
    puVar2 = (undefined2 *)malloc(0x10);
    piVar1 = DAT_300c2d54;
    if (puVar2 == (undefined2 *)0x0) {
      uVar3 = 0xffffffff;
      errnoSet(DAT_300c2d30);
    }
    else {
      semTake(*(undefined4 *)(*DAT_300c2d54 + param_1 * 4),0xffffffff);
      *(int *)(puVar2 + 2) = param_3;
      *(undefined4 *)(puVar2 + 4) = param_4;
      *puVar2 = param_5;
      uVar3 = FUN_300c2410(param_1,param_2,puVar2);
      semGive(*(undefined4 *)(*piVar1 + param_1 * 4));
    }
  }
  else {
    uVar3 = 0xffffffff;
    errnoSet(DAT_300c2d14);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300c24fc @ 0x300C24FC  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: erfHandlerUnregister
 * Константы: 0x300C24FC
 * Данные: DAT_300c2d3c, DAT_300c2d50
 * ---------------------------------------------------------------- */
int FUN_300c24fc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  param_2 = param_1 * (uint)*DAT_300c2d3c + param_2;
  iVar3 = *DAT_300c2d50;
  iVar1 = *(int *)(iVar3 + param_2 * 4);
  iVar4 = 0;
  iVar5 = 0;
  while ((iVar2 = iVar1, iVar2 != 0 && (iVar4 == 0))) {
    if ((*(int *)(iVar2 + 4) == param_3) && (*(int *)(iVar2 + 8) == param_4)) {
      iVar1 = iVar2;
      iVar4 = iVar2;
      if (iVar5 == 0) {
        *(undefined4 *)(iVar3 + param_2 * 4) = *(undefined4 *)(iVar2 + 0xc);
      }
      else {
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
      }
    }
    else {
      iVar1 = *(int *)(iVar2 + 0xc);
      iVar5 = iVar2;
    }
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * erfHandlerUnregister @ 0x300C2588  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 5
 * Вызывает: FUN_300c24fc, errnoSet, free, semGive, semTake
 * Вызывают: FUN_300c92e0, FUN_300ca46c, FUN_300d6fa8, FUN_300de384, FUN_300decb0, fsWaitForPath, rawFsDevInit, xbdPartitionDevCreate
 * Константы: 0xFFFFFFFF, 0x300C2588
 * Данные: DAT_300c2d14, DAT_300c2d38, DAT_300c2d3c, DAT_300c2d54, DAT_300c2d74
 * ---------------------------------------------------------------- */
undefined4 erfHandlerUnregister(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  void *__ptr;
  undefined4 uVar2;
  
  piVar1 = DAT_300c2d54;
  uVar2 = DAT_300c2d14;
  if (((param_1 < (int)(uint)*DAT_300c2d38) && (param_2 < (int)(uint)*DAT_300c2d3c)) &&
     (param_3 != 0)) {
    semTake(*(undefined4 *)(*DAT_300c2d54 + param_1 * 4),0xffffffff);
    __ptr = (void *)FUN_300c24fc(param_1,param_2,param_3,param_4);
    semGive(*(undefined4 *)(*piVar1 + param_1 * 4));
    uVar2 = DAT_300c2d74;
    if (__ptr != (void *)0x0) {
      free(__ptr);
      return 0;
    }
  }
  errnoSet(uVar2);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * erfCategoryAllocate @ 0x300C2634  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: errnoSet, semGive, semTake
 * Вызывают: fsEventUtilLibInit, xbdInit
 * Константы: 0xFFFFFFFF, 0x300C2634
 * Данные: DAT_300c2d14, DAT_300c2d40, DAT_300c2d48, DAT_300c2d5c, DAT_300c2d78
 * ---------------------------------------------------------------- */
undefined4 erfCategoryAllocate(short *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 == (short *)0x0) {
    uVar1 = 0xffffffff;
    errnoSet(DAT_300c2d14);
  }
  else {
    semTake(*DAT_300c2d5c,0xffffffff);
    if (*DAT_300c2d48 < *DAT_300c2d40) {
      *param_1 = *DAT_300c2d48 + 1;
      *DAT_300c2d48 = *DAT_300c2d48 + 1;
    }
    else {
      uVar1 = 0xffffffff;
      errnoSet(DAT_300c2d78);
    }
    semGive(*DAT_300c2d5c);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * erfTypeAllocate @ 0x300C26C0  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: errnoSet, semGive, semTake
 * Вызывают: fsEventUtilLibInit, xbdInit
 * Константы: 0xFFFFFFFF, 0x300C26C0
 * Данные: DAT_300c2d14, DAT_300c2d44, DAT_300c2d48, DAT_300c2d54, DAT_300c2d60, DAT_300c2d7c
 * ---------------------------------------------------------------- */
undefined4 erfTypeAllocate(int param_1,short *param_2)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  short *psVar4;
  undefined4 uVar5;
  
  piVar2 = DAT_300c2d54;
  uVar5 = 0;
  if ((param_1 < (int)(*DAT_300c2d48 + 1)) && (param_2 != (short *)0x0)) {
    semTake(*(undefined4 *)(*DAT_300c2d54 + param_1 * 4),0xffffffff);
    iVar3 = *DAT_300c2d60;
    uVar1 = *(ushort *)(iVar3 + param_1 * 2);
    if (uVar1 < *DAT_300c2d44) {
      *param_2 = uVar1 + 3;
      psVar4 = (short *)(iVar3 + param_1 * 2);
      *psVar4 = *psVar4 + 1;
    }
    else {
      uVar5 = 0xffffffff;
      errnoSet(DAT_300c2d7c);
    }
    semGive(*(undefined4 *)(*piVar2 + param_1 * 4));
  }
  else {
    uVar5 = 0xffffffff;
    errnoSet(DAT_300c2d14);
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * erfCategoryQueueCreate @ 0x300C276C  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300c1ff8, errnoSet, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x300C276C
 * Данные: DAT_300c2d14, DAT_300c2d48, DAT_300c2d54, DAT_300c2d70, DAT_300c2d80
 * ---------------------------------------------------------------- */
undefined4 erfCategoryQueueCreate(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = DAT_300c2d54;
  uVar4 = 0;
  if ((((param_1 < (int)(*DAT_300c2d48 + 1)) && (0 < param_2)) && (-1 < param_3)) &&
     (param_3 < 0x100)) {
    semTake(*(undefined4 *)(*DAT_300c2d54 + param_1 * 4),0xffffffff);
    iVar3 = *DAT_300c2d70;
    if (*(int *)(iVar3 + param_1 * 4) == 0) {
      iVar2 = FUN_300c1ff8(param_2,param_3,param_1);
      *(int *)(iVar3 + param_1 * 4) = iVar2;
      if (iVar2 == -1) {
        uVar4 = 0xffffffff;
        *(undefined4 *)(iVar3 + param_1 * 4) = 0;
      }
    }
    else {
      uVar4 = 0xffffffff;
      errnoSet(DAT_300c2d80);
    }
    semGive(*(undefined4 *)(*piVar1 + param_1 * 4));
  }
  else {
    uVar4 = 0xffffffff;
    errnoSet(DAT_300c2d14);
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * erfCategoriesAvailable @ 0x300C2834  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C2834
 * Данные: DAT_300c2d40, DAT_300c2d48
 * ---------------------------------------------------------------- */
short erfCategoriesAvailable(void)

{
  return *DAT_300c2d40 - *DAT_300c2d48;
}

/* ----------------------------------------------------------------
 * erfTypesAvailable @ 0x300C2854  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C2854
 * Данные: DAT_300c2d38, DAT_300c2d44, DAT_300c2d60
 * ---------------------------------------------------------------- */
short erfTypesAvailable(int param_1)

{
  short sVar1;
  
  if (param_1 < (int)(uint)*DAT_300c2d38) {
    sVar1 = *DAT_300c2d44 - *(short *)(*DAT_300c2d60 + param_1 * 2);
  }
  else {
    sVar1 = 0;
  }
  return sVar1;
}

/* ----------------------------------------------------------------
 * FUN_300c2898 @ 0x300C2898  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: errnoSet, memcpy, semGive, spinLockIsrGive, spinLockIsrTake
 * Вызывают: FUN_300c2958
 * Константы: 0xFFFFFFFF, 0x300C2898
 * Данные: DAT_300c2d14, DAT_300c2d4c, DAT_300c2d84
 * ---------------------------------------------------------------- */
undefined4 FUN_300c2898(ushort *param_1,void *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar1 = DAT_300c2d4c;
  uVar5 = 0;
  if ((param_1 == (ushort *)0x0) || (param_2 == (void *)0x0)) {
    errnoSet(DAT_300c2d14);
    uVar5 = 0xffffffff;
  }
  else {
    spinLockIsrTake(DAT_300c2d4c);
    uVar4 = (uint)param_1[2];
    if (uVar4 + 1 == (uint)*param_1) {
      uVar2 = 0;
    }
    else {
      uVar2 = uVar4 + 1;
    }
    if (param_1[1] == uVar2) {
      errnoSet(DAT_300c2d84);
      uVar5 = 0xffffffff;
      spinLockIsrGive(uVar1);
    }
    else {
      memcpy(param_1 + uVar4 * 6 + 8,param_2,0xc);
      if (param_1[2] + 1 == (uint)*param_1) {
        uVar3 = 0;
      }
      else {
        uVar3 = param_1[2] + 1;
      }
      param_1[2] = uVar3;
      spinLockIsrGive(uVar1);
      semGive(*(undefined4 *)(param_1 + 4));
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * FUN_300c2958 @ 0x300C2958  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300c2898, errnoSet
 * Вызывают: erfEventRaise
 * Константы: 0x300C2958, 0xFFFFFFFF
 * Данные: DAT_300c2d14, DAT_300c2d38, DAT_300c2d3c, DAT_300c2d6c, DAT_300c2d70
 * ---------------------------------------------------------------- */
undefined4 FUN_300c2958(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 local_14;
  undefined2 local_12;
  int local_10;
  int local_c;
  
  if (((param_1 < (int)(uint)*DAT_300c2d38) && (param_2 < (int)(uint)*DAT_300c2d3c)) &&
     ((param_4 == 0 || (param_3 != 0)))) {
    local_14 = (undefined2)param_1;
    local_12 = (undefined2)param_2;
    iVar2 = *(int *)(*DAT_300c2d70 + param_1 * 4);
    if (iVar2 == 0) {
      iVar2 = *DAT_300c2d6c;
    }
    local_10 = param_3;
    local_c = param_4;
    uVar1 = FUN_300c2898(iVar2,&local_14);
  }
  else {
    uVar1 = 0xffffffff;
    errnoSet(DAT_300c2d14);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300c29e8 @ 0x300C29E8  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: erfEventRaise
 * Константы: 0x300C29E8
 * Данные: DAT_300c2d3c, DAT_300c2d50
 * ---------------------------------------------------------------- */
int FUN_300c29e8(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = -1;
  param_2 = param_1 * (uint)*DAT_300c2d3c + param_2;
  iVar3 = *DAT_300c2d50;
  iVar1 = *(int *)(iVar3 + param_2 * 4);
  iVar5 = 0;
  while ((iVar2 = iVar1, iVar2 != 0 && (iVar4 == -1))) {
    if (iVar2 == param_3) {
      iVar4 = 0;
      iVar1 = iVar2;
      if (iVar5 == 0) {
        *(undefined4 *)(iVar3 + param_2 * 4) = *(undefined4 *)(iVar2 + 0xc);
      }
      else {
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
      }
    }
    else {
      iVar1 = *(int *)(iVar2 + 0xc);
      iVar5 = iVar2;
    }
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * FUN_300c2a64 @ 0x300C2A64  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: erfEventRaise
 * Константы: 0x300C2A64
 * Данные: DAT_300c2d3c, DAT_300c2d50
 * ---------------------------------------------------------------- */
undefined4 FUN_300c2a64(int param_1,int param_2)

{
  return *(undefined4 *)(*DAT_300c2d50 + (param_1 * (uint)*DAT_300c2d3c + param_2) * 4);
}

/* ----------------------------------------------------------------
 * erfEventRaise @ 0x300C2A80  (примерный размер ~416 байт)
 * Модуль: data | Вызывают: 11 | Вызывает: 7
 * Вызывает: FUN_300c2958, FUN_300c29e8, FUN_300c2a64, errnoSet, free, semGive, semTake
 * Вызывают: FUN_300c2cc0, FUN_300dddf8, FUN_300de834, FUN_300decb0, FUN_300deef8, fsPathAddedEventRaise, xbdBlkDevCreate, xbdBlkDevDelete, xbdPartitionDevCreate, xbdRamDiskDevCreate
 *           ...
 * Константы: 0x300C2A80, 0xFFFFFFFF
 * Данные: DAT_300c2d14, DAT_300c2d38, DAT_300c2d3c, DAT_300c2d54, DAT_300c2d88
 * ---------------------------------------------------------------- */
int erfEventRaise(int param_1,int param_2,int param_3,int param_4,code *param_5)

{
  ushort uVar1;
  ushort *__ptr;
  ushort *puVar2;
  int iVar3;
  ushort *puVar4;
  undefined2 local_28;
  
  iVar3 = 0;
  if ((((param_1 < (int)(uint)*DAT_300c2d38) && (param_2 < (int)(uint)*DAT_300c2d3c)) &&
      (param_3 < 2)) && ((param_5 == (code *)0x0 || (param_4 != 0)))) {
    if (param_3 == 1) {
      semTake(*(undefined4 *)(*DAT_300c2d54 + param_1 * 4),0xffffffff);
      __ptr = (ushort *)FUN_300c2a64(param_1,0);
      local_28 = 0;
      puVar2 = (ushort *)FUN_300c2a64(param_1,param_2);
      do {
        puVar4 = puVar2;
        if (__ptr == (ushort *)0x0) {
          if (puVar4 == (ushort *)0x0) {
            semGive(*(undefined4 *)(*DAT_300c2d54 + param_1 * 4));
            if (param_5 == (code *)0x0) {
              return iVar3;
            }
            if (param_4 == 0) {
              return iVar3;
            }
            (*param_5)(param_4);
            return iVar3;
          }
        }
        else {
          do {
            puVar2 = *(ushort **)(__ptr + 6);
            if ((*(code **)(__ptr + 2) != (code *)0x0) &&
               (uVar1 = *__ptr,
               (**(code **)(__ptr + 2))(param_1,param_2,param_4,*(undefined4 *)(__ptr + 4)),
               (uVar1 & 1) != 0)) {
              iVar3 = FUN_300c29e8(param_1,local_28,__ptr);
              if (iVar3 == 0) {
                free(__ptr);
              }
              else {
                errnoSet(DAT_300c2d88);
              }
            }
            __ptr = puVar2;
          } while (puVar2 != (ushort *)0x0);
        }
        local_28 = (undefined2)param_2;
        puVar2 = (ushort *)0x0;
        __ptr = puVar4;
      } while( true );
    }
    iVar3 = FUN_300c2958(param_1,param_2,param_4,param_5);
  }
  else {
    iVar3 = -1;
    errnoSet(DAT_300c2d14);
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_300c2c20 @ 0x300C2C20  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: errnoSet, memcpy, spinLockIsrGive, spinLockIsrTake
 * Вызывают: FUN_300c2cc0
 * Константы: 0xFFFFFFFF, 0x300C2C20
 * Данные: DAT_300c2d14, DAT_300c2d4c, DAT_300c2d8c
 * ---------------------------------------------------------------- */
undefined4 FUN_300c2c20(ushort *param_1,void *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_300c2d4c;
  uVar2 = 0;
  if ((param_1 == (ushort *)0x0) || (param_2 == (void *)0x0)) {
    errnoSet(DAT_300c2d14);
    uVar2 = 0xffffffff;
  }
  else {
    spinLockIsrTake(DAT_300c2d4c);
    if ((uint)param_1[2] == (uint)param_1[1]) {
      errnoSet(DAT_300c2d8c);
      uVar2 = 0xffffffff;
    }
    else {
      memcpy(param_2,param_1 + (uint)param_1[1] * 6 + 8,0xc);
      if (param_1[1] + 1 == (uint)*param_1) {
        param_1[1] = 0;
      }
      else {
        param_1[1] = param_1[1] + 1;
      }
    }
    spinLockIsrGive(uVar1);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300c2cc0 @ 0x300C2CC0  (примерный размер ~208 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300c2c20, erfEventRaise, semTake
 * Константы: 0x300C2CC0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void FUN_300c2cc0(int param_1)

{
  int iVar1;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined4 local_18;
  undefined4 local_14;
  
  do {
    do {
      semTake(*(undefined4 *)(param_1 + 8),0xffffffff);
      iVar1 = FUN_300c2c20(param_1,&local_1c);
    } while (iVar1 == -1);
    erfEventRaise(local_1c,local_1a,1,local_18,local_14);
  } while( true );
}

/* ----------------------------------------------------------------
 * fpTypeGet @ 0x300C2D90  (примерный размер ~420 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300c4f48
 * Константы: 0x300C2D90, 0x7FFFFFFF, 0x80000000
 * Данные: DAT_300c2f24, DAT_300c2f28, DAT_300c2f2c, DAT_300c2f30
 * ---------------------------------------------------------------- */
uint * fpTypeGet(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  uint local_14;
  uint local_10;
  
  if (((param_2 & 0x7fffffff) == 0) && (param_1 == 0)) {
    if (param_3 != (uint *)0x0) {
      *param_3 = 0;
      param_3[1] = param_2;
    }
    return (uint *)0x0;
  }
  uVar1 = DAT_300c2f24 & param_2 >> 0x14;
  if (uVar1 == DAT_300c2f24) {
    if (param_3 != (uint *)0x0) {
      *param_3 = param_1;
      param_3[1] = param_2;
    }
    bVar3 = (param_2 & DAT_300c2f28) == 0;
    if ((bVar3) && (bVar3 = param_1 == 0, bVar3)) {
      param_3 = (uint *)0x3;
    }
    if (bVar3) {
      return param_3;
    }
    return (uint *)&UndefinedInstruction;
  }
  if (param_3 == (uint *)0x0) {
    return (uint *)0x1;
  }
  bVar3 = false;
  iVar2 = uVar1 - DAT_300c2f2c;
  if (iVar2 < 0) {
    local_10 = param_2 & 0x80000000;
    local_14 = 0;
  }
  else {
    local_14 = param_1;
    local_10 = param_2;
    if (iVar2 < 0x14) {
      if ((param_1 != 0) || ((param_2 & ~*(uint *)(DAT_300c2f30 + iVar2 * -4 + 0x50)) != 0)) {
        local_14 = 0;
        bVar3 = true;
        local_10 = param_2 & *(uint *)(DAT_300c2f30 + iVar2 * -4 + 0x50);
      }
      goto LAB_300c2ef8;
    }
    if (iVar2 == 0x14) {
      if (param_1 == 0) goto LAB_300c2ef8;
      local_14 = 0;
    }
    else {
      if ((0x33 < iVar2) ||
         (uVar1 = *(uint *)(DAT_300c2f30 + iVar2 * -4 + 0xd0), (param_1 & ~uVar1) == 0))
      goto LAB_300c2ef8;
      local_14 = param_1 & uVar1;
    }
  }
  bVar3 = true;
LAB_300c2ef8:
  *param_3 = local_14;
  param_3[1] = local_10;
  return (uint *)(!bVar3 + 1);
}

/* ----------------------------------------------------------------
 * oprintf @ 0x300C3F6C  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 21 | Вызывает: 1
 * Вызывает: fioFormatV
 * Вызывают: FUN_300a1ce4, FUN_300a1d58, FUN_300a1db4, FUN_300a1df0, FUN_300a1f60, FUN_300a2038, FUN_300a2060, FUN_300a20d4, FUN_300a2114, FUN_300a21d8
 *           ...
 * Константы: 0x300C3F6C
 * Данные: DAT_300c43e8
 * ---------------------------------------------------------------- */
void oprintf(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_4;
  
  if (param_1 == 0) {
    param_2 = 1;
    param_1 = DAT_300c43e8;
  }
  uStack_4 = param_4;
  fioFormatV(param_3,&uStack_4,param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * printErr @ 0x300C3FA8  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 74 | Вызывает: 1
 * Вызывает: fioFormatV
 * Вызывают: FUN_300a5fe4, FUN_300a62bc, FUN_300a6470, FUN_300a6550, FUN_300a660c, FUN_300a66cc, FUN_300a6a38, FUN_300a6db8, FUN_300f9220, FUN_300f9b38
 *           ...
 * Константы: 0x300C3FA8
 * Данные: DAT_300c43e8
 * ---------------------------------------------------------------- */
void printErr(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  fioFormatV(param_1,&uStack_c,DAT_300c43e8,2);
  return;
}

/* ----------------------------------------------------------------
 * printExc @ 0x300C4004  (примерный размер ~668 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 5
 * Вызывает: __udiv32, intContext, sprintf, taskIdSelf, taskUnsafe
 * Вызывают: FUN_300a7c70, FUN_300a830c
 * Константы: 0x300C4004
 * Данные: DAT_300c43f0, DAT_300c43f4, DAT_300c43f8, DAT_300c43fc, DAT_300c4400, DAT_300c4404, DAT_300c4408, DAT_300c440c
 * ---------------------------------------------------------------- */
void printExc(char *param_1,char *param_2,char *param_3,char *param_4,char *param_5,char *param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  code *pcVar9;
  char *pcVar10;
  uint local_28;
  
  iVar2 = intContext();
  piVar1 = DAT_300c4400;
  if (((iVar2 == 0) && (*DAT_300c43f0 != 0)) && (*DAT_300c43f4 != 1)) {
    pcVar9 = (code *)*DAT_300c43f8;
    pcVar8 = param_1;
    pcVar5 = param_2;
    pcVar6 = param_3;
    pcVar7 = param_4;
    pcVar10 = param_5;
    if (pcVar9 == (code *)0x0) {
      if (*DAT_300c43fc == 0) goto LAB_300c406c;
      pcVar9 = (code *)*DAT_300c43fc;
      if (pcVar9 == (code *)0x0) {
        return;
      }
      pcVar8 = DAT_300c440c;
      pcVar5 = param_1;
      pcVar6 = param_2;
      pcVar7 = param_3;
      pcVar10 = param_4;
      param_6 = param_5;
      if (*DAT_300c4408 != 0) {
        pcVar5 = (char *)taskIdSelf();
        pcVar9 = (code *)*DAT_300c43fc;
        pcVar8 = (char *)*DAT_300c4408;
        pcVar6 = param_1;
        pcVar7 = param_2;
        pcVar10 = param_3;
        param_6 = param_4;
      }
    }
    (*pcVar9)(pcVar8,pcVar5,pcVar6,pcVar7,pcVar10,param_6);
  }
  else {
LAB_300c406c:
    if (*DAT_300c4400 != 0) {
      if ((code *)DAT_300c4400[8] == (code *)0x0) {
        iVar2 = -1;
      }
      else {
        iVar2 = (*(code *)DAT_300c4400[8])();
      }
      iVar3 = __udiv32(*DAT_300c4404,iVar2);
      iVar3 = iVar2 * iVar3;
      if ((((code *)piVar1[6] != (code *)0x0) &&
          (iVar4 = (*(code *)piVar1[6])(0,iVar3,&local_28), iVar4 != -1)) &&
         ((local_28 & 0x3f) == 5)) {
        *(int *)(*DAT_300c43f0 + 0xac) = *(int *)(*DAT_300c43f0 + 0xac) + 1;
        if ((code *)piVar1[5] != (code *)0x0) {
          (*(code *)piVar1[5])(0,iVar3,iVar2,0x3f,7);
        }
        pcVar8 = (char *)*DAT_300c4404;
        iVar4 = sprintf(pcVar8,param_1,param_2,param_3,param_4,param_5,param_6);
        *DAT_300c4404 = (int)(pcVar8 + iVar4);
        if ((code *)piVar1[5] != (code *)0x0) {
          (*(code *)piVar1[5])(0,iVar3,iVar2,0x3f,5);
        }
        taskUnsafe();
        return;
      }
    }
    piVar1 = DAT_300c4404;
    pcVar8 = (char *)*DAT_300c4404;
    iVar2 = sprintf(pcVar8,param_1,param_2,param_3,param_4,param_5,param_6);
    *piVar1 = (int)(pcVar8 + iVar2);
  }
  return;
}

/* ----------------------------------------------------------------
 * floatInit @ 0x300C442C  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrIosExtraInit
 * Константы: 0x300C442C
 * Данные: DAT_300c53a4, DAT_300c53a8, DAT_300c53ac, DAT_300c53b0
 * ---------------------------------------------------------------- */
void floatInit(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_300c53b0;
  *DAT_300c53a4 = DAT_300c53ac;
  *DAT_300c53a8 = uVar1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300c4448 @ 0x300C4448  (примерный размер ~292 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: __floatsidf, __muldf3, _d_feq, _d_fngt, modf
 * Вызывают: FUN_300c4638
 * Константы: 0x300C4448
 * Данные: DAT_300c53b4, DAT_300c53b8
 * ---------------------------------------------------------------- */
byte * FUN_300c4448(undefined4 param_1,undefined4 param_2,int *param_3,byte *param_4,byte *param_5,
                   int param_6,int *param_7)

{
  byte bVar1;
  int iVar2;
  double *__iptr;
  undefined8 uVar3;
  double in_stack_ffffffcc;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar3 = CONCAT44(local_28,local_2c);
  iVar2 = _d_feq(param_1,param_2,0);
  if (iVar2 == 0) {
    __iptr = (double *)__muldf3(param_1,param_2,0,DAT_300c53b4);
    modf(in_stack_ffffffcc,__iptr);
  }
  else {
    uVar3 = __floatsidf(param_6 + -0x30);
  }
  local_28 = (undefined4)((ulonglong)uVar3 >> 0x20);
  local_2c = (undefined4)uVar3;
  iVar2 = _d_fngt(local_2c,local_28,0,DAT_300c53b8);
  if (iVar2 == 0) {
    while( true ) {
      if (*param_5 == 0x2e) {
        param_5 = param_5 + -1;
      }
      bVar1 = *param_5;
      *param_5 = bVar1 + 1;
      if ((byte)(bVar1 + 1) < 0x3a) {
        return param_4;
      }
      *param_5 = 0x30;
      if (param_5 == param_4) break;
      param_5 = param_5 + -1;
    }
    if (param_3 == (int *)0x0) {
      param_5[-1] = 0x31;
      param_4 = param_4 + -1;
    }
    else {
      *param_5 = 0x31;
      *param_3 = *param_3 + 1;
    }
  }
  else if (*param_7 != 0) {
    while( true ) {
      if (*param_5 == 0x2e) {
        param_5 = param_5 + -1;
      }
      if (*param_5 != 0x30) break;
      if (param_5 == param_4) {
        *param_7 = 0;
      }
      param_5 = param_5 + -1;
    }
  }
  return param_4;
}

/* ----------------------------------------------------------------
 * FUN_300c456c @ 0x300C456C  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: __div32, __rem32
 * Вызывают: FUN_300c4638
 * Константы: 0x300C456C
 * ---------------------------------------------------------------- */
char * FUN_300c456c(undefined1 *param_1,int param_2,undefined1 param_3)

{
  char cVar1;
  char *pcVar2;
  undefined1 uVar3;
  char *pcVar4;
  char *pcVar5;
  char local_16 [2];
  
  *param_1 = param_3;
  if (param_2 < 0) {
    param_2 = -param_2;
    uVar3 = 0x2d;
  }
  else {
    uVar3 = 0x2b;
  }
  pcVar2 = param_1 + 2;
  param_1[1] = uVar3;
  pcVar4 = &stack0xffffffec;
  if (param_2 < 10) {
    *pcVar2 = '0';
    pcVar2 = param_1 + 4;
    param_1[3] = (char)param_2 + '0';
  }
  else {
    do {
      pcVar5 = pcVar4;
      cVar1 = __rem32(param_2,10);
      pcVar4 = pcVar5 + -1;
      *pcVar4 = cVar1 + '0';
      param_2 = __div32(param_2,10);
    } while (9 < param_2);
    pcVar5 = pcVar5 + -2;
    *pcVar5 = (char)param_2 + '0';
    for (; pcVar5 < &stack0xffffffec; pcVar5 = pcVar5 + 1) {
      *pcVar2 = *pcVar5;
      pcVar2 = pcVar2 + 1;
    }
  }
  return pcVar2;
}

/* ----------------------------------------------------------------
 * FUN_300c4638 @ 0x300C4638  (примерный размер ~2320 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 10
 * Вызывает: FUN_300c4448, FUN_300c456c, __adddf3, __divdf3, __fixdfsi, __muldf3, _d_feq, _d_fne, _d_fnlt, modf
 * Вызывают: FUN_300c4f48
 * Константы: 0x300C4638
 * Данные: DAT_300c53b4, DAT_300c54b0, DAT_300c54b4, DAT_300c54b8, DAT_300c54bc
 * ---------------------------------------------------------------- */
int FUN_300c4638(double *param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                uint *param_6,byte *param_7,byte *param_8)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  double *pdVar4;
  int iVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined8 uVar10;
  byte *in_stack_ffffff78;
  uint in_stack_ffffff7c;
  byte local_74;
  int local_70;
  byte *local_6c;
  int local_68;
  int local_64;
  int local_5c;
  double *local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  double *local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_70 = 0;
  iVar3 = _d_fnlt(param_1,param_2,0);
  *param_6 = (uint)(iVar3 == 0);
  modf((double)CONCAT44(in_stack_ffffff7c,in_stack_ffffff78),param_1);
  uVar1 = local_4c;
  uVar6 = local_50;
  local_5c = 0;
  local_30 = local_50;
  local_2c = local_4c;
  iVar3 = _d_feq(local_50,local_4c,0);
  if (iVar3 == 0) {
    local_5c = 1;
  }
  pbVar7 = (byte *)((int)param_7 + 1);
  local_6c = param_8 + -1;
  local_30 = uVar6;
  local_2c = uVar1;
  iVar3 = _d_feq(uVar6,uVar1,0);
  uVar6 = DAT_300c53b4;
  if (iVar3 == 0) {
    local_30 = DAT_300c54b0;
    local_2c = DAT_300c54b4;
    do {
      local_38._0_4_ = (double *)0x0;
      local_38._4_4_ = uVar6;
      uVar10 = __divdf3(local_50,local_4c,0,uVar6);
      local_44 = (undefined4)((ulonglong)uVar10 >> 0x20);
      pdVar4 = (double *)uVar10;
      local_48 = pdVar4;
      local_38._0_4_ = pdVar4;
      local_38._4_4_ = local_44;
      modf((double)CONCAT44(in_stack_ffffff7c,in_stack_ffffff78),pdVar4);
      local_38._0_4_ = (double *)local_30;
      local_38._4_4_ = local_2c;
      local_58 = pdVar4;
      local_54 = extraout_r1_00;
      local_48 = pdVar4;
      local_40._0_4_ = pdVar4;
      local_40 = __adddf3();
      local_48 = (double *)0x0;
      local_44 = uVar6;
      local_38 = local_40;
      uVar10 = __muldf3((int)local_40,(int)((ulonglong)local_40 >> 0x20),0,uVar6);
      local_40 = uVar10;
      cVar2 = __fixdfsi();
      *local_6c = cVar2 + 0x30;
      local_70 = local_70 + 1;
      local_48 = (double *)0x0;
      local_44 = 0;
      local_6c = local_6c + -1;
      iVar3 = _d_fne(local_50,local_4c,0);
    } while (iVar3 != 0);
  }
  local_68 = 0;
  if (param_5 != 0x65) {
    pbVar8 = pbVar7;
    if (param_5 < 0x66) {
      if (param_5 == 0x45) goto LAB_300c49c0;
      if (param_5 != 0x47) goto LAB_300c4f30;
    }
    else {
      if (param_5 == 0x66) {
        if (local_70 == 0) {
          *pbVar7 = 0x30;
          pbVar8 = (byte *)((int)param_7 + 2);
        }
        else {
          while (local_6c = local_6c + 1, local_6c < param_8) {
            *pbVar8 = *local_6c;
            pbVar8 = pbVar8 + 1;
          }
        }
        if (param_3 != 0 || param_4 != 0) {
          *pbVar8 = 0x2e;
          pbVar8 = pbVar8 + 1;
        }
        iVar3 = _d_feq(param_1,extraout_r1,0);
        param_7 = pbVar7;
        if (iVar3 == 0) {
          uVar6 = extraout_r1;
          pbVar9 = pbVar8;
          if (param_3 != 0) {
            do {
              param_1 = (double *)__muldf3(param_1,uVar6,0,DAT_300c53b4);
              modf((double)CONCAT44(in_stack_ffffff7c,in_stack_ffffff78),param_1);
              cVar2 = __fixdfsi(local_58,local_54);
              pbVar8 = pbVar9 + 1;
              *pbVar9 = cVar2 + 0x30;
              param_3 = param_3 + -1;
              uVar6 = extraout_r1_01;
              if (param_3 == 0) break;
              iVar3 = _d_fne(param_1,extraout_r1_01,0);
              pbVar9 = pbVar8;
            } while (iVar3 != 0);
          }
          iVar3 = _d_feq(param_1,uVar6,0);
          if (iVar3 == 0) {
            param_7 = (byte *)FUN_300c4448(param_1,uVar6,0,pbVar7,pbVar8 + -1,0,param_6);
          }
        }
        for (; pbVar7 = pbVar8, pbVar8 = param_7, param_3 != 0; param_3 = param_3 + -1) {
          *pbVar7 = 0x30;
          pbVar8 = pbVar7 + 1;
        }
        goto LAB_300c4f30;
      }
      if (param_5 != 0x67) goto LAB_300c4f30;
    }
    param_3 = param_3 + (uint)(param_3 == 0);
    if (local_70 <= param_3) {
      if (local_70 == 0) {
        iVar3 = _d_feq(param_1,extraout_r1,0);
        if (iVar3 == 0) {
          iVar3 = _d_fnlt(param_1,extraout_r1,DAT_300c54bc,DAT_300c54b8);
          if (iVar3 == 0) goto LAB_300c4cfc;
        }
        *pbVar7 = 0x30;
        pbVar8 = (byte *)((int)param_7 + 2);
      }
      else {
        while (local_6c = local_6c + 1, local_6c < param_8) {
          param_3 = param_3 + -1;
          *pbVar8 = *local_6c;
          pbVar8 = pbVar8 + 1;
        }
      }
      if ((param_3 == 0) && (param_4 == 0)) {
        local_64 = 0;
      }
      else {
        local_64 = 1;
        *pbVar8 = 0x2e;
        pbVar8 = pbVar8 + 1;
      }
      iVar3 = _d_feq(param_1,extraout_r1,0);
      param_7 = pbVar7;
      if (iVar3 == 0) {
        uVar6 = extraout_r1;
        if (param_3 != 0) {
          if (local_5c == 0) {
            do {
              param_1 = (double *)__muldf3(param_1,uVar6,0,DAT_300c53b4);
              modf((double)CONCAT44(in_stack_ffffff7c,in_stack_ffffff78),param_1);
              cVar2 = __fixdfsi(local_58,local_54);
              pbVar9 = pbVar8 + 1;
              *pbVar8 = cVar2 + 0x30;
              iVar3 = _d_feq(local_58,local_54,0);
              uVar6 = extraout_r1_04;
              pbVar8 = pbVar9;
            } while (iVar3 != 0);
            param_3 = param_3 + -1;
          }
          for (; param_3 != 0; param_3 = param_3 + -1) {
            iVar3 = _d_feq(param_1,uVar6,0);
            if (iVar3 != 0) break;
            param_1 = (double *)__muldf3(param_1,uVar6,0,DAT_300c53b4);
            modf((double)CONCAT44(in_stack_ffffff7c,in_stack_ffffff78),param_1);
            cVar2 = __fixdfsi(local_58,local_54);
            *pbVar8 = cVar2 + 0x30;
            uVar6 = extraout_r1_05;
            pbVar8 = pbVar8 + 1;
          }
        }
        iVar3 = _d_feq(param_1,uVar6,0);
        if (iVar3 == 0) {
          param_7 = (byte *)FUN_300c4448(param_1,uVar6,0,pbVar7,pbVar8 + -1,0,param_6);
        }
      }
      pbVar7 = pbVar8;
      pbVar8 = param_7;
      if (param_4 == 0) {
        if (local_64 != 0) {
          do {
            if (pbVar7 <= param_7) break;
            pbVar7 = pbVar7 + -1;
          } while (*pbVar7 == 0x30);
          if (*pbVar7 != 0x2e) {
            pbVar7 = pbVar7 + 1;
          }
        }
      }
      else {
        for (; param_3 != 0; param_3 = param_3 + -1) {
          *pbVar7 = 0x30;
          pbVar7 = pbVar7 + 1;
        }
      }
      goto LAB_300c4f30;
    }
LAB_300c4cfc:
    param_3 = param_3 + -1;
    param_5 = param_5 + -2;
    local_68 = 1;
  }
LAB_300c49c0:
  uVar6 = extraout_r1;
  if (local_70 == 0) {
    iVar3 = _d_feq(param_1,extraout_r1,0);
    if (iVar3 == 0) {
      local_70 = -1;
      while( true ) {
        param_1 = (double *)__muldf3(param_1,uVar6,0,DAT_300c53b4);
        modf((double)CONCAT44(in_stack_ffffff7c,in_stack_ffffff78),param_1);
        uVar6 = local_54;
        pdVar4 = local_58;
        iVar3 = _d_fne(local_58,local_54,0);
        if (iVar3 != 0) break;
        local_70 = local_70 + -1;
        uVar6 = extraout_r1_02;
      }
      cVar2 = __fixdfsi(pdVar4,uVar6);
      local_74 = cVar2 + 0x30;
      uVar6 = extraout_r1_02;
    }
    else {
      local_74 = 0x30;
    }
    pbVar8 = (byte *)((int)param_7 + 2);
    *pbVar7 = local_74;
    if (param_3 != 0 || param_4 != 0) {
      *pbVar8 = 0x2e;
      pbVar8 = (byte *)((int)param_7 + 3);
    }
  }
  else {
    local_6c = local_6c + 1;
    *pbVar7 = *local_6c;
    pbVar8 = (byte *)((int)param_7 + 2);
    if ((param_3 == 0) && (param_4 == 0)) {
LAB_300c4a40:
      local_6c = local_6c + 1;
      param_7 = pbVar7;
      if (local_6c < param_8) {
        in_stack_ffffff7c = (uint)*local_6c;
        uVar6 = 0;
        param_1 = (double *)0x0;
        in_stack_ffffff78 = pbVar8 + -1;
        param_7 = (byte *)FUN_300c4448(0,0,&local_70,pbVar7,in_stack_ffffff78,in_stack_ffffff7c,
                                       param_6);
      }
    }
    else {
      *pbVar8 = 0x2e;
      pbVar8 = (byte *)((int)param_7 + 3);
      if (param_3 == 0) goto LAB_300c4a40;
      do {
        local_6c = local_6c + 1;
        if (param_8 <= local_6c) break;
        param_3 = param_3 + -1;
        *pbVar8 = *local_6c;
        pbVar8 = pbVar8 + 1;
      } while (param_3 != 0);
      param_7 = pbVar7;
      if (param_3 == 0) goto LAB_300c4a40;
    }
    local_70 = local_70 + -1;
    pbVar7 = param_7;
  }
  param_7 = pbVar7;
  iVar5 = _d_feq(param_1,uVar6,0);
  pbVar7 = pbVar8;
  iVar3 = param_3;
  if (iVar5 == 0) {
    while (pbVar8 = pbVar7, iVar3 != 0) {
      param_1 = (double *)__muldf3(param_1,uVar6,0,DAT_300c53b4);
      modf((double)CONCAT44(in_stack_ffffff7c,in_stack_ffffff78),param_1);
      cVar2 = __fixdfsi(local_58,local_54);
      pbVar8 = pbVar7 + 1;
      *pbVar7 = cVar2 + 0x30;
      param_3 = param_3 + -1;
      uVar6 = extraout_r1_03;
      if (param_3 == 0) break;
      iVar3 = _d_fne(param_1,extraout_r1_03,0);
      pbVar7 = pbVar8;
    }
    iVar3 = _d_feq(param_1,uVar6,0);
    if (iVar3 == 0) {
      param_7 = (byte *)FUN_300c4448(param_1,uVar6,&local_70,param_7,pbVar8 + -1,0,param_6);
    }
  }
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *pbVar8 = 0x30;
    pbVar8 = pbVar8 + 1;
  }
  if ((local_68 != 0) && (param_4 == 0)) {
    do {
      if (pbVar8 <= param_7) break;
      pbVar8 = pbVar8 + -1;
    } while (*pbVar8 == 0x30);
    if (*pbVar8 == 0x2e) {
      pbVar8 = pbVar8 + -1;
    }
    pbVar8 = pbVar8 + 1;
  }
  pbVar7 = (byte *)FUN_300c456c(pbVar8,local_70,param_5);
  pbVar8 = param_7;
LAB_300c4f30:
  param_7 = pbVar8;
  return (int)pbVar7 - (int)param_7;
}

/* ----------------------------------------------------------------
 * FUN_300c4f48 @ 0x300C4F48  (примерный размер ~276 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300c4638, _d_fnlt, fpTypeGet
 * Константы: 0xFFFFFFFD, 0x300C4F48, 0xFFFFFFFC
 * Данные: DAT_300c54c0, DAT_300c54c4
 * ---------------------------------------------------------------- */
undefined4
FUN_300c4f48(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,undefined1 *param_6,undefined4 param_7)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = *param_1 + 0xb & 0xfffffffc;
  *param_1 = uVar1;
  uVar4 = *(undefined4 *)(uVar1 - 8);
  uVar5 = *(undefined4 *)(uVar1 - 4);
  *param_5 = 0;
  iVar2 = fpTypeGet(uVar4,uVar5);
  if (iVar2 == 3) {
    iVar2 = 4;
    puVar3 = DAT_300c54c0;
    do {
      iVar2 = iVar2 + -1;
      *param_6 = *puVar3;
      param_6 = param_6 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 != 0);
    iVar2 = _d_fnlt(uVar4,uVar5,0);
    if (iVar2 == 0) {
      *param_5 = 1;
    }
    uVar4 = 0xfffffffd;
  }
  else {
    iVar2 = fpTypeGet(uVar4,uVar5,0);
    if (iVar2 == 4) {
      iVar2 = 4;
      puVar3 = DAT_300c54c4;
      do {
        iVar2 = iVar2 + -1;
        *param_6 = *puVar3;
        param_6 = param_6 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar2 != 0);
      uVar4 = 0xfffffffd;
    }
    else {
      uVar4 = FUN_300c4638(uVar4,uVar5,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * FUN_300c505c @ 0x300C505C  (примерный размер ~1148 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: __adddf3, __divdf3, __floatsidf, __muldf3, __truncdfsf2, _d_feq
 * Константы: 0xFFFFFFFF, 0x300C505C, 0x80000000
 * Данные: DAT_300c54c8, DAT_300c54d0, DAT_300c54d4
 * ---------------------------------------------------------------- */
bool FUN_300c505c(undefined4 *param_1,int param_2,int param_3,code *param_4,undefined4 param_5,
                 uint *param_6,int *param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  bool bVar14;
  longlong lVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  int local_64;
  int local_60;
  int local_5c;
  undefined4 local_4c;
  uint local_48;
  
  iVar9 = 0;
  uVar10 = *param_6;
  iVar6 = 0;
  iVar7 = 0;
  bVar13 = false;
  if (0 < param_3) {
    bVar13 = (uVar10 & 0xff) == 0x2d;
    if ((bVar13) || ((uVar10 & 0xff) == 0x2b)) {
      iVar9 = 1;
      uVar10 = (*param_4)(param_5);
    }
  }
  local_60 = 0;
  iVar2 = 0;
  bVar14 = false;
  local_5c = 0;
  iVar5 = 0;
  for (; (uVar10 != 0xffffffff && (iVar9 < param_3)); iVar9 = iVar9 + 1) {
    iVar4 = iVar5;
    if ((bVar14) || (uVar10 != 0x2e)) {
      if (9 < uVar10 - 0x30) break;
      iVar11 = uVar10 - 0x30;
      local_5c = local_5c + (uint)bVar14;
      if ((iVar5 != 0) || (iVar11 != 0)) {
        iVar4 = iVar5 + 1;
        if (iVar6 < DAT_300c54c8) {
          iVar6 = iVar6 * 10 + iVar11;
          local_60 = local_60 + 1;
        }
        else {
          iVar12 = DAT_300c54c8;
          if (iVar4 < 0x11) {
            iVar12 = 10;
          }
          if (iVar4 == 0x10 || iVar5 + -0xf < 0 != SBORROW4(iVar4,0x10)) {
            iVar7 = iVar7 * iVar12 + iVar11;
            iVar2 = iVar2 + 1;
          }
        }
      }
    }
    else {
      bVar14 = true;
    }
    uVar10 = (*param_4)(param_5);
    iVar5 = iVar4;
  }
  local_64 = 0;
  bVar14 = false;
  if ((iVar9 < param_3) && ((uVar10 == 0x65 || (uVar10 == 0x45)))) {
    iVar9 = iVar9 + 1;
    uVar10 = (*param_4)(param_5);
    if (param_3 <= iVar9) goto LAB_300c5264;
    bVar14 = uVar10 == 0x2d;
    if ((!bVar14) && (uVar10 != 0x2b)) goto LAB_300c5264;
    while( true ) {
      iVar9 = iVar9 + 1;
      uVar10 = (*param_4)(param_5);
LAB_300c5264:
      if (((uVar10 == 0xffffffff) || (param_3 <= iVar9)) || (9 < uVar10 - 0x30)) break;
      local_64 = local_64 * 10 + uVar10 + -0x30;
    }
  }
  if (iVar9 == 0) {
    bVar13 = false;
  }
  else {
    lVar15 = __floatsidf(iVar6);
    if (iVar2 != 0) {
      uVar16 = __muldf3();
      uVar17 = __floatsidf(iVar7);
      lVar15 = __adddf3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
    }
    if (bVar14) {
      local_64 = -local_64;
    }
    uVar8 = (((iVar5 - local_60) - iVar2) - local_5c) + local_64;
    bVar14 = -1 < (int)uVar8;
    if (!bVar14) {
      uVar8 = -uVar8;
    }
    puVar3 = DAT_300c54d0;
    if (uVar8 != 0) {
      do {
        local_48 = (uint)((ulonglong)lVar15 >> 0x20);
        local_4c = (undefined4)lVar15;
        uVar1 = *puVar3;
        iVar6 = _d_feq(uVar1,puVar3[1],0);
        if (iVar6 != 0) break;
        if ((uVar8 & 1) != 0) {
          if (bVar14) {
            lVar15 = __muldf3(local_4c,local_48,uVar1);
          }
          else {
            lVar15 = __divdf3();
          }
        }
        uVar8 = (int)uVar8 >> 1;
        puVar3 = puVar3 + 2;
      } while (uVar8 != 0);
      if (uVar8 != 0) {
        if (bVar14) {
          lVar15 = (ulonglong)DAT_300c54d4 << 0x20;
        }
        else {
          lVar15 = 0;
        }
      }
    }
    local_48 = (uint)((ulonglong)lVar15 >> 0x20);
    local_4c = (undefined4)lVar15;
    if (bVar13) {
      local_48 = local_48 ^ 0x80000000;
    }
    if (param_1 != (undefined4 *)0x0) {
      if (param_2 == 0x6c) {
        *param_1 = local_4c;
        param_1[1] = local_48;
      }
      else {
        uVar1 = __truncdfsf2(local_4c,local_48);
        *param_1 = uVar1;
      }
    }
    bVar13 = iVar9 != 0;
    *param_6 = uVar10;
    *param_7 = iVar9 + *param_7;
  }
  return bVar13;
}

/* ----------------------------------------------------------------
 * voprintf @ 0x300C54E8  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: fioFormatV
 * Константы: 0x300C54E8
 * Данные: DAT_300c5d88
 * ---------------------------------------------------------------- */
void voprintf(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 == 0) {
    param_2 = 1;
    param_1 = DAT_300c5d88;
  }
  fioFormatV(param_3,param_4,param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * fdprintf @ 0x300C5518  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 28 | Вызывает: 1
 * Вызывает: fioFormatV
 * Вызывают: FUN_300c906c, FUN_300e3428, FUN_300f6ea4, FUN_300f7094, FUN_300f7254, FUN_300f72a4, FUN_300f74f8, FUN_300f7564, FUN_300f7744, FUN_300f7dbc
 *           ...
 * Константы: 0x300C5518
 * Данные: DAT_300c5d88
 * ---------------------------------------------------------------- */
void fdprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  fioFormatV(param_2,&uStack_8,DAT_300c5d88,param_1);
  return;
}

/* ----------------------------------------------------------------
 * vfdprintf @ 0x300C554C  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: fioFormatV
 * Вызывают: FUN_30103378
 * Константы: 0x300C554C
 * Данные: DAT_300c5d88
 * ---------------------------------------------------------------- */
void vfdprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  fioFormatV(param_2,param_3,DAT_300c5d88,param_1);
  return;
}

/* ----------------------------------------------------------------
 * vsprintf @ 0x300C556C  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: fioFormatV
 * Константы: 0x300C556C
 * Данные: DAT_300c5d8c
 * ---------------------------------------------------------------- */
int vsprintf(char *__s,char *__format,__gnuc_va_list __arg)

{
  int iVar1;
  char *local_4;
  
  local_4 = __s;
  iVar1 = fioFormatV(__format,__arg,DAT_300c5d8c,&local_4);
  *local_4 = '\0';
  return iVar1;
}

/* ----------------------------------------------------------------
 * vsnprintf @ 0x300C55A8  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 1
 * Вызывает: fioFormatV
 * Вызывают: FUN_30062e20, FUN_30106c34, QC_gzprintf, exchPrintBuffer, exchvsnprintf, os_snprintf
 * Константы: 0x300C55A8
 * Данные: DAT_300c5d90
 * ---------------------------------------------------------------- */
int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
  int iVar1;
  char *local_18;
  char *local_14;
  
  local_14 = __s + __maxlen;
  local_18 = __s;
  iVar1 = fioFormatV(__format,__arg,DAT_300c5d90,&local_18);
  if (__maxlen != 0) {
    *local_18 = '\0';
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * scanCharSet @ 0x300C5840  (примерный размер ~452 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x300C5840
 * ---------------------------------------------------------------- */
undefined4
scanCharSet(undefined1 *param_1,int param_2,char *param_3,code *param_4,undefined4 param_5,
           uint *param_6,int *param_7)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  char *pcVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  char acStack_125 [257];
  
  pbVar9 = (byte *)(param_3 + 1);
  uVar8 = 0;
  if (*param_3 == '[') {
    bVar11 = *pbVar9 != 0x5e;
    if (!bVar11) {
      pbVar9 = (byte *)(param_3 + 2);
    }
    iVar2 = 0x100;
    if (bVar11) {
      param_3 = (char *)0x0;
    }
    cVar3 = (char)param_3;
    pcVar7 = acStack_125;
    if (!bVar11) {
      cVar3 = '\x01';
    }
    iVar4 = 0x100;
    do {
      pcVar7 = pcVar7 + 1;
      *pcVar7 = cVar3;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    pbVar10 = pbVar9;
    if (*pbVar9 == 0x2d || *pbVar9 == 0x5d) {
      pbVar10 = pbVar9 + 1;
      acStack_125[*pbVar9 + 1] = bVar11;
    }
    do {
      uVar5 = (uint)*pbVar10;
      if ((uVar5 == 0x5d) || (uVar5 == 0)) break;
      if ((uVar5 == 0x2d) && ((uVar8 < pbVar10[1] && (pbVar10[1] != 0x5d)))) {
        pbVar10 = pbVar10 + 1;
        if (uVar8 <= *pbVar10) {
          pcVar7 = acStack_125 + uVar8;
          uVar5 = uVar8;
          do {
            pcVar7 = pcVar7 + 1;
            *pcVar7 = bVar11;
            uVar5 = uVar5 + 1;
          } while ((int)uVar5 <= (int)(uint)*pbVar10);
        }
      }
      else {
        acStack_125[uVar5 + 1] = bVar11;
        uVar8 = (uint)*pbVar10;
      }
      pbVar10 = pbVar10 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (*pbVar10 == 0x5d) {
      uVar8 = *param_6;
      iVar2 = 0;
      bVar11 = uVar8 == 0xffffffff;
      puVar6 = param_1;
      if (!bVar11) {
        do {
          puVar6 = param_1;
          if ((param_2 <= iVar2) || (acStack_125[(uVar8 & 0xff) + 1] == '\0')) break;
          if (param_1 != (undefined1 *)0x0) {
            puVar6 = param_1 + 1;
            *param_1 = (char)uVar8;
          }
          iVar2 = iVar2 + 1;
          uVar8 = (*param_4)(param_5,0xffffffff);
          param_1 = puVar6;
        } while (uVar8 != 0xffffffff);
        bVar11 = iVar2 == 0;
      }
      if (bVar11) {
        uVar1 = 0;
      }
      else {
        if (puVar6 != (undefined1 *)0x0) {
          *puVar6 = 0;
        }
        *param_6 = uVar8;
        uVar1 = 1;
        *param_7 = iVar2 + *param_7;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300c5a04 @ 0x300C5A04  (примерный размер ~640 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __mul64
 * Константы: 0xFFFFFFFF, 0x300C5A04
 * Данные: DAT_300c5d94
 * ---------------------------------------------------------------- */
bool FUN_300c5a04(int param_1,int *param_2,int param_3,int param_4,code *param_5,undefined4 param_6,
                 uint *param_7,int *param_8)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  undefined8 uVar8;
  
  iVar6 = 0;
  bVar7 = false;
  uVar2 = *param_7;
  if ((0 < param_4) && (((uVar2 & 0xff) == 0x2b || (bVar7 = (uVar2 & 0xff) == 0x2d, bVar7)))) {
    iVar6 = 1;
    uVar2 = (*param_5)(param_6,0xffffffff);
  }
  if ((iVar6 < param_4) && (uVar2 == 0x30)) {
    uVar2 = (*param_5)(param_6,0xffffffff);
    if (((iVar6 + 1 < param_4) && ((uVar2 == 0x78 || (uVar2 == 0x58)))) &&
       ((param_1 == 0x10 || (param_1 == 0)))) {
      iVar6 = iVar6 + 2;
      uVar2 = (*param_5)(param_6,0xffffffff);
      param_1 = 0x10;
      goto LAB_300c5b0c;
    }
    iVar3 = 8;
    iVar6 = iVar6 + 1;
  }
  else {
    iVar3 = 10;
  }
  if (param_1 == 0) {
    param_1 = iVar3;
  }
LAB_300c5b0c:
  iVar4 = 0;
  iVar3 = 0;
  for (; (uVar2 != 0xffffffff && (iVar6 < param_4)); iVar6 = iVar6 + 1) {
    bVar1 = *(byte *)(*DAT_300c5d94 + (uVar2 & 0xff));
    if ((bVar1 & 4) == 0) {
      if ((bVar1 & 2) == 0) {
        if ((bVar1 & 1) == 0) break;
        uVar5 = uVar2 - 0x37;
      }
      else {
        uVar5 = uVar2 - 0x57;
      }
    }
    else {
      uVar5 = uVar2 - 0x30;
    }
    if (param_1 <= (int)uVar5) break;
    uVar8 = __mul64(iVar3,iVar4,param_1,param_1 >> 0x1f);
    iVar3 = (uint)uVar8 + uVar5;
    iVar4 = (int)((ulonglong)uVar8 >> 0x20) + ((int)uVar5 >> 0x1f) + (uint)CARRY4((uint)uVar8,uVar5)
    ;
    uVar2 = (*param_5)(param_6,0xffffffff);
  }
  if (iVar6 == 0) {
    bVar7 = false;
  }
  else {
    if (bVar7) {
      bVar7 = iVar3 != 0;
      iVar3 = -iVar3;
      iVar4 = -(iVar4 + (uint)bVar7);
    }
    if (param_2 != (int *)0x0) {
      if (param_3 == 1) {
        *param_2 = iVar3;
        param_2[1] = iVar4;
      }
      else if (param_3 == 0x68) {
        *(short *)param_2 = (short)iVar3;
      }
      else if (param_3 == 0x6c) {
        *param_2 = iVar3;
      }
      else {
        *param_2 = iVar3;
      }
    }
    bVar7 = iVar6 != 0;
    *param_7 = uVar2;
    *param_8 = iVar6 + *param_8;
  }
  return bVar7;
}

/* ----------------------------------------------------------------
 * scanField @ 0x300C5C84  (примерный размер ~924 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: fioScanV
 * Константы: 0x300C5C84, 0x300C5D7C
 * Данные: DAT_300c5d94, DAT_300c5d98
 * ---------------------------------------------------------------- */
undefined4 scanField(undefined4 *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint *in_stack_00000000;
  
  pbVar4 = (byte *)*param_1;
  bVar1 = *pbVar4;
  *in_stack_00000000 = (uint)(bVar1 == 0x2a);
  if ((bVar1 == 0x2a) != 0) {
    pbVar4 = pbVar4 + 1;
  }
  while ((*(byte *)(*DAT_300c5d94 + (uint)*pbVar4) & 4) != 0) {
    pbVar4 = pbVar4 + 1;
  }
  bVar1 = *pbVar4;
  if ((bVar1 == 0x4c) || (bVar1 == 0x68)) {
    pbVar5 = pbVar4 + 1;
  }
  else {
    pbVar5 = pbVar4;
    if ((bVar1 == 0x6c) && (pbVar5 = pbVar4 + 1, pbVar4[1] == 0x6c)) {
      pbVar5 = pbVar4 + 2;
    }
  }
  uVar3 = *pbVar5 - 0x45;
  if (0x33 < uVar3) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x300c5d7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(DAT_300c5d98 + uVar3 * 4))((uint)*pbVar5);
  return uVar2;
}

/* ----------------------------------------------------------------
 * sscanf @ 0x300C6390  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 1
 * Вызывает: fioScanV
 * Вызывают: FUN_300f8b2c, FUN_301208f4, changeFpReg, shellInternalStrToChar, shellInternalStrToFloat, shellInternalStrToInt, shellInternalStrToInt2
 * Константы: 0x300C6390
 * Данные: DAT_300c63fc
 * ---------------------------------------------------------------- */
int sscanf(char *__s,char *__format,...)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined1 auStack_1c [4];
  char *pcStack_10;
  char *local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  pcStack_10 = __s;
  local_c = __format;
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  iVar1 = fioScanV(__format,DAT_300c63fc,&pcStack_10,auStack_1c,&uStack_8);
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300c6400 @ 0x300C6400  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300c701c, vxdbgBpAdd, vxdbgClntRegister
 * Константы: 0x300C6400
 * ---------------------------------------------------------------- */
void FUN_300c6400(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    iVar1 = *param_1;
    *param_1 = (int)param_3;
  }
  else {
    iVar1 = *param_2;
    *param_2 = (int)param_3;
  }
  if (iVar1 == 0) {
    param_1[1] = (int)param_3;
  }
  else {
    *(int **)(iVar1 + 4) = param_3;
  }
  *param_3 = iVar1;
  param_3[1] = (int)param_2;
  param_1[2] = param_1[2] + 1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300c6438 @ 0x300C6438  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300c701c, vxdbgBpAdd
 * Константы: 0x300C6438
 * ---------------------------------------------------------------- */
void FUN_300c6438(int *param_1,int *param_2)

{
  if ((int *)param_2[1] == (int *)0x0) {
    *param_1 = *param_2;
  }
  else {
    *(int *)param_2[1] = *param_2;
  }
  if (*param_2 == 0) {
    param_1[1] = param_2[1];
  }
  else {
    *(int *)(*param_2 + 4) = param_2[1];
  }
  param_1[2] = param_1[2] + -1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300c6470 @ 0x300C6470  (примерный размер ~228 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300c6554, FUN_300c8154
 * Константы: 0x300C6470
 * Данные: DAT_300c73e0, DAT_300c73e4, DAT_300c73e8, DAT_300c73ec, DAT_300c73f0
 * ---------------------------------------------------------------- */
int FUN_300c6470(int param_1,int param_2)

{
  int iVar1;
  
  if (((((code *)*DAT_300c73e0 != (code *)0x0) && ((code *)*DAT_300c73e4 != (code *)0x0)) &&
      (param_2 != 0)) && (*DAT_300c73e8 != param_2)) {
    if (param_1 == param_2) {
      return param_2;
    }
    if (*DAT_300c73ec == 1) {
      iVar1 = (*(code *)*DAT_300c73e4)(param_2);
      if ((iVar1 != -1) && ((*(uint *)(param_2 + 100) & 0x204) == 0)) {
        if (*(code **)(DAT_300c73f0 + 100) == (code *)0x0) {
          return param_2;
        }
        iVar1 = (**(code **)(DAT_300c73f0 + 100))(*(undefined4 *)(param_2 + 0x44));
        if (iVar1 != -1) {
          return param_2;
        }
      }
    }
    else {
      iVar1 = (*(code *)*DAT_300c73e0)(param_2,0);
      if (iVar1 != 0) {
        return param_2;
      }
    }
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * FUN_300c6554 @ 0x300C6554  (примерный размер ~516 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 2
 * Вызывает: FUN_300c6470, usrBreakpointSet
 * Вызывают: FUN_300c7cbc, FUN_300c7fec, FUN_300c8154, vxdbgEnable
 * Константы: 0x300C6554
 * Данные: DAT_300c73e4, DAT_300c73ec, DAT_300c74ac, DAT_300c74b0, DAT_300c74b4, DAT_300c7610, DAT_300c7614
 * ---------------------------------------------------------------- */
void FUN_300c6554(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  bool bVar6;
  
  if (*DAT_300c74ac != 0) {
    iVar4 = *DAT_300c74b0;
    if (param_2 == 0) {
      param_2 = iVar4;
    }
    bVar1 = *(byte *)(param_2 + 0x238);
    iVar2 = 0;
    if ((*DAT_300c73ec != 1) &&
       ((((code *)*DAT_300c73e4 == (code *)0x0 ||
         (iVar2 = (*(code *)*DAT_300c73e4)(*(undefined4 *)(iVar4 + 0x90)), iVar2 == -1)) ||
        (iVar2 = *(int *)(iVar4 + 0x90), (*(uint *)(iVar2 + 100) & 0x204) != 0)))) {
      iVar2 = 0;
    }
    iVar4 = iVar2;
    for (puVar5 = (undefined4 *)*DAT_300c74b4; puVar5 != (undefined4 *)0x0;
        puVar5 = (undefined4 *)*puVar5) {
      bVar6 = (bVar1 & 7) == 0;
      if ((bVar6) &&
         (((((puVar5[6] & 1) != 0 && (puVar5[5] == param_2)) ||
           (((puVar5[6] & 2) != 0 && (puVar5[5] == *(int *)(param_2 + 0x94))))) ||
          (bVar6 = puVar5[5] == 0, bVar6)))) {
        bVar6 = (*(uint *)(param_2 + 0x98) & 2) == 0;
        if (!bVar6) {
          bVar6 = (puVar5[0xb] & 0x14) == 0;
          if (bVar6) {
            bVar6 = *DAT_300c7610 == 0;
          }
          goto LAB_300c666c;
        }
      }
      else {
LAB_300c666c:
        if (!bVar6) {
          param_3 = 0;
        }
      }
      if (bVar6) {
        param_3 = 1;
      }
      if (param_3 == 0) {
LAB_300c66d8:
        if ((puVar5[10] != 0) && ((*(uint *)(*(int *)(param_2 + 0x94) + 100) & 0x204) == 0)) {
          iVar4 = FUN_300c6470(iVar4,*(undefined4 *)(param_1 + 0x94));
          param_3 = *(int *)(param_1 + 0x94);
          usrBreakpointSet(puVar5[3],puVar5[4],param_3,2);
          uVar3 = 0;
LAB_300c6718:
          puVar5[10] = uVar3;
        }
      }
      else if (puVar5[10] == 0) {
        if ((*(uint *)(*(int *)(param_2 + 0x94) + 100) & 0x204) == 0) {
          iVar4 = FUN_300c6470(iVar4,*(int *)(param_2 + 0x94));
          param_3 = *(int *)(param_2 + 0x94);
          usrBreakpointSet(puVar5[3],DAT_300c7614,param_3,2);
          uVar3 = 1;
          goto LAB_300c6718;
        }
      }
      else if (param_3 == 0) goto LAB_300c66d8;
    }
    if (iVar2 != 0) {
      FUN_300c6470(iVar4,iVar2);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * fsEventUtilLibInit @ 0x300C927C  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: erfCategoryAllocate, erfTypeAllocate
 * Вызывают: usrIosExtraInit
 * Константы: 0xFFFFFFFF, 0x300C927C
 * Данные: DAT_300c9464
 * ---------------------------------------------------------------- */
undefined4 fsEventUtilLibInit(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  puVar1 = DAT_300c9464;
  if (*(int *)(DAT_300c9464 + 2) == 0) {
    iVar2 = erfCategoryAllocate(DAT_300c9464);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    iVar2 = erfTypeAllocate(*puVar1,puVar1 + 1);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(puVar1 + 2) = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300c92e0 @ 0x300C92E0  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: erfHandlerUnregister, semGive, strcmp
 * Константы: 0x300C92E0
 * Данные: DAT_300c9464, DAT_300c9468
 * ---------------------------------------------------------------- */
void FUN_300c92e0(uint param_1,uint param_2,char *param_3,undefined4 *param_4)

{
  ushort *puVar1;
  int iVar2;
  
  puVar1 = DAT_300c9464;
  if (((*DAT_300c9464 == param_1) && (DAT_300c9464[1] == param_2)) &&
     (iVar2 = strcmp(param_3,(char *)*param_4), iVar2 == 0)) {
    semGive(param_4[1]);
    erfHandlerUnregister(*puVar1,puVar1[1],DAT_300c9468,param_4);
  }
  return;
}

/* ----------------------------------------------------------------
 * fsPathAddedEventSetup @ 0x300C934C  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: erfHandlerRegister, semBCreate, semDelete
 * Вызывают: xbdCreatePartition, xbdCreatePartitionSz, xbdRamDiskDevCreate
 * Константы: 0x300C934C
 * Данные: DAT_300c9464, DAT_300c9468
 * ---------------------------------------------------------------- */
int fsPathAddedEventSetup(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = -1;
  }
  else {
    *param_1 = param_2;
    iVar1 = semBCreate(1,0);
    param_1[1] = iVar1;
    if (iVar1 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = erfHandlerRegister(*DAT_300c9464,DAT_300c9464[1],DAT_300c9468,param_1,0,DAT_300c9464);
      if (iVar1 != 0) {
        semDelete(param_1[1]);
        param_1[1] = 0;
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * fsPathAddedEventRaise @ 0x300C93D4  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: erfEventRaise
 * Вызывают: dosFsDevCreate, rawFsDevInit
 * Константы: 0x300C93D4
 * Данные: DAT_300c9464
 * ---------------------------------------------------------------- */
void fsPathAddedEventRaise(undefined4 param_1)

{
  erfEventRaise(*DAT_300c9464,DAT_300c9464[1],1,param_1,0,DAT_300c9464);
  return;
}

/* ----------------------------------------------------------------
 * fsWaitForPath @ 0x300C9408  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: erfHandlerUnregister, semDelete, semTake
 * Вызывают: xbdCreatePartition, xbdCreatePartitionSz, xbdRamDiskDevCreate
 * Константы: 0xFFFFFFFF, 0x300C9408
 * Данные: DAT_300c9464, DAT_300c9468
 * ---------------------------------------------------------------- */
undefined4 fsWaitForPath(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = semTake(*(int *)(param_1 + 4),0xffffffff);
    erfHandlerUnregister(*DAT_300c9464,DAT_300c9464[1],DAT_300c9468,param_1,DAT_300c9464);
    semDelete(*(undefined4 *)(param_1 + 4));
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * fsMonitorInit @ 0x300C946C  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: erfHandlerRegister, semMCreate
 * Вызывают: usrIosExtraInit
 * Константы: 0x300C946C
 * Данные: DAT_300c9c94, DAT_300c9c98, DAT_300c9c9c, DAT_300c9ca0, DAT_300c9ca4, DAT_300c9ca8, DAT_300c9cac, DAT_300c9cb0
 * ---------------------------------------------------------------- */
int fsMonitorInit(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = DAT_300c9c94;
  *DAT_300c9c94 = 0;
  puVar1[1] = 0;
  puVar1 = DAT_300c9c98;
  *DAT_300c9c98 = 0;
  puVar1[1] = 0;
  iVar3 = semMCreate(9);
  *DAT_300c9c9c = iVar3;
  uVar2 = DAT_300c9ca0;
  if (iVar3 == 0) {
    iVar3 = -1;
  }
  else {
    iVar3 = erfHandlerRegister(*DAT_300c9ca4,*DAT_300c9ca8,DAT_300c9ca0,0,0);
    if (((iVar3 == 0) &&
        (iVar3 = erfHandlerRegister(*DAT_300c9ca4,*DAT_300c9cac,uVar2,0,0), iVar3 == 0)) &&
       (iVar3 = erfHandlerRegister(*DAT_300c9ca4,*DAT_300c9cb0,uVar2,0,0), iVar3 == 0)) {
      *DAT_300c9cb4 = 1;
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_300c9548 @ 0x300C9548  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Вызывают: FUN_300c9698
 * Константы: 0xFFFFFFFF, 0x300C9548
 * Данные: DAT_300c9c94, DAT_300c9c9c
 * ---------------------------------------------------------------- */
undefined4 FUN_300c9548(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  puVar1 = DAT_300c9c9c;
  semTake(*DAT_300c9c9c,0xffffffff);
  piVar3 = DAT_300c9c94;
  do {
    piVar3 = (int *)*piVar3;
    if (piVar3 == (int *)0x0) {
      semGive(*puVar1);
      return 0xffffffff;
    }
    iVar2 = (*(code *)piVar3[2])(param_1);
  } while ((iVar2 != 0) || (iVar2 = (*(code *)piVar3[3])(param_1,param_2), iVar2 != 0));
  semGive(*puVar1);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300c95e0 @ 0x300C95E0  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: strncpy
 * Вызывают: fsmGetVolume, fsmNameInstall, fsmNameMap
 * Константы: 0x300C95E0
 * ---------------------------------------------------------------- */
void FUN_300c95e0(char *param_1,char *param_2,int param_3)

{
  strncpy(param_1,param_2,param_3 - 1);
  param_1[param_3 + -1] = '\0';
  return;
}

/* ----------------------------------------------------------------
 * fsmNameMap @ 0x300C9604  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 5
 * Вызывает: FUN_300c95e0, semGive, semTake, strcpy, strncmp
 * Вызывают: FUN_300c9698, xbdCreatePartition, xbdCreatePartitionSz, xbdRamDiskDevCreate
 * Константы: 0x300C9604, 0xFFFFFFFF
 * Данные: DAT_300c9c98, DAT_300c9c9c
 * ---------------------------------------------------------------- */
undefined4 fsmNameMap(char *param_1,char *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  puVar1 = DAT_300c9c9c;
  semTake(*DAT_300c9c9c,0xffffffff);
  piVar3 = DAT_300c9c98;
  do {
    piVar3 = (int *)*piVar3;
    if (piVar3 == (int *)0x0) {
      semGive(*puVar1);
      strcpy(param_2,param_1);
      return 0;
    }
    iVar2 = strncmp(param_1,(char *)((int)piVar3 + 0x1d),10);
  } while (iVar2 != 0);
  FUN_300c95e0(param_2,piVar3 + 2,0x15);
  semGive(*puVar1);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300c9698 @ 0x300C9698  (примерный размер ~296 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_300c9548, devName, fsmNameMap, printf, rawFsDevInit, xbdPartitionDevCreate
 * Константы: 0x300C9698
 * Данные: DAT_300c9ca4, DAT_300c9ca8, DAT_300c9cac, DAT_300c9cb0, DAT_300c9cb4, DAT_300c9cb8, DAT_300c9cbc
 * ---------------------------------------------------------------- */
void FUN_300c9698(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_30 [12];
  undefined1 auStack_24 [24];
  
  if ((*DAT_300c9cb4 != 0) && (*DAT_300c9ca4 == param_1)) {
    if (*DAT_300c9ca8 == param_2) {
      if (param_3 == 0) {
        return;
      }
      iVar1 = devName(param_3,auStack_30);
      if (iVar1 != 0) {
        return;
      }
      xbdPartitionDevCreate(param_3);
    }
    if (*DAT_300c9cac == param_2) {
      if (param_3 == 0) {
        return;
      }
      iVar1 = devName(param_3,auStack_30);
      if (iVar1 != 0) {
        return;
      }
      fsmNameMap(auStack_30,auStack_24);
      iVar1 = FUN_300c9548(param_3,auStack_24);
      if (iVar1 == -1) {
        printf(DAT_300c9cb8,auStack_24,param_3);
        rawFsDevInit(auStack_24,param_3);
      }
    }
    if (((*DAT_300c9cb0 == param_2) && (param_3 != 0)) &&
       (iVar1 = devName(param_3,auStack_30), iVar1 == 0)) {
      fsmNameMap(auStack_30,auStack_24);
      printf(DAT_300c9cbc,auStack_24,param_3);
      rawFsDevInit(auStack_24,param_3);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * fsmProbeInstall @ 0x300C97C0  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: memPartAlloc, semGive, semTake
 * Вызывают: usrDosfsInit
 * Константы: 0xFFFFFFFF, 0x300C97C0
 * Данные: DAT_300c9c94, DAT_300c9c9c, DAT_300c9cc0
 * ---------------------------------------------------------------- */
undefined4 fsmProbeInstall(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  
  piVar3 = (int *)memPartAlloc(*DAT_300c9cc0,0x10);
  if (piVar3 == (int *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    piVar3[2] = param_1;
    piVar3[3] = param_2;
    puVar2 = DAT_300c9c9c;
    semTake(*DAT_300c9c9c,0xffffffff);
    piVar1 = DAT_300c9c94;
    piVar5 = (int *)DAT_300c9c94[1];
    if (piVar5 == (int *)0x0) {
      iVar6 = *DAT_300c9c94;
      *DAT_300c9c94 = (int)piVar3;
    }
    else {
      iVar6 = *piVar5;
      *piVar5 = (int)piVar3;
    }
    if (iVar6 == 0) {
      piVar1[1] = (int)piVar3;
    }
    else {
      *(int **)(iVar6 + 4) = piVar3;
    }
    *piVar3 = iVar6;
    piVar3[1] = (int)piVar5;
    semGive(*puVar2);
    uVar4 = 0;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * fsmProbeUninstall @ 0x300C9854  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: __errno, memPartFree, semGive, semTake
 * Константы: 0x300C9854, 0xFFFFFFFF
 * Данные: DAT_300c9c94, DAT_300c9c9c, DAT_300c9cc0
 * ---------------------------------------------------------------- */
int fsmProbeUninstall(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  
  puVar3 = DAT_300c9c9c;
  iVar5 = -1;
  semTake(*DAT_300c9c9c,0xffffffff);
  piVar2 = DAT_300c9c94;
  piVar4 = (int *)*DAT_300c9c94;
  while (piVar1 = piVar4, piVar1 != (int *)0x0) {
    piVar4 = (int *)*piVar1;
    if (piVar1[2] == param_1) {
      if ((int *)piVar1[1] == (int *)0x0) {
        *piVar2 = (int)piVar4;
      }
      else {
        *(int *)piVar1[1] = (int)piVar4;
      }
      if (*piVar1 == 0) {
        piVar2[1] = piVar1[1];
      }
      else {
        *(int *)(*piVar1 + 4) = piVar1[1];
      }
      iVar5 = 0;
      memPartFree(*DAT_300c9cc0);
    }
  }
  semGive(*puVar3);
  if (iVar5 == -1) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 2;
  }
  return iVar5;
}

/* ----------------------------------------------------------------
 * fsmNameInstall @ 0x300C9904  (примерный размер ~252 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_300c95e0, memPartAlloc, semGive, semTake, strncmp, strncpy
 * Константы: 0xFFFFFFFF, 0x300C9904
 * Данные: DAT_300c9c98, DAT_300c9c9c, DAT_300c9cc0
 * ---------------------------------------------------------------- */
undefined4 fsmNameInstall(char *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  
  puVar2 = DAT_300c9c9c;
  semTake(*DAT_300c9c9c,0xffffffff);
  piVar1 = DAT_300c9c98;
  puVar7 = (undefined4 *)*DAT_300c9c98;
  do {
    if (puVar7 == (undefined4 *)0x0) {
      piVar3 = (int *)memPartAlloc(*DAT_300c9cc0,0x28);
      if (piVar3 == (int *)0x0) {
        semGive(*puVar2);
        uVar4 = 0xffffffff;
      }
      else {
        strncpy((char *)((int)piVar3 + 0x1d),param_1,10);
        FUN_300c95e0(piVar3 + 2,param_2,0x15);
        piVar5 = (int *)piVar1[1];
        if (piVar5 == (int *)0x0) {
          iVar6 = *piVar1;
          *piVar1 = (int)piVar3;
        }
        else {
          iVar6 = *piVar5;
          *piVar5 = (int)piVar3;
        }
        if (iVar6 == 0) {
          piVar1[1] = (int)piVar3;
        }
        else {
          *(int **)(iVar6 + 4) = piVar3;
        }
        *piVar3 = iVar6;
        piVar3[1] = (int)piVar5;
LAB_300c99e8:
        semGive(*puVar2);
        uVar4 = 0;
      }
      return uVar4;
    }
    iVar6 = strncmp(param_1,(char *)((int)puVar7 + 0x1d),10);
    if (iVar6 == 0) {
      FUN_300c95e0(puVar7 + 2,param_2,0x15);
      goto LAB_300c99e8;
    }
    puVar7 = (undefined4 *)*puVar7;
  } while( true );
}

/* ----------------------------------------------------------------
 * fsmNameUninstall @ 0x300C9A00  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: __errno, memPartFree, semGive, semTake, strncmp
 * Константы: 0x300C9A00, 0xFFFFFFFF
 * Данные: DAT_300c9c98, DAT_300c9c9c, DAT_300c9cc0
 * ---------------------------------------------------------------- */
int fsmNameUninstall(char *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  
  puVar4 = DAT_300c9c9c;
  iVar6 = -1;
  semTake(*DAT_300c9c9c,0xffffffff);
  piVar2 = DAT_300c9c98;
  piVar5 = (int *)*DAT_300c9c98;
  while (piVar1 = piVar5, piVar1 != (int *)0x0) {
    piVar5 = (int *)*piVar1;
    iVar3 = strncmp(param_1,(char *)((int)piVar1 + 0x1d),10);
    if (iVar3 == 0) {
      if ((int *)piVar1[1] == (int *)0x0) {
        *piVar2 = (int)piVar5;
      }
      else {
        *(int *)piVar1[1] = (int)piVar5;
      }
      if (*piVar1 == 0) {
        piVar2[1] = piVar1[1];
      }
      else {
        *(int *)(*piVar1 + 4) = piVar1[1];
      }
      iVar6 = 0;
      memPartFree(*DAT_300c9cc0,piVar1);
    }
  }
  semGive(*puVar4);
  if (iVar6 == -1) {
    puVar4 = (undefined4 *)__errno();
    *puVar4 = 2;
  }
  return iVar6;
}

/* ----------------------------------------------------------------
 * fsmGetDriver @ 0x300C9AC0  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: __errno, semGive, semTake, strncmp, strncpy
 * Константы: 0x300C9AC0, 0xFFFFFFFF
 * Данные: DAT_300c9c98, DAT_300c9c9c
 * ---------------------------------------------------------------- */
int fsmGetDriver(char *param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  puVar2 = DAT_300c9c9c;
  iVar3 = -1;
  semTake(*DAT_300c9c9c,0xffffffff);
  piVar4 = DAT_300c9c98;
  do {
    piVar4 = (int *)*piVar4;
    if (piVar4 == (int *)0x0) goto LAB_300c9b2c;
    iVar1 = strncmp(param_1,(char *)(piVar4 + 2),0x15);
  } while (iVar1 != 0);
  strncpy(param_2,(char *)((int)piVar4 + 0x1d),10);
  iVar3 = 0;
LAB_300c9b2c:
  semGive(*puVar2);
  if (iVar3 == -1) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 2;
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * fsmGetVolume @ 0x300C9B58  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300c95e0, __errno, semGive, semTake, strncmp
 * Константы: 0x300C9B58, 0xFFFFFFFF
 * Данные: DAT_300c9c98, DAT_300c9c9c
 * ---------------------------------------------------------------- */
int fsmGetVolume(char *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  puVar2 = DAT_300c9c9c;
  iVar3 = -1;
  semTake(*DAT_300c9c9c,0xffffffff);
  piVar4 = DAT_300c9c98;
  do {
    piVar4 = (int *)*piVar4;
    if (piVar4 == (int *)0x0) goto LAB_300c9bc4;
    iVar1 = strncmp(param_1,(char *)((int)piVar4 + 0x1d),10);
  } while (iVar1 != 0);
  FUN_300c95e0(param_2,piVar4 + 2,0x15);
  iVar3 = 0;
LAB_300c9bc4:
  semGive(*puVar2);
  if (iVar3 == -1) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 2;
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * fsmUnmountHookAdd @ 0x300C9BF0  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, hookAddToTail
 * Константы: 0x300C9BF0, 0xFFFFFFFF
 * Данные: DAT_300c9cc4
 * ---------------------------------------------------------------- */
undefined4 fsmUnmountHookAdd(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = hookAddToTail(param_1,DAT_300c9cc4,4);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * fsmUnmountHookDelete @ 0x300C9C20  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, hookDelete
 * Константы: 0x300C9C20, 0xFFFFFFFF
 * Данные: DAT_300c9cc4
 * ---------------------------------------------------------------- */
undefined4 fsmUnmountHookDelete(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = hookDelete(param_1,DAT_300c9cc4,4);
  }
  return uVar2;
}

