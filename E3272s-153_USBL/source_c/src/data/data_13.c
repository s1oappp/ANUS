/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 13 (функций: 150, адреса 0x300FBEAC..0x3011C940)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * FUN_300fbeac @ 0x300FBEAC  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: free, loadModuleSeek, loadModuleStringRead, malloc
 * Вызывают: FUN_300fbfdc
 * Константы: 0x300FBEAC, 0xFFFFFFFF
 * Данные: DAT_300fc1d4, DAT_300fc1d8
 * ---------------------------------------------------------------- */
undefined4 FUN_300fbeac(undefined4 param_1,int *param_2,int param_3)

{
  size_t __size;
  void *pvVar1;
  int iVar2;
  
  iVar2 = DAT_300fc1d4;
  if (param_2[3] == 1) {
    *param_2 = DAT_300fc1d4;
    param_2[2] = DAT_300fc1d8 - iVar2;
    return 0;
  }
  __size = *(size_t *)(param_3 + 0x14);
  param_2[2] = __size;
  pvVar1 = malloc(__size);
  *param_2 = (int)pvVar1;
  if (pvVar1 != (void *)0x0) {
    iVar2 = loadModuleSeek(param_1,*(undefined4 *)(param_3 + 0x10),0);
    if ((iVar2 != -1) && (iVar2 = loadModuleStringRead(param_1,*param_2,param_2[2]), iVar2 == 0)) {
      param_2[4] = 1;
      return 0;
    }
    free((void *)*param_2);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300fbf48 @ 0x300FBF48  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: printErr, strlen, tagCheckModuleDel, tagCheckStatementAdd
 * Вызывают: FUN_300fbfdc
 * Константы: 0x300FBF48, 0xFFFFFFFF
 * Данные: DAT_300fc1dc
 * ---------------------------------------------------------------- */
undefined4 FUN_300fbf48(undefined4 *param_1)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  char *__s;
  undefined1 auStack_214 [512];
  
  __s = (char *)*param_1;
  pcVar3 = __s + param_1[2];
  while( true ) {
    if (pcVar3 <= __s) {
      return 0;
    }
    iVar1 = tagCheckStatementAdd(param_1[1],__s,auStack_214,0x200);
    if (iVar1 != 0) break;
    sVar2 = strlen(__s);
    __s = __s + sVar2 + 1;
  }
  printErr(DAT_300fc1dc,auStack_214);
  tagCheckModuleDel(param_1[1]);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300fbfdc @ 0x300FBFDC  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300fbe34, FUN_300fbeac, FUN_300fbf48, free
 * Вызывают: loadModuleTagsCheck
 * Константы: 0x300FBFDC, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4
FUN_300fbfdc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  iVar1 = FUN_300fbeac(param_1,param_4,param_2);
  if ((iVar1 == 0) && (iVar1 = FUN_300fbe34(param_3,param_4), iVar1 == 0)) {
    uVar2 = FUN_300fbf48(param_4);
  }
  if (param_4[4] != 0) {
    free((void *)*param_4);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300fc03c @ 0x300FC03C  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: errnoSet, printErr, tagCheckEvaluateAsserts, tagCheckModuleDel
 * Вызывают: loadModuleTagsCheck
 * Константы: 0x300FC03C, 0xFFFFFFFF
 * Данные: DAT_300fc1e0, DAT_300fc1e4, DAT_300fc1e8
 * ---------------------------------------------------------------- */
undefined4 FUN_300fc03c(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_210 [512];
  
  uVar2 = 0;
  iVar1 = tagCheckEvaluateAsserts(auStack_210,0x200);
  if (iVar1 != 0) {
    if ((param_2 & 0x80) == 0) {
      printErr(DAT_300fc1e4,auStack_210);
      errnoSet(DAT_300fc1e8);
      uVar2 = 0xffffffff;
    }
    else {
      printErr(DAT_300fc1e0,auStack_210);
    }
  }
  tagCheckModuleDel(*(undefined4 *)(param_1 + 4));
  return uVar2;
}

/* ----------------------------------------------------------------
 * loadModuleTagsCheck @ 0x300FC0B0  (примерный размер ~324 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300fbfdc, FUN_300fc03c, memcmp, memset
 * Вызывают: FUN_300fa0b8
 * Константы: 0x300FC0B0, 0xFFFFFFFF
 * Данные: DAT_300fc1ec, DAT_300fc1f0
 * ---------------------------------------------------------------- */
undefined4
loadModuleTagsCheck(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,
                   undefined4 param_5,int param_6,undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined1 auStack_34 [12];
  undefined4 local_28;
  
  piVar1 = DAT_300fc1ec;
  if ((DAT_300fc1ec[1] == 0) && (1 < param_4)) {
    piVar5 = (int *)(param_3 + 0x28);
    iVar4 = param_4 - 1;
    do {
      iVar2 = memcmp((void *)(param_6 + *piVar5),DAT_300fc1f0,0x10);
      if ((iVar2 == 0) && (piVar5[5] != 0)) {
        memset(auStack_34,0,0x14);
        if (*piVar1 == 0) {
          local_28 = 1;
          iVar4 = FUN_300fbfdc(param_1,piVar5,param_2,auStack_34);
          if (iVar4 != 0) {
            piVar1[1] = 1;
            return 0;
          }
          *piVar1 = 1;
        }
        memset(auStack_34,0,0x14);
        local_28 = 2;
        iVar4 = FUN_300fbfdc(param_1,piVar5,param_2,auStack_34);
        if (iVar4 != 0) {
          return 0xffffffff;
        }
        uVar3 = FUN_300fc03c(auStack_34,param_7);
        return uVar3;
      }
      piVar5 = piVar5 + 10;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * loadShareTgtMemAlign @ 0x300FC1F4  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: memPartAlignedAlloc
 * Вызывают: FUN_300fbbc0, loadSegmentsAllocate
 * Константы: 0x300FC1F4
 * Данные: DAT_300f1a40
 * ---------------------------------------------------------------- */
void loadShareTgtMemAlign(undefined4 param_1,undefined4 param_2)

{
  memPartAlignedAlloc(*DAT_300f1a40,param_2,param_1);
  return;
}

/* ----------------------------------------------------------------
 * loadShareTgtMemSet @ 0x300FC1F8  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: bfill
 * Вызывают: FUN_300fbbc0, loadSectionsInstall
 * Константы: 0x300FC1F8
 * ---------------------------------------------------------------- */
void * loadShareTgtMemSet(void *__s,int __c,size_t __n)

{
  bfill(__s,__n,__c);
  return __s;
}

/* ----------------------------------------------------------------
 * loadShareTgtMemFree @ 0x300FC1FC  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300f2884
 * Константы: 0x300FC1FC
 * Данные: DAT_300f2ee8
 * ---------------------------------------------------------------- */
void loadShareTgtMemFree(void *__ptr)

{
  int iVar1;
  
  iVar1 = *DAT_300f2ee8;
  if (*(code **)(iVar1 + 0xcc) == (code *)0x0) {
    FUN_300f2884(iVar1,__ptr);
  }
  else {
    (**(code **)(iVar1 + 0xcc))(iVar1,*(undefined4 *)(iVar1 + 0xd8),__ptr);
  }
  return;
}

/* ----------------------------------------------------------------
 * completionSymListGet @ 0x300FD824  (примерный размер ~664 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 13
 * Вызывает: cplusDemangleToBuffer, free, lstAdd, lstDelete, lstFirst, lstGet, lstInit, lstNext, malloc, strcmp, strcpy, strlen, symListGet
 * Вызывают: FUN_3010c4f0, ledDfltComplete
 * Константы: 0x300FD824
 * Данные: DAT_300fe724
 * ---------------------------------------------------------------- */
undefined4 completionSymListGet(undefined4 param_1,int param_2)

{
  bool bVar1;
  char *__src;
  int iVar2;
  size_t sVar3;
  void *pvVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *local_240;
  char *local_23c;
  size_t local_238;
  undefined1 auStack_234 [12];
  undefined1 auStack_228 [256];
  undefined1 local_128;
  undefined1 auStack_124 [256];
  undefined1 local_24;
  
  uVar8 = *(undefined4 *)(param_2 + 0xc);
  lstInit(auStack_234);
  symListGet(param_1,uVar8,0,auStack_234);
  symListGet(param_1,uVar8,1,auStack_234);
  for (iVar2 = lstFirst(auStack_234); iVar2 != 0; iVar2 = lstNext(iVar2)) {
    pvVar5 = (void *)lstNext(iVar2);
    while (pvVar4 = pvVar5, pvVar4 != (void *)0x0) {
      pvVar5 = (void *)lstNext(pvVar4);
      iVar6 = strcmp(*(char **)(iVar2 + 8),*(char **)((int)pvVar4 + 8));
      if (iVar6 == 0) {
        lstDelete(auStack_234,pvVar4);
        free(pvVar4);
      }
    }
  }
  while (pvVar5 = (void *)lstGet(auStack_234), pvVar5 != (void *)0x0) {
    local_23c = *(char **)((int)pvVar5 + 0x10);
    bVar1 = false;
    pcVar9 = *(char **)((int)pvVar5 + 8);
    if (local_23c == (char *)0x0) {
      local_238 = 0x100;
      local_128 = 0;
      cplusDemangleToBuffer(pcVar9,auStack_228,&local_238,2,&local_23c);
      iVar2 = strcmp(local_23c,pcVar9);
      if (iVar2 == 0) {
        local_23c = (char *)0x0;
        bVar1 = true;
      }
    }
    local_240 = *(char **)((int)pvVar5 + 0xc);
    if ((local_240 == (char *)0x0) && (!bVar1)) {
      local_238 = 0x100;
      local_24 = 0;
      cplusDemangleToBuffer(pcVar9,auStack_124,&local_238,1,&local_240);
      iVar2 = strcmp(local_240,pcVar9);
      if (iVar2 == 0) {
        local_240 = (char *)0x0;
      }
    }
    __src = local_23c;
    iVar2 = 0;
    if (local_23c != (char *)0x0) {
      sVar3 = strlen(local_23c);
      iVar2 = sVar3 + 1;
    }
    iVar6 = 0;
    if (local_240 != (char *)0x0) {
      sVar3 = strlen(local_240);
      iVar6 = sVar3 + 1;
    }
    sVar3 = strlen(pcVar9);
    local_238 = sVar3 + iVar2 + iVar6 + 0x19;
    pvVar4 = malloc(local_238);
    if (pvVar4 != (void *)0x0) {
      *(char **)((int)pvVar4 + 8) = (char *)((int)pvVar4 + 0x18);
      strcpy((char *)((int)pvVar4 + 0x18),pcVar9);
      sVar3 = strlen(pcVar9);
      pcVar9 = (char *)(*(int *)((int)pvVar4 + 8) + sVar3 + 1);
      if (*(uint *)((int)pvVar5 + 0x14) < 4) {
        uVar7 = (uint)*(byte *)(DAT_300fe724 + *(uint *)((int)pvVar5 + 0x14));
      }
      else {
        uVar7 = 0;
      }
      *(uint *)((int)pvVar4 + 0x14) = uVar7;
      if (__src != (char *)0x0) {
        *(char **)((int)pvVar4 + 0xc) = pcVar9;
        strcpy(pcVar9,__src);
        pcVar9 = *(char **)((int)pvVar4 + 0xc);
        sVar3 = strlen(pcVar9);
        pcVar9 = pcVar9 + sVar3 + 1;
      }
      if (local_240 != (char *)0x0) {
        *(char **)((int)pvVar4 + 0x10) = pcVar9;
        strcpy(pcVar9,local_240);
      }
      lstAdd(param_2,pvVar4);
    }
    free(pvVar5);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300fdabc @ 0x300FDABC  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300fdaf4, completionSymComplete, completionSymShow
 * Константы: 0x300FDABC
 * ---------------------------------------------------------------- */
int FUN_300fdabc(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x14) == 2) {
    iVar1 = *(int *)(param_1 + 0x10);
  }
  else if (*(int *)(param_1 + 0x14) == 3) {
    iVar1 = *(int *)(param_1 + 0xc);
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 8);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300fdaf4 @ 0x300FDAF4  (примерный размер ~248 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_300fdabc, calloc, free, lstFirst, lstNext, strlen, strncmp, strncpy
 * Вызывают: completionSymComplete
 * Константы: 0x300FDAF4
 * ---------------------------------------------------------------- */
void FUN_300fdaf4(undefined4 param_1,size_t param_2,char *param_3,size_t param_4)

{
  int iVar1;
  char *pcVar2;
  char *__dest;
  int iVar3;
  size_t sVar4;
  
  do {
    iVar1 = lstFirst(param_1);
    pcVar2 = (char *)FUN_300fdabc();
    __dest = (char *)calloc(2,param_2 + 1);
    if (__dest == (char *)0x0) {
      strncpy(param_3,pcVar2,param_4);
      return;
    }
    strncpy(__dest,pcVar2,param_2);
    strncpy(__dest + param_2 + 1,pcVar2,param_2 - 1);
    while (iVar1 = lstNext(iVar1), iVar1 != 0) {
      pcVar2 = (char *)FUN_300fdabc(iVar1);
      iVar3 = strncmp(__dest,pcVar2,param_2);
      if ((iVar3 != 0) || (sVar4 = strlen(pcVar2), sVar4 + 1 == param_2)) {
        strncpy(param_3,__dest + param_2 + 1,param_4);
        free(__dest);
        return;
      }
    }
    param_2 = param_2 + 1;
    free(__dest);
  } while( true );
}

/* ----------------------------------------------------------------
 * completionSymComplete @ 0x300FDBEC  (примерный размер ~304 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 8
 * Вызывает: FUN_300fdabc, FUN_300fdaf4, lstCount, lstFirst, lstNext, strcmp, strlen, strncpy
 * Вызывают: FUN_3010c4f0, ledDfltComplete
 * Константы: 0x300FDBEC
 * ---------------------------------------------------------------- */
int completionSymComplete(int param_1,char *param_2,size_t param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  size_t sVar8;
  
  if (param_1 == 0) {
    return -1;
  }
  iVar2 = lstCount(param_1);
  if (iVar2 != 0) {
    if (iVar2 != 1) {
      uVar4 = lstFirst(param_1);
      pcVar3 = (char *)FUN_300fdabc();
      iVar5 = lstNext(uVar4);
      if (iVar5 != 0) {
        do {
          pcVar6 = (char *)FUN_300fdabc(iVar5);
          iVar7 = strcmp(pcVar3,pcVar6);
          if (iVar7 != 0) break;
          iVar5 = lstNext(iVar5);
        } while (iVar5 != 0);
        if (iVar5 != 0) {
          pcVar6 = *(char **)(param_1 + 0xc);
          sVar8 = strlen(pcVar6);
          if (*pcVar6 != '_') {
            cVar1 = *pcVar3;
            while (cVar1 == '_') {
              pcVar3 = pcVar3 + 1;
              sVar8 = sVar8 + 1;
              cVar1 = *pcVar3;
            }
          }
          FUN_300fdaf4(param_1,sVar8 + 1,param_2,param_3);
          return iVar2;
        }
      }
      strncpy(param_2,pcVar3,param_3);
      return 1;
    }
    lstFirst(param_1);
    pcVar3 = (char *)FUN_300fdabc();
    strncpy(param_2,pcVar3,param_3);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300fdd1c @ 0x300FDD1C  (примерный размер ~356 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: __div32, __udiv32, shellPrint, strlen
 * Вызывают: completionPathShow, completionSymShow
 * Константы: 0x300FDD1C
 * Данные: DAT_300fe728, DAT_300fe72c, DAT_300fe730
 * ---------------------------------------------------------------- */
void FUN_300fdd1c(char *param_1,int param_2,int param_3,char *param_4,char *param_5)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  size_t sVar5;
  
  sVar5 = 0;
  if (param_4 != (char *)0x0) {
    sVar5 = strlen(param_4);
  }
  sVar4 = 0;
  if (param_5 != (char *)0x0) {
    sVar4 = strlen(param_5);
  }
  param_2 = param_2 + 1;
  if (param_2 < 0x4f) {
    iVar1 = __div32(0x4e,param_2);
    iVar2 = __udiv32(param_3,iVar1);
    if (param_3 == iVar1 * iVar2) {
      shellPrint(0,DAT_300fe728);
    }
    if (param_4 != (char *)0x0) {
      shellPrint(0,DAT_300fe72c,param_4);
    }
    shellPrint(0,DAT_300fe72c,param_1);
    if (param_5 != (char *)0x0) {
      shellPrint(0,DAT_300fe72c,param_5);
    }
    iVar1 = __div32(0x4e - param_2 * iVar1,iVar1);
    sVar3 = strlen(param_1);
    iVar1 = iVar1 + ((param_2 - sVar3) - (sVar5 + sVar4));
    if (iVar1 < 1) {
      iVar1 = 1;
    }
    do {
      shellPrint(0,DAT_300fe730);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  else {
    shellPrint(0,DAT_300fe728);
    if (param_4 != (char *)0x0) {
      shellPrint(0,DAT_300fe72c,param_4);
    }
    shellPrint(0,DAT_300fe72c,param_1);
    if (param_5 == (char *)0x0) {
      return;
    }
    shellPrint(0,DAT_300fe72c,param_5);
  }
  return;
}

/* ----------------------------------------------------------------
 * completionSymShow @ 0x300FDE80  (примерный размер ~404 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 10
 * Вызывает: FUN_300fdabc, FUN_300fdd1c, __stdout, fflush, lstCount, lstFirst, lstNext, shellPrint, strcmp, strlen
 * Вызывают: FUN_3010c4f0
 * Константы: 0x300FDE80
 * Данные: DAT_300fe728
 * ---------------------------------------------------------------- */
int completionSymShow(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  size_t sVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  bool bVar12;
  
  if (param_1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = lstCount(param_1);
    if (1 < iVar1) {
      uVar2 = lstFirst(param_1);
      pcVar3 = (char *)FUN_300fdabc();
      iVar4 = lstNext(uVar2);
      bVar12 = iVar4 == 0;
      if (!bVar12) {
        do {
          pcVar5 = (char *)FUN_300fdabc(iVar4);
          if (((pcVar3 != (char *)0x0) && (pcVar5 != (char *)0x0)) &&
             (iVar6 = strcmp(pcVar3,pcVar5), iVar6 != 0)) break;
          iVar4 = lstNext(iVar4);
        } while (iVar4 != 0);
        bVar12 = iVar4 == 0;
      }
      if (bVar12) {
        iVar1 = 1;
      }
      else {
        uVar11 = 0;
        for (iVar4 = lstFirst(param_1); iVar4 != 0; iVar4 = lstNext(iVar4)) {
          pcVar3 = (char *)FUN_300fdabc(iVar4);
          sVar7 = strlen(pcVar3);
          if (uVar11 < sVar7) {
            uVar11 = sVar7;
          }
        }
        iVar6 = lstFirst(param_1);
        iVar4 = 0;
        while (iVar6 != 0) {
          pcVar3 = (char *)FUN_300fdabc(iVar6);
          iVar8 = lstFirst(param_1);
          if (iVar8 == iVar6) {
LAB_300fdfc4:
            iVar9 = iVar4 + 1;
            FUN_300fdd1c(pcVar3,uVar11,iVar4,0,0);
          }
          else {
            do {
              pcVar5 = (char *)FUN_300fdabc(iVar8);
              iVar9 = strcmp(pcVar3,pcVar5);
              if (iVar9 == 0) break;
              iVar8 = lstNext(iVar8);
            } while (iVar8 != iVar6);
            iVar9 = iVar4;
            if (iVar8 == iVar6) goto LAB_300fdfc4;
          }
          iVar6 = lstNext(iVar6);
          iVar4 = iVar9;
        }
        shellPrint(0,DAT_300fe728);
        puVar10 = (undefined4 *)__stdout();
        fflush((FILE *)*puVar10);
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300fe014 @ 0x300FE014  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: strcpy, strlen
 * Вызывают: completionPathListGet
 * Константы: 0x300FE014, 0xFFFFFFFF
 * Данные: DAT_300fe734
 * ---------------------------------------------------------------- */
void FUN_300fe014(char *param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  
  strcpy(param_2,param_1);
  strcpy(param_3,param_1);
  sVar2 = strlen(param_1);
  do {
    sVar1 = sVar2;
    sVar2 = sVar1 - 1;
    if (sVar2 == 0xffffffff) {
      *param_2 = '\0';
      return;
    }
  } while (param_2[sVar2] != '/');
  strcpy(param_3,param_2 + sVar1);
  param_2[sVar2] = '\0';
  if (*param_2 == '\0') {
    iVar4 = 2;
    pcVar3 = DAT_300fe734;
    do {
      iVar4 = iVar4 + -1;
      *param_2 = *pcVar3;
      param_2 = param_2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (iVar4 != 0);
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * completionPathListGet @ 0x300FE0C0  (примерный размер ~508 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 13
 * Вызывает: FUN_300fe014, calloc, closedir, free, lstAdd, malloc, memcmp, opendir, readdir, sprintf, stat, strlen, strncmp
 * Вызывают: shellCompletionPathnameGet
 * Константы: 0xFFFFFFFF, 0x300FE0C0
 * Данные: DAT_300fe738, DAT_300fe73c, DAT_300fe740, DAT_300fe744
 * ---------------------------------------------------------------- */
undefined4 completionPathListGet(int param_1)

{
  size_t sVar1;
  char *__s;
  undefined4 uVar2;
  size_t sVar3;
  int iVar4;
  DIR *__dirp;
  size_t sVar5;
  size_t sVar6;
  void *pvVar7;
  dirent *pdVar8;
  char *__s_00;
  char *__format;
  char *pcVar9;
  char *__name;
  bool bVar10;
  uint local_64;
  
  pcVar9 = *(char **)(param_1 + 0xc);
  sVar1 = strlen(pcVar9);
  __s = (char *)calloc(2,sVar1 + 2);
  if (__s == (char *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    sVar1 = strlen(pcVar9);
    __s_00 = __s + sVar1 + 1;
    FUN_300fe014(pcVar9,__s,__s_00);
    sVar1 = strlen(__s);
    sVar3 = strlen(__s_00);
    pcVar9 = (char *)malloc(sVar3 + sVar1 + 3);
    if (pcVar9 == (char *)0x0) {
      free(__s);
      uVar2 = 0xffffffff;
    }
    else {
      bVar10 = sVar1 == 0;
      if (!bVar10) {
        bVar10 = __s[sVar1 - 1] == '/';
      }
      __format = DAT_300fe738;
      if (!bVar10) {
        __format = DAT_300fe73c;
      }
      sprintf(pcVar9,__format,__s,__s_00);
      sVar1 = strlen(pcVar9);
      iVar4 = memcmp(__s,DAT_300fe740,1);
      __name = DAT_300fe744;
      if (iVar4 != 0) {
        __name = __s;
      }
      __dirp = opendir(__name);
      if (__dirp == (DIR *)0x0) {
        free(pcVar9);
        free(__s);
        uVar2 = 0xffffffff;
      }
      else {
        sVar3 = strlen(__s_00);
        sVar5 = strlen(__s);
        while (pdVar8 = readdir(__dirp), pdVar8 != (dirent *)0x0) {
          iVar4 = strncmp((char *)&pdVar8->d_off,__s_00,sVar3);
          if (iVar4 == 0) {
            sVar6 = strlen((char *)&pdVar8->d_off);
            pvVar7 = malloc(sVar6 + sVar5 + 0x16);
            if (pvVar7 != (void *)0x0) {
              *(char **)((int)pvVar7 + 8) = (char *)((int)pvVar7 + 0x14);
              sprintf((char *)((int)pvVar7 + 0x14),__format,__s,&pdVar8->d_off);
              iVar4 = stat(*(char **)((int)pvVar7 + 8),(stat *)&stack0xffffff94);
              if ((iVar4 == -1) || ((local_64 & 0xf000) != 0x4000)) {
                uVar2 = 0;
              }
              else {
                uVar2 = 1;
              }
              *(undefined4 *)((int)pvVar7 + 0xc) = uVar2;
              *(size_t *)((int)pvVar7 + 0x10) = sVar1;
              lstAdd(param_1,pvVar7);
            }
          }
        }
        closedir(__dirp);
        free(pcVar9);
        free(__s);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300fe2bc @ 0x300FE2BC  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: lstFirst, lstNext, memcmp, strncmp, strncpy, strrchr
 * Вызывают: completionPathComplete
 * Константы: 0xFFFFFFFF, 0x300FE2BC
 * Данные: DAT_300fe744, DAT_300fe748
 * ---------------------------------------------------------------- */
undefined4 FUN_300fe2bc(undefined4 param_1,char *param_2,uint param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char *__s1;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = lstFirst();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  pcVar4 = *(char **)(iVar1 + 8);
  pcVar2 = strrchr(pcVar4,0x2f);
  if ((pcVar2 == (char *)0x0) && (pcVar2 = strrchr(pcVar4,0x5c), pcVar2 == (char *)0x0)) {
    pcVar2 = pcVar4 + -1;
  }
  pcVar2 = pcVar2 + (1 - (int)pcVar4);
  do {
    iVar5 = *(int *)(iVar1 + 8);
    iVar3 = memcmp(pcVar2 + iVar5,DAT_300fe744,2);
    if ((iVar3 != 0) && (iVar3 = memcmp(pcVar2 + iVar5,DAT_300fe748,3), iVar3 != 0)) break;
    iVar1 = lstNext(iVar1);
  } while (iVar1 != 0);
  if (iVar1 != 0) {
    uVar6 = *(uint *)(iVar1 + 0x10);
    iVar3 = iVar1;
    do {
      do {
        while (iVar3 = lstNext(iVar3), iVar3 == 0) {
          uVar6 = uVar6 + 1;
          iVar3 = iVar1;
        }
        pcVar4 = *(char **)(iVar3 + 8);
        iVar5 = memcmp(pcVar4 + (int)pcVar2,DAT_300fe744,2);
      } while ((iVar5 == 0) || (iVar5 = memcmp(pcVar4 + (int)pcVar2,DAT_300fe748,3), iVar5 == 0));
      __s1 = *(char **)(iVar1 + 8);
      iVar5 = strncmp(__s1,pcVar4,uVar6 + 1);
    } while (iVar5 == 0);
    if (uVar6 < param_3) {
      param_3 = uVar6;
    }
    strncpy(param_2,__s1,param_3);
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * completionPathComplete @ 0x300FE410  (примерный размер ~380 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_300fe2bc, lstCount, lstFirst, lstNext, memcmp, strlen, strncpy, strrchr
 * Вызывают: shellCompletionPathnameGet
 * Константы: 0x300FE410
 * Данные: DAT_300fe744, DAT_300fe748
 * ---------------------------------------------------------------- */
int completionPathComplete(undefined4 param_1,char *param_2,size_t param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  size_t sVar6;
  size_t sVar7;
  int iVar8;
  int iVar9;
  char *__s;
  
  iVar1 = lstCount();
  if (iVar1 == 0) {
    return 0;
  }
  if (iVar1 == 1) {
    iVar2 = lstFirst(param_1);
LAB_300fe4ec:
    if (iVar2 != 0) {
      strncpy(param_2,*(char **)(iVar2 + 8),param_3);
      if (*(int *)(iVar2 + 0xc) != 0) {
        sVar6 = strlen(*(char **)(iVar2 + 8));
        if (0 < (int)(param_3 - sVar6)) {
          sVar7 = strlen(param_2);
          param_2[sVar7] = '/';
          if (1 < (int)(param_3 - sVar6)) {
            param_2[sVar7 + 1] = '\0';
          }
        }
      }
      return 1;
    }
  }
  else if (iVar1 == 3) {
    iVar9 = 0;
    iVar3 = lstFirst(param_1);
    iVar8 = 0;
    if (iVar3 == 0) goto LAB_300fe560;
    do {
      __s = *(char **)(iVar3 + 8);
      pcVar4 = strrchr(__s,0x2f);
      if (pcVar4 != (char *)0x0) {
        __s = pcVar4 + 1;
      }
      iVar2 = memcmp(__s,DAT_300fe748,3);
      if ((iVar2 == 0) || (iVar5 = memcmp(__s,DAT_300fe744,2), iVar2 = iVar3, iVar5 == 0)) {
        iVar9 = iVar9 + 1;
        iVar2 = iVar8;
      }
      iVar3 = lstNext(iVar3);
      iVar8 = iVar2;
    } while (iVar3 != 0);
    if (iVar9 == 2) goto LAB_300fe4ec;
  }
  if (iVar1 == 0) {
    return 0;
  }
LAB_300fe560:
  iVar8 = FUN_300fe2bc(param_1,param_2,param_3);
  if (iVar8 != 0) {
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * completionPathShow @ 0x300FE58C  (примерный размер ~452 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 10
 * Вызывает: FUN_300fdd1c, __stdout, fflush, lstCount, lstFirst, lstNext, memcmp, shellPrint, strlen, strrchr
 * Вызывают: shellCompletionPathnameGet
 * Константы: 0x300FE58C
 * Данные: DAT_300fe728, DAT_300fe740, DAT_300fe744, DAT_300fe748, DAT_300fe74c
 * ---------------------------------------------------------------- */
int completionPathShow(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  undefined4 uVar11;
  bool bVar12;
  
  if (param_1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = lstCount(param_1);
    if (1 < iVar1) {
      uVar8 = 0;
      for (iVar2 = lstFirst(param_1); iVar2 != 0; iVar2 = lstNext(iVar2)) {
        pcVar5 = *(char **)(iVar2 + 8);
        if (param_2 == 0) {
          pcVar9 = strrchr(pcVar5,0x2f);
          if ((pcVar9 == (char *)0x0) && (pcVar9 = strrchr(pcVar5,0x5c), pcVar9 == (char *)0x0)) {
            pcVar9 = pcVar5 + -1;
          }
          pcVar5 = pcVar9 + 1;
        }
        sVar3 = strlen(pcVar5);
        if (uVar8 < sVar3) {
          uVar8 = sVar3;
        }
      }
      iVar4 = lstFirst(param_1);
      iVar2 = 0;
      while (iVar4 != 0) {
        pcVar9 = *(char **)(iVar4 + 8);
        iVar10 = *(int *)(iVar4 + 0xc);
        pcVar5 = strrchr(pcVar9,0x2f);
        if ((pcVar5 == (char *)0x0) && (pcVar5 = strrchr(pcVar9,0x5c), pcVar5 == (char *)0x0)) {
          pcVar5 = pcVar9 + -1;
        }
        pcVar5 = pcVar5 + 1;
        if (iVar10 != 0) {
          iVar6 = memcmp(pcVar5,DAT_300fe748,3);
          bVar12 = iVar6 == 0;
          if (!bVar12) {
            iVar6 = memcmp(pcVar5,DAT_300fe744,2);
            bVar12 = iVar6 == 0;
          }
          if (bVar12) {
            iVar10 = 0;
          }
        }
        if (param_2 != 0) {
          pcVar5 = pcVar9;
        }
        uVar11 = DAT_300fe74c;
        if (iVar10 == 0) {
          uVar11 = DAT_300fe740;
        }
        FUN_300fdd1c(pcVar5,uVar8 + 1,iVar2,0,uVar11);
        iVar4 = lstNext(iVar4);
        iVar2 = iVar2 + 1;
      }
      shellPrint(0,DAT_300fe728);
      puVar7 = (undefined4 *)__stdout();
      fflush((FILE *)*puVar7);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * viLedLibInit @ 0x30112EA8  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30112EA8
 * Данные: DAT_30113148, DAT_3011314c
 * ---------------------------------------------------------------- */
undefined4 viLedLibInit(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = DAT_30113148;
  *(undefined4 *)(param_1 + 8) = DAT_3011314c;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30112ec0 @ 0x30112EC0  (примерный размер ~4412 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 19
 * Вызывает: bzero, free, ioctl, ledBeep, ledComplete, ledHistFind, ledPreempt, ledPreemptSet, ledRedraw, malloc, memcmp, memmove, memset, read
 *           ...
 * Константы: 0xFFFFFFFF, 0x30112EC0, 0xFFFFFFBE, 0x30113144
 * Данные: DAT_30113150, DAT_30113154, DAT_30113158, DAT_30113fc0, DAT_30113fe0, DAT_30113fe8, DAT_30113fec, DAT_30113ff0
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

size_t FUN_30112ec0(uint *param_1,char *param_2,size_t param_3)

{
  byte bVar1;
  int iVar2;
  ssize_t sVar3;
  char *__dest;
  size_t sVar4;
  char *__src;
  uint uVar5;
  char *pcVar6;
  bool bVar7;
  byte local_160 [4];
  uint local_15c [2];
  char *local_154;
  char *local_150;
  undefined1 auStack_14c [4];
  void *local_148;
  char *local_144;
  char *local_140;
  uint local_13c;
  uint local_138;
  int local_134;
  fd_set afStack_128 [2];
  
  local_134 = 0;
  local_140 = (char *)0x0;
  local_15c[0] = 0;
  local_13c = 0;
  local_15c[1] = 0;
  local_160[0] = 0;
  local_138 = ioctl(*param_1,0x13,0);
  if ((local_138 & 0x40) == 0) {
    local_13c = read(*param_1,param_2,param_3);
  }
  else {
    ioctl(*param_1,3,local_138 & 0xffffffbe);
    local_148 = (void *)param_1[4];
    if (local_148 != (void *)0x0) {
      param_1[4] = 0;
      free(local_148);
    }
    sVar4 = param_3 * 5 + 6;
    local_148 = malloc(sVar4);
    param_1[4] = (uint)local_148;
    if (local_148 == (void *)0x0) {
      ioctl(*param_1,3,local_138);
      local_13c = 0xffffffff;
    }
    else {
      memset(local_148,0,sVar4);
      __src = (char *)((int)local_148 + 1);
      local_144 = __src + param_3 + 1;
      __dest = local_144 + param_3 + 1;
      local_154 = __dest + param_3 + 1;
      local_150 = local_154 + param_3 + 1;
      *param_2 = '\0';
      param_1[7] = 0;
      ledPreemptSet(auStack_14c,0);
LAB_30112ffc:
      do {
        while( true ) {
          do {
            ledRedraw(param_1[1],local_144,local_13c,__src,local_15c);
            local_13c = local_15c[0];
            strcpy(local_144,__src);
            local_160[0] = 0;
            bzero(afStack_128,0x100);
            uVar5 = *param_1;
            afStack_128[0].fds_bits[uVar5 >> 5] =
                 afStack_128[0].fds_bits[uVar5 >> 5] | 1 << (uVar5 & 0x1f);
            if (param_1[10] == 0) {
              iVar2 = 1;
            }
            else {
              iVar2 = select(uVar5 + 1,afStack_128,(fd_set *)0x0,(fd_set *)0x0,
                             (timeval *)(param_1 + 10));
            }
            if ((iVar2 == 0) || (sVar3 = read(*param_1,local_160,1), sVar3 < 1)) goto LAB_30113ce4;
          } while (local_160[0] == 0);
          uVar5 = ledPreempt(auStack_14c,local_160[0],__src,local_15c,local_15c + 1,param_1);
          if (uVar5 != 0xffffffff) break;
LAB_30113eb8:
          ledBeep(param_1[1]);
        }
      } while (uVar5 == 0);
      if (param_1[7] != 0) {
        if (local_160[0] == *DAT_30113150) {
          local_160[0] = 0x68;
        }
        bVar7 = (uint)*DAT_30113154 == (uint)local_160[0];
        if (!bVar7) {
          uVar5 = local_160[0] - 4;
          if (uVar5 < 0x7b) {
                    /* WARNING: Could not recover jumptable at 0x30113144. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            sVar4 = (**(code **)(DAT_30113158 + uVar5 * 4))();
            return sVar4;
          }
          goto LAB_30113eb8;
        }
        param_1[7] = 0;
LAB_30113d2c:
        if (bVar7) {
          uVar5 = 0;
        }
        if (!bVar7) {
          if (uVar5 == 10) {
            if (local_140 == (char *)0x0) {
              local_13c = strlen(__src);
              if (local_13c != 0xffffffff) {
                write(param_1[1],DAT_30113fe0,1);
              }
              goto LAB_30113f78;
            }
          }
          else {
            if ((int)uVar5 < 0xb) {
              if (uVar5 == 4) {
                strcpy(__dest,__src);
                iVar2 = ledComplete(param_1,__src,param_3,local_15c,4);
                if (iVar2 != 0) goto LAB_30113eb8;
                while( true ) {
                  bVar1 = *(byte *)(*DAT_30113fc0 + (uint)(byte)__src[local_15c[0]]);
                  if ((((bVar1 & 3) == 0) && ((bVar1 & 4) == 0)) &&
                     ((byte)__src[local_15c[0]] != 0x5f)) break;
                  local_15c[0] = local_15c[0] + 1;
                }
              }
              else {
                if (uVar5 == 9) goto LAB_30113e5c;
LAB_30113efc:
                if ((local_134 == 0) || (param_3 <= local_15c[0])) {
                  sVar4 = strlen(__src);
                  if (sVar4 < param_3) {
                    pcVar6 = __src + local_15c[0];
                    sVar4 = strlen(pcVar6);
                    memmove(pcVar6 + 1,pcVar6,sVar4 + 1);
                    goto LAB_30113f44;
                  }
                  ledBeep(param_1[1]);
                }
                else {
LAB_30113f44:
                  __src[local_15c[0]] = (char)uVar5;
                }
                if (local_15c[0] < param_3) {
                  iVar2 = 1;
                  goto LAB_30113f68;
                }
              }
              goto LAB_30112ffc;
            }
            if (uVar5 == 0x17) {
LAB_30113e5c:
              strcpy(__dest,__src);
              iVar2 = ledComplete(param_1,__src,param_3,local_15c,uVar5);
              if (iVar2 != 0) goto LAB_30113eb8;
              goto LAB_30112ffc;
            }
            if (uVar5 != 0x1b) goto LAB_30113efc;
            local_134 = 0;
            if (local_140 == (char *)0x0) {
              param_1[7] = 1;
              if (local_15c[0] != 0) {
                local_15c[0] = local_15c[0] - 1;
              }
              goto LAB_30112ffc;
            }
          }
          iVar2 = memcmp(__src,DAT_30113ff4,2);
          bVar7 = iVar2 == 0;
          if (!bVar7) {
            iVar2 = memcmp(__src,DAT_30113ff8,2);
            bVar7 = iVar2 == 0;
          }
          pcVar6 = local_150;
          local_140 = __src;
          if (bVar7) {
            local_140 = local_150;
            pcVar6 = __src;
          }
          strcpy(pcVar6,local_140);
          iVar2 = ledHistFind(param_1,local_150,__src,param_3);
          if (iVar2 == 0) {
            *__src = '\0';
            ledBeep(param_1[1]);
          }
          local_15c[0] = 0;
          local_140 = (char *)0x0;
          param_1[7] = 1;
          goto LAB_30112ffc;
        }
        *__src = (char)uVar5;
        local_15c[0] = uVar5;
        goto LAB_30112ffc;
      }
      uVar5 = (uint)local_160[0];
      if ((*DAT_30113fe8 != uVar5) || (local_15c[0] != 0)) {
        if (*DAT_30113fec != uVar5) {
          bVar7 = *DAT_30113ff0 == uVar5;
          goto LAB_30113d2c;
        }
        if (local_15c[0] != 0) {
          strcpy(__src + local_15c[0] + -1,__src + local_15c[0]);
          iVar2 = -1;
LAB_30113f68:
          local_15c[0] = local_15c[0] + iVar2;
        }
        goto LAB_30112ffc;
      }
LAB_30113ce4:
      local_13c = 0xffffffff;
LAB_30113f78:
      strncpy(param_2,__src,param_3);
      ioctl(*param_1,3,local_138);
      param_1[4] = 0;
      free(local_148);
    }
  }
  return local_13c;
}

/* ----------------------------------------------------------------
 * bh @ 0x301146F4  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_30114598, shellOutputLock, shellOutputUnlock
 * Константы: 0x301146F4
 * Данные: DAT_30115540
 * ---------------------------------------------------------------- */
undefined4
bh(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  shellOutputLock(0);
  uVar1 = FUN_30114598(param_1,param_3,param_4,0,0,param_5,1,param_2,DAT_30115540);
  shellOutputUnlock(0);
  return uVar1;
}

/* ----------------------------------------------------------------
 * bd @ 0x30114760  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: printErr, taskIdFigure, taskName
 * Константы: 0xFFFFFFFF, 0x30114760
 * Данные: DAT_30114fd0, DAT_30115410, DAT_30115698, DAT_3011569c, DAT_301156a0, DAT_301156a4, DAT_301156a8
 * ---------------------------------------------------------------- */
undefined4 bd(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_24 [4];
  int *local_14;
  undefined4 local_10;
  
  iVar3 = 0;
  if ((param_2 == 0) || (iVar3 = taskIdFigure(param_2), iVar3 != -1)) {
    local_24[1] = 1;
    local_24[2] = 1;
    local_14 = local_24;
    local_24[3] = *DAT_30114fd0;
    local_24[0] = iVar3;
    local_10 = param_1;
    iVar2 = (**(code **)(DAT_3011569c + 8))(1,local_24[3],local_14,param_1);
    if (iVar2 == -1) {
      printErr(DAT_301156a0,DAT_30115698,param_1);
      if (iVar3 == 0) {
        printErr(DAT_301156a4);
      }
      else {
        uVar1 = taskName(iVar3);
        printErr(DAT_301156a8,iVar3,uVar1);
      }
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    printErr(*DAT_30115410,DAT_30115698);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * bdall @ 0x3011483C  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: printErr, taskIdFigure
 * Константы: 0xFFFFFFFF, 0x3011483C
 * Данные: DAT_30114fd0, DAT_30115410, DAT_3011569c, DAT_301156ac
 * ---------------------------------------------------------------- */
undefined4 bdall(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  code *pcVar3;
  int local_2c [4];
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_2c[0] = 0;
  if ((param_1 == 0) || (local_2c[0] = taskIdFigure(), local_2c[0] != -1)) {
    local_2c[1] = 1;
    if (local_2c[0] != 0) {
      local_2c[2] = 1;
      local_8 = 0;
      uVar1 = *DAT_30114fd0;
      piVar2 = local_2c;
      local_18 = 0;
      pcVar3 = *(code **)(DAT_3011569c + 8);
      local_2c[3] = uVar1;
      local_1c = piVar2;
    }
    else {
      local_14 = 0;
      uVar1 = *DAT_30114fd0;
      piVar2 = (int *)0xffffffff;
      local_c = 0xffffffff;
      pcVar3 = *(code **)(DAT_3011569c + 8);
      local_10 = uVar1;
    }
    (*pcVar3)(local_2c[0] != 0,uVar1,piVar2,local_8);
    uVar1 = 0;
  }
  else {
    printErr(*DAT_30115410,DAT_301156ac);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_301148fc @ 0x301148FC  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: printErr, taskIdSelf, taskName, taskTcb
 * Вызывают: FUN_30114978
 * Константы: 0xFFFFFFFF, 0x301148FC
 * Данные: DAT_30115824, DAT_30115828
 * ---------------------------------------------------------------- */
undefined4 FUN_301148fc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    param_1 = taskIdSelf();
  }
  iVar1 = taskTcb(param_1);
  if (iVar1 == 0) {
    printErr(DAT_30115824,param_2,param_1);
    return 0xffffffff;
  }
  if ((*(uint *)(iVar1 + 0x98) & 2) != 0) {
    uVar2 = taskName(param_1);
    printErr(DAT_30115828,param_2,param_1,uVar2);
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30114978 @ 0x30114978  (примерный размер ~192 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 7
 * Вызывает: FUN_301148fc, printErr, shellTaskIdDefault, taskIdFigure, taskIdSelf, taskIdVerify, taskIsStopped
 * Вызывают: FUN_30114d7c, FUN_30114e1c, cret, so
 * Константы: 0xFFFFFFFF, 0x30114978
 * Данные: DAT_30114fc8, DAT_30115410, DAT_3011582c
 * ---------------------------------------------------------------- */
undefined4 FUN_30114978(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = taskIdFigure();
  if (iVar1 == -1) {
    printErr(*DAT_30115410,param_2);
    return 0xffffffff;
  }
  if (iVar1 == 0) {
    iVar1 = taskIdSelf();
  }
  iVar2 = taskIdVerify(iVar1);
  if (iVar2 == -1) {
    printErr(*DAT_30114fc8,param_2,iVar1);
    return 0xffffffff;
  }
  iVar2 = taskIsStopped(iVar1);
  if (iVar2 == 0) {
    printErr(DAT_3011582c,param_2,iVar1);
    return 0xffffffff;
  }
  iVar2 = FUN_301148fc(iVar1,param_2);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  uVar3 = shellTaskIdDefault(0,iVar1);
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_30114a38 @ 0x30114A38  (примерный размер ~836 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 13
 * Вызывает: _dbgFuncCallCheck, _dbgInstSizeGet, _dbgRetAdrsGet, _dbgTaskPCGet, _dbgTaskPCSet, printErr, shellDataAdd, shellDataRemove, taskIdVerify, taskRegsGet, vxdbgBpAdd, vxdbgCont, vxdbgStep
 * Вызывают: FUN_30114d7c, FUN_30114e1c, cret, so
 * Константы: 0xFFFFFFFF, 0x30114A38
 * Данные: DAT_30114fc8, DAT_30114fd0, DAT_30115114
 * ---------------------------------------------------------------- */
undefined4
FUN_30114a38(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 auStack_60 [72];
  
  local_6c = 0;
  iVar3 = taskIdVerify();
  if (iVar3 != 0) {
    printErr(*DAT_30114fc8,param_5,param_1);
    return 0xffffffff;
  }
  local_64 = 1;
  local_68 = param_1;
  if (param_2 == 0) {
    if (param_3 != 0) {
      _dbgTaskPCSet(param_1,param_3,param_4);
    }
    iVar3 = vxdbgCont(*DAT_30114fd0,&local_68);
    if (iVar3 != 0) {
      printErr(*DAT_30114fc8,param_5,param_1);
      return 0xffffffff;
    }
  }
  else if (param_2 == 1) {
    iVar3 = taskRegsGet(param_1,auStack_60);
    if (iVar3 != 0) {
      printErr(*DAT_30114fc8,param_5,param_1);
      return 0xffffffff;
    }
    iVar3 = _dbgRetAdrsGet(auStack_60);
    puVar1 = DAT_30114fd0;
    if (iVar3 == 0) {
      printErr(DAT_30115114,param_5);
      return 0xffffffff;
    }
    iVar4 = vxdbgBpAdd(*DAT_30114fd0,&local_68,0,6,0,0,iVar3,1,0,&local_6c);
    if (iVar4 == -1) {
      printErr(DAT_30115114,param_5,iVar3);
      return 0xffffffff;
    }
    iVar3 = vxdbgCont(*puVar1,&local_68);
    if (iVar3 != 0) {
      printErr(*DAT_30114fc8,param_5,param_1);
      return 0xffffffff;
    }
  }
  else if (param_2 == 2) {
    if (param_3 != 0) {
      _dbgTaskPCSet(param_1,param_3,param_4);
    }
    puVar1 = DAT_30114fc8;
    shellDataAdd(0,DAT_30114fc8[3],param_1,0);
    iVar3 = vxdbgStep(*DAT_30114fd0,&local_68,0,0);
    if (iVar3 != 0) {
      shellDataRemove(0,puVar1[3],0);
      printErr(*puVar1,param_5,param_1);
      return 0xffffffff;
    }
  }
  else if (param_2 == 3) {
    iVar3 = _dbgTaskPCGet(param_1);
    iVar4 = _dbgFuncCallCheck();
    if (iVar4 == 0) {
      uVar5 = FUN_30114a38(param_1,2,0,0,param_5);
      return uVar5;
    }
    iVar4 = _dbgInstSizeGet(iVar3);
    puVar2 = DAT_30114fd0;
    iVar4 = vxdbgBpAdd(*DAT_30114fd0,&local_68,0,6,0,0,iVar3 + iVar4 * 4,1,0,&local_6c);
    puVar1 = DAT_30114fc8;
    if (iVar4 == -1) {
      iVar4 = _dbgInstSizeGet(iVar3);
      printErr(DAT_30115114,param_5,iVar4 + iVar3);
      return 0xffffffff;
    }
    shellDataAdd(0,DAT_30114fc8[3],param_1,0);
    iVar3 = vxdbgCont(*puVar2,&local_68);
    if (iVar3 == -1) {
      shellDataRemove(0,puVar1[3],0);
      printErr(*puVar1,param_5,param_1);
      return 0xffffffff;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30114d7c @ 0x30114D7C  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30114978, FUN_30114a38
 * Константы: 0xFFFFFFFF, 0x30114D7C
 * Данные: DAT_30115c5c
 * ---------------------------------------------------------------- */
undefined4 FUN_30114d7c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_30114978(param_1,DAT_30115c5c);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = FUN_30114a38(iVar1,0,param_2,param_3,DAT_30115c5c);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * cret @ 0x30114DD0  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30114978, FUN_30114a38
 * Константы: 0xFFFFFFFF, 0x30114DD0
 * Данные: DAT_30115c60
 * ---------------------------------------------------------------- */
undefined4 cret(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_30114978(param_1,DAT_30115c60);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = FUN_30114a38(iVar1,1,0,0,DAT_30115c60);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30114e1c @ 0x30114E1C  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30114978, FUN_30114a38
 * Константы: 0xFFFFFFFF, 0x30114E1C
 * Данные: DAT_30115c64
 * ---------------------------------------------------------------- */
undefined4 FUN_30114e1c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_30114978(param_1,DAT_30115c64);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = FUN_30114a38(iVar1,2,param_2,param_3,DAT_30115c64);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * so @ 0x30114E70  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30114978, FUN_30114a38
 * Константы: 0x30114E70
 * Данные: DAT_30115d14
 * ---------------------------------------------------------------- */
void so(long param_1)

{
  int iVar1;
  
  iVar1 = FUN_30114978(param_1,DAT_30115d14);
  if (iVar1 != -1) {
    FUN_30114a38(iVar1,3,0,0,DAT_30115d14);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30114ebc @ 0x30114EBC  (примерный размер ~536 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 11
 * Вызывает: cplusDemangle, free, ioTaskStdSet, printErr, printf, shellDataAdd, shellDataRemove, shellInOutUse, shellPrintErr, symByValueAndTypeFind, taskTcb
 * Вызывают: FUN_30115680, dbgDisassemble
 * Константы: 0x30114EBC
 * Данные: DAT_30114fc8, DAT_30115d18, DAT_30115d1c, DAT_30115e08, DAT_30115ee0
 * ---------------------------------------------------------------- */
int FUN_30114ebc(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStack_140 [4];
  int local_13c;
  void *local_138;
  undefined4 local_134;
  undefined4 local_130;
  int local_12c;
  undefined1 auStack_128 [260];
  
  piVar1 = DAT_30115d18;
  uVar5 = 0;
  local_134 = 0;
  local_130 = 0;
  if (*DAT_30115d18 == 0) {
    if (param_1 == -1) {
      printErr(*DAT_30115d1c,param_5);
    }
    else {
      shellPrintErr(param_1,*DAT_30115d1c,param_5);
    }
  }
  else {
    local_13c = DAT_30114fc8;
    if (param_1 != -1) {
      iVar3 = taskTcb(0);
      local_134 = *(undefined4 *)(iVar3 + 0x100);
      local_130 = *(undefined4 *)(iVar3 + 0x104);
      uVar5 = *(undefined4 *)(iVar3 + 0x108);
      shellInOutUse(param_1);
      shellDataAdd(param_1,*(undefined4 *)(local_13c + 0x18),param_4,0);
    }
    *(int *)(local_13c + 0x10) = param_4;
    uVar2 = DAT_30115e08;
    if (0 < param_3) {
      do {
        local_138 = (void *)0x0;
        if (((param_4 != 0) &&
            (iVar3 = symByValueAndTypeFind(param_4,param_2,&local_138,&local_12c,auStack_140,0,0),
            iVar3 == 0)) && (local_12c == param_2)) {
          uVar4 = cplusDemangle(local_138,auStack_128,0x100);
          printf(DAT_30115ee0,uVar4);
        }
        free(local_138);
        iVar3 = (*(code *)*piVar1)(param_2,param_2,uVar2,0,0);
        param_2 = param_2 + iVar3 * 4;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    if (param_1 != -1) {
      shellDataRemove(param_1,*(undefined4 *)(local_13c + 0x18),0);
      ioTaskStdSet(0,0,local_134);
      ioTaskStdSet(0,1,local_130);
      ioTaskStdSet(0,2,uVar5);
    }
    *(undefined4 *)(local_13c + 0x10) = 0;
  }
  return param_2;
}

/* ----------------------------------------------------------------
 * FUN_301150d4 @ 0x301150D4  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: shellDataAdd, shellFirst, shellNext
 * Вызывают: FUN_30115590, FUN_30115680, dbgDisassemble
 * Константы: 0x301150D4
 * Данные: DAT_30116044
 * ---------------------------------------------------------------- */
void FUN_301150d4(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == -1) {
    iVar1 = shellFirst();
    if (iVar1 == 0) {
      return;
    }
    do {
      shellDataAdd(iVar1,*DAT_30116044,param_2,0);
      iVar1 = shellNext(iVar1);
    } while (iVar1 != 0);
  }
  else {
    shellDataAdd(param_1,*DAT_30116044,param_2,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * tt @ 0x30115510  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: dbgTaskTraceCoreRtn, printErr, taskIdFigure
 * Константы: 0x30115510, 0xFFFFFFFF
 * Данные: DAT_30116178, DAT_3011617c
 * ---------------------------------------------------------------- */
undefined4 tt(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = taskIdFigure();
  if (iVar1 == -1) {
    printErr(*DAT_3011617c);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = dbgTaskTraceCoreRtn(iVar1,DAT_30116178);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30115590 @ 0x30115590  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 13
 * Вызывает: FUN_3011423c, FUN_301150d4, memcmp, shellConfigValueGet, shellFirst, shellInternalSymTblFromTaskGet, shellNext, shellOutputLock, shellOutputUnlock, shellPrintErr, shellTaskIdDefault, taskName, taskTcb
 * Константы: 0x30115590
 * Данные: DAT_30116184, DAT_30116188, DAT_3011618c, DAT_30116190, DAT_30116194, DAT_30116198
 * ---------------------------------------------------------------- */
void FUN_30115590(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  void *__s1;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = taskTcb();
  if (iVar1 == 0) {
    return;
  }
  uVar2 = shellInternalSymTblFromTaskGet(param_1,param_3);
  for (iVar1 = shellFirst(); iVar1 != 0; iVar1 = shellNext(iVar1)) {
    __s1 = (void *)shellConfigValueGet(iVar1,DAT_30116184);
    if ((__s1 == (void *)0x0) || (iVar3 = memcmp(__s1,DAT_30116188,4), iVar3 != 0)) {
      shellTaskIdDefault(iVar1,param_1);
      shellOutputLock(iVar1);
      shellPrintErr(iVar1,DAT_3011618c);
      FUN_3011423c(iVar1,2,param_3,uVar2);
      uVar4 = taskName(param_1);
      shellPrintErr(iVar1,DAT_30116190,param_1,uVar4);
      shellPrintErr(iVar1,DAT_30116194);
      shellOutputUnlock(iVar1);
      FUN_301150d4(iVar1,param_2);
    }
  }
  *DAT_30116198 = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30115680 @ 0x30115680  (примерный размер ~620 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 14
 * Вызывает: FUN_30114ebc, FUN_301150d4, ioTaskStdSet, printErr, shellDataFirst, shellDataNext, shellDataRemove, shellInOutUse, shellInternalSymTblFromTaskGet, shellOutputLock, shellOutputUnlock, shellTaskIdDefault, taskRegsShow, taskTcb
 * Константы: 0x30115680
 * Данные: DAT_30116048, DAT_3011616c, DAT_30116198, DAT_3011619c, DAT_301161a0
 * ---------------------------------------------------------------- */
void FUN_30115680(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  code *pcVar9;
  int local_28;
  
  iVar2 = DAT_30116048;
  iVar1 = shellDataFirst(*(undefined4 *)(DAT_30116048 + 0xc),&local_28);
  if (iVar1 != 0) {
    do {
      if (local_28 == param_1) break;
      iVar1 = shellDataNext(*(undefined4 *)(iVar2 + 0xc),iVar1,&local_28);
    } while (iVar1 != 0);
    if (iVar1 != 0) {
      shellDataRemove(iVar1,*(undefined4 *)(iVar2 + 0xc),0);
    }
  }
  iVar2 = taskTcb(param_1);
  iVar7 = 0;
  uVar6 = 0;
  uVar4 = 0;
  uVar5 = 0;
  if (iVar2 != 0) {
    iVar3 = -1;
    if (iVar1 != 0) {
      iVar3 = iVar1;
    }
    shellTaskIdDefault(iVar3,param_1);
    if (iVar1 != 0) {
      iVar3 = taskTcb(0);
      uVar6 = *(undefined4 *)(iVar3 + 0x100);
      uVar4 = *(undefined4 *)(iVar3 + 0x104);
      uVar5 = *(undefined4 *)(iVar3 + 0x108);
      shellInOutUse(iVar1);
    }
    shellOutputLock(iVar1);
    taskRegsShow(param_1);
    piVar8 = *(int **)(iVar2 + 0xf0);
    if (piVar8 != (int *)0x0) {
      iVar2 = *piVar8;
      while (iVar2 != 0) {
        pcVar9 = *(code **)(piVar8[1] + 0x38);
        if ((pcVar9 != (code *)0x0) && (*(int *)(piVar8[1] + 0x4c) != 0)) {
          (*pcVar9)();
        }
        piVar8 = piVar8 + 3;
        iVar2 = *piVar8;
      }
    }
    if (iVar1 != 0) {
      ioTaskStdSet(0,0,uVar6);
      ioTaskStdSet(0,1,uVar4);
      ioTaskStdSet(0,2,uVar5);
    }
    uVar4 = shellInternalSymTblFromTaskGet(param_1,param_2);
    piVar8 = DAT_3011616c;
    if (*DAT_3011616c != 0) {
      iVar2 = taskTcb(param_1);
      iVar7 = (*(code *)*piVar8)(*(undefined4 *)(iVar2 + 0x94),0);
      if (iVar7 == 0) {
        printErr(DAT_3011619c,param_1);
        return;
      }
    }
    iVar2 = -1;
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
    FUN_30114ebc(iVar2,param_2,1,uVar4,DAT_301161a0);
    pcVar9 = (code *)*piVar8;
    if (pcVar9 != (code *)0x0) {
      (*pcVar9)(iVar7,0);
    }
    shellOutputUnlock(iVar1);
    iVar2 = -1;
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
    FUN_301150d4(iVar2,param_2);
    *DAT_30116198 = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_301158ec @ 0x301158EC  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: jobExcAdd, vxCpuIndexGet
 * Константы: 0x301158EC
 * Данные: DAT_30116180, DAT_30116198, DAT_301161a4, DAT_301161a8
 * ---------------------------------------------------------------- */
void FUN_301158ec(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = *param_1;
  *DAT_30116198 = 1;
  if ((param_5 == 0) ||
     ((*(int *)(param_5 + 0x1c) == *DAT_30116180 && ((*(byte *)(param_5 + 0x22) & 1) != 0)))) {
    param_4 = vxCpuIndexGet();
    uVar3 = 0;
    uVar1 = DAT_301161a4;
  }
  else {
    if ((*(byte *)(param_5 + 0x22) & 1) == 1) {
      return;
    }
    uVar3 = vxCpuIndexGet();
    uVar1 = DAT_301161a8;
  }
  jobExcAdd(uVar1,uVar2,*(undefined4 *)(param_3 + 0x3c),param_4,uVar3,0,0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_301159dc @ 0x301159DC  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: cplusDemangle, free, printf, shellDataGet, symByValueAndTypeFind
 * Константы: 0x301159DC
 * Данные: DAT_30116048, DAT_301161ac, DAT_301161b0
 * ---------------------------------------------------------------- */
void FUN_301159dc(int param_1)

{
  int iVar1;
  char *__format;
  undefined1 auStack_124 [4];
  int local_120;
  void *local_11c;
  int local_118;
  int local_114;
  undefined1 auStack_110 [260];
  
  local_120 = 0;
  local_11c = (void *)0x0;
  local_118 = DAT_30116048;
  iVar1 = shellDataGet(0,*(undefined4 *)(DAT_30116048 + 0x18),&local_120);
  if (iVar1 != 0) {
    local_120 = *(int *)(local_118 + 0x10);
  }
  __format = DAT_301161b0;
  if (((local_120 != 0) &&
      (iVar1 = symByValueAndTypeFind(local_120,param_1,&local_11c,&local_114,auStack_124,0,0),
      __format = DAT_301161b0, iVar1 == 0)) && (local_114 == param_1)) {
    param_1 = cplusDemangle(local_11c,auStack_110,0x100);
    __format = DAT_301161ac;
  }
  printf(__format,param_1);
  free(local_11c);
  return;
}

/* ----------------------------------------------------------------
 * dprintf @ 0x30116498  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: dbgDynPrintfCommonRtn, shellPrintErr, taskIdFigure
 * Константы: 0x30116498
 * Данные: DAT_30116644, DAT_30116648, DAT_3011664c
 * ---------------------------------------------------------------- */
int dprintf(int __fd,char *__fmt,...)

{
  undefined4 in_r2;
  int in_r3;
  int iVar1;
  
  iVar1 = 0;
  if ((__fmt == (char *)0x0) || (iVar1 = taskIdFigure(__fmt), iVar1 != -1)) {
    if ((__fd == 0) || (in_r3 == 0)) {
      shellPrintErr(0,DAT_3011664c,DAT_30116648);
      iVar1 = -1;
    }
    else {
      iVar1 = dbgDynPrintfCommonRtn(__fd,iVar1,1,0,0,in_r2,in_r3,&stack0x00000000,DAT_30116648);
    }
  }
  else {
    shellPrintErr(0,*DAT_30116644,DAT_30116648);
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * hdprintf @ 0x30116564  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: dbgDynPrintfCommonRtn, shellPrintErr, taskIdFigure
 * Константы: 0xFFFFFFFF, 0x30116564
 * Данные: DAT_30116644, DAT_3011664c, DAT_30116650
 * ---------------------------------------------------------------- */
undefined4 hdprintf(int param_1,undefined2 param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((param_3 == 0) || (iVar2 = taskIdFigure(param_3), iVar2 != -1)) {
    if ((param_1 == 0) || (param_5 == 0)) {
      shellPrintErr(0,DAT_3011664c,DAT_30116650);
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = dbgDynPrintfCommonRtn
                        (param_1,iVar2,1,1,param_2,param_4,param_5,&stack0x00000004,DAT_30116650);
    }
  }
  else {
    shellPrintErr(0,*DAT_30116644,DAT_30116650);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30116654 @ 0x30116654  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_301173b0, tagCheckStatementAdd
 * Константы: 0x30116654
 * Данные: DAT_301175d8
 * ---------------------------------------------------------------- */
byte * FUN_30116654(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  
  pbVar2 = param_1 + 1;
  if (((*(byte *)(*DAT_301175d8 + (uint)*param_1) & 3) == 0) && (*param_1 != 0x5f)) {
    return (byte *)0x0;
  }
  bVar1 = *pbVar2;
  while( true ) {
    uVar3 = (uint)bVar1;
    if (uVar3 == 0) {
      return pbVar2;
    }
    if (((*(byte *)(*DAT_301175d8 + uVar3) & 7) == 0) && (uVar3 != 0x5f)) break;
    pbVar2 = pbVar2 + 1;
    bVar1 = *pbVar2;
  }
  return pbVar2;
}

/* ----------------------------------------------------------------
 * FUN_301166b0 @ 0x301166B0  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: malloc, strncpy
 * Вызывают: FUN_30116a88, FUN_30116cdc, FUN_30117d54
 * Константы: 0x301166B0
 * ---------------------------------------------------------------- */
char * FUN_301166b0(char *param_1,size_t param_2)

{
  char *__dest;
  
  __dest = (char *)malloc(param_2 + 1);
  if (__dest == (char *)0x0) {
    return (char *)0x0;
  }
  strncpy(__dest,param_1,param_2);
  __dest[param_2] = '\0';
  return __dest;
}

/* ----------------------------------------------------------------
 * FUN_301166fc @ 0x301166FC  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: strcmp
 * Вызывают: FUN_30116860, tagCheckModuleAdd
 * Константы: 0x301166FC
 * ---------------------------------------------------------------- */
undefined4 * FUN_301166fc(int *param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = *param_1;
  if (0 < iVar4) {
    puVar2 = (undefined4 *)(param_1[2] + -4);
    do {
      puVar2 = puVar2 + 1;
      puVar3 = (undefined4 *)*puVar2;
      iVar1 = strcmp((char *)*puVar3,param_2);
      if (iVar1 == 0) {
        return puVar3;
      }
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return (undefined4 *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_30116750 @ 0x30116750  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: malloc, realloc
 * Вызывают: FUN_30116860, FUN_30116d70, tagCheckModuleAdd
 * Константы: 0x30116750
 * ---------------------------------------------------------------- */
undefined4 FUN_30116750(int *param_1,undefined4 param_2)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  if (*param_1 == iVar2) {
    if (iVar2 == 0) {
      param_1[1] = 1;
      pvVar1 = malloc(4);
    }
    else {
      param_1[1] = iVar2 << 1;
      pvVar1 = realloc((void *)param_1[2],iVar2 << 3);
    }
    param_1[2] = (int)pvVar1;
    if (pvVar1 == (void *)0x0) {
      return 1;
    }
  }
  iVar2 = *param_1;
  *(undefined4 *)(param_1[2] + iVar2 * 4) = param_2;
  *param_1 = iVar2 + 1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_301167d0 @ 0x301167D0  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: tagCheckModuleDel
 * Константы: 0x301167D0
 * ---------------------------------------------------------------- */
undefined4 FUN_301167d0(int *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *param_1;
  iVar5 = 0;
  if (0 < iVar4) {
    piVar3 = (int *)(param_1[2] + -4);
    iVar5 = iVar4;
    do {
      piVar3 = piVar3 + 1;
      if (*piVar3 == param_2) break;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar5 = iVar4 - iVar5;
  }
  if (iVar5 < iVar4) {
    iVar4 = iVar4 + -1;
    *param_1 = iVar4;
    if (iVar5 < iVar4) {
      puVar2 = (undefined4 *)(param_1[2] + iVar5 * 4);
      iVar4 = iVar4 - iVar5;
      do {
        iVar4 = iVar4 + -1;
        *puVar2 = puVar2[1];
        puVar2 = puVar2 + 1;
      } while (iVar4 != 0);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30116860 @ 0x30116860  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_301166fc, FUN_30116750
 * Вызывают: FUN_30117d54
 * Константы: 0x30116860
 * ---------------------------------------------------------------- */
undefined4 FUN_30116860(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_301166fc(param_1,*param_2);
  if (iVar1 != 0) {
    return 0;
  }
  uVar2 = FUN_30116750(param_1,param_2);
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30116894 @ 0x30116894  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: memcmp, strlen
 * Вызывают: FUN_30116a88
 * Константы: 0x30116894
 * ---------------------------------------------------------------- */
undefined4 * FUN_30116894(int *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *__s;
  int iVar5;
  
  iVar5 = *param_1;
  if (0 < iVar5) {
    puVar3 = (undefined4 *)(param_1[2] + -4);
    do {
      puVar3 = puVar3 + 1;
      puVar4 = (undefined4 *)*puVar3;
      __s = (char *)*puVar4;
      sVar1 = strlen(__s);
      if ((sVar1 == param_3) && (iVar2 = memcmp(__s,param_2,param_3), iVar2 == 0)) {
        return puVar4;
      }
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return (undefined4 *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_30116908 @ 0x30116908  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: malloc, realloc
 * Вызывают: FUN_30116a88, FUN_30116fcc
 * Константы: 0x30116908
 * ---------------------------------------------------------------- */
undefined4 FUN_30116908(int *param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  if (*param_1 == iVar2) {
    if (iVar2 == 0) {
      param_1[1] = 1;
      pvVar1 = malloc(4);
    }
    else {
      param_1[1] = iVar2 << 1;
      pvVar1 = realloc((void *)param_1[2],iVar2 << 3);
    }
    param_1[2] = (int)pvVar1;
    if (pvVar1 == (void *)0x0) {
      return 1;
    }
  }
  iVar2 = *param_1;
  *(int *)(param_1[2] + iVar2 * 4) = param_2;
  *param_1 = iVar2 + 1;
  *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30116994 @ 0x30116994  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: __assert
 * Вызывают: FUN_30116d70, FUN_301173b0, FUN_30117bcc
 * Константы: 0x30116994
 * Данные: DAT_30117730
 * ---------------------------------------------------------------- */
void FUN_30116994(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  char *__file;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  
  __file = (char *)*param_1;
  iVar3 = 0;
  if (0 < (int)__file) {
    piVar2 = (int *)(param_1[2] + -4);
    pcVar4 = __file;
    do {
      piVar2 = piVar2 + 1;
      if (*piVar2 == param_2) break;
      pcVar4 = pcVar4 + -1;
    } while (pcVar4 != (char *)0x0);
    iVar3 = (int)__file - (int)pcVar4;
  }
  if ((int)__file <= iVar3) {
    return;
  }
  pcVar4 = __file + -1;
  *param_1 = pcVar4;
  if (iVar3 < (int)pcVar4) {
    puVar1 = (undefined4 *)(param_1[2] + iVar3 * 4);
    iVar3 = (int)pcVar4 - iVar3;
    do {
      iVar3 = iVar3 + -1;
      *puVar1 = puVar1[1];
      puVar1 = puVar1 + 1;
    } while (iVar3 != 0);
  }
  if (*(int *)(param_2 + 4) < 1) {
    __assert(DAT_30117730,__file,(int)pcVar4);
  }
  *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + -1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30116a34 @ 0x30116A34  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 2
 * Вызывает: __assert, free
 * Вызывают: FUN_30116a88, FUN_30116d70, FUN_301173b0, FUN_30117bcc, tagCheckModuleDel
 * Константы: 0x30116A34
 * Данные: DAT_30117734
 * ---------------------------------------------------------------- */
void FUN_30116a34(undefined4 *param_1,char *param_2,int param_3)

{
  if (param_1[2] != 0) {
    __assert(DAT_30117734,param_2,param_3);
  }
  if (param_1[1] != 0) {
    return;
  }
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
  }
  if ((void *)param_1[4] != (void *)0x0) {
    free((void *)param_1[4]);
  }
  free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30116a88 @ 0x30116A88  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_301166b0, FUN_30116894, FUN_30116908, FUN_30116a34, malloc, memset
 * Вызывают: FUN_30116d70, FUN_301173b0
 * Константы: 0x30116A88
 * ---------------------------------------------------------------- */
int * FUN_30116a88(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *__s;
  int iVar1;
  
  __s = (int *)FUN_30116894();
  if (__s == (int *)0x0) {
    __s = (int *)malloc(0x14);
    if (__s == (int *)0x0) {
      return (int *)0x0;
    }
    memset(__s,0,0x14);
    iVar1 = FUN_301166b0(param_2,param_3);
    *__s = iVar1;
    if ((iVar1 == 0) || (iVar1 = FUN_30116908(param_1,__s), iVar1 != 0)) {
      FUN_30116a34(__s);
      return (int *)0x0;
    }
  }
  return __s;
}

/* ----------------------------------------------------------------
 * FUN_30116b1c @ 0x30116B1C  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: memcmp, strlen
 * Вызывают: FUN_30116cdc
 * Константы: 0x30116B1C
 * ---------------------------------------------------------------- */
undefined4 * FUN_30116b1c(int param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *__s;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 8);
  if (0 < iVar5) {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x10) + -4);
    do {
      puVar3 = puVar3 + 1;
      puVar4 = (undefined4 *)*puVar3;
      __s = (char *)*puVar4;
      sVar1 = strlen(__s);
      if ((sVar1 == param_3) && (iVar2 = memcmp(__s,param_2,param_3), iVar2 == 0)) {
        return puVar4;
      }
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return (undefined4 *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_30116b90 @ 0x30116B90  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: malloc, realloc
 * Вызывают: FUN_30116cdc
 * Константы: 0x30116B90
 * ---------------------------------------------------------------- */
undefined4 FUN_30116b90(int param_1,undefined4 param_2)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 8) == iVar2) {
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0xc) = 1;
      pvVar1 = malloc(4);
    }
    else {
      *(int *)(param_1 + 0xc) = iVar2 << 1;
      pvVar1 = realloc(*(void **)(param_1 + 0x10),iVar2 << 3);
    }
    *(void **)(param_1 + 0x10) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      return 1;
    }
  }
  iVar2 = *(int *)(param_1 + 8);
  *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar2 * 4) = param_2;
  *(int *)(param_1 + 8) = iVar2 + 1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30116c10 @ 0x30116C10  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30116d70
 * Константы: 0x30116C10
 * ---------------------------------------------------------------- */
void FUN_30116c10(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 8);
  iVar4 = 0;
  if (0 < iVar3) {
    piVar2 = (int *)(*(int *)(param_1 + 0x10) + -4);
    iVar4 = iVar3;
    do {
      piVar2 = piVar2 + 1;
      if (*piVar2 == param_2) break;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar4 = iVar3 - iVar4;
  }
  if (iVar4 < iVar3) {
    iVar3 = iVar3 + -1;
    *(int *)(param_1 + 8) = iVar3;
    if (iVar4 < iVar3) {
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0x10) + iVar4 * 4);
      iVar3 = iVar3 - iVar4;
      do {
        iVar3 = iVar3 + -1;
        *puVar1 = puVar1[1];
        puVar1 = puVar1 + 1;
      } while (iVar3 != 0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30116c94 @ 0x30116C94  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: __assert, free
 * Вызывают: FUN_30116cdc, FUN_30116d70, tagCheckModuleDel
 * Константы: 0x30116C94
 * Данные: DAT_30117738
 * ---------------------------------------------------------------- */
void FUN_30116c94(undefined4 *param_1,char *param_2,int param_3)

{
  if (param_1[1] != 0) {
    __assert(DAT_30117738,param_2,param_3);
  }
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
  }
  if ((void *)param_1[3] != (void *)0x0) {
    free((void *)param_1[3]);
  }
  free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30116cdc @ 0x30116CDC  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_301166b0, FUN_30116b1c, FUN_30116b90, FUN_30116c94, malloc, memset
 * Вызывают: FUN_30116d70
 * Константы: 0x30116CDC
 * ---------------------------------------------------------------- */
int * FUN_30116cdc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *__s;
  int iVar1;
  
  __s = (int *)FUN_30116b1c();
  if (__s == (int *)0x0) {
    __s = (int *)malloc(0x10);
    if (__s == (int *)0x0) {
      return (int *)0x0;
    }
    memset(__s,0,0x10);
    iVar1 = FUN_301166b0(param_2,param_3);
    *__s = iVar1;
    if ((iVar1 == 0) || (iVar1 = FUN_30116b90(param_1,__s), iVar1 != 0)) {
      FUN_30116c94(__s);
      return (int *)0x0;
    }
  }
  return __s;
}

/* ----------------------------------------------------------------
 * FUN_30116d70 @ 0x30116D70  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_30116750, FUN_30116994, FUN_30116a34, FUN_30116a88, FUN_30116c10, FUN_30116c94, FUN_30116cdc
 * Вызывают: tagCheckStatementAdd
 * Константы: 0x30116D70
 * Данные: DAT_3011773c
 * ---------------------------------------------------------------- */
void FUN_30116d70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = DAT_3011773c;
  iVar2 = FUN_30116a88(DAT_3011773c);
  if (iVar2 == 0) {
    return;
  }
  iVar3 = FUN_30116cdc(iVar2,param_4,param_5);
  if (iVar3 != 0) {
    iVar4 = FUN_30116750(iVar3 + 4,param_1);
    if (iVar4 == 0) {
      return;
    }
    if (*(int *)(iVar3 + 4) != 0) {
      return;
    }
    FUN_30116c10(iVar2,iVar3);
    FUN_30116c94(iVar3);
  }
  if (*(int *)(iVar2 + 8) != 0) {
    return;
  }
  FUN_30116994(uVar1,iVar2);
  FUN_30116a34(iVar2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30116e08 @ 0x30116E08  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: __errno, strtol
 * Вызывают: FUN_3011764c
 * Константы: 0x30116E08
 * Данные: DAT_301175d8
 * ---------------------------------------------------------------- */
bool FUN_30116e08(int *param_1,long *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  long lVar3;
  int *piVar4;
  uint uVar5;
  byte *local_10;
  
  if (*param_1 == 0) {
    bVar1 = false;
    *param_2 = param_1[1];
  }
  else {
    if (*param_1 == 1) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 0;
      lVar3 = strtol((char *)param_1[1],(char **)&local_10,0);
      *param_2 = lVar3;
      piVar4 = (int *)__errno();
      if ((*piVar4 == 0) && ((byte *)param_1[1] < local_10)) {
        uVar5 = (uint)*local_10;
        if (uVar5 != 0) {
          do {
            if ((*(byte *)(*DAT_301175d8 + uVar5) & 0x28) == 0) break;
            uVar5 = (uint)local_10[1];
            local_10 = local_10 + 1;
          } while (uVar5 != 0);
        }
        return uVar5 != 0;
      }
    }
    bVar1 = true;
  }
  return bVar1;
}

/* ----------------------------------------------------------------
 * FUN_30116ed4 @ 0x30116ED4  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __assert, sprintf
 * Константы: 0x30116ED4
 * Данные: DAT_30117740, DAT_30117744
 * ---------------------------------------------------------------- */
char * FUN_30116ed4(int *param_1,char *param_2,int param_3)

{
  if (*param_1 == 0) {
    sprintf(param_2,DAT_30117740,param_1[1]);
    return param_2;
  }
  if (*param_1 != 1) {
    __assert(DAT_30117744,param_2,param_3);
  }
  return (char *)param_1[1];
}

/* ----------------------------------------------------------------
 * FUN_30116f1c @ 0x30116F1C  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 2
 * Вызывает: malloc, realloc
 * Вызывают: FUN_30116f84, FUN_30116fcc, FUN_3011706c, FUN_301170c0
 * Константы: 0x30116F1C
 * ---------------------------------------------------------------- */
bool FUN_30116f1c(int *param_1)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  if (*param_1 != iVar2) {
    return false;
  }
  if (iVar2 == 0) {
    param_1[1] = 1;
    pvVar1 = malloc(8);
  }
  else {
    param_1[1] = iVar2 << 1;
    pvVar1 = realloc((void *)param_1[2],iVar2 << 4);
  }
  param_1[2] = (int)pvVar1;
  return pvVar1 == (void *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_30116f84 @ 0x30116F84  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30116f1c
 * Вызывают: FUN_301173b0
 * Константы: 0x30116F84
 * ---------------------------------------------------------------- */
undefined4 FUN_30116f84(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_30116f1c();
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = *param_1;
  puVar2 = (undefined4 *)(param_1[2] + iVar1 * 8);
  puVar2[1] = param_2;
  *puVar2 = 1;
  *param_1 = iVar1 + 1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30116fcc @ 0x30116FCC  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30116908, FUN_30116f1c
 * Вызывают: FUN_301173b0
 * Константы: 0x30116FCC
 * ---------------------------------------------------------------- */
undefined4 FUN_30116fcc(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = FUN_30116f1c();
  if (iVar1 != 0) {
    return 1;
  }
  iVar3 = param_1[3];
  iVar1 = 0;
  if (0 < iVar3) {
    piVar2 = (int *)(param_1[5] + -4);
    iVar1 = iVar3;
    do {
      piVar2 = piVar2 + 1;
      if (*piVar2 == param_2) break;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    iVar1 = iVar3 - iVar1;
  }
  if (iVar3 <= iVar1) {
    FUN_30116908(param_1 + 3,param_2);
  }
  *(int *)(param_1[2] + *param_1 * 8 + 4) = iVar1;
  iVar1 = *param_1;
  *(undefined4 *)(param_1[2] + iVar1 * 8) = 2;
  *param_1 = iVar1 + 1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3011706c @ 0x3011706C  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30116f1c
 * Вызывают: FUN_301173b0
 * Константы: 0x3011706C
 * ---------------------------------------------------------------- */
undefined4 FUN_3011706c(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_30116f1c();
  if (iVar1 != 0) {
    return 1;
  }
  *(undefined4 *)(param_1[2] + *param_1 * 8 + 4) = param_2;
  iVar1 = *param_1;
  *(undefined4 *)(param_1[2] + iVar1 * 8) = 0;
  *param_1 = iVar1 + 1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_301170c0 @ 0x301170C0  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: FUN_30116f1c
 * Вызывают: FUN_301170fc, FUN_301171c4, FUN_30117270, FUN_30117310, FUN_301173b0
 * Константы: 0x301170C0
 * ---------------------------------------------------------------- */
undefined4 FUN_301170c0(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_30116f1c();
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = *param_1;
  *(undefined4 *)(param_1[2] + iVar1 * 8) = param_2;
  *param_1 = iVar1 + 1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_301170fc @ 0x301170FC  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_301170c0, FUN_301173b0
 * Вызывают: FUN_301171c4
 * Константы: 0x301170FC
 * Данные: DAT_301175d8
 * ---------------------------------------------------------------- */
byte * FUN_301170fc(undefined4 param_1)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  pbVar1 = (byte *)FUN_301173b0();
  if (pbVar1 == (byte *)0x0) {
    return (byte *)0x0;
  }
  do {
    uVar2 = (uint)*pbVar1;
    if (uVar2 != 0) {
      do {
        if ((*(byte *)(*DAT_301175d8 + uVar2) & 0x28) == 0) break;
        pbVar1 = pbVar1 + 1;
        uVar2 = (uint)*pbVar1;
      } while (uVar2 != 0);
    }
    if (uVar2 == 0x3c) {
      pbVar4 = pbVar1 + 1;
      if (*pbVar4 == 0x3d) {
        pbVar4 = pbVar1 + 2;
        uVar3 = 5;
      }
      else {
        uVar3 = 4;
      }
    }
    else {
      if (uVar2 != 0x3e) {
        return pbVar1;
      }
      pbVar4 = pbVar1 + 1;
      if (*pbVar4 == 0x3d) {
        pbVar4 = pbVar1 + 2;
        uVar3 = 7;
      }
      else {
        uVar3 = 6;
      }
    }
    pbVar1 = (byte *)FUN_301173b0(param_1,pbVar4);
    if (pbVar1 == (byte *)0x0) {
      return (byte *)0x0;
    }
    FUN_301170c0(param_1,uVar3);
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_301171c4 @ 0x301171C4  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_301170c0, FUN_301170fc
 * Вызывают: FUN_30117270
 * Константы: 0x301171C4
 * Данные: DAT_301175d8
 * ---------------------------------------------------------------- */
byte * FUN_301171c4(undefined4 param_1)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 uVar3;
  
  pbVar1 = (byte *)FUN_301170fc();
  if (pbVar1 == (byte *)0x0) {
    return (byte *)0x0;
  }
  do {
    uVar2 = (uint)*pbVar1;
    if (uVar2 != 0) {
      do {
        if ((*(byte *)(*DAT_301175d8 + uVar2) & 0x28) == 0) break;
        pbVar1 = pbVar1 + 1;
        uVar2 = (uint)*pbVar1;
      } while (uVar2 != 0);
    }
    if (uVar2 == 0x3d) {
      uVar3 = 8;
    }
    else {
      if (uVar2 != 0x21) {
        return pbVar1;
      }
      uVar3 = 9;
    }
    if (pbVar1[1] != 0x3d) {
      return pbVar1;
    }
    pbVar1 = (byte *)FUN_301170fc(param_1,pbVar1 + 2);
    if (pbVar1 == (byte *)0x0) {
      return (byte *)0x0;
    }
    FUN_301170c0(param_1,uVar3);
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_30117270 @ 0x30117270  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_301170c0, FUN_301171c4
 * Вызывают: FUN_30117310
 * Константы: 0x30117270
 * Данные: DAT_301175d8
 * ---------------------------------------------------------------- */
byte * FUN_30117270(undefined4 param_1)

{
  byte *pbVar1;
  uint uVar2;
  
  pbVar1 = (byte *)FUN_301171c4();
  if (pbVar1 == (byte *)0x0) {
    return (byte *)0x0;
  }
  do {
    uVar2 = (uint)*pbVar1;
    if (uVar2 != 0) {
      do {
        if ((*(byte *)(*DAT_301175d8 + uVar2) & 0x28) == 0) break;
        pbVar1 = pbVar1 + 1;
        uVar2 = (uint)*pbVar1;
      } while (uVar2 != 0);
    }
    if ((uVar2 != 0x26) || (pbVar1[1] != 0x26)) {
      return pbVar1;
    }
    pbVar1 = (byte *)FUN_301171c4(param_1,pbVar1 + 2);
    if (pbVar1 == (byte *)0x0) {
      return (byte *)0x0;
    }
    FUN_301170c0(param_1,10);
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_30117310 @ 0x30117310  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: FUN_301170c0, FUN_30117270
 * Вызывают: FUN_301173b0, tagCheckStatementAdd
 * Константы: 0x30117310
 * Данные: DAT_301175d8
 * ---------------------------------------------------------------- */
byte * FUN_30117310(undefined4 param_1)

{
  byte *pbVar1;
  uint uVar2;
  
  pbVar1 = (byte *)FUN_30117270();
  if (pbVar1 == (byte *)0x0) {
    return (byte *)0x0;
  }
  do {
    uVar2 = (uint)*pbVar1;
    if (uVar2 != 0) {
      do {
        if ((*(byte *)(*DAT_301175d8 + uVar2) & 0x28) == 0) break;
        pbVar1 = pbVar1 + 1;
        uVar2 = (uint)*pbVar1;
      } while (uVar2 != 0);
    }
    if ((uVar2 != 0x7c) || (pbVar1[1] != 0x7c)) {
      return pbVar1;
    }
    pbVar1 = (byte *)FUN_30117270(param_1,pbVar1 + 2);
    if (pbVar1 == (byte *)0x0) {
      return (byte *)0x0;
    }
    FUN_301170c0(param_1,0xb);
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_301173b0 @ 0x301173B0  (примерный размер ~668 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 12
 * Вызывает: FUN_30116654, FUN_30116994, FUN_30116a34, FUN_30116a88, FUN_30116f84, FUN_30116fcc, FUN_3011706c, FUN_301170c0, FUN_30117310, __errno, malloc, strtol
 * Вызывают: FUN_301170fc
 * Константы: 0x301173B0
 * Данные: DAT_301175d8, DAT_3011773c
 * ---------------------------------------------------------------- */
byte * FUN_301173b0(undefined4 param_1,byte *param_2)

{
  undefined4 uVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 *puVar7;
  long lVar8;
  int *piVar9;
  byte bVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  byte *local_18;
  
  uVar13 = (uint)*param_2;
  if (uVar13 != 0) {
    do {
      if ((*(byte *)(*DAT_301175d8 + uVar13) & 0x28) == 0) break;
      param_2 = param_2 + 1;
      uVar13 = (uint)*param_2;
    } while (uVar13 != 0);
    if (uVar13 != 0) {
      if (uVar13 == 0x21) {
        local_18 = (byte *)FUN_301173b0(param_1,param_2 + 1);
        if (local_18 == (byte *)0x0) {
          return (byte *)0x0;
        }
        iVar2 = FUN_301170c0(param_1,3);
      }
      else {
        if (uVar13 == 0x28) {
          pbVar3 = (byte *)FUN_30117310(param_1,param_2 + 1);
          if (pbVar3 == (byte *)0x0) {
            return (byte *)0x0;
          }
          uVar13 = (uint)*pbVar3;
          if (uVar13 != 0) {
            do {
              if ((*(byte *)(*DAT_301175d8 + uVar13) & 0x28) == 0) break;
              pbVar3 = pbVar3 + 1;
              uVar13 = (uint)*pbVar3;
            } while (uVar13 != 0);
          }
          if (uVar13 != 0x29) {
            return (byte *)0x0;
          }
          return pbVar3;
        }
        if ((uVar13 == 0x22) || (uVar13 == 0x27)) {
          param_2 = param_2 + 1;
          pbVar3 = param_2;
          while (pbVar5 = pbVar3, uVar11 = (uint)*pbVar5, pbVar3 = pbVar5, uVar11 != 0) {
            if (uVar11 == uVar13) goto LAB_301174ec;
            pbVar3 = pbVar5 + 1;
            if (uVar11 == 0x5c) {
              uVar11 = (uint)*pbVar3;
              if (uVar11 == 0) break;
              pbVar3 = pbVar5 + 2;
            }
          }
          pbVar5 = pbVar3;
          if (uVar11 != uVar13) {
            return (byte *)0x0;
          }
LAB_301174ec:
          pbVar4 = (byte *)malloc((size_t)(pbVar5 + (1 - (int)param_2)));
          pbVar3 = pbVar4;
          if (pbVar4 == (byte *)0x0) {
            return (byte *)0x0;
          }
          while (param_2 < pbVar5) {
            bVar10 = *param_2;
            pbVar12 = param_2 + 1;
            if (bVar10 == 0x5c) {
              pbVar12 = param_2 + 2;
              bVar10 = param_2[1];
            }
            *pbVar3 = bVar10;
            pbVar3 = pbVar3 + 1;
            param_2 = pbVar12;
          }
          *pbVar3 = 0;
          iVar2 = FUN_30116f84(param_1,pbVar4);
          if (iVar2 != 0) {
            return (byte *)0x0;
          }
LAB_301175dc:
          return pbVar5 + 1;
        }
        if ((uVar13 == 0x24) && (param_2[1] == 0x28)) {
          param_2 = param_2 + 2;
          pbVar5 = (byte *)FUN_30116654(param_2);
          uVar1 = DAT_3011773c;
          if (pbVar5 == (byte *)0x0) {
            return (byte *)0x0;
          }
          if (*pbVar5 != 0x29) {
            return (byte *)0x0;
          }
          iVar2 = FUN_30116a88(DAT_3011773c,param_2,(int)pbVar5 - (int)param_2);
          if (iVar2 == 0) {
            return (byte *)0x0;
          }
          iVar6 = FUN_30116fcc(param_1,iVar2);
          if (iVar6 != 0) {
            if (*(int *)(iVar2 + 8) != 0) {
              return (byte *)0x0;
            }
            FUN_30116994(uVar1,iVar2);
            FUN_30116a34(iVar2);
            return (byte *)0x0;
          }
          goto LAB_301175dc;
        }
        puVar7 = (undefined4 *)__errno();
        *puVar7 = 0;
        lVar8 = strtol((char *)param_2,(char **)&local_18,0);
        piVar9 = (int *)__errno();
        if (*piVar9 != 0) {
          return (byte *)0x0;
        }
        if (local_18 <= param_2) {
          return (byte *)0x0;
        }
        iVar2 = FUN_3011706c(param_1,lVar8);
      }
      if (iVar2 == 0) {
        return local_18;
      }
    }
  }
  return (byte *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_3011764c @ 0x3011764C  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30116e08, strlen
 * Вызывают: tagCheckEvaluateAsserts
 * Константы: 0x3011764C
 * ---------------------------------------------------------------- */
undefined4 FUN_3011764c(int *param_1)

{
  int iVar1;
  size_t sVar2;
  uint uVar3;
  int local_10;
  
  if (*param_1 == 0) {
    param_1[1] = (uint)(param_1[1] != 0);
  }
  else {
    if (*param_1 != 1) {
      return 1;
    }
    iVar1 = FUN_30116e08(param_1,&local_10);
    if (iVar1 == 0) {
      uVar3 = (uint)(local_10 != 0);
    }
    else {
      sVar2 = strlen((char *)param_1[1]);
      if (sVar2 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
    }
    param_1[1] = uVar3;
    *param_1 = 0;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_301176e0 @ 0x301176E0  (примерный размер ~1204 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: __assert
 * Вызывают: tagCheckEvaluateAsserts
 * Константы: 0x301176E0, 0x3011772C
 * Данные: DAT_30117748, DAT_3011886c, DAT_30118870
 * ---------------------------------------------------------------- */
undefined4 FUN_301176e0(int *param_1,int *param_2)

{
  undefined4 uVar1;
  uint __line;
  
  if (*param_1 < 1) {
    uVar1 = 0;
  }
  else if (*param_2 < 100) {
    __line = *(uint *)param_1[2];
    if (__line < 0xc) {
                    /* WARNING: Could not recover jumptable at 0x3011772c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(DAT_30117748 + __line * 4))(param_1);
      return uVar1;
    }
    if (DAT_3011886c != 0) {
      __assert(DAT_30118870,(char *)param_2,__line);
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30117b94 @ 0x30117B94  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: malloc, memset
 * Вызывают: tagCheckStatementAdd
 * Константы: 0x30117B94
 * ---------------------------------------------------------------- */
void * FUN_30117b94(void)

{
  void *__s;
  
  __s = malloc(0x2c);
  if (__s == (void *)0x0) {
    return (void *)0x0;
  }
  memset(__s,0,0x2c);
  return __s;
}

/* ----------------------------------------------------------------
 * FUN_30117bcc @ 0x30117BCC  (примерный размер ~288 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 4
 * Вызывает: FUN_30116994, FUN_30116a34, __assert, free
 * Вызывают: FUN_30117d54, tagCheckModuleDel, tagCheckStatementAdd
 * Константы: 0x30117BCC
 * Данные: DAT_30118874
 * ---------------------------------------------------------------- */
void FUN_30117bcc(undefined4 *param_1,char *param_2,int param_3)

{
  void *__ptr;
  int iVar1;
  
  if (param_1[8] != 0) {
    __assert(DAT_30118874,param_2,param_3);
  }
  while (0 < (int)param_1[5]) {
    iVar1 = *(int *)(param_1[7] + param_1[5] * 4 + -4);
    FUN_30116994(param_1 + 5,iVar1);
    if (*(int *)(iVar1 + 8) == 0) {
      FUN_30116a34(iVar1);
    }
  }
  iVar1 = param_1[2];
  while (0 < iVar1) {
    iVar1 = param_1[4] + param_1[2] * 8;
    if ((*(int *)(iVar1 + -8) == 1) && (__ptr = *(void **)(iVar1 + -4), __ptr != (void *)0x0)) {
      free(__ptr);
    }
    iVar1 = param_1[2] + -1;
    param_1[2] = iVar1;
  }
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
  }
  if ((void *)param_1[7] != (void *)0x0) {
    free((void *)param_1[7]);
  }
  if ((void *)param_1[4] != (void *)0x0) {
    free((void *)param_1[4]);
  }
  if ((void *)param_1[10] != (void *)0x0) {
    free((void *)param_1[10]);
  }
  free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30117cec @ 0x30117CEC  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: malloc, realloc
 * Вызывают: FUN_30117d54
 * Константы: 0x30117CEC
 * ---------------------------------------------------------------- */
bool FUN_30117cec(int *param_1)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  if (*param_1 != iVar2) {
    return false;
  }
  if (iVar2 == 0) {
    param_1[1] = 1;
    pvVar1 = malloc(4);
  }
  else {
    param_1[1] = iVar2 << 1;
    pvVar1 = realloc((void *)param_1[2],iVar2 << 3);
  }
  param_1[2] = (int)pvVar1;
  return pvVar1 == (void *)0x0;
}

/* ----------------------------------------------------------------
 * FUN_30117d54 @ 0x30117D54  (примерный размер ~292 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_301166b0, FUN_30116860, FUN_30117bcc, FUN_30117cec, memcmp, strlen
 * Вызывают: tagCheckStatementAdd
 * Константы: 0x30117D54
 * Данные: DAT_30118878
 * ---------------------------------------------------------------- */
void FUN_30117d54(undefined4 param_1,int *param_2,void *param_3,size_t param_4,int param_5,
                 undefined4 param_6)

{
  int *piVar1;
  size_t sVar2;
  int iVar3;
  undefined4 *puVar4;
  char *__s;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar1 = DAT_30118878;
  iVar6 = *DAT_30118878;
  iVar5 = 0;
  if (0 < iVar6) {
    iVar7 = DAT_30118878[2];
    do {
      puVar4 = *(undefined4 **)(iVar7 + iVar5 * 4);
      __s = (char *)*puVar4;
      sVar2 = strlen(__s);
      if ((sVar2 == param_4) && (iVar3 = memcmp(__s,param_3,param_4), iVar3 == 0)) {
        FUN_30117bcc(param_2);
        FUN_30116860(puVar4 + 8,param_1);
        return;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar6);
  }
  iVar5 = FUN_301166b0(param_3,param_4);
  *param_2 = iVar5;
  if (iVar5 != 0) {
    if (param_5 != 0) {
      iVar5 = FUN_301166b0(param_5,param_6);
      param_2[1] = iVar5;
      if (iVar5 == 0) goto LAB_30117e3c;
    }
    iVar5 = FUN_30117cec(piVar1);
    if (iVar5 == 0) {
      FUN_30116860(param_2 + 8,param_1);
      iVar5 = *piVar1;
      *(int **)(piVar1[2] + iVar5 * 4) = param_2;
      *piVar1 = iVar5 + 1;
      return;
    }
  }
LAB_30117e3c:
  FUN_30117bcc(param_2);
  return;
}

/* ----------------------------------------------------------------
 * tagCheckModuleAdd @ 0x30117E78  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_301166fc, FUN_30116750, free, malloc, memset, strdup
 * Вызывают: FUN_300fbe34
 * Константы: 0x30117E78
 * Данные: DAT_3011887c
 * ---------------------------------------------------------------- */
undefined4 * tagCheckModuleAdd(char *param_1)

{
  undefined4 uVar1;
  undefined4 *__s;
  char *pcVar2;
  int iVar3;
  
  uVar1 = DAT_3011887c;
  __s = (undefined4 *)FUN_301166fc(DAT_3011887c,param_1);
  if (__s == (undefined4 *)0x0) {
    __s = (undefined4 *)malloc(4);
    if (__s == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    memset(__s,0,4);
    pcVar2 = strdup(param_1);
    *__s = pcVar2;
    if ((pcVar2 == (char *)0x0) || (iVar3 = FUN_30116750(uVar1,__s), iVar3 != 0)) {
      if ((void *)*__s != (void *)0x0) {
        free((void *)*__s);
      }
      free(__s);
      return (undefined4 *)0x0;
    }
  }
  return __s;
}

/* ----------------------------------------------------------------
 * tagCheckModuleDel @ 0x30117F20  (примерный размер ~568 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_301167d0, FUN_30116a34, FUN_30116c94, FUN_30117bcc, __assert, free
 * Вызывают: FUN_300fbf48, FUN_300fc03c
 * Константы: 0x30117F20
 * Данные: DAT_30118878, DAT_3011887c, DAT_30118880, DAT_30118884
 * ---------------------------------------------------------------- */
void tagCheckModuleDel(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  char *extraout_r1;
  char *extraout_r1_00;
  char *extraout_r1_01;
  char *__file;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  
  piVar2 = DAT_3011887c;
  uVar9 = FUN_301167d0(DAT_3011887c,param_1);
  piVar1 = DAT_30118878;
  __file = (char *)((ulonglong)uVar9 >> 0x20);
  if ((int)uVar9 == 0) {
    iVar3 = 0;
    iVar4 = 0;
    if (0 < *DAT_30118878) {
      do {
        iVar6 = piVar1[2];
        iVar5 = *(int *)(iVar6 + iVar4 * 4);
        uVar9 = FUN_301167d0(iVar5 + 0x20,param_1);
        __file = (char *)((ulonglong)uVar9 >> 0x20);
        if (((int)uVar9 == 0) && (*(int *)(iVar5 + 0x20) == 0)) {
          FUN_30117bcc(iVar5);
          __file = extraout_r1;
        }
        else {
          *(int *)(iVar6 + iVar3 * 4) = iVar5;
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *piVar1);
    }
    *DAT_30118878 = iVar3;
    piVar1 = DAT_30118880;
    iVar3 = 0;
    iVar4 = 0;
    if (0 < *DAT_30118880) {
      do {
        iVar5 = 0;
        iVar8 = *(int *)(piVar1[2] + iVar4 * 4);
        iVar6 = 0;
        if (0 < *(int *)(iVar8 + 8)) {
          do {
            iVar7 = *(int *)(*(int *)(iVar8 + 0x10) + iVar6 * 4);
            uVar9 = FUN_301167d0(iVar7 + 4,param_1);
            __file = (char *)((ulonglong)uVar9 >> 0x20);
            if (((int)uVar9 == 0) && (*(int *)(iVar7 + 4) == 0)) {
              FUN_30116c94(iVar7);
              __file = extraout_r1_00;
            }
            else {
              *(int *)(*(int *)(iVar8 + 0x10) + iVar5 * 4) = iVar7;
              iVar5 = iVar5 + 1;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < *(int *)(iVar8 + 8));
        }
        *(int *)(iVar8 + 8) = iVar5;
        if (iVar5 == 0) {
          if (*(int *)(iVar8 + 4) != 1) {
            __assert(DAT_30118884,__file,param_3);
          }
          *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + -1;
          FUN_30116a34(iVar8);
          __file = extraout_r1_01;
        }
        else {
          *(int *)(piVar1[2] + iVar3 * 4) = iVar8;
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *piVar1);
    }
    *piVar1 = iVar3;
    if ((void *)*param_1 != (void *)0x0) {
      free((void *)*param_1);
    }
    free(param_1);
    if ((*piVar2 == 0) && (piVar2[1] != 0)) {
      free((void *)piVar2[2]);
      piVar2[1] = 0;
      piVar2[2] = 0;
    }
    if ((*piVar1 == 0) && (piVar1[1] != 0)) {
      free((void *)piVar1[2]);
      piVar1[1] = 0;
      piVar1[2] = 0;
    }
    if ((*DAT_30118878 == 0) && (DAT_30118878[1] != 0)) {
      free((void *)DAT_30118878[2]);
      piVar1 = DAT_30118878;
      DAT_30118878[1] = 0;
      piVar1[2] = 0;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * tagCheckStatementAdd @ 0x30118158  (примерный размер ~868 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 9
 * Вызывает: FUN_30116654, FUN_30116d70, FUN_30117310, FUN_30117b94, FUN_30117bcc, FUN_30117d54, memcmp, snprintf, strlen
 * Вызывают: FUN_300fbf48
 * Константы: 0x30118158
 * Данные: DAT_30118888, DAT_3011888c, DAT_30118890, DAT_30118894, DAT_30118898, DAT_3011889c, DAT_301188a0
 * ---------------------------------------------------------------- */
int tagCheckStatementAdd(undefined4 *param_1,byte *param_2,char *param_3,uint param_4)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  size_t sVar7;
  int iVar8;
  
  iVar6 = *DAT_30118888;
  pbVar4 = param_2;
  while (uVar3 = (uint)*pbVar4, (*(byte *)(iVar6 + uVar3) & 0x28) != 0) {
    pbVar4 = pbVar4 + 1;
  }
  if ((uVar3 != 0) && (pbVar5 = pbVar4, uVar3 != 0x23)) {
    do {
      if ((*(byte *)(iVar6 + uVar3) & 0x28) != 0) break;
      pbVar5 = pbVar5 + 1;
      uVar3 = (uint)*pbVar5;
    } while (uVar3 != 0);
    if (((int)pbVar5 - (int)pbVar4 == 3) && (iVar1 = memcmp(pbVar4,DAT_3011888c,3), iVar1 == 0)) {
      while ((*(byte *)(iVar6 + (uint)*pbVar5) & 0x28) != 0) {
        pbVar5 = pbVar5 + 1;
      }
      pbVar4 = (byte *)FUN_30116654(pbVar5);
      if ((pbVar4 == (byte *)0x0) ||
         ((*pbVar4 != 0 && ((*(byte *)(iVar6 + (uint)*pbVar4) & 0x28) == 0)))) {
        sVar7 = 0;
        if (param_4 != 0) {
          sVar7 = param_4;
        }
        uVar3 = snprintf(param_3,sVar7,DAT_30118890,*param_1);
        sVar7 = 0;
        if (uVar3 < param_4) {
          sVar7 = param_4 - uVar3;
        }
        goto LAB_30118470;
      }
      iVar1 = (int)pbVar4 - (int)pbVar5;
      while ((*(byte *)(iVar6 + (uint)*pbVar4) & 0x28) != 0) {
        pbVar4 = pbVar4 + 1;
      }
      sVar7 = strlen((char *)pbVar4);
      pbVar2 = pbVar4 + sVar7;
      while ((pbVar4 < pbVar2 && ((*(byte *)(iVar6 + (uint)pbVar2[-1]) & 0x28) != 0))) {
        pbVar2 = pbVar2 + -1;
      }
      FUN_30116d70(param_1,pbVar5,iVar1,pbVar4,(int)pbVar2 - (int)pbVar4);
    }
    else if (((int)pbVar5 - (int)pbVar4 == 6) && (iVar1 = memcmp(pbVar4,DAT_30118894,6), iVar1 == 0)
            ) {
      while ((*(byte *)(iVar6 + (uint)*pbVar5) & 0x28) != 0) {
        pbVar5 = pbVar5 + 1;
      }
      iVar6 = FUN_30117b94();
      if (iVar6 == 0) {
        sVar7 = 0;
        if (param_4 != 0) {
          sVar7 = param_4;
        }
        uVar3 = snprintf(param_3,sVar7,DAT_30118898,*param_1);
        sVar7 = 0;
        if (uVar3 < param_4) {
          sVar7 = param_4 - uVar3;
        }
      }
      else {
        pbVar4 = (byte *)FUN_30117310(iVar6 + 8,pbVar5);
        if (pbVar4 != (byte *)0x0) {
          iVar8 = *DAT_30118888;
          iVar1 = (int)pbVar4 - (int)pbVar5;
          while (uVar3 = (uint)*pbVar4, (*(byte *)(iVar8 + uVar3) & 0x28) != 0) {
            pbVar4 = pbVar4 + 1;
          }
          if (uVar3 == 0x2c) {
            do {
              pbVar4 = pbVar4 + 1;
            } while ((*(byte *)(iVar8 + (uint)*pbVar4) & 0x28) != 0);
            sVar7 = strlen((char *)pbVar4);
            pbVar2 = pbVar4 + sVar7;
            while ((pbVar4 < pbVar2 && ((*(byte *)(iVar8 + (uint)pbVar2[-1]) & 0x28) != 0))) {
              pbVar2 = pbVar2 + -1;
            }
            iVar8 = (int)pbVar2 - (int)pbVar4;
          }
          else {
            if (uVar3 != 0) {
              FUN_30117bcc(iVar6);
              sVar7 = 0;
              if (param_4 != 0) {
                sVar7 = param_4;
              }
              uVar3 = snprintf(param_3,sVar7,DAT_3011889c,*param_1);
              sVar7 = 0;
              if (uVar3 < param_4) {
                sVar7 = param_4 - uVar3;
              }
              goto LAB_30118470;
            }
            pbVar4 = (byte *)0x0;
            iVar8 = 0;
          }
          FUN_30117d54(param_1,iVar6,pbVar5,iVar1,pbVar4,iVar8);
          return 0;
        }
        FUN_30117bcc(iVar6);
        sVar7 = 0;
        if (param_4 != 0) {
          sVar7 = param_4;
        }
        uVar3 = snprintf(param_3,sVar7,DAT_3011889c,*param_1);
        sVar7 = 0;
        if (uVar3 < param_4) {
          sVar7 = param_4 - uVar3;
        }
      }
LAB_30118470:
      iVar6 = snprintf(param_3 + uVar3,sVar7,DAT_301188a0,param_2);
      return iVar6 + uVar3;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * tagCheckEvaluateAsserts @ 0x301184BC  (примерный размер ~1044 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_3011764c, FUN_301176e0, __assert, snprintf
 * Вызывают: FUN_300fc03c
 * Константы: 0x301184BC
 * Данные: DAT_30118878, DAT_301188a4, DAT_301188a8, DAT_301188ac, DAT_301188b0, DAT_301188b4, DAT_301188b8, DAT_301188bc
 * ---------------------------------------------------------------- */
uint tagCheckEvaluateAsserts(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  char *extraout_r1;
  char *pcVar3;
  size_t *psVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  size_t sVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  size_t local_37c;
  size_t local_378;
  size_t local_374 [10];
  int local_34c;
  int local_348;
  int local_344;
  
  piVar1 = DAT_30118878;
  uVar9 = 0;
  local_37c = 0;
  if (0 < *DAT_30118878) {
    do {
      puVar5 = *(undefined4 **)(piVar1[2] + local_37c * 4);
      iVar8 = puVar5[5];
      if (10 < iVar8) {
        local_37c = 0;
        if (uVar9 < param_2) {
          local_37c = param_2 - uVar9;
        }
        iVar8 = snprintf((char *)(param_1 + uVar9),local_37c,DAT_301188a4,
                         **(undefined4 **)puVar5[10]);
        uVar9 = iVar8 + uVar9;
        sVar10 = 0;
        if (uVar9 < param_2) {
          sVar10 = param_2 - uVar9;
        }
LAB_3011863c:
        iVar8 = snprintf((char *)(param_1 + uVar9),sVar10,DAT_301188b0,*puVar5);
        return iVar8 + uVar9;
      }
      if (0 < iVar8) {
        psVar4 = &local_378;
        do {
          psVar4 = psVar4 + 1;
          *psVar4 = 0;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      do {
        local_34c = 0;
        psVar4 = local_374;
        uVar12 = FUN_301176e0(puVar5 + 2,&local_34c);
        if ((int)uVar12 != 0) {
          local_37c = 0;
          if (uVar9 < param_2) {
            local_37c = param_2 - uVar9;
          }
          iVar8 = snprintf((char *)(param_1 + uVar9),local_37c,DAT_301188a8,
                           **(undefined4 **)puVar5[10]);
          uVar9 = iVar8 + uVar9;
          sVar10 = 0;
          if (uVar9 < param_2) {
            sVar10 = param_2 - uVar9;
          }
          goto LAB_3011863c;
        }
        if (local_34c != 1) {
          __assert(DAT_301188ac,(char *)((ulonglong)uVar12 >> 0x20),(int)psVar4);
        }
        uVar12 = FUN_3011764c(&local_348);
        pcVar3 = (char *)((ulonglong)uVar12 >> 0x20);
        if ((int)uVar12 != 0) {
          local_37c = 0;
          if (uVar9 < param_2) {
            local_37c = param_2 - uVar9;
          }
          iVar8 = snprintf((char *)(param_1 + uVar9),local_37c,DAT_301188a8,
                           **(undefined4 **)puVar5[10]);
          uVar9 = iVar8 + uVar9;
          sVar10 = 0;
          if (uVar9 < param_2) {
            sVar10 = param_2 - uVar9;
          }
          goto LAB_3011863c;
        }
        if (local_348 != 0) {
          __assert(DAT_301188b4,pcVar3,(int)psVar4);
          pcVar3 = extraout_r1;
        }
        if (local_344 == 0) {
          if ((int)puVar5[8] < 1) {
            __assert(DAT_301188b8,pcVar3,(int)psVar4);
          }
          sVar10 = 0;
          if (uVar9 < param_2) {
            sVar10 = param_2 - uVar9;
          }
          iVar8 = snprintf((char *)(param_1 + uVar9),sVar10,DAT_301188bc);
          uVar9 = iVar8 + uVar9;
          if (puVar5[1] != 0) {
            sVar10 = 0;
            if (uVar9 < param_2) {
              sVar10 = param_2 - uVar9;
            }
            iVar8 = snprintf((char *)(param_1 + uVar9),sVar10,DAT_301188c0,puVar5[1]);
            uVar9 = iVar8 + uVar9;
          }
          sVar10 = 0;
          if (uVar9 < param_2) {
            sVar10 = param_2 - uVar9;
          }
          uVar11 = **(undefined4 **)puVar5[10];
          iVar8 = snprintf((char *)(param_1 + uVar9),sVar10,DAT_301188c4,*puVar5,uVar11);
          uVar9 = iVar8 + uVar9;
          iVar8 = 0;
          if (0 < (int)puVar5[5]) {
            psVar4 = &local_378;
            do {
              psVar4 = psVar4 + 1;
              puVar6 = *(undefined4 **)(puVar5[7] + iVar8 * 4);
              if ((int)*psVar4 < (int)puVar6[2]) {
                local_378 = 0;
                if (uVar9 < param_2) {
                  local_378 = param_2 - uVar9;
                }
                uVar11 = **(undefined4 **)(puVar6[4] + *psVar4 * 4);
                sVar10 = local_378;
                pcVar3 = DAT_301188c8;
              }
              else {
                sVar10 = 0;
                pcVar3 = DAT_301188cc;
                if (uVar9 < param_2) {
                  sVar10 = param_2 - uVar9;
                }
              }
              iVar2 = snprintf((char *)(param_1 + uVar9),sVar10,pcVar3,*puVar6,uVar11);
              uVar9 = iVar2 + uVar9;
              iVar8 = iVar8 + 1;
            } while (iVar8 < (int)puVar5[5]);
          }
        }
        iVar8 = 0;
        if (0 < (int)puVar5[5]) {
          psVar4 = &local_378;
          piVar7 = (int *)(puVar5[7] + -4);
          do {
            psVar4 = psVar4 + 1;
            sVar10 = *psVar4;
            piVar7 = piVar7 + 1;
            *psVar4 = sVar10 + 1;
            if ((int)(sVar10 + 1) < *(int *)(*piVar7 + 8)) break;
            *psVar4 = 0;
            iVar8 = iVar8 + 1;
          } while (iVar8 < (int)puVar5[5]);
        }
      } while (iVar8 < (int)puVar5[5]);
      local_37c = local_37c + 1;
    } while ((int)local_37c < *piVar1);
  }
  return uVar9;
}

/* ----------------------------------------------------------------
 * unlink @ 0x301188D0  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: close, errnoGet, errnoSet, ioctl, open, remove
 * Вызывают: FUN_3011a5a0, xdelete
 * Константы: 0x301188D0
 * Данные: DAT_30118ee4, DAT_30118ee8
 * ---------------------------------------------------------------- */
int unlink(char *__name)

{
  undefined4 uVar1;
  int __fd;
  int iVar2;
  int iVar3;
  
  if ((__name == (char *)0x0) || (*__name == '\0')) {
    errnoSet(2);
    return -1;
  }
  uVar1 = errnoGet();
  __fd = open(__name,0,0);
  if ((__fd < 0) && (__fd = open(__name,0x40000,0), __fd < 0)) {
    return -1;
  }
  errnoSet(uVar1);
  iVar2 = ioctl(__fd,0x3b,0);
  iVar3 = errnoGet();
  close(__fd);
  if ((iVar2 != 0) &&
     ((((iVar3 == 0x47 || (iVar3 == 0x23)) || (iVar3 == DAT_30118ee4)) || (iVar3 == DAT_30118ee8))))
  {
    errnoSet(0);
    iVar2 = remove(__name);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * link @ 0x301189C0  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: close, errnoGet, errnoSet, ioctl, open
 * Константы: 0x301189C0
 * ---------------------------------------------------------------- */
int link(char *__from,char *__to)

{
  undefined4 uVar1;
  int __fd;
  int iVar2;
  
  if ((((__from != (char *)0x0) && (__to != (char *)0x0)) && (*__from != '\0')) && (*__to != '\0'))
  {
    uVar1 = errnoGet();
    __fd = open(__from,0,0);
    if ((__fd < 0) && (__fd = open(__from,0x40000,0), __fd < 0)) {
      return -1;
    }
    errnoSet(uVar1);
    iVar2 = ioctl(__fd,0x3a,__to);
    close(__fd);
    return iVar2;
  }
  errnoSet(2);
  return -1;
}

/* ----------------------------------------------------------------
 * fsync @ 0x30118A78  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: ioctl
 * Вызывают: FUN_3000c338
 * Константы: 0x30118A78
 * Данные: DAT_30118eec
 * ---------------------------------------------------------------- */
int fsync(int __fd)

{
  int iVar1;
  undefined4 local_c;
  
  if ((code *)*DAT_30118eec != (code *)0x0) {
    (*(code *)*DAT_30118eec)(0,&local_c);
  }
  iVar1 = ioctl(__fd,0x15,0);
  if ((code *)*DAT_30118eec != (code *)0x0) {
    (*(code *)*DAT_30118eec)(local_c,0);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * fdatasync @ 0x30118AEC  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: ioctl
 * Константы: 0x30118AEC
 * Данные: DAT_30118eec
 * ---------------------------------------------------------------- */
int fdatasync(int __fildes)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_10;
  
  puVar1 = DAT_30118eec;
  if ((code *)*DAT_30118eec != (code *)0x0) {
    (*(code *)*DAT_30118eec)(0,&local_10);
  }
  iVar2 = ioctl(__fildes,0x39,0);
  if ((code *)*puVar1 != (code *)0x0) {
    (*(code *)*puVar1)(local_10,0);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * rename @ 0x30118B5C  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: close, errnoGet, errnoSet, ioctl, open
 * Вызывают: exchFileSave
 * Константы: 0x30118B5C
 * ---------------------------------------------------------------- */
int rename(char *__old,char *__new)

{
  undefined4 uVar1;
  int __fd;
  int iVar2;
  
  if ((((__old != (char *)0x0) && (__new != (char *)0x0)) && (*__old != '\0')) && (*__new != '\0'))
  {
    uVar1 = errnoGet();
    __fd = open(__old,0,0);
    if ((__fd < 0) && (__fd = open(__old,0x40000,0), __fd < 0)) {
      return -1;
    }
    errnoSet(uVar1);
    iVar2 = ioctl(__fd,10,__new);
    close(__fd);
    return iVar2;
  }
  errnoSet(2);
  return -1;
}

/* ----------------------------------------------------------------
 * fpathconf @ 0x30118C14  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: ioctl, strlen
 * Константы: 0x30118C14
 * Данные: DAT_30118ef0, DAT_30118ef4
 * ---------------------------------------------------------------- */
long fpathconf(int __fd,int __name)

{
  int iVar1;
  size_t sVar2;
  long local_c;
  
  local_c = __name;
  iVar1 = ioctl(__fd,0x3d,&local_c);
  if (iVar1 == 0) {
    if ((__name == 0xb) && (*DAT_30118ef0 != 0)) {
      sVar2 = strlen(*(char **)(*(int *)(*DAT_30118ef4 + 0x94) + 0xd4));
      local_c = local_c - (sVar2 + 1);
    }
  }
  else {
    local_c = -1;
  }
  return local_c;
}

/* ----------------------------------------------------------------
 * pathconf @ 0x30118C88  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: close, errnoGet, errnoSet, ioctl, open, strlen
 * Константы: 0x30118C88
 * Данные: DAT_30118ef0, DAT_30118ef4
 * ---------------------------------------------------------------- */
long pathconf(char *__path,int __name)

{
  undefined4 uVar1;
  int __fd;
  int iVar2;
  size_t sVar3;
  long local_18;
  
  if ((__path == (char *)0x0) || (*__path == '\0')) {
    errnoSet(2);
  }
  else {
    uVar1 = errnoGet();
    __fd = open(__path,0,0);
    if ((-1 < __fd) || (__fd = open(__path,0x40000,0), -1 < __fd)) {
      errnoSet(uVar1);
      local_18 = __name;
      iVar2 = ioctl(__fd,0x3d,&local_18);
      if (iVar2 == 0) {
        close(__fd);
        if (__name != 0xb) {
          return local_18;
        }
        if (*DAT_30118ef0 == 0) {
          return local_18;
        }
        sVar3 = strlen(*(char **)(*(int *)(*DAT_30118ef4 + 0x94) + 0xd4));
        return local_18 - (sVar3 + 1);
      }
      close(__fd);
    }
  }
  return -1;
}

/* ----------------------------------------------------------------
 * access @ 0x30118D78  (примерный размер ~180 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: close, errnoGet, errnoSet, ioctl, open
 * Вызывают: exchFileSave
 * Константы: 0x30118D78
 * ---------------------------------------------------------------- */
int access(char *__name,int __type)

{
  undefined4 uVar1;
  int __fd;
  int iVar2;
  
  if ((__name == (char *)0x0) || (*__name == '\0')) {
    errnoSet(2);
  }
  else {
    uVar1 = errnoGet();
    __fd = open(__name,0,0);
    if ((-1 < __fd) || (__fd = open(__name,0x40000,0), -1 < __fd)) {
      errnoSet(uVar1);
      if ((__type == 0) || (iVar2 = ioctl(__fd,0x3c,__type), iVar2 == 0)) {
        close(__fd);
        return 0;
      }
      close(__fd);
    }
  }
  return -1;
}

/* ----------------------------------------------------------------
 * chmod @ 0x30118E2C  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: close, errnoGet, errnoSet, ioctl, open
 * Константы: 0x30118E2C
 * ---------------------------------------------------------------- */
int chmod(char *__file,__mode_t __mode)

{
  undefined4 uVar1;
  int __fd;
  int iVar2;
  
  if ((__file == (char *)0x0) || (*__file == '\0')) {
    errnoSet(2);
  }
  else {
    uVar1 = errnoGet();
    __fd = open(__file,0,0);
    if ((-1 < __fd) || (__fd = open(__file,0x40000,0), -1 < __fd)) {
      errnoSet(uVar1);
      iVar2 = ioctl(__fd,0x3f,__mode);
      if (iVar2 == 0) {
        close(__fd);
        return 0;
      }
      close(__fd);
    }
  }
  return -1;
}

/* ----------------------------------------------------------------
 * fchmod @ 0x30118ED8  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: ioctl
 * Константы: 0x30118ED8
 * ---------------------------------------------------------------- */
int fchmod(int __fd,__mode_t __mode)

{
  int iVar1;
  
  iVar1 = ioctl(__fd,0x3f,__mode);
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30118ef8 @ 0x30118EF8  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 1
 * Вызывает: index
 * Вызывают: FUN_30118f30, FUN_3011904c, cp, xattrib, xcopy, xdelete
 * Константы: 0x30118EF8
 * ---------------------------------------------------------------- */
char * FUN_30118ef8(char *param_1)

{
  char *pcVar1;
  bool bVar2;
  
  pcVar1 = index(param_1,0x2a);
  bVar2 = pcVar1 == (char *)0x0;
  if (bVar2) {
    pcVar1 = index(param_1,0x3f);
    bVar2 = pcVar1 == (char *)0x0;
    if (bVar2) {
      param_1 = (char *)0x0;
    }
  }
  if (!bVar2) {
    param_1 = (char *)0x1;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * FUN_30118f30 @ 0x30118F30  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: FUN_30118ef8, stat
 * Вызывают: FUN_3011904c, mv
 * Константы: 0x30118F30
 * ---------------------------------------------------------------- */
undefined4 FUN_30118f30(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint local_48;
  
  iVar1 = FUN_30118ef8();
  if (iVar1 == 0) {
    iVar1 = stat(param_1,(stat *)&stack0xffffffb0);
    if (iVar1 == 0) {
      if ((local_48 & 0xf000) == 0x4000) {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 3;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30118f84 @ 0x30118F84  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 3
 * Вызывает: memcmp, sprintf, strcpy
 * Вызывают: cp, dirList, mv, xattrib, xcopy
 * Константы: 0x30118F84
 * Данные: DAT_30119f60, DAT_30119f64
 * ---------------------------------------------------------------- */
void FUN_30118f84(char *param_1,char *param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  *param_3 = '\0';
  if (((param_1 != (char *)0x0) && (*param_1 != '\0')) &&
     (iVar1 = memcmp(param_1,DAT_30119f60,3), iVar1 != 0)) {
    iVar2 = sprintf(param_3,DAT_30119f64,param_1);
  }
  strcpy(param_3 + iVar2,param_2);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30118fec @ 0x30118FEC  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 2
 * Вызывает: __errno, stat
 * Вызывают: FUN_3011904c, FUN_3011a5a0, copy, cp, xattrib, xcopy
 * Константы: 0x30118FEC
 * ---------------------------------------------------------------- */
undefined4 FUN_30118fec(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  uint local_44;
  
  bVar4 = param_1 == (char *)0x0;
  if (!bVar4) {
    bVar4 = *param_1 == '\0';
  }
  if (bVar4) {
    uVar1 = 0;
  }
  else {
    iVar2 = stat(param_1,(stat *)&stack0xffffffb4);
    if (iVar2 == -1) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0;
      uVar1 = 0;
    }
    else if ((local_44 & 0xf000) == 0x4000) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3011904c @ 0x3011904C  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 4
 * Вызывает: FUN_30118ef8, FUN_30118f30, FUN_30118fec, rindex
 * Вызывают: cp, dirList, xattrib, xcopy, xdelete
 * Константы: 0x3011904C
 * Данные: DAT_30119f60
 * ---------------------------------------------------------------- */
undefined4 FUN_3011904c(char *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = rindex(param_1,0x2f);
  if (pcVar1 == param_1) {
LAB_30119094:
    *param_2 = param_1;
  }
  else {
    iVar2 = FUN_30118f30(param_1);
    if (pcVar1 == (char *)0x0) {
      if (iVar2 != 1) {
        *param_2 = DAT_30119f60;
        goto LAB_301190e0;
      }
      goto LAB_30119094;
    }
    *param_2 = param_1;
    *param_3 = pcVar1 + 1;
    if ((pcVar1[1] != '\0') &&
       ((iVar2 = FUN_30118ef8(), iVar2 != 0 || (iVar2 = FUN_30118fec(param_1), iVar2 == 0)))) {
      *pcVar1 = '\0';
      return 0;
    }
  }
  param_1 = (char *)0x0;
LAB_301190e0:
  *param_3 = param_1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_301190ec @ 0x301190EC  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: rindex
 * Вызывают: mv
 * Константы: 0x301190EC
 * Данные: DAT_30119f60
 * ---------------------------------------------------------------- */
undefined4 FUN_301190ec(char *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char *pcVar1;
  
  while( true ) {
    pcVar1 = rindex(param_1,0x2f);
    if (pcVar1 == param_1) {
      *param_2 = param_1;
      param_1 = (char *)0x0;
      goto LAB_30119148;
    }
    if (pcVar1 == (char *)0x0) break;
    *pcVar1 = '\0';
    if (pcVar1[1] != '\0') {
      *param_2 = param_1;
      param_1 = pcVar1 + 1;
LAB_30119148:
      *param_3 = param_1;
      return 0;
    }
  }
  *param_2 = DAT_30119f60;
  goto LAB_30119148;
}

/* ----------------------------------------------------------------
 * cd @ 0x30119154  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: __errno, ioDefPathCat, printf
 * Вызывают: dynFSFirstPacketHandle
 * Константы: 0x30119154, 0xFFFFFFFF
 * Данные: DAT_3011a0d0
 * ---------------------------------------------------------------- */
undefined4 cd(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = ioDefPathCat();
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    puVar2 = (undefined4 *)__errno();
    printf(DAT_3011a0d0,*puVar2);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * pwd @ 0x30119184  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: ioDefPathGet, puts
 * Константы: 0x30119184
 * ---------------------------------------------------------------- */
void pwd(void)

{
  char acStack_404 [1028];
  
  ioDefPathGet(acStack_404);
  puts(acStack_404);
  return;
}

/* ----------------------------------------------------------------
 * mkdir @ 0x301191AC  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 2
 * Вызывает: close, open
 * Вызывают: BSP_mkdir, dynFSFirstPacketHandle, exchFileSave, exchInit, xcopy
 * Константы: 0x301191AC
 * Данные: DAT_3011a0d4, DAT_3011a0d8
 * ---------------------------------------------------------------- */
int mkdir(char *__path,__mode_t __mode)

{
  int iVar1;
  
  iVar1 = open(__path,DAT_3011a0d4,DAT_3011a0d8);
  if (iVar1 == -1) {
    iVar1 = -1;
  }
  else {
    iVar1 = close(iVar1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * rmdir @ 0x301191D4  (примерный размер ~216 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 7
 * Вызывает: close, errnoGet, errnoSet, fstat, ioctl, open, remove
 * Вызывают: BSP_rmdir, FUN_3011a5a0, yaffsFormat
 * Константы: 0x301191D4
 * ---------------------------------------------------------------- */
int rmdir(char *__path)

{
  int __fd;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_54;
  
  __fd = open(__path,0,0);
  if (__fd == -1) {
    iVar1 = -1;
  }
  else {
    iVar1 = fstat(__fd,(stat *)&stack0xffffffa4);
    if (iVar1 == 0) {
      if ((local_54 & 0xf000) == 0x4000) {
        iVar1 = ioctl(__fd,0x20,__path);
        iVar3 = errnoGet();
        close(__fd);
        if ((iVar1 != 0) && ((iVar3 == 0x23 || (iVar3 == 0x47)))) {
          iVar1 = remove(__path);
        }
      }
      else {
        close(__fd);
        errnoSet(0x14);
        iVar1 = -1;
      }
    }
    else {
      uVar2 = errnoGet();
      close(__fd);
      errnoSet(uVar2);
      iVar1 = -1;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * rm @ 0x301192AC  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 12
 * Вызывает: __errno, errnoSet, ioFullFileNameGet, iosDelete, iosDevFind, memPartAlloc, memPartFree, pathCat, pathCondense, strlen, strncmp, strncpy
 * Вызывают: FUN_30080798, dloadFromFsMainThread, dloadTFPro, yaffsFormat
 * Константы: 0x301192AC
 * Данные: DAT_300e8b80, DAT_300e8b84, DAT_300e8b88
 * ---------------------------------------------------------------- */
int rm(char *__filename)

{
  int iVar1;
  char *__s;
  size_t __n;
  undefined4 *puVar2;
  int iVar3;
  char *pcStack_24;
  int iStack_20;
  
  iVar3 = 1;
  if ((__filename == (char *)0x0) || (*__filename == '\0')) {
    errnoSet(2);
    iVar1 = -1;
  }
  else {
    __s = (char *)memPartAlloc(*DAT_300e8b80,0x400);
    if (__s == (char *)0x0) {
      iVar1 = -1;
    }
    else {
      iVar1 = pathCat(*(undefined4 *)(*(int *)(*DAT_300e8b84 + 0x94) + 0xd4),__filename,__s);
      if (iVar1 == -1) {
        memPartFree(*DAT_300e8b80,__s);
        iVar1 = -1;
      }
      else {
        pathCondense(__s);
        __n = strlen(__s);
        iVar1 = strncmp(__s,*(char **)(*(int *)(*DAT_300e8b84 + 0x94) + 0xd4),__n);
        if (iVar1 == 0) {
          memPartFree(*DAT_300e8b80,__s);
          iVar1 = -1;
        }
        else {
          iVar1 = ioFullFileNameGet(__filename,&iStack_20,__s);
          if (iVar1 == -1) {
            memPartFree(*DAT_300e8b80,__s);
            iVar1 = -1;
          }
          else {
            iVar1 = iosDelete(iStack_20,__s);
            while (iVar1 == -2) {
              if (*DAT_300e8b88 < iVar3) {
                memPartFree(*DAT_300e8b80,__s);
                puVar2 = (undefined4 *)__errno();
                *puVar2 = 0x40;
                return -1;
              }
              iVar3 = iVar3 + 1;
              iVar1 = iosDevFind(__s,&pcStack_24);
              if (iVar1 == 0) {
                memPartFree(*DAT_300e8b80,__s);
                return -1;
              }
              if (__s != pcStack_24) {
                strncpy(__s,pcStack_24,0x400);
                iStack_20 = iVar1;
              }
              iVar1 = iosDelete(iStack_20,__s);
            }
            memPartFree(*DAT_300e8b80,__s);
          }
        }
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * copyStreams @ 0x301192B0  (примерный размер ~264 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: __errno, fioRead, free, ioctl, malloc, printErr, write
 * Вызывают: copy
 * Константы: 0xFFFFFFFF, 0x301192B0
 * Данные: DAT_3011a2a4, DAT_3011a2a8
 * ---------------------------------------------------------------- */
undefined4 copyStreams(int param_1,int param_2)

{
  int iVar1;
  void *__buf;
  size_t sVar2;
  undefined4 *puVar3;
  size_t __n;
  int iVar4;
  uint local_1c;
  
  iVar4 = 0;
  local_1c = 0x10000;
  if (param_1 == 0) {
    local_1c = 1;
  }
  else {
    iVar1 = ioctl(param_1,1,&local_1c);
    if ((iVar1 == -1) || (0x10000 < local_1c)) {
      local_1c = 0x10000;
    }
    else if (local_1c == 0) {
      return 0;
    }
  }
  __buf = malloc(local_1c);
  if (__buf == (void *)0x0) {
    return 0xffffffff;
  }
  while (__n = fioRead(param_1,__buf), 0 < (int)__n) {
    sVar2 = write(param_2,__buf,__n);
    if (sVar2 != __n) {
      puVar3 = (undefined4 *)__errno();
      printErr(DAT_3011a2a4,*puVar3);
      free(__buf);
      return 0xffffffff;
    }
    iVar4 = iVar4 + __n;
  }
  free(__buf);
  if (-1 < (int)__n) {
    return 0;
  }
  printErr(DAT_3011a2a8,iVar4);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * copy @ 0x301193B8  (примерный размер ~416 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 10
 * Вызывает: FUN_30118fec, __errno, close, copyStreams, errnoSet, ioctl, open, printErr, strcmp, time
 * Вызывают: cp, xcopy
 * Константы: 0x301193B8
 * Данные: DAT_3011a39c, DAT_3011a3a0, DAT_3011a3a4, DAT_3011a3a8, DAT_3011a3ac
 * ---------------------------------------------------------------- */
int copy(EVP_PKEY_CTX *dst,EVP_PKEY_CTX *src)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  time_t local_68;
  time_t local_64;
  undefined1 auStack_60 [32];
  time_t local_40;
  time_t local_3c;
  
  iVar5 = 0;
  if (dst != (EVP_PKEY_CTX *)0x0) {
    iVar5 = open((char *)dst,0,0);
  }
  if (iVar5 == -1) {
    puVar1 = (undefined4 *)__errno();
    printErr(DAT_3011a39c,dst,*puVar1);
    return -1;
  }
  iVar2 = FUN_30118fec(src);
  if (iVar2 != 0) {
    errnoSet(0x15);
    close(iVar5);
    return -1;
  }
  if (dst == (EVP_PKEY_CTX *)0x0) {
LAB_30119474:
    if (src != (EVP_PKEY_CTX *)0x0) {
      iVar2 = open((char *)src,DAT_3011a3a4,DAT_3011a3a8);
      goto LAB_30119498;
    }
  }
  else if (src != (EVP_PKEY_CTX *)0x0) {
    iVar2 = strcmp((char *)dst,(char *)src);
    if (iVar2 == 0) {
      printErr(DAT_3011a3a0,dst,src);
      errnoSet(0x16);
      return -1;
    }
    goto LAB_30119474;
  }
  iVar2 = 1;
LAB_30119498:
  if (iVar2 == -1) {
    puVar1 = (undefined4 *)__errno();
    printErr(DAT_3011a3ac,src,*puVar1);
    if (dst != (EVP_PKEY_CTX *)0x0) {
      close(iVar5);
    }
    iVar3 = -1;
  }
  else {
    iVar3 = copyStreams(iVar5,iVar2);
    iVar4 = ioctl(iVar5,0x40,auStack_60);
    if (iVar4 == 0) {
      local_68 = local_40;
    }
    else {
      local_3c = time((time_t *)0x0);
      local_68 = local_3c;
    }
    local_64 = local_3c;
    ioctl(iVar2,0x2c,&local_68);
    if (dst != (EVP_PKEY_CTX *)0x0) {
      close(iVar5);
    }
    if ((src != (EVP_PKEY_CTX *)0x0) && (iVar5 = close(iVar2), iVar5 == -1)) {
      iVar3 = -1;
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * chkdsk @ 0x30119558  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: close, ioctl, open, perror
 * Константы: 0x30119558
 * ---------------------------------------------------------------- */
int chkdsk(char *param_1,uint param_2,uint param_3)

{
  int __fd;
  int iVar1;
  
  __fd = open(param_1,(uint)(1 < (param_2 & 0xf)) << 1,0);
  if (__fd != -1) {
    if ((param_3 & 0xff00) == 0) {
      if ((param_3 & 0xff) == 0) {
        param_3 = 0x100;
      }
      else {
        param_3 = param_3 << 8;
      }
    }
    else {
      param_3 = param_3 & 0xff00;
    }
    iVar1 = ioctl(__fd,0x30,param_2 & 0xf | param_3);
    close(__fd);
    return iVar1;
  }
  perror(param_1);
  return -1;
}

/* ----------------------------------------------------------------
 * FUN_301195e4 @ 0x301195E4  (примерный размер ~268 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 0
 * Вызывают: FUN_3011a5a0, cp, dirList, mv, xattrib, xcopy
 * Константы: 0x301195E4
 * Данные: DAT_3011a5d8
 * ---------------------------------------------------------------- */
bool FUN_301195e4(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  bVar1 = *param_2;
  pbVar5 = param_2;
  while (bVar1 != 0) {
    uVar3 = (uint)*param_1;
    if (uVar3 == 0x3f) {
LAB_301196b0:
      param_1 = param_1 + 1;
      pbVar5 = pbVar5 + 1;
    }
    else {
      pbVar4 = param_1;
      if (uVar3 != 0x2a) {
        if (*(char *)(*DAT_3011a5d8 + uVar3) != *(char *)(*DAT_3011a5d8 + (uint)*pbVar5)) {
          return false;
        }
        goto LAB_301196b0;
      }
      do {
        pbVar4 = pbVar4 + 1;
      } while (*pbVar4 == 0x2a);
      if (*pbVar5 == 0) break;
      do {
        if (((param_3 == 0) && (*pbVar5 == 0x2e)) && (pbVar5 == param_2)) {
          return false;
        }
        iVar2 = FUN_301195e4(pbVar4,pbVar5,param_3 + 1);
        if (iVar2 != 0) {
          return true;
        }
        pbVar5 = pbVar5 + 1;
      } while (*pbVar5 != 0);
    }
    bVar1 = *pbVar5;
  }
  bVar1 = *param_1;
  while (bVar1 == 0x2a) {
    param_1 = param_1 + 1;
    bVar1 = *param_1;
  }
  return *param_1 == 0;
}

/* ----------------------------------------------------------------
 * FUN_301196f0 @ 0x301196F0  (примерный размер ~632 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: fdprintf, localtime_r, memcmp, strlen, time
 * Вызывают: dirList
 * Константы: 0x301196F0, 0xFFFFFF6D, 0xFFFFFFFF
 * Данные: DAT_30119f60, DAT_30119f64, DAT_3011a7e4, DAT_3011a7e8, DAT_3011a7ec, DAT_3011a7f0, DAT_3011a7f4, DAT_3011a7f8
 * ---------------------------------------------------------------- */
undefined4
FUN_301196f0(undefined4 param_1,undefined4 param_2,int param_3,char *param_4,undefined4 param_5,
            int param_6)

{
  byte bVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  time_t tStack_7c;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined1 local_75;
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  undefined1 local_70;
  undefined1 local_6f;
  tm tStack_6c;
  int local_34;
  
  uVar5 = 0x20;
  if (param_6 == 0) {
    if (((param_4 != (char *)0x0) && (iVar3 = memcmp(param_4,DAT_30119f60,3), iVar3 != 0)) &&
       (*param_4 != '\0')) {
      sVar2 = strlen(param_4);
      if (param_4[sVar2 - 1] == '/') {
        fdprintf(param_1,param_4);
      }
      else {
        fdprintf(param_1,DAT_30119f64,param_4);
      }
    }
  }
  else {
    time(&tStack_7c);
    localtime_r(&tStack_7c,(tm *)&tStack_6c.tm_gmtoff);
    localtime_r((time_t *)(param_3 + 0x24),&tStack_6c);
    bVar1 = *(byte *)(param_3 + 0x34);
    if ((bVar1 & 1) != 0) {
      *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) & 0xffffff6d;
    }
    uVar6 = *(uint *)(param_3 + 8);
    if ((uVar6 & 0xf000) == 0x4000) {
      uVar4 = 100;
      uVar5 = 0x2f;
    }
    else {
      uVar4 = 0x3f;
      if ((uVar6 & 0xf000) == 0x8000) {
        uVar4 = 0x2d;
      }
    }
    local_78 = 0x2d;
    if ((uVar6 & 0x100) != 0) {
      local_78 = 0x72;
    }
    local_77 = 0x2d;
    if ((uVar6 & 0x80) != 0) {
      local_77 = 0x77;
    }
    local_76 = 0x2d;
    if ((uVar6 & 0x40) != 0) {
      local_76 = 0x78;
    }
    local_75 = 0x2d;
    if ((uVar6 & 0x20) != 0) {
      local_75 = 0x72;
    }
    local_74 = 0x2d;
    if ((uVar6 & 0x10) != 0) {
      local_74 = 0x77;
    }
    local_73 = 0x2d;
    if ((uVar6 & 8) != 0) {
      local_73 = 0x78;
    }
    local_72 = 0x2d;
    if ((uVar6 & 4) != 0) {
      local_72 = 0x72;
    }
    local_71 = 0x2d;
    if ((uVar6 & 2) != 0) {
      local_71 = 0x77;
    }
    local_70 = 0x2d;
    if ((uVar6 & 1) != 0) {
      local_70 = 0x78;
    }
    if ((bVar1 & 0x20) != 0) {
      local_72 = 0x41;
    }
    if ((bVar1 & 4) != 0) {
      local_71 = 0x53;
    }
    if ((bVar1 & 2) != 0) {
      local_70 = 0x48;
    }
    local_6f = 0;
    fdprintf(param_1,DAT_3011a7e4,uVar4,&local_78);
    fdprintf(param_1,DAT_3011a7e8,*(undefined4 *)(param_3 + 0xc),*(undefined2 *)(param_3 + 0x10),
             *(undefined2 *)(param_3 + 0x12));
    fdprintf(param_1,DAT_3011a7ec,*(undefined4 *)(param_3 + 0x18),*(undefined4 *)(param_3 + 0x1c));
    if (local_34 == tStack_6c.tm_year) {
      fdprintf(param_1,DAT_3011a7f4,*(undefined4 *)(DAT_3011a7f0 + tStack_6c.tm_mon * 4),
               tStack_6c.tm_mday,tStack_6c.tm_hour,tStack_6c.tm_min);
    }
    else {
      fdprintf(param_1,DAT_3011a7fc,*(undefined4 *)(DAT_3011a7f0 + tStack_6c.tm_mon * 4),
               tStack_6c.tm_mday,tStack_6c.tm_year + DAT_3011a7f8);
    }
  }
  iVar3 = fdprintf(param_1,DAT_3011a800,param_2,uVar5);
  if (iVar3 == -1) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * dirList @ 0x30119968  (примерный размер ~904 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 15
 * Вызывает: FUN_30118f84, FUN_3011904c, FUN_301195e4, FUN_301196f0, __errno, bzero, closedir, fdprintf, free, malloc, memcmp, opendir, readdir, stat
 *           ...
 * Вызывают: ll, llr, ls, lsr
 * Константы: 0xFFFFFFFF, 0x30119968
 * Данные: DAT_30119f60, DAT_3011a8a0, DAT_3011a8a4, DAT_3011a8a8, DAT_3011a8ac, DAT_3011a9a8, DAT_3011a9ac, DAT_3011aa98
 * ---------------------------------------------------------------- */
uint dirList(undefined4 param_1,char *param_2,int param_3,int param_4)

{
  size_t sVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  DIR *pDVar5;
  int iVar6;
  undefined4 *puVar7;
  dirent *pdVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  char *__file;
  char *pcVar12;
  uint local_80;
  int local_7c;
  char *local_78;
  undefined1 auStack_74 [8];
  uint local_6c;
  
  if ((code *)*DAT_3011a8a0 != (code *)0x0) {
    pcVar4 = DAT_3011a8a4;
    if (param_2 != (char *)0x0) {
      pcVar4 = param_2;
    }
    iVar2 = (*(code *)*DAT_3011a8a0)(pcVar4);
    if (iVar2 == 0) {
      return 0;
    }
    piVar3 = (int *)__errno(iVar2);
    if (*piVar3 != DAT_3011a8a8) {
      return 0xffffffff;
    }
  }
  pcVar4 = (char *)malloc(0x800);
  sVar1 = DAT_3011a8ac;
  if (pcVar4 == (char *)0x0) {
    return 0xffffffff;
  }
  __file = pcVar4 + 0x400;
  if (param_2 == (char *)0x0) {
    iVar2 = 0;
    pcVar11 = DAT_30119f60;
  }
  else {
    strncpy(pcVar4,param_2,DAT_3011a8ac);
    pcVar4[sVar1] = '\0';
    FUN_3011904c(pcVar4,&local_78,&local_7c);
    iVar2 = local_7c;
    pcVar11 = local_78;
  }
  pDVar5 = opendir(pcVar11);
  if (pDVar5 != (DIR *)0x0) {
    iVar6 = memcmp(pcVar11,DAT_30119f60,3);
    pcVar12 = DAT_3011a9a8;
    if ((iVar6 != 0) && (pcVar12 = pcVar11, param_3 != 0)) {
      fdprintf(param_1,DAT_3011a9ac,pcVar11);
    }
    local_80 = 0;
    do {
      puVar7 = (undefined4 *)__errno();
      *puVar7 = 0;
      pdVar8 = readdir(pDVar5);
      if (pdVar8 == (dirent *)0x0) {
        piVar3 = (int *)__errno();
        if (*piVar3 == 0) break;
        puVar7 = (undefined4 *)__errno();
        fdprintf(param_1,DAT_3011aa98,pcVar12,*puVar7);
LAB_30119b60:
        local_80 = 0xffffffff;
      }
      else if ((iVar2 == 0) || (iVar6 = FUN_301195e4(iVar2,&pdVar8->d_off,0), iVar6 != 0)) {
        if (param_3 != 0) {
          FUN_30118f84(pcVar12,&pdVar8->d_off,__file);
          iVar6 = stat(__file,(stat *)auStack_74);
          if (iVar6 != 0) {
            bzero(auStack_74,0x48);
          }
        }
        iVar6 = FUN_301196f0(param_1,&pdVar8->d_off,auStack_74,pcVar12,__file,param_3);
        if (iVar6 == -1) goto LAB_30119b60;
      }
    } while (pdVar8 != (dirent *)0x0);
    uVar9 = closedir(pDVar5);
    uVar9 = uVar9 | local_80;
    if (param_4 == 0) goto LAB_30119cd4;
    pcVar11 = DAT_30119f60;
    if (*pcVar12 != '\0') {
      pcVar11 = pcVar12;
    }
    pDVar5 = opendir(pcVar11);
    if (pDVar5 != (DIR *)0x0) {
      do {
        puVar7 = (undefined4 *)__errno();
        *puVar7 = 0;
        pdVar8 = readdir(pDVar5);
        if (pdVar8 == (dirent *)0x0) {
          piVar3 = (int *)__errno();
          if (*piVar3 == 0) break;
          puVar7 = (undefined4 *)__errno();
          fdprintf(param_1,DAT_3011ab98,pcVar12,*puVar7);
          uVar9 = 0xffffffff;
        }
        else if ((iVar2 == 0) || (iVar6 = FUN_301195e4(iVar2,&pdVar8->d_off,0), iVar6 != 0)) {
          FUN_30118f84(pcVar12,&pdVar8->d_off,__file);
          iVar6 = stat(__file,(stat *)auStack_74);
          if (iVar6 != 0) {
            bzero(auStack_74,0x48);
          }
          if ((((local_6c & 0xf000) == 0x4000) &&
              (iVar6 = memcmp(&pdVar8->d_off,DAT_3011a8a4,2), iVar6 != 0)) &&
             (iVar6 = memcmp(&pdVar8->d_off,DAT_3011ab94,3), iVar6 != 0)) {
            uVar9 = dirList(param_1,__file,param_3,param_4);
          }
        }
      } while (pdVar8 != (dirent *)0x0);
      uVar10 = closedir(pDVar5);
      uVar9 = uVar10 | uVar9;
      goto LAB_30119cd4;
    }
  }
  fdprintf(param_1,DAT_3011ab9c,param_2);
  uVar9 = 0xffffffff;
LAB_30119cd4:
  free(pcVar4);
  return uVar9;
}

/* ----------------------------------------------------------------
 * ls @ 0x30119CF0  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: dirList
 * Константы: 0x30119CF0
 * ---------------------------------------------------------------- */
void ls(undefined4 param_1,undefined4 param_2)

{
  dirList(1,param_1,param_2,0);
  return;
}

/* ----------------------------------------------------------------
 * ll @ 0x30119D04  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: dirList
 * Константы: 0x30119D04
 * ---------------------------------------------------------------- */
void ll(undefined4 param_1)

{
  dirList(1,param_1,1,0);
  return;
}

/* ----------------------------------------------------------------
 * lsr @ 0x30119D18  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: dirList
 * Константы: 0x30119D18
 * ---------------------------------------------------------------- */
void lsr(undefined4 param_1)

{
  dirList(1,param_1,0,1);
  return;
}

/* ----------------------------------------------------------------
 * llr @ 0x30119D2C  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: dirList
 * Константы: 0x30119D2C
 * ---------------------------------------------------------------- */
void llr(undefined4 param_1)

{
  dirList(1,param_1,1,1);
  return;
}

/* ----------------------------------------------------------------
 * cp @ 0x30119D40  (примерный размер ~624 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 17
 * Вызывает: FUN_30118ef8, FUN_30118f84, FUN_30118fec, FUN_3011904c, FUN_301195e4, __errno, closedir, copy, free, malloc, memcmp, opendir, perror, printErr
 *           ...
 * Константы: 0xFFFFFFFF, 0x30119D40
 * Данные: DAT_30119f60, DAT_3011a8a4, DAT_3011a8ac, DAT_3011ab94, DAT_3011acec, DAT_3011acf0, DAT_3011acf4, DAT_3011ae18
 * ---------------------------------------------------------------- */
uint cp(EVP_PKEY_CTX *param_1,EVP_PKEY_CTX *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  char *__dest;
  int iVar3;
  DIR *__dirp;
  dirent *pdVar4;
  uint uVar5;
  EVP_PKEY_CTX *src;
  EVP_PKEY_CTX *dst;
  char *local_2c;
  int local_28;
  
  uVar5 = 0;
  if (param_1 == (EVP_PKEY_CTX *)0x0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  else {
    if (param_2 == (EVP_PKEY_CTX *)0x0) {
      param_2 = DAT_30119f60;
    }
    __dest = (char *)malloc(0xc00);
    if (__dest == (char *)0x0) {
      uVar2 = 0xffffffff;
    }
    else {
      dst = (EVP_PKEY_CTX *)(__dest + 0x400);
      src = (EVP_PKEY_CTX *)(__dest + 0x800);
      strncpy(__dest,(char *)param_1,DAT_3011a8ac);
      FUN_3011904c(__dest,&local_2c,&local_28);
      if (local_28 == 0) {
        printErr(DAT_3011acec,param_1);
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 0x15;
        uVar2 = 0xffffffff;
      }
      else {
        iVar3 = FUN_30118fec(param_2);
        if (iVar3 == 0) {
          iVar3 = FUN_30118ef8(param_1);
          if (iVar3 == 0) {
            printf(DAT_3011acf4,param_1,param_2);
            uVar2 = copy(param_1,param_2);
          }
          else {
            printErr(DAT_3011acf0,param_2);
            puVar1 = (undefined4 *)__errno();
            *puVar1 = 0x14;
            uVar2 = 0xffffffff;
          }
        }
        else {
          iVar3 = FUN_30118ef8(local_28);
          if (iVar3 == 0) {
            FUN_30118f84(param_2,local_28,src);
            printf(DAT_3011acf4,param_1,src);
            uVar2 = copy(param_1,src);
          }
          else {
            __dirp = opendir(local_2c);
            if (__dirp == (DIR *)0x0) {
              perror(local_2c);
              uVar2 = 0xffffffff;
            }
            else {
              puVar1 = (undefined4 *)__errno();
              *puVar1 = 0;
              do {
                pdVar4 = readdir(__dirp);
                if (pdVar4 == (dirent *)0x0) break;
                if ((((local_28 == 0) ||
                     (iVar3 = FUN_301195e4(local_28,&pdVar4->d_off,0), iVar3 != 0)) &&
                    (iVar3 = memcmp(&pdVar4->d_off,DAT_3011a8a4,2), iVar3 != 0)) &&
                   (iVar3 = memcmp(&pdVar4->d_off,DAT_3011ab94,3), iVar3 != 0)) {
                  FUN_30118f84(local_2c,&pdVar4->d_off,dst);
                  FUN_30118f84(param_2,&pdVar4->d_off,src);
                  iVar3 = FUN_30118fec(dst);
                  if (iVar3 == 0) {
                    printf(DAT_3011acf4,dst,src);
                    uVar2 = copy(dst,src);
                    uVar5 = uVar2 | uVar5;
                  }
                  else {
                    printf(DAT_3011ae18,dst);
                  }
                }
              } while (pdVar4 != (dirent *)0x0);
              uVar2 = closedir(__dirp);
              uVar2 = uVar2 | uVar5;
            }
          }
        }
      }
      free(__dest);
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30119fb0 @ 0x30119FB0  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: close, errnoSet, ioctl, open
 * Вызывают: mv
 * Константы: 0x30119FB0
 * ---------------------------------------------------------------- */
int FUN_30119fb0(char *param_1,char *param_2)

{
  int __fd;
  int iVar1;
  
  if (((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {
    __fd = open(param_1,0,0);
    if (__fd == -1) {
      return -1;
    }
    iVar1 = ioctl(__fd,0x2f,param_2);
    close(__fd);
    return iVar1;
  }
  errnoSet(2);
  return -1;
}

/* ----------------------------------------------------------------
 * mv @ 0x3011A030  (примерный размер ~828 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 19
 * Вызывает: FUN_30118f30, FUN_30118f84, FUN_301190ec, FUN_301195e4, FUN_30119fb0, __errno, closedir, free, malloc, memcmp, opendir, perror, printErr, printf
 *           ...
 * Константы: 0xFFFFFFFF, 0x3011A030
 * Данные: DAT_3011a8a4, DAT_3011a8ac, DAT_3011ab94, DAT_3011ae1c, DAT_3011ae20, DAT_3011ae24, DAT_3011ae28, DAT_3011ae2c
 * ---------------------------------------------------------------- */
uint mv(char *param_1,char *param_2)

{
  char *__s;
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  size_t sVar6;
  size_t sVar7;
  DIR *__dirp;
  dirent *pdVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  char *__s_00;
  char *local_2c;
  char *local_28;
  
  uVar10 = 0;
  if (param_1 == (char *)0x0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    return 0xffffffff;
  }
  if (param_2 == (char *)0x0) {
    param_2 = DAT_3011ae1c;
  }
  iVar2 = FUN_30118f30(param_1);
  iVar3 = FUN_30118f30(param_2);
  if (iVar2 == 3) {
    printErr(DAT_3011ae20,param_1);
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 2;
    return 0xffffffff;
  }
  if (iVar3 == 2) {
    printErr(DAT_3011ae24,param_2);
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    return 0xffffffff;
  }
  if (iVar2 == 2) {
    if (iVar3 != 1) {
      printErr(DAT_3011ae28,param_2);
      puVar1 = (undefined4 *)__errno();
      *puVar1 = 0x16;
      return 0xffffffff;
    }
  }
  else {
    if (iVar2 == 1) {
      pcVar4 = DAT_3011ae34;
      if (iVar3 == 0) {
        printErr(DAT_3011ae2c);
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 0x16;
        return 0xffffffff;
      }
    }
    else {
      if (iVar2 != 0) goto LAB_3011a184;
      pcVar4 = DAT_3011ae30;
      if (iVar3 == 0) goto LAB_3011a164;
    }
    if (iVar3 == 3) {
LAB_3011a164:
      printf(pcVar4,param_1,param_2);
      uVar10 = FUN_30119fb0(param_1,param_2);
      return uVar10;
    }
  }
LAB_3011a184:
  pcVar4 = (char *)malloc(0xc00);
  if (pcVar4 == (char *)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    pcVar9 = pcVar4 + 0x400;
    __s_00 = pcVar4 + 0x800;
    strncpy(pcVar4,param_1,DAT_3011a8ac);
    local_28 = (char *)0x0;
    local_2c = (char *)0x0;
    FUN_301190ec(pcVar4,&local_2c,&local_28);
    __s = local_28;
    pcVar11 = local_2c;
    if (local_28 == (char *)0x0) {
      puts(DAT_3011ae38);
      uVar5 = 0x16;
    }
    else {
      if ((iVar2 == 0) || (iVar2 == 1)) {
        sVar6 = strlen(param_2);
        sVar7 = strlen(__s);
        if (0x3ff < sVar7 + sVar6 + 2) {
          return 0x1a;
        }
        sprintf(__s_00,DAT_3011ae3c,param_2,__s);
        pcVar11 = DAT_3011ae30;
        if (iVar2 != 0) {
          pcVar11 = DAT_3011ae34;
        }
        printf(pcVar11,param_1,param_2);
        uVar5 = FUN_30119fb0(param_1,__s_00);
      }
      else {
        __dirp = opendir(local_2c);
        if (__dirp == (DIR *)0x0) {
          perror(pcVar11);
          uVar5 = 0xffffffff;
        }
        else {
          puVar1 = (undefined4 *)__errno();
          *puVar1 = 0;
          while (pdVar8 = readdir(__dirp), pdVar8 != (dirent *)0x0) {
            if ((((__s == (char *)0x0) || (iVar2 = FUN_301195e4(__s,&pdVar8->d_off,0), iVar2 != 0))
                && (iVar2 = memcmp(&pdVar8->d_off,DAT_3011a8a4,2), iVar2 != 0)) &&
               (iVar2 = memcmp(&pdVar8->d_off,DAT_3011ab94,3), iVar2 != 0)) {
              FUN_30118f84(pcVar11,&pdVar8->d_off,pcVar9);
              FUN_30118f84(param_2,&pdVar8->d_off,__s_00);
              printf(DAT_3011ae30,pcVar9,__s_00);
              uVar5 = FUN_30119fb0(pcVar9,__s_00);
              uVar10 = uVar5 | uVar10;
            }
          }
          uVar5 = closedir(__dirp);
          uVar5 = uVar5 | uVar10;
        }
      }
      free(pcVar4);
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * xcopy @ 0x3011A36C  (примерный размер ~564 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 18
 * Вызывает: FUN_30118ef8, FUN_30118f84, FUN_30118fec, FUN_3011904c, FUN_301195e4, __errno, closedir, copy, free, malloc, memcmp, mkdir, opendir, perror
 *           ...
 * Константы: 0xFFFFFFFF, 0x3011A36C
 * Данные: DAT_3011a8a4, DAT_3011a8ac, DAT_3011ab94, DAT_3011acf4, DAT_3011ae40, DAT_3011ae44, DAT_3011ae48
 * ---------------------------------------------------------------- */
uint xcopy(EVP_PKEY_CTX *param_1,EVP_PKEY_CTX *param_2)

{
  char *__dest;
  uint uVar1;
  int iVar2;
  DIR *__dirp;
  undefined4 *puVar3;
  dirent *pdVar4;
  uint uVar5;
  EVP_PKEY_CTX *src;
  EVP_PKEY_CTX *dst;
  undefined8 uVar6;
  char *local_2c;
  int local_28;
  
  uVar5 = 0;
  __dest = (char *)malloc(0xc00);
  if (__dest == (char *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    dst = (EVP_PKEY_CTX *)(__dest + 0x400);
    src = (EVP_PKEY_CTX *)(__dest + 0x800);
    strncpy(__dest,(char *)param_1,DAT_3011a8ac);
    FUN_3011904c(__dest,&local_2c,&local_28);
    if ((local_28 == 0) || (iVar2 = FUN_30118ef8(local_28), iVar2 != 0)) {
      __dirp = opendir(local_2c);
      if (__dirp == (DIR *)0x0) {
        perror(local_2c);
        free(__dest);
        return 0xffffffff;
      }
      uVar6 = FUN_30118fec(param_2);
      if ((int)uVar6 == 0) {
        iVar2 = mkdir((char *)param_2,(__mode_t)((ulonglong)uVar6 >> 0x20));
        if (iVar2 == -1) {
          closedir(__dirp);
          printErr(DAT_3011ae40,param_2);
          free(__dest);
          puVar3 = (undefined4 *)__errno();
          *puVar3 = 0x14;
          return 0xffffffff;
        }
        printf(DAT_3011ae44,param_2);
      }
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0;
      while (pdVar4 = readdir(__dirp), pdVar4 != (dirent *)0x0) {
        if ((local_28 == 0) || (iVar2 = FUN_301195e4(local_28,&pdVar4->d_off,0), iVar2 != 0)) {
          FUN_30118f84(local_2c,&pdVar4->d_off,dst);
          FUN_30118f84(param_2,&pdVar4->d_off,src);
          iVar2 = FUN_30118fec(dst);
          if (iVar2 == 0) {
            printf(DAT_3011acf4,dst,src);
            uVar1 = copy(dst,src);
            uVar5 = uVar1 | uVar5;
          }
          else {
            iVar2 = memcmp(&pdVar4->d_off,DAT_3011a8a4,2);
            if ((iVar2 != 0) && (iVar2 = memcmp(&pdVar4->d_off,DAT_3011ab94,3), iVar2 != 0)) {
              printf(DAT_3011ae48,dst,src);
              uVar1 = xcopy(dst,src);
              uVar5 = uVar1 | uVar5;
            }
          }
        }
      }
      uVar1 = closedir(__dirp);
      uVar1 = uVar1 | uVar5;
    }
    else {
      printf(DAT_3011acf4,param_1,param_2);
      uVar1 = copy(param_1,param_2);
    }
    free(__dest);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3011a5a0 @ 0x3011A5A0  (примерный размер ~544 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 14
 * Вызывает: FUN_30118fec, FUN_301195e4, __errno, closedir, memcmp, opendir, perror, printf, readdir, rmdir, strcpy, strerror, strlen, unlink
 * Вызывают: xdelete
 * Константы: 0xFFFFFFFF, 0x3011A5A0
 * Данные: DAT_3011ab94, DAT_3011ae4c, DAT_3011ae50, DAT_3011ae54, DAT_3011ae58
 * ---------------------------------------------------------------- */
uint FUN_3011a5a0(char *param_1,int param_2)

{
  DIR *__dirp;
  size_t sVar1;
  dirent *pdVar2;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  int *piVar6;
  char *pcVar7;
  uint uVar8;
  char *__dest;
  uint uVar9;
  
  uVar9 = 0;
  __dirp = opendir(param_1);
  if (__dirp == (DIR *)0x0) {
    perror(param_1);
    uVar9 = 0xffffffff;
  }
  else {
    sVar1 = strlen(param_1);
    __dest = param_1 + sVar1;
    if (__dest[-1] != '/') {
      *__dest = '/';
      __dest = __dest + 1;
      sVar1 = sVar1 + 1;
    }
    do {
      pdVar2 = readdir(__dirp);
      if (pdVar2 == (dirent *)0x0) break;
      if ((param_2 == 0) || (iVar3 = FUN_301195e4(param_2,&pdVar2->d_off,0), iVar3 != 0)) {
        sVar4 = strlen((char *)&pdVar2->d_off);
        if (sVar1 + sVar4 < 0x400) {
          strcpy(__dest,(char *)&pdVar2->d_off);
          iVar3 = FUN_30118fec(param_1);
          if (iVar3 == 0) {
            printf(DAT_3011ae54,param_1);
            uVar8 = unlink(param_1);
            if (uVar8 != 0) {
              perror(param_1);
            }
            uVar9 = uVar9 | uVar8;
          }
          else if (((char)pdVar2->d_off != '.') ||
                  ((sVar4 != 1 && (iVar3 = memcmp(&pdVar2->d_off,DAT_3011ab94,3), iVar3 != 0)))) {
            closedir(__dirp);
            uVar8 = FUN_3011a5a0(param_1,0);
            if (uVar8 != 0) goto LAB_3011a7ac;
            __dest[-1] = '\0';
            __dirp = opendir(param_1);
            if (__dirp == (DIR *)0x0) {
              piVar6 = (int *)__errno();
              pcVar7 = strerror(*piVar6);
              printf(DAT_3011ae50,param_1,pcVar7);
              uVar9 = 0xffffffff;
            }
            __dest[-1] = '/';
          }
        }
        else {
          printf(DAT_3011ae4c,param_1,&pdVar2->d_off);
          puVar5 = (undefined4 *)__errno();
          *puVar5 = 0x1a;
          uVar9 = 0xffffffff;
        }
      }
    } while (__dirp != (DIR *)0x0);
    if (__dirp != (DIR *)0x0) {
      closedir(__dirp);
    }
    if (param_2 == 0) {
      __dest[-1] = '\0';
      printf(DAT_3011ae58,param_1);
      uVar8 = rmdir(param_1);
      if (uVar8 != 0) {
        perror(param_1);
      }
LAB_3011a7ac:
      uVar9 = uVar9 | uVar8;
    }
  }
  return uVar9;
}

/* ----------------------------------------------------------------
 * xdelete @ 0x3011A7C0  (примерный размер ~288 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 12
 * Вызывает: FUN_30118ef8, FUN_3011904c, FUN_3011a5a0, __errno, free, malloc, perror, printf, strcpy, strerror, strncpy, unlink
 * Вызывают: dynFSFirstPacketHandle, update_WebUITask, yaffsFormat
 * Константы: 0x3011A7C0
 * Данные: DAT_3011a8ac, DAT_3011ae54, DAT_3011ae5c
 * ---------------------------------------------------------------- */
int xdelete(char *param_1)

{
  size_t sVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  int local_1c;
  char *local_18;
  
  pcVar2 = (char *)malloc(0x800);
  sVar1 = DAT_3011a8ac;
  if (pcVar2 == (char *)0x0) {
    piVar3 = (int *)__errno();
    pcVar2 = strerror(*piVar3);
    printf(DAT_3011ae5c,pcVar2);
    iVar4 = -1;
  }
  else {
    strncpy(pcVar2,param_1,DAT_3011a8ac);
    pcVar2[sVar1] = '\0';
    FUN_3011904c(pcVar2,&local_18,&local_1c);
    if ((local_1c == 0) || (iVar4 = FUN_30118ef8(local_1c), iVar4 != 0)) {
      strcpy(pcVar2 + 0x400,local_18);
      iVar4 = FUN_3011a5a0(pcVar2 + 0x400,local_1c);
    }
    else {
      printf(DAT_3011ae54,param_1);
      iVar4 = unlink(param_1);
      if (iVar4 != 0) {
        perror(param_1);
      }
    }
    free(pcVar2);
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * attrib @ 0x3011A8E0  (примерный размер ~392 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: __errno, close, fstat, ioctl, open, perror, printErr
 * Вызывают: xattrib
 * Константы: 0x3011A8E0
 * Данные: DAT_3011ae60, DAT_3011ae64
 * ---------------------------------------------------------------- */
int attrib(char *param_1,byte *param_2)

{
  byte bVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int __fd;
  byte bVar5;
  byte local_2c;
  
  bVar2 = true;
  bVar5 = 0;
  if (param_2 == (byte *)0x0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 0x16;
    iVar4 = -1;
  }
  else {
    __fd = open(param_1,0,0);
    if (__fd == -1) {
      perror(param_1);
      iVar4 = -1;
    }
    else {
      iVar4 = fstat(__fd,(stat *)&stack0xffffffa0);
      if (iVar4 == -1) {
        printErr(DAT_3011ae60,param_1);
        iVar4 = -1;
      }
      else {
        bVar1 = *param_2;
        while (bVar1 != 0) {
          bVar1 = *param_2;
          if (bVar1 == 0x53) {
LAB_3011a9f0:
            bVar5 = 4;
LAB_3011aa14:
            if (!bVar2) goto LAB_3011aa28;
LAB_3011aa1c:
            local_2c = bVar5 | local_2c;
          }
          else {
            if (0x53 < bVar1) {
              if (bVar1 == 0x61) goto LAB_3011a9e8;
              if (bVar1 == 0x68) {
LAB_3011a9f8:
                bVar5 = 2;
              }
              else {
                if (bVar1 != 0x72) {
                  if (bVar1 != 0x73) goto LAB_3011aa08;
                  goto LAB_3011a9f0;
                }
LAB_3011aa00:
                bVar5 = 1;
              }
              goto LAB_3011aa14;
            }
            if (bVar1 == 0x41) {
LAB_3011a9e8:
              bVar5 = 0x20;
              goto LAB_3011aa14;
            }
            if (0x41 < bVar1) {
              if (bVar1 == 0x48) goto LAB_3011a9f8;
              if (bVar1 == 0x52) goto LAB_3011aa00;
LAB_3011aa08:
              printErr(DAT_3011ae64,bVar1);
              goto LAB_3011aa14;
            }
            if (bVar1 == 0x2b) {
              bVar2 = true;
              goto LAB_3011aa1c;
            }
            if (bVar1 != 0x2d) goto LAB_3011aa08;
            bVar2 = false;
LAB_3011aa28:
            local_2c = local_2c & ~bVar5;
          }
          param_2 = param_2 + 1;
          bVar1 = *param_2;
        }
        iVar4 = ioctl(__fd,0x23,(uint)local_2c);
        close(__fd);
      }
    }
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * xattrib @ 0x3011AA68  (примерный размер ~452 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 16
 * Вызывает: FUN_30118ef8, FUN_30118f84, FUN_30118fec, FUN_3011904c, FUN_301195e4, __errno, attrib, closedir, free, malloc, memcmp, opendir, perror, printf
 *           ...
 * Константы: 0xFFFFFFFF, 0x3011AA68
 * Данные: DAT_3011ae68, DAT_3011ae6c, DAT_3011ae70, DAT_3011ae74, DAT_3011ae78
 * ---------------------------------------------------------------- */
uint xattrib(char *param_1,undefined4 param_2)

{
  char *__dest;
  uint uVar1;
  int iVar2;
  DIR *__dirp;
  undefined4 *puVar3;
  uint uVar4;
  dirent *pdVar5;
  uint uVar6;
  char *pcVar7;
  char *local_28;
  int local_24;
  
  uVar6 = 0;
  __dest = (char *)malloc(0x800);
  if (__dest == (char *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    pcVar7 = __dest + 0x400;
    strncpy(__dest,param_1,DAT_3011ae68);
    FUN_3011904c(__dest,&local_28,&local_24);
    if ((local_24 == 0) || (iVar2 = FUN_30118ef8(local_24), iVar2 != 0)) {
      __dirp = opendir(local_28);
      if (__dirp == (DIR *)0x0) {
        perror(local_28);
        free(__dest);
        return 0xffffffff;
      }
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0;
LAB_3011abfc:
      pdVar5 = readdir(__dirp);
      if (pdVar5 != (dirent *)0x0) {
        if ((local_24 == 0) || (iVar2 = FUN_301195e4(local_24,&pdVar5->d_off,0), iVar2 != 0)) {
          FUN_30118f84(local_28,&pdVar5->d_off,pcVar7);
          iVar2 = FUN_30118fec(pcVar7);
          if (iVar2 == 0) {
            printf(DAT_3011ae6c,pcVar7);
            uVar1 = attrib(pcVar7,param_2);
            uVar6 = uVar1 | uVar6;
          }
          else {
            iVar2 = memcmp(&pdVar5->d_off,DAT_3011ae70,2);
            if ((iVar2 == 0) || (iVar2 = memcmp(&pdVar5->d_off,DAT_3011ae74,3), iVar2 == 0))
            goto LAB_3011abfc;
          }
          printf(DAT_3011ae78,pcVar7);
          uVar1 = xattrib(pcVar7,param_2);
          uVar4 = attrib(pcVar7,param_2);
          uVar6 = uVar4 | uVar1 | uVar6;
        }
        goto LAB_3011abfc;
      }
      uVar1 = closedir(__dirp);
      uVar1 = uVar1 | uVar6;
    }
    else {
      printf(DAT_3011ae6c,param_1);
      uVar1 = attrib(param_1,param_2);
    }
    free(__dest);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * dosfsDiskFormat @ 0x3011AC2C  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: __errno, printErr
 * Вызывают: diskFormat
 * Константы: 0x3011AC2C, 0xFFFFFFFF
 * Данные: DAT_3011ae7c, DAT_3011ae80
 * ---------------------------------------------------------------- */
undefined4 dosfsDiskFormat(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((code *)*DAT_3011ae7c == (code *)0x0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x47;
    printErr(DAT_3011ae80);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (*(code *)*DAT_3011ae7c)(param_1,0,0);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * diskFormat @ 0x3011AC74  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: dosfsDiskFormat, puts
 * Константы: 0x3011AC74
 * Данные: DAT_3011ae84, DAT_3011ae88
 * ---------------------------------------------------------------- */
void diskFormat(undefined4 param_1)

{
  puts(DAT_3011ae84);
  puts(DAT_3011ae88);
  dosfsDiskFormat(param_1);
  return;
}

/* ----------------------------------------------------------------
 * hrfsDiskFormat @ 0x3011AC98  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, printErr
 * Константы: 0x3011AC98, 0xFFFFFFFF
 * Данные: DAT_3011ae8c, DAT_3011ae90
 * ---------------------------------------------------------------- */
undefined4
hrfsDiskFormat(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((code *)*DAT_3011ae8c == (code *)0x0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x47;
    printErr(DAT_3011ae90);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (*(code *)*DAT_3011ae8c)(param_1,0,0,0,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * diskInit @ 0x3011AD18  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: puts
 * Константы: 0x3011AD18, 0xFFFFFFFF
 * Данные: DAT_3011ae94, DAT_3011ae98
 * ---------------------------------------------------------------- */
undefined4 diskInit(void)

{
  puts(DAT_3011ae94);
  puts(DAT_3011ae98);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * commit @ 0x3011AD34  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: close, ioctl, open
 * Константы: 0x3011AD34
 * Данные: DAT_3011ae9c
 * ---------------------------------------------------------------- */
int commit(char *param_1)

{
  int __fd;
  int iVar1;
  
  __fd = open(param_1,0x80000,DAT_3011ae9c);
  if (__fd < 0) {
    return -1;
  }
  iVar1 = ioctl(__fd,0x38,0);
  close(__fd);
  return iVar1;
}

/* ----------------------------------------------------------------
 * help @ 0x3011AEAC  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: __rem32, fioRdString, printf, puts
 * Константы: 0x3011AEAC
 * Данные: DAT_3011be60, DAT_3011be64, DAT_3011be68
 * ---------------------------------------------------------------- */
void help(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char local_10 [4];
  
  puts(DAT_3011be60);
  iVar2 = 0;
  iVar3 = *DAT_3011be64;
  piVar1 = DAT_3011be64;
  while (iVar3 != 0) {
    iVar3 = __rem32(iVar2 + 1,0x14);
    if (iVar3 == 0) {
      printf(DAT_3011be68);
      fioRdString(0,local_10,1);
      if ((local_10[0] == 'q') || (local_10[0] == 'Q')) break;
      puts(DAT_3011be60);
    }
    puts((char *)*piVar1);
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + 1;
    iVar3 = *piVar1;
  }
  puts(DAT_3011be60);
  return;
}

/* ----------------------------------------------------------------
 * netHelp @ 0x3011AF44  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: __rem32, fioRdString, printf, puts
 * Константы: 0x3011AF44
 * Данные: DAT_3011be60, DAT_3011be68, DAT_3011be6c, DAT_3011be70
 * ---------------------------------------------------------------- */
void netHelp(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char local_10 [4];
  
  puts(DAT_3011be6c);
  iVar2 = 0;
  iVar3 = *DAT_3011be70;
  piVar1 = DAT_3011be70;
  while (iVar3 != 0) {
    iVar3 = __rem32(iVar2 + 1,0x14);
    if (iVar3 == 0) {
      printf(DAT_3011be68);
      fioRdString(0,local_10,1);
      if ((local_10[0] == 'q') || (local_10[0] == 'Q')) break;
      puts(DAT_3011be60);
    }
    puts((char *)*piVar1);
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + 1;
    iVar3 = *piVar1;
  }
  puts(DAT_3011be60);
  return;
}

/* ----------------------------------------------------------------
 * tw @ 0x3011B0F0  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: printErr, shellTaskIdDefault, taskIdFigure, taskIdVerify, taskWaitShowCoreRtn
 * Константы: 0x3011B0F0
 * Данные: DAT_3011bf98, DAT_3011c0c0, DAT_3011c0c4
 * ---------------------------------------------------------------- */
void tw(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = taskIdFigure();
  if ((iVar1 == -1) || (iVar2 = taskIdVerify(iVar1), iVar2 != 0)) {
    if (param_1 == 0) {
      printErr(DAT_3011c0c4,*DAT_3011c0c0);
    }
    else {
      printErr(*DAT_3011bf98,DAT_3011bf98[2]);
    }
  }
  else {
    uVar3 = shellTaskIdDefault(0,iVar1);
    taskWaitShowCoreRtn(0,1,uVar3,*DAT_3011c0c0);
  }
  return;
}

/* ----------------------------------------------------------------
 * shConfig @ 0x3011B17C  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: free, printErr, puts, shellConfigGet, shellConfigSet
 * Константы: 0x3011B17C
 * Данные: DAT_3011c0c8, DAT_3011c0cc
 * ---------------------------------------------------------------- */
void shConfig(int param_1)

{
  char *__s;
  int iVar1;
  
  if (param_1 == 0) {
    __s = (char *)shellConfigGet(0);
    if (__s == (char *)0x0) {
      puts(DAT_3011c0c8);
    }
    else {
      puts(__s);
      free(__s);
    }
  }
  else {
    iVar1 = shellConfigSet(0,param_1);
    if (iVar1 == 0) {
      return;
    }
    printErr(DAT_3011c0cc);
  }
  return;
}

/* ----------------------------------------------------------------
 * strFree @ 0x3011B1E0  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: printErr, shellMemStringFree, shellMemStringShow
 * Константы: 0x3011B1E0
 * Данные: DAT_3011c0d0
 * ---------------------------------------------------------------- */
void strFree(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    shellMemStringShow(0);
  }
  else {
    iVar1 = shellMemStringFree(0,param_1);
    if (iVar1 == 0) {
      return;
    }
    printErr(DAT_3011c0d0,param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * bootChange @ 0x3011B220  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: bootParamsPrompt, strlen, sysNvRamSet
 * Константы: 0x3011B220
 * Данные: DAT_3011c0d4
 * ---------------------------------------------------------------- */
void bootChange(void)

{
  size_t sVar1;
  char *__s;
  
  bootParamsPrompt(*DAT_3011c0d4);
  __s = (char *)*DAT_3011c0d4;
  sVar1 = strlen(__s);
  sysNvRamSet(__s,sVar1 + 1,0);
  return;
}

/* ----------------------------------------------------------------
 * periodRun @ 0x3011B254  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: sysClkRateGet, taskDelay
 * Константы: 0x3011B254
 * ---------------------------------------------------------------- */
void periodRun(int param_1,code *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
              undefined4 param_10)

{
  int iVar1;
  
  do {
    (*param_2)(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
    iVar1 = sysClkRateGet();
    taskDelay(param_1 * iVar1);
  } while( true );
}

/* ----------------------------------------------------------------
 * sp @ 0x3011B2C0  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 7
 * Вызывает: __errno, printErr, printf, shellOutputLock, shellOutputUnlock, taskName, taskSpawn
 * Вызывают: period, repeat
 * Константы: 0x3011B2C0
 * Данные: DAT_3011c258, DAT_3011c25c, DAT_3011c260, DAT_3011c264, DAT_3011c268, DAT_3011c26c
 * ---------------------------------------------------------------- */
int sp(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
      undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
      undefined4 param_10)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    printErr(DAT_3011c258);
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    iVar2 = -1;
  }
  else {
    iVar2 = taskSpawn(0,*DAT_3011c25c,*DAT_3011c260,*DAT_3011c264,param_1,param_2,param_3,param_4,
                      param_5,param_6,param_7,param_8,param_9,param_10,0);
    if (iVar2 == -1) {
      printErr(DAT_3011c268);
      iVar2 = -1;
    }
    else {
      shellOutputLock(0);
      uVar3 = taskName(iVar2);
      printf(DAT_3011c26c,iVar2,uVar3);
      shellOutputUnlock(0);
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * period @ 0x3011B3B0  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: sp
 * Константы: 0x3011B3B0
 * Данные: DAT_3011c370
 * ---------------------------------------------------------------- */
void period(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
           undefined4 param_9)

{
  sp(DAT_3011c370,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}

/* ----------------------------------------------------------------
 * repeatRun @ 0x3011B404  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011B404
 * ---------------------------------------------------------------- */
void repeatRun(int param_1,code *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
              undefined4 param_10)

{
  bool bVar1;
  
  if (param_1 == 0) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  while ((bVar1 || (param_1 = param_1 + -1, -1 < param_1))) {
    (*param_2)(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  }
  return;
}

/* ----------------------------------------------------------------
 * repeat @ 0x3011B48C  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: sp
 * Константы: 0x3011B48C
 * Данные: DAT_3011c374
 * ---------------------------------------------------------------- */
void repeat(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
           undefined4 param_9)

{
  sp(DAT_3011c374,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3011b4e0 @ 0x3011B4E0  (примерный размер ~452 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 9
 * Вызывает: cplusDemangle, free, printErr, printf, puts, shellInternalSymTblFromTaskGet, symByValueAndTypeFind, taskIdFigure, taskInfoGet
 * Вызывают: checkStack
 * Константы: 0x3011B4E0
 * Данные: DAT_3011be60, DAT_3011bf98, DAT_3011c4b8, DAT_3011c4bc, DAT_3011c4c0, DAT_3011c4c4, DAT_3011c4c8, DAT_3011c4cc
 * ---------------------------------------------------------------- */
undefined4 FUN_3011b4e0(undefined4 param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_1ac [4];
  void *local_1a8;
  int local_1a4;
  undefined4 local_1a0 [3];
  uint local_194;
  int local_190;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  int local_174;
  undefined1 auStack_15c [36];
  undefined4 local_138;
  undefined4 local_128;
  int local_124;
  undefined4 local_120;
  undefined1 auStack_114 [260];
  
  iVar3 = -1;
  local_1a8 = (void *)0x0;
  local_1a4 = 0;
  iVar1 = taskIdFigure();
  if ((iVar1 == -1) || (iVar1 = taskInfoGet(iVar1,local_1a0), iVar1 != 0)) {
    if (param_2 != 0) {
      printErr(*DAT_3011bf98,DAT_3011c4b8);
    }
  }
  else {
    if (param_2 != 0) {
      puts(DAT_3011c4bc);
    }
    iVar1 = shellInternalSymTblFromTaskGet(local_1a0[0],local_190);
    if (iVar1 != 0) {
      iVar3 = symByValueAndTypeFind(iVar1,local_190,&local_1a8,&local_1a4,auStack_1ac,0,0);
    }
    printf(DAT_3011c4c0,auStack_15c);
    __format = DAT_3011c4cc;
    if ((iVar3 == 0) && (local_190 == local_1a4)) {
      local_190 = cplusDemangle(local_1a8,auStack_114,DAT_3011c4c4);
      __format = DAT_3011c4c8;
    }
    printf(__format,local_190);
    free(local_1a8);
    printf(DAT_3011c4d0,local_1a0[0],local_180,local_17c);
    if ((local_194 & 0x100) == 0) {
      uVar2 = DAT_3011c4dc;
      if (0 < local_174) {
        uVar2 = DAT_3011be60;
      }
      printf(DAT_3011c4e0,local_178,local_174,uVar2);
    }
    else {
      printf(DAT_3011c4d8,DAT_3011c4d4,DAT_3011c4d4);
    }
    printf(DAT_3011c4e4,DAT_3011c4e8,local_138,local_120);
    if ((local_194 & 0x100) == 0) {
      uVar2 = DAT_3011c4dc;
      if (0 < local_124) {
        uVar2 = DAT_3011be60;
      }
      printf(DAT_3011c4e0,local_128,local_124,uVar2);
    }
    else {
      printf(DAT_3011c4d8,DAT_3011c4d4,DAT_3011c4d4);
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * checkStack @ 0x3011B6A4  (примерный размер ~328 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 7
 * Вызывает: FUN_3011b4e0, printf, puts, taskEach, taskIdListGet, taskIdListSort, taskListCount
 * Константы: 0x3011B6A4
 * Данные: DAT_3011be60, DAT_3011c4bc, DAT_3011c4dc, DAT_3011c5d4, DAT_3011c5d8, DAT_3011c5dc, DAT_3011c5e0, DAT_3011c5e4
 * ---------------------------------------------------------------- */
void checkStack(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  
  iVar1 = -DAT_3011c5d4;
  if (param_1 == 0) {
    puts(DAT_3011c4bc);
    iVar2 = taskListCount(*DAT_3011c5d8);
    if (iVar2 < 0x1f5) {
      iVar2 = taskIdListGet(&stack0xfffffff8 + iVar1,500);
      taskIdListSort(&stack0xfffffff8 + iVar1,iVar2);
      if (0 < iVar2) {
        puVar6 = (undefined4 *)(&stack0xfffffff4 + iVar1);
        do {
          puVar6 = puVar6 + 1;
          FUN_3011b4e0(*puVar6,0);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    else {
      printf(DAT_3011c5dc,500);
      uVar5 = DAT_3011c5e0;
      taskEach(DAT_3011c5e0,0,0);
      taskEach(uVar5,0,1);
    }
    pcVar4 = (char *)*DAT_3011c5e4;
    pcVar3 = (char *)*DAT_3011c5e8;
    for (pcVar7 = pcVar3; (pcVar7 < pcVar4 && (*pcVar7 == -0x12)); pcVar7 = pcVar7 + 1) {
    }
    printf(DAT_3011c5ec,DAT_3011c5f0,DAT_3011be60);
    uVar5 = DAT_3011be60;
    if ((pcVar7 == pcVar3) && (pcVar3 != pcVar4)) {
      uVar5 = DAT_3011c4dc;
    }
    *(int *)(&stack0xffffffec + iVar1) = (int)pcVar4 - (int)pcVar7;
    *(int *)(&stack0xfffffff0 + iVar1) = (int)pcVar7 - (int)pcVar3;
    *(undefined4 *)(&stack0xfffffff4 + iVar1) = uVar5;
    printf(DAT_3011c71c,DAT_3011be60,(int)pcVar4 - (int)pcVar3,0);
  }
  else {
    FUN_3011b4e0(param_1,1);
  }
  return;
}

/* ----------------------------------------------------------------
 * objectShow @ 0x3011B7EC  (примерный размер ~320 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 4
 * Вызывает: __errno, objShow, printErr, vxMemProbe
 * Вызывают: FUN_300f5e28, FUN_3011b934, show, ti
 * Константы: 0xFFFFFFFF, 0x3011B7EC
 * Данные: DAT_3011c720, DAT_3011c724, DAT_3011c728, DAT_3011c72c, DAT_3011c7e8
 * ---------------------------------------------------------------- */
undefined4 objectShow(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined1 auStack_14 [4];
  
  if ((param_1 & 1) == 0) {
    iVar1 = vxMemProbe(param_1,0,4,auStack_14);
    if ((iVar1 == -1) || (iVar1 = vxMemProbe(param_1 + 0x30,0,4,auStack_14), iVar1 == -1)) {
      printErr(DAT_3011c724,param_3,param_1);
      return 0xffffffff;
    }
    iVar1 = objShow(param_1,param_2);
    if (iVar1 != 0) {
      piVar2 = (int *)__errno();
      if (*piVar2 == DAT_3011c7e8) {
        printErr(DAT_3011c72c,param_3);
      }
      else {
        printErr(DAT_3011c724,param_3,param_1);
      }
      return 0xffffffff;
    }
  }
  else {
    iVar1 = vxMemProbe(param_1 + *DAT_3011c720,0,4,auStack_14);
    if (iVar1 == -1) {
      printErr(DAT_3011c724,param_3,param_1);
      return 0xffffffff;
    }
    if ((code *)*DAT_3011c728 == (code *)0x0) {
      printErr(DAT_3011c72c,param_3);
      return 0xffffffff;
    }
    (*(code *)*DAT_3011c728)(param_1,param_2);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * show @ 0x3011B92C  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: objectShow
 * Константы: 0x3011B92C
 * Данные: DAT_3011c7ec
 * ---------------------------------------------------------------- */
void show(undefined4 param_1,undefined4 param_2)

{
  objectShow(param_1,param_2,DAT_3011c7ec);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3011b934 @ 0x3011B934  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: objectShow, printErr, taskIdFigure, taskIdSelf, taskIdVerify
 * Константы: 0x3011B934
 * Данные: DAT_3011bf98, DAT_3011c7ec, DAT_3011c7f0
 * ---------------------------------------------------------------- */
void FUN_3011b934(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    iVar1 = taskIdSelf();
    uVar3 = 2;
  }
  else {
    iVar1 = taskIdFigure(param_1);
    if ((iVar1 == -1) || (iVar2 = taskIdVerify(iVar1), iVar2 != 0)) {
      printErr(*DAT_3011bf98,DAT_3011c7f0);
      return;
    }
    uVar3 = 0;
  }
  objectShow(iVar1,uVar3,DAT_3011c7ec);
  return;
}

/* ----------------------------------------------------------------
 * ti @ 0x3011B99C  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: objectShow, printErr, shellTaskIdDefault, taskIdFigure, taskIdVerify
 * Константы: 0x3011B99C
 * Данные: DAT_3011bf98, DAT_3011c7ec, DAT_3011c8b0
 * ---------------------------------------------------------------- */
void ti(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = taskIdFigure();
  if ((iVar1 == -1) || (iVar2 = taskIdVerify(iVar1), iVar2 != 0)) {
    printErr(*DAT_3011bf98,DAT_3011c8b0);
  }
  else {
    uVar3 = shellTaskIdDefault(0,iVar1);
    objectShow(uVar3,1,DAT_3011c7ec);
  }
  return;
}

/* ----------------------------------------------------------------
 * printErrno @ 0x3011B9F0  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 5
 * Вызывает: errnoGet, free, printf, puts, symByValueAndTypeFind
 * Вызывают: FUN_3010c16c, td, tr, ts
 * Константы: 0x3011B9F0
 * Данные: DAT_3011c8b4, DAT_3011c8b8, DAT_3011c8bc, DAT_3011c8c0, DAT_3011c8c4, DAT_3011c9bc, DAT_3011c9c0
 * ---------------------------------------------------------------- */
void printErrno(void *param_1)

{
  int iVar1;
  char *__format;
  undefined1 auStack_18 [4];
  void *local_14;
  void *local_10;
  
  if ((param_1 == (void *)0x0) && (param_1 = (void *)errnoGet(), param_1 == (void *)0x0)) {
    puts(DAT_3011c8b4);
  }
  else if (*DAT_3011c8b8 == 0) {
    printf(DAT_3011c8bc,param_1);
  }
  else {
    local_14 = (void *)0x0;
    local_10 = (void *)0x0;
    iVar1 = symByValueAndTypeFind(*DAT_3011c8b8,param_1,&local_14,&local_10,auStack_18,0,0);
    __format = DAT_3011c8c0;
    if ((local_10 != param_1) ||
       (printf(DAT_3011c8c4,param_1), __format = DAT_3011c9bc, param_1 = local_14, iVar1 != -1)) {
      printf(__format,param_1);
    }
    puts(DAT_3011c9c0);
    free(local_14);
  }
  return;
}

/* ----------------------------------------------------------------
 * ts @ 0x3011BABC  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: printErr, printErrno, puts, taskIdFigure, taskSuspend
 * Константы: 0x3011BABC
 * Данные: DAT_3011bf98, DAT_3011c9c4, DAT_3011c9c8, DAT_3011c9cc
 * ---------------------------------------------------------------- */
void ts(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = taskIdFigure();
  if (iVar1 == -1) {
    printErr(*DAT_3011bf98,DAT_3011c9c4);
  }
  else if (iVar1 == 0) {
    puts(DAT_3011c9c8);
  }
  else {
    iVar2 = taskSuspend(iVar1);
    if (iVar2 == 0) {
      return;
    }
    printErr(DAT_3011c9cc,iVar1);
    printErrno(0);
  }
  return;
}

/* ----------------------------------------------------------------
 * tr @ 0x3011BB20  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: printErr, printErrno, taskIdFigure, taskResume
 * Константы: 0x3011BB20
 * Данные: DAT_3011bf98, DAT_3011c9d0, DAT_3011c9d4
 * ---------------------------------------------------------------- */
void tr(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = taskIdFigure();
  if (iVar1 == -1) {
    printErr(*DAT_3011bf98,DAT_3011c9d0);
  }
  else {
    iVar2 = taskResume(iVar1);
    if (iVar2 == 0) {
      return;
    }
    printErr(DAT_3011c9d4,iVar1);
    printErrno(0);
  }
  return;
}

/* ----------------------------------------------------------------
 * td @ 0x3011BB70  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: printErr, printErrno, taskDelete, taskIdFigure
 * Константы: 0x3011BB70
 * Данные: DAT_3011bf98, DAT_3011c9d8, DAT_3011c9dc, DAT_3011c9e0
 * ---------------------------------------------------------------- */
void td(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = taskIdFigure();
  if (iVar1 == -1) {
    printErr(*DAT_3011bf98,DAT_3011c9d8);
  }
  else if (iVar1 == 0) {
    printErr(DAT_3011c9dc);
  }
  else {
    iVar2 = taskDelete(iVar1);
    if (iVar2 == 0) {
      return;
    }
    printErr(DAT_3011c9e0,iVar1);
    printErrno(0);
  }
  return;
}

/* ----------------------------------------------------------------
 * version @ 0x3011BBD4  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: kernelVersion, printf, sysModel
 * Константы: 0x3011BBD4
 * Данные: DAT_3011c0d4, DAT_3011cae0, DAT_3011cae4, DAT_3011cae8, DAT_3011caec, DAT_3011caf0, DAT_3011caf4, DAT_3011caf8
 * ---------------------------------------------------------------- */
void version(void)

{
  undefined4 uVar1;
  
  uVar1 = sysModel();
  printf(DAT_3011cae8,*DAT_3011cae0,uVar1,*DAT_3011cae4);
  uVar1 = kernelVersion();
  printf(DAT_3011caec,uVar1);
  printf(DAT_3011caf4,*DAT_3011caf0);
  printf(DAT_3011caf8,*DAT_3011c0d4);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3011bc2c @ 0x3011BC2C  (примерный размер ~444 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: strlen
 * Вызывают: changeReg, memoryModify
 * Константы: 0xFFFFFFFF, 0x3011BC2C
 * Данные: DAT_3011cafc, DAT_3011cb00
 * ---------------------------------------------------------------- */
undefined4
FUN_3011bc2c(byte *param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5,uint param_6)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  byte *__s;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar5 = 0;
  uVar6 = 0;
  bVar9 = false;
  uVar8 = (uint)*param_1;
  uVar7 = 0;
  uVar4 = 0;
  if ((uVar8 == 0x2b) || (bVar9 = uVar8 == 0x2d, __s = param_1, bVar9)) {
    __s = param_1 + 1;
    uVar8 = (uint)*__s;
  }
  if (uVar8 == 0x30) {
    if (*(char *)(*DAT_3011cafc + (uint)__s[1]) == 'x') {
      __s = __s + 2;
      uVar8 = (uint)*__s;
    }
    else {
      uVar8 = (uint)*__s;
    }
  }
  sVar1 = strlen((char *)__s);
  if (param_6 < sVar1) {
    uVar2 = 0xffffffff;
  }
  else {
    if (uVar8 != 0) {
      do {
        if ((*(byte *)(*DAT_3011cb00 + uVar8) & 4) == 0) {
          if ((*(byte *)(*DAT_3011cb00 + uVar8) & 3) == 0) break;
          iVar3 = *(byte *)(*DAT_3011cafc + uVar8) - 0x57;
        }
        else {
          iVar3 = uVar8 - 0x30;
        }
        if (0xf < iVar3) break;
        __s = __s + 1;
        uVar5 = uVar5 * 0x10 + (uVar7 >> 0x1c);
        uVar8 = (uint)*__s;
        uVar7 = uVar7 * 0x10 + (uVar6 >> 0x1c);
        uVar6 = uVar6 * 0x10 + (uVar4 >> 0x1c);
        uVar4 = iVar3 + uVar4 * 0x10;
      } while (uVar8 != 0);
    }
    if (__s == param_1) {
      uVar2 = 0xffffffff;
    }
    else {
      if (bVar9) {
        uVar5 = ~uVar5;
        uVar7 = ~uVar7;
        uVar6 = ~uVar6;
        uVar4 = ~uVar4 + 1;
        if (((uVar4 == 0) && (uVar6 = uVar6 + 1, uVar6 == 0)) && (uVar7 = uVar7 + 1, uVar7 == 0)) {
          uVar5 = uVar5 + 1;
        }
      }
      if (param_2 != (uint *)0x0) {
        *param_2 = uVar5;
      }
      if (param_3 != (uint *)0x0) {
        *param_3 = uVar7;
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = uVar6;
      }
      uVar2 = 0;
      *param_5 = uVar4;
      if (uVar8 != 0) {
        uVar2 = 0xffffffff;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * ld @ 0x3011C83C  (примерный размер ~208 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: close, open, printErr, usrModuleLoad
 * Константы: 0x3011C83C, 0xFFFFFFFF
 * Данные: DAT_3011d678, DAT_3011d67c, DAT_3011d680
 * ---------------------------------------------------------------- */
undefined4 ld(uint param_1,undefined4 param_2,char *param_3)

{
  int __fd;
  undefined4 uVar1;
  
  if (param_3 == (char *)0x0) {
    __fd = 0;
  }
  else {
    __fd = open(param_3,0,0);
    if (__fd == -1) {
      printErr(DAT_3011d678,param_3);
      return 0;
    }
  }
  if (param_1 == 0xffffffff) {
    param_1 = 2;
  }
  else if (param_1 == 0) {
    param_1 = 8;
  }
  else if (param_1 == 1) {
    param_1 = 0xc;
  }
  if (*DAT_3011d67c != 0) {
    param_1 = param_1 | 0x400;
  }
  uVar1 = usrModuleLoad(__fd,param_1,param_2,DAT_3011d680);
  if (param_3 != (char *)0x0) {
    close(__fd);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * devs @ 0x3011C90C  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x3011C90C
 * Данные: DAT_300ec46c, DAT_300ec488, DAT_300ec48c, DAT_300ec490, DAT_300ec494, DAT_300ec498, DAT_300ec49c
 * ---------------------------------------------------------------- */
void devs(void)

{
  char *__format;
  int *piVar1;
  
  printf(DAT_300ec488,DAT_300ec46c,DAT_300ec48c);
  piVar1 = DAT_300ec490;
  while (piVar1 = (int *)*piVar1, piVar1 != (int *)0x0) {
    __format = DAT_300ec498;
    if (piVar1[6] != *DAT_300ec494) {
      __format = DAT_300ec49c;
    }
    printf(__format,(int)*(short *)(piVar1 + 2),piVar1[3]);
  }
  return;
}

/* ----------------------------------------------------------------
 * lkup @ 0x3011C910  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: handleShow, printErr
 * Константы: 0x3011C910
 * Данные: DAT_3011d684, DAT_3011d688
 * ---------------------------------------------------------------- */
void lkup(undefined4 param_1)

{
  if (*DAT_3011d684 == 0) {
    printErr(DAT_3011d688);
  }
  else {
    handleShow(*DAT_3011d684,param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * lkAddrInternal @ 0x3011C940  (примерный размер ~284 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: bzero, symEach
 * Вызывают: lkAddr
 * Константы: 0x3011C940, 0xFFFFFFFF
 * Данные: DAT_3011d68c, DAT_3011d690, DAT_3011d694
 * ---------------------------------------------------------------- */
undefined4 lkAddrInternal(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_44;
  int local_40;
  int local_3c [6];
  int local_24;
  
  if (param_2 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    bzero(&local_44,0x2c);
    local_44 = 0;
    local_40 = param_1;
    symEach(param_2,DAT_3011d68c,&local_44);
    piVar4 = local_3c;
    iVar3 = 3;
    do {
      local_40 = *piVar4;
      if (local_40 != 0) {
        symEach(param_2,DAT_3011d690,&local_44);
      }
      uVar1 = DAT_3011d694;
      uVar2 = DAT_3011d690;
      piVar4 = piVar4 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    local_40 = local_24;
    if (local_24 != 0) {
      while (local_44 < 0xc) {
        local_24 = 0;
        symEach(param_2,uVar1,&local_44);
        if (local_24 == 0) break;
        local_40 = local_24;
        symEach(param_2,uVar2,&local_44);
        local_40 = local_24;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}

