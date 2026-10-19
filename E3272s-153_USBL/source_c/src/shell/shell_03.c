/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : shell — командный интерпретатор VxWorks shell (C-интерпретатор, таблицы команд)
 * Часть  : 3 (функций: 9, адреса 0x30112838..0x30112E10)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * shellWorkingMemCtxDetach @ 0x30112838  (примерный размер ~244 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 9
 * Вызывает: FUN_301125c4, lstDelete, lstFirst, lstNext, semGive, semTake, shellFirst, shellMemFree, shellNext
 * Константы: 0xFFFFFFFF, 0x30112838
 * Данные: DAT_30112e80
 * ---------------------------------------------------------------- */
undefined4 shellWorkingMemCtxDetach(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == -1) {
    for (iVar2 = shellFirst(); iVar2 != 0; iVar2 = shellNext(iVar2)) {
      shellWorkingMemCtxDetach(iVar2,param_2);
    }
    return 0;
  }
  iVar2 = FUN_301125c4(param_1);
  if ((iVar2 != 0) && (iVar3 = semTake(*(undefined4 *)(iVar2 + 0xc),0xffffffff), iVar3 == 0)) {
    for (iVar3 = lstFirst(iVar2); iVar3 != 0; iVar3 = lstNext(iVar3)) {
      if (*(int *)(iVar3 + 0xc) == param_2) {
        lstDelete(iVar2,iVar3);
        shellMemFree(iVar3);
        iVar3 = *(int *)(iVar2 + 0x14);
        if (iVar3 == param_2) {
          iVar3 = 0;
          *(undefined4 *)(iVar2 + 0x14) = 0;
        }
        iVar1 = *(int *)(iVar2 + 0x10);
        if (*(int *)(iVar2 + 0x10) == param_2) {
          *(int *)(iVar2 + 0x10) = iVar3;
          iVar1 = iVar3;
        }
        if (iVar1 == 0) {
          *(undefined4 *)(iVar2 + 0x10) = *DAT_30112e80;
        }
        semGive(*(undefined4 *)(iVar2 + 0xc));
        return 0;
      }
    }
    semGive(*(undefined4 *)(iVar2 + 0xc));
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellWorkingMemCtxCurrentGet @ 0x3011292C  (примерный размер ~28 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_301125c4
 * Вызывают: FUN_30111224, shellWorkingMemCtxIdConvert
 * Константы: 0x3011292C
 * ---------------------------------------------------------------- */
undefined4 shellWorkingMemCtxCurrentGet(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_301125c4();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x10);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellWorkingMemCtxLastGet @ 0x30112948  (примерный размер ~28 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_301125c4
 * Вызывают: shellWorkingMemCtxIdConvert
 * Константы: 0x30112948
 * ---------------------------------------------------------------- */
undefined4 shellWorkingMemCtxLastGet(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_301125c4();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x14);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30112964 @ 0x30112964  (примерный размер ~116 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_301125c4, lstFirst, lstNext, semGive, semTake
 * Вызывают: shellWorkingMemCtxIdConvert
 * Константы: 0x30112964, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_30112964(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (((param_2 != 0) && (iVar1 = FUN_301125c4(), iVar1 != 0)) &&
     (iVar2 = semTake(*(undefined4 *)(iVar1 + 0xc),0xffffffff), iVar2 == 0)) {
    iVar2 = lstFirst(iVar1);
    while (iVar2 != 0) {
      if (*(int *)(iVar2 + 8) == param_2) {
        uVar3 = *(undefined4 *)(iVar2 + 0xc);
        break;
      }
      iVar2 = lstNext();
    }
    semGive(*(undefined4 *)(iVar1 + 0xc));
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * shellWorkingMemCtxIdConvert @ 0x301129D8  (примерный размер ~380 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_301125c4, FUN_30112964, shellInternalStrToInt, shellWorkingMemCtxCurrentGet, shellWorkingMemCtxLastGet
 * Константы: 0x301129D8
 * Данные: DAT_30112e80
 * ---------------------------------------------------------------- */
int shellWorkingMemCtxIdConvert(undefined4 param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int local_24;
  undefined1 auStack_20 [8];
  int local_18 [2];
  
  iVar5 = 0;
  if (param_2 == (char *)0x0) {
    return 0;
  }
  if (*param_2 != '%') {
    iVar2 = FUN_301125c4();
    if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) &&
        (pcVar3 = *(code **)(*(int *)(iVar2 + 0x18) + 4), pcVar3 != (code *)0x0)) &&
       (iVar5 = (*pcVar3)(param_2), iVar5 != 0)) {
      return iVar5;
    }
    iVar4 = shellInternalStrToInt(param_2,local_18,&local_24,auStack_20,0);
    if (iVar4 != 1) {
      return iVar5;
    }
    if (local_24 != 4) {
      return iVar5;
    }
    if (iVar2 == 0) {
      return local_18[0];
    }
    if (*(int *)(iVar2 + 0x18) == 0) {
      return local_18[0];
    }
    pcVar3 = *(code **)(*(int *)(iVar2 + 0x18) + 8);
    if (pcVar3 == (code *)0x0) {
      return local_18[0];
    }
    iVar5 = (*pcVar3)(*(undefined4 *)(iVar2 + 0x10),local_18[0]);
    return iVar5;
  }
  if (param_2[2] == '\0') {
    cVar1 = param_2[1];
    if (cVar1 == '+') {
      iVar5 = shellWorkingMemCtxCurrentGet(param_1);
    }
    else if (cVar1 == '-') {
      iVar5 = shellWorkingMemCtxLastGet(param_1);
    }
    else {
      if (cVar1 != '0') goto LAB_30112a58;
      iVar5 = *DAT_30112e80;
    }
    if (iVar5 != 0) {
      return iVar5;
    }
  }
LAB_30112a58:
  iVar2 = shellInternalStrToInt(param_2 + 1,local_18,&local_24,auStack_20,0);
  if ((iVar2 == 1) && (local_24 == 4)) {
    iVar5 = FUN_30112964(param_1,local_18[0]);
  }
  return iVar5;
}

/* ----------------------------------------------------------------
 * shellWorkingMemCtxAttachedShow @ 0x30112B54  (примерный размер ~352 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_301125c4, lstFirst, lstNext, semGive, semTake, shellPrint, shellWorkingMemCtxGet, strlen
 * Константы: 0x30112B54, 0xFFFFFFFF
 * Данные: DAT_30112e80, DAT_30112e94, DAT_30112e98, DAT_30112e9c, DAT_30112ea0, DAT_30112ea4
 * ---------------------------------------------------------------- */
void shellWorkingMemCtxAttachedShow(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  undefined4 local_44;
  char acStack_40 [24];
  undefined1 local_28;
  
  iVar1 = FUN_301125c4();
  if ((iVar1 != 0) && (iVar2 = semTake(*(undefined4 *)(iVar1 + 0xc),0xffffffff), iVar2 == 0)) {
    iVar11 = *(int *)(iVar1 + 0x10);
    iVar10 = *(int *)(iVar1 + 0x14);
    shellPrint(0,DAT_30112e94);
    shellPrint(0,DAT_30112e98);
    for (iVar2 = lstFirst(iVar1); pcVar12 = DAT_30112e9c, iVar2 != 0; iVar2 = lstNext(iVar2)) {
      iVar9 = *(int *)(iVar2 + 0xc);
      local_28 = 0;
      uVar8 = 0x20;
      if (iVar11 == iVar9) {
        uVar8 = 0x2b;
      }
      else if (iVar10 == iVar9) {
        uVar8 = 0x2d;
      }
      iVar3 = shellWorkingMemCtxGet(param_1,iVar9,acStack_40,0x18,&local_44);
      if ((iVar3 == 0) && (sVar4 = strlen(acStack_40), sVar4 != 0)) {
        pcVar12 = acStack_40;
      }
      if (*DAT_30112e80 == iVar9) {
        uVar7 = 0x18;
        uVar5 = DAT_30112ea4;
        uVar6 = uVar8;
      }
      else {
        pcVar12 = &IRQ;
        uVar5 = DAT_30112ea0;
        uVar6 = *(undefined4 *)(iVar2 + 8);
        uVar7 = uVar8;
      }
      shellPrint(0,uVar5,uVar6,uVar7,0x18,pcVar12);
    }
    semGive(*(undefined4 *)(iVar1 + 0xc));
    shellPrint(0,DAT_30112e94);
  }
  return;
}

/* ----------------------------------------------------------------
 * shellWorkingMemCtxCurrentSet @ 0x30112CB4  (примерный размер ~48 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_301125c4
 * Константы: 0x30112CB4
 * ---------------------------------------------------------------- */
void shellWorkingMemCtxCurrentSet(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_301125c4();
  if (iVar1 == 0) {
    return;
  }
  if (*(int *)(iVar1 + 0x10) == param_2) {
    return;
  }
  *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x10);
  *(int *)(iVar1 + 0x10) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * shellWorkingMemCtxDuplicate @ 0x30112CE4  (примерный размер ~300 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_301123c4, FUN_301125c4, lstAdd, lstFirst, lstNext, semGive, semTake
 * Вызывают: shellBackgroundInit
 * Константы: 0xFFFFFFFF, 0x30112CE4
 * Данные: DAT_30112e80
 * ---------------------------------------------------------------- */
undefined4 shellWorkingMemCtxDuplicate(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 == 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_301125c4(param_1);
  if ((iVar2 != 0) && (iVar3 = semTake(*(undefined4 *)(iVar2 + 0xc),0xffffffff), iVar3 == 0)) {
    iVar3 = FUN_301125c4(param_2);
    if ((iVar3 != 0) && (iVar4 = semTake(*(undefined4 *)(iVar3 + 0xc),0xffffffff), iVar4 == 0)) {
      iVar4 = lstFirst(iVar2);
      piVar1 = DAT_30112e80;
      do {
        if (iVar4 == 0) {
          *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
          *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
          *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(iVar2 + 0x18);
          semGive(*(undefined4 *)(iVar3 + 0xc));
          semGive(*(undefined4 *)(iVar2 + 0xc));
          return 0;
        }
        if (*piVar1 != *(int *)(iVar4 + 0xc)) {
          iVar5 = FUN_301123c4(*(int *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 0x10),
                               *(undefined4 *)(iVar4 + 8));
          if (iVar5 == 0) {
            semGive(*(undefined4 *)(iVar3 + 0xc));
            semGive(*(undefined4 *)(iVar2 + 0xc));
            return 0xffffffff;
          }
          lstAdd(iVar3,iVar5);
        }
        iVar4 = lstNext(iVar4);
      } while( true );
    }
    semGive(*(undefined4 *)(iVar2 + 0xc));
    return 0xffffffff;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_30112e10 @ 0x30112E10  (примерный размер ~152 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 6
 * Вызывает: lstDelete, lstFirst, lstNext, semDelete, semTake, shellMemFree
 * Константы: 0x30112E10, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void FUN_30112e10(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = semTake(*(undefined4 *)(param_3 + 0xc),0xffffffff);
  if (iVar1 == 0) {
    iVar1 = lstFirst(param_3);
    while (iVar1 != 0) {
      iVar2 = lstNext(iVar1);
      lstDelete(param_3,iVar1);
      shellMemFree(iVar1);
      iVar1 = iVar2;
    }
    semDelete(*(undefined4 *)(param_3 + 0xc));
    shellMemFree(param_3);
    return;
  }
  return;
}

