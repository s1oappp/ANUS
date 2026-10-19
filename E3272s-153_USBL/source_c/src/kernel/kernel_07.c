/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : kernel — ядро VxWorks 6.8: задачи, семафоры, очереди, прерывания, память, планировщик
 * Часть  : 7 (функций: 106, адреса 0x30124B24..0x3012B740)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * semLocalIdVerify @ 0x30124B24  (примерный размер ~188 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 3
 * Вызывает: __errno, intContext, objVerify
 * Вызывают: __diab_free_mutex, __diab_free_semaphore, semDelete, semDestroy, semTerminate
 * Константы: 0xFFFFFFFF, 0x30124B24
 * Данные: DAT_30124c98, DAT_30124cac, DAT_30124cb0, DAT_30124cb4
 * ---------------------------------------------------------------- */
undefined4 semLocalIdVerify(uint param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  byte in_Q;
  
  iVar1 = intContext();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30124cac;
    return 0xffffffff;
  }
  bVar3 = (param_1 & 1) == 0;
  if (!bVar3) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30124cb0;
    return 0xffffffff;
  }
  *param_3 = (uint)(byte)(bVar3 << 3 | 4U | in_Q) << 0x1b;
  iVar1 = objVerify(param_1,*DAT_30124c98);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if ((param_2 != 1) && ((*(ushort *)(param_1 + 8) & 0x80) != 0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30124cb4;
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * semDelete @ 0x30124BE0  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 30 | Вызывает: 2
 * Вызывает: FUN_30124a88, semLocalIdVerify
 * Вызывают: FUN_3005f9a4, FUN_300ca3dc, FUN_300cb558, FUN_300cbe88, FUN_300d6de0, FUN_300dec40, FUN_300e6c18, FUN_301124fc, FUN_30112e10, OSAL_SemDelete
 *           ...
 * Константы: 0x30124BE0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 semDelete(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  iVar1 = semLocalIdVerify(param_1,0,&local_c);
  if (iVar1 == 0) {
    uVar2 = FUN_30124a88(param_1,1,local_c);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * semTerminate @ 0x30124C1C  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 9 | Вызывает: 2
 * Вызывает: FUN_30124a88, semLocalIdVerify
 * Вызывают: FUN_300eeb94, FUN_300f2198, poolCreate, poolDelete, ptyDevCreate, ptyDevRemove, selWakeupListTerm, symTblDelete, tyDevTerminate
 * Константы: 0x30124C1C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 semTerminate(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  iVar1 = semLocalIdVerify(param_1,0,&local_c);
  if (iVar1 == 0) {
    uVar2 = FUN_30124a88(param_1,0,local_c);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * semDestroy @ 0x30124C58  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30124a88, semLocalIdVerify
 * Вызывают: FUN_300ad768
 * Константы: 0x30124C58, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 semDestroy(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  
  iVar1 = semLocalIdVerify(param_1,1,&local_10);
  if (iVar1 == 0) {
    uVar2 = FUN_30124a88(param_1,param_2,local_10);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * semEvStart @ 0x30124CB8  (примерный размер ~228 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 6
 * Вызывает: __errno, errnoSet, eventStart, intContext, objVerify, taskCpuUnlock
 * Константы: 0xFFFFFFFF, 0x30124CB8
 * Данные: DAT_30124e34, DAT_30124e38, DAT_30124e3c, DAT_30124e40, DAT_30124e44
 * ---------------------------------------------------------------- */
undefined4 semEvStart(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 == 0) {
    errnoSet(DAT_30124e34);
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = intContext();
    if (iVar2 == 0) {
      *(int *)(*DAT_30124e3c + 0x7c) = *(int *)(*DAT_30124e3c + 0x7c) + 1;
      iVar2 = objVerify(param_1,*DAT_30124e40);
      if (iVar2 == 0) {
        uVar1 = eventStart(param_1,param_1 + 0x58,
                           *(undefined4 *)(DAT_30124e44 + (*(byte *)(param_1 + 0x40) & 0xf) * 4),
                           param_2,param_3,0);
      }
      else {
        taskCpuUnlock();
        uVar1 = 0xffffffff;
      }
    }
    else {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = DAT_30124e38;
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * semEvStop @ 0x30124D9C  (примерный размер ~176 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: __errno, errnoSet, intContext, objVerify
 * Константы: 0xFFFFFFFF, 0x30124D9C
 * Данные: DAT_30124e38, DAT_30124e3c, DAT_30124e40, DAT_30124e48
 * ---------------------------------------------------------------- */
undefined4 semEvStop(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = intContext();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30124e38;
    return 0xffffffff;
  }
  iVar1 = objVerify(param_1,*DAT_30124e40);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (*DAT_30124e3c != *(int *)(param_1 + 0x5c)) {
    errnoSet(DAT_30124e48);
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x5c) = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * semInfo @ 0x30124E4C  (примерный размер ~340 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: __errno, intContext, objVerify
 * Константы: 0x30124E4C
 * Данные: DAT_301251a8, DAT_301251ac, DAT_301251b0, DAT_301251b4, DAT_301251b8
 * ---------------------------------------------------------------- */
int semInfo(uint param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = intContext();
  if (iVar1 == 0) {
    if ((param_1 & 1) == 0) {
      iVar1 = objVerify(param_1,*DAT_301251b8);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*(int *)(param_1 + 0x50) + 0x30))(param_1 + 0x44,param_2,param_3);
        if ((*(char *)(param_1 + 0x40) == '\x06') && (0 < param_3 - iVar1)) {
          iVar3 = (**(code **)(*(int *)(param_1 + 0x7c) + 0x30))
                            (param_1 + 0x70,param_2 + iVar1 * 4,param_3 - iVar1);
          iVar1 = iVar3 + iVar1;
        }
        if ((param_2 != 0) && (0 < iVar1)) {
          piVar4 = (int *)(param_2 + -4);
          iVar3 = iVar1;
          do {
            piVar4 = piVar4 + 1;
            iVar3 = iVar3 + -1;
            *piVar4 = *piVar4 + -0x50;
          } while (iVar3 != 0);
        }
      }
      else {
        iVar1 = -1;
      }
    }
    else if ((code *)*DAT_301251ac == (code *)0x0) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_301251b0;
      iVar1 = -1;
    }
    else {
      iVar1 = (*(code *)*DAT_301251ac)(param_1 + *DAT_301251b4,param_2,param_3);
    }
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_301251a8;
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * semInfoGet @ 0x30124FA0  (примерный размер ~544 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: __errno, intContext, objVerify
 * Константы: 0xFFFFFFFF, 0x30124FA0, 0xFFFFFFFE
 * Данные: DAT_301251a8, DAT_301251b8, DAT_301251bc
 * ---------------------------------------------------------------- */
undefined4 semInfoGet(uint param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar6 = 0;
  iVar3 = intContext();
  if (iVar3 == 0) {
    if ((param_1 & 1) == 0) {
      iVar3 = objVerify(param_1,*DAT_301251b8);
      if (iVar3 == 0) {
        if (param_2[5] != 0) {
          iVar6 = (**(code **)(*(int *)(param_1 + 0x50) + 0x30))
                            (param_1 + 0x44,param_2[5],param_2[4]);
        }
        iVar3 = (**(code **)(*(int *)(param_1 + 0x50) + 0x30))(param_1 + 0x44,0,0);
        *param_2 = iVar3;
        if (*(char *)(param_1 + 0x40) == '\x06') {
          if ((param_2[5] != 0) && (0 < param_2[4] - iVar6)) {
            iVar3 = (**(code **)(*(int *)(param_1 + 0x7c) + 0x30))
                              (param_1 + 0x70,param_2[5] + iVar6 * 4,param_2[4] - iVar6);
            iVar6 = iVar3 + iVar6;
          }
          iVar7 = *param_2;
          iVar3 = (**(code **)(*(int *)(param_1 + 0x7c) + 0x30))(param_1 + 0x70,0,0);
          *param_2 = iVar3 + iVar7;
        }
        uVar8 = *(uint *)(param_1 + 0x54);
        iVar3 = param_2[5];
        if ((iVar3 != 0) && (iVar7 = 0, 0 < iVar6)) {
          do {
            iVar1 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(int *)(iVar3 + iVar1) = *(int *)(iVar3 + iVar1) + -0x50;
          } while (iVar7 < iVar6);
        }
        cVar2 = *(char *)(param_1 + 0x40);
        if (cVar2 == '\0') {
          if (uVar8 == 0) {
            param_2[3] = 1;
          }
          else {
            param_2[3] = 0;
          }
        }
        else if (cVar2 == '\x01') {
          param_2[3] = uVar8 & 0xfffffffe;
        }
        else if (cVar2 == '\x02') {
          param_2[3] = uVar8;
        }
        else {
          if (cVar2 != '\x06') {
            puVar4 = (undefined4 *)__errno();
            *puVar4 = DAT_301251bc;
            return 0xffffffff;
          }
          param_2[3] = uVar8;
        }
        uVar5 = 0;
        param_2[1] = (uint)*(byte *)(param_1 + 0x40);
        param_2[2] = (uint)*(byte *)(param_1 + 0x41);
      }
      else {
        uVar5 = 0xffffffff;
      }
    }
    else {
      puVar4 = (undefined4 *)__errno();
      *puVar4 = DAT_301251bc;
      uVar5 = 0xffffffff;
    }
  }
  else {
    puVar4 = (undefined4 *)__errno();
    *puVar4 = DAT_301251a8;
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * semLibInit @ 0x301251C0  (примерный размер ~128 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: classInit
 * Вызывают: usrInit
 * Константы: 0x301251C0, 0xFFFFFFFF
 * Данные: DAT_301255fc, DAT_30125600
 * ---------------------------------------------------------------- */
undefined4 semLibInit(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
  piVar1 = DAT_301255fc;
  bVar4 = *DAT_301255fc == 0;
  if (bVar4) {
    iVar2 = classInit(*DAT_30125600,0x68,0,0,0,0,0,0,1,0);
    if (iVar2 == 0) {
      *piVar1 = 1;
    }
    bVar4 = *piVar1 == 0;
  }
  if (bVar4) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * semGiveDefer @ 0x30125240  (примерный размер ~92 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 3
 * Вызывает: __errno, objVerify, workQAdd1
 * Вызывают: __diab_unlock_mutex, __diab_unlock_semaphore, semGive
 * Константы: 0xFFFFFFFF, 0x30125240
 * Данные: DAT_30125600, DAT_30125604, DAT_30125608
 * ---------------------------------------------------------------- */
undefined4 semGiveDefer(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = objVerify(param_1,*DAT_30125600);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(DAT_30125604 + (uint)*(byte *)(param_1 + 0x40) * 4);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30125608;
    return 0xffffffff;
  }
  workQAdd1(iVar1,param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * semGive @ 0x3012529C  (примерный размер ~112 байт)
 * Модуль: kernel | Вызывают: 230 | Вызывает: 1
 * Вызывает: semGiveDefer
 * Вызывают: BSP_HKADC_Convert, BSP_WDT_Feed, CvAnnounce, FUN_3005fcf8, FUN_3005ff20, FUN_30060dd0, FUN_300615fc, FUN_30062e20, FUN_300c2898, FUN_300c69b0
 *           ...
 * Константы: 0x3012529C
 * Данные: DAT_3012560c, DAT_30125610, DAT_30125614
 * ---------------------------------------------------------------- */
void semGive(uint param_1)

{
  code *pcVar1;
  
  if ((param_1 & 1) == 0) {
    if (*DAT_3012560c == 1) {
      semGiveDefer(param_1);
      return;
    }
    pcVar1 = *(code **)(DAT_30125610 + (*(byte *)(param_1 + 0x40) & 0xf) * 4);
  }
  else {
    param_1 = param_1 + *DAT_30125614;
    pcVar1 = *(code **)(DAT_30125610 + (*(byte *)(param_1 + 7) & 0xf) * 4);
  }
  (*pcVar1)(param_1);
  return;
}

/* ----------------------------------------------------------------
 * semTake @ 0x3012530C  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 228 | Вызывает: 0
 * Вызывают: BSP_HKADC_Convert, BSP_HKADC_GetTempTask, FUN_30060dd0, FUN_3006106c, FUN_30062e20, FUN_30067a78, FUN_30075e48, FUN_300c2cc0, FUN_300c69b0, FUN_300c9548
 *           ...
 * Константы: 0x3012530C
 * Данные: DAT_30125614, DAT_30125618
 * ---------------------------------------------------------------- */
void semTake(uint param_1)

{
  code *pcVar1;
  
  if ((param_1 & 1) == 0) {
    pcVar1 = *(code **)(DAT_30125618 + (*(byte *)(param_1 + 0x40) & 0xf) * 4);
  }
  else {
    param_1 = param_1 + *DAT_30125614;
    pcVar1 = *(code **)(DAT_30125618 + (*(byte *)(param_1 + 7) & 0xf) * 4);
  }
  (*pcVar1)(param_1);
  return;
}

/* ----------------------------------------------------------------
 * semFlushDefer @ 0x30125360  (примерный размер ~92 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: __errno, objVerify, workQAdd1
 * Вызывают: semFlush
 * Константы: 0xFFFFFFFF, 0x30125360
 * Данные: DAT_30125600, DAT_30125608, DAT_3012561c
 * ---------------------------------------------------------------- */
undefined4 semFlushDefer(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = objVerify(param_1,*DAT_30125600);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(DAT_3012561c + (uint)*(byte *)(param_1 + 0x40) * 4);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30125608;
    return 0xffffffff;
  }
  workQAdd1(iVar1,param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * semFlush @ 0x301253BC  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: semFlushDefer
 * Вызывают: os_msleep_uninit, os_mutex_uninit
 * Константы: 0x301253BC
 * Данные: DAT_3012560c, DAT_30125614, DAT_30125620
 * ---------------------------------------------------------------- */
void semFlush(uint param_1)

{
  if ((param_1 & 1) == 0) {
    if (*DAT_3012560c == 1) {
      semFlushDefer(param_1);
    }
    else {
      (**(code **)(DAT_30125620 + (*(byte *)(param_1 + 0x40) & 0xf) * 4))(param_1);
    }
  }
  else {
    (**(code **)(DAT_30125620 + (*(byte *)(param_1 + *DAT_30125614 + 7) & 0xf) * 4))();
  }
  return;
}

/* ----------------------------------------------------------------
 * semInvalid @ 0x30125438  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, objVerify
 * Константы: 0x30125438, 0xFFFFFFFF
 * Данные: DAT_30125600, DAT_30125624
 * ---------------------------------------------------------------- */
undefined4 semInvalid(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = objVerify(param_1,*DAT_30125600);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30125624;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * semIntRestrict @ 0x3012546C  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, intContext
 * Константы: 0x3012546C, 0xFFFFFFFF
 * Данные: DAT_30125608
 * ---------------------------------------------------------------- */
undefined4 semIntRestrict(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = intContext();
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30125608;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * semQInit @ 0x30125498  (примерный размер ~208 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 2
 * Вызывает: __errno, qInit
 * Вызывают: semBInit, semCInit, semMInit
 * Константы: 0x30125498, 0xFFFFFFFF
 * Данные: DAT_30125628, DAT_3012562c, DAT_30125630
 * ---------------------------------------------------------------- */
undefined4 semQInit(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = (int)param_2 >> 5 & 1;
  if ((param_2 & 0x40) != 0) {
    uVar3 = uVar3 | 2;
  }
  uVar2 = 0;
  if ((param_2 & 3) == 0) {
    qInit(param_1 + 0x44,*DAT_30125628,uVar3,0,0,0,0,0,0,0,0,0);
  }
  else if ((param_2 & 3) == 1) {
    qInit(param_1 + 0x44,*DAT_3012562c,uVar3,0,0,0,0,0,0,0,0,0);
  }
  else {
    puVar1 = (undefined4 *)__errno();
    uVar2 = 0xffffffff;
    *puVar1 = DAT_30125630;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * semQFlush @ 0x30125568  (примерный размер ~116 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: objVerify, windExit, windPendQFlush
 * Константы: 0x30125568, 0xFFFFFFFF
 * Данные: DAT_30125600, DAT_3012560c
 * ---------------------------------------------------------------- */
undefined4 semQFlush(int param_1)

{
  int iVar1;
  
  iVar1 = objVerify(param_1,*DAT_30125600);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x44) != 0) {
      *DAT_3012560c = 1;
      windPendQFlush(param_1 + 0x44);
      windExit();
    }
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * semQFlushDefer @ 0x301255DC  (примерный размер ~88 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: windPendQFlush
 * Константы: 0x301255DC
 * ---------------------------------------------------------------- */
void semQFlushDefer(int param_1)

{
  if (*(int *)(param_1 + 0x44) != 0) {
    windPendQFlush(param_1 + 0x44,param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * semMGiveKernWork @ 0x30125634  (примерный размер ~304 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: errnoGet, errnoSet, windPendQFlush, windPendQGet, windPrioritySet
 * Константы: 0x30125634, 0xFFFFFFFF
 * Данные: DAT_301266d8, DAT_301266dc
 * ---------------------------------------------------------------- */
undefined4 semMGiveKernWork(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0;
  if ((param_2 & 1) != 0) {
    iVar3 = *(int *)(param_1 + 0x44);
    if (iVar3 != 0) {
      iVar3 = iVar3 + -0x50;
    }
    windPendQGet(param_1 + 0x44);
    *(int *)(param_1 + 0x54) = iVar3;
    if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
      *(int *)(iVar3 + 0xac) = *(int *)(iVar3 + 0xac) + 1;
    }
    *(undefined4 *)(iVar3 + 0x8c) = 0;
    if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
      *(int *)(iVar3 + 0x80) = *(int *)(iVar3 + 0x80) + 1;
      if ((*(int *)(param_1 + 0x44) != 0) &&
         (*(uint *)(*(int *)(param_1 + 0x44) + 0x24) < *(uint *)(iVar3 + 0x78))) {
        *(undefined4 *)(param_1 + 100) = 1;
        *(int *)(iVar3 + 0x84) = *(int *)(iVar3 + 0x84) + 1;
      }
    }
  }
  if ((param_2 & 4) != 0) {
    windPrioritySet(param_3,*(undefined4 *)(param_3 + 0x88));
  }
  if ((param_2 & 2) != 0) {
    windPendQFlush(param_3 + 0xb0);
  }
  if ((param_2 & 8) == 0) {
    return 0;
  }
  uVar1 = errnoGet();
  iVar3 = (*(code *)*DAT_301266d8)(*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
  if (iVar3 == 0) {
    if ((*(byte *)(param_1 + 0x60) & 1) == 0) goto LAB_30125750;
  }
  else if ((*(byte *)(param_1 + 0x41) & 0x10) != 0) {
    uVar2 = 0xffffffff;
    uVar1 = DAT_301266dc;
  }
  *(undefined4 *)(param_1 + 0x5c) = 0;
LAB_30125750:
  errnoSet(uVar1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * semMPendQPut @ 0x30125764  (примерный размер ~168 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: objVerify, windPendQPut, windPrioritySet
 * Константы: 0x30125764, 0xFFFFFFFF
 * Данные: DAT_301266e0
 * ---------------------------------------------------------------- */
undefined4 semMPendQPut(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = windPendQPut(param_1 + 0x44);
  if (iVar1 == 0) {
    iVar3 = *(int *)(param_1 + 0x54);
    iVar1 = objVerify(iVar3,*DAT_301266e0);
    if (((iVar1 == 0) && ((*(byte *)(param_1 + 0x41) & 8) != 0)) &&
       (*(int *)(param_3 + 0x8c) = param_1, *(uint *)(param_3 + 0x74) < *(uint *)(iVar3 + 0x78))) {
      if (*(int *)(param_1 + 100) == 0) {
        *(undefined4 *)(param_1 + 100) = 1;
        *(int *)(iVar3 + 0x84) = *(int *)(iVar3 + 0x84) + 1;
      }
      if (*(uint *)(param_3 + 0x74) < *(uint *)(iVar3 + 0x74)) {
        windPrioritySet(iVar3,*(uint *)(param_3 + 0x74));
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * semMInit @ 0x3012580C  (примерный размер ~140 байт)
 * Модуль: kernel | Вызывают: 14 | Вызывает: 3
 * Вызывает: __errno, objCoreInit, semQInit
 * Вызывают: FUN_300e66ac, dbgInit, jobLibInit, kernelBaseInit, logInit, memPartInit, poolCreate, poolLibInit, selWakeupListInit, semMCreate
 *           ...
 * Константы: 0xFFFFFFFF, 0x3012580C, 0xFFFFFFC2
 * Данные: DAT_301267b8, DAT_301267bc
 * ---------------------------------------------------------------- */
undefined4 semMInit(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (((param_2 & 0xffffffc2) == 0) && ((param_2 & 0xb) != 8)) {
    iVar2 = semQInit();
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined2 *)(param_1 + 0x42) = 0;
    *(char *)(param_1 + 0x41) = (char)param_2;
    *(undefined1 *)(param_1 + 0x40) = 1;
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0;
    *(undefined1 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
    objCoreInit(param_1,*DAT_301267bc);
    return 0;
  }
  puVar1 = (undefined4 *)__errno();
  *puVar1 = DAT_301267b8;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * semMInitialize @ 0x30125898  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: semMInit
 * Вызывают: FUN_300ad5ec, envLibInit
 * Константы: 0x30125898
 * ---------------------------------------------------------------- */
int semMInitialize(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = semMInit(param_1), iVar1 == 0)) {
    return param_1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * semMGive @ 0x301258C8  (примерный размер ~716 байт)
 * Модуль: kernel | Вызывают: 19 | Вызывает: 8
 * Вызывает: __errno, errnoGet, errnoSet, objVerify, windExit, windPendQFlush, windPendQGet, windPrioritySet
 * Вызывают: FUN_300ace48, FUN_300ad9ec, FUN_300ae424, FUN_300ae7f0, FUN_300ae930, FUN_300f2514, FUN_300f2884, memPartAddToPool, memPartFindMax, memPartInfoGet
 *           ...
 * Константы: 0xFFFFFFFF, 0x301258C8
 * Данные: DAT_301266d8, DAT_301266dc, DAT_301267bc, DAT_301267c0, DAT_301267c4, DAT_30126874, DAT_30126878, DAT_3012687c
 * ---------------------------------------------------------------- */
undefined4 semMGive(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if (0 < *DAT_301267c0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_301267c4;
    return 0xffffffff;
  }
  iVar5 = *DAT_30126874;
  iVar2 = objVerify(param_1,*DAT_301267bc);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x54) != iVar5) {
    errnoSet(DAT_30126878);
    return 0xffffffff;
  }
  if (*(short *)(param_1 + 0x42) != 0) {
    *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + (short)DAT_3012687c;
    return 0;
  }
  uVar6 = 0;
  if ((*(byte *)(param_1 + 0x41) & 8) == 0) goto LAB_30125a00;
  if (*(int *)(param_1 + 100) != 0) {
    *(undefined4 *)(param_1 + 100) = 0;
    iVar2 = *(int *)(iVar5 + 0x84) + -1;
    *(int *)(iVar5 + 0x84) = iVar2;
    if (iVar2 == 0) {
      uVar6 = 4;
    }
  }
  iVar2 = *(int *)(iVar5 + 0x80) + -1;
  *(int *)(iVar5 + 0x80) = iVar2;
  if (*(int *)(iVar5 + 0x84) == iVar2) {
    *(int *)(iVar5 + 0x88) = *(int *)(iVar5 + 0x78);
    if ((iVar2 != 0) || (*(int *)(iVar5 + 0x74) == *(int *)(iVar5 + 0x78))) goto LAB_301259f8;
    uVar7 = 4;
  }
  else {
LAB_301259f8:
    uVar7 = 0;
  }
  uVar6 = uVar7 | uVar6;
LAB_30125a00:
  if (*(int *)(param_1 + 0x44) == 0) {
    *(undefined4 *)(param_1 + 0x54) = 0;
    if (*(int *)(param_1 + 0x5c) != 0) {
      uVar6 = uVar6 | 8;
    }
  }
  else {
    uVar6 = uVar6 | 1;
  }
  if ((((*(byte *)(param_1 + 0x41) & 4) != 0) &&
      (iVar2 = *(int *)(iVar5 + 0xac) + -1, *(int *)(iVar5 + 0xac) = iVar2, iVar2 == 0)) &&
     (*(int *)(iVar5 + 0xb0) != 0)) {
    uVar6 = uVar6 | 2;
  }
  if (uVar6 == 0) {
    uVar3 = 0;
  }
  else {
    *DAT_30126a0c = 1;
    uVar3 = 0;
    if ((uVar6 & 1) != 0) {
      iVar2 = *(int *)(param_1 + 0x44);
      if (iVar2 != 0) {
        iVar2 = iVar2 + -0x50;
      }
      windPendQGet(param_1 + 0x44);
      *(int *)(param_1 + 0x54) = iVar2;
      if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
        *(int *)(iVar2 + 0xac) = *(int *)(iVar2 + 0xac) + 1;
      }
      *(undefined4 *)(iVar2 + 0x8c) = 0;
      if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
        *(int *)(iVar2 + 0x80) = *(int *)(iVar2 + 0x80) + 1;
        if ((*(int *)(param_1 + 0x44) != 0) &&
           (*(uint *)(*(int *)(param_1 + 0x44) + 0x24) < *(uint *)(iVar2 + 0x78))) {
          *(undefined4 *)(param_1 + 100) = 1;
          *(int *)(iVar2 + 0x84) = *(int *)(iVar2 + 0x84) + 1;
        }
      }
    }
    if ((uVar6 & 4) != 0) {
      windPrioritySet(iVar5,*(undefined4 *)(iVar5 + 0x88));
    }
    if ((uVar6 & 2) != 0) {
      windPendQFlush(iVar5 + 0xb0);
    }
    if ((uVar6 & 8) != 0) {
      uVar4 = errnoGet();
      iVar2 = (*(code *)*DAT_301266d8)
                        (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
      if (iVar2 == 0) {
        if ((*(byte *)(param_1 + 0x60) & 1) != 0) {
          *(undefined4 *)(param_1 + 0x5c) = 0;
        }
      }
      else {
        if ((*(byte *)(param_1 + 0x41) & 0x10) != 0) {
          uVar3 = 0xffffffff;
          uVar4 = DAT_301266dc;
        }
        *(undefined4 *)(param_1 + 0x5c) = 0;
      }
      errnoSet(uVar4);
    }
    windExit();
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * semMGiveNoLock @ 0x30125B94  (примерный размер ~564 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: errnoGet, errnoSet, windPendQFlush, windPendQGet, windPrioritySet
 * Константы: 0xFFFFFFFF, 0x30125B94
 * Данные: DAT_301266d8, DAT_301266dc, DAT_30126878, DAT_3012687c
 * ---------------------------------------------------------------- */
undefined4 semMGiveNoLock(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (*(int *)(param_1 + 0x54) != param_2) {
    errnoSet(DAT_30126878);
    return 0xffffffff;
  }
  if (*(short *)(param_1 + 0x42) != 0) {
    *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + (short)DAT_3012687c;
    return 0;
  }
  uVar2 = 0;
  if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
    if (*(int *)(param_1 + 100) != 0) {
      *(undefined4 *)(param_1 + 100) = 0;
      iVar3 = *(int *)(param_2 + 0x84) + -1;
      *(int *)(param_2 + 0x84) = iVar3;
      if (iVar3 == 0) {
        uVar2 = 4;
      }
    }
    iVar3 = *(int *)(param_2 + 0x80) + -1;
    *(int *)(param_2 + 0x80) = iVar3;
    if (*(int *)(param_2 + 0x84) == iVar3) {
      *(int *)(param_2 + 0x88) = *(int *)(param_2 + 0x78);
      if ((iVar3 != 0) || (*(int *)(param_2 + 0x74) == *(int *)(param_2 + 0x78))) goto LAB_30125c48;
      uVar4 = 4;
    }
    else {
LAB_30125c48:
      uVar4 = 0;
    }
    uVar2 = uVar4 | uVar2;
  }
  iVar3 = *(int *)(param_1 + 0x44);
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x54) = 0;
    if (*(int *)(param_1 + 0x5c) != 0) {
      uVar2 = uVar2 | 8;
    }
  }
  else {
    uVar2 = uVar2 | 1;
  }
  if ((((*(byte *)(param_1 + 0x41) & 4) != 0) &&
      (iVar5 = *(int *)(param_2 + 0xac) + -1, *(int *)(param_2 + 0xac) = iVar5, iVar5 == 0)) &&
     (*(int *)(param_2 + 0xb0) != 0)) {
    uVar2 = uVar2 | 2;
  }
  if (uVar2 == 0) {
    return 0;
  }
  uVar6 = 0;
  if ((uVar2 & 1) != 0) {
    if (iVar3 != 0) {
      iVar3 = iVar3 + -0x50;
    }
    windPendQGet(param_1 + 0x44);
    *(int *)(param_1 + 0x54) = iVar3;
    if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
      *(int *)(iVar3 + 0xac) = *(int *)(iVar3 + 0xac) + 1;
    }
    *(undefined4 *)(iVar3 + 0x8c) = 0;
    if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
      *(int *)(iVar3 + 0x80) = *(int *)(iVar3 + 0x80) + 1;
      if ((*(int *)(param_1 + 0x44) != 0) &&
         (*(uint *)(*(int *)(param_1 + 0x44) + 0x24) < *(uint *)(iVar3 + 0x78))) {
        *(undefined4 *)(param_1 + 100) = 1;
        *(int *)(iVar3 + 0x84) = *(int *)(iVar3 + 0x84) + 1;
      }
    }
  }
  if ((uVar2 & 4) != 0) {
    windPrioritySet(param_2,*(undefined4 *)(param_2 + 0x88));
  }
  if ((uVar2 & 2) != 0) {
    windPendQFlush(param_2 + 0xb0);
  }
  if ((uVar2 & 8) == 0) {
    return 0;
  }
  uVar1 = errnoGet();
  iVar3 = (*(code *)*DAT_301266d8)(*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
  if (iVar3 == 0) {
    if ((*(byte *)(param_1 + 0x60) & 1) == 0) goto LAB_30125db4;
  }
  else if ((*(byte *)(param_1 + 0x41) & 0x10) != 0) {
    uVar6 = 0xffffffff;
    uVar1 = DAT_301266dc;
  }
  *(undefined4 *)(param_1 + 0x5c) = 0;
LAB_30125db4:
  errnoSet(uVar1);
  return uVar6;
}

/* ----------------------------------------------------------------
 * semMTakeNoLock @ 0x30125DC8  (примерный размер ~288 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: errnoSet, objVerify, windPendQPut, windPrioritySet
 * Константы: 0xFFFFFFFF, 0x30125DC8
 * Данные: DAT_301266e0, DAT_30126a38
 * ---------------------------------------------------------------- */
undefined4 semMTakeNoLock(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x54) == 0) {
    *(int *)(param_1 + 0x54) = param_3;
    if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
      *(int *)(param_3 + 0x80) = *(int *)(param_3 + 0x80) + 1;
    }
    if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
      *(int *)(param_3 + 0xac) = *(int *)(param_3 + 0xac) + 1;
    }
    return 0;
  }
  if (*(int *)(param_1 + 0x54) == param_3) {
    *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
    return 0;
  }
  if (param_2 == 0) {
    errnoSet(DAT_30126a38);
    return 0xffffffff;
  }
  iVar1 = windPendQPut(param_1 + 0x44);
  if (iVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x54);
    iVar1 = objVerify(iVar2,*DAT_301266e0);
    if (((iVar1 == 0) && ((*(byte *)(param_1 + 0x41) & 8) != 0)) &&
       (*(int *)(param_3 + 0x8c) = param_1, *(uint *)(param_3 + 0x74) < *(uint *)(iVar2 + 0x78))) {
      if (*(int *)(param_1 + 100) == 0) {
        *(undefined4 *)(param_1 + 100) = 1;
        *(int *)(iVar2 + 0x84) = *(int *)(iVar2 + 0x84) + 1;
      }
      if (*(uint *)(param_3 + 0x74) < *(uint *)(iVar2 + 0x74)) {
        windPrioritySet(iVar2,*(uint *)(param_3 + 0x74));
      }
    }
    return 2;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * semMTake @ 0x30125EE8  (примерный размер ~488 байт)
 * Модуль: kernel | Вызывают: 18 | Вызывает: 6
 * Вызывает: __errno, errnoSet, objVerify, windExit, windPendQPut, windPrioritySet
 * Вызывают: FUN_300ace48, FUN_300ad768, FUN_300ad9ec, FUN_300ae424, FUN_300ae7f0, FUN_300ae930, FUN_300f2198, FUN_300f2514, FUN_300f2884, memPartReallocInternal
 *           ...
 * Константы: 0x30125EE8
 * Данные: DAT_301266e0, DAT_301267bc, DAT_301267c0, DAT_301267c4, DAT_30126874, DAT_30126a0c, DAT_30126a38, DAT_30126a3c
 * ---------------------------------------------------------------- */
int semMTake(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*DAT_301267c0 < 1) {
    iVar3 = *DAT_30126874;
    do {
      iVar2 = objVerify(param_1,*DAT_301267bc);
      if (iVar2 != 0) {
        return -1;
      }
      if (*(int *)(param_1 + 0x54) == 0) {
        *(int *)(param_1 + 0x54) = iVar3;
        if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
          *(int *)(iVar3 + 0x80) = *(int *)(iVar3 + 0x80) + 1;
        }
        if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
          *(int *)(iVar3 + 0xac) = *(int *)(iVar3 + 0xac) + 1;
        }
        return 0;
      }
      if (*(int *)(param_1 + 0x54) == iVar3) {
        *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
        return 0;
      }
      if (param_2 == 0) {
        errnoSet(DAT_30126a38);
        return -1;
      }
      *DAT_30126a0c = 1;
      iVar2 = windPendQPut(param_1 + 0x44,param_2);
      if (iVar2 != 0) {
        windExit();
        return -1;
      }
      iVar4 = *(int *)(param_1 + 0x54);
      iVar2 = objVerify(iVar4,*DAT_301266e0);
      if (((iVar2 == 0) && ((*(byte *)(param_1 + 0x41) & 8) != 0)) &&
         (*(int *)(iVar3 + 0x8c) = param_1, *(uint *)(iVar3 + 0x74) < *(uint *)(iVar4 + 0x78))) {
        if (*(int *)(param_1 + 100) == 0) {
          *(undefined4 *)(param_1 + 100) = 1;
          *(int *)(iVar4 + 0x84) = *(int *)(iVar4 + 0x84) + 1;
        }
        if (*(uint *)(iVar3 + 0x74) < *(uint *)(iVar4 + 0x74)) {
          windPrioritySet(iVar4);
        }
      }
      iVar2 = windExit();
      if (iVar2 != 1) {
        return iVar2;
      }
      param_2 = (*(code *)*DAT_30126a3c)(param_2);
    } while (param_2 != 0);
    errnoSet(DAT_30126a40);
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_301267c4;
  }
  return -1;
}

/* ----------------------------------------------------------------
 * semMGiveScalable @ 0x301260D0  (примерный размер ~820 байт)
 * Модуль: kernel | Вызывают: 10 | Вызывает: 8
 * Вызывает: __errno, errnoGet, errnoSet, objVerify, windExit, windPendQFlush, windPendQGet, windPrioritySet
 * Вызывают: FUN_300e17dc, FUN_300e18e4, envGet, envPrivateCreate, envPrivateDestroy, envShow, getenv, putenv, taskEach, taskListCount
 * Константы: 0xFFFFFFFF, 0x301260D0
 * Данные: DAT_301266d8, DAT_301266dc, DAT_301267b8, DAT_301267bc, DAT_301267c0, DAT_301267c4, DAT_30126874, DAT_30126878
 * ---------------------------------------------------------------- */
undefined4 semMGiveScalable(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  bool bVar8;
  char in_CY;
  char in_OV;
  bool bVar9;
  byte in_Q;
  undefined8 uVar10;
  
  uVar5 = 0;
  if ((param_2 & DAT_30126a44) != 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_301267b8;
    return 0xffffffff;
  }
  bVar9 = (param_2 & 0x80) == 0;
  bVar8 = false;
  if (bVar9) {
    iVar7 = *DAT_301267c0;
    bVar8 = iVar7 < 0;
    bVar9 = iVar7 == 0;
    in_CY = '\x01';
    in_OV = '\0';
    if (0 < iVar7) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = DAT_301267c4;
      return 0xffffffff;
    }
  }
  iVar7 = *DAT_30126874;
  uVar3 = (uint)(byte)(bVar8 << 4 | bVar9 << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b | 0x80;
  if ((param_2 & 0x40) == 0) {
    uVar10 = objVerify(param_1,*DAT_301267bc);
    uVar3 = (uint)((ulonglong)uVar10 >> 0x20);
    if ((int)uVar10 != 0) {
      return 0xffffffff;
    }
  }
  if ((param_2 & 0x80) == 0) {
    if ((*(byte *)(param_1 + 0x41) & 0xc) != (param_2 & 0xc)) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = DAT_301267b8;
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0x54) != iVar7) {
      errnoSet(DAT_30126878);
      return 0xffffffff;
    }
  }
  if ((param_2 & 0x400) == 0) {
    uVar3 = (uint)*(ushort *)(param_1 + 0x42);
    if (uVar3 != 0) {
      *(ushort *)(param_1 + 0x42) = *(ushort *)(param_1 + 0x42) + (short)DAT_3012687c;
      return 0;
    }
  }
  if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
    if (*(int *)(param_1 + 100) != 0) {
      *(undefined4 *)(param_1 + 100) = 0;
      iVar4 = *(int *)(iVar7 + 0x84) + -1;
      *(int *)(iVar7 + 0x84) = iVar4;
      if (iVar4 == 0) {
        uVar5 = 4;
      }
    }
    uVar3 = *(int *)(iVar7 + 0x80) - 1;
    *(uint *)(iVar7 + 0x80) = uVar3;
    if (*(uint *)(iVar7 + 0x84) == uVar3) {
      *(int *)(iVar7 + 0x88) = *(int *)(iVar7 + 0x78);
      if ((uVar3 == 0) && (*(int *)(iVar7 + 0x74) != *(int *)(iVar7 + 0x78))) {
        uVar5 = 4;
      }
    }
  }
  if (*(int *)(param_1 + 0x44) == 0) {
    *(undefined4 *)(param_1 + 0x54) = 0;
    if (((param_2 & 0x100) == 0) && (*(int *)(param_1 + 0x5c) != 0)) {
      uVar5 = uVar5 | 8;
    }
  }
  else {
    uVar5 = uVar5 | 1;
  }
  if ((((*(byte *)(param_1 + 0x41) & 4) != 0) &&
      (iVar4 = *(int *)(iVar7 + 0xac) + -1, *(int *)(iVar7 + 0xac) = iVar4, iVar4 == 0)) &&
     (*(int *)(iVar7 + 0xb0) != 0)) {
    uVar5 = uVar5 | 2;
  }
  if (uVar5 == 0) {
    uVar6 = 0;
  }
  else {
    *DAT_30126a0c = 1;
    uVar6 = 0;
    if ((uVar5 & 1) != 0) {
      iVar4 = *(int *)(param_1 + 0x44);
      if (iVar4 != 0) {
        iVar4 = iVar4 + -0x50;
      }
      windPendQGet(param_1 + 0x44,uVar3);
      *(int *)(param_1 + 0x54) = iVar4;
      if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
        *(int *)(iVar4 + 0xac) = *(int *)(iVar4 + 0xac) + 1;
      }
      *(undefined4 *)(iVar4 + 0x8c) = 0;
      if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
        *(int *)(iVar4 + 0x80) = *(int *)(iVar4 + 0x80) + 1;
        if ((*(int *)(param_1 + 0x44) != 0) &&
           (*(uint *)(*(int *)(param_1 + 0x44) + 0x24) < *(uint *)(iVar4 + 0x78))) {
          *(undefined4 *)(param_1 + 100) = 1;
          *(int *)(iVar4 + 0x84) = *(int *)(iVar4 + 0x84) + 1;
        }
      }
    }
    if ((uVar5 & 4) != 0) {
      windPrioritySet(iVar7,*(undefined4 *)(iVar7 + 0x88));
    }
    if ((uVar5 & 2) != 0) {
      windPendQFlush(iVar7 + 0xb0);
    }
    if ((uVar5 & 8) != 0) {
      uVar2 = errnoGet();
      iVar7 = (*(code *)*DAT_301266d8)
                        (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
      if (iVar7 == 0) {
        if ((*(byte *)(param_1 + 0x60) & 1) != 0) {
          *(undefined4 *)(param_1 + 0x5c) = 0;
        }
      }
      else {
        if ((*(byte *)(param_1 + 0x41) & 0x10) != 0) {
          uVar6 = 0xffffffff;
          uVar2 = DAT_301266dc;
        }
        *(undefined4 *)(param_1 + 0x5c) = 0;
      }
      errnoSet(uVar2);
    }
    windExit();
  }
  return uVar6;
}

/* ----------------------------------------------------------------
 * semMTakeScalable @ 0x30126404  (примерный размер ~580 байт)
 * Модуль: kernel | Вызывают: 11 | Вызывает: 6
 * Вызывает: __errno, errnoSet, objVerify, windExit, windPendQPut, windPrioritySet
 * Вызывают: FUN_300e17dc, FUN_300e18e4, FUN_300e67b4, envGet, envPrivateCreate, envPrivateDestroy, envShow, getenv, putenv, taskEach
 *           ...
 * Константы: 0xFFFFFF00, 0x30126404
 * Данные: DAT_301266e0, DAT_301267b8, DAT_301267bc, DAT_301267c0, DAT_301267c4, DAT_30126874, DAT_30126a0c, DAT_30126a38
 * ---------------------------------------------------------------- */
int semMTakeScalable(int param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  char in_CY;
  char in_OV;
  char cVar6;
  byte in_Q;
  uint in_cpsr;
  uint uVar7;
  ulonglong uVar8;
  
  if ((param_3 & DAT_30126a44) == 0) {
    cVar6 = (param_3 & 0x80) == 0;
    cVar5 = false;
    if ((bool)cVar6) {
      iVar3 = *DAT_301267c0;
      cVar5 = iVar3 < 0;
      cVar6 = iVar3 == 0;
      in_CY = '\x01';
      in_OV = '\0';
      if (0 < iVar3) {
        puVar1 = (undefined4 *)__errno();
        *puVar1 = DAT_301267c4;
        return -1;
      }
    }
    iVar3 = *DAT_30126874;
    while( true ) {
      iVar2 = (uint)(byte)(cVar5 << 4 | cVar6 << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
      uVar8 = CONCAT44(iVar2,iVar2) | 0x8000000000;
      uVar7 = in_cpsr & 0xffffff00;
      if (((param_3 & 0x40) == 0) && (uVar8 = objVerify(param_1,*DAT_301267bc), (int)uVar8 != 0)) {
        return -1;
      }
      if (((param_3 & 0x80) == 0) && ((*(byte *)(param_1 + 0x41) & 0xc) != (param_3 & 0xc))) {
        puVar1 = (undefined4 *)__errno((int)uVar8,(int)(uVar8 >> 0x20));
        *puVar1 = DAT_301267b8;
        return -1;
      }
      if (*(int *)(param_1 + 0x54) == 0) break;
      if (((param_3 & 0x400) == 0) && (*(int *)(param_1 + 0x54) == iVar3)) {
        *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
        return 0;
      }
      if (param_2 == 0) {
        errnoSet(DAT_30126a38);
        return -1;
      }
      *DAT_30126a0c = 1;
      in_cpsr = uVar7 & 0xffffff00;
      in_Q = (uVar7 >> 0x1b & 1) != 0;
      iVar2 = windPendQPut(param_1 + 0x44,param_2);
      if (iVar2 != 0) {
        windExit();
        return -1;
      }
      iVar4 = *(int *)(param_1 + 0x54);
      iVar2 = objVerify(iVar4,*DAT_301266e0);
      if (((iVar2 == 0) && ((*(byte *)(param_1 + 0x41) & 8) != 0)) &&
         (*(int *)(iVar3 + 0x8c) = param_1, *(uint *)(iVar3 + 0x74) < *(uint *)(iVar4 + 0x78))) {
        if (*(int *)(param_1 + 100) == 0) {
          *(undefined4 *)(param_1 + 100) = 1;
          *(int *)(iVar4 + 0x84) = *(int *)(iVar4 + 0x84) + 1;
        }
        if (*(uint *)(iVar3 + 0x74) < *(uint *)(iVar4 + 0x74)) {
          windPrioritySet(iVar4);
        }
      }
      iVar2 = windExit();
      in_CY = iVar2 != 0;
      in_OV = SBORROW4(iVar2,1);
      cVar5 = iVar2 + -1 < 0;
      cVar6 = iVar2 == 1;
      if (!(bool)cVar6) {
        return iVar2;
      }
      param_2 = (*(code *)*DAT_30126a3c)(param_2);
    }
    *(int *)(param_1 + 0x54) = iVar3;
    if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
      *(int *)(iVar3 + 0x80) = *(int *)(iVar3 + 0x80) + 1;
    }
    if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
      *(int *)(iVar3 + 0xac) = *(int *)(iVar3 + 0xac) + 1;
    }
    iVar3 = 0;
  }
  else {
    puVar1 = (undefined4 *)__errno();
    iVar3 = -1;
    *puVar1 = DAT_301267b8;
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * semMTakeByProxy @ 0x30126648  (примерный размер ~192 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: __errno, objVerify
 * Вызывают: FUN_300e2e10
 * Константы: 0xFFFFFFFF, 0x30126648
 * Данные: DAT_301266e0, DAT_301267bc, DAT_30126a48
 * ---------------------------------------------------------------- */
undefined4 semMTakeByProxy(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_2 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30126a48;
    return 0xffffffff;
  }
  iVar2 = objVerify(param_1,*DAT_301267bc);
  if ((iVar2 == 0) && (iVar2 = objVerify(param_2,*DAT_301266e0), iVar2 == 0)) {
    if (*(int *)(param_1 + 0x54) != 0) {
      return 0xffffffff;
    }
    *(int *)(param_1 + 0x54) = param_2;
    if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
      *(int *)(param_2 + 0x80) = *(int *)(param_2 + 0x80) + 1;
    }
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * semMGiveForce @ 0x30126708  (примерный размер ~848 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 9
 * Вызывает: __errno, errnoGet, errnoSet, objVerify, semMGive, windExit, windPendQFlush, windPendQGet, windPrioritySet
 * Вызывают: FUN_30111224
 * Константы: 0xFFFFFFFF, 0x30126708
 * Данные: DAT_301267bc, DAT_301267c0, DAT_301267c4, DAT_30126874, DAT_30126a0c, DAT_30126a4c, DAT_30126a50, DAT_30126a54
 * ---------------------------------------------------------------- */
undefined4 semMGiveForce(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = 0;
  uVar6 = 0;
  if (0 < *DAT_301267c0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_301267c4;
    return 0xffffffff;
  }
  iVar2 = objVerify(param_1,*DAT_301267bc);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  iVar2 = *(int *)(param_1 + 0x54);
  if (iVar2 == 0) {
    return 0;
  }
  *(undefined2 *)(param_1 + 0x42) = 0;
  if (*DAT_30126874 == iVar2) {
    uVar5 = semMGive(param_1);
    return uVar5;
  }
  iVar3 = objVerify(iVar2,*DAT_30126a4c);
  *DAT_30126a0c = 1;
  if (iVar3 != 0) {
    if (*(int *)(param_1 + 0x44) == 0) {
      *(undefined4 *)(param_1 + 0x54) = 0;
      if (*(int *)(param_1 + 0x5c) != 0) {
        uVar6 = 8;
      }
    }
    else {
      uVar6 = 1;
    }
    goto LAB_30126904;
  }
  uVar6 = 0;
  if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
    if (*(int *)(param_1 + 100) != 0) {
      *(undefined4 *)(param_1 + 100) = 0;
      iVar3 = *(int *)(iVar2 + 0x84) + -1;
      *(int *)(iVar2 + 0x84) = iVar3;
      if (iVar3 == 0) {
        uVar6 = 4;
      }
    }
    iVar3 = *(int *)(iVar2 + 0x80) + -1;
    *(int *)(iVar2 + 0x80) = iVar3;
    if (*(int *)(iVar2 + 0x84) == iVar3) {
      *(int *)(iVar2 + 0x88) = *(int *)(iVar2 + 0x78);
      if ((iVar3 != 0) || (*(int *)(iVar2 + 0x74) == *(int *)(iVar2 + 0x78))) goto LAB_30126880;
      uVar7 = 4;
    }
    else {
LAB_30126880:
      uVar7 = 0;
    }
    uVar6 = uVar7 | uVar6;
  }
  if (*(int *)(param_1 + 0x44) == 0) {
    *(undefined4 *)(param_1 + 0x54) = 0;
    if (*(int *)(param_1 + 0x5c) != 0) {
      uVar6 = uVar6 | 8;
    }
  }
  else {
    uVar6 = uVar6 | 1;
  }
  if ((((*(byte *)(param_1 + 0x41) & 4) != 0) &&
      (iVar3 = *(int *)(iVar2 + 0xac) + -1, *(int *)(iVar2 + 0xac) = iVar3, iVar3 == 0)) &&
     (*(int *)(iVar2 + 0xb0) != 0)) {
    uVar6 = uVar6 | 2;
  }
LAB_30126904:
  *(undefined4 *)(param_1 + 100) = 0;
  if (uVar6 != 0) {
    uVar5 = 0;
    if ((uVar6 & 1) != 0) {
      iVar3 = *(int *)(param_1 + 0x44);
      if (iVar3 != 0) {
        iVar3 = iVar3 + -0x50;
      }
      windPendQGet(param_1 + 0x44);
      *(int *)(param_1 + 0x54) = iVar3;
      if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
        *(int *)(iVar3 + 0xac) = *(int *)(iVar3 + 0xac) + 1;
      }
      *(undefined4 *)(iVar3 + 0x8c) = 0;
      if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
        *(int *)(iVar3 + 0x80) = *(int *)(iVar3 + 0x80) + 1;
        if ((*(int *)(param_1 + 0x44) != 0) &&
           (*(uint *)(*(int *)(param_1 + 0x44) + 0x24) < *(uint *)(iVar3 + 0x78))) {
          *(undefined4 *)(param_1 + 100) = 1;
          *(int *)(iVar3 + 0x84) = *(int *)(iVar3 + 0x84) + 1;
        }
      }
    }
    if ((uVar6 & 4) != 0) {
      windPrioritySet(iVar2,*(undefined4 *)(iVar2 + 0x88));
    }
    if ((uVar6 & 2) != 0) {
      windPendQFlush(iVar2 + 0xb0);
    }
    if ((uVar6 & 8) != 0) {
      uVar4 = errnoGet();
      iVar2 = (*(code *)*DAT_30126a50)
                        (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
      if (iVar2 == 0) {
        if ((*(byte *)(param_1 + 0x60) & 1) != 0) {
          *(undefined4 *)(param_1 + 0x5c) = 0;
        }
      }
      else {
        if ((*(byte *)(param_1 + 0x41) & 0x10) != 0) {
          uVar5 = 0xffffffff;
          uVar4 = DAT_30126a54;
        }
        *(undefined4 *)(param_1 + 0x5c) = 0;
      }
      errnoSet(uVar4);
    }
  }
  windExit();
  return uVar5;
}

/* ----------------------------------------------------------------
 * semRWInitialize @ 0x30126A58  (примерный размер ~348 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 4
 * Вызывает: __errno, bzero, objCoreInit, qInit
 * Вызывают: semRWCreate
 * Константы: 0x30126A58, 0xFFFFFFC2
 * Данные: DAT_30127a10, DAT_30127a14, DAT_30127a18, DAT_30127a1c, DAT_30127b2c
 * ---------------------------------------------------------------- */
int semRWInitialize(int param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((((param_2 & 0xffffffc2) == 0) && (param_1 != 0)) && ((param_2 & 0xb) != 8)) {
    if (param_3 == 0) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = DAT_30127a10;
      param_1 = 0;
    }
    else {
      if (*DAT_30127a14 < param_3) {
        param_3 = *DAT_30127a14;
      }
      *(uint *)(param_1 + 0x68) = param_3;
      if ((param_2 & 3) == 0) {
        uVar3 = *DAT_30127a18;
      }
      else {
        uVar3 = *DAT_30127a1c;
      }
      uVar2 = (int)param_2 >> 5 & 1;
      qInit(param_1 + 0x44,uVar3,uVar2,0,0,0,0,0,0,0,0,0);
      qInit(param_1 + 0x70,uVar3,uVar2,0,0,0,0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x6c) = 0;
      *(undefined4 *)(param_1 + 0x54) = 0;
      *(char *)(param_1 + 0x41) = (char)param_2;
      *(undefined1 *)(param_1 + 0x40) = 6;
      *(undefined2 *)(param_1 + 0x42) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined4 *)(param_1 + 0x58) = 0;
      *(undefined1 *)(param_1 + 0x60) = 0;
      bzero((void *)(param_1 + 0x80),*(int *)(param_1 + 0x68) * 0xc);
      *(undefined4 *)(param_1 + 100) = 0;
      objCoreInit(param_1,*DAT_30127b2c);
    }
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30127a10;
    param_1 = 0;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * semRWGive @ 0x30126BB4  (примерный размер ~1348 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 7
 * Вызывает: __errno, errnoSet, objVerify, windExit, windPendQFlush, windPendQGet, windPrioritySet
 * Вызывают: semRWGiveForce
 * Константы: 0xFFFFFFFF, 0x30126BB4
 * Данные: DAT_30127b2c, DAT_30127b30, DAT_30127b34, DAT_30127b38, DAT_30127b3c, DAT_30127b40, DAT_30127cb4, DAT_30127cb8
 * ---------------------------------------------------------------- */
undefined4 semRWGive(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *extraout_r1;
  int *extraout_r1_00;
  int *extraout_r1_01;
  int *extraout_r1_02;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint unaff_r7;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined4 local_24;
  int local_20;
  
  uVar6 = 0;
  if (0 < *DAT_30127b30) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30127b34;
    return 0xffffffff;
  }
  iVar7 = *DAT_30127b38;
  uVar10 = objVerify(param_1,*DAT_30127b2c);
  piVar3 = (int *)((ulonglong)uVar10 >> 0x20);
  if ((int)uVar10 != 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x54) == 0) {
    iVar8 = *(int *)(param_1 + 0x6c);
    if (iVar8 == 0) {
      errnoSet(DAT_30127b3c);
      return 0xffffffff;
    }
    iVar4 = *(int *)(param_1 + 0x68);
    if (iVar4 != 0) {
      piVar3 = (int *)(param_1 + 0x80);
      do {
        if (*piVar3 == iVar7) {
          if (piVar3[1] != 0) {
            piVar3[1] = piVar3[1] + -1;
            return 0;
          }
          *piVar3 = 0;
          *(int *)(param_1 + 0x6c) = iVar8 + -1;
          if (piVar3[2] != 0) {
            piVar3[2] = 0;
            iVar8 = *(int *)(iVar7 + 0x84) + -1;
            *(int *)(iVar7 + 0x84) = iVar8;
            if (iVar8 == 0) {
              uVar6 = 8;
            }
          }
          if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
            iVar8 = *(int *)(iVar7 + 0x80) + -1;
            *(int *)(iVar7 + 0x80) = iVar8;
            if (*(int *)(iVar7 + 0x84) == iVar8) {
              piVar3 = *(int **)(iVar7 + 0x78);
              *(int **)(iVar7 + 0x88) = piVar3;
              if ((iVar8 != 0) || (*(int **)(iVar7 + 0x74) == piVar3)) goto LAB_30126df8;
              uVar9 = 8;
            }
            else {
LAB_30126df8:
              uVar9 = 0;
            }
            uVar6 = uVar9 | uVar6;
          }
          if (*(int *)(param_1 + 0x6c) == 0) goto LAB_30126e3c;
          if (*(int *)(param_1 + 0x70) == 0) goto LAB_30126e68;
          iVar8 = *(int *)(param_1 + 0x44);
          goto joined_r0x30126e20;
        }
        piVar3 = piVar3 + 3;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    errnoSet(DAT_30127b3c);
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x54) != iVar7) {
    errnoSet(DAT_30127b3c);
    return 0xffffffff;
  }
  if (*(short *)(param_1 + 0x42) != 0) {
    *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + (short)DAT_30127b40;
    return 0;
  }
  if (*(int *)(param_1 + 100) != 0) {
    *(undefined4 *)(param_1 + 100) = 0;
    iVar8 = *(int *)(iVar7 + 0x84) + -1;
    *(int *)(iVar7 + 0x84) = iVar8;
    if (iVar8 == 0) {
      uVar6 = 8;
    }
  }
  if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
    iVar8 = *(int *)(iVar7 + 0x80) + -1;
    *(int *)(iVar7 + 0x80) = iVar8;
    if (*(int *)(iVar7 + 0x84) == iVar8) {
      piVar3 = *(int **)(iVar7 + 0x78);
      *(int **)(iVar7 + 0x88) = piVar3;
      if ((iVar8 != 0) || (*(int **)(iVar7 + 0x74) == piVar3)) goto LAB_30126cec;
      uVar9 = 8;
    }
    else {
LAB_30126cec:
      uVar9 = 0;
    }
    uVar6 = uVar9 | uVar6;
  }
LAB_30126e3c:
  iVar8 = *(int *)(param_1 + 0x44);
  *(int *)(param_1 + 0x54) = iVar8;
  if (iVar8 == 0) {
    iVar8 = *(int *)(param_1 + 0x70);
joined_r0x30126e20:
    if (iVar8 == 0) goto LAB_30126e64;
  }
  else {
    *(int *)(param_1 + 0x54) = iVar8 + -0x50;
LAB_30126e64:
    uVar6 = uVar6 | 1;
  }
LAB_30126e68:
  if ((((*(byte *)(param_1 + 0x41) & 4) != 0) &&
      (iVar8 = *(int *)(iVar7 + 0xac) + -1, *(int *)(iVar7 + 0xac) = iVar8, iVar8 == 0)) &&
     (*(int *)(iVar7 + 0xb0) != 0)) {
    uVar6 = uVar6 | 2;
  }
  if (uVar6 == 0) {
    return 0;
  }
  *DAT_30127cb4 = 1;
  if ((uVar6 & 1) == 0) goto LAB_301270bc;
  if (*(int *)(param_1 + 0x44) != 0) {
    windPendQGet(param_1 + 0x44);
    if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
      piVar3 = (int *)(*(int *)(param_1 + 0x54) + 0xac);
      *piVar3 = *piVar3 + 1;
    }
    iVar8 = *(int *)(param_1 + 0x54);
    *(undefined4 *)(iVar8 + 0x8c) = 0;
    piVar3 = extraout_r1;
    if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
      *(int *)(iVar8 + 0x80) = *(int *)(iVar8 + 0x80) + 1;
      if (*(int *)(param_1 + 0x44) == 0) {
        uVar9 = 0xffffffff;
      }
      else {
        uVar9 = *(uint *)(*(int *)(param_1 + 0x44) + 0x24);
      }
      piVar3 = *(int **)(param_1 + 0x70);
      if (piVar3 != (int *)0x0) {
        puVar1 = (uint *)(piVar3 + 9);
        piVar3 = piVar3 + -0x14;
        if (*puVar1 < uVar9) {
          uVar9 = *puVar1;
        }
      }
      if (uVar9 < *(uint *)(iVar8 + 0x78)) {
        *(undefined4 *)(param_1 + 100) = 1;
        *(int *)(iVar8 + 0x84) = *(int *)(iVar8 + 0x84) + 1;
        if (uVar9 < *(uint *)(iVar8 + 0x74)) {
          windPrioritySet(iVar8,uVar9);
          piVar3 = extraout_r1_00;
        }
      }
    }
    goto LAB_301270bc;
  }
  if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
    local_24 = 1;
    local_20 = (*(int *)(param_1 + 0x68) - *(int *)(param_1 + 0x6c)) + 1;
    if (local_20 != 0) {
      uVar10 = (**(code **)(*(int *)(param_1 + 0x7c) + 0x34))(param_1 + 0x70,DAT_30127cb8,&local_24)
      ;
      piVar3 = (int *)((ulonglong)uVar10 >> 0x20);
      if ((int)uVar10 != 0) {
        unaff_r7 = *(uint *)((int)uVar10 + 0x24);
        goto LAB_30126ff0;
      }
    }
    unaff_r7 = 0xffffffff;
  }
LAB_30126ff0:
  while (iVar8 = *(int *)(param_1 + 0x70), iVar8 != 0) {
    iVar4 = *(int *)(param_1 + 0x6c);
    uVar5 = iVar4 + 1;
    *(uint *)(param_1 + 0x6c) = uVar5;
    uVar9 = *(uint *)(param_1 + 0x68);
    if ((uVar9 < uVar5) || (uVar9 == 0)) {
LAB_301270b0:
      *(int *)(param_1 + 0x6c) = iVar4;
      break;
    }
    piVar3 = (int *)(param_1 + 0x80);
    while (*piVar3 != 0) {
      piVar3 = piVar3 + 3;
      uVar9 = uVar9 - 1;
      if (uVar9 == 0) {
        piVar3 = (int *)0x0;
        goto LAB_301270b0;
      }
    }
    *piVar3 = iVar8 + -0x50;
    windPendQGet(param_1 + 0x70);
    piVar3 = extraout_r1_01;
    if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
      piVar3 = (int *)(*(int *)(iVar8 + 0x5c) + 1);
      *(int **)(iVar8 + 0x5c) = piVar3;
    }
    if (((*(byte *)(param_1 + 0x41) & 8) != 0) &&
       (*(int *)(iVar8 + 0x30) = *(int *)(iVar8 + 0x30) + 1, unaff_r7 < *(uint *)(iVar8 + 0x28))) {
      *(undefined4 *)(param_1 + 100) = 1;
      *(int *)(iVar8 + 0x34) = *(int *)(iVar8 + 0x34) + 1;
    }
  }
LAB_301270bc:
  if ((uVar6 & 8) != 0) {
    windPrioritySet(iVar7,*(undefined4 *)(iVar7 + 0x88));
    piVar3 = extraout_r1_02;
  }
  if ((uVar6 & 2) != 0) {
    windPendQFlush(*DAT_30127b38 + 0xb0,piVar3);
  }
  windExit();
  return 0;
}

/* ----------------------------------------------------------------
 * semWTake @ 0x301270F8  (примерный размер ~696 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 6
 * Вызывает: __errno, errnoSet, objVerify, windExit, windPendQPut, windPrioritySet
 * Константы: 0x301270F8
 * Данные: DAT_30127b2c, DAT_30127b30, DAT_30127b34, DAT_30127b38, DAT_30127b3c, DAT_30127cb4, DAT_30127cbc, DAT_30127cc0
 * ---------------------------------------------------------------- */
int semWTake(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  if (*DAT_30127b30 < 1) {
    iVar7 = *DAT_30127b38;
    while ((iVar2 = objVerify(param_1,*DAT_30127b2c), iVar2 == 0 &&
           (*(char *)(param_1 + 0x40) == '\x06'))) {
      if ((*(int *)(param_1 + 0x54) == 0) && (*(int *)(param_1 + 0x6c) == 0)) {
        *(int *)(param_1 + 0x54) = iVar7;
        if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
          *(int *)(iVar7 + 0x80) = *(int *)(iVar7 + 0x80) + 1;
        }
        if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
          *(int *)(iVar7 + 0xac) = *(int *)(iVar7 + 0xac) + 1;
        }
        return 0;
      }
      if (*(int *)(param_1 + 0x54) == iVar7) {
        *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
        return 0;
      }
      if ((*(int *)(param_1 + 0x6c) != 0) && (iVar2 = *(int *)(param_1 + 0x68), iVar2 != 0)) {
        piVar5 = (int *)(param_1 + 0x80);
        do {
          if (*piVar5 == iVar7) {
            errnoSet(DAT_30127b3c);
            return -1;
          }
          piVar5 = piVar5 + 3;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      if (param_2 == 0) {
        errnoSet(DAT_30127cc0);
        return -1;
      }
      *DAT_30127cb4 = 1;
      iVar2 = windPendQPut(param_1 + 0x44,param_2);
      if (iVar2 != 0) {
        windExit();
        return -1;
      }
      if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
        iVar2 = *(int *)(param_1 + 0x54);
        uVar8 = 0;
        if (iVar2 == 0) {
          iVar6 = *(int *)(param_1 + 0x6c);
          iVar2 = *(int *)(param_1 + 0x80);
          piVar5 = (int *)(param_1 + 0x88);
        }
        else {
          piVar5 = (int *)(param_1 + 100);
          iVar6 = 1;
          uVar8 = *(uint *)(param_1 + 0x68);
        }
        *(int *)(iVar7 + 0x8c) = param_1;
        iVar4 = uVar8 * 0xc + param_1;
        while (iVar6 != 0) {
          if ((iVar2 != 0) && (iVar3 = objVerify(iVar2,*DAT_30127cc4), iVar3 == 0)) {
            if (*(uint *)(iVar7 + 0x74) < *(uint *)(iVar2 + 0x78)) {
              if (*piVar5 == 0) {
                *piVar5 = 1;
                *(int *)(iVar2 + 0x84) = *(int *)(iVar2 + 0x84) + 1;
              }
              if (*(uint *)(iVar7 + 0x74) < *(uint *)(iVar2 + 0x74)) {
                windPrioritySet(iVar2);
              }
            }
            iVar6 = iVar6 + -1;
          }
          uVar8 = uVar8 + 1;
          if (*(uint *)(param_1 + 0x68) <= uVar8) break;
          iVar2 = *(int *)(iVar4 + 0x8c);
          piVar5 = (int *)(iVar4 + 0x94);
          iVar4 = iVar4 + 0xc;
        }
      }
      iVar2 = windExit();
      if (iVar2 != 1) {
        return iVar2;
      }
      param_2 = (*(code *)*DAT_30127cc8)(param_2);
    }
    errnoSet(DAT_30127cbc);
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30127b34;
  }
  return -1;
}

/* ----------------------------------------------------------------
 * semRTake @ 0x301273B0  (примерный размер ~852 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 6
 * Вызывает: __errno, errnoSet, objVerify, windExit, windPendQPut, windPrioritySet
 * Константы: 0x301273B0
 * Данные: DAT_30127b2c, DAT_30127b30, DAT_30127b34, DAT_30127b38, DAT_30127b3c, DAT_30127cb4, DAT_30127cbc, DAT_30127cc0
 * ---------------------------------------------------------------- */
int semRTake(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  if (*DAT_30127b30 < 1) {
    iVar6 = *DAT_30127b38;
    while ((iVar2 = objVerify(param_1,*DAT_30127b2c), iVar2 == 0 &&
           (*(char *)(param_1 + 0x40) == '\x06'))) {
      if (*(int *)(param_1 + 0x54) == iVar6) {
        errnoSet(DAT_30127b3c);
        return -1;
      }
      iVar2 = *(int *)(param_1 + 0x6c);
      if ((iVar2 != 0) && (iVar4 = *(int *)(param_1 + 0x68), iVar4 != 0)) {
        piVar8 = (int *)(param_1 + 0x80);
        do {
          if (*piVar8 == iVar6) {
            piVar8[1] = piVar8[1] + 1;
            return 0;
          }
          piVar8 = piVar8 + 3;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      if (((*(int *)(param_1 + 0x54) == 0) && (iVar2 == 0)) ||
         ((iVar2 != 0 && ((*(int *)(param_1 + 0x44) == 0 && (*(int *)(param_1 + 0x70) == 0)))))) {
        *(uint *)(param_1 + 0x6c) = iVar2 + 1U;
        uVar5 = *(uint *)(param_1 + 0x68);
        if ((iVar2 + 1U <= uVar5) && (uVar5 != 0)) {
          piVar8 = (int *)(param_1 + 0x80);
          do {
            if (*piVar8 == 0) {
              *piVar8 = iVar6;
              if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
                *(int *)(iVar6 + 0x80) = *(int *)(iVar6 + 0x80) + 1;
              }
              if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
                *(int *)(iVar6 + 0xac) = *(int *)(iVar6 + 0xac) + 1;
              }
              return 0;
            }
            piVar8 = piVar8 + 3;
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
        *(int *)(param_1 + 0x6c) = iVar2;
      }
      if (param_2 == 0) {
        errnoSet(DAT_30127cc0);
        return -1;
      }
      *DAT_30127cb4 = 1;
      iVar2 = windPendQPut(param_1 + 0x70,param_2);
      if (iVar2 != 0) {
        windExit();
        return -1;
      }
      if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
        iVar2 = *(int *)(param_1 + 0x54);
        uVar5 = 0;
        if (iVar2 == 0) {
          iVar4 = *(int *)(param_1 + 0x6c);
          iVar2 = *(int *)(param_1 + 0x80);
          piVar8 = (int *)(param_1 + 0x88);
        }
        else {
          piVar8 = (int *)(param_1 + 100);
          iVar4 = 1;
          uVar5 = *(uint *)(param_1 + 0x68);
        }
        *(int *)(iVar6 + 0x8c) = param_1;
        iVar7 = uVar5 * 0xc + param_1;
        while (iVar4 != 0) {
          if ((iVar2 != 0) && (iVar3 = objVerify(iVar2,*DAT_30127cc4), iVar3 == 0)) {
            if (*(uint *)(iVar6 + 0x74) < *(uint *)(iVar2 + 0x78)) {
              if (*piVar8 == 0) {
                *piVar8 = 1;
                *(int *)(iVar2 + 0x84) = *(int *)(iVar2 + 0x84) + 1;
              }
              if (*(uint *)(iVar6 + 0x74) < *(uint *)(iVar2 + 0x74)) {
                windPrioritySet(iVar2);
              }
            }
            iVar4 = iVar4 + -1;
          }
          uVar5 = uVar5 + 1;
          if (*(uint *)(param_1 + 0x68) <= uVar5) break;
          iVar2 = *(int *)(iVar7 + 0x8c);
          piVar8 = (int *)(iVar7 + 0x94);
          iVar7 = iVar7 + 0xc;
        }
      }
      iVar2 = windExit();
      if (iVar2 != 1) {
        return iVar2;
      }
      param_2 = (*(code *)*DAT_30127cc8)(param_2);
    }
    errnoSet(DAT_30127cbc);
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30127b34;
  }
  return -1;
}

/* ----------------------------------------------------------------
 * semRWGiveForce @ 0x30127704  (примерный размер ~1480 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 8
 * Вызывает: __errno, bzero, objVerify, semRWGive, windExit, windPendQFlush, windPendQGet, windPrioritySet
 * Константы: 0xFFFFFFFF, 0x30127704, 0x30127C7C, 0x30127C98
 * Данные: DAT_30127b2c, DAT_30127b30, DAT_30127b34, DAT_30127b38, DAT_30127cb4, DAT_30127cb8, DAT_30127cc4
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x30127c7c) */
/* WARNING: Removing unreachable block (ram,0x30127c98) */

undefined4 semRWGiveForce(int param_1)

{
  byte bVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint unaff_r5;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  bool bVar11;
  undefined4 local_2c;
  int local_28;
  
  bVar11 = false;
  bVar2 = false;
  if (0 < *DAT_30127b30) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = DAT_30127b34;
    return 0xffffffff;
  }
  iVar4 = objVerify(param_1,*DAT_30127b2c);
  if (iVar4 != 0) {
    return 0xffffffff;
  }
  if ((*(int *)(param_1 + 0x54) == 0) && (*(int *)(param_1 + 0x6c) == 0)) {
    return 0;
  }
  *(undefined2 *)(param_1 + 0x42) = 0;
  if (*DAT_30127b38 == *(int *)(param_1 + 0x54)) {
    uVar5 = semRWGive(param_1);
    return uVar5;
  }
  *DAT_30127cb4 = 1;
  iVar4 = *(int *)(param_1 + 0x54);
  if ((iVar4 != 0) && (iVar6 = objVerify(iVar4,*DAT_30127cc4), iVar6 == 0)) {
    if (((*(byte *)(param_1 + 0x41) & 4) != 0) &&
       ((iVar6 = *(int *)(iVar4 + 0xac) + -1, *(int *)(iVar4 + 0xac) = iVar6, iVar6 == 0 &&
        (*(int *)(iVar4 + 0xb0) != 0)))) {
      windPendQFlush(iVar4 + 0xb0);
    }
    if (*(int *)(param_1 + 100) == 0) {
      if ((*(byte *)(param_1 + 0x41) & 8) != 0) goto LAB_3012784c;
    }
    else {
      iVar6 = *(int *)(iVar4 + 0x84) + -1;
      bVar11 = iVar6 == 0;
      *(int *)(iVar4 + 0x84) = iVar6;
LAB_3012784c:
      iVar6 = *(int *)(iVar4 + 0x80) + -1;
      *(int *)(iVar4 + 0x80) = iVar6;
      if (*(int *)(iVar4 + 0x84) == iVar6) {
        *(int *)(iVar4 + 0x88) = *(int *)(iVar4 + 0x78);
        if ((iVar6 != 0) || (*(int *)(iVar4 + 0x74) == *(int *)(iVar4 + 0x78))) goto LAB_30127890;
        bVar1 = 1;
      }
      else {
LAB_30127890:
        bVar1 = 0;
      }
      bVar11 = (bool)(bVar1 | bVar11);
    }
    if (bVar11) {
      windPrioritySet(iVar4,*(undefined4 *)(iVar4 + 0x88));
    }
  }
  *(undefined4 *)(param_1 + 100) = 0;
  uVar8 = 0;
  bVar11 = false;
  while ((*(int *)(param_1 + 0x6c) != 0 && (uVar8 < *(uint *)(param_1 + 0x68)))) {
    iVar4 = uVar8 * 0xc + param_1;
    iVar6 = *(int *)(iVar4 + 0x80);
    if ((iVar6 != 0) && (iVar7 = objVerify(iVar6,*DAT_30127cc4), iVar7 == 0)) {
      if ((((*(byte *)(param_1 + 0x41) & 4) != 0) &&
          (iVar7 = *(int *)(iVar6 + 0xac) + -1, *(int *)(iVar6 + 0xac) = iVar7, iVar7 == 0)) &&
         (*(int *)(iVar6 + 0xb0) != 0)) {
        windPendQFlush(iVar6 + 0xb0);
      }
      if (*(int *)(iVar4 + 0x88) == 0) {
        if ((*(byte *)(param_1 + 0x41) & 8) != 0) goto LAB_30127958;
      }
      else {
        iVar7 = *(int *)(iVar6 + 0x84) + -1;
        *(int *)(iVar6 + 0x84) = iVar7;
        if (iVar7 == 0) {
          bVar11 = true;
        }
LAB_30127958:
        iVar7 = *(int *)(iVar6 + 0x80) + -1;
        *(int *)(iVar6 + 0x80) = iVar7;
        if (*(int *)(iVar6 + 0x84) == iVar7) {
          *(int *)(iVar6 + 0x88) = *(int *)(iVar6 + 0x78);
          if ((iVar7 != 0) || (*(int *)(iVar6 + 0x74) == *(int *)(iVar6 + 0x78))) goto LAB_3012799c;
          bVar1 = 1;
        }
        else {
LAB_3012799c:
          bVar1 = 0;
        }
        bVar11 = (bool)(bVar1 | bVar11);
      }
      if (bVar11) {
        windPrioritySet(iVar6,*(undefined4 *)(iVar6 + 0x88));
      }
      *(undefined4 *)(iVar4 + 0x88) = 0;
      uVar8 = uVar8 + 1;
      *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;
    }
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  bzero((void *)(param_1 + 0x80),*(int *)(param_1 + 0x68) * 0xc);
  iVar4 = *(int *)(param_1 + 0x44);
  *(int *)(param_1 + 0x54) = iVar4;
  if (iVar4 == 0) {
    if (*(int *)(param_1 + 0x70) == 0) goto LAB_30127a3c;
    iVar6 = 0;
  }
  else {
    iVar6 = iVar4 + -0x50;
  }
  *(int *)(param_1 + 0x54) = iVar6;
  bVar2 = true;
LAB_30127a3c:
  if (bVar2) {
    if (bVar2) {
      if (iVar4 == 0) {
        if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
          local_2c = 1;
          local_28 = (*(int *)(param_1 + 0x68) - *(int *)(param_1 + 0x6c)) + 1;
          if ((local_28 == 0) ||
             (iVar4 = (**(code **)(*(int *)(param_1 + 0x7c) + 0x34))
                                (param_1 + 0x70,DAT_30127cb8,&local_2c), iVar4 == 0)) {
            unaff_r5 = 0xffffffff;
          }
          else {
            unaff_r5 = *(uint *)(iVar4 + 0x24);
          }
        }
        while (iVar4 = *(int *)(param_1 + 0x70), iVar4 != 0) {
          iVar6 = *(int *)(param_1 + 0x6c);
          uVar9 = iVar6 + 1;
          *(uint *)(param_1 + 0x6c) = uVar9;
          uVar8 = *(uint *)(param_1 + 0x68);
          if ((uVar8 < uVar9) || (uVar8 == 0)) {
LAB_30127c68:
            *(int *)(param_1 + 0x6c) = iVar6;
            break;
          }
          piVar10 = (int *)(param_1 + 0x80);
          while (*piVar10 != 0) {
            piVar10 = piVar10 + 3;
            uVar8 = uVar8 - 1;
            if (uVar8 == 0) goto LAB_30127c68;
          }
          *piVar10 = iVar4 + -0x50;
          windPendQGet(param_1 + 0x70);
          if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
            *(int *)(iVar4 + 0x5c) = *(int *)(iVar4 + 0x5c) + 1;
          }
          if (((*(byte *)(param_1 + 0x41) & 8) != 0) &&
             (*(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1,
             unaff_r5 < *(uint *)(iVar4 + 0x28))) {
            *(undefined4 *)(param_1 + 100) = 1;
            *(int *)(iVar4 + 0x34) = *(int *)(iVar4 + 0x34) + 1;
          }
        }
      }
      else {
        windPendQGet(param_1 + 0x44);
        if ((*(byte *)(param_1 + 0x41) & 4) != 0) {
          piVar10 = (int *)(*(int *)(param_1 + 0x54) + 0xac);
          *piVar10 = *piVar10 + 1;
        }
        iVar4 = *(int *)(param_1 + 0x54);
        *(undefined4 *)(iVar4 + 0x8c) = 0;
        if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
          *(int *)(iVar4 + 0x80) = *(int *)(iVar4 + 0x80) + 1;
          if (*(int *)(param_1 + 0x44) == 0) {
            uVar8 = 0xffffffff;
          }
          else {
            uVar8 = *(uint *)(*(int *)(param_1 + 0x44) + 0x24);
          }
          if ((*(int *)(param_1 + 0x70) != 0) &&
             (uVar9 = *(uint *)(*(int *)(param_1 + 0x70) + 0x24), uVar9 < uVar8)) {
            uVar8 = uVar9;
          }
          if (uVar8 < *(uint *)(iVar4 + 0x78)) {
            *(undefined4 *)(param_1 + 100) = 1;
            *(int *)(iVar4 + 0x84) = *(int *)(iVar4 + 0x84) + 1;
            if (uVar8 < *(uint *)(iVar4 + 0x74)) {
              windPrioritySet(iVar4,uVar8);
            }
          }
        }
      }
    }
    windExit();
  }
  else {
    windExit();
  }
  return 0;
}

/* ----------------------------------------------------------------
 * semBCreate @ 0x30127CCC  (примерный размер ~116 байт)
 * Модуль: kernel | Вызывают: 26 | Вызывает: 3
 * Вызывает: objAlloc, objFree, semBInit
 * Вызывают: BSP_DLOAD_Init, BSP_HKADC_GetTempInit, Create_Intr_Thread, FUN_30009f84, FUN_30060598, FUN_300cb558, HI6451_init, OSAL_SemBCreate, WDT_SoftWdInit, dosFsCacheCreate
 *           ...
 * Константы: 0x30127CCC
 * Данные: DAT_30127d3c
 * ---------------------------------------------------------------- */
int semBCreate(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = objAlloc(*DAT_30127d3c);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = semBInit(iVar1,param_1,param_2);
  if (iVar2 != 0) {
    objFree(*DAT_30127d3c,iVar1);
    return 0;
  }
  *(ushort *)(iVar1 + 8) = *(ushort *)(iVar1 + 8) | 2;
  return iVar1;
}

/* ----------------------------------------------------------------
 * semCCreate @ 0x30127D40  (примерный размер ~116 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 3
 * Вызывает: objAlloc, objFree, semCInit
 * Вызывают: FUN_300c1ff8, OSAL_SemCCreate, dosFsDevCreate
 * Константы: 0x30127D40
 * Данные: DAT_30127db0
 * ---------------------------------------------------------------- */
int semCCreate(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = objAlloc(*DAT_30127db0);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = semCInit(iVar1,param_1,param_2);
  if (iVar2 != 0) {
    objFree(*DAT_30127db0,iVar1);
    return 0;
  }
  *(ushort *)(iVar1 + 8) = *(ushort *)(iVar1 + 8) | 2;
  return iVar1;
}

/* ----------------------------------------------------------------
 * semMCreate @ 0x30127DB4  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 34 | Вызывает: 3
 * Вызывает: objAlloc, objFree, semMInit
 * Вызывают: FUN_30060598, FUN_300c1a54, FUN_300cb558, FUN_300db20c, FUN_30111c28, FUN_301124fc, OSAL_SemMCreate, SPI_Init, __diab_alloc_mutex, __diab_alloc_semaphore
 *           ...
 * Константы: 0x30127DB4
 * Данные: DAT_30127e1c
 * ---------------------------------------------------------------- */
int semMCreate(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = objAlloc(*DAT_30127e1c);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = semMInit(iVar1,param_1);
  if (iVar2 != 0) {
    objFree(*DAT_30127e1c,iVar1);
    return 0;
  }
  *(ushort *)(iVar1 + 8) = *(ushort *)(iVar1 + 8) | 2;
  return iVar1;
}

/* ----------------------------------------------------------------
 * semRWCreate @ 0x30127E20  (примерный размер ~184 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: errnoSet, objAllocExtra, objFree, semRWInitialize
 * Константы: 0x30127E20
 * Данные: DAT_30127ecc, DAT_30127ed0, DAT_30127ed4
 * ---------------------------------------------------------------- */
int semRWCreate(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_14 [4];
  
  if (param_2 == 0) {
    errnoSet(DAT_30127ecc);
    iVar1 = 0;
  }
  else {
    if (*DAT_30127ed0 < param_2) {
      param_2 = *DAT_30127ed0;
    }
    iVar1 = objAllocExtra(*DAT_30127ed4,param_2 * 0xc + 0x18,auStack_14);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar2 = semRWInitialize(iVar1,param_1,param_2);
      if (iVar2 == 0) {
        objFree(*DAT_30127ed4,iVar1);
        iVar1 = 0;
      }
      else {
        *(ushort *)(iVar1 + 8) = *(ushort *)(iVar1 + 8) | 2;
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * taskOptionsSet @ 0x30127ED8  (примерный размер ~192 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 5
 * Вызывает: __errno, intContext, taskCpuLock, taskCpuUnlock, taskTcb
 * Вызывают: FUN_300e17dc, envPrivateCreate, envPrivateDestroy
 * Константы: 0xFFFFFFFF, 0x30127ED8
 * Данные: DAT_301281ec, DAT_301281f0, DAT_301281f4
 * ---------------------------------------------------------------- */
undefined4 taskOptionsSet(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = intContext();
  if (iVar1 == 0) {
    taskCpuLock();
    iVar1 = taskTcb(param_1);
    if (iVar1 == 0) {
      taskCpuUnlock();
      uVar3 = 0xffffffff;
    }
    else {
      *(uint *)(iVar1 + 0x98) = param_3 | *(uint *)(iVar1 + 0x98) & ~param_2;
      if (((((param_2 & 2) != 0) || ((param_3 & 2) != 0)) &&
          ((param_1 == 0 || (*DAT_301281f0 == param_1)))) && ((code *)*DAT_301281f4 != (code *)0x0))
      {
        (*(code *)*DAT_301281f4)(param_1);
      }
      taskCpuUnlock();
      uVar3 = 0;
    }
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_301281ec;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * taskOptionsGet @ 0x30127F98  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: taskTcb
 * Константы: 0x30127F98, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 taskOptionsGet(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  *param_2 = *(undefined4 *)(iVar1 + 0x98);
  return 0;
}

/* ----------------------------------------------------------------
 * taskBpHookSet @ 0x30127FC4  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300c69b0
 * Константы: 0x30127FC4
 * Данные: DAT_301281f4
 * ---------------------------------------------------------------- */
void taskBpHookSet(undefined4 param_1)

{
  *DAT_301281f4 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * taskRegsGet @ 0x30127FD0  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 23 | Вызывает: 2
 * Вызывает: bcopy, taskTcb
 * Вызывают: FUN_300f5e28, FUN_30114a38, _dbgTaskPCGet, _dbgTaskPCSet, cpsr, dbgStackTrace, pc, r0, r1, r10
 *           ...
 * Константы: 0x30127FD0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 taskRegsGet(undefined4 param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if (*(void **)(iVar1 + 0x120) != (void *)0x0) {
    bcopy(*(void **)(iVar1 + 0x120),(void *)(iVar1 + 0x1d0),0x48);
    *(undefined4 *)(iVar1 + 0x120) = 0;
  }
  bcopy((void *)(iVar1 + 0x1d0),param_2,0x48);
  return 0;
}

/* ----------------------------------------------------------------
 * taskRegsSet @ 0x30128030  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 2
 * Вызывает: bcopy, taskTcb
 * Вызывают: FUN_300c8154, _dbgTaskPCSet, taskRegsModify
 * Константы: 0x30128030, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 taskRegsSet(undefined4 param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  bcopy(param_2,(void *)(iVar1 + 0x1d0),0x48);
  return 0;
}

/* ----------------------------------------------------------------
 * taskName @ 0x30128064  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 13 | Вызывает: 2
 * Вызывает: objNamePtrGet, taskTcb
 * Вызывают: CvTaskNameget, FUN_300a8104, FUN_300c906c, FUN_301148fc, FUN_30115590, bd, eventRsrcShow, exchStackTrace, logTask, shellInternalTaskNameMatch
 *           ...
 * Константы: 0x30128064
 * Данные: DAT_301281f8
 * ---------------------------------------------------------------- */
int taskName(void)

{
  int iVar1;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = objNamePtrGet(iVar1);
    if (iVar1 == 0) {
      iVar1 = DAT_301281f8;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * taskIdDefault @ 0x30128088  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 19 | Вызывает: 0
 * Вызывают: cpsr, excExcHandle, r0, r1, r10, r11, r12, r13, r14, r2
 *           ...
 * Константы: 0x30128088
 * Данные: DAT_301281fc
 * ---------------------------------------------------------------- */
int taskIdDefault(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_301281fc;
  if (param_1 != 0) {
    *DAT_301281fc = param_1;
  }
  return *piVar1;
}

/* ----------------------------------------------------------------
 * taskIsReady @ 0x301280A8  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskTcb
 * Вызывают: FUN_300f5e28
 * Константы: 0x301280A8
 * ---------------------------------------------------------------- */
undefined4 taskIsReady(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = taskTcb();
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x70) != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * taskIsSuspended @ 0x301280D4  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 1
 * Вызывает: taskTcb
 * Вызывают: dbgStackTrace, exchStackTrace, shellBackgroundInit
 * Константы: 0x301280D4
 * ---------------------------------------------------------------- */
bool taskIsSuspended(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = taskTcb();
  bVar2 = iVar1 == 0;
  if (!bVar2) {
    bVar2 = (*(uint *)(iVar1 + 0x70) & 1) == 0;
  }
  return !bVar2;
}

/* ----------------------------------------------------------------
 * taskIsStopped @ 0x301280F8  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 1
 * Вызывает: taskTcb
 * Вызывают: FUN_300f5e28, FUN_30114978, dbgStackTrace, exchStackTrace, vxdbgTaskCont, vxdbgTaskStep, vxdbgTaskStop
 * Константы: 0x301280F8
 * ---------------------------------------------------------------- */
bool taskIsStopped(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = taskTcb();
  bVar2 = iVar1 == 0;
  if (!bVar2) {
    bVar2 = (*(uint *)(iVar1 + 0x70) & 0x10) == 0;
  }
  return !bVar2;
}

/* ----------------------------------------------------------------
 * taskIsPended @ 0x3012811C  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: taskTcb
 * Вызывают: FUN_300f5e28, shellBackgroundInit
 * Константы: 0x3012811C
 * ---------------------------------------------------------------- */
bool taskIsPended(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = taskTcb();
  bVar2 = iVar1 == 0;
  if (!bVar2) {
    bVar2 = (*(uint *)(iVar1 + 0x70) & 2) == 0;
  }
  return !bVar2;
}

/* ----------------------------------------------------------------
 * taskIsDelayed @ 0x30128140  (примерный размер ~112 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: taskTcb
 * Константы: 0x30128140
 * Данные: DAT_30128200
 * ---------------------------------------------------------------- */
undefined4 taskIsDelayed(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = taskTcb();
  if ((iVar1 == 0) || ((*(uint *)(iVar1 + 0x70) & 4) == 0)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
    }
    uVar2 = 0;
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      uVar2 = (**(code **)(*(int *)(DAT_30128200 + 0xc) + 0x28))(iVar1 + 0x40,1);
      *param_2 = uVar2;
    }
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * taskPriNormalGet @ 0x301281B0  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: taskTcb
 * Константы: 0xFFFFFFFF, 0x301281B0
 * ---------------------------------------------------------------- */
undefined4 taskPriNormalGet(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  *param_2 = *(undefined4 *)(iVar1 + 0x78);
  return 0;
}

/* ----------------------------------------------------------------
 * taskCreateLibInit @ 0x30128204  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrKernelCoreInit
 * Константы: 0x30128204
 * Данные: DAT_30129180, DAT_30129184, DAT_30129188, DAT_3012918c
 * ---------------------------------------------------------------- */
void taskCreateLibInit(void)

{
  *(undefined4 *)(*DAT_30129180 + 0x14) = DAT_30129184;
  *DAT_3012918c = DAT_30129188;
  return;
}

/* ----------------------------------------------------------------
 * taskInit @ 0x30128224  (примерный размер ~524 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: free, memPartAlignedAlloc, taskInitExcStk
 * Вызывают: taskCreateWithGuard
 * Константы: 0xFFFFFFFF, 0x30128224, 0xFFFFFFFC
 * Данные: DAT_30129190, DAT_30129194, DAT_30129198, DAT_3012919c, DAT_301291a0, DAT_301291a4, DAT_301291a8, DAT_30129250
 * ---------------------------------------------------------------- */
undefined4
taskInit(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5,
        undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
        undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
        undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint local_2c;
  void *local_28;
  
  if (*DAT_30129190 == 0) {
    iVar2 = *DAT_30129194;
  }
  else {
    iVar2 = *(int *)(*DAT_30129190 + 0x94);
  }
  *(int *)(param_1 + 0x94) = iVar2;
  if (*DAT_30129194 == iVar2) {
    iVar3 = *DAT_30129198;
    uVar1 = *DAT_3012919c;
  }
  else {
    iVar3 = *DAT_301291a0;
    uVar1 = *DAT_301291a4;
  }
  local_2c = iVar3 + 3U & 0xfffffffc;
  if ((code *)*DAT_301291a8 == (code *)0x0) {
    local_28 = (void *)memPartAlignedAlloc(*DAT_30129250,local_2c,4);
    if (local_28 == (void *)0x0) {
      return 0xffffffff;
    }
  }
  else {
    iVar2 = (*(code *)*DAT_301291a8)
                      (iVar2,local_2c,uVar1,0,param_4 & 0x4000 | 9,&local_2c,&local_28);
    if (iVar2 == -1) {
      return 0xffffffff;
    }
  }
  local_28 = (void *)((int)local_28 + local_2c);
  iVar2 = taskInitExcStk(param_1,param_2,param_3,param_4 | 0x1000,param_5,param_6,local_28,local_2c,
                         param_7,param_8,param_9,param_10,param_11,param_12,param_13,param_14,
                         param_15,param_16,param_17);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    local_28 = (void *)((int)local_28 - local_2c);
    if ((code *)*DAT_30129254 == (code *)0x0) {
      free(local_28);
    }
    else {
      (*(code *)*DAT_30129254)(param_1,local_28,local_2c,uVar1,0,param_4 & 0x4000 | 9);
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * taskCreateWithGuard @ 0x30128430  (примерный размер ~880 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 8
 * Вызывает: __errno, intCpuLock, intCpuUnlock, objAllocExtra, objFree, strcpy, strlen, taskInit
 * Вызывают: taskCreate
 * Константы: 0x30128430, 0xFFFFFFFC
 * Данные: DAT_30129180, DAT_30129190, DAT_30129194, DAT_301291a8, DAT_30129254, DAT_30129258, DAT_3012925c, DAT_30129260
 * ---------------------------------------------------------------- */
int taskCreateWithGuard(char *param_1,undefined4 param_2,uint param_3,uint param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                       undefined4 param_9,undefined4 param_10,undefined4 param_11,
                       undefined4 param_12,undefined4 param_13,undefined4 param_14,
                       undefined4 param_15,undefined4 param_16)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  undefined4 *puVar4;
  int iVar5;
  size_t sVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  size_t sVar10;
  undefined4 uVar11;
  int iVar12;
  int local_50;
  int *local_4c;
  char acStack_48 [11];
  char acStack_3d [21];
  uint local_4;
  
  iVar12 = 5;
  pcVar7 = acStack_48;
  pcVar9 = DAT_30129258;
  local_4 = param_4;
  do {
    pcVar8 = pcVar9 + 1;
    cVar1 = *pcVar9;
    iVar12 = iVar12 + -1;
    pcVar9 = pcVar9 + 2;
    cVar2 = *pcVar8;
    pcVar8 = pcVar7 + 1;
    *pcVar7 = cVar1;
    pcVar7 = pcVar7 + 2;
    *pcVar8 = cVar2;
  } while (iVar12 != 0);
  cVar1 = *pcVar9;
  *pcVar7 = cVar1;
  if ((param_3 & DAT_3012925c) == 0) {
    if ((int)local_4 < 0) {
      puVar4 = (undefined4 *)__errno(cVar1,cVar2,acStack_48);
      *puVar4 = DAT_30129264;
      iVar5 = 0;
    }
    else {
      if (param_1 == (char *)0x0) {
        strcpy(acStack_3d + 1,(char *)*DAT_30129268);
        sVar6 = strlen(acStack_3d + 1);
        intCpuLock();
        local_4c = DAT_3012926c;
        iVar12 = *DAT_3012926c;
        *DAT_3012926c = iVar12 + 1;
        intCpuUnlock();
        pcVar7 = acStack_3d + sVar6;
        sVar3 = sVar6;
        do {
          sVar10 = sVar3;
          pcVar7 = pcVar7 + 1;
          iVar5 = (int)((longlong)iVar12 * (longlong)DAT_30129270 >> 0x22) - (iVar12 >> 0x1f);
          *pcVar7 = acStack_48[iVar12 + iVar5 * -10];
          sVar3 = sVar10 + 1;
          iVar12 = iVar5;
        } while (iVar5 != 0);
        pcVar9 = acStack_3d + sVar10 + 1;
        pcVar7 = acStack_3d + sVar6 + 1;
        if (acStack_3d + sVar6 + 1 < pcVar9) {
          do {
            cVar1 = *pcVar7;
            pcVar8 = pcVar7 + 1;
            *pcVar7 = *pcVar9;
            *pcVar9 = cVar1;
            pcVar9 = pcVar9 + -1;
            pcVar7 = pcVar8;
          } while (pcVar8 < pcVar9);
        }
        acStack_3d[sVar10 + 2] = '\0';
        param_1 = acStack_3d + 1;
      }
      local_4 = local_4 + 3 & 0xfffffffc;
      iVar12 = *DAT_30129194;
      if (*DAT_30129190 != 0) {
        iVar12 = *(int *)(*DAT_30129190 + 0x94);
      }
      if (*DAT_30129194 == iVar12) {
        uVar11 = *DAT_30129274;
      }
      else {
        uVar11 = *DAT_30129278;
      }
      if (*DAT_301291a8 == 0) {
        local_50 = objAllocExtra(*DAT_30129180,local_4,0);
        if (local_50 == 0) {
          return 0;
        }
        param_3 = param_3 | 0x8000;
        iVar12 = local_50 + local_4;
        iVar5 = iVar12;
      }
      else {
        iVar5 = objAllocExtra(*DAT_30129180,0,0);
        if (iVar5 == 0) {
          return 0;
        }
        iVar12 = (*(code *)*DAT_301291a8)
                           (iVar12,local_4,param_5,uVar11,param_3 & 0x4000 | 5,&local_4,&local_50);
        if (iVar12 == -1) {
          objFree(*DAT_30129180,iVar5);
          return 0;
        }
        iVar12 = local_50 + local_4;
        *(undefined4 *)(iVar5 + 0x15c) = param_5;
        param_3 = param_3 | DAT_3012927c;
      }
      iVar12 = taskInit(iVar5,param_1,param_2,param_3,iVar12,local_4,param_6,param_7,param_8,param_9
                        ,param_10,param_11,param_12,param_13,param_14,param_15,param_16);
      if (iVar12 != 0) {
        iVar12 = local_50;
        if ((code *)*DAT_30129254 != (code *)0x0) {
          (*(code *)*DAT_30129254)(iVar5,local_50,local_4,param_5,uVar11,param_3 & 0x4000 | 5);
          iVar12 = iVar5;
        }
        objFree(*DAT_30129180,iVar12);
        iVar5 = 0;
      }
    }
  }
  else {
    puVar4 = (undefined4 *)__errno(cVar1,cVar2,acStack_48);
    *puVar4 = DAT_30129260;
    iVar5 = 0;
  }
  return iVar5;
}

/* ----------------------------------------------------------------
 * taskCreate @ 0x301287A0  (примерный размер ~172 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 1
 * Вызывает: taskCreateWithGuard
 * Вызывают: shellGenericInit, taskCreat, taskSpawn
 * Константы: 0x301287A0
 * ---------------------------------------------------------------- */
void taskCreate(void)

{
  taskCreateWithGuard();
  return;
}

/* ----------------------------------------------------------------
 * taskSpawn @ 0x3012884C  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 24 | Вызывает: 2
 * Вызывает: taskActivate, taskCreate
 * Вызывают: BSP_DRV_BOOTROM_Init, BSP_HKADC_GetTempInit, BSP_TLED_LedInit, Create_Intr_Thread, FUN_30009f84, FUN_300c1ff8, FUN_30110d64, HI6451_init, TFUP_CheckInit, WDT_SoftWdInit
 *           ...
 * Константы: 0x3012884C
 * ---------------------------------------------------------------- */
int taskSpawn(void)

{
  int iVar1;
  
  iVar1 = taskCreate();
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else {
    taskActivate(iVar1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * taskCreat @ 0x301288D4  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: taskCreate
 * Константы: 0x301288D4
 * ---------------------------------------------------------------- */
void taskCreat(void)

{
  taskCreate();
  return;
}

/* ----------------------------------------------------------------
 * FUN_30128940 @ 0x30128940  (примерный размер ~1132 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 16
 * Вызывает: __errno, atomic32Dec, free, memAddToPool, objClassIdGet, objCoreInvalidate, objCoreReclaim, objCoreUnlink, objFree, objNamePtrSet, objVerify, taskUnsafe, windDelete, windExit
 *           ...
 * Вызывают: taskDestroy
 * Константы: 0xFFFFFF00, 0x30128940
 * Данные: DAT_30129180, DAT_30129190, DAT_30129194, DAT_3012919c, DAT_301291a4, DAT_30129254, DAT_30129274, DAT_30129278
 * ---------------------------------------------------------------- */
undefined4 FUN_30128940(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte in_Q;
  byte bVar12;
  uint in_cpsr;
  
  cVar10 = param_3 < 0;
  cVar11 = param_3 == 0;
  cVar8 = '\x01';
  cVar9 = '\0';
  if (!(bool)cVar11) {
    *DAT_30129288 = 1;
    windSuspend(param_1);
    windExit();
    *(int *)(*DAT_30129190 + 0xac) = *(int *)(*DAT_30129190 + 0xac) + 1;
  }
  puVar2 = DAT_30129180;
  objCoreUnlink(param_1,*DAT_30129180);
  objNamePtrSet(param_1,0);
  uVar4 = (uint)(byte)(cVar10 << 4 | cVar11 << 3 | cVar8 << 2 | cVar9 << 1 | in_Q) << 0x1b | 0x80;
  in_cpsr = in_cpsr & 0xffffff00;
  if (*(int *)(param_1 + 0xc) != 0) goto LAB_301289d0;
  iVar7 = *(int *)(param_1 + 0x34);
  while (iVar7 != 0) {
LAB_301289d0:
    do {
      bVar12 = (in_cpsr >> 0x1b & 1) != 0;
      cVar9 = (in_cpsr >> 0x1c & 1) != 0;
      cVar8 = (in_cpsr >> 0x1d & 1) != 0;
      cVar11 = (in_cpsr >> 0x1e & 1) != 0;
      cVar10 = (int)in_cpsr < 0;
      objCoreReclaim(param_1,uVar4);
      uVar4 = (uint)(byte)(cVar10 << 4 | cVar11 << 3 | cVar8 << 2 | cVar9 << 1 | bVar12) << 0x1b |
              0x80;
      in_cpsr = in_cpsr & 0xffffff00;
    } while (*(int *)(param_1 + 0xc) != 0);
    iVar7 = *(int *)(param_1 + 0x34);
  }
  iVar7 = *(int *)(param_1 + 0x94);
  bVar1 = false;
  *(int *)(iVar7 + 0xb4) = *(int *)(iVar7 + 0xb4) + -1;
  if (*DAT_30129194 == iVar7) {
    bVar1 = true;
  }
  else {
    iVar7 = objClassIdGet(5);
    if (iVar7 != 0) {
      puVar3 = (undefined4 *)__errno();
      uVar6 = *puVar3;
      iVar7 = objVerify(*(undefined4 *)(param_1 + 0x94),iVar7);
      if (iVar7 == 0) {
        bVar1 = true;
      }
      else {
        puVar3 = (undefined4 *)__errno();
        *puVar3 = uVar6;
      }
    }
  }
  objCoreInvalidate(param_1);
  *DAT_30129288 = 1;
  iVar7 = windDelete(param_1);
  if (*DAT_3012928c == param_1) {
    *DAT_3012928c = 0;
  }
  if (*DAT_30129290 == param_1) {
    *DAT_30129290 = 0;
  }
  if ((*(int *)(param_1 + 0x118) != 0) && (iVar7 == 0)) {
    (*(code *)*DAT_30129294)(*(int *)(param_1 + 0x118));
  }
  if (*(int *)(param_1 + 0xb0) != 0) {
    windPendQFlush(param_1 + 0xb0);
  }
  if ((((*(int *)(param_1 + 0x90) != *(int *)(param_1 + 0x94)) &&
       (iVar7 = objClassIdGet(5), iVar7 != 0)) &&
      (iVar7 = objVerify(*(undefined4 *)(param_1 + 0x90),iVar7), iVar7 == 0)) &&
     (((*DAT_30129194 != *(int *)(param_1 + 0x90) &&
       (iVar7 = atomic32Dec(*(int *)(param_1 + 0x90) + 0x40), iVar7 == 1)) &&
      (*(int *)(*(int *)(param_1 + 0x90) + 0xb8) != 0)))) {
    windPendQFlush(*(int *)(param_1 + 0x90) + 0xb8);
  }
  windExit();
  if (param_2 == 0) {
LAB_30128d64:
    if (*DAT_30129298 != param_1) {
      if (*(short *)(param_1 + 0x3e) != 0) {
        *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | 0x100;
      }
      goto LAB_30128d9c;
    }
  }
  else {
    if ((*(uint *)(param_1 + 0x98) & 4) != 0) {
      if (*DAT_30129298 == param_1) {
        memAddToPool(*DAT_301292a0,*DAT_3012929c);
      }
      else {
        pvVar5 = *(void **)(param_1 + 200);
        if ((code *)*DAT_30129254 == (code *)0x0) {
          free(pvVar5);
        }
        else if (bVar1) {
          if (*(int *)(param_1 + 0x94) == *DAT_30129194) {
            uVar6 = *DAT_30129274;
          }
          else {
            uVar6 = *DAT_30129278;
          }
          (*(code *)*DAT_30129254)
                    (param_1,pvVar5,*(int *)(param_1 + 0xc4) - (int)pvVar5,
                     *(undefined4 *)(param_1 + 0x15c),uVar6,*(uint *)(param_1 + 0x98) & 0x4000 | 5);
        }
      }
    }
    if (param_2 == 0) goto LAB_30128d64;
    if ((*DAT_30129298 != param_1) && ((*(uint *)(param_1 + 0x98) & 0x1000) != 0)) {
      pvVar5 = *(void **)(param_1 + 100);
      if (*(int *)(param_1 + 0x94) == *DAT_30129194) {
        uVar6 = *DAT_3012919c;
      }
      else {
        uVar6 = *DAT_301291a4;
      }
      if ((code *)*DAT_30129254 == (code *)0x0) {
        free(pvVar5);
      }
      else {
        (*(code *)*DAT_30129254)
                  (param_1,pvVar5,*(int *)(param_1 + 0x68) - (int)pvVar5,uVar6,0,
                   *(uint *)(param_1 + 0x98) & 0x4000 | 9);
      }
    }
    if (((param_2 == 0) || ((*(uint *)(param_1 + 0x98) & 0x8000) == 0)) ||
       (*(short *)(param_1 + 0x3e) != 0)) goto LAB_30128d64;
    if (*DAT_30129298 != param_1) {
      if ((*DAT_30129254 == 0) && (*(int *)(param_1 + 0xc4) == param_1)) {
        param_1 = *(int *)(param_1 + 200);
      }
      objFree(*puVar2,param_1);
      goto LAB_30128d9c;
    }
  }
  *DAT_30129298 = 0;
LAB_30128d9c:
  taskUnsafe();
  return 0;
}

/* ----------------------------------------------------------------
 * taskDestroy @ 0x30128DAC  (примерный размер ~1048 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 14
 * Вызывает: FUN_30128940, __errno, edrErrorInjectStub, edrKernelFatalPolicyHandler, intContext, objCoreReclaim, objVerify, snprintf, taskSuspend, windExit, windPendQFlush, windPendQPut, windPendQRemove, windSuspend
 * Вызывают: exit, taskDelete, taskDeleteForce, taskTerminate
 * Константы: 0xFFFFFFFF, 0x30128DAC
 * Данные: DAT_30129180, DAT_30129190, DAT_30129194, DAT_30129288, DAT_301292a4, DAT_301292a8, DAT_301292ac, DAT_301292b0
 * ---------------------------------------------------------------- */
undefined4 taskDestroy(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  code *pcVar6;
  int iVar7;
  char acStack_80 [100];
  
  iVar1 = intContext();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_301292a4;
    return 0xffffffff;
  }
  if (param_1 == 0) {
    param_1 = *DAT_30129190;
  }
LAB_30128dfc:
  puVar2 = DAT_30129180;
  iVar1 = objVerify(param_1,*DAT_30129180);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x94) == *DAT_30129194) {
    iVar1 = *(int *)(param_1 + 0xd8);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x614) = 0xffffffff;
      *(undefined4 *)(iVar1 + 0x618) = 0;
    }
  }
  else if ((code *)*DAT_301292a8 != (code *)0x0) {
    (*(code *)*DAT_301292a8)(param_1);
  }
  do {
    if ((*(int *)(param_1 + 0xac) == 0) &&
       ((*(int *)(param_1 + 0x70) != 0 || (*(int *)(param_1 + 0x7c) == 0)))) {
      *(int *)(*DAT_30129190 + 0xac) = *(int *)(*DAT_30129190 + 0xac) + 1;
      *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
      if (*DAT_30129190 != param_1) {
        *DAT_30129288 = 1;
        windSuspend(param_1);
        uVar4 = *(uint *)(param_1 + 0x70);
        *(uint *)(param_1 + 0x70) = uVar4 | 8;
        if ((uVar4 & 2) != 0) {
          windPendQRemove(param_1);
        }
        windExit();
      }
      iVar7 = *DAT_301292b8;
      iVar1 = 0;
      piVar5 = DAT_301292b8;
      break;
    }
    if ((param_4 == 0) && (*DAT_30129190 != param_1)) {
      if (param_3 == 0) {
        puVar2 = (undefined4 *)__errno();
        *puVar2 = DAT_301292ac;
        return 0xffffffff;
      }
      *DAT_30129288 = 1;
      iVar1 = windPendQPut(param_1 + 0xb0,param_3);
      if (iVar1 != 0) {
        windExit();
        return 0xffffffff;
      }
      iVar1 = windExit();
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      if (iVar1 == 1) goto code_r0x30128f6c;
    }
    else {
      *DAT_30129288 = 1;
      *(undefined4 *)(param_1 + 0xac) = 0;
      *(undefined4 *)(param_1 + 0x7c) = 0;
      if (*(int *)(param_1 + 0xb0) != 0) {
        windPendQFlush(param_1 + 0xb0);
      }
      windExit();
    }
    iVar1 = objVerify(param_1,*puVar2);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_301292b4;
      return 0xffffffff;
    }
  } while( true );
joined_r0x3012904c:
  if (iVar7 == 0) {
LAB_30129080:
    objCoreReclaim(param_1);
    if (*DAT_30129190 != param_1) {
      uVar3 = FUN_30128940(param_1,param_2,0);
      return uVar3;
    }
    pcVar6 = (code *)*DAT_301292bc;
    if ((pcVar6 == (code *)0x0) && (pcVar6 = (code *)*DAT_301292c0, pcVar6 == (code *)0x0)) {
      do {
        taskSuspend(0);
      } while( true );
    }
    iVar1 = (*pcVar6)(DAT_301292c4,param_1,param_2,1,0,0,0,0);
    if (iVar1 == -1) {
      uVar3 = DAT_301292cc;
      if (*DAT_301292bc != 0) {
        uVar3 = DAT_301292c8;
      }
      snprintf(acStack_80,100,DAT_301292d0,uVar3,param_1);
      edrErrorInjectStub(0x11,DAT_301292d4,DAT_301292d8,0,0,0,acStack_80);
      edrKernelFatalPolicyHandler(0);
    }
    do {
      *DAT_30129288 = 1;
      windSuspend(param_1);
      windExit();
    } while( true );
  }
  (*(code *)*piVar5)(param_1);
  iVar1 = iVar1 + 1;
  if (0x13 < iVar1) goto LAB_30129080;
  piVar5 = piVar5 + 1;
  iVar7 = *piVar5;
  goto joined_r0x3012904c;
code_r0x30128f6c:
  param_3 = (*(code *)*DAT_301292b0)(param_3);
  goto LAB_30128dfc;
}

/* ----------------------------------------------------------------
 * taskDelete @ 0x30129220  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 1
 * Вызывает: taskDestroy
 * Вызывают: FUN_3005c700, FUN_300cbe88, FUN_3010ef1c, Kill_Intr_Thread, TFUP_dosFsDevDelete, os_task_delete, td
 * Константы: 0x30129220, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void taskDelete(undefined4 param_1)

{
  taskDestroy(param_1,1,0xffffffff,0);
  return;
}

/* ----------------------------------------------------------------
 * taskDeleteForce @ 0x30129230  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskDestroy
 * Вызывают: shellInOutBgndClose
 * Константы: 0x30129230, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void taskDeleteForce(undefined4 param_1)

{
  taskDestroy(param_1,1,0xffffffff,1);
  return;
}

/* ----------------------------------------------------------------
 * taskTerminate @ 0x30129240  (примерный размер ~164 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskDestroy
 * Вызывают: taskRestart
 * Константы: 0x30129240, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void taskTerminate(undefined4 param_1)

{
  taskDestroy(param_1,0,0xffffffff,0);
  return;
}

/* ----------------------------------------------------------------
 * taskLibInit @ 0x301292E4  (примерный размер ~252 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: classInit
 * Вызывают: usrKernelInit
 * Константы: 0xFFFFFFFC, 0x301292E4, 0xFFFFFFFF
 * Данные: DAT_3012a2a0, DAT_3012a2a4, DAT_3012a2a8, DAT_3012a2ac, DAT_3012a2b0, DAT_3012a2b4, DAT_3012a2b8, DAT_3012a2bc
 * ---------------------------------------------------------------- */
undefined4
taskLibInit(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
           int param_7)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_3012a2a0;
  if (*DAT_3012a2a0 == 0) {
    iVar2 = classInit(*DAT_3012a2a4,0x244,0,0,0,0,0,0,6,1);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    if (param_1 != 0) {
      *DAT_3012a2a8 = param_1 + 3U & 0xfffffffc;
    }
    *DAT_3012a2ac = param_2 + 3U & 0xfffffffc;
    *DAT_3012a2b0 = param_4 + 3U & 0xfffffffc;
    *DAT_3012a2b4 = param_5 + 3U & 0xfffffffc;
    *DAT_3012a2b8 = param_6 + 3U & 0xfffffffc;
    *DAT_3012a2bc = param_7 + 3U & 0xfffffffc;
    *piVar1 = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * taskTcb @ 0x301293E0  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 56 | Вызывает: 1
 * Вызывает: objVerify
 * Вызывают: FUN_30094530, FUN_300a74d4, FUN_300e17dc, FUN_300e1b70, FUN_300e72cc, FUN_300e7448, FUN_300f5e28, FUN_3010df20, FUN_3010f2f0, FUN_30110e10
 *           ...
 * Константы: 0x301293E0
 * Данные: DAT_3012a2a4, DAT_3012a2c0
 * ---------------------------------------------------------------- */
int taskTcb(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return *DAT_3012a2c0;
  }
  iVar1 = objVerify(param_1,*DAT_3012a2a4);
  if (iVar1 != 0) {
    return 0;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * taskStackAllot @ 0x30129424  (примерный размер ~148 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: objVerify
 * Вызывают: coprocTaskCreateHook, taskInitialize
 * Константы: 0x30129424, 0xFFFFFFFC
 * Данные: DAT_3012a2a4, DAT_3012a2c0
 * ---------------------------------------------------------------- */
int taskStackAllot(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    param_1 = *DAT_3012a2c0;
  }
  else {
    iVar1 = objVerify(param_1,*DAT_3012a2a4);
    if (iVar1 != 0) {
      param_1 = 0;
    }
  }
  uVar2 = param_2 + 3U & 0xfffffffc;
  if (((param_1 != 0) && (uVar2 <= (uint)(*(int *)(param_1 + 0x60) - *(int *)(param_1 + 100)))) &&
     (param_1 != *DAT_3012a2c0)) {
    iVar1 = *(int *)(param_1 + 0x60) - uVar2;
    *(int *)(param_1 + 0x60) = iVar1;
    return iVar1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * taskInitialize @ 0x301294B8  (примерный размер ~1012 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 13
 * Вызывает: __errno, bfill, bzero, errnoOfTaskGet, objCoreInit, objNamePtrSet, objNameSet, qInit, strcpy, strlen, taskArgsSet, taskRegsInit, taskStackAllot
 * Вызывают: taskInitExcStk
 * Константы: 0xFFFFFFFF, 0x301294B8
 * Данные: DAT_3012a2a4, DAT_3012a2c0, DAT_3012a3f4, DAT_3012a3f8, DAT_3012a3fc, DAT_3012a400, DAT_3012a404, DAT_3012a408
 * ---------------------------------------------------------------- */
undefined4
taskInitialize(int param_1,char *param_2,uint param_3,uint param_4,int param_5,int param_6,
              int param_7,int param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,
              undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,
              undefined4 param_16,undefined4 param_17,undefined4 param_18,undefined4 param_19)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  size_t sVar3;
  char *__dest;
  uint uVar4;
  uint extraout_r1;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  byte in_Q;
  undefined8 uVar13;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar5 = *DAT_3012a2c0;
  if (*DAT_3012a3f4 < 1) {
    if (param_3 < 0x100) {
      if (*(int *)(param_1 + 0x94) == *DAT_3012a400) {
        param_4 = param_4 | 1;
      }
      if (*DAT_3012a404 != 0) {
        param_4 = param_4 | 0x100;
      }
      local_4c = param_10;
      local_48 = param_11;
      local_44 = param_12;
      local_40 = param_13;
      local_3c = param_14;
      local_38 = param_15;
      local_34 = param_16;
      local_30 = param_17;
      local_2c = param_18;
      local_28 = param_19;
      *(uint *)(param_1 + 0x98) = param_4;
      *(undefined4 *)(param_1 + 0x70) = 1;
      *(uint *)(param_1 + 0x74) = param_3;
      *(undefined4 *)(param_1 + 0x9c) = 0;
      *(undefined4 *)(param_1 + 0x80) = 0;
      *(undefined4 *)(param_1 + 0x84) = 0;
      *(uint *)(param_1 + 0x78) = param_3;
      *(uint *)(param_1 + 0x88) = param_3;
      *(undefined4 *)(param_1 + 0x8c) = 0;
      *(undefined4 *)(param_1 + 0x7c) = 0;
      *(undefined4 *)(param_1 + 0xa0) = 0;
      *(undefined2 *)(param_1 + 0xa4) = 0;
      *(undefined2 *)(param_1 + 0xa6) = 0;
      *(undefined4 *)(param_1 + 0xa8) = 0;
      *(undefined4 *)(param_1 + 0x23c) = 0;
      *(undefined4 *)(param_1 + 0x240) = 0;
      *(undefined4 *)(param_1 + 0xac) = 0;
      *(undefined4 *)(param_1 + 0x6c) = 0;
      qInit(param_1 + 0xb0,*DAT_3012a408,0,0,0,0,0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0xc0) = param_9;
      *(int *)(param_1 + 0xc4) = param_5;
      *(int *)(param_1 + 200) = param_5 - param_6;
      if ((param_4 & 0x100) == 0) {
        bfill(param_5 - param_6,param_6,0xee);
      }
      taskRegsInit(param_1,*(undefined4 *)(param_1 + 0xc4));
      iVar8 = 0;
      *(undefined4 *)(param_1 + 0xcc) = 0;
      *(undefined4 *)(param_1 + 0xd0) = 0;
      *(undefined4 *)(param_1 + 0xd4) = 0;
      *(undefined4 *)(param_1 + 0xd8) = 0;
      *(undefined4 *)(param_1 + 0xdc) = 0;
      *(undefined4 *)(param_1 + 0x10c) = 0;
      *(undefined4 *)(param_1 + 0xe0) = 0;
      *(undefined4 *)(param_1 + 0xe4) = 0;
      *(undefined4 *)(param_1 + 0x1b4) = 0;
      *(undefined4 *)(param_1 + 0xe8) = 0;
      *(undefined4 *)(param_1 + 0xec) = 0;
      *(undefined4 *)(param_1 + 0xf0) = 0;
      *(undefined4 *)(param_1 + 0x218) = 0;
      iVar7 = param_1;
      do {
        *(int *)(iVar7 + 0x100) = iVar8;
        *(undefined4 *)(iVar7 + 0xf4) = 0;
        iVar7 = iVar7 + 4;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 3);
      *(undefined4 *)(param_1 + 0x118) = 0;
      *(undefined4 *)(param_1 + 0x11c) = 0;
      *(undefined4 *)(param_1 + 0x120) = 0;
      bzero((void *)(param_1 + 0x124),0xc);
      *(int *)(param_1 + 0x60) = param_7;
      *(int *)(param_1 + 0x68) = param_7;
      *(int *)(param_1 + 100) = param_7 - param_8;
      if ((param_4 & 0x100) == 0) {
        bfill(param_7 - param_8,param_8,0xee);
      }
      *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x94);
      *(undefined4 *)(param_1 + 0x154) = 0;
      *(undefined4 *)(param_1 + 0x158) = 0;
      *(undefined4 *)(param_1 + 0x160) = 0;
      *(undefined4 *)(param_1 + 0x164) = 0;
      *(undefined4 *)(param_1 + 0x168) = 0;
      *(undefined4 *)(param_1 + 0x16c) = 0;
      *(undefined4 *)(param_1 + 0x174) = 0;
      *(undefined4 *)(param_1 + 0x19c) = 0;
      *(undefined4 *)(param_1 + 0x1a0) = 0;
      *(undefined4 *)(param_1 + 0x1a4) = 0;
      *(undefined4 *)(param_1 + 0x1a8) = 0;
      *(undefined4 *)(param_1 + 0x1ac) = 0;
      *(undefined4 *)(param_1 + 0x1b0) = 0;
      *(undefined4 *)(param_1 + 0x21c) = 0;
      *(undefined4 *)(param_1 + 0x138) = 0;
      *(undefined4 *)(param_1 + 0x130) = 0;
      *(undefined4 *)(param_1 + 0x134) = 0;
      *(undefined4 *)(param_1 + 0x13c) = 0;
      *(undefined4 *)(param_1 + 0x140) = 0;
      bzero((void *)(param_1 + 0x144),0x10);
      bzero((void *)(param_1 + 0x224),0x18);
      taskArgsSet(param_1,*(undefined4 *)(param_1 + 0xc4),&local_4c);
      objCoreInit(param_1,*DAT_3012a2a4);
      if (iVar5 == 0) {
        *(undefined4 *)(param_1 + 0x17c) = 0;
      }
      else {
        *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(iVar5 + 0x17c);
      }
      cVar11 = iVar5 < 0;
      cVar12 = iVar5 == 0;
      cVar9 = '\x01';
      cVar10 = '\0';
      if ((bool)cVar12) {
        sVar3 = strlen(param_2);
        __dest = (char *)taskStackAllot(param_1,sVar3 + 1);
        strcpy(__dest,param_2);
        objNamePtrSet(param_1,__dest);
        piVar6 = (int *)(*(int *)(param_1 + 0x94) + 0xb4);
        *piVar6 = *piVar6 + 1;
        uVar4 = extraout_r1;
      }
      else {
        objNameSet(param_1,param_2);
        uVar4 = (uint)(byte)(cVar11 << 4 | cVar12 << 3 | cVar9 << 2 | cVar10 << 1 | in_Q) << 0x1b |
                0x80;
        piVar6 = (int *)(*(int *)(param_1 + 0x94) + 0xb4);
        *piVar6 = *piVar6 + 1;
      }
      iVar5 = 0x14;
      *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | 0x80;
      puVar1 = DAT_3012a40c;
      do {
        puVar1 = puVar1 + 1;
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)(param_1,uVar4);
          uVar13 = errnoOfTaskGet(param_1);
          uVar4 = (uint)((ulonglong)uVar13 >> 0x20);
          if ((int)uVar13 != 0) {
            return 0xffffffff;
          }
        }
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      taskStackAllot(param_1,1);
      uVar2 = 0;
    }
    else {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = DAT_3012a3fc;
      uVar2 = 0xffffffff;
    }
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_3012a3f8;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * taskInitExcStk @ 0x301298AC  (примерный размер ~176 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 1
 * Вызывает: taskInitialize
 * Вызывают: excInit, kernelInit, taskInit, taskRestart
 * Константы: 0x301298AC
 * Данные: DAT_3012a2c0, DAT_3012a400
 * ---------------------------------------------------------------- */
void taskInitExcStk(int param_1)

{
  undefined4 uVar1;
  
  if (*DAT_3012a2c0 == 0) {
    uVar1 = *DAT_3012a400;
  }
  else {
    uVar1 = *(undefined4 *)(*DAT_3012a2c0 + 0x94);
  }
  *(undefined4 *)(param_1 + 0x94) = uVar1;
  taskInitialize();
  return;
}

/* ----------------------------------------------------------------
 * taskResume @ 0x3012995C  (примерный размер ~188 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 4
 * Вызывает: objVerify, windExit, windResume, workQAdd1
 * Вызывают: FUN_3010f2f0, tr
 * Константы: 0xFFFFFFFF, 0x3012995C
 * Данные: DAT_3012a2a4, DAT_3012a410, DAT_3012a414
 * ---------------------------------------------------------------- */
undefined4 taskResume(int param_1)

{
  int iVar1;
  
  if (*DAT_3012a410 == 1) {
    if ((param_1 != 0) && (iVar1 = objVerify(param_1,*DAT_3012a2a4), iVar1 == 0)) {
      workQAdd1(DAT_3012a414,param_1);
      return 0;
    }
    return 0xffffffff;
  }
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = objVerify(param_1,*DAT_3012a2a4);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  *DAT_3012a410 = 1;
  windResume(param_1);
  windExit();
  return 0;
}

/* ----------------------------------------------------------------
 * taskActivate @ 0x30129A18  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 4
 * Вызывает: objVerify, windExit, windResume, workQAdd1
 * Вызывают: excInit, kernelInit, shellGenericInit, taskRestart, taskSpawn
 * Константы: 0xFFFFFFFF, 0x30129A18
 * Данные: DAT_3012a2a4, DAT_3012a410, DAT_3012a414
 * ---------------------------------------------------------------- */
undefined4 taskActivate(int param_1)

{
  int iVar1;
  
  if (*DAT_3012a410 == 1) {
    if ((param_1 != 0) && (iVar1 = objVerify(param_1,*DAT_3012a2a4), iVar1 == 0)) {
      workQAdd1(DAT_3012a414,param_1);
      return 0;
    }
    return 0xffffffff;
  }
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = objVerify(param_1,*DAT_3012a2a4);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  *DAT_3012a410 = 1;
  windResume(param_1);
  windExit();
  return 0;
}

/* ----------------------------------------------------------------
 * taskSuspend @ 0x30129C2C  (примерный размер ~228 байт)
 * Модуль: kernel | Вызывают: 15 | Вызывает: 1
 * Вызывает: _taskSuspend
 * Вызывают: FUN_300f2514, FUN_300f2884, FUN_3010f2f0, FUN_30110d64, FUN_30110e10, longjmp, memPartReallocInternal, os_panic, shellCompatibleSet, shellExec
 *           ...
 * Константы: 0x30129C2C
 * ---------------------------------------------------------------- */
void taskSuspend(undefined4 param_1)

{
  _taskSuspend(param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * taskStop @ 0x30129D10  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 4
 * Вызывает: objVerify, windExit, windStop, workQAdd1
 * Вызывают: FUN_300c78e4, dbgStackTrace, exchStackTrace, vxdbgTaskStop
 * Константы: 0xFFFFFFFF, 0x30129D10
 * Данные: DAT_3012a2a4, DAT_3012a2c0, DAT_3012a3f4, DAT_3012a410, DAT_3012a420
 * ---------------------------------------------------------------- */
undefined4 taskStop(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = DAT_3012a2a4;
  if (param_1 == 0) {
    if (0 < *DAT_3012a3f4) {
      return 0xffffffff;
    }
    param_1 = *DAT_3012a2c0;
  }
  iVar3 = objVerify(param_1,*DAT_3012a2a4);
  piVar2 = DAT_3012a410;
  if ((iVar3 != 0) || ((*(uint *)(param_1 + 0x98) & 2) != 0)) {
    return 0xffffffff;
  }
  if (*DAT_3012a410 == 1) {
    workQAdd1(DAT_3012a420,param_1);
    return 0;
  }
  iVar3 = objVerify(param_1,*puVar1);
  if (iVar3 == 0) {
    *piVar2 = 1;
    windStop(param_1);
    windExit();
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskStopForce @ 0x30129D18  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 4
 * Вызывает: objVerify, windExit, windStop, workQAdd1
 * Вызывают: FUN_300c7cbc, FUN_300f5e28, edrKernelFatalPolicyHandler
 * Константы: 0xFFFFFFFF, 0x30129D18, 0x30129C88
 * Данные: DAT_3012a2a4, DAT_3012a2c0, DAT_3012a3f4, DAT_3012a410, DAT_3012a420
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x30129c88) */

undefined4 taskStopForce(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = DAT_3012a2a4;
  if (param_1 == 0) {
    if (0 < *DAT_3012a3f4) {
      return 0xffffffff;
    }
    param_1 = *DAT_3012a2c0;
  }
  iVar3 = objVerify(param_1,*DAT_3012a2a4);
  piVar2 = DAT_3012a410;
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  if (*DAT_3012a410 == 1) {
    workQAdd1(DAT_3012a420,param_1);
    return 0;
  }
  iVar3 = objVerify(param_1,*puVar1);
  if (iVar3 == 0) {
    *piVar2 = 1;
    windStop(param_1);
    windExit();
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskCont @ 0x30129D20  (примерный размер ~200 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 4
 * Вызывает: objVerify, windCont, windExit, workQAdd1
 * Вызывают: FUN_300f5e28, dbgStackTrace, exchStackTrace, vxdbgTaskCont, vxdbgTaskStep
 * Константы: 0xFFFFFFFF, 0x30129D20
 * Данные: DAT_3012a2a4, DAT_3012a3f4, DAT_3012a410, DAT_3012a424
 * ---------------------------------------------------------------- */
undefined4 taskCont(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = DAT_3012a2a4;
  if (param_1 == 0) {
    if (0 < *DAT_3012a3f4) {
      return 0xffffffff;
    }
    return 0;
  }
  iVar3 = objVerify(param_1,*DAT_3012a2a4);
  piVar2 = DAT_3012a410;
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  if (*DAT_3012a410 == 1) {
    workQAdd1(DAT_3012a424,param_1);
    return 0;
  }
  iVar3 = objVerify(param_1,*puVar1);
  if (iVar3 == 0) {
    *piVar2 = 1;
    windCont(param_1);
    windExit();
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskPrioritySet @ 0x30129DE8  (примерный размер ~220 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 5
 * Вызывает: __errno, objVerify, windExit, windPriNormalSet, workQAdd2
 * Вызывают: FUN_300ddd0c, FUN_300de180, FUN_300e2e10, FUN_300e3008, sdmmcBlkRd
 * Константы: 0xFFFFFFFF, 0x30129DE8
 * Данные: DAT_3012a2a4, DAT_3012a2c0, DAT_3012a3fc, DAT_3012a410, DAT_3012a428
 * ---------------------------------------------------------------- */
undefined4 taskPrioritySet(int param_1,uint param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  piVar1 = DAT_3012a410;
  if (0xff < param_2) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_3012a3fc;
    return 0xffffffff;
  }
  if (*DAT_3012a410 != 1) {
    if (param_1 == 0) {
      param_1 = *DAT_3012a2c0;
    }
    iVar3 = objVerify(param_1,*DAT_3012a2a4);
    if (iVar3 == 0) {
      *piVar1 = 1;
      windPriNormalSet(param_1,param_2);
      windExit();
      return 0;
    }
    return 0xffffffff;
  }
  if ((param_1 != 0) && (iVar3 = objVerify(param_1,*DAT_3012a2a4), iVar3 == 0)) {
    workQAdd2(DAT_3012a428,param_1,param_2);
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskPriorityGet @ 0x30129EC4  (примерный размер ~92 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 1
 * Вызывает: objVerify
 * Вызывают: FUN_300e2e10, sdmmcBlkRd, taskIdListSort, xbdStrategy
 * Константы: 0xFFFFFFFF, 0x30129EC4
 * Данные: DAT_3012a2a4, DAT_3012a2c0
 * ---------------------------------------------------------------- */
undefined4 taskPriorityGet(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = *DAT_3012a2c0;
  }
  else {
    iVar1 = objVerify(param_1,*DAT_3012a2a4);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
  }
  if (param_1 == 0) {
    return 0xffffffff;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x74);
  return 0;
}

/* ----------------------------------------------------------------
 * taskStackSizeGet @ 0x30129F20  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: objVerify
 * Константы: 0xFFFFFFFF, 0x30129F20
 * Данные: DAT_3012a2a4, DAT_3012a2c0
 * ---------------------------------------------------------------- */
undefined4 taskStackSizeGet(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = *DAT_3012a2c0;
  }
  else {
    iVar1 = objVerify(param_1,*DAT_3012a2a4);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
  }
  if (param_1 == 0) {
    return 0xffffffff;
  }
  *param_2 = *(int *)(param_1 + 0xc4) - *(int *)(param_1 + 200);
  return 0;
}

/* ----------------------------------------------------------------
 * taskCpuUnlockNoResched @ 0x30129F84  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300c78e4, FUN_300c7bac, FUN_300c7cbc
 * Константы: 0x30129F84
 * Данные: DAT_3012a2c0
 * ---------------------------------------------------------------- */
undefined4 taskCpuUnlockNoResched(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*DAT_3012a2c0 + 0x7c);
  if (iVar1 != 0) {
    *(int *)(*DAT_3012a2c0 + 0x7c) = iVar1 + -1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * taskSafe @ 0x30129FA4  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300fb05c, tyWrite
 * Константы: 0x30129FA4
 * Данные: DAT_3012a2c0
 * ---------------------------------------------------------------- */
undefined4 taskSafe(void)

{
  *(int *)(*DAT_3012a2c0 + 0xac) = *(int *)(*DAT_3012a2c0 + 0xac) + 1;
  return 0;
}

/* ----------------------------------------------------------------
 * taskUnsafe @ 0x30129FC4  (примерный размер ~80 байт)
 * Модуль: kernel | Вызывают: 14 | Вызывает: 2
 * Вызывает: windExit, windPendQFlush
 * Вызывают: FUN_300e2e10, FUN_300fb05c, FUN_30122a44, FUN_30122acc, FUN_30124a88, FUN_30128940, bootStructToString, iosRtpFdUnmap2, printExc, select
 *           ...
 * Константы: 0x30129FC4
 * Данные: DAT_3012a2c0, DAT_3012a410
 * ---------------------------------------------------------------- */
undefined4 taskUnsafe(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *DAT_3012a2c0;
  if (((*(int *)(iVar2 + 0xac) != 0) &&
      (iVar1 = *(int *)(iVar2 + 0xac) + -1, *(int *)(iVar2 + 0xac) = iVar1, iVar1 == 0)) &&
     (*(int *)(iVar2 + 0xb0) != 0)) {
    *DAT_3012a410 = 1;
    windPendQFlush(iVar2 + 0xb0);
    windExit();
  }
  return 0;
}

/* ----------------------------------------------------------------
 * taskDelay @ 0x3012A014  (примерный размер ~188 байт)
 * Модуль: kernel | Вызывают: 49 | Вызывает: 3
 * Вызывает: __errno, windDelay, windExit
 * Вызывают: BSP_DLOAD_Init, BSP_DRV_BOOTROM_Init, BSP_HKADC_Convert, BSP_LDScript, BSP_TFUP_CompleteDeal, Enumerate_SD_card_Stack, FUN_30061708, FUN_30080798, FUN_300ccc2c, FUN_300cefe8
 *           ...
 * Константы: 0x3012A014
 * Данные: DAT_3012a2c0, DAT_3012a3f4, DAT_3012a3f8, DAT_3012a410, DAT_3012a42c
 * ---------------------------------------------------------------- */
int taskDelay(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (*DAT_3012a3f4 < 1) {
    iVar3 = *DAT_3012a2c0;
    *DAT_3012a410 = 1;
    iVar2 = DAT_3012a42c;
    if (param_1 == 0) {
      (**(code **)(*(int *)(DAT_3012a42c + 0xc) + 0x18))(DAT_3012a42c,iVar3 + 0x50);
      (**(code **)(*(int *)(iVar2 + 0xc) + 0x10))(iVar2,iVar3 + 0x50,*(undefined4 *)(iVar3 + 0x74));
    }
    else {
      windDelay(param_1);
    }
    iVar2 = windExit();
    if (iVar2 == 1) {
      iVar2 = -1;
      puVar1 = (undefined4 *)__errno();
      *puVar1 = 4;
    }
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_3012a3f8;
    iVar2 = -1;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * taskUndelay @ 0x3012A0D0  (примерный размер ~160 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: objVerify, windExit, windUndelay, workQAdd1
 * Константы: 0xFFFFFFFF, 0x3012A0D0
 * Данные: DAT_3012a2a4, DAT_3012a410, DAT_3012a430
 * ---------------------------------------------------------------- */
undefined4 taskUndelay(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_3012a410;
  if (*DAT_3012a410 != 1) {
    iVar2 = objVerify(param_1,*DAT_3012a2a4);
    if (iVar2 == 0) {
      *piVar1 = 1;
      windUndelay(param_1);
      windExit();
      return 0;
    }
    return 0xffffffff;
  }
  iVar2 = objVerify(param_1,*DAT_3012a2a4);
  if (iVar2 == 0) {
    workQAdd1(DAT_3012a430,param_1);
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskIdSelf @ 0x3012A170  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 40 | Вызывает: 0
 * Вызывают: FUN_3005c700, FUN_3005f7d4, FUN_30095574, FUN_300c906c, FUN_300cc508, FUN_300ccc2c, FUN_300cef14, FUN_300cefe8, FUN_300cf1d0, FUN_300eeb94
 *           ...
 * Константы: 0x3012A170
 * Данные: DAT_3012a2c0
 * ---------------------------------------------------------------- */
undefined4 taskIdSelf(void)

{
  return *DAT_3012a2c0;
}

/* ----------------------------------------------------------------
 * taskIdVerify @ 0x3012A17C  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 20 | Вызывает: 1
 * Вызывает: objVerify
 * Вызывают: FUN_30110c38, FUN_30114978, FUN_30114a38, FUN_3011b068, FUN_3011b934, dbgBpEpCoreRtn, dbgStackTrace, exchExcHook, exchRegsShow, exchStackFlowHook
 *           ...
 * Константы: 0x3012A17C
 * Данные: DAT_3012a2a4
 * ---------------------------------------------------------------- */
void taskIdVerify(undefined4 param_1)

{
  objVerify(param_1,*DAT_3012a2a4);
  return;
}

/* ----------------------------------------------------------------
 * taskCpuAffinitySet @ 0x3012A188  (примерный размер ~204 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: __errno, ffsLsb, ffsMsb, objVerify
 * Константы: 0xFFFFFFFF, 0x3012A188
 * Данные: DAT_3012a2a4, DAT_3012a2c0, DAT_3012a3f4, DAT_3012a3f8, DAT_3012a434, DAT_3012a438
 * ---------------------------------------------------------------- */
undefined4 taskCpuAffinitySet(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (0 < *DAT_3012a3f4) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_3012a3f8;
    return 0xffffffff;
  }
  uVar2 = ffsLsb(param_2);
  if ((uVar2 <= *DAT_3012a434) && (uVar3 = ffsMsb(param_2), uVar3 == uVar2)) {
    if (param_1 == 0) {
      param_1 = *DAT_3012a2c0;
    }
    iVar4 = objVerify(param_1,*DAT_3012a2a4);
    if (iVar4 != 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(param_1 + 0x17c) = param_2;
    return 0;
  }
  puVar1 = (undefined4 *)__errno();
  *puVar1 = DAT_3012a438;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskCpuAffinityGet @ 0x3012A254  (примерный размер ~192 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, objVerify
 * Константы: 0xFFFFFFFF, 0x3012A254
 * Данные: DAT_3012a2c0, DAT_3012a3f4, DAT_3012a3f8, DAT_3012a43c
 * ---------------------------------------------------------------- */
undefined4 taskCpuAffinityGet(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (0 < *DAT_3012a3f4) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_3012a3f8;
    return 0xffffffff;
  }
  if (param_1 == 0) {
    *param_2 = *(undefined4 *)(*DAT_3012a2c0 + 0x17c);
    return 0;
  }
  iVar2 = objVerify(param_1,*DAT_3012a43c);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x17c);
  return 0;
}

/* ----------------------------------------------------------------
 * taskCpuLock @ 0x3012A314  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 23 | Вызывает: 0
 * Вызывают: BSP_OM_SoftReboot, BSP_WDT_reboot_direct, FUN_3005c6bc, FUN_300c701c, FUN_300c72f8, FUN_300c7448, FUN_300c7b48, FUN_300c7bac, FUN_300c7cbc, FUN_300ed06c
 *           ...
 * Константы: 0x3012A314
 * Данные: DAT_3012a440
 * ---------------------------------------------------------------- */
undefined4 taskCpuLock(void)

{
  *(int *)(*DAT_3012a440 + 0x7c) = *(int *)(*DAT_3012a440 + 0x7c) + 1;
  return 0;
}

/* ----------------------------------------------------------------
 * taskCpuUnlock @ 0x3012A334  (примерный размер ~152 байт)
 * Модуль: kernel | Вызывают: 41 | Вызывает: 3
 * Вызывает: FUN_3012a3cc, windExit, windPendQFlush
 * Вызывают: FUN_3005c6bc, FUN_300ae930, FUN_300ae9dc, FUN_300aebec, FUN_300c701c, FUN_300c72f8, FUN_300c7448, FUN_300c7b48, FUN_300ecf38, FUN_300ed06c
 *           ...
 * Константы: 0x3012A334
 * Данные: DAT_3012a410, DAT_3012a42c, DAT_3012a440
 * ---------------------------------------------------------------- */
undefined4 taskCpuUnlock(void)

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
 * FUN_3012a3cc @ 0x3012A3CC  (примерный размер ~120 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: spinLockTaskGive, taskCpuUnlock
 * Константы: 0x3012A3CC
 * ---------------------------------------------------------------- */
bool FUN_3012a3cc(int param_1)

{
  if (*(int *)(param_1 + 0xac) != 0) {
    return false;
  }
  return *(int *)(param_1 + 0xb0) != 0;
}

/* ----------------------------------------------------------------
 * taskIdListGet @ 0x3012A444  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 8 | Вызывает: 3
 * Вызывает: objInfo, taskCpuLock, taskCpuUnlock
 * Вызывают: CvInfoContinue, CvInfoStart, CvTaskNameget, FUN_3012b38c, checkStack, exchTaskShow, shellInternalTaskNameMatch, taskWaitShowCoreRtn
 * Константы: 0x3012A444
 * ---------------------------------------------------------------- */
undefined4 taskIdListGet(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  taskCpuLock();
  uVar1 = objInfo(6,param_1,param_2);
  taskCpuUnlock();
  return uVar1;
}

/* ----------------------------------------------------------------
 * taskNameToId @ 0x3012A474  (примерный размер ~56 байт)
 * Модуль: kernel | Вызывают: 10 | Вызывает: 2
 * Вызывает: __errno, objNameToId
 * Вызывают: BSP_LDScript, BSP_PromptSet, BSP_TLED_LedCallback, BSP_TLED_LedFlush, TFUP_dosFsDevDelete, sdmmcBlkRd, shellContextInit, shellFromNameGet, taskIdFigure, testExcTaskShow
 * Константы: 0x3012A474
 * Данные: DAT_3012a5c0
 * ---------------------------------------------------------------- */
int taskNameToId(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = objNameToId(6,param_1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_3012a5c0;
    return -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * taskEach @ 0x3012A4AC  (примерный размер ~200 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 4
 * Вызывает: errnoSet, objClassIdGet, semMGiveScalable, semMTakeScalable
 * Вызывают: checkStack, taskShow, taskWaitShowCoreRtn
 * Константы: 0x3012A4AC, 0xFFFFFFFF
 * Данные: DAT_3012a5c4, DAT_3012a5c8
 * ---------------------------------------------------------------- */
int taskEach(code *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = 0;
  iVar3 = objClassIdGet(6);
  uVar2 = DAT_3012a5c8;
  if (iVar3 == 0) {
    errnoSet(DAT_3012a5c4);
    iVar5 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(iVar3 + 0x50);
    semMTakeScalable(uVar4,0xffffffff,DAT_3012a5c8);
    if (param_3 == 0) {
      piVar6 = (int *)*(int *)(iVar3 + 0x40);
    }
    else {
      piVar6 = (int *)*(int *)(iVar3 + 0x48);
    }
    do {
      piVar1 = piVar6;
      if (piVar1 == (int *)0x0) break;
      iVar5 = (int)(piVar1 + -7);
      piVar6 = (int *)*piVar1;
      iVar3 = (*param_1)(iVar5,param_2);
    } while (iVar3 != 0);
    semMGiveScalable(uVar4,uVar2);
    if (piVar1 == (int *)0x0) {
      iVar5 = 0;
    }
  }
  return iVar5;
}

/* ----------------------------------------------------------------
 * taskListCount @ 0x3012A574  (примерный размер ~88 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 3
 * Вызывает: dllCount, semMGiveScalable, semMTakeScalable
 * Вызывают: checkStack, taskShow, taskWaitShowCoreRtn
 * Константы: 0x3012A574, 0xFFFFFFFF
 * Данные: DAT_3012a5c8
 * ---------------------------------------------------------------- */
int taskListCount(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = DAT_3012a5c8;
  uVar4 = *(undefined4 *)(param_1 + 0x50);
  semMTakeScalable(uVar4,0xffffffff,DAT_3012a5c8);
  iVar2 = dllCount(param_1 + 0x40);
  iVar3 = dllCount(param_1 + 0x48);
  semMGiveScalable(uVar4,uVar1);
  return iVar3 + iVar2;
}

/* ----------------------------------------------------------------
 * taskRestart @ 0x3012A5CC  (примерный размер ~624 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 15
 * Вызывает: __errno, free, intContext, malloc, objNamePtrGet, strcpy, strlen, taskActivate, taskArgsGet, taskInitExcStk, taskSpawn, taskSuspend, taskTcb, taskTerminate
 *           ...
 * Вызывают: shellRestart
 * Константы: 0xFFFFFFFF, 0x3012A5CC
 * Данные: DAT_3012aaf4, DAT_3012aaf8, DAT_3012aafc, DAT_3012ab00, DAT_3012ab04, DAT_3012ab08, DAT_3012ab0c
 * ---------------------------------------------------------------- */
undefined4 taskRestart(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  char *__s;
  size_t sVar5;
  char *__dest;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  char *__ptr;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar2 = intContext();
  piVar1 = DAT_3012aaf8;
  if (iVar2 == 0) {
    if ((param_1 == 0) || (*DAT_3012aaf8 == param_1)) {
      iVar2 = *(int *)(*DAT_3012aaf8 + 0xac);
      while (iVar2 != 0) {
        taskUnsafe();
        iVar2 = *(int *)(*piVar1 + 0xac);
      }
      taskSpawn(*DAT_3012ab00,*DAT_3012ab04,*DAT_3012ab08,*DAT_3012ab0c,DAT_3012aafc,*piVar1,0,0,0,0
                ,0,0,0,0,0);
      do {
        taskSuspend(0);
      } while( true );
    }
    iVar2 = taskTcb(param_1);
    if (iVar2 == 0) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar10 = *(undefined4 *)(iVar2 + 0xc0);
      uVar4 = *(undefined4 *)(iVar2 + 0x78);
      uVar7 = *(undefined4 *)(iVar2 + 0x98);
      iVar9 = *(int *)(iVar2 + 0xc4);
      iVar11 = *(int *)(iVar2 + 200);
      iVar8 = *(int *)(iVar2 + 0x68);
      iVar12 = *(int *)(iVar2 + 100);
      taskArgsGet(iVar2,iVar9,&local_4c);
      __s = (char *)objNamePtrGet(iVar2);
      __dest = __s;
      __ptr = (char *)0x0;
      if (__s != (char *)0x0) {
        sVar5 = strlen(__s);
        __dest = (char *)malloc(sVar5 + 1);
        __ptr = __dest;
        if (__dest != (char *)0x0) {
          strcpy(__dest,__s);
        }
      }
      *(int *)(*DAT_3012aaf8 + 0xac) = *(int *)(*DAT_3012aaf8 + 0xac) + 1;
      iVar6 = taskTerminate(param_1);
      if (iVar6 == 0) {
        iVar8 = taskInitExcStk(iVar2,__dest,uVar4,uVar7,iVar9,iVar9 - iVar11,iVar8,iVar8 - iVar12,
                               uVar10,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34
                               ,local_30,local_2c,local_28);
        bVar13 = iVar8 == 0;
        if (bVar13) {
          iVar8 = taskActivate(iVar2);
          bVar13 = iVar8 == 0;
          if (bVar13) {
            iVar2 = 0;
          }
        }
        if (!bVar13) {
          iVar2 = 1;
        }
        free(__ptr);
        taskUnsafe();
        if (iVar2 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0xffffffff;
        }
      }
      else {
        free(__ptr);
        taskUnsafe();
        uVar4 = 0xffffffff;
      }
    }
  }
  else {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = DAT_3012aaf4;
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * taskReset @ 0x3012A83C  (примерный размер ~744 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 16
 * Вызывает: __errno, bfill, bzero, errnoSet, intContext, objVerify, taskArgsGet, taskArgsSet, taskRegsInit, taskTcb, taskUnsafe, windExit, windPendQFlush, windPendQPut
 *           ...
 * Константы: 0xFFFFFFFF, 0xFFFFFF00, 0x3012A83C
 * Данные: DAT_3012aaf4, DAT_3012aaf8, DAT_3012ab10, DAT_3012ab14, DAT_3012ab18, DAT_3012ab1c, DAT_3012ab20
 * ---------------------------------------------------------------- */
undefined4 taskReset(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  byte in_Q;
  uint in_cpsr;
  undefined1 auStack_38 [40];
  
  iVar2 = intContext();
  uVar1 = DAT_3012aaf4;
  if (iVar2 == 0) {
    if (param_1 != 0) {
      uVar6 = *DAT_3012aaf8;
      bVar8 = param_1 <= uVar6;
      bVar9 = SBORROW4(uVar6,param_1);
      iVar2 = uVar6 - param_1;
      bVar7 = uVar6 == param_1;
      if (!bVar7) {
        do {
          uVar6 = in_cpsr & 0xffffff00;
          iVar4 = taskTcb(param_1,(uint)(byte)((iVar2 < 0) << 4 | bVar7 << 3 | bVar8 << 2 |
                                               bVar9 << 1 | in_Q) << 0x1b | 0x80);
          if (iVar4 == 0) {
            return 0xffffffff;
          }
          if (*(int *)(iVar4 + 0x94) == *DAT_3012ab14) {
            errnoSet(DAT_3012ab10);
            return 0xffffffff;
          }
          while( true ) {
            if ((*(int *)(iVar4 + 0xac) == 0) &&
               ((*(int *)(iVar4 + 0x70) != 0 || (*(int *)(iVar4 + 0x7c) == 0)))) {
              *(int *)(*DAT_3012aaf8 + 0xac) = *(int *)(*DAT_3012aaf8 + 0xac) + 1;
              *(int *)(iVar4 + 0xac) = *(int *)(iVar4 + 0xac) + 1;
              *DAT_3012ab18 = 1;
              windSuspend(iVar4);
              if ((*(uint *)(iVar4 + 0x70) & 2) != 0) {
                windPendQRemove(iVar4);
              }
              windExit();
              taskArgsGet(iVar4,*(undefined4 *)(iVar4 + 0xc4),auStack_38);
              *(undefined4 *)(iVar4 + 0x7c) = 0;
              *(undefined4 *)(iVar4 + 0x6c) = 0;
              if ((*(uint *)(iVar4 + 0x98) & 0x100) == 0) {
                bfill(*(int *)(iVar4 + 200),*(int *)(iVar4 + 0xc4) - *(int *)(iVar4 + 200),0xee);
              }
              taskRegsInit(iVar4,*(undefined4 *)(iVar4 + 0xc4));
              *(undefined4 *)(iVar4 + 0xd0) = 0;
              *(undefined4 *)(iVar4 + 0xd4) = 0;
              if ((*(uint *)(iVar4 + 0x98) & 0x100) == 0) {
                bfill(*(int *)(iVar4 + 100),*(int *)(iVar4 + 0x60) - *(int *)(iVar4 + 100),0xee);
              }
              bzero((void *)(iVar4 + 0x224),0x18);
              taskArgsSet(iVar4,*(undefined4 *)(iVar4 + 0xc4),auStack_38);
              *(undefined4 *)(iVar4 + 0x80) = 0;
              *(undefined4 *)(iVar4 + 0x84) = 0;
              *(undefined4 *)(iVar4 + 0x78) = *(undefined4 *)(iVar4 + 0x74);
              *(undefined4 *)(iVar4 + 0x88) = *(undefined4 *)(iVar4 + 0x74);
              *(undefined4 *)(iVar4 + 0x8c) = 0;
              *DAT_3012ab18 = 1;
              if (*(int *)(iVar4 + 0xb0) != 0) {
                windPendQFlush(iVar4 + 0xb0);
              }
              *(undefined4 *)(iVar4 + 0xac) = 0;
              windExit();
              taskUnsafe();
              return 0;
            }
            *DAT_3012ab18 = 1;
            in_cpsr = uVar6 & 0xffffff00;
            in_Q = (uVar6 >> 0x1b & 1) != 0;
            iVar2 = windPendQPut(iVar4 + 0xb0,0xffffffff);
            if (iVar2 != 0) {
              windExit();
              return 0xffffffff;
            }
            iVar5 = windExit();
            if (iVar5 == -1) {
              return 0xffffffff;
            }
            bVar8 = iVar5 != 0;
            bVar9 = SBORROW4(iVar5,1);
            iVar2 = iVar5 + -1;
            bVar7 = iVar5 == 1;
            if (bVar7) break;
            uVar6 = in_cpsr & 0xffffff00;
            iVar2 = objVerify(iVar4,*DAT_3012ab1c);
            if (iVar2 != 0) {
              puVar3 = (undefined4 *)__errno();
              *puVar3 = DAT_3012ab20;
              return 0xffffffff;
            }
          }
        } while( true );
      }
    }
    errnoSet(DAT_3012ab10);
  }
  else {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = uVar1;
    errnoSet(uVar1);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * taskShowInit @ 0x3012AB24  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: classShowConnect
 * Вызывают: usrShowInit
 * Константы: 0x3012AB24
 * Данные: DAT_3012ae20, DAT_3012ae24, DAT_3012ae28, DAT_3012ae2c
 * ---------------------------------------------------------------- */
void taskShowInit(void)

{
  classShowConnect(*DAT_3012ae20,DAT_3012ae24);
  *DAT_3012ae2c = DAT_3012ae28;
  return;
}

/* ----------------------------------------------------------------
 * taskInfoGet @ 0x3012AB48  (примерный размер ~612 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 4
 * Вызывает: errnoOfTaskGet, objNamePtrGet, strncpy, taskTcb
 * Вызывают: FUN_30095814, FUN_300f5e28, FUN_3011b4e0, FUN_3012b38c, taskShow
 * Константы: 0x3012AB48, 0xFFFFFFFF
 * Данные: DAT_3012ae30, DAT_3012ae34, DAT_3012ae38
 * ---------------------------------------------------------------- */
undefined4 taskInfoGet(undefined4 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  
  iVar2 = taskTcb();
  if (iVar2 == 0 || param_2 == (int *)0x0) {
    return 0xffffffff;
  }
  *param_2 = iVar2;
  pcVar3 = (char *)objNamePtrGet(iVar2);
  strncpy((char *)(param_2 + 0x11),pcVar3,0x1f);
  *(undefined1 *)((int)param_2 + 99) = 0;
  param_2[1] = *(int *)(iVar2 + 0x74);
  param_2[2] = *(int *)(iVar2 + 0x70);
  param_2[3] = *(int *)(iVar2 + 0x98);
  param_2[4] = *(int *)(iVar2 + 0xc0);
  iVar5 = *(int *)(iVar2 + 0x204);
  param_2[5] = iVar5;
  param_2[0x19] = *(int *)(iVar2 + 0x94);
  param_2[6] = *(int *)(iVar2 + 0xc4);
  param_2[7] = *(int *)(iVar2 + 200);
  pcVar7 = *(char **)(iVar2 + 200);
  pcVar3 = pcVar7;
  if ((*(uint *)(iVar2 + 0x98) & 0x100) == 0) {
    cVar1 = *pcVar7;
    while (cVar1 == -0x12) {
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
  }
  iVar8 = *(int *)(iVar2 + 0xc4);
  param_2[8] = iVar8 - (int)pcVar7;
  param_2[10] = iVar8 - (int)pcVar3;
  param_2[0xb] = (int)pcVar3 - (int)pcVar7;
  pcVar3 = *(char **)(iVar2 + 0x60);
  iVar6 = iVar5;
  if (*(int *)(iVar2 + 0x6c) == 0) {
LAB_3012ac7c:
    if (iVar6 == 0) goto LAB_3012ac88;
    iVar8 = iVar8 - iVar6;
  }
  else {
    iVar6 = iVar2;
    if (iVar2 == 0) {
      iVar6 = *DAT_3012ae30;
    }
    if ((*(int *)(iVar6 + 0x94) != *DAT_3012ae34) || (*(int *)(iVar2 + 0x120) != 0)) {
      if (*(int *)(iVar2 + 0x120) == 0) {
        iVar6 = *(int *)(pcVar3 + -0x14);
      }
      else {
        iVar6 = *(int *)(*(int *)(iVar2 + 0x120) + 0x34);
      }
      goto LAB_3012ac7c;
    }
LAB_3012ac88:
    iVar8 = 0;
  }
  param_2[9] = iVar8;
  param_2[0x1b] = (int)pcVar3;
  param_2[0x1c] = *(int *)(iVar2 + 100);
  param_2[0x1d] = *(int *)(iVar2 + 0x68);
  pcVar4 = *(char **)(iVar2 + 100);
  pcVar7 = pcVar4;
  if ((*(uint *)(iVar2 + 0x98) & 0x100) == 0) {
    cVar1 = *pcVar4;
    while ((cVar1 == -0x12 && (pcVar7 < pcVar3))) {
      pcVar7 = pcVar7 + 1;
      cVar1 = *pcVar7;
    }
  }
  iVar6 = *(int *)(iVar2 + 0x60);
  param_2[0x1a] = iVar6 - (int)pcVar4;
  param_2[0x1e] = iVar6 - (int)pcVar7;
  param_2[0x1f] = (int)pcVar7 - (int)pcVar4;
  if (*(int *)(iVar2 + 0x6c) < 1) {
    iVar6 = 0;
  }
  else {
    iVar8 = iVar2;
    if (iVar2 == 0) {
      iVar8 = *DAT_3012ae30;
    }
    if ((*(int *)(iVar8 + 0x94) == *DAT_3012ae34) && (*(int *)(iVar2 + 0x120) == 0))
    goto LAB_3012ad44;
    iVar6 = iVar6 - iVar5;
  }
  param_2[0x20] = iVar6;
LAB_3012ad44:
  iVar5 = errnoOfTaskGet(param_1);
  param_2[0xc] = iVar5;
  if ((*(uint *)(iVar2 + 0x70) & 4) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = (**(code **)(*(int *)(DAT_3012ae38 + 0xc) + 0x28))(iVar2 + 0x40,1);
  }
  param_2[0xd] = iVar5;
  param_2[0xe] = *(int *)(iVar2 + 0x124);
  param_2[0xf] = *(int *)(iVar2 + 0x128);
  *(undefined1 *)(param_2 + 0x10) = *(undefined1 *)(iVar2 + 300);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3012adac @ 0x3012ADAC  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: bcopy, taskTcb
 * Вызывают: FUN_3012b140, taskRegsShow
 * Константы: 0x3012ADAC, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_3012adac(undefined4 param_1,void *param_2)

{
  int iVar1;
  void *__src;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  __src = *(void **)(iVar1 + 0x120);
  if (__src == (void *)0x0) {
    __src = (void *)(iVar1 + 0x1d0);
  }
  bcopy(__src,param_2,0x48);
  return 0;
}

/* ----------------------------------------------------------------
 * taskStatusString @ 0x3012ADF0  (примерный размер ~848 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 2
 * Вызывает: sprintf, taskTcb
 * Вызывают: FUN_30095574, FUN_300f5e28, FUN_3012b140
 * Константы: 0xFFFFFFFF, 0x3012ADF0, 0x3012AE1C
 * Данные: DAT_3012ae3c, DAT_3012b9ec
 * ---------------------------------------------------------------- */
undefined4 taskStatusString(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  uVar3 = *(uint *)(iVar1 + 0x70);
  if (uVar3 < 0x18) {
                    /* WARNING: Could not recover jumptable at 0x3012ae1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(DAT_3012ae3c + uVar3 * 4))();
    return uVar2;
  }
  sprintf(param_2,DAT_3012b9ec,uVar3);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_3012b140 @ 0x3012B140  (примерный размер ~452 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_3012adac, printf, sprintf, strlen, taskIdSelf, taskStatusString
 * Вызывают: FUN_3012b38c, taskShow
 * Константы: 0x3012B140
 * Данные: DAT_3012b9f4, DAT_3012b9f8, DAT_3012b9fc, DAT_3012ba00, DAT_3012ba04, DAT_3012ba08, DAT_3012ba0c, DAT_3012ba10
 * ---------------------------------------------------------------- */
void FUN_3012b140(int *param_1,int param_2)

{
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 local_74;
  int local_70;
  int local_6c;
  char local_68;
  char local_67;
  char local_66;
  char local_65;
  undefined1 auStack_64 [12];
  undefined1 auStack_58 [52];
  undefined4 local_24;
  undefined4 uStack_1c;
  
  local_70 = DAT_3012b9f4;
  local_6c = 0;
  local_68 = *DAT_3012b9f8;
  local_67 = DAT_3012b9f8[1];
  local_66 = DAT_3012b9f8[2];
  local_65 = DAT_3012b9f8[3];
  taskStatusString(*param_1,auStack_64);
  sVar1 = strlen((char *)(param_1 + 0x11));
  pcVar3 = DAT_3012b9fc;
  if (10 < sVar1) {
    pcVar3 = DAT_3012ba00;
  }
  printf(pcVar3,param_1 + 0x11);
  if ((((code *)*DAT_3012ba04 != (code *)0x0) && (*DAT_3012ba08 != 0)) &&
     (iVar2 = (*(code *)*DAT_3012ba04)(*DAT_3012ba08,0,param_1[4],5,5,&local_74), iVar2 == 0)) {
    (*(code *)*DAT_3012ba0c)(local_74,&local_70);
    (*(code *)*DAT_3012ba10)(local_74,&local_6c);
  }
  iVar2 = local_70;
  pcVar3 = DAT_3012ba14;
  if (param_1[4] != local_6c) {
    iVar2 = param_1[4];
    pcVar3 = DAT_3012ba18;
  }
  printf(pcVar3,iVar2);
  FUN_3012adac(*param_1,auStack_58);
  if (param_2 == 2) {
    if (param_1[0x21] != -1) {
      sprintf(&local_68,DAT_3012ba1c,param_1[0x21]);
    }
    iVar2 = taskIdSelf();
    uVar4 = DAT_3012ba20;
    if (iVar2 != *param_1) {
      uVar4 = uStack_1c;
    }
    iVar2 = param_1[0xc];
    pcVar5 = &local_68;
    pcVar3 = DAT_3012ba24;
  }
  else {
    iVar2 = taskIdSelf();
    uVar4 = DAT_3012ba20;
    if (iVar2 != *param_1) {
      uVar4 = uStack_1c;
    }
    iVar2 = param_1[0xc];
    pcVar5 = (char *)param_1[0xd];
    pcVar3 = DAT_3012ba28;
  }
  printf(pcVar3,*param_1,param_1[1],auStack_64,uVar4,local_24,iVar2,pcVar5);
  return;
}

/* ----------------------------------------------------------------
 * taskIdListSort @ 0x3012B304  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 1
 * Вызывает: taskPriorityGet
 * Вызывают: FUN_3012b38c, checkStack, taskWaitShowCoreRtn
 * Константы: 0x3012B304
 * ---------------------------------------------------------------- */
void taskIdListSort(undefined4 *param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int local_1c;
  int local_18;
  
  if (param_2 != 0) {
    do {
      bVar1 = false;
      taskPriorityGet(*param_1,&local_18);
      puVar3 = param_1 + 1;
      if (param_1 + param_2 <= puVar3) {
        return;
      }
      do {
        taskPriorityGet(*puVar3,&local_1c);
        if (local_1c < local_18) {
          uVar2 = *puVar3;
          *puVar3 = puVar3[-1];
          puVar3[-1] = uVar2;
          bVar1 = true;
        }
        puVar3 = puVar3 + 1;
        local_18 = local_1c;
      } while (puVar3 < param_1 + param_2);
    } while (bVar1);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3012b38c @ 0x3012B38C  (примерный размер ~284 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_3012b140, __rem32, fioRdString, printf, taskIdListGet, taskIdListSort, taskInfoGet
 * Вызывают: taskShow
 * Константы: 0x3012B38C
 * Данные: DAT_3012ba2c
 * ---------------------------------------------------------------- */
undefined4 FUN_3012b38c(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_874 [4];
  undefined1 auStack_870 [140];
  undefined4 local_7e4 [500];
  
  if ((param_2 & 1) == 0) {
    iVar1 = taskInfoGet(param_1,auStack_870);
    if (iVar1 == 0) {
      FUN_3012b140(auStack_870,((param_2 & 2) == 0) * '\x02' + '\x02');
    }
  }
  else {
    iVar3 = 0;
    iVar1 = taskIdListGet(local_7e4,500);
    taskIdListSort(local_7e4,iVar1);
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        iVar3 = iVar3 + 1;
        iVar2 = __rem32(iVar3,0x32);
        if (iVar2 == 0) {
          printf(DAT_3012ba2c);
          fioRdString(0,local_874,1);
          if (local_874[0] == 'q') {
            return 1;
          }
          if (local_874[0] == 'Q') {
            return 1;
          }
        }
        iVar2 = taskInfoGet(local_7e4[iVar4],auStack_870);
        if (iVar2 == 0) {
          FUN_3012b140(auStack_870,((param_2 & 2) == 0) * '\x02' + '\x02');
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * taskRegsShow @ 0x3012B584  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_3012adac, printf, regsShowOutput
 * Вызывают: FUN_30115680, taskShow
 * Константы: 0x3012B584
 * Данные: DAT_3012ba44, DAT_3012ba48
 * ---------------------------------------------------------------- */
void taskRegsShow(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_50 [72];
  
  if ((code *)*DAT_3012ba44 == (code *)0x0) {
    iVar1 = FUN_3012adac(param_1,auStack_50);
    if (iVar1 == -1) {
      printf(DAT_3012ba48,param_1);
    }
    else {
      regsShowOutput(auStack_50,0,0);
    }
  }
  else {
    (*(code *)*DAT_3012ba44)(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * taskOptionsString @ 0x3012B5F0  (примерный размер ~336 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: strcat, taskTcb
 * Вызывают: FUN_30095814, taskShow
 * Константы: 0x3012B5F0, 0xFFFFFFFF, 0x01000000
 * Данные: DAT_3012ba4c, DAT_3012ba50, DAT_3012ba54, DAT_3012ba58, DAT_3012ba5c, DAT_3012ba60, DAT_3012ba64, DAT_3012ba68
 * ---------------------------------------------------------------- */
undefined4 taskOptionsString(undefined4 param_1,char *param_2)

{
  int iVar1;
  char *__src;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  *param_2 = '\0';
  __src = DAT_3012ba4c;
  if ((*(uint *)(iVar1 + 0x98) & 1) == 0) {
    __src = DAT_3012ba50;
  }
  strcat(param_2,__src);
  if ((*(uint *)(iVar1 + 0x98) & 2) != 0) {
    strcat(param_2,DAT_3012ba54);
  }
  if ((*(uint *)(iVar1 + 0x98) & 4) != 0) {
    strcat(param_2,DAT_3012ba58);
  }
  if ((*(uint *)(iVar1 + 0x98) & 0x8000) != 0) {
    strcat(param_2,DAT_3012ba5c);
  }
  if ((*(uint *)(iVar1 + 0x98) & 0x1000) != 0) {
    strcat(param_2,DAT_3012ba60);
  }
  if ((*(uint *)(iVar1 + 0x98) & 0x1000000) != 0) {
    strcat(param_2,DAT_3012ba64);
  }
  if ((*(uint *)(iVar1 + 0x98) & 0x10) != 0) {
    strcat(param_2,DAT_3012ba68);
  }
  if ((*(uint *)(iVar1 + 0x98) & 0x20) != 0) {
    strcat(param_2,DAT_3012ba6c);
  }
  if ((*(uint *)(iVar1 + 0x98) & 0x40) != 0) {
    strcat(param_2,DAT_3012ba70);
  }
  if ((*(uint *)(iVar1 + 0x98) & 0x80) != 0) {
    strcat(param_2,DAT_3012ba74);
  }
  if ((*(uint *)(iVar1 + 0x98) & 0x100) != 0) {
    strcat(param_2,DAT_3012ba78);
  }
  if ((*(uint *)(iVar1 + 0x98) & 0x4000) != 0) {
    strcat(param_2,DAT_3012ba7c);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * taskShow @ 0x3012B740  (примерный размер ~900 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 15
 * Вызывает: FUN_3012b140, FUN_3012b38c, eventTaskShow, objNamePtrGet, printErr, printf, puts, taskEach, taskIdDefault, taskIdSelf, taskInfoGet, taskListCount, taskOptionsString, taskRegsShow
 *           ...
 * Константы: 0xFFFFFFFF, 0x3012B740
 * Данные: DAT_3012ba80, DAT_3012ba84, DAT_3012ba88, DAT_3012ba8c, DAT_3012ba90, DAT_3012ba94, DAT_3012ba98, DAT_3012ba9c
 * ---------------------------------------------------------------- */
undefined4 taskShow(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined1 auStack_198 [12];
  uint local_18c;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 uStack_170;
  undefined1 auStack_160 [44];
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 uStack_120;
  undefined1 auStack_10c [256];
  
  iVar1 = taskIdDefault();
  if (param_2 != 0) {
    if (param_2 == 1) {
      iVar2 = taskInfoGet(iVar1,auStack_198);
      if (iVar2 != 0) {
        printErr(DAT_3012ba84);
        return 0xffffffff;
      }
      taskOptionsString(iVar1,auStack_10c);
      printf(DAT_3012ba88);
      FUN_3012b140(auStack_198,4);
      printf(DAT_3012ba8c,local_180,local_17c,local_178);
      pcVar3 = DAT_3012ba94;
      uVar4 = DAT_3012ba90;
      if ((local_18c & 0x100) == 0) {
        pcVar3 = DAT_3012ba98;
        uVar4 = uStack_170;
      }
      printf(pcVar3,uVar4);
      printf(DAT_3012ba9c,local_12c,local_128,local_124,local_130);
      pcVar3 = DAT_3012baa0;
      uVar4 = DAT_3012ba90;
      if ((local_18c & 0x100) == 0) {
        pcVar3 = DAT_3012baa4;
        uVar4 = uStack_120;
      }
      printf(pcVar3,uVar4);
      uVar4 = objNamePtrGet(local_134);
      printf(DAT_3012baa8,local_134,uVar4);
      printf(DAT_3012baac,local_18c,auStack_10c);
      eventTaskShow(auStack_160);
      iVar2 = taskIdSelf();
      if (iVar2 != iVar1) {
        taskRegsShow(iVar1);
        if ((code *)*DAT_3012bab0 != (code *)0x0) {
          (*(code *)*DAT_3012bab0)(iVar1,0);
        }
      }
      if (*DAT_3012bab4 == 0) {
        return 0;
      }
      iVar1 = taskTcb(iVar1);
      if (iVar1 == 0) {
        return 0;
      }
      (*(code *)*DAT_3012bab4)(iVar1 + 0x1b4,0,0,0);
      return 0;
    }
    if (param_2 != 0x100) {
      if (param_2 == DAT_3012ba80) {
        printf(DAT_3012ba88);
        return 0;
      }
      iVar1 = taskListCount(*DAT_3012bab8);
      printf(DAT_3012ba88);
      if (iVar1 < 0x1f5) {
        FUN_3012b38c(0,5);
        return 0;
      }
      puts(DAT_3012babc);
      uVar4 = DAT_3012bac0;
      taskEach(DAT_3012bac0,4,0);
      taskEach(uVar4,4,1);
      return 0;
    }
  }
  iVar1 = taskInfoGet(iVar1,auStack_198);
  if (iVar1 == 0) {
    if (param_2 != 0x100) {
      printf(DAT_3012ba88);
    }
    FUN_3012b140(auStack_198,4);
    return 0;
  }
  printErr(DAT_3012ba84);
  return 0xffffffff;
}

