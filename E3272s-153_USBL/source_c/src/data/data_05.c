/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 5 (функций: 150, адреса 0x3006DF20..0x30083304)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * Read_Status @ 0x3006DF20  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFEA, 0x3006DF20
 * Данные: DAT_3006eb30, DAT_3006ee30
 * ---------------------------------------------------------------- */
undefined4 Read_Status(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (*DAT_3006ee30 == 0) {
    uVar1 = 0xffffffea;
  }
  else if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    *param_1 = *(undefined4 *)(*DAT_3006eb30 + 0x40);
    param_1[1] = *(undefined4 *)(*DAT_3006eb30 + 0x44);
    param_1[2] = *(undefined4 *)(*DAT_3006eb30 + 0x48);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Read_Write_MultiRegdata @ 0x3006DF8C  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3006DF8C, 0xFFFFFFEA
 * ---------------------------------------------------------------- */
undefined4 Read_Write_MultiRegdata(void)

{
  return 0xffffffea;
}

/* ----------------------------------------------------------------
 * Read_Write_FIFOdata @ 0x3006DF94  (примерный размер ~548 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: __udiv32, memcpy
 * Вызывают: Read_Write_FIFO
 * Константы: 0x3006DF94
 * Данные: DAT_3006eb30, DAT_3006ef50, DAT_3006ef54, DAT_3006ef58
 * ---------------------------------------------------------------- */
int Read_Write_FIFOdata(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_30 [2];
  
  local_30[0] = 0;
  uVar3 = *(uint *)(*DAT_3006eb30 + 0x48);
  if ((param_1 == 0) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    if (param_3 == 0) {
      if ((uVar3 & 4) != 0) {
        return 0;
      }
      if ((uVar3 & 8) == 0) {
        uVar3 = DAT_3006ef54 & uVar3 >> 0x11;
      }
      else {
        uVar3 = *DAT_3006ef50;
      }
      uVar2 = __udiv32(param_1,*DAT_3006ef58 >> 3);
      if (uVar2 < uVar3) {
        uVar3 = __udiv32(param_1,*DAT_3006ef58 >> 3);
      }
      if (uVar3 == 0) {
        uVar3 = 1;
      }
      else {
        param_1 = *DAT_3006ef58 >> 3;
      }
      for (iVar1 = 0; iVar1 < (int)uVar3; iVar1 = iVar1 + 1) {
        local_30[0] = *(undefined4 *)(*DAT_3006eb30 + 0x100);
        memcpy((void *)(iVar1 * param_1 + param_2),local_30,param_1);
      }
    }
    else {
      if ((uVar3 & 8) != 0) {
        return 0;
      }
      if ((uVar3 & 4) == 0) {
        uVar3 = *DAT_3006ef50 - (DAT_3006ef54 & uVar3 >> 0x11);
      }
      else {
        uVar3 = *DAT_3006ef50;
      }
      uVar2 = __udiv32(param_1,*DAT_3006ef58 >> 3);
      if (uVar2 < uVar3) {
        uVar3 = __udiv32(param_1,*DAT_3006ef58 >> 3);
      }
      if (uVar3 == 0) {
        uVar3 = 1;
      }
      else {
        param_1 = *DAT_3006ef58 >> 3;
      }
      for (iVar1 = 0; iVar1 < (int)uVar3; iVar1 = iVar1 + 1) {
        memcpy(local_30,(void *)(iVar1 * param_1 + param_2),param_1);
        *(undefined4 *)(*DAT_3006eb30 + 0x100) = local_30[0];
      }
    }
    iVar1 = param_1 * iVar1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Assert_n_Poll_startcmd @ 0x3006E1B8  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: Poll_Cmd_Accept
 * Вызывают: Clk_Enable, Set_ClkDivider_Freq, Set_Clock_Source
 * Константы: 0x3006E1B8
 * Данные: DAT_3006eb30, DAT_3006f0ec
 * ---------------------------------------------------------------- */
void Assert_n_Poll_startcmd(void)

{
  *(undefined4 *)(*DAT_3006eb30 + 0x2c) = DAT_3006f0ec;
  Poll_Cmd_Accept();
  return;
}

/* ----------------------------------------------------------------
 * Clk_Enable @ 0x3006E1E4  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: Assert_n_Poll_startcmd
 * Вызывают: Clk_Enable_Disable, Set_ClkDivider_Freq, Set_Clock_Source, sdmmcDrvExit
 * Константы: 0x3006E1E4
 * Данные: DAT_3006eb30, DAT_3006f0f0
 * ---------------------------------------------------------------- */
void Clk_Enable(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = DAT_3006f0f0;
  if (param_1 != 0xff) {
    uVar1 = 1 << (param_1 & 0xff);
  }
  if (param_2 == 0) {
    uVar1 = *(uint *)(*DAT_3006eb30 + 0x10) & ~uVar1;
  }
  else {
    uVar1 = *(uint *)(*DAT_3006eb30 + 0x10) | uVar1;
  }
  *(uint *)(*DAT_3006eb30 + 0x10) = uVar1;
  Assert_n_Poll_startcmd();
  return;
}

/* ----------------------------------------------------------------
 * Set_ClkDivider_Freq @ 0x3006E240  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: Assert_n_Poll_startcmd, Clk_Enable, Read_Write_IPreg
 * Вызывают: Set_Clk_Frequency
 * Константы: 0x3006E240
 * Данные: DAT_3006eb30
 * ---------------------------------------------------------------- */
void Set_ClkDivider_Freq(int param_1,undefined1 param_2,undefined1 *param_3)

{
  undefined4 local_18;
  undefined1 auStack_14 [4];
  
  Read_Write_IPreg(0x10,auStack_14,0);
  Clk_Enable(0xff,0);
  local_18 = *(undefined4 *)(*DAT_3006eb30 + 8);
  *param_3 = auStack_14[param_1 + -4];
  auStack_14[param_1 + -4] = param_2;
  *(undefined4 *)(*DAT_3006eb30 + 8) = local_18;
  local_18 = *(undefined4 *)(*DAT_3006eb30 + 8);
  Read_Write_IPreg(0x10,auStack_14,1);
  Assert_n_Poll_startcmd();
  return;
}

/* ----------------------------------------------------------------
 * Set_Clock_Source @ 0x3006E2D0  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: Assert_n_Poll_startcmd, Clk_Enable, Read_Write_IPreg
 * Вызывают: Set_Clk_Source
 * Константы: 0x3006E2D0, 0xFFFFFFEA
 * Данные: DAT_3006eb30
 * ---------------------------------------------------------------- */
undefined4 Set_Clock_Source(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined1 auStack_10 [4];
  
  if ((param_2 & 3) < 4) {
    Read_Write_IPreg(0x10,auStack_10,0);
    Clk_Enable(0xff,0);
    *(uint *)(*DAT_3006eb30 + 0xc) =
         *(uint *)(*DAT_3006eb30 + 0xc) & ~(3 << ((param_1 & 0x7f) << 1)) |
         (param_2 & 3) << ((param_1 & 0x7f) << 1);
    Read_Write_IPreg(0x10,auStack_10,1);
    uVar1 = Assert_n_Poll_startcmd();
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Set_Reset_CNTRLreg @ 0x3006E39C  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Suspend_Transfer
 * Константы: 0x3006E39C
 * Данные: DAT_3006eb30
 * ---------------------------------------------------------------- */
undefined4 Set_Reset_CNTRLreg(uint param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)*DAT_3006eb30 = *(uint *)*DAT_3006eb30 & ~param_1;
  }
  else {
    *(uint *)*DAT_3006eb30 = *(uint *)*DAT_3006eb30 | param_1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * SDIO_config_load @ 0x3006E3EC  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: free, malloc, memset, printf
 * Вызывают: sdmmcDrvHwInit
 * Константы: 0x3006E3EC, 0xFFFFFFFF
 * Данные: DAT_3006f364, DAT_3006f368, DAT_3006f36c
 * ---------------------------------------------------------------- */
undefined4 SDIO_config_load(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = malloc(0x54);
  *DAT_3006f364 = (int)pvVar1;
  if (*DAT_3006f364 == 0) {
    printf(DAT_3006f368);
    free((void *)*DAT_3006f364);
    uVar2 = 0xffffffff;
  }
  else {
    memset((void *)*DAT_3006f364,0,0x54);
    *(undefined4 *)(*DAT_3006f364 + 8) = 0;
    *(undefined4 *)*DAT_3006f364 = DAT_3006f36c;
    *(undefined4 *)(*DAT_3006f364 + 0x50) = 0;
    *(undefined4 *)(*DAT_3006f364 + 0x40) = 1;
    *(undefined4 *)(*DAT_3006f364 + 0x44) = 1;
    *(undefined4 *)(*DAT_3006f364 + 0x3c) = 1;
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * sdmmcDrvHwInit @ 0x3006E4A8  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: BSP_PMU_LDOCtrl, IDMAC_Init, SDIO_config_load, printf, taskDelay
 * Вызывают: SD_MMC_Host_Init
 * Константы: 0x3006E4A8, 0x00400000, 0xFFBFFFFF, 0xFFFFC0FF
 * Данные: DAT_3006f364, DAT_3006f370, DAT_3006f374, DAT_3006f378, DAT_3006f410, DAT_3006f414, DAT_3006f418
 * ---------------------------------------------------------------- */
void sdmmcDrvHwInit(void)

{
  int iVar1;
  
  *DAT_3006f370 = *DAT_3006f370 | 0x400000;
  taskDelay(5);
  *DAT_3006f370 = *DAT_3006f370 & 0xffbfffff;
  taskDelay(5);
  BSP_PMU_LDOCtrl(10,1);
  BSP_PMU_LDOCtrl(7,1);
  *DAT_3006f374 = *DAT_3006f374 | 0x8000;
  taskDelay(10);
  *DAT_3006f378 = *DAT_3006f378 & 0xffffc0ff | 0xa00;
  taskDelay(2);
  iVar1 = SDIO_config_load();
  if (iVar1 == 0) {
    if ((*(int *)(*DAT_3006f364 + 0x44) == 0) || (iVar1 = IDMAC_Init(), iVar1 == 0)) {
      printf(DAT_3006f418);
    }
    else {
      printf(DAT_3006f414);
    }
  }
  else {
    printf(DAT_3006f410);
  }
  return;
}

/* ----------------------------------------------------------------
 * SD_MMC_Host_Init @ 0x3006E59C  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: SD_MMC_Bus_Init, Set_SD_Mode, intConnect, intEnable, printf, sdmmcDrvHwInit
 * Вызывают: sdmmcInit
 * Константы: 0x3006E59C
 * Данные: DAT_3006eb30, DAT_3006eb38, DAT_3006ee30, DAT_3006ef50, DAT_3006ef58, DAT_3006f41c, DAT_3006f420, DAT_3006f520
 * ---------------------------------------------------------------- */
int SD_MMC_Host_Init(void)

{
  int iVar1;
  uint uVar2;
  
  sdmmcDrvHwInit();
  *DAT_3006ee30 = *DAT_3006eb30;
  *DAT_3006f41c = 0;
  intConnect(0x6c,DAT_3006f420,0);
  intEnable(0x6c);
  *DAT_3006ef50 = (*(ushort *)(*DAT_3006eb30 + 0x4e) & DAT_3006eb38) + 1;
  printf(DAT_3006f520,*DAT_3006ef50);
  uVar2 = *(uint *)(*DAT_3006eb30 + 0x70) >> 7 & 7;
  if (uVar2 == 1) {
    *DAT_3006ef58 = 0x20;
  }
  else if (uVar2 == 0) {
    *DAT_3006ef58 = 0x10;
  }
  else {
    *DAT_3006ef58 = 0x40;
  }
  iVar1 = SD_MMC_Bus_Init();
  if (iVar1 == 0) {
    iVar1 = Set_SD_Mode(0,1);
    if (iVar1 != 0) {
      printf(DAT_3006f528,iVar1);
    }
  }
  else {
    printf(DAT_3006f524);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * SD_MMC_Host_Exit @ 0x3006E6B4  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: intDisable
 * Вызывают: sdmmcDrvExit
 * Константы: 0x3006E6B4
 * Данные: DAT_3006eb30, DAT_3006eb34, DAT_3006ee30, DAT_3006ef50, DAT_3006ef58
 * ---------------------------------------------------------------- */
void SD_MMC_Host_Exit(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*DAT_3006eb30 + 0x4c) & DAT_3006eb34;
  *DAT_3006ef50 = *DAT_3006ef50 << 0x10;
  *(uint *)(*DAT_3006eb30 + 0x4c) = uVar1 | *DAT_3006ef50 - 1U;
  *DAT_3006ee30 = 0;
  *DAT_3006ef50 = 1;
  *DAT_3006ef58 = 0x20;
  intDisable(0x6c);
  return;
}

/* ----------------------------------------------------------------
 * sdmmcHwInit @ 0x3006E72C  (примерный размер ~556 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: logMsg, taskDelay
 * Вызывают: sdmmcISRInit
 * Константы: 0x00400000, 0x3006E72C, 0xFFBFFFFF, 0xFFFFC0FF
 * Данные: DAT_3006eb30, DAT_3006f36c, DAT_3006f370, DAT_3006f374, DAT_3006f378, DAT_3006f64c, DAT_3006f650, DAT_3006f654
 * ---------------------------------------------------------------- */
void sdmmcHwInit(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = 0;
  logMsg(DAT_3006f64c,*DAT_3006eb30,2,3,4,5,6);
  logMsg(DAT_3006f650,*DAT_3006eb30,2,3,4,5,6);
  *DAT_3006f36c = 1;
  do {
    uVar3 = uVar3 + 1;
    if (500 < uVar3) {
      logMsg(DAT_3006f654,0,0,0,0,0,0);
      return;
    }
  } while ((*(uint *)*DAT_3006eb30 & 1) != 0);
  logMsg(DAT_3006f658,*DAT_3006eb30,2,3,4,5,6);
  *DAT_3006f370 = *DAT_3006f370 | 0x400000;
  taskDelay(5);
  logMsg(DAT_3006f6e0,1,2,3,4,5,6);
  *DAT_3006f370 = *DAT_3006f370 & 0xffbfffff;
  iVar1 = 0x14;
  do {
    taskDelay(5);
    iVar2 = iVar1;
    if ((*DAT_3006f370 & 0x400000) == 0) break;
    iVar2 = iVar1 + -1;
    bVar4 = iVar1 == 0;
    iVar1 = iVar2;
  } while (bVar4);
  if (iVar2 == 0) {
    logMsg(DAT_3006f6e4,1,2,3,4,5,6);
  }
  logMsg(DAT_3006f7e4,1,2,3,4,5,6);
  *DAT_3006f374 = *DAT_3006f374 | 0x8000;
  taskDelay(10);
  *DAT_3006f378 = *DAT_3006f378 & 0xffffc0ff | 0xa00;
  taskDelay(2);
  return;
}

/* ----------------------------------------------------------------
 * sdmmcHwExit @ 0x3006E958  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: sdmmcDrvExit
 * Константы: 0x3006E958
 * ---------------------------------------------------------------- */
void sdmmcHwExit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * sd_mmc_setDbg @ 0x3006E95C  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3006E95C
 * Данные: DAT_3006f7e8
 * ---------------------------------------------------------------- */
void sd_mmc_setDbg(undefined4 param_1)

{
  *DAT_3006f7e8 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * sd_mmc_setDummy @ 0x3006E974  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3006E974
 * Данные: DAT_3006f7ec
 * ---------------------------------------------------------------- */
void sd_mmc_setDummy(undefined4 param_1)

{
  *DAT_3006f7ec = param_1;
  return;
}

/* ----------------------------------------------------------------
 * sdmmcTFCardOnOff @ 0x3006E98C  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: sdmmcBlkDataRW
 * Константы: 0x3006E98C
 * Данные: DAT_3006f7f0
 * ---------------------------------------------------------------- */
uint sdmmcTFCardOnOff(void)

{
  return *DAT_3006f7f0 >> 8 & 1;
}

/* ----------------------------------------------------------------
 * sdmmcBlkDataRW @ 0x3006E9A0  (примерный размер ~356 байт)
 * Модуль: data | Вызывают: 21 | Вызывает: 6
 * Вызывает: Read_Write_BlkData, printf, sdmmcPollBusyBit, sdmmcTFCardOnOff, semGive, semTake
 * Вызывают: sd_mmc_blk_read, sd_mmc_blk_read_fixed, sd_mmc_blk_read_increase, sd_mmc_blk_rw, sd_mmc_blk_write_fixed, sd_mmc_blk_write_increase, sd_mmc_blk_write_increaseaddr, sdmmcBlkRd, sdmmcBlkWrt, sdmmcGetFat16
 *           ...
 * Константы: 0x3006E9A0, 0xFFFFFFFF
 * Данные: DAT_3006f41c, DAT_3006f7f4, DAT_3006f7f8, DAT_3006f7fc, DAT_3006f910, DAT_3006f914, DAT_3006f918, DAT_3006f91c
 * ---------------------------------------------------------------- */
int sdmmcBlkDataRW(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  semTake(*DAT_3006f7f4,0xffffffff);
  *DAT_3006f7f8 = 1;
  if (*(char *)(DAT_3006f7fc + param_1 * 0x88) == '\x01') {
    param_2 = param_2 << 9;
  }
  if ((*DAT_3006f41c == 1) && (iVar2 = sdmmcPollBusyBit(), iVar2 != 0)) {
    printf(DAT_3006f910);
    iVar1 = sdmmcTFCardOnOff();
    *DAT_3006f914 = (uint)(iVar1 != 0);
  }
  *DAT_3006f41c = param_5;
  iVar2 = Read_Write_BlkData(param_1,param_2,param_3 << 9,param_4,DAT_3006f918,0,0,10,
                             param_5 << 7 | 0xe,iVar2);
  if (iVar2 != 0) {
    iVar1 = sdmmcTFCardOnOff();
    *DAT_3006f914 = (uint)(iVar1 != 0);
    printf(DAT_3006f91c,iVar2);
  }
  *DAT_3006f7f8 = 0;
  semGive(*DAT_3006f7f4);
  return iVar2;
}

/* ----------------------------------------------------------------
 * sd_mmc_blk_write_increase @ 0x3006EB04  (примерный размер ~612 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: bzero, free, logMsg, memalign, sdmmcBlkDataRW
 * Константы: 0xFFFFFFFF, 0x3006EB04
 * Данные: DAT_3006f7ec, DAT_3006f9d0, DAT_3006f9d4, DAT_3006fa64, DAT_3006fb50, DAT_3006fb54, DAT_3006fb58
 * ---------------------------------------------------------------- */
undefined4
sd_mmc_blk_write_increase
          (undefined4 param_1,undefined4 param_2,int param_3,char param_4,int param_5)

{
  undefined4 uVar1;
  void *__s;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    logMsg(DAT_3006f9d0,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    if (param_5 < 1) {
      param_5 = 1;
    }
    __s = (void *)memalign(0x20,param_3 * 0x200);
    if (__s == (void *)0x0) {
      logMsg(DAT_3006f9d4,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
    else {
      if (((uint)__s & 0x1f) != 0) {
        logMsg(DAT_3006fa64,__s,0,0,0,0,0);
      }
      bzero(__s,param_3 * 0x200);
      for (iVar2 = 0; iVar2 < param_5; iVar2 = iVar2 + 1) {
        for (uVar4 = 0; uVar4 <= (uint)(param_3 * 0x200) && param_3 * 0x200 - uVar4 != 0;
            uVar4 = uVar4 + 1) {
          *(char *)((int)__s + uVar4) = (char)uVar4 + param_4;
        }
        if (*DAT_3006f7ec == 0) {
          iVar3 = sdmmcBlkDataRW(param_1,param_2,param_3,__s,1);
        }
        else {
          logMsg(DAT_3006fb50,1,2,3,4,5,6);
          iVar3 = 0;
        }
        logMsg(DAT_3006fb54,iVar2,2,3,4,5,6);
        if (iVar3 != 0) {
          logMsg(DAT_3006fb58,0,0,0,0,0,0);
          free(__s);
          return 0xffffffff;
        }
      }
      free(__s);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sd_mmc_blk_write_fixed @ 0x3006ED68  (примерный размер ~536 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: bzero, free, logMsg, memalign, printf, sdmmcBlkDataRW
 * Константы: 0xFFFFFFFF, 0x3006ED68
 * Данные: DAT_3006f7ec, DAT_3006f9d0, DAT_3006f9d4, DAT_3006fa64, DAT_3006fb50, DAT_3006fb58
 * ---------------------------------------------------------------- */
undefined4
sd_mmc_blk_write_fixed
          (undefined4 param_1,undefined4 param_2,int param_3,undefined1 param_4,int param_5)

{
  undefined4 uVar1;
  void *__s;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    logMsg(DAT_3006f9d0,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    if (param_5 < 1) {
      param_5 = 1;
    }
    __s = (void *)memalign(0x20,param_3 * 0x200);
    if (__s == (void *)0x0) {
      logMsg(DAT_3006f9d4,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
    else {
      if (((uint)__s & 0x1f) != 0) {
        printf(DAT_3006fa64,__s,0,0,0,0,0);
      }
      bzero(__s,param_3 * 0x200);
      for (iVar3 = 0; iVar3 < param_5; iVar3 = iVar3 + 1) {
        for (uVar4 = 0; uVar4 <= (uint)(param_3 * 0x200) && param_3 * 0x200 - uVar4 != 0;
            uVar4 = uVar4 + 1) {
          *(undefined1 *)((int)__s + uVar4) = param_4;
        }
        if (*DAT_3006f7ec == 0) {
          iVar2 = sdmmcBlkDataRW(param_1,param_2,param_3,__s,1);
          if (iVar2 != 0) {
            logMsg(DAT_3006fb58,0,0,0,0,0,0);
            free(__s);
            return 0xffffffff;
          }
        }
        else {
          logMsg(DAT_3006fb50,1,2,3,4,5,6);
        }
      }
      free(__s);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sd_mmc_blk_write_increaseaddr @ 0x3006EF80  (примерный размер ~504 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: bzero, free, logMsg, memalign, printf, sdmmcBlkDataRW
 * Константы: 0xFFFFFFFF, 0x3006EF80
 * Данные: DAT_3006f7ec, DAT_3006f9d0, DAT_3006f9d4, DAT_3006fa64, DAT_3006fb50, DAT_3006fb58
 * ---------------------------------------------------------------- */
undefined4
sd_mmc_blk_write_increaseaddr(undefined4 param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  undefined4 uVar1;
  void *__s;
  int iVar2;
  int iVar3;
  
  if (param_3 == 0) {
    logMsg(DAT_3006f9d0,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    __s = (void *)memalign(0x20,param_3 * 0x200);
    if (__s == (void *)0x0) {
      logMsg(DAT_3006f9d4,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
    else {
      if (((uint)__s & 0x1f) != 0) {
        printf(DAT_3006fa64,__s,0,0,0,0,0);
      }
      bzero(__s,0x200);
      for (iVar3 = 0; iVar3 < 0x200; iVar3 = iVar3 + 1) {
        *(undefined1 *)((int)__s + iVar3) = param_4;
      }
      for (iVar3 = 0; iVar3 < param_3; iVar3 = iVar3 + 1) {
        if (*DAT_3006f7ec == 0) {
          iVar2 = sdmmcBlkDataRW(param_1,param_2,param_3,__s,1);
          if (iVar2 != 0) {
            logMsg(DAT_3006fb58,0,0,0,0,0,0);
            free(__s);
            return 0xffffffff;
          }
        }
        else {
          logMsg(DAT_3006fb50,1,2,3,4,5,6);
        }
      }
      free(__s);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sd_mmc_blk_read @ 0x3006F178  (примерный размер ~888 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: free, logMsg, memalign, memset, printf, sdmmcBlkDataRW
 * Константы: 0xFFFFFFFF, 0x3006F178
 * Данные: DAT_3006f7ec, DAT_3006f9d4, DAT_3006fa64, DAT_3006fb50, DAT_30070048, DAT_3007004c, DAT_30070050, DAT_30070054
 * ---------------------------------------------------------------- */
undefined4 sd_mmc_blk_read(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  void *__ptr;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (param_4 < 1) {
    param_4 = 1;
  }
  logMsg(DAT_30070048,param_1,param_2,param_3,0x200,5,6);
  __ptr = (void *)memalign(0x20,param_3 * 0x200);
  logMsg(DAT_3007004c,0,DAT_30070050,3,4,5,6);
  if (__ptr == (void *)0x0) {
    logMsg(DAT_3006f9d4,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    logMsg(DAT_30070054,__ptr,DAT_30070058,3,4,5,6);
    if (((uint)__ptr & 0x1f) != 0) {
      logMsg(DAT_3006fa64,__ptr,0,0,0,0,0);
    }
    logMsg(DAT_3007004c,0,DAT_30070150,3,4,5,6);
    for (iVar4 = 0; iVar4 < param_4; iVar4 = iVar4 + 1) {
      logMsg(DAT_3007004c,0,DAT_30070154,3,4,5,6);
      memset(__ptr,0,param_3 * 0x200);
      logMsg(DAT_30070158,1,2,3,4,5,6);
      if (*DAT_3006f7ec == 0) {
        iVar2 = sdmmcBlkDataRW(param_1,param_2,param_3,__ptr,0);
        if (iVar2 != 0) {
          logMsg(DAT_30070280,0,0,0,0,0,0);
          free(__ptr);
          return 0xffffffff;
        }
      }
      else {
        logMsg(DAT_3006fb50,1,2,3,4,5,6);
      }
      printf(DAT_30070284);
      for (uVar3 = 0; uVar3 <= (uint)(param_3 * 0x200) && param_3 * 0x200 - uVar3 != 0;
          uVar3 = uVar3 + 1) {
        printf(DAT_30070288,(uint)*(byte *)((int)__ptr + uVar3));
        if ((uVar3 + 1 & 0xf) == 0) {
          printf(DAT_3007028c);
        }
        else if (param_3 * 0x200 - 1U == uVar3) {
          printf(DAT_30070284);
        }
        else {
          printf(DAT_30070320);
        }
      }
      printf(DAT_30070284);
    }
    free(__ptr);
    logMsg(DAT_3007004c,0,DAT_30070324,3,4,5,6);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sd_mmc_blk_read_increase @ 0x3006F4F0  (примерный размер ~668 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: free, logMsg, memalign, memset, printf, sdmmcBlkDataRW
 * Константы: 0xFFFFFFFF, 0x3006F4F0
 * Данные: DAT_3006f7ec, DAT_3006f9d0, DAT_3006f9d4, DAT_3006fa64, DAT_3006fb50, DAT_30070280, DAT_30070584
 * ---------------------------------------------------------------- */
undefined4
sd_mmc_blk_read_increase(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,int param_5)

{
  undefined4 uVar1;
  void *__ptr;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (param_3 == 0) {
    logMsg(DAT_3006f9d0,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    if (param_5 < 1) {
      param_5 = 1;
    }
    __ptr = (void *)memalign(0x20,param_3 * 0x200);
    if (__ptr == (void *)0x0) {
      logMsg(DAT_3006f9d4,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
    else {
      if (((uint)__ptr & 0x1f) != 0) {
        printf(DAT_3006fa64,__ptr,0,0,0,0,0);
      }
      for (iVar4 = 0; iVar4 < param_5; iVar4 = iVar4 + 1) {
        memset(__ptr,0,param_3 * 0x200);
        if (*DAT_3006f7ec == 0) {
          iVar3 = sdmmcBlkDataRW(param_1,param_2,param_3,__ptr,0);
          if (iVar3 != 0) {
            logMsg(DAT_30070280,0,0,0,0,0,0);
            free(__ptr);
            return 0xffffffff;
          }
        }
        else {
          logMsg(DAT_3006fb50,1,2,3,4,5,6);
        }
        for (iVar3 = 0; param_3 * 0x200 - iVar3 != 0 && iVar3 <= param_3 * 0x200; iVar3 = iVar3 + 1)
        {
          uVar5 = iVar3 + (param_4 & 0xff);
          uVar2 = uVar5 & 0xff;
          if ((int)uVar5 < 0) {
            uVar2 = -(-uVar5 & 0xff);
          }
          if (uVar2 != *(byte *)((int)__ptr + iVar3)) {
            uVar5 = iVar3 + (param_4 & 0xff);
            uVar2 = uVar5 & 0xff;
            if ((int)uVar5 < 0) {
              uVar2 = -(-uVar5 & 0xff);
            }
            printf(DAT_30070584,iVar4,iVar3,(uint)*(byte *)((int)__ptr + iVar3),uVar2);
          }
        }
      }
      free(__ptr);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sd_mmc_blk_read_fixed @ 0x3006F78C  (примерный размер ~616 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: free, logMsg, memalign, memset, printf, sdmmcBlkDataRW
 * Константы: 0xFFFFFFFF, 0x3006F78C
 * Данные: DAT_3006f9d0, DAT_3006f9d4, DAT_3006fa64, DAT_3006fb50, DAT_30070280, DAT_30070584, DAT_300707fc
 * ---------------------------------------------------------------- */
undefined4
sd_mmc_blk_read_fixed(undefined4 param_1,undefined4 param_2,int param_3,byte param_4,int param_5)

{
  undefined4 uVar1;
  void *__ptr;
  int iVar2;
  int iVar3;
  
  if (param_3 == 0) {
    logMsg(DAT_3006f9d0,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    if (param_5 < 1) {
      param_5 = 1;
    }
    __ptr = (void *)memalign(0x20,param_3 * 0x200);
    if (__ptr == (void *)0x0) {
      logMsg(DAT_3006f9d4,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
    else {
      if (((uint)__ptr & 0x1f) != 0) {
        printf(DAT_3006fa64,__ptr,0,0,0,0,0);
      }
      for (iVar2 = 0; iVar2 < param_5; iVar2 = iVar2 + 1) {
        memset(__ptr,0,param_3 * 0x200);
        if (*DAT_300707fc == 0) {
          iVar3 = sdmmcBlkDataRW(param_1,param_2,param_3,__ptr,0);
          if (iVar3 != 0) {
            logMsg(DAT_30070280,0,0,0,0,0,0);
            free(__ptr);
            return 0xffffffff;
          }
        }
        else {
          logMsg(DAT_3006fb50,1,2,3,4,5,6);
        }
        for (iVar3 = 0; param_3 * 0x200 - iVar3 != 0 && iVar3 <= param_3 * 0x200; iVar3 = iVar3 + 1)
        {
          if (param_4 != *(byte *)((int)__ptr + iVar3)) {
            printf(DAT_30070584,iVar2,iVar3,(uint)*(byte *)((int)__ptr + iVar3),(uint)param_4);
          }
        }
      }
      free(__ptr);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sd_mmc_blk_rw @ 0x3006F9F4  (примерный размер ~636 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: __urem32, bzero, free, logMsg, memalign, memset, printf, sdmmcBlkDataRW
 * Константы: 0xFFFFFFFF, 0x3006F9F4
 * Данные: DAT_3006fb58, DAT_30070280, DAT_30070948, DAT_3007094c, DAT_30070aec
 * ---------------------------------------------------------------- */
undefined4
sd_mmc_blk_rw(undefined4 param_1,undefined4 param_2,int param_3,int param_4,byte param_5,int param_6
             ,int param_7)

{
  undefined1 uVar1;
  void *__s;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = (uint)param_5;
  __s = (void *)memalign(0x20,param_4 * param_3);
  if (__s == (void *)0x0) {
    logMsg(DAT_30070948,0,0,0,0,0,0);
    uVar2 = 0xffffffff;
  }
  else {
    printf(DAT_3007094c,__s);
    if (param_7 < 1) {
      param_7 = 1;
    }
    if (param_6 == 0) {
      param_6 = 0x100;
    }
    memset(__s,0,param_4 * param_3);
    for (iVar6 = 0; iVar6 < param_7; iVar6 = iVar6 + 1) {
      for (iVar5 = 0; param_4 * param_3 - iVar5 != 0 && iVar5 <= param_4 * param_3;
          iVar5 = iVar5 + 1) {
        uVar1 = __urem32(iVar5 + uVar4,param_6);
        *(undefined1 *)((int)__s + iVar5) = uVar1;
      }
      iVar5 = sdmmcBlkDataRW(param_1,param_2,param_3,__s,1);
      if (iVar5 != 0) {
        logMsg(DAT_3006fb58,0,0,0,0,0,0,iVar6,iVar5);
        free(__s);
        return 0xffffffff;
      }
      bzero(__s,param_4 * param_3);
      iVar5 = sdmmcBlkDataRW(param_1,param_2,param_3,__s,0);
      if (iVar5 != 0) {
        logMsg(DAT_30070280,0,0,0,0,0,0,iVar6,iVar5);
        free(__s);
        return 0xffffffff;
      }
      for (iVar5 = 0; param_4 * param_3 - iVar5 != 0 && iVar5 <= param_4 * param_3;
          iVar5 = iVar5 + 1) {
        uVar3 = __urem32(iVar5 + uVar4,param_6);
        if (uVar3 != *(byte *)((int)__s + iVar5)) {
          uVar2 = __urem32(iVar5 + uVar4,param_6);
          printf(DAT_30070aec,iVar5,(uint)*(byte *)((int)__s + iVar5),uVar2,0,0,0);
        }
      }
    }
    free(__s);
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * testwrite @ 0x3006FC70  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: printf, sdmmcBlkDataRW
 * Константы: 0x3006FC70
 * Данные: DAT_30070af0, DAT_30070b9c
 * ---------------------------------------------------------------- */
void testwrite(undefined4 param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_30070af0;
  for (iVar3 = 0; iVar3 < 0x400; iVar3 = iVar3 + 1) {
    *(undefined1 *)(iVar1 + iVar3) = param_2;
  }
  if ((param_3 == 1) || (param_3 == 2)) {
    uVar2 = sdmmcBlkDataRW(0,param_1,param_3,iVar1,1);
    printf(DAT_30070b9c,uVar2);
  }
  return;
}

/* ----------------------------------------------------------------
 * testread @ 0x3006FCEC  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: printf, sdmmcBlkDataRW
 * Константы: 0x3006FCEC
 * Данные: DAT_30070af0, DAT_30070ba0, DAT_30070c48
 * ---------------------------------------------------------------- */
void testread(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_30070af0;
  for (iVar3 = 0; iVar3 < 0x400; iVar3 = iVar3 + 1) {
    *(undefined1 *)(iVar1 + iVar3) = 0;
  }
  if ((param_2 == 1) || (param_2 == 2)) {
    uVar2 = sdmmcBlkDataRW(0,param_1,param_2,iVar1,0);
    printf(DAT_30070ba0,uVar2);
    for (iVar3 = 0; iVar3 < 0x200; iVar3 = iVar3 + 1) {
      printf(DAT_30070c48,iVar3,(uint)*(byte *)(iVar1 + iVar3));
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * testerase @ 0x3006FD94  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: Erase_Card_Data
 * Константы: 0x3006FD94, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 testerase(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined1 auStack_1c [16];
  
  if (param_2 < param_1) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = Erase_Card_Data(auStack_1c,0,param_1,param_2 - 1);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sdmmcReadWrite @ 0x3006FDD8  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: printf, sdmmcBlkDataRW
 * Константы: 0x3006FDD8
 * Данные: DAT_30070cd8
 * ---------------------------------------------------------------- */
int sdmmcReadWrite(int param_1,uint param_2,int param_3,undefined1 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (param_2 <= uVar2) {
      return 0;
    }
    iVar1 = sdmmcBlkDataRW(0,param_1 + uVar2 >> 9,0x80,param_3 + uVar2,param_4);
    if (iVar1 != 0) break;
    uVar2 = uVar2 + 0x10000;
  }
  printf(DAT_30070cd8,uVar2,iVar1);
  return iVar1;
}

/* ----------------------------------------------------------------
 * testSdPerR @ 0x3006FE60  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: free, memalign, printf, sdmmcBlkDataRW
 * Константы: 0x3006FE60
 * Данные: DAT_30070cdc, DAT_30070dcc
 * ---------------------------------------------------------------- */
void testSdPerR(uint param_1)

{
  void *__ptr;
  int iVar1;
  uint uVar2;
  
  __ptr = (void *)memalign(0x400,0x10000);
  if (__ptr != (void *)0x0) {
    printf(DAT_30070cdc);
    for (uVar2 = 0; uVar2 < param_1; uVar2 = uVar2 + 0x80) {
      iVar1 = sdmmcBlkDataRW(0,uVar2,0x80,__ptr,0);
      if (iVar1 != 0) {
        printf(DAT_30070dcc,uVar2,iVar1);
        break;
      }
    }
    free(__ptr);
  }
  return;
}

/* ----------------------------------------------------------------
 * testSdPerW @ 0x3006FEF8  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: free, memalign, printf, sdmmcBlkDataRW
 * Константы: 0x3006FEF8
 * Данные: DAT_30070cdc, DAT_30070dcc
 * ---------------------------------------------------------------- */
void testSdPerW(uint param_1)

{
  void *__ptr;
  int iVar1;
  uint uVar2;
  
  __ptr = (void *)memalign(0x400,0x10000);
  if (__ptr != (void *)0x0) {
    printf(DAT_30070cdc);
    for (uVar2 = 0; uVar2 < param_1; uVar2 = uVar2 + 0x80) {
      iVar1 = sdmmcBlkDataRW(0,uVar2,0x80,__ptr,1);
      if (iVar1 != 0) {
        printf(DAT_30070dcc,uVar2,iVar1);
        break;
      }
    }
    free(__ptr);
  }
  return;
}

/* ----------------------------------------------------------------
 * sdmmcGetStatus @ 0x3006FF90  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 0
 * Вызывают: TFUP_CheckTask, sdmmcBlkRd, sdmmcBlkWrt, sdmmcUpdateIdentify, sdmmcUsbGetStatus
 * Константы: 0x3006FF90
 * Данные: DAT_30070dd0
 * ---------------------------------------------------------------- */
undefined4 sdmmcGetStatus(void)

{
  return *DAT_30070dd0;
}

/* ----------------------------------------------------------------
 * sdmmcUsbGetStatus @ 0x3006FF9C  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: sdmmcGetStatus
 * Вызывают: sdmmcUsbSecRead, sdmmcUsbSecWrite
 * Константы: 0x3006FF9C, 0xFFFFFFFF
 * Данные: DAT_30070dd4
 * ---------------------------------------------------------------- */
undefined4 sdmmcUsbGetStatus(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sdmmcGetStatus();
  if ((iVar1 == 0) || (*DAT_30070dd4 != 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * sdmmcUsbSecRead @ 0x3006FFD0  (примерный размер ~216 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: sdmmcBlkDataRW, sdmmcUsbGetStatus
 * Вызывают: testSdRW, testUsbSdRW0x2040
 * Константы: 0x3006FFD0
 * Данные: DAT_30070dd4
 * ---------------------------------------------------------------- */
int sdmmcUsbSecRead(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = sdmmcUsbGetStatus();
  if (iVar1 == 0) {
    if (*DAT_30070dd4 == 1) {
      iVar1 = -1;
    }
    else {
      for (; iVar1 = 0, iVar3 < (int)(param_2 & 0xffff); iVar3 = iVar3 + iVar1) {
        iVar1 = (param_2 & 0xffff) - iVar3;
        if (0x80 < iVar1) {
          iVar1 = 0x80;
        }
        iVar2 = sdmmcBlkDataRW(0,param_1 + iVar3,iVar1,param_3 + iVar3 * 0x200,0);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sdmmcUsbSecWrite @ 0x300700A8  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: sdmmcBlkDataRW, sdmmcUsbGetStatus
 * Вызывают: testSdRW, testUsbSdRW0x2040
 * Константы: 0xFFFFFFFF, 0x300700A8
 * Данные: DAT_30070dd4, DAT_30070fe0
 * ---------------------------------------------------------------- */
undefined4 sdmmcUsbSecWrite(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *DAT_30070fe0 = 0;
  iVar1 = sdmmcUsbGetStatus();
  if (iVar1 == 0) {
    if (*DAT_30070dd4 == 1) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = sdmmcBlkDataRW(0,param_1,param_2,param_3,1);
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * testSdRW @ 0x30070124  (примерный размер ~424 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: free, memalign, memcmp, memset, printf, sdmmcUsbSecRead, sdmmcUsbSecWrite, taskDelay
 * Константы: 0xFFFFFFFF, 0x30070124
 * Данные: DAT_30070dcc, DAT_30070fe4, DAT_300710cc, DAT_300710d0, DAT_300711c4
 * ---------------------------------------------------------------- */
undefined4 testSdRW(uint param_1,uint param_2)

{
  undefined4 uVar1;
  void *__ptr;
  void *__ptr_00;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  if (*(char *)(DAT_30070fe4 + 1) == '\b') {
    uVar5 = *(uint *)(DAT_30070fe4 + 4);
  }
  else {
    uVar5 = *(uint *)(DAT_30070fe4 + 4) >> 9;
  }
  if ((param_2 < param_1 + 0x80) || (uVar5 <= param_2)) {
    uVar1 = 0xffffffff;
  }
  else {
    __ptr = (void *)memalign(0x400,0x10000);
    if (__ptr == (void *)0x0) {
      uVar1 = 0xffffffff;
    }
    else {
      __ptr_00 = (void *)memalign(0x400,0x10000);
      if (__ptr_00 == (void *)0x0) {
        free(__ptr);
        uVar1 = 0xffffffff;
      }
      else {
        for (uVar5 = 0; uVar5 < 0x10000; uVar5 = uVar5 + 1) {
          *(char *)((int)__ptr + uVar5) = (char)uVar5;
        }
        printf(DAT_300710cc,param_2 - param_1);
        for (; param_1 < param_2; param_1 = param_1 + 0x80) {
          memset(__ptr_00,0,0x10000);
          uVar5 = sdmmcUsbSecWrite(param_1,0x80,__ptr);
          uVar2 = sdmmcUsbSecRead(param_1,0x80,__ptr_00);
          uVar3 = memcmp(__ptr,__ptr_00,0x10000);
          uVar4 = uVar3 | uVar2 | uVar5 | uVar4;
          if (uVar4 == 0) {
            printf(DAT_300710d0,param_1);
          }
          else {
            printf(DAT_30070dcc,param_1,uVar4);
          }
          taskDelay(5);
        }
        free(__ptr);
        free(__ptr_00);
        printf(DAT_300711c4);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * testUsbSdRW0x2040 @ 0x300702CC  (примерный размер ~320 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: free, memalign, memcmp, printf, sdmmcUsbSecRead, sdmmcUsbSecWrite
 * Константы: 0xFFFFFFFF, 0x300702CC
 * Данные: DAT_30071270, DAT_30071274, DAT_30071278
 * ---------------------------------------------------------------- */
undefined4 testUsbSdRW0x2040(int param_1)

{
  void *__ptr;
  undefined4 uVar1;
  void *__ptr_00;
  int iVar2;
  uint uVar3;
  
  __ptr = (void *)memalign(0x400,0x10000);
  if (__ptr == (void *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    __ptr_00 = (void *)memalign(0x400,0x10000);
    if (__ptr_00 == (void *)0x0) {
      free(__ptr);
      uVar1 = 0xffffffff;
    }
    else {
      for (uVar3 = 0; uVar3 < 0x4000; uVar3 = uVar3 + 1) {
        *(uint *)((int)__ptr + uVar3 * 4) = uVar3;
      }
      for (uVar3 = 1; uVar3 < 0x81; uVar3 = uVar3 + 1) {
        sdmmcUsbSecWrite(param_1,uVar3,(int)__ptr + uVar3 * -0x200 + 0x10000);
        sdmmcUsbSecRead(param_1,uVar3,(int)__ptr_00 + uVar3 * -0x200 + 0x10000);
        iVar2 = memcmp((void *)((int)__ptr + uVar3 * -0x200 + 0x10000),
                       (void *)((int)__ptr_00 + uVar3 * -0x200 + 0x10000),uVar3 << 9);
        if (iVar2 == 0) {
          printf(DAT_30071274,param_1,param_1 + uVar3 + -1);
        }
        else {
          printf(DAT_30071270,param_1,param_1 + uVar3 + -1,iVar2);
        }
        param_1 = param_1 + uVar3;
      }
      free(__ptr);
      free(__ptr_00);
      printf(DAT_30071278);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * testcallback @ 0x3007040C  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x3007040C
 * Данные: DAT_3007127c
 * ---------------------------------------------------------------- */
void testcallback(void)

{
  logMsg(DAT_3007127c,0,0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * sdmmcInit @ 0x30070448  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: SD_MMC_Host_Init
 * Вызывают: sdmmcDrv
 * Константы: 0x30070448
 * Данные: DAT_30071280, DAT_30071284
 * ---------------------------------------------------------------- */
int sdmmcInit(void)

{
  int iVar1;
  
  *DAT_30071280 = 1;
  *DAT_30071284 = 0;
  iVar1 = SD_MMC_Host_Init();
  *DAT_30071280 = 0;
  if (iVar1 != 0) {
    *DAT_30071284 = 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sdmmcDrvExit @ 0x30070494  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 5
 * Вызывает: Clk_Enable, SD_MMC_Host_Exit, printf, sdmmcHwExit, semGive
 * Вызывают: sdmmcExit, sdmmcStatusPollTask
 * Константы: 0x30070494
 * Данные: DAT_30070dd0, DAT_30070fe4, DAT_30071360, DAT_30071364, DAT_30071368, DAT_3007136c, DAT_30071370
 * ---------------------------------------------------------------- */
undefined4 sdmmcDrvExit(void)

{
  *DAT_30071360 = *(uint *)(DAT_30070fe4 + 4) >> 10;
  if (*DAT_30070dd0 != 0) {
    SD_MMC_Host_Exit();
    Clk_Enable(0,0);
    sdmmcHwExit();
    *DAT_30070dd0 = 0;
    *DAT_30071364 = 0;
    printf(DAT_30071368);
    if (*(int *)(DAT_3007136c + 8) != 0) {
      (**(code **)(DAT_3007136c + 8))();
    }
    semGive(*DAT_30071370);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * sdmmcExit @ 0x30070534  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: free, logMsg, sdmmcDrvExit, taskDelay, xbdBlkDevDelete
 * Константы: 0x30070534
 * Данные: DAT_30071374, DAT_30071378, DAT_3007140c
 * ---------------------------------------------------------------- */
void sdmmcExit(void)

{
  if (*DAT_30071374 != 0) {
    taskDelay(100);
    xbdBlkDevDelete(*DAT_30071374,DAT_30071378);
    free((void *)*DAT_30071378);
    *DAT_30071378 = 0;
    sdmmcDrvExit();
    logMsg(DAT_3007140c,0,0,0,0,0,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * sdmmcEraseBlk @ 0x300705BC  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: Erase_Card_Data, printf, semGive, semTake
 * Константы: 0x300705BC, 0xFFFFFFFF
 * Данные: DAT_30071410, DAT_30071414, DAT_30071418
 * ---------------------------------------------------------------- */
int sdmmcEraseBlk(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_24 [16];
  
  semTake(*DAT_30071410,0xffffffff);
  if (*(char *)(DAT_30071414 + param_1 * 0x88) == '\x01') {
    iVar1 = Erase_Card_Data(auStack_24,param_1,param_2 << 9,(param_2 + param_3) * 0x200 + -1);
  }
  else {
    iVar1 = Erase_Card_Data(auStack_24,param_1,param_2,param_2 + param_3 + -1);
  }
  if (iVar1 != 0) {
    printf(DAT_30071418,iVar1);
  }
  semGive(*DAT_30071410);
  return iVar1;
}

/* ----------------------------------------------------------------
 * sdmmcDrv @ 0x30070668  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 2
 * Вызывает: printf, sdmmcInit
 * Вызывают: sdmmcISRInit, sdmmcStatusPollTask
 * Константы: 0x30070668
 * Данные: DAT_30070dd0, DAT_3007136c, DAT_3007141c, DAT_30071420
 * ---------------------------------------------------------------- */
int sdmmcDrv(void)

{
  int iVar1;
  
  iVar1 = sdmmcInit();
  if (iVar1 == 0) {
    printf(DAT_3007141c);
    *DAT_30070dd0 = 1;
    if (*(int *)(DAT_3007136c + 0x10) != 0) {
      (**(code **)(DAT_3007136c + 0x10))();
      printf(DAT_30071420);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sdmmcDevCreate @ 0x300706CC  (примерный размер ~308 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: malloc, printf
 * Вызывают: TFUP_dosFsDevCreate
 * Константы: 0x300706CC
 * Данные: DAT_30070dd0, DAT_30070fe4, DAT_30071424, DAT_30071428, DAT_3007142c, DAT_30071430, DAT_30071434, DAT_30071438
 * ---------------------------------------------------------------- */
undefined4 * sdmmcDevCreate(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  printf(DAT_30071424);
  if (*DAT_30070dd0 == 0) {
    printf(DAT_30071428);
    puVar1 = (undefined4 *)0x0;
  }
  else {
    if (*DAT_3007142c == 0) {
      pvVar2 = malloc(0x3c);
      *DAT_3007142c = (int)pvVar2;
      if (*DAT_3007142c == 0) {
        return (undefined4 *)0x0;
      }
    }
    *(undefined4 *)(*DAT_3007142c + 0x34) = 0;
    *(undefined4 *)(*DAT_3007142c + 0x38) = 0;
    puVar1 = (undefined4 *)*DAT_3007142c;
    if (*(char *)(DAT_30070fe4 + 1) == '\x01') {
      puVar1[6] = *(uint *)(DAT_30070fe4 + 4) >> 9;
    }
    else {
      puVar1[6] = *(undefined4 *)(DAT_30070fe4 + 4);
    }
    puVar1[7] = 0x200;
    puVar1[8] = 1;
    puVar1[9] = 1;
    puVar1[5] = 1;
    puVar1[10] = 1;
    puVar1[0xb] = 2;
    puVar1[0xc] = 1;
    *puVar1 = DAT_30071430;
    puVar1[1] = DAT_30071434;
    puVar1[2] = DAT_30071438;
    puVar1[3] = DAT_3007143c;
    puVar1[4] = DAT_30071440;
    printf(DAT_30071444);
  }
  return puVar1;
}

/* ----------------------------------------------------------------
 * sdmmcBlkRd @ 0x30070800  (примерный размер ~284 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 7
 * Вызывает: logMsg, sdmmcBlkDataRW, sdmmcGetStatus, taskIdSelf, taskNameToId, taskPriorityGet, taskPrioritySet
 * Константы: 0xFFFFFFFF, 0x30070800
 * Данные: DAT_30071448, DAT_3007144c, DAT_30071450
 * ---------------------------------------------------------------- */
undefined4 sdmmcBlkRd(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_20;
  
  local_20 = 0;
  iVar1 = taskIdSelf();
  iVar2 = taskPriorityGet(iVar1,&local_20);
  if (iVar2 == 0) {
    if ((local_20 < 0x3c) && (iVar2 = taskNameToId(DAT_30071448), iVar2 == iVar1)) {
      logMsg(DAT_3007144c,0,0,0,0,0,0);
      taskPrioritySet(iVar1,0x91);
    }
  }
  else {
    logMsg(DAT_30071450,iVar2,0,0,0,0,0);
  }
  iVar1 = sdmmcGetStatus();
  if (iVar1 == 0) {
    uVar3 = 0xffffffff;
  }
  else if ((param_1 == 0) || (param_4 == 0)) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = sdmmcBlkDataRW(*(undefined4 *)(param_1 + 0x34),param_2,param_3,param_4,0);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * sdmmcBlkWrt @ 0x3007091C  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: sdmmcBlkDataRW, sdmmcGetStatus
 * Константы: 0xFFFFFFFF, 0x3007091C
 * ---------------------------------------------------------------- */
undefined4 sdmmcBlkWrt(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sdmmcGetStatus();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else if ((param_1 == 0) || (param_4 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = sdmmcBlkDataRW(*(undefined4 *)(param_1 + 0x34),param_2,param_3,param_4,1);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * sdmmcIoctl @ 0x3007098C  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3007098C
 * ---------------------------------------------------------------- */
undefined4 sdmmcIoctl(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * sdmmcReset @ 0x30070994  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30070994
 * ---------------------------------------------------------------- */
undefined4 sdmmcReset(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * sdmmcStatus @ 0x3007099C  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3007099C
 * ---------------------------------------------------------------- */
undefined4 sdmmcStatus(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * sdmmcCheckStatus @ 0x300709A4  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_PMU_LDOCtrl
 * Константы: 0x300709A4
 * Данные: DAT_30071454
 * ---------------------------------------------------------------- */
uint sdmmcCheckStatus(void)

{
  BSP_PMU_LDOCtrl(10,1);
  return *DAT_30071454 >> 8 & 1;
}

/* ----------------------------------------------------------------
 * sdmmcISRInit @ 0x300709C8  (примерный размер ~736 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 15
 * Вызывает: BSP_PMU_LDOCtrl, BSP_PMU_LDOVoltSet, Clk_Enable_Disable, OSAL_LogMsg, OSAL_SemBCreate, Set_Clk_Frequency, cacheDmaMalloc, logMsg, memset, printf, sdmmcDrv, sdmmcHwInit, semBCreate, semMCreate
 *           ...
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x300709C8
 * Данные: DAT_30071370, DAT_30071410, DAT_30071458, DAT_3007145c, DAT_30071460, DAT_30071464, DAT_30071468, DAT_3007146c
 * ---------------------------------------------------------------- */
void sdmmcISRInit(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_c [4];
  
  sdmmcHwInit();
  iVar1 = Set_Clk_Frequency(0,0x3f,auStack_c);
  if (iVar1 == 0) {
    printf(DAT_30071458);
  }
  else {
    printf(DAT_3007145c,iVar1);
  }
  Clk_Enable_Disable(0,1);
  iVar1 = cacheDmaMalloc(0x40);
  *DAT_30071460 = iVar1;
  if (*DAT_30071460 == 0) {
    printf(DAT_30071464);
  }
  else {
    iVar1 = OSAL_SemBCreate(0,0);
    *DAT_30071468 = iVar1;
    if (*DAT_30071468 == 0) {
      logMsg(DAT_3007146c,0,0,0,0,0,0);
    }
    else {
      iVar1 = semMCreate(0xd);
      *DAT_30071410 = iVar1;
      if (*DAT_30071410 == 0) {
        logMsg(DAT_30071470,0,0,0,0,0,0);
      }
      else {
        iVar1 = semBCreate(1,0);
        *DAT_30071370 = iVar1;
        if (*DAT_30071370 == 0) {
          logMsg(DAT_30071474,0,0,0,0,0,0);
        }
        else {
          iVar1 = semBCreate(1,0);
          *DAT_30071478 = iVar1;
          if (*DAT_30071478 == 0) {
            logMsg(DAT_3007147c,0,0,0,0,0,0);
          }
          else {
            iVar1 = OSAL_SemBCreate(0,0);
            *DAT_30071480 = iVar1;
            if (*DAT_30071480 == 0) {
              OSAL_LogMsg(DAT_30071484,0,0,0,0,0,0);
            }
            else {
              uVar2 = semMCreate(0xd);
              *DAT_30071488 = uVar2;
              if (*DAT_30071410 == 0) {
                logMsg(DAT_30071470,0,0,0,0,0,0);
              }
              else {
                BSP_PMU_LDOVoltSet(7,300);
                BSP_PMU_LDOCtrl(7,1);
                taskDelay(2);
                BSP_PMU_LDOVoltSet(10,300);
                BSP_PMU_LDOCtrl(10,1);
                taskDelay(2);
                sdmmcDrv();
                memset(DAT_3007148c,0,0x4c);
              }
            }
          }
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * sdmmcGetCapacity @ 0x30070CA8  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: sdmmcUsbReadCapacity
 * Константы: 0x30070CA8
 * Данные: DAT_30070dd0, DAT_30070fe4
 * ---------------------------------------------------------------- */
uint sdmmcGetCapacity(void)

{
  uint uVar1;
  
  if (*DAT_30070dd0 == 0) {
    uVar1 = 0;
  }
  else if (*(char *)(DAT_30070fe4 + 1) == '\x01') {
    uVar1 = *(uint *)(DAT_30070fe4 + 4) >> 9;
  }
  else {
    uVar1 = *(uint *)(DAT_30070fe4 + 4);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sdmmcUsbReadCapacity @ 0x30070CF4  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: sdmmcGetCapacity
 * Константы: 0x30070CF4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 sdmmcUsbReadCapacity(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sdmmcGetCapacity();
  *param_1 = iVar1;
  if (iVar1 == 0) {
    *param_2 = 0;
    uVar2 = 0xffffffff;
  }
  else {
    *param_2 = 0x200;
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * sdmmcExcInit @ 0x30070D34  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30070D34
 * ---------------------------------------------------------------- */
void sdmmcExcInit(void)

{
  return;
}

/* ----------------------------------------------------------------
 * sdmmcStatusPollTask @ 0x30070D38  (примерный размер ~888 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 14
 * Вызывает: Clk_Enable_Disable, HI6451_voltage_set, HI6451_voltage_switch, Set_Clk_Frequency, logMsg, pmGetLDOStatus, printf, sdmmcDrv, sdmmcDrvExit, sdmmcGetStausPoll, sdmmcPollBusyBit, semGive, semTake, taskDelay
 * Константы: 0x30070D38, 0xFFFFFFFF, 0x00400000, 0xFFBFFFFF
 * Данные: DAT_30071410, DAT_30071454, DAT_30071490, DAT_30071494, DAT_30071498, DAT_3007149c, DAT_300714a0, DAT_300714a4
 * ---------------------------------------------------------------- */
void sdmmcStatusPollTask(void)

{
  int iVar1;
  char local_14;
  undefined1 auStack_13 [3];
  
  semTake(*DAT_30071410,0xffffffff);
  pmGetLDOStatus(7,&local_14);
  if (local_14 == '\0') {
    HI6451_voltage_set(7,300);
    HI6451_voltage_switch(7,1);
    printf(DAT_30071490);
    taskDelay(2);
  }
  pmGetLDOStatus(10,&local_14);
  if (local_14 == '\0') {
    HI6451_voltage_set(10,300);
    HI6451_voltage_switch(10,1);
    printf(DAT_30071490);
    taskDelay(2);
  }
  if (*DAT_30071494 == 1) {
    if ((*DAT_30071454 & 0x100) == 0) {
      *DAT_30071498 = 0;
      sdmmcDrvExit();
      HI6451_voltage_switch(7,0);
    }
    else {
      iVar1 = sdmmcGetStausPoll(0);
      if (iVar1 == 0) {
        *DAT_30071498 = 1;
      }
      else {
        *DAT_30071498 = 0;
        sdmmcDrvExit();
        taskDelay(100);
        iVar1 = sdmmcDrv();
        if (iVar1 == 0) {
          *DAT_30071498 = 1;
          if (*DAT_3007149c != 0) {
            logMsg(DAT_300714a0,0,0,0,0,0,0);
          }
        }
        else {
          *DAT_30071498 = 0;
          sdmmcDrvExit();
          HI6451_voltage_switch(7,0);
          taskDelay(2);
          HI6451_voltage_switch(10,0);
          taskDelay(2);
        }
      }
    }
  }
  else {
    iVar1 = Set_Clk_Frequency(0,0x3f,auStack_13);
    if (iVar1 == 0) {
      printf(DAT_300714a4);
    }
    else {
      *DAT_300714a8 = *DAT_300714a8 | 0x400000;
      taskDelay(5);
      *DAT_300714a8 = *DAT_300714a8 & 0xffbfffff;
      taskDelay(5);
      semGive(*DAT_30071410);
    }
    iVar1 = Clk_Enable_Disable(0,1);
    if (iVar1 != 0) {
      logMsg(DAT_300714ac,iVar1,0,0,0,0,0);
    }
    if ((*DAT_30071454 & 0x100) == 0) {
      *DAT_30071498 = 0;
    }
    else {
      iVar1 = sdmmcDrv();
      if (iVar1 == 0) {
        *DAT_30071498 = 1;
      }
      else {
        *DAT_30071498 = 0;
        sdmmcDrvExit();
      }
    }
  }
  *DAT_30071494 = *DAT_30071498;
  if (*DAT_3007149c != 0) {
    if (*DAT_30071494 == 0) {
      logMsg(DAT_300714b4,0,0,0,0,0,0);
    }
    else {
      logMsg(DAT_300714b0,0,0,0,0,0,0);
    }
  }
  sdmmcPollBusyBit();
  semGive(*DAT_30071410);
  return;
}

/* ----------------------------------------------------------------
 * sdmmcErrLogRecordTask @ 0x300710B0  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300710B0
 * ---------------------------------------------------------------- */
undefined4 sdmmcErrLogRecordTask(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * sdmmcIpReset @ 0x300710B8  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: taskDelay
 * Константы: 0x300710B8
 * Данные: DAT_300714b8
 * ---------------------------------------------------------------- */
void sdmmcIpReset(void)

{
  *DAT_300714b8 = 1;
  taskDelay(2);
  return;
}

/* ----------------------------------------------------------------
 * sdmmcInqTransferData @ 0x300710D4  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300710D4
 * Данные: DAT_300714bc, DAT_300714c0, DAT_300714c4
 * ---------------------------------------------------------------- */
uint sdmmcInqTransferData(void)

{
  uint uVar1;
  uint uVar2;
  
  *DAT_300714bc = 1;
  uVar1 = *DAT_300714c0;
  uVar2 = *DAT_300714c4;
  *DAT_300714bc = 0;
  return uVar2 & uVar1 >> 9;
}

/* ----------------------------------------------------------------
 * sdmmcExcWrite @ 0x30071114  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: ISR_Callback
 * Константы: 0x30071114
 * ---------------------------------------------------------------- */
void sdmmcExcWrite(void)

{
  return;
}

/* ----------------------------------------------------------------
 * sdmmcIsEnableSleep @ 0x30071118  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30071118
 * Данные: DAT_30071280
 * ---------------------------------------------------------------- */
bool sdmmcIsEnableSleep(void)

{
  return *DAT_30071280 == 0;
}

/* ----------------------------------------------------------------
 * sdmmcOverCurrentProtect @ 0x3007113C  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: OSAL_LogMsg
 * Константы: 0x3007113C
 * Данные: DAT_300714c8
 * ---------------------------------------------------------------- */
void sdmmcOverCurrentProtect(void)

{
  OSAL_LogMsg(DAT_300714c8,1,2,3,4,5,6);
  return;
}

/* ----------------------------------------------------------------
 * sdmmcGetDosFsDevName @ 0x30071178  (примерный размер ~320 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, calloc, dosFsShow, strcpy, strlen
 * Вызывают: TFUP_CheckFileValidify, TFUP_GetFileType, TFUP_LogInit
 * Константы: 0x30071178
 * Данные: DAT_300714cc, DAT_300714d0, DAT_300714d4, DAT_300714d8, DAT_300714dc, DAT_300714e0
 * ---------------------------------------------------------------- */
size_t * sdmmcGetDosFsDevName(void)

{
  int iVar1;
  size_t *psVar2;
  size_t sVar3;
  
  iVar1 = dosFsShow(DAT_300714cc,1);
  if (iVar1 == 0) {
    psVar2 = (size_t *)calloc(0x14,1);
    if (psVar2 == (size_t *)0x0) {
      OSAL_LogMsg(DAT_300714d0,1,2,3,4,5,6);
      psVar2 = (size_t *)0x0;
    }
    else {
      strcpy((char *)(psVar2 + 1),DAT_300714d4);
      sVar3 = strlen(DAT_300714d4);
      *psVar2 = sVar3;
    }
  }
  else {
    iVar1 = dosFsShow(DAT_300714d8,1);
    if (iVar1 == 0) {
      psVar2 = (size_t *)calloc(0x14,1);
      if (psVar2 == (size_t *)0x0) {
        OSAL_LogMsg(DAT_300714dc,1,2,3,4,5,6);
        psVar2 = (size_t *)0x0;
      }
      else {
        strcpy((char *)(psVar2 + 1),DAT_300714e0);
        sVar3 = strlen(DAT_300714e0);
        *psVar2 = sVar3;
      }
    }
    else {
      psVar2 = (size_t *)0x0;
    }
  }
  return psVar2;
}

/* ----------------------------------------------------------------
 * transfer_mode_config @ 0x300712B8  (примерный размер ~592 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: Read_Write_IPreg
 * Вызывают: Send_cmd_to_host_raw
 * Константы: 0x300712B8, 0xFDFFFFDF, 0x02000010
 * Данные: DAT_300714b8, DAT_300714e4, DAT_300714e8, DAT_300714ec, DAT_300714f0, DAT_300714f4, DAT_300714f8, DAT_300714fc
 * ---------------------------------------------------------------- */
void transfer_mode_config(int param_1)

{
  uint local_10;
  uint local_c;
  
  if (param_1 == 0) {
    Read_Write_IPreg(0x24,&local_c,0);
    local_c = local_c & DAT_300714fc | DAT_30071504;
    Read_Write_IPreg(0x24,&local_c,1);
    local_10 = local_10 | 0x10;
    Read_Write_IPreg(0,&local_10,0);
    local_10 = local_10 & 0xfdffffdf;
    Read_Write_IPreg(0,&local_10,1);
  }
  else {
    *DAT_300714e4 = 1;
    *DAT_300714e4 = 0x82;
    *DAT_300714e8 = DAT_300714ec;
    *DAT_300714f0 = DAT_300714f4;
    *DAT_300714f8 = *DAT_300714f8 & DAT_300714fc | DAT_30071500;
    *DAT_300714b8 = *DAT_300714b8 | 0x2000010;
  }
  return;
}

/* ----------------------------------------------------------------
 * sdmmcGetFatData @ 0x30071508  (примерный размер ~1088 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: logMsg, memcmp, memcpy, sdmmcBlkDataRW, strlen, strncmp
 * Вызывают: sdmmcUpdateIdentify
 * Константы: 0x30071508, 0xFFFFFFFF
 * Данные: DAT_300724e4, DAT_300724e8, DAT_300724ec, DAT_300724f0, DAT_300724f4, DAT_300724f8, DAT_300724fc, DAT_30072500
 * ---------------------------------------------------------------- */
undefined4 sdmmcGetFatData(void)

{
  void *pvVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  
  iVar3 = sdmmcBlkDataRW(0,0,1,DAT_300724e4,0);
  puVar2 = DAT_300724ec;
  pvVar1 = DAT_300724e4;
  if (iVar3 == 0) {
    DAT_300724ec[3] = 0;
    puVar2[2] = 0;
    puVar2[1] = 0;
    *puVar2 = 0;
    iVar3 = memcmp((void *)((int)pvVar1 + 0x36),DAT_300724f0,5);
    if (iVar3 == 0) {
      memcpy(DAT_300724f4,DAT_300724e4,0x3e);
      puVar2 = DAT_30072504;
      iVar8 = (uint)*DAT_300724fc * (uint)(byte)DAT_300724ec[0x14] + (uint)*DAT_300724f8;
      iVar3 = (int)((uint)*DAT_30072500 * 0x20) >> 9;
      iVar10 = iVar8 + iVar3;
      DAT_30072504[3] = (char)((uint)iVar10 >> 0x18);
      puVar2[2] = (char)((uint)iVar10 >> 0x10);
      puVar2[1] = (char)((uint)iVar10 >> 8);
      *puVar2 = (char)iVar10;
      for (iVar10 = 0; iVar10 < iVar3; iVar10 = iVar10 + 1) {
        iVar5 = sdmmcBlkDataRW(0,iVar8 + iVar10,1,DAT_300724e4,0);
        if (iVar5 != 0) {
          logMsg(DAT_30072604,iVar8,0,0,0,0,0);
          return 0x7b;
        }
        for (iVar5 = 0; iVar5 < 0x10; iVar5 = iVar5 + 1) {
          pcVar9 = (char *)((int)DAT_300724e4 + iVar5 * 0x20);
          sVar6 = strlen(DAT_30072608);
          iVar7 = strncmp(pcVar9,DAT_30072608,sVar6);
          if (iVar7 == 0) {
            sVar6 = strlen(DAT_3007260c);
            iVar7 = strncmp(pcVar9 + 8,DAT_3007260c,sVar6);
            if (iVar7 == 0) {
              memcpy(DAT_30072610,pcVar9,0x20);
              puVar2 = DAT_300724ec;
              DAT_300724ec[3] = 0;
              puVar2[2] = 0;
              puVar2[1] = 0;
              *puVar2 = 1;
              return 0;
            }
          }
        }
      }
    }
    else {
      iVar3 = memcmp((void *)((int)pvVar1 + 0x52),DAT_30072614,5);
      if (iVar3 == 0) {
        memcpy(DAT_300726a8,DAT_300724e4,0x5a);
        puVar2 = DAT_30072504;
        iVar3 = *DAT_300726b0 * (uint)(byte)DAT_300724ec[0x52] + (uint)*DAT_300726ac;
        iVar8 = iVar3 + (uint)(byte)DAT_300724ec[0x4f];
        DAT_30072504[3] = (char)((uint)iVar8 >> 0x18);
        puVar2[2] = (char)((uint)iVar8 >> 0x10);
        puVar2[1] = (char)((uint)iVar8 >> 8);
        *puVar2 = (char)iVar8;
        for (iVar8 = 0; iVar8 < (int)(uint)(byte)DAT_300724ec[0x4f]; iVar8 = iVar8 + 1) {
          iVar10 = sdmmcBlkDataRW(0,iVar3 + iVar8,1,DAT_300724e4,0);
          if (iVar10 != 0) {
            logMsg(DAT_30072604,iVar3,0,0,0,0,0);
            return 0x7b;
          }
          for (iVar10 = 0; iVar10 < 0x10; iVar10 = iVar10 + 1) {
            pcVar9 = (char *)((int)DAT_300724e4 + iVar10 * 0x20);
            sVar6 = strlen(DAT_30072608);
            iVar5 = strncmp(pcVar9,DAT_30072608,sVar6);
            if (iVar5 == 0) {
              sVar6 = strlen(DAT_3007260c);
              iVar5 = strncmp(pcVar9 + 8,DAT_3007260c,sVar6);
              if (iVar5 == 0) {
                memcpy(DAT_30072610,pcVar9,0x20);
                puVar2 = DAT_300724ec;
                DAT_300724ec[3] = 0;
                puVar2[2] = 0;
                puVar2[1] = 0;
                *puVar2 = 2;
                return 0;
              }
            }
          }
        }
      }
    }
    uVar4 = 0xffffffff;
  }
  else {
    logMsg(DAT_300724e8,0,0,0,0,0,0);
    uVar4 = 0x7b;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * sdmmcGetFat16 @ 0x30071948  (примерный размер ~304 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: __div32, logMsg, sdmmcBlkDataRW
 * Вызывают: sdmmcUpdateIdentify
 * Константы: 0x30071948
 * Данные: DAT_300724ec, DAT_300724f8, DAT_300724fc, DAT_3007291c, DAT_30072920
 * ---------------------------------------------------------------- */
undefined4 sdmmcGetFat16(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = (uint)*DAT_300724fc;
  iVar1 = __div32(*DAT_300724fc,*(undefined1 *)(DAT_300724ec + 0x11));
  uVar5 = (uint)*DAT_300724f8;
  iVar4 = 0;
  while( true ) {
    if ((iVar1 + 1 <= iVar4) || ((int)uVar6 < 1)) {
      return 0;
    }
    uVar3 = uVar6;
    if ((int)(uint)*(byte *)(DAT_300724ec + 0x11) <= (int)uVar6) {
      uVar3 = (uint)*(byte *)(DAT_300724ec + 0x11);
    }
    iVar2 = sdmmcBlkDataRW(0,uVar5,uVar3,*DAT_3007291c + (uVar5 - *DAT_300724f8) * 0x200,0);
    if (iVar2 != 0) break;
    uVar6 = uVar6 - uVar3;
    uVar5 = uVar5 + uVar3;
    iVar4 = iVar4 + 1;
  }
  logMsg(DAT_30072920,uVar5,0,0,0,0,0);
  return 0x7b;
}

/* ----------------------------------------------------------------
 * sdmmcGetFat32 @ 0x30071A78  (примерный размер ~328 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: __udiv32, logMsg, sdmmcBlkDataRW
 * Вызывают: sdmmcUpdateIdentify
 * Константы: 0x30071A78
 * Данные: DAT_300724ec, DAT_300726ac, DAT_300726b0, DAT_30072a40, DAT_30072a44
 * ---------------------------------------------------------------- */
undefined4 sdmmcGetFat32(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = *DAT_300726b0;
  iVar1 = __udiv32(*DAT_300726b0,*(undefined1 *)(DAT_300724ec + 0x4f));
  uVar6 = (uint)*DAT_300726ac;
  iVar4 = 0;
  while( true ) {
    if ((iVar1 + 1 <= iVar4) || ((int)uVar5 < 1)) {
      return 0;
    }
    uVar3 = uVar5;
    if ((int)(uint)*(byte *)(DAT_300724ec + 0x4f) <= (int)uVar5) {
      uVar3 = (uint)*(byte *)(DAT_300724ec + 0x4f);
    }
    iVar2 = sdmmcBlkDataRW(0,uVar6,uVar3,*DAT_30072a40 + (uVar6 - *DAT_300726ac) * 0x200,0);
    if (iVar2 != 0) break;
    uVar5 = uVar5 - uVar3;
    uVar6 = uVar6 + uVar3;
    iVar4 = iVar4 + 1;
  }
  logMsg(DAT_30072a44,uVar6,0,0,0,0,0);
  return 0x7b;
}

/* ----------------------------------------------------------------
 * sdmmcLogicClusterToPhysicBlock16 @ 0x30071BC0  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: sdmmcGetFileClusterRestData16
 * Константы: 0x30071BC0
 * Данные: DAT_300724ec, DAT_30072504, DAT_3007291c, DAT_30072a48, DAT_30072af8
 * ---------------------------------------------------------------- */
undefined4 sdmmcLogicClusterToPhysicBlock16(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)*DAT_30072a48;
  uVar2 = 0;
  while( true ) {
    if (param_1 <= (uVar2 & 0xffff)) {
      *param_2 = (uVar1 - 2) * (uint)*(byte *)(DAT_300724ec + 0x11) + *DAT_30072504;
      return 0;
    }
    uVar1 = (uint)*(ushort *)(*DAT_3007291c + uVar1 * 2);
    if (DAT_30072af8 < uVar1 - 2) break;
    uVar2 = uVar2 + 1;
  }
  return 0x7d;
}

/* ----------------------------------------------------------------
 * sdmmcLogicClusterToPhysicBlock32 @ 0x30071C6C  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: sdmmcGetFileClusterRestData32
 * Константы: 0x30071C6C, 0xFFFFFFEF
 * Данные: DAT_300724ec, DAT_30072504, DAT_30072a40, DAT_30072a48, DAT_30072afc
 * ---------------------------------------------------------------- */
undefined4 sdmmcLogicClusterToPhysicBlock32(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = CONCAT22(*DAT_30072afc,*DAT_30072a48);
  uVar2 = 0;
  while( true ) {
    if (param_1 <= uVar2) {
      *param_2 = (uVar1 - 3) * (uint)*(byte *)(DAT_300724ec + 0x4f) + *DAT_30072504;
      return 0;
    }
    uVar1 = *(uint *)(*DAT_30072a40 + uVar1 * 4);
    if ((0xffffffef < uVar1) || (uVar1 < 2)) break;
    uVar2 = uVar2 + 1;
  }
  return 0x7d;
}

/* ----------------------------------------------------------------
 * sdmmcGetFileClusterRestData16 @ 0x30071D28  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: __udiv32, sdmmcBlkDataRW, sdmmcLogicClusterToPhysicBlock16
 * Вызывают: sdmmcGetUnitHeadData16, sdmmcGetUpdateUnitData16
 * Константы: 0x30071D28
 * Данные: DAT_300724ec, DAT_30072ccc
 * ---------------------------------------------------------------- */
undefined4 sdmmcGetFileClusterRestData16(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_1c;
  
  iVar1 = (uint)*(byte *)(DAT_300724ec + 0x11) * 0x200;
  iVar2 = __udiv32(param_1,iVar1);
  uVar3 = __udiv32(param_1,iVar1);
  iVar4 = sdmmcLogicClusterToPhysicBlock16(uVar3,&local_1c);
  if (iVar4 == 0) {
    iVar4 = sdmmcBlkDataRW(0,local_1c,*(undefined1 *)(DAT_300724ec + 0x11),*DAT_30072ccc,0);
    if (iVar4 == 0) {
      *param_2 = param_1 - iVar1 * iVar2;
      uVar3 = 0;
    }
    else {
      uVar3 = 0x7b;
    }
  }
  else {
    uVar3 = 0x7e;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * sdmmcGetFileClusterRestData32 @ 0x30071DCC  (примерный размер ~164 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: __udiv32, sdmmcBlkDataRW, sdmmcLogicClusterToPhysicBlock32
 * Вызывают: sdmmcGetUnitHeadData32, sdmmcGetUpdateUnitData32
 * Константы: 0x30071DCC
 * Данные: DAT_300724ec, DAT_30072cd0
 * ---------------------------------------------------------------- */
undefined4 sdmmcGetFileClusterRestData32(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_1c;
  
  iVar1 = (uint)*(byte *)(DAT_300724ec + 0x4f) * 0x200;
  iVar2 = __udiv32(param_1,iVar1);
  uVar3 = __udiv32(param_1,iVar1);
  iVar4 = sdmmcLogicClusterToPhysicBlock32(uVar3,&local_1c);
  if (iVar4 == 0) {
    iVar4 = sdmmcBlkDataRW(0,local_1c,*(undefined1 *)(DAT_300724ec + 0x4f),*DAT_30072cd0,0);
    if (iVar4 == 0) {
      *param_2 = param_1 - iVar1 * iVar2;
      uVar3 = 0;
    }
    else {
      uVar3 = 0x7b;
    }
  }
  else {
    uVar3 = 0x7e;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * sdmmcGetUnitHeadData16 @ 0x30071E70  (примерный размер ~500 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: memcpy, sdmmcGetFileClusterRestData16
 * Вызывают: sdmmcUpdateIdentify
 * Константы: 0x30071E70, 0xFFFFFFFC
 * Данные: DAT_300724ec, DAT_30072ccc, DAT_30072cd4, DAT_30072da0, DAT_30072e24, DAT_30072e28, DAT_30072e2c
 * ---------------------------------------------------------------- */
int sdmmcGetUnitHeadData16(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  size_t __n;
  int iVar4;
  int local_24;
  
  *DAT_30072cd4 = 0;
  iVar4 = 0x5c;
  iVar2 = 0;
  while( true ) {
    if (0xf < iVar2) {
      return 0;
    }
    iVar1 = sdmmcGetFileClusterRestData16(iVar4,&local_24);
    if (iVar1 != 0) {
      return iVar1;
    }
    if ((uint)*(byte *)(DAT_300724ec + 0x11) * 0x200 - local_24 < 0x62) {
      __n = (uint)*(byte *)(DAT_300724ec + 0x11) * 0x200 - local_24;
      memcpy((void *)((uint)*DAT_30072cd4 * 0x62 + DAT_30072da0),(void *)(*DAT_30072ccc + local_24),
             __n);
      iVar1 = sdmmcGetFileClusterRestData16(iVar4 + __n,&local_24);
      if (iVar1 != 0) {
        return iVar1;
      }
      memcpy((void *)((uint)*DAT_30072cd4 * 0x62 + __n + DAT_30072da0),(void *)*DAT_30072ccc,
             0x62 - __n);
    }
    else {
      memcpy((void *)((uint)*DAT_30072cd4 * 0x62 + DAT_30072da0),(void *)(*DAT_30072ccc + local_24),
             0x62);
    }
    if (*(int *)((uint)*DAT_30072cd4 * 0x62 + DAT_30072da0) != DAT_30072e24) break;
    uVar3 = *(int *)((uint)*DAT_30072cd4 * 0x62 + DAT_30072e28) +
            *(int *)((uint)*DAT_30072cd4 * 0x62 + DAT_30072e2c);
    if ((uVar3 & 3) != 0) {
      uVar3 = (uVar3 & 0xfffffffc) + 4;
    }
    iVar4 = iVar4 + uVar3;
    *DAT_30072cd4 = *DAT_30072cd4 + 1;
    iVar2 = iVar2 + 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * sdmmcGetUnitHeadData32 @ 0x30072064  (примерный размер ~500 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: memcpy, sdmmcGetFileClusterRestData32
 * Вызывают: sdmmcUpdateIdentify
 * Константы: 0x30072064, 0xFFFFFFFC
 * Данные: DAT_300724ec, DAT_30072cd0, DAT_30072cd4, DAT_30072da0, DAT_30072e24, DAT_30072e28, DAT_30072e2c
 * ---------------------------------------------------------------- */
int sdmmcGetUnitHeadData32(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  size_t __n;
  int iVar4;
  int local_24;
  
  *DAT_30072cd4 = 0;
  iVar4 = 0x5c;
  iVar2 = 0;
  while( true ) {
    if (0xf < iVar2) {
      return 0;
    }
    iVar1 = sdmmcGetFileClusterRestData32(iVar4,&local_24);
    if (iVar1 != 0) {
      return iVar1;
    }
    if ((uint)*(byte *)(DAT_300724ec + 0x4f) * 0x200 - local_24 < 0x62) {
      __n = (uint)*(byte *)(DAT_300724ec + 0x4f) * 0x200 - local_24;
      memcpy((void *)((uint)*DAT_30072cd4 * 0x62 + DAT_30072da0),(void *)(*DAT_30072cd0 + local_24),
             __n);
      iVar1 = sdmmcGetFileClusterRestData32(iVar4 + __n,&local_24);
      if (iVar1 != 0) {
        return iVar1;
      }
      memcpy((void *)((uint)*DAT_30072cd4 * 0x62 + __n + DAT_30072da0),(void *)*DAT_30072cd0,
             0x62 - __n);
    }
    else {
      memcpy((void *)((uint)*DAT_30072cd4 * 0x62 + DAT_30072da0),(void *)(*DAT_30072cd0 + local_24),
             0x62);
    }
    if (*(int *)((uint)*DAT_30072cd4 * 0x62 + DAT_30072da0) != DAT_30072e24) break;
    uVar3 = *(int *)((uint)*DAT_30072cd4 * 0x62 + DAT_30072e28) +
            *(int *)((uint)*DAT_30072cd4 * 0x62 + DAT_30072e2c);
    if ((uVar3 & 3) != 0) {
      uVar3 = (uVar3 & 0xfffffffc) + 4;
    }
    iVar4 = iVar4 + uVar3;
    *DAT_30072cd4 = *DAT_30072cd4 + 1;
    iVar2 = iVar2 + 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * sdmmcBufferMalloc @ 0x30072258  (примерный размер ~392 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: free, memalign
 * Вызывают: sdmmcUpdateIdentify
 * Константы: 0x30072258
 * Данные: DAT_300724ec, DAT_300724fc, DAT_300726b0, DAT_3007291c, DAT_30072a40, DAT_30072ccc, DAT_30072cd0
 * ---------------------------------------------------------------- */
undefined4 sdmmcBufferMalloc(void)

{
  int iVar1;
  
  if (*DAT_300724ec == 1) {
    iVar1 = memalign(0x200,(uint)*(byte *)((int)DAT_300724ec + 0x11) << 9);
    *DAT_30072ccc = iVar1;
    if (*DAT_30072ccc == 0) {
      return 0x7a;
    }
    iVar1 = memalign(0x200,(uint)*DAT_300724fc << 9);
    *DAT_3007291c = iVar1;
    if (*DAT_3007291c == 0) {
      free((void *)*DAT_30072ccc);
      *DAT_30072ccc = 0;
      return 0x7a;
    }
  }
  else {
    if (*DAT_300724ec != 2) {
      return 0x79;
    }
    iVar1 = memalign(0x200,(uint)*(byte *)((int)DAT_300724ec + 0x4f) << 9);
    *DAT_30072cd0 = iVar1;
    if (*DAT_30072cd0 == 0) {
      return 0x7a;
    }
    iVar1 = memalign(0x200,(uint)*DAT_300726b0 << 9);
    *DAT_30072a40 = iVar1;
    if (*DAT_30072a40 == 0) {
      free((void *)*DAT_30072cd0);
      *DAT_30072cd0 = 0;
      return 0x7a;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * sdmmcBufferFree @ 0x300723E0  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: free
 * Вызывают: sdmmcUpdateExit
 * Константы: 0x300723E0
 * Данные: DAT_3007291c, DAT_30072a40, DAT_30072ccc, DAT_30072cd0
 * ---------------------------------------------------------------- */
void sdmmcBufferFree(void)

{
  if (*DAT_30072ccc != 0) {
    free((void *)*DAT_30072ccc);
    *DAT_30072ccc = 0;
  }
  if (*DAT_30072cd0 != 0) {
    free((void *)*DAT_30072cd0);
    *DAT_30072cd0 = 0;
  }
  if (*DAT_3007291c != 0) {
    free((void *)*DAT_3007291c);
    *DAT_3007291c = 0;
  }
  if (*DAT_30072a40 != 0) {
    free((void *)*DAT_30072a40);
    *DAT_30072a40 = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * sdmmcGetUpdateUnitData16 @ 0x30072488  (примерный размер ~632 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: memcpy, sdmmcGetFileClusterRestData16
 * Вызывают: sdmmcGetUpdateUnitData
 * Константы: 0x30072488, 0xFFFFFFFC
 * Данные: DAT_300724ec, DAT_30072ccc, DAT_30072e28, DAT_30072e2c
 * ---------------------------------------------------------------- */
int sdmmcGetUpdateUnitData16(byte param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  size_t __n;
  int local_44;
  uint local_40;
  int local_3c;
  int local_38;
  int local_34;
  
  local_38 = (uint)*(byte *)(DAT_300724ec + 0x11) << 9;
  iVar1 = 0x5c;
  for (uVar3 = 0; uVar3 < param_1; uVar3 = uVar3 + 1) {
    uVar4 = *(int *)(uVar3 * 0x62 + DAT_30072e28) + *(int *)(uVar3 * 0x62 + DAT_30072e2c);
    if ((uVar4 & 3) != 0) {
      uVar4 = (uVar4 & 0xfffffffc) + 4;
    }
    iVar1 = iVar1 + uVar4;
  }
  uVar3 = iVar1 + param_3 * 0x20000;
  local_40 = *(int *)((uint)param_1 * 0x62 + DAT_30072e28) +
             *(int *)((uint)param_1 * 0x62 + DAT_30072e2c);
  if ((uint)(param_3 << 0x11) < local_40) {
    if (local_40 < param_3 * 0x20000 + 0x20000U) {
      local_3c = local_40 + param_3 * -0x20000;
    }
    else {
      local_3c = 0x20000;
    }
    uVar2 = uVar3 + local_3c;
    for (uVar4 = uVar3; uVar4 < uVar2; uVar4 = uVar4 + __n) {
      local_34 = sdmmcGetFileClusterRestData16(uVar4,&local_44);
      if (local_34 != 0) {
        return local_34;
      }
      if ((uint)(local_38 - local_44) < uVar2 - uVar4) {
        __n = local_38 - local_44;
      }
      else {
        __n = uVar2 - uVar4;
      }
      memcpy((void *)(param_2 + (uVar4 - uVar3)),(void *)(*DAT_30072ccc + local_44),__n);
    }
    iVar1 = 0;
  }
  else {
    iVar1 = 0x7c;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sdmmcGetUpdateUnitData32 @ 0x30072700  (примерный размер ~568 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: memcpy, sdmmcGetFileClusterRestData32
 * Вызывают: sdmmcGetUpdateUnitData
 * Константы: 0x30072700, 0xFFFFFFFC
 * Данные: DAT_30072cd0, DAT_30072e28, DAT_30072e2c, DAT_30072e30
 * ---------------------------------------------------------------- */
int sdmmcGetUpdateUnitData32(byte param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  size_t __n;
  int local_44;
  uint local_40;
  int local_3c;
  int local_38;
  int local_34;
  
  local_38 = (uint)*(byte *)(DAT_30072e30 + 0x4f) << 9;
  iVar1 = 0x5c;
  for (uVar3 = 0; uVar3 < param_1; uVar3 = uVar3 + 1) {
    uVar4 = *(int *)(uVar3 * 0x62 + DAT_30072e28) + *(int *)(uVar3 * 0x62 + DAT_30072e2c);
    if ((uVar4 & 3) != 0) {
      uVar4 = (uVar4 & 0xfffffffc) + 4;
    }
    iVar1 = iVar1 + uVar4;
  }
  uVar3 = iVar1 + param_3 * 0x20000;
  local_40 = *(int *)((uint)param_1 * 0x62 + DAT_30072e28) +
             *(int *)((uint)param_1 * 0x62 + DAT_30072e2c);
  if ((uint)(param_3 << 0x11) < local_40) {
    if (local_40 < param_3 * 0x20000 + 0x20000U) {
      local_3c = local_40 + param_3 * -0x20000;
    }
    else {
      local_3c = 0x20000;
    }
    uVar2 = uVar3 + local_3c;
    for (uVar4 = uVar3; uVar4 < uVar2; uVar4 = uVar4 + __n) {
      local_34 = sdmmcGetFileClusterRestData32(uVar4,&local_44);
      if (local_34 != 0) {
        return local_34;
      }
      if ((uint)(local_38 - local_44) < uVar2 - uVar4) {
        __n = local_38 - local_44;
      }
      else {
        __n = uVar2 - uVar4;
      }
      memcpy((void *)(param_2 + (uVar4 - uVar3)),(void *)(*DAT_30072cd0 + local_44),__n);
    }
    iVar1 = 0;
  }
  else {
    iVar1 = 0x7c;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sdmmcHookTask @ 0x30072938  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: exit, logMsg, taskDelay
 * Константы: 0x30072938
 * Данные: DAT_30072e34, DAT_30072e38
 * ---------------------------------------------------------------- */
void sdmmcHookTask(void)

{
  while (*DAT_30072e34 == 0) {
    taskDelay(0x1e);
  }
  (*(code *)*DAT_30072e34)();
  logMsg(DAT_30072e38,0,0,0,0,0,0);
  exit(0);
  return;
}

/* ----------------------------------------------------------------
 * sdmmcUpdateIdentify @ 0x300729A8  (примерный размер ~840 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 9
 * Вызывает: logMsg, sdmmcBufferMalloc, sdmmcGetFat16, sdmmcGetFat32, sdmmcGetFatData, sdmmcGetStatus, sdmmcGetUnitHeadData16, sdmmcGetUnitHeadData32, taskSpawn
 * Константы: 0x300729A8
 * Данные: DAT_30072e30, DAT_30072e34, DAT_30072e3c, DAT_30072e40, DAT_30072e44, DAT_30072e48, DAT_30072e4c, DAT_30072e50
 * ---------------------------------------------------------------- */
int sdmmcUpdateIdentify(void)

{
  int iVar1;
  
  if (*DAT_30072e3c == 1) {
    iVar1 = 0;
  }
  else {
    *DAT_30072e3c = 1;
    iVar1 = sdmmcGetStatus();
    if (iVar1 == 0) {
      *DAT_30072e3c = 0;
      iVar1 = 0x78;
    }
    else {
      iVar1 = sdmmcGetFatData();
      if (iVar1 == 0) {
        iVar1 = sdmmcBufferMalloc();
        if (iVar1 == 0) {
          if (*DAT_30072e30 == 1) {
            iVar1 = sdmmcGetFat16();
            if (iVar1 != 0) {
              *DAT_30072e3c = 0;
              return iVar1;
            }
          }
          else {
            if (*DAT_30072e30 != 2) {
              *DAT_30072e3c = 0;
              return 0x79;
            }
            iVar1 = sdmmcGetFat32();
            if (iVar1 != 0) {
              *DAT_30072e3c = 0;
              return iVar1;
            }
          }
          if (*DAT_30072e30 == 1) {
            iVar1 = sdmmcGetUnitHeadData16();
            if (iVar1 != 0) {
              *DAT_30072e3c = 0;
              return iVar1;
            }
          }
          else {
            if (*DAT_30072e30 != 2) {
              *DAT_30072e3c = 0;
              return 0x79;
            }
            iVar1 = sdmmcGetUnitHeadData32();
            if (iVar1 != 0) {
              *DAT_30072e3c = 0;
              return iVar1;
            }
          }
          logMsg(DAT_30072e40,0,0,0,0,0,0);
          if (*DAT_30072e34 == 0) {
            iVar1 = taskSpawn(DAT_30072e4c,0xfa,0,500,DAT_30072e48,0,0,0,0,0,0,0,0,0,0);
            if (iVar1 == -1) {
              logMsg(DAT_30072e50,0,0,0,0,0,0);
            }
          }
          else {
            (*(code *)*DAT_30072e34)();
            logMsg(DAT_30072e44,0,0,0,0,0,0);
          }
          *DAT_30072e3c = 0;
          iVar1 = 0;
        }
        else {
          *DAT_30072e3c = 0;
        }
      }
      else {
        *DAT_30072e3c = 0;
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sdmmcUpdateExit @ 0x30072CF0  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: memset, sdmmcBufferFree
 * Константы: 0x30072CF0
 * Данные: DAT_30072e30, DAT_30072e54
 * ---------------------------------------------------------------- */
void sdmmcUpdateExit(void)

{
  sdmmcBufferFree();
  memset(DAT_30072e30,0,0xc0);
  *DAT_30072e54 = 0;
  return;
}

/* ----------------------------------------------------------------
 * sdmmcGetUpdateAllUnitHead @ 0x30072D18  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: memcpy
 * Константы: 0x30072D18
 * Данные: DAT_30072da0, DAT_30072e54
 * ---------------------------------------------------------------- */
undefined4 sdmmcGetUpdateAllUnitHead(void *param_1,byte *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == (void *)0x0) || (param_2 == (byte *)0x0)) {
    uVar1 = 0x7c;
  }
  else {
    *param_2 = *DAT_30072e54;
    memcpy(param_1,DAT_30072da0,(uint)*DAT_30072e54 * 0x62);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sdmmcGetUpdateUnitData @ 0x30072D6C  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: sdmmcGetUpdateUnitData16, sdmmcGetUpdateUnitData32
 * Константы: 0x30072D6C
 * Данные: DAT_30072e30, DAT_30072e54
 * ---------------------------------------------------------------- */
undefined4 sdmmcGetUpdateUnitData(uint param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || ((uint)*DAT_30072e54 <= (param_1 & 0xff))) {
    uVar1 = 0x7c;
  }
  else if (*DAT_30072e30 == 1) {
    uVar1 = sdmmcGetUpdateUnitData16(param_1,param_2,param_3);
  }
  else if (*DAT_30072e30 == 2) {
    uVar1 = sdmmcGetUpdateUnitData32(param_1,param_2,param_3);
  }
  else {
    uVar1 = 0x79;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sdmmcAddHook @ 0x30072E58  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: printf, tickGet
 * Вызывают: BSP_SdmmcAddHook, TFUP_CheckInit, dloadInit
 * Константы: 0x30072E58, 0xFFFFFFFF
 * Данные: DAT_30072edc, DAT_30072ee0, DAT_30072ee4
 * ---------------------------------------------------------------- */
undefined4 sdmmcAddHook(int param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if (param_1 < 5) {
    *(undefined4 *)(DAT_30072edc + param_1 * 4) = param_2;
    uVar4 = tickGet();
    lVar1 = (ulonglong)DAT_30072ee0 * (uVar4 & 0xffffffff);
    uVar3 = tickGet((int)uVar4,(int)(uVar4 >> 0x20),(int)lVar1);
    printf(DAT_30072ee4,(uint)((ulonglong)DAT_30072ee0 * (ulonglong)uVar3 >> 0x25),
           (int)uVar4 + (uint)((ulonglong)lVar1 >> 0x25) * -100,param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x7c;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * HSSD_Send_CMD6 @ 0x30072EE8  (примерный размер ~448 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: Check_TranState, Form_Data_Command, Send_cmd_to_host, SetBlockLength, Validate_Response, logMsg
 * Вызывают: HSSD_CheckFn_Support, HSSD_Function_Switch
 * Константы: 0x30072EE8, 0x00FFFFFF, 0x80000000, 0xFFFFFFC0
 * Данные: DAT_300738f4, DAT_300738f8, DAT_300738fc
 * ---------------------------------------------------------------- */
int HSSD_Send_CMD6(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  uint local_64;
  undefined1 auStack_60 [64];
  
  local_70 = *DAT_300738f4;
  local_6c = DAT_300738f4[1];
  local_68 = DAT_300738f4[2];
  local_64 = DAT_300738f4[3];
  iVar1 = Check_TranState(param_1);
  if (iVar1 == 0) {
    iVar2 = *(int *)(DAT_300738f8 + param_1 * 0x88);
    if (iVar2 != 0x40) {
      iVar1 = SetBlockLength(param_1,0x40,0,1);
    }
    if (iVar1 == 0) {
      param_3 = param_3 & 0xffffff;
      if (param_4 != 0) {
        param_3 = param_3 | 0x80000000;
      }
      Form_Data_Command(param_1,param_3,0x40,2,&local_70,0);
      local_64 = local_64 & 0xffffffc0 | 6;
      iVar1 = Send_cmd_to_host(&local_70,auStack_60,0,param_2,0,2,0,1,0,1);
      if (iVar1 == 0) {
        iVar1 = Validate_Response(6,auStack_60,param_1,4);
      }
      else {
        logMsg(DAT_300738fc,iVar1,0,0,0,0,0);
      }
      if (iVar2 != 0x40) {
        SetBlockLength(param_1,iVar2,0,1);
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Wait_for_CardClkCycles @ 0x300730A8  (примерный размер ~264 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: Read_ClkSource_Info, __udiv32
 * Вызывают: HSSD_Function_Switch
 * Константы: 0x300730A8
 * Данные: DAT_30073900, DAT_30073904
 * ---------------------------------------------------------------- */
void Wait_for_CardClkCycles(undefined4 param_1,int param_2)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int local_30;
  int local_2c;
  
  local_30 = *DAT_30073900;
  local_2c = DAT_30073900[1];
  Read_ClkSource_Info(&local_30,param_1);
  iVar4 = local_30 * param_2 * 0x2c;
  uVar2 = __udiv32(iVar4 * 100,0x32);
  uVar1 = (ulonglong)DAT_30073904;
  uVar3 = __udiv32(iVar4 * 100,0x32,(int)(uVar1 * uVar2));
  uVar3 = (uint)((ulonglong)DAT_30073904 * (ulonglong)uVar3 >> 0x25);
  if ((uVar3 == 0) || (uVar2 + (uint)(uVar1 * uVar2 >> 0x25) * -100 != 0)) {
    uVar3 = uVar3 + 1;
  }
  for (uVar2 = 0; uVar2 < uVar3; uVar2 = uVar2 + 1) {
  }
  return;
}

/* ----------------------------------------------------------------
 * Validate_CMD6_Switch @ 0x300731B0  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: HSSD_CheckFn_Support, HSSD_Function_Switch
 * Константы: 0x300731B0
 * ---------------------------------------------------------------- */
undefined4 Validate_CMD6_Switch(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = 0;
  uVar1 = 0;
  for (uVar3 = 0; (int)uVar3 < 3; uVar3 = uVar3 + 1) {
    uVar4 = (uint)*(byte *)(param_1 + uVar3 + 0xe);
    if ((uVar4 & 0xf) == 0xf) {
      uVar2 = uVar2 | 1 << (uVar3 * 2 + 1 & 0xff);
    }
    if ((int)(uVar4 & 0xf0) >> 4 == 0xf) {
      uVar2 = uVar2 | 1 << ((uVar3 & 0x7f) << 1);
    }
  }
  *param_2 = (char)uVar2;
  if ((uVar2 & 0xff) != 0) {
    uVar1 = 0x65;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * HSSD_Function_Switch @ 0x30073248  (примерный размер ~320 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: HSSD_Send_CMD6, Validate_CMD6_Switch, Validate_Command, Wait_for_CardClkCycles, memset
 * Вызывают: HSSD_Initialise_Handler
 * Константы: 0x30073248
 * Данные: DAT_30073908
 * ---------------------------------------------------------------- */
int HSSD_Function_Switch(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  memset((void *)*DAT_30073908,0,0x40);
  if (param_3 == 0) {
    iVar1 = -0x16;
  }
  else {
    iVar1 = Validate_Command(param_1,0,0,0x12);
    if (((iVar1 == 0) && (iVar1 = HSSD_Send_CMD6(param_1,*DAT_30073908,param_2,0), iVar1 == 0)) &&
       (iVar1 = Validate_CMD6_Switch(*DAT_30073908,param_3,param_4), iVar1 == 0)) {
      if (*(ushort *)(*DAT_30073908 + 0x3e) >> 8 < 0xc9) {
        memset((void *)*DAT_30073908,0,0x40);
        iVar1 = HSSD_Send_CMD6(param_1,*DAT_30073908,param_2,1);
        if (iVar1 == 0) {
          Wait_for_CardClkCycles(param_1,10);
          iVar1 = Validate_CMD6_Switch(*DAT_30073908,param_3,param_4);
        }
      }
      else {
        iVar1 = 100;
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Read_SD_Reg @ 0x30073388  (примерный размер ~504 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: ChangeEndian, Form_Data_Command, Send_CMD55, Send_cmd_to_host, SetBlockLength, Validate_Response
 * Вызывают: Check_HSSD_Type
 * Константы: 0x30073388, 0xFFFFFFC0
 * Данные: DAT_300738f8, DAT_3007390c
 * ---------------------------------------------------------------- */
int Read_SD_Reg(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  local_34 = *DAT_3007390c;
  local_30 = DAT_3007390c[1];
  local_2c = DAT_3007390c[2];
  local_28 = DAT_3007390c[3];
  iVar3 = 0;
  if (param_3 == 0) {
    iVar3 = -0x16;
  }
  else {
    if (param_2 == 0xd) {
      iVar1 = 0x40;
    }
    else {
      if (param_2 != 0x33) {
        return 0x60;
      }
      iVar1 = 8;
    }
    if (param_4 == iVar1) {
      iVar2 = *(int *)(DAT_300738f8 + param_1 * 0x88);
      if (iVar2 != iVar1) {
        iVar3 = SetBlockLength(param_1,iVar1,0,1);
      }
      if (iVar3 == 0) {
        Form_Data_Command(param_1,0,iVar1,2,&local_34,0);
        local_28 = local_28 & 0xffffffc0 | param_2 & 0x3f;
        iVar3 = Send_CMD55(param_1);
        if (iVar3 == 0) {
          iVar3 = Send_cmd_to_host(&local_34,auStack_38,0,param_3,0,2,0,1,0,1);
          if (iVar3 == 0) {
            iVar3 = Validate_Response(param_2,auStack_38,param_1,4);
            ChangeEndian(param_3,iVar1);
          }
          if (iVar2 != iVar1) {
            SetBlockLength(param_1,iVar2,0,1);
          }
        }
        else {
          iVar3 = 0x52;
        }
      }
    }
    else {
      iVar3 = 0x60;
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * Check_HSSD_Type @ 0x30073580  (примерный размер ~248 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: Read_SD_Reg, logMsg, memset, printf
 * Вызывают: HSSD_Initialise_Handler
 * Константы: 0x30073580
 * Данные: DAT_30073910, DAT_30073914, DAT_30073918
 * ---------------------------------------------------------------- */
int Check_HSSD_Type(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 auStack_18 [7];
  byte local_11;
  
  if (param_2 == (undefined1 *)0x0) {
    iVar1 = 0x60;
  }
  else {
    memset(auStack_18,0,8);
    iVar1 = Read_SD_Reg(param_1,0x33,auStack_18,8);
    if (iVar1 == 0) {
      printf(DAT_30073910,(uint)local_11);
      if ((local_11 & 0xf) == 0) {
        *param_2 = 0;
        logMsg(DAT_30073918,0,0,0,0,0,0);
      }
      else {
        *param_2 = 1;
        logMsg(DAT_30073914,0,0,0,0,0,0);
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * HSSD_CheckFn_Support @ 0x30073678  (примерный размер ~344 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: HSSD_Send_CMD6, Validate_CMD6_Switch, Validate_Command, logMsg, memset
 * Вызывают: HSSD_Initialise_Handler
 * Константы: 0x30073678
 * Данные: DAT_30073908, DAT_3007391c, DAT_30073920, DAT_30073924
 * ---------------------------------------------------------------- */
int HSSD_CheckFn_Support(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 local_1c [4];
  
  local_1c[0] = 0;
  memset((void *)*DAT_30073908,0,0x40);
  if (param_3 == 0) {
    iVar1 = -0x16;
  }
  else if (param_4 < 0x40) {
    iVar1 = 0x60;
  }
  else {
    iVar1 = Validate_Command(param_1,0,0,0x12);
    if ((iVar1 == 0) && (iVar1 = HSSD_Send_CMD6(param_1,*DAT_30073908,param_2,0), iVar1 == 0)) {
      if ((*(byte *)(*DAT_30073908 + 0xd) & 2) == 2) {
        *DAT_3007391c = 1;
        logMsg(DAT_30073920,0,0,0,0,0,0);
      }
      else {
        *DAT_3007391c = 0;
        logMsg(DAT_30073924,0,0,0,0,0,0);
      }
      Validate_CMD6_Switch(*DAT_30073908,local_1c,1);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * HSSD_Initialise_Handler @ 0x300737D0  (примерный размер ~268 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: Check_HSSD_Type, HSSD_CheckFn_Support, HSSD_Function_Switch, printf
 * Константы: 0x300737D0
 * Данные: DAT_3007391c, DAT_30073928, DAT_3007392c, DAT_30073930, DAT_30073934, DAT_30073938, DAT_3007393c, DAT_30073940
 * ---------------------------------------------------------------- */
int HSSD_Initialise_Handler(int param_1)

{
  int iVar1;
  char local_14 [4];
  undefined1 local_10 [4];
  
  local_14[0] = '\0';
  local_10[0] = *DAT_30073928;
  iVar1 = Check_HSSD_Type(param_1,local_14);
  if (iVar1 == 0) {
    if (local_14[0] != '\0') {
      *(byte *)(DAT_30073930 + param_1 * 0x88) = (byte)*DAT_3007392c & 0x7f | 0x80;
      iVar1 = HSSD_CheckFn_Support(param_1,DAT_30073934,local_10,0x40,1);
      if (iVar1 == 0) {
        if (*DAT_3007391c == '\x01') {
          printf(DAT_3007393c);
          iVar1 = HSSD_Function_Switch(param_1,DAT_30073934,local_10,1);
          if (iVar1 == 0) {
            printf(DAT_30073940);
          }
        }
      }
      else {
        printf(DAT_30073938,iVar1);
      }
    }
  }
  else {
    printf(DAT_30073944,iVar1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * HSSD_CheckSdMode @ 0x300738DC  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300738DC
 * Данные: DAT_3007391c
 * ---------------------------------------------------------------- */
bool HSSD_CheckSdMode(void)

{
  return *DAT_3007391c == '\x01';
}

/* ----------------------------------------------------------------
 * unpack_csd @ 0x30073948  (примерный размер ~1280 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Validate_Response
 * Константы: 0x30073948, 0xFFFFFFFF
 * Данные: DAT_30074438, DAT_3007443c
 * ---------------------------------------------------------------- */
undefined4 unpack_csd(int param_1,byte *param_2,char param_3)

{
  undefined4 uVar1;
  
  *param_2 = *(byte *)(param_1 + 0xf) >> 6;
  if (*param_2 == 0) {
    param_2[1] = *(byte *)(param_1 + 0xf) >> 2 & 0xf;
    param_2[2] = *(byte *)(param_1 + 0xe);
    param_2[3] = *(byte *)(param_1 + 0xd);
    param_2[4] = *(byte *)(param_1 + 0xc);
    *(ushort *)(param_2 + 6) = (ushort)DAT_30074438 & *(ushort *)(param_1 + 10) >> 4;
    param_2[8] = *(byte *)(param_1 + 10) & 0xf;
    param_2[9] = (*(byte *)(param_1 + 9) & 0x80) != 0;
    param_2[10] = (*(byte *)(param_1 + 9) & 0x40) != 0;
    param_2[0xb] = (*(byte *)(param_1 + 9) & 0x20) != 0;
    param_2[0xc] = (*(byte *)(param_1 + 9) & 0x10) != 0;
    *(ushort *)(param_2 + 0xe) =
         (ushort)(*(byte *)(param_1 + 7) >> 6) |
         (ushort)((*(ushort *)(param_1 + 8) & DAT_3007443c) << 2);
    param_2[0x10] = *(byte *)(param_1 + 7) >> 3 & 7;
    param_2[0x11] = *(byte *)(param_1 + 7) & 7;
    param_2[0x12] = *(byte *)(param_1 + 6) >> 5;
    param_2[0x13] = *(byte *)(param_1 + 6) >> 2 & 7;
    param_2[0x14] = *(byte *)(param_1 + 5) >> 7 | (byte)((*(byte *)(param_1 + 6) & 3) << 1);
    if (param_3 == '\0') {
      if (*param_2 < 2) {
        param_2[0x15] = *(byte *)(param_1 + 5) >> 2 & 0x1f;
        param_2[0x16] = *(byte *)(param_1 + 4) >> 5 | (byte)((*(byte *)(param_1 + 5) & 3) << 3);
      }
      else {
        param_2[0x15] = *(byte *)(param_1 + 5) >> 2 & 0x1f;
        param_2[0x16] = *(byte *)(param_1 + 4) >> 5 | (byte)((*(byte *)(param_1 + 5) & 3) << 3);
      }
      param_2[0x17] = *(byte *)(param_1 + 4) & 0x1f;
    }
    else {
      param_2[0x16] = *(byte *)(param_1 + 5) >> 6 & 1;
      param_2[0x15] = *(byte *)(param_1 + 4) >> 7 | (byte)((*(byte *)(param_1 + 5) & 0x3f) << 1);
      param_2[0x17] = *(byte *)(param_1 + 4) & 0x7f;
    }
    param_2[0x18] = (*(byte *)(param_1 + 3) & 0x80) != 0;
    param_2[0x19] = *(byte *)(param_1 + 3) >> 5 & 3;
    param_2[0x1a] = *(byte *)(param_1 + 3) >> 2 & 7;
    param_2[0x1b] = *(byte *)(param_1 + 2) >> 6 | (byte)((*(byte *)(param_1 + 3) & 3) << 2);
    param_2[0x1c] = (*(byte *)(param_1 + 2) & 0x20) != 0;
    param_2[0x1d] = (*(byte *)(param_1 + 1) & 0x80) != 0;
    param_2[0x1e] = (*(byte *)(param_1 + 1) & 0x40) != 0;
    param_2[0x1f] = (*(byte *)(param_1 + 1) & 0x20) != 0;
    param_2[0x20] = (*(byte *)(param_1 + 1) & 0x10) != 0;
    param_2[0x21] = *(byte *)(param_1 + 1) >> 2 & 3;
    param_2[0x22] = *(byte *)(param_1 + 1) & 3;
    uVar1 = 0;
  }
  else if (*param_2 == 1) {
    param_2[1] = 0;
    param_2[2] = *(byte *)(param_1 + 0xe);
    param_2[3] = *(byte *)(param_1 + 0xd);
    param_2[4] = *(byte *)(param_1 + 0xc);
    *(ushort *)(param_2 + 6) = (ushort)DAT_30074438 & *(ushort *)(param_1 + 10) >> 4;
    param_2[8] = *(byte *)(param_1 + 10) & 0xf;
    param_2[9] = (*(byte *)(param_1 + 9) & 0x80) != 0;
    param_2[10] = (*(byte *)(param_1 + 9) & 0x40) != 0;
    param_2[0xb] = (*(byte *)(param_1 + 9) & 0x20) != 0;
    param_2[0xc] = (*(byte *)(param_1 + 9) & 0x10) != 0;
    *(undefined2 *)(param_2 + 0xe) = *(undefined2 *)(param_1 + 6);
    param_2[0x10] = 0;
    param_2[0x11] = 0;
    param_2[0x12] = 0;
    param_2[0x13] = 0;
    param_2[0x14] = 0;
    param_2[0x16] = 0;
    param_2[0x15] = *(byte *)(param_1 + 4) & 0x7f;
    param_2[0x17] = 0;
    param_2[0x18] = (*(byte *)(param_1 + 3) & 0x80) != 0;
    param_2[0x19] = 0;
    param_2[0x1a] = *(byte *)(param_1 + 3) >> 2 & 7;
    param_2[0x1b] = *(byte *)(param_1 + 2) >> 6 | (byte)((*(byte *)(param_1 + 3) & 3) << 2);
    param_2[0x1c] = (*(byte *)(param_1 + 2) & 0x20) != 0;
    param_2[0x1d] = (*(byte *)(param_1 + 1) & 0x80) != 0;
    param_2[0x1e] = (*(byte *)(param_1 + 1) & 0x40) != 0;
    param_2[0x1f] = (*(byte *)(param_1 + 1) & 0x20) != 0;
    param_2[0x20] = (*(byte *)(param_1 + 1) & 0x10) != 0;
    param_2[0x21] = *(byte *)(param_1 + 1) >> 2 & 3;
    param_2[0x22] = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * mmc_unpack_r1 @ 0x30073E48  (примерный размер ~284 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Validate_Response
 * Константы: 0x30073E48, 0x80000000, 0x40000000, 0x20000000, 0x10000000, 0x08000000, 0x04000000, 0x01000000
 * Данные: DAT_30074440
 * ---------------------------------------------------------------- */
undefined4 mmc_unpack_r1(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  if ((uVar2 & DAT_30074440) != 0) {
    if ((uVar2 & 0x80000000) != 0) {
      return 200;
    }
    if ((uVar2 & 0x40000000) != 0) {
      return 0xc9;
    }
    if ((uVar2 & 0x20000000) != 0) {
      return 0xca;
    }
    if ((uVar2 & 0x10000000) != 0) {
      return 0xcb;
    }
    if ((uVar2 & 0x8000000) != 0) {
      return 0xcc;
    }
    if ((uVar2 & 0x4000000) != 0) {
      return 0xcd;
    }
    if ((uVar2 & 0x1000000) != 0) {
      return 0xce;
    }
    if ((uVar2 & 0x200000) != 0) {
      return 0xcf;
    }
    if ((uVar2 & 0x100000) != 0) {
      return 0xd0;
    }
    if ((uVar2 & 0x80000) != 0) {
      return 0xd1;
    }
    if ((uVar2 & 0x40000) != 0) {
      return 0xd2;
    }
    if ((uVar2 & 0x20000) != 0) {
      return 0xd3;
    }
    if ((uVar2 & 0x10000) != 0) {
      return 0xd4;
    }
  }
  if ((param_2 == 0xff) || ((uVar2 >> 9 & 0xf) == param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x4e;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * mmc_unpack_cid @ 0x30073F64  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Validate_Response
 * Константы: 0x30073F64
 * ---------------------------------------------------------------- */
undefined4 mmc_unpack_cid(int param_1,undefined1 *param_2)

{
  int iVar1;
  
  *param_2 = *(undefined1 *)(param_1 + 0xf);
  *(short *)(param_2 + 2) = (short)*(undefined4 *)(param_1 + 0xd);
  for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
    param_2[iVar1 + 4] = *(undefined1 *)(param_1 + iVar1 + 7);
  }
  param_2[10] = 0;
  param_2[0xb] = *(undefined1 *)(param_1 + 6);
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 2);
  param_2[0x10] = *(undefined1 *)(param_1 + 1);
  return 0;
}

/* ----------------------------------------------------------------
 * Unpack_CMD52_Resp @ 0x30073FD4  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Validate_Response
 * Константы: 0x30073FD4
 * ---------------------------------------------------------------- */
undefined4 Unpack_CMD52_Resp(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 1);
  if (bVar1 != 0) {
    if ((bVar1 & 8) != 0) {
      return 0x29;
    }
    if ((bVar1 & 2) != 0) {
      return 0x2a;
    }
    if ((bVar1 & 1) != 0) {
      return 0x2b;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * Unpack_CCCR_reg @ 0x30074028  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30074028, 0x00FFFFFF
 * Данные: DAT_30074444, DAT_30074448, DAT_3007444c, DAT_30074450, DAT_30074454, DAT_30074458, DAT_3007445c, DAT_30074460
 * ---------------------------------------------------------------- */
void Unpack_CCCR_reg(int param_1,undefined1 *param_2)

{
  *(undefined1 *)(param_1 * 0x88 + DAT_30074444) = *param_2;
  *(undefined1 *)(param_1 * 0x88 + DAT_30074448) = param_2[1];
  *(undefined1 *)(param_1 * 0x88 + DAT_3007444c) = param_2[2];
  *(undefined1 *)(param_1 * 0x88 + DAT_30074450) = param_2[4];
  *(undefined1 *)(param_1 * 0x88 + DAT_30074454) = param_2[7];
  *(undefined1 *)(param_1 * 0x88 + DAT_30074458) = param_2[8];
  *(uint *)(DAT_3007445c + param_1 * 0x88) = *(uint *)(param_2 + 9) & 0xffffff;
  *(undefined1 *)(param_1 * 0x88 + DAT_30074460) = param_2[0x12];
  return;
}

/* ----------------------------------------------------------------
 * Repack_csd @ 0x300740E4  (примерный размер ~620 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Set_Clr_WrProt
 * Константы: 0x300740E4
 * Данные: DAT_30074438
 * ---------------------------------------------------------------- */
void Repack_csd(int param_1,byte *param_2,char param_3)

{
  *(byte *)(param_1 + 0xf) = param_2[1] << 2 | *param_2 << 6;
  *(byte *)(param_1 + 0xe) = param_2[2];
  *(byte *)(param_1 + 0xd) = param_2[3];
  *(byte *)(param_1 + 0xc) = param_2[4];
  *(char *)(param_1 + 0xb) = (char)((int)(*(ushort *)(param_2 + 6) & DAT_30074438) >> 4);
  *(byte *)(param_1 + 10) = param_2[8] | (byte)((*(ushort *)(param_2 + 6) & 0xf) << 4);
  *(byte *)(param_1 + 9) =
       param_2[10] << 6 | param_2[9] << 7 | param_2[0xb] << 5 | param_2[0xc] << 4 |
       (byte)((int)(*(ushort *)(param_2 + 0xe) & 0xc00) >> 10);
  *(char *)(param_1 + 8) = (char)((int)(*(ushort *)(param_2 + 0xe) & 0x3fc) >> 2);
  *(byte *)(param_1 + 7) =
       param_2[0x10] << 3 | (byte)((*(ushort *)(param_2 + 0xe) & 3) << 6) | param_2[0x11];
  *(byte *)(param_1 + 6) = param_2[0x13] << 2 | param_2[0x12] << 5 | param_2[0x14] >> 1 & 3;
  *(char *)(param_1 + 5) = (char)((param_2[0x14] & 1) << 7);
  if (param_3 == '\0') {
    if (*param_2 < 2) {
      *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) | param_2[0x15] << 2 | param_2[0x16] >> 3 & 3;
      *(char *)(param_1 + 4) = (char)((param_2[0x16] & 7) << 5);
    }
    else {
      *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) | param_2[0x15] << 2 | param_2[0x16] >> 3 & 3;
      *(char *)(param_1 + 4) = (char)((param_2[0x16] & 7) << 5);
    }
    *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) | param_2[0x17] & 0x1f;
  }
  else {
    *(byte *)(param_1 + 5) =
         *(byte *)(param_1 + 5) | (byte)((param_2[0x16] & 1) << 6) | param_2[0x15] >> 1 & 0x3f;
    *(byte *)(param_1 + 4) = param_2[0x17] & 0x7f | (byte)((param_2[0x15] & 1) << 7);
  }
  *(byte *)(param_1 + 3) =
       (byte)((param_2[0x19] & 3) << 5) | param_2[0x18] << 7 | param_2[0x1a] << 2 |
       param_2[0x1b] >> 2 & 3;
  *(byte *)(param_1 + 2) = param_2[0x1c] << 5 | (byte)((param_2[0x1b] & 3) << 6);
  *(byte *)(param_1 + 1) =
       param_2[0x1e] << 6 | param_2[0x1d] << 7 | param_2[0x1f] << 5 | param_2[0x20] << 4 |
       param_2[0x21] << 2 | param_2[0x22];
  return;
}

/* ----------------------------------------------------------------
 * calcCrc7 @ 0x30074350  (примерный размер ~276 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Set_Clr_WrProt
 * Константы: 0x30074350
 * ---------------------------------------------------------------- */
uint calcCrc7(byte *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0;
  iVar2 = 0;
  uVar6 = (uint)*param_1;
  uVar3 = 0;
  for (iVar4 = 0; iVar4 < param_2 + 7; iVar4 = iVar4 + 1) {
    iVar1 = (int)uVar5 >> 6;
    uVar5 = (uVar5 & 0x3f) << 1;
    if ((int)(uVar6 & 0x80 >> (uVar3 & 0xff)) >> (7 - uVar3 & 0xff) != 0) {
      uVar5 = uVar5 | 1;
    }
    if (uVar3 == 7) {
      uVar3 = 0;
      iVar2 = iVar2 + 1;
      if (iVar2 < (int)(param_2 + 8 + ((uint)(param_2 + 8 >> 0x1f) >> 0x1d)) >> 3) {
        uVar6 = (uint)param_1[iVar2];
      }
    }
    else {
      uVar3 = uVar3 + 1;
    }
    if (iVar1 == 1) {
      uVar5 = (uVar5 ^ 0x89) & 0x7f;
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * IDMAC_SetDescDbg @ 0x30074464  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30074464
 * Данные: DAT_30074f20
 * ---------------------------------------------------------------- */
void IDMAC_SetDescDbg(undefined4 param_1)

{
  *DAT_30074f20 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * IDMAC_alloc_memory @ 0x3007447C  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: memalign
 * Вызывают: IDMAC_Init
 * Константы: 0x3007447C
 * ---------------------------------------------------------------- */
void IDMAC_alloc_memory(undefined4 param_1,undefined4 param_2)

{
  memalign(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * IDMAC_free_memory @ 0x30074498  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: free
 * Константы: 0x30074498
 * ---------------------------------------------------------------- */
void IDMAC_free_memory(void *param_1)

{
  free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * IDMAC_alloc_consistent_dmaable_memory @ 0x300744AC  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: cacheDmaMalloc
 * Вызывают: IDMAC_alloc_desc_queue
 * Константы: 0x300744AC
 * ---------------------------------------------------------------- */
undefined4
IDMAC_alloc_consistent_dmaable_memory(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = cacheDmaMalloc(param_2);
  *param_3 = uVar1;
  return *param_3;
}

/* ----------------------------------------------------------------
 * IDMAC_free_consistent_dmaable_memory @ 0x300744CC  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: cacheDmaFree
 * Вызывают: IDMAC_free_desc_queue
 * Константы: 0x300744CC
 * ---------------------------------------------------------------- */
void IDMAC_free_consistent_dmaable_memory(undefined4 param_1)

{
  cacheDmaFree(param_1);
  return;
}

/* ----------------------------------------------------------------
 * IDMAC_alloc_desc_queue @ 0x300744E0  (примерный размер ~268 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: IDMAC_alloc_consistent_dmaable_memory, bzero, printf
 * Вызывают: IDMAC_Init, Send_cmd_to_host_raw
 * Константы: 0x300744E0, 0xFFFFFFFF
 * Данные: DAT_30074f24, DAT_30074f28, DAT_30074f2c, DAT_30074f30
 * ---------------------------------------------------------------- */
undefined4 IDMAC_alloc_desc_queue(undefined4 *param_1,int param_2)

{
  void *__s;
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_18;
  
  local_18 = 0;
  param_1[2] = 0;
  printf(DAT_30074f24,param_2 << 4);
  __s = (void *)IDMAC_alloc_consistent_dmaable_memory(0x20,param_2 << 4,&local_18);
  if (__s == (void *)0x0) {
    printf(DAT_30074f28);
    uVar1 = 0xffffffff;
  }
  else {
    printf(DAT_30074f2c,__s,&local_18);
    bzero(__s,param_2 << 4);
    param_1[2] = param_2 + -1;
    param_1[1] = __s;
    *param_1 = local_18;
    printf(DAT_30074f30,param_1[2],param_1[1],*param_1);
    for (uVar2 = 0; uVar2 < (uint)param_1[2]; uVar2 = uVar2 + 1) {
      *(uint *)(param_1[1] + uVar2 * 0x10) = (uint)(param_1[2] - 1 == uVar2) << 5;
      *(undefined4 *)(param_1[1] + uVar2 * 0x10 + 4) = 0;
    }
    param_1[3] = 0;
    param_1[4] = param_1[1];
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * IDMAC_free_desc_queue @ 0x300745EC  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: IDMAC_free_consistent_dmaable_memory, printf
 * Вызывают: Send_cmd_to_host_raw
 * Константы: 0x300745EC
 * Данные: DAT_30074f34, DAT_30074f38
 * ---------------------------------------------------------------- */
void IDMAC_free_desc_queue(undefined4 *param_1)

{
  printf(DAT_30074f34);
  printf(DAT_30074f38,param_1[2],param_1[1],*param_1);
  IDMAC_free_consistent_dmaable_memory(param_1[1]);
  return;
}

/* ----------------------------------------------------------------
 * IDMAC_Show @ 0x3007461C  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x3007461C
 * Данные: DAT_30074f3c, DAT_30074f40, DAT_30074f44, DAT_30074f48, DAT_30074f4c, DAT_30074f50, DAT_30074f54, DAT_30074f58
 * ---------------------------------------------------------------- */
void IDMAC_Show(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*DAT_30074f3c + 4);
  printf(DAT_30074f40);
  printf(DAT_30074f44,*(undefined4 *)(iVar1 + 4));
  printf(DAT_30074f48,*(undefined4 *)(iVar1 + 8));
  printf(DAT_30074f4c,*(undefined4 *)(iVar1 + 0xc));
  printf(DAT_30074f50,*(undefined4 *)(iVar1 + 0x10));
  printf(DAT_30074f54,*(undefined4 *)(iVar1 + 0x14));
  printf(DAT_30074f58,*(undefined4 *)(iVar1 + 0x18));
  printf(DAT_30074f5c,*(undefined4 *)(iVar1 + 0x20));
  printf(DAT_30074f60,*(undefined4 *)(iVar1 + 0x1c));
  return;
}

/* ----------------------------------------------------------------
 * IDMAC_Init @ 0x30074698  (примерный размер ~388 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: IDMAC_alloc_desc_queue, IDMAC_alloc_memory, free, memset, printf
 * Вызывают: sdmmcDrvHwInit
 * Константы: 0xFFFFFFFF, 0x30074698
 * Данные: DAT_30074f3c, DAT_30074f64, DAT_30074f68, DAT_30074f6c, DAT_30074f70, DAT_30074f74, DAT_30074f78, DAT_30074f7c
 * ---------------------------------------------------------------- */
undefined4 IDMAC_Init(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *__s;
  
  printf(DAT_30074f64);
  if (*DAT_30074f3c == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = IDMAC_alloc_memory(4,0x28);
    *(undefined4 *)(*DAT_30074f3c + 4) = uVar1;
    if (*(int *)(*DAT_30074f3c + 4) == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      __s = *(undefined4 **)(*DAT_30074f3c + 4);
      printf(DAT_30074f68,__s);
      memset(__s,0,0x28);
      uVar1 = IDMAC_alloc_memory(0x20,0x20);
      __s[5] = uVar1;
      if (__s[5] == 0) {
        free(__s);
        uVar1 = 0xffffffff;
      }
      else {
        printf(DAT_30074f6c,__s[5]);
        uVar1 = IDMAC_alloc_memory(0x20,0x1000);
        __s[9] = uVar1;
        if (__s[9] == 0) {
          free(__s);
          uVar1 = 0xffffffff;
        }
        else {
          printf(DAT_30074f70,__s[9]);
          *DAT_30074f74 = 1;
          *DAT_30074f74 = 0x82;
          *DAT_30074f78 = DAT_30074f7c;
          *DAT_30074f80 = DAT_30074f84;
          iVar2 = IDMAC_alloc_desc_queue(__s,DAT_30074f88);
          if (iVar2 == 0) {
            *DAT_30074f90 = *__s;
            __s[6] = 1;
            printf(DAT_30074f8c);
            uVar1 = 0;
          }
          else {
            free((void *)__s[5]);
            free((void *)__s[9]);
            free(__s);
            printf(DAT_30074f8c);
            uVar1 = 0xffffffff;
          }
        }
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * IDMAC_NoCopySend @ 0x3007481C  (примерный размер ~784 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_30074e48, FUN_30074ed8, cacheFlush, logMsg, memcpy, printf
 * Вызывают: Send_cmd_to_host_raw
 * Константы: 0x3007481C, 0x80000000
 * Данные: DAT_30074f20, DAT_30074f90, DAT_30074f94, DAT_30074f98, DAT_30074f9c, DAT_30074fa0, DAT_30074fa4
 * ---------------------------------------------------------------- */
void IDMAC_NoCopySend(undefined4 *param_1,void *param_2,size_t param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  void *__dest;
  uint uVar3;
  void *pvVar4;
  size_t sVar5;
  size_t __n;
  bool bVar6;
  uint *local_3c;
  uint *local_38;
  size_t local_34;
  void *local_30;
  
  local_3c = (uint *)0x0;
  local_38 = (uint *)0x0;
  pvVar4 = param_2;
  if (((uint)param_2 & 0x1f) != 0) {
    pvVar4 = (void *)((int)param_2 + (0x20 - ((uint)param_2 & 0x1f)));
  }
  bVar6 = ((uint)param_2 & 0x1f) != 0;
  __dest = param_2;
  sVar5 = 0;
  local_34 = param_3;
  for (uVar3 = 0; uVar3 < param_4; uVar3 = uVar3 + 1) {
    iVar2 = FUN_30074ed8(uVar3,param_4);
    __n = local_34;
    if (iVar2 == 0) {
      if (bVar6) {
        __dest = (void *)param_1[5];
        local_30 = param_2;
        if (((uint)param_2 & 0x1f) != 0) {
          local_30 = (void *)((int)param_2 + (0x20 - ((uint)param_2 & 0x1f)));
        }
        __n = (int)local_30 - (int)param_2;
      }
      else {
        __n = 0x1000;
        __dest = pvVar4;
      }
      if (bVar6) {
        memcpy(__dest,param_2,__n);
      }
      param_1[3] = 0;
      *DAT_30074f90 = *param_1;
    }
    else if (iVar2 == 1) {
      if (bVar6) {
        iVar1 = uVar3 * 0x1000 + -0x1000;
      }
      else {
        iVar1 = uVar3 * 0x1000;
      }
      __dest = (void *)((int)pvVar4 + iVar1);
      __n = 0x1000;
    }
    else if (iVar2 == 2) {
      if (bVar6) {
        __dest = (void *)param_1[9];
        memcpy(__dest,(void *)((int)pvVar4 + uVar3 * 0x1000 + -0x1000),local_34);
      }
      else {
        __dest = (void *)((int)pvVar4 + uVar3 * 0x1000);
      }
    }
    else if (iVar2 == 3) {
      __dest = pvVar4;
      if (bVar6) {
        __dest = (void *)param_1[5];
        memcpy(__dest,param_2,param_3);
      }
      param_1[3] = 0;
      *DAT_30074f90 = *param_1;
      __n = param_3;
    }
    else {
      printf(DAT_30074f94);
      __n = sVar5;
    }
    if (*DAT_30074f98 != 0) {
      cacheFlush(1,__dest,__n);
    }
    FUN_30074e48(param_1,iVar2,__dest,__n,&local_3c);
    if ((iVar2 == 0) || (iVar2 == 3)) {
      local_38 = local_3c;
    }
    if ((iVar2 == 2) && (local_38 != (uint *)0x0)) {
      *local_38 = *local_38 | 0x80000000;
    }
    if (*DAT_30074f20 != 0) {
      logMsg(DAT_30074f9c,uVar3,*local_3c,local_3c[1],local_3c[2],local_3c[3]);
    }
    local_34 = local_34 - __n;
    sVar5 = __n;
  }
  if (*DAT_30074f20 != 0) {
    logMsg(DAT_30074fa0,param_2,param_3,param_4);
  }
  *DAT_30074fa4 = 1;
  return;
}

/* ----------------------------------------------------------------
 * IDMAC_NoCopyReceive @ 0x30074B2C  (примерный размер ~796 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_30074e48, FUN_30074ed8, cacheInvalidate, logMsg, printf
 * Вызывают: Send_cmd_to_host_raw
 * Константы: 0x30074B2C, 0x80000000
 * Данные: DAT_30074f20, DAT_30074f90, DAT_30074f94, DAT_30074fa0, DAT_30074fa4, DAT_30074fa8, DAT_30074fac, DAT_30074fb0
 * ---------------------------------------------------------------- */
void IDMAC_NoCopyReceive(undefined4 *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  uint *local_40;
  uint *local_3c;
  int local_38;
  uint local_34;
  undefined4 local_30;
  
  local_40 = (uint *)0x0;
  local_3c = (uint *)0x0;
  iVar4 = 0;
  uVar3 = param_2;
  if ((param_2 & 0x1f) != 0) {
    uVar3 = (param_2 - (param_2 & 0x1f)) + 0x20;
  }
  bVar6 = (param_2 & 0x1f) != 0;
  local_38 = param_3;
  if (param_1 == (undefined4 *)0x0) {
    printf(DAT_30074fa8);
  }
  else {
    uVar5 = param_2;
    for (uVar2 = 0; uVar2 < param_4; uVar2 = uVar2 + 1) {
      iVar1 = FUN_30074ed8(uVar2,param_4);
      if (iVar1 == 0) {
        if (bVar6) {
          uVar5 = param_1[5];
          local_34 = param_2;
          if ((param_2 & 0x1f) != 0) {
            local_34 = (param_2 - (param_2 & 0x1f)) + 0x20;
          }
          iVar4 = local_34 - param_2;
        }
        else {
          iVar4 = 0x1000;
          uVar5 = uVar3;
        }
        param_1[3] = 0;
        *DAT_30074f90 = *param_1;
      }
      else if (iVar1 == 1) {
        if (bVar6) {
          uVar5 = (uVar3 + uVar2 * 0x1000) - 0x1000;
        }
        else {
          uVar5 = uVar3 + uVar2 * 0x1000;
        }
        iVar4 = 0x1000;
      }
      else if (iVar1 == 2) {
        iVar4 = local_38;
        if (bVar6) {
          uVar5 = param_1[9];
        }
        else {
          uVar5 = uVar3 + uVar2 * 0x1000;
        }
      }
      else if (iVar1 == 3) {
        uVar5 = uVar3;
        if (bVar6) {
          uVar5 = param_1[5];
        }
        param_1[3] = 0;
        *DAT_30074f90 = *param_1;
        iVar4 = param_3;
      }
      else {
        printf(DAT_30074f94);
      }
      cacheInvalidate(1,uVar5,iVar4);
      if (*(int *)(DAT_30074fac + 0x20) == 0) {
        local_30 = 0;
      }
      else {
        local_30 = (**(code **)(DAT_30074fac + 0x20))();
      }
      FUN_30074e48(param_1,iVar1,uVar5,iVar4,&local_40);
      if ((iVar1 == 0) || (iVar1 == 3)) {
        local_3c = local_40;
      }
      if ((iVar1 == 2) && (local_3c != (uint *)0x0)) {
        *local_3c = *local_3c | 0x80000000;
      }
      if (*DAT_30074f20 != 0) {
        logMsg(DAT_30074fb0,uVar2,iVar1,iVar4,4,5,6);
        logMsg(DAT_30074fb4,uVar2,*local_40,local_40[1],local_40[2],local_40[3]);
      }
      local_38 = local_38 - iVar4;
    }
    if (*DAT_30074f20 != 0) {
      logMsg(DAT_30074fa0,param_2,param_3,param_4);
    }
    *DAT_30074fa4 = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30074e48 @ 0x30074E48  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: IDMAC_NoCopyReceive, IDMAC_NoCopySend
 * Константы: 0x30074E48
 * Данные: DAT_30074fb8, DAT_30074fbc
 * ---------------------------------------------------------------- */
int FUN_30074e48(int param_1,int param_2,uint param_3,uint param_4,int *param_5)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  puVar1 = (uint *)(*(int *)(param_1 + 4) + iVar2 * 0x10);
  puVar1[1] = param_4 & DAT_30074fb8;
  if (iVar2 + 1 == *(int *)(param_1 + 8)) {
    *puVar1 = *(uint *)(DAT_30074fbc + param_2 * 4) | 0x20;
  }
  else {
    *puVar1 = *(uint *)(DAT_30074fbc + param_2 * 4);
  }
  puVar1[2] = param_3;
  *(uint *)(param_1 + 0xc) = iVar2 + 1U & *(int *)(param_1 + 8) - 1U;
  *param_5 = (int)puVar1;
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_30074ed8 @ 0x30074ED8  (примерный размер ~232 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: IDMAC_NoCopyReceive, IDMAC_NoCopySend
 * Константы: 0x30074ED8
 * ---------------------------------------------------------------- */
char FUN_30074ed8(int param_1,int param_2)

{
  char cVar1;
  
  if (param_2 == 1) {
    cVar1 = '\x03';
  }
  else if (param_1 == 0) {
    cVar1 = '\0';
  }
  else {
    cVar1 = (param_2 + -1 == param_1) + '\x01';
  }
  return cVar1;
}

/* ----------------------------------------------------------------
 * getDloadVersion @ 0x300755A4  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: OSAL_LogMsg, memcpy, memset, printf
 * Вызывают: BSP_DLOAD_GetDloadVer
 * Константы: 0x300755A4, 0xFFFFFFFF
 * Данные: DAT_30076290, DAT_30076294, DAT_30076298
 * ---------------------------------------------------------------- */
undefined4 getDloadVersion(void *param_1,uint param_2)

{
  undefined4 uVar1;
  
  printf(DAT_30076290);
  if (((param_1 == (void *)0x0) || ((int)param_2 < 1)) || (param_2 < 4)) {
    OSAL_LogMsg(DAT_30076294,1,2,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else {
    memset(param_1,0,param_2);
    memcpy(param_1,DAT_30076298,4);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * getDloadID @ 0x30075634  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: BSP_GetProductDloadName, memset
 * Вызывают: BSP_DLOAD_GetProductId, TFUP_CheckVersionMatch, dloadUSBSendPro
 * Константы: 0x30075634
 * Данные: DAT_3007629c, DAT_300762a0
 * ---------------------------------------------------------------- */
void * getDloadID(void)

{
  int iVar1;
  void *pvVar2;
  
  memset(DAT_3007629c,0,0x40);
  iVar1 = BSP_GetProductDloadName(DAT_3007629c,0x40);
  pvVar2 = DAT_3007629c;
  if (iVar1 != 0) {
    pvVar2 = DAT_300762a0;
  }
  return pvVar2;
}

/* ----------------------------------------------------------------
 * update_getWebUIUpdateFlag @ 0x30075670  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30075670
 * Данные: DAT_300762a4, DAT_300762a8
 * ---------------------------------------------------------------- */
bool update_getWebUIUpdateFlag(void)

{
  return *DAT_300762a4 != DAT_300762a8;
}

/* ----------------------------------------------------------------
 * getDloadNetMode @ 0x3007569C  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: OSAL_LogMsg, printf
 * Вызывают: BSP_DLOAD_GetDloadNetMode
 * Константы: 0x3007569C, 0xFFFFFFFF
 * Данные: DAT_30076294, DAT_300762ac
 * ---------------------------------------------------------------- */
undefined4 getDloadNetMode(undefined4 *param_1)

{
  undefined4 uVar1;
  
  printf(DAT_300762ac);
  if (param_1 == (undefined4 *)0x0) {
    OSAL_LogMsg(DAT_30076294,1,2,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else {
    *param_1 = 5;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * getAuthorityId @ 0x300757A8  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, dloadGetNvImeiNumber, dloadIsDefaultImeiValue, memset, printf
 * Вызывают: BSP_DLOAD_GetAuthorityId
 * Константы: 0xFFFFFFFF, 0x300757A8
 * Данные: DAT_30076294, DAT_300762b4, DAT_300762b8
 * ---------------------------------------------------------------- */
undefined4 getAuthorityId(void *param_1,size_t param_2)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte bVar6;
  int iVar7;
  byte local_20 [16];
  
  iVar7 = 8;
  pbVar3 = local_20;
  pbVar5 = DAT_300762b4;
  do {
    pbVar4 = pbVar5 + 1;
    bVar6 = *pbVar5;
    pbVar5 = pbVar5 + 2;
    bVar1 = *pbVar4;
    iVar7 = iVar7 + -1;
    pbVar4 = pbVar3 + 1;
    *pbVar3 = bVar6;
    pbVar3 = pbVar3 + 2;
    *pbVar4 = bVar1;
  } while (iVar7 != 0);
  printf(DAT_300762b8,(uint)bVar1,local_20);
  if (((param_1 == (void *)0x0) || ((int)param_2 < 1)) || ((int)param_2 < 0x13)) {
    OSAL_LogMsg(DAT_30076294,1,2,3,4,5,6);
    uVar2 = 0xffffffff;
  }
  else {
    memset(param_1,0,param_2);
    iVar7 = dloadGetNvImeiNumber(local_20);
    if (iVar7 == -1) {
      uVar2 = 0xffffffff;
    }
    else {
      iVar7 = dloadIsDefaultImeiValue(local_20);
      if (iVar7 == 0) {
        uVar2 = 0xffffffff;
      }
      else {
        for (bVar6 = 0; bVar6 < 0xf; bVar6 = bVar6 + 1) {
          if (9 < local_20[bVar6]) {
            return 0xffffffff;
          }
          *(byte *)((int)param_1 + (uint)bVar6) = local_20[bVar6] + 0x30;
        }
        *(undefined1 *)((int)param_1 + (uint)bVar6) = 0x2c;
        *(undefined1 *)((int)param_1 + bVar6 + 1) = 0x30;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * getAuthorityVersion @ 0x300758FC  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: OSAL_LogMsg, memcpy, memset, printf
 * Вызывают: BSP_DLOAD_GetAuthorityVer
 * Константы: 0x300758FC, 0xFFFFFFFF
 * Данные: DAT_30076294, DAT_300762bc, DAT_300762c0
 * ---------------------------------------------------------------- */
undefined4 getAuthorityVersion(void *param_1,uint param_2)

{
  undefined4 uVar1;
  
  printf(DAT_300762bc);
  if (((param_1 == (void *)0x0) || ((int)param_2 < 1)) || (param_2 < 5)) {
    OSAL_LogMsg(DAT_30076294,1,2,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else {
    memset(param_1,0,param_2);
    memcpy(param_1,DAT_300762c0,5);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * NVBackupFlashDataWrite @ 0x3007598C  (примерный размер ~476 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: OSAL_LogMsg, nand_write, ptable_get_range
 * Константы: 0xFFFFFFFF, 0x3007598C
 * Данные: DAT_300762c4, DAT_300762c8, DAT_300762cc, DAT_300762d0, DAT_300762d4, DAT_300762d8, DAT_300762dc
 * ---------------------------------------------------------------- */
undefined4 NVBackupFlashDataWrite(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_20;
  uint local_1c;
  
  local_20 = 0;
  local_1c = 0;
  if ((param_1 == 0) || (param_3 == 0)) {
    OSAL_LogMsg(DAT_300762c4,param_1,param_3,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else if ((param_2 & 1) == 0) {
    iVar2 = ptable_get_range(DAT_300762cc,&local_20,&local_1c);
    if (iVar2 == 0) {
      if (local_20 + param_2 + param_3 < local_1c) {
        iVar2 = nand_write(local_20 + param_2,param_1,param_3,0);
        if (iVar2 == 0) {
          OSAL_LogMsg(DAT_300762dc,1,2,3,4,5,6);
          uVar1 = 0;
        }
        else {
          OSAL_LogMsg(DAT_300762d8,1,2,3,4,5,6);
          uVar1 = 0xffffffff;
        }
      }
      else {
        OSAL_LogMsg(DAT_300762d4,1,2,3,4,5,6);
        uVar1 = 0xffffffff;
      }
    }
    else {
      OSAL_LogMsg(DAT_300762d0,1,2,3,4,5,6);
      uVar1 = 0xffffffff;
    }
  }
  else {
    OSAL_LogMsg(DAT_300762c8,1,2,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * CalculateCRC @ 0x3007635C  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: TFUP_ValidateCRCWithCRCList, TFUP_ValidateCRCWithLic
 * Константы: 0x3007635C
 * Данные: DAT_3007640c, DAT_30076410, DAT_30076414
 * ---------------------------------------------------------------- */
undefined4 CalculateCRC(byte *param_1,int param_2,ushort *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = DAT_3007640c;
  for (uVar1 = param_2 << 3; 7 < uVar1; uVar1 = uVar1 - 8) {
    uVar2 = (uint)*(ushort *)(DAT_30076410 + ((uVar2 ^ *param_1) & 0xff) * 2) ^ uVar2 >> 8;
    param_1 = param_1 + 1;
  }
  if (uVar1 != 0) {
    uVar3 = ((uint)*param_1 << 0x10) >> 8;
    while (uVar1 != 0) {
      uVar1 = uVar1 - 1;
      if (((uVar2 ^ uVar3) & 1) == 0) {
        uVar2 = (uVar2 << 0x10) >> 0x11;
      }
      else {
        uVar2 = DAT_30076414 ^ uVar2 >> 1;
      }
      uVar3 = (uVar3 << 0x10) >> 0x11;
    }
  }
  *param_3 = ~(ushort)uVar2;
  return 1;
}

/* ----------------------------------------------------------------
 * update_record_file @ 0x30076418  (примерный размер ~180 байт)
 * Модуль: data | Вызывают: 25 | Вызывает: 5
 * Вызывает: fclose, fopen, ftell, fwrite, strlen
 * Вызывают: DCBInit, FUN_30080798, FUN_30081f50, FUN_300827c0, ImageDloadToFlash, ImageDloadToRam, dloadDealBootrom, dloadFromFsCheckSpaceForISO, dloadFromFsGetUnitData, dloadFromFsGetUnitHeadData
 *           ...
 * Константы: 0x30076418
 * Данные: DAT_3007699c, DAT_300769a0, DAT_300769a4
 * ---------------------------------------------------------------- */
void update_record_file(char *param_1)

{
  FILE *__stream;
  long lVar1;
  size_t sVar2;
  size_t sVar3;
  
  __stream = fopen(DAT_3007699c,DAT_300769a0);
  if (__stream != (FILE *)0x0) {
    lVar1 = ftell(__stream);
    if (lVar1 < 0) {
      fclose(__stream);
    }
    else {
      if (0xfff < lVar1) {
        fclose(__stream);
        __stream = fopen(DAT_3007699c,DAT_300769a4);
        if (__stream == (FILE *)0x0) {
          return;
        }
      }
      sVar2 = strlen(param_1);
      sVar3 = strlen(param_1);
      sVar3 = fwrite(param_1,1,sVar3,__stream);
      if (sVar3 == sVar2) {
        fclose(__stream);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * getWebUIVersion @ 0x3007653C  (примерный размер ~312 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, fclose, fopen, fread, memset
 * Константы: 0xFFFFFFFF, 0x3007653C
 * Данные: DAT_300769b0, DAT_300769b4, DAT_300769b8, DAT_300769bc, DAT_300769c0
 * ---------------------------------------------------------------- */
undefined4 getWebUIVersion(void *param_1,size_t param_2)

{
  undefined4 uVar1;
  FILE *__stream;
  size_t sVar2;
  
  if ((param_1 == (void *)0x0) || (param_2 == 0)) {
    OSAL_LogMsg(DAT_300769b0,param_1,param_2,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    __stream = fopen(*(char **)(DAT_300769b4 + 8),DAT_300769b8);
    if (__stream == (FILE *)0x0) {
      OSAL_LogMsg(DAT_300769bc,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
    else {
      memset(param_1,0,param_2);
      sVar2 = fread(param_1,1,param_2,__stream);
      if (sVar2 == param_2) {
        *(undefined1 *)((int)param_1 + (param_2 - 1)) = 0;
        fclose(__stream);
        uVar1 = 0;
      }
      else {
        OSAL_LogMsg(DAT_300769c0,0,0,0,0,0,0);
        fclose(__stream);
        uVar1 = 0xffffffff;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * setCdromFlag @ 0x30076674  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_DLOAD_SetCdromMarker
 * Константы: 0x30076674
 * Данные: DAT_300769c4, DAT_300769c8
 * ---------------------------------------------------------------- */
undefined4 setCdromFlag(int param_1)

{
  if (param_1 == 0) {
    *(undefined4 *)(DAT_300769c4 + 0x18) = DAT_300769c8;
  }
  else {
    *(undefined4 *)(DAT_300769c4 + 0x18) = 0;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * getCdromFlag @ 0x300766A8  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300766A8
 * Данные: DAT_300769c4, DAT_300769c8
 * ---------------------------------------------------------------- */
bool getCdromFlag(void)

{
  return *(int *)(DAT_300769c4 + 0x18) != DAT_300769c8;
}

/* ----------------------------------------------------------------
 * cfdNvFileSize @ 0x300766CC  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300766CC
 * ---------------------------------------------------------------- */
int cfdNvFileSize(int param_1)

{
  return *(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x28) + 0x40;
}

/* ----------------------------------------------------------------
 * getCdromVersion @ 0x300766FC  (примерный размер ~308 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, fclose, fopen, fread, memset
 * Вызывают: BSP_DLOAD_GetISOVer
 * Константы: 0xFFFFFFFF, 0x300766FC
 * Данные: DAT_300769b4, DAT_300769cc, DAT_300769d0, DAT_300769d4, DAT_300769d8
 * ---------------------------------------------------------------- */
undefined4 getCdromVersion(void *param_1,size_t param_2)

{
  undefined4 uVar1;
  FILE *__stream;
  size_t sVar2;
  
  if ((param_1 == (void *)0x0) || (param_2 == 0)) {
    OSAL_LogMsg(DAT_300769cc,param_1,param_2,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    __stream = fopen(*(char **)(DAT_300769b4 + 4),DAT_300769d0);
    if (__stream == (FILE *)0x0) {
      OSAL_LogMsg(DAT_300769d4,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
    else {
      memset(param_1,0,param_2);
      sVar2 = fread(param_1,1,param_2,__stream);
      if (sVar2 == 0) {
        OSAL_LogMsg(DAT_300769d8,0,0,0,0,0,0);
        fclose(__stream);
        uVar1 = 0xffffffff;
      }
      else {
        *(undefined1 *)((int)param_1 + (param_2 - 1)) = 0;
        fclose(__stream);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * writeM @ 0x30076830  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 0
 * Вызывают: ONLINE_SetGoOn, TFUP_SetBootromFlag, TFUP_SetGoOn, TFUP_SetSuccessFlag, TFUP_setTFUpdateFlag, update_setWebUIUpdateFlag
 * Константы: 0x30076830
 * ---------------------------------------------------------------- */
void writeM(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}

/* ----------------------------------------------------------------
 * drvSecCheck @ 0x30076848  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: dloadInit
 * Константы: 0x30076848
 * ---------------------------------------------------------------- */
undefined4 drvSecCheck(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * strnicmp @ 0x300768D4  (примерный размер ~268 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: tolower
 * Вызывают: ATCommandProcess
 * Константы: 0xFFFFFFFF, 0x300768D4
 * ---------------------------------------------------------------- */
undefined4 strnicmp(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  undefined4 uVar4;
  int iVar3;
  
  while( true ) {
    if (((*param_1 == '\0') || (*param_2 == '\0')) || (param_3 == 0)) {
      if (param_3 == 0) {
        uVar4 = 0;
      }
      else if (*param_1 == *param_2) {
        uVar4 = 0;
      }
      else {
        uVar4 = 0xffffffff;
      }
      return uVar4;
    }
    param_3 = param_3 + -1;
    cVar1 = *param_1;
    cVar2 = *param_2;
    if ((int)cVar1 - 0x41U < 0x1a) {
      iVar3 = tolower((int)cVar1);
      cVar1 = (char)iVar3;
    }
    if ((int)cVar2 - 0x41U < 0x1a) {
      iVar3 = tolower((int)cVar2);
      cVar2 = (char)iVar3;
    }
    if (cVar1 != cVar2) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * set_nv_resotre_flag @ 0x300769E0  (примерный размер ~296 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: DR_NV_Write, logMsg, memset, omTimerTickGet, snprintf, update_record_file
 * Константы: 0x300769E0
 * Данные: DAT_300773e4, DAT_300773e8, DAT_300773ec, DAT_300773f0, DAT_300773f4, DAT_300773f8
 * ---------------------------------------------------------------- */
void set_nv_resotre_flag(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char acStack_110 [256];
  
  pcVar4 = acStack_110;
  iVar7 = 0x80;
  pcVar6 = DAT_300773e4;
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
  if (*DAT_300773e8 == 0) {
    iVar7 = DR_NV_Write(4,DAT_300773ec,2);
    if (iVar7 != 0) {
      logMsg(DAT_300773f0,iVar7,2,3,4,5,6);
      uVar3 = omTimerTickGet();
      snprintf(acStack_110,0x100,DAT_300773f4,uVar3,iVar7);
      update_record_file(acStack_110);
    }
    memset(acStack_110,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_110,0x100,DAT_300773f8,uVar3,(uint)*DAT_300773ec);
    update_record_file(acStack_110);
    *DAT_300773e8 = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * ONLINE_SetGoOn @ 0x30077098  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: writeM
 * Константы: 0x30077098
 * Данные: DAT_3007745c, DAT_30077464
 * ---------------------------------------------------------------- */
void ONLINE_SetGoOn(int param_1)

{
  if (param_1 == 0) {
    writeM(DAT_3007745c,0);
  }
  else {
    writeM(DAT_3007745c,DAT_30077464);
  }
  return;
}

/* ----------------------------------------------------------------
 * ONLINE_GetGoOn @ 0x300770C8  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: update_WebUITask
 * Константы: 0x300770C8
 * Данные: DAT_3007745c, DAT_30077464
 * ---------------------------------------------------------------- */
bool ONLINE_GetGoOn(void)

{
  return *DAT_3007745c == DAT_30077464;
}

/* ----------------------------------------------------------------
 * update_UpDateInfoSet @ 0x300797D8  (примерный размер ~384 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, fclose, fopen, fseek, fwrite
 * Вызывают: update_WebUITask
 * Константы: 0xFFFFFFFF, 0x300797D8
 * Данные: DAT_3007a3cc, DAT_3007a3d0, DAT_3007a3d4, DAT_3007a3d8, DAT_3007a3dc, DAT_3007a3e0
 * ---------------------------------------------------------------- */
undefined4 update_UpDateInfoSet(void *param_1)

{
  FILE *__stream;
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  
  __stream = fopen(*(char **)(DAT_3007a3cc + 0x10),DAT_3007a3d0);
  if (__stream == (FILE *)0x0) {
    OSAL_LogMsg(DAT_3007a3d4,1,2,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = fseek(__stream,0,0);
    if (iVar2 == -1) {
      fclose(__stream);
      OSAL_LogMsg(DAT_3007a3d8,1,2,3,4,5,6);
      uVar1 = 0xffffffff;
    }
    else {
      sVar3 = fwrite(param_1,1,0x20,__stream);
      if (sVar3 == 0x20) {
        iVar2 = fclose(__stream);
        if (iVar2 == 0) {
          uVar1 = 0;
        }
        else {
          OSAL_LogMsg(DAT_3007a3e0,1,2,3,4,5,6);
          uVar1 = 0xffffffff;
        }
      }
      else {
        fclose(__stream);
        OSAL_LogMsg(DAT_3007a3dc,0x20,sVar3,3,4,5,6);
        uVar1 = 0xffffffff;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * update_UpDateInfoGet @ 0x30079958  (примерный размер ~716 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 9
 * Вызывает: OSAL_LogMsg, fclose, fopen, fread, fseek, memset, omTimerTickGet, snprintf, update_record_file
 * Вызывают: update_WebUIInit
 * Константы: 0xFFFFFFFF, 0x30079958
 * Данные: DAT_3007a3cc, DAT_3007a3e4, DAT_3007a3e8, DAT_3007a3ec, DAT_3007a3f0, DAT_3007a3f4, DAT_3007a3f8, DAT_3007a3fc
 * ---------------------------------------------------------------- */
undefined4 update_UpDateInfoGet(void *param_1)

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
  char acStack_118 [256];
  
  pcVar5 = acStack_118;
  iVar8 = 0x80;
  pcVar7 = DAT_3007a3e4;
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
  __stream = fopen(*(char **)(DAT_3007a3cc + 0x10),DAT_3007a3e8);
  if (__stream == (FILE *)0x0) {
    OSAL_LogMsg(DAT_3007a3ec,1,2,3,4,5,6);
    memset(acStack_118,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_118,0x100,DAT_3007a3f0,uVar3);
    update_record_file(acStack_118);
    uVar3 = 0xffffffff;
  }
  else {
    iVar8 = fseek(__stream,0,0);
    if (iVar8 == -1) {
      fclose(__stream);
      OSAL_LogMsg(DAT_3007a3f4,1,2,3,4,5,6);
      memset(acStack_118,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_118,0x100,DAT_3007a3f8,uVar3);
      update_record_file(acStack_118);
      uVar3 = 0xffffffff;
    }
    else {
      sVar4 = fread(param_1,1,0x20,__stream);
      if (sVar4 == 0x20) {
        iVar8 = fclose(__stream);
        if (iVar8 == 0) {
          uVar3 = 0;
        }
        else {
          OSAL_LogMsg(DAT_3007a404,1,2,3,4,5,6);
          memset(acStack_118,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_118,0x100,DAT_3007a408,uVar3);
          update_record_file(acStack_118);
          uVar3 = 0xffffffff;
        }
      }
      else {
        fclose(__stream);
        OSAL_LogMsg(DAT_3007a3fc,sVar4,2,3,4,5,6);
        memset(acStack_118,0x100,0);
        uVar3 = omTimerTickGet();
        snprintf(acStack_118,0x100,DAT_3007a400,uVar3,sVar4);
        update_record_file(acStack_118);
        uVar3 = 0xffffffff;
      }
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * update_setWebUIUpdateFlag @ 0x30079C24  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: writeM
 * Вызывают: update_WebUIInit, update_WebUITask
 * Константы: 0x30079C24, 0xFFFFFFFF
 * Данные: DAT_3007a40c, DAT_3007a410
 * ---------------------------------------------------------------- */
undefined4 update_setWebUIUpdateFlag(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    writeM(DAT_3007a40c,DAT_3007a410);
    uVar1 = 0;
  }
  else if (param_1 == 1) {
    writeM(DAT_3007a40c,0);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * update_WebUITask @ 0x30079C6C  (примерный размер ~676 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 15
 * Вызывает: BSP_DLOAD_SetCdromMarker, BSP_DLOAD_SetSoftLoad, DLOAD_LEDInd, ONLINE_GetGoOn, OSAL_LogMsg, dloadBootromEnd, dloadFromFsMainThread, memset, omTimerTickGet, semTake, snprintf, update_UpDateInfoSet, update_record_file, update_setWebUIUpdateFlag
 *           ...
 * Константы: 0x30079C6C, 0xFFFFFFFF
 * Данные: DAT_3007a3cc, DAT_3007a414, DAT_3007a418, DAT_3007a41c, DAT_3007a420, DAT_3007a424, DAT_3007a428, DAT_3007a42c
 * ---------------------------------------------------------------- */
void update_WebUITask(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char acStack_108 [256];
  
  iVar7 = 0x80;
  pcVar4 = acStack_108;
  pcVar6 = DAT_3007a414;
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
  semTake(*DAT_3007a418,0xffffffff,acStack_108);
  DLOAD_LEDInd(1);
  iVar7 = dloadFromFsMainThread();
  if (iVar7 == 0) {
    iVar7 = ONLINE_GetGoOn();
    if ((iVar7 == 0) &&
       (iVar7 = xdelete(*(undefined4 *)(DAT_3007a3cc + *(int *)(DAT_3007a420 + 8) * 4)), iVar7 != 0)
       ) {
      OSAL_LogMsg(DAT_3007a424,1,2,3,4,5,6);
    }
    if ((*(int *)(DAT_3007a420 + 8) == 2) || (*(int *)(DAT_3007a420 + 8) == 3)) {
      *(undefined4 *)(DAT_3007a420 + 0x14) = 100;
      update_UpDateInfoSet(DAT_3007a420);
      BSP_DLOAD_SetCdromMarker(1);
    }
    else {
      BSP_DLOAD_SetCdromMarker(0);
    }
    BSP_DLOAD_SetCdromMarker(1);
    update_setWebUIUpdateFlag(0);
    BSP_DLOAD_SetSoftLoad(0);
    memset(acStack_108,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_108,0x100,DAT_3007a42c,uVar3);
    update_record_file(acStack_108);
    OSAL_LogMsg(DAT_3007a434,*(undefined4 *)(*DAT_3007a430 + 4),2,3,4,5,6);
    DLOAD_LEDInd(2);
    dloadBootromEnd(1);
  }
  else {
    OSAL_LogMsg(DAT_3007a41c,1,2,3,4,5,6);
    iVar7 = ONLINE_GetGoOn();
    if ((iVar7 == 0) &&
       (iVar7 = xdelete(*(undefined4 *)(DAT_3007a3cc + *(int *)(DAT_3007a420 + 8) * 4)), iVar7 != 0)
       ) {
      OSAL_LogMsg(DAT_3007a424,1,2,3,4,5,6);
    }
    update_setWebUIUpdateFlag(1);
    *(undefined4 *)(DAT_3007a420 + 0x14) = 0x46;
    update_UpDateInfoSet(DAT_3007a420);
    DLOAD_LEDInd(3);
    memset(acStack_108,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_108,0x100,DAT_3007a428,uVar3);
    update_record_file(acStack_108);
  }
  return;
}

/* ----------------------------------------------------------------
 * update_WebUIInit @ 0x30079F10  (примерный размер ~1388 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 11
 * Вызывает: OSAL_LogMsg, logMsg, memset, omTimerTickGet, semBCreate, semGive, snprintf, taskSpawn, update_UpDateInfoGet, update_record_file, update_setWebUIUpdateFlag
 * Константы: 0x30079F10
 * Данные: DAT_3007a418, DAT_3007a420, DAT_3007a438, DAT_3007a43c, DAT_3007a440, DAT_3007a444, DAT_3007a448, DAT_3007a44c
 * ---------------------------------------------------------------- */
void update_WebUIInit(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char acStack_110 [256];
  
  pcVar4 = acStack_110;
  iVar7 = 0x80;
  pcVar6 = DAT_3007a438;
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
  snprintf(acStack_110,0x100,DAT_3007a43c);
  update_record_file(acStack_110);
  memset(DAT_3007a420,0,0x20);
  iVar7 = update_UpDateInfoGet(DAT_3007a420);
  if (iVar7 == -1) {
    update_setWebUIUpdateFlag(1);
    OSAL_LogMsg(DAT_3007a440,1,2,3,4,5,6);
    memset(acStack_110,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_110,0x100,DAT_3007a444,uVar3);
    update_record_file(acStack_110);
  }
  else if ((*(char *)((int)DAT_3007a420 + 0x10) == '\0') ||
          (4 < *(byte *)((int)DAT_3007a420 + 0x10))) {
    update_setWebUIUpdateFlag(1);
    OSAL_LogMsg(DAT_3007a448,1,2,3,4,5,6);
    memset(acStack_110,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_110,0x100,DAT_3007a44c,uVar3,(uint)*(byte *)((int)DAT_3007a420 + 0x10));
    update_record_file(acStack_110);
  }
  else if (*(byte *)((int)DAT_3007a420 + 0x10) < *(byte *)((int)DAT_3007a420 + 0x11)) {
    update_setWebUIUpdateFlag(1);
    OSAL_LogMsg(DAT_3007a450,1,2,3,4,5,6);
    memset(acStack_110,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_110,0x100,DAT_3007a454,uVar3,(uint)*(byte *)((int)DAT_3007a420 + 0x11),
             (uint)*(byte *)((int)DAT_3007a420 + 0x10));
    update_record_file(acStack_110);
  }
  else {
    iVar7 = semBCreate(1,0);
    *DAT_3007a418 = iVar7;
    if (*DAT_3007a418 == 0) {
      update_setWebUIUpdateFlag(1);
      logMsg(DAT_3007a458,0,0,0,0,0,0);
      memset(acStack_110,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_110,0x100,DAT_3007a45c,uVar3);
      update_record_file(acStack_110);
    }
    else {
      iVar7 = taskSpawn(DAT_3007a464,0x9e,0,0x4000,DAT_3007a460,0,0,0,0,0,0,0,0,0,0);
      if (iVar7 == -1) {
        update_setWebUIUpdateFlag(1);
        OSAL_LogMsg(DAT_3007a468,1,2,3,4,5,6);
        memset(acStack_110,0x100,0);
        uVar3 = omTimerTickGet();
        snprintf(acStack_110,0x100,DAT_3007a46c,uVar3);
        update_record_file(acStack_110);
      }
      else if (*(int *)((int)DAT_3007a420 + 0x14) == 0x3c) {
        *DAT_3007a470 = 1;
        semGive(*DAT_3007a418);
      }
      else {
        update_setWebUIUpdateFlag(1);
        OSAL_LogMsg(DAT_3007a474,1,2,3,4,5,6);
        memset(acStack_110,0x100,0);
        uVar3 = omTimerTickGet();
        snprintf(acStack_110,0x100,DAT_3007a478,uVar3,*(undefined4 *)((int)DAT_3007a420 + 0x14));
        update_record_file(acStack_110);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * getFilePath @ 0x3007EA78  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: strcat
 * Вызывают: TFUP_GetAllFileName
 * Константы: 0x3007EA78, 0xFFFFFFFF
 * Данные: DAT_3007f7a0
 * ---------------------------------------------------------------- */
undefined4 getFilePath(char *param_1,char *param_2,char *param_3)

{
  undefined4 uVar1;
  
  if (((param_1 == (char *)0x0) || (param_3 == (char *)0x0)) || (param_2 == (char *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    strcat(param_3,param_1);
    strcat(param_3,DAT_3007f7a0);
    strcat(param_3,param_2);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * ATCommandHandle @ 0x3007F944  (примерный размер ~928 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: dloadUSBSend, memset, strlen
 * Вызывают: ATCommandProcess
 * Константы: 0x3007F944, 0x3007FA28
 * Данные: DAT_3007fa34, DAT_3007fa38, DAT_3007fa3c, DAT_3007fa40, DAT_30080aec
 * ---------------------------------------------------------------- */
undefined4 ATCommandHandle(uint param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  size_t sVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined1 auStack_cc [24];
  undefined1 auStack_b4 [20];
  undefined1 auStack_a0 [152];
  
  puVar5 = auStack_cc;
  iVar8 = 5;
  puVar7 = DAT_3007fa34;
  do {
    puVar6 = puVar7 + 1;
    uVar1 = *puVar7;
    puVar7 = puVar7 + 2;
    uVar2 = *puVar6;
    iVar8 = iVar8 + -1;
    puVar6 = puVar5 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar5 + 2;
    *puVar6 = uVar2;
  } while (iVar8 != 0);
  puVar5 = auStack_a0;
  iVar8 = 0x4b;
  puVar7 = DAT_3007fa38;
  do {
    puVar6 = puVar7 + 1;
    uVar1 = *puVar7;
    puVar7 = puVar7 + 2;
    uVar2 = *puVar6;
    iVar8 = iVar8 + -1;
    puVar6 = puVar5 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar5 + 2;
    *puVar6 = uVar2;
  } while (iVar8 != 0);
  puVar5 = auStack_b4;
  iVar8 = 9;
  puVar7 = DAT_3007fa3c;
  do {
    puVar6 = puVar7 + 1;
    uVar1 = *puVar7;
    puVar7 = puVar7 + 2;
    uVar2 = *puVar6;
    iVar8 = iVar8 + -1;
    puVar6 = puVar5 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar5 + 2;
    *puVar6 = uVar2;
  } while (iVar8 != 0);
  *puVar5 = *puVar7;
  memset(auStack_a0,0,0x96);
  memset(auStack_cc,0,10);
  if (param_1 < 0xb) {
                    /* WARNING: Could not recover jumptable at 0x3007fa28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(DAT_3007fa40 + param_1 * 4))();
    return uVar3;
  }
  sVar4 = strlen(DAT_30080aec);
  dloadUSBSend(DAT_30080aec,sVar4);
  return 1;
}

/* ----------------------------------------------------------------
 * ATCommandProcess @ 0x3007FCE4  (примерный размер ~292 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: ATCommandHandle, OSAL_LogMsg, dloadUSBSend, strlen, strnicmp
 * Вызывают: dloadUSBCallback
 * Константы: 0x3007FCE4, 0xFFFFFFFF
 * Данные: DAT_30080aec, DAT_30080c14, DAT_30080c18
 * ---------------------------------------------------------------- */
undefined4 ATCommandProcess(int param_1,uint param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte bVar7;
  int iVar8;
  undefined4 local_68 [22];
  undefined4 *puVar6;
  
  puVar4 = local_68;
  iVar8 = 0xb;
  puVar5 = DAT_30080c14;
  do {
    puVar6 = puVar5 + 1;
    uVar1 = *puVar5;
    puVar5 = puVar5 + 2;
    uVar3 = *puVar6;
    iVar8 = iVar8 + -1;
    puVar6 = puVar4 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 2;
    *puVar6 = uVar3;
  } while (iVar8 != 0);
  if (param_1 == 0) {
    OSAL_LogMsg(DAT_30080c18,1,2,3,4,5,6);
    sVar2 = strlen(DAT_30080aec);
    dloadUSBSend(DAT_30080aec,sVar2);
    uVar1 = 0xffffffff;
  }
  else {
    bVar7 = 0;
    while ((bVar7 < 0xb &&
           ((sVar2 = strlen((char *)local_68[(uint)bVar7 * 2]),
            (param_2 & 0xffff) != (sVar2 & 0xffff) ||
            (iVar8 = strnicmp(local_68[(uint)bVar7 * 2],param_1,param_2 & 0xffff), iVar8 != 0))))) {
      bVar7 = bVar7 + 1;
    }
    if (bVar7 == 0xb) {
      uVar1 = 2;
    }
    else {
      uVar1 = ATCommandHandle(local_68[(uint)bVar7 * 2 + 1]);
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * save_check_data @ 0x3007FE08  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3007FE08
 * ---------------------------------------------------------------- */
void save_check_data(void)

{
  return;
}

/* ----------------------------------------------------------------
 * add_log @ 0x3007FE0C  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3007FE0C
 * ---------------------------------------------------------------- */
void add_log(void)

{
  return;
}

/* ----------------------------------------------------------------
 * HighToLow @ 0x30080674  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: OSAL_LogMsg
 * Вызывают: FUN_30080798
 * Константы: 0x30080674
 * Данные: DAT_3008156c
 * ---------------------------------------------------------------- */
int HighToLow(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if ((param_2 & 0xff) < 5) {
    for (uVar2 = 0; uVar2 < (param_2 & 0xff); uVar2 = uVar2 + 1) {
      iVar1 = iVar1 + ((uint)*(byte *)(param_1 + uVar2) <<
                      (((param_2 & 0xff) - uVar2) * 8 - 8 & 0xff));
    }
  }
  else {
    OSAL_LogMsg(DAT_3008156c,1,2,3,4,5,6);
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * LowToHigh @ 0x30081D34  (примерный размер ~328 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: OSAL_LogMsg
 * Константы: 0x30081D34
 * Данные: DAT_30081e78
 * ---------------------------------------------------------------- */
int LowToHigh(int param_1,byte param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (param_2 < 5) {
    for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1) {
      iVar1 = iVar1 + ((uint)*(byte *)(param_1 + uVar2) << ((uVar2 & 0x1f) << 3));
    }
  }
  else {
    OSAL_LogMsg(DAT_30081e78,1,2,3,4,5,6);
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * getFactoryMode @ 0x30081E7C  (примерный размер ~212 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: DR_NV_Read, OSAL_LogMsg
 * Вызывают: dloadInit
 * Константы: 0x30081E7C
 * Данные: DAT_30082e68, DAT_30082e6c, DAT_30082e70, DAT_30082e74
 * ---------------------------------------------------------------- */
undefined4 getFactoryMode(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DR_NV_Read(0x24,DAT_30082e68,4);
  if (iVar1 == 0) {
    if (*DAT_30082e68 == 0) {
      uVar2 = 0;
    }
    else {
      OSAL_LogMsg(DAT_30082e74,0,0,0,0,0,0);
      uVar2 = 1;
    }
  }
  else {
    OSAL_LogMsg(DAT_30082e6c,0,0,0,0,0,0);
    OSAL_LogMsg(DAT_30082e70,0,0,0,0,0,0);
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30081f50 @ 0x30081F50  (примерный размер ~932 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 9
 * Вызывает: OSAL_LogMsg, fclose, fopen, fwrite, memset, omTimerTickGet, ptable_dload_write, snprintf, update_record_file
 * Вызывают: ImageDloadToFlash
 * Константы: 0xFFFFFFFF, 0x30081F50
 * Данные: DAT_30082e78, DAT_30082e7c, DAT_30082e80, DAT_3008302c, DAT_30083030, DAT_30083034, DAT_30083038, DAT_3008303c
 * ---------------------------------------------------------------- */
undefined4 FUN_30081f50(void)

{
  undefined4 uVar1;
  FILE *pFVar2;
  size_t sVar3;
  int iVar4;
  char acStack_110 [256];
  
  if (*(int *)(*DAT_30082e78 + 4) - 0x100U < 0x100) {
    memset(acStack_110,0x100,0);
    uVar1 = omTimerTickGet();
    snprintf(acStack_110,0x100,DAT_30082e80,uVar1,*(undefined4 *)(*DAT_30082e78 + 0x10),
             DAT_30082e7c[1]);
    update_record_file(acStack_110);
    uVar1 = ptable_dload_write(*DAT_30082e7c,*(undefined4 *)(*DAT_30082e78 + 4),
                               *(undefined4 *)(*DAT_30082e78 + 0x10),DAT_30082e7c[1]);
    *(int *)(*DAT_30082e78 + 0x10) = *(int *)(*DAT_30082e78 + 0x10) + DAT_30082e7c[1];
  }
  else if ((*(int *)(*DAT_30082e78 + 4) < 1) || (0xfd < *(int *)(*DAT_30082e78 + 4))) {
    uVar1 = 0xffffffff;
  }
  else {
    if (*(int *)(*DAT_30082e78 + 0xc) == 0) {
      if (*(int *)(*DAT_30082e78 + 4) - 0x65U < 0x99) {
        OSAL_LogMsg(DAT_3008302c,1,2,3,4,5,6);
        memset(acStack_110,0x100,0);
        uVar1 = omTimerTickGet();
        snprintf(acStack_110,0x100,DAT_30083030,uVar1);
        update_record_file(acStack_110);
        return 0xffffffff;
      }
      pFVar2 = fopen(*(char **)(DAT_30083034 + *(int *)(*DAT_30082e78 + 4) * 4),DAT_30083038);
      *(FILE **)(*DAT_30082e78 + 0xc) = pFVar2;
      if (*(int *)(*DAT_30082e78 + 0xc) == 0) {
        OSAL_LogMsg(DAT_3008303c,1,2,3,4,5,6);
        memset(acStack_110,0x100,0);
        uVar1 = omTimerTickGet();
        snprintf(acStack_110,0x100,DAT_30083040,uVar1);
        update_record_file(acStack_110);
        return 0xffffffff;
      }
    }
    sVar3 = fwrite((void *)*DAT_30082e7c,1,DAT_30082e7c[1],*(FILE **)(*DAT_30082e78 + 0xc));
    if (sVar3 == DAT_30082e7c[1]) {
      iVar4 = fclose(*(FILE **)(*DAT_30082e78 + 0xc));
      if (iVar4 == 0) {
        *(undefined4 *)(*DAT_30082e78 + 0xc) = 0;
        uVar1 = 0;
      }
      else {
        OSAL_LogMsg(DAT_3008312c,1,2,3,4,5,6);
        memset(acStack_110,0x100,0);
        uVar1 = omTimerTickGet();
        snprintf(acStack_110,0x100,DAT_30083130,uVar1);
        update_record_file(acStack_110);
        uVar1 = 0xffffffff;
      }
    }
    else {
      OSAL_LogMsg(DAT_30083124,1,2,3,4,5,6);
      memset(acStack_110,0x100,0);
      uVar1 = omTimerTickGet();
      snprintf(acStack_110,0x100,DAT_30083128,uVar1);
      update_record_file(acStack_110);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * ImageDloadToFlash @ 0x30082428  (примерный размер ~920 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 10
 * Вызывает: FUN_30081f50, OSAL_LogMsg, dloadDealBootrom, memcpy, memset, omTimerTickGet, ptable_find_older_part, ptable_get_ram_data, snprintf, update_record_file
 * Вызывают: imageDloadProcess
 * Константы: 0xFFFFFFFF, 0x30082428
 * Данные: DAT_30082e78, DAT_30082e7c, DAT_30083398, DAT_3008339c, DAT_300833a0, DAT_300833a4, DAT_300834dc, DAT_300834e0
 * ---------------------------------------------------------------- */
undefined4 ImageDloadToFlash(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  size_t __n;
  size_t __n_00;
  int iVar7;
  char acStack_114 [256];
  
  __n_00 = 0;
  pcVar4 = acStack_114;
  iVar7 = 0x80;
  pcVar6 = DAT_30083398;
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
  if (*DAT_30082e7c == 0) {
    OSAL_LogMsg(DAT_3008339c,1,2,3,4,5,6);
    memset(acStack_114,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_114,0x100,DAT_300833a0,uVar3,DAT_30082e7c[1]);
    update_record_file(acStack_114);
    uVar3 = 0xffffffff;
  }
  else {
    if ((uint)(*DAT_300833a4 - DAT_30082e7c[1]) <= *(uint *)(*DAT_30082e78 + 0x18)) {
      __n_00 = *DAT_300833a4 - DAT_30082e7c[1];
      memcpy((void *)(*DAT_30082e7c + DAT_30082e7c[1]),*(void **)(*DAT_30082e78 + 0x14),__n_00);
      DAT_30082e7c[1] = *DAT_300833a4;
      iVar7 = FUN_30081f50();
      if (iVar7 != 0) {
        OSAL_LogMsg(DAT_300834dc,1,2,3,4,5,6);
        memset(acStack_114,0x100,0);
        uVar3 = omTimerTickGet();
        snprintf(acStack_114,0x100,DAT_300834e0,uVar3);
        update_record_file(acStack_114);
        return 0xffffffff;
      }
      DAT_30082e7c[1] = 0;
      __n = *(int *)(*DAT_30082e78 + 0x18) - __n_00;
      if (__n != 0) {
        memcpy((void *)(*DAT_30082e7c + DAT_30082e7c[1]),
               (void *)(*(int *)(*DAT_30082e78 + 0x14) + __n_00),__n);
        DAT_30082e7c[1] = __n + DAT_30082e7c[1];
      }
    }
    memcpy((void *)(*DAT_30082e7c + DAT_30082e7c[1]),
           (void *)(*(int *)(*DAT_30082e78 + 0x14) + __n_00),*(int *)(*DAT_30082e78 + 0x18) - __n_00
          );
    DAT_30082e7c[1] = DAT_30082e7c[1] + (*(int *)(*DAT_30082e78 + 0x18) - __n_00);
    *(int *)(*DAT_30082e78 + 0x1c) = *(int *)(*DAT_30082e78 + 0x1c) + *(int *)(*DAT_30082e78 + 0x18)
    ;
    if (*(int *)(*DAT_30082e78 + 8) == *(int *)(*DAT_30082e78 + 0x1c)) {
      iVar7 = FUN_30081f50();
      if (iVar7 != 0) {
        return 0xffffffff;
      }
      *DAT_30083650 = *(undefined4 *)(*DAT_30082e78 + 4);
      OSAL_LogMsg(DAT_30083654,*(undefined4 *)(*DAT_30082e78 + 4),2,3,4,5,6);
      DAT_30082e7c[1] = 0;
      if (*(int *)(*DAT_30082e78 + 4) - 0x100U < 0x100) {
        uVar3 = ptable_get_ram_data();
        ptable_find_older_part(*(undefined4 *)(*DAT_30082e78 + 4),uVar3,1,1);
        if (*(int *)(*DAT_30082e78 + 4) == DAT_30083658) {
          dloadDealBootrom();
        }
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300827c0 @ 0x300827C0  (примерный размер ~2020 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 10
 * Вызывает: OSAL_LogMsg, fclose, fopen, fwrite, imgSecHandle, memset, omTimerTickGet, ptable_dload_write, snprintf, update_record_file
 * Вызывают: ImageDloadToRam, dynFSDloadToRam
 * Константы: 0xFFFFFFFF, 0x300827C0
 * Данные: DAT_30082e78, DAT_30082e7c, DAT_30083034, DAT_30083038, DAT_3008303c, DAT_3008312c, DAT_30083130, DAT_3008365c
 * ---------------------------------------------------------------- */
undefined4 FUN_300827c0(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  FILE *pFVar4;
  size_t sVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  char acStack_114 [256];
  
  pcVar6 = acStack_114;
  iVar9 = 0x80;
  pcVar8 = DAT_3008365c;
  do {
    pcVar7 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 2;
    cVar2 = *pcVar7;
    iVar9 = iVar9 + -1;
    pcVar7 = pcVar6 + 1;
    *pcVar6 = cVar1;
    pcVar6 = pcVar6 + 2;
    *pcVar7 = cVar2;
  } while (iVar9 != 0);
  if (((int)DAT_30083660[2] < 1) || (0x1ff < (int)DAT_30083660[2])) {
    OSAL_LogMsg(DAT_30083718,DAT_30083660[2],0,0,0,0,0);
    memset(acStack_114,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_114,0x100,DAT_3008371c,uVar3,DAT_30083660[2]);
    update_record_file(acStack_114);
    uVar3 = 0xffffffff;
  }
  else if (DAT_30083660[2] - 0x100 < 0x100) {
    iVar9 = imgSecHandle(*DAT_30083660,DAT_30083660[2],DAT_30083660[3]);
    if (iVar9 == 0) {
      OSAL_LogMsg(DAT_30083830,1,2,3,4,5,6);
      uVar3 = ptable_dload_write(*DAT_30083660,DAT_30083660[2],DAT_30083660[4],DAT_30083660[3]);
    }
    else {
      OSAL_LogMsg(DAT_30083828,DAT_30083660[2],0,0,0,0,0);
      memset(acStack_114,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_114,0x100,DAT_3008382c,uVar3,DAT_30083660[2]);
      update_record_file(acStack_114);
      uVar3 = 0xffffffff;
    }
  }
  else if ((*(int *)(*DAT_30082e78 + 4) < 1) || (0xfd < *(int *)(*DAT_30082e78 + 4))) {
    OSAL_LogMsg(DAT_30083e6c,1,2,3,4,5,6);
    memset(acStack_114,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_114,0x100,DAT_30083e70,uVar3);
    update_record_file(acStack_114);
    uVar3 = 0xffffffff;
  }
  else {
    if (*(int *)(*DAT_30082e78 + 0xc) == 0) {
      if (*(int *)(*DAT_30082e78 + 4) - 0x65U < 0x99) {
        if (DAT_30082e7c[1] != DAT_30082e7c[2]) {
          OSAL_LogMsg(DAT_30083958,0,0,0,0,0,0);
          memset(acStack_114,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_114,0x100,DAT_3008395c,uVar3);
          update_record_file(acStack_114);
          return 0xffffffff;
        }
        iVar9 = imgSecHandle(*DAT_30082e7c,DAT_30082e7c[3],DAT_30082e7c[2]);
        if (iVar9 != 0) {
          OSAL_LogMsg(DAT_30083828,DAT_30083660[2],0,0,0,0,0);
          memset(acStack_114,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_114,0x100,DAT_3008382c,uVar3,DAT_30083660[2]);
          update_record_file(acStack_114);
          return 0xffffffff;
        }
        pFVar4 = fopen(DAT_30083960,DAT_30083038);
        *(FILE **)(*DAT_30082e78 + 0xc) = pFVar4;
        if (*(int *)(*DAT_30082e78 + 0xc) == 0) {
          OSAL_LogMsg(DAT_3008303c,1,2,3,4,5,6);
          memset(acStack_114,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_114,0x100,DAT_30083aa4,uVar3);
          update_record_file(acStack_114);
          return 0xffffffff;
        }
        sVar5 = fwrite((void *)*DAT_30082e7c,1,DAT_30082e7c[2],*(FILE **)(*DAT_30082e78 + 0xc));
        if (sVar5 != DAT_30082e7c[2]) {
          OSAL_LogMsg(DAT_30083aa8,1,2,3,4,5,6);
          memset(acStack_114,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_114,0x100,DAT_30083aac,uVar3);
          update_record_file(acStack_114);
          return 0xffffffff;
        }
      }
      else {
        iVar9 = imgSecHandle(*DAT_30083660,DAT_30083660[2],DAT_30083660[3]);
        if (iVar9 != 0) {
          OSAL_LogMsg(DAT_30083828,DAT_30083660[2],0,0,0,0,0);
          memset(acStack_114,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_114,0x100,DAT_3008382c,uVar3,DAT_30083660[2]);
          update_record_file(acStack_114);
          return 0xffffffff;
        }
        pFVar4 = fopen(*(char **)(DAT_30083034 + DAT_30083660[2] * 4),DAT_30083038);
        *(FILE **)(*DAT_30082e78 + 0xc) = pFVar4;
        if (*(int *)(*DAT_30082e78 + 0xc) == 0) {
          OSAL_LogMsg(DAT_3008303c,1,2,3,4,5,6);
          memset(acStack_114,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_114,0x100,DAT_30083aa4,uVar3);
          update_record_file(acStack_114);
          return 0xffffffff;
        }
        sVar5 = fwrite((void *)*DAT_30083660,1,DAT_30083660[3],*(FILE **)(*DAT_30082e78 + 0xc));
        if (sVar5 != DAT_30083660[3]) {
          OSAL_LogMsg(DAT_30083d24,1,2,3,4,5,6);
          memset(acStack_114,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_114,0x100,DAT_30083d28,uVar3);
          update_record_file(acStack_114);
          return 0xffffffff;
        }
      }
    }
    iVar9 = fclose(*(FILE **)(*DAT_30083d2c + 0xc));
    if (iVar9 == 0) {
      *(undefined4 *)(*DAT_30083d2c + 0xc) = 0;
      uVar3 = 0;
    }
    else {
      OSAL_LogMsg(DAT_3008312c,1,2,3,4,5,6);
      memset(acStack_114,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_114,0x100,DAT_30083130,uVar3);
      update_record_file(acStack_114);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * ImageDloadToRam @ 0x30082FA4  (примерный размер ~752 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 10
 * Вызывает: FUN_300827c0, OSAL_LogMsg, dloadDealBootrom, memcpy, memset, omTimerTickGet, ptable_find_older_part, ptable_get_ram_data, snprintf, update_record_file
 * Вызывают: imageDloadProcess
 * Константы: 0xFFFFFFFF, 0x30082FA4
 * Данные: DAT_30083650, DAT_30083658, DAT_30083660, DAT_30083d2c, DAT_30083e74, DAT_30083e78, DAT_30083fa0, DAT_300840a8
 * ---------------------------------------------------------------- */
undefined4 ImageDloadToRam(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char acStack_108 [256];
  
  pcVar4 = acStack_108;
  iVar7 = 0x80;
  pcVar6 = DAT_30083e74;
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
  if (*DAT_30083660 == 0) {
    OSAL_LogMsg(DAT_30083e78,1,2,3,4,5,6);
    memset(acStack_108,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_108,0x100,DAT_30083fa0,uVar3);
    update_record_file(acStack_108);
    uVar3 = 0xffffffff;
  }
  else {
    memcpy((void *)(*DAT_30083660 + DAT_30083660[1]),*(void **)(*DAT_30083d2c + 0x14),
           *(size_t *)(*DAT_30083d2c + 0x18));
    DAT_30083660[1] = DAT_30083660[1] + *(int *)(*DAT_30083d2c + 0x18);
    *(int *)(*DAT_30083d2c + 0x1c) = *(int *)(*DAT_30083d2c + 0x1c) + *(int *)(*DAT_30083d2c + 0x18)
    ;
    if (*(int *)(*DAT_30083d2c + 8) == *(int *)(*DAT_30083d2c + 0x1c)) {
      iVar7 = FUN_300827c0();
      if (iVar7 != 0) {
        return 0xffffffff;
      }
      *DAT_30083650 = *(undefined4 *)(*DAT_30083d2c + 4);
      DAT_30083660[5] = 0;
      OSAL_LogMsg(DAT_300840a8,*(undefined4 *)(*DAT_30083d2c + 4),2,3,4,5,6);
      if (*(int *)(*DAT_30083d2c + 4) - 0x100U < 0x100) {
        uVar3 = ptable_get_ram_data();
        ptable_find_older_part(*(undefined4 *)(*DAT_30083d2c + 4),uVar3,1,1);
        if (*(int *)(*DAT_30083d2c + 4) == DAT_30083658) {
          dloadDealBootrom();
        }
      }
    }
    else if (*(uint *)(*DAT_30083d2c + 8) < *(uint *)(*DAT_30083d2c + 0x1c)) {
      OSAL_LogMsg(DAT_300840ac,1,2,3,4,5,6);
      memset(acStack_108,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_108,0x100,DAT_300840b0,uVar3);
      update_record_file(acStack_108);
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * resetImgBuf @ 0x30083294  (примерный размер ~112 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: free
 * Вызывают: FUN_30080798, dloadFromFsMainThread, dloadTFPro
 * Константы: 0x30083294
 * Данные: DAT_30083660, DAT_30084200
 * ---------------------------------------------------------------- */
void resetImgBuf(void)

{
  if (DAT_30083660[5] == 0) {
    DAT_30083660[1] = 0;
    if (*DAT_30083660 != 0) {
      free((void *)*DAT_30083660);
      *DAT_30083660 = 0;
    }
    DAT_30083660[2] = 0x50;
    DAT_30083660[3] = 0;
    *DAT_30084200 = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * imageDloadProcess @ 0x30083304  (примерный размер ~676 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 7
 * Вызывает: ImageDloadToFlash, ImageDloadToRam, OSAL_LogMsg, memset, omTimerTickGet, snprintf, update_record_file
 * Вызывают: FUN_30080798, dloadFromFsMainThread, dloadTFPro
 * Константы: 0xFFFFFFFF, 0x30083304
 * Данные: DAT_300833a4, DAT_30083d2c, DAT_30084200, DAT_30084204, DAT_30084208, DAT_300842fc, DAT_30084300, DAT_30084304
 * ---------------------------------------------------------------- */
undefined4 imageDloadProcess(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char acStack_10c [256];
  
  pcVar4 = acStack_10c;
  iVar7 = 0x80;
  pcVar6 = DAT_30084204;
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
  if (((*DAT_30083d2c == 0) || (*DAT_300833a4 < *(uint *)(*DAT_30083d2c + 0x18))) ||
     (*(int *)(*DAT_30083d2c + 0x18) == 0)) {
    OSAL_LogMsg(DAT_30084208,*(undefined4 *)(*DAT_30083d2c + 0x18),2,3,4,5,6);
    memset(acStack_10c,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_10c,0x100,DAT_300842fc,uVar3,*(undefined4 *)(*DAT_30083d2c + 0x18));
    update_record_file(acStack_10c);
    return 0xffffffff;
  }
  if (*(int *)(*DAT_30083d2c + 0x1c) == 0) {
    OSAL_LogMsg(DAT_30084300,*(undefined4 *)(*DAT_30083d2c + 4),2,3,4,5,6);
    *(undefined4 *)(*DAT_30083d2c + 0x10) = 0;
    if (*(int *)(DAT_30084304 + 4) != 0) {
      OSAL_LogMsg(DAT_30084308,*(undefined4 *)(DAT_30084304 + 4),2,3,4,5,6);
      memset(acStack_10c,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_10c,0x100,DAT_30084410,uVar3,*(undefined4 *)(DAT_30084304 + 4));
      update_record_file(acStack_10c);
      return 0xffffffff;
    }
  }
  if (*DAT_30084200 == '\x01') {
    iVar7 = ImageDloadToRam();
    if (iVar7 != 0) {
      return 0xffffffff;
    }
  }
  else {
    if (*DAT_30084200 != '\0') {
      OSAL_LogMsg(DAT_30084414,*DAT_30084200,2,3,4,5,6);
      return 0xffffffff;
    }
    iVar7 = ImageDloadToFlash();
    if (iVar7 != 0) {
      return 0xffffffff;
    }
  }
  return 0;
}

