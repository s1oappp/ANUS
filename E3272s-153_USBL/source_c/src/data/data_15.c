/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 15 (функций: 20, адреса 0x3012DA14..0x3012E060)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * xbdStrategyGeneric @ 0x3012DA14  (примерный размер ~364 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_3012d6a4, semGive, semTake
 * Константы: 0x3012DA14, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int xbdStrategyGeneric(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  int *piVar6;
  
  pcVar5 = *(code **)(*(int *)(param_1 + 0x2c) + 0x18);
  if ((pcVar5 == (code *)0x0) || (iVar1 = (*pcVar5)(param_1,param_2), iVar1 == 0)) {
    iVar1 = semTake(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 4),0xffffffff);
    if (iVar1 == 0) {
      piVar6 = *(int **)(param_1 + 0x2c);
      if ((*piVar6 < 1) || (2 < *piVar6)) {
        piVar4 = piVar6 + 7;
        iVar1 = param_2;
        if (*(int *)(param_2 + 0x2c) != 0) {
          iVar3 = piVar6[7];
          do {
            iVar1 = *(int *)(iVar1 + 0x2c);
            iVar2 = iVar3 + 1;
            iVar3 = iVar3 + 1;
          } while (*(int *)(iVar1 + 0x2c) != 0);
          *piVar4 = iVar2;
        }
        *piVar4 = *piVar4 + 1;
        piVar4 = (int *)piVar6[4];
        iVar3 = *piVar4;
        if (iVar3 == 0) {
          *(int *)piVar6[3] = param_2;
        }
        else {
          *(int *)(iVar3 + 0x2c) = param_2;
        }
        *piVar4 = iVar1;
      }
      else if (param_2 != 0) {
        do {
          iVar1 = *(int *)(param_2 + 0x2c);
          *(undefined4 *)(param_2 + 0x2c) = 0;
          piVar6 = *(int **)(param_1 + 0x2c);
          if (*piVar6 == 2) {
            (*(code *)piVar6[5])(param_1,param_2);
          }
          else {
            piVar6[7] = piVar6[7] + 1;
            FUN_3012d6a4(param_1,param_2);
          }
          param_2 = iVar1;
        } while (iVar1 != 0);
      }
      if (**(int **)(param_1 + 0x2c) != 2) {
        semGive((*(int **)(param_1 + 0x2c))[2]);
      }
      semGive(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 4));
      iVar1 = 0;
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * xbdGetNextBioGeneric @ 0x3012DB80  (примерный размер ~232 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Вызывают: xbdSrvTaskGeneric
 * Константы: 0x3012DB80, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int xbdGetNextBioGeneric(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x2c);
  piVar4 = *(int **)(iVar6 + 0xc);
  piVar3 = *(int **)(iVar6 + 0x10);
  iVar1 = semTake(*(undefined4 *)(iVar6 + 4),0xffffffff);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = *piVar4;
  piVar5 = *(int **)(param_1 + 0x2c);
  if (iVar1 == 0) goto LAB_3012dc58;
  if (*piVar5 == 1) {
    iVar2 = *(int *)(iVar1 + 8);
    piVar5[9] = *(int *)(iVar1 + 4);
    piVar5[10] = iVar2;
    iVar2 = *(int *)(iVar6 + 0x2c);
    if (iVar1 == iVar2) {
      iVar2 = 0;
LAB_3012dc28:
      *(int *)(iVar6 + 0x2c) = iVar2;
    }
    else if (iVar2 == 0) {
      piVar5[8] = (uint)(piVar5[8] == 0);
      *(undefined4 *)(iVar6 + 0x30) = 0;
      iVar2 = *piVar3;
      if (*piVar4 != iVar2) goto LAB_3012dc28;
    }
  }
  *piVar4 = *(int *)(iVar1 + 0x2c);
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  if (*piVar4 == 0) {
    *piVar3 = 0;
  }
  piVar5[7] = piVar5[7] + -1;
LAB_3012dc58:
  semGive(piVar5[1]);
  return iVar1;
}

/* ----------------------------------------------------------------
 * xbdSrvTaskGeneric @ 0x3012DC68  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: semTake, xbdGetNextBioGeneric
 * Константы: 0xFFFFFFFF, 0x3012DC68
 * Данные: DAT_3012df68
 * ---------------------------------------------------------------- */
void xbdSrvTaskGeneric(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x28) == DAT_3012df68) && (*(int *)(*(int *)(param_1 + 0x2c) + 0x14) != 0)
     ) {
    iVar1 = semTake(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 8),0xffffffff);
    while (iVar1 == 0) {
      while( true ) {
        iVar1 = xbdGetNextBioGeneric(param_1);
        if (iVar1 == 0) break;
        (**(code **)(*(int *)(param_1 + 0x2c) + 0x14))(param_1,iVar1);
      }
      iVar1 = semTake(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 8),0xffffffff);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * xbdGetBioSched @ 0x3012DCF0  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012DCF0, 0xFFFFFFFF
 * Данные: DAT_3012df68
 * ---------------------------------------------------------------- */
undefined4 xbdGetBioSched(int param_1,undefined4 *param_2)

{
  if (*(int *)(param_1 + 0x28) != DAT_3012df68) {
    return 0xffffffff;
  }
  *param_2 = **(undefined4 **)(param_1 + 0x2c);
  return 0;
}

/* ----------------------------------------------------------------
 * xbdSetBioSched @ 0x3012DD1C  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: semGive, semTake, taskDelay
 * Константы: 0xFFFFFFFF, 0x3012DD1C
 * Данные: DAT_3012df68
 * ---------------------------------------------------------------- */
undefined4 xbdSetBioSched(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x28) != DAT_3012df68) {
    return 0xffffffff;
  }
  if ((param_2 != 0) && (param_2 != 1)) {
    if (param_2 != 2) {
      return 0xffffffff;
    }
    if (*(int *)(*(int *)(param_1 + 0x2c) + 0x14) == 0) {
      return 0xffffffff;
    }
  }
  if (**(int **)(param_1 + 0x2c) != param_2) {
    while( true ) {
      iVar1 = semTake(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 4),0xffffffff);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      piVar2 = *(int **)(param_1 + 0x2c);
      if (piVar2[7] == 0) break;
      semGive(piVar2[2]);
      semGive(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 4));
      taskDelay(1);
    }
    *piVar2 = param_2;
    piVar2[8] = 1;
    piVar2[9] = 0;
    piVar2[10] = 0;
    piVar2[0xb] = 0;
    piVar2[0xc] = 0;
    semGive(piVar2[1]);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * xbdDump @ 0x3012DE08  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: devMapUnsafe, devUnmapUnsafe
 * Вызывают: FUN_300df174
 * Константы: 0x3012DE08
 * ---------------------------------------------------------------- */
undefined4
xbdDump(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
       undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  iVar1 = devMapUnsafe();
  if (iVar1 == 0) {
    uVar2 = 6;
  }
  else {
    pcVar3 = *(code **)(*(int *)(iVar1 + 0x18) + 8);
    if (pcVar3 == (code *)0x0) {
      uVar2 = 0x23;
    }
    else {
      uVar2 = (*pcVar3)(iVar1,param_2,param_3,param_4,param_5);
    }
    devUnmapUnsafe(iVar1);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * xbdSize @ 0x3012DE84  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: __mul64, devMap, devUnmap
 * Вызывают: FUN_300caa84
 * Константы: 0x3012DE84
 * ---------------------------------------------------------------- */
undefined4 xbdSize(undefined4 param_1,undefined8 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  iVar1 = devMap();
  if (iVar1 == 0) {
    uVar2 = 6;
  }
  else {
    if (param_2 != (undefined8 *)0x0) {
      uVar3 = __mul64(*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x24),
                      *(undefined4 *)(iVar1 + 0x1c),0);
      *param_2 = uVar3;
    }
    devUnmap(iVar1);
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * xbdNBlocks @ 0x3012DEDC  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 2
 * Вызывает: devMap, devUnmap
 * Вызывают: FUN_300d266c, dosFsDevCreate, rawFsDevInit, xbdPartitionDevCreate
 * Константы: 0x3012DEDC
 * ---------------------------------------------------------------- */
undefined4 xbdNBlocks(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = devMap();
  if (iVar1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      uVar2 = *(undefined4 *)(iVar1 + 0x24);
      *param_2 = *(undefined4 *)(iVar1 + 0x20);
      param_2[1] = uVar2;
    }
    devUnmap();
    return 0;
  }
  return 6;
}

/* ----------------------------------------------------------------
 * xbdBlockSize @ 0x3012DF18  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 2
 * Вызывает: devMap, devUnmap
 * Вызывают: FUN_300d266c, FUN_300d66b0, bio_alloc, dosFsDevCreate, dosFsDiskProbe, rawFsDevInit, xbdPartitionDevCreate
 * Константы: 0x3012DF18
 * ---------------------------------------------------------------- */
undefined4 xbdBlockSize(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = devMap();
  if (iVar1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(iVar1 + 0x1c);
    }
    devUnmap();
    return 0;
  }
  return 6;
}

/* ----------------------------------------------------------------
 * bioInit @ 0x3012DF6C  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012DF6C
 * ---------------------------------------------------------------- */
undefined4 bioInit(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * bio_done @ 0x3012DF74  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 0
 * Вызывают: FUN_300ddb94, FUN_300dddf8, FUN_300de180, FUN_300deda4, FUN_300df538, xbdBlkDevDelete, xbdStrategy
 * Константы: 0x3012DF74
 * ---------------------------------------------------------------- */
void bio_done(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    (**(code **)(param_1 + 0x24))();
  }
  return;
}

/* ----------------------------------------------------------------
 * bio_alloc @ 0x3012DF98  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 4
 * Вызывает: __errno, cacheDmaMalloc, errnoSet, xbdBlockSize
 * Вызывают: dosFsDevCreate, dosFsDiskProbe, rawFsDevInit, xbdPartitionDevCreate
 * Константы: 0x3012DF98
 * ---------------------------------------------------------------- */
undefined4 bio_alloc(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int local_c;
  
  iVar1 = xbdBlockSize(param_1,&local_c);
  if (iVar1 == 0) {
    uVar3 = cacheDmaMalloc(local_c * param_2);
  }
  else {
    puVar2 = (undefined4 *)__errno();
    errnoSet(*puVar2);
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * bio_free @ 0x3012DFDC  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 2
 * Вызывает: free, memPartFree
 * Вызывают: FUN_300ca3dc, FUN_300d6de0, FUN_300dec40, dosFsDevCreate, dosFsDiskProbe, rawFsDevInit, xbdPartitionDevCreate
 * Константы: 0x3012DFDC
 * Данные: DAT_300f0db4, DAT_300f0db8, DAT_300f0dbc
 * ---------------------------------------------------------------- */
undefined4 bio_free(void *param_1)

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
 * spinLockIsrInit @ 0x3012DFE0  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: erfLibInit, tyDevInit
 * Константы: 0x3012DFE0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void spinLockIsrInit(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = 0xffffffff;
  param_1[0x10] = param_2;
  return;
}

/* ----------------------------------------------------------------
 * spinLockIsrTake @ 0x3012DFF0  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_300c2898, FUN_300c2c20, FUN_300ef24c, FUN_300ef698, FUN_300efbec
 * Константы: 0x3012DFF0
 * ---------------------------------------------------------------- */
void spinLockIsrTake(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

/* ----------------------------------------------------------------
 * spinLockIsrGive @ 0x3012E014  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_300c2898, FUN_300c2c20, FUN_300ef24c, FUN_300ef698, FUN_300efbec
 * Константы: 0x3012E014, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void spinLockIsrGive(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  return;
}

/* ----------------------------------------------------------------
 * spinLockTaskInit @ 0x3012E038  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300cb558, vxdbgClntRegister
 * Константы: 0x3012E038
 * ---------------------------------------------------------------- */
void spinLockTaskInit(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x8c) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * spinLockTaskTake @ 0x3012E040  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 17 | Вызывает: 0
 * Вызывают: FUN_300c6b50, FUN_300cc2dc, FUN_300cc330, FUN_300cc3c4, FUN_300cc508, FUN_300ccc2c, FUN_300cd2a8, FUN_300cd79c, FUN_300cdb24, FUN_300ce044
 *           ...
 * Константы: 0x3012E040
 * Данные: _DAT_3012e068
 * ---------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void spinLockTaskTake(void)

{
  *(int *)(*_DAT_3012e068 + 0x7c) = *(int *)(*_DAT_3012e068 + 0x7c) + 1;
  return;
}

/* ----------------------------------------------------------------
 * spinLockTaskGive @ 0x3012E05C  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 17 | Вызывает: 3
 * Вызывает: FUN_3012a3cc, windExit, windPendQFlush
 * Вызывают: FUN_300c6b50, FUN_300cc2dc, FUN_300cc330, FUN_300cc3c4, FUN_300cc508, FUN_300ccc2c, FUN_300cd2a8, FUN_300cd79c, FUN_300cdb24, FUN_300ce044
 *           ...
 * Константы: 0x3012E05C
 * Данные: DAT_3012a410, DAT_3012a42c, DAT_3012a440
 * ---------------------------------------------------------------- */
undefined4 spinLockTaskGive(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *DAT_3012a440;
  if ((*(int *)(iVar2 + 0x7c) != 0) &&
     (iVar1 = *(int *)(iVar2 + 0x7c) + -1, *(int *)(iVar2 + 0x7c) = iVar1, iVar1 == 0)) {
    if (*DAT_3012a42c + -0x50 == iVar2) {
      if (*(int *)(iVar2 + 0xac) != 0) {
        return 0;
      }
      if (*(int *)(iVar2 + 0xb0) == 0) {
        return 0;
      }
      *DAT_3012a410 = 1;
      windPendQFlush(iVar2 + 0xb0);
    }
    else {
      *DAT_3012a410 = 1;
      iVar1 = FUN_3012a3cc(iVar2);
      if (iVar1 != 0) {
        windPendQFlush(iVar2 + 0xb0);
      }
    }
    windExit();
  }
  return 0;
}

/* ----------------------------------------------------------------
 * spinLockRestrict @ 0x3012E060  (примерный размер ~0 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012E060
 * ---------------------------------------------------------------- */
undefined4 spinLockRestrict(void)

{
  return 0;
}

