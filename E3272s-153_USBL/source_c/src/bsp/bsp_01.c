/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : bsp — BSP Huawei: GPIO, HKADC, PMU HI6451, WDT, LED, SPI/SSI, таймеры, питание
 * Часть  : 1 (функций: 150, адреса 0x3000465C..0x3000C600)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * ABB_UnReset @ 0x3000465C  (примерный размер ~88 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0xFFFFFFFE, 0x3000465C
 * Данные: DAT_30005088, DAT_3000508c
 * ---------------------------------------------------------------- */
undefined4 ABB_UnReset(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *DAT_30005088;
  *DAT_30005088 = uVar2 & 0xfffffffe;
  for (iVar1 = DAT_3000508c; -1 < iVar1; iVar1 = iVar1 + -1) {
  }
  *DAT_30005088 = uVar2 & 0xfffffffe | 1 | *DAT_30005088;
  return param_1;
}

/* ----------------------------------------------------------------
 * BSP_LDScript @ 0x300046B4  (примерный размер ~184 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 7
 * Вызывает: close, open, printf, shellGenericInit, sysClkRateGet, taskDelay, taskNameToId
 * Константы: 0x300046B4
 * Данные: DAT_30005090, DAT_30005094, DAT_30005098, DAT_3000509c
 * ---------------------------------------------------------------- */
void BSP_LDScript(void)

{
  bool bVar1;
  int __fd;
  int iVar2;
  int iVar3;
  undefined4 local_14;
  
  local_14 = DAT_30005090;
  __fd = open(DAT_30005094,0,0);
  if (-1 < __fd) {
    iVar2 = shellGenericInit(DAT_30005098,0,0,&local_14,0,0,__fd,1,2);
    iVar3 = 10;
    if (iVar2 == 0) {
      do {
        sysClkRateGet();
        taskDelay();
        iVar2 = taskNameToId(local_14);
        if (iVar2 == -1) break;
        bVar1 = 0 < iVar3;
        iVar3 = iVar3 + -1;
      } while (bVar1);
      close(__fd);
    }
    else {
      printf(DAT_3000509c);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_OsWait @ 0x3000476C  (примерный размер ~364 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: bzero, printf, read, select
 * Вызывают: usrAppInit
 * Константы: 0x3000476C, 0xFFFFFFFF
 * Данные: DAT_300050a0, DAT_300050a4, DAT_300050a8, DAT_300050ac
 * ---------------------------------------------------------------- */
undefined4 BSP_OsWait(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  ssize_t sVar3;
  uint uVar4;
  int iVar5;
  char local_124 [4];
  timeval local_120;
  fd_set local_118 [2];
  
  uVar4 = 0;
  if (param_1 < 1) {
    printf(DAT_300050a0);
    uVar1 = 0;
  }
  else {
    bzero(local_118,0x100);
    local_118[0].fds_bits[0] = local_118[0].fds_bits[0] | 1;
    printf(DAT_300050a4,param_1);
    for (iVar5 = 0; iVar5 < param_1; iVar5 = iVar5 + 1) {
      local_120.tv_sec = 1;
      local_120.tv_usec = 0;
      bzero(local_118,0x100);
      local_118[0].fds_bits[0] = local_118[0].fds_bits[0] | 1;
      iVar2 = select(1,local_118,(fd_set *)0x0,(fd_set *)0x0,&local_120);
      if (iVar2 == -1) break;
      if (iVar2 == 0) {
        printf(DAT_300050a8,(param_1 - iVar5) + -1);
      }
      else {
        sVar3 = read(1,local_124,1);
        if (0 < sVar3) {
          if (local_124[0] == '\n') {
            uVar4 = uVar4 + 1;
            if (2 < uVar4) {
              return 0;
            }
          }
          else {
            uVar4 = 0;
          }
        }
      }
    }
    printf(DAT_300050ac);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_USB_RegEnumDoneForMsp @ 0x300048E0  (примерный размер ~64 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: intCpuLock, intCpuUnlock
 * Константы: 0x300048E0
 * Данные: DAT_300050b4, DAT_300050b8
 * ---------------------------------------------------------------- */
bool BSP_USB_RegEnumDoneForMsp(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = intCpuLock();
  *DAT_300050b4 = param_1;
  intCpuUnlock(uVar1);
  return *DAT_300050b8 != 0;
}

/* ----------------------------------------------------------------
 * BSP_USB_RegEnumDoneForPs @ 0x30004920  (примерный размер ~64 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: intCpuLock, intCpuUnlock
 * Константы: 0x30004920
 * Данные: DAT_300050b8, DAT_300050bc
 * ---------------------------------------------------------------- */
bool BSP_USB_RegEnumDoneForPs(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = intCpuLock();
  *DAT_300050bc = param_1;
  intCpuUnlock(uVar1);
  return *DAT_300050b8 != 0;
}

/* ----------------------------------------------------------------
 * BSP_PromptSet @ 0x30004B34  (примерный размер ~84 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: shellFirst, shellInterpPromptSet, shellNext, taskNameToId
 * Вызывают: usrAppInit
 * Константы: 0x30004B34
 * Данные: DAT_300050ec, DAT_300050f0, DAT_300050f4
 * ---------------------------------------------------------------- */
void BSP_PromptSet(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = taskNameToId(DAT_300050ec);
  for (iVar2 = shellFirst(); (iVar2 != 0 && (*(int *)(iVar2 + 0x424) != iVar1));
      iVar2 = shellNext(iVar2)) {
  }
  shellInterpPromptSet(iVar2,DAT_300050f0,DAT_300050f4);
  return;
}

/* ----------------------------------------------------------------
 * BSP_DRV_BOOTROM_Init @ 0x30004B88  (примерный размер ~1168 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 28
 * Вызывает: ABB_SetBandGapOn, ABB_UnReset, BSP_GPIO_Init, BSP_MEM_Init, BSP_PMU_BoardInit, BSP_PMU_Init, BSP_ProductInfoInit, BSP_TLED_LedInit, BSP_WDT_Feed_Force, BSP_WDT_Resume, BSP_WDT_Stop, SPI_Init, SSI_Init, TFUP_CheckInit
 *           ...
 * Вызывают: usrAppInit
 * Константы: 0x30004B88
 * Данные: DAT_300050b8, DAT_300050f8, DAT_300050fc, DAT_30005100, DAT_30005104, DAT_30005108, DAT_3000510c, DAT_30005110
 * ---------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BSP_DRV_BOOTROM_Init(void)

{
  int iVar1;
  undefined4 uVar2;
  
  BSP_WDT_Feed_Force();
  iVar1 = secInit();
  if (iVar1 != 0) {
    logMsg(DAT_300050f8,iVar1,0,0,0,0,0);
  }
  BSP_GPIO_Init();
  iVar1 = SPI_Init();
  if (iVar1 != 0) {
    logMsg(DAT_300050fc,iVar1,0,0,0,0,0);
  }
  iVar1 = BSP_PMU_Init();
  if (iVar1 != 0) {
    logMsg(DAT_30005100,iVar1,0,0,0,0,0);
  }
  taskDelay(10);
  ABB_UnReset();
  iVar1 = SSI_Init();
  if (iVar1 != 0) {
    logMsg(DAT_30005104,iVar1,0,0,0,0,0);
  }
  iVar1 = hkadcInit();
  if (iVar1 != 0) {
    logMsg(DAT_30005108,iVar1,0,0,0,0,0);
  }
  uVar2 = ABB_SetBandGapOn();
  for (iVar1 = DAT_3000510c; -1 < iVar1; iVar1 = iVar1 + -1) {
  }
  iVar1 = BSP_ProductInfoInit(uVar2);
  if (iVar1 != 0) {
    logMsg(DAT_30005110,iVar1,0,0,0,0,0);
  }
  iVar1 = BSP_MEM_Init();
  if (iVar1 != 0) {
    logMsg(DAT_30005114,iVar1,0,0,0,0,0);
  }
  iVar1 = nand_init();
  if (iVar1 != 0) {
    logMsg(DAT_30005118,iVar1,0,0,0,0,0);
  }
  if (_DAT_2ffffffc != DAT_3000511c) {
    nand_erase_all();
  }
  BSP_WDT_Feed_Force();
  BSP_WDT_Stop();
  iVar1 = yaffsInit();
  if (iVar1 != 0) {
    logMsg(DAT_30005120,iVar1,0,0,0,0,0);
  }
  BSP_WDT_Resume();
  BSP_WDT_Feed_Force();
  BSP_PMU_BoardInit();
  iVar1 = BSP_TLED_LedInit();
  if (iVar1 != 0) {
    logMsg(DAT_30005124,iVar1,0,0,0,0,0);
  }
  iVar1 = WDT_Init();
  if (iVar1 != 0) {
    logMsg(DAT_30005128,iVar1,0,0,0,0,0);
  }
  BSP_WDT_Stop();
  power_off_clearup_flag();
  dloadInit();
  USB_UnReset();
  *DAT_300050b8 = 0;
  *DAT_3000512c = 0;
  taskSpawn(DAT_30005134,0x50,0,DAT_30005138,DAT_30005130,0,0,0,0,0,0,0,0,0,0);
  iVar1 = TFUP_getTFUpdateFlag();
  if (iVar1 == 1) {
    TFUP_CheckInit();
    sdmmcISRInit();
  }
  taskSpawn(DAT_30005140,0x51,0,DAT_30005138,DAT_3000513c,0,0,0,0,0,0,0,0,0,0);
  taskSpawn(DAT_30005148,0xff,0,0x1000,DAT_30005144,0,0,0,0,0,0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * BSP_ClearLogModule @ 0x30005154  (примерный размер ~156 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30005154
 * Данные: DAT_300055ac
 * ---------------------------------------------------------------- */
void BSP_ClearLogModule(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = DAT_300055ac;
  if ((int)param_1 < 0x34) {
    puVar1 = DAT_300055ac + 1;
    uVar3 = ~(1 << (param_1 & 0xff));
    *DAT_300055ac = uVar3 & *DAT_300055ac;
    puVar2[1] = (int)uVar3 >> 0x1f & *puVar1;
  }
  else {
    *DAT_300055ac = 0;
    puVar2[1] = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_SetLogModule @ 0x300051F0  (примерный размер ~152 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x300051F0
 * Данные: DAT_300055ac
 * ---------------------------------------------------------------- */
void BSP_SetLogModule(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar3 = DAT_300055ac;
  if ((int)param_1 < 0x34) {
    puVar2 = DAT_300055ac + 1;
    uVar1 = 1 << (param_1 & 0xff);
    *DAT_300055ac = uVar1 | *DAT_300055ac;
    puVar3[1] = (int)uVar1 >> 0x1f | *puVar2;
  }
  else {
    *DAT_300055ac = 0xffffffff;
    puVar3[1] = 0xffffffff;
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_GetLogModule @ 0x30005288  (примерный размер ~12 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30005288
 * Данные: DAT_300055ac
 * ---------------------------------------------------------------- */
undefined4 BSP_GetLogModule(void)

{
  return *DAT_300055ac;
}

/* ----------------------------------------------------------------
 * BSP_SetLogLevel @ 0x30005294  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30005294
 * Данные: DAT_300055b0
 * ---------------------------------------------------------------- */
void BSP_SetLogLevel(undefined4 param_1)

{
  *DAT_300055b0 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * BSP_GetLogLevel @ 0x300052AC  (примерный размер ~12 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300052AC
 * Данные: DAT_300055b0
 * ---------------------------------------------------------------- */
undefined4 BSP_GetLogLevel(void)

{
  return *DAT_300055b0;
}

/* ----------------------------------------------------------------
 * BSP_SetPrintPos @ 0x300052B8  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300052B8
 * Данные: DAT_300055b4
 * ---------------------------------------------------------------- */
void BSP_SetPrintPos(undefined4 param_1)

{
  *DAT_300055b4 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * BSP_GetPrintPos @ 0x300052D0  (примерный размер ~12 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300052D0
 * Данные: DAT_300055b4
 * ---------------------------------------------------------------- */
undefined4 BSP_GetPrintPos(void)

{
  return *DAT_300055b4;
}

/* ----------------------------------------------------------------
 * BSP_ErrnoGet @ 0x300052DC  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300052DC
 * Данные: DAT_300e2108, DAT_300e210c, DAT_300e2110
 * ---------------------------------------------------------------- */
undefined4 BSP_ErrnoGet(void)

{
  if ((*DAT_300e2108 < 1) && (*DAT_300e210c != 0)) {
    return *(undefined4 *)(*DAT_300e210c + 0xd0);
  }
  return *DAT_300e2110;
}

/* ----------------------------------------------------------------
 * BSP_TaskErrnoGet @ 0x300052E0  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoOfTaskGet
 * Константы: 0x300052E0
 * ---------------------------------------------------------------- */
void BSP_TaskErrnoGet(undefined4 param_1)

{
  errnoOfTaskGet(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_ErrnoSet @ 0x300052F4  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoSet
 * Константы: 0x300052F4
 * ---------------------------------------------------------------- */
void BSP_ErrnoSet(undefined4 param_1)

{
  errnoSet(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_TaskErrnoSet @ 0x30005308  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: errnoOfTaskSet
 * Константы: 0x30005308
 * ---------------------------------------------------------------- */
void BSP_TaskErrnoSet(undefined4 param_1,undefined4 param_2)

{
  errnoOfTaskSet(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_RegExceptionalEventReport @ 0x30005324  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30005324
 * Данные: DAT_300055b8
 * ---------------------------------------------------------------- */
void BSP_RegExceptionalEventReport(undefined4 param_1)

{
  *DAT_300055b8 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * BSP_TRACE @ 0x3000533C  (примерный размер ~380 байт)
 * Модуль: bsp | Вызывают: 135 | Вызывает: 2
 * Вызывает: __lsl64, logMsg
 * Вызывают: ABB_ReadCfg, BSP_CLK_Enable, BSP_CLK_RateSet, BSP_DLOAD_GetProductId, BSP_DLOAD_Init, BSP_DLOAD_SendData, BSP_FreeDbg, BSP_HKADC_BatVolAdcRead, BSP_HKADC_BatVolRead, BSP_HKADC_Convert
 *           ...
 * Константы: 0x3000533C
 * Данные: DAT_300055ac, DAT_300055b0, DAT_300055b4, DAT_300055bc, DAT_300055c0, DAT_300055c4
 * ---------------------------------------------------------------- */
void BSP_TRACE(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_3c [6];
  undefined4 local_4;
  
  if (*DAT_300055b0 <= param_1) {
    local_4 = param_4;
    uVar3 = __lsl64(1,0,param_2);
    if (((uint)((ulonglong)uVar3 >> 0x20) & DAT_300055ac[1]) + ((uint)uVar3 & *DAT_300055ac) != 0) {
      if (*DAT_300055b4 != 0) {
        logMsg(DAT_300055bc,DAT_300055c0,0,DAT_300055c4,0,0,0);
      }
      puVar2 = &local_4;
      for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
        local_3c[iVar1] = *puVar2;
        puVar2 = puVar2 + 1;
      }
      logMsg(param_3,local_3c[0],local_3c[1],local_3c[2],local_3c[3],local_3c[4],local_3c[5]);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_SFree @ 0x30005C90  (примерный размер ~172 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 4
 * Вызывает: BSP_TRACE, FUN_300067b0, FUN_30006d10, cacheInvalidate
 * Вызывают: BSP_SFreeDbg, FUN_30005d3c
 * Константы: 0x30005C90
 * Данные: DAT_30006b48, DAT_30006b4c, DAT_30006b50, DAT_30006c24, DAT_30006c28
 * ---------------------------------------------------------------- */
void BSP_SFree(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_30006d10(param_1);
  if (iVar1 == 0) {
    if (0x3ffff < (uint)(param_1 - DAT_30006b50)) {
      cacheInvalidate(1,param_1 + -0x20,0x20);
    }
    if (*(int *)(param_1 + -8) == 0) {
      BSP_TRACE(4,0x1c,DAT_30006c28,param_1,DAT_30006c24);
    }
    else {
      FUN_300067b0(*(undefined4 *)(param_1 + -0x14),param_1,*(undefined4 *)(param_1 + -0x18));
    }
  }
  else {
    BSP_TRACE(4,0x1c,DAT_30006b4c,param_1,DAT_30006b48);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30005d3c @ 0x30005D3C  (примерный размер ~276 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 5
 * Вызывает: BSP_SFree, BSP_TRACE, FUN_30006964, free, malloc
 * Вызывают: BSP_MEM_Init
 * Константы: 0xFFFFFFFF, 0x30005D3C
 * Данные: DAT_30006c2c, DAT_30006c30, DAT_30006c34, DAT_30006c38
 * ---------------------------------------------------------------- */
undefined4 FUN_30005d3c(undefined4 param_1)

{
  void *__ptr;
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    if (8 < uVar3) {
      return 0;
    }
    __ptr = malloc(*(int *)(DAT_30006c2c + uVar3 * 4) << 2);
    if (__ptr == (void *)0x0) break;
    for (uVar2 = 0; uVar2 < *(uint *)(DAT_30006c2c + uVar3 * 4); uVar2 = uVar2 + 1) {
      uVar1 = FUN_30006964(param_1,*(undefined4 *)(DAT_30006c34 + uVar3 * 4));
      *(undefined4 *)((int)__ptr + uVar2 * 4) = uVar1;
      if (*(int *)((int)__ptr + uVar2 * 4) == 0) {
        BSP_TRACE(4,0x1c,DAT_30006c38,0x204);
        for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
          BSP_SFree(*(undefined4 *)((int)__ptr + uVar3 * 4));
        }
        free(__ptr);
        return 0xffffffff;
      }
    }
    for (uVar2 = 0; uVar2 < *(uint *)(DAT_30006c2c + uVar3 * 4); uVar2 = uVar2 + 1) {
      BSP_SFree(*(undefined4 *)((int)__ptr + uVar2 * 4));
    }
    free(__ptr);
    uVar3 = uVar3 + 1;
  }
  BSP_TRACE(4,0x1c,DAT_30006c30,0x1fc);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * BSP_MEM_SetMostUsedSize @ 0x30005E74  (примерный размер ~224 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Вызывают: BSP_MEM_Init
 * Константы: 0xFFFFFFFF, 0x30005E74
 * Данные: DAT_30006b24, DAT_30006b28, DAT_30006d54, DAT_30006d58, DAT_30006d5c, DAT_30006d60, DAT_30006d64
 * ---------------------------------------------------------------- */
undefined4 BSP_MEM_SetMostUsedSize(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 < 3) {
    for (uVar2 = 0; (uVar2 < 9 && (*(uint *)(*DAT_30006d5c + uVar2 * 4) < param_1));
        uVar2 = uVar2 + 1) {
    }
    if (uVar2 < 9) {
      iVar3 = DAT_30006b28;
      if (param_2 != 0) {
        iVar3 = param_2 * 0xf4 + *DAT_30006b24 + -0xf4;
      }
      if (uVar2 == 0) {
        *(undefined4 *)(iVar3 + 0xec) = 0;
      }
      else {
        *(uint *)(iVar3 + 0xec) = uVar2 - 1;
      }
      uVar1 = 0;
    }
    else {
      BSP_TRACE(4,0x1c,DAT_30006d64,param_1,DAT_30006d60);
      uVar1 = 0xffffffff;
    }
  }
  else {
    BSP_TRACE(4,0x1c,DAT_30006d58,param_2,DAT_30006d54);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_MEM_Init @ 0x30005F54  (примерный размер ~216 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 7
 * Вызывает: BSP_MEM_SetMostUsedSize, BSP_TRACE, FUN_30005b50, FUN_30005d3c, memUsrInitFunction, memcpy, memset
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0xFFFFFFFF, 0x30005F54
 * Данные: DAT_30006b24, DAT_30006c34, DAT_30006d5c, DAT_30006de0, DAT_30006de4, DAT_30006de8, DAT_30006dec, DAT_30006df0
 * ---------------------------------------------------------------- */
undefined4 BSP_MEM_Init(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  memset(DAT_30006de0,0,4);
  memset((void *)*DAT_30006b24,0,0x2dc);
  memcpy((void *)*DAT_30006d5c,DAT_30006c34,0x24);
  iVar1 = memUsrInitFunction();
  if (iVar1 != 0) {
    BSP_TRACE(4,0x1c,DAT_30006de4,DAT_30006de8);
  }
  uVar3 = 0;
  while( true ) {
    if (2 < uVar3) {
      iVar1 = FUN_30005d3c(1);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        BSP_TRACE(4,0x1c,DAT_30006dec,DAT_30006df0);
        uVar2 = 0xffffffff;
      }
      return uVar2;
    }
    iVar1 = FUN_30005b50(uVar3);
    if (iVar1 != 0) break;
    BSP_MEM_SetMostUsedSize(0x200,uVar3);
    uVar3 = uVar3 + 1;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * BSP_Malloc @ 0x3000602C  (примерный размер ~32 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30006964
 * Вызывают: FUN_3005f68c
 * Константы: 0x3000602C
 * ---------------------------------------------------------------- */
undefined4 BSP_Malloc(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_30006964(0,param_1);
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_MallocDbg @ 0x3000604C  (примерный размер ~56 байт)
 * Модуль: bsp | Вызывают: 12 | Вызывает: 1
 * Вызывает: FUN_30006964
 * Вызывают: FUN_300426cc, FUN_30043428, FUN_30044654, FUN_30046974, FUN_30047fd4, FUN_3004a390, FUN_30050400, FUN_30056278, FUN_30059924, FUN_3005beb4
 *           ...
 * Константы: 0x3000604C
 * ---------------------------------------------------------------- */
int BSP_MallocDbg(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_30006964(0,param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + -0xc) = param_4;
    *(undefined4 *)(iVar1 + -0x10) = param_3;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * BSP_Free @ 0x30006084  (примерный размер ~32 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_300067b0
 * Вызывают: BSP_FreeDbg, FUN_3005f64c
 * Константы: 0x30006084
 * ---------------------------------------------------------------- */
void BSP_Free(int param_1)

{
  FUN_300067b0(0,param_1,*(undefined4 *)(param_1 + -0x18));
  return;
}

/* ----------------------------------------------------------------
 * BSP_FreeDbg @ 0x300060A4  (примерный размер ~148 байт)
 * Модуль: bsp | Вызывают: 39 | Вызывает: 3
 * Вызывает: BSP_Free, BSP_TRACE, FUN_30006d10
 * Вызывают: FUN_30043bd4, FUN_30043e64, FUN_30048f78, FUN_3004fce4, FUN_3004ffac, FUN_30051844, FUN_30058310, FUN_3005c700, cdc_free_descriptors, cdc_init_acm
 *           ...
 * Константы: 0x300060A4
 * Данные: DAT_30006df4, DAT_30006df8, DAT_30006dfc, DAT_30006e00
 * ---------------------------------------------------------------- */
void BSP_FreeDbg(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_30006d10(param_1);
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + -8) == 0) || (*(int *)(param_1 + -0x14) != 0)) {
      BSP_TRACE(4,0x1c,DAT_30006e00,param_1,DAT_30006dfc);
    }
    else {
      BSP_Free(param_1);
      *(undefined4 *)(param_1 + -0xc) = param_3;
      *(undefined4 *)(param_1 + -0x10) = param_2;
    }
  }
  else {
    BSP_TRACE(4,0x1c,DAT_30006df8,param_1,DAT_30006df4);
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_SMalloc @ 0x30006138  (примерный размер ~36 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_30006964
 * Константы: 0x30006138
 * ---------------------------------------------------------------- */
undefined4 BSP_SMalloc(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_30006964(param_2,param_1);
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_SMallocDbg @ 0x3000615C  (примерный размер ~88 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_TRACE, FUN_30006964
 * Константы: 0x3000615C
 * Данные: DAT_30006e04, DAT_30006e08
 * ---------------------------------------------------------------- */
undefined4 BSP_SMallocDbg(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 3) {
    uVar1 = FUN_30006964(param_2,param_1);
  }
  else {
    BSP_TRACE(4,0x1c,DAT_30006e08,param_2,DAT_30006e04);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_SFreeDbg @ 0x300061B4  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_SFree
 * Константы: 0x300061B4
 * ---------------------------------------------------------------- */
void BSP_SFreeDbg(undefined4 param_1)

{
  BSP_SFree(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_MEM_Info @ 0x300061C8  (примерный размер ~424 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x300061C8, 0xFFFFFFFF
 * Данные: DAT_30006b24, DAT_30006b28, DAT_30006c2c, DAT_30006d5c, DAT_30006e0c, DAT_30006e10, DAT_30006e14, DAT_30006e18
 * ---------------------------------------------------------------- */
undefined4 BSP_MEM_Info(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 < 3) {
    iVar2 = DAT_30006b28;
    if (param_1 != 0) {
      iVar2 = *DAT_30006b24 + param_1 * 0xf4 + -0xf4;
    }
    printf(DAT_30006e14,*(undefined4 *)(DAT_30006e10 + param_1 * 4));
    printf(DAT_30006e18);
    printf(DAT_30006e1c);
    printf(DAT_30006e20);
    printf(DAT_30006e24,*(undefined4 *)(iVar2 + 0xd8));
    printf(DAT_30006e28,*(undefined4 *)(iVar2 + 0xdc),*(undefined4 *)(iVar2 + 0xdc));
    printf(DAT_30006e2c,*(undefined4 *)(iVar2 + 0xe4),*(undefined4 *)(iVar2 + 0xe4));
    printf(DAT_30006e30,*(undefined4 *)(iVar2 + 0xe0));
    printf(DAT_30006e34,*(undefined4 *)(iVar2 + 0xe8));
    printf(DAT_30006e38,*(undefined4 *)(iVar2 + 0xec));
    printf(DAT_30006e3c,*(undefined4 *)(iVar2 + 0xf0));
    printf(DAT_30006e40);
    printf(DAT_30006e18);
    printf(DAT_30006e44);
    printf(DAT_30006e20);
    for (uVar3 = 0; uVar3 < 9; uVar3 = uVar3 + 1) {
      printf(DAT_30006e48,*(undefined4 *)(*DAT_30006d5c + uVar3 * 4));
      printf(DAT_30006e4c,*(undefined4 *)(iVar2 + uVar3 * 0x10 + 0x48));
      printf(DAT_30006e50,*(undefined4 *)(iVar2 + uVar3 * 0x10 + 0x4c));
      if (param_1 == 1) {
        printf(DAT_30006e54,*(undefined4 *)(DAT_30006c2c + uVar3 * 4));
        printf(DAT_30006e5c,*(undefined4 *)(DAT_30006e58 + uVar3 * 4));
      }
      printf(DAT_30006e60,*(undefined4 *)(iVar2 + uVar3 * 0x10 + 0x50));
      printf(DAT_30006e64,*(undefined4 *)(iVar2 + uVar3 * 0x10 + 0x54));
      printf(DAT_30006e68);
    }
    printf(DAT_30006e18);
    uVar1 = 0;
  }
  else {
    printf(DAT_30006e0c,param_1);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_MEM_DumpBlock @ 0x30006370  (примерный размер ~276 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 2
 * Вызывает: cacheInvalidate, printf
 * Вызывают: BSP_MEM_DumpAllocList, BSP_MEM_Scan
 * Константы: 0x30006370, 0xFFFFFFFF
 * Данные: DAT_30006e18, DAT_30006e6c, DAT_30006e70, DAT_30006e74, DAT_30006e78, DAT_30006e7c, DAT_30006e80, DAT_30006e84
 * ---------------------------------------------------------------- */
undefined4 BSP_MEM_DumpBlock(int param_1)

{
  undefined4 uVar1;
  bool bVar2;
  
  if (param_1 == 0) {
    printf(DAT_30006e6c);
    uVar1 = 0xffffffff;
  }
  else {
    bVar2 = *(int *)(param_1 + -0x20) == DAT_30006e70;
    if (!bVar2) {
      printf(DAT_30006e74,param_1);
    }
    cacheInvalidate(1,param_1 + -0x20,0x20);
    printf(DAT_30006e18);
    printf(DAT_30006e78);
    printf(DAT_30006e18);
    printf(DAT_30006e7c,param_1);
    printf(DAT_30006e80,param_1 + -0x20);
    printf(DAT_30006e84,*(undefined4 *)(param_1 + -0x20));
    printf(DAT_30006e88,*(undefined4 *)(param_1 + -0x18));
    printf(DAT_30006e8c,*(undefined4 *)(param_1 + -0x14));
    printf(DAT_30006e90,*(undefined4 *)(param_1 + -0x1c));
    uVar1 = DAT_30006e94;
    if (bVar2) {
      uVar1 = *(undefined4 *)(param_1 + -0x10);
    }
    printf(DAT_30006e98,uVar1);
    printf(DAT_30006e9c,*(undefined4 *)(param_1 + -0xc));
    uVar1 = DAT_30006ea4;
    if (*(int *)(param_1 + -8) != 0) {
      uVar1 = DAT_30006ea0;
    }
    printf(DAT_30006ea8,uVar1);
    printf(DAT_30006e18);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_MEM_DumpAllocList @ 0x30006484  (примерный размер ~320 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_MEM_DumpBlock, printf
 * Константы: 0xFFFFFFFF, 0x30006484
 * Данные: DAT_30006b24, DAT_30006b28, DAT_30006d5c, DAT_30006e0c, DAT_30006eac, DAT_30006eb0, DAT_30006eb4
 * ---------------------------------------------------------------- */
undefined4 BSP_MEM_DumpAllocList(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = 0;
  if (param_2 < 3) {
    iVar3 = DAT_30006b28;
    if (param_2 != 0) {
      iVar3 = *DAT_30006b24 + param_2 * 0xf4 + -0xf4;
    }
    uVar4 = *(uint *)(iVar3 + 0xec);
    uVar5 = uVar4;
    if (*(uint *)(*DAT_30006d5c + uVar4 * 4) < param_1) {
      do {
        uVar5 = uVar5 + 1;
        if (8 < uVar5) break;
      } while (*(uint *)(*DAT_30006d5c + uVar5 * 4) < param_1);
    }
    else {
      for (uVar5 = 0; (uVar5 <= uVar4 && (*(uint *)(*DAT_30006d5c + uVar5 * 4) < param_1));
          uVar5 = uVar5 + 1) {
      }
      if (uVar4 < uVar5) {
        uVar5 = 9;
      }
    }
    if (uVar5 < 9) {
      printf(DAT_30006eb0);
      for (iVar3 = *(int *)(iVar3 + uVar5 * 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + -0x1c)) {
        BSP_MEM_DumpBlock(iVar3);
        iVar2 = iVar2 + 1;
      }
      printf(DAT_30006eb4,iVar2);
      uVar1 = 0;
    }
    else {
      printf(DAT_30006eac,param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    printf(DAT_30006e0c,param_2);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_MEM_Scan @ 0x300065C4  (примерный размер ~492 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: BSP_MEM_DumpBlock, __srget, __stdin, printf
 * Константы: 0x300065C4, 0xFFFFFFFF
 * Данные: DAT_30006b24, DAT_30006b28, DAT_30006e0c, DAT_30006e10, DAT_30006e18, DAT_30006e1c, DAT_30006e20, DAT_30006e24
 * ---------------------------------------------------------------- */
undefined4 BSP_MEM_Scan(uint param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  
  iVar6 = DAT_30006b28;
  if (param_1 != 0) {
    iVar6 = *DAT_30006b24 + param_1 * 0xf4 + -0xf4;
  }
  if (param_1 < 3) {
    uVar5 = *(uint *)(iVar6 + 0xd8);
    iVar8 = *(int *)(iVar6 + 0xe8);
    uVar9 = *(uint *)(iVar6 + 0xe0);
    printf(DAT_30006eb8,*(undefined4 *)(DAT_30006e10 + param_1 * 4));
    printf(DAT_30006e18);
    printf(DAT_30006e1c);
    printf(DAT_30006e20);
    printf(DAT_30006e24,*(undefined4 *)(iVar6 + 0xd8));
    printf(DAT_30006e28,*(undefined4 *)(iVar6 + 0xdc),*(undefined4 *)(iVar6 + 0xdc));
    printf(DAT_30006e2c,*(undefined4 *)(iVar6 + 0xe4),*(undefined4 *)(iVar6 + 0xe4));
    printf(DAT_30006e30,*(undefined4 *)(iVar6 + 0xe0));
    printf(DAT_30006e34,*(undefined4 *)(iVar6 + 0xe8));
    printf(DAT_30006e38,*(undefined4 *)(iVar6 + 0xec));
    printf(DAT_30006e40);
    do {
      do {
        if (uVar9 <= uVar5) goto LAB_3000679c;
        iVar6 = uVar5 + iVar8;
        BSP_MEM_DumpBlock(iVar6);
        uVar5 = iVar6 + *(int *)(iVar6 + -0x18);
        printf(DAT_30006ebc);
        piVar2 = (int *)__stdin();
        iVar6 = *(int *)(*piVar2 + 4);
        piVar2 = (int *)__stdin();
      } while ((*piVar2 != iVar6) || (piVar2 = (int *)__stdin(), *(char *)(*piVar2 + 10) != 'f'));
      piVar2 = (int *)__stdin();
      piVar2 = (int *)(*piVar2 + 0x10);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 0) {
        puVar3 = (undefined4 *)__stdin();
        uVar4 = __srget(*puVar3);
      }
      else {
        piVar2 = (int *)__stdin();
        piVar2 = (int *)(*piVar2 + 0xc);
        pbVar7 = (byte *)*piVar2;
        *piVar2 = *piVar2 + 1;
        uVar4 = (uint)*pbVar7;
      }
    } while (uVar4 != 0x71);
LAB_3000679c:
    uVar1 = 0;
  }
  else {
    printf(DAT_30006e0c,param_1);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300067b0 @ 0x300067B0  (примерный размер ~436 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 6
 * Вызывает: BSP_TRACE, cacheFlush, intCpuLock, intCpuUnlock, spinLockAmpGive, spinLockAmpTake
 * Вызывают: BSP_Free, BSP_SFree
 * Константы: 0x300067B0
 * Данные: DAT_30006b24, DAT_30006b28, DAT_30006d5c, DAT_30006de0, DAT_30006ec0, DAT_30006ec4, DAT_30006ec8
 * ---------------------------------------------------------------- */
void FUN_300067b0(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  
  iVar2 = DAT_30006b28;
  if (param_1 != 0) {
    iVar2 = *DAT_30006b24 + param_1 * 0xf4 + -0xf4;
  }
  uVar3 = *(uint *)(iVar2 + 0xec);
  uVar4 = uVar3;
  if (*(uint *)(*DAT_30006d5c + uVar3 * 4) < param_3) {
    do {
      uVar4 = uVar4 + 1;
      if (8 < uVar4) break;
    } while (*(uint *)(*DAT_30006d5c + uVar4 * 4) < param_3);
  }
  else {
    for (uVar4 = 0; (uVar4 <= uVar3 && (*(uint *)(*DAT_30006d5c + uVar4 * 4) < param_3));
        uVar4 = uVar4 + 1) {
    }
    if (uVar3 < uVar4) {
      uVar4 = 9;
    }
  }
  if (uVar4 < 9) {
    if (param_1 == 0) {
      uVar1 = intCpuLock();
      *DAT_30006ec8 = uVar1;
    }
    else {
      uVar1 = intCpuLock();
      *DAT_30006ec8 = uVar1;
      spinLockAmpTake(DAT_30006de0);
    }
    *(undefined4 *)(param_2 + -0x1c) = *(undefined4 *)(iVar2 + uVar4 * 4);
    *(int *)(iVar2 + uVar4 * 4) = param_2;
    piVar5 = (int *)(iVar2 + uVar4 * 0x10 + 0x48);
    *piVar5 = *piVar5 + -1;
    piVar5 = (int *)(iVar2 + uVar4 * 0x10 + 0x54);
    *piVar5 = *piVar5 + 1;
    *(undefined4 *)(param_2 + -8) = 0;
    if (param_1 == 1) {
      cacheFlush(1,param_2 + -0x20,0x20);
    }
    if (param_1 == 0) {
      intCpuUnlock(*DAT_30006ec8);
    }
    else {
      spinLockAmpGive(DAT_30006de0);
      intCpuUnlock(*DAT_30006ec8);
    }
  }
  else {
    BSP_TRACE(4,0x1c,DAT_30006ec4,param_3,DAT_30006ec0);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30006964 @ 0x30006964  (примерный размер ~580 байт)
 * Модуль: bsp | Вызывают: 5 | Вызывает: 7
 * Вызывает: BSP_TRACE, FUN_30006ba8, cacheFlush, intCpuLock, intCpuUnlock, spinLockAmpGive, spinLockAmpTake
 * Вызывают: BSP_Malloc, BSP_MallocDbg, BSP_SMalloc, BSP_SMallocDbg, FUN_30005d3c
 * Константы: 0x30006964
 * Данные: DAT_30006b24, DAT_30006b28, DAT_30006d5c, DAT_30006de0, DAT_30006ec8, DAT_30006ecc, DAT_30006ed0
 * ---------------------------------------------------------------- */
int FUN_30006964(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  
  iVar4 = DAT_30006b28;
  if (param_1 != 0) {
    iVar4 = *DAT_30006b24 + param_1 * 0xf4 + -0xf4;
  }
  uVar3 = *(uint *)(iVar4 + 0xec);
  uVar5 = uVar3;
  if (*(uint *)(*DAT_30006d5c + uVar3 * 4) < param_2) {
    do {
      uVar5 = uVar5 + 1;
      if (8 < uVar5) break;
    } while (*(uint *)(*DAT_30006d5c + uVar5 * 4) < param_2);
  }
  else {
    for (uVar5 = 0; (uVar5 <= uVar3 && (*(uint *)(*DAT_30006d5c + uVar5 * 4) < param_2));
        uVar5 = uVar5 + 1) {
    }
    if (uVar3 < uVar5) {
      uVar5 = 9;
    }
  }
  if (uVar5 < 9) {
    uVar7 = *(undefined4 *)(*DAT_30006d5c + uVar5 * 4);
    if (param_1 == 0) {
      uVar2 = intCpuLock();
      *DAT_30006ec8 = uVar2;
    }
    else {
      uVar2 = intCpuLock();
      *DAT_30006ec8 = uVar2;
      spinLockAmpTake(DAT_30006de0);
    }
    iVar1 = FUN_30006ba8(iVar4,uVar5,param_1,uVar7);
    if (iVar1 != 0) {
      piVar6 = (int *)(iVar4 + uVar5 * 0x10 + 0x48);
      *piVar6 = *piVar6 + 1;
      piVar6 = (int *)(iVar4 + uVar5 * 0x10 + 0x50);
      *piVar6 = *piVar6 + 1;
      if (*(uint *)(iVar4 + uVar5 * 0x10 + 0x4c) < *(uint *)(iVar4 + uVar5 * 0x10 + 0x48)) {
        *(undefined4 *)(iVar4 + uVar5 * 0x10 + 0x4c) = *(undefined4 *)(iVar4 + uVar5 * 0x10 + 0x48);
      }
      *(undefined4 *)(iVar1 + -8) = 1;
      if (param_1 == 1) {
        cacheFlush(1,iVar1 + -0x20,0x20);
      }
    }
    if (param_1 == 0) {
      intCpuUnlock(*DAT_30006ec8);
    }
    else {
      spinLockAmpGive(DAT_30006de0);
      intCpuUnlock(*DAT_30006ec8);
    }
  }
  else {
    BSP_TRACE(4,0x1c,DAT_30006ed0,param_2,DAT_30006ecc);
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30006ba8 @ 0x30006BA8  (примерный размер ~280 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30006cc0, cacheInvalidate
 * Вызывают: FUN_30006964
 * Константы: 0x30006BA8
 * Данные: DAT_30006e58, DAT_30006e70
 * ---------------------------------------------------------------- */
int FUN_30006ba8(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + param_2 * 4);
  if (*piVar2 == 0) {
    if ((param_3 == 1) &&
       (*(uint *)(DAT_30006e58 + param_2 * 4) <= *(uint *)(param_1 + param_2 * 4 + 0x24))) {
      *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_30006cc0(param_1,param_4 + *(int *)(param_1 + 0xe8));
      if (iVar1 == 0) {
        *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
        iVar1 = 0;
      }
      else {
        *(undefined4 *)(iVar1 + -0x20) = DAT_30006e70;
        *(int *)(iVar1 + -0x18) = param_4;
        *(int *)(iVar1 + -0x14) = param_3;
        if (param_3 == 1) {
          piVar2 = (int *)(param_1 + param_2 * 4 + 0x24);
          *piVar2 = *piVar2 + 1;
        }
        *(undefined4 *)(iVar1 + -0x10) = 0;
        *(undefined4 *)(iVar1 + -0xc) = 0;
      }
    }
  }
  else {
    iVar1 = *piVar2;
    if (param_3 == 1) {
      cacheInvalidate(1,iVar1 + -0x20,0x20);
    }
    *piVar2 = *(int *)(iVar1 + -0x1c);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30006cc0 @ 0x30006CC0  (примерный размер ~80 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30006ba8
 * Константы: 0x30006CC0
 * ---------------------------------------------------------------- */
int FUN_30006cc0(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xe0);
  if (*(uint *)(param_1 + 0xe4) < param_2) {
    iVar1 = 0;
  }
  else {
    *(uint *)(param_1 + 0xe0) = param_2 + *(int *)(param_1 + 0xe0);
    *(uint *)(param_1 + 0xe4) = *(int *)(param_1 + 0xe4) - param_2;
    iVar1 = iVar1 + *(int *)(param_1 + 0xe8);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30006d10 @ 0x30006D10  (примерный размер ~460 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 0
 * Вызывают: BSP_FreeDbg, BSP_SFree
 * Константы: 0x30006D10
 * Данные: DAT_30006e70, DAT_30006ed4, DAT_30006ed8
 * ---------------------------------------------------------------- */
undefined4 FUN_30006d10(uint param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  bVar1 = false;
  for (uVar3 = 0; uVar3 < 3; uVar3 = uVar3 + 1) {
    iVar4 = DAT_30006ed8;
    if (uVar3 != 0) {
      iVar4 = *DAT_30006ed4 + uVar3 * 0xf4 + -0xf4;
    }
    if ((*(uint *)(iVar4 + 0xd8) <= param_1) ||
       (param_1 < *(uint *)(iVar4 + 0xd8) + *(int *)(iVar4 + 0xdc))) {
      bVar1 = true;
    }
  }
  if (((bVar1) && (*(int *)(param_1 - 0x20) == DAT_30006e70)) && (*(uint *)(param_1 - 0x14) < 3)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_CalcCrc32 @ 0x30006EDC  (примерный размер ~120 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30006EDC
 * Данные: DAT_30006f50
 * ---------------------------------------------------------------- */
uint BSP_CalcCrc32(byte *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  while (param_2 != 0) {
    uVar1 = param_2;
    if (0x8000 < param_2) {
      uVar1 = 0x8000;
    }
    param_2 = param_2 - uVar1;
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      param_3 = *(uint *)(DAT_30006f50 + (param_3 & 0xff ^ (uint)*param_1) * 4) ^ param_3 >> 8;
      param_1 = param_1 + 1;
    }
  }
  return param_3;
}

/* ----------------------------------------------------------------
 * WDT_FeedLogStart @ 0x30006F54  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30006F54
 * Данные: DAT_30007a04, DAT_30007a08, DAT_30007a0c
 * ---------------------------------------------------------------- */
void WDT_FeedLogStart(void)

{
  *DAT_30007a04 = 1;
  *DAT_30007a08 = 0;
  *DAT_30007a0c = 0;
  return;
}

/* ----------------------------------------------------------------
 * WDT_FeedLogStop @ 0x30006F7C  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30006F7C
 * Данные: DAT_30007a04, DAT_30007a0c
 * ---------------------------------------------------------------- */
void WDT_FeedLogStop(void)

{
  *DAT_30007a04 = 0;
  *DAT_30007a0c = 0;
  return;
}

/* ----------------------------------------------------------------
 * WDT_FeedLog @ 0x30006F98  (примерный размер ~148 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: tickGet
 * Вызывают: WDT_LowTask
 * Константы: 0x30006F98
 * Данные: DAT_30007a08, DAT_30007a0c, DAT_30007a10, DAT_30007a14
 * ---------------------------------------------------------------- */
void WDT_FeedLog(void)

{
  int iVar1;
  uint uVar2;
  
  if (*DAT_30007a08 == 0) {
    iVar1 = tickGet();
    *DAT_30007a10 = iVar1;
    *DAT_30007a08 = 1;
  }
  else {
    iVar1 = tickGet();
    uVar2 = *DAT_30007a0c;
    *(int *)(DAT_30007a14 + uVar2 * 4) = iVar1 - *DAT_30007a10;
    *DAT_30007a0c = uVar2 + 1;
    *DAT_30007a10 = iVar1;
    if (99 < *DAT_30007a0c) {
      *DAT_30007a0c = *DAT_30007a0c - 100;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * WDT_FeedLogClean @ 0x3000702C  (примерный размер ~16 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: memset
 * Константы: 0x3000702C
 * Данные: DAT_30007a14
 * ---------------------------------------------------------------- */
void WDT_FeedLogClean(void)

{
  memset(DAT_30007a14,0,400);
  return;
}

/* ----------------------------------------------------------------
 * WDT_ShowLog @ 0x3000703C  (примерный размер ~232 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x3000703C
 * Данные: DAT_30007a14, DAT_30007a18, DAT_30007a1c, DAT_30007a20, DAT_30007a24, DAT_30007a28, DAT_30007a2c, DAT_30007a30
 * ---------------------------------------------------------------- */
void WDT_ShowLog(void)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1) {
    printf(DAT_30007a3c,*(undefined4 *)(DAT_30007a14 + uVar1 * 0x28),
           *(undefined4 *)(DAT_30007a34 + uVar1 * 0x28),*(undefined4 *)(DAT_30007a38 + uVar1 * 0x28)
           ,*(undefined4 *)(DAT_30007a18 + uVar1 * 0x28),
           *(undefined4 *)(DAT_30007a1c + uVar1 * 0x28),*(undefined4 *)(DAT_30007a20 + uVar1 * 0x28)
           ,*(undefined4 *)(DAT_30007a24 + uVar1 * 0x28),
           *(undefined4 *)(DAT_30007a28 + uVar1 * 0x28),*(undefined4 *)(DAT_30007a2c + uVar1 * 0x28)
           ,*(undefined4 *)(DAT_30007a30 + uVar1 * 0x28));
  }
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_WDT_SoftClkStatus @ 0x30007124  (примерный размер ~80 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x30007124
 * Данные: DAT_30007a40, DAT_30007a44
 * ---------------------------------------------------------------- */
void PWRCTRL_WDT_SoftClkStatus(void)

{
  logMsg(DAT_30007a44,*DAT_30007a40 >> 0x1f & 1,0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_WDT_SoftClkDis @ 0x30007174  (примерный размер ~16 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 0
 * Вызывают: BSP_WDT_Disable, BSP_WDT_SetTimeOut
 * Константы: 0x30007174
 * Данные: DAT_30007a48, DAT_30007a4c
 * ---------------------------------------------------------------- */
void PWRCTRL_WDT_SoftClkDis(void)

{
  *DAT_30007a48 = DAT_30007a4c;
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_WDT_SoftClkEn @ 0x30007184  (примерный размер ~16 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 0
 * Вызывают: BSP_OM_SoftReboot, BSP_WDT_Enable, BSP_WDT_SetTimeOut, BSP_WDT_reboot_direct
 * Константы: 0x30007184
 * Данные: DAT_30007a4c, DAT_30007a50
 * ---------------------------------------------------------------- */
void PWRCTRL_WDT_SoftClkEn(void)

{
  *DAT_30007a50 = DAT_30007a4c;
  return;
}

/* ----------------------------------------------------------------
 * WDT_LOCK @ 0x30007194  (примерный размер ~16 байт)
 * Модуль: bsp | Вызывают: 5 | Вызывает: 0
 * Вызывают: BSP_WDT_Disable, BSP_WDT_Enable, BSP_WDT_HardwareFeed, BSP_WDT_SetTimeOut, BSP_WDT_TimeoutGet
 * Константы: 0x30007194
 * Данные: DAT_30007a54
 * ---------------------------------------------------------------- */
void WDT_LOCK(void)

{
  *DAT_30007a54 = 0;
  return;
}

/* ----------------------------------------------------------------
 * WDT_UNLOCK @ 0x300071A4  (примерный размер ~16 байт)
 * Модуль: bsp | Вызывают: 5 | Вызывает: 0
 * Вызывают: BSP_WDT_Disable, BSP_WDT_Enable, BSP_WDT_HardwareFeed, BSP_WDT_SetTimeOut, BSP_WDT_TimeoutGet
 * Константы: 0x300071A4
 * Данные: DAT_30007a54, DAT_30007a58
 * ---------------------------------------------------------------- */
void WDT_UNLOCK(void)

{
  *DAT_30007a54 = DAT_30007a58;
  return;
}

/* ----------------------------------------------------------------
 * BSP_WDT_HardwareFeed @ 0x300071B4  (примерный размер ~172 байт)
 * Модуль: bsp | Вызывают: 5 | Вызывает: 3
 * Вызывает: BSP_TRACE, WDT_LOCK, WDT_UNLOCK
 * Вызывают: WDT_IntHandler, WDT_LowTask, exchSave, exchWdtHook, usrAppInit
 * Константы: 0xFFFFFFFF, 0x300071B4
 * Данные: DAT_30007a5c, DAT_30007a60, DAT_30007a64, DAT_30007a68
 * ---------------------------------------------------------------- */
undefined4 BSP_WDT_HardwareFeed(char param_1)

{
  undefined4 uVar1;
  
  if (*DAT_30007a5c == 0) {
    uVar1 = 0xffffffff;
  }
  else if (*DAT_30007a60 == 0) {
    if (param_1 == '\0') {
      BSP_TRACE(0,9,DAT_30007a64,0,0,0,0,0,0);
      WDT_UNLOCK();
      *DAT_30007a68 = 0;
      WDT_LOCK();
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * WDT_LowTask @ 0x30007260  (примерный размер ~148 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: BSP_TRACE, BSP_WDT_HardwareFeed, WDT_FeedLog, semTake
 * Константы: 0x30007260
 * Данные: DAT_30007a04, DAT_30007a5c, DAT_30007a6c, DAT_30007a70, DAT_30007a74
 * ---------------------------------------------------------------- */
void WDT_LowTask(void)

{
  do {
    do {
      semTake(*DAT_30007a6c,500);
    } while (*DAT_30007a5c == 0);
    if (*DAT_30007a70 == 1) {
      BSP_TRACE(0,9,DAT_30007a74,0,0,0,0,0,0);
      BSP_WDT_HardwareFeed(0);
      if (*DAT_30007a04 != 0) {
        WDT_FeedLog();
      }
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * WDT_SoftWdInit @ 0x300072F4  (примерный размер ~308 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: BSP_TRACE, semBCreate, taskSpawn
 * Вызывают: WDT_Init
 * Константы: 0xFFFFFFFF, 0x300072F4
 * Данные: DAT_30007a6c, DAT_30007a78, DAT_30007a7c, DAT_30007a80, DAT_30007a84, DAT_30007a88
 * ---------------------------------------------------------------- */
undefined4 WDT_SoftWdInit(void)

{
  int iVar1;
  
  if (*DAT_30007a6c == 0) {
    iVar1 = semBCreate(0,0);
    *DAT_30007a6c = iVar1;
    if (*DAT_30007a6c == 0) {
      BSP_TRACE(4,9,DAT_30007a78,0,0,0,0,0,0);
      return 0xffffffff;
    }
  }
  if (*DAT_30007a7c == 0) {
    iVar1 = taskSpawn(DAT_30007a84,0xfe,0,0x1000,DAT_30007a80,0,0,0,0,0,0,0,0,0,0);
    *DAT_30007a7c = iVar1;
    if (*DAT_30007a7c == -1) {
      return 0xffffffff;
    }
  }
  *DAT_30007a88 = 1;
  return 0;
}

/* ----------------------------------------------------------------
 * WDT_APPInit @ 0x30007428  (примерный размер ~32 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: intConnect, intEnable
 * Вызывают: WDT_Init
 * Константы: 0x30007428
 * Данные: DAT_30007a8c
 * ---------------------------------------------------------------- */
void WDT_APPInit(void)

{
  intConnect(0x54,DAT_30007a8c,0);
  intEnable(0x54);
  return;
}

/* ----------------------------------------------------------------
 * WDT_Init @ 0x30007448  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 4
 * Вызывает: WDT_APPInit, WDT_SoftWdInit, intCpuLock, intCpuUnlock
 * Вызывают: BSP_DRV_BOOTROM_Init, BSP_WDT_Enable
 * Константы: 0x30007448
 * ---------------------------------------------------------------- */
undefined4 WDT_Init(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = intCpuLock();
  uVar2 = WDT_SoftWdInit();
  WDT_APPInit();
  intCpuUnlock(uVar1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * WDT_IntHandler @ 0x30007470  (примерный размер ~176 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_WDT_HardwareFeed, intDisable
 * Константы: 0xFFFFFFFF, 0x30007470
 * Данные: DAT_30007a60, DAT_30007a70, DAT_30007a90, DAT_30007a94, DAT_30007a98, DAT_30007a9c
 * ---------------------------------------------------------------- */
undefined4 WDT_IntHandler(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 & 0xff) == 0) {
    if (*DAT_30007a90 == DAT_30007a94) {
      intDisable(0x25);
      *DAT_30007a60 = 1;
      uVar1 = 0;
    }
    else {
      if (*DAT_30007a70 == 0) {
        if (*DAT_30007a98 == 0) {
          BSP_WDT_HardwareFeed(param_1);
        }
      }
      else {
        if (*DAT_30007a9c == 0) {
          return 0xffffffff;
        }
        (*(code *)*DAT_30007a9c)();
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * WDT_APPIntHandler @ 0x30007520  (примерный размер ~164 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, excJobAdd, intDisable
 * Константы: 0x30007520
 * Данные: DAT_30007aa0, DAT_30007aa4, DAT_30007ab0
 * ---------------------------------------------------------------- */
undefined4 WDT_APPIntHandler(void)

{
  *(undefined4 *)(*DAT_30007aa0 + 0x114) = 1;
  BSP_TRACE(0,9,DAT_30007aa4,0,0,0,0,0,0);
  intDisable(0x54);
  excJobAdd(DAT_30007ab0,0,0,0,0,0,0);
  return 0;
}

/* ----------------------------------------------------------------
 * WDT_Reboot @ 0x300075C4  (примерный размер ~68 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: BSP_OM_SoftReboot, BSP_WDT_reboot_direct
 * Константы: 0x300075C4
 * Данные: DAT_30007a98, DAT_30007ab4
 * ---------------------------------------------------------------- */
void WDT_Reboot(void)

{
  logMsg(DAT_30007ab4,0,0,0,0,0,0);
  *DAT_30007a98 = 1;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* ----------------------------------------------------------------
 * wdtFeedDisableSet @ 0x30007608  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: exchWdtHook
 * Константы: 0x30007608
 * Данные: DAT_30007a60
 * ---------------------------------------------------------------- */
void wdtFeedDisableSet(undefined4 param_1,undefined2 param_2)

{
  *DAT_30007a60 = param_2;
  return;
}

/* ----------------------------------------------------------------
 * BSP_WDT_Init @ 0x3000761C  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000761C
 * ---------------------------------------------------------------- */
undefined4 BSP_WDT_Init(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_WDT_Enable @ 0x30007624  (примерный размер ~180 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 6
 * Вызывает: PWRCTRL_WDT_SoftClkEn, WDT_Init, WDT_LOCK, WDT_UNLOCK, intConnect, intEnable
 * Константы: 0xFFFFFFFF, 0x30007624
 * Данные: DAT_30007a5c, DAT_30007a88, DAT_30007ab8, DAT_30007abc, DAT_30007ac0, DAT_30007ac4, DAT_30007ac8
 * ---------------------------------------------------------------- */
undefined4 BSP_WDT_Enable(char param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_30007a5c == 0) {
    if ((*DAT_30007a88 == 0) && (iVar2 = WDT_Init(), iVar2 != 0)) {
      uVar1 = 0xffffffff;
    }
    else if (param_1 == '\0') {
      PWRCTRL_WDT_SoftClkEn();
      *DAT_30007ab8 = DAT_30007abc;
      WDT_UNLOCK();
      *DAT_30007ac0 = 0xf0000;
      *DAT_30007ac4 = 3;
      WDT_LOCK();
      intConnect(0x25,DAT_30007ac8,0);
      intEnable(0x25);
      *DAT_30007a5c = 1;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_WDT_Disable @ 0x300076D8  (примерный размер ~72 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: PWRCTRL_WDT_SoftClkDis, WDT_LOCK, WDT_UNLOCK
 * Вызывают: usrAppInit
 * Константы: 0x300076D8, 0xFFFFFFFF
 * Данные: DAT_30007a5c, DAT_30007ac4
 * ---------------------------------------------------------------- */
undefined4 BSP_WDT_Disable(char param_1)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    WDT_UNLOCK();
    *DAT_30007ac4 = 0;
    WDT_LOCK();
    PWRCTRL_WDT_SoftClkDis();
    *DAT_30007a5c = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_WDT_SetTimeOut @ 0x30007720  (примерный размер ~100 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: PWRCTRL_WDT_SoftClkDis, PWRCTRL_WDT_SoftClkEn, WDT_LOCK, WDT_UNLOCK
 * Константы: 0x30007720, 0xFFFFFFFF
 * Данные: DAT_30007a5c, DAT_30007ac0
 * ---------------------------------------------------------------- */
undefined4 BSP_WDT_SetTimeOut(char param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    if (*DAT_30007a5c == 0) {
      PWRCTRL_WDT_SoftClkEn();
    }
    WDT_UNLOCK();
    *DAT_30007ac0 = param_2;
    WDT_LOCK();
    if (*DAT_30007a5c == 0) {
      PWRCTRL_WDT_SoftClkDis();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_WDT_Feed @ 0x30007784  (примерный размер ~72 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: semGive
 * Константы: 0xFFFFFFFF, 0x30007784
 * Данные: DAT_30007a5c, DAT_30007a60, DAT_30007a6c
 * ---------------------------------------------------------------- */
undefined4 BSP_WDT_Feed(void)

{
  undefined4 uVar1;
  
  if (*DAT_30007a5c == 0) {
    uVar1 = 0xffffffff;
  }
  else if (*DAT_30007a60 == 0) {
    semGive(*DAT_30007a6c);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_WDT_Feed_Force @ 0x300077CC  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x300077CC
 * Данные: DAT_30007a54, DAT_30007a58, DAT_30007a68
 * ---------------------------------------------------------------- */
void BSP_WDT_Feed_Force(void)

{
  *DAT_30007a54 = DAT_30007a58;
  *DAT_30007a68 = 0;
  *DAT_30007a54 = 0;
  return;
}

/* ----------------------------------------------------------------
 * BSP_WDT_Switch @ 0x300077F4  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300077F4
 * ---------------------------------------------------------------- */
undefined4 BSP_WDT_Switch(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_WDT_IntInstall @ 0x300077FC  (примерный размер ~68 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x300077FC
 * Данные: DAT_30007a9c
 * ---------------------------------------------------------------- */
undefined4 BSP_WDT_IntInstall(char param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else if (param_1 == '\0') {
    *DAT_30007a9c = param_2;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_WDT_IntUnInstall @ 0x30007840  (примерный размер ~52 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30007840, 0xFFFFFFFF
 * Данные: DAT_30007a9c
 * ---------------------------------------------------------------- */
undefined4 BSP_WDT_IntUnInstall(char param_1)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    *DAT_30007a9c = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_WDT_TimeoutGet @ 0x30007874  (примерный размер ~96 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: WDT_LOCK, WDT_UNLOCK
 * Константы: 0xFFFFFFFF, 0x30007874
 * Данные: DAT_30007acc, DAT_30007ad0
 * ---------------------------------------------------------------- */
undefined4 BSP_WDT_TimeoutGet(char param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_2 == (uint *)0x0) {
    uVar1 = 0xffffffff;
  }
  else if (param_1 == '\0') {
    WDT_UNLOCK();
    uVar2 = *DAT_30007acc;
    WDT_LOCK();
    *param_2 = (uint)((ulonglong)DAT_30007ad0 * (ulonglong)uVar2 >> 0x23);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_WDT_reboot @ 0x300078D4  (примерный размер ~60 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: systemError
 * Константы: 0x300078D4
 * Данные: DAT_30007aa0
 * ---------------------------------------------------------------- */
void BSP_WDT_reboot(void)

{
  *(undefined4 *)(*DAT_30007aa0 + 0x24) = 0xfe;
  systemError(0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * BSP_WDT_reboot_direct @ 0x30007910  (примерный размер ~108 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 6
 * Вызывает: PWRCTRL_WDT_SoftClkEn, WDT_Reboot, cacheFlush, intCpuLock, intDisable, taskCpuLock
 * Вызывают: BSP_DLOAD_Reset, exchSaveAndRebootJob, sysToMonitor, systemError
 * Константы: 0x30007910, 0x00100000
 * Данные: DAT_30007a54, DAT_30007a58, DAT_30007aa0, DAT_30007ac0, DAT_30007ac4, DAT_30007ad4
 * ---------------------------------------------------------------- */
void BSP_WDT_reboot_direct(void)

{
  PWRCTRL_WDT_SoftClkEn();
  taskCpuLock();
  intCpuLock();
  intDisable(0x25);
  *(undefined4 *)(*DAT_30007aa0 + 0x114) = 1;
  cacheFlush(1,DAT_30007ad4,0x100000);
  *DAT_30007a54 = DAT_30007a58;
  *DAT_30007ac4 = 3;
  *DAT_30007ac0 = 10;
  *DAT_30007a54 = 0;
  WDT_Reboot();
  return;
}

/* ----------------------------------------------------------------
 * BSP_WDT_Stop @ 0x3000797C  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x3000797C
 * Данные: DAT_30007a54, DAT_30007a58, DAT_30007ac4
 * ---------------------------------------------------------------- */
void BSP_WDT_Stop(void)

{
  *DAT_30007a54 = DAT_30007a58;
  *DAT_30007ac4 = 0;
  *DAT_30007a54 = 0;
  return;
}

/* ----------------------------------------------------------------
 * BSP_WDT_Resume @ 0x300079A4  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x300079A4
 * Данные: DAT_30007a54, DAT_30007a58, DAT_30007ac4
 * ---------------------------------------------------------------- */
void BSP_WDT_Resume(void)

{
  *DAT_30007a54 = DAT_30007a58;
  *DAT_30007ac4 = 3;
  *DAT_30007a54 = 0;
  return;
}

/* ----------------------------------------------------------------
 * BSP_DRV_SubVicIntHandler @ 0x30007B04  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30007B04
 * ---------------------------------------------------------------- */
void BSP_DRV_SubVicIntHandler(void)

{
  return;
}

/* ----------------------------------------------------------------
 * BSP_DRV_SubVicInit @ 0x30007B08  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30007B08
 * ---------------------------------------------------------------- */
void BSP_DRV_SubVicInit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * BSP_INT_Enable @ 0x30007B0C  (примерный размер ~64 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: intEnable
 * Константы: 0x30007B0C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 BSP_INT_Enable(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0xa0) {
    if (param_1 < 0xa0) {
      uVar1 = intEnable(param_1);
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_INT_Disable @ 0x30007B4C  (примерный размер ~56 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: intDisable
 * Константы: 0x30007B4C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 BSP_INT_Disable(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0xa0) {
    if (param_1 < 0xa0) {
      uVar1 = intDisable(param_1);
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_INT_Connect @ 0x30007B84  (примерный размер ~72 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: intConnect
 * Вызывают: BSP_USRCLK_Init
 * Константы: 0x30007B84, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 BSP_INT_Connect(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0xa0) {
    if (param_1 < 0xa0) {
      uVar1 = intConnect(param_1,param_2,param_3);
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_INT_DisConnect @ 0x30007BCC  (примерный размер ~72 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: intDisconnect
 * Константы: 0x30007BCC, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 BSP_INT_DisConnect(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0xa0) {
    if (param_1 < 0xa0) {
      uVar1 = intDisconnect(param_1,param_2,param_3);
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_INT_Lock @ 0x30007C14  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30007C14
 * ---------------------------------------------------------------- */
longlong BSP_INT_Lock(void)

{
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  return (ulonglong)
         ((uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b | 0x80) <<
         0x20;
}

/* ----------------------------------------------------------------
 * BSP_INT_UnLock @ 0x30007C18  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: intCpuUnlock
 * Константы: 0x30007C18
 * ---------------------------------------------------------------- */
void BSP_INT_UnLock(undefined4 param_1)

{
  intCpuUnlock(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30007c30 @ 0x30007C30  (примерный размер ~708 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: armGicCtlInit
 * Константы: 0xFFFFFFFF, 0x30007C30
 * Данные: DAT_30008508, DAT_3000850c, DAT_30008510, DAT_30008514, DAT_30008518, DAT_3000851c, DAT_30008520, DAT_30008524
 * ---------------------------------------------------------------- */
undefined4 FUN_30007c30(void)

{
  uint uVar1;
  
  *(undefined4 *)(*DAT_30008508 + 0x1280) = DAT_3000850c;
  for (uVar1 = 0; uVar1 < 0x10; uVar1 = uVar1 + 4) {
    *(undefined4 *)(*DAT_30008508 + uVar1 + 0x1400) = DAT_30008510;
  }
  for (uVar1 = 0; uVar1 < 0x10; uVar1 = uVar1 + 0x10) {
    *(undefined4 *)(*DAT_30008508 + (uVar1 >> 4) * 4 + 0x1c00) = DAT_30008514;
  }
  for (uVar1 = 0x10; uVar1 < 0x20; uVar1 = uVar1 + 4) {
    *(undefined4 *)(*DAT_30008508 + uVar1 + 0x1400) = DAT_30008518;
  }
  *(undefined4 *)(*DAT_30008508 + 0x1000) = 0;
  for (uVar1 = 0x20; uVar1 < *DAT_3000851c; uVar1 = uVar1 + 0x20) {
    *(undefined4 *)(*DAT_30008508 + (uVar1 >> 5) * 4 + 0x1180) = 0xffffffff;
  }
  for (uVar1 = 0x20; uVar1 < *DAT_3000851c; uVar1 = uVar1 + 0x20) {
    *(undefined4 *)(*DAT_30008508 + (uVar1 >> 5) * 4 + 0x1280) = 0xffffffff;
  }
  for (uVar1 = 0x20; uVar1 < *DAT_3000851c; uVar1 = uVar1 + 4) {
    *(undefined4 *)(*DAT_30008508 + uVar1 + 0x1400) = *(undefined4 *)(DAT_30008520 + (uVar1 - 0x20))
    ;
    *(undefined4 *)(*DAT_30008508 + uVar1 + 0x1800) = *(undefined4 *)(DAT_30008524 + (uVar1 - 0x20))
    ;
  }
  for (uVar1 = 0x20; uVar1 < *DAT_3000851c; uVar1 = uVar1 + 0x10) {
    *(undefined4 *)(*DAT_30008508 + (uVar1 >> 4) * 4 + 0x1c00) = DAT_30008528;
  }
  *(uint *)(*DAT_30008508 + DAT_3000852c) = *(uint *)(*DAT_30008508 + DAT_3000852c) | 0xa0;
  *(uint *)(*DAT_30008508 + DAT_30008530) = *(uint *)(*DAT_30008508 + DAT_30008530) | 0x800;
  *(undefined4 *)(*DAT_30008508 + 0x104) = 0xff;
  *(undefined4 *)(*DAT_30008508 + 0x108) = 2;
  *(undefined4 *)(*DAT_30008508 + 0x100) = 1;
  *(undefined4 *)(*DAT_30008508 + 0x1000) = 1;
  return 0;
}

/* ----------------------------------------------------------------
 * TIMER_BASE @ 0x30008584  (примерный размер ~92 байт)
 * Модуль: bsp | Вызывают: 28 | Вызывает: 0
 * Вызывают: BSP_CLK_Value, BSP_USRCLK_Disable, BSP_USRCLK_Enable, BSP_USRCLK_TimerMilliSecStart, BSP_USRCLK_TimerStart, BSP_USRCLK_TimerStop, USRCLK_GetCurTimerValue, USRClkInt_Handle, softTimeClkInt, softtimer_interrupt_call_back
 *           ...
 * Константы: 0x30008584
 * Данные: DAT_300094ac, DAT_300094b0, DAT_300094b4
 * ---------------------------------------------------------------- */
int TIMER_BASE(int param_1)

{
  int iVar1;
  
  if (param_1 == 5) {
    iVar1 = 100 - DAT_300094ac;
  }
  else if (param_1 == 0) {
    iVar1 = -DAT_300094b0;
  }
  else {
    iVar1 = param_1 * 0x14 - DAT_300094b4;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * BSP_CLK_Connect @ 0x30008DD0  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: sysAuxClkConnect
 * Константы: 0x30008DD0
 * ---------------------------------------------------------------- */
void BSP_CLK_Connect(undefined4 param_1,undefined4 param_2)

{
  sysAuxClkConnect(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_CLK_Enable @ 0x30008DEC  (примерный размер ~84 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_TRACE, sysAuxClkEnable
 * Вызывают: BSP_CLK_RateSet
 * Константы: 0x30008DEC, 0xFFFFFFFF
 * Данные: DAT_30009830, DAT_30009aec, DAT_30009cf8
 * ---------------------------------------------------------------- */
undefined4 BSP_CLK_Enable(void)

{
  if (*DAT_30009cf8 == 0) {
    if (*DAT_30009830 != 0) {
      BSP_TRACE(4,1,DAT_30009aec);
      return 0xffffffff;
    }
    sysAuxClkEnable();
    *DAT_30009cf8 = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_CLK_Disable @ 0x30008E40  (примерный размер ~44 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: sysAuxClkDisable
 * Вызывают: BSP_CLK_RateSet
 * Константы: 0x30008E40
 * Данные: DAT_30009cf8
 * ---------------------------------------------------------------- */
undefined4 BSP_CLK_Disable(void)

{
  if (*DAT_30009cf8 != 0) {
    sysAuxClkDisable();
    *DAT_30009cf8 = 0;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_CLK_RateGet @ 0x30008E6C  (примерный размер ~12 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30008E6C
 * Данные: DAT_30009cfc
 * ---------------------------------------------------------------- */
undefined4 BSP_CLK_RateGet(void)

{
  return *DAT_30009cfc;
}

/* ----------------------------------------------------------------
 * BSP_CLK_RateSet @ 0x30008E78  (примерный размер ~140 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_CLK_Disable, BSP_CLK_Enable, BSP_TRACE
 * Константы: 0x30008E78, 0xFFFFFFFF
 * Данные: DAT_300096a0, DAT_30009ae8, DAT_30009bd4, DAT_30009cfc
 * ---------------------------------------------------------------- */
undefined4 BSP_CLK_RateSet(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_300096a0 < param_1 - 10U) {
    BSP_TRACE(4,1,DAT_30009bd4,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    *DAT_30009cfc = param_1;
    if (*DAT_30009ae8 != 0) {
      BSP_CLK_Disable();
      BSP_CLK_Enable();
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_CLK_Value @ 0x30008F04  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: TIMER_BASE, intCpuLock, intCpuUnlock
 * Константы: 0x30008F04
 * ---------------------------------------------------------------- */
undefined4 BSP_CLK_Value(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = intCpuLock();
  iVar2 = TIMER_BASE(0);
  uVar3 = *(undefined4 *)(iVar2 + 4);
  intCpuUnlock(uVar1);
  return uVar3;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_Init @ 0x30008F2C  (примерный размер ~120 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_INT_Connect, memset
 * Константы: 0x30008F2C
 * Данные: DAT_30009e38, DAT_30009e3c, DAT_30009e40, DAT_30009e44
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_Init(void)

{
  int iVar1;
  
  if (*DAT_30009e38 != 1) {
    memset(DAT_30009e3c,0,0x14);
    for (iVar1 = 0; iVar1 < 1; iVar1 = iVar1 + 1) {
      *(undefined4 *)(iVar1 * 0x14 + DAT_30009e40) = 100;
    }
    BSP_INT_Connect(0x53,DAT_30009e44,0);
    *DAT_30009e38 = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_Alloc @ 0x30008FA4  (примерный размер ~260 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Константы: 0x30008FA4
 * Данные: DAT_30009e38, DAT_30009e48, DAT_30009e4c, DAT_30009e50, DAT_30009e54, DAT_30009e58, DAT_30009e5c, DAT_30009e60
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_Alloc(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_30009e38 == 0) {
    BSP_TRACE(4,1,DAT_30009e48,DAT_30009e4c,0,3,4,5,6);
    uVar1 = DAT_30009e50;
  }
  else if (param_1 == (int *)0x0) {
    BSP_TRACE(4,1,DAT_30009e54,DAT_30009e58,0,3,4,5,6);
    uVar1 = DAT_30009e5c;
  }
  else {
    for (iVar2 = 0; uVar1 = DAT_30009ecc, iVar2 < 1; iVar2 = iVar2 + 1) {
      if (*(int *)(DAT_30009e60 + iVar2 * 0x14) == 0) {
        *param_1 = iVar2;
        *(undefined4 *)(iVar2 * 0x14 + DAT_30009e60) = 1;
        return 0;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_Free @ 0x300090A8  (примерный размер ~204 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Константы: 0x300090A8
 * Данные: DAT_30009e38, DAT_30009e48, DAT_30009e50, DAT_30009e54, DAT_30009e5c, DAT_30009e60, DAT_30009ed0
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_Free(int param_1)

{
  undefined4 uVar1;
  
  if (*DAT_30009e38 == 0) {
    BSP_TRACE(4,1,DAT_30009e48,0x4a0,0,3,4,5,6);
    uVar1 = DAT_30009e50;
  }
  else if (param_1 < 1) {
    *(undefined4 *)(param_1 * 0x14 + DAT_30009e60) = 0;
    uVar1 = 0;
  }
  else {
    BSP_TRACE(4,1,DAT_30009e54,DAT_30009ed0,0,3,4,5,6);
    uVar1 = DAT_30009e5c;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_Connect @ 0x30009248  (примерный размер ~136 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Константы: 0x30009248
 * Данные: DAT_30009e3c, DAT_30009e5c, DAT_30009ed8, DAT_30009edc, DAT_30009ee0
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_Connect(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 < 1) {
    *(undefined4 *)(DAT_30009e3c + param_3 * 0x14) = param_1;
    *(undefined4 *)(DAT_30009ed8 + param_3 * 0x14) = param_2;
    uVar1 = 0;
  }
  else {
    BSP_TRACE(4,1,DAT_30009edc,DAT_30009ee0,0,param_3,4,5,6);
    uVar1 = DAT_30009e5c;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_Disable @ 0x300092F4  (примерный размер ~260 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: BSP_TRACE, TIMER_BASE, USRCLK_GetClkNum
 * Вызывают: BSP_USRCLK_RateSet
 * Константы: 0x300092F4
 * Данные: DAT_30009e38, DAT_30009e48, DAT_30009e50, DAT_30009e54, DAT_30009e5c, DAT_30009ee4, DAT_30009ee8, DAT_30009eec
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_Disable(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  if (*DAT_30009e38 == 0) {
    BSP_TRACE(4,1,DAT_30009e48,DAT_30009ee4,0,3,4,5,6);
    uVar2 = DAT_30009e50;
  }
  else if (param_1 < 1) {
    USRCLK_GetClkNum(param_1,&local_c);
    if (*(int *)(DAT_30009eec + param_1 * 0x14) != 0) {
      iVar1 = TIMER_BASE(local_c);
      *(undefined4 *)(iVar1 + 8) = 6;
      *(undefined4 *)(param_1 * 0x14 + DAT_30009eec) = 0;
    }
    uVar2 = 0;
  }
  else {
    BSP_TRACE(4,1,DAT_30009e54,DAT_30009ee8,0,3,4,5,6);
    uVar2 = DAT_30009e5c;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_Enable @ 0x300093F8  (примерный размер ~488 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 5
 * Вызывает: BSP_TRACE, TIMER_BASE, USRCLK_GetClkNum, __div32, intEnable
 * Вызывают: BSP_USRCLK_RateSet
 * Константы: 0x300093F8, 0xFFFFFFFF
 * Данные: DAT_30009584, DAT_30009698, DAT_30009e38, DAT_30009e40, DAT_30009e48, DAT_30009e50, DAT_30009e54, DAT_30009e5c
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_Enable(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 local_1c;
  
  uVar4 = 0;
  if (*DAT_30009e38 == 0) {
    BSP_TRACE(4,1,DAT_30009e48,DAT_30009ef0,0,3,4,5,6);
    uVar2 = DAT_30009e50;
  }
  else if (param_1 < 1) {
    USRCLK_GetClkNum(param_1,&local_1c);
    if (*(int *)(DAT_30009eec + param_1 * 0x14) == 0) {
      iVar1 = TIMER_BASE(local_1c);
      *(undefined4 *)(iVar1 + 8) = 6;
      uVar2 = __div32(DAT_30009584,*(undefined4 *)(DAT_30009e40 + param_1 * 0x14));
      puVar3 = (undefined4 *)TIMER_BASE(local_1c);
      *puVar3 = uVar2;
      do {
        iVar1 = TIMER_BASE(local_1c);
        uVar4 = uVar4 + 1;
        if ((*(uint *)(iVar1 + 8) & 0x10) != 0) break;
      } while (uVar4 < 100);
      if (uVar4 == 100) {
        BSP_TRACE(4,1,DAT_30009698);
        return 0xffffffff;
      }
      iVar1 = TIMER_BASE(local_1c);
      *(undefined4 *)(iVar1 + 8) = 3;
      if (*DAT_30009ef8 == 0) {
        intEnable(0x53);
        *DAT_30009ef8 = 1;
      }
      *(undefined4 *)(param_1 * 0x14 + DAT_30009eec) = 1;
    }
    uVar2 = 0;
  }
  else {
    BSP_TRACE(4,1,DAT_30009e54,DAT_30009ef4,0,3,4,5,6);
    uVar2 = DAT_30009e5c;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_RateGet @ 0x300095E0  (примерный размер ~232 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Константы: 0x300095E0
 * Данные: DAT_30009e38, DAT_30009e40, DAT_30009e48, DAT_30009e50, DAT_30009e54, DAT_30009e5c, DAT_30009efc, DAT_30009f00
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_RateGet(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*DAT_30009e38 == 0) {
    BSP_TRACE(4,1,DAT_30009e48,DAT_30009efc,0,3,4,5,6);
    uVar1 = DAT_30009e50;
  }
  else if ((param_1 < 1) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(DAT_30009e40 + param_1 * 0x14);
    uVar1 = 0;
  }
  else {
    BSP_TRACE(4,1,DAT_30009e54,DAT_30009f00,0,3,4,5,6);
    uVar1 = DAT_30009e5c;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_RateSet @ 0x300096C8  (примерный размер ~268 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, BSP_USRCLK_Disable, BSP_USRCLK_Enable
 * Константы: 0x300096C8
 * Данные: DAT_30009e38, DAT_30009e40, DAT_30009e48, DAT_30009e50, DAT_30009e54, DAT_30009e5c, DAT_30009eec, DAT_30009f04
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_RateSet(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*DAT_30009e38 == 0) {
    BSP_TRACE(4,1,DAT_30009e48,DAT_30009f04,0,3,4,5,6);
    uVar1 = DAT_30009e50;
  }
  else if (param_2 < 1) {
    uVar1 = DAT_30009e5c;
    if (param_1 - 1U <= DAT_30009f0c) {
      *(int *)(DAT_30009e40 + param_2 * 0x14) = param_1;
      if (*(int *)(DAT_30009eec + param_2 * 0x14) != 0) {
        BSP_USRCLK_Disable(param_2);
        BSP_USRCLK_Enable(param_2);
      }
      uVar1 = 0;
    }
  }
  else {
    BSP_TRACE(4,1,DAT_30009e54,DAT_30009f08,0,3,4,5,6);
    uVar1 = DAT_30009e5c;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_TimerStart @ 0x300097D4  (примерный размер ~444 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, TIMER_BASE, USRCLK_GetClkNum
 * Константы: 0x300097D4, 0xFFFFFFFF
 * Данные: DAT_30009e38, DAT_30009e48, DAT_30009e50, DAT_30009e54, DAT_30009e5c, DAT_30009f10, DAT_30009f14, DAT_30009f18
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_TimerStart(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_1c;
  
  uVar4 = 0;
  if (*DAT_30009e38 == 0) {
    BSP_TRACE(4,1,DAT_30009e48,DAT_30009f10,0,3,4,5,6);
    uVar3 = DAT_30009e50;
  }
  else if (param_1 < 1) {
    if (param_2 == 0) {
      BSP_TRACE(4,1,DAT_30009f18,DAT_30009f1c,0,3,4,5,6);
      uVar3 = DAT_30009e5c;
    }
    else {
      USRCLK_GetClkNum(param_1,&local_1c);
      iVar1 = TIMER_BASE(local_1c);
      *(undefined4 *)(iVar1 + 8) = 6;
      piVar2 = (int *)TIMER_BASE(local_1c);
      *piVar2 = param_2;
      do {
        iVar1 = TIMER_BASE(local_1c);
        uVar4 = uVar4 + 1;
        if ((*(uint *)(iVar1 + 8) & 0x10) != 0) break;
      } while (uVar4 < 100);
      if (uVar4 == 100) {
        BSP_TRACE(4,1,DAT_30009f20);
        uVar3 = 0xffffffff;
      }
      else {
        iVar1 = TIMER_BASE(local_1c);
        *(undefined4 *)(iVar1 + 8) = 3;
        uVar3 = 0;
      }
    }
  }
  else {
    BSP_TRACE(4,1,DAT_30009e54,DAT_30009f14,0,3,4,5,6);
    uVar3 = DAT_30009e5c;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_TimerStop @ 0x30009990  (примерный размер ~240 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, TIMER_BASE, USRCLK_GetClkNum
 * Константы: 0x30009990
 * Данные: DAT_30009e38, DAT_30009e48, DAT_30009e50, DAT_30009e54, DAT_30009e5c, DAT_30009f24, DAT_30009f28
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_TimerStop(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  if (*DAT_30009e38 == 0) {
    BSP_TRACE(4,1,DAT_30009e48,DAT_30009f24,0,3,4,5,6);
    uVar2 = DAT_30009e50;
  }
  else if (param_1 < 1) {
    USRCLK_GetClkNum(param_1,&local_c);
    iVar1 = TIMER_BASE(local_c);
    *(undefined4 *)(iVar1 + 8) = 6;
    uVar2 = 0;
  }
  else {
    BSP_TRACE(4,1,DAT_30009e54,DAT_30009f28,0,3,4,5,6);
    uVar2 = DAT_30009e5c;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_TimerValue @ 0x30009A80  (примерный размер ~240 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, USRCLK_GetClkNum, USRCLK_GetCurTimerValue
 * Константы: 0x30009A80
 * Данные: DAT_30009e38, DAT_30009e48, DAT_30009e54, DAT_30009f2c
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_TimerValue(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_10;
  
  if (*DAT_30009e38 == 0) {
    BSP_TRACE(4,1,DAT_30009e48,DAT_30009f2c,0,3,4,5,6);
  }
  else if ((param_1 < 1) && (param_2 != (undefined4 *)0x0)) {
    USRCLK_GetClkNum(param_1,&local_10);
    uVar1 = USRCLK_GetCurTimerValue(local_10);
    *param_2 = uVar1;
  }
  else {
    BSP_TRACE(4,1,DAT_30009e54,0x630,0,3,4,5,6);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_TimerMilliSecStart @ 0x30009B70  (примерный размер ~348 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, TIMER_BASE, USRCLK_GetClkNum
 * Константы: 0x30009B70
 * Данные: DAT_30009e38, DAT_30009e48, DAT_30009e50, DAT_30009e54, DAT_30009e5c, DAT_30009f30, DAT_30009f34, DAT_30009f38
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_TimerMilliSecStart(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 local_14;
  
  if (*DAT_30009e38 == 0) {
    BSP_TRACE(4,1,DAT_30009e48,DAT_30009f30,0,3,4,5,6);
    uVar3 = DAT_30009e50;
  }
  else if (param_1 < 1) {
    if ((DAT_30009f38 < param_2) || (param_2 == 0)) {
      BSP_TRACE(4,1,DAT_30009f3c,DAT_30009f40,0,param_2,4,5,6);
      uVar3 = DAT_30009e5c;
    }
    else {
      USRCLK_GetClkNum(param_1,&local_14);
      iVar1 = TIMER_BASE(local_14);
      *(undefined4 *)(iVar1 + 8) = 6;
      piVar2 = (int *)TIMER_BASE(local_14);
      *piVar2 = param_2 * 0x4b00;
      iVar1 = TIMER_BASE(local_14);
      *(undefined4 *)(iVar1 + 8) = 3;
      uVar3 = 0;
    }
  }
  else {
    BSP_TRACE(4,1,DAT_30009e54,DAT_30009f34,0,3,4,5,6);
    uVar3 = DAT_30009e5c;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_TimerMilliSecValue @ 0x30009CCC  (примерный размер ~260 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, USRCLK_GetClkNum, USRCLK_GetCurTimerValue
 * Константы: 0x30009CCC
 * Данные: DAT_30009e38, DAT_30009e48, DAT_30009e54, DAT_30009f44, DAT_30009f48
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_TimerMilliSecValue(int param_1,uint *param_2)

{
  uint uVar1;
  undefined4 local_14;
  
  if (*DAT_30009e38 == 0) {
    BSP_TRACE(4,1,DAT_30009e48,0x680,0,3,4,5,6);
  }
  else if ((param_1 < 1) && (param_2 != (uint *)0x0)) {
    USRCLK_GetClkNum(param_1,&local_14);
    uVar1 = USRCLK_GetCurTimerValue(local_14);
    *param_2 = (uint)((ulonglong)DAT_30009f48 * (ulonglong)uVar1 >> 0x2b);
  }
  else {
    BSP_TRACE(4,1,DAT_30009e54,DAT_30009f44,0,3,4,5,6);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_USRCLK_TimerStart_ID @ 0x30009DD0  (примерный размер ~384 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Константы: 0x30009DD0, 0xFFFFFFFF
 * Данные: DAT_30009e5c, DAT_30009f18, DAT_30009f20, DAT_30009f4c
 * ---------------------------------------------------------------- */
undefined4 BSP_USRCLK_TimerStart_ID(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 == 0) {
    BSP_TRACE(4,1,DAT_30009f18,DAT_30009f4c,0,3,4,5,6);
    uVar1 = DAT_30009e5c;
  }
  else {
    param_1[2] = 6;
    *param_1 = param_2;
    do {
      uVar2 = uVar2 + 1;
      if ((param_1[2] & 0x10U) != 0) break;
    } while (uVar2 < 100);
    if (uVar2 == 100) {
      BSP_TRACE(4,1,DAT_30009f20);
      uVar1 = 0xffffffff;
    }
    else {
      param_1[2] = param_3;
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * softtimer_interrupt_call_back @ 0x30009F50  (примерный размер ~52 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: TIMER_BASE, semGive
 * Константы: 0x30009F50
 * Данные: DAT_3000aebc
 * ---------------------------------------------------------------- */
void softtimer_interrupt_call_back(void)

{
  int iVar1;
  
  iVar1 = TIMER_BASE(1);
  if (*(int *)(iVar1 + 0x10) != 0) {
    TIMER_BASE(1);
    semGive(*DAT_3000aebc);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30009f84 @ 0x30009F84  (примерный размер ~756 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 9
 * Вызывает: BSP_TRACE, free, intConnect, intEnable, logMsg, malloc, memset, semBCreate, taskSpawn
 * Вызывают: softtimer_module_start
 * Константы: 0x30009F84, 0xFFFFFFFF
 * Данные: DAT_3000aebc, DAT_3000aec0, DAT_3000aec4, DAT_3000aec8, DAT_3000aecc, DAT_3000aed0, DAT_3000aed4, DAT_3000b0ac
 * ---------------------------------------------------------------- */
undefined4 FUN_30009f84(uint param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  *DAT_3000aec0 = param_1;
  *DAT_3000aec4 = param_1;
  pvVar1 = malloc(*DAT_3000aec0 * 0x30);
  *DAT_3000aec8 = (int)pvVar1;
  if (*DAT_3000aec8 == 0) {
    uVar2 = 1;
  }
  else {
    memset((void *)*DAT_3000aec8,0,*DAT_3000aec0 * 0x30);
    *DAT_3000aecc = *DAT_3000aec8;
    *DAT_3000aed0 = *DAT_3000aec8;
    *DAT_3000aed4 = *DAT_3000aec8 + *DAT_3000aec0 * 0x30;
    for (uVar4 = 0; uVar4 < *DAT_3000aec0; uVar4 = uVar4 + 1) {
      *(undefined4 *)(uVar4 * 0x30 + *DAT_3000aec8 + 4) = 0;
      *(uint *)(*DAT_3000aec8 + uVar4 * 0x30) = uVar4;
      *(undefined4 *)(uVar4 * 0x30 + *DAT_3000aec8 + 0x10) = 0;
      *(undefined4 *)(uVar4 * 0x30 + *DAT_3000aec8 + 0xc) = 0;
      *(undefined4 *)(uVar4 * 0x30 + *DAT_3000aec8 + 0x20) = 0;
      *(uint *)(uVar4 * 0x30 + *DAT_3000aec8 + 0x1c) = *DAT_3000aec8 + uVar4 * 0x30 + 0x30;
    }
    *(undefined4 *)(*DAT_3000aec0 * 0x30 + *DAT_3000aec8 + -0x14) = 0;
    *DAT_3000b0ac = *DAT_3000aec0;
    iVar3 = semBCreate(1,0);
    *DAT_3000aebc = iVar3;
    if (*DAT_3000aebc == 0) {
      logMsg(DAT_3000b0b0,0,0,0,0,0,0);
      free((void *)*DAT_3000aec8);
      uVar2 = 1;
    }
    else {
      iVar3 = taskSpawn(DAT_3000b0b8,0x32,0,0x2000,DAT_3000b0b4,0,0,0,0,0,0,0,0,0,0);
      *DAT_3000b0bc = iVar3;
      if (*DAT_3000b0bc == -1) {
        BSP_TRACE(4,1,DAT_3000b0c0,0,0,0,0,0,0);
        uVar2 = 0xffffffff;
      }
      else {
        intConnect(0x4e,DAT_3000b0c4,0);
        intEnable(0x4e);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * timer_load_set @ 0x3000A278  (примерный размер ~68 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Вызывают: FUN_3000a334
 * Константы: 0x3000A278
 * ---------------------------------------------------------------- */
void timer_load_set(undefined1 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar1 = (undefined4 *)TIMER_BASE(param_1);
  *puVar1 = param_2;
  do {
    iVar2 = TIMER_BASE(param_1);
    uVar3 = uVar3 + 1;
    if ((*(uint *)(iVar2 + 8) & 0x10) != 0) {
      return;
    }
  } while (uVar3 < 1000);
  return;
}

/* ----------------------------------------------------------------
 * timer_start @ 0x3000A2BC  (примерный размер ~92 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Вызывают: FUN_3000a334
 * Константы: 0x3000A2BC
 * ---------------------------------------------------------------- */
void timer_start(undefined1 param_1,int param_2)

{
  int iVar1;
  
  TIMER_BASE(param_1);
  if (param_2 == 0) {
    do {
      iVar1 = TIMER_BASE(param_1);
      *(undefined4 *)(iVar1 + 8) = 1;
      iVar1 = TIMER_BASE(param_1);
    } while ((*(uint *)(iVar1 + 8) & 1) == 0);
  }
  else {
    iVar1 = TIMER_BASE(param_1);
    *(undefined4 *)(iVar1 + 8) = 3;
  }
  return;
}

/* ----------------------------------------------------------------
 * timer_stop @ 0x3000A318  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Вызывают: FUN_3000a334, FUN_3000b300
 * Константы: 0x3000A318
 * ---------------------------------------------------------------- */
void timer_stop(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = TIMER_BASE(param_1);
  *(undefined4 *)(iVar1 + 8) = 6;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3000a334 @ 0x3000A334  (примерный размер ~76 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 3
 * Вызывает: timer_load_set, timer_start, timer_stop
 * Вызывают: FUN_3000a678, softtimer_task_func
 * Константы: 0x3000A334
 * Данные: DAT_3000b200
 * ---------------------------------------------------------------- */
void FUN_3000a334(uint param_1)

{
  *DAT_3000b200 = param_1;
  if (param_1 < 2) {
    param_1 = 2;
  }
  timer_stop(1);
  timer_load_set(1,param_1);
  timer_start(1,0);
  return;
}

/* ----------------------------------------------------------------
 * timer_value_get @ 0x3000A380  (примерный размер ~188 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_TRACE, TIMER_BASE
 * Вызывают: FUN_3000a43c
 * Константы: 0x3000A380
 * Данные: DAT_3000b204, DAT_3000b30c, DAT_3000b310, DAT_3000b314
 * ---------------------------------------------------------------- */
undefined4 timer_value_get(undefined1 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint unaff_r9;
  
  iVar1 = TIMER_BASE(param_1);
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 8;
  for (uVar3 = 0; uVar3 < DAT_3000b204; uVar3 = uVar3 + 1) {
    iVar1 = TIMER_BASE(param_1);
    unaff_r9 = *(uint *)(iVar1 + 8);
    if ((unaff_r9 & 8) == 0) break;
  }
  if ((unaff_r9 & 8) == 0) {
    iVar1 = TIMER_BASE(param_1);
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
  else {
    BSP_TRACE(4,1,DAT_3000b310,DAT_3000b314,DAT_3000b30c,param_1,4,5,6);
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3000a43c @ 0x3000A43C  (примерный размер ~88 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: timer_value_get
 * Вызывают: FUN_3000a678
 * Константы: 0x3000A43C, 0xFFFFFFFF
 * Данные: DAT_3000b200
 * ---------------------------------------------------------------- */
int FUN_3000a43c(void)

{
  int iVar1;
  uint uVar2;
  
  if (*DAT_3000b200 == 0xffffffff) {
    iVar1 = 0;
  }
  else {
    uVar2 = timer_value_get(1);
    if (uVar2 < *DAT_3000b200) {
      iVar1 = *DAT_3000b200 - uVar2;
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3000a494 @ 0x3000A494  (примерный размер ~216 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: FUN_3000a7c8
 * Константы: 0x3000A494
 * Данные: DAT_3000aec4, DAT_3000aecc, DAT_3000b0ac, DAT_3000b318
 * ---------------------------------------------------------------- */
int FUN_3000a494(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*DAT_3000aec4 == 0) {
    logMsg(DAT_3000b318,0,0,0,0,0,0);
    iVar1 = 0;
  }
  else {
    *DAT_3000aec4 = *DAT_3000aec4 - 1;
    iVar1 = *DAT_3000aecc;
    *(undefined4 *)(iVar1 + 4) = 1;
    *DAT_3000aecc = *(int *)(*DAT_3000aecc + 0x1c);
    if (*DAT_3000aec4 < *DAT_3000b0ac) {
      *DAT_3000b0ac = *DAT_3000aec4;
    }
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x28) = param_1;
    *(undefined4 *)(iVar1 + 0x2c) = param_2;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3000a56c @ 0x3000A56C  (примерный размер ~72 байт)
 * Модуль: bsp | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_3000a5b4, softtimer_create_timer, softtimer_del_timer
 * Константы: 0x3000A56C
 * Данные: DAT_3000aec4, DAT_3000aecc
 * ---------------------------------------------------------------- */
void FUN_3000a56c(int param_1,undefined1 param_2)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 0x25) = param_2;
  *(int *)(param_1 + 0x1c) = *DAT_3000aecc;
  *DAT_3000aecc = param_1;
  *DAT_3000aec4 = *DAT_3000aec4 + 1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3000a5b4 @ 0x3000A5B4  (примерный размер ~196 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3000a56c, logMsg
 * Вызывают: FUN_3000a914
 * Константы: 0x3000A5B4
 * Данные: DAT_3000aed0, DAT_3000aed4, DAT_3000b330, DAT_3000b334
 * ---------------------------------------------------------------- */
undefined4 FUN_3000a5b4(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_1 < *DAT_3000aed0) || (*DAT_3000aed4 < param_1)) {
    logMsg(DAT_3000b330,0,0,0,0,0,0);
    uVar1 = 1;
  }
  else if (*(int *)(param_1 + 4) == 0) {
    logMsg(DAT_3000b334,*(undefined1 *)(param_1 + 0x25),param_2 & 0xff,0,0,0,0);
    uVar1 = 3;
  }
  else {
    FUN_3000a56c(param_1,param_2);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3000a678 @ 0x3000A678  (примерный размер ~252 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3000a334, FUN_3000a43c
 * Вызывают: FUN_3000a7c8
 * Константы: 0x3000A678
 * Данные: DAT_3000b338
 * ---------------------------------------------------------------- */
void FUN_3000a678(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  if (*DAT_3000b338 == 0) {
    *DAT_3000b338 = param_1;
  }
  else {
    iVar1 = FUN_3000a43c();
    *(int *)(param_1 + 0x18) = iVar1 + *(int *)(param_1 + 0x18);
    iVar2 = *DAT_3000b338;
    for (iVar3 = *DAT_3000b338;
        (iVar3 != 0 && (*(uint *)(iVar3 + 0x18) <= *(uint *)(param_1 + 0x18)));
        iVar3 = *(int *)(iVar3 + 0x1c)) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - *(int *)(iVar3 + 0x18);
      iVar2 = iVar3;
    }
    if (*DAT_3000b338 == iVar3) {
      *(int *)(param_1 + 0x1c) = *DAT_3000b338;
      *DAT_3000b338 = param_1;
    }
    else {
      *(int *)(param_1 + 0x1c) = iVar3;
      *(int *)(iVar2 + 0x1c) = param_1;
      *(int *)(param_1 + 0x20) = iVar2;
    }
    if (iVar3 != 0) {
      *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) - *(int *)(param_1 + 0x18);
      *(int *)(iVar3 + 0x20) = param_1;
    }
  }
  if (*DAT_3000b338 == param_1) {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - iVar1;
    FUN_3000a334(*(undefined4 *)(param_1 + 0x18));
  }
  return;
}

/* ----------------------------------------------------------------
 * timer_input_clk_get @ 0x3000A774  (примерный размер ~84 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3000a7c8
 * Константы: 0x3000A774, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 timer_input_clk_get(char param_1)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    uVar1 = 0x8000;
  }
  else if (param_1 == '\x01') {
    uVar1 = 0x8000;
  }
  else if ((param_1 == '\x02') || (param_1 == '\x03')) {
    uVar1 = 0x8000;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3000a7c8 @ 0x3000A7C8  (примерный размер ~256 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 5
 * Вызывает: FUN_3000a494, FUN_3000a678, __udiv32, logMsg, timer_input_clk_get
 * Вызывают: FUN_3000a8c8, softtimer_create_timer
 * Константы: 0x3000A7C8, 0xFFFFFFFF
 * Данные: DAT_3000b33c, DAT_3000b340
 * ---------------------------------------------------------------- */
void FUN_3000a7c8(undefined4 param_1,uint param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  iVar2 = FUN_3000a494(param_6,param_7);
  if (iVar2 == 0) {
    logMsg(DAT_3000b33c,0,0,0,0,0,0);
  }
  else {
    *(undefined4 *)(iVar2 + 8) = param_5;
    *(undefined1 *)(iVar2 + 0x24) = param_3;
    *(undefined4 *)(iVar2 + 0x10) = param_1;
    *(uint *)(iVar2 + 0x14) = param_2;
    uVar3 = timer_input_clk_get(1);
    uVar4 = __udiv32(0xffffffff,uVar3);
    if (param_2 < uVar4) {
      uVar6 = timer_input_clk_get(1);
      uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
      lVar1 = (ulonglong)DAT_3000b340 * (ulonglong)(param_2 * (int)uVar6);
      uVar5 = (undefined4)lVar1;
      *(uint *)(iVar2 + 0x18) = (uint)((ulonglong)lVar1 >> 0x26);
    }
    else {
      uVar6 = timer_input_clk_get(1);
      uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
      uVar5 = (undefined4)((ulonglong)DAT_3000b340 * (ulonglong)param_2);
      *(uint *)(iVar2 + 0x18) =
           (uint)((ulonglong)DAT_3000b340 * (ulonglong)param_2 >> 0x26) * (int)uVar6;
    }
    *(undefined4 *)(iVar2 + 0xc) = param_4;
    **(int **)(iVar2 + 0x10) = iVar2;
    FUN_3000a678(iVar2,uVar3,uVar5);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3000a8c8 @ 0x3000A8C8  (примерный размер ~76 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3000a7c8
 * Вызывают: softtimer_task_func
 * Константы: 0x3000A8C8
 * ---------------------------------------------------------------- */
void FUN_3000a8c8(int param_1)

{
  if (*(char *)(param_1 + 0x24) == '\x01') {
    FUN_3000a7c8(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                 *(undefined1 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0xc),
                 *(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x28),
                 *(undefined4 *)(param_1 + 0x2c));
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3000a914 @ 0x3000A914  (примерный размер ~68 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3000a5b4
 * Вызывают: softtimer_task_func
 * Константы: 0x3000A914
 * ---------------------------------------------------------------- */
void FUN_3000a914(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    (**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 8));
    iVar1 = *(int *)(param_1 + 0x1c);
    FUN_3000a5b4(param_1,1);
    param_1 = iVar1;
  }
  return;
}

/* ----------------------------------------------------------------
 * softtimer_task_func @ 0x3000A958  (примерный размер ~384 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 7
 * Вызывает: BSP_TRACE, FUN_3000a334, FUN_3000a8c8, FUN_3000a914, intCpuLock, intCpuUnlock, semTake
 * Константы: 0x3000A958, 0xFFFFFFFF
 * Данные: DAT_3000aebc, DAT_3000aec0, DAT_3000b200, DAT_3000b338, DAT_3000b344
 * ---------------------------------------------------------------- */
void softtimer_task_func(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = 0;
  do {
    while( true ) {
      semTake(*DAT_3000aebc,0xffffffff);
      uVar1 = intCpuLock();
      iVar2 = *DAT_3000b200;
      *DAT_3000b200 = -1;
      iVar6 = *DAT_3000b338;
      if (iVar6 != 0) break;
      intCpuUnlock(uVar1);
    }
    *(int *)(iVar6 + 0x18) = *(int *)(iVar6 + 0x18) - iVar2;
    uVar3 = 0;
    iVar2 = 0;
    while ((iVar6 != 0 && (*(int *)(iVar6 + 0x18) == 0))) {
      uVar3 = uVar3 + 1;
      if (*DAT_3000aec0 < uVar3) {
        intCpuUnlock(uVar1);
        BSP_TRACE(1,4,DAT_3000b344,500,0,0,0,0,0);
        return;
      }
      **(undefined4 **)(iVar6 + 0x10) = 0;
      FUN_3000a8c8(iVar6);
      iVar7 = *(int *)(iVar6 + 0x1c);
      *(undefined4 *)(iVar6 + 0x1c) = 0;
      iVar5 = iVar6;
      if ((iVar2 != 0) && (iVar5 = iVar2, iVar4 != 0)) {
        *(int *)(iVar4 + 0x1c) = iVar6;
      }
      *DAT_3000b338 = iVar7;
      iVar4 = iVar6;
      iVar2 = iVar5;
      iVar6 = iVar7;
    }
    if (*DAT_3000b338 != 0) {
      *(undefined4 *)(*DAT_3000b338 + 0x20) = 0;
      FUN_3000a334(*(undefined4 *)(*DAT_3000b338 + 0x18));
    }
    FUN_3000a914(iVar2);
    intCpuUnlock(uVar1);
  } while( true );
}

/* ----------------------------------------------------------------
 * softtimer_module_start @ 0x3000AAD8  (примерный размер ~248 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_30009f84, free, logMsg, semDelete, taskSpawn
 * Вызывают: softtimer_create_timer
 * Константы: 0x3000AAD8
 * Данные: DAT_3000aebc, DAT_3000aec8, DAT_3000b0b4, DAT_3000b348, DAT_3000b34c, DAT_3000b350
 * ---------------------------------------------------------------- */
undefined4 softtimer_module_start(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_30009f84(0x28);
  if (iVar1 == 1) {
    logMsg(DAT_3000b348,0,0,0,0,0,0);
    uVar2 = 1;
  }
  else {
    iVar1 = taskSpawn(DAT_3000b34c,6,0,0x1000,DAT_3000b0b4,0,0,0,0,0,0,0,0,0,0);
    if (iVar1 == -1) {
      semDelete(*DAT_3000aebc);
      free((void *)*DAT_3000aec8);
      uVar2 = 1;
    }
    else {
      *DAT_3000b350 = 1;
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3000abd0 @ 0x3000ABD0  (примерный размер ~240 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: softtimer_create_timer, softtimer_del_timer
 * Константы: 0x3000ABD0
 * Данные: DAT_3000aec0, DAT_3000aec8, DAT_3000aed0, DAT_3000aed4, DAT_3000b354, DAT_3000b358
 * ---------------------------------------------------------------- */
undefined4 FUN_3000abd0(uint *param_1,uint *param_2)

{
  uint uVar1;
  
  if ((*param_1 < *DAT_3000aed0) || (*DAT_3000aed4 <= *param_1)) {
    logMsg(DAT_3000b358,0,0,0,0,0,0);
  }
  else {
    uVar1 = *(uint *)*param_1;
    if (*DAT_3000aec0 - 1U < uVar1) {
      logMsg(DAT_3000b354,0,0,0,0,0,0);
    }
    else if (*(uint **)(*DAT_3000aec8 + uVar1 * 0x30 + 0x10) == param_1) {
      *param_2 = uVar1;
      return 0;
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3000acc0 @ 0x3000ACC0  (примерный размер ~172 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_3000b300
 * Вызывают: softtimer_create_timer, softtimer_del_timer
 * Константы: 0x3000ACC0
 * Данные: DAT_3000b338
 * ---------------------------------------------------------------- */
void FUN_3000acc0(int param_1)

{
  int *piVar1;
  
  if (*DAT_3000b338 == param_1) {
    *DAT_3000b338 = *(int *)(param_1 + 0x1c);
    if (*DAT_3000b338 != 0) {
      *(undefined4 *)(*DAT_3000b338 + 0x20) = 0;
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
    if (*(int *)(param_1 + 0x1c) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x20) = *(undefined4 *)(param_1 + 0x20);
    }
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0x1c) + 0x18);
    *piVar1 = *piVar1 + *(int *)(param_1 + 0x18);
  }
  if (*DAT_3000b338 == 0) {
    FUN_3000b300();
  }
  return;
}

/* ----------------------------------------------------------------
 * softtimer_del_timer @ 0x3000AD6C  (примерный размер ~428 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_3000a56c, FUN_3000abd0, FUN_3000acc0, intCpuLock, intCpuUnlock, logMsg
 * Вызывают: BSP_TLED_LedTask
 * Константы: 0x3000AD6C
 * Данные: DAT_3000aec8, DAT_3000b350, DAT_3000b35c, DAT_3000b360, DAT_3000b364, DAT_3000b368
 * ---------------------------------------------------------------- */
undefined4 softtimer_del_timer(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_1c;
  
  if (*DAT_3000b350 == '\0') {
    logMsg(DAT_3000b35c,0,0,0,0,0,0);
    uVar1 = 1;
  }
  else if (*param_1 == 0) {
    logMsg(DAT_3000b360,0,0,0,0,0,0);
    uVar1 = 2;
  }
  else {
    uVar1 = intCpuLock();
    iVar2 = FUN_3000abd0(param_1,&local_1c,param_2,param_3);
    if (iVar2 == 0) {
      iVar2 = *DAT_3000aec8 + local_1c * 0x30;
      if (*(int *)(iVar2 + 4) == 1) {
        FUN_3000acc0(iVar2);
        **(undefined4 **)(iVar2 + 0x10) = 0;
        FUN_3000a56c(iVar2,2);
        intCpuUnlock(uVar1);
        uVar1 = 0;
      }
      else {
        logMsg(DAT_3000b368,0,0,0,0,0,0);
        intCpuUnlock(uVar1);
        uVar1 = 2;
      }
    }
    else {
      intCpuUnlock(uVar1);
      logMsg(DAT_3000b364,*param_1,0,0,0,0,0);
      uVar1 = 2;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * softtimer_create_timer @ 0x3000AF30  (примерный размер ~332 байт)
 * Модуль: bsp | Вызывают: 5 | Вызывает: 8
 * Вызывает: FUN_3000a56c, FUN_3000a7c8, FUN_3000abd0, FUN_3000acc0, intCpuLock, intCpuUnlock, logMsg, softtimer_module_start
 * Вызывают: BSP_TLED_LedInit, BSP_TLED_LedTask, ST_TST_LOOP, ST_TST_NOLOOP, drv_sleep
 * Константы: 0x3000AF30
 * Данные: DAT_3000b350, DAT_3000b35c, DAT_3000b36c, DAT_3000b370
 * ---------------------------------------------------------------- */
undefined4
softtimer_create_timer
          (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int local_28;
  
  if (*DAT_3000b350 == '\0') {
    logMsg(DAT_3000b35c,0,0,0,0,0,0);
    softtimer_module_start();
  }
  if (param_4 == 0) {
    logMsg(DAT_3000b36c,0,0,0,0,0,0);
    uVar1 = 1;
  }
  else {
    uVar1 = intCpuLock();
    if (((*param_1 != 0) && (iVar2 = FUN_3000abd0(param_1,&local_28,param_6,param_7), iVar2 == 0))
       && (iVar2 = *DAT_3000b370 + local_28 * 0x30, *(int *)(iVar2 + 4) == 1)) {
      FUN_3000acc0(iVar2);
      **(undefined4 **)(iVar2 + 0x10) = 0;
      FUN_3000a56c(iVar2,2);
    }
    FUN_3000a7c8(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    intCpuUnlock(uVar1);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * softtimer_show_used_info @ 0x3000B180  (примерный размер ~152 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: intCpuLock, intCpuUnlock, logMsg
 * Константы: 0x3000B180
 * Данные: DAT_3000b338, DAT_3000b378, DAT_3000b37c
 * ---------------------------------------------------------------- */
void softtimer_show_used_info(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  logMsg(DAT_3000b378,0,0,0,0,0,0);
  uVar1 = intCpuLock();
  for (puVar2 = (undefined4 *)*DAT_3000b338; puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)puVar2[7]) {
    logMsg(DAT_3000b37c,*puVar2,puVar2[1],*(undefined1 *)(puVar2 + 9),puVar2[3],puVar2[5],puVar2[6])
    ;
  }
  intCpuUnlock(uVar1);
  return;
}

/* ----------------------------------------------------------------
 * timer_load_get @ 0x3000B218  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Константы: 0x3000B218
 * ---------------------------------------------------------------- */
undefined4 timer_load_get(undefined1 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)TIMER_BASE(param_1);
  return *puVar1;
}

/* ----------------------------------------------------------------
 * timer_int_mask @ 0x3000B234  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Константы: 0x3000B234
 * ---------------------------------------------------------------- */
void timer_int_mask(undefined1 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = TIMER_BASE(param_1);
  uVar2 = *(uint *)(iVar1 + 8);
  iVar1 = TIMER_BASE(param_1);
  *(uint *)(iVar1 + 8) = uVar2 | 4;
  return;
}

/* ----------------------------------------------------------------
 * timer_int_unmask @ 0x3000B25C  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Константы: 0x3000B25C
 * ---------------------------------------------------------------- */
void timer_int_unmask(undefined1 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = TIMER_BASE(param_1);
  uVar2 = *(uint *)(iVar1 + 8);
  iVar1 = TIMER_BASE(param_1);
  *(uint *)(iVar1 + 8) = uVar2 | 1;
  return;
}

/* ----------------------------------------------------------------
 * timer_int_clear @ 0x3000B284  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Константы: 0x3000B284
 * ---------------------------------------------------------------- */
void timer_int_clear(undefined1 param_1)

{
  TIMER_BASE(param_1);
  return;
}

/* ----------------------------------------------------------------
 * timer_int_status_get @ 0x3000B29C  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Константы: 0x3000B29C
 * ---------------------------------------------------------------- */
uint timer_int_status_get(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = TIMER_BASE(param_1);
  return *(uint *)(iVar1 + 0x10) & 1;
}

/* ----------------------------------------------------------------
 * timer_raw_int_status_get @ 0x3000B2B8  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Константы: 0x3000B2B8
 * ---------------------------------------------------------------- */
uint timer_raw_int_status_get(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = TIMER_BASE(param_1);
  return *(uint *)(iVar1 + 0xa8) & 1;
}

/* ----------------------------------------------------------------
 * timer_32bit_count_set @ 0x3000B2D4  (примерный размер ~44 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: TIMER_BASE
 * Константы: 0x3000B2D4
 * ---------------------------------------------------------------- */
void timer_32bit_count_set(undefined1 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = TIMER_BASE(param_1);
  uVar2 = *(uint *)(iVar1 + 8);
  iVar1 = TIMER_BASE(param_1);
  *(uint *)(iVar1 + 8) = uVar2 | 2;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3000b300 @ 0x3000B300  (примерный размер ~140 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: timer_stop
 * Вызывают: FUN_3000acc0
 * Константы: 0x3000B300, 0xFFFFFFFF
 * Данные: DAT_3000b380
 * ---------------------------------------------------------------- */
void FUN_3000b300(void)

{
  timer_stop(1);
  *DAT_3000b380 = 0xffffffff;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3000b38c @ 0x3000B38C  (примерный размер ~176 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: __udiv32
 * Вызывают: primeCellSioDevInit
 * Константы: 0x3000B38C
 * ---------------------------------------------------------------- */
void FUN_3000b38c(int param_1)

{
  uint uVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 8) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 8) = 0x51;
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 8) = 0x57;
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 4) = 0;
  uVar1 = __udiv32(*(undefined4 *)(param_1 + 0x24),*(int *)(param_1 + 0x20) << 4);
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 0xc) = 0x80;
  **(uint **)(param_1 + 0x14) = uVar1 & 0xff;
  *(uint *)(*(int *)(param_1 + 0x14) + 4) = uVar1 >> 8 & 0xff;
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 0xc) = 3;
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 4) = 1;
  return;
}

/* ----------------------------------------------------------------
 * BSP_UART_Ioctl @ 0x3000BA78  (примерный размер ~52 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000BA78, 0x3000B618
 * Данные: DAT_3000b630, DAT_3000b634
 * ---------------------------------------------------------------- */
undefined4 BSP_UART_Ioctl(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((uint)(param_2 - DAT_3000b630) < 7) {
                    /* WARNING: Could not recover jumptable at 0x3000b618. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_3000b634 + (param_2 - DAT_3000b630) * 4))();
    return uVar1;
  }
  return 0x47;
}

/* ----------------------------------------------------------------
 * BSP_UART_DrxRestoreReg @ 0x3000BC30  (примерный размер ~160 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000BC30
 * ---------------------------------------------------------------- */
void BSP_UART_DrxRestoreReg(undefined4 *param_1)

{
  param_1[2] = 1;
  param_1[2] = 0x51;
  param_1[2] = 0x57;
  param_1[1] = 0;
  param_1[3] = 0x80;
  *param_1 = 0x1a;
  param_1[1] = 0;
  param_1[3] = 3;
  param_1[1] = 1;
  return;
}

/* ----------------------------------------------------------------
 * BSP_IpCfgModifyBootLine @ 0x3000BCD0  (примерный размер ~360 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 8
 * Вызывает: free, malloc, memcpy, memset, strcat, strcpy, strlen, strstr
 * Вызывают: BSP_IpCfgSaveIpMask
 * Константы: 0x3000BCD0
 * Данные: DAT_3000c8a0, DAT_3000c8a4
 * ---------------------------------------------------------------- */
void BSP_IpCfgModifyBootLine(char *param_1,char *param_2)

{
  size_t __n;
  size_t sVar1;
  char *__src;
  char *__src_00;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)*DAT_3000c8a0;
  __n = strlen(param_2);
  pcVar2 = strstr(pcVar2,param_1);
  if (pcVar2 != (char *)0x0) {
    sVar1 = strlen(param_1);
    pcVar2 = pcVar2 + sVar1;
    __src = strstr(pcVar2,DAT_3000c8a4);
    if (__src != (char *)0x0) {
      if ((int)__src - (int)pcVar2 == __n) {
        memcpy(pcVar2,param_2,__n);
      }
      else {
        if ((uint)((int)__src - (int)pcVar2) < __n) {
          sVar1 = strlen((char *)*DAT_3000c8a0);
          sVar1 = sVar1 + (__n - ((int)__src - (int)pcVar2));
        }
        else {
          sVar1 = strlen((char *)*DAT_3000c8a0);
        }
        __src_00 = (char *)malloc(sVar1 + 1);
        if ((__src_00 != (char *)0x0) && (__src_00 != (char *)0x0)) {
          memset(__src_00,0,sVar1 + 1);
          memcpy(__src_00,(void *)*DAT_3000c8a0,(int)pcVar2 - *DAT_3000c8a0);
          iVar3 = *DAT_3000c8a0;
          memcpy(__src_00 + ((int)pcVar2 - iVar3),param_2,__n);
          strcat(__src_00 + ((int)pcVar2 - iVar3) + __n,__src);
          strcpy((char *)*DAT_3000c8a0,__src_00);
          free(__src_00);
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_IpCfgSaveIpMask @ 0x3000BE38  (примерный размер ~184 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_IpCfgModifyBootLine, sprintf
 * Константы: 0x3000BE38
 * Данные: DAT_3000c8a8, DAT_3000c8ac, DAT_3000c8b0, DAT_3000c8b4, DAT_3000c8b8
 * ---------------------------------------------------------------- */
void BSP_IpCfgSaveIpMask(void)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char acStack_40 [64];
  
  pcVar3 = acStack_40;
  iVar6 = 0x1e;
  pcVar5 = DAT_3000c8a8;
  do {
    pcVar4 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 2;
    cVar2 = *pcVar4;
    iVar6 = iVar6 + -1;
    pcVar4 = pcVar3 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 2;
    *pcVar4 = cVar2;
  } while (iVar6 != 0);
  sprintf(acStack_40,DAT_3000c8b4,(uint)*DAT_3000c8ac,(uint)DAT_3000c8ac[1],(uint)DAT_3000c8ac[2],
          (uint)DAT_3000c8ac[3],(uint)*DAT_3000c8b0,(uint)DAT_3000c8b0[1],(uint)DAT_3000c8b0[2],
          (uint)DAT_3000c8b0[3]);
  BSP_IpCfgModifyBootLine(DAT_3000c8b8,acStack_40);
  return;
}

/* ----------------------------------------------------------------
 * BSP_SetPsMacAddr @ 0x3000BEF0  (примерный размер ~88 байт)
 * Модуль: bsp | Вызывают: 3 | Вызывает: 0
 * Вызывают: BSP_IpCfgSetMacAddr, BSP_SetPsMacAddrEx, SETMAC
 * Константы: 0x3000BEF0
 * Данные: DAT_3000c8bc
 * ---------------------------------------------------------------- */
undefined4
BSP_SetPsMacAddr(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                undefined1 param_5,undefined1 param_6)

{
  *DAT_3000c8bc = param_1;
  DAT_3000c8bc[1] = param_2;
  DAT_3000c8bc[2] = param_3;
  DAT_3000c8bc[3] = param_4;
  DAT_3000c8bc[4] = param_5;
  DAT_3000c8bc[5] = param_6;
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_IpCfgSetMacAddr @ 0x3000BF48  (примерный размер ~80 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_SetPsMacAddr
 * Константы: 0x3000BF48
 * ---------------------------------------------------------------- */
undefined4 BSP_IpCfgSetMacAddr(undefined1 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = BSP_SetPsMacAddr(*param_1,param_1[1],param_1[2],param_1[3],param_1[4],param_1[5]);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3000bf98 @ 0x3000BF98  (примерный размер ~104 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: lseek
 * Вызывают: FUN_3000c338
 * Константы: 0x3000BF98
 * ---------------------------------------------------------------- */
bool FUN_3000bf98(int param_1)

{
  bool bVar1;
  __off_t _Var2;
  __off_t _Var3;
  
  _Var2 = lseek(param_1,0,0);
  if (_Var2 < 0) {
    bVar1 = true;
  }
  else {
    _Var3 = lseek(param_1,0,2);
    if (_Var3 < 0) {
      bVar1 = true;
    }
    else {
      bVar1 = _Var3 - _Var2 < 0x400;
    }
  }
  return bVar1;
}

/* ----------------------------------------------------------------
 * FUN_3000c000 @ 0x3000C000  (примерный размер ~236 байт)
 * Модуль: bsp | Вызывают: 3 | Вызывает: 4
 * Вызывает: logMsg, lseek, read, write
 * Вызывают: BSP_ShowIfCfgFile, FUN_3000c0ec, FUN_3000c208
 * Константы: 0x3000C000, 0xFFFFFFFF
 * Данные: DAT_3000c8c0, DAT_3000c8c4
 * ---------------------------------------------------------------- */
undefined4 FUN_3000c000(int param_1,void *param_2,__off_t param_3,size_t param_4,int param_5)

{
  ssize_t sVar1;
  size_t __n;
  int iVar2;
  
  iVar2 = 0;
  lseek(param_1,param_3,0);
  __n = param_4;
  while( true ) {
    if ((int)param_4 <= iVar2) {
      return 0;
    }
    if (param_5 == 0) {
      sVar1 = write(param_1,param_2,__n);
    }
    else {
      sVar1 = read(param_1,param_2,__n);
    }
    if (sVar1 < 1) break;
    iVar2 = iVar2 + sVar1;
    param_2 = (void *)((int)param_2 + sVar1);
    __n = __n - sVar1;
  }
  logMsg(DAT_3000c8c0,sVar1,DAT_3000c8c4,3,4,5,6);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_3000c0ec @ 0x3000C0EC  (примерный размер ~284 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_3000c000, free, logMsg, malloc, memset
 * Вызывают: FUN_3000c338
 * Константы: 0x3000C0EC
 * Данные: DAT_3000c8c8, DAT_3000c8cc
 * ---------------------------------------------------------------- */
int FUN_3000c0ec(undefined4 param_1)

{
  void *__s;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0x400;
  iVar2 = 0;
  __s = malloc(0x400);
  if (__s == (void *)0x0) {
    logMsg(DAT_3000c8c8,0,0,0,0,0,0);
    iVar2 = -1;
  }
  else {
    memset(__s,0,0x400);
    for (; 0 < iVar3; iVar3 = iVar3 + -0x400) {
      iVar1 = iVar3;
      if (0x400 < iVar3) {
        iVar1 = 0x400;
      }
      iVar1 = FUN_3000c000(param_1,__s,iVar2,iVar1,0);
      if (iVar1 != 0) {
        logMsg(DAT_3000c8cc,0,0,0,0,0,0);
        free(__s);
        return iVar1;
      }
      iVar2 = iVar2 + 0x400;
    }
    free(__s);
    iVar2 = 0;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_3000c208 @ 0x3000C208  (примерный размер ~304 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_3000c000, free, logMsg, malloc, memcpy, memset, strcpy, strlen
 * Вызывают: FUN_3000c338
 * Константы: 0xFFFFFFFF, 0x3000C208
 * Данные: DAT_3000c8d0, DAT_3000c8d4, DAT_3000c8d8
 * ---------------------------------------------------------------- */
undefined4 FUN_3000c208(undefined4 param_1,int param_2,char *param_3)

{
  char *__dest;
  undefined4 uVar1;
  size_t sVar2;
  
  __dest = (char *)malloc(0x40);
  if (__dest == (char *)0x0) {
    logMsg(DAT_3000c8d0,0x40,0x170,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else {
    memset(__dest,0,0x40);
    sVar2 = strlen(param_3);
    if (sVar2 < 0x41) {
      if ((param_2 == 3) || (param_2 == 4)) {
        memcpy(__dest,param_3,6);
      }
      else {
        strcpy(__dest,param_3);
      }
      uVar1 = FUN_3000c000(param_1,__dest,param_2 << 6,0x40,0);
      free(__dest);
    }
    else {
      sVar2 = strlen(param_3);
      logMsg(DAT_3000c8d4,sVar2,DAT_3000c8d8,3,4,5,6);
      free(__dest);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3000c338 @ 0x3000C338  (примерный размер ~400 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_3000bf98, FUN_3000c0ec, FUN_3000c208, close, fsync, logMsg, open
 * Вызывают: BSP_SetPsMacAddrEx
 * Константы: 0x3000C338
 * Данные: DAT_3000c8dc, DAT_3000c8e0, DAT_3000c8e4, DAT_3000c8e8, DAT_3000c8ec, DAT_3000c8f0, DAT_3000c8f4, DAT_3000c8f8
 * ---------------------------------------------------------------- */
int FUN_3000c338(char *param_1,undefined4 param_2,undefined4 param_3)

{
  int __fd;
  int iVar1;
  
  __fd = open(param_1,DAT_3000c8dc,DAT_3000c8e0);
  if (__fd < 1) {
    logMsg(DAT_3000c8e4,DAT_3000c8e8,__fd,3,4,5,6);
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_3000bf98(__fd);
    if ((iVar1 == 0) || (iVar1 = FUN_3000c0ec(__fd), iVar1 == 0)) {
      iVar1 = FUN_3000c208(__fd,0,DAT_3000c8ec);
      if (iVar1 == 0) {
        fsync(__fd);
        iVar1 = FUN_3000c208(__fd,param_2,param_3);
        if ((iVar1 == 0) && (iVar1 = FUN_3000c208(__fd,0,DAT_3000c8f4), iVar1 != 0)) {
          logMsg(DAT_3000c8f0,iVar1,DAT_3000c8f8,0,0,0,0);
          close(__fd);
        }
        else {
          fsync(__fd);
          close(__fd);
        }
      }
      else {
        logMsg(DAT_3000c8f0,iVar1,0x1c4,0,0,0,0);
        close(__fd);
      }
    }
    else {
      close(__fd);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3000c4c8 @ 0x3000C4C8  (примерный размер ~208 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: logMsg, printf
 * Вызывают: FUN_3000c600
 * Константы: 0x3000C4C8
 * Данные: DAT_3000c8fc, DAT_3000c900, DAT_3000c904
 * ---------------------------------------------------------------- */
void FUN_3000c4c8(undefined4 param_1,byte *param_2)

{
  if (((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0)) &&
      (((param_2[3] == 0 && (param_2[4] == 0)) && (param_2[5] == 0)))) || ((*param_2 & 1) != 0)) {
    logMsg(DAT_3000c8fc,DAT_3000c900,0,0,0,0,0);
  }
  else {
    printf(DAT_3000c904,param_1,(uint)*param_2,(uint)param_2[1],(uint)param_2[2],(uint)param_2[3],
           (uint)param_2[4],(uint)param_2[5]);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3000c598 @ 0x3000C598  (примерный размер ~104 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: logMsg, printf, strlen
 * Вызывают: FUN_3000c600
 * Константы: 0x3000C598
 * Данные: DAT_3000c908, DAT_3000c90c, DAT_3000c910
 * ---------------------------------------------------------------- */
void FUN_3000c598(undefined4 param_1,char *param_2)

{
  size_t sVar1;
  
  sVar1 = strlen(param_2);
  if (sVar1 == 0) {
    logMsg(DAT_3000c908,DAT_3000c90c,0,0,0,0,0);
  }
  else {
    printf(DAT_3000c910,param_1,param_2);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3000c600 @ 0x3000C600  (примерный размер ~152 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3000c4c8, FUN_3000c598
 * Вызывают: BSP_ShowIfCfgFile
 * Константы: 0x3000C600
 * Данные: DAT_3000c914, DAT_3000c918, DAT_3000c91c, DAT_3000c920, DAT_3000c924
 * ---------------------------------------------------------------- */
void FUN_3000c600(int param_1,undefined4 param_2)

{
  if (param_1 == 3) {
    FUN_3000c4c8(DAT_3000c91c,param_2);
  }
  else if (param_1 < 4) {
    if (param_1 == 1) {
      FUN_3000c598(DAT_3000c914,param_2);
    }
    else if (param_1 == 2) {
      FUN_3000c598(DAT_3000c918,param_2);
    }
  }
  else if (param_1 == 4) {
    FUN_3000c4c8(DAT_3000c920,param_2);
  }
  else if (param_1 == 5) {
    FUN_3000c598(DAT_3000c924,param_2);
  }
  return;
}

