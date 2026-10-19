/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : lib — libc/математика/криптография/компрессия (AES, zlib-подобный QC_*)
 * Часть  : 3 (функций: 98, адреса 0x300BEB8C..0x3011DEC0)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * FUN_300beb8c @ 0x300BEB8C  (примерный размер ~48 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: __div32, __rem32
 * Константы: 0x300BEB8C
 * ---------------------------------------------------------------- */
int FUN_300beb8c(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = __rem32((param_2 - param_1) + 7,7);
  iVar1 = __div32((param_3 - iVar1) + 0xc,7);
  return iVar1 + -1;
}

/* ----------------------------------------------------------------
 * __getZoneInfo @ 0x300BEBBC  (примерный размер ~288 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 4
 * Вызывает: getenv, memcmp, strcpy, strpbrk
 * Вызывают: FUN_300becdc, localtime_r, mktime
 * Константы: 0x300BEBBC
 * Данные: DAT_300bee90, DAT_300bee94, DAT_300bee98
 * ---------------------------------------------------------------- */
void __getZoneInfo(char *param_1,int param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar1 = getenv(DAT_300bee90);
  if ((pcVar1 == (char *)0x0) || (iVar2 = memcmp(pcVar1,DAT_300bee94,1), iVar2 == 0)) {
    pcVar1 = *(char **)(param_3 + param_2 * 4 + 0xac);
    iVar2 = memcmp(pcVar1,DAT_300bee94,1);
    if (iVar2 == 0) {
      *param_1 = '\0';
    }
    else {
      strcpy(param_1,pcVar1);
    }
    return;
  }
  pcVar3 = strpbrk(pcVar1,DAT_300bee98);
  if (param_2 == 0) {
    strcpy(param_1,pcVar1);
    param_1[(int)pcVar3 - (int)pcVar1] = '\0';
    return;
  }
  pcVar3 = pcVar3 + 1;
  pcVar1 = strpbrk(pcVar3,DAT_300bee98);
  if (param_2 == 1) {
    strcpy(param_1,pcVar3);
  }
  else {
    pcVar3 = pcVar1 + 1;
    pcVar1 = strpbrk(pcVar3,DAT_300bee98);
    if (param_2 != 2) {
      return;
    }
    strcpy(param_1,pcVar3);
    if (pcVar1 == (char *)0x0) {
      return;
    }
  }
  param_1[(int)pcVar1 - (int)pcVar3] = '\0';
  return;
}

/* ----------------------------------------------------------------
 * FUN_300becdc @ 0x300BECDC  (примерный размер ~172 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: __getZoneInfo, strcpy, strlen
 * Константы: 0x300BECDC
 * ---------------------------------------------------------------- */
void FUN_300becdc(char *param_1,int param_2,int param_3,int param_4,size_t *param_5)

{
  size_t sVar1;
  char *__s;
  char acStack_30 [28];
  
  __s = (char *)0x0;
  if (param_2 == 2) {
    __s = *(char **)(param_4 + 0xa0);
  }
  else if (param_2 < 3) {
    if (param_2 == 0) {
      __s = *(char **)(param_4 + 0x98);
    }
    else if (param_2 == 1) {
      __s = *(char **)(param_4 + 0x9c);
    }
  }
  else if (param_2 == 3) {
    __s = *(char **)(param_4 + (uint)(0xb < *(int *)(param_3 + 8)) * 4 + 0xa4);
  }
  else if (param_2 == 4) {
    __getZoneInfo(acStack_30,0,param_4);
    __s = acStack_30;
  }
  sVar1 = strlen(__s);
  *param_5 = sVar1;
  strcpy(param_1,__s);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300bed88 @ 0x300BED88  (примерный размер ~88 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: __div32, __rem32
 * Константы: 0x300BED88
 * ---------------------------------------------------------------- */
void FUN_300bed88(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = 0;
  if (-1 < param_2) {
    iVar2 = param_2;
  }
  pcVar3 = (char *)(param_1 + param_3);
  while (param_3 = param_3 + -1, -1 < param_3) {
    cVar1 = __rem32(iVar2,10);
    pcVar3 = pcVar3 + -1;
    *pcVar3 = cVar1 + '0';
    iVar2 = __div32(iVar2,10);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300bede0 @ 0x300BEDE0  (примерный размер ~60 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: strcpy, strlen
 * Константы: 0x300BEDE0
 * ---------------------------------------------------------------- */
void FUN_300bede0(char *param_1,int param_2,int param_3,int param_4,size_t *param_5)

{
  size_t sVar1;
  int iVar2;
  char *__s;
  
  iVar2 = 7;
  if (param_3 == 1) {
    iVar2 = 0;
  }
  __s = *(char **)(param_4 + (param_2 + iVar2) * 4);
  sVar1 = strlen(__s);
  *param_5 = sVar1;
  strcpy(param_1,__s);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300bee1c @ 0x300BEE1C  (примерный размер ~64 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: strcpy, strlen
 * Константы: 0x300BEE1C
 * ---------------------------------------------------------------- */
void FUN_300bee1c(char *param_1,int param_2,int param_3,int param_4,size_t *param_5)

{
  size_t sVar1;
  int iVar2;
  char *__s;
  
  iVar2 = 0xc;
  if (param_3 == 1) {
    iVar2 = 0;
  }
  __s = *(char **)(param_4 + (param_2 + iVar2) * 4 + 0x38);
  sVar1 = strlen(__s);
  *param_5 = sVar1;
  strcpy(param_1,__s);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300bee5c @ 0x300BEE5C  (примерный размер ~960 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_300bf21c
 * Константы: 0x300BEE5C, 0x300BEE8C
 * Данные: DAT_300bee9c
 * ---------------------------------------------------------------- */
void FUN_300bee5c(void)

{
  undefined4 *in_r3;
  byte *in_stack_00000000;
  
  if (*in_stack_00000000 - 0x25 < 0x55) {
                    /* WARNING: Could not recover jumptable at 0x300bee8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_300bee9c + (*in_stack_00000000 - 0x25) * 4))();
    return;
  }
  *in_r3 = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300bf21c @ 0x300BF21C  (примерный размер ~296 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_300bee5c, abs, memcpy
 * Вызывают: strftime
 * Константы: 0x300BF21C
 * ---------------------------------------------------------------- */
uint FUN_300bf21c(char *param_1,uint param_2,char *param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  size_t local_3c;
  undefined1 auStack_38 [28];
  
  uVar2 = 0;
  local_3c = 0;
LAB_300bf268:
  do {
    for (; *param_3 != '%'; param_3 = param_3 + 1) {
      if (uVar2 == param_2) goto LAB_300bf330;
      if (*param_3 == '\0') break;
      uVar2 = uVar2 + 1;
      *param_1 = *param_3;
      param_1 = param_1 + 1;
    }
    if ((uVar2 == param_2) || (*param_3 == '\0')) goto LAB_300bf330;
    FUN_300bee5c(auStack_38,param_4,param_5,&local_3c,param_3 + 1);
    if (-1 < (int)local_3c) break;
    iVar1 = abs(local_3c);
    auStack_38[iVar1] = 0;
    local_3c = FUN_300bf21c(param_1,param_2 - uVar2,auStack_38,param_4,param_5);
    param_1 = param_1 + local_3c;
    uVar2 = uVar2 + local_3c;
    param_3 = param_3 + 2;
  } while( true );
  if (param_2 <= uVar2 + local_3c) {
    memcpy(param_1,auStack_38,param_2 - uVar2);
    param_1 = param_1 + (param_2 - uVar2);
    uVar2 = param_2;
LAB_300bf330:
    *param_1 = '\0';
    return uVar2;
  }
  memcpy(param_1,auStack_38,local_3c);
  param_3 = param_3 + 2;
  uVar2 = uVar2 + local_3c;
  param_1 = param_1 + local_3c;
  goto LAB_300bf268;
}

/* ----------------------------------------------------------------
 * strftime @ 0x300BF344  (примерный размер ~32 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300bf21c
 * Вызывают: asctime_r
 * Константы: 0x300BF344
 * ---------------------------------------------------------------- */
size_t strftime(char *__s,size_t __maxsize,char *__format,tm *__tp)

{
  size_t sVar1;
  
  sVar1 = FUN_300bf21c();
  return sVar1;
}

/* ----------------------------------------------------------------
 * __getDstInfo @ 0x300BF364  (примерный размер ~708 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 7
 * Вызывает: atoi, bzero, getenv, memcmp, strcpy, strncpy, strtok_r
 * Вызывают: localtime_r, mktime
 * Константы: 0x300BF364
 * Данные: DAT_300bf61c, DAT_300bf620, DAT_300bf624
 * ---------------------------------------------------------------- */
undefined4 __getDstInfo(int param_1,int param_2)

{
  char *pcVar1;
  char *__src;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  char acStack_44 [4];
  char *local_40;
  char acStack_3c [28];
  
  local_40 = DAT_300bf61c;
  pcVar1 = getenv(DAT_300bf620);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = *(char **)(param_2 + 0xb8);
    __src = *(char **)(param_2 + 0xbc);
    iVar4 = memcmp(pcVar1,DAT_300bf61c,1);
    bVar10 = iVar4 == 0;
    if (!bVar10) {
      iVar4 = memcmp(__src,DAT_300bf61c,1);
      bVar10 = iVar4 == 0;
    }
    if (bVar10) {
      return 0;
    }
  }
  else {
    strcpy(acStack_3c,pcVar1);
    strtok_r(acStack_3c,DAT_300bf624,&local_40);
    strtok_r((char *)0x0,DAT_300bf624,&local_40);
    pcVar1 = strtok_r((char *)0x0,DAT_300bf624,&local_40);
    __src = strtok_r((char *)0x0,DAT_300bf624,&local_40);
  }
  if (pcVar1 == (char *)0x0 || __src == (char *)0x0) {
    uVar2 = 0;
  }
  else {
    bzero(acStack_44,4);
    pcVar3 = strncpy(acStack_44,pcVar1,2);
    iVar4 = atoi(pcVar3);
    iVar4 = iVar4 + -1;
    bzero(acStack_44,4);
    pcVar3 = strncpy(acStack_44,__src,2);
    iVar5 = atoi(pcVar3);
    iVar9 = *(int *)(param_1 + 0x10);
    iVar5 = iVar5 + -1;
    if ((iVar9 < iVar4) || (iVar5 < iVar9)) {
      uVar2 = 0;
    }
    else {
      if ((iVar9 == iVar4) || (iVar9 == iVar5)) {
        bzero(acStack_44,4);
        pcVar3 = strncpy(acStack_44,pcVar1 + 2,2);
        iVar9 = atoi(pcVar3);
        bzero(acStack_44,4);
        pcVar3 = strncpy(acStack_44,__src + 2,2);
        iVar6 = atoi(pcVar3);
        iVar7 = *(int *)(param_1 + 0x10);
        if (((iVar7 == iVar4) && (*(int *)(param_1 + 0xc) < iVar9)) ||
           ((iVar7 == iVar5 && (iVar6 < *(int *)(param_1 + 0xc))))) {
          return 0;
        }
        if (((iVar7 == iVar4) && (*(int *)(param_1 + 0xc) == iVar9)) ||
           ((iVar7 == iVar5 && (*(int *)(param_1 + 0xc) == iVar6)))) {
          bzero(acStack_44,4);
          pcVar1 = strncpy(acStack_44,pcVar1 + 4,2);
          iVar7 = atoi(pcVar1);
          bzero(acStack_44,4);
          pcVar1 = strncpy(acStack_44,__src + 4,2);
          iVar8 = atoi(pcVar1);
          if ((((*(int *)(param_1 + 0x10) != iVar4) || (*(int *)(param_1 + 0xc) != iVar9)) ||
              (iVar7 <= *(int *)(param_1 + 8))) &&
             (((*(int *)(param_1 + 0x10) != iVar5 || (*(int *)(param_1 + 0xc) != iVar6)) ||
              (*(int *)(param_1 + 8) + 1 < iVar8)))) {
            return 1;
          }
          return 0;
        }
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * __common_intrinsicsInit @ 0x300BF6A0  (примерный размер ~12 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300BF6A0
 * Данные: DAT_300bf6a8
 * ---------------------------------------------------------------- */
undefined4 __common_intrinsicsInit(void)

{
  return DAT_300bf6a8;
}

/* ----------------------------------------------------------------
 * __POL @ 0x300BF8DC  (примерный размер ~732 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 5
 * Вызывает: __ff1ll, __lsl64, __lsr64, __mul64, sfpDoubleNormalize2
 * Константы: 0x00100000, 0x300BF8DC
 * Данные: DAT_300bfbac, DAT_300bfbb0, DAT_300bfbb4
 * ---------------------------------------------------------------- */
void __POL(uint *param_1,uint param_2,uint param_3,int param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int extraout_r1;
  int extraout_r1_00;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  uint local_64;
  uint local_60;
  uint *local_8;
  int local_4;
  
  uVar11 = DAT_300bfbac & param_3 >> 0x14;
  uVar3 = (param_3 & DAT_300bfbb0 | 0x100000) << 10 | param_2 >> 0x16;
  uVar6 = param_1[1];
  local_60 = uVar6 >> 0x1f;
  local_64 = DAT_300bfbac & uVar6 >> 0x14;
  uVar15 = CONCAT44((uVar6 & DAT_300bfbb0 | 0x100000) << 10 | *param_1 >> 0x16,*param_1 << 10);
  local_8 = param_1;
  local_4 = param_4;
  while( true ) {
    uVar6 = (uint)((ulonglong)uVar15 >> 0x20);
    local_60 = local_60 ^ param_3 >> 0x1f;
    local_64 = (uVar11 + local_64) - DAT_300bfbb4;
    __mul64(uVar6,0,param_2 << 10);
    __mul64(uVar3,0,(int)uVar15);
    uVar1 = (ulonglong)uVar6 * (ulonglong)uVar3 + (ulonglong)(uint)(extraout_r1 + extraout_r1_00);
    if ((uVar1 & 0x2000000000000000) == 0) {
      local_64 = local_64 - 1;
      uVar1 = CONCAT44((int)(uVar1 >> 0x20) * 2 | (uint)uVar1 >> 0x1f,(uint)uVar1 * 2);
    }
    uVar7 = local_8[3];
    uVar6 = local_8[2];
    uVar10 = DAT_300bfbac & uVar7 >> 0x14;
    iVar12 = local_64 - uVar10;
    uVar8 = uVar7 & DAT_300bfbb0 | 0x100000;
    uVar14 = CONCAT44(uVar7 & DAT_300bfbb0,uVar6) | 0x10000000000000;
    if (iVar12 < 0) {
      uVar14 = CONCAT44(uVar8 << 9 | uVar6 >> 0x17,uVar6 << 9);
      uVar1 = __lsr64((int)uVar1,(int)(uVar1 >> 0x20),-iVar12);
      local_64 = uVar10;
    }
    else if (iVar12 < 9) {
      uVar14 = __lsl64(uVar6,uVar8,9 - iVar12);
    }
    else if (9 < iVar12) {
      uVar14 = __lsr64(uVar6,uVar8,iVar12 + -9);
    }
    uVar9 = (uint)(uVar14 >> 0x20);
    uVar10 = (uint)uVar14;
    uVar8 = (uint)(uVar1 >> 0x20);
    uVar6 = (uint)uVar1;
    if (local_60 == uVar7 >> 0x1f) {
      lVar2 = uVar1 + uVar14;
    }
    else {
      bVar13 = uVar9 <= uVar8;
      if (uVar8 == uVar9) {
        bVar13 = uVar10 <= uVar6;
      }
      if (bVar13 && uVar1 != uVar14) {
        lVar2 = CONCAT44(uVar8 - (uVar9 + (uVar6 < uVar10)),uVar6 - uVar10);
      }
      else {
        local_60 = local_60 ^ 1;
        lVar2 = CONCAT44(uVar9 - (uVar8 + (uVar10 < uVar6)),uVar10 - uVar6);
      }
    }
    uVar5 = (undefined4)((ulonglong)lVar2 >> 0x20);
    uVar4 = (undefined4)lVar2;
    local_4 = local_4 + -1;
    if (local_4 == 0) break;
    iVar12 = __ff1ll(uVar4,uVar5);
    local_64 = local_64 + (2 - iVar12);
    uVar15 = __lsl64(uVar4,uVar5,iVar12 + -1);
    local_8 = local_8 + 2;
  }
  sfpDoubleNormalize2(local_60,local_64 - 9,uVar4,uVar5);
  return;
}

/* ----------------------------------------------------------------
 * __DIAB_rd_pk_db @ 0x300C0504  (примерный размер ~68 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C0504
 * ---------------------------------------------------------------- */
undefined8 __DIAB_rd_pk_db(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 uStack_19;
  undefined8 local_18;
  
  puVar3 = &uStack_19;
  iVar2 = 4;
  do {
    puVar1 = param_1 + 1;
    iVar2 = iVar2 + -1;
    puVar3[1] = *param_1;
    param_1 = param_1 + 2;
    puVar3 = puVar3 + 2;
    *puVar3 = *puVar1;
  } while (iVar2 != 0);
  return local_18;
}

/* ----------------------------------------------------------------
 * __DIAB_rd_pk_fl @ 0x300C0548  (примерный размер ~56 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C0548
 * ---------------------------------------------------------------- */
undefined4 __DIAB_rd_pk_fl(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 uStack_11;
  undefined4 local_10;
  
  puVar3 = &uStack_11;
  iVar2 = 2;
  do {
    puVar1 = param_1 + 1;
    iVar2 = iVar2 + -1;
    puVar3[1] = *param_1;
    param_1 = param_1 + 2;
    puVar3 = puVar3 + 2;
    *puVar3 = *puVar1;
  } while (iVar2 != 0);
  return local_10;
}

/* ----------------------------------------------------------------
 * __DIAB_rd_pk_ld @ 0x300C0580  (примерный размер ~68 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C0580
 * ---------------------------------------------------------------- */
void __DIAB_rd_pk_ld(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 uStack_11;
  undefined1 local_10 [16];
  
  puVar3 = &uStack_11;
  iVar2 = 4;
  do {
    puVar1 = param_1 + 1;
    iVar2 = iVar2 + -1;
    puVar3[1] = *param_1;
    param_1 = param_1 + 2;
    puVar3 = puVar3 + 2;
    *puVar3 = *puVar1;
  } while (iVar2 != 0);
  return;
}

/* ----------------------------------------------------------------
 * __DIAB_rd_sw_db @ 0x300C05C4  (примерный размер ~72 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C05C4
 * ---------------------------------------------------------------- */
undefined8 __DIAB_rd_sw_db(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined8 local_18;
  undefined1 auStack_10 [8];
  
  puVar3 = auStack_10;
  iVar2 = 7;
  do {
    puVar1 = param_1 + 1;
    iVar2 = iVar2 + -2;
    puVar3[-1] = *param_1;
    puVar3 = puVar3 + -2;
    param_1 = param_1 + 2;
    *puVar3 = *puVar1;
  } while (-1 < iVar2);
  return local_18;
}

/* ----------------------------------------------------------------
 * __DIAB_rd_sw_fl @ 0x300C060C  (примерный размер ~60 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C060C
 * ---------------------------------------------------------------- */
undefined4 __DIAB_rd_sw_fl(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 local_10;
  undefined1 auStack_c [12];
  
  puVar3 = auStack_c;
  iVar2 = 3;
  do {
    puVar1 = param_1 + 1;
    iVar2 = iVar2 + -2;
    puVar3[-1] = *param_1;
    puVar3 = puVar3 + -2;
    param_1 = param_1 + 2;
    *puVar3 = *puVar1;
  } while (-1 < iVar2);
  return local_10;
}

/* ----------------------------------------------------------------
 * __DIAB_rd_sw_ld @ 0x300C0648  (примерный размер ~72 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C0648
 * ---------------------------------------------------------------- */
void __DIAB_rd_sw_ld(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 auStack_a [10];
  
  puVar3 = auStack_a + 2;
  iVar2 = 7;
  do {
    puVar1 = param_1 + 1;
    iVar2 = iVar2 + -2;
    puVar3[-1] = *param_1;
    puVar3 = puVar3 + -2;
    param_1 = param_1 + 2;
    *puVar3 = *puVar1;
  } while (-1 < iVar2);
  return;
}

/* ----------------------------------------------------------------
 * __DIAB_wr_pk_db @ 0x300C0690  (примерный размер ~76 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C0690
 * ---------------------------------------------------------------- */
void __DIAB_wr_pk_db(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 uStack_19;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = param_1;
  local_14 = param_2;
  puVar2 = &uStack_19;
  iVar1 = 4;
  do {
    iVar1 = iVar1 + -1;
    *param_3 = puVar2[1];
    puVar2 = puVar2 + 2;
    param_3[1] = *puVar2;
    param_3 = param_3 + 2;
  } while (iVar1 != 0);
  return;
}

/* ----------------------------------------------------------------
 * __DIAB_wr_pk_fl @ 0x300C06DC  (примерный размер ~64 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C06DC
 * ---------------------------------------------------------------- */
void __DIAB_wr_pk_fl(undefined4 param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 uStack_11;
  undefined4 local_10;
  
  local_10 = param_1;
  puVar1 = &uStack_11;
  iVar2 = 2;
  do {
    iVar2 = iVar2 + -1;
    *param_2 = puVar1[1];
    puVar1 = puVar1 + 2;
    param_2[1] = *puVar1;
    param_2 = param_2 + 2;
  } while (iVar2 != 0);
  return;
}

/* ----------------------------------------------------------------
 * __DIAB_wr_pk_ld @ 0x300C071C  (примерный размер ~108 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C071C
 * ---------------------------------------------------------------- */
void __DIAB_wr_pk_ld(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 uStack_1d;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_18 = param_2;
  puVar2 = &uStack_1d;
  iVar1 = 4;
  do {
    iVar1 = iVar1 + -1;
    *param_3 = puVar2[1];
    puVar2 = puVar2 + 2;
    param_3[1] = *puVar2;
    param_3 = param_3 + 2;
  } while (iVar1 != 0);
  return;
}

/* ----------------------------------------------------------------
 * __DIAB_wr_sw_db @ 0x300C0788  (примерный размер ~80 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C0788
 * ---------------------------------------------------------------- */
void __DIAB_wr_sw_db(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 auStack_12 [10];
  
  puVar2 = auStack_12 + 2;
  iVar1 = 7;
  do {
    iVar1 = iVar1 + -2;
    *param_3 = puVar2[-1];
    puVar2 = puVar2 + -2;
    param_3[1] = *puVar2;
    param_3 = param_3 + 2;
  } while (-1 < iVar1);
  return;
}

/* ----------------------------------------------------------------
 * __DIAB_wr_sw_fl @ 0x300C07D8  (примерный размер ~68 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C07D8
 * ---------------------------------------------------------------- */
void __DIAB_wr_sw_fl(undefined4 param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 auStack_e [14];
  
  puVar1 = auStack_e + 2;
  iVar2 = 3;
  do {
    iVar2 = iVar2 + -2;
    *param_2 = puVar1[-1];
    puVar1 = puVar1 + -2;
    param_2[1] = *puVar1;
    param_2 = param_2 + 2;
  } while (-1 < iVar2);
  return;
}

/* ----------------------------------------------------------------
 * __DIAB_wr_sw_ld @ 0x300C081C  (примерный размер ~112 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C081C
 * ---------------------------------------------------------------- */
void __DIAB_wr_sw_ld(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 auStack_16 [10];
  
  puVar2 = auStack_16 + 2;
  iVar1 = 7;
  do {
    iVar1 = iVar1 + -2;
    *param_3 = puVar2[-1];
    puVar2 = puVar2 + -2;
    param_3[1] = *puVar2;
    param_3 = param_3 + 2;
  } while (-1 < iVar1);
  return;
}

/* ----------------------------------------------------------------
 * __diab_intrinsics_impfpInit @ 0x300C088C  (примерный размер ~12 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C088C
 * Данные: DAT_300c0894
 * ---------------------------------------------------------------- */
undefined4 __diab_intrinsics_impfpInit(void)

{
  return DAT_300c0894;
}

/* ----------------------------------------------------------------
 * FUN_300c0898 @ 0x300C0898  (примерный размер ~244 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: __rem32, __urem32
 * Константы: 0xFF000000, 0xFFFFFF00, 0x80000000, 0x300C0898, 0xFFFFFFFF
 * Данные: DAT_300c09fc
 * ---------------------------------------------------------------- */
uint FUN_300c0898(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_2 & param_2 - 1) == 0) {
    param_1 = param_1 & param_2 - 1;
  }
  else {
    uVar2 = param_1 | param_2;
    uVar1 = 0xff000000;
    if ((((uVar2 & 0xff000000) == 0) && (uVar1 = DAT_300c09fc, (uVar2 & DAT_300c09fc) == 0)) &&
       (uVar1 = 0xffffff00, (uVar2 & 0xffffff00) == 0)) {
      uVar1 = 0xffffffff;
    }
    iVar3 = 0;
    uVar2 = param_2;
    if ((param_2 & uVar1) == 0) {
      uVar2 = param_2 << 8;
      iVar3 = 8;
      if ((uVar2 & uVar1) == 0) {
        uVar2 = param_2 << 0x10;
        iVar3 = 0x10;
        if ((uVar2 & uVar1) == 0) {
          uVar2 = param_2 << 0x18;
          iVar3 = 0x18;
        }
      }
    }
    if ((param_1 & 0x80000000) == 0) {
      for (; uVar2 <= param_1; uVar2 = uVar2 * 2) {
        iVar3 = iVar3 + 1;
      }
    }
    else {
      for (; (uVar2 & 0x80000000) == 0; uVar2 = uVar2 << 1) {
        iVar3 = iVar3 + 1;
      }
      if (uVar2 <= param_1) {
        param_1 = param_1 - uVar2;
      }
    }
    if (0 < iVar3) {
      do {
        uVar2 = uVar2 >> 1;
        if (uVar2 <= param_1) {
          param_1 = param_1 - uVar2;
        }
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * __rem32 @ 0x300C098C  (примерный размер ~84 байт)
 * Модуль: lib | Вызывают: 13 | Вызывает: 1
 * Вызывает: FUN_300c0898
 * Вызывают: FUN_300be870, FUN_300beb8c, FUN_300bed88, FUN_300c456c, FUN_3012b38c, __getTime, __julday, help, ioHelp, mktime
 *           ...
 * Константы: 0x300C098C, 0x80000000, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
int __rem32(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = param_1 < 0;
  if (bVar2) {
    param_1 = -param_1;
  }
  if (param_2 < 1) {
    if (param_2 == 0) {
      if (bVar2) {
        iVar1 = -0x80000000;
      }
      else {
        iVar1 = 0x7fffffff;
      }
      return iVar1;
    }
    param_2 = -param_2;
  }
  iVar1 = FUN_300c0898(param_1,param_2);
  if (bVar2) {
    iVar1 = -iVar1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * __urem32 @ 0x300C09E0  (примерный размер ~32 байт)
 * Модуль: lib | Вызывают: 26 | Вызывает: 1
 * Вызывает: FUN_300c0898
 * Вызывают: FUN_3004749c, FUN_30051430, FUN_300515b4, FUN_30051c34, FUN_30056524, FUN_300c0dd4, FUN_300c906c, FUN_300cb558, FUN_300d0918, FUN_300d8fc4
 *           ...
 * Константы: 0x300C09E0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 __urem32(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = FUN_300c0898();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300c0a00 @ 0x300C0A00  (примерный размер ~688 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 1
 * Вызывает: __udiv32
 * Вызывают: __div64, __udiv64
 * Константы: 0xFF000000, 0xFFFFFF00, 0x80000000, 0x300C0A00, 0xFFFFFFFF
 * Данные: DAT_300c0dcc, DAT_300c0dd0
 * ---------------------------------------------------------------- */
undefined8 FUN_300c0a00(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  int local_30;
  uint local_8;
  uint local_4;
  
  if ((param_4 & (param_4 - 1) + (uint)(param_3 != 0)) + (param_3 & param_3 - 1) == 0) {
    uVar2 = param_1;
    uVar3 = param_2;
    if (param_3 == 0) {
      uVar3 = 0;
      uVar2 = param_2;
      param_3 = param_4;
    }
    if ((param_3 & DAT_300c0dcc) == 0) {
      param_3 = param_3 >> 0x10;
      uVar2 = uVar2 >> 0x10 | uVar3 << 0x10;
      uVar3 = uVar3 >> 0x10;
    }
    if ((param_3 & 0xff) == 0) {
      param_3 = param_3 >> 8;
      uVar2 = uVar2 >> 8 | uVar3 << 0x18;
      uVar3 = uVar3 >> 8;
    }
    while (param_3 = param_3 >> 1, param_3 != 0) {
      uVar2 = uVar2 >> 1 | uVar3 << 0x1f;
      uVar3 = uVar3 >> 1;
    }
  }
  else {
    uVar2 = param_2 | param_4;
    if (uVar2 == 0) {
      uVar2 = __udiv32(param_1,param_3,param_1,param_2);
      uVar3 = 0;
    }
    else {
      uVar3 = 0xff000000;
      if ((((uVar2 & 0xff000000) == 0) && (uVar3 = DAT_300c0dd0, (uVar2 & DAT_300c0dd0) == 0)) &&
         (uVar3 = 0xffffff00, (uVar2 & 0xffffff00) == 0)) {
        uVar3 = 0xffffffff;
      }
      local_30 = 0;
      uVar2 = param_4 & uVar3;
      while (uVar2 == 0) {
        param_4 = param_4 << 8 | param_3 >> 0x18;
        param_3 = param_3 << 8;
        local_30 = local_30 + 8;
        uVar2 = param_4 & uVar3;
      }
      uVar2 = param_4;
      local_8 = param_1;
      local_4 = param_2;
      if ((param_2 & 0x80000000) == 0) {
        bVar4 = param_2 <= param_4;
        if (param_4 == param_2) {
          bVar4 = param_1 <= param_3;
        }
        if (!bVar4 || param_4 == param_2 && param_3 == param_1) {
          do {
            param_4 = param_4 << 1 | param_3 >> 0x1f;
            local_30 = local_30 + 1;
            param_3 = param_3 * 2;
            bVar4 = param_2 <= param_4;
            if (param_4 == param_2) {
              bVar4 = param_1 <= param_3;
            }
          } while (!bVar4 || param_4 == param_2 && param_3 == param_1);
        }
        uVar2 = 0;
      }
      else {
        while ((uVar2 & 0x80000000) == 0) {
          uVar2 = param_4 << 1;
          param_4 = uVar2 | param_3 >> 0x1f;
          local_30 = local_30 + 1;
          param_3 = param_3 << 1;
        }
        bVar4 = param_4 <= param_2;
        if (param_2 == param_4) {
          bVar4 = param_3 <= param_1;
        }
        uVar2 = 0;
        if (bVar4) {
          local_8 = param_1 - param_3;
          local_4 = param_2 - (param_4 + (param_1 < param_3));
          uVar2 = 1;
        }
      }
      uVar3 = 0;
      for (; local_30 != 0; local_30 = local_30 + -1) {
        uVar1 = param_4 >> 1;
        param_3 = param_3 >> 1 | param_4 << 0x1f;
        bVar4 = uVar1 <= local_4;
        uVar3 = uVar3 << 1 | uVar2 >> 0x1f;
        uVar2 = uVar2 << 1;
        if (local_4 == uVar1) {
          bVar4 = param_3 <= local_8;
        }
        if (bVar4) {
          bVar4 = local_8 < param_3;
          local_8 = local_8 - param_3;
          local_4 = local_4 - (uVar1 + bVar4);
          uVar2 = uVar2 | 1;
        }
        param_4 = uVar1;
      }
    }
  }
  return CONCAT44(uVar3,uVar2);
}

/* ----------------------------------------------------------------
 * __div64 @ 0x300C0CB0  (примерный размер ~216 байт)
 * Модуль: lib | Вызывают: 9 | Вызывает: 1
 * Вызывает: FUN_300c0a00
 * Вызывают: FUN_300ca6d8, FUN_300caba4, FUN_300d3fd4, FUN_300d40c8, FUN_300deef8, dosVDirReaddirPlus, print64, print64Mult, xbdCreatePartitionSz
 * Константы: 0x300C0CB0
 * ---------------------------------------------------------------- */
undefined8 __div64(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  undefined8 uVar3;
  
  bVar1 = false;
  if ((param_2 != 0) && (param_2 < 0)) {
    bVar1 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(param_2 + (uint)bVar1);
    bVar1 = true;
  }
  if (param_4 == 0) {
LAB_300c0d08:
    if (param_4 != 0 || param_3 != 0) goto LAB_300c0d4c;
  }
  else if (0 < param_4) {
    if (0 < param_4) goto LAB_300c0d4c;
    goto LAB_300c0d08;
  }
  if (param_4 + param_3 == 0) {
    if (bVar1) {
      return 0x8000000000000000;
    }
    return 0x7fffffffffffffff;
  }
  bVar2 = param_3 != 0;
  param_3 = -param_3;
  param_4 = -(param_4 + (uint)bVar2);
  bVar1 = (bool)(bVar1 ^ 1);
LAB_300c0d4c:
  uVar3 = FUN_300c0a00(param_1,param_2,param_3,param_4);
  if (bVar1) {
    uVar3 = CONCAT44(-((int)((ulonglong)uVar3 >> 0x20) + (uint)((int)uVar3 != 0)),-(int)uVar3);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * __udiv64 @ 0x300C0D88  (примерный размер ~76 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 1
 * Вызывает: FUN_300c0a00
 * Вызывают: clock_gettime, clock_gettime_wd, clock_nanosleep, clock_settime
 * Константы: 0x300C0D88, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 __udiv64(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_4 + param_3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = FUN_300c0a00(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300c0dd4 @ 0x300C0DD4  (примерный размер ~512 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 1
 * Вызывает: __urem32
 * Вызывают: __rem64, __urem64
 * Константы: 0xFF000000, 0xFFFFFF00, 0x80000000, 0x300C0DD4, 0xFFFFFFFF
 * Данные: DAT_300c10ec
 * ---------------------------------------------------------------- */
undefined8 FUN_300c0dd4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int local_34;
  
  if ((param_4 & (param_4 - 1) + (uint)(param_3 != 0)) + (param_3 & param_3 - 1) == 0) {
    param_1 = param_1 & param_3 - 1;
    param_2 = param_2 & (param_4 - 1) + (uint)(param_3 != 0);
  }
  else {
    uVar2 = param_2 | param_4;
    if (uVar2 == 0) {
      param_1 = __urem32(param_1,param_3);
      param_2 = 0;
    }
    else {
      uVar1 = 0xff000000;
      if ((((uVar2 & 0xff000000) == 0) && (uVar1 = DAT_300c10ec, (uVar2 & DAT_300c10ec) == 0)) &&
         (uVar1 = 0xffffff00, (uVar2 & 0xffffff00) == 0)) {
        uVar1 = 0xffffffff;
      }
      local_34 = 0;
      uVar2 = param_4 & uVar1;
      while (uVar2 == 0) {
        param_4 = param_4 << 8 | param_3 >> 0x18;
        local_34 = local_34 + 8;
        param_3 = param_3 << 8;
        uVar2 = param_4 & uVar1;
      }
      uVar2 = param_4;
      if ((param_2 & 0x80000000) == 0) {
        bVar3 = param_2 <= param_4;
        if (param_4 == param_2) {
          bVar3 = param_1 <= param_3;
        }
        if (!bVar3 || param_4 == param_2 && param_3 == param_1) {
          do {
            param_4 = param_4 << 1 | param_3 >> 0x1f;
            param_3 = param_3 * 2;
            bVar3 = param_2 <= param_4;
            local_34 = local_34 + 1;
            if (param_4 == param_2) {
              bVar3 = param_1 <= param_3;
            }
          } while (!bVar3 || param_4 == param_2 && param_3 == param_1);
        }
      }
      else {
        while ((uVar2 & 0x80000000) == 0) {
          uVar2 = param_4 << 1;
          param_4 = uVar2 | param_3 >> 0x1f;
          local_34 = local_34 + 1;
          param_3 = param_3 << 1;
        }
        bVar3 = param_4 <= param_2;
        if (param_2 == param_4) {
          bVar3 = param_3 <= param_1;
        }
        if (bVar3) {
          bVar3 = param_1 < param_3;
          param_1 = param_1 - param_3;
          param_2 = param_2 - (param_4 + bVar3);
        }
      }
      for (; local_34 != 0; local_34 = local_34 + -1) {
        uVar2 = param_4 >> 1;
        param_3 = param_3 >> 1 | param_4 << 0x1f;
        bVar3 = uVar2 <= param_2;
        if (param_2 == uVar2) {
          bVar3 = param_3 <= param_1;
        }
        if (bVar3) {
          bVar3 = param_1 < param_3;
          param_1 = param_1 - param_3;
          param_2 = param_2 - (uVar2 + bVar3);
        }
        param_4 = uVar2;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}

/* ----------------------------------------------------------------
 * __rem64 @ 0x300C0FD4  (примерный размер ~212 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 1
 * Вызывает: FUN_300c0dd4
 * Вызывают: FUN_300caba4, FUN_300da684, FUN_3010a138, dosVDirReaddirPlus
 * Константы: 0x300C0FD4
 * ---------------------------------------------------------------- */
undefined8 __rem64(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  undefined8 uVar3;
  
  bVar1 = false;
  if ((param_2 != 0) && (param_2 < 0)) {
    bVar1 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(param_2 + (uint)bVar1);
    bVar1 = true;
  }
  if (param_4 == 0) {
LAB_300c102c:
    if (param_4 != 0 || param_3 != 0) goto LAB_300c106c;
  }
  else if (0 < param_4) {
    if (0 < param_4) goto LAB_300c106c;
    goto LAB_300c102c;
  }
  if (param_4 + param_3 == 0) {
    if (bVar1) {
      return 0x8000000000000000;
    }
    return 0x7fffffffffffffff;
  }
  bVar2 = param_3 != 0;
  param_3 = -param_3;
  param_4 = -(param_4 + (uint)bVar2);
LAB_300c106c:
  uVar3 = FUN_300c0dd4(param_1,param_2,param_3,param_4);
  if (bVar1) {
    uVar3 = CONCAT44(-((int)((ulonglong)uVar3 >> 0x20) + (uint)((int)uVar3 != 0)),-(int)uVar3);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * __urem64 @ 0x300C10A8  (примерный размер ~72 байт)
 * Модуль: lib | Вызывают: 5 | Вызывает: 1
 * Вызывает: FUN_300c0dd4
 * Вызывают: FUN_3010a138, clock_gettime, clock_gettime_wd, clock_nanosleep, clock_settime
 * Константы: 0x300C10A8, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 __urem64(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_4 + param_3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = FUN_300c0dd4(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * __mul64 @ 0x300C10F0  (примерный размер ~256 байт)
 * Модуль: lib | Вызывают: 14 | Вызывает: 0
 * Вызывают: FUN_300c5a04, FUN_300d0d4c, FUN_300dc4fc, FUN_301092d0, __POL, clock_nanosleep, clock_settime, omTimerTickGet, partLibCreate, partLibCreateSz
 *           ...
 * Константы: 0x300C10F0
 * ---------------------------------------------------------------- */
undefined8 __mul64(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  uVar1 = param_4 & 0xffff;
  uVar2 = param_3 >> 0x10;
  param_3 = param_3 & 0xffff;
  iVar6 = 0;
  if ((param_2 >> 0x10 != 0) && (param_3 != 0)) {
    iVar6 = param_3 * (param_2 >> 0x10) * 0x10000;
  }
  param_2 = param_2 & 0xffff;
  if (param_2 != 0) {
    if (uVar2 != 0) {
      iVar6 = iVar6 + uVar2 * param_2 * 0x10000;
    }
    if (param_3 != 0) {
      iVar6 = param_2 * param_3 + iVar6;
    }
  }
  uVar3 = param_1 >> 0x10;
  uVar5 = 0;
  uVar4 = 0;
  if (uVar3 != 0) {
    if (uVar1 != 0) {
      iVar6 = iVar6 + uVar1 * uVar3 * 0x10000;
    }
    if (uVar2 != 0) {
      iVar6 = uVar3 * uVar2 + iVar6;
    }
    if (param_3 != 0) {
      uVar5 = param_3 * uVar3 >> 0x10;
      uVar4 = param_3 * uVar3 * 0x10000;
    }
  }
  param_1 = param_1 & 0xffff;
  if (param_1 != 0) {
    if (param_4 >> 0x10 != 0) {
      iVar6 = iVar6 + (param_4 >> 0x10) * param_1 * 0x10000;
    }
    if (uVar1 != 0) {
      iVar6 = param_1 * uVar1 + iVar6;
    }
    if (uVar2 != 0) {
      uVar1 = uVar2 * param_1 * 0x10000;
      bVar7 = CARRY4(uVar4,uVar1);
      uVar4 = uVar4 + uVar1;
      uVar5 = uVar5 + (uVar2 * param_1 >> 0x10) + (uint)bVar7;
    }
    if (param_3 != 0) {
      bVar7 = CARRY4(uVar4,param_3 * param_1);
      uVar4 = uVar4 + param_3 * param_1;
      uVar5 = uVar5 + bVar7;
    }
  }
  return CONCAT44(uVar5 + iVar6,uVar4);
}

/* ----------------------------------------------------------------
 * __lsl64 @ 0x300C11F0  (примерный размер ~92 байт)
 * Модуль: lib | Вызывают: 14 | Вызывает: 0
 * Вызывают: BSP_TRACE, FUN_300d0d4c, FUN_300dc4fc, FUN_300e4ac4, FUN_300e55ec, FUN_3010a138, __POL, sfpDoubleNormalize, sfpDoubleNormalize2, sfpDoubleSetup
 *           ...
 * Константы: 0x300C11F0
 * ---------------------------------------------------------------- */
undefined8 __lsl64(uint param_1,uint param_2,uint param_3)

{
  if ((int)param_3 < 0x20) {
    if (0 < (int)param_3) {
      param_2 = param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff);
      param_1 = param_1 << (param_3 & 0xff);
    }
  }
  else {
    param_2 = param_1 << (param_3 - 0x20 & 0xff);
    param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}

/* ----------------------------------------------------------------
 * __asr64 @ 0x300C124C  (примерный размер ~92 байт)
 * Модуль: lib | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_300d30d8, FUN_300d39e8, FUN_300d40c8, FUN_300d4858, yaffs_AddrToChunk
 * Константы: 0x300C124C
 * ---------------------------------------------------------------- */
undefined8 __asr64(uint param_1,int param_2,uint param_3)

{
  if ((int)param_3 < 0x20) {
    if (0 < (int)param_3) {
      param_1 = param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff);
      param_2 = param_2 >> (param_3 & 0xff);
    }
  }
  else {
    param_1 = param_2 >> (param_3 - 0x20 & 0xff);
    param_2 = param_2 >> 0x1f;
  }
  return CONCAT44(param_2,param_1);
}

/* ----------------------------------------------------------------
 * __lsr64 @ 0x300C12A8  (примерный размер ~92 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 0
 * Вызывают: FUN_3010a138, __POL, sfpDoubleNormalize, sfpDoubleNormalize2
 * Константы: 0x300C12A8
 * ---------------------------------------------------------------- */
undefined8 __lsr64(uint param_1,uint param_2,uint param_3)

{
  if ((int)param_3 < 0x20) {
    if (0 < (int)param_3) {
      param_1 = param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff);
      param_2 = param_2 >> (param_3 & 0xff);
    }
  }
  else {
    param_1 = param_2 >> (param_3 - 0x20 & 0xff);
    param_2 = 0;
  }
  return CONCAT44(param_2,param_1);
}

/* ----------------------------------------------------------------
 * __add64 @ 0x300C1304  (примерный размер ~12 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C1304
 * ---------------------------------------------------------------- */
undefined8 __add64(uint param_1,int param_2,uint param_3,int param_4)

{
  return CONCAT44(param_2 + param_4 + (uint)CARRY4(param_1,param_3),param_1 + param_3);
}

/* ----------------------------------------------------------------
 * __sub64 @ 0x300C1310  (примерный размер ~12 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C1310
 * ---------------------------------------------------------------- */
undefined8 __sub64(uint param_1,int param_2,uint param_3,int param_4)

{
  return CONCAT44(param_2 - (param_4 + (uint)(param_1 < param_3)),param_1 - param_3);
}

/* ----------------------------------------------------------------
 * __eq64 @ 0x300C131C  (примерный размер ~20 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C131C
 * ---------------------------------------------------------------- */
bool __eq64(int param_1,int param_2,int param_3,int param_4)

{
  return param_2 == param_4 && param_1 == param_3;
}

/* ----------------------------------------------------------------
 * __ne64 @ 0x300C1330  (примерный размер ~20 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C1330
 * ---------------------------------------------------------------- */
bool __ne64(int param_1,int param_2,int param_3,int param_4)

{
  return param_2 != param_4 || param_1 != param_3;
}

/* ----------------------------------------------------------------
 * __ge64 @ 0x300C1344  (примерный размер ~108 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C1344
 * ---------------------------------------------------------------- */
bool __ge64(uint param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  if ((param_1 == param_3) && (param_2 == param_4)) {
    bVar1 = true;
  }
  else if (param_4 < param_2) {
    bVar1 = true;
  }
  else if (param_2 == param_4) {
    bVar1 = param_3 < param_1;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

/* ----------------------------------------------------------------
 * __gt64 @ 0x300C13B0  (примерный размер ~100 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C13B0
 * ---------------------------------------------------------------- */
bool __gt64(uint param_1,int param_2,uint param_3,int param_4)

{
  if ((param_1 != param_3) || (param_2 != param_4)) {
    if (param_4 < param_2) {
      return true;
    }
    if (param_2 == param_4) {
      return param_3 < param_1;
    }
  }
  return false;
}

/* ----------------------------------------------------------------
 * __le64 @ 0x300C1414  (примерный размер ~128 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C1414
 * ---------------------------------------------------------------- */
bool __le64(uint param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  if ((param_1 == param_3) && (param_2 == param_4)) {
    bVar1 = true;
  }
  else if (param_2 < param_4) {
    bVar1 = true;
  }
  else if (param_2 == param_4) {
    bVar1 = param_1 < param_3;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

/* ----------------------------------------------------------------
 * __lt64 @ 0x300C1494  (примерный размер ~124 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C1494
 * ---------------------------------------------------------------- */
bool __lt64(uint param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  if ((param_1 == param_3) && (param_2 == param_4)) {
    bVar1 = false;
  }
  else if (param_2 < param_4) {
    bVar1 = true;
  }
  else if (param_2 == param_4) {
    bVar1 = param_1 < param_3;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

/* ----------------------------------------------------------------
 * __uge64 @ 0x300C1510  (примерный размер ~108 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C1510
 * ---------------------------------------------------------------- */
bool __uge64(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  
  if ((param_1 == param_3) && (param_2 == param_4)) {
    bVar1 = true;
  }
  else if (param_4 < param_2) {
    bVar1 = true;
  }
  else if (param_2 == param_4) {
    bVar1 = param_3 < param_1;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

/* ----------------------------------------------------------------
 * __ugt64 @ 0x300C157C  (примерный размер ~100 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C157C
 * ---------------------------------------------------------------- */
bool __ugt64(uint param_1,uint param_2,uint param_3,uint param_4)

{
  if ((param_1 != param_3) || (param_2 != param_4)) {
    if (param_4 < param_2) {
      return true;
    }
    if (param_2 == param_4) {
      return param_3 < param_1;
    }
  }
  return false;
}

/* ----------------------------------------------------------------
 * __ule64 @ 0x300C15E0  (примерный размер ~128 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C15E0
 * ---------------------------------------------------------------- */
bool __ule64(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  
  if ((param_1 == param_3) && (param_2 == param_4)) {
    bVar1 = true;
  }
  else if (param_2 < param_4) {
    bVar1 = true;
  }
  else if (param_2 == param_4) {
    bVar1 = param_1 < param_3;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

/* ----------------------------------------------------------------
 * __ult64 @ 0x300C1660  (примерный размер ~124 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C1660
 * ---------------------------------------------------------------- */
bool __ult64(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  
  if ((param_1 == param_3) && (param_2 == param_4)) {
    bVar1 = false;
  }
  else if (param_2 < param_4) {
    bVar1 = true;
  }
  else if (param_2 == param_4) {
    bVar1 = param_1 < param_3;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

/* ----------------------------------------------------------------
 * div32 @ 0x300C16DC  (примерный размер ~160 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: __div32, __udiv32
 * Константы: 0x300C16DC
 * Данные: DAT_300c17ec
 * ---------------------------------------------------------------- */
uint div32(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_2 & param_2 - 1) == 0) {
    if ((param_2 & DAT_300c17ec) == 0) {
      param_2 = param_2 >> 0x10;
      param_1 = param_1 >> 0x10;
    }
    uVar2 = param_1;
    if ((param_2 & 0xff) == 0) {
      param_2 = param_2 >> 8;
      uVar2 = param_1 >> 8;
    }
    while (param_2 = param_2 >> 1, param_2 != 0) {
      uVar2 = uVar2 >> 1;
    }
  }
  else {
    uVar1 = param_2;
    if (param_2 <= param_1 >> 1) {
      do {
        uVar1 = uVar1 << 1;
      } while (uVar1 <= param_1 >> 1);
    }
    uVar2 = (uint)(uVar1 <= param_1);
    if (uVar1 <= param_1) {
      param_1 = param_1 - uVar1;
    }
    while (uVar1 != param_2) {
      uVar1 = uVar1 >> 1;
      uVar2 = uVar2 * 2;
      if (uVar1 <= param_1) {
        uVar2 = uVar2 + 1;
        param_1 = param_1 - uVar1;
      }
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * __div32 @ 0x300C177C  (примерный размер ~88 байт)
 * Модуль: lib | Вызывают: 47 | Вызывает: 1
 * Вызывает: div32
 * Вызывают: BSP_HKADC_BatVolRead, BSP_HKADC_TemVoltTrans, BSP_USRCLK_Enable, FUN_30019d80, FUN_3001a908, FUN_3001a9e0, FUN_3001d854, FUN_300ad460, FUN_300bce74, FUN_300be7f4
 *           ...
 * Константы: 0x300C177C, 0x7FFFFFFF
 * Данные: DAT_300c17f0
 * ---------------------------------------------------------------- */
int __div32(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = param_1 < 0;
  if (bVar2) {
    param_1 = -param_1;
  }
  if (param_2 < 1) {
    if (param_2 == 0) {
      iVar1 = DAT_300c17f0;
      if (!bVar2) {
        iVar1 = 0x7fffffff;
      }
      return iVar1;
    }
    param_2 = -param_2;
    bVar2 = !bVar2;
  }
  iVar1 = div32(param_1,param_2);
  if (bVar2) {
    iVar1 = -iVar1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * __udiv32 @ 0x300C17D4  (примерный размер ~32 байт)
 * Модуль: lib | Вызывают: 91 | Вызывает: 1
 * Вызывает: div32
 * Вызывают: BSP_DLOAD_GetDloadFlashInfo, BSP_NANDF_Erase_Force, BSP_NANDF_Scan, Blksize_Data_Transfer, FUN_3000a7c8, FUN_3000b38c, FUN_3001465c, FUN_30015718, FUN_30025414, FUN_300517d8
 *           ...
 * Константы: 0x300C17D4
 * ---------------------------------------------------------------- */
void __udiv32(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    div32(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * __mul6432 @ 0x300C17F4  (примерный размер ~152 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C17F4
 * ---------------------------------------------------------------- */
undefined8 __mul6432(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  uVar1 = param_2 >> 0x10;
  iVar4 = 0;
  uVar2 = param_1 >> 0x10;
  param_2 = param_2 & 0xffff;
  uVar3 = 0;
  if (uVar2 != 0) {
    if (uVar1 != 0) {
      iVar4 = uVar1 * uVar2;
    }
    uVar3 = 0;
    if (param_2 != 0) {
      uVar3 = param_2 * uVar2 * 0x10000;
      iVar4 = iVar4 + (param_2 * uVar2 >> 0x10);
    }
  }
  param_1 = param_1 & 0xffff;
  if (param_1 != 0) {
    if (uVar1 != 0) {
      uVar2 = uVar1 * param_1 * 0x10000;
      bVar5 = CARRY4(uVar3,uVar2);
      uVar3 = uVar3 + uVar2;
      iVar4 = iVar4 + (uVar1 * param_1 >> 0x10) + (uint)bVar5;
    }
    if (param_2 != 0) {
      bVar5 = CARRY4(uVar3,param_2 * param_1);
      uVar3 = uVar3 + param_2 * param_1;
      iVar4 = iVar4 + (uint)bVar5;
    }
  }
  return CONCAT44(iVar4,uVar3);
}

/* ----------------------------------------------------------------
 * __ff1l @ 0x300C188C  (примерный размер ~76 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 0
 * Вызывают: __ff1ll, sfpFloatNormalize, sfpFloatSetup
 * Константы: 0x300C188C
 * Данные: DAT_300c1914
 * ---------------------------------------------------------------- */
int __ff1l(uint param_1)

{
  int iVar1;
  
  iVar1 = 0x20;
  if (DAT_300c1914 < param_1) {
    iVar1 = 0x10;
    param_1 = param_1 >> 0x10;
  }
  if (0xff < param_1) {
    iVar1 = iVar1 + -8;
    param_1 = param_1 >> 8;
  }
  if (0xf < param_1) {
    iVar1 = iVar1 + -4;
    param_1 = param_1 >> 4;
  }
  if (3 < param_1) {
    iVar1 = iVar1 + -2;
    param_1 = param_1 >> 2;
  }
  if (1 < param_1) {
    iVar1 = iVar1 + -1;
    param_1 = param_1 >> 1;
  }
  return iVar1 - param_1;
}

/* ----------------------------------------------------------------
 * __ff1 @ 0x300C18D8  (примерный размер ~4 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C18D8
 * Данные: DAT_300c1914
 * ---------------------------------------------------------------- */
int __ff1(uint param_1)

{
  int iVar1;
  
  iVar1 = 0x20;
  if (DAT_300c1914 < param_1) {
    iVar1 = 0x10;
    param_1 = param_1 >> 0x10;
  }
  if (0xff < param_1) {
    iVar1 = iVar1 + -8;
    param_1 = param_1 >> 8;
  }
  if (0xf < param_1) {
    iVar1 = iVar1 + -4;
    param_1 = param_1 >> 4;
  }
  if (3 < param_1) {
    iVar1 = iVar1 + -2;
    param_1 = param_1 >> 2;
  }
  if (1 < param_1) {
    iVar1 = iVar1 + -1;
    param_1 = param_1 >> 1;
  }
  return iVar1 - param_1;
}

/* ----------------------------------------------------------------
 * __ff1ll @ 0x300C18DC  (примерный размер ~60 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 1
 * Вызывает: __ff1l
 * Вызывают: __POL, sfpDoubleNormalize, sfpDoubleNormalize2, sfpDoubleSetup
 * Константы: 0x300C18DC
 * ---------------------------------------------------------------- */
int __ff1ll(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = __ff1l();
    iVar1 = iVar1 + 0x20;
  }
  else {
    iVar1 = __ff1l(param_2);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * __exec_ctors @ 0x300C1918  (примерный размер ~68 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C1918
 * Данные: DAT_300c199c, DAT_300c19a0
 * ---------------------------------------------------------------- */
void __exec_ctors(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_300c19a0;
  for (puVar2 = (undefined4 *)(DAT_300c199c - 4); puVar1 < puVar2; puVar2 = puVar2 + -1) {
    (*(code *)*puVar2)();
  }
  return;
}

/* ----------------------------------------------------------------
 * __exec_dtors @ 0x300C195C  (примерный размер ~80 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C195C
 * Данные: DAT_300c19a4, DAT_300c19a8
 * ---------------------------------------------------------------- */
void __exec_dtors(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_300c19a8;
  for (puVar2 = (undefined4 *)(DAT_300c19a4 + 4); puVar2 < puVar1; puVar2 = puVar2 + 1) {
    (*(code *)*puVar2)();
  }
  return;
}

/* ----------------------------------------------------------------
 * __diab_intrinsics_implInit @ 0x300C19AC  (примерный размер ~12 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C19AC
 * Данные: DAT_300c19b4
 * ---------------------------------------------------------------- */
undefined4 __diab_intrinsics_implInit(void)

{
  return DAT_300c19b4;
}

/* ----------------------------------------------------------------
 * __diab_atomic_enter @ 0x300C19CC  (примерный размер ~24 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: __diab_lock_mutex
 * Константы: 0x300C19CC
 * Данные: DAT_300c19f0
 * ---------------------------------------------------------------- */
undefined4 __diab_atomic_enter(void)

{
  __diab_lock_mutex(*DAT_300c19f0);
  return 0;
}

/* ----------------------------------------------------------------
 * __diab_atomic_restore @ 0x300C19E4  (примерный размер ~16 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: __diab_unlock_mutex
 * Константы: 0x300C19E4
 * Данные: DAT_300c19f0
 * ---------------------------------------------------------------- */
void __diab_atomic_restore(void)

{
  __diab_unlock_mutex(*DAT_300c19f0);
  return;
}

/* ----------------------------------------------------------------
 * __diab_alloc_mutex @ 0x300C19F4  (примерный размер ~16 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: semMCreate
 * Вызывают: _STI__07__diab_atomic_init
 * Константы: 0x300C19F4
 * ---------------------------------------------------------------- */
void __diab_alloc_mutex(void)

{
  semMCreate(5);
  return;
}

/* ----------------------------------------------------------------
 * __diab_free_mutex @ 0x300C1A04  (примерный размер ~4 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30124a88, semLocalIdVerify
 * Константы: 0x300C1A04, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 __diab_free_mutex(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  
  iVar1 = semLocalIdVerify(param_1,0,&uStack_c);
  if (iVar1 == 0) {
    uVar2 = FUN_30124a88(param_1,1,uStack_c);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * __diab_lock_mutex @ 0x300C1A08  (примерный размер ~8 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: semTake
 * Вызывают: __diab_atomic_enter
 * Константы: 0x300C1A08, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void __diab_lock_mutex(undefined4 param_1)

{
  semTake(param_1,0xffffffff);
  return;
}

/* ----------------------------------------------------------------
 * __diab_trylock_mutex @ 0x300C1A10  (примерный размер ~8 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: semTake
 * Константы: 0x300C1A10
 * ---------------------------------------------------------------- */
void __diab_trylock_mutex(undefined4 param_1)

{
  semTake(param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * __diab_unlock_mutex @ 0x300C1A18  (примерный размер ~4 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: semGiveDefer
 * Вызывают: __diab_atomic_restore
 * Константы: 0x300C1A18
 * Данные: DAT_3012560c, DAT_30125610, DAT_30125614
 * ---------------------------------------------------------------- */
void __diab_unlock_mutex(uint param_1)

{
  code *pcVar1;
  
  if ((param_1 & 1) == 0) {
    if (*DAT_3012560c == 1) {
      semGiveDefer(param_1);
      return;
    }
    pcVar1 = *(code **)(DAT_30125610 + (*(byte *)(param_1 + 0x40) & 0xf) * 4);
  }
  else {
    param_1 = param_1 + *DAT_30125614;
    pcVar1 = *(code **)(DAT_30125610 + (*(byte *)(param_1 + 7) & 0xf) * 4);
  }
  (*pcVar1)(param_1);
  return;
}

/* ----------------------------------------------------------------
 * __diab_alloc_semaphore @ 0x300C1A1C  (примерный размер ~16 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: semMCreate
 * Константы: 0x300C1A1C
 * ---------------------------------------------------------------- */
void __diab_alloc_semaphore(void)

{
  semMCreate(5);
  return;
}

/* ----------------------------------------------------------------
 * __diab_free_semaphore @ 0x300C1A2C  (примерный размер ~4 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30124a88, semLocalIdVerify
 * Константы: 0x300C1A2C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 __diab_free_semaphore(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  
  iVar1 = semLocalIdVerify(param_1,0,&uStack_c);
  if (iVar1 == 0) {
    uVar2 = FUN_30124a88(param_1,1,uStack_c);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * __diab_lock_semaphore @ 0x300C1A30  (примерный размер ~8 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: semTake
 * Константы: 0x300C1A30, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void __diab_lock_semaphore(undefined4 param_1)

{
  semTake(param_1,0xffffffff);
  return;
}

/* ----------------------------------------------------------------
 * __diab_trylock_semaphore @ 0x300C1A38  (примерный размер ~8 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: semTake
 * Константы: 0x300C1A38
 * ---------------------------------------------------------------- */
void __diab_trylock_semaphore(undefined4 param_1)

{
  semTake(param_1,0);
  return;
}

/* ----------------------------------------------------------------
 * __diab_unlock_semaphore @ 0x300C1A40  (примерный размер ~4 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: semGiveDefer
 * Константы: 0x300C1A40
 * Данные: DAT_3012560c, DAT_30125610, DAT_30125614
 * ---------------------------------------------------------------- */
void __diab_unlock_semaphore(uint param_1)

{
  code *pcVar1;
  
  if ((param_1 & 1) == 0) {
    if (*DAT_3012560c == 1) {
      semGiveDefer(param_1);
      return;
    }
    pcVar1 = *(code **)(DAT_30125610 + (*(byte *)(param_1 + 0x40) & 0xf) * 4);
  }
  else {
    param_1 = param_1 + *DAT_30125614;
    pcVar1 = *(code **)(DAT_30125610 + (*(byte *)(param_1 + 7) & 0xf) * 4);
  }
  (*pcVar1)(param_1);
  return;
}

/* ----------------------------------------------------------------
 * __common_long_jmp @ 0x300C1A44  (примерный размер ~4 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C1A44
 * ---------------------------------------------------------------- */
void __common_long_jmp(void)

{
  return;
}

/* ----------------------------------------------------------------
 * __diab_intrinsics_tornInit @ 0x300C1A48  (примерный размер ~12 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300C1A48
 * Данные: DAT_300c1a50
 * ---------------------------------------------------------------- */
undefined4 __diab_intrinsics_tornInit(void)

{
  return DAT_300c1a50;
}

/* ----------------------------------------------------------------
 * FUN_300c1a54 @ 0x300C1A54  (примерный размер ~220 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 4
 * Вызывает: __errno, free, malloc, semMCreate
 * Вызывают: devInit
 * Константы: 0x300C1A54
 * Данные: DAT_300c1ff0
 * ---------------------------------------------------------------- */
undefined2 * FUN_300c1a54(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 *__ptr;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if ((param_1 & 0xffff) == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 0x16;
    return (undefined2 *)0x0;
  }
  __ptr = (undefined2 *)malloc((param_1 & 0xffff) * 0x10 + 0xc);
  if (__ptr == (undefined2 *)0x0) {
    return (undefined2 *)0x0;
  }
  iVar4 = semMCreate(9);
  *(int *)(__ptr + 4) = iVar4;
  iVar2 = DAT_300c1ff0;
  if (iVar4 == 0) {
    free(__ptr);
    return (undefined2 *)0x0;
  }
  uVar5 = 0;
  uVar6 = param_1 + DAT_300c1ff0;
  uVar1 = uVar6 & 0xffff;
  *__ptr = (short)param_1;
  __ptr[1] = 0;
  __ptr[2] = (short)uVar6;
  do {
    __ptr[uVar5 * 8 + 6] = 1;
    *(undefined4 *)(__ptr + uVar5 * 8 + 8) = 0;
    *(undefined4 *)(__ptr + uVar5 * 8 + 0xc) = 0;
    __ptr[uVar5 * 8 + 7] = (short)(uVar5 + 1);
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 <= uVar1);
  __ptr[uVar1 * 8 + 7] = (short)iVar2;
  return __ptr;
}

/* ----------------------------------------------------------------
 * FUN_300c1b30 @ 0x300C1B30  (примерный размер ~140 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: devAttach
 * Константы: 0x300C1B30
 * Данные: DAT_300c1ff0
 * ---------------------------------------------------------------- */
undefined4 FUN_300c1b30(int param_1,int param_2,undefined4 *param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar4 = DAT_300c1ff0;
  if (param_1 == 0) {
    uVar5 = 0x16;
  }
  else if (param_2 == 0) {
    uVar5 = 0x16;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 2);
    if (uVar1 == DAT_300c1ff0) {
      uVar5 = 0xc;
    }
    else {
      iVar6 = param_1 + (uint)uVar1 * 0x10;
      uVar2 = *(ushort *)(iVar6 + 0xe);
      *(ushort *)(param_1 + 2) = uVar2;
      uVar3 = (undefined2)DAT_300c1ff0;
      if (uVar2 == uVar4) {
        *(undefined2 *)(param_1 + 4) = uVar3;
      }
      *(int *)(iVar6 + 0x10) = param_2;
      *(undefined4 *)(iVar6 + 0x18) = 0;
      *(undefined2 *)(iVar6 + 0xe) = uVar3;
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = CONCAT22(uVar1,*(undefined2 *)(iVar6 + 0xc));
      }
      uVar5 = 0;
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * FUN_300c1bbc @ 0x300C1BBC  (примерный размер ~96 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300c1c1c, FUN_300c1d44
 * Константы: 0x300C1BBC
 * Данные: DAT_300c1ff0
 * ---------------------------------------------------------------- */
void FUN_300c1bbc(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = param_1 + param_2 * 0x10;
  puVar2 = *(undefined4 **)(iVar3 + 0x14);
  *(short *)(iVar3 + 0xc) = *(short *)(iVar3 + 0xc) + 1;
  uVar1 = (undefined2)param_2;
  if (*(ushort *)(param_1 + 4) == DAT_300c1ff0) {
    *(undefined2 *)(param_1 + 4) = uVar1;
    *(undefined2 *)(param_1 + 2) = uVar1;
  }
  else {
    *(undefined2 *)(param_1 + (uint)*(ushort *)(param_1 + 4) * 0x10 + 0xe) = uVar1;
    *(undefined2 *)(param_1 + 4) = uVar1;
  }
  *(short *)(iVar3 + 0xe) = (short)DAT_300c1ff0;
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300c1c1c @ 0x300C1C1C  (примерный размер ~144 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_300c1bbc
 * Вызывают: devDetach, xbdDetach
 * Константы: 0x300C1C1C
 * ---------------------------------------------------------------- */
undefined4 FUN_300c1c1c(ushort *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (((param_1 == (ushort *)0x0) || ((param_2 & 0xffff) == 0)) ||
     ((uint)*param_1 <= param_2 >> 0x10)) {
    uVar1 = 0x16;
  }
  else if ((*(int *)(param_1 + (param_2 >> 0x10) * 8 + 8) == 0) ||
          ((uint)param_1[(param_2 >> 0x10) * 8 + 6] != (param_2 & 0xffff))) {
    uVar1 = 2;
  }
  else {
    param_2 = param_2 >> 0x10;
    *(undefined4 *)(param_1 + param_2 * 8 + 10) = *(undefined4 *)(param_1 + param_2 * 8 + 8);
    (param_1 + param_2 * 8 + 8)[0] = 0;
    (param_1 + param_2 * 8 + 8)[1] = 0;
    if (*(int *)(param_1 + param_2 * 8 + 0xc) == 0) {
      FUN_300c1bbc(param_1,param_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300c1cac @ 0x300C1CAC  (примерный размер ~152 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 1
 * Вызывает: __errno
 * Вызывают: devMap, devMapUnsafe
 * Константы: 0x300C1CAC
 * ---------------------------------------------------------------- */
undefined4 FUN_300c1cac(ushort *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (((param_1 == (ushort *)0x0) || ((param_2 & 0xffff) == 0)) ||
     ((uint)*param_1 <= param_2 >> 0x10)) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x16;
    uVar2 = 0;
  }
  else if ((*(int *)(param_1 + (param_2 >> 0x10) * 8 + 8) == 0) ||
          ((uint)param_1[(param_2 >> 0x10) * 8 + 6] != (param_2 & 0xffff))) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 2;
    uVar2 = 0;
  }
  else {
    param_2 = param_2 >> 0x10;
    *(int *)(param_1 + param_2 * 8 + 0xc) = *(int *)(param_1 + param_2 * 8 + 0xc) + 1;
    uVar2 = *(undefined4 *)(param_1 + param_2 * 8 + 8);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_300c1d44 @ 0x300C1D44  (примерный размер ~172 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_300c1bbc
 * Вызывают: devUnmap, devUnmapUnsafe
 * Константы: 0x300C1D44
 * ---------------------------------------------------------------- */
undefined4 FUN_300c1d44(ushort *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 == (uint *)0x0) {
    return 0x16;
  }
  uVar2 = *param_2;
  if (param_1 != (ushort *)0x0) {
    if (((uVar2 & 0xffff) != 0) && (uVar2 >> 0x10 < (uint)*param_1)) {
      uVar1 = uVar2 >> 0x10;
      if ((uint)param_1[uVar1 * 8 + 6] != (uVar2 & 0xffff)) {
        return 2;
      }
      if (*(int *)(param_1 + uVar1 * 8 + 0xc) == 0) {
        return 0xd;
      }
      iVar3 = *(int *)(param_1 + uVar1 * 8 + 0xc);
      *(int *)(param_1 + uVar1 * 8 + 0xc) = iVar3 + -1;
      if ((iVar3 + -1 == 0) && (*(int *)(param_1 + uVar1 * 8 + 8) == 0)) {
        FUN_300c1bbc(param_1,uVar1);
      }
      return 0;
    }
  }
  return 0x16;
}

/* ----------------------------------------------------------------
 * printf @ 0x300C3F44  (примерный размер ~40 байт)
 * Модуль: lib | Вызывают: 350 | Вызывает: 1
 * Вызывает: fioFormatV
 * Вызывают: BSPLogHelp, BSP_AcmDump, BSP_AcmDumpList, BSP_DLOAD_GetDloadFlashInfo, BSP_DLOAD_GetProductId, BSP_DLOAD_Reset, BSP_DLOAD_Show, BSP_Errlog_IFCInit, BSP_HKADC_Test, BSP_LDScript
 *           ...
 * Константы: 0x300C3F44
 * Данные: DAT_300c43e8
 * ---------------------------------------------------------------- */
int printf(char *__format,...)

{
  int iVar1;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = in_r1;
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  iVar1 = fioFormatV(__format,&uStack_c,DAT_300c43e8,1);
  return iVar1;
}

/* ----------------------------------------------------------------
 * snprintf @ 0x300C42A0  (примерный размер ~88 байт)
 * Модуль: lib | Вызывают: 36 | Вызывает: 1
 * Вызывает: fioFormatV
 * Вызывают: DCBInit, FUN_300624c4, FUN_30080798, FUN_30081f50, FUN_300827c0, FUN_300a609c, FUN_300de458, FUN_300e2e10, FUN_300fbe34, FUN_30115d68
 *           ...
 * Константы: 0x300C42A0
 * Данные: DAT_300c4410
 * ---------------------------------------------------------------- */
int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  undefined4 in_r3;
  char *local_24;
  char *local_20;
  undefined4 uStack_4;
  
  local_20 = __s + __maxlen;
  local_24 = __s;
  uStack_4 = in_r3;
  iVar1 = fioFormatV(__format,&uStack_4,DAT_300c4410,&local_24);
  if (__maxlen != 0) {
    *local_24 = '\0';
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * vprintf @ 0x300C5540  (примерный размер ~12 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: fioFormatV
 * Константы: 0x300C5540
 * Данные: DAT_300c5d88
 * ---------------------------------------------------------------- */
int vprintf(char *__format,__gnuc_va_list __arg)

{
  int iVar1;
  
  iVar1 = fioFormatV(__format,__arg,DAT_300c5d88,1);
  return iVar1;
}

/* ----------------------------------------------------------------
 * __errno @ 0x300E2004  (примерный размер ~72 байт)
 * Модуль: lib | Вызывают: 316 | Вызывает: 0
 * Вызывают: FUN_3008b03c, FUN_3008b138, FUN_3008b394, FUN_3008b498, FUN_3008b88c, FUN_300a0cb8, FUN_300a0d4c, FUN_300a0ddc, FUN_300a0ed0, FUN_300a0fbc
 *           ...
 * Константы: 0x300E2004
 * Данные: DAT_300e2108, DAT_300e210c, DAT_300e2110, DAT_300e2114, DAT_300e2118
 * ---------------------------------------------------------------- */
int __errno(void)

{
  if ((*DAT_300e2108 < 1) && (*DAT_300e210c != 0)) {
    if (*DAT_300e2114 != 0) {
      return *DAT_300e210c + 0xd0;
    }
    return DAT_300e2118;
  }
  return DAT_300e2110;
}

/* ----------------------------------------------------------------
 * logFdAdd @ 0x300E312C  (примерный размер ~96 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Вызывают: logFdSet, shellGenericInit, shellInOutSet
 * Константы: 0xFFFFFFFF, 0x300E312C
 * Данные: DAT_300e3698, DAT_300e369c, DAT_300e36a0
 * ---------------------------------------------------------------- */
undefined4 logFdAdd(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = DAT_300e3698;
  semTake(DAT_300e3698,0xffffffff);
  iVar2 = *DAT_300e369c;
  if (5 < iVar2 + 1) {
    semGive(uVar1);
    return 0xffffffff;
  }
  *(undefined4 *)(DAT_300e36a0 + iVar2 * 4) = param_1;
  *DAT_300e369c = iVar2 + 1;
  semGive(uVar1);
  return 0;
}

/* ----------------------------------------------------------------
 * logFdDelete @ 0x300E318C  (примерный размер ~148 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 2
 * Вызывает: semGive, semTake
 * Вызывают: FUN_30111020, logFdSet, shellGenericInit, shellInOutSet
 * Константы: 0xFFFFFFFF, 0x300E318C
 * Данные: DAT_300e3698, DAT_300e369c, DAT_300e36a0
 * ---------------------------------------------------------------- */
undefined4 logFdDelete(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar1 = DAT_300e3698;
  semTake(DAT_300e3698,0xffffffff);
  iVar3 = DAT_300e36a0;
  piVar2 = DAT_300e369c;
  iVar8 = 0;
  iVar5 = *DAT_300e369c;
  iVar7 = 0;
  if (0 < iVar5) {
    piVar4 = (int *)(DAT_300e36a0 + -4);
    do {
      piVar4 = piVar4 + 1;
      iVar6 = *piVar4;
      *(int *)(iVar3 + iVar8 * 4) = iVar6;
      if ((iVar6 == param_1) && (iVar7 == iVar8)) {
        iVar8 = iVar8 + -1;
      }
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar7 < iVar5);
  }
  if (iVar7 == iVar8) {
    semGive(uVar1);
    return 0xffffffff;
  }
  *piVar2 = iVar5 + -1;
  semGive(uVar1);
  return 0;
}

/* ----------------------------------------------------------------
 * logFdSet @ 0x300E3220  (примерный размер ~124 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 4
 * Вызывает: logFdAdd, logFdDelete, semGive, semTake
 * Вызывают: logInit
 * Константы: 0xFFFFFFFF, 0x300E3220
 * Данные: DAT_300e3698, DAT_300e36a4, DAT_300e36a8
 * ---------------------------------------------------------------- */
void logFdSet(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = DAT_300e3698;
  semTake(DAT_300e3698,0xffffffff);
  iVar2 = DAT_300e36a4;
  if (*(int *)(DAT_300e36a4 + 4) != -1) {
    logFdDelete();
  }
  if (*DAT_300e36a8 != -1) {
    logFdDelete();
    *DAT_300e36a8 = -1;
  }
  iVar3 = logFdAdd(param_1);
  if (iVar3 != 0) {
    param_1 = 0xffffffff;
  }
  *(undefined4 *)(iVar2 + 4) = param_1;
  semGive(uVar1);
  return;
}

/* ----------------------------------------------------------------
 * logInit @ 0x300E329C  (примерный размер ~220 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 4
 * Вызывает: logFdSet, msgQCreate, semMInit, taskSpawn
 * Вызывают: usrIosExtraInit
 * Константы: 0xFFFFFFFF, 0x300E329C
 * Данные: DAT_300e3698, DAT_300e36a4, DAT_300e36ac, DAT_300e36b0, DAT_300e36b4, DAT_300e36b8, DAT_300e36bc, DAT_300e36c0
 * ---------------------------------------------------------------- */
undefined4 logInit(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_300e36ac == 0) {
    iVar2 = msgQCreate(param_2,0x20,0);
    *DAT_300e36a4 = iVar2;
    if (iVar2 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      iVar2 = taskSpawn(DAT_300e36c0,*DAT_300e36b4,*DAT_300e36b8,*DAT_300e36bc,DAT_300e36b0,0,0,0,0,
                        0,0,0,0,0,0);
      *DAT_300e36ac = iVar2;
      if (iVar2 == -1) {
        uVar1 = 0xffffffff;
      }
      else {
        semMInit(DAT_300e3698,*DAT_300e36c4);
        logFdSet(param_1);
        uVar1 = 0;
        *DAT_300e36c8 = DAT_300e36cc;
      }
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * logMsg @ 0x300E3378  (примерный размер ~176 байт)
 * Модуль: lib | Вызывают: 132 | Вызывает: 3
 * Вызывает: atomic32Inc, msgQSend, taskIdSelf
 * Вызывают: ABB_ReadData_Ssi, ABB_Read_Ssi, ABB_Write_Ssi, BSP_DLOAD_GetDloadFlashInfo, BSP_DRV_BOOTROM_Init, BSP_Flashless_HwGetVerMain, BSP_GPIO_DrcGet, BSP_GPIO_DrcSet, BSP_GPIO_IntInstall, BSP_GPIO_IntMaskSet
 *           ...
 * Константы: 0xFFFFFFFF, 0x300E3378
 * Данные: DAT_300e36a4, DAT_300e36d0
 * ---------------------------------------------------------------- */
undefined4
logMsg(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
      undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  if (*DAT_300e36d0 < 1) {
    local_40 = taskIdSelf();
    uVar3 = 0xffffffff;
  }
  else {
    local_40 = 0xffffffff;
    uVar3 = 0;
  }
  puVar1 = DAT_300e36a4;
  local_2c = param_5;
  local_28 = param_6;
  local_24 = param_7;
  local_3c = param_1;
  local_38 = param_2;
  local_34 = param_3;
  local_30 = param_4;
  iVar2 = msgQSend(*DAT_300e36a4,&local_40,0x20,uVar3,0);
  if (iVar2 == 0) {
    uVar3 = 0x20;
  }
  else {
    atomic32Inc(puVar1 + 3);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_300e3428 @ 0x300E3428  (примерный размер ~148 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 3
 * Вызывает: fdprintf, semGive, semTake
 * Вызывают: logTask
 * Константы: 0x300E3428, 0xFFFFFFFF
 * Данные: DAT_300e3698, DAT_300e369c, DAT_300e36d4
 * ---------------------------------------------------------------- */
void FUN_300e3428(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  uVar1 = DAT_300e3698;
  semTake(DAT_300e3698,0xffffffff);
  piVar2 = DAT_300e369c;
  iVar4 = 0;
  puVar3 = DAT_300e36d4;
  if (0 < *DAT_300e369c) {
    do {
      fdprintf(puVar3[1],param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar4 < *piVar2);
  }
  semGive(uVar1);
  return;
}

/* ----------------------------------------------------------------
 * logTask @ 0x300E34BC  (примерный размер ~372 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300e3428, msgQReceive, strncpy, taskIdVerify, taskName
 * Константы: 0x300E34BC, 0xFFFFFFFF
 * Данные: DAT_300e36a4, DAT_300e36d8, DAT_300e36dc, DAT_300e36e0, DAT_300e36e4, DAT_300e36e8, DAT_300e36ec
 * ---------------------------------------------------------------- */
void logTask(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  char acStack_38 [31];
  undefined1 local_19;
  
  do {
    puVar1 = DAT_300e36a4;
    local_19 = 0;
    iVar2 = msgQReceive(*DAT_300e36a4,&local_58,0x20,0xffffffff);
    iVar10 = DAT_300e36d8;
    if (iVar2 == 0x20) {
      if (local_58 == -1) {
        pcVar4 = (char *)0x0;
        uVar3 = DAT_300e36dc;
        iVar10 = 0;
      }
      else {
        iVar10 = taskIdVerify(local_58);
        if ((iVar10 == 0) && (pcVar4 = (char *)taskName(local_58), pcVar4 != (char *)0x0)) {
          strncpy(acStack_38,pcVar4,0x1f);
          pcVar4 = acStack_38;
          uVar3 = DAT_300e36e4;
          iVar10 = local_58;
        }
        else {
          pcVar4 = (char *)0x0;
          uVar3 = DAT_300e36e0;
          iVar10 = local_58;
        }
      }
      FUN_300e3428(uVar3,iVar10,pcVar4,0,0,0,0);
      uVar3 = local_50;
      uVar5 = local_4c;
      uVar6 = local_48;
      uVar7 = local_3c;
      uVar8 = local_40;
      uVar9 = local_44;
      iVar10 = DAT_300e36e8;
      iVar2 = local_54;
      if (local_54 == 0) goto LAB_300e35a4;
    }
    else {
LAB_300e35a4:
      uVar3 = 0;
      uVar5 = 0;
      uVar6 = 0;
      uVar7 = 0;
      uVar8 = 0;
      uVar9 = 0;
      iVar2 = iVar10;
    }
    FUN_300e3428(iVar2,uVar3,uVar5,uVar6,uVar9,uVar8,uVar7);
    iVar10 = puVar1[3];
    if (puVar1[2] != iVar10) {
      FUN_300e3428(DAT_300e36ec,iVar10 - puVar1[2],0,0,0,0,0);
      puVar1[2] = iVar10;
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * logShow @ 0x300E3630  (примерный размер ~216 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: printf
 * Константы: 0x300E3630
 * Данные: DAT_300e369c, DAT_300e36d4, DAT_300e36f0, DAT_300e36f4, DAT_300e36f8, DAT_300e36fc, DAT_300e3700, DAT_300e3704
 * ---------------------------------------------------------------- */
void logShow(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  printf(DAT_300e36f0,DAT_300e36f4,DAT_300e36f8);
  printf(DAT_300e36f0,DAT_300e36fc,DAT_300e3700);
  piVar1 = DAT_300e369c;
  iVar3 = 0;
  puVar2 = DAT_300e36d4;
  if (0 < *DAT_300e369c) {
    do {
      printf(DAT_300e3704,iVar3,puVar2[1]);
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < *piVar1);
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * malloc @ 0x300F2B70  (примерный размер ~88 байт)
 * Модуль: lib | Вызывают: 162 | Вызывает: 1
 * Вызывает: FUN_300f2514
 * Вызывают: ABB_ReadCfg, BSP_DLOAD_GetDloadInfo, BSP_IfConfigFromFile, BSP_IpCfgModifyBootLine, BSP_ShowIfCfgFile, BSP_USB_BuildDevProfile, BSP_USB_ValidateDevProfile, CheckHukIsValid, CvInfoReport, FUN_30005d3c
 *           ...
 * Константы: 0x300F2B70
 * Данные: DAT_300f2e70, DAT_300f2ee8
 * ---------------------------------------------------------------- */
void * malloc(size_t __size)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = *DAT_300f2ee8;
  if (*(code **)(iVar2 + 200) == (code *)0x0) {
    pvVar1 = (void *)FUN_300f2514(iVar2,__size,*DAT_300f2e70);
  }
  else {
    pvVar1 = (void *)(**(code **)(iVar2 + 200))(iVar2,*(undefined4 *)(iVar2 + 0xd8),__size);
  }
  return pvVar1;
}

/* ----------------------------------------------------------------
 * calloc @ 0x300F2BC8  (примерный размер ~148 байт)
 * Модуль: lib | Вызывают: 29 | Вызывает: 3
 * Вызывает: __errno, bzero, memPartAlignedAlloc
 * Вызывают: FUN_300a03e0, FUN_300e1714, FUN_300f7744, FUN_300f9a0c, FUN_300fa0b8, FUN_300fdaf4, FUN_301044b0, FUN_3010c4f0, FUN_3012021c, completionPathListGet
 *           ...
 * Константы: 0x300F2BC8
 * Данные: DAT_300f2e70, DAT_300f2ea4, DAT_300f2ea8, DAT_300f2ecc, DAT_300f2ee8
 * ---------------------------------------------------------------- */
void * calloc(size_t __nmemb,size_t __size)

{
  undefined4 *puVar1;
  void *__s;
  size_t __n;
  uint uVar2;
  
  uVar2 = *DAT_300f2ee8;
  __n = __size * __nmemb;
  if ((uVar2 & 1) == 0) {
    __s = (void *)memPartAlignedAlloc(uVar2,__n,*DAT_300f2e70);
  }
  else {
    if ((code *)*DAT_300f2ecc == (code *)0x0) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = DAT_300f2ea4;
      return (void *)0x0;
    }
    __s = (void *)(*(code *)*DAT_300f2ecc)(uVar2 + *DAT_300f2ea8,__n);
  }
  if (__s != (void *)0x0) {
    bzero(__s,__n);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * free @ 0x300F2C5C  (примерный размер ~76 байт)
 * Модуль: lib | Вызывают: 216 | Вызывает: 1
 * Вызывает: FUN_300f2884
 * Вызывают: ABB_ReadCfg, BSP_DLOAD_GetDloadInfo, BSP_IfConfigFromFile, BSP_IpCfgModifyBootLine, BSP_ShowIfCfgFile, BSP_USB_BuildDevProfile, BSP_USB_FreeDevProfile, BSP_USB_ValidateDevProfile, CheckHukIsValid, CvInfoReport
 *           ...
 * Константы: 0x300F2C5C
 * Данные: DAT_300f2ee8
 * ---------------------------------------------------------------- */
void free(void *__ptr)

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
 * realloc @ 0x300F2CA8  (примерный размер ~324 байт)
 * Модуль: lib | Вызывают: 9 | Вызывает: 3
 * Вызывает: FUN_300f2514, FUN_300f2884, bcopy
 * Вызывают: FUN_300bc39c, FUN_300f7094, FUN_30116750, FUN_30116908, FUN_30116b90, FUN_30116f1c, FUN_30117cec, putenv, shellBackgroundRead
 * Константы: 0x300F2CA8
 * Данные: DAT_300f2e70, DAT_300f2ee8, DAT_300f2eec
 * ---------------------------------------------------------------- */
void * realloc(void *__ptr,size_t __size)

{
  void *__dest;
  int iVar1;
  
  if ((code *)*DAT_300f2eec == (code *)0x0) {
    if (__size == 0) {
      iVar1 = *DAT_300f2ee8;
      if (*(code **)(iVar1 + 0xcc) == (code *)0x0) {
        FUN_300f2884(iVar1,__ptr);
      }
      else {
        (**(code **)(iVar1 + 0xcc))(iVar1,*(undefined4 *)(iVar1 + 0xd8),__ptr);
      }
      __dest = (void *)0x0;
    }
    else {
      iVar1 = *DAT_300f2ee8;
      if (*(code **)(iVar1 + 200) == (code *)0x0) {
        __dest = (void *)FUN_300f2514(iVar1,__size,*DAT_300f2e70);
      }
      else {
        __dest = (void *)(**(code **)(iVar1 + 200))(iVar1,*(undefined4 *)(iVar1 + 0xd8),__size);
      }
      if ((__ptr != (void *)0x0) && (__dest != (void *)0x0)) {
        bcopy(__ptr,__dest,__size);
        iVar1 = *DAT_300f2ee8;
        if (*(code **)(iVar1 + 0xcc) == (code *)0x0) {
          FUN_300f2884(iVar1,__ptr);
        }
        else {
          (**(code **)(iVar1 + 0xcc))(iVar1,*(undefined4 *)(iVar1 + 0xd8),__ptr);
        }
      }
    }
  }
  else {
    __dest = (void *)(*(code *)*DAT_300f2eec)(*DAT_300f2ee8,__ptr,__size);
  }
  return __dest;
}

/* ----------------------------------------------------------------
 * logout @ 0x3011D314  (примерный размер ~16 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: shellLogout2
 * Константы: 0x3011D314
 * Данные: DAT_3011d70c
 * ---------------------------------------------------------------- */
void logout(void)

{
  shellLogout2(0,DAT_3011d70c);
  return;
}

/* ----------------------------------------------------------------
 * bzero @ 0x3011DEC0  (примерный размер ~8 байт)
 * Модуль: lib | Вызывают: 90 | Вызывает: 1
 * Вызывает: bfill
 * Вызывают: BSP_OsWait, FUN_300cb558, FUN_300cbe88, FUN_300cc5fc, FUN_300cc684, FUN_300cc7c8, FUN_300cc974, FUN_300ccc2c, FUN_300ccfe8, FUN_300cd078
 *           ...
 * Константы: 0x3011DEC0
 * ---------------------------------------------------------------- */
void bzero(void *__s,size_t __n)

{
  bfill(__s,__n,0);
  return;
}

