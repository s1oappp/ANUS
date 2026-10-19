/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : shell — командный интерпретатор VxWorks shell (C-интерпретатор, таблицы команд)
 * Часть  : 1 (функций: 150, адреса 0x3010052C..0x301092D0)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * shellCompletionPathnameGet @ 0x3010052C  (примерный размер ~568 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 14
 * Вызывает: __stdout, calloc, completionPathComplete, completionPathListGet, completionPathShow, fflush, free, lstFree, lstInit, shellPrint, shellPromptPrint, strcpy, strlen, strncpy
 * Вызывают: FUN_3010c7c0
 * Константы: 0xFFFFFFFF, 0x3010052C
 * Данные: DAT_3010075c, DAT_30100760
 * ---------------------------------------------------------------- */
undefined4
shellCompletionPathnameGet
          (undefined4 param_1,int *param_2,int param_3,int param_4,char *param_5,int param_6,
          int param_7)

{
  char *__src;
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined1 auStack_34 [12];
  undefined4 local_28;
  
  __src = (char *)calloc(2,param_6 + 1);
  if (__src == (char *)0x0) {
    return 0xffffffff;
  }
  lstInit(auStack_34);
  local_28 = param_1;
  iVar1 = completionPathListGet(auStack_34);
  if (iVar1 == -1) {
    free(__src);
    return 0xffffffff;
  }
  if ((param_7 != 0) || (iVar1 = completionPathShow(auStack_34,0), iVar1 == 1)) {
    iVar1 = completionPathComplete(auStack_34,__src,param_6);
  }
  lstFree(auStack_34);
  if (param_7 == 0) {
    if (iVar1 == 1) goto LAB_301005fc;
    if (1 < iVar1) {
      shellPromptPrint(0);
      shellPrint(0,DAT_30100760,param_5);
      puVar4 = (undefined4 *)__stdout();
      fflush((FILE *)*puVar4);
      uVar5 = 0;
      goto LAB_30100748;
    }
  }
  else if (0 < iVar1) {
LAB_301005fc:
    strcpy(__src + param_6 + 1,param_5);
    strncpy(param_5 + param_3,__src,(param_6 - param_3) - 1);
    sVar2 = strlen(param_5);
    sVar3 = strlen(param_5);
    strncpy(param_5 + sVar3,__src + param_6 + 1 + param_4,(param_6 - sVar2) - 1);
    iVar1 = *DAT_3010075c;
    uVar7 = (uint)(byte)param_5[*param_2];
    if (((((((*(byte *)(iVar1 + uVar7) & 7) != 0) || (uVar7 == 0x5f)) || (uVar7 == 0x2d)) ||
         ((uVar7 == 0x2b || (uVar7 == 0x2e)))) ||
        ((uVar7 == 0x3a || ((uVar7 == 0x2f || (uVar7 == 0x5c)))))) || (uVar7 == 0x20)) {
      while( true ) {
        uVar7 = (uint)(byte)param_5[*param_2 + 1];
        iVar6 = *param_2 + 1;
        if ((((((*(byte *)(iVar1 + uVar7) & 7) == 0) && (uVar7 != 0x5f)) && (uVar7 != 0x2d)) &&
            (((uVar7 != 0x2b && (uVar7 != 0x2e)) &&
             ((uVar7 != 0x3a && ((uVar7 != 0x2f && (uVar7 != 0x5c)))))))) && (uVar7 != 0x20)) break;
        *param_2 = iVar6;
      }
      *param_2 = iVar6;
    }
    uVar5 = 0;
    goto LAB_30100748;
  }
  uVar5 = 0xffffffff;
LAB_30100748:
  free(__src);
  return uVar5;
}

/* ----------------------------------------------------------------
 * shellConfigLibInit @ 0x30100764  (примерный размер ~140 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 4
 * Вызывает: lstInit, semMCreate, shellPrintErr, shellResourceReleaseHookAdd
 * Вызывают: FUN_301007f0, shellLibInit
 * Константы: 0xFFFFFFFF, 0x30100764
 * Данные: DAT_30101638, DAT_3010163c, DAT_30101640, DAT_30101644, DAT_30101648
 * ---------------------------------------------------------------- */
undefined4 shellConfigLibInit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_3010163c;
  iVar1 = DAT_30101638;
  if (*(int *)(DAT_30101638 + 4) == 0) {
    lstInit(DAT_3010163c);
    iVar2 = semMCreate(0);
    *(int *)(iVar3 + 0xc) = iVar2;
    if (iVar2 == 0) {
      shellPrintErr(0,DAT_30101640);
      return 0xffffffff;
    }
    iVar3 = shellResourceReleaseHookAdd(DAT_30101644);
    if (iVar3 != 0) {
      shellPrintErr(0,DAT_30101648);
      return 0xffffffff;
    }
    *(undefined4 *)(iVar1 + 4) = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_301007f0 @ 0x301007F0  (примерный размер ~36 байт)
 * Модуль: shell | Вызывают: 4 | Вызывает: 2
 * Вызывает: shellConfigLibInit, shellMemLibInit
 * Вызывают: shellConfigDefaultGet, shellConfigDefaultSet, shellConfigDefaultValueGet, shellConfigDefaultValueSet
 * Константы: 0x301007F0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_301007f0(void)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  iVar1 = shellMemLibInit();
  bVar3 = iVar1 == 0;
  if (bVar3) {
    iVar1 = shellConfigLibInit();
    bVar3 = iVar1 == 0;
  }
  if (bVar3) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30100814 @ 0x30100814  (примерный размер ~84 байт)
 * Модуль: shell | Вызывают: 5 | Вызывает: 3
 * Вызывает: lstFirst, lstNext, strcmp
 * Вызывают: FUN_30100920, FUN_30100e2c, FUN_30101228, FUN_30101460, shellConfigDefaultValueUnset
 * Константы: 0x30100814
 * ---------------------------------------------------------------- */
int FUN_30100814(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = lstFirst(param_1);
  while ((iVar1 != 0 && (iVar2 = strcmp(*(char **)(iVar1 + 8),param_2), iVar2 != 0))) {
    iVar1 = lstNext(iVar1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30100868 @ 0x30100868  (примерный размер ~184 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 5
 * Вызывает: lstAdd, shellMemFree, shellMemMalloc, strcpy, strlen
 * Вызывают: FUN_30100920, FUN_30101228
 * Константы: 0x30100868
 * ---------------------------------------------------------------- */
int FUN_30100868(undefined4 param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  int iVar2;
  char *__dest;
  
  sVar1 = strlen(param_2);
  iVar2 = shellMemMalloc(sVar1 + 0x19);
  if (iVar2 == 0) {
    return 0;
  }
  if (param_3 == (char *)0x0) {
    sVar1 = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
  else {
    sVar1 = strlen(param_3);
    __dest = (char *)shellMemMalloc(sVar1 + 1);
    *(char **)(iVar2 + 0xc) = __dest;
    if (__dest == (char *)0x0) {
      shellMemFree(iVar2);
      return 0;
    }
    strcpy(__dest,param_3);
    sVar1 = strlen(param_3);
  }
  *(size_t *)(iVar2 + 0x10) = sVar1;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(char **)(iVar2 + 8) = (char *)(iVar2 + 0x18);
  strcpy((char *)(iVar2 + 0x18),param_2);
  lstAdd(param_1,iVar2);
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_30100920 @ 0x30100920  (примерный размер ~212 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 6
 * Вызывает: FUN_30100814, FUN_30100868, shellMemFree, shellMemMalloc, strcpy, strlen
 * Вызывают: FUN_301009f4, shellConfigDefaultValueSet, shellConfigValueSet
 * Константы: 0xFFFFFFFF, 0x30100920
 * ---------------------------------------------------------------- */
undefined4 FUN_30100920(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_30100814(param_1,param_3);
  if ((iVar1 == 0) && (iVar1 = FUN_30100868(param_1,param_3,param_4), iVar1 == 0)) {
    return 0xffffffff;
  }
  if (param_4 == (char *)0x0) {
    uVar4 = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    shellMemFree(uVar4);
  }
  else {
    sVar2 = strlen(param_4);
    if (*(uint *)(iVar1 + 0x10) < sVar2) {
      sVar2 = strlen(param_4);
      iVar3 = shellMemMalloc(sVar2 + 1);
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      shellMemFree(*(undefined4 *)(iVar1 + 0xc));
      *(int *)(iVar1 + 0xc) = iVar3;
      sVar2 = strlen(param_4);
      *(size_t *)(iVar1 + 0x10) = sVar2;
    }
    strcpy(*(char **)(iVar1 + 0xc),param_4);
    *(undefined4 *)(iVar1 + 0x14) = 0;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_301009f4 @ 0x301009F4  (примерный размер ~552 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_30100920, __errno, shellInternalStrTokenize, shellInternalStrUnquote, shellMemFree, shellMemStrdup, strlen
 * Вызывают: shellConfigDefaultSet, shellConfigSet
 * Константы: 0xFFFFFFFF, 0x301009F4
 * Данные: DAT_3010164c, DAT_30101650, DAT_30101654, DAT_30101658
 * ---------------------------------------------------------------- */
undefined4 FUN_301009f4(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  byte *__s;
  byte *__s_00;
  size_t sVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  
  if (param_3 != 0) {
    iVar2 = shellMemStrdup(param_3);
    iVar5 = iVar2;
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    while (iVar5 = shellInternalStrTokenize(iVar5,DAT_30101658,auStack_2c), iVar5 != 0) {
      __s = (byte *)shellInternalStrTokenize(iVar5,DAT_3010164c,auStack_28);
      __s_00 = (byte *)shellInternalStrTokenize(0,DAT_3010164c,auStack_28);
      if (__s == (byte *)0x0) break;
      iVar5 = *DAT_30101650;
      bVar1 = *(byte *)(iVar5 + (uint)*__s);
      while ((bVar1 & 0x28) != 0) {
        __s = __s + 1;
        bVar1 = *(byte *)(iVar5 + (uint)*__s);
      }
      sVar3 = strlen((char *)__s);
      bVar1 = *(byte *)(iVar5 + (uint)__s[sVar3 - 1]);
      while ((bVar1 & 0x28) != 0) {
        sVar3 = strlen((char *)__s);
        __s[sVar3 - 1] = 0;
        sVar3 = strlen((char *)__s);
        bVar1 = *(byte *)(iVar5 + (uint)__s[sVar3 - 1]);
      }
      if (*__s == 0) break;
      if (__s_00 != (byte *)0x0) {
        bVar1 = *(byte *)(iVar5 + (uint)*__s_00);
        while ((bVar1 & 0x28) != 0) {
          __s_00 = __s_00 + 1;
          bVar1 = *(byte *)(iVar5 + (uint)*__s_00);
        }
        sVar3 = strlen((char *)__s_00);
        bVar1 = *(byte *)(iVar5 + (uint)__s_00[sVar3 - 1]);
        while ((bVar1 & 0x28) != 0) {
          sVar3 = strlen((char *)__s_00);
          __s_00[sVar3 - 1] = 0;
          sVar3 = strlen((char *)__s_00);
          bVar1 = *(byte *)(iVar5 + (uint)__s_00[sVar3 - 1]);
        }
        __s_00 = (byte *)shellInternalStrUnquote(__s_00);
        if (__s_00 == (byte *)0x0) {
          shellMemFree(iVar2);
          puVar4 = (undefined4 *)__errno();
          *puVar4 = DAT_30101654;
          return 0xffffffff;
        }
      }
      iVar5 = shellInternalStrUnquote(__s);
      if (iVar5 == 0) {
        shellMemFree(iVar2);
        puVar4 = (undefined4 *)__errno();
        *puVar4 = DAT_30101654;
        return 0xffffffff;
      }
      iVar5 = FUN_30100920(param_1,param_2,iVar5,__s_00);
      if (iVar5 != 0) {
        shellMemFree(iVar2);
        return 0xffffffff;
      }
      iVar5 = 0;
    }
    shellMemFree(iVar2);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellConfigDefaultSet @ 0x30100C1C  (примерный размер ~84 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_301007f0, FUN_301009f4, semGive, semTake
 * Вызывают: FUN_3003ffc8
 * Константы: 0xFFFFFFFF, 0x30100C1C
 * Данные: DAT_3010163c
 * ---------------------------------------------------------------- */
undefined4 shellConfigDefaultSet(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_301007f0();
  iVar1 = DAT_3010163c;
  semTake(*(undefined4 *)(DAT_3010163c + 0xc),0xffffffff);
  iVar2 = FUN_301009f4(iVar1,1,param_1);
  if (iVar2 != 0) {
    semGive(*(undefined4 *)(iVar1 + 0xc));
    return 0xffffffff;
  }
  semGive(*(undefined4 *)(iVar1 + 0xc));
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30100c70 @ 0x30100C70  (примерный размер ~160 байт)
 * Модуль: shell | Вызывают: 5 | Вызывает: 6
 * Вызывает: __errno, lstInit, shellDataAdd, shellDataGet, shellMemFree, shellMemMalloc
 * Вызывают: shellConfigGet, shellConfigSet, shellConfigValueGet, shellConfigValueSet, shellConfigValueUnset
 * Константы: 0x30100C70
 * Данные: DAT_3010165c, DAT_30101660, DAT_30101664
 * ---------------------------------------------------------------- */
int FUN_30100c70(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int local_14;
  
  puVar1 = (undefined4 *)__errno();
  uVar4 = *puVar1;
  iVar2 = shellDataGet(param_1,DAT_3010165c,&local_14);
  if (iVar2 != 0) {
    piVar3 = (int *)__errno();
    if (*piVar3 == DAT_30101660) {
      puVar1 = (undefined4 *)__errno(*piVar3);
      *puVar1 = uVar4;
      local_14 = shellMemMalloc(0xc);
      if (local_14 == 0) {
        local_14 = 0;
      }
      else {
        lstInit(local_14);
        iVar2 = shellDataAdd(param_1,DAT_3010165c,local_14,DAT_30101664);
        if (iVar2 != 0) {
          shellMemFree(local_14);
          local_14 = 0;
        }
      }
    }
    else {
      local_14 = 0;
    }
  }
  return local_14;
}

/* ----------------------------------------------------------------
 * shellConfigSet @ 0x30100D10  (примерный размер ~112 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 5
 * Вызывает: FUN_301009f4, FUN_30100c70, __errno, shellFromTaskGet, shellIdVerify
 * Вызывают: shConfig, shellTask
 * Константы: 0xFFFFFFFF, 0x30100D10
 * Данные: DAT_30101668
 * ---------------------------------------------------------------- */
undefined4 shellConfigSet(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = shellIdVerify();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30101668;
    return 0xffffffff;
  }
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = FUN_30100c70(param_1);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  uVar3 = FUN_301009f4(iVar1,0,param_2);
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_30100d80 @ 0x30100D80  (примерный размер ~172 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: sprintf, strpbrk
 * Вызывают: FUN_30100e2c
 * Константы: 0x30100D80
 * Данные: DAT_30101638, DAT_3010166c, DAT_30101670
 * ---------------------------------------------------------------- */
void FUN_30100d80(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = DAT_30101638;
  uVar4 = *DAT_30101638;
  pcVar2 = strpbrk(*(char **)(param_2 + 8),(char *)DAT_30101638[3]);
  if (pcVar2 != (char *)0x0) {
    *puVar1 = puVar1[2];
  }
  if ((*(char **)(param_2 + 0xc) != (char *)0x0) &&
     (pcVar2 = strpbrk(*(char **)(param_2 + 0xc),(char *)puVar1[3]), pcVar2 != (char *)0x0)) {
    uVar4 = puVar1[2];
  }
  iVar3 = DAT_3010166c;
  if (*(int *)(param_2 + 0xc) != 0) {
    iVar3 = *(int *)(param_2 + 0xc);
  }
  pcVar2 = (char *)*param_1;
  iVar3 = sprintf(pcVar2,DAT_30101670,*puVar1,*(undefined4 *)(param_2 + 8),*puVar1,uVar4,iVar3,uVar4
                 );
  *param_1 = pcVar2 + iVar3;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30100e2c @ 0x30100E2C  (примерный размер ~472 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_30100814, FUN_30100d80, lstFirst, lstNext, shellMemMalloc, strlen
 * Вызывают: shellConfigDefaultGet, shellConfigGet
 * Константы: 0x30100E2C
 * ---------------------------------------------------------------- */
undefined1 * FUN_30100e2c(undefined4 param_1,int param_2)

{
  int iVar1;
  size_t sVar2;
  undefined1 *puVar3;
  int iVar4;
  size_t sVar5;
  bool bVar6;
  undefined1 *local_20;
  
  iVar4 = 1;
  for (iVar1 = lstFirst(); iVar1 != 0; iVar1 = lstNext(iVar1)) {
    sVar5 = 0;
    if (*(char **)(iVar1 + 0xc) != (char *)0x0) {
      sVar5 = strlen(*(char **)(iVar1 + 0xc));
    }
    sVar2 = strlen(*(char **)(iVar1 + 8));
    iVar4 = sVar2 + iVar4 + sVar5 + 6;
  }
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstFirst(param_2);
  }
  for (; iVar1 != 0; iVar1 = lstNext(iVar1)) {
    sVar5 = 0;
    if (*(char **)(iVar1 + 0xc) != (char *)0x0) {
      sVar5 = strlen(*(char **)(iVar1 + 0xc));
    }
    sVar2 = strlen(*(char **)(iVar1 + 8));
    iVar4 = sVar2 + iVar4 + sVar5 + 6;
  }
  puVar3 = (undefined1 *)shellMemMalloc(iVar4);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    bVar6 = true;
    local_20 = puVar3;
    iVar1 = lstFirst(param_1);
    while (iVar1 != 0) {
      iVar4 = FUN_30100814(param_2,*(undefined4 *)(iVar1 + 8));
      if (iVar4 == 0) {
        iVar4 = iVar1;
      }
      if (*(int *)(iVar4 + 0x14) == 0) {
        FUN_30100d80(&local_20,iVar4);
        bVar6 = false;
      }
      iVar1 = lstNext(iVar1);
      if (*(int *)(iVar4 + 0x14) == 0) {
        if (iVar1 == 0) break;
        *local_20 = 0x2c;
        local_20 = local_20 + 1;
      }
    }
    if (param_2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = lstFirst(param_2);
    }
    for (; iVar1 != 0; iVar1 = lstNext(iVar1)) {
      if ((*(int *)(iVar1 + 0x14) == 0) &&
         (iVar4 = FUN_30100814(param_1,*(undefined4 *)(iVar1 + 8)), iVar4 == 0)) {
        if (!bVar6) {
          *local_20 = 0x2c;
          local_20 = local_20 + 1;
        }
        bVar6 = false;
        FUN_30100d80(&local_20,iVar1);
      }
    }
  }
  return puVar3;
}

/* ----------------------------------------------------------------
 * shellConfigDefaultGet @ 0x30101004  (примерный размер ~128 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_301007f0, FUN_30100e2c, malloc, semGive, semTake, shellMemFree, strcpy, strlen
 * Константы: 0x30101004, 0xFFFFFFFF
 * Данные: DAT_3010163c
 * ---------------------------------------------------------------- */
char * shellConfigDefaultGet(void)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  char *__dest;
  
  FUN_301007f0();
  iVar1 = DAT_3010163c;
  semTake(*(undefined4 *)(DAT_3010163c + 0xc),0xffffffff);
  __s = (char *)FUN_30100e2c(iVar1,0);
  if (__s == (char *)0x0) {
    semGive(*(undefined4 *)(iVar1 + 0xc));
    return (char *)0x0;
  }
  semGive(*(undefined4 *)(iVar1 + 0xc));
  sVar2 = strlen(__s);
  __dest = (char *)malloc(sVar2 + 1);
  if (__dest != (char *)0x0) {
    strcpy(__dest,__s);
  }
  shellMemFree(__s);
  return __dest;
}

/* ----------------------------------------------------------------
 * shellConfigGet @ 0x30101084  (примерный размер ~208 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 11
 * Вызывает: FUN_30100c70, FUN_30100e2c, __errno, malloc, semGive, semTake, shellFromTaskGet, shellIdVerify, shellMemFree, strcpy, strlen
 * Вызывают: shConfig, shellBackgroundInit
 * Константы: 0x30101084, 0xFFFFFFFF
 * Данные: DAT_3010163c, DAT_30101668
 * ---------------------------------------------------------------- */
char * shellConfigGet(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  char *__s;
  size_t sVar4;
  char *__dest;
  
  iVar1 = shellIdVerify();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30101668;
    return (char *)0x0;
  }
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar3 = FUN_30100c70(param_1);
  iVar1 = DAT_3010163c;
  if (iVar3 == 0) {
    return (char *)0x0;
  }
  semTake(*(undefined4 *)(DAT_3010163c + 0xc),0xffffffff);
  __s = (char *)FUN_30100e2c(iVar1,iVar3);
  if (__s == (char *)0x0) {
    semGive(*(undefined4 *)(iVar1 + 0xc));
    return (char *)0x0;
  }
  semGive(*(undefined4 *)(iVar1 + 0xc));
  sVar4 = strlen(__s);
  __dest = (char *)malloc(sVar4 + 1);
  if (__dest != (char *)0x0) {
    strcpy(__dest,__s);
  }
  shellMemFree(__s);
  return __dest;
}

/* ----------------------------------------------------------------
 * shellConfigDefaultValueSet @ 0x30101154  (примерный размер ~92 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_301007f0, FUN_30100920, semGive, semTake
 * Константы: 0xFFFFFFFF, 0x30101154
 * Данные: DAT_3010163c
 * ---------------------------------------------------------------- */
undefined4 shellConfigDefaultValueSet(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_301007f0();
  iVar1 = DAT_3010163c;
  semTake(*(undefined4 *)(DAT_3010163c + 0xc),0xffffffff);
  iVar2 = FUN_30100920(iVar1,1,param_1,param_2);
  if (iVar2 != 0) {
    semGive(*(undefined4 *)(iVar1 + 0xc));
    return 0xffffffff;
  }
  semGive(*(undefined4 *)(iVar1 + 0xc));
  return 0;
}

/* ----------------------------------------------------------------
 * shellConfigValueSet @ 0x301011B0  (примерный размер ~120 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 5
 * Вызывает: FUN_30100920, FUN_30100c70, __errno, shellFromTaskGet, shellIdVerify
 * Вызывают: FUN_3010fc88, FUN_3010ff7c, shellInterpEvaluate
 * Константы: 0xFFFFFFFF, 0x301011B0
 * Данные: DAT_30101668
 * ---------------------------------------------------------------- */
undefined4 shellConfigValueSet(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = shellIdVerify();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30101668;
    return 0xffffffff;
  }
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = FUN_30100c70(param_1);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  uVar3 = FUN_30100920(iVar1,0,param_2,param_3);
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_30101228 @ 0x30101228  (примерный размер ~252 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_30100814, FUN_30100868, lstDelete, shellMemFree
 * Вызывают: shellConfigDefaultValueUnset, shellConfigValueUnset
 * Константы: 0x30101228
 * ---------------------------------------------------------------- */
void FUN_30101228(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_30100814(param_1,param_4);
  iVar2 = FUN_30100814(param_2,param_4);
  if ((iVar1 == 0) && (iVar2 == 0)) {
    return;
  }
  if (param_3 == 0) {
    if (iVar1 == 0) {
      if (iVar2 != 0) {
        iVar1 = FUN_30100868(param_1,param_4,0);
        if (iVar1 == 0) {
          return;
        }
        goto LAB_301012f8;
      }
    }
    else if (iVar2 != 0) {
LAB_301012f8:
      *(undefined4 *)(iVar1 + 0x14) = 1;
      return;
    }
    lstDelete(param_1,iVar1);
    shellMemFree(*(undefined4 *)(iVar1 + 0xc));
  }
  else {
    if (iVar2 == 0) {
      return;
    }
    lstDelete(param_2,iVar2);
    shellMemFree(*(undefined4 *)(iVar2 + 0xc));
    shellMemFree(iVar2);
    if (iVar1 == 0) {
      return;
    }
    if (*(int *)(iVar1 + 0x14) == 0) {
      return;
    }
    lstDelete(param_1,iVar1);
    shellMemFree(*(undefined4 *)(iVar1 + 0xc));
  }
  shellMemFree(iVar1);
  return;
}

/* ----------------------------------------------------------------
 * shellConfigDefaultValueUnset @ 0x30101324  (примерный размер ~172 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_30100814, FUN_30101228, lstDelete, semGive, semTake, shellDataFirst, shellDataNext, shellMemFree
 * Константы: 0x30101324, 0xFFFFFFFF
 * Данные: DAT_3010163c, DAT_3010165c
 * ---------------------------------------------------------------- */
void shellConfigDefaultValueUnset(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_1c;
  
  iVar1 = DAT_3010163c;
  semTake(*(undefined4 *)(DAT_3010163c + 0xc),0xffffffff);
  FUN_30101228(0,iVar1,1,param_1);
  for (iVar2 = shellDataFirst(DAT_3010165c,&local_1c); iVar2 != 0;
      iVar2 = shellDataNext(DAT_3010165c,iVar2,&local_1c)) {
    iVar3 = FUN_30100814(local_1c,param_1);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x14) != 0)) {
      lstDelete(local_1c,iVar3);
      shellMemFree(*(undefined4 *)(iVar3 + 0xc));
      shellMemFree(iVar3);
    }
  }
  semGive(*(undefined4 *)(iVar1 + 0xc));
  return;
}

/* ----------------------------------------------------------------
 * shellConfigValueUnset @ 0x301013D0  (примерный размер ~144 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_30100c70, FUN_30101228, __errno, semGive, semTake, shellFromTaskGet, shellIdVerify
 * Вызывают: shellInterpEvaluate
 * Константы: 0xFFFFFFFF, 0x301013D0
 * Данные: DAT_3010163c, DAT_30101668
 * ---------------------------------------------------------------- */
undefined4 shellConfigValueUnset(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = shellIdVerify();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30101668;
    return 0xffffffff;
  }
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar3 = FUN_30100c70(param_1);
  iVar1 = DAT_3010163c;
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  semTake(*(undefined4 *)(DAT_3010163c + 0xc),0xffffffff);
  FUN_30101228(iVar3,iVar1,0,param_2);
  semGive(*(undefined4 *)(iVar1 + 0xc));
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30101460 @ 0x30101460  (примерный размер ~100 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_30100814
 * Вызывают: shellConfigDefaultValueGet, shellConfigValueGet
 * Константы: 0x30101460
 * Данные: DAT_30101674
 * ---------------------------------------------------------------- */
int FUN_30101460(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_30100814(param_2,param_3);
  if ((iVar1 == 0) && (iVar1 = FUN_30100814(param_1,param_3), iVar1 == 0)) {
    return 0;
  }
  if (*(int *)(iVar1 + 0xc) == 0) {
    return *DAT_30101674;
  }
  return *(int *)(iVar1 + 0xc);
}

/* ----------------------------------------------------------------
 * shellConfigDefaultValueGet @ 0x301014C4  (примерный размер ~88 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_301007f0, FUN_30101460, semGive, semTake
 * Константы: 0x301014C4, 0xFFFFFFFF
 * Данные: DAT_3010163c
 * ---------------------------------------------------------------- */
int shellConfigDefaultValueGet(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_301007f0();
  iVar1 = DAT_3010163c;
  semTake(*(undefined4 *)(DAT_3010163c + 0xc),0xffffffff);
  iVar2 = FUN_30101460(iVar1,0,param_1);
  if (iVar2 == 0) {
    semGive(*(undefined4 *)(iVar1 + 0xc));
    return 0;
  }
  semGive(*(undefined4 *)(iVar1 + 0xc));
  return iVar2;
}

/* ----------------------------------------------------------------
 * shellConfigValueGet @ 0x3010151C  (примерный размер ~156 байт)
 * Модуль: shell | Вызывают: 5 | Вызывает: 6
 * Вызывает: FUN_30100c70, FUN_30101460, semGive, semTake, shellFromTaskGet, shellIdVerify
 * Вызывают: FUN_3010fc88, FUN_3010ff7c, FUN_30115590, shellInternalSymbolGet, shellLineLenGet
 * Константы: 0x3010151C, 0xFFFFFFFF
 * Данные: DAT_3010163c
 * ---------------------------------------------------------------- */
int shellConfigValueGet(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = shellIdVerify();
  if (iVar1 != 0) {
    return 0;
  }
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar2 = FUN_30100c70(param_1);
  iVar1 = DAT_3010163c;
  if (iVar2 == 0) {
    return 0;
  }
  semTake(*(undefined4 *)(DAT_3010163c + 0xc),0xffffffff);
  iVar2 = FUN_30101460(iVar1,iVar2,param_2);
  if (iVar2 == 0) {
    semGive(*(undefined4 *)(iVar1 + 0xc));
    return 0;
  }
  semGive(*(undefined4 *)(iVar1 + 0xc));
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_301015b8 @ 0x301015B8  (примерный размер ~192 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 4
 * Вызывает: lstDelete, lstFirst, lstNext, shellMemFree
 * Константы: 0x301015B8
 * ---------------------------------------------------------------- */
void FUN_301015b8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = lstFirst(param_3);
  while (iVar1 != 0) {
    iVar2 = lstNext(iVar1);
    lstDelete(param_3,iVar1);
    shellMemFree(*(undefined4 *)(iVar1 + 0xc));
    shellMemFree(iVar1);
    iVar1 = iVar2;
  }
  shellMemFree(param_3);
  return;
}

/* ----------------------------------------------------------------
 * shellDataAdd @ 0x30101678  (примерный размер ~220 байт)
 * Модуль: shell | Вызывают: 11 | Вызывает: 10
 * Вызывает: __errno, lstAdd, lstFirst, lstNext, shellFromTaskGet, shellIdVerify, shellMemMalloc, strcmp, strcpy, strlen
 * Вызывают: FUN_30100c70, FUN_301124fc, FUN_30114a38, FUN_30114ebc, FUN_301150d4, dbgDisassemble, memoryDump, memoryModify, shellDataFromNameAdd, shellMemStringAdd
 *           ...
 * Константы: 0xFFFFFFFF, 0x30101678
 * Данные: DAT_30101a80
 * ---------------------------------------------------------------- */
undefined4 shellDataAdd(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  size_t sVar4;
  
  iVar1 = shellIdVerify();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30101a80;
    return 0xffffffff;
  }
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = lstFirst(param_1 + 0x1c);
  if (iVar1 != 0) {
    do {
      iVar3 = strcmp(*(char **)(iVar1 + 8),param_2);
      if (iVar3 == 0) break;
      iVar1 = lstNext(iVar1);
    } while (iVar1 != 0);
    if (iVar1 != 0) goto LAB_30101744;
  }
  sVar4 = strlen(param_2);
  iVar1 = shellMemMalloc(sVar4 + 0x15);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  *(char **)(iVar1 + 8) = (char *)(iVar1 + 0x14);
  strcpy((char *)(iVar1 + 0x14),param_2);
  lstAdd(param_1 + 0x1c,iVar1);
LAB_30101744:
  *(undefined4 *)(iVar1 + 0xc) = param_3;
  *(undefined4 *)(iVar1 + 0x10) = param_4;
  return 0;
}

/* ----------------------------------------------------------------
 * shellDataFromNameAdd @ 0x30101754  (примерный размер ~68 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 3
 * Вызывает: __errno, shellDataAdd, shellFromNameGet
 * Вызывают: shellParserControl
 * Константы: 0x30101754, 0xFFFFFFFF
 * Данные: DAT_30101a80
 * ---------------------------------------------------------------- */
undefined4
shellDataFromNameAdd(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = shellFromNameGet();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30101a80;
    return 0xffffffff;
  }
  uVar3 = shellDataAdd(iVar1,param_2,param_3,param_4);
  return uVar3;
}

/* ----------------------------------------------------------------
 * shellDataRemove @ 0x30101798  (примерный размер ~192 байт)
 * Модуль: shell | Вызывают: 5 | Вызывает: 7
 * Вызывает: lstDelete, lstFirst, lstNext, shellFromTaskGet, shellIdVerify, shellMemFree, strcmp
 * Вызывают: FUN_30114a38, FUN_30114ebc, FUN_30115680, shellParserControl, shellTask
 * Константы: 0x30101798
 * ---------------------------------------------------------------- */
void shellDataRemove(int param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = shellIdVerify();
  if (iVar1 == 0) {
    if (param_1 == 0) {
      param_1 = shellFromTaskGet(0);
    }
    iVar1 = lstFirst(param_1 + 0x1c);
    if (iVar1 != 0) {
      do {
        iVar2 = strcmp(*(char **)(iVar1 + 8),param_2);
        if (iVar2 == 0) break;
        iVar1 = lstNext(iVar1);
      } while (iVar1 != 0);
      if (iVar1 != 0) {
        if ((param_3 != 0) && (*(code **)(iVar1 + 0x10) != (code *)0x0)) {
          (**(code **)(iVar1 + 0x10))
                    (param_1,*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc));
        }
        lstDelete(param_1 + 0x1c,iVar1);
        shellMemFree(iVar1);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * shellDataAllRemove @ 0x30101858  (примерный размер ~164 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 6
 * Вызывает: lstDelete, lstFirst, lstNext, shellFromTaskGet, shellIdVerify, shellMemFree
 * Вызывают: shellContextFinalize
 * Константы: 0x30101858
 * ---------------------------------------------------------------- */
void shellDataAllRemove(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = shellIdVerify();
  if (iVar1 == 0) {
    if (param_1 == 0) {
      param_1 = shellFromTaskGet(0);
    }
    iVar1 = lstFirst(param_1 + 0x1c);
    while (iVar1 != 0) {
      iVar2 = lstNext(iVar1);
      if ((param_2 != 0) && (*(code **)(iVar1 + 0x10) != (code *)0x0)) {
        (**(code **)(iVar1 + 0x10))(param_1,*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc))
        ;
      }
      lstDelete(param_1 + 0x1c,iVar1);
      shellMemFree(iVar1);
      iVar1 = iVar2;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * shellDataGet @ 0x301018FC  (примерный размер ~172 байт)
 * Модуль: shell | Вызывают: 14 | Вызывает: 6
 * Вызывает: __errno, lstFirst, lstNext, shellFromTaskGet, shellIdVerify, strcmp
 * Вызывают: FUN_30100c70, FUN_301118ec, FUN_301125c4, FUN_301159dc, dbgDisassemble, memoryDump, memoryModify, shellDataFirst, shellDataFromNameGet, shellDataNext
 *           ...
 * Константы: 0xFFFFFFFF, 0x301018FC
 * Данные: DAT_30101a80, DAT_30101a84
 * ---------------------------------------------------------------- */
undefined4 shellDataGet(int param_1,char *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = shellIdVerify();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30101a80;
    return 0xffffffff;
  }
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = lstFirst(param_1 + 0x1c);
  if (iVar1 != 0) {
    do {
      iVar3 = strcmp(*(char **)(iVar1 + 8),param_2);
      if (iVar3 == 0) break;
      iVar1 = lstNext(iVar1);
    } while (iVar1 != 0);
    if (iVar1 != 0) {
      *param_3 = *(undefined4 *)(iVar1 + 0xc);
      return 0;
    }
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = DAT_30101a84;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellDataFromNameGet @ 0x301019A8  (примерный размер ~60 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 3
 * Вызывает: __errno, shellDataGet, shellFromNameGet
 * Константы: 0x301019A8, 0xFFFFFFFF
 * Данные: DAT_30101a80
 * ---------------------------------------------------------------- */
undefined4 shellDataFromNameGet(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = shellFromNameGet();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30101a80;
    return 0xffffffff;
  }
  uVar3 = shellDataGet(iVar1,param_2,param_3);
  return uVar3;
}

/* ----------------------------------------------------------------
 * shellDataFirst @ 0x301019E4  (примерный размер ~68 байт)
 * Модуль: shell | Вызывают: 4 | Вызывает: 3
 * Вызывает: shellDataGet, shellFirst, shellNext
 * Вызывают: FUN_30115680, shellConfigDefaultValueUnset, shellDataNext, shellParserControl
 * Константы: 0x301019E4
 * ---------------------------------------------------------------- */
int shellDataFirst(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = shellFirst();
  while ((iVar1 != 0 && (iVar2 = shellDataGet(iVar1,param_1,param_2), iVar2 != 0))) {
    iVar1 = shellNext(iVar1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellDataNext @ 0x30101A28  (примерный размер ~96 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 3
 * Вызывает: shellDataFirst, shellDataGet, shellNext
 * Вызывают: FUN_30115680, shellConfigDefaultValueUnset, shellParserControl
 * Константы: 0x30101A28
 * ---------------------------------------------------------------- */
int shellDataNext(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    param_2 = shellDataFirst(param_1,param_3);
  }
  else {
    do {
      param_2 = shellNext(param_2);
      if (param_2 == 0) {
        return 0;
      }
      iVar1 = shellDataGet(param_2,param_1,param_3);
    } while (iVar1 != 0);
  }
  return param_2;
}

/* ----------------------------------------------------------------
 * shellInOutInputUniqueCheck @ 0x30101A88  (примерный размер ~120 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 5
 * Вызывает: ioGlobalStdGet, shellContextListLock, shellContextListUnlock, shellFirst, shellNext
 * Вызывают: shellGenericInit
 * Константы: 0x30101A88
 * ---------------------------------------------------------------- */
undefined4 shellInOutInputUniqueCheck(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ioGlobalStdGet(0);
  shellContextListLock();
  iVar2 = shellFirst();
  while( true ) {
    if (iVar2 == 0) {
      shellContextListUnlock();
      return 1;
    }
    if (((*(int *)(iVar2 + 0x130) == param_1) || (*(int *)(iVar2 + 0x220) == param_1)) ||
       ((param_1 == 0 && ((*(int *)(iVar2 + 0x130) == iVar1 || (*(int *)(iVar2 + 0x220) == iVar1))))
       )) break;
    iVar2 = shellNext();
  }
  shellContextListUnlock();
  return 0;
}

/* ----------------------------------------------------------------
 * shellInOutInputHookAdd @ 0x30101B00  (примерный размер ~104 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 3
 * Вызывает: calloc, hookAddToHead, hookAddToTail
 * Вызывают: shellInOutInputHookSet
 * Константы: 0x30101B00, 0xFFFFFFFF
 * Данные: DAT_30102a6c
 * ---------------------------------------------------------------- */
undefined4
shellInOutInputHookAdd(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  int *piVar4;
  
  piVar1 = DAT_30102a6c;
  piVar4 = DAT_30102a6c;
  if (*DAT_30102a6c == 0) {
    pvVar2 = calloc(DAT_30102a6c[1],4);
    *piVar1 = (int)pvVar2;
    if (pvVar2 == (void *)0x0) {
      return 0xffffffff;
    }
  }
  if (param_2 == 0) {
    uVar3 = hookAddToTail(param_1,*piVar1,piVar1[1],param_4,piVar4);
  }
  else {
    uVar3 = hookAddToHead();
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * shellInOutInputHookSet @ 0x30101B68  (примерный размер ~164 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 4
 * Вызывает: ioctl, isatty, shellIdVerify, shellInOutInputHookAdd
 * Вызывают: shellTask
 * Константы: 0x30101B68, 0xFFFFFFFF
 * Данные: DAT_30102a6c, DAT_30102a70, DAT_30102a74, DAT_30102a78, DAT_30102b18
 * ---------------------------------------------------------------- */
undefined4 shellInOutInputHookSet(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = shellIdVerify();
  if (iVar1 == 0) {
    if (*DAT_30102a70 == 0) {
      *DAT_30102a70 = DAT_30102a74;
    }
    iVar1 = isatty(*(int *)(param_1 + 0x130));
    if (iVar1 != 0) {
      ioctl(*(int *)(param_1 + 0x130),0x16,DAT_30102a78);
      ioctl(*(int *)(param_1 + 0x130),0x17,param_1);
      iVar1 = DAT_30102a6c;
      if ((*(int *)(DAT_30102a6c + 8) == 0) &&
         (iVar2 = shellInOutInputHookAdd(DAT_30102b18,0), iVar2 == 0)) {
        *(undefined4 *)(iVar1 + 8) = 1;
      }
      return 0;
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInOutInputHookUnset @ 0x30101C0C  (примерный размер ~60 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: ioctl, isatty
 * Вызывают: FUN_3010dac8
 * Константы: 0x30101C0C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInOutInputHookUnset(int param_1)

{
  int iVar1;
  
  iVar1 = isatty(*(int *)(param_1 + 0x130));
  if (iVar1 != 0) {
    ioctl(*(int *)(param_1 + 0x130),0x16,0);
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInOutInputHookDelete @ 0x30101C48  (примерный размер ~48 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: hookDelete
 * Константы: 0x30101C48
 * Данные: DAT_30102a6c
 * ---------------------------------------------------------------- */
void shellInOutInputHookDelete(undefined4 param_1)

{
  if (*DAT_30102a6c != 0) {
    hookDelete(param_1,*DAT_30102a6c,DAT_30102a6c[1],DAT_30102a6c,DAT_30102a6c);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30101c78 @ 0x30101C78  (примерный размер ~64 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 1
 * Вызывает: ioTaskStdSet
 * Вызывают: shellInOutSet, shellInOutUse
 * Константы: 0x30101C78
 * ---------------------------------------------------------------- */
void FUN_30101c78(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ioTaskStdSet(param_1,0,param_2);
  ioTaskStdSet(param_1,1,param_3);
  ioTaskStdSet(param_1,2,param_4);
  return;
}

/* ----------------------------------------------------------------
 * shellInOutSet @ 0x30101CB8  (примерный размер ~364 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 9
 * Вызывает: FUN_30101c78, ioGlobalStdGet, ioGlobalStdSet, ledControl, logFdAdd, logFdDelete, shellCompatibleCheck, shellFromTaskGet, shellIdVerify
 * Вызывают: shellInOutRedirectRestore, shellInOutRedirectSet, shellTask
 * Константы: 0xFFFFFFFF, 0x30101CB8
 * ---------------------------------------------------------------- */
undefined4 shellInOutSet(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = shellCompatibleCheck();
  if (param_2 != -1) {
    if ((iVar1 != 0) && (param_2 != 0)) {
      ioGlobalStdSet(0,param_2);
      param_2 = 0;
    }
    *(int *)(param_1 + 0x220) = param_2;
  }
  if (param_3 == -1) goto LAB_30101db8;
  if (iVar1 == 0) {
LAB_30101d78:
    iVar3 = *(int *)(param_1 + 0x224);
    if ((iVar3 != 1) && (iVar2 = ioGlobalStdGet(1), iVar2 != iVar3)) {
      logFdDelete(iVar3);
    }
  }
  else {
    if (param_3 != 1) {
      ioGlobalStdGet(1);
      logFdDelete();
      logFdAdd(param_3);
      ioGlobalStdSet(1,param_3);
      param_3 = 1;
    }
    if (iVar1 == 0) goto LAB_30101d78;
  }
  if (param_3 != 1) {
    logFdDelete(param_3);
    logFdAdd(param_3);
  }
  *(int *)(param_1 + 0x224) = param_3;
LAB_30101db8:
  if (param_4 != -1) {
    if ((iVar1 != 0) && (param_4 != 2)) {
      ioGlobalStdSet(2,param_4);
      param_4 = 2;
    }
    *(int *)(param_1 + 0x228) = param_4;
  }
  if (*(int *)(param_1 + 0x420) != 0) {
    ledControl(*(int *)(param_1 + 0x420),param_2,param_3,0xffffffff);
  }
  FUN_30101c78(*(undefined4 *)(param_1 + 0x424),*(undefined4 *)(param_1 + 0x220),
               *(undefined4 *)(param_1 + 0x224),*(undefined4 *)(param_1 + 0x228));
  return 0;
}

/* ----------------------------------------------------------------
 * shellInOutGet @ 0x30101E24  (примерный размер ~188 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 4
 * Вызывает: ioGlobalStdGet, shellCompatibleCheck, shellFromTaskGet, shellIdVerify
 * Вызывают: shellBackgroundInit, shellInOutRedirectSet
 * Константы: 0x30101E24, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInOutGet(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = shellCompatibleCheck();
  if ((param_2 != (undefined4 *)0x0) && (*param_2 = *(undefined4 *)(param_1 + 0x220), iVar1 != 0)) {
    uVar2 = ioGlobalStdGet(0);
    *param_2 = uVar2;
  }
  if ((param_3 != (undefined4 *)0x0) && (*param_3 = *(undefined4 *)(param_1 + 0x224), iVar1 != 0)) {
    uVar2 = ioGlobalStdGet(1);
    *param_3 = uVar2;
  }
  if ((param_4 != (undefined4 *)0x0) && (*param_4 = *(undefined4 *)(param_1 + 0x228), iVar1 != 0)) {
    uVar2 = ioGlobalStdGet(2);
    *param_4 = uVar2;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellInOutInitialGet @ 0x30101EE0  (примерный размер ~108 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: shellFromTaskGet, shellIdVerify
 * Вызывают: FUN_30110e10
 * Константы: 0x30101EE0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4
shellInOutInitialGet(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 == 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x130);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(param_1 + 0x134);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(param_1 + 0x138);
    }
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInOutUse @ 0x30101F4C  (примерный размер ~68 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 3
 * Вызывает: FUN_30101c78, shellFromTaskGet, shellIdVerify
 * Вызывают: FUN_30114ebc, FUN_30115680, shellPromptPrint
 * Константы: 0x30101F4C
 * ---------------------------------------------------------------- */
void shellInOutUse(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    return;
  }
  FUN_30101c78(0,*(undefined4 *)(param_1 + 0x220),*(undefined4 *)(param_1 + 0x224),
               *(undefined4 *)(param_1 + 0x228));
  return;
}

/* ----------------------------------------------------------------
 * FUN_30101f90 @ 0x30101F90  (примерный размер ~464 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 10
 * Вызывает: __errno, close, open, ptyDevCreate, ptyDevRemove, ptyDrv, shellMemFree, shellMemMalloc, sprintf, strlen
 * Вызывают: shellInOutBgndOpen, shellInOutBlockingOpen
 * Константы: 0xFFFFFFFF, 0x30101F90
 * Данные: DAT_30102f2c, DAT_30102f30, DAT_30102f34, DAT_30103060, DAT_30103064
 * ---------------------------------------------------------------- */
int FUN_30101f90(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  char *__s;
  
  iVar7 = -DAT_30102f2c;
  if ((param_1 == 2) || (param_1 == 3)) {
    if (param_2 == (char *)0x0) {
      iVar1 = 0;
    }
    else {
      sVar2 = strlen((char *)*DAT_30102f30);
      sVar3 = strlen(param_2);
      iVar1 = sVar3 + sVar2 + 6;
    }
    iVar1 = shellMemMalloc(iVar1 + 0x28);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      *(int *)(iVar1 + 8) = param_1;
      *(undefined4 *)(iVar1 + 0xc) = 0;
      *(undefined4 *)(iVar1 + 0x10) = 0xffffffff;
      *(undefined4 *)(iVar1 + 0x14) = 0xffffffff;
      iVar4 = ptyDrv(iVar1);
      if (iVar4 == 0) {
        if (param_2 != (char *)0x0) {
          __s = (char *)(iVar1 + 0x28);
          *(char **)(iVar1 + 0xc) = __s;
          iVar4 = 0;
          do {
            *(int *)(&stack0xffffffe4 + iVar7) = iVar4;
            sprintf(__s,DAT_30102f34,*DAT_30102f30,param_2);
            iVar5 = ptyDevCreate(__s,param_3,param_4);
            if (iVar5 == 0) break;
            piVar6 = (int *)__errno();
            if (*piVar6 != 0x16) {
              shellMemFree(iVar1);
              return 0;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < 99);
          if (iVar4 == 99) {
            shellMemFree(iVar1);
            iVar1 = 0;
          }
          else {
            sprintf(&stack0xffffffe8 + iVar7,DAT_30103060,__s);
            iVar4 = open(&stack0xffffffe8 + iVar7,2,0);
            if (iVar4 < 0) {
              ptyDevRemove(__s);
              shellMemFree(iVar1);
              iVar1 = 0;
            }
            else {
              sprintf(&stack0xffffffe8 + iVar7,DAT_30103064,__s);
              iVar7 = open(&stack0xffffffe8 + iVar7,2,0);
              if (iVar7 < 0) {
                close(iVar4);
                ptyDevRemove(__s);
                shellMemFree(iVar1);
                iVar1 = 0;
              }
              else {
                *(int *)(iVar1 + 0x10) = iVar4;
                *(int *)(iVar1 + 0x14) = iVar7;
              }
            }
          }
        }
      }
      else {
        iVar1 = 0;
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellInOutBgndOpen @ 0x30102160  (примерный размер ~84 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30101f90, ioctl
 * Вызывают: shellBackgroundInit
 * Константы: 0x30102160
 * Данные: DAT_30103068
 * ---------------------------------------------------------------- */
int shellInOutBgndOpen(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_30101f90(3,DAT_30103068,param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  ioctl(*(int *)(iVar1 + 0x10),3,0x48);
  ioctl(*(int *)(iVar1 + 0x14),3,0x48);
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellInOutBgndIoClose @ 0x301021B4  (примерный размер ~76 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 3
 * Вызывает: close, ptyDevRemove, shellMemFree
 * Вызывают: shellBackgroundInit, shellInOutBgndClose
 * Константы: 0x301021B4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInOutBgndIoClose(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 8) == 3)) {
    close(*(int *)(param_1 + 0x10));
    close(*(int *)(param_1 + 0x14));
    ptyDevRemove(*(undefined4 *)(param_1 + 0xc));
    shellMemFree(param_1);
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInOutBgndGet @ 0x30102200  (примерный размер ~116 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 5
 * Вызывает: __errno, lstFirst, lstNext, shellFromTaskGet, shellIdVerify
 * Вызывают: shellBackgroundRead, shellInOutBgndClose
 * Константы: 0x30102200
 * Данные: DAT_301031cc
 * ---------------------------------------------------------------- */
int shellInOutBgndGet(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 == 0) {
    for (iVar1 = lstFirst(param_1 + 0x34); iVar1 != 0; iVar1 = lstNext(iVar1)) {
      if (*(int *)(iVar1 + 8) == 3) {
        return iVar1;
      }
    }
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_301031cc;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellInOutBgndClose @ 0x30102274  (примерный размер ~468 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 13
 * Вызывает: __errno, ioctl, kill, lstDelete, shellFromTaskGet, shellIdVerify, shellInOutBgndGet, shellInOutBgndIoClose, shellTaskGet, sysClkRateGet, taskDelay, taskDeleteForce, tyAbortGet
 * Вызывают: FUN_3010dac8, shellBackgroundInit, shellBackgroundRead
 * Константы: 0x30102274, 0xFFFFFFFF
 * Данные: DAT_30102a6c, DAT_301031cc
 * ---------------------------------------------------------------- */
undefined4 shellInOutBgndClose(int param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar3 = shellIdVerify(param_1);
  if (iVar3 == 0) {
    iVar3 = shellInOutBgndGet(param_1);
    if (iVar3 == 0) {
      uVar5 = 0;
    }
    else {
      lstDelete(param_1 + 0x34,iVar3);
      iVar7 = *(int *)(param_1 + 0x14);
      if ((iVar7 != 0) && (iVar6 = shellIdVerify(iVar7), iVar6 == 0)) {
        iVar6 = shellTaskGet(iVar7);
        piVar1 = DAT_30102a6c;
        if ((iVar6 != -1) && (uVar9 = 0, DAT_30102a6c[1] != 0)) {
          while (*(int *)(*piVar1 + uVar9 * 4) != 0) {
            uVar2 = tyAbortGet();
            iVar6 = (**(code **)(*piVar1 + uVar9 * 4))(iVar7,uVar2,0);
            if ((iVar6 != 0) || (uVar9 = uVar9 + 1, (uint)piVar1[1] <= uVar9)) break;
          }
        }
        iVar8 = 0;
        iVar6 = sysClkRateGet();
        if (0 < iVar6) {
          do {
            iVar6 = shellTaskGet(iVar7);
            if (iVar6 == -1) break;
            taskDelay(2);
            iVar8 = iVar8 + 2;
            iVar6 = sysClkRateGet();
          } while (iVar8 < iVar6);
        }
        iVar6 = shellTaskGet(iVar7);
        if (iVar6 != -1) {
          kill(iVar6,0xf);
          ioctl(*(int *)(param_1 + 0x220),0xe,0);
          ioctl(*(int *)(param_1 + 0x224),0xe,0);
          sysClkRateGet();
          taskDelay();
          iVar6 = shellTaskGet(iVar7);
          if (iVar6 != -1) {
            taskDeleteForce(iVar6);
            sysClkRateGet();
            taskDelay();
          }
        }
      }
      *(undefined4 *)(param_1 + 0x14) = 0;
      iVar7 = shellIdVerify(iVar7);
      if (iVar7 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = shellInOutBgndIoClose(iVar3);
      }
    }
  }
  else {
    puVar4 = (undefined4 *)__errno();
    *puVar4 = DAT_301031cc;
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * shellInOutBgndRegister @ 0x30102448  (примерный размер ~156 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 3
 * Вызывает: lstAdd, shellFromTaskGet, shellIdVerify
 * Вызывают: shellBackgroundInit
 * Константы: 0xFFFFFFFF, 0x30102448
 * ---------------------------------------------------------------- */
undefined4 shellInOutBgndRegister(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (((param_2 == 0) || (param_2 == -1)) || (iVar1 = shellIdVerify(param_2), iVar1 != 0)) {
    return 0xffffffff;
  }
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if ((param_3 != 0) && (*(int *)(param_3 + 8) == 3)) {
    lstAdd(param_1 + 0x34,param_3);
    *(int *)(param_1 + 0x14) = param_2;
    *(int *)(param_2 + 0x18) = param_1;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInOutSlavePtyGet @ 0x301024E4  (примерный размер ~48 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: shellBackgroundInit
 * Константы: 0x301024E4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInOutSlavePtyGet(int param_1)

{
  if ((param_1 != 0) && ((*(int *)(param_1 + 8) == 2 || (*(int *)(param_1 + 8) == 3)))) {
    return *(undefined4 *)(param_1 + 0x14);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInOutMasterPtyGet @ 0x30102514  (примерный размер ~48 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 0
 * Вызывают: shellBackgroundInit, shellBackgroundRead
 * Константы: 0x30102514, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInOutMasterPtyGet(int param_1)

{
  if ((param_1 != 0) && ((*(int *)(param_1 + 8) == 2 || (*(int *)(param_1 + 8) == 3)))) {
    return *(undefined4 *)(param_1 + 0x10);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInOutBlockingOpen @ 0x30102544  (примерный размер ~284 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 11
 * Вызывает: FUN_30101f90, __errno, close, lstAdd, ptyDevRemove, ptyDrv, semDelete, semMCreate, shellFromTaskGet, shellIdVerify, shellMemFree
 * Константы: 0x30102544
 * Данные: DAT_301031cc
 * ---------------------------------------------------------------- */
int shellInOutBlockingOpen(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = ptyDrv();
  if (iVar1 != 0) {
    return 0;
  }
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_301031cc;
    return 0;
  }
  iVar1 = FUN_30101f90(2,param_2,0x100,0x100);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  uVar3 = semMCreate();
  *(undefined4 *)(iVar1 + 0x1c) = uVar3;
  iVar4 = semMCreate(0);
  *(int *)(iVar1 + 0x20) = iVar4;
  if (*(int *)(iVar1 + 0x1c) != 0) {
    if (iVar4 != 0) {
      lstAdd(param_1 + 0x34,iVar1);
      return iVar1;
    }
    semDelete();
  }
  if (*(int *)(iVar1 + 0x20) != 0) {
    semDelete(*(int *)(iVar1 + 0x20));
  }
  if (*(int *)(iVar1 + 0xc) != 0) {
    close(*(int *)(iVar1 + 0x10));
    close(*(int *)(iVar1 + 0x14));
    ptyDevRemove(*(undefined4 *)(iVar1 + 0xc));
  }
  shellMemFree(iVar1);
  return 0;
}

/* ----------------------------------------------------------------
 * shellInOutBlockingGet @ 0x30102660  (примерный размер ~128 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 5
 * Вызывает: __errno, lstFirst, lstNext, shellFromTaskGet, shellIdVerify
 * Вызывают: shellInOutBlockingOnDataClose
 * Константы: 0x30102660
 * Данные: DAT_301031cc
 * ---------------------------------------------------------------- */
int shellInOutBlockingGet(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_301031cc;
    return 0;
  }
  for (iVar1 = lstFirst(param_1 + 0x34);
      (iVar1 != 0 && ((*(int *)(iVar1 + 8) != 2 || (*(int *)(iVar1 + 0x24) != param_2))));
      iVar1 = lstNext(iVar1)) {
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellInOutBlockingDataSet @ 0x301026E0  (примерный размер ~40 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x301026E0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInOutBlockingDataSet(int param_1,undefined4 param_2)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 8) == 2)) {
    *(undefined4 *)(param_1 + 0x24) = param_2;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInOutBlockingBlock @ 0x30102708  (примерный размер ~596 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 13
 * Вызывает: __div32, __errno, bzero, ioTaskStdGet, lstFind, read, select, semGive, semTake, shellFromTaskGet, sysClkRateGet, taskDelay, write
 * Константы: 0xFFFFFFFF, 0x30102708
 * Данные: DAT_301031cc, DAT_301037b8
 * ---------------------------------------------------------------- */
undefined4 shellInOutBlockingBlock(int param_1)

{
  __time_t *p_Var1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  size_t __n;
  undefined4 uVar7;
  bool bVar8;
  timeval local_22c;
  fd_set afStack_224 [2];
  undefined1 auStack_124 [256];
  
  uVar7 = 0xffffffff;
  iVar2 = shellFromTaskGet(0);
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = DAT_301031cc;
    return 0xffffffff;
  }
  if (((param_1 == 0) || (*(int *)(param_1 + 8) != 2)) ||
     (iVar2 = lstFind(iVar2 + 0x34,param_1), iVar2 == -1)) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 0x16;
    return 0xffffffff;
  }
  iVar2 = semTake(*(undefined4 *)(param_1 + 0x20),0xffffffff);
  bVar8 = iVar2 == 0;
  if (bVar8) {
    iVar2 = semTake(*(undefined4 *)(param_1 + 0x1c),0xffffffff);
    bVar8 = iVar2 == 0;
  }
  if (!bVar8) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x18) = 1;
  semGive(*(undefined4 *)(param_1 + 0x1c));
  p_Var1 = DAT_301037b8;
  if (*(int *)(param_1 + 0x10) == -1) {
    iVar2 = semTake(*(undefined4 *)(param_1 + 0x1c),0xffffffff);
    while (uVar7 = 0xffffffff, iVar2 == 0) {
      if (*(int *)(param_1 + 0x18) == 0) goto LAB_30102938;
      semGive(*(undefined4 *)(param_1 + 0x1c));
      uVar7 = sysClkRateGet();
      __div32(uVar7,2);
      taskDelay();
      iVar2 = semTake(*(undefined4 *)(param_1 + 0x1c),0xffffffff);
    }
  }
  else {
    while( true ) {
      local_22c.tv_sec = *p_Var1;
      local_22c.tv_usec = p_Var1[1];
      bzero(afStack_224,0x100);
      uVar4 = ioTaskStdGet(0,0);
      uVar5 = ioTaskStdGet(0,0);
      afStack_224[0].fds_bits[uVar4 >> 5] =
           afStack_224[0].fds_bits[uVar4 >> 5] | 1 << (uVar5 & 0x1f);
      iVar2 = ioTaskStdGet(0,0);
      iVar2 = select(iVar2 + 1,afStack_224,(fd_set *)0x0,(fd_set *)0x0,&local_22c);
      if ((iVar2 == -1) || (iVar6 = semTake(*(undefined4 *)(param_1 + 0x1c),0xffffffff), iVar6 != 0)
         ) break;
      if (iVar2 != 0) {
        while (__n = read(0,auStack_124,0x100), __n != 0) {
          if (__n != 0xffffffff) {
            write(*(int *)(param_1 + 0x10),auStack_124,__n);
          }
          if (((__n == 0) || (__n == 0xffffffff)) || (__n != 0x100)) break;
        }
      }
      if (*(int *)(param_1 + 0x18) == 0) goto LAB_30102938;
      semGive(*(undefined4 *)(param_1 + 0x1c));
    }
  }
LAB_30102944:
  semGive(*(undefined4 *)(param_1 + 0x20));
  return uVar7;
LAB_30102938:
  semGive(*(undefined4 *)(param_1 + 0x1c));
  uVar7 = 0;
  goto LAB_30102944;
}

/* ----------------------------------------------------------------
 * FUN_3010295c @ 0x3010295C  (примерный размер ~112 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 3
 * Вызывает: __errno, lstFirst, lstNext
 * Вызывают: shellInOutBlockingBlockedDataGet, shellInOutBlockingUnblock
 * Константы: 0x3010295C, 0xFFFFFFFF
 * Данные: DAT_301031cc
 * ---------------------------------------------------------------- */
undefined4 FUN_3010295c(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_1 != -1)) {
    for (iVar2 = lstFirst(param_1 + 0x34);
        (iVar2 != 0 && ((*(int *)(iVar2 + 8) != 2 || (*(int *)(iVar2 + 0x18) == 0))));
        iVar2 = lstNext(iVar2)) {
    }
    *param_2 = iVar2;
    return 0;
  }
  puVar1 = (undefined4 *)__errno();
  *puVar1 = DAT_301031cc;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInOutBlockingUnblock @ 0x301029CC  (примерный размер ~108 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_3010295c, semGive, semTake
 * Вызывают: shellInOutBlockingClose
 * Константы: 0xFFFFFFFF, 0x301029CC
 * ---------------------------------------------------------------- */
undefined4 shellInOutBlockingUnblock(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  
  iVar1 = FUN_3010295c(param_1,&local_10);
  if (iVar1 == 0) {
    if (local_10 != 0) {
      iVar1 = semTake(*(undefined4 *)(local_10 + 0x1c),0xffffffff);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      *(undefined4 *)(local_10 + 0x18) = 0;
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(local_10 + 0x24);
      }
      semGive(*(undefined4 *)(local_10 + 0x1c));
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellInOutBlockingBlockedDataGet @ 0x30102A38  (примерный размер ~88 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_3010295c
 * Константы: 0xFFFFFFFF, 0x30102A38
 * ---------------------------------------------------------------- */
undefined4 shellInOutBlockingBlockedDataGet(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  iVar1 = FUN_3010295c(param_1,&local_c);
  if (iVar1 == 0) {
    if (local_c == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
      *param_2 = *(undefined4 *)(local_c + 0x24);
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellInOutBlockingClose @ 0x30102A90  (примерный размер ~316 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 12
 * Вызывает: __errno, close, lstDelete, lstFirst, lstNext, ptyDevRemove, semDelete, semTake, shellFromTaskGet, shellIdVerify, shellInOutBlockingUnblock, shellMemFree
 * Вызывают: FUN_3010dac8, shellInOutBlockingOnDataClose
 * Константы: 0xFFFFFFFF, 0x30102A90
 * Данные: DAT_301031cc
 * ---------------------------------------------------------------- */
undefined4 shellInOutBlockingClose(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_301031cc;
    return 0xffffffff;
  }
  if (param_2 == -1) {
    iVar1 = lstFirst(param_1 + 0x34);
    while (iVar1 != 0) {
      iVar3 = lstNext(iVar1);
      shellInOutBlockingClose(param_1,iVar1);
      iVar1 = iVar3;
    }
  }
  else {
    if ((param_2 == 0) || (*(int *)(param_2 + 8) != 2)) {
      return 0xffffffff;
    }
    if ((*(int *)(param_2 + 0x18) != 0) &&
       (iVar1 = shellInOutBlockingUnblock(param_1,0), iVar1 != 0)) {
      return 0xffffffff;
    }
    iVar1 = semTake(*(undefined4 *)(param_2 + 0x20),0xffffffff);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    lstDelete(param_1 + 0x34,param_2);
    if (*(int *)(param_2 + 0xc) != 0) {
      close(*(int *)(param_2 + 0x10));
      close(*(int *)(param_2 + 0x14));
      ptyDevRemove(*(undefined4 *)(param_2 + 0xc));
    }
    semDelete(*(undefined4 *)(param_2 + 0x20));
    semDelete(*(undefined4 *)(param_2 + 0x1c));
    shellMemFree(param_2);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellInOutBlockingOnDataClose @ 0x30102BCC  (примерный размер ~80 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 4
 * Вызывает: shellFirst, shellInOutBlockingClose, shellInOutBlockingGet, shellNext
 * Константы: 0x30102BCC
 * ---------------------------------------------------------------- */
undefined4 shellInOutBlockingOnDataClose(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = shellFirst();
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = shellInOutBlockingGet(iVar1,param_1);
    if (iVar2 != 0) break;
    iVar1 = shellNext(iVar1,0);
  }
  uVar3 = shellInOutBlockingClose();
  return uVar3;
}

/* ----------------------------------------------------------------
 * shellOutputLock @ 0x30102C1C  (примерный размер ~104 байт)
 * Модуль: shell | Вызывают: 8 | Вызывает: 4
 * Вызывает: semTake, shellFromTaskParentContextGet, shellIdVerify, taskIdSelf
 * Вызывают: FUN_301090ac, FUN_3011468c, FUN_30115590, FUN_30115680, bh, shellPrint, shellPrintErr, sp
 * Константы: 0xFFFFFFFF, 0x30102C1C
 * ---------------------------------------------------------------- */
undefined4 shellOutputLock(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    taskIdSelf();
    param_1 = shellFromTaskParentContextGet();
    if (param_1 == 0) {
      return 0xffffffff;
    }
  }
  else {
    iVar1 = shellIdVerify(param_1);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
  }
  iVar1 = semTake(*(undefined4 *)(param_1 + 0x410),0xffffffff);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellOutputUnlock @ 0x30102C84  (примерный размер ~100 байт)
 * Модуль: shell | Вызывают: 8 | Вызывает: 4
 * Вызывает: semGive, shellFromTaskParentContextGet, shellIdVerify, taskIdSelf
 * Вызывают: FUN_301090ac, FUN_3011468c, FUN_30115590, FUN_30115680, bh, shellPrint, shellPrintErr, sp
 * Константы: 0xFFFFFFFF, 0x30102C84
 * ---------------------------------------------------------------- */
undefined4 shellOutputUnlock(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    taskIdSelf();
    param_1 = shellFromTaskParentContextGet();
    if (param_1 == 0) {
      return 0xffffffff;
    }
  }
  else {
    iVar1 = shellIdVerify(param_1);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
  }
  iVar1 = semGive(*(undefined4 *)(param_1 + 0x410));
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellInOutRedirectOpen @ 0x30102CE8  (примерный размер ~716 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 11
 * Вызывает: __errno, close, lseek, lstAdd, open, remove, shellFromTaskGet, shellIdVerify, shellMemMalloc, stat, strcmp
 * Вызывают: FUN_3010c16c
 * Константы: 0xFFFFFFFF, 0x30102CE8
 * Данные: DAT_301031cc, DAT_301037d0, DAT_301037d4
 * ---------------------------------------------------------------- */
int shellInOutRedirectOpen
              (int param_1,char *param_2,char *param_3,char *param_4,char *param_5,int param_6)

{
  int iVar1;
  undefined4 *puVar2;
  __off_t _Var3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  int local_4;
  
  iVar4 = -1;
  bVar7 = false;
  bVar9 = false;
  iVar6 = -1;
  iVar5 = -1;
  if (((param_2 == (char *)0x0) && (param_3 == (char *)0x0)) && (param_5 == (char *)0x0)) {
    return DAT_301037d0;
  }
  local_4 = param_1;
  if (param_1 == 0) {
    local_4 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(local_4);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_301031cc;
    return 0;
  }
  if (param_2 != (char *)0x0) {
    if (((param_3 != (char *)0x0) && (iVar1 = strcmp(param_2,param_3), iVar1 == 0)) ||
       ((param_5 != (char *)0x0 && (iVar1 = strcmp(param_2,param_5), iVar1 == 0)))) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 0x16;
      return 0;
    }
    if ((param_2 != (char *)0x0) && (iVar4 = open(param_2,0,0), iVar4 < 0)) {
      return 0;
    }
  }
  if (param_3 != (char *)0x0) {
    iVar6 = stat(param_3,(stat *)&stack0xffffff90);
    bVar7 = iVar6 == 0;
    bVar8 = param_4 == (char *)0x0;
    if ((!bVar8) && (bVar8 = !bVar7, !bVar8)) {
      param_2 = (char *)0x1;
    }
    if (bVar8) {
      param_2 = DAT_301037d4;
    }
    iVar6 = open(param_3,(int)param_2,0x1a4);
    if ((iVar6 < 0) || ((param_4 != (char *)0x0 && (_Var3 = lseek(iVar6,0,2), _Var3 == -1))))
    goto LAB_30102f38;
  }
  if (param_5 != (char *)0x0) {
    iVar5 = stat(param_5,(stat *)&stack0xffffff90);
    bVar9 = iVar5 == 0;
    bVar8 = param_6 == 0;
    if ((!bVar8) && (bVar8 = !bVar9, !bVar8)) {
      param_4 = (char *)0x1;
    }
    if (bVar8) {
      param_4 = DAT_301037d4;
    }
    iVar5 = open(param_5,(int)param_4,0x1a4);
    if ((iVar5 < 0) || ((param_6 != 0 && (_Var3 = lseek(iVar5,0,2), _Var3 == -1))))
    goto LAB_30102f38;
  }
  iVar1 = shellMemMalloc(0x28);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 8) = 1;
    *(int *)(iVar1 + 0x1c) = iVar4;
    *(int *)(iVar1 + 0x20) = iVar6;
    *(int *)(iVar1 + 0x24) = iVar5;
    *(undefined4 *)(iVar1 + 0x10) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x14) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x18) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    lstAdd(local_4 + 0x34,iVar1);
    return iVar1;
  }
LAB_30102f38:
  if (iVar4 != -1) {
    close(iVar4);
  }
  if (((iVar6 != -1) && (iVar4 = close(iVar6), iVar4 == 0)) && (!bVar7)) {
    remove(param_3);
  }
  if (((iVar5 != -1) && (iVar4 = close(iVar5), iVar4 == 0)) && (!bVar9)) {
    remove(param_5);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellInOutRedirectSet @ 0x30102FB4  (примерный размер ~300 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 6
 * Вызывает: __errno, lstFind, shellFromTaskGet, shellIdVerify, shellInOutGet, shellInOutSet
 * Вызывают: FUN_30108cb4, shellInOutRedirectScript
 * Константы: 0xFFFFFFFF, 0x30102FB4
 * Данные: DAT_301031cc, DAT_301037d0
 * ---------------------------------------------------------------- */
undefined4 shellInOutRedirectSet(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_301031cc;
    return 0xffffffff;
  }
  if (DAT_301037d0 != param_2) {
    if ((param_2 == 0) || (iVar1 = lstFind(param_1 + 0x34,param_2), iVar1 == -1)) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 0x16;
      return 0xffffffff;
    }
    if (*(int *)(param_2 + 8) != 1) {
      return 0xffffffff;
    }
    if (*(int *)(param_2 + 0xc) == 0) {
      iVar1 = shellInOutGet(param_1,param_2 + 0x10,param_2 + 0x14,param_2 + 0x18);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      if (*(int *)(param_2 + 0x1c) == -1) {
        *(undefined4 *)(param_2 + 0x10) = 0xffffffff;
      }
      if (*(int *)(param_2 + 0x20) == -1) {
        *(undefined4 *)(param_2 + 0x14) = 0xffffffff;
      }
      if (*(int *)(param_2 + 0x24) == -1) {
        *(undefined4 *)(param_2 + 0x18) = 0xffffffff;
      }
      iVar1 = shellInOutSet(param_1);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellInOutRedirectRestore @ 0x301030E0  (примерный размер ~212 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 5
 * Вызывает: __errno, lstFind, shellFromTaskGet, shellIdVerify, shellInOutSet
 * Вызывают: FUN_30108cb4, shellInOutRedirectClose, shellInOutRedirectScript
 * Константы: 0xFFFFFFFF, 0x301030E0
 * Данные: DAT_301031cc, DAT_301037d0
 * ---------------------------------------------------------------- */
undefined4 shellInOutRedirectRestore(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_301031cc;
    return 0xffffffff;
  }
  if (DAT_301037d0 != param_2) {
    if ((param_2 == 0) || (iVar1 = lstFind(param_1 + 0x34,param_2), iVar1 == -1)) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 0x16;
      return 0xffffffff;
    }
    if (*(int *)(param_2 + 8) != 1) {
      return 0xffffffff;
    }
    if (*(int *)(param_2 + 0xc) != 0) {
      shellInOutSet(param_1,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                    *(undefined4 *)(param_2 + 0x18));
      *(undefined4 *)(param_2 + 0x10) = 0xffffffff;
      *(undefined4 *)(param_2 + 0x14) = 0xffffffff;
      *(undefined4 *)(param_2 + 0x18) = 0xffffffff;
      *(undefined4 *)(param_2 + 0xc) = 0;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * shellInOutRedirectScript @ 0x301031B4  (примерный размер ~144 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 5
 * Вызывает: shellExec, shellFromTaskGet, shellIdVerify, shellInOutRedirectRestore, shellInOutRedirectSet
 * Вызывают: FUN_3010c16c
 * Константы: 0xFFFFFFFF, 0x301031B4
 * ---------------------------------------------------------------- */
undefined4 shellInOutRedirectScript(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = shellInOutRedirectSet(param_1,param_2);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  uVar3 = *(undefined4 *)(param_1 + 0x13c);
  *(undefined4 *)(param_1 + 0x13c) = 0;
  uVar2 = shellExec(param_1);
  *(undefined4 *)(param_1 + 0x13c) = uVar3;
  shellInOutRedirectRestore(param_1,param_2);
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellInOutRedirectClose @ 0x30103244  (примерный размер ~308 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 9
 * Вызывает: __errno, close, lstDelete, lstFirst, lstNext, shellFromTaskGet, shellIdVerify, shellInOutRedirectRestore, shellMemFree
 * Вызывают: FUN_3010c16c, FUN_3010dac8
 * Константы: 0xFFFFFFFF, 0x30103244
 * Данные: DAT_301037d0, DAT_301037d8
 * ---------------------------------------------------------------- */
undefined4 shellInOutRedirectClose(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_301037d8;
    return 0xffffffff;
  }
  if (param_2 == -1) {
    iVar1 = lstFirst(param_1 + 0x34);
    while (iVar1 != 0) {
      iVar3 = lstNext(iVar1);
      shellInOutRedirectClose(param_1,iVar1);
      iVar1 = iVar3;
    }
  }
  else {
    iVar1 = shellInOutRedirectRestore(param_1,param_2);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    if (DAT_301037d0 != param_2) {
      if (param_1 == 0) {
        shellFromTaskGet(0);
      }
      if ((param_2 == 0) || (*(int *)(param_2 + 8) != 1)) {
        return 0xffffffff;
      }
      lstDelete(param_1 + 0x34,param_2);
      if (*(int *)(param_2 + 0x1c) != -1) {
        close(*(int *)(param_2 + 0x1c));
      }
      if (*(int *)(param_2 + 0x20) != -1) {
        close(*(int *)(param_2 + 0x20));
      }
      if (*(int *)(param_2 + 0x24) != -1) {
        close(*(int *)(param_2 + 0x24));
      }
      shellMemFree(param_2);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30103378 @ 0x30103378  (примерный размер ~128 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 3
 * Вызывает: shellFromTaskGet, shellIdVerify, vfdprintf
 * Вызывают: shellPrint, shellPrintErr
 * Константы: 0xFFFFFFFF, 0x30103378
 * ---------------------------------------------------------------- */
undefined4 FUN_30103378(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 != 1) && (param_2 != 2)) {
    return 0xffffffff;
  }
  if (param_1 == 0) {
    param_1 = shellFromTaskGet(0);
  }
  iVar1 = shellIdVerify(param_1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (param_2 == 1) {
    uVar2 = *(undefined4 *)(param_1 + 0x224);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x228);
  }
  uVar2 = vfdprintf(uVar2,param_3,param_4);
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellPrintErr @ 0x301033F8  (примерный размер ~192 байт)
 * Модуль: shell | Вызывают: 35 | Вызывает: 7
 * Вызывает: FUN_30103378, __errno, shellFirst, shellIdVerify, shellNext, shellOutputLock, shellOutputUnlock
 * Вызывают: FUN_30104058, FUN_30105988, FUN_3010891c, FUN_30108e10, FUN_3010bf74, FUN_3010c16c, FUN_3010ed74, FUN_3010fc88, FUN_3010fed0, FUN_3010ff7c
 *           ...
 * Константы: 0xFFFFFFFF, 0x301033F8
 * Данные: DAT_301037d8
 * ---------------------------------------------------------------- */
undefined4 shellPrintErr(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar3 = 0xffffffff;
  uStack_8 = param_3;
  uStack_4 = param_4;
  if (param_1 == -1) {
    for (iVar1 = shellFirst(); iVar1 != 0; iVar1 = shellNext(iVar1)) {
      shellOutputLock(iVar1);
      uVar3 = FUN_30103378(iVar1,2,param_2,&uStack_8);
      shellOutputUnlock(iVar1);
    }
  }
  else {
    iVar1 = shellIdVerify();
    if (iVar1 == 0) {
      shellOutputLock(param_1);
      uVar3 = FUN_30103378(param_1,2,param_2,&uStack_8);
      shellOutputUnlock(param_1);
    }
    else {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_301037d8;
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * shellPrint @ 0x301034B8  (примерный размер ~452 байт)
 * Модуль: shell | Вызывают: 25 | Вызывает: 7
 * Вызывает: FUN_30103378, __errno, shellFirst, shellIdVerify, shellNext, shellOutputLock, shellOutputUnlock
 * Вызывают: FUN_300fdd1c, FUN_301040fc, FUN_301044b0, FUN_30106424, FUN_3010891c, FUN_301090ac, FUN_3010c4f0, FUN_3010cb7c, FUN_3010cbcc, FUN_3010cc3c
 *           ...
 * Константы: 0xFFFFFFFF, 0x301034B8
 * Данные: DAT_301037d8
 * ---------------------------------------------------------------- */
undefined4 shellPrint(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar3 = 0xffffffff;
  uStack_8 = param_3;
  uStack_4 = param_4;
  if (param_1 == -1) {
    for (iVar1 = shellFirst(); iVar1 != 0; iVar1 = shellNext(iVar1)) {
      shellOutputLock(iVar1);
      uVar3 = FUN_30103378(iVar1,1,param_2,&uStack_8);
      shellOutputUnlock(iVar1);
    }
  }
  else {
    iVar1 = shellIdVerify();
    if (iVar1 == 0) {
      shellOutputLock(param_1);
      uVar3 = FUN_30103378(param_1,1,param_2,&uStack_8);
      shellOutputUnlock(param_1);
    }
    else {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_301037d8;
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_3010367c @ 0x3010367C  (примерный размер ~188 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: shellIdVerify
 * Константы: 0x3010367C
 * Данные: DAT_301037e8
 * ---------------------------------------------------------------- */
bool FUN_3010367c(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  
  iVar2 = shellIdVerify();
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x14) != 0) {
      FUN_3010367c(*(int *)(param_1 + 0x14),param_2);
    }
    piVar1 = DAT_301037e8;
    uVar4 = 0;
    if (DAT_301037e8[1] != 0) {
      while (pcVar3 = *(code **)(*piVar1 + uVar4 * 4), pcVar3 != (code *)0x0) {
        iVar2 = (*pcVar3)(param_1,param_2,1);
        if (iVar2 != 0) {
          return iVar2 != 0;
        }
        uVar4 = uVar4 + 1;
        if ((uint)piVar1[1] <= uVar4) {
          return false;
        }
      }
    }
  }
  return false;
}

/* ----------------------------------------------------------------
 * FUN_30103738 @ 0x30103738  (примерный размер ~184 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 5
 * Вызывает: jobExcAdd, shellAbort, shellAbortHandledByShell, shellIdVerify, tyAbortGet
 * Константы: 0x30103738
 * Данные: DAT_301037ec
 * ---------------------------------------------------------------- */
undefined4 FUN_30103738(undefined4 param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = tyAbortGet();
  if ((uVar1 & 0xff) == param_2) {
    iVar3 = shellAbortHandledByShell(uVar1 & 0xff);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      iVar3 = shellIdVerify(param_1);
      if (iVar3 == -1) {
        uVar2 = 0;
      }
      else {
        if (param_3 == 0) {
          shellAbort(param_1);
        }
        else {
          jobExcAdd(DAT_301037ec,param_1,0,0,0,0,0);
        }
        uVar2 = 1;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellInternalStrToInt @ 0x301037F0  (примерный размер ~1332 байт)
 * Модуль: shell | Вызывают: 4 | Вызывает: 7
 * Вызывает: sprintf, sscanf, strchr, strcmp, strcpy, strlen, strpbrk
 * Вызывают: FUN_3010fc88, FUN_3010ff7c, shellInternalStrToInt32, shellWorkingMemCtxIdConvert
 * Константы: 0x301037F0
 * Данные: DAT_301047cc, DAT_301047d0, DAT_30104914, DAT_30104918, DAT_3010491c, DAT_30104920, DAT_30104924, DAT_30104928
 * ---------------------------------------------------------------- */
int shellInternalStrToInt(char *param_1,int *param_2,undefined4 *param_3,uint *param_4,int param_5)

{
  size_t sVar1;
  char *pcVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  int local_14c;
  int local_144;
  char acStack_134 [7];
  byte abStack_12d [128];
  undefined1 local_ad;
  char local_ac [127];
  undefined1 local_2d;
  
  iVar4 = 0;
  iVar7 = 0;
  sVar1 = strlen(param_1);
  iVar6 = 10;
  if (((sVar1 == 0) || (0x7f < (int)sVar1)) ||
     (pcVar2 = strchr(param_1,0x2e), pcVar2 != (char *)0x0)) {
    return -1;
  }
  strcpy((char *)(abStack_12d + 1),param_1);
  local_ad = 0;
  uVar5 = 0;
  sVar1 = strlen((char *)(abStack_12d + 1));
  if (sVar1 != 0) {
    iVar9 = *DAT_301047cc;
    pbVar3 = abStack_12d;
    do {
      pbVar3 = pbVar3 + 1;
      uVar5 = uVar5 + 1;
      *pbVar3 = *(byte *)(iVar9 + (uint)*pbVar3);
      sVar1 = strlen((char *)(abStack_12d + 1));
    } while (uVar5 < sVar1);
  }
  uVar5 = (uint)(abStack_12d[1] == '-');
  if (((abStack_12d[uVar5 + 1] != 0x30) && (abStack_12d[uVar5 + 2] != 0x78)) &&
     (pcVar2 = strpbrk((char *)(abStack_12d + 1),DAT_301047d0), pcVar2 != (char *)0x0)) {
    return -1;
  }
  do {
    sVar1 = strlen((char *)(abStack_12d + 1));
    if (abStack_12d[sVar1] == 0x75) {
      iVar7 = iVar7 + 1;
    }
    else {
      if (abStack_12d[sVar1] != 0x6c) break;
      iVar4 = iVar4 + 1;
    }
    abStack_12d[sVar1] = 0;
  } while( true );
  if (abStack_12d[uVar5 + 1] == 0x30) {
    if ((abStack_12d[uVar5 + 2] == 0x78) && (abStack_12d[uVar5 + 3] == 0)) {
      return -1;
    }
  }
  else if (abStack_12d[uVar5 + 1] == 0) {
    return -1;
  }
  *param_4 = (uint)(0 < iVar7);
  if (abStack_12d[uVar5 + 1] == 0x30) {
    if (abStack_12d[uVar5 + 2] == 0x78) {
      iVar6 = 0x10;
      uVar5 = uVar5 + 2;
    }
    else if ((*(byte *)(*DAT_30104914 + (uint)abStack_12d[uVar5 + 2]) & 4) != 0) {
      iVar6 = 8;
      uVar5 = uVar5 + 1;
    }
  }
  if (abStack_12d[uVar5 + 1] == 0x30) {
    pbVar3 = abStack_12d + uVar5 + 1;
    do {
      pbVar3 = pbVar3 + 1;
      uVar5 = uVar5 + 1;
    } while (*pbVar3 == 0x30);
  }
  if ((iVar4 < 2) &&
     (((iVar6 == 0x10 && (sVar1 = strlen((char *)(abStack_12d + uVar5 + 1)), 8 < sVar1)) ||
      (((iVar6 == 10 && (sVar1 = strlen((char *)(abStack_12d + uVar5 + 1)), 10 < sVar1)) ||
       ((iVar6 == 8 && (sVar1 = strlen((char *)(abStack_12d + uVar5 + 1)), 0xb < sVar1)))))))) {
    if (param_5 == 0) {
      return -1;
    }
    iVar4 = 2;
  }
  else if (iVar4 == 1) {
    uVar8 = 5;
    uVar10 = DAT_30104918;
    goto LAB_30103a9c;
  }
  uVar8 = 8;
  uVar10 = DAT_3010491c;
LAB_30103a9c:
  *param_3 = uVar8;
  sprintf(acStack_134,DAT_30104920,uVar10);
  local_ac[0] = '\0';
  iVar7 = sscanf((char *)(abStack_12d + 1),acStack_134,param_2,local_ac);
  local_2d = 0;
  sVar1 = strlen(local_ac);
  if (sVar1 == 0) {
    if ((iVar7 == 1) && (iVar4 == 0)) {
      if ((*param_4 == 0) && (iVar6 == 10)) {
        sprintf((char *)(abStack_12d + 1),DAT_3010492c);
        sprintf(local_ac,DAT_30104930,*param_2);
      }
      else {
        iVar4 = param_2[1];
        local_14c = *param_2;
        if (((iVar4 != 0) && (iVar4 < 0)) && (iVar4 < 0)) {
          local_14c = -local_14c;
        }
        sprintf((char *)(abStack_12d + 1),DAT_30104924);
        sprintf(local_ac,DAT_30104928,local_14c);
      }
      iVar4 = strcmp((char *)(abStack_12d + 1),local_ac);
      if (iVar4 == 0) {
        iVar4 = *param_2;
        *param_3 = 4;
        *param_2 = iVar4;
      }
      else if (param_5 == 0) {
        iVar7 = -1;
      }
      else {
        if ((*param_4 == 0) && (iVar6 == 10)) {
          sprintf(local_ac,DAT_30104938,*param_2);
        }
        else {
          iVar4 = param_2[1];
          local_144 = *param_2;
          if ((iVar4 != 0) && ((iVar4 < 0 && (iVar4 < 0)))) {
            local_144 = -local_144;
          }
          sprintf(local_ac,DAT_30104934,local_144);
        }
        iVar4 = strcmp((char *)(abStack_12d + 1),local_ac);
        if (iVar4 == 0) {
          iVar4 = *param_2;
          *param_3 = 5;
          *param_2 = iVar4;
        }
      }
    }
  }
  else {
    iVar7 = -1;
  }
  return iVar7;
}

/* ----------------------------------------------------------------
 * shellInternalStrToInt32 @ 0x30103D24  (примерный размер ~128 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: shellInternalStrToInt, shellPrintErr
 * Вызывают: shellLineLenGet
 * Константы: 0x30103D24, 0xFFFFFFFF
 * Данные: DAT_3010493c
 * ---------------------------------------------------------------- */
undefined4 shellInternalStrToInt32(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_24;
  undefined1 auStack_20 [8];
  undefined4 local_18 [2];
  
  iVar1 = shellInternalStrToInt(param_1,local_18,&local_24,auStack_20,0);
  if ((iVar1 == 1) && ((local_24 == 4 || (local_24 == 5)))) {
    uVar2 = 0;
    *param_2 = local_18[0];
  }
  else {
    if (param_3 != 0) {
      shellPrintErr(0,DAT_3010493c,param_3,param_1);
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30103da4 @ 0x30103DA4  (примерный размер ~36 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 1
 * Вызывает: shellMemFree
 * Вызывают: shellInternalOptGet
 * Константы: 0x30103DA4
 * ---------------------------------------------------------------- */
void FUN_30103da4(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    shellMemFree();
  }
  shellMemFree(param_1);
  return;
}

/* ----------------------------------------------------------------
 * shellInternalSymTblFromRtpGet @ 0x30103DC8  (примерный размер ~316 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 3
 * Вызывает: abs, free, symByValueAndTypeFind
 * Вызывают: FUN_30111224, dbgBpListPrint, shellInternalSymTblFromTaskGet
 * Константы: 0x30103DC8, 0xFFFFFFFF
 * Данные: DAT_30104940, DAT_30104944, DAT_30104948
 * ---------------------------------------------------------------- */
int shellInternalSymTblFromRtpGet(code *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  undefined1 auStack_24 [4];
  void *local_20;
  void *local_1c;
  int local_18;
  int local_14;
  
  local_20 = (void *)0x0;
  local_1c = (void *)0x0;
  local_18 = 0;
  local_14 = 0;
  uVar5 = 0xffffffff;
  if ((code *)*DAT_30104940 == param_1) {
LAB_30103ec4:
    iVar2 = *DAT_30104948;
  }
  else {
    bVar6 = param_1 == (code *)0x0;
    pcVar1 = param_1;
    if (!bVar6) {
      pcVar1 = (code *)*DAT_30104944;
      bVar6 = pcVar1 == (code *)0x0;
    }
    if (bVar6) {
      return 0;
    }
    iVar2 = (*pcVar1)(param_1);
    if (*DAT_30104948 == 0) {
      return iVar2;
    }
    if (param_2 == 0) {
      return iVar2;
    }
    iVar3 = symByValueAndTypeFind(*DAT_30104948,param_2,&local_1c,&local_14,auStack_24,0,0);
    if (iVar3 == 0) {
      uVar5 = abs(local_14 - param_2);
    }
    free(local_1c);
    if (iVar2 != 0) {
      iVar3 = symByValueAndTypeFind(iVar2,param_2,&local_20,&local_18,auStack_24,0,0);
      if (iVar3 != 0) goto LAB_30103ec4;
      if ((iVar2 != 0) && (uVar4 = abs(local_18 - param_2), uVar5 < uVar4)) {
        iVar2 = *DAT_30104948;
      }
    }
    free(local_20);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * shellInternalSymTblFromTaskGet @ 0x30103F04  (примерный размер ~28 байт)
 * Модуль: shell | Вызывают: 6 | Вызывает: 2
 * Вызывает: shellInternalSymTblFromRtpGet, taskTcb
 * Вызывают: FUN_300f5e28, FUN_30115590, FUN_30115680, FUN_3011b4e0, dbgCallPrint, exchTrcPrint
 * Константы: 0x30103F04
 * ---------------------------------------------------------------- */
void shellInternalSymTblFromTaskGet(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = taskTcb();
  shellInternalSymTblFromRtpGet(*(undefined4 *)(iVar1 + 0x94),param_2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30103f20 @ 0x30103F20  (примерный размер ~24 байт)
 * Модуль: shell | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_30103f38, FUN_30104058, FUN_301040fc, FUN_301043e4, FUN_301044b0
 * Константы: 0x30103F20
 * ---------------------------------------------------------------- */
char FUN_30103f20(uint param_1)

{
  return ((param_1 & 0x2e) != 4) + '\x02';
}

/* ----------------------------------------------------------------
 * FUN_30103f38 @ 0x30103F38  (примерный размер ~196 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_30103f20, __errno, shellMemFree, shellMemMalloc, sprintf, strlen, symFindByName
 * Вызывают: shellInternalSymbolGet
 * Константы: 0x30103F38
 * Данные: DAT_3010494c, DAT_30104950
 * ---------------------------------------------------------------- */
int FUN_30103f38(int param_1,char *param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  size_t sVar3;
  char *__s;
  undefined4 uVar4;
  undefined1 local_20 [4];
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_3010494c;
    iVar2 = -1;
  }
  else {
    sVar3 = strlen(param_2);
    __s = (char *)shellMemMalloc(sVar3 + 2);
    if (__s == (char *)0x0) {
      iVar2 = -1;
    }
    else {
      sprintf(__s,DAT_30104950,param_2);
      iVar2 = symFindByName(param_1,param_2,param_3,local_20);
      if (iVar2 != 0) {
        iVar2 = symFindByName(param_1,__s,param_3,local_20);
      }
      shellMemFree(__s);
      if (iVar2 == 0) {
        uVar4 = FUN_30103f20(local_20[0]);
        *param_4 = uVar4;
      }
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_30103ffc @ 0x30103FFC  (примерный размер ~92 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 1
 * Вызывает: symEach
 * Вызывают: FUN_30104058
 * Константы: 0x30103FFC
 * Данные: DAT_30104948, DAT_30104954
 * ---------------------------------------------------------------- */
undefined4 FUN_30103ffc(undefined4 param_1,undefined4 *param_2,undefined1 *param_3)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10;
  
  if (*DAT_30104948 == 0) {
    local_14 = 0;
  }
  else {
    local_14 = 0;
    local_18 = param_1;
    symEach(*DAT_30104948,DAT_30104954,&local_1c);
    *param_3 = local_10;
    *param_2 = local_1c;
  }
  return local_14;
}

/* ----------------------------------------------------------------
 * FUN_30104058 @ 0x30104058  (примерный размер ~164 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_30103f20, FUN_30103ffc, __errno, shellPrintErr, symEach
 * Вызывают: shellInternalSymbolGet
 * Константы: 0x30104058, 0xFFFFFFFF
 * Данные: DAT_3010494c, DAT_30104958, DAT_3010495c, DAT_30104960
 * ---------------------------------------------------------------- */
undefined4 FUN_30104058(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_18 [4];
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_3010494c;
  }
  else if ((*DAT_30104958 != 0) && (iVar2 = FUN_30103ffc(param_2,param_3,local_18), iVar2 != 0)) {
    if (iVar2 == 1) {
      uVar3 = FUN_30103f20(local_18[0]);
      *param_4 = uVar3;
      return 0;
    }
    shellPrintErr(0,DAT_3010495c,param_2);
    symEach(param_1,DAT_30104960,param_2);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_301040fc @ 0x301040FC  (примерный размер ~744 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 18
 * Вызывает: FUN_30103f20, __errno, cplusMangledSymCheck, cplusMatchMangledListGet, cplusUserAsk, free, lstCount, lstDelete, lstFirst, lstFree, lstInit, lstNext, lstNth, shellPrint
 *           ...
 * Вызывают: FUN_301043e4
 * Константы: 0x301040FC
 * Данные: DAT_30104964, DAT_30104968
 * ---------------------------------------------------------------- */
int FUN_301040fc(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 *param_4,int param_5
                )

{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  void *__ptr;
  int iVar4;
  void *pvVar5;
  size_t sVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  char *__s;
  char *pcVar9;
  undefined1 local_44 [4];
  undefined1 auStack_40 [12];
  undefined1 auStack_34 [12];
  
  lstInit(auStack_34);
  if (param_5 != 0) {
    cplusMatchMangledListGet(param_1,param_2,auStack_34);
  }
  lstInit(auStack_40);
  symListGet(param_1,param_2,1,auStack_40);
  pvVar2 = (void *)lstFirst(auStack_40);
joined_r0x30104168:
  pvVar5 = pvVar2;
  if (pvVar5 != (void *)0x0) {
    pvVar2 = (void *)lstNext(pvVar5);
    iVar3 = cplusMangledSymCheck(*(undefined4 *)((int)pvVar5 + 8));
    if (iVar3 == 0) {
      lstDelete(auStack_40,pvVar5);
      free(pvVar5);
    }
    else {
      for (__ptr = (void *)lstFirst(auStack_34); __ptr != (void *)0x0;
          __ptr = (void *)lstNext(__ptr)) {
        iVar3 = strcmp(*(char **)((int)pvVar5 + 8),*(char **)((int)__ptr + 8));
        if (iVar3 == 0) {
          lstDelete(auStack_40,pvVar5);
          free(pvVar5);
          lstDelete(auStack_34,__ptr);
          free(__ptr);
          break;
        }
      }
    }
    goto joined_r0x30104168;
  }
  lstFree(auStack_34);
  iVar3 = lstFirst(auStack_40);
  if (iVar3 != 0) {
    do {
      iVar4 = strcmp(*(char **)(iVar3 + 0x10),param_2);
      if (iVar4 == 0) break;
      iVar3 = lstNext(iVar3);
    } while (iVar3 != 0);
    if (iVar3 != 0) goto LAB_3010437c;
  }
  pvVar2 = (void *)lstFirst(auStack_40);
  while (pvVar2 != (void *)0x0) {
    bVar1 = false;
    pvVar5 = (void *)lstNext(pvVar2);
    __s = *(char **)((int)pvVar2 + 0x10);
    sVar6 = strlen(__s);
    pcVar9 = __s + (sVar6 - 1);
    if (__s[sVar6 - 1] == ')') {
      iVar3 = 1;
      pcVar9 = __s + (sVar6 - 2);
      do {
        if (__s == pcVar9) break;
        if (*pcVar9 == ')') {
          iVar3 = iVar3 + 1;
        }
        else if (*pcVar9 == '(') {
          iVar3 = iVar3 + -1;
        }
        pcVar9 = pcVar9 + -1;
      } while (0 < iVar3);
      pcVar9[1] = '\0';
      bVar1 = true;
    }
    iVar3 = strcmp(param_2,*(char **)((int)pvVar2 + 0x10));
    if (iVar3 == 0) {
      pvVar2 = pvVar5;
      if (bVar1) {
        pcVar9[1] = '(';
      }
    }
    else {
      lstDelete(auStack_40,pvVar2);
      free(pvVar2);
      pvVar2 = pvVar5;
    }
  }
  iVar3 = lstCount(auStack_40);
  if (iVar3 == 1) {
    iVar3 = lstFirst();
  }
  else {
    iVar4 = lstCount(auStack_40);
    iVar3 = 0;
    if (1 < iVar4) {
      shellPrint(0,DAT_30104964,param_2);
      iVar4 = cplusUserAsk(auStack_40);
      if (0 < iVar4) {
        iVar3 = lstNth(auStack_40,iVar4);
      }
    }
  }
LAB_3010437c:
  iVar4 = -1;
  if (iVar3 != 0) {
    iVar4 = symFindByName(param_1,*(undefined4 *)(iVar3 + 8),param_3,local_44);
  }
  lstFree(auStack_40);
  if (iVar4 == 0) {
    uVar7 = FUN_30103f20(local_44[0]);
    *param_4 = uVar7;
  }
  else {
    puVar8 = (undefined4 *)__errno();
    *puVar8 = DAT_30104968;
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * FUN_301043e4 @ 0x301043E4  (примерный размер ~204 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_30103f20, FUN_301040fc, __errno, cplusMangledSymCheck, cplusMangledSymGet
 * Вызывают: shellInternalSymbolGet
 * Константы: 0x301043E4
 * Данные: DAT_3010494c, DAT_3010496c
 * ---------------------------------------------------------------- */
int FUN_301043e4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_20 [4];
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_3010494c;
    iVar2 = -1;
  }
  else {
    iVar2 = cplusMangledSymCheck(param_2);
    if (iVar2 == 0) {
      if (*param_5 == 0) {
        iVar2 = cplusMangledSymGet(param_1,param_2,local_20,param_3,param_5);
        if (iVar2 == 0) {
          uVar3 = FUN_30103f20(local_20[0]);
          *param_4 = uVar3;
        }
        if (iVar2 != -1) {
          return iVar2;
        }
      }
      iVar2 = FUN_301040fc(param_1,param_2,param_3,param_4,*param_5);
    }
    else {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = DAT_3010496c;
      iVar2 = -1;
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_301044b0 @ 0x301044B0  (примерный размер ~292 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 12
 * Вызывает: FUN_30103f20, calloc, cplusMatchMangledListGet, cplusUserAsk, lstFree, lstInit, lstInsert, lstNth, shellPrint, strcpy, strlen, symFindByName
 * Вызывают: shellInternalSymbolGet
 * Константы: 0x301044B0
 * Данные: DAT_30104970
 * ---------------------------------------------------------------- */
int FUN_301044b0(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  int iVar1;
  size_t sVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined1 local_2c [4];
  undefined1 auStack_28 [12];
  
  *param_5 = 0;
  lstInit(auStack_28);
  iVar1 = cplusMatchMangledListGet(param_1,param_2,auStack_28);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    sVar2 = strlen(param_2);
    pvVar3 = calloc(1,sVar2 + 0x19);
    if (pvVar3 == (void *)0x0) {
      lstFree(auStack_28);
      iVar1 = 0;
    }
    else {
      *(char **)((int)pvVar3 + 8) = (char *)((int)pvVar3 + 0x18);
      strcpy((char *)((int)pvVar3 + 0x18),param_2);
      lstInsert(auStack_28,0,pvVar3);
      shellPrint(0,DAT_30104970,param_2);
      iVar1 = cplusUserAsk(auStack_28);
      if ((iVar1 < 1) || (iVar1 = lstNth(auStack_28,iVar1), iVar1 == 0)) {
        iVar1 = -1;
      }
      else {
        iVar1 = symFindByName(param_1,*(undefined4 *)(iVar1 + 8),param_3,local_2c);
      }
      lstFree(auStack_28);
      *param_5 = 1;
      if (iVar1 == 0) {
        uVar4 = FUN_30103f20(local_2c[0]);
        *param_4 = uVar4;
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellInternalSymbolGet @ 0x301045D4  (примерный размер ~244 байт)
 * Модуль: shell | Вызывают: 4 | Вызывает: 7
 * Вызывает: FUN_30103f38, FUN_30104058, FUN_301043e4, FUN_301044b0, __errno, memcmp, shellConfigValueGet
 * Вызывают: FUN_30106d84, shellInternalDataSymbolGet, shellInternalSymbolsResolve, shellInternalTextSymbolGet
 * Константы: 0x301045D4
 * Данные: DAT_3010494c, DAT_30104974, DAT_30104978
 * ---------------------------------------------------------------- */
int shellInternalSymbolGet(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  void *__s1;
  bool bVar3;
  undefined4 local_1c;
  
  local_1c = 0;
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_3010494c;
    iVar2 = -1;
  }
  else {
    iVar2 = FUN_30103f38();
    if (iVar2 == 0) {
      __s1 = (void *)shellConfigValueGet(0,DAT_30104974);
      bVar3 = __s1 == (void *)0x0;
      if (!bVar3) {
        iVar2 = memcmp(__s1,DAT_30104978,4);
        bVar3 = iVar2 == 0;
      }
      if (bVar3) {
        return 0;
      }
      iVar2 = FUN_301044b0(param_1,param_2,param_3,param_4,&local_1c);
    }
    if ((iVar2 == -1) && (iVar2 = FUN_30104058(param_1,param_2,param_3,param_4), iVar2 == -1)) {
      iVar2 = FUN_301043e4(param_1,param_2,param_3,param_4,&local_1c);
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * shellInternalTextSymbolGet @ 0x301046C8  (примерный размер ~72 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, shellInternalSymbolGet
 * Константы: 0x301046C8, 0xFFFFFFFF
 * Данные: DAT_30104968
 * ---------------------------------------------------------------- */
undefined4 shellInternalTextSymbolGet(void)

{
  int iVar1;
  undefined4 *puVar2;
  int local_8;
  
  iVar1 = shellInternalSymbolGet();
  if (iVar1 == 0) {
    if (local_8 == 2 || local_8 == 4) {
      return 0;
    }
    puVar2 = (undefined4 *)__errno(local_8);
    *puVar2 = DAT_30104968;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInternalDataSymbolGet @ 0x30104710  (примерный размер ~64 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, shellInternalSymbolGet
 * Константы: 0x30104710, 0xFFFFFFFF
 * Данные: DAT_30104968
 * ---------------------------------------------------------------- */
undefined4 shellInternalDataSymbolGet(void)

{
  int iVar1;
  undefined4 *puVar2;
  int local_8;
  
  iVar1 = shellInternalSymbolGet();
  if (iVar1 == 0) {
    if (local_8 == 3) {
      return 0;
    }
    puVar2 = (undefined4 *)__errno(0);
    *puVar2 = DAT_30104968;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInternalArgStackAllocate @ 0x30104750  (примерный размер ~36 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: shellMemCalloc
 * Константы: 0x30104750
 * ---------------------------------------------------------------- */
void shellInternalArgStackAllocate(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)shellMemCalloc(1,0x34);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * shellInternalFuncIntArgAdd @ 0x30104774  (примерный размер ~44 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3010aaf0
 * Константы: 0x30104774, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInternalFuncIntArgAdd(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if (0xb < uVar1) {
    return 0xffffffff;
  }
  param_1[uVar1 + 1] = param_2;
  *param_1 = uVar1 + 1;
  return 0;
}

/* ----------------------------------------------------------------
 * shellInternalFuncLLongArgAdd @ 0x301047A0  (примерный размер ~116 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x301047A0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInternalFuncLLongArgAdd(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_8 [2];
  
  if (*param_1 + 2U < 0xd) {
    piVar2 = (int *)&stack0xfffffff4;
    iVar3 = 2;
    do {
      iVar4 = *param_1;
      piVar2 = piVar2 + 1;
      param_1[iVar4 + 1] = *piVar2;
      *param_1 = iVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * shellInternalFuncFloatArgAdd @ 0x30104814  (примерный размер ~104 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30104814, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInternalFuncFloatArgAdd(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  if (*param_1 + 1U < 0xd) {
    iVar3 = 0;
    piVar2 = (int *)&stack0xfffffff8;
    do {
      iVar4 = *param_1;
      piVar2 = piVar2 + 1;
      param_1[iVar4 + 1] = *piVar2;
      *param_1 = iVar4 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 == 0);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * shellInternalFuncDoubleArgAdd @ 0x3010487C  (примерный размер ~108 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3010487C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInternalFuncDoubleArgAdd(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_8 [2];
  
  if (*param_1 + 2U < 0xd) {
    piVar2 = (int *)&stack0xfffffff4;
    iVar3 = 2;
    do {
      iVar4 = *param_1;
      piVar2 = piVar2 + 1;
      param_1[iVar4 + 1] = *piVar2;
      *param_1 = iVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * shellInternalFunctionCall @ 0x301048E8  (примерный размер ~572 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30108cb4
 * Константы: 0x301048E8, 0x30104910, 0xFFFFFFFF
 * Данные: DAT_3010497c
 * ---------------------------------------------------------------- */
undefined4 shellInternalFunctionCall(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 9) {
                    /* WARNING: Could not recover jumptable at 0x30104910. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_3010497c + param_2 * 4))();
    return uVar1;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInternalKernelSymbolCreate @ 0x30104B24  (примерный размер ~228 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 6
 * Вызывает: __errno, calloc, free, shellPrint, shellPrintErr, symRegister
 * Константы: 0xFFFFFFFF, 0x30104B24
 * Данные: DAT_30104d10, DAT_30104d14, DAT_30104d18, DAT_30104d1c, DAT_30104d20, DAT_30104d24, DAT_30104d28
 * ---------------------------------------------------------------- */
undefined4 shellInternalKernelSymbolCreate(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *__ptr;
  int iVar3;
  
  iVar3 = *DAT_30104d10;
  if (iVar3 == 0) {
    shellPrintErr(0,DAT_30104d14);
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30104d18;
    uVar2 = 0xffffffff;
  }
  else {
    __ptr = calloc(1,8);
    if (__ptr == (void *)0x0) {
      shellPrintErr(0,DAT_30104d1c);
      uVar2 = 0xffffffff;
    }
    else {
      iVar3 = symRegister(iVar3,param_1,__ptr,0x11,*DAT_30104d20,0xffffffff,1);
      if (iVar3 == 0) {
        free(__ptr);
        puVar1 = (undefined4 *)__errno();
        shellPrintErr(0,DAT_30104d24,param_1,*puVar1);
        uVar2 = 0xffffffff;
      }
      else {
        shellPrint(0,DAT_30104d28,param_1);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellInternalSymbolDisplay @ 0x30104C08  (примерный размер ~228 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 4
 * Вызывает: cplusDemangle, free, shellPrint, symByValueFind
 * Вызывают: FUN_301090ac
 * Константы: 0x30104C08
 * Данные: DAT_30104d2c, DAT_30104d30, DAT_30104d34
 * ---------------------------------------------------------------- */
undefined4 shellInternalSymbolDisplay(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_124 [4];
  int local_120;
  void *local_11c;
  undefined1 auStack_118 [260];
  
  local_11c = (void *)0x0;
  if ((param_2 != -1) && (param_1 != 0)) {
    iVar1 = symByValueFind(param_1,param_2,&local_11c,&local_120,auStack_124);
    if ((iVar1 == 0) && ((local_120 != 0 && ((uint)(param_2 - local_120) < 0x1000)))) {
      uVar2 = cplusDemangle(local_11c,auStack_118,DAT_30104d2c);
      shellPrint(0,DAT_30104d30,param_3);
      if (local_120 == param_2) {
        shellPrint(0,DAT_30104d30,uVar2);
      }
      else {
        shellPrint(0,DAT_30104d34,uVar2,param_2 - local_120);
      }
      shellPrint(0,DAT_30104d30,param_4);
    }
  }
  free(local_11c);
  return 0;
}

/* ----------------------------------------------------------------
 * shellInternalDecValueDisplay @ 0x30104CEC  (примерный размер ~464 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: shellInternalValueDisplay
 * Константы: 0x30104CEC, 0x30104DC8, 0x30104DCC, 0x30104DD0, 0x30104DD4, 0x30104D0C, 0x30104DE8, 0xFFFFFFFF
 * Данные: DAT_30104d38, DAT_30104df4
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x30104dc8) */
/* WARNING: Removing unreachable block (ram,0x30104dcc) */
/* WARNING: Removing unreachable block (ram,0x30104dd0) */
/* WARNING: Removing unreachable block (ram,0x30104dd4) */

undefined4 shellInternalDecValueDisplay(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_3 < 9) {
                    /* WARNING: Could not recover jumptable at 0x30104d0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_30104d38 + param_3 * 4))();
    return uVar1;
  }
  if (param_3 < 9) {
                    /* WARNING: Could not recover jumptable at 0x30104de8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_30104df4 + param_3 * 4))();
    return uVar1;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInternalHexValueDisplay @ 0x30104EBC  (примерный размер ~400 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: shellInternalValueDisplay
 * Константы: 0x30104EBC, 0x30104EF4, 0xFFFFFFFF
 * Данные: DAT_30104efc, DAT_30104f00
 * ---------------------------------------------------------------- */
undefined4 shellInternalHexValueDisplay(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_1c [12];
  
  iVar2 = 10;
  puVar3 = auStack_1c;
  puVar4 = DAT_30104efc;
  do {
    iVar2 = iVar2 + -1;
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar2 != 0);
  if (param_2 < 9) {
                    /* WARNING: Could not recover jumptable at 0x30104ef4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_30104f00 + param_2 * 4))();
    return uVar1;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInternalValueDisplay @ 0x3010504C  (примерный размер ~324 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 3
 * Вызывает: shellInternalDecValueDisplay, shellInternalHexValueDisplay, shellPrint
 * Вызывают: FUN_301090ac
 * Константы: 0xFFFFFFFF, 0x3010504C, 0x301050C4
 * Данные: DAT_301050c8, DAT_301050cc
 * ---------------------------------------------------------------- */
undefined4
shellInternalValueDisplay(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = shellInternalDecValueDisplay(param_2,param_3,param_4);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if ((param_4 == 3) || (param_4 == 7)) {
    return 0;
  }
  shellPrint(0,DAT_301050c8);
  iVar1 = shellInternalHexValueDisplay(param_2,param_4);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (param_4 < 9) {
                    /* WARNING: Could not recover jumptable at 0x301050c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(DAT_301050cc + param_4 * 4))();
    return uVar2;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * shellInternalArgumentEval @ 0x30105190  (примерный размер ~72 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 3
 * Вызывает: shellInterpEvaluate, shellMemFree, shellMemStrdup
 * Константы: 0x30105190, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 shellInternalArgumentEval(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = shellMemStrdup();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  uVar2 = shellInterpEvaluate(iVar1,param_2,param_3);
  shellMemFree(iVar1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * shellInternalTaskNameMatch @ 0x301051D8  (примерный размер ~180 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 4
 * Вызывает: strlen, strncmp, taskIdListGet, taskName
 * Вызывают: FUN_30106e88
 * Константы: 0x301051D8
 * ---------------------------------------------------------------- */
int shellInternalTaskNameMatch(char *param_1,undefined4 *param_2)

{
  int iVar1;
  char *__s1;
  size_t __n;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  bool bVar6;
  undefined4 uStack_7f4;
  undefined4 local_7f0 [500];
  
  uVar3 = 0;
  bVar6 = param_1 == (char *)0x0;
  iVar5 = 0;
  if (!bVar6) {
    bVar6 = *param_1 == '\0';
  }
  if (bVar6) {
    iVar5 = 0;
  }
  else {
    iVar1 = taskIdListGet(local_7f0,500);
    if (0 < iVar1) {
      puVar4 = &uStack_7f4;
      do {
        puVar4 = puVar4 + 1;
        __s1 = (char *)taskName(*puVar4);
        if (__s1 != (char *)0x0) {
          __n = strlen(param_1);
          iVar2 = strncmp(__s1,param_1,__n);
          if (iVar2 == 0) {
            if (iVar5 == 0) {
              uVar3 = *puVar4;
            }
            iVar5 = iVar5 + 1;
          }
        }
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      if (iVar5 == 1) {
        *param_2 = uVar3;
      }
    }
  }
  return iVar5;
}

/* ----------------------------------------------------------------
 * shellInternalStrToChar @ 0x3010528C  (примерный размер ~292 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: __rem32, sscanf
 * Константы: 0x3010528C
 * Данные: DAT_301061fc
 * ---------------------------------------------------------------- */
int shellInternalStrToChar(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_14;
  
  bVar2 = *param_1;
  iVar4 = 1;
  if (bVar2 == 0x5c) {
    param_1 = param_1 + 1;
    bVar2 = *param_1;
    uVar3 = (uint)bVar2;
    if (uVar3 - 0x30 < 8) {
      local_14 = 0;
      sscanf((char *)param_1,DAT_301061fc,&local_14);
      bVar2 = __rem32(local_14,0x100);
      bVar1 = *param_1;
      while ((0x2f < bVar1 && (*param_1 < 0x38))) {
        param_1 = param_1 + 1;
        bVar1 = *param_1;
        iVar4 = iVar4 + 1;
      }
    }
    else {
      iVar4 = 2;
      if (uVar3 == 0x66) {
        bVar2 = 0xc;
      }
      else if (uVar3 < 0x67) {
        if (uVar3 == 0x5c) {
          bVar2 = 0x5c;
        }
        else if (uVar3 < 0x5d) {
          if (uVar3 == 0x22) {
            bVar2 = 0x22;
          }
          else if (uVar3 == 0x27) {
            bVar2 = 0x27;
          }
        }
        else if (uVar3 == 0x61) {
          bVar2 = 7;
        }
        else if (uVar3 == 0x62) {
          bVar2 = 8;
        }
      }
      else if (uVar3 == 0x6e) {
        bVar2 = 10;
      }
      else if (uVar3 == 0x72) {
        bVar2 = 0xd;
      }
      else if (uVar3 == 0x74) {
        bVar2 = 9;
      }
      else if (uVar3 == 0x76) {
        bVar2 = 0xb;
      }
    }
  }
  *param_2 = bVar2;
  return iVar4;
}

/* ----------------------------------------------------------------
 * shellInternalStrUnquote @ 0x301053B0  (примерный размер ~308 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 3
 * Вызывает: __errno, bcopy, strlen
 * Вызывают: FUN_301009f4, FUN_30105988
 * Константы: 0x301053B0
 * Данные: DAT_30106200, DAT_30106204
 * ---------------------------------------------------------------- */
char * shellInternalStrUnquote(char *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  size_t sVar3;
  char cVar4;
  uint uVar5;
  char *__dest;
  
  if (param_1 == (char *)0x0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x16;
    return (char *)0x0;
  }
  cVar4 = *param_1;
  __dest = param_1;
  do {
    if (cVar4 == '\0') {
      return param_1;
    }
    cVar4 = *__dest;
    if ((cVar4 == '\\') || (cVar4 == '\"')) {
      sVar3 = strlen(__dest + 1);
      bcopy(__dest + 1,__dest,sVar3 + 1);
      cVar1 = *__dest;
      if (cVar4 != '\"') {
        if (cVar1 == '\0') {
          return param_1;
        }
        goto LAB_301054cc;
      }
      while ((cVar1 != '\"' && (*__dest != '\0'))) {
        if ((*__dest == '\\') && (uVar5 = (uint)(byte)__dest[1], uVar5 != 0)) {
          if (uVar5 < 0x75) {
            cVar4 = *(char *)(DAT_30106200 + uVar5);
          }
          else {
            cVar4 = '\0';
          }
          if (cVar4 != '\0') {
            sVar3 = strlen(__dest + 1);
            bcopy(__dest + 1,__dest,sVar3 + 1);
            *__dest = cVar4;
          }
        }
        __dest = __dest + 1;
        cVar1 = *__dest;
      }
      if (*__dest == '\0') {
        puVar2 = (undefined4 *)__errno();
        *puVar2 = DAT_30106204;
        return (char *)0x0;
      }
      sVar3 = strlen(__dest + 1);
      bcopy(__dest + 1,__dest,sVar3 + 1);
    }
    else {
LAB_301054cc:
      __dest = __dest + 1;
    }
    cVar4 = *__dest;
  } while( true );
}

/* ----------------------------------------------------------------
 * shellInternalStrTokenize @ 0x301054E4  (примерный размер ~248 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 3
 * Вызывает: strlen, strpbrk, strspn
 * Вызывают: FUN_301009f4, FUN_30105988, shellInternalStrSpaceTokenize
 * Константы: 0x301054E4
 * ---------------------------------------------------------------- */
char * shellInternalStrTokenize(char *param_1,char *param_2,int *param_3)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  
  if ((param_1 == (char *)0x0) && (param_1 = (char *)*param_3, param_1 == (char *)0x0)) {
    return (char *)0x0;
  }
  sVar2 = strspn(param_1,param_2);
  param_1 = param_1 + sVar2;
  pcVar4 = param_1;
  do {
    while( true ) {
      cVar1 = *pcVar4;
      while (cVar1 == '\\') {
        pcVar4 = pcVar4 + 2;
        cVar1 = *pcVar4;
      }
      if (*pcVar4 != '\"') break;
      do {
        pcVar3 = pcVar4;
        pcVar4 = pcVar3 + 1;
        cVar1 = *pcVar4;
        if ((cVar1 == '\"') && (*pcVar3 != '\\')) break;
      } while (cVar1 != '\0');
      if (cVar1 == '\"') {
        pcVar4 = pcVar3 + 2;
      }
    }
    pcVar3 = strpbrk(pcVar4,param_2);
    if (pcVar3 == pcVar4) {
      *pcVar4 = '\0';
      pcVar4 = pcVar4 + 1;
      goto LAB_301055b8;
    }
    if (*pcVar4 == '\0') {
      pcVar4 = (char *)0x0;
LAB_301055b8:
      *param_3 = (int)pcVar4;
      sVar2 = strlen(param_1);
      if (sVar2 != 0) {
        return param_1;
      }
      return (char *)0x0;
    }
    pcVar4 = pcVar4 + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * shellInternalStrSpaceTokenize @ 0x301055DC  (примерный размер ~12 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: shellInternalStrTokenize
 * Константы: 0x301055DC
 * Данные: DAT_30106208
 * ---------------------------------------------------------------- */
void shellInternalStrSpaceTokenize(undefined4 param_1,undefined4 param_2)

{
  shellInternalStrTokenize(param_1,DAT_30106208,param_2);
  return;
}

/* ----------------------------------------------------------------
 * shellInternalStrToInt2 @ 0x301055E8  (примерный размер ~572 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 5
 * Вызывает: sscanf, strchr, strcpy, strlen, strpbrk
 * Константы: 0x301055E8
 * Данные: DAT_3010620c, DAT_30106210, DAT_30106214
 * ---------------------------------------------------------------- */
int shellInternalStrToInt2(char *param_1,undefined2 *param_2,undefined4 *param_3,uint *param_4)

{
  byte bVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  byte abStack_12d [128];
  undefined1 local_ad;
  char local_ac [127];
  undefined1 local_2d;
  
  iVar9 = 0;
  iVar4 = 0;
  iVar6 = 0;
  sVar2 = strlen(param_1);
  if (((sVar2 != 0) && ((int)sVar2 < 0x80)) &&
     (pcVar3 = strchr(param_1,0x2e), pcVar3 == (char *)0x0)) {
    strcpy((char *)(abStack_12d + 1),param_1);
    uVar8 = 0;
    local_ad = 0;
    sVar2 = strlen((char *)(abStack_12d + 1));
    if (sVar2 != 0) {
      iVar5 = *DAT_3010620c;
      pbVar7 = abStack_12d;
      do {
        pbVar7 = pbVar7 + 1;
        uVar8 = uVar8 + 1;
        *pbVar7 = *(byte *)(iVar5 + (uint)*pbVar7);
        sVar2 = strlen((char *)(abStack_12d + 1));
      } while (uVar8 < sVar2);
    }
    uVar8 = (uint)(abStack_12d[1] == '-');
    if (((abStack_12d[uVar8 + 1] == 0x30) || (abStack_12d[uVar8 + 2] == 0x78)) ||
       (pcVar3 = strpbrk((char *)(abStack_12d + 1),DAT_30106210), pcVar3 == (char *)0x0)) {
      do {
        sVar2 = strlen((char *)(abStack_12d + 1));
        bVar1 = abStack_12d[sVar2];
        if (bVar1 == 0x75) {
          iVar4 = iVar4 + 1;
        }
        else if (bVar1 == 0x68) {
          iVar9 = iVar9 + 1;
        }
        else {
          if (bVar1 != 0x72) {
            *param_4 = (uint)(0 < iVar4);
            if (iVar9 == 0) {
              if (iVar6 == 0) {
                return -1;
              }
              *param_3 = 1;
            }
            else {
              *param_3 = 2;
            }
            if (abStack_12d[uVar8 + 1] == 0x30) {
              if ((abStack_12d[uVar8 + 2] == 0x78) && (abStack_12d[uVar8 + 3] == 0)) {
                return -1;
              }
            }
            else if (abStack_12d[uVar8 + 1] == 0) {
              return -1;
            }
            local_ac[0] = '\0';
            iVar4 = sscanf((char *)(abStack_12d + 1),DAT_30106214,param_2,local_ac);
            local_2d = 0;
            sVar2 = strlen(local_ac);
            if (sVar2 != 0) {
              return -1;
            }
            if (iVar4 == 1) {
              *param_3 = 2;
              if (iVar6 != 0) {
                *(char *)param_2 = (char)*param_2;
                *param_3 = 1;
                return 1;
              }
              return 1;
            }
            return iVar4;
          }
          iVar6 = iVar6 + 1;
        }
        abStack_12d[sVar2] = 0;
      } while( true );
    }
  }
  return -1;
}

/* ----------------------------------------------------------------
 * shellInternalStrToFloat @ 0x30105824  (примерный размер ~288 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 4
 * Вызывает: sprintf, sscanf, strlen, strncpy
 * Константы: 0x30105824
 * Данные: DAT_301060d0, DAT_30106218, DAT_3010621c
 * ---------------------------------------------------------------- */
int shellInternalStrToFloat(char *param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  char acStack_120 [7];
  char acStack_119 [128];
  undefined1 local_99;
  char local_98 [127];
  undefined1 local_19;
  
  iVar4 = 0;
  sVar3 = strlen(param_1);
  if ((sVar3 == 0) || (0x7f < (int)sVar3)) {
    return -1;
  }
  strncpy(acStack_119 + 1,param_1,0x7f);
  local_99 = 0;
  sVar3 = strlen(acStack_119 + 1);
  cVar1 = acStack_119[sVar3];
  if ((cVar1 == 'f') || (cVar1 == 'F')) {
    iVar4 = 1;
  }
  else {
    if ((cVar1 != 'l') && (cVar1 != 'L')) goto LAB_301058c8;
    iVar4 = -1;
  }
  acStack_119[sVar3] = '\0';
LAB_301058c8:
  if (acStack_119[1] == '\0') {
    iVar4 = -1;
  }
  else {
    if (iVar4 == 1) {
      uVar5 = 3;
      uVar2 = DAT_301060d0;
    }
    else {
      uVar5 = 7;
      uVar2 = DAT_30106218;
    }
    *param_3 = uVar5;
    sprintf(acStack_120,DAT_3010621c,uVar2);
    local_98[0] = '\0';
    iVar4 = sscanf(acStack_119 + 1,acStack_120,param_2,local_98);
    local_19 = 0;
    sVar3 = strlen(local_98);
    if (sVar3 != 0) {
      iVar4 = -1;
    }
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * shellInternalOptFree @ 0x30105944  (примерный размер ~68 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 1
 * Вызывает: shellMemFree
 * Вызывают: shellInternalOptGet
 * Константы: 0x30105944
 * ---------------------------------------------------------------- */
void shellInternalOptFree(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = param_1[2];
  piVar2 = param_1;
  while (iVar3 == 0) {
    if (*piVar2 != 0) {
      shellMemFree();
    }
    piVar1 = piVar2 + 5;
    piVar2 = piVar2 + 3;
    iVar3 = *piVar1;
  }
  shellMemFree(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30105988 @ 0x30105988  (примерный размер ~924 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 11
 * Вызывает: __errno, lstAdd, lstFree2, lstInit, shellInternalStrTokenize, shellInternalStrUnquote, shellMemCalloc, shellMemFree, shellMemStrdup, shellPrintErr, strlen
 * Вызывают: shellInternalOptGet
 * Константы: 0x30105988
 * Данные: DAT_30106208, DAT_30106220, DAT_30106224, DAT_30106228
 * ---------------------------------------------------------------- */
int FUN_30105988(char *param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  size_t sVar7;
  undefined4 *puVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  bool bVar12;
  int local_2c;
  undefined1 auStack_28 [4];
  
  local_2c = 0;
  lstInit(param_3);
  bVar12 = param_1 == (char *)0x0;
  if (!bVar12) {
    bVar12 = *param_1 == '\0';
  }
  if (bVar12) {
    local_2c = 0;
  }
  else {
    iVar3 = shellMemStrdup(param_1);
    if (iVar3 == 0) {
      local_2c = -1;
    }
    else if ((param_2 == (char *)0x0) || (*param_2 != ':')) {
      bVar12 = param_2 == (char *)0x0;
      if (!bVar12) {
        bVar12 = *param_2 == '\0';
      }
      pcVar6 = (char *)shellInternalStrTokenize(iVar3,DAT_30106208,auStack_28);
      if ((pcVar6 != (char *)0x0) &&
         (pcVar6 = (char *)shellInternalStrUnquote(pcVar6), pcVar6 == (char *)0x0)) {
        local_2c = -1;
      }
      bVar2 = false;
      do {
        if (pcVar6 == (char *)0x0) goto LAB_30105cf8;
        if (!bVar12) {
          while ((*pcVar6 == '-' && (!bVar2))) {
            cVar1 = pcVar6[1];
            if ((cVar1 == '-') && (pcVar6[2] == '\0')) {
              bVar12 = true;
            }
            else {
              uVar11 = 0;
              sVar7 = strlen(param_2);
              if (sVar7 == 0) {
LAB_30105b50:
                shellPrintErr(0,DAT_30106220,cVar1);
                puVar8 = (undefined4 *)__errno();
                *puVar8 = DAT_30106224;
                goto LAB_30105cf0;
              }
              pcVar10 = param_2 + -1;
              while( true ) {
                pcVar10 = pcVar10 + 1;
                if ((*pcVar10 != ':') && (cVar1 == *pcVar10)) break;
                uVar11 = uVar11 + 1;
                sVar7 = strlen(param_2);
                if (sVar7 <= uVar11) goto LAB_30105b50;
              }
              if (param_2[uVar11 + 1] == ':') {
                bVar2 = true;
              }
            }
            iVar4 = shellMemCalloc(1,0xc);
            if (iVar4 == 0) {
LAB_30105b9c:
              shellMemFree(iVar4);
              lstFree2(param_3,DAT_30106228);
              shellMemFree(iVar3);
              return -1;
            }
            iVar9 = shellMemStrdup(pcVar6);
            *(int *)(iVar4 + 8) = iVar9;
            if (iVar9 == 0) goto LAB_30105b9c;
            lstAdd(param_3,iVar4);
            if ((bVar12) || (pcVar6[2] == '\0')) goto LAB_30105cbc;
            *(undefined1 *)(*(int *)(iVar4 + 8) + 2) = 0;
            if (bVar2) {
              iVar4 = shellMemCalloc(1,0xc);
              if (iVar4 != 0) {
                iVar9 = shellMemStrdup(pcVar6 + 2);
                *(int *)(iVar4 + 8) = iVar9;
                if (iVar9 != 0) goto LAB_30105cac;
              }
              shellMemFree(iVar4);
              lstFree2(param_3,DAT_30106228);
              shellMemFree(iVar3);
              return -1;
            }
            pcVar6 = pcVar6 + 1;
            *pcVar6 = '-';
            if (pcVar6 == (char *)0x0) goto LAB_30105cf8;
          }
        }
        iVar4 = shellMemCalloc(1,0xc);
        if (iVar4 == 0) {
LAB_30105c88:
          shellMemFree(iVar4);
          lstFree2(param_3,DAT_30106228);
          shellMemFree(iVar3);
          return -1;
        }
        iVar9 = shellMemStrdup(pcVar6);
        *(int *)(iVar4 + 8) = iVar9;
        if (iVar9 == 0) goto LAB_30105c88;
LAB_30105cac:
        lstAdd(param_3,iVar4);
        bVar2 = false;
LAB_30105cbc:
        pcVar6 = (char *)shellInternalStrTokenize(0,DAT_30106208,auStack_28);
      } while ((pcVar6 == (char *)0x0) ||
              (pcVar6 = (char *)shellInternalStrUnquote(pcVar6), pcVar6 != (char *)0x0));
LAB_30105cf0:
      local_2c = -1;
LAB_30105cf8:
      shellMemFree(iVar3);
      if (local_2c == -1) {
        lstFree2(param_3,DAT_30106228);
      }
    }
    else {
      iVar4 = shellMemCalloc(1,0xc);
      if (iVar4 != 0) {
        uVar5 = shellMemStrdup(iVar3);
        *(undefined4 *)(iVar4 + 8) = uVar5;
      }
      shellMemFree(iVar3);
      if ((iVar4 == 0) || (*(int *)(iVar4 + 8) == 0)) {
        shellMemFree(iVar4);
        local_2c = -1;
      }
      else {
        lstAdd(param_3,iVar4);
        local_2c = 0;
      }
    }
  }
  return local_2c;
}

/* ----------------------------------------------------------------
 * shellInternalOptGet @ 0x30105D24  (примерный размер ~740 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 13
 * Вызывает: FUN_30103da4, FUN_30105988, __errno, __udiv32, lstCount, lstDelete, lstFirst, lstFree2, lstNext, shellInternalOptFree, shellMemCalloc, shellMemStrdup, strlen
 * Константы: 0xFFFFFFFF, 0x30105D24
 * Данные: DAT_30106228, DAT_3010622c
 * ---------------------------------------------------------------- */
uint shellInternalOptGet(byte *param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  byte *pbVar9;
  size_t sVar10;
  int *piVar11;
  byte *pbVar12;
  undefined1 auStack_34 [12];
  
  iVar3 = FUN_30105988(param_2,param_1,auStack_34);
  if (iVar3 == 0) {
    sVar10 = 0;
    if (param_1 != (byte *)0x0) {
      sVar10 = strlen((char *)param_1);
    }
    iVar3 = lstCount(auStack_34);
    iVar3 = (iVar3 + sVar10) * 0xc + 0xc;
    piVar5 = (int *)shellMemCalloc(1,iVar3);
    if (piVar5 == (int *)0x0) {
      lstFree2(auStack_34,DAT_30106228);
      uVar4 = 0xffffffff;
    }
    else {
      iVar3 = __udiv32(iVar3,0xc);
      piVar5[iVar3 * 3 + -1] = 1;
      piVar11 = piVar5;
      if (((param_1 != (byte *)0x0) && (*param_1 != 0)) && (pbVar9 = param_1, *param_1 != 0x3a)) {
        do {
          bVar1 = *pbVar9;
          iVar3 = lstFirst(auStack_34);
          if (iVar3 == 0) {
LAB_30105f18:
            piVar11[1] = 0;
          }
          else {
            do {
              pbVar12 = *(byte **)(iVar3 + 8);
              if (*pbVar12 == param_3) {
                if ((pbVar12[1] == param_3) && (pbVar12[2] == 0)) goto LAB_30105f18;
                if ((*pbVar12 == param_3) && ((uint)pbVar12[1] == (uint)bVar1)) break;
              }
              iVar3 = lstNext(iVar3);
            } while (iVar3 != 0);
            if (iVar3 == 0) goto LAB_30105f18;
            piVar11[1] = 1;
            if (pbVar9[1] == 0x3a) {
              iVar6 = lstNext(iVar3);
              if (iVar6 == 0) {
                puVar7 = (undefined4 *)__errno();
                *puVar7 = DAT_3010622c;
                shellInternalOptFree(piVar5);
                lstFree2(auStack_34,DAT_30106228);
                return 0xffffffff;
              }
              iVar8 = shellMemStrdup(*(undefined4 *)(iVar6 + 8));
              *piVar11 = iVar8;
              if (iVar8 == 0) {
                shellInternalOptFree(piVar5);
                lstFree2(auStack_34,DAT_30106228);
                return 0xffffffff;
              }
              lstDelete(auStack_34,iVar6);
              FUN_30103da4(iVar6);
              pbVar9 = pbVar9 + 1;
            }
            lstDelete(auStack_34,iVar3);
            FUN_30103da4(iVar3);
          }
          pbVar12 = pbVar9 + 1;
          piVar11 = piVar11 + 3;
          if (*pbVar12 == 0x3a) {
            pbVar12 = pbVar9 + 2;
          }
          pbVar9 = pbVar12;
        } while (*pbVar12 != 0);
      }
      bVar2 = false;
      for (iVar3 = lstFirst(auStack_34); iVar3 != 0; iVar3 = lstNext(iVar3)) {
        pbVar9 = *(byte **)(iVar3 + 8);
        if (((bVar2) || (*pbVar9 != param_3)) || ((pbVar9[1] != param_3 || (pbVar9[2] != 0)))) {
          iVar6 = shellMemStrdup(pbVar9);
          *piVar11 = iVar6;
          if (iVar6 == 0) {
            shellInternalOptFree(piVar5);
            lstFree2(auStack_34,DAT_30106228);
            return 0xffffffff;
          }
          piVar11 = piVar11 + 3;
        }
        else {
          bVar2 = true;
        }
      }
      *piVar11 = 0;
      piVar11[1] = 0;
      piVar11[2] = 1;
      lstFree2(auStack_34,DAT_30106228);
      uVar4 = (uint)(param_1 == (byte *)0x0);
      *param_4 = piVar5;
    }
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * shellInternalSymbolsResolve @ 0x30106008  (примерный размер ~848 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 11
 * Вызывает: __errno, memcmp, shellInternalSymbolGet, shellMemFree, shellMemRealloc, shellMemStrdup, shellPrintErr, sprintf, strlen, strpbrk, strrchr
 * Константы: 0xFFFFFFFF, 0x30106008, 0x301061F8
 * Данные: DAT_30106230, DAT_30106234, DAT_30106238, DAT_3010623c, DAT_30106240, DAT_30106244, DAT_30106248, DAT_3010624c
 * ---------------------------------------------------------------- */
undefined4 shellInternalSymbolsResolve(undefined4 *param_1,undefined4 param_2)

{
  char *__s;
  char *pcVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  undefined4 uVar5;
  uint uVar6;
  byte *__s_00;
  char *__s_01;
  undefined1 local_2c [4];
  int local_28;
  
  do {
    if (param_1[2] != 0) {
      return 0;
    }
    __s_01 = (char *)*param_1;
    if ((__s_01 != (char *)0x0) && (((*__s_01 == '&' || (*__s_01 == '$')) && (__s_01[1] != '\0'))))
    {
      __s = (char *)shellMemStrdup(__s_01 + 1);
      if (__s == (char *)0x0) {
        return 0xffffffff;
      }
      pcVar1 = strrchr(__s,0x2e);
      __s_00 = DAT_30106230;
      if (pcVar1 != (char *)0x0) {
        *pcVar1 = '\0';
        __s_00 = (byte *)(pcVar1 + 1);
      }
      iVar2 = shellInternalSymbolGet(param_2,__s,local_2c,&local_28);
      if (iVar2 != 0) {
        piVar3 = (int *)__errno();
        if (*piVar3 == DAT_30106234) {
          shellPrintErr(0,DAT_30106238);
        }
        else {
          shellPrintErr(0,DAT_3010623c,__s);
        }
        shellMemFree(__s);
        return 0xffffffff;
      }
      if ((local_28 == 2) && (*(char *)*param_1 == '$')) {
        shellPrintErr(0,DAT_30106240,__s);
        shellMemFree(__s);
        return 0xffffffff;
      }
      uVar6 = 10;
      if (*__s_01 == '$') {
        iVar2 = memcmp(__s_00,DAT_30106244,3);
        if (iVar2 == 0) {
          uVar6 = 0x12;
        }
        else {
          pcVar1 = strpbrk((char *)__s_00,DAT_30106248);
          if (pcVar1 != (char *)0x0) {
            uVar6 = 0x1e;
          }
        }
      }
      sVar4 = strlen(__s_01);
      if (sVar4 < uVar6) {
        __s_01 = (char *)shellMemRealloc(__s_01,uVar6 + 1);
        *param_1 = __s_01;
      }
      if (__s_01 == (char *)0x0) {
        shellPrintErr(0,DAT_3010624c);
        shellMemFree(__s);
        return 0xffffffff;
      }
      if (((local_28 == 2) && (*__s_01 == '&')) || (*__s_01 != '$')) {
        sprintf(__s_01,DAT_30106460);
      }
      else if (*__s_00 - 100 < 0xf) {
                    /* WARNING: Could not recover jumptable at 0x301061f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar5 = (**(code **)(DAT_30106250 + (*__s_00 - 100) * 4))();
        return uVar5;
      }
      shellMemFree(__s);
    }
    param_1 = param_1 + 3;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_30106358 @ 0x30106358  (примерный размер ~148 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_301063ec, FUN_30106424
 * Константы: 0x30106358
 * ---------------------------------------------------------------- */
undefined4 FUN_30106358(char *param_1,char *param_2)

{
  if (((*param_1 != '_') || (param_1[1] != 'A')) || (param_1[2] != '_')) {
    return 0;
  }
  param_1 = param_1 + 3;
  if (*param_2 != '\0') {
    do {
      if ((*param_1 == '\0') || (*param_2 != *param_1)) break;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (*param_2 != '\0');
    if (*param_2 != '\0') {
      return 0;
    }
  }
  if ((*param_1 != '\0') && (*param_1 != '.')) {
    return 0;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_301063ec @ 0x301063EC  (примерный размер ~56 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_30106358
 * Константы: 0x301063EC
 * ---------------------------------------------------------------- */
undefined4
FUN_301063ec(undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_30106358(param_1,param_4[1]);
  if (iVar1 != 0) {
    param_4[2] = param_4[2] + 1;
    *(undefined1 *)(param_4 + 3) = param_3;
    *param_4 = param_2;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_30106424 @ 0x30106424  (примерный размер ~68 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30106358, shellPrint
 * Константы: 0x30106424
 * Данные: DAT_30106464
 * ---------------------------------------------------------------- */
undefined4 FUN_30106424(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_30106358(param_1,param_4);
  if (iVar1 != 0) {
    shellPrint(0,DAT_30106464,param_1);
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_30106468 @ 0x30106468  (примерный размер ~32 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: shellInterpCparse
 * Константы: 0x30106468
 * ---------------------------------------------------------------- */
void FUN_30106468(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  if (param_3 < 1) {
    return;
  }
  do {
    param_3 = param_3 + -1;
    *param_1 = *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (param_3 != 0);
  return;
}

/* ----------------------------------------------------------------
 * shellInterpC_load_buffer_state @ 0x30106488  (примерный размер ~68 байт)
 * Модуль: shell | Вызывают: 4 | Вызывает: 0
 * Вызывают: shellInterpC_flush_buffer, shellInterpC_switch_to_buffer, shellInterpClex, shellInterpCrestart
 * Константы: 0x30106488
 * Данные: DAT_3010743c, DAT_30107440, DAT_30107444
 * ---------------------------------------------------------------- */
void shellInterpC_load_buffer_state(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_3010743c;
  puVar3 = *(undefined4 **)(DAT_3010743c + 8);
  *(undefined4 *)(DAT_3010743c + 0x10) = puVar3[4];
  puVar2 = (undefined1 *)puVar3[2];
  *(undefined1 **)(puVar1 + 0xc) = puVar2;
  *DAT_30107440 = puVar2;
  *DAT_30107444 = *puVar3;
  *puVar1 = *puVar2;
  return;
}

/* ----------------------------------------------------------------
 * shellInterpC_flush_buffer @ 0x301064CC  (примерный размер ~76 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 1
 * Вызывает: shellInterpC_load_buffer_state
 * Вызывают: shellInterpC_init_buffer
 * Константы: 0x301064CC
 * Данные: DAT_30107448
 * ---------------------------------------------------------------- */
void shellInterpC_flush_buffer(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  **(undefined1 **)(param_1 + 4) = 0;
  *(undefined1 *)(*(int *)(param_1 + 4) + 1) = 0;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (*DAT_30107448 == param_1) {
    shellInterpC_load_buffer_state(param_1,0,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * shellInterpC_init_buffer @ 0x30106518  (примерный размер ~40 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 1
 * Вызывает: shellInterpC_flush_buffer
 * Вызывают: shellInterpC_create_buffer, shellInterpCrestart
 * Константы: 0x30106518
 * ---------------------------------------------------------------- */
void shellInterpC_init_buffer(undefined4 *param_1,undefined4 param_2)

{
  shellInterpC_flush_buffer();
  *param_1 = param_2;
  param_1[8] = 1;
  param_1[6] = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30106540 @ 0x30106540  (примерный размер ~36 байт)
 * Модуль: shell | Вызывают: 8 | Вызывает: 3
 * Вызывает: __stderr, exit, fprintf
 * Вызывают: FUN_3010661c, FUN_30106fd0, FUN_30107098, shellInterpC_create_buffer, shellInterpC_scan_buffer, shellInterpC_scan_bytes, shellInterpC_scan_string, shellInterpClex
 * Константы: 0x30106540
 * Данные: DAT_3010744c
 * ---------------------------------------------------------------- */
void FUN_30106540(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)__stderr();
  fprintf((FILE *)*puVar1,DAT_3010744c,param_1);
  exit(2);
  return;
}

/* ----------------------------------------------------------------
 * shellInterpC_create_buffer @ 0x30106564  (примерный размер ~104 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_30106540, shellInterpC_init_buffer, shellMemMalloc
 * Вызывают: shellInterpClex, shellInterpCrestart
 * Константы: 0x30106564
 * Данные: DAT_30107500
 * ---------------------------------------------------------------- */
int shellInterpC_create_buffer(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = shellMemMalloc(0x28);
  if (iVar1 == 0) {
    FUN_30106540(DAT_30107500);
  }
  else {
    *(int *)(iVar1 + 0xc) = param_2;
    iVar2 = shellMemMalloc(param_2 + 2);
    *(int *)(iVar1 + 4) = iVar2;
    if (iVar2 != 0) goto LAB_301065b0;
  }
  FUN_30106540(DAT_30107500);
LAB_301065b0:
  *(undefined4 *)(iVar1 + 0x14) = 1;
  shellInterpC_init_buffer(iVar1,param_1);
  return iVar1;
}

/* ----------------------------------------------------------------
 * shellInterpCrestart @ 0x301065CC  (примерный размер ~80 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 3
 * Вызывает: shellInterpC_create_buffer, shellInterpC_init_buffer, shellInterpC_load_buffer_state
 * Вызывают: FUN_3010661c
 * Константы: 0x301065CC
 * Данные: DAT_3010743c, DAT_30107444
 * ---------------------------------------------------------------- */
void shellInterpCrestart(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_3010743c;
  if (*(int *)(DAT_3010743c + 8) == 0) {
    uVar2 = shellInterpC_create_buffer(*DAT_30107444,0x4000);
    *(undefined4 *)(iVar1 + 8) = uVar2;
  }
  shellInterpC_init_buffer(*(undefined4 *)(iVar1 + 8),param_1);
  shellInterpC_load_buffer_state();
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010661c @ 0x3010661C  (примерный размер ~432 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_30106540, shellInterpCrestart, shellMemRealloc
 * Вызывают: FUN_30107098
 * Константы: 0x3010661C
 * Данные: DAT_3010743c, DAT_30107440, DAT_30107444, DAT_30107504, DAT_30107508
 * ---------------------------------------------------------------- */
undefined1 * FUN_3010661c(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar1 = DAT_3010743c;
  iVar6 = *(int *)(DAT_3010743c + 8);
  puVar3 = *(undefined1 **)(iVar6 + 4);
  puVar2 = (undefined1 *)*DAT_30107440;
  if (puVar3 + *(int *)(DAT_3010743c + 0x10) + 1 < *(undefined1 **)(DAT_3010743c + 0xc)) {
    FUN_30106540(DAT_30107504);
LAB_30106780:
    FUN_30106540(DAT_30107508);
  }
  else {
    iVar8 = (int)*(undefined1 **)(DAT_3010743c + 0xc) - (int)puVar2;
    if (*(int *)(iVar6 + 0x20) == 0) {
      return (undefined1 *)((iVar8 != 1) + 1);
    }
    iVar6 = iVar8 + -1;
    iVar8 = iVar6;
    if (0 < iVar6) {
      do {
        iVar8 = iVar8 + -1;
        *puVar3 = *puVar2;
        puVar3 = puVar3 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar8 != 0);
    }
    if (*(int *)(*(int *)(iVar1 + 8) + 0x24) != 2) {
      iVar8 = *(int *)(*(int *)(iVar1 + 8) + 0xc) - iVar6;
      while (iVar8 + -1 < 1) {
        puVar2 = *(undefined1 **)(iVar1 + 8);
        iVar7 = *(int *)(iVar1 + 0xc);
        iVar8 = *(int *)(puVar2 + 4);
        if (*(int *)(puVar2 + 0x14) == 0) {
          iVar4 = 0;
        }
        else {
          uVar5 = *(uint *)(puVar2 + 0xc);
          iVar4 = uVar5 * 2;
          if (iVar4 < 1) {
            iVar4 = uVar5 + (uVar5 >> 3);
          }
          *(int *)(puVar2 + 0xc) = iVar4;
          iVar4 = shellMemRealloc(iVar8,iVar4 + 2);
        }
        *(int *)(puVar2 + 4) = iVar4;
        if (iVar4 == 0) goto LAB_30106780;
        *(int *)(iVar1 + 0xc) = iVar4 + (iVar7 - iVar8);
        iVar8 = *(int *)(*(int *)(iVar1 + 8) + 0xc) - iVar6;
      }
    }
    *(undefined4 *)(iVar1 + 0x10) = 0;
    if (iVar6 == 0) {
      puVar2 = (undefined1 *)0x1;
      shellInterpCrestart(*DAT_30107444);
    }
    else {
      puVar2 = (undefined1 *)0x2;
      *(undefined4 *)(*(int *)(iVar1 + 8) + 0x24) = 2;
    }
  }
  iVar6 = *(int *)(iVar1 + 0x10) + iVar6;
  *(int *)(iVar1 + 0x10) = iVar6;
  iVar1 = *(int *)(iVar1 + 8);
  *(undefined1 *)(*(int *)(iVar1 + 4) + iVar6) = 0;
  *(undefined1 *)(*(int *)(iVar1 + 4) + iVar6 + 1) = 0;
  *DAT_30107440 = *(undefined4 *)(iVar1 + 4);
  return puVar2;
}

/* ----------------------------------------------------------------
 * FUN_301067cc @ 0x301067CC  (примерный размер ~236 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x301067CC
 * Данные: DAT_3010743c, DAT_30107440, DAT_3010750c, DAT_30107510, DAT_30107514, DAT_30107518, DAT_3010751c, DAT_30107520
 * ---------------------------------------------------------------- */
void FUN_301067cc(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  
  iVar5 = DAT_30107518;
  iVar4 = DAT_30107514;
  iVar3 = DAT_30107510;
  iVar2 = DAT_3010750c;
  iVar1 = DAT_3010743c;
  iVar6 = *(int *)(DAT_3010743c + 0x14);
  pbVar7 = *(byte **)(DAT_3010743c + 0xc);
  for (pbVar8 = (byte *)*DAT_30107440; pbVar8 < pbVar7; pbVar8 = pbVar8 + 1) {
    if (*pbVar8 == 0) {
      uVar9 = 1;
    }
    else {
      uVar9 = *(uint *)(DAT_3010751c + (uint)*pbVar8 * 4);
    }
    if (*(short *)(iVar5 + iVar6 * 2) != 0) {
      *(int *)(iVar1 + 0x18) = iVar6;
      *(byte **)(iVar1 + 0x1c) = pbVar8;
    }
    if (*(short *)(iVar4 + ((int)*(short *)(iVar3 + iVar6 * 2) + (uVar9 & 0xff)) * 2) != iVar6) {
      do {
        iVar6 = (int)*(short *)(DAT_30107520 + iVar6 * 2);
        if (0xb3 < iVar6) {
          uVar9 = *(uint *)(DAT_30107524 + (uVar9 & 0xff) * 4);
        }
      } while (*(short *)(iVar4 + ((int)*(short *)(iVar3 + iVar6 * 2) + (uVar9 & 0xff)) * 2) !=
               iVar6);
    }
    iVar6 = (int)*(short *)(iVar2 + ((int)*(short *)(iVar3 + iVar6 * 2) + (uVar9 & 0xff)) * 2);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_301068b8 @ 0x301068B8  (примерный размер ~204 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x301068B8
 * Данные: DAT_3010743c, DAT_3010750c, DAT_30107510, DAT_30107514, DAT_30107518, DAT_30107520, DAT_30107524
 * ---------------------------------------------------------------- */
int FUN_301068b8(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = DAT_3010743c;
  puVar1 = (undefined4 *)(DAT_3010743c + 0xc);
  uVar2 = 1;
  if (*(short *)(DAT_30107518 + param_1 * 2) != 0) {
    *(int *)(DAT_3010743c + 0x18) = param_1;
    *(undefined4 *)(iVar3 + 0x1c) = *puVar1;
  }
  if (*(short *)(DAT_30107514 + *(short *)(DAT_30107510 + param_1 * 2) * 2 + 2) != param_1) {
    do {
      param_1 = (int)*(short *)(DAT_30107520 + param_1 * 2);
      if (0xb3 < param_1) {
        uVar2 = *(uint *)(DAT_30107524 + (uVar2 & 0xff) * 4);
      }
    } while (*(short *)(DAT_30107514 +
                       ((int)*(short *)(DAT_30107510 + param_1 * 2) + (uVar2 & 0xff)) * 2) !=
             param_1);
  }
  iVar3 = (int)*(short *)(DAT_3010750c +
                         ((int)*(short *)(DAT_30107510 + param_1 * 2) + (uVar2 & 0xff)) * 2);
  if (iVar3 == 0xb3) {
    iVar3 = 0;
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * shellInterpC_delete_buffer @ 0x30106984  (примерный размер ~80 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 1
 * Вызывает: shellMemFree
 * Вызывают: FUN_3010bec0, FUN_3010c16c
 * Константы: 0x30106984
 * Данные: DAT_3010743c
 * ---------------------------------------------------------------- */
void shellInterpC_delete_buffer(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(DAT_3010743c + 8) == param_1) {
      *(undefined4 *)(DAT_3010743c + 8) = 0;
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      shellMemFree(*(undefined4 *)(param_1 + 4));
    }
    shellMemFree(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * shellInterpC_switch_to_buffer @ 0x301069D4  (примерный размер ~104 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 1
 * Вызывает: shellInterpC_load_buffer_state
 * Вызывают: shellInterpC_scan_buffer
 * Константы: 0x301069D4
 * Данные: DAT_3010743c
 * ---------------------------------------------------------------- */
void shellInterpC_switch_to_buffer(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = DAT_3010743c;
  if (*(int *)(DAT_3010743c + 8) != param_1) {
    if (*(int *)(DAT_3010743c + 8) != 0) {
      **(undefined1 **)(DAT_3010743c + 0xc) = *DAT_3010743c;
      iVar2 = *(int *)(puVar1 + 8);
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(puVar1 + 0xc);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(puVar1 + 0x10);
    }
    *(int *)(puVar1 + 8) = param_1;
    shellInterpC_load_buffer_state();
    *(undefined4 *)(puVar1 + 0x20) = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * shellInterpC_scan_buffer @ 0x30106A3C  (примерный размер ~156 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_30106540, shellInterpC_switch_to_buffer, shellMemMalloc
 * Вызывают: shellInterpC_scan_bytes, shellInterpC_scan_string
 * Константы: 0x30106A3C
 * Данные: DAT_30107528
 * ---------------------------------------------------------------- */
undefined4 * shellInterpC_scan_buffer(int param_1,uint param_2)

{
  undefined4 *puVar1;
  
  if (((1 < param_2) && (*(char *)(param_1 + param_2 + -2) == '\0')) &&
     (*(char *)(param_1 + param_2 + -1) == '\0')) {
    puVar1 = (undefined4 *)shellMemMalloc(0x28);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_30106540(DAT_30107528);
    }
    puVar1[3] = param_2 - 2;
    puVar1[1] = param_1;
    puVar1[2] = param_1;
    puVar1[5] = 0;
    *puVar1 = 0;
    puVar1[4] = param_2 - 2;
    puVar1[6] = 0;
    puVar1[7] = 1;
    puVar1[8] = 0;
    puVar1[9] = 0;
    shellInterpC_switch_to_buffer(puVar1);
    return puVar1;
  }
  return (undefined4 *)0x0;
}

/* ----------------------------------------------------------------
 * shellInterpC_scan_bytes @ 0x30106AD8  (примерный размер ~140 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_30106540, shellInterpC_scan_buffer, shellMemMalloc
 * Вызывают: shellInterpC_scan_string
 * Константы: 0x30106AD8
 * Данные: DAT_3010752c, DAT_30107530
 * ---------------------------------------------------------------- */
void shellInterpC_scan_bytes(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  iVar1 = shellMemMalloc(param_2 + 2);
  if (iVar1 == 0) {
    FUN_30106540(DAT_3010752c);
  }
  else {
    if (0 < param_2) {
      puVar3 = (undefined1 *)(iVar1 + -1);
      puVar4 = (undefined1 *)(param_1 + -1);
      iVar2 = param_2;
      do {
        puVar4 = puVar4 + 1;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + 1;
        *puVar3 = *puVar4;
      } while (iVar2 != 0);
    }
    *(undefined1 *)(iVar1 + param_2 + 1) = 0;
    *(undefined1 *)(iVar1 + param_2) = 0;
    iVar1 = shellInterpC_scan_buffer(iVar1,param_2 + 2);
    if (iVar1 != 0) goto LAB_30106b58;
  }
  iVar1 = FUN_30106540(DAT_30107530);
LAB_30106b58:
  *(undefined4 *)(iVar1 + 0x14) = 1;
  return;
}

/* ----------------------------------------------------------------
 * shellInterpC_scan_string @ 0x30106B64  (примерный размер ~44 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_30106540, shellInterpC_scan_buffer, shellInterpC_scan_bytes, shellMemMalloc
 * Вызывают: shellInterpClex
 * Константы: 0x30106B64, 0x30106B00, 0x30106B0C
 * Данные: DAT_3010752c, DAT_30107530
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x30106b00) */
/* WARNING: Removing unreachable block (ram,0x30106b0c) */

void shellInterpC_scan_string(char *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = 0;
  pcVar3 = param_1;
  if (*param_1 != '\0') {
    do {
      pcVar3 = pcVar3 + 1;
      iVar2 = iVar2 + 1;
    } while (*pcVar3 != '\0');
    shellInterpC_scan_bytes(param_1,iVar2);
    return;
  }
  puVar1 = (undefined1 *)shellMemMalloc(2);
  if (puVar1 == (undefined1 *)0x0) {
    FUN_30106540(DAT_3010752c);
  }
  else {
    puVar1[1] = 0;
    *puVar1 = 0;
    iVar2 = shellInterpC_scan_buffer(puVar1,2);
    if (iVar2 != 0) goto LAB_30106b58;
  }
  iVar2 = FUN_30106540(DAT_30107530);
LAB_30106b58:
  *(undefined4 *)(iVar2 + 0x14) = 1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30106b90 @ 0x30106B90  (примерный размер ~164 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: shellInterpClex
 * Константы: 0x30106B90
 * Данные: DAT_3010743c, DAT_30107440, DAT_30107444, DAT_30107534, DAT_30107538
 * ---------------------------------------------------------------- */
void FUN_30106b90(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_3010743c;
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(DAT_3010743c + 8);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(puVar1 + 0xc);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(puVar1 + 0x28);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(puVar1 + 0x14);
  *(undefined4 *)(param_1 + 4) = *DAT_30107444;
  *(undefined4 *)(param_1 + 8) = *DAT_30107534;
  *(undefined1 *)(param_1 + 0x34) = *puVar1;
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(puVar1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *DAT_30107538;
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(puVar1 + 0x20);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(puVar1 + 0x18);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(puVar1 + 0x1c);
  *(undefined4 *)(param_1 + 0xc) = *DAT_30107440;
  if ((param_2 != 0) && (*(int *)(param_1 + 100) == 0)) {
    *(undefined4 *)(param_1 + 100) = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30106c34 @ 0x30106C34  (примерный размер ~112 байт)
 * Модуль: shell | Вызывают: 14 | Вызывает: 1
 * Вызывает: vsnprintf
 * Вызывают: FUN_30106ce8, FUN_30106d24, FUN_30106e88, FUN_30108cb4, FUN_30108edc, FUN_30108f14, FUN_301092d0, FUN_3010a138, FUN_3010a8cc, FUN_3010aaf0
 *           ...
 * Константы: 0x30106C34
 * Данные: DAT_3010753c, DAT_30107540
 * ---------------------------------------------------------------- */
void FUN_30106c34(undefined4 param_1,int param_2,char *param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 uStack_4;
  
  *(undefined4 *)(param_2 + 0x70) = 1;
  *(undefined4 *)(param_2 + 0x74) = param_1;
  uStack_4 = param_4;
  iVar1 = vsnprintf((char *)(param_2 + 0x78),0x100,param_3,&uStack_4);
  if (0xff < iVar1) {
    iVar1 = 5;
    puVar3 = (undefined1 *)(param_2 + DAT_3010753c);
    puVar2 = DAT_30107540;
    do {
      iVar1 = iVar1 + -1;
      *puVar3 = *puVar2;
      puVar3 = puVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 != 0);
  }
  *(undefined1 *)(param_2 + 0x178) = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30106ca4 @ 0x30106CA4  (примерный размер ~68 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30106CA4
 * Данные: DAT_30107544
 * ---------------------------------------------------------------- */
longlong FUN_30106ca4(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *DAT_30107544;
  uVar1 = 0;
  piVar2 = DAT_30107544;
  while( true ) {
    if (iVar3 == 0) {
      return (ulonglong)uVar1 << 0x20;
    }
    if (piVar2[1] == param_1) break;
    piVar2 = piVar2 + 2;
    iVar3 = *piVar2;
    uVar1 = uVar1 + 1;
  }
  return CONCAT44(uVar1,*piVar2);
}

/* ----------------------------------------------------------------
 * FUN_30106ce8 @ 0x30106CE8  (примерный размер ~60 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_30106c34, __errno, shellMemRegMalloc
 * Вызывают: FUN_30106d24
 * Константы: 0x30106CE8
 * Данные: DAT_30107548
 * ---------------------------------------------------------------- */
int FUN_30106ce8(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = shellMemRegMalloc(param_1,param_2,param_3 + 0x38);
  if (iVar1 != 0) {
    return iVar1;
  }
  puVar2 = (undefined4 *)__errno();
  FUN_30106c34(*puVar2,param_3,*DAT_30107548);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30106d24 @ 0x30106D24  (примерный размер ~96 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_30106c34, FUN_30106ce8, __errno, strcpy, strlen
 * Константы: 0x30106D24
 * Данные: DAT_30107548
 * ---------------------------------------------------------------- */
char * FUN_30106d24(char *param_1,undefined4 param_2)

{
  size_t sVar1;
  char *__dest;
  undefined4 *puVar2;
  
  sVar1 = strlen(param_1);
  __dest = (char *)FUN_30106ce8(sVar1 + 1,3,param_2);
  if (__dest == (char *)0x0) {
    puVar2 = (undefined4 *)__errno();
    FUN_30106c34(*puVar2,param_2,*DAT_30107548);
    return (char *)0x0;
  }
  strcpy(__dest,param_1);
  return __dest;
}

/* ----------------------------------------------------------------
 * FUN_30106d84 @ 0x30106D84  (примерный размер ~260 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 6
 * Вызывает: __errno, shellInternalSymbolGet, shellMemFree, shellMemMalloc, sprintf, strlen
 * Вызывают: FUN_30106e88
 * Константы: 0xFFFFFFFF, 0x30106D84
 * Данные: DAT_3010754c, DAT_30107550, DAT_30107554
 * ---------------------------------------------------------------- */
undefined4 FUN_30106d84(char *param_1,char *param_2,int param_3,int *param_4)

{
  size_t sVar1;
  size_t sVar2;
  char *__s;
  int iVar3;
  undefined4 *puVar4;
  int local_20;
  undefined4 local_1c;
  
  local_20 = 5;
  __s = param_1;
  if (param_2 != (char *)0x0) {
    sVar1 = strlen(param_2);
    sVar2 = strlen(param_1);
    __s = (char *)shellMemMalloc(sVar2 + sVar1 + 3);
    if (__s == (char *)0x0) {
      return 0xffffffff;
    }
    sprintf(__s,DAT_3010754c,param_2,param_1);
  }
  iVar3 = shellInternalSymbolGet(*DAT_30107550,__s,&local_1c,&local_20);
  if (param_2 != (char *)0x0) {
    shellMemFree(__s);
  }
  if (iVar3 == 0) {
    if (param_4 != (int *)0x0) {
      *param_4 = local_20;
    }
    if (param_3 == 1) {
      return local_1c;
    }
    if (param_3 == 2) {
      if (local_20 == 2) {
        return local_1c;
      }
      if (local_20 == 4) {
        return local_1c;
      }
    }
    if ((param_3 == 3) && (local_20 == 3)) {
      return local_1c;
    }
    puVar4 = (undefined4 *)__errno();
    *puVar4 = DAT_30107554;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_30106e88 @ 0x30106E88  (примерный размер ~328 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_30106c34, FUN_30106d84, __errno, bzero, shellInternalTaskNameMatch
 * Константы: 0xFFFFFFFF, 0x30106E88
 * Данные: DAT_30107558, DAT_3010755c, DAT_30107560
 * ---------------------------------------------------------------- */
undefined4
FUN_30106e88(int param_1,int param_2,void *param_3,int *param_4,undefined4 *param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_24;
  
  bzero(param_3,0x44);
  *(undefined4 *)((int)param_3 + 0x34) = 0xffffffff;
  iVar1 = FUN_30106d84(param_2,param_1,1,param_4);
  *(int *)((int)param_3 + 0x24) = iVar1;
  if (iVar1 == -1) {
    local_24 = -1;
    iVar1 = shellInternalTaskNameMatch(param_2,&local_24);
    *param_5 = 0;
    if (1 < iVar1) {
      puVar2 = (undefined4 *)__errno();
      FUN_30106c34(*puVar2,param_6,DAT_30107558,param_2);
      return 0xffffffff;
    }
    if ((iVar1 != 1) || (local_24 == -1)) {
      if (param_1 == 0) {
        puVar2 = (undefined4 *)__errno();
        uVar3 = *puVar2;
        uVar4 = DAT_30107560;
      }
      else {
        puVar2 = (undefined4 *)__errno();
        uVar3 = *puVar2;
        uVar4 = DAT_3010755c;
        param_2 = param_1;
      }
      FUN_30106c34(uVar3,param_6,uVar4,param_2);
      return 0xffffffff;
    }
    *(int *)((int)param_3 + 0x24) = local_24;
    *(undefined4 *)((int)param_3 + 0x30) = 4;
    *(undefined4 *)((int)param_3 + 0x34) = 0;
    *(undefined4 *)((int)param_3 + 0x2c) = 2;
  }
  else {
    *(undefined4 *)((int)param_3 + 0x34) = 0;
    *(undefined4 *)((int)param_3 + 0x30) = 4;
    if (*param_4 == 2) {
      *(int *)((int)param_3 + 0x24) = iVar1;
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    *(undefined4 *)((int)param_3 + 0x2c) = uVar4;
    *param_5 = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30106fd0 @ 0x30106FD0  (примерный размер ~200 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30106540
 * Вызывают: FUN_30107170
 * Константы: 0x30106FD0
 * Данные: DAT_3010743c, DAT_30107440, DAT_30107564
 * ---------------------------------------------------------------- */
void FUN_30106fd0(undefined1 param_1,int param_2)

{
  undefined1 *puVar1;
  int extraout_r1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  puVar1 = DAT_3010743c;
  puVar6 = *(undefined1 **)(DAT_3010743c + 0xc);
  *puVar6 = *DAT_3010743c;
  iVar4 = *(int *)(puVar1 + 8);
  puVar2 = *(undefined1 **)(iVar4 + 4);
  if (puVar6 < puVar2 + 2) {
    puVar5 = puVar2 + *(int *)(puVar1 + 0x10) + 2;
    puVar3 = puVar2 + *(int *)(iVar4 + 0xc) + 2;
    if (puVar2 < puVar5) {
      do {
        puVar5 = puVar5 + -1;
        puVar3 = puVar3 + -1;
        *puVar3 = *puVar5;
      } while (*(undefined1 **)(iVar4 + 4) < puVar5);
    }
    puVar6 = puVar6 + ((int)puVar3 - (int)puVar5);
    *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(iVar4 + 0xc);
    param_2 = param_2 + ((int)puVar3 - (int)puVar5);
    if (puVar6 < (undefined1 *)(*(int *)(iVar4 + 4) + 2)) {
      param_1 = FUN_30106540(DAT_30107564);
      param_2 = extraout_r1;
    }
  }
  puVar6 = puVar6 + -1;
  *puVar6 = param_1;
  *DAT_30107440 = param_2;
  *puVar1 = *puVar6;
  *(undefined1 **)(puVar1 + 0xc) = puVar6;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30107098 @ 0x30107098  (примерный размер ~216 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30106540, FUN_3010661c
 * Вызывают: FUN_30107170
 * Константы: 0x30107098, 0xFFFFFFFF
 * Данные: DAT_3010743c, DAT_30107440, DAT_30107568
 * ---------------------------------------------------------------- */
uint FUN_30107098(void)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  
  pcVar3 = DAT_3010743c;
  cVar1 = *DAT_3010743c;
  **(char **)(DAT_3010743c + 0xc) = cVar1;
  puVar4 = DAT_30107440;
  if (cVar1 == '\0') {
    puVar6 = *(undefined1 **)(pcVar3 + 0xc);
    if (puVar6 < (undefined1 *)(*(int *)(*(int *)(pcVar3 + 8) + 4) + *(int *)(pcVar3 + 0x10))) {
      *puVar6 = 0;
    }
    else {
      *DAT_30107440 = puVar6;
      *(undefined1 **)(pcVar3 + 0xc) = puVar6 + 1;
      iVar5 = FUN_3010661c();
      if (iVar5 == 0) {
        *(undefined4 *)(pcVar3 + 0xc) = *puVar4;
      }
      else {
        if (iVar5 == 1) {
          *(undefined4 *)(pcVar3 + 0xc) = *puVar4;
          return 0xffffffff;
        }
        if (iVar5 == 2) {
          FUN_30106540(DAT_30107568);
        }
      }
    }
  }
  bVar2 = **(byte **)(pcVar3 + 0xc);
  **(byte **)(pcVar3 + 0xc) = 0;
  iVar5 = *(int *)(pcVar3 + 0xc);
  *(char **)(pcVar3 + 0xc) = (char *)(iVar5 + 1);
  *pcVar3 = *(char *)(iVar5 + 1);
  return (uint)bVar2;
}

/* ----------------------------------------------------------------
 * FUN_30107170 @ 0x30107170  (примерный размер ~148 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_30106fd0, FUN_30107098, strlen
 * Константы: 0x30107170
 * Данные: DAT_30107440
 * ---------------------------------------------------------------- */
void FUN_30107170(char *param_1)

{
  char cVar1;
  size_t sVar2;
  char cVar3;
  char cVar4;
  
  cVar1 = FUN_30107098();
  sVar2 = strlen(param_1);
  cVar3 = '\0';
  if (sVar2 == 0) {
    if (cVar1 == -1) {
      return;
    }
    do {
      if (cVar1 == '\n') break;
      cVar1 = FUN_30107098();
    } while (cVar1 != -1);
    if (cVar1 == -1) {
      return;
    }
    FUN_30106fd0(cVar1,*DAT_30107440);
  }
  else {
    while (cVar4 = cVar1, cVar4 != -1) {
      if ((cVar3 == *param_1) && (param_1[1] == cVar4)) {
        return;
      }
      cVar1 = FUN_30107098();
      cVar3 = cVar4;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * shellInterpClex @ 0x30107204  (примерный размер ~5784 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 11
 * Вызывает: FUN_30106540, FUN_30106b90, FUN_30106c34, __stdin, __stdout, semGive, semMCreate, semTake, shellInterpC_create_buffer, shellInterpC_load_buffer_state, shellInterpC_scan_string
 * Вызывают: shellInterpCparse
 * Константы: 0x30107204, 0xFFFFFFFF, 0x301074FC
 * Данные: DAT_3010743c, DAT_30107440, DAT_30107444, DAT_3010750c, DAT_30107510, DAT_30107514, DAT_30107518, DAT_3010751c
 * ---------------------------------------------------------------- */
undefined4 shellInterpClex(undefined4 param_1,undefined4 *param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  int iVar11;
  
  pbVar1 = DAT_3010743c;
  if (*(int *)(DAT_3010743c + 4) == 0) {
    iVar5 = semMCreate(0);
    *(int *)(pbVar1 + 4) = iVar5;
    if (iVar5 == 0) {
      FUN_30106c34(DAT_30107570,param_2,DAT_3010756c);
    }
  }
  if ((*(int *)(pbVar1 + 4) != 0) && (iVar5 = semTake(*(int *)(pbVar1 + 4),0xffffffff), iVar5 != 0))
  {
    FUN_30106c34(DAT_30107570,param_2,DAT_3010756c);
  }
  *(undefined4 *)(pbVar1 + 8) = param_2[4];
  *(undefined4 *)(pbVar1 + 0xc) = param_2[5];
  *(undefined4 *)(pbVar1 + 0x28) = param_2[9];
  *(undefined4 *)(pbVar1 + 0x14) = param_2[10];
  *DAT_30107444 = param_2[1];
  *DAT_30107534 = param_2[2];
  *pbVar1 = *(byte *)(param_2 + 0xd);
  *(undefined4 *)(pbVar1 + 0x10) = param_2[8];
  *DAT_30107538 = param_2[7];
  *(undefined4 *)(pbVar1 + 0x20) = param_2[0xb];
  *(undefined4 *)(pbVar1 + 0x18) = param_2[0xc];
  *(undefined4 *)(pbVar1 + 0x1c) = param_2[6];
  puVar2 = DAT_30107440;
  *DAT_30107440 = param_2[3];
  if (param_2[0x17] != 0) {
    shellInterpC_scan_string(*param_2);
    param_2[0x17] = 0;
  }
  if (param_2[0x18] != 0) {
    pbVar1[0x14] = 3;
    pbVar1[0x15] = 0;
    pbVar1[0x16] = 0;
    pbVar1[0x17] = 0;
    param_2[0x18] = 0;
  }
  if (*(int *)(pbVar1 + 0x28) != 0) {
    pbVar1[0x28] = 0;
    pbVar1[0x29] = 0;
    pbVar1[0x2a] = 0;
    pbVar1[0x2b] = 0;
    if (*(int *)(pbVar1 + 0x14) == 0) {
      *(uint *)(pbVar1 + 0x14) = (uint)(*(int *)(pbVar1 + 0x14) == 0);
    }
    if (*DAT_30107444 == 0) {
      piVar6 = (int *)__stdin();
      *DAT_30107444 = *piVar6;
    }
    if (*DAT_30107534 == 0) {
      piVar6 = (int *)__stdout();
      *DAT_30107534 = *piVar6;
    }
    if (*(int *)(pbVar1 + 8) == 0) {
      uVar7 = shellInterpC_create_buffer(*DAT_30107444,0x4000);
      *(undefined4 *)(pbVar1 + 8) = uVar7;
    }
    shellInterpC_load_buffer_state();
  }
  pbVar9 = *(byte **)(pbVar1 + 0xc);
  *pbVar9 = *pbVar1;
  iVar4 = DAT_30107518;
  iVar3 = DAT_30107514;
  iVar5 = DAT_30107510;
  iVar11 = *(int *)(pbVar1 + 0x14);
  pbVar10 = pbVar9;
  do {
    uVar8 = *(uint *)(DAT_3010751c + (uint)*pbVar10 * 4);
    if (*(short *)(iVar4 + iVar11 * 2) != 0) {
      *(int *)(pbVar1 + 0x18) = iVar11;
      *(byte **)(pbVar1 + 0x1c) = pbVar10;
    }
    if (*(short *)(iVar3 + ((int)*(short *)(iVar5 + iVar11 * 2) + (uVar8 & 0xff)) * 2) != iVar11) {
      do {
        iVar11 = (int)*(short *)(DAT_30107520 + iVar11 * 2);
        if (0xb3 < iVar11) {
          uVar8 = *(uint *)(DAT_30107524 + (uVar8 & 0xff) * 4);
        }
      } while (*(short *)(iVar3 + ((int)*(short *)(iVar5 + iVar11 * 2) + (uVar8 & 0xff)) * 2) !=
               iVar11);
    }
    iVar11 = (int)*(short *)(DAT_3010750c +
                            ((int)*(short *)(iVar5 + iVar11 * 2) + (uVar8 & 0xff)) * 2);
    pbVar10 = pbVar10 + 1;
  } while (iVar11 != 0xb3);
  pbVar10 = *(byte **)(pbVar1 + 0x1c);
  uVar8 = (uint)*(short *)(iVar4 + *(int *)(pbVar1 + 0x18) * 2);
  *puVar2 = pbVar9;
  *DAT_30107538 = (int)pbVar10 - (int)pbVar9;
  *pbVar1 = *pbVar10;
  *pbVar10 = 0;
  *(byte **)(pbVar1 + 0xc) = pbVar10;
  if (0x4d < uVar8) {
    FUN_30106540(DAT_30108be0);
    param_2[0x19] = 0;
    *pbVar10 = *pbVar1;
    *(byte **)(pbVar1 + 0xc) = pbVar9;
    *puVar2 = pbVar9;
    *DAT_30108be4 = 0;
    *pbVar1 = *pbVar9;
    *pbVar9 = 0;
    *(byte **)(pbVar1 + 0xc) = pbVar9;
    FUN_30106b90(param_2,0);
    semGive(*(undefined4 *)(pbVar1 + 4));
    return 0x29;
  }
                    /* WARNING: Could not recover jumptable at 0x301074fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar7 = (**(code **)(DAT_30107574 + uVar8 * 4))();
  return uVar7;
}

/* ----------------------------------------------------------------
 * FUN_3010889c @ 0x3010889C  (примерный размер ~32 байт)
 * Модуль: shell | Вызывают: 11 | Вызывает: 0
 * Вызывают: FUN_301088bc, FUN_301088fc, FUN_3010891c, FUN_30108cb4, FUN_30108e10, FUN_30108f14, FUN_301090ac, FUN_301092d0, FUN_3010a138, FUN_3010a494
 *           ...
 * Константы: 0x3010889C
 * ---------------------------------------------------------------- */
undefined4 FUN_3010889c(int param_1)

{
  if (0 < *(int *)(param_1 + 0x38)) {
    return 8;
  }
  return *(undefined4 *)(param_1 + 0x30);
}

/* ----------------------------------------------------------------
 * FUN_301088bc @ 0x301088BC  (примерный размер ~64 байт)
 * Модуль: shell | Вызывают: 6 | Вызывает: 1
 * Вызывает: FUN_3010889c
 * Вызывают: FUN_3010891c, FUN_3010a138, FUN_3010a8cc, FUN_3010ac04, FUN_3010acd0, FUN_3010ae00
 * Константы: 0x301088BC
 * ---------------------------------------------------------------- */
int FUN_301088bc(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_3010889c();
  bVar2 = iVar1 == 8;
  if ((((!bVar2) && (bVar2 = iVar1 == 1, !bVar2)) && (bVar2 = iVar1 == 2, !bVar2)) &&
     (((bVar2 = iVar1 == 4, !bVar2 && (bVar2 = iVar1 == 5, !bVar2)) && (bVar2 = iVar1 == 7, !bVar2))
     )) {
    iVar1 = 0;
  }
  if (bVar2) {
    iVar1 = 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_301088fc @ 0x301088FC  (примерный размер ~32 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 1
 * Вызывает: FUN_3010889c
 * Вызывают: FUN_3010891c, FUN_301092d0, FUN_3010a8cc
 * Константы: 0x301088FC
 * ---------------------------------------------------------------- */
int FUN_301088fc(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_3010889c();
  bVar2 = iVar1 == 3;
  if ((!bVar2) && (bVar2 = iVar1 == 6, !bVar2)) {
    iVar1 = 0;
  }
  if (bVar2) {
    iVar1 = 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3010891c @ 0x3010891C  (примерный размер ~512 байт)
 * Модуль: shell | Вызывают: 11 | Вызывает: 10
 * Вызывает: FUN_3010889c, FUN_301088bc, FUN_301088fc, __fixdfdi, __fixsfsi, __floatdidf, __floatsisf, bzero, shellPrint, shellPrintErr
 * Вызывают: FUN_30108cb4, FUN_30108f14, FUN_301090ac, FUN_301092d0, FUN_3010a138, FUN_3010a3ec, FUN_3010a494, FUN_3010a8cc, FUN_3010ac04, FUN_3010acd0
 *           ...
 * Константы: 0x3010891C, 0xFFFFFFFF
 * Данные: DAT_30108be8, DAT_30108bec, DAT_30108bf0, DAT_30108bf4
 * ---------------------------------------------------------------- */
void FUN_3010891c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 auStack_5c [48];
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  bzero(auStack_5c,0x44);
  local_28 = 0xffffffff;
  if (*(int *)(param_1 + 0x2c) != 2) {
    shellPrintErr(0,DAT_30108be8);
    return;
  }
  iVar1 = FUN_3010889c(param_1);
  if ((iVar1 == 0) || (param_2 == 0)) {
    shellPrint(0,*DAT_30108bec);
    return;
  }
  if (iVar1 == 8) {
    if (param_2 == 8) {
      return;
    }
    if (param_2 != 8) {
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x38) = 0;
      *(undefined4 *)(param_1 + 0x30) = 4;
    }
  }
  else if (param_2 == 8) {
    FUN_3010891c(param_1,4);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x38) = 1;
    *(int *)(param_1 + 0x30) = iVar1;
    *(undefined4 *)(param_1 + 0x34) = 1;
    return;
  }
  local_24 = 0;
  local_2c = param_2;
  iVar1 = FUN_3010889c(param_1);
  iVar2 = FUN_301088fc(param_1);
  if ((iVar2 == 0) || (iVar2 = FUN_301088bc(auStack_5c), iVar2 == 0)) {
    iVar2 = FUN_301088bc(param_1);
    if ((iVar2 == 0) || (iVar2 = FUN_301088fc(auStack_5c), iVar2 == 0)) goto LAB_30108ae0;
    if (iVar1 < 4) {
      FUN_3010891c(param_1,2);
      uVar3 = __floatsisf((int)*(short *)(param_1 + 0x24));
      *(undefined4 *)(param_1 + 0x24) = uVar3;
      uVar3 = 3;
    }
    else {
      FUN_3010891c(param_1,7);
      uVar5 = __floatdidf(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28));
      *(undefined8 *)(param_1 + 0x24) = uVar5;
      uVar3 = 6;
    }
  }
  else if (iVar1 == 3) {
    uVar3 = __fixsfsi();
    *(undefined4 *)(param_1 + 0x24) = uVar3;
    uVar3 = 4;
  }
  else {
    uVar5 = __fixdfdi(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28));
    *(undefined8 *)(param_1 + 0x24) = uVar5;
    uVar3 = 7;
  }
  *(undefined4 *)(param_1 + 0x30) = uVar3;
LAB_30108ae0:
  iVar2 = FUN_3010889c(param_1);
  iVar4 = FUN_301088bc(param_1);
  iVar1 = DAT_30108bf0;
  if (iVar4 == 0) {
    iVar1 = DAT_30108bf4;
  }
  (**(code **)(iVar1 + iVar2 * 4))(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30108b1c @ 0x30108B1C  (примерный размер ~68 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30108cb4, FUN_301090ac
 * Константы: 0x30108B1C
 * Данные: DAT_30108bf8
 * ---------------------------------------------------------------- */
undefined8 FUN_30108b1c(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *DAT_30108bf8;
  iVar1 = 0;
  piVar2 = DAT_30108bf8;
  while( true ) {
    if (iVar3 == 0) {
      return CONCAT44(iVar1,4);
    }
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar3 = *piVar2;
    iVar1 = iVar1 + 1;
  }
  return CONCAT44(iVar1,piVar2[1]);
}

/* ----------------------------------------------------------------
 * FUN_30108b60 @ 0x30108B60  (примерный размер ~340 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30108e10
 * Константы: 0x30108B60, 0x30108B80, 0xFFFFFFFF
 * Данные: DAT_30108bfc
 * ---------------------------------------------------------------- */
undefined4 FUN_30108b60(uint param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 < 9) {
                    /* WARNING: Could not recover jumptable at 0x30108b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_30108bfc + param_1 * 4))();
    return uVar1;
  }
  *(undefined4 *)(param_3 + 0x24) = *param_2;
  *(undefined4 *)(param_3 + 0x30) = 4;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_30108cb4 @ 0x30108CB4  (примерный размер ~348 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 10
 * Вызывает: FUN_30106c34, FUN_3010889c, FUN_3010891c, FUN_30108b1c, __errno, shellErrnoGet, shellErrnoSet, shellInOutRedirectRestore, shellInOutRedirectSet, shellInternalFunctionCall
 * Вызывают: FUN_30108e10
 * Константы: 0x30108CB4, 0xFFFFFFFF
 * Данные: DAT_30109230
 * ---------------------------------------------------------------- */
undefined4 FUN_30108cb4(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 auStack_5c [9];
  undefined1 auStack_38 [12];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar6 = param_1[3];
  if (iVar6 != 0) {
    uVar1 = FUN_30108b1c(param_1[4]);
    iVar4 = 0x11;
    puVar3 = auStack_5c;
    puVar5 = param_1;
    do {
      iVar4 = iVar4 + -1;
      *puVar3 = *puVar5;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar4 != 0);
    local_2c = param_1[4];
    local_28 = param_1[5];
    local_24 = param_1[6];
    local_20 = param_1[7];
    local_1c = param_1[8];
    auStack_5c[2] = 0;
    auStack_5c[3] = 0;
    shellInOutRedirectSet(0,*(undefined4 *)(param_2 + 0x6c));
    uVar2 = shellErrnoGet(0);
    puVar3 = (undefined4 *)__errno();
    *puVar3 = uVar2;
    iVar6 = shellInternalFunctionCall(auStack_38,uVar1,param_1[2],iVar6);
    shellInOutRedirectRestore(0,*(undefined4 *)(param_2 + 0x6c));
    if (iVar6 != 0) {
      puVar3 = (undefined4 *)__errno();
      FUN_30106c34(*puVar3,param_2,DAT_30109230,param_1[2]);
      return 0xffffffff;
    }
    puVar3 = (undefined4 *)__errno();
    shellErrnoSet(0,*puVar3);
    uVar1 = FUN_3010889c(param_1);
    FUN_3010891c(auStack_5c,uVar1);
    local_2c = param_1[0xc];
    local_28 = param_1[0xd];
    iVar6 = 0x11;
    local_24 = param_1[0xe];
    local_20 = param_1[0xf];
    local_1c = param_1[0x10];
    puVar3 = auStack_5c;
    do {
      iVar6 = iVar6 + -1;
      *param_1 = *puVar3;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar6 != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30108e10 @ 0x30108E10  (примерный размер ~204 байт)
 * Модуль: shell | Вызывают: 10 | Вызывает: 5
 * Вызывает: FUN_3010889c, FUN_30108b60, FUN_30108cb4, bzero, shellPrintErr
 * Вызывают: FUN_301090ac, FUN_301092d0, FUN_3010a138, FUN_3010a3ec, FUN_3010a494, FUN_3010a804, FUN_3010a8cc, FUN_3010aaf0, FUN_3010acd0, FUN_3010ae00
 * Константы: 0xFFFFFFFF, 0x30108E10
 * Данные: DAT_30109234
 * ---------------------------------------------------------------- */
undefined4 FUN_30108e10(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  bzero(param_1,0x44);
  param_1[0xd] = 0xffffffff;
  iVar1 = FUN_30108cb4(param_2,param_3);
  if (iVar1 == 0) {
    if (param_2[0xb] == 2) {
      iVar1 = 0x11;
      do {
        iVar1 = iVar1 + -1;
        *param_1 = *param_2;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      } while (iVar1 != 0);
    }
    else {
      uVar2 = FUN_3010889c(param_2);
      param_1[0xc] = param_2[0xc];
      param_1[0xd] = param_2[0xd];
      param_1[0xe] = param_2[0xe];
      param_1[0xf] = param_2[0xf];
      param_1[0x10] = param_2[0x10];
      param_1[0xb] = 2;
      iVar1 = FUN_30108b60(uVar2,param_2[9],param_1);
      if (iVar1 != 0) {
        shellPrintErr(0,DAT_30109234);
      }
    }
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_30108edc @ 0x30108EDC  (примерный размер ~56 байт)
 * Модуль: shell | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_30106c34
 * Вызывают: FUN_3010a494, FUN_3010a804
 * Константы: 0x30108EDC, 0xFFFFFFFF
 * Данные: DAT_30109238, DAT_3010923c
 * ---------------------------------------------------------------- */
undefined4 FUN_30108edc(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(int *)(param_1 + 0x2c) != 1) {
    FUN_30106c34(DAT_3010923c,param_3,DAT_30109238,param_2);
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30108f14 @ 0x30108F14  (примерный размер ~408 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_30106c34, FUN_3010889c, FUN_3010891c
 * Константы: 0x30108F14
 * Данные: DAT_3010923c, DAT_30109240
 * ---------------------------------------------------------------- */
void FUN_30108f14(undefined4 *param_1,int *param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int aiStack_a0 [4];
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  undefined1 auStack_58 [48];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  iVar2 = 0x11;
  piVar3 = aiStack_a0;
  do {
    iVar2 = iVar2 + -1;
    *piVar3 = *param_3;
    piVar3 = piVar3 + 1;
    param_3 = param_3 + 1;
  } while (iVar2 != 0);
  if (aiStack_a0[2] == 0) {
    if (param_2[4] != 0) {
      FUN_30106c34(DAT_3010923c,param_4,DAT_30109240);
      return;
    }
LAB_30108ff4:
    local_28 = *param_2;
    if (local_28 != 0) {
      if (local_74 == 2) {
        local_24 = param_2[1];
        local_20 = param_2[2];
        local_1c = param_2[3];
        local_18 = param_2[4];
        uVar1 = FUN_3010889c(auStack_58);
        FUN_3010891c(aiStack_a0,uVar1);
      }
      goto LAB_30109044;
    }
  }
  else {
    if (param_2[4] != 0) {
      param_2[3] = 1;
      local_90 = *param_2;
      local_8c = param_2[1];
      local_88 = param_2[2];
      local_84 = param_2[3];
      local_80 = param_2[4];
      if (local_64 == 0) {
        local_70 = *param_2;
        local_6c = param_2[1];
        local_68 = param_2[2];
        local_64 = param_2[3];
        local_60 = param_2[4];
      }
      iVar2 = 0x1c;
      goto LAB_30109078;
    }
    if (aiStack_a0[2] == 0) goto LAB_30108ff4;
LAB_30109044:
    if (*param_2 != 0) {
      local_70 = *param_2;
      local_6c = param_2[1];
      local_68 = param_2[2];
      local_64 = param_2[3];
      local_60 = param_2[4];
    }
  }
  iVar2 = 0x3c;
LAB_30109078:
  *(undefined4 *)((int)aiStack_a0 + iVar2) = 1;
  iVar2 = 0x11;
  piVar3 = aiStack_a0;
  do {
    iVar2 = iVar2 + -1;
    *param_1 = *piVar3;
    param_1 = param_1 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 != 0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_301090ac @ 0x301090AC  (примерный размер ~368 байт)
 * Модуль: shell | Вызывают: 0 | Вызывает: 10
 * Вызывает: FUN_3010889c, FUN_3010891c, FUN_30108b1c, FUN_30108e10, __errno, shellInternalSymbolDisplay, shellInternalValueDisplay, shellOutputLock, shellOutputUnlock, shellPrint
 * Константы: 0x301090AC
 * Данные: DAT_30109244, DAT_30109248, DAT_3010924c, DAT_30109250, DAT_30109254, DAT_30109258, DAT_3010925c
 * ---------------------------------------------------------------- */
void FUN_301090ac(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined1 auStack_54 [36];
  undefined4 local_30;
  undefined4 local_2c;
  int local_20;
  int local_18;
  
  iVar1 = FUN_30108e10(auStack_54,param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_3010889c(auStack_54);
    if (*(int *)(param_2 + 0x44) == 0) {
      shellOutputLock(0);
      if (*(int *)(param_1 + 0x2c) == 1) {
        puVar2 = (undefined4 *)__errno();
        uVar3 = *puVar2;
        shellInternalSymbolDisplay
                  (*DAT_30109244,*(undefined4 *)(param_1 + 0x24),DAT_30109248,DAT_3010924c);
        puVar2 = (undefined4 *)__errno();
        *puVar2 = uVar3;
        shellPrint(0,DAT_30109250,*(undefined4 *)(param_1 + 0x24));
        if ((0 < iVar1) && (iVar1 < 9)) {
          shellPrint(0,DAT_30109254);
        }
      }
      if (iVar1 - 1U < 8) {
        if (local_18 == 0) {
          FUN_3010891c(auStack_54,4);
        }
        shellPrint(0,DAT_30109258);
        uVar3 = FUN_30108b1c(iVar1);
        shellInternalValueDisplay(*DAT_30109244,&local_30,0 < local_20,uVar3);
      }
      shellPrint(0,DAT_3010925c);
      shellOutputUnlock(0);
    }
    else {
      if (*(int *)(param_1 + 0x2c) == 1) {
        uVar3 = *(undefined4 *)(param_1 + 0x24);
      }
      else {
        uVar3 = 0;
      }
      *(undefined4 *)(param_2 + 0x48) = uVar3;
      uVar3 = FUN_30108b1c(iVar1);
      *(undefined4 *)(param_2 + 0x4c) = uVar3;
      *(undefined4 *)(param_2 + 0x50) = local_30;
      *(undefined4 *)(param_2 + 0x54) = local_2c;
      if (local_20 == -1) {
        *(undefined4 *)(param_2 + 0x58) = 0;
      }
      else {
        *(int *)(param_2 + 0x58) = local_20;
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3010921c @ 0x3010921C  (примерный размер ~180 байт)
 * Модуль: shell | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_301092d0, FUN_3010aa90, FUN_3010acd0
 * Константы: 0x3010921C, 0x3010922C
 * Данные: DAT_30109260
 * ---------------------------------------------------------------- */
undefined4 FUN_3010921c(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 9) {
                    /* WARNING: Could not recover jumptable at 0x3010922c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_30109260 + param_1 * 4))();
    return uVar1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_301092d0 @ 0x301092D0  (примерный размер ~3688 байт)
 * Модуль: shell | Вызывают: 1 | Вызывает: 10
 * Вызывает: FUN_30106c34, FUN_3010889c, FUN_301088fc, FUN_3010891c, FUN_30108e10, FUN_3010921c, __floatsidf, __mul64, _d_fne, bzero
 * Вызывают: FUN_3010a3ec
 * Константы: 0x301092D0, 0xFFFFFFFF, 0x30109670
 * Данные: DAT_30109674, DAT_30109678, DAT_3010967c
 * ---------------------------------------------------------------- */
void FUN_301092d0(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *__s;
  undefined4 *puVar4;
  int iVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int local_148;
  undefined1 *local_13c;
  int local_138;
  int local_134;
  undefined4 local_130;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  undefined4 local_110;
  undefined1 auStack_108 [36];
  int local_e4;
  int local_e0;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  undefined4 local_c8;
  undefined1 auStack_c0 [36];
  int local_9c;
  int local_98;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  undefined4 auStack_78 [9];
  undefined8 local_54;
  undefined4 local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  
  local_13c = (undefined1 *)0x0;
  iVar5 = 0;
  puVar4 = (undefined4 *)0x0;
  uVar8 = 0;
  local_138 = 0;
  iVar1 = FUN_30108e10(auStack_108,param_2,param_5);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = FUN_30108e10(auStack_c0,param_4,param_5);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = FUN_3010889c(auStack_108);
  iVar2 = FUN_3010889c(auStack_c0);
  if ((((((param_3 != 0x2b) && (param_3 != 0x2d)) && ((iVar1 == 8 || (iVar2 == 8)))) ||
       ((iVar1 == 8 && (iVar3 = FUN_301088fc(auStack_c0), iVar3 != 0)))) ||
      ((iVar3 = FUN_301088fc(auStack_108), iVar3 != 0 && (iVar2 == 8)))) ||
     (((iVar1 == 8 && (iVar2 == 8)) && ((local_d8 != local_90 || (local_d0 != local_88)))))) {
    FUN_30106c34(DAT_30109678,param_5,DAT_30109674);
    return;
  }
  if ((param_3 == 0x2b) || (param_3 == 0x2d)) {
    local_120 = local_d8;
    local_11c = local_d4;
    local_118 = local_d0;
    local_114 = local_cc;
    local_110 = local_c8;
    if ((iVar1 == 8) && (local_cc != 0)) {
      if (iVar2 != 8) {
        local_13c = auStack_c0;
        if (local_d0 < 2) {
          local_138 = FUN_3010921c(local_d8);
        }
        else {
          local_138 = FUN_3010921c(8);
        }
        goto LAB_30109520;
      }
    }
    else if (iVar2 != 8) goto LAB_30109520;
    if ((local_84 != 0) && (iVar1 != 8)) {
      local_13c = auStack_108;
      if (1 < local_88) {
        local_90 = 8;
      }
      local_138 = FUN_3010921c(local_90);
      local_120 = local_d8;
      local_11c = local_d4;
      local_118 = local_d0;
      local_114 = local_cc;
      local_110 = local_c8;
    }
  }
LAB_30109520:
  local_148 = 7;
  iVar3 = FUN_301088fc(auStack_c0);
  if ((iVar3 == 0) && (iVar3 = FUN_301088fc(auStack_108), iVar3 == 0)) {
    local_134 = iVar1;
    if (iVar1 < iVar2) {
      local_134 = iVar2;
    }
  }
  else {
    local_148 = 6;
    if ((iVar1 == 6) || (iVar2 == 6)) {
      local_134 = 6;
    }
    else {
      local_134 = 3;
    }
  }
  FUN_3010891c(auStack_108,local_148);
  FUN_3010891c(auStack_c0,local_148);
  if (local_13c != (undefined1 *)0x0) {
    if (*(int *)(local_13c + 0x34) == 1) {
      uVar7 = __mul64(*(undefined4 *)(local_13c + 0x24),*(undefined4 *)(local_13c + 0x28),local_138,
                      local_138 >> 0x1f);
    }
    else {
      uVar7 = __mul64(*(undefined4 *)(local_13c + 0x24),*(undefined4 *)(local_13c + 0x28),local_138,
                      local_138 >> 0x1f);
    }
    *(undefined8 *)(local_13c + 0x24) = uVar7;
  }
  __s = auStack_78;
  bzero(__s,0x44);
  local_44 = 0xffffffff;
  if (param_3 == 0x7c) {
    local_44 = 1;
    if (local_148 == 7) {
      if ((local_d4 == 1) && (local_8c == 1)) {
        bVar6 = local_e0 + local_e4 == 0;
        if ((bVar6) && (bVar6 = local_98 + local_9c == 0, bVar6)) {
          __s = (undefined4 *)0x0;
        }
        if (!bVar6) {
          __s = (undefined4 *)0x1;
        }
        iVar5 = (int)__s >> 0x1f;
        local_44 = 1;
        puVar4 = __s;
        uVar8 = 0;
      }
      else {
        bVar6 = local_e0 + local_e4 == 0;
        if ((bVar6) && (bVar6 = local_98 + local_9c == 0, bVar6)) {
          __s = (undefined4 *)0x0;
        }
        if (!bVar6) {
          __s = (undefined4 *)0x1;
        }
        iVar5 = (int)__s >> 0x1f;
        puVar4 = __s;
      }
    }
    else {
      iVar3 = _d_fne(local_e4,local_e0,0);
      bVar6 = iVar3 == 0;
      if (bVar6) {
        iVar3 = _d_fne(local_9c,local_98,0);
        bVar6 = iVar3 == 0;
        if (bVar6) {
          local_130 = 0;
        }
      }
      if (!bVar6) {
        local_130 = 1;
      }
      uVar8 = __floatsidf(local_130);
    }
  }
  else {
    uVar8 = 0;
    if (param_3 - 0x21U < 0x2c) {
                    /* WARNING: Could not recover jumptable at 0x30109670. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(DAT_3010967c + (param_3 - 0x21U) * 4))();
      return;
    }
  }
  if (local_148 == 7) {
    uVar8 = CONCAT44(iVar5,puVar4);
  }
  local_48 = local_148;
  local_4c = 2;
  local_54 = uVar8;
  FUN_3010891c(auStack_78,local_134);
  if (local_13c == (undefined1 *)0x0) {
    if ((iVar1 != 8) && (iVar2 != 8)) {
      local_3c = 1;
    }
  }
  else {
    local_48 = local_120;
    local_44 = local_11c;
    local_40 = local_118;
    local_3c = local_114;
    local_38 = local_110;
  }
  iVar5 = 0x11;
  puVar4 = auStack_78;
  do {
    iVar5 = iVar5 + -1;
    *param_1 = *puVar4;
    param_1 = param_1 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar5 != 0);
  return;
}

