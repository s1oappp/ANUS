/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : bsp — BSP Huawei: GPIO, HKADC, PMU HI6451, WDT, LED, SPI/SSI, таймеры, питание
 * Часть  : 4 (функций: 58, адреса 0x30077148..0x301002EC)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * BSP_SdmmcAddHook @ 0x30077148  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: sdmmcAddHook
 * Константы: 0x30077148
 * ---------------------------------------------------------------- */
void BSP_SdmmcAddHook(undefined4 param_1,undefined4 param_2)

{
  sdmmcAddHook(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_Exch_ChangeCfg @ 0x300969E4  (примерный размер ~164 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300969E4
 * Данные: DAT_30096e94
 * ---------------------------------------------------------------- */
undefined4 BSP_Exch_ChangeCfg(int param_1,int param_2)

{
  if (param_1 == 0) {
    *DAT_30096e94 = param_2;
  }
  else if (param_1 == 10) {
    DAT_30096e94[1] = DAT_30096e94[1] & 0x7fffffffU | param_2 << 0x1f;
  }
  else if (param_2 == 0) {
    DAT_30096e94[1] = DAT_30096e94[1] & ~(1 << (param_1 - 1U & 0xff));
  }
  else {
    DAT_30096e94[1] = DAT_30096e94[1] | 1 << (param_1 - 1U & 0xff);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_MNTN_ExchOMRegisterTdsPhy @ 0x30096FEC  (примерный размер ~44 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30096FEC
 * Данные: DAT_300974fc, DAT_30097500
 * ---------------------------------------------------------------- */
void BSP_MNTN_ExchOMRegisterTdsPhy(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    *DAT_300974fc = param_2;
    *DAT_30097500 = param_1;
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_Errlog_IFCInit @ 0x300979FC  (примерный размер ~76 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: OSAL_LogMsg, printf
 * Константы: 0x300979FC
 * Данные: DAT_30097ffc, DAT_30098000
 * ---------------------------------------------------------------- */
undefined4 BSP_Errlog_IFCInit(void)

{
  printf(DAT_30097ffc);
  OSAL_LogMsg(DAT_30098000,0,0,0,0,0,0);
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_MNTN_GetBattState @ 0x300997A8  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300997A8
 * ---------------------------------------------------------------- */
undefined4 BSP_MNTN_GetBattState(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_fopen @ 0x30099CD0  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: fopen
 * Константы: 0x30099CD0
 * ---------------------------------------------------------------- */
void BSP_fopen(char *param_1,char *param_2)

{
  fopen(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_fseek @ 0x30099CEC  (примерный размер ~36 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: fseek
 * Константы: 0x30099CEC
 * ---------------------------------------------------------------- */
void BSP_fseek(FILE *param_1,long param_2,int param_3)

{
  fseek(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * BSP_ftell @ 0x30099D10  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: ftell
 * Константы: 0x30099D10
 * ---------------------------------------------------------------- */
void BSP_ftell(FILE *param_1)

{
  ftell(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_fread @ 0x30099D24  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: fread
 * Константы: 0x30099D24
 * ---------------------------------------------------------------- */
void BSP_fread(FILE *param_1,void *param_2,size_t param_3)

{
  fread(param_2,1,param_3,param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_fwrite @ 0x30099D4C  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: fwrite
 * Константы: 0x30099D4C
 * ---------------------------------------------------------------- */
void BSP_fwrite(FILE *param_1,void *param_2,size_t param_3)

{
  fwrite(param_2,1,param_3,param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_fclose @ 0x30099D74  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: fclose
 * Константы: 0x30099D74
 * ---------------------------------------------------------------- */
void BSP_fclose(FILE *param_1)

{
  fclose(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_remove @ 0x30099D88  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: remove
 * Константы: 0x30099D88
 * ---------------------------------------------------------------- */
void BSP_remove(char *param_1)

{
  remove(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_mkdir @ 0x30099D9C  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: mkdir
 * Константы: 0x30099D9C
 * ---------------------------------------------------------------- */
void BSP_mkdir(char *param_1,__mode_t param_2)

{
  mkdir(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_rmdir @ 0x30099DB0  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: rmdir
 * Константы: 0x30099DB0
 * ---------------------------------------------------------------- */
void BSP_rmdir(char *param_1)

{
  rmdir(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_opendir @ 0x30099DC4  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: opendir
 * Константы: 0x30099DC4
 * ---------------------------------------------------------------- */
void BSP_opendir(char *param_1)

{
  opendir(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_readdir @ 0x30099DD8  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: readdir
 * Константы: 0x30099DD8
 * ---------------------------------------------------------------- */
void BSP_readdir(DIR *param_1)

{
  readdir(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_closedir @ 0x30099DEC  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: closedir
 * Константы: 0x30099DEC
 * ---------------------------------------------------------------- */
void BSP_closedir(DIR *param_1)

{
  closedir(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_stat @ 0x30099E00  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: stat
 * Константы: 0x30099E00
 * ---------------------------------------------------------------- */
void BSP_stat(char *param_1,stat *param_2)

{
  stat(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * ledLibInit @ 0x300FE750  (примерный размер ~100 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: lstInit, semMCreate, shellPrintErr, shellResourceReleaseHookAdd
 * Вызывают: shellLibInit
 * Константы: 0xFFFFFFFF, 0x300FE750
 * Данные: DAT_300ff6f4, DAT_300ff6f8, DAT_300ff6fc, DAT_300ff700
 * ---------------------------------------------------------------- */
undefined4 ledLibInit(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_300ff6f4;
  lstInit(DAT_300ff6f4);
  iVar1 = semMCreate(0);
  *(int *)(iVar2 + 0xc) = iVar1;
  if (iVar1 == 0) {
    shellPrintErr(0,DAT_300ff6f8);
    return 0xffffffff;
  }
  iVar2 = shellResourceReleaseHookAdd(DAT_300ff6fc);
  if (iVar2 != 0) {
    shellPrintErr(0,DAT_300ff700);
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300fe7b4 @ 0x300FE7B4  (примерный размер ~48 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: malloc
 * Вызывают: ledHistResize, ledHistoryLineAllocate
 * Константы: 0x300FE7B4
 * ---------------------------------------------------------------- */
void FUN_300fe7b4(int param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1 + 0x11);
  if (pvVar1 == (void *)0x0) {
    return;
  }
  *(int *)((int)pvVar1 + 0xc) = (int)pvVar1 + 0x10;
  *(undefined1 *)((int)pvVar1 + 0x10) = 0;
  *(int *)((int)pvVar1 + 8) = param_1;
  return;
}

/* ----------------------------------------------------------------
 * ledHistoryLineAllocate @ 0x300FE7E4  (примерный размер ~264 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 9
 * Вызывает: FUN_300fe7b4, free, lstAdd, lstDelete, lstFirst, lstInsert, lstNext, lstPrevious, strcpy
 * Вызывают: ledHistoryCreate
 * Константы: 0xFFFFFFFF, 0x300FE7E4
 * ---------------------------------------------------------------- */
undefined4 ledHistoryLineAllocate(undefined4 *param_1,uint param_2)

{
  void *__ptr;
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  __ptr = (void *)lstFirst(param_1 + 1);
  iVar4 = param_1[5];
  while (__ptr != (void *)0x0) {
    if (param_2 < *(uint *)((int)__ptr + 8)) {
      *(uint *)((int)__ptr + 8) = param_2;
      pvVar2 = __ptr;
    }
    else {
      uVar1 = lstPrevious(__ptr);
      lstDelete(param_1 + 1,__ptr);
      pvVar2 = (void *)FUN_300fe7b4(param_2);
      if (pvVar2 == (void *)0x0) {
        return 0xffffffff;
      }
      strcpy(*(char **)((int)pvVar2 + 0xc),*(char **)((int)__ptr + 0xc));
      lstInsert(param_1 + 1,uVar1,pvVar2);
      free(__ptr);
    }
    __ptr = (void *)lstNext(pvVar2);
    iVar4 = iVar4 + -1;
  }
  param_1[6] = param_1[5] - iVar4;
  if (0 < iVar4) {
    do {
      iVar3 = FUN_300fe7b4(param_2);
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      lstAdd(param_1 + 1,iVar3);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  *param_1 = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * ledHistoryFree @ 0x300FE8EC  (примерный размер ~36 байт)
 * Модуль: bsp | Вызывают: 3 | Вызывает: 2
 * Вызывает: free, lstFree
 * Вызывают: ledClose, ledHistoryCreate, shellInterpDelete
 * Константы: 0x300FE8EC
 * ---------------------------------------------------------------- */
void ledHistoryFree(void *param_1)

{
  if (param_1 == (void *)0x0) {
    return;
  }
  lstFree((int)param_1 + 4);
  free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * ledHistoryCreate @ 0x300FE910  (примерный размер ~124 байт)
 * Модуль: bsp | Вызывают: 3 | Вызывает: 4
 * Вызывает: calloc, ledHistoryFree, ledHistoryLineAllocate, lstInit
 * Вызывают: ledHistoryClone, ledOpen, shellInterpCtxCreate
 * Константы: 0x300FE910, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void * ledHistoryCreate(undefined4 param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = calloc(1,0x1c);
  if (pvVar1 == (void *)0x0) {
    return (void *)0x0;
  }
  lstInit((int)pvVar1 + 4);
  *(undefined4 *)((int)pvVar1 + 0x10) = 0;
  *(undefined4 *)((int)pvVar1 + 0x14) = param_1;
  if (param_2 == 0) {
    *(undefined4 *)((int)pvVar1 + 0x18) = 0xffffffff;
  }
  else {
    iVar2 = ledHistoryLineAllocate(pvVar1,param_2);
    if (iVar2 != 0) {
      ledHistoryFree(pvVar1);
      return (void *)0x0;
    }
  }
  return pvVar1;
}

/* ----------------------------------------------------------------
 * ledOpen @ 0x300FE98C  (примерный размер ~176 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: calloc, free, ledHistoryCreate, shellPrintErr
 * Вызывают: shellTask
 * Константы: 0xFFFFFFFF, 0x300FE98C
 * Данные: DAT_300ff8d4, DAT_300ff8d8
 * ---------------------------------------------------------------- */
undefined4 * ledOpen(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *__ptr;
  int iVar1;
  
  iVar1 = *DAT_300ff8d4;
  if (iVar1 == 0) {
    shellPrintErr(0,DAT_300ff8d8);
    return (undefined4 *)0xffffffff;
  }
  __ptr = (undefined4 *)calloc(1,0x30);
  if (__ptr == (undefined4 *)0x0) {
    return (undefined4 *)0xffffffff;
  }
  *__ptr = param_1;
  __ptr[1] = param_2;
  __ptr[6] = 0;
  __ptr[5] = 0;
  __ptr[4] = 0;
  __ptr[10] = 0;
  __ptr[0xb] = 0;
  __ptr[8] = iVar1;
  iVar1 = ledHistoryCreate(param_3,0);
  __ptr[3] = iVar1;
  __ptr[2] = iVar1;
  if (iVar1 == 0) {
    free(__ptr);
    return (undefined4 *)0xffffffff;
  }
  return __ptr;
}

/* ----------------------------------------------------------------
 * ledClose @ 0x300FEA3C  (примерный размер ~72 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: free, ledHistoryFree
 * Вызывают: shellContextFinalize
 * Константы: 0x300FEA3C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 ledClose(void *param_1)

{
  if (param_1 == (void *)0x0) {
    return 0xffffffff;
  }
  ledHistoryFree(*(undefined4 *)((int)param_1 + 0xc));
  *(undefined4 *)((int)param_1 + 0xc) = 0;
  free(*(void **)((int)param_1 + 0x14));
  free(*(void **)((int)param_1 + 0x10));
  free(param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * ledRead @ 0x300FEA84  (примерный размер ~156 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: free, malloc, memmove
 * Вызывают: FUN_30110224
 * Константы: 0xFFFFFFFF, 0x300FEA84
 * ---------------------------------------------------------------- */
undefined4 ledRead(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  undefined1 *__dest;
  uint uVar2;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x18);
    if (uVar2 < param_3) {
      __dest = (undefined1 *)malloc(param_3 + 1);
      if (__dest == (undefined1 *)0x0) {
        return 0xffffffff;
      }
      if (*(void **)(param_1 + 0x14) == (void *)0x0) {
        *__dest = 0;
      }
      else {
        memmove(__dest,*(void **)(param_1 + 0x14),uVar2 + 1);
        free(*(void **)(param_1 + 0x14));
      }
      *(undefined1 **)(param_1 + 0x14) = __dest;
      *(uint *)(param_1 + 0x18) = param_3;
    }
    uVar1 = (**(code **)(*(int *)(param_1 + 0x20) + 0xc))(param_1,param_2,param_3);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * ledModeRegister @ 0x300FEB20  (примерный размер ~180 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 6
 * Вызывает: free, lstAdd, malloc, semGive, semTake, shellPrintErr
 * Вызывают: usrShellInit
 * Константы: 0xFFFFFFFF, 0x300FEB20
 * Данные: DAT_300ff6f4, DAT_300ffae4, DAT_300ffae8, DAT_300ffaec
 * ---------------------------------------------------------------- */
undefined4 ledModeRegister(code *param_1)

{
  void *__ptr;
  undefined4 uVar1;
  int iVar2;
  
  __ptr = malloc(0x10);
  if (__ptr == (void *)0x0) {
    shellPrintErr(0,DAT_300ffae4,param_1);
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = (*param_1)(__ptr);
    if (iVar2 == -1) {
      shellPrintErr(0,DAT_300ffae8,*(undefined4 *)((int)__ptr + 8));
      free(__ptr);
      uVar1 = 0xffffffff;
    }
    else {
      if (*(int *)(DAT_300ffaec + 4) == 0) {
        *(void **)(DAT_300ffaec + 4) = __ptr;
      }
      iVar2 = DAT_300ff6f4;
      semTake(*(undefined4 *)(DAT_300ff6f4 + 0xc),0xffffffff);
      lstAdd(iVar2,__ptr);
      semGive(*(undefined4 *)(iVar2 + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * ledInactivityDelaySet @ 0x300FEBD4  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3010ff7c
 * Константы: 0x300FEBD4
 * ---------------------------------------------------------------- */
void ledInactivityDelaySet(int param_1,int param_2)

{
  if (param_1 == 0) {
    return;
  }
  *(int *)(param_1 + 0x28) = param_2 * 0x3c;
  return;
}

/* ----------------------------------------------------------------
 * ledModeDefaultNameGet @ 0x300FEBEC  (примерный размер ~32 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: ledModeSet
 * Константы: 0x300FEBEC
 * Данные: DAT_300ff8d4
 * ---------------------------------------------------------------- */
undefined4 ledModeDefaultNameGet(void)

{
  if (*DAT_300ff8d4 == 0) {
    return 0;
  }
  return *(undefined4 *)(*DAT_300ff8d4 + 8);
}

/* ----------------------------------------------------------------
 * ledModeSet @ 0x300FEC0C  (примерный размер ~180 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 6
 * Вызывает: ledModeDefaultNameGet, lstFirst, lstNext, semGive, semTake, strcmp
 * Вызывают: FUN_3010fed0
 * Константы: 0xFFFFFFFF, 0x300FEC0C
 * Данные: DAT_300ff6f4
 * ---------------------------------------------------------------- */
undefined4 ledModeSet(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if ((param_2 == (char *)0x0) &&
     (param_2 = (char *)ledModeDefaultNameGet(), param_2 == (char *)0x0)) {
    return 0xffffffff;
  }
  iVar1 = DAT_300ff6f4;
  semTake(*(undefined4 *)(DAT_300ff6f4 + 0xc),0xffffffff);
  iVar2 = lstFirst(iVar1);
  if (iVar2 != 0) {
    do {
      iVar3 = strcmp(*(char **)(iVar2 + 8),param_2);
      if (iVar3 == 0) break;
      iVar2 = lstNext(iVar2);
    } while (iVar2 != 0);
    if (iVar2 != 0) {
      *(int *)(param_1 + 0x20) = iVar2;
      semGive(*(undefined4 *)(iVar1 + 0xc));
      return 0;
    }
  }
  semGive(*(undefined4 *)(iVar1 + 0xc));
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * ledModeNameGet @ 0x300FECC0  (примерный размер ~32 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_3010fc88, FUN_3010ff7c
 * Константы: 0x300FECC0
 * ---------------------------------------------------------------- */
undefined4 ledModeNameGet(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x20) + 8);
}

/* ----------------------------------------------------------------
 * ledHistResize @ 0x300FECE0  (примерный размер ~308 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_300fe7b4, free, lstAdd, lstCount, lstDelete, lstFirst, lstNext, lstNth
 * Вызывают: ledControl
 * Константы: 0x300FECE0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 ledHistResize(undefined4 *param_1,int param_2)

{
  int iVar1;
  void *__ptr;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = lstCount(param_1 + 1);
  iVar1 = param_2 - iVar1;
  param_1[5] = param_2;
  if (iVar1 < 0) {
    if (param_1[6] == -1) {
      __ptr = (void *)lstFirst();
    }
    else {
      __ptr = (void *)lstNth(param_1 + 1,param_1[6] + 1);
      if (__ptr == (void *)0x0) {
        __ptr = (void *)lstFirst(param_1 + 1);
      }
    }
    while ((iVar1 < 0 && (__ptr != (void *)0x0))) {
      pvVar2 = (void *)lstNext(__ptr);
      if (pvVar2 == (void *)0x0) {
        pvVar2 = (void *)lstFirst(param_1 + 1);
      }
      lstDelete(param_1 + 1,__ptr);
      free(__ptr);
      iVar1 = iVar1 + 1;
      __ptr = pvVar2;
    }
    *param_1 = 0;
    if ((param_1[6] != -1) && (param_2 < (int)param_1[6])) {
      param_1[6] = param_2;
    }
  }
  else if ((0 < iVar1) && (param_1[6] != -1)) {
    iVar3 = lstFirst(param_1 + 1);
    uVar4 = *(undefined4 *)(iVar3 + 8);
    do {
      iVar1 = iVar1 + -1;
      iVar3 = FUN_300fe7b4(uVar4);
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      lstAdd(param_1 + 1,iVar3);
    } while (iVar1 != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300fee14 @ 0x300FEE14  (примерный размер ~116 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: write
 * Вызывают: FUN_300fee88, ledRedraw
 * Константы: 0x300FEE14
 * Данные: DAT_300ffda0
 * ---------------------------------------------------------------- */
int FUN_300fee14(int param_1,byte *param_2,int param_3)

{
  ssize_t sVar1;
  byte *__buf;
  int iVar2;
  byte local_18 [4];
  
  local_18[0] = 0x3f;
  iVar2 = param_3;
  if (0 < param_3) {
    do {
      __buf = param_2;
      if ((*(byte *)(*DAT_300ffda0 + (uint)*param_2) & 0x1f) == 0) {
        __buf = local_18;
      }
      sVar1 = write(param_1,__buf,1);
      if (sVar1 != 1) {
        return -1;
      }
      param_2 = param_2 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return param_3;
}

/* ----------------------------------------------------------------
 * FUN_300fee88 @ 0x300FEE88  (примерный размер ~236 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 9
 * Вызывает: FUN_300fee14, free, lstCount, lstFirst, lstNext, malloc, sprintf, strlen, write
 * Вызывают: ledControl
 * Константы: 0x300FEE88
 * Данные: DAT_300ffe7c, DAT_300ffe80
 * ---------------------------------------------------------------- */
void FUN_300fee88(int param_1)

{
  int iVar1;
  size_t sVar2;
  char *__s;
  char *__s_00;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x18);
  if (iVar4 == -1) {
    iVar4 = lstCount(*(int *)(param_1 + 8) + 4);
  }
  iVar4 = (*(int *)(*(int *)(param_1 + 8) + 0x10) - iVar4) + 1;
  iVar1 = lstFirst(*(int *)(param_1 + 8) + 4);
  iVar3 = 0;
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    if (*(int *)(*(int *)(param_1 + 8) + 0x18) == iVar3) break;
    __s_00 = *(char **)(iVar1 + 0xc);
    sVar2 = strlen(__s_00);
    __s = (char *)malloc(sVar2 + 10);
    if (__s != (char *)0x0) {
      sprintf(__s,DAT_300ffe7c,iVar4,__s_00);
      __s_00 = __s;
      iVar4 = iVar4 + 1;
    }
    sVar2 = strlen(__s_00);
    FUN_300fee14(*(undefined4 *)(param_1 + 4),__s_00,sVar2);
    write(*(int *)(param_1 + 4),DAT_300ffe80,1);
    free(__s);
    iVar1 = lstNext(iVar1);
    iVar3 = iVar3 + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * ledControl @ 0x300FEF74  (примерный размер ~76 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 2
 * Вызывает: FUN_300fee88, ledHistResize
 * Вызывают: shellHistory, shellInOutSet
 * Константы: 0x300FEF74
 * ---------------------------------------------------------------- */
void ledControl(int *param_1,int param_2,int param_3,int param_4)

{
  if (param_1 == (int *)0x0) {
    return;
  }
  if (-1 < param_2) {
    *param_1 = param_2;
  }
  if (-1 < param_3) {
    param_1[1] = param_3;
  }
  if (param_4 == 0) {
    FUN_300fee88(param_1);
  }
  if (param_4 < 1) {
    return;
  }
  ledHistResize(param_1[2],param_4);
  return;
}

/* ----------------------------------------------------------------
 * ledHistCurrentNumGet @ 0x300FEFC0  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300FEFC0
 * ---------------------------------------------------------------- */
undefined4 ledHistCurrentNumGet(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {
    return *(undefined4 *)(*(int *)(param_1 + 8) + 0x10);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ledHistoryAdd @ 0x300FEFE8  (примерный размер ~460 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 11
 * Вызывает: free, lstAdd, lstCount, lstGet, lstLast, lstNth, malloc, strcmp, strcpy, strlen, strncpy
 * Вызывают: ledHistoryClone, shellExec
 * Константы: 0x300FEFE8
 * Данные: DAT_300ffda0
 * ---------------------------------------------------------------- */
void ledHistoryAdd(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  size_t sVar2;
  void *pvVar3;
  void *__ptr;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  if (param_1[5] == 0) {
    return;
  }
  iVar7 = 0;
  iVar6 = *DAT_300ffda0;
  bVar1 = *(byte *)(iVar6 + (uint)*param_2);
  pbVar4 = param_2;
  while ((bVar1 & 0x28) != 0) {
    pbVar4 = pbVar4 + 1;
    iVar7 = iVar7 + 1;
    bVar1 = *(byte *)(iVar6 + (uint)*pbVar4);
  }
  pbVar4 = param_2 + iVar7;
  sVar2 = strlen((char *)pbVar4);
  pbVar5 = pbVar4 + (sVar2 - 1);
  if (pbVar4 <= pbVar5) {
    do {
      if ((*(byte *)(iVar6 + (uint)*pbVar5) & 0x28) == 0) break;
      pbVar5 = pbVar5 + -1;
    } while (param_2 + iVar7 <= pbVar5);
  }
  pbVar5[1] = 0;
  param_2 = param_2 + iVar7;
  if (param_1[6] == -1) {
    iVar7 = lstLast();
  }
  else {
    iVar7 = lstNth(param_1 + 1,param_1[6]);
  }
  if (*param_2 == 0) {
    return;
  }
  if ((iVar7 == 0) || (iVar7 = strcmp((char *)param_2,*(char **)(iVar7 + 0xc)), iVar7 != 0)) {
    if (param_1[6] == -1) {
      sVar2 = strlen((char *)param_2);
      pvVar3 = malloc(sVar2 + 0x11);
      if (pvVar3 == (void *)0x0) {
        return;
      }
      iVar7 = lstCount(param_1 + 1);
      if (iVar7 == param_1[5]) {
        __ptr = (void *)lstGet(param_1 + 1);
        free(__ptr);
      }
      *(char **)((int)pvVar3 + 0xc) = (char *)((int)pvVar3 + 0x10);
      sVar2 = strlen((char *)param_2);
      *(size_t *)((int)pvVar3 + 8) = sVar2;
      strcpy((char *)((int)pvVar3 + 0x10),(char *)param_2);
      lstAdd(param_1 + 1,pvVar3);
    }
    else {
      iVar7 = lstNth(param_1 + 1,param_1[6] + 1);
      if (iVar7 == 0) {
        iVar7 = lstGet(param_1 + 1);
        lstAdd(param_1 + 1,iVar7);
      }
      else {
        param_1[6] = param_1[6] + 1;
      }
      strncpy(*(char **)(iVar7 + 0xc),(char *)param_2,*(size_t *)(iVar7 + 8));
    }
    param_1[4] = param_1[4] + 1;
  }
  *param_1 = 0;
  return;
}

/* ----------------------------------------------------------------
 * ledHistoryClone @ 0x300FF1B4  (примерный размер ~176 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 7
 * Вызывает: ledHistoryAdd, ledHistoryCreate, lstCount, lstFind, lstFirst, lstNext, lstNth
 * Константы: 0x300FF1B4
 * ---------------------------------------------------------------- */
undefined4 * ledHistoryClone(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if ((param_1[6] != -1) && (iVar1 = lstCount(param_1 + 1), iVar1 != 0)) {
    iVar1 = lstFirst(param_1 + 1);
    uVar3 = *(undefined4 *)(iVar1 + 8);
  }
  puVar2 = (undefined4 *)ledHistoryCreate(param_1[5],uVar3);
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  for (iVar1 = lstFirst(param_1 + 1); iVar1 != 0; iVar1 = lstNext(iVar1)) {
    ledHistoryAdd(puVar2,*(undefined4 *)(iVar1 + 0xc));
  }
  uVar3 = lstFind(param_1 + 1,*param_1);
  uVar3 = lstNth(puVar2 + 1,uVar3);
  *puVar2 = uVar3;
  return puVar2;
}

/* ----------------------------------------------------------------
 * ledHistorySet @ 0x300FF264  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_3010ff7c, shellInterpSwitch
 * Константы: 0x300FF264
 * ---------------------------------------------------------------- */
void ledHistorySet(int param_1,int param_2)

{
  if (param_1 == 0) {
    return;
  }
  if (param_2 == 0) {
    return;
  }
  *(int *)(param_1 + 8) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * ledCompletionSet @ 0x300FF27C  (примерный размер ~16 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: shellTask
 * Константы: 0x300FF27C
 * ---------------------------------------------------------------- */
void ledCompletionSet(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * ledComplete @ 0x300FF28C  (примерный размер ~52 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30112ec0
 * Константы: 0x300FF28C
 * Данные: DAT_30100248
 * ---------------------------------------------------------------- */
void ledComplete(int param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x24);
  if (*(code **)(param_1 + 0x24) == (code *)0x0) {
    pcVar1 = DAT_30100248;
  }
  (*pcVar1)();
  return;
}

/* ----------------------------------------------------------------
 * ledDfltComplete @ 0x300FF2C0  (примерный размер ~612 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 11
 * Вызывает: calloc, completionSymComplete, completionSymListGet, free, lstFree, lstInit, malloc, strcat, strcpy, strlen, strncpy
 * Вызывают: FUN_30110b1c
 * Константы: 0xFFFFFFFF, 0x300FF2C0
 * Данные: DAT_300ffda0, DAT_3010037c, DAT_30100380
 * ---------------------------------------------------------------- */
undefined4 ledDfltComplete(undefined4 param_1,char *param_2,uint param_3,int *param_4)

{
  size_t sVar1;
  undefined4 uVar2;
  char *__s;
  int iVar3;
  size_t sVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_38 [12];
  char *local_2c;
  
  iVar8 = *param_4;
  sVar1 = strlen(param_2);
  iVar7 = iVar8;
  if (0 < iVar8) {
    pcVar5 = param_2 + iVar8;
    do {
      pcVar5 = pcVar5 + -1;
      if ((*(byte *)(*DAT_300ffda0 + (uint)(*pcVar5 != '\0')) & 7) == 0) break;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if (iVar8 < (int)sVar1) {
    pcVar5 = param_2 + iVar8 + -1;
    iVar8 = sVar1 - iVar8;
    do {
      pcVar5 = pcVar5 + 1;
      if ((*(byte *)(*DAT_300ffda0 + (uint)(*pcVar5 != '\0')) & 7) == 0) break;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    iVar8 = sVar1 - iVar8;
  }
  if (iVar8 == iVar7) {
    uVar2 = 0xffffffff;
  }
  else {
    pcVar5 = (char *)malloc((iVar8 - iVar7) + 1);
    __s = (char *)calloc(2,param_3 + 1);
    if ((pcVar5 == (char *)0x0) || (__s == (char *)0x0)) {
      free(pcVar5);
      free(__s);
      uVar2 = 0xffffffff;
    }
    else {
      strncpy(pcVar5,param_2 + iVar7,iVar8 - iVar7);
      pcVar5[iVar8 - iVar7] = '\0';
      lstInit(auStack_38);
      local_2c = pcVar5;
      iVar3 = completionSymListGet(*DAT_3010037c,auStack_38);
      if (iVar3 == -1) {
        free(pcVar5);
        free(__s);
        uVar2 = 0xffffffff;
      }
      else {
        iVar3 = completionSymComplete(auStack_38,__s,param_3);
        lstFree(auStack_38);
        if ((iVar3 == 1) && (sVar1 = strlen(__s), sVar1 < param_3)) {
          strcat(__s,DAT_30100380);
        }
        strcpy(__s + param_3 + 1,param_2);
        strncpy(param_2 + iVar7,__s,(param_3 - iVar7) - 1);
        sVar1 = strlen(param_2);
        sVar4 = strlen(param_2);
        strncpy(param_2 + sVar4,__s + param_3 + 1 + iVar8,(param_3 - sVar1) - 1);
        iVar7 = *DAT_300ffda0;
        while( true ) {
          uVar6 = (uint)(byte)param_2[*param_4];
          if ((((*(byte *)(iVar7 + uVar6) & 7) == 0) && (uVar6 != 0x5f)) && (uVar6 != 0x20)) break;
          *param_4 = *param_4 + 1;
        }
        free(pcVar5);
        free(__s);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * ledPreemptSet @ 0x300FF524  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30112ec0
 * Константы: 0x300FF524
 * ---------------------------------------------------------------- */
void ledPreemptSet(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}

/* ----------------------------------------------------------------
 * ledPreempt @ 0x300FF52C  (примерный размер ~84 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30112ec0
 * Константы: 0x300FF52C
 * ---------------------------------------------------------------- */
undefined4
ledPreempt(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  code *pcVar2;
  
  pcVar2 = (code *)*param_1;
  if (pcVar2 == (code *)0x0) {
    uVar1 = 1;
  }
  else {
    *param_1 = 0;
    uVar1 = (*pcVar2)(param_2,param_3,param_4,param_5,param_6);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * ledNWrite @ 0x300FF580  (примерный размер ~160 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: free, malloc, memset, write
 * Вызывают: ledRedraw
 * Константы: 0x300FF580
 * ---------------------------------------------------------------- */
ssize_t ledNWrite(int param_1,byte param_2,size_t param_3)

{
  void *__s;
  ssize_t sVar1;
  size_t sVar2;
  byte local_4 [4];
  
  local_4[0] = param_2;
  __s = malloc(param_3);
  if (__s == (void *)0x0) {
    sVar1 = 0;
    sVar2 = param_3;
    if (0 < (int)param_3) {
      do {
        sVar1 = write(param_1,local_4,1);
        if (sVar1 != 1) break;
        sVar2 = sVar2 - 1;
      } while (sVar2 != 0);
      sVar1 = param_3 - sVar2;
    }
  }
  else {
    memset(__s,(uint)local_4[0],param_3);
    sVar1 = write(param_1,__s,param_3);
    free(__s);
  }
  return sVar1;
}

/* ----------------------------------------------------------------
 * ledRedraw @ 0x300FF620  (примерный размер ~492 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300fee14, ledNWrite, strlen
 * Вызывают: FUN_30112ec0
 * Константы: 0x300FF620
 * ---------------------------------------------------------------- */
void ledRedraw(undefined4 param_1,char *param_2,uint param_3,char *param_4,uint *param_5)

{
  char *pcVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  uVar5 = 0;
  pcVar1 = param_4;
  pcVar6 = param_2;
  if (*param_4 == *param_2) {
    do {
      if (*pcVar1 == '\0') break;
      pcVar1 = pcVar1 + 1;
      pcVar6 = pcVar6 + 1;
      uVar5 = uVar5 + 1;
    } while (*pcVar1 == *pcVar6);
  }
  sVar2 = strlen(param_4);
  sVar3 = strlen(param_2);
  if (sVar3 == sVar2) {
    sVar2 = strlen(param_4);
    if (param_4[sVar2] == param_2[sVar2]) {
      pcVar1 = param_4 + sVar2;
      pcVar6 = param_2 + sVar2;
      do {
        if (sVar2 == 0) break;
        pcVar1 = pcVar1 + -1;
        pcVar6 = pcVar6 + -1;
        sVar2 = sVar2 - 1;
      } while (*pcVar1 == *pcVar6);
    }
    sVar3 = strlen(param_4);
    if (sVar2 < sVar3) {
      sVar2 = sVar2 + 1;
    }
  }
  else {
    sVar2 = strlen(param_4);
  }
  if (uVar5 < param_3) {
    ledNWrite(param_1,8,param_3 - uVar5);
    FUN_300fee14(param_1,param_4 + uVar5,sVar2 - uVar5);
    param_3 = sVar2;
  }
  else if (param_3 < sVar2) {
    FUN_300fee14(param_1,param_4 + param_3,sVar2 - param_3);
    param_3 = sVar2;
  }
  else if ((sVar2 == param_3) && (sVar2 = strlen(param_4), param_3 < sVar2)) {
    FUN_300fee14(param_1,param_4 + param_3,1);
    param_3 = param_3 + 1;
  }
  sVar2 = strlen(param_4);
  if (sVar2 == param_3) {
    sVar2 = strlen(param_2);
    sVar3 = strlen(param_4);
    iVar4 = sVar2 - sVar3;
    if (0 < iVar4) {
      ledNWrite(param_1,0x20,iVar4);
      ledNWrite(param_1,8,iVar4);
    }
  }
  uVar5 = *param_5;
  if (uVar5 < param_3) {
    ledNWrite(param_1,8,param_3 - uVar5);
  }
  else {
    FUN_300fee14(param_1,param_4 + param_3,uVar5 - param_3);
  }
  return;
}

/* ----------------------------------------------------------------
 * ledSearch @ 0x300FF80C  (примерный размер ~644 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: ledCDelete
 * Константы: 0x300FF80C
 * Данные: DAT_300ffda0
 * ---------------------------------------------------------------- */
void ledSearch(int param_1,int param_2,int param_3,int *param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = (uint)*(byte *)(param_3 + *param_4);
  if ((uVar3 != 0) && (uVar4 = (uint)*(byte *)(param_3 + param_5 + *param_4), uVar4 != 0)) {
    iVar2 = *DAT_300ffda0;
    bVar1 = *(byte *)(iVar2 + uVar3);
    if ((bVar1 & 0x28) == 0) {
      if ((((bVar1 & 0x10) == 0) || (param_1 != 0)) || (param_5 != 1)) {
        if ((param_2 == 0) && (param_5 != -1)) {
          do {
            do {
              iVar5 = param_5 + *param_4;
              *param_4 = iVar5;
              if (*(char *)(param_3 + param_5 + iVar5) == '\0') goto LAB_300ffa4c;
              bVar1 = *(byte *)(iVar2 + (uint)*(byte *)(param_3 + iVar5));
            } while ((bVar1 & 7) != 0);
          } while (((param_1 != 0) && ((bVar1 & 0x10) != 0)) && ((bVar1 & 0x28) == 0));
LAB_300ffa4c:
          if (*(char *)(param_3 + param_5 + iVar5) == '\0') {
            return;
          }
          do {
            if ((*(byte *)(iVar2 + (uint)*(byte *)(param_3 + *param_4)) & 0x28) == 0) {
              return;
            }
            iVar5 = param_5 + *param_4;
            *param_4 = iVar5;
          } while (*(char *)(param_3 + param_5 + iVar5) != '\0');
          return;
        }
      }
      else if (param_2 == 0) {
        if (uVar4 == 0) {
          return;
        }
        do {
          if ((*(byte *)(iVar2 + (uint)*(byte *)(param_3 + *param_4)) & 7) != 0) {
            return;
          }
          iVar5 = *param_4 + 1;
          *param_4 = iVar5;
        } while (*(char *)(param_3 + 1 + iVar5) != '\0');
        return;
      }
      if ((*(byte *)(iVar2 + uVar4) & 0x28) != 0) {
        do {
          iVar5 = *param_4;
          *param_4 = param_5 + iVar5;
        } while ((*(byte *)(iVar2 + (uint)*(byte *)(param_3 + param_5 + param_5 + iVar5)) & 0x28) !=
                 0);
      }
      bVar1 = *(byte *)(iVar2 + (uint)*(byte *)(param_3 + param_5 + *param_4));
      if (((bVar1 & 0x10) != 0) && ((bVar1 & 0x28) == 0)) {
        do {
          iVar5 = param_5 + *param_4;
          *param_4 = iVar5;
          uVar3 = (uint)*(byte *)(param_3 + param_5 + iVar5);
          if ((uVar3 == 0) || (bVar1 = *(byte *)(iVar2 + uVar3), (bVar1 & 0x10) == 0)) break;
        } while ((bVar1 & 0x28) == 0);
        if (*(char *)(param_3 + param_5 + iVar5) != '\0') {
          do {
            if ((*(byte *)(iVar2 + (uint)*(byte *)(param_3 + *param_4)) & 0x28) == 0) break;
            iVar5 = param_5 + *param_4;
            *param_4 = iVar5;
          } while (*(char *)(param_3 + param_5 + iVar5) != '\0');
        }
        if (param_1 == 0) {
          return;
        }
      }
      if (*(char *)(param_3 + param_5 + *param_4) != '\0') {
        do {
          bVar1 = *(byte *)(iVar2 + (uint)*(byte *)(param_3 + param_5 + *param_4));
          if ((bVar1 & 7) == 0) {
            if (param_1 == 0) {
              return;
            }
            if ((bVar1 & 0x10) == 0) {
              return;
            }
            if ((bVar1 & 0x28) != 0) {
              return;
            }
          }
          iVar5 = param_5 + *param_4;
          *param_4 = iVar5;
        } while (*(char *)(param_3 + param_5 + iVar5) != '\0');
      }
    }
    else {
      do {
        if ((*(byte *)(iVar2 + (uint)*(byte *)(param_3 + *param_4)) & 0x28) == 0) {
          return;
        }
        iVar5 = param_5 + *param_4;
        *param_4 = iVar5;
      } while (*(char *)(param_3 + param_5 + iVar5) != '\0');
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300ffa90 @ 0x300FFA90  (примерный размер ~124 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 0
 * Вызывают: ledBwdFind, ledFwdFind
 * Константы: 0x300FFA90
 * ---------------------------------------------------------------- */
undefined4 FUN_300ffa90(uint param_1,int param_2,int *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = *(char *)(param_2 + *param_3) == '\0';
  if (!bVar3) {
    bVar3 = *(char *)(param_2 + param_4 + *param_3) == '\0';
  }
  if (bVar3) {
    uVar1 = 0;
  }
  else {
    do {
      iVar2 = param_4 + *param_3;
      *param_3 = iVar2;
      if (*(byte *)(param_2 + iVar2) == param_1) break;
    } while (*(char *)(param_2 + param_4 + iVar2) != '\0');
    if (*(byte *)(param_2 + iVar2) == param_1) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * ledFwdFind @ 0x300FFB0C  (примерный размер ~84 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300ffa90
 * Константы: 0x300FFB0C
 * ---------------------------------------------------------------- */
undefined4 ledFwdFind(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  do {
    iVar1 = FUN_300ffa90(param_1,param_2,param_3,1);
    if (iVar1 == 0) break;
    iVar1 = *param_4;
    *param_4 = iVar1 + -1;
  } while (0 < iVar1 + -1);
  *param_4 = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * ledBwdFind @ 0x300FFB60  (примерный размер ~84 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300ffa90
 * Константы: 0x300FFB60, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 ledBwdFind(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  do {
    iVar1 = FUN_300ffa90(param_1,param_2,param_3,0xffffffff);
    if (iVar1 == 0) break;
    iVar1 = *param_4;
    *param_4 = iVar1 + -1;
  } while (0 < iVar1 + -1);
  *param_4 = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * ledCDelete @ 0x300FFBB4  (примерный размер ~884 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 5
 * Вызывает: ledSearch, memmove, strcpy, strlen, strncpy
 * Вызывают: ledChange
 * Константы: 0x300FFBB4, 0xFFFFFFFF
 * Данные: DAT_300ffda0
 * ---------------------------------------------------------------- */
undefined4 ledCDelete(int param_1,char *param_2,uint *param_3,int *param_4,int param_5)

{
  size_t sVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  uint uVar5;
  bool bVar6;
  int local_34;
  undefined4 local_30;
  
  uVar2 = *param_3;
  sVar4 = 0;
  bVar6 = param_1 == 0x62;
  if ((!bVar6) && (bVar6 = param_1 == 0x42, !bVar6)) {
    bVar6 = param_1 == 0x68;
  }
  if (bVar6) {
    local_34 = -1;
  }
  else {
    local_34 = 1;
  }
  local_30 = 0;
  do {
    if (param_1 == 0x62) {
LAB_300ffcb8:
      uVar5 = *param_3;
      iVar3 = *DAT_300ffda0;
      ledSearch(*(byte *)(iVar3 + param_1) & 1,param_1 != 0x77 && param_1 != 0x57,param_2,param_3,
                local_34);
      if (*param_3 == uVar5) {
        *param_4 = 1;
      }
      uVar5 = *param_3;
      if (((*(byte *)(iVar3 + (uint)(byte)param_2[uVar5]) & 7) == 0) ||
         (param_2[uVar5 + local_34] != '\0')) {
        iVar3 = 0;
      }
      else {
        iVar3 = 1;
      }
      if (local_34 == 1) {
        sVar4 = iVar3 + (uVar5 - uVar2);
        strncpy(*(char **)(param_5 + 0x14),param_2 + uVar2,sVar4);
        strcpy(param_2 + uVar2,param_2 + *param_3 + iVar3);
        *param_3 = uVar2;
      }
      else {
        sVar4 = iVar3 + (uVar2 - uVar5);
        strncpy(*(char **)(param_5 + 0x14),param_2 + uVar5,sVar4);
        strcpy(param_2 + *param_3,param_2 + iVar3 + uVar2);
        uVar2 = *param_3 - iVar3;
      }
    }
    else {
      if (0x62 < param_1) {
        if (param_1 != 0x68) {
          if (param_1 < 0x69) {
            if (param_1 == 100) {
              strcpy(*(char **)(param_5 + 0x14),param_2);
              sVar4 = strlen(*(char **)(param_5 + 0x14));
              *param_3 = 0;
LAB_300ffe60:
              param_2[*param_3] = '\0';
              *param_4 = 1;
              goto LAB_300ffeec;
            }
            if (param_1 == 0x65) goto LAB_300ffcb8;
          }
          else {
            if (param_1 == 0x6c) goto LAB_300ffda4;
            if (param_1 == 0x77) goto LAB_300ffcb8;
          }
        }
        goto LAB_300ffed0;
      }
      if (param_1 == 0x42) goto LAB_300ffcb8;
      if (param_1 < 0x43) {
        if (param_1 == 0x20) {
LAB_300ffda4:
          *(char *)(*(int *)(param_5 + 0x14) + sVar4) = param_2[*param_3];
          uVar5 = *param_3;
          sVar4 = sVar4 + 1;
          sVar1 = strlen(param_2);
          if (uVar5 < sVar1 - 1) {
            strcpy(param_2 + uVar5,param_2 + uVar5 + local_34);
          }
          else {
            sVar1 = strlen(param_2);
            if (sVar1 - 1 == uVar5) {
              *param_4 = 1;
            }
            param_2[*param_3] = '\0';
          }
          goto LAB_300ffeec;
        }
        if (param_1 == 0x24) {
          uVar5 = *param_3;
          sVar4 = strlen(param_2);
          sVar4 = (sVar4 - uVar5) + 1;
          strncpy(*(char **)(param_5 + 0x14),param_2 + uVar5,sVar4);
          goto LAB_300ffe60;
        }
        if (param_1 == 0x30) {
          sVar4 = *param_3 + 1;
          strncpy(*(char **)(param_5 + 0x14),param_2,sVar4);
          uVar5 = *param_3;
          sVar1 = strlen(param_2 + uVar5);
          memmove(param_2,param_2 + uVar5,sVar1 + 1);
          *param_3 = 0;
          *param_4 = 1;
          goto LAB_300ffeec;
        }
      }
      else if ((param_1 == 0x45) || (param_1 == 0x57)) goto LAB_300ffcb8;
LAB_300ffed0:
      sVar4 = strlen(*(char **)(param_5 + 0x14));
      *param_4 = 1;
      local_30 = 0xffffffff;
    }
LAB_300ffeec:
    iVar3 = *param_4;
    *param_4 = iVar3 + -1;
    if (iVar3 + -1 < 1) {
      *param_4 = 0;
      *(undefined1 *)(*(int *)(param_5 + 0x14) + sVar4) = 0;
      return local_30;
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * ledChange @ 0x300FFF28  (примерный размер ~268 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: ledCDelete, strcpy
 * Константы: 0xFFFFFFFF, 0x300FFF28
 * ---------------------------------------------------------------- */
undefined4 ledChange(int param_1,int param_2,int *param_3,undefined4 *param_4,int param_5)

{
  undefined4 uVar1;
  
  if (param_1 != 0x62) {
    if (param_1 < 99) {
      if (param_1 != 0x42) {
        if (param_1 < 0x43) {
          if (param_1 != 0x20) {
            if (param_1 == 0x24) goto LAB_300ffff4;
            if (param_1 != 0x30) {
              return 0xffffffff;
            }
          }
        }
        else if ((param_1 != 0x45) && (param_1 != 0x57)) {
          return 0xffffffff;
        }
      }
    }
    else if (param_1 != 0x68) {
      if (param_1 < 0x69) {
        if (param_1 == 99) {
          *param_3 = 0;
LAB_300ffff4:
          *(undefined4 *)(param_5 + 0x1c) = 0;
          strcpy(*(char **)(param_5 + 0x14),(char *)(param_2 + *param_3));
          *(undefined1 *)(param_2 + *param_3) = 0;
          *param_4 = 0;
          return 0;
        }
        if (param_1 != 0x65) {
          return 0xffffffff;
        }
      }
      else if ((param_1 != 0x6c) && (param_1 != 0x77)) {
        return 0xffffffff;
      }
    }
  }
  uVar1 = ledCDelete(param_1,param_2,param_3,param_4,param_5);
  *(undefined4 *)(param_5 + 0x1c) = 0;
  return uVar1;
}

/* ----------------------------------------------------------------
 * ledReplace @ 0x30100034  (примерный размер ~112 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: memset, strlen
 * Константы: 0x30100034
 * ---------------------------------------------------------------- */
undefined4 ledReplace(int param_1,int param_2,int *param_3,size_t *param_4)

{
  size_t sVar1;
  char *__s;
  size_t __n;
  
  if ((int)*param_4 < 1) {
    *param_4 = 1;
  }
  if (param_1 != 0x1b) {
    __n = *param_4;
    __s = (char *)(param_2 + *param_3);
    sVar1 = strlen(__s);
    if ((int)sVar1 <= (int)__n) {
      __n = strlen(__s);
    }
    memset(__s,param_1,__n);
  }
  *param_4 = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * ledBeep @ 0x301000A4  (примерный размер ~12 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: write
 * Вызывают: FUN_30112ec0
 * Константы: 0x301000A4
 * Данные: DAT_30100524
 * ---------------------------------------------------------------- */
void ledBeep(int param_1)

{
  write(param_1,DAT_30100524,1);
  return;
}

/* ----------------------------------------------------------------
 * ledHistNumGet @ 0x301000B0  (примерный размер ~204 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: lstCount, lstFirst, lstNext, strncpy
 * Константы: 0x301000B0
 * ---------------------------------------------------------------- */
undefined4 ledHistNumGet(int param_1,int param_2,char *param_3,size_t param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x18);
  if (iVar1 == -1) {
    iVar1 = lstCount(*(int *)(param_1 + 8) + 4);
  }
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x10);
  iVar1 = (iVar2 - iVar1) + 1;
  if ((param_2 < iVar1) || (iVar2 < param_2)) {
    return 0;
  }
  iVar2 = lstFirst(*(int *)(param_1 + 8) + 4);
  if (iVar2 != 0) {
    do {
      if (iVar1 == param_2) break;
      iVar2 = lstNext(iVar2);
      iVar1 = iVar1 + 1;
    } while (iVar2 != 0);
    if (iVar2 != 0) {
      strncpy(param_3,*(char **)(iVar2 + 0xc),param_4);
      **(int **)(param_1 + 8) = iVar2;
      return 1;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ledHistNextGet @ 0x3010017C  (примерный размер ~212 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: lstFind, lstFirst, lstNext, strncpy
 * Константы: 0x3010017C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 ledHistNextGet(int param_1,char *param_2,size_t param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  piVar3 = *(int **)(param_1 + 8);
  if (*piVar3 != 0) {
    if ((piVar3[6] != -1) &&
       (iVar1 = lstFind(piVar3 + 1,*piVar3), iVar1 == *(int *)(*(int *)(param_1 + 8) + 0x18))) {
      **(undefined4 **)(param_1 + 8) = 0;
    }
    piVar3 = *(int **)(param_1 + 8);
    iVar1 = *piVar3;
    if (iVar1 != 0) {
      iVar1 = lstNext(iVar1);
      *piVar3 = iVar1;
      if (**(int **)(param_1 + 8) != 0) goto LAB_30100220;
    }
  }
  puVar4 = *(undefined4 **)(param_1 + 8);
  uVar2 = lstFirst(puVar4 + 1);
  *puVar4 = uVar2;
  if (**(int **)(param_1 + 8) == 0) {
    return 0xffffffff;
  }
LAB_30100220:
  if (param_2 != (char *)0x0) {
    strncpy(param_2,*(char **)(**(int **)(param_1 + 8) + 0xc),param_3);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ledHistPrevGet @ 0x30100250  (примерный размер ~156 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: lstLast, lstNth, lstPrevious, strncpy
 * Константы: 0x30100250, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 ledHistPrevGet(int param_1,char *param_2,size_t param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 8);
  iVar1 = *piVar2;
  if (iVar1 != 0) {
    iVar1 = lstPrevious(iVar1);
    *piVar2 = iVar1;
  }
  piVar2 = *(int **)(param_1 + 8);
  if (*piVar2 == 0) {
    if (piVar2[6] == -1) {
      iVar1 = lstLast();
    }
    else {
      iVar1 = lstNth(piVar2 + 1,piVar2[6]);
    }
    **(int **)(param_1 + 8) = iVar1;
    if (iVar1 == 0) {
      return 0xffffffff;
    }
  }
  if (param_2 != (char *)0x0) {
    strncpy(param_2,*(char **)(**(int **)(param_1 + 8) + 0xc),param_3);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ledHistFind @ 0x301002EC  (примерный размер ~576 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 11
 * Вызывает: lstCount, lstFind, lstFirst, lstLast, lstNext, lstNth, lstPrevious, strchr, strlen, strncmp, strncpy
 * Вызывают: FUN_30112ec0
 * Константы: 0x301002EC
 * ---------------------------------------------------------------- */
undefined4 ledHistFind(int param_1,char *param_2,char *param_3,size_t param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  int iVar6;
  char *__src;
  int iVar7;
  bool bVar8;
  
  iVar7 = **(int **)(param_1 + 8);
  bVar8 = *param_2 != '?';
  iVar2 = lstCount(*(int **)(param_1 + 8) + 1);
  iVar2 = iVar2 + 1;
  *param_3 = '\0';
  if (iVar7 != 0) {
    if (bVar8) {
      iVar7 = lstPrevious(iVar7);
    }
    else {
      iVar3 = lstFind(*(int *)(param_1 + 8) + 4,iVar7);
      iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x18);
      if ((iVar6 != -1) && (iVar6 == iVar3)) goto LAB_30100394;
      iVar7 = lstNext(iVar7);
    }
    if (iVar7 != 0) goto LAB_301003d8;
  }
LAB_30100394:
  if (bVar8) {
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x18);
    iVar7 = *(int *)(param_1 + 8) + 4;
    if (iVar3 == -1) {
      iVar7 = lstLast(iVar7);
    }
    else {
      iVar7 = lstNth(iVar7,iVar3);
    }
  }
  else {
    iVar7 = lstFirst(*(int *)(param_1 + 8) + 4);
  }
  if (iVar7 == 0) {
    return 0;
  }
LAB_301003d8:
  do {
    __src = *(char **)(iVar7 + 0xc);
    bVar1 = param_2[1];
    pcVar4 = __src;
    do {
      pcVar4 = strchr(pcVar4,(uint)bVar1);
      if (pcVar4 == (char *)0x0) break;
      sVar5 = strlen(param_2);
      iVar3 = strncmp(pcVar4,param_2 + 1,sVar5 - 1);
      if (iVar3 == 0) {
        strncpy(param_3,__src,param_4);
        **(int **)(param_1 + 8) = iVar7;
        return 1;
      }
      pcVar4 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    if (bVar8) {
      iVar7 = lstPrevious(iVar7);
      if (iVar7 == 0) {
        iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x18);
        iVar7 = *(int *)(param_1 + 8) + 4;
        if (iVar3 == -1) {
          iVar7 = lstLast(iVar7);
        }
        else {
          iVar7 = lstNth(iVar7,iVar3);
        }
        goto LAB_301004dc;
      }
    }
    else {
      iVar3 = lstFind(*(int *)(param_1 + 8) + 4,iVar7);
      iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x18);
      if (((iVar6 != -1) && (iVar6 == iVar3)) || (iVar7 = lstNext(iVar7), iVar7 == 0)) {
        iVar7 = lstFirst(*(int *)(param_1 + 8) + 4);
LAB_301004dc:
        if (iVar7 == 0) {
          return 0;
        }
      }
    }
    iVar2 = iVar2 + -1;
    if (iVar2 < 1) {
      return 0;
    }
  } while( true );
}

