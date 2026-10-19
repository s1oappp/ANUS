/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : bsp — BSP Huawei: GPIO, HKADC, PMU HI6451, WDT, LED, SPI/SSI, таймеры, питание
 * Часть  : 3 (функций: 150, адреса 0x300339CC..0x30077144)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * BSP_PMU_LDOVoltGet @ 0x300339CC  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: HI6451_voltage_get
 * Константы: 0x300339CC
 * ---------------------------------------------------------------- */
void BSP_PMU_LDOVoltGet(undefined1 param_1)

{
  HI6451_voltage_get(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_BuckVoltSet @ 0x300339E0  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: HI6451_buck_voltage_set
 * Вызывают: BSP_PMU_BoardInit, BSP_PMU_ModeSwitch
 * Константы: 0x300339E0
 * ---------------------------------------------------------------- */
void BSP_PMU_BuckVoltSet(undefined1 param_1,undefined2 param_2)

{
  HI6451_buck_voltage_set(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_BuckVoltGet @ 0x300339FC  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: HI6451_buck_voltage_get
 * Константы: 0x300339FC
 * ---------------------------------------------------------------- */
void BSP_PMU_BuckVoltGet(undefined1 param_1)

{
  HI6451_buck_voltage_get(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_DrCurrentSet @ 0x30033A10  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: HI6451_current_set
 * Константы: 0x30033A10
 * ---------------------------------------------------------------- */
void BSP_PMU_DrCurrentSet(undefined4 param_1,undefined2 param_2)

{
  HI6451_current_set(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_DrCurrentGet @ 0x30033A2C  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: HI6451_current_get
 * Константы: 0x30033A2C
 * ---------------------------------------------------------------- */
void BSP_PMU_DrCurrentGet(undefined4 param_1)

{
  HI6451_current_get(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_AptEnable @ 0x30033A40  (примерный размер ~108 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_PMU_RegWriteMask, NVM_Read
 * Константы: 0x30033A40, 0xFFFFFFFF
 * Данные: DAT_300343e8, DAT_300343ec, DAT_300343f0
 * ---------------------------------------------------------------- */
undefined4 BSP_PMU_AptEnable(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*DAT_300343e8 == 0) {
    iVar1 = NVM_Read(DAT_300343f0,DAT_300343ec,4);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    *DAT_300343e8 = 1;
  }
  if (*DAT_300343ec == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = BSP_PMU_RegWriteMask(0x1a,8,8);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_PMU_AptDisable @ 0x30033AAC  (примерный размер ~16 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_PMU_RegWriteMask
 * Константы: 0x30033AAC
 * ---------------------------------------------------------------- */
void BSP_PMU_AptDisable(void)

{
  BSP_PMU_RegWriteMask(0x1a,0,8);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_AptIsEnable @ 0x30033ABC  (примерный размер ~60 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_PMU_RegRead
 * Константы: 0x30033ABC
 * ---------------------------------------------------------------- */
bool BSP_PMU_AptIsEnable(void)

{
  byte local_c [4];
  
  local_c[0] = 0;
  BSP_PMU_RegRead(0x1a,local_c);
  return (local_c[0] & 8) != 0;
}

/* ----------------------------------------------------------------
 * pmuLDOVoltSet @ 0x30033AF8  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: HI6451_voltage_set
 * Константы: 0x30033AF8
 * ---------------------------------------------------------------- */
void pmuLDOVoltSet(undefined1 param_1,undefined2 param_2)

{
  HI6451_voltage_set(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_LDOOn @ 0x30033BB0  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: BSP_PMU_LDOCtrl
 * Вызывают: BSP_PMU_BoardInit, efuseWrite
 * Константы: 0x30033BB0
 * ---------------------------------------------------------------- */
void BSP_PMU_LDOOn(undefined4 param_1)

{
  BSP_PMU_LDOCtrl(param_1,1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_LDOOff @ 0x30033BC8  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: BSP_PMU_LDOCtrl
 * Вызывают: BSP_PMU_BoardInit, efuseWrite
 * Константы: 0x30033BC8
 * ---------------------------------------------------------------- */
void BSP_PMU_LDOOff(undefined4 param_1)

{
  BSP_PMU_LDOCtrl(param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_BuckOn @ 0x30033BE0  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: BSP_PMU_BuckCtrl
 * Вызывают: BSP_PMU_BoardInit
 * Константы: 0x30033BE0
 * ---------------------------------------------------------------- */
void BSP_PMU_BuckOn(undefined4 param_1)

{
  BSP_PMU_BuckCtrl(param_1,1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_BuckOff @ 0x30033BF8  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_PMU_BuckCtrl
 * Константы: 0x30033BF8
 * ---------------------------------------------------------------- */
void BSP_PMU_BuckOff(undefined4 param_1)

{
  BSP_PMU_BuckCtrl(param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_DROn @ 0x30033C10  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_PMU_DRCtrl
 * Константы: 0x30033C10
 * ---------------------------------------------------------------- */
void BSP_PMU_DROn(undefined4 param_1)

{
  BSP_PMU_DRCtrl(param_1,1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_DROff @ 0x30033C28  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_PMU_DRCtrl
 * Константы: 0x30033C28
 * ---------------------------------------------------------------- */
void BSP_PMU_DROff(undefined4 param_1)

{
  BSP_PMU_DRCtrl(param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_VolAdjust_ForSci @ 0x30033C48  (примерный размер ~60 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_PMU_LDOVoltSet
 * Константы: 0x30033C48
 * ---------------------------------------------------------------- */
undefined4 BSP_PMU_VolAdjust_ForSci(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = BSP_PMU_LDOVoltSet(0xb,300);
  }
  else {
    uVar1 = BSP_PMU_LDOVoltSet(0xb,0xb4);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_PMU_VolAdjust_ForSDIO @ 0x30033C84  (примерный размер ~60 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: pmSetLDOVltg
 * Константы: 0x30033C84
 * ---------------------------------------------------------------- */
undefined4 BSP_PMU_VolAdjust_ForSDIO(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = pmSetLDOVltg(7,300);
  }
  else {
    uVar1 = pmSetLDOVltg(7,0xb4);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_PMU_RfAdjustVoltage @ 0x30033CC0  (примерный размер ~36 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30033CC0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 BSP_PMU_RfAdjustVoltage(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_PMU_RF_OnOff @ 0x30033CE4  (примерный размер ~36 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: BSP_PMU_LDOCtrl
 * Вызывают: BSP_PMU_DEVS_Ctrl
 * Константы: 0x30033CE4
 * ---------------------------------------------------------------- */
undefined4 BSP_PMU_RF_OnOff(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = BSP_PMU_LDOCtrl(5,param_1);
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_PMU_WiFi_PwrDown @ 0x30033D08  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30033D08
 * ---------------------------------------------------------------- */
void BSP_PMU_WiFi_PwrDown(void)

{
  return;
}

/* ----------------------------------------------------------------
 * BSP_PMU_DEVS_Ctrl @ 0x30033D0C  (примерный размер ~244 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_PMU_LDOCtrl, BSP_PMU_RF_OnOff
 * Константы: 0x30033D0C
 * Данные: DAT_300343f4, DAT_300343f8
 * ---------------------------------------------------------------- */
undefined4 BSP_PMU_DEVS_Ctrl(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  
  uVar1 = DAT_300343f4;
  if ((param_1 < 5) && (param_2 < 2)) {
    bVar3 = param_2 == 0;
    if (param_1 == 2) {
      uVar1 = BSP_PMU_LDOCtrl(10,bVar3);
      iVar2 = DAT_300343f8;
    }
    else {
      uVar1 = 0;
      iVar2 = DAT_300343f8;
      if (param_1 < 3) {
        if (param_1 == 0) {
          uVar1 = BSP_PMU_RF_OnOff(bVar3);
          iVar2 = DAT_300343f8;
        }
        else if (param_1 == 1) {
          uVar1 = BSP_PMU_LDOCtrl(3,bVar3);
          iVar2 = DAT_300343f8;
        }
      }
      else if (param_1 == 3) {
        uVar1 = BSP_PMU_LDOCtrl(0xb,bVar3);
        iVar2 = DAT_300343f8;
      }
      else if (param_1 == 4) {
        uVar1 = BSP_PMU_LDOCtrl(0xb,bVar3);
        iVar2 = DAT_300343f8;
      }
    }
    for (; -1 < iVar2; iVar2 = iVar2 + -1) {
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_PMU_IsWarmStart @ 0x30033E00  (примерный размер ~48 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_PMU_RegRead
 * Константы: 0x30033E00
 * ---------------------------------------------------------------- */
bool BSP_PMU_IsWarmStart(void)

{
  byte local_8 [8];
  
  BSP_PMU_RegRead(1,local_8);
  return (local_8[0] & 2) != 0;
}

/* ----------------------------------------------------------------
 * BSP_PMU_ModeSwitch @ 0x30033E50  (примерный размер ~196 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_PMU_BuckVoltSet, BSP_PMU_RegWriteMask, BSP_TRACE
 * Константы: 0x30033E50, 0xFFFFFFFF
 * Данные: DAT_300343fc, DAT_30034400, DAT_30034404
 * ---------------------------------------------------------------- */
undefined4 BSP_PMU_ModeSwitch(int param_1)

{
  if (param_1 != 0) {
    if (param_1 == 1) {
      BSP_PMU_RegWriteMask(0x27,0,0x1f);
      BSP_PMU_BuckVoltSet(4,DAT_30034400);
      BSP_PMU_RegWriteMask(0x23,1,1);
      return 0;
    }
    if ((param_1 != 2) && (param_1 != 3)) {
      BSP_TRACE(4,0x2b,DAT_30034404,param_1);
      return 0xffffffff;
    }
  }
  BSP_PMU_RegWriteMask(0x27,0x15,0x1f);
  BSP_PMU_BuckVoltSet(4,DAT_300343fc);
  BSP_PMU_RegWriteMask(0x27,0x55,0x7f);
  BSP_PMU_RegWriteMask(0x23,0,1);
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_PMU_BoardInit @ 0x30033F14  (примерный размер ~1340 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 19
 * Вызывает: BSP_GPIO_DrcSet, BSP_GPIO_ValSet, BSP_HwGetVerMain, BSP_PMU_BuckOn, BSP_PMU_BuckVoltSet, BSP_PMU_LDOOff, BSP_PMU_LDOOn, BSP_PMU_LDOVoltSet, BSP_PMU_RegWrite, BSP_PMU_RegWriteMask, BSP_TRACE, HI6451_int_install, HI6451_otp_temperature_set, HI6451_reg_read
 *           ...
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x30033F14
 * Данные: DAT_300343fc, DAT_30034408, DAT_3003440c, DAT_30034410, DAT_30034414, DAT_30034418, DAT_3003441c, DAT_30034420
 * ---------------------------------------------------------------- */
void BSP_PMU_BoardInit(void)

{
  ushort uVar1;
  int iVar2;
  byte local_10 [4];
  
  uVar1 = BSP_HwGetVerMain();
  BSP_PMU_RegWriteMask(10,0xc,0xc);
  HI6451_reg_write(2,0xc);
  HI6451_reg_write(0x41,0xc);
  HI6451_int_install(1,2,DAT_30034408,0);
  HI6451_int_install(1,3,DAT_3003440c,0);
  HI6451_reg_read(8,local_10);
  if ((local_10[0] & 5) == 0) {
    BSP_PMU_RegWriteMask(10,4,0xc);
  }
  else {
    HI6451_usb_insert_proc(0);
    BSP_PMU_RegWriteMask(10,8,0xc);
  }
  iVar2 = NVM_Read(DAT_30034414,DAT_30034410,4);
  if (iVar2 == 0) {
    BSP_TRACE(4,0x2b,DAT_3003441c,*DAT_30034410,DAT_30034410[1],DAT_30034410[2],DAT_30034410[3],0,0)
    ;
  }
  else {
    BSP_TRACE(4,0x2b,DAT_30034418,0,0,0,0,0,0);
  }
  HI6451_otp_temperature_set(*DAT_30034410);
  intConnect(0x7f,DAT_30034420,0);
  intEnable(0x7f);
  if ((((((uVar1 == DAT_30034424) || (uVar1 == 0x200)) || (uVar1 == DAT_30034428)) ||
       ((uVar1 == 0x204 || (uVar1 == DAT_3003442c)))) || (uVar1 == DAT_30034430)) ||
     (((uVar1 == DAT_30034434 || (uVar1 == DAT_30034438)) ||
      ((uVar1 == DAT_3003443c || (uVar1 == DAT_30034440)))))) {
    BSP_PMU_RegWrite(0x4b,6);
  }
  else {
    BSP_PMU_RegWrite(0x4b,7);
  }
  if (uVar1 == DAT_30034444) {
    BSP_PMU_LDOVoltSet(5,0xdc);
    BSP_PMU_LDOOn(5);
    BSP_PMU_LDOVoltSet(7,300);
    BSP_PMU_LDOOn(7);
    BSP_PMU_LDOVoltSet(8,0x78);
    BSP_PMU_LDOOn(8);
    BSP_PMU_LDOVoltSet(0xd,0xfa);
    BSP_PMU_LDOOn(0xd);
  }
  else if (uVar1 == DAT_30034448) {
    BSP_PMU_LDOVoltSet(5,0xb4);
    BSP_PMU_LDOOn(5);
  }
  else if (((((uVar1 == DAT_30034424) || (uVar1 == 0x200)) || (uVar1 == DAT_30034428)) ||
           (((uVar1 == 0x204 || (uVar1 == DAT_3003442c)) ||
            ((uVar1 == DAT_30034430 || ((uVar1 == DAT_30034434 || (uVar1 == DAT_30034438)))))))) ||
          ((uVar1 == DAT_3003443c || (uVar1 == DAT_30034440)))) {
    BSP_PMU_LDOVoltSet(5,0xdc);
    BSP_PMU_LDOOn(5);
    BSP_PMU_LDOOff(4);
    BSP_PMU_LDOOff(8);
  }
  else if (((uVar1 == 0) || (uVar1 == 1)) || (uVar1 == 3)) {
    BSP_PMU_LDOVoltSet(0xd,0x104);
    BSP_PMU_LDOOff(5);
  }
  BSP_PMU_LDOOn(0xe);
  if (*DAT_3003444c == 0x10) {
    BSP_PMU_BuckVoltSet(1,0x5a);
  }
  else if (uVar1 == DAT_30034444) {
    BSP_PMU_BuckVoltSet(1,0x6e);
  }
  else {
    BSP_PMU_BuckVoltSet(1,100);
  }
  if (uVar1 == DAT_30034444) {
    BSP_PMU_BuckVoltSet(2,0x78);
  }
  BSP_PMU_BuckVoltSet(4,DAT_300343fc);
  BSP_PMU_BuckOn(4);
  if (uVar1 == DAT_30034444) {
    BSP_PMU_BuckVoltSet(5,0xb4);
  }
  else if (((uVar1 != 0) && (uVar1 != 1)) && (uVar1 != 3)) {
    BSP_PMU_BuckVoltSet(5,0xb4);
  }
  BSP_PMU_BuckOn(5);
  if (((uVar1 == 0) || (uVar1 == 1)) || (uVar1 == 3)) {
    BSP_GPIO_DrcSet(2,1,1);
    BSP_GPIO_ValSet(2,1,1);
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_PinModeCtrl @ 0x300348C4  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300348C4
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_PinModeCtrl(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_IntMaskSet @ 0x300348CC  (примерный размер ~180 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: BSP_GPIO_Init
 * Константы: 0xFFFFFFFF, 0x300348CC
 * Данные: DAT_300357a4, DAT_300357a8, DAT_300357ac, DAT_300357b0
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_IntMaskSet(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_300357a4 == 0) {
    logMsg(DAT_300357a8,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (param_1 < 6) {
    iVar2 = *(int *)(DAT_300357b0 + param_1 * 4);
    *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) & ~param_2;
    uVar1 = 0;
  }
  else {
    logMsg(DAT_300357ac,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_IntStateClear @ 0x30034980  (примерный размер ~180 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: BSP_GPIO_Init, GPIO_Int_handle
 * Константы: 0xFFFFFFFF, 0x30034980
 * Данные: DAT_300357a4, DAT_300357a8, DAT_300357ac, DAT_300357b0
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_IntStateClear(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_300357a4 == 0) {
    logMsg(DAT_300357a8,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (param_1 < 6) {
    iVar2 = *(int *)(DAT_300357b0 + param_1 * 4);
    *(uint *)(iVar2 + 0x4c) = param_2 | *(uint *)(iVar2 + 0x4c);
    uVar1 = 0;
  }
  else {
    logMsg(DAT_300357ac,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_Init @ 0x30034A34  (примерный размер ~144 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 5
 * Вызывает: BSP_GPIO_IntMaskSet, BSP_GPIO_IntStateClear, intConnect, intEnable, memset
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0xFFFFFFFF, 0x30034A34
 * Данные: DAT_300357a4, DAT_300357b4, DAT_300357b8, DAT_300357bc, DAT_300357c0
 * ---------------------------------------------------------------- */
void BSP_GPIO_Init(void)

{
  uint uVar1;
  
  if (*DAT_300357a4 != 1) {
    *DAT_300357a4 = 1;
    memset(DAT_300357b4,0,0x300);
    memset(DAT_300357b8,0,0x300);
    for (uVar1 = 0; uVar1 < 6; uVar1 = uVar1 + 1) {
      BSP_GPIO_IntStateClear(uVar1,0xffffffff);
      BSP_GPIO_IntMaskSet(uVar1,0xffffffff);
      intConnect(*(undefined4 *)(DAT_300357bc + uVar1 * 4),DAT_300357c0,uVar1);
      intEnable(*(undefined4 *)(DAT_300357bc + uVar1 * 4));
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_DrcSet @ 0x30034AC4  (примерный размер ~276 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: BSP_PMU_BoardInit, hwVerGet
 * Константы: 0xFFFFFFFF, 0x30034AC4
 * Данные: DAT_300357a4, DAT_300357ac, DAT_300357b0, DAT_300357c4, DAT_300357c8
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_DrcSet(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_300357a4 == 0) {
    logMsg(DAT_300357c4,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (param_1 < 6) {
    iVar2 = *(int *)(DAT_300357b0 + param_1 * 4);
    if (param_3 == 1) {
      *(uint *)(iVar2 + 4) = param_2 | *(uint *)(iVar2 + 4);
      uVar1 = 0;
    }
    else if (param_3 == 0) {
      *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) & ~param_2;
      uVar1 = 0;
    }
    else {
      logMsg(DAT_300357c8,param_3,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
  }
  else {
    logMsg(DAT_300357ac,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_DrcGet @ 0x30034BD8  (примерный размер ~172 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: BSP_GPIO_ValSet, hwVerGet
 * Константы: 0xFFFFFFFF, 0x30034BD8
 * Данные: DAT_300357a4, DAT_300357ac, DAT_300357b0, DAT_300357cc
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_DrcGet(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*DAT_300357a4 == 0) {
    logMsg(DAT_300357cc,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (param_1 < 6) {
    *param_2 = *(undefined4 *)(*(int *)(DAT_300357b0 + param_1 * 4) + 4);
    uVar1 = 0;
  }
  else {
    logMsg(DAT_300357ac,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_ValSet @ 0x30034C84  (примерный размер ~412 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_GPIO_DrcGet, logMsg
 * Вызывают: BSP_PMU_BoardInit
 * Константы: 0xFFFFFFFF, 0x30034C84
 * Данные: DAT_300357a4, DAT_300357ac, DAT_300357b0, DAT_300357d0, DAT_300357d4, DAT_300357d8
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_ValSet(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint local_28;
  
  uVar4 = 1;
  local_28 = 0;
  if (*DAT_300357a4 == 0) {
    logMsg(DAT_300357d0,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (param_1 < 6) {
    puVar3 = *(uint **)(DAT_300357b0 + param_1 * 4);
    BSP_GPIO_DrcGet(param_1,&local_28);
    for (uVar2 = 0; uVar2 < 0x20; uVar2 = uVar2 + 1) {
      if (uVar2 != 0) {
        uVar4 = uVar4 << 1;
      }
      if (((param_2 & uVar4) != 0) && ((local_28 & uVar4) == 0)) {
        logMsg(DAT_300357d4,uVar2,0,0,0,0,0);
        return 0xffffffff;
      }
    }
    if (param_3 == 0) {
      *puVar3 = *puVar3 & ~param_2;
    }
    else {
      if (param_3 != 1) {
        logMsg(DAT_300357d8,param_3,0,0,0,0,0);
        return 0xffffffff;
      }
      *puVar3 = param_2 | *puVar3;
    }
    uVar1 = 0;
  }
  else {
    logMsg(DAT_300357ac,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_ValGet @ 0x30034E20  (примерный размер ~176 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: hwVerGet
 * Константы: 0xFFFFFFFF, 0x30034E20
 * Данные: DAT_300357a4, DAT_300357ac, DAT_300357b0, DAT_300357dc
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_ValGet(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*DAT_300357a4 == 0) {
    logMsg(DAT_300357dc,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (param_1 < 6) {
    *param_2 = *(undefined4 *)(*(int *)(DAT_300357b0 + param_1 * 4) + 0x50);
    uVar1 = 0;
  }
  else {
    logMsg(DAT_300357ac,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_IntUnMaskSet @ 0x30034ED0  (примерный размер ~180 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0xFFFFFFFF, 0x30034ED0
 * Данные: DAT_300357a4, DAT_300357a8, DAT_300357ac, DAT_300357b0
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_IntUnMaskSet(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_300357a4 == 0) {
    logMsg(DAT_300357a8,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (param_1 < 6) {
    iVar2 = *(int *)(DAT_300357b0 + param_1 * 4);
    *(uint *)(iVar2 + 0x30) = param_2 | *(uint *)(iVar2 + 0x30);
    uVar1 = 0;
  }
  else {
    logMsg(DAT_300357ac,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_IntStateGet @ 0x30034F84  (примерный размер ~176 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: GPIO_Int_handle
 * Константы: 0xFFFFFFFF, 0x30034F84
 * Данные: DAT_300357a4, DAT_300357a8, DAT_300357ac, DAT_300357b0
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_IntStateGet(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*DAT_300357a4 == 0) {
    logMsg(DAT_300357a8,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (param_1 < 6) {
    *param_2 = *(undefined4 *)(*(int *)(DAT_300357b0 + param_1 * 4) + 0x40);
    uVar1 = 0;
  }
  else {
    logMsg(DAT_300357ac,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_RawIntStateGet @ 0x30035034  (примерный размер ~176 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0xFFFFFFFF, 0x30035034
 * Данные: DAT_300357a4, DAT_300357a8, DAT_300357ac, DAT_300357b0
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_RawIntStateGet(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*DAT_300357a4 == 0) {
    logMsg(DAT_300357a8,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (param_1 < 6) {
    *param_2 = *(undefined4 *)(*(int *)(DAT_300357b0 + param_1 * 4) + 0x44);
    uVar1 = 0;
  }
  else {
    logMsg(DAT_300357ac,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_IntTriggerSet @ 0x300350E4  (примерный размер ~380 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0xFFFFFFFF, 0x300350E4
 * Данные: DAT_300357a4, DAT_300357a8, DAT_300357ac, DAT_300357b0, DAT_300357e0
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_IntTriggerSet(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_300357a4 == 0) {
    logMsg(DAT_300357a8,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if ((param_1 < 6) && (param_3 < 6)) {
    iVar2 = *(int *)(DAT_300357b0 + param_1 * 4);
    if (param_3 == 1) {
      *(uint *)(iVar2 + 0x38) = *(uint *)(iVar2 + 0x38) & ~param_2;
      *(uint *)(iVar2 + 0x3c) = param_2 | *(uint *)(iVar2 + 0x3c);
    }
    else if (param_3 == 2) {
      *(uint *)(iVar2 + 0x38) = *(uint *)(iVar2 + 0x38) & ~param_2;
      *(uint *)(iVar2 + 0x3c) = *(uint *)(iVar2 + 0x3c) & ~param_2;
    }
    else if (param_3 == 4) {
      *(uint *)(iVar2 + 0x38) = param_2 | *(uint *)(iVar2 + 0x38);
      *(uint *)(iVar2 + 0x3c) = param_2 | *(uint *)(iVar2 + 0x3c);
    }
    else {
      if (param_3 != 5) {
        logMsg(DAT_300357e0,param_3,0,0,0,0,0);
        return 0xffffffff;
      }
      *(uint *)(iVar2 + 0x38) = param_2 | *(uint *)(iVar2 + 0x38);
      *(uint *)(iVar2 + 0x3c) = *(uint *)(iVar2 + 0x3c) & ~param_2;
    }
    uVar1 = 0;
  }
  else {
    logMsg(DAT_300357ac,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_IntInstall @ 0x30035260  (примерный размер ~272 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0xFFFFFFFF, 0x30035260
 * Данные: DAT_300357a4, DAT_300357a8, DAT_300357ac, DAT_300357b4, DAT_300357b8
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_IntInstall(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 1;
  if (*DAT_300357a4 == 0) {
    logMsg(DAT_300357a8,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (param_1 < 6) {
    for (uVar3 = 0; uVar3 < 0x20; uVar3 = uVar3 + 1) {
      if (uVar3 != 0) {
        uVar2 = uVar2 << 1;
      }
      if ((param_2 & uVar2) != 0) {
        *(undefined4 *)(DAT_300357b4 + param_1 * 0x80 + uVar3 * 4) = 0;
        *(undefined4 *)(DAT_300357b8 + param_1 * 0x80 + uVar3 * 4) = param_4;
        if (param_3 != 0) {
          *(int *)(DAT_300357b4 + param_1 * 0x80 + uVar3 * 4) = param_3;
        }
      }
    }
    uVar1 = 0;
  }
  else {
    logMsg(DAT_300357ac,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_IntUnInstall @ 0x30035370  (примерный размер ~252 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0xFFFFFFFF, 0x30035370
 * Данные: DAT_300357a4, DAT_300357b4, DAT_300357b8, DAT_300357e4, DAT_300357e8
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_IntUnInstall(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 1;
  if (*DAT_300357a4 == 0) {
    logMsg(DAT_300357e4,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (param_1 < 6) {
    for (uVar3 = 0; uVar3 < 0x20; uVar3 = uVar3 + 1) {
      if (uVar3 != 0) {
        uVar2 = uVar2 << 1;
      }
      if ((param_2 & uVar2) != 0) {
        *(undefined4 *)(DAT_300357b4 + param_1 * 0x80 + uVar3 * 4) = 0;
        *(undefined4 *)(DAT_300357b8 + param_1 * 0x80 + uVar3 * 4) = 0;
      }
    }
    uVar1 = 0;
  }
  else {
    logMsg(DAT_300357e8,param_1,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_GetVersion @ 0x3003554C  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_OM_GetHwVersion
 * Константы: 0x3003554C
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_GetVersion(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = 0;
  *param_2 = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_PWC_Reg_Save @ 0x30035574  (примерный размер ~236 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30035574
 * Данные: DAT_300357b0, DAT_300357f0, DAT_300357f4, DAT_300357f8, DAT_300357fc, DAT_30035800, DAT_30035804, DAT_30035808
 * ---------------------------------------------------------------- */
void BSP_GPIO_PWC_Reg_Save(void)

{
  uint uVar1;
  
  for (uVar1 = 1; uVar1 < 6; uVar1 = uVar1 + 1) {
    if (uVar1 != 2) {
      *(undefined4 *)(uVar1 * 0x1c + DAT_300357f0) = **(undefined4 **)(DAT_300357b0 + uVar1 * 4);
      *(undefined4 *)(uVar1 * 0x1c + DAT_300357f4) =
           *(undefined4 *)(*(int *)(DAT_300357b0 + uVar1 * 4) + 4);
      *(undefined4 *)(uVar1 * 0x1c + DAT_300357f8) =
           *(undefined4 *)(*(int *)(DAT_300357b0 + uVar1 * 4) + 0x30);
      *(undefined4 *)(uVar1 * 0x1c + DAT_300357fc) =
           *(undefined4 *)(*(int *)(DAT_300357b0 + uVar1 * 4) + 0x34);
      *(undefined4 *)(uVar1 * 0x1c + DAT_30035800) =
           *(undefined4 *)(*(int *)(DAT_300357b0 + uVar1 * 4) + 0x38);
      *(undefined4 *)(uVar1 * 0x1c + DAT_30035804) =
           *(undefined4 *)(*(int *)(DAT_300357b0 + uVar1 * 4) + 0x3c);
      *(undefined4 *)(uVar1 * 0x1c + DAT_30035808) =
           *(undefined4 *)(*(int *)(DAT_300357b0 + uVar1 * 4) + 0x50);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_PWC_Reg_Restore @ 0x30035660  (примерный размер ~316 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30035660
 * Данные: DAT_300357b0, DAT_300357f0, DAT_300357f4, DAT_300357f8, DAT_300357fc, DAT_30035800, DAT_30035804, DAT_30035808
 * ---------------------------------------------------------------- */
void BSP_GPIO_PWC_Reg_Restore(void)

{
  uint uVar1;
  uint *puVar2;
  
  for (uVar1 = 1; uVar1 < 6; uVar1 = uVar1 + 1) {
    if (uVar1 != 2) {
      puVar2 = *(uint **)(DAT_300357b0 + uVar1 * 4);
      *puVar2 = *puVar2 | *(uint *)(DAT_300357f0 + uVar1 * 0x1c);
      puVar2 = (uint *)(*(int *)(DAT_300357b0 + uVar1 * 4) + 4);
      *puVar2 = *puVar2 | *(uint *)(DAT_300357f4 + uVar1 * 0x1c);
      puVar2 = (uint *)(*(int *)(DAT_300357b0 + uVar1 * 4) + 0x30);
      *puVar2 = *puVar2 | *(uint *)(DAT_300357f8 + uVar1 * 0x1c);
      puVar2 = (uint *)(*(int *)(DAT_300357b0 + uVar1 * 4) + 0x34);
      *puVar2 = *puVar2 | *(uint *)(DAT_300357fc + uVar1 * 0x1c);
      puVar2 = (uint *)(*(int *)(DAT_300357b0 + uVar1 * 4) + 0x38);
      *puVar2 = *puVar2 | *(uint *)(DAT_30035800 + uVar1 * 0x1c);
      puVar2 = (uint *)(*(int *)(DAT_300357b0 + uVar1 * 4) + 0x3c);
      *puVar2 = *puVar2 | *(uint *)(DAT_30035804 + uVar1 * 0x1c);
      puVar2 = (uint *)(*(int *)(DAT_300357b0 + uVar1 * 4) + 0x50);
      *puVar2 = *puVar2 | *(uint *)(DAT_30035808 + uVar1 * 0x1c);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_GPIO_GetSignal @ 0x3003579C  (примерный размер ~112 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3003579C
 * ---------------------------------------------------------------- */
undefined4 BSP_GPIO_GetSignal(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * LED_DefaultCallback @ 0x3003580C  (примерный размер ~12 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3003580C
 * Данные: DAT_30035f7c
 * ---------------------------------------------------------------- */
undefined4 LED_DefaultCallback(void)

{
  return *DAT_30035f7c;
}

/* ----------------------------------------------------------------
 * BSP_TLED_LedOff @ 0x30035818  (примерный размер ~36 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: pmDROFF
 * Вызывают: BSP_TLED_LedTask
 * Константы: 0x30035818
 * ---------------------------------------------------------------- */
undefined4 BSP_TLED_LedOff(void)

{
  pmDROFF(1);
  pmDROFF(2);
  pmDROFF(3);
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_TLED_LedSwitch @ 0x3003583C  (примерный размер ~240 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: pmDROFF, pmDRON
 * Вызывают: BSP_TLED_LedTask
 * Константы: 0x3003583C
 * Данные: DAT_30035f80
 * ---------------------------------------------------------------- */
void BSP_TLED_LedSwitch(uint param_1,uint param_2)

{
  if ((*DAT_30035f80 != 0) || ((param_1 & 4) != (param_2 & 4))) {
    if ((param_2 & 4) == 0) {
      pmDROFF(1);
    }
    else {
      pmDRON(1);
    }
  }
  if ((*DAT_30035f80 != 0) || ((param_1 & 2) != (param_2 & 2))) {
    if ((param_2 & 2) == 0) {
      pmDROFF(2);
    }
    else {
      pmDRON(2);
    }
  }
  if ((*DAT_30035f80 != 0) || ((param_1 & 1) != (param_2 & 1))) {
    if ((param_2 & 1) == 0) {
      pmDROFF(3);
    }
    else {
      pmDRON(3);
    }
  }
  *DAT_30035f80 = 0;
  return;
}

/* ----------------------------------------------------------------
 * BSP_TLED_LedStateFuncReg @ 0x3003592C  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 0
 * Вызывают: BSP_LED_TST_Init, BSP_MNTN_LedStateFuncReg
 * Константы: 0x3003592C
 * Данные: DAT_30035f84
 * ---------------------------------------------------------------- */
void BSP_TLED_LedStateFuncReg(undefined4 param_1)

{
  *DAT_30035f84 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * BSP_TLED_LedTask @ 0x30035944  (примерный размер ~540 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 6
 * Вызывает: BSP_TLED_LedOff, BSP_TLED_LedSwitch, BSP_TRACE, eventReceive, softtimer_create_timer, softtimer_del_timer
 * Константы: 0x30035944, 0xFFFFFFFF
 * Данные: DAT_30035f88, DAT_30035f8c, DAT_30035f90, DAT_30035f94, DAT_30035f98, DAT_30035f9c, DAT_30035fa0, DAT_30035fa4
 * ---------------------------------------------------------------- */
void BSP_TLED_LedTask(void)

{
  byte bVar1;
  int iVar2;
  int local_10;
  uint local_c;
  
  local_c = 0;
  local_10 = 0;
  do {
    bVar1 = DAT_30035f88[2];
    iVar2 = eventReceive(7,1,0xffffffff,&local_c);
    if (iVar2 != 0) {
      BSP_TRACE(4,0x2d,DAT_30035f8c);
    }
    if ((local_c & 1) == 0) {
      if ((local_c & 2) != 0) {
        if ((DAT_30035f88[1] < 10) &&
           (*(char *)(DAT_30035fa4 + (uint)DAT_30035f88[1] * 2 + (uint)*DAT_30035f88 * 0x16) != '\0'
           )) {
          DAT_30035f88[1] = DAT_30035f88[1] + 1;
        }
        else {
          DAT_30035f88[1] = 0;
        }
        DAT_30035f88[2] =
             *(byte *)((uint)*DAT_30035f88 * 0x16 + DAT_30035fa8 + (uint)DAT_30035f88[1] * 2);
        DAT_30035f88[3] =
             *(byte *)(DAT_30035fac + (uint)DAT_30035f88[1] * 2 + (uint)*DAT_30035f88 * 0x16);
        if (local_10 != 0) {
          BSP_TRACE(4,0x2d,DAT_30035fb0);
        }
        iVar2 = softtimer_create_timer
                          (&local_10,(uint)DAT_30035f88[3] * 100,0,DAT_30035f9c,0,DAT_30035f90,
                           DAT_30035fb4);
        if (iVar2 != 0) {
          BSP_TRACE(4,0x2d,DAT_30035fa0);
        }
      }
    }
    else {
      if (local_10 != 0) {
        BSP_TLED_LedOff();
        softtimer_del_timer(&local_10,DAT_30035f90,DAT_30035f94);
      }
      iVar2 = softtimer_create_timer
                        (&local_10,(uint)DAT_30035f88[3] * 100,0,DAT_30035f9c,0,DAT_30035f90,
                         DAT_30035f98);
      if (iVar2 != 0) {
        BSP_TRACE(4,0x2d,DAT_30035fa0);
      }
    }
    BSP_TLED_LedSwitch(bVar1,DAT_30035f88[2]);
  } while( true );
}

/* ----------------------------------------------------------------
 * BSP_TLED_LedFlush @ 0x30035B60  (примерный размер ~160 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 4
 * Вызывает: eventSend, intCpuLock, intCpuUnlock, taskNameToId
 * Вызывают: BSP_TLED_LedInit, BSP_TLED_LedUpdateCallback
 * Константы: 0x30035B60, 0xFFFFFFFF
 * Данные: DAT_30035f80, DAT_30035f88, DAT_30035fa8, DAT_30035fac, DAT_30035fb8
 * ---------------------------------------------------------------- */
undefined4 BSP_TLED_LedFlush(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x20) {
    uVar1 = intCpuLock();
    *DAT_30035f88 = (char)param_1;
    DAT_30035f88[1] = 0;
    DAT_30035f88[2] = *(undefined1 *)(DAT_30035fa8 + param_1 * 0x16);
    DAT_30035f88[3] = *(undefined1 *)(DAT_30035fac + param_1 * 0x16);
    *DAT_30035f80 = 1;
    intCpuUnlock(uVar1);
    uVar1 = taskNameToId(DAT_30035fb8);
    eventSend(uVar1,1);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_TLED_LedUpdateCallback @ 0x30035C00  (примерный размер ~80 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_TLED_LedFlush
 * Константы: 0x30035C00
 * Данные: DAT_30035f84, DAT_30035f88
 * ---------------------------------------------------------------- */
void BSP_TLED_LedUpdateCallback(void)

{
  uint uVar1;
  
  if ((*DAT_30035f84 != 0) && (uVar1 = (*(code *)*DAT_30035f84)(), *DAT_30035f88 != uVar1)) {
    BSP_TLED_LedFlush(uVar1);
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_TLED_LedCallback @ 0x30035C50  (примерный размер ~36 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: eventSend, taskNameToId
 * Константы: 0x30035C50
 * Данные: DAT_30035fb8
 * ---------------------------------------------------------------- */
void BSP_TLED_LedCallback(void)

{
  undefined4 uVar1;
  
  uVar1 = taskNameToId(DAT_30035fb8);
  eventSend(uVar1,2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_TLED_LedInit @ 0x30035C74  (примерный размер ~364 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: BSP_TLED_LedFlush, BSP_TRACE, softtimer_create_timer, taskSpawn
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0xFFFFFFFF, 0x30035C74
 * Данные: DAT_30035f80, DAT_30035f84, DAT_30035f88, DAT_30035f90, DAT_30035fa8, DAT_30035fb8, DAT_30035fbc, DAT_30035fc0
 * ---------------------------------------------------------------- */
undefined4 BSP_TLED_LedInit(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  
  local_10 = 0;
  if (*DAT_30035fbc == 1) {
    uVar1 = 0;
  }
  else {
    *DAT_30035f88 = 7;
    DAT_30035f88[1] = 0;
    DAT_30035f88[2] = *(undefined1 *)(DAT_30035fa8 + 0x9a);
    DAT_30035f88[3] = *(undefined1 *)(DAT_30035fa8 + 0x9b);
    *DAT_30035f80 = 1;
    *DAT_30035fbc = 1;
    *DAT_30035f84 = DAT_30035fc0;
    iVar2 = softtimer_create_timer
                      (DAT_30035fc8,100,1,DAT_30035fcc,&local_10,DAT_30035f90,DAT_30035fc4);
    if (iVar2 == 0) {
      iVar2 = taskSpawn(DAT_30035fb8,10,0,0x1000,DAT_30035fd4,0,0,0,0,0,0,0,0,0,0);
      if (iVar2 == -1) {
        uVar1 = 0xffffffff;
      }
      else {
        BSP_TLED_LedFlush(7);
        uVar1 = 0;
      }
    }
    else {
      BSP_TRACE(4,0x2d,DAT_30035fd0);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_TLED_LedControlAddressGet @ 0x30035DE0  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30035DE0
 * ---------------------------------------------------------------- */
void BSP_TLED_LedControlAddressGet(void)

{
  return;
}

/* ----------------------------------------------------------------
 * BSP_TLED_NotifyLedFlush @ 0x30035DE4  (примерный размер ~88 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Вызывают: BSP_MNTN_LedFlush
 * Константы: 0x30035DE4
 * Данные: DAT_30035f7c, DAT_30035fd8, DAT_30035fdc, DAT_30035fe0
 * ---------------------------------------------------------------- */
void BSP_TLED_NotifyLedFlush(int param_1)

{
  *DAT_30035fd8 = *DAT_30035fd8 + 1;
  *DAT_30035f7c = param_1;
  if (param_1 == 9) {
    *DAT_30035fdc = *DAT_30035fdc + 1;
  }
  else {
    BSP_TRACE(4,0x2d,DAT_30035fe0);
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_MNTN_LedStateFuncReg @ 0x30035E3C  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_TLED_LedStateFuncReg
 * Константы: 0x30035E3C
 * ---------------------------------------------------------------- */
void BSP_MNTN_LedStateFuncReg(undefined4 param_1)

{
  BSP_TLED_LedStateFuncReg(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_MNTN_LedFlush @ 0x30035E50  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: BSP_TLED_NotifyLedFlush
 * Вызывают: DLOAD_LEDInd
 * Константы: 0x30035E50
 * ---------------------------------------------------------------- */
void BSP_MNTN_LedFlush(undefined4 param_1)

{
  BSP_TLED_NotifyLedFlush(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_LED_TST_Init @ 0x30035E70  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_TLED_LedStateFuncReg
 * Константы: 0x30035E70
 * Данные: DAT_30035fe4
 * ---------------------------------------------------------------- */
void BSP_LED_TST_Init(void)

{
  BSP_TLED_LedStateFuncReg(DAT_30035fe4);
  return;
}

/* ----------------------------------------------------------------
 * hkadcSsiSend @ 0x300406F0  (примерный размер ~108 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 2
 * Вызывает: BSP_SSI_Write, BSP_TRACE
 * Вызывают: BSP_HKADC_Convert, hkadcInit
 * Константы: 0x300406F0
 * Данные: DAT_30041628
 * ---------------------------------------------------------------- */
int hkadcSsiSend(uint param_1,uint param_2)

{
  int iVar1;
  uint local_18;
  
  local_18 = param_1 & 0xff | (param_2 & 0xff) << 7;
  iVar1 = BSP_SSI_Write(3,&local_18,1);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    BSP_TRACE(4,0x2e,DAT_30041628);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * hkadcSsiRecv @ 0x3004075C  (примерный размер ~96 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_SSI_Read, BSP_TRACE
 * Вызывают: BSP_HKADC_Convert
 * Константы: 0x3004075C
 * Данные: DAT_300416b4
 * ---------------------------------------------------------------- */
int hkadcSsiRecv(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_4 [4];
  
  local_4[0] = param_1;
  iVar1 = BSP_SSI_Read(3,local_4,param_2,1);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    BSP_TRACE(4,0x2e,DAT_300416b4);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * hkadcInit @ 0x300407BC  (примерный размер ~188 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: BSP_SSI_SetAttr, BSP_TRACE, hkadcSsiSend, semBCreate
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0xFFFFFFFF, 0x300407BC
 * Данные: DAT_300416b8, DAT_300416bc, DAT_300416c0
 * ---------------------------------------------------------------- */
undefined4 hkadcInit(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 6;
  local_14 = 7;
  local_10 = 0xf;
  iVar1 = BSP_SSI_SetAttr(3,&local_18);
  if (iVar1 == 0) {
    if (*DAT_300416bc == 0) {
      iVar1 = semBCreate(0,1);
      *DAT_300416bc = iVar1;
    }
    if (*DAT_300416bc == 0) {
      BSP_TRACE(4,0x2e,DAT_300416c0);
      uVar2 = 0xffffffff;
    }
    else {
      hkadcSsiSend(2,2);
      uVar2 = 0;
    }
  }
  else {
    BSP_TRACE(4,0x2e,DAT_300416b8,iVar1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * hkadcReInit @ 0x30040878  (примерный размер ~100 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_SSI_SetAttr, BSP_TRACE
 * Константы: 0x30040878, 0xFFFFFFFF
 * Данные: DAT_300416b8
 * ---------------------------------------------------------------- */
undefined4 hkadcReInit(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 6;
  local_14 = 7;
  local_10 = 0xf;
  iVar1 = BSP_SSI_SetAttr(3,&local_18);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    BSP_TRACE(4,0x2e,DAT_300416b8,iVar1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_GetTempInit @ 0x300408DC  (примерный размер ~196 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_TRACE, semBCreate, taskSpawn
 * Константы: 0x300408DC
 * Данные: DAT_30041778, DAT_30041834, DAT_30041838, DAT_3004183c
 * ---------------------------------------------------------------- */
void BSP_HKADC_GetTempInit(void)

{
  int iVar1;
  
  if (*DAT_30041778 == 0) {
    iVar1 = semBCreate(0,0);
    *DAT_30041778 = iVar1;
    if (*DAT_30041778 == 0) {
      BSP_TRACE(4,0x2e,DAT_30041834);
      return;
    }
  }
  taskSpawn(DAT_3004183c,0x98,0,0x1000,DAT_30041838,0,0,0,0,0,0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_Convert @ 0x300409A0  (примерный размер ~476 байт)
 * Модуль: bsp | Вызывают: 12 | Вызывает: 6
 * Вызывает: BSP_TRACE, hkadcSsiRecv, hkadcSsiSend, semGive, semTake, taskDelay
 * Вызывают: BSP_HKADC_BatVolAdcRead, BSP_HKADC_BatVolRead, BSP_HKADC_DcxoTempRead, BSP_HKADC_GetTempTask, BSP_HKADC_GetVer, BSP_HKADC_LtePAPowerRead, BSP_HKADC_LtePATempRead, BSP_HKADC_PaValueGet, BSP_HKADC_SIMTempRead, BSP_HKADC_Test
 *           ...
 * Константы: 0xFFFFFFFF, 0x300409A0
 * Данные: DAT_300416bc, DAT_30041840, DAT_30041844, DAT_300418a8, DAT_300418ac, DAT_300418b0
 * ---------------------------------------------------------------- */
undefined4 BSP_HKADC_Convert(uint param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  byte local_28 [4];
  int local_24;
  
  while (*DAT_30041840 == 0) {
    taskDelay(3);
  }
  semTake(*DAT_300416bc,0xffffffff);
  hkadcSsiSend(0,0x10);
  hkadcSsiSend(0,0x12);
  for (iVar2 = DAT_30041844; -1 < iVar2; iVar2 = iVar2 + -1) {
  }
  if (9 < (int)param_1) {
    param_1 = param_1 + 4;
  }
  hkadcSsiSend(2,(param_1 & 0xff) << 2 | 2);
  hkadcSsiSend(1,0);
  hkadcSsiSend(1,1);
  local_24 = 0x600;
  hkadcSsiRecv(4,local_28);
  while (((local_28[0] & 1) != 1 && (local_24 = local_24 + -1, iVar2 = DAT_300418a8, local_24 != 0))
        ) {
    for (; -1 < iVar2; iVar2 = iVar2 + -1) {
    }
    hkadcSsiRecv(4,local_28);
  }
  if (local_24 == 0) {
    semGive(*DAT_300416bc);
    hkadcSsiSend(0,0x18);
    hkadcSsiSend(1,0);
    BSP_TRACE(4,0x2e,DAT_300418ac);
    uVar1 = 0xffffffff;
  }
  else {
    hkadcSsiRecv(5,local_28);
    uVar3 = (uint)local_28[0];
    hkadcSsiRecv(6,local_28);
    hkadcSsiSend(0,0x18);
    hkadcSsiSend(1,0);
    *param_2 = (short)((int)(((uVar3 << 0x10) >> 0xe | (int)(local_28[0] & 0xc0) >> 6) *
                             DAT_300418b0 + 0x200) >> 10);
    semGive(*DAT_300416bc);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_GetTempTask @ 0x30040B7C  (примерный размер ~200 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_HKADC_Convert, BSP_TRACE, semTake
 * Константы: 0x30040B7C
 * Данные: DAT_30041778, DAT_300418b4, DAT_300418b8
 * ---------------------------------------------------------------- */
void BSP_HKADC_GetTempTask(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_300418b4;
  do {
    semTake(*DAT_30041778,0x32);
    for (uVar3 = 0; uVar3 < 0xc; uVar3 = uVar3 + 1) {
      if (*(char *)(iVar1 + uVar3 * 8 + 3) != '\0') {
        iVar2 = BSP_HKADC_Convert(uVar3,iVar1 + uVar3 * 8);
        if (iVar2 == 0) {
          *(undefined1 *)(iVar1 + uVar3 * 8 + 2) = 1;
        }
        else {
          *(undefined1 *)(iVar1 + uVar3 * 8 + 2) = 0;
          BSP_TRACE(4,0x2e,DAT_300418b8,uVar3,0,0,0,0,0);
        }
      }
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * BSP_HKADC_GetVer @ 0x30040C44  (примерный размер ~264 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_HKADC_Convert, BSP_TRACE
 * Вызывают: BSP_HKADC_GetVerSafe
 * Константы: 0xFFFFFFFF, 0x30040C44
 * Данные: DAT_300418bc, DAT_300418c0, DAT_300418c4, DAT_300418c8, DAT_300418cc, DAT_300418d0
 * ---------------------------------------------------------------- */
undefined4 BSP_HKADC_GetVer(undefined4 param_1,byte *param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  ushort local_18 [2];
  
  local_18[0] = 0;
  uVar2 = DAT_300418bc;
  if (param_2 != (byte *)0x0) {
    iVar1 = BSP_HKADC_Convert(param_1,local_18);
    if (iVar1 == -1) {
      uVar2 = 0xffffffff;
    }
    else {
      BSP_TRACE(0,0x2e,DAT_300418c0,param_1,local_18[0]);
      for (bVar3 = 0; bVar3 < 10; bVar3 = bVar3 + 1) {
        if ((*(ushort *)(DAT_300418c4 + (uint)bVar3 * 4) <= local_18[0]) &&
           (local_18[0] <= *(ushort *)(DAT_300418c8 + (uint)bVar3 * 4))) {
          *param_2 = bVar3;
          BSP_TRACE(0,0x2e,DAT_300418cc,param_1,bVar3);
          return 0;
        }
      }
      BSP_TRACE(4,0x2e,DAT_300418d0,param_1,local_18[0]);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_GetVerSafe @ 0x30040D4C  (примерный размер ~180 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: BSP_HKADC_GetVer
 * Вызывают: hwVerGet
 * Константы: 0x30040D4C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 BSP_HKADC_GetVerSafe(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  char local_1c;
  char local_1b [3];
  
  for (uVar3 = 0; uVar3 < 2; uVar3 = uVar3 + 1) {
    BSP_HKADC_GetVer(param_1,&local_1c);
    BSP_HKADC_GetVer(param_1,local_1b);
    iVar1 = BSP_HKADC_GetVer(param_1,param_2);
    if (((iVar1 == 0) && (local_1c == local_1b[0])) && (local_1b[0] == *param_2)) break;
    for (iVar1 = 500; iVar1 != 0; iVar1 = iVar1 + -1) {
    }
  }
  if (uVar3 == 2) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_PaValueGet @ 0x30040E00  (примерный размер ~96 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_HKADC_Convert, BSP_TRACE
 * Константы: 0x30040E00, 0xFFFFFFFF
 * Данные: DAT_300418bc, DAT_300418d4
 * ---------------------------------------------------------------- */
undefined4 BSP_HKADC_PaValueGet(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_300418bc;
  if (param_1 != 0) {
    iVar1 = BSP_HKADC_Convert(1,param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      BSP_TRACE(4,0x2e,DAT_300418d4,1,iVar1);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_GetSystemTemperature @ 0x30040E60  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30040E60
 * ---------------------------------------------------------------- */
undefined4 BSP_HKADC_GetSystemTemperature(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_TemVoltTrans @ 0x30040E68  (примерный размер ~368 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 1
 * Вызывает: __div32
 * Вызывают: BSP_HKADC_DcxoTempRead, BSP_HKADC_LtePATempRead, BSP_HKADC_SIMTempRead, BSP_HKADC_TftTempRead
 * Константы: 0x30040E68
 * Данные: DAT_300418d8
 * ---------------------------------------------------------------- */
int BSP_HKADC_TemVoltTrans(char param_1,ushort param_2,short *param_3)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  short *psVar5;
  
  if (param_3 == (short *)0x0) {
    iVar2 = (int)(short)param_2;
  }
  else {
    if (param_1 == '\x03') {
      uVar3 = 0x13;
    }
    else {
      uVar3 = 0x20;
    }
    uVar4 = 0;
    for (psVar5 = param_3; (uVar4 < uVar3 && ((psVar5[1] != 0 || (*psVar5 != 0))));
        psVar5 = psVar5 + 2) {
      uVar4 = uVar4 + 1;
    }
    if ((*param_3 != 0) || (iVar2 = DAT_300418d8, param_3[1] != 0)) {
      if (param_2 < (ushort)param_3[1]) {
        if ((ushort)param_3[(uint)uVar4 * 2 + -1] < param_2) {
          for (; param_2 < (ushort)param_3[1]; param_3 = param_3 + 2) {
          }
          sVar1 = __div32(((uint)(ushort)param_3[-1] - (uint)param_2) *
                          ((int)*param_3 - (int)param_3[-2]) +
                          (int)(((uint)(ushort)param_3[-1] - (uint)(ushort)param_3[1]) + 1) / 2,
                          (uint)(ushort)param_3[-1] - (uint)(ushort)param_3[1]);
          iVar2 = (int)(short)(param_3[-2] + sVar1);
        }
        else {
          iVar2 = (int)param_3[(uint)uVar4 * 2 + -2];
        }
      }
      else {
        iVar2 = (int)*param_3;
      }
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_LtePATempRead @ 0x30040FD8  (примерный размер ~208 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: BSP_HKADC_Convert, BSP_HKADC_TemVoltTrans, BSP_HwGetVerMain, BSP_TRACE
 * Вызывают: BSP_HKADC_TempVoltGet
 * Константы: 0x30040FD8
 * Данные: DAT_300418dc, DAT_300418e0, DAT_300418e4
 * ---------------------------------------------------------------- */
int BSP_HKADC_LtePATempRead(int *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined2 local_18 [2];
  
  local_18[0] = 0;
  uVar3 = BSP_HwGetVerMain();
  if ((uVar3 & 0xffff) == DAT_300418dc) {
    iVar4 = 0;
  }
  else if (param_1 == (int *)0x0) {
    BSP_TRACE(4,0x2e,DAT_300418e0,0,0,0,0,0,0);
    iVar4 = -1;
  }
  else {
    uVar1 = *(undefined1 *)(DAT_300418e4 + 1);
    iVar4 = BSP_HKADC_Convert(uVar1,local_18);
    if (iVar4 == 0) {
      sVar2 = BSP_HKADC_TemVoltTrans(uVar1,local_18[0],param_2);
      *param_1 = (int)sVar2;
    }
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_SIMTempRead @ 0x300410A8  (примерный размер ~360 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: BSP_HKADC_Convert, BSP_HKADC_TemVoltTrans, BSP_HwGetVerMain, BSP_TRACE
 * Вызывают: BSP_HKADC_TempVoltGet
 * Константы: 0xFFFFFFFF, 0x300410A8
 * Данные: DAT_300418d8, DAT_300418dc, DAT_300418e4, DAT_300418e8, DAT_300418ec, DAT_300418f0
 * ---------------------------------------------------------------- */
undefined4 BSP_HKADC_SIMTempRead(int *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 local_18 [2];
  
  local_18[0] = 0;
  uVar3 = BSP_HwGetVerMain();
  if ((uVar3 & 0xffff) == DAT_300418dc) {
    uVar4 = 0;
  }
  else if (param_1 == (int *)0x0) {
    BSP_TRACE(4,0x2e,DAT_300418e8,0,0,0,0,0,0);
    uVar4 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined1 *)(DAT_300418e4 + 3);
    iVar5 = BSP_HKADC_Convert(uVar1,local_18);
    if (iVar5 == 0) {
      sVar2 = BSP_HKADC_TemVoltTrans(uVar1,local_18[0],param_2);
      *param_1 = (int)sVar2;
      if (*param_1 == DAT_300418d8) {
        BSP_TRACE(4,0x2e,DAT_300418ec,0,0,0,0,0,0);
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      BSP_TRACE(4,0x2e,DAT_300418f0,0,0,0,0,0,0);
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_LtePAPowerRead @ 0x30041210  (примерный размер ~172 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_HKADC_Convert, BSP_HwGetVerMain, BSP_TRACE
 * Константы: 0x30041210, 0xFFFFFFFF
 * Данные: DAT_300418dc, DAT_300418e4, DAT_300418f4
 * ---------------------------------------------------------------- */
undefined4 BSP_HKADC_LtePAPowerRead(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  ushort local_10 [2];
  
  local_10[0] = 0;
  uVar1 = BSP_HwGetVerMain();
  if ((uVar1 & 0xffff) == DAT_300418dc) {
    uVar2 = 0;
  }
  else if (param_1 == (uint *)0x0) {
    BSP_TRACE(4,0x2e,DAT_300418f4,0,0,0,0,0,0);
    uVar2 = 0xffffffff;
  }
  else {
    BSP_HKADC_Convert(*(undefined1 *)(DAT_300418e4 + 1),local_10);
    *param_1 = (uint)local_10[0];
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_BatVolRead @ 0x300412BC  (примерный размер ~288 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: BSP_HKADC_Convert, BSP_TRACE, __div32
 * Вызывают: BSP_HKADC_BatVoltGet
 * Константы: 0xFFFFFFFF, 0x300412BC
 * Данные: DAT_300418e4, DAT_300418f8, DAT_300418fc
 * ---------------------------------------------------------------- */
undefined4 BSP_HKADC_BatVolRead(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  ushort local_28 [2];
  
  local_28[0] = 0;
  if (param_1 == (int *)0x0) {
    BSP_TRACE(4,0x2e,DAT_300418f8,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = BSP_HKADC_Convert(*(undefined1 *)(DAT_300418e4 + 6),local_28);
    if (iVar2 == 0) {
      iVar3 = *DAT_300418fc;
      iVar2 = __div32((DAT_300418fc[2] - iVar3) * ((uint)local_28[0] * 2 - DAT_300418fc[1]),
                      DAT_300418fc[3] - DAT_300418fc[1]);
      *param_1 = iVar2 + iVar3;
      uVar1 = 0;
    }
    else {
      BSP_TRACE(4,0x2e,DAT_300418f8,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_BatVolAdcRead @ 0x300413DC  (примерный размер ~232 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_HKADC_Convert, BSP_TRACE
 * Константы: 0xFFFFFFFF, 0x300413DC
 * Данные: DAT_300418e4, DAT_300418f8
 * ---------------------------------------------------------------- */
undefined4 BSP_HKADC_BatVolAdcRead(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  ushort local_18 [2];
  
  local_18[0] = 0;
  if (param_1 == (int *)0x0) {
    BSP_TRACE(4,0x2e,DAT_300418f8,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = BSP_HKADC_Convert(*(undefined1 *)(DAT_300418e4 + 6),local_18);
    if (iVar2 == 0) {
      *param_1 = (uint)local_18[0] << 1;
      uVar1 = 0;
    }
    else {
      BSP_TRACE(4,0x2e,DAT_300418f8,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_BatTempRead @ 0x300414C4  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300414C4
 * ---------------------------------------------------------------- */
void BSP_HKADC_BatTempRead(void)

{
  return;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_DcxoTempRead @ 0x300414C8  (примерный размер ~208 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: BSP_HKADC_Convert, BSP_HKADC_TemVoltTrans, BSP_HwGetVerMain, BSP_TRACE
 * Вызывают: BSP_HKADC_TempVoltGet
 * Константы: 0x300414C8
 * Данные: DAT_300418dc, DAT_300418e4, DAT_30041900
 * ---------------------------------------------------------------- */
int BSP_HKADC_DcxoTempRead(int *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined2 local_18 [2];
  
  local_18[0] = 0;
  uVar3 = BSP_HwGetVerMain();
  if ((uVar3 & 0xffff) == DAT_300418dc) {
    iVar4 = 0;
  }
  else if (param_1 == (int *)0x0) {
    BSP_TRACE(4,0x2e,DAT_30041900,0,0,0,0,0,0);
    iVar4 = -1;
  }
  else {
    uVar1 = *(undefined1 *)(DAT_300418e4 + 8);
    iVar4 = BSP_HKADC_Convert(uVar1,local_18);
    if (iVar4 == 0) {
      sVar2 = BSP_HKADC_TemVoltTrans(uVar1,local_18[0],param_2);
      *param_1 = (int)sVar2;
    }
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_BatADCRead @ 0x30041598  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30041598
 * ---------------------------------------------------------------- */
undefined4 BSP_HKADC_BatADCRead(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_TftTempRead @ 0x300415A0  (примерный размер ~212 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: BSP_HKADC_Convert, BSP_HKADC_TemVoltTrans, BSP_HwGetVerMain, BSP_TRACE
 * Вызывают: BSP_HKADC_TempVoltGet
 * Константы: 0x300415A0
 * Данные: DAT_300418dc, DAT_300418e4, DAT_30041900
 * ---------------------------------------------------------------- */
int BSP_HKADC_TftTempRead(int *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined2 local_18 [2];
  
  local_18[0] = 0;
  uVar3 = BSP_HwGetVerMain();
  if ((uVar3 & 0xffff) == DAT_300418dc) {
    iVar4 = 0;
  }
  else if (param_1 == (int *)0x0) {
    BSP_TRACE(4,0x2e,DAT_30041900,0,0,0,0,0,0);
    iVar4 = -1;
  }
  else {
    uVar1 = *(undefined1 *)(DAT_300418e4 + 5);
    iVar4 = BSP_HKADC_Convert(uVar1,local_18);
    if (iVar4 == 0) {
      sVar2 = BSP_HKADC_TemVoltTrans(uVar1,local_18[0],param_2);
      *param_1 = (int)sVar2;
    }
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_TempVoltGet @ 0x30041674  (примерный размер ~196 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: BSP_HKADC_DcxoTempRead, BSP_HKADC_LtePATempRead, BSP_HKADC_SIMTempRead, BSP_HKADC_TftTempRead
 * Вызывают: BSP_HKADC_SmthProc
 * Константы: 0x30041674
 * Данные: DAT_30041904
 * ---------------------------------------------------------------- */
int BSP_HKADC_TempVoltGet(int param_1)

{
  int iVar1;
  int local_10;
  
  local_10 = 0;
  if (param_1 == 0) {
    iVar1 = BSP_HKADC_LtePATempRead(&local_10,DAT_30041904);
  }
  else if (param_1 == 1) {
    iVar1 = BSP_HKADC_SIMTempRead(&local_10,DAT_30041904);
  }
  else if (param_1 == 2) {
    iVar1 = BSP_HKADC_DcxoTempRead(&local_10,DAT_30041904);
  }
  else {
    if (param_1 != 6) {
      return -1;
    }
    iVar1 = BSP_HKADC_TftTempRead(&local_10,DAT_30041904);
  }
  if (iVar1 != 0) {
    local_10 = iVar1;
  }
  return local_10;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_SmthProc @ 0x30041788  (примерный размер ~76 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_HKADC_TempVoltGet
 * Константы: 0x30041788
 * Данные: DAT_30041908
 * ---------------------------------------------------------------- */
undefined4 BSP_HKADC_SmthProc(int param_1)

{
  int iVar1;
  
  iVar1 = BSP_HKADC_TempVoltGet(param_1);
  iVar1 = iVar1 + *(int *)(DAT_30041908 + param_1 * 4) * 3;
  *(int *)(DAT_30041908 + param_1 * 4) = (int)(iVar1 + ((uint)(iVar1 >> 0x1f) >> 0x1e)) >> 2;
  return *(undefined4 *)(DAT_30041908 + param_1 * 4);
}

/* ----------------------------------------------------------------
 * BSP_HKADC_SmthValGet @ 0x300417D4  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300417D4
 * Данные: DAT_30041908
 * ---------------------------------------------------------------- */
undefined4 BSP_HKADC_SmthValGet(int param_1)

{
  return *(undefined4 *)(DAT_30041908 + param_1 * 4);
}

/* ----------------------------------------------------------------
 * BSP_PWRCTRL_GetTemp @ 0x300417EC  (примерный размер ~664 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_HwGetVerMain, BSP_TRACE
 * Константы: 0xFFFFFFFF, 0x300417EC, 0x300418A4
 * Данные: DAT_300418dc, DAT_3004190c, DAT_30041910
 * ---------------------------------------------------------------- */
undefined4 BSP_PWRCTRL_GetTemp(uint param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  
  uVar3 = 0;
  uVar1 = BSP_HwGetVerMain();
  if ((uVar1 & 0xffff) == DAT_300418dc) {
    uVar2 = 0;
  }
  else if (param_3 == 0) {
    BSP_TRACE(4,0x2e,DAT_3004190c,param_1,0,0,0,0,0,uVar3);
    uVar2 = 0xffffffff;
  }
  else {
    if (param_1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x300418a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_30041910 + param_1 * 4))();
      return uVar2;
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_BatVoltGet @ 0x30041A84  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_HKADC_BatVolRead
 * Константы: 0x30041A84
 * ---------------------------------------------------------------- */
void BSP_HKADC_BatVoltGet(undefined4 param_1)

{
  BSP_HKADC_BatVolRead(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_HKADC_Test @ 0x30041A98  (примерный размер ~88 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_HKADC_Convert, printf, timeDelay
 * Константы: 0x30041A98
 * Данные: DAT_30041cbc
 * ---------------------------------------------------------------- */
void BSP_HKADC_Test(undefined1 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
    iVar1 = BSP_HKADC_Convert(param_1,param_2);
    if (iVar1 != 0) {
      printf(DAT_30041cbc,uVar2);
    }
    timeDelay(100);
  }
  return;
}

/* ----------------------------------------------------------------
 * hkadcRegShow @ 0x30041AF0  (примерный размер ~116 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_SSI_Read, BSP_TRACE, printf
 * Константы: 0x30041AF0
 * Данные: DAT_30041cc0, DAT_30041cc4
 * ---------------------------------------------------------------- */
int hkadcRegShow(byte param_1)

{
  int iVar1;
  byte local_14 [4];
  byte local_4 [4];
  
  local_4[0] = param_1;
  iVar1 = BSP_SSI_Read(3,local_4,local_14,1);
  if (iVar1 == 0) {
    printf(DAT_30041cc4,(uint)local_4[0],(uint)local_14[0]);
    iVar1 = 0;
  }
  else {
    BSP_TRACE(4,0x2e,DAT_30041cc0);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * hkadcTest @ 0x30041B64  (примерный размер ~404 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_HKADC_Convert, printf
 * Константы: 0x30041B64
 * Данные: DAT_30041ca8, DAT_30041cc8, DAT_30041ccc, DAT_30041cd0, DAT_30041cd4, DAT_30041cd8, DAT_30041cdc, DAT_30041ce0
 * ---------------------------------------------------------------- */
void hkadcTest(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ushort local_1c [2];
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  printf(DAT_30041cc8,0xc,param_1);
  printf(DAT_30041ccc);
  for (uVar2 = 0; uVar2 < 0xc; uVar2 = uVar2 + 1) {
    printf(DAT_30041cd0,uVar2);
  }
  printf(DAT_30041cd4);
  for (uVar2 = 0; uVar2 < param_1; uVar2 = uVar2 + 1) {
    printf(DAT_30041cd8,uVar2);
    for (uVar3 = 0; uVar3 < 0xc; uVar3 = uVar3 + 1) {
      iVar1 = BSP_HKADC_Convert(uVar3,local_1c);
      if (iVar1 == 0) {
        printf(DAT_30041cd8,(uint)local_1c[0]);
      }
      else {
        printf(DAT_30041cdc,iVar1);
      }
    }
    printf(DAT_30041cd4);
  }
  for (uVar2 = 0; uVar2 < 0xc; uVar2 = uVar2 + 1) {
    printf(DAT_30041ce0,uVar2);
    printf(DAT_30041ce4,(uint)*(ushort *)(DAT_30041ca8 + uVar2 * 8));
    printf(DAT_30041cec,(uint)*(byte *)(DAT_30041ce8 + uVar2 * 8));
    printf(DAT_30041cf4,(uint)*(byte *)(DAT_30041cf0 + uVar2 * 8));
    printf(DAT_30041cd4);
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_USB_GetDiagModeValue @ 0x30059BB0  (примерный размер ~40 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30059BB0
 * ---------------------------------------------------------------- */
undefined4 BSP_USB_GetDiagModeValue(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = 1;
  *param_2 = 2;
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_USB_GetU2diagDefaultValue @ 0x30059BD8  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30059BD8
 * Данные: DAT_3005ab54
 * ---------------------------------------------------------------- */
undefined4 BSP_USB_GetU2diagDefaultValue(void)

{
  return DAT_3005ab54;
}

/* ----------------------------------------------------------------
 * BSP_USB_GetIsWwanMode @ 0x30059BE0  (примерный размер ~32 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30059BE0
 * Данные: DAT_3005ab58
 * ---------------------------------------------------------------- */
undefined4 BSP_USB_GetIsWwanMode(undefined4 *param_1)

{
  *param_1 = *DAT_3005ab58;
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_USB_DumpDevProfile @ 0x30059C00  (примерный размер ~164 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: os_printf
 * Вызывают: BSP_USB_QueryDevProfile
 * Константы: 0x30059C00
 * Данные: DAT_3005ab5c, DAT_3005ab60, DAT_3005ab64, DAT_3005ab68, DAT_3005ab6c, DAT_3005ab70, DAT_3005ab74, DAT_3005ab78
 * ---------------------------------------------------------------- */
void BSP_USB_DumpDevProfile(undefined2 *param_1)

{
  byte bVar1;
  
  os_printf(DAT_3005ab5c);
  os_printf(DAT_3005ab60);
  os_printf(DAT_3005ab64,*param_1);
  os_printf(DAT_3005ab68,*(undefined1 *)(param_1 + 1));
  os_printf(DAT_3005ab6c,param_1[2]);
  os_printf(DAT_3005ab70,*(undefined4 *)(param_1 + 4));
  os_printf(DAT_3005ab74,*(undefined4 *)(param_1 + 6));
  for (bVar1 = 0; bVar1 < *(byte *)(param_1 + 1); bVar1 = bVar1 + 1) {
    os_printf(DAT_3005ab7c,bVar1 + 1,
              *(undefined4 *)(DAT_3005ab78 + *(int *)(param_1 + (uint)bVar1 * 4 + 8) * 4));
  }
  os_printf(DAT_3005ab5c);
  return;
}

/* ----------------------------------------------------------------
 * BSP_USB_CheckDevProfile @ 0x30059CA4  (примерный размер ~76 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30059CA4
 * Данные: DAT_3005ab80
 * ---------------------------------------------------------------- */
undefined4 BSP_USB_CheckDevProfile(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (8 < uVar1) {
      return 10;
    }
    if (*(ushort *)(DAT_3005ab80 + uVar1 * 0x98) == param_1) break;
    uVar1 = uVar1 + 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_USB_GetDevProfileInfo @ 0x30059CF0  (примерный размер ~204 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: os_memcpy, os_nv_read, os_printf
 * Константы: 0x30059CF0
 * Данные: DAT_3005ac14, DAT_3005ac18, DAT_3005ac1c, DAT_3005ac20, DAT_3005ac24, DAT_3005ac28
 * ---------------------------------------------------------------- */
undefined4 BSP_USB_GetDevProfileInfo(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    uVar1 = 10;
  }
  else {
    iVar2 = os_nv_read(DAT_3005ac14,param_1,0x10);
    if (iVar2 == 0) {
      if (*param_1 == 0) {
        os_memcpy(param_1,DAT_3005ac18,0x10);
      }
      iVar2 = os_nv_read(DAT_3005ac20,param_2,0x28);
      if (iVar2 == 0) {
        if (*param_2 == 0) {
          os_memcpy(param_2,DAT_3005ac24,0x28);
        }
        uVar1 = 0;
      }
      else {
        os_printf(DAT_3005ac28,0);
        uVar1 = 10;
      }
    }
    else {
      os_printf(DAT_3005ac1c,0);
      uVar1 = 10;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_USB_ValidateDevProfile @ 0x30059DBC  (примерный размер ~760 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: free, malloc, os_memset, os_printf
 * Вызывают: BSP_USB_UpdateDevProfileInfo
 * Константы: 0x30059DBC
 * Данные: DAT_3005acd4, DAT_3005acd8, DAT_3005acdc, DAT_3005ace0, DAT_3005ace4, DAT_3005ace8, DAT_3005acec, DAT_3005acf0
 * ---------------------------------------------------------------- */
undefined4 BSP_USB_ValidateDevProfile(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  void *__ptr;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  char local_c;
  char cStack_b;
  
  bVar5 = 0;
  bVar4 = 0;
  iVar3 = 9;
  __ptr = malloc(0x100);
  if (__ptr == (void *)0x0) {
    os_printf(DAT_3005acd4,0);
    uVar2 = 7;
  }
  else {
    os_memset(__ptr,0,0x100);
    local_c = (char)param_2;
    if ((local_c == -1) || (local_c == -0x5f)) {
      cStack_b = (char)((uint)param_2 >> 8);
      if ((cStack_b == '\0') || (cStack_b == -0x5e)) {
        if ((local_c == -1) && (cStack_b != '\0')) {
          os_printf(DAT_3005ace0,0);
          free(__ptr);
          uVar2 = 10;
        }
        else {
          for (bVar7 = 0; bVar7 < 0x11; bVar7 = bVar7 + 1) {
            cVar1 = (&stack0x00000005)[bVar7];
            if ((cVar1 == '\0') && (bVar7 == 0)) {
              os_printf(DAT_3005ace4,0);
              free(__ptr);
              return 10;
            }
            if (cVar1 == '\x12') {
              iVar3 = 0;
            }
            if (cVar1 == '\0') break;
            for (bVar6 = 0; (bVar6 < 0xc && (cVar1 != *(char *)(DAT_3005ace8 + (uint)bVar6)));
                bVar6 = bVar6 + 1) {
            }
            if (bVar6 == 0xc) {
              os_printf(DAT_3005acec,0);
              os_printf(DAT_3005acf0,0,0xc,0xc);
              free(__ptr);
              return 0xb;
            }
            if ((*(char *)((int)__ptr + (uint)bVar6) != '\0') && (cVar1 != '\x16')) {
              os_printf(DAT_3005acf4,0);
              free(__ptr);
              return 10;
            }
            *(char *)((int)__ptr + (uint)bVar6) = *(char *)((int)__ptr + (uint)bVar6) + '\x01';
            if ((cVar1 == '\x10') || (cVar1 == '\x16')) {
              bVar5 = bVar5 + 2;
            }
            else {
              bVar5 = bVar5 + 1;
            }
            bVar4 = bVar4 + 1;
          }
          if ((local_c == -1) && (iVar3 == 9)) {
            os_printf(DAT_3005acf8,0);
            free(__ptr);
            uVar2 = 10;
          }
          else if ((bVar5 < 0x10) && (bVar4 < 0x10)) {
            free(__ptr);
            uVar2 = 0;
          }
          else {
            os_printf(DAT_3005acfc,0,bVar5,bVar4);
            free(__ptr);
            uVar2 = 10;
          }
        }
      }
      else {
        os_printf(DAT_3005acdc,0);
        free(__ptr);
        uVar2 = 10;
      }
    }
    else {
      os_printf(DAT_3005acd8,0);
      free(__ptr);
      uVar2 = 10;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_USB_FindDevProfile @ 0x3005A0B4  (примерный размер ~88 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 0
 * Вызывают: BSP_USB_BuildDevArgs, BSP_USB_QueryDevProfile, BSP_USB_UpdateDevPidInfo, BSP_USB_UpdateDevProfileInfo
 * Константы: 0x3005A0B4
 * Данные: DAT_3005ab80
 * ---------------------------------------------------------------- */
int BSP_USB_FindDevProfile(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (8 < uVar1) {
      return 0;
    }
    if (*(ushort *)(DAT_3005ab80 + uVar1 * 0x98) == param_1) break;
    uVar1 = uVar1 + 1;
  }
  return DAT_3005ab80 + uVar1 * 0x98;
}

/* ----------------------------------------------------------------
 * BSP_USB_UpdateDevProfileInfo @ 0x3005A10C  (примерный размер ~1044 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 3
 * Вызывает: BSP_USB_FindDevProfile, BSP_USB_ValidateDevProfile, os_printf
 * Константы: 0x3005A10C
 * Данные: DAT_3005ad00, DAT_3005ad04, DAT_3005ad08, DAT_3005ad0c, DAT_3005ad10, DAT_3005ad14
 * ---------------------------------------------------------------- */
undefined4
BSP_USB_UpdateDevProfileInfo
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  byte bVar8;
  int iVar9;
  undefined4 auStack_50 [10];
  char local_c;
  char cStack_b;
  undefined4 *puVar7;
  
  iVar2 = DAT_3005ad00;
  puVar5 = auStack_50;
  iVar9 = 3;
  puVar6 = (undefined4 *)register0x00000054;
  do {
    puVar7 = puVar6 + 1;
    uVar3 = *puVar6;
    puVar6 = puVar6 + 2;
    uVar4 = *puVar7;
    iVar9 = iVar9 + -1;
    puVar7 = puVar5 + 1;
    *puVar5 = uVar3;
    puVar5 = puVar5 + 2;
    *puVar7 = uVar4;
  } while (iVar9 != 0);
  iVar9 = BSP_USB_ValidateDevProfile(param_1,param_2,param_3,param_4);
  if (iVar9 == 0) {
    iVar9 = BSP_USB_FindDevProfile(DAT_3005ad08);
    if (iVar9 == 0) {
      uVar3 = 0xb;
    }
    else {
      local_c = (char)param_2;
      if (local_c == -1) {
        *(undefined4 *)(iVar9 + 8) = 0;
        if (*DAT_3005ad0c != 0) {
          *(undefined4 *)(iVar2 + 0x1c) = DAT_3005ad10;
        }
      }
      else {
        cStack_b = (char)((uint)param_2 >> 8);
        if ((local_c == -0x5f) && (cStack_b == -0x5e)) {
          *(undefined4 *)(iVar9 + 8) = 2;
        }
        else if ((local_c == -0x5f) && (cStack_b == '\0')) {
          *(undefined4 *)(iVar9 + 8) = 1;
        }
      }
      for (bVar8 = 0; bVar8 < 0x11; bVar8 = bVar8 + 1) {
        bVar1 = (&stack0x00000005)[bVar8];
        if (bVar1 == 0x13) {
          *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x10) = 1;
          *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x14) = 6;
        }
        else if (bVar1 < 0x14) {
          if (bVar1 == 10) {
            *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x10) = 3;
            *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x14) = 6;
          }
          else if (bVar1 < 0xb) {
            if (bVar1 == 0) {
              *(byte *)(iVar9 + 2) = bVar8;
              return 0;
            }
            if (bVar1 == 3) {
              *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x10) = 0x13;
              *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x14) = 6;
            }
            else {
              if (bVar1 != 6) {
LAB_3005a4f0:
                os_printf(DAT_3005ad14,0);
                return 10;
              }
              *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x10) = 5;
              *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x14) = 6;
            }
          }
          else if (bVar1 == 0x10) {
            *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x10) = 6;
            *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x14) = 6;
          }
          else {
            if (bVar1 != 0x12) goto LAB_3005a4f0;
            *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x10) = 2;
            *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x14) = 6;
          }
        }
        else if (bVar1 == 0x17) {
          *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x10) = 0x12;
          *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x14) = 6;
        }
        else if (bVar1 < 0x18) {
          if (bVar1 == 0x14) {
            *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x10) = 0xc;
            *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x14) = 6;
          }
          else if (bVar1 == 0x15) {
            *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x10) = 0xd;
            *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x14) = 6;
          }
          else {
            if (bVar1 != 0x16) goto LAB_3005a4f0;
            *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x10) = 8;
            *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x14) = 9;
          }
        }
        else if (bVar1 == 0xa1) {
          *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x10) = 10;
          *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x14) = 1;
        }
        else {
          if (bVar1 != 0xa2) goto LAB_3005a4f0;
          *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x10) = 0xb;
          *(undefined4 *)(iVar9 + (uint)bVar8 * 8 + 0x14) = 1;
        }
      }
      uVar3 = 0;
    }
  }
  else {
    os_printf(DAT_3005ad04,0);
    uVar3 = 10;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * BSP_USB_UpdateDevPidInfo @ 0x3005A520  (примерный размер ~188 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_USB_FindDevProfile, os_printf
 * Константы: 0x3005A520
 * Данные: DAT_3005ad08, DAT_3005ad18, DAT_3005ad1c, DAT_3005ad20, DAT_3005ad24, DAT_3005ad28
 * ---------------------------------------------------------------- */
undefined4
BSP_USB_UpdateDevPidInfo
          (undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = BSP_USB_FindDevProfile(DAT_3005ad18);
  if (iVar1 == 0) {
    os_printf(DAT_3005ad1c,0);
    uVar2 = 0xb;
  }
  else {
    *(undefined2 *)(iVar1 + 4) = param_3;
    iVar1 = BSP_USB_FindDevProfile(DAT_3005ad20);
    if (iVar1 == 0) {
      os_printf(DAT_3005ad24,0);
      uVar2 = 0xb;
    }
    else {
      *(undefined2 *)(iVar1 + 4) = param_3;
      iVar1 = BSP_USB_FindDevProfile(DAT_3005ad08);
      if (iVar1 == 0) {
        os_printf(DAT_3005ad28,0);
        uVar2 = 0xb;
      }
      else {
        *(undefined2 *)(iVar1 + 4) = param_4;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_USB_GetDevDescIdx @ 0x3005A5DC  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: os_printf
 * Вызывают: BSP_USB_BuildDevArgs
 * Константы: 0x3005A5DC
 * Данные: DAT_3005ad2c
 * ---------------------------------------------------------------- */
undefined4 BSP_USB_GetDevDescIdx(void)

{
  os_printf(DAT_3005ad2c);
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_USB_BuildDevProfile @ 0x3005A5F0  (примерный размер ~1068 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 5
 * Вызывает: free, malloc, os_memcpy, os_memset, os_printf
 * Вызывают: BSP_USB_BuildDevArgs
 * Константы: 0x3005A5F0, 0xFFFFFFFF
 * Данные: DAT_3005ad34, DAT_3005ad38, DAT_3005ad3c, DAT_3005ad40, DAT_3005ad44, DAT_3005ad48, DAT_3005ad4c, DAT_3005ad50
 * ---------------------------------------------------------------- */
undefined4 BSP_USB_BuildDevProfile(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int local_134;
  char local_130 [8];
  undefined4 auStack_128 [65];
  
  bVar3 = 0;
  cVar4 = '\0';
  if ((param_1 == 0) || (param_2 == 0)) {
    os_printf(DAT_3005ad34,0);
    uVar1 = 10;
  }
  else {
    *DAT_3005ad38 = 0;
    *DAT_3005ad3c = 0;
    iVar5 = param_2 + 0x10;
    os_memset(DAT_3005ad40,0,0x11);
    os_memset(DAT_3005ad44,0xffffffff,0x18);
    os_memset(&local_134,0,0x110);
    for (uVar6 = 0; uVar6 < *(byte *)(param_2 + 2); uVar6 = uVar6 + 1) {
      if (*(int *)(iVar5 + uVar6 * 8 + 4) == 0) {
        os_printf(DAT_3005ad48,0);
        return 0x13;
      }
      if ((*(int *)(iVar5 + uVar6 * 8 + 4) == (&local_134)[(uint)bVar3 * 4]) &&
         (*(int *)(iVar5 + uVar6 * 8 + 4) != 1)) {
        local_130[(uint)bVar3 * 0x10] = local_130[(uint)bVar3 * 0x10] + '\x01';
      }
      else {
        bVar3 = bVar3 + ((&local_134)[(uint)bVar3 * 4] != 0);
        (&local_134)[(uint)bVar3 * 4] = *(int *)(iVar5 + uVar6 * 8 + 4);
        local_130[(uint)bVar3 * 0x10] = local_130[(uint)bVar3 * 0x10] + '\x01';
        if ((&local_134)[(uint)bVar3 * 4] != 6) {
          os_printf(DAT_3005ad50,0);
          os_printf(DAT_3005ad54,0,(&local_134)[(uint)bVar3 * 4],uVar6,bVar3,iVar5,param_2);
          return 0x13;
        }
        auStack_128[(uint)bVar3 * 4] = DAT_3005ad4c;
      }
      if (*(int *)(iVar5 + uVar6 * 8 + 4) == 9) {
        *DAT_3005ad38 = *DAT_3005ad38 + 1;
      }
      else if (*(int *)(iVar5 + uVar6 * 8 + 4) == 6) {
        *DAT_3005ad3c = *DAT_3005ad3c + 1;
        *(char *)(DAT_3005ad40 + cVar4) = (char)*(undefined4 *)(iVar5 + uVar6 * 8);
        cVar4 = cVar4 + '\x01';
        if (*(int *)(iVar5 + uVar6 * 8) == 5) {
          *DAT_3005ad44 = (int)cVar4;
        }
        if (*(int *)(iVar5 + uVar6 * 8) == 2) {
          DAT_3005ad44[1] = (int)cVar4;
        }
        if (*(int *)(iVar5 + uVar6 * 8) == 3) {
          DAT_3005ad44[2] = (int)cVar4;
        }
        if (*(int *)(iVar5 + uVar6 * 8) == 6) {
          DAT_3005ad44[5] = (int)cVar4;
        }
        if (*(int *)(iVar5 + uVar6 * 8) == 1) {
          DAT_3005ad44[3] = (int)cVar4;
        }
        if (*(int *)(iVar5 + uVar6 * 8) == 0x13) {
          DAT_3005ad44[4] = (int)cVar4;
        }
      }
    }
    bVar3 = bVar3 + 1;
    if ((uVar6 < 0x11) && (*(int *)(iVar5 + uVar6 * 8 + 4) != 0)) {
      os_printf(DAT_3005ad58,0);
      uVar1 = 0x13;
    }
    else {
      pvVar2 = malloc((uint)bVar3 * 0x10 + 0x10);
      if (pvVar2 == (void *)0x0) {
        os_printf(DAT_3005ad5c,0,bVar3);
        os_printf(DAT_3005ad60,0);
        uVar1 = 0x13;
      }
      else {
        os_memset(pvVar2,1,(uint)bVar3 * 0x10 + 0x10);
        os_memcpy(pvVar2,&local_134,(uint)bVar3 * 0x10 + 0x10);
        if (*(int *)(param_1 + 0x14) != 0) {
          free(*(void **)(param_1 + 0x14));
          *(undefined4 *)(param_1 + 0x14) = 0;
        }
        *(void **)(param_1 + 0x14) = pvVar2;
        *(byte *)(param_1 + 0x10) = bVar3;
        *(undefined2 *)(*(int *)(param_1 + 0xc) + 4) = *(undefined2 *)(param_2 + 4);
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14) = 0;
        *DAT_3005ad64 = param_2;
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_USB_FreeDevProfile @ 0x3005AA1C  (примерный размер ~160 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: free, os_memset
 * Вызывают: jstop_stack
 * Константы: 0x3005AA1C
 * Данные: DAT_3005ad40, DAT_3005ad68
 * ---------------------------------------------------------------- */
void BSP_USB_FreeDevProfile(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    param_1 = DAT_3005ad68;
  }
  for (uVar1 = 0; uVar1 < *(byte *)(param_1 + 4); uVar1 = uVar1 + 1) {
    if (*(int *)(uVar1 * 0x1c + *(int *)(param_1 + 8) + 0x14) != 0) {
      free(*(void **)(uVar1 * 0x1c + *(int *)(param_1 + 8) + 0x14));
      *(undefined4 *)(uVar1 * 0x1c + *(int *)(param_1 + 8) + 0x14) = 0;
    }
    *(undefined1 *)(uVar1 * 0x1c + *(int *)(param_1 + 8) + 0x10) = 0;
  }
  os_memset(DAT_3005ad40,0,0x11);
  return;
}

/* ----------------------------------------------------------------
 * BSP_USB_BuildDevArgs @ 0x3005AABC  (примерный размер ~504 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: BSP_USB_BuildDevProfile, BSP_USB_FindDevProfile, BSP_USB_GetDevDescIdx, os_printf
 * Вызывают: get_uw_args
 * Константы: 0x3005AABC
 * Данные: DAT_3005ad00, DAT_3005ad0c, DAT_3005ad18, DAT_3005ad20, DAT_3005ad6c, DAT_3005ad70, DAT_3005ad74, DAT_3005ad78
 * ---------------------------------------------------------------- */
undefined4 BSP_USB_BuildDevArgs(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_3005ad00;
  if (param_1 == 0) {
    os_printf(DAT_3005ad6c,0);
    uVar1 = 10;
  }
  else {
    uVar1 = BSP_USB_GetDevDescIdx();
    *DAT_3005ad70 = uVar1;
    iVar2 = BSP_USB_FindDevProfile(*DAT_3005ad70);
    if (((*(int *)(iVar3 + 0x10) == DAT_3005ad74) || (*(int *)(iVar3 + 0x10) == DAT_3005ad78)) ||
       (*(int *)(iVar3 + 0x10) == DAT_3005ad7c)) {
      if ((*DAT_3005ad0c == 0) || (*(int *)(iVar3 + 0x1c) != 0)) {
        if (*(int *)(iVar3 + 0x10) == DAT_3005ad78) {
          *DAT_3005ad70 = DAT_3005ad88;
          iVar2 = BSP_USB_FindDevProfile(*DAT_3005ad70);
        }
        else if (*(int *)(iVar3 + 0x10) == DAT_3005ad7c) {
          *DAT_3005ad70 = DAT_3005ad8c;
          iVar2 = BSP_USB_FindDevProfile(*DAT_3005ad70);
        }
      }
      else {
        *DAT_3005ad70 = DAT_3005ad84;
        iVar2 = BSP_USB_FindDevProfile(*DAT_3005ad70);
      }
    }
    else {
      iVar3 = *(int *)(iVar2 + 8);
      if (iVar3 != 0) {
        if (iVar3 == 1) {
          iVar2 = BSP_USB_FindDevProfile(DAT_3005ad20);
        }
        else {
          if (iVar3 != 2) {
            os_printf(DAT_3005ad80,0);
            return 0x13;
          }
          iVar2 = BSP_USB_FindDevProfile(DAT_3005ad18);
        }
      }
    }
    if (iVar2 == 0) {
      os_printf(DAT_3005ad90,0);
      uVar1 = 10;
    }
    else {
      iVar3 = BSP_USB_BuildDevProfile(*(undefined4 *)(param_1 + 8),iVar2);
      if (iVar3 == 0) {
        uVar1 = 0;
      }
      else {
        os_printf(DAT_3005ad94,0);
        uVar1 = 0x13;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_UDI_FindVcom @ 0x3005ACB4  (примерный размер ~344 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3005ACB4, 0x3005AE00, 0x3005ACD0
 * Данные: DAT_3005ad98
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x3005ae00) */

undefined4 BSP_UDI_FindVcom(uint param_1)

{
  undefined4 uVar1;
  
  if (5 < param_1) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x3005acd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(DAT_3005ad98 + param_1 * 4))();
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_Find_VCOM @ 0x3005AE0C  (примерный размер ~144 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_DLOAD_Init
 * Константы: 0x3005AE0C, 0x3005AE24, 0xFFFFFFFF
 * Данные: DAT_3005ae2c
 * ---------------------------------------------------------------- */
undefined4 BSP_Find_VCOM(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 6) {
                    /* WARNING: Could not recover jumptable at 0x3005ae24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_3005ae2c + param_1 * 4))();
    return uVar1;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * BSP_USB_DumpDevProt @ 0x3005AE9C  (примерный размер ~156 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: os_printf
 * Вызывают: BSP_USB_QueryDevProfile
 * Константы: 0x3005AE9C
 * Данные: DAT_3005afa0, DAT_3005afa4, DAT_3005afa8
 * ---------------------------------------------------------------- */
void BSP_USB_DumpDevProt(int param_1)

{
  byte bVar1;
  
  os_printf(DAT_3005afa0,0);
  bVar1 = 0;
  while (*(char *)(param_1 + (uint)bVar1 + 4) != '\0') {
    os_printf(DAT_3005afa4,0,bVar1,*(undefined1 *)(param_1 + (uint)bVar1 + 4));
    bVar1 = bVar1 + 1;
  }
  bVar1 = 0;
  while (*(char *)(param_1 + (uint)bVar1 + 0x15) != '\0') {
    os_printf(DAT_3005afa8,0,bVar1,*(undefined1 *)(param_1 + (uint)bVar1 + 0x15));
    bVar1 = bVar1 + 1;
  }
  os_printf(DAT_3005afa0,0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005af38 @ 0x3005AF38  (примерный размер ~480 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: os_printf
 * Вызывают: BSP_USB_QueryDevProfile
 * Константы: 0x3005AF38, 0x3005AF98
 * Данные: DAT_3005afac, DAT_3005afb0, DAT_3005b2ec
 * ---------------------------------------------------------------- */
undefined4 FUN_3005af38(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    os_printf(DAT_3005afac,0);
    uVar1 = 10;
  }
  else if ((int)-(uint)*(byte *)(param_1 + 2) < 0) {
    if (*(uint *)(param_1 + 0x10) < 0x14) {
                    /* WARNING: Could not recover jumptable at 0x3005af98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(DAT_3005afb0 + *(uint *)(param_1 + 0x10) * 4))();
      return uVar1;
    }
    os_printf(DAT_3005b2ec,0);
    uVar1 = 10;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_USB_QueryDevProfile @ 0x3005B118  (примерный размер ~384 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 6
 * Вызывает: BSP_USB_DumpDevProfile, BSP_USB_DumpDevProt, BSP_USB_FindDevProfile, FUN_3005af38, os_memset, os_printf
 * Константы: 0xFFFFFFFF, 0x3005B118
 * Данные: DAT_3005b2f0, DAT_3005b2f4, DAT_3005b2f8, DAT_3005b2fc, DAT_3005b300, DAT_3005b304, DAT_3005b308, DAT_3005b30c
 * ---------------------------------------------------------------- */
undefined4 BSP_USB_QueryDevProfile(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    os_printf(DAT_3005b2f0,0);
    uVar1 = 0xffffffff;
  }
  else {
    os_memset(param_1 + 4,0,0x11);
    os_memset(param_1 + 0x15,0,0x11);
    os_printf(DAT_3005b2f4,0,*DAT_3005b2f8);
    iVar2 = BSP_USB_FindDevProfile(*DAT_3005b2f8);
    if (iVar2 == 0) {
      os_printf(DAT_3005b2fc,0);
      uVar1 = 0xffffffff;
    }
    else {
      BSP_USB_DumpDevProfile(iVar2);
      iVar3 = FUN_3005af38(iVar2,param_1 + 0x15);
      if (iVar3 == 0) {
        iVar2 = *(int *)(iVar2 + 8);
        if (iVar2 == 0) {
          *(undefined1 *)(param_1 + 4) = 0xff;
          iVar2 = 0;
        }
        else if (iVar2 == 1) {
          uVar1 = BSP_USB_FindDevProfile(DAT_3005b308);
          iVar2 = FUN_3005af38(uVar1,param_1 + 4);
        }
        else {
          if (iVar2 != 2) {
            os_printf(DAT_3005b30c,0);
            return 0xffffffff;
          }
          uVar1 = BSP_USB_FindDevProfile(DAT_3005b304);
          iVar2 = FUN_3005af38(uVar1,param_1 + 4);
        }
        if (iVar2 == 0) {
          BSP_USB_DumpDevProt(param_1);
          uVar1 = 0;
        }
        else {
          os_printf(DAT_3005b310,0);
          uVar1 = 0xffffffff;
        }
      }
      else {
        os_printf(DAT_3005b300,0);
        uVar1 = 0xffffffff;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_USB_GetUwArgs @ 0x3005B298  (примерный размер ~36 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: get_dev_params, get_num_of_devices
 * Вызывают: get_uw_args
 * Константы: 0x3005B298
 * Данные: DAT_3005b314
 * ---------------------------------------------------------------- */
int BSP_USB_GetUwArgs(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  uVar2 = get_dev_params();
  *(undefined4 *)(DAT_3005b314 + 8) = uVar2;
  uVar1 = get_num_of_devices();
  *(undefined1 *)(DAT_3005b314 + 4) = uVar1;
  return DAT_3005b314;
}

/* ----------------------------------------------------------------
 * BSP_AcmGetDevNameByType @ 0x30061510  (примерный размер ~100 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30061510
 * Данные: DAT_3006233c, DAT_30062340, DAT_30062344, DAT_30062348
 * ---------------------------------------------------------------- */
undefined4 BSP_AcmGetDevNameByType(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (*DAT_3006233c < uVar1) {
      return 0;
    }
    if (*(int *)(DAT_30062340 + DAT_30062344 * uVar1) == param_1) break;
    uVar1 = uVar1 + 1;
  }
  return *(undefined4 *)(DAT_30062348 + DAT_30062344 * uVar1);
}

/* ----------------------------------------------------------------
 * BSP_AcmGetTypeStr @ 0x30061574  (примерный размер ~136 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_AcmDump
 * Константы: 0x30061574
 * Данные: DAT_30062464, DAT_30062468, DAT_3006246c, DAT_30062470, DAT_30062474, DAT_30062478, DAT_3006247c
 * ---------------------------------------------------------------- */
undefined4 BSP_AcmGetTypeStr(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_30062474;
  if (param_1 != 5) {
    uVar1 = DAT_3006247c;
    if (param_1 < 6) {
      if (param_1 == 1) {
        return DAT_30062464;
      }
      if (param_1 == 2) {
        return DAT_30062468;
      }
      if (param_1 == 3) {
        return DAT_30062470;
      }
    }
    else {
      if (param_1 == 6) {
        return DAT_3006246c;
      }
      if (param_1 == 0x13) {
        return DAT_30062478;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300615fc @ 0x300615FC  (примерный размер ~268 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: BSP_TRACE, jos_safe_enter_d, jos_safe_leave_d, semGive
 * Константы: 0xFFFFFFFF, 0x300615FC
 * Данные: DAT_30061b24, DAT_30062480, DAT_30062484, DAT_30062488, DAT_3006248c, DAT_30062490, DAT_30062584
 * ---------------------------------------------------------------- */
undefined4 FUN_300615fc(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    BSP_TRACE(4,0x14,DAT_30062480,DAT_30062484,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (*(int *)(param_1 + 0x28) == 0) {
    BSP_TRACE(4,0x14,DAT_30062488,DAT_3006248c,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    jos_safe_enter_d(DAT_30061b24,DAT_30062490);
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xcfc) = 0;
    if (*(int *)(param_1 + 0x74) != 0) {
      *(undefined4 *)(param_1 + 0x74) = 0;
      semGive(*(undefined4 *)(param_1 + 0x90));
    }
    jos_safe_leave_d(DAT_30061b24,DAT_30062584);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30061708 @ 0x30061708  (примерный размер ~620 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 11
 * Вызывает: BSP_TRACE, FUN_3005f620, FUN_3005f64c, FUN_3005f6fc, FUN_3005f8d0, FUN_3005fb3c, FUN_30060344, FUN_3006044c, jos_safe_enter_d, jos_safe_leave_d, taskDelay
 * Вызывают: FUN_30061974
 * Константы: 0xFFFFFFFF, 0x30061708
 * Данные: DAT_30061b18, DAT_30061b24, DAT_30062588, DAT_3006258c, DAT_30062590, DAT_30062594, DAT_30062598, DAT_3006259c
 * ---------------------------------------------------------------- */
undefined4 FUN_30061708(int param_1,uint *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar4 = 100;
  if (param_2 == (uint *)0x0) {
    BSP_TRACE(4,0x14,DAT_30062588,DAT_3006258c,0,0,0,0,0);
    uVar3 = 0xffffffff;
  }
  else {
    uVar6 = *param_2;
    uVar5 = param_2[1];
    if (((uVar6 == 0) || ((uVar6 & DAT_30062590) != 0)) || (uVar5 < 2)) {
      BSP_TRACE(4,0x14,DAT_30062598,uVar6,0x200,uVar5,2,DAT_30062594,0);
      uVar3 = DAT_30061b18;
    }
    else {
      jos_safe_enter_d(DAT_30061b24,DAT_3006259c);
      iVar7 = *(int *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x24) = 0;
      FUN_3005f620(param_1);
      jos_safe_leave_d(DAT_30061b24,DAT_300625a0);
      do {
        jos_safe_enter_d(DAT_30061b24,DAT_300625a4);
        iVar2 = FUN_30060344(param_1 + 0x50);
        if (iVar2 == *(int *)(param_1 + 0x68)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        while (iVar2 = FUN_3005fb3c(param_1), iVar2 != 0) {
          FUN_3005f64c(param_1,iVar2);
        }
        jos_safe_leave_d(DAT_30061b24,DAT_3006269c);
        if (bVar1) break;
        taskDelay(10);
        iVar4 = iVar4 + -1;
      } while (0 < iVar4);
      if (iVar4 < 1) {
        *(int *)(param_1 + 0x24) = iVar7;
        BSP_TRACE(4,0x14,DAT_300626a0,DAT_300626a4,0,0,0,0,0);
        uVar3 = 0xffffffff;
      }
      else {
        jos_safe_enter_d(DAT_30061b24,DAT_300626a8);
        FUN_3005f8d0(param_1);
        iVar4 = FUN_3006044c(param_1,uVar5,uVar6);
        if (iVar4 == 0) {
          *(int *)(param_1 + 0x24) = iVar7;
          if (iVar7 != 0) {
            FUN_3005f6fc(param_1);
          }
          jos_safe_leave_d(DAT_30061b24,DAT_300627b0);
          uVar3 = 0;
        }
        else {
          FUN_3005f8d0(param_1);
          jos_safe_leave_d(DAT_30061b24,DAT_300626ac);
          BSP_TRACE(4,0x14,DAT_300626b0,DAT_300627ac,0,0,0,0,0);
          uVar3 = 0xffffffff;
        }
      }
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_30061974 @ 0x30061974  (примерный размер ~904 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 6
 * Вызывает: BSP_TRACE, FUN_300608e8, FUN_30060b5c, FUN_300612f4, FUN_300613c4, FUN_30061708
 * Константы: 0x30061974
 * Данные: DAT_30061b18, DAT_30061d54, DAT_30062480, DAT_300627b4, DAT_300627b8, DAT_30062874, DAT_30062878, DAT_3006287c
 * ---------------------------------------------------------------- */
undefined4 FUN_30061974(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) == 0)) {
    BSP_TRACE(4,0x14,DAT_30062480,DAT_300627b4,0,0,0,0,0);
    return DAT_30061d54;
  }
  if (param_2 == DAT_300627b8) {
    if (param_3 != (undefined4 *)0x0) {
      uVar1 = FUN_30060b5c(param_1,*param_3,param_3[1]);
      return uVar1;
    }
    BSP_TRACE(4,0x14,DAT_300628a4,0,DAT_300628a0,0,0,0,0);
    return DAT_30061b18;
  }
  if (param_2 == DAT_300627b8 || param_2 < DAT_300627b8) {
    if (param_2 == DAT_30062874) {
LAB_30061aa8:
      *(undefined4 **)(param_1 + 0x7c) = param_3;
      return 0;
    }
    if (param_2 <= DAT_30062874) {
      if (param_2 != DAT_30062878) {
        if (param_2 == DAT_3006287c) goto LAB_30061aa8;
        if (param_2 != DAT_30062880) goto LAB_30061ca8;
      }
      *(undefined4 **)(param_1 + 200) = param_3;
      return 0;
    }
    if (param_2 == DAT_30062884) {
      *(undefined4 **)(param_1 + 0xcfc) = param_3;
      return 0;
    }
    if (param_2 == DAT_30062888) {
      *(undefined4 **)(param_1 + 0xcc) = param_3;
      return 0;
    }
  }
  else {
    if (param_2 == DAT_3006288c) {
      if (param_3 != (undefined4 *)0x0) {
        uVar1 = FUN_30061708(param_1,param_3);
        return uVar1;
      }
      BSP_TRACE(4,0x14,DAT_300628a4,0,DAT_30062978,0,0,0,0);
      return DAT_30062970;
    }
    if (param_2 == DAT_3006288c || param_2 < DAT_3006288c) {
      if (param_2 == DAT_30062890) {
        if (param_3 != (undefined4 *)0x0) {
          uVar1 = FUN_300612f4(param_1,param_3);
          return uVar1;
        }
        BSP_TRACE(4,0x14,DAT_300628a4,0,DAT_3006296c,0,0,0,0);
        return DAT_30062970;
      }
      if (param_2 == DAT_30062894) {
        if (param_3 != (undefined4 *)0x0) {
          uVar1 = FUN_300613c4(param_1,param_3);
          return uVar1;
        }
        BSP_TRACE(4,0x14,DAT_300628a4,0,DAT_30062974,0,0,0,0);
        return DAT_30062970;
      }
    }
    else {
      if (param_2 == DAT_30062898) {
        *(undefined4 *)(param_1 + 0xac) = 0;
        return 0;
      }
      if (param_2 == DAT_3006289c) {
        return *DAT_3006297c;
      }
    }
  }
LAB_30061ca8:
  uVar1 = FUN_300608e8(param_1,param_2,param_3);
  BSP_TRACE(1,0x14,DAT_30062984,param_2,param_3,uVar1,DAT_30062980,0,0);
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_AcmDump @ 0x30061CFC  (примерный размер ~836 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: BSP_AcmGetTypeStr, printf
 * Константы: 0xFFFFFFFF, 0x30061CFC
 * Данные: DAT_3006233c, DAT_30062344, DAT_30062988, DAT_3006298c, DAT_30062990, DAT_30062994, DAT_30062998, DAT_3006299c
 * ---------------------------------------------------------------- */
undefined4 BSP_AcmDump(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((int)param_1 < 1) && (*DAT_3006233c + 1U < param_1)) {
    printf(DAT_30062988,param_1,1,*DAT_3006233c + 1);
    uVar1 = 0xffffffff;
  }
  else if (*(int *)(DAT_3006298c + DAT_30062344 * (param_1 - 1)) == 0) {
    printf(DAT_30062990,param_1);
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = DAT_30062994 + DAT_30062344 * (param_1 - 1);
    printf(DAT_30062998);
    printf(DAT_3006299c);
    printf(DAT_300629a0,*(undefined4 *)(iVar2 + 0x20));
    uVar1 = BSP_AcmGetTypeStr(*(undefined4 *)(iVar2 + 0x2c));
    printf(DAT_300629a4,uVar1);
    printf(DAT_300629a8,*(undefined4 *)(iVar2 + 0x28));
    printf(DAT_300629ac,*(undefined4 *)(iVar2 + 0x24));
    uVar1 = DAT_300629b4;
    if (*(int *)(iVar2 + 0xd00) == 1) {
      uVar1 = DAT_300629b0;
    }
    printf(DAT_300629b8,uVar1);
    printf(DAT_300629bc,*(undefined4 *)(iVar2 + 0x44));
    printf(DAT_300629c0,*(undefined4 *)(iVar2 + 0xcfc));
    printf(DAT_300629c4,*(undefined4 *)(iVar2 + 0x34));
    printf(DAT_300629c8,*(undefined4 *)(iVar2 + 0x3c));
    printf(DAT_300629cc,*(undefined4 *)(iVar2 + 0x38));
    printf(DAT_300629d0,*(undefined4 *)(iVar2 + 0x40));
    printf(DAT_300629d4);
    printf(DAT_300629d8);
    printf(DAT_300629dc,*(undefined4 *)(iVar2 + 0x7c));
    printf(DAT_300629e0,*(undefined4 *)(iVar2 + 100));
    printf(DAT_300629e4,*(undefined4 *)(iVar2 + 0x68));
    printf(DAT_300629dc,*(undefined4 *)(iVar2 + 0x7c));
    printf(DAT_300629e8,*(undefined4 *)(iVar2 + 0x78));
    printf(DAT_300629ec,*(undefined4 *)(iVar2 + 0x80));
    printf(DAT_300629f0,*(undefined4 *)(iVar2 + 0x84));
    printf(DAT_300629f4,*(undefined4 *)(iVar2 + 0x88));
    printf(DAT_300629f8,*(undefined4 *)(iVar2 + 0x8c));
    printf(DAT_300629fc,*(undefined4 *)(iVar2 + 0x6c));
    printf(DAT_30062a00,*(undefined4 *)(iVar2 + 0x70));
    printf(DAT_300629d4);
    printf(DAT_30062a04);
    printf(DAT_30062a08,*(undefined4 *)(iVar2 + 200));
    printf(DAT_30062a0c,*(undefined4 *)(iVar2 + 0xa8));
    printf(DAT_30062a10,*(undefined4 *)(iVar2 + 0x94));
    printf(DAT_30062a14,*(undefined4 *)(iVar2 + 0x98));
    printf(DAT_30062a18,*(undefined4 *)(iVar2 + 0xb4));
    printf(DAT_30062a1c,*(undefined4 *)(iVar2 + 0xb8));
    printf(DAT_30062a20,*(undefined4 *)(iVar2 + 0xbc));
    printf(DAT_30062a24,*(undefined4 *)(iVar2 + 0xc0));
    printf(DAT_30062a28,*(undefined4 *)(iVar2 + 0xac));
    printf(DAT_30062a2c,*(undefined4 *)(iVar2 + 0xcd0));
    printf(DAT_30062a30,*(undefined4 *)(iVar2 + 0xcd4));
    printf(DAT_30062a34,*(undefined4 *)(iVar2 + 0xc4));
    printf(DAT_30062a38,*(undefined4 *)(iVar2 + 0xcd8));
    printf(DAT_30062a3c,*(undefined4 *)(iVar2 + 0xcdc));
    printf(DAT_30062998);
    printf(DAT_30062a40);
    printf(DAT_30062a44);
    printf(DAT_30062a48);
    printf(DAT_30062998);
    if (param_2 != 0) {
      *(undefined4 *)(iVar2 + 0x80) = 0;
      *(undefined4 *)(iVar2 + 0x84) = 0;
      *(undefined4 *)(iVar2 + 0x88) = 0;
    }
    if (param_3 != 0) {
      *(undefined4 *)(iVar2 + 0xb4) = 0;
      *(undefined4 *)(iVar2 + 0xbc) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_AcmDumpList @ 0x30062040  (примерный размер ~1156 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300628c8, printf
 * Константы: 0xFFFFFFFF, 0x30062040
 * Данные: DAT_30062344, DAT_30062988, DAT_3006298c, DAT_30062990, DAT_30062994, DAT_30062998, DAT_30062a4c, DAT_30062a50
 * ---------------------------------------------------------------- */
undefined4 BSP_AcmDumpList(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_2c [3];
  
  local_2c[0] = *DAT_30062a4c;
  local_2c[1] = DAT_30062a4c[1];
  local_2c[2] = DAT_30062a4c[2];
  if ((param_1 < 1) && (*DAT_30062a50 < param_1)) {
    printf(DAT_30062988,param_1,1,*DAT_30062a50);
    uVar1 = 0xffffffff;
  }
  else if (*(int *)(DAT_3006298c + DAT_30062344 * (param_1 + -1)) == 0) {
    printf(DAT_30062990,param_1);
    uVar1 = 0xffffffff;
  }
  else {
    iVar5 = DAT_30062994 + DAT_30062344 * (param_1 + -1);
    printf(DAT_30062a54,*(undefined4 *)(iVar5 + 0x68));
    for (uVar4 = 0; uVar4 < *(uint *)(iVar5 + 0x68); uVar4 = uVar4 + 1) {
      printf(DAT_30062a58,uVar4,uVar4 * 0x24 + *(int *)(iVar5 + 0x48));
      printf(DAT_30062a5c,uVar4,local_2c[*(int *)(uVar4 * 0x24 + *(int *)(iVar5 + 0x48) + 8)]);
      printf(DAT_30062a60,uVar4,*(undefined4 *)(uVar4 * 0x24 + *(int *)(iVar5 + 0x48) + 0xc));
      printf(DAT_30062a64,uVar4,*(undefined4 *)(uVar4 * 0x24 + *(int *)(iVar5 + 0x48) + 0x1c));
      printf(DAT_30062a68,uVar4,*(undefined4 *)(uVar4 * 0x24 + *(int *)(iVar5 + 0x48) + 0x20));
      printf(DAT_30062a6c,uVar4,*(undefined4 *)(uVar4 * 0x24 + *(int *)(iVar5 + 0x48) + 0x18));
      printf(DAT_30062a70,uVar4,*(undefined4 *)(*(int *)(iVar5 + 0x48) + uVar4 * 0x24));
      printf(DAT_30062a74,uVar4,*(undefined4 *)(uVar4 * 0x24 + *(int *)(iVar5 + 0x48) + 4));
      printf(DAT_30062a78);
    }
    printf(DAT_30062998);
    iVar2 = FUN_300628c8(iVar5 + 0x50);
    if (iVar2 == 0) {
      puVar3 = *(undefined4 **)(iVar5 + 0x50);
      printf(DAT_30062a80);
      printf(DAT_30062a84,iVar5 + 0x50);
      printf(DAT_30062a88,*(undefined4 *)(iVar5 + 0x50));
      printf(DAT_30062a8c,*(undefined4 *)(iVar5 + 0x54));
      printf(DAT_30062a78);
      uVar4 = 0;
      do {
        if ((undefined4 *)(iVar5 + 0x50) == puVar3) goto LAB_30062368;
        printf(DAT_30062a90,puVar3);
        printf(DAT_30062a94,local_2c[puVar3[2]]);
        printf(DAT_30062a98,puVar3[3]);
        printf(DAT_30062a9c,puVar3[7]);
        printf(DAT_30062aa0,puVar3[8]);
        printf(DAT_30062aa4,puVar3[6]);
        printf(DAT_30062aa8,*puVar3);
        printf(DAT_30062aac,puVar3[1]);
        printf(DAT_30062a78);
        puVar3 = (undefined4 *)*puVar3;
        uVar4 = uVar4 + 1;
      } while (uVar4 <= *(uint *)(iVar5 + 0x68));
      printf(DAT_30062ab0);
LAB_30062368:
      printf(DAT_30062ab4,uVar4);
    }
    else {
      printf(DAT_30062a7c);
    }
    iVar2 = FUN_300628c8(iVar5 + 0x58);
    if (iVar2 == 0) {
      puVar3 = *(undefined4 **)(iVar5 + 0x58);
      printf(DAT_30062abc);
      printf(DAT_30062ac0,iVar5 + 0x58);
      printf(DAT_30062ac4,*(undefined4 *)(iVar5 + 0x58));
      printf(DAT_30062ac8,*(undefined4 *)(iVar5 + 0x5c));
      printf(DAT_30062a78);
      uVar4 = 0;
      do {
        if ((undefined4 *)(iVar5 + 0x58) == puVar3) goto LAB_300624ac;
        printf(DAT_30062a90,puVar3);
        printf(DAT_30062a94,local_2c[puVar3[2]]);
        printf(DAT_30062a98,puVar3[3]);
        printf(DAT_30062a9c,puVar3[7]);
        printf(DAT_30062aa0,puVar3[8]);
        printf(DAT_30062aa4,puVar3[6]);
        printf(DAT_30062aa8,*puVar3);
        printf(DAT_30062aac,puVar3[1]);
        printf(DAT_30062a78);
        puVar3 = (undefined4 *)*puVar3;
        uVar4 = uVar4 + 1;
      } while (uVar4 <= *(uint *)(iVar5 + 0x68));
      printf(DAT_30062acc);
LAB_300624ac:
      printf(DAT_30062ad0,uVar4);
    }
    else {
      printf(DAT_30062ab8);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300624c4 @ 0x300624C4  (примерный размер ~412 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 5
 * Вызывает: BSP_TRACE, FUN_30060740, iosDevDelete, iosDrvInstall, snprintf
 * Вызывают: uwd_acm_app_init
 * Константы: 0x300624C4, 0xFFFFFFFF
 * Данные: DAT_30062994, DAT_30062a50, DAT_30062ad4, DAT_30062ad8, DAT_30062adc, DAT_30062ae0, DAT_30062ae4, DAT_30062ae8
 * ---------------------------------------------------------------- */
undefined4 FUN_300624c4(int param_1)

{
  int iVar1;
  
  if (*DAT_30062a50 <= *DAT_30062ad4) {
    return 0;
  }
  if (*DAT_30062ad8 < 1) {
    iVar1 = iosDrvInstall(DAT_30062ae8,0,DAT_30062ae8,DAT_30062aec,DAT_30062adc,DAT_30062ae0,
                          DAT_30062ae4);
    *DAT_30062ad8 = iVar1;
    if (*DAT_30062ad8 == -1) {
      BSP_TRACE(4,0x14,DAT_30062af0,DAT_30062af4,0,0,0,0,0);
      goto LAB_30062638;
    }
  }
  snprintf(*(char **)(param_1 + 0x20),0x1f,DAT_30062af8,*DAT_30062ad4 + 1);
  iVar1 = FUN_30060740(*(undefined4 *)(param_1 + 0x20),*DAT_30062ad4);
  if (iVar1 == 0) {
    *DAT_30062ad4 = *DAT_30062ad4 + 1;
    return 0;
  }
  BSP_TRACE(4,0x14,DAT_30062afc,DAT_30062b00,0,0,0,0,0);
LAB_30062638:
  iosDevDelete(DAT_30062994 + DAT_30062b04 * *DAT_30062ad4);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * PWRCTRL_I2C_SoftClkStatus @ 0x30063C68  (примерный размер ~80 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: logMsg
 * Константы: 0x30063C68
 * Данные: DAT_30064134, DAT_30064138
 * ---------------------------------------------------------------- */
void PWRCTRL_I2C_SoftClkStatus(void)

{
  logMsg(DAT_30064138,*DAT_30064134 >> 0x1b & 1,0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_I2C_SoftClkDis @ 0x30063CB8  (примерный размер ~16 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 0
 * Вызывают: BSP_I2C_DataRx, BSP_I2C_DataTx
 * Константы: 0x30063CB8, 0x08000000
 * Данные: DAT_3006413c
 * ---------------------------------------------------------------- */
void PWRCTRL_I2C_SoftClkDis(void)

{
  *DAT_3006413c = 0x8000000;
  return;
}

/* ----------------------------------------------------------------
 * PWRCTRL_I2C_SoftClkEn @ 0x30063CC8  (примерный размер ~16 байт)
 * Модуль: bsp | Вызывают: 2 | Вызывает: 0
 * Вызывают: BSP_I2C_DataRx, BSP_I2C_DataTx
 * Константы: 0x30063CC8, 0x08000000
 * Данные: DAT_30064140
 * ---------------------------------------------------------------- */
void PWRCTRL_I2C_SoftClkEn(void)

{
  *DAT_30064140 = 0x8000000;
  return;
}

/* ----------------------------------------------------------------
 * BSP_I2C_DataTx @ 0x30063D5C  (примерный размер ~424 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: I2C_StatusCheck, PWRCTRL_I2C_SoftClkDis, PWRCTRL_I2C_SoftClkEn, logMsg
 * Константы: 0xFFFFFFFF, 0x30063D5C
 * Данные: DAT_3006414c, DAT_30064154, DAT_30064158, DAT_3006415c, DAT_30064160, DAT_30064164, DAT_30064168, DAT_3006416c
 * ---------------------------------------------------------------- */
undefined4 BSP_I2C_DataTx(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  PWRCTRL_I2C_SoftClkEn();
  *DAT_30064154 = 0x77;
  *DAT_30064158 = 0x77;
  *DAT_3006414c = 0x7f;
  *DAT_3006415c = DAT_30064160;
  *DAT_30064164 = 10;
  iVar1 = I2C_StatusCheck();
  if (iVar1 == 0) {
    *DAT_30064170 = param_1 & 0xff;
    *DAT_30064164 = 2;
    iVar1 = I2C_StatusCheck();
    if (iVar1 == 0) {
      *DAT_30064170 = param_2 & 0xff;
      *DAT_30064164 = 2;
      iVar1 = I2C_StatusCheck();
      if (iVar1 == 0) {
        *DAT_30064164 = 1;
        iVar1 = I2C_StatusCheck();
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          logMsg(DAT_30064168,DAT_3006417c,1,2,3,4,5);
          PWRCTRL_I2C_SoftClkDis();
          uVar2 = 0xffffffff;
        }
      }
      else {
        logMsg(DAT_30064168,DAT_30064178,1,2,3,4,5);
        PWRCTRL_I2C_SoftClkDis();
        uVar2 = 0xffffffff;
      }
    }
    else {
      logMsg(DAT_30064168,DAT_30064174,1,2,3,4,5);
      PWRCTRL_I2C_SoftClkDis();
      uVar2 = 0xffffffff;
    }
  }
  else {
    logMsg(DAT_30064168,DAT_3006416c,1,2,3,4,5);
    PWRCTRL_I2C_SoftClkDis();
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_CY22393_Init @ 0x30063F04  (примерный размер ~56 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30063F04, 0x08000000, 0xFFFFFBFF
 * Данные: DAT_30064140, DAT_30064180
 * ---------------------------------------------------------------- */
undefined4 BSP_CY22393_Init(void)

{
  *DAT_30064140 = 0x8000000;
  *DAT_30064180 = *DAT_30064180 & 0xfffffbff | 0x4000;
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_I2C_DataRx @ 0x30063F3C  (примерный размер ~604 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 4
 * Вызывает: I2C_StatusCheck, PWRCTRL_I2C_SoftClkDis, PWRCTRL_I2C_SoftClkEn, logMsg
 * Константы: 0xFFFFFFFF, 0x30063F3C
 * Данные: DAT_3006414c, DAT_30064154, DAT_30064158, DAT_3006415c, DAT_30064160, DAT_30064164, DAT_30064168, DAT_30064170
 * ---------------------------------------------------------------- */
undefined4 BSP_I2C_DataRx(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  PWRCTRL_I2C_SoftClkEn();
  *DAT_30064154 = 0x77;
  *DAT_30064158 = 0x77;
  *DAT_3006414c = 0x7f;
  *DAT_3006415c = DAT_30064160;
  *DAT_30064170 = 0xd2;
  *DAT_30064164 = 10;
  iVar1 = I2C_StatusCheck();
  if (iVar1 == 0) {
    *DAT_30064170 = param_1 & 0xff;
    *DAT_30064164 = 2;
    iVar1 = I2C_StatusCheck();
    if (iVar1 == 0) {
      *DAT_30064170 = 0xd3;
      *DAT_30064164 = 10;
      iVar1 = I2C_StatusCheck();
      if (iVar1 == 0) {
        *DAT_30064164 = 0x14;
        iVar1 = I2C_StatusCheck();
        if (iVar1 == 0) {
          uVar2 = *DAT_30064190;
          *DAT_30064164 = 1;
          iVar1 = I2C_StatusCheck();
          if (iVar1 != 0) {
            logMsg(DAT_30064168,DAT_30064194,1,2,3,4,5);
            uVar2 = 0xffffffff;
          }
        }
        else {
          logMsg(DAT_30064168,DAT_3006418c,1,2,3,4,5);
          uVar2 = 0xffffffff;
        }
      }
      else {
        logMsg(DAT_30064168,DAT_30064188,1,2,3,4,5);
        uVar2 = 0xffffffff;
      }
    }
    else {
      logMsg(DAT_30064168,DAT_30064184,1,2,3,4,5);
      uVar2 = 0xffffffff;
    }
  }
  else {
    logMsg(DAT_30064168,0x290,1,2,3,4,5);
    PWRCTRL_I2C_SoftClkDis();
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_SendData @ 0x30075010  (примерный размер ~184 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_TRACE, ioctl
 * Вызывают: dloadUSBSend
 * Константы: 0x30075010
 * Данные: DAT_30075f70, DAT_30075f74, DAT_30075f78, DAT_30075f7c, DAT_30075f80
 * ---------------------------------------------------------------- */
undefined4 BSP_DLOAD_SendData(uint param_1,int param_2)

{
  undefined4 uVar1;
  uint local_18;
  uint local_14;
  uint local_10;
  
  local_18 = *DAT_30075f70;
  local_14 = DAT_30075f70[1];
  local_10 = DAT_30075f70[2];
  if ((((param_1 & 0x1f) == 0) && (param_2 != 0)) && (param_1 != 0)) {
    local_18 = param_1;
    local_14 = param_2;
    ioctl(*DAT_30075f7c,DAT_30075f80,&local_18);
    uVar1 = 0;
  }
  else {
    BSP_TRACE(4,0x1e,DAT_30075f74,param_1,param_2,3,4,5,6);
    uVar1 = DAT_30075f78;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_SetSoftLoad @ 0x300750C8  (примерный размер ~48 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 0
 * Вызывают: dloadBootromEnd, dloadFromFsMainThread, update_WebUITask, usrAppInit
 * Константы: 0x300750C8
 * Данные: DAT_30075f84, DAT_30075f88
 * ---------------------------------------------------------------- */
void BSP_DLOAD_SetSoftLoad(int param_1)

{
  if (param_1 == 0) {
    *DAT_30075f84 = 0;
  }
  else {
    *DAT_30075f84 = DAT_30075f88;
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetMidwayRestart @ 0x300750F8  (примерный размер ~88 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: OSAL_LogMsg
 * Вызывают: BSP_DLOAD_GetDloadInfo
 * Константы: 0x300750F8
 * Данные: DAT_30075f8c, DAT_30075f90, DAT_30075f94
 * ---------------------------------------------------------------- */
bool BSP_DLOAD_GetMidwayRestart(void)

{
  OSAL_LogMsg(DAT_30075f8c,*DAT_30075f90,2,3,4,5,6);
  return *DAT_30075f90 == DAT_30075f94;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_SetMidwayRestart @ 0x30075150  (примерный размер ~104 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: OSAL_LogMsg
 * Вызывают: dloadBootromEnd
 * Константы: 0x30075150
 * Данные: DAT_30075f90, DAT_30075f94, DAT_300760cc
 * ---------------------------------------------------------------- */
void BSP_DLOAD_SetMidwayRestart(int param_1)

{
  if (param_1 == 0) {
    *DAT_30075f90 = 0;
  }
  else {
    *DAT_30075f90 = DAT_30075f94;
  }
  OSAL_LogMsg(DAT_300760cc,*DAT_30075f90,2,3,4,5,6);
  return;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetSoftwareVer @ 0x300751B8  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 3 | Вызывает: 1
 * Вызывает: BSP_OM_GetDloadVer
 * Вызывают: BSP_DLOAD_GetDloadInfo, TFUP_CheckVersionMatch, dloadUSBSendPro
 * Константы: 0x300751B8
 * ---------------------------------------------------------------- */
void BSP_DLOAD_GetSoftwareVer(undefined4 param_1,undefined4 param_2)

{
  BSP_OM_GetDloadVer(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetISOVer @ 0x300751D4  (примерный размер ~144 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 4
 * Вызывает: OSAL_LogMsg, getCdromVersion, memcpy, strlen
 * Вызывают: BSP_DLOAD_GetDloadInfo
 * Константы: 0x300751D4
 * Данные: DAT_300760d0, DAT_300760d4, DAT_300760d8
 * ---------------------------------------------------------------- */
int BSP_DLOAD_GetISOVer(void *param_1,undefined4 param_2)

{
  int iVar1;
  size_t sVar2;
  
  iVar1 = getCdromVersion(param_1,param_2);
  if (iVar1 != 0) {
    sVar2 = strlen(DAT_300760d0);
    memcpy(param_1,DAT_300760d4,sVar2);
    sVar2 = strlen(DAT_300760d0);
    *(undefined1 *)(sVar2 + (int)param_1) = 0;
    OSAL_LogMsg(DAT_300760d8,param_1,2,3,4,5,6);
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetDloadInfo @ 0x30075264  (примерный размер ~724 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 11
 * Вызывает: BSP_DLOAD_GetISOVer, BSP_DLOAD_GetMidwayRestart, BSP_DLOAD_GetSoftwareVer, BSP_GetProductDloadName, OSAL_LogMsg, free, malloc, memset, sprintf, strcat, strcpy
 * Вызывают: dloadInfoATHandle
 * Константы: 0xFFFFFFFF, 0x30075264
 * Данные: DAT_300760dc, DAT_3007617c, DAT_30076180, DAT_30076184, DAT_30076248, DAT_3007624c, DAT_30076250, DAT_30076254
 * ---------------------------------------------------------------- */
undefined4 BSP_DLOAD_GetDloadInfo(char *param_1,int param_2)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char acStack_11c [256];
  
  pcVar4 = acStack_11c;
  iVar7 = 0x7f;
  pcVar6 = DAT_300760dc;
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
  *pcVar4 = *pcVar6;
  pcVar6 = (char *)malloc(0x81);
  if (pcVar6 == (char *)0x0) {
    OSAL_LogMsg(DAT_3007617c,1,2,3,4,5,6);
    uVar3 = 0xffffffff;
  }
  else {
    memset(pcVar6,0,0x81);
    iVar7 = BSP_DLOAD_GetSoftwareVer(pcVar6,0x1e);
    if (iVar7 == 0) {
      if (param_2 == 1) {
        sprintf(param_1,DAT_30076184,pcVar6);
      }
      else if (param_2 == 0) {
        sprintf(param_1,DAT_30076248,pcVar6);
      }
      memset(pcVar6,0,0x80);
      iVar7 = BSP_DLOAD_GetISOVer(pcVar6,0x80);
      if (iVar7 != 0) {
        OSAL_LogMsg(DAT_3007624c,1,2,3,4,5,6);
        strcpy(pcVar6,DAT_30076250);
      }
      memset(acStack_11c,0,0xff);
      sprintf(acStack_11c,DAT_30076254,pcVar6);
      strcat(param_1,acStack_11c);
      memset(acStack_11c,0,0xff);
      iVar7 = BSP_GetProductDloadName(acStack_11c,0xff);
      if (iVar7 != 0) {
        OSAL_LogMsg(DAT_30076278,1,2,3,4,5,6);
        strcpy(pcVar6,DAT_30076250);
      }
      strcat(param_1,DAT_3007627c);
      strcat(param_1,acStack_11c);
      strcat(param_1,DAT_30076280);
      memset(acStack_11c,0,0xff);
      iVar7 = BSP_DLOAD_GetMidwayRestart();
      sprintf(acStack_11c,DAT_30076284,(uint)(iVar7 == 0));
      strcat(param_1,acStack_11c);
      if (param_2 == 1) {
        strcat(param_1,DAT_30076288);
      }
      free(pcVar6);
      uVar3 = 0;
    }
    else {
      OSAL_LogMsg(DAT_30076180,1,2,3,4,5,6);
      free(pcVar6);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetSoftLoad @ 0x30075538  (примерный размер ~36 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30075538
 * Данные: DAT_30075f84, DAT_30075f88
 * ---------------------------------------------------------------- */
bool BSP_DLOAD_GetSoftLoad(void)

{
  return *DAT_30075f84 == DAT_30075f88;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_SetCdromMarker @ 0x3007555C  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 7 | Вызывает: 1
 * Вызывает: setCdromFlag
 * Вызывают: BSP_TFUP_CompleteDeal, FUN_30080798, TFUP_CompleteDeal, TFUP_DloadTask, TFUP_IdentifyFile, dloadFromFsMainThread, update_WebUITask
 * Константы: 0x3007555C
 * ---------------------------------------------------------------- */
void BSP_DLOAD_SetCdromMarker(undefined4 param_1)

{
  setCdromFlag(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetCdromMarker @ 0x30075570  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30075570
 * Данные: DAT_300769c4, DAT_300769c8
 * ---------------------------------------------------------------- */
bool BSP_DLOAD_GetCdromMarker(void)

{
  return *(int *)(DAT_300769c4 + 0x18) != DAT_300769c8;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_SetDloadComplete @ 0x30075574  (примерный размер ~48 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrAppInit
 * Константы: 0x30075574
 * Данные: DAT_30075f84, DAT_3007628c
 * ---------------------------------------------------------------- */
void BSP_DLOAD_SetDloadComplete(int param_1)

{
  if (param_1 == 0) {
    *(undefined4 *)(DAT_30075f84 + 8) = 0;
  }
  else {
    *(undefined4 *)(DAT_30075f84 + 8) = DAT_3007628c;
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetNVBackupFlag @ 0x30075B68  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30075B68
 * Данные: DAT_300762e0, DAT_300762e4
 * ---------------------------------------------------------------- */
bool BSP_DLOAD_GetNVBackupFlag(void)

{
  return *DAT_300762e0 == DAT_300762e4;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetDloadVer @ 0x30075B84  (примерный размер ~56 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 2
 * Вызывает: getDloadVersion, strlen
 * Константы: 0x30075B84
 * ---------------------------------------------------------------- */
size_t BSP_DLOAD_GetDloadVer(char *param_1,undefined4 param_2)

{
  size_t sVar1;
  
  sVar1 = getDloadVersion(param_1,param_2);
  if (sVar1 == 0) {
    sVar1 = strlen(param_1);
  }
  return sVar1;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetProductId @ 0x30075BBC  (примерный размер ~184 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 6
 * Вызывает: BSP_TRACE, getDloadID, memset, printf, strlen, strncpy
 * Константы: 0x30075BBC, 0xFFFFFFFF
 * Данные: DAT_300762e8, DAT_300762ec
 * ---------------------------------------------------------------- */
size_t BSP_DLOAD_GetProductId(char *param_1,size_t param_2)

{
  char *pcVar1;
  size_t __n;
  
  pcVar1 = (char *)getDloadID();
  __n = strlen(pcVar1);
  printf(DAT_300762e8);
  if ((param_1 == (char *)0x0) || ((int)param_2 < (int)__n)) {
    BSP_TRACE(4,0x1e,DAT_300762ec,param_1,param_2,3,4,5,6);
    __n = 0xffffffff;
  }
  else {
    memset(param_1,0,param_2);
    pcVar1 = (char *)getDloadID();
    strncpy(param_1,pcVar1,__n);
  }
  return __n;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetBootromVer @ 0x30075C74  (примерный размер ~8 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30075C74
 * ---------------------------------------------------------------- */
undefined4 BSP_DLOAD_GetBootromVer(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetCurMode @ 0x30075C7C  (примерный размер ~64 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 0
 * Вызывают: BSP_DLOAD_GetDloadType
 * Константы: 0x30075C7C
 * Данные: DAT_30075f84, DAT_300762f0, DAT_300762f4
 * ---------------------------------------------------------------- */
int BSP_DLOAD_GetCurMode(void)

{
  int iVar1;
  
  if (*(int *)(DAT_30075f84 + 4) == DAT_300762f0) {
    iVar1 = 1;
  }
  else {
    iVar1 = (uint)(*(int *)(DAT_30075f84 + 4) == DAT_300762f4) << 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetDloadType @ 0x30075CBC  (примерный размер ~24 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: BSP_DLOAD_GetCurMode
 * Константы: 0x30075CBC
 * ---------------------------------------------------------------- */
bool BSP_DLOAD_GetDloadType(void)

{
  int iVar1;
  
  iVar1 = BSP_DLOAD_GetCurMode();
  return iVar1 != 1;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetAuthorityVer @ 0x30075CD4  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: getAuthorityVersion
 * Константы: 0x30075CD4
 * ---------------------------------------------------------------- */
void BSP_DLOAD_GetAuthorityVer(undefined4 param_1,undefined4 param_2)

{
  getAuthorityVersion(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetAuthorityId @ 0x30075CF0  (примерный размер ~28 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: getAuthorityId
 * Константы: 0x30075CF0
 * ---------------------------------------------------------------- */
void BSP_DLOAD_GetAuthorityId(undefined4 param_1,undefined4 param_2)

{
  getAuthorityId(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_Reset @ 0x30075D0C  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 4 | Вызывает: 2
 * Вызывает: BSP_WDT_reboot_direct, printf
 * Вызывают: BSP_TFUP_CompleteDeal, TFUP_CompleteDeal, dloadBootromEnd, dloadDealBootrom
 * Константы: 0x30075D0C
 * Данные: DAT_300762f8
 * ---------------------------------------------------------------- */
void BSP_DLOAD_Reset(void)

{
  printf(DAT_300762f8);
  BSP_WDT_reboot_direct();
  return;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_SetCurMode @ 0x30075D20  (примерный размер ~68 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30075D20
 * Данные: DAT_30075f84, DAT_300762f0, DAT_300762f4
 * ---------------------------------------------------------------- */
void BSP_DLOAD_SetCurMode(int param_1)

{
  if (param_1 == 1) {
    *(undefined4 *)(DAT_30075f84 + 4) = DAT_300762f0;
  }
  else if (param_1 == 2) {
    *(undefined4 *)(DAT_30075f84 + 4) = DAT_300762f4;
  }
  else {
    *(undefined4 *)(DAT_30075f84 + 4) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetDloadNetMode @ 0x30075D64  (примерный размер ~20 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: getDloadNetMode
 * Константы: 0x30075D64
 * ---------------------------------------------------------------- */
void BSP_DLOAD_GetDloadNetMode(undefined4 param_1)

{
  getDloadNetMode(param_1);
  return;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_GetDloadFlashInfo @ 0x30075D78  (примерный размер ~160 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 5
 * Вызывает: __udiv32, logMsg, memset, nand_get_spec, printf
 * Константы: 0x30075D78, 0xFFFFFFFF
 * Данные: DAT_30076294, DAT_300762fc
 * ---------------------------------------------------------------- */
undefined4 BSP_DLOAD_GetDloadFlashInfo(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  printf(DAT_300762fc);
  if (param_1 == (undefined4 *)0x0) {
    logMsg(DAT_30076294,1,2,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else {
    memset(param_1,0,0xc);
    nand_get_spec(&local_18);
    uVar1 = __udiv32(local_10,local_18);
    *param_1 = uVar1;
    param_1[1] = local_14;
    uVar1 = __udiv32(local_18,local_14);
    param_1[2] = uVar1;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_AtProcReg @ 0x30075E18  (примерный размер ~48 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30075E18
 * ---------------------------------------------------------------- */
undefined4 BSP_DLOAD_AtProcReg(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30075e48 @ 0x30075E48  (примерный размер ~120 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 3
 * Вызывает: dloadUSBCallback, ioctl, semTake
 * Вызывают: BSP_DLOAD_Init
 * Константы: 0x30075E48, 0xFFFFFFFF
 * Данные: DAT_30076300, DAT_30076304, DAT_30076308, DAT_3007630c
 * ---------------------------------------------------------------- */
void FUN_30075e48(int param_1)

{
  int iVar1;
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  
  local_14 = *DAT_30076304;
  local_10 = DAT_30076304[1];
  local_c = DAT_30076304[2];
  do {
    semTake(*DAT_30076300,0xffffffff);
    while (iVar1 = ioctl(param_1,DAT_30076308,&local_14), iVar1 == 0) {
      dloadUSBCallback(local_14,local_10 & 0xffff);
      ioctl(param_1,DAT_3007630c,&local_14);
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_30075ec0 @ 0x30075EC0  (примерный размер ~60 байт)
 * Модуль: bsp | Вызывают: 1 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: BSP_DLOAD_Init
 * Константы: 0x30075EC0
 * Данные: DAT_30076310
 * ---------------------------------------------------------------- */
void FUN_30075ec0(void)

{
  logMsg(DAT_30076310,0,0,0,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_Init @ 0x30075EFC  (примерный размер ~884 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 9
 * Вызывает: BSP_Find_VCOM, BSP_TRACE, FUN_30075e48, FUN_30075ec0, ioctl, open, semBCreate, sprintf, taskDelay
 * Константы: 0xFFFFFFFF, 0x30075EFC
 * Данные: DAT_30076300, DAT_30076314, DAT_30076318, DAT_3007631c, DAT_30076320, DAT_30076324, DAT_30076328, DAT_3007632c
 * ---------------------------------------------------------------- */
undefined4 BSP_DLOAD_Init(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 local_44;
  uint local_40;
  char acStack_3c [32];
  
  uVar9 = 0xffffffff;
  iVar7 = -1;
  pcVar4 = acStack_3c;
  iVar10 = 0x10;
  pcVar6 = DAT_30076314;
  do {
    pcVar5 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 2;
    cVar2 = *pcVar5;
    iVar10 = iVar10 + -1;
    pcVar5 = pcVar4 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 2;
    *pcVar5 = cVar2;
  } while (iVar10 != 0);
  local_44 = *DAT_30076318;
  local_40 = DAT_30076318[1];
  while( true ) {
    do {
      iVar10 = BSP_Find_VCOM(1);
    } while (iVar10 == -1);
    sprintf(acStack_3c,DAT_3007631c,DAT_30076320,iVar10);
    iVar10 = open(acStack_3c,2,0);
    if (0 < iVar10) break;
    BSP_TRACE(3,0x1e,DAT_30076324,acStack_3c,2,3,4,5,6);
    taskDelay(200);
  }
  BSP_TRACE(1,0x1e,DAT_30076328,acStack_3c,iVar10,3,4,5,6);
  *DAT_3007632c = iVar10;
  iVar3 = semBCreate(0,0);
  *DAT_30076300 = iVar3;
  if (*DAT_30076300 == 0) {
    BSP_TRACE(4,0x1e,DAT_30076330,1,2,3,4,5,6);
    uVar9 = DAT_30076334;
  }
  else {
    for (uVar8 = 0x100; 7 < uVar8; uVar8 = uVar8 >> 1) {
      local_44 = 0x2200;
      local_40 = uVar8;
      iVar7 = ioctl(iVar10,DAT_30076338,&local_44);
      if (iVar7 == 0) break;
    }
    if (iVar7 == 0) {
      iVar7 = ioctl(iVar10,DAT_30076344,DAT_30076340);
      if (iVar7 == 0) {
        iVar7 = ioctl(iVar10,DAT_30076350,DAT_3007634c);
        if (iVar7 == 0) {
          FUN_30075e48(iVar10);
        }
        else {
          BSP_TRACE(4,0x1e,DAT_30076354,1,2,3,4,5,6);
          uVar9 = 0xffffffff;
        }
      }
      else {
        BSP_TRACE(4,0x1e,DAT_30076348,1,2,3,4,5,6);
        uVar9 = 0xffffffff;
      }
    }
    else {
      BSP_TRACE(4,0x1e,DAT_3007633c,1,2,3,4,5,6);
      uVar9 = 0xffffffff;
    }
  }
  FUN_30075ec0();
  return uVar9;
}

/* ----------------------------------------------------------------
 * BSP_DLOAD_Show @ 0x30076270  (примерный размер ~236 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x30076270
 * Данные: DAT_30076358
 * ---------------------------------------------------------------- */
void BSP_DLOAD_Show(void)

{
  printf(DAT_30076358);
  return;
}

/* ----------------------------------------------------------------
 * ledFlush @ 0x300764CC  (примерный размер ~112 байт)
 * Модуль: bsp | Вызывают: 3 | Вызывает: 2
 * Вызывает: DLOAD_LEDInd, logMsg
 * Вызывают: FUN_30080798, TFUP_CheckFileValidify, dloadTFCallback
 * Константы: 0x300764CC
 * Данные: DAT_300769a8, DAT_300769ac
 * ---------------------------------------------------------------- */
bool ledFlush(int param_1)

{
  int iVar1;
  
  iVar1 = *DAT_300769a8;
  if (iVar1 != param_1) {
    *DAT_300769a8 = param_1;
    logMsg(DAT_300769ac,param_1,0,0,0,0,0);
    DLOAD_LEDInd(param_1);
  }
  return iVar1 != param_1;
}

/* ----------------------------------------------------------------
 * BSP_TFUP_CompleteDeal @ 0x30077140  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 8
 * Вызывает: BSP_DLOAD_Reset, BSP_DLOAD_SetCdromMarker, TFUP_GetGoOn, TFUP_GetSuccessFlag, TFUP_SetSuccessFlag, TFUP_getTFUpdateFlag, TFUP_setTFUpdateFlag, taskDelay
 * Константы: 0x30077140
 * ---------------------------------------------------------------- */
void BSP_TFUP_CompleteDeal(void)

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
 * BSP_ONUP_CompleteDeal @ 0x30077144  (примерный размер ~4 байт)
 * Модуль: bsp | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30077144
 * ---------------------------------------------------------------- */
void BSP_ONUP_CompleteDeal(void)

{
  return;
}

