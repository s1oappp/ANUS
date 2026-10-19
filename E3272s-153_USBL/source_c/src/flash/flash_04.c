/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : flash — флеш-подсистема: NAND-контроллер, ptable, YAFFS/YAFFS2, NV-память (NVM/nvim)
 * Часть  : 4 (функций: 105, адреса 0x3002BB10..0x3009FB10)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * ptable_set_integrality @ 0x3002BB10  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 2
 * Вызывает: printf, ptable_get_ram_head
 * Вызывают: FUN_3002cd64, dloadBootromEnd, dloadFromFsMainThread
 * Константы: 0x3002BB10, 0xFFFFFFFE
 * Данные: DAT_3002c488, DAT_3002c48c
 * ---------------------------------------------------------------- */
void ptable_set_integrality(uint param_1)

{
  int iVar1;
  
  iVar1 = ptable_get_ram_head();
  if (((*DAT_3002c488 & 0x800) != 0) && (-1 < (int)*DAT_3002c488)) {
    printf(DAT_3002c48c,param_1);
  }
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffffffe | param_1 & 1;
  return;
}

/* ----------------------------------------------------------------
 * ptable_find_by_name @ 0x3002BB68  (примерный размер ~116 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 1
 * Вызывает: strcmp
 * Вызывают: FUN_3002c4d0, ptable_erase_partition, ptable_quary_partition
 * Константы: 0x3002BB68
 * Данные: DAT_3002c46c
 * ---------------------------------------------------------------- */
char * ptable_find_by_name(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = (char *)0x0;
  if (param_2 != (char *)0x0) {
    while (iVar1 = strcmp(DAT_3002c46c,param_2), iVar1 != 0) {
      iVar1 = strcmp(param_1,param_2);
      pcVar3 = pcVar2;
      if (((iVar1 == 0) && (pcVar3 = param_2, pcVar2 != (char *)0x0)) &&
         (pcVar3 = pcVar2, *(uint *)(pcVar2 + 0x2c) < *(uint *)(param_2 + 0x2c))) {
        pcVar3 = param_2;
      }
      param_2 = param_2 + 0x30;
      pcVar2 = pcVar3;
    }
  }
  return pcVar2;
}

/* ----------------------------------------------------------------
 * ptable_read_by_type @ 0x3002BBDC  (примерный размер ~280 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 3
 * Вызывает: nand_read, nand_read_oob, printf
 * Вызывают: FUN_3002cb08, ptable_dload_read, ptable_get_cdromiso_version
 * Константы: 0x3002BBDC
 * Данные: DAT_3002c488, DAT_3002c490, DAT_3002c494, DAT_3002c498
 * ---------------------------------------------------------------- */
undefined4
ptable_read_by_type(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                   undefined4 param_5)

{
  int iVar1;
  
  if (param_3 == 0) {
    iVar1 = nand_read(param_1,param_2,param_4,param_5);
    if (iVar1 == 0) {
      return 0;
    }
    if (((*DAT_3002c488 & 0x800) != 0) && (-1 < (int)*DAT_3002c488)) {
      printf(DAT_3002c490);
    }
  }
  else if (param_3 == 1) {
    iVar1 = nand_read_oob(param_1,param_2,param_4,0x10,param_5);
    if (iVar1 == 0) {
      return 0;
    }
    if (((*DAT_3002c488 & 0x800) != 0) && (-1 < (int)*DAT_3002c488)) {
      printf(DAT_3002c494);
    }
  }
  else if (((*DAT_3002c488 & 0x800) != 0) && (-1 < (int)*DAT_3002c488)) {
    printf(DAT_3002c498,param_3);
  }
  return 1;
}

/* ----------------------------------------------------------------
 * ptable_write_by_type @ 0x3002BCF4  (примерный размер ~280 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 3
 * Вызывает: nand_write, nand_write_oob, printf
 * Вызывают: FUN_3002c4d0, ptable_dload_write, ptable_set_cdromiso_version
 * Константы: 0x3002BCF4
 * Данные: DAT_3002c488, DAT_3002c49c, DAT_3002c4a0, DAT_3002c4a4
 * ---------------------------------------------------------------- */
undefined4
ptable_write_by_type
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if (param_3 == 0) {
    iVar1 = nand_write(param_1,param_2,param_4,param_5);
    if (iVar1 == 0) {
      return 0;
    }
    if (((*DAT_3002c488 & 0x800) != 0) && (-1 < (int)*DAT_3002c488)) {
      printf(DAT_3002c49c);
    }
  }
  else if (param_3 == 1) {
    iVar1 = nand_write_oob(param_1,param_2,param_4,0x10,param_5);
    if (iVar1 == 0) {
      return 0;
    }
    if (((*DAT_3002c488 & 0x800) != 0) && (-1 < (int)*DAT_3002c488)) {
      printf(DAT_3002c4a0);
    }
  }
  else if (((*DAT_3002c488 & 0x800) != 0) && (-1 < (int)*DAT_3002c488)) {
    printf(DAT_3002c4a4,param_3);
  }
  return 1;
}

/* ----------------------------------------------------------------
 * ptable_erase_partition @ 0x3002BE0C  (примерный размер ~384 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 8
 * Вызывает: __udiv32, nand_erase, nand_get_spec, nand_isbad, printf, ptable_find_by_name, ptable_find_by_type, ptable_get_ram_data
 * Константы: 0x3002BE0C
 * Данные: DAT_3002c488, DAT_3002c4a8, DAT_3002c4ac, DAT_3002c4b0, DAT_3002c4b4, DAT_3002c4b8
 * ---------------------------------------------------------------- */
undefined4 ptable_erase_partition(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_30;
  undefined4 local_2c [4];
  
  local_30 = 1;
  uVar1 = ptable_get_ram_data();
  iVar2 = ptable_find_by_name(param_1,uVar1);
  if (iVar2 == 0) {
    uVar1 = ptable_get_ram_data();
    iVar2 = ptable_find_by_type(param_1,uVar1);
    if (iVar2 == 0) {
      if (((*DAT_3002c488 & 0x800) != 0) && (-1 < (int)*DAT_3002c488)) {
        printf(DAT_3002c4a8);
      }
      return 1;
    }
  }
  iVar3 = nand_get_spec(local_2c);
  if (((iVar3 != 0) && ((*DAT_3002c488 & 0x800) != 0)) && (-1 < (int)*DAT_3002c488)) {
    printf(DAT_3002c4ac);
  }
  iVar3 = __udiv32(*(undefined4 *)(iVar2 + 0x10),local_2c[0]);
  iVar2 = __udiv32(*(int *)(iVar2 + 0x10) + *(int *)(iVar2 + 0x18),local_2c[0]);
  for (; iVar3 <= iVar2 + -1; iVar3 = iVar3 + 1) {
    nand_isbad(iVar3,&local_30);
    if (local_30 == 1) {
      if (param_2 == 1) {
        printf(DAT_3002c4b0,iVar3);
        nand_erase(iVar3);
      }
      else {
        printf(DAT_3002c4b4,iVar3);
      }
    }
    else if (local_30 == 0) {
      printf(DAT_3002c4b8,iVar3);
      nand_erase(iVar3);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ptable_quary_partition @ 0x3002BF8C  (примерный размер ~356 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 7
 * Вызывает: __udiv32, nand_get_spec, nand_isbad, printf, ptable_find_by_name, ptable_find_by_type, ptable_get_ram_data
 * Константы: 0x3002BF8C
 * Данные: DAT_3002c488, DAT_3002c4a8, DAT_3002c4ac, DAT_3002c4bc, DAT_3002c4c0, DAT_3002c4c4
 * ---------------------------------------------------------------- */
undefined4 ptable_quary_partition(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_2c;
  undefined4 local_28 [4];
  
  local_2c = 1;
  uVar1 = ptable_get_ram_data();
  iVar2 = ptable_find_by_type(param_1,uVar1);
  if (iVar2 == 0) {
    uVar1 = ptable_get_ram_data();
    iVar2 = ptable_find_by_name(param_1,uVar1);
    if (iVar2 == 0) {
      if (((*DAT_3002c488 & 0x800) != 0) && (-1 < (int)*DAT_3002c488)) {
        printf(DAT_3002c4a8);
      }
      return 1;
    }
  }
  iVar3 = nand_get_spec(local_28);
  if (((iVar3 != 0) && ((*DAT_3002c488 & 0x800) != 0)) && (-1 < (int)*DAT_3002c488)) {
    printf(DAT_3002c4ac);
  }
  iVar3 = __udiv32(*(undefined4 *)(iVar2 + 0x10),local_28[0]);
  iVar2 = __udiv32(*(int *)(iVar2 + 0x10) + *(int *)(iVar2 + 0x18),local_28[0]);
  for (; iVar3 <= iVar2 + -1; iVar3 = iVar3 + 1) {
    nand_isbad(iVar3,&local_2c);
    if (local_2c == 1) {
      printf(DAT_3002c4bc,iVar3);
    }
    else if (local_2c == 0) {
      printf(DAT_3002c4c0,iVar3);
    }
    else {
      printf(DAT_3002c4c4,iVar3);
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ptable_get_range @ 0x3002C0F0  (примерный размер ~148 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: ptable_find_by_type, ptable_get_ram_data
 * Вызывают: NVBackupFlashDataWrite
 * Константы: 0x3002C0F0
 * ---------------------------------------------------------------- */
undefined4 ptable_get_range(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 == (undefined4 *)0x0) && (param_3 == (int *)0x0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = ptable_get_ram_data();
    iVar2 = ptable_find_by_type(param_1,uVar1);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
    else {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(iVar2 + 0x10);
      }
      if (param_3 != (int *)0x0) {
        *param_3 = *(int *)(iVar2 + 0x10) + *(int *)(iVar2 + 0x18);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * ptable_get_cdromiso_version @ 0x3002C184  (примерный размер ~344 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 5
 * Вызывает: memset, ptable_find_by_type, ptable_get_ram_data, ptable_read_by_type, strlen
 * Константы: 0x3002C184
 * Данные: DAT_3002c4c8
 * ---------------------------------------------------------------- */
undefined4 ptable_get_cdromiso_version(char *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  int local_20;
  
  local_20 = 0;
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = ptable_get_ram_data();
    iVar2 = ptable_find_by_type(0x10c,uVar1);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
    else {
      iVar4 = *(int *)(iVar2 + 0x10) + *(int *)(iVar2 + 0x18);
      iVar2 = ptable_read_by_type(iVar4 + -0x7ff80,&local_20,0,4,0);
      if (iVar2 == 0) {
        if (local_20 == DAT_3002c4c8) {
          iVar2 = ptable_read_by_type(iVar4 + -0x80000,param_1,0,param_2,0);
          if (iVar2 == 0) {
            sVar3 = strlen(param_1);
            if (sVar3 < param_2) {
              memset(param_1 + sVar3,0,param_2 - sVar3);
              uVar1 = 0;
            }
            else {
              memset(param_1,0,param_2);
              uVar1 = 1;
            }
          }
          else {
            memset(param_1,0,param_2);
            uVar1 = 1;
          }
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * ptable_set_cdromiso_version @ 0x3002C2DC  (примерный размер ~500 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 6
 * Вызывает: memcpy, memset, ptable_find_by_type, ptable_get_ram_data, ptable_write_by_type, strlen
 * Константы: 0x3002C2DC
 * Данные: DAT_3002c4c8, DAT_3002c4cc
 * ---------------------------------------------------------------- */
undefined4 ptable_set_cdromiso_version(char *param_1,uint param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  size_t __n;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 local_a8;
  undefined1 auStack_a4 [128];
  undefined1 auStack_24 [8];
  
  local_a8 = DAT_3002c4c8;
  iVar7 = 0x42;
  puVar4 = auStack_a4;
  puVar6 = DAT_3002c4cc;
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
  uVar1 = *puVar6;
  *puVar4 = uVar1;
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    uVar3 = 1;
  }
  else {
    uVar3 = ptable_get_ram_data(uVar1,uVar2,auStack_a4);
    iVar7 = ptable_find_by_type(0x10c,uVar3);
    if (iVar7 == 0) {
      uVar3 = 1;
    }
    else {
      __n = strlen(param_1);
      if ((__n < param_2) && (__n < 0x80)) {
        iVar8 = *(int *)(iVar7 + 0x10);
        iVar7 = *(int *)(iVar7 + 0x18);
        memset(auStack_a4,0,0x85);
        memcpy(auStack_a4,param_1,__n);
        memcpy(auStack_24,&local_a8,4);
        iVar7 = ptable_write_by_type(iVar8 + iVar7 + -0x80000,auStack_a4,0,0x84,0);
        if (iVar7 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
      }
      else {
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_3002c4d0 @ 0x3002C4D0  (примерный размер ~396 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 5
 * Вызывает: free, printf, ptable_find_by_name, ptable_write_by_type, strcmp
 * Вызывают: FUN_3002cd64
 * Константы: 0x3002C4D0
 * Данные: DAT_3002d464, DAT_3002d468, DAT_3002d46c, DAT_3002d470, DAT_3002d588
 * ---------------------------------------------------------------- */
undefined4 FUN_3002c4d0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  uVar2 = 0;
  pcVar3 = (char *)(param_2 + 0x30);
LAB_3002c500:
  do {
    iVar1 = strcmp(DAT_3002d464,pcVar3);
    if (iVar1 == 0) {
      pcVar3 = (char *)(param_2 + 0x30);
      while (iVar1 = strcmp(DAT_3002d464,pcVar3), iVar1 != 0) {
        if (*(int *)(pcVar3 + 0x1c) != 0) {
          free(*(void **)(pcVar3 + 0x1c));
          pcVar3[0x1c] = '\0';
          pcVar3[0x1d] = '\0';
          pcVar3[0x1e] = '\0';
          pcVar3[0x1f] = '\0';
        }
        pcVar3 = pcVar3 + 0x30;
      }
      return uVar2;
    }
    if (*(int *)(pcVar3 + 0x1c) != 0) {
      iVar1 = ptable_find_by_name(pcVar3,param_1 + 0x30);
      if (iVar1 == 0) {
        if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
          printf(DAT_3002d46c,pcVar3);
        }
        uVar2 = 1;
        pcVar3 = pcVar3 + 0x30;
        goto LAB_3002c500;
      }
      if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
        printf(DAT_3002d470,*(undefined4 *)(pcVar3 + 0x10),*(undefined4 *)(iVar1 + 0x10));
      }
      iVar1 = ptable_write_by_type
                        (*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(pcVar3 + 0x1c),
                         *(uint *)(pcVar3 + 0x28) & 7,*(undefined4 *)(pcVar3 + 0x18),0);
      if (iVar1 != 0) {
        if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
          printf(DAT_3002d588,pcVar3);
        }
        uVar2 = 1;
      }
    }
    pcVar3 = pcVar3 + 0x30;
  } while( true );
}

/* ----------------------------------------------------------------
 * ptable_set_table_changed @ 0x3002C65C  (примерный размер ~24 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: ptable_replace_ram_table
 * Константы: 0x3002C65C
 * Данные: DAT_3002d58c
 * ---------------------------------------------------------------- */
void ptable_set_table_changed(undefined4 param_1)

{
  *DAT_3002d58c = param_1;
  return;
}

/* ----------------------------------------------------------------
 * ptable_replace_ram_table @ 0x3002C674  (примерный размер ~788 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 10
 * Вызывает: memcmp, memcpy, nandc_init_mtd_partition, printf, ptable_get_ram_data, ptable_get_ram_head, ptable_set_table_changed, strcmp, strlen, strncmp
 * Вызывают: FUN_3002cd64
 * Константы: 0x0FFFFFFF, 0xF0000000, 0x3002C674
 * Данные: DAT_3002d464, DAT_3002d468, DAT_3002d590, DAT_3002d6ac, DAT_3002d6b0, DAT_3002d6f4, DAT_3002d6f8, DAT_3002d6fc
 * ---------------------------------------------------------------- */
undefined4 ptable_replace_ram_table(void *param_1,uint param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  char *__s2;
  void *pvVar6;
  undefined4 uVar7;
  char *__s2_00;
  
  bVar2 = false;
  bVar1 = false;
  if (param_1 == (void *)0x0) {
    return 0;
  }
  iVar3 = ptable_get_ram_head();
  sVar4 = strlen(DAT_3002d590);
  iVar5 = strncmp((char *)((int)param_1 + 0xc),DAT_3002d590,sVar4);
  if (iVar5 == 0) {
LAB_3002c700:
    sVar4 = strlen(DAT_3002d6ac);
    iVar5 = strncmp((char *)(iVar3 + 0x10),DAT_3002d6ac,sVar4);
    if (((iVar5 == 0) && (bVar1 = true, (*DAT_3002d468 & 0x800) != 0)) &&
       (0xfffffff < (int)(*DAT_3002d468 & 0xf0000000))) {
      printf(DAT_3002d6b0);
    }
  }
  else {
    sVar4 = strlen(DAT_3002d590);
    iVar5 = strncmp((char *)((int)param_1 + 0x10),DAT_3002d590,sVar4);
    if (iVar5 == 0) goto LAB_3002c700;
  }
  if (!bVar1) {
    iVar5 = memcmp((void *)(iVar3 + 0x10),(void *)((int)param_1 + 0x10),0x10);
    if (iVar5 != 0) {
      bVar2 = true;
      goto LAB_3002c8ac;
    }
    iVar3 = memcmp((void *)(iVar3 + 0x20),(void *)((int)param_1 + 0x20),0x10);
    if (iVar3 != 0) {
      bVar2 = true;
      goto LAB_3002c8ac;
    }
  }
  __s2 = (char *)ptable_get_ram_data();
  __s2_00 = (char *)((int)param_1 + 0x30);
  while ((iVar3 = strcmp(DAT_3002d464,__s2), iVar3 != 0 &&
         (iVar3 = strcmp(DAT_3002d464,__s2_00), iVar3 != 0))) {
    if ((((*(int *)(__s2 + 0x10) != *(int *)(__s2_00 + 0x10)) ||
         ((*(int *)(__s2 + 0x18) != *(int *)(__s2_00 + 0x18) ||
          (*(int *)(__s2 + 0x1c) != *(int *)(__s2_00 + 0x1c))))) ||
        (*(int *)(__s2 + 0x20) != *(int *)(__s2_00 + 0x20))) ||
       ((*(int *)(__s2 + 0x24) != *(int *)(__s2_00 + 0x24) ||
        ((((*(uint *)(__s2 + 0x28) | 8) != (*(uint *)(__s2_00 + 0x28) | 8) && (!bVar1)) ||
         (iVar3 = strcmp(__s2,__s2_00), iVar3 != 0)))))) {
      bVar2 = true;
      goto LAB_3002c8ac;
    }
    __s2 = __s2 + 0x30;
    __s2_00 = __s2_00 + 0x30;
  }
  iVar3 = strcmp(DAT_3002d464,__s2_00);
  if ((iVar3 != 0) || (iVar3 = strcmp(DAT_3002d464,__s2), iVar3 != 0)) {
    bVar2 = true;
  }
LAB_3002c8ac:
  if ((param_1 == (void *)0x0) || (!bVar2)) {
    uVar7 = 0;
  }
  else {
    if (param_2 < 0x401) {
      pvVar6 = (void *)ptable_get_ram_head();
      memcpy(pvVar6,param_1,param_2);
      if (((*DAT_3002d468 & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d468 & 0xf0000000))) {
        printf(DAT_3002d6f4);
      }
    }
    else {
      pvVar6 = (void *)ptable_get_ram_head();
      memcpy(pvVar6,param_1,0x400);
      iVar3 = ptable_get_ram_head();
      memcpy((void *)(iVar3 + 0x3c0),DAT_3002d6f8,2);
      if (((*DAT_3002d468 & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d468 & 0xf0000000))) {
        printf(DAT_3002d6fc);
      }
    }
    ptable_set_table_changed(1);
    uVar7 = nandc_init_mtd_partition(*DAT_3002d700);
  }
  return uVar7;
}

/* ----------------------------------------------------------------
 * ptable_replace_flash_table @ 0x3002C988  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 4 | Вызывает: 2
 * Вызывает: nand_write, ptable_get_ram_head
 * Вызывают: FUN_3002cd64, dloadBootromEnd, dloadFromFsMainThread, ptable_find_older_part
 * Константы: 0x3002C988
 * ---------------------------------------------------------------- */
void ptable_replace_flash_table(void)

{
  undefined4 uVar1;
  
  uVar1 = ptable_get_ram_head();
  nand_write(0x1e000,uVar1,0x400,0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3002c9a8 @ 0x3002C9A8  (примерный размер ~352 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: nand_scan_bad, printf, strcmp
 * Вызывают: FUN_3002cd64
 * Константы: 0x0FFFFFFF, 0xF0000000, 0x3002C9A8
 * Данные: DAT_3002d464, DAT_3002d468, DAT_3002d704
 * ---------------------------------------------------------------- */
undefined4 FUN_3002c9a8(int param_1,int param_2)

{
  int iVar1;
  char *__s2;
  char *__s2_00;
  
  __s2_00 = (char *)(param_2 + 0x30);
  __s2 = (char *)(param_1 + 0x30);
  while ((iVar1 = strcmp(DAT_3002d464,__s2_00), iVar1 != 0 &&
         (iVar1 = strcmp(DAT_3002d464,__s2), iVar1 != 0))) {
    if (((*(uint *)(__s2 + 0x28) & 7) == 1) &&
       ((((*(int *)(__s2_00 + 0x10) != *(int *)(__s2 + 0x10) ||
          (*(int *)(__s2_00 + 0x18) != *(int *)(__s2 + 0x18))) ||
         ((*(uint *)(__s2_00 + 0x28) & 7) != 1)) || (iVar1 = strcmp(__s2_00,__s2), iVar1 != 0)))) {
      if (((*DAT_3002d468 & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d468 & 0xf0000000))) {
        printf(DAT_3002d704,__s2);
      }
      nand_scan_bad(*(undefined4 *)(__s2 + 0x10),*(undefined4 *)(__s2 + 0x18),1);
    }
    __s2_00 = __s2_00 + 0x30;
    __s2 = __s2 + 0x30;
  }
  while (iVar1 = strcmp(DAT_3002d464,__s2), iVar1 != 0) {
    if ((*(uint *)(__s2 + 0x28) & 7) == 1) {
      if (((*DAT_3002d468 & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d468 & 0xf0000000))) {
        printf(DAT_3002d704,__s2);
      }
      nand_scan_bad(*(undefined4 *)(__s2 + 0x10),*(undefined4 *)(__s2 + 0x18),1);
    }
    __s2 = __s2 + 0x30;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3002cb08 @ 0x3002CB08  (примерный размер ~552 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 6
 * Вызывает: malloc, nand_read, nand_yaffs_write_size, printf, ptable_read_by_type, strcmp
 * Вызывают: FUN_3002cd64
 * Константы: 0x3002CB08
 * Данные: DAT_3002d464, DAT_3002d468, DAT_3002d708, DAT_3002d70c, DAT_3002d710
 * ---------------------------------------------------------------- */
undefined4 FUN_3002cb08(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 uVar4;
  char *__s2;
  char *__s2_00;
  uint uVar5;
  
  uVar4 = 0;
  __s2_00 = (char *)(param_2 + 0x30);
  __s2 = (char *)(param_1 + 0x30);
  while ((iVar1 = strcmp(DAT_3002d464,__s2_00), iVar1 != 0 &&
         (iVar1 = strcmp(DAT_3002d464,__s2), iVar1 != 0))) {
    if (((*(uint *)(__s2 + 0x28) & 0x800) == 0) ||
       (((*(int *)(__s2_00 + 0x10) == *(int *)(__s2 + 0x10) &&
         (*(int *)(__s2_00 + 0x18) == *(int *)(__s2 + 0x18))) &&
        (iVar1 = strcmp(__s2_00,__s2), iVar1 == 0)))) {
      __s2_00[0x1c] = '\0';
      __s2_00[0x1d] = '\0';
      __s2_00[0x1e] = '\0';
      __s2_00[0x1f] = '\0';
    }
    else {
      uVar5 = *(uint *)(__s2_00 + 0x28);
      if ((uVar5 & 7) == 1) {
        uVar2 = nand_yaffs_write_size(*(undefined4 *)(__s2_00 + 0x18));
        *(undefined4 *)(__s2_00 + 0x18) = uVar2;
      }
      pvVar3 = malloc(*(size_t *)(__s2_00 + 0x18));
      *(void **)(__s2_00 + 0x1c) = pvVar3;
      if (*(int *)(__s2_00 + 0x1c) == 0) {
        if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
          printf(DAT_3002d708);
        }
        uVar4 = 1;
      }
      iVar1 = ptable_read_by_type(*(undefined4 *)(__s2_00 + 0x10),*(undefined4 *)(__s2_00 + 0x1c),
                                  uVar5 & 7,*(undefined4 *)(__s2_00 + 0x18));
      if (iVar1 != 0) {
        if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
          printf(DAT_3002d70c);
        }
        uVar4 = 1;
      }
    }
    __s2_00 = __s2_00 + 0x30;
    __s2 = __s2 + 0x30;
  }
  while (iVar1 = strcmp(DAT_3002d464,__s2_00), iVar1 != 0) {
    if ((*(uint *)(__s2_00 + 0x28) & 0x800) == 0) {
      __s2_00[0x1c] = '\0';
      __s2_00[0x1d] = '\0';
      __s2_00[0x1e] = '\0';
      __s2_00[0x1f] = '\0';
    }
    else {
      pvVar3 = malloc(*(size_t *)(__s2_00 + 0x18));
      *(void **)(__s2_00 + 0x1c) = pvVar3;
      if (*(int *)(__s2_00 + 0x1c) == 0) {
        if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
          printf(DAT_3002d708);
        }
        uVar4 = 1;
      }
      iVar1 = nand_read(*(undefined4 *)(__s2_00 + 0x10),*(undefined4 *)(__s2_00 + 0x1c),
                        *(undefined4 *)(__s2_00 + 0x18),0);
      if (iVar1 != 0) {
        if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
          printf(DAT_3002d710);
        }
        uVar4 = 1;
      }
    }
    __s2_00 = __s2_00 + 0x30;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * ptable_flash_prepare @ 0x3002CD30  (примерный размер ~52 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: nand_scan_bad
 * Вызывают: ptable_dload_write
 * Константы: 0x3002CD30
 * ---------------------------------------------------------------- */
undefined4 ptable_flash_prepare(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 1) {
    uVar1 = nand_scan_bad(param_1,param_2,1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3002cd64 @ 0x3002CD64  (примерный размер ~324 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 12
 * Вызывает: FUN_3002c4d0, FUN_3002c9a8, FUN_3002cb08, free, malloc, memcpy, printf, ptable_get_ram_head, ptable_replace_flash_table, ptable_replace_ram_table, ptable_set_integrality, ptable_show
 * Вызывают: ptable_dload_write
 * Константы: 0x3002CD64
 * Данные: DAT_3002d468, DAT_3002d714, DAT_3002d718, DAT_3002d71c, DAT_3002d720
 * ---------------------------------------------------------------- */
void FUN_3002cd64(undefined4 param_1,undefined4 param_2)

{
  void *__dest;
  void *__src;
  int iVar1;
  
  ptable_show(param_1);
  __dest = malloc(0x400);
  if (__dest == (void *)0x0) {
    if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
      printf(DAT_3002d714);
    }
  }
  else {
    __src = (void *)ptable_get_ram_head();
    memcpy(__dest,__src,0x400);
    FUN_3002cb08(param_1,__dest);
    iVar1 = ptable_replace_ram_table(param_1,param_2);
    if (((iVar1 != 0) && ((*DAT_3002d468 & 0x800) != 0)) && (-1 < (int)*DAT_3002d468)) {
      printf(DAT_3002d718);
    }
    FUN_3002c9a8(param_1,__dest);
    iVar1 = FUN_3002c4d0(param_1,__dest);
    if (((iVar1 != 0) && ((*DAT_3002d468 & 0x800) != 0)) && (-1 < (int)*DAT_3002d468)) {
      printf(DAT_3002d71c);
    }
  }
  if (*DAT_3002d720 == 0) {
    ptable_set_integrality(1);
    ptable_replace_flash_table();
    *DAT_3002d720 = 1;
  }
  if (__dest != (void *)0x0) {
    free(__dest);
  }
  return;
}

/* ----------------------------------------------------------------
 * ptable_get_table_changed @ 0x3002CEA8  (примерный размер ~12 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: dloadDealBootrom
 * Константы: 0x3002CEA8
 * Данные: DAT_3002d58c
 * ---------------------------------------------------------------- */
undefined4 ptable_get_table_changed(void)

{
  return *DAT_3002d58c;
}

/* ----------------------------------------------------------------
 * ptable_find_older_part @ 0x3002CEB4  (примерный размер ~232 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 4
 * Вызывает: ptable_get_validity, ptable_replace_flash_table, ptable_set_validity, strcmp
 * Вызывают: ImageDloadToFlash, ImageDloadToRam, ptable_dload_write
 * Константы: 0x3002CEB4
 * Данные: DAT_3002d464
 * ---------------------------------------------------------------- */
char * ptable_find_older_part(int param_1,char *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  
  pcVar5 = (char *)0x0;
  pcVar3 = (char *)0x0;
  if (param_2 != (char *)0x0) {
    while (iVar1 = strcmp(DAT_3002d464,param_2), iVar1 != 0) {
      pcVar4 = pcVar3;
      pcVar6 = pcVar5;
      if ((*(int *)(param_2 + 0x24) == param_1) &&
         (pcVar4 = param_2, pcVar6 = param_2, pcVar5 != (char *)0x0)) {
        if (*(uint *)(param_2 + 0x2c) <= *(uint *)(pcVar5 + 0x2c)) {
          pcVar5 = param_2;
        }
        pcVar4 = pcVar3;
        pcVar6 = pcVar5;
        if (*(uint *)(pcVar3 + 0x2c) < *(uint *)(param_2 + 0x2c)) {
          pcVar4 = param_2;
        }
      }
      param_2 = param_2 + 0x30;
      pcVar3 = pcVar4;
      pcVar5 = pcVar6;
    }
    if (pcVar5 != (char *)0x0) {
      if ((param_3 == 1) && (pcVar3 != (char *)0x0)) {
        *(int *)(pcVar5 + 0x2c) = *(int *)(pcVar3 + 0x2c) + 1;
      }
      iVar1 = ptable_get_validity(pcVar5);
      ptable_set_validity(pcVar5,param_4);
      iVar2 = ptable_get_validity(pcVar5);
      if (iVar2 != iVar1) {
        ptable_replace_flash_table();
      }
    }
  }
  return pcVar5;
}

/* ----------------------------------------------------------------
 * ptable_dload_write @ 0x3002CF9C  (примерный размер ~612 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_3002cd64, nand_yaffs_data_size, printf, ptable_find_older_part, ptable_flash_prepare, ptable_get_ram_data, ptable_write_by_type
 * Вызывают: FUN_30081f50, FUN_300827c0
 * Константы: 0x3002CF9C, 0x0FFFFFFF, 0xF0000000
 * Данные: DAT_3002d468, DAT_3002d724, DAT_3002d728, DAT_3002d72c, DAT_3002d730, DAT_3002d734, DAT_3002d738, DAT_3002d73c
 * ---------------------------------------------------------------- */
undefined4 ptable_dload_write(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_24;
  
  local_24 = 0;
  if (((*DAT_3002d468 & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d468 & 0xf0000000))) {
    printf(DAT_3002d724,param_1,param_2,param_3,param_4);
  }
  if (param_1 == 0) {
    if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
      printf(DAT_3002d728);
    }
  }
  else {
    if (param_2 == 0x100) {
      FUN_3002cd64(param_1,param_4);
      return 0;
    }
    uVar1 = ptable_get_ram_data();
    iVar2 = ptable_find_older_part(param_2,uVar1,0,0);
    if (iVar2 == 0) {
      if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
        printf(DAT_3002d72c,param_2);
      }
    }
    else {
      uVar4 = *(uint *)(iVar2 + 0x28) & 7;
      if ((*DAT_3002d730 == param_2) && (param_3 != 0)) {
        param_3 = *(int *)(iVar2 + 0x14);
      }
      else {
        *DAT_3002d730 = param_2;
        *DAT_3002d734 = 0;
        iVar3 = ptable_flash_prepare
                          (*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x18),uVar4);
        if (iVar3 != 0) {
          if ((*DAT_3002d468 & 0x800) == 0) {
            return 1;
          }
          if ((int)*DAT_3002d468 < 0) {
            return 1;
          }
          printf(DAT_3002d738);
          return 1;
        }
        *(undefined4 *)(iVar2 + 0x14) = 0;
      }
      local_24 = 0;
      iVar3 = ptable_write_by_type
                        (*DAT_3002d734 + param_3 + *(int *)(iVar2 + 0x10),param_1,uVar4,param_4,
                         &local_24);
      if (iVar3 == 0) {
        *DAT_3002d734 = *DAT_3002d734 + local_24;
        if ((uVar4 == 1) && (param_4 != 0)) {
          param_4 = nand_yaffs_data_size(param_4);
        }
        *(int *)(iVar2 + 0x14) = param_4 + *(int *)(iVar2 + 0x14);
        return 0;
      }
      if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
        printf(DAT_3002d73c,param_2);
      }
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * ptable_dload_read @ 0x3002D200  (примерный размер ~348 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 4
 * Вызывает: printf, ptable_find_by_type, ptable_get_ram_data, ptable_read_by_type
 * Константы: 0x3002D200, 0x1FFFFFFF, 0xF0000000
 * Данные: DAT_3002d468, DAT_3002d740, DAT_3002d744, DAT_3002d748, DAT_3002d74c
 * ---------------------------------------------------------------- */
undefined4 ptable_dload_read(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((*DAT_3002d468 & 0x800) != 0) && (0x1fffffff < (int)(*DAT_3002d468 & 0xf0000000))) {
    printf(DAT_3002d740,param_1,param_2,param_3,param_4);
  }
  if (param_1 == 0) {
    if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
      printf(DAT_3002d744);
    }
  }
  else {
    uVar1 = ptable_get_ram_data();
    iVar2 = ptable_find_by_type(param_2,uVar1);
    if (iVar2 == 0) {
      if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
        printf(DAT_3002d748,param_2);
      }
    }
    else {
      iVar2 = ptable_read_by_type(param_3 + *(int *)(iVar2 + 0x10),param_1,
                                  *(uint *)(iVar2 + 0x28) & 7,param_4,0);
      if (iVar2 == 0) {
        return 0;
      }
      if (((*DAT_3002d468 & 0x800) != 0) && (-1 < (int)*DAT_3002d468)) {
        printf(DAT_3002d74c,param_2);
      }
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * ptable_yaffs_mount @ 0x3002D35C  (примерный размер ~340 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: printf, ptable_get_ram_data, strcmp, yaffsDevCreate
 * Вызывают: yaffsInit
 * Константы: 0x0FFFFFFF, 0xF0000000, 0x3002D35C
 * Данные: DAT_3002d464, DAT_3002d468, DAT_3002d750, DAT_3002d754, DAT_3002d758, DAT_3002d75c, DAT_3002d760
 * ---------------------------------------------------------------- */
void ptable_yaffs_mount(void)

{
  char *__s2;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  __s2 = (char *)ptable_get_ram_data();
  while (iVar1 = strcmp(DAT_3002d464,__s2), iVar1 != 0) {
    if ((*(uint *)(__s2 + 0x28) & 0x600) != 0) {
      if (((*DAT_3002d468 & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d468 & 0xf0000000))) {
        printf(DAT_3002d750,__s2);
      }
      if (*(int *)(__s2 + 0x18) == 0) {
        if (((*DAT_3002d75c & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d75c & 0xf0000000))) {
          printf(DAT_3002d760,__s2);
        }
      }
      else {
        iVar1 = yaffsDevCreate(iVar2,*(undefined4 *)(__s2 + 0x10),
                               *(int *)(__s2 + 0x10) + *(int *)(__s2 + 0x18),__s2);
        if (iVar1 == 0) {
          if (((*DAT_3002d468 & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d468 & 0xf0000000))) {
            printf(DAT_3002d754,__s2);
          }
        }
        else if (((*DAT_3002d468 & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d468 & 0xf0000000)))
        {
          printf(DAT_3002d758,__s2);
        }
        iVar2 = iVar2 + 1;
      }
    }
    __s2 = __s2 + 0x30;
  }
  return;
}

/* ----------------------------------------------------------------
 * ptable_yaffs_mount_byname @ 0x3002D4B0  (примерный размер ~292 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 4
 * Вызывает: printf, ptable_get_ram_data, strcmp, yaffs_mount
 * Константы: 0x0FFFFFFF, 0xF0000000, 0x3002D4B0
 * Данные: DAT_3002d754, DAT_3002d758, DAT_3002d75c, DAT_3002d764, DAT_3002d768
 * ---------------------------------------------------------------- */
void ptable_yaffs_mount_byname(char *param_1)

{
  char *__s2;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  __s2 = (char *)ptable_get_ram_data();
  while (iVar1 = strcmp(DAT_3002d764,__s2), iVar1 != 0) {
    if (((*(uint *)(__s2 + 0x28) & 0x600) != 0) && (*(int *)(__s2 + 0x18) != 0)) {
      iVar1 = strcmp(param_1,__s2);
      if (iVar1 == 0) {
        if (((*DAT_3002d75c & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d75c & 0xf0000000))) {
          printf(DAT_3002d768,__s2);
        }
        iVar1 = yaffs_mount(iVar2,param_1);
        if (iVar1 == 0) {
          if (((*DAT_3002d75c & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d75c & 0xf0000000))) {
            printf(DAT_3002d754,__s2);
          }
        }
        else if (((*DAT_3002d75c & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d75c & 0xf0000000)))
        {
          printf(DAT_3002d758,__s2);
        }
      }
      iVar2 = iVar2 + 1;
    }
    __s2 = __s2 + 0x30;
  }
  return;
}

/* ----------------------------------------------------------------
 * ptable_yaffs_unmount_byname @ 0x3002D5D4  (примерный размер ~408 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 4
 * Вызывает: printf, ptable_get_ram_data, strcmp, yaffs_unmount
 * Константы: 0x0FFFFFFF, 0xF0000000, 0x3002D5D4
 * Данные: DAT_3002d754, DAT_3002d758, DAT_3002d75c, DAT_3002d764, DAT_3002d768
 * ---------------------------------------------------------------- */
void ptable_yaffs_unmount_byname(char *param_1)

{
  char *__s2;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  __s2 = (char *)ptable_get_ram_data();
  while (iVar1 = strcmp(DAT_3002d764,__s2), iVar1 != 0) {
    if (((*(uint *)(__s2 + 0x28) & 0x600) != 0) && (*(int *)(__s2 + 0x18) != 0)) {
      iVar1 = strcmp(param_1,__s2);
      if (iVar1 == 0) {
        if (((*DAT_3002d75c & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d75c & 0xf0000000))) {
          printf(DAT_3002d768,__s2);
        }
        iVar1 = yaffs_unmount(iVar2,param_1);
        if (iVar1 == 0) {
          if (((*DAT_3002d75c & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d75c & 0xf0000000))) {
            printf(DAT_3002d754,__s2);
          }
        }
        else if (((*DAT_3002d75c & 0x800) != 0) && (0xfffffff < (int)(*DAT_3002d75c & 0xf0000000)))
        {
          printf(DAT_3002d758,__s2);
        }
      }
      iVar2 = iVar2 + 1;
    }
    __s2 = __s2 + 0x30;
  }
  return;
}

/* ----------------------------------------------------------------
 * ptable_size @ 0x3002D76C  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: ptable_ensure
 * Константы: 0x3002D76C
 * ---------------------------------------------------------------- */
undefined4 ptable_size(void)

{
  return 0x3c0;
}

/* ----------------------------------------------------------------
 * nand_get_bad_block @ 0x30099CA4  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099CA4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 nand_get_bad_block(void)

{
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * nand_free_bad_block_mem @ 0x30099CAC  (примерный размер ~4 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099CAC
 * ---------------------------------------------------------------- */
void nand_free_bad_block_mem(void)

{
  return;
}

/* ----------------------------------------------------------------
 * nand_get_dev_info @ 0x30099CB0  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099CB0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 nand_get_dev_info(void)

{
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * NVM_Read @ 0x3009B480  (примерный размер ~172 байт)
 * Модуль: flash | Вызывают: 4 | Вызывает: 0
 * Вызывают: BSP_PMU_AptEnable, BSP_PMU_BoardInit, exchReadConfig, os_nv_read
 * Константы: 0x3009B480
 * Данные: DAT_3009bbac, DAT_3009bbb0, DAT_3009bbb4
 * ---------------------------------------------------------------- */
undefined4 NVM_Read(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  iVar1 = (*DAT_3009bbac)();
  puVar3 = (uint *)(iVar1 + 4);
  iVar1 = (*DAT_3009bbb0)();
  if (iVar1 == 0) {
    iVar1 = 2;
    do {
      if (((*puVar3 & DAT_3009bbb4) <= param_1) && (param_1 <= *puVar3 >> 0x10)) {
        if ((code *)puVar3[2] != (code *)0x0) {
          uVar2 = (*(code *)puVar3[2])(param_1 & 0xffff,param_2,param_3);
          return uVar2;
        }
        return 3;
      }
      puVar3 = puVar3 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    uVar2 = 0x208;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * NVM_Write @ 0x3009B52C  (примерный размер ~172 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B52C
 * Данные: DAT_3009bbac, DAT_3009bbb0, DAT_3009bbb4
 * ---------------------------------------------------------------- */
undefined4 NVM_Write(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  iVar1 = (*DAT_3009bbac)();
  puVar3 = (uint *)(iVar1 + 4);
  iVar1 = (*DAT_3009bbb0)();
  if (iVar1 == 0) {
    iVar1 = 2;
    do {
      if (((*puVar3 & DAT_3009bbb4) <= param_1) && (param_1 <= *puVar3 >> 0x10)) {
        if ((code *)puVar3[3] != (code *)0x0) {
          uVar2 = (*(code *)puVar3[3])(param_1 & 0xffff,param_2,param_3);
          return uVar2;
        }
        return 3;
      }
      puVar3 = puVar3 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    uVar2 = 0x208;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * NVM_Flush @ 0x3009B5D8  (примерный размер ~152 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B5D8
 * Данные: DAT_3009bbac, DAT_3009bbb0, DAT_3009bbb8, DAT_3009bbbc, DAT_3009bbc0, DAT_3009bbc4
 * ---------------------------------------------------------------- */
undefined4 NVM_Flush(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (*DAT_3009bbac)();
  iVar2 = (*DAT_3009bbb0)();
  if (iVar2 == 0) {
    if (*(code **)(iVar1 + 0x30) == (code *)0x0) {
      (*DAT_3009bbb8)(DAT_3009bbc0);
      uVar3 = 3;
    }
    else {
      uVar3 = (**(code **)(iVar1 + 0x30))();
      (*DAT_3009bbb8)(DAT_3009bbc4,uVar3);
    }
  }
  else {
    (*DAT_3009bbb8)(DAT_3009bbbc);
    uVar3 = 3;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * NVM_AutoRestoreNV @ 0x3009B670  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B670
 * Данные: DAT_3009bbac
 * ---------------------------------------------------------------- */
void NVM_AutoRestoreNV(void)

{
  (*DAT_3009bbac)();
  return;
}

/* ----------------------------------------------------------------
 * NVM_IoRegister @ 0x3009B684  (примерный размер ~172 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B684
 * Данные: DAT_3009bbac, DAT_3009bbc8, DAT_3009bbcc
 * ---------------------------------------------------------------- */
undefined4 NVM_IoRegister(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  uVar2 = DAT_3009bbc8;
  if (param_2 != 0) {
    iVar1 = (*DAT_3009bbac)();
    piVar3 = (int *)(iVar1 + 4);
    iVar1 = 2;
    do {
      if (*piVar3 == 0) {
        *piVar3 = param_1;
        (*DAT_3009bbcc)(piVar3 + 1,param_2,0x2c);
        break;
      }
      if (*piVar3 == param_1) {
        (*DAT_3009bbcc)(piVar3 + 1,param_2,0x2c);
        break;
      }
      piVar3 = piVar3 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (iVar1 == 0) {
      uVar2 = 0x214;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * NVM_Init @ 0x3009B730  (примерный размер ~172 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B730
 * Данные: DAT_3009bbac, DAT_3009bbb8, DAT_3009bbd0, DAT_3009bbd4, DAT_3009bbd8, DAT_3009bbdc, DAT_3009bbe0, DAT_3009bbe4
 * ---------------------------------------------------------------- */
int NVM_Init(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*DAT_3009bbac)();
  *piVar1 = 3;
  (*DAT_3009bbb8)(DAT_3009bbd0);
  iVar2 = (*DAT_3009bbd4)(0);
  *piVar1 = (iVar2 != 0) + 1;
  if ((iVar2 == 0) && (iVar2 = (*DAT_3009bbd8)(DAT_3009bbe0,DAT_3009bbdc,4), iVar2 != 0)) {
    (*DAT_3009bbe4)(6,iVar2,0,5);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * NVM_UpgradeBackup @ 0x3009B7DC  (примерный размер ~148 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B7DC
 * Данные: DAT_3009bbac, DAT_3009bbb0, DAT_3009bbb8, DAT_3009bbe8
 * ---------------------------------------------------------------- */
int NVM_UpgradeBackup(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = (*DAT_3009bbb0)();
  if (iVar1 == 0) {
    iVar1 = (*DAT_3009bbac)();
    puVar3 = (undefined4 *)(iVar1 + 0x24);
    iVar1 = 2;
    do {
      if ((code *)*puVar3 == (code *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(code *)*puVar3)(param_1);
        (*DAT_3009bbb8)(DAT_3009bbe8,iVar2);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      puVar3 = puVar3 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  else {
    iVar2 = 3;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * NVM_UpgradeRestore @ 0x3009B870  (примерный размер ~144 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B870
 * Данные: DAT_3009bbac, DAT_3009bbb0, DAT_3009bbb8, DAT_3009bbec
 * ---------------------------------------------------------------- */
int NVM_UpgradeRestore(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = (*DAT_3009bbb0)();
  if (iVar1 == 0) {
    iVar1 = (*DAT_3009bbac)();
    puVar3 = (undefined4 *)(iVar1 + 0x58);
    iVar1 = 2;
    do {
      if ((code *)*puVar3 == (code *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(code *)*puVar3)();
        (*DAT_3009bbb8)(DAT_3009bbec,iVar2);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      puVar3 = puVar3 + -0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  else {
    iVar2 = 3;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * NVM_BackUpFNV @ 0x3009B900  (примерный размер ~144 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B900
 * Данные: DAT_3009bbac, DAT_3009bbb0, DAT_3009bbb8, DAT_3009bbf0
 * ---------------------------------------------------------------- */
int NVM_BackUpFNV(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = (*DAT_3009bbb0)();
  if (iVar1 == 0) {
    iVar1 = (*DAT_3009bbac)();
    puVar3 = (undefined4 *)(iVar1 + 0x24);
    iVar1 = 2;
    do {
      if ((code *)*puVar3 == (code *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(code *)*puVar3)(3);
        (*DAT_3009bbb8)(DAT_3009bbf0,iVar2);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      puVar3 = puVar3 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  else {
    iVar2 = 3;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * NVM_RevertFNV @ 0x3009B990  (примерный размер ~140 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B990
 * Данные: DAT_3009bbac, DAT_3009bbb0, DAT_3009bbb8, DAT_3009bbf4
 * ---------------------------------------------------------------- */
int NVM_RevertFNV(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = (*DAT_3009bbb0)();
  if (iVar1 == 0) {
    iVar1 = (*DAT_3009bbac)();
    puVar3 = (undefined4 *)(iVar1 + 0x20);
    iVar1 = 2;
    do {
      if ((code *)*puVar3 == (code *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(code *)*puVar3)();
        (*DAT_3009bbb8)(DAT_3009bbf4,iVar2);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      puVar3 = puVar3 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  else {
    iVar2 = 3;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * NVM_SetFactoryDefault @ 0x3009BA1C  (примерный размер ~140 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BA1C
 * Данные: DAT_3009bbac, DAT_3009bbb0, DAT_3009bbb8, DAT_3009bbf4
 * ---------------------------------------------------------------- */
int NVM_SetFactoryDefault(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = (*DAT_3009bbb0)();
  if (iVar1 == 0) {
    iVar1 = (*DAT_3009bbac)();
    puVar3 = (undefined4 *)(iVar1 + 0x18);
    iVar1 = 2;
    do {
      if ((code *)*puVar3 == (code *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(code *)*puVar3)();
        (*DAT_3009bbb8)(DAT_3009bbf4,iVar2);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      puVar3 = puVar3 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  else {
    iVar2 = 3;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * NVM_GetItemLength @ 0x3009BAA8  (примерный размер ~172 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BAA8
 * Данные: DAT_3009bbac, DAT_3009bbb0, DAT_3009bbb4
 * ---------------------------------------------------------------- */
undefined4 NVM_GetItemLength(ushort param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  iVar1 = (*DAT_3009bbac)();
  puVar3 = (uint *)(iVar1 + 4);
  iVar1 = (*DAT_3009bbb0)();
  if (iVar1 == 0) {
    iVar1 = 2;
    do {
      if (((*puVar3 & DAT_3009bbb4) <= (uint)param_1) && ((uint)param_1 <= *puVar3 >> 0x10)) {
        if ((code *)puVar3[4] != (code *)0x0) {
          uVar2 = (*(code *)puVar3[4])(param_1,param_2);
          return uVar2;
        }
        return 3;
      }
      puVar3 = puVar3 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    uVar2 = 0x208;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * NVM_IsReStoreFunAll @ 0x3009BB54  (примерный размер ~164 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BB54
 * Данные: DAT_3009bbac, DAT_3009bbb0
 * ---------------------------------------------------------------- */
undefined4 NVM_IsReStoreFunAll(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = (*DAT_3009bbb0)();
  if (iVar1 == 0) {
    iVar1 = (*DAT_3009bbac)(0);
    piVar3 = (int *)(iVar1 + 0x28);
    iVar1 = 2;
    do {
      if (*piVar3 == 0) {
        return 0;
      }
      piVar3 = piVar3 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nvimGetMainInfo @ 0x3009BBF8  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BBF8
 * Данные: DAT_3009bc28
 * ---------------------------------------------------------------- */
undefined4 nvimGetMainInfo(void)

{
  return DAT_3009bc28;
}

/* ----------------------------------------------------------------
 * nvimSetInitState @ 0x3009BC00  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BC00
 * Данные: DAT_3009bc28
 * ---------------------------------------------------------------- */
undefined4 nvimSetInitState(void)

{
  *DAT_3009bc28 = 1;
  return 0;
}

/* ----------------------------------------------------------------
 * nvimSetInitStateFailure @ 0x3009BC14  (примерный размер ~24 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BC14, 0xFFFFFFFF
 * Данные: DAT_3009bc28
 * ---------------------------------------------------------------- */
undefined4 nvimSetInitStateFailure(void)

{
  *DAT_3009bc28 = 2;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * Lnv_File_Open @ 0x3009BC34  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BC34
 * Данные: DAT_3009bcc0
 * ---------------------------------------------------------------- */
void Lnv_File_Open(void)

{
  (*DAT_3009bcc0)();
  return;
}

/* ----------------------------------------------------------------
 * Lnv_File_Close @ 0x3009BC48  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BC48
 * Данные: DAT_3009bcc4
 * ---------------------------------------------------------------- */
void Lnv_File_Close(void)

{
  (*DAT_3009bcc4)();
  return;
}

/* ----------------------------------------------------------------
 * Lnv_File_Read @ 0x3009BC5C  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BC5C
 * Данные: DAT_3009bcc8
 * ---------------------------------------------------------------- */
void Lnv_File_Read(void)

{
  (*DAT_3009bcc8)();
  return;
}

/* ----------------------------------------------------------------
 * Lnv_File_Write @ 0x3009BC70  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BC70
 * Данные: DAT_3009bccc
 * ---------------------------------------------------------------- */
void Lnv_File_Write(void)

{
  (*DAT_3009bccc)();
  return;
}

/* ----------------------------------------------------------------
 * Lnv_File_Remove @ 0x3009BC84  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BC84
 * Данные: DAT_3009bcd0
 * ---------------------------------------------------------------- */
void Lnv_File_Remove(void)

{
  (*DAT_3009bcd0)();
  return;
}

/* ----------------------------------------------------------------
 * Lnv_File_Seek @ 0x3009BC98  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BC98
 * Данные: DAT_3009bcd4
 * ---------------------------------------------------------------- */
void Lnv_File_Seek(void)

{
  (*DAT_3009bcd4)();
  return;
}

/* ----------------------------------------------------------------
 * Lnv_File_Ftell @ 0x3009BCAC  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BCAC
 * Данные: DAT_3009bcd8
 * ---------------------------------------------------------------- */
void Lnv_File_Ftell(void)

{
  (*DAT_3009bcd8)();
  return;
}

/* ----------------------------------------------------------------
 * Lnvm_IsLegalToWrite @ 0x3009CC18  (примерный размер ~4 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009CC18
 * ---------------------------------------------------------------- */
void Lnvm_IsLegalToWrite(void)

{
  return;
}

/* ----------------------------------------------------------------
 * Lnvm_WritePriorityHNV @ 0x3009CC1C  (примерный размер ~476 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009CC1C
 * Данные: DAT_3009d068, DAT_3009d070, DAT_3009d4ac, DAT_3009d4b0, DAT_3009d4b4, DAT_3009d4b8, DAT_3009d50c, DAT_3009d510
 * ---------------------------------------------------------------- */
int Lnvm_WritePriorityHNV(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = 0;
  iVar1 = (*DAT_3009d50c)();
  iVar1 = iVar1 + param_4 * 0xc;
  uVar5 = (uint)*(ushort *)(iVar1 + 0x3ec);
  if (uVar5 == 0) {
    (*DAT_3009d070)(5,0,0,2);
    iVar4 = (*DAT_3009d4ac)(param_1,param_2,param_3);
    if (iVar4 == 0) {
      return 0;
    }
    uVar2 = 6;
    uVar5 = 0;
    uVar3 = 6;
  }
  else {
    uVar2 = 5;
    if (uVar5 == 1) {
      (*DAT_3009d070)(5,*DAT_3009d510,1,3);
      uVar5 = *DAT_3009d510 + (uint)*(ushort *)(iVar1 + DAT_3009d514);
      *DAT_3009d510 = uVar5;
      if (uVar5 < *DAT_3009d518) {
        return 0;
      }
      iVar4 = (*DAT_3009d4b0)(param_1,param_2,param_3);
      if (iVar4 == 0) {
        (*DAT_3009d068)(DAT_3009d4b4);
        (*DAT_3009d070)(5,0,0,5);
        iVar4 = (*DAT_3009d4b8)();
        if (iVar4 == 0) {
          *DAT_3009d510 = 0;
          return 0;
        }
        (*DAT_3009d070)(6,iVar4,0,8);
        uVar3 = 8;
        uVar2 = 6;
        uVar5 = *DAT_3009d510;
      }
      else {
        uVar3 = 7;
        uVar2 = 6;
        uVar5 = *DAT_3009d510;
      }
    }
    else {
      uVar3 = 4;
    }
  }
  (*DAT_3009d070)(uVar2,iVar4,uVar5,uVar3);
  return iVar4;
}

/* ----------------------------------------------------------------
 * nvim_GetInitState @ 0x3009D530  (примерный размер ~36 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009D530, 0xFFFFFFFF
 * Данные: DAT_3009e0c0
 * ---------------------------------------------------------------- */
undefined4 nvim_GetInitState(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(*DAT_3009e0c0)();
  if (*piVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * nvim_RestoreVersionSetting @ 0x3009D554  (примерный размер ~444 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009D554
 * Данные: DAT_3009e0c4, DAT_3009e0c8, DAT_3009e0cc, DAT_3009e0d0, DAT_3009e0d4, DAT_3009e0d8, DAT_3009e0dc, DAT_3009e0e0
 * ---------------------------------------------------------------- */
int nvim_RestoreVersionSetting(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_14;
  
  iVar1 = (*DAT_3009e0c4)();
  iVar1 = (*DAT_3009e0c8)(&local_14,iVar1 + 0x134,4);
  if (iVar1 == 0) {
    (*DAT_3009e0cc)(DAT_3009e0d4);
    iVar2 = (*DAT_3009e0d8)(local_14);
    if (iVar2 == 0) {
      iVar1 = 0xf;
    }
    else {
      iVar1 = (*DAT_3009e0dc)(iVar2);
      if (iVar1 == 0) {
        (*DAT_3009e0cc)(DAT_3009e0e0,*(undefined2 *)(iVar2 + 0x66));
        if ((*(short *)(iVar2 + 0x66) != 3) && (*(short *)(iVar2 + 0x66) != 2)) {
          (*DAT_3009e0e4)(iVar2);
          return -1;
        }
        *(undefined2 *)(iVar2 + 0x66) = 1;
        iVar1 = (*DAT_3009e0e8)(iVar2);
        if (iVar1 == 0) {
          iVar1 = (*DAT_3009e0f0)(0,iVar2,*(undefined4 *)(iVar2 + 0x134));
          if (iVar1 == 0) {
            iVar1 = (*DAT_3009e0f8)(0,iVar2,*(undefined4 *)(iVar2 + 0x134));
            if (iVar1 != 0) {
              (*DAT_3009e0f4)(8,iVar1,0,10);
            }
          }
          else {
            (*DAT_3009e0f4)(8,iVar1,0,9);
          }
        }
        else {
          (*DAT_3009e0cc)(DAT_3009e0ec,iVar1);
        }
      }
      (*DAT_3009e0e4)(iVar2);
    }
  }
  else {
    (*DAT_3009e0cc)(DAT_3009e0d0,iVar1,local_14);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * nvim_QueryNvFileVersion @ 0x3009D710  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009D710
 * Данные: DAT_3009e0fc, DAT_3009e100
 * ---------------------------------------------------------------- */
undefined4 nvim_QueryNvFileVersion(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_3009e0fc;
  if (param_1 != 0) {
    uVar1 = (*DAT_3009e100)(0x20,param_1,4);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * nvim_GetImei @ 0x3009D740  (примерный размер ~316 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009D740
 * Данные: DAT_3009e104, DAT_3009e108, DAT_3009e10c
 * ---------------------------------------------------------------- */
int nvim_GetImei(int param_1)

{
  byte bVar1;
  byte bVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  int iVar14;
  byte bStack_2e;
  char cStack_2d;
  byte local_2c [16];
  
  uVar9 = 0;
  pbVar6 = local_2c;
  iVar14 = 8;
  pbVar8 = DAT_3009e104;
  do {
    pbVar7 = pbVar8 + 1;
    bVar1 = *pbVar8;
    iVar14 = iVar14 + -1;
    pbVar8 = pbVar8 + 2;
    bVar2 = *pbVar7;
    pbVar7 = pbVar6 + 1;
    *pbVar6 = bVar1;
    pbVar6 = pbVar6 + 2;
    *pbVar7 = bVar2;
  } while (iVar14 != 0);
  iVar14 = (*DAT_3009e108)(0,local_2c,0x10);
  if (iVar14 == 0) {
    uVar4 = 0;
    pbVar8 = &bStack_2e;
    do {
      pbVar6 = pbVar8 + 3;
      pbVar8 = pbVar8 + 2;
      uVar4 = uVar4 + 2;
      uVar9 = uVar9 + *pbVar8 +
              (int)((longlong)(int)((uint)*pbVar6 * 2) * (longlong)DAT_3009e10c >> 0x22) * -9 +
              (uint)*pbVar6 * 2;
    } while (uVar4 < 0xe);
    pcVar11 = (char *)(param_1 + -1);
    iVar10 = 10 - ((uVar9 & 0xff) +
                  (int)((longlong)(int)(uVar9 & 0xff) * (longlong)DAT_3009e10c >> 0x22) * -10);
    lVar3 = (longlong)DAT_3009e10c;
    pcVar13 = &cStack_2d;
    iVar5 = 8;
    do {
      pcVar12 = pcVar13 + 1;
      pcVar13 = pcVar13 + 2;
      pcVar11[1] = *pcVar12 + '0';
      pcVar11 = pcVar11 + 2;
      iVar5 = iVar5 + -1;
      *pcVar11 = *pcVar13 + '0';
    } while (iVar5 != 0);
    *(char *)(param_1 + 0xe) =
         (char)iVar10 + ((char)(int)(iVar10 * lVar3 >> 0x22) - (char)(iVar10 >> 0x1f)) * -10 + '0';
    *(undefined1 *)(param_1 + 0xf) = 0;
  }
  return iVar14;
}

/* ----------------------------------------------------------------
 * nvim_GetInitExportFileInfo @ 0x3009D87C  (примерный размер ~240 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009D87C
 * Данные: DAT_3009e0c4, DAT_3009e0c8, DAT_3009e0cc, DAT_3009e0d0, DAT_3009e0d8, DAT_3009e0dc, DAT_3009e0e4, DAT_3009e0fc
 * ---------------------------------------------------------------- */
int nvim_GetInitExportFileInfo(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  
  iVar1 = DAT_3009e0fc;
  if (param_1 != 0) {
    iVar1 = (*DAT_3009e0c4)();
    iVar1 = (*DAT_3009e0c8)(&local_10,iVar1 + 0x134,4);
    if (iVar1 == 0) {
      iVar2 = (*DAT_3009e0d8)(local_10);
      if (iVar2 == 0) {
        iVar1 = 0xf;
      }
      else {
        iVar1 = (*DAT_3009e0dc)(iVar2);
        if (iVar1 == 0) {
          if (*(short *)(iVar2 + 0x66) == 3) {
            *(undefined2 *)(iVar2 + 0x66) = 0;
            iVar1 = 0;
          }
          else {
            (*DAT_3009e0e4)(iVar2);
            iVar1 = -1;
          }
        }
        else {
          (*DAT_3009e0e4)(iVar2);
        }
      }
    }
    else {
      (*DAT_3009e0cc)(DAT_3009e0d0,iVar1,local_10);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * nvim_GetWorkExportFileInfo @ 0x3009D96C  (примерный размер ~164 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009D96C
 * Данные: DAT_3009e0d8, DAT_3009e100
 * ---------------------------------------------------------------- */
int nvim_GetWorkExportFileInfo(uint *param_1)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  uint local_10;
  
  local_10 = 0;
  iVar1 = (*DAT_3009e100)(0x134,&local_10,4);
  bVar3 = iVar1 == 0;
  if (bVar3) {
    if (0x80000 < local_10) {
      return 0;
    }
    *param_1 = local_10;
    param_1[1] = 0;
    uVar2 = (*DAT_3009e0d8)(local_10);
    param_1[1] = uVar2;
    if (uVar2 == 0) {
      return -1;
    }
    iVar1 = (*DAT_3009e100)(0,uVar2,local_10);
    bVar3 = iVar1 == 0;
  }
  if (bVar3) {
    return 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * nvim_DiagDownLoad @ 0x3009DA10  (примерный размер ~164 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009DA10
 * Данные: DAT_3009e0fc, DAT_3009e110, DAT_3009e114, DAT_3009e118, DAT_3009e11c, DAT_3009e120, DAT_3009e124, DAT_3009e128
 * ---------------------------------------------------------------- */
undefined4 nvim_DiagDownLoad(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_3009e0fc;
  if (param_1 != 0) {
    iVar1 = (*DAT_3009e110)();
    uVar3 = DAT_3009e114;
    if (iVar1 != 0) {
      uVar3 = DAT_3009e118;
    }
    iVar1 = (*DAT_3009e11c)(uVar3,DAT_3009e120);
    uVar3 = DAT_3009e124;
    if (iVar1 != 0) {
      iVar2 = (*DAT_3009e128)(param_1,1,param_2,iVar1);
      (*DAT_3009e12c)(iVar1);
      uVar3 = DAT_3009e130;
      if (iVar2 == param_2) {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * nvim_GetItemLenById @ 0x3009DAB4  (примерный размер ~80 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009DAB4
 * Данные: DAT_3009e0fc, DAT_3009e134
 * ---------------------------------------------------------------- */
int nvim_GetItemLenById(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  undefined2 auStack_18 [2];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  
  iVar1 = DAT_3009e0fc;
  if ((param_2 != (undefined2 *)0x0) &&
     (iVar1 = (*DAT_3009e134)(param_1,auStack_18,auStack_14,auStack_10), iVar1 == 0)) {
    *param_2 = auStack_18[0];
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * nvim_GetNvMainInfo @ 0x3009DB04  (примерный размер ~68 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009DB04
 * Данные: DAT_3009e138
 * ---------------------------------------------------------------- */
undefined4 nvim_GetNvMainInfo(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(*DAT_3009e138)();
  *param_1 = *puVar1;
  iVar2 = (*DAT_3009e138)();
  *param_2 = iVar2 + 0x3e4;
  return 0;
}

/* ----------------------------------------------------------------
 * nvim_GetRevertState @ 0x3009DB48  (примерный размер ~124 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009DB48
 * Данные: DAT_3009e13c, DAT_3009e140, DAT_3009e144, DAT_3009e148, DAT_3009e14c
 * ---------------------------------------------------------------- */
bool nvim_GetRevertState(void)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  
  pcVar1 = DAT_3009e13c;
  cVar2 = *DAT_3009e13c;
  while (cVar2 == '\0') {
    (*DAT_3009e140)(10);
    cVar2 = *pcVar1;
  }
  iVar3 = (*DAT_3009e144)();
  if (iVar3 == 0) {
    (*DAT_3009e148)(1);
  }
  cVar2 = (*DAT_3009e14c)();
  return cVar2 != '\x01';
}

/* ----------------------------------------------------------------
 * nvim_GetAuthorityVer @ 0x3009DBC4  (примерный размер ~64 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009DBC4
 * Данные: DAT_3009e108, DAT_3009e150
 * ---------------------------------------------------------------- */
void nvim_GetAuthorityVer(undefined4 *param_1)

{
  int iVar1;
  
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (*DAT_3009e108)(DAT_3009e150,param_1,4), iVar1 != 0)) {
    *param_1 = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * nvim_GetAuthorityType @ 0x3009DC04  (примерный размер ~64 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009DC04
 * Данные: DAT_3009e108, DAT_3009e154
 * ---------------------------------------------------------------- */
void nvim_GetAuthorityType(undefined4 *param_1)

{
  int iVar1;
  
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (*DAT_3009e108)(DAT_3009e154,param_1,4), iVar1 != 0)) {
    *param_1 = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * nvim_RevertFactoryNV @ 0x3009DED4  (примерный размер ~252 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009DED4
 * Данные: DAT_3009e0c4, DAT_3009e0c8, DAT_3009e0cc, DAT_3009e0d0, DAT_3009e0d8, DAT_3009e0dc, DAT_3009e0e4, DAT_3009e17c
 * ---------------------------------------------------------------- */
int nvim_RevertFactoryNV(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 local_10;
  
  iVar1 = (*DAT_3009e0c4)();
  iVar1 = (*DAT_3009e0c8)(&local_10,iVar1 + 0x134,4);
  if (iVar1 == 0) {
    iVar2 = (*DAT_3009e0d8)(local_10);
    if (iVar2 == 0) {
      iVar1 = 0xf;
    }
    else {
      iVar1 = (*DAT_3009e0dc)(iVar2);
      pcVar3 = DAT_3009e0e4;
      if ((iVar1 == 0) && (iVar1 = (*DAT_3009e17c)(iVar2,0), pcVar3 = DAT_3009e0e4, iVar1 == 0)) {
        (*DAT_3009e0e4)(iVar2);
        iVar1 = (*DAT_3009e184)();
        iVar2 = DAT_3009e188;
        pcVar3 = DAT_3009e0cc;
        if (iVar1 == 0) {
          return 0;
        }
      }
      (*pcVar3)(iVar2);
    }
  }
  else {
    (*DAT_3009e0cc)(DAT_3009e0d0,iVar1,local_10);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * nvim_BackupFactoryNV @ 0x3009DFD0  (примерный размер ~452 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009DFD0
 * Данные: DAT_3009e0c4, DAT_3009e0d8, DAT_3009e0e4, DAT_3009e0fc, DAT_3009e100, DAT_3009e110, DAT_3009e168, DAT_3009e190
 * ---------------------------------------------------------------- */
int nvim_BackupFactoryNV(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_14;
  
  iVar3 = 0;
  iVar1 = (*DAT_3009e100)(0x134,&local_14,4);
  if ((iVar1 == 0) && (iVar1 = DAT_3009e0fc, local_14 < 0x80001)) {
    iVar2 = (*DAT_3009e0d8)(local_14);
    if (iVar2 == 0) {
      iVar1 = 0xf;
    }
    else {
      iVar1 = (*DAT_3009e100)(0,iVar2,local_14);
      if (iVar1 == 0) {
        iVar1 = (*DAT_3009e110)();
        if (iVar1 == 0) {
          iVar1 = (*DAT_3009e190)();
          iVar3 = iVar1 * 0x20000 + 0x80000;
        }
        iVar1 = (*DAT_3009e0c4)();
        iVar1 = (*DAT_3009e168)(iVar2,iVar1 + iVar3,local_14);
      }
      (*DAT_3009e0e4)(iVar2);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Lnvm_SetFlashAddr @ 0x3009E194  (примерный размер ~12 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E194
 * Данные: DAT_3009f0c4
 * ---------------------------------------------------------------- */
void Lnvm_SetFlashAddr(undefined4 param_1)

{
  *DAT_3009f0c4 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * Lnvm_GetFlashAddr @ 0x3009E1A0  (примерный размер ~12 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E1A0
 * Данные: DAT_3009f0c4
 * ---------------------------------------------------------------- */
undefined4 Lnvm_GetFlashAddr(void)

{
  return *DAT_3009f0c4;
}

/* ----------------------------------------------------------------
 * LnvimGetMainInfo @ 0x3009E1AC  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E1AC
 * Данные: DAT_3009f0c8
 * ---------------------------------------------------------------- */
undefined4 LnvimGetMainInfo(void)

{
  return DAT_3009f0c8;
}

/* ----------------------------------------------------------------
 * LnvimCreateIndexInfo @ 0x3009E1B4  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E1B4, 0xFFFFFFFF
 * Данные: DAT_3009f0cc, DAT_3009f0d0
 * ---------------------------------------------------------------- */
undefined4 LnvimCreateIndexInfo(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*DAT_3009f0cc)(1,1);
  *DAT_3009f0d0 = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * LnvimCreateNvASynIndexInfo @ 0x3009E1E4  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E1E4, 0xFFFFFFFF
 * Данные: DAT_3009f0cc, DAT_3009f0d4
 * ---------------------------------------------------------------- */
undefined4 LnvimCreateNvASynIndexInfo(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*DAT_3009f0cc)(0,1);
  *DAT_3009f0d4 = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * LnvimLockIndexInfo @ 0x3009E214  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E214
 * Данные: DAT_3009f0d0, DAT_3009f0d8, DAT_3009f0dc
 * ---------------------------------------------------------------- */
void LnvimLockIndexInfo(void)

{
  (*DAT_3009f0d8)(*DAT_3009f0d0);
  *DAT_3009f0dc = *DAT_3009f0dc + 1;
  return;
}

/* ----------------------------------------------------------------
 * LnvimUnLockIndexInfo @ 0x3009E244  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E244
 * Данные: DAT_3009f0d0, DAT_3009f1b0, DAT_3009f1b4
 * ---------------------------------------------------------------- */
void LnvimUnLockIndexInfo(void)

{
  (*DAT_3009f1b0)(*DAT_3009f0d0);
  *DAT_3009f1b4 = *DAT_3009f1b4 + 1;
  return;
}

/* ----------------------------------------------------------------
 * nvimDimidiateSearch @ 0x3009E274  (примерный размер ~304 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E274, 0xFFFFFFFF
 * Данные: DAT_3009f0c8, DAT_3009f1b8, DAT_3009f1bc, DAT_3009f1c0
 * ---------------------------------------------------------------- */
undefined4 nvimDimidiateSearch(int param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  *param_3 = 0xffffffff;
  if (param_2 == 0) {
    uVar3 = 500;
  }
  else {
    param_2 = param_2 & 0xffff;
    uVar4 = 0;
    if ((param_1 < (int)(uint)*(ushort *)(DAT_3009f0c8 + 0x3e4)) ||
       ((int)(uint)*(ushort *)(DAT_3009f0c8 + param_2 * 0xc + 0x3d8) < param_1)) {
      (*DAT_3009f1b8)(DAT_3009f1bc);
    }
    else {
      do {
        uVar1 = (uVar4 + param_2) / 2;
        uVar2 = *(ushort *)(uVar1 * 0xc + DAT_3009f0c8 + 0x3e4);
        while (param_1 < (int)(uint)uVar2) {
          param_2 = uVar1 + DAT_3009f1c0 & 0xffff;
          if (param_2 < uVar4) goto LAB_3009e398;
          uVar1 = (uVar4 + param_2) / 2;
          uVar2 = *(ushort *)(uVar1 * 0xc + DAT_3009f0c8 + 0x3e4);
        }
        if (param_1 <= (int)(uint)uVar2) {
          *param_3 = uVar1;
          return 0;
        }
        uVar4 = uVar1 + 1 & 0xffff;
      } while (uVar4 <= param_2);
    }
LAB_3009e398:
    uVar3 = 0x208;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * LnvmSearchById @ 0x3009E3A4  (примерный размер ~96 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E3A4
 * Данные: DAT_3009f0c8, DAT_3009f304, DAT_3009f308
 * ---------------------------------------------------------------- */
int LnvmSearchById(undefined4 param_1,undefined2 *param_2,undefined4 *param_3,int *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = DAT_3009f0c8;
  iVar2 = (*DAT_3009f304)(param_1,*DAT_3009f0c8,param_4);
  if (iVar2 == 0) {
    iVar3 = *param_4;
    iVar2 = 0;
    *param_2 = *(undefined2 *)((int)puVar1 + DAT_3009f308 + iVar3 * 0xc);
    *param_3 = puVar1[iVar3 * 3 + 0xfa];
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_3009e404 @ 0x3009E404  (примерный размер ~100 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E404
 * Данные: DAT_3009f0c8
 * ---------------------------------------------------------------- */
undefined4 FUN_3009e404(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar1 = DAT_3009f0c8 + 4;
  if ((param_1 < *(uint *)(DAT_3009f0c8 + 0x48)) || (*(uint *)(DAT_3009f0c8 + 0x4c) < param_1)) {
    do {
      iVar3 = iVar1;
      uVar2 = uVar2 + 1;
      if (7 < uVar2) break;
      iVar1 = iVar3 + 0x7c;
    } while ((param_1 < *(uint *)(iVar3 + 0xc0)) || (*(uint *)(iVar3 + 0xc4) < param_1));
    if (uVar2 == 8) {
      return 0x208;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * LnvmIndexOrder @ 0x3009E468  (примерный размер ~384 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E468
 * Данные: DAT_3009f0c8, DAT_3009f414, DAT_3009f418, DAT_3009f41c, DAT_3009f420, DAT_3009f424, DAT_3009f544
 * ---------------------------------------------------------------- */
int LnvmIndexOrder(int param_1,uint *param_2)

{
  undefined2 uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  
  puVar2 = DAT_3009f0c8;
  uVar4 = *DAT_3009f0c8;
  iVar3 = DAT_3009f414;
  if ((uVar4 + 1 < 0x7d1) && (iVar3 = (*DAT_3009f418)(), iVar3 == 0)) {
    uVar1 = (undefined2)param_1;
    if (uVar4 == 0) {
      *(undefined2 *)(puVar2 + 0xf9) = uVar1;
      *param_2 = 0;
      *puVar2 = *puVar2 + 1;
    }
    else if ((int)(uint)(ushort)puVar2[uVar4 * 3 + 0xf6] < param_1) {
      *(undefined2 *)(puVar2 + uVar4 * 3 + 0xf9) = uVar1;
      *param_2 = *puVar2;
      *puVar2 = *puVar2 + 1;
    }
    else {
      iVar3 = (*DAT_3009f41c)(DAT_3009f420);
      if (iVar3 == 0) {
        return 0xf;
      }
      uVar4 = 0;
      *param_2 = 0;
      if (*puVar2 != 0) {
        puVar5 = puVar2 + 0xf9;
        do {
          if (param_1 < (int)(uint)(ushort)*puVar5) {
            *param_2 = uVar4;
            break;
          }
          puVar5 = puVar5 + 3;
          uVar4 = uVar4 + 1;
        } while (uVar4 < *puVar2);
      }
      iVar6 = (*puVar2 - *param_2) * 0xc;
      (*DAT_3009f424)(iVar3,puVar2 + *param_2 * 3 + 0xf9,iVar6);
      uVar4 = *param_2;
      *(undefined2 *)(puVar2 + uVar4 * 3 + 0xf9) = uVar1;
      (*DAT_3009f424)(puVar2 + uVar4 * 3 + 0xfc,iVar3,iVar6);
      *puVar2 = *puVar2 + 1;
      (*DAT_3009f544)(iVar3);
    }
    iVar3 = 0;
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * Lnvm_ReadFromMemory @ 0x3009E5E8  (примерный размер ~124 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E5E8
 * Данные: DAT_3009f424, DAT_3009f548, DAT_3009f54c, DAT_3009f550
 * ---------------------------------------------------------------- */
undefined4 Lnvm_ReadFromMemory(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(char *)*DAT_3009f548 == '\x01') {
    (*DAT_3009f54c)(3,1,0,1);
    (*DAT_3009f424)(param_2,*DAT_3009f550 + param_1,param_3);
    uVar1 = 0;
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Lnvm_WriteToMemroy @ 0x3009E664  (примерный размер ~196 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E664
 * Данные: DAT_3009f424, DAT_3009f548, DAT_3009f54c, DAT_3009f550, DAT_3009f554, DAT_3009f558, DAT_3009f55c
 * ---------------------------------------------------------------- */
undefined4 Lnvm_WriteToMemroy(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(char *)*DAT_3009f548 == '\x01') {
    if (DAT_3009f554 < (uint)(param_1 + param_3)) {
      (*DAT_3009f54c)(4,param_1,param_3,0x10);
      uVar1 = DAT_3009f558;
    }
    else {
      (*DAT_3009f54c)(3,param_1,param_3,2);
      (*DAT_3009f55c)(0);
      (*DAT_3009f424)(*DAT_3009f550 + param_1,param_2,param_3);
      (*DAT_3009f55c)(1);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Lnvm_WriteToHNV @ 0x3009E728  (примерный размер ~204 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E728
 * Данные: DAT_3009f698, DAT_3009f69c, DAT_3009f6a0, DAT_3009f6a4, DAT_3009f6a8, DAT_3009f6ac, DAT_3009f6b0, DAT_3009f6b4
 * ---------------------------------------------------------------- */
int Lnvm_WriteToHNV(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = (*DAT_3009f698)();
  uVar4 = DAT_3009f69c;
  if (iVar1 != 0) {
    uVar4 = DAT_3009f6a0;
  }
  iVar2 = (*DAT_3009f6a4)(uVar4,DAT_3009f6a8);
  iVar1 = DAT_3009f6ac;
  if (iVar2 != 0) {
    iVar1 = (*DAT_3009f6b0)(iVar2,param_1,0);
    if ((iVar1 == 0) && (iVar3 = (*DAT_3009f6b4)(param_2,1,param_3,iVar2), iVar3 != param_3)) {
      (*DAT_3009f6b8)(iVar2);
      iVar1 = DAT_3009f6bc;
    }
    else {
      (*DAT_3009f6b8)(iVar2);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Lnv_Read_Backup_Data_From_Flash @ 0x3009E7F4  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E7F4
 * Данные: DAT_3009f6c0
 * ---------------------------------------------------------------- */
void Lnv_Read_Backup_Data_From_Flash(void)

{
  (*DAT_3009f6c0)();
  return;
}

/* ----------------------------------------------------------------
 * Lnv_Read_Backup_Data_From_File @ 0x3009E808  (примерный размер ~236 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E808
 * Данные: DAT_3009f0c4, DAT_3009f54c, DAT_3009f6a4, DAT_3009f6ac, DAT_3009f6b0, DAT_3009f6b8, DAT_3009f6c4, DAT_3009f6c8
 * ---------------------------------------------------------------- */
undefined4 Lnv_Read_Backup_Data_From_File(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (*DAT_3009f6a4)(DAT_3009f6c4,DAT_3009f6c8);
  if (iVar1 == 0) {
    (*DAT_3009f54c)(6,0,0,3);
    uVar3 = DAT_3009f6ac;
  }
  else {
    (*DAT_3009f6b0)(iVar1,param_2 - *DAT_3009f0c4,0);
    iVar2 = (*DAT_3009f7c0)(param_1,1,param_3,iVar1);
    if (iVar2 == param_3) {
      (*DAT_3009f6b8)(iVar1,iVar2);
      uVar3 = 0;
    }
    else {
      (*DAT_3009f54c)(6,iVar2,param_3,4);
      (*DAT_3009f6b8)(iVar1);
      uVar3 = DAT_3009f7c4;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * Lnvm_NandIsBad @ 0x3009E8F4  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E8F4
 * Данные: DAT_3009f7c8
 * ---------------------------------------------------------------- */
void Lnvm_NandIsBad(void)

{
  (*DAT_3009f7c8)();
  return;
}

/* ----------------------------------------------------------------
 * Lnvm_NandBadCount @ 0x3009E908  (примерный размер ~100 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E908
 * Данные: DAT_3009f0c4, DAT_3009f7c8
 * ---------------------------------------------------------------- */
int Lnvm_NandBadCount(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_10;
  
  iVar2 = 0;
  local_10 = 0;
  uVar3 = 0;
  do {
    iVar1 = (*DAT_3009f7c8)(*DAT_3009f0c4 + uVar3 * 0x20000 >> 0x11,&local_10);
    if ((local_10 == 1) && (iVar1 == 0)) {
      iVar2 = iVar2 + 1;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
  return iVar2;
}

/* ----------------------------------------------------------------
 * Lnv_Backup_To_Flash @ 0x3009E96C  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E96C
 * Данные: DAT_3009f7cc
 * ---------------------------------------------------------------- */
void Lnv_Backup_To_Flash(undefined4 param_1,undefined4 param_2)

{
  (*DAT_3009f7cc)(param_2,param_1);
  return;
}

/* ----------------------------------------------------------------
 * Lnv_Backup_To_File @ 0x3009E98C  (примерный размер ~232 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009E98C
 * Данные: DAT_3009f0c4, DAT_3009f54c, DAT_3009f6a4, DAT_3009f6ac, DAT_3009f6b0, DAT_3009f6b4, DAT_3009f6b8, DAT_3009f6c4
 * ---------------------------------------------------------------- */
undefined4 Lnv_Backup_To_File(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (*DAT_3009f6a4)(DAT_3009f6c4,DAT_3009f8e4);
  if (iVar1 == 0) {
    (*DAT_3009f54c)(6,0,0,1);
    uVar3 = DAT_3009f6ac;
  }
  else {
    (*DAT_3009f6b0)(iVar1,param_2 - *DAT_3009f0c4,0);
    iVar2 = (*DAT_3009f6b4)(param_1,1,param_3,iVar1);
    if (iVar2 == param_3) {
      uVar3 = (*DAT_3009f6b8)(iVar1,iVar2);
    }
    else {
      (*DAT_3009f54c)(6,iVar2,param_3,2);
      (*DAT_3009f6b8)(iVar1);
      uVar3 = DAT_3009f7c4;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * Lnv_Write_To_Backup_Domain @ 0x3009EA74  (примерный размер ~100 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009EA74
 * Данные: DAT_3009f698, DAT_3009f7cc, DAT_3009f9ac
 * ---------------------------------------------------------------- */
void Lnv_Write_To_Backup_Domain(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (*DAT_3009f698)();
  if (iVar1 == 0) {
    (*DAT_3009f7cc)(param_2,param_1,param_3);
  }
  else {
    (*DAT_3009f9ac)(param_1,param_2,param_3);
  }
  return;
}

/* ----------------------------------------------------------------
 * Lnv_Read_From_Backup_Domain @ 0x3009EAD8  (примерный размер ~100 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009EAD8
 * Данные: DAT_3009f698, DAT_3009f6c0, DAT_3009f9b0
 * ---------------------------------------------------------------- */
void Lnv_Read_From_Backup_Domain(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (*DAT_3009f698)();
  if (iVar1 == 0) {
    (*DAT_3009f6c0)(param_1,param_2,param_3);
  }
  else {
    (*DAT_3009f9b0)(param_1,param_2,param_3);
  }
  return;
}

/* ----------------------------------------------------------------
 * Lnvm_ReadBackUpData @ 0x3009EB3C  (примерный размер ~244 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009EB3C
 * Данные: DAT_3009f0c4, DAT_3009f1b8, DAT_3009f414, DAT_3009f698, DAT_3009f6c0, DAT_3009f9b0, DAT_3009fa90, DAT_3009fa94
 * ---------------------------------------------------------------- */
int Lnvm_ReadBackUpData(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  uint local_18;
  
  piVar1 = DAT_3009f0c4;
  iVar3 = *DAT_3009f0c4;
  iVar2 = (*DAT_3009f698)();
  pcVar4 = DAT_3009f6c0;
  if (iVar2 != 0) {
    pcVar4 = DAT_3009f9b0;
  }
  iVar2 = (*pcVar4)(&local_18,iVar3 + 0x134,4);
  if (iVar2 == 0) {
    if (local_18 < 0x80001) {
      iVar3 = *piVar1;
      iVar2 = (*DAT_3009f698)();
      pcVar4 = DAT_3009f6c0;
      if (iVar2 != 0) {
        pcVar4 = DAT_3009f9b0;
      }
      iVar2 = (*pcVar4)(param_1,iVar3,local_18);
      if (iVar2 != 0) {
        (*DAT_3009f1b8)(DAT_3009fa98,iVar2);
      }
    }
    else {
      (*DAT_3009f1b8)(DAT_3009fa94,0,local_18);
      iVar2 = DAT_3009f414;
    }
  }
  else {
    (*DAT_3009f1b8)(DAT_3009fa90,iVar2,local_18);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * Lnvm_Read_FactoryNV_From_Backup_Domain @ 0x3009EC30  (примерный размер ~240 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009EC30
 * Данные: DAT_3009f0c4, DAT_3009f1b8, DAT_3009f414, DAT_3009f698, DAT_3009f6c0, DAT_3009f9b0, DAT_3009fa9c, DAT_3009fbf8
 * ---------------------------------------------------------------- */
int Lnvm_Read_FactoryNV_From_Backup_Domain(undefined4 param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  uint local_1c;
  
  iVar4 = 0;
  local_1c = 0;
  iVar3 = (*DAT_3009f698)();
  if (iVar3 == 0) {
    iVar3 = (*DAT_3009fa9c)();
    iVar4 = iVar3 * 0x20000 + 0x80000;
  }
  piVar1 = DAT_3009f0c4;
  iVar5 = *DAT_3009f0c4;
  iVar3 = (*DAT_3009f698)();
  pcVar6 = DAT_3009f6c0;
  if (iVar3 != 0) {
    pcVar6 = DAT_3009f9b0;
  }
  iVar3 = (*pcVar6)(&local_1c,iVar5 + iVar4 + 0x134,4);
  uVar2 = local_1c;
  if (iVar3 == 0) {
    if (local_1c < 0x80001) {
      iVar5 = *piVar1;
      iVar3 = (*DAT_3009f698)();
      pcVar6 = DAT_3009f6c0;
      if (iVar3 != 0) {
        pcVar6 = DAT_3009f9b0;
      }
      iVar3 = (*pcVar6)(param_1,iVar5 + iVar4,uVar2);
    }
    else {
      (*DAT_3009f1b8)(DAT_3009fbf8,local_1c);
      iVar3 = DAT_3009f414;
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * Lnvm_SetRestoreFlag @ 0x3009ED20  (примерный размер ~12 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009ED20
 * Данные: DAT_3009fbfc
 * ---------------------------------------------------------------- */
void Lnvm_SetRestoreFlag(undefined1 param_1)

{
  *DAT_3009fbfc = param_1;
  return;
}

/* ----------------------------------------------------------------
 * Lnvm_IsRestoreOK @ 0x3009ED2C  (примерный размер ~12 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009ED2C
 * Данные: DAT_3009fbfc
 * ---------------------------------------------------------------- */
undefined1 Lnvm_IsRestoreOK(void)

{
  return *DAT_3009fbfc;
}

/* ----------------------------------------------------------------
 * Lnvm_SetFileOption @ 0x3009ED38  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009ED38
 * Данные: DAT_3009f1b8, DAT_3009fc00, DAT_3009fc04
 * ---------------------------------------------------------------- */
void Lnvm_SetFileOption(undefined2 param_1)

{
  int iVar1;
  undefined2 local_4 [2];
  
  local_4[0] = param_1;
  iVar1 = (*DAT_3009fc00)(0x66,local_4,2);
  if (iVar1 != 0) {
    (*DAT_3009f1b8)(DAT_3009fc04,iVar1);
  }
  return;
}

/* ----------------------------------------------------------------
 * Lnvm_RestoreNoPrioFactoryNv @ 0x3009ED90  (примерный размер ~408 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009ED90
 * Данные: DAT_3009f414, DAT_3009f424, DAT_3009f54c, DAT_3009fcc8, DAT_3009fccc, DAT_3009fcd0, DAT_3009fcd4
 * ---------------------------------------------------------------- */
int Lnvm_RestoreNoPrioFactoryNv(int param_1,char param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  int iVar5;
  int local_9c [17];
  uint local_58;
  uint local_54;
  ushort local_50;
  
  iVar5 = 0x1a0;
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      (*DAT_3009f424)(local_9c,param_1 + iVar5,0x7c);
      uVar3 = (uint)local_50;
      iVar5 = iVar5 + 0x7c;
      if (local_9c[0] == 0) {
        (*DAT_3009f54c)(4,0,0,0x17);
        return DAT_3009f414;
      }
      if ((0xe4ff < local_58) && (local_54 <= DAT_3009fcc8)) {
        while( true ) {
          if (uVar3 == 0) {
            return 0;
          }
          puVar4 = (undefined2 *)(param_1 + iVar5);
          iVar5 = iVar5 + 4;
          if (param_2 == '\0') {
            iVar1 = (*DAT_3009fccc)(*puVar4,param_1 + iVar5,puVar4[1]);
          }
          else if (param_2 == '\x02') {
            iVar1 = (*DAT_3009fcd0)(*puVar4,param_1 + iVar5,puVar4[1]);
          }
          else {
            (*DAT_3009f54c)(4,0,param_2,0x18);
            iVar1 = DAT_3009fcd4;
          }
          if ((iVar1 != 0) && (iVar1 != 0x208)) break;
          uVar3 = uVar3 - 1;
          iVar5 = iVar5 + (uint)(ushort)puVar4[1];
        }
        (*DAT_3009f54c)(4,0,iVar1,0x19);
        return iVar1;
      }
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        iVar5 = iVar5 + (uint)*(ushort *)(param_1 + iVar5 + 2) + 4;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_3);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * Lnvm_RestorePrioFactoryNv @ 0x3009EF28  (примерный размер ~504 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009EF28
 * Данные: DAT_3009f1b8, DAT_3009f414, DAT_3009f424, DAT_3009f54c, DAT_3009fcc8, DAT_3009fccc, DAT_3009fcd0, DAT_3009fcd4
 * ---------------------------------------------------------------- */
int Lnvm_RestorePrioFactoryNv(int param_1,char param_2,ushort param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  int iVar5;
  int local_9c [17];
  uint local_58;
  uint local_54;
  ushort local_50;
  
  iVar5 = 0x1a0;
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      (*DAT_3009f424)(local_9c,param_1 + iVar5,0x7c);
      uVar3 = (uint)local_50;
      iVar5 = iVar5 + 0x7c;
      (*DAT_3009f1b8)(DAT_3009fcd8,uVar2,(uint)param_3);
      (*DAT_3009f1b8)(DAT_3009fcdc,local_9c[0]);
      if (local_9c[0] == 0) {
        (*DAT_3009f54c)(4,0,0,0x17);
        return DAT_3009f414;
      }
      if ((0xe4ff < local_58) && (local_54 <= DAT_3009fcc8)) {
        while( true ) {
          if (uVar3 == 0) {
            return 0;
          }
          puVar4 = (undefined2 *)(param_1 + iVar5);
          iVar5 = iVar5 + 8;
          if (param_2 == '\0') {
            iVar1 = (*DAT_3009fccc)(*puVar4,param_1 + iVar5,puVar4[1]);
          }
          else if (param_2 == '\x02') {
            iVar1 = (*DAT_3009fcd0)(*puVar4,param_1 + iVar5,puVar4[1]);
          }
          else {
            (*DAT_3009f54c)(4,0,param_2,0x18);
            iVar1 = DAT_3009fcd4;
          }
          if ((iVar1 != 0) && (iVar1 != 0x208)) break;
          uVar3 = uVar3 - 1;
          iVar5 = iVar5 + (uint)(ushort)puVar4[1];
        }
        (*DAT_3009f54c)(4,0,iVar1,0x19);
        return iVar1;
      }
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        iVar5 = iVar5 + (uint)*(ushort *)(param_1 + iVar5 + 2) + 8;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_3);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * Lnvm_RestoreFactoryNv @ 0x3009F120  (примерный размер ~316 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009F120
 * Данные: DAT_3009f414, DAT_3009f424, DAT_3009f54c, DAT_3009fce0, DAT_3009fce4
 * ---------------------------------------------------------------- */
undefined4 Lnvm_RestoreFactoryNv(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  ushort local_18 [2];
  uint local_14;
  int local_10;
  
  local_10 = 0;
  local_18[0] = 0;
  if (param_1 == 0) {
    (*DAT_3009f54c)(4,0,0,0x14);
    uVar1 = DAT_3009f414;
  }
  else {
    (*DAT_3009f424)(&local_14,param_1 + 0x134,4);
    if (local_14 < 0x80000) {
      (*DAT_3009f424)(local_18,param_1 + 100,2);
      if ((local_18[0] == 0) || (8 < local_18[0])) {
        (*DAT_3009f54c)(4,0,local_18[0],0x16);
        uVar1 = DAT_3009f414;
      }
      else {
        (*DAT_3009f424)(&local_10,param_1 + 0x17c,4);
        pcVar2 = DAT_3009fce0;
        if (local_10 != 0) {
          pcVar2 = DAT_3009fce4;
        }
        uVar1 = (*pcVar2)(param_1,param_2,local_18[0]);
      }
    }
    else {
      (*DAT_3009f54c)(4,0,local_14,0x15);
      uVar1 = DAT_3009f414;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Lnvm_SetUpgradeOpFlag @ 0x3009F358  (примерный размер ~12 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009F358
 * Данные: DAT_3009fcf0
 * ---------------------------------------------------------------- */
void Lnvm_SetUpgradeOpFlag(undefined1 param_1)

{
  *DAT_3009fcf0 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * Lnvm_GetUpgradeOpFlag @ 0x3009F364  (примерный размер ~12 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009F364
 * Данные: DAT_3009fcf0
 * ---------------------------------------------------------------- */
undefined1 Lnvm_GetUpgradeOpFlag(void)

{
  return *DAT_3009fcf0;
}

/* ----------------------------------------------------------------
 * Lnvm_NoPrioFileCheck @ 0x3009F370  (примерный размер ~348 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009F370, 0xFFFFFFFF
 * Данные: DAT_3009f424, DAT_3009f548, DAT_3009f54c, DAT_3009f550, DAT_3009fcf4, DAT_3009fcf8, DAT_3009fcfc, DAT_3009fd00
 * ---------------------------------------------------------------- */
undefined4 Lnvm_NoPrioFileCheck(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  int iVar5;
  short local_28;
  ushort local_26;
  
  iVar5 = 0x1a0;
  if (param_2 != 0) {
    do {
      puVar1 = DAT_3009f548;
      iVar2 = param_1 + iVar5;
      iVar5 = iVar5 + 0x7c;
      uVar3 = 0;
      if (*(short *)(iVar2 + 0x4c) != 0) {
        do {
          psVar4 = (short *)(param_1 + iVar5);
          if (*(char *)*puVar1 != '\x01') {
            (*DAT_3009fcf4)(DAT_3009fcf8,3);
            return 3;
          }
          (*DAT_3009f54c)(3,1,0,1);
          (*DAT_3009f424)(&local_28,*DAT_3009f550 + iVar5,4);
          if ((local_28 != *psVar4) || ((uint)(ushort)psVar4[1] != (uint)local_26)) {
            (*DAT_3009fcf4)(DAT_3009fcfc,*psVar4,psVar4[1]);
            (*DAT_3009fcf4)(DAT_3009fd00,local_28,local_26);
            (*DAT_3009fcf4)(DAT_3009fd04,iVar5);
            return 0xffffffff;
          }
          uVar3 = uVar3 + 1;
          iVar5 = iVar5 + (uint)(ushort)psVar4[1] + 4;
        } while (uVar3 < *(ushort *)(iVar2 + 0x4c));
      }
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * Lnvm_PrioFileCheck @ 0x3009F4CC  (примерный размер ~352 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009F4CC, 0xFFFFFFFF
 * Данные: DAT_3009f548, DAT_3009f54c, DAT_3009f550, DAT_3009fcf4, DAT_3009fcfc, DAT_3009fd00, DAT_3009fd04, DAT_3009fd08
 * ---------------------------------------------------------------- */
undefined4 Lnvm_PrioFileCheck(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  short *psVar3;
  int iVar4;
  short local_28;
  ushort local_26;
  
  iVar4 = 0x1a0;
  if (param_2 != 0) {
    do {
      iVar1 = param_1 + iVar4;
      iVar4 = iVar4 + 0x7c;
      uVar2 = 0;
      if (*(short *)(iVar1 + 0x4c) != 0) {
        do {
          psVar3 = (short *)(param_1 + iVar4);
          if (*(char *)*DAT_3009f548 != '\x01') {
            (*DAT_3009fcf4)(DAT_3009fd0c,3);
            return 3;
          }
          (*DAT_3009f54c)(3,1,0,1);
          (*DAT_3009fd08)(&local_28,*DAT_3009f550 + iVar4,8);
          if ((local_28 != *psVar3) || ((uint)(ushort)psVar3[1] != (uint)local_26)) {
            (*DAT_3009fcf4)(DAT_3009fcfc,*psVar3,psVar3[1]);
            (*DAT_3009fcf4)(DAT_3009fd00,local_28,local_26);
            (*DAT_3009fcf4)(DAT_3009fd04,iVar4);
            return 0xffffffff;
          }
          uVar2 = uVar2 + 1;
          iVar4 = iVar4 + (uint)(ushort)psVar3[1] + 8;
        } while (uVar2 < *(ushort *)(iVar1 + 0x4c));
      }
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * Lnvm_FileCheck @ 0x3009F62C  (примерный размер ~296 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009F62C
 * Данные: DAT_3009fcf4, DAT_3009fd08, DAT_3009fd10, DAT_3009fd14, DAT_3009fd18, DAT_3009fd1c, DAT_3009fd20, DAT_3009fd24
 * ---------------------------------------------------------------- */
int Lnvm_FileCheck(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  code *pcVar3;
  int local_14;
  
  local_14 = 0;
  iVar2 = DAT_3009fd10;
  if (param_1 != 0) {
    if (*(char *)*DAT_3009fd14 == '\x01') {
      (*DAT_3009fd18)(3,1,0,1);
      (*DAT_3009fd08)(&local_14,*DAT_3009fd1c + 0x134,4);
      iVar2 = 0;
    }
    else {
      iVar2 = 3;
    }
    if ((iVar2 == 0) && (iVar2 = DAT_3009fd20, *(int *)(param_1 + 0x134) == local_14)) {
      iVar2 = *(int *)(param_1 + 0x17c);
      uVar1 = *(undefined2 *)(param_1 + 100);
      (*DAT_3009fcf4)(DAT_3009fd24,iVar2,uVar1);
      pcVar3 = DAT_3009fd28;
      if (iVar2 != 0) {
        pcVar3 = DAT_3009fd2c;
      }
      iVar2 = (*pcVar3)(param_1,uVar1);
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * Lnvm_SetUpgradeRestoreFlags @ 0x3009F754  (примерный размер ~44 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009F754
 * Данные: DAT_3009fbfc, DAT_3009fd30
 * ---------------------------------------------------------------- */
void Lnvm_SetUpgradeRestoreFlags(void)

{
  char cVar1;
  
  cVar1 = (*DAT_3009fd30)();
  *(bool *)DAT_3009fbfc = cVar1 == '\0';
  return;
}

/* ----------------------------------------------------------------
 * Lnvm_InitMainInfo @ 0x3009F780  (примерный размер ~912 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009F780
 * Данные: DAT_3009fd08, DAT_3009fd14, DAT_3009fd18, DAT_3009fd1c, DAT_3009fd34, DAT_3009fd38, DAT_3009fd3c, DAT_3009fd40
 * ---------------------------------------------------------------- */
uint Lnvm_InitMainInfo(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int unaff_r8;
  ushort uVar6;
  int iVar7;
  uint local_40;
  undefined2 local_3c;
  ushort local_3a;
  int local_38;
  int local_34;
  int local_30;
  undefined2 local_2c;
  ushort local_2a;
  undefined2 local_28;
  undefined2 local_26;
  
  iVar2 = DAT_3009fd3c;
  local_3c = *DAT_3009fd34;
  local_3a = DAT_3009fd34[1];
  local_2c = *DAT_3009fd38;
  local_2a = DAT_3009fd38[1];
  local_28 = DAT_3009fd38[2];
  local_26 = DAT_3009fd38[3];
  local_34 = 0;
  (*DAT_3009fd40)(DAT_3009fd3c,0,DAT_3009fd44);
  iVar5 = *DAT_3009fd1c;
  if (iVar5 == 0) {
    uVar3 = 4;
  }
  else {
    if (*(char *)*DAT_3009fd14 == '\x01') {
      (*DAT_3009fd18)(3,1,0,1);
      (*DAT_3009fd08)(&local_34,*DAT_3009fd1c + 0x17c,4);
      local_40 = 0;
    }
    else {
      local_40 = 3;
    }
    iVar7 = 0x1a0;
    uVar3 = local_40;
    if (local_40 == 0) {
      local_40 = 0;
      if (local_34 == 0) {
        if (*(short *)(iVar5 + 100) != 0) {
          do {
            (*DAT_3009fd08)(local_40 * 0x7c + iVar2 + 4,iVar5 + iVar7);
            if (*(int *)(local_40 * 0x7c + iVar2 + 4) == 0) {
              return -1;
            }
            iVar7 = iVar7 + 0x7c;
            uVar1 = *(ushort *)(local_40 * 0x7c + iVar2 + 0x50);
            uVar6 = 0;
            local_38 = unaff_r8;
            if (uVar1 != 0) {
              local_30 = DAT_3009fd48;
              do {
                (*DAT_3009fd08)(&local_3c,iVar5 + iVar7,4);
                local_38 = unaff_r8;
                iVar4 = (*DAT_3009fd4c)(local_3c,&local_38);
                if (iVar4 != 0) {
                  return iVar4;
                }
                iVar4 = local_38 * 0xc + iVar2;
                *(int *)(iVar4 + 1000) = iVar7 + 4;
                uVar6 = uVar6 + 1;
                *(ushort *)(iVar4 + local_30) = local_3a;
                iVar7 = iVar7 + 4 + (uint)local_3a;
                unaff_r8 = local_38;
              } while (uVar6 < uVar1);
            }
            local_40 = local_40 + 1;
            unaff_r8 = local_38;
          } while (local_40 < *(ushort *)(iVar5 + 100));
        }
      }
      else if (*(short *)(iVar5 + 100) != 0) {
        do {
          iVar4 = local_40 * 0x7c + iVar2;
          (*DAT_3009fd08)(iVar4 + 4,iVar5 + iVar7,0x7c);
          if (*(int *)(iVar4 + 4) == 0) {
            (*DAT_3009fd18)(6,0,0,0xc);
            return -1;
          }
          uVar1 = *(ushort *)(iVar4 + 0x50);
          iVar7 = iVar7 + 0x7c;
          uVar6 = 0;
          local_38 = unaff_r8;
          if (uVar1 != 0) {
            do {
              (*DAT_3009fd08)(&local_2c,iVar5 + iVar7,8);
              local_38 = unaff_r8;
              uVar3 = (*DAT_3009fd4c)(local_2c,&local_38);
              if (uVar3 != 0) goto LAB_3009fa78;
              iVar4 = local_38 * 0xc + iVar2;
              *(int *)(iVar4 + 1000) = iVar7 + 8;
              *(ushort *)(iVar4 + DAT_3009fd48) = local_2a;
              *(undefined2 *)(iVar4 + 0x3ec) = local_26;
              uVar6 = uVar6 + 1;
              *(undefined2 *)(iVar4 + DAT_3009fd50) = local_28;
              iVar7 = iVar7 + 8 + (uint)local_2a;
              unaff_r8 = local_38;
            } while (uVar6 < uVar1);
          }
          local_40 = local_40 + 1;
          unaff_r8 = local_38;
        } while (local_40 < *(ushort *)(iVar5 + 100));
      }
      uVar3 = 0;
    }
    else {
LAB_3009fa78:
      (*DAT_3009fd18)(6,uVar3);
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * nvim_ShowNvimInfo @ 0x3009FB10  (примерный размер ~628 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009FB10
 * Данные: DAT_3009fcf4, DAT_3009fd3c, DAT_3009fd48, DAT_3009fd50, DAT_3009fd54, DAT_3009fd58, DAT_3009fd5c, DAT_3009fd60
 * ---------------------------------------------------------------- */
undefined4 nvim_ShowNvimInfo(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  
  puVar1 = DAT_3009fd3c;
  (*DAT_3009fcf4)(DAT_3009fd54);
  (*DAT_3009fcf4)(DAT_3009fd58,*puVar1);
  uVar5 = 0;
  puVar4 = puVar1;
  do {
    (*DAT_3009fcf4)(DAT_3009fd5c,uVar5,puVar4[0x12]);
    (*DAT_3009fcf4)(DAT_3009fd60,uVar5,puVar4[0x13]);
    (*DAT_3009fcf4)(DAT_3009fd64,uVar5,(short)puVar4[0x14]);
    (*DAT_3009fcf4)(DAT_3009fd68,uVar5,puVar4[0x1f]);
    (*DAT_3009fcf4)(DAT_3009fd6c,uVar5,puVar4[1]);
    uVar5 = uVar5 + 1;
    puVar4 = puVar4 + 0x1f;
  } while (uVar5 < 2);
  (*DAT_3009fcf4)(DAT_3009fd54);
  iVar3 = DAT_3009fd50;
  iVar2 = DAT_3009fd48;
  uVar5 = 0;
  puVar4 = puVar1;
  if (*puVar1 != 0) {
    do {
      (*DAT_3009fcf4)(DAT_3009fd70,uVar5,(short)puVar4[0xf9]);
      (*DAT_3009fcf4)(DAT_3009fd74,uVar5,*(undefined2 *)((int)puVar4 + iVar2));
      (*DAT_3009fcf4)(DAT_3009fd78,uVar5,puVar4[0xfa]);
      (*DAT_3009fcf4)(DAT_3009fd7c,uVar5,(short)puVar4[0xfb]);
      (*DAT_3009fcf4)(DAT_3009fd80,uVar5,*(undefined2 *)((int)puVar4 + iVar3));
      uVar5 = uVar5 + 1;
      puVar4 = puVar4 + 3;
    } while (uVar5 < *puVar1);
  }
  (*DAT_3009fcf4)(DAT_3009fd54);
  return 0;
}

