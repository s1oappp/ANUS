/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : flash — флеш-подсистема: NAND-контроллер, ptable, YAFFS/YAFFS2, NV-память (NVM/nvim)
 * Часть  : 1 (функций: 150, адреса 0x3000F1C4..0x30019E10)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * nand_mutex_in @ 0x3000F1C4  (примерный размер ~92 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 1
 * Вызывает: PWRCTRL_NAND_LowPowerExit
 * Вызывают: nand_deinit, nand_init_platform, nand_read_yaffs, nand_run, nand_write_yaffs
 * Константы: 0x3000F1C4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
bool nand_mutex_in(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 0x14));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    (**(code **)(param_1 + 0xc))(0xffffffff);
  }
  iVar1 = PWRCTRL_NAND_LowPowerExit();
  return iVar1 != 0;
}

/* ----------------------------------------------------------------
 * nand_mutex_out @ 0x3000F220  (примерный размер ~96 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 1
 * Вызывает: PWRCTRL_NAND_LowPowerEnter
 * Вызывают: nand_deinit, nand_init_platform, nand_read_yaffs, nand_run, nand_write_yaffs
 * Константы: 0x3000F220
 * ---------------------------------------------------------------- */
undefined4 nand_mutex_out(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = PWRCTRL_NAND_LowPowerEnter();
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x10) != 0) {
      (**(code **)(param_1 + 0x10))();
    }
    if (*(int *)(param_1 + 8) != 0) {
      (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0x14));
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nand_init_platform @ 0x3000F280  (примерный размер ~232 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 5
 * Вызывает: memset, nand_mutex_in, nand_mutex_out, nandc_mutex_create, printf
 * Вызывают: nand_balong_port_mtd, nand_init
 * Константы: 0x3000F280
 * Данные: DAT_3000f470, DAT_3000f474, DAT_3000f478, DAT_3000f47c, DAT_3000f480, DAT_3000f484, DAT_3000f488, DAT_3000f48c
 * ---------------------------------------------------------------- */
int nand_init_platform(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_3000f470;
  if (DAT_3000f470[6] == DAT_3000f474) {
    iVar2 = 0;
    printf(DAT_3000f478);
  }
  else {
    memset(DAT_3000f470,0,0x1c);
    *puVar1 = DAT_3000f47c;
    puVar1[1] = DAT_3000f480;
    puVar1[2] = DAT_3000f484;
    nandc_mutex_create(puVar1 + 5);
    nand_mutex_in(puVar1);
    if (*(int *)*puVar1 == 0) {
      printf(DAT_3000f488);
      iVar2 = 1;
    }
    else if (param_1 == 0) {
      iVar2 = (**(code **)*puVar1)();
    }
    else {
      iVar2 = 0;
    }
    nand_mutex_out(puVar1);
    if (iVar2 == 0) {
      puVar1[6] = DAT_3000f474;
    }
    else {
      printf(DAT_3000f48c);
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * nand_init @ 0x3000F368  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: nand_init_platform
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x3000F368
 * ---------------------------------------------------------------- */
void nand_init(void)

{
  nand_init_platform(0);
  return;
}

/* ----------------------------------------------------------------
 * nand_balong_port_mtd @ 0x3000F370  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: nand_init_platform
 * Константы: 0x3000F370
 * ---------------------------------------------------------------- */
void nand_balong_port_mtd(void)

{
  nand_init_platform(1);
  return;
}

/* ----------------------------------------------------------------
 * nand_deinit @ 0x3000F378  (примерный размер ~164 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 4
 * Вызывает: nand_mutex_in, nand_mutex_out, nandc_mutex_delete, printf
 * Константы: 0x3000F378
 * Данные: DAT_3000f470, DAT_3000f474, DAT_3000f478, DAT_3000f490
 * ---------------------------------------------------------------- */
int nand_deinit(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_3000f470;
  if (DAT_3000f470[6] == DAT_3000f474) {
    nand_mutex_in(DAT_3000f470);
    if (*(int *)(*piVar1 + 4) == 0) {
      printf(DAT_3000f490);
      iVar2 = 1;
    }
    else {
      iVar2 = (**(code **)(*piVar1 + 4))();
    }
    nand_mutex_out(piVar1);
    if (iVar2 == 0) {
      piVar1[6] = 0;
    }
    nandc_mutex_delete(piVar1[5]);
    piVar1[5] = 0;
  }
  else {
    iVar2 = 0;
    printf(DAT_3000f478);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * nand_run @ 0x3000F41C  (примерный размер ~768 байт)
 * Модуль: flash | Вызывают: 9 | Вызывает: 3
 * Вызывает: nand_mutex_in, nand_mutex_out, printf
 * Вызывают: nand_bad, nand_erase, nand_isbad, nand_read, nand_read_oob, nand_read_raw, nand_write, nand_write_oob, nand_write_raw
 * Константы: 0x3000F41C, 0x3000F46C
 * Данные: DAT_3000f470, DAT_3000f474, DAT_3000f494, DAT_3000f498, DAT_3000ff30
 * ---------------------------------------------------------------- */
undefined4 nand_run(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_3000f470;
  if (*(int *)(DAT_3000f470 + 0x18) == DAT_3000f474) {
    nand_mutex_in(DAT_3000f470);
    if (param_2 < 0xb) {
                    /* WARNING: Could not recover jumptable at 0x3000f46c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(DAT_3000f498 + param_2 * 4))();
      return uVar2;
    }
    printf(DAT_3000ff30,param_2);
    nand_mutex_out(iVar1);
  }
  else {
    printf(DAT_3000f494);
  }
  return 1;
}

/* ----------------------------------------------------------------
 * nand_read @ 0x3000F71C  (примерный размер ~112 байт)
 * Модуль: flash | Вызывают: 6 | Вызывает: 1
 * Вызывает: nand_run
 * Вызывают: BSP_NANDF_Read, FUN_3002cb08, nand_export_data, nand_scan_bad, ptable_read_by_type, secIsSecVer
 * Константы: 0x3000F71C
 * Данные: DAT_3000ff34
 * ---------------------------------------------------------------- */
void nand_read(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar6;
  undefined4 auStack_30 [6];
  undefined4 local_18;
  undefined4 *puVar5;
  
  puVar3 = auStack_30;
  iVar6 = 3;
  puVar4 = DAT_3000ff34;
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
  *puVar3 = *puVar4;
  auStack_30[1] = param_1;
  auStack_30[2] = param_2;
  auStack_30[4] = param_3;
  local_18 = param_4;
  nand_run(auStack_30,0,auStack_30);
  return;
}

/* ----------------------------------------------------------------
 * nand_get_spec @ 0x3000F78C  (примерный размер ~104 байт)
 * Модуль: flash | Вызывают: 16 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: BSP_DLOAD_GetDloadFlashInfo, BSP_NANDF_Erase_Force, BSP_NANDF_Scan, BSP_OM_GetFlashSpec, dload_nand_init, nand_data_to_total_size, nand_erase_all, nand_export_data, nand_export_data_with_oob, nand_quary_bad
 *           ...
 * Константы: 0x3000F78C
 * Данные: DAT_3000ff38, DAT_3000ff3c, DAT_3000ff40, DAT_3000ff44
 * ---------------------------------------------------------------- */
undefined4 nand_get_spec(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (DAT_3000ff38[6] == DAT_3000ff3c) {
    if (*(int *)(*DAT_3000ff38 + 0xc) == 0) {
      printf(DAT_3000ff44);
      uVar1 = 1;
    }
    else {
      uVar1 = (**(code **)(*DAT_3000ff38 + 0xc))(param_1);
    }
  }
  else {
    printf(DAT_3000ff40);
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * nand_read_oob @ 0x3000F7F4  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: nand_run
 * Вызывают: nand_export_data_with_oob, ptable_read_by_type
 * Константы: 0x3000F7F4
 * Данные: DAT_3000ff48
 * ---------------------------------------------------------------- */
void nand_read_oob(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar6;
  undefined4 auStack_30 [6];
  undefined4 local_18;
  undefined4 *puVar5;
  
  puVar3 = auStack_30;
  iVar6 = 3;
  puVar4 = DAT_3000ff48;
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
  *puVar3 = *puVar4;
  local_18 = param_5;
  auStack_30[1] = param_1;
  auStack_30[2] = param_2;
  auStack_30[4] = param_3;
  auStack_30[5] = param_4;
  nand_run(auStack_30,0,auStack_30);
  return;
}

/* ----------------------------------------------------------------
 * nand_yaffs_write_size @ 0x3000F86C  (примерный размер ~128 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: bootload_div, nand_get_spec, printf
 * Вызывают: FUN_3002cb08
 * Константы: 0x3000F86C
 * Данные: DAT_3000ff4c, DAT_3000ff50
 * ---------------------------------------------------------------- */
int nand_yaffs_write_size(undefined4 param_1)

{
  int iVar1;
  int local_24;
  undefined1 auStack_20 [4];
  int local_1c;
  
  local_24 = 0;
  iVar1 = nand_get_spec(auStack_20);
  if (iVar1 == 0) {
    iVar1 = bootload_div(param_1,local_1c,&local_24);
    if (local_24 == 0) {
      iVar1 = (local_1c + 0x10) * iVar1;
    }
    else {
      printf(DAT_3000ff50);
      iVar1 = 1;
    }
  }
  else {
    printf(DAT_3000ff4c);
    iVar1 = 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * nand_read_raw @ 0x3000F8EC  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: nand_run
 * Константы: 0x3000F8EC
 * Данные: DAT_3000ff54
 * ---------------------------------------------------------------- */
void nand_read_raw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar6;
  undefined4 local_30 [6];
  undefined4 local_18;
  undefined4 *puVar5;
  
  puVar3 = local_30;
  iVar6 = 3;
  puVar4 = DAT_3000ff54;
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
  *puVar3 = *puVar4;
  local_18 = param_5;
  local_30[0] = param_1;
  local_30[1] = param_2;
  local_30[2] = param_3;
  local_30[4] = param_4;
  nand_run(local_30,3,local_30);
  return;
}

/* ----------------------------------------------------------------
 * nand_read_yaffs @ 0x3000F964  (примерный размер ~72 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: nand_mutex_in, nand_mutex_out, nandc_nand_yaffs_read
 * Вызывают: ynandif_ReadChunkFromNAND
 * Константы: 0x3000F964
 * Данные: DAT_3000ff38
 * ---------------------------------------------------------------- */
undefined4
nand_read_yaffs(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_3000ff38;
  nand_mutex_in(DAT_3000ff38);
  uVar2 = nandc_nand_yaffs_read(param_1,param_2,param_3,param_4);
  nand_mutex_out(uVar1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * nand_isbad @ 0x3000F9AC  (примерный размер ~96 байт)
 * Модуль: flash | Вызывают: 7 | Вызывает: 1
 * Вызывает: nand_run
 * Вызывают: BSP_NANDF_Erase, BSP_NANDF_Scan, nand_quary_bad, nand_scan_bad, ptable_erase_partition, ptable_quary_partition, yaffs_TagsCompatabilityQueryNANDBlock
 * Константы: 0x3000F9AC
 * Данные: DAT_3000ff58
 * ---------------------------------------------------------------- */
void nand_isbad(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar6;
  undefined4 local_28 [7];
  undefined4 *puVar5;
  
  puVar3 = local_28;
  iVar6 = 3;
  puVar4 = DAT_3000ff58;
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
  *puVar3 = *puVar4;
  local_28[0] = param_1;
  local_28[2] = param_2;
  nand_run(local_28,9,local_28);
  return;
}

/* ----------------------------------------------------------------
 * nand_bad @ 0x3000FA0C  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: nand_run
 * Вызывают: nand_scan_bad, yaffs_TagsCompatabilityMarkNANDBlockBad
 * Константы: 0x3000FA0C
 * Данные: DAT_3000ff5c
 * ---------------------------------------------------------------- */
void nand_bad(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar6;
  undefined4 local_24 [7];
  undefined4 *puVar5;
  
  puVar3 = local_24;
  iVar6 = 3;
  puVar4 = DAT_3000ff5c;
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
  *puVar3 = *puVar4;
  local_24[0] = param_1;
  nand_run(local_24,10,local_24);
  return;
}

/* ----------------------------------------------------------------
 * nand_erase @ 0x3000FA64  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 1
 * Вызывает: nand_run
 * Вызывают: BSP_NANDF_Erase, BSP_NANDF_Erase_Force, nand_scan_bad, ptable_erase_partition, ynandif_EraseBlockInNAND
 * Константы: 0x3000FA64
 * Данные: DAT_3000ff60
 * ---------------------------------------------------------------- */
void nand_erase(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar6;
  undefined4 local_24 [7];
  undefined4 *puVar5;
  
  puVar3 = local_24;
  iVar6 = 3;
  puVar4 = DAT_3000ff60;
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
  *puVar3 = *puVar4;
  local_24[0] = param_1;
  nand_run(local_24,8,local_24);
  return;
}

/* ----------------------------------------------------------------
 * nand_write @ 0x3000FABC  (примерный размер ~112 байт)
 * Модуль: flash | Вызывают: 4 | Вызывает: 1
 * Вызывает: nand_run
 * Вызывают: BSP_NANDF_Write, NVBackupFlashDataWrite, ptable_replace_flash_table, ptable_write_by_type
 * Константы: 0x3000FABC
 * Данные: DAT_3000ff64
 * ---------------------------------------------------------------- */
void nand_write(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar6;
  undefined4 auStack_30 [6];
  undefined4 local_18;
  undefined4 *puVar5;
  
  puVar3 = auStack_30;
  iVar6 = 3;
  puVar4 = DAT_3000ff64;
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
  *puVar3 = *puVar4;
  auStack_30[1] = param_1;
  auStack_30[2] = param_2;
  auStack_30[4] = param_3;
  local_18 = param_4;
  nand_run(auStack_30,4,auStack_30);
  return;
}

/* ----------------------------------------------------------------
 * nand_write_oob @ 0x3000FB2C  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: nand_run
 * Вызывают: ptable_write_by_type
 * Константы: 0x3000FB2C
 * Данные: DAT_3000ff68
 * ---------------------------------------------------------------- */
void nand_write_oob(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar6;
  undefined4 auStack_30 [6];
  undefined4 local_18;
  undefined4 *puVar5;
  
  puVar3 = auStack_30;
  iVar6 = 3;
  puVar4 = DAT_3000ff68;
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
  *puVar3 = *puVar4;
  local_18 = param_5;
  auStack_30[1] = param_1;
  auStack_30[2] = param_2;
  auStack_30[4] = param_3;
  auStack_30[5] = param_4;
  nand_run(auStack_30,4,auStack_30);
  return;
}

/* ----------------------------------------------------------------
 * nand_write_raw @ 0x3000FBA4  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: nand_run
 * Константы: 0x3000FBA4
 * Данные: DAT_3000ff6c
 * ---------------------------------------------------------------- */
void nand_write_raw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar6;
  undefined4 local_30 [6];
  undefined4 local_18;
  undefined4 *puVar5;
  
  puVar3 = local_30;
  iVar6 = 3;
  puVar4 = DAT_3000ff6c;
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
  *puVar3 = *puVar4;
  local_18 = param_5;
  local_30[0] = param_1;
  local_30[1] = param_2;
  local_30[2] = param_3;
  local_30[4] = param_4;
  nand_run(local_30,7,local_30);
  return;
}

/* ----------------------------------------------------------------
 * nand_write_yaffs @ 0x3000FC1C  (примерный размер ~72 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: nand_mutex_in, nand_mutex_out, nandc_nand_yaffs_write
 * Вызывают: ynandif_WriteChunkToNAND
 * Константы: 0x3000FC1C
 * Данные: DAT_3000ff38
 * ---------------------------------------------------------------- */
undefined4
nand_write_yaffs(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_3000ff38;
  nand_mutex_in(DAT_3000ff38);
  uVar2 = nandc_nand_yaffs_write(param_1,param_2,param_3,param_4);
  nand_mutex_out(uVar1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * nand_scan_bad @ 0x3000FC64  (примерный размер ~380 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 10
 * Вызывает: __udiv32, __urem32, free, malloc, nand_bad, nand_erase, nand_get_spec, nand_isbad, nand_read, printf
 * Вызывают: FUN_3002c9a8, ptable_flash_prepare
 * Константы: 0x3000FC64
 * Данные: DAT_3000ff70, DAT_3000ff74, DAT_3000ff78, DAT_3000ff7c, DAT_3000ff80
 * ---------------------------------------------------------------- */
undefined4 nand_scan_bad(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  void *__ptr;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_38;
  size_t local_34 [4];
  
  iVar1 = nand_get_spec(local_34);
  if (iVar1 == 0) {
    iVar1 = __urem32(param_1,local_34[0]);
    iVar1 = param_1 - iVar1;
    iVar5 = ((param_1 + param_2 + local_34[0]) - 1 & ~(local_34[0] - 1)) - iVar1;
    __ptr = malloc(local_34[0]);
    if (__ptr == (void *)0x0) {
      printf(DAT_3000ff74);
LAB_3000fdc4:
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
      uVar2 = 1;
    }
    else {
      for (; iVar5 != 0; iVar5 = iVar5 - local_34[0]) {
        uVar2 = __udiv32(iVar1,local_34[0]);
        iVar3 = nand_isbad(uVar2,&local_38);
        if (iVar3 != 0) {
          printf(DAT_3000ff78);
          goto LAB_3000fdc4;
        }
        if (local_38 == 0) {
          for (iVar3 = 1;
              (iVar4 = nand_read(iVar1,__ptr,local_34[0],0), iVar4 == 0xc && (iVar3 != 0));
              iVar3 = iVar3 + -1) {
          }
          if (iVar3 == 0) {
            printf(DAT_3000ff7c,iVar1);
            nand_bad(uVar2);
          }
          else if (param_3 == 1) {
            nand_erase(uVar2);
          }
        }
        else {
          printf(DAT_3000ff80,iVar1);
        }
        iVar1 = iVar1 + local_34[0];
      }
      free(__ptr);
      uVar2 = 0;
    }
  }
  else {
    printf(DAT_3000ff70);
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nand_yaffs_data_size @ 0x3000FDE0  (примерный размер ~124 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: __udiv32, nand_get_spec, printf
 * Вызывают: ptable_dload_write
 * Константы: 0x3000FDE0
 * Данные: DAT_3000ff84, DAT_3000ff88
 * ---------------------------------------------------------------- */
int nand_yaffs_data_size(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_1c [4];
  int local_18;
  
  iVar1 = nand_get_spec(auStack_1c);
  if (iVar1 == 0) {
    iVar2 = local_18 + 0x10;
    iVar1 = __udiv32(param_1,iVar2);
    if (param_1 == iVar2 * iVar1) {
      iVar1 = __udiv32(param_1,iVar2);
      local_18 = local_18 * iVar1;
    }
    else {
      printf(DAT_3000ff88);
      local_18 = 1;
    }
  }
  else {
    printf(DAT_3000ff84);
    local_18 = 1;
  }
  return local_18;
}

/* ----------------------------------------------------------------
 * nand_data_to_total_size @ 0x3000FE5C  (примерный размер ~124 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 3
 * Вызывает: __udiv32, nand_get_spec, printf
 * Константы: 0x3000FE5C
 * Данные: DAT_3000ff8c, DAT_3000ff90
 * ---------------------------------------------------------------- */
int nand_data_to_total_size(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_1c [4];
  int local_18;
  
  iVar1 = nand_get_spec(auStack_1c);
  if (iVar1 == 0) {
    iVar2 = local_18 + 0x10;
    iVar1 = __udiv32(param_1,local_18);
    if (param_1 == local_18 * iVar1) {
      iVar1 = __udiv32(param_1,local_18);
      iVar2 = iVar2 * iVar1;
    }
    else {
      printf(DAT_3000ff90);
      iVar2 = 1;
    }
  }
  else {
    printf(DAT_3000ff8c);
    iVar2 = 1;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * nand_isinit @ 0x3000FED8  (примерный размер ~28 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000FED8
 * Данные: DAT_3000ff38, DAT_3000ff3c
 * ---------------------------------------------------------------- */
bool nand_isinit(void)

{
  return *(int *)(DAT_3000ff38 + 0x18) == DAT_3000ff3c;
}

/* ----------------------------------------------------------------
 * nand_init_clear @ 0x3000FEF4  (примерный размер ~164 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: memset
 * Константы: 0x3000FEF4
 * Данные: DAT_3000ff38, DAT_3000ff94
 * ---------------------------------------------------------------- */
void nand_init_clear(void)

{
  *DAT_3000ff94 = 0;
  memset(DAT_3000ff38,0,0x1c);
  return;
}

/* ----------------------------------------------------------------
 * nandc_set_trace @ 0x3000FF98  (примерный размер ~24 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000FF98
 * Данные: DAT_3000ffbc
 * ---------------------------------------------------------------- */
void nandc_set_trace(undefined4 param_1)

{
  *DAT_3000ffbc = param_1;
  return;
}

/* ----------------------------------------------------------------
 * nandc_get_trace @ 0x3000FFB0  (примерный размер ~16 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3000FFB0
 * Данные: DAT_3000ffbc
 * ---------------------------------------------------------------- */
undefined4 nandc_get_trace(void)

{
  return *DAT_3000ffbc;
}

/* ----------------------------------------------------------------
 * nandc_ctrl_reset @ 0x3000FFC0  (примерный размер ~796 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300124e4, FUN_300126e4, FUN_30012778
 * Вызывают: nandc_ctrl_entry
 * Константы: 0x3000FFC0
 * Данные: DAT_30010f9c, DAT_30011224
 * ---------------------------------------------------------------- */
undefined4 nandc_ctrl_reset(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_30010f9c;
  iVar3 = *(int *)(param_1 + 0xc);
  FUN_30012778(param_1,0xff,0,0);
  FUN_300124e4(param_1,*(undefined2 *)(param_1 + 0x2e));
  if (*(int *)(iVar3 + 0xbc) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0xbc) + 4) == 0x20) {
      *(undefined4 *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xb8)) = 1;
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xb8)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xb8)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0xbc) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0xbc) & 0xff)) |
           ((1 << (*(uint *)(*(int *)(iVar3 + 0xbc) + 4) & 0xff)) - 1U & 1) <<
           (**(uint **)(iVar3 + 0xbc) & 0xff);
    }
  }
  if (*(int *)(iVar3 + 0xa4) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0xa4) + 4) == 0x20) {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xa0)) =
           (uint)*(ushort *)(param_1 + 0x38);
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xa0)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xa0)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0xa4) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0xa4) & 0xff)) |
           ((uint)*(ushort *)(param_1 + 0x38) &
           (1 << (*(uint *)(*(int *)(iVar3 + 0xa4) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar3 + 0xa4) & 0xff);
    }
  }
  if (*(int *)(iVar3 + 0x50) != 0) {
    *(int *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x4c)) =
         0 << (**(uint **)(iVar3 + 0x50) & 0xff);
  }
  if (*(int *)(iVar3 + 0x5c) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0x5c) + 4) == 0x20) {
      *(undefined4 *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x58)) =
           *(undefined4 *)(param_1 + 0x7c);
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x58)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x58)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0x5c) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0x5c) & 0xff)) |
           (*(uint *)(param_1 + 0x7c) & (1 << (*(uint *)(*(int *)(iVar3 + 0x5c) + 4) & 0xff)) - 1U)
           << (**(uint **)(iVar3 + 0x5c) & 0xff);
    }
  }
  if (*(int *)(iVar3 + 0x68) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0x68) + 4) == 0x20) {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 100)) = (uint)*(byte *)(param_1 + 0x2a);
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 100)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 100)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0x68) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0x68) & 0xff)) |
           ((uint)*(byte *)(param_1 + 0x2a) &
           (1 << (*(uint *)(*(int *)(iVar3 + 0x68) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar3 + 0x68) & 0xff);
    }
  }
  iVar1 = FUN_300126e4(param_1,iVar3 + 0x78,1,uVar2);
  if (iVar1 == 0) {
    iVar3 = FUN_300126e4(param_1,iVar3 + 0x6c,1,DAT_30011224);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nandc_ctrl_read_id @ 0x300102DC  (примерный размер ~1372 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_3001243c, FUN_300124e4, FUN_300126e4, FUN_30012778, nandc_data_transmit_raw
 * Вызывают: nandc_ctrl_entry
 * Константы: 0x300102DC
 * Данные: DAT_30011224
 * ---------------------------------------------------------------- */
undefined4 nandc_ctrl_read_id(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  FUN_3001243c(param_1,*(undefined2 *)(param_1 + 0x30));
  FUN_30012778(param_1,0x90,0,0);
  if (*(int *)(iVar3 + 0x38) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0x38) + 4) == 0x20) {
      *(undefined4 *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x34)) = 0;
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x34)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x34)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0x38) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0x38) & 0xff)) | 0 << (**(uint **)(iVar3 + 0x38) & 0xff);
    }
  }
  if (*(int *)(iVar3 + 0x44) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0x44) + 4) == 0x20) {
      *(undefined4 *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x40)) = 0;
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x40)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x40)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0x44) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0x44) & 0xff)) | 0 << (**(uint **)(iVar3 + 0x44) & 0xff);
    }
  }
  if (*(int *)(iVar3 + 0x98) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0x98) + 4) == 0x20) {
      *(undefined4 *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x94)) = 0;
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x94)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x94)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0x98) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0x98) & 0xff)) | 0 << (**(uint **)(iVar3 + 0x98) & 0xff);
    }
  }
  if (*(int *)(iVar3 + 0xa4) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0xa4) + 4) == 0x20) {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xa0)) =
           (uint)*(ushort *)(param_1 + 0x38);
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xa0)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xa0)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0xa4) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0xa4) & 0xff)) |
           ((uint)*(ushort *)(param_1 + 0x38) &
           (1 << (*(uint *)(*(int *)(iVar3 + 0xa4) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar3 + 0xa4) & 0xff);
    }
  }
  FUN_300124e4(param_1,*(undefined2 *)(param_1 + 0x2e));
  if (*(int *)(iVar3 + 0xbc) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0xbc) + 4) == 0x20) {
      *(undefined4 *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xb8)) = 1;
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xb8)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xb8)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0xbc) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0xbc) & 0xff)) |
           ((1 << (*(uint *)(*(int *)(iVar3 + 0xbc) + 4) & 0xff)) - 1U & 1) <<
           (**(uint **)(iVar3 + 0xbc) & 0xff);
    }
  }
  if (*(int *)(iVar3 + 0x2c) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0x2c) + 4) == 0x20) {
      *(undefined4 *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x28)) =
           *(undefined4 *)(param_1 + 0x84);
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x28)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x28)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0x2c) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0x2c) & 0xff)) |
           (*(uint *)(param_1 + 0x84) & (1 << (*(uint *)(*(int *)(iVar3 + 0x2c) + 4) & 0xff)) - 1U)
           << (**(uint **)(iVar3 + 0x2c) & 0xff);
    }
  }
  if (*(int *)(iVar3 + 0x50) != 0) {
    *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x4c)) =
         ((1 << (*(uint *)(*(int *)(iVar3 + 0x50) + 4) & 0xff)) - 1U & 1) <<
         (**(uint **)(iVar3 + 0x50) & 0xff);
  }
  if (*(int *)(iVar3 + 0x5c) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0x5c) + 4) == 0x20) {
      *(undefined4 *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x58)) =
           *(undefined4 *)(param_1 + 0x7c);
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x58)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0x58)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0x5c) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0x5c) & 0xff)) |
           (*(uint *)(param_1 + 0x7c) & (1 << (*(uint *)(*(int *)(iVar3 + 0x5c) + 4) & 0xff)) - 1U)
           << (**(uint **)(iVar3 + 0x5c) & 0xff);
    }
  }
  if (*(int *)(iVar3 + 0x68) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0x68) + 4) == 0x20) {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 100)) = (uint)*(byte *)(param_1 + 0x20);
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 100)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 100)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0x68) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0x68) & 0xff)) |
           ((uint)*(byte *)(param_1 + 0x20) &
           (1 << (*(uint *)(*(int *)(iVar3 + 0x68) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar3 + 0x68) & 0xff);
    }
  }
  iVar1 = FUN_300126e4(param_1,iVar3 + 0x78,1,DAT_30011224);
  if ((iVar1 == 0) && (iVar3 = FUN_300126e4(param_1,iVar3 + 0x6c,1,DAT_30011224), iVar3 == 0)) {
    nandc_data_transmit_raw(param_1,8,0,0x30);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nandc_ctrl_read_dma @ 0x30010838  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: nandc_ctrl_entry
 * Константы: 0x30010838
 * ---------------------------------------------------------------- */
undefined4 nandc_ctrl_read_dma(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * nandc_ctrl_read_normal @ 0x30010840  (примерный размер ~2424 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_3001258c, FUN_30012834, nandc_data_transmit_page, nandc_data_transmit_raw, printf
 * Вызывают: nandc_ctrl_entry
 * Константы: 0x1FFFFFFF, 0xF0000000, 0x30010840
 * Данные: DAT_3001176c, DAT_30011770, DAT_30011774, DAT_30011778, DAT_30011840, DAT_30011844
 * ---------------------------------------------------------------- */
int nandc_ctrl_read_normal(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *param_1;
  iVar4 = param_1[3];
  if (param_1[0x18] == 2) {
    if (((*DAT_30011778 & 4) != 0) && (0x1fffffff < (int)(*DAT_30011778 & 0xf0000000))) {
      printf(DAT_30011844);
    }
  }
  else {
    FUN_30012834(param_1,param_1 + 0xf,DAT_30011770,DAT_30011774,DAT_3001176c);
    if (param_1[0x18] == 1) {
      if (((*DAT_30011778 & 4) != 0) && (0x1fffffff < (int)(*DAT_30011778 & 0xf0000000))) {
        printf(DAT_30011840);
      }
      param_1[0x18] = 2;
    }
  }
  if (*(int *)(iVar4 + 0x44) != 0) {
    if (*(int *)(*(int *)(iVar4 + 0x44) + 4) == 0x20) {
      *(int *)(param_1[0x24] + *(int *)(iVar4 + 0x40)) = param_1[0x1a];
    }
    else {
      *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0x40)) =
           *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0x40)) &
           ~((1 << (*(uint *)(*(int *)(iVar4 + 0x44) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar4 + 0x44) & 0xff)) |
           (param_1[0x1a] & (1 << (*(uint *)(*(int *)(iVar4 + 0x44) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar4 + 0x44) & 0xff);
    }
  }
  if (*(int *)(iVar4 + 0x38) != 0) {
    if (*(int *)(*(int *)(iVar4 + 0x38) + 4) == 0x20) {
      *(int *)(param_1[0x24] + *(int *)(iVar4 + 0x34)) = param_1[0x1b];
    }
    else {
      *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0x34)) =
           *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0x34)) &
           ~((1 << (*(uint *)(*(int *)(iVar4 + 0x38) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar4 + 0x38) & 0xff)) |
           (param_1[0x1b] & (1 << (*(uint *)(*(int *)(iVar4 + 0x38) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar4 + 0x38) & 0xff);
    }
  }
  if (*(int *)(iVar4 + 0xd4) != 0) {
    if (*(int *)(*(int *)(iVar4 + 0xd4) + 4) == 0x20) {
      *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xd0)) = (uint)*(ushort *)((int)param_1 + 0x2e);
    }
    else {
      *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xd0)) =
           *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xd0)) &
           ~((1 << (*(uint *)(*(int *)(iVar4 + 0xd4) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar4 + 0xd4) & 0xff)) |
           ((uint)*(ushort *)((int)param_1 + 0x2e) &
           (1 << (*(uint *)(*(int *)(iVar4 + 0xd4) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar4 + 0xd4) & 0xff);
    }
  }
  if (*(int *)(iVar5 + 4) == 0x800) {
    if (*(int *)(iVar4 + 0x68) != 0) {
      if (*(int *)(*(int *)(iVar4 + 0x68) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
             (uint)(*(byte *)((int)param_1 + 0x21) | *(byte *)((int)param_1 + 0x23));
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) &
             ~((1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar4 + 0x68) & 0xff)) |
             ((uint)(*(byte *)((int)param_1 + 0x21) | *(byte *)((int)param_1 + 0x23)) &
             (1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar4 + 0x68) & 0xff);
      }
    }
  }
  else if (*DAT_30011770 == *DAT_30011774) {
    if (*(int *)(iVar4 + 0xe0) != 0) {
      if (*(int *)(*(int *)(iVar4 + 0xe0) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) =
             (uint)(*(byte *)(param_1 + 10) | *(byte *)((int)param_1 + 0x29));
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) &
             ~((1 << (*(uint *)(*(int *)(iVar4 + 0xe0) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar4 + 0xe0) & 0xff)) |
             ((uint)(*(byte *)(param_1 + 10) | *(byte *)((int)param_1 + 0x29)) &
             (1 << (*(uint *)(*(int *)(iVar4 + 0xe0) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar4 + 0xe0) & 0xff);
      }
    }
    if (*(int *)(iVar4 + 0x68) != 0) {
      if (*(int *)(*(int *)(iVar4 + 0x68) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
             (uint)(*(byte *)((int)param_1 + 0x21) | *(byte *)((int)param_1 + 0x23));
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) &
             ~((1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar4 + 0x68) & 0xff)) |
             ((uint)(*(byte *)((int)param_1 + 0x21) | *(byte *)((int)param_1 + 0x23)) &
             (1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar4 + 0x68) & 0xff);
      }
    }
  }
  else {
    if (*(int *)(iVar4 + 0xe0) != 0) {
      if (*(int *)(*(int *)(iVar4 + 0xe0) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) = (uint)*(byte *)(param_1 + 10);
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) &
             ~((1 << (*(uint *)(*(int *)(iVar4 + 0xe0) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar4 + 0xe0) & 0xff)) |
             ((uint)*(byte *)(param_1 + 10) &
             (1 << (*(uint *)(*(int *)(iVar4 + 0xe0) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar4 + 0xe0) & 0xff);
      }
    }
    if (*(int *)(iVar4 + 0x68) != 0) {
      if (*(int *)(*(int *)(iVar4 + 0x68) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) = (uint)*(byte *)((int)param_1 + 0x21);
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) &
             ~((1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar4 + 0x68) & 0xff)) |
             ((uint)*(byte *)((int)param_1 + 0x21) &
             (1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar4 + 0x68) & 0xff);
      }
    }
  }
  iVar5 = FUN_3001258c(param_1);
  if (iVar5 == 0) {
    if (((uint)*(ushort *)(param_1 + 0xe) == *DAT_3001176c) ||
       ((uint)*(ushort *)(param_1 + 0xd) == *DAT_3001176c)) {
      nandc_data_transmit_raw(param_1,*DAT_30011774,0,0x30);
    }
    else {
      nandc_data_transmit_page(param_1,*(undefined4 *)(*param_1 + 0x4c),0,0x30);
    }
    iVar2 = 0;
    iVar5 = 0;
    iVar3 = *DAT_30011770 - *DAT_30011774;
    while (iVar3 != 0) {
      if (*(int *)(iVar4 + 0xd4) != 0) {
        if (*(int *)(*(int *)(iVar4 + 0xd4) + 4) == 0x20) {
          *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xd0)) = (uint)*(ushort *)((int)param_1 + 0x2e)
          ;
        }
        else {
          *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xd0)) =
               *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xd0)) &
               ~((1 << (*(uint *)(*(int *)(iVar4 + 0xd4) + 4) & 0xff)) + -1 <<
                (**(uint **)(iVar4 + 0xd4) & 0xff)) |
               ((uint)*(ushort *)((int)param_1 + 0x2e) &
               (1 << (*(uint *)(*(int *)(iVar4 + 0xd4) + 4) & 0xff)) - 1U) <<
               (**(uint **)(iVar4 + 0xd4) & 0xff);
        }
      }
      iVar3 = iVar3 - *DAT_30011774;
      if (iVar3 == 0) {
        if (*(int *)(iVar4 + 0xe0) != 0) {
          if (*(int *)(*(int *)(iVar4 + 0xe0) + 4) == 0x20) {
            *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) = (uint)*(byte *)((int)param_1 + 0x29)
            ;
          }
          else {
            *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) =
                 *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) &
                 ~((1 << (*(uint *)(*(int *)(iVar4 + 0xe0) + 4) & 0xff)) + -1 <<
                  (**(uint **)(iVar4 + 0xe0) & 0xff)) |
                 ((uint)*(byte *)((int)param_1 + 0x29) &
                 (1 << (*(uint *)(*(int *)(iVar4 + 0xe0) + 4) & 0xff)) - 1U) <<
                 (**(uint **)(iVar4 + 0xe0) & 0xff);
          }
        }
        if (*(int *)(iVar4 + 0x68) != 0) {
          if (*(int *)(*(int *)(iVar4 + 0x68) + 4) == 0x20) {
            *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) = (uint)*(byte *)((int)param_1 + 0x23);
          }
          else {
            *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
                 *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) &
                 ~((1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) + -1 <<
                  (**(uint **)(iVar4 + 0x68) & 0xff)) |
                 ((uint)*(byte *)((int)param_1 + 0x23) &
                 (1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) - 1U) <<
                 (**(uint **)(iVar4 + 0x68) & 0xff);
          }
        }
      }
      else if (*(int *)(iVar4 + 0x68) != 0) {
        if (*(int *)(*(int *)(iVar4 + 0x68) + 4) == 0x20) {
          *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) = (uint)*(byte *)((int)param_1 + 0x22);
        }
        else {
          *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
               *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) &
               ~((1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) + -1 <<
                (**(uint **)(iVar4 + 0x68) & 0xff)) |
               ((uint)*(byte *)((int)param_1 + 0x22) &
               (1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) - 1U) <<
               (**(uint **)(iVar4 + 0x68) & 0xff);
        }
      }
      iVar1 = FUN_3001258c(param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      if ((uint)*(ushort *)(param_1 + 0xe) == *DAT_3001176c) {
        iVar2 = iVar2 + *DAT_30011774;
        nandc_data_transmit_raw(param_1,*DAT_30011774,iVar2,0x30);
      }
      else {
        iVar5 = iVar5 + 1;
        nandc_data_transmit_page(param_1,*(undefined4 *)(*param_1 + 0x4c),iVar5,0x30);
      }
    }
    iVar5 = 0;
  }
  return iVar5;
}

/* ----------------------------------------------------------------
 * FUN_300111b8 @ 0x300111B8  (примерный размер ~136 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: nandc_ctrl_entry
 * Константы: 0x300111B8
 * ---------------------------------------------------------------- */
undefined4 FUN_300111b8(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 0xec) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (1 << (*(uint *)(*(int *)(iVar1 + 0xec) + 4) & 0xff)) - 1U &
            *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 0xe8)) >>
            (**(uint **)(iVar1 + 0xec) & 0xff);
  }
  if (*(byte *)(param_1 + 0x2d) == uVar2) {
    **(undefined4 **)(param_1 + 0x94) = 1;
  }
  else {
    **(undefined4 **)(param_1 + 0x94) = 0xc0;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30011240 @ 0x30011240  (примерный размер ~2452 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_30012324, FUN_30012834, nandc_data_transmit_page, nandc_data_transmit_raw, printf
 * Вызывают: nandc_ctrl_entry
 * Константы: 0x1FFFFFFF, 0xF0000000, 0x30011240
 * Данные: DAT_30011778, DAT_30012188, DAT_3001218c, DAT_30012190, DAT_30012194, DAT_30012250
 * ---------------------------------------------------------------- */
int FUN_30011240(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *param_1;
  iVar4 = param_1[3];
  if (param_1[0x18] == 4) {
    if (((*DAT_30011778 & 4) != 0) && (0x1fffffff < (int)(*DAT_30011778 & 0xf0000000))) {
      printf(DAT_30012250);
    }
  }
  else {
    FUN_30012834(param_1,param_1 + 0x12,DAT_3001218c,DAT_30012190,DAT_30012188);
    if (param_1[0x18] == 3) {
      if (((*DAT_30011778 & 4) != 0) && (0x1fffffff < (int)(*DAT_30011778 & 0xf0000000))) {
        printf(DAT_30012194);
      }
      param_1[0x18] = 4;
    }
  }
  if (*(int *)(iVar4 + 0x44) != 0) {
    if (*(int *)(*(int *)(iVar4 + 0x44) + 4) == 0x20) {
      *(int *)(param_1[0x24] + *(int *)(iVar4 + 0x40)) = param_1[0x1a];
    }
    else {
      *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0x40)) =
           *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0x40)) &
           ~((1 << (*(uint *)(*(int *)(iVar4 + 0x44) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar4 + 0x44) & 0xff)) |
           (param_1[0x1a] & (1 << (*(uint *)(*(int *)(iVar4 + 0x44) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar4 + 0x44) & 0xff);
    }
  }
  if (*(int *)(iVar4 + 0x38) != 0) {
    if (*(int *)(*(int *)(iVar4 + 0x38) + 4) == 0x20) {
      *(int *)(param_1[0x24] + *(int *)(iVar4 + 0x34)) = param_1[0x1b];
    }
    else {
      *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0x34)) =
           *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0x34)) &
           ~((1 << (*(uint *)(*(int *)(iVar4 + 0x38) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar4 + 0x38) & 0xff)) |
           (param_1[0x1b] & (1 << (*(uint *)(*(int *)(iVar4 + 0x38) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar4 + 0x38) & 0xff);
    }
  }
  if (*(int *)(iVar4 + 0xd4) != 0) {
    if (*(int *)(*(int *)(iVar4 + 0xd4) + 4) == 0x20) {
      *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xd0)) = (uint)*(ushort *)((int)param_1 + 0x2e);
    }
    else {
      *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xd0)) =
           *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xd0)) &
           ~((1 << (*(uint *)(*(int *)(iVar4 + 0xd4) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar4 + 0xd4) & 0xff)) |
           ((uint)*(ushort *)((int)param_1 + 0x2e) &
           (1 << (*(uint *)(*(int *)(iVar4 + 0xd4) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar4 + 0xd4) & 0xff);
    }
  }
  if (((uint)*(ushort *)(param_1 + 0xe) == *DAT_30012188) ||
     ((uint)*(ushort *)(param_1 + 0xd) == *DAT_30012188)) {
    nandc_data_transmit_raw(param_1,*DAT_30012190,0,0x10);
  }
  else {
    nandc_data_transmit_page(param_1,*(undefined4 *)(*param_1 + 0x4c),0,0x10);
  }
  iVar3 = 0;
  iVar2 = 0;
  if (*(int *)(iVar5 + 4) == 0x800) {
    if (*(int *)(iVar4 + 0x68) != 0) {
      if (*(int *)(*(int *)(iVar4 + 0x68) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
             (uint)(*(byte *)(param_1 + 9) | *(byte *)((int)param_1 + 0x26));
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) &
             ~((1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar4 + 0x68) & 0xff)) |
             ((uint)(*(byte *)(param_1 + 9) | *(byte *)((int)param_1 + 0x26)) &
             (1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar4 + 0x68) & 0xff);
      }
    }
  }
  else if (*DAT_3001218c == *DAT_30012190) {
    if (*(int *)(iVar4 + 0xe0) != 0) {
      if (*(int *)(*(int *)(iVar4 + 0xe0) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) =
             (uint)(*(byte *)(param_1 + 10) | *(byte *)((int)param_1 + 0x29));
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) &
             ~((1 << (*(uint *)(*(int *)(iVar4 + 0xe0) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar4 + 0xe0) & 0xff)) |
             ((uint)(*(byte *)(param_1 + 10) | *(byte *)((int)param_1 + 0x29)) &
             (1 << (*(uint *)(*(int *)(iVar4 + 0xe0) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar4 + 0xe0) & 0xff);
      }
    }
    if (*(int *)(iVar4 + 0x68) != 0) {
      if (*(int *)(*(int *)(iVar4 + 0x68) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
             (uint)(*(byte *)(param_1 + 9) | *(byte *)((int)param_1 + 0x26));
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) &
             ~((1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar4 + 0x68) & 0xff)) |
             ((uint)(*(byte *)(param_1 + 9) | *(byte *)((int)param_1 + 0x26)) &
             (1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar4 + 0x68) & 0xff);
      }
    }
  }
  else {
    if (*(int *)(iVar4 + 0xe0) != 0) {
      if (*(int *)(*(int *)(iVar4 + 0xe0) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) = (uint)*(byte *)(param_1 + 10);
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) &
             ~((1 << (*(uint *)(*(int *)(iVar4 + 0xe0) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar4 + 0xe0) & 0xff)) |
             ((uint)*(byte *)(param_1 + 10) &
             (1 << (*(uint *)(*(int *)(iVar4 + 0xe0) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar4 + 0xe0) & 0xff);
      }
    }
    if (*(int *)(iVar4 + 0x68) != 0) {
      if (*(int *)(*(int *)(iVar4 + 0x68) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) = (uint)*(byte *)(param_1 + 9);
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) &
             ~((1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar4 + 0x68) & 0xff)) |
             ((uint)*(byte *)(param_1 + 9) &
             (1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar4 + 0x68) & 0xff);
      }
    }
  }
  iVar5 = *DAT_3001218c - *DAT_30012190;
  iVar1 = FUN_30012324(param_1,iVar5);
  while( true ) {
    if (iVar1 != 0) {
      return iVar1;
    }
    if (iVar5 == 0) break;
    if ((uint)*(ushort *)(param_1 + 0xe) == *DAT_30012188) {
      iVar3 = iVar3 + *DAT_30012190;
      nandc_data_transmit_raw(param_1,*DAT_30012190,iVar3,0x10);
    }
    else {
      iVar2 = iVar2 + 1;
      nandc_data_transmit_page(param_1,*(undefined4 *)(*param_1 + 0x4c),iVar2,0x10);
    }
    if (*(int *)(iVar4 + 0xd4) != 0) {
      if (*(int *)(*(int *)(iVar4 + 0xd4) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xd0)) = (uint)*(ushort *)((int)param_1 + 0x2e);
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xd0)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xd0)) &
             ~((1 << (*(uint *)(*(int *)(iVar4 + 0xd4) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar4 + 0xd4) & 0xff)) |
             ((uint)*(ushort *)((int)param_1 + 0x2e) &
             (1 << (*(uint *)(*(int *)(iVar4 + 0xd4) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar4 + 0xd4) & 0xff);
      }
    }
    iVar5 = iVar5 - *DAT_30012190;
    if (iVar5 == 0) {
      if (*(int *)(iVar4 + 0xe0) != 0) {
        if (*(int *)(*(int *)(iVar4 + 0xe0) + 4) == 0x20) {
          *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) = (uint)*(byte *)((int)param_1 + 0x29);
        }
        else {
          *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) =
               *(uint *)(param_1[0x24] + *(int *)(iVar4 + 0xdc)) &
               ~((1 << (*(uint *)(*(int *)(iVar4 + 0xe0) + 4) & 0xff)) + -1 <<
                (**(uint **)(iVar4 + 0xe0) & 0xff)) |
               ((uint)*(byte *)((int)param_1 + 0x29) &
               (1 << (*(uint *)(*(int *)(iVar4 + 0xe0) + 4) & 0xff)) - 1U) <<
               (**(uint **)(iVar4 + 0xe0) & 0xff);
        }
      }
      if (*(int *)(iVar4 + 0x68) != 0) {
        if (*(int *)(*(int *)(iVar4 + 0x68) + 4) == 0x20) {
          *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) = (uint)*(byte *)((int)param_1 + 0x26);
        }
        else {
          *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
               *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) &
               ~((1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) + -1 <<
                (**(uint **)(iVar4 + 0x68) & 0xff)) |
               ((uint)*(byte *)((int)param_1 + 0x26) &
               (1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) - 1U) <<
               (**(uint **)(iVar4 + 0x68) & 0xff);
        }
      }
    }
    else if (*(int *)(iVar4 + 0x68) != 0) {
      if (*(int *)(*(int *)(iVar4 + 0x68) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) = (uint)*(byte *)((int)param_1 + 0x25);
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar4 + 100)) &
             ~((1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar4 + 0x68) & 0xff)) |
             ((uint)*(byte *)((int)param_1 + 0x25) &
             (1 << (*(uint *)(*(int *)(iVar4 + 0x68) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar4 + 0x68) & 0xff);
      }
    }
    iVar1 = FUN_30012324(param_1,iVar5);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30011bd4 @ 0x30011BD4  (примерный размер ~1016 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300121ac, FUN_300124e4, FUN_30012778, printf
 * Вызывают: nandc_ctrl_entry
 * Константы: 0x30011BD4, 0x0FFFFFFF, 0xF0000000
 * Данные: DAT_30012b74, DAT_30012b78, DAT_30012ea8
 * ---------------------------------------------------------------- */
int FUN_30011bd4(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 3;
  iVar1 = 1;
  iVar3 = param_1[3];
  iVar4 = *(int *)(*param_1 + 0x44);
  if (((param_1[0x1a] == 0) && ((*DAT_30012b74 & 4) != 0)) &&
     (0xfffffff < (int)(*DAT_30012b74 & 0xf0000000))) {
    printf(DAT_30012b78);
  }
  FUN_30012778(param_1,0x60,0xd0,0x70);
  FUN_300124e4(param_1,*(undefined2 *)((int)param_1 + 0x2e));
  if (*(int *)(iVar3 + 0x44) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0x44) + 4) == 0x20) {
      *(int *)(param_1[0x24] + *(int *)(iVar3 + 0x40)) = param_1[0x1a];
    }
    else {
      *(uint *)(param_1[0x24] + *(int *)(iVar3 + 0x40)) =
           *(uint *)(param_1[0x24] + *(int *)(iVar3 + 0x40)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0x44) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0x44) & 0xff)) |
           (param_1[0x1a] & (1 << (*(uint *)(*(int *)(iVar3 + 0x44) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar3 + 0x44) & 0xff);
    }
  }
  if (*(int *)(iVar3 + 0xa4) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0xa4) + 4) == 0x20) {
      *(uint *)(param_1[0x24] + *(int *)(iVar3 + 0xa0)) = (uint)*(ushort *)(param_1 + 0xe);
    }
    else {
      *(uint *)(param_1[0x24] + *(int *)(iVar3 + 0xa0)) =
           *(uint *)(param_1[0x24] + *(int *)(iVar3 + 0xa0)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0xa4) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0xa4) & 0xff)) |
           ((uint)*(ushort *)(param_1 + 0xe) &
           (1 << (*(uint *)(*(int *)(iVar3 + 0xa4) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar3 + 0xa4) & 0xff);
    }
  }
  if (*(int *)(iVar3 + 0x98) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0x98) + 4) == 0x20) {
      *(undefined4 *)(param_1[0x24] + *(int *)(iVar3 + 0x94)) = 0;
    }
    else {
      *(uint *)(param_1[0x24] + *(int *)(iVar3 + 0x94)) =
           *(uint *)(param_1[0x24] + *(int *)(iVar3 + 0x94)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0x98) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0x98) & 0xff)) | 0 << (**(uint **)(iVar3 + 0x98) & 0xff);
    }
  }
  if (*(int *)(iVar3 + 0x50) != 0) {
    *(uint *)(param_1[0x24] + *(int *)(iVar3 + 0x4c)) =
         (iVar4 - 2U & (1 << (*(uint *)(*(int *)(iVar3 + 0x50) + 4) & 0xff)) - 1U) <<
         (**(uint **)(iVar3 + 0x50) & 0xff);
  }
  if (*(int *)(iVar3 + 0x5c) != 0) {
    if (*(int *)(*(int *)(iVar3 + 0x5c) + 4) == 0x20) {
      *(int *)(param_1[0x24] + *(int *)(iVar3 + 0x58)) = param_1[0x1f];
    }
    else {
      *(uint *)(param_1[0x24] + *(int *)(iVar3 + 0x58)) =
           *(uint *)(param_1[0x24] + *(int *)(iVar3 + 0x58)) &
           ~((1 << (*(uint *)(*(int *)(iVar3 + 0x5c) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar3 + 0x5c) & 0xff)) |
           (param_1[0x1f] & (1 << (*(uint *)(*(int *)(iVar3 + 0x5c) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar3 + 0x5c) & 0xff);
    }
  }
  for (; (iVar1 != 0 && (iVar2 != 0)); iVar2 = iVar2 + -1) {
    if (*(int *)(iVar3 + 0x68) != 0) {
      if (*(int *)(*(int *)(iVar3 + 0x68) + 4) == 0x20) {
        *(uint *)(param_1[0x24] + *(int *)(iVar3 + 100)) = (uint)*(byte *)((int)param_1 + 0x27);
      }
      else {
        *(uint *)(param_1[0x24] + *(int *)(iVar3 + 100)) =
             *(uint *)(param_1[0x24] + *(int *)(iVar3 + 100)) &
             ~((1 << (*(uint *)(*(int *)(iVar3 + 0x68) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar3 + 0x68) & 0xff)) |
             ((uint)*(byte *)((int)param_1 + 0x27) &
             (1 << (*(uint *)(*(int *)(iVar3 + 0x68) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar3 + 0x68) & 0xff);
      }
    }
    iVar1 = FUN_300121ac(param_1);
  }
  if ((iVar1 != 0) && (((*DAT_30012b74 & 4) != 0 && (-1 < (int)*DAT_30012b74)))) {
    printf(DAT_30012ea8);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * nandc_ctrl_entry @ 0x30011FCC  (примерный размер ~472 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 9
 * Вызывает: FUN_300111b8, FUN_30011240, FUN_30011bd4, FUN_300121a4, nandc_ctrl_read_dma, nandc_ctrl_read_id, nandc_ctrl_read_normal, nandc_ctrl_reset, printf
 * Вызывают: FUN_300161c8, nandc_native_read_id, nandc_native_reset_chip
 * Константы: 0x30011FCC, 0x1FFFFFFF, 0xF0000000
 * Данные: DAT_30012b74, DAT_30012eac, DAT_30012eb0, DAT_30013074
 * ---------------------------------------------------------------- */
int nandc_ctrl_entry(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int local_18;
  
  iVar3 = 1;
  iVar2 = 3;
  if (((*DAT_30012b74 & 4) != 0) && (0x1fffffff < (int)(*DAT_30012b74 & 0xf0000000))) {
    printf(DAT_30012eac,*(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x7c),
           *(undefined4 *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0x68),
           *(undefined4 *)(param_1 + 0x6c));
  }
  do {
    if (*DAT_30012eb0 == 1) {
      nandc_ctrl_reset(param_1);
      *DAT_30012eb0 = 0;
    }
    iVar1 = *(int *)(param_1 + 0x58);
    if (iVar1 == 0x70) {
      iVar3 = FUN_300111b8(param_1);
    }
    else if (iVar1 < 0x71) {
      if (iVar1 != 0) {
        if (iVar1 == 0x10) {
          if ((*(uint *)(param_1 + 0x5c) & 1) == 0) {
            iVar3 = FUN_30011240(param_1);
          }
          else {
            iVar3 = FUN_300121a4(param_1);
          }
        }
        else if (iVar1 == 0x30) {
          if ((*(uint *)(param_1 + 0x5c) & 1) == 0) {
            iVar3 = nandc_ctrl_read_normal(param_1);
          }
          else {
            iVar3 = nandc_ctrl_read_dma(param_1);
          }
        }
        else if (iVar1 != 0x60) {
LAB_30012140:
          iVar3 = 1;
        }
      }
    }
    else if (iVar1 != 0x80) {
      if (iVar1 == 0x90) {
        iVar3 = nandc_ctrl_read_id(param_1);
      }
      else if (iVar1 == 0xd0) {
        iVar3 = FUN_30011bd4(param_1);
      }
      else {
        if (iVar1 != 0xff) goto LAB_30012140;
        iVar3 = nandc_ctrl_reset(param_1);
      }
    }
    if (((*(int *)(param_1 + 0x58) != 0x30) || (iVar3 == 0)) || (iVar2 == 0)) {
      return iVar3;
    }
    iVar2 = iVar2 + -1;
    local_18 = DAT_30013074;
    do {
      bVar4 = local_18 != 0;
      local_18 = local_18 + -1;
    } while (bVar4);
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_300121a4 @ 0x300121A4  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: nandc_ctrl_entry
 * Константы: 0x300121A4
 * ---------------------------------------------------------------- */
undefined4 FUN_300121a4(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300121ac @ 0x300121AC  (примерный размер ~376 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300126e4, printf
 * Вызывают: FUN_30011bd4
 * Константы: 0x300121AC
 * Данные: DAT_30012b74, DAT_30013078, DAT_30013134, DAT_30013138, DAT_30013280
 * ---------------------------------------------------------------- */
int FUN_300121ac(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = FUN_300126e4(param_1,iVar2 + 0x6c,1,DAT_30013078);
  if (iVar1 == 0) {
    if (*(int *)(iVar2 + 0x80) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (1 << (*(uint *)(*(int *)(iVar2 + 0x80) + 4) & 0xff)) - 1U &
              *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar2 + 0x7c)) >>
              (**(uint **)(iVar2 + 0x80) & 0xff);
    }
    if (uVar3 == 1) {
      if (*(int *)(iVar2 + 0xf8) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (1 << (*(uint *)(*(int *)(iVar2 + 0xf8) + 4) & 0xff)) - 1U &
                *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar2 + 0xf4)) >>
                (**(uint **)(iVar2 + 0xf8) & 0xff);
      }
      if ((uVar3 & 1) == 0) {
        iVar1 = 0;
      }
      else {
        if (((*DAT_30012b74 & 4) != 0) && (-1 < (int)*DAT_30012b74)) {
          printf(DAT_30013280,uVar3);
        }
        iVar1 = 10;
      }
    }
    else {
      iVar1 = 10;
      if (((*DAT_30012b74 & 4) != 0) && (-1 < (int)*DAT_30012b74)) {
        printf(DAT_30013138);
      }
    }
  }
  else if (((*DAT_30012b74 & 4) != 0) && (-1 < (int)*DAT_30012b74)) {
    printf(DAT_30013134);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30012324 @ 0x30012324  (примерный размер ~280 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300126e4, printf
 * Вызывают: FUN_30011240
 * Константы: 0x30012324
 * Данные: DAT_30012b74, DAT_30013284, DAT_30013288, DAT_3001333c
 * ---------------------------------------------------------------- */
int FUN_30012324(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = DAT_30013284;
  iVar3 = *(int *)(param_1 + 0xc);
  iVar1 = FUN_300126e4(param_1,iVar3 + 0x6c,1,DAT_30013284);
  if (iVar1 == 0) {
    if (param_2 == 0) {
      while( true ) {
        if (*(int *)(iVar3 + 0xf8) == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = (1 << (*(uint *)(*(int *)(iVar3 + 0xf8) + 4) & 0xff)) - 1U &
                  *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar3 + 0xf4)) >>
                  (**(uint **)(iVar3 + 0xf8) & 0xff);
        }
        if (((uVar4 & 1) == 0) || (iVar2 == 0)) break;
        iVar2 = iVar2 + -1;
      }
      if (iVar2 == 0) {
        if (((*DAT_30012b74 & 4) != 0) && (-1 < (int)*DAT_30012b74)) {
          printf(DAT_3001333c);
        }
        return 6;
      }
    }
    iVar1 = 0;
  }
  else if (((*DAT_30012b74 & 4) != 0) && (-1 < (int)*DAT_30012b74)) {
    printf(DAT_30013288);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3001243c @ 0x3001243C  (примерный размер ~168 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: nandc_ctrl_read_id
 * Константы: 0x3001243C
 * ---------------------------------------------------------------- */
undefined4 FUN_3001243c(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 0xb0) != 0) {
    if (*(int *)(*(int *)(iVar1 + 0xb0) + 4) == 0x20) {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 0xac)) = param_2;
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 0xac)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 0xac)) &
           ~((1 << (*(uint *)(*(int *)(iVar1 + 0xb0) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar1 + 0xb0) & 0xff)) |
           (param_2 & (1 << (*(uint *)(*(int *)(iVar1 + 0xb0) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar1 + 0xb0) & 0xff);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300124e4 @ 0x300124E4  (примерный размер ~168 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_30011bd4, nandc_ctrl_read_id, nandc_ctrl_reset
 * Константы: 0x300124E4
 * ---------------------------------------------------------------- */
undefined4 FUN_300124e4(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 0xd4) != 0) {
    if (*(int *)(*(int *)(iVar1 + 0xd4) + 4) == 0x20) {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 0xd0)) = param_2;
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 0xd0)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 0xd0)) &
           ~((1 << (*(uint *)(*(int *)(iVar1 + 0xd4) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar1 + 0xd4) & 0xff)) |
           (param_2 & (1 << (*(uint *)(*(int *)(iVar1 + 0xd4) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar1 + 0xd4) & 0xff);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3001258c @ 0x3001258C  (примерный размер ~344 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300126e4, printf
 * Вызывают: nandc_ctrl_read_normal
 * Константы: 0x3001258C
 * Данные: DAT_30012b74, DAT_30013074, DAT_300134fc, DAT_3001356c, DAT_30013570
 * ---------------------------------------------------------------- */
int FUN_3001258c(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  int local_1c;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = FUN_300126e4(param_1,iVar2 + 0x6c,1,DAT_30013074);
  if (iVar1 == 0) {
    local_1c = 500;
    do {
      bVar4 = local_1c != 0;
      local_1c = local_1c + -1;
    } while (bVar4);
    if (*(int *)(iVar2 + 0xec) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (1 << (*(uint *)(*(int *)(iVar2 + 0xec) + 4) & 0xff)) - 1U &
              *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar2 + 0xe8)) >>
              (**(uint **)(iVar2 + 0xec) & 0xff);
    }
    if (*(byte *)(param_1 + 0x2d) != uVar3) {
      return 0;
    }
    if (((*DAT_30012b74 & 4) != 0) && (-1 < (int)*DAT_30012b74)) {
      printf(DAT_3001356c);
    }
    iVar1 = 0xd;
  }
  else if (((*DAT_30012b74 & 4) != 0) && (-1 < (int)*DAT_30012b74)) {
    printf(DAT_300134fc);
  }
  if (((*DAT_30012b74 & 4) != 0) && (-1 < (int)*DAT_30012b74)) {
    printf(DAT_30013570,*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c));
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300126e4 @ 0x300126E4  (примерный размер ~148 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: FUN_300121ac, FUN_30012324, FUN_3001258c, nandc_ctrl_read_id, nandc_ctrl_reset
 * Константы: 0x300126E4
 * Данные: DAT_30012b74, DAT_30013574
 * ---------------------------------------------------------------- */
undefined4 FUN_300126e4(int param_1,int param_2,uint param_3,int param_4)

{
  do {
    if (((1 << (*(uint *)(*(int *)(param_2 + 8) + 4) & 0xff)) - 1U &
        *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(param_2 + 4)) >>
        (**(uint **)(param_2 + 8) & 0xff)) == param_3) {
      return 0;
    }
    param_4 = param_4 + -1;
  } while (param_4 != 0);
  if (((*DAT_30012b74 & 4) != 0) && (-1 < (int)*DAT_30012b74)) {
    printf(DAT_30013574);
  }
  return 6;
}

/* ----------------------------------------------------------------
 * FUN_30012778 @ 0x30012778  (примерный размер ~188 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_30011bd4, nandc_ctrl_read_id, nandc_ctrl_reset
 * Константы: 0x30012778
 * ---------------------------------------------------------------- */
void FUN_30012778(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 8) != 0) {
    if (*(int *)(*(int *)(iVar1 + 8) + 4) == 0x20) {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 4)) =
           param_2 | param_3 << 8 | param_4 << 0x10;
    }
    else {
      *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 4)) =
           *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 4)) &
           ~((1 << (*(uint *)(*(int *)(iVar1 + 8) + 4) & 0xff)) + -1 <<
            (**(uint **)(iVar1 + 8) & 0xff)) |
           ((param_2 | param_3 << 8 | param_4 << 0x10) &
           (1 << (*(uint *)(*(int *)(iVar1 + 8) + 4) & 0xff)) - 1U) <<
           (**(uint **)(iVar1 + 8) & 0xff);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30012834 @ 0x30012834  (примерный размер ~460 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 2
 * Вызывает: FUN_30012a00, FUN_30012a2c
 * Вызывают: FUN_30011240, nandc_ctrl_read_normal
 * Константы: 0x30012834
 * ---------------------------------------------------------------- */
void FUN_30012834(int param_1,int *param_2,uint *param_3,uint *param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  uint local_28;
  uint local_24;
  
  iVar1 = *(int *)(param_1 + 0xc);
  local_28 = 0;
  local_24 = 0;
  if (*(int *)(param_1 + 0x5c) == 0) {
    if (*param_2 == 0) {
      FUN_30012a2c(param_1,param_2,&local_24,&local_28,param_5);
    }
    else {
      puVar2 = (undefined4 *)*param_2;
      FUN_30012a00(param_1,*puVar2);
      local_24 = puVar2[1];
      local_28 = puVar2[2];
      *param_5 = puVar2[3];
    }
  }
  else if ((*(uint *)(param_1 + 0x5c) & 4) != 0) {
    if (param_2[1] == 0) {
      FUN_30012a2c(param_1,param_2 + 1,&local_24,&local_28,param_5);
    }
    else {
      puVar2 = (undefined4 *)param_2[1];
      FUN_30012a00(param_1,*puVar2);
      local_24 = *(uint *)(param_1 + 0x78);
      local_28 = puVar2[2];
      *param_5 = puVar2[3];
    }
    if (local_24 <= local_28) {
      local_28 = local_24;
    }
    if (*(int *)(iVar1 + 0x8c) != 0) {
      if (*(int *)(*(int *)(iVar1 + 0x8c) + 4) == 0x20) {
        *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 0x88)) = local_28;
      }
      else {
        *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 0x88)) =
             *(uint *)(*(int *)(param_1 + 0x90) + *(int *)(iVar1 + 0x88)) &
             ~((1 << (*(uint *)(*(int *)(iVar1 + 0x8c) + 4) & 0xff)) + -1 <<
              (**(uint **)(iVar1 + 0x8c) & 0xff)) |
             (local_28 & (1 << (*(uint *)(*(int *)(iVar1 + 0x8c) + 4) & 0xff)) - 1U) <<
             (**(uint **)(iVar1 + 0x8c) & 0xff);
      }
    }
  }
  *param_3 = local_24;
  *param_4 = local_28;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30012a00 @ 0x30012A00  (примерный размер ~44 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30012834
 * Константы: 0x30012A00
 * ---------------------------------------------------------------- */
void FUN_30012a00(undefined4 param_1,undefined4 *param_2)

{
  for (; param_2 != (undefined4 *)0x0; param_2 = (undefined4 *)param_2[2]) {
    *(undefined4 *)*param_2 = param_2[1];
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30012a2c @ 0x30012A2C  (примерный размер ~2204 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300132c8, FUN_3001338c, malloc, memset
 * Вызывают: FUN_30012834
 * Константы: 0x30012A2C
 * Данные: DAT_30013578
 * ---------------------------------------------------------------- */
undefined4 FUN_30012a2c(int *param_1,int *param_2,undefined4 *param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  uint local_2c;
  
  iVar3 = *param_1;
  iVar1 = FUN_3001338c(param_1,param_3,&local_2c,param_5,param_4);
  if (iVar1 == 0) {
    iVar1 = param_1[3];
    pvVar2 = malloc(0x10);
    *param_2 = (int)pvVar2;
    if (*param_2 != 0) {
      memset((void *)*param_2,0,0x10);
      if (param_1[0x16] == 0x30) {
        if (*(int *)(iVar1 + 8) != 0) {
          if (*(int *)(iVar1 + 8) != 0) {
            if (*(int *)(*(int *)(iVar1 + 8) + 4) == 0x20) {
              *(undefined4 *)(param_1[0x24] + *(int *)(iVar1 + 4)) = 0x3000;
            }
            else {
              *(uint *)(param_1[0x24] + *(int *)(iVar1 + 4)) =
                   *(uint *)(param_1[0x24] + *(int *)(iVar1 + 4)) &
                   ~((1 << (*(uint *)(*(int *)(iVar1 + 8) + 4) & 0xff)) + -1 <<
                    (**(uint **)(iVar1 + 8) & 0xff)) |
                   ((1 << (*(uint *)(*(int *)(iVar1 + 8) + 4) & 0xff)) - 1U & 0x3000) <<
                   (**(uint **)(iVar1 + 8) & 0xff);
            }
          }
          FUN_300132c8(param_1,param_1[0x24] + *(int *)(iVar1 + 4),*param_2);
        }
      }
      else if (*(int *)(iVar1 + 8) != 0) {
        if (*(int *)(iVar1 + 8) != 0) {
          if (*(int *)(*(int *)(iVar1 + 8) + 4) == 0x20) {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 4)) = DAT_30013578;
          }
          else {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 4)) =
                 *(uint *)(param_1[0x24] + *(int *)(iVar1 + 4)) &
                 ~((1 << (*(uint *)(*(int *)(iVar1 + 8) + 4) & 0xff)) + -1 <<
                  (**(uint **)(iVar1 + 8) & 0xff)) |
                 ((1 << (*(uint *)(*(int *)(iVar1 + 8) + 4) & 0xff)) - 1U & DAT_30013578) <<
                 (**(uint **)(iVar1 + 8) & 0xff);
          }
        }
        FUN_300132c8(param_1,param_1[0x24] + *(int *)(iVar1 + 4),*param_2);
      }
      if (*(int *)(iVar1 + 0x2c) != 0) {
        if (*(int *)(iVar1 + 0x2c) != 0) {
          if (*(int *)(*(int *)(iVar1 + 0x2c) + 4) == 0x20) {
            *(undefined4 *)(param_1[0x24] + *(int *)(iVar1 + 0x28)) = *(undefined4 *)(iVar3 + 0x58);
          }
          else {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x28)) =
                 *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x28)) &
                 ~((1 << (*(uint *)(*(int *)(iVar1 + 0x2c) + 4) & 0xff)) + -1 <<
                  (**(uint **)(iVar1 + 0x2c) & 0xff)) |
                 (*(uint *)(iVar3 + 0x58) &
                 (1 << (*(uint *)(*(int *)(iVar1 + 0x2c) + 4) & 0xff)) - 1U) <<
                 (**(uint **)(iVar1 + 0x2c) & 0xff);
          }
        }
        FUN_300132c8(param_1,param_1[0x24] + *(int *)(iVar1 + 0x28),*param_2);
      }
      if (*(int *)(iVar1 + 200) != 0) {
        if (*(int *)(iVar1 + 200) != 0) {
          if (*(int *)(*(int *)(iVar1 + 200) + 4) == 0x20) {
            *(undefined4 *)(param_1[0x24] + *(int *)(iVar1 + 0xc4)) = *(undefined4 *)(iVar3 + 0x54);
          }
          else {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0xc4)) =
                 *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0xc4)) &
                 ~((1 << (*(uint *)(*(int *)(iVar1 + 200) + 4) & 0xff)) + -1 <<
                  (**(uint **)(iVar1 + 200) & 0xff)) |
                 (*(uint *)(iVar3 + 0x54) &
                 (1 << (*(uint *)(*(int *)(iVar1 + 200) + 4) & 0xff)) - 1U) <<
                 (**(uint **)(iVar1 + 200) & 0xff);
          }
        }
        FUN_300132c8(param_1,param_1[0x24] + *(int *)(iVar1 + 0xc4),*param_2);
      }
      if (*(int *)(iVar1 + 0x98) != 0) {
        if (*(int *)(iVar1 + 0x98) != 0) {
          if (*(int *)(*(int *)(iVar1 + 0x98) + 4) == 0x20) {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x94)) = local_2c;
          }
          else {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x94)) =
                 *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x94)) &
                 ~((1 << (*(uint *)(*(int *)(iVar1 + 0x98) + 4) & 0xff)) + -1 <<
                  (**(uint **)(iVar1 + 0x98) & 0xff)) |
                 (local_2c & (1 << (*(uint *)(*(int *)(iVar1 + 0x98) + 4) & 0xff)) - 1U) <<
                 (**(uint **)(iVar1 + 0x98) & 0xff);
          }
        }
        FUN_300132c8(param_1,param_1[0x24] + *(int *)(iVar1 + 0x94),*param_2);
      }
      if (*(int *)(iVar1 + 0xa4) != 0) {
        if (*(int *)(iVar1 + 0xa4) != 0) {
          if (*(int *)(*(int *)(iVar1 + 0xa4) + 4) == 0x20) {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0xa0)) = *param_5;
          }
          else {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0xa0)) =
                 *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0xa0)) &
                 ~((1 << (*(uint *)(*(int *)(iVar1 + 0xa4) + 4) & 0xff)) + -1 <<
                  (**(uint **)(iVar1 + 0xa4) & 0xff)) |
                 (*param_5 & (1 << (*(uint *)(*(int *)(iVar1 + 0xa4) + 4) & 0xff)) - 1U) <<
                 (**(uint **)(iVar1 + 0xa4) & 0xff);
          }
        }
        FUN_300132c8(param_1,param_1[0x24] + *(int *)(iVar1 + 0xa0),*param_2);
      }
      if (*(int *)(iVar1 + 0x50) != 0) {
        *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x4c)) =
             (*(uint *)(iVar3 + 0x44) & (1 << (*(uint *)(*(int *)(iVar1 + 0x50) + 4) & 0xff)) - 1U)
             << (**(uint **)(iVar1 + 0x50) & 0xff);
      }
      if (*(int *)(iVar1 + 0x50) != 0) {
        if (*(int *)(iVar1 + 0x50) != 0) {
          if (*(int *)(*(int *)(iVar1 + 0x50) + 4) == 0x20) {
            *(undefined4 *)(param_1[0x24] + *(int *)(iVar1 + 0x4c)) = *(undefined4 *)(iVar3 + 0x44);
          }
          else {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x4c)) =
                 *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x4c)) &
                 ~((1 << (*(uint *)(*(int *)(iVar1 + 0x50) + 4) & 0xff)) + -1 <<
                  (**(uint **)(iVar1 + 0x50) & 0xff)) |
                 (*(uint *)(iVar3 + 0x44) &
                 (1 << (*(uint *)(*(int *)(iVar1 + 0x50) + 4) & 0xff)) - 1U) <<
                 (**(uint **)(iVar1 + 0x50) & 0xff);
          }
        }
        FUN_300132c8(param_1,param_1[0x24] + *(int *)(iVar1 + 0x4c),*param_2);
      }
      if (*(int *)(iVar1 + 0x5c) != 0) {
        if (*(int *)(iVar1 + 0x5c) != 0) {
          if (*(int *)(*(int *)(iVar1 + 0x5c) + 4) == 0x20) {
            *(int *)(param_1[0x24] + *(int *)(iVar1 + 0x58)) = param_1[0x1f];
          }
          else {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x58)) =
                 *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x58)) &
                 ~((1 << (*(uint *)(*(int *)(iVar1 + 0x5c) + 4) & 0xff)) + -1 <<
                  (**(uint **)(iVar1 + 0x5c) & 0xff)) |
                 (param_1[0x1f] & (1 << (*(uint *)(*(int *)(iVar1 + 0x5c) + 4) & 0xff)) - 1U) <<
                 (**(uint **)(iVar1 + 0x5c) & 0xff);
          }
        }
        FUN_300132c8(param_1,param_1[0x24] + *(int *)(iVar1 + 0x58),*param_2);
      }
      if (*(int *)(iVar1 + 0xb0) != 0) {
        if (*(int *)(iVar1 + 0xb0) != 0) {
          if (*(int *)(*(int *)(iVar1 + 0xb0) + 4) == 0x20) {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0xac)) = (uint)*(ushort *)(param_1 + 0xc);
          }
          else {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0xac)) =
                 *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0xac)) &
                 ~((1 << (*(uint *)(*(int *)(iVar1 + 0xb0) + 4) & 0xff)) + -1 <<
                  (**(uint **)(iVar1 + 0xb0) & 0xff)) |
                 ((uint)*(ushort *)(param_1 + 0xc) &
                 (1 << (*(uint *)(*(int *)(iVar1 + 0xb0) + 4) & 0xff)) - 1U) <<
                 (**(uint **)(iVar1 + 0xb0) & 0xff);
          }
        }
        FUN_300132c8(param_1,param_1[0x24] + *(int *)(iVar1 + 0xac),*param_2);
      }
      if (*(int *)(iVar1 + 0x8c) != 0) {
        if (*(int *)(iVar1 + 0x8c) != 0) {
          if (*(int *)(*(int *)(iVar1 + 0x8c) + 4) == 0x20) {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x88)) = *param_4;
          }
          else {
            *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x88)) =
                 *(uint *)(param_1[0x24] + *(int *)(iVar1 + 0x88)) &
                 ~((1 << (*(uint *)(*(int *)(iVar1 + 0x8c) + 4) & 0xff)) + -1 <<
                  (**(uint **)(iVar1 + 0x8c) & 0xff)) |
                 (*param_4 & (1 << (*(uint *)(*(int *)(iVar1 + 0x8c) + 4) & 0xff)) - 1U) <<
                 (**(uint **)(iVar1 + 0x8c) & 0xff);
          }
        }
        FUN_300132c8(param_1,param_1[0x24] + *(int *)(iVar1 + 0x88),*param_2);
      }
      *(undefined4 *)(*param_2 + 4) = *param_3;
      *(uint *)(*param_2 + 8) = *param_4;
      *(uint *)(*param_2 + 0xc) = *param_5;
      return 0;
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300132c8 @ 0x300132C8  (примерный размер ~196 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: malloc
 * Вызывают: FUN_30012a2c
 * Константы: 0x300132C8
 * ---------------------------------------------------------------- */
void FUN_300132c8(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  if (*param_3 == 0) {
    pvVar2 = malloc(0xc);
    *param_3 = (int)pvVar2;
    if (*param_3 != 0) {
      *(undefined4 **)*param_3 = param_2;
      *(undefined4 *)(*param_3 + 4) = *param_2;
      *(undefined4 *)(*param_3 + 8) = 0;
    }
  }
  else {
    puVar1 = (undefined4 *)*param_3;
    do {
      puVar3 = puVar1;
      if ((undefined4 *)*puVar3 == param_2) {
        puVar3[1] = *param_2;
        return;
      }
      puVar1 = (undefined4 *)puVar3[2];
    } while ((undefined4 *)puVar3[2] != (undefined4 *)0x0);
    pvVar2 = malloc(0xc);
    puVar3[2] = pvVar2;
    if (puVar3[2] != 0) {
      *(undefined4 **)puVar3[2] = param_2;
      *(undefined4 *)(puVar3[2] + 4) = *param_2;
      *(undefined4 *)(puVar3[2] + 8) = 0;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001338c @ 0x3001338C  (примерный размер ~392 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30013514, printf
 * Вызывают: FUN_30012a2c
 * Константы: 0x3001338C
 * Данные: DAT_3001357c, DAT_30013580, DAT_30013584
 * ---------------------------------------------------------------- */
undefined4 FUN_3001338c(int *param_1,uint *param_2,undefined4 *param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = *param_1;
  uVar4 = *(uint *)(*(int *)(param_1[2] + 0x14) + 0x104);
  uVar2 = param_1[0x1a] & DAT_3001357c;
  if (*(int *)(iVar3 + 0x58) == 1) {
    uVar2 = uVar2 << 1;
  }
  uVar1 = FUN_30013514(*(undefined4 *)(iVar3 + 4));
  if ((param_1[0x17] & 4U) == 0) {
    *param_3 = *(undefined4 *)(iVar3 + 0x50);
    if (uVar2 == 0) {
      if ((param_1[0x17] & 7U) == 0) {
        uVar4 = uVar4 + *(int *)(iVar3 + 4);
        uVar2 = uVar4 >> (uVar1 & 0xff);
        *param_4 = (uint)*(ushort *)((int)param_1 + 0x36);
      }
      else {
        *param_4 = (uint)*(ushort *)(param_1 + 0xd);
        uVar2 = uVar4;
      }
      goto LAB_300134e4;
    }
  }
  else {
    uVar4 = param_1[0x1e];
    if ((uVar4 < 0x201) ||
       ((uVar2 == 0 && (uVar4 <= (uint)(*(int *)(iVar3 + 4) + *(int *)(iVar3 + 0x1c)))))) {
      iVar5 = *(int *)(iVar3 + 4);
      iVar3 = *(int *)(iVar3 + 0x1c);
      *param_3 = 0;
      *param_4 = (uint)*(ushort *)(param_1 + 0xe);
      uVar2 = (uint)(iVar5 + iVar3) >> (uVar1 & 0xff);
LAB_300134e4:
      *param_2 = uVar4;
      *param_5 = uVar2;
      return 0;
    }
    if (((*DAT_30013580 & 4) != 0) && (-1 < (int)*DAT_30013580)) {
      printf(DAT_30013584,uVar4,uVar2);
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_30013514 @ 0x30013514  (примерный размер ~116 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3001338c
 * Константы: 0x30013514
 * ---------------------------------------------------------------- */
undefined4 FUN_30013514(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x800) {
    uVar1 = 0;
  }
  else if (param_1 == 0x1000) {
    uVar1 = 1;
  }
  else if (param_1 == 0x2000) {
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * nandc_data_transmit_page @ 0x30013588  (примерный размер ~388 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 2
 * Вызывает: memcpy, memset
 * Вызывают: FUN_30011240, nandc_ctrl_read_normal
 * Константы: 0x30013588
 * ---------------------------------------------------------------- */
undefined4 nandc_data_transmit_page(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x88) != *(int *)(param_1 + 0x94)) {
    sVar2 = *(size_t *)(param_2 + param_3 * 0x10 + 4);
    if ((sVar2 != 0) && (*(int *)(param_1 + 0x88) != 0)) {
      iVar4 = *(int *)(param_2 + param_3 * 0x10);
      iVar3 = 0;
      for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
        iVar3 = iVar3 + *(int *)(param_2 + uVar1 * 0x10 + 4);
      }
      if (param_4 == 0x30) {
        memcpy((void *)(iVar3 + *(int *)(param_1 + 0x88)),(void *)(iVar4 + *(int *)(param_1 + 0x94))
               ,sVar2);
      }
      else {
        memcpy((void *)(iVar4 + *(int *)(param_1 + 0x94)),(void *)(iVar3 + *(int *)(param_1 + 0x88))
               ,sVar2);
      }
    }
    sVar2 = *(size_t *)(param_2 + param_3 * 0x10 + 0xc);
    iVar3 = *(int *)(param_2 + param_3 * 0x10 + 8);
    if ((sVar2 == 0) || (*(int *)(param_1 + 0x8c) == 0)) {
      if ((sVar2 != 0) && (param_4 != 0x30)) {
        memset((void *)(iVar3 + *(int *)(param_1 + 0x94)),0xff,sVar2);
      }
    }
    else {
      iVar4 = 0;
      for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
        iVar4 = iVar4 + *(int *)(param_2 + uVar1 * 0x10 + 0xc);
      }
      if (param_4 == 0x30) {
        memcpy((void *)(iVar4 + *(int *)(param_1 + 0x8c)),(void *)(iVar3 + *(int *)(param_1 + 0x94))
               ,sVar2);
      }
      else {
        memcpy((void *)(iVar3 + *(int *)(param_1 + 0x94)),(void *)(iVar4 + *(int *)(param_1 + 0x8c))
               ,sVar2);
      }
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * nandc_data_transmit_raw @ 0x3001370C  (примерный размер ~104 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 1
 * Вызывает: memcpy
 * Вызывают: FUN_30011240, nandc_ctrl_read_id, nandc_ctrl_read_normal
 * Константы: 0x3001370C
 * ---------------------------------------------------------------- */
undefined4 nandc_data_transmit_raw(int param_1,size_t param_2,int param_3,int param_4)

{
  if (*(int *)(param_1 + 0x88) != *(int *)(param_1 + 0x94)) {
    if (param_4 == 0x30) {
      memcpy((void *)(*(int *)(param_1 + 0x88) + param_3),*(void **)(param_1 + 0x94),param_2);
    }
    else {
      memcpy(*(void **)(param_1 + 0x94),(void *)(*(int *)(param_1 + 0x88) + param_3),param_2);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * nandc_host_get_ecc_ability @ 0x30013774  (примерный размер ~152 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: nandc_host_set_partition
 * Константы: 0x30013774
 * Данные: DAT_30014118, DAT_3001411c
 * ---------------------------------------------------------------- */
undefined4 nandc_host_get_ecc_ability(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x18);
  while( true ) {
    if (piVar1[3] == 0) {
      if (((*DAT_30014118 & 0x10) != 0) && (-1 < (int)*DAT_30014118)) {
        printf(DAT_3001411c,*(uint *)(param_2 + 0x1c),*(int *)(param_2 + 4));
      }
      return 1;
    }
    if ((*piVar1 == *(int *)(param_2 + 4)) && ((uint)piVar1[1] <= *(uint *)(param_2 + 0x1c))) break;
    piVar1 = piVar1 + 4;
  }
  *param_3 = (int)piVar1;
  return 0;
}

/* ----------------------------------------------------------------
 * nandc_host_init_regset @ 0x3001380C  (примерный размер ~168 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: nandc_host_init_cluster
 * Константы: 0x3001380C
 * Данные: DAT_30014118, DAT_30014120
 * ---------------------------------------------------------------- */
undefined4 nandc_host_init_regset(int *param_1,int *param_2)

{
  int *piVar1;
  
  do {
    if (param_1[2] == 0) {
      if (((*DAT_30014118 & 0x10) != 0) && (-1 < (int)*DAT_30014118)) {
        printf(DAT_30014120,*param_2);
      }
      return 1;
    }
    for (piVar1 = (int *)param_1[2]; *piVar1 != 0xff; piVar1 = piVar1 + 6) {
      if (*piVar1 == *param_2) {
        param_2[1] = *param_1;
        param_2[2] = (int)(piVar1 + 1);
        return 0;
      }
    }
    param_1 = param_1 + 3;
  } while( true );
}

/* ----------------------------------------------------------------
 * nandc_host_init_cluster @ 0x300138B4  (примерный размер ~108 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30014058, nandc_host_init_regset
 * Вызывают: nandc_native_host_create
 * Константы: 0x300138B4
 * Данные: DAT_30014124
 * ---------------------------------------------------------------- */
undefined4 nandc_host_init_cluster(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = DAT_30014124;
  while( true ) {
    if (*piVar2 == 0xff) {
      *(int **)(param_1 + 0xc) = DAT_30014124;
      return 0;
    }
    iVar1 = FUN_30014058(param_3,*piVar2);
    if ((iVar1 != 0) && (iVar1 = nandc_host_init_regset(param_2,piVar2), iVar1 != 0)) break;
    piVar2 = piVar2 + 3;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * nandc_host_set_partition @ 0x30013920  (примерный размер ~580 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_3001401c, free, malloc, memset, nandc_host_get_ecc_ability
 * Вызывают: nandc_host_set_define
 * Константы: 0x30013920
 * Данные: DAT_30014128, DAT_3001412c
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 nandc_host_set_partition(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int *__ptr;
  int local_34 [3];
  
  __ptr = (int *)0x0;
  local_34[0] = *DAT_30014128;
  local_34[1] = 0;
  piVar4 = (int *)param_1[1];
  FUN_3001401c(local_34 + 2,*param_1,local_34);
  if (piVar4 == (int *)0x0) {
LAB_30013b2c:
    if (__ptr != (int *)0x0) {
      if (*__ptr != 0) {
        free((void *)*__ptr);
      }
      free(__ptr);
    }
    uVar2 = 1;
  }
  else {
    if (param_2 == 0) {
      __ptr = (int *)malloc(local_34[2] * 0x18);
      if (__ptr == (int *)0x0) goto LAB_30013b2c;
      memset(__ptr,0,local_34[2] * 0x18);
      *piVar4 = (int)__ptr;
      piVar4[2] = local_34[2];
      for (uVar3 = 0; uVar3 < (uint)local_34[2]; uVar3 = uVar3 + 1) {
        iVar1 = nandc_host_get_ecc_ability(param_1,local_34[uVar3],local_34 + 1);
        if (iVar1 == 0) {
          *(undefined4 *)(local_34[uVar3] + 0x50) = *(undefined4 *)(local_34[1] + 8);
          if (uVar3 == 0) {
            __ptr[2] = *(int *)(local_34[0] + 0x38);
            *__ptr = DAT_3001412c;
            __ptr[5] = *(int *)(local_34[1] + 0xc);
          }
          else {
            __ptr[3] = __ptr[-3] + __ptr[-4];
            __ptr[2] = *(int *)(local_34[uVar3] + 0x38);
            *__ptr = 0;
            __ptr[5] = *(int *)(local_34[1] + 0xc);
          }
          __ptr = __ptr + 6;
        }
      }
    }
    else {
      for (uVar3 = 0; iVar1 = param_3, uVar3 < (uint)local_34[2]; uVar3 = uVar3 + 1) {
        iVar1 = nandc_host_get_ecc_ability(param_1,local_34[uVar3],local_34 + 1);
        if (iVar1 == 0) {
          *(undefined4 *)(local_34[uVar3] + 0x50) = *(undefined4 *)(local_34[1] + 8);
        }
      }
      for (; 0 < iVar1; iVar1 = iVar1 + -1) {
        if (local_34[1] != 0) {
          *(undefined4 *)(param_2 + iVar1 * 0x18 + -4) = *(undefined4 *)(local_34[1] + 0xc);
        }
      }
      *piVar4 = param_2;
      piVar4[2] = param_3;
    }
    param_1[2] = *piVar4;
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nandc_host_get_pagemap @ 0x30013B64  (примерный размер ~256 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: nandc_host_set_chipparam
 * Константы: 0x30013B64
 * Данные: DAT_30014118, DAT_30014130
 * ---------------------------------------------------------------- */
int nandc_host_get_pagemap(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  
  do {
    if (*param_1 == 0) {
      if (*param_1 == 0) {
LAB_30013c28:
        if (((*DAT_30014118 & 0x10) != 0) && (-1 < (int)*DAT_30014118)) {
          printf(DAT_30014130,param_2,param_3);
        }
      }
      return 0;
    }
    if (param_1[1] == param_2) {
      if (param_3 == 0x800) {
        iVar1 = *param_1;
        *param_4 = *(undefined4 *)*param_1;
        return iVar1 + 4;
      }
      if (param_3 == 0x1000) {
        iVar1 = *param_1;
        *param_4 = *(undefined4 *)(*param_1 + 0x14);
        return iVar1 + 0x18;
      }
      if (param_3 == 0x2000) {
        iVar1 = *param_1;
        *param_4 = *(undefined4 *)(*param_1 + 0x38);
        return iVar1 + 0x3c;
      }
      goto LAB_30013c28;
    }
    param_1 = param_1 + 2;
  } while( true );
}

/* ----------------------------------------------------------------
 * nandc_host_get_pageset @ 0x30013C64  (примерный размер ~112 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: nandc_host_set_chipparam
 * Константы: 0x30013C64
 * ---------------------------------------------------------------- */
undefined4 nandc_host_get_pageset(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x200) {
    uVar1 = 0;
  }
  else if (param_1 == 0x800) {
    uVar1 = 1;
  }
  else if (param_1 == 0x1000) {
    uVar1 = 2;
  }
  else if (param_1 == 0x2000) {
    uVar1 = 3;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * nandc_host_set_chipparam @ 0x30013CD4  (примерный размер ~148 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: nandc_host_get_pagemap, nandc_host_get_pageset, printf
 * Вызывают: nandc_nand_init
 * Константы: 0x30013CD4, 0x1FFFFFFF, 0xF0000000
 * Данные: DAT_30014118, DAT_30014134
 * ---------------------------------------------------------------- */
undefined4 nandc_host_set_chipparam(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *param_1;
  uVar3 = *(undefined4 *)(iVar4 + 0x50);
  uVar2 = *(undefined4 *)(iVar4 + 4);
  uVar1 = nandc_host_get_pagemap(param_1[7],uVar3,uVar2,param_1 + 0x15);
  *(undefined4 *)(iVar4 + 0x4c) = uVar1;
  uVar1 = nandc_host_get_pageset(*(undefined4 *)(iVar4 + 4));
  *(undefined4 *)(iVar4 + 0x54) = uVar1;
  *(uint *)(iVar4 + 0x58) = (uint)(*(int *)(iVar4 + 0x40) == 2);
  if (((*DAT_30014118 & 0x10) != 0) && (0x1fffffff < (int)(*DAT_30014118 & 0xf0000000))) {
    printf(DAT_30014134,*(undefined4 *)(iVar4 + 0x5c),uVar3,uVar2);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * nandc_host_set_define @ 0x30013D68  (примерный размер ~108 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: malloc, memset, nandc_host_set_partition
 * Вызывают: nandc_init_mtd_partition
 * Константы: 0x30013D68
 * ---------------------------------------------------------------- */
undefined4 nandc_host_set_define(int param_1,undefined4 param_2,undefined4 param_3)

{
  void *__s;
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    __s = malloc(0xc);
    if (__s == (void *)0x0) {
      return 2;
    }
    memset(__s,0,0xc);
    *(undefined4 *)((int)__s + 4) = 0;
    *(void **)(param_1 + 4) = __s;
  }
  uVar1 = nandc_host_set_partition(param_1,param_2,param_3);
  return uVar1;
}

/* ----------------------------------------------------------------
 * nandc_host_add_nand_chip @ 0x30013DD4  (примерный размер ~584 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_3001409c, free, malloc, printf
 * Вызывают: nandc_native_nand_prob
 * Константы: 0x30013DD4, 0x00100000, 0x08000000
 * Данные: DAT_30014118, DAT_30014138
 * ---------------------------------------------------------------- */
undefined4 nandc_host_add_nand_chip(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *__ptr;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar3 = 1;
  iVar2 = param_3[1];
  uVar1 = param_3[8];
  uVar6 = param_3[0x10];
  uVar4 = param_3[0xe];
  uVar5 = param_3[7];
  __ptr = (undefined4 *)malloc(0x60);
  if (__ptr != (undefined4 *)0x0) {
    *__ptr = *param_3;
    if ((((iVar2 == 0x200) || (iVar2 == 0x800)) || (iVar2 == 0x1000)) || (iVar2 == 0x2000)) {
      __ptr[1] = iVar2;
    }
    else {
      __ptr[1] = 0;
    }
    if (((uVar1 == 0x8000) || (uVar1 == 0x20000)) || ((uVar1 == 0x40000 || (uVar1 == 0x100000)))) {
      __ptr[8] = uVar1;
    }
    else {
      __ptr[8] = 0;
    }
    __ptr[0x10] = uVar6;
    __ptr[0xe] = uVar4;
    __ptr[7] = uVar5;
    if (((__ptr[1] != 0) && (__ptr[7] != 0)) && ((__ptr[8] != 0 && (__ptr[0xe] != 0)))) {
      __ptr[3] = iVar2 + -1;
      __ptr[4] = ~__ptr[3];
      __ptr[0xb] = uVar1 - 1;
      __ptr[0xc] = ~__ptr[0xb];
      iVar2 = FUN_3001409c(__ptr[1]);
      __ptr[5] = iVar2 + -1;
      iVar2 = FUN_3001409c(__ptr[8]);
      __ptr[0xd] = iVar2 + -1;
      __ptr[9] = uVar1 >> (__ptr[5] & 0xff);
      __ptr[10] = (uVar4 >> (__ptr[0xd] & 0xff)) - 1;
      __ptr[2] = __ptr[9] * __ptr[10];
      __ptr[6] = (uVar4 >> (__ptr[5] & 0xff)) - 1;
      if (uVar4 != 0) {
        iVar2 = FUN_3001409c(uVar4);
        __ptr[0xf] = iVar2 + -1;
      }
      __ptr[0x11] = (0x8000000 < uVar4) + 4;
      __ptr[0x12] = 0;
      __ptr[0x17] = param_2;
      *param_1 = __ptr;
      return 0;
    }
    if (((*DAT_30014118 & 0x10) != 0) && (-1 < (int)*DAT_30014118)) {
      printf(DAT_30014138,iVar2,uVar5,uVar1,uVar6,uVar4,0);
    }
    uVar3 = 3;
  }
  if (__ptr != (undefined4 *)0x0) {
    free(__ptr);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_3001401c @ 0x3001401C  (примерный размер ~60 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: nandc_host_set_partition
 * Константы: 0x3001401C
 * ---------------------------------------------------------------- */
undefined4 FUN_3001401c(undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_2 + 0x5c); iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_3 = param_2;
    param_3 = param_3 + 1;
  }
  *param_1 = *(undefined4 *)(param_2 + 0x5c);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30014058 @ 0x30014058  (примерный размер ~68 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: nandc_host_init_cluster
 * Константы: 0x30014058
 * ---------------------------------------------------------------- */
undefined4 FUN_30014058(byte *param_1,uint param_2)

{
  while( true ) {
    if (*param_1 == 0xff) {
      return 0;
    }
    if (*param_1 == param_2) break;
    param_1 = param_1 + 1;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3001409c @ 0x3001409C  (примерный размер ~164 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: nandc_host_add_nand_chip
 * Константы: 0x3001409C
 * Данные: DAT_3001413c
 * ---------------------------------------------------------------- */
int FUN_3001409c(uint param_1)

{
  int iVar1;
  
  iVar1 = 1;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    if ((param_1 & DAT_3001413c) == 0) {
      param_1 = (int)param_1 >> 0x10;
      iVar1 = 0x11;
    }
    if ((param_1 & 0xff) == 0) {
      param_1 = (int)param_1 >> 8;
      iVar1 = iVar1 + 8;
    }
    if ((param_1 & 0xf) == 0) {
      param_1 = (int)param_1 >> 4;
      iVar1 = iVar1 + 4;
    }
    if ((param_1 & 3) == 0) {
      param_1 = (int)param_1 >> 2;
      iVar1 = iVar1 + 2;
    }
    if ((param_1 & 1) == 0) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * nandc_host_get_partition @ 0x30014140  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30014140
 * ---------------------------------------------------------------- */
undefined4 nandc_host_get_partition(void)

{
  return 1;
}

/* ----------------------------------------------------------------
 * nandc_nand_yaffs_read @ 0x30014148  (примерный размер ~116 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300161c8
 * Вызывают: nand_read_yaffs
 * Константы: 0x30014148
 * Данные: DAT_300150f8
 * ---------------------------------------------------------------- */
void nandc_nand_yaffs_read(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*DAT_300150f8;
  iVar1 = *piVar2;
  piVar2[0x1c] = (param_1 & *(uint *)(iVar1 + 0x18)) << (*(uint *)(iVar1 + 0x14) & 0xff);
  piVar2[0x1f] = param_1 >> (*(int *)(iVar1 + 0x3c) - *(int *)(iVar1 + 0x14) & 0xffU);
  FUN_300161c8(piVar2,param_2,param_3,0,param_4,0x30);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300141bc @ 0x300141BC  (примерный размер ~400 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300161c8, memcpy, printf
 * Константы: 0x300141BC
 * Данные: DAT_300150f8, DAT_30015230, DAT_30015234, DAT_30015238
 * ---------------------------------------------------------------- */
undefined4 FUN_300141bc(uint param_1,int param_2,void *param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*DAT_300150f8;
  iVar2 = *piVar3;
  piVar3[0x1c] = (param_1 & *(uint *)(iVar2 + 0x18)) << (*(uint *)(iVar2 + 0x14) & 0xff);
  piVar3[0x1f] = param_1 >> (*(int *)(iVar2 + 0x3c) - *(int *)(iVar2 + 0x14) & 0xffU);
  if ((param_2 == 0) || (param_4 < 0x201)) {
    piVar3[0x1c] = param_2 + piVar3[0x1c];
    uVar1 = FUN_300161c8(piVar3,param_3,0,param_4,0,0x30);
    return uVar1;
  }
  if ((uint)(*(int *)(iVar2 + 4) + *(int *)(iVar2 + 0x1c)) < param_2 + param_4) {
    if (((*DAT_30015230 & 0x200) != 0) && (-1 < (int)*DAT_30015230)) {
      printf(DAT_30015238,param_2,param_3,param_4);
    }
LAB_30014338:
    uVar1 = 0;
  }
  else {
    if (piVar3[4] == 0) {
      if (((*DAT_30015230 & 0x200) != 0) && (-1 < (int)*DAT_30015230)) {
        printf(DAT_30015234);
      }
    }
    else {
      iVar2 = FUN_300161c8(piVar3,piVar3[4] + 0x368,0,*(int *)(iVar2 + 4) + *(int *)(iVar2 + 0x1c),0
                           ,0x30);
      if (iVar2 == 0) {
        memcpy(param_3,(void *)(piVar3[4] + param_2 + 0x368),param_4);
        goto LAB_30014338;
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3001434c @ 0x3001434C  (примерный размер ~136 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300161c8, nandc_native_location_by_address
 * Константы: 0x3001434C
 * Данные: DAT_300150f8
 * ---------------------------------------------------------------- */
undefined4 FUN_3001434c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = (int *)*DAT_300150f8;
  if (piVar3 == (int *)0x0) {
    uVar2 = 9;
  }
  else {
    iVar1 = nandc_native_location_by_address(piVar3,param_1);
    if (iVar1 == 0) {
      piVar3[0x1c] = piVar3[0x1c] & *(uint *)(*piVar3 + 0x10);
      uVar2 = FUN_300161c8(piVar3,param_2,param_3,0,param_4,0x30);
    }
    else {
      uVar2 = 4;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300143d4 @ 0x300143D4  (примерный размер ~116 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30016108, FUN_300161c8
 * Вызывают: FUN_30014448
 * Константы: 0x300143D4
 * Данные: DAT_300150f8
 * ---------------------------------------------------------------- */
undefined4 FUN_300143d4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *DAT_300150f8;
  if ((iVar3 == 0) || (iVar1 = FUN_30016108(iVar3,param_1,param_2), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_300161c8(iVar3,param_3,0,param_4,0,0x30);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30014448 @ 0x30014448  (примерный размер ~424 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 2
 * Вызывает: FUN_300143d4, printf
 * Вызывают: FUN_3001465c, FUN_30014c54, FUN_30015718
 * Константы: 0x1FFFFFFF, 0xF0000000, 0x30014448
 * Данные: DAT_30015230, DAT_300153fc, DAT_30015400, DAT_30015404, DAT_30015408, DAT_300154f4
 * ---------------------------------------------------------------- */
int FUN_30014448(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  byte local_94 [128];
  
  iVar1 = FUN_300143d4(param_1,0,local_94 + 0x40,0x40);
  if (iVar1 == 0) {
    if (((*DAT_30015230 & 0x200) != 0) && (0x1fffffff < (int)(*DAT_30015230 & 0xf0000000))) {
      printf(DAT_300153fc);
    }
    for (uVar2 = 0; uVar2 < 0x40; uVar2 = uVar2 + 1) {
      if (((*DAT_30015230 & 0x200) != 0) && (0x1fffffff < (int)(*DAT_30015230 & 0xf0000000))) {
        printf(DAT_30015400,uVar2,(uint)local_94[uVar2 + 0x40]);
      }
    }
    if (*DAT_30015404 == 4) {
      iVar1 = FUN_300143d4(param_1,0x3f,local_94,0x40);
    }
    else {
      iVar1 = FUN_300143d4(param_1,1,local_94,0x40);
    }
    if (iVar1 == 0) {
      if (((*DAT_30015230 & 0x200) != 0) && (0x1fffffff < (int)(*DAT_30015230 & 0xf0000000))) {
        printf(DAT_30015408);
      }
      for (uVar2 = 0; uVar2 < 0x40; uVar2 = uVar2 + 1) {
        if (((*DAT_30015230 & 0x200) != 0) && (0x1fffffff < (int)(*DAT_30015230 & 0xf0000000))) {
          printf(DAT_300154f4,uVar2,(uint)local_94[uVar2]);
        }
      }
      if ((local_94[0x40] == -1) && (local_94[0] == 0xff)) {
        *param_2 = 0;
      }
      else {
        *param_2 = 1;
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * nandc_nand_create_host @ 0x30014FA4  (примерный размер ~80 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: nandc_native_host_create
 * Вызывают: nandc_nand_init
 * Константы: 0x30014FA4
 * Данные: DAT_300150f8, DAT_30015ecc
 * ---------------------------------------------------------------- */
bool nandc_nand_create_host(int *param_1)

{
  int iVar1;
  
  iVar1 = nandc_native_host_create(*DAT_30015ecc);
  *DAT_300150f8 = iVar1;
  iVar1 = *DAT_300150f8;
  if (iVar1 != 0) {
    *param_1 = *DAT_300150f8;
  }
  else {
    *param_1 = 0;
  }
  return iVar1 == 0;
}

/* ----------------------------------------------------------------
 * nandc_init_mtd_partition @ 0x30014FF4  (примерный размер ~104 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 2
 * Вызывает: nandc_host_set_define, ptable_parse_mtd_partitions
 * Вызывают: nandc_nand_init, ptable_replace_ram_table
 * Константы: 0x30014FF4
 * ---------------------------------------------------------------- */
undefined4 nandc_init_mtd_partition(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 local_10;
  
  local_14 = 0;
  iVar1 = ptable_parse_mtd_partitions(&local_14,&local_10);
  if (iVar1 == 0) {
    uVar2 = nandc_host_set_define(param_1,local_14,local_10);
  }
  else {
    uVar2 = nandc_host_set_define(param_1,0,0);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nandc_nand_init @ 0x3001505C  (примерный размер ~240 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 4
 * Вызывает: nandc_host_set_chipparam, nandc_init_mtd_partition, nandc_nand_create_host, nandc_native_nand_prob
 * Константы: 0x3001505C
 * ---------------------------------------------------------------- */
undefined4 nandc_nand_init(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  local_c = 0;
  iVar1 = nandc_nand_create_host(&local_c);
  if (iVar1 == 0) {
    if (**(int **)(local_c + 0x14) != 0) {
      (*(code *)**(undefined4 **)(local_c + 0x14))(local_c + 0x20,local_c);
    }
    *(undefined4 *)(local_c + 0x84) = 0;
    iVar1 = nandc_native_nand_prob(local_c);
    if (iVar1 != 0) {
      *(undefined4 *)(local_c + 0x84) = 1;
      iVar1 = nandc_native_nand_prob(local_c);
      if (iVar1 != 0) {
        return 1;
      }
    }
    iVar1 = nandc_init_mtd_partition(local_c);
    if (iVar1 == 0) {
      uVar2 = nandc_host_set_chipparam(local_c);
      return uVar2;
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * nandc_nand_yaffs_write @ 0x3001514C  (примерный размер ~336 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300161c8, memcmp
 * Вызывают: nand_write_yaffs
 * Константы: 0x3001514C
 * Данные: DAT_30016028
 * ---------------------------------------------------------------- */
undefined4 nandc_nand_yaffs_write(uint param_1,void *param_2,void *param_3,size_t param_4)

{
  int iVar1;
  void *__s1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*DAT_30016028;
  iVar2 = *piVar3;
  piVar3[0x1c] = (param_1 & *(uint *)(iVar2 + 0x18)) << (*(uint *)(iVar2 + 0x14) & 0xff);
  piVar3[0x1f] = param_1 >> (*(int *)(iVar2 + 0x3c) - *(int *)(iVar2 + 0x14) & 0xffU);
  iVar1 = FUN_300161c8(piVar3,param_2,param_3,0,param_4,0x10);
  if (((iVar1 == 0) && (piVar3[4] != 0)) &&
     (__s1 = (void *)(piVar3[4] + 0x368), __s1 != (void *)0x0)) {
    piVar3[0x1c] = (param_1 & *(uint *)(iVar2 + 0x18)) << (*(uint *)(iVar2 + 0x14) & 0xff);
    piVar3[0x1f] = param_1 >> (*(int *)(iVar2 + 0x3c) - *(int *)(iVar2 + 0x14) & 0xffU);
    iVar1 = FUN_300161c8(piVar3,__s1,(int)__s1 + *(int *)(iVar2 + 4),0,param_4,0x30);
    if (((iVar1 == 0) && (iVar1 = memcmp(__s1,param_2,*(size_t *)(iVar2 + 4)), iVar1 == 0)) &&
       (iVar1 = memcmp((void *)((int)__s1 + *(int *)(iVar2 + 4)),param_3,param_4), iVar1 == 0)) {
      return 0;
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3001529c @ 0x3001529C  (примерный размер ~380 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300161c8, memcpy, memset, printf
 * Константы: 0x3001529C
 * Данные: DAT_30016028, DAT_30016260, DAT_30016264, DAT_30016268
 * ---------------------------------------------------------------- */
undefined4 FUN_3001529c(uint param_1,int param_2,void *param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*DAT_30016028;
  iVar2 = *piVar3;
  piVar3[0x1c] = (param_1 & *(uint *)(iVar2 + 0x18)) << (*(uint *)(iVar2 + 0x14) & 0xff);
  piVar3[0x1f] = param_1 >> (*(int *)(iVar2 + 0x3c) - *(int *)(iVar2 + 0x14) & 0xffU);
  if ((param_2 == 0) || (param_4 < 0x201)) {
    piVar3[0x1c] = param_2 + piVar3[0x1c];
    uVar1 = FUN_300161c8(piVar3,param_3,0,param_4,0,0x10);
  }
  else {
    if (param_2 + param_4 < (uint)(*(int *)(iVar2 + 4) + *(int *)(iVar2 + 0x1c))) {
      if (piVar3[4] == 0) {
        if (((*DAT_30016260 & 0x200) != 0) && (-1 < (int)*DAT_30016260)) {
          printf(DAT_30016264);
        }
      }
      else {
        memset((void *)(piVar3[4] + 0x368),0xff,DAT_30016268);
        memcpy((void *)(piVar3[4] + param_2 + 0x368),param_3,param_4);
        iVar2 = FUN_300161c8(piVar3,piVar3[4] + 0x368,0,*(int *)(iVar2 + 4) + *(int *)(iVar2 + 0x1c)
                             ,0,0x10);
        if (iVar2 == 0) {
          return 0;
        }
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30015418 @ 0x30015418  (примерный размер ~116 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300161c8, nandc_native_location_by_address
 * Константы: 0x30015418
 * Данные: DAT_30016028
 * ---------------------------------------------------------------- */
undefined4 FUN_30015418(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *DAT_30016028;
  if (iVar3 == 0) {
    uVar2 = 3;
  }
  else {
    iVar1 = nandc_native_location_by_address(iVar3,param_1);
    if (iVar1 == 0) {
      uVar2 = FUN_300161c8(iVar3,param_2,param_3,0,param_4,0x10);
    }
    else {
      uVar2 = 4;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3001548c @ 0x3001548C  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30016108, FUN_300161c8
 * Вызывают: FUN_30015504
 * Константы: 0x3001548C
 * Данные: DAT_30016028
 * ---------------------------------------------------------------- */
undefined4 FUN_3001548c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *DAT_30016028;
  if ((iVar3 == 0) || (iVar1 = FUN_30016108(iVar3,param_1,param_2), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_300161c8(iVar3,param_3,0,param_4,0,0x10);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30015504 @ 0x30015504  (примерный размер ~300 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_3001548c, memset, printf
 * Вызывают: FUN_30015718
 * Константы: 0x30015504, 0x0FFFFFFF, 0xF0000000
 * Данные: DAT_30016260, DAT_30016450, DAT_30016454, DAT_30016458, DAT_30016500
 * ---------------------------------------------------------------- */
int FUN_30015504(int param_1)

{
  int iVar1;
  undefined1 auStack_4c [64];
  
  if (param_1 == 0) {
    if (((*DAT_30016260 & 0x200) != 0) && (-1 < (int)*DAT_30016260)) {
      printf(DAT_30016450);
    }
    iVar1 = 0;
  }
  else {
    if (((*DAT_30016260 & 0x200) != 0) && (0xfffffff < (int)(*DAT_30016260 & 0xf0000000))) {
      printf(DAT_30016454,param_1);
    }
    memset(auStack_4c,0,0x40);
    FUN_3001548c(param_1,0,auStack_4c,0x40);
    if (*DAT_30016458 == 4) {
      iVar1 = FUN_3001548c(param_1,0x3f,auStack_4c,0x40);
    }
    else {
      iVar1 = FUN_3001548c(param_1,1,auStack_4c,0x40);
    }
    if (((iVar1 != 0) && ((*DAT_30016260 & 0x200) != 0)) && (-1 < (int)*DAT_30016260)) {
      printf(DAT_30016500,param_1);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30015630 @ 0x30015630  (примерный размер ~232 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300161c8, nandc_native_location_by_blocknum, printf
 * Вызывают: FUN_30015718
 * Константы: 0x30015630, 0x0FFFFFFF, 0xF0000000
 * Данные: DAT_30016028, DAT_30016260, DAT_30016504, DAT_30016598
 * ---------------------------------------------------------------- */
undefined4 FUN_30015630(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *DAT_30016028;
  if (iVar3 != 0) {
    if (((param_1 == 0) && ((*DAT_30016260 & 0x200) != 0)) &&
       (0xfffffff < (int)(*DAT_30016260 & 0xf0000000))) {
      printf(DAT_30016504);
    }
    iVar1 = nandc_native_location_by_blocknum(iVar3,param_1);
    if (iVar1 == 0) {
      uVar2 = FUN_300161c8(iVar3,0,0,0,0,0xd0);
      return uVar2;
    }
    if (((*DAT_30016260 & 0x200) != 0) && (-1 < (int)*DAT_30016260)) {
      printf(DAT_30016598,param_1);
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_30015718 @ 0x30015718  (примерный размер ~2336 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 15
 * Вызывает: FUN_30014448, FUN_30014c54, FUN_30015504, FUN_30015630, FUN_300161c8, FUN_3001640c, FUN_30016424, __udiv32, memcmp, memcpy, nandc_bbm_real_addr, nandc_get_block_buf, nandc_give_block_buf, nandc_native_location_by_address
 *           ...
 * Константы: 0xF0000000, 0x0FFFFFFF, 0x1FFFFFFF, 0x30015718
 * Данные: DAT_30016028, DAT_30016260, DAT_3001659c, DAT_300165a0, DAT_300165a4, DAT_300165a8, DAT_300165ac, DAT_300165b0
 * ---------------------------------------------------------------- */
int FUN_30015718(uint param_1,void *param_2,uint param_3,int param_4,int *param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *__s1;
  void *pvVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int local_68;
  size_t local_64;
  void *local_60;
  void *local_5c;
  uint local_58;
  undefined4 *local_50;
  size_t local_48;
  int local_44;
  int local_40;
  int local_34;
  void *local_8;
  uint local_4;
  
  local_50 = (undefined4 *)0x0;
  piVar2 = (int *)*DAT_30016028;
  iVar4 = 0;
  local_60 = (void *)0x0;
  local_5c = (void *)0x0;
  local_68 = 0;
  if (piVar2 != (int *)0x0) {
    iVar3 = *piVar2;
    local_4 = param_3;
    if (param_4 != 0) {
      local_68 = nandc_native_location_by_address(piVar2,param_1);
      if (local_68 != 0) goto LAB_30015f78;
      iVar1 = __udiv32(param_3,param_4 + *(int *)(iVar3 + 4));
      local_4 = param_3 - param_4 * iVar1;
      if (((local_4 & *(uint *)(iVar3 + 0xc)) != 0) || ((param_1 & *(uint *)(iVar3 + 0x2c)) != 0)) {
        if (((*DAT_30016260 & 0x200) != 0) && (-1 < (int)*DAT_30016260)) {
          printf(DAT_3001659c,local_4,param_1);
        }
        local_68 = 3;
        goto LAB_30015f78;
      }
    }
    if (((*DAT_30016260 & 0x200) != 0) && (0x1fffffff < (int)(*DAT_30016260 & 0xf0000000))) {
      printf(DAT_300165a0,param_1,param_2,local_4,param_4,param_5);
    }
    local_58 = local_4;
    if (param_4 == 0) {
      local_44 = *(int *)(iVar3 + 0x20);
    }
    else {
      local_44 = __udiv32(*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 4));
      local_44 = (param_4 + *(int *)(iVar3 + 4)) * local_44;
    }
    local_60 = (void *)nandc_get_block_buf(local_44);
    if (local_60 != (void *)0x0) {
      if (param_4 == 0) {
        local_40 = *(int *)(iVar3 + 0x20);
      }
      else {
        local_40 = __udiv32(*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 4));
        local_40 = (param_4 + *(int *)(iVar3 + 4)) * local_40;
      }
      local_5c = (void *)nandc_get_block_buf(local_40);
      local_8 = param_2;
      if (local_5c != (void *)0x0) {
        while (local_58 != 0) {
          local_68 = nandc_native_location_by_address(piVar2,param_1);
          if (local_68 != 0) {
            if (((*DAT_30016260 & 0x200) != 0) && (-1 < (int)*DAT_30016260)) {
              printf(DAT_300165a4,param_1);
            }
            goto LAB_30015f78;
          }
          if (local_50 == (undefined4 *)0x0) {
            local_50 = (undefined4 *)piVar2[2];
          }
          else if ((undefined4 *)piVar2[2] != local_50) {
            if (((*DAT_30016260 & 0x200) != 0) && (-1 < (int)*DAT_30016260)) {
              printf(DAT_300165a8,param_1,*local_50);
            }
            local_68 = 0xb;
            goto LAB_30015f78;
          }
          local_68 = FUN_30014448(param_1 >> (*(uint *)(iVar3 + 0x34) & 0xff),&local_34);
          if (local_68 != 0) {
            if (((*DAT_30016260 & 0x200) != 0) && (-1 < (int)*DAT_30016260)) {
              printf(DAT_300165ac,param_1);
            }
            goto LAB_30015f78;
          }
          pvVar5 = local_8;
          if (local_34 == 1) {
            if (((*DAT_30016260 & 0x200) != 0) && (0xfffffff < (int)(*DAT_30016260 & 0xf0000000))) {
              printf(DAT_300165b0,param_1);
            }
            param_1 = param_1 + *(int *)(*piVar2 + 0x20);
            iVar4 = iVar4 + 1;
          }
          else {
            if (((*DAT_30016260 & 0x200) != 0) && (0x1fffffff < (int)(*DAT_30016260 & 0xf0000000)))
            {
              printf(DAT_300165b4,param_1);
            }
            uVar8 = param_1 & *(uint *)(iVar3 + 0x2c);
            local_64 = *(int *)(iVar3 + 0x20) - uVar8;
            if (local_58 < local_64) {
              local_64 = local_58;
            }
            local_68 = nandc_bbm_real_addr(piVar2[0x1d],piVar2 + 0x1c);
            if (local_68 != 0) goto LAB_30015f78;
            if ((*(size_t *)(iVar3 + 0x20) == local_64) || (param_4 != 0)) {
              local_68 = FUN_30014c54(param_1 & *(uint *)(iVar3 + 0x30),local_60,param_4);
              if (local_68 == 0) {
                local_68 = FUN_30015630(param_1 >> (*(uint *)(iVar3 + 0x34) & 0xff));
                __s1 = local_8;
                uVar6 = local_58;
                uVar7 = param_1;
                if (*(uint *)(iVar3 + 0x20) <= local_58) {
                  uVar6 = *(uint *)(iVar3 + 0x20);
                }
                goto LAB_30015cbc;
              }
              if (((*DAT_30016260 & 0x200) != 0) && (0xfffffff < (int)(*DAT_30016260 & 0xf0000000)))
              {
                printf(DAT_300165c4,param_1,uVar8,local_64,*(undefined4 *)(iVar3 + 0x20),
                       DAT_300165c0);
              }
              FUN_30015504(param_1 >> (*(uint *)(iVar3 + 0x34) & 0xff));
              param_1 = param_1 + *(int *)(iVar3 + 0x20);
              iVar4 = iVar4 + 1;
            }
            else {
              local_68 = FUN_30014c54(param_1 & *(uint *)(iVar3 + 0x30),local_60,0);
              if (local_68 == 0) {
                uVar7 = param_1 & *(uint *)(iVar3 + 0x30);
                local_68 = FUN_30015630(uVar7 >> (*(uint *)(iVar3 + 0x34) & 0xff));
                uVar6 = *(uint *)(iVar3 + 0x20);
                memcpy((void *)((int)local_60 + uVar8),local_8,local_64);
                __s1 = local_60;
LAB_30015cbc:
                if (local_68 == 0) {
                  FUN_30016424(piVar2,0x10);
                  pvVar5 = __s1;
                  local_48 = uVar6;
                  if (param_4 != 0) {
                    iVar1 = __udiv32(uVar6,*(undefined4 *)(iVar3 + 4));
                    local_48 = (param_4 + *(int *)(iVar3 + 4)) * iVar1;
                  }
                  for (; uVar6 != 0; uVar6 = uVar6 - iVar9) {
                    if (param_4 == 0) {
                      iVar1 = 0;
                    }
                    else {
                      iVar1 = (int)pvVar5 + *(int *)(iVar3 + 4);
                    }
                    local_68 = FUN_300161c8(piVar2,pvVar5,iVar1,0,param_4,0x10);
                    if (local_68 != 0) {
                      if (((*DAT_30016260 & 0x200) != 0) && (-1 < (int)*DAT_30016260)) {
                        printf(DAT_300165cc,piVar2[0x1f],piVar2[0x1c]);
                      }
                      FUN_30015504(uVar7 >> (*(uint *)(iVar3 + 0x34) & 0xff));
                      iVar4 = iVar4 + 1;
                      param_1 = param_1 + *(int *)(iVar3 + 0x20);
                      pvVar5 = local_8;
                      goto LAB_30015f0c;
                    }
                    if (param_4 == 0) {
                      iVar1 = *(int *)(iVar3 + 4);
                    }
                    else {
                      iVar1 = *(int *)(iVar3 + 4) + param_4;
                    }
                    iVar9 = *(int *)(iVar3 + 4);
                    piVar2[0x1c] = piVar2[0x1c] + *(int *)(iVar3 + 4);
                    pvVar5 = (void *)((int)pvVar5 + iVar1);
                  }
                  local_68 = FUN_30014c54(uVar7,local_5c,param_4);
                  if ((local_68 == 0) && (iVar1 = memcmp(__s1,local_5c,local_48), iVar1 == 0)) {
                    local_58 = local_58 - local_64;
                    param_1 = param_1 + local_64;
                    if (param_4 == 0) {
                      pvVar5 = (void *)((int)local_8 + local_64);
                    }
                  }
                  else {
                    if (((*DAT_30016260 & 0x200) != 0) &&
                       (0xfffffff < (int)(*DAT_30016260 & 0xf0000000))) {
                      printf(DAT_300165d0,uVar7,uVar8,local_64,*(undefined4 *)(iVar3 + 0x20));
                    }
                    FUN_30015504(uVar7 >> (*(uint *)(iVar3 + 0x34) & 0xff));
                    iVar4 = iVar4 + 1;
                    param_1 = param_1 + *(int *)(iVar3 + 0x20);
                    pvVar5 = local_8;
                  }
                }
                else {
                  if (((*DAT_30016260 & 0x200) != 0) &&
                     (0xfffffff < (int)(*DAT_30016260 & 0xf0000000))) {
                    printf(DAT_300165c8,uVar7);
                  }
                  FUN_30015504(uVar7 >> (*(uint *)(iVar3 + 0x34) & 0xff));
                  param_1 = param_1 + *(int *)(iVar3 + 0x20);
                  iVar4 = iVar4 + 1;
                }
              }
              else {
                if (((*DAT_30016260 & 0x200) != 0) &&
                   (0xfffffff < (int)(*DAT_30016260 & 0xf0000000))) {
                  printf(DAT_300165bc,param_1,uVar8,local_64,*(undefined4 *)(iVar3 + 0x20),
                         DAT_300165b8);
                }
                FUN_30015504(param_1 >> (*(uint *)(iVar3 + 0x34) & 0xff));
                param_1 = param_1 + *(int *)(iVar3 + 0x20);
                iVar4 = iVar4 + 1;
              }
            }
          }
LAB_30015f0c:
          local_8 = pvVar5;
          FUN_3001640c(piVar2);
        }
        if ((((param_5 != (int *)0x0) &&
             (*param_5 = iVar4 << (*(uint *)(iVar3 + 0x34) & 0xff), *param_5 != 0)) &&
            ((*DAT_30016260 & 0x200) != 0)) && (-1 < (int)*DAT_30016260)) {
          printf(DAT_300165d4,*param_5);
        }
LAB_30015f78:
        if (local_60 != (void *)0x0) {
          nandc_give_block_buf(local_60);
        }
        if (local_5c == (void *)0x0) {
          return local_68;
        }
        nandc_give_block_buf(local_5c);
        return local_68;
      }
    }
  }
  if (local_60 != (void *)0x0) {
    nandc_give_block_buf(local_60);
  }
  if (local_5c != (void *)0x0) {
    nandc_give_block_buf(local_5c);
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_30016038 @ 0x30016038  (примерный размер ~208 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300161c8, memcpy, nandc_bbm_real_addr, printf
 * Вызывают: FUN_3001465c
 * Константы: 0x30016038
 * Данные: DAT_30016260, DAT_300165d8
 * ---------------------------------------------------------------- */
undefined4 FUN_30016038(int *param_1,int param_2,void *param_3,size_t param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[4];
  iVar1 = nandc_bbm_real_addr(*(uint *)(*param_1 + 0x10) & param_1[0x1d],param_1 + 0x1c);
  if (iVar1 == 0) {
    iVar1 = FUN_300161c8(param_1,iVar2 + 0x368,0,0,0,0x30);
    if (iVar1 == 0) {
      memcpy(param_3,(void *)(iVar2 + 0x368 + param_2),param_4);
      return 0;
    }
    if (((*DAT_30016260 & 0x200) != 0) && (-1 < (int)*DAT_30016260)) {
      printf(DAT_300165d8,param_1[0x1f],param_1[0x1c]);
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_30016108 @ 0x30016108  (примерный размер ~192 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_3001639c, nandc_native_location_by_blocknum, printf
 * Вызывают: FUN_300143d4, FUN_3001548c
 * Константы: 0x30016108, 0x1FFFFFFF, 0xF0000000
 * Данные: DAT_30016260, DAT_300165dc
 * ---------------------------------------------------------------- */
undefined4 FUN_30016108(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = nandc_native_location_by_blocknum(param_1,param_2);
  if (iVar1 == 0) {
    param_1[0x1c] = param_1[0x1c] + (param_3 << (*(uint *)(*param_1 + 0x14) & 0xff));
    iVar1 = FUN_3001639c(param_1);
    if (iVar1 == 0) {
      uVar2 = param_1[0x15];
      if (((*DAT_30016260 & 0x200) != 0) && (0x1fffffff < (int)(*DAT_30016260 & 0xf0000000))) {
        printf(DAT_300165dc,uVar2);
      }
      if (*(int *)(*param_1 + 0x40) == 2) {
        param_1[0x1a] = param_1[0x1a] + (uVar2 >> 1);
      }
      else {
        param_1[0x1a] = uVar2 + param_1[0x1a];
      }
      param_1[0x1c] = -1;
      return 0;
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300161c8 @ 0x300161C8  (примерный размер ~468 байт)
 * Модуль: flash | Вызывают: 13 | Вызывает: 5
 * Вызывает: FUN_3001639c, FUN_30016480, FUN_30016510, nandc_ctrl_entry, printf
 * Вызывают: FUN_300141bc, FUN_3001434c, FUN_300143d4, FUN_3001465c, FUN_30014c54, FUN_3001529c, FUN_30015418, FUN_3001548c, FUN_30015630, FUN_30015718
 *           ...
 * Константы: 0x300161C8
 * Данные: DAT_300165e0, DAT_300165e4, DAT_300165e8, DAT_300165ec
 * ---------------------------------------------------------------- */
int FUN_300161c8(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  
  iVar1 = FUN_3001639c(param_1);
  if (iVar1 == 0) {
    if ((param_6 == 0x10) || (param_6 == 0x30)) {
      if (param_2 == 0 && param_3 == 0) goto LAB_30016394;
      if (param_4 == 0) {
        *(int *)(param_1 + 0x88) = param_2;
        if (param_3 == 0) {
          *(undefined4 *)(param_1 + 0x5c) = 0;
          *(undefined4 *)(param_1 + 0x8c) = 0;
        }
        else {
          *(undefined4 *)(param_1 + 0x5c) = 0;
          if (*(int *)(param_1 + 0x10) == 0) goto LAB_30016394;
          *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x10) + 0x1b4;
        }
        if ((*(uint *)(param_1 + 0x68) & DAT_300165e0) != 0) {
          if (((*DAT_300165e4 & 0x200) != 0) && (-1 < (int)*DAT_300165e4)) {
            printf(DAT_300165e8,*(undefined4 *)(param_1 + 0x68));
          }
          goto LAB_30016394;
        }
      }
      else {
        *(int *)(param_1 + 0x88) = param_2;
        *(undefined4 *)(param_1 + 0x8c) = 0;
        *(undefined4 *)(param_1 + 0x5c) = 4;
        *(int *)(param_1 + 0x78) = param_4;
      }
      if ((param_6 == 0x10) && (param_3 != 0)) {
        FUN_30016480(param_1,*(undefined4 *)(param_1 + 0x8c),param_3,param_5);
      }
    }
    else {
      if (param_6 != 0xd0) {
        if ((*DAT_300165e4 & 0x200) == 0) {
          return 1;
        }
        if ((int)*DAT_300165e4 < 0) {
          return 1;
        }
        printf(DAT_300165ec,param_6);
        return 1;
      }
      *(uint *)(param_1 + 0x68) =
           (uint)*(ushort *)(param_1 + 0x6a) | *(int *)(param_1 + 0x6c) << 0x10;
    }
    *(int *)(param_1 + 0x58) = param_6;
    iVar1 = nandc_ctrl_entry(param_1);
    if (((iVar1 == 0) && (param_6 == 0x30)) && (param_3 != 0)) {
      FUN_30016510(param_1,param_3,*(undefined4 *)(param_1 + 0x8c),param_5);
    }
  }
  else {
LAB_30016394:
    iVar1 = 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3001639c @ 0x3001639C  (примерный размер ~112 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30016108, FUN_300161c8
 * Константы: 0x3001639C
 * ---------------------------------------------------------------- */
undefined4 FUN_3001639c(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (param_1[0x1c] == -1) {
    param_1[0x1c] = 0;
  }
  else {
    uVar2 = param_1[0x1c] & *(uint *)(iVar3 + 0xc);
    if (*(int *)(iVar3 + 0x40) == 2) {
      uVar2 = uVar2 >> 1;
    }
    uVar1 = (uint)param_1[0x1c] >> (*(uint *)(iVar3 + 0x14) & 0xff);
    param_1[0x1a] = uVar2 | uVar1 << 0x10;
    param_1[0x1b] = uVar1 >> 0x10;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3001640c @ 0x3001640C  (примерный размер ~24 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_3001465c, FUN_30014c54, FUN_30015718
 * Константы: 0x3001640C
 * ---------------------------------------------------------------- */
void FUN_3001640c(int param_1)

{
  *(undefined4 *)(param_1 + 0x60) = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30016424 @ 0x30016424  (примерный размер ~92 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_3001465c, FUN_30014c54, FUN_30015718
 * Константы: 0x30016424
 * ---------------------------------------------------------------- */
void FUN_30016424(int param_1,int param_2)

{
  if (param_2 == 0x30) {
    if (*(int *)(param_1 + 0x60) != 2) {
      *(undefined4 *)(param_1 + 0x60) = 1;
    }
  }
  else if ((param_2 == 0x10) && (*(int *)(param_1 + 0x60) != 4)) {
    *(undefined4 *)(param_1 + 0x60) = 3;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30016480 @ 0x30016480  (примерный размер ~144 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: memcpy
 * Вызывают: FUN_300161c8
 * Константы: 0x30016480
 * ---------------------------------------------------------------- */
undefined4 FUN_30016480(int param_1,int param_2,void *param_3,uint param_4)

{
  size_t __n;
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(*(int *)(param_1 + 8) + 0x14) + 0x108);
  for (; (piVar1[1] != 0 && (param_4 != 0)); param_4 = param_4 - __n) {
    __n = param_4;
    if ((uint)piVar1[1] <= param_4) {
      __n = piVar1[1];
    }
    memcpy((void *)(param_2 + *piVar1),param_3,__n);
    param_3 = (void *)((int)param_3 + __n);
    piVar1 = piVar1 + 2;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30016510 @ 0x30016510  (примерный размер ~224 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: memcpy
 * Вызывают: FUN_300161c8
 * Константы: 0x30016510
 * ---------------------------------------------------------------- */
undefined4 FUN_30016510(int param_1,void *param_2,int param_3,uint param_4)

{
  size_t __n;
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(*(int *)(param_1 + 8) + 0x14) + 0x108);
  for (; (piVar1[1] != 0 && (param_4 != 0)); param_4 = param_4 - __n) {
    __n = param_4;
    if ((uint)piVar1[1] <= param_4) {
      __n = piVar1[1];
    }
    memcpy(param_2,(void *)(param_3 + *piVar1),__n);
    param_2 = (void *)((int)param_2 + __n);
    piVar1 = piVar1 + 2;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * nandc_bbm_real_addr @ 0x300165F0  (примерный размер ~28 байт)
 * Модуль: flash | Вызывают: 6 | Вызывает: 0
 * Вызывают: FUN_3001465c, FUN_30014c54, FUN_30015718, FUN_30016038, nandc_native_location_by_address, nandc_native_location_by_pagenum
 * Константы: 0x300165F0
 * ---------------------------------------------------------------- */
undefined4 nandc_bbm_real_addr(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = param_1;
  return 0;
}

/* ----------------------------------------------------------------
 * nandc_native_reset_chip @ 0x3001660C  (примерный размер ~36 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: nandc_ctrl_entry
 * Вызывают: nandc_native_nand_prob
 * Константы: 0x3001660C
 * ---------------------------------------------------------------- */
void nandc_native_reset_chip(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x58) = 0xff;
  *(undefined4 *)(param_1 + 0x7c) = param_2;
  nandc_ctrl_entry(param_1);
  return;
}

/* ----------------------------------------------------------------
 * nandc_native_read_id @ 0x30016630  (примерный размер ~108 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: nandc_ctrl_entry, printf
 * Вызывают: nandc_native_get_id
 * Константы: 0x30016630
 * Данные: DAT_300170dc, DAT_300170e0
 * ---------------------------------------------------------------- */
undefined4 nandc_native_read_id(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_3 < 9) {
    *(undefined4 *)(param_1 + 0x58) = 0x90;
    *(undefined4 *)(param_1 + 0x88) = param_2;
    uVar1 = nandc_ctrl_entry(param_1);
  }
  else {
    if (((*DAT_300170dc & 0x100) != 0) && (-1 < (int)*DAT_300170dc)) {
      printf(DAT_300170e0,param_3);
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * nandc_native_get_spec @ 0x3001669C  (примерный размер ~1216 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: nandc_native_nand_prob
 * Константы: 0xF0000000, 0x3001669C, 0x00100000, 0x0FFFFFFF, 0x1FFFFFFF
 * Данные: DAT_300170dc, DAT_300170e4, DAT_300170e8, DAT_300170ec, DAT_300170f0, DAT_300170f4, DAT_300170f8, DAT_300170fc
 * ---------------------------------------------------------------- */
undefined4 nandc_native_get_spec(byte *param_1,int *param_2)

{
  uint uVar1;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int local_34;
  uint local_30;
  uint uVar2;
  
  uVar5 = 0;
  uVar7 = (uint)*param_1;
  uVar8 = (uint)param_1[1];
  for (piVar9 = DAT_300170e4; (*piVar9 != 0 && (piVar9[1] != uVar8)); piVar9 = piVar9 + 6) {
  }
  if (*piVar9 == 0) {
    if (((*DAT_300170dc & 0x100) != 0) && (-1 < (int)*DAT_300170dc)) {
      printf(DAT_300170e8,uVar7,uVar8);
    }
    uVar3 = 8;
  }
  else {
    iVar11 = piVar9[3];
    if (piVar9[2] == 0) {
      uVar4 = (uint)param_1[3];
      uVar1 = (int)uVar4 >> 2;
      uVar2 = (int)uVar4 >> 4;
      if ((((*param_1 == param_1[6]) && (param_1[1] == param_1[7])) && (*param_1 == 0xec)) &&
         (((param_1[2] & 0xc) != 0 && (param_1[5] != 0)))) {
        uVar6 = 0x800 << (uVar4 & 3);
        if ((uVar1 & 3) == 1) {
          uVar5 = 0x80;
        }
        else if ((uVar1 & 3) == 2) {
          uVar5 = 0xda;
        }
        else if ((uVar1 & 3) == 3) {
          uVar5 = 400;
        }
        else if ((uVar1 & 0xb) == 8) {
          uVar5 = 0x1b4;
        }
        local_34 = 0x20000 << ((int)uVar4 >> 5 & 4U | uVar2 & 3);
        local_30 = 0;
      }
      else if ((*param_1 == 0xec) && ((param_1[1] == 0xaa || (param_1[1] == 0xbc)))) {
        uVar6 = 0x400 << (uVar4 & 3);
        uVar5 = (uVar6 >> 9) * (8 << (uVar1 & 3));
        local_34 = 0x10000 << (uVar2 & 3);
        if (((int)uVar4 >> 6 & 1U) == 0) {
          local_30 = 0;
        }
        else {
          local_30 = 2;
        }
      }
      else if ((*param_1 == 0xad) &&
              ((((param_1[1] == 0xbc && (*param_1 == param_1[6])) && (param_1[1] == param_1[7])) &&
               (param_1[5] != 0)))) {
        if (param_1[2] == 0x80) {
          uVar6 = DAT_300170ec << (uVar4 & 3);
        }
        else {
          uVar6 = 0x800 << (uVar4 & 3);
        }
        if ((uVar1 & 0x13) == 0) {
          uVar5 = 0x80;
        }
        else if ((uVar1 & 0x13) == 1) {
          if (param_1[2] == 0x80) {
            uVar5 = 0x100;
            *DAT_300170f0 = 4;
          }
          else {
            uVar5 = 0xe0;
          }
        }
        else if ((uVar1 & 0x13) == 0x13) {
          uVar5 = 0x40;
        }
        if ((uVar2 & 8) == 0) {
          if ((uVar2 & 3) == 3) {
            local_34 = 0x300;
          }
          else {
            local_34 = 0x20000 << (uVar2 & 3);
          }
        }
        else if ((uVar2 & 0xb) == 8) {
          local_34 = 0x100000;
        }
        local_30 = 2;
      }
      else {
        uVar6 = 0x400 << (uVar4 & 3);
        uVar5 = (uVar6 >> 9) * (8 << (uVar1 & 1));
        local_34 = 0x10000 << (uVar2 & 3);
        if (((int)uVar4 >> 6 & 1U) == 0) {
          local_30 = 0;
        }
        else {
          local_30 = 2;
        }
      }
    }
    else {
      local_34 = piVar9[4];
      uVar6 = piVar9[2];
      uVar5 = uVar6 >> 5;
      local_30 = piVar9[5] & 2;
    }
    for (iVar10 = 0;
        (*(int *)(DAT_300170f4 + iVar10 * 8) != 0 && (*(uint *)(DAT_300170f4 + iVar10 * 8) != uVar7)
        ); iVar10 = iVar10 + 1) {
    }
    if (((*DAT_300170dc & 0x100) != 0) && (0xfffffff < (int)(*DAT_300170dc & 0xf0000000))) {
      printf(DAT_300170fc,uVar7,uVar8,*(undefined4 *)(DAT_300170f8 + iVar10 * 8),*piVar9);
    }
    if (((*DAT_300170dc & 0x100) != 0) && (0x1fffffff < (int)(*DAT_300170dc & 0xf0000000))) {
      printf(DAT_30017100,iVar11 << 0x14,uVar6,uVar5,local_34,local_30);
    }
    param_2[0x10] = local_30;
    param_2[8] = local_34;
    param_2[1] = uVar6;
    param_2[0xe] = iVar11 << 0x14;
    *param_2 = *piVar9;
    param_2[7] = uVar5;
    *DAT_30017104 = uVar6;
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * nandc_native_get_id @ 0x30016B5C  (примерный размер ~304 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: nandc_native_read_id, printf
 * Вызывают: nandc_native_nand_prob
 * Константы: 0x30016B5C
 * Данные: DAT_300170dc, DAT_30017108, DAT_3001710c, DAT_30017110
 * ---------------------------------------------------------------- */
undefined4 nandc_native_get_id(undefined4 param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = nandc_native_read_id(param_1,param_2,param_3);
  if (iVar3 == 0) {
    bVar1 = *param_2;
    bVar2 = param_2[1];
    iVar3 = nandc_native_read_id(param_1,param_2,param_3);
    if (iVar3 == 0) {
      if (((uint)*param_2 == (uint)bVar1) && ((uint)param_2[1] == (uint)bVar2)) {
        uVar4 = 0;
      }
      else {
        if (((*DAT_300170dc & 0x100) != 0) && (-1 < (int)*DAT_300170dc)) {
          printf(DAT_30017110,0,(uint)bVar1,(uint)bVar2,(uint)*param_2,(uint)param_2[1]);
        }
        uVar4 = 8;
      }
    }
    else {
      if (((*DAT_300170dc & 0x100) != 0) && (-1 < (int)*DAT_300170dc)) {
        printf(DAT_3001710c);
      }
      uVar4 = 8;
    }
  }
  else {
    if (((*DAT_300170dc & 0x100) != 0) && (-1 < (int)*DAT_300170dc)) {
      printf(DAT_30017108);
    }
    uVar4 = 8;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * nandc_native_nand_prob @ 0x30016C8C  (примерный размер ~232 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 5
 * Вызывает: nandc_host_add_nand_chip, nandc_native_get_id, nandc_native_get_spec, nandc_native_reset_chip, printf
 * Вызывают: nandc_nand_init
 * Константы: 0x30016C8C
 * Данные: DAT_300170dc, DAT_30017114
 * ---------------------------------------------------------------- */
undefined4 nandc_native_nand_prob(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  byte local_60;
  byte local_5f;
  undefined1 auStack_58 [76];
  
  iVar3 = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  do {
    if (*(uint *)(param_1 + 0x80) <= *(uint *)(param_1 + 0x7c)) {
      if (iVar3 == 0) {
        uVar2 = 1;
      }
      else {
        uVar2 = nandc_host_add_nand_chip(param_1,iVar3,auStack_58);
      }
      return uVar2;
    }
    nandc_native_reset_chip(param_1,*(undefined4 *)(param_1 + 0x7c));
    iVar1 = nandc_native_get_id(param_1,&local_60,8);
    if (iVar1 == 0) {
      iVar1 = nandc_native_get_spec(&local_60,auStack_58);
      if (iVar1 != 0) {
        if (((*DAT_300170dc & 0x100) != 0) && (-1 < (int)*DAT_300170dc)) {
          printf(DAT_30017114,*(undefined4 *)(param_1 + 0x7c),(uint)local_60,(uint)local_5f);
        }
        return 7;
      }
      iVar3 = iVar3 + 1;
    }
    *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * nandc_native_host_delete @ 0x30016D74  (примерный размер ~4 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30016D74
 * ---------------------------------------------------------------- */
void nandc_native_host_delete(void)

{
  return;
}

/* ----------------------------------------------------------------
 * nandc_native_host_create @ 0x30016D78  (примерный размер ~396 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 5
 * Вызывает: free, malloc, memset, nandc_host_init_cluster, printf
 * Вызывают: nandc_nand_create_host
 * Константы: 0x30016D78, 0xF0000000, 0x20000000
 * Данные: DAT_300170dc, DAT_30017118, DAT_3001711c, DAT_30017120, DAT_30017124
 * ---------------------------------------------------------------- */
void * nandc_native_host_create(uint *param_1)

{
  void *__s;
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  
  __s = malloc(0xa0);
  if ((((uint)__s & (uint)param_1) != 0) &&
     ((*param_1 & param_1[1] & param_1[2] & param_1[3] & param_1[4]) != 0)) {
    memset(__s,0,0xa0);
    printf(DAT_30017118,*(undefined4 *)(*param_1 + 4));
    puVar3 = (undefined4 *)*param_1;
    *(undefined4 *)((int)__s + 0x94) = puVar3[4];
    *(undefined4 *)((int)__s + 0x90) = puVar3[2];
    *(undefined4 *)((int)__s + 0x80) = puVar3[6];
    *(uint *)((int)__s + 0x14) = param_1[1];
    *(uint *)((int)__s + 0x18) = param_1[2];
    *(uint *)((int)__s + 0x1c) = param_1[4];
    *(undefined4 *)((int)__s + 0x98) = puVar3[3];
    *(undefined4 *)((int)__s + 0x9c) = puVar3[5];
    *(undefined4 *)((int)__s + 0x60) = 0;
    pvVar1 = malloc(DAT_3001711c);
    *(void **)((int)__s + 0x10) = pvVar1;
    if (*(int *)((int)__s + 0x10) != 0) {
      memset(*(void **)((int)__s + 0x10),0xff,DAT_3001711c);
      iVar2 = nandc_host_init_cluster(__s,*puVar3,param_1[3]);
      if (iVar2 == 0) {
        if ((*DAT_300170dc & 0x100) == 0) {
          return __s;
        }
        if ((int)(*DAT_300170dc & 0xf0000000) < 0x20000000) {
          return __s;
        }
        printf(DAT_30017120);
        return __s;
      }
    }
  }
  if ((__s != (void *)0x0) && (*(int *)((int)__s + 0x10) != 0)) {
    free(*(void **)((int)__s + 0x10));
  }
  if (__s != (void *)0x0) {
    free(__s);
  }
  if (((*DAT_300170dc & 0x100) != 0) && (-1 < (int)*DAT_300170dc)) {
    printf(DAT_30017124);
  }
  return (void *)0x0;
}

/* ----------------------------------------------------------------
 * nandc_native_find_partition @ 0x30016F04  (примерный размер ~188 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: nandc_native_location_by_address, nandc_native_location_by_pagenum
 * Константы: 0x30016F04
 * Данные: DAT_300170dc, DAT_30017128
 * ---------------------------------------------------------------- */
undefined4 nandc_native_find_partition(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = **(int **)(param_1 + 4);
  uVar2 = *(uint *)(*(int *)(param_1 + 4) + 8);
  uVar3 = 0;
  do {
    if (uVar2 <= uVar3) {
LAB_30016f70:
      if (uVar3 == uVar2) {
        if (((*DAT_300170dc & 0x100) != 0) && (-1 < (int)*DAT_300170dc)) {
          printf(DAT_30017128,param_2);
        }
        uVar1 = 4;
      }
      else {
        uVar1 = 0;
      }
      return uVar1;
    }
    if ((*(uint *)(iVar4 + 0xc) <= param_2) &&
       (param_2 < (uint)(*(int *)(iVar4 + 0xc) + *(int *)(iVar4 + 8)))) {
      *(int *)(param_1 + 8) = iVar4;
      goto LAB_30016f70;
    }
    iVar4 = iVar4 + 0x18;
    uVar3 = uVar3 + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * nandc_native_location_by_blocknum @ 0x30016FC0  (примерный размер ~72 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30015630, FUN_30016108
 * Константы: 0x30016FC0
 * ---------------------------------------------------------------- */
undefined4 nandc_native_location_by_blocknum(int *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  param_1[0x1c] = (param_2 & *(uint *)(iVar1 + 0x28)) << (*(uint *)(iVar1 + 0x34) & 0xff);
  param_1[0x1f] = param_2 >> (*(int *)(iVar1 + 0x3c) - *(int *)(iVar1 + 0x34) & 0xffU);
  return 0;
}

/* ----------------------------------------------------------------
 * nandc_native_location_by_pagenum @ 0x30017008  (примерный размер ~116 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 2
 * Вызывает: nandc_bbm_real_addr, nandc_native_find_partition
 * Константы: 0x30017008
 * ---------------------------------------------------------------- */
undefined4 nandc_native_location_by_pagenum(int *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  param_1[0x1d] = (param_2 & *(uint *)(iVar2 + 0x18)) << (*(uint *)(iVar2 + 0x14) & 0xff);
  param_1[0x1f] = param_2 >> (*(int *)(iVar2 + 0x3c) - *(int *)(iVar2 + 0x14) & 0xffU);
  iVar2 = nandc_native_find_partition(param_1,param_2 << (*(uint *)(iVar2 + 0x14) & 0xff));
  if (iVar2 == 0) {
    uVar1 = nandc_bbm_real_addr(param_1[0x1d],param_1 + 0x1c);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * nandc_native_location_by_address @ 0x3001707C  (примерный размер ~176 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 2
 * Вызывает: nandc_bbm_real_addr, nandc_native_find_partition
 * Вызывают: FUN_3001434c, FUN_3001465c, FUN_30014c54, FUN_30015418, FUN_30015718
 * Константы: 0x3001707C
 * ---------------------------------------------------------------- */
undefined4 nandc_native_location_by_address(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1[0x1d] = param_2 & *(int *)(*param_1 + 0x38) - 1U;
  param_1[0x1f] = param_2 >> (*(uint *)(*param_1 + 0x3c) & 0xff);
  iVar1 = nandc_native_find_partition(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = nandc_bbm_real_addr(param_1[0x1d],param_1 + 0x1c);
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nandc_get_block_buf @ 0x3001712C  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: malloc
 * Вызывают: FUN_30015718
 * Константы: 0x3001712C
 * ---------------------------------------------------------------- */
void nandc_get_block_buf(size_t param_1)

{
  malloc(param_1);
  return;
}

/* ----------------------------------------------------------------
 * nandc_give_block_buf @ 0x30017140  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: free
 * Вызывают: FUN_30015718
 * Константы: 0x30017140
 * ---------------------------------------------------------------- */
void nandc_give_block_buf(void *param_1)

{
  free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * nandc_mutex_create @ 0x30017154  (примерный размер ~40 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: semMCreate
 * Вызывают: nand_init_platform
 * Константы: 0x30017154
 * ---------------------------------------------------------------- */
bool nandc_mutex_create(int *param_1)

{
  int iVar1;
  
  iVar1 = semMCreate(9);
  *param_1 = iVar1;
  return *param_1 == 0;
}

/* ----------------------------------------------------------------
 * nandc_mutex_lock @ 0x3001717C  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 2
 * Вызывает: printf, semTake
 * Константы: 0x3001717C, 0xFFFFFFFF
 * Данные: DAT_3001723c, DAT_30017240
 * ---------------------------------------------------------------- */
undefined4 nandc_mutex_lock(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = semTake(param_1,0xffffffff);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if (((*DAT_3001723c & 0x400) != 0) && (-1 < (int)*DAT_3001723c)) {
      printf(DAT_30017240);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nandc_mutex_unlock @ 0x300171D4  (примерный размер ~84 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 2
 * Вызывает: printf, semGive
 * Константы: 0x300171D4
 * Данные: DAT_3001723c, DAT_30017244
 * ---------------------------------------------------------------- */
undefined4 nandc_mutex_unlock(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = semGive(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if (((*DAT_3001723c & 0x400) != 0) && (-1 < (int)*DAT_3001723c)) {
      printf(DAT_30017244);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nandc_mutex_delete @ 0x30017228  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: semDelete
 * Вызывают: nand_deinit
 * Константы: 0x30017228
 * ---------------------------------------------------------------- */
void nandc_mutex_delete(undefined4 param_1)

{
  semDelete(param_1);
  return;
}

/* ----------------------------------------------------------------
 * nandc2_ctrl_init @ 0x30017248  (примерный размер ~200 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30017248, 0xFFFFFDFF
 * Данные: DAT_3001730c
 * ---------------------------------------------------------------- */
undefined4 nandc2_ctrl_init(undefined1 *param_1,int param_2)

{
  param_1[7] = 0x6d;
  param_1[10] = 0x44;
  *param_1 = 0x66;
  param_1[1] = 0x6e;
  param_1[2] = 2;
  param_1[3] = 2;
  param_1[4] = 0x70;
  param_1[5] = 0x10;
  param_1[6] = 0x1d;
  *(short *)(param_1 + 0xe) = (short)DAT_3001730c;
  *(undefined2 *)(param_1 + 0x10) = 0;
  *(short *)(param_1 + 0x12) = (short)DAT_3001730c;
  param_1[0xb] = 0;
  param_1[0xc] = 1;
  param_1[0xd] = 2;
  *(undefined2 *)(param_1 + 0x16) = 1;
  *(undefined2 *)(param_1 + 0x18) = 0;
  *(undefined2 *)(param_1 + 0x14) = 0;
  **(uint **)(param_2 + 0x90) = **(uint **)(param_2 + 0x90) & 0xfffffdff | 0x200;
  return 0;
}

/* ----------------------------------------------------------------
 * nandc3_ctrl_init @ 0x30017310  (примерный размер ~188 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30017310
 * Данные: DAT_300173c4, DAT_300173c8
 * ---------------------------------------------------------------- */
undefined4 nandc3_ctrl_init(undefined1 *param_1,int param_2)

{
  param_1[7] = 0x6d;
  param_1[10] = 0x44;
  *param_1 = 0x66;
  param_1[1] = 0x6e;
  param_1[2] = 2;
  param_1[3] = 2;
  param_1[4] = 0x70;
  param_1[5] = 0x10;
  param_1[6] = 0x1d;
  *(short *)(param_1 + 0xe) = (short)DAT_300173c4;
  *(undefined2 *)(param_1 + 0x10) = 0;
  *(short *)(param_1 + 0x12) = (short)DAT_300173c4;
  param_1[0xb] = 0;
  param_1[0xc] = 1;
  param_1[0xd] = 2;
  *(undefined2 *)(param_1 + 0x16) = 1;
  *(undefined2 *)(param_1 + 0x18) = 0;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x90) + 4) = DAT_300173c8;
  return 0;
}

/* ----------------------------------------------------------------
 * nandc4_ctrl_init @ 0x300173CC  (примерный размер ~204 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300173CC
 * Данные: DAT_30017490, DAT_30017494
 * ---------------------------------------------------------------- */
undefined4 nandc4_ctrl_init(undefined1 *param_1,int param_2)

{
  param_1[7] = 0x6d;
  param_1[10] = 0x44;
  *param_1 = 0x66;
  param_1[1] = 0x6e;
  param_1[2] = 2;
  param_1[3] = 2;
  param_1[4] = 0x70;
  param_1[5] = 0x10;
  param_1[6] = 0x1d;
  param_1[8] = 0;
  param_1[9] = 1;
  *(short *)(param_1 + 0xe) = (short)DAT_30017490;
  *(undefined2 *)(param_1 + 0x10) = 0;
  *(short *)(param_1 + 0x12) = (short)DAT_30017490;
  param_1[0xb] = 0;
  param_1[0xc] = 1;
  param_1[0xd] = 2;
  *(undefined2 *)(param_1 + 0x16) = 0x3f;
  *(undefined2 *)(param_1 + 0x18) = 3;
  *(undefined2 *)(param_1 + 0x14) = 0x2a;
  *(undefined4 *)(*(int *)(param_2 + 0x90) + 4) = DAT_30017494;
  return 0;
}

/* ----------------------------------------------------------------
 * nand_erase_all @ 0x300176F0  (примерный размер ~196 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: nand_get_spec, printf
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x300176F0, 0x3001772C, 0x30017744, 0x30017750, 0x30017764, 0x30017778, 0x30017788
 * Данные: DAT_30017cf4, DAT_30017cf8
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x3001772c) */
/* WARNING: Removing unreachable block (ram,0x30017744) */
/* WARNING: Removing unreachable block (ram,0x30017750) */
/* WARNING: Removing unreachable block (ram,0x30017764) */
/* WARNING: Removing unreachable block (ram,0x30017778) */
/* WARNING: Removing unreachable block (ram,0x30017788) */

bool nand_erase_all(void)

{
  int iVar1;
  undefined4 local_1c [4];
  
  iVar1 = nand_get_spec(local_1c);
  if (iVar1 != 0) {
    printf(DAT_30017cf8);
  }
  else {
    printf(DAT_30017cf4,local_1c[0]);
  }
  return iVar1 != 0;
}

/* ----------------------------------------------------------------
 * nand_export_data @ 0x300177E4  (примерный размер ~408 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 8
 * Вызывает: fclose, fopen, free, fwrite, malloc, nand_get_spec, nand_read, printf
 * Константы: 0x300177E4
 * Данные: DAT_30017cfc, DAT_30017d00, DAT_30017d04, DAT_30017d08, DAT_30017d0c, DAT_30017d10, DAT_30017d14, DAT_30017d18
 * ---------------------------------------------------------------- */
int nand_export_data(undefined4 param_1,size_t param_2,char *param_3)

{
  size_t sVar1;
  void *__ptr;
  FILE *__s;
  int iVar2;
  undefined4 local_38;
  undefined1 auStack_34 [16];
  
  __s = (FILE *)0x0;
  __ptr = (void *)0x0;
  if ((param_3 == (char *)0x0) || (param_2 == 0)) {
    printf(DAT_30017cfc);
    iVar2 = 1;
  }
  else {
    iVar2 = nand_get_spec(auStack_34);
    if (iVar2 == 0) {
      __ptr = malloc(param_2);
      if (__ptr == (void *)0x0) {
        printf(DAT_30017d04,param_2);
        iVar2 = 1;
      }
      else {
        printf(DAT_30017d08,__ptr);
        iVar2 = nand_read(param_1,__ptr,param_2,&local_38);
        if (iVar2 == 0) {
          printf(DAT_30017d10,local_38);
          __s = fopen(param_3,DAT_30017d14);
          if (__s == (FILE *)0x0) {
            printf(DAT_30017d18,param_3);
            iVar2 = 1;
          }
          else {
            sVar1 = fwrite(__ptr,param_2,1,__s);
            if (sVar1 == 1) {
              iVar2 = fclose(__s);
              if (iVar2 != 0) {
                printf(DAT_30017d20,param_3);
                __s = (FILE *)0x0;
              }
            }
            else {
              printf(DAT_30017d1c,param_2);
              iVar2 = 1;
            }
          }
        }
        else {
          printf(DAT_30017d0c,param_1,param_2);
        }
      }
    }
    else {
      printf(DAT_30017d00);
    }
  }
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * nand_export_data_with_oob @ 0x3001797C  (примерный размер ~444 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 9
 * Вызывает: __urem32, fclose, fopen, free, fwrite, malloc, nand_get_spec, nand_read_oob, printf
 * Константы: 0x3001797C
 * Данные: DAT_30017d04, DAT_30017d08, DAT_30017d0c, DAT_30017d10, DAT_30017d14, DAT_30017d18, DAT_30017d1c, DAT_30017d20
 * ---------------------------------------------------------------- */
int nand_export_data_with_oob(undefined4 param_1,size_t param_2,char *param_3)

{
  int iVar1;
  size_t sVar2;
  void *__ptr;
  FILE *__s;
  undefined4 local_38;
  undefined1 auStack_34 [4];
  int local_30;
  
  __s = (FILE *)0x0;
  __ptr = (void *)0x0;
  iVar1 = nand_get_spec(auStack_34);
  if (iVar1 == 0) {
    if (((param_3 == (char *)0x0) || (param_2 == 0)) ||
       (iVar1 = __urem32(param_2,local_30 + 0x10), iVar1 != 0)) {
      printf(DAT_30017d28);
      iVar1 = 1;
    }
    else {
      __ptr = malloc(param_2);
      if (__ptr == (void *)0x0) {
        printf(DAT_30017d04,param_2);
        iVar1 = 1;
      }
      else {
        printf(DAT_30017d08,__ptr);
        iVar1 = nand_read_oob(param_1,__ptr,param_2,0x10,&local_38);
        if (iVar1 == 0) {
          printf(DAT_30017d10,local_38);
          __s = fopen(param_3,DAT_30017d14);
          if (__s == (FILE *)0x0) {
            printf(DAT_30017d18,param_3);
            iVar1 = 1;
          }
          else {
            sVar2 = fwrite(__ptr,param_2,1,__s);
            if (sVar2 == 1) {
              iVar1 = fclose(__s);
              if (iVar1 != 0) {
                printf(DAT_30017d20,param_3);
                __s = (FILE *)0x0;
              }
            }
            else {
              printf(DAT_30017d1c,param_2);
              iVar1 = 1;
            }
          }
        }
        else {
          printf(DAT_30017d0c,param_1,param_2);
        }
      }
    }
  }
  else {
    printf(DAT_30017d24);
  }
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * nand_quary_bad @ 0x30017B38  (примерный размер ~256 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 4
 * Вызывает: __udiv32, nand_get_spec, nand_isbad, printf
 * Константы: 0x30017B38
 * Данные: DAT_30017ce0, DAT_30017d2c, DAT_30017d30, DAT_30017d34
 * ---------------------------------------------------------------- */
int nand_quary_bad(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int local_28;
  undefined4 local_24 [2];
  undefined4 local_1c;
  
  local_28 = 0;
  iVar1 = nand_get_spec(local_24);
  if (iVar1 == 0) {
    uVar2 = __udiv32(local_1c,local_24[0]);
    if (((param_1 < uVar2) && (uVar2 = __udiv32(local_1c,local_24[0]), param_2 < uVar2)) &&
       (param_1 <= param_2)) {
      for (; param_1 <= param_2; param_1 = param_1 + 1) {
        iVar1 = nand_isbad(param_1,&local_28);
        if (iVar1 == 0) {
          if (local_28 == 1) {
            printf(DAT_30017ce0,param_1);
          }
        }
        else {
          printf(DAT_30017d34,param_1);
        }
      }
      iVar1 = 0;
    }
    else {
      printf(DAT_30017d30);
      iVar1 = 1;
    }
  }
  else {
    printf(DAT_30017d2c);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * yaffs2_CheckpointOpen @ 0x30018250  (примерный размер ~384 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_30017ea0, FUN_30017ee4, malloc, memset
 * Вызывают: FUN_30029ffc, FUN_3002a144
 * Константы: 0xFFFFFFFF, 0x30018250
 * ---------------------------------------------------------------- */
undefined4 yaffs2_CheckpointOpen(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  
  *(int *)(param_1 + 0xfc) = param_2;
  if ((((*(int *)(param_1 + 0x54) == 0) || (*(int *)(param_1 + 0x58) == 0)) ||
      (*(int *)(param_1 + 0x48) == 0)) || (*(int *)(param_1 + 0x5c) == 0)) {
    uVar1 = 0;
  }
  else if ((param_2 == 0) || (iVar2 = FUN_30017ea0(param_1), iVar2 != 0)) {
    if (*(int *)(param_1 + 0xf8) == 0) {
      pvVar3 = malloc(*(size_t *)(param_1 + 8));
      *(void **)(param_1 + 0xf8) = pvVar3;
    }
    if (*(int *)(param_1 + 0xf8) == 0) {
      uVar1 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0xec) = 0;
      *(undefined4 *)(param_1 + 0xf0) = 0;
      *(undefined4 *)(param_1 + 0x118) = 0;
      *(undefined4 *)(param_1 + 0x11c) = 0;
      *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x104) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_1 + 0xdc);
      if (param_2 == 0) {
        *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_1 + 0x9c);
        *(undefined4 *)(param_1 + 0x100) = 0;
        iVar2 = *(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc);
        *(int *)(param_1 + 0x114) = ((int)(iVar2 + ((uint)(iVar2 >> 0x1f) >> 0x1c)) >> 4) + 2;
        pvVar3 = malloc(*(int *)(param_1 + 0x114) << 2);
        *(void **)(param_1 + 0x110) = pvVar3;
        if (*(int *)(param_1 + 0x110) == 0) {
          uVar1 = 0;
        }
        else {
          for (iVar2 = 0; iVar2 < *(int *)(param_1 + 0x114); iVar2 = iVar2 + 1) {
            *(undefined4 *)(*(int *)(param_1 + 0x110) + iVar2 * 4) = 0xffffffff;
          }
          uVar1 = 1;
        }
      }
      else {
        memset(*(void **)(param_1 + 0xf8),0,*(size_t *)(param_1 + 0x9c));
        *(undefined4 *)(param_1 + 0xf4) = 0;
        uVar1 = FUN_30017ee4(param_1);
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs2_GetCheckpointSum @ 0x300183D0  (примерный размер ~44 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30029f50, FUN_30029f98
 * Константы: 0x300183D0
 * ---------------------------------------------------------------- */
undefined4 yaffs2_GetCheckpointSum(int param_1,uint *param_2)

{
  *param_2 = *(uint *)(param_1 + 0x11c) & 0xff | *(int *)(param_1 + 0x118) << 8;
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_300183fc @ 0x300183FC  (примерный размер ~372 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_30017e20, FUN_30018014, memset, printf
 * Вызывают: yaffs2_CheckpointClose, yaffs2_CheckpointWrite
 * Константы: 0x300183FC, 0xFF0FFFFF, 0x00700000, 0xFFFFFFFF
 * Данные: DAT_30018988, DAT_300189bc
 * ---------------------------------------------------------------- */
undefined4 FUN_300183fc(int param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  undefined1 auStack_5c [8];
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_40;
  undefined4 local_38;
  
  if (*(int *)(param_1 + 0x108) < 0) {
    FUN_30018014(param_1);
    *(undefined4 *)(param_1 + 0x104) = 0;
  }
  if (*(int *)(param_1 + 0x108) < 0) {
    uVar1 = 0;
  }
  else {
    local_40 = 0;
    local_54 = *(undefined4 *)(param_1 + 0x10c);
    local_50 = *(int *)(param_1 + 0xec) + 1;
    local_38 = 0x21;
    local_4c = *(undefined4 *)(param_1 + 0x9c);
    if (*(int *)(param_1 + 0x104) == 0) {
      puVar2 = (uint *)FUN_30017e20(param_1,*(undefined4 *)(param_1 + 0x108));
      *puVar2 = *puVar2 & 0xff0fffff | 0x700000;
      *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;
    }
    iVar3 = *(int *)(param_1 + 0x108) * *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x104);
    if ((*DAT_30018988 & 0x8000) != 0) {
      printf(DAT_300189bc,iVar3,*(undefined4 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x104),
             local_54,local_50);
    }
    *(int *)(param_1 + 0xe28) = *(int *)(param_1 + 0xe28) + 1;
    (**(code **)(param_1 + 0x54))
              (param_1,iVar3 - *(int *)(param_1 + 0xe8),*(undefined4 *)(param_1 + 0xf8),auStack_5c);
    *(undefined4 *)(param_1 + 0xf4) = 0;
    *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + 1;
    *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 1;
    if (*(int *)(param_1 + 0xc) <= *(int *)(param_1 + 0x104)) {
      *(undefined4 *)(param_1 + 0x104) = 0;
      *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
    }
    memset(*(void **)(param_1 + 0xf8),0,*(size_t *)(param_1 + 0x9c));
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs2_CheckpointWrite @ 0x30018570  (примерный размер ~224 байт)
 * Модуль: flash | Вызывают: 6 | Вызывает: 1
 * Вызывает: FUN_300183fc
 * Вызывают: FUN_30029388, FUN_30029544, FUN_300299f4, FUN_30029ac8, FUN_30029c70, FUN_30029f50
 * Константы: 0x30018570
 * ---------------------------------------------------------------- */
int yaffs2_CheckpointWrite(int param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 1;
  if (*(int *)(param_1 + 0xf8) == 0) {
    iVar3 = 0;
  }
  else if (*(int *)(param_1 + 0xfc) == 0) {
    iVar3 = -1;
  }
  else {
    while ((iVar3 < param_3 && (iVar2 != 0))) {
      *(byte *)(*(int *)(param_1 + 0xf8) + *(int *)(param_1 + 0xf4)) = *param_2;
      *(uint *)(param_1 + 0x118) = *(int *)(param_1 + 0x118) + (uint)*param_2;
      pbVar1 = param_2 + 1;
      *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) ^ (uint)*param_2;
      *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;
      iVar3 = iVar3 + 1;
      *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
      param_2 = pbVar1;
      if ((*(int *)(param_1 + 0xf4) < 0) || (*(int *)(param_1 + 0x9c) <= *(int *)(param_1 + 0xf4)))
      {
        iVar2 = FUN_300183fc(param_1);
      }
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * yaffs2_CheckpointRead @ 0x30018650  (примерный размер ~444 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 1
 * Вызывает: FUN_3001811c
 * Вызывают: FUN_300293f8, FUN_300295fc, FUN_30029b40, FUN_30029dd4, FUN_30029f98
 * Константы: 0x30018650, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int yaffs2_CheckpointRead(int param_1,byte *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined1 auStack_6c [12];
  int local_60;
  int local_58;
  int local_48;
  
  iVar2 = 0;
  bVar1 = true;
  if (*(int *)(param_1 + 0xf8) == 0) {
    iVar2 = 0;
  }
  else if (*(int *)(param_1 + 0xfc) == 0) {
    while ((iVar2 < param_3 && (bVar1))) {
      if ((*(int *)(param_1 + 0xf4) < 0) || (*(int *)(param_1 + 0x9c) <= *(int *)(param_1 + 0xf4)))
      {
        if (*(int *)(param_1 + 0x108) < 0) {
          FUN_3001811c(param_1);
          *(undefined4 *)(param_1 + 0x104) = 0;
        }
        if (-1 < *(int *)(param_1 + 0x108)) {
          *(int *)(param_1 + 0xe2c) = *(int *)(param_1 + 0xe2c) + 1;
          (**(code **)(param_1 + 0x58))
                    (param_1,(*(int *)(param_1 + 0x108) * *(int *)(param_1 + 0xc) +
                             *(int *)(param_1 + 0x104)) - *(int *)(param_1 + 0xe8),
                     *(undefined4 *)(param_1 + 0xf8),auStack_6c);
          if (((local_60 != *(int *)(param_1 + 0xec) + 1) || (2 < local_58)) || (local_48 != 0x21))
          {
            bVar1 = false;
          }
          *(undefined4 *)(param_1 + 0xf4) = 0;
          *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + 1;
          *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 1;
          if (*(int *)(param_1 + 0xc) <= *(int *)(param_1 + 0x104)) {
            *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
          }
          goto LAB_300187a8;
        }
        bVar1 = false;
      }
      else {
LAB_300187a8:
        if (bVar1) {
          *param_2 = *(byte *)(*(int *)(param_1 + 0xf8) + *(int *)(param_1 + 0xf4));
          *(uint *)(param_1 + 0x118) = *(int *)(param_1 + 0x118) + (uint)*param_2;
          *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) ^ (uint)*param_2;
          *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;
          iVar2 = iVar2 + 1;
          *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
          param_2 = param_2 + 1;
        }
      }
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * yaffs2_CheckpointClose @ 0x3001880C  (примерный размер ~332 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_30017e20, FUN_300183fc, free, printf
 * Вызывают: FUN_30029ffc, FUN_3002a144
 * Константы: 0x3001880C, 0xFF0FFFFF, 0x00700000
 * Данные: DAT_30018988, DAT_300189c0
 * ---------------------------------------------------------------- */
bool yaffs2_CheckpointClose(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if (*(int *)(param_1 + 0xfc) == 0) {
    if (*(int *)(param_1 + 0x110) != 0) {
      for (iVar3 = 0;
          (iVar3 < *(int *)(param_1 + 0x100) &&
          (-1 < *(int *)(*(int *)(param_1 + 0x110) + iVar3 * 4))); iVar3 = iVar3 + 1) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x110) + iVar3 * 4);
        puVar1 = (uint *)0x0;
        if ((*(int *)(param_1 + 0xdc) <= iVar2) && (iVar2 <= *(int *)(param_1 + 0xe0))) {
          puVar1 = (uint *)FUN_30017e20(param_1,iVar2);
        }
        if ((puVar1 != (uint *)0x0) && ((*puVar1 >> 0x14 & 0xf) == 3)) {
          *puVar1 = *puVar1 & 0xff0fffff | 0x700000;
        }
      }
      free(*(void **)(param_1 + 0x110));
      *(undefined4 *)(param_1 + 0x110) = 0;
    }
  }
  else if (*(int *)(param_1 + 0xf4) != 0) {
    FUN_300183fc(param_1);
  }
  *(int *)(param_1 + 0xd58) =
       *(int *)(param_1 + 0xd58) - *(int *)(param_1 + 0xc) * *(int *)(param_1 + 0x100);
  *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x100);
  if ((*DAT_30018988 & 0x8000) != 0) {
    printf(DAT_300189c0,*(undefined4 *)(param_1 + 0xf0));
  }
  bVar4 = *(int *)(param_1 + 0xf8) != 0;
  if (bVar4) {
    free(*(void **)(param_1 + 0xf8));
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  return bVar4;
}

/* ----------------------------------------------------------------
 * yaffs2_CheckpointInvalidateStream @ 0x30018958  (примерный размер ~112 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30017ee4, printf
 * Вызывают: yaffs2_InvalidateCheckpoint
 * Константы: 0x30018958
 * Данные: DAT_30018988, DAT_300189c4
 * ---------------------------------------------------------------- */
void yaffs2_CheckpointInvalidateStream(int param_1)

{
  if ((*DAT_30018988 & 0x8000) != 0) {
    printf(DAT_300189c4,*(undefined4 *)(param_1 + 0x100));
  }
  FUN_30017ee4(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300189c8 @ 0x300189C8  (примерный размер ~68 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: yaffs_ECCCorrect, yaffs_ECCCorrectOther
 * Константы: 0x300189C8
 * ---------------------------------------------------------------- */
int FUN_300189c8(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; (param_1 & 0xff) != 0; param_1 = (param_1 & 0xff) >> 1) {
    iVar1 = iVar1 + (uint)((param_1 & 1) != 0);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30018a0c @ 0x30018A0C  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_ECCCorrectOther
 * Константы: 0x30018A0C
 * ---------------------------------------------------------------- */
int FUN_30018a0c(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_1 != 0; param_1 = param_1 >> 1) {
    iVar1 = iVar1 + (param_1 & 1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * yaffs_ECCCalculate @ 0x30018A3C  (примерный размер ~348 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_CalcECC
 * Константы: 0x30018A3C
 * Данные: DAT_30018f4c
 * ---------------------------------------------------------------- */
void yaffs_ECCCalculate(byte *param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  
  bVar3 = 0;
  uVar2 = 0;
  uVar1 = 0;
  for (uVar4 = 0; uVar4 < 0x100; uVar4 = uVar4 + 1) {
    bVar3 = bVar3 ^ *(byte *)(DAT_30018f4c + (uint)*param_1);
    if ((*(byte *)(DAT_30018f4c + (uint)*param_1) & 1) != 0) {
      uVar2 = uVar2 ^ uVar4;
      uVar1 = uVar1 ^ ~uVar4;
    }
    param_1 = param_1 + 1;
  }
  param_2[2] = ~bVar3 | 3;
  bVar3 = 0;
  if ((uVar2 & 0x80) != 0) {
    bVar3 = 0x80;
  }
  if ((uVar1 & 0x80) != 0) {
    bVar3 = bVar3 | 0x40;
  }
  if ((uVar2 & 0x40) != 0) {
    bVar3 = bVar3 | 0x20;
  }
  if ((uVar1 & 0x40) != 0) {
    bVar3 = bVar3 | 0x10;
  }
  if ((uVar2 & 0x20) != 0) {
    bVar3 = bVar3 | 8;
  }
  if ((uVar1 & 0x20) != 0) {
    bVar3 = bVar3 | 4;
  }
  if ((uVar2 & 0x10) != 0) {
    bVar3 = bVar3 | 2;
  }
  param_2[1] = ~(bVar3 | (uVar1 & 0x10) != 0);
  bVar3 = 0;
  if ((uVar2 & 8) != 0) {
    bVar3 = 0x80;
  }
  if ((uVar1 & 8) != 0) {
    bVar3 = bVar3 | 0x40;
  }
  if ((uVar2 & 4) != 0) {
    bVar3 = bVar3 | 0x20;
  }
  if ((uVar1 & 4) != 0) {
    bVar3 = bVar3 | 0x10;
  }
  if ((uVar2 & 2) != 0) {
    bVar3 = bVar3 | 8;
  }
  if ((uVar1 & 2) != 0) {
    bVar3 = bVar3 | 4;
  }
  if ((uVar2 & 1) != 0) {
    bVar3 = bVar3 | 2;
  }
  *param_2 = ~(bVar3 | (uVar1 & 1) != 0);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_ECCCorrect @ 0x30018B98  (примерный размер ~464 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_300189c8
 * Константы: 0x30018B98, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 yaffs_ECCCorrect(int param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  
  bVar1 = *param_2 ^ *param_3;
  uVar9 = (uint)bVar1;
  bVar2 = param_2[1] ^ param_3[1];
  uVar8 = (uint)bVar2;
  bVar3 = param_2[2] ^ param_3[2];
  uVar11 = (uint)bVar3;
  if ((bVar3 == 0 && bVar1 == 0) && bVar2 == 0) {
    uVar4 = 0;
  }
  else if (((((uVar9 ^ (int)uVar9 >> 1) & 0x55) == 0x55) &&
           (((uVar8 ^ (int)uVar8 >> 1) & 0x55) == 0x55)) &&
          (((uVar11 ^ (int)uVar11 >> 1) & 0x54) == 0x54)) {
    uVar9 = 0;
    uVar8 = 0;
    if ((bVar2 & 0x80) != 0) {
      uVar9 = 0x80;
    }
    if ((bVar2 & 0x20) != 0) {
      uVar9 = uVar9 | 0x40;
    }
    if ((bVar2 & 8) != 0) {
      uVar9 = uVar9 | 0x20;
    }
    if ((bVar2 & 2) != 0) {
      uVar9 = uVar9 | 0x10;
    }
    if ((bVar1 & 0x80) != 0) {
      uVar9 = uVar9 | 8;
    }
    if ((bVar1 & 0x20) != 0) {
      uVar9 = uVar9 | 4;
    }
    if ((bVar1 & 8) != 0) {
      uVar9 = uVar9 | 2;
    }
    if ((bVar3 & 0x80) != 0) {
      uVar8 = 4;
    }
    if ((bVar3 & 0x20) != 0) {
      uVar8 = uVar8 | 2;
    }
    pbVar10 = (byte *)(param_1 + (uVar9 | (bVar1 & 2) != 0));
    *pbVar10 = *pbVar10 ^ (byte)(1 << (uVar8 | (bVar3 & 8) != 0));
    uVar4 = 1;
  }
  else {
    iVar5 = FUN_300189c8(uVar8);
    iVar6 = FUN_300189c8(uVar11);
    iVar7 = FUN_300189c8(uVar9);
    if (iVar7 + iVar5 + iVar6 == 1) {
      *param_2 = *param_3;
      param_2[1] = param_3[1];
      param_2[2] = param_3[2];
      uVar4 = 1;
    }
    else {
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * yaffs_ECCCalculateOther @ 0x30018D68  (примерный размер ~128 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: yaffs_PackTags2, yaffs_UnpackTags2
 * Константы: 0x30018D68
 * Данные: DAT_30018f4c
 * ---------------------------------------------------------------- */
void yaffs_ECCCalculateOther(byte *param_1,uint param_2,undefined1 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar2 = 0;
  uVar1 = 0;
  for (uVar4 = 0; uVar4 < param_2; uVar4 = uVar4 + 1) {
    uVar3 = uVar3 ^ *(byte *)(DAT_30018f4c + (uint)*param_1);
    if ((*(byte *)(DAT_30018f4c + (uint)*param_1) & 1) != 0) {
      uVar2 = uVar2 ^ uVar4;
      uVar1 = uVar1 ^ ~uVar4;
    }
    param_1 = param_1 + 1;
  }
  *param_3 = (char)(uVar3 >> 2);
  *(uint *)(param_3 + 4) = uVar2;
  *(uint *)(param_3 + 8) = uVar1;
  return;
}

/* ----------------------------------------------------------------
 * yaffs_ECCCorrectOther @ 0x30018DE8  (примерный размер ~360 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300189c8, FUN_30018a0c
 * Вызывают: yaffs_UnpackTags2
 * Константы: 0xFFFFFFFF, 0x30018DE8
 * ---------------------------------------------------------------- */
undefined4 yaffs_ECCCorrectOther(int param_1,uint param_2,byte *param_3,byte *param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  bVar1 = *param_3 ^ *param_4;
  uVar6 = (uint)bVar1;
  uVar8 = *(uint *)(param_3 + 4) ^ *(uint *)(param_4 + 4);
  uVar7 = *(uint *)(param_3 + 8) ^ *(uint *)(param_4 + 8);
  if ((uVar7 == 0 && uVar8 == 0) && uVar6 == 0) {
    uVar2 = 0;
  }
  else if ((~uVar7 == uVar8) && (((uVar6 ^ (int)uVar6 >> 1) & 0x15) == 0x15)) {
    uVar6 = 0;
    if ((bVar1 & 0x20) != 0) {
      uVar6 = 4;
    }
    if ((bVar1 & 8) != 0) {
      uVar6 = uVar6 | 2;
    }
    if (uVar8 < param_2) {
      *(byte *)(param_1 + uVar8) =
           *(byte *)(param_1 + uVar8) ^ (byte)(1 << (uVar6 | (bVar1 & 2) != 0));
      uVar2 = 1;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    iVar3 = FUN_30018a0c(uVar7);
    iVar4 = FUN_300189c8(uVar6);
    iVar5 = FUN_30018a0c(uVar8);
    if (iVar5 + iVar3 + iVar4 == 1) {
      uVar2 = *(undefined4 *)(param_4 + 4);
      *(undefined4 *)param_3 = *(undefined4 *)param_4;
      *(undefined4 *)(param_3 + 4) = uVar2;
      *(undefined4 *)(param_3 + 8) = *(undefined4 *)(param_4 + 8);
      uVar2 = 1;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30018f50 @ 0x30018F50  (примерный размер ~40 байт)
 * Модуль: flash | Вызывают: 6 | Вызывает: 0
 * Вызывают: FUN_3001cf58, FUN_3001d17c, FUN_3001df80, FUN_3001e034, yaffs_AddObjectToDirectory, yaffs_HardlinkFixup
 * Константы: 0x30018F50
 * ---------------------------------------------------------------- */
void FUN_30018f50(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *param_2 = (int)param_1;
  param_1[1] = (int)param_2;
  *param_1 = iVar1;
  *(int **)(iVar1 + 4) = param_1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30018f78 @ 0x30018F78  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30018f98
 * Константы: 0x30018F78
 * ---------------------------------------------------------------- */
void FUN_30018f78(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1;
  piVar1 = (int *)param_1[1];
  *(int **)(iVar2 + 4) = piVar1;
  *piVar1 = iVar2;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30018f98 @ 0x30018F98  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 1
 * Вызывает: FUN_30018f78
 * Вызывают: FUN_3001aba4, FUN_3001c51c, FUN_3001de4c, FUN_3001e3e4, yaffs_UpdateDirtyDirectories
 * Константы: 0x30018F98
 * ---------------------------------------------------------------- */
void FUN_30018f98(undefined4 *param_1)

{
  FUN_30018f78(param_1);
  param_1[1] = param_1;
  *param_1 = param_1[1];
  return;
}

/* ----------------------------------------------------------------
 * FUN_30018fb8 @ 0x30018FB8  (примерный размер ~128 байт)
 * Модуль: flash | Вызывают: 11 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: FUN_300197f0, FUN_30019d80, FUN_30019e10, FUN_30019f80, FUN_3001a9e0, FUN_3001b01c, FUN_3001b670, yaffs_BlockBecameDirty, yaffs_DeleteChunk, yaffs_SkipRestOfBlock
 *           ...
 * Константы: 0x30018FB8
 * Данные: DAT_30019f98, DAT_30019f9c
 * ---------------------------------------------------------------- */
int FUN_30018fb8(int param_1,int param_2)

{
  if ((param_2 < *(int *)(param_1 + 0xdc)) || (*(int *)(param_1 + 0xe0) < param_2)) {
    printf(DAT_30019f98,param_2);
    printf(DAT_30019f9c,0x1e);
  }
  return *(int *)(param_1 + 0x124) + (param_2 - *(int *)(param_1 + 0xdc)) * 8;
}

/* ----------------------------------------------------------------
 * yaffs_AddrToChunk @ 0x30019038  (примерный размер ~268 байт)
 * Модуль: flash | Вызывают: 4 | Вызывает: 3
 * Вызывает: __asr64, __mul64, __udiv32
 * Вызывают: yaffsGetFileSavings, yaffs_DoWriteDataToFile, yaffs_ReadDataFromFile, yaffs_ResizeDown
 * Константы: 0x30019038
 * ---------------------------------------------------------------- */
void yaffs_AddrToChunk(int param_1,uint param_2,undefined4 param_3,int *param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __asr64(param_2,param_3,*(undefined4 *)(param_1 + 0xb4));
  if (*(int *)(param_1 + 0xb8) == 1) {
    param_2 = param_2 & *(uint *)(param_1 + 0xbc);
  }
  else {
    iVar1 = __udiv32(iVar1,*(undefined4 *)(param_1 + 0xb8));
    iVar2 = __mul64(iVar1,iVar1 >> 0x1f,*(int *)(param_1 + 0x9c),*(int *)(param_1 + 0x9c) >> 0x1f);
    param_2 = param_2 - iVar2;
  }
  *param_4 = iVar1;
  *param_5 = param_2;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30019144 @ 0x30019144  (примерный размер ~76 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x30019144
 * ---------------------------------------------------------------- */
int FUN_30019144(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  for (; 1 < param_1; param_1 = param_1 >> 1) {
    iVar2 = iVar2 + (param_1 & 1);
    iVar1 = iVar1 + 1;
  }
  return iVar1 + (uint)(iVar2 != 0);
}

/* ----------------------------------------------------------------
 * FUN_30019190 @ 0x30019190  (примерный размер ~60 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x30019190
 * ---------------------------------------------------------------- */
int FUN_30019190(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    for (; (param_1 & 1) == 0; param_1 = param_1 >> 1) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300191cc @ 0x300191CC  (примерный размер ~128 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: malloc, memset
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x300191CC
 * Данные: DAT_3001a0d4
 * ---------------------------------------------------------------- */
bool FUN_300191cc(int param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = (void *)0x1;
  memset((void *)(param_1 + DAT_3001a0d4),0,0x48);
  for (iVar2 = 0; (pvVar1 != (void *)0x0 && (iVar2 < 6)); iVar2 = iVar2 + 1) {
    *(undefined4 *)(param_1 + iVar2 * 0xc + 0xdbc) = 0;
    pvVar1 = malloc(*(size_t *)(param_1 + 8));
    *(void **)(param_1 + iVar2 * 0xc + 0xdb8) = pvVar1;
  }
  return pvVar1 != (void *)0x0;
}

/* ----------------------------------------------------------------
 * yaffs_GetTempBuffer @ 0x3001924C  (примерный размер ~356 байт)
 * Модуль: flash | Вызывают: 16 | Вызывает: 2
 * Вызывает: malloc, printf
 * Вызывают: FUN_300195b0, FUN_30019658, FUN_300197f0, FUN_3001b01c, FUN_3001beac, yaffs1_Scan, yaffs2_HandleHole, yaffs2_ScanBackwards, yaffs_DoWriteDataToFile, yaffs_GetObjectName
 *           ...
 * Константы: 0x3001924C
 * Данные: DAT_30019f94, DAT_3001a2cc, DAT_3001a2d0, DAT_3001a2d4
 * ---------------------------------------------------------------- */
void * yaffs_GetTempBuffer(int param_1,undefined4 param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  *(int *)(param_1 + 0xe04) = *(int *)(param_1 + 0xe04) + 1;
  if (*(int *)(param_1 + 0xe00) < *(int *)(param_1 + 0xe04)) {
    *(undefined4 *)(param_1 + 0xe00) = *(undefined4 *)(param_1 + 0xe04);
  }
  iVar3 = 0;
  while( true ) {
    if (5 < iVar3) {
      if ((*DAT_30019f94 & 0x400) != 0) {
        printf(DAT_3001a2cc,param_2);
      }
      for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
        if ((*DAT_30019f94 & 0x400) != 0) {
          printf(DAT_3001a2d0,*(undefined4 *)(param_1 + iVar3 * 0xc + 0xdbc));
        }
      }
      if ((*DAT_30019f94 & 0x400) != 0) {
        printf(DAT_3001a2d4);
      }
      *(int *)(param_1 + 0xe08) = *(int *)(param_1 + 0xe08) + 1;
      pvVar1 = malloc(*(size_t *)(param_1 + 0x9c));
      return pvVar1;
    }
    if (*(int *)(param_1 + iVar3 * 0xc + 0xdbc) == 0) break;
    iVar3 = iVar3 + 1;
  }
  *(undefined4 *)(param_1 + iVar3 * 0xc + 0xdbc) = param_2;
  if (*(int *)(param_1 + 0xe00) < iVar3 + 1) {
    *(int *)(param_1 + 0xe00) = iVar3 + 1;
    for (iVar2 = 0; iVar2 <= iVar3; iVar2 = iVar2 + 1) {
      *(undefined4 *)(param_1 + iVar2 * 0xc + 0xdc0) =
           *(undefined4 *)(param_1 + iVar2 * 0xc + 0xdbc);
    }
  }
  return *(void **)(param_1 + iVar3 * 0xc + 0xdb8);
}

/* ----------------------------------------------------------------
 * yaffs_ReleaseTempBuffer @ 0x300193B0  (примерный размер ~160 байт)
 * Модуль: flash | Вызывают: 16 | Вызывает: 2
 * Вызывает: free, printf
 * Вызывают: FUN_300195b0, FUN_30019658, FUN_300197f0, FUN_3001b01c, FUN_3001beac, yaffs1_Scan, yaffs2_HandleHole, yaffs2_ScanBackwards, yaffs_DoWriteDataToFile, yaffs_GetObjectName
 *           ...
 * Константы: 0x300193B0
 * Данные: DAT_30019f94, DAT_3001a2d8
 * ---------------------------------------------------------------- */
void yaffs_ReleaseTempBuffer(int param_1,void *param_2,undefined4 param_3)

{
  int iVar1;
  
  *(int *)(param_1 + 0xe04) = *(int *)(param_1 + 0xe04) + -1;
  iVar1 = 0;
  while( true ) {
    if (5 < iVar1) {
      if (param_2 != (void *)0x0) {
        if ((*DAT_30019f94 & 0x400) != 0) {
          printf(DAT_3001a2d8,param_3);
        }
        free(param_2);
        *(int *)(param_1 + 0xe0c) = *(int *)(param_1 + 0xe0c) + 1;
      }
      return;
    }
    if (*(void **)(param_1 + iVar1 * 0xc + 0xdb8) == param_2) break;
    iVar1 = iVar1 + 1;
  }
  *(undefined4 *)(param_1 + iVar1 * 0xc + 0xdbc) = 0;
  return;
}

/* ----------------------------------------------------------------
 * yaffs_IsManagedTempBuffer @ 0x30019450  (примерный размер ~196 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x30019450
 * Данные: DAT_3001a480
 * ---------------------------------------------------------------- */
bool yaffs_IsManagedTempBuffer(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
    if (*(int *)(param_1 + iVar1 * 0xc + 0xdb8) == param_2) {
      return true;
    }
  }
  iVar1 = 0;
  while( true ) {
    if (*(int *)(param_1 + 0x20) <= iVar1) {
      bVar2 = *(int *)(param_1 + 0xf8) != param_2;
      if (bVar2) {
        printf(DAT_3001a480);
      }
      return !bVar2;
    }
    if (*(int *)(*(int *)(param_1 + 0xd98) + iVar1 * 0x1c + 0x18) == param_2) break;
    iVar1 = iVar1 + 1;
  }
  return true;
}

/* ----------------------------------------------------------------
 * FUN_30019514 @ 0x30019514  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 1
 * Вызывает: abs
 * Вызывают: FUN_3001aba4, FUN_3001d17c, yaffs_FindObjectByNumber
 * Константы: 0x30019514
 * ---------------------------------------------------------------- */
uint FUN_30019514(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = abs(param_1);
  uVar2 = uVar1 & 0xff;
  if ((int)uVar1 < 0) {
    uVar2 = -(-uVar1 & 0xff);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_Root @ 0x30019544  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30019544
 * ---------------------------------------------------------------- */
undefined4 yaffs_Root(int param_1)

{
  return *(undefined4 *)(param_1 + 0xd88);
}

/* ----------------------------------------------------------------
 * yaffs_LostNFound @ 0x30019558  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30019558
 * ---------------------------------------------------------------- */
undefined4 yaffs_LostNFound(int param_1)

{
  return *(undefined4 *)(param_1 + 0xd8c);
}

/* ----------------------------------------------------------------
 * yaffs_CheckFF @ 0x3001956C  (примерный размер ~68 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300195b0
 * Константы: 0x3001956C
 * ---------------------------------------------------------------- */
undefined4 yaffs_CheckFF(char *param_1,int param_2)

{
  while( true ) {
    if (param_2 == 0) {
      return 1;
    }
    param_2 = param_2 + -1;
    if (*param_1 != -1) break;
    param_1 = param_1 + 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300195b0 @ 0x300195B0  (примерный размер ~168 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 5
 * Вызывает: printf, yaffs_CheckFF, yaffs_GetTempBuffer, yaffs_ReadChunkWithTagsFromNAND, yaffs_ReleaseTempBuffer
 * Вызывают: FUN_3001a0fc, yaffs_BlockBecameDirty
 * Константы: 0x300195B0
 * Данные: DAT_30019f94, DAT_3001a484, DAT_3001a5ac, DAT_3001a5b0
 * ---------------------------------------------------------------- */
bool FUN_300195b0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  undefined1 auStack_60 [4];
  int local_5c;
  int local_4c;
  
  uVar1 = yaffs_GetTempBuffer(param_1,DAT_3001a484);
  yaffs_ReadChunkWithTagsFromNAND(param_1,param_2,uVar1,auStack_60);
  bVar3 = local_4c < 2;
  iVar2 = yaffs_CheckFF(uVar1,*(undefined4 *)(param_1 + 0x9c));
  if ((iVar2 == 0) || (local_5c != 0)) {
    if ((*DAT_30019f94 & 0x800) != 0) {
      printf(DAT_3001a5ac,param_2);
    }
    bVar3 = false;
  }
  yaffs_ReleaseTempBuffer(param_1,uVar1,DAT_3001a5b0);
  return bVar3;
}

/* ----------------------------------------------------------------
 * FUN_30019658 @ 0x30019658  (примерный размер ~172 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: memcmp, yaffs_GetTempBuffer, yaffs_ReadChunkWithTagsFromNAND, yaffs_ReleaseTempBuffer
 * Вызывают: FUN_3001a0fc
 * Константы: 0x30019658
 * Данные: DAT_3001a5b4, DAT_3001a5b8
 * ---------------------------------------------------------------- */
undefined4 FUN_30019658(int param_1,undefined4 param_2,void *param_3,int param_4)

{
  void *__s1;
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [8];
  int local_60;
  int local_5c;
  int local_58;
  
  uVar2 = 1;
  __s1 = (void *)yaffs_GetTempBuffer(param_1,DAT_3001a5b4);
  yaffs_ReadChunkWithTagsFromNAND(param_1,param_2,__s1,auStack_68);
  iVar1 = memcmp(__s1,param_3,*(size_t *)(param_1 + 0x9c));
  if ((((iVar1 != 0) || (local_60 != *(int *)(param_4 + 8))) ||
      (local_5c != *(int *)(param_4 + 0xc))) || (local_58 != *(int *)(param_4 + 0x10))) {
    uVar2 = 0;
  }
  yaffs_ReleaseTempBuffer(param_1,__s1,DAT_3001a5b8);
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30019704 @ 0x30019704  (примерный размер ~4 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3001a0fc
 * Константы: 0x30019704
 * ---------------------------------------------------------------- */
void FUN_30019704(void)

{
  return;
}

/* ----------------------------------------------------------------
 * yaffs_HandleChunkError @ 0x30019708  (примерный размер ~148 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: FUN_30019d80, yaffs_ReadChunkWithTagsFromNAND
 * Константы: 0x04000000, 0x30019708, 0xC7FFFFFF, 0x01000000
 * Данные: DAT_3001a664
 * ---------------------------------------------------------------- */
void yaffs_HandleChunkError(int param_1,uint *param_2)

{
  if ((*param_2 & 0x4000000) == 0) {
    *param_2 = *param_2 | 0x4000000;
    *(undefined4 *)(param_1 + 0xd64) = 1;
    *param_2 = *param_2 & 0xc7ffffff | ((*param_2 >> 0x1b & 7) + 1 & 7) << 0x1b;
    if (3 < (*param_2 >> 0x1b & 7)) {
      *param_2 = *param_2 | 0x1000000;
      printf(DAT_3001a664);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_SkipRestOfBlock @ 0x3001979C  (примерный размер ~84 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 1
 * Вызывает: FUN_30018fb8
 * Вызывают: FUN_30019d80, FUN_3001a0fc, yaffs2_ScanBackwards
 * Константы: 0x3001979C, 0xFF0FFFFF, 0x00500000, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void yaffs_SkipRestOfBlock(int param_1)

{
  uint *puVar1;
  
  if ((0 < *(int *)(param_1 + 0x138)) &&
     (puVar1 = (uint *)FUN_30018fb8(param_1,*(undefined4 *)(param_1 + 0x138)),
     (*puVar1 >> 0x14 & 0xf) == 4)) {
    *puVar1 = *puVar1 & 0xff0fffff | 0x500000;
    *(undefined4 *)(param_1 + 0x138) = 0xffffffff;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300197f0 @ 0x300197F0  (примерный размер ~292 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 10
 * Вызывает: FUN_30018fb8, memset, printf, yaffs2_ClearOldestDirtySequence, yaffs2_InvalidateCheckpoint, yaffs_EraseBlockInNAND, yaffs_GetTempBuffer, yaffs_InitialiseTags, yaffs_MarkBlockBad, yaffs_ReleaseTempBuffer
 * Вызывают: yaffs_BlockBecameDirty
 * Константы: 0x300197F0, 0xFA0FFFFF, 0x00900000
 * Данные: DAT_3001a75c, DAT_3001a760, DAT_3001a764, DAT_3001a768
 * ---------------------------------------------------------------- */
void FUN_300197f0(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  void *__s;
  undefined1 auStack_60 [36];
  undefined4 local_3c;
  
  puVar1 = (uint *)FUN_30018fb8(param_1,param_2);
  yaffs2_InvalidateCheckpoint(param_1);
  yaffs2_ClearOldestDirtySequence(param_1,puVar1);
  iVar2 = yaffs_MarkBlockBad(param_1,param_2);
  if (iVar2 != 1) {
    iVar2 = yaffs_EraseBlockInNAND(param_1,param_2);
    if (iVar2 == 1) {
      iVar2 = *(int *)(param_1 + 0xc);
      __s = (void *)yaffs_GetTempBuffer(param_1,DAT_3001a760);
      memset(__s,0xff,*(size_t *)(param_1 + 0x9c));
      yaffs_InitialiseTags(auStack_60);
      local_3c = DAT_3001a764;
      iVar2 = (**(code **)(param_1 + 0x54))
                        (param_1,iVar2 * param_2 - *(int *)(param_1 + 0xe8),__s,auStack_60);
      if (iVar2 != 1) {
        yaffs_ReleaseTempBuffer(param_1,__s,DAT_3001a768);
      }
    }
    else {
      printf(DAT_3001a75c,param_2);
    }
  }
  *puVar1 = *puVar1 & 0xfa0fffff | 0x900000;
  *(int *)(param_1 + 0xe54) = *(int *)(param_1 + 0xe54) + 1;
  return;
}

/* ----------------------------------------------------------------
 * yaffs_BlockBecameDirty @ 0x30019914  (примерный размер ~580 байт)
 * Модуль: flash | Вызывают: 4 | Вызывает: 9
 * Вызывает: FUN_30018fb8, FUN_300195b0, FUN_300197f0, printf, yaffs2_ClearOldestDirtySequence, yaffs2_InvalidateCheckpoint, yaffs_ClearChunkBits, yaffs_EraseBlockInNAND, yaffs_SkipVerification
 * Вызывают: FUN_3001b01c, yaffs1_Scan, yaffs2_ScanBackwards, yaffs_DeleteChunk
 * Константы: 0x01000000, 0xFF0FFFFF, 0x30019914, 0x00600000, 0x00300000, 0xFBFFFFFF, 0x02000000
 * Данные: DAT_30019f94, DAT_3001a858, DAT_3001a85c, DAT_3001a860, DAT_3001a8f0, DAT_3001a8f4, DAT_3001a9c0, DAT_3001a9c4
 * ---------------------------------------------------------------- */
void yaffs_BlockBecameDirty(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  puVar1 = (uint *)FUN_30018fb8(param_1,param_2);
  iVar4 = 0;
  if ((*DAT_30019f94 & 0x60) != 0) {
    uVar5 = DAT_3001a85c;
    if ((*puVar1 & 0x1000000) != 0) {
      uVar5 = DAT_3001a858;
    }
    printf(DAT_3001a860,param_2,*puVar1 >> 0x14 & 0xf,uVar5);
  }
  yaffs2_ClearOldestDirtySequence(param_1,puVar1);
  *puVar1 = *puVar1 & 0xff0fffff | 0x600000;
  if (*(int *)(param_1 + 0xd7c) == param_2) {
    *(undefined4 *)(param_1 + 0xd7c) = 0;
  }
  if (*(int *)(param_1 + 0xd70) == param_2) {
    *(undefined4 *)(param_1 + 0xd70) = 0;
    *(undefined4 *)(param_1 + 0xd74) = 0;
  }
  if ((*puVar1 & 0x1000000) == 0) {
    yaffs2_InvalidateCheckpoint(param_1);
    iVar4 = yaffs_EraseBlockInNAND(param_1,param_2);
    if (iVar4 == 0) {
      *(int *)(param_1 + 0xe34) = *(int *)(param_1 + 0xe34) + 1;
      printf(DAT_3001a8f0,param_2);
    }
  }
  if ((iVar4 != 0) &&
     (((*DAT_30019f94 & 0x20) != 0 || (iVar2 = yaffs_SkipVerification(param_1), iVar2 == 0)))) {
    for (iVar2 = 0; iVar2 < *(int *)(param_1 + 0xc); iVar2 = iVar2 + 1) {
      iVar3 = FUN_300195b0(param_1,param_2 * *(int *)(param_1 + 0xc) + iVar2);
      if (iVar3 == 0) {
        printf(DAT_3001a8f4,param_2,iVar2);
      }
    }
  }
  if (iVar4 == 0) {
    *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) - *(int *)(param_1 + 0xc);
    FUN_300197f0(param_1,param_2);
    printf(DAT_3001a9c8,param_2);
  }
  else {
    *puVar1 = *puVar1 & 0xff0fffff | 0x300000;
    puVar1[1] = 0;
    *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
    *puVar1 = *puVar1 & DAT_3001a9c0 & 0xfbffffff | 0x2000000;
    yaffs_ClearChunkBits(param_1,param_2);
    if ((*DAT_30019f94 & 0x20) != 0) {
      printf(DAT_3001a9c4,param_2);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_DeleteChunk @ 0x30019B58  (примерный размер ~552 байт)
 * Модуль: flash | Вызывают: 10 | Вызывает: 10
 * Вызывает: FUN_30018fb8, FUN_30020c78, __div32, printf, yaffs2_UpdateOldestDirtySequence, yaffs_BlockBecameDirty, yaffs_CheckChunkBit, yaffs_ClearChunkBit, yaffs_InitialiseTags, yaffs_WriteChunkWithTagsToNAND
 * Вызывают: FUN_30019d80, FUN_3001a0fc, FUN_3001b01c, FUN_3001cc70, FUN_3001d45c, FUN_3001d854, yaffs1_Scan, yaffs2_ScanBackwards, yaffs_PutChunkIntoFile, yaffs_UpdateObjectHeader
 * Константы: 0x30019B58, 0x40000000
 * Данные: DAT_30019f94, DAT_3001ab08, DAT_3001ab0c, DAT_3001ac34, DAT_3001ac38
 * ---------------------------------------------------------------- */
void yaffs_DeleteChunk(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined1 auStack_6c [28];
  undefined4 local_50;
  
  if (0 < param_2) {
    *(int *)(param_1 + 0xe68) = *(int *)(param_1 + 0xe68) + 1;
    uVar1 = __div32(param_2,*(undefined4 *)(param_1 + 0xc));
    iVar2 = __div32(param_2,*(undefined4 *)(param_1 + 0xc));
    iVar4 = param_2 - *(int *)(param_1 + 0xc) * iVar2;
    iVar2 = yaffs_CheckChunkBit(param_1,uVar1,iVar4);
    if ((iVar2 == 0) && ((*DAT_30019f94 & 0x10000) != 0)) {
      printf(DAT_3001ab08,param_2);
    }
    puVar3 = (uint *)FUN_30018fb8(param_1,uVar1);
    yaffs2_UpdateOldestDirtySequence(param_1,uVar1,puVar3);
    if ((*DAT_30019f94 & 0x200) != 0) {
      printf(DAT_3001ab0c,param_4,param_2);
    }
    if (((*(int *)(param_1 + 0x2c) == 0) && (param_3 != 0)) && ((*puVar3 >> 0x14 & 0xf) != 8)) {
      yaffs_InitialiseTags(auStack_6c);
      local_50 = 1;
      yaffs_WriteChunkWithTagsToNAND(param_1,param_2,0,auStack_6c);
      FUN_30020c78(param_1,param_2,auStack_6c);
    }
    else {
      *(int *)(param_1 + 0xe6c) = *(int *)(param_1 + 0xe6c) + 1;
    }
    if ((((*puVar3 >> 0x14 & 0xf) == 4) || ((*puVar3 >> 0x14 & 0xf) == 5)) ||
       (((*puVar3 >> 0x14 & 0xf) == 2 || ((*puVar3 >> 0x14 & 0xf) == 8)))) {
      *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) + 1;
      yaffs_ClearChunkBit(param_1,uVar1,iVar4);
      *puVar3 = *puVar3 & DAT_3001ac34 | (((*puVar3 << 0xc) >> 0x16) - 1 & DAT_3001ac38) << 10;
      if ((((*puVar3 << 0xc) >> 0x16 == 0) && ((*puVar3 & 0x40000000) == 0)) &&
         (((*puVar3 >> 0x14 & 0xf) != 4 && ((*puVar3 >> 0x14 & 0xf) != 2)))) {
        yaffs_BlockBecameDirty(param_1,uVar1);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30019d80 @ 0x30019D80  (примерный размер ~144 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_30018fb8, __div32, printf, yaffs_DeleteChunk, yaffs_HandleChunkError, yaffs_SkipRestOfBlock
 * Вызывают: FUN_3001a0fc
 * Константы: 0x30019D80, 0x01000000
 * Данные: DAT_3001ac3c, DAT_3001ac40
 * ---------------------------------------------------------------- */
void FUN_30019d80(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  
  uVar1 = __div32(param_2,*(undefined4 *)(param_1 + 0xc));
  puVar2 = (uint *)FUN_30018fb8(param_1,uVar1);
  yaffs_HandleChunkError(param_1,puVar2);
  if (param_3 != 0) {
    *puVar2 = *puVar2 | 0x1000000;
    printf(DAT_3001ac3c,uVar1);
  }
  yaffs_DeleteChunk(param_1,param_2,1,DAT_3001ac40);
  yaffs_SkipRestOfBlock(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30019e10 @ 0x30019E10  (примерный размер ~304 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30018fb8, printf
 * Вызывают: FUN_30019f80
 * Константы: 0x30019E10, 0xFF0FFFFF, 0x00400000, 0xFFFFFFFF
 * Данные: DAT_30019f94, DAT_3001ad40, DAT_3001ad44, DAT_3001ae40
 * ---------------------------------------------------------------- */
undefined4 FUN_30019e10(int param_1)

{
  uint *puVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x134) < 1) {
    printf(DAT_3001ad40);
  }
  else {
    for (iVar2 = *(int *)(param_1 + 0xdc); iVar2 <= *(int *)(param_1 + 0xe0); iVar2 = iVar2 + 1) {
      *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + 1;
      if ((*(int *)(param_1 + 0x140) < *(int *)(param_1 + 0xdc)) ||
         (*(int *)(param_1 + 0xe0) < *(int *)(param_1 + 0x140))) {
        *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(param_1 + 0xdc);
      }
      puVar1 = (uint *)FUN_30018fb8(param_1,*(undefined4 *)(param_1 + 0x140));
      if ((*puVar1 >> 0x14 & 0xf) == 3) {
        *puVar1 = *puVar1 & 0xff0fffff | 0x400000;
        *(int *)(param_1 + 0xe10) = *(int *)(param_1 + 0xe10) + 1;
        puVar1[1] = *(uint *)(param_1 + 0xe10);
        *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + -1;
        if ((*DAT_30019f94 & 4) != 0) {
          printf(DAT_3001ad44,*(undefined4 *)(param_1 + 0x140),*(undefined4 *)(param_1 + 0xe10),
                 *(undefined4 *)(param_1 + 0x134));
        }
        return *(undefined4 *)(param_1 + 0x140);
      }
    }
    printf(DAT_3001ae40,*(undefined4 *)(param_1 + 0x134));
  }
  return 0xffffffff;
}

