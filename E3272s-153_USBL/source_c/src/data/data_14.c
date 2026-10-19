/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 14 (функций: 150, адреса 0x3011CA5C..0x3012D6A4)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * lkAddr @ 0x3011CA5C  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: lkAddrInternal
 * Константы: 0x3011CA5C
 * Данные: DAT_3011d684
 * ---------------------------------------------------------------- */
void lkAddr(undefined4 param_1)

{
  lkAddrInternal(param_1,*DAT_3011d684);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3011ca68 @ 0x3011CA68  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: strncmp
 * Вызывают: FUN_3011caac, FUN_3011cb6c, FUN_3011cbc4
 * Константы: 0x3011CA68
 * Данные: DAT_3011d698, DAT_3011d69c
 * ---------------------------------------------------------------- */
undefined4 FUN_3011ca68(char *param_1)

{
  int iVar1;
  
  iVar1 = strncmp(param_1,DAT_3011d698,0xb);
  if ((iVar1 != 0) && (iVar1 = strncmp(param_1,DAT_3011d69c,0xc), iVar1 != 0)) {
    return 0;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3011caac @ 0x3011CAAC  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_3011ca68
 * Константы: 0x3011CAAC
 * ---------------------------------------------------------------- */
undefined4 FUN_3011caac(undefined4 param_1,uint param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_3011ca68();
  if (iVar1 == 0) {
    uVar2 = *(uint *)(param_4 + 4);
    if (param_2 < uVar2) {
      if (*(uint *)(param_4 + 8) < param_2) {
        *(uint *)(param_4 + 8) = param_2;
        *(undefined4 *)(param_4 + 0xc) = param_1;
        *(undefined1 *)(param_4 + 0x10) = param_3;
      }
    }
    else if (uVar2 == param_2) {
      *(uint *)(param_4 + 0x14) = param_2;
      *(undefined4 *)(param_4 + 0x18) = param_1;
      *(undefined1 *)(param_4 + 0x1c) = param_3;
    }
    else if ((uVar2 < param_2) &&
            ((param_2 < *(uint *)(param_4 + 0x20) || (*(uint *)(param_4 + 0x20) == 0)))) {
      *(uint *)(param_4 + 0x20) = param_2;
      *(undefined4 *)(param_4 + 0x24) = param_1;
      *(undefined1 *)(param_4 + 0x28) = param_3;
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3011cb6c @ 0x3011CB6C  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_3011ca68
 * Константы: 0x3011CB6C
 * ---------------------------------------------------------------- */
undefined4 FUN_3011cb6c(undefined4 param_1,uint param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = FUN_3011ca68();
  if (((iVar1 == 0) && (*(uint *)(param_4 + 4) < param_2)) &&
     ((param_2 < *(uint *)(param_4 + 0x20) || (*(uint *)(param_4 + 0x20) == 0)))) {
    *(uint *)(param_4 + 0x20) = param_2;
    *(undefined4 *)(param_4 + 0x24) = param_1;
    *(undefined1 *)(param_4 + 0x28) = param_3;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3011cbc4 @ 0x3011CBC4  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_3011ca68, cplusDemangle, printf, puts, symTypeToStringConvert
 * Константы: 0x3011CBC4
 * Данные: DAT_3011cfe8, DAT_3011d6a0, DAT_3011d6a4
 * ---------------------------------------------------------------- */
undefined4 FUN_3011cbc4(undefined4 param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_11c [260];
  
  iVar1 = FUN_3011ca68();
  if ((iVar1 == 0) && (param_4[1] == param_2)) {
    uVar2 = cplusDemangle(param_1,auStack_11c,0x100);
    uVar3 = symTypeToStringConvert(param_3 & 0xfe);
    printf(DAT_3011d6a0,param_2,uVar2,uVar3);
    if ((param_3 & 1) != 1) {
      printf(DAT_3011d6a4);
    }
    puts(DAT_3011cfe8);
    *param_4 = *param_4 + 1;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * substrcmp @ 0x3011CC64  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: index, strcmp, strlen, strncmp
 * Вызывают: taskRegsModify
 * Константы: 0x3011CC64
 * ---------------------------------------------------------------- */
bool substrcmp(char *param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  
  if (param_1 != (char *)0x0) {
    do {
      pcVar1 = index(param_1,0x2f);
      if (pcVar1 == (char *)0x0) {
        iVar2 = strcmp(param_1,param_2);
        return iVar2 == 0;
      }
      iVar2 = strncmp(param_1,param_2,(int)pcVar1 - (int)param_1);
      if ((iVar2 == 0) && (sVar3 = strlen(param_2), sVar3 == (int)pcVar1 - (int)param_1)) {
        return true;
      }
      param_1 = pcVar1 + 1;
    } while (param_1 != (char *)0x0);
  }
  return false;
}

/* ----------------------------------------------------------------
 * changeReg @ 0x3011CD14  (примерный размер ~532 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_3011bc2c, fioRdString, printf
 * Вызывают: taskRegsModify
 * Константы: 0xFFFFFFFF, 0x3011CD14
 * Данные: DAT_3011d6a8, DAT_3011d6ac, DAT_3011d6b0, DAT_3011d6b4, DAT_3011d6b8, DAT_3011d6bc
 * ---------------------------------------------------------------- */
undefined4 changeReg(char *param_1,ushort *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  byte local_3c;
  byte local_3b [38];
  undefined1 local_15;
  
  local_44 = 0;
  local_40 = 0;
  local_4c = 0;
  iVar3 = param_3 << 1;
  if (*param_1 == '\0') {
    return 0;
  }
  if (param_3 == 4) {
    printf(DAT_3011d6b0,param_1,*(undefined4 *)param_2);
    goto LAB_3011ce18;
  }
  if (param_3 < 5) {
    if (param_3 == 1) {
      printf(DAT_3011d6a8,param_1,(uint)(byte)*param_2);
      goto LAB_3011ce18;
    }
    if (param_3 == 2) {
      printf(DAT_3011d6ac,param_1,(uint)*param_2);
      goto LAB_3011ce18;
    }
  }
  else {
    if (param_3 == 8) {
      printf(DAT_3011d6b4,param_1,*(undefined4 *)(param_2 + 2),*(undefined4 *)param_2);
      goto LAB_3011ce18;
    }
    if (param_3 == 0x10) {
      printf(DAT_3011d6b8,param_1,*(undefined4 *)(param_2 + 6),*(undefined4 *)(param_2 + 4),
             *(undefined4 *)(param_2 + 2),*(undefined4 *)param_2);
      goto LAB_3011ce18;
    }
  }
  printf(DAT_3011d6a8,param_1,(uint)(byte)*param_2);
  iVar3 = 2;
LAB_3011ce18:
  iVar2 = fioRdString(0,&local_3c,0x28);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  local_15 = 0;
  pbVar4 = &local_3c;
  bVar1 = *(byte *)(*DAT_3011d6bc + (uint)local_3c);
  while ((bVar1 & 0x28) != 0) {
    pbVar4 = pbVar4 + 1;
    bVar1 = *(byte *)(*DAT_3011d6bc + (uint)*pbVar4);
  }
  if (*pbVar4 != 0) {
    local_48 = 0;
    iVar3 = FUN_3011bc2c(pbVar4,&local_44,&local_40,&local_4c,&local_48,iVar3);
    if (iVar3 != 0) {
      return 0xffffffff;
    }
    if (param_3 == 2) {
      *param_2 = (ushort)local_48;
    }
    else if (param_3 == 4) {
      *(undefined4 *)param_2 = local_48;
    }
    else if (param_3 == 8) {
      *(undefined4 *)param_2 = local_48;
      *(undefined4 *)(param_2 + 2) = local_4c;
    }
    else if (param_3 == 0x10) {
      *(undefined4 *)param_2 = local_48;
      *(undefined4 *)(param_2 + 2) = local_4c;
      *(undefined4 *)(param_2 + 4) = local_40;
      *(undefined4 *)(param_2 + 6) = local_44;
    }
    else {
      *(byte *)param_2 = (byte)local_48;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * mRegs @ 0x3011D140  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: printErr, taskIdFigure, taskRegsModify
 * Константы: 0x3011D140, 0xFFFFFFFF
 * Данные: DAT_3011d3b4, DAT_3011d6d8
 * ---------------------------------------------------------------- */
undefined4 mRegs(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = taskIdFigure(param_2);
  if (iVar1 == -1) {
    printErr(*DAT_3011d3b4,DAT_3011d3b4[8]);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = taskRegsModify(param_1,iVar1,*DAT_3011d6d8);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * changeFpReg @ 0x3011D1A8  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: fioRdString, printf, sscanf, strcmp
 * Константы: 0xFFFFFFFF, 0x3011D1A8
 * Данные: DAT_3011d6dc, DAT_3011d6e0, DAT_3011d6e4
 * ---------------------------------------------------------------- */
undefined4 changeFpReg(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined1 auStack_38 [8];
  undefined4 local_30;
  undefined4 local_2c;
  char acStack_28 [20];
  
  if (*param_1 != '\0') {
    printf(DAT_3011d6dc,param_1,param_2,param_3);
    iVar1 = fioRdString(0,acStack_28,0x14);
    if (iVar1 != 1) {
      iVar1 = strcmp(DAT_3011d6e0,acStack_28);
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      iVar1 = sscanf(acStack_28,DAT_3011d6e4,&local_30,auStack_38);
      param_2 = local_30;
      param_3 = local_2c;
      if (iVar1 != 1) {
        return 0xffffffff;
      }
    }
    *param_4 = param_2;
    param_4[1] = param_3;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * pc @ 0x3011D24C  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: shellTaskIdDefault, taskIdFigure, taskRegsGet
 * Константы: 0xFFFFFFFF, 0x3011D24C
 * ---------------------------------------------------------------- */
undefined4 pc(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_4c [60];
  undefined4 uStack_10;
  
  iVar1 = taskIdFigure();
  if (iVar1 == -1) {
    uStack_10 = 0xffffffff;
  }
  else {
    uVar2 = shellTaskIdDefault(0,iVar1);
    iVar1 = taskRegsGet(uVar2,auStack_4c);
    if (iVar1 != 0) {
      uStack_10 = 0xffffffff;
    }
  }
  return uStack_10;
}

/* ----------------------------------------------------------------
 * printLogo @ 0x3011D290  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: kernelVersion, printf, puts
 * Вызывают: usrBanner
 * Константы: 0x3011D290
 * Данные: DAT_3011d6d4, DAT_3011d6e8, DAT_3011d6ec, DAT_3011d6f0, DAT_3011d6f4, DAT_3011d6f8, DAT_3011d6fc, DAT_3011d700
 * ---------------------------------------------------------------- */
void printLogo(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0x10;
  puVar2 = DAT_3011d6e8;
  do {
    puVar2 = puVar2 + 1;
    printf(DAT_3011d6ec,*puVar2);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  printf(DAT_3011d6f8,DAT_3011d6fc,*DAT_3011d6f0,*DAT_3011d6f4);
  uVar1 = kernelVersion();
  printf(DAT_3011d700,DAT_3011d704,uVar1);
  printf(DAT_3011d6ec,DAT_3011d708);
  puts(DAT_3011d6d4);
  return;
}

/* ----------------------------------------------------------------
 * spyReport @ 0x3011D324  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: puts
 * Константы: 0x3011D324
 * Данные: DAT_3011d710, DAT_3011d714, DAT_3011d718
 * ---------------------------------------------------------------- */
void spyReport(void)

{
  if ((code *)*DAT_3011d710 == (code *)0x0) {
    puts(DAT_3011d718);
  }
  else {
    (*(code *)*DAT_3011d710)(DAT_3011d714);
  }
  return;
}

/* ----------------------------------------------------------------
 * spyTask @ 0x3011D358  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: puts
 * Константы: 0x3011D358
 * Данные: DAT_3011d714, DAT_3011d718, DAT_3011d71c
 * ---------------------------------------------------------------- */
void spyTask(undefined4 param_1)

{
  if ((code *)*DAT_3011d71c == (code *)0x0) {
    puts(DAT_3011d718);
  }
  else {
    (*(code *)*DAT_3011d71c)(param_1,DAT_3011d714);
  }
  return;
}

/* ----------------------------------------------------------------
 * spy @ 0x3011D38C  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: puts
 * Константы: 0x3011D38C
 * Данные: DAT_3011d714, DAT_3011d718, DAT_3011d720
 * ---------------------------------------------------------------- */
void spy(undefined4 param_1,undefined4 param_2)

{
  if ((code *)*DAT_3011d720 == (code *)0x0) {
    puts(DAT_3011d718);
  }
  else {
    (*(code *)*DAT_3011d720)(param_1,param_2,DAT_3011d714);
  }
  return;
}

/* ----------------------------------------------------------------
 * spyClkStart @ 0x3011D3C8  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: puts
 * Константы: 0x3011D3C8, 0xFFFFFFFF
 * Данные: DAT_3011d714, DAT_3011d718, DAT_3011d724
 * ---------------------------------------------------------------- */
undefined4 spyClkStart(undefined4 param_1)

{
  undefined4 uVar1;
  
  if ((code *)*DAT_3011d724 == (code *)0x0) {
    puts(DAT_3011d718);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (*(code *)*DAT_3011d724)(param_1,DAT_3011d714);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * spyClkStop @ 0x3011D400  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: puts
 * Константы: 0x3011D400
 * Данные: DAT_3011d718, DAT_3011d728
 * ---------------------------------------------------------------- */
void spyClkStop(void)

{
  if ((code *)*DAT_3011d728 == (code *)0x0) {
    puts(DAT_3011d718);
  }
  else {
    (*(code *)*DAT_3011d728)();
  }
  return;
}

/* ----------------------------------------------------------------
 * spyStop @ 0x3011D430  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: puts
 * Константы: 0x3011D430
 * Данные: DAT_3011d718, DAT_3011d72c
 * ---------------------------------------------------------------- */
void spyStop(void)

{
  if ((code *)*DAT_3011d72c == (code *)0x0) {
    puts(DAT_3011d718);
  }
  else {
    (*(code *)*DAT_3011d72c)();
  }
  return;
}

/* ----------------------------------------------------------------
 * spyHelp @ 0x3011D460  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: puts
 * Константы: 0x3011D460
 * Данные: DAT_3011d718, DAT_3011d71c, DAT_3011d730
 * ---------------------------------------------------------------- */
void spyHelp(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*DAT_3011d71c == 0) {
    puts(DAT_3011d718);
  }
  else {
    iVar2 = 0xc;
    puVar1 = DAT_3011d730;
    do {
      puVar1 = puVar1 + 1;
      puts((char *)*puVar1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

/* ----------------------------------------------------------------
 * unld @ 0x3011D4B0  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: printErr
 * Константы: 0xFFFFFFFF, 0x3011D4B0
 * Данные: DAT_3011d734, DAT_3011d738, DAT_3011d73c
 * ---------------------------------------------------------------- */
undefined4 unld(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  bool bVar3;
  
  if (*DAT_3011d734 == 0) {
    printErr(DAT_3011d738);
    uVar1 = 0xffffffff;
  }
  else {
    pcVar2 = (code *)*DAT_3011d73c;
    bVar3 = pcVar2 == (code *)0x0;
    if (!bVar3) {
      pcVar2 = (code *)(*pcVar2)();
      bVar3 = pcVar2 == (code *)0x0;
    }
    if (bVar3) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = (*(code *)*DAT_3011d734)(pcVar2,param_2);
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * reld @ 0x3011D528  (примерный размер ~248 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 7
 * Вызывает: close, loadModule, moduleIdFigure, open, printErr, strcat, strcpy
 * Константы: 0x3011D528
 * Данные: DAT_3011d734, DAT_3011d738, DAT_3011d740, DAT_3011d744, DAT_3011d748
 * ---------------------------------------------------------------- */
undefined4 reld(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  char acStack_514 [1280];
  
  piVar1 = DAT_3011d734;
  if (*DAT_3011d734 == 0) {
    printErr(DAT_3011d738);
  }
  else {
    iVar2 = moduleIdFigure();
    if (iVar2 != 0) {
      strcpy(acStack_514,(char *)(iVar2 + DAT_3011d740));
      if (*(char *)(iVar2 + 0x117) != '\0') {
        strcat(acStack_514,DAT_3011d744);
      }
      strcat(acStack_514,(char *)(iVar2 + 0x18));
      uVar3 = *(undefined4 *)(iVar2 + 0x518);
      (*(code *)*piVar1)(iVar2,param_2);
      iVar2 = open(acStack_514,0,0);
      if (iVar2 != -1) {
        uVar3 = loadModule(iVar2,uVar3);
        close(iVar2);
        return uVar3;
      }
      printErr(DAT_3011d748,acStack_514);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * tip @ 0x3011D620  (примерный размер ~308 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: puts
 * Константы: 0x3011D620
 * Данные: DAT_3011d74c, DAT_3011d750
 * ---------------------------------------------------------------- */
void tip(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  if ((code *)*DAT_3011d74c == (code *)0x0) {
    puts(DAT_3011d750);
  }
  else {
    (*(code *)*DAT_3011d74c)(param_1,&uStack_c,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3011d754 @ 0x3011D754  (примерный размер ~428 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: avlUintDelete, avlUintInsert
 * Константы: 0x3011D754
 * ---------------------------------------------------------------- */
void FUN_3011d754(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  if (param_2 < 1) {
    return;
  }
  do {
    puVar1 = (undefined4 *)(param_1 + param_2 * 4);
    while( true ) {
      puVar1 = puVar1 + -1;
      puVar2 = (undefined4 *)*puVar1;
      param_2 = param_2 + -1;
      piVar4 = (int *)*puVar2;
      piVar7 = (int *)*piVar4;
      if (piVar7 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = piVar7[2];
      }
      piVar6 = (int *)piVar4[1];
      if (piVar6 == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = piVar6[2];
      }
      if (-2 < iVar5 - iVar3) {
        if (iVar5 - iVar3 < 2) {
          if (iVar5 <= iVar3) {
            iVar5 = iVar3;
          }
          if (piVar4[2] == iVar5 + 1) {
            return;
          }
          piVar4[2] = iVar5 + 1;
        }
        else {
          piVar7 = (int *)*piVar6;
          if (piVar7 == (int *)0x0) {
            iVar3 = 0;
          }
          else {
            iVar3 = piVar7[2];
          }
          if ((piVar6[1] == 0) || (*(int *)(piVar6[1] + 8) < iVar3)) {
            piVar4[1] = *piVar7;
            piVar4[2] = iVar3;
            *piVar6 = piVar7[1];
            piVar6[2] = iVar3;
            *piVar7 = (int)piVar4;
            piVar7[1] = (int)piVar6;
            piVar7[2] = iVar3 + 1;
            *puVar2 = piVar7;
          }
          else {
            piVar4[1] = (int)piVar7;
            piVar4[2] = iVar3 + 1;
            *piVar6 = (int)piVar4;
            piVar6[2] = iVar3 + 2;
            *puVar2 = piVar6;
          }
        }
        goto joined_r0x3011d8f4;
      }
      piVar6 = (int *)piVar7[1];
      if (piVar6 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = piVar6[2];
      }
      if ((*piVar7 == 0) || (*(int *)(*piVar7 + 8) < iVar3)) break;
      *piVar4 = (int)piVar6;
      piVar4[2] = iVar3 + 1;
      piVar7[1] = (int)piVar4;
      piVar7[2] = iVar3 + 2;
      *puVar2 = piVar7;
      if (param_2 == 0) {
        return;
      }
    }
    piVar7[1] = *piVar6;
    piVar7[2] = iVar3;
    *piVar4 = piVar6[1];
    piVar4[2] = iVar3;
    *piVar6 = (int)piVar7;
    piVar6[1] = (int)piVar4;
    piVar6[2] = iVar3 + 1;
    *puVar2 = piVar6;
joined_r0x3011d8f4:
    if (param_2 < 1) {
      return;
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * bcmp @ 0x3011DD98  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300d88b4, FUN_300db20c, dosFsVolIsFat12
 * Константы: 0x3011DD98
 * ---------------------------------------------------------------- */
int bcmp(void *__s1,void *__s2,size_t __n)

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
 * binvert @ 0x3011DDD8  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011DDD8
 * ---------------------------------------------------------------- */
void binvert(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar3 = param_1 + param_2 + -1;
  if (puVar3 <= param_1) {
    return;
  }
  do {
    uVar1 = *param_1;
    puVar2 = param_1 + 1;
    *param_1 = *puVar3;
    *puVar3 = uVar1;
    puVar3 = puVar3 + -1;
    param_1 = puVar2;
  } while (puVar2 < puVar3);
  return;
}

/* ----------------------------------------------------------------
 * bswap @ 0x3011DE08  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011DE08
 * ---------------------------------------------------------------- */
void bswap(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  
  while (param_3 = param_3 + -1, -1 < param_3) {
    uVar1 = *param_1;
    *param_1 = *param_2;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * swab @ 0x3011DE38  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011DE38
 * ---------------------------------------------------------------- */
void swab(void *__from,void *__to,ssize_t __n)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar1 = (ushort *)__to;
  if (__to < (ushort *)((int)__to + __n)) {
    do {
                    /* WARNING: Load size is inaccurate */
      puVar2 = puVar1 + 1;
      *puVar1 = *__from >> 8 | (ushort)((*__from & 0xff) << 8);
      __from = (ushort *)((int)__from + 2);
      puVar1 = puVar2;
    } while (puVar2 < (ushort *)((int)__to + __n));
  }
  return;
}

/* ----------------------------------------------------------------
 * uswab @ 0x3011DE84  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011DE84
 * ---------------------------------------------------------------- */
void uswab(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar3 = param_2 + param_3;
  if (param_2 < puVar3) {
    do {
      puVar2 = param_1 + 1;
      uVar1 = *param_1;
      param_1 = param_1 + 2;
      puVar4 = param_2 + 1;
      *param_2 = *puVar2;
      param_2 = param_2 + 2;
      *puVar4 = uVar1;
    } while (param_2 < puVar3);
  }
  return;
}

/* ----------------------------------------------------------------
 * index @ 0x3011DEC8  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 0
 * Вызывают: FUN_30118ef8, FUN_301207c8, FUN_30120ec8, bootLeaseExtract, bootNetmaskExtract, bootStringToStructAdd, pathCat, substrcmp
 * Константы: 0x3011DEC8
 * ---------------------------------------------------------------- */
char * index(char *__s,int __c)

{
  uint uVar1;
  byte *pbVar2;
  
  do {
    pbVar2 = (byte *)__s;
    uVar1 = (uint)*pbVar2;
    if (uVar1 == __c) break;
    __s = (char *)(pbVar2 + 1);
  } while (uVar1 != 0);
  if ((uVar1 == 0) && (__c != 0)) {
    pbVar2 = (byte *)0x0;
  }
  return (char *)pbVar2;
}

/* ----------------------------------------------------------------
 * rindex @ 0x3011DEFC  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: strlen
 * Вызывают: FUN_300ec834, FUN_3011904c, FUN_301190ec, symFindSymbol
 * Константы: 0x3011DEFC
 * ---------------------------------------------------------------- */
char * rindex(char *__s,int __c)

{
  size_t sVar1;
  byte *pbVar2;
  
  sVar1 = strlen(__s);
  pbVar2 = (byte *)(__s + sVar1 + 1);
  while( true ) {
    if ((int)sVar1 < 0) {
      return (char *)0x0;
    }
    pbVar2 = pbVar2 + -1;
    if ((uint)*pbVar2 == __c) break;
    sVar1 = sVar1 - 1;
  }
  return (char *)pbVar2;
}

/* ----------------------------------------------------------------
 * FUN_3011df44 @ 0x3011DF44  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: sprintf, strlen
 * Вызывают: bootStructToString
 * Константы: 0x3011DF44
 * Данные: DAT_3011e78c, DAT_3011e790
 * ---------------------------------------------------------------- */
void FUN_3011df44(char *param_1,undefined4 param_2,int param_3)

{
  size_t sVar1;
  char *__format;
  
  if (param_3 == 0) {
    return;
  }
  sVar1 = strlen(param_1);
  __format = DAT_3011e78c;
  if (7 < param_3) {
    __format = DAT_3011e790;
  }
  sprintf(param_1 + sVar1,__format,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3011df8c @ 0x3011DF8C  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: sprintf, strlen
 * Вызывают: bootStructToString
 * Константы: 0x3011DF8C
 * Данные: DAT_3011e794
 * ---------------------------------------------------------------- */
void FUN_3011df8c(char *param_1,undefined4 param_2,char *param_3)

{
  size_t sVar1;
  
  if (*param_3 == '\0') {
    return;
  }
  sVar1 = strlen(param_1);
  sprintf(param_1 + sVar1,DAT_3011e794,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * bootStructToString @ 0x3011DFC4  (примерный размер ~544 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_3011df44, FUN_3011df8c, __udiv32, sprintf, taskUnsafe
 * Константы: 0x3011DFC4
 * Данные: DAT_3011e798, DAT_3011e79c, DAT_3011e7a0, DAT_3011e7a4, DAT_3011e7a8, DAT_3011e7ac, DAT_3011e7b0, DAT_3011e7b4
 * ---------------------------------------------------------------- */
undefined4 bootStructToString(char *param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  char *__format;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint local_20;
  
  piVar2 = DAT_3011e798;
  bVar1 = false;
  iVar5 = 0;
  iVar4 = 0;
  if (*DAT_3011e798 != 0) {
    if ((code *)DAT_3011e798[8] == (code *)0x0) {
      iVar5 = -1;
    }
    else {
      iVar5 = (*(code *)DAT_3011e798[8])();
    }
    iVar4 = __udiv32(param_1,iVar5);
    iVar4 = iVar5 * iVar4;
    if ((((code *)piVar2[6] != (code *)0x0) &&
        (iVar3 = (*(code *)piVar2[6])(0,iVar4,&local_20), iVar3 != -1)) && ((local_20 & 0x3f) == 5))
    {
      bVar1 = true;
      *(int *)(*DAT_3011e79c + 0xac) = *(int *)(*DAT_3011e79c + 0xac) + 1;
      if ((code *)piVar2[5] != (code *)0x0) {
        (*(code *)piVar2[5])(0,iVar4,iVar5,0x3f,7);
      }
    }
  }
  if ((*(char *)(param_2 + 0x28) == '\0') && (*(char *)(param_2 + 0xf0) == '\0')) {
    uVar6 = *(undefined4 *)(param_2 + 0x2a8);
    __format = DAT_3011e7a0;
  }
  else {
    uVar6 = *(undefined4 *)(param_2 + 0x2a8);
    __format = DAT_3011e7a4;
  }
  sprintf(param_1,__format,param_2,*(undefined4 *)(param_2 + 0x2b0),uVar6);
  FUN_3011df8c(param_1,DAT_3011e7a8,param_2 + 0x50);
  FUN_3011df8c(param_1,DAT_3011e7ac,param_2 + 0x82);
  FUN_3011df8c(param_1,DAT_3011e7b0,param_2 + 0xb4);
  FUN_3011df8c(param_1,DAT_3011e7b4,param_2 + 0xd2);
  FUN_3011df8c(param_1,DAT_3011e7b8,param_2 + 0x230);
  FUN_3011df8c(param_1,DAT_3011e7bc,param_2 + 0x244);
  FUN_3011df44(param_1,DAT_3011e7c0,*(undefined4 *)(param_2 + 0x2ac));
  FUN_3011df8c(param_1,DAT_3011e7c4,param_2 + 0x3c);
  FUN_3011df8c(param_1,DAT_3011e7c8,param_2 + 400);
  FUN_3011df8c(param_1,DAT_3011e7cc,param_2 + 600);
  if (bVar1) {
    if ((code *)piVar2[5] != (code *)0x0) {
      (*(code *)piVar2[5])(0,iVar4,iVar5,0x3f,5);
    }
    taskUnsafe();
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3011e1e4 @ 0x3011E1E4  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: bootParamsShow
 * Константы: 0x3011E1E4
 * Данные: DAT_3011e7d0, DAT_3011e7d4
 * ---------------------------------------------------------------- */
void FUN_3011e1e4(undefined4 param_1,undefined4 param_2,int param_3)

{
  char *__format;
  
  __format = DAT_3011e7d0;
  if (param_3 == 0) {
    __format = DAT_3011e7d4;
  }
  printf(__format,0x15,param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3011e204 @ 0x3011E204  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: FUN_3011e248, FUN_3011e43c, FUN_3011e5a4
 * Константы: 0x3011E204
 * Данные: DAT_3011e7d8, DAT_3011e7dc
 * ---------------------------------------------------------------- */
void FUN_3011e204(byte *param_1)

{
  uint uVar1;
  
  while( true ) {
    uVar1 = (uint)*param_1;
    if (uVar1 == 0) break;
    if ((0x7f < uVar1) || ((*(byte *)(*DAT_3011e7d8 + uVar1) & 0x1f) == 0)) {
      uVar1 = 0x3f;
    }
    printf(DAT_3011e7dc,uVar1);
    param_1 = param_1 + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3011e248 @ 0x3011E248  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_3011e204, printf, puts
 * Вызывают: bootParamsShow
 * Константы: 0x3011E248
 * Данные: DAT_3011e7e0, DAT_3011e7e4
 * ---------------------------------------------------------------- */
void FUN_3011e248(undefined4 param_1,char *param_2)

{
  if (*param_2 == '\0') {
    return;
  }
  printf(DAT_3011e7e0,0x15,param_1);
  FUN_3011e204(param_2);
  puts(DAT_3011e7e4);
  return;
}

/* ----------------------------------------------------------------
 * bootParamsShow @ 0x3011E280  (примерный размер ~288 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_3011e1e4, FUN_3011e248, bootParamsErrorPrint, bootStringToStruct, puts
 * Константы: 0x3011E280
 * Данные: DAT_3011e7e4, DAT_3011e7e8, DAT_3011e7ec, DAT_3011e7f0, DAT_3011e7f4, DAT_3011e7f8, DAT_3011e7fc, DAT_3011e800
 * ---------------------------------------------------------------- */
void bootParamsShow(int param_1)

{
  char *pcVar1;
  undefined1 auStack_2bc [40];
  undefined1 auStack_294 [20];
  undefined1 auStack_280 [20];
  undefined1 auStack_26c [50];
  undefined1 auStack_23a [50];
  undefined1 auStack_208 [30];
  undefined1 auStack_1ea [30];
  undefined1 auStack_1cc [160];
  undefined1 auStack_12c [160];
  undefined1 auStack_8c [20];
  undefined1 auStack_78 [20];
  undefined1 auStack_64 [80];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  pcVar1 = DAT_3011e7e8;
  if (param_1 != 0) {
    pcVar1 = (char *)bootStringToStruct(param_1,auStack_2bc);
    if (*pcVar1 != '\0') {
      bootParamsErrorPrint(param_1,pcVar1);
      return;
    }
    puts(DAT_3011e7e4);
    FUN_3011e248(DAT_3011e7ec,auStack_2bc);
    FUN_3011e1e4(DAT_3011e7f0,local_c,0);
    FUN_3011e1e4(DAT_3011e7f4,local_14,0);
    FUN_3011e248(DAT_3011e7f8,auStack_294);
    FUN_3011e248(DAT_3011e7fc,auStack_1cc);
    FUN_3011e248(DAT_3011e800,auStack_26c);
    FUN_3011e248(DAT_3011e804,auStack_23a);
    FUN_3011e248(DAT_3011e808,auStack_208);
    FUN_3011e248(DAT_3011e80c,auStack_1ea);
    FUN_3011e248(DAT_3011e810,auStack_8c);
    FUN_3011e248(DAT_3011e814,auStack_78);
    FUN_3011e1e4(DAT_3011e818,local_10,1);
    FUN_3011e248(DAT_3011e81c,auStack_280);
    FUN_3011e248(DAT_3011e820,auStack_12c);
    FUN_3011e248(DAT_3011e824,auStack_64);
    pcVar1 = DAT_3011e7e4;
  }
  puts(pcVar1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3011e3a0 @ 0x3011E3A0  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: fioRdString, printf
 * Вызывают: FUN_3011e43c, FUN_3011e5a4, FUN_3011e698
 * Константы: 0x3011E3A0, 0xFFFFFF9D, 0xFFFFFFFF, 0xFFFFFF9E
 * Данные: DAT_3011e828
 * ---------------------------------------------------------------- */
undefined4 FUN_3011e3a0(char *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = fioRdString(0,param_1,param_2);
  if (iVar1 == -1) {
    return 0xffffff9d;
  }
  if (iVar1 == 1) {
    return 1;
  }
  if ((iVar1 == 2) && (*param_1 == '-')) {
    return 0xffffffff;
  }
  if (param_2 <= iVar1) {
    printf(DAT_3011e828,param_2);
    do {
      iVar1 = fioRdString(0,param_1,param_2);
    } while (param_2 <= iVar1);
    return 0xffffff9e;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3011e43c @ 0x3011E43C  (примерный размер ~360 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 7
 * Вызывает: FUN_3011e204, FUN_3011e3a0, bootScanNum, printf, puts, sprintf, strcat
 * Константы: 0x3011E43C
 * Данные: DAT_3011e7d8, DAT_3011e7e0, DAT_3011e7ec, DAT_3011e82c, DAT_3011e830, DAT_3011e834
 * ---------------------------------------------------------------- */
int FUN_3011e43c(undefined4 param_1,char *param_2,undefined4 *param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 local_bc;
  byte *local_b8;
  byte local_b4 [160];
  
  sprintf((char *)local_b4,DAT_3011e82c,param_2,*param_3);
  printf(DAT_3011e7e0,0x15,DAT_3011e7ec);
  FUN_3011e204(local_b4);
  if (local_b4[0] != 0) {
    printf(DAT_3011e830);
  }
  iVar2 = FUN_3011e3a0(local_b4,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_b4[0] == 0x2e) {
    local_bc = 0;
    *param_2 = '\0';
  }
  else {
    iVar2 = *DAT_3011e7d8;
    iVar5 = 0;
    if ((*(byte *)(iVar2 + (uint)local_b4[0]) & 4) == 0) {
      pbVar4 = local_b4;
      pbVar3 = (byte *)(param_2 + -1);
      do {
        bVar1 = *pbVar4;
        if ((bVar1 == 0x3d) || (bVar1 == 0)) break;
        pbVar3 = pbVar3 + 1;
        *pbVar3 = bVar1;
        pbVar4 = pbVar4 + 1;
        iVar5 = iVar5 + 1;
      } while ((*(byte *)(iVar2 + (uint)*pbVar4) & 4) == 0);
    }
    param_2[iVar5] = '\0';
    if ((*(byte *)(iVar2 + (uint)local_b4[iVar5]) & 4) == 0) {
      local_bc = 0;
      if (local_b4[iVar5] != 0x3d) goto LAB_3011e594;
      pbVar3 = local_b4 + iVar5;
    }
    else {
      local_b8 = local_b4 + iVar5;
      iVar2 = bootScanNum(&local_b8,&local_bc,0);
      pbVar3 = local_b8;
      if (iVar2 != 0) {
        puts(DAT_3011e834);
        return -0x62;
      }
    }
    strcat(param_2,(char *)pbVar3);
  }
LAB_3011e594:
  *param_3 = local_bc;
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3011e5a4 @ 0x3011E5A4  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_3011e204, FUN_3011e3a0, printf, strcpy, strlen
 * Константы: 0x3011E5A4
 * Данные: DAT_3011e7d8, DAT_3011e7e0, DAT_3011e830
 * ---------------------------------------------------------------- */
int FUN_3011e5a4(undefined4 param_1,char *param_2,undefined4 param_3)

{
  byte *pbVar1;
  int iVar2;
  size_t sVar3;
  byte *__src;
  byte *pbVar4;
  byte local_b4 [160];
  
  __src = local_b4;
  printf(DAT_3011e7e0,0x15,param_1);
  FUN_3011e204(param_2);
  if (*param_2 != '\0') {
    printf(DAT_3011e830);
  }
  iVar2 = FUN_3011e3a0(local_b4,param_3);
  if (iVar2 == 0) {
    if (local_b4[0] == 0x2e) {
      *param_2 = '\0';
    }
    else {
      iVar2 = *DAT_3011e7d8;
      for (; ((*(byte *)(iVar2 + (uint)*__src) & 0x28) != 0 && (*__src != 0)); __src = __src + 1) {
      }
      sVar3 = strlen((char *)local_b4);
      pbVar4 = local_b4 + sVar3;
      do {
        pbVar1 = pbVar4;
        pbVar4 = pbVar1 + -1;
        if ((*(byte *)(iVar2 + (uint)*pbVar4) & 0x28) == 0) break;
      } while (__src < pbVar4);
      *pbVar1 = 0;
      strcpy(param_2,(char *)__src);
    }
    iVar2 = 1;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_3011e698 @ 0x3011E698  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_3011e3a0, bootScanNum, printf, puts
 * Константы: 0x3011E698
 * Данные: DAT_3011e838, DAT_3011e83c, DAT_3011e840
 * ---------------------------------------------------------------- */
int FUN_3011e698(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  char *__format;
  char *local_b4;
  undefined4 local_b0;
  char local_ac [160];
  
  __format = DAT_3011e838;
  if (param_3 == 0) {
    __format = DAT_3011e83c;
  }
  printf(__format,0x15,param_1,*param_2);
  iVar1 = FUN_3011e3a0(local_ac,0xa0);
  if (iVar1 == 0) {
    if (local_ac[0] == '.') {
      local_b0 = 0;
    }
    else {
      local_b4 = local_ac;
      iVar1 = bootScanNum(&local_b4,&local_b0,0);
      if ((iVar1 != 0) || (*local_b4 != '\0')) {
        puts(DAT_3011e840);
        return -0x62;
      }
    }
    *param_2 = local_b0;
    iVar1 = 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * bootParamsPrompt @ 0x3011E748  (примерный размер ~720 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: bootStringToStruct, puts
 * Вызывают: bootChange
 * Константы: 0x3011E748, 0x3011E9AC, 0x3011E9B4, 0x3011E9A0, 0x3011E788
 * Данные: DAT_3011e844, DAT_3011e848
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x3011e9ac) */
/* WARNING: Removing unreachable block (ram,0x3011e9b4) */
/* WARNING: Removing unreachable block (ram,0x3011e9a0) */

void bootParamsPrompt(undefined4 param_1)

{
  undefined1 auStack_2d0 [692];
  
  bootStringToStruct(param_1,auStack_2d0);
  puts(DAT_3011e844);
                    /* WARNING: Could not recover jumptable at 0x3011e788. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*DAT_3011e848)();
  return;
}

/* ----------------------------------------------------------------
 * dllInit @ 0x3011EA18  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 11 | Вызывает: 0
 * Вызывают: FUN_300e66d4, FUN_30111c28, iosInit, moduleCreateHookAdd, moduleInit, moduleLibInit, objCoreInit, qFifoInit, qPriBMapInit, qPriDeltaInit
 *           ...
 * Константы: 0x3011EA18
 * ---------------------------------------------------------------- */
undefined4 dllInit(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * dllTerminate @ 0x3011EA2C  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011EA2C
 * ---------------------------------------------------------------- */
undefined4 dllTerminate(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * dllCount @ 0x3011EA34  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 0
 * Вызывают: objInfo, qFifoInfo, qPriBMapInfo, qPriDeltaInfo, qPriListInfo, taskListCount
 * Константы: 0x3011EA34
 * ---------------------------------------------------------------- */
int dllCount(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
      param_1 = (undefined4 *)*param_1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * dllEach @ 0x3011EA58  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: moduleShow
 * Константы: 0x3011EA58
 * ---------------------------------------------------------------- */
undefined4 * dllEach(undefined4 *param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  
  param_1 = (undefined4 *)*param_1;
  while ((param_1 != (undefined4 *)0x0 && (iVar1 = (*param_2)(param_1,param_3), iVar1 != 0))) {
    param_1 = (undefined4 *)*param_1;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * lstLibInit @ 0x3011EAA4  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011EAA4
 * ---------------------------------------------------------------- */
void lstLibInit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * lstInit @ 0x3011EAA8  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 24 | Вызывает: 0
 * Вызывают: FUN_300f80cc, FUN_30100c70, FUN_301040fc, FUN_301044b0, FUN_30105988, FUN_3010be78, FUN_3010c4f0, FUN_301124fc, completionSymListGet, cplusMangledSymGet
 *           ...
 * Константы: 0x3011EAA8
 * ---------------------------------------------------------------- */
void lstInit(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

/* ----------------------------------------------------------------
 * lstInsert @ 0x3011EABC  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 0
 * Вызывают: FUN_301044b0, FUN_301123fc, ledHistoryLineAllocate, lstAdd
 * Константы: 0x3011EABC
 * ---------------------------------------------------------------- */
void lstInsert(int *param_1,int *param_2,int *param_3)

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
 * lstAdd @ 0x3011EAF4  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 34 | Вызывает: 1
 * Вызывает: lstInsert
 * Вызывают: FUN_300a03e0, FUN_300c9fc0, FUN_300ca508, FUN_300f7f08, FUN_300f84f8, FUN_30100868, FUN_30105988, FUN_30110184, FUN_30110f80, FUN_301123fc
 *           ...
 * Константы: 0x3011EAF4
 * ---------------------------------------------------------------- */
void lstAdd(int param_1,undefined4 param_2)

{
  lstInsert(param_1,*(undefined4 *)(param_1 + 4),param_2);
  return;
}

/* ----------------------------------------------------------------
 * lstConcat @ 0x3011EB08  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: lstInit
 * Константы: 0x3011EB08
 * ---------------------------------------------------------------- */
void lstConcat(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = param_2[2];
  if (iVar1 != 0) {
    if (param_1[2] == 0) {
      *param_1 = *param_2;
      param_1[1] = param_2[1];
    }
    else {
      iVar1 = param_1[2] + iVar1;
      *(int *)param_1[1] = *param_2;
      *(int *)(*param_2 + 4) = param_1[1];
      param_1[1] = param_2[1];
    }
    param_1[2] = iVar1;
    lstInit(param_2);
  }
  return;
}

/* ----------------------------------------------------------------
 * lstCount @ 0x3011EB70  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 27 | Вызывает: 0
 * Вызывают: FUN_300f7564, FUN_300f8b2c, FUN_300fee88, FUN_301040fc, completionPathComplete, completionPathShow, completionSymComplete, completionSymShow, cplusMatchMangledListGet, cplusUserAsk
 *           ...
 * Константы: 0x3011EB70
 * ---------------------------------------------------------------- */
undefined4 lstCount(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}

/* ----------------------------------------------------------------
 * lstDelete @ 0x3011EB78  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 30 | Вызывает: 0
 * Вызывают: FUN_300c9fc0, FUN_300f7564, FUN_30101228, FUN_301015b8, FUN_301040fc, FUN_3010c4f0, FUN_3010da44, FUN_30111020, FUN_30112e10, completionSymListGet
 *           ...
 * Константы: 0x3011EB78
 * ---------------------------------------------------------------- */
void lstDelete(int *param_1,int *param_2)

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
 * lstExtract @ 0x3011EBB0  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011EBB0
 * ---------------------------------------------------------------- */
void lstExtract(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  if ((int *)param_2[1] == (int *)0x0) {
    *param_1 = *param_3;
  }
  else {
    *(int *)param_2[1] = *param_3;
  }
  if (*param_3 == 0) {
    param_1[1] = param_2[1];
  }
  else {
    *(int *)(*param_3 + 4) = param_2[1];
  }
  *param_4 = (int)param_2;
  param_4[1] = (int)param_3;
  param_2[1] = 0;
  *param_3 = 0;
  iVar1 = 0;
  if (param_2 != (int *)0x0) {
    do {
      param_2 = (int *)*param_2;
      iVar1 = iVar1 + 1;
    } while (param_2 != (int *)0x0);
  }
  param_1[2] = param_1[2] - iVar1;
  param_4[2] = iVar1;
  return;
}

/* ----------------------------------------------------------------
 * lstFirst @ 0x3011EC28  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 78 | Вызывает: 0
 * Вызывают: FUN_300ca3dc, FUN_300ca570, FUN_300f7564, FUN_300f8488, FUN_300f84f8, FUN_300f8680, FUN_300f8a54, FUN_300fdaf4, FUN_300fe2bc, FUN_300fee88
 *           ...
 * Константы: 0x3011EC28
 * ---------------------------------------------------------------- */
undefined4 lstFirst(undefined4 *param_1)

{
  return *param_1;
}

/* ----------------------------------------------------------------
 * lstGet @ 0x3011EC30  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 0
 * Вызывают: FUN_300ca508, completionSymListGet, ledHistoryAdd, poolCreate, poolDelete, poolItemGet, symListGet
 * Константы: 0x3011EC30
 * ---------------------------------------------------------------- */
int lstGet(int *param_1)

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
    param_1[2] = param_1[2] + -1;
  }
  return (int)piVar1;
}

/* ----------------------------------------------------------------
 * lstLast @ 0x3011EC70  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 0
 * Вызывают: FUN_3010da44, ledHistFind, ledHistPrevGet, ledHistoryAdd
 * Константы: 0x3011EC70
 * ---------------------------------------------------------------- */
undefined4 lstLast(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}

/* ----------------------------------------------------------------
 * lstNext @ 0x3011EC78  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 70 | Вызывает: 0
 * Вызывают: FUN_300ca3dc, FUN_300ca570, FUN_300f7564, FUN_300f8488, FUN_300f84f8, FUN_300f8680, FUN_300f8a54, FUN_300fdaf4, FUN_300fe2bc, FUN_300fee88
 *           ...
 * Константы: 0x3011EC78
 * ---------------------------------------------------------------- */
undefined4 lstNext(undefined4 *param_1)

{
  return *param_1;
}

/* ----------------------------------------------------------------
 * lstNth @ 0x3011EC80  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 0
 * Вызывают: FUN_301040fc, FUN_301044b0, cplusMangledSymGet, ledHistFind, ledHistPrevGet, ledHistResize, ledHistoryAdd, ledHistoryClone
 * Константы: 0x3011EC80
 * ---------------------------------------------------------------- */
undefined4 * lstNth(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  if ((0 < param_2) && (iVar1 = param_1[2], param_2 <= iVar1)) {
    if (param_2 < iVar1 >> 1) {
      param_1 = (undefined4 *)*param_1;
      param_2 = param_2 + -1;
      if (0 < param_2) {
        do {
          param_1 = (undefined4 *)*param_1;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
    }
    else {
      param_1 = (undefined4 *)param_1[1];
      if (param_2 - iVar1 < 0) {
        iVar1 = -(param_2 - iVar1);
        do {
          param_1 = (undefined4 *)param_1[1];
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
    }
    return param_1;
  }
  return (undefined4 *)0x0;
}

/* ----------------------------------------------------------------
 * lstPrevious @ 0x3011ECF0  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: ledHistFind, ledHistPrevGet, ledHistoryLineAllocate
 * Константы: 0x3011ECF0
 * ---------------------------------------------------------------- */
undefined4 lstPrevious(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}

/* ----------------------------------------------------------------
 * lstNStep @ 0x3011ECF8  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: abs
 * Константы: 0x3011ECF8
 * ---------------------------------------------------------------- */
undefined4 * lstNStep(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = abs(param_2);
  if (0 < iVar1) {
    do {
      if (param_2 < 0) {
        param_1 = (undefined4 *)param_1[1];
      }
      else if (0 < param_2) {
        param_1 = (undefined4 *)*param_1;
      }
      if (param_1 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      iVar2 = iVar2 + 1;
      iVar1 = abs(param_2);
    } while (iVar2 < iVar1);
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * lstFind @ 0x3011ED54  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 9 | Вызывает: 0
 * Вызывают: FUN_30121580, ledHistFind, ledHistNextGet, ledHistoryClone, poolItemReturn, shellContextFinalize, shellInOutBlockingBlock, shellInOutRedirectRestore, shellInOutRedirectSet
 * Константы: 0x3011ED54
 * ---------------------------------------------------------------- */
int lstFind(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 1;
  for (param_1 = (int *)*param_1; (param_1 != (int *)0x0 && (param_1 != (int *)param_2));
      param_1 = (int *)*param_1) {
    iVar1 = iVar1 + 1;
  }
  if (param_1 == (int *)0x0) {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * lstFree2 @ 0x3011EDA0  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_30105988, FUN_30111bc8, lstFree, shellInternalOptGet, shellInterpDelete
 * Константы: 0x3011EDA0
 * ---------------------------------------------------------------- */
void lstFree2(int *param_1,code *param_2)

{
  int *piVar1;
  
  if (0 < param_1[2]) {
    piVar1 = (int *)*param_1;
    while (piVar1 != (int *)0x0) {
      piVar1 = (int *)*piVar1;
      (*param_2)();
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * lstFree @ 0x3011EDFC  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 9 | Вызывает: 1
 * Вызывает: lstFree2
 * Вызывают: FUN_300f7564, FUN_301040fc, FUN_301044b0, FUN_3010c4f0, cplusMangledSymGet, ledDfltComplete, ledHistoryFree, pipeDevDelete, shellCompletionPathnameGet
 * Константы: 0x3011EDFC
 * Данные: DAT_3011ee04
 * ---------------------------------------------------------------- */
void lstFree(undefined4 param_1)

{
  lstFree2(param_1,DAT_3011ee04);
  return;
}

/* ----------------------------------------------------------------
 * bootScanNum @ 0x301209D8  (примерный размер ~256 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 2
 * Вызывает: FUN_30120788, strncmp
 * Вызывают: FUN_3011e43c, FUN_3011e698, FUN_30120ad8, FUN_30120ec8
 * Константы: 0x301209D8, 0xFFFFFFFF
 * Данные: DAT_3012109c, DAT_301210a0, DAT_301210b0
 * ---------------------------------------------------------------- */
undefined4 bootScanNum(int *param_1,int *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__s1;
  byte *pbVar5;
  
  iVar4 = 0;
  FUN_30120788();
  __s1 = (char *)*param_1;
  if (*__s1 == '$') {
    iVar3 = 1;
  }
  else {
    iVar3 = strncmp(__s1,DAT_301210b0,2);
    if (iVar3 != 0) goto LAB_30120a30;
    iVar3 = 2;
  }
  *param_1 = (int)(__s1 + iVar3);
  param_3 = 1;
LAB_30120a30:
  for (pbVar5 = (byte *)*param_1; uVar1 = (uint)*pbVar5, uVar1 < 0x80; pbVar5 = pbVar5 + 1) {
    if ((*(byte *)(*DAT_3012109c + uVar1) & 4) == 0) {
      if (param_3 == 0) break;
      if ((*(byte *)(*DAT_3012109c + uVar1) & 1) != 0) {
        uVar1 = (uint)*(byte *)(*DAT_301210a0 + uVar1);
      }
      if (5 < uVar1 - 0x61) break;
      iVar3 = -0x57;
    }
    else {
      iVar3 = -0x30;
    }
    iVar2 = 10;
    if (param_3 != 0) {
      iVar2 = 0x10;
    }
    iVar4 = iVar4 * iVar2 + uVar1 + iVar3;
  }
  if ((byte *)*param_1 != pbVar5) {
    *param_1 = (int)pbVar5;
    FUN_30120788(param_1);
    *param_2 = iVar4;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_30120ad8 @ 0x30120AD8  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30120968, bootScanNum
 * Вызывают: bootStringToStructAdd
 * Константы: 0x30120AD8
 * ---------------------------------------------------------------- */
undefined4 FUN_30120ad8(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  char *local_b8;
  undefined4 local_b4;
  undefined4 uStack_b0;
  char local_ac [160];
  
  local_b8 = local_ac;
  local_b4 = *param_1;
  iVar1 = FUN_30120968(&local_b4,param_2,local_b8,0xa0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = bootScanNum(&local_b8,&uStack_b0,0);
    bVar3 = iVar1 == 0;
    if (bVar3) {
      bVar3 = *local_b8 == '\0';
    }
    if (bVar3) {
      uVar2 = 1;
      *param_1 = local_b4;
      *param_3 = uStack_b0;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * bootStringToStructAdd @ 0x30120B54  (примерный размер ~808 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_30120788, FUN_301207c8, FUN_3012084c, FUN_301208f4, FUN_30120968, FUN_30120ad8, index
 * Вызывают: bootStringToStruct
 * Константы: 0x30120B54
 * Данные: DAT_301210ac, DAT_301210b4, DAT_301210b8, DAT_301210bc, DAT_301210c0, DAT_301210c4, DAT_301210c8, DAT_301210cc
 * ---------------------------------------------------------------- */
char * bootStringToStructAdd(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *local_dc;
  char *local_d8;
  char acStack_d4 [180];
  
  local_dc = param_1;
  iVar2 = FUN_301207c8(&local_dc,param_2,0x28,DAT_301210b4);
  if ((((iVar2 != 0) && (iVar2 = FUN_3012084c(&local_dc,DAT_301210b8), iVar2 != 0)) &&
      (iVar2 = FUN_301208f4(&local_dc,param_2 + 0x2b0), iVar2 != 0)) &&
     (iVar2 = FUN_3012084c(&local_dc,DAT_301210bc), iVar2 != 0)) {
    iVar2 = FUN_301208f4(&local_dc,param_2 + 0x2a8);
    if ((iVar2 != 0) &&
       (iVar2 = FUN_3012084c(&local_dc,DAT_301210c0), pcVar1 = local_dc, iVar2 != 0)) {
      FUN_301207c8(&local_dc,acStack_d4,0xb4,DAT_301210ac);
      pcVar3 = index(acStack_d4,0x3a);
      if (pcVar3 != (char *)0x0) {
        local_d8 = acStack_d4;
        FUN_301207c8(&local_d8,param_2 + 0x28,0x14,DAT_301210c4);
        FUN_3012084c(&local_d8,DAT_301210c4);
        FUN_301207c8(&local_d8,param_2 + 0xf0,0xa0,DAT_301210ac);
        pcVar1 = local_dc;
      }
      local_dc = pcVar1;
      do {
        FUN_30120788(&local_dc);
        if (*local_dc == '\0') {
          return local_dc;
        }
        iVar2 = FUN_30120968(&local_dc,DAT_301210c8,param_2 + 0x50,0x32);
      } while ((((((iVar2 != 0) ||
                  (iVar2 = FUN_30120968(&local_dc,DAT_301210cc,param_2 + 0x50,0x32), iVar2 != 0)) ||
                 ((iVar2 = FUN_30120968(&local_dc,DAT_301210d0,param_2 + 0x82,0x32), iVar2 != 0 ||
                  ((((iVar2 = FUN_30120968(&local_dc,DAT_301210d4,param_2 + 0x82,0x32), iVar2 != 0
                     || (iVar2 = FUN_30120968(&local_dc,DAT_301210d8,param_2 + 0xb4,0x1e),
                        iVar2 != 0)) ||
                    (iVar2 = FUN_30120968(&local_dc,DAT_301210dc,param_2 + 0xb4,0x1e), iVar2 != 0))
                   || ((iVar2 = FUN_30120968(&local_dc,DAT_301210e0,param_2 + 0xd2,0x1e), iVar2 != 0
                       || (iVar2 = FUN_30120968(&local_dc,DAT_301210e4,param_2 + 0xd2,0x1e),
                          iVar2 != 0)))))))) ||
                (iVar2 = FUN_30120968(&local_dc,DAT_301210e8,param_2 + 0x230,0x14), iVar2 != 0)) ||
               (((iVar2 = FUN_30120968(&local_dc,DAT_301210ec,param_2 + 0x230,0x14), iVar2 != 0 ||
                 (iVar2 = FUN_30120968(&local_dc,DAT_301210f0,param_2 + 0x244,0x14), iVar2 != 0)) ||
                ((iVar2 = FUN_30120968(&local_dc,DAT_301210f4,param_2 + 600,0x50), iVar2 != 0 ||
                 (((iVar2 = FUN_30120968(&local_dc,DAT_301210f8,param_2 + 0x3c,0x14), iVar2 != 0 ||
                   (iVar2 = FUN_30120968(&local_dc,DAT_301210fc,param_2 + 0x28,0x14), iVar2 != 0))
                  || (iVar2 = FUN_30120968(&local_dc,DAT_30121100,param_2 + 0xf0,0xa0), iVar2 != 0))
                 )))))) ||
              (((iVar2 = FUN_30120968(&local_dc,DAT_30121104,param_2 + 400,0xa0), iVar2 != 0 ||
                (iVar2 = FUN_30120ad8(&local_dc,DAT_30121108,param_2 + 0x2a8), iVar2 != 0)) ||
               (iVar2 = FUN_30120ad8(&local_dc,DAT_3012110c,param_2 + 0x2ac), iVar2 != 0))));
    }
  }
  return local_dc;
}

/* ----------------------------------------------------------------
 * bootStringToStruct @ 0x30120E7C  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 2
 * Вызывает: bootStringToStructAdd, bzero
 * Вызывают: FUN_300e1550, bootParamsPrompt, bootParamsShow, usrBootLineCrack
 * Константы: 0x30120E7C
 * ---------------------------------------------------------------- */
void bootStringToStruct(undefined4 param_1,void *param_2)

{
  bzero(param_2,0x2b4);
  bootStringToStructAdd(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * bootParamsErrorPrint @ 0x30120EA4  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: bootParamsShow, usrBootLineCrack
 * Константы: 0x30120EA4
 * Данные: DAT_30121110
 * ---------------------------------------------------------------- */
void bootParamsErrorPrint(int param_1,int param_2)

{
  printf(DAT_30121110,param_1,(param_2 - param_1) + 1,0x5e);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30120ec8 @ 0x30120EC8  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: bootScanNum, index
 * Вызывают: bootBpAnchorExtract, bootLeaseExtract, bootNetmaskExtract
 * Константы: 0x30120EC8, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_30120ec8(char *param_1,undefined4 *param_2,int param_3)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uStack_14;
  char *local_4;
  
  local_4 = param_1;
  pcVar1 = index(param_1,param_3);
  if (pcVar1 == (char *)0x0) {
    uVar2 = 0;
  }
  else {
    local_4 = pcVar1 + 1;
    iVar3 = bootScanNum(&local_4,&uStack_14,1);
    if (iVar3 == 0) {
      *pcVar1 = '\0';
      uVar2 = 1;
      *param_2 = uStack_14;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * bootLeaseExtract @ 0x30120F38  (примерный размер ~228 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30120ec8, index
 * Константы: 0x30120F38
 * ---------------------------------------------------------------- */
int bootLeaseExtract(char *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  pcVar1 = index(param_1,0x3a);
  if (pcVar1 == (char *)0x0) {
    iVar2 = 0;
  }
  else {
    pcVar1 = index(pcVar1 + 1,0x3a);
    if (pcVar1 == (char *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar3 = FUN_30120ec8(pcVar1 + 1,&uStack_1c,0x3a);
      if ((iVar3 == 1) && (param_3 != (undefined4 *)0x0)) {
        *param_3 = uStack_1c;
      }
      pcVar1 = index(param_1,0x3a);
      if (pcVar1 == (char *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_30120ec8(pcVar1 + 1,&uStack_18,0x3a);
        if ((iVar2 == 1) && (param_2 != (undefined4 *)0x0)) {
          *param_2 = uStack_18;
        }
        if (iVar3 != 0) {
          if ((iVar3 < 0) || (iVar2 < 0)) {
            iVar2 = -2;
          }
          else {
            iVar2 = 2;
          }
        }
      }
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * bootNetmaskExtract @ 0x3012101C  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_30120788, FUN_30120ec8, index
 * Константы: 0x3012101C
 * ---------------------------------------------------------------- */
undefined4 bootNetmaskExtract(char *param_1,undefined4 *param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  char *local_14;
  
  pcVar1 = index(param_1,0x3a);
  if (pcVar1 == (char *)0x0) {
    uVar2 = 0;
  }
  else {
    local_14 = pcVar1 + 1;
    FUN_30120788(&local_14);
    if (*local_14 == ':' || *local_14 == '\0') {
      *pcVar1 = '\0';
      *param_2 = 0;
      uVar2 = 1;
    }
    else {
      uVar2 = FUN_30120ec8(param_1,param_2,0x3a);
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * bootBpAnchorExtract @ 0x30121094  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_30120ec8
 * Константы: 0x30121094
 * ---------------------------------------------------------------- */
void bootBpAnchorExtract(undefined4 param_1,undefined4 param_2)

{
  FUN_30120ec8(param_1,param_2,0x3d);
  return;
}

/* ----------------------------------------------------------------
 * eventLibInit @ 0x30121AA0  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrKernelCoreInit
 * Константы: 0x30121AA0
 * Данные: DAT_30122294, DAT_30122298, DAT_3012229c, DAT_301222a0, DAT_301222a4, DAT_301222a8, DAT_301222ac, DAT_301222b0
 * ---------------------------------------------------------------- */
void eventLibInit(uint param_1)

{
  *DAT_30122298 = DAT_30122294;
  *DAT_301222a0 = DAT_3012229c;
  *DAT_301222a8 = DAT_301222a4;
  *DAT_301222b0 = DAT_301222ac;
  *DAT_301222b8 = DAT_301222b4;
  if ((param_1 & 1) == 0) {
    return;
  }
  *(undefined4 *)(DAT_301222bc + 8) = 1;
  return;
}

/* ----------------------------------------------------------------
 * eventInit @ 0x30121AF4  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30121AF4
 * ---------------------------------------------------------------- */
void eventInit(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  return;
}

/* ----------------------------------------------------------------
 * eventTerminate @ 0x30121B08  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: objVerify, taskRtnValueSet, windPendQRemove, windReadyQPut
 * Константы: 0x30121B08, 0xFFFFFFFF
 * Данные: DAT_301222c0, DAT_301222c4, DAT_301222c8
 * ---------------------------------------------------------------- */
void eventTerminate(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 == 0) {
    return;
  }
  iVar2 = objVerify(iVar3,*DAT_301222c0);
  iVar1 = DAT_301222c4;
  if ((iVar2 == 0) && ((*(byte *)(iVar3 + 0x12d) & 1) != 0)) {
    *(byte *)(iVar3 + 0x12d) = *(byte *)(iVar3 + 0x12d) & 0xfe;
    if ((*(uint *)(iVar3 + 0x70) & 2) == 0) {
      *(byte *)(iVar3 + iVar1) = *(byte *)(iVar3 + iVar1) | 2;
    }
    else {
      windPendQRemove(iVar3);
      windReadyQPut(iVar3);
      taskRtnValueSet(iVar3,0xffffffff);
      *(undefined4 *)(iVar3 + 0xd0) = DAT_301222c8;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * eventReceive @ 0x30121BAC  (примерный размер ~864 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: __errno, errnoSet, windExit, windPendQPut
 * Вызывают: BSP_TLED_LedTask
 * Константы: 0x30121BAC
 * Данные: DAT_301222bc, DAT_301222c4, DAT_301222c8, DAT_301222cc, DAT_301222d0, DAT_301222d4, DAT_301222d8, DAT_301222dc
 * ---------------------------------------------------------------- */
int eventReceive(uint param_1,byte param_2,int param_3,uint *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_4;
  
  if (*DAT_301222cc < 1) {
    iVar3 = *DAT_301222d4;
    if ((param_2 & 0x80) == 0) {
      if (param_1 != 0) {
        local_4 = param_3;
        while( true ) {
          do {
            uVar5 = *(uint *)(iVar3 + 0x128);
            if ((param_2 & 1) == 0) {
              if ((param_1 & uVar5) == param_1) {
                if (param_4 != (uint *)0x0) {
                  if ((param_2 & 2) == 0) {
                    *param_4 = param_1;
                  }
                  else {
                    *param_4 = *(uint *)(iVar3 + 0x128);
                  }
                }
                if (((param_2 & 4) == 0) || ((param_2 & 2) != 0)) {
                  *(undefined4 *)(iVar3 + 0x128) = 0;
                }
                else {
                  *(uint *)(iVar3 + 0x128) = *(uint *)(iVar3 + 0x128) & ~param_1;
                }
                return 0;
              }
            }
            else if ((param_1 & uVar5) != 0) {
              if (param_4 != (uint *)0x0) {
                if ((param_2 & 2) == 0) {
                  *param_4 = param_1 & *(uint *)(iVar3 + 0x128);
                }
                else {
                  *param_4 = *(uint *)(iVar3 + 0x128);
                }
              }
              if (((param_2 & 4) == 0) || ((param_2 & 2) != 0)) {
                *(undefined4 *)(iVar3 + 0x128) = 0;
              }
              else {
                *(uint *)(iVar3 + 0x128) = *(uint *)(iVar3 + 0x128) & ~param_1;
              }
              return 0;
            }
          } while (*(uint *)(iVar3 + 0x128) != uVar5);
          if (local_4 == 0) {
            if (param_4 != (uint *)0x0) {
              if ((param_2 & 2) == 0) {
                *param_4 = param_1 & uVar5;
              }
              else {
                *param_4 = uVar5;
              }
            }
            if (((param_2 & 4) == 0) || ((param_2 & 2) != 0)) {
              *(undefined4 *)(iVar3 + 0x128) = 0;
            }
            else {
              *(uint *)(iVar3 + 0x128) = *(uint *)(iVar3 + 0x128) & ~param_1;
            }
            errnoSet(DAT_301222dc);
            return -1;
          }
          *(byte *)(iVar3 + 300) = param_2;
          *(uint *)(iVar3 + 0x124) = param_1;
          iVar1 = DAT_301222c4;
          *(undefined1 *)(iVar3 + DAT_301222c4) = 1;
          *DAT_301222e0 = 1;
          iVar4 = windPendQPut(DAT_301222bc,local_4);
          if (iVar4 == -1) break;
          iVar4 = windExit();
          if (iVar4 != 1) {
            if ((iVar4 == -1) && (*(int *)(iVar3 + 0xd0) == DAT_301222e8)) {
              errnoSet(DAT_301222ec);
            }
            goto LAB_30121e8c;
          }
          *(byte *)(iVar3 + iVar1) = *(byte *)(iVar3 + iVar1) & 0xfe;
          if ((*(byte *)(iVar3 + iVar1) & 2) != 0) {
            *(byte *)(iVar3 + iVar1) = *(byte *)(iVar3 + iVar1) & 0xfd;
            iVar4 = -1;
            errnoSet(DAT_301222c8);
            goto LAB_30121e8c;
          }
          local_4 = (*(code *)*DAT_301222e4)(local_4);
        }
        windExit();
        iVar4 = -1;
LAB_30121e8c:
        *(byte *)(iVar3 + iVar1) = *(byte *)(iVar3 + iVar1) & 0xfe;
        if (param_4 != (uint *)0x0) {
          if ((param_2 & 2) == 0) {
            *param_4 = param_1 & *(uint *)(iVar3 + 0x128);
          }
          else {
            *param_4 = *(uint *)(iVar3 + 0x128);
          }
        }
        if (((param_2 & 4) != 0) && ((param_2 & 2) == 0)) {
          *(uint *)(iVar3 + 0x128) = *(uint *)(iVar3 + 0x128) & ~param_1;
          return iVar4;
        }
        *(undefined4 *)(iVar3 + 0x128) = 0;
        return iVar4;
      }
      errnoSet(DAT_301222d8);
      iVar3 = -1;
    }
    else {
      if (param_4 != (uint *)0x0) {
        *param_4 = *(uint *)(iVar3 + 0x128);
      }
      iVar3 = 0;
    }
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_301222d0;
    iVar3 = -1;
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * eventSend @ 0x30121F0C  (примерный размер ~336 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 7
 * Вызывает: errnoSet, intCpuUnlock, objVerify, windExit, windPendQRemove, windReadyQPut, workQAdd1
 * Вызывают: BSP_TLED_LedCallback, BSP_TLED_LedFlush, eventStart
 * Константы: 0xFFFFFFFF, 0x30121F0C
 * Данные: DAT_301222c0, DAT_301222c4, DAT_301222cc, DAT_301222d4, DAT_301222e0, DAT_301222f0, DAT_301222f4
 * ---------------------------------------------------------------- */
undefined4 eventSend(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  byte in_Q;
  
  bVar4 = param_1 < 0;
  bVar3 = param_1 == 0;
  if (param_1 == 0) {
    bVar4 = false;
    if (*DAT_301222cc >= 1) {
      errnoSet(DAT_301222f0);
      return 0xffffffff;
    }
    param_1 = *DAT_301222d4;
    bVar3 = *DAT_301222cc < 1;
  }
  iVar1 = objVerify(param_1,*DAT_301222c0);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x128) = param_2 | *(uint *)(param_1 + 0x128);
  if ((*(byte *)(param_1 + 0x12d) & 1) == 0) {
    return 0;
  }
  uVar2 = *(uint *)(param_1 + 0x124);
  if (((uVar2 & *(uint *)(param_1 + 0x128)) == uVar2) ||
     (((*(byte *)(param_1 + 300) & 1) == 1 && ((uVar2 & *(uint *)(param_1 + 0x128)) != 0)))) {
    *(byte *)(param_1 + DAT_301222c4) = *(byte *)(param_1 + 0x12d) & 0xfe;
    if (*DAT_301222e0 == 1) {
      intCpuUnlock((uint)(byte)(bVar4 << 4 | bVar3 << 3 | 4U | in_Q) << 0x1b);
      workQAdd1(DAT_301222f4,param_1);
      return 0;
    }
    if ((*(uint *)(param_1 + 0x70) & 2) != 0) {
      *DAT_301222e0 = 1;
      windPendQRemove(param_1);
      windReadyQPut(param_1);
      windExit();
      return 0;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3012205c @ 0x3012205C  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: windPendQRemove, windReadyQPut
 * Константы: 0x3012205C
 * ---------------------------------------------------------------- */
void FUN_3012205c(int param_1)

{
  if ((*(uint *)(param_1 + 0x70) & 2) == 0) {
    return;
  }
  windPendQRemove();
  windReadyQPut(param_1);
  return;
}

/* ----------------------------------------------------------------
 * eventRsrcSend @ 0x30122080  (примерный размер ~216 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: objVerify, windPendQRemove, windReadyQPut
 * Константы: 0x30122080, 0xFFFFFFFF
 * Данные: DAT_301222c0, DAT_301222c4
 * ---------------------------------------------------------------- */
undefined4 eventRsrcSend(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = objVerify(param_1,*DAT_301222c0);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x128) = param_2 | *(uint *)(param_1 + 0x128);
  if ((*(byte *)(param_1 + 0x12d) & 1) == 0) {
    return 0;
  }
  uVar2 = *(uint *)(param_1 + 0x124);
  if (((uVar2 & *(uint *)(param_1 + 0x128)) == uVar2) ||
     (((*(byte *)(param_1 + 300) & 1) == 1 && ((uVar2 & *(uint *)(param_1 + 0x128)) != 0)))) {
    *(byte *)(param_1 + DAT_301222c4) = *(byte *)(param_1 + 0x12d) & 0xfe;
    if ((*(uint *)(param_1 + 0x70) & 2) != 0) {
      windPendQRemove(param_1);
      windReadyQPut(param_1);
      return 0;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * eventClear @ 0x30122158  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __errno
 * Константы: 0x30122158, 0xFFFFFFFF
 * Данные: DAT_301222cc, DAT_301222d0, DAT_301222d4
 * ---------------------------------------------------------------- */
undefined4 eventClear(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (*DAT_301222cc < 1) {
    uVar2 = 0;
    *(undefined4 *)(*DAT_301222d4 + 0x128) = 0;
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_301222d0;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * eventStart @ 0x30122194  (примерный размер ~364 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: errnoSet, eventSend, taskCpuUnlock
 * Вызывают: msgQEvStart, semEvStart
 * Константы: 0xFFFFFFFF, 0x30122194
 * Данные: DAT_301222d4, DAT_301222f8, DAT_301222fc
 * ---------------------------------------------------------------- */
undefined4
eventStart(undefined4 param_1,undefined4 *param_2,code *param_3,undefined4 param_4,byte param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  byte in_Q;
  
  uVar3 = *DAT_301222d4;
  uVar4 = *(byte *)(param_2 + 2) & 2;
  bVar7 = 1 < uVar4;
  bVar8 = SBORROW4(uVar4,2);
  bVar5 = (int)(uVar4 - 2) < 0;
  bVar6 = uVar4 == 2;
  if (!bVar6) {
    uVar4 = param_2[1];
    bVar5 = (int)uVar4 < 0;
    bVar6 = uVar4 == 0;
    bVar7 = true;
    bVar8 = false;
    if (!bVar6) {
      bVar7 = uVar3 <= uVar4;
      bVar8 = SBORROW4(uVar4,uVar3);
      bVar5 = (int)(uVar4 - uVar3) < 0;
      bVar6 = uVar4 == uVar3;
      if (!bVar6) {
        taskCpuUnlock();
        errnoSet(DAT_301222f8);
        return 0xffffffff;
      }
    }
  }
  if (((param_5 & 4) == 4) &&
     (iVar1 = (*param_3)(param_1,(uint)(byte)(bVar5 << 4 | bVar6 << 3 | bVar7 << 2 | bVar8 << 1 |
                                             in_Q) << 0x1b | 0x80), iVar1 != 0)) {
    if ((param_5 & 1) == 1) {
      param_2[1] = 0;
    }
    else {
      *param_2 = param_4;
      *(byte *)(param_2 + 2) = param_5;
      param_2[1] = uVar3;
    }
    taskCpuUnlock();
    iVar1 = eventSend(uVar3,param_4);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      errnoSet(DAT_301222fc);
      uVar2 = 0xffffffff;
    }
  }
  else {
    *param_2 = param_4;
    *(byte *)(param_2 + 2) = param_5;
    param_2[1] = uVar3;
    taskCpuUnlock();
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * eventTaskShow @ 0x30122300  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: printf, puts
 * Вызывают: taskShow
 * Константы: 0x30122300
 * Данные: DAT_30122428, DAT_3012242c, DAT_30122430, DAT_30122434, DAT_30122438, DAT_3012243c, DAT_30122440
 * ---------------------------------------------------------------- */
undefined4 eventTaskShow(undefined4 *param_1)

{
  char *__s;
  
  puts(DAT_30122428);
  if ((*(byte *)((int)param_1 + 9) & 1) == 0) {
    printf(DAT_3012242c,param_1[1]);
  }
  else {
    printf(DAT_30122430,*param_1,param_1[1],(uint)*(byte *)(param_1 + 2));
    __s = DAT_30122434;
    if ((*(byte *)(param_1 + 2) & 1) != 0) {
      __s = DAT_30122438;
    }
    puts(__s);
    if ((*(byte *)(param_1 + 2) & 2) != 0) {
      puts(DAT_3012243c);
    }
    if ((*(byte *)(param_1 + 2) & 4) != 0) {
      puts(DAT_30122440);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * eventRsrcShow @ 0x30122384  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: printf, puts, taskName
 * Константы: 0x30122384
 * Данные: DAT_30122428, DAT_30122444, DAT_30122448, DAT_3012244c, DAT_30122450, DAT_30122454, DAT_30122458, DAT_3012245c
 * ---------------------------------------------------------------- */
undefined4 eventRsrcShow(undefined4 *param_1)

{
  int iVar1;
  char *__s;
  
  puts(DAT_30122428);
  __s = DAT_30122444;
  if (param_1[1] != 0) {
    iVar1 = taskName(param_1[1]);
    if (iVar1 == 0) {
      iVar1 = DAT_30122448;
    }
    printf(DAT_3012244c,param_1[1],iVar1,*param_1,(uint)*(byte *)(param_1 + 2));
    __s = DAT_30122450;
    if (*(byte *)(param_1 + 2) != 0) {
      if ((*(byte *)(param_1 + 2) & 1) != 0) {
        printf(DAT_30122454);
      }
      if ((*(byte *)(param_1 + 2) & 2) != 0) {
        printf(DAT_30122458);
      }
      __s = DAT_3012245c;
      if ((*(byte *)(param_1 + 2) & 4) == 0) {
        return 0;
      }
    }
  }
  puts(__s);
  return 0;
}

/* ----------------------------------------------------------------
 * exit @ 0x301291C4  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 3
 * Вызывает: taskCpuLock, taskCpuUnlock, taskDestroy
 * Вызывают: FUN_30106540, FUN_30110e10, abort, sdmmcHookTask, shellExitWrapper
 * Константы: 0x301291C4, 0xFFFFFFFF
 * Данные: DAT_301292dc, DAT_301292e0
 * ---------------------------------------------------------------- */
void exit(int __status)

{
  int *piVar1;
  
  piVar1 = DAT_301292dc;
  *(int *)(*DAT_301292dc + 0xd4) = __status;
  taskCpuLock();
  *(uint *)(*piVar1 + 0x98) = *(uint *)(*piVar1 + 0x98) | 2;
  if ((code *)*DAT_301292e0 != (code *)0x0) {
    (*(code *)*DAT_301292e0)();
  }
  taskCpuUnlock();
  taskDestroy(0,1,0xffffffff,0);
  return;
}

/* ----------------------------------------------------------------
 * _taskSuspend @ 0x30129A1C  (примерный размер ~528 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: __errno, objVerify, windExit, windPendQFlush, windPendQPut, windSuspend, workQAdd1
 * Вызывают: taskSuspend
 * Константы: 0xFFFFFFFF, 0x30129A1C
 * Данные: DAT_3012a2a4, DAT_3012a2c0, DAT_3012a3f4, DAT_3012a400, DAT_3012a410, DAT_3012a418, DAT_3012a41c
 * ---------------------------------------------------------------- */
undefined4 _taskSuspend(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    param_1 = *DAT_3012a2c0;
  }
  if (*DAT_3012a410 == 1) {
    if ((param_1 != 0) && (iVar1 = objVerify(param_1,*DAT_3012a2a4), iVar1 == 0)) {
      workQAdd1(DAT_3012a418,param_1);
      return 0;
    }
    return 0xffffffff;
  }
  if (((*DAT_3012a3f4 < 1) && (*(int *)(*DAT_3012a2c0 + 0x94) != *DAT_3012a400)) && (param_2 == 0))
  {
    do {
      puVar2 = DAT_3012a2a4;
      iVar1 = objVerify(param_1,*DAT_3012a2a4);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      while( true ) {
        if ((*(int *)(param_1 + 0xac) == 0) &&
           ((*(int *)(param_1 + 0x70) != 0 || (*(int *)(param_1 + 0x7c) == 0)))) {
          *DAT_3012a410 = 1;
          goto LAB_30129c18;
        }
        *DAT_3012a410 = 1;
        if (*DAT_3012a2c0 == param_1) {
          *(undefined4 *)(param_1 + 0xac) = 0;
          *(undefined4 *)(param_1 + 0x7c) = 0;
          if (*(int *)(param_1 + 0xb0) != 0) {
            windPendQFlush(param_1 + 0xb0);
          }
        }
        else {
          iVar1 = windPendQPut(param_1 + 0xb0,0xffffffff);
          if (iVar1 != 0) {
            windExit();
            return 0xffffffff;
          }
        }
        iVar1 = windExit();
        if (iVar1 == -1) {
          return 0xffffffff;
        }
        if (iVar1 == 1) break;
        iVar1 = objVerify(param_1,*puVar2);
        if (iVar1 != 0) {
          puVar2 = (undefined4 *)__errno();
          *puVar2 = DAT_3012a41c;
          return 0xffffffff;
        }
      }
    } while( true );
  }
  *DAT_3012a410 = 1;
  iVar1 = objVerify(param_1,*DAT_3012a2a4);
  if (iVar1 != 0) {
    windExit();
    return 0xffffffff;
  }
LAB_30129c18:
  windSuspend(param_1);
  windExit();
  return 0;
}

/* ----------------------------------------------------------------
 * regsShowOutput @ 0x3012B4A8  (примерный размер ~208 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: __rem32, oprintf
 * Вызывают: regsShow, taskRegsShow
 * Константы: 0x3012B4A8
 * Данные: DAT_3012b9f4, DAT_3012ba30, DAT_3012ba34, DAT_3012ba38, DAT_3012ba3c, DAT_3012ba40
 * ---------------------------------------------------------------- */
void regsShowOutput(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = *DAT_3012ba30;
  piVar4 = DAT_3012ba30;
  while (iVar5 != 0) {
    iVar5 = __rem32(iVar3,3);
    if (iVar5 == 0) {
      oprintf(param_2,param_3,DAT_3012ba34);
    }
    else {
      oprintf(param_2,param_3,DAT_3012ba38,DAT_3012b9f4);
    }
    uVar1 = DAT_3012ba40;
    pcVar2 = DAT_3012b9f4;
    if (*(char *)*piVar4 != '\0') {
      uVar1 = *DAT_3012ba3c;
      pcVar2 = (char *)*piVar4;
    }
    oprintf(param_2,param_3,uVar1,pcVar2);
    piVar4 = piVar4 + 2;
    iVar3 = iVar3 + 1;
    iVar5 = *piVar4;
  }
  oprintf(param_2,param_3,DAT_3012ba34);
  return;
}

/* ----------------------------------------------------------------
 * regsShow @ 0x3012B578  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: regsShowOutput
 * Константы: 0x3012B578
 * ---------------------------------------------------------------- */
void regsShow(undefined4 param_1)

{
  regsShowOutput(param_1,0,0);
  return;
}

/* ----------------------------------------------------------------
 * tickAnnounce @ 0x3012BAC4  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: windExit, windTickAnnounce, workQAdd0
 * Константы: 0x3012BAC4
 * Данные: DAT_3012bbc4, DAT_3012bbc8
 * ---------------------------------------------------------------- */
void tickAnnounce(void)

{
  if (*DAT_3012bbc4 == 1) {
    workQAdd0(DAT_3012bbc8);
  }
  else {
    *DAT_3012bbc4 = 1;
    windTickAnnounce();
    windExit();
  }
  return;
}

/* ----------------------------------------------------------------
 * tickSet @ 0x3012BAFC  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012BAFC
 * Данные: DAT_3012bbcc
 * ---------------------------------------------------------------- */
undefined4 tickSet(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_3012bbcc;
  *DAT_3012bbcc = param_1;
  puVar1[1] = 0;
  return param_1;
}

/* ----------------------------------------------------------------
 * tickGet @ 0x3012BB30  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 20 | Вызывает: 0
 * Вызывают: FUN_300f687c, HI6451_record_startflag_save, TFUP_CheckFileValidify, TFUP_CheckTask, TFUP_CheckVersionMatch, TFUP_DloadTask, TFUP_GetAllFileName, TFUP_GetUnitData, TFUP_GetUnitHeadData, TFUP_IdentifyFile
 *           ...
 * Константы: 0x3012BB30
 * Данные: DAT_3012bbcc
 * ---------------------------------------------------------------- */
undefined4 tickGet(void)

{
  return *DAT_3012bbcc;
}

/* ----------------------------------------------------------------
 * tick64Set @ 0x3012BB3C  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012BB3C
 * Данные: DAT_3012bbcc
 * ---------------------------------------------------------------- */
void tick64Set(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_3012bbcc;
  *DAT_3012bbcc = param_1;
  puVar1[1] = param_2;
  return;
}

/* ----------------------------------------------------------------
 * tick64Get @ 0x3012BB6C  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012BB6C
 * Данные: DAT_3012bbcc
 * ---------------------------------------------------------------- */
undefined8 tick64Get(void)

{
  return *DAT_3012bbcc;
}

/* ----------------------------------------------------------------
 * tickAnnounceHookAdd @ 0x3012BB9C  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: kernelTimeSlice
 * Константы: 0x3012BB9C, 0xFFFFFFFF
 * Данные: DAT_3012bbd0
 * ---------------------------------------------------------------- */
undefined4 tickAnnounceHookAdd(int param_1)

{
  if (*DAT_3012bbd0 == 0) {
    *DAT_3012bbd0 = param_1;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * wdCreateLibInit @ 0x3012BBD4  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrKernelCoreInit
 * Константы: 0x3012BBD4
 * Данные: DAT_3012bd24, DAT_3012bd28
 * ---------------------------------------------------------------- */
void wdCreateLibInit(void)

{
  *(undefined4 *)(*DAT_3012bd24 + 0x14) = DAT_3012bd28;
  return;
}

/* ----------------------------------------------------------------
 * wdCreate @ 0x3012BBE8  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: objAlloc, objFree, wdInit
 * Константы: 0x3012BBE8
 * Данные: DAT_3012bd24
 * ---------------------------------------------------------------- */
int wdCreate(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = objAlloc(*DAT_3012bd24);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = wdInit(iVar1);
  if (iVar2 != 0) {
    objFree(*DAT_3012bd24,iVar1);
    return 0;
  }
  *(ushort *)(iVar1 + 8) = *(ushort *)(iVar1 + 8) | 2;
  return iVar1;
}

/* ----------------------------------------------------------------
 * wdDestroy @ 0x3012BC48  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 9
 * Вызывает: __errno, intContext, objCoreInvalidate, objCoreTerminate, objFree, objVerify, taskUnsafe, windExit, windWdCancel
 * Вызывают: wdDelete, wdTerminate
 * Константы: 0xFFFFFFFF, 0x3012BC48
 * Данные: DAT_3012bd24, DAT_3012bd2c, DAT_3012bd30, DAT_3012bd34
 * ---------------------------------------------------------------- */
undefined4 wdDestroy(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = intContext();
  puVar2 = DAT_3012bd24;
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_3012bd2c;
    return 0xffffffff;
  }
  iVar1 = objVerify(param_1,*DAT_3012bd24);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  objCoreInvalidate(param_1);
  *DAT_3012bd30 = 1;
  windWdCancel(param_1);
  *(undefined2 *)(param_1 + 0x50) = 2;
  *(int *)(*DAT_3012bd34 + 0xac) = *(int *)(*DAT_3012bd34 + 0xac) + 1;
  windExit();
  objCoreTerminate(param_1);
  if (param_2 != 0) {
    objFree(*puVar2,param_1);
  }
  taskUnsafe();
  return 0;
}

/* ----------------------------------------------------------------
 * wdDelete @ 0x3012BD14  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: wdDestroy
 * Константы: 0x3012BD14
 * ---------------------------------------------------------------- */
void wdDelete(undefined4 param_1)

{
  wdDestroy(param_1,1);
  return;
}

/* ----------------------------------------------------------------
 * wdTerminate @ 0x3012BD1C  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: wdDestroy
 * Константы: 0x3012BD1C
 * ---------------------------------------------------------------- */
void wdTerminate(undefined4 param_1)

{
  wdDestroy(param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * wdLibInit @ 0x3012BD38  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: classInit
 * Вызывают: usrKernelCoreInit
 * Константы: 0x3012BD38
 * Данные: DAT_3012bf48
 * ---------------------------------------------------------------- */
void wdLibInit(void)

{
  classInit(*DAT_3012bf48,0x5c,0,0,0,0,0,0,7,0);
  return;
}

/* ----------------------------------------------------------------
 * wdInit @ 0x3012BD80  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: objCoreInit
 * Вызывают: wdCreate
 * Константы: 0x3012BD80
 * Данные: DAT_3012bf48
 * ---------------------------------------------------------------- */
undefined4 wdInit(int param_1)

{
  *(undefined2 *)(param_1 + 0x50) = 0;
  *(undefined2 *)(param_1 + 0x52) = 0;
  objCoreInit(param_1,*DAT_3012bf48);
  return 0;
}

/* ----------------------------------------------------------------
 * wdInitialize @ 0x3012BDA4  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: objCoreInit
 * Константы: 0x3012BDA4
 * Данные: DAT_3012bf48
 * ---------------------------------------------------------------- */
int wdInitialize(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  *(undefined2 *)(param_1 + 0x50) = 0;
  *(undefined2 *)(param_1 + 0x52) = 0;
  objCoreInit(param_1,*DAT_3012bf48);
  return param_1;
}

/* ----------------------------------------------------------------
 * wdStart @ 0x3012BDD8  (примерный размер ~208 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: objVerify, windExit, windWdStart, workQAdd2
 * Константы: 0xFFFFFFFF, 0x3012BDD8
 * Данные: DAT_3012bf48, DAT_3012bf4c, DAT_3012bf50
 * ---------------------------------------------------------------- */
undefined4 wdStart(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = objVerify(param_1,*DAT_3012bf48);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (*DAT_3012bf4c == 1) {
    *(short *)(param_1 + 0x52) = *(short *)(param_1 + 0x52) + 1;
    *(undefined4 *)(param_1 + 0x58) = param_4;
    *(undefined4 *)(param_1 + 0x54) = param_3;
    workQAdd2(DAT_3012bf50,param_1,param_2);
    return 0;
  }
  *(undefined2 *)(param_1 + 0x52) = 1;
  *(undefined4 *)(param_1 + 0x58) = param_4;
  *(undefined4 *)(param_1 + 0x54) = param_3;
  *DAT_3012bf4c = 1;
  iVar1 = windWdStart(param_1,param_2);
  if (iVar1 != 0) {
    windExit();
    return 0xffffffff;
  }
  windExit();
  return 0;
}

/* ----------------------------------------------------------------
 * wdCancel @ 0x3012BEA8  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: objVerify, windExit, windWdCancel, workQAdd1
 * Константы: 0xFFFFFFFF, 0x3012BEA8
 * Данные: DAT_3012bf48, DAT_3012bf4c, DAT_3012bf54
 * ---------------------------------------------------------------- */
undefined4 wdCancel(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_3012bf4c;
  if (*DAT_3012bf4c != 1) {
    iVar2 = objVerify(param_1,*DAT_3012bf48);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    *piVar1 = 1;
    windWdCancel(param_1);
    windExit();
    return 0;
  }
  iVar2 = objVerify(param_1,*DAT_3012bf48);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  workQAdd1(DAT_3012bf54,param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * wdTick @ 0x3012BF44  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012BF44
 * ---------------------------------------------------------------- */
void wdTick(void)

{
  return;
}

/* ----------------------------------------------------------------
 * windPendQRemove @ 0x3012BF58  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 0
 * Вызывают: FUN_3012205c, eventRsrcSend, eventSend, eventTerminate, taskDestroy, taskReset, windDelete, windTickAnnounce
 * Константы: 0x3012BF58, 0xFFFFFFFD, 0xFFFFFFF9
 * Данные: DAT_3012cdf8
 * ---------------------------------------------------------------- */
undefined4 windPendQRemove(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0xa8) + 0xc) + 0x18))
                    (*(int *)(param_1 + 0xa8),param_1 + 0x50);
  uVar2 = *(uint *)(param_1 + 0x70);
  *(uint *)(param_1 + 0x70) = uVar2 & 0xfffffffd;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  if ((uVar2 & 4) != 0) {
    *(uint *)(param_1 + 0x70) = uVar2 & 0xfffffff9;
    (**(code **)(*(int *)(DAT_3012cdf8 + 0xc) + 0x18))(DAT_3012cdf8,param_1 + 0x40);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * windDelete @ 0x3012BFCC  (примерный размер ~224 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: windPendQRemove
 * Вызывают: FUN_30128940
 * Константы: 0x3012BFCC
 * Данные: DAT_3012cdf8, DAT_3012cdfc, DAT_3012ce00
 * ---------------------------------------------------------------- */
undefined4 windDelete(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = 0;
  if (*(uint *)(param_1 + 0x70) == 0) {
    iVar1 = param_1 + 0x50;
    iVar2 = DAT_3012cdfc;
  }
  else {
    if ((*(uint *)(param_1 + 0x70) & 2) != 0) {
      uVar3 = windPendQRemove(param_1);
    }
    if ((*(uint *)(param_1 + 0x70) & 4) == 0) goto LAB_3012c030;
    iVar1 = param_1 + 0x40;
    iVar2 = DAT_3012cdf8;
  }
  (**(code **)(*(int *)(iVar2 + 0xc) + 0x18))(iVar2,iVar1);
LAB_3012c030:
  iVar2 = 0;
  for (uVar4 = (uint)*(ushort *)(param_1 + 0xa4); uVar4 != 0; uVar4 = uVar4 >> 1) {
    if ((uVar4 & 1) != 0) {
      *(int *)(DAT_3012ce00 + iVar2 * 4) = *(int *)(DAT_3012ce00 + iVar2 * 4) + -1;
    }
    iVar2 = iVar2 + 1;
  }
  iVar2 = 0;
  for (uVar4 = (uint)*(ushort *)(param_1 + 0xa6); uVar4 != 0; uVar4 = uVar4 >> 1) {
    if ((uVar4 & 1) != 0) {
      *(int *)(DAT_3012ce00 + iVar2 * 4) = *(int *)(DAT_3012ce00 + iVar2 * 4) + -1;
    }
    iVar2 = iVar2 + 1;
  }
  *(undefined4 *)(param_1 + 0x70) = 8;
  return uVar3;
}

/* ----------------------------------------------------------------
 * windSuspend @ 0x3012C0AC  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 0
 * Вызывают: FUN_30128940, _taskSuspend, taskDestroy, taskReset
 * Константы: 0x3012C0AC
 * Данные: DAT_3012cdfc
 * ---------------------------------------------------------------- */
void windSuspend(int param_1)

{
  if (*(int *)(param_1 + 0x70) == 0) {
    (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x18))(DAT_3012cdfc,param_1 + 0x50);
  }
  *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 1;
  return;
}

/* ----------------------------------------------------------------
 * windResume @ 0x3012C0F0  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: taskActivate, taskResume
 * Константы: 0x3012C0F0, 0xFFFFFFFE
 * Данные: DAT_3012cdfc
 * ---------------------------------------------------------------- */
void windResume(int param_1)

{
  if (*(int *)(param_1 + 0x70) == 1) {
    (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x10))
              (DAT_3012cdfc,param_1 + 0x50,*(undefined4 *)(param_1 + 0x74));
  }
  *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & 0xfffffffe;
  return;
}

/* ----------------------------------------------------------------
 * windStop @ 0x3012C138  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: taskStop, taskStopForce
 * Константы: 0x3012C138
 * Данные: DAT_3012cdfc
 * ---------------------------------------------------------------- */
void windStop(int param_1)

{
  if (*(int *)(param_1 + 0x70) == 0) {
    (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x18))(DAT_3012cdfc,param_1 + 0x50);
  }
  *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 0x10;
  return;
}

/* ----------------------------------------------------------------
 * windCont @ 0x3012C17C  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: taskCont
 * Константы: 0x3012C17C, 0xFFFFFFEF
 * Данные: DAT_3012cdfc
 * ---------------------------------------------------------------- */
void windCont(int param_1)

{
  if (*(int *)(param_1 + 0x70) == 0x10) {
    (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x10))
              (DAT_3012cdfc,param_1 + 0x50,*(undefined4 *)(param_1 + 0x74));
  }
  *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & 0xffffffef;
  return;
}

/* ----------------------------------------------------------------
 * windPrioritySet @ 0x3012C1C4  (примерный размер ~332 байт)
 * Модуль: data | Вызывают: 16 | Вызывает: 1
 * Вызывает: objVerify
 * Вызывают: semMGive, semMGiveForce, semMGiveKernWork, semMGiveNoLock, semMGiveScalable, semMPendQPut, semMTake, semMTakeNoLock, semMTakeScalable, semRTake
 *           ...
 * Константы: 0x3012C1C4
 * Данные: DAT_3012cdfc, DAT_3012ce04
 * ---------------------------------------------------------------- */
void windPrioritySet(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x84) == 0) && (*(uint *)(param_1 + 0x74) < param_2)) {
    if (*(uint *)(param_1 + 0x78) != *(uint *)(param_1 + 0x88)) {
      param_2 = *(uint *)(param_1 + 0x88);
    }
    *(uint *)(param_1 + 0x74) = param_2;
    if (*(uint *)(param_1 + 0x70) == 0) {
      (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x1c))(DAT_3012cdfc,param_1 + 0x50,param_2);
    }
    else if ((*(uint *)(param_1 + 0x70) & 2) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0xa8) + 0xc) + 0x1c))
                (*(int *)(param_1 + 0xa8),param_1 + 0x50,param_2);
    }
  }
  else {
    do {
      do {
        if (*(uint *)(param_1 + 0x74) <= param_2) {
          return;
        }
        *(uint *)(param_1 + 0x74) = param_2;
        iVar1 = DAT_3012cdfc;
        iVar2 = *(int *)(param_1 + 0x70);
        while (iVar2 == 0) {
          (**(code **)(*(int *)(iVar1 + 0xc) + 0x1c))
                    (iVar1,param_1 + 0x50,*(undefined4 *)(param_1 + 0x74));
          if (*(uint *)(param_1 + 0x74) <= param_2) {
            return;
          }
          *(uint *)(param_1 + 0x74) = param_2;
          iVar2 = *(int *)(param_1 + 0x70);
        }
      } while ((*(uint *)(param_1 + 0x70) & 2) == 0);
      (**(code **)(*(int *)(*(int *)(param_1 + 0xa8) + 0xc) + 0x1c))
                (*(int *)(param_1 + 0xa8),param_1 + 0x50,param_2);
      if (*(int *)(param_1 + 0x8c) == 0) {
        return;
      }
      param_1 = *(int *)(*(int *)(param_1 + 0x8c) + 0x54);
      iVar1 = objVerify(param_1,*DAT_3012ce04);
    } while (iVar1 == 0);
  }
  return;
}

/* ----------------------------------------------------------------
 * windPriNormalSet @ 0x3012C310  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: windPrioritySet
 * Вызывают: taskPrioritySet
 * Константы: 0x3012C310
 * ---------------------------------------------------------------- */
void windPriNormalSet(int param_1,uint param_2)

{
  if ((param_2 < *(uint *)(param_1 + 0x88)) ||
     (*(int *)(param_1 + 0x80) == *(int *)(param_1 + 0x84))) {
    *(uint *)(param_1 + 0x88) = param_2;
  }
  *(uint *)(param_1 + 0x78) = param_2;
  windPrioritySet();
  return;
}

/* ----------------------------------------------------------------
 * windPendQFlush @ 0x3012C33C  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 18 | Вызывает: 1
 * Вызывает: taskRtnValueSet
 * Вызывают: FUN_30128940, _taskSuspend, semMGive, semMGiveForce, semMGiveKernWork, semMGiveNoLock, semMGiveScalable, semQFlush, semQFlushDefer, semRWGive
 *           ...
 * Константы: 0x3012C33C, 0xFFFFFFFD, 0xFFFFFFFB
 * Данные: DAT_3012cdf8, DAT_3012cdfc
 * ---------------------------------------------------------------- */
void windPendQFlush(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x14))();
  while (iVar1 != 0) {
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfffffffd;
    taskRtnValueSet(iVar1 + -0x50,0);
    if ((*(uint *)(iVar1 + 0x20) & 4) != 0) {
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfffffffb;
      (**(code **)(*(int *)(DAT_3012cdf8 + 0xc) + 0x18))(DAT_3012cdf8,iVar1 + -0x10);
    }
    if (*(int *)(iVar1 + 0x20) == 0) {
      (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x10))
                (DAT_3012cdfc,iVar1,*(undefined4 *)(iVar1 + 0x24));
    }
    iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x14))(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * windPendQTerminate @ 0x3012C404  (примерный размер ~216 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: taskRtnValueSet
 * Вызывают: FUN_30122a44, windSemDelete, windSemRWDelete
 * Константы: 0x3012C404, 0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFB
 * Данные: DAT_3012cdf8, DAT_3012cdfc, DAT_3012ce08
 * ---------------------------------------------------------------- */
void windPendQTerminate(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*(int *)(param_1 + 0xc) + 0x14))();
  uVar1 = DAT_3012ce08;
  while (iVar2 != 0) {
    *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xfffffffd;
    *(undefined4 *)(iVar2 + 0x3c) = 0;
    *(undefined4 *)(iVar2 + 0x80) = uVar1;
    taskRtnValueSet(iVar2 + -0x50,0xffffffff);
    if ((*(uint *)(iVar2 + 0x20) & 4) != 0) {
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xfffffffb;
      (**(code **)(*(int *)(DAT_3012cdf8 + 0xc) + 0x18))(DAT_3012cdf8,iVar2 + -0x10);
    }
    if (*(int *)(iVar2 + 0x20) == 0) {
      (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x10))
                (DAT_3012cdfc,iVar2,*(undefined4 *)(iVar2 + 0x24));
    }
    iVar2 = (**(code **)(*(int *)(param_1 + 0xc) + 0x14))(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * windSemDelete @ 0x3012C4DC  (примерный размер ~276 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: objVerify, windPendQFlush, windPendQTerminate, windPrioritySet
 * Вызывают: FUN_30124a88
 * Константы: 0x3012C4DC
 * Данные: DAT_3012ce04, DAT_3012ce0c
 * ---------------------------------------------------------------- */
void windSemDelete(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  windPendQTerminate(param_1 + 0x44);
  if (*(char *)(param_1 + 0x40) == '\x01') {
    iVar3 = *(int *)(param_1 + 0x54);
  }
  bVar1 = false;
  if ((iVar3 == 0) || (iVar2 = objVerify(iVar3,*DAT_3012ce04), iVar2 != 0)) {
    if (*(char *)(param_1 + 0x40) == '\x06') {
      (*(code *)*DAT_3012ce0c)(param_1);
    }
  }
  else {
    if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
      if ((*(int *)(param_1 + 100) != 0) &&
         (iVar2 = *(int *)(iVar3 + 0x84) + -1, *(int *)(iVar3 + 0x84) = iVar2, iVar2 == 0)) {
        bVar1 = true;
      }
      iVar2 = *(int *)(iVar3 + 0x80) + -1;
      *(int *)(iVar3 + 0x80) = iVar2;
      if (*(int *)(iVar3 + 0x84) == iVar2) {
        *(int *)(iVar3 + 0x88) = *(int *)(iVar3 + 0x78);
        if ((iVar2 == 0) && (*(int *)(iVar3 + 0x74) != *(int *)(iVar3 + 0x78))) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        windPrioritySet(iVar3,*(undefined4 *)(iVar3 + 0x88));
      }
    }
    if ((((*(byte *)(param_1 + 0x41) & 4) != 0) &&
        (iVar2 = *(int *)(iVar3 + 0xac) + -1, *(int *)(iVar3 + 0xac) = iVar2, iVar2 == 0)) &&
       (*(int *)(iVar3 + 0xb0) != 0)) {
      windPendQFlush(iVar3 + 0xb0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * windTickAnnounce @ 0x3012C5F0  (примерный размер ~552 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: taskRtnValueSet, windPendQRemove, workQDoWork
 * Вызывают: tickAnnounce, usrClock, windTickAnnounceN
 * Константы: 0xFFFFFFFF, 0x3012C5F0, 0xFFFFFFFE, 0xFFFFFFFB
 * Данные: DAT_3012cdf8, DAT_3012cdfc, DAT_3012ce04, DAT_3012ce10, DAT_3012ce14, DAT_3012ce18, DAT_3012ce1c, DAT_3012ce20
 * ---------------------------------------------------------------- */
void windTickAnnounce(void)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  
  puVar4 = DAT_3012ce10;
  uVar9 = *DAT_3012ce10;
  puVar1 = DAT_3012ce10 + 1;
  *DAT_3012ce10 = uVar9 + 1;
  puVar4[1] = *puVar1 + (uint)(0xfffffffe < uVar9);
  piVar3 = DAT_3012cdf8;
  iVar10 = DAT_3012cdf8[3];
  if ((*(int *)(iVar10 + 0x40) == *DAT_3012ce14) && (iVar7 = *DAT_3012cdf8, iVar7 != 0)) {
    if (*(int *)(iVar7 + 8) == 0) {
      *(undefined4 *)(iVar7 + 8) = 0;
    }
    else {
      *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + -1;
    }
  }
  iVar10 = (**(code **)(iVar10 + 0x24))(piVar3);
  piVar2 = DAT_3012ce04;
  while (DAT_3012ce04 = piVar2, iVar10 != 0) {
    if (*(int *)(iVar10 + -0x10) == *piVar2) {
      do {
        iVar7 = iVar10 + -0x40;
        uVar9 = *(uint *)(iVar10 + 0x30);
        uVar8 = uVar9 & 0xfffffffb;
        *(uint *)(iVar10 + 0x30) = uVar8;
        if ((uVar8 != 0) && ((uVar9 & 2) != 0)) {
          iVar5 = windPendQRemove(iVar7);
          if (iVar5 == -1) {
            taskRtnValueSet(iVar7,0xffffffff);
            *(undefined4 *)(iVar10 + 0x90) = DAT_3012ce18;
          }
          else if (iVar5 == 1) {
            taskRtnValueSet(iVar7,0);
          }
          else {
            taskRtnValueSet(iVar7,0xffffffff);
            *(undefined4 *)(iVar10 + 0x90) = DAT_3012ce1c;
          }
        }
        if (*(int *)(iVar10 + 0x30) == 0) {
          (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x10))
                    (DAT_3012cdfc,iVar10 + 0x10,*(undefined4 *)(iVar10 + 0x34));
        }
        iVar10 = (**(code **)(piVar3[3] + 0x24))(piVar3);
        if (iVar10 == 0) goto LAB_3012c7ec;
      } while (*(int *)(iVar10 + -0x10) == *piVar2);
    }
    *(undefined2 *)(iVar10 + 0x10) = 0;
    pcVar6 = *(code **)(iVar10 + 0x14);
    uVar11 = *(undefined4 *)(iVar10 + 0x18);
    *DAT_3012ce20 = *DAT_3012ce20 + 1;
    if (*(short *)(iVar10 + 0x12) == 0) {
      (*pcVar6)(uVar11);
    }
    *DAT_3012ce20 = *DAT_3012ce20 + -1;
    workQDoWork();
    iVar10 = (**(code **)(piVar3[3] + 0x24))(piVar3);
    piVar2 = DAT_3012ce04;
  }
LAB_3012c7ec:
  if ((code *)*DAT_3012ce24 != (code *)0x0) {
    (*(code *)*DAT_3012ce24)(*DAT_3012ce28);
  }
  return;
}

/* ----------------------------------------------------------------
 * windDelay @ 0x3012C818  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: taskDelay
 * Константы: 0x3012C818
 * Данные: DAT_3012cdf8, DAT_3012cdfc, DAT_3012ce28
 * ---------------------------------------------------------------- */
undefined4 windDelay(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = *DAT_3012ce28;
  (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x18))(DAT_3012cdfc,iVar1 + 0x50);
  (**(code **)(*(int *)(DAT_3012cdf8 + 0xc) + 0x10))(DAT_3012cdf8,iVar1 + 0x40,param_1);
  *(uint *)(iVar1 + 0x70) = *(uint *)(iVar1 + 0x70) | 4;
  return 0;
}

/* ----------------------------------------------------------------
 * windUndelay @ 0x3012C878  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskRtnValueSet
 * Вызывают: taskUndelay
 * Константы: 0x3012C878, 0xFFFFFFFB, 0xFFFFFFFF
 * Данные: DAT_3012cdf8, DAT_3012cdfc, DAT_3012ce2c
 * ---------------------------------------------------------------- */
undefined4 windUndelay(int param_1)

{
  if ((*(uint *)(param_1 + 0x70) & 4) != 0) {
    *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & 0xfffffffb;
    (**(code **)(*(int *)(DAT_3012cdf8 + 0xc) + 0x18))(DAT_3012cdf8,param_1 + 0x40);
    taskRtnValueSet(param_1,0xffffffff);
    *(undefined4 *)(param_1 + 0xd0) = DAT_3012ce2c;
    if (*(int *)(param_1 + 0x70) == 0) {
      (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x10))
                (DAT_3012cdfc,param_1 + 0x50,*(undefined4 *)(param_1 + 0x74));
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3012c8f8 @ 0x3012C8F8  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: windPendQPut, windReadyQRemove, windWdStart
 * Константы: 0x3012C8F8
 * Данные: DAT_3012cdf8, DAT_3012ce04, DAT_3012ce10
 * ---------------------------------------------------------------- */
void FUN_3012c8f8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  uVar1 = *DAT_3012ce10;
  uVar2 = DAT_3012ce10[1];
  piVar5 = (int *)*DAT_3012cdf8;
  if (piVar5 != (int *)0x0) {
    iVar4 = *DAT_3012ce04;
    do {
      if (piVar5[-4] == iVar4) {
        uVar3 = piVar5[0x48];
        piVar5[0x48] = uVar3 - uVar1;
        piVar5[0x49] = piVar5[0x49] - (uVar2 + (uVar3 < uVar1));
      }
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)0x0);
  }
  return;
}

/* ----------------------------------------------------------------
 * windWdStart @ 0x3012C964  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_3012c8f8, intCpuLock, intCpuUnlock
 * Вызывают: wdStart
 * Константы: 0x3012C964
 * Данные: DAT_3012cdf8, DAT_3012ce10, DAT_3012ce30
 * ---------------------------------------------------------------- */
undefined4 windWdStart(int param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  bool bVar6;
  
  intCpuLock();
  uVar4 = (uint)*(ushort *)(param_1 + 0x52) + DAT_3012ce30;
  *(short *)(param_1 + 0x52) = (short)uVar4;
  intCpuUnlock();
  puVar1 = DAT_3012ce10;
  if ((uVar4 & 0xffff) == 0) {
    uVar4 = *DAT_3012ce10 + param_2;
    uVar3 = DAT_3012ce10[1];
    uVar2 = DAT_3012ce10[1] + ((int)param_2 >> 0x1f) + (uint)CARRY4(*DAT_3012ce10,param_2);
    bVar6 = uVar2 <= uVar3;
    if (uVar3 == uVar2) {
      bVar6 = uVar4 <= *DAT_3012ce10;
    }
    if (bVar6 && (uVar3 != uVar2 || *DAT_3012ce10 != uVar4)) {
      FUN_3012c8f8();
      *puVar1 = 0;
      puVar1[1] = 0;
    }
    if (*(short *)(param_1 + 0x50) == 1) {
      pcVar5 = *(code **)(*(int *)(DAT_3012cdf8 + 0xc) + 0x1c);
    }
    else {
      pcVar5 = *(code **)(*(int *)(DAT_3012cdf8 + 0xc) + 0x10);
    }
    (*pcVar5)(DAT_3012cdf8,param_1 + 0x40,param_2);
    *(undefined2 *)(param_1 + 0x50) = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * windWdCancel @ 0x3012CA1C  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: wdCancel, wdDestroy
 * Константы: 0x3012CA1C
 * Данные: DAT_3012cdf8
 * ---------------------------------------------------------------- */
void windWdCancel(int param_1)

{
  if (*(short *)(param_1 + 0x50) == 1) {
    (**(code **)(*(int *)(DAT_3012cdf8 + 0xc) + 0x18))(DAT_3012cdf8,param_1 + 0x40);
    *(undefined2 *)(param_1 + 0x50) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * windPendQGet @ 0x3012CA5C  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 18 | Вызывает: 0
 * Вызывают: FUN_300e55ec, FUN_30122f24, FUN_30123680, msgQReceive, msgQSend, semBGive, semBGiveDefer, semBGiveNoLock, semBGiveScalable, semCGive
 *           ...
 * Константы: 0x3012CA5C, 0xFFFFFFFD, 0xFFFFFFF9
 * Данные: DAT_3012cdf8, DAT_3012cdfc
 * ---------------------------------------------------------------- */
void windPendQGet(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x14))();
  uVar2 = *(uint *)(iVar1 + 0x20);
  *(uint *)(iVar1 + 0x20) = uVar2 & 0xfffffffd;
  if ((uVar2 & 4) != 0) {
    *(uint *)(iVar1 + 0x20) = uVar2 & 0xfffffff9;
    (**(code **)(*(int *)(DAT_3012cdf8 + 0xc) + 0x18))(DAT_3012cdf8,iVar1 + -0x10);
  }
  if (*(int *)(iVar1 + 0x20) == 0) {
    (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x10))
              (DAT_3012cdfc,iVar1,*(undefined4 *)(iVar1 + 0x24));
  }
  return;
}

/* ----------------------------------------------------------------
 * windReadyQPut @ 0x3012CADC  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 0
 * Вызывают: FUN_3012205c, eventRsrcSend, eventSend, eventTerminate
 * Константы: 0x3012CADC, 0xFFFFFFFD, 0xFFFFFFF9
 * Данные: DAT_3012cdf8, DAT_3012cdfc
 * ---------------------------------------------------------------- */
void windReadyQPut(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x70);
  *(uint *)(param_1 + 0x70) = uVar1 & 0xfffffffd;
  if ((uVar1 & 4) != 0) {
    *(uint *)(param_1 + 0x70) = uVar1 & 0xfffffff9;
    (**(code **)(*(int *)(DAT_3012cdf8 + 0xc) + 0x18))(DAT_3012cdf8,param_1 + 0x40);
  }
  if (*(int *)(param_1 + 0x70) == 0) {
    (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x10))
              (DAT_3012cdfc,param_1 + 0x50,*(undefined4 *)(param_1 + 0x74));
  }
  return;
}

/* ----------------------------------------------------------------
 * windReadyQRemove @ 0x3012CB4C  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_3012c8f8
 * Константы: 0x3012CB4C, 0xFFFFFFFF
 * Данные: DAT_3012cdf8, DAT_3012cdfc, DAT_3012ce10, DAT_3012ce28
 * ---------------------------------------------------------------- */
void windReadyQRemove(undefined4 param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = *DAT_3012ce28;
  (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x18))(DAT_3012cdfc,iVar5 + 0x50);
  *(uint *)(iVar5 + 0x70) = *(uint *)(iVar5 + 0x70) | 2;
  *(undefined4 *)(iVar5 + 0xa8) = param_1;
  puVar1 = DAT_3012ce10;
  if (param_2 != 0xffffffff) {
    uVar2 = *DAT_3012ce10 + param_2;
    uVar4 = DAT_3012ce10[1];
    uVar3 = DAT_3012ce10[1] + ((int)param_2 >> 0x1f) + (uint)CARRY4(*DAT_3012ce10,param_2);
    bVar6 = uVar3 <= uVar4;
    if (uVar4 == uVar3) {
      bVar6 = uVar2 <= *DAT_3012ce10;
    }
    if (bVar6 && (uVar4 != uVar3 || *DAT_3012ce10 != uVar2)) {
      FUN_3012c8f8();
      *puVar1 = 0;
      puVar1[1] = 0;
    }
    uVar2 = *puVar1;
    uVar3 = puVar1[1];
    *(uint *)(iVar5 + 0x160) = uVar2 + param_2;
    *(uint *)(iVar5 + 0x164) = uVar3 + ((int)param_2 >> 0x1f) + (uint)CARRY4(uVar2,param_2);
    (**(code **)(*(int *)(DAT_3012cdf8 + 0xc) + 0x10))(DAT_3012cdf8,iVar5 + 0x40,param_2);
    *(uint *)(iVar5 + 0x70) = *(uint *)(iVar5 + 0x70) | 4;
  }
  return;
}

/* ----------------------------------------------------------------
 * windPendQPut @ 0x3012CC14  (примерный размер ~232 байт)
 * Модуль: data | Вызывают: 18 | Вызывает: 1
 * Вызывает: FUN_3012c8f8
 * Вызывают: FUN_30122fd4, _taskSuspend, eventReceive, pause, semBTake, semBTakeNoLock, semBTakeScalable, semCTake, semMPendQPut, semMTake
 *           ...
 * Константы: 0x3012CC14, 0xFFFFFFFF
 * Данные: DAT_3012cdf8, DAT_3012cdfc, DAT_3012ce10, DAT_3012ce28
 * ---------------------------------------------------------------- */
undefined4 windPendQPut(int param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = *DAT_3012ce28;
  (**(code **)(*(int *)(DAT_3012cdfc + 0xc) + 0x18))(DAT_3012cdfc,iVar5 + 0x50);
  *(uint *)(iVar5 + 0x70) = *(uint *)(iVar5 + 0x70) | 2;
  *(int *)(iVar5 + 0xa8) = param_1;
  (**(code **)(*(int *)(param_1 + 0xc) + 0x10))(param_1,iVar5 + 0x50,*(undefined4 *)(iVar5 + 0x74));
  puVar1 = DAT_3012ce10;
  if (param_2 != 0xffffffff) {
    uVar2 = *DAT_3012ce10 + param_2;
    uVar4 = DAT_3012ce10[1];
    uVar3 = DAT_3012ce10[1] + ((int)param_2 >> 0x1f) + (uint)CARRY4(*DAT_3012ce10,param_2);
    bVar6 = uVar3 <= uVar4;
    if (uVar4 == uVar3) {
      bVar6 = uVar2 <= *DAT_3012ce10;
    }
    if (bVar6 && (uVar4 != uVar3 || *DAT_3012ce10 != uVar2)) {
      FUN_3012c8f8();
      *puVar1 = 0;
      puVar1[1] = 0;
    }
    uVar2 = *puVar1;
    uVar3 = puVar1[1];
    *(uint *)(iVar5 + 0x160) = uVar2 + param_2;
    *(uint *)(iVar5 + 0x164) = uVar3 + ((int)param_2 >> 0x1f) + (uint)CARRY4(uVar2,param_2);
    (**(code **)(*(int *)(DAT_3012cdf8 + 0xc) + 0x10))(DAT_3012cdf8,iVar5 + 0x40,param_2);
    *(uint *)(iVar5 + 0x70) = *(uint *)(iVar5 + 0x70) | 4;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * windTickAnnounceN @ 0x3012CCFC  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: windTickAnnounce
 * Константы: 0x3012CCFC
 * Данные: DAT_3012cdf8, DAT_3012ce10, DAT_3012ce14
 * ---------------------------------------------------------------- */
void windTickAnnounceN(uint param_1)

{
  uint *puVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  
  piVar2 = DAT_3012cdf8;
  if (param_1 != 0) {
    if ((*DAT_3012cdf8 != 0) &&
       (uVar4 = (**(code **)(DAT_3012cdf8[3] + 0x28))(*DAT_3012cdf8,1), uVar4 < param_1)) {
      param_1 = uVar4;
    }
    puVar3 = DAT_3012ce10;
    param_1 = param_1 - 1;
    if (param_1 != 0) {
      uVar4 = *DAT_3012ce10;
      puVar1 = DAT_3012ce10 + 1;
      *DAT_3012ce10 = uVar4 + param_1;
      puVar3[1] = *puVar1 + (uint)CARRY4(uVar4,param_1);
      if ((*(int *)(piVar2[3] + 0x40) == *DAT_3012ce14) && (iVar5 = *piVar2, iVar5 != 0)) {
        if (*(uint *)(iVar5 + 8) < param_1) {
          *(undefined4 *)(iVar5 + 8) = 0;
        }
        else {
          *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) - param_1;
        }
      }
    }
    windTickAnnounce();
  }
  return;
}

/* ----------------------------------------------------------------
 * windTickWaitGet @ 0x3012CDB8  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012CDB8
 * Данные: DAT_3012cdf8
 * ---------------------------------------------------------------- */
void windTickWaitGet(void)

{
  if (*DAT_3012cdf8 != 0) {
    (**(code **)(DAT_3012cdf8[3] + 0x28))(*DAT_3012cdf8,1);
  }
  return;
}

/* ----------------------------------------------------------------
 * windNullReturn @ 0x3012CDF0  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012CDF0
 * ---------------------------------------------------------------- */
undefined4 windNullReturn(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * windPwrModeSet @ 0x3012CE34  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012CE34
 * Данные: DAT_3012ce9c
 * ---------------------------------------------------------------- */
void windPwrModeSet(undefined4 param_1)

{
  *DAT_3012ce9c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * windPwrModeGet @ 0x3012CE40  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012CE40
 * Данные: DAT_3012ce9c
 * ---------------------------------------------------------------- */
undefined4 windPwrModeGet(void)

{
  return *DAT_3012ce9c;
}

/* ----------------------------------------------------------------
 * windPwrDownRtnSet @ 0x3012CE4C  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012CE4C
 * Данные: DAT_3012cea0
 * ---------------------------------------------------------------- */
void windPwrDownRtnSet(undefined4 param_1)

{
  *DAT_3012cea0 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * windPwrUpRtnSet @ 0x3012CE58  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012CE58
 * Данные: DAT_3012cea4
 * ---------------------------------------------------------------- */
void windPwrUpRtnSet(undefined4 param_1)

{
  *DAT_3012cea4 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * windPwrDown @ 0x3012CE64  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: reschedule, windExit
 * Константы: 0x3012CE64
 * Данные: DAT_3012ce9c, DAT_3012cea8
 * ---------------------------------------------------------------- */
void windPwrDown(void)

{
  if ((*DAT_3012ce9c != 0) && ((code *)*DAT_3012cea8 != (code *)0x0)) {
    (*(code *)*DAT_3012cea8)();
  }
  return;
}

/* ----------------------------------------------------------------
 * windPwrUp @ 0x3012CE98  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: intEnt
 * Константы: 0x3012CE98
 * ---------------------------------------------------------------- */
void windPwrUp(void)

{
  return;
}

/* ----------------------------------------------------------------
 * windSemRWDelete @ 0x3012CEAC  (примерный размер ~320 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: objVerify, windPendQFlush, windPendQTerminate, windPrioritySet
 * Константы: 0x3012CEAC
 * Данные: DAT_3012cfe8
 * ---------------------------------------------------------------- */
void windSemRWDelete(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  bVar1 = false;
  uVar4 = 0;
  windPendQTerminate(param_1 + 0x70);
  iVar6 = *(int *)(param_1 + 0x54);
  if (iVar6 == 0) {
    iVar3 = *(int *)(param_1 + 0x6c);
    if (iVar3 == 0) {
      return;
    }
    iVar6 = *(int *)(param_1 + 0x80);
    piVar7 = (int *)(param_1 + 0x88);
  }
  else {
    piVar7 = (int *)(param_1 + 100);
    iVar3 = 1;
    uVar4 = *(uint *)(param_1 + 0x68);
  }
  iVar5 = uVar4 * 0xc + param_1;
  while( true ) {
    if (iVar6 != 0) {
      iVar2 = objVerify(iVar6,*DAT_3012cfe8);
      if (iVar2 == 0) {
        if ((*(byte *)(param_1 + 0x41) & 8) != 0) {
          if ((*piVar7 != 0) &&
             (iVar2 = *(int *)(iVar6 + 0x84) + -1, *(int *)(iVar6 + 0x84) = iVar2, iVar2 == 0)) {
            bVar1 = true;
          }
          iVar2 = *(int *)(iVar6 + 0x80) + -1;
          *(int *)(iVar6 + 0x80) = iVar2;
          if (*(int *)(iVar6 + 0x84) == iVar2) {
            *(int *)(iVar6 + 0x88) = *(int *)(iVar6 + 0x78);
            if ((iVar2 == 0) && (*(int *)(iVar6 + 0x74) != *(int *)(iVar6 + 0x78))) {
              bVar1 = true;
            }
          }
          if (bVar1) {
            windPrioritySet(iVar6,*(undefined4 *)(iVar6 + 0x88));
          }
        }
        if ((((*(byte *)(param_1 + 0x41) & 4) != 0) &&
            (iVar2 = *(int *)(iVar6 + 0xac) + -1, *(int *)(iVar6 + 0xac) = iVar2, iVar2 == 0)) &&
           (*(int *)(iVar6 + 0xb0) != 0)) {
          windPendQFlush(iVar6 + 0xb0);
        }
      }
      iVar3 = iVar3 + -1;
    }
    uVar4 = uVar4 + 1;
    if (*(uint *)(param_1 + 0x68) <= uVar4) break;
    iVar6 = *(int *)(iVar5 + 0x8c);
    piVar7 = (int *)(iVar5 + 0x94);
    iVar5 = iVar5 + 0xc;
    if (iVar3 == 0) {
      return;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * workQInit @ 0x3012CFEC  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: ffsMsb
 * Вызывают: usrKernelInit
 * Константы: 0x3012CFEC, 0xFFFFFFFF
 * Данные: DAT_3012d3c8, DAT_3012d3cc, DAT_3012d3d0
 * ---------------------------------------------------------------- */
void workQInit(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (0x10000 < param_1) {
    param_1 = 0x10000;
  }
  iVar2 = ffsMsb(param_1);
  *DAT_3012d3c8 = 0xffffffff;
  *DAT_3012d3cc = 1;
  puVar1 = DAT_3012d3d0;
  DAT_3012d3d0[1] = (1 << (iVar2 + 0xffU & 0xff)) + -1;
  puVar1[2] = 0;
  *puVar1 = 0;
  return;
}

/* ----------------------------------------------------------------
 * workQPanic @ 0x3012D03C  (примерный размер ~296 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: edrErrorInjectStub, edrInterruptFatalPolicyHandler, reboot
 * Вызывают: workQAdd0, workQAdd1, workQAdd2
 * Константы: 0x3012D03C
 * Данные: DAT_3012d3cc, DAT_3012d3d4, DAT_3012d3d8, DAT_3012d3dc, DAT_3012d3e0, DAT_3012d3e4
 * ---------------------------------------------------------------- */
void workQPanic(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  code *pcVar8;
  bool bVar9;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  code *local_c;
  
  iVar7 = 0;
  if (((code *)*DAT_3012d3d4 == (code *)0x0) || (iVar3 = (*(code *)*DAT_3012d3d4)(), iVar3 != 0)) {
    *DAT_3012d3cc = 1;
    piVar2 = DAT_3012d3dc;
    cVar1 = *(char *)*DAT_3012d3dc;
    *(char *)*DAT_3012d3d8 = cVar1;
    pcVar6 = (char *)*DAT_3012d3d8;
    if (cVar1 != '\0') {
      pcVar4 = (char *)*piVar2;
      pcVar5 = pcVar6;
      do {
        iVar7 = iVar7 + 1;
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar5 = pcVar5 + 1;
        *pcVar5 = cVar1;
      } while (cVar1 != '\0');
    }
    *DAT_3012d3d8 = pcVar6 + iVar7;
    pcVar8 = (code *)*DAT_3012d3e0;
    bVar9 = pcVar8 == (code *)0x0;
    if (!bVar9) {
      pcVar8 = (code *)(*pcVar8)(0,0,0);
      bVar9 = pcVar8 == (code *)0x0;
    }
    if (bVar9) {
      pcVar8 = (code *)*piVar2;
    }
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    edrErrorInjectStub(0x21,DAT_3012d3e4,0x308,0,0,0,pcVar8);
    local_c = pcVar8;
    edrInterruptFatalPolicyHandler(&local_20);
    reboot(0);
  }
  return;
}

/* ----------------------------------------------------------------
 * workQAdd0 @ 0x3012D164  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: workQPanic
 * Вызывают: tickAnnounce, usrClock
 * Константы: 0x3012D164
 * Данные: DAT_3012d3cc, DAT_3012d3d0, DAT_3012d3e8, DAT_3012d3ec
 * ---------------------------------------------------------------- */
void workQAdd0(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_3012d3d0;
  puVar3 = (undefined4 *)(DAT_3012d3e8 + DAT_3012d3d0[2] * 0x10);
  uVar2 = DAT_3012d3d0[1] & DAT_3012d3d0[2] + 1;
  DAT_3012d3d0[2] = uVar2;
  if (*puVar1 == uVar2) {
    workQPanic();
  }
  *DAT_3012d3cc = 0;
  *puVar3 = param_1;
  if (*DAT_3012d3ec != 0) {
    puVar3[3] = *(undefined4 *)(*DAT_3012d3ec + 0x40);
    return;
  }
  puVar3[3] = 0;
  return;
}

/* ----------------------------------------------------------------
 * workQAdd1 @ 0x3012D1EC  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 12 | Вызывает: 1
 * Вызывает: workQPanic
 * Вызывают: _taskSuspend, eventSend, semBGiveScalable, semFlushDefer, semGiveDefer, taskActivate, taskCont, taskResume, taskStop, taskStopForce
 *           ...
 * Константы: 0x3012D1EC
 * Данные: DAT_3012d3cc, DAT_3012d3d0, DAT_3012d3e8, DAT_3012d3ec
 * ---------------------------------------------------------------- */
void workQAdd1(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  puVar1 = DAT_3012d3d0;
  puVar2 = (undefined4 *)(DAT_3012d3e8 + DAT_3012d3d0[2] * 0x10);
  uVar3 = DAT_3012d3d0[1] & DAT_3012d3d0[2] + 1;
  if (*DAT_3012d3d0 == uVar3) {
    workQPanic(DAT_3012d3d0[1],
               (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b | 0x80
              );
  }
  puVar1[2] = uVar3;
  *DAT_3012d3cc = 0;
  *puVar2 = param_1;
  puVar2[1] = param_2;
  if (*DAT_3012d3ec != 0) {
    puVar2[3] = *(undefined4 *)(*DAT_3012d3ec + 0x40);
    return;
  }
  puVar2[3] = 0;
  return;
}

/* ----------------------------------------------------------------
 * workQAdd2 @ 0x3012D27C  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: workQPanic
 * Вызывают: msgQSend, taskPrioritySet, wdStart
 * Константы: 0x3012D27C
 * Данные: DAT_3012d3cc, DAT_3012d3d0, DAT_3012d3e8, DAT_3012d3ec
 * ---------------------------------------------------------------- */
void workQAdd2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  puVar1 = DAT_3012d3d0;
  puVar2 = (undefined4 *)(DAT_3012d3e8 + DAT_3012d3d0[2] * 0x10);
  uVar3 = DAT_3012d3d0[1] & DAT_3012d3d0[2] + 1;
  if (*DAT_3012d3d0 == uVar3) {
    workQPanic(DAT_3012d3d0[1],
               (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b | 0x80
              );
  }
  puVar1[2] = uVar3;
  *DAT_3012d3cc = 0;
  *puVar2 = param_1;
  puVar2[1] = param_2;
  puVar2[2] = param_3;
  if (*DAT_3012d3ec != 0) {
    puVar2[3] = *(undefined4 *)(*DAT_3012d3ec + 0x40);
    return;
  }
  puVar2[3] = 0;
  return;
}

/* ----------------------------------------------------------------
 * workQDoWork @ 0x3012D314  (примерный размер ~224 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: __errno
 * Вызывают: reschedule, windExit, windTickAnnounce
 * Константы: 0x3012D314, 0xFFFFFFFF
 * Данные: DAT_3012d3c8, DAT_3012d3cc, DAT_3012d3d0, DAT_3012d3e8, DAT_3012d3f0
 * ---------------------------------------------------------------- */
void workQDoWork(void)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_r6;
  uint uVar6;
  
  puVar1 = DAT_3012d3d0;
  uVar6 = DAT_3012d3d0[1];
  iVar5 = *DAT_3012d3f0;
  if (iVar5 == 0) {
    *DAT_3012d3c8 = 0;
  }
  else {
    puVar3 = (undefined4 *)__errno();
    unaff_r6 = *puVar3;
  }
  iVar2 = DAT_3012d3e8;
  uVar4 = *puVar1;
  if (puVar1[2] != uVar4) {
    do {
      puVar3 = (undefined4 *)(iVar2 + uVar4 * 0x10);
      *puVar1 = uVar6 & uVar4 + 1;
      (*(code *)*puVar3)(puVar3[1],puVar3[2]);
      *DAT_3012d3cc = 1;
      uVar4 = *puVar1;
    } while (puVar1[2] != uVar4);
  }
  if (iVar5 == 0) {
    *DAT_3012d3c8 = 0xffffffff;
  }
  else {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = unaff_r6;
  }
  return;
}

/* ----------------------------------------------------------------
 * eventPointStubLibInit @ 0x3012D3F4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrToolsInit
 * Константы: 0x3012D3F4
 * ---------------------------------------------------------------- */
undefined4 eventPointStubLibInit(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * eventPointSwHandle @ 0x3012D3FC  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3012D3FC
 * ---------------------------------------------------------------- */
void eventPointSwHandle(void)

{
  return;
}

/* ----------------------------------------------------------------
 * xbdInit @ 0x3012D400  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: erfCategoryAllocate, erfTypeAllocate
 * Вызывают: usrIosExtraInit
 * Константы: 0xFFFFFFFF, 0x3012D400
 * Данные: DAT_3012df4c, DAT_3012df50, DAT_3012df54, DAT_3012df58, DAT_3012df5c, DAT_3012df60, DAT_3012df64
 * ---------------------------------------------------------------- */
undefined4 xbdInit(void)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_3012df4c;
  iVar2 = erfCategoryAllocate(DAT_3012df4c);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  iVar2 = erfTypeAllocate(*puVar1,DAT_3012df50);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  iVar2 = erfTypeAllocate(*puVar1,DAT_3012df54);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  iVar2 = erfTypeAllocate(*puVar1,DAT_3012df58);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  iVar2 = erfTypeAllocate(*puVar1,DAT_3012df5c);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  iVar2 = erfTypeAllocate(*puVar1,DAT_3012df60);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  uVar3 = erfTypeAllocate(*puVar1,DAT_3012df64);
  return uVar3;
}

/* ----------------------------------------------------------------
 * xbdAttach @ 0x3012D4BC  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: devAttach
 * Вызывают: FUN_300dddf8, FUN_300de834, xbdBlkDevCreate, xbdPartitionDevCreate, xbdRamDiskDevCreate
 * Константы: 0x3012D4BC
 * ---------------------------------------------------------------- */
void xbdAttach(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 0x1c) = param_4;
  *(undefined4 *)(param_1 + 0x20) = param_5;
  *(undefined4 *)(param_1 + 0x24) = param_6;
  devAttach(param_1,param_3,1,param_7);
  return;
}

/* ----------------------------------------------------------------
 * xbdAttachExt @ 0x3012D4F0  (примерный размер ~180 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: malloc
 * Константы: 0xFFFFFFFF, 0x3012D4F0
 * Данные: DAT_3012df68
 * ---------------------------------------------------------------- */
undefined4
xbdAttachExt(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8)

{
  int *piVar1;
  
  if (param_3 == 0) {
    return 0xffffffff;
  }
  if ((param_2 == 2) && (param_7 == 0)) {
    return 0xffffffff;
  }
  piVar1 = (int *)malloc(0x34);
  if (piVar1 == (int *)0x0) {
    return 0xffffffff;
  }
  *piVar1 = param_2;
  piVar1[1] = param_3;
  piVar1[2] = param_4;
  piVar1[3] = param_5;
  piVar1[4] = param_6;
  piVar1[5] = param_7;
  piVar1[6] = param_8;
  piVar1[7] = 0;
  piVar1[8] = 1;
  piVar1[9] = 0;
  piVar1[10] = 0;
  piVar1[0xb] = 0;
  piVar1[0xc] = 0;
  *(undefined4 *)(param_1 + 0x28) = DAT_3012df68;
  *(int **)(param_1 + 0x2c) = piVar1;
  return 0;
}

/* ----------------------------------------------------------------
 * xbdDetach @ 0x3012D5A4  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 3
 * Вызывает: FUN_300c1c1c, semGive, semTake
 * Вызывают: FUN_300dddf8, FUN_300decb0, xbdBlkDevDelete, xbdRamDiskDevDelete
 * Константы: 0x3012D5A4, 0xFFFFFFFF
 * Данные: DAT_300c1ff4
 * ---------------------------------------------------------------- */
undefined4 xbdDetach(undefined4 *param_1)

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
 * xbdIoctl @ 0x3012D5A8  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 17 | Вызывает: 2
 * Вызывает: devMap, devUnmap
 * Вызывают: FUN_300c9f7c, FUN_300ca6d8, FUN_300caa84, FUN_300cad40, FUN_300cb00c, FUN_300ce91c, FUN_300ceaec, FUN_300d20d4, FUN_300d5d2c, FUN_300d7f88
 *           ...
 * Константы: 0x3012D5A8
 * ---------------------------------------------------------------- */
undefined4 xbdIoctl(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = devMap();
  if (iVar1 == 0) {
    uVar2 = 6;
  }
  else {
    if ((code *)**(undefined4 **)(iVar1 + 0x18) == (code *)0x0) {
      uVar2 = 0x23;
    }
    else {
      uVar2 = (*(code *)**(undefined4 **)(iVar1 + 0x18))(iVar1,param_2,param_3);
    }
    devUnmap(iVar1);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * xbdStrategy @ 0x3012D614  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 4
 * Вызывает: bio_done, devMap, devUnmap, taskPriorityGet
 * Вызывают: FUN_300cace0, FUN_300caf8c, FUN_300cc0c0, FUN_300cc194, FUN_300d204c, FUN_300de4b8, FUN_300deda4, dosFsDiskProbe
 * Константы: 0x3012D614
 * ---------------------------------------------------------------- */
undefined4 xbdStrategy(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = devMap();
  if (iVar1 == 0) {
    uVar2 = 6;
    bio_done(param_2,6);
  }
  else {
    if (*(int *)(*(int *)(iVar1 + 0x18) + 4) == 0) {
      uVar2 = 0x23;
      bio_done(param_2,0x23);
    }
    else {
      taskPriorityGet(0,param_2 + 0x20);
      uVar2 = (**(code **)(*(int *)(iVar1 + 0x18) + 4))(iVar1,param_2);
    }
    devUnmap(iVar1);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3012d6a4 @ 0x3012D6A4  (примерный размер ~880 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: xbdStrategyGeneric
 * Константы: 0x3012D6A4
 * ---------------------------------------------------------------- */
undefined4 FUN_3012d6a4(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  bool bVar13;
  
  iVar9 = *(int *)(param_1 + 0x2c);
  iVar8 = 0;
  piVar3 = *(int **)(iVar9 + 0x10);
  piVar4 = *(int **)(iVar9 + 0xc);
  iVar7 = *(int *)(iVar9 + 0x20);
  piVar5 = (int *)(iVar9 + 0x2c);
  piVar2 = (int *)(iVar9 + 0x30);
  if (iVar7 != 1) {
LAB_3012d700:
    if (iVar7 == 0) {
      uVar6 = *(uint *)(param_2 + 8);
      uVar1 = *(uint *)(iVar9 + 0x28);
      bVar13 = uVar6 <= uVar1;
      if (uVar1 != uVar6) {
        if ((int)uVar6 <= (int)uVar1) goto LAB_3012d730;
        if ((int)uVar1 < (int)uVar6) goto LAB_3012d890;
      }
      if (uVar1 == uVar6) {
        bVar13 = *(uint *)(param_2 + 4) <= *(uint *)(iVar9 + 0x24);
      }
      if (bVar13) goto LAB_3012d730;
    }
LAB_3012d890:
    iVar9 = *piVar2;
    if (iVar9 == 0) {
      *piVar2 = param_2;
      if (*piVar5 != 0) {
        *(int *)(*piVar5 + 0x2c) = param_2;
        *piVar3 = param_2;
        return 0;
      }
      *piVar3 = param_2;
      *piVar4 = param_2;
      return 0;
    }
    iVar10 = *piVar3;
    if (iVar7 == 1) {
      uVar6 = *(uint *)(param_2 + 8);
      uVar1 = *(uint *)(iVar10 + 8);
      bVar13 = uVar6 <= uVar1;
      if (uVar1 != uVar6) {
        if ((int)uVar1 < (int)uVar6) goto LAB_3012d908;
        if ((int)uVar6 <= (int)uVar1) goto LAB_3012d938;
      }
      if (uVar1 == uVar6) {
        bVar13 = *(uint *)(param_2 + 4) <= *(uint *)(iVar10 + 4);
      }
      if (bVar13) goto LAB_3012d938;
    }
LAB_3012d908:
    iVar11 = iVar9;
    if (iVar7 == 0) {
      uVar6 = *(uint *)(param_2 + 8);
      uVar1 = *(uint *)(iVar10 + 8);
      bVar13 = uVar6 <= uVar1;
      bVar12 = uVar1 != uVar6;
      if (bVar12) {
        if ((int)uVar1 <= (int)uVar6) goto LAB_3012d938;
        if ((int)uVar6 < (int)uVar1) goto joined_r0x3012d954;
      }
      if (!bVar12) {
        bVar13 = *(uint *)(param_2 + 4) <= *(uint *)(iVar10 + 4);
      }
      if (!bVar13 || !bVar12 && *(uint *)(iVar10 + 4) == *(uint *)(param_2 + 4)) {
LAB_3012d938:
        *(int *)(iVar10 + 0x2c) = param_2;
        *piVar3 = param_2;
        return 0;
      }
    }
joined_r0x3012d954:
    while( true ) {
      if (iVar11 == 0) {
        return 0;
      }
      if (iVar7 != 1) break;
      uVar6 = *(uint *)(param_2 + 8);
      uVar1 = *(uint *)(iVar11 + 8);
      bVar13 = uVar6 <= uVar1;
      if (uVar1 == uVar6) {
LAB_3012d980:
        if (uVar1 == uVar6) {
          bVar13 = *(uint *)(param_2 + 4) <= *(uint *)(iVar11 + 4);
        }
        if (!bVar13) break;
      }
      else {
        if ((int)uVar1 < (int)uVar6) break;
        if ((int)uVar1 < (int)uVar6) goto LAB_3012d980;
      }
LAB_3012d9f4:
      iVar8 = iVar11;
      iVar11 = *(int *)(iVar11 + 0x2c);
    }
    if (iVar7 == 0) {
      uVar6 = *(uint *)(param_2 + 8);
      uVar1 = *(uint *)(iVar11 + 8);
      bVar13 = uVar6 <= uVar1;
      bVar12 = uVar1 == uVar6;
      if (!bVar12) {
        if (!bVar12 && (int)uVar6 <= (int)uVar1) goto LAB_3012d9b8;
        if ((int)uVar1 <= (int)uVar6) goto LAB_3012d9f4;
      }
      if (bVar12) {
        bVar13 = *(uint *)(param_2 + 4) <= *(uint *)(iVar11 + 4);
      }
      if (!bVar13 || bVar12 && *(uint *)(iVar11 + 4) == *(uint *)(param_2 + 4)) goto LAB_3012d9f4;
    }
LAB_3012d9b8:
    if (iVar9 == iVar11) {
      *(int *)(param_2 + 0x2c) = iVar9;
      if (*piVar5 == 0) {
        *piVar4 = param_2;
      }
      else {
        *(int *)(*piVar5 + 0x2c) = param_2;
      }
      *piVar2 = param_2;
      return 0;
    }
LAB_3012d9e8:
    *(int *)(iVar8 + 0x2c) = param_2;
    *(int *)(param_2 + 0x2c) = iVar11;
    return 0;
  }
  uVar6 = *(uint *)(param_2 + 8);
  uVar1 = *(uint *)(iVar9 + 0x28);
  bVar13 = uVar6 <= uVar1;
  if (uVar1 == uVar6) {
LAB_3012d6f8:
    if (uVar1 == uVar6) {
      bVar13 = *(uint *)(param_2 + 4) <= *(uint *)(iVar9 + 0x24);
    }
    if (bVar13) goto LAB_3012d700;
  }
  else {
    if ((int)uVar6 <= (int)uVar1) goto LAB_3012d700;
    if ((int)uVar6 <= (int)uVar1) goto LAB_3012d6f8;
  }
LAB_3012d730:
  iVar9 = *piVar5;
  if (iVar9 == 0) {
    *piVar4 = param_2;
    *piVar5 = param_2;
    *(int *)(param_2 + 0x2c) = *piVar2;
    if (*piVar3 != 0) {
      return 0;
    }
    *piVar3 = param_2;
    return 0;
  }
  if (iVar7 == 1) {
    uVar6 = *(uint *)(param_2 + 8);
    uVar1 = *(uint *)(iVar9 + 8);
    bVar13 = uVar6 <= uVar1;
    bVar12 = uVar1 == uVar6;
    if (bVar12) {
LAB_3012d78c:
      if (bVar12) {
        bVar13 = *(uint *)(param_2 + 4) <= *(uint *)(iVar9 + 4);
      }
      if (bVar13 && (!bVar12 || *(uint *)(iVar9 + 4) != *(uint *)(param_2 + 4))) goto LAB_3012d794;
    }
    else {
      if (!bVar12 && (int)uVar6 <= (int)uVar1) goto LAB_3012d794;
      if ((int)uVar6 < (int)uVar1) goto LAB_3012d78c;
    }
LAB_3012d7c4:
    *(int *)(iVar9 + 0x2c) = param_2;
    if (*piVar2 == 0) {
      *piVar3 = param_2;
    }
    *piVar5 = param_2;
    *(int *)(param_2 + 0x2c) = *piVar2;
  }
  else {
LAB_3012d794:
    if (iVar7 == 0) {
      uVar6 = *(uint *)(param_2 + 8);
      uVar1 = *(uint *)(iVar9 + 8);
      bVar13 = uVar6 <= uVar1;
      if (uVar1 != uVar6) {
        if ((int)uVar6 <= (int)uVar1) goto LAB_3012d7c4;
        if ((int)uVar1 < (int)uVar6) goto LAB_3012d7e8;
      }
      if (uVar1 == uVar6) {
        bVar13 = *(uint *)(param_2 + 4) <= *(uint *)(iVar9 + 4);
      }
      if (bVar13) goto LAB_3012d7c4;
    }
LAB_3012d7e8:
    iVar9 = *piVar4;
    for (iVar11 = iVar9; *piVar2 != iVar11; iVar11 = *(int *)(iVar11 + 0x2c)) {
      if (iVar7 != 1) {
LAB_3012d830:
        if (iVar7 == 0) {
          uVar6 = *(uint *)(param_2 + 8);
          uVar1 = *(uint *)(iVar11 + 8);
          bVar13 = uVar6 <= uVar1;
          if (uVar1 != uVar6) {
            if ((int)uVar1 < (int)uVar6) goto LAB_3012d860;
            if ((int)uVar6 <= (int)uVar1) goto LAB_3012d878;
          }
          if (uVar1 == uVar6) {
            bVar13 = *(uint *)(param_2 + 4) <= *(uint *)(iVar11 + 4);
          }
          if (bVar13) goto LAB_3012d878;
        }
LAB_3012d860:
        if (iVar9 == iVar11) {
          *(int *)(param_2 + 0x2c) = iVar9;
          *piVar4 = param_2;
          return 0;
        }
        goto LAB_3012d9e8;
      }
      uVar6 = *(uint *)(param_2 + 8);
      uVar1 = *(uint *)(iVar11 + 8);
      bVar13 = uVar6 <= uVar1;
      bVar12 = uVar1 == uVar6;
      if (bVar12) {
LAB_3012d828:
        if (bVar12) {
          bVar13 = *(uint *)(param_2 + 4) <= *(uint *)(iVar11 + 4);
        }
        if (bVar13 && (!bVar12 || *(uint *)(iVar11 + 4) != *(uint *)(param_2 + 4)))
        goto LAB_3012d830;
      }
      else {
        if (!bVar12 && (int)uVar6 <= (int)uVar1) goto LAB_3012d830;
        if ((int)uVar6 < (int)uVar1) goto LAB_3012d828;
      }
LAB_3012d878:
      iVar8 = iVar11;
    }
  }
  return 0;
}

