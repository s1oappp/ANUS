/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : flash — флеш-подсистема: NAND-контроллер, ptable, YAFFS/YAFFS2, NV-память (NVM/nvim)
 * Часть  : 3 (функций: 150, адреса 0x3002213C..0x3002BAEC)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * yaffs_StartUp @ 0x3002213C  (примерный размер ~692 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 6
 * Вызывает: OSAL_SemMCreate, __udiv32, memset, nand_get_spec, yaffs_initialise, yaffsfs_LocalInitialisation
 * Вызывают: yaffsDevCreate
 * Константы: 0x3002213C, 0xFFFFFFFF
 * Данные: DAT_30022620, DAT_30022624, DAT_30022628, DAT_3002262c, DAT_30022630, DAT_30022634, DAT_30022638, DAT_3002263c
 * ---------------------------------------------------------------- */
undefined4 yaffs_StartUp(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar1 = nand_get_spec(&local_24);
  if (iVar1 == 0) {
    uVar2 = OSAL_SemMCreate(9);
    *(undefined4 *)(DAT_30022620 + param_1 * 4) = uVar2;
    yaffsfs_LocalInitialisation(param_1);
    memset((void *)(param_1 * DAT_30022628 + DAT_30022624),0,DAT_30022628);
    *(int *)(DAT_3002262c + DAT_30022628 * param_1) = param_1;
    *(undefined4 *)(param_1 * DAT_30022628 + DAT_30022630) = local_20;
    *(undefined4 *)(param_1 * DAT_30022628 + DAT_30022634) = local_20;
    uVar2 = __udiv32(local_24,local_20);
    *(undefined4 *)(DAT_30022638 + DAT_30022628 * param_1) = uVar2;
    *(undefined4 *)(param_1 * DAT_30022628 + DAT_3002263c) = 5;
    *(undefined4 *)(param_1 * DAT_30022628 + DAT_30022640) = 10;
    uVar2 = __udiv32(param_2,local_24);
    *(undefined4 *)(DAT_30022644 + DAT_30022628 * param_1) = uVar2;
    iVar1 = __udiv32(param_3,local_24);
    *(int *)(DAT_30022648 + DAT_30022628 * param_1) = iVar1 + -1;
    *(undefined4 *)(param_1 * DAT_30022628 + DAT_3002264c) = 1;
    *(undefined4 *)(param_1 * DAT_30022628 + DAT_30022650) = 0;
    *(undefined4 *)(param_1 * DAT_30022628 + DAT_30022654) = 10;
    *(undefined4 *)(param_1 * DAT_30022628 + DAT_30022658) = 2;
    *(undefined4 *)(DAT_30022660 + DAT_30022628 * param_1) = DAT_3002265c;
    *(undefined4 *)(DAT_30022668 + DAT_30022628 * param_1) = DAT_30022664;
    *(undefined4 *)(DAT_30022670 + DAT_30022628 * param_1) = DAT_3002266c;
    *(undefined4 *)(DAT_30022678 + DAT_30022628 * param_1) = DAT_30022674;
    *(undefined4 *)(DAT_30022680 + DAT_30022628 * param_1) = DAT_3002267c;
    *(undefined4 *)(DAT_30022688 + DAT_30022628 * param_1) = DAT_30022684;
    *(undefined4 *)(DAT_30022690 + DAT_30022628 * param_1) = DAT_3002268c;
    *(undefined4 *)(DAT_30022698 + DAT_30022628 * param_1) = DAT_30022694;
    *(undefined4 *)(param_1 * DAT_30022628 + DAT_3002269c) = 1;
    *(undefined4 *)(param_1 * DAT_30022628 + DAT_300226a0) = 1;
    *(undefined4 *)(param_1 * DAT_30022628 + DAT_300226a4) = 1;
    *(undefined4 *)(param_1 * DAT_30022628 + DAT_300226a8) = 500;
    *(undefined4 *)(DAT_30022624 + DAT_30022628 * param_1) = param_4;
    *(undefined1 *)(param_1 * DAT_30022628 + DAT_300226ac) = 1;
    *(undefined1 *)(param_1 * DAT_30022628 + DAT_300226b0) = 1;
    yaffs_initialise(DAT_300226b4,DAT_30022624 + DAT_30022628 * param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffsFormat @ 0x300223F0  (примерный размер ~232 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 9
 * Вызывает: rm, rmdir, strcat, strcmp, strcpy, xdelete, yaffs_closedir, yaffs_opendir, yaffs_readdir
 * Константы: 0x300223F0, 0xFFFFFFFF
 * Данные: DAT_300226b8, DAT_300226bc, DAT_300226c0
 * ---------------------------------------------------------------- */
undefined4 yaffsFormat(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char acStack_114 [256];
  
  uVar1 = yaffs_opendir(param_1,*(undefined4 *)(DAT_300226b8 + param_1 * 4));
  do {
    do {
      iVar2 = yaffs_readdir(param_1,uVar1);
      if (iVar2 == 0) {
        yaffs_closedir(param_1,uVar1);
        return 0;
      }
      iVar3 = strcmp((char *)(iVar2 + 10),DAT_300226bc);
    } while (iVar3 == 0);
    strcpy(acStack_114,*(char **)(DAT_300226b8 + param_1 * 4));
    strcat(acStack_114,DAT_300226c0);
    strcat(acStack_114,(char *)(iVar2 + 10));
    iVar2 = rm(acStack_114);
  } while (((iVar2 == 0) || (iVar2 = rmdir(acStack_114), iVar2 == 0)) ||
          (iVar2 = xdelete(acStack_114), iVar2 == 0));
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * yaffsMemShow @ 0x300224D8  (примерный размер ~112 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 3
 * Вызывает: printf, yaffs_DumpDevStruct, yaffs_freespace
 * Константы: 0x300224D8
 * Данные: DAT_30022628, DAT_30022644, DAT_30022648, DAT_300226b8, DAT_300226c4, DAT_300226c8
 * ---------------------------------------------------------------- */
void yaffsMemShow(int param_1)

{
  undefined4 uVar1;
  
  yaffs_DumpDevStruct(*(undefined4 *)(DAT_300226b8 + param_1 * 4));
  uVar1 = yaffs_freespace(param_1,*(undefined4 *)(DAT_300226b8 + param_1 * 4));
  printf(DAT_300226c4,
         (*(int *)(DAT_30022648 + DAT_30022628 * param_1) -
         *(int *)(DAT_30022644 + DAT_30022628 * param_1)) * 0x20000 + 0x20000);
  printf(DAT_300226c8,uVar1);
  return;
}

/* ----------------------------------------------------------------
 * yaffsfs_SetError @ 0x300225D0  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 21 | Вызывает: 1
 * Вызывает: __errno
 * Вызывают: yaffs_chmod, yaffs_close, yaffs_fchmod, yaffs_freespace, yaffs_fstat, yaffs_link, yaffs_lseek, yaffs_lstat, yaffs_mkdir, yaffs_mount
 *           ...
 * Константы: 0x300225D0
 * ---------------------------------------------------------------- */
void yaffsfs_SetError(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)__errno();
  *puVar1 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * yaffsfs_Lock @ 0x300225E4  (примерный размер ~28 байт)
 * Модуль: flash | Вызывают: 27 | Вызывает: 1
 * Вызывает: OSAL_SemTake
 * Вызывают: yaffsGetFileSavings, yaffsIoctl, yaffs_FileIsOpen, yaffs_chmod, yaffs_close, yaffs_closedir, yaffs_fchmod, yaffs_freespace, yaffs_fstat, yaffs_link
 *           ...
 * Константы: 0x300225E4, 0xFFFFFFFF
 * Данные: DAT_30022620
 * ---------------------------------------------------------------- */
void yaffsfs_Lock(int param_1)

{
  OSAL_SemTake(*(undefined4 *)(DAT_30022620 + param_1 * 4),0xffffffff);
  return;
}

/* ----------------------------------------------------------------
 * yaffsfs_Unlock @ 0x30022600  (примерный размер ~24 байт)
 * Модуль: flash | Вызывают: 27 | Вызывает: 1
 * Вызывает: OSAL_SemGive
 * Вызывают: yaffsGetFileSavings, yaffsIoctl, yaffs_FileIsOpen, yaffs_chmod, yaffs_close, yaffs_closedir, yaffs_fchmod, yaffs_freespace, yaffs_fstat, yaffs_link
 *           ...
 * Константы: 0x30022600
 * Данные: DAT_30022620
 * ---------------------------------------------------------------- */
void yaffsfs_Unlock(int param_1)

{
  OSAL_SemGive(*(undefined4 *)(DAT_30022620 + param_1 * 4));
  return;
}

/* ----------------------------------------------------------------
 * yaffsfs_CurrentTime @ 0x30022618  (примерный размер ~180 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30022618
 * ---------------------------------------------------------------- */
undefined4 yaffsfs_CurrentTime(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * yaffsDrv @ 0x300226CC  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: iosDrvInstall
 * Вызывают: yaffsInit
 * Константы: 0x300226CC, 0xFFFFFFFF
 * Данные: DAT_30023654, DAT_30023658, DAT_3002365c, DAT_30023660, DAT_30023664, DAT_30023668, DAT_3002366c, DAT_30023670
 * ---------------------------------------------------------------- */
undefined4 yaffsDrv(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_30023654 < 1) {
    iVar2 = iosDrvInstall(DAT_30023664,DAT_30023668,DAT_3002366c,DAT_30023670,DAT_30023658,
                          DAT_3002365c,DAT_30023660);
    *DAT_30023654 = iVar2;
    if (*DAT_30023654 == -1) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffsInit @ 0x30022744  (примерный размер ~100 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: logMsg, ptable_yaffs_mount, yaffsDrv
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x30022744
 * Данные: DAT_30023674
 * ---------------------------------------------------------------- */
int yaffsInit(void)

{
  int iVar1;
  
  iVar1 = yaffsDrv();
  if (iVar1 == 0) {
    ptable_yaffs_mount();
    iVar1 = 0;
  }
  else {
    logMsg(DAT_30023674,iVar1,0,0,0,0,0);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * yaffsDrvUninstall @ 0x300227A8  (примерный размер ~76 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: iosDrvRemove
 * Константы: 0x300227A8, 0xFFFFFFFF
 * Данные: DAT_30023654
 * ---------------------------------------------------------------- */
undefined4 yaffsDrvUninstall(undefined4 param_1)

{
  int iVar1;
  
  if (*DAT_30023654 != 0) {
    iVar1 = iosDrvRemove(*DAT_30023654,param_1);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    *DAT_30023654 = 0;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * yaffsDevCreate @ 0x300227F4  (примерный размер ~616 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 9
 * Вызывает: OSAL_LogMsg, OSAL_SemMCreate, calloc, free, iosDevAdd, memset, strcpy, yaffs_StartUp, yaffs_mount
 * Вызывают: ptable_yaffs_mount
 * Константы: 0xFFFFFFFF, 0x300227F4
 * Данные: DAT_30023654, DAT_30023758, DAT_3002375c, DAT_30023760, DAT_300237f0, DAT_300237f4, DAT_300237f8, DAT_300237fc
 * ---------------------------------------------------------------- */
undefined4 yaffsDevCreate(int param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  undefined4 uVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(int *)(DAT_30023758 + param_1 * 4) == 0) {
    *(char **)(DAT_30023758 + param_1 * 4) = param_4;
    if (param_4 == (char *)0x0) {
      OSAL_LogMsg(DAT_3002375c,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
    else if (*DAT_30023654 < 1) {
      OSAL_LogMsg(DAT_300237f0,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
    else if (*(char *)(DAT_300237f4 + param_1) == '\0') {
      pvVar2 = calloc(1,0x30);
      *(void **)(DAT_300237fc + param_1 * 4) = pvVar2;
      if (*(int *)(DAT_300237fc + param_1 * 4) == 0) {
        OSAL_LogMsg(DAT_30023800,0,0,0,0,0,0);
        uVar1 = 0xffffffff;
      }
      else {
        memset(*(void **)(DAT_300237fc + param_1 * 4),0,0x30);
        strcpy((char *)(*(int *)(DAT_300237fc + param_1 * 4) + 0x24),param_4);
        *(int *)(*(int *)(DAT_300237fc + param_1 * 4) + 0x20) = param_1;
        uVar3 = iosDevAdd(*(undefined4 *)(DAT_300237fc + param_1 * 4),param_4,*DAT_30023654);
        uVar1 = OSAL_SemMCreate(9);
        *(undefined4 *)(DAT_30023930 + param_1 * 4) = uVar1;
        yaffs_StartUp(param_1,param_2,param_3,param_4);
        uVar4 = yaffs_mount(param_1,param_4);
        if ((uVar4 | uVar3) == 0xffffffff) {
          OSAL_LogMsg(DAT_30023934,0,0,0,0,0,0);
          free(*(void **)(DAT_300237fc + param_1 * 4));
          uVar1 = 0xffffffff;
        }
        else {
          *(undefined1 *)(DAT_300237f4 + param_1) = 1;
          uVar1 = 0;
        }
      }
    }
    else {
      OSAL_LogMsg(DAT_300237f8,0,0,0,0,0,0);
      uVar1 = 0;
    }
  }
  else {
    OSAL_LogMsg(DAT_30023760,param_4,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffsDevDelete @ 0x30022A5C  (примерный размер ~324 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, free, iosDevDelete, iosDevFind, yaffs_unmount
 * Константы: 0xFFFFFFFF, 0x30022A5C
 * Данные: DAT_30023758, DAT_300237f4, DAT_300237fc, DAT_30023938, DAT_300239dc, DAT_300239e0
 * ---------------------------------------------------------------- */
undefined4 yaffsDevDelete(int param_1,int param_2)

{
  undefined4 uVar1;
  void *__ptr;
  
  if (param_2 == 0) {
    OSAL_LogMsg(DAT_30023938,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (*(char *)(DAT_300237f4 + param_1) == '\0') {
    OSAL_LogMsg(DAT_300239dc,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    __ptr = (void *)iosDevFind(param_2,0);
    if (*(void **)(DAT_300237fc + param_1 * 4) == __ptr) {
      yaffs_unmount(param_1,*(undefined4 *)(DAT_30023758 + param_1 * 4));
      iosDevDelete(__ptr);
      *(undefined4 *)(DAT_300237fc + param_1 * 4) = 0;
      free(__ptr);
      *(undefined1 *)(DAT_300237f4 + param_1) = 0;
      *(undefined4 *)(DAT_30023758 + param_1 * 4) = 0;
      uVar1 = 0;
    }
    else {
      OSAL_LogMsg(DAT_300239e0,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffsCreate @ 0x30022BA0  (примерный размер ~536 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 7
 * Вызывает: OSAL_LogMsg, malloc, memset, strcat, strcpy, strlen, yaffs_open
 * Константы: 0xFFFFFFFF, 0x30022BA0
 * Данные: DAT_30023758, DAT_30023b08, DAT_30023b0c, DAT_30023b10, DAT_30023b14, DAT_30023c60, DAT_30023c64
 * ---------------------------------------------------------------- */
undefined1 * yaffsCreate(int param_1,char *param_2,uint param_3)

{
  undefined1 *__s;
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  char acStack_124 [256];
  
  if (param_1 == 0) {
    OSAL_LogMsg(DAT_30023b08,0,0,0,0,0,0);
    __s = (undefined1 *)0xffffffff;
  }
  else if (((param_3 == 0) || (param_3 == 2)) || (param_3 == 1)) {
    sVar1 = strlen(DAT_30023b10);
    sVar2 = strlen(param_2);
    sVar3 = strlen(*(char **)(DAT_30023758 + *(int *)(param_1 + 0x20) * 4));
    if (sVar3 + sVar1 + sVar2 < 0xff) {
      strcpy(acStack_124,*(char **)(DAT_30023758 + *(int *)(param_1 + 0x20) * 4));
      strcat(acStack_124,DAT_30023b10);
      strcat(acStack_124,param_2);
      iVar4 = yaffs_open(*(undefined4 *)(param_1 + 0x20),acStack_124,param_3 | 0x200,DAT_30023c60);
      if (iVar4 == -1) {
        __s = (undefined1 *)0xffffffff;
      }
      else {
        __s = (undefined1 *)malloc(0x118);
        if (__s == (undefined1 *)0x0) {
          OSAL_LogMsg(DAT_30023c64,0,0,0,0,0,0);
          __s = (undefined1 *)0xffffffff;
        }
        else {
          memset(__s,0,0x118);
          *(int *)(__s + 0x104) = iVar4;
          __s[1] = 0;
          *__s = 0;
          *(undefined4 *)(__s + 0x114) = *(undefined4 *)(param_1 + 0x20);
          strcpy(__s + 2,acStack_124);
        }
      }
    }
    else {
      OSAL_LogMsg(DAT_30023b14,0,0,0,0,0,0);
      __s = (undefined1 *)0xffffffff;
    }
  }
  else {
    OSAL_LogMsg(DAT_30023b0c,0,0,0,0,0,0);
    __s = (undefined1 *)0xffffffff;
  }
  return __s;
}

/* ----------------------------------------------------------------
 * yaffs_FileIsOpen @ 0x30022DB8  (примерный размер ~168 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: yaffsfs_FindObject, yaffsfs_Lock, yaffsfs_Unlock
 * Вызывают: yaffsDelete
 * Константы: 0x30022DB8
 * Данные: DAT_30023c68, DAT_30023d70
 * ---------------------------------------------------------------- */
undefined4 yaffs_FileIsOpen(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_FindObject(0,param_2,0);
  if (iVar1 != 0) {
    uVar3 = 0;
    for (iVar2 = 0; iVar2 < 200; iVar2 = iVar2 + 1) {
      if (((*(byte *)(param_1 * 0x960 + DAT_30023c68 + iVar2 * 0xc) & 1) != 0) &&
         (*(int *)(DAT_30023d70 + iVar2 * 0xc + param_1 * 0x960) == iVar1)) {
        uVar3 = 1;
      }
    }
  }
  yaffsfs_Unlock(param_1);
  return uVar3;
}

/* ----------------------------------------------------------------
 * yaffsDelete @ 0x30022E60  (примерный размер ~236 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 6
 * Вызывает: OSAL_LogMsg, strcat, strcpy, strlen, yaffs_FileIsOpen, yaffs_unlink
 * Константы: 0xFFFFFFFF, 0x30022E60
 * Данные: DAT_30023758, DAT_30023b14
 * ---------------------------------------------------------------- */
undefined4 yaffsDelete(int param_1,char *param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  char acStack_114 [256];
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    sVar2 = strlen(*(char **)(DAT_30023758 + *(int *)(param_1 + 0x20) * 4));
    sVar3 = strlen(param_2);
    if (sVar3 + sVar2 < 0xff) {
      strcpy(acStack_114,*(char **)(DAT_30023758 + *(int *)(param_1 + 0x20) * 4));
      strcat(acStack_114,param_2);
      iVar4 = yaffs_FileIsOpen(*(undefined4 *)(param_1 + 0x20),acStack_114);
      if (iVar4 == 1) {
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = yaffs_unlink(*(undefined4 *)(param_1 + 0x20),acStack_114);
      }
    }
    else {
      OSAL_LogMsg(DAT_30023b14,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_CheckFileName @ 0x30022F4C  (примерный размер ~276 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: OSAL_LogMsg
 * Вызывают: yaffsIoctl, yaffsOpen
 * Константы: 0xFFFFFFFF, 0x30022F4C
 * Данные: DAT_30023ecc, DAT_30023ed0
 * ---------------------------------------------------------------- */
undefined4 yaffs_CheckFileName(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (*(char *)(param_1 + iVar1) == '\0') {
      return 0;
    }
    if (((((*(char *)(param_1 + iVar1) == ':') || (*(char *)(param_1 + iVar1) == '*')) ||
         (*(char *)(param_1 + iVar1) == '?')) ||
        ((*(char *)(param_1 + iVar1) == '\"' || (*(char *)(param_1 + iVar1) == '<')))) ||
       ((*(char *)(param_1 + iVar1) == '>' ||
        ((*(char *)(param_1 + iVar1) == '|' || (*(char *)(param_1 + iVar1) == '\\')))))) break;
    if ((*(char *)(param_1 + iVar1 + 1) == '\0') && (*(char *)(param_1 + iVar1) == '/')) {
      OSAL_LogMsg(DAT_30023ed0,0,0,0,0,0,0);
      return 0xffffffff;
    }
    iVar1 = iVar1 + 1;
  }
  OSAL_LogMsg(DAT_30023ecc,(int)*(char *)(param_1 + iVar1),0,0,0,0,0);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * yaffsOpen @ 0x30023060  (примерный размер ~892 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 13
 * Вызывает: OSAL_LogMsg, malloc, memset, printf, strcat, strcmp, strcpy, strlen, yaffs_CheckFileName, yaffs_mkdir, yaffs_open, yaffs_opendir, yaffs_stat
 * Константы: 0xFFFFFFFF, 0x30023060
 * Данные: DAT_30023758, DAT_30023b14, DAT_30023ffc, DAT_30024000, DAT_30024004, DAT_300240b4, DAT_300240b8, DAT_300241ec
 * ---------------------------------------------------------------- */
undefined1 * yaffsOpen(int param_1,char *param_2,uint param_3,ushort param_4)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *__s;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 auStack_15c [8];
  uint local_154;
  char acStack_128 [256];
  
  uVar5 = 0;
  if (param_1 == 0) {
    OSAL_LogMsg(DAT_30023ffc,0,0,0,0,0,0);
    __s = (undefined1 *)0xffffffff;
  }
  else {
    sVar1 = strlen(*(char **)(DAT_30023758 + *(int *)(param_1 + 0x20) * 4));
    sVar2 = strlen(param_2);
    if (sVar2 + sVar1 < 0xff) {
      strcpy(acStack_128,*(char **)(DAT_30023758 + *(int *)(param_1 + 0x20) * 4));
      strcat(acStack_128,param_2);
      if ((*DAT_30024000 & 0x20) != 0) {
        printf(DAT_30024004,acStack_128,param_3,(uint)param_4);
      }
      if ((param_3 & 0x200) == 0x200) {
        iVar3 = strcmp(*(char **)(DAT_30023758 + *(int *)(param_1 + 0x20) * 4),acStack_128);
        if (iVar3 == 0) {
          OSAL_LogMsg(DAT_300240b4,0,0,0,0,0,0);
          return (undefined1 *)0xffffffff;
        }
        iVar3 = yaffs_CheckFileName(acStack_128);
        if (iVar3 != 0) {
          return (undefined1 *)0xffffffff;
        }
        if ((param_4 & 0xf000) == 0x4000) {
          puVar4 = (undefined1 *)yaffs_mkdir(*(undefined4 *)(param_1 + 0x20),acStack_128,param_4);
          uVar6 = 1;
          uVar5 = 1;
        }
        else {
          if ((param_4 & 0xf000) == 0xa000) {
            OSAL_LogMsg(DAT_300240b8,0,0,0,0,0,0);
            return (undefined1 *)0xffffffff;
          }
          puVar4 = (undefined1 *)
                   yaffs_open(*(undefined4 *)(param_1 + 0x20),acStack_128,param_3,param_4);
          uVar6 = 0;
        }
      }
      else {
        iVar3 = yaffs_stat(*(undefined4 *)(param_1 + 0x20),acStack_128,auStack_15c);
        if (iVar3 == -1) {
          return (undefined1 *)0xffffffff;
        }
        if ((local_154 & 0xf000) == 0x4000) {
          puVar4 = (undefined1 *)yaffs_opendir(*(undefined4 *)(param_1 + 0x20),acStack_128);
          uVar6 = 1;
          uVar5 = 2;
        }
        else {
          if ((*DAT_30024000 & 0x20) != 0) {
            printf(DAT_300241ec,acStack_128);
          }
          puVar4 = (undefined1 *)
                   yaffs_open(*(undefined4 *)(param_1 + 0x20),acStack_128,param_3,param_4);
          uVar6 = 0;
        }
      }
      __s = puVar4;
      if (puVar4 != (undefined1 *)0xffffffff) {
        __s = (undefined1 *)malloc(0x118);
        if (__s == (undefined1 *)0x0) {
          OSAL_LogMsg(DAT_300241f0,0,0,0,0,0,0);
          __s = (undefined1 *)0xffffffff;
        }
        else {
          memset(__s,0,0x118);
          *(undefined1 **)(__s + 0x104) = puVar4;
          *__s = uVar6;
          __s[1] = uVar5;
          *(undefined4 *)(__s + 0x114) = *(undefined4 *)(param_1 + 0x20);
          strcpy(__s + 2,acStack_128);
        }
      }
    }
    else {
      OSAL_LogMsg(DAT_30023b14,0,0,0,0,0,0);
      __s = (undefined1 *)0xffffffff;
    }
  }
  return __s;
}

/* ----------------------------------------------------------------
 * yaffsRead @ 0x300233DC  (примерный размер ~252 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, OSAL_SemGive, OSAL_SemTake, printf, yaffs_read
 * Константы: 0x300233DC, 0xFFFFFFFF
 * Данные: DAT_30023930, DAT_30024000, DAT_300242c8, DAT_300242cc, DAT_300242d0, DAT_300242d4, DAT_300242d8
 * ---------------------------------------------------------------- */
undefined4 yaffsRead(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_3 < (*(int *)(DAT_300242c8 + DAT_300242cc * *(int *)(param_1 + 0x114)) -
                *(int *)(DAT_300242d0 + DAT_300242cc * *(int *)(param_1 + 0x114))) * 0x20000 +
                0x20000U) {
    OSAL_SemTake(*(undefined4 *)(DAT_30023930 + *(int *)(param_1 + 0x114) * 4),0xffffffff);
    if ((*DAT_30024000 & 0x20) != 0) {
      printf(DAT_300242d8,param_1,param_2,param_3);
    }
    uVar1 = yaffs_read(*(undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x104),param_2,
                       param_3);
    OSAL_SemGive(*(undefined4 *)(DAT_30023930 + *(int *)(param_1 + 0x114) * 4));
  }
  else {
    OSAL_LogMsg(DAT_300242d4,0,0,0,0,0,0);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffsWrite @ 0x300234D8  (примерный размер ~264 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 4
 * Вызывает: OSAL_SemGive, OSAL_SemTake, printf, yaffs_write
 * Константы: 0x300234D8, 0xFFFFFFFF
 * Данные: DAT_30023930, DAT_30024000, DAT_300242c8, DAT_300242cc, DAT_300242d0, DAT_30024304, DAT_30024308
 * ---------------------------------------------------------------- */
undefined4 yaffsWrite(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if ((*DAT_30024000 & 0x20) != 0) {
    printf(DAT_30024304,param_1,param_2,param_3);
  }
  if (param_3 < (*(int *)(DAT_300242c8 + DAT_300242cc * *(int *)(param_1 + 0x114)) -
                *(int *)(DAT_300242d0 + DAT_300242cc * *(int *)(param_1 + 0x114))) * 0x20000 +
                0x20000U) {
    OSAL_SemTake(*(undefined4 *)(DAT_30023930 + *(int *)(param_1 + 0x114) * 4),0xffffffff);
    if ((*DAT_30024000 & 0x20) != 0) {
      printf(DAT_30024304,param_1,param_2,param_3);
    }
    uVar1 = yaffs_write(*(undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x104),param_2,
                        param_3);
    OSAL_SemGive(*(undefined4 *)(DAT_30023930 + *(int *)(param_1 + 0x114) * 4));
  }
  else {
    printf(DAT_30024308);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffsClose @ 0x300235E0  (примерный размер ~276 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 7
 * Вызывает: OSAL_LogMsg, OSAL_SemGive, OSAL_SemTake, free, printf, yaffs_close, yaffs_closedir
 * Константы: 0xFFFFFFFF, 0x300235E0
 * Данные: DAT_30023930, DAT_30024000, DAT_3002430c, DAT_30024310
 * ---------------------------------------------------------------- */
undefined4 yaffsClose(char *param_1)

{
  undefined4 uVar1;
  
  if ((*DAT_30024000 & 0x20) != 0) {
    printf(DAT_3002430c,param_1);
  }
  if (*param_1 == '\0') {
    OSAL_SemTake(*(undefined4 *)(DAT_30023930 + *(int *)(param_1 + 0x114) * 4),0xffffffff);
    uVar1 = yaffs_close(*(undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x104));
    OSAL_SemGive(*(undefined4 *)(DAT_30023930 + *(int *)(param_1 + 0x114) * 4));
  }
  else {
    if (*param_1 != '\x01') {
      OSAL_LogMsg(DAT_30024310,0,0,0,0,0,0);
      return 0xffffffff;
    }
    if (param_1[1] == '\x01') {
      uVar1 = 0;
    }
    else {
      uVar1 = yaffs_closedir(*(undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x104));
    }
  }
  free(param_1);
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffsIoctl @ 0x300236F4  (примерный размер ~2140 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 19
 * Вызывает: OSAL_LogMsg, memset, strcat, strcpy, strlen, yaffs_CheckFileName, yaffs_FlushFile, yaffs_GetObjectFileLength, yaffs_lseek, yaffs_readdir, yaffs_rename, yaffs_rewinddir, yaffs_rmdir, yaffs_stat
 *           ...
 * Константы: 0x300236F4
 * Данные: DAT_30023b14, DAT_30024314, DAT_30024318, DAT_3002431c, DAT_30024320, DAT_30024324, DAT_30024328, DAT_3002432c
 * ---------------------------------------------------------------- */
int yaffsIoctl(char *param_1,int param_2,int *param_3)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_594 [8];
  int local_58c;
  undefined2 local_584;
  int local_578;
  undefined1 auStack_560 [52];
  char local_52c [256];
  char local_42c [256];
  char local_32c [256];
  char local_22c [256];
  char acStack_12c [256];
  
  iVar6 = 0;
  if (param_2 == 0x25) {
    if (*param_1 == '\x01') {
      iVar3 = yaffs_readdir(*(undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x104));
      if (iVar3 == 0) {
        param_3[2] = 1;
      }
      else {
        param_3[2] = 0;
        strcpy((char *)(param_3 + 4),(char *)(iVar3 + 10));
      }
    }
    else {
      OSAL_LogMsg(DAT_30024314,0,0,0,0,0,0);
      iVar6 = -1;
    }
  }
  else if (param_2 < 0x26) {
    if (param_2 == 10) {
      local_22c[0] = '\0';
      local_52c[0] = '\0';
      sVar1 = strlen(*(char **)(DAT_3002431c + *(int *)(param_1 + 0x114) * 4));
      sVar2 = strlen((char *)param_3[0x100]);
      if (sVar2 + sVar1 < 0xff) {
        sVar1 = strlen(*(char **)(DAT_3002431c + *(int *)(param_1 + 0x114) * 4));
        sVar2 = strlen((char *)param_3);
        if (sVar2 + sVar1 < 0xff) {
          strcpy(local_22c,*(char **)(DAT_3002431c + *(int *)(param_1 + 0x114) * 4));
          strcat(local_22c,(char *)param_3[0x100]);
          strcpy(local_52c,*(char **)(DAT_3002431c + *(int *)(param_1 + 0x114) * 4));
          strcat(local_52c,(char *)param_3);
          iVar6 = yaffs_CheckFileName(local_52c);
          if (iVar6 != 0) {
            return -1;
          }
          iVar6 = yaffs_stat(*(undefined4 *)(param_1 + 0x114),local_52c,auStack_560);
          if (iVar6 != 0) {
            iVar6 = yaffs_rename(*(undefined4 *)(param_1 + 0x114),local_22c,local_52c);
            return iVar6;
          }
          OSAL_LogMsg(DAT_30024328,local_52c,0,0,0,0,0);
          return -1;
        }
      }
      OSAL_LogMsg(DAT_30024324,0,0,0,0,0,0);
      iVar6 = -1;
    }
    else if (param_2 < 0xb) {
      if (param_2 == 1) {
        yaffsfs_Lock(*(undefined4 *)(param_1 + 0x114));
        iVar3 = yaffsfs_GetHandlePointer
                          (*(undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x104));
        iVar7 = *(int *)(iVar3 + 4);
        uVar4 = yaffsfs_GetHandleObject
                          (*(undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x104));
        iVar3 = yaffs_GetObjectFileLength(uVar4);
        *param_3 = iVar3 - iVar7;
        yaffsfs_Unlock(*(undefined4 *)(param_1 + 0x114));
        if (*param_3 < 0) {
          iVar6 = -1;
        }
      }
      else if (param_2 == 7) {
        iVar3 = yaffs_lseek(*(undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x104),
                            param_3,0);
        if (iVar3 < 0) {
          iVar6 = -1;
        }
      }
      else if (param_2 == 8) {
        yaffsfs_Lock(*(undefined4 *)(param_1 + 0x114));
        iVar6 = yaffsfs_GetHandlePointer
                          (*(undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x104));
        yaffsfs_Unlock(*(undefined4 *)(param_1 + 0x114));
        iVar6 = *(int *)(iVar6 + 4);
      }
    }
    else if (param_2 == 0x15) {
      yaffsfs_Lock(*(undefined4 *)(param_1 + 0x114));
      pbVar5 = (byte *)yaffsfs_GetHandlePointer
                                 (*(undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x104))
      ;
      if ((pbVar5 == (byte *)0x0) || ((*pbVar5 & 1) == 0)) {
        OSAL_LogMsg(DAT_30024320,pbVar5,0,0,0,0,0);
      }
      else {
        yaffs_FlushFile(*(undefined4 *)(pbVar5 + 8),1);
      }
      yaffsfs_Unlock(*(undefined4 *)(param_1 + 0x114));
    }
    else if (param_2 == 0x20) {
      if (*param_1 == '\x01') {
        sVar1 = strlen(*(char **)(DAT_3002431c + *(int *)(param_1 + 0x114) * 4));
        sVar2 = strlen((char *)param_3);
        if (sVar2 + sVar1 < 0xff) {
          strcpy(acStack_12c,*(char **)(DAT_3002431c + *(int *)(param_1 + 0x114) * 4));
          strcat(acStack_12c,(char *)param_3);
          iVar6 = yaffs_rmdir(*(undefined4 *)(param_1 + 0x114),acStack_12c);
        }
        else {
          OSAL_LogMsg(DAT_30023b14,0,0,0,0,0,0);
          iVar6 = -1;
        }
      }
      else {
        OSAL_LogMsg(DAT_30024318,0,0,0,0,0,0);
        iVar6 = -1;
      }
    }
  }
  else if (param_2 == 0x3b) {
    iVar6 = yaffs_unlink(*(undefined4 *)(param_1 + 0x114),param_1 + 2);
    if (iVar6 != 0) {
      OSAL_LogMsg(DAT_30024330,0,0,0,0,0,0);
      iVar6 = -1;
    }
  }
  else if (param_2 < 0x3c) {
    if (param_2 == 0x2c) {
      *(int *)(param_1 + 0x108) = *param_3;
      *(int *)(param_1 + 0x110) = param_3[1];
    }
    else if (param_2 == 0x2f) {
      local_32c[0] = '\0';
      local_42c[0] = '\0';
      sVar1 = strlen(*(char **)(DAT_3002431c + *(int *)(param_1 + 0x114) * 4));
      sVar2 = strlen((char *)param_3[0x100]);
      if (sVar2 + sVar1 < 0xff) {
        sVar1 = strlen(*(char **)(DAT_3002431c + *(int *)(param_1 + 0x114) * 4));
        sVar2 = strlen((char *)param_3);
        if (sVar2 + sVar1 < 0xff) {
          strcpy(local_32c,*(char **)(DAT_3002431c + *(int *)(param_1 + 0x114) * 4));
          strcat(local_32c,(char *)param_3[0x100]);
          strcpy(local_42c,*(char **)(DAT_3002431c + *(int *)(param_1 + 0x114) * 4));
          strcat(local_42c,(char *)param_3);
          iVar6 = yaffs_CheckFileName(local_42c);
          if (iVar6 == 0) {
            iVar6 = yaffs_rename(*(undefined4 *)(param_1 + 0x114),local_32c,local_42c);
            return iVar6;
          }
          return -1;
        }
      }
      OSAL_LogMsg(DAT_30024324,0,0,0,0,0,0);
      iVar6 = -1;
    }
  }
  else if (param_2 == 0x40) {
    memset(auStack_594,0,0x34);
    if (*param_1 == '\x01') {
      param_3[2] = param_3[2] & 0xffff0fffU | 0x4000;
      param_3[0xb] = 0;
      param_3[6] = 0;
      param_3[7] = 0;
    }
    else {
      iVar6 = yaffs_stat(*(undefined4 *)(param_1 + 0x114),param_1 + 2,auStack_594);
      if (iVar6 != -1) {
        param_3[2] = local_58c;
        param_3[2] = param_3[2] & 0xffff0fffU | 0x8000;
        param_3[8] = *(int *)(param_1 + 0x108);
        param_3[10] = *(int *)(param_1 + 0x10c);
        param_3[9] = *(int *)(param_1 + 0x110);
        param_3[6] = local_578;
        param_3[7] = local_578 >> 0x1f;
        *(undefined2 *)(param_3 + 4) = local_584;
        param_3[0xb] = 0;
      }
    }
  }
  else if (param_2 == 0x50) {
    if (*param_1 == '\x01') {
      yaffs_rewinddir(*(undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x104));
    }
    else {
      OSAL_LogMsg(DAT_3002432c,0,0,0,0,0,0);
      iVar6 = -1;
    }
  }
  return iVar6;
}

/* ----------------------------------------------------------------
 * yaffsGetFileSavings @ 0x30023F50  (примерный размер ~612 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 12
 * Вызывает: OSAL_LogMsg, __div32, malloc, yaffs_AddrToChunk, yaffs_FindChunkInFile, yaffs_GetObjectFileLength, yaffs_close, yaffs_open, yaffsfs_GetHandleObject, yaffsfs_GetHandlePointer, yaffsfs_Lock, yaffsfs_Unlock
 * Вызывают: yaffsCheckFileSavings
 * Константы: 0xFFFFFFFF, 0x30023F50
 * Данные: DAT_30024334, DAT_30024338
 * ---------------------------------------------------------------- */
undefined4
yaffsGetFileSavings(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  int local_50;
  int local_4c;
  int local_48;
  size_t local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  
  local_4c = 0;
  iVar7 = 0;
  uVar1 = yaffs_open(param_1,param_2,2,0);
  yaffsfs_Lock(param_1);
  local_4c = yaffsfs_GetHandlePointer(param_1,uVar1);
  iVar2 = yaffsfs_GetHandleObject(param_1,uVar1);
  yaffsfs_Unlock(param_1);
  if ((local_4c == 0) || (iVar2 == 0)) {
    OSAL_LogMsg(DAT_30024334,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    yaffsfs_Lock(param_1);
    iVar3 = yaffs_GetObjectFileLength(iVar2);
    yaffsfs_Unlock(param_1);
    *param_4 = iVar3;
    iVar4 = __div32(iVar3,*(undefined4 *)(*(int *)(iVar2 + 8) + 0x9c));
    local_44 = iVar4 * 2 + 2;
    puVar5 = (undefined2 *)malloc(local_44);
    *param_3 = puVar5;
    if (puVar5 == (undefined2 *)0x0) {
      OSAL_LogMsg(DAT_30024338,0,0,0,0,0,0);
      uVar1 = 0xffffffff;
    }
    else {
      for (; 0 < iVar3; iVar3 = iVar3 - iVar4) {
        yaffsfs_Lock(param_1);
        local_3c = iVar7 >> 0x1f;
        local_40 = iVar7;
        local_38 = iVar7;
        local_34 = local_3c;
        yaffs_AddrToChunk(*(undefined4 *)(iVar2 + 8),iVar7,local_3c,&local_50,&local_48);
        local_50 = local_50 + 1;
        iVar4 = iVar3;
        if (*(int *)(*(int *)(iVar2 + 8) + 0x9c) <= local_48 + iVar3) {
          iVar4 = *(int *)(*(int *)(iVar2 + 8) + 0x9c) - local_48;
        }
        iVar6 = yaffs_FindChunkInFile(iVar2,local_50,0);
        yaffsfs_Unlock(param_1);
        if (iVar6 == -1) {
          *puVar5 = 0;
        }
        else {
          *puVar5 = (short)iVar6;
        }
        puVar5 = puVar5 + 1;
        iVar7 = iVar7 + iVar4;
      }
      yaffs_close(param_1,uVar1);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffsCheckFileSavings @ 0x300241B4  (примерный размер ~404 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, fclose, fopen, free, yaffsGetFileSavings
 * Константы: 0xFFFFFFFF, 0x300241B4
 * Данные: DAT_3002433c, DAT_30024340, DAT_30024344
 * ---------------------------------------------------------------- */
undefined4 yaffsCheckFileSavings(undefined4 param_1,char *param_2)

{
  FILE *__stream;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  void *local_28;
  uint local_24;
  
  local_28 = (void *)0x0;
  __stream = fopen(param_2,DAT_3002433c);
  if (__stream == (FILE *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    fclose(__stream);
    iVar2 = yaffsGetFileSavings(param_1,param_2,&local_28,&local_24);
    if (iVar2 == 0) {
      uVar3 = local_24 & DAT_30024340;
      if ((int)local_24 < 0) {
        uVar3 = -(-local_24 & DAT_30024340);
      }
      for (iVar2 = 0;
          iVar2 < (int)(((int)(local_24 + ((uint)((int)local_24 >> 0x1f) >> 0x15)) >> 0xb) +
                       (uint)(uVar3 != 0)); iVar2 = iVar2 + 1) {
        if (*(short *)((int)local_28 + iVar2 * 2) == 0) {
          OSAL_LogMsg(DAT_30024344,param_2,0,0,0,0,0);
          free(local_28);
          return 0xffffffff;
        }
      }
    }
    if (local_28 != (void *)0x0) {
      free(local_28);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30024348 @ 0x30024348  (примерный размер ~40 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_opendir
 * Константы: 0x30024348
 * ---------------------------------------------------------------- */
void FUN_30024348(int *param_1,int *param_2)

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
 * FUN_30024370 @ 0x30024370  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_closedir
 * Константы: 0x30024370
 * ---------------------------------------------------------------- */
void FUN_30024370(int *param_1)

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
 * FUN_30024390 @ 0x30024390  (примерный размер ~124 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_initialise
 * Константы: 0x30024390
 * Данные: DAT_30025348, DAT_3002534c
 * ---------------------------------------------------------------- */
undefined4 FUN_30024390(int param_1)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 200; iVar1 = iVar1 + 1) {
    *(byte *)(param_1 * 0x960 + DAT_30025348 + iVar1 * 0xc) =
         *(byte *)(param_1 * 0x960 + DAT_30025348 + iVar1 * 0xc) & 0xfe;
    *(undefined4 *)(param_1 * 0x960 + DAT_3002534c + iVar1 * 0xc) = 0;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * yaffsfs_GetHandlePointer @ 0x3002440C  (примерный размер ~64 байт)
 * Модуль: flash | Вызывают: 11 | Вызывает: 0
 * Вызывают: FUN_300244f0, yaffsGetFileSavings, yaffsIoctl, yaffs_close, yaffs_lseek, yaffs_open, yaffs_read, yaffs_truncate, yaffs_write, yaffsfs_GetHandle
 *           ...
 * Константы: 0x3002440C
 * Данные: DAT_30025348
 * ---------------------------------------------------------------- */
int yaffsfs_GetHandlePointer(int param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 < 200) {
    iVar1 = DAT_30025348 + param_1 * 0x960 + param_2 * 0xc;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * yaffsfs_GetHandleObject @ 0x3002444C  (примерный размер ~64 байт)
 * Модуль: flash | Вызывают: 8 | Вызывает: 1
 * Вызывает: yaffsfs_GetHandlePointer
 * Вызывают: yaffsGetFileSavings, yaffsIoctl, yaffs_fchmod, yaffs_fstat, yaffs_lseek, yaffs_read, yaffs_truncate, yaffs_write
 * Константы: 0x3002444C
 * ---------------------------------------------------------------- */
undefined4 yaffsfs_GetHandleObject(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  undefined4 uVar2;
  
  pbVar1 = (byte *)yaffsfs_GetHandlePointer(param_1,param_2);
  if ((pbVar1 == (byte *)0x0) || ((*pbVar1 & 1) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(pbVar1 + 8);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffsfs_GetHandle @ 0x3002448C  (примерный размер ~100 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: memset, yaffsfs_GetHandlePointer
 * Вызывают: yaffs_open
 * Константы: 0x3002448C
 * ---------------------------------------------------------------- */
int yaffsfs_GetHandle(undefined4 param_1)

{
  byte *__s;
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (199 < iVar1) {
      return -1;
    }
    __s = (byte *)yaffsfs_GetHandlePointer(param_1,iVar1);
    if ((*__s & 1) == 0) break;
    iVar1 = iVar1 + 1;
  }
  memset(__s,0,0xc);
  *__s = *__s | 1;
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300244f0 @ 0x300244F0  (примерный размер ~64 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: yaffsfs_GetHandlePointer
 * Вызывают: yaffs_close, yaffs_open
 * Константы: 0x300244F0
 * ---------------------------------------------------------------- */
undefined4 FUN_300244f0(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)yaffsfs_GetHandlePointer(param_1,param_2);
  if (pbVar1 != (byte *)0x0) {
    *pbVar1 = *pbVar1 & 0xfe;
    pbVar1[8] = 0;
    pbVar1[9] = 0;
    pbVar1[10] = 0;
    pbVar1[0xb] = 0;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * yaffsfs_Match @ 0x30024530  (примерный размер ~40 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30024558
 * Константы: 0x30024530
 * ---------------------------------------------------------------- */
bool yaffsfs_Match(char param_1,char param_2)

{
  return param_1 == param_2;
}

/* ----------------------------------------------------------------
 * FUN_30024558 @ 0x30024558  (примерный размер ~252 байт)
 * Модуль: flash | Вызывают: 4 | Вызывает: 2
 * Вызывает: strcmp, yaffsfs_Match
 * Вызывают: FUN_30024654, yaffs_freespace, yaffs_mount, yaffs_unmount
 * Константы: 0x30024558
 * Данные: DAT_300254a0, DAT_300254a4
 * ---------------------------------------------------------------- */
int FUN_30024558(char *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__s1;
  char *pcVar5;
  int *piVar6;
  
  iVar4 = 0;
  iVar2 = -1;
  for (piVar6 = (int *)*DAT_300254a0; ((piVar6 != (int *)0x0 && (*piVar6 != 0)) && (piVar6[1] != 0))
      ; piVar6 = piVar6 + 2) {
    __s1 = (char *)*piVar6;
    iVar3 = 0;
    pcVar5 = param_1;
    while (((*__s1 != '\0' && (iVar1 = strcmp(__s1,DAT_300254a4), iVar1 != 0)) &&
           ((*pcVar5 != '\0' && (iVar1 = yaffsfs_Match((int)*__s1,(int)*pcVar5), iVar1 != 0))))) {
      __s1 = __s1 + 1;
      pcVar5 = pcVar5 + 1;
      iVar3 = iVar3 + 1;
    }
    if ((((*__s1 == '\0') || (iVar1 = strcmp(__s1,DAT_300254a4), iVar1 == 0)) &&
        ((*pcVar5 == '\0' || (*pcVar5 == '/')))) && (iVar2 < iVar3)) {
      *param_2 = pcVar5;
      iVar4 = piVar6[1];
      iVar2 = iVar3;
    }
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * FUN_30024654 @ 0x30024654  (примерный размер ~468 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_30024558
 * Вызывают: FUN_30024828, yaffs_DumpDevStruct
 * Константы: 0x30024654
 * ---------------------------------------------------------------- */
undefined4 FUN_30024654(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_30024558(param_1,param_2);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0xd0) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0xd88);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30024828 @ 0x30024828  (примерный размер ~44 байт)
 * Модуль: flash | Вызывают: 7 | Вызывает: 4
 * Вызывает: FUN_30024654, FUN_300248b4, strcmp, yaffs_FindObjectByName
 * Вызывают: yaffs_link, yaffs_mkdir, yaffs_open, yaffs_rename, yaffs_symlink, yaffsfs_DoUnlink, yaffsfs_FindObject
 * Константы: 0x30024828
 * Данные: DAT_300256d4, DAT_300256d8
 * ---------------------------------------------------------------- */
int FUN_30024828(int param_1,char *param_2,undefined4 *param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  char *local_120;
  char local_11c [256];
  
  if (param_4 < 6) {
    pcVar1 = param_2;
    if (param_1 == 0) {
      param_1 = FUN_30024654(param_2,&local_120);
      pcVar1 = local_120;
    }
    do {
      while( true ) {
        do {
          local_120 = pcVar1;
          if (param_1 == 0) {
            return 0;
          }
          for (; *local_120 == '/'; local_120 = local_120 + 1) {
          }
          *param_3 = local_120;
          iVar2 = 0;
          for (; (*local_120 != '\0' && (*local_120 != '/')); local_120 = local_120 + 1) {
            if (iVar2 < 0xff) {
              local_11c[iVar2] = *local_120;
              local_11c[iVar2 + 1] = '\0';
              iVar2 = iVar2 + 1;
            }
          }
          if (*local_120 == '\0') {
            return param_1;
          }
          iVar2 = strcmp(local_11c,DAT_300256d4);
          pcVar1 = local_120;
        } while (iVar2 == 0);
        iVar2 = strcmp(local_11c,DAT_300256d8);
        if (iVar2 != 0) break;
        param_1 = *(int *)(param_1 + 0x1c);
        pcVar1 = local_120;
      }
      for (param_1 = yaffs_FindObjectByName(param_1,local_11c);
          (param_1 != 0 && (*(int *)(param_1 + 100) == 2)); param_1 = FUN_300248b4(param_1,param_4))
      {
      }
      pcVar1 = local_120;
    } while ((param_1 == 0) || (*(int *)(param_1 + 100) == 3));
  }
  return 0;
}

/* ----------------------------------------------------------------
 * yaffsfs_FindObject @ 0x30024854  (примерный размер ~96 байт)
 * Модуль: flash | Вызывают: 11 | Вызывает: 2
 * Вызывает: FUN_30024828, yaffs_FindObjectByName
 * Вызывают: FUN_300248b4, yaffs_FileIsOpen, yaffs_chmod, yaffs_link, yaffs_lstat, yaffs_open, yaffs_opendir, yaffs_readlink, yaffs_rename, yaffs_stat
 *           ...
 * Константы: 0x30024854
 * ---------------------------------------------------------------- */
int yaffsfs_FindObject(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char *local_18;
  
  iVar1 = FUN_30024828(param_1,param_2,&local_18,param_3);
  if ((iVar1 != 0) && (*local_18 != '\0')) {
    iVar1 = yaffs_FindObjectByName(iVar1,local_18);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300248b4 @ 0x300248B4  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 1
 * Вызывает: yaffsfs_FindObject
 * Вызывают: FUN_30024828, yaffs_open, yaffs_stat
 * Константы: 0x300248B4
 * ---------------------------------------------------------------- */
int FUN_300248b4(int param_1,int param_2)

{
  char *pcVar1;
  
  while ((param_1 != 0 && (*(int *)(param_1 + 100) == 2))) {
    pcVar1 = *(char **)(param_1 + 0x68);
    if (*pcVar1 == '/') {
      param_1 = yaffsfs_FindObject(0,pcVar1,param_2);
      param_2 = param_2 + 1;
    }
    else {
      param_1 = yaffsfs_FindObject(*(undefined4 *)(param_1 + 0x1c),pcVar1,param_2);
      param_2 = param_2 + 1;
    }
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * yaffs_open @ 0x3002492C  (примерный размер ~900 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 11
 * Вызывает: FUN_300244f0, FUN_30024828, FUN_300248b4, yaffs_MknodFile, yaffs_ResizeFile, yaffsfs_FindObject, yaffsfs_GetHandle, yaffsfs_GetHandlePointer, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Вызывают: yaffsCreate, yaffsGetFileSavings, yaffsOpen
 * Константы: 0x3002492C, 0xFFFFFFEC, 0xFFFFFFEF, 0xFFFFFFF3
 * Данные: DAT_30025348, DAT_3002534c
 * ---------------------------------------------------------------- */
int yaffs_open(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  undefined4 local_30;
  
  bVar2 = false;
  bVar7 = false;
  yaffsfs_Lock(param_1);
  iVar3 = yaffsfs_GetHandle(param_1);
  if (-1 < iVar3) {
    pbVar4 = (byte *)yaffsfs_GetHandlePointer(param_1,iVar3);
    iVar5 = yaffsfs_FindObject(0,param_2,0);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 100) == 2)) {
      iVar5 = FUN_300248b4(iVar5,0);
    }
    if (iVar5 == 0) {
      if ((param_3 & 0x200) != 0) {
        iVar6 = FUN_30024828(0,param_2,&local_30,0);
        if (iVar6 == 0) {
          yaffsfs_SetError(0xffffffec);
        }
        else {
          iVar5 = yaffs_MknodFile(iVar6,local_30,param_4,0,0);
        }
      }
    }
    else {
      bVar1 = false;
      bVar7 = false;
      for (iVar6 = 0; iVar6 < 200; iVar6 = iVar6 + 1) {
        if ((((iVar6 != iVar3) &&
             ((*(byte *)(param_1 * 0x960 + DAT_30025348 + iVar6 * 0xc) & 1) != 0)) &&
            (*(int *)(DAT_3002534c + iVar6 * 0xc + param_1 * 0x960) == iVar5)) &&
           (bVar7 = true, (*(byte *)(param_1 * 0x960 + DAT_30025348 + iVar6 * 0xc) & 8) != 0)) {
          bVar1 = true;
        }
      }
      if ((((param_3 & 0x800) != 0) && (bVar7)) || (bVar1)) {
        bVar2 = true;
      }
      bVar7 = (param_3 & 0xa00) == 0xa00;
      if (bVar7) {
        bVar2 = true;
        yaffsfs_SetError(0xffffffef);
      }
      if (((param_3 & 3) == 0) && ((*(uint *)(iVar5 + 0x34) & 0x100) == 0)) {
        bVar2 = true;
      }
      if (((param_3 & 2) != 0) && ((*(uint *)(iVar5 + 0x34) & 0x100) == 0)) {
        bVar2 = true;
      }
      if (((param_3 & 3) != 0) && ((*(uint *)(iVar5 + 0x34) & 0x80) == 0)) {
        bVar2 = true;
      }
    }
    if ((iVar5 == 0) || (bVar2)) {
      FUN_300244f0(param_1,iVar3);
      if (!bVar7) {
        yaffsfs_SetError(0xfffffff3);
      }
      iVar3 = -1;
    }
    else {
      *(int *)(pbVar4 + 8) = iVar5;
      *pbVar4 = *pbVar4 | 1;
      *pbVar4 = *pbVar4 & 0xfd | ((param_3 & 3) == 0) << 1;
      *pbVar4 = *pbVar4 & 0xfb | (byte)(((int)param_3 >> 3 & 1U) << 2);
      *pbVar4 = *pbVar4 & 0xf7 | (byte)(((int)param_3 >> 0xb & 1U) << 3);
      pbVar4[4] = 0;
      pbVar4[5] = 0;
      pbVar4[6] = 0;
      pbVar4[7] = 0;
      *(int *)(iVar5 + 0x48) = *(int *)(iVar5 + 0x48) + 1;
      if (((param_3 & 0x400) != 0) && ((*pbVar4 & 2) == 0)) {
        yaffs_ResizeFile(iVar5,0,0);
      }
    }
  }
  yaffsfs_Unlock(param_1);
  return iVar3;
}

/* ----------------------------------------------------------------
 * yaffs_close @ 0x30024CB0  (примерный размер ~188 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_300244f0, yaffs_DeleteFile, yaffs_FlushFile, yaffsfs_GetHandlePointer, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Вызывают: yaffsClose, yaffsGetFileSavings
 * Константы: 0x30024CB0, 0xFFFFFFF7, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 yaffs_close(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  undefined4 uVar2;
  
  yaffsfs_Lock(param_1);
  pbVar1 = (byte *)yaffsfs_GetHandlePointer(param_1,param_2);
  if ((pbVar1 == (byte *)0x0) || ((*pbVar1 & 1) == 0)) {
    yaffsfs_SetError(0xfffffff7);
    uVar2 = 0xffffffff;
  }
  else {
    yaffs_FlushFile(*(undefined4 *)(pbVar1 + 8),1,0);
    *(int *)(*(int *)(pbVar1 + 8) + 0x48) = *(int *)(*(int *)(pbVar1 + 8) + 0x48) + -1;
    if ((*(int *)(*(int *)(pbVar1 + 8) + 0x48) == 0) && ((**(byte **)(pbVar1 + 8) & 4) != 0)) {
      yaffs_DeleteFile(*(undefined4 *)(pbVar1 + 8));
    }
    FUN_300244f0(param_1,param_2);
    uVar2 = 0;
  }
  yaffsfs_Unlock(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_read @ 0x30024D6C  (примерный размер ~316 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 7
 * Вызывает: yaffs_GetObjectFileLength, yaffs_ReadDataFromFile, yaffsfs_GetHandleObject, yaffsfs_GetHandlePointer, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Вызывают: yaffsRead
 * Константы: 0x30024D6C, 0xFFFFFFF7
 * ---------------------------------------------------------------- */
int yaffs_read(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = -1;
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_GetHandlePointer(param_1,param_2);
  iVar2 = yaffsfs_GetHandleObject(param_1,param_2);
  if ((iVar1 == 0) || (iVar2 == 0)) {
    yaffsfs_SetError(0xfffffff7);
  }
  else if ((iVar1 != 0) && (iVar2 != 0)) {
    iVar3 = *(int *)(iVar1 + 4);
    iVar4 = yaffs_GetObjectFileLength(iVar2);
    if (iVar3 < iVar4) {
      iVar4 = yaffs_GetObjectFileLength(iVar2);
      uVar5 = iVar4 - iVar3;
    }
    else {
      uVar5 = 0;
    }
    if (uVar5 < param_4) {
      param_4 = uVar5;
    }
    if (param_4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = yaffs_ReadDataFromFile(iVar2,param_3,iVar3,iVar3 >> 0x1f,param_4);
      if (-1 < iVar4) {
        *(int *)(iVar1 + 4) = iVar3 + iVar4;
      }
    }
  }
  yaffsfs_Unlock(param_1);
  if (iVar4 < 0) {
    iVar4 = -1;
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * yaffs_write @ 0x30024EA8  (примерный размер ~308 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 7
 * Вызывает: yaffs_GetObjectFileLength, yaffs_WriteDataToFile, yaffsfs_GetHandleObject, yaffsfs_GetHandlePointer, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Вызывают: yaffsWrite
 * Константы: 0x30024EA8, 0xFFFFFFF7
 * ---------------------------------------------------------------- */
int yaffs_write(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = -1;
  yaffsfs_Lock(param_1);
  pbVar1 = (byte *)yaffsfs_GetHandlePointer(param_1,param_2);
  iVar2 = yaffsfs_GetHandleObject(param_1,param_2);
  if ((pbVar1 == (byte *)0x0) || (iVar2 == 0)) {
    yaffsfs_SetError(0xfffffff7);
  }
  else if ((((pbVar1 == (byte *)0x0) || (iVar2 == 0)) || ((*pbVar1 & 2) == 0)) &&
          ((pbVar1 != (byte *)0x0 && (iVar2 != 0)))) {
    if ((*pbVar1 & 4) == 0) {
      iVar3 = *(int *)(pbVar1 + 4);
    }
    else {
      iVar3 = yaffs_GetObjectFileLength(iVar2);
    }
    iVar4 = yaffs_WriteDataToFile(iVar2,param_3,iVar3,iVar3 >> 0x1f,param_4,0);
    if (-1 < iVar4) {
      *(int *)(pbVar1 + 4) = iVar3 + iVar4;
    }
  }
  yaffsfs_Unlock(param_1);
  if (iVar4 < 0) {
    iVar4 = -1;
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * yaffs_truncate @ 0x30024FDC  (примерный размер ~160 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 6
 * Вызывает: yaffs_ResizeFile, yaffsfs_GetHandleObject, yaffsfs_GetHandlePointer, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Константы: 0x30024FDC, 0xFFFFFFF7, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 yaffs_truncate(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_GetHandlePointer(param_1,param_2);
  iVar2 = yaffsfs_GetHandleObject(param_1,param_2);
  if ((iVar1 == 0) || (iVar2 == 0)) {
    yaffsfs_SetError(0xfffffff7);
  }
  else {
    iVar3 = yaffs_ResizeFile(iVar2,param_3,param_3 >> 0x1f);
  }
  yaffsfs_Unlock(param_1);
  if (iVar3 == 0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * yaffs_lseek @ 0x3002507C  (примерный размер ~220 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 6
 * Вызывает: yaffs_GetObjectFileLength, yaffsfs_GetHandleObject, yaffsfs_GetHandlePointer, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Вызывают: yaffsIoctl
 * Константы: 0x3002507C, 0xFFFFFFF7
 * ---------------------------------------------------------------- */
int yaffs_lseek(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = -1;
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_GetHandlePointer(param_1,param_2);
  iVar2 = yaffsfs_GetHandleObject(param_1,param_2);
  if ((iVar1 == 0) || (iVar2 == 0)) {
    yaffsfs_SetError(0xfffffff7);
  }
  else if (param_4 == 0) {
    if (-1 < param_3) {
      iVar3 = param_3;
    }
  }
  else if (param_4 == 1) {
    iVar3 = param_3 + *(int *)(iVar1 + 4);
  }
  else if (((param_4 == 2) && (iVar2 = yaffs_GetObjectFileLength(iVar2), -1 < iVar2)) &&
          (-1 < iVar2 + param_3)) {
    iVar3 = iVar2 + param_3;
  }
  if (-1 < iVar3) {
    *(int *)(iVar1 + 4) = iVar3;
  }
  yaffsfs_Unlock(param_1);
  return iVar3;
}

/* ----------------------------------------------------------------
 * yaffsfs_DoUnlink @ 0x30025158  (примерный размер ~268 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_30024828, yaffs_Unlink, yaffsfs_FindObject, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Вызывают: yaffs_rmdir, yaffs_unlink
 * Константы: 0xFFFFFFEC, 0x30025158, 0xFFFFFFFE, 0xFFFFFFEB, 0xFFFFFFF1, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 yaffsfs_DoUnlink(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_24;
  
  iVar3 = 0;
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_FindObject(0,param_2,0);
  iVar2 = FUN_30024828(0,param_2,&local_24,0);
  if (iVar2 == 0) {
    yaffsfs_SetError(0xffffffec);
  }
  else if (iVar1 == 0) {
    yaffsfs_SetError(0xfffffffe);
  }
  else if ((param_3 == 0) && (*(int *)(iVar1 + 100) == 3)) {
    yaffsfs_SetError(0xffffffeb);
  }
  else if ((param_3 == 0) || (*(int *)(iVar1 + 100) == 3)) {
    iVar3 = yaffs_Unlink(iVar2,local_24);
    if ((iVar3 == 0) && (param_3 != 0)) {
      yaffsfs_SetError(0xfffffff1);
    }
  }
  else {
    yaffsfs_SetError(0xffffffec);
  }
  yaffsfs_Unlock(param_1);
  if (iVar3 == 0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * yaffs_rmdir @ 0x30025264  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: yaffsfs_DoUnlink
 * Вызывают: yaffsIoctl
 * Константы: 0x30025264
 * ---------------------------------------------------------------- */
void yaffs_rmdir(undefined4 param_1,undefined4 param_2)

{
  yaffsfs_DoUnlink(param_1,param_2,1);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_unlink @ 0x30025284  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: yaffsfs_DoUnlink
 * Вызывают: yaffsDelete, yaffsIoctl
 * Константы: 0x30025284
 * ---------------------------------------------------------------- */
void yaffs_unlink(undefined4 param_1,undefined4 param_2)

{
  yaffsfs_DoUnlink(param_1,param_2,0);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_rename @ 0x300252A4  (примерный размер ~368 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_30024828, yaffs_RenameObject, yaffsfs_FindObject, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Вызывают: yaffsIoctl
 * Константы: 0x300252A4, 0xFFFFFFF7, 0xFFFFFFF3, 0xFFFFFFEE, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 yaffs_rename(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_34;
  undefined4 local_30;
  
  iVar5 = 0;
  bVar1 = true;
  yaffsfs_Lock(param_1);
  iVar2 = FUN_30024828(0,param_2,&local_34,0);
  iVar3 = FUN_30024828(0,param_3,&local_30,0);
  iVar4 = yaffsfs_FindObject(0,param_2,0);
  if (((iVar2 == 0) || (iVar3 == 0)) || (iVar4 == 0)) {
    yaffsfs_SetError(0xfffffff7);
  }
  else if (*(int *)(iVar2 + 8) == *(int *)(iVar3 + 8)) {
    if ((iVar4 != 0) && (iVar7 = iVar3, *(int *)(iVar4 + 100) == 3)) {
      for (; (bVar1 && (iVar7 != 0)); iVar7 = *(int *)(iVar7 + 0x1c)) {
        if (iVar7 == iVar4) {
          bVar1 = false;
        }
      }
      if (!bVar1) {
        yaffsfs_SetError(0xfffffff3);
      }
    }
    if (bVar1) {
      iVar5 = yaffs_RenameObject(iVar2,local_34,iVar3,local_30);
    }
  }
  else {
    yaffsfs_SetError(0xffffffee);
  }
  yaffsfs_Unlock(param_1);
  if (iVar5 == 0) {
    uVar6 = 0xffffffff;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}

/* ----------------------------------------------------------------
 * FUN_30025414 @ 0x30025414  (примерный размер ~432 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 4
 * Вызывает: __udiv32, yaffs_GetEquivalentObject, yaffs_GetObjectFileLength, yaffs_GetObjectLinkCount
 * Вызывают: yaffs_fstat, yaffs_lstat, yaffs_stat
 * Константы: 0x30025414, 0xFFFFFFFF, 0xFFFF0FFF
 * ---------------------------------------------------------------- */
undefined4 FUN_30025414(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    param_1 = yaffs_GetEquivalentObject(param_1);
  }
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xa0);
    param_2[1] = *(undefined4 *)(param_1 + 0x30);
    param_2[2] = *(uint *)(param_1 + 0x34) & 0xffff0fff;
    if (*(int *)(param_1 + 100) == 3) {
      param_2[2] = param_2[2] | 0x4000;
    }
    else if (*(int *)(param_1 + 100) == 2) {
      param_2[2] = param_2[2] | 0xa000;
    }
    else if (*(int *)(param_1 + 100) == 1) {
      param_2[2] = param_2[2] | 0x8000;
    }
    uVar1 = yaffs_GetObjectLinkCount(param_1);
    param_2[3] = uVar1;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = *(undefined4 *)(param_1 + 0x60);
    uVar1 = yaffs_GetObjectFileLength(param_1);
    param_2[7] = uVar1;
    param_2[8] = *(undefined4 *)(*(int *)(param_1 + 8) + 0x9c);
    uVar1 = __udiv32(param_2[7] + param_2[8] + -1,param_2[8]);
    param_2[9] = uVar1;
    param_2[10] = *(undefined4 *)(param_1 + 0x54);
    param_2[0xc] = *(undefined4 *)(param_1 + 0x5c);
    param_2[0xb] = *(undefined4 *)(param_1 + 0x58);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_stat @ 0x300255C4  (примерный размер ~40 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_300248b4, FUN_30025414, yaffsfs_FindObject, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Вызывают: yaffsIoctl, yaffsOpen
 * Константы: 0x300255C4, 0xFFFFFFFF, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4 yaffs_stat(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_FindObject(0,param_2,0);
  if (iVar1 != 0) {
    iVar1 = FUN_300248b4(iVar1,0);
  }
  if (iVar1 == 0) {
    yaffsfs_SetError(0xfffffffe);
  }
  else {
    uVar2 = FUN_30025414(iVar1,param_3);
  }
  yaffsfs_Unlock(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_lstat @ 0x300255EC  (примерный размер ~40 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_30025414, yaffsfs_FindObject, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Константы: 0x300255EC, 0x30025578, 0x30025580, 0xFFFFFFFF, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x30025578) */
/* WARNING: Removing unreachable block (ram,0x30025580) */

undefined4 yaffs_lstat(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_FindObject(0,param_2,0);
  if (iVar1 == 0) {
    yaffsfs_SetError(0xfffffffe);
  }
  else {
    uVar2 = FUN_30025414(iVar1,param_3);
  }
  yaffsfs_Unlock(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_fstat @ 0x30025614  (примерный размер ~96 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_30025414, yaffsfs_GetHandleObject, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Константы: 0x30025614, 0xFFFFFFFF, 0xFFFFFFF7
 * ---------------------------------------------------------------- */
undefined4 yaffs_fstat(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_GetHandleObject(param_1,param_2);
  if (iVar1 == 0) {
    yaffsfs_SetError(0xfffffff7);
  }
  else {
    uVar2 = FUN_30025414(iVar1,param_3);
  }
  yaffsfs_Unlock(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30025674 @ 0x30025674  (примерный размер ~116 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 2
 * Вызывает: yaffs_FlushFile, yaffs_GetEquivalentObject
 * Вызывают: yaffs_chmod, yaffs_fchmod
 * Константы: 0x30025674, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_30025674(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = 0;
  if (param_1 != (byte *)0x0) {
    param_1 = (byte *)yaffs_GetEquivalentObject(param_1);
  }
  if (param_1 != (byte *)0x0) {
    *(undefined4 *)(param_1 + 0x34) = param_2;
    *param_1 = *param_1 | 0x40;
    iVar1 = yaffs_FlushFile(param_1,0,0);
  }
  if (iVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_chmod @ 0x300256E8  (примерный размер ~100 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_30025674, yaffsfs_FindObject, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Константы: 0x300256E8, 0xFFFFFFFF, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4 yaffs_chmod(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_FindObject(0,param_2,0);
  if (iVar1 == 0) {
    yaffsfs_SetError(0xfffffffe);
  }
  else {
    uVar2 = FUN_30025674(iVar1,param_3);
  }
  yaffsfs_Unlock(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_fchmod @ 0x3002574C  (примерный размер ~96 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_30025674, yaffsfs_GetHandleObject, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Константы: 0x3002574C, 0xFFFFFFFF, 0xFFFFFFF7
 * ---------------------------------------------------------------- */
undefined4 yaffs_fchmod(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_GetHandleObject(param_1,param_2);
  if (iVar1 == 0) {
    yaffsfs_SetError(0xfffffff7);
  }
  else {
    uVar2 = FUN_30025674(iVar1,param_3);
  }
  yaffsfs_Unlock(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_mkdir @ 0x300257AC  (примерный размер ~156 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_30024828, yaffs_MknodDirectory, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Вызывают: yaffsOpen
 * Константы: 0x300257AC, 0xFFFFFFE4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 yaffs_mkdir(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_20;
  
  iVar3 = 0;
  yaffsfs_Lock(param_1);
  iVar1 = FUN_30024828(0,param_2,&local_20,0);
  if (iVar1 != 0) {
    iVar3 = yaffs_MknodDirectory(iVar1,local_20,param_3,0,0);
  }
  if (iVar3 == 0) {
    yaffsfs_SetError(0xffffffe4);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  yaffsfs_Unlock(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_mount @ 0x30025848  (примерный размер ~204 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_30024558, printf, yaffs_GutsInitialise, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock, ynandif_InitialiseNAND
 * Вызывают: ptable_yaffs_mount_byname, yaffsDevCreate
 * Константы: 0xFFFFFFFF, 0x30025848, 0xFFFFFFED, 0xFFFFFFF4, 0xFFFFFFF0
 * Данные: DAT_300262fc
 * ---------------------------------------------------------------- */
undefined4 yaffs_mount(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_1c [4];
  
  uVar2 = 0xffffffff;
  printf(DAT_300262fc,param_2);
  yaffsfs_Lock(param_1);
  iVar1 = FUN_30024558(param_2,auStack_1c);
  ynandif_InitialiseNAND(iVar1);
  if (iVar1 == 0) {
    yaffsfs_SetError(0xffffffed);
  }
  else if (*(int *)(iVar1 + 0xd0) == 0) {
    iVar1 = yaffs_GutsInitialise(iVar1);
    if (iVar1 == 0) {
      yaffsfs_SetError(0xfffffff4);
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    yaffsfs_SetError(0xfffffff0);
  }
  yaffsfs_Unlock(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_unmount @ 0x30025914  (примерный размер ~280 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_30024558, yaffs_CheckpointSave, yaffs_Deinitialise, yaffs_FlushEntireDeviceCache, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Вызывают: ptable_yaffs_unmount_byname, yaffsDevDelete
 * Константы: 0x30025914, 0xFFFFFFFF, 0xFFFFFFED, 0xFFFFFFEA, 0xFFFFFFF0
 * Данные: DAT_30026300, DAT_30026304
 * ---------------------------------------------------------------- */
undefined4 yaffs_unmount(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_20 [4];
  
  uVar4 = 0xffffffff;
  yaffsfs_Lock(param_1);
  iVar2 = FUN_30024558(param_2,auStack_20);
  if (iVar2 == 0) {
    yaffsfs_SetError(0xffffffed);
  }
  else if (*(int *)(iVar2 + 0xd0) == 0) {
    yaffsfs_SetError(0xffffffea);
  }
  else {
    *(undefined4 *)(iVar2 + 0xd0) = 0;
    yaffs_FlushEntireDeviceCache(iVar2);
    yaffs_CheckpointSave(iVar2);
    bVar1 = false;
    iVar3 = 0;
    while ((iVar3 < 200 && (!bVar1))) {
      if (((*(byte *)(param_1 * 0x960 + DAT_30026300 + iVar3 * 0xc) & 1) != 0) &&
         (*(int *)(*(int *)(DAT_30026304 + iVar3 * 0xc + param_1 * 0x960) + 8) == iVar2)) {
        bVar1 = true;
      }
      iVar3 = iVar3 + 1;
    }
    if (bVar1) {
      yaffsfs_SetError(0xfffffff0);
    }
    else {
      yaffs_Deinitialise(iVar2);
      uVar4 = 0;
    }
  }
  yaffsfs_Unlock(param_1);
  return uVar4;
}

/* ----------------------------------------------------------------
 * yaffs_freespace @ 0x30025A2C  (примерный размер ~260 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_30024558, __mul64, yaffs_GetNumberOfFreeChunks, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Вызывают: getdskspc, yaffsMemShow
 * Константы: 0xFFFFFFFF, 0x30025A2C, 0xFFFFFFEA
 * ---------------------------------------------------------------- */
undefined8 yaffs_freespace(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_4c [8];
  undefined8 local_44;
  undefined8 local_3c;
  int local_34;
  int local_30;
  undefined8 local_2c;
  int local_24;
  int local_20;
  undefined8 local_1c;
  
  local_44._0_4_ = 0xffffffff;
  local_44._4_4_ = 0xffffffff;
  yaffsfs_Lock(param_1);
  iVar1 = FUN_30024558(param_2,auStack_4c);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0xd0) == 0)) {
    yaffsfs_SetError(0xffffffea);
  }
  else {
    local_44._0_4_ = yaffs_GetNumberOfFreeChunks(iVar1);
    local_44._4_4_ = (int)local_44 >> 0x1f;
    local_34 = (int)local_44;
    local_30 = local_44._4_4_;
    local_24 = (int)local_44;
    local_20 = local_44._4_4_;
    local_44 = __mul64((int)local_44,local_44._4_4_,*(int *)(iVar1 + 0x9c),
                       *(int *)(iVar1 + 0x9c) >> 0x1f);
    local_3c = local_44;
    local_2c = local_44;
    local_1c = local_44;
  }
  yaffsfs_Unlock(param_1);
  return local_44;
}

/* ----------------------------------------------------------------
 * yaffs_initialise @ 0x30025B30  (примерный размер ~304 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30024390, printf
 * Вызывают: yaffs_StartUp
 * Константы: 0x30025B30
 * Данные: DAT_30026308, DAT_3002630c, DAT_30026310, DAT_30026314, DAT_30026318
 * ---------------------------------------------------------------- */
void yaffs_initialise(int *param_1,int *param_2)

{
  if (*DAT_30026308 == 0) {
    *DAT_30026308 = (int)param_1;
  }
  else if ((int *)*DAT_30026308 != param_1) {
    printf(DAT_3002630c);
  }
  for (; *param_1 != 0; param_1 = param_1 + 2) {
  }
  if ((uint)((int)param_1 - *DAT_30026308 >> 3) >> 3 < 9) {
    *param_1 = *param_2;
    param_1[1] = (int)param_2;
    if (((param_1 != (int *)0x0) && (*param_1 != 0)) && (param_1[1] != 0)) {
      if (*(int *)(param_1[1] + 0xd0) == 0) {
        *(undefined4 *)(param_1[1] + 0xd0) = 0;
        *(undefined4 *)(param_1[1] + 100) = DAT_30026314;
        FUN_30024390(*(undefined4 *)(param_1[1] + 0x98));
      }
      else {
        printf(DAT_30026318,*param_1);
      }
    }
  }
  else {
    printf(DAT_30026310);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30025c60 @ 0x30025C60  (примерный размер ~104 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_300262d8
 * Вызывают: yaffs_opendir, yaffs_rewinddir
 * Константы: 0x30025C60
 * ---------------------------------------------------------------- */
void FUN_30025c60(int param_1)

{
  int iVar1;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x214) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0x214) + 100) == 3)) {
    *(undefined4 *)(param_1 + 0x21c) = 0;
    iVar1 = FUN_300262d8(*(int *)(param_1 + 0x214) + 0x68);
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x218) = *(int *)(*(int *)(param_1 + 0x214) + 0x68) + -0x20;
    }
    else {
      *(undefined4 *)(param_1 + 0x218) = 0;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30025cc8 @ 0x30025CC8  (примерный размер ~140 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_300262d8
 * Вызывают: FUN_30025d54, yaffs_readdir
 * Константы: 0x30025CC8
 * ---------------------------------------------------------------- */
void FUN_30025cc8(int param_1)

{
  int iVar1;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x214) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0x214) + 100) == 3)) {
    if ((*(int *)(param_1 + 0x218) == 0) ||
       (iVar1 = FUN_300262d8(*(int *)(param_1 + 0x214) + 0x68), iVar1 != 0)) {
      *(undefined4 *)(param_1 + 0x218) = 0;
    }
    else {
      iVar1 = *(int *)(*(int *)(param_1 + 0x218) + 0x20);
      if (*(int *)(param_1 + 0x214) + 0x68 == iVar1) {
        *(undefined4 *)(param_1 + 0x218) = 0;
      }
      else {
        *(int *)(param_1 + 0x218) = iVar1 + -0x20;
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30025d54 @ 0x30025D54  (примерный размер ~104 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_30025cc8
 * Константы: 0x30025D54
 * Данные: DAT_3002631c
 * ---------------------------------------------------------------- */
void FUN_30025d54(int param_1)

{
  int *piVar1;
  
  if (*DAT_3002631c != 0) {
    for (piVar1 = (int *)*DAT_3002631c; DAT_3002631c != piVar1; piVar1 = (int *)*piVar1) {
      if ((piVar1 != (int *)0x0) && (piVar1[-2] == param_1)) {
        FUN_30025cc8(piVar1 + -0x88);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_opendir @ 0x30025DBC  (примерный размер ~248 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 8
 * Вызывает: FUN_30024348, FUN_30025c60, malloc, memset, strncpy, yaffsfs_FindObject, yaffsfs_Lock, yaffsfs_Unlock
 * Вызывают: yaffsFormat, yaffsOpen
 * Константы: 0x30025DBC
 * Данные: DAT_3002631c, DAT_30026320
 * ---------------------------------------------------------------- */
undefined4 * yaffs_opendir(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined4 *__s;
  
  __s = (undefined4 *)0x0;
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_FindObject(0,param_2,0);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 100) == 3)) &&
     (__s = (undefined4 *)malloc(0x228), __s != (undefined4 *)0x0)) {
    memset(__s,0,0x228);
    *__s = DAT_30026320;
    __s[0x85] = iVar1;
    strncpy((char *)(__s + 0x45),param_2,0xff);
    __s[0x88] = __s + 0x88;
    __s[0x89] = __s + 0x88;
    if (*DAT_3002631c == 0) {
      *DAT_3002631c = (int)DAT_3002631c;
      DAT_3002631c[1] = (int)DAT_3002631c;
    }
    FUN_30024348(__s + 0x88,DAT_3002631c);
    FUN_30025c60(__s);
  }
  yaffsfs_Unlock(param_1);
  return __s;
}

/* ----------------------------------------------------------------
 * yaffs_readdir @ 0x30025EB4  (примерный размер ~232 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 8
 * Вызывает: FUN_30025cc8, strcpy, strlen, yaffs_GetEquivalentObject, yaffs_GetObjectName, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Вызывают: yaffsFormat, yaffsIoctl
 * Константы: 0x30025EB4, 0xFFFFFFF7
 * Данные: DAT_30026320, DAT_30026324
 * ---------------------------------------------------------------- */
int * yaffs_readdir(undefined4 param_1,int *param_2)

{
  int iVar1;
  size_t sVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  yaffsfs_Lock(param_1);
  if ((param_2 == (int *)0x0) || (*param_2 != DAT_30026320)) {
    yaffsfs_SetError(0xfffffff7);
  }
  else {
    yaffsfs_SetError(0);
    if (param_2[0x86] == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      iVar1 = yaffs_GetEquivalentObject(param_2[0x86]);
      param_2[1] = *(int *)(iVar1 + 0x30);
      param_2[0x44] = param_2[0x86];
      param_2[2] = param_2[0x87];
      param_2[0x87] = param_2[0x87] + 1;
      yaffs_GetObjectName(param_2[0x86],(int)param_2 + 0xe,0xff);
      sVar2 = strlen((char *)((int)param_2 + 0xe));
      if (sVar2 == 0) {
        strcpy((char *)((int)param_2 + 0xe),DAT_30026324);
      }
      *(undefined2 *)(param_2 + 3) = 0x110;
      piVar3 = param_2 + 1;
      FUN_30025cc8(param_2);
    }
  }
  yaffsfs_Unlock(param_1);
  return piVar3;
}

/* ----------------------------------------------------------------
 * yaffs_rewinddir @ 0x30025F9C  (примерный размер ~44 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_30025c60, yaffsfs_Lock, yaffsfs_Unlock
 * Вызывают: yaffsIoctl
 * Константы: 0x30025F9C
 * ---------------------------------------------------------------- */
void yaffs_rewinddir(undefined4 param_1,undefined4 param_2)

{
  yaffsfs_Lock(param_1);
  FUN_30025c60(param_2);
  yaffsfs_Unlock(param_1);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_closedir @ 0x30025FC8  (примерный размер ~68 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_30024370, free, yaffsfs_Lock, yaffsfs_Unlock
 * Вызывают: yaffsClose, yaffsFormat
 * Константы: 0x30025FC8
 * ---------------------------------------------------------------- */
undefined4 yaffs_closedir(undefined4 param_1,undefined4 *param_2)

{
  yaffsfs_Lock(param_1);
  *param_2 = 0;
  FUN_30024370(param_2 + 0x88);
  free(param_2);
  yaffsfs_Unlock(param_1);
  return 0;
}

/* ----------------------------------------------------------------
 * yaffs_symlink @ 0x3002600C  (примерный размер ~152 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_30024828, yaffs_MknodSymLink, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Константы: 0x3002600C, 0xFFFFFFE4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 yaffs_symlink(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_24;
  
  yaffsfs_Lock(param_1);
  uVar1 = FUN_30024828(0,param_3,&local_24,0);
  iVar2 = yaffs_MknodSymLink(uVar1,local_24,0,0,0,param_2);
  if (iVar2 == 0) {
    yaffsfs_SetError(0xffffffe4);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  yaffsfs_Unlock(param_1);
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_readlink @ 0x300260A4  (примерный размер ~160 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 6
 * Вызывает: memset, strncpy, yaffsfs_FindObject, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Константы: 0xFFFFFFFF, 0x300260A4, 0xFFFFFFFE, 0xFFFFFFEA
 * ---------------------------------------------------------------- */
undefined4 yaffs_readlink(undefined4 param_1,undefined4 param_2,char *param_3,size_t param_4)

{
  int iVar1;
  char *__src;
  undefined4 uVar2;
  
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_FindObject(0,param_2,0);
  if (iVar1 == 0) {
    yaffsfs_SetError(0xfffffffe);
    uVar2 = 0xffffffff;
  }
  else if (*(int *)(iVar1 + 100) == 2) {
    __src = *(char **)(iVar1 + 0x68);
    memset(param_3,0,param_4);
    strncpy(param_3,__src,param_4 - 1);
    uVar2 = 0;
  }
  else {
    yaffsfs_SetError(0xffffffea);
    uVar2 = 0xffffffff;
  }
  yaffsfs_Unlock(param_1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_link @ 0x30026144  (примерный размер ~304 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 7
 * Вызывает: FUN_30024828, strlen, yaffs_Link, yaffsfs_FindObject, yaffsfs_Lock, yaffsfs_SetError, yaffsfs_Unlock
 * Константы: 0xFFFFFFFF, 0x30026144, 0xFFFFFFFE, 0xFFFFFFEC, 0xFFFFFFEE, 0xFFFFFFE4, 0xFFFFFFEF
 * ---------------------------------------------------------------- */
undefined4 yaffs_link(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  char *local_28;
  
  uVar4 = 0;
  yaffsfs_Lock(param_1);
  iVar1 = yaffsfs_FindObject(0,param_2,0);
  iVar2 = yaffsfs_FindObject(0,param_3,0);
  if (iVar1 == 0) {
    yaffsfs_SetError(0xfffffffe);
    uVar4 = 0xffffffff;
  }
  else if (iVar2 == 0) {
    iVar2 = FUN_30024828(0,param_3,&local_28,0);
    if (iVar2 == 0) {
      yaffsfs_SetError(0xffffffec);
      uVar4 = 0xffffffff;
    }
    else if (*(int *)(iVar2 + 8) != *(int *)(iVar1 + 8)) {
      yaffsfs_SetError(0xffffffee);
      uVar4 = 0xffffffff;
    }
    if ((iVar2 != 0) && (sVar3 = strlen(local_28), sVar3 != 0)) {
      iVar1 = yaffs_Link(iVar2,local_28,iVar1);
      if (iVar1 == 0) {
        yaffsfs_SetError(0xffffffe4);
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = 0;
      }
    }
  }
  else {
    yaffsfs_SetError(0xffffffef);
    uVar4 = 0xffffffff;
  }
  yaffsfs_Unlock(param_1);
  return uVar4;
}

/* ----------------------------------------------------------------
 * yaffs_DumpDevStruct @ 0x30026274  (примерный размер ~100 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30024654, printf
 * Вызывают: yaffsMemShow
 * Константы: 0x30026274
 * Данные: DAT_30026328
 * ---------------------------------------------------------------- */
undefined4 yaffs_DumpDevStruct(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_14 [4];
  
  iVar1 = FUN_30024654(param_1,auStack_14);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 8);
    printf(DAT_30026328,*(undefined4 *)(iVar1 + 0xe28),*(undefined4 *)(iVar1 + 0xe2c),
           *(undefined4 *)(iVar1 + 0xe30),*(undefined4 *)(iVar1 + 0xe38),
           *(undefined4 *)(iVar1 + 0xe3c),*(undefined4 *)(iVar1 + 0xe40));
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300262d8 @ 0x300262D8  (примерный размер ~84 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30025c60, FUN_30025cc8
 * Константы: 0x300262D8
 * ---------------------------------------------------------------- */
bool FUN_300262d8(int *param_1)

{
  return (int *)*param_1 == param_1;
}

/* ----------------------------------------------------------------
 * yaffs_AllocateRawTnode @ 0x30026780  (примерный размер ~136 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30026604, printf
 * Вызывают: yaffs_GetTnode
 * Константы: 0x30026780
 * Данные: DAT_30026c34
 * ---------------------------------------------------------------- */
undefined4 yaffs_AllocateRawTnode(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x144);
  uVar1 = 0;
  if (iVar2 == 0) {
    printf(DAT_30026c34,0xd6);
    uVar1 = 0;
  }
  else {
    if (*(int *)(iVar2 + 4) == 0) {
      FUN_30026604(param_1,100);
    }
    if (*(int *)(iVar2 + 4) != 0) {
      uVar1 = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(iVar2 + 4) = **(undefined4 **)(iVar2 + 4);
      *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -1;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_FreeRawTnode @ 0x30026808  (примерный размер ~104 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: FUN_3001a414
 * Константы: 0x30026808
 * Данные: DAT_30026c34
 * ---------------------------------------------------------------- */
void yaffs_FreeRawTnode(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x144);
  if (iVar1 == 0) {
    printf(DAT_30026c34,0xed);
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(iVar1 + 4);
      *(undefined4 **)(iVar1 + 4) = param_2;
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    *(undefined4 *)(param_1 + 0x120) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30026870 @ 0x30026870  (примерный размер ~84 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: yaffs_InitialiseRawTnodesAndObjects
 * Константы: 0x30026870
 * Данные: DAT_30026c34
 * ---------------------------------------------------------------- */
void FUN_30026870(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x144);
  if (iVar1 == 0) {
    printf(DAT_30026c34,0x104);
  }
  else {
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x18) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300268c4 @ 0x300268C4  (примерный размер ~132 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: free, printf
 * Вызывают: yaffs_DeinitialiseRawTnodesAndObjects
 * Константы: 0x300268C4
 * Данные: DAT_30026c34, DAT_30026c44
 * ---------------------------------------------------------------- */
void FUN_300268c4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x144);
  if (iVar2 == 0) {
    printf(DAT_30026c34,DAT_30026c44);
  }
  else {
    while (*(int *)(iVar2 + 0x1c) != 0) {
      uVar1 = *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 4);
      free((void *)**(undefined4 **)(iVar2 + 0x1c));
      free(*(void **)(iVar2 + 0x1c));
      *(undefined4 *)(iVar2 + 0x1c) = uVar1;
    }
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined4 *)(iVar2 + 0x18) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30026948 @ 0x30026948  (примерный размер ~328 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: free, malloc, printf
 * Вызывают: yaffs_AllocateRawObject
 * Константы: 0x30026948
 * Данные: DAT_30026c30, DAT_30026c34, DAT_30026c48
 * ---------------------------------------------------------------- */
undefined4 FUN_30026948(int param_1,int param_2)

{
  undefined4 uVar1;
  void *__ptr;
  undefined4 *__ptr_00;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x144);
  if (iVar3 == 0) {
    printf(DAT_30026c34,0x128);
    uVar1 = 0;
  }
  else if (param_2 < 1) {
    uVar1 = 1;
  }
  else {
    __ptr = malloc(param_2 * 0x7c);
    __ptr_00 = (undefined4 *)malloc(8);
    if ((__ptr == (void *)0x0) || (__ptr_00 == (undefined4 *)0x0)) {
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
      if (__ptr_00 != (undefined4 *)0x0) {
        free(__ptr_00);
      }
      if ((*DAT_30026c30 & 4) != 0) {
        printf(DAT_30026c48);
      }
      uVar1 = 0;
    }
    else {
      for (iVar2 = 0; iVar2 < param_2 + -1; iVar2 = iVar2 + 1) {
        *(int *)((int)__ptr + iVar2 * 0x7c + 0x20) = (int)__ptr + iVar2 * 0x7c + 0x7c;
      }
      *(undefined4 *)((int)__ptr + param_2 * 0x7c + -0x5c) = *(undefined4 *)(iVar3 + 0x14);
      *(void **)(iVar3 + 0x14) = __ptr;
      *(int *)(iVar3 + 0x18) = param_2 + *(int *)(iVar3 + 0x18);
      *(int *)(iVar3 + 0x10) = param_2 + *(int *)(iVar3 + 0x10);
      *__ptr_00 = __ptr;
      __ptr_00[1] = *(undefined4 *)(iVar3 + 0x1c);
      *(undefined4 **)(iVar3 + 0x1c) = __ptr_00;
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_AllocateRawObject @ 0x30026A90  (примерный размер ~136 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30026948, printf
 * Вызывают: FUN_3001cf58
 * Константы: 0x30026A90
 * Данные: DAT_30026c34, DAT_30026c4c
 * ---------------------------------------------------------------- */
undefined4 yaffs_AllocateRawObject(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = *(int *)(param_1 + 0x144);
  if (iVar1 == 0) {
    printf(DAT_30026c34,DAT_30026c4c);
    uVar2 = 0;
  }
  else {
    if (*(int *)(iVar1 + 0x14) == 0) {
      FUN_30026948(param_1,100);
    }
    if (*(int *)(iVar1 + 0x14) != 0) {
      uVar2 = *(undefined4 *)(iVar1 + 0x14);
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x20);
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -1;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_FreeRawObject @ 0x30026B18  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: FUN_3001ac00
 * Константы: 0x30026B18
 * Данные: DAT_30026c34
 * ---------------------------------------------------------------- */
void yaffs_FreeRawObject(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x144);
  if (iVar1 == 0) {
    printf(DAT_30026c34,0x174);
  }
  else {
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(iVar1 + 0x14);
    *(int *)(iVar1 + 0x14) = param_2;
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_DeinitialiseRawTnodesAndObjects @ 0x30026B70  (примерный размер ~92 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_30026524, FUN_300268c4, free, printf
 * Вызывают: FUN_3001a444
 * Константы: 0x30026B70
 * Данные: DAT_30026c34, DAT_30026c50
 * ---------------------------------------------------------------- */
void yaffs_DeinitialiseRawTnodesAndObjects(int param_1)

{
  if (*(int *)(param_1 + 0x144) == 0) {
    printf(DAT_30026c34,DAT_30026c50);
  }
  else {
    FUN_30026524(param_1);
    FUN_300268c4(param_1);
    free(*(void **)(param_1 + 0x144));
    *(undefined4 *)(param_1 + 0x144) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_InitialiseRawTnodesAndObjects @ 0x30026BCC  (примерный размер ~140 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300265a8, FUN_30026870, malloc, printf
 * Вызывают: FUN_3001d36c
 * Константы: 0x30026BCC
 * Данные: DAT_30026c34, DAT_30026c54
 * ---------------------------------------------------------------- */
void yaffs_InitialiseRawTnodesAndObjects(int param_1)

{
  void *pvVar1;
  
  if (*(int *)(param_1 + 0x144) == 0) {
    pvVar1 = malloc(0x20);
    if (pvVar1 != (void *)0x0) {
      *(void **)(param_1 + 0x144) = pvVar1;
      FUN_300265a8(param_1);
      FUN_30026870(param_1);
    }
  }
  else {
    printf(DAT_30026c34,DAT_30026c54);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30026c58 @ 0x30026C58  (примерный размер ~132 байт)
 * Модуль: flash | Вызывают: 6 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: yaffs_CheckChunkBit, yaffs_ClearChunkBit, yaffs_ClearChunkBits, yaffs_CountChunkBits, yaffs_SetChunkBit, yaffs_StillSomeChunkBits
 * Константы: 0x30026C58
 * Данные: DAT_30026f84, DAT_30026f88
 * ---------------------------------------------------------------- */
int FUN_30026c58(int param_1,int param_2)

{
  if ((param_2 < *(int *)(param_1 + 0xdc)) || (*(int *)(param_1 + 0xe0) < param_2)) {
    printf(DAT_30026f84,param_2);
    printf(DAT_30026f88,0x1a);
  }
  return *(int *)(param_1 + 0x130) * (param_2 - *(int *)(param_1 + 0xdc)) +
         *(int *)(param_1 + 0x128);
}

/* ----------------------------------------------------------------
 * yaffs_VerifyChunkBitId @ 0x30026CDC  (примерный размер ~144 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: yaffs_CheckChunkBit, yaffs_ClearChunkBit, yaffs_SetChunkBit
 * Константы: 0x30026CDC
 * Данные: DAT_30026f88, DAT_30026f8c
 * ---------------------------------------------------------------- */
void yaffs_VerifyChunkBitId(int param_1,int param_2,int param_3)

{
  if ((((param_2 < *(int *)(param_1 + 0xdc)) || (*(int *)(param_1 + 0xe0) < param_2)) ||
      (param_3 < 0)) || (*(int *)(param_1 + 0xc) <= param_3)) {
    printf(DAT_30026f8c,param_2,param_3);
    printf(DAT_30026f88,0x27);
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_ClearChunkBits @ 0x30026D6C  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 2
 * Вызывает: FUN_30026c58, memset
 * Вызывают: yaffs1_Scan, yaffs2_ScanBackwards, yaffs_BlockBecameDirty
 * Константы: 0x30026D6C
 * ---------------------------------------------------------------- */
void yaffs_ClearChunkBits(int param_1,undefined4 param_2)

{
  void *__s;
  
  __s = (void *)FUN_30026c58(param_1,param_2);
  memset(__s,0,*(size_t *)(param_1 + 0x130));
  return;
}

/* ----------------------------------------------------------------
 * yaffs_ClearChunkBit @ 0x30026D9C  (примерный размер ~92 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30026c58, yaffs_VerifyChunkBitId
 * Вызывают: yaffs_DeleteChunk
 * Константы: 0x30026D9C
 * ---------------------------------------------------------------- */
void yaffs_ClearChunkBit(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  iVar1 = FUN_30026c58(param_1,param_2);
  yaffs_VerifyChunkBitId(param_1,param_2,param_3);
  uVar3 = param_3 + ((uint)(param_3 >> 0x1f) >> 0x1d);
  pbVar2 = (byte *)(iVar1 + ((int)uVar3 >> 3));
  *pbVar2 = *pbVar2 & ~(byte)(1 << (uVar3 & 7));
  return;
}

/* ----------------------------------------------------------------
 * yaffs_SetChunkBit @ 0x30026DF8  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 2
 * Вызывает: FUN_30026c58, yaffs_VerifyChunkBitId
 * Вызывают: FUN_30019f80, yaffs1_Scan, yaffs2_ScanBackwards
 * Константы: 0x30026DF8
 * ---------------------------------------------------------------- */
void yaffs_SetChunkBit(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  iVar1 = FUN_30026c58(param_1,param_2);
  yaffs_VerifyChunkBitId(param_1,param_2,param_3);
  uVar3 = param_3 + ((uint)(param_3 >> 0x1f) >> 0x1d);
  pbVar2 = (byte *)(iVar1 + ((int)uVar3 >> 3));
  *pbVar2 = *pbVar2 | (byte)(1 << (uVar3 & 7));
  return;
}

/* ----------------------------------------------------------------
 * yaffs_CheckChunkBit @ 0x30026E50  (примерный размер ~96 байт)
 * Модуль: flash | Вызывают: 4 | Вызывает: 2
 * Вызывает: FUN_30026c58, yaffs_VerifyChunkBitId
 * Вызывают: FUN_3001a908, FUN_3001b01c, yaffs_DeleteChunk, yaffs_VerifyObject
 * Константы: 0x30026E50
 * ---------------------------------------------------------------- */
bool yaffs_CheckChunkBit(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_30026c58(param_1,param_2);
  yaffs_VerifyChunkBitId(param_1,param_2,param_3);
  uVar2 = param_3 + ((uint)(param_3 >> 0x1f) >> 0x1d);
  return ((uint)*(byte *)(iVar1 + ((int)uVar2 >> 3)) & 1 << (uVar2 & 7)) != 0;
}

/* ----------------------------------------------------------------
 * yaffs_StillSomeChunkBits @ 0x30026EB0  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30026c58
 * Вызывают: FUN_3001b01c
 * Константы: 0x30026EB0
 * ---------------------------------------------------------------- */
undefined4 yaffs_StillSomeChunkBits(int param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)FUN_30026c58(param_1,param_2);
  iVar2 = 0;
  while( true ) {
    if (*(int *)(param_1 + 0x130) <= iVar2) {
      return 0;
    }
    if (*pcVar1 != '\0') break;
    pcVar1 = pcVar1 + 1;
    iVar2 = iVar2 + 1;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * yaffs_CountChunkBits @ 0x30026F08  (примерный размер ~136 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30026c58
 * Вызывают: yaffs_VerifyBlock
 * Константы: 0x30026F08
 * ---------------------------------------------------------------- */
int yaffs_CountChunkBits(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  pbVar1 = (byte *)FUN_30026c58(param_1,param_2);
  iVar3 = 0;
  for (iVar4 = 0; iVar4 < *(int *)(param_1 + 0x130); iVar4 = iVar4 + 1) {
    for (uVar2 = (uint)*pbVar1; uVar2 != 0; uVar2 = uVar2 >> 1) {
      iVar3 = iVar3 + (uint)((uVar2 & 1) != 0);
    }
    pbVar1 = pbVar1 + 1;
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_30026f90 @ 0x30026F90  (примерный размер ~224 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 2
 * Вызывает: memcpy, strncmp
 * Вызывают: nval_del, nval_get, nval_set
 * Константы: 0x30026F90, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
uint FUN_30026f90(void *param_1,int param_2,char *param_3,size_t *param_4)

{
  int iVar1;
  uint uVar2;
  size_t local_1c;
  
  uVar2 = 0;
  memcpy(&local_1c,param_1,4);
  while (((0 < (int)local_1c && ((int)local_1c < param_2)) && ((int)(uVar2 + local_1c) < param_2)))
  {
    iVar1 = strncmp((char *)((int)param_1 + uVar2 + 4),param_3,local_1c);
    if (iVar1 == 0) {
      if (param_4 == (size_t *)0x0) {
        return uVar2;
      }
      *param_4 = local_1c;
      return uVar2;
    }
    uVar2 = uVar2 + local_1c;
    if (param_2 - 4U <= uVar2) break;
    memcpy(&local_1c,(void *)((int)param_1 + uVar2),4);
  }
  if (param_4 != (size_t *)0x0) {
    *param_4 = 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_30027070 @ 0x30027070  (примерный размер ~148 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: memcpy
 * Вызывают: nval_hasvalues, nval_set
 * Константы: 0x30027070
 * ---------------------------------------------------------------- */
uint FUN_30027070(void *param_1,int param_2)

{
  uint uVar1;
  int local_14;
  
  uVar1 = 0;
  memcpy(&local_14,param_1,4);
  while ((((0 < local_14 && (local_14 < param_2)) && ((int)(uVar1 + local_14) < param_2)) &&
         (uVar1 = uVar1 + local_14, uVar1 < param_2 - 4U))) {
    memcpy(&local_14,(void *)((int)param_1 + uVar1),4);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_SkipVerification @ 0x3002759C  (примерный размер ~28 байт)
 * Модуль: flash | Вызывают: 13 | Вызывает: 0
 * Вызывают: FUN_3001b01c, yaffs_BlockBecameDirty, yaffs_VerifyBlock, yaffs_VerifyBlocks, yaffs_VerifyFile, yaffs_VerifyFreeChunks, yaffs_VerifyHardLink, yaffs_VerifyObject, yaffs_VerifyObjectHeader, yaffs_VerifyObjectInDirectory
 *           ...
 * Константы: 0x3002759C
 * Данные: DAT_30028454
 * ---------------------------------------------------------------- */
bool yaffs_SkipVerification(void)

{
  return (*DAT_30028454 & 0x50000) == 0;
}

/* ----------------------------------------------------------------
 * yaffs_VerifyBlock @ 0x300275B8  (примерный размер ~392 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 3
 * Вызывает: printf, yaffs_CountChunkBits, yaffs_SkipVerification
 * Вызывают: FUN_3001b01c, yaffs_VerifyBlocks, yaffs_VerifyCollectedBlock
 * Константы: 0x300275B8
 * Данные: DAT_30028454, DAT_30028460, DAT_30028464, DAT_30028468, DAT_3002846c, DAT_30028470
 * ---------------------------------------------------------------- */
void yaffs_VerifyBlock(int param_1,uint *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = yaffs_SkipVerification(param_1);
  if (iVar1 == 0) {
    if ((9 < (*param_2 >> 0x14 & 0xf)) && ((*DAT_30028454 & 0x10000) != 0)) {
      printf(DAT_30028460,param_3,*param_2 >> 0x14 & 0xf);
    }
    if (((*param_2 >> 0x14 & 0xf) < 3) && ((*DAT_30028454 & 0x10000) != 0)) {
      printf(DAT_30028468,param_3,*(undefined4 *)(DAT_30028464 + (*param_2 >> 0x14 & 0xf) * 4));
    }
    iVar1 = ((*param_2 << 0xc) >> 0x16) - (*param_2 & 0x3ff);
    if (((((*(uint *)(param_1 + 0xc) < (*param_2 << 0xc) >> 0x16) ||
          (*(uint *)(param_1 + 0xc) < (*param_2 & 0x3ff))) || (iVar1 < 0)) ||
        (*(int *)(param_1 + 0xc) < iVar1)) && ((*DAT_30028454 & 0x10000) != 0)) {
      printf(DAT_3002846c,param_3,(*param_2 << 0xc) >> 0x16,*param_2 & 0x3ff);
    }
    uVar2 = yaffs_CountChunkBits(param_1,param_3);
    if ((uVar2 != (*param_2 << 0xc) >> 0x16) && ((*DAT_30028454 & 0x10000) != 0)) {
      printf(DAT_30028470,param_3,(*param_2 << 0xc) >> 0x16,uVar2);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifyCollectedBlock @ 0x30027740  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: printf, yaffs_VerifyBlock
 * Вызывают: FUN_3001b01c
 * Константы: 0x30027740
 * Данные: DAT_30028474
 * ---------------------------------------------------------------- */
void yaffs_VerifyCollectedBlock(undefined4 param_1,uint *param_2,undefined4 param_3)

{
  yaffs_VerifyBlock(param_1,param_2,param_3);
  if (((*param_2 >> 0x14 & 0xf) != 8) && ((*param_2 >> 0x14 & 0xf) != 3)) {
    printf(DAT_30028474,param_3,*param_2 >> 0x14 & 0xf);
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifyBlocks @ 0x300277B8  (примерный размер ~508 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 5
 * Вызывает: FUN_3002751c, memset, printf, yaffs_SkipVerification, yaffs_VerifyBlock
 * Вызывают: yaffs2_CheckpointRestore, yaffs_CheckpointSave, yaffs_GutsInitialise
 * Константы: 0x300277B8
 * Данные: DAT_30028454, DAT_30028464, DAT_30028478, DAT_3002847c, DAT_30028480, DAT_30028484, DAT_30028488, DAT_3002848c
 * ---------------------------------------------------------------- */
void yaffs_VerifyBlocks(int param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int local_40 [10];
  
  iVar3 = 0;
  iVar1 = yaffs_SkipVerification(param_1);
  if (iVar1 == 0) {
    memset(local_40,0,0x28);
    for (iVar1 = *(int *)(param_1 + 0xdc); iVar1 <= *(int *)(param_1 + 0xe0); iVar1 = iVar1 + 1) {
      puVar2 = (uint *)FUN_3002751c(param_1,iVar1);
      yaffs_VerifyBlock(param_1,puVar2,iVar1);
      if ((*puVar2 >> 0x14 & 0xf) < 10) {
        local_40[*puVar2 >> 0x14 & 0xf] = local_40[*puVar2 >> 0x14 & 0xf] + 1;
      }
      else {
        iVar3 = iVar3 + 1;
      }
    }
    if ((*DAT_30028454 & 0x10000) != 0) {
      printf(DAT_30028478);
    }
    if ((*DAT_30028454 & 0x10000) != 0) {
      printf(DAT_3002847c);
    }
    if ((*DAT_30028454 & 0x10000) != 0) {
      printf(DAT_30028480,iVar3);
    }
    if ((1 < local_40[4]) && ((*DAT_30028454 & 0x10000) != 0)) {
      printf(DAT_30028484);
    }
    for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
      if ((*DAT_30028454 & 0x10000) != 0) {
        printf(DAT_30028488,*(undefined4 *)(DAT_30028464 + iVar1 * 4),local_40[iVar1]);
      }
    }
    if ((*(int *)(param_1 + 0x100) != local_40[7]) && ((*DAT_30028454 & 0x10000) != 0)) {
      printf(DAT_3002848c,*(undefined4 *)(param_1 + 0x100),local_40[7]);
    }
    if ((*(int *)(param_1 + 0x134) != local_40[3]) && ((*DAT_30028454 & 0x10000) != 0)) {
      printf(DAT_30028490,*(undefined4 *)(param_1 + 0x134),local_40[3]);
    }
    if ((1 < local_40[8]) && ((*DAT_30028454 & 0x10000) != 0)) {
      printf(DAT_30028494,local_40[8]);
    }
    if ((*DAT_30028454 & 0x10000) != 0) {
      printf(DAT_30028478);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifyObjectHeader @ 0x300279B4  (примерный размер ~492 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 2
 * Вызывает: printf, yaffs_SkipVerification
 * Вызывают: FUN_3001b01c, yaffs_UpdateObjectHeader, yaffs_VerifyObject
 * Константы: 0x300279B4
 * Данные: DAT_30028454, DAT_30028498, DAT_3002849c, DAT_300284a0, DAT_300284a4, DAT_300284a8, DAT_300284ac, DAT_300284b0
 * ---------------------------------------------------------------- */
void yaffs_VerifyObjectHeader(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_1 == 0) || (iVar1 = yaffs_SkipVerification(*(undefined4 *)(param_1 + 8)), iVar1 == 0))
  {
    if ((param_3 == 0) || ((param_1 == 0 || (param_2 == (int *)0x0)))) {
      if ((*DAT_30028454 & 0x10000) != 0) {
        printf(DAT_30028498,param_3,param_1,param_2);
      }
    }
    else {
      if (((*param_2 < 1) || (5 < *param_2)) && ((*DAT_30028454 & 0x10000) != 0)) {
        printf(DAT_3002849c,*(undefined4 *)(param_3 + 8),*param_2);
      }
      if ((*(int *)(param_3 + 8) != *(int *)(param_1 + 0x30)) && ((*DAT_30028454 & 0x10000) != 0)) {
        printf(DAT_300284a0,*(undefined4 *)(param_3 + 8),*(undefined4 *)(param_1 + 0x30));
      }
      if ((((param_4 != 0) && (1 < *(uint *)(param_3 + 8))) && (*(int *)(param_1 + 0x1c) == 0)) &&
         ((*DAT_30028454 & 0x10000) != 0)) {
        printf(DAT_300284a4,*(undefined4 *)(param_3 + 8),param_2[1]);
      }
      if ((((param_4 != 0) && (*(int *)(param_1 + 0x1c) != 0)) &&
          ((param_2[1] != *(int *)(*(int *)(param_1 + 0x1c) + 0x30) &&
           ((param_2[1] != 3 || (*(int *)(*(int *)(param_1 + 0x1c) + 0x30) != 4)))))) &&
         ((*DAT_30028454 & 0x10000) != 0)) {
        printf(DAT_300284a8,*(undefined4 *)(param_3 + 8),param_2[1],
               *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x30));
      }
      if (((1 < *(uint *)(param_3 + 8)) && (*(char *)((int)param_2 + 10) == '\0')) &&
         ((*DAT_30028454 & 0x10000) != 0)) {
        printf(DAT_300284ac,*(undefined4 *)(param_1 + 0x30));
      }
      if (((1 < *(uint *)(param_3 + 8)) && (*(char *)((int)param_2 + 10) == -1)) &&
         ((*DAT_30028454 & 0x10000) != 0)) {
        printf(DAT_300284b0,*(undefined4 *)(param_1 + 0x30));
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifyFile @ 0x30027BA0  (примерный размер ~336 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_3002841c, __udiv32, printf, yaffs_FindLevel0Tnode, yaffs_GetChunkGroupBase, yaffs_ReadChunkWithTagsFromNAND, yaffs_SkipVerification
 * Вызывают: yaffs_VerifyObject
 * Константы: 0x30027BA0
 * Данные: DAT_30028454, DAT_300284b4, DAT_300284b8
 * ---------------------------------------------------------------- */
void yaffs_VerifyFile(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_6c [8];
  int local_64;
  uint local_60;
  
  if ((param_1 != 0) && (iVar1 = yaffs_SkipVerification(*(undefined4 *)(param_1 + 8)), iVar1 == 0))
  {
    iVar3 = *(int *)(param_1 + 8);
    iVar5 = *(int *)(param_1 + 0x30);
    iVar1 = __udiv32(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(iVar3 + 0x9c));
    for (uVar4 = iVar1 + 1U >> 4; uVar4 != 0; uVar4 = uVar4 >> 3) {
    }
    iVar2 = FUN_3002841c(iVar3);
    if (iVar2 == 0) {
      for (uVar4 = 1; uVar4 <= iVar1 + 1U; uVar4 = uVar4 + 1) {
        iVar2 = yaffs_FindLevel0Tnode(iVar3,param_1 + 0x68,uVar4);
        if ((((iVar2 != 0) && (iVar2 = yaffs_GetChunkGroupBase(iVar3,iVar2,uVar4), iVar2 != 0)) &&
            ((yaffs_ReadChunkWithTagsFromNAND(iVar3,iVar2,0,auStack_6c), local_64 != iVar5 ||
             (local_60 != uVar4)))) && (*DAT_30028454 != 0 || DAT_300284b4 != 0)) {
          printf(DAT_300284b8,iVar5,uVar4,iVar2,local_64,local_60);
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifyHardLink @ 0x30027CF0  (примерный размер ~28 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: yaffs_SkipVerification
 * Вызывают: yaffs_VerifyObject
 * Константы: 0x30027CF0
 * ---------------------------------------------------------------- */
void yaffs_VerifyHardLink(int param_1)

{
  if (param_1 != 0) {
    yaffs_SkipVerification(*(undefined4 *)(param_1 + 8));
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifySymlink @ 0x30027D0C  (примерный размер ~28 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: yaffs_SkipVerification
 * Вызывают: yaffs_VerifyObject
 * Константы: 0x30027D0C
 * ---------------------------------------------------------------- */
void yaffs_VerifySymlink(int param_1)

{
  if (param_1 != 0) {
    yaffs_SkipVerification(*(undefined4 *)(param_1 + 8));
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifySpecial @ 0x30027D28  (примерный размер ~28 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: yaffs_SkipVerification
 * Вызывают: yaffs_VerifyObject
 * Константы: 0x30027D28
 * ---------------------------------------------------------------- */
void yaffs_VerifySpecial(int param_1)

{
  if (param_1 != 0) {
    yaffs_SkipVerification(*(undefined4 *)(param_1 + 8));
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifyObjectInDirectory @ 0x30027D44  (примерный размер ~404 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 3
 * Вызывает: printf, yaffs_SkipVerification, yaffs_VerifyObject
 * Вызывают: FUN_3001c51c, yaffs_AddObjectToDirectory, yaffs_VerifyDirectory
 * Константы: 0x30027D44
 * Данные: DAT_300284bc, DAT_300284c0, DAT_300284c4, DAT_300284c8, DAT_300284cc, DAT_300284d0, DAT_300284d4, DAT_300284d8
 * ---------------------------------------------------------------- */
void yaffs_VerifyObjectInDirectory(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  if (param_1 == 0) {
    printf(DAT_300284bc);
    printf(DAT_300284c0,0x1e0);
  }
  else {
    iVar1 = yaffs_SkipVerification(*(undefined4 *)(param_1 + 8));
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x1c) == 0) {
        printf(DAT_300284c4);
        printf(DAT_300284c0,DAT_300284c8);
      }
      else {
        if (*(int *)(*(int *)(param_1 + 0x1c) + 100) != 3) {
          printf(DAT_300284cc);
          printf(DAT_300284c0,DAT_300284d0);
        }
        for (piVar3 = *(int **)(*(int *)(param_1 + 0x1c) + 0x68);
            (int *)(*(int *)(param_1 + 0x1c) + 0x68) != piVar3; piVar3 = (int *)*piVar3) {
          if ((piVar3 != (int *)0x0) &&
             (yaffs_VerifyObject(piVar3 + -8), (int *)param_1 == piVar3 + -8)) {
            iVar2 = iVar2 + 1;
          }
        }
        if (iVar2 != 1) {
          printf(DAT_300284d4,iVar2);
          printf(DAT_300284c0,DAT_300284d8);
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifyDirectory @ 0x30027ED8  (примерный размер ~280 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 3
 * Вызывает: FUN_30028438, printf, yaffs_VerifyObjectInDirectory
 * Вызывают: FUN_3001c51c, yaffs_AddObjectToDirectory, yaffs_VerifyObject
 * Константы: 0x30027ED8
 * Данные: DAT_300284c0, DAT_300284dc, DAT_300284e0, DAT_300284e4, DAT_300284e8
 * ---------------------------------------------------------------- */
void yaffs_VerifyDirectory(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    printf(DAT_300284c0,DAT_300284dc);
  }
  else {
    iVar1 = FUN_30028438(*(undefined4 *)(param_1 + 8));
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 100) != 3) {
        printf(DAT_300284e0,*(undefined4 *)(param_1 + 100));
        printf(DAT_300284c0,DAT_300284e4);
      }
      for (piVar2 = *(int **)(param_1 + 0x68); (int *)(param_1 + 0x68) != piVar2;
          piVar2 = (int *)*piVar2) {
        if (piVar2 != (int *)0x0) {
          if (piVar2[-1] != param_1) {
            printf(DAT_300284e8,piVar2[-1]);
            printf(DAT_300284c0,0x21c);
          }
          yaffs_VerifyObjectInDirectory(piVar2 + -8);
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifyObject @ 0x30027FF0  (примерный размер ~820 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 14
 * Вызывает: FUN_3002841c, __div32, printf, yaffs_CheckChunkBit, yaffs_GetTempBuffer, yaffs_ReadChunkWithTagsFromNAND, yaffs_ReleaseTempBuffer, yaffs_SkipVerification, yaffs_VerifyDirectory, yaffs_VerifyFile, yaffs_VerifyHardLink, yaffs_VerifyObjectHeader, yaffs_VerifySpecial, yaffs_VerifySymlink
 * Вызывают: yaffs_VerifyObjectInDirectory, yaffs_VerifyObjects
 * Константы: 0x30027FF0
 * Данные: DAT_30028454, DAT_300284ec, DAT_300284f0, DAT_300284f4, DAT_300284f8, DAT_300284fc, DAT_30028500, DAT_30028504
 * ---------------------------------------------------------------- */
void yaffs_VerifyObject(byte *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_80;
  undefined1 auStack_6c [72];
  
  if (param_1 == (byte *)0x0) {
    return;
  }
  if ((param_1[1] & 4) != 0) {
    return;
  }
  iVar6 = *(int *)(param_1 + 8);
  iVar4 = yaffs_SkipVerification(iVar6);
  if (iVar4 != 0) {
    return;
  }
  if ((*(uint *)(param_1 + 0x28) < (uint)(*(int *)(iVar6 + 0xc) * *(int *)(iVar6 + 0xdc))) ||
     (*(int *)(iVar6 + 0xc) * (*(int *)(iVar6 + 0xe0) + 1) - 1U < *(uint *)(param_1 + 0x28))) {
    bVar1 = false;
    if (*(int *)(param_1 + 0x28) == 0) goto LAB_30028094;
    bVar2 = false;
  }
  else {
    bVar1 = true;
LAB_30028094:
    bVar2 = true;
  }
  if (bVar1) {
    iVar4 = __div32(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(iVar6 + 0xc));
    iVar7 = *(int *)(iVar6 + 0xc);
    iVar8 = *(int *)(param_1 + 0x28);
    uVar5 = __div32(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(iVar6 + 0xc));
    iVar4 = yaffs_CheckChunkBit(iVar6,uVar5,iVar8 - iVar7 * iVar4);
    if (iVar4 != 0) {
      bVar3 = true;
      goto LAB_300280f0;
    }
  }
  bVar3 = false;
LAB_300280f0:
  if ((!bVar1) || (bVar3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((*param_1 & 8) == 0) && (((!bVar2 || (bVar1)) && ((*DAT_30028454 & 0x10000) != 0)))) {
    uVar5 = DAT_300284f0;
    if (bVar2) {
      uVar5 = DAT_300284ec;
    }
    if (bVar1) {
      local_80 = DAT_300284f4;
    }
    else {
      local_80 = DAT_300284ec;
    }
    printf(DAT_300284f8,*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x28),uVar5,
           local_80);
  }
  if ((bVar3) && (iVar4 = FUN_3002841c(iVar6), iVar4 == 0)) {
    uVar5 = yaffs_GetTempBuffer(iVar6,DAT_300284fc);
    yaffs_ReadChunkWithTagsFromNAND(iVar6,*(undefined4 *)(param_1 + 0x28),uVar5,auStack_6c);
    yaffs_VerifyObjectHeader(param_1,uVar5,auStack_6c,1);
    yaffs_ReleaseTempBuffer(iVar6,uVar5,DAT_30028500);
  }
  if ((((param_1 != (byte *)0x0) && ((*param_1 & 8) == 0)) &&
      ((*(int *)(param_1 + 0x1c) == 0 || (*(int *)(*(int *)(param_1 + 0x1c) + 8) != iVar6)))) &&
     ((*DAT_30028454 & 0x10000) != 0)) {
    printf(DAT_30028504,*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x1c));
  }
  if (((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(*(int *)(param_1 + 0x1c) + 100) != 3)) &&
     ((*DAT_30028454 & 0x10000) != 0)) {
    printf(DAT_30028508,*(undefined4 *)(param_1 + 0x30),
           *(undefined4 *)(*(int *)(param_1 + 0x1c) + 100));
  }
  iVar4 = *(int *)(param_1 + 100);
  if (iVar4 == 3) {
    yaffs_VerifyDirectory(param_1);
    return;
  }
  if (iVar4 < 4) {
    if (iVar4 == 1) {
      yaffs_VerifyFile(param_1);
      return;
    }
    if (iVar4 == 2) {
      yaffs_VerifySymlink(param_1);
      return;
    }
  }
  else {
    if (iVar4 == 4) {
      yaffs_VerifyHardLink(param_1);
      return;
    }
    if (iVar4 == 5) {
      yaffs_VerifySpecial(param_1);
      return;
    }
  }
  if ((*DAT_30028454 & 0x10000) != 0) {
    printf(DAT_3002850c,*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 100));
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifyObjects @ 0x30028324  (примерный размер ~124 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 2
 * Вызывает: yaffs_SkipVerification, yaffs_VerifyObject
 * Вызывают: yaffs2_CheckpointRestore, yaffs_CheckpointSave
 * Константы: 0x30028324
 * ---------------------------------------------------------------- */
void yaffs_VerifyObjects(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = yaffs_SkipVerification(param_1);
  if (iVar1 == 0) {
    for (iVar1 = 0; iVar1 < 0x100; iVar1 = iVar1 + 1) {
      for (piVar2 = *(int **)(param_1 + iVar1 * 0xc + 0x154);
          (int *)(param_1 + iVar1 * 0xc + 0x154) != piVar2; piVar2 = (int *)*piVar2) {
        if (piVar2 != (int *)0x0) {
          yaffs_VerifyObject(piVar2 + -3);
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifyFreeChunks @ 0x300283A0  (примерный размер ~116 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 3
 * Вызывает: printf, yaffs_CountFreeChunks, yaffs_SkipVerification
 * Вызывают: yaffs2_CheckpointRestore, yaffs_CheckpointSave, yaffs_GutsInitialise
 * Константы: 0x300283A0
 * Данные: DAT_30028510, DAT_30028514
 * ---------------------------------------------------------------- */
void yaffs_VerifyFreeChunks(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = yaffs_SkipVerification(param_1);
  if (iVar1 == 0) {
    iVar1 = yaffs_CountFreeChunks(param_1);
    iVar2 = *(int *)(param_1 + 0xd58) - iVar1;
    if (iVar2 != 0) {
      printf(DAT_30028510,*(undefined4 *)(param_1 + 0xd58),iVar1,iVar2);
      *DAT_30028514 = *DAT_30028514 + 1;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_VerifyFileSanity @ 0x30028414  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3001d45c
 * Константы: 0x30028414
 * ---------------------------------------------------------------- */
undefined4 yaffs_VerifyFileSanity(void)

{
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3002841c @ 0x3002841C  (примерный размер ~28 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: yaffs_VerifyFile, yaffs_VerifyObject
 * Константы: 0x3002841C
 * Данные: DAT_30028454
 * ---------------------------------------------------------------- */
bool FUN_3002841c(void)

{
  return (*DAT_30028454 & 0x20000) == 0;
}

/* ----------------------------------------------------------------
 * FUN_30028438 @ 0x30028438  (примерный размер ~224 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_VerifyDirectory
 * Константы: 0x30028438
 * Данные: DAT_30028454
 * ---------------------------------------------------------------- */
bool FUN_30028438(void)

{
  return (*DAT_30028454 & 0x40000) == 0;
}

/* ----------------------------------------------------------------
 * FUN_30028518 @ 0x30028518  (примерный размер ~128 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: yaffs1_Scan
 * Константы: 0x30028518
 * Данные: DAT_30028ee0, DAT_30028ee4
 * ---------------------------------------------------------------- */
int FUN_30028518(int param_1,int param_2)

{
  if ((param_2 < *(int *)(param_1 + 0xdc)) || (*(int *)(param_1 + 0xe0) < param_2)) {
    printf(DAT_30028ee0,param_2);
    printf(DAT_30028ee4,0x1e);
  }
  return *(int *)(param_1 + 0x124) + (param_2 - *(int *)(param_1 + 0xdc)) * 8;
}

/* ----------------------------------------------------------------
 * yaffs1_Scan @ 0x30028598  (примерный размер ~2440 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 21
 * Вызывает: FUN_30028518, free, malloc, printf, yaffs_AddObjectToDirectory, yaffs_BlockBecameDirty, yaffs_ClearChunkBits, yaffs_CloneString, yaffs_DeleteChunk, yaffs_DeleteObject, yaffs_FindObjectByNumber, yaffs_FindOrCreateObjectByNumber, yaffs_GetTempBuffer, yaffs_HardlinkFixup
 *           ...
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0xFF0FFFFF, 0x30028598, 0x00900000, 0xFFFFFFFF, 0x40000000
 * Данные: DAT_30028edc, DAT_30028ee8, DAT_30028eec, DAT_30028ef0, DAT_30028ef4, DAT_30028ef8, DAT_30028efc, DAT_30028f00
 * ---------------------------------------------------------------- */
undefined4 yaffs1_Scan(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint local_c0;
  int local_bc;
  int local_b8;
  int *local_b4;
  int local_b0;
  int local_ac;
  int *local_a8;
  byte *local_a4;
  int *local_a0;
  int local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  int local_80;
  int local_7c;
  undefined4 local_78;
  uint local_74;
  uint local_70;
  undefined1 auStack_6c [4];
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_50;
  uint local_4c;
  
  local_a4 = (byte *)0x0;
  local_bc = 0;
  local_b4 = (int *)0x0;
  if ((*DAT_30028edc & 8) != 0) {
    printf(DAT_30028ee8,*(undefined4 *)(param_1 + 0xdc),*(undefined4 *)(param_1 + 0xe0));
  }
  local_a0 = (int *)yaffs_GetTempBuffer(param_1,0x36);
  *(undefined4 *)(param_1 + 0xe10) = 0x1000;
  puVar9 = *(uint **)(param_1 + 0x124);
  for (iVar7 = *(int *)(param_1 + 0xdc); iVar7 <= *(int *)(param_1 + 0xe0); iVar7 = iVar7 + 1) {
    yaffs_ClearChunkBits(param_1,iVar7);
    *puVar9 = *puVar9 & DAT_30028eec;
    yaffs_QueryInitialBlockState(param_1,iVar7,&local_c0,&local_98);
    local_84 = local_c0;
    *puVar9 = *puVar9 & 0xff0fffff | (local_c0 & 0xf) << 0x14;
    puVar9[1] = local_98;
    if (puVar9[1] == DAT_30028ef0) {
      local_c0 = 9;
      *puVar9 = *puVar9 & 0xff0fffff | 0x900000;
    }
    if ((*DAT_30028edc & 0x2000) != 0) {
      printf(DAT_30028ef4,iVar7,local_c0,local_98);
    }
    if (local_c0 == 9) {
      if ((*DAT_30028edc & 0x10) != 0) {
        printf(DAT_30028ef8,iVar7);
      }
    }
    else if (local_c0 == 3) {
      if ((*DAT_30028edc & 0x2000) != 0) {
        printf(DAT_30028efc);
      }
      *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
      *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) + *(int *)(param_1 + 0xc);
    }
    puVar9 = puVar9 + 2;
  }
  local_ac = *(int *)(param_1 + 0xdc);
  local_7c = *(int *)(param_1 + 0xe0);
  local_80 = local_ac;
  do {
    iVar7 = local_ac;
    if ((local_bc != 0) || (local_7c < local_ac)) {
      yaffs_HardlinkFixup(param_1,local_a4);
      while (local_b4 != (int *)0x0) {
        local_a8 = local_b4;
        piVar1 = local_b4 + 1;
        local_b4 = (int *)local_b4[2];
        local_b0 = yaffs_FindObjectByNumber(param_1,*piVar1);
        if (local_b0 != 0) {
          yaffs_DeleteObject(local_b0);
        }
        local_b0 = yaffs_FindObjectByNumber(param_1,*local_a8);
        if (local_b0 != 0) {
          yaffs_UpdateObjectHeader(local_b0,0,1,0,0,0);
        }
        free(local_a8);
      }
      yaffs_ReleaseTempBuffer(param_1,local_a0,DAT_30028f18);
      if (local_bc == 0) {
        if ((*DAT_30028edc & 8) != 0) {
          printf(DAT_30028f1c);
        }
        uVar6 = 1;
      }
      else {
        uVar6 = 0;
      }
      return uVar6;
    }
    puVar9 = (uint *)FUN_30028518(param_1,local_ac);
    local_c0 = *puVar9 >> 0x14 & 0xf;
    local_9c = 0;
    iVar8 = 0;
    while (((local_bc == 0 && (iVar8 < *(int *)(param_1 + 0xc))) && (local_c0 == 2))) {
      local_b8 = iVar7 * *(int *)(param_1 + 0xc) + iVar8;
      local_78 = yaffs_ReadChunkWithTagsFromNAND(param_1,local_b8,0,auStack_6c);
      if ((local_58 == 3) || (local_50 != 0)) {
        local_9c = local_9c + 1;
        *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) + 1;
      }
      else if (local_68 == 0) {
        if (iVar8 == 0) {
          local_c0 = 3;
          *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
        }
        else {
          if ((*DAT_30028edc & 8) != 0) {
            printf(DAT_30028f00,iVar7,iVar8);
          }
          local_c0 = 4;
          *(int *)(param_1 + 0x138) = iVar7;
          *(int *)(param_1 + 0x13c) = iVar8;
          *(int *)(param_1 + 0x140) = iVar7;
        }
        *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) + (*(int *)(param_1 + 0xc) - iVar8);
      }
      else if (local_60 == 0) {
        yaffs_SetChunkBit(param_1,iVar7,iVar8);
        local_8c = ((*puVar9 << 0xc) >> 0x16) + 1;
        *puVar9 = *puVar9 & DAT_30028f04 | (local_8c & DAT_30028f08) << 10;
        local_78 = yaffs_ReadChunkWithTagsFromNAND(param_1,local_b8,local_a0,0);
        piVar1 = local_a0;
        iVar2 = yaffs_FindObjectByNumber(param_1,local_64);
        if ((iVar2 != 0) && (*(int *)(iVar2 + 100) != *piVar1)) {
          yaffs_DeleteObject(iVar2);
        }
        pbVar4 = (byte *)yaffs_FindOrCreateObjectByNumber(param_1,local_64,*piVar1);
        if (pbVar4 == (byte *)0x0) {
          local_bc = 1;
        }
        else if ((0 < piVar1[0x7e]) && (piVar5 = (int *)malloc(0xc), piVar5 != (int *)0x0)) {
          piVar5[2] = (int)local_b4;
          *piVar5 = local_64;
          piVar5[1] = piVar1[0x7e];
          local_b4 = piVar5;
          if ((*DAT_30028edc & 8) != 0) {
            printf(DAT_30028f0c,*piVar5,piVar5[1]);
          }
        }
        if ((pbVar4 != (byte *)0x0) && ((*pbVar4 & 0x80) != 0)) {
          local_74 = (uint)pbVar4[2];
          local_70 = local_4c;
          if ((local_74 + 1 & 3) == local_4c) {
            yaffs_DeleteChunk(param_1,*(undefined4 *)(pbVar4 + 0x28),1,0xfd);
            *pbVar4 = *pbVar4 & 0x7f;
          }
          else {
            yaffs_DeleteChunk(param_1,local_b8,1,DAT_30028f10);
          }
        }
        if (((pbVar4 == (byte *)0x0) || ((*pbVar4 & 0x80) != 0)) ||
           ((local_64 != 1 && (local_64 != 2)))) {
          if ((pbVar4 != (byte *)0x0) && ((*pbVar4 & 0x80) == 0)) {
            *pbVar4 = *pbVar4 | 0x80;
            *(int *)(pbVar4 + 100) = *piVar1;
            *(int *)(pbVar4 + 0x34) = piVar1[0x43];
            *(int *)(pbVar4 + 0x4c) = piVar1[0x44];
            *(int *)(pbVar4 + 0x50) = piVar1[0x45];
            *(int *)(pbVar4 + 0x54) = piVar1[0x46];
            *(int *)(pbVar4 + 0x58) = piVar1[0x47];
            *(int *)(pbVar4 + 0x5c) = piVar1[0x48];
            *(int *)(pbVar4 + 0x60) = piVar1[0x73];
            *(int *)(pbVar4 + 0x28) = local_b8;
            pbVar4[2] = (byte)local_4c;
            yaffs_SetObjectNameFromOH(pbVar4,piVar1);
            *pbVar4 = *pbVar4 & 0xbf;
            iVar2 = yaffs_FindOrCreateObjectByNumber(param_1,piVar1[1],3);
            if (iVar2 == 0) {
              local_bc = 1;
LAB_30028c90:
              if ((iVar2 == 0) || (*(int *)(iVar2 + 100) != 3)) {
                printf(DAT_30028f14);
                iVar2 = *(int *)(param_1 + 0xd8c);
              }
            }
            else {
              if (*(int *)(iVar2 + 100) != 0) goto LAB_30028c90;
              *(undefined4 *)(iVar2 + 100) = 3;
              *(int *)(iVar2 + 0x68) = iVar2 + 0x68;
              *(int *)(iVar2 + 0x6c) = iVar2 + 0x68;
            }
            yaffs_AddObjectToDirectory(iVar2,pbVar4);
            iVar2 = *(int *)(pbVar4 + 100);
            if (iVar2 == 1) {
              if (*(int *)(param_1 + 0x70) != 0) {
                *(int *)(pbVar4 + 0x68) = piVar1[0x49];
              }
            }
            else if (iVar2 == 2) {
              uVar6 = yaffs_CloneString(piVar1 + 0x4b);
              *(undefined4 *)(pbVar4 + 0x68) = uVar6;
              if (*(int *)(pbVar4 + 0x68) == 0) {
                local_bc = 1;
              }
            }
            else if (iVar2 == 4) {
              *(int *)(pbVar4 + 0x6c) = piVar1[0x4a];
              *(byte **)(pbVar4 + 0x14) = local_a4;
              local_a4 = pbVar4;
            }
          }
        }
        else {
          *pbVar4 = *pbVar4 | 0x80;
          *(int *)(pbVar4 + 100) = *piVar1;
          *(int *)(pbVar4 + 0x34) = piVar1[0x43];
          *(int *)(pbVar4 + 0x4c) = piVar1[0x44];
          *(int *)(pbVar4 + 0x50) = piVar1[0x45];
          *(int *)(pbVar4 + 0x54) = piVar1[0x46];
          *(int *)(pbVar4 + 0x58) = piVar1[0x47];
          *(int *)(pbVar4 + 0x5c) = piVar1[0x48];
          *(int *)(pbVar4 + 0x60) = piVar1[0x73];
          *(int *)(pbVar4 + 0x28) = local_b8;
          pbVar4[2] = (byte)local_4c;
        }
      }
      else {
        yaffs_SetChunkBit(param_1,iVar7,iVar8);
        local_88 = ((*puVar9 << 0xc) >> 0x16) + 1;
        *puVar9 = *puVar9 & DAT_30028f04 | (local_88 & DAT_30028f08) << 10;
        iVar2 = yaffs_FindOrCreateObjectByNumber(param_1,local_64,1);
        if (iVar2 == 0) {
          local_bc = 1;
        }
        else {
          iVar3 = yaffs_PutChunkIntoFile(iVar2,local_60,local_b8,1);
          if (iVar3 == 0) {
            local_bc = 1;
          }
        }
        local_94 = (local_60 + -1) * *(int *)(param_1 + 0x9c) + local_5c;
        if ((((iVar2 != 0) && (*(int *)(iVar2 + 100) == 1)) && (*(uint *)(iVar2 + 0x6c) < local_94))
           && (*(uint *)(iVar2 + 0x6c) = local_94, *(int *)(param_1 + 0x70) == 0)) {
          *(undefined4 *)(iVar2 + 0x68) = *(undefined4 *)(iVar2 + 0x6c);
        }
      }
      iVar8 = iVar8 + 1;
    }
    if (local_c0 == 2) {
      local_c0 = 5;
    }
    if (local_c0 == 4) {
      local_c0 = 5;
      *(undefined4 *)(param_1 + 0x138) = 0xffffffff;
    }
    local_90 = local_c0;
    *puVar9 = *puVar9 & 0xff0fffff | (local_c0 & 0xf) << 0x14;
    if ((((*puVar9 << 0xc) >> 0x16 == 0) && ((*puVar9 & 0x40000000) == 0)) &&
       ((*puVar9 >> 0x14 & 0xf) == 5)) {
      yaffs_BlockBecameDirty(param_1,iVar7);
    }
    local_ac = local_ac + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_30028f20 @ 0x30028F20  (примерный размер ~128 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: yaffs2_ScanBackwards
 * Константы: 0x30028F20
 * Данные: DAT_30029ea0, DAT_30029ea4
 * ---------------------------------------------------------------- */
int FUN_30028f20(int param_1,int param_2)

{
  if ((param_2 < *(int *)(param_1 + 0xdc)) || (*(int *)(param_1 + 0xe0) < param_2)) {
    printf(DAT_30029ea0,param_2);
    printf(DAT_30029ea4,0x1e);
  }
  return *(int *)(param_1 + 0x124) + (param_2 - *(int *)(param_1 + 0xdc)) * 8;
}

/* ----------------------------------------------------------------
 * yaffs2_CalcOldestDirtySequence @ 0x30028FA0  (примерный размер ~172 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs2_FindOldestDirtySequence
 * Константы: 0x30028FA0
 * ---------------------------------------------------------------- */
void yaffs2_CalcOldestDirtySequence(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 0x2c) != 0) {
    uVar3 = *(int *)(param_1 + 0xe10) + 1;
    puVar1 = *(uint **)(param_1 + 0x124);
    for (iVar4 = *(int *)(param_1 + 0xdc); iVar4 <= *(int *)(param_1 + 0xe0); iVar4 = iVar4 + 1) {
      if ((((*puVar1 >> 0x14 & 0xf) == 5) &&
          (((*puVar1 << 0xc) >> 0x16) - (*puVar1 & 0x3ff) < *(uint *)(param_1 + 0xc))) &&
         (puVar1[1] < uVar3)) {
        uVar3 = puVar1[1];
        iVar2 = iVar4;
      }
      puVar1 = puVar1 + 2;
    }
    if (iVar2 != 0) {
      *(uint *)(param_1 + 0xe14) = uVar3;
      *(int *)(param_1 + 0xe18) = iVar2;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs2_FindOldestDirtySequence @ 0x3002904C  (примерный размер ~44 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: yaffs2_CalcOldestDirtySequence
 * Вызывают: FUN_3001b670, yaffs2_BlockNotDisqualifiedFromGC
 * Константы: 0x3002904C
 * ---------------------------------------------------------------- */
void yaffs2_FindOldestDirtySequence(int param_1)

{
  if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0xe14) == 0)) {
    yaffs2_CalcOldestDirtySequence(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs2_ClearOldestDirtySequence @ 0x30029078  (примерный размер ~72 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300197f0, yaffs_BlockBecameDirty
 * Константы: 0x30029078
 * ---------------------------------------------------------------- */
void yaffs2_ClearOldestDirtySequence(int param_1,int param_2)

{
  if ((*(int *)(param_1 + 0x2c) != 0) &&
     ((param_2 == 0 || (*(int *)(param_2 + 4) == *(int *)(param_1 + 0xe14))))) {
    *(undefined4 *)(param_1 + 0xe14) = 0;
    *(undefined4 *)(param_1 + 0xe18) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs2_UpdateOldestDirtySequence @ 0x300290C0  (примерный размер ~76 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_3001a9e0, yaffs_DeleteChunk
 * Константы: 0x300290C0
 * ---------------------------------------------------------------- */
void yaffs2_UpdateOldestDirtySequence(int param_1,undefined4 param_2,int param_3)

{
  if (((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0xe14) != 0)) &&
     (*(uint *)(param_3 + 4) < *(uint *)(param_1 + 0xe14))) {
    *(undefined4 *)(param_1 + 0xe14) = *(undefined4 *)(param_3 + 4);
    *(undefined4 *)(param_1 + 0xe18) = param_2;
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs2_BlockNotDisqualifiedFromGC @ 0x3002910C  (примерный размер ~84 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: yaffs2_FindOldestDirtySequence
 * Вызывают: FUN_3001b670
 * Константы: 0x3002910C, 0x40000000
 * ---------------------------------------------------------------- */
undefined4 yaffs2_BlockNotDisqualifiedFromGC(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
    uVar1 = 1;
  }
  else if ((*param_2 & 0x40000000) == 0) {
    uVar1 = 1;
  }
  else {
    yaffs2_FindOldestDirtySequence(param_1);
    if (*(uint *)(param_1 + 0xe14) < param_2[1]) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs2_FindRefreshBlock @ 0x30029160  (примерный размер ~260 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: FUN_3001bb54
 * Константы: 0x30029160
 * Данные: DAT_30029e9c, DAT_3002a1e8
 * ---------------------------------------------------------------- */
uint yaffs2_FindRefreshBlock(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar2 = 0;
  if (*(int *)(param_1 + 0x2c) == 0) {
    uVar3 = 0;
  }
  else if (*(int *)(param_1 + 0x34) < 10) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x34) < *(int *)(param_1 + 0xe1c)) {
      *(undefined4 *)(param_1 + 0xe1c) = *(undefined4 *)(param_1 + 0x34);
    }
    if (*(int *)(param_1 + 0xe1c) < 1) {
      *(undefined4 *)(param_1 + 0xe1c) = *(undefined4 *)(param_1 + 0x34);
      *(int *)(param_1 + 0xe70) = *(int *)(param_1 + 0xe70) + 1;
      puVar1 = *(uint **)(param_1 + 0x124);
      for (uVar4 = *(uint *)(param_1 + 0xdc); uVar4 <= *(uint *)(param_1 + 0xe0); uVar4 = uVar4 + 1)
      {
        if (((*puVar1 >> 0x14 & 0xf) == 5) && ((uVar3 == 0 || (puVar1[1] < uVar2)))) {
          uVar2 = puVar1[1];
          uVar3 = uVar4;
        }
        puVar1 = puVar1 + 2;
      }
      if ((uVar3 != 0) && ((*DAT_30029e9c & 0x40) != 0)) {
        printf(DAT_3002a1e8,*(undefined4 *)(param_1 + 0xe70),uVar3,uVar2);
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * yaffs2_CheckpointRequired @ 0x30029264  (примерный размер ~100 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30029ffc, yaffs2_CalcCheckpointBlocksRequired
 * Константы: 0x30029264
 * ---------------------------------------------------------------- */
undefined4 yaffs2_CheckpointRequired(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
    uVar1 = 0;
  }
  else if (((*(char *)(param_1 + 0x39) == '\0') && (*(int *)(param_1 + 0xd4) == 0)) &&
          (0x3b < (*(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc)) + 1)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs2_CalcCheckpointBlocksRequired @ 0x300292C8  (примерный размер ~192 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 2
 * Вызывает: __div32, yaffs2_CheckpointRequired
 * Вызывают: FUN_3001bb54, yaffs_CheckSpaceForAllocation, yaffs_GetNumberOfFreeChunks
 * Константы: 0x300292C8
 * ---------------------------------------------------------------- */
int yaffs2_CalcCheckpointBlocksRequired(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
    iVar1 = 0;
  }
  else {
    if ((*(int *)(param_1 + 0x120) == 0) && (iVar1 = yaffs2_CheckpointRequired(param_1), iVar1 != 0)
       ) {
      iVar1 = (*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14)) + 1;
      iVar1 = __div32((*(int *)(param_1 + 0xb0) + 4) * *(int *)(param_1 + 0x14c) +
                      iVar1 * *(int *)(param_1 + 0x130) + iVar1 * 8 +
                      *(int *)(param_1 + 0x148) * 0x20 + 0x48,
                      *(int *)(param_1 + 0xc) * *(int *)(param_1 + 0x9c));
      *(int *)(param_1 + 0x120) = iVar1 + 3;
    }
    iVar1 = *(int *)(param_1 + 0x120) - *(int *)(param_1 + 0x100);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30029388 @ 0x30029388  (примерный размер ~112 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: memset, yaffs2_CheckpointWrite
 * Вызывают: FUN_30029ffc
 * Константы: 0x30029388
 * Данные: DAT_3002a33c
 * ---------------------------------------------------------------- */
bool FUN_30029388(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  
  memset(&local_20,0,0x10);
  local_20 = 0x10;
  local_1c = DAT_3002a33c;
  local_18 = 4;
  local_14 = (uint)(param_2 != 0);
  iVar1 = yaffs2_CheckpointWrite(param_1,&local_20,0x10);
  return iVar1 == 0x10;
}

/* ----------------------------------------------------------------
 * FUN_300293f8 @ 0x300293F8  (примерный размер ~164 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: yaffs2_CheckpointRead
 * Вызывают: FUN_3002a144
 * Константы: 0x300293F8
 * Данные: DAT_3002a33c
 * ---------------------------------------------------------------- */
undefined4 FUN_300293f8(undefined4 param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  
  iVar1 = yaffs2_CheckpointRead(param_1,&local_28,0x10);
  bVar2 = iVar1 == 0x10;
  if (bVar2) {
    if (local_28 != 0x10) {
      return 0;
    }
    if (local_24 != DAT_3002a33c) {
      return 0;
    }
    if (local_20 != 4) {
      return 0;
    }
    if (local_1c != (param_2 != 0)) {
      return 0;
    }
    bVar2 = true;
  }
  if (!bVar2) {
    return 0;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3002949c @ 0x3002949C  (примерный размер ~84 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30029544
 * Константы: 0x3002949C
 * ---------------------------------------------------------------- */
void FUN_3002949c(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 0x134);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 0x138);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0x13c);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0xd58);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0xdac);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0xdb0);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0xdb4);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0xe10);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300294f0 @ 0x300294F0  (примерный размер ~84 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300295fc
 * Константы: 0x300294F0
 * ---------------------------------------------------------------- */
void FUN_300294f0(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0xd58) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_1 + 0xdac) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(param_1 + 0xdb0) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0xdb4) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0xe10) = *(undefined4 *)(param_2 + 0x20);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30029544 @ 0x30029544  (примерный размер ~184 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3002949c, yaffs2_CheckpointWrite
 * Вызывают: FUN_30029ffc
 * Константы: 0x30029544
 * ---------------------------------------------------------------- */
bool FUN_30029544(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined4 local_3c [9];
  
  iVar3 = (*(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc)) + 1;
  FUN_3002949c(local_3c,param_1);
  local_3c[0] = 0x24;
  iVar1 = yaffs2_CheckpointWrite(param_1,local_3c,0x24);
  bVar4 = iVar1 == 0x24;
  if (bVar4) {
    iVar1 = iVar3 * 8;
    iVar2 = yaffs2_CheckpointWrite(param_1,*(undefined4 *)(param_1 + 0x124),iVar1);
    if (iVar2 == iVar1) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
  }
  if (bVar4) {
    iVar3 = *(int *)(param_1 + 0x130) * iVar3;
    iVar1 = yaffs2_CheckpointWrite(param_1,*(undefined4 *)(param_1 + 0x128),iVar3);
    if (iVar1 == iVar3) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
  }
  return bVar4;
}

/* ----------------------------------------------------------------
 * FUN_300295fc @ 0x300295FC  (примерный размер ~212 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300294f0, yaffs2_CheckpointRead
 * Вызывают: FUN_3002a144
 * Константы: 0x300295FC
 * ---------------------------------------------------------------- */
bool FUN_300295fc(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int local_3c [9];
  
  iVar3 = (*(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc)) + 1;
  iVar1 = yaffs2_CheckpointRead(param_1,local_3c,0x24);
  if (iVar1 == 0x24) {
    if (local_3c[0] == 0x24) {
      FUN_300294f0(param_1,local_3c);
      iVar1 = iVar3 * 8;
      iVar2 = yaffs2_CheckpointRead(param_1,*(undefined4 *)(param_1 + 0x124),iVar1);
      if (iVar2 == iVar1) {
        iVar3 = *(int *)(param_1 + 0x130) * iVar3;
        iVar1 = yaffs2_CheckpointRead(param_1,*(undefined4 *)(param_1 + 0x128),iVar3);
        bVar4 = iVar1 == iVar3;
      }
      else {
        bVar4 = false;
      }
    }
    else {
      bVar4 = false;
    }
  }
  else {
    bVar4 = false;
  }
  return bVar4;
}

/* ----------------------------------------------------------------
 * FUN_300296d0 @ 0x300296D0  (примерный размер ~360 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30029c70
 * Константы: 0x300296D0, 0xFFFFFFF8
 * ---------------------------------------------------------------- */
void FUN_300296d0(int param_1,byte *param_2)

{
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 0x30);
  if (*(int *)(param_2 + 0x1c) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_2 + 0x1c) + 0x30);
  }
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0x28);
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffff8 | *(uint *)(param_2 + 100) & 7;
  *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) & 0xf7 | (byte)((*param_2 & 1) << 3);
  *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) & 0xef | (byte)((*param_2 >> 1 & 1) << 4);
  *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) & 0xdf | (byte)((*param_2 >> 2 & 1) << 5);
  *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) & 0xbf | (byte)((*param_2 >> 3 & 1) << 6);
  *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) & 0x7f | (byte)((*param_2 >> 4 & 1) << 7);
  *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xfe | *param_2 >> 5 & 1;
  *(byte *)(param_1 + 0x12) = param_2[2];
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x2c);
  if (*(int *)(param_2 + 100) == 1) {
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x68);
  }
  else if (*(int *)(param_2 + 100) == 4) {
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x6c);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30029838 @ 0x30029838  (примерный размер ~444 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: yaffs_AddObjectToDirectory, yaffs_FindOrCreateObjectByNumber
 * Вызывают: FUN_30029dd4
 * Константы: 0x30029838
 * ---------------------------------------------------------------- */
undefined4 FUN_30029838(byte *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(uint *)(param_1 + 100) == (*(uint *)(param_2 + 0x10) & 7)) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 4);
    if (*(int *)(param_2 + 8) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = yaffs_FindOrCreateObjectByNumber
                        (*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_2 + 8),3);
    }
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 100) != 3) {
        return 0;
      }
      yaffs_AddObjectToDirectory(iVar2,param_1);
    }
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 0xc);
    *(uint *)(param_1 + 100) = *(uint *)(param_2 + 0x10) & 7;
    *param_1 = *param_1 & 0xfe | *(byte *)(param_2 + 0x10) >> 3 & 1;
    *param_1 = *param_1 & 0xfd | (byte)((*(byte *)(param_2 + 0x10) >> 4 & 1) << 1);
    *param_1 = *param_1 & 0xfb | (byte)((*(byte *)(param_2 + 0x10) >> 5 & 1) << 2);
    *param_1 = *param_1 & 0xf7 | (byte)((*(byte *)(param_2 + 0x10) >> 6 & 1) << 3);
    *param_1 = *param_1 & 0xef | (*(byte *)(param_2 + 0x10) >> 7) << 4;
    *param_1 = *param_1 & 0xdf | (byte)((*(byte *)(param_2 + 0x11) & 1) << 5);
    param_1[2] = *(byte *)(param_2 + 0x12);
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x14);
    if (*(int *)(param_1 + 100) == 1) {
      *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_2 + 0x18);
    }
    else if (*(int *)(param_1 + 100) == 4) {
      *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_2 + 0x18);
    }
    if (0 < *(int *)(param_1 + 0x28)) {
      param_1[1] = param_1[1] | 1;
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300299f4 @ 0x300299F4  (примерный размер ~212 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: yaffs2_CheckpointWrite
 * Вызывают: FUN_30029ac8
 * Константы: 0x300299F4
 * ---------------------------------------------------------------- */
uint FUN_300299f4(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int local_24;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar2 = 1;
  if (param_2 != 0) {
    if (param_3 == 0) {
      local_24 = param_4 << 4;
      iVar1 = yaffs2_CheckpointWrite(iVar3,&local_24,4);
      uVar2 = (uint)(iVar1 == 4);
      if (iVar1 == 4) {
        uVar2 = 1;
      }
      if (uVar2 != 0) {
        iVar1 = yaffs2_CheckpointWrite(iVar3,param_2,*(undefined4 *)(iVar3 + 0xb0));
        if (iVar1 == *(int *)(iVar3 + 0xb0)) {
          uVar2 = 1;
        }
        else {
          uVar2 = 0;
        }
      }
    }
    else {
      iVar3 = 0;
      while ((iVar3 < 8 && (uVar2 != 0))) {
        if (*(int *)(param_2 + iVar3 * 4) != 0) {
          uVar2 = FUN_300299f4(param_1,*(undefined4 *)(param_2 + iVar3 * 4),param_3 + -1,
                               iVar3 + param_4 * 8);
        }
        iVar3 = iVar3 + 1;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30029ac8 @ 0x30029AC8  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300299f4, yaffs2_CheckpointWrite
 * Вызывают: FUN_30029c70
 * Константы: 0x30029AC8, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
bool FUN_30029ac8(int param_1)

{
  int iVar1;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  iVar1 = 1;
  if ((*(int *)(param_1 + 100) == 1) &&
     (iVar1 = FUN_300299f4(param_1,*(undefined4 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x74),0
                          ), iVar1 != 0)) {
    iVar1 = yaffs2_CheckpointWrite(*(undefined4 *)(param_1 + 8),&local_14,4);
    if (iVar1 == 4) {
      iVar1 = 1;
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1 != 0;
}

/* ----------------------------------------------------------------
 * FUN_30029b40 @ 0x30029B40  (примерный размер ~304 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: printf, yaffs2_CheckpointRead, yaffs_AddOrFindLevel0Tnode, yaffs_GetTnode
 * Вызывают: FUN_30029dd4
 * Константы: 0x30029B40
 * Данные: DAT_30029e9c, DAT_3002ab84
 * ---------------------------------------------------------------- */
bool FUN_30029b40(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_24;
  
  iVar4 = *(int *)(param_1 + 8);
  iVar3 = 0;
  iVar1 = yaffs2_CheckpointRead(iVar4,&local_24,4);
  uVar5 = (uint)(iVar1 == 4);
  if (iVar1 == 4) {
    uVar5 = 1;
  }
  while( true ) {
    if ((uVar5 == 0) || (local_24 == -1)) {
      if ((*DAT_30029e9c & 0x8000) != 0) {
        printf(DAT_3002ab84,iVar3,local_24,uVar5);
      }
      return uVar5 != 0;
    }
    iVar3 = iVar3 + 1;
    iVar1 = yaffs_GetTnode(iVar4);
    if (iVar1 != 0) break;
    uVar5 = 0;
LAB_30029c0c:
    if (uVar5 != 0) {
LAB_30029c14:
      iVar1 = yaffs2_CheckpointRead(iVar4,&local_24,4);
      uVar5 = (uint)(iVar1 == 4);
    }
  }
  iVar2 = yaffs2_CheckpointRead(iVar4,iVar1,*(undefined4 *)(iVar4 + 0xb0));
  uVar5 = (uint)(iVar2 == *(int *)(iVar4 + 0xb0));
  if (uVar5 == 0) goto LAB_30029c0c;
  iVar1 = yaffs_AddOrFindLevel0Tnode(iVar4,param_1 + 0x68,local_24,iVar1);
  if (iVar1 == 0) {
    uVar5 = 0;
    goto LAB_30029c0c;
  }
  goto LAB_30029c14;
}

/* ----------------------------------------------------------------
 * FUN_30029c70 @ 0x30029C70  (примерный размер ~356 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300296d0, FUN_30029ac8, memset, printf, yaffs2_CheckpointWrite
 * Вызывают: FUN_30029ffc
 * Константы: 0x30029C70
 * Данные: DAT_30029e9c, DAT_3002ac80
 * ---------------------------------------------------------------- */
bool FUN_30029c70(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  uVar3 = 1;
  for (iVar4 = 0; (uVar3 != 0 && (iVar4 < 0x100)); iVar4 = iVar4 + 1) {
    for (piVar2 = *(int **)(param_1 + iVar4 * 0xc + 0x154);
        (int *)(param_1 + iVar4 * 0xc + 0x154) != piVar2; piVar2 = (int *)*piVar2) {
      if ((piVar2 != (int *)0x0) && (iVar5 = (int)(piVar2 + -3), (*piVar2 & 0x20000000000) == 0)) {
        FUN_300296d0(&local_38,iVar5);
        local_38 = 0x1c;
        if ((*DAT_30029e9c & 0x8000) != 0) {
          printf(DAT_3002ac80,local_34,local_30,local_28 & 7,local_2c,iVar5);
        }
        iVar1 = yaffs2_CheckpointWrite(param_1,&local_38,0x1c);
        uVar3 = (uint)(iVar1 == 0x1c);
        if ((uVar3 != 0) && (piVar2[0x16] == 1)) {
          uVar3 = FUN_30029ac8(iVar5);
        }
      }
    }
  }
  memset(&local_38,0xff,0x1c);
  local_38 = 0x1c;
  if (uVar3 != 0) {
    iVar4 = yaffs2_CheckpointWrite(param_1,&local_38,0x1c);
    if (iVar4 == 0x1c) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3 != 0;
}

/* ----------------------------------------------------------------
 * FUN_30029dd4 @ 0x30029DD4  (примерный размер ~380 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_30029838, FUN_30029b40, printf, yaffs2_CheckpointRead, yaffs_FindOrCreateObjectByNumber, yaffs_HardlinkFixup
 * Вызывают: FUN_3002a144
 * Константы: 0x30029DD4
 * Данные: DAT_30029e9c, DAT_3002ad9c, DAT_3002ada0
 * ---------------------------------------------------------------- */
bool FUN_30029dd4(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  uVar4 = 1;
  bVar1 = false;
  iVar3 = 0;
  while( true ) {
    do {
      while( true ) {
        if ((uVar4 == 0) || (bVar1)) goto LAB_30029f24;
        iVar2 = yaffs2_CheckpointRead(param_1,&local_38,0x1c);
        uVar4 = (uint)(iVar2 == 0x1c);
        if (local_38 != 0x1c) {
          if ((*DAT_30029e9c & 0x8000) != 0) {
            printf(DAT_3002ad9c,local_38,0x1c,uVar4);
          }
          uVar4 = 0;
        }
        if ((*DAT_30029e9c & 0x8000) != 0) {
          printf(DAT_3002ada0,local_34,local_30,local_28 & 7,local_2c);
        }
        if ((uVar4 == 0) || (local_34 != -1)) break;
        bVar1 = true;
      }
    } while (uVar4 == 0);
    iVar2 = yaffs_FindOrCreateObjectByNumber(param_1,local_34,local_28 & 7);
    if (iVar2 == 0) break;
    uVar4 = FUN_30029838(iVar2,&local_38);
    if (uVar4 == 0) goto LAB_30029f24;
    if (*(int *)(iVar2 + 100) == 1) {
      uVar4 = FUN_30029b40(iVar2);
    }
    else if (*(int *)(iVar2 + 100) == 4) {
      *(int *)(iVar2 + 0x14) = iVar3;
      iVar3 = iVar2;
    }
  }
  uVar4 = 0;
LAB_30029f24:
  if (uVar4 != 0) {
    yaffs_HardlinkFixup(param_1,iVar3);
  }
  return uVar4 != 0;
}

/* ----------------------------------------------------------------
 * FUN_30029f50 @ 0x30029F50  (примерный размер ~72 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: yaffs2_CheckpointWrite, yaffs2_GetCheckpointSum
 * Вызывают: FUN_30029ffc
 * Константы: 0x30029F50
 * ---------------------------------------------------------------- */
bool FUN_30029f50(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_10 [4];
  
  yaffs2_GetCheckpointSum(param_1,auStack_10);
  iVar1 = yaffs2_CheckpointWrite(param_1,auStack_10,4);
  return iVar1 == 4;
}

/* ----------------------------------------------------------------
 * FUN_30029f98 @ 0x30029F98  (примерный размер ~100 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: yaffs2_CheckpointRead, yaffs2_GetCheckpointSum
 * Вызывают: FUN_3002a144
 * Константы: 0x30029F98
 * ---------------------------------------------------------------- */
undefined4 FUN_30029f98(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  int local_10;
  
  yaffs2_GetCheckpointSum(param_1,&local_10);
  iVar1 = yaffs2_CheckpointRead(param_1,&local_14,4);
  if (iVar1 == 4) {
    if (local_10 == local_14) {
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
 * FUN_30029ffc @ 0x30029FFC  (примерный размер ~328 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_30029388, FUN_30029544, FUN_30029c70, FUN_30029f50, printf, yaffs2_CheckpointClose, yaffs2_CheckpointOpen, yaffs2_CheckpointRequired
 * Вызывают: yaffs_CheckpointSave
 * Константы: 0x30029FFC
 * Данные: DAT_3002af2c, DAT_3002af30, DAT_3002af34, DAT_3002af38, DAT_3002af3c
 * ---------------------------------------------------------------- */
undefined4 FUN_30029ffc(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  iVar1 = yaffs2_CheckpointRequired(param_1);
  if (iVar1 == 0) {
    if ((*DAT_3002af2c & 0x8000) != 0) {
      printf(DAT_3002af30);
    }
    iVar2 = 0;
  }
  if (iVar2 != 0) {
    iVar2 = yaffs2_CheckpointOpen(param_1,1);
  }
  if (iVar2 != 0) {
    if ((*DAT_3002af2c & 0x8000) != 0) {
      printf(DAT_3002af34);
    }
    iVar2 = FUN_30029388(param_1,1);
  }
  if (iVar2 != 0) {
    if ((*DAT_3002af2c & 0x8000) != 0) {
      printf(DAT_3002af38);
    }
    iVar2 = FUN_30029544(param_1);
  }
  if (iVar2 != 0) {
    if ((*DAT_3002af2c & 0x8000) != 0) {
      printf(DAT_3002af3c);
    }
    iVar2 = FUN_30029c70(param_1);
  }
  if (iVar2 != 0) {
    if ((*DAT_3002af2c & 0x8000) != 0) {
      printf(DAT_3002af34);
    }
    iVar2 = FUN_30029388(param_1,0);
  }
  if (iVar2 != 0) {
    iVar2 = FUN_30029f50(param_1);
  }
  iVar1 = yaffs2_CheckpointClose(param_1);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  *(uint *)(param_1 + 0xd8) = (uint)(iVar2 != 0);
  return *(undefined4 *)(param_1 + 0xd8);
}

/* ----------------------------------------------------------------
 * FUN_3002a144 @ 0x3002A144  (примерный размер ~396 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_300293f8, FUN_300295fc, FUN_30029dd4, FUN_30029f98, printf, yaffs2_CheckpointClose, yaffs2_CheckpointOpen
 * Вызывают: yaffs2_CheckpointRestore
 * Константы: 0x3002A144
 * Данные: DAT_3002af2c, DAT_3002b070, DAT_3002b074, DAT_3002b078, DAT_3002b190, DAT_3002b194
 * ---------------------------------------------------------------- */
bool FUN_3002a144(int param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)(*(int *)(param_1 + 0x2c) != 0);
  if ((uVar2 != 0) && (*(char *)(param_1 + 0x38) != '\0')) {
    if ((*DAT_3002af2c & 0x8000) != 0) {
      printf(DAT_3002b070);
    }
    uVar2 = 0;
  }
  if (uVar2 != 0) {
    uVar2 = yaffs2_CheckpointOpen(param_1,0);
  }
  if (uVar2 != 0) {
    if ((*DAT_3002af2c & 0x8000) != 0) {
      printf(DAT_3002b074);
    }
    uVar2 = FUN_300293f8(param_1,1);
  }
  if (uVar2 != 0) {
    if ((*DAT_3002af2c & 0x8000) != 0) {
      printf(DAT_3002b078);
    }
    uVar2 = FUN_300295fc(param_1);
  }
  if (uVar2 != 0) {
    if ((*DAT_3002af2c & 0x8000) != 0) {
      printf(DAT_3002b190);
    }
    uVar2 = FUN_30029dd4(param_1);
  }
  if (uVar2 != 0) {
    if ((*DAT_3002af2c & 0x8000) != 0) {
      printf(DAT_3002b074);
    }
    uVar2 = FUN_300293f8(param_1,0);
  }
  if ((uVar2 != 0) && (uVar2 = FUN_30029f98(param_1), (*DAT_3002af2c & 0x8000) != 0)) {
    printf(DAT_3002b194,uVar2);
  }
  iVar1 = yaffs2_CheckpointClose(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  *(uint *)(param_1 + 0xd8) = (uint)(uVar2 != 0);
  return uVar2 != 0;
}

/* ----------------------------------------------------------------
 * yaffs2_InvalidateCheckpoint @ 0x3002A2D0  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 1
 * Вызывает: yaffs2_CheckpointInvalidateStream
 * Вызывают: FUN_300197f0, FUN_3001a0fc, yaffs_BlockBecameDirty, yaffs_CheckpointSave, yaffs_GutsInitialise
 * Константы: 0x3002A2D0
 * ---------------------------------------------------------------- */
void yaffs2_InvalidateCheckpoint(int param_1)

{
  if ((*(int *)(param_1 + 0xd8) != 0) || (0 < *(int *)(param_1 + 0x100))) {
    *(undefined4 *)(param_1 + 0xd8) = 0;
    yaffs2_CheckpointInvalidateStream(param_1);
  }
  if (*(int *)(param_1 + 0x68) != 0) {
    (**(code **)(param_1 + 0x68))(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_CheckpointSave @ 0x3002A328  (примерный размер ~136 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_30029ffc, printf, yaffs2_InvalidateCheckpoint, yaffs_VerifyBlocks, yaffs_VerifyFreeChunks, yaffs_VerifyObjects
 * Вызывают: yaffs_unmount
 * Константы: 0x3002A328
 * Данные: DAT_3002af2c, DAT_3002b274, DAT_3002b278
 * ---------------------------------------------------------------- */
undefined4 yaffs_CheckpointSave(int param_1)

{
  if ((*DAT_3002af2c & 0x8000) != 0) {
    printf(DAT_3002b274,*(undefined4 *)(param_1 + 0xd8));
  }
  yaffs_VerifyObjects(param_1);
  yaffs_VerifyBlocks(param_1);
  yaffs_VerifyFreeChunks(param_1);
  if (*(int *)(param_1 + 0xd8) == 0) {
    yaffs2_InvalidateCheckpoint(param_1);
    FUN_30029ffc(param_1);
  }
  printf(DAT_3002b278,*(undefined4 *)(param_1 + 0xd8));
  return *(undefined4 *)(param_1 + 0xd8);
}

/* ----------------------------------------------------------------
 * yaffs2_CheckpointRestore @ 0x3002A3B0  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_3002a144, printf, yaffs_VerifyBlocks, yaffs_VerifyFreeChunks, yaffs_VerifyObjects
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x3002A3B0
 * Данные: DAT_3002af2c, DAT_3002b27c, DAT_3002b32c
 * ---------------------------------------------------------------- */
undefined4 yaffs2_CheckpointRestore(int param_1)

{
  undefined4 uVar1;
  
  if ((*DAT_3002af2c & 0x8000) != 0) {
    printf(DAT_3002b27c,*(undefined4 *)(param_1 + 0xd8));
  }
  uVar1 = FUN_3002a144(param_1);
  if (*(int *)(param_1 + 0xd8) != 0) {
    yaffs_VerifyObjects(param_1);
    yaffs_VerifyBlocks(param_1);
    yaffs_VerifyFreeChunks(param_1);
  }
  if ((*DAT_3002af2c & 0x8000) != 0) {
    printf(DAT_3002b32c,*(undefined4 *)(param_1 + 0xd8));
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs2_HandleHole @ 0x3002A428  (примерный размер ~656 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 7
 * Вызывает: memset, yaffs_CheckSpaceForAllocation, yaffs_DoWriteDataToFile, yaffs_GetTempBuffer, yaffs_ReleaseTempBuffer, yaffs_ResizeDown, yaffs_UpdateObjectHeader
 * Вызывают: yaffs_ResizeFile, yaffs_WriteDataToFile
 * Константы: 0x3002A428
 * Данные: DAT_3002b44c
 * ---------------------------------------------------------------- */
undefined4 yaffs2_HandleHole(int param_1,uint param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *__s;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  __s = (void *)0x0;
  bVar1 = false;
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 100) != 1) {
    return 0;
  }
  iVar5 = *(int *)(param_1 + 8);
  if (*(int *)(iVar5 + 0x2c) == 0) {
    return 1;
  }
  uVar7 = *(uint *)(param_1 + 0x68);
  if (param_3 != 0) {
    if (param_3 < 1) {
      return 1;
    }
    if (0 < param_3) goto LAB_3002a4d4;
  }
  if (param_3 == 0 && param_2 <= uVar7) {
    return 1;
  }
LAB_3002a4d4:
  iVar6 = param_2 - uVar7;
  if ((iVar6 < *(int *)(iVar5 + 0x9c) * 4) &&
     (iVar2 = yaffs_CheckSpaceForAllocation(iVar5,5), iVar2 != 0)) {
    __s = (void *)yaffs_GetTempBuffer(iVar5,DAT_3002b44c);
  }
  if (__s != (void *)0x0) {
    memset(__s,0,*(size_t *)(iVar5 + 0x9c));
    bVar1 = true;
    uVar4 = uVar7;
    while ((0 < iVar6 && (bVar1))) {
      iVar2 = iVar6;
      if (*(int *)(iVar5 + 0x9c) < iVar6) {
        iVar2 = *(int *)(iVar5 + 0x9c);
      }
      iVar3 = yaffs_DoWriteDataToFile(param_1,__s,uVar4,(int)uVar4 >> 0x1f,iVar2,0);
      if (iVar3 == iVar2) {
        uVar4 = uVar4 + iVar2;
        iVar6 = iVar6 - iVar2;
      }
      else {
        bVar1 = false;
      }
    }
    yaffs_ReleaseTempBuffer(iVar5,__s,0x370);
    if (!bVar1) {
      yaffs_ResizeDown(param_1,uVar7,0);
    }
  }
  if (bVar1) {
    return 1;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    return 1;
  }
  if (*(int *)(*(int *)(param_1 + 0x1c) + 0x30) != 3) {
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x30) != 4) {
      yaffs_UpdateObjectHeader(param_1,0,0,1,0,0);
      return 1;
    }
    return 1;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * yaffs2_ScanBackwards @ 0x3002A6B8  (примерный размер ~3720 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 21
 * Вызывает: FUN_30028f20, free, malloc, printf, yaffs_AddObjectToDirectory, yaffs_BlockBecameDirty, yaffs_ClearChunkBits, yaffs_CloneString, yaffs_DeleteChunk, yaffs_FindOrCreateObjectByNumber, yaffs_GetTempBuffer, yaffs_HandleShadowedObject, yaffs_HardlinkFixup, yaffs_PutChunkIntoFile
 *           ...
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0xFF0FFFFF, 0x40000000, 0x3002A6B8, 0x00700000, 0x00900000, 0xFFFFFFFF
 * Данные: DAT_3002af2c, DAT_3002b4cc, DAT_3002b4d0, DAT_3002b4d4, DAT_3002b4d8, DAT_3002b4dc, DAT_3002b4e0, DAT_3002b4e4
 * ---------------------------------------------------------------- */
undefined4 yaffs2_ScanBackwards(int param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint *puVar7;
  uint local_dc;
  void *local_d8;
  int local_d4;
  int local_d0;
  uint local_cc;
  int local_c8;
  uint local_c4;
  int local_c0;
  uint local_bc;
  byte *local_b8;
  int *local_b4;
  int local_b0;
  uint local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  int local_80;
  int local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined1 auStack_6c [4];
  int local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  int local_58;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int local_2c;
  
  local_d0 = 0;
  local_b8 = (byte *)0x0;
  local_a4 = (*(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc)) + 1;
  local_d4 = 0;
  local_d8 = (void *)0x0;
  local_98 = 0;
  if ((*DAT_3002af2c & 8) != 0) {
    printf(DAT_3002b4cc,*(undefined4 *)(param_1 + 0xdc),*(undefined4 *)(param_1 + 0xe0));
  }
  *(undefined4 *)(param_1 + 0xe10) = 0x1000;
  local_d8 = malloc(local_a4 << 3);
  if (local_d8 == (void *)0x0) {
    local_d8 = malloc(local_a4 << 3);
    local_98 = 1;
  }
  if (local_d8 == (void *)0x0) {
    if ((*DAT_3002af2c & 8) != 0) {
      printf(DAT_3002b4d0);
    }
    return 0;
  }
  *(undefined4 *)(param_1 + 0x100) = 0;
  local_b4 = (int *)yaffs_GetTempBuffer(param_1,DAT_3002b4d4);
  puVar7 = *(uint **)(param_1 + 0x124);
  for (iVar3 = *(int *)(param_1 + 0xdc); iVar3 <= *(int *)(param_1 + 0xe0); iVar3 = iVar3 + 1) {
    yaffs_ClearChunkBits(param_1,iVar3);
    *puVar7 = *puVar7 & DAT_3002b4d8;
    yaffs_QueryInitialBlockState(param_1,iVar3,&local_dc,&local_cc);
    local_84 = local_dc;
    *puVar7 = *puVar7 & 0xff0fffff | (local_dc & 0xf) << 0x14;
    puVar7[1] = local_cc;
    if (puVar7[1] == 0x21) {
      local_dc = 7;
      *puVar7 = *puVar7 & 0xff0fffff | 0x700000;
    }
    if (puVar7[1] == DAT_3002b4dc) {
      local_dc = 9;
      *puVar7 = *puVar7 & 0xff0fffff | 0x900000;
    }
    if ((*DAT_3002af2c & 0x2000) != 0) {
      printf(DAT_3002b4e0,iVar3,local_dc,local_cc);
    }
    if (local_dc == 7) {
      *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;
    }
    else if (local_dc == 9) {
      if ((*DAT_3002af2c & 0x10) != 0) {
        printf(DAT_3002b4e4,iVar3);
      }
    }
    else if (local_dc == 3) {
      if ((*DAT_3002af2c & 0x2000) != 0) {
        printf(DAT_3002b4e8);
      }
      *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
      *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) + *(int *)(param_1 + 0xc);
    }
    else if (local_dc == 2) {
      if ((local_cc < 0x1000) || (DAT_3002b4ec <= local_cc)) {
        if ((*DAT_3002af2c & 8) != 0) {
          printf(DAT_3002b4f0,iVar3,local_cc);
        }
      }
      else {
        *(uint *)((int)local_d8 + local_d0 * 8) = local_cc;
        *(int *)((int)local_d8 + local_d0 * 8 + 4) = iVar3;
        local_d0 = local_d0 + 1;
        if (*(uint *)(param_1 + 0xe10) <= local_cc) {
          *(uint *)(param_1 + 0xe10) = local_cc;
        }
      }
    }
    puVar7 = puVar7 + 2;
  }
  if ((*DAT_3002af2c & 8) != 0) {
    printf(DAT_3002b4f4,local_d0);
  }
  yaffs_qsort(local_d8,local_d0,8,DAT_3002b4f8);
  if ((*DAT_3002af2c & 8) != 0) {
    printf(DAT_3002b4fc);
  }
  local_7c = 0;
  local_78 = local_d0 + -1;
  if ((*DAT_3002af2c & 0x2000) != 0) {
    printf(DAT_3002b500,local_d0);
  }
  local_c0 = local_78;
  do {
    if ((local_d4 != 0) || (local_c0 < local_7c)) {
      yaffs_SkipRestOfBlock(param_1);
      if (local_98 == 0) {
        free(local_d8);
      }
      else {
        free(local_d8);
      }
      yaffs_HardlinkFixup(param_1,local_b8);
      yaffs_ReleaseTempBuffer(param_1,local_b4,DAT_3002b538);
      if (local_d4 != 0) {
        return 0;
      }
      if ((*DAT_3002b530 & 8) != 0) {
        printf(DAT_3002b53c);
      }
      return 1;
    }
    iVar4 = *(int *)((int)local_d8 + local_c0 * 8 + 4);
    puVar7 = (uint *)FUN_30028f20(param_1,iVar4);
    local_dc = *puVar7 >> 0x14 & 0xf;
    local_70 = 0;
    local_b0 = 0;
    iVar3 = *(int *)(param_1 + 0xc);
    while (((iVar3 = iVar3 + -1, local_d4 == 0 && (-1 < iVar3)) &&
           ((local_dc == 2 || (local_dc == 4))))) {
      iVar6 = iVar4 * *(int *)(param_1 + 0xc) + iVar3;
      local_74 = yaffs_ReadChunkWithTagsFromNAND(param_1,iVar6,0,auStack_6c);
      if (local_68 == 0) {
        if (local_b0 == 0) {
          if (iVar3 == 0) {
            local_dc = 3;
            *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
          }
          else if ((local_dc == 2) || (local_dc == 4)) {
            if (*(uint *)(param_1 + 0xe10) == puVar7[1]) {
              if ((*DAT_3002af2c & 8) != 0) {
                printf(DAT_3002b504,iVar4,iVar3);
              }
              local_dc = 4;
              *(int *)(param_1 + 0x138) = iVar4;
              *(int *)(param_1 + 0x13c) = iVar3;
              *(int *)(param_1 + 0x140) = iVar4;
            }
            else if ((*DAT_3002af2c & 8) != 0) {
              printf(DAT_3002b508,iVar4);
            }
          }
        }
        *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) + 1;
      }
      else if (local_58 == 3) {
        if ((*DAT_3002af2c & 8) != 0) {
          printf(DAT_3002b50c,iVar4,iVar3);
        }
        *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) + 1;
      }
      else if (((DAT_3002b510 < local_64) || (DAT_3002b514 < local_60)) ||
              (((local_60 != 0 && (*(uint *)(param_1 + 0x9c) < local_5c)) || (local_48 != puVar7[1])
               ))) {
        if ((*DAT_3002af2c & 8) != 0) {
          printf(DAT_3002b518,iVar4,iVar3,local_64,local_60,local_5c);
        }
        *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) + 1;
      }
      else if (local_60 == 0) {
        local_b0 = 1;
        yaffs_SetChunkBit(param_1,iVar4,iVar3);
        local_8c = ((*puVar7 << 0xc) >> 0x16) + 1;
        *puVar7 = *puVar7 & DAT_3002b51c | (local_8c & DAT_3002b520) << 10;
        piVar5 = (int *)0x0;
        pbVar1 = (byte *)0x0;
        if ((local_44 != 0) &&
           (pbVar1 = (byte *)yaffs_FindOrCreateObjectByNumber(param_1,local_64,local_34),
           pbVar1 == (byte *)0x0)) {
          local_d4 = 1;
        }
        if (((pbVar1 == (byte *)0x0) ||
            ((((*pbVar1 & 0x80) == 0 && (*(int *)(param_1 + 0x74) != 0)) || (local_38 != 0)))) ||
           (((*pbVar1 & 0x80) == 0 && ((local_64 == 1 || (local_64 == 2)))))) {
          local_74 = yaffs_ReadChunkWithTagsFromNAND(param_1,iVar6,local_b4,0);
          piVar5 = local_b4;
          if (*(int *)(param_1 + 4) != 0) {
            local_b4[0x7e] = local_b4[0x7a];
            local_b4[0x7f] = local_b4[0x7b];
          }
          if ((pbVar1 == (byte *)0x0) &&
             (pbVar1 = (byte *)yaffs_FindOrCreateObjectByNumber(param_1,local_64,*local_b4),
             pbVar1 == (byte *)0x0)) {
            local_d4 = 1;
          }
        }
        if (pbVar1 == (byte *)0x0) {
          printf(DAT_3002b528,local_64,iVar6);
        }
        else {
          if ((*pbVar1 & 0x80) != 0) {
            if ((*(int *)(pbVar1 + 100) == 1) &&
               (((piVar5 != (int *)0x0 && (*piVar5 == 1)) || ((local_44 != 0 && (local_34 == 1))))))
            {
              if (piVar5 == (int *)0x0) {
                local_bc = local_30;
                local_a8 = local_40;
                local_c8 = local_3c;
              }
              else {
                local_bc = piVar5[0x49];
                local_a8 = piVar5[1];
                local_c8 = piVar5[0x7f];
              }
              if ((local_a8 == 4) || (local_a8 == 3)) {
                local_bc = 0;
                local_c8 = 1;
              }
              if ((local_c8 != 0) && (local_bc < *(uint *)(pbVar1 + 0x70))) {
                *(uint *)(pbVar1 + 0x70) = local_bc;
              }
              if (local_c8 != 0) {
                *puVar7 = *puVar7 | 0x40000000;
              }
            }
            yaffs_DeleteChunk(param_1,iVar6,1,DAT_3002b52c);
          }
          if ((*pbVar1 & 0x80) == 0) {
            if (piVar5 == (int *)0x0) {
              local_80 = local_34;
            }
            else {
              local_80 = *piVar5;
            }
          }
          if (((*pbVar1 & 0x80) == 0) && ((local_64 == 1 || (local_64 == 2)))) {
            *pbVar1 = *pbVar1 | 0x80;
            if (piVar5 == (int *)0x0) {
              pbVar1[1] = pbVar1[1] | 1;
            }
            else {
              *(int *)(pbVar1 + 0x34) = piVar5[0x43];
              *(int *)(pbVar1 + 0x4c) = piVar5[0x44];
              *(int *)(pbVar1 + 0x50) = piVar5[0x45];
              *(int *)(pbVar1 + 0x54) = piVar5[0x46];
              *(int *)(pbVar1 + 0x58) = piVar5[0x47];
              *(int *)(pbVar1 + 0x5c) = piVar5[0x48];
              *(int *)(pbVar1 + 0x60) = piVar5[0x73];
              pbVar1[1] = pbVar1[1] & 0xfe;
            }
            *(int *)(pbVar1 + 0x28) = iVar6;
          }
          else if ((*pbVar1 & 0x80) == 0) {
            *pbVar1 = *pbVar1 | 0x80;
            *(int *)(pbVar1 + 0x28) = iVar6;
            if (piVar5 == (int *)0x0) {
              *(int *)(pbVar1 + 100) = local_34;
              iVar6 = yaffs_FindOrCreateObjectByNumber(param_1,local_40,3);
              local_c4 = local_30;
              local_c8 = local_3c;
              local_9c = local_2c;
              pbVar1[1] = pbVar1[1] | 1;
            }
            else {
              *(int *)(pbVar1 + 100) = *piVar5;
              *(int *)(pbVar1 + 0x34) = piVar5[0x43];
              *(int *)(pbVar1 + 0x4c) = piVar5[0x44];
              *(int *)(pbVar1 + 0x50) = piVar5[0x45];
              *(int *)(pbVar1 + 0x54) = piVar5[0x46];
              *(int *)(pbVar1 + 0x58) = piVar5[0x47];
              *(int *)(pbVar1 + 0x5c) = piVar5[0x48];
              *(int *)(pbVar1 + 0x60) = piVar5[0x73];
              if (0 < piVar5[0x7e]) {
                yaffs_HandleShadowedObject(param_1,piVar5[0x7e],1);
              }
              yaffs_SetObjectNameFromOH(pbVar1,piVar5);
              iVar6 = yaffs_FindOrCreateObjectByNumber(param_1,piVar5[1],3);
              local_c4 = piVar5[0x49];
              local_c8 = piVar5[0x7f];
              local_9c = piVar5[0x4a];
            }
            *pbVar1 = *pbVar1 & 0xbf;
            if (iVar6 == 0) {
              local_d4 = 1;
LAB_3002b280:
              if ((iVar6 == 0) || (*(int *)(iVar6 + 100) != 3)) {
                printf(DAT_3002b534);
                iVar6 = *(int *)(param_1 + 0xd8c);
              }
            }
            else {
              if (*(int *)(iVar6 + 100) != 0) goto LAB_3002b280;
              *(undefined4 *)(iVar6 + 100) = 3;
              *(int *)(iVar6 + 0x68) = iVar6 + 0x68;
              *(int *)(iVar6 + 0x6c) = iVar6 + 0x68;
            }
            yaffs_AddObjectToDirectory(iVar6,pbVar1);
            if ((*(int *)(param_1 + 0xda4) == iVar6) || (*(int *)(param_1 + 0xda0) == iVar6)) {
              local_a0 = 1;
            }
            else {
              local_a0 = 0;
            }
            if (local_c8 != 0) {
              *puVar7 = *puVar7 | 0x40000000;
            }
            iVar6 = *(int *)(pbVar1 + 100);
            if (iVar6 == 1) {
              if (*(uint *)(pbVar1 + 0x6c) < local_c4) {
                *(uint *)(pbVar1 + 0x68) = local_c4;
                *(uint *)(pbVar1 + 0x6c) = local_c4;
              }
              if (local_c4 < *(uint *)(pbVar1 + 0x70)) {
                *(uint *)(pbVar1 + 0x70) = local_c4;
              }
            }
            else if (iVar6 == 2) {
              if (piVar5 != (int *)0x0) {
                uVar2 = yaffs_CloneString(piVar5 + 0x4b);
                *(undefined4 *)(pbVar1 + 0x68) = uVar2;
                if (*(int *)(pbVar1 + 0x68) == 0) {
                  local_d4 = 1;
                }
              }
            }
            else if ((iVar6 == 4) && (local_a0 == 0)) {
              *(int *)(pbVar1 + 0x6c) = local_9c;
              *(byte **)(pbVar1 + 0x14) = local_b8;
              local_b8 = pbVar1;
            }
          }
        }
      }
      else {
        local_94 = *(int *)(param_1 + 0x9c) * (local_60 - 1);
        local_b0 = 1;
        yaffs_SetChunkBit(param_1,iVar4,iVar3);
        local_88 = ((*puVar7 << 0xc) >> 0x16) + 1;
        *puVar7 = *puVar7 & DAT_3002b51c | (local_88 & DAT_3002b520) << 10;
        pbVar1 = (byte *)yaffs_FindOrCreateObjectByNumber(param_1,local_64,1);
        if (pbVar1 == (byte *)0x0) {
          local_d4 = 1;
LAB_3002ada4:
          if (pbVar1 != (byte *)0x0) {
            yaffs_DeleteChunk(param_1,iVar6,1,DAT_3002b524);
          }
        }
        else {
          if ((*(int *)(pbVar1 + 100) != 1) || (*(uint *)(pbVar1 + 0x70) <= local_94))
          goto LAB_3002ada4;
          iVar6 = yaffs_PutChunkIntoFile(pbVar1,local_60,iVar6,0xffffffff);
          if (iVar6 == 0) {
            local_d4 = 1;
          }
          local_ac = local_94 + local_5c;
          if (((*pbVar1 & 0x80) == 0) && (*(uint *)(pbVar1 + 0x6c) < local_ac)) {
            *(uint *)(pbVar1 + 0x6c) = local_ac;
            *(uint *)(pbVar1 + 0x68) = local_ac;
          }
        }
      }
    }
    if (local_dc == 2) {
      local_dc = 5;
    }
    local_90 = local_dc;
    *puVar7 = *puVar7 & 0xff0fffff | (local_dc & 0xf) << 0x14;
    if ((((*puVar7 << 0xc) >> 0x16 == 0) && ((*puVar7 & 0x40000000) == 0)) &&
       ((*puVar7 >> 0x14 & 0xf) == 5)) {
      yaffs_BlockBecameDirty(param_1,iVar4);
    }
    local_c0 = local_c0 + -1;
  } while( true );
}

/* ----------------------------------------------------------------
 * ptable_get_ram_head @ 0x3002B588  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 9 | Вызывает: 0
 * Вызывают: FUN_3002cd64, ptable_check_integrality, ptable_ensure, ptable_mark_default, ptable_parse_mtd_partitions, ptable_replace_flash_table, ptable_replace_ram_table, ptable_set_integrality, ptable_show
 * Константы: 0x3002B588
 * Данные: DAT_3002c430
 * ---------------------------------------------------------------- */
undefined4 ptable_get_ram_head(void)

{
  return DAT_3002c430;
}

/* ----------------------------------------------------------------
 * ptable_get_ram_data @ 0x3002B590  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 17 | Вызывает: 0
 * Вызывают: ImageDloadToFlash, ImageDloadToRam, dload_GetISOUseableSize, ptable_dload_read, ptable_dload_write, ptable_erase_partition, ptable_find_theother_by_type, ptable_get_cdromiso_version, ptable_get_range, ptable_parse_mtd_partitions
 *           ...
 * Константы: 0x3002B590
 * Данные: DAT_3002c434
 * ---------------------------------------------------------------- */
undefined4 ptable_get_ram_data(void)

{
  return DAT_3002c434;
}

/* ----------------------------------------------------------------
 * ptable_mark_default @ 0x3002B598  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: ptable_get_ram_head
 * Вызывают: ptable_ensure
 * Константы: 0x3002B598, 0xBFFFFFFF, 0x40000000
 * ---------------------------------------------------------------- */
void ptable_mark_default(void)

{
  int iVar1;
  
  iVar1 = ptable_get_ram_head();
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xbfffffff | 0x40000000;
  return;
}

/* ----------------------------------------------------------------
 * ptable_ensure @ 0x3002B5B8  (примерный размер ~180 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 8
 * Вызывает: memcpy, memset, printf, ptable_get_ram_head, ptable_mark_default, ptable_size, strcmp, strcpy
 * Вызывают: ptable_parse_mtd_partitions
 * Константы: 0x3002B5B8
 * Данные: DAT_3002c438, DAT_3002c43c, DAT_3002c440, DAT_3002c444, DAT_3002c448, DAT_3002c44c, DAT_3002c450, DAT_3002c454
 * ---------------------------------------------------------------- */
undefined4 ptable_ensure(void)

{
  char *__s2;
  int iVar1;
  size_t __n;
  
  __s2 = (char *)ptable_get_ram_head();
  iVar1 = strcmp(DAT_3002c438,__s2);
  if (iVar1 != 0) {
    printf(DAT_3002c43c);
    printf(DAT_3002c440,__s2);
    printf(DAT_3002c444);
    memset(__s2,0,0x30);
    strcpy(__s2,DAT_3002c438);
    memcpy(__s2 + 0xc,DAT_3002c448,4);
    strcpy(__s2 + 0x10,DAT_3002c44c);
    strcpy(__s2 + 0x20,DAT_3002c450);
    ptable_mark_default();
    __n = ptable_size();
    memcpy(__s2 + 0x30,DAT_3002c454,__n);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * ptable_show @ 0x3002B66C  (примерный размер ~404 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 3
 * Вызывает: printf, ptable_get_ram_head, strcmp
 * Вызывают: FUN_3002cd64, ptable_parse_mtd_partitions
 * Константы: 0x3002B66C
 * Данные: DAT_3002c440, DAT_3002c458, DAT_3002c45c, DAT_3002c460, DAT_3002c464, DAT_3002c468, DAT_3002c46c, DAT_3002c470
 * ---------------------------------------------------------------- */
undefined4 ptable_show(char *param_1)

{
  int iVar1;
  int iVar2;
  char *__s2;
  
  iVar2 = 1;
  if (param_1 == (char *)0x0) {
    param_1 = (char *)ptable_get_ram_head();
  }
  printf(DAT_3002c458,DAT_3002c45c);
  printf(DAT_3002c458,param_1 + 0x10);
  printf(DAT_3002c458,param_1 + 0x20);
  printf(DAT_3002c458,DAT_3002c460);
  printf(DAT_3002c458,DAT_3002c464);
  printf(DAT_3002c458,DAT_3002c468);
  while( true ) {
    __s2 = param_1 + 0x30;
    iVar1 = strcmp(DAT_3002c46c,__s2);
    if (iVar1 == 0) break;
    printf(DAT_3002c470,iVar2);
    printf(DAT_3002c458,DAT_3002c474);
    printf(DAT_3002c440,*(undefined4 *)(param_1 + 0x40));
    printf(DAT_3002c458,DAT_3002c478);
    printf(DAT_3002c440,*(undefined4 *)(param_1 + 0x44));
    printf(DAT_3002c458,DAT_3002c478);
    printf(DAT_3002c440,*(undefined4 *)(param_1 + 0x48));
    printf(DAT_3002c458,DAT_3002c478);
    printf(DAT_3002c440,*(undefined4 *)(param_1 + 0x4c));
    printf(DAT_3002c458,DAT_3002c478);
    printf(DAT_3002c440,*(undefined4 *)(param_1 + 0x50));
    printf(DAT_3002c458,DAT_3002c478);
    printf(DAT_3002c440,*(undefined4 *)(param_1 + 0x58));
    printf(DAT_3002c458,DAT_3002c478);
    printf(DAT_3002c440,*(undefined4 *)(param_1 + 0x5c));
    printf(DAT_3002c458,DAT_3002c478);
    printf(DAT_3002c440,*(undefined4 *)(param_1 + 0x54));
    printf(DAT_3002c458,DAT_3002c478);
    printf(DAT_3002c458,__s2);
    printf(DAT_3002c458,DAT_3002c460);
    iVar2 = iVar2 + 1;
    param_1 = __s2;
  }
  printf(DAT_3002c458,DAT_3002c47c);
  return 0;
}

/* ----------------------------------------------------------------
 * ptable_parse_mtd_partitions @ 0x3002B800  (примерный размер ~392 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 9
 * Вызывает: free, malloc, memset, printf, ptable_ensure, ptable_get_ram_data, ptable_get_ram_head, ptable_show, strcmp
 * Вызывают: nandc_init_mtd_partition
 * Константы: 0x3002B800
 * Данные: DAT_3002c460, DAT_3002c46c, DAT_3002c480, DAT_3002c484
 * ---------------------------------------------------------------- */
undefined4 ptable_parse_mtd_partitions(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *__s;
  
  __s = (undefined4 *)0x0;
  iVar5 = 0;
  iVar4 = 0;
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (int *)0x0)) {
    ptable_ensure();
    uVar1 = ptable_get_ram_head();
    ptable_show(uVar1);
    pcVar2 = (char *)ptable_get_ram_data();
    iVar6 = 0;
    while (iVar3 = strcmp(DAT_3002c46c,pcVar2), iVar3 != 0) {
      iVar6 = iVar6 + (uint)(*(int *)(pcVar2 + 0x18) != 0);
      pcVar2 = pcVar2 + 0x30;
    }
    __s = (undefined4 *)malloc(iVar6 * 0x18);
    if (__s == (undefined4 *)0x0) {
      printf(DAT_3002c480);
    }
    else {
      memset(__s,0,iVar6 * 0x18);
      *param_1 = __s;
      *param_2 = iVar6;
      pcVar2 = (char *)ptable_get_ram_data();
      iVar6 = 0;
      while( true ) {
        iVar3 = strcmp(DAT_3002c46c,pcVar2);
        if (iVar3 == 0) {
          *param_2 = iVar6;
          return 0;
        }
        if ((*(int *)(pcVar2 + 0x10) != iVar5) && (iVar4 != 0)) break;
        if (*(int *)(pcVar2 + 0x18) != 0) {
          *__s = pcVar2;
          __s[3] = *(undefined4 *)(pcVar2 + 0x10);
          __s[2] = *(undefined4 *)(pcVar2 + 0x18);
          __s = __s + 6;
          iVar6 = iVar6 + 1;
        }
        iVar5 = *(int *)(pcVar2 + 0x10) + *(int *)(pcVar2 + 0x18);
        iVar4 = *(int *)(pcVar2 + 0x24);
        pcVar2 = pcVar2 + 0x30;
      }
      printf(DAT_3002c484);
      printf(pcVar2);
      printf(DAT_3002c460);
    }
  }
  if (__s != (undefined4 *)0x0) {
    free(__s);
  }
  return 1;
}

/* ----------------------------------------------------------------
 * ptable_get_validity @ 0x3002B988  (примерный размер ~28 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 0
 * Вызывают: ptable_find_by_type, ptable_find_older_part, ptable_find_theother_by_type
 * Константы: 0x3002B988
 * ---------------------------------------------------------------- */
uint ptable_get_validity(int param_1)

{
  return *(uint *)(param_1 + 0x28) >> 3 & 1;
}

/* ----------------------------------------------------------------
 * ptable_find_by_type @ 0x3002B9A4  (примерный размер ~144 байт)
 * Модуль: flash | Вызывают: 7 | Вызывает: 2
 * Вызывает: ptable_get_validity, strcmp
 * Вызывают: ptable_dload_read, ptable_erase_partition, ptable_get_cdromiso_version, ptable_get_range, ptable_quary_partition, ptable_set_cdromiso_version, secIsSecVer
 * Константы: 0x3002B9A4
 * Данные: DAT_3002c46c
 * ---------------------------------------------------------------- */
char * ptable_find_by_type(int param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = (char *)0x0;
  if (param_2 != (char *)0x0) {
    while (iVar1 = strcmp(DAT_3002c46c,param_2), iVar1 != 0) {
      if (*(int *)(param_2 + 0x24) == param_1) {
        if (pcVar2 == (char *)0x0) {
          iVar1 = ptable_get_validity(param_2);
          if (iVar1 == 0) {
            pcVar2 = param_2;
          }
        }
        else {
          iVar1 = ptable_get_validity(param_2);
          if ((iVar1 == 0) && (*(uint *)(pcVar2 + 0x2c) < *(uint *)(param_2 + 0x2c))) {
            pcVar2 = param_2;
          }
        }
      }
      param_2 = param_2 + 0x30;
    }
  }
  return pcVar2;
}

/* ----------------------------------------------------------------
 * ptable_find_theother_by_type @ 0x3002BA34  (примерный размер ~124 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 3
 * Вызывает: ptable_get_ram_data, ptable_get_validity, strcmp
 * Константы: 0x3002BA34
 * Данные: DAT_3002c46c
 * ---------------------------------------------------------------- */
char * ptable_find_theother_by_type(int param_1,char *param_2)

{
  char *__s2;
  int iVar1;
  char *pcVar2;
  
  __s2 = (char *)ptable_get_ram_data();
  pcVar2 = (char *)0x0;
  if (param_2 != (char *)0x0) {
    while ((iVar1 = strcmp(DAT_3002c46c,__s2), pcVar2 = (char *)0x0, iVar1 != 0 &&
           (((*(int *)(__s2 + 0x24) != param_1 || (param_2 == __s2)) ||
            (iVar1 = ptable_get_validity(__s2), pcVar2 = __s2, iVar1 != 0))))) {
      __s2 = __s2 + 0x30;
    }
  }
  return pcVar2;
}

/* ----------------------------------------------------------------
 * ptable_set_validity @ 0x3002BAB0  (примерный размер ~60 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: ptable_find_older_part
 * Константы: 0xFFFFFFF7, 0x3002BAB0
 * ---------------------------------------------------------------- */
void ptable_set_validity(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffff7 | 8;
  }
  else {
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffff7;
  }
  return;
}

/* ----------------------------------------------------------------
 * ptable_check_integrality @ 0x3002BAEC  (примерный размер ~36 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: ptable_get_ram_head
 * Константы: 0x3002BAEC
 * ---------------------------------------------------------------- */
bool ptable_check_integrality(void)

{
  int iVar1;
  
  iVar1 = ptable_get_ram_head();
  return (*(uint *)(iVar1 + 0xc) & 1) == 0;
}

