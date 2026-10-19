/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : dload — протоколы заливки: AT-команды загрузчика, DLOAD, TFUP, обновление
 * Часть  : 1 (функций: 75, адреса 0x30074FC0..0x3009B400)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * DLOAD_LEDInd @ 0x30074FC0  (примерный размер ~80 байт)
 * Модуль: dload | Вызывают: 3 | Вызывает: 1
 * Вызывает: BSP_MNTN_LedFlush
 * Вызывают: FUN_30080798, ledFlush, update_WebUITask
 * Константы: 0x30074FC0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 DLOAD_LEDInd(int param_1)

{
  if (param_1 == 1) {
    BSP_MNTN_LedFlush(9);
  }
  else if (param_1 == 2) {
    BSP_MNTN_LedFlush(0);
  }
  else if (param_1 != 3) {
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * dloadGetNvImeiNumber @ 0x30075700  (примерный размер ~48 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 1
 * Вызывает: DR_NV_Read
 * Вызывают: getAuthorityId
 * Константы: 0x30075700, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 dloadGetNvImeiNumber(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DR_NV_Read(0,param_1,0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * dloadIsDefaultImeiValue @ 0x30075730  (примерный размер ~120 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 0
 * Вызывают: getAuthorityId
 * Константы: 0x30075730, 0xFFFFFFFF
 * Данные: DAT_300762b0
 * ---------------------------------------------------------------- */
undefined4 dloadIsDefaultImeiValue(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined1 *puVar3;
  byte bVar4;
  char local_18 [16];
  
  iVar1 = 0x10;
  pcVar2 = local_18;
  puVar3 = DAT_300762b0;
  do {
    iVar1 = iVar1 + -1;
    *pcVar2 = *puVar3;
    pcVar2 = pcVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar1 != 0);
  bVar4 = 0;
  while( true ) {
    if (0xf < bVar4) {
      return 0;
    }
    if (*(char *)(param_1 + (uint)bVar4) != local_18[bVar4]) break;
    bVar4 = bVar4 + 1;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * dloadUSBSend @ 0x30076850  (примерный размер ~132 байт)
 * Модуль: dload | Вызывают: 4 | Вызывает: 4
 * Вызывает: BSP_DLOAD_SendData, logMsg, memalign, memcpy
 * Вызывают: ATCommandHandle, ATCommandProcess, dloadInfoATHandle, dloadUSBSendPro
 * Константы: 0x30076850, 0xFFFFFFFF
 * Данные: DAT_300769dc
 * ---------------------------------------------------------------- */
undefined4 dloadUSBSend(void *param_1,size_t param_2)

{
  void *__dest;
  undefined4 uVar1;
  
  __dest = (void *)memalign(0x20,param_2);
  if (__dest == (void *)0x0) {
    logMsg(DAT_300769dc,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    memcpy(__dest,param_1,param_2);
    uVar1 = BSP_DLOAD_SendData(__dest,param_2);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * dload_nand_init @ 0x30076B08  (примерный размер ~88 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 2
 * Вызывает: __udiv32, nand_get_spec
 * Вызывают: dloadInit
 * Константы: 0x30076B08
 * Данные: DAT_300773fc, DAT_30077400, DAT_30077404, DAT_30077408
 * ---------------------------------------------------------------- */
void dload_nand_init(void)

{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  nand_get_spec(&local_14);
  *DAT_300773fc = local_10;
  uVar1 = __udiv32(local_c,local_14);
  *DAT_30077400 = uVar1;
  uVar1 = __udiv32(local_14,local_10);
  *DAT_30077404 = uVar1;
  *DAT_30077408 = local_c;
  return;
}

/* ----------------------------------------------------------------
 * TFUP_getTFUpdateFlag @ 0x30076B60  (примерный размер ~72 байт)
 * Модуль: dload | Вызывают: 4 | Вызывает: 0
 * Вызывают: BSP_DRV_BOOTROM_Init, BSP_TFUP_CompleteDeal, TFUP_CompleteDeal, dloadInit
 * Константы: 0x30076B60
 * Данные: DAT_3007740c, DAT_30077410, DAT_30077414
 * ---------------------------------------------------------------- */
int TFUP_getTFUpdateFlag(void)

{
  int iVar1;
  
  if (*DAT_3007740c == DAT_30077410) {
    iVar1 = 1;
  }
  else {
    iVar1 = (uint)(*DAT_3007740c == DAT_30077414) << 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * dloadInit @ 0x30076BA8  (примерный размер ~792 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 13
 * Вызывает: DCBInit, OSAL_LogMsg, OSAL_SemBCreate, OSAL_SemDelete, Om_HdlcInit, TFUP_getTFUpdateFlag, dload_nand_init, drvSecCheck, free, getFactoryMode, malloc, sdmmcAddHook, taskSpawn
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0xFFFFFFFF, 0x30076BA8
 * Данные: DAT_30077418, DAT_3007741c, DAT_30077420, DAT_30077424, DAT_30077428, DAT_3007742c, DAT_30077430, DAT_30077434
 * ---------------------------------------------------------------- */
undefined4 dloadInit(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  dload_nand_init();
  iVar1 = TFUP_getTFUpdateFlag();
  if ((iVar1 == 1) && (iVar1 = sdmmcAddHook(0,DAT_30077418), iVar1 != 0)) {
    OSAL_LogMsg(DAT_3007741c,1,2,3,4,5,6);
    uVar2 = 0xffffffff;
  }
  else {
    if (*DAT_30077420 == 0) {
      pvVar3 = malloc(0x28);
      *DAT_30077420 = (int)pvVar3;
      if (*DAT_30077420 == 0) {
        OSAL_LogMsg(DAT_30077424,1,2,3,4,5,6);
        return 0xffffffff;
      }
    }
    *(undefined4 *)*DAT_30077420 = 5;
    DCBInit();
    uVar2 = drvSecCheck();
    *DAT_30077428 = uVar2;
    uVar2 = getFactoryMode();
    *DAT_3007742c = uVar2;
    iVar1 = TFUP_getTFUpdateFlag();
    if (iVar1 == 1) {
      if (*DAT_30077430 == 0) {
        iVar1 = OSAL_SemBCreate(0,0);
        *DAT_30077430 = iVar1;
        if (*DAT_30077430 == 0) {
          free((void *)*DAT_30077420);
          *DAT_30077420 = 0;
          OSAL_LogMsg(DAT_30077434,1,2,3,4,5,6);
          return 0xffffffff;
        }
      }
      iVar1 = taskSpawn(DAT_3007743c,0x36,0,0x2000,DAT_30077438,0,0,0,0,0,0,0,0,0,0);
      if (iVar1 == -1) {
        OSAL_SemDelete(*DAT_30077430);
        free((void *)*DAT_30077420);
        *DAT_30077420 = 0;
        OSAL_LogMsg(DAT_30077440,1,2,3,4,5,6);
        return 0xffffffff;
      }
    }
    if (*(int *)(DAT_30077444 + 0xc) == 0) {
      pvVar3 = malloc(0x2200);
      *(void **)(DAT_30077444 + 0xc) = pvVar3;
      if (*(int *)(DAT_30077444 + 0xc) == 0) {
        OSAL_LogMsg(DAT_30077448,1,2,3,4,5,6);
        OSAL_SemDelete(*DAT_30077430);
        free((void *)*DAT_30077420);
        *DAT_30077420 = 0;
        if (*DAT_3007744c != 0) {
          free((void *)*DAT_3007744c);
          *DAT_3007744c = 0;
        }
        return 0xffffffff;
      }
      Om_HdlcInit(DAT_30077444);
      *(undefined4 *)(DAT_30077444 + 8) = 0x2200;
    }
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * dloadBootromEnd @ 0x30076EC0  (примерный размер ~64 байт)
 * Модуль: dload | Вызывают: 3 | Вызывает: 6
 * Вызывает: BSP_DLOAD_Reset, BSP_DLOAD_SetMidwayRestart, BSP_DLOAD_SetSoftLoad, dloadNeedMidwayRestart, ptable_replace_flash_table, ptable_set_integrality
 * Вызывают: FUN_30080798, TFUP_DloadTask, update_WebUITask
 * Константы: 0x30076EC0
 * ---------------------------------------------------------------- */
void dloadBootromEnd(void)

{
  int iVar1;
  
  BSP_DLOAD_SetSoftLoad(0);
  iVar1 = dloadNeedMidwayRestart();
  if (iVar1 == 0) {
    BSP_DLOAD_SetMidwayRestart(0);
    ptable_set_integrality(0);
  }
  else {
    BSP_DLOAD_SetMidwayRestart(1);
  }
  ptable_replace_flash_table();
  BSP_DLOAD_Reset();
  return;
}

/* ----------------------------------------------------------------
 * TFUP_setTFUpdateFlag @ 0x30076F00  (примерный размер ~100 байт)
 * Модуль: dload | Вызывают: 4 | Вызывает: 1
 * Вызывает: writeM
 * Вызывают: BSP_TFUP_CompleteDeal, TFUP_CheckTask, TFUP_CompleteDeal, TFUP_DloadTask
 * Константы: 0x30076F00, 0xFFFFFFFF
 * Данные: DAT_3007740c, DAT_30077410, DAT_30077414
 * ---------------------------------------------------------------- */
undefined4 TFUP_setTFUpdateFlag(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    writeM(DAT_3007740c,DAT_30077410);
    uVar1 = 0;
  }
  else if (param_1 == 0) {
    writeM(DAT_3007740c,0);
    uVar1 = 0;
  }
  else if (param_1 == 2) {
    writeM(DAT_3007740c,DAT_30077414);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * TFUP_SetBootromFlag @ 0x30076F64  (примерный размер ~72 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 1
 * Вызывает: writeM
 * Константы: 0x30076F64, 0xFFFFFFFF
 * Данные: DAT_30077414, DAT_30077450
 * ---------------------------------------------------------------- */
undefined4 TFUP_SetBootromFlag(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    writeM(DAT_30077450,DAT_30077414);
    uVar1 = 0;
  }
  else if (param_1 == 0) {
    writeM(DAT_30077450,0);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * TFUP_GetBootromFlag @ 0x30076FAC  (примерный размер ~44 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30076FAC
 * Данные: DAT_30077414, DAT_30077450
 * ---------------------------------------------------------------- */
bool TFUP_GetBootromFlag(void)

{
  return *DAT_30077450 == DAT_30077414;
}

/* ----------------------------------------------------------------
 * TFUP_SetSuccessFlag @ 0x30076FD8  (примерный размер ~72 байт)
 * Модуль: dload | Вызывают: 3 | Вызывает: 1
 * Вызывает: writeM
 * Вызывают: BSP_TFUP_CompleteDeal, TFUP_CompleteDeal, TFUP_DloadTask
 * Константы: 0x30076FD8, 0xFFFFFFFF
 * Данные: DAT_30077454, DAT_30077458
 * ---------------------------------------------------------------- */
undefined4 TFUP_SetSuccessFlag(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    writeM(DAT_30077454,DAT_30077458);
    uVar1 = 0;
  }
  else if (param_1 == 0) {
    writeM(DAT_30077454,0);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * TFUP_GetSuccessFlag @ 0x30077020  (примерный размер ~44 байт)
 * Модуль: dload | Вызывают: 2 | Вызывает: 0
 * Вызывают: BSP_TFUP_CompleteDeal, TFUP_CompleteDeal
 * Константы: 0x30077020
 * Данные: DAT_30077454, DAT_30077458
 * ---------------------------------------------------------------- */
bool TFUP_GetSuccessFlag(void)

{
  return *DAT_30077454 == DAT_30077458;
}

/* ----------------------------------------------------------------
 * TFUP_SetGoOn @ 0x3007704C  (примерный размер ~48 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 1
 * Вызывает: writeM
 * Константы: 0x3007704C
 * Данные: DAT_3007745c, DAT_30077460
 * ---------------------------------------------------------------- */
void TFUP_SetGoOn(int param_1)

{
  if (param_1 == 0) {
    writeM(DAT_3007745c,0);
  }
  else {
    writeM(DAT_3007745c,DAT_30077460);
  }
  return;
}

/* ----------------------------------------------------------------
 * TFUP_GetGoOn @ 0x3007707C  (примерный размер ~28 байт)
 * Модуль: dload | Вызывают: 2 | Вызывает: 0
 * Вызывают: BSP_TFUP_CompleteDeal, TFUP_CompleteDeal
 * Константы: 0x3007707C
 * Данные: DAT_3007745c, DAT_30077460
 * ---------------------------------------------------------------- */
bool TFUP_GetGoOn(void)

{
  return *DAT_3007745c == DAT_30077460;
}

/* ----------------------------------------------------------------
 * TFUP_CompleteDeal @ 0x300770E4  (примерный размер ~92 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 8
 * Вызывает: BSP_DLOAD_Reset, BSP_DLOAD_SetCdromMarker, TFUP_GetGoOn, TFUP_GetSuccessFlag, TFUP_SetSuccessFlag, TFUP_getTFUpdateFlag, TFUP_setTFUpdateFlag, taskDelay
 * Константы: 0x300770E4
 * ---------------------------------------------------------------- */
void TFUP_CompleteDeal(void)

{
  int iVar1;
  
  iVar1 = TFUP_getTFUpdateFlag();
  if (iVar1 == 2) {
    BSP_DLOAD_SetCdromMarker(1);
    iVar1 = TFUP_GetSuccessFlag();
    TFUP_setTFUpdateFlag(0);
    if ((iVar1 == 1) && (iVar1 = TFUP_GetGoOn(), iVar1 != 0)) {
      taskDelay(100);
      TFUP_SetSuccessFlag(0);
      BSP_DLOAD_Reset();
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * TFUP_DloadTask @ 0x30077164  (примерный размер ~804 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 11
 * Вызывает: BSP_DLOAD_SetCdromMarker, OSAL_LogMsg, OSAL_SemTake, TFUP_LogPrintf, TFUP_SetSuccessFlag, TFUP_setTFUpdateFlag, dloadBootromEnd, dloadTFPro, free, malloc, tickGet
 * Константы: 0xFFFFFFFF, 0x30077164
 * Данные: DAT_30077430, DAT_30077468, DAT_3007746c, DAT_30077470, DAT_30077474, DAT_30077478, DAT_3007747c, DAT_30077480
 * ---------------------------------------------------------------- */
void TFUP_DloadTask(void)

{
  longlong lVar1;
  uint uVar2;
  void *__ptr;
  int iVar3;
  ulonglong uVar4;
  
  while( true ) {
    OSAL_SemTake(*DAT_30077430,0xffffffff);
    uVar4 = tickGet();
    lVar1 = (ulonglong)DAT_30077468 * (uVar4 & 0xffffffff);
    uVar2 = tickGet((int)uVar4,(int)(uVar4 >> 0x20),(int)lVar1);
    TFUP_LogPrintf(DAT_3007746c,(uint)((ulonglong)DAT_30077468 * (ulonglong)uVar2 >> 0x25),
                   (int)uVar4 + (uint)((ulonglong)lVar1 >> 0x25) * -100,0);
    __ptr = malloc(0x620);
    if (__ptr == (void *)0x0) break;
    iVar3 = dloadTFPro(__ptr);
    if (iVar3 == 0) {
      if (*DAT_30077478 == 1) {
        BSP_DLOAD_SetCdromMarker(0);
      }
      else {
        BSP_DLOAD_SetCdromMarker(1);
      }
      TFUP_setTFUpdateFlag(2);
      uVar4 = tickGet();
      lVar1 = (ulonglong)DAT_30077468 * (uVar4 & 0xffffffff);
      uVar2 = tickGet((int)uVar4,(int)(uVar4 >> 0x20),(int)lVar1);
      TFUP_LogPrintf(DAT_3007747c,(uint)((ulonglong)DAT_30077468 * (ulonglong)uVar2 >> 0x25),
                     (int)uVar4 + (uint)((ulonglong)lVar1 >> 0x25) * -100,0);
      OSAL_LogMsg(DAT_30077480,1,2,3,4,5,6);
      TFUP_SetSuccessFlag(1);
      dloadBootromEnd(0x20);
    }
    else {
      TFUP_setTFUpdateFlag(0);
      TFUP_SetSuccessFlag(0);
      uVar4 = tickGet();
      lVar1 = (ulonglong)DAT_30077468 * (uVar4 & 0xffffffff);
      uVar2 = tickGet((int)uVar4,(int)(uVar4 >> 0x20),(int)lVar1);
      TFUP_LogPrintf(DAT_30077484,(uint)((ulonglong)DAT_30077468 * (ulonglong)uVar2 >> 0x25),
                     (int)uVar4 + (uint)((ulonglong)lVar1 >> 0x25) * -100,0);
    }
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
  }
  uVar4 = tickGet();
  lVar1 = (ulonglong)DAT_30077468 * (uVar4 & 0xffffffff);
  uVar2 = tickGet((int)uVar4,(int)(uVar4 >> 0x20),(int)lVar1);
  TFUP_LogPrintf(DAT_30077470,(uint)((ulonglong)DAT_30077468 * (ulonglong)uVar2 >> 0x25),
                 (int)uVar4 + (uint)((ulonglong)lVar1 >> 0x25) * -100,0);
  OSAL_LogMsg(DAT_30077474,1,2,3,4,5,6);
  return;
}

/* ----------------------------------------------------------------
 * dloadFromFsGetUnitHeadData @ 0x30077488  (примерный размер ~1384 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 10
 * Вызывает: OSAL_LogMsg, fclose, fopen, fread, fseek, ftell, memcpy, memset, snprintf, update_record_file
 * Вызывают: dloadFromFsMainThread
 * Константы: 0xFFFFFFFF, 0x30077488, 0xFFFFFFFC
 * Данные: DAT_3007840c, DAT_30078410, DAT_30078414, DAT_30078510, DAT_30078514, DAT_30078518, DAT_3007851c, DAT_30078520
 * ---------------------------------------------------------------- */
undefined4 dloadFromFsGetUnitHeadData(char *param_1,void *param_2,byte *param_3)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  FILE *__stream;
  uint uVar4;
  size_t sVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  uint __off;
  uint uVar9;
  byte bVar10;
  int iVar11;
  char acStack_130 [256];
  
  __off = 0x5c;
  bVar10 = 0;
  pcVar6 = acStack_130;
  iVar11 = 0x80;
  pcVar8 = DAT_3007840c;
  do {
    pcVar7 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 2;
    cVar2 = *pcVar7;
    iVar11 = iVar11 + -1;
    pcVar7 = pcVar6 + 1;
    *pcVar6 = cVar1;
    pcVar6 = pcVar6 + 2;
    *pcVar7 = cVar2;
  } while (iVar11 != 0);
  if (((param_2 == (void *)0x0) || (param_1 == (char *)0x0)) || (param_3 == (byte *)0x0)) {
    OSAL_LogMsg(DAT_30078410,1,2,3,4,5,6);
    memset(acStack_130,0x100,0);
    snprintf(acStack_130,0x100,DAT_30078414,param_2,param_1,param_3);
    update_record_file(acStack_130);
    uVar3 = 0xffffffff;
  }
  else {
    __stream = fopen(param_1,DAT_30078510);
    if (__stream == (FILE *)0x0) {
      OSAL_LogMsg(DAT_30078514,1,2,3,4,5,6);
      OSAL_LogMsg(DAT_30078518,param_1,2,3,4,5,6);
      memset(acStack_130,0x100,0);
      snprintf(acStack_130,0x100,DAT_3007851c,param_1);
      update_record_file(acStack_130);
      uVar3 = 0xffffffff;
    }
    else {
      iVar11 = fseek(__stream,0,2);
      if (iVar11 == -1) {
        fclose(__stream);
        OSAL_LogMsg(DAT_30078520,1,2,3,4,5,6);
        memset(acStack_130,0x100,0);
        snprintf(acStack_130,0x100,DAT_3007861c);
        update_record_file(acStack_130);
        uVar3 = 0xffffffff;
      }
      else {
        uVar4 = ftell(__stream);
        if (uVar4 == 0xffffffff) {
          fclose(__stream);
          OSAL_LogMsg(DAT_30078620,1,2,3,4,5,6);
          memset(acStack_130,0x100,0);
          snprintf(acStack_130,0x100,DAT_30078624);
          update_record_file(acStack_130);
          uVar3 = 0xffffffff;
        }
        else {
          OSAL_LogMsg(DAT_30078628,uVar4,2,3,4,5,6);
          for (iVar11 = 0; iVar11 < 0x10; iVar11 = iVar11 + 1) {
            memset((void *)(iVar11 * 0x62 + (int)DAT_3007862c),0,0x62);
          }
          for (; __off < uVar4; __off = __off + uVar9) {
            iVar11 = fseek(__stream,__off,0);
            if (iVar11 == -1) {
              fclose(__stream);
              OSAL_LogMsg(DAT_30078520,1,2,3,4,5,6);
              return 0xffffffff;
            }
            if (0xf < bVar10) {
              fclose(__stream);
              OSAL_LogMsg(DAT_30078794,1,2,3,4,5,6);
              return 0xffffffff;
            }
            sVar5 = fread((void *)((uint)bVar10 * 0x62 + (int)DAT_3007862c),0x62,1,__stream);
            if (sVar5 == 0) {
              fclose(__stream);
              OSAL_LogMsg(DAT_30078798,1,2,3,4,5,6);
              return 0xffffffff;
            }
            if (*(int *)((uint)bVar10 * 0x62 + (int)DAT_3007862c) != DAT_3007879c) break;
            uVar9 = *(int *)((uint)bVar10 * 0x62 + DAT_300787a0) +
                    *(int *)((uint)bVar10 * 0x62 + DAT_300787a4);
            if ((uVar9 & 3) != 0) {
              uVar9 = (uVar9 & 0xfffffffc) + 4;
            }
            bVar10 = bVar10 + 1;
          }
          iVar11 = fclose(__stream);
          if ((iVar11 == 0) || (iVar11 = fclose(__stream), iVar11 == 0)) {
            *param_3 = bVar10;
            memcpy(param_2,DAT_3007862c,(uint)bVar10 * 0x62);
            uVar3 = 0;
          }
          else {
            OSAL_LogMsg(DAT_300788f4,1,2,3,4,5,6);
            uVar3 = 0xffffffff;
          }
        }
      }
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * dloadFromFsCheckSpaceForISO @ 0x300779F0  (примерный размер ~252 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, dload_GetISOUseableSize, omTimerTickGet, snprintf, update_record_file
 * Вызывают: dloadFromFsMainThread
 * Константы: 0x300779F0, 0xFFFFFFFF
 * Данные: DAT_300788f8, DAT_300788fc, DAT_30078900, DAT_30078a00
 * ---------------------------------------------------------------- */
undefined4 dloadFromFsCheckSpaceForISO(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char acStack_108 [256];
  
  iVar8 = 0x80;
  pcVar5 = acStack_108;
  pcVar7 = DAT_300788f8;
  do {
    pcVar6 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 2;
    cVar2 = *pcVar6;
    iVar8 = iVar8 + -1;
    pcVar6 = pcVar5 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 2;
    *pcVar6 = cVar2;
  } while (iVar8 != 0);
  if ((*(int *)(*DAT_300788fc + 4) == 0x10c) &&
     (uVar3 = dload_GetISOUseableSize(*(undefined4 *)(*DAT_300788fc + 4),cVar2,acStack_108),
     uVar3 < *(uint *)(*DAT_300788fc + 8))) {
    OSAL_LogMsg(DAT_30078900,*(undefined4 *)(*DAT_300788fc + 8),2,3,4,5,6);
    uVar4 = omTimerTickGet();
    snprintf(acStack_108,0x100,DAT_30078a00,uVar4,*(undefined4 *)(*DAT_300788fc + 8));
    update_record_file(acStack_108);
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * dloadFromFsReadDataFromFS @ 0x30077AEC  (примерный размер ~668 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 9
 * Вызывает: OSAL_LogMsg, fclose, fopen, fread, fseek, memset, omTimerTickGet, snprintf, update_record_file
 * Вызывают: dloadFromFsGetUnitData
 * Константы: 0xFFFFFFFF, 0x30077AEC
 * Данные: DAT_30078510, DAT_30078a04, DAT_30078a08, DAT_30078a0c, DAT_30078b3c, DAT_30078b40, DAT_30078b44, DAT_30078b48
 * ---------------------------------------------------------------- */
size_t dloadFromFsReadDataFromFS(char *param_1,void *param_2,long param_3,size_t param_4)

{
  char cVar1;
  char cVar2;
  FILE *__stream;
  undefined4 uVar3;
  size_t sVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char acStack_11c [256];
  
  pcVar5 = acStack_11c;
  iVar8 = 0x80;
  pcVar7 = DAT_30078a04;
  do {
    pcVar6 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 2;
    cVar2 = *pcVar6;
    iVar8 = iVar8 + -1;
    pcVar6 = pcVar5 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 2;
    *pcVar6 = cVar2;
  } while (iVar8 != 0);
  __stream = fopen(param_1,DAT_30078510);
  if (__stream == (FILE *)0x0) {
    OSAL_LogMsg(DAT_30078a08,1,2,3,4,5,6);
    memset(acStack_11c,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_11c,0x100,DAT_30078a0c,uVar3);
    update_record_file(acStack_11c);
    sVar4 = 0xffffffff;
  }
  else {
    iVar8 = fseek(__stream,param_3,0);
    if (iVar8 == -1) {
      fclose(__stream);
      OSAL_LogMsg(DAT_30078b3c,1,2,3,4,5,6);
      memset(acStack_11c,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_11c,0x100,DAT_30078b40,uVar3);
      update_record_file(acStack_11c);
      sVar4 = 0xffffffff;
    }
    else {
      sVar4 = fread(param_2,1,param_4,__stream);
      if (param_4 == sVar4) {
        iVar8 = fclose(__stream);
        if (iVar8 != 0) {
          OSAL_LogMsg(DAT_30078c50,1,2,3,4,5,6);
          memset(acStack_11c,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_11c,0x100,DAT_30078c54,uVar3);
          update_record_file(acStack_11c);
          sVar4 = 0xffffffff;
        }
      }
      else {
        fclose(__stream);
        OSAL_LogMsg(DAT_30078b44,1,2,3,4,5,6);
        memset(acStack_11c,0x100,0);
        uVar3 = omTimerTickGet();
        snprintf(acStack_11c,0x100,DAT_30078b48,uVar3);
        update_record_file(acStack_11c);
      }
    }
  }
  return sVar4;
}

/* ----------------------------------------------------------------
 * dloadFromFsGetUnitData @ 0x30077D88  (примерный размер ~1304 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 7
 * Вызывает: OSAL_LogMsg, dloadFromFsReadDataFromFS, memset, omTimerTickGet, snprintf, uncompress_file_to_stream, update_record_file
 * Вызывают: dloadFromFsMainThread
 * Константы: 0xFFFFFFFF, 0x30077D88, 0xFFFFFFFC
 * Данные: DAT_300787a0, DAT_300787a4, DAT_300788fc, DAT_30078c58, DAT_30078c5c, DAT_30078d60, DAT_30078e24, DAT_30078f14
 * ---------------------------------------------------------------- */
undefined4 dloadFromFsGetUnitData(int param_1,uint param_2,int param_3,int param_4)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int local_13c;
  char acStack_130 [256];
  
  iVar7 = 0x5c;
  pcVar4 = acStack_130;
  iVar9 = 0x80;
  pcVar6 = DAT_30078c58;
  do {
    pcVar5 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 2;
    cVar2 = *pcVar5;
    iVar9 = iVar9 + -1;
    pcVar5 = pcVar4 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 2;
    *pcVar5 = cVar2;
  } while (iVar9 != 0);
  if ((param_1 == 0) || (param_3 == 0)) {
    OSAL_LogMsg(DAT_30078c5c,1,2,3,4,5,6,0);
    memset(acStack_130,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_130,0x100,DAT_30078d60,uVar3,param_1,param_3);
    update_record_file(acStack_130);
    uVar3 = 0xffffffff;
  }
  else {
    for (iVar9 = 0; iVar9 < (int)(param_2 & 0xff); iVar9 = iVar9 + 1) {
      uVar8 = *(int *)(iVar9 * 0x62 + DAT_300787a0) + *(int *)(iVar9 * 0x62 + DAT_300787a4);
      if ((uVar8 & 3) != 0) {
        uVar8 = (uVar8 & 0xfffffffc) + 4;
      }
      iVar7 = iVar7 + uVar8;
    }
    iVar7 = param_4 * *DAT_30078e24 + iVar7 + *(int *)(iVar9 * 0x62 + DAT_300787a0);
    uVar8 = *(int *)((param_2 & 0xff) * 0x62 + DAT_300787a0) +
            *(int *)((param_2 & 0xff) * 0x62 + DAT_300787a4);
    if ((uint)(param_4 * *DAT_30078e24 + *(int *)(iVar9 * 0x62 + DAT_300787a0)) < uVar8) {
      if (uVar8 < (uint)(param_4 * *DAT_30078e24 +
                        *DAT_30078e24 + *(int *)(iVar9 * 0x62 + DAT_300787a0))) {
        local_13c = (uVar8 - *(int *)(iVar9 * 0x62 + DAT_300787a0)) - *DAT_30078e24 * param_4;
      }
      else {
        local_13c = *DAT_30078e24;
      }
      if (*(int *)(*DAT_300788fc + 8) == *(int *)((param_2 & 0xff) * 0x62 + DAT_300787a4)) {
        iVar7 = dloadFromFsReadDataFromFS(param_1,param_3,iVar7,local_13c);
        if (iVar7 == -1) {
          OSAL_LogMsg(DAT_300790b0,1,2,3,4,5,6);
          memset(acStack_130,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_130,0x100,DAT_300790b4,uVar3);
          update_record_file(acStack_130);
          return 0xffffffff;
        }
      }
      else {
        iVar7 = uncompress_file_to_stream(param_1,iVar7,param_3,*(undefined4 *)(*DAT_300788fc + 8));
        if (iVar7 != 0) {
          OSAL_LogMsg(DAT_300790b8,1,2,3,4,5,6);
          memset(acStack_130,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_130,0x100,DAT_300790bc,uVar3);
          update_record_file(acStack_130);
          return 0xffffffff;
        }
      }
      uVar3 = 0;
    }
    else {
      OSAL_LogMsg(DAT_30078f14,1,2,3,4,5,6);
      memset(acStack_130,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_130,0x100,DAT_30078f18,uVar3);
      update_record_file(acStack_130);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * dloadFromFsGetUnitSize @ 0x300782A0  (примерный размер ~1000 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 6
 * Вызывает: OSAL_LogMsg, get_uncompress_length, memset, omTimerTickGet, snprintf, update_record_file
 * Вызывают: dloadFromFsMainThread
 * Константы: 0x300782A0, 0xFFFFFFFC
 * Данные: DAT_300787a0, DAT_300787a4, DAT_300791e4, DAT_300791e8, DAT_300791ec, DAT_300793c4, DAT_300793c8, DAT_300794a4
 * ---------------------------------------------------------------- */
int dloadFromFsGetUnitSize(int param_1,uint param_2)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int local_130;
  uint local_12c;
  char acStack_128 [256];
  
  local_12c = 0;
  iVar8 = 0x5c;
  local_130 = 0;
  pcVar4 = acStack_128;
  iVar9 = 0x80;
  pcVar6 = DAT_300791e4;
  do {
    pcVar5 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 2;
    cVar2 = *pcVar5;
    iVar9 = iVar9 + -1;
    pcVar5 = pcVar4 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 2;
    *pcVar5 = cVar2;
  } while (iVar9 != 0);
  if (param_1 == 0) {
    OSAL_LogMsg(DAT_300791e8,1,2,3,4,5,6);
    memset(acStack_128,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_128,0x100,DAT_300791ec,uVar3);
    update_record_file(acStack_128);
    local_130 = -1;
  }
  else {
    for (iVar9 = 0; iVar9 < (int)(param_2 & 0xff); iVar9 = iVar9 + 1) {
      uVar7 = *(int *)(iVar9 * 0x62 + DAT_300787a0) + *(int *)(iVar9 * 0x62 + DAT_300787a4);
      if ((uVar7 & 3) != 0) {
        uVar7 = (uVar7 & 0xfffffffc) + 4;
      }
      iVar8 = iVar8 + uVar7;
    }
    local_12c = *(int *)((param_2 & 0xff) * 0x62 + DAT_300787a0) +
                *(int *)((param_2 & 0xff) * 0x62 + DAT_300787a4);
    if (*(uint *)(iVar9 * 0x62 + DAT_300787a0) < local_12c) {
      iVar8 = get_uncompress_length
                        (param_1,iVar8 + *(int *)(iVar9 * 0x62 + DAT_300787a0),
                         *(undefined4 *)((param_2 & 0xff) * 0x62 + DAT_300787a4),&local_130);
      if (iVar8 == 0) {
        if (local_130 == 0) {
          local_130 = *(int *)((param_2 & 0xff) * 0x62 + DAT_300787a4);
        }
      }
      else {
        OSAL_LogMsg(DAT_300794a4,1,2,3,4,5,6);
        memset(acStack_128,0x100,0);
        uVar3 = omTimerTickGet();
        snprintf(acStack_128,0x100,DAT_300794a8,uVar3);
        update_record_file(acStack_128);
        local_130 = -1;
      }
    }
    else {
      OSAL_LogMsg(DAT_300793c4,1,2,3,4,5,6);
      memset(acStack_128,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_128,0x100,DAT_300793c8,uVar3);
      update_record_file(acStack_128);
      local_130 = -1;
    }
  }
  return local_130;
}

/* ----------------------------------------------------------------
 * dloadFromFsMainThread @ 0x30078688  (примерный размер ~4432 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 28
 * Вызывает: BSP_DLOAD_SetCdromMarker, BSP_DLOAD_SetSoftLoad, DCBInit, OSAL_LogMsg, __udiv32, __urem32, dloadFromFsCheckSpaceForISO, dloadFromFsGetUnitData, dloadFromFsGetUnitHeadData, dloadFromFsGetUnitSize, dloadInitRamBuffer, dynFSDloadProcess, fclose, fopen
 *           ...
 * Вызывают: update_WebUITask
 * Константы: 0x30078688
 * Данные: DAT_30079574, DAT_30079578, DAT_3007957c, DAT_30079580, DAT_30079584, DAT_30079680, DAT_30079684, DAT_30079688
 * ---------------------------------------------------------------- */
undefined4 dloadFromFsMainThread(void)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  void *__ptr;
  undefined4 uVar5;
  uint uVar6;
  FILE *pFVar7;
  size_t sVar8;
  char *pcVar9;
  undefined1 *puVar10;
  char *pcVar11;
  char *pcVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  byte local_408 [4];
  uint local_404;
  undefined4 local_400;
  undefined4 local_3fc;
  undefined4 local_3f8;
  undefined4 local_3f4;
  undefined4 local_3f0;
  undefined4 local_3ec;
  undefined4 local_3e8;
  undefined4 local_3e4;
  undefined1 auStack_3e0 [200];
  char acStack_318 [256];
  undefined1 auStack_218 [500];
  
  local_408[0] = 0;
  local_404 = 0;
  local_400 = 0;
  pcVar9 = acStack_318;
  iVar19 = 0x80;
  pcVar12 = DAT_30079574;
  do {
    pcVar11 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 2;
    cVar2 = *pcVar11;
    iVar19 = iVar19 + -1;
    pcVar11 = pcVar9 + 1;
    *pcVar9 = cVar1;
    pcVar9 = pcVar9 + 2;
    *pcVar11 = cVar2;
  } while (iVar19 != 0);
  puVar10 = auStack_218;
  iVar19 = 0xfa;
  puVar14 = DAT_30079578;
  do {
    puVar13 = puVar14 + 1;
    uVar3 = *puVar14;
    puVar14 = puVar14 + 2;
    uVar4 = *puVar13;
    iVar19 = iVar19 + -1;
    puVar13 = puVar10 + 1;
    *puVar10 = uVar3;
    puVar10 = puVar10 + 2;
    *puVar13 = uVar4;
  } while (iVar19 != 0);
  uVar16 = 0;
  puVar10 = auStack_3e0;
  iVar19 = 100;
  puVar14 = DAT_3007957c;
  do {
    puVar13 = puVar14 + 1;
    uVar3 = *puVar14;
    puVar14 = puVar14 + 2;
    uVar4 = *puVar13;
    iVar19 = iVar19 + -1;
    puVar13 = puVar10 + 1;
    *puVar10 = uVar3;
    puVar10 = puVar10 + 2;
    *puVar13 = uVar4;
  } while (iVar19 != 0);
  uVar18 = 0;
  if (((*(int *)(DAT_30079580 + 8) == 2) || (*(int *)(DAT_30079580 + 8) == 3)) &&
     (*DAT_30079584 == 0)) {
    OSAL_LogMsg(DAT_30079680,1,2,3,4,5,6);
    ptable_set_integrality(1);
    ptable_replace_flash_table();
    *DAT_30079584 = 1;
  }
  BSP_DLOAD_SetSoftLoad(1);
  __ptr = malloc(0x620);
  if (__ptr == (void *)0x0) {
    OSAL_LogMsg(DAT_30079684,1,2,3,4,5,6);
    memset(acStack_318,0x100,0);
    uVar5 = omTimerTickGet();
    snprintf(acStack_318,0x100,DAT_30079688,uVar5);
    update_record_file(acStack_318);
    uVar5 = 0xb;
  }
  else {
    iVar19 = dloadFromFsGetUnitHeadData
                       (*(undefined4 *)(DAT_3007968c + *(int *)(DAT_30079580 + 8) * 4),__ptr,
                        local_408);
    if (iVar19 == 0) {
      OSAL_LogMsg(DAT_300797b0,1,2,3,4,5,6);
      memset(acStack_318,0x100,0);
      uVar5 = omTimerTickGet();
      snprintf(acStack_318,0x100,DAT_300797b4,uVar5);
      update_record_file(acStack_318);
      OSAL_LogMsg(DAT_300797b8,local_408[0],2,3,4,5,6);
      memset(acStack_318,0x100,0);
      local_3e4 = omTimerTickGet();
      snprintf(acStack_318,0x100,DAT_30079894,local_3e4,(uint)local_408[0]);
      update_record_file(acStack_318);
      for (uVar15 = 0; (uVar15 & 0xff) < (uint)local_408[0]; uVar15 = uVar15 + 1) {
        DCBInit();
        uVar17 = 0;
        *(undefined4 *)(*DAT_30079898 + 4) =
             *(undefined4 *)((int)__ptr + (uVar15 & 0xff) * 0x62 + 0x14);
        OSAL_LogMsg(DAT_30079944,local_408[0],(uVar15 & 0xff) + 1,*(undefined4 *)(*DAT_30079898 + 4)
                    ,4,5,6);
        memset(acStack_318,0x100,0);
        local_3e8 = omTimerTickGet();
        snprintf(acStack_318,0x100,DAT_30079948,local_3e8,(uint)local_408[0],(uVar15 & 0xff) + 1,
                 *(undefined4 *)(*DAT_30079898 + 4));
        update_record_file(acStack_318);
        iVar19 = imageTypeChange(*DAT_30079898 + 4);
        if (iVar19 != 0) {
          free(__ptr);
          OSAL_LogMsg(DAT_30079a30,*(undefined4 *)(*DAT_30079898 + 4),2,3,4,5,6);
          memset(acStack_318,0x100,0);
          local_3ec = omTimerTickGet();
          snprintf(acStack_318,0x100,DAT_30079a34,local_3ec,*(undefined4 *)(*DAT_30079898 + 4));
          update_record_file(acStack_318);
          return 0xe;
        }
        uVar5 = dloadFromFsGetUnitSize
                          (*(undefined4 *)(DAT_3007968c + *(int *)(DAT_30079580 + 8) * 4),uVar15);
        *(undefined4 *)(*DAT_30079898 + 8) = uVar5;
        if ((*(int *)(*DAT_30079898 + 8) == 0) || (*(int *)(*DAT_30079898 + 8) == -1)) {
          free(__ptr);
          OSAL_LogMsg(DAT_30079b60,*(undefined4 *)(*DAT_30079898 + 8),2,3,4,5,6);
          memset(acStack_318,0x100,0);
          local_3f0 = omTimerTickGet();
          snprintf(acStack_318,0x100,DAT_30079a34,local_3f0,*(undefined4 *)(*DAT_30079898 + 4));
          update_record_file(acStack_318);
          return 0xf;
        }
        iVar19 = dloadInitRamBuffer(*(undefined4 *)(*DAT_30079898 + 4),
                                    *(undefined4 *)(*DAT_30079898 + 8));
        if (iVar19 != 0) {
          OSAL_LogMsg(DAT_30079b64,1,2,3,4,5,6);
          memset(acStack_318,0x100,0);
          uVar5 = omTimerTickGet();
          snprintf(acStack_318,0x100,DAT_30079b68,uVar5);
          update_record_file(acStack_318);
          return 0x11;
        }
        if (*DAT_30079b6c == '\0') {
          *(undefined4 *)(*DAT_30079898 + 0x14) = *DAT_30079b70;
        }
        else {
          if (*DAT_30079b6c != '\x01') {
            OSAL_LogMsg(DAT_30079c0c,1,2,3,4,5,6);
            memset(acStack_318,0x100,0);
            uVar5 = omTimerTickGet();
            snprintf(acStack_318,0x100,DAT_30079c10,uVar5);
            update_record_file(acStack_318);
            return 0x11;
          }
          *(undefined4 *)(*DAT_30079898 + 0x14) = *DAT_30079c08;
        }
        local_400 = *(undefined4 *)(*DAT_30079898 + 0x14);
        local_404 = *(uint *)((int)__ptr + (uVar15 & 0xff) * 0x62 + 4);
        if ((local_404 < 100) || (*DAT_30079d4c <= local_404)) {
          free(__ptr);
          OSAL_LogMsg(DAT_30079d50,local_404,2,3,4,5,6);
          memset(acStack_318,0x100,0);
          local_3f4 = omTimerTickGet();
          snprintf(acStack_318,0x100,DAT_30079d54,local_3f4,local_404);
          update_record_file(acStack_318);
          return 0x10;
        }
        iVar19 = dloadFromFsCheckSpaceForISO();
        if (iVar19 == -1) {
          free(__ptr);
          OSAL_LogMsg(DAT_30079a30,*(undefined4 *)(*DAT_30079898 + 4),2,3,4,5,6);
          memset(acStack_318,0x100,0);
          local_3f8 = omTimerTickGet();
          snprintf(acStack_318,0x100,DAT_30079e5c,local_3f8,*(undefined4 *)(*DAT_30079898 + 4));
          update_record_file(acStack_318);
          return 0x11;
        }
        iVar19 = __urem32(*(undefined4 *)(*DAT_30079898 + 8),*DAT_30079d4c);
        if (iVar19 == 0) {
          uVar6 = __udiv32(*(undefined4 *)(*DAT_30079898 + 8),*DAT_30079d4c);
        }
        else {
          iVar19 = __udiv32(*(undefined4 *)(*DAT_30079898 + 8),*DAT_30079d4c);
          uVar6 = iVar19 + 1;
        }
        for (; uVar17 < uVar6; uVar17 = uVar17 + 1) {
          iVar19 = dloadFromFsGetUnitData
                             (*(undefined4 *)(DAT_3007968c + *(int *)(DAT_30079580 + 8) * 4),uVar15,
                              local_400,uVar17);
          if (iVar19 != 0) {
            free(__ptr);
            OSAL_LogMsg(DAT_30079e60,1,2,3,4,5,6);
            memset(acStack_318,0x100,0);
            uVar5 = omTimerTickGet();
            snprintf(acStack_318,0x100,DAT_30079f9c,uVar5);
            update_record_file(acStack_318);
            return 0x12;
          }
          if (uVar6 - 1 == uVar17) {
            iVar19 = __urem32(*(undefined4 *)(*DAT_30079898 + 8),*DAT_30079d4c);
            if (iVar19 == 0) {
              *(uint *)(*DAT_30079898 + 0x18) = *DAT_30079d4c;
            }
            else {
              uVar5 = __urem32(*(undefined4 *)(*DAT_30079898 + 8),*DAT_30079d4c);
              *(undefined4 *)(*DAT_30079898 + 0x18) = uVar5;
            }
          }
          else {
            *(uint *)(*DAT_30079898 + 0x18) = *DAT_30079d4c;
          }
          if (*(int *)(*DAT_30079898 + 4) - 0x65U < 0x99) {
            iVar19 = dynFSDloadProcess();
            if (iVar19 == -1) {
              DAT_30079b70[1] = 0;
              DAT_30079c08[5] = 0;
              resetImgBuf();
              DCBInit();
              free(__ptr);
              OSAL_LogMsg(DAT_3007a0a0,1,2,3,4,5,6);
              memset(acStack_318,0x100,0);
              uVar5 = omTimerTickGet();
              snprintf(acStack_318,0x100,DAT_3007a0a4,uVar5);
              update_record_file(acStack_318);
              return 0x14;
            }
          }
          else if (*(int *)(*DAT_30079898 + 4) == 1) {
            rm(*(char **)(DAT_3007a0a8 + *(int *)(*DAT_30079898 + 4) * 4));
            uVar16 = *(uint *)(*DAT_30079898 + 0x18);
            OSAL_LogMsg(DAT_3007a0ac,uVar16 & 0xff,2,3,4,5,6);
            if ((uVar16 & 0xff) < 0x1f5) {
              memset(auStack_218,0,500);
              memcpy(auStack_218,*(void **)(*DAT_30079898 + 0x14),*(size_t *)(*DAT_30079898 + 0x18))
              ;
            }
            else {
              OSAL_LogMsg(DAT_3007a168,uVar16 & 0xff,2,3,4,5,6);
            }
          }
          else if (*(int *)(*DAT_30079898 + 4) == 2) {
            rm(*(char **)(DAT_3007a0a8 + *(int *)(*DAT_30079898 + 4) * 4));
            uVar18 = *(uint *)(*DAT_30079898 + 0x18);
            OSAL_LogMsg(DAT_3007a16c,uVar18 & 0xff,2,3,4,5,6);
            if ((uVar18 & 0xff) < 0xc9) {
              memset(auStack_3e0,0,200);
              memcpy(auStack_3e0,*(void **)(*DAT_30079898 + 0x14),*(size_t *)(*DAT_30079898 + 0x18))
              ;
            }
            else {
              OSAL_LogMsg(DAT_3007a168,uVar16 & 0xff,2,3,4,5,6);
            }
          }
          else {
            iVar19 = imageDloadProcess();
            if (iVar19 == -1) {
              DAT_30079b70[1] = 0;
              DAT_30079c08[5] = 0;
              resetImgBuf();
              DCBInit();
              free(__ptr);
              OSAL_LogMsg(DAT_3007a2c0,1,2,3,4,5,6);
              memset(acStack_318,0x100,0);
              uVar5 = omTimerTickGet();
              snprintf(acStack_318,0x100,DAT_3007a2c4,uVar5);
              update_record_file(acStack_318);
              return 0x13;
            }
          }
        }
        if (*(int *)(*DAT_30079898 + 4) == 0x10c) {
          pFVar7 = fopen(*(char **)(DAT_3007a0a8 + 4),DAT_3007a2c8);
          if (pFVar7 == (FILE *)0x0) {
            OSAL_LogMsg(DAT_3007a3c0,1,2,3,4,5,6);
          }
          else {
            sVar8 = fwrite(auStack_218,1,uVar16 & 0xff,pFVar7);
            if (sVar8 != (uVar16 & 0xff)) {
              OSAL_LogMsg(DAT_3007a3b8,1,2,3,4,5,6);
            }
            iVar19 = fclose(pFVar7);
            if (iVar19 != 0) {
              OSAL_LogMsg(DAT_3007a3bc,1,2,3,4,5,6);
            }
          }
        }
        else if (*(int *)(*DAT_30079898 + 4) == 0x65) {
          pFVar7 = fopen(*(char **)(DAT_3007a0a8 + 8),DAT_3007a2c8);
          if (pFVar7 == (FILE *)0x0) {
            OSAL_LogMsg(DAT_3007a3c0,1,2,3,4,5,6);
          }
          else {
            sVar8 = fwrite(auStack_3e0,1,uVar18 & 0xff,pFVar7);
            if (sVar8 != (uVar18 & 0xff)) {
              OSAL_LogMsg(DAT_3007a3b8,1,2,3,4,5,6);
            }
            iVar19 = fclose(pFVar7);
            if (iVar19 != 0) {
              OSAL_LogMsg(DAT_3007a3bc,1,2,3,4,5,6);
            }
          }
        }
        if ((((*(int *)(*DAT_30079898 + 4) != 1) && (*(int *)(*DAT_30079898 + 4) != 0x10c)) &&
            (*(int *)(*DAT_30079898 + 4) != 0x65)) && (*(int *)(*DAT_30079898 + 4) != 2)) {
          BSP_DLOAD_SetCdromMarker(0);
        }
        OSAL_LogMsg(DAT_3007a3c4,*(undefined4 *)(*DAT_30079898 + 4),2,3,4,5,6);
        memset(acStack_318,0x100,0);
        local_3fc = omTimerTickGet();
        snprintf(acStack_318,0x100,DAT_3007a3c8,local_3fc,*(undefined4 *)(*DAT_30079898 + 4));
        update_record_file(acStack_318);
      }
      free(__ptr);
      uVar5 = 0;
    }
    else {
      free(__ptr);
      OSAL_LogMsg(DAT_300797a8,1,2,3,4,5,6);
      memset(acStack_318,0x100,0);
      uVar5 = omTimerTickGet();
      snprintf(acStack_318,0x100,DAT_300797ac,uVar5);
      update_record_file(acStack_318);
      uVar5 = 0xd;
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * TFUP_LogPrintf @ 0x3007A47C  (примерный размер ~292 байт)
 * Модуль: dload | Вызывают: 12 | Вызывает: 6
 * Вызывает: fclose, fopen, fseek, ftell, remove, vfprintf
 * Вызывают: TFUP_CheckFileValidify, TFUP_CheckTask, TFUP_CheckVersionMatch, TFUP_DloadTask, TFUP_GetAllFileName, TFUP_GetUnitData, TFUP_GetUnitHeadData, TFUP_IdentifyFile, TFUP_ReadDataFromTF, TFUP_ValidateCRCWithCRCList
 *           ...
 * Константы: 0x3007A47C
 * Данные: DAT_3007b430, DAT_3007b434, DAT_3007b438
 * ---------------------------------------------------------------- */
uint TFUP_LogPrintf(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FILE *__stream;
  long lVar1;
  FILE *__stream_00;
  uint uVar2;
  uint uVar3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar3 = 0;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  __stream = fopen(DAT_3007b430,DAT_3007b434);
  if (__stream != (FILE *)0x0) {
    fseek(__stream,0,2);
    lVar1 = ftell(__stream);
    if (0xffff < lVar1) {
      fclose(__stream);
      remove(DAT_3007b430);
      __stream = fopen(DAT_3007b430,DAT_3007b434);
    }
  }
  __stream_00 = fopen(DAT_3007b438,DAT_3007b434);
  if (__stream_00 != (FILE *)0x0) {
    fseek(__stream_00,0,2);
    lVar1 = ftell(__stream_00);
    if (0xffff < lVar1) {
      fclose(__stream_00);
      remove(DAT_3007b438);
      __stream_00 = fopen(DAT_3007b438,DAT_3007b434);
    }
  }
  if (__stream != (FILE *)0x0) {
    uVar3 = vfprintf(__stream,param_1,&uStack_c);
    fclose(__stream);
  }
  if (__stream_00 != (FILE *)0x0) {
    uVar2 = vfprintf(__stream_00,param_1,&uStack_c);
    uVar3 = uVar2 | uVar3;
    fclose(__stream_00);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * TFUP_ValidateCRCWithCRCList @ 0x3007A5A0  (примерный размер ~396 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 5
 * Вызывает: CalculateCRC, OSAL_LogMsg, TFUP_LogPrintf, memcmp, tickGet
 * Вызывают: dloadTFPro
 * Константы: 0xFFFFFFFF, 0x3007A5A0
 * Данные: DAT_3007b5a0, DAT_3007b5a4, DAT_3007b5a8, DAT_3007b5ac
 * ---------------------------------------------------------------- */
undefined4 TFUP_ValidateCRCWithCRCList(int param_1,uint param_2,int param_3,uint *param_4)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined1 auStack_34 [4];
  
  if ((param_2 & DAT_3007b5a0) == 0) {
    uVar3 = (param_2 >> 0xc) << 1;
  }
  else {
    uVar3 = (param_2 >> 0xc) * 2 + 2;
  }
  uVar4 = 0;
  while( true ) {
    if (uVar3 >> 1 <= uVar4) {
      *param_4 = uVar3;
      return 0;
    }
    if ((uVar3 >> 1) - 1 == uVar4) {
      if ((param_2 & DAT_3007b5a0) == 0) {
        uVar5 = 0x1000;
      }
      else {
        uVar5 = param_2 & DAT_3007b5a0;
      }
    }
    else {
      uVar5 = 0x1000;
    }
    iVar2 = CalculateCRC(param_1 + uVar4 * 0x1000,uVar5 & 0xffff,auStack_34);
    if (iVar2 != 1) break;
    iVar2 = memcmp((void *)(param_3 + uVar4 * 2),auStack_34,2);
    if (iVar2 != 0) {
      OSAL_LogMsg(DAT_3007b5ac,1,2,3,4,5,6);
      return 0xffffffff;
    }
    uVar4 = uVar4 + 1;
  }
  uVar6 = tickGet();
  lVar1 = (ulonglong)DAT_3007b5a4 * (uVar6 & 0xffffffff);
  uVar3 = tickGet((int)uVar6,(int)(uVar6 >> 0x20),(int)lVar1);
  TFUP_LogPrintf(DAT_3007b5a8,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar3 >> 0x25),
                 (int)uVar6 + (uint)((ulonglong)lVar1 >> 0x25) * -100);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * TFUP_GetUnitHeadData @ 0x3007A72C  (примерный размер ~1740 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 9
 * Вызывает: OSAL_LogMsg, TFUP_LogPrintf, fclose, fopen, fread, fseek, ftell, memcpy, tickGet
 * Вызывают: dloadTFPro
 * Константы: 0xFFFFFFFF, 0x3007A72C, 0xFFFFFFFC
 * Данные: DAT_3007b5a4, DAT_3007b698, DAT_3007b69c, DAT_3007b6a0, DAT_3007b80c, DAT_3007b810, DAT_3007b814, DAT_3007b818
 * ---------------------------------------------------------------- */
undefined4 TFUP_GetUnitHeadData(char *param_1,void *param_2,byte *param_3)

{
  longlong lVar1;
  FILE *__stream;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  size_t sVar6;
  byte bVar7;
  uint uVar8;
  ulonglong uVar9;
  
  uVar8 = 0x5c;
  bVar7 = 0;
  __stream = fopen(param_1,DAT_3007b698);
  if (__stream == (FILE *)0x0) {
    uVar2 = tickGet();
    uVar8 = (uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2 >> 0x25);
    uVar3 = tickGet((int)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2),uVar8 * 100,DAT_3007b5a4,0);
    TFUP_LogPrintf(DAT_3007b69c,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar3 >> 0x25),
                   uVar2 + uVar8 * -100,param_1);
    OSAL_LogMsg(DAT_3007b6a0,1,2,3,4,5,6);
    uVar4 = 0xffffffff;
  }
  else {
    iVar5 = fseek(__stream,0,2);
    if (iVar5 == -1) {
      fclose(__stream);
      uVar2 = tickGet();
      uVar8 = (uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2 >> 0x25);
      uVar3 = tickGet((int)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2),uVar8 * 100,DAT_3007b5a4,0);
      TFUP_LogPrintf(DAT_3007b80c,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar3 >> 0x25),
                     uVar2 + uVar8 * -100,param_1);
      OSAL_LogMsg(DAT_3007b810,1,2,3,4,5,6);
      uVar4 = 0xffffffff;
    }
    else {
      uVar2 = ftell(__stream);
      if (uVar2 == 0xffffffff) {
        fclose(__stream);
        uVar2 = tickGet();
        uVar8 = (uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2 >> 0x25);
        uVar3 = tickGet((int)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2),uVar8 * 100,DAT_3007b5a4,0
                       );
        TFUP_LogPrintf(DAT_3007b814,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar3 >> 0x25),
                       uVar2 + uVar8 * -100,param_1);
        OSAL_LogMsg(DAT_3007b818,1,2,3,4,5,6);
        uVar4 = 0xffffffff;
      }
      else {
        for (; uVar8 < uVar2; uVar8 = uVar8 + uVar3) {
          iVar5 = fseek(__stream,uVar8,0);
          if (iVar5 == -1) {
            fclose(__stream);
            uVar9 = tickGet();
            lVar1 = (ulonglong)DAT_3007b5a4 * (uVar9 & 0xffffffff);
            uVar8 = tickGet((int)uVar9,(int)(uVar9 >> 0x20),(int)lVar1);
            TFUP_LogPrintf(DAT_3007b984,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar8 >> 0x25),
                           (int)uVar9 + (uint)((ulonglong)lVar1 >> 0x25) * -100,param_1);
            OSAL_LogMsg(DAT_3007b810,1,2,3,4,5,6);
            return 0xffffffff;
          }
          if (0x13 < bVar7) {
            fclose(__stream);
            uVar2 = tickGet();
            uVar8 = (uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2 >> 0x25);
            uVar3 = tickGet((int)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2),uVar8 * 100,
                            DAT_3007b5a4,0);
            TFUP_LogPrintf(DAT_3007b988,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar3 >> 0x25),
                           uVar2 + uVar8 * -100,param_1);
            OSAL_LogMsg(DAT_3007b98c,1,2,3,4,5,6);
            return 0xffffffff;
          }
          sVar6 = fread((void *)((uint)bVar7 * 0x62 + (int)DAT_3007b990),0x62,1,__stream);
          if (sVar6 != 1) {
            fclose(__stream);
            uVar2 = tickGet();
            uVar8 = (uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2 >> 0x25);
            uVar3 = tickGet((int)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2),uVar8 * 100,
                            DAT_3007b5a4,0);
            TFUP_LogPrintf(DAT_3007bb08,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar3 >> 0x25),
                           uVar2 + uVar8 * -100,param_1,bVar7);
            OSAL_LogMsg(DAT_3007bb0c,1,2,3,4,5,6);
            return 0xffffffff;
          }
          if (*(int *)((uint)bVar7 * 0x62 + (int)DAT_3007b990) != DAT_3007bb10) {
            fclose(__stream);
            uVar2 = tickGet();
            uVar8 = (uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2 >> 0x25);
            uVar3 = tickGet((int)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2),uVar8 * 100,
                            DAT_3007b5a4,0);
            TFUP_LogPrintf(DAT_3007bc34,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar3 >> 0x25),
                           uVar2 + uVar8 * -100,param_1,bVar7);
            break;
          }
          uVar3 = *(int *)((uint)bVar7 * 0x62 + DAT_3007bb14) +
                  *(int *)((uint)bVar7 * 0x62 + DAT_3007bb18);
          if ((uVar3 & 3) != 0) {
            uVar3 = (uVar3 & 0xfffffffc) + 4;
          }
          bVar7 = bVar7 + 1;
        }
        iVar5 = fclose(__stream);
        if (iVar5 == 0) {
          *param_3 = bVar7;
          memcpy(param_2,DAT_3007b990,(uint)bVar7 * 0x62);
          uVar4 = 0;
        }
        else {
          uVar2 = tickGet();
          uVar8 = (uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2 >> 0x25);
          uVar3 = tickGet((int)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2),uVar8 * 100,DAT_3007b5a4
                          ,0);
          TFUP_LogPrintf(DAT_3007bc38,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar3 >> 0x25),
                         uVar2 + uVar8 * -100,0);
          OSAL_LogMsg(DAT_3007bc3c,1,2,3,4,5,6);
          uVar4 = 0xffffffff;
        }
      }
    }
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * TFUP_ReadDataFromTF @ 0x3007ADF8  (примерный размер ~824 байт)
 * Модуль: dload | Вызывают: 5 | Вызывает: 7
 * Вызывает: OSAL_LogMsg, TFUP_LogPrintf, fclose, fopen, fread, fseek, tickGet
 * Вызывают: TFUP_CheckVersionMatch, TFUP_GetUnitCRC, TFUP_GetUnitData, TFUP_IdentifyFile, TFUP_ValidateCRCWithLic
 * Константы: 0xFFFFFFFF, 0x3007ADF8
 * Данные: DAT_3007b5a4, DAT_3007b698, DAT_3007bd38, DAT_3007bd3c, DAT_3007bd40, DAT_3007bec4, DAT_3007bec8, DAT_3007becc
 * ---------------------------------------------------------------- */
undefined4 TFUP_ReadDataFromTF(char *param_1,void *param_2,long param_3,size_t param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  FILE *__stream;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  ulonglong uVar6;
  
  if (param_2 == (void *)0x0) {
    OSAL_LogMsg(DAT_3007bd38,1,2,3,4,5,6);
    uVar2 = 0xffffffff;
  }
  else {
    __stream = fopen(param_1,DAT_3007b698);
    if (__stream == (FILE *)0x0) {
      uVar6 = tickGet();
      lVar1 = (ulonglong)DAT_3007b5a4 * (uVar6 & 0xffffffff);
      uVar3 = tickGet((int)uVar6,(int)(uVar6 >> 0x20),(int)lVar1);
      TFUP_LogPrintf(DAT_3007bd3c,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar3 >> 0x25),
                     (int)uVar6 + (uint)((ulonglong)lVar1 >> 0x25) * -100,param_1);
      OSAL_LogMsg(DAT_3007bd40,1,2,3,4,5,6);
      uVar2 = 0xffffffff;
    }
    else {
      iVar4 = fseek(__stream,param_3,0);
      if (iVar4 == -1) {
        fclose(__stream);
        uVar6 = tickGet();
        lVar1 = (ulonglong)DAT_3007b5a4 * (uVar6 & 0xffffffff);
        uVar3 = tickGet((int)uVar6,(int)(uVar6 >> 0x20),(int)lVar1);
        TFUP_LogPrintf(DAT_3007bec4,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar3 >> 0x25),
                       (int)uVar6 + (uint)((ulonglong)lVar1 >> 0x25) * -100,param_1);
        OSAL_LogMsg(DAT_3007bec8,1,2,3,4,5,6);
        uVar2 = 0xffffffff;
      }
      else {
        sVar5 = fread(param_2,1,param_4,__stream);
        if (sVar5 == 0) {
          fclose(__stream);
          uVar6 = tickGet();
          lVar1 = (ulonglong)DAT_3007b5a4 * (uVar6 & 0xffffffff);
          uVar3 = tickGet((int)uVar6,(int)(uVar6 >> 0x20),(int)lVar1);
          TFUP_LogPrintf(DAT_3007becc,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar3 >> 0x25),
                         (int)uVar6 + (uint)((ulonglong)lVar1 >> 0x25) * -100,param_1);
          OSAL_LogMsg(DAT_3007bed0,1,2,3,4,5,6);
          uVar2 = 0xffffffff;
        }
        else {
          iVar4 = fclose(__stream);
          if (iVar4 == 0) {
            uVar2 = 0;
          }
          else {
            uVar6 = tickGet();
            lVar1 = (ulonglong)DAT_3007b5a4 * (uVar6 & 0xffffffff);
            uVar3 = tickGet((int)uVar6,(int)(uVar6 >> 0x20),(int)lVar1);
            TFUP_LogPrintf(DAT_3007bffc,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar3 >> 0x25),
                           (int)uVar6 + (uint)((ulonglong)lVar1 >> 0x25) * -100,param_1);
            OSAL_LogMsg(DAT_3007c000,1,2,3,4,5,6);
            uVar2 = 0xffffffff;
          }
        }
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * TFUP_GetUnitData @ 0x3007B130  (примерный размер ~1200 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 4
 * Вызывает: OSAL_LogMsg, TFUP_LogPrintf, TFUP_ReadDataFromTF, tickGet
 * Вызывают: dloadTFPro
 * Константы: 0xFFFFFFFF, 0x3007B130, 0xFFFFFFFC
 * Данные: DAT_3007b5a4, DAT_3007bb14, DAT_3007bb18, DAT_3007c0b4, DAT_3007c0b8, DAT_3007c1b8, DAT_3007c31c, DAT_3007c320
 * ---------------------------------------------------------------- */
undefined4 TFUP_GetUnitData(int param_1,byte param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_5c;
  
  uVar6 = 0;
  iVar3 = 0x5c;
  if ((param_1 == 0) || (param_3 == 0)) {
    uVar1 = tickGet();
    uVar4 = (uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar1 >> 0x25);
    uVar2 = tickGet((int)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar1),uVar4 * 100,DAT_3007b5a4,0);
    TFUP_LogPrintf(DAT_3007c0b4,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2 >> 0x25),
                   uVar1 + uVar4 * -100,param_2);
    OSAL_LogMsg(DAT_3007c0b8,1,2,3,4,5,6,uVar6);
    uVar6 = 0xffffffff;
  }
  else {
    for (iVar5 = 0; iVar5 < (int)(uint)param_2; iVar5 = iVar5 + 1) {
      uVar4 = *(int *)(iVar5 * 0x62 + DAT_3007bb14) + *(int *)(iVar5 * 0x62 + DAT_3007bb18);
      if ((uVar4 & 3) != 0) {
        uVar4 = (uVar4 & 0xfffffffc) + 4;
      }
      iVar3 = iVar3 + uVar4;
    }
    uVar4 = *(int *)((uint)param_2 * 0x62 + DAT_3007bb14) +
            *(int *)((uint)param_2 * 0x62 + DAT_3007bb18);
    if ((uint)(param_4 * *DAT_3007c1b8 + *(int *)(iVar5 * 0x62 + DAT_3007bb14)) < uVar4) {
      if (uVar4 < (uint)(param_4 * *DAT_3007c1b8 +
                        *DAT_3007c1b8 + *(int *)(iVar5 * 0x62 + DAT_3007bb14))) {
        local_5c = (uVar4 - *(int *)(iVar5 * 0x62 + DAT_3007bb14)) - *DAT_3007c1b8 * param_4;
      }
      else {
        local_5c = *DAT_3007c1b8;
      }
      iVar3 = TFUP_ReadDataFromTF(param_1,param_3,
                                  param_4 * *DAT_3007c1b8 +
                                  iVar3 + *(int *)(iVar5 * 0x62 + DAT_3007bb14),local_5c);
      if (iVar3 == -1) {
        uVar1 = tickGet();
        uVar4 = (uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar1 >> 0x25);
        uVar2 = tickGet((int)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar1),uVar4 * 100,DAT_3007b5a4,0
                       );
        TFUP_LogPrintf(DAT_3007c3ec,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2 >> 0x25),
                       uVar1 + uVar4 * -100,param_2,param_4);
        OSAL_LogMsg(DAT_3007c4f4,1,2,3,4,5,6);
        uVar6 = 0xffffffff;
      }
      else {
        uVar6 = 0;
      }
    }
    else {
      uVar1 = tickGet();
      uVar4 = (uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar1 >> 0x25);
      uVar2 = tickGet((int)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar1),uVar4 * 100,DAT_3007b5a4,0);
      TFUP_LogPrintf(DAT_3007c31c,(uint)((ulonglong)DAT_3007b5a4 * (ulonglong)uVar2 >> 0x25),
                     uVar1 + uVar4 * -100,param_2);
      OSAL_LogMsg(DAT_3007c320,1,2,3,4,5,6);
      uVar6 = 0xffffffff;
    }
  }
  return uVar6;
}

/* ----------------------------------------------------------------
 * TFUP_GetUnitCRC @ 0x3007B5E0  (примерный размер ~364 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 2
 * Вызывает: OSAL_LogMsg, TFUP_ReadDataFromTF
 * Вызывают: dloadTFPro
 * Константы: 0x3007B5E0, 0xFFFFFFFF
 * Данные: DAT_3007bb14, DAT_3007bb18, DAT_3007c630, DAT_3007c634
 * ---------------------------------------------------------------- */
undefined4 TFUP_GetUnitCRC(undefined4 param_1,uint param_2,undefined4 param_3,uint *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = 0x5c;
  for (iVar3 = 0; iVar3 < (int)(param_2 & 0xff); iVar3 = iVar3 + 1) {
    uVar4 = *(int *)(iVar3 * 0x62 + DAT_3007bb14) + *(int *)(iVar3 * 0x62 + DAT_3007bb18);
    if ((uVar4 & 3) != 0) {
      uVar4 = ((int)(uVar4 + ((uint)((int)uVar4 >> 0x1f) >> 0x1e)) >> 2) * 4 + 4;
    }
    iVar2 = iVar2 + uVar4;
  }
  uVar4 = (uint)*(ushort *)(iVar3 * 0x62 + DAT_3007bb14) + DAT_3007c630;
  iVar2 = TFUP_ReadDataFromTF(param_1,param_3,iVar2 + 0x62,uVar4 & 0xffff);
  if (iVar2 == -1) {
    OSAL_LogMsg(DAT_3007c634,1,2,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else {
    *param_4 = uVar4 & 0xffff;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * dloadTFPro @ 0x3007B74C  (примерный размер ~6188 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 23
 * Вызывает: DCBInit, OSAL_LogMsg, TFUP_GetUnitCRC, TFUP_GetUnitData, TFUP_GetUnitHeadData, TFUP_LogPrintf, TFUP_ValidateCRCWithCRCList, __udiv32, __urem32, dloadInitRamBuffer, dynFSDloadProcess, fclose, fopen, free
 *           ...
 * Вызывают: TFUP_DloadTask
 * Константы: 0xFFFFFFFF, 0x3007B74C
 * Данные: DAT_3007c1b8, DAT_3007c638, DAT_3007c63c, DAT_3007c640, DAT_3007c778, DAT_3007c77c, DAT_3007c780, DAT_3007c784
 * ---------------------------------------------------------------- */
undefined4 dloadTFPro(undefined4 param_1)

{
  uint uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  longlong lVar4;
  int iVar5;
  void *__ptr;
  undefined4 uVar6;
  int iVar7;
  FILE *pFVar8;
  size_t sVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  void *pvVar17;
  uint uVar18;
  int iVar19;
  ulonglong uVar20;
  uint uStack_8;
  uint local_4;
  
  iVar5 = -DAT_3007c638;
  *(undefined4 *)(&stack0x00000474 + iVar5) = param_1;
  *(undefined4 *)(&stack0xfffffff4 + iVar5) = 0;
  *(undefined4 *)((int)&local_4 + iVar5) = 0;
  *(undefined4 *)(&stack0x00000000 + iVar5) = 0;
  *(undefined4 *)((int)&uStack_8 + iVar5) = 0;
  (&stack0xffffffe4)[iVar5] = 0;
  *(undefined4 *)(&stack0xfffffff0 + iVar5) = 0;
  puVar10 = &stack0x0000025c + iVar5;
  iVar19 = 0xfa;
  puVar12 = DAT_3007c63c;
  do {
    puVar11 = puVar12 + 1;
    uVar2 = *puVar12;
    puVar12 = puVar12 + 2;
    uVar3 = *puVar11;
    iVar19 = iVar19 + -1;
    puVar11 = puVar10 + 1;
    *puVar10 = uVar2;
    puVar10 = puVar10 + 2;
    *puVar11 = uVar3;
  } while (iVar19 != 0);
  uVar15 = 0;
  puVar10 = &stack0x00000194 + iVar5;
  iVar19 = 100;
  puVar12 = DAT_3007c640;
  do {
    puVar11 = puVar12 + 1;
    uVar2 = *puVar12;
    puVar12 = puVar12 + 2;
    uVar3 = *puVar11;
    iVar19 = iVar19 + -1;
    puVar11 = puVar10 + 1;
    *puVar10 = uVar2;
    puVar10 = puVar10 + 2;
    *puVar11 = uVar3;
  } while (iVar19 != 0);
  uVar14 = 0;
  *(undefined4 *)(&stack0xffffffec + iVar5) = 0;
  *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
  *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
  *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
  OSAL_LogMsg(DAT_3007c778,1,2,3);
  __ptr = malloc(0x10000);
  if (__ptr == (void *)0x0) {
    uVar6 = tickGet();
    *(undefined4 *)(&stack0x00000060 + iVar5) = uVar6;
    uVar15 = (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000060 + iVar5) >> 0x25
                   );
    *(uint *)(&stack0x00000128 + iVar5) = *(int *)(&stack0x00000060 + iVar5) + uVar15 * -100;
    uVar6 = tickGet((int)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000060 + iVar5)),
                    uVar15 * 100,DAT_3007c77c,0);
    *(undefined4 *)(&stack0x00000190 + iVar5) = uVar6;
    *(uint *)(&stack0x0000012c + iVar5) =
         (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000190 + iVar5) >> 0x25);
    TFUP_LogPrintf(DAT_3007c780,*(undefined4 *)(&stack0x0000012c + iVar5),
                   *(undefined4 *)(&stack0x00000128 + iVar5),0);
    *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
    *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
    *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
    OSAL_LogMsg(DAT_3007c784,1,2,3);
    uVar6 = 0xffffffff;
  }
  else {
    *(undefined4 *)(&stack0xfffffff0 + iVar5) = 0;
    while (*(int *)(&stack0xfffffff0 + iVar5) < *DAT_3007c788) {
      iVar19 = TFUP_GetUnitHeadData
                         (*(undefined4 *)(DAT_3007c78c + *(int *)(&stack0xfffffff0 + iVar5) * 8),
                          *(undefined4 *)(&stack0x00000474 + iVar5),&stack0xffffffe4 + iVar5);
      if (iVar19 != 0) {
        free(__ptr);
        *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
        *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
        *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
        OSAL_LogMsg(DAT_3007c888,1,2,3);
        return 0xffffffff;
      }
      uVar6 = tickGet();
      *(undefined4 *)(&stack0x0000005c + iVar5) = uVar6;
      uVar16 = (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x0000005c + iVar5) >>
                     0x25);
      *(uint *)(&stack0x00000120 + iVar5) = *(int *)(&stack0x0000005c + iVar5) + uVar16 * -100;
      uVar6 = tickGet((int)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x0000005c + iVar5)
                           ),uVar16 * 100,DAT_3007c77c,0);
      *(undefined4 *)(&stack0x0000018c + iVar5) = uVar6;
      *(uint *)(&stack0x00000124 + iVar5) =
           (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x0000018c + iVar5) >> 0x25);
      TFUP_LogPrintf(DAT_3007c88c,*(undefined4 *)(&stack0x00000124 + iVar5),
                     *(undefined4 *)(&stack0x00000120 + iVar5),
                     *(undefined4 *)(DAT_3007c78c + *(int *)(&stack0xfffffff0 + iVar5) * 8));
      for (uVar16 = 0; (uVar16 & 0xff) < (uint)(byte)(&stack0xffffffe4)[iVar5]; uVar16 = uVar16 + 1)
      {
        uVar13 = 0;
        uVar18 = 0;
        DCBInit();
        *(uint *)(&stack0xffffffe8 + iVar5) =
             (uVar16 & 0xff) * 0x62 + *(int *)(&stack0x00000474 + iVar5) + 0x14;
        *(uint *)(*DAT_3007c990 + 4) =
             CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(*(int *)(&stack0xffffffe8 + iVar5) + 3),
                                        *(undefined1 *)(*(int *)(&stack0xffffffe8 + iVar5) + 2)),
                               *(undefined1 *)(*(int *)(&stack0xffffffe8 + iVar5) + 1)),
                      **(undefined1 **)(&stack0xffffffe8 + iVar5));
        iVar19 = imageTypeChange(*DAT_3007c990 + 4);
        if (iVar19 != 0) {
          free(__ptr);
          uVar6 = tickGet();
          *(undefined4 *)(&stack0x00000058 + iVar5) = uVar6;
          uVar15 = (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000058 + iVar5)
                         >> 0x25);
          *(uint *)(&stack0x00000118 + iVar5) = *(int *)(&stack0x00000058 + iVar5) + uVar15 * -100;
          uVar6 = tickGet((int)((ulonglong)DAT_3007c77c *
                               (ulonglong)*(uint *)(&stack0x00000058 + iVar5)),uVar15 * 100,
                          DAT_3007c77c,0);
          *(undefined4 *)(&stack0x00000188 + iVar5) = uVar6;
          *(uint *)(&stack0x0000011c + iVar5) =
               (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000188 + iVar5) >>
                     0x25);
          TFUP_LogPrintf(DAT_3007c994,*(undefined4 *)(&stack0x0000011c + iVar5),
                         *(undefined4 *)(&stack0x00000118 + iVar5),0);
          return 0xffffffff;
        }
        *(uint *)(&stack0xffffffe8 + iVar5) =
             (uVar16 & 0xff) * 0x62 + *(int *)(&stack0x00000474 + iVar5) + 0x18;
        *(uint *)(*DAT_3007c990 + 8) =
             CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(*(int *)(&stack0xffffffe8 + iVar5) + 3),
                                        *(undefined1 *)(*(int *)(&stack0xffffffe8 + iVar5) + 2)),
                               *(undefined1 *)(*(int *)(&stack0xffffffe8 + iVar5) + 1)),
                      **(undefined1 **)(&stack0xffffffe8 + iVar5));
        if (*(int *)(*DAT_3007c990 + 8) == 0) {
          free(__ptr);
          uVar6 = tickGet();
          *(undefined4 *)(&stack0x00000054 + iVar5) = uVar6;
          uVar15 = (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000054 + iVar5)
                         >> 0x25);
          *(uint *)(&stack0x00000110 + iVar5) = *(int *)(&stack0x00000054 + iVar5) + uVar15 * -100;
          uVar6 = tickGet((int)((ulonglong)DAT_3007c77c *
                               (ulonglong)*(uint *)(&stack0x00000054 + iVar5)),uVar15 * 100,
                          DAT_3007c77c,0);
          *(undefined4 *)(&stack0x00000184 + iVar5) = uVar6;
          *(uint *)(&stack0x00000114 + iVar5) =
               (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000184 + iVar5) >>
                     0x25);
          TFUP_LogPrintf(DAT_3007caf0,*(undefined4 *)(&stack0x00000114 + iVar5),
                         *(undefined4 *)(&stack0x00000110 + iVar5),uVar16 & 0xff);
          *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
          *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
          *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
          OSAL_LogMsg(DAT_3007caf4,1,2,3);
          return 0xffffffff;
        }
        iVar19 = dloadInitRamBuffer(*(undefined4 *)(*DAT_3007c990 + 4),
                                    *(undefined4 *)(*DAT_3007c990 + 8));
        if (iVar19 != 0) {
          free(__ptr);
          uVar6 = tickGet();
          *(undefined4 *)(&stack0x00000050 + iVar5) = uVar6;
          uVar15 = (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000050 + iVar5)
                         >> 0x25);
          *(uint *)(&stack0x00000108 + iVar5) = *(int *)(&stack0x00000050 + iVar5) + uVar15 * -100;
          uVar6 = tickGet((int)((ulonglong)DAT_3007c77c *
                               (ulonglong)*(uint *)(&stack0x00000050 + iVar5)),uVar15 * 100,
                          DAT_3007c77c,0);
          *(undefined4 *)(&stack0x00000180 + iVar5) = uVar6;
          *(uint *)(&stack0x0000010c + iVar5) =
               (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000180 + iVar5) >>
                     0x25);
          TFUP_LogPrintf(DAT_3007caf0,*(undefined4 *)(&stack0x0000010c + iVar5),
                         *(undefined4 *)(&stack0x00000108 + iVar5),uVar16 & 0xff);
          *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
          *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
          *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
          OSAL_LogMsg(DAT_3007cc24,1,2,3);
          return 0xffffffff;
        }
        if (*DAT_3007cc28 == '\0') {
          *(undefined4 *)(*DAT_3007c990 + 0x14) = *DAT_3007cc2c;
        }
        else {
          if (*DAT_3007cc28 != '\x01') {
            uVar6 = tickGet();
            *(undefined4 *)(&stack0x0000004c + iVar5) = uVar6;
            uVar15 = (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x0000004c + iVar5)
                           >> 0x25);
            *(uint *)(&stack0x00000100 + iVar5) = *(int *)(&stack0x0000004c + iVar5) + uVar15 * -100
            ;
            uVar6 = tickGet((int)((ulonglong)DAT_3007c77c *
                                 (ulonglong)*(uint *)(&stack0x0000004c + iVar5)),uVar15 * 100,
                            DAT_3007c77c,0);
            *(undefined4 *)(&stack0x0000017c + iVar5) = uVar6;
            *(uint *)(&stack0x00000104 + iVar5) =
                 (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x0000017c + iVar5) >>
                       0x25);
            TFUP_LogPrintf(DAT_3007cc34,*(undefined4 *)(&stack0x00000104 + iVar5),
                           *(undefined4 *)(&stack0x00000100 + iVar5),0);
            if (__ptr != (void *)0x0) {
              free(__ptr);
            }
            return 0xffffffff;
          }
          *(undefined4 *)(*DAT_3007c990 + 0x14) = *DAT_3007cc30;
        }
        *(undefined4 *)(&stack0x00000064 + iVar5) = *(undefined4 *)(*DAT_3007c990 + 0x14);
        *(uint *)(&stack0xffffffe8 + iVar5) =
             (uVar16 & 0xff) * 0x62 + *(int *)(&stack0x00000474 + iVar5) + 4;
        *(uint *)((int)&uStack_8 + iVar5) =
             CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(*(int *)(&stack0xffffffe8 + iVar5) + 3),
                                        *(undefined1 *)(*(int *)(&stack0xffffffe8 + iVar5) + 2)),
                               *(undefined1 *)(*(int *)(&stack0xffffffe8 + iVar5) + 1)),
                      **(undefined1 **)(&stack0xffffffe8 + iVar5));
        if ((*(uint *)((int)&uStack_8 + iVar5) < 100) ||
           (*DAT_3007c1b8 <= *(uint *)((int)&uStack_8 + iVar5))) {
          free(__ptr);
          uVar6 = tickGet();
          *(undefined4 *)(&stack0x00000048 + iVar5) = uVar6;
          uVar15 = (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000048 + iVar5)
                         >> 0x25);
          *(uint *)(&stack0x000000f8 + iVar5) = *(int *)(&stack0x00000048 + iVar5) + uVar15 * -100;
          uVar6 = tickGet((int)((ulonglong)DAT_3007c77c *
                               (ulonglong)*(uint *)(&stack0x00000048 + iVar5)),uVar15 * 100,
                          DAT_3007c77c,0);
          *(undefined4 *)(&stack0x00000178 + iVar5) = uVar6;
          *(uint *)(&stack0x000000fc + iVar5) =
               (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000178 + iVar5) >>
                     0x25);
          TFUP_LogPrintf(DAT_3007ce00,*(undefined4 *)(&stack0x000000fc + iVar5),
                         *(undefined4 *)(&stack0x000000f8 + iVar5),uVar16 & 0xff);
          *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
          *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
          *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
          OSAL_LogMsg(DAT_3007ce04,*(undefined4 *)((int)&uStack_8 + iVar5),2,3);
          return 0xffffffff;
        }
        iVar19 = TFUP_GetUnitCRC(*(undefined4 *)
                                  (DAT_3007c78c + *(int *)(&stack0xfffffff0 + iVar5) * 8),uVar16,
                                 __ptr,(int)&local_4 + iVar5);
        if (iVar19 != 0) {
          free(__ptr);
          uVar6 = tickGet();
          *(undefined4 *)(&stack0x00000044 + iVar5) = uVar6;
          uVar15 = (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000044 + iVar5)
                         >> 0x25);
          *(uint *)(&stack0x000000f0 + iVar5) = *(int *)(&stack0x00000044 + iVar5) + uVar15 * -100;
          uVar6 = tickGet((int)((ulonglong)DAT_3007c77c *
                               (ulonglong)*(uint *)(&stack0x00000044 + iVar5)),uVar15 * 100,
                          DAT_3007c77c,0);
          *(undefined4 *)(&stack0x00000174 + iVar5) = uVar6;
          *(uint *)(&stack0x000000f4 + iVar5) =
               (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000174 + iVar5) >>
                     0x25);
          TFUP_LogPrintf(DAT_3007ce08,*(undefined4 *)(&stack0x000000f4 + iVar5),
                         *(undefined4 *)(&stack0x000000f0 + iVar5),uVar16 & 0xff);
          *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
          *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
          *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
          OSAL_LogMsg(DAT_3007ceac,1,2,3);
          return 0xffffffff;
        }
        uVar6 = tickGet();
        *(undefined4 *)(&stack0x00000040 + iVar5) = uVar6;
        uVar1 = (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000040 + iVar5) >>
                      0x25);
        *(uint *)(&stack0x000000e8 + iVar5) = *(int *)(&stack0x00000040 + iVar5) + uVar1 * -100;
        uVar6 = tickGet((int)((ulonglong)DAT_3007c77c *
                             (ulonglong)*(uint *)(&stack0x00000040 + iVar5)),uVar1 * 100,
                        DAT_3007c77c,0);
        *(undefined4 *)(&stack0x00000170 + iVar5) = uVar6;
        *(uint *)(&stack0x000000ec + iVar5) =
             (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000170 + iVar5) >> 0x25
                   );
        TFUP_LogPrintf(DAT_3007ceb0,*(undefined4 *)(&stack0x000000ec + iVar5),
                       *(undefined4 *)(&stack0x000000e8 + iVar5),uVar16 & 0xff);
        iVar19 = __urem32(*(undefined4 *)(*DAT_3007c990 + 8),*DAT_3007c1b8);
        pvVar17 = __ptr;
        if (iVar19 == 0) {
          uVar6 = __udiv32(*(undefined4 *)(*DAT_3007c990 + 8),*DAT_3007c1b8);
          *(undefined4 *)(&stack0xfffffff4 + iVar5) = uVar6;
        }
        else {
          iVar19 = __udiv32(*(undefined4 *)(*DAT_3007c990 + 8),*DAT_3007c1b8);
          *(int *)(&stack0xfffffff4 + iVar5) = iVar19 + 1;
        }
        for (; uVar13 < *(uint *)(&stack0xfffffff4 + iVar5); uVar13 = uVar13 + 1) {
          iVar19 = TFUP_GetUnitData(*(undefined4 *)
                                     (DAT_3007c78c + *(int *)(&stack0xfffffff0 + iVar5) * 8),uVar16,
                                    *(undefined4 *)(&stack0x00000064 + iVar5),uVar13);
          if (iVar19 != 0) {
            free(__ptr);
            uVar20 = tickGet();
            lVar4 = (ulonglong)DAT_3007c77c * (uVar20 & 0xffffffff);
            *(uint *)(&stack0x000000e0 + iVar5) =
                 (int)uVar20 + (uint)((ulonglong)lVar4 >> 0x25) * -100;
            uVar6 = tickGet((int)uVar20,(int)(uVar20 >> 0x20),(int)lVar4);
            *(undefined4 *)(&stack0x0000016c + iVar5) = uVar6;
            *(uint *)(&stack0x000000e4 + iVar5) =
                 (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x0000016c + iVar5) >>
                       0x25);
            *(uint *)(&stack0xffffffd8 + iVar5) = uVar13;
            TFUP_LogPrintf(DAT_3007d06c,*(undefined4 *)(&stack0x000000e4 + iVar5),
                           *(undefined4 *)(&stack0x000000e0 + iVar5),uVar16 & 0xff);
            *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
            *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
            *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
            OSAL_LogMsg(DAT_3007d070,1,2,3);
            return 0xffffffff;
          }
          if (*(int *)(&stack0xfffffff4 + iVar5) - 1U == uVar13) {
            iVar19 = __urem32(*(undefined4 *)(*DAT_3007c990 + 8),*DAT_3007d074);
            if (iVar19 == 0) {
              *(undefined4 *)(*DAT_3007c990 + 0x18) = *DAT_3007d074;
            }
            else {
              uVar6 = __urem32(*(undefined4 *)(*DAT_3007c990 + 8),*DAT_3007d074);
              *(undefined4 *)(*DAT_3007c990 + 0x18) = uVar6;
            }
          }
          else {
            *(undefined4 *)(*DAT_3007c990 + 0x18) = *DAT_3007d074;
          }
          iVar19 = TFUP_ValidateCRCWithCRCList
                             (*(undefined4 *)(&stack0x00000064 + iVar5),
                              *(undefined4 *)(*DAT_3007c990 + 0x18),pvVar17,
                              (int)&stack0x00000000 + iVar5);
          if (iVar19 == -1) {
            free(__ptr);
            uVar6 = tickGet();
            *(undefined4 *)(&stack0x0000003c + iVar5) = uVar6;
            uVar15 = (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x0000003c + iVar5)
                           >> 0x25);
            *(uint *)(&stack0x000000d8 + iVar5) = *(int *)(&stack0x0000003c + iVar5) + uVar15 * -100
            ;
            uVar6 = tickGet((int)((ulonglong)DAT_3007c77c *
                                 (ulonglong)*(uint *)(&stack0x0000003c + iVar5)),uVar15 * 100,
                            DAT_3007c77c,0);
            *(undefined4 *)(&stack0x00000168 + iVar5) = uVar6;
            *(uint *)(&stack0x000000dc + iVar5) =
                 (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000168 + iVar5) >>
                       0x25);
            *(uint *)(&stack0xffffffd8 + iVar5) = uVar13;
            TFUP_LogPrintf(DAT_3007d1cc,*(undefined4 *)(&stack0x000000dc + iVar5),
                           *(undefined4 *)(&stack0x000000d8 + iVar5),uVar16 & 0xff);
            *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
            *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
            *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
            OSAL_LogMsg(DAT_3007d1d0,1,2,3);
            return 0xffffffff;
          }
          uVar18 = uVar18 + *(int *)(&stack0x00000000 + iVar5);
          if (*(uint *)((int)&local_4 + iVar5) < uVar18) {
            free(__ptr);
            uVar6 = tickGet();
            *(undefined4 *)(&stack0x00000038 + iVar5) = uVar6;
            uVar15 = (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000038 + iVar5)
                           >> 0x25);
            *(uint *)(&stack0x000000d0 + iVar5) = *(int *)(&stack0x00000038 + iVar5) + uVar15 * -100
            ;
            uVar6 = tickGet((int)((ulonglong)DAT_3007c77c *
                                 (ulonglong)*(uint *)(&stack0x00000038 + iVar5)),uVar15 * 100,
                            DAT_3007c77c,0);
            *(undefined4 *)(&stack0x00000164 + iVar5) = uVar6;
            *(uint *)(&stack0x000000d4 + iVar5) =
                 (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000164 + iVar5) >>
                       0x25);
            TFUP_LogPrintf(DAT_3007d274,*(undefined4 *)(&stack0x000000d4 + iVar5),
                           *(undefined4 *)(&stack0x000000d0 + iVar5),uVar16 & 0xff);
            *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
            *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
            *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
            OSAL_LogMsg(DAT_3007d278,1,2,3);
            return 0xffffffff;
          }
          iVar19 = *(int *)(&stack0x00000000 + iVar5);
          if (*(int *)(*DAT_3007c990 + 4) - 0x65U < 0x99) {
            iVar7 = dynFSDloadProcess();
            if (iVar7 != 0) {
              DAT_3007cc2c[1] = 0;
              DAT_3007cc30[5] = 0;
              resetImgBuf();
              DCBInit();
              uVar6 = tickGet();
              *(undefined4 *)(&stack0x00000034 + iVar5) = uVar6;
              uVar15 = (uint)((ulonglong)DAT_3007c77c *
                              (ulonglong)*(uint *)(&stack0x00000034 + iVar5) >> 0x25);
              *(uint *)(&stack0x000000c8 + iVar5) =
                   *(int *)(&stack0x00000034 + iVar5) + uVar15 * -100;
              uVar6 = tickGet((int)((ulonglong)DAT_3007c77c *
                                   (ulonglong)*(uint *)(&stack0x00000034 + iVar5)),uVar15 * 100,
                              DAT_3007c77c,0);
              *(undefined4 *)(&stack0x00000160 + iVar5) = uVar6;
              *(uint *)(&stack0x000000cc + iVar5) =
                   (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000160 + iVar5)
                         >> 0x25);
              *(uint *)(&stack0xffffffd8 + iVar5) = uVar13;
              TFUP_LogPrintf(DAT_3007d3c0,*(undefined4 *)(&stack0x000000cc + iVar5),
                             *(undefined4 *)(&stack0x000000c8 + iVar5),uVar16 & 0xff);
              *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
              *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
              *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
              OSAL_LogMsg(DAT_3007d3c4,1,2,3);
              if (__ptr != (void *)0x0) {
                free(__ptr);
              }
              return 0xffffffff;
            }
          }
          else if (*(int *)(*DAT_3007c990 + 4) == 1) {
            rm(*(char **)(DAT_3007d3c8 + *(int *)(*DAT_3007c990 + 4) * 4));
            uVar15 = *(uint *)(*DAT_3007c990 + 0x18);
            *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
            *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
            *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
            OSAL_LogMsg(DAT_3007d3cc,uVar15 & 0xff,2,3);
            if ((uVar15 & 0xff) < 0x1f5) {
              memset(&stack0x0000025c + iVar5,0,500);
              memcpy(&stack0x0000025c + iVar5,*(void **)(*DAT_3007c990 + 0x14),
                     *(size_t *)(*DAT_3007c990 + 0x18));
            }
            else {
              *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
              *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
              *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
              OSAL_LogMsg(DAT_3007d464,uVar15 & 0xff,2,3);
              uVar6 = tickGet();
              *(undefined4 *)(&stack0x00000030 + iVar5) = uVar6;
              uVar1 = (uint)((ulonglong)DAT_3007c77c *
                             (ulonglong)*(uint *)(&stack0x00000030 + iVar5) >> 0x25);
              *(uint *)(&stack0x000000c0 + iVar5) =
                   *(int *)(&stack0x00000030 + iVar5) + uVar1 * -100;
              uVar6 = tickGet((int)((ulonglong)DAT_3007c77c *
                                   (ulonglong)*(uint *)(&stack0x00000030 + iVar5)),uVar1 * 100,
                              DAT_3007c77c,0);
              *(undefined4 *)(&stack0x0000015c + iVar5) = uVar6;
              *(uint *)(&stack0x000000c4 + iVar5) =
                   (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x0000015c + iVar5)
                         >> 0x25);
              TFUP_LogPrintf(DAT_3007d598,*(undefined4 *)(&stack0x000000c4 + iVar5),
                             *(undefined4 *)(&stack0x000000c0 + iVar5),0);
            }
          }
          else if (*(int *)(*DAT_3007c990 + 4) == 2) {
            rm(*(char **)(DAT_3007d3c8 + *(int *)(*DAT_3007c990 + 4) * 4));
            uVar14 = *(uint *)(*DAT_3007c990 + 0x18);
            *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
            *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
            *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
            OSAL_LogMsg(DAT_3007d59c,uVar14 & 0xff,2,3);
            if ((uVar14 & 0xff) < 0xc9) {
              memset(&stack0x00000194 + iVar5,0,200);
              memcpy(&stack0x00000194 + iVar5,*(void **)(*DAT_3007c990 + 0x14),
                     *(size_t *)(*DAT_3007c990 + 0x18));
            }
            else {
              *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
              *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
              *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
              OSAL_LogMsg(DAT_3007d464,uVar15 & 0xff,2,3);
              uVar6 = tickGet();
              *(undefined4 *)(&stack0x0000002c + iVar5) = uVar6;
              uVar1 = (uint)((ulonglong)DAT_3007d5a0 *
                             (ulonglong)*(uint *)(&stack0x0000002c + iVar5) >> 0x23);
              *(uint *)(&stack0x000000b8 + iVar5) = *(int *)(&stack0x0000002c + iVar5) + uVar1 * -10
              ;
              uVar6 = tickGet((int)((ulonglong)DAT_3007d5a0 *
                                   (ulonglong)*(uint *)(&stack0x0000002c + iVar5)),uVar1 * 10,
                              DAT_3007d5a0,0);
              *(undefined4 *)(&stack0x00000158 + iVar5) = uVar6;
              *(uint *)(&stack0x000000bc + iVar5) =
                   (uint)((ulonglong)DAT_3007c77c * (ulonglong)*(uint *)(&stack0x00000158 + iVar5)
                         >> 0x25);
              TFUP_LogPrintf(DAT_3007d6e4,*(undefined4 *)(&stack0x000000bc + iVar5),
                             *(undefined4 *)(&stack0x000000b8 + iVar5),0);
            }
          }
          else {
            iVar7 = imageDloadProcess();
            if (iVar7 == -1) {
              DAT_3007cc2c[1] = 0;
              DAT_3007cc30[5] = 0;
              resetImgBuf();
              DCBInit();
              uVar6 = tickGet();
              *(undefined4 *)(&stack0x00000028 + iVar5) = uVar6;
              uVar15 = (uint)((ulonglong)DAT_3007d6e8 *
                              (ulonglong)*(uint *)(&stack0x00000028 + iVar5) >> 0x25);
              *(uint *)(&stack0x000000b0 + iVar5) =
                   *(int *)(&stack0x00000028 + iVar5) + uVar15 * -100;
              uVar6 = tickGet((int)((ulonglong)DAT_3007d6e8 *
                                   (ulonglong)*(uint *)(&stack0x00000028 + iVar5)),uVar15 * 100,
                              DAT_3007d6e8,0);
              *(undefined4 *)(&stack0x00000154 + iVar5) = uVar6;
              *(uint *)(&stack0x000000b4 + iVar5) =
                   (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x00000154 + iVar5)
                         >> 0x25);
              *(uint *)(&stack0xffffffd8 + iVar5) = uVar13;
              TFUP_LogPrintf(DAT_3007d3c0,*(undefined4 *)(&stack0x000000b4 + iVar5),
                             *(undefined4 *)(&stack0x000000b0 + iVar5),uVar16 & 0xff);
              *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
              *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
              *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
              OSAL_LogMsg(DAT_3007d6ec,1,2,3);
              if (__ptr != (void *)0x0) {
                free(__ptr);
              }
              return 0xffffffff;
            }
          }
          pvVar17 = (void *)((int)pvVar17 + iVar19);
        }
        if (*(int *)(*DAT_3007c990 + 4) == 0x10c) {
          pFVar8 = fopen(*(char **)(DAT_3007d3c8 + 4),DAT_3007d7c8);
          *(FILE **)(&stack0xffffffec + iVar5) = pFVar8;
          if (*(int *)(&stack0xffffffec + iVar5) == 0) {
            *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
            *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
            *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
            OSAL_LogMsg(DAT_3007d8a0,1,2,3);
            uVar6 = tickGet();
            *(undefined4 *)(&stack0x0000001c + iVar5) = uVar6;
            uVar13 = (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x0000001c + iVar5)
                           >> 0x25);
            *(uint *)(&stack0x00000098 + iVar5) = *(int *)(&stack0x0000001c + iVar5) + uVar13 * -100
            ;
            uVar6 = tickGet((int)((ulonglong)DAT_3007d6e8 *
                                 (ulonglong)*(uint *)(&stack0x0000001c + iVar5)),uVar13 * 100,
                            DAT_3007d6e8,0);
            *(undefined4 *)(&stack0x00000148 + iVar5) = uVar6;
            *(uint *)(&stack0x0000009c + iVar5) =
                 (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x00000148 + iVar5) >>
                       0x25);
            TFUP_LogPrintf(DAT_3007d9fc,*(undefined4 *)(&stack0x0000009c + iVar5),
                           *(undefined4 *)(&stack0x00000098 + iVar5),0);
          }
          else {
            sVar9 = fwrite(&stack0x0000025c + iVar5,1,uVar15 & 0xff,
                           *(FILE **)(&stack0xffffffec + iVar5));
            if (sVar9 != (uVar15 & 0xff)) {
              *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
              *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
              *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
              OSAL_LogMsg(DAT_3007d7cc,1,2,3);
              uVar6 = tickGet();
              *(undefined4 *)(&stack0x00000024 + iVar5) = uVar6;
              uVar13 = (uint)((ulonglong)DAT_3007d6e8 *
                              (ulonglong)*(uint *)(&stack0x00000024 + iVar5) >> 0x25);
              *(uint *)(&stack0x000000a8 + iVar5) =
                   *(int *)(&stack0x00000024 + iVar5) + uVar13 * -100;
              uVar6 = tickGet((int)((ulonglong)DAT_3007d6e8 *
                                   (ulonglong)*(uint *)(&stack0x00000024 + iVar5)),uVar13 * 100,
                              DAT_3007d6e8,0);
              *(undefined4 *)(&stack0x00000150 + iVar5) = uVar6;
              *(uint *)(&stack0x000000ac + iVar5) =
                   (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x00000150 + iVar5)
                         >> 0x25);
              TFUP_LogPrintf(DAT_3007d7d0,*(undefined4 *)(&stack0x000000ac + iVar5),
                             *(undefined4 *)(&stack0x000000a8 + iVar5),0);
            }
            iVar19 = fclose(*(FILE **)(&stack0xffffffec + iVar5));
            if (iVar19 == 0) {
              *(undefined4 *)(&stack0xffffffec + iVar5) = 0;
            }
            else {
              *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
              *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
              *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
              OSAL_LogMsg(DAT_3007d898,1,2,3);
              uVar6 = tickGet();
              *(undefined4 *)(&stack0x00000020 + iVar5) = uVar6;
              uVar13 = (uint)((ulonglong)DAT_3007d6e8 *
                              (ulonglong)*(uint *)(&stack0x00000020 + iVar5) >> 0x25);
              *(uint *)(&stack0x000000a0 + iVar5) =
                   *(int *)(&stack0x00000020 + iVar5) + uVar13 * -100;
              uVar6 = tickGet((int)((ulonglong)DAT_3007d6e8 *
                                   (ulonglong)*(uint *)(&stack0x00000020 + iVar5)),uVar13 * 100,
                              DAT_3007d6e8,0);
              *(undefined4 *)(&stack0x0000014c + iVar5) = uVar6;
              *(uint *)(&stack0x000000a4 + iVar5) =
                   (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x0000014c + iVar5)
                         >> 0x25);
              TFUP_LogPrintf(DAT_3007d89c,*(undefined4 *)(&stack0x000000a4 + iVar5),
                             *(undefined4 *)(&stack0x000000a0 + iVar5),0);
            }
          }
        }
        else if (*(int *)(*DAT_3007da00 + 4) == 0x65) {
          pFVar8 = fopen(*(char **)(DAT_3007d3c8 + 8),DAT_3007d7c8);
          *(FILE **)(&stack0xffffffec + iVar5) = pFVar8;
          if (*(int *)(&stack0xffffffec + iVar5) == 0) {
            *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
            *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
            *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
            OSAL_LogMsg(DAT_3007d8a0,1,2,3);
            uVar6 = tickGet();
            *(undefined4 *)(&stack0x00000010 + iVar5) = uVar6;
            uVar13 = (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x00000010 + iVar5)
                           >> 0x25);
            *(uint *)(&stack0x00000080 + iVar5) = *(int *)(&stack0x00000010 + iVar5) + uVar13 * -100
            ;
            uVar6 = tickGet((int)((ulonglong)DAT_3007d6e8 *
                                 (ulonglong)*(uint *)(&stack0x00000010 + iVar5)),uVar13 * 100,
                            DAT_3007d6e8,0);
            *(undefined4 *)(&stack0x0000013c + iVar5) = uVar6;
            *(uint *)(&stack0x00000084 + iVar5) =
                 (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x0000013c + iVar5) >>
                       0x25);
            TFUP_LogPrintf(DAT_3007dbb4,*(undefined4 *)(&stack0x00000084 + iVar5),
                           *(undefined4 *)(&stack0x00000080 + iVar5),0);
          }
          else {
            sVar9 = fwrite(&stack0x00000194 + iVar5,1,uVar14 & 0xff,
                           *(FILE **)(&stack0xffffffec + iVar5));
            if (sVar9 != (uVar14 & 0xff)) {
              *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
              *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
              *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
              OSAL_LogMsg(DAT_3007d7cc,1,2,3);
              uVar6 = tickGet();
              *(undefined4 *)(&stack0x00000018 + iVar5) = uVar6;
              uVar13 = (uint)((ulonglong)DAT_3007d6e8 *
                              (ulonglong)*(uint *)(&stack0x00000018 + iVar5) >> 0x25);
              *(uint *)(&stack0x00000090 + iVar5) =
                   *(int *)(&stack0x00000018 + iVar5) + uVar13 * -100;
              uVar6 = tickGet((int)((ulonglong)DAT_3007d6e8 *
                                   (ulonglong)*(uint *)(&stack0x00000018 + iVar5)),uVar13 * 100,
                              DAT_3007d6e8,0);
              *(undefined4 *)(&stack0x00000144 + iVar5) = uVar6;
              *(uint *)(&stack0x00000094 + iVar5) =
                   (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x00000144 + iVar5)
                         >> 0x25);
              TFUP_LogPrintf(DAT_3007da04,*(undefined4 *)(&stack0x00000094 + iVar5),
                             *(undefined4 *)(&stack0x00000090 + iVar5),0);
            }
            iVar19 = fclose(*(FILE **)(&stack0xffffffec + iVar5));
            if (iVar19 == 0) {
              *(undefined4 *)(&stack0xffffffec + iVar5) = 0;
            }
            else {
              *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
              *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
              *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
              OSAL_LogMsg(DAT_3007d898,1,2,3);
              uVar6 = tickGet();
              *(undefined4 *)(&stack0x00000014 + iVar5) = uVar6;
              uVar13 = (uint)((ulonglong)DAT_3007d6e8 *
                              (ulonglong)*(uint *)(&stack0x00000014 + iVar5) >> 0x25);
              *(uint *)(&stack0x00000088 + iVar5) =
                   *(int *)(&stack0x00000014 + iVar5) + uVar13 * -100;
              uVar6 = tickGet((int)((ulonglong)DAT_3007d6e8 *
                                   (ulonglong)*(uint *)(&stack0x00000014 + iVar5)),uVar13 * 100,
                              DAT_3007d6e8,0);
              *(undefined4 *)(&stack0x00000140 + iVar5) = uVar6;
              *(uint *)(&stack0x0000008c + iVar5) =
                   (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x00000140 + iVar5)
                         >> 0x25);
              TFUP_LogPrintf(DAT_3007dbb0,*(undefined4 *)(&stack0x0000008c + iVar5),
                             *(undefined4 *)(&stack0x00000088 + iVar5),0);
            }
          }
        }
        if (uVar18 != *(uint *)((int)&local_4 + iVar5)) {
          free(__ptr);
          uVar6 = tickGet();
          *(undefined4 *)(&stack0x0000000c + iVar5) = uVar6;
          uVar15 = (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x0000000c + iVar5)
                         >> 0x25);
          *(uint *)(&stack0x00000078 + iVar5) = *(int *)(&stack0x0000000c + iVar5) + uVar15 * -100;
          uVar6 = tickGet((int)((ulonglong)DAT_3007d6e8 *
                               (ulonglong)*(uint *)(&stack0x0000000c + iVar5)),uVar15 * 100,
                          DAT_3007d6e8,0);
          *(undefined4 *)(&stack0x00000138 + iVar5) = uVar6;
          *(uint *)(&stack0x0000007c + iVar5) =
               (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x00000138 + iVar5) >>
                     0x25);
          TFUP_LogPrintf(DAT_3007dcdc,*(undefined4 *)(&stack0x0000007c + iVar5),
                         *(undefined4 *)(&stack0x00000078 + iVar5),uVar16 & 0xff);
          *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
          *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
          *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
          OSAL_LogMsg(DAT_3007dce0,1,2,3);
          return 0xffffffff;
        }
        *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
        *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
        *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
        OSAL_LogMsg(DAT_3007dce4,uVar16 & 0xff,2,3);
        uVar6 = tickGet();
        *(undefined4 *)(&stack0x00000008 + iVar5) = uVar6;
        uVar13 = (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x00000008 + iVar5) >>
                       0x25);
        *(uint *)(&stack0x00000070 + iVar5) = *(int *)(&stack0x00000008 + iVar5) + uVar13 * -100;
        uVar6 = tickGet((int)((ulonglong)DAT_3007d6e8 *
                             (ulonglong)*(uint *)(&stack0x00000008 + iVar5)),uVar13 * 100,
                        DAT_3007d6e8,0);
        *(undefined4 *)(&stack0x00000134 + iVar5) = uVar6;
        *(uint *)(&stack0x00000074 + iVar5) =
             (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x00000134 + iVar5) >> 0x25
                   );
        TFUP_LogPrintf(DAT_3007dce8,*(undefined4 *)(&stack0x00000074 + iVar5),
                       *(undefined4 *)(&stack0x00000070 + iVar5),uVar16 & 0xff);
      }
      *(int *)(&stack0xfffffff0 + iVar5) = *(int *)(&stack0xfffffff0 + iVar5) + 1;
    }
    free(__ptr);
    *(undefined4 *)(&stack0xffffffd8 + iVar5) = 4;
    *(undefined4 *)(&stack0xffffffdc + iVar5) = 5;
    *(undefined4 *)(&stack0xffffffe0 + iVar5) = 6;
    OSAL_LogMsg(DAT_3007ddbc,1,2,3);
    uVar6 = tickGet();
    *(undefined4 *)(&stack0x00000004 + iVar5) = uVar6;
    uVar15 = (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x00000004 + iVar5) >> 0x25
                   );
    *(uint *)(&stack0x00000068 + iVar5) = *(int *)(&stack0x00000004 + iVar5) + uVar15 * -100;
    uVar6 = tickGet((int)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x00000004 + iVar5)),
                    uVar15 * 100,DAT_3007d6e8,0);
    *(undefined4 *)(&stack0x00000130 + iVar5) = uVar6;
    *(uint *)(&stack0x0000006c + iVar5) =
         (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)*(uint *)(&stack0x00000130 + iVar5) >> 0x25);
    TFUP_LogPrintf(DAT_3007ddc0,*(undefined4 *)(&stack0x0000006c + iVar5),
                   *(undefined4 *)(&stack0x00000068 + iVar5),0);
    uVar6 = 0;
  }
  return uVar6;
}

/* ----------------------------------------------------------------
 * dloadTFCallback @ 0x3007CF78  (примерный размер ~132 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 3
 * Вызывает: OSAL_LogMsg, OSAL_SemGive, ledFlush
 * Константы: 0x3007CF78
 * Данные: DAT_3007da00, DAT_3007de74, DAT_3007de78
 * ---------------------------------------------------------------- */
void dloadTFCallback(void)

{
  if ((*(int *)*DAT_3007da00 == 0) || (*(int *)*DAT_3007da00 == 1)) {
    OSAL_LogMsg(DAT_3007de74,*(undefined4 *)*DAT_3007da00,2,3,4,5,6);
  }
  else {
    ledFlush(1);
    OSAL_SemGive(*DAT_3007de78);
  }
  return;
}

/* ----------------------------------------------------------------
 * TFUP_CheckInit @ 0x3007CFFC  (примерный размер ~484 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, OSAL_SemBCreate, OSAL_SemMCreate, sdmmcAddHook, taskSpawn
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0xFFFFFFFF, 0x3007CFFC
 * Данные: DAT_3007de7c, DAT_3007de80, DAT_3007df20, DAT_3007df24, DAT_3007df28, DAT_3007df2c, DAT_3007dfe8, DAT_3007dfec
 * ---------------------------------------------------------------- */
undefined4 TFUP_CheckInit(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*DAT_3007de7c == 0) {
    iVar1 = OSAL_SemBCreate(0,0);
    *DAT_3007de7c = iVar1;
    if (*DAT_3007de7c == 0) {
      OSAL_LogMsg(DAT_3007de80,1,2,3,4,5,6);
      return 0xffffffff;
    }
  }
  if (*DAT_3007df20 == 0) {
    iVar1 = OSAL_SemMCreate(9);
    *DAT_3007df20 = iVar1;
    if (*DAT_3007df20 == 0) {
      OSAL_LogMsg(DAT_3007df24,1,2,3,4,5,6);
      return 0xffffffff;
    }
  }
  iVar1 = sdmmcAddHook(4,DAT_3007df28);
  if (iVar1 == 0) {
    iVar1 = taskSpawn(DAT_3007dfec,0x9e,0,0x2000,DAT_3007dfe8,0,0,0,0,0,0,0,0,0,0);
    if (iVar1 == -1) {
      OSAL_LogMsg(DAT_3007dff0,1,2,3,4,5,6);
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    OSAL_LogMsg(DAT_3007df2c,1,2,3,4,5,6);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * TFUP_dosFsDevCreate @ 0x3007D1E0  (примерный размер ~520 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 8
 * Вызывает: OSAL_LogMsg, OSAL_SemGive, OSAL_SemTake, dosFsShow, sdmmcDevCreate, taskDelay, tickGet, xbdBlkDevCreate
 * Вызывают: TFUP_CheckTask
 * Константы: 0xFFFFFFFF, 0x3007D1E0
 * Данные: DAT_3007df20, DAT_3007e0f8, DAT_3007e0fc, DAT_3007e100, DAT_3007e104, DAT_3007e108, DAT_3007e204, DAT_3007e208
 * ---------------------------------------------------------------- */
undefined4 TFUP_dosFsDevCreate(void)

{
  int iVar1;
  int iVar2;
  
  OSAL_SemTake(*DAT_3007df20,0xffffffff);
  if (*DAT_3007e0f8 == 0) {
    iVar1 = sdmmcDevCreate();
    *DAT_3007e0f8 = iVar1;
    if (*DAT_3007e0f8 == 0) {
      OSAL_LogMsg(DAT_3007e0fc,1,2,3,4,5,6);
      taskDelay(10);
      OSAL_SemGive(*DAT_3007df20);
      return 0xffffffff;
    }
  }
  if (*DAT_3007e100 == 0) {
    iVar1 = xbdBlkDevCreate(*DAT_3007e0f8,DAT_3007e104);
    *DAT_3007e100 = iVar1;
    if (*DAT_3007e100 == 0) {
      OSAL_LogMsg(DAT_3007e108,1,2,3,4,5,6);
      taskDelay(10);
      OSAL_SemGive(*DAT_3007df20);
      return 0xffffffff;
    }
  }
  taskDelay(100);
  iVar1 = tickGet();
  while ((iVar2 = dosFsShow(DAT_3007e204), iVar2 != 0 &&
         (iVar2 = dosFsShow(DAT_3007e208), iVar2 != 0))) {
    taskDelay(0x32);
    iVar2 = tickGet();
    if (DAT_3007e20c <= (uint)(iVar2 - iVar1)) {
      OSAL_LogMsg(DAT_3007e210,1,2,3,4,5,6);
      OSAL_LogMsg(DAT_3007e214,1,2,3,4,5,6);
      taskDelay(10);
      OSAL_SemGive(*DAT_3007df20);
      return 0xffffffff;
    }
  }
  OSAL_SemGive(*DAT_3007df20);
  return 0;
}

/* ----------------------------------------------------------------
 * TFUP_GetFileType @ 0x3007D3E8  (примерный размер ~252 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 4
 * Вызывает: sdmmcGetDosFsDevName, strcat, strcmp, strlen
 * Вызывают: TFUP_IdentifyFile
 * Константы: 0x3007D3E8
 * Данные: DAT_3007e218, DAT_3007e334, DAT_3007e338, DAT_3007e33c, DAT_3007e340
 * ---------------------------------------------------------------- */
undefined4 TFUP_GetFileType(char *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  size_t sVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  char acStack_44 [48];
  
  pcVar5 = acStack_44;
  iVar8 = 0x18;
  puVar7 = DAT_3007e218;
  do {
    puVar6 = puVar7 + 1;
    uVar1 = *puVar7;
    puVar7 = puVar7 + 2;
    uVar2 = *puVar6;
    iVar8 = iVar8 + -1;
    puVar6 = pcVar5 + 1;
    *pcVar5 = uVar1;
    pcVar5 = pcVar5 + 2;
    *puVar6 = uVar2;
  } while (iVar8 != 0);
  iVar8 = sdmmcGetDosFsDevName(uVar1,uVar2,acStack_44);
  strcat(acStack_44,(char *)(iVar8 + 4));
  strcat(acStack_44,DAT_3007e334);
  sVar3 = strlen(param_1);
  if ((int)sVar3 < 5) {
    uVar4 = 0x67;
  }
  else {
    pcVar5 = param_1 + (sVar3 - 4);
    iVar8 = strcmp(pcVar5,DAT_3007e338);
    if ((iVar8 == 0) || (iVar8 = strcmp(pcVar5,DAT_3007e33c), iVar8 == 0)) {
      uVar4 = 100;
    }
    else {
      iVar8 = strcmp(pcVar5,DAT_3007e340);
      if (iVar8 == 0) {
        uVar4 = 0x65;
      }
      else {
        iVar8 = strcmp(param_1,acStack_44);
        if (iVar8 == 0) {
          uVar4 = 0x66;
        }
        else {
          uVar4 = 0x67;
        }
      }
    }
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * TFUP_IdentifyFile @ 0x3007D4E4  (примерный размер ~1812 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 9
 * Вызывает: BSP_DLOAD_SetCdromMarker, OSAL_LogMsg, TFUP_GetFileType, TFUP_LogPrintf, TFUP_ReadDataFromTF, imageTypeChange, strlen, strncmp, tickGet
 * Вызывают: TFUP_CheckFileValidify
 * Константы: 0xFFFFFFFF, 0x3007D4E4
 * Данные: DAT_3007d6e8, DAT_3007e344, DAT_3007e348, DAT_3007e4b8, DAT_3007e5b8, DAT_3007e5bc, DAT_3007e5c0, DAT_3007e5c4
 * ---------------------------------------------------------------- */
undefined4 TFUP_IdentifyFile(int param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulonglong uVar10;
  int local_b8;
  int local_b4;
  uint local_b0;
  int local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  int local_90;
  uint local_8c;
  int local_88;
  uint local_84;
  int local_80;
  uint local_7c;
  int local_78;
  uint local_74;
  int local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  int local_54;
  int local_50 [4];
  int local_40;
  int local_3c [4];
  int local_2c;
  
  local_b8 = 0;
  iVar8 = 0;
  local_ac = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_50[0] = *DAT_3007e344;
  local_50[1] = DAT_3007e344[1];
  local_50[2] = DAT_3007e344[2];
  local_50[3] = DAT_3007e344[3];
  local_40 = DAT_3007e344[4];
  local_3c[0] = *DAT_3007e348;
  local_3c[1] = DAT_3007e348[1];
  local_3c[2] = DAT_3007e348[2];
  local_3c[3] = DAT_3007e348[3];
  local_2c = DAT_3007e348[4];
  for (iVar7 = 0; iVar7 < param_1; iVar7 = iVar7 + 1) {
    local_54 = TFUP_GetFileType(DAT_3007e4b8 + iVar7 * 0x100);
    if (local_54 == 100) {
      local_50[local_b8] = DAT_3007e4b8 + iVar7 * 0x100;
      local_b8 = local_b8 + 1;
    }
    else if (local_54 == 0x65) {
      local_3c[iVar8] = DAT_3007e4b8 + iVar7 * 0x100;
      iVar8 = iVar8 + 1;
    }
    else if (local_54 == 0x66) {
      local_ac = local_ac + 1;
    }
  }
  if ((param_1 == 5) && (local_ac == 0)) {
    local_94 = tickGet();
    uVar6 = (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)local_94 >> 0x25);
    local_70 = local_94 + uVar6 * -100;
    local_58 = tickGet((int)((ulonglong)DAT_3007d6e8 * (ulonglong)local_94),uVar6 * 100,DAT_3007d6e8
                       ,0);
    local_6c = (uint)((ulonglong)DAT_3007d6e8 * (ulonglong)local_58 >> 0x25);
    TFUP_LogPrintf(DAT_3007e5b8,5,local_6c,local_70);
    OSAL_LogMsg(DAT_3007e5bc,5,2,3,4,5,6);
    uVar2 = 0xffffffff;
  }
  else if ((iVar8 < local_b8) || ((2 < local_b8 || (local_b8 == 0)))) {
    local_98 = tickGet();
    uVar6 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_98 >> 0x25);
    local_78 = local_98 + uVar6 * -100;
    local_5c = tickGet((int)((ulonglong)DAT_3007e5c0 * (ulonglong)local_98),uVar6 * 100,DAT_3007e5c0
                       ,0);
    local_74 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_5c >> 0x25);
    TFUP_LogPrintf(DAT_3007e5c4,local_74,local_78,0);
    OSAL_LogMsg(DAT_3007e5c8,1,2,3,4,5,6);
    uVar2 = 0xffffffff;
  }
  else {
    for (iVar7 = 0; iVar7 < local_b8; iVar7 = iVar7 + 1) {
      for (iVar9 = 0; iVar9 < iVar8; iVar9 = iVar9 + 1) {
        sVar3 = strlen((char *)local_50[iVar7]);
        sVar4 = strlen((char *)local_3c[iVar9]);
        if (sVar4 == sVar3) {
          sVar3 = strlen((char *)local_50[iVar7]);
          iVar5 = strncmp((char *)local_50[iVar7],(char *)local_3c[iVar9],sVar3 - 4);
          if (iVar5 == 0) {
            *(int *)(DAT_3007e74c + iVar7 * 8) = local_50[iVar7];
            *(int *)(DAT_3007e750 + iVar7 * 8) = local_3c[iVar9];
            break;
          }
        }
        if ((iVar8 + -1 == iVar9) && (*(int *)(DAT_3007e74c + iVar7 * 8) == 0)) {
          uVar10 = tickGet();
          lVar1 = (ulonglong)DAT_3007e5c0 * (uVar10 & 0xffffffff);
          uVar6 = tickGet((int)uVar10,(int)(uVar10 >> 0x20),(int)lVar1);
          TFUP_LogPrintf(DAT_3007e754,(uint)((ulonglong)DAT_3007e5c0 * (ulonglong)uVar6 >> 0x25),
                         (int)uVar10 + (uint)((ulonglong)lVar1 >> 0x25) * -100);
          OSAL_LogMsg(DAT_3007e758,1,2,3,4,5,6);
          return 0xffffffff;
        }
      }
    }
    for (iVar7 = 0; iVar7 < local_b8; iVar7 = iVar7 + 1) {
      iVar8 = TFUP_ReadDataFromTF(*(undefined4 *)(DAT_3007e74c + iVar7 * 8),&local_b4,0x70,4);
      if (iVar8 == -1) {
        local_9c = tickGet();
        uVar6 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_9c >> 0x25);
        local_80 = local_9c + uVar6 * -100;
        local_60 = tickGet((int)((ulonglong)DAT_3007e5c0 * (ulonglong)local_9c),uVar6 * 100,
                           DAT_3007e5c0,0);
        local_7c = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_60 >> 0x25);
        TFUP_LogPrintf(DAT_3007e85c,local_7c,local_80,0);
        return 0xffffffff;
      }
      iVar8 = imageTypeChange(&local_b4);
      if (iVar8 == -1) {
        local_a0 = tickGet();
        uVar6 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_a0 >> 0x25);
        local_88 = local_a0 + uVar6 * -100;
        local_64 = tickGet((int)((ulonglong)DAT_3007e5c0 * (ulonglong)local_a0),uVar6 * 100,
                           DAT_3007e5c0,0);
        local_84 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_64 >> 0x25);
        TFUP_LogPrintf(DAT_3007e930,local_84,local_88,0);
        return 0xffffffff;
      }
      if ((((local_b4 == 1) || (local_b4 == 0x10c)) || (local_b4 == 0x65)) || (local_b4 == 2)) {
        local_a8 = local_a8 + 1;
      }
      else {
        *(undefined4 *)(DAT_3007e934 + iVar7 * 8) = 0x9b;
        local_b0 = local_b0 + 1;
      }
    }
    if ((local_a8 < 2) && (local_b0 < 2)) {
      if (local_b0 != 0) {
        *DAT_3007ea20 = 1;
        BSP_DLOAD_SetCdromMarker(0);
      }
      *DAT_3007ea24 = local_b8;
      uVar2 = 0;
    }
    else {
      local_a4 = tickGet();
      uVar6 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_a4 >> 0x25);
      local_90 = local_a4 + uVar6 * -100;
      local_68 = tickGet((int)((ulonglong)DAT_3007e5c0 * (ulonglong)local_a4),uVar6 * 100,
                         DAT_3007e5c0,0);
      local_8c = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_68 >> 0x25);
      TFUP_LogPrintf(DAT_3007ea18,local_8c,local_90,0);
      OSAL_LogMsg(DAT_3007ea1c,1,2,3,4,5,6);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * TFUP_CheckVersionMatch @ 0x3007DBF8  (примерный размер ~1652 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 8
 * Вызывает: BSP_DLOAD_GetSoftwareVer, OSAL_LogMsg, TFUP_LogPrintf, TFUP_ReadDataFromTF, getDloadID, strcmp, strlen, tickGet
 * Вызывают: TFUP_CheckFileValidify
 * Константы: 0xFFFFFFFF, 0x3007DBF8
 * Данные: DAT_3007e5c0, DAT_3007ea28, DAT_3007ea2c, DAT_3007eacc, DAT_3007ead0, DAT_3007ebd4, DAT_3007ebd8, DAT_3007eca8
 * ---------------------------------------------------------------- */
undefined4 TFUP_CheckVersionMatch(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  size_t sVar8;
  size_t sVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  size_t sVar13;
  int iVar14;
  int iVar15;
  ulonglong uVar16;
  char acStack_a8 [32];
  char local_88 [32];
  char local_68 [32];
  char local_48 [32];
  
  pcVar10 = local_48;
  iVar15 = 0x10;
  pcVar12 = DAT_3007ea28;
  do {
    pcVar11 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 2;
    cVar2 = *pcVar11;
    iVar15 = iVar15 + -1;
    pcVar11 = pcVar10 + 1;
    *pcVar10 = cVar1;
    pcVar10 = pcVar10 + 2;
    *pcVar11 = cVar2;
  } while (iVar15 != 0);
  pcVar10 = local_68;
  iVar15 = 0xf;
  pcVar12 = DAT_3007ea2c;
  do {
    pcVar11 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 2;
    cVar2 = *pcVar11;
    iVar15 = iVar15 + -1;
    pcVar11 = pcVar10 + 1;
    *pcVar10 = cVar1;
    pcVar10 = pcVar10 + 2;
    *pcVar11 = cVar2;
  } while (iVar15 != 0);
  *pcVar10 = *pcVar12;
  pcVar10 = local_88;
  iVar15 = 0xf;
  pcVar12 = DAT_3007eacc;
  do {
    pcVar11 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 2;
    cVar2 = *pcVar11;
    iVar15 = iVar15 + -1;
    pcVar11 = pcVar10 + 1;
    *pcVar10 = cVar1;
    pcVar10 = pcVar10 + 2;
    *pcVar11 = cVar2;
  } while (iVar15 != 0);
  *pcVar10 = *pcVar12;
  pcVar10 = acStack_a8;
  iVar15 = 0xf;
  pcVar12 = DAT_3007ead0;
  do {
    pcVar11 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 2;
    cVar2 = *pcVar11;
    iVar15 = iVar15 + -1;
    pcVar11 = pcVar10 + 1;
    *pcVar10 = cVar1;
    pcVar10 = pcVar10 + 2;
    *pcVar11 = cVar2;
  } while (iVar15 != 0);
  *pcVar10 = *pcVar12;
  iVar15 = TFUP_ReadDataFromTF(param_1,local_48,0,0x20);
  if (iVar15 == -1) {
    uVar16 = tickGet();
    lVar3 = (ulonglong)DAT_3007e5c0 * (uVar16 & 0xffffffff);
    uVar4 = tickGet((int)uVar16,(int)(uVar16 >> 0x20),(int)lVar3);
    TFUP_LogPrintf(DAT_3007ebd4,(uint)((ulonglong)DAT_3007e5c0 * (ulonglong)uVar4 >> 0x25),
                   (int)uVar16 + (uint)((ulonglong)lVar3 >> 0x25) * -100,param_1);
    OSAL_LogMsg(DAT_3007ebd8,1,2,3,4,5,6);
    uVar5 = 0xffffffff;
  }
  else {
    iVar15 = BSP_DLOAD_GetSoftwareVer(acStack_a8,0x1e);
    if (iVar15 == 0) {
      for (iVar15 = 0; (iVar15 < 0x20 && (local_48[iVar15] != ':')); iVar15 = iVar15 + 1) {
      }
      iVar14 = 0;
      while ((iVar15 + 1 < 0x20 && (local_48[iVar15 + 1] != ':'))) {
        local_68[iVar14] = local_48[iVar15 + 1];
        iVar14 = iVar14 + 1;
        iVar15 = iVar15 + 1;
      }
      iVar14 = 0;
      for (iVar15 = iVar15 + 2; (iVar15 < 0x20 && (local_48[iVar15] != '\0')); iVar15 = iVar15 + 1)
      {
        local_88[iVar14] = local_48[iVar15];
        iVar14 = iVar14 + 1;
      }
      pcVar12 = (char *)getDloadID();
      iVar15 = strcmp(local_68,pcVar12);
      if (iVar15 == 0) {
        sVar8 = strlen(acStack_a8);
        sVar9 = strlen(local_88);
        do {
          sVar13 = sVar8;
          if (acStack_a8[sVar13] == '.') break;
          sVar8 = sVar13 - 1;
        } while (sVar13 - 1 != 0);
        do {
          sVar8 = sVar9;
          if (local_88[sVar8] == '.') break;
          sVar9 = sVar8 - 1;
        } while (sVar8 - 1 != 0);
        sVar9 = strlen(acStack_a8);
        if ((sVar9 < sVar13 + 1) || (sVar9 = strlen(local_88), sVar9 < sVar8 + 1)) {
          uVar6 = tickGet();
          uVar4 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)uVar6 >> 0x25);
          uVar7 = tickGet((int)((ulonglong)DAT_3007e5c0 * (ulonglong)uVar6),uVar4 * 100,DAT_3007e5c0
                          ,0);
          TFUP_LogPrintf(DAT_3007efc0,(uint)((ulonglong)DAT_3007e5c0 * (ulonglong)uVar7 >> 0x25),
                         uVar6 + uVar4 * -100,0);
          OSAL_LogMsg(DAT_3007efc4,1,2,3,4,5,6);
          uVar5 = 0xffffffff;
        }
        else {
          iVar15 = strcmp(acStack_a8 + sVar13 + 1,local_88 + sVar8 + 1);
          if ((iVar15 == 0) || (iVar15 = strcmp(acStack_a8 + sVar13 + 1,DAT_3007efc8), iVar15 == 0))
          {
            OSAL_LogMsg(DAT_3007f0c8,1,2,3,4,5,6);
            uVar5 = 0;
          }
          else {
            uVar6 = tickGet();
            uVar4 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)uVar6 >> 0x25);
            uVar7 = tickGet((int)((ulonglong)DAT_3007e5c0 * (ulonglong)uVar6),uVar4 * 100,
                            DAT_3007e5c0,0);
            TFUP_LogPrintf(DAT_3007efcc,(uint)((ulonglong)DAT_3007e5c0 * (ulonglong)uVar7 >> 0x25),
                           uVar6 + uVar4 * -100,0);
            OSAL_LogMsg(DAT_3007f0c4,1,2,3,4,5,6);
            uVar5 = 0xffffffff;
          }
        }
      }
      else {
        uVar6 = tickGet();
        uVar4 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)uVar6 >> 0x25);
        uVar7 = tickGet((int)((ulonglong)DAT_3007e5c0 * (ulonglong)uVar6),uVar4 * 100,DAT_3007e5c0,0
                       );
        TFUP_LogPrintf(DAT_3007ee30,(uint)((ulonglong)DAT_3007e5c0 * (ulonglong)uVar7 >> 0x25),
                       uVar6 + uVar4 * -100,0);
        OSAL_LogMsg(DAT_3007ee34,1,2,3,4,5,6);
        uVar5 = 0xffffffff;
      }
    }
    else {
      uVar16 = tickGet();
      lVar3 = (ulonglong)DAT_3007e5c0 * (uVar16 & 0xffffffff);
      uVar4 = tickGet((int)uVar16,(int)(uVar16 >> 0x20),(int)lVar3);
      TFUP_LogPrintf(DAT_3007eca8,(uint)((ulonglong)DAT_3007e5c0 * (ulonglong)uVar4 >> 0x25),
                     (int)uVar16 + (uint)((ulonglong)lVar3 >> 0x25) * -100,0);
      OSAL_LogMsg(DAT_3007ecac,DAT_3007ecb0,2,3,4,5,6);
      uVar5 = 0xffffffff;
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * TFUP_ValidateCRCWithLic @ 0x3007E26C  (примерный размер ~2060 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 13
 * Вызывает: CalculateCRC, OSAL_LogMsg, TFUP_LogPrintf, TFUP_ReadDataFromTF, fclose, fopen, free, fseek, ftell, malloc, memcmp, rewind, tickGet
 * Вызывают: TFUP_CheckFileValidify
 * Константы: 0xFFFFFFFF, 0x3007E26C, 0x00500001, 0x00500000
 * Данные: DAT_3007e5c0, DAT_3007f1e4, DAT_3007f1e8, DAT_3007f1ec, DAT_3007f284, DAT_3007f288, DAT_3007f3c0, DAT_3007f3c4
 * ---------------------------------------------------------------- */
void TFUP_ValidateCRCWithLic(undefined4 param_1,char *param_2)

{
  uint uVar1;
  longlong lVar2;
  void *__ptr;
  FILE *__stream;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  undefined1 auStack_b0 [2];
  undefined1 auStack_ae [2];
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  long local_98;
  int local_94;
  uint local_90;
  int local_8c;
  uint local_88;
  int local_84;
  uint local_80;
  int local_7c;
  uint local_78;
  int local_74;
  uint local_70;
  int local_6c;
  uint local_68;
  int local_64;
  uint local_60;
  int local_5c;
  uint local_58;
  int local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  __ptr = malloc(0x100);
  if (__ptr == (void *)0x0) {
    local_9c = tickGet();
    uVar1 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_9c >> 0x25);
    local_54 = local_9c + uVar1 * -100;
    local_2c = tickGet((int)((ulonglong)DAT_3007e5c0 * (ulonglong)local_9c),uVar1 * 100,DAT_3007e5c0
                       ,0);
    local_50 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_2c >> 0x25);
    TFUP_LogPrintf(DAT_3007f1e4,local_50,local_54,0x100);
    OSAL_LogMsg(DAT_3007f1e8,1,2,3,4,5,6);
  }
  else {
    __stream = fopen(param_2,DAT_3007f1ec);
    if (__stream == (FILE *)0x0) {
      free(__ptr);
      local_a0 = tickGet();
      uVar1 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_a0 >> 0x25);
      local_5c = local_a0 + uVar1 * -100;
      local_30 = tickGet((int)((ulonglong)DAT_3007e5c0 * (ulonglong)local_a0),uVar1 * 100,
                         DAT_3007e5c0,0);
      local_58 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_30 >> 0x25);
      TFUP_LogPrintf(DAT_3007f284,local_58,local_5c,param_2);
      OSAL_LogMsg(DAT_3007f288,1,2,3,4,5,6);
    }
    else {
      rewind(__stream);
      iVar3 = fseek(__stream,0,2);
      if (iVar3 == -1) {
        fclose(__stream);
        free(__ptr);
        local_a4 = tickGet();
        uVar1 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_a4 >> 0x25);
        local_64 = local_a4 + uVar1 * -100;
        local_34 = tickGet((int)((ulonglong)DAT_3007e5c0 * (ulonglong)local_a4),uVar1 * 100,
                           DAT_3007e5c0,0);
        local_60 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_34 >> 0x25);
        TFUP_LogPrintf(DAT_3007f3c0,local_60,local_64,param_2);
        OSAL_LogMsg(DAT_3007f3c4,1,2,3,4,5,6);
      }
      else {
        local_98 = ftell(__stream);
        if (local_98 == -1) {
          fclose(__stream);
          free(__ptr);
          local_a8 = tickGet();
          uVar1 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_a8 >> 0x25);
          local_6c = local_a8 + uVar1 * -100;
          local_38 = tickGet((int)((ulonglong)DAT_3007e5c0 * (ulonglong)local_a8),uVar1 * 100,
                             DAT_3007e5c0,0);
          local_68 = (uint)((ulonglong)DAT_3007e5c0 * (ulonglong)local_38 >> 0x25);
          TFUP_LogPrintf(DAT_3007f3c8,local_68,local_6c,param_2);
          OSAL_LogMsg(DAT_3007f3cc,1,2,3,4,5,6);
        }
        else if (local_98 < 0x500001) {
          fclose(__stream);
          free(__ptr);
          local_ac = tickGet();
          uVar1 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)local_ac >> 0x25);
          local_74 = local_ac + uVar1 * -100;
          local_3c = tickGet((int)((ulonglong)DAT_3007f4fc * (ulonglong)local_ac),uVar1 * 100,
                             DAT_3007f4fc,0);
          local_70 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)local_3c >> 0x25);
          TFUP_LogPrintf(DAT_3007f500,local_70,local_74,param_2);
          OSAL_LogMsg(DAT_3007f504,1,2,3,4,5,6);
        }
        else {
          for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
            iVar4 = TFUP_ReadDataFromTF(param_2,__ptr,0x500000,0x100);
            if (iVar4 != 0) {
              fclose(__stream);
              free(__ptr);
              uVar5 = tickGet();
              lVar2 = (ulonglong)DAT_3007f4fc * (uVar5 & 0xffffffff);
              local_7c = (int)uVar5 + (uint)((ulonglong)lVar2 >> 0x25) * -100;
              local_40 = tickGet((int)uVar5,(int)(uVar5 >> 0x20),(int)lVar2);
              local_78 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)local_40 >> 0x25);
              TFUP_LogPrintf(DAT_3007f5e8,local_78,local_7c,param_2);
              OSAL_LogMsg(DAT_3007f5ec,1,2,3,4,5,6);
              return;
            }
            iVar4 = CalculateCRC(__ptr,0x100,auStack_b0);
            if (iVar4 != 1) {
              fclose(__stream);
              free(__ptr);
              uVar5 = tickGet();
              lVar2 = (ulonglong)DAT_3007f4fc * (uVar5 & 0xffffffff);
              local_84 = (int)uVar5 + (uint)((ulonglong)lVar2 >> 0x25) * -100;
              local_44 = tickGet((int)uVar5,(int)(uVar5 >> 0x20),(int)lVar2);
              local_80 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)local_44 >> 0x25);
              TFUP_LogPrintf(DAT_3007f70c,local_80,local_84,0);
              OSAL_LogMsg(DAT_3007f710,1,2,3,4,5,6);
              return;
            }
            iVar4 = TFUP_ReadDataFromTF(param_1,auStack_ae,0x20,2);
            if (iVar4 != 0) {
              fclose(__stream);
              free(__ptr);
              uVar5 = tickGet();
              lVar2 = (ulonglong)DAT_3007f4fc * (uVar5 & 0xffffffff);
              local_8c = (int)uVar5 + (uint)((ulonglong)lVar2 >> 0x25) * -100;
              local_48 = tickGet((int)uVar5,(int)(uVar5 >> 0x20),(int)lVar2);
              local_88 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)local_48 >> 0x25);
              TFUP_LogPrintf(DAT_3007f714,local_88,local_8c,param_2);
              OSAL_LogMsg(DAT_3007f5ec,1,2,3,4,5,6);
              return;
            }
            iVar4 = memcmp(auStack_b0,auStack_ae,2);
            if (iVar4 == 0) {
              fclose(__stream);
              free(__ptr);
              return;
            }
            if (iVar3 == 2) {
              fclose(__stream);
              free(__ptr);
              uVar5 = tickGet();
              lVar2 = (ulonglong)DAT_3007f4fc * (uVar5 & 0xffffffff);
              local_94 = (int)uVar5 + (uint)((ulonglong)lVar2 >> 0x25) * -100;
              local_4c = tickGet((int)uVar5,(int)(uVar5 >> 0x20),(int)lVar2);
              local_90 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)local_4c >> 0x25);
              TFUP_LogPrintf(DAT_3007f798,local_90,local_94,param_2,param_1);
              OSAL_LogMsg(DAT_3007f79c,1,2,3,4,5,6);
              return;
            }
          }
          fclose(__stream);
          free(__ptr);
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * TFUP_GetAllFileName @ 0x3007EADC  (примерный размер ~764 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 8
 * Вызывает: OSAL_LogMsg, TFUP_LogPrintf, closedir, getFilePath, opendir, readdir, strcmp, tickGet
 * Вызывают: TFUP_CheckFileValidify
 * Константы: 0xFFFFFFFF, 0x3007EADC
 * Данные: DAT_3007f4fc, DAT_3007f7a4, DAT_3007f7a8, DAT_3007f7ac, DAT_3007f7b0, DAT_3007f7b4, DAT_3007f7b8, DAT_3007f7bc
 * ---------------------------------------------------------------- */
undefined4 TFUP_GetAllFileName(char *param_1,int *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  DIR *__dirp;
  uint uVar3;
  uint uVar4;
  dirent *pdVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulonglong uVar10;
  
  if ((param_1 == (char *)0x0) || (param_2 == (int *)0x0)) {
    OSAL_LogMsg(DAT_3007f7a4,1,2,3,4,5,6);
    uVar2 = 0xffffffff;
  }
  else {
    __dirp = opendir(param_1);
    iVar8 = 0;
    if (__dirp == (DIR *)0x0) {
      uVar3 = tickGet();
      uVar6 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar3 >> 0x25);
      uVar4 = tickGet((int)((ulonglong)DAT_3007f4fc * (ulonglong)uVar3),uVar6 * 100,DAT_3007f4fc,0);
      TFUP_LogPrintf(DAT_3007f7a8,(uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar4 >> 0x25),
                     uVar3 + uVar6 * -100,0);
      OSAL_LogMsg(DAT_3007f7ac,1,2,3,4,5,6);
      uVar2 = 0xffffffff;
    }
    else {
      do {
        pdVar5 = readdir(__dirp);
        iVar9 = iVar8;
        if (pdVar5 != (dirent *)0x0) {
          if (4 < iVar8) {
            closedir(__dirp);
            uVar10 = tickGet();
            lVar1 = (ulonglong)DAT_3007f4fc * (uVar10 & 0xffffffff);
            uVar6 = tickGet((int)uVar10,(int)(uVar10 >> 0x20),(int)lVar1);
            TFUP_LogPrintf(DAT_3007f7b0,(uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar6 >> 0x25),
                           (int)uVar10 + (uint)((ulonglong)lVar1 >> 0x25) * -100);
            OSAL_LogMsg(DAT_3007f7b4,1,2,3,4,5,6);
            return 0xffffffff;
          }
          iVar7 = strcmp((char *)&pdVar5->d_off,DAT_3007f7b8);
          if ((iVar7 != 0) && (iVar7 = strcmp((char *)&pdVar5->d_off,DAT_3007f7bc), iVar7 != 0)) {
            iVar9 = iVar8 + 1;
            iVar8 = getFilePath(param_1,&pdVar5->d_off,DAT_3007f7c0 + iVar8 * 0x100);
            if (iVar8 == -1) {
              closedir(__dirp);
              uVar10 = tickGet();
              lVar1 = (ulonglong)DAT_3007f4fc * (uVar10 & 0xffffffff);
              uVar6 = tickGet((int)uVar10,(int)(uVar10 >> 0x20),(int)lVar1);
              TFUP_LogPrintf(DAT_3007f7c4,(uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar6 >> 0x25)
                             ,(int)uVar10 + (uint)((ulonglong)lVar1 >> 0x25) * -100,0);
              OSAL_LogMsg(DAT_3007f7c8,1,2,3,4,5,6);
              return 0xffffffff;
            }
          }
        }
        iVar8 = iVar9;
      } while (pdVar5 != (dirent *)0x0);
      *param_2 = iVar9;
      closedir(__dirp);
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * TFUP_LogInit @ 0x3007EDD8  (примерный размер ~96 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 3
 * Вызывает: memset, sdmmcGetDosFsDevName, strcat
 * Вызывают: TFUP_CheckFileValidify
 * Константы: 0x3007EDD8
 * Данные: DAT_3007f7cc, DAT_3007f7d0, DAT_3007f7d4, DAT_3007f7d8
 * ---------------------------------------------------------------- */
void TFUP_LogInit(void)

{
  int iVar1;
  
  iVar1 = sdmmcGetDosFsDevName();
  memset(DAT_3007f7cc,0,0x40);
  memset(DAT_3007f7d0,0,0x40);
  strcat(DAT_3007f7cc,(char *)(iVar1 + 4));
  strcat(DAT_3007f7cc,DAT_3007f7d4);
  strcat(DAT_3007f7d0,DAT_3007f7d8);
  return;
}

/* ----------------------------------------------------------------
 * TFUP_CheckFileValidify @ 0x3007EE38  (примерный размер ~1372 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 13
 * Вызывает: OSAL_LogMsg, TFUP_CheckVersionMatch, TFUP_GetAllFileName, TFUP_IdentifyFile, TFUP_LogInit, TFUP_LogPrintf, TFUP_ValidateCRCWithLic, ledFlush, memset, sdmmcGetDosFsDevName, strcat, taskDelay, tickGet
 * Вызывают: TFUP_CheckTask
 * Константы: 0xFFFFFFFF, 0x3007EE38
 * Данные: DAT_3007f4fc, DAT_3007f7c0, DAT_3007f7dc, DAT_3007f7e0, DAT_3007f7e4, DAT_3007f7e8, DAT_3007f7ec, DAT_3007f7f0
 * ---------------------------------------------------------------- */
undefined4 TFUP_CheckFileValidify(void)

{
  char cVar1;
  char cVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  ulonglong uVar12;
  undefined4 local_170;
  int local_16c;
  int local_168;
  uint local_164;
  int local_160;
  uint local_15c;
  int local_158;
  uint local_154;
  int local_150;
  uint local_14c;
  int local_148;
  uint local_144;
  int local_140;
  uint local_13c;
  uint local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  uint local_128;
  char acStack_124 [256];
  
  local_170 = 0;
  iVar11 = 0x80;
  pcVar8 = acStack_124;
  pcVar10 = DAT_3007f7dc;
  do {
    pcVar9 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 2;
    cVar2 = *pcVar9;
    iVar11 = iVar11 + -1;
    pcVar9 = pcVar8 + 1;
    *pcVar8 = cVar1;
    pcVar8 = pcVar8 + 2;
    *pcVar9 = cVar2;
  } while (iVar11 != 0);
  local_16c = sdmmcGetDosFsDevName(cVar1,cVar2,acStack_124);
  if (local_16c == 0) {
    OSAL_LogMsg(DAT_3007f7e0,1,2,3,4,5,6);
    uVar4 = 0xffffffff;
  }
  else {
    strcat(acStack_124,(char *)(local_16c + 4));
    strcat(acStack_124,DAT_3007f7e4);
    memset(DAT_3007f7c0,0,0x500);
    TFUP_LogInit();
    iVar11 = TFUP_GetAllFileName(acStack_124,&local_170);
    if (iVar11 == 0) {
      uVar5 = tickGet();
      uVar7 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar5 >> 0x25);
      local_140 = uVar5 + uVar7 * -100;
      local_128 = tickGet((int)((ulonglong)DAT_3007f4fc * (ulonglong)uVar5),uVar7 * 100,DAT_3007f4fc
                          ,0);
      local_13c = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)local_128 >> 0x25);
      TFUP_LogPrintf(DAT_3007f7e8,local_13c,local_140,0);
      OSAL_LogMsg(DAT_3007f7ec,1,2,3,4,5,6);
      iVar11 = TFUP_IdentifyFile(local_170);
      if (iVar11 == 0) {
        uVar5 = tickGet();
        uVar7 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar5 >> 0x25);
        local_148 = uVar5 + uVar7 * -100;
        local_12c = tickGet((int)((ulonglong)DAT_3007f4fc * (ulonglong)uVar5),uVar7 * 100,
                            DAT_3007f4fc,0);
        local_144 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)local_12c >> 0x25);
        TFUP_LogPrintf(DAT_3007f7f0,local_144,local_148,0);
        OSAL_LogMsg(DAT_3007f7f4,1,2,3,4,5,6);
        for (iVar11 = 0; iVar11 < *DAT_3007f7f8; iVar11 = iVar11 + 1) {
          if (*(int *)(DAT_3007f7fc + iVar11 * 8) == 0x9b) {
            iVar6 = TFUP_CheckVersionMatch(*(undefined4 *)(DAT_3007f800 + iVar11 * 8));
            if (iVar6 == -1) {
              ledFlush(3);
              return 0xffffffff;
            }
            uVar12 = tickGet();
            lVar3 = (ulonglong)DAT_3007f4fc * (uVar12 & 0xffffffff);
            local_150 = (int)uVar12 + (uint)((ulonglong)lVar3 >> 0x25) * -100;
            uVar7 = tickGet((int)uVar12,(int)(uVar12 >> 0x20),(int)lVar3);
            local_14c = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar7 >> 0x25);
            TFUP_LogPrintf(DAT_3007f804,local_14c,local_150);
          }
          iVar6 = TFUP_ValidateCRCWithLic
                            (*(undefined4 *)(DAT_3007f800 + iVar11 * 8),
                             *(undefined4 *)(DAT_3007f808 + iVar11 * 8));
          if (iVar6 == -1) {
            ledFlush(3);
            return 0xffffffff;
          }
          uVar12 = tickGet();
          lVar3 = (ulonglong)DAT_3007f4fc * (uVar12 & 0xffffffff);
          uVar7 = tickGet((int)uVar12,(int)(uVar12 >> 0x20),(int)lVar3);
          TFUP_LogPrintf(DAT_3007f80c,(uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar7 >> 0x25),
                         (int)uVar12 + (uint)((ulonglong)lVar3 >> 0x25) * -100,
                         *(undefined4 *)(DAT_3007f800 + iVar11 * 8));
          OSAL_LogMsg(DAT_3007f810,1,2,3,4,5,6);
        }
        uVar5 = tickGet();
        uVar7 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar5 >> 0x25);
        local_158 = uVar5 + uVar7 * -100;
        local_130 = tickGet((int)((ulonglong)DAT_3007f4fc * (ulonglong)uVar5),uVar7 * 100,
                            DAT_3007f4fc,0);
        local_154 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)local_130 >> 0x25);
        TFUP_LogPrintf(DAT_3007f814,local_154,local_158,0);
        uVar7 = 0;
        while ((uVar7 < 0x1e && (*DAT_3007f818 == 0))) {
          taskDelay(100);
          uVar7 = uVar7 + 1;
        }
        if (*DAT_3007f818 == 0) {
          uVar5 = tickGet();
          uVar7 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar5 >> 0x25);
          local_168 = uVar5 + uVar7 * -100;
          local_138 = tickGet((int)((ulonglong)DAT_3007f4fc * (ulonglong)uVar5),uVar7 * 100,
                              DAT_3007f4fc,0);
          local_164 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)local_138 >> 0x25);
          TFUP_LogPrintf(DAT_3007f820,local_164,local_168,0);
          uVar4 = 0xffffffff;
        }
        else {
          uVar5 = tickGet();
          uVar7 = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar5 >> 0x25);
          local_160 = uVar5 + uVar7 * -100;
          local_134 = tickGet((int)((ulonglong)DAT_3007f4fc * (ulonglong)uVar5),uVar7 * 100,
                              DAT_3007f4fc,0);
          local_15c = (uint)((ulonglong)DAT_3007f4fc * (ulonglong)local_134 >> 0x25);
          TFUP_LogPrintf(DAT_3007f81c,local_15c,local_160,0);
          (*(code *)*DAT_3007f818)();
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 0xffffffff;
      }
    }
    else {
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * TFUP_CheckTask @ 0x3007F394  (примерный размер ~604 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 8
 * Вызывает: OSAL_LogMsg, OSAL_SemTake, TFUP_CheckFileValidify, TFUP_LogPrintf, TFUP_dosFsDevCreate, TFUP_setTFUpdateFlag, sdmmcGetStatus, tickGet
 * Константы: 0xFFFFFFFF, 0x3007F394
 * Данные: DAT_3007f4fc, DAT_3007f824, DAT_3007f828, DAT_3007f82c, DAT_3007f830, DAT_3007f834, DAT_3007f838, DAT_3007f83c
 * ---------------------------------------------------------------- */
void TFUP_CheckTask(void)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  
  do {
    while( true ) {
      while( true ) {
        OSAL_SemTake(*DAT_3007f824,0xffffffff);
        iVar2 = sdmmcGetStatus();
        if (iVar2 == 1) break;
        uVar4 = tickGet();
        lVar1 = (ulonglong)DAT_3007f838 * (uVar4 & 0xffffffff);
        uVar3 = tickGet((int)uVar4,(int)(uVar4 >> 0x20),(int)lVar1);
        TFUP_LogPrintf(DAT_3007f840,(uint)((ulonglong)DAT_3007f838 * (ulonglong)uVar3 >> 0x25),
                       (int)uVar4 + (uint)((ulonglong)lVar1 >> 0x25) * -100,0);
        OSAL_LogMsg(DAT_3007f844);
        TFUP_setTFUpdateFlag(0);
      }
      iVar2 = TFUP_dosFsDevCreate();
      if (iVar2 == 0) break;
      uVar4 = tickGet();
      lVar1 = (ulonglong)DAT_3007f4fc * (uVar4 & 0xffffffff);
      uVar3 = tickGet((int)uVar4,(int)(uVar4 >> 0x20),(int)lVar1);
      TFUP_LogPrintf(DAT_3007f828,(uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar3 >> 0x25),
                     (int)uVar4 + (uint)((ulonglong)lVar1 >> 0x25) * -100,0);
      OSAL_LogMsg(DAT_3007f82c,1,2,3,4,5,6);
      TFUP_setTFUpdateFlag(0);
    }
    iVar2 = TFUP_CheckFileValidify();
    if (iVar2 == 0) {
      uVar4 = tickGet();
      lVar1 = (ulonglong)DAT_3007f4fc * (uVar4 & 0xffffffff);
      uVar3 = tickGet((int)uVar4,(int)(uVar4 >> 0x20),(int)lVar1);
      TFUP_LogPrintf(DAT_3007f830,(uint)((ulonglong)DAT_3007f4fc * (ulonglong)uVar3 >> 0x25),
                     (int)uVar4 + (uint)((ulonglong)lVar1 >> 0x25) * -100,0);
      OSAL_LogMsg(DAT_3007f834,1,2,3,4,5,6);
    }
    else {
      uVar4 = tickGet();
      lVar1 = (ulonglong)DAT_3007f838 * (uVar4 & 0xffffffff);
      uVar3 = tickGet((int)uVar4,(int)(uVar4 >> 0x20),(int)lVar1);
      TFUP_LogPrintf(DAT_3007f83c,(uint)((ulonglong)DAT_3007f838 * (ulonglong)uVar3 >> 0x25),
                     (int)uVar4 + (uint)((ulonglong)lVar1 >> 0x25) * -100,0);
      TFUP_setTFUpdateFlag(0);
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * TFUP_dosFsDevDelete @ 0x3007F5F0  (примерный размер ~180 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, taskDelay, taskDelete, taskNameToId, xbdBlkDevDelete
 * Константы: 0x3007F5F0, 0xFFFFFFFF
 * Данные: DAT_3007f848, DAT_3007f84c, DAT_3007f850, DAT_3007f854
 * ---------------------------------------------------------------- */
undefined4 TFUP_dosFsDevDelete(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*DAT_3007f848 == 0) || (*DAT_3007f84c == 0)) {
    uVar1 = 0;
  }
  else {
    iVar2 = xbdBlkDevDelete(*DAT_3007f84c,DAT_3007f848);
    if (iVar2 == 0) {
      taskDelay(5);
      *DAT_3007f848 = 0;
      *DAT_3007f84c = 0;
      taskNameToId(DAT_3007f854);
      taskDelete();
      uVar1 = 0;
    }
    else {
      OSAL_LogMsg(DAT_3007f850,1,2,3,4,5,6);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * TFUP_CheckCallback @ 0x3007F6A4  (примерный размер ~136 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 2
 * Вызывает: OSAL_LogMsg, OSAL_SemGive
 * Константы: 0x3007F6A4
 * Данные: DAT_3007f824, DAT_3007f858, DAT_3007f85c
 * ---------------------------------------------------------------- */
void TFUP_CheckCallback(void)

{
  if ((*(int *)*DAT_3007f858 == 0) || (*(int *)*DAT_3007f858 == 1)) {
    OSAL_LogMsg(DAT_3007f85c,*(undefined4 *)*DAT_3007f858,2,3,4,5,6);
  }
  else {
    OSAL_SemGive(*DAT_3007f824);
  }
  return;
}

/* ----------------------------------------------------------------
 * TFUP_LogFsInit @ 0x3007F72C  (примерный размер ~312 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 5
 * Вызывает: fclose, fopen, fseek, ftell, remove
 * Константы: 0x3007F72C
 * Данные: DAT_3007f860
 * ---------------------------------------------------------------- */
FILE * TFUP_LogFsInit(char *param_1)

{
  FILE *__stream;
  long lVar1;
  
  __stream = fopen(param_1,DAT_3007f860);
  if (__stream != (FILE *)0x0) {
    fseek(__stream,0,2);
    lVar1 = ftell(__stream);
    if (0xffff < lVar1) {
      fclose(__stream);
      remove(param_1);
      __stream = fopen(param_1,DAT_3007f860);
    }
  }
  return __stream;
}

/* ----------------------------------------------------------------
 * dloadInfoATHandle @ 0x3007F864  (примерный размер ~224 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 7
 * Вызывает: BSP_DLOAD_GetDloadInfo, OSAL_LogMsg, dloadUSBSend, free, malloc, memset, strlen
 * Константы: 0xFFFFFFFF, 0x3007F864
 * Данные: DAT_3007fa2c, DAT_3007fa30
 * ---------------------------------------------------------------- */
undefined4 dloadInfoATHandle(void)

{
  char *__s;
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  
  __s = (char *)malloc(0x400);
  if (__s == (char *)0x0) {
    OSAL_LogMsg(DAT_3007fa2c,1,2,3,4,5,6);
    sVar1 = strlen(DAT_3007fa30);
    dloadUSBSend(DAT_3007fa30,sVar1);
    uVar2 = 0xffffffff;
  }
  else {
    memset(__s,0,0x400);
    iVar3 = BSP_DLOAD_GetDloadInfo(__s,1);
    if (iVar3 == 0) {
      sVar1 = strlen(__s);
      dloadUSBSend(__s,sVar1);
      free(__s);
      uVar2 = 0;
    }
    else {
      free(__s);
      sVar1 = strlen(DAT_3007fa30);
      dloadUSBSend(DAT_3007fa30,sVar1);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * dloadUSBSendPro @ 0x3007FE10  (примерный размер ~2148 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 14
 * Вызывает: BSP_DLOAD_GetSoftwareVer, OSAL_LogMsg, Om_HdlcEncap, dloadUSBSend, free, getDloadID, malloc, memcpy, memset, omTimerTickGet, snprintf, strcat, strlen, update_record_file
 * Вызывают: FUN_30080798
 * Константы: 0xFFFFFFFF, 0x3007FE10
 * Данные: DAT_30080d94, DAT_30080d98, DAT_30080d9c, DAT_30080da0, DAT_30080da4, DAT_30080da8, DAT_30080dac, DAT_30080db0
 * ---------------------------------------------------------------- */
undefined4 dloadUSBSendPro(int param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  size_t sVar4;
  size_t sVar5;
  uint uVar6;
  void *pvVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  ushort local_128 [2];
  char acStack_124 [256];
  
  pcVar8 = acStack_124;
  iVar11 = 0x80;
  pcVar10 = DAT_30080d94;
  do {
    pcVar9 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 2;
    cVar2 = *pcVar9;
    iVar11 = iVar11 + -1;
    pcVar9 = pcVar8 + 1;
    *pcVar8 = cVar1;
    pcVar8 = pcVar8 + 2;
    *pcVar9 = cVar2;
  } while (iVar11 != 0);
  if (*DAT_30080d98 != 0) {
    memset(acStack_124,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_124,0x100,DAT_30080d9c,uVar3,param_1);
    update_record_file(acStack_124);
  }
  if (param_1 == 0x4b) {
    pcVar10 = (char *)malloc(0x5e);
    if (pcVar10 == (char *)0x0) {
      OSAL_LogMsg(DAT_30081060,1,2,3,4,5,6);
      dloadUSBSend(DAT_30080dac,7);
    }
    else {
      memset(pcVar10,0,0x1f);
      iVar11 = BSP_DLOAD_GetSoftwareVer(pcVar10,0x1e);
      if (iVar11 == 0) {
        pcVar8 = (char *)malloc(0x42);
        if (pcVar8 == (char *)0x0) {
          OSAL_LogMsg(DAT_30080e7c,1,2,3,4,5,6);
          free(pcVar10);
          dloadUSBSend(DAT_30080dac,7);
        }
        else {
          memset(pcVar8,0,0x42);
          *pcVar8 = 'K';
          pcVar8[1] = -0x37;
          pcVar8[2] = '\x03';
          pcVar8[3] = -1;
          strcat(pcVar8,pcVar10);
          pvVar7 = malloc(0x8a);
          if (pvVar7 == (void *)0x0) {
            OSAL_LogMsg(DAT_30080f8c,1,2,3,4,5,6);
            free(pcVar10);
            free(pcVar8);
            dloadUSBSend(DAT_30080dac,7);
          }
          else {
            iVar11 = Om_HdlcEncap(pcVar8,0x42,pvVar7,0x8a,local_128);
            if (iVar11 == 0) {
              memcpy(pvVar7,(void *)((int)pvVar7 + 1),(uint)local_128[0]);
              dloadUSBSend(pvVar7,local_128[0] - 1);
            }
            else {
              OSAL_LogMsg(DAT_30080f90,1,2,3,4,5,6);
              dloadUSBSend(DAT_30080dac,7);
            }
            free(pcVar10);
            free(pcVar8);
            free(pvVar7);
          }
        }
      }
      else {
        OSAL_LogMsg(DAT_300812c4,1,2,3,4,5,6);
        free(pcVar10);
        dloadUSBSend(DAT_30080dac,7);
      }
    }
  }
  else if (param_1 < 0x4c) {
    if (param_1 == 0x3a) {
      dloadUSBSend(DAT_30080db8,5);
    }
    else if (param_1 < 0x3b) {
      if (param_1 == 2) {
        dloadUSBSend(DAT_30080da8,5);
      }
      else {
        if (param_1 != 0xd) {
          return 0xffffffff;
        }
        dloadUSBSend(DAT_30080dc0,0x14);
      }
    }
    else if (param_1 == 0x45) {
      memset(acStack_124,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_124,0x100,DAT_30080e74,uVar3);
      update_record_file(acStack_124);
      pcVar10 = (char *)getDloadID();
      sVar5 = strlen(pcVar10);
      sVar4 = strlen(DAT_30080e78);
      if (sVar4 + (sVar5 & 0xffff) + 1 < 0x15) {
        uVar6 = 0x15;
      }
      else {
        sVar4 = strlen(DAT_30080e78);
        uVar6 = sVar4 + sVar5 + 1;
      }
      pcVar10 = (char *)malloc(uVar6 & 0xffff);
      if (pcVar10 == (char *)0x0) {
        OSAL_LogMsg(DAT_30080e7c,1,2,3,4,5,6);
        dloadUSBSend(DAT_30080dac,7);
      }
      else {
        memset(pcVar10,0,uVar6 & 0xffff);
        *pcVar10 = 'E';
        pcVar8 = (char *)getDloadID();
        pcVar9 = strcat(pcVar10,DAT_30080e78);
        strcat(pcVar9,pcVar8);
        pvVar7 = malloc(0x30);
        if (pvVar7 == (void *)0x0) {
          OSAL_LogMsg(DAT_30080f8c,1,2,3,4,5,6);
          free(pcVar10);
          dloadUSBSend(DAT_30080dac,7);
        }
        else {
          iVar11 = Om_HdlcEncap(pcVar10,0x15,pvVar7,0x30,local_128);
          if (iVar11 == 0) {
            dloadUSBSend(pvVar7,local_128[0]);
          }
          else {
            OSAL_LogMsg(DAT_30080f90,1,2,3,4,5,6);
            dloadUSBSend(DAT_30080dac,7);
          }
          free(pcVar10);
          free(pvVar7);
        }
      }
    }
    else {
      if (param_1 != 0x46) {
        return 0xffffffff;
      }
      pcVar10 = (char *)malloc(0x1f);
      if (pcVar10 == (char *)0x0) {
        OSAL_LogMsg(DAT_30081060,1,2,3,4,5,6);
        dloadUSBSend(DAT_30080dac,7);
      }
      else {
        memset(pcVar10,0,0x1f);
        iVar11 = BSP_DLOAD_GetSoftwareVer(pcVar10,0x1e);
        if (iVar11 == 0) {
          sVar5 = strlen(pcVar10);
          if (sVar5 < 0x19) {
            uVar6 = 0x1a;
          }
          else {
            sVar5 = strlen(pcVar10);
            uVar6 = sVar5 + 2;
          }
          pcVar8 = (char *)malloc(uVar6 & 0xffff);
          if (pcVar8 == (char *)0x0) {
            OSAL_LogMsg(DAT_30080e7c,1,2,3,4,5,6);
            free(pcVar10);
            dloadUSBSend(DAT_30080dac,7);
          }
          else {
            memset(pcVar8,0,uVar6 & 0xffff);
            *pcVar8 = 'F';
            pcVar8[1] = '\x18';
            strcat(pcVar8,pcVar10);
            pvVar7 = malloc(0x3a);
            if (pvVar7 == (void *)0x0) {
              OSAL_LogMsg(DAT_30080f8c,1,2,3,4,5,6);
              free(pcVar10);
              free(pcVar8);
              dloadUSBSend(DAT_30080dac,7);
            }
            else {
              iVar11 = Om_HdlcEncap(pcVar8,0x1a,pvVar7,0x3a,local_128);
              if (iVar11 == 0) {
                dloadUSBSend(pvVar7,local_128[0]);
              }
              else {
                OSAL_LogMsg(DAT_30080f90,1,2,3,4,5,6);
                dloadUSBSend(DAT_30080dac,7);
              }
              free(pcVar10);
              free(pcVar8);
              free(pvVar7);
            }
          }
        }
        else {
          OSAL_LogMsg(DAT_30081064,DAT_30081068,2,3,4,5,6);
          free(pcVar10);
          dloadUSBSend(DAT_30080dac,7);
        }
      }
    }
  }
  else if (param_1 == 0xfb) {
    dloadUSBSend(DAT_30080dbc,6);
  }
  else if (param_1 == DAT_30080da0) {
    dloadUSBSend(DAT_30080db4,7);
  }
  else if (param_1 == 0x304) {
    dloadUSBSend(DAT_30080db0,7);
  }
  else {
    if (param_1 != DAT_30080da4) {
      return 0xffffffff;
    }
    dloadUSBSend(DAT_30080dac,7);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * dload_GetISOUseableSize @ 0x3008070C  (примерный размер ~140 байт)
 * Модуль: dload | Вызывают: 2 | Вызывает: 3
 * Вызывает: OSAL_LogMsg, ptable_get_ram_data, strcmp
 * Вызывают: FUN_30080798, dloadFromFsCheckSpaceForISO
 * Константы: 0x00400000, 0x3008070C
 * Данные: DAT_30081570, DAT_30081574
 * ---------------------------------------------------------------- */
int dload_GetISOUseableSize(int param_1)

{
  char *__s2;
  int iVar1;
  
  for (__s2 = (char *)ptable_get_ram_data();
      (iVar1 = strcmp(DAT_30081570,__s2), iVar1 != 0 && (*(int *)(__s2 + 0x24) != param_1));
      __s2 = __s2 + 0x30) {
  }
  iVar1 = *(int *)(__s2 + 0x18);
  OSAL_LogMsg(DAT_30081574,param_1,*(undefined4 *)(__s2 + 0x10),iVar1 + -0x400000,4,5,6);
  return iVar1 + -0x400000;
}

/* ----------------------------------------------------------------
 * FUN_30080798 @ 0x30080798  (примерный размер ~5352 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 27
 * Вызывает: BSP_DLOAD_SetCdromMarker, DCBInit, DLOAD_LEDInd, HighToLow, OSAL_LogMsg, Om_HdlcInit, dloadBootromEnd, dloadInitRamBuffer, dloadNeedMidwayRestart, dloadUSBSendPro, dload_GetISOUseableSize, dynFSDloadProcess, fclose, fopen
 *           ...
 * Вызывают: dloadUSBCallback
 * Константы: 0x30080798
 * Данные: DAT_30080a24, DAT_30080d98, DAT_30080da0, DAT_30080da4, DAT_30081578, DAT_30081654, DAT_30081658, DAT_3008170c
 * ---------------------------------------------------------------- */
undefined4 FUN_30080798(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  FILE *pFVar4;
  size_t sVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  char acStack_124 [256];
  
  pcVar6 = acStack_124;
  iVar11 = 0x80;
  pcVar8 = DAT_30081578;
  do {
    pcVar7 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 2;
    cVar2 = *pcVar7;
    iVar11 = iVar11 + -1;
    pcVar7 = pcVar6 + 1;
    *pcVar6 = cVar1;
    pcVar6 = pcVar6 + 2;
    *pcVar7 = cVar2;
  } while (iVar11 != 0);
  uVar10 = (uint)**(byte **)(DAT_30081654 + 0xc);
  if (uVar10 == 0x42) {
    *DAT_30080d98 = 0;
  }
  else {
    memset(acStack_124,0x100,0);
    *DAT_30080d98 = 1;
    uVar3 = omTimerTickGet();
    snprintf(acStack_124,0x100,DAT_30081658,uVar3,uVar10);
    update_record_file(acStack_124);
  }
  uVar9 = DAT_30081e30;
  uVar3 = DAT_30080da4;
  if (uVar10 == 0x43) {
    if (*(int *)(DAT_30081e2c + 0x10) == 0x17) {
      if ((((*(int *)(*DAT_30081830 + 4) != 1) && (*(int *)(*DAT_30081830 + 4) != 0x10c)) &&
          (*(int *)(*DAT_30081830 + 4) != 0x65)) &&
         ((*(int *)(*DAT_30081830 + 4) != 2 && (*(int *)(*DAT_30081830 + 4) != DAT_30081e3c)))) {
        BSP_DLOAD_SetCdromMarker(0);
      }
      uVar9 = 2;
      if (*DAT_30081e40 == 0x10c) {
        pFVar4 = fopen(*(char **)(DAT_30081c60 + 4),DAT_30081e44);
        if (pFVar4 == (FILE *)0x0) {
          OSAL_LogMsg(DAT_30081e58,1,2,3,4,5,6);
          memset(acStack_124,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_124,0x100,DAT_30081e5c,uVar3);
          update_record_file(acStack_124);
          uVar9 = DAT_30081d24;
        }
        else {
          sVar5 = fwrite(DAT_30081e00,1,*DAT_30081df4,pFVar4);
          if (sVar5 != *DAT_30081df4) {
            OSAL_LogMsg(DAT_30081e48,1,2,3,4,5,6);
            memset(acStack_124,0x100,0);
            uVar3 = omTimerTickGet();
            snprintf(acStack_124,0x100,DAT_30081e4c,uVar3);
            update_record_file(acStack_124);
            uVar9 = DAT_30081d24;
          }
          iVar11 = fclose(pFVar4);
          if (iVar11 != 0) {
            OSAL_LogMsg(DAT_30081e50,1,2,3,4,5,6);
            memset(acStack_124,0x100,0);
            uVar3 = omTimerTickGet();
            snprintf(acStack_124,0x100,DAT_30081e54,uVar3);
            update_record_file(acStack_124);
            uVar9 = DAT_30081d24;
          }
        }
      }
      else if (*DAT_30081e40 == 0x65) {
        pFVar4 = fopen(*(char **)(DAT_30081c60 + 8),DAT_30081e44);
        if (pFVar4 == (FILE *)0x0) {
          OSAL_LogMsg(DAT_30081e58,1,2,3,4,5,6);
          memset(acStack_124,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_124,0x100,DAT_30081e5c,uVar3);
          update_record_file(acStack_124);
          uVar9 = DAT_30081d24;
        }
        else {
          sVar5 = fwrite(DAT_30081e18,1,*DAT_30081e0c,pFVar4);
          if (sVar5 != *DAT_30081e0c) {
            OSAL_LogMsg(DAT_30081e48,1,2,3,4,5,6);
            memset(acStack_124,0x100,0);
            uVar3 = omTimerTickGet();
            snprintf(acStack_124,0x100,DAT_30081e4c,uVar3);
            update_record_file(acStack_124);
            uVar9 = DAT_30081d24;
          }
          iVar11 = fclose(pFVar4);
          if (iVar11 != 0) {
            OSAL_LogMsg(DAT_30081e50,1,2,3,4,5,6);
            memset(acStack_124,0x100,0);
            uVar3 = omTimerTickGet();
            snprintf(acStack_124,0x100,DAT_30081e54,uVar3);
            update_record_file(acStack_124);
            uVar9 = DAT_30081d24;
          }
        }
      }
      *DAT_30081e40 = 0x50;
      *(undefined4 *)(DAT_30081e60 + 4) = 0;
      memset(acStack_124,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_124,0x100,DAT_30081e68,uVar3,*(undefined4 *)(*DAT_30081e64 + 4));
      update_record_file(acStack_124);
      DCBInit();
      OSAL_LogMsg(DAT_30081e6c,1,2,3,4,5,6);
    }
    else {
      OSAL_LogMsg(DAT_30081e34,*(undefined4 *)(DAT_30081e2c + 0x10),2,3,4,5,6);
      memset(acStack_124,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_124,0x100,DAT_30081e38,uVar3,*(undefined4 *)(DAT_30081e2c + 0x10));
      update_record_file(acStack_124);
    }
  }
  else {
    uVar9 = DAT_30080da0;
    if (uVar10 < 0x44) {
      if (uVar10 == 0x3a) {
        if (*(int *)(DAT_30081654 + 0x10) == 1) {
          uVar9 = 0x3a;
        }
      }
      else if (uVar10 < 0x3b) {
        if (uVar10 == 10) {
          if (*(int *)(DAT_30081654 + 0x10) == 1) {
            dloadUSBSendPro(2);
            taskDelay(200);
            *(undefined4 *)*DAT_30080a24 = 2;
            DLOAD_LEDInd(2);
            dloadBootromEnd(0x20);
            uVar9 = 0x310;
          }
        }
        else {
          uVar9 = DAT_30081e70;
          if ((uVar10 == 0xc) && (uVar9 = DAT_30080da0, *(int *)(DAT_30081654 + 0x10) == 1)) {
            if (*(int *)*DAT_30080a24 == 1) {
              OSAL_LogMsg(DAT_3008170c,1,2,3,4,5,6);
              uVar9 = uVar3;
            }
            else {
              *(undefined4 *)*DAT_30080a24 = 0;
              ledFlush(1);
              uVar9 = 0xd;
            }
          }
        }
      }
      else if (uVar10 == 0x41) {
        OSAL_LogMsg(DAT_30081948,1,2,3,4,5,6);
        uVar9 = DAT_30080da0;
        if (*(int *)(DAT_30081654 + 0x10) == 0xc) {
          *(undefined4 *)(DAT_3008194c + 4) = 0;
          DCBInit();
          DLOAD_LEDInd(1);
          Om_HdlcInit(DAT_30081654);
          *(undefined4 *)(DAT_30081654 + 8) = 0x2200;
          uVar3 = HighToLow(*(int *)(DAT_30081654 + 0xc) + 1,4);
          *(undefined4 *)(*DAT_30081830 + 4) = uVar3;
          iVar11 = imageTypeChange(*DAT_30081830 + 4);
          uVar9 = DAT_30080da4;
          if (iVar11 == -1) {
            OSAL_LogMsg(DAT_30081a6c,*(undefined4 *)(*DAT_30081830 + 4),2,3,4,5,6);
            memset(acStack_124,0x100,0);
            uVar3 = omTimerTickGet();
            snprintf(acStack_124,0x100,DAT_30081a70,uVar3,*(undefined4 *)(*DAT_30081830 + 4));
            update_record_file(acStack_124);
          }
          else {
            uVar3 = HighToLow(*(int *)(DAT_30081654 + 0xc) + 5,4);
            *(undefined4 *)(*DAT_30081830 + 8) = uVar3;
            if (*(int *)(*DAT_30081830 + 8) == 0) {
              OSAL_LogMsg(DAT_30081a74,*(undefined4 *)(*DAT_30081830 + 8),2,3,4,5,6);
              memset(acStack_124,0x100,0);
              uVar3 = omTimerTickGet();
              snprintf(acStack_124,0x100,DAT_30081b40,uVar3,*(undefined4 *)(*DAT_30081830 + 8));
              update_record_file(acStack_124);
            }
            iVar11 = dloadInitRamBuffer(*(undefined4 *)(*DAT_30081830 + 4),
                                        *(undefined4 *)(*DAT_30081830 + 8));
            uVar9 = DAT_30080da4;
            if (iVar11 == 0) {
              logMsg(DAT_30081c5c,*(undefined4 *)(*DAT_30081830 + 8),2,3,4,5,6);
              if ((*(int *)(*DAT_30081830 + 4) == 1) || (*(int *)(*DAT_30081830 + 4) == 2)) {
                if (*(int *)(*DAT_30081830 + 4) == 1) {
                  rm(*(char **)(DAT_30081c60 + *(int *)(*DAT_30081830 + 4) * 4));
                }
                else {
                  rm(*(char **)(DAT_30081c60 + *(int *)(*DAT_30081830 + 4) * 4));
                }
                OSAL_LogMsg(DAT_30081d1c,1,2,3,4,5,6);
                memset(acStack_124,0x100,0);
                uVar3 = omTimerTickGet();
                snprintf(acStack_124,0x100,DAT_30081d20,uVar3);
                update_record_file(acStack_124);
              }
              if ((*(int *)(*DAT_30081830 + 4) == 0x10c) &&
                 (uVar10 = dload_GetISOUseableSize(*(undefined4 *)(*DAT_30081830 + 4)),
                 uVar9 = DAT_30081d24, uVar10 < *(uint *)(*DAT_30081830 + 8))) {
                OSAL_LogMsg(DAT_30081dc0,*(undefined4 *)(*DAT_30081830 + 8),2,3,4,5,6);
                memset(acStack_124,0x100,0);
                uVar3 = omTimerTickGet();
                snprintf(acStack_124,0x100,DAT_30081dc4,uVar3,*(undefined4 *)(*DAT_30081830 + 8));
                update_record_file(acStack_124);
              }
              else {
                iVar11 = dloadNeedMidwayRestart();
                uVar9 = 2;
                if (iVar11 != 0) {
                  taskDelay(5);
                  OSAL_LogMsg(DAT_30081dc8,1,2,3,4,5,6);
                  memset(acStack_124,0x100,0);
                  uVar3 = omTimerTickGet();
                  snprintf(acStack_124,0x100,DAT_30081dcc,uVar3);
                  update_record_file(acStack_124);
                  uVar9 = DAT_30081d24;
                  taskDelay(5);
                }
              }
            }
            else {
              OSAL_LogMsg(DAT_30081b44,1,2,3,4,5,6);
              memset(acStack_124,0x100,0);
              uVar3 = omTimerTickGet();
              snprintf(acStack_124,0x100,DAT_30081c58,uVar3);
              update_record_file(acStack_124);
            }
          }
        }
      }
      else {
        uVar9 = DAT_30081e70;
        if (uVar10 == 0x42) {
          DLOAD_LEDInd(1);
          uVar3 = HighToLow(*(int *)(DAT_30081654 + 0xc) + 5,2);
          *(undefined4 *)(*DAT_30081830 + 0x18) = uVar3;
          if (*(int *)(DAT_30081654 + 0x10) == *(int *)(*DAT_30081830 + 0x18) + 7) {
            uVar10 = HighToLow(*(int *)(DAT_30081654 + 0xc) + 1,4);
            uVar9 = DAT_30081d24;
            if ((*(int *)(*DAT_30081830 + 0x20) + 1U < uVar10) ||
               (uVar10 < *(uint *)(*DAT_30081830 + 0x20))) {
              OSAL_LogMsg(DAT_30081dd8,uVar10,*(undefined4 *)(*DAT_30081830 + 0x20),3,4,5,6);
              memset(acStack_124,0x100,0);
              uVar3 = omTimerTickGet();
              snprintf(acStack_124,0x100,DAT_30081ddc,uVar3,uVar10,
                       *(undefined4 *)(*DAT_30081830 + 0x20));
              update_record_file(acStack_124);
            }
            else if (*(uint *)(*DAT_30081830 + 0x20) == uVar10) {
              OSAL_LogMsg(DAT_30081de0,uVar10,*(undefined4 *)(*DAT_30081830 + 0x20),3,4,5,6);
              memset(acStack_124,0x100,0);
              uVar3 = omTimerTickGet();
              snprintf(acStack_124,0x100,DAT_30081de4,uVar3,uVar10);
              update_record_file(acStack_124);
              uVar9 = 2;
            }
            else {
              *(int *)(*DAT_30081830 + 0x14) = *(int *)(DAT_30081654 + 0xc) + 7;
              if (*(int *)(*DAT_30081830 + 4) - 0x65U < 0x99) {
                iVar11 = dynFSDloadProcess();
                if (iVar11 == -1) {
                  *(undefined4 *)(DAT_3008194c + 4) = 0;
                  *(undefined4 *)(DAT_30081de8 + 0x14) = 0;
                  resetImgBuf();
                  DCBInit();
                  OSAL_LogMsg(DAT_30081dec,1,2,3,4,5,6);
                  memset(acStack_124,0x100,0);
                  uVar3 = omTimerTickGet();
                  snprintf(acStack_124,0x100,DAT_30081df0,uVar3);
                  update_record_file(acStack_124);
                  uVar9 = DAT_30081d24;
                }
                else {
                  *(uint *)(*DAT_30081830 + 0x20) = uVar10;
                  uVar9 = 2;
                }
              }
              else if (*(int *)(*DAT_30081830 + 4) == 1) {
                *DAT_30081df4 = *(size_t *)(*DAT_30081830 + 0x18);
                OSAL_LogMsg(DAT_30081df8,*DAT_30081df4,2,3,4,5,6);
                memset(acStack_124,0x100,0);
                uVar3 = omTimerTickGet();
                snprintf(acStack_124,0x100,DAT_30081dfc,uVar3,*DAT_30081df4);
                update_record_file(acStack_124);
                if (*DAT_30081df4 < 0x1f5) {
                  memcpy(DAT_30081e00,*(void **)(*DAT_30081830 + 0x14),
                         *(size_t *)(*DAT_30081830 + 0x18));
                  uVar9 = 2;
                }
                else {
                  OSAL_LogMsg(DAT_30081e04,1,2,3,4,5,6);
                  memset(acStack_124,0x100,0);
                  uVar3 = omTimerTickGet();
                  snprintf(acStack_124,0x100,DAT_30081e08,uVar3);
                  update_record_file(acStack_124);
                  uVar9 = DAT_30081d24;
                }
              }
              else if (*(int *)(*DAT_30081830 + 4) == 2) {
                *DAT_30081e0c = *(size_t *)(*DAT_30081830 + 0x18);
                OSAL_LogMsg(DAT_30081e10,*DAT_30081e0c,2,3,4,5,6);
                memset(acStack_124,0x100,0);
                uVar3 = omTimerTickGet();
                snprintf(acStack_124,0x100,DAT_30081e14,uVar3,*DAT_30081e0c);
                update_record_file(acStack_124);
                if (*DAT_30081e0c < 0xc9) {
                  memcpy(DAT_30081e18,*(void **)(*DAT_30081830 + 0x14),
                         *(size_t *)(*DAT_30081830 + 0x18));
                  uVar9 = 2;
                }
                else {
                  OSAL_LogMsg(DAT_30081e1c,1,2,3,4,5,6);
                  memset(acStack_124,0x100,0);
                  uVar3 = omTimerTickGet();
                  snprintf(acStack_124,0x100,DAT_30081e20,uVar3);
                  update_record_file(acStack_124);
                  uVar9 = DAT_30081d24;
                }
              }
              else {
                iVar11 = imageDloadProcess();
                if (iVar11 == -1) {
                  *(undefined4 *)(DAT_3008194c + 4) = 0;
                  *(undefined4 *)(DAT_30081de8 + 0x14) = 0;
                  resetImgBuf();
                  DCBInit();
                  OSAL_LogMsg(DAT_30081e24,1,2,3,4,5,6);
                  memset(acStack_124,0x100,0);
                  uVar3 = omTimerTickGet();
                  snprintf(acStack_124,0x100,DAT_30081e28,uVar3);
                  update_record_file(acStack_124);
                  uVar9 = DAT_30081d24;
                }
                else {
                  *(uint *)(*DAT_30081830 + 0x20) = uVar10;
                  uVar9 = 2;
                }
              }
            }
          }
          else {
            OSAL_LogMsg(DAT_30081dd0,*(undefined4 *)(DAT_30081654 + 0x10),
                        *(undefined4 *)(*DAT_30081830 + 0x18),3,4,5,6);
            memset(acStack_124,0x100,0);
            uVar3 = omTimerTickGet();
            snprintf(acStack_124,0x100,DAT_30081dd4,uVar3,*(undefined4 *)(DAT_30081654 + 0x10),
                     *(undefined4 *)(*DAT_30081830 + 0x18));
            update_record_file(acStack_124);
            uVar9 = 0x304;
          }
        }
      }
    }
    else if (uVar10 == 0x45) {
      if (*(int *)*DAT_30080a24 == 1) {
        OSAL_LogMsg(DAT_3008182c,1,2,3,4,5,6);
        uVar9 = uVar3;
      }
      else {
        *(undefined4 *)*DAT_30081830 = 0;
        ledFlush(1);
        uVar9 = 0x45;
      }
    }
    else if (uVar10 == 0x46) {
      if (*(int *)(DAT_30081654 + 0x10) == 1) {
        uVar9 = 0x46;
      }
    }
    else if (uVar10 == 0x4b) {
      if (*(int *)(DAT_30081654 + 0x10) == 1) {
        uVar9 = 0x4b;
      }
      else {
        OSAL_LogMsg(DAT_30081834,1,2,3,4,5,6);
        memset(acStack_124,0x100,0);
        uVar3 = omTimerTickGet();
        snprintf(acStack_124,0x100,DAT_30081944,uVar3);
        update_record_file(acStack_124);
        uVar9 = 0x4b;
      }
    }
    else {
      uVar9 = DAT_30081e70;
      if ((uVar10 == 0xfb) && (uVar9 = DAT_30080da0, *(int *)(DAT_30081654 + 0x10) == 1)) {
        uVar9 = 0xfb;
      }
    }
  }
  dloadUSBSendPro(uVar9);
  return 0;
}

/* ----------------------------------------------------------------
 * dloadUSBCallback @ 0x30081C80  (примерный размер ~180 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 4
 * Вызывает: ATCommandProcess, FUN_30080798, OSAL_LogMsg, Om_HdlcDecap
 * Вызывают: FUN_30075e48
 * Константы: 0x30081C80
 * Данные: DAT_30081e2c, DAT_30081e74
 * ---------------------------------------------------------------- */
undefined4 dloadUSBCallback(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ATCommandProcess(param_1,param_2);
  if (iVar1 == 2) {
    for (iVar1 = 0; iVar1 < (int)(param_2 & 0xffff); iVar1 = iVar1 + 1) {
      iVar2 = Om_HdlcDecap(DAT_30081e2c,*(undefined1 *)(param_1 + iVar1));
      if (iVar2 == 0) {
        FUN_30080798();
      }
      else if (iVar2 != 1) {
        OSAL_LogMsg(DAT_30081e74,iVar2,2,3,4,5,6);
      }
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * dloadSetMidwayRestart @ 0x300822F4  (примерный размер ~24 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 0
 * Вызывают: dloadDealBootrom
 * Константы: 0x300822F4
 * Данные: DAT_30083268
 * ---------------------------------------------------------------- */
void dloadSetMidwayRestart(undefined4 param_1)

{
  *DAT_30083268 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * dloadDealBootrom @ 0x3008230C  (примерный размер ~284 байт)
 * Модуль: dload | Вызывают: 2 | Вызывает: 8
 * Вызывает: BSP_DLOAD_Reset, OSAL_LogMsg, dloadSetMidwayRestart, memset, omTimerTickGet, ptable_get_table_changed, snprintf, update_record_file
 * Вызывают: ImageDloadToFlash, ImageDloadToRam
 * Константы: 0x3008230C
 * Данные: DAT_30082e78, DAT_3008326c, DAT_30083270, DAT_30083274, DAT_30083278
 * ---------------------------------------------------------------- */
void dloadDealBootrom(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char acStack_104 [260];
  
  iVar7 = 0x80;
  pcVar4 = acStack_104;
  pcVar6 = DAT_3008326c;
  do {
    pcVar5 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 2;
    cVar2 = *pcVar5;
    iVar7 = iVar7 + -1;
    pcVar5 = pcVar4 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 2;
    *pcVar5 = cVar2;
  } while (iVar7 != 0);
  iVar7 = ptable_get_table_changed(cVar1,cVar2,acStack_104);
  if (iVar7 == 0) {
    OSAL_LogMsg(DAT_30083274,1,2,3,4,5,6);
    memset(acStack_104,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_104,0x100,DAT_30083278,uVar3);
    update_record_file(acStack_104);
  }
  else {
    memset(acStack_104,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_104,0x100,DAT_30083270,uVar3);
    update_record_file(acStack_104);
    dloadSetMidwayRestart(1);
    if (*(int *)*DAT_30082e78 != 0) {
      BSP_DLOAD_Reset();
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * dloadNeedMidwayRestart @ 0x30084D60  (примерный размер ~12 байт)
 * Модуль: dload | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30080798, dloadBootromEnd
 * Константы: 0x30084D60
 * Данные: DAT_300857ec
 * ---------------------------------------------------------------- */
undefined4 dloadNeedMidwayRestart(void)

{
  return *DAT_300857ec;
}

/* ----------------------------------------------------------------
 * dloadInitImageBufferType @ 0x30084D6C  (примерный размер ~192 байт)
 * Модуль: dload | Вызывают: 1 | Вызывает: 1
 * Вызывает: OSAL_LogMsg
 * Вызывают: dloadInitRamBuffer
 * Константы: 0x30084D6C
 * Данные: DAT_300857f0, DAT_300857f4
 * ---------------------------------------------------------------- */
undefined4 dloadInitImageBufferType(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x65) {
    uVar1 = 1;
  }
  else if (param_1 == 0x66) {
    uVar1 = 1;
  }
  else if (param_1 == 0x10c) {
    if (*DAT_300857f0 == 1) {
      OSAL_LogMsg(DAT_300857f4,1,2,3,4,5,6);
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
    if (*DAT_300857f0 == 1) {
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * dloadInitRamBuffer @ 0x30084E2C  (примерный размер ~1024 байт)
 * Модуль: dload | Вызывают: 3 | Вызывает: 9
 * Вызывает: OSAL_LogMsg, __udiv32, dloadInitImageBufferType, free, malloc, memset, omTimerTickGet, snprintf, update_record_file
 * Вызывают: FUN_30080798, dloadFromFsMainThread, dloadTFPro
 * Константы: 0xFFFFFFFF, 0x30084E2C, 0x00200000
 * Данные: DAT_30085178, DAT_300857d0, DAT_300857f8, DAT_300857fc, DAT_30085800, DAT_30085804, DAT_30085808, DAT_3008580c
 * ---------------------------------------------------------------- */
undefined4 dloadInitRamBuffer(int param_1,size_t param_2)

{
  char cVar1;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  size_t __size;
  int iVar8;
  char acStack_11c [256];
  
  iVar8 = 0x80;
  pcVar5 = acStack_11c;
  pcVar7 = DAT_300857f8;
  do {
    pcVar6 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 2;
    cVar2 = *pcVar6;
    iVar8 = iVar8 + -1;
    pcVar6 = pcVar5 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 2;
    *pcVar6 = cVar2;
  } while (iVar8 != 0);
  iVar8 = dloadInitImageBufferType(param_1,cVar2,acStack_11c);
  *DAT_300857d0 = (char)iVar8;
  if (iVar8 == 0) {
    OSAL_LogMsg(DAT_300857fc,param_1,param_2,3,4,5,6);
    memset(acStack_11c,0x100,0);
    uVar4 = omTimerTickGet();
    snprintf(acStack_11c,0x100,DAT_30085800,uVar4,param_1,param_2);
    update_record_file(acStack_11c);
    iVar8 = __udiv32(0x200000,*DAT_30085804);
    __size = (*DAT_30085804 + *DAT_30085808) * iVar8;
    if (*DAT_30085178 != 0) {
      free((void *)*DAT_30085178);
      *DAT_30085178 = 0;
    }
    if (*DAT_3008580c != 0) {
      free((void *)*DAT_3008580c);
      *DAT_3008580c = 0;
    }
    if (*DAT_30085178 == 0) {
      pvVar3 = malloc(__size);
      *DAT_30085178 = (int)pvVar3;
      if (*DAT_30085178 == 0) {
        free((void *)*DAT_30085810);
        *DAT_30085810 = 0;
        OSAL_LogMsg(DAT_30085814,1,2,3,4,5,6);
        memset(acStack_11c,0x100,0);
        uVar4 = omTimerTickGet();
        snprintf(acStack_11c,0x100,DAT_30085818,uVar4);
        update_record_file(acStack_11c);
        return 0xffffffff;
      }
    }
    DAT_30085178[2] = __size;
    DAT_30085178[1] = 0;
    memset((void *)*DAT_30085178,0,__size);
    *DAT_3008581c = __size;
  }
  else {
    if (iVar8 != 1) {
      return 0xffffffff;
    }
    OSAL_LogMsg(DAT_30085820,param_1,param_2,3,4,5,6);
    if (*DAT_3008580c != 0) {
      free((void *)*DAT_3008580c);
      *DAT_3008580c = 0;
    }
    if (*DAT_30085178 != 0) {
      free((void *)*DAT_30085178);
      *DAT_30085178 = 0;
    }
    pvVar3 = malloc(param_2);
    *DAT_3008580c = (int)pvVar3;
    if (*DAT_3008580c == 0) {
      OSAL_LogMsg(DAT_30085824,0,0,0,0,0,0);
      memset(acStack_11c,0x100,0);
      uVar4 = omTimerTickGet();
      snprintf(acStack_11c,0x100,DAT_30085828,uVar4);
      update_record_file(acStack_11c);
      return 0xffffffff;
    }
    memset((void *)*DAT_3008580c,0,param_2);
    DAT_3008580c[1] = 0;
    DAT_3008580c[2] = param_1;
    DAT_3008580c[3] = param_2;
    DAT_3008580c[5] = 1;
    *DAT_3008581c = param_2;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * dloadRecord @ 0x30085578  (примерный размер ~784 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 7
 * Вызывает: OSAL_LogMsg, exchLogPrintf, fclose, fopen, ftell, remove, tickGet
 * Константы: 0x30085578
 * Данные: DAT_3008585c, DAT_30085860, DAT_30085864, DAT_30085868, DAT_3008586c, DAT_30085870, DAT_30085874, DAT_30085878
 * ---------------------------------------------------------------- */
void dloadRecord(int param_1,undefined2 param_2)

{
  undefined4 uVar1;
  FILE *__stream;
  long lVar2;
  int iVar3;
  
  uVar1 = tickGet();
  __stream = fopen(DAT_3008585c,DAT_30085860);
  if (__stream == (FILE *)0x0) {
    OSAL_LogMsg(DAT_30085864,1,2,3,4,5,6);
  }
  else {
    lVar2 = ftell(__stream);
    if (lVar2 == -1) {
      OSAL_LogMsg(DAT_30085868,1,2,3,4,5,6);
      fclose(__stream);
    }
    else {
      OSAL_LogMsg(DAT_3008586c,lVar2,2,3,4,5,6);
      if (0x3ffff < lVar2) {
        OSAL_LogMsg(DAT_30085870,1,2,3,4,5,6);
        fclose(__stream);
        iVar3 = remove(DAT_3008585c);
        if (iVar3 != 0) {
          OSAL_LogMsg(DAT_30085874,1,2,3,4,5,6);
          return;
        }
        __stream = fopen(DAT_3008585c,DAT_30085860);
        if (__stream == (FILE *)0x0) {
          OSAL_LogMsg(DAT_30085864,1,2,3,4,5,6);
          return;
        }
      }
      if (param_1 == 1) {
        exchLogPrintf(__stream,DAT_30085878,uVar1);
      }
      else if (param_1 == 0) {
        exchLogPrintf(__stream,DAT_3008587c,uVar1);
      }
      else if (param_1 == 3) {
        exchLogPrintf(__stream,DAT_30085880,uVar1,param_2);
      }
      else if (param_1 == 2) {
        exchLogPrintf(__stream,DAT_30085884,uVar1,param_2);
      }
      fclose(__stream);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * upgradeAllow @ 0x30085E1C  (примерный размер ~120 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 3
 * Вызывает: OSAL_LogMsg, imgIdioCheck, imgUpgradeAllow
 * Константы: 0x30085E1C
 * Данные: DAT_30085ee8
 * ---------------------------------------------------------------- */
undefined4 upgradeAllow(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = imgIdioCheck(param_1,param_2,param_3);
  if (iVar1 == -1) {
    OSAL_LogMsg(DAT_30085ee8,0,0,0,0,0,0);
    uVar2 = 3;
  }
  else {
    uVar2 = imgUpgradeAllow(iVar1);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * atBuildResult @ 0x3009A264  (примерный размер ~252 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A264
 * ---------------------------------------------------------------- */
undefined4 atBuildResult(undefined1 *param_1,char *param_2,char *param_3,uint param_4)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (param_1 == (undefined1 *)0x0) {
    return 2;
  }
  if ((param_2 == (char *)0x0) && (param_3 == (char *)0x0)) {
    return 2;
  }
  *param_1 = 0xd;
  param_1[1] = 10;
  pcVar2 = param_1 + 2;
  if (param_2 != (char *)0x0) {
    cVar1 = *param_2;
    while (cVar1 != '\0') {
      *pcVar2 = *param_2;
      param_2 = param_2 + 1;
      pcVar2 = pcVar2 + 1;
      cVar1 = *param_2;
    }
  }
  if ((param_3 != (char *)0x0) && (param_4 != 0)) {
    pcVar3 = param_3 + -1;
    if ((param_4 & 1) != 0) {
      param_4 = param_4 - 1;
      *pcVar2 = *param_3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = param_3;
      if (param_4 == 0) goto LAB_3009a340;
    }
    param_4 = param_4 >> 1;
    do {
      param_4 = param_4 - 1;
      *pcVar2 = pcVar3[1];
      pcVar3 = pcVar3 + 2;
      pcVar2[1] = *pcVar3;
      pcVar2 = pcVar2 + 2;
    } while (param_4 != 0);
  }
LAB_3009a340:
  *pcVar2 = '\r';
  pcVar2[1] = '\n';
  return 0;
}

/* ----------------------------------------------------------------
 * atBuildOK @ 0x3009A360  (примерный размер ~88 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A360
 * ---------------------------------------------------------------- */
undefined4 atBuildOK(undefined1 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 2;
  }
  else {
    *param_1 = 0xd;
    param_1[1] = 10;
    param_1[2] = 0x4f;
    param_1[3] = 0x4b;
    param_1[4] = 0xd;
    param_1[5] = 10;
    param_1[6] = 0;
    *param_2 = 6;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * atBuildERROR @ 0x3009A3B8  (примерный размер ~104 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A3B8
 * ---------------------------------------------------------------- */
undefined4 atBuildERROR(undefined1 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 2;
  }
  else {
    *param_1 = 0xd;
    param_1[1] = 10;
    param_1[2] = 0x45;
    param_1[3] = 0x52;
    param_1[4] = 0x52;
    param_1[5] = 0x4f;
    param_1[6] = 0x52;
    param_1[7] = 0xd;
    param_1[8] = 10;
    param_1[9] = 0;
    *param_2 = 9;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * atSendOK2PC @ 0x3009A420  (примерный размер ~204 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A420
 * Данные: DAT_3009b3b4, DAT_3009b3b8, DAT_3009b3bc, DAT_3009b3c0, DAT_3009b3c4
 * ---------------------------------------------------------------- */
int atSendOK2PC(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_14;
  
  local_14 = 0;
  uVar1 = (*DAT_3009b3b4)(0x820);
  if (uVar1 == 0) {
    iVar2 = 4;
  }
  else {
    (*DAT_3009b3b8)(uVar1,0,0x820);
    iVar3 = uVar1 + (0x20 - (uVar1 & 0x1f));
    iVar2 = (*DAT_3009b3bc)(iVar3,&local_14);
    if (iVar2 == 0) {
      iVar2 = (*DAT_3009b3c4)(iVar3,local_14);
      (*DAT_3009b3c0)(uVar1);
      if (iVar2 == -1) {
        iVar2 = 3;
      }
      else {
        iVar2 = 0;
      }
    }
    else {
      (*DAT_3009b3c0)(iVar3);
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * atSendERR2PC @ 0x3009A4EC  (примерный размер ~156 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A4EC
 * Данные: DAT_3009b3b4, DAT_3009b3b8, DAT_3009b3c0, DAT_3009b3c4, DAT_3009b418
 * ---------------------------------------------------------------- */
void atSendERR2PC(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_10;
  
  local_10 = 0;
  uVar1 = (*DAT_3009b3b4)(0x820);
  if (uVar1 != 0) {
    (*DAT_3009b3b8)(uVar1,0,0x820);
    uVar3 = uVar1 + (0x20 - (uVar1 & 0x1f));
    iVar2 = (*DAT_3009b418)(uVar3,&local_10);
    if (iVar2 == 0) {
      (*DAT_3009b3c4)(uVar3,local_10);
      uVar3 = uVar1;
    }
    (*DAT_3009b3c0)(uVar3);
  }
  return;
}

/* ----------------------------------------------------------------
 * atQryBootRomVerBr @ 0x3009A588  (примерный размер ~416 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A588, 0xFFFFFFFF
 * Данные: DAT_3009b3b4, DAT_3009b3b8, DAT_3009b3bc, DAT_3009b3c0, DAT_3009b3c4, DAT_3009b41c, DAT_3009b420
 * ---------------------------------------------------------------- */
undefined4 atQryBootRomVerBr(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_1c;
  
  local_1c = 0;
  iVar1 = (*DAT_3009b3b4)(0x400);
  if (iVar1 == 0) {
    uVar2 = 4;
  }
  else {
    (*DAT_3009b3b8)(iVar1,0,0x400);
    uVar3 = (*DAT_3009b41c)(iVar1,0x400);
    if ((uVar3 == 0xffffffff) || (0x1e < uVar3)) {
      (*DAT_3009b3c0)(iVar1);
      uVar2 = 1;
    }
    else {
      if (*(char *)(iVar1 + uVar3 + -1) == '\0') {
        uVar3 = uVar3 - 1;
      }
      uVar4 = (*DAT_3009b3b4)(0x820);
      if (uVar4 == 0) {
        uVar2 = 4;
      }
      else {
        (*DAT_3009b3b8)(uVar4,0,0x820);
        iVar6 = uVar4 + (0x20 - (uVar4 & 0x1f));
        iVar5 = (*DAT_3009b420)(iVar6,0,iVar1,uVar3);
        if (iVar5 == 0) {
          (*DAT_3009b3bc)(iVar6 + uVar3 + 4,&local_1c);
          iVar5 = uVar3 + 4 + local_1c;
          (*DAT_3009b3c0)(iVar1);
          iVar1 = (*DAT_3009b3c4)(iVar6,iVar5);
          (*DAT_3009b3c0)(uVar4);
          if (iVar1 == -1) {
            uVar2 = 3;
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          (*DAT_3009b3c0)(uVar4);
          (*DAT_3009b3c0)(iVar1);
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * atQryDLoadVerBr @ 0x3009A728  (примерный размер ~396 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A728, 0xFFFFFFFF
 * Данные: DAT_3009b3b4, DAT_3009b3b8, DAT_3009b3bc, DAT_3009b3c0, DAT_3009b3c4, DAT_3009b420, DAT_3009b424
 * ---------------------------------------------------------------- */
undefined4 atQryDLoadVerBr(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_1c;
  
  local_1c = 0;
  iVar1 = (*DAT_3009b3b4)(0x400);
  if (iVar1 == 0) {
    uVar2 = 4;
  }
  else {
    (*DAT_3009b3b8)(iVar1,0,0x400);
    uVar3 = (*DAT_3009b424)(iVar1,0x400);
    if ((uVar3 == 0xffffffff) || (0x1e < uVar3)) {
      (*DAT_3009b3c0)(iVar1);
      uVar2 = 1;
    }
    else {
      uVar4 = (*DAT_3009b3b4)(0x820);
      if (uVar4 == 0) {
        uVar2 = 4;
      }
      else {
        (*DAT_3009b3b8)(uVar4,0,0x820);
        iVar6 = uVar4 + (0x20 - (uVar4 & 0x1f));
        iVar5 = (*DAT_3009b420)(iVar6,0,iVar1,uVar3);
        if (iVar5 == 0) {
          (*DAT_3009b3bc)(iVar6 + uVar3 + 4,&local_1c);
          iVar5 = uVar3 + 4 + local_1c;
          (*DAT_3009b3c0)(iVar1);
          iVar1 = (*DAT_3009b3c4)(iVar6,iVar5);
          (*DAT_3009b3c0)(uVar4);
          if (iVar1 == -1) {
            uVar2 = 3;
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          (*DAT_3009b3c0)(uVar4);
          (*DAT_3009b3c0)(iVar1);
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * atQryDLoadInfoBr @ 0x3009A8B4  (примерный размер ~780 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x3009A8B4
 * Данные: DAT_3009b3b4, DAT_3009b3b8, DAT_3009b3bc, DAT_3009b3c0, DAT_3009b3c4, DAT_3009b420, DAT_3009b428, DAT_3009b42c
 * ---------------------------------------------------------------- */
undefined4 atQryDLoadInfoBr(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char local_28 [4];
  int local_24;
  
  local_24 = 0;
  local_28[0] = '\0';
  iVar1 = (*DAT_3009b3b4)(0x400);
  if (iVar1 == 0) {
    uVar2 = 4;
  }
  else {
    (*DAT_3009b3b8)(iVar1,0,0x400);
    uVar3 = (*DAT_3009b3b4)(0x820);
    if (uVar3 == 0) {
      uVar2 = 4;
    }
    else {
      (*DAT_3009b3b8)(uVar3,0,0x820);
      iVar9 = uVar3 + (0x20 - (uVar3 & 0x1f));
      uVar4 = (*DAT_3009b428)(iVar1,0x400);
      if ((uVar4 == 0xffffffff) || (0x1e < uVar4)) {
        (*DAT_3009b3c0)(iVar1);
        (*DAT_3009b3c0)(uVar3);
        uVar2 = 1;
      }
      else {
        (*DAT_3009b420)(iVar9,DAT_3009b42c,iVar1,uVar4);
        iVar8 = iVar9 + uVar4 + 10;
        (*DAT_3009b3b8)(iVar1,0,0x400);
        uVar5 = (*DAT_3009b430)(iVar1,0x400);
        if ((uVar5 == 0xffffffff) || (100 < uVar5)) {
          (*DAT_3009b3c0)(iVar1);
          (*DAT_3009b3c0)(uVar3);
          uVar2 = 1;
        }
        else {
          (*DAT_3009b420)(iVar8,DAT_3009b434,iVar1,uVar5);
          iVar8 = iVar8 + uVar5 + 0xb;
          (*DAT_3009b3b8)(iVar1,0,0x400);
          uVar6 = (*DAT_3009b438)(iVar1,0x400);
          if ((uVar6 == 0xffffffff) || (0x1e < uVar6)) {
            (*DAT_3009b3c0)(iVar1);
            (*DAT_3009b3c0)(uVar3);
            uVar2 = 1;
          }
          else {
            (*DAT_3009b420)(iVar8,DAT_3009b43c,iVar1,uVar6);
            iVar8 = iVar8 + uVar6;
            iVar7 = (*DAT_3009b440)();
            if ((iVar7 == 0) || (iVar7 == 1)) {
              local_28[0] = (char)iVar7 + '0';
              (*DAT_3009b420)(iVar8 + 0x11,DAT_3009b444,local_28,1);
              (*DAT_3009b3bc)(iVar8 + 0x21,&local_24);
              iVar8 = uVar4 + uVar5 + uVar6 + 0x36 + local_24;
              (*DAT_3009b3c0)(iVar1);
              iVar1 = (*DAT_3009b3c4)(iVar9,iVar8);
              (*DAT_3009b3c0)(uVar3);
              if (iVar1 == -1) {
                uVar2 = 3;
              }
              else {
                uVar2 = 0;
              }
            }
            else {
              (*DAT_3009b3c0)(iVar1);
              (*DAT_3009b3c0)(uVar3);
              uVar2 = 1;
            }
          }
        }
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * atQryAuthorityVerBr @ 0x3009ABC0  (примерный размер ~408 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009ABC0, 0xFFFFFFFF
 * Данные: DAT_3009b3b4, DAT_3009b3b8, DAT_3009b3bc, DAT_3009b3c0, DAT_3009b3c4, DAT_3009b420, DAT_3009b448
 * ---------------------------------------------------------------- */
undefined4 atQryAuthorityVerBr(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_1c;
  
  local_1c = 0;
  iVar1 = (*DAT_3009b3b4)(0x400);
  if (iVar1 == 0) {
    uVar2 = 4;
  }
  else {
    (*DAT_3009b3b8)(iVar1,0,0x400);
    uVar3 = (*DAT_3009b3b4)(0x820);
    if (uVar3 == 0) {
      uVar2 = 4;
    }
    else {
      (*DAT_3009b3b8)(uVar3,0,0x820);
      iVar6 = uVar3 + (0x20 - (uVar3 & 0x1f));
      uVar4 = (*DAT_3009b448)(iVar1,0x400);
      if ((uVar4 == 0xffffffff) || (0x1e < uVar4)) {
        (*DAT_3009b3c0)(uVar3);
        (*DAT_3009b3c0)(iVar1);
        uVar2 = 1;
      }
      else {
        iVar5 = (*DAT_3009b420)(iVar6,0,iVar1,uVar4);
        if (iVar5 == 0) {
          (*DAT_3009b3bc)(iVar6 + uVar4 + 4,&local_1c);
          iVar5 = uVar4 + 4 + local_1c;
          (*DAT_3009b3c0)(iVar1);
          iVar1 = (*DAT_3009b3c4)(iVar6,iVar5);
          (*DAT_3009b3c0)(uVar3);
          if (iVar1 == -1) {
            uVar2 = 3;
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          (*DAT_3009b3c0)(iVar1);
          (*DAT_3009b3c0)(uVar3);
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * atQryAuthorityIDBr @ 0x3009AD58  (примерный размер ~464 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009AD58, 0xFFFFFFFF
 * Данные: DAT_3009b3b4, DAT_3009b3b8, DAT_3009b3bc, DAT_3009b3c0, DAT_3009b3c4, DAT_3009b420, DAT_3009b44c, DAT_3009b450
 * ---------------------------------------------------------------- */
undefined4 atQryAuthorityIDBr(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char local_20 [4];
  int local_1c;
  
  local_1c = 0;
  local_20[0] = '\0';
  iVar2 = (*DAT_3009b3b4)(0x400);
  if (iVar2 == 0) {
    uVar3 = 4;
  }
  else {
    (*DAT_3009b3b8)(iVar2,0,0x400);
    uVar4 = (*DAT_3009b3b4)(0x820);
    if (uVar4 == 0) {
      uVar3 = 4;
    }
    else {
      (*DAT_3009b3b8)(uVar4,0,0x820);
      iVar6 = uVar4 + (0x20 - (uVar4 & 0x1f));
      uVar5 = (*DAT_3009b44c)(iVar2,0x400);
      if ((uVar5 == 0xffffffff) || (0x1e < uVar5)) {
        (*DAT_3009b3c0)(iVar2);
        (*DAT_3009b3c0)(uVar4);
        uVar3 = 1;
      }
      else {
        *(undefined1 *)(iVar2 + uVar5) = 0x2c;
        ((undefined1 *)(iVar2 + uVar5))[1] = 0;
        cVar1 = (*DAT_3009b450)();
        if ((cVar1 == '\0') || (cVar1 == '\x01')) {
          local_20[0] = cVar1 + '0';
          (*DAT_3009b420)(iVar6,iVar2,local_20,1);
          (*DAT_3009b3bc)(iVar6 + uVar5 + 6,&local_1c);
          iVar7 = uVar5 + local_1c;
          (*DAT_3009b3c0)(iVar2);
          iVar2 = (*DAT_3009b3c4)(iVar6,iVar7 + 6);
          (*DAT_3009b3c0)(uVar4);
          if (iVar2 == -1) {
            uVar3 = 3;
          }
          else {
            uVar3 = 0;
          }
        }
        else {
          (*DAT_3009b3c0)(iVar2);
          (*DAT_3009b3c0)(uVar4);
          uVar3 = 1;
        }
      }
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * atSetDataModeBr @ 0x3009AF28  (примерный размер ~48 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009AF28
 * Данные: DAT_3009b454, DAT_3009b458
 * ---------------------------------------------------------------- */
undefined4 atSetDataModeBr(void)

{
  int iVar1;
  undefined4 uVar2;
  
  (*DAT_3009b454)(2);
  iVar1 = (*DAT_3009b458)();
  if (iVar1 == -1) {
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * atTestOK @ 0x3009AF58  (примерный размер ~28 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009AF58
 * Данные: DAT_3009b458
 * ---------------------------------------------------------------- */
int atTestOK(void)

{
  int iVar1;
  
  iVar1 = (*DAT_3009b458)();
  if (iVar1 == -1) {
    iVar1 = 3;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * atGetSdmBr @ 0x3009AF74  (примерный размер ~8 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009AF74
 * ---------------------------------------------------------------- */
undefined4 atGetSdmBr(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * atCheckStr @ 0x3009AF7C  (примерный размер ~404 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009AF7C
 * ---------------------------------------------------------------- */
undefined1 atCheckStr(byte *param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  
  iVar2 = 0;
  if (param_1 == (byte *)0x0) {
    uVar4 = 2;
  }
  else if ((*param_1 == 0x61) || (*param_1 == 0x41)) {
    if ((param_1[1] == 0x74) || (param_1[1] == 0x54)) {
      bVar1 = param_1[2];
      if (((((bVar1 == 0x2b) || (bVar1 == 0x5e)) || (bVar1 == 0x20)) ||
          ((bVar1 == 0xd || (bVar1 == 10)))) || ((bVar1 == 0x45 || (bVar1 == 0x65)))) {
        do {
          while( true ) {
            uVar3 = (uint)*param_1;
            while (uVar3 - 0x61 < 0x1a) {
              param_1 = param_1 + 1;
              uVar3 = (uint)*param_1;
              iVar2 = iVar2 + 1;
              if (uVar3 == 0xd) goto LAB_3009b0ec;
            }
            uVar3 = (uint)*param_1;
            if (0x19 < uVar3 - 0x41) break;
            bVar1 = param_1[1];
joined_r0x3009b0c4:
            iVar2 = iVar2 + 1;
            param_1 = param_1 + 1;
            if (bVar1 == 0xd) goto LAB_3009b0ec;
          }
          if (((uVar3 == 0x5e) || (uVar3 == 0x3f)) ||
             ((uVar3 == 0x3d || ((uVar3 == 0x2b || (uVar3 == 0x24)))))) {
            bVar1 = param_1[1];
            goto joined_r0x3009b0c4;
          }
          if (9 < uVar3 - 0x30) break;
          param_1 = param_1 + 1;
          iVar2 = iVar2 + 1;
        } while (*param_1 != 0xd);
LAB_3009b0ec:
        uVar4 = iVar2 == 0x40;
        *param_2 = iVar2;
      }
      else {
        uVar4 = 2;
      }
    }
    else {
      uVar4 = 2;
    }
  }
  else {
    uVar4 = 2;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * atProcUpString @ 0x3009B110  (примерный размер ~120 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B110
 * ---------------------------------------------------------------- */
undefined4 atProcUpString(byte *param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 == 0 || param_1 == (byte *)0x0) {
    uVar1 = 2;
  }
  else if (param_2 < 0x41) {
    if (param_2 != 0) {
      do {
        uVar2 = uVar2 + 1;
        if (*param_1 - 0x61 < 0x1a) {
          *param_1 = *param_1 - 0x20;
        }
        param_1 = param_1 + 1;
      } while ((uVar2 & 0xffff) < param_2);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * atFormatStr @ 0x3009B188  (примерный размер ~84 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B188
 * Данные: DAT_3009b45c
 * ---------------------------------------------------------------- */
undefined4 atFormatStr(byte *param_1,int param_2)

{
  undefined4 uVar1;
  byte bVar2;
  short sVar3;
  
  sVar3 = 0;
  if (param_1 == (byte *)0x0) {
    uVar1 = 2;
  }
  else {
    if (param_2 != 0) {
      bVar2 = *param_1;
      do {
        bVar2 = bVar2 & 0x7f;
        sVar3 = sVar3 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      *param_1 = bVar2;
    }
    uVar1 = (*DAT_3009b45c)(param_1,sVar3);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * atCmpATStr @ 0x3009B1DC  (примерный размер ~88 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B1DC
 * ---------------------------------------------------------------- */
undefined4 atCmpATStr(int param_1,int param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    pcVar1 = (char *)(param_1 + -1);
    pcVar2 = (char *)(param_2 + -1);
    do {
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
      if (*pcVar1 != *pcVar2) {
        return 1;
      }
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    return 0;
  }
  return 2;
}

/* ----------------------------------------------------------------
 * atFindFunc @ 0x3009B234  (примерный размер ~180 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B234
 * Данные: DAT_3009b460, DAT_3009b464
 * ---------------------------------------------------------------- */
undefined4 atFindFunc(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if ((param_2 < 0x401) && (puVar3 = DAT_3009b460, param_1 != 0)) {
    do {
      uVar4 = 0;
      pcVar5 = (char *)puVar3[1];
      if (pcVar5 == (char *)0x0) {
        return 0;
      }
      cVar1 = *pcVar5;
      pcVar6 = pcVar5;
      while (cVar1 != '\0') {
        pcVar6 = pcVar6 + 1;
        uVar4 = uVar4 + 1;
        cVar1 = *pcVar6;
      }
      if ((uVar4 == param_2) &&
         (iVar2 = (*DAT_3009b464)(pcVar5,param_1,param_2), pcVar6 = pcVar5, iVar2 == 0)) {
        return *puVar3;
      }
      puVar3 = puVar3 + 3;
    } while (pcVar6 != (char *)0x0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * atInitTask @ 0x3009B400  (примерный размер ~128 байт)
 * Модуль: dload | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B400
 * Данные: DAT_3009b478, DAT_3009b47c
 * ---------------------------------------------------------------- */
void atInitTask(void)

{
  (*DAT_3009b478)(DAT_3009b47c);
  return;
}

