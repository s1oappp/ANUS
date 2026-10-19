/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 7 (функций: 150, адреса 0x300A159C..0x300B8B6C)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * r0 @ 0x300A159C  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A159C, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*(code *)*DAT_300a14c0)();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r1 @ 0x300A15A4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A15A4, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r1(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 4))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r2 @ 0x300A15AC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A15AC, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r2(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 8))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r3 @ 0x300A15B4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A15B4, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r3(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0xc))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r4 @ 0x300A15BC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A15BC, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r4(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0x10))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r5 @ 0x300A15C4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A15C4, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r5(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0x14))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r6 @ 0x300A15CC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A15CC, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r6(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0x18))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r7 @ 0x300A15D4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A15D4, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r7(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0x1c))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r8 @ 0x300A15DC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A15DC, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r8(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0x20))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r9 @ 0x300A15E4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A15E4, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r9(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0x24))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r10 @ 0x300A15EC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A15EC, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r10(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0x28))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r11 @ 0x300A15F4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A15F4, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r11(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0x2c))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r12 @ 0x300A15FC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A15FC, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r12(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0x30))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r13 @ 0x300A1604  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A1604, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r13(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0x34))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * r14 @ 0x300A160C  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A160C, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 r14(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0x38))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * cpsr @ 0x300A1614  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: taskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0x300A1614, 0x300A1490, 0xFFFFFFFF
 * Данные: DAT_300a14c0
 * ---------------------------------------------------------------- */
undefined4 cpsr(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [72];
  
  iVar1 = taskIdFigure();
  if (iVar1 != -1) {
    uVar2 = taskIdDefault();
    iVar1 = taskRegsGet(uVar2,auStack_50);
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a1490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_300a14c0 + 0x40))();
      return uVar2;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * psrShow @ 0x300A161C  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: puts, strcat
 * Константы: 0x300A161C, 0x80000000, 0x40000000, 0x20000000, 0x10000000, 0x300A16AC
 * Данные: DAT_300a16b0, DAT_300a16b4, DAT_300a176c
 * ---------------------------------------------------------------- */
undefined4 psrShow(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  char *pcVar5;
  char local_14 [20];
  
  pcVar5 = local_14;
  iVar2 = 8;
  puVar3 = DAT_300a16b0;
  do {
    iVar2 = iVar2 + -1;
    *pcVar5 = *puVar3;
    pcVar5 = pcVar5 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar2 != 0);
  if ((param_1 & 0x80000000) != 0) {
    local_14[0] = 'N';
  }
  if ((param_1 & 0x40000000) != 0) {
    local_14[1] = 0x5a;
  }
  if ((param_1 & 0x20000000) != 0) {
    local_14[2] = 0x43;
  }
  if ((param_1 & 0x10000000) != 0) {
    local_14[3] = 0x56;
  }
  if ((param_1 & 0x80) != 0) {
    local_14[4] = 0x49;
  }
  if ((param_1 & 0x40) != 0) {
    local_14[5] = 0x46;
  }
  if ((param_1 & 0x20) != 0) {
    local_14[6] = 0x54;
  }
  uVar4 = (param_1 & 0x1f) - 0x10;
  if (0xf < uVar4) {
    strcat(local_14,DAT_300a176c);
    puts(local_14);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x300a16ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(DAT_300a16b4 + uVar4 * 4))();
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300a1770 @ 0x300A1770  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A1770, 0x80000000
 * ---------------------------------------------------------------- */
uint FUN_300a1770(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_2 >> 5 & 3;
  if ((param_2 & 0x10) == 0) {
    uVar2 = param_2 >> 7 & 0x1f;
  }
  else {
    uVar2 = param_2 >> 8 & 0xf;
    if (uVar2 == 0xf) {
      uVar2 = *(int *)(param_1 + 0x3c) + 8;
    }
    else {
      uVar2 = *(uint *)(param_1 + uVar2 * 4);
    }
    uVar2 = uVar2 & 0xff;
  }
  if ((param_2 & 0xf) == 0xf) {
    uVar3 = *(int *)(param_1 + 0x3c) + (param_2 >> 4 & 1) * 4 + 8;
  }
  else {
    uVar3 = *(uint *)(param_1 + (param_2 & 0xf) * 4);
  }
  if (uVar1 == 0) {
    if (uVar2 < 0x20) {
      return uVar3 << uVar2;
    }
LAB_300a1820:
    uVar3 = 0;
  }
  else {
    if (uVar1 == 1) {
      if (0x1f < uVar2) goto LAB_300a1820;
    }
    else {
      if (uVar1 != 2) {
        if (uVar1 != 3) {
          return uVar3;
        }
        uVar2 = uVar2 & 0x1f;
        if (uVar2 == 0) {
          return (uint)(param_3 != 0) << 0x1f | uVar3 >> 1;
        }
        return uVar3 << (0x20 - uVar2 & 0xff) | uVar3 >> uVar2;
      }
      if (0x1f < uVar2) {
        uVar2 = 0x1f;
      }
      if ((uVar3 & 0x80000000) != 0) {
        return ~(~uVar3 >> uVar2);
      }
    }
    uVar3 = uVar3 >> uVar2;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * armGetNpc @ 0x300A1888  (примерный размер ~936 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: wdbDbgGetNpc
 * Константы: 0x300A1888, 0x300A191C
 * Данные: DAT_300a1920, DAT_300a1924, DAT_300a1928
 * ---------------------------------------------------------------- */
int armGetNpc(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar1 = param_1;
  if ((*(uint *)(DAT_300a1920 + (param_1 >> 0x1c) * 4) >> (*(uint *)(param_2 + 0x40) >> 0x1c) & 1)
      != 0) {
LAB_300a1910:
    uVar4 = param_1 >> 0x18 & 0xf;
                    /* WARNING: Could not recover jumptable at 0x300a191c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (**(code **)(DAT_300a1928 + uVar4 * 4))(uVar1,DAT_300a1928,uVar4,param_2);
    return iVar2;
  }
  uVar1 = 0;
  if (*DAT_300a1924 != 0) {
    puVar3 = DAT_300a1924;
    do {
      if (((param_1 & 1) != 0) && ((param_1 & puVar3[1]) == (*puVar3 & puVar3[1])))
      goto LAB_300a1910;
      puVar3 = puVar3 + 2;
      uVar1 = uVar1 + 1;
    } while (*puVar3 != 0);
  }
  return *(int *)(param_2 + 0x3c) + 4;
}

/* ----------------------------------------------------------------
 * armInstrChangesPc @ 0x300A1C30  (примерный размер ~180 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: _dbgFuncCallCheck
 * Константы: 0x300A1C30, 0x300A1C44
 * Данные: DAT_300a1c50
 * ---------------------------------------------------------------- */
void armInstrChangesPc(uint *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x300a1c44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_300a1c50 + (*param_1 >> 0x18 & 0xf) * 4))();
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a1ce4 @ 0x300A1CE4  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: oprintf
 * Вызывают: FUN_300a1df0, FUN_300a2114, FUN_300a21e4, FUN_300a2404, FUN_300a2ff8
 * Константы: 0x300A1CE4
 * Данные: DAT_300a27b8, DAT_300a27bc, DAT_300a27c0, DAT_300a27c4, DAT_300a27c8, DAT_300a27cc
 * ---------------------------------------------------------------- */
void FUN_300a1ce4(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = DAT_300a27b8;
  iVar2 = DAT_300a27bc;
  if (((param_3 != 0xf) && (iVar2 = DAT_300a27c0, param_3 != 0xe)) &&
     (iVar2 = DAT_300a27c4, param_3 != 0xd)) {
    uVar1 = DAT_300a27c8;
    iVar2 = param_3;
  }
  oprintf(param_1,param_2,uVar1,iVar2);
  if (param_4 == 0) {
    return;
  }
  oprintf(param_1,param_2,DAT_300a27cc,param_4);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a1d58 @ 0x300A1D58  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: oprintf
 * Вызывают: FUN_300a21e4, FUN_300a2338, FUN_300a2404
 * Константы: 0x300A1D58
 * Данные: DAT_300a27cc
 * ---------------------------------------------------------------- */
void FUN_300a1d58(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  oprintf(param_1,param_2,DAT_300a27cc,0x23);
  if (param_4 == 0) {
    oprintf(param_1,param_2,DAT_300a27cc,0x2d);
  }
  oprintf(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a1db4 @ 0x300A1DB4  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: oprintf
 * Вызывают: FUN_300a2060, FUN_300a2640, FUN_300a2ff8
 * Константы: 0x300A1DB4
 * Данные: DAT_300a27cc
 * ---------------------------------------------------------------- */
void FUN_300a1db4(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (8 < param_3) {
    return;
  }
  param_3 = 9 - param_3;
  do {
    oprintf(param_1,param_2,DAT_300a27cc,0x20);
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a1df0 @ 0x300A1DF0  (примерный размер ~368 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300a1ce4, oprintf
 * Константы: 0x300A1DF0
 * Данные: DAT_300a27cc
 * ---------------------------------------------------------------- */
void FUN_300a1df0(undefined4 param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  bVar1 = false;
  uVar3 = 0;
  bVar2 = false;
  uVar4 = 0;
  oprintf(param_1,param_2,DAT_300a27cc,0x7b);
  uVar5 = 0;
  do {
    if ((param_3 & 1 << (uVar5 & 0xff)) >> (uVar5 & 0xff) != 0) {
      if (bVar1) {
        if (uVar4 + 1 == uVar5) {
          bVar2 = true;
          uVar4 = uVar5;
        }
        else {
          if ((uVar4 + 1 < uVar5) && (bVar2)) {
            oprintf(param_1,param_2,DAT_300a27cc,(uVar4 - 1 != uVar3) + ',');
            FUN_300a1ce4(param_1,param_2,uVar4,0);
            bVar2 = false;
          }
          oprintf(param_1,param_2,DAT_300a27cc,0x2c);
          FUN_300a1ce4(param_1,param_2,uVar5,0);
          uVar3 = uVar5;
          uVar4 = uVar5;
        }
      }
      else {
        FUN_300a1ce4(param_1,param_2,uVar5,0);
        bVar1 = true;
        uVar3 = uVar5;
        uVar4 = uVar5;
      }
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x10);
  if (bVar2) {
    oprintf(param_1,param_2,DAT_300a27cc,(uVar4 - 1 != uVar3) + ',');
    FUN_300a1ce4(param_1,param_2,uVar4,0);
  }
  oprintf(param_1,param_2,DAT_300a27cc,0x7d);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a1f60 @ 0x300A1F60  (примерный размер ~216 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: oprintf
 * Константы: 0x300A1F60
 * Данные: DAT_300a27cc, DAT_300a27d8
 * ---------------------------------------------------------------- */
void FUN_300a1f60(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  oprintf(param_1,param_2,DAT_300a27cc,0x7b);
  if ((param_4 == 0x53) || (param_4 == 0x73)) {
    uVar2 = param_3 >> 0x16 & 1 | (param_3 >> 0xc & 0xf) << 1;
  }
  else {
    uVar2 = param_3 >> 0xc & 0xf;
  }
  uVar3 = uVar2 + (param_3 & 0xff);
  bVar1 = false;
  for (; uVar2 <= uVar3; uVar2 = uVar2 + 1) {
    if (bVar1) {
      oprintf(param_1,param_2,DAT_300a27cc,0x2c);
    }
    else {
      bVar1 = true;
    }
    oprintf(param_1,param_2,DAT_300a27d8,param_4,uVar2);
  }
  oprintf(param_1,param_2,DAT_300a27cc,0x7d);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a2038 @ 0x300A2038  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: oprintf, strlen
 * Вызывают: FUN_300a2060, FUN_300a2640, FUN_300a2ff8
 * Константы: 0x300A2038
 * Данные: DAT_300a27b8, DAT_300a27dc
 * ---------------------------------------------------------------- */
void FUN_300a2038(undefined4 param_1,undefined4 param_2,uint param_3)

{
  char *__s;
  
  __s = (char *)(DAT_300a27dc + (param_3 >> 0x1c) * 4);
  oprintf(param_1,param_2,DAT_300a27b8,__s);
  strlen(__s);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a2060 @ 0x300A2060  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 4
 * Вызывает: FUN_300a1db4, FUN_300a2038, oprintf, strlen
 * Вызывают: FUN_300a2338, FUN_300a2404, FUN_300a24e4, FUN_300a2ff8, FUN_300a3184, FUN_300a3228
 * Константы: 0x300A2060
 * Данные: DAT_300a27b8, DAT_300a27cc
 * ---------------------------------------------------------------- */
void FUN_300a2060(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,int param_5
                 )

{
  size_t sVar1;
  int iVar2;
  
  oprintf(param_1,param_2,DAT_300a27b8);
  sVar1 = strlen(param_4);
  iVar2 = FUN_300a2038(param_1,param_2,param_3);
  iVar2 = iVar2 + sVar1;
  if (param_5 != 0) {
    oprintf(param_1,param_2,DAT_300a27cc,param_5);
    iVar2 = iVar2 + 1;
  }
  FUN_300a1db4(param_1,param_2,iVar2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a20d4 @ 0x300A20D4  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: oprintf
 * Вызывают: FUN_300a25dc, FUN_300a2640, FUN_300a2ff8, FUN_300a3184, FUN_300a3228
 * Константы: 0x300A20D4
 * Данные: DAT_300a27cc, DAT_300a27e0
 * ---------------------------------------------------------------- */
void FUN_300a20d4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  oprintf(param_1,param_2,DAT_300a27e0,param_3);
  if (param_4 == 0) {
    return;
  }
  oprintf(param_1,param_2,DAT_300a27cc,param_4);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a2114 @ 0x300A2114  (примерный размер ~196 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300a1ce4, oprintf
 * Вызывают: FUN_300a21e4
 * Константы: 0x300A2114
 * Данные: DAT_300a27e4, DAT_300a27e8
 * ---------------------------------------------------------------- */
void FUN_300a2114(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = DAT_300a27e4 + (param_3 >> 5 & 3) * 4;
  FUN_300a1ce4(param_1,param_2,param_3 & 0xf,0);
  if ((param_3 & 0x10) == 0) {
    if ((param_3 & 0xfe0) == 0) {
      return;
    }
    if ((param_3 >> 5 & 0x7f) != 3) {
      oprintf(param_1,param_2,DAT_300a27e8,iVar1);
    }
    oprintf(param_1,param_2);
  }
  else {
    oprintf(param_1,param_2,DAT_300a27e8,iVar1);
    FUN_300a1ce4(param_1,param_2,param_3 >> 8 & 0xf,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a21d8 @ 0x300A21D8  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: oprintf
 * Вызывают: FUN_300a21e4
 * Константы: 0x300A21D8
 * Данные: DAT_300a27f4
 * ---------------------------------------------------------------- */
void FUN_300a21d8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  oprintf(param_1,param_2,DAT_300a27f4,param_3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a21e4 @ 0x300A21E4  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 5
 * Вызывает: FUN_300a1ce4, FUN_300a1d58, FUN_300a2114, FUN_300a21d8, oprintf
 * Вызывают: FUN_300a24e4, FUN_300a3184, FUN_300a3228
 * Константы: 0x01000000, 0x00800000, 0x300A21E4, 0x03000000, 0x02000000, 0x00200000
 * Данные: DAT_300a27cc, DAT_300a27f8
 * ---------------------------------------------------------------- */
void FUN_300a21e4(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,int param_5,
                 code *param_6)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = param_3 >> 0x10 & 0xf;
  if ((uVar1 == 0xf) && ((param_3 & 0x3000000) == 0x1000000)) {
    if ((param_3 & 0x800000) == 0) {
      param_5 = -param_5;
    }
    iVar3 = param_4 + param_5 + 8;
    if (DAT_300a27f8 == param_6) {
      FUN_300a21d8(param_1,param_2,iVar3);
    }
    else {
      (*param_6)(iVar3);
    }
  }
  else {
    oprintf(param_1,param_2,DAT_300a27cc,0x5b);
    uVar2 = 0x5d;
    if ((param_3 & 0x1000000) != 0) {
      uVar2 = 0;
    }
    FUN_300a1ce4(param_1,param_2,uVar1,uVar2);
    oprintf(param_1,param_2,DAT_300a27cc,0x2c);
    if ((param_3 & 0x2000000) == 0) {
      FUN_300a1d58(param_1,param_2,param_5,param_3 >> 0x17 & 1);
    }
    else {
      if ((param_3 & 0x800000) == 0) {
        oprintf(param_1,param_2,DAT_300a27cc,0x2d);
      }
      FUN_300a2114(param_1,param_2,param_3);
    }
    if (((param_3 & 0x1000000) != 0) &&
       (oprintf(param_1,param_2,DAT_300a27cc,0x5d), (param_3 & 0x200000) != 0)) {
      oprintf(param_1,param_2,DAT_300a27cc,0x21);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a2338 @ 0x300A2338  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_300a1d58, FUN_300a2060, oprintf
 * Вызывают: FUN_300a2758, FUN_300a2c78
 * Константы: 0x300A2338
 * Данные: DAT_300a27cc, DAT_300a27d4, DAT_300a2800, DAT_300a2804
 * ---------------------------------------------------------------- */
void FUN_300a2338(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  FUN_300a2060();
  oprintf(param_1,param_2,DAT_300a2800,param_3 >> 8 & 0xf,uVar1);
  oprintf(param_1,param_2,DAT_300a27d4,param_3 >> 0x14 & 0xf);
  oprintf(param_1,param_2,DAT_300a27cc,0x2c);
  oprintf(param_1,param_2,DAT_300a2804,param_3 >> 0xc & 0xf);
  oprintf(param_1,param_2,DAT_300a2804,param_3 >> 0x10 & 0xf);
  oprintf(param_1,param_2,DAT_300a2804,param_3 & 0xf);
  FUN_300a1d58(param_1,param_2,param_3 >> 5 & 7,1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a2404 @ 0x300A2404  (примерный размер ~224 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300a1ce4, FUN_300a1d58, FUN_300a2060, oprintf
 * Константы: 0x300A2404, 0x00100000
 * Данные: DAT_300a27cc, DAT_300a27d4, DAT_300a2800, DAT_300a2804, DAT_300a2808, DAT_300a280c
 * ---------------------------------------------------------------- */
void FUN_300a2404(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  uVar1 = DAT_300a2808;
  if ((param_3 & 0x100000) == 0) {
    uVar1 = DAT_300a280c;
  }
  FUN_300a2060(param_1,param_2,param_3,uVar1,0);
  oprintf(param_1,param_2,DAT_300a2800,param_3 >> 8 & 0xf);
  oprintf(param_1,param_2,DAT_300a27d4,param_3 >> 0x15 & 7);
  oprintf(param_1,param_2,DAT_300a27cc,0x2c);
  FUN_300a1ce4(param_1,param_2,param_3 >> 0xc & 0xf,0x2c);
  oprintf(param_1,param_2,DAT_300a2804,param_3 >> 0x10 & 0xf);
  oprintf(param_1,param_2,DAT_300a2804,param_3 & 0xf);
  FUN_300a1d58(param_1,param_2,param_3 >> 5 & 7,1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a24e4 @ 0x300A24E4  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_300a2060, FUN_300a21e4, oprintf
 * Вызывают: FUN_300a3184, FUN_300a3228
 * Константы: 0x300A24E4, 0x00100000, 0x00400000
 * Данные: DAT_300a2800, DAT_300a2804, DAT_300a2810, DAT_300a2814
 * ---------------------------------------------------------------- */
void FUN_300a24e4(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_300a2810;
  if ((param_3 & 0x100000) == 0) {
    uVar1 = DAT_300a2814;
  }
  uVar2 = 0;
  if ((param_3 & 0x400000) != 0) {
    uVar2 = 0x4c;
  }
  FUN_300a2060(param_1,param_2,param_3,uVar1,uVar2);
  oprintf(param_1,param_2,DAT_300a2800,param_3 >> 8 & 0xf);
  oprintf(param_1,param_2,DAT_300a2804,param_3 >> 0xc & 0xf);
  FUN_300a21e4(param_1,param_2,param_3,param_4,(param_3 & 0xff) << 2,param_5);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a2588 @ 0x300A2588  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300a3184
 * Константы: 0x300A2588
 * Данные: DAT_300a2818
 * ---------------------------------------------------------------- */
undefined1 FUN_300a2588(uint param_1)

{
  return *(undefined1 *)(DAT_300a2818 + (param_1 >> 0xf & 1) + (param_1 >> 0x16 & 1) * 2);
}

/* ----------------------------------------------------------------
 * FUN_300a25a8 @ 0x300A25A8  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300a2640, FUN_300a2ff8
 * Константы: 0x300A25A8
 * Данные: DAT_300a2818
 * ---------------------------------------------------------------- */
undefined1 FUN_300a25a8(uint param_1)

{
  return *(undefined1 *)(DAT_300a2818 + (param_1 >> 7 & 1) + (param_1 >> 0x13 & 1) * 2);
}

/* ----------------------------------------------------------------
 * FUN_300a25c8 @ 0x300A25C8  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300a2640, FUN_300a2ff8
 * Константы: 0x300A25C8
 * Данные: DAT_300a281c
 * ---------------------------------------------------------------- */
int FUN_300a25c8(uint param_1)

{
  return DAT_300a281c + (param_1 >> 5 & 3) * 2;
}

/* ----------------------------------------------------------------
 * FUN_300a25dc @ 0x300A25DC  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_300a20d4, oprintf, strlen
 * Вызывают: FUN_300a2640, FUN_300a2ff8
 * Константы: 0x300A25DC
 * Данные: DAT_300a27b8, DAT_300a27f0, DAT_300a2820, DAT_300a2824
 * ---------------------------------------------------------------- */
void FUN_300a25dc(undefined4 param_1,undefined4 param_2,uint param_3)

{
  char *pcVar1;
  uint uVar2;
  
  uVar2 = param_3 & 7;
  if ((param_3 & 8) == 0) {
    FUN_300a20d4(param_1,param_2,uVar2,0);
  }
  else if (uVar2 < 6) {
    oprintf(param_1,param_2,DAT_300a27f0,uVar2);
  }
  else {
    pcVar1 = DAT_300a2820;
    if (uVar2 != 6) {
      pcVar1 = DAT_300a2824;
    }
    oprintf(param_1,param_2,DAT_300a27b8,pcVar1);
    pcVar1 = DAT_300a2820;
    if (uVar2 != 6) {
      pcVar1 = DAT_300a2824;
    }
    strlen(pcVar1);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a2640 @ 0x300A2640  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_300a1db4, FUN_300a2038, FUN_300a20d4, FUN_300a25a8, FUN_300a25c8, FUN_300a25dc, oprintf, strlen
 * Константы: 0x300A2640
 * Данные: DAT_300a27b8, DAT_300a27cc, DAT_300a2828, DAT_300a282c
 * ---------------------------------------------------------------- */
void FUN_300a2640(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  undefined1 uVar1;
  size_t sVar2;
  int iVar3;
  size_t sVar4;
  char *pcVar5;
  
  iVar3 = DAT_300a2828;
  if ((param_3 & 0x8000) == 0) {
    iVar3 = DAT_300a282c;
  }
  pcVar5 = (char *)(iVar3 + (param_3 >> 0x14 & 0xf) * 4);
  oprintf(param_1,param_2,DAT_300a27b8,pcVar5);
  sVar2 = strlen(pcVar5);
  iVar3 = FUN_300a2038(param_1,param_2,param_3);
  uVar1 = FUN_300a25a8(param_3);
  oprintf(param_1,param_2,DAT_300a27cc,uVar1);
  pcVar5 = (char *)FUN_300a25c8(param_3);
  oprintf(param_1,param_2,DAT_300a27b8,pcVar5);
  sVar4 = strlen(pcVar5);
  FUN_300a1db4(param_1,param_2,sVar4 + iVar3 + sVar2 + 1);
  FUN_300a20d4(param_1,param_2,param_3 >> 0xc & 7,0x2c);
  if ((param_3 & 0x8000) == 0) {
    FUN_300a20d4(param_1,param_2,param_3 >> 0x10 & 7,0x2c);
  }
  else if ((param_3 & 0x70000) != 0) {
    *param_4 = 1;
  }
  FUN_300a25dc(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a2758 @ 0x300A2758  (примерный размер ~1312 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300a2338
 * Константы: 0x300A2758, 0x00800000, 0x300A27B4
 * Данные: DAT_300a2830
 * ---------------------------------------------------------------- */
void FUN_300a2758(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  
  if ((((param_3 & 0x800000) == 0) && ((param_3 >> 0x14 & 3) != 3)) && ((param_3 & 0x40) == 0)) {
    *param_4 = 1;
  }
  else {
    uVar1 = param_3 >> 7 & 1 | (param_3 >> 0x10 & 0xf) << 1;
    if (uVar1 < 0x1c) {
                    /* WARNING: Could not recover jumptable at 0x300a27b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(DAT_300a2830 + uVar1 * 4))();
      return;
    }
    *param_4 = 1;
    FUN_300a2338(param_1,param_2,param_3);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a2c78 @ 0x300A2C78  (примерный размер ~896 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300a2338
 * Константы: 0x300A2C78, 0x300A2CDC
 * Данные: DAT_300a2d68
 * ---------------------------------------------------------------- */
void FUN_300a2c78(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  
  uVar1 = param_3 >> 8 & 0xf;
  if ((uVar1 == 10) || (uVar1 == 0xb)) {
    uVar1 = (param_3 >> 0x14 & 3) << 1 | (param_3 >> 0x17 & 1) << 3 | param_3 >> 6 & 1;
    if (uVar1 < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x300a2cdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(DAT_300a2d68 + uVar1 * 4))();
      return;
    }
    *param_4 = 1;
  }
  FUN_300a2338(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a2ff8 @ 0x300A2FF8  (примерный размер ~396 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 10
 * Вызывает: FUN_300a1ce4, FUN_300a1db4, FUN_300a2038, FUN_300a2060, FUN_300a20d4, FUN_300a25a8, FUN_300a25c8, FUN_300a25dc, oprintf, strlen
 * Константы: 0x300A2FF8, 0x00F00000
 * Данные: DAT_300a3374, DAT_300a3378, DAT_300a337c, DAT_300a3380
 * ---------------------------------------------------------------- */
void FUN_300a2ff8(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined1 uVar1;
  size_t sVar2;
  char *__s;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = param_3 >> 0xc & 0xf;
  uVar6 = param_3 >> 0x14 & 0xf;
  if (uVar4 == 0xf) {
    iVar5 = 4;
    if ((param_3 >> 0x14 & 9) == 9) {
      iVar5 = ((int)uVar6 >> 1) + -4;
    }
    FUN_300a2060(param_1,param_2,param_3,DAT_300a3374 + iVar5 * 5,0);
    FUN_300a20d4(param_1,param_2,param_3 >> 0x10 & 7,0x2c);
  }
  else {
    uVar7 = 7;
    if (uVar6 < 8) {
      uVar7 = uVar6;
    }
    oprintf(param_1,param_2,DAT_300a337c,DAT_300a3378 + uVar7 * 4);
    sVar2 = strlen((char *)(DAT_300a3378 + uVar7 * 4));
    iVar5 = FUN_300a2038(param_1,param_2,param_3);
    uVar1 = FUN_300a25a8(param_3);
    oprintf(param_1,param_2,DAT_300a3380,uVar1);
    __s = (char *)FUN_300a25c8(param_3);
    oprintf(param_1,param_2,DAT_300a337c,__s);
    sVar3 = strlen(__s);
    FUN_300a1db4(param_1,param_2,sVar3 + iVar5 + sVar2 + 1);
    if ((param_3 & 0xf00000) == 0) {
      FUN_300a20d4(param_1,param_2,param_3 >> 0x10 & 7,0x2c);
    }
    FUN_300a1ce4(param_1,param_2,uVar4,0);
    if (uVar6 != 1) {
      return;
    }
    oprintf(param_1,param_2,DAT_300a3380,0x2c);
  }
  FUN_300a25dc(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a3184 @ 0x300A3184  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300a2060, FUN_300a20d4, FUN_300a21e4, FUN_300a24e4, FUN_300a2588
 * Константы: 0x300A3184, 0x01200000, 0x00100000
 * Данные: DAT_300a3384, DAT_300a3388
 * ---------------------------------------------------------------- */
void FUN_300a3184(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if ((param_3 & 0x1200000) == 0) {
    FUN_300a24e4();
  }
  else {
    uVar2 = DAT_300a3384;
    if ((param_3 & 0x100000) == 0) {
      uVar2 = DAT_300a3388;
    }
    uVar1 = FUN_300a2588(param_3);
    FUN_300a2060(param_1,param_2,param_3,uVar2,uVar1);
    FUN_300a20d4(param_1,param_2,param_3 >> 0xc & 7,0x2c);
    FUN_300a21e4(param_1,param_2,param_3,param_4,(param_3 & 0xff) << 2,param_5);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a3228 @ 0x300A3228  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300a2060, FUN_300a20d4, FUN_300a21e4, FUN_300a24e4, oprintf
 * Константы: 0x300A3228, 0x01200000, 0x00100000
 * Данные: DAT_300a338c, DAT_300a3390, DAT_300a3394
 * ---------------------------------------------------------------- */
void FUN_300a3228(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_3 & 0x1200000) == 0) {
    FUN_300a24e4();
  }
  else {
    uVar1 = DAT_300a338c;
    if ((param_3 & 0x100000) == 0) {
      uVar1 = DAT_300a3390;
    }
    FUN_300a2060(param_1,param_2,param_3,uVar1,0);
    FUN_300a20d4(param_1,param_2,param_3 >> 0xc & 7,0x2c);
    iVar2 = (param_3 >> 0xf & 1) + (param_3 >> 0x16 & 1) * 2;
    if (iVar2 == 0) {
      iVar2 = 4;
    }
    oprintf(param_1,param_2,DAT_300a3394,iVar2);
    FUN_300a21e4(param_1,param_2,param_3,param_4,(param_3 & 0xff) << 2,param_5);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a32e8 @ 0x300A32E8  (примерный размер ~11136 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: dsmInst
 * Константы: 0x300A32E8, 0x300A3318
 * Данные: DAT_300a3398
 * ---------------------------------------------------------------- */
void FUN_300a32e8(undefined4 param_1,undefined4 param_2,uint param_3)

{
                    /* WARNING: Could not recover jumptable at 0x300a3318. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_300a3398 + (param_3 >> 0x18 & 0xf) * 4))();
  return;
}

/* ----------------------------------------------------------------
 * dsmInst @ 0x300A5E68  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300a32e8, oprintf, vxdbgMemRead
 * Константы: 0x300A5E68
 * Данные: DAT_300a5fd8, DAT_300a5fdc, DAT_300a5fe0
 * ---------------------------------------------------------------- */
uint dsmInst(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  undefined4 local_18;
  
  if (param_3 == 0) {
    param_3 = DAT_300a5fd8;
  }
  if (*(int *)(DAT_300a5fdc + 0xc) == 0) {
    local_18 = *param_1;
  }
  else {
    vxdbgMemRead(param_1,&local_18,4,0);
  }
  oprintf(param_4,param_5,DAT_300a5fe0,param_2,local_18);
  uVar1 = FUN_300a32e8(param_4,param_5,local_18,param_2,param_3);
  return uVar1 >> 2;
}

/* ----------------------------------------------------------------
 * dsmNbytes @ 0x300A5F04  (примерный размер ~224 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: _dbgInstSizeGet
 * Константы: 0x300A5F04
 * ---------------------------------------------------------------- */
undefined4 dsmNbytes(void)

{
  return 4;
}

/* ----------------------------------------------------------------
 * FUN_300a5fe4 @ 0x300A5FE4  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: errnoSet, printErr
 * Константы: 0xFE000000, 0x00FFFFFF, 0xFFFFFFFF, 0x300A5FE4, 0x02000000, 0xFF000000
 * Данные: DAT_300a60c0, DAT_300a60c4, DAT_300a60c8, DAT_300a60cc
 * ---------------------------------------------------------------- */
undefined4
FUN_300a5fe4(int param_1,uint *param_2,int param_3,undefined1 param_4,undefined4 param_5,int param_6
            )

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = ((*param_2 & 0xffffff) << 2 ^ 0x2000000) + 0xfe000000;
  if (param_1 == 4) {
    iVar3 = iVar3 + param_6;
  }
  uVar1 = iVar3 + (param_3 - (int)param_2);
  if (((uVar1 & 0xfe000000) == 0) || ((uVar1 & 0xfe000000) == 0xfe000000)) {
    if ((uVar1 & 3) == 0) {
      *param_2 = *param_2 & 0xff000000 | uVar1 >> 2 & 0xffffff;
      uVar2 = 0;
    }
    else {
      printErr(DAT_300a60c8,param_5,param_4);
      errnoSet(DAT_300a60cc);
      uVar2 = 0xffffffff;
    }
  }
  else {
    printErr(DAT_300a60c0,param_5,param_4);
    errnoSet(DAT_300a60c4);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300a609c @ 0x300A609C  (примерный размер ~332 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: memset, snprintf
 * Вызывают: FUN_300a62bc
 * Константы: 0x300A609C, 0x300A60BC
 * Данные: DAT_300a60d0, DAT_300a6720, DAT_300a6748, DAT_300a674c
 * ---------------------------------------------------------------- */
char * FUN_300a609c(uint param_1)

{
  char *pcVar1;
  
  pcVar1 = DAT_300a6748;
  if (param_1 == 0x66) {
    return DAT_300a6720;
  }
  if (param_1 < 0x1f) {
                    /* WARNING: Could not recover jumptable at 0x300a60bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (char *)(**(code **)(DAT_300a60d0 + param_1 * 4))();
    return pcVar1;
  }
  memset(DAT_300a6748,0,0x28);
  snprintf(pcVar1,0x28,DAT_300a674c,param_1);
  return pcVar1;
}

/* ----------------------------------------------------------------
 * FUN_300a61e8 @ 0x300A61E8  (примерный размер ~212 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300a62bc
 * Константы: 0x300A61E8, 0xFFFFFFFF
 * Данные: DAT_300a6750, DAT_300a6754
 * ---------------------------------------------------------------- */
undefined4 FUN_300a61e8(int param_1,ushort *param_2,ushort *param_3,uint param_4)

{
  undefined4 uVar1;
  ushort unaff_r6;
  uint uVar2;
  ushort uVar3;
  
  if ((param_1 == 1) || (param_1 == 2)) {
    uVar2 = param_4 >> 0x18 & 1;
    uVar3 = *param_2 & 0xf000 | (ushort)(param_4 >> 0xc) & (ushort)DAT_300a6750;
    *param_2 = uVar3;
    if (uVar2 != 0) {
      *param_2 = uVar3 | 0x400;
    }
    if (param_1 == 1) {
      unaff_r6 = 0xd000;
    }
    else if (param_1 == 2) {
      unaff_r6 = 0x9000;
    }
    uVar3 = unaff_r6 & *param_3 | (ushort)(param_4 >> 1) & (ushort)DAT_300a6754;
    *param_3 = uVar3;
    if ((~(param_4 >> 0x17 & 1 ^ uVar2) & 1) != 0) {
      uVar3 = uVar3 | 0x2000;
      *param_3 = uVar3;
    }
    if ((~(param_4 >> 0x16 & 1 ^ uVar2) & 1) != 0) {
      *param_3 = uVar3 | 0x800;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300a62bc @ 0x300A62BC  (примерный размер ~336 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300a609c, FUN_300a61e8, errnoSet, printErr
 * Константы: 0xFFFFFFFF, 0xFF000000, 0x01FFFFFF, 0x300A62BC
 * Данные: DAT_300a6758, DAT_300a675c, DAT_300a6760, DAT_300a6764, DAT_300a6768, DAT_300a676c, DAT_300a6770, DAT_300a6774
 * ---------------------------------------------------------------- */
undefined4
FUN_300a62bc(int param_1,undefined2 *param_2,int param_3,int param_4,byte param_5,undefined4 param_6
            ,undefined4 param_7,undefined4 param_8,int param_9)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined2 local_28;
  undefined2 local_26;
  
  if ((param_9 != 0x1c) && (param_9 != 0x1e)) {
    printErr(DAT_300a6758);
    errnoSet(DAT_300a675c);
  }
  local_26 = *param_2;
  local_28 = param_2[1];
  if (param_1 == 9) {
    uVar1 = FUN_300a609c(param_9);
    printErr(DAT_300a6760,uVar1,param_7,param_9);
    errnoSet(DAT_300a6764);
    uVar1 = 0xffffffff;
  }
  else {
    uVar3 = (uint)((param_5 & 0x80) != 0);
    uVar4 = (uVar3 | param_3 + param_4) - (int)param_2;
    if (((uVar4 & 0xff000000) == 0) || ((uVar4 & 0xff000000) == 0xff000000)) {
      iVar2 = FUN_300a61e8(1,&local_26,&local_28,uVar4,uVar3);
      if (iVar2 == -1) {
        printErr(DAT_300a6770);
        errnoSet(DAT_300a6774);
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = 0;
        *param_2 = local_26;
        param_2[1] = local_28;
      }
    }
    else {
      uVar1 = FUN_300a609c(param_9);
      printErr(DAT_300a6768,uVar1,param_7,param_2,param_3,param_4,uVar4,uVar4,uVar4 & 0x1ffffff,
               uVar4 & 0x1ffffff);
      errnoSet(DAT_300a676c);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300a640c @ 0x300A640C  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A640C
 * ---------------------------------------------------------------- */
undefined4 FUN_300a640c(int param_1,uint *param_2,int param_3,int param_4,byte param_5)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = *param_2;
  if (param_1 == 4) {
    uVar2 = uVar2 + param_4;
  }
  uVar1 = param_5 & 0x80;
  bVar3 = (param_5 & 0x80) == 0;
  if (bVar3) {
    uVar1 = 0;
  }
  if (!bVar3) {
    uVar1 = 1;
  }
  *param_2 = param_3 + uVar2 | uVar1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300a6448 @ 0x300A6448  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A6448
 * ---------------------------------------------------------------- */
undefined4 FUN_300a6448(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (param_1 == 4) {
    iVar1 = iVar1 + param_4;
  }
  *param_2 = (param_3 + iVar1) - (int)param_2;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300a6470 @ 0x300A6470  (примерный размер ~224 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: errnoSet, printErr
 * Константы: 0xFFFFFFFF, 0x300A6470, 0x00400000
 * Данные: DAT_300a6754, DAT_300a676c, DAT_300a6774, DAT_300a6778, DAT_300a677c, DAT_300a6780, DAT_300a6784
 * ---------------------------------------------------------------- */
undefined4
FUN_300a6470(int param_1,ushort *param_2,int param_3,undefined1 param_4,undefined4 param_5,
            int param_6)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = ((*param_2 & DAT_300a6754) << 0xc & DAT_300a6778 ^ 0x400000) +
          (param_2[1] & DAT_300a6754) * 2 + DAT_300a677c;
  if (param_1 == 4) {
    iVar4 = iVar4 + param_6;
  }
  uVar2 = iVar4 + (param_3 - (int)param_2);
  if (((uVar2 & DAT_300a677c) == 0) || ((uVar2 & DAT_300a677c) == DAT_300a677c)) {
    if ((uVar2 & 1) == 0) {
      uVar1 = (ushort)DAT_300a6754;
      *param_2 = *param_2 & 0xf800 | (ushort)(uVar2 >> 0xc) & uVar1;
      param_2[1] = param_2[1] & 0xf800 | (ushort)(uVar2 >> 1) & uVar1;
      uVar3 = 0;
    }
    else {
      printErr(DAT_300a6784,param_5,param_4);
      errnoSet(DAT_300a6774);
      uVar3 = 0xffffffff;
    }
  }
  else {
    printErr(DAT_300a6780,param_5,param_4);
    errnoSet(DAT_300a676c);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300a6550 @ 0x300A6550  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: errnoSet, printErr
 * Вызывают: FUN_300a66cc
 * Константы: 0xFFFFFF00, 0xFFFFFFFF, 0x300A6550
 * Данные: DAT_300a676c, DAT_300a6774, DAT_300a6784, DAT_300a6788, DAT_300a678c
 * ---------------------------------------------------------------- */
undefined4
FUN_300a6550(int param_1,ushort *param_2,int param_3,undefined1 param_4,undefined4 param_5,
            int param_6)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = ((*param_2 & 0xff) << 1 & DAT_300a6788 ^ 0x100) - 0x100;
  if (param_1 == 4) {
    iVar3 = iVar3 + param_6;
  }
  uVar1 = (param_3 + iVar3) - (int)param_2;
  if (((uVar1 & 0xffffff00) == 0) || ((uVar1 & 0xffffff00) == 0xffffff00)) {
    if ((uVar1 & 1) == 0) {
      *param_2 = *param_2 & 0xff00 | (ushort)(uVar1 >> 1) & 0xff;
      uVar2 = 0;
    }
    else {
      printErr(DAT_300a6784,param_5,param_4);
      errnoSet(DAT_300a6774);
      uVar2 = 0xffffffff;
    }
  }
  else {
    printErr(DAT_300a678c,param_5,param_4);
    errnoSet(DAT_300a676c);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300a660c @ 0x300A660C  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: errnoSet, printErr
 * Вызывают: FUN_300a66cc
 * Константы: 0xFFFFFFFF, 0x300A660C
 * Данные: DAT_300a6754, DAT_300a676c, DAT_300a6774, DAT_300a6784, DAT_300a6790, DAT_300a6794, DAT_300a6798
 * ---------------------------------------------------------------- */
undefined4
FUN_300a660c(int param_1,ushort *param_2,int param_3,undefined1 param_4,undefined4 param_5,
            int param_6)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = ((*param_2 & DAT_300a6754) << 1 & DAT_300a6794 ^ 0x800) + DAT_300a6790;
  if (param_1 == 4) {
    iVar3 = iVar3 + param_6;
  }
  uVar1 = (param_3 + iVar3) - (int)param_2;
  if (((uVar1 & DAT_300a6790) == 0) || ((uVar1 & DAT_300a6790) == DAT_300a6790)) {
    if ((uVar1 & 1) == 0) {
      *param_2 = *param_2 & 0xf800 | (ushort)(uVar1 >> 1) & (ushort)DAT_300a6754;
      uVar2 = 0;
    }
    else {
      printErr(DAT_300a6784,param_5,param_4);
      errnoSet(DAT_300a6774);
      uVar2 = 0xffffffff;
    }
  }
  else {
    printErr(DAT_300a6798,param_5,param_4);
    errnoSet(DAT_300a676c);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300a66cc @ 0x300A66CC  (примерный размер ~752 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300a6550, FUN_300a660c, errnoSet, printErr
 * Вызывают: elfArchReloc
 * Константы: 0xFFFFFFFF, 0x300A66CC, 0x300A6710
 * Данные: DAT_300a679c, DAT_300a6efc, DAT_300a6f00
 * ---------------------------------------------------------------- */
undefined4
FUN_300a66cc(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_4 & 0xff;
  if (uVar3 == 0x66) {
    iVar2 = FUN_300a660c(param_1,param_2,param_3,param_4,param_5,param_6,param_8);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
LAB_300a69b0:
    uVar1 = 0;
  }
  else {
    if (uVar3 < 0x67) {
      if (uVar3 < 0x1f) {
                    /* WARNING: Could not recover jumptable at 0x300a6710. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (**(code **)(DAT_300a679c + uVar3 * 4))();
        return uVar1;
      }
    }
    else if (uVar3 == 0x67) {
      iVar2 = FUN_300a6550(param_1,param_2,param_3,param_4,param_5,param_6,param_8);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      goto LAB_300a69b0;
    }
    printErr(DAT_300a6efc,uVar3);
    errnoSet(DAT_300a6f00);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300a69bc @ 0x300A69BC  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300a6a38
 * Константы: 0xFFFFFFFF, 0x300A69BC
 * Данные: DAT_300a6f04
 * ---------------------------------------------------------------- */
undefined4
FUN_300a69bc(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,byte param_6)

{
  undefined4 uVar1;
  int iVar2;
  uint local_18;
  
  if ((code *)*DAT_300a6f04 == (code *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = (*(code *)*DAT_300a6f04)(*param_1,param_4,param_5,&local_18);
    if (iVar2 == 0) {
      if ((param_6 & 0x80) != 0) {
        local_18 = local_18 | 1;
      }
      uVar1 = 0;
      *param_1 = local_18;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300a6a38 @ 0x300A6A38  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300a69bc, errnoSet, printErr
 * Вызывают: elfArchReloc
 * Константы: 0xFFFFFFFF, 0x300A6A38
 * Данные: DAT_300a6efc, DAT_300a6f00
 * ---------------------------------------------------------------- */
undefined4
FUN_300a6a38(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined1 param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_2 + 4) & 0xff;
  if (uVar3 == 2) {
    iVar1 = FUN_300a69bc(param_1,param_2,param_3,param_4,param_5,param_6);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
LAB_300a6ad4:
    uVar2 = 0;
  }
  else {
    if (uVar3 < 3) {
      if ((uVar3 == 0) || (uVar3 == 1)) goto LAB_300a6ad4;
    }
    else if ((uVar3 == 0x14) || (uVar3 == 0x16)) goto LAB_300a6ad4;
    printErr(DAT_300a6efc,uVar3);
    errnoSet(DAT_300a6f00);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * elfArchReloc @ 0x300A6AE0  (примерный размер ~616 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_300a66cc, FUN_300a6a38, __udiv32, errnoSet, loadElfRelaEntryRead, loadModuleSeek, printErr, puts
 * Вызывают: FUN_300f9964
 * Константы: 0xFFFFFFFF, 0x300A6AE0
 * Данные: DAT_300a6f04, DAT_300a6f08, DAT_300a6f0c, DAT_300a6f10, DAT_300a6f14, DAT_300a6f18, DAT_300a6f1c
 * ---------------------------------------------------------------- */
undefined4
elfArchReloc(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,int param_7)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  uint local_34;
  undefined4 local_30;
  
  if (param_2 == 0) {
    printErr(DAT_300a6f08);
    return 0xffffffff;
  }
  if (*(int *)(param_3 + 4) == 4) {
    if (*(int *)(param_3 + 0x24) != 0xc) {
      printErr(DAT_300a6f0c);
      errnoSet(DAT_300a6f10);
      return 0xffffffff;
    }
  }
  else {
    if (*(int *)(param_3 + 4) != 9) {
      printErr(DAT_300a6f14);
      errnoSet(DAT_300a6f10);
      return 0xffffffff;
    }
    if (*(int *)(param_3 + 0x24) != 8) {
      printErr(DAT_300a6f0c);
      errnoSet(DAT_300a6f10);
      return 0xffffffff;
    }
  }
  iVar3 = __udiv32(*(undefined4 *)(param_3 + 0x14),*(undefined4 *)(param_3 + 0x24));
  iVar4 = loadModuleSeek(param_2,*(undefined4 *)(param_3 + 0x10),0);
  if (iVar4 == -1) {
    uVar5 = 0xffffffff;
  }
  else {
    bVar2 = false;
    if (iVar3 != 0) {
      do {
        iVar4 = loadElfRelaEntryRead(param_2,&local_38,param_1);
        if (iVar4 == -1) {
          return 0xffffffff;
        }
        local_44 = local_30;
        iVar4 = (local_34 >> 8) * 0xc;
        bVar1 = *(byte *)(param_7 + iVar4 + 4);
        if ((((bVar1 & 2) == 0) || (*(int *)(param_2 + 0xc) != 3)) &&
           (iVar4 = *(int *)(param_7 + iVar4), iVar4 != 0)) {
          iVar6 = *(int *)(param_2 + 0xc);
          if (iVar6 == 5) {
            local_48 = param_4 + local_38;
            iVar4 = FUN_300a66cc(*(undefined4 *)(param_3 + 4),local_48,iVar4,local_34,local_38,
                                 local_30,bVar1,param_1);
          }
          else {
            if (iVar6 != 3) {
              if ((iVar6 != 1) && (iVar6 != 2)) {
                puts(DAT_300a6f1c);
              }
              goto LAB_300a6d34;
            }
            if ((code *)*DAT_300a6f04 == (code *)0x0) {
              return 0xffffffff;
            }
            local_40 = param_5;
            local_3c = param_6;
            iVar6 = (*(code *)*DAT_300a6f04)(local_38,param_5,param_6,&local_48);
            if (iVar6 != 0) {
              bVar2 = true;
              errnoSet(DAT_300a6f18);
              break;
            }
            local_40 = param_5;
            local_3c = param_6;
            iVar4 = FUN_300a6a38(local_48,&local_38,iVar4,param_5,param_6,bVar1);
          }
          if (iVar4 != 0) {
            bVar2 = true;
          }
        }
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      if (bVar2) {
        return 0xffffffff;
      }
    }
LAB_300a6d34:
    uVar5 = 0;
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * elfArchVerify @ 0x300A6D48  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: FUN_300fa5c4
 * Константы: 0x300A6D48
 * Данные: DAT_300a6f20
 * ---------------------------------------------------------------- */
int elfArchVerify(int param_1)

{
  if (*(short *)(param_1 + 0x12) != 0x28) {
    errnoSet(DAT_300a6f20);
    param_1 = 0;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * FUN_300a6d68 @ 0x300A6D68  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A6D68
 * Данные: DAT_300a6f24
 * ---------------------------------------------------------------- */
undefined4 FUN_300a6d68(void)

{
  if (*(int *)(DAT_300a6f24 + 4) == 0) {
    *(undefined4 *)(DAT_300a6f24 + 4) = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300a6d90 @ 0x300A6D90  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300a6db8, FUN_300a6e24
 * Константы: 0x300A6D90
 * ---------------------------------------------------------------- */
undefined4 FUN_300a6d90(undefined4 param_1,uint param_2,int param_3)

{
  if ((param_3 != 0xd) && ((param_3 != 2 || ((param_2 & 1) == 0)))) {
    return 0;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300a6db8 @ 0x300A6DB8  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300a6d90, errnoSet, printErr
 * Вызывают: FUN_300a6e24
 * Константы: 0x300A6DB8, 0xFFFFFFFF
 * Данные: DAT_300a6f24, DAT_300a6f28, DAT_300a6f2c, DAT_300a6f30
 * ---------------------------------------------------------------- */
undefined4 FUN_300a6db8(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*param_3 == 0xd) || (*param_3 == 2)) {
    iVar2 = FUN_300a6d90(param_1,*param_2);
    uVar1 = DAT_300a6f28;
    *DAT_300a6f24 = DAT_300a6f28;
    if (iVar2 != 0) {
      printErr(DAT_300a6f2c,uVar1,param_1,uVar1);
      errnoSet(DAT_300a6f30);
      return 0xffffffff;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300a6e24 @ 0x300A6E24  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300a6d90, FUN_300a6db8
 * Вызывают: FUN_300a6ea0
 * Константы: 0x300A6E24, 0xFFFFFFFF, 0xFFFFFFF0, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4
FUN_300a6e24(undefined4 param_1,uint *param_2,uint *param_3,undefined4 param_4,uint *param_5,
            undefined4 param_6,undefined4 param_7,uint param_8)

{
  int iVar1;
  uint uVar2;
  
  if (((param_8 & 0x80) == 0) && (iVar1 = FUN_300a6db8(), iVar1 == -1)) {
    return 0xffffffff;
  }
  uVar2 = *param_2;
  iVar1 = FUN_300a6d90(param_1,uVar2,*param_3);
  if (iVar1 != 0) {
    *param_5 = *param_5 | 0x80;
    *param_3 = *param_3 & 0xfffffff0 | 2;
    *param_2 = uVar2 & 0xfffffffe;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300a6ea0 @ 0x300A6EA0  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300a6e24
 * Константы: 0x300A6EA0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300a6ea0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_300a6e24();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300a6ee8 @ 0x300A6EE8  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A6EE8
 * ---------------------------------------------------------------- */
undefined4 FUN_300a6ee8(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * armInitExceptionModes @ 0x300A6F6C  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: excVecInit
 * Константы: 0x300A6F6C
 * Данные: DAT_300a6f44
 * ---------------------------------------------------------------- */
int armInitExceptionModes(void)

{
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  *(undefined4 *)(DAT_300a6f44 + -4) = 0;
  return (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
}

/* ----------------------------------------------------------------
 * objVerify @ 0x300A8DA4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 100 | Вызывает: 1
 * Вызывает: errnoSet
 * Вызывают: FUN_300c8154, FUN_300e3008, FUN_300e6c9c, FUN_300eeac8, FUN_300f2198, FUN_300f5e28, FUN_30122acc, FUN_30122fd4, FUN_30123a80, FUN_30128940
 *           ...
 * Константы: 0x300A8DA4, 0xFFFFFFFF
 * Данные: DAT_300a8da0
 * ---------------------------------------------------------------- */
undefined4 objVerify(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  bVar2 = param_1 == iVar1;
  if (bVar2) {
    iVar1 = (int)*(char *)(param_1 + 10);
    param_4 = *(int *)(param_2 + 0x38);
  }
  if (!bVar2 || iVar1 != param_4) {
    errnoSet(DAT_300a8da0);
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * objVerifyTypeRead @ 0x300A8DAC  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoSet
 * Константы: 0x300A8DAC, 0xFFFFFFFF
 * Данные: DAT_300a8da0
 * ---------------------------------------------------------------- */
undefined4 objVerifyTypeRead(int param_1,int param_2)

{
  bool in_ZR;
  
  if (in_ZR) {
    in_ZR = (int)*(char *)(param_1 + 10) == *(int *)(param_2 + 0x38);
  }
  if (!in_ZR) {
    errnoSet(DAT_300a8da0);
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * objVerifyError @ 0x300A8DC0  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoSet
 * Константы: 0x300A8DC0, 0xFFFFFFFF
 * Данные: DAT_300a8da0
 * ---------------------------------------------------------------- */
undefined4 objVerifyError(void)

{
  errnoSet(DAT_300a8da0);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * objArchLibInit @ 0x300A8DD8  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: objLibInit
 * Константы: 0x300A8DD8
 * Данные: DAT_300a8e68, DAT_300a8e6c, DAT_300a8e70
 * ---------------------------------------------------------------- */
undefined4 objArchLibInit(void)

{
  *DAT_300a8e6c = *DAT_300a8e68;
  *DAT_300a8e68 = DAT_300a8e70;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300a8dfc @ 0x300A8DFC  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A8DFC
 * Данные: DAT_300a8e6c, DAT_300a8e74, DAT_300a8e78, DAT_300a8e7c
 * ---------------------------------------------------------------- */
undefined4 FUN_300a8dfc(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (((DAT_300a8e74 == *(int *)(param_3 + 0x3c)) || (DAT_300a8e78 == *(int *)(param_3 + 0x3c))) &&
     (param_1 == 0x10)) {
    uVar1 = 1;
    *param_2 = DAT_300a8e7c;
  }
  else if ((code *)*DAT_300a8e6c == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)*DAT_300a8e6c)();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sigsetjmp @ 0x300A8E84  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: _setjmpSetup, _sigCtxSave
 * Константы: 0x300A8E84
 * ---------------------------------------------------------------- */
void sigsetjmp(undefined4 param_1,undefined4 param_2)

{
  _setjmpSetup();
  _sigCtxSave(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * setjmp @ 0x300A8E94  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: _setjmpSetup
 * Вызывают: memPartEdrErrorInject, reboot
 * Константы: 0x300A8E94
 * ---------------------------------------------------------------- */
int setjmp(__jmp_buf_tag *__env)

{
  int extraout_r1;
  int in_r2;
  int in_r3;
  int unaff_r4;
  int unaff_r5;
  int unaff_r6;
  ulong unaff_r7;
  ulong unaff_r8;
  ulong unaff_r9;
  ulong unaff_r10;
  ulong unaff_r11;
  ulong in_r12;
  ulong in_lr;
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  _setjmpSetup(__env,1);
  (__env->__saved_mask).__val[8] = in_lr;
  (__env->__saved_mask).__val[9] =
       (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
  __env->__jmpbuf[1] = extraout_r1;
  __env->__jmpbuf[2] = in_r2;
  __env->__jmpbuf[3] = in_r3;
  __env->__jmpbuf[4] = unaff_r4;
  __env->__jmpbuf[5] = unaff_r5;
  __env->__mask_was_saved = unaff_r6;
  (__env->__saved_mask).__val[0] = unaff_r7;
  (__env->__saved_mask).__val[1] = unaff_r8;
  (__env->__saved_mask).__val[2] = unaff_r9;
  (__env->__saved_mask).__val[3] = unaff_r10;
  (__env->__saved_mask).__val[4] = unaff_r11;
  (__env->__saved_mask).__val[5] = in_r12;
  (__env->__saved_mask).__val[6] = (ulong)register0x00000054;
  return 0;
}

/* ----------------------------------------------------------------
 * _sigCtxSave @ 0x300A8EA4  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300e4ac4, FUN_300e55ec, sigsetjmp
 * Константы: 0x300A8EA4
 * ---------------------------------------------------------------- */
undefined4 _sigCtxSave(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 in_r12;
  undefined4 in_lr;
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  *(undefined4 *)(param_1 + 0x3c) = in_lr;
  *(uint *)(param_1 + 0x40) =
       (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x10) = unaff_r4;
  *(undefined4 *)(param_1 + 0x14) = unaff_r5;
  *(undefined4 *)(param_1 + 0x18) = unaff_r6;
  *(undefined4 *)(param_1 + 0x1c) = unaff_r7;
  *(undefined4 *)(param_1 + 0x20) = unaff_r8;
  *(undefined4 *)(param_1 + 0x24) = unaff_r9;
  *(undefined4 *)(param_1 + 0x28) = unaff_r10;
  *(undefined4 *)(param_1 + 0x2c) = unaff_r11;
  *(undefined4 *)(param_1 + 0x30) = in_r12;
  *(BADSPACEBASE **)(param_1 + 0x34) = register0x00000054;
  return 0;
}

/* ----------------------------------------------------------------
 * _sigCtxLoad @ 0x300A8EC0  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: longjmp, sigreturn
 * Константы: 0x300A8EC0, 0x300A8EF4
 * ---------------------------------------------------------------- */
undefined8 _sigCtxLoad(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if ((*(uint *)(param_1 + 8) & 0xf) != 0) {
    return *param_1;
  }
                    /* WARNING: Could not recover jumptable at 0x300a8ef4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)((int)param_1 + 0x3c))
                    (*(undefined4 *)param_1,*(undefined4 *)((int)param_1 + 4),
                     *(undefined4 *)(param_1 + 1),*(undefined4 *)((int)param_1 + 0xc));
  return uVar1;
}

/* ----------------------------------------------------------------
 * _sigCtxRtnValSet @ 0x300A8EF8  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300e4ac4, FUN_300e55ec, longjmp
 * Константы: 0x300A8EF8
 * ---------------------------------------------------------------- */
void _sigCtxRtnValSet(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}

/* ----------------------------------------------------------------
 * _sigCtxStackEnd @ 0x300A8F00  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300e55ec
 * Константы: 0x300A8F00
 * ---------------------------------------------------------------- */
undefined4 _sigCtxStackEnd(int param_1)

{
  return *(undefined4 *)(param_1 + 0x34);
}

/* ----------------------------------------------------------------
 * _sigCtxSetup @ 0x300A8F08  (примерный размер ~260 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: bzero
 * Вызывают: FUN_300e55ec
 * Константы: 0x300A8F08, 0xFFFFFFFC
 * Данные: DAT_300a9000, DAT_300a9004, DAT_300a9008
 * ---------------------------------------------------------------- */
void _sigCtxSetup(void *param_1,uint param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (*DAT_300a9000 == 0) {
    uVar2 = *DAT_300a9004;
  }
  else {
    uVar2 = *(undefined4 *)(*DAT_300a9000 + 0x94);
  }
  bzero(param_1,0x48);
  *(undefined4 *)((int)param_1 + 0x40) = 0x13;
  *(undefined4 *)((int)param_1 + 0x3c) = param_3;
  if ((code *)*DAT_300a9008 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*(code *)*DAT_300a9008)(uVar2);
  }
  *(undefined4 *)((int)param_1 + 0x44) = uVar2;
  piVar3 = (int *)(param_2 & 0xfffffffc);
  iVar4 = *param_4;
  if (4 < iVar4) {
    piVar1 = param_4 + iVar4 + 1;
    iVar5 = iVar4 + -4;
    do {
      iVar4 = iVar5;
      piVar1 = piVar1 + -1;
      iVar5 = iVar4 + -1;
      piVar3 = piVar3 + -1;
      *piVar3 = *piVar1;
    } while (iVar5 != 0);
    iVar4 = iVar4 + 3;
  }
  if (0 < iVar4) {
    piVar1 = (int *)((int)param_1 + iVar4 * 4);
    param_4 = param_4 + iVar4 + 1;
    do {
      param_4 = param_4 + -1;
      iVar4 = iVar4 + -1;
      piVar1 = piVar1 + -1;
      *piVar1 = *param_4;
    } while (iVar4 != 0);
  }
  *(int **)((int)param_1 + 0x34) = piVar3;
  return;
}

/* ----------------------------------------------------------------
 * rotate_N_bits @ 0x300A91B8  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300a9264
 * Константы: 0x300A91B8
 * ---------------------------------------------------------------- */
uint rotate_N_bits(uint param_1,uint param_2)

{
  return param_2 >> (param_1 & 0x1f) | param_2 << 0x20 - (param_1 & 0x1f);
}

/* ----------------------------------------------------------------
 * FUN_300a91c4 @ 0x300A91C4  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300a9264
 * Константы: 0x300A91C4, 0x300A91E8
 * Данные: DAT_300a91ec
 * ---------------------------------------------------------------- */
undefined4 FUN_300a91c4(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar2 = param_1 >> ((uVar3 & 0x3f) << 2) & 0xf;
    if (uVar2 < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x300a91e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(DAT_300a91ec + uVar2 * 4))();
      return uVar1;
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 3);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300a9264 @ 0x300A9264  (примерный размер ~700 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_300a91c4, rotate_N_bits, vxCpuConfiguredGet
 * Вызывают: FUN_300a9520, FUN_300a9560
 * Константы: 0x300A9264, 0xFFFFFFFF
 * Данные: DAT_300a95f8, DAT_300a95fc, DAT_300a9600, DAT_300a9604, DAT_300a961c, DAT_300a9620
 * ---------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_300a9264(undefined4 *param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6,int *param_7)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 *puVar8;
  int local_3c;
  uint *local_34;
  
  local_3c = 0;
  uVar1 = vxCpuConfiguredGet();
  if ((((uVar1 < 2) && (((uint)param_3 & 3) == 0)) && ((undefined4 *)param_1[1] < param_3)) &&
     ((param_3 < (undefined4 *)*param_1 &&
      (iVar2 = (*(code *)param_1[2])(param_2,param_1), puVar7 = param_2, puVar8 = param_3,
      iVar2 == 0)))) {
    while (puVar4 = param_3, puVar5 = (uint *)0x0, local_3c < 2000) {
      uVar1 = *puVar7;
      puVar5 = puVar7;
      if ((uVar1 & DAT_300a95f8) == DAT_300a95fc) {
        iVar2 = FUN_300a91c4(uVar1 & DAT_300a9600);
        param_4 = puVar8 + iVar2;
        if ((uVar1 & 0x800) != 0) {
          puVar8 = param_4 + 1;
        }
        puVar7 = puVar7 + -1;
        iVar2 = (*(code *)param_1[2])(puVar7,param_1);
        puVar4 = puVar8;
        if ((iVar2 == 0) && ((*puVar7 & DAT_300a9604) == _LAB_300a9608)) {
          puVar4 = (undefined4 *)((int)puVar8 + (*puVar7 & DAT_300a9600));
          puVar5 = puVar7;
        }
        break;
      }
      if ((uVar1 & DAT_300a9604) == _LAB_300a9608) {
        puVar8 = (undefined4 *)((int)puVar8 + (uVar1 & DAT_300a9600));
      }
      if (uVar1 == _LAB_300a960c) {
        puVar4 = (undefined4 *)((int)puVar8 + (uVar1 & DAT_300a9600));
        param_4 = puVar8;
        break;
      }
      if (uVar1 == _LAB_300a9610) {
        puVar5 = puVar7 + -1;
        iVar2 = (*(code *)param_1[2])(puVar5,param_1);
        if (iVar2 == 0) {
          uVar1 = *puVar5;
          uVar6 = uVar1 & DAT_300a9604;
          if (uVar6 == _LAB_300a9614) {
            iVar2 = rotate_N_bits();
            puVar8 = (undefined4 *)((int)puVar8 + iVar2);
          }
          if (uVar6 == _LAB_300a9618) {
            puVar8 = (undefined4 *)
                     ((int)puVar8 + *(int *)((int)puVar5 + (uVar1 & DAT_300a9600) + 8));
          }
        }
      }
      puVar4 = puVar8;
      if ((uVar1 & DAT_300a961c) == DAT_300a9620) break;
      puVar7 = puVar5 + -1;
      iVar2 = (*(code *)param_1[2])(puVar7,param_1);
      puVar4 = param_3;
      puVar5 = (uint *)0x0;
      local_3c = local_3c + 1;
      if (iVar2 != 0) break;
    }
    local_34 = param_2;
    if (puVar5 != (uint *)0x0) {
      local_34 = puVar5;
    }
    *param_7 = (int)local_34;
    *param_5 = puVar4;
    if ((((((uint)param_4 & 3) == 0) && ((undefined4 *)param_1[1] < param_4)) &&
        (param_4 < (undefined4 *)*param_1)) &&
       (iVar2 = (*(code *)param_1[2])(*param_4,param_1), iVar2 == 0)) {
      uVar3 = *param_4;
    }
    else {
      uVar3 = 0;
    }
    *param_6 = uVar3;
    uVar3 = 0;
  }
  else {
    *param_5 = 0;
    uVar3 = 0xffffffff;
    *param_6 = 0;
    *param_7 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300a9520 @ 0x300A9520  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300a9264
 * Константы: 0x300A9520
 * ---------------------------------------------------------------- */
void FUN_300a9520(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_300a9264(param_3,param_2,param_1,0,param_4,param_5,param_6);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a9558 @ 0x300A9558  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A9558, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300a9558(void)

{
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300a9560 @ 0x300A9560  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300a9264
 * Константы: 0x300A9560
 * ---------------------------------------------------------------- */
void FUN_300a9560(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = *(undefined4 *)(iVar2 + 0x34);
  *param_2 = uVar1;
  FUN_300a9264(param_1,*(undefined4 *)(iVar2 + 0x3c),uVar1,*(undefined4 *)(iVar2 + 0x38),param_3,
               param_4,param_5);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300a959c @ 0x300A959C  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A959C
 * Данные: DAT_300a9624
 * ---------------------------------------------------------------- */
void FUN_300a959c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x28);
  iVar1 = (**(code **)(param_2 + 8))(iVar2 + -4);
  if ((iVar1 == 0) && (*(int *)(iVar2 + -4) == DAT_300a9624)) {
    iVar1 = *(int *)(param_2 + 0xc);
    *(int *)(iVar1 + 0x3c) = iVar2;
    *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(param_2 + 0x10) = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * atomic32Clear @ 0x300A968C  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: vxdbgBpMsgQCreate
 * Константы: 0x300A968C
 * ---------------------------------------------------------------- */
undefined4 atomic32Clear(undefined4 *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  do {
    uVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = 0;
  return uVar2;
}

/* ----------------------------------------------------------------
 * atomic32Set @ 0x300A9690  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300c906c, vxCpuReservedGet
 * Константы: 0x300A9690
 * ---------------------------------------------------------------- */
undefined4 atomic32Set(undefined4 *param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  
  do {
    uVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = param_2;
  return uVar2;
}

/* ----------------------------------------------------------------
 * atomic32Get @ 0x300A96A8  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300c906c, FUN_300cf1d0, vxdbgBpMsgGet
 * Константы: 0x300A96A8
 * ---------------------------------------------------------------- */
undefined4 atomic32Get(undefined4 *param_1)

{
  return *param_1;
}

/* ----------------------------------------------------------------
 * atomic32Inc @ 0x300A96B0  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 12 | Вызывает: 0
 * Вызывают: FUN_300cc194, FUN_300cd2a8, FUN_300cd79c, FUN_300cdb24, FUN_300ce044, FUN_300ceaec, FUN_300ed68c, FUN_300ed6dc, FUN_3010df20, logMsg
 *           ...
 * Константы: 0x300A96B0
 * ---------------------------------------------------------------- */
int atomic32Inc(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  do {
    iVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = iVar2 + 1;
  return iVar2;
}

/* ----------------------------------------------------------------
 * atomic32Add @ 0x300A96B4  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A96B4
 * ---------------------------------------------------------------- */
int atomic32Add(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  do {
    iVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = iVar2 + param_2;
  return iVar2;
}

/* ----------------------------------------------------------------
 * atomic32Dec @ 0x300A96D0  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 11 | Вызывает: 0
 * Вызывают: FUN_300c906c, FUN_300cc150, FUN_300cd078, FUN_300cdb24, FUN_300cefe8, FUN_300cf1d0, FUN_300ed734, FUN_300ed794, FUN_3010df20, FUN_30111020
 *           ...
 * Константы: 0x300A96D0
 * ---------------------------------------------------------------- */
int atomic32Dec(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  do {
    iVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = iVar2 + -1;
  return iVar2;
}

/* ----------------------------------------------------------------
 * atomic32Sub @ 0x300A96D4  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A96D4
 * ---------------------------------------------------------------- */
int atomic32Sub(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  do {
    iVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = iVar2 - param_2;
  return iVar2;
}

/* ----------------------------------------------------------------
 * atomic32Nand @ 0x300A96F0  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A96F0
 * ---------------------------------------------------------------- */
uint atomic32Nand(uint *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  
  do {
    uVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = ~(uVar2 & param_2);
  return uVar2;
}

/* ----------------------------------------------------------------
 * atomic32And @ 0x300A9710  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A9710
 * ---------------------------------------------------------------- */
uint atomic32And(uint *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  
  do {
    uVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = uVar2 & param_2;
  return uVar2;
}

/* ----------------------------------------------------------------
 * atomic32Or @ 0x300A972C  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A972C
 * ---------------------------------------------------------------- */
uint atomic32Or(uint *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  
  do {
    uVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = uVar2 | param_2;
  return uVar2;
}

/* ----------------------------------------------------------------
 * atomic32Xor @ 0x300A9748  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A9748
 * ---------------------------------------------------------------- */
uint atomic32Xor(uint *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  
  do {
    uVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = uVar2 ^ param_2;
  return uVar2;
}

/* ----------------------------------------------------------------
 * atomic32Cas @ 0x300A9764  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A9764
 * ---------------------------------------------------------------- */
undefined4 atomic32Cas(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  
  do {
    if (*param_1 != param_2) {
      return 0;
    }
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = param_3;
  return 1;
}

/* ----------------------------------------------------------------
 * windExit @ 0x300A9AC4  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 60 | Вызывает: 2
 * Вызывает: windPwrDown, workQDoWork
 * Вызывают: FUN_300e43ec, FUN_300e4ac4, FUN_300e55ec, FUN_30122a44, FUN_30122f24, FUN_30122fd4, FUN_30124a88, FUN_30128940, _taskSuspend, eventReceive
 *           ...
 * Константы: 0x300A9AC4, 0x08000000, 0x300A9D4C
 * Данные: DAT_300a99e0, DAT_300a99e4, DAT_300a99e8, DAT_300a99ec, DAT_300a99f0, DAT_300a99f4, DAT_300a99f8, DAT_300a9a00
 * ---------------------------------------------------------------- */
longlong windExit(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  int *piVar10;
  undefined4 unaff_r11;
  undefined4 in_r12;
  undefined4 in_lr;
  char in_CY;
  char cVar11;
  char in_OV;
  char cVar12;
  char cVar13;
  bool bVar14;
  char cVar15;
  bool bVar16;
  bool bVar17;
  byte in_Q;
  byte bVar18;
  byte bVar19;
  longlong lVar20;
  
  iVar4 = *DAT_300a99e4;
  if (iVar4 != 0) {
    while (puVar1 = DAT_300a99e8, *DAT_300a99ec == 0) {
      workQDoWork();
    }
    *DAT_300a99e8 = 0;
    return ZEXT48(puVar1) << 0x20;
  }
  uVar9 = (uint)(byte)((iVar4 < 0) << 4 | (iVar4 == 0) << 3 | in_CY << 2 | in_OV << 1 | in_Q) <<
          0x1b;
  while( true ) {
    puVar1 = DAT_300a99e8;
    uVar5 = *DAT_300a99f0;
    uVar8 = uVar5 + 0x50 ^ *DAT_300a99f4;
    bVar14 = uVar8 == 0;
    if (!bVar14) break;
LAB_300a9a58:
    uVar9 = (uint)(byte)(((int)uVar8 < 0) << 4 | bVar14 << 3 | in_CY << 2 | in_OV << 1 | in_Q) <<
            0x1b;
    if (*DAT_300a99ec != 0) {
      *DAT_300a99e8 = 0;
      return ZEXT48(puVar1) << 0x20;
    }
    do {
      workQDoWork();
    } while (*DAT_300a99ec == 0);
    in_Q = (in_Q & 1) != 0;
    in_OV = (uVar9 >> 0x1c & 1) != 0;
    in_CY = (uVar9 >> 0x1d & 1) != 0;
  }
  if (*(int *)(uVar5 + 0x7c) != 0) {
    uVar8 = *(uint *)(uVar5 + 0x70);
    bVar14 = uVar8 == 0;
    if (bVar14) goto LAB_300a9a58;
  }
  *(undefined4 *)(uVar5 + 0x20c) = in_lr;
  *(uint *)(uVar5 + 0x210) = uVar9;
  *(undefined4 *)(uVar5 + 0x1d0) = 0;
  *(undefined4 *)(uVar5 + 0x1e0) = unaff_r4;
  *(undefined4 *)(uVar5 + 0x1e4) = unaff_r5;
  *(undefined4 *)(uVar5 + 0x1e8) = unaff_r6;
  *(undefined4 *)(uVar5 + 0x1ec) = unaff_r7;
  *(undefined4 *)(uVar5 + 0x1f0) = unaff_r8;
  *(undefined4 *)(uVar5 + 500) = unaff_r9;
  *(undefined4 *)(uVar5 + 0x1f8) = unaff_r10;
  *(undefined4 *)(uVar5 + 0x1fc) = unaff_r11;
  *(undefined4 *)(uVar5 + 0x200) = in_r12;
  *(BADSPACEBASE **)(uVar5 + 0x204) = register0x00000054;
  *(undefined4 *)(uVar5 + 0x1c4) = *DAT_300a99e0;
  uVar6 = coproc_movefrom_Translation_table_base_0();
  *(undefined4 *)(uVar5 + 0x214) = uVar6;
  *(int *)(uVar5 + 0x6c) = *(int *)(uVar5 + 0x6c) + 1;
  puVar2 = DAT_300a99f0;
  bVar19 = (in_Q & 1) != 0;
  uVar9 = *DAT_300a99f0;
  cVar13 = *DAT_300a99ec < 0;
  cVar15 = *DAT_300a99ec == 0;
  cVar11 = true;
  cVar12 = false;
  if (!(bool)cVar15) goto LAB_300a9b6c;
  do {
    while( true ) {
      workQDoWork(uVar5);
LAB_300a9b6c:
      puVar3 = DAT_300a99f4;
      uVar8 = (uint)(byte)(cVar13 << 4 | cVar15 << 3 | cVar11 << 2 | cVar12 << 1 | bVar19);
      uVar7 = uVar8 << 0x1b;
      uVar5 = uVar7 | 0x80;
      bVar18 = (uVar7 & 0x8000000) != 0;
      if (*DAT_300a99f4 == 0) break;
LAB_300a9c04:
      *DAT_300a99f8 = 0;
      bVar19 = (uVar7 >> 0x1b & 1) != 0;
      uVar7 = *puVar3;
      uVar8 = *puVar2;
      uVar5 = uVar7 - 0x50;
      bVar16 = uVar5 <= uVar8;
      bVar17 = SBORROW4(uVar8,uVar5);
      iVar4 = uVar8 - uVar5;
      bVar14 = uVar8 == uVar5;
      if (!bVar14) {
        uVar8 = (uint)(*(ushort *)(uVar7 + 0x54) | *(ushort *)(uVar8 + 0xa6));
        if (uVar8 != 0) {
          iVar4 = 0;
          do {
            if ((uVar8 & 1) != 0) {
              (**(code **)(DAT_300a9a00 + iVar4 * 4))(*puVar2,uVar5);
            }
            iVar4 = iVar4 + 1;
            uVar8 = uVar8 >> 1;
          } while (uVar8 != 0);
        }
        iVar4 = *DAT_300a9a04;
        uVar8 = 0;
        piVar10 = DAT_300a9a04;
        while( true ) {
          bVar14 = iVar4 == 0;
          bVar17 = false;
          bVar16 = true;
          if (bVar14) break;
          (*(code *)*piVar10)(*puVar2,uVar5);
          uVar7 = uVar8 + 1;
          bVar16 = 0xf < uVar7;
          bVar17 = SBORROW4(uVar7,0x10);
          iVar4 = uVar8 - 0xf;
          bVar14 = uVar7 == 0x10;
          if (0xf < (int)uVar7) break;
          piVar10 = piVar10 + 1;
          iVar4 = *piVar10;
          uVar8 = uVar7;
        }
        *puVar2 = uVar5;
      }
      uVar8 = (uint)(byte)((iVar4 < 0) << 4 | bVar14 << 3 | bVar16 << 2 | bVar17 << 1 | bVar19);
      uVar5 = uVar8 << 0x1b | 0x80;
      if (*DAT_300a99ec != 0) {
        *DAT_300a99e8 = 0;
        *(int *)(uVar9 + 0x6c) = *(int *)(uVar9 + 0x6c) + -1;
        *DAT_300a99e0 = *(undefined4 *)(*DAT_300a99f0 + 0x1c4);
        uVar9 = *DAT_300a99f0;
        if ((*(uint *)(uVar9 + 0x210) & 0xf) == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a9d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          lVar20 = (**(code **)(uVar9 + 0x20c))
                             (*(undefined4 *)(uVar9 + 0x1d0),*(undefined4 *)(uVar9 + 0x1d4),
                              *(undefined4 *)(uVar9 + 0x1d8),*(undefined4 *)(uVar9 + 0x1dc));
          return lVar20;
        }
        return *(longlong *)(uVar9 + 0x1d0);
      }
      uVar8 = uVar8 & 0x1f;
      bVar19 = (bVar19 & 1) != 0;
      cVar12 = (uVar8 >> 1 & 1) != 0;
      cVar11 = (uVar8 >> 2 & 1) != 0;
      cVar15 = (uVar8 >> 3 & 1) != 0;
      cVar13 = uVar8 >> 4 != 0;
    }
    if (*DAT_300a99ec != 0) {
      *DAT_300a99f8 = 1;
      *DAT_300a99e8 = 0;
      *(int *)(uVar9 + 0x6c) = *(int *)(uVar9 + 0x6c) + -1;
      windPwrDown();
      do {
      } while (*puVar3 == 0);
      uVar7 = (uint)bVar18 << 0x1b;
      *DAT_300a99e8 = 1;
      *(int *)(uVar9 + 0x6c) = *(int *)(uVar9 + 0x6c) + 1;
      goto LAB_300a9c04;
    }
    uVar8 = uVar8 & 0x1f;
    bVar19 = (bVar19 & 1) != 0;
    cVar12 = (uVar8 >> 1 & 1) != 0;
    cVar11 = (uVar8 >> 2 & 1) != 0;
    cVar15 = (uVar8 >> 3 & 1) != 0;
    cVar13 = uVar8 >> 4 != 0;
  } while( true );
}

/* ----------------------------------------------------------------
 * reschedule @ 0x300A9B50  (примерный размер ~424 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: windPwrDown, workQDoWork
 * Вызывают: intEnt, intExit
 * Константы: 0x300A9B50, 0x08000000, 0x300A9D4C
 * Данные: DAT_300a99e0, DAT_300a99e8, DAT_300a99ec, DAT_300a99f0, DAT_300a99f4, DAT_300a99f8, DAT_300a9a00, DAT_300a9a04
 * ---------------------------------------------------------------- */
undefined8 reschedule(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  byte in_Q;
  byte bVar16;
  undefined8 uVar17;
  
  puVar1 = DAT_300a99f0;
  uVar4 = *DAT_300a99f0;
  cVar11 = *DAT_300a99ec < 0;
  cVar12 = *DAT_300a99ec == 0;
  cVar9 = true;
  cVar10 = false;
  if (!(bool)cVar12) goto LAB_300a9b6c;
  do {
    while( true ) {
      workQDoWork(param_1);
LAB_300a9b6c:
      piVar5 = DAT_300a99f4;
      uVar3 = (uint)(byte)(cVar11 << 4 | cVar12 << 3 | cVar9 << 2 | cVar10 << 1 | in_Q);
      uVar2 = uVar3 << 0x1b;
      param_1 = uVar2 | 0x80;
      bVar16 = (uVar2 & 0x8000000) != 0;
      if (*DAT_300a99f4 == 0) break;
LAB_300a9c04:
      *DAT_300a99f8 = 0;
      bVar16 = (uVar2 >> 0x1b & 1) != 0;
      iVar8 = *piVar5;
      uVar3 = *puVar1;
      uVar2 = iVar8 - 0x50;
      bVar14 = uVar2 <= uVar3;
      bVar15 = SBORROW4(uVar3,uVar2);
      iVar6 = uVar3 - uVar2;
      bVar13 = uVar3 == uVar2;
      if (!bVar13) {
        uVar3 = (uint)(*(ushort *)(iVar8 + 0x54) | *(ushort *)(uVar3 + 0xa6));
        if (uVar3 != 0) {
          iVar6 = 0;
          do {
            if ((uVar3 & 1) != 0) {
              (**(code **)(DAT_300a9a00 + iVar6 * 4))(*puVar1,uVar2);
            }
            iVar6 = iVar6 + 1;
            uVar3 = uVar3 >> 1;
          } while (uVar3 != 0);
        }
        iVar6 = *DAT_300a9a04;
        uVar3 = 0;
        piVar5 = DAT_300a9a04;
        while( true ) {
          bVar13 = iVar6 == 0;
          bVar15 = false;
          bVar14 = true;
          if (bVar13) break;
          (*(code *)*piVar5)(*puVar1,uVar2);
          uVar7 = uVar3 + 1;
          bVar14 = 0xf < uVar7;
          bVar15 = SBORROW4(uVar7,0x10);
          iVar6 = uVar3 - 0xf;
          bVar13 = uVar7 == 0x10;
          if (0xf < (int)uVar7) break;
          piVar5 = piVar5 + 1;
          iVar6 = *piVar5;
          uVar3 = uVar7;
        }
        *puVar1 = uVar2;
      }
      uVar3 = (uint)(byte)((iVar6 < 0) << 4 | bVar13 << 3 | bVar14 << 2 | bVar15 << 1 | bVar16);
      param_1 = uVar3 << 0x1b | 0x80;
      if (*DAT_300a99ec != 0) {
        *DAT_300a99e8 = 0;
        *(int *)(uVar4 + 0x6c) = *(int *)(uVar4 + 0x6c) + -1;
        *DAT_300a99e0 = *(undefined4 *)(*DAT_300a99f0 + 0x1c4);
        uVar4 = *DAT_300a99f0;
        if ((*(uint *)(uVar4 + 0x210) & 0xf) == 0) {
                    /* WARNING: Could not recover jumptable at 0x300a9d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar17 = (**(code **)(uVar4 + 0x20c))
                             (*(undefined4 *)(uVar4 + 0x1d0),*(undefined4 *)(uVar4 + 0x1d4),
                              *(undefined4 *)(uVar4 + 0x1d8),*(undefined4 *)(uVar4 + 0x1dc));
          return uVar17;
        }
        return *(undefined8 *)(uVar4 + 0x1d0);
      }
      uVar3 = uVar3 & 0x1f;
      in_Q = (bVar16 & 1) != 0;
      cVar10 = (uVar3 >> 1 & 1) != 0;
      cVar9 = (uVar3 >> 2 & 1) != 0;
      cVar12 = (uVar3 >> 3 & 1) != 0;
      cVar11 = uVar3 >> 4 != 0;
    }
    if (*DAT_300a99ec != 0) {
      *DAT_300a99f8 = 1;
      *DAT_300a99e8 = 0;
      *(int *)(uVar4 + 0x6c) = *(int *)(uVar4 + 0x6c) + -1;
      windPwrDown();
      do {
      } while (*piVar5 == 0);
      uVar2 = (uint)bVar16 << 0x1b;
      *DAT_300a99e8 = 1;
      *(int *)(uVar4 + 0x6c) = *(int *)(uVar4 + 0x6c) + 1;
      goto LAB_300a9c04;
    }
    uVar3 = uVar3 & 0x1f;
    in_Q = (in_Q & 1) != 0;
    cVar10 = (uVar3 >> 1 & 1) != 0;
    cVar9 = (uVar3 >> 2 & 1) != 0;
    cVar12 = (uVar3 >> 3 & 1) != 0;
    cVar11 = uVar3 >> 4 != 0;
  } while( true );
}

/* ----------------------------------------------------------------
 * windLoadContext @ 0x300A9CF8  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300A9CF8, 0x300A9D4C
 * Данные: DAT_300a99e0, DAT_300a99f0
 * ---------------------------------------------------------------- */
undefined8 windLoadContext(void)

{
  int iVar1;
  undefined8 uVar2;
  
  *DAT_300a99e0 = *(undefined4 *)(*DAT_300a99f0 + 0x1c4);
  iVar1 = *DAT_300a99f0;
  if ((*(uint *)(iVar1 + 0x210) & 0xf) != 0) {
    return *(undefined8 *)(iVar1 + 0x1d0);
  }
                    /* WARNING: Could not recover jumptable at 0x300a9d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(iVar1 + 0x20c))
                    (*(undefined4 *)(iVar1 + 0x1d0),*(undefined4 *)(iVar1 + 0x1d4),
                     *(undefined4 *)(iVar1 + 0x1d8),*(undefined4 *)(iVar1 + 0x1dc));
  return uVar2;
}

/* ----------------------------------------------------------------
 * windIntStackSet @ 0x300A9D50  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: kernelInit
 * Константы: 0x300A9D50
 * ---------------------------------------------------------------- */
void windIntStackSet(void)

{
  return;
}

/* ----------------------------------------------------------------
 * dllInsert @ 0x300AA700  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 10 | Вызывает: 0
 * Вызывают: FUN_300cc974, FUN_300fc308, FUN_3011f5b4, FUN_3011fb94, qFifoPut, qFifoRestore, qPriBMapRestore, qPriDeltaPut, qPriListPut, qPriListPutFromTail
 * Константы: 0x300AA700
 * ---------------------------------------------------------------- */
void dllInsert(int *param_1,int *param_2,int *param_3)

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
  return;
}

/* ----------------------------------------------------------------
 * dllAdd @ 0x300AA740  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 17 | Вызывает: 0
 * Вызывают: FUN_300cb558, FUN_300cc7c8, FUN_300ccfe8, FUN_300cd2a8, FUN_300cdb24, FUN_300ce044, FUN_300ceaec, FUN_300e6704, iosDevAdd, iosDevReplaceExt
 *           ...
 * Константы: 0x300AA740
 * ---------------------------------------------------------------- */
void dllAdd(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_1[1];
  if (piVar1 == (int *)0x0) {
    iVar2 = *param_1;
    *param_1 = (int)param_2;
  }
  else {
    iVar2 = *piVar1;
    *piVar1 = (int)param_2;
  }
  if (iVar2 == 0) {
    param_1[1] = (int)param_2;
  }
  else {
    *(int **)(iVar2 + 4) = param_2;
  }
  *param_2 = iVar2;
  param_2[1] = (int)piVar1;
  return;
}

/* ----------------------------------------------------------------
 * dllRemove @ 0x300AA780  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 19 | Вызывает: 0
 * Вызывают: FUN_300cc7c8, FUN_300cc974, FUN_300ccfe8, FUN_300cd2a8, FUN_300cdb24, FUN_300ce044, FUN_300ceaec, FUN_300e675c, FUN_3011fb94, iosDevDelete
 *           ...
 * Константы: 0x300AA780
 * ---------------------------------------------------------------- */
void dllRemove(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_2;
  piVar2 = (int *)param_2[1];
  if (piVar2 == (int *)0x0) {
    *param_1 = iVar1;
  }
  else {
    *piVar2 = iVar1;
  }
  if (iVar1 == 0) {
    param_1[1] = (int)piVar2;
  }
  else {
    *(int **)(iVar1 + 4) = piVar2;
  }
  return;
}

/* ----------------------------------------------------------------
 * dllGet @ 0x300AA7A0  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 0
 * Вызывают: FUN_300fc65c, FUN_300fc69c, qFifoGet, qPriDeltaGet, qPriListGet, qPriListGetExpired
 * Константы: 0x300AA7A0
 * ---------------------------------------------------------------- */
int dllGet(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    *param_1 = *piVar1;
    if (*piVar1 == 0) {
      param_1[1] = 0;
    }
    else {
      *(undefined4 *)(*piVar1 + 4) = 0;
    }
    return (int)piVar1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ffsMsb @ 0x300AA7E0  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 10 | Вызывает: 0
 * Вызывают: FUN_300d266c, FUN_300f544c, coprocCtxReplicate, coprocTaskRegsGet, coprocTaskRegsSet, excInit, hashFuncMultiply, sigFfsMsb, taskCpuAffinitySet, workQInit
 * Константы: 0x300AA7E0
 * ---------------------------------------------------------------- */
int ffsMsb(int param_1)

{
  if (param_1 != 0) {
    if (param_1 != 0) {
      param_1 = 0x20 - LZCOUNT(param_1);
    }
    return param_1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ffsLsb @ 0x300AA7F4  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: qPriBMapNext, qPriBMapRemove, taskCpuAffinitySet
 * Константы: 0x300AA7F4
 * ---------------------------------------------------------------- */
uint ffsLsb(uint param_1)

{
  param_1 = -param_1 & param_1;
  if (param_1 != 0) {
    param_1 = 0x20 - LZCOUNT(param_1);
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * mathSoftInit @ 0x300AF05C  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrRoot
 * Константы: 0x300AF05C
 * ---------------------------------------------------------------- */
void mathSoftInit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * _d_fnlt @ 0x300AF060  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: _d_flt
 * Вызывают: FUN_300c4638, FUN_300c4f48, exp, expm1
 * Константы: 0x300AF060
 * ---------------------------------------------------------------- */
bool _d_fnlt(void)

{
  int iVar1;
  
  iVar1 = _d_flt();
  return iVar1 == 0;
}

/* ----------------------------------------------------------------
 * _d_fngt @ 0x300AF080  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 9 | Вызывает: 1
 * Вызывает: _d_fgt
 * Вызывают: FUN_300c4448, asin, atan, ceil, exp, expm1, floor, pow, sinh
 * Константы: 0x300AF080
 * ---------------------------------------------------------------- */
bool _d_fngt(void)

{
  int iVar1;
  
  iVar1 = _d_fgt();
  return iVar1 == 0;
}

/* ----------------------------------------------------------------
 * _d_fnle @ 0x300AF0A0  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: _d_fle
 * Константы: 0x300AF0A0
 * ---------------------------------------------------------------- */
bool _d_fnle(void)

{
  int iVar1;
  
  iVar1 = _d_fle();
  return iVar1 == 0;
}

/* ----------------------------------------------------------------
 * _d_fnge @ 0x300AF0C0  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: _d_fge
 * Вызывают: __kernel_rem_pio2, pow
 * Константы: 0x300AF0C0
 * ---------------------------------------------------------------- */
bool _d_fnge(void)

{
  int iVar1;
  
  iVar1 = _d_fge();
  return iVar1 == 0;
}

/* ----------------------------------------------------------------
 * _f_fnlt @ 0x300AF0E0  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: _f_flt
 * Константы: 0x300AF0E0
 * ---------------------------------------------------------------- */
bool _f_fnlt(void)

{
  int iVar1;
  
  iVar1 = _f_flt();
  return iVar1 == 0;
}

/* ----------------------------------------------------------------
 * _f_fngt @ 0x300AF0F8  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: _f_fgt
 * Константы: 0x300AF0F8
 * ---------------------------------------------------------------- */
bool _f_fngt(void)

{
  int iVar1;
  
  iVar1 = _f_fgt();
  return iVar1 == 0;
}

/* ----------------------------------------------------------------
 * _f_fnle @ 0x300AF110  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: _f_fle
 * Константы: 0x300AF110
 * ---------------------------------------------------------------- */
bool _f_fnle(void)

{
  int iVar1;
  
  iVar1 = _f_fle();
  return iVar1 == 0;
}

/* ----------------------------------------------------------------
 * _f_fnge @ 0x300AF128  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: _f_fge
 * Константы: 0x300AF128
 * ---------------------------------------------------------------- */
bool _f_fnge(void)

{
  int iVar1;
  
  iVar1 = _f_fge();
  return iVar1 == 0;
}

/* ----------------------------------------------------------------
 * _fp_trap @ 0x300AF148  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 0
 * Вызывают: __divsf3, __extendsfdf2, __fpl_exception, __fpl_fcheck_NaN2, __funder, __truncdfsf2, _fp_trapveneer
 * Константы: 0x300AF148
 * ---------------------------------------------------------------- */
void _fp_trap(void)

{
  return;
}

/* ----------------------------------------------------------------
 * frexp @ 0x300B2340  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __muldf3
 * Константы: 0x7FFFFFFF, 0x300B2340, 0x00100000
 * Данные: DAT_300b2408, DAT_300b2410
 * ---------------------------------------------------------------- */
double frexp(double __x,int *__exponent)

{
  uint in_r1;
  uint uVar1;
  uint extraout_r1;
  int *in_r2;
  double in_d0;
  
  uVar1 = in_r1 & 0x7fffffff;
  *in_r2 = 0;
  if (((int)uVar1 < DAT_300b2408) && (uVar1 != 0 || __exponent != (int *)0x0)) {
    if (uVar1 < 0x100000) {
      in_d0 = (double)__muldf3(__exponent);
      uVar1 = extraout_r1 & 0x7fffffff;
      *in_r2 = -0x36;
    }
    *in_r2 = (*in_r2 + ((int)uVar1 >> 0x14)) - DAT_300b2410;
  }
  return in_d0;
}

/* ----------------------------------------------------------------
 * scalbn @ 0x300B2FBC  (примерный размер ~460 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: __adddf3, __muldf3, copysign
 * Вызывают: __kernel_rem_pio2, ldexp, pow
 * Константы: 0x300B2FBC, 0x7FFFFFFF
 * Данные: DAT_300b319c, DAT_300b31a0, DAT_300b31a4, DAT_300b31b0, DAT_300b31c0
 * ---------------------------------------------------------------- */
double scalbn(double __x,int __n)

{
  uint in_r1;
  int in_r2;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  double in_d0;
  double extraout_d0;
  double dVar4;
  undefined8 uVar5;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  
  uVar5 = CONCAT44(in_r1,__n);
  uVar1 = DAT_300b319c & (int)in_r1 >> 0x14;
  if (uVar1 == 0) {
    if (__n == 0 && (in_r1 & 0x7fffffff) == 0) {
      return in_d0;
    }
    uVar5 = __muldf3(__n,in_r1,0,DAT_300b31a0);
    uVar1 = (DAT_300b319c & (uint)((longlong)uVar5 >> 0x34)) - 0x36;
    in_d0 = extraout_d0;
    if (in_r2 < DAT_300b31a4) goto LAB_300b3174;
  }
  uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
  if (uVar1 == DAT_300b319c) {
    dVar4 = (double)__adddf3((int)uVar5,uVar3,(int)uVar5,uVar3);
    return dVar4;
  }
  iVar2 = uVar1 + in_r2;
  if (DAT_300b31b0 < iVar2) {
    copysign(in_stack_ffffffa8,in_stack_ffffffb0);
  }
  else {
    if (0 < iVar2) {
      return in_d0;
    }
    if (iVar2 == -0x36 || iVar2 + 0x36 < 0 != SCARRY4(iVar2,0x36)) {
      if (DAT_300b31c0 < in_r2) {
        copysign(in_stack_ffffffa8,in_stack_ffffffb0);
      }
      else {
        copysign(in_stack_ffffffa8,in_stack_ffffffb0);
      }
    }
  }
LAB_300b3174:
  dVar4 = (double)__muldf3();
  return dVar4;
}

/* ----------------------------------------------------------------
 * ldexp @ 0x300B3188  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: scalbn
 * Вызывают: strtod
 * Константы: 0x300B3188
 * ---------------------------------------------------------------- */
double ldexp(double __x,int __exponent)

{
  double dVar1;
  double in_stack_ffffffec;
  
  dVar1 = scalbn(in_stack_ffffffec,__exponent);
  return dVar1;
}

/* ----------------------------------------------------------------
 * copysign @ 0x300B4D1C  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: fmod, scalbn
 * Константы: 0x300B4D1C
 * ---------------------------------------------------------------- */
double copysign(double __x,double __y)

{
  double in_d0;
  
  return in_d0;
}

/* ----------------------------------------------------------------
 * _dabs @ 0x300B70C8  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300B70C8
 * ---------------------------------------------------------------- */
void _dabs(void)

{
  return;
}

/* ----------------------------------------------------------------
 * _fabs @ 0x300B70D0  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300B70D0, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
uint _fabs(uint param_1)

{
  return param_1 & 0x7fffffff;
}

/* ----------------------------------------------------------------
 * _d_feq @ 0x300B72DC  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 1
 * Вызывает: _dcmpeq
 * Вызывают: FUN_300c4448, FUN_300c4638, FUN_300c505c, FUN_3010a3ec, FUN_3010a8cc, __ieee754_rem_pio2
 * Константы: 0x300B72DC
 * ---------------------------------------------------------------- */
undefined1 _d_feq(void)

{
  undefined1 in_ZR;
  
  _dcmpeq();
  return in_ZR;
}

/* ----------------------------------------------------------------
 * _d_fne @ 0x300B72F0  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: _dcmpeq
 * Вызывают: FUN_300c4638, FUN_301092d0, __ieee754_rem_pio2, __kernel_rem_pio2, log
 * Константы: 0x300B72F0
 * ---------------------------------------------------------------- */
bool _d_fne(void)

{
  undefined1 in_ZR;
  
  _dcmpeq();
  return !(bool)in_ZR;
}

/* ----------------------------------------------------------------
 * _d_fgt @ 0x300B7304  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: _dcmpge
 * Вызывают: _d_fngt
 * Константы: 0x300B7304
 * ---------------------------------------------------------------- */
bool _d_fgt(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  _dcmpge();
  return (bool)in_CY && !(bool)in_ZR;
}

/* ----------------------------------------------------------------
 * _d_fge @ 0x300B7318  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: _dcmpge
 * Вызывают: _d_fnge
 * Константы: 0x300B7318
 * ---------------------------------------------------------------- */
undefined1 _d_fge(void)

{
  undefined1 in_CY;
  
  _dcmpge();
  return in_CY;
}

/* ----------------------------------------------------------------
 * _d_fle @ 0x300B732C  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: _dcmple
 * Вызывают: _d_fnle
 * Константы: 0x300B732C
 * ---------------------------------------------------------------- */
bool _d_fle(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  _dcmple();
  return !(bool)in_CY || (bool)in_ZR;
}

/* ----------------------------------------------------------------
 * _d_flt @ 0x300B7340  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: _dcmple
 * Вызывают: _d_fnlt
 * Константы: 0x300B7340
 * ---------------------------------------------------------------- */
bool _d_flt(void)

{
  undefined1 in_CY;
  
  _dcmple();
  return !(bool)in_CY;
}

/* ----------------------------------------------------------------
 * _drdiv @ 0x300B73C8  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: __fpl_exception, __fpl_return_NaN, __rt_fp_status_addr, _fp_trapveneer, ddiv_mantissas
 * Константы: 0x7FFFFFFF, 0x80000000, 0x00100000, 0x00130000, 0x00140000, 0xFFFFFFFE, 0xC0000000, 0x04000000
 * Данные: DAT_300b7960
 * ---------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _drdiv(uint param_1,uint param_2,uint param_3,uint param_4)

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
  
  if ((ram0x300b795c & ~(param_4 >> 4)) == 0 || (ram0x300b795c & ~(param_2 >> 4)) == 0) {
    uVar5 = param_4 * 2;
    uVar6 = ram0x300b795c * 0x20;
    bVar12 = uVar5 == uVar6;
    bVar11 = bVar12 && param_3 == 0;
    bVar13 = bVar12 || uVar6 <= uVar5;
    if (!bVar12 && uVar6 > uVar5 || bVar12 && param_3 == 0) {
      bVar13 = ram0x300b795c * 0x20 <= param_2 * 2;
      bVar11 = param_2 * 2 == ram0x300b795c * 0x20;
    }
    if (bVar11) {
      bVar11 = param_1 == 0;
      bVar13 = true;
    }
    if (bVar13 && !bVar11) {
      uVar6 = param_4 * 2 + 0x100000 + (uint)(param_3 != 0);
      uVar5 = uVar6;
      if (uVar6 < 0xfff00001) {
        uVar5 = param_2 * 2 + 0x100000 + (uint)(param_1 != 0);
      }
      if (0xfff00000 < uVar5) {
        uVar5 = __fpl_exception();
        return uVar5;
      }
      if (0xfffff < uVar6) {
        param_3 = param_1;
        param_4 = param_2;
      }
      uVar5 = __fpl_return_NaN(param_3,param_4);
      return uVar5;
    }
    if ((ram0x300b795c & ~(param_4 >> 4)) != 0) {
      return 0;
    }
    if ((ram0x300b795c & ~(param_2 >> 4)) != 0) {
      return param_3;
    }
LAB_300b7678:
    uVar5 = __fpl_exception();
    return uVar5;
  }
  uVar5 = ram0x300b795c & param_4 >> 4;
  uVar6 = uVar5 | (param_4 ^ param_2) >> 0x1f;
  uVar10 = ram0x300b795c & param_2 >> 4;
  if (uVar10 == 0 || (param_4 & ram0x300b795c << 4) == 0) {
    if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) {
      if (param_1 != 0 || (param_2 & 0x7fffffff) != 0) {
        return param_3;
      }
      goto LAB_300b7678;
    }
    if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) {
      uVar5 = __fpl_exception();
      return uVar5;
    }
    if (uVar10 == 0) {
      iVar9 = 0x10000;
      param_2 = param_2 & 0x7fffffff;
      if (param_2 == 0 && param_1 >> 0xc == 0) {
        param_1 = param_1 << 0x14;
        iVar9 = -0x130000;
      }
      uVar4 = param_1;
      if (param_2 == 0) {
        param_2 = param_1 >> 0xc;
        uVar4 = param_1 << 0x14;
        iVar9 = iVar9 + -0x140000;
      }
      uVar1 = 0;
      if (param_2 >> 5 == 0) {
        param_2 = param_2 << 0x10;
        uVar1 = 0x10;
      }
      if (param_2 >> 0xd == 0) {
        param_2 = param_2 << 8;
        uVar1 = uVar1 + 8;
      }
      if (param_2 >> 0x11 == 0) {
        param_2 = param_2 << 4;
        uVar1 = uVar1 + 4;
      }
      if (param_2 >> 0x13 == 0) {
        param_2 = param_2 << 2;
        uVar1 = uVar1 + 2;
      }
      if (param_2 >> 0x14 == 0) {
        param_2 = 0;
        uVar1 = uVar1 + 1;
      }
      uVar10 = iVar9 + uVar1 * -0x10000;
      param_1 = uVar4 << (uVar1 & 0xff);
      param_2 = param_2 | uVar4 >> (0x20 - uVar1 & 0xff);
    }
    if ((uVar5 & 0xfffffffe) == 0) {
      iVar9 = uVar6 + 0x10000;
      param_4 = param_4 & 0x7fffffff;
      if (param_4 == 0 && param_3 >> 0xc == 0) {
        param_3 = param_3 << 0x14;
        iVar9 = uVar6 - 0x130000;
      }
      uVar5 = param_3;
      if (param_4 == 0) {
        param_4 = param_3 >> 0xc;
        uVar5 = param_3 << 0x14;
        iVar9 = iVar9 + -0x140000;
      }
      uVar4 = 0;
      if (param_4 >> 5 == 0) {
        param_4 = param_4 << 0x10;
        uVar4 = 0x10;
      }
      if (param_4 >> 0xd == 0) {
        param_4 = param_4 << 8;
        uVar4 = uVar4 + 8;
      }
      if (param_4 >> 0x11 == 0) {
        param_4 = param_4 << 4;
        uVar4 = uVar4 + 4;
      }
      if (param_4 >> 0x13 == 0) {
        param_4 = param_4 << 2;
        uVar4 = uVar4 + 2;
      }
      if (param_4 >> 0x14 == 0) {
        param_4 = param_4 << 1;
        uVar4 = uVar4 + 1;
      }
      uVar6 = iVar9 + uVar4 * -0x10000;
      param_3 = uVar5 << (uVar4 & 0xff);
      param_4 = param_4 | uVar5 >> (0x20 - uVar4 & 0xff);
    }
  }
  iVar7 = uVar6 - uVar10;
  iVar8 = iVar7 + 0x3fc0000;
  uVar10 = param_2 << 0xb | param_1 >> 0x15;
  iVar9 = param_1 << 0xb;
  uVar14 = ddiv_mantissas(param_3 << 0xb,param_4 << 0xb | param_3 >> 0x15 | 0x80000000);
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
 * ddiv_mantissas @ 0x300B7684  (примерный размер ~744 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: __divdf3, _drdiv
 * Константы: 0x04000000, 0x20000000, 0x80000000, 0x00400000, 0x300B7684, 0x300B785C, 0x00800000, 0x40000000
 * ---------------------------------------------------------------- */
undefined8 ddiv_mantissas(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  
  uVar7 = param_4 >> 0x10;
  uVar6 = param_3 >> 0x10;
  uVar8 = param_4 & ~(uVar7 << 0x10);
  param_3 = param_3 & ~(uVar6 << 0x10);
  uVar9 = (uint)*(byte *)((param_4 >> 0x18) + 0x300b785c);
  iVar10 = ((0x800000 - (uVar7 * uVar9 + uVar9)) * uVar9 >> 0x13) + 2;
  uVar11 = 0x20000000 - ((param_4 >> 0xd) * iVar10 + iVar10);
  uVar9 = uVar11 >> 0x10;
  uVar9 = uVar9 * iVar10 + ((uVar11 & ~(uVar9 << 0x10)) * iVar10 >> 0x10) >> 6;
  uVar11 = (uint)((byte)param_2 & 1) << 0x1f | param_1 >> 1;
  if ((bool)((byte)param_1 & 1)) {
    uVar12 = 0x80000000;
  }
  else {
    uVar12 = 0;
  }
  uVar1 = uVar9 * (param_2 >> 0x10) >> 0x10;
  uVar3 = uVar11 - uVar1 * uVar6;
  uVar13 = uVar1 * param_3;
  bVar19 = uVar13 * 0x10000 <= uVar12;
  uVar12 = uVar12 + uVar13 * -0x10000;
  uVar13 = uVar13 >> 0x10;
  bVar2 = uVar3 - uVar13 < (uint)bVar19;
  bVar20 = uVar13 < uVar3 || bVar2;
  uVar4 = uVar3 - (uVar13 + !bVar19);
  uVar14 = uVar1 * uVar8;
  if (uVar13 < uVar3 || bVar2) {
    bVar20 = uVar14 * 0x10000 <= uVar4;
  }
  uVar4 = uVar4 + uVar14 * -0x10000;
  uVar14 = ((param_2 >> 1) - (uVar7 * uVar1 + (uint)(uVar11 < uVar1 * uVar6))) -
           ((uVar14 >> 0x10) + (uint)!bVar20);
  uVar11 = uVar9 * (uVar14 >> 2) >> 0x10;
  uVar13 = uVar11 * uVar6;
  bVar19 = uVar13 * 0x80000 <= uVar12;
  uVar12 = uVar12 + uVar13 * -0x80000;
  uVar13 = uVar13 >> 0xd;
  bVar2 = uVar4 - uVar13 < (uint)bVar19;
  bVar20 = uVar13 < uVar4 || bVar2;
  uVar3 = uVar4 - (uVar13 + !bVar19);
  uVar15 = uVar7 * uVar11;
  if (uVar13 < uVar4 || bVar2) {
    bVar20 = uVar15 * 0x80000 <= uVar3;
  }
  uVar3 = uVar3 + uVar15 * -0x80000;
  uVar13 = uVar11 * param_3;
  bVar21 = uVar13 * 8 <= uVar12;
  uVar4 = uVar13 >> 0x1d;
  bVar2 = uVar3 - uVar4 < (uint)bVar21;
  bVar19 = uVar4 < uVar3 || bVar2;
  uVar5 = uVar3 - (uVar4 + !bVar21);
  uVar16 = uVar11 * uVar8;
  if (uVar4 < uVar3 || bVar2) {
    bVar19 = uVar16 * 8 <= uVar5;
  }
  uVar5 = uVar5 + uVar16 * -8;
  uVar16 = ((uVar14 - ((uVar15 >> 0xd) + (uint)!bVar20)) - ((uVar16 >> 0x1d) + (uint)!bVar19)) *
           0x4000000 | uVar5 >> 6;
  uVar4 = uVar5 * 0x4000000 | uVar12 + uVar13 * -8 >> 6;
  uVar13 = uVar13 * -0x20000000;
  uVar5 = uVar9 * (uVar16 >> 0xf);
  uVar12 = uVar5 >> 0x10;
  uVar14 = uVar4 - uVar12 * uVar6;
  uVar3 = uVar12 * param_3;
  bVar19 = uVar3 * 0x10000 <= uVar13;
  uVar13 = uVar13 + uVar3 * -0x10000;
  uVar3 = uVar3 >> 0x10;
  bVar2 = uVar14 - uVar3 < (uint)bVar19;
  bVar20 = uVar3 < uVar14 || bVar2;
  uVar15 = uVar14 - (uVar3 + !bVar19);
  uVar17 = uVar12 * uVar8;
  if (uVar3 < uVar14 || bVar2) {
    bVar20 = uVar17 * 0x10000 <= uVar15;
  }
  uVar15 = uVar15 + uVar17 * -0x10000;
  uVar14 = (uVar16 - (uVar7 * uVar12 + (uint)(uVar4 < uVar12 * uVar6))) -
           ((uVar17 >> 0x10) + (uint)!bVar20);
  uVar9 = uVar9 * (uVar14 >> 2) >> 0x10;
  uVar3 = uVar9 * uVar6;
  bVar19 = uVar3 * 0x80000 <= uVar13;
  uVar13 = uVar13 + uVar3 * -0x80000;
  uVar3 = uVar3 >> 0xd;
  bVar2 = uVar15 - uVar3 < (uint)bVar19;
  bVar20 = uVar3 < uVar15 || bVar2;
  uVar4 = uVar15 - (uVar3 + !bVar19);
  uVar16 = uVar7 * uVar9;
  if (uVar3 < uVar15 || bVar2) {
    bVar20 = uVar16 * 0x80000 <= uVar4;
  }
  uVar4 = uVar4 + uVar16 * -0x80000;
  uVar15 = uVar9 * param_3;
  bVar21 = uVar15 * 8 <= uVar13;
  uVar3 = uVar15 >> 0x1d;
  bVar2 = uVar4 - uVar3 < (uint)bVar21;
  bVar19 = uVar3 < uVar4 || bVar2;
  uVar17 = uVar4 - (uVar3 + !bVar21);
  uVar18 = uVar9 * uVar8;
  if (uVar3 < uVar4 || bVar2) {
    bVar19 = uVar18 * 8 <= uVar17;
  }
  uVar17 = uVar17 + uVar18 * -8;
  uVar3 = uVar17 * 0x4000000 | uVar13 + uVar15 * -8 >> 6;
  uVar13 = uVar15 * -0x20000000;
  uVar4 = uVar12 * 0x400000 + uVar9 * 0x200;
  uVar8 = uVar8 | uVar7 << 0x10;
  param_3 = param_3 | uVar6 << 0x10;
  uVar7 = uVar15 * -0x40000000;
  uVar6 = uVar3 * 2 + (uint)CARRY4(uVar13,uVar13);
  uVar3 = (((uVar14 - ((uVar16 >> 0xd) + (uint)!bVar20)) - ((uVar18 >> 0x1d) + (uint)!bVar19)) *
           0x4000000 | uVar17 >> 6) * 2 +
          (uint)(CARRY4(uVar3,uVar3) || CARRY4(uVar3 * 2,(uint)CARRY4(uVar13,uVar13)));
  bVar2 = uVar3 - uVar8 < (uint)(param_3 <= uVar6);
  uVar13 = uVar3;
  if (uVar8 < uVar3 || bVar2) {
    uVar13 = uVar3 - (uVar8 + (param_3 > uVar6));
    uVar6 = uVar6 - param_3;
  }
  uVar15 = uVar15 * -0x80000000;
  bVar19 = CARRY4(uVar6,uVar6) || CARRY4(uVar6 * 2,(uint)CARRY4(uVar7,uVar7));
  uVar7 = uVar6 * 2 + (uint)CARRY4(uVar7,uVar7);
  bVar20 = CARRY4(uVar13 * 2,(uint)bVar19);
  bVar21 = CARRY4(uVar13,uVar13) || bVar20;
  uVar6 = uVar13 * 2 + (uint)bVar19;
  bVar19 = bVar21 < (uVar8 < uVar6 || uVar6 - uVar8 < (uint)(param_3 <= uVar7));
  if ((CARRY4(uVar13,uVar13) || bVar20) || bVar19) {
    uVar6 = uVar6 - (uVar8 + (param_3 > uVar7));
    uVar7 = uVar7 - param_3;
  }
  bVar22 = CARRY4(uVar7,uVar7) || CARRY4(uVar7 * 2,(uint)CARRY4(uVar15,uVar15));
  uVar7 = uVar7 * 2 + (uint)CARRY4(uVar15,uVar15);
  bVar20 = CARRY4(uVar6 * 2,(uint)bVar22);
  bVar23 = CARRY4(uVar6,uVar6) || bVar20;
  uVar13 = uVar6 * 2 + (uint)bVar22;
  bVar22 = bVar23 < (uVar8 < uVar13 || uVar13 - uVar8 < (uint)(param_3 <= uVar7));
  if ((CARRY4(uVar6,uVar6) || bVar20) || bVar22) {
    uVar13 = uVar13 - (uVar8 + (param_3 > uVar7));
    uVar7 = uVar7 - param_3;
  }
  uVar13 = uVar13 | uVar7;
  if (uVar13 != 0) {
    uVar13 = 1;
  }
  uVar7 = (((uint)(uVar8 < uVar3 || bVar2) * 2 + (uint)(bVar21 || bVar19)) * 2 +
          (uint)(bVar23 || bVar22)) * 0x200;
  iVar10 = uVar1 * 0x10000 + uVar11 * 8 + (uVar5 >> 0x1a) +
           (uint)CARRY4(uVar12 * 0x400000,uVar9 * 0x200) + (uint)CARRY4(uVar4,uVar7);
  uVar13 = uVar4 + uVar7 | uVar13;
  if (iVar10 < 0) {
    return CONCAT44(iVar10,uVar13);
  }
  return CONCAT44(iVar10 * 2 + (uint)CARRY4(uVar13,uVar13),uVar13 * 2);
}

/* ----------------------------------------------------------------
 * _dcmpeq @ 0x300B796C  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: __fpl_dcmp_InfNaN
 * Вызывают: __cmpdf2, _d_feq, _d_fne
 * Константы: 0x00100000, 0x7FFFFFFF, 0xFFE00000, 0x300B796C
 * ---------------------------------------------------------------- */
void _dcmpeq(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = param_2 | param_4;
  if ((int)uVar2 < 0) {
    if ((int)(uVar2 + 0x100000) < 0) {
      bVar1 = (param_2 & 0x7fffffff) == 0;
      bVar3 = param_1 == 0 && bVar1;
      if (param_1 == 0 && bVar1) {
        bVar3 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
      }
      if (!bVar3) {
        bVar3 = param_4 == param_2;
      }
      if (!bVar3) {
        return;
      }
      return;
    }
    if (param_2 << 1 < 0xffe00000 && param_4 << 1 < 0xffe00000) {
      return;
    }
  }
  else {
    if (-1 < (int)(uVar2 + 0x100000)) {
      if (param_2 != param_4) {
        return;
      }
      return;
    }
    if (-1 < (int)(param_2 + 0x100000) && -1 < (int)(param_4 + 0x100000)) {
      return;
    }
  }
  __fpl_dcmp_InfNaN();
  return;
}

/* ----------------------------------------------------------------
 * _dfix_r @ 0x300B7A80  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x300B7A80, 0x80000000, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
uint _dfix_r(uint param_1,uint param_2)

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
 * _ll_sfrom_d_r @ 0x300B7BC8  (примерный размер ~180 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x80000000, 0x300B7BC8, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
undefined8 _ll_sfrom_d_r(uint param_1,int param_2)

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
 * _dfixu_r @ 0x300B7D10  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x300B7D10, 0x80000000, 0x40100000, 0x40000000, 0x00100000
 * ---------------------------------------------------------------- */
uint _dfixu_r(uint param_1,uint param_2)

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
 * _ll_ufrom_d_r @ 0x300B7E40  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Константы: 0x300B7E40, 0x80000000, 0x40100000, 0x40000000, 0x00100000
 * ---------------------------------------------------------------- */
undefined8 _ll_ufrom_d_r(uint param_1,int param_2)

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
 * _dcmpge @ 0x300B7EDC  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: __fpl_dcmp_InfNaN
 * Вызывают: _d_fge, _d_fgt
 * Константы: 0x00100000, 0x7FFFFFFF, 0xFFE00000, 0x300B7EDC
 * ---------------------------------------------------------------- */
void _dcmpge(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = param_2 | param_4;
  if ((int)uVar2 < 0) {
    if ((int)(uVar2 + 0x100000) < 0) {
      bVar1 = (param_2 & 0x7fffffff) == 0;
      bVar3 = param_1 == 0 && bVar1;
      if (param_1 == 0 && bVar1) {
        bVar3 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
      }
      if (!bVar3) {
        bVar3 = param_4 == param_2;
      }
      if (!bVar3) {
        return;
      }
      return;
    }
    if (param_2 << 1 < 0xffe00000 && param_4 << 1 < 0xffe00000) {
      return;
    }
  }
  else {
    if (-1 < (int)(uVar2 + 0x100000)) {
      if (param_2 != param_4) {
        return;
      }
      return;
    }
    if (-1 < (int)(param_2 + 0x100000) && -1 < (int)(param_4 + 0x100000)) {
      return;
    }
  }
  __fpl_dcmp_InfNaN();
  return;
}

/* ----------------------------------------------------------------
 * _dcmple @ 0x300B7F5C  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: __fpl_dcmp_InfNaN
 * Вызывают: _d_fle, _d_flt
 * Константы: 0x00100000, 0x7FFFFFFF, 0xFFE00000, 0x300B7F5C
 * ---------------------------------------------------------------- */
void _dcmple(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = param_2 | param_4;
  if ((int)uVar2 < 0) {
    if ((int)(uVar2 + 0x100000) < 0) {
      bVar1 = (param_2 & 0x7fffffff) == 0;
      bVar3 = param_1 == 0 && bVar1;
      if (param_1 == 0 && bVar1) {
        bVar3 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
      }
      if (!bVar3) {
        bVar3 = param_4 == param_2;
      }
      if (!bVar3) {
        return;
      }
      return;
    }
    if (param_2 << 1 < 0xffe00000 && param_4 << 1 < 0xffe00000) {
      return;
    }
  }
  else {
    if (-1 < (int)(uVar2 + 0x100000)) {
      if (param_2 != param_4) {
        return;
      }
      return;
    }
    if (-1 < (int)(param_2 + 0x100000) && -1 < (int)(param_4 + 0x100000)) {
      return;
    }
  }
  __fpl_dcmp_InfNaN();
  return;
}

/* ----------------------------------------------------------------
 * _drem @ 0x300B7FDC  (примерный размер ~740 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: __dunder, __dunder_d, __fpl_exception, __fpl_return_NaN
 * Вызывают: fmod
 * Константы: 0x7FFFFFFF, 0x00100000, 0x00140000, 0x00130000, 0xFFF00001, 0x300B7FDC, 0x80000000, 0x001E0000
 * Данные: DAT_300b82b8
 * ---------------------------------------------------------------- */
double _drem(double __x,double __y)

{
  uint in_r0;
  uint in_r1;
  uint uVar1;
  uint in_r2;
  uint in_r3;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  double in_d0;
  double dVar11;
  
  if ((DAT_300b82b8 & ~(in_r1 >> 4)) != 0 && (DAT_300b82b8 & ~(in_r3 >> 4)) != 0) {
    uVar3 = DAT_300b82b8 & in_r1 >> 4;
    uVar5 = DAT_300b82b8 & in_r3 >> 4;
    bVar8 = uVar5 == 0;
    if (SCARRY4(in_r1,-0x80000000)) {
      uVar5 = uVar5 | 5;
    }
    if (bVar8 || (in_r1 & DAT_300b82b8 << 4) == 0) {
      if (in_r2 == 0 && (in_r3 & 0x7fffffff) == 0) goto LAB_300b82ac;
      if (in_r0 == 0 && (in_r1 & 0x7fffffff) == 0) {
        return in_d0;
      }
      if (uVar5 >> 0x10 == 0) {
        iVar4 = uVar5 + 0x10000;
        uVar1 = in_r3 & 0x7fffffff;
        if (uVar1 == 0 && in_r2 >> 0xc == 0) {
          in_r2 = in_r2 << 0x14;
          iVar4 = uVar5 - 0x130000;
        }
        uVar2 = in_r2;
        if (uVar1 == 0) {
          uVar1 = in_r2 >> 0xc;
          uVar2 = in_r2 << 0x14;
          iVar4 = iVar4 + -0x140000;
        }
        uVar7 = 0;
        if (uVar1 >> 5 == 0) {
          uVar1 = uVar1 << 0x10;
          uVar7 = 0x10;
        }
        if (uVar1 >> 0xd == 0) {
          uVar1 = uVar1 << 8;
          uVar7 = uVar7 + 8;
        }
        if (uVar1 >> 0x11 == 0) {
          uVar1 = uVar1 << 4;
          uVar7 = uVar7 + 4;
        }
        if (uVar1 >> 0x13 == 0) {
          uVar1 = uVar1 << 2;
          uVar7 = uVar7 + 2;
        }
        if (uVar1 >> 0x14 == 0) {
          uVar1 = uVar1 << 1;
          uVar7 = uVar7 + 1;
        }
        uVar5 = iVar4 + uVar7 * -0x10000;
        in_r2 = uVar2 << (uVar7 & 0xff);
        in_r3 = uVar1 | uVar2 >> (0x20 - uVar7 & 0xff);
      }
      if (uVar3 >> 0x10 == 0) {
        iVar4 = uVar3 + 0x10000;
        uVar1 = in_r1 & 0x7fffffff;
        if (uVar1 == 0 && in_r0 >> 0xc == 0) {
          in_r0 = in_r0 << 0x14;
          iVar4 = uVar3 - 0x130000;
        }
        uVar2 = in_r0;
        if (uVar1 == 0) {
          uVar1 = in_r0 >> 0xc;
          uVar2 = in_r0 << 0x14;
          iVar4 = iVar4 + -0x140000;
        }
        uVar7 = 0;
        if (uVar1 >> 5 == 0) {
          uVar1 = uVar1 << 0x10;
          uVar7 = 0x10;
        }
        if (uVar1 >> 0xd == 0) {
          uVar1 = uVar1 << 8;
          uVar7 = uVar7 + 8;
        }
        if (uVar1 >> 0x11 == 0) {
          uVar1 = uVar1 << 4;
          uVar7 = uVar7 + 4;
        }
        if (uVar1 >> 0x13 == 0) {
          uVar1 = uVar1 << 2;
          uVar7 = uVar7 + 2;
        }
        if (uVar1 >> 0x14 == 0) {
          uVar1 = uVar1 << 1;
          uVar7 = uVar7 + 1;
        }
        uVar3 = iVar4 + uVar7 * -0x10000;
        in_r0 = uVar2 << (uVar7 & 0xff);
        in_r1 = uVar1 | uVar2 >> (0x20 - uVar7 & 0xff);
      }
    }
    uVar1 = in_r1 & ~(DAT_300b82b8 << 5) | 0x100000;
    uVar2 = in_r3 & ~(DAT_300b82b8 << 5) | 0x100000;
    uVar5 = uVar5 - 0x10000;
    do {
      if ((int)uVar3 <= (int)uVar5) {
        if (in_r0 == 0 && (uVar1 & 0x7fffffff) == 0) {
          return in_d0;
        }
        if ((int)uVar3 >> 0x10 < (int)uVar5 >> 0x10) {
LAB_300b8118:
          if (0xffff < (int)uVar3) {
            return in_d0;
          }
          dVar11 = (double)__dunder();
          return dVar11;
        }
        bVar8 = uVar2 <= uVar1;
        if (uVar1 == uVar2) {
          bVar8 = in_r2 <= in_r0;
        }
        if ((uVar1 == uVar2 && in_r0 == in_r2) || (!bVar8)) goto LAB_300b8118;
        iVar4 = (int)in_r2 >> 0x1f;
        in_r2 = in_r2 << 1;
        uVar2 = uVar2 * 2 - iVar4;
      }
      bVar8 = in_r0 < in_r2;
      in_r0 = in_r0 - in_r2;
      uVar1 = uVar1 - (uVar2 + bVar8);
      if ((int)uVar1 < 0) {
        bVar8 = in_r0 != 0;
        in_r0 = -in_r0;
        uVar1 = -(uVar1 + bVar8);
        uVar5 = uVar5 ^ 1;
      }
      if ((uVar1 & 0x1e0000) == 0) {
        uVar1 = uVar1 & 0x7fffffff;
        if (uVar1 == 0 && in_r0 >> 0xc == 0) {
          in_r0 = in_r0 << 0x14;
          uVar3 = uVar3 - 0x140000;
        }
        uVar7 = in_r0;
        if (uVar1 == 0) {
          uVar1 = in_r0 >> 0xc;
          uVar7 = in_r0 << 0x14;
          uVar3 = uVar3 - 0x140000;
        }
        uVar6 = 0;
        if (uVar1 >> 5 == 0) {
          uVar1 = uVar1 << 0x10;
          uVar6 = 0x10;
        }
        if (uVar1 >> 0xd == 0) {
          uVar1 = uVar1 << 8;
          uVar6 = uVar6 + 8;
        }
        if (uVar1 >> 0x11 == 0) {
          uVar1 = uVar1 << 4;
          uVar6 = uVar6 + 4;
        }
        if (uVar1 >> 0x13 == 0) {
          uVar1 = uVar1 << 2;
          uVar6 = uVar6 + 2;
        }
        if (uVar1 >> 0x14 == 0) {
          uVar1 = uVar1 << 1;
          uVar6 = uVar6 + 1;
        }
        uVar3 = uVar3 + uVar6 * -0x10000;
        in_r0 = uVar7 << (uVar6 & 0xff);
        uVar1 = uVar1 | uVar7 >> (0x20 - uVar6 & 0xff);
      }
      else {
        for (; (uVar1 & 0x100000) == 0; uVar1 = uVar1 * 2 - iVar4) {
          iVar4 = (int)in_r0 >> 0x1f;
          in_r0 = in_r0 << 1;
          uVar3 = uVar3 - 0x10000;
        }
      }
    } while( true );
  }
  uVar3 = in_r1 * 2;
  uVar5 = DAT_300b82b8 * 0x20;
  bVar9 = uVar3 == uVar5;
  bVar8 = bVar9 && in_r0 == 0;
  bVar10 = bVar9 || uVar5 <= uVar3;
  if (!bVar9 && uVar5 > uVar3 || bVar9 && in_r0 == 0) {
    bVar10 = DAT_300b82b8 * 0x20 <= in_r3 * 2;
    bVar8 = in_r3 * 2 == DAT_300b82b8 * 0x20;
  }
  if (bVar8) {
    bVar8 = in_r2 == 0;
    bVar10 = true;
  }
  if (bVar10 && !bVar8) {
    uVar3 = in_r1 * 2 + 0x100000 + (uint)(in_r0 != 0);
    if (uVar3 < 0xfff00001) {
      uVar3 = in_r3 * 2 + 0x100000 + (uint)(in_r2 != 0);
    }
    if (uVar3 < 0xfff00001) {
      dVar11 = (double)__fpl_return_NaN();
      return dVar11;
    }
    dVar11 = (double)__fpl_exception();
    return dVar11;
  }
  if (uVar3 < DAT_300b82b8 << 5) {
    if (0x1fffff < uVar3) {
      return in_d0;
    }
    if (in_r0 == 0 && (in_r1 & 0x7fffffff) == 0) {
      return in_d0;
    }
    dVar11 = (double)__dunder_d();
    return dVar11;
  }
LAB_300b82ac:
  dVar11 = (double)__fpl_exception();
  return dVar11;
}

/* ----------------------------------------------------------------
 * _dsqrt @ 0x300B82C0  (примерный размер ~464 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: __fpl_exception
 * Вызывают: acos, asin, pow, sqrt
 * Константы: 0x7FF00000, 0x40000000, 0x7FFFFFFF, 0x80000000, 0x00100000, 0x300B82C0, 0xC0000000, 0x10000000
 * ---------------------------------------------------------------- */
undefined8 _dsqrt(uint param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  undefined8 uVar14;
  
  if ((param_2 & 0x7ff00000) == 0) {
    if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
      return CONCAT44(param_2,param_1);
    }
    if (-1 < (int)param_2) {
      iVar4 = 1;
      if (param_2 == 0 && param_1 >> 0xc == 0) {
        param_1 = param_1 << 0x14;
        iVar4 = -0x13;
      }
      uVar2 = param_1;
      if (param_2 == 0) {
        param_2 = param_1 >> 0xc;
        uVar2 = param_1 << 0x14;
        iVar4 = iVar4 + -0x14;
      }
      uVar11 = 0;
      if (param_2 >> 5 == 0) {
        param_2 = param_2 << 0x10;
        uVar11 = 0x10;
      }
      if (param_2 >> 0xd == 0) {
        param_2 = param_2 << 8;
        uVar11 = uVar11 + 8;
      }
      if (param_2 >> 0x11 == 0) {
        param_2 = param_2 << 4;
        uVar11 = uVar11 + 4;
      }
      if (param_2 >> 0x13 == 0) {
        param_2 = param_2 << 2;
        uVar11 = uVar11 + 2;
      }
      if (param_2 >> 0x14 == 0) {
        param_2 = param_2 << 1;
        uVar11 = uVar11 + 1;
      }
      uVar10 = iVar4 - uVar11;
      param_1 = uVar2 << (uVar11 & 0xff);
      param_2 = param_2 | uVar2 >> (0x20 - uVar11 & 0xff);
LAB_300b82f0:
      if ((bool)((byte)(uVar10 + 0xfd) & 1)) {
        iVar4 = (int)param_1 >> 0x1f;
        param_1 = param_1 << 1;
        param_2 = param_2 * 2 - iVar4;
      }
      uVar2 = param_1 << 10;
      uVar5 = 0x40000000;
      uVar6 = 0;
      uVar3 = (param_2 << 10 | param_1 >> 0x16) + 0xc0000000;
      uVar11 = 0x10000000;
      do {
        uVar7 = uVar3 - uVar5;
        uVar8 = uVar7;
        if (uVar5 <= uVar3) {
          uVar8 = uVar7 - uVar11;
        }
        if (uVar5 <= uVar3 && uVar11 <= uVar7) {
          uVar5 = uVar5 + uVar11 * 2;
          uVar3 = uVar8;
        }
        iVar4 = (int)uVar2 >> 0x1f;
        uVar2 = uVar2 * 2;
        uVar3 = uVar3 * 2 - iVar4;
        bVar13 = (bool)((byte)uVar11 & 1);
        uVar11 = uVar11 >> 1;
      } while (uVar11 != 0);
      uVar8 = uVar3 - (uVar5 + !bVar13);
      uVar11 = uVar2;
      if (uVar5 < uVar3 || uVar3 - uVar5 < (uint)bVar13) {
        if (uVar8 != 0 || uVar8 < (0x7fffffff < uVar2)) {
          uVar5 = uVar5 + 1;
          uVar11 = uVar2 + 0x80000000;
          uVar3 = uVar8 - (0x7fffffff >= uVar2);
        }
      }
      uVar2 = uVar11 << 1;
      uVar3 = uVar3 * 2 - ((int)uVar11 >> 0x1f);
      uVar11 = 0x40000000;
      do {
        uVar9 = uVar2 - uVar6;
        uVar7 = uVar3 - (uVar5 + (uVar6 > uVar2));
        uVar8 = uVar2;
        if (uVar5 < uVar3 || uVar3 - uVar5 < (uint)(uVar6 <= uVar2)) {
          if (uVar7 != 0 || uVar7 < (uVar11 <= uVar9)) {
            uVar6 = uVar6 + uVar11 * 2;
            uVar8 = uVar9 - uVar11;
            uVar3 = uVar7 - (uVar11 > uVar9);
          }
        }
        uVar2 = uVar8 << 1;
        uVar3 = uVar3 * 2 - ((int)uVar8 >> 0x1f);
        uVar11 = uVar11 >> 1;
      } while (uVar11 != 0x80);
      uVar3 = uVar3 | uVar2;
      if (uVar3 != 0) {
        uVar3 = 2;
      }
      uVar11 = uVar6 >> 10 | uVar5 << 0x16;
      iVar4 = (uVar5 >> 10) + ((uVar10 + 0xfd >> 1) + 0x180) * 0x100000;
      uVar2 = (uint)((byte)(uVar6 >> 9) & 1) << 0x1f | uVar3 >> 1;
      if (uVar2 != 0) {
        bVar1 = (byte)(uVar2 >> 0x1f);
        uVar2 = uVar11 + bVar1;
        if (uVar3 >> 1 == 0) {
          uVar2 = uVar2 & 0xfffffffe;
        }
        return CONCAT44(iVar4 + (uint)CARRY4(uVar11,(uint)bVar1),uVar2);
      }
      return CONCAT44(iVar4,uVar11);
    }
  }
  else if ((~param_2 & 0x7ff00000) == 0) {
    uVar2 = param_1 | param_2 << 0xc;
    bVar13 = (int)uVar2 < 0;
    bVar12 = uVar2 == 0;
    if (!bVar12) {
      bVar13 = -1 < (int)(param_2 << 0xc);
      bVar12 = param_2 << 0xc == -1;
    }
    if (bVar12) {
      bVar13 = (int)param_2 < 0;
    }
    if (!bVar13) {
      return CONCAT44(param_2,param_1);
    }
  }
  else if ((param_2 & 0x80000000) == 0) {
    uVar10 = param_2 >> 0x14;
    param_2 = param_2 & ~(uVar10 << 0x14) | 0x100000;
    goto LAB_300b82f0;
  }
  uVar14 = __fpl_exception();
  return uVar14;
}

/* ----------------------------------------------------------------
 * _f_feq @ 0x300B88BC  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: _fcmpeq
 * Константы: 0x300B88BC
 * ---------------------------------------------------------------- */
undefined1 _f_feq(void)

{
  undefined1 in_ZR;
  
  _fcmpeq();
  return in_ZR;
}

/* ----------------------------------------------------------------
 * _f_fne @ 0x300B88D0  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: _fcmpeq
 * Константы: 0x300B88D0
 * ---------------------------------------------------------------- */
bool _f_fne(void)

{
  undefined1 in_ZR;
  
  _fcmpeq();
  return !(bool)in_ZR;
}

/* ----------------------------------------------------------------
 * _f_fgt @ 0x300B88E4  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: _fcmpge
 * Вызывают: _f_fngt
 * Константы: 0x300B88E4
 * ---------------------------------------------------------------- */
bool _f_fgt(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  _fcmpge();
  return (bool)in_CY && !(bool)in_ZR;
}

/* ----------------------------------------------------------------
 * _f_fge @ 0x300B88F8  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: _fcmpge
 * Вызывают: _f_fnge
 * Константы: 0x300B88F8
 * ---------------------------------------------------------------- */
undefined1 _f_fge(void)

{
  undefined1 in_CY;
  
  _fcmpge();
  return in_CY;
}

/* ----------------------------------------------------------------
 * _f_fle @ 0x300B890C  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: _fcmple
 * Вызывают: _f_fnle
 * Константы: 0x300B890C
 * ---------------------------------------------------------------- */
bool _f_fle(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  _fcmple();
  return !(bool)in_CY || (bool)in_ZR;
}

/* ----------------------------------------------------------------
 * _f_flt @ 0x300B8920  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: _fcmple
 * Вызывают: _f_fnlt
 * Константы: 0x300B8920
 * ---------------------------------------------------------------- */
bool _f_flt(void)

{
  undefined1 in_CY;
  
  _fcmple();
  return !(bool)in_CY;
}

/* ----------------------------------------------------------------
 * _frdiv @ 0x300B898C  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __divsf3
 * Константы: 0x300B898C
 * ---------------------------------------------------------------- */
void _frdiv(undefined4 param_1,undefined4 param_2)

{
  __divsf3(param_2);
  return;
}

/* ----------------------------------------------------------------
 * _fcmpeq @ 0x300B8B6C  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: __fpl_fcheck_NaN2
 * Вызывают: __cmpsf2, _f_feq, _f_fne
 * Константы: 0xFF000001, 0x00800000, 0x300B8B6C
 * ---------------------------------------------------------------- */
void _fcmpeq(uint param_1,uint param_2)

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
  __fpl_fcheck_NaN2();
  return;
}

