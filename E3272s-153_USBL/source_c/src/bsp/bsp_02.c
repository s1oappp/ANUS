/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : bsp — BSP Huawei: GPIO, HKADC, PMU HI6451, WDT, LED, SPI/SSI, таймеры, питание
 * Часть  : 2 (функций: 150, адреса 0x3000C698..0x300339B0)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * BSP_ShowFtpHostAddr @ 0x3000C698  (примерный размер ~60 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x3000C698
 * Данные: DAT_3000c928, DAT_3000c92c
 * ---------------------------------------------------------------- */
void BSP_ShowFtpHostAddr(void)

{
  logMsg(DAT_3000c92c,DAT_3000c928,0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * BSP_ShowLocalIPAddr @ 0x3000C6D4  (примерный размер ~76 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x3000C6D4
 * Данные: DAT_3000c8ac, DAT_3000c930
 * ---------------------------------------------------------------- */
void BSP_ShowLocalIPAddr(void)

{
  logMsg(DAT_3000c930,*DAT_3000c8ac,DAT_3000c8ac[1],DAT_3000c8ac[2],DAT_3000c8ac[3],0,0);
  return;
}

/* ----------------------------------------------------------------
 * BSP_ShowIfCfgFile @ 0x3000C720  (примерный размер ~312 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 9
 * Вызывает: FUN_3000c000, FUN_3000c600, close, free, logMsg, malloc, memset, open, printf
 * Константы: 0x3000C720
 * Данные: DAT_3000c8d0, DAT_3000c8e0, DAT_3000c934, DAT_3000c938, DAT_3000c93c, DAT_3000c940
 * ---------------------------------------------------------------- */
int BSP_ShowIfCfgFile(void)

{
  int __fd;
  void *__s;
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  __fd = open(DAT_3000c934,0,DAT_3000c8e0);
  if (__fd < 1) {
    logMsg(DAT_3000c938,0x298,__fd,3,4,5,6);
    iVar1 = -1;
  }
  else {
    __s = malloc(0x40);
    if (__s == (void *)0x0) {
      logMsg(DAT_3000c8d0,0x2a0,0x40,3,4,5,6);
      iVar1 = -1;
    }
    else {
      memset(__s,0,0x40);
      printf(DAT_3000c93c);
      for (uVar2 = 0; uVar2 < 6; uVar2 = uVar2 + 1) {
        iVar1 = FUN_3000c000(__fd,__s,uVar2 << 6,0x40,1);
        if (iVar1 != 0) goto LAB_3000c83c;
        FUN_3000c600(uVar2,__s);
      }
      printf(DAT_3000c940);
LAB_3000c83c:
      free(__s);
    }
    close(__fd);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * BSP_SetupDeviceNofyHook @ 0x3000C858  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000C858
 * Данные: DAT_3000c944
 * ---------------------------------------------------------------- */
undefined4 BSP_SetupDeviceNofyHook(undefined4 param_1)

{
  *DAT_3000c944 = param_1;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3000c874 @ 0x3000C874  (примерный размер ~980 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: BSP_IfConfigFromFile
 * Константы: 0x3000C874, 0x3000C89C, 0xFFFFFFFF
 * Данные: DAT_3000c948, DAT_3000d0bc
 * ---------------------------------------------------------------- */
undefined4 FUN_3000c874(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 6) {
                    /* WARNING: Could not recover jumptable at 0x3000c89c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_3000c948 + param_2 * 4))();
    return uVar1;
  }
  logMsg(DAT_3000d0bc,param_2,0x38c,3,4,5,6);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * BSP_IfConfigFromFile @ 0x3000CC48  (примерный размер ~268 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 7
 * Вызывает: FUN_3000c874, close, free, logMsg, malloc, memset, open
 * Константы: 0x3000CC48
 * Данные: DAT_3000d0c0, DAT_3000d0c4, DAT_3000d0c8, DAT_3000d0cc, DAT_3000d0d0
 * ---------------------------------------------------------------- */
int BSP_IfConfigFromFile(void)

{
  int __fd;
  void *__s;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  __fd = open(DAT_3000d0c0,0,DAT_3000d0c4);
  if (__fd < 1) {
    logMsg(DAT_3000d0c8,__fd,2,3,4,5,6);
    iVar2 = -1;
  }
  else {
    __s = malloc(0x40);
    if (__s == (void *)0x0) {
      logMsg(DAT_3000d0cc,DAT_3000d0d0,0x40,3,4,5,6);
      iVar2 = -1;
    }
    else {
      memset(__s,0,0x40);
      iVar1 = 0;
      while ((iVar1 < 6 && (iVar2 = FUN_3000c874(__fd,iVar1,__s), iVar2 == 0))) {
        iVar1 = iVar1 + 1;
      }
      free(__s);
    }
    close(__fd);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * BSP_NET_OMIpMacSet @ 0x3000CD54  (примерный размер ~88 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x3000CD54
 * Данные: DAT_3000d0d4, DAT_3000d0d8, DAT_3000d0dc
 * ---------------------------------------------------------------- */
undefined4 BSP_NET_OMIpMacSet(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_3000d0d4;
  if (param_1 != 0) {
    logMsg(DAT_3000d0d8,0x3a8,2,3,4,5,6);
    uVar1 = DAT_3000d0dc;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_NET_OMIpMacGet @ 0x3000CDAC  (примерный размер ~168 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: logMsg, memcpy
 * Константы: 0x3000CDAC
 * Данные: DAT_3000d0d4, DAT_3000d0d8, DAT_3000d0dc, DAT_3000d0e0, DAT_3000d0e4, DAT_3000d0e8
 * ---------------------------------------------------------------- */
undefined4 BSP_NET_OMIpMacGet(int param_1,void *param_2,void *param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = DAT_3000d0d4;
    if (param_2 != (void *)0x0) {
      memcpy(param_2,DAT_3000d0e4,4);
      uVar1 = 0;
    }
    if (param_3 != (void *)0x0) {
      memcpy(param_3,DAT_3000d0e8,4);
      uVar1 = 0;
    }
    if (param_4 != 0) {
      uVar1 = DAT_3000d0dc;
    }
  }
  else {
    logMsg(DAT_3000d0d8,DAT_3000d0e0,2,3,4,5,6);
    uVar1 = DAT_3000d0dc;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GetMacAddr @ 0x3000CE54  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_NET_PsMacGet
 * Константы: 0x3000CE54
 * Данные: DAT_3000d0ec
 * ---------------------------------------------------------------- */
undefined4 BSP_GetMacAddr(void)

{
  return DAT_3000d0ec;
}

/* ----------------------------------------------------------------
 * BSP_SetPsMacAddrEx @ 0x3000CE5C  (примерный размер ~292 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: BSP_SetPsMacAddr, FUN_3000c338, logMsg
 * Вызывают: BSP_NET_PsMacSet
 * Константы: 0xFFFFFFFF, 0x3000CE5C
 * Данные: DAT_3000d0b0, DAT_3000d0c0, DAT_3000d0f0, DAT_3000d0f4, DAT_3000d0f8
 * ---------------------------------------------------------------- */
undefined4
BSP_SetPsMacAddrEx(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined1 param_5,undefined1 param_6)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 local_28 [5];
  undefined1 local_23;
  
  puVar4 = local_28;
  iVar7 = 3;
  puVar6 = DAT_3000d0f0;
  do {
    puVar5 = puVar6 + 1;
    uVar1 = *puVar6;
    puVar6 = puVar6 + 2;
    uVar2 = *puVar5;
    iVar7 = iVar7 + -1;
    puVar5 = puVar4 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 2;
    *puVar5 = uVar2;
  } while (iVar7 != 0);
  iVar7 = BSP_SetPsMacAddr(param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar7 == 0) {
    local_28[0] = (undefined1)param_1;
    local_28[1] = (undefined1)param_2;
    local_28[2] = (undefined1)param_3;
    local_28[3] = (undefined1)param_4;
    local_28[4] = param_5;
    local_23 = param_6;
    iVar7 = FUN_3000c338(DAT_3000d0c0,4,local_28);
    if (iVar7 == 0) {
      uVar3 = 0;
    }
    else {
      logMsg(DAT_3000d0b0,DAT_3000d0f8,iVar7,3,4,5,6);
      uVar3 = 0xffffffff;
    }
  }
  else {
    logMsg(DAT_3000d0b0,DAT_3000d0f4,iVar7,3,4,5,6);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * BSP_NET_PsMacSet @ 0x3000CF80  (примерный размер ~72 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_SetPsMacAddrEx
 * Константы: 0x3000CF80
 * Данные: DAT_3000d0d4
 * ---------------------------------------------------------------- */
undefined4 BSP_NET_PsMacSet(undefined1 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_3000d0d4;
  if (param_1 != (undefined1 *)0x0) {
    uVar1 = BSP_SetPsMacAddrEx(*param_1,param_1[1],param_1[2],param_1[3],param_1[4],param_1[5]);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_NET_PsMacGet @ 0x3000CFC8  (примерный размер ~60 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_GetMacAddr, memcpy
 * Константы: 0x3000CFC8
 * Данные: DAT_3000d0d4
 * ---------------------------------------------------------------- */
undefined4 BSP_NET_PsMacGet(void *param_1)

{
  void *__src;
  undefined4 uVar1;
  
  uVar1 = DAT_3000d0d4;
  if (param_1 != (void *)0x0) {
    __src = (void *)BSP_GetMacAddr();
    memcpy(param_1,__src,6);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_printProcessTrace @ 0x3000D100  (примерный размер ~128 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x3000D100
 * Данные: DAT_3000d2c8, DAT_3000d2cc, DAT_3000d2d0, DAT_3000d2d4, DAT_3000d2d8, DAT_3000d2dc, DAT_3000d2e0, DAT_3000d2e4
 * ---------------------------------------------------------------- */
void BSP_printProcessTrace(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined4 *)*DAT_3000d2c8;
  printf(DAT_3000d2cc);
  for (uVar2 = 0; uVar2 < 0x29; uVar2 = uVar2 + 1) {
    printf(DAT_3000d2d4,DAT_3000d2d0 + uVar2 * 0x20,*puVar1);
    puVar1 = puVar1 + 1;
  }
  puVar1 = (undefined4 *)*DAT_3000d2d8;
  printf(DAT_3000d2dc);
  for (uVar2 = 0; uVar2 < 0x20; uVar2 = uVar2 + 1) {
    printf(DAT_3000d2d4,DAT_3000d2e0 + uVar2 * 0x20,*puVar1);
    puVar1 = puVar1 + 1;
  }
  printf(DAT_3000d2e4);
  return;
}

/* ----------------------------------------------------------------
 * BSP_printLastProcessTrace @ 0x3000D180  (примерный размер ~192 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x3000D180
 * Данные: DAT_3000d2c8, DAT_3000d2cc, DAT_3000d2d0, DAT_3000d2d4, DAT_3000d2d8, DAT_3000d2dc, DAT_3000d2e0, DAT_3000d2e4
 * ---------------------------------------------------------------- */
void BSP_printLastProcessTrace(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = DAT_3000d2e8;
  if ((undefined4 *)*DAT_3000d2c8 == DAT_3000d2e8) {
    puVar2 = DAT_3000d2ec;
  }
  puVar1 = (undefined4 *)(DAT_3000d2f0 + (uint)(*DAT_3000d2d8 == DAT_3000d2f0) * 0x200);
  printf(DAT_3000d2cc);
  for (uVar3 = 0; uVar3 < 0x29; uVar3 = uVar3 + 1) {
    printf(DAT_3000d2d4,DAT_3000d2d0 + uVar3 * 0x20,*puVar2);
    puVar2 = puVar2 + 1;
  }
  printf(DAT_3000d2dc);
  for (uVar3 = 0; uVar3 < 0x20; uVar3 = uVar3 + 1) {
    printf(DAT_3000d2d4,DAT_3000d2e0 + uVar3 * 0x20,*puVar1);
    puVar1 = puVar1 + 1;
  }
  printf(DAT_3000d2e4);
  return;
}

/* ----------------------------------------------------------------
 * BSP_traceProcessInit @ 0x3000D240  (примерный размер ~132 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: sysClkInt
 * Константы: 0x3000D240
 * Данные: DAT_3000d2c8, DAT_3000d2d8, DAT_3000d2e8, DAT_3000d2ec, DAT_3000d2f0, DAT_3000d2f4, DAT_3000d2f8, DAT_3000d2fc
 * ---------------------------------------------------------------- */
void BSP_traceProcessInit(void)

{
  if (*DAT_3000d2f4 != 1) {
    *DAT_3000d2f4 = 1;
    if (*DAT_3000d2f8 == 0) {
      *DAT_3000d2f8 = 1;
      *DAT_3000d2c8 = DAT_3000d2e8;
      *DAT_3000d2d8 = DAT_3000d2f0;
    }
    else {
      *DAT_3000d2f8 = 0;
      *DAT_3000d2c8 = DAT_3000d2ec;
      *DAT_3000d2d8 = DAT_3000d2fc;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_Flashless_HwGetVerMain @ 0x3000D300  (примерный размер ~164 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: logMsg, strcmp
 * Константы: 0x3000D300
 * Данные: DAT_3000dd30, DAT_3000dd34, DAT_3000dd38, DAT_3000dd3c, DAT_3000dd40
 * ---------------------------------------------------------------- */
undefined4 BSP_Flashless_HwGetVerMain(void)

{
  int iVar1;
  uint uVar2;
  char *__s2;
  
  uVar2 = 0;
  __s2 = DAT_3000dd30;
  while( true ) {
    if (0x13 < uVar2) {
      logMsg(DAT_3000dd40,0,0,0,0,0,0);
      return 0;
    }
    iVar1 = strcmp(DAT_3000dd34,__s2);
    if (iVar1 == 0) break;
    __s2 = __s2 + 0x30;
    uVar2 = uVar2 + 1;
  }
  logMsg(DAT_3000dd38,*(undefined4 *)(__s2 + 0x10),DAT_3000dd3c,0,0,0,0);
  return *(undefined4 *)(__s2 + 0x10);
}

/* ----------------------------------------------------------------
 * BSP_ProductInfoInit @ 0x3000D644  (примерный размер ~440 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: hwVerGet, logMsg, memcpy, memset
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0xFFFFFFFF, 0x3000D644
 * Данные: DAT_3000dd74, DAT_3000dd78, DAT_3000dd7c, DAT_3000dd80, DAT_3000dd84, DAT_3000dd88, DAT_3000dd8c, DAT_3000dd90
 * ---------------------------------------------------------------- */
undefined4 BSP_ProductInfoInit(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  byte local_10 [2];
  short local_e;
  
  memset(DAT_3000dd74,0,0x34);
  *(short *)DAT_3000dd74 = (short)DAT_3000dd78;
  *(undefined2 *)((int)DAT_3000dd74 + 2) = 0xff;
  DAT_3000dd74[1] = DAT_3000dd7c;
  DAT_3000dd74[2] = DAT_3000dd80;
  DAT_3000dd74[3] = DAT_3000dd84;
  DAT_3000dd74[4] = DAT_3000dd88;
  DAT_3000dd74[5] = DAT_3000dd8c;
  memset(DAT_3000dd90,0,0xc);
  memset(DAT_3000dd94,0,0xc);
  iVar1 = hwVerGet(&local_e,local_10);
  if (iVar1 != 0) {
    logMsg(DAT_3000dd98,0,iVar1,0,0,0,0);
    return 0xffffffff;
  }
  uVar7 = 0;
  while( true ) {
    if (0x11 < uVar7) goto LAB_3000d7a4;
    if (*(short *)(DAT_3000dd9c + uVar7 * 0x34) == local_e) break;
    uVar7 = uVar7 + 1;
  }
  puVar5 = (undefined4 *)(DAT_3000dd9c + uVar7 * 0x34);
  iVar1 = 6;
  puVar4 = DAT_3000dd74;
  do {
    puVar6 = puVar5 + 1;
    uVar2 = *puVar5;
    puVar5 = puVar5 + 2;
    uVar3 = *puVar6;
    iVar1 = iVar1 + -1;
    puVar6 = puVar4 + 1;
    *puVar4 = uVar2;
    puVar4 = puVar4 + 2;
    *puVar6 = uVar3;
  } while (iVar1 != 0);
  *puVar4 = *puVar5;
  *(ushort *)((int)DAT_3000dd74 + 2) = (ushort)local_10[0];
LAB_3000d7a4:
  if (uVar7 == 0x12) {
    logMsg(DAT_3000dda0,0,local_e,local_10[0],0,0,0);
    return 0xffffffff;
  }
  memcpy(DAT_3000dda4,DAT_3000dd74,0x34);
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_HwGetVerMain @ 0x3000D7FC  (примерный размер ~12 байт)
 * Модуль: bsp | Вызывают: 8 | Вызывает: 0
 * Вызывают: BSP_HKADC_DcxoTempRead, BSP_HKADC_LtePAPowerRead, BSP_HKADC_LtePATempRead, BSP_HKADC_SIMTempRead, BSP_HKADC_TftTempRead, BSP_PMU_BoardInit, BSP_PWRCTRL_GetTemp, BSP_PrintHwVersion
 * Константы: 0x3000D7FC
 * Данные: DAT_3000dd74
 * ---------------------------------------------------------------- */
undefined2 BSP_HwGetVerMain(void)

{
  return *DAT_3000dd74;
}

/* ----------------------------------------------------------------
 * BSP_HwGetVerSub @ 0x3000D808  (примерный размер ~12 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_PrintHwVersion
 * Константы: 0x3000D808
 * Данные: DAT_3000dd74
 * ---------------------------------------------------------------- */
undefined2 BSP_HwGetVerSub(void)

{
  return *(undefined2 *)(DAT_3000dd74 + 2);
}

/* ----------------------------------------------------------------
 * BSP_HwGetHwVersion @ 0x3000D814  (примерный размер ~192 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: memset, strcat, strlen
 * Вызывают: BSP_PrintHwVersion
 * Константы: 0xFFFFFFFF, 0x3000D814
 * Данные: DAT_3000dd74, DAT_3000dd78, DAT_3000dda8, DAT_3000ddac
 * ---------------------------------------------------------------- */
undefined4 BSP_HwGetHwVersion(char *param_1,uint param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  size_t sVar3;
  size_t sVar4;
  char *__dest;
  uint uVar5;
  
  if ((*DAT_3000dd74 == DAT_3000dd78) || (param_1 == (char *)0x0)) {
    uVar2 = 0xffffffff;
  }
  else {
    sVar3 = strlen(*(char **)(DAT_3000dd74 + 6));
    sVar4 = strlen(DAT_3000dda8);
    uVar5 = sVar4 + sVar3;
    if (uVar5 < param_2) {
      uVar1 = DAT_3000dd74[1];
      memset(param_1,0,param_2);
      __dest = strcat(param_1,*(char **)(DAT_3000dd74 + 6));
      strcat(__dest,DAT_3000ddac);
      param_1[uVar5 - 1] = (char)uVar1 + 'A';
      param_1[uVar5] = '\0';
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_HwGetPCBVersion @ 0x3000D8D4  (примерный размер ~136 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: memcpy, memset, strlen
 * Вызывают: BSP_PrintHwVersion
 * Константы: 0xFFFFFFFF, 0x3000D8D4
 * Данные: DAT_3000dd74, DAT_3000dd78
 * ---------------------------------------------------------------- */
undefined4 BSP_HwGetPCBVersion(void *param_1,uint param_2)

{
  undefined4 uVar1;
  size_t __n;
  
  if ((*DAT_3000dd74 == DAT_3000dd78) || (param_1 == (void *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    __n = strlen(*(char **)(DAT_3000dd74 + 6));
    if (__n < param_2) {
      memset(param_1,0,param_2);
      memcpy(param_1,*(void **)(DAT_3000dd74 + 6),__n);
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GetProductName @ 0x3000D95C  (примерный размер ~152 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: memset, strcat, strlen
 * Вызывают: BSP_PrintHwVersion
 * Константы: 0xFFFFFFFF, 0x3000D95C
 * Данные: DAT_3000dd74, DAT_3000dd78
 * ---------------------------------------------------------------- */
undefined4 BSP_GetProductName(char *param_1,uint param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  
  if ((*DAT_3000dd74 == DAT_3000dd78) || (param_1 == (char *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    sVar2 = strlen(*(char **)(DAT_3000dd74 + 10));
    if (sVar2 < param_2) {
      memset(param_1,0,param_2);
      strcat(param_1,*(char **)(DAT_3000dd74 + 10));
      sVar2 = strlen(*(char **)(DAT_3000dd74 + 10));
      param_1[sVar2] = '\0';
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GetProductDloadName @ 0x3000D9F4  (примерный размер ~152 байт)
 * Модуль: bsp | Вызывают: 3 | Вызывает: 3
 * Вызывает: memset, strcat, strlen
 * Вызывают: BSP_DLOAD_GetDloadInfo, BSP_PrintHwVersion, getDloadID
 * Константы: 0xFFFFFFFF, 0x3000D9F4
 * Данные: DAT_3000dd74, DAT_3000dd78
 * ---------------------------------------------------------------- */
undefined4 BSP_GetProductDloadName(char *param_1,uint param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  
  if ((*DAT_3000dd74 == DAT_3000dd78) || (param_1 == (char *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    sVar2 = strlen(*(char **)(DAT_3000dd74 + 8));
    if (sVar2 < param_2) {
      memset(param_1,0,param_2);
      strcat(param_1,*(char **)(DAT_3000dd74 + 8));
      sVar2 = strlen(*(char **)(DAT_3000dd74 + 8));
      param_1[sVar2] = '\0';
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GetProductInnerName @ 0x3000DA8C  (примерный размер ~200 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: memset, strcat, strlen
 * Вызывают: BSP_PrintHwVersion
 * Константы: 0xFFFFFFFF, 0x3000DA8C
 * Данные: DAT_3000dd74, DAT_3000dd78
 * ---------------------------------------------------------------- */
undefined4 BSP_GetProductInnerName(char *param_1,uint param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  size_t sVar3;
  char *__dest;
  
  if ((*DAT_3000dd74 == DAT_3000dd78) || (param_1 == (char *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    sVar2 = strlen(*(char **)(DAT_3000dd74 + 2));
    sVar3 = strlen(*(char **)(DAT_3000dd74 + 4));
    if (sVar3 + sVar2 < param_2) {
      memset(param_1,0,param_2);
      __dest = strcat(param_1,*(char **)(DAT_3000dd74 + 2));
      strcat(__dest,*(char **)(DAT_3000dd74 + 4));
      sVar2 = strlen(*(char **)(DAT_3000dd74 + 4));
      sVar3 = strlen(*(char **)(DAT_3000dd74 + 2));
      param_1[sVar3 + sVar2] = '\0';
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GetSupportBands @ 0x3000DB54  (примерный размер ~88 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_PrintHwVersion
 * Константы: 0x3000DB54, 0xFFFFFFFF
 * Данные: DAT_3000dd74, DAT_3000dd78, DAT_3000dd90
 * ---------------------------------------------------------------- */
undefined4 BSP_GetSupportBands(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_3000dd90;
  if ((*DAT_3000dd74 == DAT_3000dd78) || (param_1 == (undefined4 *)0x0)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = DAT_3000dd90[1];
    *param_1 = *DAT_3000dd90;
    param_1[1] = uVar2;
    param_1[2] = puVar1[2];
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_GetSupportBandsForGu @ 0x3000DBAC  (примерный размер ~108 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000DBAC, 0xFFFFFFFF
 * Данные: DAT_3000dd74, DAT_3000dd78
 * ---------------------------------------------------------------- */
undefined4 BSP_GetSupportBandsForGu(ushort *param_1,ushort *param_2)

{
  undefined4 uVar1;
  
  if (((*DAT_3000dd74 == DAT_3000dd78) || (param_1 == (ushort *)0x0)) || (param_2 == (ushort *)0x0))
  {
    uVar1 = 0xffffffff;
  }
  else {
    *param_1 = (ushort)*(undefined4 *)(DAT_3000dd74 + 0xc) & (ushort)DAT_3000dd78;
    *param_2 = DAT_3000dd74[0xd] & (ushort)DAT_3000dd78;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_HwIsSupportWifi @ 0x3000DC18  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000DC18
 * ---------------------------------------------------------------- */
undefined4 BSP_HwIsSupportWifi(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_PrintHwVersion @ 0x3000DC20  (примерный размер ~444 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 9
 * Вызывает: BSP_GetProductDloadName, BSP_GetProductInnerName, BSP_GetProductName, BSP_GetSupportBands, BSP_HwGetHwVersion, BSP_HwGetPCBVersion, BSP_HwGetVerMain, BSP_HwGetVerSub, printf
 * Константы: 0x3000DC20
 * Данные: DAT_3000ddb0, DAT_3000ddb4, DAT_3000ddb8, DAT_3000ddbc, DAT_3000ddc0, DAT_3000ddc4, DAT_3000ddc8, DAT_3000ddcc
 * ---------------------------------------------------------------- */
undefined4 BSP_PrintHwVersion(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 auStack_28 [32];
  
  uVar1 = BSP_HwGetVerMain();
  printf(DAT_3000ddb0,uVar1 & 0xffff);
  uVar1 = BSP_HwGetVerSub();
  printf(DAT_3000ddb4,uVar1 & 0xffff);
  uVar2 = BSP_GetSupportBands(&local_34);
  printf(DAT_3000ddb8);
  printf(DAT_3000ddbc,local_34);
  printf(DAT_3000ddc0,local_30);
  printf(DAT_3000ddc4,local_2c);
  BSP_GetProductName(auStack_28,0x20);
  printf(DAT_3000ddc8,auStack_28);
  BSP_GetProductInnerName(auStack_28,0x20);
  printf(DAT_3000ddcc,auStack_28);
  BSP_GetProductDloadName(auStack_28,0x20);
  printf(DAT_3000ddd0,auStack_28);
  BSP_HwGetHwVersion(auStack_28,0x20);
  printf(DAT_3000ddd4,auStack_28);
  BSP_HwGetPCBVersion(auStack_28,0x20);
  printf(DAT_3000ddd8,auStack_28);
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_OM_RegRead @ 0x3000DFD0  (примерный размер ~132 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: OM_REGCheckVolid
 * Константы: 0xFFFFFFFF, 0x3000DFD0
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_RegRead(uint *param_1,int param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = OM_REGCheckVolid(param_1);
  if (iVar1 == 0) {
    if (param_2 == 0) {
      *param_3 = (uint)(byte)*param_1;
      uVar2 = 0;
    }
    else if (param_2 == 1) {
      *param_3 = (uint)(ushort)*param_1;
      uVar2 = 0;
    }
    else if (param_2 == 2) {
      *param_3 = *param_1;
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_OM_RegWrite @ 0x3000E054  (примерный размер ~120 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: OM_REGCheckVolid
 * Константы: 0xFFFFFFFF, 0x3000E054
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_RegWrite(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = OM_REGCheckVolid(param_1);
  if (iVar1 == 0) {
    if (param_2 == 0) {
      *(char *)param_1 = (char)param_3;
      uVar2 = 0;
    }
    else if (param_2 == 1) {
      *(short *)param_1 = (short)param_3;
      uVar2 = 0;
    }
    else if (param_2 == 2) {
      *param_1 = param_3;
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_OM_MemRead @ 0x3000E0CC  (примерный размер ~132 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: OM_RAMCheckVolid
 * Константы: 0xFFFFFFFF, 0x3000E0CC
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_MemRead(uint *param_1,int param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = OM_RAMCheckVolid(param_1);
  if (iVar1 == 0) {
    if (param_2 == 0) {
      *param_3 = (uint)(byte)*param_1;
      uVar2 = 0;
    }
    else if (param_2 == 1) {
      *param_3 = (uint)(ushort)*param_1;
      uVar2 = 0;
    }
    else if (param_2 == 2) {
      *param_3 = *param_1;
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_OM_MemWrite @ 0x3000E150  (примерный размер ~120 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: OM_RAMCheckVolid
 * Константы: 0xFFFFFFFF, 0x3000E150
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_MemWrite(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = OM_RAMCheckVolid(param_1);
  if (iVar1 == 0) {
    if (param_2 == 0) {
      *(char *)param_1 = (char)param_3;
      uVar2 = 0;
    }
    else if (param_2 == 1) {
      *(short *)param_1 = (short)param_3;
      uVar2 = 0;
    }
    else if (param_2 == 2) {
      *param_1 = param_3;
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_OM_MemNWrite @ 0x3000E1C8  (примерный размер ~108 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: OM_RAMCheckVolid
 * Константы: 0x3000E1C8, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_MemNWrite(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = OM_RAMCheckVolid(param_1);
  iVar2 = OM_RAMCheckVolid((int)param_1 + param_3);
  if ((iVar1 == 0) && (iVar2 == 0)) {
    for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + 1) {
      *param_1 = param_2;
      param_1 = param_1 + 1;
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * BSP_OM_MemPrint @ 0x3000E234  (примерный размер ~176 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_3011c7a0, OM_RAMCheckVolid
 * Константы: 0xFFFFFFFF, 0x3000E234
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_MemPrint(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = OM_RAMCheckVolid(param_1);
  iVar2 = OM_RAMCheckVolid(param_1 + 0x40);
  if ((iVar1 == 0) && (iVar2 == 0)) {
    if (param_2 == 0) {
      FUN_3011c7a0(param_1,0x40,1);
      uVar3 = 0;
    }
    else if (param_2 == 1) {
      FUN_3011c7a0(param_1,0x20,2);
      uVar3 = 0;
    }
    else if (param_2 == 2) {
      FUN_3011c7a0(param_1,0x10,4);
      uVar3 = 0;
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * BSP_OM_MemChk @ 0x3000E2E4  (примерный размер ~396 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: OM_RAMCheckVolid
 * Константы: 0xFFFFFFFF, 0x3000E2E4
 * Данные: DAT_3000e9b0
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_MemChk(ushort *param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  ushort *puVar5;
  
  iVar2 = OM_RAMCheckVolid(param_1);
  if (iVar2 == 0) {
    iVar2 = OM_RAMCheckVolid(param_2);
    if (iVar2 == 0) {
      if (param_3 == 1) {
        puVar5 = param_1;
        for (uVar4 = 0; uVar4 < (uint)(param_2 - (int)param_1) >> 1; uVar4 = uVar4 + 1) {
          uVar1 = *puVar5;
          *puVar5 = 0;
          if (*puVar5 != 0) {
            *puVar5 = uVar1;
            return 0xffffffff;
          }
          *puVar5 = (ushort)DAT_3000e9b0;
          if (*puVar5 != DAT_3000e9b0) {
            *puVar5 = uVar1;
            return 0xffffffff;
          }
          *puVar5 = uVar1;
          puVar5 = puVar5 + 1;
        }
        uVar3 = 0;
      }
      else if (param_3 == 0) {
        puVar5 = param_1;
        for (uVar4 = 0; uVar4 < (uint)(param_2 - (int)param_1) >> 2; uVar4 = uVar4 + 1) {
          uVar3 = *(undefined4 *)puVar5;
          puVar5[0] = 0;
          puVar5[1] = 0;
          if (*(int *)puVar5 != 0) {
            *(undefined4 *)puVar5 = uVar3;
            return 0xffffffff;
          }
          puVar5[0] = 0xffff;
          puVar5[1] = 0xffff;
          if (*(int *)puVar5 != -1) {
            *(undefined4 *)puVar5 = uVar3;
            return 0xffffffff;
          }
          *(undefined4 *)puVar5 = uVar3;
          puVar5 = puVar5 + 2;
        }
        uVar3 = 0;
      }
      else {
        uVar3 = 0xffffffff;
      }
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * BSP_OM_GetVerTime @ 0x3000E470  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: strcpy
 * Константы: 0x3000E470
 * Данные: DAT_3000e9b4
 * ---------------------------------------------------------------- */
void BSP_OM_GetVerTime(char *param_1)

{
  strcpy(param_1,(char *)*DAT_3000e9b4);
  return;
}

/* ----------------------------------------------------------------
 * BSP_GetBootBuildVersion @ 0x3000E48C  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_OM_GetVersion
 * Константы: 0x3000E48C
 * Данные: DAT_3000e9b8
 * ---------------------------------------------------------------- */
undefined4 BSP_GetBootBuildVersion(void)

{
  return DAT_3000e9b8;
}

/* ----------------------------------------------------------------
 * BSP_GetBuildVersion @ 0x3000E494  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_OM_GetVersion
 * Константы: 0x3000E494
 * Данные: DAT_3000e9bc
 * ---------------------------------------------------------------- */
undefined4 BSP_GetBuildVersion(void)

{
  return DAT_3000e9bc;
}

/* ----------------------------------------------------------------
 * BSP_OM_GetVersion @ 0x3000E49C  (примерный размер ~384 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 5
 * Вызывает: BSP_GetBootBuildVersion, BSP_GetBuildVersion, OM_GetVersionInfo, logMsg, sprintf
 * Константы: 0x3000E49C
 * Данные: DAT_3000e9c0, DAT_3000e9c4, DAT_3000e9c8, DAT_3000e9cc, DAT_3000e9d0, DAT_3000e9d4
 * ---------------------------------------------------------------- */
void BSP_OM_GetVersion(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  char *pcVar11;
  char *pcVar12;
  int iVar13;
  undefined1 auStack_17c [16];
  undefined1 auStack_16c [16];
  undefined1 auStack_15c [16];
  undefined1 auStack_14c [16];
  undefined1 auStack_13c [16];
  undefined1 auStack_12c [32];
  char acStack_10c [256];
  
  puVar5 = (undefined2 *)BSP_GetBootBuildVersion();
  puVar6 = (undefined2 *)BSP_GetBuildVersion();
  puVar7 = auStack_17c;
  iVar13 = 0x38;
  puVar10 = DAT_3000e9c0;
  do {
    puVar9 = puVar10 + 1;
    uVar1 = *puVar10;
    puVar10 = puVar10 + 2;
    uVar2 = *puVar9;
    iVar13 = iVar13 + -1;
    puVar9 = puVar7 + 1;
    *puVar7 = uVar1;
    puVar7 = puVar7 + 2;
    *puVar9 = uVar2;
  } while (iVar13 != 0);
  iVar13 = 0x80;
  pcVar8 = acStack_10c;
  pcVar12 = DAT_3000e9c4;
  do {
    pcVar11 = pcVar12 + 1;
    cVar3 = *pcVar12;
    pcVar12 = pcVar12 + 2;
    cVar4 = *pcVar11;
    iVar13 = iVar13 + -1;
    pcVar11 = pcVar8 + 1;
    *pcVar8 = cVar3;
    pcVar8 = pcVar8 + 2;
    *pcVar11 = cVar4;
  } while (iVar13 != 0);
  OM_GetVersionInfo(auStack_17c,cVar4,acStack_10c);
  sprintf(acStack_10c,DAT_3000e9c8,auStack_17c,auStack_16c,auStack_15c,auStack_14c,auStack_13c,
          auStack_12c);
  if (puVar6[4] == 0) {
    logMsg(DAT_3000e9d0,*puVar6,puVar6[1],puVar6[2],puVar6[3],acStack_10c,0);
  }
  else {
    logMsg(DAT_3000e9cc,*puVar6,puVar6[1],puVar6[2],puVar6[4],puVar6[3],acStack_10c);
  }
  logMsg(DAT_3000e9d4,*puVar5,puVar5[1],puVar5[2],puVar5[3],0,0);
  return;
}

/* ----------------------------------------------------------------
 * BSP_OM_GetDloadVer @ 0x3000E61C  (примерный размер ~476 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 4
 * Вызывает: DR_NV_Read, logMsg, memcpy, strlen
 * Вызывают: BSP_DLOAD_GetSoftwareVer, exchInit
 * Константы: 0x3000E61C, 0xFFFFFFFF
 * Данные: DAT_3000e9d8, DAT_3000e9dc, DAT_3000e9e0, DAT_3000e9e4, DAT_3000e9e8, DAT_3000e9ec, DAT_3000e9f0
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_GetDloadVer(void *param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  char *__s;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined4 local_38;
  undefined2 local_34 [16];
  
  puVar5 = &local_38;
  iVar8 = 8;
  puVar7 = DAT_3000e9dc;
  do {
    puVar6 = puVar7 + 1;
    uVar1 = *puVar7;
    puVar7 = puVar7 + 2;
    uVar2 = *puVar6;
    iVar8 = iVar8 + -1;
    puVar6 = (undefined2 *)((int)puVar5 + 2);
    *(undefined2 *)puVar5 = uVar1;
    puVar5 = puVar5 + 1;
    *puVar6 = uVar2;
  } while (iVar8 != 0);
  *(undefined2 *)puVar5 = *puVar7;
  iVar8 = 0;
  if (param_1 == (void *)0x0) {
    logMsg(DAT_3000e9e0,1,2,3,4,5,6);
    return 0xffffffff;
  }
  iVar3 = DR_NV_Read(DAT_3000e9e4,&local_38,0x22);
  if (iVar3 == 0) {
    if (local_38 == 0) {
      logMsg(DAT_3000e9ec,0,2,3,4,5,6);
      iVar8 = -1;
    }
    if (iVar8 == 0) {
      memcpy(param_1,local_34,0x1d);
      goto LAB_3000e7c0;
    }
  }
  else {
    logMsg(DAT_3000e9e8,DAT_3000e9e4,2,3,4,5,6);
  }
  __s = DAT_3000e9d8;
  sVar4 = strlen(DAT_3000e9d8);
  memcpy(param_1,__s,sVar4);
  sVar4 = strlen(__s);
  *(undefined1 *)(sVar4 + (int)param_1) = 0;
LAB_3000e7c0:
  logMsg(DAT_3000e9f0,param_1,2,3,4,5,6);
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_OM_SoftReboot @ 0x3000E7F8  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 6
 * Вызывает: PWRCTRL_WDT_SoftClkEn, WDT_Reboot, cacheFlush, intCpuLock, intDisable, taskCpuLock
 * Константы: 0x3000E7F8, 0x00100000
 * Данные: DAT_30007a54, DAT_30007a58, DAT_30007aa0, DAT_30007ac0, DAT_30007ac4, DAT_30007ad4
 * ---------------------------------------------------------------- */
void BSP_OM_SoftReboot(void)

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
 * BSP_OM_ShutDown @ 0x3000E7FC  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000E7FC
 * ---------------------------------------------------------------- */
void BSP_OM_ShutDown(void)

{
  return;
}

/* ----------------------------------------------------------------
 * BSP_OM_GetFPGAVer @ 0x3000E800  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000E800
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_GetFPGAVer(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_OM_ShellLock @ 0x3000E808  (примерный размер ~144 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: ioGlobalStdGet, shellFromNameGet, shellGenericInit, shellTerminate
 * Константы: 0x3000E808
 * Данные: DAT_3000e9f4
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_ShellLock(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar1 = ioGlobalStdGet(0);
    uVar2 = ioGlobalStdGet(1);
    uVar3 = ioGlobalStdGet(2);
    uVar1 = shellGenericInit(0,0,0,DAT_3000e9f4,1,0,uVar1,uVar2,uVar3);
  }
  else {
    uVar1 = shellFromNameGet(*DAT_3000e9f4);
    shellTerminate(uVar1);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_OM_GetFlashDistribution @ 0x3000E898  (примерный размер ~648 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x3000E898, 0x3000E970, 0xFFFFFFFF
 * Данные: DAT_3000e9f8, DAT_3000e9fc, DAT_3000ea00, DAT_3000ea04, DAT_3000f128
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_GetFlashDistribution(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((int)param_1 < 9) {
    if (param_2 == 0) {
      logMsg(DAT_3000e9fc,1,2,3,4,5,6);
    }
    else if (param_3 == 0) {
      logMsg(DAT_3000ea00,1,2,3,4,5,6);
    }
    else {
      if (param_1 < 9) {
                    /* WARNING: Could not recover jumptable at 0x3000e970. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (**(code **)(DAT_3000ea04 + param_1 * 4))();
        return uVar1;
      }
      logMsg(DAT_3000f128,param_1,2,3,4,5,6);
    }
  }
  else {
    logMsg(DAT_3000e9f8,param_1,2,3,4,5,6);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * BSP_OM_GetFlashSpec @ 0x3000EB20  (примерный размер ~248 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: logMsg, nand_get_spec
 * Константы: 0xFFFFFFFF, 0x3000EB20
 * Данные: DAT_3000f12c, DAT_3000f130, DAT_3000f134
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_GetFlashSpec(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (param_1 == (undefined4 *)0x0) {
    logMsg(DAT_3000f12c,1,2,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else if (param_2 == (undefined4 *)0x0) {
    logMsg(DAT_3000f130,1,2,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else if (param_3 == (undefined4 *)0x0) {
    logMsg(DAT_3000f134,1,2,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else {
    nand_get_spec(&local_20);
    *param_1 = local_18;
    *param_2 = local_20;
    *param_3 = local_1c;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_OM_NET @ 0x3000EC18  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000EC18
 * ---------------------------------------------------------------- */
void BSP_OM_NET(void)

{
  return;
}

/* ----------------------------------------------------------------
 * BSP_InitBootVersion @ 0x3000EC1C  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: memcpy
 * Вызывают: usrAppInit
 * Константы: 0x3000EC1C
 * Данные: DAT_3000f138, DAT_3000f13c
 * ---------------------------------------------------------------- */
void BSP_InitBootVersion(void)

{
  memcpy(DAT_3000f13c,DAT_3000f138,0x28);
  return;
}

/* ----------------------------------------------------------------
 * BSP_AtoX @ 0x3000EC38  (примерный размер ~224 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000EC38
 * ---------------------------------------------------------------- */
int BSP_AtoX(byte *param_1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    bVar1 = *param_1;
    if (bVar1 != 0x30) {
      if (bVar1 < 0x31) {
        if ((bVar1 != 9) && (bVar1 != 0x20)) goto LAB_3000ec8c;
      }
      else if ((bVar1 != 0x58) && (bVar1 != 0x78)) {
LAB_3000ec8c:
        while (((*param_1 - 0x30 < 10 || (*param_1 - 0x61 < 6)) || (*param_1 - 0x41 < 6))) {
          if (*param_1 - 0x30 < 10) {
            iVar2 = (uint)*param_1 + iVar2 * 0x10 + -0x30;
            param_1 = param_1 + 1;
          }
          else if (*param_1 - 0x61 < 6) {
            iVar2 = (uint)*param_1 + iVar2 * 0x10 + -0x57;
            param_1 = param_1 + 1;
          }
          else {
            iVar2 = (uint)*param_1 + iVar2 * 0x10 + -0x37;
            param_1 = param_1 + 1;
          }
        }
        return iVar2;
      }
    }
    param_1 = param_1 + 2;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_3000ed18 @ 0x3000ED18  (примерный размер ~652 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 5
 * Вызывает: atoi, memset, strchr, strncpy, strstr
 * Вызывают: BSP_InitBspVersion
 * Константы: 0x3000ED18
 * Данные: DAT_3000f140, DAT_3000f144, DAT_3000f148, DAT_3000f14c
 * ---------------------------------------------------------------- */
void FUN_3000ed18(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char *__s;
  char *pcVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  char acStack_14 [8];
  
  __s = DAT_3000f144;
  pcVar3 = acStack_14;
  iVar6 = 4;
  puVar5 = DAT_3000f140;
  do {
    puVar4 = puVar5 + 1;
    uVar1 = *puVar5;
    puVar5 = puVar5 + 2;
    uVar2 = *puVar4;
    iVar6 = iVar6 + -1;
    puVar4 = pcVar3 + 1;
    *pcVar3 = uVar1;
    pcVar3 = pcVar3 + 2;
    *puVar4 = uVar2;
  } while (iVar6 != 0);
  pcVar3 = DAT_3000f144;
  if (DAT_3000f144 != (char *)0x0) {
    do {
      pcVar3 = strchr(pcVar3,0x56);
      if (pcVar3 == (char *)0x0) goto LAB_3000edac;
      pcVar3 = pcVar3 + 1;
    } while (9 < (int)*pcVar3 - 0x30U);
    strncpy(acStack_14,pcVar3,3);
    iVar6 = atoi(acStack_14);
    *DAT_3000f148 = (short)iVar6;
LAB_3000edac:
    do {
      pcVar3 = strchr(__s,0x52);
      if (pcVar3 == (char *)0x0) goto LAB_3000ee28;
    } while ((9 < (int)pcVar3[-1] - 0x30U) || (9 < (int)pcVar3[1] - 0x30U));
    memset(acStack_14,0,8);
    strncpy(acStack_14,pcVar3 + 1,3);
    iVar6 = atoi(acStack_14);
    DAT_3000f148[1] = (short)iVar6;
LAB_3000ee28:
    do {
      pcVar3 = strchr(__s,0x43);
      if (pcVar3 == (char *)0x0) goto LAB_3000eea8;
    } while ((9 < (int)pcVar3[-1] - 0x30U) || (9 < (int)pcVar3[1] - 0x30U));
    memset(acStack_14,0,8);
    strncpy(acStack_14,pcVar3 + 1,3);
    iVar6 = atoi(acStack_14);
    DAT_3000f148[2] = (short)iVar6;
LAB_3000eea8:
    do {
      pcVar3 = strchr(__s,0x42);
      if (pcVar3 == (char *)0x0) goto LAB_3000ef24;
    } while ((9 < (int)pcVar3[-1] - 0x30U) || (9 < (int)pcVar3[1] - 0x30U));
    memset(acStack_14,0,8);
    strncpy(acStack_14,pcVar3 + 1,3);
    iVar6 = atoi(acStack_14);
    DAT_3000f148[3] = (short)iVar6;
LAB_3000ef24:
    do {
      pcVar3 = strstr(__s,DAT_3000f14c);
      if (pcVar3 == (char *)0x0) {
        return;
      }
    } while ((9 < (int)pcVar3[-1] - 0x30U) || (9 < (int)pcVar3[3] - 0x30U));
    memset(acStack_14,0,8);
    strncpy(acStack_14,pcVar3 + 3,3);
    iVar6 = atoi(acStack_14);
    DAT_3000f148[4] = (short)iVar6;
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_InitBspVersion @ 0x3000EFA4  (примерный размер ~80 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3000ed18, strncpy
 * Вызывают: usrAppInit
 * Константы: 0x3000EFA4
 * Данные: DAT_3000f148, DAT_3000f150, DAT_3000f154, DAT_3000f158, DAT_3000f15c
 * ---------------------------------------------------------------- */
undefined4 BSP_InitBspVersion(void)

{
  *(undefined2 *)(DAT_3000f148 + 10) = 0;
  strncpy(DAT_3000f150,DAT_3000f154,0xc);
  strncpy(DAT_3000f158,DAT_3000f15c,0xc);
  FUN_3000ed18();
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_OM_GetHwVersion @ 0x3000EFF4  (примерный размер ~108 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_GPIO_GetVersion, logMsg
 * Константы: 0x3000EFF4, 0xFFFFFFFF
 * Данные: DAT_3000f160, DAT_3000f164, DAT_3000f168
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_GetHwVersion(void)

{
  int iVar1;
  undefined4 uVar2;
  byte local_c;
  byte local_b [3];
  
  local_c = 0;
  local_b[0] = 0;
  iVar1 = BSP_GPIO_GetVersion(&local_c,local_b);
  if (iVar1 == 0) {
    logMsg(DAT_3000f168,DAT_3000f160 + (uint)local_c * 0x20,DAT_3000f164 + (uint)local_b[0] * 0x10);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_OM_GetBoardType @ 0x3000F060  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000F060
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_GetBoardType(void)

{
  return 1;
}

/* ----------------------------------------------------------------
 * BSP_GetHostCore @ 0x3000F068  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000F068
 * ---------------------------------------------------------------- */
undefined4 BSP_GetHostCore(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_OM_GetChipType @ 0x3000F070  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000F070
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_GetChipType(void)

{
  return 3;
}

/* ----------------------------------------------------------------
 * BSP_OM_GetTcmAdr @ 0x3000F078  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000F078
 * Данные: DAT_3000f16c
 * ---------------------------------------------------------------- */
undefined4 BSP_OM_GetTcmAdr(void)

{
  return DAT_3000f16c;
}

/* ----------------------------------------------------------------
 * BSP_OM_PrintShareMemInfo @ 0x3000F080  (примерный размер ~300 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x3000F080
 * Данные: DAT_3000f170, DAT_3000f174, DAT_3000f178, DAT_3000f17c, DAT_3000f180, DAT_3000f184, DAT_3000f188, DAT_3000f18c
 * ---------------------------------------------------------------- */
void BSP_OM_PrintShareMemInfo(void)

{
  printf(DAT_3000f170);
  printf(DAT_3000f174,DAT_3000f178,DAT_3000f17c,0x60);
  printf(DAT_3000f174,DAT_3000f180,DAT_3000f184,0x20);
  printf(DAT_3000f174,DAT_3000f188,DAT_3000f18c,0x80);
  printf(DAT_3000f174,DAT_3000f190,DAT_3000f194,0x8000);
  printf(DAT_3000f174,DAT_3000f198,DAT_3000f19c,0x20);
  printf(DAT_3000f174,DAT_3000f1a0,DAT_3000f1a4,DAT_3000f1a8);
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_NAND_SoftClkDis @ 0x3000F1AC  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 0
 * Вызывают: BSP_NANDF_DrxBakReg, BSP_NANDF_DrxRestoreReg
 * Константы: 0x3000F1AC
 * ---------------------------------------------------------------- */
void PWRCTRL_NAND_SoftClkDis(void)

{
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_NAND_SoftClkEn @ 0x3000F1B0  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 0
 * Вызывают: BSP_NANDF_DrxBakReg, BSP_NANDF_DrxRestoreReg
 * Константы: 0x3000F1B0
 * ---------------------------------------------------------------- */
void PWRCTRL_NAND_SoftClkEn(void)

{
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_NAND_LowPowerEnter @ 0x3000F1B4  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: nand_mutex_out
 * Константы: 0x3000F1B4
 * ---------------------------------------------------------------- */
undefined4 PWRCTRL_NAND_LowPowerEnter(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * PWRCTRL_NAND_LowPowerExit @ 0x3000F1BC  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: nand_mutex_in
 * Константы: 0x3000F1BC
 * ---------------------------------------------------------------- */
undefined4 PWRCTRL_NAND_LowPowerExit(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_NANDF_Read @ 0x30017498  (примерный размер ~48 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: nand_read
 * Константы: 0x30017498
 * ---------------------------------------------------------------- */
void BSP_NANDF_Read(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_14 [4];
  
  nand_read(param_2,param_1,param_3,auStack_14);
  return;
}

/* ----------------------------------------------------------------
 * BSP_NANDF_Erase @ 0x300174C8  (примерный размер ~88 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: nand_erase, nand_isbad
 * Константы: 0x300174C8
 * ---------------------------------------------------------------- */
int BSP_NANDF_Erase(undefined4 param_1)

{
  int iVar1;
  int local_10;
  
  local_10 = 0;
  iVar1 = nand_isbad(param_1,&local_10);
  if (iVar1 == 0) {
    if (local_10 == 0) {
      iVar1 = nand_erase(param_1);
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * BSP_NANDF_Erase_Force @ 0x30017520  (примерный размер ~268 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: __udiv32, logMsg, nand_erase, nand_get_spec
 * Константы: 0x30017520
 * Данные: DAT_30017ccc, DAT_30017cd0, DAT_30017cd4, DAT_30017cd8
 * ---------------------------------------------------------------- */
uint BSP_NANDF_Erase_Force(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_28 = *DAT_30017ccc;
  local_24 = DAT_30017ccc[1];
  local_20 = DAT_30017ccc[2];
  local_1c = DAT_30017ccc[3];
  uVar1 = nand_get_spec(&local_28);
  if (uVar1 == 0) {
    uVar2 = __udiv32(local_20,local_28);
    if ((param_1 < uVar2) && (uVar2 = __udiv32(local_20,local_28), param_2 < uVar2)) {
      for (; param_1 <= param_2; param_1 = param_1 + 1) {
        uVar2 = nand_erase(param_1);
        if (uVar2 != 0) {
          logMsg(DAT_30017cd8,param_1,uVar1,0x43);
        }
        uVar1 = uVar1 | uVar2;
      }
    }
    else {
      logMsg(DAT_30017cd4,param_1,param_2,0x38);
      uVar1 = 1;
    }
  }
  else {
    logMsg(DAT_30017cd0,uVar1,0x2f);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_NANDF_Scan @ 0x3001762C  (примерный размер ~196 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: __udiv32, nand_get_spec, nand_isbad, printf
 * Константы: 0x3001762C
 * Данные: DAT_30017cdc, DAT_30017ce0, DAT_30017ce4, DAT_30017ce8
 * ---------------------------------------------------------------- */
uint BSP_NANDF_Scan(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int local_24;
  undefined4 local_20 [2];
  undefined4 local_18;
  
  uVar3 = 0;
  local_24 = 0;
  iVar1 = nand_get_spec(local_20);
  if (iVar1 == 0) {
    for (uVar4 = 0; uVar2 = __udiv32(local_18,local_20[0]), uVar4 < uVar2; uVar4 = uVar4 + 1) {
      uVar2 = nand_isbad(uVar4,&local_24);
      if (uVar2 == 0) {
        if (local_24 == 1) {
          printf(DAT_30017ce0,uVar4);
          uVar3 = uVar3 | 1;
        }
      }
      else {
        printf(DAT_30017cdc,uVar4);
        uVar3 = uVar3 | uVar2;
      }
    }
    if (uVar3 == 0) {
      printf(DAT_30017ce4);
    }
  }
  else {
    printf(DAT_30017ce8);
    uVar3 = 1;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * BSP_NANDF_Write @ 0x300177B4  (примерный размер ~48 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: nand_write
 * Константы: 0x300177B4
 * ---------------------------------------------------------------- */
void BSP_NANDF_Write(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_14 [4];
  
  nand_write(param_1,param_2,param_3,auStack_14);
  return;
}

/* ----------------------------------------------------------------
 * BSP_NANDF_DrxBakReg @ 0x30017C38  (примерный размер ~76 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: PWRCTRL_NAND_SoftClkDis, PWRCTRL_NAND_SoftClkEn, memcpy
 * Константы: 0x30017C38
 * Данные: DAT_30017d38, DAT_30017d3c, DAT_30017d40
 * ---------------------------------------------------------------- */
undefined4 BSP_NANDF_DrxBakReg(void)

{
  void *__dest;
  uint uVar1;
  
  __dest = DAT_30017d38;
  PWRCTRL_NAND_SoftClkEn();
  for (uVar1 = 0; uVar1 < 0xc; uVar1 = uVar1 + 1) {
    memcpy(__dest,(void *)(*(int *)(DAT_30017d3c + uVar1 * 4) - DAT_30017d40),4);
    __dest = (void *)((int)__dest + 4);
  }
  PWRCTRL_NAND_SoftClkDis();
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_NANDF_DrxRestoreReg @ 0x30017C84  (примерный размер ~192 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: PWRCTRL_NAND_SoftClkDis, PWRCTRL_NAND_SoftClkEn, memcpy
 * Константы: 0x30017C84
 * Данные: DAT_30017d38, DAT_30017d3c, DAT_30017d40
 * ---------------------------------------------------------------- */
void BSP_NANDF_DrxRestoreReg(void)

{
  void *__src;
  uint uVar1;
  
  __src = DAT_30017d38;
  PWRCTRL_NAND_SoftClkEn();
  for (uVar1 = 0; uVar1 < 0xc; uVar1 = uVar1 + 1) {
    memcpy((void *)(*(int *)(DAT_30017d3c + uVar1 * 4) - DAT_30017d40),__src,4);
    __src = (void *)((int)__src + 4);
  }
  PWRCTRL_NAND_SoftClkDis();
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_SPI_SoftClkStatus @ 0x3002D774  (примерный размер ~80 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x3002D774
 * Данные: DAT_3002e714, DAT_3002e718
 * ---------------------------------------------------------------- */
void PWRCTRL_SPI_SoftClkStatus(void)

{
  logMsg(DAT_3002e718,*DAT_3002e714 >> 0x1c & 1,0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_SPI_SoftClkDis @ 0x3002D7C4  (примерный размер ~16 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 0
 * Вызывают: BSP_SPI_Read, BSP_SPI_SetAttr, BSP_SPI_Write, SPI_Init
 * Константы: 0x3002D7C4, 0x10000000
 * Данные: DAT_3002e71c
 * ---------------------------------------------------------------- */
void PWRCTRL_SPI_SoftClkDis(void)

{
  *DAT_3002e71c = 0x10000000;
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_SPI_SoftClkEn @ 0x3002D7D4  (примерный размер ~16 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 0
 * Вызывают: BSP_SPI_Read, BSP_SPI_SetAttr, BSP_SPI_Write, SPI_Init
 * Константы: 0x3002D7D4, 0x10000000
 * Данные: DAT_3002e720
 * ---------------------------------------------------------------- */
void PWRCTRL_SPI_SoftClkEn(void)

{
  *DAT_3002e720 = 0x10000000;
  return;
}

/* ----------------------------------------------------------------
 * SPI_Init @ 0x3002D7E4  (примерный размер ~448 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 5
 * Вызывает: BSP_TRACE, PWRCTRL_SPI_SoftClkDis, PWRCTRL_SPI_SoftClkEn, memset, semMCreate
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x3002D7E4, 0xFFFFFFFF
 * Данные: DAT_3002e724, DAT_3002e728, DAT_3002e72c, DAT_3002e730, DAT_3002e734, DAT_3002e738, DAT_3002e73c, DAT_3002e740
 * ---------------------------------------------------------------- */
undefined4 SPI_Init(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (*DAT_3002e724 != 1) {
    memset(DAT_3002e728,0,0xd8);
    *(undefined4 *)((int)DAT_3002e728 + 0x58) = DAT_3002e72c;
    *(undefined4 *)((int)DAT_3002e728 + 0xc4) = DAT_3002e730;
    *DAT_3002e734 = *DAT_3002e734 | 0x800;
    *DAT_3002e738 = *DAT_3002e738 | 0xc000;
    PWRCTRL_SPI_SoftClkEn();
    for (uVar2 = 0; uVar2 < 2; uVar2 = uVar2 + 1) {
      *(undefined4 *)(uVar2 * 0x6c + DAT_3002e73c) = 0xffffffff;
      uVar1 = semMCreate(0);
      *(undefined4 *)(DAT_3002e740 + uVar2 * 0x6c) = uVar1;
      if (*(int *)(DAT_3002e740 + uVar2 * 0x6c) == 0) {
        BSP_TRACE(4,7,DAT_3002e800,0,0,0,0,0,0);
        PWRCTRL_SPI_SoftClkDis();
        return DAT_3002e804;
      }
      **(undefined4 **)(DAT_3002e808 + uVar2 * 0x6c) = 0;
      *(undefined4 *)(*(int *)(DAT_3002e808 + uVar2 * 0x6c) + 4) = 0;
      *(undefined4 *)(*(int *)(DAT_3002e808 + uVar2 * 0x6c) + 8) = 0;
      *(undefined4 *)(*(int *)(DAT_3002e808 + uVar2 * 0x6c) + 0xc) = 0;
      *(undefined4 *)(*(int *)(DAT_3002e808 + uVar2 * 0x6c) + 0x10) = 0;
      *(undefined4 *)(*(int *)(DAT_3002e808 + uVar2 * 0x6c) + 0x14) = 0;
    }
    PWRCTRL_SPI_SoftClkDis();
    *DAT_3002e724 = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * SPI_Lock @ 0x3002D9A4  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 1
 * Вызывает: intCpuLock
 * Вызывают: BSP_SPI_GetAttr, BSP_SPI_Read, BSP_SPI_SetAttr, BSP_SPI_Write
 * Константы: 0x3002D9A4
 * Данные: DAT_3002e8e4
 * ---------------------------------------------------------------- */
undefined4 SPI_Lock(void)

{
  undefined4 uVar1;
  
  uVar1 = intCpuLock();
  *DAT_3002e8e4 = uVar1;
  return 0;
}

/* ----------------------------------------------------------------
 * SPI_UnLock @ 0x3002D9BC  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 1
 * Вызывает: intCpuUnlock
 * Вызывают: BSP_SPI_GetAttr, BSP_SPI_Read, BSP_SPI_SetAttr, BSP_SPI_Write
 * Константы: 0x3002D9BC
 * Данные: DAT_3002e8e4
 * ---------------------------------------------------------------- */
undefined4 SPI_UnLock(void)

{
  intCpuUnlock(*DAT_3002e8e4);
  return 0;
}

/* ----------------------------------------------------------------
 * SPI_POLL_Send @ 0x3002D9D4  (примерный размер ~304 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Вызывают: BSP_SPI_Read, BSP_SPI_Write
 * Константы: 0x3002D9D4
 * Данные: DAT_3002e808, DAT_3002e8e8, DAT_3002e8ec, DAT_3002e994, DAT_3002e998, DAT_3002e99c
 * ---------------------------------------------------------------- */
undefined4 SPI_POLL_Send(int *param_1,ushort *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1[1] * 0x14 + DAT_3002e8e8 + *param_1 * 0x6c);
  iVar2 = *(int *)(DAT_3002e808 + *param_1 * 0x6c);
  if (((param_2 == (ushort *)0x0) || (param_3 == 0)) || (8 < param_3)) {
    BSP_TRACE(4,7,DAT_3002e8ec,0,0,0,0,0,0);
    uVar1 = DAT_3002e994;
  }
  else if ((iVar3 == 7) || (iVar3 == 0xf)) {
    for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + 1) {
      *(uint *)(iVar2 + 0x60) = (uint)*param_2;
      param_2 = param_2 + 1;
    }
    uVar1 = 0;
  }
  else {
    BSP_TRACE(4,7,DAT_3002e998,0,0,0,0,0,0);
    uVar1 = DAT_3002e99c;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * SPI_POLL_Receive @ 0x3002DB04  (примерный размер ~436 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Вызывают: BSP_SPI_Read
 * Константы: 0x3002DB04
 * Данные: DAT_3002e808, DAT_3002e8e8, DAT_3002e994, DAT_3002e99c, DAT_3002eab4, DAT_3002eab8, DAT_3002eabc, DAT_3002ebcc
 * ---------------------------------------------------------------- */
undefined4 SPI_POLL_Receive(int *param_1,ushort *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  iVar2 = *(int *)(param_1[1] * 0x14 + DAT_3002e8e8 + *param_1 * 0x6c);
  iVar4 = *(int *)(DAT_3002e808 + *param_1 * 0x6c);
  if ((param_2 == (ushort *)0x0) || (param_3 == 0)) {
    BSP_TRACE(4,7,DAT_3002eab4,0,0,0,0,0,0);
    uVar1 = DAT_3002e994;
  }
  else {
    if (iVar2 == 7) {
      while ((*(uint *)(iVar4 + 0x28) & 8) != 0) {
        *(char *)param_2 = (char)*(undefined4 *)(iVar4 + 0x60);
        uVar3 = uVar3 + 1;
        param_2 = (ushort *)((int)param_2 + 1);
      }
    }
    else {
      if (iVar2 != 0xf) {
        BSP_TRACE(4,7,DAT_3002eabc,0,0,0,0,0,0);
        return DAT_3002e99c;
      }
      while ((*(uint *)(iVar4 + 0x28) & 8) != 0) {
        *param_2 = (ushort)*(undefined4 *)(iVar4 + 0x60) & (ushort)DAT_3002eab8;
        uVar3 = uVar3 + 1;
        param_2 = param_2 + 1;
      }
    }
    if (param_3 < uVar3) {
      BSP_TRACE(4,7,DAT_3002ebcc,0,0,0,0,0,0);
      uVar1 = DAT_3002ebd0;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_SPI_SetAttr @ 0x3002DCB8  (примерный размер ~536 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 6
 * Вызывает: BSP_TRACE, PWRCTRL_SPI_SoftClkDis, PWRCTRL_SPI_SoftClkEn, SPI_Lock, SPI_UnLock, memcpy
 * Вызывают: HI6451_init
 * Константы: 0x3002DCB8
 * Данные: DAT_3002e724, DAT_3002e728, DAT_3002e73c, DAT_3002e808, DAT_3002e994, DAT_3002ebd4, DAT_3002ecc0, DAT_3002ecc4
 * ---------------------------------------------------------------- */
undefined4 BSP_SPI_SetAttr(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  
  iVar4 = *param_1;
  iVar3 = param_1[1];
  if ((((((iVar4 < 2) && (-1 < iVar4)) && (iVar3 < 4)) && ((-1 < iVar3 && (*param_2 < 0x10)))) &&
      ((-1 < *param_2 && ((param_2[1] - 3U < 0xd && (param_2[2] < 3)))))) && (-1 < param_2[2])) {
    if (*DAT_3002e724 == 0) {
      BSP_TRACE(4,7,DAT_3002ecc0,0,0,0,0,0,0);
      uVar2 = DAT_3002ecc4;
    }
    else {
      iVar1 = SPI_Lock(iVar4);
      if (iVar1 == 0) {
        puVar5 = *(uint **)(DAT_3002e808 + iVar4 * 0x6c);
        memcpy((void *)(iVar3 * 0x14 + iVar4 * 0x6c + DAT_3002e728),param_2,0x14);
        *(int *)(DAT_3002e73c + iVar4 * 0x6c) = iVar3;
        *(undefined4 *)(iVar4 * 0x6c + DAT_3002ecd0 + iVar3 * 4) = 1;
        uVar6 = param_2[1];
        iVar3 = param_2[2];
        iVar1 = *param_2;
        PWRCTRL_SPI_SoftClkEn();
        puVar5[2] = 0;
        *puVar5 = uVar6 | iVar3 << 4 | iVar1 << 0xc;
        puVar5[5] = (uint)*(ushort *)(param_2 + 4);
        PWRCTRL_SPI_SoftClkDis();
        iVar3 = SPI_UnLock(iVar4);
        uVar2 = DAT_3002eda0;
        if (iVar3 == 0) {
          uVar2 = 0;
        }
      }
      else {
        BSP_TRACE(4,7,DAT_3002ecc8,0,0,0,0,0,0);
        uVar2 = DAT_3002eccc;
      }
    }
  }
  else {
    BSP_TRACE(4,7,DAT_3002ebd4,0,0,0,0,0,0);
    uVar2 = DAT_3002e994;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * SPI_SetSpiOwner @ 0x3002DED0  (примерный размер ~392 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 2
 * Вызывает: BSP_TRACE, memcmp
 * Вызывают: BSP_SPI_Read, BSP_SPI_Write
 * Константы: 0x3002DED0
 * Данные: DAT_3002e728, DAT_3002e73c, DAT_3002e808, DAT_3002e8e8, DAT_3002ecd0, DAT_3002eea4, DAT_3002eea8, DAT_3002eeac
 * ---------------------------------------------------------------- */
undefined4 SPI_SetSpiOwner(int *param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar4 = *param_1;
  iVar3 = param_1[1];
  puVar2 = *(uint **)(DAT_3002e808 + iVar4 * 0x6c);
  if (*(int *)(DAT_3002e73c + iVar4 * 0x6c) != iVar3) {
    if (*(int *)(DAT_3002ecd0 + iVar3 * 4 + iVar4 * 0x6c) == 0) {
      BSP_TRACE(4,7,DAT_3002eea4,0,0,0,0,0,0);
      return DAT_3002eea8;
    }
    iVar1 = memcmp((void *)(iVar3 * 0x14 + iVar4 * 0x6c + DAT_3002e728),
                   (void *)(*(int *)(DAT_3002e73c + iVar4 * 0x6c) * 0x14 +
                           iVar4 * 0x6c + DAT_3002e728),0x14);
    if (iVar1 != 0) {
      iVar5 = *(int *)(iVar3 * 0x14 + DAT_3002eeac + iVar4 * 0x6c);
      iVar1 = *(int *)(iVar4 * 0x6c + DAT_3002e728 + iVar3 * 0x14);
      uVar6 = *(uint *)(iVar3 * 0x14 + DAT_3002e8e8 + iVar4 * 0x6c);
      puVar2[2] = 0;
      *puVar2 = iVar5 << 4 | iVar1 << 0xc | uVar6;
      puVar2[5] = (uint)*(ushort *)(iVar3 * 0x14 + DAT_3002eeb0 + iVar4 * 0x6c);
    }
    *(int *)(DAT_3002e73c + iVar4 * 0x6c) = iVar3;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_SPI_Write @ 0x3002E058  (примерный размер ~1488 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 7
 * Вызывает: BSP_TRACE, PWRCTRL_SPI_SoftClkDis, PWRCTRL_SPI_SoftClkEn, SPI_Lock, SPI_POLL_Send, SPI_SetSpiOwner, SPI_UnLock
 * Вызывают: HI6451_reg_write
 * Константы: 0x3002E058
 * Данные: DAT_3002e724, DAT_3002e808, DAT_3002e8e8, DAT_3002e994, DAT_3002ecc4, DAT_3002ecc8, DAT_3002eccc, DAT_3002eda0
 * ---------------------------------------------------------------- */
int BSP_SPI_Write(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  undefined1 auStack_38 [4];
  undefined2 local_34;
  undefined2 local_32;
  undefined4 local_30;
  
  uVar4 = 0;
  if ((((((param_2 == 0) || (param_3 == 0)) || (param_1 == (int *)0x0)) ||
       ((1 < *param_1 || (*param_1 < 0)))) ||
      ((3 < param_1[1] || ((param_1[1] < 0 || (1 < param_1[2])))))) || (param_1[2] < 0)) {
    BSP_TRACE(4,7,DAT_3002f058,0,0,0,0,0,0);
    iVar1 = DAT_3002e994;
  }
  else {
    iVar3 = *param_1;
    uVar2 = param_1[1];
    iVar6 = *(int *)(uVar2 * 0x14 + DAT_3002f05c + iVar3 * 0x6c);
    uVar7 = *(uint *)(uVar2 * 0x14 + DAT_3002e8e8 + iVar3 * 0x6c);
    puVar5 = *(uint **)(DAT_3002e808 + iVar3 * 0x6c);
    if (*DAT_3002e724 == 0) {
      BSP_TRACE(4,7,DAT_3002f060,0,0,0,0,0,0);
      iVar1 = DAT_3002ecc4;
    }
    else {
      iVar1 = SPI_Lock(iVar3);
      if (iVar1 == 0) {
        PWRCTRL_SPI_SoftClkEn();
        iVar1 = SPI_SetSpiOwner(param_1);
        if (iVar1 == 0) {
          puVar5[4] = 0;
          puVar5[2] = 0;
          iVar1 = *(int *)(uVar2 * 0x14 + DAT_3002eeac + iVar3 * 0x6c);
          if (iVar1 == 0) {
            *puVar5 = uVar7 | *puVar5 & DAT_3002f1e8 | iVar6 << 7 | 0x140;
          }
          else {
            if (iVar1 != 2) {
              iVar1 = SPI_UnLock(iVar3);
              if (iVar1 != 0) {
                PWRCTRL_SPI_SoftClkDis();
                return DAT_3002eda0;
              }
              BSP_TRACE(4,7,DAT_3002f1ec,0,0,0,0,0,0);
              return DAT_3002f1f0;
            }
            puVar5[3] = puVar5[3] | 2;
          }
          puVar5[2] = 1;
          if (param_1[2] == 0) {
            iVar1 = SPI_POLL_Send(param_1,param_2,param_3);
            if (iVar1 == 0) {
              puVar5[4] = 1 << (uVar2 & 0xff);
              for (; ((puVar5[10] & 4) == 0 && (uVar4 < DAT_3002f334)); uVar4 = uVar4 + 1) {
              }
              if (uVar4 == DAT_3002f334) {
                if (*DAT_3002f338 != 0) {
                  local_34 = (undefined2)*DAT_3002f33c;
                  local_32 = (undefined2)*DAT_3002f340;
                  local_30 = 0;
                  (*(code *)*DAT_3002f338)(DAT_3002f344,0xc,auStack_38);
                }
                iVar1 = SPI_UnLock(iVar3);
                if (iVar1 == 0) {
                  BSP_TRACE(4,7,DAT_3002f348,0,0,0,0,0,0);
                  iVar1 = DAT_3002f34c;
                }
                else {
                  PWRCTRL_SPI_SoftClkDis();
                  iVar1 = DAT_3002eda0;
                }
              }
              else {
                for (uVar4 = 0; ((puVar5[10] & 1) != 0 && (uVar4 < DAT_3002f334)); uVar4 = uVar4 + 1
                    ) {
                }
                PWRCTRL_SPI_SoftClkDis();
                if (uVar4 == DAT_3002f334) {
                  if (*DAT_3002f338 != 0) {
                    local_34 = (undefined2)*DAT_3002f33c;
                    local_32 = (undefined2)*DAT_3002f340;
                    local_30 = 0;
                    (*(code *)*DAT_3002f338)(DAT_3002f344,0xc,auStack_38);
                  }
                  iVar3 = SPI_UnLock(iVar3);
                  iVar1 = DAT_3002eda0;
                  if (iVar3 == 0) {
                    BSP_TRACE(4,7,DAT_3002f348,0,0,0,0,0,0);
                    iVar1 = DAT_3002f34c;
                  }
                }
                else {
                  iVar3 = SPI_UnLock(iVar3);
                  iVar1 = DAT_3002eda0;
                  if (iVar3 == 0) {
                    iVar1 = 0;
                  }
                }
              }
            }
            else {
              iVar3 = SPI_UnLock(iVar3);
              if (iVar3 == 0) {
                BSP_TRACE(4,7,DAT_3002f1f4,0,0,0,0,0,0);
              }
              else {
                PWRCTRL_SPI_SoftClkDis();
                iVar1 = DAT_3002eda0;
              }
            }
          }
          else {
            iVar1 = SPI_UnLock(iVar3);
            if (iVar1 == 0) {
              BSP_TRACE(4,7,DAT_3002f32c,0,0,0,0,0,0);
              iVar1 = DAT_3002f330;
            }
            else {
              PWRCTRL_SPI_SoftClkDis();
              iVar1 = DAT_3002eda0;
            }
          }
        }
        else {
          iVar3 = SPI_UnLock(iVar3);
          if (iVar3 != 0) {
            PWRCTRL_SPI_SoftClkDis();
            iVar1 = DAT_3002eda0;
          }
        }
      }
      else {
        BSP_TRACE(4,7,DAT_3002ecc8,0,0,0,0,0,0);
        iVar1 = DAT_3002eccc;
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * BSP_SPI_Read @ 0x3002E628  (примерный размер ~2060 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 8
 * Вызывает: BSP_TRACE, PWRCTRL_SPI_SoftClkDis, PWRCTRL_SPI_SoftClkEn, SPI_Lock, SPI_POLL_Receive, SPI_POLL_Send, SPI_SetSpiOwner, SPI_UnLock
 * Вызывают: HI6451_reg_read
 * Константы: 0x3002E628, 0xFFFFFFFD
 * Данные: DAT_3002e808, DAT_3002e8e8, DAT_3002e994, DAT_3002ecc4, DAT_3002eccc, DAT_3002eda0, DAT_3002eeac, DAT_3002f05c
 * ---------------------------------------------------------------- */
int BSP_SPI_Read(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  undefined1 auStack_34 [4];
  undefined2 local_30;
  undefined2 local_2e;
  undefined4 local_2c;
  
  uVar5 = 0;
  if ((((((param_2 == 0) || (param_3 == 0)) || (3 < param_1[1])) ||
       ((param_1[1] < 0 || (1 < *param_1)))) ||
      ((*param_1 < 0 || ((1 < param_1[2] || (param_1[2] < 0)))))) ||
     ((param_1[3] == 0 || (param_1[4] == 0)))) {
    BSP_TRACE(4,7,DAT_3002f570,0,0,0,0,0,0);
    iVar2 = DAT_3002e994;
  }
  else {
    iVar4 = *param_1;
    uVar3 = param_1[1];
    iVar7 = *(int *)(uVar3 * 0x14 + DAT_3002f05c + iVar4 * 0x6c);
    uVar8 = *(uint *)(uVar3 * 0x14 + DAT_3002e8e8 + iVar4 * 0x6c);
    puVar6 = *(uint **)(DAT_3002e808 + iVar4 * 0x6c);
    if (*DAT_3002f574 == 0) {
      BSP_TRACE(4,7,DAT_3002f578,0,0,0,0,0,0);
      iVar2 = DAT_3002ecc4;
    }
    else {
      iVar1 = SPI_Lock(iVar4);
      iVar2 = DAT_3002eccc;
      if (iVar1 == 0) {
        PWRCTRL_SPI_SoftClkEn();
        iVar2 = SPI_SetSpiOwner(param_1);
        if (iVar2 == 0) {
          puVar6[4] = 0;
          puVar6[2] = 0;
          puVar6[1] = param_3 - 1;
          iVar2 = *(int *)(uVar3 * 0x14 + DAT_3002eeac + iVar4 * 0x6c);
          if (iVar2 == 0) {
            *puVar6 = uVar8 | *puVar6 & DAT_3002f1e8 | iVar7 << 7 | 0x40;
            puVar6[2] = 1;
            if (param_1[2] != 0) {
              iVar2 = SPI_UnLock(iVar4);
              if (iVar2 != 0) {
                PWRCTRL_SPI_SoftClkDis();
                return DAT_3002eda0;
              }
              BSP_TRACE(4,7,DAT_3002f580,0,0,0,0,0,0);
              return DAT_3002f330;
            }
            iVar2 = SPI_POLL_Send(param_1,param_1[3],param_1[4]);
            if (iVar2 != 0) {
              iVar4 = SPI_UnLock(iVar4);
              if (iVar4 != 0) {
                PWRCTRL_SPI_SoftClkDis();
                return DAT_3002eda0;
              }
              BSP_TRACE(4,7,DAT_3002f57c,0,0,0,0,0,0);
              return iVar2;
            }
          }
          else {
            if (iVar2 != 2) {
              iVar2 = SPI_UnLock(iVar4);
              if (iVar2 != 0) {
                PWRCTRL_SPI_SoftClkDis();
                return DAT_3002eda0;
              }
              BSP_TRACE(4,7,DAT_3002f584,0,0,0,0,0,0);
              return DAT_3002f1f0;
            }
            puVar6[3] = puVar6[3] & 0xfffffffd;
            puVar6[2] = 1;
            if (param_1[2] != 0) {
              iVar2 = SPI_UnLock(iVar4);
              if (iVar2 != 0) {
                PWRCTRL_SPI_SoftClkDis();
                return DAT_3002eda0;
              }
              BSP_TRACE(4,7,DAT_3002f580,0,0,0,0,0,0);
              return DAT_3002f330;
            }
            iVar2 = SPI_POLL_Send(param_1,param_1[3],param_1[4]);
            if (iVar2 != 0) {
              iVar4 = SPI_UnLock(iVar4);
              if (iVar4 != 0) {
                PWRCTRL_SPI_SoftClkDis();
                return DAT_3002eda0;
              }
              BSP_TRACE(4,7,DAT_3002f57c,0,0,0,0,0,0);
              return iVar2;
            }
          }
          puVar6[4] = 1 << (uVar3 & 0xff);
          for (; ((puVar6[10] & 4) == 0 && (uVar5 < DAT_3002f334)); uVar5 = uVar5 + 1) {
          }
          if (uVar5 == DAT_3002f334) {
            if (*DAT_3002f338 != 0) {
              local_30 = (undefined2)*DAT_3002f33c;
              local_2e = (undefined2)*DAT_3002f340;
              local_2c = 1;
              (*(code *)*DAT_3002f338)(DAT_3002f344,0xc,auStack_34);
            }
            iVar2 = SPI_UnLock(iVar4);
            if (iVar2 == 0) {
              BSP_TRACE(4,7,DAT_3002f348,0,0,0,0,0,0);
              iVar2 = DAT_3002f34c;
            }
            else {
              PWRCTRL_SPI_SoftClkDis();
              iVar2 = DAT_3002eda0;
            }
          }
          else {
            for (uVar5 = 0; ((puVar6[10] & 1) != 0 && (uVar5 < DAT_3002f334)); uVar5 = uVar5 + 1) {
            }
            if (uVar5 == DAT_3002f334) {
              if (*DAT_3002f338 != 0) {
                local_30 = (undefined2)*DAT_3002f33c;
                local_2e = (undefined2)*DAT_3002f340;
                local_2c = 1;
                (*(code *)*DAT_3002f338)(DAT_3002f344,0xc,auStack_34);
              }
              iVar2 = SPI_UnLock(iVar4);
              if (iVar2 == 0) {
                BSP_TRACE(4,7,DAT_3002f588,0,0,0,0,0,0);
                iVar2 = DAT_3002f34c;
              }
              else {
                PWRCTRL_SPI_SoftClkDis();
                iVar2 = DAT_3002eda0;
              }
            }
            else if (param_1[2] == 0) {
              iVar2 = SPI_POLL_Receive(param_1,param_2,param_3);
              if (iVar2 == 0) {
                PWRCTRL_SPI_SoftClkDis();
                iVar4 = SPI_UnLock(iVar4);
                iVar2 = DAT_3002f590;
                if (iVar4 == 0) {
                  iVar2 = 0;
                }
              }
              else {
                iVar4 = SPI_UnLock(iVar4);
                if (iVar4 == 0) {
                  BSP_TRACE(4,7,DAT_3002f58c,0,0,0,0,0,0);
                }
                else {
                  PWRCTRL_SPI_SoftClkDis();
                  iVar2 = DAT_3002eda0;
                }
              }
            }
            else {
              iVar2 = SPI_UnLock(iVar4);
              if (iVar2 == 0) {
                BSP_TRACE(4,7,DAT_3002f580,0,0,0,0,0,0);
                iVar2 = DAT_3002f330;
              }
              else {
                PWRCTRL_SPI_SoftClkDis();
                iVar2 = DAT_3002f590;
              }
            }
          }
        }
        else {
          iVar4 = SPI_UnLock(iVar4);
          if (iVar4 != 0) {
            PWRCTRL_SPI_SoftClkDis();
            iVar2 = DAT_3002eda0;
          }
        }
      }
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * BSP_SPI_GetAttr @ 0x3002EE34  (примерный размер ~412 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: BSP_TRACE, SPI_Lock, SPI_UnLock, memset
 * Константы: 0x3002EE34
 * Данные: DAT_3002f570, DAT_3002f574, DAT_3002f578, DAT_3002f590, DAT_3002f594, DAT_3002f598, DAT_3002f59c, DAT_3002f5a0
 * ---------------------------------------------------------------- */
undefined4 BSP_SPI_GetAttr(int param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *puVar4;
  uint uVar5;
  
  puVar4 = *(ushort **)(DAT_3002f594 + param_1 * 0x6c);
  if (((param_1 < 0) || (1 < param_1)) || (param_2 == (int *)0x0)) {
    BSP_TRACE(4,7,DAT_3002f570,0,0,0,0,0,0);
    uVar3 = DAT_3002f598;
  }
  else if (*DAT_3002f574 == 0) {
    BSP_TRACE(4,7,DAT_3002f578,0,0,0,0,0,0);
    uVar3 = DAT_3002f59c;
  }
  else {
    iVar2 = SPI_Lock(param_1);
    if (iVar2 == 0) {
      memset(param_2,0,0x14);
      uVar5 = (uint)*puVar4;
      uVar1 = puVar4[10];
      param_2[1] = uVar5 & 0xf;
      *param_2 = (int)uVar5 >> 0xc;
      param_2[2] = (int)uVar5 >> 4 & 3;
      *(ushort *)(param_2 + 4) = uVar1;
      iVar2 = SPI_UnLock(param_1);
      uVar3 = DAT_3002f590;
      if (iVar2 == 0) {
        uVar3 = 0;
      }
    }
    else {
      BSP_TRACE(4,7,DAT_3002f5a0,0,0,0,0,0,0);
      uVar3 = DAT_3002f5a4;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * BSP_ReportTest @ 0x3002EFD0  (примерный размер ~156 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x3002EFD0
 * Данные: DAT_3002f338, DAT_3002f33c, DAT_3002f340, DAT_3002f344, DAT_3002f5a8
 * ---------------------------------------------------------------- */
void BSP_ReportTest(void)

{
  undefined1 auStack_10 [4];
  undefined2 local_c;
  undefined2 local_a;
  undefined4 local_8;
  
  if (*DAT_3002f338 != 0) {
    local_c = (undefined2)*DAT_3002f33c;
    local_a = (undefined2)*DAT_3002f340;
    local_8 = 1;
    logMsg(DAT_3002f5a8,0,0,0,0,0,0);
    (*(code *)*DAT_3002f338)(DAT_3002f344,0xc,auStack_10);
  }
  return;
}

/* ----------------------------------------------------------------
 * SPI_GetGlobalVariable @ 0x3002F06C  (примерный размер ~464 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x3002F06C
 * Данные: DAT_3002f574, DAT_3002f594, DAT_3002f5ac, DAT_3002f5b0, DAT_3002f5b4, DAT_3002f5b8, DAT_3002f5bc, DAT_3002f5c0
 * ---------------------------------------------------------------- */
void SPI_GetGlobalVariable(void)

{
  int iVar1;
  int iVar2;
  
  printf(DAT_3002f5ac);
  printf(DAT_3002f5b0,*DAT_3002f574);
  for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
    printf(DAT_3002f5b4,iVar2);
    printf(DAT_3002f5b8,iVar2,*(undefined4 *)(DAT_3002f594 + iVar2 * 0x6c));
    printf(DAT_3002f5c0,iVar2,*(undefined4 *)(DAT_3002f5bc + iVar2 * 0x6c));
    printf(DAT_3002f5c8,iVar2,*(undefined4 *)(DAT_3002f5c4 + iVar2 * 0x6c));
    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
      printf(DAT_3002f5d0,iVar2,iVar1,*(undefined4 *)(DAT_3002f5cc + iVar1 * 4 + iVar2 * 0x6c));
    }
    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
      if (*(int *)(DAT_3002f5cc + iVar1 * 4 + iVar2 * 0x6c) != 0) {
        printf(DAT_3002f5d4,iVar2,iVar1);
        printf(DAT_3002f5dc,iVar2,iVar1,*(undefined4 *)(iVar2 * 0x6c + DAT_3002f5d8 + iVar1 * 0x14))
        ;
        printf(DAT_3002f5e4,iVar2,iVar1,*(undefined4 *)(iVar1 * 0x14 + DAT_3002f5e0 + iVar2 * 0x6c))
        ;
        printf(DAT_3002f5ec,iVar2,iVar1,*(undefined4 *)(iVar1 * 0x14 + DAT_3002f5e8 + iVar2 * 0x6c))
        ;
        printf(DAT_3002f5f4,iVar2,iVar1,
               (uint)*(ushort *)(iVar1 * 0x14 + DAT_3002f5f0 + iVar2 * 0x6c));
      }
    }
  }
  printf(DAT_3002f5f8);
  return;
}

/* ----------------------------------------------------------------
 * SPI_GetRegistValue @ 0x3002F23C  (примерный размер ~1028 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x3002F23C
 * Данные: DAT_3002f594, DAT_3002f5fc, DAT_3002f600, DAT_3002f604, DAT_3002f608, DAT_3002f60c, DAT_3002f610, DAT_3002f614
 * ---------------------------------------------------------------- */
void SPI_GetRegistValue(void)

{
  int iVar1;
  
  printf(DAT_3002f5fc);
  for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
    printf(DAT_3002f600,iVar1,*(undefined4 *)(DAT_3002f594 + iVar1 * 0x6c),
           **(undefined4 **)(DAT_3002f594 + iVar1 * 0x6c));
    printf(DAT_3002f604,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 4,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 4));
    printf(DAT_3002f608,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 8,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 8));
    printf(DAT_3002f60c,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0xc,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0xc));
    printf(DAT_3002f610,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x10,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x10));
    printf(DAT_3002f614,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x14,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x14));
    printf(DAT_3002f618,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x18,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x18));
    printf(DAT_3002f61c,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x1c,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x1c));
    printf(DAT_3002f620,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x20,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x20));
    printf(DAT_3002f624,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x24,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x24));
    printf(DAT_3002f628,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x28,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x28));
    printf(DAT_3002f62c,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x2c,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x2c));
    printf(DAT_3002f630,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x30,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x30));
    printf(DAT_3002f634,iVar1,*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x34,
           *(undefined4 *)(*(int *)(DAT_3002f594 + iVar1 * 0x6c) + 0x34));
    printf(DAT_3002f638);
  }
  printf(DAT_3002f63c);
  return;
}

/* ----------------------------------------------------------------
 * SSI_FindID @ 0x3002F640  (примерный размер ~84 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3002F640
 * ---------------------------------------------------------------- */
char SSI_FindID(int param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    cVar1 = ')';
  }
  else if (param_1 == 1) {
    cVar1 = '*';
  }
  else if (param_1 == 2) {
    cVar1 = '+';
  }
  else {
    cVar1 = (param_1 != 3) * '\x04' + ',';
  }
  return cVar1;
}

/* ----------------------------------------------------------------
 * PWRCTRL_SSI_SoftClkStatus @ 0x3002F694  (примерный размер ~136 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x3002F694
 * Данные: DAT_300304e0, DAT_300304e4
 * ---------------------------------------------------------------- */
void PWRCTRL_SSI_SoftClkStatus(void)

{
  logMsg(DAT_300304e4,*DAT_300304e0 >> 0x16 & 1,*DAT_300304e0 >> 0x17 & 1,*DAT_300304e0 >> 0x18 & 1,
         *DAT_300304e0 >> 0x19 & 1,0,0);
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_SSI_SoftClkDis @ 0x3002F71C  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3002F71C
 * ---------------------------------------------------------------- */
void PWRCTRL_SSI_SoftClkDis(void)

{
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_SSI_SoftClkEn @ 0x3002F720  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3002F720
 * ---------------------------------------------------------------- */
void PWRCTRL_SSI_SoftClkEn(void)

{
  return;
}

/* ----------------------------------------------------------------
 * SSI_Init @ 0x3002F724  (примерный размер ~668 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x3002F724
 * Данные: DAT_300304e8, DAT_300304ec, DAT_300304f0, DAT_300304f4, DAT_300304f8, DAT_300304fc, DAT_30030500, DAT_30030504
 * ---------------------------------------------------------------- */
undefined4 SSI_Init(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  
  BSP_TRACE(0,0x26,DAT_300304e8,0,0,0,0,0,0);
  if (*DAT_300304ec == 1) {
    BSP_TRACE(0,0x26,DAT_300304f0,0,0,0,0,0,0);
  }
  else {
    *(undefined4 *)(DAT_300304f4 + 4) = DAT_300304f8;
    *(undefined4 *)(DAT_300304f4 + 0x10) = DAT_300304fc;
    *(undefined4 *)(DAT_300304f4 + 0x1c) = DAT_30030500;
    *(undefined4 *)(DAT_300304f4 + 0x28) = DAT_30030504;
    *DAT_30030508 = 4;
    for (uVar3 = 0; uVar3 < *DAT_30030508; uVar3 = uVar3 + 1) {
      puVar1 = *(undefined4 **)(DAT_3003050c + uVar3 * 0xc);
      *(undefined4 *)(uVar3 * 0xc + DAT_30030510) = 0;
      puVar1[1] = 0;
      *puVar1 = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[7] = 0;
      puVar1[10] = 0xf;
      if ((puVar1[6] & 4) != 0) {
        for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1) {
        }
      }
      uVar2 = 0;
      if ((puVar1[6] & 1) == 0) {
        puVar1[1] = 1;
        for (; ((puVar1[6] & 1) == 0 && (uVar2 < DAT_30030514)); uVar2 = uVar2 + 1) {
        }
        if (uVar2 == DAT_30030514) {
          puVar1[1] = 0;
          BSP_TRACE(4,0x26,DAT_30030518,0,0,0,0,0,0);
          return DAT_3003051c;
        }
      }
      puVar1[1] = 0;
      BSP_TRACE(0,0x26,DAT_30030520,uVar3,0,0,0,0,0);
    }
    *DAT_300304ec = 1;
    BSP_TRACE(0,0x26,DAT_30030524,0,0,0,0,0,0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_SSI_SetAttr @ 0x3002F9C0  (примерный размер ~488 байт)
 * Модуль: bsp | Вызывают: 5 | Вызывает: 3
 * Вызывает: BSP_TRACE, intCpuLock, intCpuUnlock
 * Вызывают: ABB_ReadData_Ssi, ABB_Read_Ssi, ABB_Write_Ssi, hkadcInit, hkadcReInit
 * Константы: 0x3002F9C0
 * Данные: DAT_300304ec, DAT_30030508, DAT_3003050c, DAT_30030510, DAT_30030528, DAT_3003052c, DAT_30030530, DAT_30030534
 * ---------------------------------------------------------------- */
undefined4 BSP_SSI_SetAttr(uint param_1,uint *param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  
  BSP_TRACE(0,0x26,DAT_30030528,0,0,0,0,0,0);
  if ((((param_1 < *DAT_30030508) && (-1 < (int)param_1)) && (param_2[1] - 1 < 0x17)) &&
     ((((int)*param_2 < 8 && (-1 < (int)*param_2)) &&
      (((int)param_2[2] < 0x10 && (-1 < (int)param_2[2])))))) {
    if (*DAT_300304ec == 0) {
      BSP_TRACE(4,0x26,DAT_30030534,0,0,0,0,0,0);
      uVar1 = DAT_30030538;
    }
    else {
      uVar1 = intCpuLock();
      puVar2 = *(uint **)(DAT_3003050c + param_1 * 0xc);
      puVar2[1] = 0;
      *puVar2 = *param_2 | param_2[1] << 3;
      puVar2[4] = param_2[2];
      *(undefined4 *)(param_1 * 0xc + DAT_30030510) = 1;
      intCpuUnlock(uVar1);
      BSP_TRACE(0,0x26,DAT_3003053c,0,0,0,0,0,0);
      uVar1 = 0;
    }
  }
  else {
    BSP_TRACE(4,0x26,DAT_3003052c,0,0,0,0,0,0);
    uVar1 = DAT_30030530;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_SSI_Write @ 0x3002FBA8  (примерный размер ~900 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 3
 * Вызывает: BSP_TRACE, intCpuLock, intCpuUnlock
 * Вызывают: ABB_Write_Ssi, hkadcSsiSend
 * Константы: 0x3002FBA8
 * Данные: DAT_300304ec, DAT_30030508, DAT_3003050c, DAT_30030510, DAT_30030514, DAT_3003051c, DAT_30030530, DAT_30030538
 * ---------------------------------------------------------------- */
undefined4 BSP_SSI_Write(uint param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(DAT_3003050c + param_1 * 0xc);
  BSP_TRACE(0,0x26,DAT_30030540,0,0,0,0,0,0);
  if ((((param_2 == (undefined4 *)0x0) || (param_3 != 1)) || (*DAT_30030508 <= param_1)) ||
     ((int)param_1 < 0)) {
    BSP_TRACE(4,0x26,DAT_30030544,param_1,param_2,param_3,0,0,0);
    uVar1 = DAT_30030530;
  }
  else if (*DAT_300304ec == 0) {
    BSP_TRACE(4,0x26,DAT_30030548,0,0,0,0,0,0);
    uVar1 = DAT_30030538;
  }
  else {
    uVar1 = intCpuLock();
    if (*(int *)(DAT_30030510 + param_1 * 0xc) == 0) {
      intCpuUnlock(uVar1);
      BSP_TRACE(4,0x26,DAT_3003054c,0,0,0,0,0,0);
      uVar1 = DAT_30030550;
    }
    else {
      *(undefined4 *)(iVar2 + 4) = 0;
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined4 *)(iVar2 + 4) = 1;
      uVar3 = *(uint *)(iVar2 + 0x18);
      if ((uVar3 & 1) == 0) {
        *(undefined4 *)(iVar2 + 4) = 0;
        intCpuUnlock(uVar1);
        BSP_TRACE(4,0x26,DAT_30030554,DAT_30030558,iVar2,uVar3,0,0,0);
        uVar1 = DAT_3003055c;
      }
      else {
        *(undefined4 *)(iVar2 + 0x14) = *param_2;
        for (uVar3 = 0; ((*(uint *)(iVar2 + 0x18) & 1) == 0 && (uVar3 < DAT_30030514));
            uVar3 = uVar3 + 1) {
        }
        if (uVar3 == DAT_30030514) {
          *(undefined4 *)(iVar2 + 4) = 0;
          intCpuUnlock(uVar1);
          BSP_TRACE(4,0x26,DAT_30030560,DAT_30030564,0,0,0,0,0);
          uVar1 = DAT_3003051c;
        }
        else {
          for (uVar3 = 0; ((*(uint *)(iVar2 + 0x18) & 0x10) != 0 && (uVar3 < DAT_30030514));
              uVar3 = uVar3 + 1) {
          }
          if (uVar3 == DAT_30030514) {
            *(undefined4 *)(iVar2 + 4) = 0;
            intCpuUnlock(uVar1);
            BSP_TRACE(4,0x26,DAT_30030568,0x21c,0,0,0,0,0);
            uVar1 = DAT_3003051c;
          }
          else {
            *(undefined4 *)(iVar2 + 4) = 0;
            intCpuUnlock(uVar1);
            BSP_TRACE(0,0x26,DAT_3003056c,0,0,0,0,0,0);
            uVar1 = 0;
          }
        }
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_SSI_Read @ 0x3002FF2C  (примерный размер ~1036 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 3
 * Вызывает: BSP_TRACE, intCpuLock, intCpuUnlock
 * Вызывают: ABB_ReadData_Ssi, ABB_Read_Ssi, hkadcRegShow, hkadcSsiRecv
 * Константы: 0x3002FF2C
 * Данные: DAT_300304ec, DAT_30030508, DAT_3003050c, DAT_30030510, DAT_30030514, DAT_3003051c, DAT_30030530, DAT_30030538
 * ---------------------------------------------------------------- */
undefined4 BSP_SSI_Read(uint param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = *(int *)(DAT_3003050c + param_1 * 0xc);
  BSP_TRACE(0,0x26,DAT_30030570,0,0,0,0,0,0);
  if ((((param_1 < *DAT_30030508) && (-1 < (int)param_1)) && (param_2 != (undefined4 *)0x0)) &&
     ((param_3 != (undefined4 *)0x0 && (param_4 == 1)))) {
    if (*DAT_300304ec == 0) {
      BSP_TRACE(3,0x26,DAT_30030578,0,0,0,0,0,0);
      uVar1 = DAT_30030538;
    }
    else {
      uVar1 = intCpuLock();
      if (*(int *)(DAT_30030510 + param_1 * 0xc) == 0) {
        intCpuUnlock(uVar1);
        BSP_TRACE(4,0x26,DAT_3003057c,0,0,0,0,0,0);
        uVar1 = DAT_30030550;
      }
      else {
        *(undefined4 *)(iVar3 + 4) = 0;
        *(undefined4 *)(iVar3 + 8) = 1;
        if ((*(uint *)(iVar3 + 0x18) & 4) == 0) {
          *(undefined4 *)(iVar3 + 4) = 1;
          if ((*(uint *)(iVar3 + 0x18) & 1) == 0) {
            intCpuUnlock(uVar1);
            BSP_TRACE(4,0x26,DAT_3003058c,0x280,0,0,0,0,0);
            uVar1 = DAT_3003055c;
          }
          else {
            *(undefined4 *)(iVar3 + 0x14) = *param_2;
            for (; ((*(uint *)(iVar3 + 0x18) & 1) == 0 && (uVar2 < DAT_30030514)); uVar2 = uVar2 + 1
                ) {
            }
            if (uVar2 == DAT_30030514) {
              *(undefined4 *)(iVar3 + 4) = 0;
              intCpuUnlock(uVar1);
              BSP_TRACE(4,0x26,DAT_30030590,DAT_30030594,0,0,0,0,0);
              uVar1 = DAT_3003051c;
            }
            else {
              for (uVar2 = 0; ((*(uint *)(iVar3 + 0x18) & 4) == 0 && (uVar2 < DAT_30030514));
                  uVar2 = uVar2 + 1) {
              }
              if (uVar2 == DAT_30030514) {
                *(undefined4 *)(iVar3 + 4) = 0;
                intCpuUnlock(uVar1);
                BSP_TRACE(4,0x26,DAT_30030598,DAT_3003059c,0,0,0,0,0);
                uVar1 = DAT_300305a0;
              }
              else {
                *param_3 = *(undefined4 *)(iVar3 + 0x14);
                *(undefined4 *)(iVar3 + 4) = 0;
                intCpuUnlock(uVar1);
                BSP_TRACE(0,0x26,DAT_300305a4,0,0,0,0,0,0);
                uVar1 = 0;
              }
            }
          }
        }
        else {
          intCpuUnlock(uVar1);
          BSP_TRACE(4,0x26,DAT_30030580,DAT_30030584,0,0,0,0,0);
          uVar1 = DAT_30030588;
        }
      }
    }
  }
  else {
    BSP_TRACE(4,0x26,DAT_30030574,0,0,0,0,0,0);
    uVar1 = DAT_30030530;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_SSI_GetAttr @ 0x30030338  (примерный размер ~640 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: BSP_TRACE, intCpuLock, intCpuUnlock, memset
 * Константы: 0x30030338
 * Данные: DAT_300304ec, DAT_30030508, DAT_3003050c, DAT_30030530, DAT_30030538, DAT_300305a8, DAT_300305ac, DAT_300305b0
 * ---------------------------------------------------------------- */
undefined4 BSP_SSI_GetAttr(uint param_1,uint *param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = *(uint **)(DAT_3003050c + param_1 * 0xc);
  BSP_TRACE(0,0x26,DAT_300305a8,0,0,0,0,0,0);
  if ((((int)param_1 < 0) || (*DAT_30030508 <= param_1)) || (param_2 == (uint *)0x0)) {
    BSP_TRACE(4,0x26,DAT_300305ac,0,0,0,0,0,0);
    uVar1 = DAT_30030530;
  }
  else if (*DAT_300304ec == 0) {
    BSP_TRACE(4,0x26,DAT_300305b0,0,0,0,0,0,0);
    uVar1 = DAT_30030538;
  }
  else {
    uVar1 = intCpuLock();
    memset(param_2,0,0xc);
    uVar4 = *puVar2;
    uVar3 = puVar2[4];
    *param_2 = uVar4 & 7;
    param_2[1] = uVar4 >> 3;
    param_2[2] = uVar3;
    intCpuUnlock(uVar1);
    BSP_TRACE(0,0x26,DAT_300305b4,0,0,0,0,0,0);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * ABB_ReadCfg @ 0x300305B8  (примерный размер ~500 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 12
 * Вызывает: BSP_TRACE, atoi, close, free, lseek, malloc, open, read, strlen, strncpy, strstr, write
 * Константы: 0xFFFFFFFF, 0x300305B8
 * Данные: DAT_30030c08, DAT_30030c0c, DAT_30030c10, DAT_30030c14, DAT_30030c18, DAT_30030c1c, DAT_30030c20, DAT_30030c24
 * ---------------------------------------------------------------- */
undefined4 ABB_ReadCfg(void)

{
  size_t sVar1;
  char *__haystack;
  undefined4 uVar2;
  int __fd;
  char *pcVar3;
  int iVar4;
  char local_18;
  char local_17;
  char local_16;
  char local_15;
  
  local_18 = *DAT_30030c08;
  local_17 = DAT_30030c08[1];
  local_16 = DAT_30030c08[2];
  local_15 = DAT_30030c08[3];
  sVar1 = strlen((char *)*DAT_30030c0c);
  sVar1 = sVar1 + 1;
  __haystack = (char *)malloc(sVar1);
  if (__haystack == (char *)0x0) {
    BSP_TRACE(4,0x25,DAT_30030c10,0,0,0,0,0,0);
    uVar2 = 0xffffffff;
  }
  else {
    __fd = open(DAT_30030c14,0,DAT_30030c18);
    if (__fd < 0) {
      __fd = open(DAT_30030c14,DAT_30030c1c,DAT_30030c18);
      if (__fd < 0) {
        free(__haystack);
        return 0xffffffff;
      }
      write(__fd,(void *)*DAT_30030c0c,sVar1);
    }
    lseek(__fd,0,0);
    read(__fd,__haystack,sVar1);
    pcVar3 = __haystack;
    do {
      pcVar3 = strstr(pcVar3,DAT_30030c20);
      if (pcVar3 == (char *)0x0) goto LAB_30030738;
      pcVar3 = pcVar3 + 8;
    } while (9 < (int)*pcVar3 - 0x30U);
    strncpy(&local_18,pcVar3,1);
    iVar4 = atoi(&local_18);
    *DAT_30030c24 = iVar4;
LAB_30030738:
    do {
      pcVar3 = strstr(__haystack,DAT_30030c28);
      if (pcVar3 == (char *)0x0) goto LAB_30030790;
    } while (9 < (int)pcVar3[0xe] - 0x30U);
    strncpy(&local_18,pcVar3 + 0xe,1);
    iVar4 = atoi(&local_18);
    DAT_30030c24[1] = iVar4;
LAB_30030790:
    close(__fd);
    free(__haystack);
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * ABB_LineCtrl @ 0x300307AC  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x03FFFFFF, 0x300307AC
 * Данные: DAT_30030c2c, DAT_30030c30, DAT_30030c34
 * ---------------------------------------------------------------- */
void ABB_LineCtrl(void)

{
  *DAT_30030c2c = 0x3ffffff;
  *DAT_30030c30 = 0x3ffffff;
  *DAT_30030c34 = 0x3ffffff;
  return;
}

/* ----------------------------------------------------------------
 * ABB_Write_Ssi @ 0x300307D4  (примерный размер ~244 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 3
 * Вызывает: BSP_SSI_SetAttr, BSP_SSI_Write, logMsg
 * Вызывают: ABB_Init, ABB_SetBandGapOn
 * Константы: 0x300307D4
 * Данные: DAT_30030c38
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

int ABB_Write_Ssi(uint param_1,uint param_2)

{
  int iVar1;
  uint local_24 [4];
  
  local_24[1] = 7;
  local_24[2] = 7;
  local_24[3] = 0xf;
  local_24[0] = param_1 & 0xff | (param_2 & 0xff) << 8;
  iVar1 = BSP_SSI_SetAttr(2,local_24 + 1);
  if (iVar1 == 0) {
    iVar1 = BSP_SSI_Write(2,local_24,1);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      logMsg(DAT_30030c38,0,0,0,0,0,0);
    }
  }
  else {
    logMsg(DAT_30030c38,0,0,0,0,0,0);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * ABB_Read_Ssi @ 0x300308C8  (примерный размер ~288 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_SSI_Read, BSP_SSI_SetAttr, logMsg
 * Константы: 0x300308C8
 * Данные: DAT_30030c38, DAT_30030c3c, DAT_30030c40
 * ---------------------------------------------------------------- */
int ABB_Read_Ssi(undefined1 param_1)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_4 [4];
  
  local_20 = 0;
  local_1c = 7;
  local_18 = 7;
  local_14 = 0xf;
  local_4[0] = param_1;
  iVar1 = BSP_SSI_SetAttr(2,&local_1c);
  if (iVar1 == 0) {
    iVar1 = BSP_SSI_Read(2,local_4,&local_20,1);
    if (iVar1 == 0) {
      logMsg(DAT_30030c40,local_4[0],local_20,1,2,3,4);
      iVar1 = 0;
    }
    else {
      logMsg(DAT_30030c3c,0,0,0,0,0,0);
    }
  }
  else {
    logMsg(DAT_30030c38,0,0,0,0,0,0);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * ABB_ReadData_Ssi @ 0x300309E8  (примерный размер ~236 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: BSP_SSI_Read, BSP_SSI_SetAttr, logMsg
 * Вызывают: ABB_SetBandGapOn
 * Константы: 0x300309E8
 * Данные: DAT_30030c38, DAT_30030c3c
 * ---------------------------------------------------------------- */
int ABB_ReadData_Ssi(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_4 [4];
  
  local_20 = 7;
  local_1c = 7;
  local_18 = 0xf;
  local_4[0] = param_1;
  iVar1 = BSP_SSI_SetAttr(2,&local_20);
  if (iVar1 == 0) {
    iVar1 = BSP_SSI_Read(2,local_4,param_2,1);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      logMsg(DAT_30030c3c,0,0,0,0,0,0);
    }
  }
  else {
    logMsg(DAT_30030c38,0,0,0,0,0,0);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * ABB_Init @ 0x30030AD4  (примерный размер ~236 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: ABB_Write_Ssi
 * Константы: 0x30030AD4
 * Данные: DAT_30030c48, DAT_30030c4c
 * ---------------------------------------------------------------- */
undefined4 ABB_Init(void)

{
  int iVar1;
  
  ABB_Write_Ssi(0x20,0xfe);
  ABB_Write_Ssi(0x24,0xf8);
  ABB_Write_Ssi(0xdc,0xb8);
  ABB_Write_Ssi(0xe1,0x40);
  ABB_Write_Ssi(0xda,3);
  ABB_Write_Ssi(0xd5,0x80);
  for (iVar1 = DAT_30030c48; -1 < iVar1; iVar1 = iVar1 + -1) {
  }
  ABB_Write_Ssi(0xd5,0);
  ABB_Write_Ssi(0xc0,3);
  ABB_Write_Ssi(0xc1,0);
  ABB_Write_Ssi(0xc2,0xd);
  for (iVar1 = DAT_30030c4c; -1 < iVar1; iVar1 = iVar1 + -1) {
  }
  ABB_Write_Ssi(0xc2,0xc);
  ABB_Write_Ssi(0x1c,0x13);
  return 0;
}

/* ----------------------------------------------------------------
 * ABB_SetBandGapOn @ 0x30030BC0  (примерный размер ~144 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: ABB_ReadData_Ssi, ABB_Write_Ssi
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x30030BC0
 * ---------------------------------------------------------------- */
void ABB_SetBandGapOn(void)

{
  byte local_10 [4];
  
  local_10[0] = 0;
  ABB_ReadData_Ssi(0xd6,local_10);
  local_10[0] = local_10[0] | 0x80;
  ABB_Write_Ssi(0xd6,local_10[0]);
  return;
}

/* ----------------------------------------------------------------
 * pmu_press_release_isr @ 0x30030C50  (примерный размер ~56 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30030C50
 * ---------------------------------------------------------------- */
void pmu_press_release_isr(void)

{
  return;
}

/* ----------------------------------------------------------------
 * HI6451_reg_write @ 0x30030C88  (примерный размер ~120 байт)
 * Модуль: bsp | Вызывают: 16 | Вызывает: 1
 * Вызывает: BSP_SPI_Write
 * Вызывают: BSP_PMU_BoardInit, BSP_PMU_RegWrite, HI6451_breath_set, HI6451_buck_voltage_set, HI6451_current_overflow_get, HI6451_current_overflow_isr, HI6451_current_set, HI6451_current_switch, HI6451_ist, HI6451_otp_callback
 *           ...
 * Константы: 0x30030C88, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 HI6451_reg_write(uint param_1,ushort param_2)

{
  undefined4 uVar1;
  ushort local_24 [2];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_24[0] = param_2 & 0xff | (ushort)((param_1 & 0xff) << 9);
  if ((param_1 & 0xff) < 0x80) {
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 1;
    uVar1 = BSP_SPI_Write(&local_20,local_24,1);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * HI6451_reg_read @ 0x30030D00  (примерный размер ~164 байт)
 * Модуль: bsp | Вызывают: 23 | Вызывает: 1
 * Вызывает: BSP_SPI_Read
 * Вызывают: BSP_PMU_BoardInit, BSP_PMU_RegRead, HI6451_current_get, HI6451_current_overflow_get, HI6451_current_overflow_isr, HI6451_current_set, HI6451_current_switch, HI6451_get_current_state, HI6451_get_voltage_state, HI6451_init
 *           ...
 * Константы: 0x30030D00, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 HI6451_reg_read(uint param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined2 local_28;
  ushort local_26;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ushort *local_18;
  undefined4 local_14;
  
  local_28 = 0;
  local_26 = (ushort)(((param_1 & 0xff) << 0x10) >> 7) | 0x100;
  if (((param_1 & 0xff) < 0x80) && (param_2 != (undefined1 *)0x0)) {
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = &local_26;
    local_14 = 1;
    uVar1 = BSP_SPI_Read(&local_24,&local_28,1);
    *param_2 = (char)local_28;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * HI6451_reg_show @ 0x30030DA4  (примерный размер ~96 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: HI6451_reg_read, printf
 * Константы: 0x30030DA4, 0xFFFFFFFF
 * Данные: DAT_30031d30, DAT_30031d34
 * ---------------------------------------------------------------- */
undefined4 HI6451_reg_show(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte local_10 [4];
  
  local_10[0] = 0;
  iVar1 = HI6451_reg_read(param_1,local_10);
  if (iVar1 == 0) {
    printf(DAT_30031d34,param_1 & 0xff,(uint)local_10[0]);
    uVar2 = 0;
  }
  else {
    printf(DAT_30031d30,iVar1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * HI6451_reg_write_mask @ 0x30030E04  (примерный размер ~76 байт)
 * Модуль: bsp | Вызывают: 5 | Вызывает: 2
 * Вызывает: HI6451_reg_read, HI6451_reg_write
 * Вызывают: BSP_PMU_RegWriteMask, HI6451_init, HI6451_usb_insert_proc, HI6451_usb_remove_proc, HI6451_voltage_set
 * Константы: 0x30030E04
 * ---------------------------------------------------------------- */
void HI6451_reg_write_mask(undefined4 param_1,byte param_2,byte param_3)

{
  byte local_14 [4];
  
  local_14[0] = 0;
  HI6451_reg_read(param_1,local_14);
  local_14[0] = local_14[0] & ~param_3 | param_2;
  HI6451_reg_write(param_1,local_14[0]);
  return;
}

/* ----------------------------------------------------------------
 * HI6451_voltage_set @ 0x30030E50  (примерный размер ~284 байт)
 * Модуль: bsp | Вызывают: 6 | Вызывает: 2
 * Вызывает: BSP_TRACE, HI6451_reg_write_mask
 * Вызывают: BSP_PMU_LDOVoltSet, HI6451_buck_voltage_set, HI6451_init, pmSetLDOVltg, pmuLDOVoltSet, sdmmcStatusPollTask
 * Константы: 0x30030E50, 0xFFFFFFFF
 * Данные: DAT_30031d38, DAT_30031d3c, DAT_30031d40, DAT_30031d44, DAT_30031e8c
 * ---------------------------------------------------------------- */
undefined4 HI6451_voltage_set(int param_1,short param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(DAT_30031d38 + param_1 * 4);
  if ((((param_1 < 0x16) && (0 < param_1)) && (param_2 != 0)) && (iVar2 != 0)) {
    for (uVar3 = 0; *(short *)(iVar2 + uVar3 * 2) != 0; uVar3 = uVar3 + 1) {
      if (param_2 == *(short *)(iVar2 + uVar3 * 2)) {
        if ((param_1 == 0xc) && (param_2 == 300)) {
          BSP_TRACE(0,0x2b,DAT_30031e8c,1,2,3,4,5,6);
          return 0;
        }
        uVar1 = HI6451_reg_write_mask
                          (*(undefined1 *)(DAT_30031d3c + param_1 * 4),
                           (uVar3 & 0xff) << *(sbyte *)(DAT_30031d44 + param_1 * 4),
                           *(undefined1 *)(DAT_30031d40 + param_1 * 4));
        return uVar1;
      }
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * HI6451_voltage_switch @ 0x30030F6C  (примерный размер ~608 байт)
 * Модуль: bsp | Вызывают: 8 | Вызывает: 3
 * Вызывает: HI6451_reg_read, HI6451_reg_write, logMsg
 * Вызывают: BSP_PMU_LDOCtrl, HI6451_buck_switch, HI6451_init, HI6451_ocp_callback, HI6451_otp_callback, pmLDOOFF, pmLDOON, sdmmcStatusPollTask
 * Константы: 0x30030F6C, 0x90000000, 0x20000000
 * Данные: DAT_30031e90, DAT_30031e94, DAT_30031e98, DAT_30031e9c, DAT_30031ea0, DAT_30031f54, DAT_30031f58, DAT_30032064
 * ---------------------------------------------------------------- */
int HI6451_voltage_switch(int param_1,int param_2)

{
  undefined1 uVar1;
  sbyte sVar2;
  int iVar3;
  byte local_1c [4];
  
  uVar1 = *(undefined1 *)(DAT_30031e90 + param_1 * 2);
  sVar2 = *(sbyte *)(DAT_30031e94 + param_1 * 2);
  local_1c[0] = 0;
  if ((0x15 < param_1) || (param_1 < 1)) {
    return -1;
  }
  if (((*(char *)(DAT_30031e98 + 3) == '\x01') && (param_2 == 1)) && (*DAT_30031e9c != 0)) {
    if ((param_1 == 0x13) && ((*DAT_30031e9c & 0x90000000) != 0)) {
      logMsg(DAT_30031ea0,1,2,3,4,5,6);
      return 0;
    }
    if ((param_1 == 0x14) && ((*DAT_30031e9c & 0x20000000) != 0)) {
      logMsg(DAT_30031f54,1,2,3,4,5,6);
      return 0;
    }
    if ((param_1 < 0x10) && ((*DAT_30031e9c & 1 << (0xfU - param_1 & 0xff)) != 0)) {
      logMsg(DAT_30031f58,param_1,2,3,4,5,6);
      return 0;
    }
    if ((0xf < param_1) && ((*DAT_30031e9c & 1 << (0x24U - param_1 & 0xff)) != 0)) {
      logMsg(DAT_30032064,param_1 + -0xf,2,3,4,5,6);
      return 0;
    }
  }
  iVar3 = HI6451_reg_read(uVar1,local_1c);
  if (iVar3 == 0) {
    if (param_1 == 0x10) {
      if (param_2 == 0) {
        local_1c[0] = local_1c[0] & 0x3f | 0x80;
      }
      else {
        local_1c[0] = local_1c[0] & 0x3f | 0x40;
      }
    }
    else if (param_2 == 0) {
      local_1c[0] = local_1c[0] & ~(byte)(1 << sVar2);
    }
    else {
      local_1c[0] = local_1c[0] | (byte)(1 << sVar2);
    }
    iVar3 = HI6451_reg_write(uVar1,local_1c[0]);
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * HI6451_current_set @ 0x300311CC  (примерный размер ~224 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 2
 * Вызывает: HI6451_reg_read, HI6451_reg_write
 * Вызывают: BSP_PMU_DrCurrentSet, HI6451_init
 * Константы: 0x300311CC, 0xFFFFFFFF
 * Данные: DAT_30032068, DAT_3003206c, DAT_30032070, DAT_30032074
 * ---------------------------------------------------------------- */
undefined4 HI6451_current_set(int param_1,ushort param_2)

{
  undefined1 uVar1;
  byte bVar2;
  sbyte sVar3;
  undefined4 uVar4;
  int iVar5;
  byte local_28 [4];
  
  uVar1 = *(undefined1 *)(DAT_3003206c + param_1 * 4);
  bVar2 = *(byte *)(DAT_30032070 + param_1 * 4);
  sVar3 = *(sbyte *)(DAT_30032074 + param_1 * 4);
  local_28[0] = 0;
  if (((0 < param_1) && (param_1 < 4)) && (param_2 - 3 < 0x16)) {
    for (iVar5 = 0; *(short *)(DAT_30032068 + iVar5 * 2) != 0; iVar5 = iVar5 + 1) {
      if (param_2 == *(ushort *)(DAT_30032068 + iVar5 * 2)) {
        HI6451_reg_read(uVar1,local_28);
        local_28[0] = local_28[0] & ~bVar2 | (byte)(iVar5 << sVar3);
        uVar4 = HI6451_reg_write(uVar1,local_28[0]);
        return uVar4;
      }
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * HI6451_int_install @ 0x300312AC  (примерный размер ~120 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 0
 * Вызывают: BSP_PMU_BoardInit, HI6451_init
 * Константы: 0xFFFFFFFF, 0x300312AC
 * Данные: DAT_30032214, DAT_30032218
 * ---------------------------------------------------------------- */
undefined4 HI6451_int_install(byte param_1,byte param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    uVar1 = 0xffffffff;
  }
  else if ((param_1 < 6) && (param_2 < 8)) {
    *(int *)(DAT_30032214 + (uint)param_1 * 0x40 + (uint)param_2 * 8) = param_3;
    *(undefined4 *)(DAT_30032218 + (uint)param_2 * 8 + (uint)param_1 * 0x40) = param_4;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * HI6451_status_int_install @ 0x30031324  (примерный размер ~120 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: HI6451_init
 * Константы: 0xFFFFFFFF, 0x30031324
 * Данные: DAT_3003221c, DAT_30032220
 * ---------------------------------------------------------------- */
undefined4 HI6451_status_int_install(byte param_1,byte param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    uVar1 = 0xffffffff;
  }
  else if ((param_1 < 5) && (param_2 < 8)) {
    *(int *)(DAT_3003221c + (uint)param_1 * 0x40 + (uint)param_2 * 8) = param_3;
    *(undefined4 *)(DAT_30032220 + (uint)param_2 * 8 + (uint)param_1 * 0x40) = param_4;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * HI6451_current_overflow_get @ 0x30031434  (примерный размер ~496 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: HI6451_reg_read, HI6451_reg_write
 * Вызывают: HI6451_init
 * Константы: 0x30031434, 0x80000000, 0x04000000, 0x08000000, 0x00200000, 0x00400000, 0x10000000, 0x20000000
 * Данные: DAT_30031e9c, DAT_30032334
 * ---------------------------------------------------------------- */
void HI6451_current_overflow_get(void)

{
  byte local_c [4];
  byte local_8;
  byte local_7;
  byte local_6 [6];
  
  local_c[0] = 0;
  local_8 = *DAT_30032334;
  local_7 = DAT_30032334[1];
  local_6[0] = DAT_30032334[2];
  HI6451_reg_read(0x40,local_c);
  if ((local_c[0] & 1) != 0) {
    *DAT_30031e9c = *DAT_30031e9c | 0x80000000;
  }
  if ((local_c[0] & 4) != 0) {
    *DAT_30031e9c = *DAT_30031e9c | 0x4000000;
  }
  if ((local_c[0] & 0x10) != 0) {
    *DAT_30031e9c = *DAT_30031e9c | 0x8000000;
  }
  HI6451_reg_write(0x40,0xff);
  HI6451_reg_read(0x41,local_c);
  if ((local_c[0] & 0x20) != 0) {
    *DAT_30031e9c = *DAT_30031e9c | 0x200000;
  }
  if ((local_c[0] & 0x40) != 0) {
    *DAT_30031e9c = *DAT_30031e9c | 0x400000;
  }
  if ((local_c[0] & 1) != 0) {
    HI6451_reg_read(4,&local_8);
    HI6451_reg_read(5,&local_7);
    HI6451_reg_read(6,local_6);
    *DAT_30031e9c = *DAT_30031e9c | (uint)local_8 << 0xd | (uint)local_7 << 5 | (uint)local_6[0];
    if ((*DAT_30031e9c & 0x20000) != 0) {
      *DAT_30031e9c = *DAT_30031e9c | 0x10000000;
    }
    if ((*DAT_30031e9c & 0x10000) != 0) {
      *DAT_30031e9c = *DAT_30031e9c | 0x20000000;
    }
    *DAT_30031e9c = *DAT_30031e9c | 0x2000000;
    HI6451_reg_write(4,0xff);
    HI6451_reg_write(5,0xff);
    HI6451_reg_write(6,0xff);
    HI6451_reg_write(0x41,0xff);
  }
  return;
}

/* ----------------------------------------------------------------
 * HI6451_init @ 0x30031624  (примерный размер ~1508 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 13
 * Вызывает: BSP_SPI_SetAttr, BSP_TRACE, HI6451_current_overflow_get, HI6451_current_set, HI6451_int_install, HI6451_reg_read, HI6451_reg_write_mask, HI6451_status_int_install, HI6451_voltage_set, HI6451_voltage_switch, Hi6451_BugAvoid, semBCreate, taskSpawn
 * Вызывают: BSP_PMU_Init
 * Константы: 0x30031624
 * Данные: DAT_30032224, DAT_30032228, DAT_30032518, DAT_30032624, DAT_30032628, DAT_3003262c, DAT_300326dc, DAT_300326e0
 * ---------------------------------------------------------------- */
int HI6451_init(void)

{
  int iVar1;
  uint uVar2;
  byte local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined2 local_10;
  
  local_2b = 0;
  local_2a = 0;
  local_29 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 7;
  local_1c = 0xf;
  local_18 = 0;
  local_14 = 1;
  local_10 = 0x1a;
  iVar1 = BSP_SPI_SetAttr(&local_28,&local_20);
  if (iVar1 == 0) {
    HI6451_reg_read(0,&local_2c);
    *DAT_30032224 = (uint)local_2c;
    if ((*DAT_30032224 == 0x10) && (HI6451_reg_read(0x51,&local_2c), (local_2c & 1) == 1)) {
      *DAT_30032228 = 1;
    }
    HI6451_reg_read(0x40,&local_2b);
    HI6451_reg_read(0x41,&local_2a);
    HI6451_reg_read(0x42,&local_29);
    BSP_TRACE(4,0x2b,DAT_30032624,local_2b,0,0,0,0,0);
    BSP_TRACE(4,0x2b,DAT_30032628,local_2a,0,0,0,0,0);
    BSP_TRACE(4,0x2b,DAT_3003262c,local_29,0,0,0,0,0);
    HI6451_reg_read(1,&local_2b);
    HI6451_reg_read(2,&local_2a);
    HI6451_reg_read(3,&local_29);
    BSP_TRACE(4,0x2b,DAT_300326dc,local_2b,0,0,0,0,0);
    BSP_TRACE(4,0x2b,DAT_300326e0,local_2a,0,0,0,0,0);
    BSP_TRACE(4,0x2b,DAT_300326e4,local_29,0,0,0,0,0);
    HI6451_reg_read(0x43,&local_2c);
    BSP_TRACE(4,0x2b,DAT_300327b4,local_2c,0,0,0,0,0);
    HI6451_reg_read(0x44,&local_2c);
    BSP_TRACE(4,0x2b,DAT_300327b8,local_2c,0,0,0,0,0);
    for (uVar2 = 0; uVar2 < 5; uVar2 = uVar2 + 1) {
      HI6451_reg_read(uVar2 + 4,&local_2c);
      BSP_TRACE(4,0x2b,DAT_300327bc,uVar2 + 4,local_2c,0,0,0,0);
    }
    HI6451_current_overflow_get();
    HI6451_current_set(1,3);
    HI6451_current_set(2,3);
    HI6451_current_set(3,3);
    HI6451_int_install(1,0,DAT_30032854,0);
    HI6451_int_install(0,0,DAT_30032858,0);
    for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1) {
      HI6451_status_int_install(0,uVar2,DAT_3003285c,1 << (uVar2 + 0xd & 0xff));
    }
    for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1) {
      HI6451_status_int_install(1,uVar2,DAT_3003285c,1 << (uVar2 + 5 & 0xff));
    }
    for (uVar2 = 0; uVar2 < 5; uVar2 = uVar2 + 1) {
      HI6451_status_int_install(2,uVar2,DAT_3003285c,1 << (uVar2 & 0xff));
    }
    HI6451_int_install(0,4,DAT_30032940,0);
    HI6451_int_install(0,2,DAT_30032944,0);
    HI6451_voltage_set(3,0xfa);
    HI6451_voltage_switch(3,1);
    Hi6451_BugAvoid();
    if (*DAT_30032948 == 0) {
      iVar1 = semBCreate(0,0);
      *DAT_30032948 = iVar1;
      if (*DAT_30032948 == 0) {
        return -1;
      }
    }
    taskSpawn(DAT_30032950,100,0,0x1000,DAT_3003294c,0,0,0,0,0,0,0,0,0,0);
    HI6451_reg_write_mask(9,0,0xc0);
    iVar1 = 0;
  }
  else {
    BSP_TRACE(0,0x2b,DAT_30032518,0,0,0,0,0,0);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * HI6451_buck_voltage_set @ 0x30031C08  (примерный размер ~128 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: HI6451_reg_write, HI6451_voltage_set
 * Вызывают: BSP_PMU_BuckVoltSet
 * Константы: 0x30031C08, 0xFFFFFFFF
 * Данные: DAT_30032224, DAT_30032228
 * ---------------------------------------------------------------- */
undefined4 HI6451_buck_voltage_set(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 7) {
    if ((*DAT_30032224 == 0x10) && (*DAT_30032228 == 0)) {
      if (param_1 == 4) {
        HI6451_reg_write(0x23,0);
      }
      else if (param_1 == 5) {
        HI6451_reg_write(0x24,0);
      }
    }
    uVar1 = HI6451_voltage_set(param_1 + 0xf,param_2);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * HI6451_buck_switch @ 0x30031C88  (примерный размер ~52 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: HI6451_voltage_switch
 * Вызывают: BSP_PMU_BuckCtrl
 * Константы: 0x30031C88, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 HI6451_buck_switch(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 - 1U < 5) {
    uVar1 = HI6451_voltage_switch(param_1 + 0xf,param_2);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * HI6451_voltage_get @ 0x30031CBC  (примерный размер ~204 байт)
 * Модуль: bsp | Вызывают: 3 | Вызывает: 1
 * Вызывает: HI6451_reg_read
 * Вызывают: BSP_PMU_LDOVoltGet, HI6451_buck_voltage_get, pmGetLDOVltg
 * Константы: 0xFFFFFFFF, 0x30031CBC
 * Данные: DAT_30031d38, DAT_30031d3c, DAT_30031d40, DAT_30031d44
 * ---------------------------------------------------------------- */
uint HI6451_voltage_get(int param_1)

{
  byte bVar1;
  sbyte sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte local_20 [4];
  
  local_20[0] = 0;
  iVar5 = *(int *)(DAT_30031d38 + param_1 * 4);
  bVar1 = *(byte *)(DAT_30031d40 + param_1 * 4);
  sVar2 = *(sbyte *)(DAT_30031d44 + param_1 * 4);
  if (((param_1 < 0x16) && (0 < param_1)) && (iVar5 != 0)) {
    iVar4 = HI6451_reg_read(*(undefined1 *)(DAT_30031d3c + param_1 * 4),local_20);
    if (iVar4 == 0) {
      if (param_1 == 0xc) {
        uVar3 = 300;
      }
      else {
        uVar3 = (uint)*(ushort *)(iVar5 + ((int)(uint)(local_20[0] & bVar1) >> sVar2 & 0xffffU) * 2)
        ;
      }
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * HI6451_buck_voltage_get @ 0x30031D88  (примерный размер ~44 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: HI6451_voltage_get
 * Вызывают: BSP_PMU_BuckVoltGet
 * Константы: 0x30031D88, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 HI6451_buck_voltage_get(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 - 1U < 5) {
    uVar1 = HI6451_voltage_get(param_1 + 0xf);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * HI6451_voltage_ecoset @ 0x30031DB4  (примерный размер ~144 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: HI6451_reg_read, HI6451_reg_write
 * Константы: 0x30031DB4, 0xFFFFFFFF
 * Данные: DAT_30032bb0, DAT_30032bb4
 * ---------------------------------------------------------------- */
undefined4 HI6451_voltage_ecoset(int param_1,int param_2)

{
  undefined1 uVar1;
  sbyte sVar2;
  undefined4 uVar3;
  byte local_18 [4];
  
  uVar1 = *(undefined1 *)(DAT_30032bb0 + param_1 * 2);
  sVar2 = *(sbyte *)(DAT_30032bb4 + param_1 * 2);
  local_18[0] = 0;
  if ((param_1 < 1) || (0x15 < param_1)) {
    uVar3 = 0xffffffff;
  }
  else {
    HI6451_reg_read(uVar1,local_18);
    if (param_2 == 0) {
      local_18[0] = local_18[0] & ~(byte)(1 << sVar2);
    }
    else {
      local_18[0] = local_18[0] | (byte)(1 << sVar2);
    }
    uVar3 = HI6451_reg_write(uVar1,local_18[0]);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * HI6451_current_get @ 0x30031E44  (примерный размер ~156 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: HI6451_reg_read
 * Вызывают: BSP_PMU_DrCurrentGet
 * Константы: 0x30031E44, 0xFFFFFFFF
 * Данные: DAT_30032068, DAT_3003206c, DAT_30032070, DAT_30032074
 * ---------------------------------------------------------------- */
uint HI6451_current_get(int param_1)

{
  byte bVar1;
  sbyte sVar2;
  uint uVar3;
  byte local_1c [4];
  
  bVar1 = *(byte *)(DAT_30032070 + param_1 * 4);
  sVar2 = *(sbyte *)(DAT_30032074 + param_1 * 4);
  local_1c[0] = 0;
  if ((param_1 < 1) || (3 < param_1)) {
    uVar3 = 0xffffffff;
  }
  else {
    HI6451_reg_read(*(undefined1 *)(DAT_3003206c + param_1 * 4),local_1c);
    uVar3 = (uint)*(ushort *)
                   (DAT_30032068 + ((int)(uint)(local_1c[0] & bVar1) >> sVar2 & 0xffffU) * 2);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * HI6451_current_switch @ 0x30031EE0  (примерный размер ~212 байт)
 * Модуль: bsp | Вызывают: 3 | Вызывает: 2
 * Вызывает: HI6451_reg_read, HI6451_reg_write
 * Вызывают: BSP_PMU_DRCtrl, pmDROFF, pmDRON
 * Константы: 0xFFFFFFFF, 0x30031EE0
 * Данные: DAT_3003206c, DAT_30032224, DAT_30032d48
 * ---------------------------------------------------------------- */
undefined4 HI6451_current_switch(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  byte local_18 [4];
  
  local_18[0] = 0;
  if ((param_1 < 1) || (3 < param_1)) {
    uVar2 = 0xffffffff;
  }
  else {
    if (*DAT_30032224 == 0x18) {
      uVar1 = *(undefined1 *)(DAT_30032d48 + param_1);
      iVar3 = 0;
    }
    else {
      if (*DAT_30032224 != 0x10) {
        return 0xffffffff;
      }
      uVar1 = *(undefined1 *)(DAT_3003206c + param_1 * 4);
      iVar3 = 3;
    }
    HI6451_reg_read(uVar1,local_18);
    if (param_2 == 0) {
      local_18[0] = local_18[0] & ~(byte)(1 << iVar3);
    }
    else {
      local_18[0] = local_18[0] | (byte)(1 << iVar3);
    }
    uVar2 = HI6451_reg_write(uVar1,local_18[0]);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * HI6451_int_default_handler @ 0x30031FB4  (примерный размер ~208 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Вызывают: HI6451_ist
 * Константы: 0x30031FB4
 * Данные: DAT_30032e50, DAT_30032e54
 * ---------------------------------------------------------------- */
void HI6451_int_default_handler(uint param_1,uint param_2)

{
  BSP_TRACE(0,0x2b,DAT_30032e50,param_1 >> 0x10 & 0xff,param_1 >> 8 & 0xff,param_1 & 0xff,0,0,0);
  BSP_TRACE(0,0x2b,DAT_30032e54,param_2 >> 0x10 & 0xff,param_2 >> 8 & 0xff,param_2 & 0xff,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * HI6451_isr @ 0x30032084  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: intDisable, semGive
 * Константы: 0x30032084
 * Данные: DAT_30032948
 * ---------------------------------------------------------------- */
void HI6451_isr(void)

{
  intDisable(0x7f);
  semGive(*DAT_30032948);
  return;
}

/* ----------------------------------------------------------------
 * HI6451_ist @ 0x300320A0  (примерный размер ~456 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 5
 * Вызывает: HI6451_int_default_handler, HI6451_reg_read, HI6451_reg_write, intEnable, semTake
 * Константы: 0x300320A0, 0xFFFFFFFF
 * Данные: DAT_30032214, DAT_30032218, DAT_30032948, DAT_30032e58
 * ---------------------------------------------------------------- */
void HI6451_ist(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte local_24 [8];
  
  pbVar3 = local_24;
  iVar8 = 3;
  pbVar5 = DAT_30032e58;
  do {
    pbVar4 = pbVar5 + 1;
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 2;
    bVar2 = *pbVar4;
    iVar8 = iVar8 + -1;
    pbVar4 = pbVar3 + 1;
    *pbVar3 = bVar1;
    pbVar3 = pbVar3 + 2;
    *pbVar4 = bVar2;
  } while (iVar8 != 0);
  do {
    do {
      iVar8 = semTake(*DAT_30032948,0xffffffff);
    } while (iVar8 != 0);
    for (uVar7 = 0; uVar7 < 3; uVar7 = uVar7 + 1) {
      HI6451_reg_read(uVar7 + 1,local_24 + uVar7);
      HI6451_reg_read(uVar7 + 0x40,local_24 + uVar7 + 3);
    }
    for (uVar7 = 0; uVar7 < 3; uVar7 = uVar7 + 1) {
      HI6451_reg_write(uVar7 + 1,local_24[uVar7]);
    }
    HI6451_int_default_handler
              ((uint)local_24[0] * 0x10000 + (uint)local_24[1] * 0x100 + (uint)local_24[2],
               (uint)local_24[3] * 0x10000 + (uint)local_24[4] * 0x100 + (uint)local_24[5]);
    for (uVar7 = 0; uVar7 < 6; uVar7 = uVar7 + 1) {
      bVar1 = local_24[uVar7];
      for (uVar6 = 0; uVar6 < 8; uVar6 = uVar6 + 1) {
        if ((((uint)bVar1 & 1 << (uVar6 & 0xff)) != 0) &&
           (*(int *)(DAT_30032214 + uVar7 * 0x40 + uVar6 * 8) != 0)) {
          (**(code **)(DAT_30032214 + uVar7 * 0x40 + uVar6 * 8))
                    (*(undefined4 *)(DAT_30032218 + uVar6 * 8 + uVar7 * 0x40));
        }
      }
    }
    for (uVar7 = 0; uVar7 < 3; uVar7 = uVar7 + 1) {
      HI6451_reg_write(uVar7 + 0x40,local_24[uVar7 + 3]);
    }
    intEnable(0x7f);
  } while( true );
}

/* ----------------------------------------------------------------
 * HI6451_usb_insert_proc @ 0x30032268  (примерный размер ~276 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: BSP_TRACE, HI6451_reg_read, HI6451_reg_write_mask
 * Вызывают: BSP_PMU_BoardInit
 * Константы: 0x30032268
 * Данные: DAT_30033130, DAT_30033134
 * ---------------------------------------------------------------- */
void HI6451_usb_insert_proc(void)

{
  int iVar1;
  byte local_8 [8];
  
  local_8[0] = 0;
  HI6451_reg_write_mask(10,8,8);
  iVar1 = HI6451_reg_read(8,local_8);
  if (iVar1 == 0) {
    if (((local_8[0] & 3) == 3) && (*DAT_30033130 != 0)) {
      (*(code *)*DAT_30033130)();
      BSP_TRACE(0,0x2b,DAT_30033134,0,0,0,0,0,0);
    }
    BSP_TRACE(4,0x2b,DAT_30033134,0,0,0,0,0,0);
    HI6451_reg_write_mask(10,0,4);
  }
  else {
    HI6451_reg_write_mask(10,0,8);
  }
  return;
}

/* ----------------------------------------------------------------
 * HI6451_usb_status_get @ 0x3003237C  (примерный размер ~72 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: HI6451_reg_read
 * Константы: 0x3003237C
 * ---------------------------------------------------------------- */
undefined4 HI6451_usb_status_get(void)

{
  int iVar1;
  undefined4 uVar2;
  byte local_8 [8];
  
  local_8[0] = 0;
  iVar1 = HI6451_reg_read(8,local_8);
  if (iVar1 == 0) {
    if ((local_8[0] & 3) == 3) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * HI6451_usb_remove_proc @ 0x300323C4  (примерный размер ~264 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, HI6451_reg_read, HI6451_reg_write_mask
 * Константы: 0x300323C4
 * Данные: DAT_30033130, DAT_30033318
 * ---------------------------------------------------------------- */
void HI6451_usb_remove_proc(void)

{
  int iVar1;
  byte local_8 [8];
  
  local_8[0] = 0;
  HI6451_reg_write_mask(10,4,4);
  iVar1 = HI6451_reg_read(8,local_8);
  if (iVar1 == 0) {
    if (((local_8[0] & 3) == 0) && (*(int *)(DAT_30033130 + 4) != 0)) {
      (**(code **)(DAT_30033130 + 4))();
      BSP_TRACE(0,0x2b,DAT_30033318,0,0,0,0,0,0);
    }
    BSP_TRACE(4,0x2b,DAT_30033318,0,0,0,0,0,0);
    HI6451_reg_write_mask(10,0,8);
  }
  else {
    HI6451_reg_write_mask(10,0,4);
  }
  return;
}

/* ----------------------------------------------------------------
 * HI6451_clock_switch @ 0x300324CC  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300324CC
 * ---------------------------------------------------------------- */
undefined4 HI6451_clock_switch(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * HI6451_sim_puresister_switch @ 0x300324D4  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300324D4
 * ---------------------------------------------------------------- */
undefined4 HI6451_sim_puresister_switch(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * HI6451_get_voltage_state @ 0x300324DC  (примерный размер ~112 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: HI6451_reg_read
 * Вызывают: pmGetLDOStatus
 * Константы: 0x300324DC, 0xFFFFFFFF
 * Данные: DAT_3003331c, DAT_30033320
 * ---------------------------------------------------------------- */
undefined4 HI6451_get_voltage_state(int param_1)

{
  sbyte sVar1;
  undefined4 uVar2;
  byte local_14 [4];
  
  sVar1 = *(sbyte *)(DAT_30033320 + param_1 * 2);
  local_14[0] = 0;
  if ((param_1 < 0x16) && (0 < param_1)) {
    HI6451_reg_read(*(undefined1 *)(DAT_3003331c + param_1 * 2),local_14);
    if (((uint)local_14[0] & 1 << sVar1) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * HI6451_get_current_state @ 0x3003254C  (примерный размер ~96 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: HI6451_reg_read
 * Константы: 0x3003254C, 0xFFFFFFFF
 * Данные: DAT_30033448
 * ---------------------------------------------------------------- */
undefined4 HI6451_get_current_state(int param_1)

{
  undefined4 uVar1;
  byte local_10 [4];
  
  local_10[0] = 0;
  if ((param_1 < 1) || (3 < param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    HI6451_reg_read(*(undefined1 *)(DAT_30033448 + param_1 * 4),local_10);
    if ((local_10[0] & 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * HI6451_error_log_save @ 0x300325AC  (примерный размер ~808 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: BSP_TRACE, exchLogPrintf, fclose, fopen
 * Вызывают: HI6451_status_isr
 * Константы: 0x300325AC, 0x40000000, 0x01000000, 0x00800000, 0xBFFFFFFF
 * Данные: DAT_3003344c, DAT_30033450, DAT_30033454, DAT_30033458, DAT_3003345c, DAT_30033460, DAT_30033518, DAT_3003351c
 * ---------------------------------------------------------------- */
void HI6451_error_log_save(void)

{
  FILE *__stream;
  uint uVar1;
  
  if (*DAT_3003344c != 0) {
    __stream = fopen(DAT_30033450,DAT_30033454);
    if (__stream == (FILE *)0x0) {
      BSP_TRACE(4,0x2b,DAT_30033458,0,0,0,0,0,0);
    }
    else {
      exchLogPrintf(__stream,DAT_3003345c,*DAT_3003344c);
      if ((*DAT_3003344c & 0x40000000) != 0) {
        exchLogPrintf(__stream,DAT_30033460);
      }
      for (uVar1 = 1; uVar1 < 0x16; uVar1 = uVar1 + 1) {
        if ((0xf < uVar1) && ((*DAT_3003344c & 1 << (0x24 - uVar1 & 0xff)) != 0)) {
          exchLogPrintf(__stream,DAT_30033518,uVar1 - 0xf);
        }
        if ((uVar1 < 0x10) && ((*DAT_3003344c & 1 << (0xf - uVar1 & 0xff)) != 0)) {
          exchLogPrintf(__stream,DAT_3003351c,uVar1);
        }
      }
      if ((*DAT_3003344c & 0x1000000) != 0) {
        exchLogPrintf(__stream,DAT_30033520);
      }
      if ((*DAT_3003344c & 0x800000) != 0) {
        exchLogPrintf(__stream,DAT_30033524);
      }
      fclose(__stream);
      BSP_TRACE(4,0x2b,DAT_30033644,0,0,0,0,0,0);
      if (*DAT_30033648 == 0) {
        BSP_TRACE(4,0x2b,DAT_3003364c,0,0,0,0,0,0);
      }
      else {
        *(uint *)(DAT_30033650 + 0x10) = *DAT_3003344c;
        if ((*DAT_3003344c & 0xbfffffff) == 0) {
          (*(code *)*DAT_30033648)
                    (DAT_30033654,DAT_30033658,DAT_30033760,DAT_30033764,DAT_30033650,0x14);
          BSP_TRACE(4,0x2b,DAT_30033768,0,0,0,0,0,0);
        }
        else {
          (*(code *)*DAT_30033648)
                    (DAT_30033654,DAT_30033658,DAT_3003365c,DAT_30033660,DAT_30033650,0x14);
          BSP_TRACE(4,0x2b,DAT_30033664,0,0,0,0,0,0);
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * HI6451_status_isr @ 0x300328D4  (примерный размер ~544 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: BSP_TRACE, HI6451_error_log_save, HI6451_reg_read, HI6451_reg_write
 * Константы: 0x300328D4, 0xF0000000
 * Данные: DAT_3003344c, DAT_3003376c, DAT_30033814, DAT_30033818, DAT_3003381c, DAT_30033820, DAT_30033824, DAT_30033828
 * ---------------------------------------------------------------- */
void HI6451_status_isr(void)

{
  uint uVar1;
  uint uVar2;
  byte local_18 [8];
  
  local_18[0] = *DAT_3003376c;
  local_18[1] = DAT_3003376c[1];
  local_18[2] = DAT_3003376c[2];
  local_18[3] = DAT_3003376c[3];
  local_18[4] = DAT_3003376c[4];
  for (uVar2 = 0; uVar2 < 5; uVar2 = uVar2 + 1) {
    HI6451_reg_read(uVar2 + 4,local_18 + uVar2);
  }
  BSP_TRACE(0,0x2b,DAT_30033814,local_18[0],0,0,0,0,0);
  BSP_TRACE(0,0x2b,DAT_30033818,local_18[1],0,0,0,0,0);
  BSP_TRACE(0,0x2b,DAT_3003381c,local_18[2],0,0,0,0,0);
  *DAT_3003344c =
       *DAT_3003344c | *DAT_3003344c & 0xf0000000 | (uint)local_18[0] << 0xd |
       (uint)local_18[1] << 5 | (uint)local_18[2];
  for (uVar2 = 0; uVar2 < 5; uVar2 = uVar2 + 1) {
    for (uVar1 = 0; uVar1 < 8; uVar1 = uVar1 + 1) {
      if ((((uint)local_18[uVar2] & 1 << (uVar1 & 0xff)) != 0) &&
         (*(int *)(DAT_30033820 + uVar2 * 0x40 + uVar1 * 8) != 0)) {
        (**(code **)(DAT_30033820 + uVar2 * 0x40 + uVar1 * 8))
                  (*(undefined4 *)(DAT_30033824 + uVar1 * 8 + uVar2 * 0x40));
      }
    }
  }
  if (*(char *)(DAT_30033828 + 3) == '\x01') {
    HI6451_error_log_save();
  }
  for (uVar2 = 0; uVar2 < 5; uVar2 = uVar2 + 1) {
    HI6451_reg_write(uVar2 + 4,0xff);
  }
  return;
}

/* ----------------------------------------------------------------
 * HI6451_current_overflow_isr @ 0x30032AF4  (примерный размер ~300 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, HI6451_reg_read, HI6451_reg_write
 * Константы: 0x30032AF4
 * Данные: DAT_3003382c, DAT_30033830, DAT_30033834
 * ---------------------------------------------------------------- */
void HI6451_current_overflow_isr(void)

{
  undefined1 local_8 [8];
  
  local_8[0] = 0;
  HI6451_reg_read(4,local_8);
  BSP_TRACE(0,0x2b,DAT_3003382c,local_8[0],0,0,0,0,0);
  HI6451_reg_read(5,local_8);
  BSP_TRACE(0,0x2b,DAT_30033830,local_8[0],0,0,0,0,0);
  HI6451_reg_read(6,local_8);
  BSP_TRACE(0,0x2b,DAT_30033834,local_8[0],0,0,0,0,0);
  HI6451_reg_write(4,0xff);
  HI6451_reg_write(5,0xff);
  HI6451_reg_write(6,0xff);
  return;
}

/* ----------------------------------------------------------------
 * HI6451_breath_set @ 0x30032C20  (примерный размер ~416 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: HI6451_reg_write
 * Константы: 0xFFFFFFFF, 0x30032C20
 * ---------------------------------------------------------------- */
undefined4 HI6451_breath_set(byte param_1,char param_2,uint param_3)

{
  undefined4 uVar1;
  byte bStack_3;
  
  if ((param_1 == 0) || (3 < param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    if (param_2 == '\x01') {
      bStack_3 = (byte)(param_3 >> 8);
      if (param_1 == 1) {
        HI6451_reg_write(0x74,(uint)bStack_3 | (param_3 & 0xff) << 4);
        HI6451_reg_write(0x75,param_3 >> 0x10 & 0xff | (param_3 >> 0x18) << 4);
        HI6451_reg_write(0x73,3);
      }
      else if (param_1 == 2) {
        HI6451_reg_write(0x77,(uint)bStack_3 | (param_3 & 0xff) << 4);
        HI6451_reg_write(0x78,param_3 >> 0x10 & 0xff | (param_3 >> 0x18) << 4);
        HI6451_reg_write(0x76,3);
      }
      else if (param_1 == 3) {
        HI6451_reg_write(0x7a,(uint)bStack_3 | (param_3 & 0xff) << 4);
        HI6451_reg_write(0x7b,param_3 >> 0x10 & 0xff | (param_3 >> 0x18) << 4);
        HI6451_reg_write(0x79,3);
      }
    }
    else {
      if (param_2 != '\0') {
        return 0xffffffff;
      }
      if (param_1 == 1) {
        HI6451_reg_write(0x73,0);
      }
      else if (param_1 == 2) {
        HI6451_reg_write(0x76,0);
      }
      else if (param_1 == 3) {
        HI6451_reg_write(0x79,0);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * HI6451_otp_temperature_set @ 0x30032DC0  (примерный размер ~244 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: HI6451_reg_read, HI6451_reg_write
 * Вызывают: BSP_PMU_BoardInit
 * Константы: 0x30032DC0
 * ---------------------------------------------------------------- */
void HI6451_otp_temperature_set(char param_1)

{
  byte local_c [4];
  
  local_c[0] = 0;
  if (param_1 == '\0') {
    HI6451_reg_read(0x12,local_c);
    local_c[0] = local_c[0] & 0xe7;
    HI6451_reg_write(0x12,local_c[0]);
  }
  else if (param_1 == '\x01') {
    HI6451_reg_read(0x12,local_c);
    local_c[0] = local_c[0] & 0xef | 8;
    HI6451_reg_write(0x12,local_c[0]);
  }
  else if (param_1 == '\x02') {
    HI6451_reg_read(0x12,local_c);
    local_c[0] = local_c[0] & 0xf7 | 0x10;
    HI6451_reg_write(0x12,local_c[0]);
  }
  else if (param_1 == '\x03') {
    HI6451_reg_read(0x12,local_c);
    local_c[0] = local_c[0] | 0x18;
    HI6451_reg_write(0x12,local_c[0]);
  }
  return;
}

/* ----------------------------------------------------------------
 * HI6451_otp_callback @ 0x30032EB4  (примерный размер ~488 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: HI6451_reg_write, HI6451_voltage_switch, logMsg, systemError
 * Константы: 0x30032EB4, 0x40000000
 * Данные: DAT_3003344c, DAT_30033460, DAT_30033828, DAT_30033838, DAT_3003383c, DAT_30033840, DAT_30033844, DAT_30033848
 * ---------------------------------------------------------------- */
void HI6451_otp_callback(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = DAT_30033838;
  *DAT_3003344c = *DAT_3003344c | 0x40000000;
  logMsg(DAT_30033460,1,2,3,4,5,6);
  if (*(char *)(DAT_30033828 + 3) == '\x01') {
    if (*(char *)(DAT_30033828 + 1) == '\0') {
      if (uVar1 == 0) {
        return;
      }
      for (uVar2 = 1; uVar2 < 7; uVar2 = uVar2 + 1) {
        if ((uVar1 & 1 << (uVar2 + 0xf & 0xff)) != 0) {
          logMsg(DAT_3003383c,uVar2,2,3,4,5,6);
          HI6451_voltage_switch(uVar2 + 0xf,0);
        }
      }
      for (uVar2 = 1; uVar2 < 0x10; uVar2 = uVar2 + 1) {
        if ((uVar1 & 1 << (uVar2 & 0xff)) != 0) {
          if (uVar2 == 3) {
            logMsg(DAT_30033844,3,2,3,4,5,6);
          }
          else {
            logMsg(DAT_30033840,uVar2,2,3,4,5,6);
            HI6451_voltage_switch(uVar2,0);
          }
        }
      }
    }
    if (*(char *)(DAT_30033828 + 2) != '\0') {
      HI6451_reg_write(0x40,1);
      logMsg(DAT_30033848,1,2,3,4,5,6);
      systemError(0x2b,0xaa,0,0,0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * HI6451_ocp_callback @ 0x3003309C  (примерный размер ~340 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: HI6451_voltage_switch, logMsg, systemError
 * Константы: 0x3003309C
 * Данные: DAT_30033828, DAT_3003384c, DAT_30033850, DAT_30033854, DAT_30033858
 * ---------------------------------------------------------------- */
void HI6451_ocp_callback(uint param_1)

{
  uint uVar1;
  
  if ((*(char *)(DAT_30033828 + 3) == '\x01') && (param_1 = DAT_3003384c & param_1, param_1 != 0)) {
    for (uVar1 = 0; uVar1 < 0xf; uVar1 = uVar1 + 1) {
      if ((param_1 & 1 << (uVar1 & 0xff)) != 0) {
        if (uVar1 == 2) {
          logMsg(DAT_30033854,0xd,2,3,4,5,6);
          systemError(0x2b,0xaa,param_1,0,0);
        }
        else {
          logMsg(DAT_30033850,0xf - uVar1,2,3,4,5,6);
          HI6451_voltage_switch(0xf - uVar1,0);
        }
      }
    }
    for (uVar1 = 0; uVar1 < 6; uVar1 = uVar1 + 1) {
      if ((param_1 & 1 << (uVar1 + 0xf & 0xff)) != 0) {
        logMsg(DAT_30033858,6 - uVar1,2,3,4,5,6);
        HI6451_voltage_switch(0x15 - uVar1,0);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * HI6451_overvoltage_isr @ 0x300331F0  (примерный размер ~80 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x300331F0, 0x01000000
 * Данные: DAT_3003344c, DAT_3003385c
 * ---------------------------------------------------------------- */
void HI6451_overvoltage_isr(void)

{
  *DAT_3003344c = *DAT_3003344c | 0x1000000;
  logMsg(DAT_3003385c,1,2,3,4,5,6);
  return;
}

/* ----------------------------------------------------------------
 * HI6451_undervoltage_isr @ 0x30033240  (примерный размер ~80 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x30033240, 0x00800000
 * Данные: DAT_3003344c, DAT_30033860
 * ---------------------------------------------------------------- */
void HI6451_undervoltage_isr(void)

{
  *DAT_3003344c = *DAT_3003344c | 0x800000;
  logMsg(DAT_30033860,1,2,3,4,5,6);
  return;
}

/* ----------------------------------------------------------------
 * HI6451_reset_log_save @ 0x30033290  (примерный размер ~420 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 5
 * Вызывает: BSP_TRACE, exchLogPrintf, exchReadNVToGetSysTime, fclose, fopen
 * Константы: 0x30033290, 0x80000000, 0x02000000, 0x08000000, 0x04000000, 0x00400000, 0x00200000
 * Данные: DAT_3003344c, DAT_30033454, DAT_30033864, DAT_30033868, DAT_3003386c, DAT_30033870, DAT_30033874, DAT_30033878
 * ---------------------------------------------------------------- */
void HI6451_reset_log_save(void)

{
  FILE *__stream;
  undefined4 local_c;
  
  local_c = 0;
  if (*DAT_3003344c != 0) {
    exchReadNVToGetSysTime(&local_c);
    __stream = fopen(DAT_30033864,DAT_30033454);
    if (__stream == (FILE *)0x0) {
      BSP_TRACE(4,0x2b,DAT_30033868,0,0,0,0,0,0);
    }
    else {
      BSP_TRACE(4,0x2b,DAT_3003386c,*DAT_3003344c,local_c,0,0,0,0);
      exchLogPrintf(__stream,DAT_3003386c,*DAT_3003344c,local_c);
      if ((*DAT_3003344c & 0x80000000) != 0) {
        exchLogPrintf(__stream,DAT_30033870);
      }
      if ((*DAT_3003344c & 0x2000000) != 0) {
        exchLogPrintf(__stream,DAT_30033874);
      }
      if ((*DAT_3003344c & 0x8000000) != 0) {
        exchLogPrintf(__stream,DAT_30033878);
      }
      if ((*DAT_3003344c & 0x4000000) != 0) {
        exchLogPrintf(__stream,DAT_3003387c);
      }
      if ((*DAT_3003344c & 0x400000) != 0) {
        exchLogPrintf(__stream,DAT_30033880);
      }
      if ((*DAT_3003344c & 0x200000) != 0) {
        exchLogPrintf(__stream,DAT_30033884);
      }
      fclose(__stream);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * HI6451_record_startflag_save @ 0x30033434  (примерный размер ~680 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 7
 * Вызывает: BSP_TRACE, fclose, fopen, fprintf, ftell, remove, tickGet
 * Константы: 0x30033434
 * Данные: DAT_30033888, DAT_3003388c, DAT_30033890, DAT_30033894, DAT_30033898, DAT_3003389c, DAT_300338a0, DAT_300338a4
 * ---------------------------------------------------------------- */
void HI6451_record_startflag_save(void)

{
  FILE *__stream;
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  
  __stream = fopen(DAT_30033888,DAT_3003388c);
  if (__stream == (FILE *)0x0) {
    BSP_TRACE(4,0x2b,DAT_30033890,0,0,0,0,0,0);
  }
  else {
    lVar1 = ftell(__stream);
    if (lVar1 == -1) {
      BSP_TRACE(4,0x2b,DAT_30033894,0,0,0,0,0,0);
      fclose(__stream);
    }
    else {
      BSP_TRACE(1,0x2b,DAT_30033898,lVar1,0,0,0,0,0);
    }
    if (0x7ff < lVar1) {
      BSP_TRACE(4,0x2b,DAT_3003389c,0,0,0,0,0,0);
      fclose(__stream);
      iVar2 = remove(DAT_30033888);
      if (iVar2 != 0) {
        BSP_TRACE(4,0x2b,DAT_300338a0,0,0,0,0,0,0);
      }
      __stream = fopen(DAT_30033888,DAT_3003388c);
      if (__stream == (FILE *)0x0) {
        BSP_TRACE(4,0x2b,DAT_300338a4,0,0,0,0,0,0);
      }
    }
    uVar3 = tickGet();
    fprintf(__stream,DAT_300338a8,uVar3);
    fclose(__stream);
    BSP_TRACE(4,0x2b,DAT_300338ac,0,0,0,0,0,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * pmuReadReg0 @ 0x300336DC  (примерный размер ~168 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: HI6451_reg_read, printf
 * Константы: 0x300336DC
 * Данные: DAT_300338b0, DAT_300338b4, DAT_300338b8, DAT_300338bc
 * ---------------------------------------------------------------- */
void pmuReadReg0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  byte local_14 [4];
  
  local_14[0] = 0;
  uVar1 = 1;
  if (param_1 != 0) {
    uVar1 = param_1;
  }
  printf(DAT_300338b0,uVar1);
  for (uVar2 = 0; uVar2 < uVar1; uVar2 = uVar2 + 1) {
    HI6451_reg_read(0,local_14);
    if ((uVar2 & 7) == 0) {
      printf(DAT_300338b4,uVar2);
    }
    printf(DAT_300338b8,(uint)local_14[0]);
    if ((uVar2 & 7) == 7) {
      printf(DAT_300338bc);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * HI6451_reg_read_all @ 0x30033784  (примерный размер ~324 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: HI6451_reg_read, printf
 * Константы: 0x30033784
 * Данные: DAT_300338b4, DAT_300338b8, DAT_300338bc, DAT_300338c0, DAT_300338c4
 * ---------------------------------------------------------------- */
void HI6451_reg_read_all(void)

{
  uint uVar1;
  uint uVar2;
  byte local_c [4];
  
  local_c[0] = 0;
  printf(DAT_300338c0);
  for (uVar2 = 0; (int)uVar2 < 0x6f; uVar2 = uVar2 + 1) {
    HI6451_reg_read(uVar2,local_c);
    if ((uVar2 & 7) == 0) {
      printf(DAT_300338b4,uVar2);
    }
    printf(DAT_300338b8,(uint)local_c[0]);
    uVar1 = uVar2 & 7;
    if ((int)uVar2 < 0) {
      uVar1 = -(-uVar2 & 7);
    }
    if (uVar1 == 7) {
      printf(DAT_300338bc);
    }
  }
  printf(DAT_300338c4);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_Init @ 0x300338C8  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: HI6451_init
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x300338C8
 * ---------------------------------------------------------------- */
undefined4 BSP_PMU_Init(void)

{
  undefined4 uVar1;
  
  uVar1 = HI6451_init();
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_PMU_RegWrite @ 0x300338DC  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: HI6451_reg_write
 * Вызывают: BSP_PMU_BoardInit
 * Константы: 0x300338DC
 * ---------------------------------------------------------------- */
void BSP_PMU_RegWrite(undefined1 param_1,undefined1 param_2)

{
  HI6451_reg_write(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_RegWriteMask @ 0x300338F8  (примерный размер ~36 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 1
 * Вызывает: HI6451_reg_write_mask
 * Вызывают: BSP_PMU_AptDisable, BSP_PMU_AptEnable, BSP_PMU_BoardInit, BSP_PMU_ModeSwitch
 * Константы: 0x300338F8
 * ---------------------------------------------------------------- */
void BSP_PMU_RegWriteMask(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  HI6451_reg_write_mask(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_RegRead @ 0x3003391C  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: HI6451_reg_read
 * Вызывают: BSP_PMU_AptIsEnable, BSP_PMU_IsWarmStart
 * Константы: 0x3003391C
 * ---------------------------------------------------------------- */
void BSP_PMU_RegRead(undefined1 param_1,undefined4 param_2)

{
  HI6451_reg_read(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_LDOCtrl @ 0x30033938  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 7 | Вызывает: 1
 * Вызывает: HI6451_voltage_switch
 * Вызывают: BSP_PMU_DEVS_Ctrl, BSP_PMU_LDOOff, BSP_PMU_LDOOn, BSP_PMU_RF_OnOff, sdmmcCheckStatus, sdmmcDrvHwInit, sdmmcISRInit
 * Константы: 0x30033938
 * ---------------------------------------------------------------- */
void BSP_PMU_LDOCtrl(undefined1 param_1,int param_2)

{
  HI6451_voltage_switch(param_1,param_2 == 1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_BuckCtrl @ 0x30033960  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: HI6451_buck_switch
 * Вызывают: BSP_PMU_BuckOff, BSP_PMU_BuckOn
 * Константы: 0x30033960
 * ---------------------------------------------------------------- */
void BSP_PMU_BuckCtrl(undefined1 param_1,int param_2)

{
  HI6451_buck_switch(param_1,param_2 == 1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_DRCtrl @ 0x30033988  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: HI6451_current_switch
 * Вызывают: BSP_PMU_DROff, BSP_PMU_DROn
 * Константы: 0x30033988
 * ---------------------------------------------------------------- */
void BSP_PMU_DRCtrl(undefined1 param_1,int param_2)

{
  HI6451_current_switch(param_1,param_2 == 1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_LDOVoltSet @ 0x300339B0  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 1
 * Вызывает: HI6451_voltage_set
 * Вызывают: BSP_PMU_BoardInit, BSP_PMU_VolAdjust_ForSci, efuseWrite, sdmmcISRInit
 * Константы: 0x300339B0
 * ---------------------------------------------------------------- */
void BSP_PMU_LDOVoltSet(undefined1 param_1,undefined2 param_2)

{
  HI6451_voltage_set(param_1,param_2);
  return;
}

