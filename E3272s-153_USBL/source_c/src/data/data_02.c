/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 2 (функций: 150, адреса 0x30036008..0x3004A824)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * sysFlashGet @ 0x30036008  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30036008
 * ---------------------------------------------------------------- */
undefined4 sysFlashGet(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * sysFlashSet @ 0x30036010  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30036010
 * ---------------------------------------------------------------- */
undefined4 sysFlashSet(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * DR_NV_File_Open @ 0x30036018  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: fopen, logMsg
 * Вызывают: DR_NV_Ctrl_File_Search, DR_NV_Read, DR_NV_Write
 * Константы: 0x30036018
 * Данные: DAT_30036714
 * ---------------------------------------------------------------- */
FILE * DR_NV_File_Open(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
  pFVar1 = fopen(param_1,param_2);
  if (pFVar1 == (FILE *)0x0) {
    logMsg(DAT_30036714,1,2,3,4,5,6);
  }
  return pFVar1;
}

/* ----------------------------------------------------------------
 * DR_NV_File_Close @ 0x30036078  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: fclose, logMsg
 * Вызывают: DR_NV_Ctrl_File_Search, DR_NV_Read, DR_NV_Write
 * Константы: 0x30036078
 * Данные: DAT_30036718
 * ---------------------------------------------------------------- */
int DR_NV_File_Close(FILE *param_1)

{
  int iVar1;
  
  iVar1 = fclose(param_1);
  if (iVar1 != 0) {
    logMsg(DAT_30036718,1,2,3,4,5,6);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * DR_NV_File_Seek @ 0x300360D4  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: fseek, logMsg
 * Вызывают: DR_NV_Ctrl_File_Search, DR_NV_Read, DR_NV_Write
 * Константы: 0x300360D4
 * Данные: DAT_3003671c
 * ---------------------------------------------------------------- */
int DR_NV_File_Seek(FILE *param_1,long param_2,int param_3)

{
  int iVar1;
  
  iVar1 = fseek(param_1,param_2,param_3);
  if (iVar1 != 0) {
    logMsg(DAT_3003671c,1,2,3,4,5,6);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * DR_NV_File_Read @ 0x30036140  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: fread, logMsg
 * Вызывают: DR_NV_Ctrl_File_Search, DR_NV_Read
 * Константы: 0x30036140
 * Данные: DAT_30036720
 * ---------------------------------------------------------------- */
size_t DR_NV_File_Read(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
  sVar1 = fread(param_1,param_2,param_3,param_4);
  if (sVar1 != param_3) {
    logMsg(DAT_30036720,1,2,3,4,5,6);
  }
  return sVar1;
}

/* ----------------------------------------------------------------
 * DR_NV_File_Write @ 0x300361BC  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: fwrite, logMsg
 * Вызывают: DR_NV_Write
 * Константы: 0x300361BC
 * Данные: DAT_30036724
 * ---------------------------------------------------------------- */
size_t DR_NV_File_Write(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
  sVar1 = fwrite(param_1,param_2,param_3,param_4);
  if (sVar1 == 0) {
    logMsg(DAT_30036724,1,2,3,4,5,6);
  }
  return sVar1;
}

/* ----------------------------------------------------------------
 * DR_NV_GetFileAbsltPath @ 0x30036230  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: strcat, strcpy
 * Вызывают: DR_NV_Read, DR_NV_Write
 * Константы: 0x30036230
 * ---------------------------------------------------------------- */
void DR_NV_GetFileAbsltPath(char *param_1,char *param_2,char *param_3)

{
  strcpy(param_3,param_1);
  strcat(param_3,param_2);
  return;
}

/* ----------------------------------------------------------------
 * DR_NV_Ctrl_File_Search @ 0x3003625C  (примерный размер ~336 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 4
 * Вызывает: DR_NV_File_Close, DR_NV_File_Open, DR_NV_File_Read, DR_NV_File_Seek
 * Вызывают: DR_NV_GetLength, DR_NV_Read, DR_NV_Write
 * Константы: 0x3003625C, 0xFFFFFFFF
 * Данные: DAT_30036728
 * ---------------------------------------------------------------- */
undefined4
DR_NV_Ctrl_File_Search(ushort param_1,undefined4 param_2,undefined4 param_3,ushort *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_68 [36];
  int local_44;
  uint local_38;
  
  iVar2 = DR_NV_File_Open(param_2,DAT_30036728);
  if ((iVar2 != 0) && (iVar3 = DR_NV_File_Read(auStack_68,0x40,1,iVar2), iVar3 != 0)) {
    uVar5 = 1;
    uVar4 = local_38;
    while (uVar5 <= uVar4) {
      uVar1 = uVar5 + uVar4 >> 1;
      DR_NV_File_Seek(iVar2,uVar1 * 0xc + local_44 * 0x24 + 0x34,0);
      DR_NV_File_Read(param_4,0xc,1,iVar2);
      if (param_1 < *param_4) {
        uVar4 = uVar1 - 1;
      }
      else {
        if (param_1 <= *param_4) {
          DR_NV_File_Seek(iVar2,*(int *)(param_4 + 4) * 0x24 + 0x1c,0);
          DR_NV_File_Read(param_3,0x24,1,iVar2);
          DR_NV_File_Close(iVar2);
          return 0;
        }
        uVar5 = uVar1 + 1;
      }
    }
    DR_NV_File_Close(iVar2);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * DR_NV_Read @ 0x300363AC  (примерный размер ~344 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 7
 * Вызывает: DR_NV_Ctrl_File_Search, DR_NV_File_Close, DR_NV_File_Open, DR_NV_File_Read, DR_NV_File_Seek, DR_NV_GetFileAbsltPath, logMsg
 * Вызывают: BSP_OM_GetDloadVer, dloadGetNvImeiNumber, getFactoryMode, secureSupport
 * Константы: 0x300363AC
 * Данные: DAT_30036728, DAT_3003672c, DAT_30036730, DAT_30036734, DAT_30036738, DAT_3003673c
 * ---------------------------------------------------------------- */
undefined4 DR_NV_Read(undefined4 param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_a8 [2];
  ushort local_a6;
  undefined4 local_a4;
  undefined1 auStack_9c [4];
  undefined1 auStack_98 [32];
  undefined1 auStack_78 [100];
  
  if ((param_2 == 0) || (param_3 == 0)) {
    logMsg(DAT_3003672c,1,2,3,4,5,6);
    uVar1 = 4;
  }
  else {
    iVar2 = DR_NV_Ctrl_File_Search(param_1,DAT_30036730,auStack_9c,auStack_a8);
    if (iVar2 == 0) {
      if (local_a6 < param_3) {
        logMsg(DAT_30036738,1,2,3,4,5,6);
        uVar1 = 2;
      }
      else {
        DR_NV_GetFileAbsltPath(DAT_3003673c,auStack_98,auStack_78);
        uVar1 = DR_NV_File_Open(auStack_78,DAT_30036728);
        DR_NV_File_Seek(uVar1,local_a4,0);
        DR_NV_File_Read(param_2,param_3,1,uVar1);
        DR_NV_File_Close(uVar1);
        uVar1 = 0;
      }
    }
    else {
      logMsg(DAT_30036734,1,2,3,4,5,6);
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * DR_NV_Write @ 0x30036504  (примерный размер ~344 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: DR_NV_Ctrl_File_Search, DR_NV_File_Close, DR_NV_File_Open, DR_NV_File_Seek, DR_NV_File_Write, DR_NV_GetFileAbsltPath, logMsg
 * Вызывают: set_nv_resotre_flag
 * Константы: 0x30036504
 * Данные: DAT_30036730, DAT_3003673c, DAT_30036740, DAT_30036744, DAT_30036748, DAT_3003674c
 * ---------------------------------------------------------------- */
undefined4 DR_NV_Write(undefined4 param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_a8 [2];
  ushort local_a6;
  undefined4 local_a4;
  undefined1 auStack_9c [4];
  undefined1 auStack_98 [32];
  undefined1 auStack_78 [100];
  
  if ((param_2 == 0) || (param_3 == 0)) {
    logMsg(DAT_30036740,1,2,3,4,5,6);
    uVar1 = 4;
  }
  else {
    iVar2 = DR_NV_Ctrl_File_Search(param_1,DAT_30036730,auStack_9c,auStack_a8);
    if (iVar2 == 0) {
      if (local_a6 < param_3) {
        logMsg(DAT_30036748,1,2,3,4,5,6);
        uVar1 = 2;
      }
      else {
        DR_NV_GetFileAbsltPath(DAT_3003673c,auStack_98,auStack_78);
        uVar1 = DR_NV_File_Open(auStack_78,DAT_3003674c);
        DR_NV_File_Seek(uVar1,local_a4,0);
        DR_NV_File_Write(param_2,1,param_3,uVar1);
        DR_NV_File_Close(uVar1);
        uVar1 = 0;
      }
    }
    else {
      logMsg(DAT_30036744,1,2,3,4,5,6);
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * DR_NV_GetLength @ 0x3003665C  (примерный размер ~252 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: DR_NV_Ctrl_File_Search, logMsg
 * Константы: 0x3003665C
 * Данные: DAT_30036730, DAT_30036750, DAT_30036754
 * ---------------------------------------------------------------- */
undefined4 DR_NV_GetLength(undefined4 param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_3c [2];
  ushort local_3a;
  undefined1 auStack_30 [36];
  
  if (param_2 == (uint *)0x0) {
    logMsg(DAT_30036750,1,2,3,4,5,6);
    uVar1 = 4;
  }
  else {
    iVar2 = DR_NV_Ctrl_File_Search(param_1,DAT_30036730,auStack_30,auStack_3c);
    if (iVar2 == 0) {
      *param_2 = (uint)local_3a;
      uVar1 = 0;
    }
    else {
      logMsg(DAT_30036754,1,2,3,4,5,6);
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30036758 @ 0x30036758  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30036888
 * Константы: 0x30036758, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_30036758(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + param_3 * 4) == 0) {
    for (param_3 = param_3 + -1; -1 < param_3; param_3 = param_3 + -1) {
      if (*(uint *)(param_2 + param_3 * 4) < *(uint *)(param_1 + param_3 * 4)) {
        return 1;
      }
      if (*(uint *)(param_1 + param_3 * 4) < *(uint *)(param_2 + param_3 * 4)) {
        return 0xffffffff;
      }
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300367d0 @ 0x300367D0  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30036888
 * Константы: 0x300367D0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void FUN_300367d0(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
    if (*(uint *)(param_1 + uVar2 * 4) < *(uint *)(param_2 + uVar2 * 4)) {
      *(uint *)(param_1 + uVar2 * 4) =
           ~(*(int *)(param_2 + uVar2 * 4) - *(int *)(param_1 + uVar2 * 4)) + 1;
      uVar1 = uVar2;
      while (uVar1 = uVar1 + 1, *(int *)(param_1 + uVar1 * 4) == 0) {
        *(undefined4 *)(param_1 + uVar1 * 4) = 0xffffffff;
      }
      piVar3 = (int *)(param_1 + uVar1 * 4);
      *piVar3 = *piVar3 + -1;
    }
    else {
      *(int *)(param_1 + uVar2 * 4) = *(int *)(param_1 + uVar2 * 4) - *(int *)(param_2 + uVar2 * 4);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30036888 @ 0x30036888  (примерный размер ~500 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30036758, FUN_300367d0
 * Вызывают: secDataRsa
 * Константы: 0x30036888, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
void FUN_30036888(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_b0 [33];
  
  for (uVar2 = 0; uVar2 < 0x21; uVar2 = uVar2 + 1) {
    local_b0[uVar2] = 0;
  }
  uVar2 = param_3 + 0x1f >> 5;
  if (uVar2 < 0x21) {
    for (uVar3 = 0; uVar3 < uVar2 - 1; uVar3 = uVar3 + 1) {
      local_b0[uVar3] = ~*(uint *)(param_2 + uVar3 * 4);
    }
    if ((param_3 & 0x1f) == 0) {
      local_b0[uVar3] = ~*(uint *)(param_2 + uVar3 * 4);
    }
    else {
      local_b0[uVar3] =
           (1 << (param_3 - (uVar2 * 0x20 + -0x20) & 0xff)) - 1U & ~*(uint *)(param_2 + uVar3 * 4);
    }
    local_b0[0] = local_b0[0] + 1;
    for (uVar3 = 0; uVar3 < (uVar2 * 0x40 - param_3) + 0x40; uVar3 = uVar3 + 1) {
      uVar4 = 0;
      while (uVar5 = uVar4, uVar4 < uVar2) {
        for (; 0x7fffffff < local_b0[uVar5]; uVar5 = uVar5 + 1) {
          local_b0[uVar5] = local_b0[uVar5] << 1;
        }
        local_b0[uVar5] = local_b0[uVar5] << 1;
        while (uVar4 < uVar5) {
          uVar4 = uVar4 + 1;
          local_b0[uVar4] = local_b0[uVar4] + 1;
        }
        uVar4 = uVar5 + 1;
      }
      while (iVar1 = FUN_30036758(local_b0,param_2,uVar2), -1 < iVar1) {
        FUN_300367d0(local_b0,param_2,uVar2);
      }
    }
    for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
      *(uint *)(param_1 + uVar3 * 4) = local_b0[uVar3];
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * secInit @ 0x30036A7C  (примерный размер ~332 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: BSP_TRACE, malloc, memcpy, memset, semBCreate
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0xFFFFFFFF, 0x30036A7C
 * Данные: DAT_30037714, DAT_30037718, DAT_3003771c, DAT_30037720, DAT_30037724, DAT_30037728, DAT_3003772c, DAT_30037730
 * ---------------------------------------------------------------- */
undefined4 secInit(void)

{
  void *__src;
  void *pvVar1;
  int iVar2;
  
  __src = DAT_30037714;
  if (*DAT_30037718 == 0) {
    *(undefined4 *)((int)DAT_30037714 + 0x1c) = 0;
    memset(DAT_3003771c,0,0x24);
    pvVar1 = malloc(0x104);
    if (pvVar1 == (void *)0x0) {
      BSP_TRACE(4,0x2a,DAT_30037720);
      *(undefined4 *)((int)__src + 0x10) = 0;
      return 0xffffffff;
    }
    if ((*(int *)((int)__src + 0x20) == DAT_30037724) ||
       (*(int *)((int)__src + 0x20) == DAT_30037728)) {
      memcpy(DAT_3003771c,__src,0x24);
      *(void **)((int)DAT_3003771c + 0x18) = pvVar1;
      memcpy(*(void **)((int)DAT_3003771c + 0x18),*(void **)((int)__src + 0x18),0x104);
    }
    else {
      *(void **)((int)DAT_3003771c + 0x18) = pvVar1;
    }
    if (*(int *)((int)__src + 0x10) == 0) {
      BSP_TRACE(0,0x2a,DAT_30037730);
    }
    else {
      BSP_TRACE(0,0x2a,DAT_3003772c);
    }
    if (*DAT_30037734 == 0) {
      iVar2 = semBCreate(0,1);
      *DAT_30037734 = iVar2;
    }
    if (*DAT_30037734 == 0) {
      BSP_TRACE(4,0x2a,DAT_30037738);
      return 0xffffffff;
    }
    *DAT_30037718 = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * secInit_ForPc @ 0x30036BC8  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30036BC8
 * Данные: DAT_30037718
 * ---------------------------------------------------------------- */
undefined4 secInit_ForPc(uint param_1)

{
  *DAT_30037718 = param_1 & 0xff;
  return 0;
}

/* ----------------------------------------------------------------
 * secDataRsa @ 0x30036BE8  (примерный размер ~620 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: BSP_TRACE, FUN_30036888, RunSsdmaRsa, SetSsdmaRsaMode, SsdmaRsaInit, semGive, semTake, taskDelay
 * Вызывают: secIdioChk
 * Константы: 0xFFFFFFFF, 0x00200000, 0x01000000, 0x30036BE8
 * Данные: DAT_30037718, DAT_3003771c, DAT_30037724, DAT_30037728, DAT_30037734, DAT_3003773c, DAT_30037740, DAT_30037744
 * ---------------------------------------------------------------- */
undefined4 secDataRsa(ushort *param_1,int param_2,uint param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 local_124 [256];
  
  if (((((param_1 == (ushort *)0x0) || (param_2 == 0)) || (0x80 < param_3)) ||
      ((param_4 == 0 || (param_5 == (undefined4 *)0x0)))) ||
     ((0x400 < param_1[1] || (0x400 < *param_1)))) {
    BSP_TRACE(4,0x2a,DAT_3003773c);
    uVar3 = DAT_30037740;
  }
  else {
    uVar3 = DAT_30037744;
    if (*DAT_30037718 != 0) {
      semTake(*DAT_30037734,0xffffffff);
      *DAT_30037748 = 0x8000;
      *param_5 = 0x80;
      for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
        local_124[uVar2] = *(undefined1 *)(param_2 + uVar2);
      }
      for (; param_3 < 0x80; param_3 = param_3 + 1) {
        local_124[param_3] = 0;
      }
      uVar3 = 0;
      if ((*(int *)(DAT_3003771c + 0x20) == DAT_30037724) ||
         (*(int *)(DAT_3003771c + 0x20) == DAT_30037728)) {
        *DAT_30037748 = 0x200000;
        taskDelay(2);
        iVar1 = (**(code **)(DAT_3003771c + 8))(param_1,local_124,param_4);
        if (iVar1 == 0) {
          *DAT_3003774c = 0x200000;
        }
        else {
          *DAT_3003774c = 0x200000;
          BSP_TRACE(4,0x2a,DAT_30037750);
          uVar3 = 0xffffffff;
        }
      }
      else {
        uVar2 = 0;
        while ((uVar2 < 0x1000000 && (iVar1 = SsdmaRsaInit(), iVar1 != 0))) {
          uVar2 = uVar2 + 1;
        }
        if (uVar2 < 0x1000000) {
          SetSsdmaRsaMode(1,param_1[1],*param_1);
          FUN_30036888(local_124 + 0x80,param_1 + 0x42,param_1[1]);
          iVar1 = RunSsdmaRsa(param_1,local_124 + 0x80,param_2,param_4);
          if (iVar1 == -1) {
            BSP_TRACE(4,0x2a,DAT_30037750);
            uVar3 = 0xffffffff;
          }
        }
        else {
          BSP_TRACE(4,0x2a,DAT_30037754);
          uVar3 = 0xffffffff;
        }
      }
      *DAT_3003774c = 0x8000;
      taskDelay(2);
      semGive(*DAT_30037734);
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * Bsp_SHA1Hash @ 0x30036E54  (примерный размер ~400 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: BSP_TRACE, RunSsdmaSha1, SetSsdmaSha1Iv, SsdmaSha1Init, memcpy, memset
 * Вызывают: secDataSha
 * Константы: 0x01000000, 0x30036E54, 0xFFFFFFFF
 * Данные: DAT_30037740, DAT_30037758, DAT_3003775c, DAT_30037760
 * ---------------------------------------------------------------- */
uint Bsp_SHA1Hash(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint __n;
  undefined1 auStack_64 [59];
  byte local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    BSP_TRACE(4,0x2a,DAT_30037758);
    uVar2 = DAT_30037740;
  }
  else {
    uVar4 = 0;
    while ((uVar4 < 0x1000000 && (iVar1 = SsdmaSha1Init(), iVar1 != 0))) {
      uVar4 = uVar4 + 1;
    }
    if (uVar4 < 0x1000000) {
      uVar4 = SetSsdmaSha1Iv(DAT_30037760);
      __n = param_2 & 0x3f;
      for (uVar2 = 0; uVar2 < param_2 >> 6; uVar2 = uVar2 + 1) {
        memcpy(auStack_64,(void *)(param_1 + uVar2 * 0x40),0x40);
        uVar3 = RunSsdmaSha1(auStack_64,param_3);
        uVar4 = uVar3 | uVar4;
      }
      memset(auStack_64,0,0x40);
      memcpy(auStack_64,(void *)(param_1 + (param_2 >> 6) * 0x40),__n);
      auStack_64[__n] = 0x80;
      if (0x37 < __n) {
        uVar2 = RunSsdmaSha1(auStack_64,param_3);
        uVar4 = uVar2 | uVar4;
        memset(auStack_64,0,0x40);
      }
      local_29 = (byte)(param_2 >> 0x1d);
      local_28 = (undefined1)(param_2 >> 0x15);
      local_27 = (undefined1)(param_2 >> 0xd);
      local_26 = (undefined1)(param_2 >> 5);
      local_25 = (undefined1)((param_2 & 0x1f) << 3);
      uVar2 = RunSsdmaSha1(auStack_64,param_3);
      uVar2 = uVar2 | uVar4;
    }
    else {
      BSP_TRACE(4,0x2a,DAT_3003775c);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * secDataSha @ 0x30036FE4  (примерный размер ~336 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 5
 * Вызывает: BSP_TRACE, Bsp_SHA1Hash, semGive, semTake, taskDelay
 * Вызывают: crypto_hash, secIdioChk
 * Константы: 0x00200000, 0xFFFFFFFF, 0x30036FE4
 * Данные: DAT_30037718, DAT_3003771c, DAT_30037724, DAT_30037728, DAT_30037734, DAT_30037740, DAT_30037744, DAT_30037748
 * ---------------------------------------------------------------- */
undefined4 secDataSha(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    BSP_TRACE(4,0x2a,DAT_30037764);
    uVar2 = DAT_30037740;
  }
  else {
    uVar2 = DAT_30037744;
    if (*DAT_30037718 != 0) {
      semTake(*DAT_30037734,0xffffffff);
      *DAT_30037748 = 0x8000;
      if ((*(int *)(DAT_3003771c + 0x20) == DAT_30037724) ||
         (*(int *)(DAT_3003771c + 0x20) == DAT_30037728)) {
        *DAT_30037748 = 0x200000;
        taskDelay(2);
        iVar1 = (**(code **)(DAT_3003771c + 4))(param_1,param_2,param_3);
        if (iVar1 == 0) {
          *DAT_3003774c = 0x200000;
          uVar2 = 0;
        }
        else {
          *DAT_3003774c = 0x200000;
          BSP_TRACE(4,0x2a,DAT_30037768);
          uVar2 = 0xffffffff;
        }
      }
      else {
        uVar2 = Bsp_SHA1Hash(param_1,param_2,param_3);
      }
      *DAT_3003774c = 0x8000;
      taskDelay(2);
      semGive(*DAT_30037734);
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * secIdioChk @ 0x30037134  (примерный размер ~540 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: BSP_TRACE, memset, secDataRsa, secDataSha, semGive, semTake, taskDelay
 * Вызывают: secCheck
 * Константы: 0x00200000, 0x30037134, 0xFFFFFFFF
 * Данные: DAT_30037718, DAT_3003771c, DAT_30037724, DAT_30037728, DAT_30037734, DAT_30037740, DAT_30037744, DAT_30037748
 * ---------------------------------------------------------------- */
int secIdioChk(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 auStack_b4 [4];
  int local_b0 [5];
  int local_9c [32];
  
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) || (param_4 == 0)) {
    BSP_TRACE(4,0x2a,DAT_3003776c);
    iVar1 = DAT_30037740;
  }
  else {
    iVar1 = DAT_30037744;
    if (*DAT_30037718 != 0) {
      if ((*(int *)(DAT_3003771c + 0x20) == DAT_30037724) ||
         (*(int *)(DAT_3003771c + 0x20) == DAT_30037728)) {
        semTake(*DAT_30037734,0xffffffff);
        *DAT_30037748 = 0x8000;
        *DAT_30037748 = 0x200000;
        taskDelay(2);
        iVar1 = (**(code **)(DAT_3003771c + 0xc))(param_1,param_2,param_3,param_4);
        if (iVar1 != 0) {
          BSP_TRACE(4,0x2a,DAT_30037770);
          iVar1 = -1;
        }
        *DAT_3003774c = 0x200000;
        *DAT_3003774c = 0x8000;
        taskDelay(2);
        semGive(*DAT_30037734);
      }
      else {
        memset(local_b0,0,0x14);
        memset(local_9c,0,0x80);
        iVar1 = secDataSha(param_1,param_2,local_b0);
        if (iVar1 == 0) {
          iVar1 = secDataRsa(param_3,param_4,5,local_9c,auStack_b4);
          if (iVar1 == 0) {
            for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
              if (local_b0[iVar1] != local_9c[iVar1]) {
                return -1;
              }
            }
            iVar1 = 0;
          }
          else {
            BSP_TRACE(4,0x2a,DAT_30037778);
            iVar1 = 1;
          }
        }
        else {
          BSP_TRACE(4,0x2a,DAT_30037774);
          iVar1 = -1;
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * secCheck @ 0x30037350  (примерный размер ~224 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_TRACE, secIdioChk
 * Вызывают: secIsAllowUpgrade
 * Константы: 0x30037350
 * Данные: DAT_30037718, DAT_30037740, DAT_30037744, DAT_3003777c, DAT_30037780, DAT_30037784, DAT_30037788, DAT_3003778c
 * ---------------------------------------------------------------- */
undefined4 secCheck(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (((param_1 == 0) || (param_3 == 0)) || (param_2 == 0)) {
    BSP_TRACE(4,0x2a,DAT_3003777c);
    uVar2 = DAT_30037740;
  }
  else {
    uVar2 = DAT_30037744;
    if (*DAT_30037718 != 0) {
      iVar3 = param_2 + param_3;
      iVar1 = secIdioChk(iVar3 + 0x80,0x10c,param_1,iVar3 + 0x18c);
      if (iVar1 == 0) {
        iVar1 = secIdioChk(param_2,param_3,iVar3 + 0x80,iVar3);
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          BSP_TRACE(4,0x2a,DAT_30037788);
          uVar2 = DAT_3003778c;
        }
      }
      else {
        BSP_TRACE(4,0x2a,DAT_30037780);
        uVar2 = DAT_30037784;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * secSetRootCa @ 0x30037430  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: memcpy
 * Константы: 0x30037430, 0xFFFFFFFF
 * Данные: DAT_3003771c
 * ---------------------------------------------------------------- */
undefined4 secSetRootCa(int param_1)

{
  if (*(int *)(DAT_3003771c + 0x14) == 0) {
    if (*(int *)(DAT_3003771c + 0x18) == 0) {
      return 0xffffffff;
    }
    memcpy(*(void **)(DAT_3003771c + 0x18),(void *)(param_1 + 0xc),0x104);
    *(undefined4 *)(DAT_3003771c + 0x14) = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * secIsAllowUpgrade @ 0x30037490  (примерный размер ~480 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_TRACE, secCheck
 * Константы: 0x30037490
 * Данные: DAT_30037718, DAT_3003771c, DAT_30037740, DAT_30037744, DAT_30037790, DAT_30037794, DAT_30037798, DAT_3003779c
 * ---------------------------------------------------------------- */
uint secIsAllowUpgrade(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  
  if ((param_3 == 0) || (param_4 == 0)) {
    BSP_TRACE(4,0x2a,DAT_30037790);
    uVar1 = DAT_30037740;
  }
  else {
    uVar1 = DAT_30037744;
    if (*DAT_30037718 != 0) {
      if (*(int *)(DAT_3003771c + 0x10) == 0) {
        if (param_1 == 0) {
          if (param_2 == 0) {
            uVar1 = 1;
          }
          else {
            uVar1 = (uint)(*DAT_300377a4 == 0);
          }
        }
        else if (param_2 == 0) {
          uVar1 = 1;
        }
        else if (*(int *)(DAT_3003771c + 0x14) == 0) {
          BSP_TRACE(4,0x2a,DAT_30037794);
          uVar1 = 0;
        }
        else {
          BSP_TRACE(0,0x2a,DAT_30037798);
          iVar2 = secCheck(*(undefined4 *)(DAT_3003771c + 0x18),param_3,param_4 + -0x20c);
          if (iVar2 == 0) {
            BSP_TRACE(0,0x2a,DAT_300377a0);
            uVar1 = 1;
          }
          else {
            BSP_TRACE(4,0x2a,DAT_3003779c);
            uVar1 = 0;
          }
        }
      }
      else if (param_2 == 0) {
        uVar1 = 0;
      }
      else if (*(int *)(DAT_3003771c + 0x14) == 0) {
        BSP_TRACE(4,0x2a,DAT_30037794);
        uVar1 = 0;
      }
      else {
        BSP_TRACE(0,0x2a,DAT_30037798);
        iVar2 = secCheck(*(undefined4 *)(DAT_3003771c + 0x18),param_3,param_4 + -0x20c);
        if (iVar2 == 0) {
          BSP_TRACE(0,0x2a,DAT_300377a0);
          uVar1 = 1;
        }
        else {
          BSP_TRACE(4,0x2a,DAT_3003779c);
          uVar1 = 0;
        }
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * secIsSecVer @ 0x30037670  (примерный размер ~324 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: BSP_TRACE, nand_read, ptable_find_by_type, ptable_get_ram_data, strcmp
 * Константы: 0x30037670
 * Данные: DAT_300377a8, DAT_300377ac, DAT_300377b0
 * ---------------------------------------------------------------- */
undefined4 secIsSecVer(void)

{
  undefined4 uVar1;
  int iVar2;
  char acStack_14 [8];
  
  uVar1 = ptable_get_ram_data();
  iVar2 = ptable_find_by_type(DAT_300377a8,uVar1);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = nand_read(*(int *)(iVar2 + 0x10) + *(int *)(iVar2 + 0x14) + -8,acStack_14,8,0);
    if (iVar2 == 0) {
      iVar2 = strcmp(DAT_300377b0,acStack_14);
      if (iVar2 == 0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      BSP_TRACE(4,0x2a,DAT_300377ac,iVar2);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * hash_md5_init @ 0x3003B960  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: encrypt_lock_md5_data
 * Константы: 0x3003B960
 * Данные: DAT_3003c764, DAT_3003c768, DAT_3003c76c, DAT_3003c770
 * ---------------------------------------------------------------- */
void hash_md5_init(undefined4 *param_1)

{
  param_1[5] = 0;
  param_1[4] = 0;
  *param_1 = DAT_3003c764;
  param_1[1] = DAT_3003c768;
  param_1[2] = DAT_3003c76c;
  param_1[3] = DAT_3003c770;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3003b9a0 @ 0x3003B9A0  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3003ba40
 * Константы: 0x3003B9A0
 * ---------------------------------------------------------------- */
void FUN_3003b9a0(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 4) {
    *(uint *)(param_1 + iVar2 * 4) =
         CONCAT13(*(undefined1 *)(param_2 + uVar1 + 3),
                  CONCAT12(*(undefined1 *)(param_2 + uVar1 + 2),
                           CONCAT11(*(undefined1 *)(param_2 + uVar1 + 1),
                                    *(undefined1 *)(param_2 + uVar1))));
    iVar2 = iVar2 + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3003ba08 @ 0x3003BA08  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_3003ba40, hash_md5_final
 * Константы: 0x3003BA08
 * ---------------------------------------------------------------- */
void FUN_3003ba08(int param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
    *(undefined1 *)(param_1 + uVar1) = param_2;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3003ba40 @ 0x3003BA40  (примерный размер ~2680 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3003b9a0, FUN_3003ba08
 * Вызывают: hash_md5_update
 * Константы: 0x00400000, 0x00100000, 0x00800000, 0x00200000, 0x3003BA40
 * Данные: DAT_3003c774, DAT_3003c778, DAT_3003c77c, DAT_3003c780, DAT_3003c784, DAT_3003c788, DAT_3003c78c, DAT_3003c790
 * ---------------------------------------------------------------- */
void FUN_3003ba40(int *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  iVar4 = *param_1;
  uVar3 = param_1[1];
  uVar2 = param_1[2];
  uVar1 = param_1[3];
  FUN_3003b9a0(&local_5c,param_2,0x40);
  uVar5 = (iVar4 + (uVar3 & uVar2 | uVar1 & ~uVar3) + local_5c) - DAT_3003c774;
  uVar5 = (uVar5 >> 0x19 | uVar5 * 0x80) + uVar3;
  uVar1 = (uVar1 + (uVar5 & uVar3 | uVar2 & ~uVar5) + local_58) - DAT_3003c778;
  uVar1 = (uVar1 >> 0x14 | uVar1 * 0x1000) + uVar5;
  uVar2 = uVar2 + (uVar1 & uVar5 | uVar3 & ~uVar1) + local_54 + DAT_3003c77c;
  uVar2 = (uVar2 >> 0xf | uVar2 * 0x20000) + uVar1;
  uVar3 = (uVar3 + (uVar2 & uVar1 | uVar5 & ~uVar2) + local_50) - DAT_3003c780;
  uVar3 = (uVar3 >> 10 | uVar3 * 0x400000) + uVar2;
  uVar5 = (uVar5 + (uVar3 & uVar2 | uVar1 & ~uVar3) + local_4c) - DAT_3003c784;
  uVar5 = (uVar5 >> 0x19 | uVar5 * 0x80) + uVar3;
  uVar1 = uVar1 + (uVar5 & uVar3 | uVar2 & ~uVar5) + local_48 + DAT_3003c788;
  uVar1 = (uVar1 >> 0x14 | uVar1 * 0x1000) + uVar5;
  uVar2 = (uVar2 + (uVar1 & uVar5 | uVar3 & ~uVar1) + local_44) - DAT_3003c78c;
  uVar2 = (uVar2 >> 0xf | uVar2 * 0x20000) + uVar1;
  uVar3 = (uVar3 + (uVar2 & uVar1 | uVar5 & ~uVar2) + local_40) - DAT_3003c790;
  uVar3 = (uVar3 >> 10 | uVar3 * 0x400000) + uVar2;
  uVar5 = uVar5 + (uVar3 & uVar2 | uVar1 & ~uVar3) + local_3c + DAT_3003c794;
  uVar5 = (uVar5 >> 0x19 | uVar5 * 0x80) + uVar3;
  uVar1 = (uVar1 + (uVar5 & uVar3 | uVar2 & ~uVar5) + local_38) - DAT_3003c798;
  uVar1 = (uVar1 >> 0x14 | uVar1 * 0x1000) + uVar5;
  uVar2 = (uVar2 + (uVar1 & uVar5 | uVar3 & ~uVar1) + local_34) - DAT_3003c79c;
  uVar2 = (uVar2 >> 0xf | uVar2 * 0x20000) + uVar1;
  uVar3 = (uVar3 + (uVar2 & uVar1 | uVar5 & ~uVar2) + local_30) - DAT_3003c7a0;
  uVar3 = (uVar3 >> 10 | uVar3 * 0x400000) + uVar2;
  uVar5 = uVar5 + (uVar3 & uVar2 | uVar1 & ~uVar3) + local_2c + DAT_3003c7a4;
  uVar5 = (uVar5 >> 0x19 | uVar5 * 0x80) + uVar3;
  uVar1 = (uVar1 + (uVar5 & uVar3 | uVar2 & ~uVar5) + local_28) - DAT_3003c7a8;
  uVar1 = (uVar1 >> 0x14 | uVar1 * 0x1000) + uVar5;
  uVar2 = (uVar2 + (uVar1 & uVar5 | uVar3 & ~uVar1) + local_24) - DAT_3003c7ac;
  uVar2 = (uVar2 >> 0xf | uVar2 * 0x20000) + uVar1;
  uVar3 = uVar3 + (uVar2 & uVar1 | uVar5 & ~uVar2) + local_20 + DAT_3003c7b0;
  uVar3 = (uVar3 >> 10 | uVar3 * 0x400000) + uVar2;
  uVar5 = (uVar5 + (uVar3 & uVar1 | uVar2 & ~uVar1) + local_58) - DAT_3003c7b4;
  uVar5 = (uVar5 >> 0x1b | uVar5 * 0x20) + uVar3;
  uVar1 = (uVar1 + (uVar5 & uVar2 | uVar3 & ~uVar2) + local_44) - DAT_3003c7b8;
  uVar1 = (uVar1 >> 0x17 | uVar1 * 0x200) + uVar5;
  uVar2 = uVar2 + (uVar1 & uVar3 | uVar5 & ~uVar3) + local_30 + DAT_3003c7bc;
  uVar2 = (uVar2 >> 0x12 | uVar2 * 0x4000) + uVar1;
  uVar3 = (uVar3 + (uVar2 & uVar5 | uVar1 & ~uVar5) + local_5c) - DAT_3003c7c0;
  uVar3 = (uVar3 >> 0xc | uVar3 * 0x100000) + uVar2;
  uVar5 = (uVar5 + (uVar3 & uVar1 | uVar2 & ~uVar1) + local_48) - DAT_3003c7c4;
  uVar5 = (uVar5 >> 0x1b | uVar5 * 0x20) + uVar3;
  uVar1 = uVar1 + (uVar5 & uVar2 | uVar3 & ~uVar2) + local_34 + DAT_3003c7c8;
  uVar1 = (uVar1 >> 0x17 | uVar1 * 0x200) + uVar5;
  uVar2 = (uVar2 + (uVar1 & uVar3 | uVar5 & ~uVar3) + local_20) - DAT_3003c7cc;
  uVar2 = (uVar2 >> 0x12 | uVar2 * 0x4000) + uVar1;
  uVar3 = (uVar3 + (uVar2 & uVar5 | uVar1 & ~uVar5) + local_4c) - DAT_3003c7d0;
  uVar3 = (uVar3 >> 0xc | uVar3 * 0x100000) + uVar2;
  uVar5 = uVar5 + (uVar3 & uVar1 | uVar2 & ~uVar1) + local_38 + DAT_3003c7d4;
  uVar5 = (uVar5 >> 0x1b | uVar5 * 0x20) + uVar3;
  uVar1 = (uVar1 + (uVar5 & uVar2 | uVar3 & ~uVar2) + local_24) - DAT_3003c7d8;
  uVar1 = (uVar1 >> 0x17 | uVar1 * 0x200) + uVar5;
  uVar2 = (uVar2 + (uVar1 & uVar3 | uVar5 & ~uVar3) + local_50) - DAT_3003c7dc;
  uVar2 = (uVar2 >> 0x12 | uVar2 * 0x4000) + uVar1;
  uVar3 = uVar3 + (uVar2 & uVar5 | uVar1 & ~uVar5) + local_3c + DAT_3003c7e0;
  uVar3 = (uVar3 >> 0xc | uVar3 * 0x100000) + uVar2;
  uVar5 = (uVar5 + (uVar3 & uVar1 | uVar2 & ~uVar1) + local_28) - DAT_3003c7e4;
  uVar5 = (uVar5 >> 0x1b | uVar5 * 0x20) + uVar3;
  uVar1 = (uVar1 + (uVar5 & uVar2 | uVar3 & ~uVar2) + local_54) - DAT_3003c7e8;
  uVar1 = (uVar1 >> 0x17 | uVar1 * 0x200) + uVar5;
  uVar2 = uVar2 + (uVar1 & uVar3 | uVar5 & ~uVar3) + local_40 + DAT_3003c7ec;
  uVar2 = (uVar2 >> 0x12 | uVar2 * 0x4000) + uVar1;
  uVar3 = (uVar3 + (uVar2 & uVar5 | uVar1 & ~uVar5) + local_2c) - DAT_3003c7f0;
  uVar3 = (uVar3 >> 0xc | uVar3 * 0x100000) + uVar2;
  uVar5 = (uVar5 + (uVar1 ^ uVar3 ^ uVar2) + local_48) - DAT_3003c7f4;
  uVar5 = (uVar5 >> 0x1c | uVar5 * 0x10) + uVar3;
  uVar1 = (uVar1 + (uVar2 ^ uVar5 ^ uVar3) + local_3c) - DAT_3003c7f8;
  uVar1 = (uVar1 >> 0x15 | uVar1 * 0x800) + uVar5;
  uVar2 = uVar2 + (uVar3 ^ uVar1 ^ uVar5) + local_30 + DAT_3003c7fc;
  uVar2 = (uVar2 >> 0x10 | uVar2 * 0x10000) + uVar1;
  uVar3 = (uVar3 + (uVar5 ^ uVar2 ^ uVar1) + local_24) - DAT_3003c800;
  uVar3 = (uVar3 >> 9 | uVar3 * 0x800000) + uVar2;
  uVar5 = (uVar5 + (uVar1 ^ uVar3 ^ uVar2) + local_58) - DAT_3003c804;
  uVar5 = (uVar5 >> 0x1c | uVar5 * 0x10) + uVar3;
  uVar1 = uVar1 + (uVar2 ^ uVar5 ^ uVar3) + local_4c + DAT_3003c808;
  uVar1 = (uVar1 >> 0x15 | uVar1 * 0x800) + uVar5;
  uVar2 = (uVar2 + (uVar3 ^ uVar1 ^ uVar5) + local_40) - DAT_3003c80c;
  uVar2 = (uVar2 >> 0x10 | uVar2 * 0x10000) + uVar1;
  uVar3 = (uVar3 + (uVar5 ^ uVar2 ^ uVar1) + local_34) - DAT_3003c810;
  uVar3 = (uVar3 >> 9 | uVar3 * 0x800000) + uVar2;
  uVar5 = uVar5 + (uVar1 ^ uVar3 ^ uVar2) + local_28 + DAT_3003c814;
  uVar5 = (uVar5 >> 0x1c | uVar5 * 0x10) + uVar3;
  uVar1 = (uVar1 + (uVar2 ^ uVar5 ^ uVar3) + local_5c) - DAT_3003c818;
  uVar1 = (uVar1 >> 0x15 | uVar1 * 0x800) + uVar5;
  uVar2 = (uVar2 + (uVar3 ^ uVar1 ^ uVar5) + local_50) - DAT_3003c81c;
  uVar2 = (uVar2 >> 0x10 | uVar2 * 0x10000) + uVar1;
  uVar3 = uVar3 + (uVar5 ^ uVar2 ^ uVar1) + local_44 + DAT_3003c820;
  uVar3 = (uVar3 >> 9 | uVar3 * 0x800000) + uVar2;
  uVar5 = (uVar5 + (uVar1 ^ uVar3 ^ uVar2) + local_38) - DAT_3003c824;
  uVar5 = (uVar5 >> 0x1c | uVar5 * 0x10) + uVar3;
  uVar1 = (uVar1 + (uVar2 ^ uVar5 ^ uVar3) + local_2c) - DAT_3003c828;
  uVar1 = (uVar1 >> 0x15 | uVar1 * 0x800) + uVar5;
  uVar2 = uVar2 + (uVar3 ^ uVar1 ^ uVar5) + local_20 + DAT_3003c82c;
  uVar2 = (uVar2 >> 0x10 | uVar2 * 0x10000) + uVar1;
  uVar3 = (uVar3 + (uVar5 ^ uVar2 ^ uVar1) + local_54) - DAT_3003c830;
  uVar3 = (uVar3 >> 9 | uVar3 * 0x800000) + uVar2;
  uVar5 = (uVar5 + (uVar2 ^ (uVar3 | ~uVar1)) + local_5c) - DAT_3003c834;
  uVar5 = (uVar5 >> 0x1a | uVar5 * 0x40) + uVar3;
  uVar1 = uVar1 + (uVar3 ^ (uVar5 | ~uVar2)) + local_40 + DAT_3003c838;
  uVar1 = (uVar1 >> 0x16 | uVar1 * 0x400) + uVar5;
  uVar2 = (uVar2 + (uVar5 ^ (uVar1 | ~uVar3)) + local_24) - DAT_3003c83c;
  uVar2 = (uVar2 >> 0x11 | uVar2 * 0x8000) + uVar1;
  uVar3 = (uVar3 + (uVar1 ^ (uVar2 | ~uVar5)) + local_48) - DAT_3003c840;
  uVar3 = (uVar3 >> 0xb | uVar3 * 0x200000) + uVar2;
  uVar5 = uVar5 + (uVar2 ^ (uVar3 | ~uVar1)) + local_2c + DAT_3003c844;
  uVar5 = (uVar5 >> 0x1a | uVar5 * 0x40) + uVar3;
  uVar1 = (uVar1 + (uVar3 ^ (uVar5 | ~uVar2)) + local_50) - DAT_3003c848;
  uVar1 = (uVar1 >> 0x16 | uVar1 * 0x400) + uVar5;
  uVar2 = (uVar2 + (uVar5 ^ (uVar1 | ~uVar3)) + local_34) - DAT_3003c84c;
  uVar2 = (uVar2 >> 0x11 | uVar2 * 0x8000) + uVar1;
  uVar3 = (uVar3 + (uVar1 ^ (uVar2 | ~uVar5)) + local_58) - DAT_3003c850;
  uVar3 = (uVar3 >> 0xb | uVar3 * 0x200000) + uVar2;
  uVar5 = uVar5 + (uVar2 ^ (uVar3 | ~uVar1)) + local_3c + DAT_3003c854;
  uVar5 = (uVar5 >> 0x1a | uVar5 * 0x40) + uVar3;
  uVar1 = (uVar1 + (uVar3 ^ (uVar5 | ~uVar2)) + local_20) - DAT_3003c858;
  uVar1 = (uVar1 >> 0x16 | uVar1 * 0x400) + uVar5;
  uVar2 = (uVar2 + (uVar5 ^ (uVar1 | ~uVar3)) + local_44) - DAT_3003c85c;
  uVar2 = (uVar2 >> 0x11 | uVar2 * 0x8000) + uVar1;
  uVar3 = uVar3 + (uVar1 ^ (uVar2 | ~uVar5)) + local_28 + DAT_3003c860;
  uVar3 = (uVar3 >> 0xb | uVar3 * 0x200000) + uVar2;
  uVar5 = (uVar5 + (uVar2 ^ (uVar3 | ~uVar1)) + local_4c) - DAT_3003c864;
  uVar5 = (uVar5 >> 0x1a | uVar5 * 0x40) + uVar3;
  uVar1 = (uVar1 + (uVar3 ^ (uVar5 | ~uVar2)) + local_30) - DAT_3003c868;
  uVar1 = (uVar1 >> 0x16 | uVar1 * 0x400) + uVar5;
  uVar2 = uVar2 + (uVar5 ^ (uVar1 | ~uVar3)) + local_54 + DAT_3003c86c;
  uVar2 = (uVar2 >> 0x11 | uVar2 * 0x8000) + uVar1;
  uVar3 = (uVar3 + (uVar1 ^ (uVar2 | ~uVar5)) + local_38) - DAT_3003c870;
  *param_1 = uVar5 + *param_1;
  param_1[1] = (uVar3 >> 0xb | uVar3 * 0x200000) + uVar2 + param_1[1];
  param_1[2] = uVar2 + param_1[2];
  param_1[3] = uVar1 + param_1[3];
  FUN_3003ba08(&local_5c,0,0x40);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3003c4b8 @ 0x3003C4B8  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: hash_md5_update
 * Константы: 0x3003C4B8
 * ---------------------------------------------------------------- */
void FUN_3003c4b8(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
    *(undefined1 *)(param_1 + uVar1) = *(undefined1 *)(param_2 + uVar1);
  }
  return;
}

/* ----------------------------------------------------------------
 * hash_md5_update @ 0x3003C4F8  (примерный размер ~216 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: FUN_3003ba40, FUN_3003c4b8
 * Вызывают: encrypt_lock_md5_data, hash_md5_final
 * Константы: 0x3003C4F8
 * ---------------------------------------------------------------- */
void hash_md5_update(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x10) >> 3 & 0x3f;
  *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + param_3 * 8;
  if (*(uint *)(param_1 + 0x10) < param_3 << 3) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
  uVar1 = 0x40 - uVar2;
  if (param_3 < uVar1) {
    uVar1 = 0;
  }
  else {
    FUN_3003c4b8(param_1 + uVar2 + 0x18,param_2,uVar1);
    FUN_3003ba40(param_1,param_1 + 0x18);
    for (; uVar1 + 0x3f < param_3; uVar1 = uVar1 + 0x40) {
      FUN_3003ba40(param_1,param_2 + uVar1);
    }
    uVar2 = 0;
  }
  FUN_3003c4b8(param_1 + uVar2 + 0x18,param_2 + uVar1,param_3 - uVar1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3003c5d0 @ 0x3003C5D0  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: hash_md5_final
 * Константы: 0x3003C5D0
 * ---------------------------------------------------------------- */
void FUN_3003c5d0(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 4) {
    *(char *)(param_1 + uVar1) = (char)*(undefined4 *)(param_2 + iVar2 * 4);
    *(char *)(param_1 + uVar1 + 1) = (char)((uint)*(undefined4 *)(param_2 + iVar2 * 4) >> 8);
    *(char *)(param_1 + uVar1 + 2) = (char)*(undefined2 *)(param_2 + iVar2 * 4 + 2);
    *(undefined1 *)(param_1 + uVar1 + 3) = *(undefined1 *)(param_2 + iVar2 * 4 + 3);
    iVar2 = iVar2 + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * hash_md5_final @ 0x3003C65C  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_3003ba08, FUN_3003c5d0, hash_md5_update
 * Вызывают: encrypt_lock_md5_data
 * Константы: 0x3003C65C
 * Данные: DAT_3003c874
 * ---------------------------------------------------------------- */
void hash_md5_final(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_1c [8];
  
  FUN_3003c5d0(auStack_1c,param_1 + 0x10,8);
  uVar2 = *(uint *)(param_1 + 0x10) >> 3 & 0x3f;
  if (uVar2 < 0x38) {
    iVar1 = 0x38 - uVar2;
  }
  else {
    iVar1 = 0x78 - uVar2;
  }
  hash_md5_update(param_1,DAT_3003c874,iVar1);
  hash_md5_update(param_1,auStack_1c,8);
  FUN_3003c5d0(param_2,param_1,0x10);
  FUN_3003ba08(param_1,0,0x58);
  return;
}

/* ----------------------------------------------------------------
 * encrypt_lock_md5_data @ 0x3003C6E8  (примерный размер ~404 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: hash_md5_final, hash_md5_init, hash_md5_update
 * Вызывают: crypto_hash
 * Константы: 0x3003C6E8
 * Данные: DAT_3003c878
 * ---------------------------------------------------------------- */
void encrypt_lock_md5_data(int param_1,undefined2 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar6;
  undefined4 auStack_68 [22];
  undefined4 *puVar5;
  
  puVar3 = auStack_68;
  iVar6 = 0xb;
  puVar4 = DAT_3003c878;
  do {
    puVar5 = puVar4 + 1;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 2;
    uVar2 = *puVar5;
    iVar6 = iVar6 + -1;
    puVar5 = puVar3 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 2;
    *puVar5 = uVar2;
  } while (iVar6 != 0);
  if ((param_1 != 0) && (param_3 != 0)) {
    hash_md5_init(auStack_68,uVar2,auStack_68);
    hash_md5_update(auStack_68,param_1,param_2);
    hash_md5_final(auStack_68,param_3);
  }
  return;
}

/* ----------------------------------------------------------------
 * ran_seed @ 0x3003C87C  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: tickGet
 * Вызывают: crypto_rand, ran_next
 * Константы: 0x3003C87C, 0x7FFFFFFF, 0x7FFFFFFE
 * Данные: DAT_3003ca1c
 * ---------------------------------------------------------------- */
void ran_seed(uint param_1)

{
  if (param_1 == 1) {
    param_1 = tickGet();
  }
  else {
    param_1 = param_1 >> 1;
  }
  if (param_1 == 0x7fffffff) {
    param_1 = 0x7ffffffe;
  }
  *DAT_3003ca1c = param_1 << 1;
  return;
}

/* ----------------------------------------------------------------
 * ran_next @ 0x3003C8C0  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: ran_seed
 * Вызывают: crypto_rand
 * Константы: 0x3003C8C0, 0x7FFFFFFF, 0x7FFFFFFE, 0x80000001
 * Данные: DAT_3003ca1c, DAT_3003ca20, DAT_3003ca24, DAT_3003ca28
 * ---------------------------------------------------------------- */
uint ran_next(void)

{
  uint uVar1;
  uint uVar2;
  
  if (*DAT_3003ca20 == 0) {
    ran_seed(1);
  }
  *DAT_3003ca1c = *DAT_3003ca1c >> 1;
  uVar1 = DAT_3003ca28 * (*DAT_3003ca1c & DAT_3003ca24);
  uVar2 = DAT_3003ca28 * (uint)*(ushort *)((int)DAT_3003ca1c + 2) + (uVar1 >> 0x10);
  uVar1 = ((uVar1 & DAT_3003ca24 | uVar2 * 0x10000) & 0x7fffffff) + (uVar2 >> 0xf);
  if (0x7ffffffe < uVar1) {
    uVar1 = uVar1 + 0x80000001;
  }
  *DAT_3003ca1c = uVar1 << 1;
  return *DAT_3003ca1c;
}

/* ----------------------------------------------------------------
 * ran_dist @ 0x3003C970  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3003C970
 * Данные: DAT_3003ca24
 * ---------------------------------------------------------------- */
uint ran_dist(uint param_1,uint param_2,uint param_3)

{
  return (param_2 & 0xffff) +
         (((param_3 & 0xffff) - (param_2 & 0xffff)) * (param_1 >> 0x10) +
          (((param_3 & 0xffff) - (param_2 & 0xffff)) * (param_1 & DAT_3003ca24) >> 0x10) >> 0x10) &
         0xffff;
}

/* ----------------------------------------------------------------
 * hash @ 0x3003C9C4  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3003C9C4
 * Данные: DAT_3003ca24, DAT_3003ca2c
 * ---------------------------------------------------------------- */
uint hash(uint param_1,uint param_2,uint param_3)

{
  return (int)((param_2 & 0xffff) *
              (DAT_3003ca2c * (param_3 ^ param_1 & DAT_3003ca24 ^ param_1 >> 0x10 & DAT_3003ca24) &
               DAT_3003ca24 & 0xffff)) >> 0x10 & 0xffff;
}

/* ----------------------------------------------------------------
 * nn_digit_mult @ 0x3003D494  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_3003dbec, FUN_3003df3c
 * Константы: 0x3003D494
 * Данные: DAT_3003e4a8
 * ---------------------------------------------------------------- */
void nn_digit_mult(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_2 >> 0x10 & DAT_3003e4a8;
  param_2 = param_2 & DAT_3003e4a8;
  uVar1 = param_3 >> 0x10 & DAT_3003e4a8;
  param_3 = param_3 & DAT_3003e4a8;
  *param_1 = (param_3 & 0xffff) * (param_2 & 0xffff);
  uVar3 = (param_3 & 0xffff) * uVar2;
  param_1[1] = uVar1 * uVar2;
  uVar1 = uVar1 * (param_2 & 0xffff) + uVar3;
  if (uVar1 < uVar3) {
    param_1[1] = param_1[1] + 0x10000;
  }
  *param_1 = uVar1 * 0x10000 + *param_1;
  if (*param_1 < uVar1 * 0x10000) {
    param_1[1] = param_1[1] + 1;
  }
  param_1[1] = param_1[1] + (DAT_3003e4a8 & uVar1 >> 0x10);
  return;
}

/* ----------------------------------------------------------------
 * nn_digit_div @ 0x3003D584  (примерный размер ~660 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: __udiv32
 * Вызывают: nn_div
 * Константы: 0x3003D584
 * Данные: DAT_3003e4a8
 * ---------------------------------------------------------------- */
void nn_digit_div(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint local_30;
  uint local_2c;
  
  uVar1 = param_3 >> 0x10 & DAT_3003e4a8;
  uVar4 = param_3 & DAT_3003e4a8;
  iVar5 = *param_2;
  local_2c = param_2[1];
  if (uVar1 == DAT_3003e4a8) {
    uVar2 = local_2c >> 0x10 & DAT_3003e4a8;
  }
  else {
    uVar2 = __udiv32(local_2c,uVar1 + 1);
  }
  uVar3 = (uVar4 & 0xffff) * (uVar2 & 0xffff);
  local_30 = iVar5 + uVar3 * -0x10000;
  if (uVar3 * -0x10000 - 1 < local_30) {
    local_2c = local_2c - 1;
  }
  local_2c = (local_2c - (DAT_3003e4a8 & uVar3 >> 0x10)) - uVar1 * (uVar2 & 0xffff);
  while ((uVar1 < local_2c || ((local_2c == uVar1 && (uVar4 << 0x10 <= local_30))))) {
    local_30 = local_30 + uVar4 * -0x10000;
    if (uVar4 * -0x10000 - 1 < local_30) {
      local_2c = local_2c - 1;
    }
    local_2c = local_2c - uVar1;
    uVar2 = uVar2 + 1;
  }
  if (uVar1 == DAT_3003e4a8) {
    uVar3 = local_2c & DAT_3003e4a8;
  }
  else {
    uVar3 = __udiv32((local_30 >> 0x10 & DAT_3003e4a8) + local_2c * 0x10000,uVar1 + 1);
  }
  iVar5 = (uVar4 & 0xffff) * (uVar3 & 0xffff);
  uVar1 = uVar1 * (uVar3 & 0xffff);
  local_30 = local_30 - iVar5;
  if (-iVar5 - 1U < local_30) {
    local_2c = local_2c - 1;
  }
  local_30 = local_30 + uVar1 * -0x10000;
  if (uVar1 * -0x10000 - 1 < local_30) {
    local_2c = local_2c - 1;
  }
  local_2c = local_2c - (DAT_3003e4a8 & uVar1 >> 0x10);
  while ((local_2c != 0 || (param_3 <= local_30))) {
    local_30 = local_30 - param_3;
    if (-param_3 - 1 < local_30) {
      local_2c = local_2c + -1;
    }
    uVar3 = uVar3 + 1;
  }
  *param_1 = (uVar3 & 0xffff) + uVar2 * 0x10000;
  return;
}

/* ----------------------------------------------------------------
 * nn_decode @ 0x3003D818  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: rsa_private_block, rsa_public_block
 * Константы: 0x3003D818
 * ---------------------------------------------------------------- */
void nn_decode(int param_1,uint param_2,int param_3,short param_4)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  
  sVar2 = 0;
  param_4 = param_4 + -1;
  while (((int)sVar2 < (int)(param_2 & 0xffff) && (-1 < param_4))) {
    uVar3 = 0;
    for (sVar1 = 0; (-1 < param_4 && (sVar1 < 0x20)); sVar1 = sVar1 + 8) {
      uVar3 = uVar3 | (uint)*(byte *)(param_3 + param_4) << ((int)sVar1 & 0xffU);
      param_4 = param_4 + -1;
    }
    *(uint *)(param_1 + sVar2 * 4) = uVar3;
    sVar2 = sVar2 + 1;
  }
  for (; (int)sVar2 < (int)(param_2 & 0xffff); sVar2 = sVar2 + 1) {
    *(undefined4 *)(param_1 + sVar2 * 4) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * nn_encode @ 0x3003D8D0  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: rsa_private_block, rsa_public_block
 * Константы: 0x3003D8D0
 * ---------------------------------------------------------------- */
void nn_encode(int param_1,short param_2,int param_3,ushort param_4)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar2 = 0;
  param_2 = param_2 + -1;
  while ((uVar2 < param_4 && (-1 < param_2))) {
    uVar3 = *(uint *)(param_3 + (uint)uVar2 * 4);
    for (uVar1 = 0; (-1 < param_2 && ((uVar1 & 0xffff) < 0x20)); uVar1 = uVar1 + 8) {
      *(char *)(param_1 + param_2) = (char)(uVar3 >> (uVar1 & 0xff));
      param_2 = param_2 + -1;
    }
    uVar2 = uVar2 + 1;
  }
  for (; -1 < param_2; param_2 = param_2 + -1) {
    *(undefined1 *)(param_1 + param_2) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * nn_assign @ 0x3003D97C  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 0
 * Вызывают: nn_gcd, nn_mod_exp, nn_mod_inv, nn_mult
 * Константы: 0x3003D97C
 * ---------------------------------------------------------------- */
void nn_assign(int param_1,int param_2,ushort param_3)

{
  ushort uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
    *(undefined4 *)(param_1 + (uint)uVar1 * 4) = *(undefined4 *)(param_2 + (uint)uVar1 * 4);
  }
  return;
}

/* ----------------------------------------------------------------
 * nn_assign_zero @ 0x3003D9C8  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 0
 * Вызывают: nn_assign2_exp, nn_div, nn_mod_exp, nn_mod_inv, nn_mult, rsa_private_block
 * Константы: 0x3003D9C8
 * ---------------------------------------------------------------- */
void nn_assign_zero(int param_1,ushort param_2)

{
  ushort uVar1;
  
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1) {
    *(undefined4 *)(param_1 + (uint)uVar1 * 4) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * nn_assign2_exp @ 0x3003DA0C  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: nn_assign_zero
 * Константы: 0x3003DA0C, 0x3003DA4C
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x3003da4c) */

void nn_assign2_exp(int param_1,uint param_2,uint param_3)

{
  nn_assign_zero(param_1,param_3);
  if ((int)((param_2 & 0xffff) + (param_3 & 0xffff) * -0x20) < 0 !=
      SBORROW4(param_2 & 0xffff,(param_3 & 0xffff) * 0x20)) {
    *(int *)(param_1 + ((int)(param_2 & 0xffff) >> 5) * 4) = 1 << (param_2 & 0x1f);
  }
  return;
}

/* ----------------------------------------------------------------
 * nn_add @ 0x3003DA70  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: nn_mod_inv, rsa_private_block
 * Константы: 0x3003DA70
 * ---------------------------------------------------------------- */
uint nn_add(int param_1,int param_2,int param_3,uint param_4)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  for (sVar1 = 0; (int)sVar1 < (int)(param_4 & 0xffff); sVar1 = sVar1 + 1) {
    uVar3 = uVar2 + *(int *)(param_2 + sVar1 * 4);
    if (uVar3 < uVar2) {
      uVar3 = *(uint *)(param_3 + sVar1 * 4);
    }
    else {
      uVar3 = uVar3 + *(int *)(param_3 + sVar1 * 4);
      if (uVar3 < *(uint *)(param_3 + sVar1 * 4)) {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    *(uint *)(param_1 + sVar1 * 4) = uVar3;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nn_sub @ 0x3003DB00  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: nn_div, nn_mod_inv, rsa_private_block
 * Константы: 0x3003DB00
 * ---------------------------------------------------------------- */
int nn_sub(int param_1,int param_2,int param_3,uint param_4)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  for (sVar1 = 0; (int)sVar1 < (int)(param_4 & 0xffff); sVar1 = sVar1 + 1) {
    uVar3 = *(int *)(param_2 + sVar1 * 4) - iVar2;
    if (-iVar2 - 1U < uVar3) {
      uVar3 = -*(int *)(param_3 + sVar1 * 4) - 1;
    }
    else {
      uVar3 = uVar3 - *(int *)(param_3 + sVar1 * 4);
      if (-*(int *)(param_3 + sVar1 * 4) - 1U < uVar3) {
        iVar2 = 1;
      }
      else {
        iVar2 = 0;
      }
    }
    *(uint *)(param_1 + sVar1 * 4) = uVar3;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * nn_digits @ 0x3003DBA4  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 0
 * Вызывают: nn_bits, nn_div, nn_mod_exp, nn_mult, rsa_private_block, rsa_public_block
 * Константы: 0x3003DBA4
 * ---------------------------------------------------------------- */
short nn_digits(int param_1,short param_2)

{
  param_2 = param_2 + -1;
  while ((-1 < param_2 && (*(int *)(param_1 + param_2 * 4) == 0))) {
    param_2 = param_2 + -1;
  }
  return param_2 + 1;
}

/* ----------------------------------------------------------------
 * FUN_3003dbec @ 0x3003DBEC  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: nn_digit_mult
 * Вызывают: nn_mult
 * Константы: 0x3003DBEC
 * ---------------------------------------------------------------- */
uint FUN_3003dbec(int param_1,int param_2,int param_3,int param_4,ushort param_5)

{
  uint uVar1;
  short sVar2;
  uint *puVar3;
  uint local_2c;
  int local_28;
  
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    for (sVar2 = 0; (int)sVar2 < (int)(uint)param_5; sVar2 = sVar2 + 1) {
      nn_digit_mult(&local_2c,param_3,*(undefined4 *)(param_4 + sVar2 * 4));
      *(uint *)(param_1 + sVar2 * 4) = uVar1 + *(int *)(param_2 + sVar2 * 4);
      uVar1 = (uint)(*(uint *)(param_1 + sVar2 * 4) < uVar1);
      puVar3 = (uint *)(param_1 + sVar2 * 4);
      *puVar3 = *puVar3 + local_2c;
      if (*puVar3 < local_2c) {
        uVar1 = uVar1 + 1;
      }
      uVar1 = uVar1 + local_28;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * nn_mult @ 0x3003DCB8  (примерный размер ~252 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 5
 * Вызывает: FUN_3003dbec, memset, nn_assign, nn_assign_zero, nn_digits
 * Вызывают: nn_mod_inv, nn_mod_mult, rsa_private_block
 * Константы: 0x3003DCB8
 * ---------------------------------------------------------------- */
void nn_mult(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  int aiStackY_4012c [65535];
  int aiStack_12c [66];
  
  memset(aiStack_12c,0,0x108);
  nn_assign_zero(aiStack_12c,(uint)(param_4 << 0x10) >> 0xf);
  sVar1 = nn_digits(param_2,param_4);
  sVar2 = nn_digits(param_3,param_4);
  for (sVar4 = 0; sVar4 < sVar1; sVar4 = sVar4 + 1) {
    iVar3 = FUN_3003dbec(aiStack_12c + sVar4,aiStack_12c + sVar4,
                         *(undefined4 *)(param_2 + sVar4 * 4),param_3,sVar2);
    aiStack_12c[(int)sVar4 + (int)sVar2] = iVar3 + aiStack_12c[(int)sVar4 + (int)sVar2];
  }
  nn_assign(param_1,aiStack_12c,(uint)(param_4 << 0x10) >> 0xf);
  return;
}

/* ----------------------------------------------------------------
 * nn_lshift @ 0x3003DDB4  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: nn_div
 * Константы: 0x3003DDB4
 * ---------------------------------------------------------------- */
uint nn_lshift(int param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  
  if ((param_3 & 0xffff) < 0x20) {
    uVar1 = 0;
    for (sVar2 = 0; (int)sVar2 < (int)(param_4 & 0xffff); sVar2 = sVar2 + 1) {
      uVar3 = *(uint *)(param_2 + sVar2 * 4);
      *(uint *)(param_1 + sVar2 * 4) = uVar1 | uVar3 << (param_3 & 0xff);
      if ((param_3 & 0xffff) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = uVar3 >> ((int)(short)(0x20 - (short)param_3) & 0xffU);
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * nn_rshift @ 0x3003DE40  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: nn_div
 * Константы: 0x3003DE40
 * ---------------------------------------------------------------- */
uint nn_rshift(int param_1,int param_2,uint param_3,short param_4)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_3 & 0xffff) < 0x20) {
    uVar1 = 0;
    for (param_4 = param_4 + -1; -1 < param_4; param_4 = param_4 + -1) {
      uVar2 = *(uint *)(param_2 + param_4 * 4);
      *(uint *)(param_1 + param_4 * 4) = uVar1 | uVar2 >> (param_3 & 0xff);
      if ((param_3 & 0xffff) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = uVar2 << ((int)(short)(0x20 - (short)param_3) & 0xffU);
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * nn_cmp @ 0x3003DEC8  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: nn_div, rsa_private_block, rsa_public_block
 * Константы: 0x3003DEC8, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 nn_cmp(int param_1,int param_2,short param_3)

{
  param_3 = param_3 + -1;
  while( true ) {
    if (param_3 < 0) {
      return 0;
    }
    if (*(uint *)(param_2 + param_3 * 4) < *(uint *)(param_1 + param_3 * 4)) break;
    if (*(uint *)(param_1 + param_3 * 4) < *(uint *)(param_2 + param_3 * 4)) {
      return 0xffffffff;
    }
    param_3 = param_3 + -1;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3003df3c @ 0x3003DF3C  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: nn_digit_mult
 * Вызывают: nn_div
 * Константы: 0x3003DF3C
 * ---------------------------------------------------------------- */
int FUN_3003df3c(int param_1,int param_2,int param_3,int param_4,ushort param_5)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  uint *puVar4;
  int local_2c;
  int local_28;
  
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    for (sVar2 = 0; (int)sVar2 < (int)(uint)param_5; sVar2 = sVar2 + 1) {
      nn_digit_mult(&local_2c,param_3,*(undefined4 *)(param_4 + sVar2 * 4));
      *(int *)(param_1 + sVar2 * 4) = *(int *)(param_2 + sVar2 * 4) - iVar1;
      uVar3 = (uint)(-iVar1 - 1U < *(uint *)(param_1 + sVar2 * 4));
      puVar4 = (uint *)(param_1 + sVar2 * 4);
      *puVar4 = *puVar4 - local_2c;
      if (-local_2c - 1U < *puVar4) {
        uVar3 = uVar3 + 1;
      }
      iVar1 = uVar3 + local_28;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3003e018 @ 0x3003E018  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: nn_bits, nn_div
 * Константы: 0x3003E018
 * ---------------------------------------------------------------- */
short FUN_3003e018(uint param_1)

{
  short sVar1;
  
  sVar1 = 0;
  for (; (sVar1 < 0x20 && (param_1 != 0)); param_1 = param_1 >> 1) {
    sVar1 = sVar1 + 1;
  }
  return sVar1;
}

/* ----------------------------------------------------------------
 * nn_div @ 0x3003E050  (примерный размер ~688 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 10
 * Вызывает: FUN_3003df3c, FUN_3003e018, memset, nn_assign_zero, nn_cmp, nn_digit_div, nn_digits, nn_lshift, nn_rshift, nn_sub
 * Вызывают: nn_mod, nn_mod_inv
 * Константы: 0x3003E050
 * ---------------------------------------------------------------- */
void nn_div(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,
           undefined2 param_6)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_1c0;
  undefined1 auStack_1bc [128];
  undefined1 auStack_13c [4];
  int aiStack_138 [67];
  
  memset(aiStack_138,0,0x10c);
  memset(auStack_1bc,0,0x84);
  uVar3 = nn_digits(param_5,param_6);
  if ((uVar3 & 0xffff) != 0) {
    iVar4 = FUN_3003e018(*(undefined4 *)(param_5 + (uVar3 & 0xffff) * 4 + -4));
    iVar4 = 0x20 - iVar4;
    nn_assign_zero(aiStack_138,uVar3);
    iVar5 = nn_lshift(aiStack_138,param_3,iVar4,param_4);
    aiStack_138[param_4 & 0xffff] = iVar5;
    nn_lshift(auStack_1bc,param_5,iVar4,uVar3);
    iVar5 = *(int *)(auStack_1bc + (uVar3 & 0xffff) * 4 + -4);
    nn_assign_zero(param_1,param_4);
    for (iVar7 = param_4 - uVar3; sVar1 = (short)iVar7, -1 < sVar1; iVar7 = iVar7 + -1) {
      if (iVar5 == -1) {
        local_1c0 = aiStack_138[(int)sVar1 + (uVar3 & 0xffff)];
      }
      else {
        nn_digit_div(&local_1c0,auStack_13c + ((int)sVar1 + (uVar3 & 0xffff)) * 4,iVar5 + 1);
      }
      iVar6 = FUN_3003df3c(aiStack_138 + sVar1,aiStack_138 + sVar1,local_1c0,auStack_1bc,
                           (short)uVar3);
      aiStack_138[(int)sVar1 + (uVar3 & 0xffff)] =
           aiStack_138[(int)sVar1 + (uVar3 & 0xffff)] - iVar6;
      while ((aiStack_138[(int)sVar1 + (uVar3 & 0xffff)] != 0 ||
             (sVar2 = nn_cmp(aiStack_138 + sVar1,auStack_1bc,uVar3), -1 < sVar2))) {
        local_1c0 = local_1c0 + 1;
        iVar6 = nn_sub(aiStack_138 + sVar1,aiStack_138 + sVar1,auStack_1bc,uVar3);
        aiStack_138[(int)sVar1 + (uVar3 & 0xffff)] =
             aiStack_138[(int)sVar1 + (uVar3 & 0xffff)] - iVar6;
      }
      *(int *)(param_1 + sVar1 * 4) = local_1c0;
    }
    nn_assign_zero(param_2,param_6);
    nn_rshift(param_2,aiStack_138,iVar4,uVar3);
  }
  return;
}

/* ----------------------------------------------------------------
 * nn_mod @ 0x3003E300  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: memset, nn_div
 * Вызывают: nn_gcd, nn_mod_mult, rsa_private_block
 * Константы: 0x3003E300
 * ---------------------------------------------------------------- */
void nn_mod(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined2 param_5)

{
  undefined1 auStack_11c [264];
  
  memset(auStack_11c,0,0x108);
  nn_div(auStack_11c,param_1,param_2,param_3,param_4,param_5);
  return;
}

/* ----------------------------------------------------------------
 * nn_mod_mult @ 0x3003E364  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: memset, nn_mod, nn_mult
 * Вызывают: nn_mod_exp, rsa_private_block
 * Константы: 0x3003E364
 * ---------------------------------------------------------------- */
void nn_mod_mult(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                ushort param_5)

{
  undefined1 auStack_120 [264];
  
  memset(auStack_120,0,0x108);
  nn_mult(auStack_120,param_2,param_3,(uint)param_5);
  nn_mod(param_1,auStack_120,((uint)param_5 << 0x10) >> 0xf,param_4,param_5);
  return;
}

/* ----------------------------------------------------------------
 * nn_mod_exp @ 0x3003E3E4  (примерный размер ~520 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 5
 * Вызывает: memset, nn_assign, nn_assign_zero, nn_digits, nn_mod_mult
 * Вызывают: rsa_private_block, rsa_public_block
 * Константы: 0x3003E3E4
 * Данные: DAT_3003e9f0
 * ---------------------------------------------------------------- */
void nn_mod_exp(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5,undefined2 param_6)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_240 [33];
  undefined1 auStack_1bc [132];
  undefined1 auStack_138 [132];
  undefined1 auStack_b4 [132];
  
  memset(auStack_1bc,0,0x18c);
  memset(local_240,0,0x84);
  nn_assign(auStack_1bc,param_2,param_6);
  nn_mod_mult(auStack_138,auStack_1bc,param_2,param_5,param_6);
  nn_mod_mult(auStack_b4,auStack_138,param_2,param_5,param_6);
  nn_assign_zero(local_240,param_6);
  local_240[0] = 1;
  sVar1 = nn_digits(param_3,param_4);
  sVar2 = sVar1;
  while( true ) {
    sVar2 = sVar2 + -1;
    if (sVar2 < 0) break;
    uVar3 = *(uint *)(param_3 + sVar2 * 4);
    uVar5 = 0x20;
    if (sVar2 == (short)(sVar1 + -1)) {
      for (; uVar3 >> 0x1e == 0; uVar3 = uVar3 << 2) {
        uVar5 = uVar5 + DAT_3003e9f0;
      }
    }
    for (uVar4 = 0; (uVar4 & 0xffff) < (uVar5 & 0xffff); uVar4 = uVar4 + 2) {
      nn_mod_mult(local_240,local_240,local_240,param_5,param_6);
      nn_mod_mult(local_240,local_240,local_240,param_5,param_6);
      if (uVar3 >> 0x1e != 0) {
        nn_mod_mult(local_240,local_240,local_240 + (uVar3 >> 0x1e) * 0x21,param_5,param_6);
      }
      uVar3 = uVar3 << 2;
    }
  }
  nn_assign(param_1,local_240,param_6);
  return;
}

/* ----------------------------------------------------------------
 * nn_zero @ 0x3003E5EC  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: nn_gcd, nn_mod_inv
 * Константы: 0x3003E5EC
 * ---------------------------------------------------------------- */
undefined4 nn_zero(int param_1,uint param_2)

{
  short sVar1;
  
  sVar1 = 0;
  while( true ) {
    if ((int)(param_2 & 0xffff) <= (int)sVar1) {
      return 1;
    }
    if (*(int *)(param_1 + sVar1 * 4) != 0) break;
    sVar1 = sVar1 + 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * nn_mod_inv @ 0x3003E638  (примерный размер ~588 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: memset, nn_add, nn_assign, nn_assign_zero, nn_div, nn_mult, nn_sub, nn_zero
 * Константы: 0x3003E638
 * Данные: DAT_3003e9f4
 * ---------------------------------------------------------------- */
void nn_mod_inv(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  short sVar2;
  short sVar3;
  
  iVar1 = -DAT_3003e9f4;
  memset(&stack0x00000200 + iVar1,0,0x84);
  memset(&stack0x00000284 + iVar1,0,0x84);
  memset(&stack0x00000308 + iVar1,0,0x84);
  memset(&stack0xfffffff0 + iVar1,0,0x84);
  memset(&stack0x0000017c + iVar1,0,0x84);
  memset(&stack0x000000f8 + iVar1,0,0x84);
  memset(&stack0x00000074 + iVar1,0,0x84);
  memset(&stack0x0000038c + iVar1,0,0x108);
  nn_assign_zero(&stack0xfffffff0 + iVar1,param_4);
  *(undefined4 *)(&stack0xfffffff0 + iVar1) = 1;
  nn_assign_zero(&stack0x000000f8 + iVar1,param_4);
  nn_assign(&stack0x0000017c + iVar1,param_2,param_4);
  nn_assign(&stack0x00000074 + iVar1,param_3,param_4);
  sVar3 = 1;
  while (sVar2 = nn_zero(&stack0x00000074 + iVar1,param_4), sVar2 == 0) {
    *(undefined1 **)(&stack0xffffffe8 + iVar1) = &stack0x00000074 + iVar1;
    *(short *)(&stack0xffffffec + iVar1) = (short)param_4;
    nn_div(&stack0x00000200 + iVar1,&stack0x00000308 + iVar1,&stack0x0000017c + iVar1,param_4);
    nn_mult(&stack0x0000038c + iVar1,&stack0x00000200 + iVar1,&stack0x000000f8 + iVar1,param_4);
    nn_add(&stack0x00000284 + iVar1,&stack0xfffffff0 + iVar1,&stack0x0000038c + iVar1,param_4);
    nn_assign(&stack0xfffffff0 + iVar1,&stack0x000000f8 + iVar1,param_4);
    nn_assign(&stack0x000000f8 + iVar1,&stack0x00000284 + iVar1,param_4);
    nn_assign(&stack0x0000017c + iVar1,&stack0x00000074 + iVar1,param_4);
    nn_assign(&stack0x00000074 + iVar1,&stack0x00000308 + iVar1,param_4);
    sVar3 = -sVar3;
  }
  if (sVar3 < 0) {
    nn_sub(param_1,param_3,&stack0xfffffff0 + iVar1,param_4);
  }
  else {
    nn_assign(param_1,&stack0xfffffff0 + iVar1,param_4);
  }
  return;
}

/* ----------------------------------------------------------------
 * nn_gcd @ 0x3003E884  (примерный размер ~276 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: memset, nn_assign, nn_mod, nn_zero
 * Константы: 0x3003E884
 * ---------------------------------------------------------------- */
void nn_gcd(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  undefined1 auStack_1a0 [132];
  undefined1 auStack_11c [132];
  undefined1 auStack_98 [132];
  
  memset(auStack_98,0,0x84);
  memset(auStack_11c,0,0x84);
  memset(auStack_1a0,0,0x84);
  nn_assign(auStack_11c,param_2,param_4);
  nn_assign(auStack_1a0,param_3,param_4);
  while (sVar1 = nn_zero(auStack_1a0,param_4), sVar1 == 0) {
    nn_mod(auStack_98,auStack_11c,param_4,auStack_1a0,(short)param_4);
    nn_assign(auStack_11c,auStack_1a0,param_4);
    nn_assign(auStack_1a0,auStack_98,param_4);
  }
  nn_assign(param_1,auStack_11c,param_4);
  return;
}

/* ----------------------------------------------------------------
 * nn_bits @ 0x3003E998  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_3003e018, nn_digits
 * Константы: 0x3003E998
 * Данные: DAT_3003e9f8
 * ---------------------------------------------------------------- */
uint nn_bits(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = nn_digits(param_1,param_2);
  if ((uVar1 & 0xffff) == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_3003e018(*(undefined4 *)(param_1 + (uVar1 & 0xffff) * 4 + -4));
    uVar1 = iVar2 + uVar1 * 0x20 + DAT_3003e9f8 & 0xffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * startSecure @ 0x3003E9FC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3003E9FC, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 startSecure(void)

{
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * secureSupport @ 0x3003EA04  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: DR_NV_Read
 * Константы: 0xFFFFFFFF, 0x3003EA04
 * Данные: DAT_3003eac8
 * ---------------------------------------------------------------- */
undefined4 secureSupport(undefined1 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  bool bVar4;
  short local_c [2];
  
  local_c[0] = 0;
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = DR_NV_Read(DAT_3003eac8,local_c,2);
    if (iVar2 == 0) {
      bVar4 = local_c[0] == 0;
      if (bVar4) {
        local_c[0] = 0;
      }
      uVar3 = (undefined1)local_c[0];
      if (!bVar4) {
        uVar3 = 1;
      }
      *param_1 = uVar3;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * secureAlreadyUse @ 0x3003EA68  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: efuseRead
 * Константы: 0xFFFFFFFF, 0x3003EA68
 * ---------------------------------------------------------------- */
undefined4 secureAlreadyUse(byte *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint local_c;
  
  local_c = 0;
  if (param_1 == (byte *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = efuseRead(0x7f,&local_c,1);
    if (iVar2 == 0) {
      *param_1 = (byte)(local_c >> 1) & 1;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * param_check @ 0x3003EACC  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: create_crypto_key
 * Константы: 0xFFFFFFFF, 0x3003EACC
 * Данные: DAT_3003f268, DAT_3003f26c
 * ---------------------------------------------------------------- */
undefined4 param_check(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  
  if (((param_1 == 0) || (param_4 == 0)) || (param_5 == 0)) {
    printf(DAT_3003f268);
    uVar1 = 0xffffffff;
  }
  else if (param_2 < 1) {
    printf(DAT_3003f26c);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * create_crypto_key @ 0x3003EC38  (примерный размер ~612 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 9
 * Вызывает: crypto_hash, efuseRead, free, logMsg, malloc, memcpy, memset, param_check, printf
 * Константы: 0x3003EC38, 0xFFFFFFFF
 * Данные: DAT_3003f284, DAT_3003f288, DAT_3003f28c, DAT_3003f290, DAT_3003f294, DAT_3003f298, DAT_3003f29c, DAT_3003f2a0
 * ---------------------------------------------------------------- */
undefined4
create_crypto_key(void *param_1,size_t param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  void *pvVar2;
  byte bVar3;
  void *__s;
  
  __s = (void *)0x0;
  iVar1 = param_check(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    __s = malloc(param_2 + 0x10);
    if (__s == (void *)0x0) {
      printf(DAT_3003f288);
    }
    else {
      memset(__s,0,param_2 + 0x10);
      iVar1 = efuseRead(0x10,__s,4);
      if (iVar1 != 0) {
        for (bVar3 = 0; bVar3 < 0x10; bVar3 = bVar3 + 1) {
          if (*(char *)((int)DAT_3003f28c + (uint)bVar3) != '\0') {
            logMsg(DAT_3003f290,0,0,0,0,0,0);
            pvVar2 = memcpy(__s,DAT_3003f28c,0x10);
            if (pvVar2 == (void *)0x0) {
              logMsg(DAT_3003f294,0,0,0,0,0,0);
              goto LAB_3003ee80;
            }
            break;
          }
        }
        if (0xf < bVar3) {
          printf(DAT_3003f298);
          goto LAB_3003ee80;
        }
      }
      for (bVar3 = 0; (bVar3 < 0x10 && (*(char *)((int)__s + (uint)bVar3) == '\0'));
          bVar3 = bVar3 + 1) {
      }
      if (bVar3 < 0x10) {
        memcpy((void *)((int)__s + 0x10),param_1,param_2);
        if (param_3 == 0) {
          iVar1 = crypto_hash(__s,param_2 + 0x10,0,param_4,param_5);
          if (iVar1 == 0) {
LAB_3003ee68:
            if (__s != (void *)0x0) {
              free(__s);
            }
            return 0;
          }
          printf(DAT_3003f2a0);
        }
        else if (param_3 == 1) {
          iVar1 = crypto_hash(__s,param_2 + 0x10,1,param_4,param_5);
          if (iVar1 == 0) goto LAB_3003ee68;
          printf(DAT_3003f2a0);
        }
        else {
          printf(DAT_3003f2a4);
        }
      }
      else {
        printf(DAT_3003f29c);
      }
    }
  }
  else {
    printf(DAT_3003f284);
  }
LAB_3003ee80:
  if (__s != (void *)0x0) {
    free(__s);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * sysClkInit @ 0x3003F928  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: sysClkConnect, sysClkEnable, sysClkRateSet
 * Вызывают: usrRoot
 * Константы: 0x3003F928
 * Данные: DAT_30040598
 * ---------------------------------------------------------------- */
void sysClkInit(void)

{
  sysClkConnect(DAT_30040598,0);
  sysClkRateSet(100);
  sysClkEnable();
  return;
}

/* ----------------------------------------------------------------
 * coprocsDiscover @ 0x3003FAE8  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: coprocLibInit, shellTaskDefaultOptionsGet
 * Константы: 0x3003FAE8
 * ---------------------------------------------------------------- */
void coprocsDiscover(void)

{
  return;
}

/* ----------------------------------------------------------------
 * coprocDescriptorsInit @ 0x3003FAEC  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: coprocLibInit
 * Константы: 0x3003FAEC
 * ---------------------------------------------------------------- */
void coprocDescriptorsInit(int *param_1)

{
  for (; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3003fb10 @ 0x3003FB10  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: dosFsFatInit, dosFsLibInit, dosVDirLibInit
 * Вызывают: usrDosfsInit
 * Константы: 0x3003FB10, 0xFFFFFFFF
 * Данные: DAT_300405c4, DAT_300405c8, DAT_300405cc
 * ---------------------------------------------------------------- */
undefined4 FUN_3003fb10(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_300405c4 == 0) {
    iVar2 = dosFsLibInit(param_1,param_2);
    if (iVar2 == -1) {
      uVar1 = 0xffffffff;
    }
    else {
      dosFsFatInit();
      dosVDirLibInit();
      *DAT_300405c8 = 1;
      *DAT_300405cc = 0x20;
      *DAT_300405c4 = 1;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * timeDelay @ 0x300406B4  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_HKADC_Test
 * Константы: 0x300406B4
 * ---------------------------------------------------------------- */
void timeDelay(int param_1)

{
  bool bVar1;
  undefined4 local_c;
  
  local_c = param_1 * 100;
  do {
    bVar1 = local_c != 0;
    local_c = local_c + -1;
  } while (bVar1);
  return;
}

/* ----------------------------------------------------------------
 * SmthProcInit @ 0x30041738  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30041738
 * Данные: DAT_30041908
 * ---------------------------------------------------------------- */
undefined4 SmthProcInit(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 9; iVar1 = iVar1 + 1) {
    if (((iVar1 != 5) && (iVar1 != 4)) && (iVar1 != 3)) {
      *(undefined4 *)(DAT_30041908 + iVar1 * 4) = 0x19;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * valid_type @ 0x30041CF8  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 213 | Вызывает: 0
 * Вызывают: FUN_30043bd4, FUN_30043e64, FUN_30046174, FUN_30047018, FUN_300471c0, FUN_3004749c, FUN_300475c0, FUN_300483e8, FUN_30048b78, FUN_30048d14
 *           ...
 * Константы: 0x30041CF8
 * ---------------------------------------------------------------- */
void valid_type(void)

{
  return;
}

/* ----------------------------------------------------------------
 * debug_init @ 0x30041CFC  (примерный размер ~1024 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: valid_type
 * Вызывают: jstart_stack
 * Константы: 0x30041CFC
 * Данные: DAT_30042160
 * ---------------------------------------------------------------- */
void debug_init(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0xf2; iVar1 = iVar1 + 1) {
    DAT_30042160[iVar1] = 6;
  }
  valid_type(0);
  *DAT_30042160 = 6;
  valid_type(1);
  DAT_30042160[1] = 1;
  valid_type(2);
  DAT_30042160[2] = 1;
  valid_type(3);
  DAT_30042160[3] = 1;
  valid_type(4);
  DAT_30042160[4] = 1;
  valid_type(5);
  DAT_30042160[5] = 1;
  valid_type(6);
  DAT_30042160[6] = 1;
  valid_type(7);
  DAT_30042160[7] = 1;
  valid_type(8);
  DAT_30042160[8] = 1;
  valid_type(9);
  DAT_30042160[9] = 1;
  valid_type(10);
  DAT_30042160[10] = 6;
  valid_type(0xb);
  DAT_30042160[0xb] = 1;
  valid_type(0xc);
  DAT_30042160[0xc] = 1;
  valid_type(0xd);
  DAT_30042160[0xd] = 1;
  valid_type(0xe);
  DAT_30042160[0xe] = 1;
  valid_type(0xf);
  DAT_30042160[0xf] = 1;
  valid_type(0x10);
  DAT_30042160[0x10] = 1;
  valid_type(0x11);
  DAT_30042160[0x11] = 1;
  valid_type(0x12);
  DAT_30042160[0x12] = 1;
  valid_type(0x14);
  DAT_30042160[0x14] = 6;
  valid_type(0x15);
  DAT_30042160[0x15] = 1;
  valid_type(0x16);
  DAT_30042160[0x16] = 1;
  valid_type(0x17);
  DAT_30042160[0x17] = 1;
  valid_type(0x18);
  DAT_30042160[0x18] = 1;
  valid_type(0x1e);
  DAT_30042160[0x1e] = 6;
  valid_type(0x22);
  DAT_30042160[0x22] = 1;
  valid_type(0x1f);
  DAT_30042160[0x1f] = 1;
  valid_type(0x20);
  DAT_30042160[0x20] = 1;
  valid_type(0x21);
  DAT_30042160[0x21] = 1;
  valid_type(0x23);
  DAT_30042160[0x23] = 1;
  valid_type(0x24);
  DAT_30042160[0x24] = 1;
  valid_type(0x28);
  DAT_30042160[0x28] = 6;
  valid_type(0x2b);
  DAT_30042160[0x2b] = 1;
  valid_type(0x2a);
  DAT_30042160[0x2a] = 1;
  valid_type(0x29);
  DAT_30042160[0x29] = 1;
  valid_type(0x2c);
  DAT_30042160[0x2c] = 1;
  valid_type(0x2d);
  DAT_30042160[0x2d] = 1;
  valid_type(0x3c);
  DAT_30042160[0x3c] = 6;
  valid_type(0x3d);
  DAT_30042160[0x3d] = 1;
  valid_type(0x3e);
  DAT_30042160[0x3e] = 1;
  valid_type(0x3f);
  DAT_30042160[0x3f] = 1;
  valid_type(0x40);
  DAT_30042160[0x40] = 1;
  valid_type(0x41);
  DAT_30042160[0x41] = 1;
  valid_type(0x42);
  DAT_30042160[0x42] = 1;
  valid_type(0x43);
  DAT_30042160[0x43] = 1;
  valid_type(0x44);
  DAT_30042160[0x44] = 1;
  valid_type(0x45);
  DAT_30042160[0x45] = 1;
  valid_type(0xf0);
  DAT_30042160[0xf0] = 6;
  valid_type(0xf1);
  DAT_30042160[0xf1] = 1;
  return;
}

/* ----------------------------------------------------------------
 * check_byte_order @ 0x30042164  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: jos_init
 * Константы: 0x30042164, 0x300421A4
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300421a4) */

void check_byte_order(void)

{
  return;
}

/* ----------------------------------------------------------------
 * check_types_length @ 0x300421D4  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: jos_init
 * Константы: 0x300421D4, 0x3004221C, 0x300421E4, 0x30042254
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x3004221c) */
/* WARNING: Removing unreachable block (ram,0x300421e4) */
/* WARNING: Removing unreachable block (ram,0x30042254) */

void check_types_length(void)

{
  return;
}

/* ----------------------------------------------------------------
 * jgeneric_dsr @ 0x300423F0  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: jtask_schedule_d, os_dprintf, os_panic
 * Константы: 0x300423F0
 * Данные: DAT_30042720, DAT_30042724, DAT_30042728, DAT_3004272c
 * ---------------------------------------------------------------- */
void jgeneric_dsr(int *param_1)

{
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_30042720,DAT_30042724,0x15);
    os_dprintf(DAT_30042728);
    os_panic(DAT_3004272c,DAT_30042724,0x15);
  }
  if (*param_1 != 0) {
    jtask_schedule_d(param_1[2],0,*param_1,param_1[1],DAT_30042724,0x1e);
  }
  return;
}

/* ----------------------------------------------------------------
 * jdevice_delete @ 0x300432F0  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 5
 * Вызывает: BSP_FreeDbg, jos_safe_check, os_dprintf, os_printf, valid_type
 * Вызывают: add_generic_controller_ex, del_generic_controller_ex
 * Константы: 0x300432F0
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_30043530
 * ---------------------------------------------------------------- */
void jdevice_delete(int param_1)

{
  valid_type(0x1f);
  if ((2 < *(int *)(DAT_3004347c + 0x78)) && (2 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,0xef);
    os_printf(DAT_30043530,param_1);
  }
  jos_safe_check(DAT_30043484,0xf1);
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      BSP_FreeDbg(*(undefined4 *)(param_1 + 0x1c),DAT_30043484,0xf7);
    }
    if (*(int *)(param_1 + 0x20) != 0) {
      BSP_FreeDbg(*(undefined4 *)(param_1 + 0x20),DAT_30043484,0xf9);
    }
    BSP_FreeDbg(param_1,DAT_30043484,0xfa);
  }
  return;
}

/* ----------------------------------------------------------------
 * jdevice_add @ 0x3004339C  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_30043428, jos_safe_check, os_dprintf, os_printf, valid_type
 * Вызывают: add_generic_controller_ex
 * Константы: 0x3004339C
 * Данные: DAT_3004347c, DAT_30043480, DAT_30043484, DAT_30043534, DAT_30043538, DAT_3004353c, DAT_30043540
 * ---------------------------------------------------------------- */
int jdevice_add(undefined4 param_1)

{
  int iVar1;
  
  jos_safe_check(DAT_30043484,DAT_30043534);
  valid_type(0x1f);
  if ((2 < *(int *)(DAT_3004347c + 0x78)) && (2 < *(int *)(DAT_3004347c + 0x7c))) {
    os_dprintf(DAT_30043480,DAT_30043484,DAT_30043538);
    os_printf(DAT_3004353c,param_1);
  }
  iVar1 = FUN_30043428(0x38,1,DAT_30043484,DAT_30043540);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 4) = param_1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30043428 @ 0x30043428  (примерный размер ~284 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: BSP_MallocDbg, memset
 * Вызывают: j_device_set_nameunit, jdevice_add
 * Константы: 0x30043428
 * ---------------------------------------------------------------- */
void * FUN_30043428(size_t param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)BSP_MallocDbg(param_1,0,param_3,param_4);
  if ((param_2 == 1) && (__s != (void *)0x0)) {
    memset(__s,0,param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * jdrivers_uninit @ 0x30043544  (примерный размер ~396 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 4
 * Вызывает: BSP_FreeDbg, os_dprintf, os_printf, valid_type
 * Вызывают: jdrivers_init, jstart_stack, jstop_stack
 * Константы: 0x30043544
 * Данные: DAT_30044504, DAT_30044508, DAT_3004450c, DAT_30044510, DAT_30044514, DAT_30044518, DAT_3004451c, DAT_300445b4
 * ---------------------------------------------------------------- */
void jdrivers_uninit(void)

{
  int *piVar1;
  int *piVar2;
  
  valid_type(0x22);
  if ((2 < *(int *)(DAT_30044504 + 0x78)) && (2 < *(int *)(DAT_30044504 + 0x88))) {
    os_dprintf(DAT_30044508,DAT_3004450c,0x33);
    os_printf(DAT_30044510);
  }
  piVar2 = *(int **)(DAT_30044514 + 0x14);
  while (piVar2 != (int *)0x0) {
    valid_type(0x22);
    if ((2 < *(int *)(DAT_30044504 + 0x78)) && (2 < *(int *)(DAT_30044504 + 0x88))) {
      os_dprintf(DAT_30044508,DAT_3004450c,0x38);
      os_printf(DAT_30044518,piVar2[2],piVar2,piVar2[5]);
    }
    if ((((char)piVar2[4] != '\0') && (valid_type(0x22), 0 < *(int *)(DAT_30044504 + 0x78))) &&
       (0 < *(int *)(DAT_30044504 + 0x88))) {
      os_dprintf(DAT_30044508,DAT_3004450c,0x3e);
      os_printf(DAT_3004451c,piVar2[2],piVar2[1],(char)piVar2[4]);
    }
    if (*(int *)(*piVar2 + 0x18) != 0) {
      (**(code **)(*piVar2 + 0x18))();
    }
    piVar1 = (int *)piVar2[5];
    BSP_FreeDbg(piVar2,DAT_3004450c,0x46);
    piVar2 = piVar1;
  }
  *(undefined4 *)(DAT_30044514 + 0x14) = 0;
  valid_type(0x22);
  if ((2 < *(int *)(DAT_30044504 + 0x78)) && (2 < *(int *)(DAT_30044504 + 0x88))) {
    os_dprintf(DAT_30044508,DAT_3004450c,0x4b);
    os_printf(DAT_300445b4);
  }
  return;
}

/* ----------------------------------------------------------------
 * jdrivers_init @ 0x300436D0  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: jdrivers_uninit, os_dprintf, os_printf, valid_type
 * Вызывают: jstart_stack
 * Константы: 0x300436D0
 * Данные: DAT_30044504, DAT_30044508, DAT_3004450c, DAT_300445b8, DAT_300445bc, DAT_300445c0, DAT_300446a8
 * ---------------------------------------------------------------- */
int jdrivers_init(void)

{
  int iVar1;
  int iVar2;
  
  *DAT_300445b8 = 0;
  DAT_300445b8[1] = DAT_300445b8;
  valid_type(0x22);
  if ((2 < *(int *)(DAT_30044504 + 0x78)) && (2 < *(int *)(DAT_30044504 + 0x88))) {
    os_dprintf(DAT_30044508,DAT_3004450c,0x1f);
    os_printf(DAT_300445bc);
  }
  iVar2 = 0;
  while( true ) {
    if (*(int *)(DAT_300445c0 + iVar2 * 4) == 0) {
      valid_type(0x22);
      if ((2 < *(int *)(DAT_30044504 + 0x78)) && (2 < *(int *)(DAT_30044504 + 0x88))) {
        os_dprintf(DAT_30044508,DAT_3004450c,0x2a);
        os_printf(DAT_300446a8,iVar2);
      }
      return 0;
    }
    iVar1 = (**(code **)(DAT_300445c0 + iVar2 * 4))();
    if (iVar1 != 0) break;
    iVar2 = iVar2 + 1;
  }
  jdrivers_uninit();
  return iVar1;
}

/* ----------------------------------------------------------------
 * jdriver_register @ 0x300437C4  (примерный размер ~604 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_30044654, os_dprintf, os_printf, valid_type
 * Вызывают: syn_hsfc_init
 * Константы: 0x300437C4
 * Данные: DAT_30044504, DAT_30044508, DAT_3004450c, DAT_30044514, DAT_300446ac, DAT_300446b0, DAT_300446b4, DAT_300446b8
 * ---------------------------------------------------------------- */
undefined4 jdriver_register(int param_1,int param_2,int param_3,int param_4,undefined2 param_5)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_3 == 0) {
    valid_type(0x22);
    if ((0 < *(int *)(DAT_30044504 + 0x78)) && (0 < *(int *)(DAT_30044504 + 0x88))) {
      os_dprintf(DAT_30044508,DAT_3004450c,0x56);
      os_printf(DAT_300446ac);
    }
    uVar1 = 10;
  }
  else if (param_2 == 0) {
    valid_type(0x22);
    if ((0 < *(int *)(DAT_30044504 + 0x78)) && (0 < *(int *)(DAT_30044504 + 0x88))) {
      os_dprintf(DAT_30044508,DAT_3004450c,0x5d);
      os_printf(DAT_300446b0,param_3);
    }
    uVar1 = 10;
  }
  else if ((*(int *)(param_2 + 4) == 0) || (*(int *)(param_2 + 8) == 0)) {
    valid_type(0x22);
    if ((0 < *(int *)(DAT_30044504 + 0x78)) && (0 < *(int *)(DAT_30044504 + 0x88))) {
      os_dprintf(DAT_30044508,DAT_3004450c,100);
      os_printf(DAT_300446b4,param_3);
    }
    uVar1 = 10;
  }
  else if ((param_1 == 1) || (param_1 == 2)) {
    piVar2 = (int *)FUN_30044654(0x20,0,DAT_3004450c,0x70);
    if (piVar2 == (int *)0x0) {
      uVar1 = 7;
    }
    else {
      piVar2[1] = param_1;
      *piVar2 = param_2;
      piVar2[2] = param_3;
      piVar2[1] = param_1;
      piVar2[3] = param_4;
      *(undefined1 *)(piVar2 + 4) = 0;
      *(undefined2 *)((int)piVar2 + 0x12) = param_5;
      *(undefined1 *)((int)piVar2 + 0x11) = 0;
      piVar2[5] = *(int *)(DAT_30044514 + 0x14);
      *(int **)(DAT_30044514 + 0x14) = piVar2;
      piVar2[6] = 0;
      piVar2[7] = (int)(piVar2 + 6);
      valid_type(0x22);
      if ((2 < *(int *)(DAT_30044504 + 0x78)) && (2 < *(int *)(DAT_30044504 + 0x88))) {
        os_dprintf(DAT_30044508,DAT_3004450c,0x84);
        os_printf(DAT_300446bc,piVar2,param_1,param_3,param_5);
      }
      uVar1 = 0;
    }
  }
  else {
    valid_type(0x22);
    if ((0 < *(int *)(DAT_30044504 + 0x78)) && (0 < *(int *)(DAT_30044504 + 0x88))) {
      os_dprintf(DAT_30044508,DAT_3004450c,0x6b);
      os_printf(DAT_300446b8,param_3,param_1);
    }
    uVar1 = 10;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * jdriver_detach @ 0x30043A20  (примерный размер ~436 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 7
 * Вызывает: BSP_FreeDbg, jdbg_check_context, jos_core_lock_check, jos_safe_check, os_dprintf, os_printf, valid_type
 * Вызывают: del_generic_controller_ex, j_device_detach
 * Константы: 0x30043A20
 * Данные: DAT_30044504, DAT_30044508, DAT_3004450c, DAT_300446c0, DAT_300446c4, DAT_300446c8
 * ---------------------------------------------------------------- */
void jdriver_detach(int *param_1)

{
  valid_type(0x22);
  if ((3 < *(int *)(DAT_30044504 + 0x78)) && (3 < *(int *)(DAT_30044504 + 0x88))) {
    os_dprintf(DAT_30044508,DAT_3004450c,0x8b);
    os_printf(DAT_300446c0,param_1);
  }
  jos_safe_check(DAT_3004450c,0x8d);
  jos_core_lock_check(DAT_3004450c,0x8e);
  jdbg_check_context(0x30,DAT_3004450c,0x8f);
  if (*param_1 == 0) {
    valid_type(0x22);
    if ((0 < *(int *)(DAT_30044504 + 0x78)) && (0 < *(int *)(DAT_30044504 + 0x88))) {
      os_dprintf(DAT_30044508,DAT_3004450c,0x94);
      os_printf(DAT_300446c4);
    }
  }
  else {
    valid_type(0x22);
    if ((2 < *(int *)(DAT_30044504 + 0x78)) && (2 < *(int *)(DAT_30044504 + 0x88))) {
      os_dprintf(DAT_30044508,DAT_3004450c,0x99);
      os_printf(DAT_300446c8,*param_1,*(undefined4 *)(*param_1 + 8));
    }
    if (*(int *)(*(int *)*param_1 + 8) != 0) {
      (**(code **)(*(int *)*param_1 + 8))(param_1);
    }
    if (param_1[2] != 0) {
      BSP_FreeDbg(param_1[2],DAT_3004450c,0x9f);
    }
    *(char *)(*param_1 + 0x10) = *(char *)(*param_1 + 0x10) + -1;
    if (param_1[0xc] == 0) {
      *(int *)(*param_1 + 0x1c) = param_1[0xd];
    }
    else {
      *(int *)(param_1[0xc] + 0x34) = param_1[0xd];
    }
    *(int *)param_1[0xd] = param_1[0xc];
    *param_1 = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30043bd4 @ 0x30043BD4  (примерный размер ~656 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: BSP_FreeDbg, FUN_30044654, j_device_set_bus, j_device_set_nameunit, os_dprintf, os_printf, valid_type
 * Вызывают: jdriver_attach
 * Константы: 0x30043BD4
 * Данные: DAT_30044504, DAT_30044508, DAT_3004450c, DAT_30044514, DAT_300446cc, DAT_300446d0, DAT_300446d4, DAT_300446d8
 * ---------------------------------------------------------------- */
int FUN_30043bd4(int *param_1,int param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  
  valid_type(0x22);
  if ((2 < *(int *)(DAT_30044504 + 0x78)) && (2 < *(int *)(DAT_30044504 + 0x88))) {
    os_dprintf(DAT_30044508,DAT_3004450c,0xae);
    os_printf(DAT_300446cc,param_2);
  }
  for (piVar3 = *(int **)(DAT_30044514 + 0x14);
      (piVar3 != (int *)0x0 && ((piVar3[1] != 1 || (piVar3[3] != param_2))));
      piVar3 = (int *)piVar3[5]) {
  }
  if (piVar3 == (int *)0x0) {
    valid_type(0x22);
    if ((1 < *(int *)(DAT_30044504 + 0x78)) && (1 < *(int *)(DAT_30044504 + 0x88))) {
      os_dprintf(DAT_30044508,DAT_3004450c,0xb8);
      os_printf(DAT_300446d0,param_2);
    }
    return 4;
  }
  valid_type(0x22);
  if ((4 < *(int *)(DAT_30044504 + 0x78)) && (4 < *(int *)(DAT_30044504 + 0x88))) {
    os_dprintf(DAT_30044508,DAT_3004450c,0xbd);
    os_printf(DAT_300446d4,piVar3,piVar3[2],*(undefined2 *)((int)piVar3 + 0x12));
  }
  if (*(short *)((int)piVar3 + 0x12) != 0) {
    iVar2 = FUN_30044654(*(undefined2 *)((int)piVar3 + 0x12),1,DAT_3004450c,0xc2);
    param_1[2] = iVar2;
    if (param_1[2] == 0) {
      iVar2 = 7;
      goto LAB_30043e3c;
    }
  }
  j_device_set_bus(param_1,param_3);
  param_1[3] = 1;
  uVar1 = *(undefined1 *)((int)piVar3 + 0x11);
  *(char *)((int)piVar3 + 0x11) = *(char *)((int)piVar3 + 0x11) + '\x01';
  j_device_set_nameunit(param_1,piVar3[2],uVar1);
  valid_type(0x22);
  if ((3 < *(int *)(DAT_30044504 + 0x78)) && (3 < *(int *)(DAT_30044504 + 0x88))) {
    os_dprintf(DAT_30044508,DAT_3004450c,0xd0);
    os_printf(DAT_300446d8,param_1,param_1[2],*(undefined2 *)((int)piVar3 + 0x12));
  }
  iVar2 = (**(code **)(*piVar3 + 4))(param_1);
  if (iVar2 == 0) {
    *param_1 = (int)piVar3;
    *(char *)(piVar3 + 4) = (char)piVar3[4] + '\x01';
    return 0;
  }
  valid_type(0x22);
  if ((1 < *(int *)(DAT_30044504 + 0x78)) && (1 < *(int *)(DAT_30044504 + 0x88))) {
    os_dprintf(DAT_30044508,DAT_3004450c,0xd7);
    os_printf(DAT_300446dc,piVar3[2],iVar2);
  }
LAB_30043e3c:
  if (param_1[2] != 0) {
    BSP_FreeDbg(param_1[2],DAT_3004450c,0xe3);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_30043e64 @ 0x30043E64  (примерный размер ~1012 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: BSP_FreeDbg, FUN_30044654, j_device_set_nameunit, os_dprintf, os_printf, valid_type
 * Вызывают: jdriver_attach
 * Константы: 0x30043E64
 * Данные: DAT_30044504, DAT_30044508, DAT_3004450c, DAT_30044514, DAT_300446e0, DAT_300446e4, DAT_300446e8, DAT_300446ec
 * ---------------------------------------------------------------- */
int FUN_30043e64(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  piVar3 = (int *)0x0;
  iVar5 = 0;
  valid_type(0x22);
  if ((2 < *(int *)(DAT_30044504 + 0x78)) && (2 < *(int *)(DAT_30044504 + 0x88))) {
    os_dprintf(DAT_30044508,DAT_3004450c,0xef);
    os_printf(DAT_300446e0,param_1);
  }
  piVar4 = *(int **)(DAT_30044514 + 0x14);
  do {
    if (piVar4 == (int *)0x0) {
      if (piVar3 == (int *)0x0) {
        valid_type(0x22);
        if ((1 < *(int *)(DAT_30044504 + 0x78)) && (1 < *(int *)(DAT_30044504 + 0x88))) {
          os_dprintf(DAT_30044508,DAT_3004450c,DAT_300446e8);
          os_printf(DAT_300446ec,param_1);
        }
        iVar5 = *DAT_300446f0;
        *DAT_300446f0 = *DAT_300446f0 + 1;
        j_device_set_nameunit(param_1,DAT_300446f4,iVar5);
        iVar5 = 4;
      }
      else {
        valid_type(0x22);
        if ((2 < *(int *)(DAT_30044504 + 0x78)) && (2 < *(int *)(DAT_30044504 + 0x88))) {
          os_dprintf(DAT_30044508,DAT_3004450c,DAT_300446f8);
          os_printf(DAT_300446fc,piVar3,piVar3[2]);
        }
        if (*(short *)((int)piVar3 + 0x12) != 0) {
          iVar5 = FUN_30044654(*(undefined2 *)((int)piVar3 + 0x12),1,DAT_3004450c,0x11c);
          param_1[2] = iVar5;
          if (param_1[2] == 0) {
            valid_type(0x22);
            if ((0 < *(int *)(DAT_30044504 + 0x78)) && (0 < *(int *)(DAT_30044504 + 0x88))) {
              os_dprintf(DAT_30044508,DAT_3004450c,0x120);
              os_printf(DAT_30044700,*(undefined2 *)((int)piVar3 + 0x12));
            }
            iVar5 = *DAT_300446f0;
            *DAT_300446f0 = *DAT_300446f0 + 1;
            j_device_set_nameunit(param_1,DAT_300446f4,iVar5);
            return 7;
          }
        }
        uVar1 = *(undefined1 *)((int)piVar3 + 0x11);
        *(char *)((int)piVar3 + 0x11) = *(char *)((int)piVar3 + 0x11) + '\x01';
        j_device_set_nameunit(param_1,piVar3[2],uVar1);
        iVar5 = (**(code **)(*piVar3 + 4))(param_1);
        if (iVar5 == 0) {
          valid_type(0x22);
          if ((3 < *(int *)(DAT_30044504 + 0x78)) && (3 < *(int *)(DAT_30044504 + 0x88))) {
            os_dprintf(DAT_30044508,DAT_3004450c,DAT_30044710);
            os_printf(DAT_30044714,param_1,piVar3[2]);
          }
          *(char *)(piVar3 + 4) = (char)piVar3[4] + '\x01';
          *param_1 = (int)piVar3;
          param_1[3] = 2;
          iVar5 = 0;
        }
        else {
          valid_type(0x22);
          if ((0 < *(int *)(DAT_30044504 + 0x78)) && (0 < *(int *)(DAT_30044504 + 0x88))) {
            os_dprintf(DAT_30044508,DAT_3004450c,DAT_30044704);
            os_printf(DAT_30044708,piVar3[2],iVar5);
          }
          BSP_FreeDbg(param_1[2],DAT_3004450c,DAT_3004470c);
          param_1[2] = 0;
          iVar2 = *DAT_300446f0;
          *DAT_300446f0 = *DAT_300446f0 + 1;
          j_device_set_nameunit(param_1,DAT_300446f4,iVar2);
        }
      }
      return iVar5;
    }
    valid_type(0x22);
    if ((3 < *(int *)(DAT_30044504 + 0x78)) && (3 < *(int *)(DAT_30044504 + 0x88))) {
      os_dprintf(DAT_30044508,DAT_3004450c,0xf5);
      os_printf(DAT_300446e4,piVar4,piVar4[2]);
    }
    if (piVar4[1] == 2) {
      if (*(short *)((int)piVar4 + 0x12) != 0) {
        iVar2 = FUN_30044654(*(undefined2 *)((int)piVar4 + 0x12),1,DAT_3004450c,0xfd);
        param_1[2] = iVar2;
        if (param_1[2] == 0) goto LAB_30043f98;
      }
      iVar2 = (**(code **)*piVar4)(param_1);
      BSP_FreeDbg(param_1[2],DAT_3004450c,0x104);
      param_1[2] = 0;
      if (iVar5 < iVar2) {
        piVar3 = piVar4;
        iVar5 = iVar2;
      }
    }
LAB_30043f98:
    piVar4 = (int *)piVar4[5];
  } while( true );
}

/* ----------------------------------------------------------------
 * jdriver_attach @ 0x30044258  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 8
 * Вызывает: FUN_30043bd4, FUN_30043e64, jdbg_check_context, jos_core_lock_check, jos_safe_check, os_dprintf, os_printf, valid_type
 * Вызывают: add_generic_controller_ex, j_device_probe_and_attach
 * Константы: 0x30044258
 * Данные: DAT_30044504, DAT_30044508, DAT_3004450c, DAT_30044718, DAT_3004471c, DAT_30044720, DAT_30044724
 * ---------------------------------------------------------------- */
int jdriver_attach(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  jos_safe_check(DAT_3004450c,DAT_30044718);
  jos_core_lock_check(DAT_3004450c,DAT_3004471c);
  jdbg_check_context(0x30,DAT_3004450c,0x144);
  if (param_2 == (int *)0x0) {
    valid_type(0x22);
    if ((0 < *(int *)(DAT_30044504 + 0x78)) && (0 < *(int *)(DAT_30044504 + 0x88))) {
      os_dprintf(DAT_30044508,DAT_3004450c,0x148);
      os_printf(DAT_30044720);
    }
    iVar1 = 10;
  }
  else {
    if (param_1 == 1) {
      iVar1 = FUN_30043bd4(param_2,param_3,param_4);
    }
    else if (param_1 == 2) {
      iVar1 = FUN_30043e64(param_2);
    }
    else {
      iVar1 = 10;
      valid_type(0x22);
      if ((0 < *(int *)(DAT_30044504 + 0x78)) && (0 < *(int *)(DAT_30044504 + 0x88))) {
        os_dprintf(DAT_30044508,DAT_3004450c,0x158);
        os_printf(DAT_30044724,param_1);
      }
    }
    if (iVar1 == 0) {
      param_2[0xc] = 0;
      param_2[0xd] = *(int *)(*param_2 + 0x1c);
      **(int **)(*param_2 + 0x1c) = (int)param_2;
      *(int **)(*param_2 + 0x1c) = param_2 + 0xc;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * jstart_stack @ 0x30044740  (примерный размер ~1068 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 18
 * Вызывает: debug_init, jdrivers_init, jdrivers_uninit, jos_init, jos_safe_leave_d, jos_uninit, jslave_disable, jslave_enable, jslave_init, jslave_uninit, os_dprintf, os_hw_init, os_hw_uninit, os_printf
 *           ...
 * Вызывают: jusb_entry
 * Константы: 0x30044740
 * Данные: DAT_300452a8, DAT_300452ac, DAT_300452b0, DAT_300452b4, DAT_300452b8, DAT_300452bc, DAT_300452c0, DAT_300452c4
 * ---------------------------------------------------------------- */
int jstart_stack(int *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  byte bVar6;
  
  bVar3 = false;
  bVar1 = false;
  bVar2 = false;
  bVar6 = 0;
  debug_init();
  os_printf(DAT_300452a8,DAT_300452ac);
  if (param_1 == (int *)0x0) {
    valid_type(0x20);
    if ((0 < *(int *)(DAT_300452b0 + 0x78)) && (0 < *(int *)(DAT_300452b0 + 0x80))) {
      os_dprintf(DAT_300452b4,DAT_300452b8,0x7f);
      os_printf(DAT_300452bc);
    }
    return 10;
  }
  *DAT_300452c0 = (int)param_1;
  *DAT_300452c4 = *param_1;
  iVar4 = jos_init(param_1);
  if (iVar4 != 0) {
    valid_type(0x20);
    if (*(int *)(DAT_300452b0 + 0x78) < 1) {
      return iVar4;
    }
    if (*(int *)(DAT_300452b0 + 0x80) < 1) {
      return iVar4;
    }
    os_dprintf(DAT_300452b4,DAT_300452b8,0x8e);
    uVar5 = uwe_str(iVar4);
    os_printf(DAT_300452c8,uVar5);
    return iVar4;
  }
  iVar4 = uw_app_init();
  if ((iVar4 == 0) && (iVar4 = jdrivers_init(), iVar4 == 0)) {
    bVar3 = true;
    if ((*param_1 == 2) || ((*param_1 == 3 || (*param_1 == 4)))) {
      iVar4 = jslave_init(param_1);
      if (iVar4 != 0) {
        valid_type(0x20);
        if ((0 < *(int *)(DAT_300452b0 + 0x78)) && (0 < *(int *)(DAT_300452b0 + 0x80))) {
          os_dprintf(DAT_300452b4,DAT_300452b8,0xbd);
          uVar5 = uwe_str(iVar4);
          os_printf(DAT_300452cc,uVar5);
        }
        goto LAB_30044a90;
      }
      bVar2 = true;
    }
    iVar4 = os_hw_init(param_1);
    if (iVar4 == 0) {
      bVar1 = true;
      if ((*DAT_300452c4 == 2) || (*DAT_300452c4 == 3)) {
        for (bVar6 = 0; bVar6 < *(byte *)(param_1 + 1); bVar6 = bVar6 + 1) {
          if ((*(int *)(param_1[2] + (uint)bVar6 * 0x1c + 4) != 0) &&
             (iVar4 = jslave_enable(*(undefined4 *)(param_1[2] + (uint)bVar6 * 0x1c + 0x18)),
             iVar4 != 0)) {
            valid_type(0x20);
            if ((0 < *(int *)(DAT_300452b0 + 0x78)) && (0 < *(int *)(DAT_300452b0 + 0x80))) {
              os_dprintf(DAT_300452b4,DAT_300452b8,0xdb);
              uVar5 = uwe_str(iVar4);
              os_printf(DAT_300452d4,bVar6,uVar5);
            }
            goto LAB_30044a90;
          }
        }
      }
      valid_type(0x20);
      if ((2 < *(int *)(DAT_300452b0 + 0x78)) && (2 < *(int *)(DAT_300452b0 + 0x80))) {
        os_dprintf(DAT_300452b4,DAT_300452b8,0xfc);
        os_printf(DAT_300452d8);
      }
      jos_safe_leave_d(DAT_300452b8,0xfe);
      return 0;
    }
    valid_type(0x20);
    if ((0 < *(int *)(DAT_300452b0 + 0x78)) && (0 < *(int *)(DAT_300452b0 + 0x80))) {
      os_dprintf(DAT_300452b4,DAT_300452b8,0xc9);
      uVar5 = uwe_str(iVar4);
      os_printf(DAT_300452d0,uVar5);
    }
  }
LAB_30044a90:
  for (; bVar6 != 0; bVar6 = bVar6 - 1) {
    if (*(int *)(param_1[2] + (uint)bVar6 * 0x1c + 4) != 0) {
      jslave_disable(*(undefined4 *)(param_1[2] + (uint)bVar6 * 0x1c + 0x18));
    }
  }
  if (bVar1) {
    os_hw_uninit();
  }
  if (bVar2) {
    jslave_uninit();
  }
  if (bVar3) {
    jdrivers_uninit();
  }
  uw_app_uninit();
  jos_uninit();
  valid_type(0x20);
  if ((0 < *(int *)(DAT_300452b0 + 0x78)) && (0 < *(int *)(DAT_300452b0 + 0x80))) {
    os_dprintf(DAT_300452b4,DAT_300452b8,DAT_300452dc);
    uVar5 = uwe_str(iVar4);
    os_printf(DAT_300452e0,uVar5);
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * jstop_stack @ 0x30044B6C  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 9
 * Вызывает: BSP_USB_FreeDevProfile, jdrivers_uninit, jos_safe_enter_d, jos_uninit, jslave_disable, jslave_uninit, mem_log_print, os_hw_uninit, uw_app_uninit
 * Вызывают: jusb_exit
 * Константы: 0x30044B6C
 * Данные: DAT_300452b8, DAT_300452c0, DAT_300452c4, DAT_300452e4
 * ---------------------------------------------------------------- */
void jstop_stack(void)

{
  int iVar1;
  
  jos_safe_enter_d(DAT_300452b8,0x130);
  *DAT_300452e4 = 1;
  if (((*DAT_300452c4 == 2) || (*DAT_300452c4 == 3)) || (*DAT_300452c4 == 4)) {
    for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(*DAT_300452c0 + 4); iVar1 = iVar1 + 1) {
      jslave_disable(*(undefined4 *)(iVar1 * 0x1c + *(int *)(*DAT_300452c0 + 8) + 0x18));
    }
  }
  os_hw_uninit();
  if (((*DAT_300452c4 == 2) || (*DAT_300452c4 == 3)) || (*DAT_300452c4 == 4)) {
    jslave_uninit();
  }
  jdrivers_uninit();
  uw_app_uninit();
  jos_uninit();
  mem_log_print();
  BSP_USB_FreeDevProfile(0);
  *DAT_300452e4 = 0;
  return;
}

/* ----------------------------------------------------------------
 * add_generic_controller_ex @ 0x30044C58  (примерный размер ~896 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 12
 * Вызывает: j_device_add_to_pending_controllers_list, j_device_set_bus, j_device_set_controller_id, j_device_set_ivars, j_device_set_params, jdevice_add, jdevice_delete, jdriver_attach, os_dprintf, os_printf, uwe_str, valid_type
 * Вызывают: add_generic_controller
 * Константы: 0x30044C58
 * Данные: DAT_300452b0, DAT_300452b4, DAT_300452b8, DAT_300452c4, DAT_300452e8, DAT_300452ec, DAT_300452f0, DAT_300452f4
 * ---------------------------------------------------------------- */
int add_generic_controller_ex
              (undefined4 param_1,int param_2,int *param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  valid_type(0x20);
  if ((2 < *(int *)(DAT_300452b0 + 0x78)) && (2 < *(int *)(DAT_300452b0 + 0x80))) {
    os_dprintf(DAT_300452b4,DAT_300452b8,0x178);
    os_printf(DAT_300452e8);
  }
  iVar2 = jdevice_add(0);
  if (iVar2 == 0) {
    iVar4 = 7;
  }
  else {
    iVar4 = *DAT_300452c4;
    uVar1 = param_2 >> 0xc;
    if (iVar4 == 1) {
      if (((uVar1 & 0xf) != 1) && ((uVar1 & 0xf) != 3)) {
        iVar4 = 10;
        valid_type(0x20);
        if ((0 < *(int *)(DAT_300452b0 + 0x78)) && (0 < *(int *)(DAT_300452b0 + 0x80))) {
          os_dprintf(DAT_300452b4,DAT_300452b8,DAT_300452ec);
          uVar3 = uwe_str(10);
          os_printf(DAT_300452f0,0,uVar3);
        }
        goto LAB_30044fc0;
      }
    }
    else if (iVar4 == 2) {
      if (((uVar1 & 0xf) != 2) && ((uVar1 & 0xf) != 3)) {
        iVar4 = 10;
        valid_type(0x20);
        if ((0 < *(int *)(DAT_300452b0 + 0x78)) && (0 < *(int *)(DAT_300452b0 + 0x80))) {
          os_dprintf(DAT_300452b4,DAT_300452b8,DAT_300452f4);
          uVar3 = uwe_str(10);
          os_printf(DAT_300452f8,0,uVar3);
        }
        goto LAB_30044fc0;
      }
    }
    else if ((((iVar4 == 3) && ((uVar1 & 0xf) != 1)) && ((uVar1 & 0xf) != 2)) &&
            ((uVar1 & 0xf) != 3)) {
      iVar4 = 10;
      valid_type(0x20);
      if ((0 < *(int *)(DAT_300452b0 + 0x78)) && (0 < *(int *)(DAT_300452b0 + 0x80))) {
        os_dprintf(DAT_300452b4,DAT_300452b8,DAT_300452fc);
        uVar3 = uwe_str(10);
        os_printf(DAT_30045300,0,uVar3);
      }
      goto LAB_30044fc0;
    }
    valid_type(0x20);
    if ((2 < *(int *)(DAT_300452b0 + 0x78)) && (2 < *(int *)(DAT_300452b0 + 0x80))) {
      os_dprintf(DAT_300452b4,DAT_300452b8,DAT_30045304);
      os_printf(DAT_30045308);
    }
    j_device_set_controller_id(iVar2,param_2);
    j_device_set_bus(iVar2,param_1);
    j_device_set_ivars(iVar2,param_4);
    j_device_set_params(iVar2,param_5);
    if (param_5 == 0) {
      valid_type(0x20);
      if ((2 < *(int *)(DAT_300452b0 + 0x78)) && (2 < *(int *)(DAT_300452b0 + 0x80))) {
        os_dprintf(DAT_300452b4,DAT_300452b8,0x1b4);
        os_printf(DAT_3004530c,0);
      }
      *param_3 = iVar2;
      j_device_add_to_pending_controllers_list(iVar2);
      return 0;
    }
    iVar4 = jdriver_attach(1,iVar2,param_2,param_1);
    if (iVar4 == 0) {
      *(int *)(param_5 + 0x18) = iVar2;
      *param_3 = iVar2;
      return 0;
    }
    valid_type(0x20);
    if ((0 < *(int *)(DAT_300452b0 + 0x78)) && (0 < *(int *)(DAT_300452b0 + 0x80))) {
      os_dprintf(DAT_300452b4,DAT_300452b8,DAT_30045310);
      uVar3 = uwe_str(iVar4);
      os_printf(DAT_30045314,0,uVar3);
    }
  }
LAB_30044fc0:
  if (iVar2 != 0) {
    jdevice_delete(iVar2);
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * add_generic_controller @ 0x30044FD8  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: add_generic_controller_ex, jcore_safe_enter_d, jcore_safe_leave_d
 * Вызывают: os_hw_init
 * Константы: 0x30044FD8
 * Данные: DAT_300452b8, DAT_30045318
 * ---------------------------------------------------------------- */
undefined4
add_generic_controller(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  jcore_safe_enter_d(DAT_300452b8,0x1e0);
  uVar1 = add_generic_controller_ex(param_1,param_2,param_4,0,param_3);
  jcore_safe_leave_d(DAT_300452b8,DAT_30045318);
  return uVar1;
}

/* ----------------------------------------------------------------
 * generic_controller_suspend @ 0x30045030  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: j_device_suspend, jcore_safe_enter_d, jcore_safe_leave_d, os_dprintf, os_printf, valid_type
 * Константы: 0x30045030
 * Данные: DAT_300452b0, DAT_300452b4, DAT_300452b8, DAT_3004531c, DAT_30045320, DAT_30045324, DAT_30045328
 * ---------------------------------------------------------------- */
undefined4 generic_controller_suspend(undefined4 param_1)

{
  undefined4 uVar1;
  
  valid_type(0x20);
  if ((2 < *(int *)(DAT_300452b0 + 0x78)) && (2 < *(int *)(DAT_300452b0 + 0x80))) {
    os_dprintf(DAT_300452b4,DAT_300452b8,DAT_3004531c);
    os_printf(DAT_30045320,param_1);
  }
  jcore_safe_enter_d(DAT_300452b8,DAT_30045324);
  uVar1 = j_device_suspend(param_1);
  jcore_safe_leave_d(DAT_300452b8,DAT_30045328);
  return uVar1;
}

/* ----------------------------------------------------------------
 * generic_controller_resume @ 0x300450A8  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: j_device_resume, jcore_safe_enter_d, jcore_safe_leave_d, os_dprintf, os_printf, valid_type
 * Константы: 0x300450A8
 * Данные: DAT_300452b0, DAT_300452b4, DAT_300452b8, DAT_3004532c, DAT_30045330, DAT_30045334
 * ---------------------------------------------------------------- */
undefined4 generic_controller_resume(undefined4 param_1)

{
  undefined4 uVar1;
  
  valid_type(0x20);
  if ((2 < *(int *)(DAT_300452b0 + 0x78)) && (2 < *(int *)(DAT_300452b0 + 0x80))) {
    os_dprintf(DAT_300452b4,DAT_300452b8,DAT_3004532c);
    os_printf(DAT_30045330,param_1);
  }
  jcore_safe_enter_d(DAT_300452b8,DAT_30045334);
  uVar1 = j_device_resume(param_1);
  jcore_safe_leave_d(DAT_300452b8,0x1f8);
  return uVar1;
}

/* ----------------------------------------------------------------
 * del_generic_controller_ex @ 0x30045120  (примерный размер ~272 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: j_device_attached, jdevice_delete, jdriver_detach, os_dprintf, os_printf, valid_type
 * Вызывают: del_generic_controller
 * Константы: 0x30045120
 * Данные: DAT_300452b0, DAT_300452b4, DAT_300452b8, DAT_30045338, DAT_3004533c, DAT_30045340, DAT_30045344, DAT_30045348
 * ---------------------------------------------------------------- */
undefined4 del_generic_controller_ex(int param_1)

{
  int iVar1;
  
  valid_type(0x20);
  if ((2 < *(int *)(DAT_300452b0 + 0x78)) && (2 < *(int *)(DAT_300452b0 + 0x80))) {
    os_dprintf(DAT_300452b4,DAT_300452b8,DAT_30045338);
    os_printf(DAT_3004533c,param_1);
  }
  iVar1 = j_device_attached(param_1);
  if (iVar1 != 0) {
    valid_type(0x20);
    if ((2 < *(int *)(DAT_300452b0 + 0x78)) && (2 < *(int *)(DAT_300452b0 + 0x80))) {
      os_dprintf(DAT_300452b4,DAT_300452b8,DAT_30045340);
      os_printf(DAT_30045344);
    }
    jdriver_detach(param_1);
  }
  jdevice_delete(param_1);
  if (*(int *)(param_1 + 0x24) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x18) = 0;
  }
  valid_type(0x20);
  if ((2 < *(int *)(DAT_300452b0 + 0x78)) && (2 < *(int *)(DAT_300452b0 + 0x80))) {
    os_dprintf(DAT_300452b4,DAT_300452b8,DAT_30045348);
    os_printf(DAT_3004534c);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * del_generic_controller @ 0x30045230  (примерный размер ~304 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: del_generic_controller_ex, jcore_safe_enter_d, jcore_safe_leave_d, os_dprintf, os_printf, valid_type
 * Вызывают: os_hw_uninit
 * Константы: 0x30045230
 * Данные: DAT_300452b0, DAT_300452b4, DAT_300452b8, DAT_30045350, DAT_30045354, DAT_30045358, DAT_3004535c
 * ---------------------------------------------------------------- */
undefined4 del_generic_controller(undefined4 param_1)

{
  undefined4 uVar1;
  
  valid_type(0x20);
  if ((2 < *(int *)(DAT_300452b0 + 0x78)) && (2 < *(int *)(DAT_300452b0 + 0x80))) {
    os_dprintf(DAT_300452b4,DAT_300452b8,DAT_30045350);
    os_printf(DAT_30045354,param_1);
  }
  jcore_safe_enter_d(DAT_300452b8,DAT_30045358);
  uVar1 = del_generic_controller_ex(param_1);
  jcore_safe_leave_d(DAT_300452b8,DAT_3004535c);
  return uVar1;
}

/* ----------------------------------------------------------------
 * jmark_time_v @ 0x30045360  (примерный размер ~356 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: os_get_time, os_printf, os_strlen
 * Константы: 0x30045360
 * Данные: DAT_30045c68, DAT_30045c6c, DAT_30045c70, DAT_30045c74, DAT_30045c78, DAT_30045c7c, DAT_30045c80, DAT_30045c84
 * ---------------------------------------------------------------- */
void jmark_time_v(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  *DAT_30045c68 = *DAT_30045c68 + 1;
  if ((*DAT_30045c6c != 0) && (*DAT_30045c70 < 100)) {
    os_get_time(DAT_30045c74 + *DAT_30045c70 * 0x14);
    *(undefined4 *)(DAT_30045c78 + *DAT_30045c70 * 0x14) = param_1;
    *(undefined4 *)(DAT_30045c7c + *DAT_30045c70 * 0x14) = param_2;
    uVar1 = os_strlen(*DAT_30045c80 + *DAT_30045c84);
    if (uVar1 == 0) {
      *(undefined4 *)(*DAT_30045c70 * 0x14 + DAT_30045c90) = 0;
    }
    else {
      if (*DAT_30045c88 < uVar1) {
        os_printf(DAT_30045c8c);
      }
      *(int *)(DAT_30045c90 + *DAT_30045c70 * 0x14) = *DAT_30045c80 + *DAT_30045c84;
      *DAT_30045c84 = *DAT_30045c84 + uVar1 + 1;
      *DAT_30045c88 = *DAT_30045c88 - (uVar1 + 1);
    }
    *DAT_30045c70 = *DAT_30045c70 + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * time_diff @ 0x300454C4  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: os_dprintf, os_panic
 * Вызывают: dbg_get_time_diff, jdump_time
 * Константы: 0x300454C4
 * Данные: DAT_30045c94, DAT_30045c98, DAT_30045c9c, DAT_30045ca0, DAT_30045ca4
 * ---------------------------------------------------------------- */
int time_diff(int *param_1,int *param_2)

{
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_30045c94,DAT_30045c98,0x37);
    os_dprintf(DAT_30045c9c);
    os_panic(DAT_30045ca0,DAT_30045c98,0x37);
  }
  if (param_2 == (int *)0x0) {
    os_dprintf(DAT_30045c94,DAT_30045c98,0x38);
    os_dprintf(DAT_30045ca4);
    os_panic(DAT_30045ca0,DAT_30045c98,0x38);
  }
  return (*param_1 - *param_2) * 1000 +
         ((int)((param_1[1] - param_2[1]) + ((uint)(param_1[1] - param_2[1] >> 0x1f) >> 0x16)) >> 10
         );
}

/* ----------------------------------------------------------------
 * jdump_time @ 0x30045560  (примерный размер ~300 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: os_printf, time_diff
 * Вызывают: perf_free
 * Константы: 0x30045560
 * Данные: DAT_30045c68, DAT_30045c70, DAT_30045c74, DAT_30045c78, DAT_30045c7c, DAT_30045c84, DAT_30045c88, DAT_30045c90
 * ---------------------------------------------------------------- */
void jdump_time(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  os_printf(DAT_30045ca8);
  for (iVar2 = 0; iVar2 < *DAT_30045c70; iVar2 = iVar2 + 1) {
    uVar3 = DAT_30045cac;
    if (*(int *)(DAT_30045c90 + iVar2 * 0x14) != 0) {
      uVar3 = *(undefined4 *)(DAT_30045c90 + iVar2 * 0x14);
    }
    uVar1 = time_diff(DAT_30045c74 + iVar2 * 0x14,DAT_30045c74);
    os_printf(DAT_30045cb0,iVar2,uVar1,*(undefined4 *)(DAT_30045c78 + iVar2 * 0x14),
              *(undefined4 *)(DAT_30045c7c + iVar2 * 0x14),uVar3);
  }
  if (0 < *DAT_30045c68 - *DAT_30045c70) {
    os_printf(DAT_30045cb4,*DAT_30045c68,*DAT_30045c68 - *DAT_30045c70);
  }
  *DAT_30045c68 = 0;
  *DAT_30045c70 = 0;
  *DAT_30045c84 = 0;
  *DAT_30045c88 = 0x6400;
  return;
}

/* ----------------------------------------------------------------
 * perf_init @ 0x3004568C  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30046974, os_printf
 * Константы: 0x3004568C
 * Данные: DAT_30045c6c, DAT_30045c80, DAT_30045c98, DAT_30045cb8
 * ---------------------------------------------------------------- */
void perf_init(void)

{
  int iVar1;
  
  if (*DAT_30045c6c == 0) {
    iVar1 = FUN_30046974(0x6400,1,DAT_30045c98,0x61);
    *DAT_30045c80 = iVar1;
    if (*DAT_30045c80 == 0) {
      os_printf(DAT_30045cb8);
    }
    else {
      *DAT_30045c6c = 1;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * perf_free @ 0x300456E8  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_FreeDbg, jdump_time
 * Константы: 0x300456E8
 * Данные: DAT_30045c6c, DAT_30045c80, DAT_30045c98
 * ---------------------------------------------------------------- */
void perf_free(void)

{
  if (*DAT_30045c6c != 0) {
    jdump_time();
    *DAT_30045c6c = 0;
    BSP_FreeDbg(*DAT_30045c80,DAT_30045c98,0x71);
  }
  return;
}

/* ----------------------------------------------------------------
 * uwe_str @ 0x30045C4C  (примерный размер ~420 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 0
 * Вызывают: FUN_3004749c, FUN_30057fc8, add_generic_controller_ex, core_disconnect, jstart_stack, uwd_cdc_send_notification
 * Константы: 0x30045C4C, 0x30045C64
 * Данные: DAT_30045cd8, DAT_30046a20
 * ---------------------------------------------------------------- */
undefined4 uwe_str(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x16) {
                    /* WARNING: Could not recover jumptable at 0x30045c64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_30045cd8 + param_1 * 4))();
    return uVar1;
  }
  return DAT_30046a20;
}

/* ----------------------------------------------------------------
 * jvirt_to_sg @ 0x30045DF0  (примерный размер ~368 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: os_dprintf, os_memcpy, os_panic
 * Вызывают: core_request_complete
 * Константы: 0x30045DF0
 * Данные: DAT_30046a24, DAT_30046a28, DAT_30046a2c, DAT_30046a30, DAT_30046a34, DAT_30046a38, DAT_30046a3c, DAT_30046a40
 * ---------------------------------------------------------------- */
void jvirt_to_sg(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  
  if (param_2 == 0) {
    os_dprintf(DAT_30046a24,DAT_30046a28,0x1d8);
    os_dprintf(DAT_30046a2c);
    os_panic(DAT_30046a30,DAT_30046a28,0x1d8);
  }
  if (param_1 == 0) {
    os_dprintf(DAT_30046a24,DAT_30046a28,DAT_30046a34);
    os_dprintf(DAT_30046a38);
    os_panic(DAT_30046a30,DAT_30046a28,DAT_30046a34);
  }
  uVar3 = 0;
  for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + *(int *)(param_2 + uVar2 * 0xc + 8)) {
    if (*(int *)(param_2 + (uint)uVar3 * 0xc) == 0) {
      os_dprintf(DAT_30046a24,DAT_30046a28,DAT_30046a3c);
      os_dprintf(DAT_30046a40,uVar3);
      os_panic(DAT_30046a30,DAT_30046a28,DAT_30046a3c);
    }
    if (param_3 - uVar4 < *(uint *)(param_2 + (uint)uVar3 * 0xc + 8)) {
      iVar1 = param_3 - uVar4;
    }
    else {
      iVar1 = *(int *)(param_2 + (uint)uVar3 * 0xc + 8);
    }
    os_memcpy(*(undefined4 *)(param_2 + (uint)uVar3 * 0xc),param_1 + uVar4,iVar1);
    uVar2 = (uint)uVar3;
    uVar3 = uVar3 + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * jsg_to_virt @ 0x30045F60  (примерный размер ~368 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: os_dprintf, os_memcpy, os_panic
 * Вызывают: core_read_data, core_send_data
 * Константы: 0x30045F60
 * Данные: DAT_30046a24, DAT_30046a28, DAT_30046a30, DAT_30046a44, DAT_30046a48, DAT_30046a4c, DAT_30046a50, DAT_30046a54
 * ---------------------------------------------------------------- */
void jsg_to_virt(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    os_dprintf(DAT_30046a24,DAT_30046a28,DAT_30046a44);
    os_dprintf(DAT_30046a48);
    os_panic(DAT_30046a30,DAT_30046a28,DAT_30046a44);
  }
  if (param_2 == 0) {
    os_dprintf(DAT_30046a24,DAT_30046a28,DAT_30046a4c);
    os_dprintf(DAT_30046a50);
    os_panic(DAT_30046a30,DAT_30046a28,DAT_30046a4c);
  }
  uVar3 = 0;
  for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + *(int *)(param_1 + uVar2 * 0xc + 8)) {
    if (*(int *)(param_1 + (uint)uVar3 * 0xc) == 0) {
      os_dprintf(DAT_30046a24,DAT_30046a28,DAT_30046a54);
      os_dprintf(DAT_30046a58,uVar3);
      os_panic(DAT_30046a30,DAT_30046a28,DAT_30046a54);
    }
    if (param_3 - uVar4 < *(uint *)(param_1 + (uint)uVar3 * 0xc + 8)) {
      iVar1 = param_3 - uVar4;
    }
    else {
      iVar1 = *(int *)(param_1 + (uint)uVar3 * 0xc + 8);
    }
    os_memcpy(param_2 + uVar4,*(undefined4 *)(param_1 + (uint)uVar3 * 0xc),iVar1);
    uVar2 = (uint)uVar3;
    uVar3 = uVar3 + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * jdbg_pattern_start_update @ 0x300460D0  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x300460D0
 * Данные: DAT_30046a24, DAT_30046a28, DAT_30046a30, DAT_30046a5c, DAT_30046a60, DAT_30046a64, DAT_30046a68, DAT_30046a6c
 * ---------------------------------------------------------------- */
undefined4 jdbg_pattern_start_update(int *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_30046a24,DAT_30046a28,0x200);
    os_dprintf(DAT_30046a5c);
    os_panic(DAT_30046a30,DAT_30046a28,0x200);
  }
  if ((param_2 & 3) == 0) {
    *param_1 = *param_1 + (param_2 >> 2);
    uVar1 = 0;
  }
  else {
    valid_type(0x24);
    if ((0 < *(int *)(DAT_30046a60 + 0x78)) && (0 < *(int *)(DAT_30046a60 + 0x90))) {
      os_dprintf(DAT_30046a64,DAT_30046a28,DAT_30046a68);
      os_printf(DAT_30046a6c,param_2);
    }
    uVar1 = 0x10;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30046174 @ 0x30046174  (примерный размер ~372 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: jdbg_pattern_check, jdbg_pattern_set
 * Константы: 0x30046174
 * Данные: DAT_30046a28, DAT_30046a60, DAT_30046a64, DAT_30046a70, DAT_30046a74, DAT_30046a78, DAT_30046a7c, DAT_30046a80
 * ---------------------------------------------------------------- */
undefined4 FUN_30046174(byte *param_1,int param_2,int *param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_28;
  
  valid_type(0x24);
  if ((4 < *(int *)(DAT_30046a60 + 0x78)) && (4 < *(int *)(DAT_30046a60 + 0x90))) {
    os_dprintf(DAT_30046a64,DAT_30046a28,DAT_30046a70);
    if (param_5 == 0) {
      local_28 = DAT_30046a78;
    }
    else {
      local_28 = DAT_30046a74;
    }
    os_printf(DAT_30046a7c,local_28,param_1,*param_3,param_2,param_4,param_4);
  }
  do {
    if (param_2 == 0) {
      return 0;
    }
    uVar2 = param_4 + *param_3;
    uVar3 = 0;
    for (; (uVar3 < 4 && (param_2 != 0)); param_2 = param_2 + -1) {
      uVar1 = uVar2 >> ((uVar3 & 0x1f) << 3);
      uVar4 = uVar1 & 0xff;
      if (param_5 == 0) {
        if (*param_1 != uVar4) {
          valid_type(0x24);
          if ((0 < *(int *)(DAT_30046a60 + 0x78)) && (0 < *(int *)(DAT_30046a60 + 0x90))) {
            os_dprintf(DAT_30046a64,DAT_30046a28,0x228);
            os_printf(DAT_30046a80,param_1,*param_3,*param_1,uVar4,uVar2,uVar2,uVar3);
          }
          return 10;
        }
      }
      else {
        *param_1 = (byte)uVar1;
      }
      uVar3 = uVar3 + 1;
      param_1 = param_1 + 1;
    }
    *param_3 = *param_3 + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * jdbg_hex_dump @ 0x300462E8  (примерный размер ~1196 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: os_dprintf, os_memset, os_printf
 * Вызывают: jdbg_pattern_check, jdbg_pattern_set
 * Константы: 0x300462E8
 * Данные: DAT_30046a64, DAT_30046a84, DAT_30046a88
 * ---------------------------------------------------------------- */
void jdbg_hex_dump(undefined4 param_1,undefined4 param_2,byte *param_3,int param_4,byte param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char local_b4 [6];
  char acStack_ae [134];
  
  uVar4 = (uint)param_5;
  if (param_3 != (byte *)0x0) {
    if (uVar4 < 0x21) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
    }
    else {
      uVar4 = 0x20;
    }
    os_dprintf(DAT_30046a64,param_1,param_2);
    os_printf(DAT_30046a84,param_3,param_4);
    iVar2 = 0;
    while (param_4 != 0) {
      os_memset(local_b4,0x20,0x8c);
      uVar3 = 0;
      for (; (uVar3 < uVar4 && (param_4 != 0)); param_4 = param_4 + -1) {
        bVar1 = *param_3;
        uVar5 = (uint)bVar1;
        if ((uint)((int)uVar5 >> 4) < 10) {
          local_b4[uVar3 * 3] = (bVar1 >> 4) + 0x30;
        }
        else {
          local_b4[uVar3 * 3] = (bVar1 >> 4) + 0x37;
        }
        if ((uVar5 & 0xf) < 10) {
          local_b4[uVar3 * 3 + 1] = (bVar1 & 0xf) + 0x30;
        }
        else {
          local_b4[uVar3 * 3 + 1] = (bVar1 & 0xf) + 0x37;
        }
        if (uVar5 - 0x20 < 0x5f) {
          local_b4[uVar4 * 3 + uVar3 + 2] = bVar1;
        }
        else {
          local_b4[uVar4 * 3 + uVar3 + 2] = '.';
        }
        uVar3 = uVar3 + 1;
        param_3 = param_3 + 1;
      }
      local_b4[uVar4 * 4 + 2] = '\0';
      os_dprintf(DAT_30046a64,param_1,param_2);
      os_printf(DAT_30046a88,uVar4 * iVar2,local_b4);
      iVar2 = iVar2 + 1;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * jdbg_pattern_set @ 0x30046794  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_30046174, jdbg_hex_dump, os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x30046794, 0x30046518
 * Данные: DAT_30046a24, DAT_30046a28, DAT_30046a30, DAT_30046a60, DAT_30046a64, DAT_30046a74, DAT_30046a8c, DAT_30046a90
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x30046518) */

int jdbg_pattern_set(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_30046a24,DAT_30046a28,DAT_30046ab8);
    os_dprintf(DAT_30046a94);
    os_panic(DAT_30046a30,DAT_30046a28,DAT_30046ab8);
  }
  valid_type(0x24);
  if ((4 < *(int *)(DAT_30046a60 + 0x78)) && (4 < *(int *)(DAT_30046a60 + 0x90))) {
    os_dprintf(DAT_30046a64,DAT_30046a28,DAT_30046abc);
    os_printf(DAT_30046ac0,*param_1,param_2,param_3);
  }
  uStack_30 = 0;
  valid_type(0x24);
  if ((4 < *(int *)(DAT_30046a60 + 0x78)) && (4 < *(int *)(DAT_30046a60 + 0x90))) {
    os_dprintf(DAT_30046a64,DAT_30046a28,DAT_30046a8c);
    uStack_28 = DAT_30046a74;
    os_printf(DAT_30046a90,DAT_30046a74,param_1,param_2,param_3,1);
  }
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_30046a24,DAT_30046a28,0x23c);
    os_dprintf(DAT_30046a94);
    os_panic(DAT_30046a30,DAT_30046a28,0x23c);
  }
  if (*param_1 == 0) {
    if (param_1[2] == 0) {
      valid_type(0x24);
      if ((0 < *(int *)(DAT_30046a60 + 0x78)) && (0 < *(int *)(DAT_30046a60 + 0x90))) {
        os_dprintf(DAT_30046a64,DAT_30046a28,0x25c);
        os_printf(DAT_30046aa8);
      }
      return 0xb;
    }
    piVar2 = (int *)param_1[2];
    uVar4 = param_2;
    while( true ) {
      uVar3 = uVar4;
      if ((uint)piVar2[2] < uVar4) {
        uVar3 = piVar2[2];
      }
      if (piVar2[2] == 0) {
        os_dprintf(DAT_30046a24,DAT_30046a28,DAT_30046a98);
        os_dprintf(DAT_30046a9c);
        os_panic(DAT_30046a30,DAT_30046a28,DAT_30046a98);
      }
      if (*piVar2 == 0) {
        os_dprintf(DAT_30046a24,DAT_30046a28,DAT_30046aa0);
        os_dprintf(DAT_30046aa4);
        os_panic(DAT_30046a30,DAT_30046a28,DAT_30046aa0);
      }
      uVar4 = uVar4 - uVar3;
      iVar1 = FUN_30046174(*piVar2,uVar3,&uStack_30,param_3,1);
      if ((iVar1 != 0) || (uVar4 == 0)) break;
      piVar2 = piVar2 + 3;
    }
  }
  else {
    iVar1 = FUN_30046174(*param_1,param_2,&uStack_30,param_3,1);
  }
  if (iVar1 != 0) {
    valid_type(0x24);
    if ((0 < *(int *)(DAT_30046a60 + 0x78)) && (0 < *(int *)(DAT_30046a60 + 0x90))) {
      os_dprintf(DAT_30046a64,DAT_30046a28,DAT_30046aac);
      os_printf(DAT_30046ab0,param_2,uStack_30,uStack_30,param_3,param_3);
    }
    if (((*param_1 != 0) && (valid_type(0x24), 0 < *(int *)(DAT_30046a60 + 0x78))) &&
       (0 < *(int *)(DAT_30046a60 + 0x90))) {
      uStack_2c = param_2;
      if (0x400 < param_2) {
        uStack_2c = 0x400;
      }
      jdbg_hex_dump(DAT_30046a28,DAT_30046ab4,*param_1,uStack_2c,0);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * jdbg_pattern_check @ 0x30046838  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: FUN_30046174, jdbg_hex_dump, os_dprintf, os_panic, os_printf, valid_type
 * Константы: 0x30046838, 0x3004650C
 * Данные: DAT_30046a24, DAT_30046a28, DAT_30046a30, DAT_30046a60, DAT_30046a64, DAT_30046a78, DAT_30046a8c, DAT_30046a90
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x3004650c) */

int jdbg_pattern_check(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_30046a24,DAT_30046a28,0x27c);
    os_dprintf(DAT_30046a94);
    os_panic(DAT_30046a30,DAT_30046a28,0x27c);
  }
  valid_type(0x24);
  if ((4 < *(int *)(DAT_30046a60 + 0x78)) && (4 < *(int *)(DAT_30046a60 + 0x90))) {
    os_dprintf(DAT_30046a64,DAT_30046a28,DAT_30046ac4);
    os_printf(DAT_30046ac8,*param_1,param_2,param_3);
  }
  local_30 = 0;
  valid_type(0x24);
  if ((4 < *(int *)(DAT_30046a60 + 0x78)) && (4 < *(int *)(DAT_30046a60 + 0x90))) {
    os_dprintf(DAT_30046a64,DAT_30046a28,DAT_30046a8c);
    local_28 = DAT_30046a78;
    os_printf(DAT_30046a90,DAT_30046a78,param_1,param_2,param_3,0);
  }
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_30046a24,DAT_30046a28,0x23c);
    os_dprintf(DAT_30046a94);
    os_panic(DAT_30046a30,DAT_30046a28,0x23c);
  }
  if (*param_1 == 0) {
    if (param_1[2] == 0) {
      valid_type(0x24);
      if ((0 < *(int *)(DAT_30046a60 + 0x78)) && (0 < *(int *)(DAT_30046a60 + 0x90))) {
        os_dprintf(DAT_30046a64,DAT_30046a28,0x25c);
        os_printf(DAT_30046aa8);
      }
      return 0xb;
    }
    piVar2 = (int *)param_1[2];
    uVar4 = param_2;
    while( true ) {
      uVar3 = uVar4;
      if ((uint)piVar2[2] < uVar4) {
        uVar3 = piVar2[2];
      }
      if (piVar2[2] == 0) {
        os_dprintf(DAT_30046a24,DAT_30046a28,DAT_30046a98);
        os_dprintf(DAT_30046a9c);
        os_panic(DAT_30046a30,DAT_30046a28,DAT_30046a98);
      }
      if (*piVar2 == 0) {
        os_dprintf(DAT_30046a24,DAT_30046a28,DAT_30046aa0);
        os_dprintf(DAT_30046aa4);
        os_panic(DAT_30046a30,DAT_30046a28,DAT_30046aa0);
      }
      uVar4 = uVar4 - uVar3;
      iVar1 = FUN_30046174(*piVar2,uVar3,&local_30,param_3,0);
      if ((iVar1 != 0) || (uVar4 == 0)) break;
      piVar2 = piVar2 + 3;
    }
  }
  else {
    iVar1 = FUN_30046174(*param_1,param_2,&local_30,param_3,0);
  }
  if (iVar1 != 0) {
    valid_type(0x24);
    if ((0 < *(int *)(DAT_30046a60 + 0x78)) && (0 < *(int *)(DAT_30046a60 + 0x90))) {
      os_dprintf(DAT_30046a64,DAT_30046a28,DAT_30046aac);
      os_printf(DAT_30046ab0,param_2,local_30,local_30,param_3,param_3);
    }
    if (((*param_1 != 0) && (valid_type(0x24), 0 < *(int *)(DAT_30046a60 + 0x78))) &&
       (0 < *(int *)(DAT_30046a60 + 0x90))) {
      local_2c = param_2;
      if (0x400 < param_2) {
        local_2c = 0x400;
      }
      jdbg_hex_dump(DAT_30046a28,DAT_30046ab4,*param_1,local_2c,0);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * uw_code2str @ 0x300468DC  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300468DC
 * ---------------------------------------------------------------- */
int uw_code2str(int param_1,int *param_2)

{
  for (; (*param_2 != -1 && (*param_2 != param_1)); param_2 = param_2 + 2) {
  }
  return param_2[1];
}

/* ----------------------------------------------------------------
 * uw_count_set_bits @ 0x3004691C  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3004691C
 * Данные: DAT_30046acc
 * ---------------------------------------------------------------- */
int uw_count_set_bits(uint param_1)

{
  return (uint)*(byte *)(DAT_30046acc + (param_1 & 0xff)) +
         (uint)*(byte *)(DAT_30046acc + (param_1 >> 8 & 0xff)) +
         (uint)*(byte *)(DAT_30046acc + (param_1 >> 0x10 & 0xff)) +
         (uint)*(byte *)(DAT_30046acc + (param_1 >> 0x18));
}

/* ----------------------------------------------------------------
 * FUN_30046974 @ 0x30046974  (примерный размер ~348 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: BSP_MallocDbg, memset
 * Вызывают: j_strdup, perf_init
 * Константы: 0x30046974
 * ---------------------------------------------------------------- */
void * FUN_30046974(size_t param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)BSP_MallocDbg(param_1,0,param_3,param_4);
  if ((param_2 == 1) && (__s != (void *)0x0)) {
    memset(__s,0,param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * jmalloc_d @ 0x30046C80  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: jdbg_check_context, jos_safe_check, os_malloc, os_memset
 * Константы: 0xFFFFFFFC, 0x30046C80
 * Данные: DAT_30047a50, DAT_30047a5c, DAT_30047b78, DAT_30047b7c, DAT_30047b80, DAT_30047cc8, DAT_30047ccc
 * ---------------------------------------------------------------- */
undefined4 * jmalloc_d(uint param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  jos_safe_check(DAT_30047a50,0x59);
  jdbg_check_context(0x3c,DAT_30047a50,0x5a);
  puVar1 = (undefined4 *)os_malloc(param_1 + 0x3c,param_2);
  if (puVar1 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    os_memset(puVar1,0,0x30);
    *puVar1 = DAT_30047b78;
    puVar1[0xb] = DAT_30047b7c;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_1;
    puVar1[4] = puVar1;
    iVar3 = *DAT_30047b80;
    puVar1[8] = iVar3;
    *DAT_30047b80 = iVar3 + 1;
    puVar1[7] = 0;
    puVar1[10] = DAT_30047a5c;
    puVar1[9] = *(undefined4 *)(DAT_30047a5c + 0x24);
    *(undefined4 **)(DAT_30047a5c + 0x24) = puVar1;
    if (puVar1[9] != 0) {
      *(undefined4 **)(puVar1[9] + 0x28) = puVar1;
    }
    puVar2 = puVar1 + 0xc;
    puVar1[5] = puVar2;
    *(undefined4 *)((int)puVar2 + (param_1 & 0xfffffffc) + 4) = DAT_30047cc8;
    *(undefined4 *)((int)puVar2 + (param_1 & 0xfffffffc) + 8) = DAT_30047ccc;
  }
  return puVar2;
}

/* ----------------------------------------------------------------
 * jfree_d @ 0x30046D98  (примерный размер ~412 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: os_dprintf, os_free, os_panic
 * Константы: 0xFFFFFFFC, 0x30046D98
 * Данные: DAT_30047a50, DAT_30047b78, DAT_30047b7c, DAT_30047cc8, DAT_30047ccc, DAT_30047cd0, DAT_30047cd4, DAT_30047cd8
 * ---------------------------------------------------------------- */
void jfree_d(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = *param_1;
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_30047cd0,DAT_30047a50,0x92);
    os_dprintf(DAT_30047cd4,param_2,param_3);
    os_panic(DAT_30047cd8,DAT_30047a50,0x92);
  }
  if ((*(int *)(iVar2 + -0x30) != DAT_30047b78) || (*(int *)(iVar2 + -4) != DAT_30047b7c)) {
    os_dprintf(DAT_30047cd0,DAT_30047a50,0x97);
    os_dprintf(DAT_30047cdc,param_2,param_3);
    os_panic(DAT_30047cd8,DAT_30047a50,0x97);
  }
  if ((*(int *)(iVar1 + (*(uint *)(iVar2 + -0x24) & 0xfffffffc) + 4) != DAT_30047cc8) ||
     (*(int *)(iVar1 + (*(uint *)(iVar2 + -0x24) & 0xfffffffc) + 8) != DAT_30047ccc)) {
    os_dprintf(DAT_30047cd0,DAT_30047a50,0x9d);
    os_dprintf(DAT_30047ce0,*(undefined4 *)(iVar2 + -0x2c),*(undefined4 *)(iVar2 + -0x28),param_2,
               param_3);
    os_panic(DAT_30047cd8,DAT_30047a50,0x9d);
  }
  if (*(int *)(iVar2 + -0x14) != 0) {
    os_dprintf(DAT_30047cd0,DAT_30047a50,0x9f);
    os_dprintf(DAT_30047dec,param_2,param_3);
    os_panic(DAT_30047cd8,DAT_30047a50,0x9f);
  }
  *(int *)(iVar2 + -0x14) = *(int *)(iVar2 + -0x14) + 1;
  *(undefined4 *)(*(int *)(iVar2 + -8) + 0x24) = *(undefined4 *)(iVar2 + -0xc);
  if (*(int *)(iVar2 + -0xc) != 0) {
    *(undefined4 *)(*(int *)(iVar2 + -0xc) + 0x28) = *(undefined4 *)(iVar2 + -8);
  }
  os_free(*(undefined4 *)(iVar2 + -0x20));
  return;
}

/* ----------------------------------------------------------------
 * jdma_phys_addr @ 0x30046F34  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_300474f0, FUN_30050f7c, FUN_300519d8, jdma_alloc, jdma_free
 * Константы: 0x30046F34
 * ---------------------------------------------------------------- */
int jdma_phys_addr(int param_1,int param_2)

{
  return *(int *)(param_1 + 4) + param_2;
}

/* ----------------------------------------------------------------
 * jdma_virt_addr @ 0x30046F50  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 0
 * Вызывают: FUN_30046f80, FUN_300474f0, FUN_300475c0, FUN_300519d8, FUN_30055e10, jdma_alloc, jdma_free, jdma_free_all
 * Константы: 0x30046F50
 * ---------------------------------------------------------------- */
int jdma_virt_addr(int *param_1,int param_2)

{
  return *param_1 + param_2;
}

/* ----------------------------------------------------------------
 * jdma_buffer_get @ 0x30046F6C  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30055e10, core_request_alloc
 * Константы: 0x30046F6C
 * ---------------------------------------------------------------- */
undefined4 jdma_buffer_get(undefined4 param_1)

{
  return param_1;
}

/* ----------------------------------------------------------------
 * FUN_30046f80 @ 0x30046F80  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: jdma_virt_addr
 * Вызывают: FUN_30047018, jdma_free
 * Константы: 0x30046F80
 * Данные: DAT_30047df0, DAT_30047df4, DAT_30047e9c, DAT_30047ea0
 * ---------------------------------------------------------------- */
void FUN_30046f80(int param_1)

{
  undefined4 *puVar1;
  
  *DAT_30047df0 = *DAT_30047df0 + 1;
  if (*DAT_30047df4 < *DAT_30047df0) {
    *DAT_30047df4 = *DAT_30047df0;
  }
  puVar1 = (undefined4 *)jdma_virt_addr(param_1,0);
  *puVar1 = DAT_30047e9c;
  *(int *)(param_1 + 0x18) = *DAT_30047ea0;
  if (*(int *)(param_1 + 0x18) != 0) {
    *(int *)(*DAT_30047ea0 + 0x1c) = param_1 + 0x18;
  }
  *DAT_30047ea0 = param_1;
  *(int **)(param_1 + 0x1c) = DAT_30047ea0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30047018 @ 0x30047018  (примерный размер ~424 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_30046f80, FUN_30047fd4, os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: FUN_3004726c, FUN_3004749c
 * Константы: 0x30047018
 * Данные: DAT_30047a48, DAT_30047a4c, DAT_30047a50, DAT_30047cd0, DAT_30047cd8, DAT_30047ea4, DAT_30047ea8, DAT_30047f70
 * ---------------------------------------------------------------- */
undefined4 FUN_30047018(uint param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if ((param_3 & 3) != 0) {
    os_dprintf(DAT_30047cd0,DAT_30047a50,DAT_30047ea4);
    os_dprintf(DAT_30047ea8);
    os_panic(DAT_30047cd8,DAT_30047a50,DAT_30047ea4);
  }
  puVar1 = (uint *)FUN_30047fd4(0x20,1,DAT_30047a50,0x288);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 7;
  }
  else {
    valid_type(0x21);
    if ((3 < *(int *)(DAT_30047a48 + 0x78)) && (3 < *(int *)(DAT_30047a48 + 0x84))) {
      os_dprintf(DAT_30047a4c,DAT_30047a50,DAT_30047f70);
      os_printf(DAT_30047f74,param_1,param_3,param_4,puVar1);
    }
    if (puVar1 == (uint *)0x0) {
      os_dprintf(DAT_30047cd0,DAT_30047a50,0x290);
      os_dprintf(DAT_30047f78);
      os_panic(DAT_30047cd8,DAT_30047a50,0x290);
    }
    *puVar1 = param_3;
    puVar1[1] = param_4;
    puVar1[2] = 0;
    puVar1[3] = param_1;
    for (uVar3 = 1; ((param_4 & uVar3 & 0xffff) == 0 && ((uVar3 & 0xffff) < 0x1001));
        uVar3 = (uVar3 << 0x10) >> 0xf) {
    }
    *(short *)(puVar1 + 4) = (short)uVar3;
    if (param_2 != 0) {
      *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 1;
    }
    if (param_4 >> 0xc == param_4 + param_1 >> 0xc) {
      *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
    }
    if (param_5 != 0) {
      *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 4;
      puVar1[5] = param_5;
    }
    FUN_30046f80(puVar1);
    *DAT_30048028 = *DAT_30048028 + 1;
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300471c0 @ 0x300471C0  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: os_dma_alloc, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3004749c
 * Константы: 0x300471C0
 * Данные: DAT_30047a48, DAT_30047a4c, DAT_30047a50, DAT_3004802c, DAT_30048030
 * ---------------------------------------------------------------- */
int FUN_300471c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
                undefined4 *param_5,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = os_dma_alloc(param_1,param_2,param_3,param_4,param_6);
  if (iVar1 == 0) {
    *param_5 = 0;
  }
  else {
    valid_type(0x21);
    if ((0 < *(int *)(DAT_30047a48 + 0x78)) && (0 < *(int *)(DAT_30047a48 + 0x84))) {
      os_dprintf(DAT_30047a4c,DAT_30047a50,DAT_3004802c);
      os_printf(DAT_30048030,param_1,param_4);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004726c @ 0x3004726C  (примерный размер ~560 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30047018
 * Вызывают: FUN_3004749c
 * Константы: 0x3004726C
 * ---------------------------------------------------------------- */
void FUN_3004726c(uint param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = 0;
  if (0x1f < param_1) {
    if ((param_4 & 3) != 0) {
      uVar1 = 4 - (param_4 & 3);
    }
    if ((uVar1 < param_1) && (0x1f < param_1 - uVar1)) {
      FUN_30047018(param_1 - uVar1,param_2,param_3 + uVar1,param_4 + uVar1,0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3004749c @ 0x3004749C  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 9
 * Вызывает: FUN_30047018, FUN_300471c0, FUN_3004726c, __urem32, os_dprintf, os_panic, os_printf, uwe_str, valid_type
 * Вызывают: jdma_alloc
 * Константы: 0x3004749C
 * Данные: DAT_30047a48, DAT_30047a4c, DAT_30047a50, DAT_30047cd0, DAT_30047cd8, DAT_30048034, DAT_30048038, DAT_3004803c
 * ---------------------------------------------------------------- */
int FUN_3004749c(uint param_1,ushort param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  
  if (param_1 == 0) {
    os_dprintf(DAT_30047cd0,DAT_30047a50,DAT_3004803c);
    os_dprintf(DAT_30048040);
    os_panic(DAT_30047cd8,DAT_30047a50,DAT_3004803c);
  }
  local_34 = 0;
  iVar6 = 0;
  local_30 = 0;
  local_2c = 0;
  uVar4 = param_1;
  if (param_1 < 0x20) {
    uVar4 = 0x20;
  }
  iVar5 = uVar4 + param_2 + -1;
  valid_type(0x21);
  if ((3 < *(int *)(DAT_30047a48 + 0x78)) && (3 < *(int *)(DAT_30047a48 + 0x84))) {
    os_dprintf(DAT_30047a4c,DAT_30047a50,0x380);
    os_printf(DAT_30048034,iVar5,param_1);
  }
  iVar2 = FUN_300471c0(iVar5,&local_28,&local_30,param_3,&local_34,&local_2c);
  iVar1 = local_30;
  if (iVar2 == 0) {
    iVar2 = __urem32(local_30,param_2);
    if (iVar2 != 0) {
      iVar6 = __urem32(iVar1,param_2);
      iVar6 = (uint)param_2 - iVar6;
    }
    FUN_3004726c(iVar6,local_34,local_28,iVar1);
    FUN_3004726c((iVar5 - param_1) - iVar6,local_34,local_28 + iVar6 + param_1,
                 iVar1 + iVar6 + param_1);
    iVar2 = FUN_30047018(param_1,local_34,local_28 + iVar6,iVar1 + iVar6,local_2c);
  }
  else {
    valid_type(0x21);
    if ((0 < *(int *)(DAT_30047a48 + 0x78)) && (0 < *(int *)(DAT_30047a48 + 0x84))) {
      os_dprintf(DAT_30047a4c,DAT_30047a50,0x388);
      uVar3 = uwe_str(iVar2);
      os_printf(DAT_30048038,iVar5,uVar3);
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300474f0 @ 0x300474F0  (примерный размер ~208 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: jdma_phys_addr, jdma_virt_addr, os_printf
 * Вызывают: FUN_300475c0, jdma_alloc
 * Константы: 0x300474F0
 * Данные: DAT_30047a54, DAT_30047e9c, DAT_30047ea0, DAT_30048044, DAT_30048048, DAT_3004804c, DAT_30048050
 * ---------------------------------------------------------------- */
void FUN_300474f0(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  os_printf(DAT_30047a54);
  os_printf(DAT_30048044);
  iVar4 = 0;
  for (iVar5 = *DAT_30047ea0; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x18)) {
    piVar1 = (int *)jdma_virt_addr(iVar5,0);
    uVar6 = DAT_3004804c;
    if (*piVar1 != DAT_30047e9c) {
      uVar6 = DAT_30048048;
    }
    uVar2 = jdma_phys_addr(iVar5,0);
    uVar3 = jdma_virt_addr(iVar5,0);
    os_printf(DAT_30048050,iVar4,*(undefined4 *)(iVar5 + 0xc),*(undefined2 *)(iVar5 + 0x10),
              *(undefined1 *)(iVar5 + 0x12),iVar5,uVar3,uVar2,*(undefined4 *)(iVar5 + 0x14),uVar6);
    iVar4 = iVar4 + 1;
  }
  os_printf(DAT_30047a54);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300475c0 @ 0x300475C0  (примерный размер ~408 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300474f0, jdma_virt_addr, os_dprintf, os_printf, valid_type
 * Вызывают: jdma_alloc
 * Константы: 0x300475C0
 * Данные: DAT_30047a48, DAT_30047a4c, DAT_30047a50, DAT_30047df0, DAT_30047e9c, DAT_30047ea0, DAT_30048054, DAT_30048058
 * ---------------------------------------------------------------- */
undefined4 FUN_300475c0(uint param_1,ushort param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  
  *param_4 = 0;
  if (param_1 != 0) {
    for (iVar2 = *DAT_30047ea0; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x18)) {
      piVar1 = (int *)jdma_virt_addr(iVar2,0);
      if (*piVar1 != DAT_30047e9c) {
        valid_type(0x21);
        if ((0 < *(int *)(DAT_30047a48 + 0x78)) && (0 < *(int *)(DAT_30047a48 + 0x84))) {
          os_dprintf(DAT_30047a4c,DAT_30047a50,0x3f4);
          os_printf(DAT_30048054,iVar2);
        }
        FUN_300474f0();
        return 0x10;
      }
      if (((((param_3 & 2) == 0) || ((*(byte *)(iVar2 + 0x12) & 1) != 0)) &&
          (((param_3 & 2) != 0 || ((*(byte *)(iVar2 + 0x12) & 1) == 0)))) &&
         (((param_2 <= *(ushort *)(iVar2 + 0x10) && (param_1 <= *(uint *)(iVar2 + 0xc))) &&
          (*(uint *)(iVar2 + 0xc) < param_1 << 1)))) {
        if (*(int *)(iVar2 + 0x18) != 0) {
          *(undefined4 *)(*(int *)(iVar2 + 0x18) + 0x1c) = *(undefined4 *)(iVar2 + 0x1c);
        }
        **(undefined4 **)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
        *DAT_30047df0 = *DAT_30047df0 + -1;
        *param_4 = iVar2;
        valid_type(0x21);
        if (*(int *)(DAT_30047a48 + 0x78) < 5) {
          return 0;
        }
        if (*(int *)(DAT_30047a48 + 0x84) < 5) {
          return 0;
        }
        os_dprintf(DAT_30047a4c,DAT_30047a50,DAT_30048058);
        os_printf(DAT_3004805c,iVar2,*(undefined4 *)(iVar2 + 0xc));
        return 0;
      }
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * jdma_free @ 0x30047758  (примерный размер ~396 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 8
 * Вызывает: BSP_FreeDbg, FUN_30046f80, jdma_phys_addr, jdma_virt_addr, jos_safe_check, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30051844, FUN_30055d50, core_request_free, jdma_alloc
 * Константы: 0x30047758
 * Данные: DAT_30047a48, DAT_30047a4c, DAT_30047a50, DAT_30047b70, DAT_30047b74, DAT_30048060, DAT_30048064, DAT_30048068
 * ---------------------------------------------------------------- */
void jdma_free(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  jos_safe_check(DAT_30047a50,DAT_30048060);
  valid_type(0x21);
  if ((3 < *(int *)(DAT_30047a48 + 0x78)) && (3 < *(int *)(DAT_30047a48 + 0x84))) {
    os_dprintf(DAT_30047a4c,DAT_30047a50,DAT_30048064);
    uVar1 = jdma_phys_addr(param_1,0);
    uVar2 = jdma_virt_addr(param_1,0);
    os_printf(DAT_30048068,param_1,uVar2,uVar1,*(undefined4 *)(param_1 + 0xc));
  }
  if ((*(byte *)(param_1 + 0x12) & 8) == 0) {
    FUN_30046f80(param_1);
    *DAT_30047b74 = *DAT_30047b74 - *(int *)(param_1 + 0xc);
    *DAT_30047b70 = *DAT_30047b70 + -1;
  }
  else {
    if (((*(int *)(param_1 + 0xc) != 0) && (valid_type(0x21), 0 < *(int *)(DAT_30047a48 + 0x78))) &&
       (0 < *(int *)(DAT_30047a48 + 0x84))) {
      os_dprintf(DAT_30047a4c,DAT_30047a50,DAT_3004806c);
      os_printf(DAT_30048070);
    }
    valid_type(0x21);
    if ((4 < *(int *)(DAT_30047a48 + 0x78)) && (4 < *(int *)(DAT_30047a48 + 0x84))) {
      os_dprintf(DAT_30047a4c,DAT_30047a50,DAT_30048074);
      os_printf(DAT_30048078);
    }
    BSP_FreeDbg(param_1,DAT_30047a50,0x4c0);
    *DAT_30047b70 = *DAT_30047b70 + -1;
  }
  return;
}

/* ----------------------------------------------------------------
 * jdma_alloc @ 0x300478E4  (примерный размер ~1340 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 14
 * Вызывает: FUN_3004749c, FUN_300474f0, FUN_300475c0, FUN_30047fd4, __urem32, jdma_free, jdma_phys_addr, jdma_virt_addr, jos_safe_check, os_dprintf, os_memset, os_panic, os_printf, valid_type
 * Вызывают: FUN_300519d8, FUN_30055e10, core_request_alloc
 * Константы: 0x300478E4
 * Данные: DAT_30047a48, DAT_30047a4c, DAT_30047a50, DAT_30047b70, DAT_30047cd0, DAT_30047cd8, DAT_30047df0, DAT_30047e9c
 * ---------------------------------------------------------------- */
int jdma_alloc(uint param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,ushort param_5,
              int *param_6)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int local_34;
  undefined4 local_30;
  
  uVar5 = (uint)param_5;
  local_34 = 0;
  jos_safe_check(DAT_30047a50,DAT_3004807c);
  valid_type(0x21);
  if ((2 < *(int *)(DAT_30047a48 + 0x78)) && (2 < *(int *)(DAT_30047a48 + 0x84))) {
    os_dprintf(DAT_30047a4c,DAT_30047a50,DAT_30048080);
    os_printf(DAT_30048084,param_1,param_2 & 0xffff,uVar5);
  }
  if (param_1 == 0) {
    local_34 = FUN_30047fd4(0x20,1,DAT_30047a50,0x430);
    if (local_34 == 0) {
      iVar1 = 7;
    }
    else {
      valid_type(0x21);
      if ((4 < *(int *)(DAT_30047a48 + 0x78)) && (4 < *(int *)(DAT_30047a48 + 0x84))) {
        os_dprintf(DAT_30047a4c,DAT_30047a50,DAT_30048088);
        os_printf(DAT_3004808c,local_34);
      }
      *(byte *)(local_34 + 0x12) = *(byte *)(local_34 + 0x12) | 8;
      if (param_6 == (int *)0x0) {
        os_dprintf(DAT_30047cd0,DAT_30047a50,DAT_30048090);
        os_dprintf(DAT_30048094);
        os_panic(DAT_30047cd8,DAT_30047a50,DAT_30048090);
      }
      *param_6 = local_34;
      *DAT_30047b70 = *DAT_30047b70 + 1;
      iVar1 = 0;
    }
  }
  else {
    if (param_1 < 0x20) {
      param_1 = 0x20;
    }
    if ((param_2 & 0xffff) < 4) {
      param_2 = 4;
    }
    iVar1 = FUN_300475c0(param_1,param_2,uVar5,&local_34);
    if ((iVar1 == 0) &&
       (((local_34 != 0 || ((param_5 & 2) == 0)) ||
        (iVar1 = FUN_300475c0(param_1,param_2,uVar5 & DAT_30048098,&local_34), iVar1 == 0)))) {
      if (local_34 == 0) {
        iVar1 = FUN_3004749c(param_1,param_2,uVar5);
        if (iVar1 != 0) {
          valid_type(0x21);
          if ((0 < *(int *)(DAT_3004809c + 0x78)) && (0 < *(int *)(DAT_3004809c + 0x84))) {
            os_dprintf(DAT_300480a0,DAT_300480a4,DAT_300480a8);
            os_printf(DAT_300480ac,param_1,param_2 & 0xffff,uVar5);
          }
          FUN_300474f0();
          return iVar1;
        }
        local_34 = *DAT_30047ea0;
        if (*(int *)(local_34 + 0x18) != 0) {
          *(undefined4 *)(*(int *)(local_34 + 0x18) + 0x1c) = *(undefined4 *)(local_34 + 0x1c);
        }
        **(undefined4 **)(local_34 + 0x1c) = *(undefined4 *)(local_34 + 0x18);
        piVar2 = (int *)jdma_virt_addr(local_34,0);
        if (*piVar2 != DAT_30047e9c) {
          valid_type(0x21);
          if ((0 < *(int *)(DAT_3004809c + 0x78)) && (0 < *(int *)(DAT_3004809c + 0x84))) {
            os_dprintf(DAT_300480a0,DAT_300480a4,DAT_300480b0);
            os_printf(DAT_300480b4);
          }
          return 0xe;
        }
        *DAT_30047df0 = *DAT_30047df0 + -1;
      }
      if (param_6 != (int *)0x0) {
        *param_6 = local_34;
      }
      if (param_3 != (undefined4 *)0x0) {
        uVar3 = jdma_virt_addr(local_34,0);
        *param_3 = uVar3;
      }
      if (param_4 != (undefined4 *)0x0) {
        uVar3 = jdma_phys_addr(local_34,0);
        *param_4 = uVar3;
      }
      if ((param_5 & 1) != 0) {
        uVar3 = jdma_virt_addr(local_34,0);
        os_memset(uVar3,0,param_1);
      }
      valid_type(0x21);
      if ((2 < *(int *)(DAT_3004809c + 0x78)) && (2 < *(int *)(DAT_3004809c + 0x84))) {
        os_dprintf(DAT_300480a0,DAT_300480a4,DAT_300480b8);
        uVar3 = jdma_phys_addr(local_34,0);
        uVar4 = jdma_virt_addr(local_34,0);
        os_printf(DAT_300480bc,local_34,uVar4,uVar3,*(undefined4 *)(local_34 + 0xc));
      }
      *DAT_300480c0 = *DAT_300480c0 + *(int *)(local_34 + 0xc);
      *DAT_300480c4 = *DAT_300480c4 + 1;
      local_30 = jdma_phys_addr(local_34,0);
      iVar1 = __urem32(local_30,param_2 & 0xffff);
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        valid_type(0x21);
        if ((0 < *(int *)(DAT_3004809c + 0x78)) && (0 < *(int *)(DAT_3004809c + 0x84))) {
          os_dprintf(DAT_300480a0,DAT_300480a4,DAT_300480c8);
          os_printf(DAT_300480cc);
        }
        jdma_free(&local_34);
        iVar1 = 10;
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * jdma_free_all @ 0x30047E20  (примерный размер ~352 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: BSP_FreeDbg, jdma_virt_addr, os_dma_free, os_dprintf, os_printf, valid_type
 * Вызывают: jos_uninit
 * Константы: 0x30047E20
 * Данные: DAT_30047e9c, DAT_30047ea0, DAT_3004809c, DAT_300480a0, DAT_300480a4, DAT_300480d0, DAT_300480d4, DAT_300480d8
 * ---------------------------------------------------------------- */
void jdma_free_all(void)

{
  int *piVar1;
  int iVar2;
  
  for (iVar2 = *DAT_30047ea0; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x18)) {
    piVar1 = (int *)jdma_virt_addr(iVar2,0);
    if (((*piVar1 != DAT_30047e9c) && (valid_type(0x21), 0 < *(int *)(DAT_3004809c + 0x78))) &&
       (0 < *(int *)(DAT_3004809c + 0x84))) {
      os_dprintf(DAT_300480a0,DAT_300480a4,DAT_300480d0);
      os_printf(DAT_300480d4,iVar2);
    }
  }
  iVar2 = *DAT_300480d8;
  while (iVar2 != 0) {
    if (*(int *)(iVar2 + 0x18) != 0) {
      *(undefined4 *)(*(int *)(iVar2 + 0x18) + 0x1c) = *(undefined4 *)(iVar2 + 0x1c);
    }
    **(undefined4 **)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
    if ((*(byte *)(iVar2 + 0x12) & 4) == 0) {
      BSP_FreeDbg(iVar2,DAT_300480a4,DAT_300480dc);
    }
    else {
      valid_type(0x21);
      if ((2 < *(int *)(DAT_3004809c + 0x78)) && (2 < *(int *)(DAT_3004809c + 0x84))) {
        os_dprintf(DAT_300480a0,DAT_300480a4,DAT_300480e0);
        os_printf(DAT_300480e4,iVar2,*(undefined4 *)(iVar2 + 0x14),*(undefined2 *)(iVar2 + 0x10));
      }
      os_dma_free(*(undefined4 *)(iVar2 + 0x14));
      BSP_FreeDbg(iVar2,DAT_300480a4,DAT_300480e8);
    }
    iVar2 = *DAT_300480d8;
  }
  return;
}

/* ----------------------------------------------------------------
 * jtask_init @ 0x30048234  (примерный размер ~292 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 7
 * Вызывает: BSP_FreeDbg, FUN_3004a390, jos_safe_check, os_dprintf, os_msleep_init, os_printf, valid_type
 * Вызывают: FUN_30060598, core_register_dcd, jos_interrupt_setup
 * Константы: 0x30048234
 * Данные: DAT_3004907c, DAT_30049090, DAT_30049094, DAT_30049198, DAT_3004919c
 * ---------------------------------------------------------------- */
int jtask_init(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  jos_safe_check(DAT_3004907c,0x40);
  if (param_1 == (int *)0x0) {
    iVar1 = 10;
  }
  else {
    valid_type(0x23);
    if ((3 < *(int *)(DAT_30049090 + 0x78)) && (3 < *(int *)(DAT_30049090 + 0x8c))) {
      os_dprintf(DAT_30049094,DAT_3004907c,0x45);
      os_printf(DAT_30049198,param_2,param_1);
    }
    iVar1 = FUN_3004a390(0x30,1,DAT_3004907c,0x47);
    *param_1 = iVar1;
    if (*param_1 == 0) {
      iVar1 = 7;
    }
    else {
      valid_type(0x23);
      if ((4 < *(int *)(DAT_30049090 + 0x78)) && (4 < *(int *)(DAT_30049090 + 0x8c))) {
        os_dprintf(DAT_30049094,DAT_3004907c,0x4b);
        os_printf(DAT_3004919c,param_2,*param_1);
      }
      iVar1 = os_msleep_init(*param_1 + 0x24);
      if (iVar1 == 0) {
        *(undefined4 *)(*param_1 + 0xc) = param_2;
        iVar1 = 0;
      }
      else {
        BSP_FreeDbg(*param_1,DAT_3004907c,0x50);
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30048358 @ 0x30048358  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: os_dprintf, os_panic
 * Вызывают: FUN_30048f78, jtask_schedule_d, jtask_stop
 * Константы: 0x30048358
 * Данные: DAT_30049078, DAT_3004907c, DAT_30049084, DAT_30049254, DAT_30049258
 * ---------------------------------------------------------------- */
void FUN_30048358(int param_1)

{
  int *piVar1;
  
  for (piVar1 = (int *)(*(int *)(param_1 + 0xc) * 0x50 + DAT_30049254);
      (*piVar1 != 0 && (*piVar1 != param_1)); piVar1 = (int *)*piVar1) {
  }
  if (*piVar1 == 0) {
    os_dprintf(DAT_30049078,DAT_3004907c,0xe2);
    os_dprintf(DAT_30049258,*(undefined4 *)(param_1 + 0xc),param_1);
    os_panic(DAT_30049084,DAT_3004907c,0xe2);
  }
  *piVar1 = *(int *)*piVar1;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300483e8 @ 0x300483E8  (примерный размер ~324 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: os_dprintf, os_get_context, os_msleep, os_printf, valid_type
 * Вызывают: jtask_stop
 * Константы: 0x300483E8
 * Данные: DAT_3004907c, DAT_30049090, DAT_30049094, DAT_3004932c, DAT_30049330, DAT_30049334, DAT_30049338, DAT_3004933c
 * ---------------------------------------------------------------- */
void FUN_300483e8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = os_get_context();
  if (iVar1 == *(int *)(param_1 + 0x1c)) {
    valid_type(0x23);
    if ((2 < *(int *)(DAT_30049090 + 0x78)) && (2 < *(int *)(DAT_30049090 + 0x8c))) {
      os_dprintf(DAT_30049094,DAT_3004907c,DAT_3004932c);
      os_printf(DAT_30049330,param_1);
    }
  }
  else {
    while (*(char *)(param_1 + 0x18) != '\0') {
      valid_type(0x23);
      if ((0 < *(int *)(DAT_30049090 + 0x78)) && (0 < *(int *)(DAT_30049090 + 0x8c))) {
        os_dprintf(DAT_30049094,DAT_3004907c,DAT_30049334);
        uVar2 = os_get_context();
        os_printf(DAT_3004933c,param_1,*(undefined1 *)(param_1 + 0x18),uVar2,
                  *(undefined4 *)(DAT_30049338 + *(int *)(param_1 + 0xc) * 0x50));
      }
      os_msleep(*(undefined4 *)(param_1 + 0x24),0);
      if (((*(char *)(param_1 + 0x18) == '\0') &&
          (valid_type(0x23), 2 < *(int *)(DAT_30049090 + 0x78))) &&
         (2 < *(int *)(DAT_30049090 + 0x8c))) {
        os_dprintf(DAT_30049094,DAT_3004907c,DAT_300493d8);
        os_printf(DAT_300493dc,param_1);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * jdbg_check_context @ 0x30048788  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 3
 * Вызывает: os_dprintf, os_get_context, os_panic
 * Вызывают: jdriver_attach, jdriver_detach, jmalloc_d, jos_mutex_lock, jtask_stop
 * Константы: 0x30048788
 * Данные: DAT_30049078, DAT_3004907c, DAT_30049084, DAT_30049338, DAT_30049730, DAT_30049734
 * ---------------------------------------------------------------- */
void jdbg_check_context(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = os_get_context();
  if (iVar1 == 2) {
    uVar3 = 2;
  }
  else if (iVar1 == 4) {
    uVar3 = 1;
  }
  else {
    for (iVar2 = 0; (iVar2 < 1 && (*(int *)(DAT_30049338 + iVar2 * 0x50) != iVar1));
        iVar2 = iVar2 + 1) {
    }
    if (iVar2 == 0) {
      uVar3 = 4;
    }
    else {
      uVar3 = 0x20;
    }
  }
  if ((uVar3 & param_1) == 0) {
    os_dprintf(DAT_30049078,DAT_3004907c,DAT_30049730);
    os_dprintf(DAT_30049734,uVar3,param_2,param_3,param_1);
    os_panic(DAT_30049084,DAT_3004907c,DAT_30049730);
  }
  return;
}

/* ----------------------------------------------------------------
 * jtask_stop @ 0x30048850  (примерный размер ~396 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 11
 * Вызывает: FUN_30048358, FUN_300483e8, jdbg_check_context, jos_critical_enter_d, jos_critical_leave_d, jos_safe_check, os_dprintf, os_get_time, os_panic, os_printf, valid_type
 * Вызывают: FUN_3005ff20, jtask_uninit
 * Константы: 0x30048850
 * Данные: DAT_30049078, DAT_3004907c, DAT_30049084, DAT_30049090, DAT_30049094, DAT_30049738, DAT_3004973c, DAT_30049740
 * ---------------------------------------------------------------- */
void jtask_stop(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_18 [8];
  
  jos_safe_check(DAT_3004907c,0xf6);
  jdbg_check_context(0x3c,DAT_3004907c,0xf7);
  if (param_1 == 0) {
    os_dprintf(DAT_30049078,DAT_3004907c,0xf9);
    os_dprintf(DAT_30049738);
    os_panic(DAT_30049084,DAT_3004907c,0xf9);
  }
  else {
    os_get_time(auStack_18);
    valid_type(0x23);
    if ((3 < *(int *)(DAT_30049090 + 0x78)) && (3 < *(int *)(DAT_30049090 + 0x8c))) {
      os_dprintf(DAT_30049094,DAT_3004907c,DAT_3004973c);
      if (param_1 == 0) {
        uVar2 = 99;
        uVar3 = DAT_30049740;
      }
      else {
        uVar2 = *(undefined4 *)(param_1 + 0xc);
        uVar3 = *(undefined4 *)(param_1 + 0x10);
      }
      os_printf(DAT_30049744,uVar2,param_1,uVar3);
    }
    jos_critical_enter_d(DAT_3004907c,DAT_30049748);
    cVar1 = *(char *)(param_1 + 0x18);
    if (cVar1 == '\0') {
      jos_critical_leave_d(DAT_3004907c,0x108);
    }
    else if (cVar1 == '\x01') {
      *(undefined1 *)(param_1 + 0x18) = 4;
      jos_critical_leave_d(DAT_3004907c,DAT_300497f4);
      FUN_300483e8(param_1);
    }
    else if (cVar1 == '\x02') {
      FUN_30048358(param_1);
      *(undefined1 *)(param_1 + 0x18) = 0;
      jos_critical_leave_d(DAT_3004907c,DAT_300497f0);
    }
    else if (cVar1 == '\x03') {
      FUN_30048358(param_1);
      *(undefined1 *)(param_1 + 0x18) = 4;
      jos_critical_leave_d(DAT_3004907c,DAT_300497f8);
      FUN_300483e8(param_1);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * jtask_uninit @ 0x300489DC  (примерный размер ~412 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 8
 * Вызывает: BSP_FreeDbg, jos_safe_check, jtask_stop, os_dprintf, os_get_context, os_msleep_uninit, os_printf, valid_type
 * Вызывают: FUN_3005f9a4, core_unregister_dcd, jos_interrupt_setup, jos_interrupt_teardown
 * Константы: 0x300489DC
 * Данные: DAT_3004907c, DAT_30049090, DAT_30049094, DAT_300498f8, DAT_300498fc, DAT_30049900, DAT_30049904, DAT_30049908
 * ---------------------------------------------------------------- */
void jtask_uninit(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  valid_type(0x23);
  if ((3 < *(int *)(DAT_30049090 + 0x78)) && (3 < *(int *)(DAT_30049090 + 0x8c))) {
    os_dprintf(DAT_30049094,DAT_3004907c,100);
    if (param_1 == 0) {
      uVar2 = 99;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0xc);
    }
    os_printf(DAT_300498f8,uVar2,param_1);
  }
  jos_safe_check(DAT_3004907c,0x66);
  if (param_1 != 0) {
    if ((((*(char *)(param_1 + 0x18) == '\x01') || (*(char *)(param_1 + 0x18) == '\x03')) ||
        (*(char *)(param_1 + 0x18) == '\x04')) &&
       (iVar1 = os_get_context(), iVar1 == *(int *)(param_1 + 0x1c))) {
      valid_type(0x23);
      if ((2 < *(int *)(DAT_30049090 + 0x78)) && (2 < *(int *)(DAT_30049090 + 0x8c))) {
        os_dprintf(DAT_30049094,DAT_3004907c,0x73);
        uVar2 = DAT_300498fc;
        if ((*(char *)(param_1 + 0x18) != '\x01') &&
           (uVar2 = DAT_30049904, *(char *)(param_1 + 0x18) == '\x03')) {
          uVar2 = DAT_30049900;
        }
        os_printf(DAT_30049908,*(undefined4 *)(param_1 + 0x1c),uVar2);
      }
      *(undefined4 *)(param_1 + 0x20) = 1;
    }
    else {
      if (((*(char *)(param_1 + 0x18) == '\x04') &&
          (valid_type(0x23), 0 < *(int *)(DAT_30049090 + 0x78))) &&
         (0 < *(int *)(DAT_30049090 + 0x8c))) {
        os_dprintf(DAT_30049094,DAT_3004907c,0x7b);
        os_printf(DAT_3004990c);
      }
      jtask_stop(param_1);
      os_msleep_uninit(*(undefined4 *)(param_1 + 0x24));
      BSP_FreeDbg(param_1,DAT_3004907c,0x81);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30048b78 @ 0x30048B78  (примерный размер ~412 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: os_dprintf, os_memcpy, os_printf, valid_type
 * Вызывают: jtask_schedule_d
 * Константы: 0x30048B78
 * Данные: DAT_3004907c, DAT_30049090, DAT_30049094, DAT_30049254, DAT_300499d8, DAT_300499dc, DAT_30049a78
 * ---------------------------------------------------------------- */
void FUN_30048b78(int *param_1,int param_2,uint param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  uint uVar2;
  int local_8;
  uint local_4;
  
  local_8 = param_2;
  local_4 = param_3;
  valid_type(0x23);
  if ((3 < *(int *)(DAT_30049090 + 0x78)) && (3 < *(int *)(DAT_30049090 + 0x8c))) {
    os_dprintf(DAT_30049094,DAT_3004907c,DAT_300499d8);
    os_printf(DAT_300499dc,param_1[3],param_1,
              (param_1[1] - local_8) * 1000 +
              ((int)((param_1[2] - local_4) + ((uint)((int)(param_1[2] - local_4) >> 0x1f) >> 0x16))
              >> 10));
  }
  param_1[4] = param_5;
  param_1[5] = param_6;
  if (param_4 != 0) {
    uVar2 = param_4 * 1000 + local_4;
    local_8 = local_8 + ((int)(uVar2 + ((uint)((int)uVar2 >> 0x1f) >> 0xc)) >> 0x14);
    local_4 = uVar2 & DAT_30049a78;
    if ((int)uVar2 < 0) {
      local_4 = -(-uVar2 & DAT_30049a78);
    }
  }
  os_memcpy(param_1 + 1,&local_8,8);
  for (piVar1 = (int *)(param_1[3] * 0x50 + DAT_30049254);
      (*piVar1 != 0 &&
      ((*(int *)(*piVar1 + 4) < param_1[1] ||
       ((param_1[1] == *(int *)(*piVar1 + 4) && (*(int *)(*piVar1 + 8) <= param_1[2]))))));
      piVar1 = (int *)*piVar1) {
  }
  *param_1 = *piVar1;
  *piVar1 = (int)param_1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30048d14 @ 0x30048D14  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: os_dprintf, os_printf, os_wakeup, valid_type
 * Вызывают: jtask_schedule_d
 * Константы: 0x30048D14
 * Данные: DAT_3004907c, DAT_30049090, DAT_30049094, DAT_30049254, DAT_30049b98, DAT_30049b9c, DAT_30049ba0
 * ---------------------------------------------------------------- */
void FUN_30048d14(int param_1)

{
  if (*(int *)(DAT_30049254 + param_1 * 0x50) == 0) {
    valid_type(0x23);
    if ((4 < *(int *)(DAT_30049090 + 0x78)) && (4 < *(int *)(DAT_30049090 + 0x8c))) {
      os_dprintf(DAT_30049094,DAT_3004907c,DAT_30049b9c);
      os_printf(DAT_30049ba0,param_1);
    }
  }
  else {
    os_wakeup(*(undefined4 *)(DAT_30049b98 + param_1 * 0x50));
  }
  return;
}

/* ----------------------------------------------------------------
 * jtask_schedule_d @ 0x30048D98  (примерный размер ~480 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 10
 * Вызывает: FUN_30048358, FUN_30048b78, FUN_30048d14, jos_critical_enter_d, jos_critical_leave_d, os_dprintf, os_get_time, os_panic, os_printf, valid_type
 * Вызывают: FUN_30060b5c, FUN_3006106c, FUN_300613c4, core_reconfig, jgeneric_dsr
 * Константы: 0x30048D98
 * Данные: DAT_30049078, DAT_3004907c, DAT_30049084, DAT_30049090, DAT_30049094, DAT_30049ba4, DAT_30049c50, DAT_30049d20
 * ---------------------------------------------------------------- */
undefined4
jtask_schedule_d(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 local_24;
  undefined4 local_20;
  
  if (param_1 == 0) {
    os_dprintf(DAT_30049078,DAT_3004907c,0x9c);
    os_dprintf(DAT_30049ba4,param_5,param_6);
    os_panic(DAT_30049084,DAT_3004907c,0x9c);
    uVar2 = 10;
  }
  else {
    valid_type(0x23);
    if ((2 < *(int *)(DAT_30049090 + 0x78)) && (2 < *(int *)(DAT_30049090 + 0x8c))) {
      os_dprintf(DAT_30049094,DAT_3004907c,0xa1);
      os_printf(DAT_30049c50,*(undefined4 *)(param_1 + 0xc),param_1,param_2,param_3,param_4);
    }
    os_get_time(&local_24);
    jos_critical_enter_d(DAT_3004907c,0xa5);
    bVar1 = *(byte *)(param_1 + 0x18);
    if (bVar1 == 2) {
      FUN_30048358(param_1);
    }
    else if (bVar1 < 3) {
      if (bVar1 == 0) {
        *(undefined1 *)(param_1 + 0x18) = 2;
      }
      else if (bVar1 == 1) {
        *(undefined1 *)(param_1 + 0x18) = 3;
      }
    }
    else if (bVar1 == 3) {
      FUN_30048358(param_1);
    }
    else if (bVar1 == 4) {
      jos_critical_leave_d(DAT_3004907c,0xba);
      valid_type(0x23);
      if ((0 < *(int *)(DAT_30049090 + 0x78)) && (0 < *(int *)(DAT_30049090 + 0x8c))) {
        os_dprintf(DAT_30049094,DAT_3004907c,0xbb);
        os_printf(DAT_30049d20);
      }
      return 0x10;
    }
    *(undefined4 *)(param_1 + 0x28) = param_5;
    *(undefined4 *)(param_1 + 0x2c) = param_6;
    FUN_30048b78(param_1,local_24,local_20,param_2,param_3,param_4);
    jos_critical_leave_d(DAT_3004907c,0xc6);
    FUN_30048d14(*(undefined4 *)(param_1 + 0xc),&local_24);
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30048f78 @ 0x30048F78  (примерный размер ~1832 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 15
 * Вызывает: BSP_FreeDbg, FUN_30048358, jos_critical_enter_d, jos_critical_leave_d, jos_safe_check, os_dprintf, os_get_context, os_get_time, os_memcpy, os_msleep, os_msleep_uninit, os_panic, os_printf, os_wakeup
 *           ...
 * Константы: 0x30048F78
 * Данные: DAT_3004907c, DAT_30049090, DAT_30049094, DAT_30049b98, DAT_30049d24, DAT_30049d28, DAT_30049d2c, DAT_30049e18
 * ---------------------------------------------------------------- */
void FUN_30048f78(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  int local_30;
  int local_2c;
  
  puVar4 = (undefined4 *)(DAT_30049b98 + param_1 * 0x50);
  jos_safe_check(DAT_3004907c,DAT_30049d24);
  uVar2 = os_get_context();
  puVar4[0x13] = uVar2;
  valid_type(0x23);
  if ((2 < *(int *)(DAT_30049090 + 0x78)) && (2 < *(int *)(DAT_30049090 + 0x8c))) {
    os_dprintf(DAT_30049094,DAT_3004907c,DAT_30049d28);
    os_printf(DAT_30049d2c,param_1,puVar4[0x13]);
  }
  while ((*(byte *)(puVar4 + 0xe) & 4) != 0) {
    os_get_time(&local_30);
    valid_type(0x23);
    if ((4 < *(int *)(DAT_30049090 + 0x78)) && (4 < *(int *)(DAT_30049090 + 0x8c))) {
      os_dprintf(DAT_30049094,DAT_3004907c,DAT_30049e18);
      os_printf(DAT_30049e1c,param_1);
    }
    jos_critical_enter_d(DAT_3004907c,DAT_30049e20);
    iVar3 = puVar4[1];
    if (iVar3 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(iVar3 + 8) - local_2c;
      iVar5 = (*(int *)(iVar3 + 4) - local_30) * 1000 +
              ((int)(iVar5 + ((uint)(iVar5 >> 0x1f) >> 0x16)) >> 10);
      if ((*(int *)(iVar3 + 0xc) != 0) && (iVar5 < 2)) {
        iVar5 = 2;
      }
    }
    jos_critical_leave_d(DAT_30049ef8,0x1c0);
    if ((0 < iVar5) || (iVar3 == 0)) {
      valid_type(0x23);
      if ((4 < *(int *)(DAT_30049efc + 0x78)) && (4 < *(int *)(DAT_30049efc + 0x8c))) {
        os_dprintf(DAT_30049f00,DAT_30049ef8,DAT_30049f04);
        os_printf(DAT_30049f08,param_1,iVar5);
      }
      *(undefined1 *)((int)puVar4 + 0x39) = 1;
      os_msleep(*puVar4,iVar5);
    }
    *(undefined1 *)((int)puVar4 + 0x39) = 2;
    puVar4[0xf] = puVar4[0xf] + 1;
    *(byte *)(puVar4 + 0xe) = *(byte *)(puVar4 + 0xe) & 0xef;
    valid_type(0x23);
    if ((2 < *(int *)(DAT_30049efc + 0x78)) && (2 < *(int *)(DAT_30049efc + 0x8c))) {
      os_dprintf(DAT_30049f00,DAT_30049ef8,DAT_30049fa8);
      os_printf(DAT_30049fac,param_1);
    }
    jos_critical_enter_d(DAT_30049ef8,DAT_30049fb0);
    iVar3 = puVar4[1];
    if (iVar3 == 0) {
      jos_critical_leave_d(DAT_30049ef8,DAT_30049fb4);
    }
    else if (*(char *)(iVar3 + 0x18) == '\x02') {
      if (*(int *)(iVar3 + 0x10) == 0) {
        os_dprintf(DAT_3004a0ac,DAT_30049ef8,DAT_3004a0b0);
        os_dprintf(DAT_3004a0b4,*(undefined4 *)(iVar3 + 0xc),iVar3);
        os_panic(DAT_3004a0b8,DAT_30049ef8,DAT_3004a0b0);
      }
      os_get_time(&local_30);
      os_memcpy(puVar4 + 0x10,&local_30,8);
      valid_type(0x23);
      if ((3 < *(int *)(DAT_30049efc + 0x78)) && (3 < *(int *)(DAT_30049efc + 0x8c))) {
        os_dprintf(DAT_30049f00,DAT_30049ef8,DAT_3004a0bc);
        uVar2 = DAT_3004a0c0;
        if ((local_30 <= *(int *)(iVar3 + 4)) &&
           ((local_30 != *(int *)(iVar3 + 4) || (local_2c < *(int *)(iVar3 + 8))))) {
          uVar2 = DAT_3004a0c4;
        }
        iVar5 = *(int *)(iVar3 + 8) - local_2c;
        os_printf(DAT_3004a0c8,param_1,iVar3,
                  (*(int *)(iVar3 + 4) - local_30) * 1000 +
                  ((int)(iVar5 + ((uint)(iVar5 >> 0x1f) >> 0x16)) >> 10),uVar2);
      }
      iVar5 = *(int *)(iVar3 + 8) - local_2c;
      if ((*(int *)(iVar3 + 4) - local_30) * 1000 +
          ((int)(iVar5 + ((uint)(iVar5 >> 0x1f) >> 0x16)) >> 10) < 1) {
        pcVar7 = *(code **)(iVar3 + 0x10);
        uVar6 = *(undefined4 *)(iVar3 + 0x14);
        puVar4[0x12] = iVar3;
        FUN_30048358(iVar3);
        *(undefined1 *)(iVar3 + 0x18) = 1;
        uVar2 = os_get_context();
        *(undefined4 *)(iVar3 + 0x1c) = uVar2;
        valid_type(0x23);
        if ((2 < *(int *)(DAT_30049efc + 0x78)) && (2 < *(int *)(DAT_30049efc + 0x8c))) {
          os_dprintf(DAT_30049f00,DAT_30049ef8,0x218);
          os_printf(DAT_3004a230,*(undefined4 *)(iVar3 + 0xc),iVar3);
        }
        jos_critical_leave_d(DAT_30049ef8,DAT_3004a234);
        (*pcVar7)(uVar6);
        if (*(int *)(iVar3 + 0x20) == 0) {
          jos_critical_enter_d(DAT_30049ef8,DAT_3004a348);
          cVar1 = *(char *)(iVar3 + 0x18);
          if (cVar1 == '\x01') {
            *(undefined1 *)(iVar3 + 0x18) = 0;
          }
          else if (cVar1 == '\x03') {
            *(undefined1 *)(iVar3 + 0x18) = 2;
          }
          else if (cVar1 == '\x04') {
            *(undefined1 *)(iVar3 + 0x18) = 0;
            os_wakeup(*(undefined4 *)(iVar3 + 0x24));
          }
          else {
            jos_critical_leave_d(DAT_30049ef8,DAT_3004a34c);
            os_panic(DAT_3004a350,*(undefined1 *)(iVar3 + 0x18));
          }
          jos_critical_leave_d(DAT_30049ef8,0x244);
          puVar4[0x12] = 0;
        }
        else {
          if (*(char *)(iVar3 + 0x18) == '\x03') {
            FUN_30048358(iVar3);
          }
          valid_type(0x23);
          if ((4 < *(int *)(DAT_30049efc + 0x78)) && (4 < *(int *)(DAT_30049efc + 0x8c))) {
            os_dprintf(DAT_30049f00,DAT_30049ef8,0x224);
            os_printf(DAT_3004a340);
          }
          os_msleep_uninit(*(undefined4 *)(iVar3 + 0x24));
          BSP_FreeDbg(iVar3,DAT_30049ef8,DAT_3004a344);
          puVar4[0x12] = 0;
        }
      }
      else {
        jos_critical_leave_d(DAT_30049ef8,DAT_3004a228);
        valid_type(0x23);
        if ((3 < *(int *)(DAT_30049efc + 0x78)) && (3 < *(int *)(DAT_30049efc + 0x8c))) {
          os_dprintf(DAT_30049f00,DAT_30049ef8,0x208);
          iVar5 = *(int *)(iVar3 + 8) - local_2c;
          os_printf(DAT_3004a22c,*(undefined4 *)(iVar3 + 0xc),iVar3,
                    (*(int *)(iVar3 + 4) - local_30) * 1000 +
                    ((int)(iVar5 + ((uint)(iVar5 >> 0x1f) >> 0x16)) >> 10));
        }
      }
    }
    else {
      jos_critical_leave_d(DAT_30049ef8,DAT_30049fb8);
      valid_type(0x23);
      if ((0 < *(int *)(DAT_30049efc + 0x78)) && (0 < *(int *)(DAT_30049efc + 0x8c))) {
        os_dprintf(DAT_30049f00,DAT_30049ef8,0x1f0);
        os_printf(DAT_30049fbc,*(undefined1 *)(iVar3 + 0x18));
      }
    }
  }
  valid_type(0x23);
  if ((2 < *(int *)(DAT_30049efc + 0x78)) && (2 < *(int *)(DAT_30049efc + 0x8c))) {
    os_dprintf(DAT_30049f00,DAT_30049ef8,0x250);
    os_printf(DAT_3004a3e4,param_1);
  }
  *(byte *)(puVar4 + 0xe) = *(byte *)(puVar4 + 0xe) | 8;
  *(undefined1 *)((int)puVar4 + 0x39) = 3;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300496a0 @ 0x300496A0  (примерный размер ~508 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 6
 * Вызывает: os_delay_ms, os_dprintf, os_msleep_uninit, os_printf, os_wakeup, valid_type
 * Вызывают: FUN_300498e4, task_threads_init, task_threads_uninit
 * Константы: 0x300496A0
 * Данные: DAT_30049b98, DAT_30049ef8, DAT_30049efc, DAT_30049f00, DAT_3004a3e8, DAT_3004a3ec, DAT_3004a3f0, DAT_3004a3f4
 * ---------------------------------------------------------------- */
void FUN_300496a0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(DAT_30049b98 + param_1 * 0x50);
  valid_type(0x23);
  if ((2 < *(int *)(DAT_30049efc + 0x78)) && (2 < *(int *)(DAT_30049efc + 0x8c))) {
    os_dprintf(DAT_30049f00,DAT_30049ef8,DAT_3004a3e8);
    os_printf(DAT_3004a3ec,param_1);
  }
  if ((*(byte *)(puVar2 + 0xe) & 2) != 0) {
    if (puVar2[1] != 0) {
      valid_type(0x23);
      if ((0 < *(int *)(DAT_30049efc + 0x78)) && (0 < *(int *)(DAT_30049efc + 0x8c))) {
        os_dprintf(DAT_30049f00,DAT_30049ef8,DAT_3004a3f0);
        os_printf(DAT_3004a3f4,param_1,puVar2[1]);
      }
      for (piVar1 = (int *)puVar2[1]; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
        valid_type(0x23);
        if ((0 < *(int *)(DAT_30049efc + 0x78)) && (0 < *(int *)(DAT_30049efc + 0x8c))) {
          os_dprintf(DAT_30049f00,DAT_30049ef8,DAT_3004a3f8);
          os_printf(DAT_3004a3fc,piVar1,piVar1[1],piVar1[2],piVar1[10],piVar1[0xb]);
        }
      }
      puVar2[1] = 0;
    }
    *(byte *)(puVar2 + 0xe) = *(byte *)(puVar2 + 0xe) & 0xfb;
    os_wakeup(*puVar2);
    while ((*(byte *)(puVar2 + 0xe) & 8) == 0) {
      valid_type(0x23);
      if ((2 < *(int *)(DAT_30049efc + 0x78)) && (2 < *(int *)(DAT_30049efc + 0x8c))) {
        os_dprintf(DAT_30049f00,DAT_30049ef8,DAT_3004a400);
        os_printf(DAT_3004a404,param_1);
      }
      os_delay_ms(0x37);
    }
  }
  if ((*(byte *)(puVar2 + 0xe) & 1) != 0) {
    *(byte *)(puVar2 + 0xe) = *(byte *)(puVar2 + 0xe) & 0xfe;
    os_msleep_uninit(*puVar2);
  }
  return;
}

/* ----------------------------------------------------------------
 * jmutex_unlock_d @ 0x30049BC8  (примерный размер ~360 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 4
 * Вызывает: os_dprintf, os_get_context, os_mutex_unlock, os_panic
 * Вызывают: jcore_safe_leave, jcore_safe_leave_d, jos_safe_leave_d
 * Константы: 0x30049BC8
 * Данные: DAT_30049ef8, DAT_3004a0ac, DAT_3004a0b8, DAT_3004a428, DAT_3004a42c, DAT_3004a430, DAT_3004a438, DAT_3004a43c
 * ---------------------------------------------------------------- */
void jmutex_unlock_d(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_3004a0ac,DAT_30049ef8,DAT_3004a438);
    os_dprintf(DAT_3004a43c,param_2,param_3);
    os_panic(DAT_3004a0b8,DAT_30049ef8,DAT_3004a438);
  }
  if (param_1[3] == 0) {
    os_dprintf(DAT_3004a0ac,DAT_30049ef8,DAT_3004a440);
    uVar2 = DAT_3004a430;
    if ((int *)*DAT_3004a428 != param_1) {
      uVar2 = DAT_3004a42c;
    }
    os_dprintf(DAT_3004a444,uVar2,param_2,param_3);
    os_panic(DAT_3004a0b8,DAT_30049ef8,DAT_3004a440);
  }
  iVar1 = os_get_context();
  if (iVar1 != *param_1) {
    os_dprintf(DAT_3004a0ac,DAT_30049ef8,DAT_3004a448);
    uVar2 = DAT_3004a430;
    if ((int *)*DAT_3004a428 != param_1) {
      uVar2 = DAT_3004a42c;
    }
    os_dprintf(DAT_3004a44c,uVar2,param_2,param_3,param_1[1],param_1[2]);
    os_panic(DAT_3004a0b8,DAT_30049ef8,DAT_3004a448);
  }
  param_1[3] = 0;
  *param_1 = 0;
  param_1[1] = DAT_3004a450;
  param_1[2] = 0;
  os_mutex_unlock(param_1[4]);
  return;
}

/* ----------------------------------------------------------------
 * jmutex_lock_d @ 0x30049D54  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: jos_mutex_lock_checked, jos_safe_enter_d, jos_safe_leave_d
 * Вызывают: jcore_safe_enter, jcore_safe_enter_d
 * Константы: 0x30049D54
 * ---------------------------------------------------------------- */
void jmutex_lock_d(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  jos_safe_leave_d(param_2,param_3);
  jos_mutex_lock_checked(param_1,param_2,param_3);
  jos_safe_enter_d(param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * jcore_safe_enter @ 0x30049D90  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: jmutex_lock_d
 * Константы: 0x30049D90
 * Данные: DAT_30049ef8, DAT_3004a454
 * ---------------------------------------------------------------- */
void jcore_safe_enter(void)

{
  jmutex_lock_d(*DAT_3004a454,DAT_30049ef8,0x37c);
  return;
}

/* ----------------------------------------------------------------
 * jcore_safe_leave @ 0x30049DA4  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: jmutex_unlock_d
 * Константы: 0x30049DA4
 * Данные: DAT_30049ef8, DAT_3004a454, DAT_3004a458
 * ---------------------------------------------------------------- */
void jcore_safe_leave(void)

{
  jmutex_unlock_d(*DAT_3004a454,DAT_30049ef8,DAT_3004a458);
  return;
}

/* ----------------------------------------------------------------
 * jmutex_init_d @ 0x30049DB8  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: BSP_FreeDbg, FUN_3004a390, os_mutex_init
 * Вызывают: jos_safe_init, jos_sync_init
 * Константы: 0x30049DB8
 * Данные: DAT_30049ef8, DAT_3004a45c, DAT_3004a460
 * ---------------------------------------------------------------- */
int jmutex_init_d(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_3004a390(0x14,1,DAT_30049ef8,DAT_3004a45c);
  if (iVar1 == 0) {
    iVar2 = 7;
  }
  else {
    iVar2 = os_mutex_init(iVar1 + 0x10);
    if (iVar2 == 0) {
      *param_1 = iVar1;
      iVar2 = 0;
    }
    else {
      BSP_FreeDbg(iVar1,DAT_30049ef8,DAT_3004a460);
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * jmutex_uninit_d @ 0x30049E40  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: BSP_FreeDbg, os_dprintf, os_mutex_uninit, os_panic
 * Вызывают: jos_safe_uninit, jos_sync_uninit
 * Константы: 0x30049E40
 * Данные: DAT_30049ef8, DAT_3004a0ac, DAT_3004a0b8, DAT_3004a468, DAT_3004a46c, DAT_3004a470, DAT_3004a474, DAT_3004a478
 * ---------------------------------------------------------------- */
void jmutex_uninit_d(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 == 0) {
    os_dprintf(DAT_3004a0ac,DAT_30049ef8,DAT_3004a468);
    os_dprintf(DAT_3004a46c,param_2,param_3);
    os_panic(DAT_3004a0b8,DAT_30049ef8,DAT_3004a468);
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    os_dprintf(DAT_3004a0ac,DAT_30049ef8,DAT_3004a470);
    os_dprintf(DAT_3004a474,param_2,param_3,*(undefined4 *)(param_1 + 4),
               *(undefined4 *)(param_1 + 8));
    os_panic(DAT_3004a0b8,DAT_30049ef8,DAT_3004a470);
  }
  os_mutex_uninit(*(undefined4 *)(param_1 + 0x10));
  BSP_FreeDbg(param_1,DAT_30049ef8,DAT_3004a478);
  return;
}

/* ----------------------------------------------------------------
 * jcore_safe_enter_d @ 0x30049FC0  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: jmutex_lock_d
 * Вызывают: add_generic_controller, del_generic_controller, generic_controller_resume, generic_controller_suspend
 * Константы: 0x30049FC0
 * Данные: DAT_3004a454
 * ---------------------------------------------------------------- */
void jcore_safe_enter_d(undefined4 param_1,undefined4 param_2)

{
  jmutex_lock_d(*DAT_3004a454,param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * jcore_safe_leave_d @ 0x30049FE4  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: jmutex_unlock_d
 * Вызывают: add_generic_controller, del_generic_controller, generic_controller_resume, generic_controller_suspend
 * Константы: 0x30049FE4
 * Данные: DAT_3004a454
 * ---------------------------------------------------------------- */
void jcore_safe_leave_d(undefined4 param_1,undefined4 param_2)

{
  jmutex_unlock_d(*DAT_3004a454,param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * core_add_msos_string_descriptor @ 0x3004A780  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3004A780
 * ---------------------------------------------------------------- */
void core_add_msos_string_descriptor(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0xc0) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * core_add_string_descriptor @ 0x3004A79C  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: chp9_set_string_descriptors
 * Константы: 0x3004A79C
 * ---------------------------------------------------------------- */
char core_add_string_descriptor(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  
  if (param_2 == 0) {
    cVar1 = '\0';
  }
  else {
    bVar2 = 0;
    while ((bVar2 < 0x20 && (*(int *)(param_1 + (uint)bVar2 * 4 + 0x40) != 0))) {
      bVar2 = bVar2 + 1;
    }
    if (bVar2 == 0x20) {
      cVar1 = '\0';
    }
    else {
      *(int *)(param_1 + (uint)bVar2 * 4 + 0x40) = param_2;
      cVar1 = bVar2 + 1;
    }
  }
  return cVar1;
}

/* ----------------------------------------------------------------
 * core_release_string_descriptor @ 0x3004A824  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: chp9_set_string_descriptors
 * Константы: 0x3004A824
 * ---------------------------------------------------------------- */
void core_release_string_descriptor(int param_1,byte param_2)

{
  if ((param_2 != 0) && (param_2 < 0x21)) {
    *(undefined4 *)(param_1 + (uint)param_2 * 4 + 0x3c) = 0;
  }
  return;
}

