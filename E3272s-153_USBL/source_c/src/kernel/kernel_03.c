/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : kernel — ядро VxWorks 6.8: задачи, семафоры, очереди, прерывания, память, планировщик
 * Часть  : 3 (функций: 150, адреса 0x300AE13C..0x300E8404)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * FUN_300ae13c @ 0x300AE13C  (примерный размер ~436 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300ac958, mmuCortexA8TLBIDFlushEntry, mmuCortexA8WordSet, mmuCortexA8WordSetMultiple
 * Вызывают: FUN_300ae2f0
 * Константы: 0xFFFFFFFF, 0xFF000000, 0x300AE13C, 0x00F00000
 * Данные: DAT_300ae918, DAT_300aef60
 * ---------------------------------------------------------------- */
undefined4
FUN_300ae13c(int *param_1,uint param_2,uint param_3,uint param_4,uint param_5,undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint local_38 [4];
  
  puVar4 = (uint *)(*param_1 + (param_2 >> 0x14) * 4);
  iVar2 = 0;
  if (param_1[1] != 0) {
    iVar2 = param_1[1] + (param_2 >> 0x14) * 4;
  }
  uVar1 = *puVar4;
  if ((uVar1 & 3) == 0) {
    if (param_5 == DAT_300aef60) {
      uVar1 = param_3 & 0xff000000 | (param_4 & 0xf) << 0x14 | DAT_300aef60 | (param_4 & 0xf0) << 1;
      local_38[0] = uVar1;
      local_38[0] = FUN_300ac958(param_6);
      local_38[0] = local_38[0] | uVar1;
      mmuCortexA8WordSetMultiple(puVar4,local_38[0],0x10);
      if (iVar2 != 0) {
        mmuCortexA8WordSetMultiple(iVar2,local_38[0],0x10);
      }
    }
    else {
      uVar3 = param_3 & DAT_300ae918 | 2;
      local_38[0] = uVar3;
      local_38[0] = FUN_300ac958(param_6,uVar1,local_38,puVar4);
      local_38[0] = local_38[0] | uVar3;
      mmuCortexA8WordSet(puVar4);
      if (iVar2 != 0) {
        mmuCortexA8WordSet(iVar2,local_38[0]);
      }
    }
    mmuCortexA8TLBIDFlushEntry(param_2);
  }
  else if (param_5 == DAT_300aef60) {
    if ((uVar1 & 1) != 0) {
      return 0xffffffff;
    }
    if (((uVar1 & 0xf00000) >> 0x14 | (uVar1 & 0x1e0) >> 1) != param_4 ||
        (uVar1 & 0xff000000) != param_3) {
      return 0xffffffff;
    }
  }
  else {
    if ((uVar1 & 1) != 0) {
      return 0xffffffff;
    }
    if (param_4 != 0 || (uVar1 & DAT_300ae918) != param_3) {
      return 0xffffffff;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ae2f0 @ 0x300AE2F0  (примерный размер ~308 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300ae020, FUN_300ae0ac, FUN_300ae13c
 * Вызывают: FUN_300ae424
 * Константы: 0x300AE2F0
 * Данные: DAT_300aef60
 * ---------------------------------------------------------------- */
int FUN_300ae2f0(undefined4 param_1,int param_2,uint param_3,int param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  uint local_2c;
  uint local_28;
  
  iVar3 = 0;
  iVar1 = FUN_300ae0ac(param_2);
  if ((iVar1 == 2) || (iVar1 == DAT_300aef60)) {
    iVar2 = FUN_300ae020(param_5,iVar1,&local_28,&local_2c);
    if (iVar2 == -1) {
      iVar3 = -1;
    }
    else {
      uVar4 = 0;
      if (local_28 != 0) {
        do {
          iVar3 = FUN_300ae13c(param_1,param_2,param_3,param_4,iVar1,param_7);
          if (iVar3 != 0) {
            return iVar3;
          }
          uVar4 = uVar4 + 1;
          bVar5 = CARRY4(param_3,local_2c);
          param_3 = param_3 + local_2c;
          param_4 = param_4 + (uint)bVar5;
          param_2 = param_2 + local_2c;
          iVar3 = 0;
        } while (uVar4 < local_28);
      }
    }
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_300ae424 @ 0x300AE424  (примерный размер ~220 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300adf3c, FUN_300ae2f0, semMGive, semMTake
 * Константы: 0xFFFFFFFF, 0x300AE424, 0xFFFFEFFF
 * ---------------------------------------------------------------- */
undefined4
FUN_300ae424(int param_1,int param_2,uint param_3,int param_4,int param_5,undefined4 param_6,
            undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  iVar1 = semMTake(param_1 + 8,0xffffffff);
  if (iVar1 == 0) {
    iVar1 = FUN_300ae2f0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    if ((iVar1 == -1) && (param_5 != 0)) {
      do {
        iVar1 = FUN_300adf3c(param_1,param_2,param_3,param_4,param_7);
        if (iVar1 != 0) {
          semMGive(param_1 + 8);
          return 0xffffffff;
        }
        param_2 = param_2 + 0x1000;
        bVar3 = 0xffffefff < param_3;
        param_3 = param_3 + 0x1000;
        param_4 = param_4 + (uint)bVar3;
        param_5 = param_5 + -1;
      } while (param_5 != 0);
    }
    uVar2 = semMGive(param_1 + 8);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300ae500 @ 0x300AE500  (примерный размер ~152 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 5
 * Вызывает: FUN_300abfb0, cacheClear, cacheInvalidate, mmuCortexA8TLBIDFlushAll, mmuCortexA8WordSetMultiple
 * Вызывают: FUN_300ae598, FUN_300ae668, FUN_300ae7f0
 * Константы: 0x300AE500
 * Данные: DAT_300af02c
 * ---------------------------------------------------------------- */
undefined4 FUN_300ae500(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_1c;
  undefined1 auStack_18 [4];
  
  iVar2 = FUN_300abfb0(param_1,param_2,&local_1c,auStack_18);
  puVar1 = DAT_300af02c;
  if (iVar2 == 0) {
    uVar3 = (*(code *)*DAT_300af02c)();
    if ((uVar3 & 5) == 5) {
      cacheClear(1,param_2,param_3 << 0xc);
    }
    uVar3 = (*(code *)*puVar1)();
    if ((uVar3 & 0x1000) != 0) {
      cacheInvalidate(0,param_2,param_3 << 0xc);
    }
    mmuCortexA8WordSetMultiple(local_1c,0,param_3);
    mmuCortexA8TLBIDFlushAll();
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ae598 @ 0x300AE598  (примерный размер ~208 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300ae500, cacheClear, cacheInvalidate, mmuCortexA8TLBIDFlushEntry, mmuCortexA8WordSet
 * Вызывают: FUN_300ae668
 * Константы: 0x00100000, 0x300AE598
 * Данные: DAT_300af02c
 * ---------------------------------------------------------------- */
undefined4 FUN_300ae598(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  
  puVar2 = DAT_300af02c;
  uVar3 = (*(code *)*DAT_300af02c)();
  if ((uVar3 & 5) == 5) {
    cacheClear(1,param_2,0x100000);
  }
  uVar3 = (*(code *)*puVar2)();
  if ((uVar3 & 0x1000) != 0) {
    cacheInvalidate(0,param_2,0x100000);
  }
  iVar1 = (param_2 >> 0x14) * 4;
  mmuCortexA8WordSet(*param_1 + iVar1,0);
  iVar4 = param_1[1];
  if (iVar4 != 0) {
    puVar5 = (uint *)(iVar4 + iVar1);
    if ((*puVar5 & 3) == 2) {
      mmuCortexA8WordSet(puVar5,0);
    }
    else {
      FUN_300ae500(iVar4,param_2,0x100);
    }
  }
  mmuCortexA8TLBIDFlushEntry(param_2);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ae668 @ 0x300AE668  (примерный размер ~392 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300ac6ac, FUN_300ae500, FUN_300ae598
 * Вызывают: FUN_300ae7f0
 * Константы: 0xFFFFFFFF, 0x00100000, 0x00FFFFFF, 0x300AE668
 * Данные: DAT_300ae914, DAT_300ae918
 * ---------------------------------------------------------------- */
undefined4 FUN_300ae668(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = *param_1;
  puVar3 = (uint *)(iVar4 + (param_2 >> 0x14) * 4);
  uVar2 = *puVar3;
  if ((uVar2 & 3) != 2) {
    return 0xffffffff;
  }
  uVar5 = param_2 + param_3 * 0x1000;
  if ((uVar2 & 0x40000) == 0) {
    if ((param_2 & DAT_300ae914) != 0) goto LAB_300ae6dc;
    uVar6 = uVar5 & DAT_300ae914;
  }
  else {
    if ((param_2 & 0xffffff) != 0) goto LAB_300ae6dc;
    uVar6 = uVar5 & 0xffffff;
  }
  if (uVar6 == 0) {
    while( true ) {
      if (param_2 == uVar5) {
        return 0;
      }
      iVar4 = FUN_300ae598(param_1,param_2);
      if (iVar4 != 0) break;
      param_2 = param_2 + 0x100000;
    }
    return 0xffffffff;
  }
LAB_300ae6dc:
  iVar1 = FUN_300ac6ac(param_1,param_2,param_3,puVar3,uVar2);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (param_2 != uVar5) {
    do {
      while( true ) {
        puVar3 = (uint *)(iVar4 + (param_2 >> 0x14) * 4);
        uVar2 = *puVar3;
        if ((uVar2 & 3) != 2) break;
        iVar1 = FUN_300ae598(param_1,param_2);
        if (iVar1 != 0) {
          return 0xffffffff;
        }
        param_2 = param_2 + 0x100000;
        if (param_2 == uVar5) {
          return 0;
        }
      }
      uVar6 = (param_2 & DAT_300ae918) + 0x100000;
      if (((uVar5 < uVar6) && (uVar5 != 0)) || (uVar6 == 0)) {
        uVar6 = uVar5;
      }
      iVar1 = FUN_300ae500(iVar4,param_2,uVar6 - param_2 >> 0xc,puVar3,uVar2);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      param_2 = uVar6;
    } while (uVar6 != uVar5);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300ae7f0 @ 0x300AE7F0  (примерный размер ~320 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300ae500, FUN_300ae668, semMGive, semMTake
 * Константы: 0xFFFFFFFF, 0x300AE7F0, 0x00100000, 0xFF000000, 0x01000000
 * Данные: DAT_300ae918
 * ---------------------------------------------------------------- */
undefined4 FUN_300ae7f0(int *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar5 = param_2 + param_3 * 0x1000;
    iVar2 = semMTake(param_1 + 2,0xffffffff);
    if (iVar2 == 0) {
      if (param_2 != uVar5) {
        do {
          puVar4 = (uint *)(*param_1 + (param_2 >> 0x14) * 4);
          uVar3 = *puVar4;
          uVar6 = (param_2 & DAT_300ae918) + 0x100000;
          if ((uVar3 & 3) == 2) {
            if ((uVar3 & 0x40000) != 0) {
              uVar6 = (param_2 & 0xff000000) + 0x1000000;
            }
            if (((uVar5 < uVar6) && (uVar5 != 0)) || (uVar6 == 0)) {
              uVar6 = uVar5;
            }
            iVar2 = FUN_300ae668(param_1,param_2,uVar6 - param_2 >> 0xc);
            param_2 = uVar6;
            if (iVar2 == -1) {
LAB_300ae91c:
              semMGive(param_1 + 2);
              goto LAB_300ae924;
            }
          }
          else {
            if (((uVar5 < uVar6) && (uVar5 != 0)) || (uVar6 == 0)) {
              uVar6 = uVar5;
            }
            iVar2 = FUN_300ae500(*param_1,param_2,uVar6 - param_2 >> 0xc,puVar4,uVar3);
            param_2 = uVar6;
            if (iVar2 != 0) goto LAB_300ae91c;
          }
        } while (param_2 != uVar5);
      }
      uVar1 = semMGive(param_1 + 2);
    }
    else {
LAB_300ae924:
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300ae930 @ 0x300AE930  (примерный размер ~172 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: mmuCortexA8TLBIDFlushAll, mmuCortexA8WordSet, semMGive, semMTake, taskCpuUnlock
 * Константы: 0xFFFFFFFF, 0x300AE930
 * Данные: DAT_300af030
 * ---------------------------------------------------------------- */
undefined4 FUN_300ae930(int *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  
  bVar1 = false;
  iVar2 = semMTake(param_2 + 2,0xffffffff);
  if (iVar2 == 0) {
    *(int *)(*DAT_300af030 + 0x7c) = *(int *)(*DAT_300af030 + 0x7c) + 1;
    iVar2 = *param_1;
    iVar5 = 0;
    puVar4 = (uint *)(*param_2 + -4);
    do {
      puVar4 = puVar4 + 1;
      if (((*puVar4 & 3) == 1) || ((*puVar4 & 3) == 2)) {
        mmuCortexA8WordSet(iVar2 + iVar5 * 4);
        bVar1 = true;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x1000);
    if (bVar1) {
      mmuCortexA8TLBIDFlushAll();
    }
    taskCpuUnlock();
    uVar3 = semMGive(param_2 + 2);
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300ae9dc @ 0x300AE9DC  (примерный размер ~528 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_300ad708, cacheClear, cacheInvalidate, mmuCortexA8TLBIDFlushAll, mmuCortexA8WordSet, taskCpuUnlock
 * Константы: 0xFFFFFFFF, 0x300AE9DC, 0x00100000
 * Данные: DAT_300af02c, DAT_300af030
 * ---------------------------------------------------------------- */
undefined4 FUN_300ae9dc(int *param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int unaff_r11;
  int iVar7;
  undefined4 *puVar8;
  bool bVar9;
  
  bVar9 = (param_4 & 1) != 0;
  if (bVar9) {
    unaff_r11 = 0;
  }
  if (!bVar9) {
    unaff_r11 = 1;
  }
  *(int *)(*DAT_300af030 + 0x7c) = *(int *)(*DAT_300af030 + 0x7c) + 1;
  puVar8 = DAT_300af02c;
  iVar6 = param_1[1];
  iVar4 = *param_1;
  uVar1 = (*(code *)*DAT_300af02c)();
  if ((uVar1 & 5) == 5) {
    cacheClear(1,0,0xffffffff);
  }
  uVar1 = (*(code *)*puVar8)();
  if ((uVar1 & 0x1000) != 0) {
    cacheInvalidate(0,0,0xffffffff);
  }
  uVar3 = 0;
  if (unaff_r11 == 0) {
    uVar1 = 0;
    iVar7 = 0;
    do {
      if ((uVar1 < param_2) || (param_3 < uVar1)) {
        puVar8 = (undefined4 *)(iVar4 + iVar7 * 4);
        if ((param_4 & 4) != 0) {
          if ((*(uint *)(iVar4 + iVar7 * 4) & 3) == 1) {
            iVar2 = FUN_300ad708(*puVar8);
          }
          else {
            if ((iVar6 == 0) || ((*(uint *)(iVar6 + iVar7 * 4) & 3) != 1)) goto LAB_300aeba8;
            iVar2 = FUN_300ad708(*(undefined4 *)(iVar6 + iVar7 * 4));
          }
          if (iVar2 != 0) {
            uVar3 = 0xffffffff;
          }
        }
LAB_300aeba8:
        mmuCortexA8WordSet(puVar8,0);
        if (iVar6 != 0) {
          mmuCortexA8WordSet(iVar6 + iVar7 * 4,0);
        }
      }
      iVar7 = iVar7 + 1;
      uVar1 = uVar1 + 0x100000;
    } while (iVar7 < 0x1000);
  }
  else {
    param_2 = param_2 >> 0x14;
    if (param_2 <= param_3 >> 0x14) {
      puVar5 = (uint *)(iVar4 + param_2 * 4);
      do {
        if ((param_4 & 4) != 0) {
          if ((*puVar5 & 3) == 1) {
            iVar4 = FUN_300ad708(*puVar5);
          }
          else {
            if ((iVar6 == 0) || ((*(uint *)(iVar6 + param_2 * 4) & 3) != 1)) goto LAB_300aeaf4;
            iVar4 = FUN_300ad708(*(undefined4 *)(iVar6 + param_2 * 4));
          }
          if (iVar4 != 0) {
            uVar3 = 0xffffffff;
          }
        }
LAB_300aeaf4:
        mmuCortexA8WordSet(puVar5,0);
        if (iVar6 != 0) {
          mmuCortexA8WordSet(iVar6 + param_2 * 4,0);
        }
        puVar5 = puVar5 + 1;
        param_2 = param_2 + 1;
      } while (param_2 <= param_3 >> 0x14);
    }
  }
  mmuCortexA8TLBIDFlushAll();
  taskCpuUnlock();
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300aebec @ 0x300AEBEC  (примерный размер ~372 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300ace48, FUN_300ad8cc, bcopy, mmuCortexA8BufCopy, taskCpuUnlock
 * Константы: 0xFFFFFFFF, 0x300AEBEC
 * Данные: DAT_300af030, DAT_300af034, DAT_300af038, DAT_300af03c, DAT_300af040
 * ---------------------------------------------------------------- */
undefined4 FUN_300aebec(undefined4 param_1,void *param_2,void *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  size_t __n;
  uint local_2c;
  
  uVar2 = 0;
  if (*DAT_300af034 < param_4) {
    __n = 0x1000;
    uVar3 = (uint)param_3 & DAT_300af038;
    if ((uVar3 - (int)param_3) + 0x1000 < 0x1001) {
      __n = (uVar3 - (int)param_3) + 0x1000;
    }
    *(int *)(*DAT_300af030 + 0x7c) = *(int *)(*DAT_300af030 + 0x7c) + 1;
    while (param_4 != 0) {
      iVar1 = FUN_300ad8cc(param_1,uVar3,&local_2c);
      if ((iVar1 != 0) || ((local_2c & 2) == 0)) {
        uVar2 = 0xffffffff;
      }
      iVar1 = FUN_300ace48(param_1,uVar3,1,DAT_300af03c,0x10,0);
      if (iVar1 == -1) {
        uVar2 = 0xffffffff;
      }
      bcopy(param_2,param_3,__n);
      iVar1 = FUN_300ace48(param_1,uVar3,1,DAT_300af040,local_2c,0);
      if (iVar1 == -1) {
        uVar2 = 0xffffffff;
      }
      param_2 = (void *)((int)param_2 + __n);
      param_3 = (void *)((int)param_3 + __n);
      param_4 = param_4 - __n;
      __n = param_4;
      if (0x1000 < param_4) {
        __n = 0x1000;
      }
    }
    taskCpuUnlock();
  }
  else {
    mmuCortexA8BufCopy(param_2,param_3,param_4);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * mmuArchTtbrGet @ 0x300AED60  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: mmuCortexA8TtbrGet
 * Константы: 0x300AED60
 * Данные: DAT_300af044
 * ---------------------------------------------------------------- */
uint mmuArchTtbrGet(void)

{
  uint uVar1;
  
  uVar1 = mmuCortexA8TtbrGet();
  return uVar1 & DAT_300af044;
}

/* ----------------------------------------------------------------
 * FUN_300aedf0 @ 0x300AEDF0  (примерный размер ~132 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300aee74, FUN_300aeed4
 * Константы: 0xFF000000, 0x300AEDF0, 0xFFFFFFFF
 * Данные: DAT_300aef60, DAT_300af04c, DAT_300af050
 * ---------------------------------------------------------------- */
uint FUN_300aedf0(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = *(uint *)(param_1 + (param_2 >> 0x14) * 4);
  bVar2 = (uVar1 & 3) == 2;
  if (bVar2) {
    param_1 = uVar1 & DAT_300af04c;
    if (param_1 == 2) {
      bVar2 = (uVar1 & DAT_300af050) == (param_3 & DAT_300af050);
      param_1 = DAT_300af050;
      if (bVar2) {
        return 0;
      }
    }
    else {
      bVar2 = param_1 == DAT_300aef60;
      if ((bVar2) && (bVar2 = (uVar1 & 0xff000000) == (param_3 & 0xff000000), bVar2)) {
        param_1 = 0;
      }
    }
  }
  if (!bVar2) {
    param_1 = 0xffffffff;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * FUN_300aee74 @ 0x300AEE74  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300aedf0
 * Вызывают: FUN_300aeed4
 * Константы: 0x300AEE74, 0x00100000, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_300aee74(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_300aedf0(param_1,iVar2,param_2,param_3);
    if (iVar1 != -1) {
      *param_4 = iVar2;
      return 0;
    }
    iVar2 = iVar2 + 0x100000;
  } while (iVar2 != 0);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300aeed4 @ 0x300AEED4  (примерный размер ~392 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300abfb0, FUN_300aedf0, FUN_300aee74, errnoSet
 * Константы: 0x300AEED4, 0x00100000, 0xFFFFFFFF
 * Данные: DAT_300af038, DAT_300af054, DAT_300af058
 * ---------------------------------------------------------------- */
undefined4 FUN_300aeed4(undefined4 *param_1,uint param_2,int param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *local_2c;
  undefined1 auStack_28 [4];
  
  uVar1 = DAT_300af038;
  uVar5 = *param_1;
  uVar4 = param_2 & DAT_300af038;
  iVar2 = FUN_300abfb0(uVar5,param_2,&local_2c,auStack_28);
  if ((iVar2 == 0) && ((*local_2c & uVar1) == uVar4)) {
    *param_4 = param_2;
    uVar5 = 0;
  }
  else {
    if (param_3 == 0) {
      uVar6 = 0;
      do {
        iVar2 = FUN_300abfb0(uVar5,uVar6,&local_2c,auStack_28);
        if (iVar2 == 0) {
          uVar3 = *local_2c & 3;
          if (((uVar3 == 3) || (uVar3 == 2)) && ((*local_2c & uVar1) == uVar4)) {
            *param_4 = uVar6 | param_2 & DAT_300af054;
            return 0;
          }
          uVar6 = uVar6 + 0x1000;
        }
        else {
          iVar2 = FUN_300aedf0(uVar5,uVar6,param_2,0);
          if (iVar2 != -1) {
            *param_4 = uVar6;
            return 0;
          }
          uVar6 = uVar6 + 0x100000;
        }
      } while (uVar6 != 0);
    }
    else {
      iVar2 = FUN_300aee74(uVar5,param_2,param_3,param_4);
      if (iVar2 != -1) {
        return 0;
      }
    }
    errnoSet(DAT_300af058);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * memchr @ 0x300BD988  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 0
 * Вызывают: FUN_300f6f30, FUN_300f7094, __sfvwrite, fgets
 * Константы: 0x300BD988
 * ---------------------------------------------------------------- */
void * memchr(void *__s,int __c,size_t __n)

{
  while( true ) {
    if (__n == 0) {
      return (void *)0x0;
    }
                    /* WARNING: Load size is inaccurate */
    if ((uint)*__s == (__c & 0xffU)) break;
    __n = __n - 1;
    __s = (byte *)((int)__s + 1);
  }
  return (byte *)__s;
}

/* ----------------------------------------------------------------
 * memcmp @ 0x300BD9B8  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 49 | Вызывает: 0
 * Вызывают: FUN_30015718, FUN_30019658, FUN_300c762c, FUN_300d266c, FUN_300d42ac, FUN_300f795c, FUN_300f8b2c, FUN_300f8fc4, FUN_300f9570, FUN_300fe2bc
 *           ...
 * Константы: 0x300BD9B8
 * ---------------------------------------------------------------- */
int memcmp(void *__s1,void *__s2,size_t __n)

{
  if (__n == 0) {
    return 0;
  }
  do {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if (*__s1 != *__s2) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      return (uint)*__s1 - (uint)*__s2;
    }
    __n = __n - 1;
    __s1 = (byte *)((int)__s1 + 1);
    __s2 = (byte *)((int)__s2 + 1);
  } while (__n != 0);
  return 0;
}

/* ----------------------------------------------------------------
 * memcpy @ 0x300BD9F8  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 111 | Вызывает: 1
 * Вызывает: bcopy
 * Вызывают: BSP_DLOAD_GetISOVer, BSP_HwGetPCBVersion, BSP_InitBootVersion, BSP_IpCfgModifyBootLine, BSP_MEM_Init, BSP_NANDF_DrxBakReg, BSP_NANDF_DrxRestoreReg, BSP_NET_OMIpMacGet, BSP_NET_PsMacGet, BSP_OM_GetDloadVer
 *           ...
 * Константы: 0x300BD9F8
 * ---------------------------------------------------------------- */
void * memcpy(void *__dest,void *__src,size_t __n)

{
  bcopy(__src,__dest,__n);
  return __dest;
}

/* ----------------------------------------------------------------
 * memmove @ 0x300BDA14  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 8 | Вызывает: 1
 * Вызывает: bcopy
 * Вызывают: FUN_300c7590, FUN_300f7094, FUN_300f795c, FUN_300f7c20, FUN_30112ec0, ledCDelete, ledRead, vxdbgMemMove
 * Константы: 0x300BDA14
 * ---------------------------------------------------------------- */
void * memmove(void *__dest,void *__src,size_t __n)

{
  bcopy(__src,__dest,__n);
  return __dest;
}

/* ----------------------------------------------------------------
 * memset @ 0x300BDA30  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 191 | Вызывает: 1
 * Вызывает: bfill
 * Вызывают: ATCommandHandle, BSP_DLOAD_GetDloadFlashInfo, BSP_DLOAD_GetDloadInfo, BSP_DLOAD_GetProductId, BSP_GPIO_Init, BSP_GetProductDloadName, BSP_GetProductInnerName, BSP_GetProductName, BSP_HwGetHwVersion, BSP_HwGetPCBVersion
 *           ...
 * Константы: 0x300BDA30
 * ---------------------------------------------------------------- */
void * memset(void *__s,int __c,size_t __n)

{
  bfill(__s,__n,__c);
  return __s;
}

/* ----------------------------------------------------------------
 * clock @ 0x300BE444  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BE444
 * ---------------------------------------------------------------- */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

clock_t clock(void)

{
  return -1;
}

/* ----------------------------------------------------------------
 * fioBaseLibInit @ 0x300C2F34  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C2F34
 * Данные: DAT_300c3068, DAT_300c306c
 * ---------------------------------------------------------------- */
void fioBaseLibInit(void)

{
  *DAT_300c306c = DAT_300c3068;
  return;
}

/* ----------------------------------------------------------------
 * fioFormatV @ 0x300C2F44  (примерный размер ~4096 байт)
 * Модуль: kernel | Вызывают: 13 | Вызывает: 0
 * Вызывают: exchLogPrintf, fdprintf, oprintf, printErr, printf, snprintf, sprintf, vfdprintf, vfprintf, voprintf
 *           ...
 * Константы: 0x300C2F44, 0x300C3B78, 0x300C3B88, 0x300C3B8C, 0x300C3B98, 0x300C3D5C, 0x300C3D68, 0x300C3D7C
 * Данные: DAT_300c3070
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300c3b78) */
/* WARNING: Removing unreachable block (ram,0x300c3b88) */
/* WARNING: Removing unreachable block (ram,0x300c3b8c) */
/* WARNING: Removing unreachable block (ram,0x300c3b98) */
/* WARNING: Removing unreachable block (ram,0x300c3d5c) */
/* WARNING: Removing unreachable block (ram,0x300c3d68) */
/* WARNING: Removing unreachable block (ram,0x300c3d7c) */
/* WARNING: Removing unreachable block (ram,0x300c3d9c) */
/* WARNING: Removing unreachable block (ram,0x300c3dac) */
/* WARNING: Removing unreachable block (ram,0x300c3db0) */
/* WARNING: Removing unreachable block (ram,0x300c3ba8) */
/* WARNING: Removing unreachable block (ram,0x300c3bdc) */
/* WARNING: Removing unreachable block (ram,0x300c3be8) */
/* WARNING: Removing unreachable block (ram,0x300c3bf4) */
/* WARNING: Removing unreachable block (ram,0x300c3c14) */
/* WARNING: Removing unreachable block (ram,0x300c3c24) */
/* WARNING: Removing unreachable block (ram,0x300c3c28) */
/* WARNING: Removing unreachable block (ram,0x300c3c54) */
/* WARNING: Removing unreachable block (ram,0x300c3c74) */
/* WARNING: Removing unreachable block (ram,0x300c3c84) */
/* WARNING: Removing unreachable block (ram,0x300c3e7c) */
/* WARNING: Removing unreachable block (ram,0x300c3e8c) */
/* WARNING: Removing unreachable block (ram,0x300c3e98) */
/* WARNING: Removing unreachable block (ram,0x300c3eac) */
/* WARNING: Removing unreachable block (ram,0x300c3ecc) */
/* WARNING: Removing unreachable block (ram,0x300c3edc) */
/* WARNING: Removing unreachable block (ram,0x300c3ee0) */
/* WARNING: Removing unreachable block (ram,0x300c3cc8) */
/* WARNING: Removing unreachable block (ram,0x300c3cd8) */
/* WARNING: Removing unreachable block (ram,0x300c3ce4) */
/* WARNING: Removing unreachable block (ram,0x300c3cf8) */
/* WARNING: Removing unreachable block (ram,0x300c3d18) */
/* WARNING: Removing unreachable block (ram,0x300c3d28) */
/* WARNING: Removing unreachable block (ram,0x300c3d2c) */
/* WARNING: Removing unreachable block (ram,0x300c3e00) */
/* WARNING: Removing unreachable block (ram,0x300c3e0c) */
/* WARNING: Removing unreachable block (ram,0x300c3e1c) */
/* WARNING: Removing unreachable block (ram,0x300c3e3c) */
/* WARNING: Removing unreachable block (ram,0x300c3e4c) */
/* WARNING: Removing unreachable block (ram,0x300c3e50) */
/* WARNING: Removing unreachable block (ram,0x300c3f0c) */

int fioFormatV(char *param_1,undefined4 param_2,code *param_3,undefined4 param_4)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int local_220;
  byte local_1c0 [400];
  
  local_220 = 0;
  while( true ) {
    cVar1 = *param_1;
    pcVar5 = param_1;
    while ((cVar1 != '\0' && (cVar1 != '%'))) {
      pcVar5 = pcVar5 + 1;
      cVar1 = *pcVar5;
    }
    iVar6 = (int)pcVar5 - (int)param_1;
    if (iVar6 != 0) {
      iVar3 = (*param_3)(param_1,iVar6,param_4);
      if (iVar3 != 0) {
        return -1;
      }
      local_220 = local_220 + iVar6;
    }
    if (cVar1 == '\0') {
      return local_220;
    }
    bVar2 = pcVar5[1];
    param_1 = pcVar5 + 2;
    uVar4 = bVar2 - 0x20;
    if (uVar4 < 0x59) {
                    /* WARNING: Could not recover jumptable at 0x300c3064. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar6 = (**(code **)(DAT_300c3070 + uVar4 * 4))();
      return iVar6;
    }
    if (bVar2 == 0) break;
    local_1c0[0] = bVar2;
    iVar6 = (*param_3)(local_1c0,1,param_4);
    if (iVar6 != 0) {
      return -1;
    }
    local_220 = local_220 + 1;
  }
  return local_220;
}

/* ----------------------------------------------------------------
 * sprintf @ 0x300C3FD0  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 46 | Вызывает: 1
 * Вызывает: fioFormatV
 * Вызывают: BSP_DLOAD_GetDloadInfo, BSP_DLOAD_Init, BSP_IpCfgSaveIpMask, BSP_OM_GetVersion, FUN_30062d44, FUN_30095574, FUN_300d8fc4, FUN_300e2404, FUN_300f58d8, FUN_300f5a30
 *           ...
 * Константы: 0x300C3FD0
 * Данные: DAT_300c43ec
 * ---------------------------------------------------------------- */
int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  char *local_10;
  char *local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_10 = __s;
  local_c = __format;
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  iVar1 = fioFormatV(__format,&uStack_8,DAT_300c43ec,&local_10);
  *local_10 = '\0';
  return iVar1;
}

/* ----------------------------------------------------------------
 * fioBufPut @ 0x300C42F8  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: bcopy
 * Константы: 0x300C42F8
 * ---------------------------------------------------------------- */
undefined4 fioBufPut(void *param_1,size_t param_2,int *param_3)

{
  bcopy(param_1,(void *)*param_3,param_2);
  *param_3 = *param_3 + param_2;
  return 0;
}

/* ----------------------------------------------------------------
 * fioSnBufPut @ 0x300C4324  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: bcopy
 * Константы: 0x300C4324
 * ---------------------------------------------------------------- */
undefined4 fioSnBufPut(void *param_1,size_t param_2,int *param_3)

{
  size_t __n;
  
  __n = (param_3[1] - *param_3) - 1;
  if (0 < (int)__n) {
    if ((int)param_2 <= (int)__n) {
      __n = param_2;
    }
    bcopy(param_1,(void *)*param_3,__n);
    *param_3 = *param_3 + __n;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * fioBufPrint @ 0x300C4370  (примерный размер ~168 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C4370, 0xFFFFFFFF
 * Данные: DAT_300c4414
 * ---------------------------------------------------------------- */
undefined4 fioBufPrint(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((code *)*DAT_300c4414 == (code *)0x0) ||
     (iVar1 = (*(code *)*DAT_300c4414)(param_3,param_1,param_2), iVar1 != param_2)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * fioFltInstall @ 0x300C4418  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C4418
 * Данные: DAT_300c53a4, DAT_300c53a8
 * ---------------------------------------------------------------- */
void fioFltInstall(undefined4 param_1,undefined4 param_2)

{
  *DAT_300c53a4 = param_1;
  *DAT_300c53a8 = param_2;
  return;
}

/* ----------------------------------------------------------------
 * fioLibInit @ 0x300C54D8  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrIosExtraInit
 * Константы: 0x300C54D8
 * Данные: DAT_300c5d80, DAT_300c5d84
 * ---------------------------------------------------------------- */
void fioLibInit(void)

{
  *DAT_300c5d84 = DAT_300c5d80;
  return;
}

/* ----------------------------------------------------------------
 * fioRead @ 0x300C55F4  (примерный размер ~112 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 1
 * Вызывает: read
 * Вызывают: copyStreams, loadModuleStringRead, loadModuleValueRead
 * Константы: 0xFFFFFFFF, 0x300C55F4
 * ---------------------------------------------------------------- */
size_t fioRead(int param_1,void *param_2,size_t param_3)

{
  ssize_t sVar1;
  size_t __nbytes;
  
  __nbytes = param_3;
  if ((int)param_3 < 0) {
    return 0xffffffff;
  }
  while( true ) {
    if ((int)__nbytes < 1) {
      return param_3;
    }
    sVar1 = read(param_1,param_2,__nbytes);
    if (sVar1 < 0) break;
    if (sVar1 == 0) {
      return param_3 - __nbytes;
    }
    __nbytes = __nbytes - sVar1;
    param_2 = (void *)((int)param_2 + sVar1);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * fioRdString @ 0x300C5664  (примерный размер ~168 байт)
 * Модуль: kernel | Вызывают: 10 | Вызывает: 1
 * Вызывает: read
 * Вызывают: FUN_300f58d8, FUN_300f5a30, FUN_30110224, FUN_3011e3a0, FUN_3012b38c, changeFpReg, changeReg, help, memoryModify, netHelp
 * Константы: 0x300C5664
 * ---------------------------------------------------------------- */
int fioRdString(int param_1,int param_2,int param_3)

{
  int iVar1;
  ssize_t sVar2;
  int iVar3;
  bool bVar4;
  char local_1c [4];
  
  iVar3 = 0;
  iVar1 = iVar3;
  if (0 < param_3) {
    do {
      iVar3 = iVar1;
      sVar2 = read(param_1,local_1c,1);
      bVar4 = sVar2 == -1;
      if (bVar4) goto LAB_300c56fc;
      if (((sVar2 != 1) || (local_1c[0] == '\n')) || (local_1c[0] == '\0')) {
        *(undefined1 *)(param_2 + iVar3) = 0;
        break;
      }
      *(char *)(param_2 + iVar3) = local_1c[0];
      iVar1 = iVar3 + 1;
    } while (iVar3 + 1 < param_3);
    iVar3 = iVar3 + 1;
    bVar4 = sVar2 == -1;
    if (!bVar4) {
      if (sVar2 != 0) {
        return iVar3;
      }
      bVar4 = iVar3 == 1;
    }
LAB_300c56fc:
    if (bVar4) {
      iVar3 = -1;
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_300c570c @ 0x300C570C  (примерный размер ~172 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x300C570C
 * Данные: DAT_300c5d94
 * ---------------------------------------------------------------- */
bool FUN_300c570c(undefined1 *param_1,int param_2,code *param_3,undefined4 param_4,uint *param_5,
                 int *param_6)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  uVar1 = *param_5;
  iVar3 = 0;
  while (((uVar1 != 0xffffffff && (iVar3 < param_2)) &&
         ((*(byte *)(*DAT_300c5d94 + (uVar1 & 0xff)) & 0x28) == 0))) {
    puVar2 = param_1;
    if (param_1 != (undefined1 *)0x0) {
      puVar2 = param_1 + 1;
      *param_1 = (char)uVar1;
    }
    iVar3 = iVar3 + 1;
    uVar1 = (*param_3)(param_4,0xffffffff);
    param_1 = puVar2;
  }
  if (param_1 != (undefined1 *)0x0) {
    *param_1 = 0;
  }
  *param_5 = uVar1;
  *param_6 = iVar3 + *param_6;
  return iVar3 != 0;
}

/* ----------------------------------------------------------------
 * FUN_300c57b8 @ 0x300C57B8  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C57B8, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
bool FUN_300c57b8(undefined1 *param_1,int param_2,code *param_3,undefined4 param_4,int *param_5,
                 int *param_6)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar1 = *param_5;
  for (iVar3 = 0; (iVar1 != -1 && (iVar3 < param_2)); iVar3 = iVar3 + 1) {
    puVar2 = param_1;
    if (param_1 != (undefined1 *)0x0) {
      puVar2 = param_1 + 1;
      *param_1 = (char)iVar1;
    }
    iVar1 = (*param_3)(param_4,0xffffffff);
    param_1 = puVar2;
  }
  *param_5 = iVar1;
  *param_6 = iVar3 + *param_6;
  return iVar3 != 0;
}

/* ----------------------------------------------------------------
 * fioScanV @ 0x300C6020  (примерный размер ~880 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 1
 * Вызывает: scanField
 * Вызывают: fscanf, scanf, sscanf
 * Константы: 0xFFFFFFFF, 0x300C6020, 0xFFFFFFFC
 * Данные: DAT_300c63f8
 * ---------------------------------------------------------------- */
uint fioScanV(byte *param_1,code *param_2,undefined4 param_3,uint *param_4,int param_5)

{
  bool bVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  uint local_3c;
  int local_38;
  uint local_34;
  byte *local_30;
  int local_2c;
  
  bVar9 = false;
  puVar5 = (undefined4 *)(param_5 + 7U & 0xfffffffc);
  local_34 = 0;
  local_38 = 0;
  uVar6 = puVar5[-1];
  uVar4 = (*param_2)(param_3);
  local_3c = uVar4;
  do {
    piVar3 = DAT_300c63f8;
    bVar2 = *param_1;
    if (bVar2 == 0) break;
    bVar1 = true;
    if (((bVar2 == 9) || (bVar2 == 10)) || (bVar2 == 0x20)) {
      param_1 = param_1 + 1;
      bVar2 = *(byte *)(*DAT_300c63f8 + (local_3c & 0xff));
      while ((bVar2 & 0x28) != 0) {
        local_38 = local_38 + 1;
        uVar4 = (*param_2)(param_3,0xffffffff);
        local_3c = uVar4;
        bVar2 = *(byte *)(*piVar3 + (uVar4 & 0xff));
      }
    }
    else {
      pbVar7 = param_1;
      if (bVar2 == 0x25) {
        pbVar7 = param_1 + 1;
        bVar2 = *pbVar7;
        if (bVar2 == 0x25) goto LAB_300c6310;
        if (bVar2 != 99) {
          if (bVar2 < 100) {
            if (bVar2 == 0x2a) {
              if ((param_1[2] != 0x5b) && (param_1[2] != 99)) {
                bVar2 = *(byte *)(*DAT_300c63f8 + (local_3c & 0xff));
                while ((bVar2 & 0x28) != 0) {
                  local_38 = local_38 + 1;
                  local_3c = (*param_2)(param_3,0xffffffff);
                  bVar2 = *(byte *)(*piVar3 + (local_3c & 0xff));
                }
              }
            }
            else {
              if (bVar2 == 0x4c) goto LAB_300c61c8;
              if (bVar2 != 0x5b) goto LAB_300c6220;
            }
          }
          else {
            if ((bVar2 == 0x68) || (bVar2 == 0x6c)) {
LAB_300c61c8:
              bVar8 = param_1[2] == 0x6e;
              if (!bVar8) {
                if ((bVar2 != 0x6c) || (param_1[2] != 0x6c)) goto LAB_300c6220;
                bVar8 = param_1[3] == 0x6e;
              }
LAB_300c61ec:
              bVar1 = !bVar8;
              if (!bVar1) goto LAB_300c6238;
            }
            else {
              bVar8 = bVar2 == 0x6e;
              if (bVar8) goto LAB_300c61ec;
            }
LAB_300c6220:
            while ((*(byte *)(*piVar3 + (local_3c & 0xff)) & 0x28) != 0) {
              local_38 = local_38 + 1;
              local_3c = (*param_2)(param_3,0xffffffff);
            }
          }
        }
LAB_300c6238:
        if (local_3c == 0xffffffff) {
          bVar2 = *pbVar7;
          if (((bVar2 == 0x4c) || (bVar2 == 0x68)) || (bVar2 == 0x6c)) {
            if (param_1[2] != 0x6e) {
              if ((bVar2 == 0x6c) && (param_1[2] == 0x6c)) {
                bVar2 = param_1[3];
                goto joined_r0x300c6294;
              }
              goto LAB_300c6298;
            }
          }
          else {
joined_r0x300c6294:
            if (bVar2 != 0x6e) {
LAB_300c6298:
              bVar9 = true;
            }
          }
        }
        local_30 = pbVar7;
        uVar4 = scanField(&local_30,uVar6,param_2,param_3,&local_2c,&local_3c,&local_38);
        pbVar7 = local_30;
        if (uVar4 != 0) {
          param_1 = local_30;
          if (local_2c == 0) {
            local_34 = local_34 + bVar1;
            uVar6 = *puVar5;
            puVar5 = puVar5 + 1;
          }
          goto LAB_300c6350;
        }
      }
      else {
LAB_300c6310:
        if (*pbVar7 == local_3c) {
          local_38 = local_38 + 1;
          uVar4 = (*param_2)(param_3,0xffffffff);
          param_1 = pbVar7 + 1;
          local_3c = uVar4;
          goto LAB_300c6350;
        }
      }
      bVar9 = true;
      param_1 = pbVar7;
    }
LAB_300c6350:
  } while (!bVar9);
  *param_4 = local_3c;
  bVar9 = local_34 == 0;
  if ((bVar9) && (bVar9 = local_3c == 0xffffffff, bVar9)) {
    uVar4 = 0xffffffff;
  }
  if (!bVar9) {
    uVar4 = local_34;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * vxdbgBpAllDisable @ 0x300C6758  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 1
 * Вызывает: usrBreakpointSet
 * Вызывают: FUN_300c7bac, FUN_300c809c, FUN_300c8154, vxdbgEnable
 * Константы: 0x300C6758
 * Данные: DAT_300c74b4
 * ---------------------------------------------------------------- */
void vxdbgBpAllDisable(void)

{
  int *piVar1;
  
  piVar1 = DAT_300c74b4;
  while (piVar1 = (int *)*piVar1, piVar1 != (int *)0x0) {
    if (piVar1[10] != 0) {
      usrBreakpointSet(piVar1[3],piVar1[4],0,2);
      piVar1[10] = 0;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * vxdbgEnable @ 0x300C679C  (примерный размер ~120 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300c6554, taskCpuLock, taskCpuUnlock, vxdbgBpAllDisable
 * Константы: 0x300C679C
 * Данные: DAT_300c74ac, DAT_300c74b0
 * ---------------------------------------------------------------- */
void vxdbgEnable(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_300c74ac;
  if (DAT_300c74ac[5] != 0) {
    if (param_1 == 0) {
      if (*DAT_300c74ac != 0) {
        taskCpuLock();
        vxdbgBpAllDisable();
        taskCpuUnlock();
        *piVar1 = 0;
      }
    }
    else if (*DAT_300c74ac == 0) {
      *DAT_300c74ac = 1;
      FUN_300c6554(*DAT_300c74b0,*DAT_300c74b0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * vxdbgClntRegister @ 0x300C6814  (примерный размер ~264 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_300c6400, calloc, semBCreate, spinLockTaskGive, spinLockTaskInit, spinLockTaskTake, wdbDbgArchInit
 * Вызывают: dbgInit
 * Константы: 0x300C6814
 * Данные: DAT_300c74ac, DAT_300c74b4, DAT_300c77d4, DAT_300c77d8, DAT_300c77dc, DAT_300c77e0, DAT_300c77e4, DAT_300c77e8
 * ---------------------------------------------------------------- */
void * vxdbgClntRegister(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  
  iVar1 = DAT_300c74ac;
  if (*(int *)(DAT_300c74ac + 0x14) == 0) {
    iVar4 = semBCreate(0,1);
    *(int *)(iVar1 + 0x18) = iVar4;
    if (iVar4 == 0) {
      return (void *)0x0;
    }
    spinLockTaskInit(DAT_300c77d4,0);
    puVar2 = DAT_300c77d8;
    *DAT_300c77d8 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2 = DAT_300c74b4;
    *DAT_300c74b4 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2 = DAT_300c77dc;
    *DAT_300c77dc = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    wdbDbgArchInit();
    *DAT_300c77e4 = DAT_300c77e0;
    puVar2 = DAT_300c77e8;
    *DAT_300c77e8 = DAT_300c77ec;
    puVar2[1] = DAT_300c77f0;
    puVar2[2] = DAT_300c77f4;
    *(undefined4 *)(iVar1 + 0x14) = 1;
  }
  pvVar5 = calloc(1,0x1c);
  if (pvVar5 == (void *)0x0) {
    pvVar5 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar5 + 0x18) = param_1;
    uVar3 = DAT_300c77d4;
    spinLockTaskTake(DAT_300c77d4);
    FUN_300c6400(DAT_300c77d8,DAT_300c77d8[1],pvVar5);
    spinLockTaskGive(uVar3);
  }
  return pvVar5;
}

/* ----------------------------------------------------------------
 * vxdbgHookAdd @ 0x300C691C  (примерный размер ~148 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: __errno, spinLockTaskGive, spinLockTaskTake
 * Вызывают: dbgInit
 * Константы: 0xFFFFFFFF, 0x300C691C
 * Данные: DAT_300c77d4, DAT_300c77f8, DAT_300c7918
 * ---------------------------------------------------------------- */
undefined4 vxdbgHookAdd(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar1 = DAT_300c77d4;
  if (0xf < param_2) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = DAT_300c77f8;
    return 0xffffffff;
  }
  uVar2 = 0;
  do {
    uVar4 = uVar2;
    if (param_2 == 1 << (uVar4 & 0xff)) break;
    uVar2 = uVar4 + 1;
  } while (uVar4 + 1 < 4);
  spinLockTaskTake(DAT_300c77d4);
  param_1 = param_1 + uVar4 * 4;
  if (*(int *)(param_1 + 8) != 0) {
    spinLockTaskGive(uVar1);
    puVar3 = (undefined4 *)__errno();
    *puVar3 = DAT_300c7918;
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 8) = param_3;
  spinLockTaskGive(uVar1);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300c69b0 @ 0x300C69B0  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 5
 * Вызывает: semGive, semTake, taskBpHookSet, taskSwitchHookAdd, vxdbgTaskLibInit
 * Вызывают: vxdbgBpAdd, vxdbgStep
 * Константы: 0x300C69B0, 0xFFFFFFFF
 * Данные: DAT_300c74ac, DAT_300c77e8, DAT_300c791c, DAT_300c7920, DAT_300c7924, DAT_300c7928, DAT_300c792c, DAT_300c7930
 * ---------------------------------------------------------------- */
void FUN_300c69b0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_300c74ac;
  if (*(int *)(DAT_300c74ac + 0x24) == 0) {
    semTake(*(undefined4 *)(DAT_300c74ac + 0x18),0xffffffff);
    if (*(int *)(iVar1 + 0x24) == 0) {
      taskSwitchHookAdd(DAT_300c791c);
      taskBpHookSet(DAT_300c7920);
      vxdbgTaskLibInit();
      iVar2 = DAT_300c77e8;
      *(undefined4 *)(DAT_300c77e8 + 0xc) = DAT_300c7924;
      *(undefined4 *)(iVar2 + 0x10) = DAT_300c7928;
      *(undefined4 *)(iVar2 + 0x14) = DAT_300c792c;
      *(undefined4 *)(iVar2 + 0x18) = DAT_300c7930;
      *(undefined4 *)(iVar1 + 0x24) = 1;
    }
    semGive(*(undefined4 *)(iVar1 + 0x18));
  }
  return;
}

/* ----------------------------------------------------------------
 * vxdbgStep @ 0x300C6A40  (примерный размер ~80 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300c69b0, __errno, vxdbgTaskStep
 * Вызывают: FUN_30114a38
 * Константы: 0x300C6A40, 0xFFFFFFFF
 * Данные: DAT_300c7934
 * ---------------------------------------------------------------- */
undefined4 vxdbgStep(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  FUN_300c69b0();
  if ((param_2[1] & 1) == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_300c7934;
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = vxdbgTaskStep(param_1,*param_2,param_3,param_4);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * vxdbgStop @ 0x300C6A90  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, vxdbgTaskStop
 * Константы: 0x300C6A90, 0xFFFFFFFF
 * Данные: DAT_300c7934, DAT_300c7a38
 * ---------------------------------------------------------------- */
undefined4 vxdbgStop(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((param_2[1] & 1) == 0) {
    if (((param_2[1] & 2) == 0) || ((code *)*DAT_300c7a38 == (code *)0x0)) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300c7934;
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = (*(code *)*DAT_300c7a38)(*param_2);
    }
  }
  else {
    uVar1 = vxdbgTaskStop(param_1,*param_2);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * vxdbgCont @ 0x300C6AF0  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: __errno, vxdbgTaskCont
 * Вызывают: FUN_30114a38
 * Константы: 0x300C6AF0, 0xFFFFFFFF
 * Данные: DAT_300c7934, DAT_300c7a3c
 * ---------------------------------------------------------------- */
undefined4 vxdbgCont(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((param_2[1] & 1) == 0) {
    if (((param_2[1] & 2) == 0) || ((code *)*DAT_300c7a3c == (code *)0x0)) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300c7934;
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = (*(code *)*DAT_300c7a3c)(param_1,*param_2);
    }
  }
  else {
    uVar1 = vxdbgTaskCont(param_1,*param_2);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300c6b50 @ 0x300C6B50  (примерный размер ~384 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 4
 * Вызывает: __errno, intContext, spinLockTaskGive, spinLockTaskTake
 * Вызывают: FUN_300c701c, FUN_300c78e4, FUN_300c7cbc, vxdbgBpAdd
 * Константы: 0x300C6B50
 * Данные: DAT_300c77d4, DAT_300c77d8, DAT_300c77f8
 * ---------------------------------------------------------------- */
void FUN_300c6b50(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  int *piVar7;
  
  if ((int)param_2 < 0x10) {
    uVar2 = 0;
    do {
      uVar5 = uVar2;
      if (param_2 == 1 << (uVar5 & 0xff)) break;
      uVar2 = uVar5 + 1;
    } while (uVar5 + 1 < 4);
    pcVar6 = *(code **)(param_1 + uVar5 * 4 + 8);
    if (pcVar6 != (code *)0x0) {
      (*pcVar6)(param_3,param_4,param_5,param_6,param_7);
    }
    iVar4 = intContext();
    piVar7 = DAT_300c77d8;
    if (iVar4 == 0) {
      spinLockTaskTake(DAT_300c77d4);
      piVar7 = DAT_300c77d8;
    }
    while (piVar7 = (int *)*piVar7, piVar7 != (int *)0x0) {
      if ((((int *)param_1 != piVar7) && ((param_2 & piVar7[6]) == param_2)) &&
         (pcVar6 = (code *)piVar7[uVar5 + 2], pcVar6 != (code *)0x0)) {
        iVar4 = intContext();
        uVar1 = DAT_300c77d4;
        if (iVar4 == 0) {
          spinLockTaskGive(DAT_300c77d4);
          (*pcVar6)(param_3,param_4,param_5,param_6,param_7);
          spinLockTaskTake(uVar1);
        }
        else {
          (*pcVar6)(param_3,param_4,param_5,param_6,param_7);
        }
      }
    }
    iVar4 = intContext();
    if (iVar4 == 0) {
      spinLockTaskGive(DAT_300c77d4);
    }
  }
  else {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = DAT_300c77f8;
  }
  return;
}

/* ----------------------------------------------------------------
 * vxdbgBpAdd @ 0x300C6CD0  (примерный размер ~844 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 12
 * Вызывает: FUN_300c6400, FUN_300c6438, FUN_300c69b0, FUN_300c6b50, __errno, calloc, memset, objVerify, taskCpuLock, taskCpuUnlock, usrBreakpointSet, vxdbgBpAddrCheck
 * Вызывают: FUN_30114a38, dbgBpEpCoreRtn, vxdbgTaskStep
 * Константы: 0xFFFFFFFF, 0x300C6CD0
 * Данные: DAT_300c73e0, DAT_300c73e4, DAT_300c74ac, DAT_300c74b0, DAT_300c74b4, DAT_300c7610, DAT_300c7614, DAT_300c77dc
 * ---------------------------------------------------------------- */
undefined4
vxdbgBpAdd(undefined4 param_1,int *param_2,undefined2 param_3,uint param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined1 param_8,undefined4 param_9,
          undefined4 *param_10)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  void *__s;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 local_2c;
  
  FUN_300c69b0();
  if (((param_4 & 0x10) != 0) && (*DAT_300c7a38 == 0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_300c7c90;
    return 0xffffffff;
  }
  if ((param_2[1] & 1U) == 0) {
LAB_300c6d68:
    if (((param_2[1] & 2U) == 0) ||
       (((code *)*DAT_300c73e4 == (code *)0x0 ||
        (iVar4 = (*(code *)*DAT_300c73e4)(*param_2), iVar4 != 0)))) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300c7934;
      return 0xffffffff;
    }
    iVar4 = *param_2;
  }
  else if (*param_2 == 0) {
    iVar4 = 0;
  }
  else {
    if (((param_2[1] & 1U) == 0) || (iVar4 = objVerify(*param_2,*DAT_300c7c94), iVar4 != 0))
    goto LAB_300c6d68;
    iVar4 = *(int *)(*param_2 + 0x94);
  }
  iVar3 = vxdbgBpAddrCheck(iVar4,param_7,&local_2c);
  iVar5 = DAT_300c77dc;
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  uVar7 = 0;
  while( true ) {
    taskCpuLock(uVar7);
    iVar3 = *(int *)(iVar5 + 8);
    taskCpuUnlock();
    if (iVar3 == 0) break;
    taskCpuLock();
    __s = *(void **)(iVar5 + 4);
    if (__s != (void *)0x0) {
      FUN_300c6438(iVar5,__s);
      taskCpuUnlock();
      memset(__s,0,0x38);
      goto LAB_300c6e40;
    }
    uVar7 = taskCpuUnlock();
  }
  __s = calloc(1,0x38);
  if (__s == (void *)0x0) {
    return 0xffffffff;
  }
LAB_300c6e40:
  iVar5 = DAT_300c74ac;
  iVar3 = *(int *)(DAT_300c74ac + 0x28);
  *(int *)((int)__s + 8) = iVar3;
  *(int *)(iVar5 + 0x28) = iVar3 + 1;
  *(undefined2 *)((int)__s + 0x20) = param_3;
  *(undefined1 *)((int)__s + 0x22) = param_8;
  *(uint *)((int)__s + 0x2c) = param_4;
  *(undefined4 *)((int)__s + 0x30) = param_5;
  *(undefined4 *)((int)__s + 0x34) = param_6;
  *(undefined4 *)((int)__s + 0xc) = param_7;
  *(undefined4 *)((int)__s + 0x24) = param_9;
  *(int *)((int)__s + 0x18) = param_2[1];
  *(int *)((int)__s + 0x14) = *param_2;
  *(undefined4 *)((int)__s + 0x1c) = param_1;
  *(undefined4 *)((int)__s + 0x10) = local_2c;
  taskCpuLock();
  piVar1 = DAT_300c74b4;
  piVar6 = (int *)*DAT_300c74b4;
  if (piVar6 != (int *)0x0) {
    do {
      if (*(uint *)((int)__s + 0xc) < (uint)piVar6[3]) {
        FUN_300c6400(DAT_300c74b4,piVar6[1],__s);
        break;
      }
      piVar6 = (int *)*piVar6;
    } while (piVar6 != (int *)0x0);
    if (piVar6 != (int *)0x0) goto LAB_300c6efc;
  }
  FUN_300c6400(piVar1,piVar1[1],__s);
LAB_300c6efc:
  taskCpuUnlock();
  iVar5 = *DAT_300c74b0;
  if ((((((*(uint *)((int)__s + 0x18) & 1) != 0) && (*(int *)((int)__s + 0x14) == iVar5)) ||
       (((*(uint *)((int)__s + 0x18) & 2) != 0 &&
        (*(int *)((int)__s + 0x14) == *(int *)(iVar5 + 0x94))))) || (*(int *)((int)__s + 0x14) == 0)
      ) && (((*(uint *)(iVar5 + 0x98) & 2) == 0 ||
            (((*(uint *)((int)__s + 0x2c) & 0x14) == 0 && (*DAT_300c7610 == 0)))))) {
    *(undefined4 *)((int)__s + 0x28) = 1;
    if ((code *)*DAT_300c73e0 == (code *)0x0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (*(code *)*DAT_300c73e0)(iVar4,0);
    }
    usrBreakpointSet(*(undefined4 *)((int)__s + 0xc),DAT_300c7614,iVar4,2);
    if ((code *)*DAT_300c73e0 != (code *)0x0) {
      (*(code *)*DAT_300c73e0)(uVar7,0);
    }
  }
  FUN_300c6b50(param_1,4,__s,0,0,0,0);
  *param_10 = *(undefined4 *)((int)__s + 8);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300c701c @ 0x300C701C  (примерный размер ~328 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_300c6400, FUN_300c6438, FUN_300c6b50, taskCpuLock, taskCpuUnlock, usrBreakpointSet
 * Вызывают: vxdbgBpDelete
 * Константы: 0x300C701C
 * Данные: DAT_300c73e0, DAT_300c74b4, DAT_300c77dc
 * ---------------------------------------------------------------- */
undefined4 FUN_300c701c(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  bool bVar5;
  
  taskCpuLock();
  piVar3 = DAT_300c74b4;
  FUN_300c6438(DAT_300c74b4,param_1);
  taskCpuUnlock();
  if (*(int *)(param_1 + 0x28) != 0) {
    bVar5 = true;
    taskCpuLock();
    do {
      piVar3 = (int *)*piVar3;
      if (piVar3 == (int *)0x0) goto LAB_300c7084;
    } while ((piVar3[10] == 0) || (piVar3[3] != *(int *)(param_1 + 0xc)));
    bVar5 = false;
LAB_300c7084:
    taskCpuUnlock();
    puVar1 = DAT_300c73e0;
    if (bVar5) {
      uVar2 = *(uint *)(param_1 + 0x18);
      if ((uVar2 & 2) == 0) {
        bVar5 = (uVar2 & 1) == 0;
        if (!bVar5) {
          uVar2 = *(uint *)(param_1 + 0x14);
          bVar5 = uVar2 == 0;
          if (!bVar5) {
            uVar2 = *(uint *)(uVar2 + 0x94);
          }
        }
        if (bVar5) {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = *(uint *)(param_1 + 0x14);
      }
      if ((code *)*DAT_300c73e0 == (code *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (*(code *)*DAT_300c73e0)(uVar2,0);
      }
      usrBreakpointSet(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),uVar2,2);
      if ((code *)*puVar1 != (code *)0x0) {
        (*(code *)*puVar1)(uVar4,0);
      }
    }
  }
  FUN_300c6b50(*(undefined4 *)(param_1 + 0x1c),8,param_1,0,0,0,0);
  taskCpuLock();
  FUN_300c6400(DAT_300c77dc,*(undefined4 *)(DAT_300c77dc + 4),param_1);
  taskCpuUnlock();
  return 0;
}

/* ----------------------------------------------------------------
 * vxdbgBpDelete @ 0x300C7164  (примерный размер ~404 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300c701c, __errno, intContext, taskCpuLock, taskCpuUnlock
 * Вызывают: FUN_300c777c
 * Константы: 0xFFFFFFFF, 0x300C7164
 * Данные: DAT_300c74b4, DAT_300c81fc, DAT_300c8200
 * ---------------------------------------------------------------- */
undefined4 vxdbgBpDelete(int param_1,int param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  iVar2 = intContext();
  if (iVar2 == 0) {
    taskCpuLock();
  }
  piVar4 = (int *)*DAT_300c74b4;
joined_r0x300c719c:
  do {
    while( true ) {
      do {
        piVar1 = piVar4;
        if (piVar1 == (int *)0x0) {
          iVar2 = intContext();
          if (iVar2 == 0) {
            taskCpuUnlock();
          }
          if (param_1 != 0) {
            return 0;
          }
          if (param_3 == (int *)0xffffffff) {
            return 0;
          }
          puVar3 = (undefined4 *)__errno();
          *puVar3 = DAT_300c8200;
          return 0xffffffff;
        }
        piVar4 = (int *)*piVar1;
      } while ((param_2 != 0) && (piVar1[7] != param_2));
      if (param_1 != 0) break;
      if (((param_3 == (int *)0xffffffff) || ((int *)piVar1[2] == param_3)) &&
         (FUN_300c701c(piVar1), param_3 != (int *)0xffffffff)) {
        iVar2 = intContext();
        if (iVar2 == 0) {
          taskCpuUnlock();
        }
        return 0;
      }
    }
    if (param_1 == 1) goto LAB_300c7220;
    if (param_1 != 2) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = DAT_300c81fc;
      return 0xffffffff;
    }
  } while (((int *)piVar1[3] < param_3) || (param_4 < (int *)piVar1[3]));
  goto LAB_300c7284;
LAB_300c7220:
  if (((param_4 == (int *)0x0) || ((int *)piVar1[3] == param_4)) &&
     ((*param_3 == 0 || ((piVar1[6] == param_3[1] && (piVar1[5] == *param_3)))))) {
LAB_300c7284:
    FUN_300c701c(piVar1);
  }
  goto joined_r0x300c719c;
}

/* ----------------------------------------------------------------
 * FUN_300c72f8 @ 0x300C72F8  (примерный размер ~336 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: taskCpuLock, taskCpuUnlock
 * Вызывают: FUN_300c7590, FUN_300c762c
 * Константы: 0x300C72F8
 * Данные: DAT_300c74ac, DAT_300c74b4
 * ---------------------------------------------------------------- */
int FUN_300c72f8(undefined4 *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  
  piVar1 = DAT_300c74ac;
  if (param_4 == 0) {
    param_4 = 1;
  }
  if (*DAT_300c74ac != 0) {
    taskCpuLock();
  }
  iVar3 = param_3;
  puVar5 = param_1;
  if (param_3 != 0) {
    do {
      if (param_4 == 1) {
        *(undefined1 *)param_2 = *(undefined1 *)puVar5;
      }
      else if (param_4 == 2) {
        *(undefined2 *)param_2 = *(undefined2 *)puVar5;
      }
      else if (param_4 == 4) {
        *param_2 = *puVar5;
      }
      else if (param_4 == 8) {
        uVar2 = puVar5[1];
        *param_2 = *puVar5;
        param_2[1] = uVar2;
      }
      puVar5 = (undefined4 *)((int)puVar5 + param_4);
      param_2 = (undefined4 *)((int)param_2 + param_4);
      iVar3 = iVar3 - param_4;
    } while (iVar3 != 0);
  }
  if (*piVar1 != 0) {
    if ((DAT_300c74b4[2] != 0) && (param_1 < (undefined4 *)(*(int *)(DAT_300c74b4[1] + 0xc) + 4))) {
      for (puVar5 = (undefined4 *)*DAT_300c74b4; puVar5 != (undefined4 *)0x0;
          puVar5 = (undefined4 *)*puVar5) {
        if (puVar5[10] != 0) {
          puVar4 = (undefined1 *)puVar5[3];
          if ((undefined1 *)((int)param_1 + param_3) < puVar4) break;
          if ((param_1 < puVar4 + 4) && (puVar4 < (undefined1 *)((int)param_1 + param_3))) {
            *(undefined4 *)((int)param_2 + (int)(puVar4 + (-(int)param_1 - param_3))) = puVar5[4];
          }
        }
      }
    }
    taskCpuUnlock();
  }
  return param_3;
}

/* ----------------------------------------------------------------
 * FUN_300c7448 @ 0x300C7448  (примерный размер ~328 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: taskCpuLock, taskCpuUnlock
 * Вызывают: FUN_300c7590
 * Константы: 0x300C7448
 * Данные: DAT_300c74ac, DAT_300c74b4, DAT_300c7614
 * ---------------------------------------------------------------- */
int FUN_300c7448(undefined4 *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  
  piVar1 = DAT_300c74ac;
  if (param_4 == 0) {
    param_4 = 1;
  }
  if (((*DAT_300c74ac != 0) && (taskCpuLock(), DAT_300c74b4[2] != 0)) &&
     (piVar3 = DAT_300c74b4, param_1 < (undefined4 *)(*(int *)(DAT_300c74b4[1] + 0xc) + 4))) {
    while (piVar3 = (int *)*piVar3, piVar3 != (int *)0x0) {
      if (piVar3[10] != 0) {
        puVar5 = (undefined1 *)piVar3[3];
        if ((undefined1 *)((int)param_1 + param_3) < puVar5) break;
        if ((param_1 < puVar5 + 4) && (puVar5 < (undefined1 *)((int)param_1 + param_3))) {
          puVar6 = (undefined4 *)((int)param_2 + ((int)puVar5 - (int)param_1));
          piVar3[4] = *puVar6;
          *puVar6 = DAT_300c7614;
        }
      }
    }
  }
  iVar2 = param_3;
  if (param_3 != 0) {
    do {
      if (param_4 == 1) {
        *(undefined1 *)param_2 = *(undefined1 *)param_1;
      }
      else if (param_4 == 2) {
        *(undefined2 *)param_2 = *(undefined2 *)param_1;
      }
      else if (param_4 == 4) {
        *param_2 = *param_1;
      }
      else if (param_4 == 8) {
        uVar4 = param_1[1];
        *param_2 = *param_1;
        param_2[1] = uVar4;
      }
      param_1 = (undefined4 *)((int)param_1 + param_4);
      param_2 = (undefined4 *)((int)param_2 + param_4);
      iVar2 = iVar2 - param_4;
    } while (iVar2 != 0);
  }
  if (*piVar1 != 0) {
    taskCpuUnlock();
  }
  return param_3;
}

/* ----------------------------------------------------------------
 * FUN_300c7590 @ 0x300C7590  (примерный размер ~156 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300c72f8, FUN_300c7448, free, malloc, memmove
 * Константы: 0x300C7590
 * Данные: DAT_300c82d4
 * ---------------------------------------------------------------- */
size_t FUN_300c7590(void *param_1,void *param_2,size_t param_3)

{
  void *__ptr;
  undefined4 uVar1;
  size_t sVar2;
  
  if (*DAT_300c82d4 == 0) {
    memmove(param_2,param_1,param_3);
    return param_3;
  }
  __ptr = malloc(param_3);
  if (__ptr == (void *)0x0) {
    return 0;
  }
  uVar1 = FUN_300c72f8(param_1,__ptr,param_3,0);
  sVar2 = FUN_300c7448(__ptr,param_2,uVar1,0);
  free(__ptr);
  return sVar2;
}

/* ----------------------------------------------------------------
 * FUN_300c762c @ 0x300C762C  (примерный размер ~172 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300c72f8, free, malloc, memcmp
 * Константы: 0x300C762C
 * Данные: DAT_300c82d4
 * ---------------------------------------------------------------- */
int FUN_300c762c(char *param_1,char *param_2,size_t param_3)

{
  void *__s1;
  int iVar1;
  
  if (*DAT_300c82d4 == 0) {
    if (param_3 == 1) {
      if (*param_1 == *param_2) {
        iVar1 = 0;
      }
      else {
        iVar1 = -1;
      }
    }
    else {
      iVar1 = memcmp(param_1,param_2,param_3);
    }
  }
  else {
    __s1 = malloc(param_3);
    if (__s1 == (void *)0x0) {
      return -1;
    }
    FUN_300c72f8(param_1,__s1,param_3,0);
    iVar1 = memcmp(__s1,param_2,param_3);
    free(__s1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * vxdbgBpFind @ 0x300C76D8  (примерный размер ~164 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 0
 * Вызывают: FUN_300c777c, FUN_300c78e4, FUN_300c7cbc, vxdbgTaskCont
 * Константы: 0x300C76D8
 * Данные: DAT_300c82d8
 * ---------------------------------------------------------------- */
int vxdbgBpFind(int param_1,int param_2,int *param_3,undefined4 param_4,int *param_5)

{
  bool bVar1;
  
  if (param_5 == (int *)0x0) {
    param_5 = DAT_300c82d8;
  }
  do {
    do {
      param_5 = (int *)*param_5;
      if (param_5 == (int *)0x0) {
        return 0;
      }
    } while ((param_5[3] != param_1) || ((param_2 != 0 && (param_5[7] != param_2))));
    bVar1 = param_3 == (int *)0x0;
    if ((!bVar1) &&
       ((((param_5[6] & 1U) == 0 || (bVar1 = param_5[5] == *param_3, !bVar1)) &&
        (((param_5[6] & 2U) == 0 || (bVar1 = param_5[5] == *(int *)(*param_3 + 0x94), !bVar1)))))) {
      bVar1 = param_5[5] == 0;
    }
  } while (!bVar1);
  return (int)param_5;
}

/* ----------------------------------------------------------------
 * FUN_300c777c @ 0x300C777C  (примерный размер ~360 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: vxdbgBpDelete, vxdbgBpFind
 * Вызывают: FUN_300c78e4
 * Константы: 0x300C777C, 0xFFFFFFEF
 * Данные: DAT_300c82dc, DAT_300c82e0
 * ---------------------------------------------------------------- */
int FUN_300c777c(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *param_2;
  iVar5 = 0;
  iVar1 = vxdbgBpFind(param_1,0,param_2,param_4,param_5);
  if (iVar1 != 0) {
    do {
      if (*(int *)(iVar1 + 0x24) == 0) {
        if (iVar5 == 0) {
          iVar5 = iVar1;
        }
        *(undefined4 *)(param_6 + 8) = *(undefined4 *)(iVar1 + 8);
        *(undefined4 *)(param_6 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
        uVar3 = *(uint *)(param_6 + 0x2c) | *(uint *)(iVar1 + 0x2c);
        *(uint *)(param_6 + 0x2c) = uVar3;
        *(ushort *)(param_6 + 0x20) = *(ushort *)(param_6 + 0x20) | *(ushort *)(iVar1 + 0x20);
        *(byte *)(param_6 + 0x22) = *(byte *)(param_6 + 0x22) | *(byte *)(iVar1 + 0x22);
        if ((*(uint *)(iVar1 + 0x2c) & 0x10) != 0) {
          iVar2 = iVar4;
          if (iVar4 == 0) {
            iVar2 = *DAT_300c82dc;
          }
          if (*(int *)(iVar2 + 0x94) == *DAT_300c82e0) {
            *(uint *)(param_6 + 0x2c) = uVar3 & 0xffffffef | 4;
          }
        }
        if ((*(byte *)(iVar1 + 0x22) & 1) == 1) {
          vxdbgBpDelete();
        }
      }
      else {
        *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + -1;
      }
      iVar1 = vxdbgBpFind(param_1,0,param_2,param_4,iVar1);
    } while (iVar1 != 0);
    if (iVar5 != 0) {
      *(undefined4 *)(iVar4 + 0x228) = param_1;
    }
  }
  return iVar5;
}

/* ----------------------------------------------------------------
 * FUN_300c78e4 @ 0x300C78E4  (примерный размер ~612 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_300c6b50, FUN_300c777c, memset, taskCpuUnlockNoResched, taskStop, vxdbgBpFind
 * Вызывают: FUN_300c7bac, FUN_300c7cbc
 * Константы: 0x300C78E4
 * Данные: DAT_300c82e8
 * ---------------------------------------------------------------- */
undefined4
FUN_300c78e4(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint param_5,
            int param_6)

{
  int iVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  char cVar5;
  byte in_Q;
  int local_60 [2];
  undefined1 auStack_58 [28];
  undefined4 local_3c;
  uint local_2c;
  
  iVar2 = *param_2;
  if (param_6 != 0) {
    param_6 = *(int *)(param_6 + 4);
  }
  memset(auStack_58,0,0x38);
  iVar1 = FUN_300c777c(param_1,param_2,param_3,param_4,param_6,auStack_58);
  if (iVar1 != 0) {
    if ((*(uint *)(iVar2 + 0x98) & 2) != 0) {
      local_2c = local_2c & 1;
    }
    if (((param_5 & 1) != 0) && ((local_2c & 1) != 0)) {
      for (iVar1 = vxdbgBpFind(param_1,0,param_2,param_4,*(undefined4 *)(iVar1 + 4)); iVar1 != 0;
          iVar1 = vxdbgBpFind(param_1,0,param_2,param_4,iVar1)) {
        if ((*(int *)(iVar1 + 0x24) == 0) && ((*(uint *)(iVar1 + 0x2c) & 1) != 0)) {
          (**(code **)(iVar1 + 0x30))(*(undefined4 *)(iVar1 + 0x34),param_3);
        }
      }
    }
    cVar5 = '\x01';
    cVar3 = '\0';
    if ((param_5 & 2) != 0) {
      cVar5 = '\x01';
      cVar3 = '\0';
      if ((local_2c & 2) != 0) {
        if ((local_2c & 0x10) == 0) {
          if ((local_2c & 4) == 0) {
            local_60[1] = 0;
            local_60[0] = 0;
          }
          else {
            local_60[1] = 1;
            local_60[0] = iVar2;
          }
        }
        else {
          local_60[1] = 2;
          local_60[0] = *(int *)(iVar2 + 0x94);
        }
        cVar5 = '\x01';
        cVar3 = '\0';
        FUN_300c6b50(local_3c,2,param_2,local_60,param_3,param_1,auStack_58);
      }
    }
    if (((param_5 & 0x14) != 0) && ((local_2c & 0x14) != 0)) {
      *(undefined4 *)(iVar2 + 0x224) = param_3;
      bVar4 = (local_2c & 0x10) == 0;
      if (bVar4) {
        bVar4 = (local_2c & 4) == 0;
        if (bVar4) {
          return 1;
        }
        taskCpuUnlockNoResched
                  (0,(uint)(byte)(bVar4 << 3 | cVar5 << 2 | cVar3 << 1 | in_Q) << 0x1b | 0x80);
        *(byte *)(iVar2 + 0x239) = *(byte *)(iVar2 + 0x239) | 1;
        taskStop(iVar2);
      }
      else {
        taskCpuUnlockNoResched
                  (0,(uint)(byte)(bVar4 << 3 | cVar5 << 2 | cVar3 << 1 | in_Q) << 0x1b | 0x80);
        *(byte *)(iVar2 + 0x239) = *(byte *)(iVar2 + 0x239) | 1;
        if ((code *)*DAT_300c82e8 != (code *)0x0) {
          (*(code *)*DAT_300c82e8)(*(undefined4 *)(iVar2 + 0x94));
        }
      }
      *(byte *)(iVar2 + 0x239) = *(byte *)(iVar2 + 0x239) & 0xfe;
    }
    return 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300c7b48 @ 0x300C7B48  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: taskCpuLock, taskCpuUnlock
 * Вызывают: FUN_300c7bac, FUN_300c7cbc
 * Константы: 0x300C7B48
 * ---------------------------------------------------------------- */
void FUN_300c7b48(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  
  if (param_3 == 2) {
    bVar1 = 2;
  }
  else {
    if (param_3 != 4) goto LAB_300c7b78;
    bVar1 = 4;
  }
  *(byte *)(param_1 + 0x239) = *(byte *)(param_1 + 0x239) | bVar1;
LAB_300c7b78:
  *(undefined4 *)(param_1 + 0x224) = param_2;
  taskCpuUnlock();
  taskCpuLock();
  if (param_3 == 2) {
    bVar1 = 0xfd;
  }
  else {
    if (param_3 != 4) {
      return;
    }
    bVar1 = 0xfb;
  }
  *(byte *)(param_1 + 0x239) = *(byte *)(param_1 + 0x239) & bVar1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300c7bac @ 0x300C7BAC  (примерный размер ~272 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_300c78e4, FUN_300c7b48, taskCpuLock, taskCpuUnlockNoResched, usrBreakpointSet, vxdbgBpAllDisable, wdbDbgGetNpc, wdbDbgTraceModeSet
 * Вызывают: FUN_300c809c
 * Константы: 0x300C7BAC, 0xFFFFFFFF
 * Данные: DAT_300c82d4, DAT_300c82dc, DAT_300c82ec
 * ---------------------------------------------------------------- */
undefined4 FUN_300c7bac(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  byte in_Q;
  byte bVar9;
  undefined2 local_20 [2];
  int *local_1c;
  int local_18 [2];
  
  local_20[0] = 0;
  local_1c = DAT_300c82d4;
  if (*DAT_300c82d4 == 0) {
    uVar1 = 0;
  }
  else {
    iVar4 = *DAT_300c82dc;
    vxdbgBpAllDisable(param_1);
    taskCpuLock();
    bVar9 = (in_Q & 1) != 0;
    local_18[1] = 1;
    local_18[0] = iVar4;
    iVar2 = FUN_300c78e4(*(undefined4 *)(param_3 + 0x3c),local_18,param_3,local_20,0xffffffff,0);
    cVar7 = iVar2 < 0;
    cVar8 = iVar2 == 0;
    cVar5 = '\x01';
    cVar6 = '\0';
    if (!(bool)cVar8) {
      FUN_300c7b48(iVar4,param_3,2);
    }
    *(byte *)(iVar4 + 0x238) = *(byte *)(iVar4 + 0x238) | 2;
    vxdbgBpAllDisable();
    piVar3 = (int *)wdbDbgGetNpc(param_3);
    local_1c[1] = (int)piVar3;
    local_1c[2] = *piVar3;
    usrBreakpointSet(piVar3,DAT_300c82ec,*(undefined4 *)(iVar4 + 0x94),2);
    iVar2 = wdbDbgTraceModeSet(param_3);
    local_1c[3] = iVar2;
    taskCpuUnlockNoResched
              (0,(uint)(byte)(cVar7 << 4 | cVar8 << 3 | cVar5 << 2 | cVar6 << 1 | bVar9) << 0x1b |
                 0x80);
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300c7cbc @ 0x300C7CBC  (примерный размер ~564 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 12
 * Вызывает: FUN_300c6554, FUN_300c6b50, FUN_300c78e4, FUN_300c7b48, taskCpuLock, taskCpuUnlockNoResched, taskStopForce, usrBreakpointSet, vxdbgBpFind, wdbDbgGetNpc, wdbDbgTraceModeClear, wdbDbgTraceModeSet
 * Вызывают: FUN_300c809c
 * Константы: 0x300C7CBC, 0xFFFFFFFF
 * Данные: DAT_300c82d4, DAT_300c82dc, DAT_300c82ec
 * ---------------------------------------------------------------- */
undefined4 FUN_300c7cbc(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte in_Q;
  byte bVar12;
  int local_1c [2];
  
  piVar1 = DAT_300c82d4;
  cVar9 = '\x01';
  cVar10 = '\0';
  if (*DAT_300c82d4 == 0) {
    return 0;
  }
  iVar6 = *DAT_300c82dc;
  local_1c[1] = 1;
  local_1c[0] = iVar6;
  usrBreakpointSet(DAT_300c82d4[1],DAT_300c82d4[2],*(undefined4 *)(iVar6 + 0x94),1);
  wdbDbgTraceModeClear(param_3,piVar1[3]);
  uVar2 = *(uint *)(param_3 + 0x3c);
  *(uint *)(iVar6 + 0x228) = uVar2;
  bVar12 = *(byte *)(iVar6 + 0x238);
  if ((bVar12 & 2) == 0) {
    cVar11 = (bVar12 & 4) == 0;
    cVar8 = false;
    if (!(bool)cVar11) {
      uVar7 = *(uint *)(iVar6 + 0x22c);
      cVar9 = uVar2 <= uVar7;
      cVar10 = SBORROW4(uVar7,uVar2);
      cVar8 = (int)(uVar7 - uVar2) < 0;
      cVar11 = uVar7 == uVar2;
      if (!(bool)cVar9 || (bool)cVar11) {
        uVar7 = *(uint *)(iVar6 + 0x230);
        cVar9 = uVar2 <= uVar7;
        cVar10 = SBORROW4(uVar7,uVar2);
        cVar8 = (int)(uVar7 - uVar2) < 0;
        cVar11 = uVar7 == uVar2;
        if ((bool)cVar9 && !(bool)cVar11) {
          iVar3 = vxdbgBpFind(uVar2,0,local_1c,0,0);
          if (iVar3 != 0) {
            taskCpuLock();
            bVar12 = (in_Q & 1) != 0;
            iVar3 = FUN_300c78e4(*(undefined4 *)(param_3 + 0x3c),local_1c,param_3,0,0xffffffff,iVar3
                                );
            cVar9 = iVar3 < 0;
            cVar10 = iVar3 == 0;
            cVar8 = '\x01';
            cVar11 = '\0';
            if (!(bool)cVar10) {
              FUN_300c7b48(iVar6,param_3,4);
            }
            taskCpuUnlockNoResched
                      (0,(uint)(byte)(cVar9 << 4 | cVar10 << 3 | cVar8 << 2 | cVar11 << 1 | bVar12)
                         << 0x1b | 0x80);
          }
          piVar4 = (int *)wdbDbgGetNpc(param_3);
          piVar1[1] = (int)piVar4;
          piVar1[2] = *piVar4;
          usrBreakpointSet(piVar4,DAT_300c82ec,*(undefined4 *)(iVar6 + 0x94),1);
          iVar6 = wdbDbgTraceModeSet(param_3);
          piVar1[3] = iVar6;
          return 1;
        }
      }
    }
    taskCpuLock();
    uVar2 = (uint)(byte)(cVar8 << 4 | cVar11 << 3 | cVar9 << 2 | cVar10 << 1 | in_Q) << 0x1b;
    bVar12 = (in_Q & 1) != 0;
    cVar11 = (uVar2 >> 0x1c & 1) != 0;
    cVar8 = (uVar2 >> 0x1d & 1) != 0;
    cVar10 = (uVar2 >> 0x1e & 1) != 0;
    cVar9 = (int)uVar2 < 0;
    *(int *)(iVar6 + 0x224) = param_3;
    FUN_300c78e4(*(undefined4 *)(param_3 + 0x3c),local_1c,param_3,0,1,0);
    uVar5 = FUN_300c6b50(*(undefined4 *)(iVar6 + 0x234),1,local_1c,0,param_3,
                         *(undefined4 *)(param_3 + 0x3c),0);
    *(byte *)(iVar6 + 0x238) = *(byte *)(iVar6 + 0x238) & 0xfa;
    *(byte *)(iVar6 + 0x239) = *(byte *)(iVar6 + 0x239) | 1;
    taskCpuUnlockNoResched
              (uVar5,(uint)(byte)(cVar9 << 4 | cVar10 << 3 | cVar8 << 2 | cVar11 << 1 | bVar12) <<
                     0x1b | 0x80);
    taskStopForce(iVar6);
  }
  else {
    *(byte *)(iVar6 + 0x238) = bVar12 & 0xfd;
    FUN_300c6554(iVar6,iVar6);
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300c7ef0 @ 0x300C7EF0  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300c809c
 * Константы: 0x300C7EF0
 * Данные: DAT_300c82dc, DAT_300c82f0, DAT_300c82f4, DAT_300c82f8, DAT_300c82fc
 * ---------------------------------------------------------------- */
undefined4 FUN_300c7ef0(void)

{
  if (((*DAT_300c82f0 < 1) && (*DAT_300c82f4 != 1)) &&
     ((*(int *)(*DAT_300c82dc + 0x7c) == 0 || (*DAT_300c82f8 == 0)))) {
    if (*(int *)(*DAT_300c82dc + 0xac) == 0) {
      return 0;
    }
    if (*DAT_300c82fc == 0) {
      return 0;
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300c7f5c @ 0x300C7F5C  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: usrBreakpointSet, wdbDbgGetNpc, wdbDbgTraceModeSet
 * Вызывают: FUN_300c809c
 * Константы: 0x300C7F5C
 * Данные: DAT_300c82d4, DAT_300c82dc, DAT_300c82ec
 * ---------------------------------------------------------------- */
void FUN_300c7f5c(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = DAT_300c82d4;
  iVar4 = *DAT_300c82dc;
  if ((*(byte *)(iVar4 + 0x238) & 7) != 0) {
    usrBreakpointSet(*(undefined4 *)(DAT_300c82d4 + 4),*(undefined4 *)(DAT_300c82d4 + 8),
                     *(undefined4 *)(iVar4 + 0x94),1);
  }
  puVar2 = (undefined4 *)wdbDbgGetNpc(param_1);
  *(undefined4 **)(iVar1 + 0x10) = puVar2;
  *(undefined4 *)(iVar1 + 0x2c) = *puVar2;
  usrBreakpointSet(puVar2,DAT_300c82ec,*(undefined4 *)(iVar4 + 0x94),1);
  uVar3 = wdbDbgTraceModeSet(param_1);
  *(undefined4 *)(iVar1 + 0x20) = uVar3;
  *(undefined4 *)(iVar1 + 0x1c) = 1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300c7fec @ 0x300C7FEC  (примерный размер ~176 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300c6554, intContext, usrBreakpointSet, wdbDbgTraceModeClear
 * Вызывают: FUN_300c809c
 * Константы: 0x300C7FEC
 * Данные: DAT_300c82d4, DAT_300c82dc, DAT_300c82ec
 * ---------------------------------------------------------------- */
void FUN_300c7fec(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_300c82d4;
  iVar3 = *DAT_300c82dc;
  wdbDbgTraceModeClear(param_1,*(undefined4 *)(DAT_300c82d4 + 0x20));
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  usrBreakpointSet(*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x2c),
                   *(undefined4 *)(iVar3 + 0x94),1);
  if ((*(byte *)(iVar3 + 0x238) & 7) != 0) {
    iVar2 = intContext();
    if (iVar2 == 0) {
      *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0xf8;
    }
    else {
      usrBreakpointSet(*(undefined4 *)(iVar1 + 4),DAT_300c82ec,*(undefined4 *)(iVar3 + 0x94),1);
    }
    if ((*(byte *)(iVar3 + 0x238) & 7) != 0) {
      return;
    }
  }
  FUN_300c6554(iVar3,iVar3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300c809c @ 0x300C809C  (примерный размер ~184 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_300c7bac, FUN_300c7cbc, FUN_300c7ef0, FUN_300c7f5c, FUN_300c7fec, vxdbgBpAllDisable
 * Константы: 0x300C809C
 * Данные: DAT_300c82d4, DAT_300c82dc
 * ---------------------------------------------------------------- */
undefined4
FUN_300c809c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_300c82d4;
  if (*DAT_300c82d4 == 0) {
    uVar2 = 0;
  }
  else {
    vxdbgBpAllDisable(DAT_300c82d4);
    if (piVar1[7] == 0) {
      iVar3 = FUN_300c7ef0(param_4);
      if (iVar3 == 0) {
        if ((*(byte *)(*DAT_300c82dc + 0x238) & 7) == 0) {
          FUN_300c7bac(param_1,param_3,param_4,param_5,param_6);
        }
        else {
          FUN_300c7cbc(param_1,param_3,param_4);
        }
      }
      else {
        FUN_300c7f5c(param_4);
      }
    }
    else {
      FUN_300c7fec();
    }
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300c8154 @ 0x300C8154  (примерный размер ~432 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 9
 * Вызывает: FUN_300c6470, FUN_300c6554, objVerify, taskRegsSet, usrBreakpointSet, vxdbgBpAllDisable, wdbDbgGetNpc, wdbDbgTraceModeClear, wdbDbgTraceModeSet
 * Константы: 0x300C8154
 * Данные: DAT_300c82d4, DAT_300c82e4, DAT_300c82ec, DAT_300c8300
 * ---------------------------------------------------------------- */
void FUN_300c8154(int param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  byte bVar6;
  
  piVar2 = DAT_300c82d4;
  if (*DAT_300c82d4 == 0) {
    return;
  }
  iVar3 = objVerify(param_1,*DAT_300c8300);
  iVar5 = DAT_300c82e4;
  if (iVar3 == 0) {
    if ((*(byte *)(param_1 + 0x239) & 7) != 0) {
      if (0 < *(int *)(param_1 + 0x6c)) {
        *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;
      }
      taskRegsSet(param_1,*(undefined4 *)(param_1 + 0x224));
      *(byte *)(param_1 + iVar5) = *(byte *)(param_1 + iVar5) & 0xfe;
    }
    if ((*(byte *)(param_1 + 0x238) & 7) != 0) {
      FUN_300c6470(0,*(undefined4 *)(param_1 + 0x94));
      usrBreakpointSet(piVar2[1],piVar2[2],*(undefined4 *)(param_1 + 0x94),1);
      wdbDbgTraceModeClear(param_1 + 0x1d0,piVar2[3]);
    }
    bVar1 = *(byte *)(param_1 + iVar5);
    if ((bVar1 & 2) == 0) {
      if ((bVar1 & 4) == 0) goto LAB_300c8254;
      *(undefined1 *)(param_1 + 0x238) = 4;
      bVar6 = 0xfb;
    }
    else {
      *(undefined1 *)(param_1 + 0x238) = 2;
      bVar6 = 0xfd;
    }
    *(byte *)(param_1 + iVar5) = bVar1 & bVar6;
  }
LAB_300c8254:
  if ((*(byte *)(param_2 + 0x238) & 7) == 0) {
    FUN_300c6554(param_1,param_2);
  }
  else {
    vxdbgBpAllDisable();
    FUN_300c6470(0,*(undefined4 *)(param_2 + 0x94));
    piVar4 = (int *)wdbDbgGetNpc(param_2 + 0x1d0);
    piVar2[1] = (int)piVar4;
    piVar2[2] = *piVar4;
    usrBreakpointSet(piVar4,DAT_300c82ec,*(undefined4 *)(param_2 + 0x94),1);
    iVar5 = wdbDbgTraceModeSet(param_2 + 0x1d0);
    piVar2[3] = iVar5;
  }
  return;
}

/* ----------------------------------------------------------------
 * vxdbgMemAccess @ 0x300C8304  (примерный размер ~496 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: __udiv32, errnoSet
 * Вызывают: vxdbgMemRead, vxdbgMemWrite
 * Константы: 0x300C8304
 * Данные: DAT_300c85f4, DAT_300c85f8
 * ---------------------------------------------------------------- */
uint vxdbgMemAccess(int param_1,undefined4 *param_2,undefined4 *param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  
  if (param_4 == 0) {
    param_4 = 0;
  }
  else {
    if ((param_5 == 0) &&
       (((((param_4 != 1 && (param_4 != 2)) && (param_4 != 4)) && (param_4 != 8)) ||
        ((iVar1 = __udiv32(param_2,param_4), param_2 != (undefined4 *)(param_4 * iVar1) ||
         (iVar1 = __udiv32(param_3,param_4), param_5 = param_4,
         param_3 != (undefined4 *)(param_4 * iVar1))))))) {
      param_5 = 8;
      do {
        iVar1 = __udiv32(param_4,param_5);
        if (((param_4 == param_5 * iVar1) &&
            (iVar1 = __udiv32(param_2,param_5), param_2 == (undefined4 *)(param_5 * iVar1))) &&
           (iVar1 = __udiv32(param_3,param_5), param_3 == (undefined4 *)(param_5 * iVar1))) break;
        param_5 = param_5 >> 1;
      } while (1 < param_5);
    }
    if ((((param_5 != 1) && (param_5 != 2)) && (param_5 != 4)) && (param_5 != 8)) {
      param_5 = 1;
    }
    iVar1 = __udiv32(param_2,param_5);
    if ((param_2 == (undefined4 *)(param_5 * iVar1)) &&
       (iVar1 = __udiv32(param_3,param_5), param_3 == (undefined4 *)(param_5 * iVar1))) {
      pcVar3 = *(code **)(DAT_300c85f8 + ((param_1 != 0) + 3) * 4);
      if (pcVar3 == (code *)0x0) {
        uVar4 = param_4;
        if (param_4 != 0) {
          do {
            if (param_5 == 1) {
              *(undefined1 *)param_3 = *(undefined1 *)param_2;
            }
            else if (param_5 == 2) {
              *(undefined2 *)param_3 = *(undefined2 *)param_2;
            }
            else if (param_5 == 4) {
              *param_3 = *param_2;
            }
            else if (param_5 == 8) {
              uVar2 = param_2[1];
              *param_3 = *param_2;
              param_3[1] = uVar2;
            }
            param_2 = (undefined4 *)((int)param_2 + param_5);
            param_3 = (undefined4 *)((int)param_3 + param_5);
            uVar4 = uVar4 - param_5;
          } while (uVar4 != 0);
        }
      }
      else {
        param_4 = (*pcVar3)(param_2,param_3,param_4,param_5);
      }
    }
    else {
      errnoSet(DAT_300c85f4);
      param_4 = 0;
    }
  }
  return param_4;
}

/* ----------------------------------------------------------------
 * vxdbgMemRead @ 0x300C84F4  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 1
 * Вызывает: vxdbgMemAccess
 * Вызывают: dsmInst, memoryDump, memoryModify, vxdbgBpAddrCheck
 * Константы: 0x300C84F4
 * ---------------------------------------------------------------- */
void vxdbgMemRead(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  vxdbgMemAccess(0,param_1,param_2,param_3,param_4);
  return;
}

/* ----------------------------------------------------------------
 * vxdbgMemWrite @ 0x300C851C  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: vxdbgMemAccess
 * Вызывают: memoryModify
 * Константы: 0x300C851C
 * ---------------------------------------------------------------- */
void vxdbgMemWrite(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  vxdbgMemAccess(1,param_1,param_2,param_3,param_4);
  return;
}

/* ----------------------------------------------------------------
 * vxdbgMemMove @ 0x300C8544  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: memmove
 * Константы: 0x300C8544
 * Данные: DAT_300c85f8
 * ---------------------------------------------------------------- */
size_t vxdbgMemMove(void *param_1,void *param_2,size_t param_3)

{
  if (param_3 == 0) {
    param_3 = 0;
  }
  else if (*(code **)(DAT_300c85f8 + 0x14) == (code *)0x0) {
    memmove(param_2,param_1,param_3);
  }
  else {
    param_3 = (**(code **)(DAT_300c85f8 + 0x14))(param_1,param_2,param_3);
  }
  return param_3;
}

/* ----------------------------------------------------------------
 * vxdbgMemScan @ 0x300C85A4  (примерный размер ~88 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: memcmp
 * Константы: 0x300C85A4
 * Данные: DAT_300c85f8
 * ---------------------------------------------------------------- */
int vxdbgMemScan(char *param_1,char *param_2,size_t param_3)

{
  int iVar1;
  
  if (*(code **)(DAT_300c85f8 + 0x18) == (code *)0x0) {
    if (param_3 == 1) {
      if (*param_1 == *param_2) {
        iVar1 = 0;
      }
      else {
        iVar1 = -1;
      }
    }
    else {
      iVar1 = memcmp(param_1,param_2,param_3);
    }
  }
  else {
    iVar1 = (**(code **)(DAT_300c85f8 + 0x18))();
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * vxdbgTaskLibInit @ 0x300C85FC  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskDeleteHookAdd
 * Вызывают: FUN_300c69b0
 * Константы: 0x300C85FC
 * Данные: DAT_300c8978
 * ---------------------------------------------------------------- */
void vxdbgTaskLibInit(void)

{
  taskDeleteHookAdd(DAT_300c8978);
  return;
}

/* ----------------------------------------------------------------
 * vxdbgTaskCont @ 0x300C8604  (примерный размер ~208 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 7
 * Вызывает: __errno, objVerify, taskCont, taskCpuLock, taskCpuUnlock, taskIsStopped, vxdbgBpFind
 * Вызывают: vxdbgCont, vxdbgTaskStep
 * Константы: 0xFFFFFFFF, 0x300C8604
 * Данные: DAT_300c897c, DAT_300c8980
 * ---------------------------------------------------------------- */
undefined4 vxdbgTaskCont(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  bool bVar4;
  int local_14 [2];
  
  iVar1 = objVerify(param_2,*DAT_300c897c);
  if ((iVar1 == -1) || (iVar1 = taskIsStopped(param_2), iVar1 == 0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_300c8980;
    uVar3 = 0xffffffff;
  }
  else {
    local_14[1] = 1;
    local_14[0] = param_2;
    taskCpuLock();
    iVar1 = vxdbgBpFind(*(undefined4 *)(param_2 + 0x20c),0,local_14,0,0);
    bVar4 = iVar1 == 0;
    if (bVar4) {
      iVar1 = vxdbgBpFind(*(undefined4 *)(param_2 + 0x228),0,local_14,0,0);
      bVar4 = iVar1 == 0;
    }
    if (!bVar4) {
      *(undefined1 *)(param_2 + 0x238) = 2;
    }
    taskCpuUnlock();
    iVar1 = taskCont(param_2);
    if (iVar1 == 0) {
      uVar3 = 0;
    }
    else {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300c8980;
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * vxdbgTaskStop @ 0x300C86D4  (примерный размер ~112 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: __errno, objVerify, taskIsStopped, taskStop
 * Вызывают: vxdbgStop
 * Константы: 0xFFFFFFFF, 0x300C86D4
 * Данные: DAT_300c897c, DAT_300c8980
 * ---------------------------------------------------------------- */
undefined4 vxdbgTaskStop(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = objVerify(param_2,*DAT_300c897c);
  if ((iVar1 != -1) && (iVar1 = taskIsStopped(param_2), iVar1 == 0)) {
    iVar1 = taskStop(param_2);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300c8980;
      return 0xffffffff;
    }
    return 0;
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = DAT_300c8980;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * vxdbgTaskStep @ 0x300C8744  (примерный размер ~488 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 7
 * Вызывает: __errno, objVerify, taskCont, taskIsStopped, vxdbgBpAdd, vxdbgTaskCont, wdbDbgSysCallCheck
 * Вызывают: vxdbgStep
 * Константы: 0xFFFFFFFF, 0x300C8744
 * Данные: DAT_300c897c, DAT_300c8980, DAT_300c8984
 * ---------------------------------------------------------------- */
undefined4 vxdbgTaskStep(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_24 [4];
  int local_20 [2];
  
  iVar1 = objVerify(param_2,*DAT_300c897c);
  if (((iVar1 == -1) || (iVar1 = taskIsStopped(param_2), iVar1 == 0)) ||
     ((*(uint *)(param_2 + 0x98) & 2) != 0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_300c8980;
    return 0xffffffff;
  }
  *(undefined4 *)(param_2 + 0x234) = param_1;
  iVar1 = *(int *)(param_2 + 0x20c);
  if ((param_3 == 0) && (param_4 == 0)) {
    if ((code *)*DAT_300c8984 == (code *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (*(code *)*DAT_300c8984)(*(undefined4 *)(param_2 + 0x94),0);
    }
    iVar3 = wdbDbgSysCallCheck(param_2 + 0x1d0);
    if (iVar3 != 0) {
      local_20[1] = 1;
      local_20[0] = param_2;
      iVar1 = vxdbgBpAdd(param_1,local_20,0,6,0,0,iVar1 + 4,1,0,auStack_24);
      if (iVar1 == -1) {
        if ((code *)*DAT_300c8984 != (code *)0x0) {
          (*(code *)*DAT_300c8984)(uVar4,0);
        }
        return 0xffffffff;
      }
      if ((code *)*DAT_300c8984 != (code *)0x0) {
        (*(code *)*DAT_300c8984)(uVar4,0);
      }
      iVar1 = vxdbgTaskCont(param_1,param_2);
      if (iVar1 != -1) {
        return 0;
      }
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_300c8980;
      return 0xffffffff;
    }
    *(undefined1 *)(param_2 + 0x238) = 1;
    if ((code *)*DAT_300c8984 != (code *)0x0) {
      (*(code *)*DAT_300c8984)(uVar4,0);
    }
  }
  else {
    *(undefined1 *)(param_2 + 0x238) = 4;
    *(int *)(param_2 + 0x22c) = param_3;
    *(int *)(param_2 + 0x230) = param_4;
  }
  iVar1 = taskCont(param_2);
  if (iVar1 == 0) {
    return 0;
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = DAT_300c8980;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300c892c @ 0x300C892C  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C892C
 * Данные: DAT_300c8988
 * ---------------------------------------------------------------- */
void FUN_300c892c(undefined4 param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 *local_c;
  undefined4 local_8;
  
  local_18 = 1;
  local_14 = 1;
  local_10 = 0;
  local_8 = 0;
  local_c = &local_1c;
  local_1c = param_1;
  (**(code **)(DAT_300c8988 + 8))(1,0,local_c,0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300c898c @ 0x300C898C  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: wdbDbgAddrCheck
 * Вызывают: vxdbgBpAddrCheck
 * Константы: 0x300C898C
 * ---------------------------------------------------------------- */
undefined4 FUN_300c898c(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 & 3) == 0) {
    iVar2 = wdbDbgAddrCheck(param_1);
    if (iVar2 == -1) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * vxdbgBpAddrCheck @ 0x300C89B0  (примерный размер ~988 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300c898c, __errno, vxMemProbe, vxdbgMemRead
 * Вызывают: vxdbgBpAdd
 * Константы: 0xFFFFFFFF, 0x300C89B0
 * Данные: DAT_300c8e30, DAT_300c8e34, DAT_300c8e38, DAT_300c8e3c
 * ---------------------------------------------------------------- */
undefined4 vxdbgBpAddrCheck(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint local_2c;
  undefined1 auStack_28 [4];
  
  uVar5 = 0;
  local_2c = 0;
  if (param_1 != 0) {
    if ((code *)*DAT_300c8e30 == (code *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (*(code *)*DAT_300c8e30)(param_1,0);
    }
  }
  puVar1 = (undefined4 *)__errno();
  iVar3 = DAT_300c8e34;
  uVar7 = *puVar1;
  if (*(int *)(DAT_300c8e34 + 0x18) == 0) {
LAB_300c8b04:
    piVar2 = (int *)__errno();
    if (*piVar2 == DAT_300c8e38) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = uVar7;
      iVar3 = FUN_300c898c(param_2);
      if ((iVar3 == 0) || (iVar3 = vxMemProbe(param_2,0,4,auStack_28), iVar3 != 0)) {
        if ((param_1 != 0) && ((code *)*DAT_300c8e30 != (code *)0x0)) {
          (*(code *)*DAT_300c8e30)(uVar5,0);
        }
        puVar1 = (undefined4 *)__errno();
        *puVar1 = DAT_300c8e3c;
        return 0xffffffff;
      }
      goto LAB_300c8d40;
    }
  }
  else {
    if (param_1 == 0) {
      uVar8 = 0;
    }
    else {
      uVar8 = *(undefined4 *)(param_1 + 0x44);
    }
    if (*(code **)(DAT_300c8e34 + 0x20) == (code *)0x0) {
      iVar6 = -1;
    }
    else {
      iVar6 = (**(code **)(DAT_300c8e34 + 0x20))();
    }
    iVar6 = (**(code **)(iVar3 + 0x18))(uVar8,param_2 & ~(iVar6 - 1U),&local_2c);
    if (iVar6 == -1) goto LAB_300c8b04;
    if ((local_2c & 0x3f) != 7) {
      if (*(int *)(iVar3 + 0x14) != 0) {
        if (param_1 == 0) {
          uVar8 = 0;
        }
        else {
          uVar8 = *(undefined4 *)(param_1 + 0x44);
        }
        if (*(code **)(iVar3 + 0x20) == (code *)0x0) {
          iVar6 = -1;
        }
        else {
          iVar6 = (**(code **)(iVar3 + 0x20))();
        }
        if (*(code **)(iVar3 + 0x20) == (code *)0x0) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (**(code **)(iVar3 + 0x20))();
        }
        iVar6 = (**(code **)(iVar3 + 0x14))(uVar8,param_2 & ~(iVar6 - 1U),uVar4,0x3f,7);
        if (iVar6 != -1) goto LAB_300c8b8c;
      }
      goto LAB_300c8b04;
    }
  }
LAB_300c8b8c:
  puVar1 = (undefined4 *)__errno();
  *puVar1 = uVar7;
  iVar6 = FUN_300c898c(param_2);
  if (((iVar6 == 0) || (iVar6 = vxMemProbe(param_2,0,4,auStack_28), iVar6 != 0)) ||
     (iVar6 = vxMemProbe(param_2,1,4,auStack_28), iVar6 != 0)) {
    if (((local_2c & 0x3f) != 7) && (*(int *)(iVar3 + 0x14) != 0)) {
      if (param_1 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(undefined4 *)(param_1 + 0x44);
      }
      if (*(code **)(iVar3 + 0x20) == (code *)0x0) {
        iVar6 = -1;
      }
      else {
        iVar6 = (**(code **)(iVar3 + 0x20))();
      }
      if (*(code **)(iVar3 + 0x20) == (code *)0x0) {
        uVar8 = 0xffffffff;
      }
      else {
        uVar8 = (**(code **)(iVar3 + 0x20))();
      }
      (**(code **)(iVar3 + 0x14))(uVar7,param_2 & ~(iVar6 - 1U),uVar8,0x3f,local_2c);
    }
    if ((param_1 != 0) && ((code *)*DAT_300c8e30 != (code *)0x0)) {
      (*(code *)*DAT_300c8e30)(uVar5,0);
    }
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300c8e3c;
    return 0xffffffff;
  }
  if (((local_2c & 0x3f) != 7) && (*(int *)(iVar3 + 0x14) != 0)) {
    if (*(code **)(iVar3 + 0x20) == (code *)0x0) {
      iVar6 = -1;
    }
    else {
      iVar6 = (**(code **)(iVar3 + 0x20))();
    }
    if (*(code **)(iVar3 + 0x20) == (code *)0x0) {
      uVar7 = 0xffffffff;
    }
    else {
      uVar7 = (**(code **)(iVar3 + 0x20))();
    }
    (**(code **)(iVar3 + 0x14))(0,param_2 & ~(iVar6 - 1U),uVar7,0x3f,local_2c);
  }
LAB_300c8d40:
  vxdbgMemRead(param_2,param_3,4,0);
  if ((param_1 != 0) && ((code *)*DAT_300c8e30 != (code *)0x0)) {
    (*(code *)*DAT_300c8e30)(uVar5,0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * wdbDbgTrap @ 0x300C8D8C  (примерный размер ~188 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300a9968
 * Константы: 0x300C8D8C
 * Данные: DAT_300c8e40, DAT_300c8e44
 * ---------------------------------------------------------------- */
void wdbDbgTrap(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  
  if (((code *)*DAT_300c8e40 != (code *)0x0) &&
     (iVar1 = (*(code *)*DAT_300c8e40)(0,param_1,param_3,param_2,param_4,param_5), iVar1 != 0)) {
    return;
  }
  if ((code *)*DAT_300c8e44 != (code *)0x0) {
    (*(code *)*DAT_300c8e44)(0,param_1,param_3,param_2,param_4,param_5);
  }
  return;
}

/* ----------------------------------------------------------------
 * vxdbgBpMsgQCreate @ 0x300C8E48  (примерный размер ~260 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: atomic32Clear, free, malloc, strdup
 * Вызывают: dbgDynPrintfCommonRtn
 * Константы: 0x300C8E48
 * ---------------------------------------------------------------- */
undefined4 * vxdbgBpMsgQCreate(int param_1,int param_2,char *param_3)

{
  undefined4 *__ptr;
  char *__ptr_00;
  void *__ptr_01;
  undefined4 *puVar1;
  void *__ptr_02;
  
  __ptr_01 = (void *)0x0;
  __ptr_02 = (void *)0x0;
  if ((((param_1 != 0) && (param_2 != 0)) && (param_3 != (char *)0x0)) &&
     (__ptr = (undefined4 *)malloc(0x2c), __ptr != (undefined4 *)0x0)) {
    __ptr_00 = strdup(param_3);
    __ptr[6] = __ptr_00;
    if (((__ptr_00 != (char *)0x0) && (__ptr_01 = malloc(param_1 << 4), __ptr_01 != (void *)0x0)) &&
       (__ptr_02 = malloc(param_2 * param_1), __ptr_02 != (void *)0x0)) {
      *__ptr = 0;
      __ptr[1] = 0;
      atomic32Clear(__ptr + 2);
      __ptr[3] = __ptr_01;
      __ptr[4] = param_1;
      __ptr[5] = param_2;
      __ptr[7] = 0;
      __ptr[8] = 0;
      __ptr[10] = 0;
      atomic32Clear(__ptr + 9);
      puVar1 = (undefined4 *)(__ptr[3] + -0x10);
      do {
        puVar1 = puVar1 + 4;
        *puVar1 = __ptr_02;
        __ptr_02 = (void *)((int)__ptr_02 + param_2);
        param_1 = param_1 + -1;
      } while (param_1 != 0);
      return __ptr;
    }
    free(__ptr_00);
    free(__ptr);
    free(__ptr_01);
    free(__ptr_02);
  }
  return (undefined4 *)0x0;
}

/* ----------------------------------------------------------------
 * vxdbgBpMsgGet @ 0x300C8F4C  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: __urem32, atomic32Get, atomic32Inc
 * Вызывают: FUN_30115d68
 * Константы: 0x300C8F4C
 * ---------------------------------------------------------------- */
undefined4 vxdbgBpMsgGet(int param_1)

{
  int iVar1;
  
  iVar1 = atomic32Get(param_1 + 0x24);
  if (*(int *)(param_1 + 0x10) == iVar1) {
    atomic32Inc(param_1 + 8);
    return 0;
  }
  iVar1 = __urem32(*(int *)(param_1 + 4) + 1);
  return *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar1 * 0x10);
}

/* ----------------------------------------------------------------
 * vxdbgBpMsgQHdlrIsRunning @ 0x300C8F90  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskIdSelf
 * Вызывают: FUN_30115d68
 * Константы: 0x300C8F90
 * ---------------------------------------------------------------- */
undefined4 vxdbgBpMsgQHdlrIsRunning(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x1c) != 0) && (iVar1 = taskIdSelf(), iVar1 == *(int *)(param_1 + 0x20)))
  {
    return 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * vxdbgBpMsgPost @ 0x300C8FC4  (примерный размер ~164 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: __urem32, atomic32Inc, jobExcAdd
 * Вызывают: FUN_30115d68
 * Константы: 0x300C8FC4
 * Данные: DAT_300c9260
 * ---------------------------------------------------------------- */
void vxdbgBpMsgPost(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __urem32(*(int *)(param_1 + 4) + 1,*(undefined4 *)(param_1 + 0x10));
  iVar2 = *(int *)(param_1 + 0xc) + iVar1 * 0x10;
  *(undefined4 *)(iVar2 + 4) = param_3;
  *(undefined4 *)(iVar2 + 8) = param_4;
  *(undefined4 *)(iVar2 + 0xc) = param_2;
  *(int *)(param_1 + 4) = iVar1;
  iVar1 = atomic32Inc(param_1 + 0x24);
  if ((iVar1 == 0) || (*(int *)(param_1 + 0x28) != 0)) {
    iVar1 = jobExcAdd(DAT_300c9260,param_1,2,3,4,5,6);
    *(uint *)(param_1 + 0x28) = (uint)(iVar1 == -1);
  }
  return;
}

/* ----------------------------------------------------------------
 * vxdbgBpMsgDrop @ 0x300C9068  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30115d68
 * Константы: 0x300C9068
 * ---------------------------------------------------------------- */
void vxdbgBpMsgDrop(void)

{
  return;
}

/* ----------------------------------------------------------------
 * FUN_300c906c @ 0x300C906C  (примерный размер ~528 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 11
 * Вызывает: __urem32, atomic32Dec, atomic32Get, atomic32Set, fdprintf, ioTaskStdGet, iosFdTableLock, iosFdTableUnlock, printf, taskIdSelf, taskName
 * Константы: 0x300C906C, 0xFFFFFFFF
 * Данные: DAT_300c9264, DAT_300c9268, DAT_300c926c, DAT_300c9270, DAT_300c9274, DAT_300c9278
 * ---------------------------------------------------------------- */
void FUN_300c906c(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  iVar1 = taskIdSelf();
  param_1[8] = iVar1;
  param_1[7] = 1;
  do {
    iVar1 = atomic32Set(param_1 + 2,0);
    if (iVar1 != 0) {
      printf(DAT_300c9264,param_1[6],iVar1);
    }
    iVar1 = atomic32Get(param_1 + 9);
    uVar7 = 1;
    if (iVar1 == 0) {
      param_1[7] = 0;
      return;
    }
    iVar2 = __urem32(*param_1 + 1,param_1[4]);
    iVar9 = param_1[3] + iVar2 * 0x10;
    iVar1 = *(int *)(iVar9 + 4);
    uVar3 = uVar7;
    if ((*(uint *)(iVar9 + 0xc) & 4) == 0) {
      iVar9 = iVar1;
      if (iVar1 == 0) {
        iVar9 = *DAT_300c9268;
      }
      if (*(int *)(iVar9 + 0x94) == *DAT_300c926c) {
        uVar3 = ioTaskStdGet(iVar1,1);
        if (uVar3 == 0xffffffff) {
          uVar3 = 1;
        }
      }
      else {
        iVar9 = *(int *)(iVar1 + 0x94);
        iosFdTableLock(iVar9);
        iVar10 = *(int *)(*(int *)(iVar9 + 0xcc) + 4);
        iosFdTableUnlock(iVar9);
        if (((iVar10 != 0) && (iVar10 != -1)) && (iVar10 != -2)) {
          iosFdTableLock(*DAT_300c926c);
          iVar9 = *DAT_300c926c;
          if (*(uint *)(iVar9 + 0xd0) != 0) {
            piVar6 = (int *)(*(int *)(iVar9 + 0xcc) + -4);
            uVar8 = 0;
            do {
              uVar3 = uVar8;
              piVar6 = piVar6 + 1;
              if (*piVar6 == iVar10) break;
              uVar8 = uVar3 + 1;
              uVar3 = uVar7;
            } while (uVar8 < *(uint *)(iVar9 + 0xd0));
          }
          iosFdTableUnlock(iVar9);
        }
      }
    }
    uVar7 = *(uint *)(param_1[3] + iVar2 * 0x10 + 0xc);
    if ((uVar7 & 1) == 0) {
      if ((uVar7 & 2) == 0) {
        taskName(iVar1);
        uVar4 = *(undefined4 *)(param_1[3] + iVar2 * 0x10 + 8);
        iVar9 = param_1[6];
        uVar5 = DAT_300c9278;
      }
      else {
        uVar4 = taskName(iVar1);
        uVar5 = DAT_300c9274;
        iVar9 = iVar1;
        iVar1 = *(int *)(param_1[3] + iVar2 * 0x10);
      }
      fdprintf(uVar3,uVar5,iVar9,uVar4,iVar1);
    }
    else {
      fdprintf(uVar3,DAT_300c9270,*(undefined4 *)(param_1[3] + iVar2 * 0x10));
    }
    *param_1 = iVar2;
    atomic32Dec(param_1 + 9);
  } while( true );
}

/* ----------------------------------------------------------------
 * clockLibInit @ 0x300DF97C  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: bzero, sysClkRateGet
 * Вызывают: clock_settime, usrKernelExtraInit
 * Константы: 0xFFFFFFFF, 0x300DF97C
 * Данные: DAT_300e0788, DAT_300e078c, DAT_300e0790
 * ---------------------------------------------------------------- */
undefined4 clockLibInit(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = DAT_300e0788;
  if (*DAT_300e0788 == 0) {
    iVar4 = sysClkRateGet();
    if (iVar4 < 1) {
      uVar3 = 0xffffffff;
    }
    else {
      *piVar1 = 1;
      puVar2 = DAT_300e078c;
      bzero(DAT_300e078c,0x10);
      uVar3 = DAT_300e0790[1];
      *puVar2 = *DAT_300e0790;
      puVar2[1] = uVar3;
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * clock_getres @ 0x300DFA04  (примерный размер ~224 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: __div32, __errno, objVerify, sysClkRateGet
 * Константы: 0x300DFA04
 * Данные: DAT_300e0794, DAT_300e0798, DAT_300e079c, DAT_300e07a0
 * ---------------------------------------------------------------- */
int clock_getres(clockid_t __clock_id,timespec *__res)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  
  if (__clock_id == 2) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    return -1;
  }
  if ((uint)__clock_id < 3) {
LAB_300dfab8:
    if (__res != (timespec *)0x0) {
      __res->tv_sec = 0;
      uVar3 = sysClkRateGet();
      lVar4 = __div32(DAT_300e07a0,uVar3);
      __res->tv_nsec = lVar4;
    }
    return 0;
  }
  iVar2 = objVerify(__clock_id,*DAT_300e0794);
  if (iVar2 == 0) {
    if (*DAT_300e0798 == 0) {
      iVar2 = *DAT_300e079c;
    }
    else {
      iVar2 = *(int *)(*DAT_300e0798 + 0x94);
    }
    if ((*DAT_300e079c != iVar2) && (*(int *)(__clock_id + 0x174) != 0)) goto LAB_300dfab8;
  }
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 0x16;
  return -1;
}

/* ----------------------------------------------------------------
 * clock_setres @ 0x300DFAE4  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300DFAE4
 * ---------------------------------------------------------------- */
undefined4 clock_setres(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * clock_gettime @ 0x300DFAEC  (примерный размер ~632 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 6
 * Вызывает: __errno, __udiv32, __udiv64, __urem64, objVerify, sysClkRateGet
 * Вызывают: clock_nanosleep, os_get_time, time
 * Константы: 0x300DFAEC
 * Данные: DAT_300e078c, DAT_300e0790, DAT_300e0794, DAT_300e0798, DAT_300e079c, DAT_300e07a0, DAT_300e07a4
 * ---------------------------------------------------------------- */
int clock_gettime(clockid_t __clock_id,timespec *__tp)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  __time_t _Var10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  byte in_Q;
  undefined8 uVar14;
  
  if (__tp == (timespec *)0x0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0xe;
    return -1;
  }
  if (__clock_id == 0) {
    uVar6 = *DAT_300e078c;
    uVar7 = DAT_300e078c[1];
    uVar8 = *DAT_300e0790 - uVar6;
    uVar9 = DAT_300e0790[1] - (uVar7 + (*DAT_300e0790 < uVar6));
    uVar12 = DAT_300e078c[2];
    uVar11 = DAT_300e078c[3];
  }
  else {
    if (__clock_id == 1) {
      uVar6 = (uint)(byte)((__clock_id + -1 < 0) << 4 | (__clock_id == 1) << 3 |
                           (__clock_id != 0) << 2 | SBORROW4(__clock_id,1) << 1 | in_Q) << 0x1b;
      uVar7 = uVar6 | 0x80;
      uVar8 = *DAT_300e0790;
      uVar9 = DAT_300e0790[1];
    }
    else {
      if ((uint)__clock_id < 3) {
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 0x16;
        return -1;
      }
      uVar14 = objVerify(__clock_id,*DAT_300e0794);
      uVar7 = (uint)((ulonglong)uVar14 >> 0x20);
      if ((int)uVar14 != 0) {
LAB_300dfc24:
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 0x16;
        return -1;
      }
      if (*DAT_300e0798 == 0) {
        iVar3 = *DAT_300e079c;
      }
      else {
        iVar3 = *(int *)(*DAT_300e0798 + 0x94);
      }
      if ((*DAT_300e079c == iVar3) ||
         (puVar13 = *(uint **)(__clock_id + 0x174), puVar13 == (uint *)0x0)) goto LAB_300dfc24;
      uVar8 = *puVar13;
      uVar9 = puVar13[1];
      uVar6 = 0;
    }
    uVar12 = 0;
    uVar11 = 0;
  }
  uVar2 = sysClkRateGet(uVar6,uVar7);
  iVar3 = __udiv64(uVar8,uVar9,uVar2,0);
  iVar4 = __urem64(uVar8,uVar9,uVar2,0);
  iVar5 = __udiv32(DAT_300e07a0,uVar2);
  iVar3 = iVar3 + uVar12;
  __tp->tv_sec = iVar3;
  iVar4 = iVar4 * iVar5 + uVar11;
  __tp->tv_nsec = iVar4;
  if (iVar4 < DAT_300e07a0) {
    if (-1 < iVar4) {
      return 0;
    }
    _Var10 = iVar3 + -1;
    iVar3 = DAT_300e07a0;
  }
  else {
    _Var10 = iVar3 + 1;
    iVar3 = DAT_300e07a4;
  }
  __tp->tv_sec = _Var10;
  __tp->tv_nsec = iVar4 + iVar3;
  return 0;
}

/* ----------------------------------------------------------------
 * clock_gettime_wd @ 0x300DFD64  (примерный размер ~444 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 6
 * Вызывает: __errno, __udiv32, __udiv64, __urem64, objVerify, sysClkRateGet
 * Константы: 0xFFFFFFFF, 0x300DFD64
 * Данные: DAT_300e078c, DAT_300e0790, DAT_300e0794, DAT_300e07a0, DAT_300e07a4
 * ---------------------------------------------------------------- */
undefined4 clock_gettime_wd(int param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int local_40;
  uint local_3c;
  
  if (param_2 == (int *)0x0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0xe;
    return 0xffffffff;
  }
  if (param_1 == 0) {
    uVar5 = *DAT_300e0790 - *DAT_300e078c;
    uVar7 = DAT_300e078c[2];
    local_3c = DAT_300e078c[3];
    uVar6 = DAT_300e0790[1] - (DAT_300e078c[1] + (uint)(*DAT_300e0790 < *DAT_300e078c));
  }
  else {
    if (param_1 == 1) {
      uVar5 = *DAT_300e0790;
      uVar6 = DAT_300e0790[1];
    }
    else {
      if (param_1 < 3) {
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 0x16;
        return 0xffffffff;
      }
      iVar3 = objVerify(param_1,*DAT_300e0794);
      if ((iVar3 != 0) || (puVar8 = *(uint **)(param_1 + 0x174), puVar8 == (uint *)0x0)) {
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 0x16;
        return 0xffffffff;
      }
      uVar5 = *puVar8;
      uVar6 = puVar8[1];
    }
    uVar7 = 0;
    local_3c = 0;
  }
  uVar2 = sysClkRateGet();
  local_40 = __udiv64(uVar5,uVar6,uVar2,0);
  iVar3 = __urem64(uVar5,uVar6,uVar2,0);
  iVar4 = __udiv32(DAT_300e07a0,uVar2);
  local_40 = local_40 + uVar7;
  *param_2 = local_40;
  iVar3 = iVar3 * iVar4 + local_3c;
  param_2[1] = iVar3;
  if (iVar3 < DAT_300e07a0) {
    if (-1 < iVar3) {
      return 0;
    }
    local_40 = local_40 + -1;
    iVar4 = DAT_300e07a0;
  }
  else {
    local_40 = local_40 + 1;
    iVar4 = DAT_300e07a4;
  }
  *param_2 = local_40;
  param_2[1] = iVar3 + iVar4;
  return 0;
}

/* ----------------------------------------------------------------
 * clock_settime @ 0x300DFF20  (примерный размер ~596 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 7
 * Вызывает: __errno, __mul64, __udiv32, __udiv64, __urem64, clockLibInit, sysClkRateGet
 * Константы: 0x300DFF20, 0xFFFFFFFE
 * Данные: DAT_300e078c, DAT_300e0790, DAT_300e0798, DAT_300e079c, DAT_300e07a0
 * ---------------------------------------------------------------- */
int clock_settime(clockid_t __clock_id,timespec *__tp)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  longlong *plVar6;
  byte in_Q;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  
  if ((__tp == (timespec *)0x0) || (DAT_300e07a0 <= (uint)__tp->tv_nsec)) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    return -1;
  }
  clockLibInit();
  puVar1 = DAT_300e078c;
  if (__clock_id == 0) {
    uVar5 = DAT_300e0790[1];
    *DAT_300e078c = *DAT_300e0790;
    puVar1[1] = uVar5;
    puVar1[2] = __tp->tv_sec;
    puVar1[3] = __tp->tv_nsec;
LAB_300e0168:
    iVar4 = 0;
  }
  else {
    if (2U >= (uint)__clock_id) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = 0x16;
      return -1;
    }
    uVar2 = (uint)(byte)((__clock_id + -3 < 0) << 4 | (__clock_id == 3) << 3 |
                         (2U < (uint)__clock_id) << 2 | SBORROW4(__clock_id,3) << 1 | in_Q) << 0x1b;
    iVar4 = *DAT_300e0798;
    if (iVar4 == __clock_id) {
      if (iVar4 == 0) {
        iVar4 = *DAT_300e079c;
      }
      else {
        iVar4 = *(int *)(iVar4 + 0x94);
      }
      if ((*DAT_300e079c != iVar4) &&
         (plVar6 = *(longlong **)(__clock_id + 0x174), plVar6 != (longlong *)0x0)) {
        uVar5 = sysClkRateGet(uVar2,uVar2 | 0x80);
        uVar3 = __udiv32(DAT_300e07a0,uVar5);
        iVar4 = __tp->tv_nsec;
        lVar7 = __urem64(iVar4,iVar4 >> 0x1f,uVar3,0);
        lVar8 = __mul64(__tp->tv_sec,0,uVar5,0);
        lVar9 = __udiv64(iVar4,iVar4 >> 0x1f,uVar3,0);
        *plVar6 = lVar8 + lVar9 + (ulonglong)CONCAT14(0xfffffffe < (lVar7 != 0),(lVar7 != 0) + 1);
        goto LAB_300e0168;
      }
    }
    puVar1 = (undefined4 *)__errno(uVar2);
    *puVar1 = 0x16;
    iVar4 = -1;
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * clock_nanosleep @ 0x300E0174  (примерный размер ~1592 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 9
 * Вызывает: __errno, __mul64, __udiv32, __udiv64, __urem64, clock_gettime, sysClkRateGet, taskCpuUnlock, taskDelay
 * Константы: 0xFFFFFFFE, 0x300E0174
 * Данные: DAT_300e0798, DAT_300e07a0, DAT_300e07a8
 * ---------------------------------------------------------------- */
int clock_nanosleep(clockid_t __clock_id,int __flags,timespec *__req,timespec *__rem)

{
  uint5 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  bool bVar10;
  longlong lVar11;
  longlong lVar12;
  int local_78;
  undefined4 local_6c;
  timespec local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  timespec tStack_38;
  
  if ((uint)__clock_id < 2) {
    if ((__req == (timespec *)0x0) || (DAT_300e07a0 <= (uint)__req->tv_nsec)) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 0x16;
      local_78 = -1;
    }
    else if ((__req->tv_sec == 0) && (__req->tv_nsec == 0)) {
      local_78 = 0;
    }
    else {
      uVar3 = sysClkRateGet();
      uVar4 = __udiv32(DAT_300e07a0,uVar3);
      local_60._0_4_ = __req->tv_nsec;
      local_60._4_4_ = (int)(uint)local_60 >> 0x1f;
      local_58._0_4_ = (uint)local_60;
      local_58._4_4_ = local_60._4_4_;
      lVar11 = __urem64((uint)local_60,local_60._4_4_,uVar4,0);
      local_60._0_4_ = (lVar11 != 0) + 1;
      local_60._4_4_ = (uint)(0xfffffffe < (lVar11 != 0));
      lVar11 = __mul64(__req->tv_sec,0,uVar3,0);
      lVar12 = __udiv64((uint)local_58,local_58._4_4_,uVar4,0);
      local_60 = lVar11 + lVar12 + CONCAT44(local_60._4_4_,(uint)local_60);
      local_58 = local_60;
      if ((code *)*DAT_300e07a8 != (code *)0x0) {
        (*(code *)*DAT_300e07a8)(0,&local_6c);
      }
      if ((__flags & 1U) == 0) {
        local_78 = clock_gettime(__clock_id,&local_68);
        local_50 = CONCAT44(local_50._4_4_,(int)local_50);
        if (local_78 == 0) {
          local_78 = taskDelay((uint)local_60);
          local_50 = CONCAT44(local_50._4_4_,(int)local_50);
          if ((local_78 != 0) &&
             (local_50 = CONCAT44(local_50._4_4_,(int)local_50), __rem != (timespec *)0x0)) {
            clock_gettime(__clock_id,&tStack_38);
            uVar3 = sysClkRateGet();
            uVar4 = __udiv32(DAT_300e07a0,uVar3);
            lVar9 = local_68.tv_nsec;
            iVar6 = local_68.tv_nsec >> 0x1f;
            local_50._0_4_ = local_68.tv_nsec;
            local_50._4_4_ = iVar6;
            lVar11 = __urem64(local_68.tv_nsec,iVar6,uVar4,0);
            local_58._0_4_ = (lVar11 != 0) + 1;
            local_58._4_4_ = (uint)(0xfffffffe < (lVar11 != 0));
            local_50._4_4_ = 0;
            local_50._0_4_ = uVar3;
            lVar11 = __mul64(local_68.tv_sec,0,uVar3,0);
            local_50._4_4_ = 0;
            local_50._0_4_ = uVar4;
            lVar12 = __udiv64(lVar9,iVar6,uVar4,0);
            local_58 = lVar11 + lVar12 + CONCAT44(local_58._4_4_,(uint)local_58);
            uVar3 = sysClkRateGet();
            iVar5 = __udiv32(DAT_300e07a0,uVar3);
            iVar6 = local_68.tv_nsec >> 0x1f;
            local_50._4_4_ = 0;
            local_48 = local_68.tv_nsec;
            local_50._0_4_ = iVar5;
            local_44 = iVar6;
            lVar11 = __urem64(local_68.tv_nsec,iVar6,iVar5,0);
            uVar8 = (uint)(lVar11 != 0);
            local_50._0_4_ = uVar8 + 1;
            local_50._4_4_ = (uint)(0xfffffffe < uVar8);
            uVar1 = CONCAT14(0xfffffffe < uVar8,(int)local_50);
            local_44 = 0;
            local_48 = uVar3;
            local_50 = __mul64(local_68.tv_sec,0,uVar3,0);
            local_44 = 0;
            local_40 = local_68.tv_nsec;
            local_48 = iVar5;
            local_3c = iVar6;
            lVar11 = __udiv64(local_68.tv_nsec,iVar6,iVar5,0);
            lVar11 = lVar11 + local_50 + (ulonglong)uVar1;
            uVar7 = (uint)lVar11;
            iVar6 = (int)((ulonglong)lVar11 >> 0x20);
            uVar8 = iVar6 - (local_58._4_4_ + (uVar7 < (uint)local_58));
            bVar10 = local_60._4_4_ <= uVar8;
            if (uVar8 == local_60._4_4_) {
              bVar10 = (uint)local_60 <= uVar7 - (uint)local_58;
            }
            if (bVar10) {
              lVar9 = 0;
              __rem->tv_sec = 0;
            }
            else {
              uVar3 = sysClkRateGet();
              local_48 = (uint)local_60 - (uVar7 - (uint)local_58);
              local_44 = local_60._4_4_ -
                         ((iVar6 - (local_58._4_4_ + (uVar7 < (uint)local_58))) +
                         (uint)((uint)local_60 < uVar7 - (uint)local_58));
              local_50._4_4_ = 0;
              local_50._0_4_ = uVar3;
              local_50 = __udiv64(local_48,local_44,uVar3,0);
              __rem->tv_sec = (__time_t)local_50;
              bVar10 = (uint)local_60 < uVar7 - (uint)local_58;
              local_60._0_4_ = (uint)local_60 - (uVar7 - (uint)local_58);
              local_60._4_4_ =
                   local_60._4_4_ -
                   ((iVar6 - (local_58._4_4_ + (uVar7 < (uint)local_58))) + (uint)bVar10);
              local_58._4_4_ = 0;
              local_58._0_4_ = uVar3;
              local_60 = __urem64((uint)local_60,local_60._4_4_,uVar3,0);
              local_58 = local_60;
              iVar6 = __udiv32(DAT_300e07a0,uVar3,(int)local_60,(int)((ulonglong)local_60 >> 0x20));
              lVar9 = (uint)local_58 * iVar6;
            }
            __rem->tv_nsec = lVar9;
          }
        }
      }
      else {
        *(int *)(*DAT_300e0798 + 0x7c) = *(int *)(*DAT_300e0798 + 0x7c) + 1;
        local_78 = clock_gettime(__clock_id,&local_68);
        if (local_78 == 0) {
          uVar3 = sysClkRateGet();
          uVar4 = __udiv32(DAT_300e07a0,uVar3);
          iVar6 = local_68.tv_nsec >> 0x1f;
          local_50._4_4_ = 0;
          local_50._0_4_ = uVar4;
          lVar11 = __urem64(local_68.tv_nsec,iVar6,uVar4,0);
          local_58._0_4_ = (lVar11 != 0) + 1;
          local_58._4_4_ = (uint)(0xfffffffe < (lVar11 != 0));
          local_50._4_4_ = 0;
          local_50._0_4_ = uVar3;
          lVar11 = __mul64(local_68.tv_sec,0,uVar3,0);
          local_50._4_4_ = 0;
          local_48 = local_68.tv_nsec;
          local_50._0_4_ = uVar4;
          local_44 = iVar6;
          lVar12 = __udiv64(local_68.tv_nsec,iVar6,uVar4,0);
          local_58 = lVar11 + lVar12 + CONCAT44(local_58._4_4_,(uint)local_58);
          uVar8 = (uint)((ulonglong)local_58 >> 0x20);
          bVar10 = local_60._4_4_ <= uVar8;
          if (uVar8 == local_60._4_4_) {
            bVar10 = (uint)local_60 <= (uint)local_58;
          }
          if (!bVar10) {
            local_78 = taskDelay((uint)local_60 - (uint)local_58,uVar8);
          }
        }
        taskCpuUnlock();
        local_50 = CONCAT44(local_50._4_4_,(int)local_50);
      }
      if ((code *)*DAT_300e07a8 != (code *)0x0) {
        (*(code *)*DAT_300e07a8)(local_6c,0);
      }
    }
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x23;
    local_78 = -1;
  }
  return local_78;
}

/* ----------------------------------------------------------------
 * edrSystemDebugModeInit @ 0x300E1598  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300e1550
 * Вызывают: usrRoot
 * Константы: 0x300E1598
 * Данные: DAT_300e162c, DAT_300e1630
 * ---------------------------------------------------------------- */
undefined4 edrSystemDebugModeInit(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_300e1550();
  *DAT_300e162c = uVar1;
  *DAT_300e1630 = 1;
  return 0;
}

/* ----------------------------------------------------------------
 * edrSystemDebugModeGet @ 0x300E15BC  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: edrFlagsGet
 * Константы: 0x300E15BC
 * Данные: DAT_300e162c, DAT_300e1630
 * ---------------------------------------------------------------- */
undefined4 edrSystemDebugModeGet(void)

{
  if (*DAT_300e1630 != 0) {
    return *DAT_300e162c;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * edrSystemDebugModeSet @ 0x300E15E0  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300E15E0
 * Данные: DAT_300e162c, DAT_300e1630
 * ---------------------------------------------------------------- */
void edrSystemDebugModeSet(undefined4 param_1)

{
  *DAT_300e162c = param_1;
  *DAT_300e1630 = 1;
  return;
}

/* ----------------------------------------------------------------
 * edrFlagsGet @ 0x300E15F8  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 1
 * Вызывает: edrSystemDebugModeGet
 * Вызывают: edrInitFatalPolicyHandler, edrInterruptFatalPolicyHandler, edrIsDebugMode, edrKernelFatalPolicyHandler
 * Константы: 0x300E15F8
 * ---------------------------------------------------------------- */
bool edrFlagsGet(void)

{
  int iVar1;
  
  iVar1 = edrSystemDebugModeGet();
  return iVar1 != 0;
}

/* ----------------------------------------------------------------
 * edrIsDebugMode @ 0x300E1618  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: edrFlagsGet
 * Вызывают: usrBanner
 * Константы: 0x300E1618
 * ---------------------------------------------------------------- */
uint edrIsDebugMode(void)

{
  uint uVar1;
  
  uVar1 = edrFlagsGet();
  return uVar1 & 1;
}

/* ----------------------------------------------------------------
 * envLibInit @ 0x300E1634  (примерный размер ~168 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: calloc, semMInitialize, taskCreateHookAdd, taskDeleteHookAdd
 * Вызывают: usrRoot
 * Константы: 0xFFFFFFFF, 0x300E1634
 * Данные: DAT_300e1fcc, DAT_300e1fd0, DAT_300e1fd4, DAT_300e1fd8, DAT_300e1fdc, DAT_300e1fe0, DAT_300e1fe4, DAT_300e1fe8
 * ---------------------------------------------------------------- */
undefined4 envLibInit(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  pvVar1 = calloc(0x32,4);
  *DAT_300e1fcc = pvVar1;
  puVar4 = DAT_300e1fd0;
  if (pvVar1 == (void *)0x0) {
    return 0xffffffff;
  }
  *DAT_300e1fd0 = 0;
  puVar4[1] = 0x32;
  if (param_1 != 0) {
    iVar2 = taskCreateHookAdd(DAT_300e1fd4);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    iVar2 = taskDeleteHookAdd(DAT_300e1fd8);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
  }
  *DAT_300e1fdc = DAT_300e1fe0;
  iVar2 = semMInitialize(DAT_300e1fe4,0xd,param_3,param_4,puVar4);
  *DAT_300e1fe8 = iVar2;
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300e16dc @ 0x300E16DC  (примерный размер ~56 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 1
 * Вызывает: free
 * Вызывают: FUN_300e1714, FUN_300e18e4, envPrivateDestroy
 * Константы: 0x300E16DC
 * ---------------------------------------------------------------- */
void FUN_300e16dc(void *param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (0 < param_2) {
    puVar1 = (undefined4 *)((int)param_1 + -4);
    do {
      puVar1 = puVar1 + 1;
      free((void *)*puVar1);
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300e1714 @ 0x300E1714  (примерный размер ~200 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 5
 * Вызывает: FUN_300e16dc, calloc, malloc, strcpy, strlen
 * Вызывают: FUN_300e17dc, envPrivateCreate
 * Константы: 0xFFFFFFFF, 0x300E1714
 * ---------------------------------------------------------------- */
undefined4 FUN_300e1714(int param_1,size_t param_2,int param_3,int param_4)

{
  void *pvVar1;
  size_t sVar2;
  char *__dest;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *__s;
  
  pvVar1 = calloc(param_2,4);
  if (pvVar1 == (void *)0x0) {
    return 0xffffffff;
  }
  *(size_t *)(param_4 + 0x110) = param_2;
  *(undefined4 *)(param_4 + 0x114) = 0;
  *(void **)(param_4 + 0x10c) = pvVar1;
  if (0 < param_3) {
    puVar3 = (undefined4 *)(param_1 + -4);
    puVar4 = (undefined4 *)((int)pvVar1 + -4);
    do {
      puVar3 = puVar3 + 1;
      __s = (char *)*puVar3;
      sVar2 = strlen(__s);
      __dest = (char *)malloc(sVar2 + 1);
      if (__dest == (char *)0x0) {
        FUN_300e16dc(pvVar1,*(undefined4 *)(param_4 + 0x114));
        return 0xffffffff;
      }
      strcpy(__dest,__s);
      puVar4 = puVar4 + 1;
      *puVar4 = __dest;
      param_3 = param_3 + -1;
      *(int *)(param_4 + 0x114) = *(int *)(param_4 + 0x114) + 1;
    } while (param_3 != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300e17dc @ 0x300E17DC  (примерный размер ~264 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300e1714, semMGiveScalable, semMTakeScalable, taskOptionsSet, taskTcb
 * Константы: 0x300E17DC, 0xFFFFFFFF
 * Данные: DAT_300e1fcc, DAT_300e1fd0, DAT_300e1fe8, DAT_300e1fec, DAT_300e1ff0, DAT_300e1ff4
 * ---------------------------------------------------------------- */
void FUN_300e17dc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = DAT_300e1fec;
  if ((*(uint *)(param_1 + 0x98) & 0x80) == 0) {
    *(undefined4 *)(param_1 + 0x10c) = 0;
  }
  else {
    iVar2 = semMTakeScalable(*DAT_300e1fe8,0xffffffff,DAT_300e1fec);
    if (iVar2 != -1) {
      iVar2 = taskTcb(0);
      iVar3 = *(int *)(iVar2 + 0x10c);
      if (iVar3 == 0) {
        iVar3 = *DAT_300e1fcc;
        uVar4 = DAT_300e1fd0[1];
        uVar5 = *DAT_300e1fd0;
      }
      else {
        uVar4 = *(undefined4 *)(iVar2 + 0x110);
        uVar5 = *(undefined4 *)(iVar2 + 0x114);
      }
      iVar2 = FUN_300e1714(iVar3,uVar4,uVar5,param_1);
      if (iVar2 == -1) {
        if ((code *)*DAT_300e1ff0 != (code *)0x0) {
          (*(code *)*DAT_300e1ff0)(DAT_300e1ff4,0,0,0,0,0,0);
        }
        semMGiveScalable(*DAT_300e1fe8,uVar1);
        taskOptionsSet(param_1,0x80,0);
      }
      else {
        semMGiveScalable(*DAT_300e1fe8,uVar1);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300e18e4 @ 0x300E18E4  (примерный размер ~88 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300e16dc, semMGiveScalable, semMTakeScalable
 * Константы: 0x300E18E4, 0xFFFFFFFF
 * Данные: DAT_300e1fe8, DAT_300e1fec
 * ---------------------------------------------------------------- */
void FUN_300e18e4(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_300e1fec;
  puVar1 = DAT_300e1fe8;
  iVar3 = semMTakeScalable(*DAT_300e1fe8,0xffffffff,DAT_300e1fec);
  if (iVar3 == -1) {
    return;
  }
  if (((*(uint *)(param_1 + 0x98) & 0x80) != 0) && (*(int *)(param_1 + 0x10c) != 0)) {
    FUN_300e16dc(*(int *)(param_1 + 0x10c),*(undefined4 *)(param_1 + 0x114));
  }
  semMGiveScalable(*puVar1,uVar2);
  return;
}

/* ----------------------------------------------------------------
 * envPrivateCreate @ 0x300E193C  (примерный размер ~432 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_300e1714, calloc, semMGiveScalable, semMTakeScalable, taskOptionsSet, taskTcb
 * Константы: 0xFFFFFFFF, 0x300E193C
 * Данные: DAT_300e1fcc, DAT_300e1fd0, DAT_300e1fe8, DAT_300e1fec
 * ---------------------------------------------------------------- */
undefined4 envPrivateCreate(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  
  iVar3 = taskTcb();
  uVar2 = DAT_300e1fec;
  puVar1 = DAT_300e1fe8;
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  if (param_2 == -1) {
    pvVar4 = calloc(0x32,4);
    if (pvVar4 == (void *)0x0) {
      return 0xffffffff;
    }
    iVar5 = semMTakeScalable(*DAT_300e1fe8,0xffffffff,DAT_300e1fec);
    if (iVar5 == -1) {
      return 0xffffffff;
    }
    *(undefined4 *)(iVar3 + 0x110) = 0x32;
    *(undefined4 *)(iVar3 + 0x114) = 0;
    *(void **)(iVar3 + 0x10c) = pvVar4;
  }
  else if (param_2 == 0) {
    iVar5 = semMTakeScalable(*DAT_300e1fe8,0xffffffff,DAT_300e1fec);
    if (iVar5 == -1) {
      return 0xffffffff;
    }
    iVar3 = FUN_300e1714(*DAT_300e1fcc,DAT_300e1fd0[1],*DAT_300e1fd0,iVar3,DAT_300e1fd0);
    if (iVar3 == -1) {
      semMGiveScalable(*puVar1,uVar2);
      return 0xffffffff;
    }
  }
  else {
    iVar5 = semMTakeScalable(*DAT_300e1fe8,0xffffffff,DAT_300e1fec);
    if (iVar5 == -1) {
      return 0xffffffff;
    }
    iVar5 = taskTcb(param_2);
    if (iVar5 == 0 || *(int *)(iVar5 + 0x10c) == 0) {
      semMGiveScalable(*puVar1,uVar2);
      return 0xffffffff;
    }
    iVar3 = FUN_300e1714(*(int *)(iVar5 + 0x10c),*(undefined4 *)(iVar5 + 0x110),
                         *(undefined4 *)(iVar5 + 0x114),iVar3);
    if (iVar3 == -1) {
      semMGiveScalable(*puVar1,uVar2);
      return 0xffffffff;
    }
  }
  taskOptionsSet(param_1,0x80,0x80);
  semMGiveScalable(*DAT_300e1fe8,DAT_300e1fec);
  return 0;
}

/* ----------------------------------------------------------------
 * envPrivateDestroy @ 0x300E1AEC  (примерный размер ~132 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300e16dc, semMGiveScalable, semMTakeScalable, taskOptionsSet, taskTcb
 * Константы: 0xFFFFFFFF, 0x300E1AEC
 * Данные: DAT_300e1fe8, DAT_300e1fec
 * ---------------------------------------------------------------- */
undefined4 envPrivateDestroy(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = taskTcb();
  uVar2 = DAT_300e1fec;
  puVar1 = DAT_300e1fe8;
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  iVar4 = semMTakeScalable(*DAT_300e1fe8,0xffffffff,DAT_300e1fec);
  if (iVar4 == -1) {
    return 0xffffffff;
  }
  FUN_300e16dc(*(undefined4 *)(iVar3 + 0x10c),*(undefined4 *)(iVar3 + 0x114));
  *(undefined4 *)(iVar3 + 0x10c) = 0;
  semMGiveScalable(*puVar1,uVar2);
  taskOptionsSet(param_1,0x80,0);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300e1b70 @ 0x300E1B70  (примерный размер ~160 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: strncmp, taskTcb
 * Вызывают: getenv, putenv
 * Константы: 0x300E1B70
 * Данные: DAT_300e1fcc, DAT_300e1fd0
 * ---------------------------------------------------------------- */
undefined4 * FUN_300e1b70(char *param_1,size_t param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char *__s2;
  
  iVar2 = taskTcb(0);
  puVar4 = *(undefined4 **)(iVar2 + 0x10c);
  if (puVar4 == (undefined4 *)0x0) {
    iVar2 = *DAT_300e1fd0;
    puVar4 = (undefined4 *)*DAT_300e1fcc;
  }
  else {
    iVar2 = *(int *)(iVar2 + 0x114);
  }
  if (0 < iVar2) {
    do {
      __s2 = (char *)*puVar4;
      iVar3 = strncmp(param_1,__s2,param_2);
      if ((iVar3 == 0) &&
         ((((cVar1 = __s2[param_2], cVar1 == ' ' || (cVar1 == '\t')) || (cVar1 == '=')) ||
          (cVar1 == '\0')))) {
        return puVar4;
      }
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return (undefined4 *)0x0;
}

/* ----------------------------------------------------------------
 * envShow @ 0x300E1ED8  (примерный размер ~156 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: printf, puts, semMGiveScalable, semMTakeScalable, taskTcb
 * Константы: 0x300E1ED8, 0xFFFFFFFF
 * Данные: DAT_300e1fcc, DAT_300e1fd0, DAT_300e1fe8, DAT_300e1fec, DAT_300e1ff8, DAT_300e1ffc, DAT_300e2000
 * ---------------------------------------------------------------- */
void envShow(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar3 = taskTcb();
  uVar2 = DAT_300e1fec;
  puVar1 = DAT_300e1fe8;
  iVar4 = semMTakeScalable(*DAT_300e1fe8,0xffffffff,DAT_300e1fec);
  if (iVar4 == -1) {
    return;
  }
  if (*(int *)(iVar3 + 0x10c) == 0) {
    puts(DAT_300e1ff8);
    iVar3 = *DAT_300e1fd0;
    puVar5 = (undefined4 *)*DAT_300e1fcc;
  }
  else {
    puts(DAT_300e1ffc);
    puVar5 = *(undefined4 **)(iVar3 + 0x10c);
    iVar3 = *(int *)(iVar3 + 0x114);
  }
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      printf(DAT_300e2000,iVar4,*puVar5);
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar4 < iVar3);
  }
  semMGiveScalable(*puVar1,uVar2);
  return;
}

/* ----------------------------------------------------------------
 * envGet @ 0x300E1F74  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: semMGiveScalable, semMTakeScalable, taskTcb
 * Константы: 0x300E1F74, 0xFFFFFFFF
 * Данные: DAT_300e1fcc, DAT_300e1fe8, DAT_300e1fec
 * ---------------------------------------------------------------- */
int envGet(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = taskTcb();
  uVar2 = DAT_300e1fec;
  puVar1 = DAT_300e1fe8;
  iVar4 = semMTakeScalable(*DAT_300e1fe8,0xffffffff,DAT_300e1fec);
  if (iVar4 != -1) {
    iVar3 = *(int *)(iVar3 + 0x10c);
    if (iVar3 == 0) {
      iVar3 = *DAT_300e1fcc;
    }
    semMGiveScalable(*puVar1,uVar2);
    return iVar3;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * errnoGet @ 0x300E204C  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 51 | Вызывает: 0
 * Вызывают: FUN_300ac39c, FUN_300d266c, FUN_300d2d68, FUN_300d3f80, FUN_300d439c, FUN_300d5d2c, FUN_300dada0, FUN_300f6ea4, FUN_300f81ac, FUN_300fb05c
 *           ...
 * Константы: 0x300E204C
 * Данные: DAT_300e2108, DAT_300e210c, DAT_300e2110
 * ---------------------------------------------------------------- */
undefined4 errnoGet(void)

{
  if ((*DAT_300e2108 < 1) && (*DAT_300e210c != 0)) {
    return *(undefined4 *)(*DAT_300e210c + 0xd0);
  }
  return *DAT_300e2110;
}

/* ----------------------------------------------------------------
 * errnoOfTaskGet @ 0x300E2080  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 1
 * Вызывает: taskTcb
 * Вызывают: BSP_TaskErrnoGet, taskInfoGet, taskInitialize
 * Константы: 0x300E2080, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 errnoOfTaskGet(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0xd0);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * errnoSet @ 0x300E209C  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 259 | Вызывает: 0
 * Вызывают: BSP_ErrnoSet, FUN_300a5fe4, FUN_300a62bc, FUN_300a6470, FUN_300a6550, FUN_300a660c, FUN_300a66cc, FUN_300a6a38, FUN_300a6db8, FUN_300ac018
 *           ...
 * Константы: 0x300E209C
 * Данные: DAT_300e2108, DAT_300e210c, DAT_300e2110, DAT_300e2114
 * ---------------------------------------------------------------- */
undefined4 errnoSet(undefined4 param_1)

{
  if ((*DAT_300e2108 < 1) && (*DAT_300e210c != 0)) {
    if (*DAT_300e2114 != 0) {
      *(undefined4 *)(*DAT_300e210c + 0xd0) = param_1;
    }
  }
  else {
    *DAT_300e2110 = param_1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * errnoOfTaskSet @ 0x300E20E0  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: taskTcb
 * Вызывают: BSP_TaskErrnoSet, coprocTaskCreateHook
 * Константы: 0x300E20E0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 errnoOfTaskSet(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(iVar1 + 0xd0) = param_2;
  return 0;
}

/* ----------------------------------------------------------------
 * excInit @ 0x300E211C  (примерный размер ~348 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 5
 * Вызывает: ffsMsb, printf, semBInit, taskActivate, taskInitExcStk
 * Вызывают: usrIosExtraInit
 * Константы: 0xFFFFFFFF, 0x300E211C
 * Данные: DAT_300e2518, DAT_300e251c, DAT_300e2520, DAT_300e2524, DAT_300e2528, DAT_300e252c, DAT_300e2530, DAT_300e2534
 * ---------------------------------------------------------------- */
undefined4 excInit(uint param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  puVar1 = DAT_300e251c;
  if ((param_1 == 0) || ((param_1 & param_1 - 1) != 0)) {
    printf(DAT_300e2518,param_1);
    uVar2 = 0xffffffff;
  }
  else {
    DAT_300e251c[2] = 0;
    *puVar1 = 0;
    uVar6 = 0x10000;
    if (param_1 < 0x10001) {
      uVar6 = param_1;
    }
    iVar3 = ffsMsb(uVar6);
    puVar1[1] = (short)DAT_300e2520 + (short)(1 << (iVar3 + 0xffU & 0xff));
    iVar4 = semBInit(DAT_300e2524,1,0);
    iVar3 = DAT_300e2528;
    if (iVar4 == 0) {
      iVar5 = taskInitExcStk(DAT_300e2528,DAT_300e2538,0,3,DAT_300e252c + 0x2000,0x2000,
                             DAT_300e2530 + 0x1000,0x1000,DAT_300e2534,0,0,0,0,0,0,0,0,0,0);
      iVar4 = iVar3;
      if (iVar5 != 0) {
        iVar4 = 0;
      }
      if (((iVar4 == 0) || (iVar4 = taskActivate(iVar3), iVar4 != 0)) || (iVar3 == -1)) {
        uVar2 = 0xffffffff;
      }
      else {
        *DAT_300e2540 = DAT_300e253c;
        uVar2 = DAT_300e2544;
        *DAT_300e2548 = DAT_300e2544;
        *DAT_300e254c = uVar2;
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
 * excJobAdd @ 0x300E23D8  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 1
 * Вызывает: jobExcAdd
 * Вызывают: WDT_APPIntHandler, kill, sigPendKill, sigqueue, systemError
 * Константы: 0x300E23D8
 * ---------------------------------------------------------------- */
void excJobAdd(void)

{
  jobExcAdd();
  return;
}

/* ----------------------------------------------------------------
 * FUN_300e2404 @ 0x300E2404  (примерный размер ~260 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: edrErrorInjectStub, semBTake, sprintf
 * Константы: 0x300E2404, 0xFFFFFFFF
 * Данные: DAT_300e251c, DAT_300e2524, DAT_300e2550, DAT_300e2554, DAT_300e255c, DAT_300e2560, DAT_300e2564
 * ---------------------------------------------------------------- */
void FUN_300e2404(void)

{
  ushort *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  char acStack_88 [100];
  
  piVar3 = DAT_300e2554;
  iVar2 = DAT_300e2550;
  puVar1 = DAT_300e251c;
  do {
    semBTake(DAT_300e2524,0xffffffff);
    while (*puVar1 != puVar1[2]) {
      puVar4 = (undefined4 *)(iVar2 + (uint)*puVar1 * 0x1c);
      *puVar1 = *puVar1 + 1 & puVar1[1];
      (*(code *)*puVar4)(puVar4[1],puVar4[2],puVar4[3],puVar4[4],puVar4[5],puVar4[6]);
      iVar5 = *piVar3;
      if (piVar3[1] != iVar5) {
        sprintf(acStack_88,DAT_300e255c,iVar5 - piVar3[1]);
        edrErrorInjectStub(0x12,DAT_300e2560,DAT_300e2564,0,0,0,acStack_88);
        piVar3[1] = iVar5;
      }
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * excHookAdd @ 0x300E2508  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: exchInit
 * Константы: 0x300E2508
 * Данные: DAT_300e2568
 * ---------------------------------------------------------------- */
void excHookAdd(undefined4 param_1)

{
  *DAT_300e2568 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * intContext @ 0x300E2BA8  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 32 | Вызывает: 0
 * Вызывают: FUN_300ace48, FUN_300c6b50, FUN_300c7fec, FUN_300e2e10, FUN_300ecf38, FUN_30122acc, dosFsDevDelete, excExcHandle, jobAdd, msgQCreate
 *           ...
 * Константы: 0x300E2BA8
 * Данные: DAT_300e2d24
 * ---------------------------------------------------------------- */
bool intContext(void)

{
  return 0 < *DAT_300e2d24;
}

/* ----------------------------------------------------------------
 * intRestrict @ 0x300E2BC0  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: __errno
 * Константы: 0x300E2BC0, 0xFFFFFFFF
 * Данные: DAT_300e2d24, DAT_300e2d28
 * ---------------------------------------------------------------- */
undefined4 intRestrict(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (*DAT_300e2d24 < 1) {
    uVar2 = 0;
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_300e2d28;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * intCount @ 0x300E2BF0  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300E2BF0
 * Данные: DAT_300e2d24
 * ---------------------------------------------------------------- */
undefined4 intCount(void)

{
  return *DAT_300e2d24;
}

/* ----------------------------------------------------------------
 * intConnect @ 0x300E2BFC  (примерный размер ~148 байт)
 * Модуль: kernel | Вызывают: 11 | Вызывает: 1
 * Вызывает: intArchConnect
 * Вызывают: BSP_GPIO_Init, BSP_INT_Connect, BSP_PMU_BoardInit, BSP_WDT_Enable, FUN_30009f84, SD_MMC_Host_Init, WDT_APPInit, os_interrupt_setup, os_interrupt_teardown, sysHwInit2
 *           ...
 * Константы: 0x300E2BFC
 * Данные: DAT_300e2d2c, DAT_300e2d30
 * ---------------------------------------------------------------- */
undefined4 intConnect(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((code *)*DAT_300e2d2c == (code *)0x0) ||
     (iVar1 = (*(code *)*DAT_300e2d2c)(param_1,param_2,param_3), iVar1 != 0)) {
    if (((code *)*DAT_300e2d30 == (code *)0x0) ||
       (iVar1 = (*(code *)*DAT_300e2d30)(param_1,param_2,param_3), iVar1 != 0)) {
      uVar2 = intArchConnect(param_1,param_2,param_3);
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
 * intDisconnect @ 0x300E2C90  (примерный размер ~172 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: intArchDisconnect
 * Вызывают: BSP_INT_DisConnect
 * Константы: 0x300E2C90
 * Данные: DAT_300e2d34, DAT_300e2d38
 * ---------------------------------------------------------------- */
undefined4 intDisconnect(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((code *)*DAT_300e2d34 == (code *)0x0) ||
     (iVar1 = (*(code *)*DAT_300e2d34)(param_1,param_2,param_3), iVar1 != 0)) {
    if (((code *)*DAT_300e2d38 == (code *)0x0) ||
       (iVar1 = (*(code *)*DAT_300e2d38)(param_1,param_2,param_3), iVar1 != 0)) {
      uVar2 = intArchDisconnect(param_1,param_2,param_3);
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
 * kernelBaseInit @ 0x300E41C0  (примерный размер ~224 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: classInit, objCoreInit, reboot, semMInit
 * Вызывают: usrInit
 * Константы: 0x300E41C0, 0xFFFFFFFF
 * Данные: DAT_300e42d4, DAT_300e42d8, DAT_300e42dc, DAT_300e42e0, DAT_300e42e4, DAT_300e42e8
 * ---------------------------------------------------------------- */
undefined4 kernelBaseInit(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_300e42d4;
  if (*DAT_300e42d4 == 0) {
    iVar3 = classInit(*DAT_300e42d8,DAT_300e42dc,0,0,0,0,0,0,5,2);
    if (iVar3 != 0) {
      reboot(1);
      return 0xffffffff;
    }
    objCoreInit(*DAT_300e42e0,*DAT_300e42d8);
    uVar2 = DAT_300e42e4;
    semMInit(DAT_300e42e4,0xd);
    *(undefined4 *)(*DAT_300e42e0 + 0x60) = uVar2;
    uVar2 = DAT_300e42e8;
    semMInit(DAT_300e42e8,0xd);
    iVar3 = *DAT_300e42e0;
    *(undefined4 *)(iVar3 + 0x730) = uVar2;
    *(undefined4 *)(iVar3 + 0x44) = 0;
    *(undefined4 *)(iVar3 + 0x48) = 0;
    *piVar1 = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * kernelIdGet @ 0x300E42C8  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300E42C8
 * Данные: DAT_300e42e0
 * ---------------------------------------------------------------- */
undefined4 kernelIdGet(void)

{
  return *DAT_300e42e0;
}

/* ----------------------------------------------------------------
 * vxMemProbeInit @ 0x300E64F0  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: vxMemArchProbeInit
 * Вызывают: usrInit
 * Константы: 0x300E64F0
 * Данные: DAT_300e65d0
 * ---------------------------------------------------------------- */
void vxMemProbeInit(void)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = DAT_300e65d0;
  if (*DAT_300e65d0 == 0) {
    iVar2 = vxMemArchProbeInit(0);
    *puVar1 = (uint)(iVar2 == 0);
  }
  return;
}

/* ----------------------------------------------------------------
 * vxMemProbe @ 0x300E6530  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 6 | Вызывает: 0
 * Вызывают: FUN_300e6484, FUN_300f5c58, moduleIdFigure, objectShow, taskIdFigure, vxdbgBpAddrCheck
 * Константы: 0x300E6530
 * Данные: DAT_300e65d4, DAT_300e65d8
 * ---------------------------------------------------------------- */
void vxMemProbe(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)*DAT_300e65d4;
  if ((code *)*DAT_300e65d4 == (code *)0x0) {
    pcVar1 = DAT_300e65d8;
  }
  (*pcVar1)();
  return;
}

/* ----------------------------------------------------------------
 * vxMemCommonProbe @ 0x300E6560  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: vxMemProbeSup
 * Вызывают: vxMemArchProbe
 * Константы: 0xFFFFFFFF, 0x300E6560
 * Данные: DAT_300e65d0
 * ---------------------------------------------------------------- */
undefined4 vxMemCommonProbe(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (*DAT_300e65d0 == 0) {
    return 0xffffffff;
  }
  iVar2 = 0;
  uVar3 = param_3;
  if (param_3 != 0) {
    do {
      iVar2 = iVar2 + (uVar3 & 1);
      uVar3 = uVar3 >> 1;
    } while (uVar3 != 0);
    if (iVar2 == 1) {
      uVar1 = param_1;
      if (param_2 != 0) {
        uVar1 = param_4;
        param_4 = param_1;
      }
      uVar1 = vxMemProbeSup(param_3,uVar1,param_4);
      return uVar1;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * vxCpuEnabledGet @ 0x300E65DC  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300E65DC
 * Данные: DAT_300e664c
 * ---------------------------------------------------------------- */
undefined4 vxCpuEnabledGet(void)

{
  return *DAT_300e664c;
}

/* ----------------------------------------------------------------
 * vxCpuConfiguredGet @ 0x300E65E8  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300a9264
 * Константы: 0x300E65E8
 * Данные: DAT_300e6650
 * ---------------------------------------------------------------- */
undefined4 vxCpuConfiguredGet(void)

{
  return *DAT_300e6650;
}

/* ----------------------------------------------------------------
 * vxCpuReservedGet @ 0x300E65F4  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: atomic32Set, errnoSet
 * Константы: 0x300E65F4, 0xFFFFFFFF
 * Данные: DAT_300e6654, DAT_300e6658
 * ---------------------------------------------------------------- */
undefined4 vxCpuReservedGet(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    errnoSet(DAT_300e6654);
    uVar1 = 0xffffffff;
  }
  else {
    atomic32Set(param_1,*DAT_300e6658);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * vxCpuReserve @ 0x300E6624  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoSet
 * Константы: 0x300E6624, 0xFFFFFFFF
 * Данные: DAT_300e6654
 * ---------------------------------------------------------------- */
undefined4 vxCpuReserve(void)

{
  errnoSet(DAT_300e6654);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * vxCpuUnreserve @ 0x300E6638  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoSet
 * Константы: 0x300E6638, 0xFFFFFFFF
 * Данные: DAT_300e6654
 * ---------------------------------------------------------------- */
undefined4 vxCpuUnreserve(void)

{
  errnoSet(DAT_300e6654);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskVarInit @ 0x300E6BC0  (примерный размер ~88 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: taskDeleteHookAdd, taskSwitchHookAdd
 * Вызывают: usrKernelExtraInit
 * Константы: 0x300E6BC0, 0xFFFFFFFF
 * Данные: DAT_300e7114, DAT_300e7118, DAT_300e711c
 * ---------------------------------------------------------------- */
undefined4 taskVarInit(void)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  
  piVar1 = DAT_300e7114;
  if (*DAT_300e7114 == 0) {
    iVar2 = taskSwitchHookAdd(DAT_300e7118);
    bVar3 = iVar2 == 0;
    if (bVar3) {
      iVar2 = taskDeleteHookAdd(DAT_300e711c);
      bVar3 = iVar2 == 0;
    }
    if (!bVar3) {
      return 0xffffffff;
    }
    *piVar1 = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300e6c18 @ 0x300E6C18  (примерный размер ~132 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: free, semDelete, semTake
 * Константы: 0x300E6C18, 0xFFFFFFFF
 * Данные: DAT_300e7120
 * ---------------------------------------------------------------- */
void FUN_300e6c18(int param_1)

{
  int iVar1;
  undefined4 *__ptr;
  void *pvVar2;
  
  if (*(int *)(param_1 + 0x158) == 0) {
    return;
  }
  iVar1 = semTake(*(int *)(param_1 + 0x158),0xffffffff);
  if (iVar1 == -1) {
    return;
  }
  __ptr = *(undefined4 **)(param_1 + 0xe8);
  *(undefined4 *)(param_1 + 0xe8) = 0;
  while (__ptr != (undefined4 *)0x0) {
    if (*DAT_300e7120 == param_1) {
      *(undefined4 *)__ptr[1] = __ptr[2];
    }
    pvVar2 = (void *)*__ptr;
    free(__ptr);
    __ptr = (undefined4 *)pvVar2;
  }
  semDelete(*(undefined4 *)(param_1 + 0x158));
  *(undefined4 *)(param_1 + 0x158) = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300e6c9c @ 0x300E6C9C  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: objVerify
 * Константы: 0x300E6C9C
 * Данные: DAT_300e7124
 * ---------------------------------------------------------------- */
void FUN_300e6c9c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = objVerify(param_1,*DAT_300e7124);
  if (iVar1 == 0) {
    for (piVar3 = *(int **)(param_1 + 0xe8); piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      uVar2 = piVar3[2];
      piVar3[2] = *(undefined4 *)piVar3[1];
      *(undefined4 *)piVar3[1] = uVar2;
    }
  }
  piVar3 = *(int **)(param_2 + 0xe8);
  if (piVar3 != (int *)0x0) {
    do {
      iVar1 = piVar3[2];
      piVar3[2] = *(int *)piVar3[1];
      *(int *)piVar3[1] = iVar1;
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)0x0);
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * taskVarAdd @ 0x300E6D18  (примерный размер ~268 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 8
 * Вызывает: free, malloc, semGive, semMCreate, semTake, taskDeleteHookAdd, taskSwitchHookAdd, taskTcb
 * Константы: 0xFFFFFFFF, 0x300E6D18
 * Данные: DAT_300e7114, DAT_300e7118, DAT_300e711c
 * ---------------------------------------------------------------- */
undefined4 taskVarAdd(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *__ptr;
  bool bVar5;
  
  iVar2 = taskTcb();
  piVar1 = DAT_300e7114;
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    if (*DAT_300e7114 == 0) {
      iVar4 = taskSwitchHookAdd(DAT_300e7118);
      bVar5 = iVar4 == 0;
      if (bVar5) {
        iVar4 = taskDeleteHookAdd(DAT_300e711c);
        bVar5 = iVar4 == 0;
      }
      if (!bVar5) {
        return 0xffffffff;
      }
      *piVar1 = 1;
    }
    __ptr = (undefined4 *)malloc(0xc);
    if (__ptr == (undefined4 *)0x0) {
      uVar3 = 0xffffffff;
    }
    else {
      __ptr[1] = param_2;
      __ptr[2] = *param_2;
      if (*(int *)(iVar2 + 0x158) == 0) {
        iVar4 = semMCreate(0xd);
        *(int *)(iVar2 + 0x158) = iVar4;
        if (iVar4 == 0) {
          free(__ptr);
          return 0xffffffff;
        }
      }
      iVar4 = *(int *)(iVar2 + 0x158);
      *(ushort *)(iVar4 + 8) = *(ushort *)(iVar4 + 8) | 0x20;
      iVar4 = semTake(iVar4,0xffffffff);
      if (iVar4 == -1) {
        free(__ptr);
        uVar3 = 0xffffffff;
      }
      else {
        *__ptr = *(undefined4 *)(iVar2 + 0xe8);
        *(undefined4 **)(iVar2 + 0xe8) = __ptr;
        semGive(*(undefined4 *)(iVar2 + 0x158));
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * taskVarDelete @ 0x300E6E24  (примерный размер ~204 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: errnoSet, free, semGive, semTake, taskTcb
 * Константы: 0xFFFFFFFF, 0x300E6E24
 * Данные: DAT_300e7120, DAT_300e7128
 * ---------------------------------------------------------------- */
undefined4 taskVarDelete(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *__ptr;
  
  iVar2 = taskTcb();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if ((*(int *)(iVar2 + 0x158) != 0) &&
     (iVar3 = semTake(*(int *)(iVar2 + 0x158),0xffffffff), iVar3 != -1)) {
    iVar3 = *(int *)(iVar2 + 0xe8);
    piVar1 = (int *)(iVar2 + 0xe8);
    while( true ) {
      if (iVar3 == 0) {
        semGive(*(undefined4 *)(iVar2 + 0x158));
        errnoSet(DAT_300e7128);
        return 0xffffffff;
      }
      __ptr = (int *)*piVar1;
      if ((int *)__ptr[1] == param_2) break;
      iVar3 = *__ptr;
      piVar1 = __ptr;
    }
    if (*DAT_300e7120 == iVar2) {
      *param_2 = __ptr[2];
    }
    *piVar1 = *__ptr;
    semGive(*(undefined4 *)(iVar2 + 0x158));
    free(__ptr);
    return 0;
  }
  errnoSet(DAT_300e7128);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskVarGet @ 0x300E6EF0  (примерный размер ~176 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: errnoSet, semGive, semTake, taskTcb
 * Константы: 0xFFFFFFFF, 0x300E6EF0
 * Данные: DAT_300e7120, DAT_300e7128
 * ---------------------------------------------------------------- */
undefined4 taskVarGet(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if ((*(int *)(iVar1 + 0x158) != 0) &&
     (iVar2 = semTake(*(int *)(iVar1 + 0x158),0xffffffff), iVar2 != -1)) {
    piVar3 = *(int **)(iVar1 + 0xe8);
    while( true ) {
      if (piVar3 == (int *)0x0) {
        semGive(*(undefined4 *)(iVar1 + 0x158));
        errnoSet(DAT_300e7128);
        return 0xffffffff;
      }
      if ((undefined4 *)piVar3[1] == param_2) break;
      piVar3 = (int *)*piVar3;
    }
    if (*DAT_300e7120 == iVar1) {
      uVar4 = *param_2;
    }
    else {
      uVar4 = piVar3[2];
    }
    semGive(*(undefined4 *)(iVar1 + 0x158));
    return uVar4;
  }
  errnoSet(DAT_300e7128);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskVarSet @ 0x300E6FA0  (примерный размер ~180 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: errnoSet, semGive, semTake, taskTcb
 * Константы: 0xFFFFFFFF, 0x300E6FA0
 * Данные: DAT_300e7120, DAT_300e7128
 * ---------------------------------------------------------------- */
undefined4 taskVarSet(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if ((*(int *)(iVar1 + 0x158) != 0) &&
     (iVar2 = semTake(*(int *)(iVar1 + 0x158),0xffffffff), iVar2 != -1)) {
    piVar3 = *(int **)(iVar1 + 0xe8);
    while( true ) {
      if (piVar3 == (int *)0x0) {
        semGive(*(undefined4 *)(iVar1 + 0x158));
        errnoSet(DAT_300e7128);
        return 0xffffffff;
      }
      if ((undefined4 *)piVar3[1] == param_2) break;
      piVar3 = (int *)*piVar3;
    }
    if (*DAT_300e7120 == iVar1) {
      *param_2 = param_3;
    }
    else {
      piVar3[2] = param_3;
    }
    semGive(*(undefined4 *)(iVar1 + 0x158));
    return 0;
  }
  errnoSet(DAT_300e7128);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskVarInfo @ 0x300E7054  (примерный размер ~216 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: semGive, semTake, taskTcb
 * Константы: 0x300E7054, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int taskVarInfo(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = taskTcb();
  iVar4 = 0;
  if (iVar1 == 0) {
    return -1;
  }
  if (*(int *)(iVar1 + 0x158) == 0) {
    return 0;
  }
  iVar2 = semTake(*(int *)(iVar1 + 0x158),0xffffffff);
  if (iVar2 == -1) {
    return -1;
  }
  piVar3 = *(int **)(iVar1 + 0xe8);
  if ((piVar3 != (int *)0x0) && (iVar2 = param_3, 0 < param_3)) {
    do {
      iVar2 = iVar2 + -1;
      *param_2 = *piVar3;
      param_2[1] = piVar3[1];
      param_2[2] = piVar3[2];
      piVar3 = (int *)*piVar3;
      param_2 = param_2 + 3;
      if (piVar3 == (int *)0x0) break;
    } while (iVar2 != 0);
    iVar4 = param_3 - iVar2;
  }
  semGive(*(undefined4 *)(iVar1 + 0x158));
  return iVar4;
}

/* ----------------------------------------------------------------
 * taskCreateHookInit @ 0x300E712C  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300bc1cc, usrKernelCoreInit
 * Константы: 0x300E712C
 * Данные: DAT_300e7238, DAT_300e723c, DAT_300e7240, DAT_300e7244
 * ---------------------------------------------------------------- */
void taskCreateHookInit(void)

{
  *DAT_300e723c = DAT_300e7238;
  *DAT_300e7244 = DAT_300e7240;
  return;
}

/* ----------------------------------------------------------------
 * taskCreateHookAdd @ 0x300E7148  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 3
 * Вызывает: errnoGet, errnoSet, hookAddToTail
 * Вызывают: coprocLibInit, envLibInit, selectInit, shellLibInit
 * Константы: 0x300E7148
 * Данные: DAT_300e7248, DAT_300e724c, DAT_300e7250
 * ---------------------------------------------------------------- */
int taskCreateHookAdd(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = hookAddToTail(param_1,DAT_300e7248,0x14);
  if ((iVar1 == -1) && (iVar2 = errnoGet(), iVar2 == DAT_300e724c)) {
    errnoSet(DAT_300e7250);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * taskCreateHookDelete @ 0x300E7184  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: errnoGet, errnoSet, hookDelete
 * Вызывают: coprocLibInit, shellLibInit
 * Константы: 0x300E7184
 * Данные: DAT_300e7248, DAT_300e7254, DAT_300e7258
 * ---------------------------------------------------------------- */
int taskCreateHookDelete(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = hookDelete(param_1,DAT_300e7248,0x14);
  if ((iVar1 == -1) && (iVar2 = errnoGet(), iVar2 == DAT_300e7254)) {
    errnoSet(DAT_300e7258);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * taskDeleteHookAdd @ 0x300E71C0  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 11 | Вызывает: 3
 * Вызывает: errnoGet, errnoSet, hookAddToHead
 * Вызывают: FUN_300bc1cc, coprocLibInit, envLibInit, msgQLibInit, selTaskDeleteHookAdd, shellLibInit, sigInit, taskVarAdd, taskVarInit, tipStart
 *           ...
 * Константы: 0x300E71C0
 * Данные: DAT_300e724c, DAT_300e7250, DAT_300e725c
 * ---------------------------------------------------------------- */
int taskDeleteHookAdd(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = hookAddToHead(param_1,DAT_300e725c,0x14);
  if ((iVar1 == -1) && (iVar2 = errnoGet(), iVar2 == DAT_300e724c)) {
    errnoSet(DAT_300e7250);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * taskDeleteHookDelete @ 0x300E71FC  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 3
 * Вызывает: errnoGet, errnoSet, hookDelete
 * Вызывают: FUN_300f7564, coprocLibInit, shellLibInit
 * Константы: 0x300E71FC
 * Данные: DAT_300e7254, DAT_300e7258, DAT_300e725c
 * ---------------------------------------------------------------- */
int taskDeleteHookDelete(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = hookDelete(param_1,DAT_300e725c,0x14);
  if ((iVar1 == -1) && (iVar2 = errnoGet(), iVar2 == DAT_300e7254)) {
    errnoSet(DAT_300e7258);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * taskSwapHookAdd @ 0x300E7260  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: errnoSet, windExit
 * Вызывают: coprocLibInit
 * Константы: 0x300E7260, 0xFFFFFFFF
 * Данные: DAT_300e7610, DAT_300e7614, DAT_300e7618, DAT_300e761c
 * ---------------------------------------------------------------- */
undefined4 taskSwapHookAdd(int param_1)

{
  int *piVar1;
  int iVar2;
  
  *DAT_300e7610 = 1;
  iVar2 = 0;
  piVar1 = DAT_300e7614;
  do {
    piVar1 = piVar1 + 1;
    if (*piVar1 == 0) {
      *piVar1 = param_1;
      *(undefined4 *)(DAT_300e7618 + iVar2 * 4) = 0;
      windExit();
      return 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  windExit();
  errnoSet(DAT_300e761c);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300e72cc @ 0x300E72CC  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: __errno, taskTcb
 * Вызывают: taskSwapHookAttach
 * Константы: 0xFFFFFFFF, 0x300E72CC
 * Данные: DAT_300e7620
 * ---------------------------------------------------------------- */
undefined4 FUN_300e72cc(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = taskTcb();
  uVar1 = 1 << (param_2 & 0xff);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (((param_3 == 0) || ((uVar1 & *(ushort *)(iVar2 + 0xa4)) == 0)) &&
     ((param_4 == 0 || ((uVar1 & *(ushort *)(iVar2 + 0xa6)) == 0)))) {
    if (param_3 != 0) {
      *(ushort *)(iVar2 + 0xa4) = (ushort)uVar1 | *(ushort *)(iVar2 + 0xa4);
    }
    if (param_4 != 0) {
      *(ushort *)(iVar2 + 0xa6) = (ushort)uVar1 | *(ushort *)(iVar2 + 0xa6);
    }
    return 0;
  }
  puVar3 = (undefined4 *)__errno();
  *puVar3 = DAT_300e7620;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskSwapHookAttach @ 0x300E735C  (примерный размер ~236 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300e72cc, errnoSet, windExit
 * Вызывают: coprocTaskCreateHook
 * Константы: 0xFFFFFFFF, 0x300E735C
 * Данные: DAT_300e7610, DAT_300e7614, DAT_300e7618, DAT_300e7624
 * ---------------------------------------------------------------- */
undefined4 taskSwapHookAttach(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  bool bVar6;
  
  *DAT_300e7610 = 1;
  iVar1 = DAT_300e7618;
  iVar5 = 0;
  piVar4 = DAT_300e7614;
  do {
    piVar4 = piVar4 + 1;
    if (*piVar4 == param_1) {
      iVar3 = iVar5 * 4;
      iVar2 = (uint)(param_3 != 0) + *(int *)(DAT_300e7618 + iVar3);
      *(int *)(DAT_300e7618 + iVar3) = iVar2;
      *(uint *)(iVar1 + iVar3) = (uint)(param_4 != 0) + iVar2;
      iVar3 = FUN_300e72cc(param_2,iVar5,param_3,param_4);
      if (iVar3 != 0) {
        bVar6 = param_3 == 0;
        if (bVar6) {
          param_3 = 0;
        }
        iVar5 = iVar5 * 4;
        if (!bVar6) {
          param_3 = 1;
        }
        bVar6 = param_4 == 0;
        if (bVar6) {
          param_4 = 0;
        }
        param_3 = *(int *)(iVar1 + iVar5) - param_3;
        *(int *)(iVar1 + iVar5) = param_3;
        if (!bVar6) {
          param_4 = 1;
        }
        *(int *)(iVar1 + iVar5) = param_3 - param_4;
        windExit();
        return 0xffffffff;
      }
      windExit();
      return 0;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  windExit();
  errnoSet(DAT_300e7624);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300e7448 @ 0x300E7448  (примерный размер ~144 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: __errno, taskTcb
 * Вызывают: taskSwapHookDetach
 * Константы: 0xFFFFFFFF, 0x300E7448
 * Данные: DAT_300e7628
 * ---------------------------------------------------------------- */
undefined4 FUN_300e7448(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = taskTcb();
  uVar1 = 1 << (param_2 & 0xff);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (((param_3 == 0) || ((uVar1 & *(ushort *)(iVar2 + 0xa4)) != 0)) &&
     ((param_4 == 0 || ((uVar1 & *(ushort *)(iVar2 + 0xa6)) != 0)))) {
    if (param_3 != 0) {
      *(ushort *)(iVar2 + 0xa4) = *(ushort *)(iVar2 + 0xa4) & ~(ushort)uVar1;
    }
    if (param_4 != 0) {
      *(ushort *)(iVar2 + 0xa6) = *(ushort *)(iVar2 + 0xa6) & ~(ushort)uVar1;
    }
    return 0;
  }
  puVar3 = (undefined4 *)__errno();
  *puVar3 = DAT_300e7628;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskSwapHookDetach @ 0x300E74D8  (примерный размер ~188 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300e7448, errnoSet, windExit
 * Вызывают: coprocTaskDeleteHook
 * Константы: 0xFFFFFFFF, 0x300E74D8
 * Данные: DAT_300e7610, DAT_300e7614, DAT_300e7618, DAT_300e7624
 * ---------------------------------------------------------------- */
undefined4 taskSwapHookDetach(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  *DAT_300e7610 = 1;
  iVar4 = 0;
  piVar2 = DAT_300e7614;
  do {
    piVar2 = piVar2 + 1;
    if (*piVar2 == param_1) {
      iVar3 = FUN_300e7448(param_2,iVar4,param_3,param_4);
      iVar1 = DAT_300e7618;
      if (iVar3 != 0) {
        windExit();
        return 0xffffffff;
      }
      if (param_3 == 0) {
        param_2 = 0;
      }
      iVar4 = iVar4 * 4;
      if (param_3 != 0) {
        param_2 = 1;
      }
      bVar5 = param_4 == 0;
      if (bVar5) {
        param_4 = 0;
      }
      param_2 = *(int *)(DAT_300e7618 + iVar4) - param_2;
      *(int *)(DAT_300e7618 + iVar4) = param_2;
      if (!bVar5) {
        param_4 = 1;
      }
      *(int *)(iVar1 + iVar4) = param_2 - param_4;
      windExit();
      return 0;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x10);
  windExit();
  errnoSet(DAT_300e7624);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskSwapHookDelete @ 0x300E7594  (примерный размер ~156 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: errnoSet, windExit
 * Константы: 0x300E7594, 0xFFFFFFFF
 * Данные: DAT_300e7610, DAT_300e7614, DAT_300e7618, DAT_300e7624, DAT_300e762c
 * ---------------------------------------------------------------- */
undefined4 taskSwapHookDelete(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  *DAT_300e7610 = 1;
  iVar1 = 0;
  piVar3 = DAT_300e7614;
  do {
    piVar3 = piVar3 + 1;
    if (*piVar3 == param_1) {
      if (*(int *)(DAT_300e7618 + iVar1 * 4) == 0) {
        *piVar3 = 0;
        windExit();
        return 0;
      }
      windExit();
      uVar2 = DAT_300e762c;
      goto LAB_300e7604;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  windExit();
  uVar2 = DAT_300e7624;
LAB_300e7604:
  errnoSet(uVar2);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskSwitchHookAdd @ 0x300E7630  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 6 | Вызывает: 3
 * Вызывает: errnoGet, errnoSet, hookAddToTail
 * Вызывают: CvInfoStart, FUN_300c69b0, exchHookFuncAdd, exchInit, taskVarAdd, taskVarInit
 * Константы: 0x300E7630
 * Данные: DAT_300e76a8, DAT_300e76ac, DAT_300e76b0
 * ---------------------------------------------------------------- */
int taskSwitchHookAdd(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = hookAddToTail(param_1,DAT_300e76a8,0x10);
  if ((iVar1 == -1) && (iVar2 = errnoGet(), iVar2 == DAT_300e76ac)) {
    errnoSet(DAT_300e76b0);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * taskSwitchHookDelete @ 0x300E766C  (примерный размер ~80 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: errnoGet, errnoSet, hookDelete
 * Вызывают: CvInfoStop, exchHookFuncDelete
 * Константы: 0x300E766C
 * Данные: DAT_300e76a8, DAT_300e76b4, DAT_300e76b8
 * ---------------------------------------------------------------- */
int taskSwitchHookDelete(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = hookDelete(param_1,DAT_300e76a8,0x10);
  if ((iVar1 == -1) && (iVar2 = errnoGet(), iVar2 == DAT_300e76b4)) {
    errnoSet(DAT_300e76b8);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * ioFullFileNameGet @ 0x300E7ABC  (примерный размер ~996 байт)
 * Модуль: kernel | Вызывают: 6 | Вызывает: 4
 * Вызывает: bzero, iosDevFind, pathCat, strncpy
 * Вызывают: FUN_300d4a88, creat, iosPathFdEntryIoctl, open, remove, rm
 * Константы: 0xFFFFFFFF, 0x300E7ABC
 * Данные: DAT_300e862c, DAT_300e8630
 * ---------------------------------------------------------------- */
undefined4 ioFullFileNameGet(undefined4 param_1,int *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  size_t __n;
  char *local_18;
  
  __n = 0x400;
  bzero(param_3,0x400);
  iVar2 = pathCat(*(undefined4 *)(*(int *)(*DAT_300e862c + 0x94) + 0xd4),param_1,param_3);
  if (iVar2 == -1) {
    uVar3 = 0xffffffff;
  }
  else {
    if (*DAT_300e8630 != 0) {
      cVar1 = *param_3;
      iVar2 = 0;
      while (cVar1 == '/') {
        iVar4 = iVar2 + 1;
        iVar5 = iVar4;
        if (2 < iVar4) {
          iVar5 = iVar2;
        }
        if (iVar4 != 2 && iVar2 + -1 < 0 == SBORROW4(iVar4,2)) {
          param_3 = param_3 + iVar5;
          __n = __n - iVar5;
        }
        iVar2 = iVar5;
        cVar1 = param_3[iVar5];
      }
    }
    iVar2 = iosDevFind(param_3,&local_18);
    *param_2 = iVar2;
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      strncpy(param_3,local_18,__n);
      uVar3 = 0;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * ioGlobalStdSet @ 0x300E82C0  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 2
 * Вызывает: __errno, iosFdMap
 * Вызывают: FUN_30111020, shellInOutSet, shellTask, shellTerminate, usrSerialInit
 * Константы: 0x300E82C0, 0xFFFFFFFF
 * Данные: DAT_300e862c, DAT_300e8654, DAT_300e8658, DAT_300e865c, DAT_300e8660
 * ---------------------------------------------------------------- */
undefined4 ioGlobalStdSet(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = iosFdMap(param_2);
  if (iVar1 != 0) {
    if (((-1 < param_1) && (param_1 < 3)) && (*(int *)(*DAT_300e862c + 0x94) == *DAT_300e8654)) {
      *(undefined4 *)(DAT_300e8658 + param_1 * 4) = param_2;
      if (param_1 == 1) {
        *DAT_300e8660 = DAT_300e865c;
      }
      return 0;
    }
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x16;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * ioGlobalStdGet @ 0x300E833C  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 12 | Вызывает: 0
 * Вызывают: BSP_OM_ShellLock, FUN_3010df20, FUN_30111020, iosFdShow, shellCompatibleSet, shellConsoleInit, shellGenericInit, shellInOutGet, shellInOutInputUniqueCheck, shellInOutSet
 *           ...
 * Константы: 0x300E833C
 * Данные: DAT_300e862c, DAT_300e8654, DAT_300e8658
 * ---------------------------------------------------------------- */
int ioGlobalStdGet(int param_1)

{
  if (*(int *)(*DAT_300e862c + 0x94) == *DAT_300e8654) {
    if ((param_1 < 0) || (2 < param_1)) {
      param_1 = -1;
    }
    else {
      param_1 = *(int *)(DAT_300e8658 + param_1 * 4);
    }
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * ioTaskStdSet @ 0x300E8378  (примерный размер ~140 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 3
 * Вызывает: __errno, iosFdMap, taskTcb
 * Вызывают: FUN_30101c78, FUN_3010df20, FUN_3010f2f0, FUN_30110c38, FUN_30110f80, FUN_30114ebc, FUN_30115680
 * Константы: 0x300E8378, 0xFFFFFFFF
 * Данные: DAT_300e8654, DAT_300e865c, DAT_300e8660
 * ---------------------------------------------------------------- */
undefined4 ioTaskStdSet(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = iosFdMap(param_3);
  if (iVar1 != 0) {
    if ((((-1 < param_2) && (param_2 < 3)) && (iVar1 = taskTcb(param_1), iVar1 != 0)) &&
       (*(int *)(iVar1 + 0x94) == *DAT_300e8654)) {
      *(undefined4 *)(iVar1 + param_2 * 4 + 0x100) = param_3;
      if (param_2 == 1) {
        *DAT_300e8660 = DAT_300e865c;
      }
      return 0;
    }
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x16;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * ioTaskStdGet @ 0x300E8404  (примерный размер ~116 байт)
 * Модуль: kernel | Вызывают: 8 | Вызывает: 1
 * Вызывает: taskTcb
 * Вызывают: FUN_300c906c, FUN_300ee694, FUN_30110224, iosClose, iosFdMap, shellCompatibleSet, shellExec, shellInOutBlockingBlock
 * Константы: 0x300E8404
 * Данные: DAT_300e8654, DAT_300e8658
 * ---------------------------------------------------------------- */
int ioTaskStdGet(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (((param_2 < 0) || (2 < param_2)) || (iVar1 = taskTcb(), iVar1 == 0)) {
    return -1;
  }
  if (*(int *)(iVar1 + 0x94) != *DAT_300e8654) {
    return param_2;
  }
  iVar1 = *(int *)(iVar1 + param_2 * 4 + 0x100);
  if ((-1 < iVar1) && (iVar1 < 3)) {
    return *(int *)(DAT_300e8658 + iVar1 * 4);
  }
  return iVar1;
}

