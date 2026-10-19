/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 6 (функций: 150, адреса 0x300835A8..0x300A143C)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * dynFSDloadParaChk @ 0x300835A8  (примерный размер ~392 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, memset, omTimerTickGet, snprintf, update_record_file
 * Вызывают: dynFSDloadProcess
 * Константы: 0x300835A8, 0xFFFFFFFF
 * Данные: DAT_30083d2c, DAT_30084418, DAT_3008453c, DAT_30084540, DAT_30084544
 * ---------------------------------------------------------------- */
undefined4 dynFSDloadParaChk(void)

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
  pcVar6 = DAT_30084418;
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
  if ((((*DAT_30083d2c == 0) || (0x98 < *(int *)(*DAT_30083d2c + 4) - 0x65U)) ||
      (*DAT_3008453c < *(uint *)(*DAT_30083d2c + 0x18))) || (*(int *)(*DAT_30083d2c + 0x18) == 0)) {
    OSAL_LogMsg(DAT_30084540,*(undefined4 *)(*DAT_30083d2c + 0x18),
                *(undefined4 *)(*DAT_30083d2c + 4),*DAT_30083d2c,*DAT_3008453c,5,6);
    memset(acStack_108,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_108,0x100,DAT_30084544,uVar3,*(undefined4 *)(*DAT_30083d2c + 0x18),
             *(undefined4 *)(*DAT_30083d2c + 4),*DAT_30083d2c,*DAT_3008453c);
    update_record_file(acStack_108);
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * dynFSGetFileList @ 0x30083730  (примерный размер ~1684 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: OSAL_LogMsg, free, malloc, memcpy, memset, omTimerTickGet, snprintf, update_record_file
 * Вызывают: dynFSDloadProcess
 * Константы: 0xFFFFFFFF, 0x30083730
 * Данные: DAT_30083d2c, DAT_30084668, DAT_3008466c, DAT_30084670, DAT_30084674, DAT_30084678, DAT_300847a8, DAT_300847ac
 * ---------------------------------------------------------------- */
undefined4 dynFSGetFileList(void)

{
  char cVar1;
  char cVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  void *pvVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  undefined1 *__src;
  int iVar10;
  char acStack_124 [256];
  
  pcVar7 = acStack_124;
  iVar10 = 0x80;
  pcVar9 = DAT_30084668;
  do {
    pcVar8 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 2;
    cVar2 = *pcVar8;
    iVar10 = iVar10 + -1;
    pcVar8 = pcVar7 + 1;
    *pcVar7 = cVar1;
    pcVar7 = pcVar7 + 2;
    *pcVar8 = cVar2;
  } while (iVar10 != 0);
  if (*(int *)(*DAT_30083d2c + 0x1c) == 0) {
    memcpy(DAT_3008466c,*(void **)(*DAT_30083d2c + 0x14),0x20);
    if (*DAT_30084670 == 0) {
      OSAL_LogMsg(DAT_30084678,*DAT_30084674,*DAT_30084670,3,4,5,6);
      memset(acStack_124,0x100,0);
      puVar4 = DAT_30084674;
      puVar3 = DAT_30084670;
      uVar5 = omTimerTickGet();
      snprintf(acStack_124,0x100,DAT_300847a8,uVar5,*puVar4,(uint)*puVar3);
      update_record_file(acStack_124);
      return 0xffffffff;
    }
    DAT_300847ac[1] = (uint)*DAT_30084670 * 0x110;
    if (DAT_300847ac[1] + *DAT_300847b0 != *DAT_300847b4) {
      OSAL_LogMsg(DAT_300847b8,DAT_300847ac[1],*DAT_30084670,0x110,4,5,6);
      memset(acStack_124,0x100,0);
      puVar3 = DAT_30084670;
      uVar5 = omTimerTickGet();
      snprintf(acStack_124,0x100,DAT_300848d8,uVar5,DAT_300847ac[1],(uint)*puVar3,0x110);
      update_record_file(acStack_124);
      return 0xffffffff;
    }
    if (*DAT_300847ac != 0) {
      free((void *)*DAT_300847ac);
      *DAT_300847ac = 0;
    }
    pvVar6 = malloc(DAT_300847ac[1]);
    *DAT_300847ac = (int)pvVar6;
    if (*DAT_300847ac == 0) {
      OSAL_LogMsg(DAT_300848dc,DAT_300847ac[1],2,3,4,5,6);
      memset(acStack_124,0x100,0);
      uVar5 = omTimerTickGet();
      snprintf(acStack_124,0x100,DAT_300848e0,uVar5);
      update_record_file(acStack_124);
      return 0xffffffff;
    }
    *(int *)(*DAT_30083d2c + 0x18) = *(int *)(*DAT_30083d2c + 0x18) - *DAT_300847b0;
    *(int *)(*DAT_30083d2c + 0x14) = *(int *)(*DAT_30083d2c + 0x14) + *DAT_300847b0;
    *(int *)(*DAT_30083d2c + 0x1c) = *(int *)(*DAT_30083d2c + 0x1c) + *DAT_300847b0;
    DAT_300847ac[2] = 0;
    DAT_30084a48[4] = 0;
    DAT_30084a48[1] = 0;
    *DAT_30084a48 = 0;
  }
  if ((uint)DAT_300847ac[2] < (uint)DAT_300847ac[1]) {
    if ((uint)(DAT_300847ac[2] + *(int *)(*DAT_30083d2c + 0x18)) < (uint)DAT_300847ac[1]) {
      memcpy((void *)(*DAT_300847ac + DAT_300847ac[2]),*(void **)(*DAT_30083d2c + 0x14),
             *(size_t *)(*DAT_30083d2c + 0x18));
      *(int *)(*DAT_30083d2c + 0x1c) =
           *(int *)(*DAT_30083d2c + 0x1c) + *(int *)(*DAT_30083d2c + 0x18);
      DAT_300847ac[2] = DAT_300847ac[2] + *(int *)(*DAT_30083d2c + 0x18);
      return 1;
    }
    memcpy((void *)(*DAT_300847ac + DAT_300847ac[2]),*(void **)(*DAT_30083d2c + 0x14),
           DAT_300847ac[1] - DAT_300847ac[2]);
    *(int *)(*DAT_30083d2c + 0x18) =
         *(int *)(*DAT_30083d2c + 0x18) - (DAT_300847ac[1] - DAT_300847ac[2]);
    *(int *)(*DAT_30083d2c + 0x14) =
         *(int *)(*DAT_30083d2c + 0x14) + (DAT_300847ac[1] - DAT_300847ac[2]);
    *(int *)(*DAT_30083d2c + 0x1c) =
         *(int *)(*DAT_30083d2c + 0x1c) + (DAT_300847ac[1] - DAT_300847ac[2]);
    DAT_300847ac[2] = DAT_300847ac[1];
    __src = (undefined1 *)*DAT_300847ac;
    for (iVar10 = 0; iVar10 < (int)(uint)*DAT_30084670; iVar10 = iVar10 + 1) {
      memcpy(__src + 1,__src,0xfe);
      *__src = 0x2f;
      __src = __src + 0x110;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * dynFSFirstPacketHandle @ 0x30083DC4  (примерный размер ~1820 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 17
 * Вызывает: OSAL_LogMsg, cd, fclose, fopen, free, malloc, memcpy, memset, mkdir, omTimerTickGet, snprintf, strcat, strchr, strcmp
 *           ...
 * Вызывают: dynFSDloadProcess
 * Константы: 0xFFFFFFFF, 0x30083DC4
 * Данные: DAT_30084304, DAT_300847ac, DAT_300847b4, DAT_30084a48, DAT_30084c64, DAT_30084da0, DAT_30084da4, DAT_30084da8
 * ---------------------------------------------------------------- */
undefined4 dynFSFirstPacketHandle(undefined4 *param_1)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  undefined4 uVar4;
  void *pvVar5;
  size_t sVar6;
  FILE *pFVar7;
  __mode_t __mode;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  char acStack_128 [256];
  
  bVar3 = false;
  pcVar8 = acStack_128;
  iVar11 = 0x80;
  pcVar10 = DAT_30084c64;
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
  if (DAT_30084a48[1] == 0) {
    *param_1 = 0;
    DAT_30084a48[4] = *DAT_300847ac + *DAT_30084a48 * 0x110;
    if (*(char *)DAT_30084a48[4] == '\0') {
      OSAL_LogMsg(DAT_30084da0,DAT_30084a48[1],DAT_30084a48[4],3,4,5,6,0x50);
      memset(acStack_128,0x100,0);
      uVar4 = omTimerTickGet();
      snprintf(acStack_128,0x100,DAT_30084da4,uVar4,DAT_30084a48[1],DAT_30084a48[4]);
      update_record_file(acStack_128);
      return 0xffffffff;
    }
    iVar11 = (*(int *)(DAT_30084a48[4] + 0x100) + *DAT_300847b4) - *(int *)(*DAT_30084da8 + 0x1c);
    *(int *)(*DAT_30084da8 + 0x18) = *(int *)(*DAT_30084da8 + 0x18) - iVar11;
    *(int *)(*DAT_30084da8 + 0x14) = iVar11 + *(int *)(*DAT_30084da8 + 0x14);
    *(int *)(*DAT_30084da8 + 0x1c) = iVar11 + *(int *)(*DAT_30084da8 + 0x1c);
    DAT_30084a48[1] = *(int *)(DAT_30084a48[4] + 0x104);
    if (*DAT_30084304 != 0) {
      free((void *)*DAT_30084304);
      *DAT_30084304 = 0;
    }
    pvVar5 = malloc(DAT_30084a48[1]);
    *DAT_30084304 = (int)pvVar5;
    if (*DAT_30084304 == 0) {
      OSAL_LogMsg(DAT_30084f9c,0,0,0,0,0,0);
      memset(acStack_128,0x100,0);
      uVar4 = omTimerTickGet();
      snprintf(acStack_128,0x100,DAT_30084fa0,uVar4);
      update_record_file(acStack_128);
      return 0xffffffff;
    }
    DAT_30084304[1] = 0;
    DAT_30084304[2] = DAT_30084a48[1];
    pcVar10 = (char *)DAT_30084a48[4];
    memset(DAT_30084fa4,0,0xff);
    while (pcVar8 = strchr(pcVar10,0x5c), pcVar8 != (char *)0x0) {
      memset(DAT_30084fa8,0,0xff);
      memcpy(DAT_30084fa8,pcVar10,(int)pcVar8 - (int)pcVar10);
      if (bVar3) {
        mkdir(DAT_30084fa8,__mode);
        cd(DAT_30084fa8);
        strcat(DAT_30084fa4,DAT_3008506c);
      }
      else {
        iVar11 = cd(DAT_30084fa8);
        if (iVar11 != 0) {
          OSAL_LogMsg(DAT_30085060,DAT_30084fa8,2,3,4,5,6);
          memset(acStack_128,0x100,0);
          uVar4 = omTimerTickGet();
          snprintf(acStack_128,0x100,DAT_30085064,uVar4,DAT_30084fa8);
          update_record_file(acStack_128);
          return 0xffffffff;
        }
        bVar3 = true;
        xdelete(DAT_30085068);
      }
      sVar6 = strlen(DAT_30084fa4);
      if (sVar6 < 0xff) {
        strcat(DAT_30084fa4,DAT_30084fa8);
      }
      pcVar10 = pcVar8 + 1;
    }
    iVar11 = strcmp(DAT_30084fa4,DAT_30085168);
    if ((iVar11 == 0) && (iVar11 = strcmp(pcVar10,DAT_3008516c), iVar11 == 0)) {
      OSAL_LogMsg(DAT_30085170,0,0,0,0,0,0);
      memset(acStack_128,0x100,0);
      uVar4 = omTimerTickGet();
      snprintf(acStack_128,0x100,DAT_30085174,uVar4);
      update_record_file(acStack_128);
      uVar4 = 3;
    }
    else {
      uVar4 = 0x50;
    }
    *(undefined4 *)(DAT_30085178 + 0xc) = uVar4;
    memset(DAT_30084fa8,0,0xff);
    strcat(DAT_30084fa8,pcVar10);
    DAT_30084a48[2] = 0;
    DAT_30084a48[3] = 0;
    *(undefined4 *)(DAT_30085178 + 4) = 0;
    pFVar7 = fopen(DAT_30084fa8,DAT_3008517c);
    *(FILE **)(*DAT_30084da8 + 0xc) = pFVar7;
    if (*(int *)(*DAT_30084da8 + 0xc) == 0) {
      OSAL_LogMsg(DAT_30085298,*DAT_30084a48,2,3,4,5,6);
      memset(acStack_128,0x100,0);
      uVar4 = omTimerTickGet();
      snprintf(acStack_128,0x100,DAT_3008529c,uVar4,*DAT_30084a48);
      update_record_file(acStack_128);
      return 0xffffffff;
    }
    iVar11 = fclose(*(FILE **)(*DAT_30084da8 + 0xc));
    if (iVar11 != 0) {
      OSAL_LogMsg(DAT_300852a0,*DAT_30084a48,2,3,4,5,6);
      memset(acStack_128,0x100,0);
      uVar4 = omTimerTickGet();
      snprintf(acStack_128,0x100,DAT_300852a4,uVar4,*DAT_30084a48);
      update_record_file(acStack_128);
      return 0xffffffff;
    }
    *(undefined4 *)(*DAT_30084da8 + 0xc) = 0;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * dynFSDloadToRam @ 0x300844E0  (примерный размер ~984 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_300827c0, OSAL_LogMsg, memcpy, memset, omTimerTickGet, snprintf, update_record_file
 * Вызывают: dynFSDloadProcess
 * Константы: 0xFFFFFFFF, 0x300844E0
 * Данные: DAT_30084a48, DAT_30084da8, DAT_30085178, DAT_300853b8, DAT_300853bc, DAT_300853c0, DAT_300853c4, DAT_300853c8
 * ---------------------------------------------------------------- */
undefined4 dynFSDloadToRam(void)

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
  iVar7 = 0x80;
  pcVar6 = DAT_300853b8;
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
  if (*DAT_30085178 == 0) {
    OSAL_LogMsg(DAT_300853bc,DAT_300853c0,0,0,0,0,0);
    memset(acStack_11c,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_11c,0x100,DAT_300853c8,uVar3,DAT_300853c4);
    update_record_file(acStack_11c);
    uVar3 = 0xffffffff;
  }
  else if ((uint)DAT_30085178[1] < (uint)DAT_30085178[2]) {
    memcpy((void *)(*DAT_30085178 + DAT_30085178[1]),*(void **)(*DAT_30084da8 + 0x14),
           DAT_30084a48[3]);
    *(int *)(*DAT_30084da8 + 0x1c) = *(int *)(*DAT_30084da8 + 0x1c) + DAT_30084a48[3];
    *(int *)(*DAT_30084da8 + 0x18) = *(int *)(*DAT_30084da8 + 0x18) - DAT_30084a48[3];
    *(int *)(*DAT_30084da8 + 0x14) = *(int *)(*DAT_30084da8 + 0x14) + DAT_30084a48[3];
    DAT_30084a48[2] = DAT_30084a48[2] + DAT_30084a48[3];
    DAT_30085178[1] = DAT_30085178[1] + DAT_30084a48[3];
    if (DAT_30084a48[2] == DAT_30084a48[1]) {
      iVar7 = FUN_300827c0();
      if (iVar7 != 0) {
        OSAL_LogMsg(DAT_3008562c,1,2,3,4,5,6);
        memset(acStack_11c,0x100,0);
        uVar3 = omTimerTickGet();
        snprintf(acStack_11c,0x100,DAT_30085630,uVar3);
        update_record_file(acStack_11c);
        return 0xffffffff;
      }
      OSAL_LogMsg(DAT_30085634,*DAT_30084a48,2,3,4,5,6);
      memset(acStack_11c,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_11c,0x100,DAT_300856e4,uVar3,*DAT_30084a48);
      update_record_file(acStack_11c);
      DAT_30084a48[1] = 0;
      DAT_30084a48[2] = 0;
      DAT_30084a48[3] = 0;
      *DAT_30084a48 = *DAT_30084a48 + 1;
    }
    uVar3 = 0;
  }
  else {
    OSAL_LogMsg(DAT_3008546c,DAT_30085178[2],DAT_30085178[1],DAT_30085470,0,0,0);
    memset(acStack_11c,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_11c,0x100,DAT_30085478,uVar3,DAT_30085178[2],DAT_30085178[1],DAT_30085474);
    update_record_file(acStack_11c);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * dynFSDloadProcess @ 0x300848B8  (примерный размер ~1192 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 10
 * Вызывает: OSAL_LogMsg, dynFSDloadParaChk, dynFSDloadToRam, dynFSFirstPacketHandle, dynFSGetFileList, free, memset, omTimerTickGet, snprintf, update_record_file
 * Вызывают: FUN_30080798, dloadFromFsMainThread, dloadTFPro
 * Константы: 0xFFFFFFFF, 0x300848B8
 * Данные: DAT_30084da8, DAT_30085178, DAT_30085634, DAT_300856e4, DAT_300856e8, DAT_300857b8, DAT_300857bc, DAT_300857c0
 * ---------------------------------------------------------------- */
undefined4 dynFSDloadProcess(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  undefined4 local_118;
  char acStack_114 [256];
  
  local_118 = 0;
  iVar7 = 0x80;
  pcVar4 = acStack_114;
  pcVar6 = DAT_300856e8;
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
  iVar7 = dynFSDloadParaChk(cVar1,cVar2,acStack_114);
  if (iVar7 == 0) {
    iVar7 = dynFSGetFileList();
    if (iVar7 == 1) {
      uVar3 = 0;
    }
    else if (iVar7 == 0) {
      do {
        while( true ) {
          if (*(int *)(*DAT_30084da8 + 0x18) == 0) goto LAB_30084c68;
          iVar7 = dynFSFirstPacketHandle(&local_118);
          if (iVar7 != 0) {
            return 0xffffffff;
          }
          if (DAT_300857c8[1] != 0) break;
          OSAL_LogMsg(DAT_30085634,*DAT_300857c8,2,3,4,5,6);
          memset(acStack_114,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_114,0x100,DAT_300856e4,uVar3,*DAT_300857c8);
          update_record_file(acStack_114);
          DAT_300857c8[1] = 0;
          DAT_300857c8[2] = 0;
          DAT_300857c8[3] = 0;
          *DAT_300857c8 = *DAT_300857c8 + 1;
          if (*DAT_300857c8 == (uint)*DAT_300857cc) goto LAB_30084c68;
        }
        if (DAT_300857c8[1] < DAT_300857c8[2] + *(int *)(*DAT_30084da8 + 0x18)) {
          DAT_300857c8[3] = DAT_300857c8[1] - DAT_300857c8[2];
        }
        else {
          DAT_300857c8[3] = *(uint *)(*DAT_30084da8 + 0x18);
        }
        if (*DAT_300857d0 != 1) {
          OSAL_LogMsg(DAT_300857d4,*DAT_300857d0,2,3,4,5,6);
          memset(acStack_114,0x100,0);
          uVar3 = omTimerTickGet();
          snprintf(acStack_114,0x100,DAT_300857d8,uVar3,(uint)*DAT_300857d0);
          update_record_file(acStack_114);
          return 0xffffffff;
        }
        iVar7 = dynFSDloadToRam();
        if (iVar7 != 0) {
          return 0xffffffff;
        }
      } while (*DAT_300857c8 != (uint)*DAT_300857cc);
LAB_30084c68:
      if (*DAT_300857c8 == (uint)*DAT_300857cc) {
        *DAT_300857dc = *(undefined4 *)(*DAT_30084da8 + 4);
        OSAL_LogMsg(DAT_300857e0,*(undefined4 *)(*DAT_30084da8 + 4),2,3,4,5,6);
        memset(acStack_114,0x100,0);
        uVar3 = omTimerTickGet();
        snprintf(acStack_114,0x100,DAT_300857e4,uVar3);
        update_record_file(acStack_114);
        *(undefined4 *)(DAT_30085178 + 4) = 0;
        if (*DAT_300857e8 != 0) {
          free((void *)*DAT_300857e8);
          *DAT_300857e8 = 0;
        }
        DAT_300857c8[4] = 0;
      }
      uVar3 = 0;
    }
    else {
      OSAL_LogMsg(DAT_300857c0,0,0,0,0,0,0);
      memset(acStack_114,0x100,0);
      uVar3 = omTimerTickGet();
      snprintf(acStack_114,0x100,DAT_300857c4,uVar3);
      update_record_file(acStack_114);
      uVar3 = 0xffffffff;
    }
  }
  else {
    OSAL_LogMsg(DAT_300857b8,0,0,0,0,0,0);
    memset(acStack_114,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_114,0x100,DAT_300857bc,uVar3);
    update_record_file(acStack_114);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * DCBInit @ 0x3008522C  (примерный размер ~356 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, memset, omTimerTickGet, snprintf, update_record_file
 * Вызывают: FUN_30080798, dloadFromFsMainThread, dloadInit, dloadTFPro
 * Константы: 0xFFFFFFFF, 0x3008522C
 * Данные: DAT_30085810, DAT_3008581c, DAT_3008582c, DAT_30085830, DAT_30085834
 * ---------------------------------------------------------------- */
void DCBInit(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char acStack_104 [260];
  
  pcVar4 = acStack_104;
  iVar7 = 0x80;
  pcVar6 = DAT_3008582c;
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
  if (*DAT_30085810 == 0) {
    OSAL_LogMsg(DAT_30085830,1,2,3,4,5,6);
    memset(acStack_104,0x100,0);
    uVar3 = omTimerTickGet();
    snprintf(acStack_104,0x100,DAT_30085834,uVar3);
    update_record_file(acStack_104);
  }
  else {
    *(undefined4 *)(*DAT_30085810 + 4) = 0x50;
    *(undefined4 *)(*DAT_30085810 + 8) = 0;
    *(undefined4 *)(*DAT_30085810 + 0xc) = 0;
    *(undefined4 *)(*DAT_30085810 + 0x10) = 0xffffffff;
    *(undefined4 *)(*DAT_30085810 + 0x14) = 0xffffffff;
    *(undefined4 *)(*DAT_30085810 + 0x18) = 0;
    *(undefined4 *)(*DAT_30085810 + 0x1c) = 0;
    *(undefined4 *)(*DAT_30085810 + 0x20) = 0;
    *DAT_3008581c = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * imageTypeChange @ 0x30085390  (примерный размер ~352 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 1
 * Вызывает: OSAL_LogMsg
 * Вызывают: FUN_30080798, TFUP_IdentifyFile, dloadFromFsMainThread, dloadTFPro
 * Константы: 0x30085390, 0x00550000, 0x00560000, 0xFFFFFFFF
 * Данные: DAT_30085838, DAT_3008583c, DAT_30085840, DAT_30085844, DAT_30085848
 * ---------------------------------------------------------------- */
undefined4 imageTypeChange(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if (*param_1 == 4) {
    *param_1 = DAT_30085838;
  }
  else if (*param_1 == 5) {
    *param_1 = 0x10c;
  }
  else {
    if (*param_1 < 0x200) {
      return 0;
    }
    if (*param_1 == 0xa0000) {
      *param_1 = 1;
    }
    else if (*param_1 == 0xb0000) {
      *param_1 = 0x10c;
    }
    else if (*param_1 == 0x550000) {
      *param_1 = 2;
    }
    else if (*param_1 == 0x560000) {
      *param_1 = 0x65;
    }
    else {
      if (*param_1 != DAT_3008583c) {
        OSAL_LogMsg(DAT_30085844,*param_1,2,3,4,5,6);
        return 0xffffffff;
      }
      *param_1 = DAT_30085840;
    }
  }
  OSAL_LogMsg(DAT_30085848,uVar1,*param_1,3,4,5,6);
  return 0;
}

/* ----------------------------------------------------------------
 * getDloadFlashInfo @ 0x300854F0  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: OSAL_LogMsg, memset
 * Константы: 0x300854F0, 0xFFFFFFFF
 * Данные: DAT_3008584c, DAT_30085850, DAT_30085854, DAT_30085858
 * ---------------------------------------------------------------- */
undefined4 getDloadFlashInfo(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    OSAL_LogMsg(DAT_3008584c,1,2,3,4,5,6);
    uVar1 = 0xffffffff;
  }
  else {
    memset(param_1,0,0xc);
    *param_1 = *DAT_30085850;
    param_1[1] = *DAT_30085854;
    param_1[2] = *DAT_30085858;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * Om_HdlcEncap @ 0x30085888  (примерный размер ~628 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: dloadUSBSendPro
 * Константы: 0x30085888
 * Данные: DAT_30085d70, DAT_30085d74, DAT_30085d78, DAT_30085d7c, DAT_30085d80, DAT_30085d84, DAT_30085d88, DAT_30085d8c
 * ---------------------------------------------------------------- */
undefined4
Om_HdlcEncap(byte *param_1,uint param_2,undefined1 *param_3,ushort param_4,short *param_5)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = DAT_30085d70;
  if (((param_1 == (byte *)0x0) || (param_3 == (undefined1 *)0x0)) || (param_5 == (short *)0x0)) {
    printf(DAT_30085d74);
    uVar3 = 1;
  }
  else if ((param_2 & 0xffff) == 0) {
    *param_5 = 0;
    printf(DAT_30085d78);
    uVar3 = 1;
  }
  else if (param_4 < 5) {
    *param_5 = 0;
    printf(DAT_30085d7c,(uint)param_4);
    uVar3 = 1;
  }
  else {
    *param_3 = 0x7e;
    pbVar4 = param_3 + 1;
    while ((uVar7 = param_2 + DAT_30085d70, (param_2 & 0xffff) != 0 &&
           ((int)pbVar4 - (int)param_3 <= (int)(param_4 - 3)))) {
      uVar6 = (uint)*(ushort *)(DAT_30085d80 + ((uVar6 ^ *param_1) & 0xff) * 2) ^ uVar6 >> 8;
      param_2 = uVar7;
      if ((*param_1 == 0x7e) || (*param_1 == 0x7d)) {
        *pbVar4 = 0x7d;
        pbVar5 = pbVar4 + 1;
        pbVar4 = pbVar4 + 2;
        *pbVar5 = *param_1 ^ 0x20;
        param_1 = param_1 + 1;
      }
      else {
        *pbVar4 = *param_1;
        pbVar4 = pbVar4 + 1;
        param_1 = param_1 + 1;
      }
    }
    if ((int)(param_4 - 3) < (int)pbVar4 - (int)param_3) {
      *param_5 = 0;
      printf(DAT_30085d84,(uint)param_4);
      uVar3 = 1;
    }
    else {
      uVar6 = ~uVar6;
      if (((uVar6 & 0xff) == 0x7e) || ((uVar6 & 0xff) == 0x7d)) {
        *pbVar4 = 0x7d;
        pbVar5 = pbVar4 + 2;
        pbVar4[1] = (byte)uVar6 ^ 0x20;
      }
      else {
        pbVar5 = pbVar4 + 1;
        *pbVar4 = (byte)uVar6;
      }
      if ((int)(param_4 - 2) < (int)pbVar5 - (int)param_3) {
        *param_5 = 0;
        printf(DAT_30085d88,(uint)param_4);
        uVar3 = 1;
      }
      else {
        iVar1 = (int)(uVar6 & 0xffff) >> 8;
        bVar2 = (byte)((uVar6 & 0xffff) >> 8);
        if ((iVar1 == 0x7e) || (iVar1 == 0x7d)) {
          *pbVar5 = 0x7d;
          pbVar4 = pbVar5 + 2;
          pbVar5[1] = bVar2 ^ 0x20;
        }
        else {
          pbVar4 = pbVar5 + 1;
          *pbVar5 = bVar2;
        }
        if ((int)(param_4 - 1) < (int)pbVar4 - (int)param_3) {
          *param_5 = 0;
          printf(DAT_30085d8c,(uint)param_4);
          uVar3 = 1;
        }
        else {
          *pbVar4 = 0x7e;
          *param_5 = ((short)pbVar4 + 1) - (short)param_3;
          uVar3 = 0;
        }
      }
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * Om_HdlcInit @ 0x30085AFC  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: FUN_30080798, dloadInit
 * Константы: 0x30085AFC
 * Данные: DAT_30085d90
 * ---------------------------------------------------------------- */
void Om_HdlcInit(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    printf(DAT_30085d90);
  }
  else {
    param_1[4] = 0;
    param_1[1] = 0;
    *param_1 = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * OM_HdlcFcs @ 0x30085B34  (примерный размер ~76 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Om_HdlcDecap
 * Константы: 0x30085B34
 * Данные: DAT_30085d70, DAT_30085d80
 * ---------------------------------------------------------------- */
uint OM_HdlcFcs(byte *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = DAT_30085d70;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar1 = (uint)*(ushort *)(DAT_30085d80 + ((uVar1 ^ *param_1) & 0xff) * 2) ^ uVar1 >> 8;
    param_1 = param_1 + 1;
  }
  return uVar1 & 0xffff;
}

/* ----------------------------------------------------------------
 * Om_HdlcDecap @ 0x30085B80  (примерный размер ~552 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: OM_HdlcFcs, printf
 * Вызывают: dloadUSBCallback
 * Константы: 0x30085B80, 0xFFFFFFFC, 0xFFFFFFFE, 0xFFFFFFFD
 * Данные: DAT_30085d94, DAT_30085d98, DAT_30085d9c, DAT_30085da0, DAT_30085da4
 * ---------------------------------------------------------------- */
undefined4 Om_HdlcDecap(uint *param_1,byte param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1 == (uint *)0x0) {
    printf(DAT_30085d94);
    uVar1 = 5;
  }
  else if (param_1[3] == 0) {
    printf(DAT_30085d98);
    uVar1 = 5;
  }
  else if (((*param_1 & 1) == 0) || (param_2 == 0x7e)) {
    if (param_2 == 0x7d) {
      if ((*param_1 & 2) != 0) {
        *param_1 = *param_1 & 0xfffffffc | 1;
        param_1[1] = 0;
        printf(DAT_30085da0,0x7d);
        return 3;
      }
      *param_1 = *param_1 | 2;
    }
    else if (param_2 == 0x7e) {
      *param_1 = *param_1 & 0xfffffffe;
      if (2 < param_1[1]) {
        uVar2 = OM_HdlcFcs(param_1[3],param_1[1]);
        if ((uVar2 & 0xffff) != DAT_30085d9c) {
          param_1[1] = 0;
          return 2;
        }
        param_1[4] = param_1[1] - 2;
        param_1[1] = 0;
        return 0;
      }
      param_1[1] = 0;
    }
    else {
      if (param_1[2] <= param_1[1]) {
        *param_1 = *param_1 | 1;
        param_1[1] = 0;
        printf(DAT_30085da4,param_1[2]);
        return 4;
      }
      if ((*param_1 & 2) != 0) {
        *param_1 = *param_1 & 0xfffffffd;
        if ((param_2 != 0x5e) && (param_2 != 0x5d)) {
          *param_1 = *param_1 | 1;
          param_1[1] = 0;
          printf(DAT_30085da0,(uint)param_2);
          return 3;
        }
        param_2 = param_2 ^ 0x20;
      }
      *(byte *)(param_1[3] + param_1[1]) = param_2;
      param_1[1] = param_1[1] + 1;
    }
    uVar1 = 1;
  }
  else {
    param_1[1] = 0;
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * imgIdioCheck @ 0x30085DA8  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: OSAL_LogMsg
 * Вызывают: upgradeAllow
 * Константы: 0x30085DA8, 0xFFFFFFFF
 * Данные: DAT_30085ee4
 * ---------------------------------------------------------------- */
undefined4 imgIdioCheck(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    OSAL_LogMsg(DAT_30085ee4,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * imgUpgradeAllow @ 0x30085E00  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: upgradeAllow
 * Константы: 0x30085E00
 * ---------------------------------------------------------------- */
int imgUpgradeAllow(int param_1)

{
  if (param_1 == 2) {
    param_1 = 0;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * imgSecCheck @ 0x30085E94  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30085E94
 * ---------------------------------------------------------------- */
undefined4 imgSecCheck(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * imgSecHandle @ 0x30085E9C  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: OSAL_LogMsg
 * Вызывают: FUN_300827c0
 * Константы: 0x30085E9C
 * Данные: DAT_30085eec
 * ---------------------------------------------------------------- */
undefined4 imgSecHandle(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  OSAL_LogMsg(DAT_30085eec,param_2,param_3,0,0,0,0);
  return 0;
}

/* ----------------------------------------------------------------
 * tftEmiTimerOpen @ 0x30085EF0  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 0
 * Вызывают: tftClear, tftRefresh, tftRefreshByBit
 * Константы: 0x30085EF0
 * Данные: DAT_300864f8
 * ---------------------------------------------------------------- */
void tftEmiTimerOpen(void)

{
  *DAT_300864f8 = 0x80000;
  return;
}

/* ----------------------------------------------------------------
 * tftClear @ 0x30085F00  (примерный размер ~308 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: tftEmiTimerOpen
 * Вызывают: tftClearWholeScreen
 * Константы: 0x30085F00
 * Данные: DAT_300864fc, DAT_30086500
 * ---------------------------------------------------------------- */
undefined4 tftClear(uint param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (param_1 + param_3) - 1;
  uVar1 = (param_2 + param_4) - 1;
  if ((uVar2 < 0x80) && (uVar1 < 0x80)) {
    tftEmiTimerOpen();
    *DAT_300864fc = 0x2a;
    *DAT_30086500 = (char)(param_1 >> 8);
    *DAT_30086500 = (char)param_1;
    *DAT_30086500 = (char)(uVar2 >> 8);
    *DAT_30086500 = (char)uVar2;
    *DAT_300864fc = 0x2b;
    *DAT_30086500 = (char)(param_2 >> 8);
    *DAT_30086500 = (char)param_2;
    *DAT_30086500 = (char)(uVar1 >> 8);
    *DAT_30086500 = (char)uVar1;
    *DAT_300864fc = 0x2c;
    for (; uVar3 = param_1, param_2 <= uVar1; param_2 = param_2 + 1) {
      for (; uVar3 <= uVar2; uVar3 = uVar3 + 1) {
        *DAT_30086500 = 0;
        *DAT_30086500 = 0;
      }
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * tftClearWholeScreen @ 0x30086034  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: tftClear
 * Константы: 0x30086034
 * ---------------------------------------------------------------- */
void tftClearWholeScreen(void)

{
  tftClear(0,0,0x80,0x80);
  return;
}

/* ----------------------------------------------------------------
 * tftRefresh @ 0x30086058  (примерный размер ~344 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: tftEmiTimerOpen
 * Константы: 0x30086058
 * Данные: DAT_300864fc, DAT_30086500
 * ---------------------------------------------------------------- */
undefined4 tftRefresh(uint param_1,uint param_2,int param_3,int param_4,undefined1 *param_5)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  uVar1 = (param_1 + param_3) - 1;
  uVar4 = (param_2 + param_4) - 1;
  if (((param_5 != (undefined1 *)0x0) && (uVar1 < 0x80)) && (uVar4 < 0x80)) {
    tftEmiTimerOpen();
    *DAT_300864fc = 0x2a;
    *DAT_30086500 = (char)(param_1 >> 8);
    *DAT_30086500 = (char)param_1;
    *DAT_30086500 = (char)(uVar1 >> 8);
    *DAT_30086500 = (char)uVar1;
    *DAT_300864fc = 0x2b;
    *DAT_30086500 = (char)(param_2 >> 8);
    *DAT_30086500 = (char)param_2;
    *DAT_30086500 = (char)(uVar4 >> 8);
    *DAT_30086500 = (char)uVar4;
    *DAT_300864fc = 0x2c;
    for (; uVar2 = param_1, param_2 <= uVar4; param_2 = param_2 + 1) {
      for (; uVar2 <= uVar1; uVar2 = uVar2 + 1) {
        puVar3 = param_5 + 1;
        *DAT_30086500 = *param_5;
        param_5 = param_5 + 2;
        *DAT_30086500 = *puVar3;
      }
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * tftRefreshByBit @ 0x300861B0  (примерный размер ~432 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 1
 * Вызывает: tftEmiTimerOpen
 * Вызывают: tftCharDisplay, tftUpdateDisplay, tftUpdateImage
 * Константы: 0x300861B0
 * Данные: DAT_300864fc, DAT_30086500
 * ---------------------------------------------------------------- */
undefined4 tftRefreshByBit(uint param_1,uint param_2,int param_3,int param_4,byte *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 0;
  uVar1 = (param_1 + param_3) - 1;
  uVar4 = (param_2 + param_4) - 1;
  if (((param_5 != (byte *)0x0) && (uVar1 < 0x80)) && (uVar4 < 0x80)) {
    tftEmiTimerOpen();
    *DAT_300864fc = 0x2a;
    *DAT_30086500 = (char)(param_1 >> 8);
    *DAT_30086500 = (char)param_1;
    *DAT_30086500 = (char)(uVar1 >> 8);
    *DAT_30086500 = (char)uVar1;
    *DAT_300864fc = 0x2b;
    *DAT_30086500 = (char)(param_2 >> 8);
    *DAT_30086500 = (char)param_2;
    *DAT_30086500 = (char)(uVar4 >> 8);
    *DAT_30086500 = (char)uVar4;
    *DAT_300864fc = 0x2c;
    for (; uVar2 = param_1, param_2 <= uVar4; param_2 = param_2 + 1) {
      for (; uVar2 <= uVar1; uVar2 = uVar2 + 1) {
        if (iVar3 == 8) {
          param_5 = param_5 + 1;
          iVar3 = 0;
        }
        if (((int)(uint)*param_5 >> (7U - iVar3 & 0xff) & 1U) == 0) {
          *DAT_30086500 = 0;
          *DAT_30086500 = 0;
        }
        else {
          *DAT_30086500 = 0xff;
          *DAT_30086500 = 0xff;
        }
        iVar3 = iVar3 + 1;
      }
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * tftCharDisplay @ 0x30086360  (примерный размер ~196 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: tftRefreshByBit
 * Вызывают: tftStringDisplay
 * Константы: 0x30086360
 * Данные: DAT_30086504, DAT_30086508, DAT_3008650c, DAT_30086510, DAT_30086514
 * ---------------------------------------------------------------- */
void tftCharDisplay(undefined1 param_1,undefined1 param_2,byte *param_3)

{
  int iVar1;
  
  if (*param_3 - 0x41 < 0x1a) {
    iVar1 = DAT_30086504 + (uint)*param_3 * 0x10;
  }
  else if (*param_3 - 0x61 < 0x1a) {
    iVar1 = DAT_30086508 + (uint)*param_3 * 0x10;
  }
  else if (*param_3 - 0x30 < 10) {
    iVar1 = DAT_3008650c + (uint)*param_3 * 0x10;
  }
  else {
    iVar1 = DAT_30086510;
    if ((*param_3 != 0x20) && (iVar1 = 0, *param_3 == 0x21)) {
      iVar1 = DAT_30086514;
    }
  }
  tftRefreshByBit(param_1,param_2,8,0x10,iVar1);
  return;
}

/* ----------------------------------------------------------------
 * tftStringDisplay @ 0x30086424  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: tftCharDisplay
 * Константы: 0x30086424
 * ---------------------------------------------------------------- */
void tftStringDisplay(uint param_1,int param_2,char *param_3)

{
  char *pcVar1;
  
  while (*param_3 != '\0') {
    pcVar1 = param_3 + 1;
    tftCharDisplay(param_1,param_2,param_3);
    param_1 = param_1 + 8;
    param_3 = pcVar1;
    if (0x7f < (param_1 & 0xff)) {
      param_1 = 0;
      param_2 = param_2 + 0x10;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * tftUpdateImage @ 0x30086474  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: tftRefreshByBit
 * Константы: 0x30086474
 * Данные: DAT_30086518
 * ---------------------------------------------------------------- */
void tftUpdateImage(void)

{
  tftRefreshByBit(0,0,0x80,0x80,DAT_30086518);
  return;
}

/* ----------------------------------------------------------------
 * tftUpdateDisplay @ 0x300864A0  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: tftRefreshByBit
 * Константы: 0x300864A0
 * Данные: DAT_3008651c, DAT_30086520
 * ---------------------------------------------------------------- */
void tftUpdateDisplay(int param_1)

{
  if (param_1 == 0) {
    tftRefreshByBit(0,0x28,0x80,0x30,DAT_30086520);
  }
  else {
    tftRefreshByBit(0,0x28,0x80,0x30,DAT_3008651c);
  }
  return;
}

/* ----------------------------------------------------------------
 * gz_transformErr @ 0x30086524  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 0
 * Вызывают: gz_compressFile, gz_uncompressFile, gzgetUncompressLength, gzuncompressFileToStream
 * Константы: 0x30086524, 0x30086548, 0xFFFFFFFF
 * Данные: DAT_3008654c
 * ---------------------------------------------------------------- */
undefined4 gz_transformErr(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 + 6U < 8) {
                    /* WARNING: Could not recover jumptable at 0x30086548. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_3008654c + (param_1 + 6U) * 4))();
    return uVar1;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * gz_compressFile @ 0x300865B8  (примерный размер ~576 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 11
 * Вызывает: QC_gzclose, QC_gzerror, QC_gzopen, QC_gzwrite, fclose, fopen, fread, free, gz_transformErr, malloc, memset
 * Константы: 0xFFFFFFFF, 0x300865B8
 * Данные: DAT_30086ccc, DAT_30086cd0
 * ---------------------------------------------------------------- */
void gz_compressFile(char *param_1,int param_2)

{
  bool bVar1;
  size_t sVar2;
  size_t sVar3;
  void *__s;
  undefined4 uVar4;
  int iVar5;
  FILE *__stream;
  int local_38 [3];
  
  __s = (void *)0x0;
  __stream = (FILE *)0x0;
  iVar5 = 0;
  local_38[0] = -1;
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    uVar4 = 0xffffffff;
  }
  else {
    __s = malloc(0x400);
    if (__s == (void *)0x0) {
      uVar4 = 0xffffffff;
    }
    else {
      memset(__s,0,0x400);
      __stream = fopen(param_1,DAT_30086ccc);
      if (__stream == (FILE *)0x0) {
        uVar4 = 0xffffffff;
      }
      else {
        iVar5 = QC_gzopen(param_2,DAT_30086cd0,0);
        if (iVar5 == 0) {
          uVar4 = 0xffffffff;
        }
        else {
          do {
            sVar2 = fread(__s,1,0x400,__stream);
            if (((int)sVar2 < 0) ||
               ((((FILE *)__stream->_IO_read_ptr == __stream &&
                 (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) &&
                (((uint)__stream->_IO_write_end & 0x40) != 0)))) {
              uVar4 = 0xffffffff;
              goto LAB_300867b0;
            }
            if (((FILE *)__stream->_IO_read_ptr == __stream) &&
               (*(char *)((int)&__stream->_IO_read_end + 2) == 'f')) {
              local_38[1] = 0;
              local_38[2] = (int)(((uint)__stream->_IO_write_end & 0x20) != 0);
              if (local_38[2] == 0) goto LAB_30086764;
              bVar1 = true;
            }
            else {
              local_38[1] = 0xffffffff;
              local_38[2] = 0;
LAB_30086764:
              bVar1 = false;
            }
            QC_gzerror(iVar5,local_38);
            sVar3 = QC_gzwrite(iVar5,__s,sVar2);
            if ((sVar3 != sVar2) || (local_38[0] < 0)) {
              uVar4 = 0xffffffff;
              goto LAB_300867b0;
            }
          } while (!bVar1);
          uVar4 = 0;
        }
      }
    }
  }
LAB_300867b0:
  if (__s != (void *)0x0) {
    free(__s);
  }
  if (__stream != (FILE *)0x0) {
    fclose(__stream);
  }
  if (iVar5 != 0) {
    QC_gzclose(iVar5);
  }
  gz_transformErr(uVar4);
  return;
}

/* ----------------------------------------------------------------
 * gz_uncompressFile @ 0x300867F8  (примерный размер ~492 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 12
 * Вызывает: QC_gzclose, QC_gzeof, QC_gzerror, QC_gzopen, QC_gzread, fclose, fopen, free, fwrite, gz_transformErr, malloc, memset
 * Константы: 0xFFFFFFFF, 0x300867F8
 * Данные: DAT_30086ccc, DAT_30086cd0
 * ---------------------------------------------------------------- */
void gz_uncompressFile(int param_1,char *param_2)

{
  size_t __n;
  int iVar1;
  size_t sVar2;
  FILE *__s;
  int iVar3;
  void *__s_00;
  undefined4 uVar4;
  int local_30;
  
  __s_00 = (void *)0x0;
  local_30 = -1;
  iVar3 = 0;
  __s = (FILE *)0x0;
  if ((param_1 == 0) || (param_2 == (char *)0x0)) {
    uVar4 = 0xffffffff;
  }
  else {
    __s_00 = malloc(0x400);
    if (__s_00 == (void *)0x0) {
      uVar4 = 0xffffffff;
    }
    else {
      memset(__s_00,0,0x400);
      iVar3 = QC_gzopen(param_1,DAT_30086ccc,0);
      __s = fopen(param_2,DAT_30086cd0);
      if ((iVar3 == 0) || (__s == (FILE *)0x0)) {
        uVar4 = 0xffffffff;
      }
      else {
        do {
          __n = QC_gzread(iVar3,__s_00,0x400);
          if ((int)__n < 0) {
            uVar4 = 0xffffffff;
            goto LAB_3008699c;
          }
          QC_gzerror(iVar3,&local_30);
          if (local_30 < 0) {
            uVar4 = 0xffffffff;
            goto LAB_3008699c;
          }
          iVar1 = QC_gzeof(iVar3);
          sVar2 = fwrite(__s_00,1,__n,__s);
          if ((sVar2 != __n) ||
             ((((FILE *)__s->_IO_read_ptr == __s && (*(char *)((int)&__s->_IO_read_end + 2) == 'f'))
              && (((uint)__s->_IO_write_end & 0x40) != 0)))) {
            uVar4 = 0xffffffff;
            goto LAB_3008699c;
          }
        } while (iVar1 == 0);
        uVar4 = 0;
      }
    }
  }
LAB_3008699c:
  if (__s_00 != (void *)0x0) {
    free(__s_00);
  }
  if (iVar3 != 0) {
    QC_gzclose(iVar3);
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  gz_transformErr(uVar4);
  return;
}

/* ----------------------------------------------------------------
 * gzuncompressFileToStream @ 0x300869E4  (примерный размер ~416 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 11
 * Вызывает: QC_gzclose, QC_gzeof, QC_gzerror, QC_gzopen, QC_gzread, QC_isCompress, free, gz_transformErr, malloc, memcpy, memset
 * Вызывают: uncompress_file_to_stream
 * Константы: 0xFFFFFFFF, 0x300869E4
 * Данные: DAT_30086ccc
 * ---------------------------------------------------------------- */
void gzuncompressFileToStream(int param_1,undefined4 param_2,void *param_3,int param_4)

{
  int iVar1;
  size_t __n;
  int iVar2;
  void *__s;
  int iVar3;
  undefined4 uVar4;
  int local_34;
  
  __s = (void *)0x0;
  local_34 = -1;
  iVar2 = 0;
  iVar3 = 0;
  if (((param_1 == 0) || (param_3 == (void *)0x0)) || (param_4 == 0)) {
    uVar4 = 0xffffffff;
  }
  else {
    __s = malloc(0x400);
    if (__s == (void *)0x0) {
      uVar4 = 0xffffffff;
    }
    else {
      memset(__s,0,0x400);
      iVar2 = QC_gzopen(param_1,DAT_30086ccc,param_2);
      if ((iVar2 == 0) || (param_3 == (void *)0x0)) {
        uVar4 = 0xffffffff;
      }
      else {
        iVar1 = QC_isCompress(iVar2);
        if (iVar1 == 0) {
          uVar4 = 0xffffffff;
        }
        else {
          do {
            __n = QC_gzread(iVar2,__s,0x400);
            QC_gzerror(iVar2,&local_34);
            if (local_34 < 0) {
              uVar4 = 0xffffffff;
              goto LAB_30086b4c;
            }
            iVar1 = QC_gzeof(iVar2);
            memcpy(param_3,__s,__n);
            param_3 = (void *)((int)param_3 + __n);
            iVar3 = iVar3 + __n;
          } while (iVar1 == 0);
          if (param_4 == iVar3) {
            uVar4 = 0;
          }
          else {
            uVar4 = 0xffffffff;
          }
        }
      }
    }
  }
LAB_30086b4c:
  if (__s != (void *)0x0) {
    free(__s);
  }
  if (iVar2 != 0) {
    QC_gzclose(iVar2);
  }
  gz_transformErr(uVar4);
  return;
}

/* ----------------------------------------------------------------
 * gzgetUncompressLength @ 0x30086B84  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: QC_gzclose, QC_gzerror, QC_gzgetlength, QC_gzopen, QC_isCompress, gz_transformErr, printf
 * Вызывают: get_uncompress_length
 * Константы: 0x30086B84
 * Данные: DAT_30086ccc, DAT_30086cd4
 * ---------------------------------------------------------------- */
void gzgetUncompressLength(int param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int local_20;
  
  local_20 = -1;
  iVar2 = 0;
  if (((param_1 == 0) || (param_4 == (int *)0x0)) || (param_3 < 0x14)) {
    iVar1 = -1;
  }
  else {
    iVar2 = QC_gzopen(param_1,DAT_30086ccc,param_2);
    if (iVar2 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = QC_isCompress(iVar2);
      if (iVar1 == 0) {
        iVar1 = 0;
        *param_4 = 0;
      }
      else {
        iVar1 = QC_gzgetlength(iVar2,param_3 + param_2);
        if (iVar1 < 0) {
          iVar1 = -1;
        }
        else {
          printf(DAT_30086cd4,iVar1);
          *param_4 = iVar1;
          QC_gzerror(iVar2,&local_20);
          iVar1 = local_20 >> 0x1f;
        }
      }
    }
  }
  if (iVar2 != 0) {
    QC_gzclose(iVar2);
  }
  gz_transformErr(iVar1);
  return;
}

/* ----------------------------------------------------------------
 * get_uncompress_length @ 0x30086C74  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: gzgetUncompressLength
 * Вызывают: dloadFromFsGetUnitSize
 * Константы: 0x30086C74
 * ---------------------------------------------------------------- */
void get_uncompress_length
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  gzgetUncompressLength(param_1,param_2,param_3,param_4);
  return;
}

/* ----------------------------------------------------------------
 * uncompress_file_to_stream @ 0x30086CA0  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: gzuncompressFileToStream
 * Вызывают: dloadFromFsGetUnitData
 * Константы: 0x30086CA0
 * ---------------------------------------------------------------- */
void uncompress_file_to_stream
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  gzuncompressFileToStream(param_1,param_2,param_3,param_4);
  return;
}

/* ----------------------------------------------------------------
 * QueueInit @ 0x30093818  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: memset
 * Вызывают: exchInit
 * Константы: 0x30093818
 * ---------------------------------------------------------------- */
void QueueInit(int *param_1,int param_2)

{
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  memset(param_1 + 4,0,param_2 << 2);
  return;
}

/* ----------------------------------------------------------------
 * QueueIn @ 0x30093858  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: __urem32
 * Вызывают: QueueLoopIn
 * Константы: 0x30093858, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 QueueIn(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1[3] == *param_1) {
    uVar1 = 0xffffffff;
  }
  else {
    param_1[param_1[2] + 4] = param_2;
    iVar2 = __urem32(param_1[2] + 1,*param_1);
    param_1[2] = iVar2;
    param_1[3] = param_1[3] + 1;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QueueOut @ 0x300938B4  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __urem32
 * Константы: 0x300938B4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 QueueOut(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1[3] == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    *param_2 = param_1[param_1[1] + 4];
    uVar1 = __urem32(param_1[1] + 1,*param_1);
    param_1[1] = uVar1;
    param_1[3] = param_1[3] + -1;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QueueReadLast @ 0x30093910  (примерный размер ~80 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __urem32
 * Константы: 0x30093910, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 QueueReadLast(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1[3] == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = __urem32(param_1[2] + *param_1 + -1,*param_1);
    *param_2 = param_1[iVar2 + 4];
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QueueLoopIn @ 0x30093960  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: QueueIn, __urem32
 * Вызывают: exchIntHook, exchSubIntHook, exchTaskSwitchHook
 * Константы: 0x30093960
 * ---------------------------------------------------------------- */
undefined4 QueueLoopIn(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1[3] < *param_1) {
    uVar1 = QueueIn(param_1,param_2);
  }
  else {
    param_1[param_1[2] + 4] = param_2;
    uVar2 = __urem32(param_1[2] + 1,*param_1);
    param_1[2] = uVar2;
    uVar2 = __urem32(param_1[1] + 1,*param_1);
    param_1[1] = uVar2;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * stringToHex @ 0x30093AD4  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: BSP_TRACE
 * Вызывают: exchFileSave
 * Константы: 0x30093AD4
 * Данные: DAT_30094b1c
 * ---------------------------------------------------------------- */
void stringToHex(byte *param_1,uint *param_2)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  
  uVar1 = 0;
  bVar2 = 0;
  do {
    if (7 < bVar2) {
      return;
    }
    if (*param_1 - 0x61 < 6) {
      uVar3 = *param_1 + 0xa9;
    }
    else if (*param_1 - 0x41 < 6) {
      uVar3 = *param_1 + 0xc9;
    }
    else {
      if (9 < *param_1 - 0x30) {
        BSP_TRACE(4,0x25,DAT_30094b1c,0,0,0,0,0,0);
        return;
      }
      uVar3 = *param_1 + 0xd0;
    }
    uVar1 = uVar1 | (uVar3 & 0xf) << (uint)(byte)(bVar2 * -4 + 0x1c);
    *param_2 = uVar1;
    param_1 = param_1 + 1;
    bVar2 = bVar2 + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * saveTaskStack @ 0x30094794  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: exchLogPrintf, exchStackTrace, memset
 * Вызывают: exchSave
 * Константы: 0x30094794
 * Данные: DAT_3009556c, DAT_3009569c, DAT_300956a0
 * ---------------------------------------------------------------- */
void saveTaskStack(undefined4 param_1,undefined4 param_2)

{
  void *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  memset(DAT_3009569c,0,0x800);
  local_1c = DAT_3009569c;
  local_18 = 0x800;
  local_14 = DAT_3009556c;
  exchStackTrace(param_1,&local_1c);
  *(undefined1 *)((int)DAT_3009569c + 0x7ff) = 0;
  exchLogPrintf(param_2,DAT_300956a0,DAT_3009569c);
  return;
}

/* ----------------------------------------------------------------
 * systemError @ 0x30095F38  (примерный размер ~1408 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 16
 * Вызывает: BSP_WDT_reboot_direct, CvTaskNameget, cacheFlush, excJobAdd, exchHookFuncDelete, exchSave, exchTaskShowJob, heapInfoGet, max_freeblock_size_get, memcpy, omTimerGet, omTimerTickGet, taskCpuLock, taskCpuUnlock
 *           ...
 * Вызывают: BSP_WDT_reboot, HI6451_ocp_callback, HI6451_otp_callback, exchExcHook, exchRebootSet, exchStackFlowHook, exchWdtHook, osReboot
 * Константы: 0x30095F38, 0x01000000, 0x03D00001
 * Данные: DAT_30096d74, DAT_30096d78, DAT_30096d7c, DAT_30096d80, DAT_30096d84, DAT_30096d88, DAT_30096d8c, DAT_30096d90
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

void systemError(uint param_1,void *param_2,undefined4 param_3,void *param_4,size_t param_5)

{
  int iVar1;
  undefined4 uVar2;
  void *__src;
  size_t local_3c;
  int local_38;
  int local_34 [3];
  
  local_3c = 0;
  local_34[1] = 100;
  local_38 = 0;
  local_34[0] = 0;
  local_34[2] = DAT_30096d74;
  taskCpuLock();
  exchHookFuncDelete(DAT_30096d78,DAT_30096d7c);
  *DAT_30096d80 = 0;
  if (*(int *)(*DAT_30096d84 + 0x24) == 0xff) {
    *(undefined4 *)(*DAT_30096d84 + 0x24) = 0;
  }
  if (((*DAT_30096d88 != 0) && (*DAT_30096d8c < 0x3000)) && (*DAT_30096d8c != 0)) {
    memcpy(DAT_30096d90,(void *)*DAT_30096d88,*DAT_30096d8c);
  }
  if (*DAT_30096e94 != 0) {
    __src = *(void **)(*DAT_30096d84 + 0xa0);
    if (param_4 != (void *)0x0) {
      if (0x400 < (int)param_5) {
        param_5 = 0x400;
      }
      local_3c = param_5;
      memcpy(*(void **)(*DAT_30096d84 + 0xcc),param_4,param_5);
    }
    if ((param_1 & 0x1000000) != 0) {
      __src = param_2;
    }
    iVar1 = taskIdVerify(__src);
    if (iVar1 == 0) {
      memcpy(*(void **)(*DAT_30096d84 + 200),__src,0x244);
      memcpy((void *)(*DAT_30096d84 + 0x90),*(void **)((int)__src + 0x2c),0x10);
      memcpy(*(void **)(*DAT_30096d84 + 0xdc),(void *)*DAT_30096e98,0x1000);
      if (*(int *)((int)__src + 0xc4) - *(int *)((int)__src + 200) < 0x2001) {
        local_3c = *(int *)((int)__src + 0xc4) - *(int *)((int)__src + 200);
      }
      else {
        local_3c = 0x2000;
      }
      memcpy(*(void **)(*DAT_30096d84 + 0xe0),(void *)(*(int *)((int)__src + 0xc4) - local_3c),
             local_3c);
      if (*(int *)((int)__src + 0x60) + 0xd0000000U < 0x3d00001) {
        if (*(int *)((int)__src + 0x60) - *(int *)((int)__src + 100) < 0x1001) {
          local_3c = *(int *)((int)__src + 0x60) - *(int *)((int)__src + 100);
        }
        else {
          local_3c = 0x1000;
        }
        memcpy(*(void **)(*DAT_30096d84 + 0xe4),(void *)(*(int *)((int)__src + 0x60) - local_3c),
               local_3c);
      }
    }
    CvTaskNameget(*DAT_30096f3c,local_34 + 1);
    iVar1 = excJobAdd(DAT_30096f40,__src,*(undefined4 *)(*DAT_30096d84 + 0xec),0xc000,0,0,0);
    if (iVar1 != 0) {
      exchTaskShowJob(__src,*(undefined4 *)(*DAT_30096d84 + 0xec),0xc000);
    }
    if (*DAT_30096fd8 == 0) {
      *(undefined1 *)(*DAT_30096d84 + 1) = 0x10;
    }
    else {
      *(undefined1 *)(*DAT_30096d84 + 1) = 0x80;
    }
    if (*DAT_30096fdc != 0) {
      local_3c = 0x2000;
      iVar1 = (**(code **)*DAT_30096fdc)(6,*(undefined4 *)(*DAT_30096d84 + 0xf0),&local_3c);
      if (iVar1 == 0) {
        *(undefined1 *)(*DAT_30096d84 + 0x29) = 0x55;
        *(size_t *)(*DAT_30096d84 + 0xbc) = local_3c;
      }
      else {
        *(undefined1 *)(*DAT_30096d84 + 0x29) = 0;
      }
    }
    if (*DAT_30097084 != 0) {
      local_3c = 0x8000;
      iVar1 = (**(code **)*DAT_30097084)(1,*(undefined4 *)(*DAT_30096d84 + 0xf4),&local_3c);
      if (iVar1 == 0) {
        *(undefined1 *)(*DAT_30096d84 + 0x2a) = 0x55;
        *(size_t *)(*DAT_30096d84 + 0xc0) = local_3c;
      }
      else {
        *(undefined1 *)(*DAT_30096d84 + 0x2a) = 0;
      }
    }
    *DAT_30097184 = DAT_30097188;
    *(uint *)(*DAT_30096d84 + 0x38) = param_1;
    *(void **)(*DAT_30096d84 + 0x3c) = param_2;
    *(undefined4 *)(*DAT_30096d84 + 0x40) = param_3;
    uVar2 = taskIdSelf();
    *(undefined4 *)(*DAT_30096d84 + 0x30) = uVar2;
    uVar2 = omTimerTickGet();
    *(undefined4 *)(*DAT_30096d84 + 0x34) = uVar2;
    uVar2 = omTimerGet();
    *(undefined4 *)(*DAT_30096d84 + 0x44) = uVar2;
    heapInfoGet(&local_38,local_34);
    *(int *)(*DAT_30096d84 + 0x108) = local_34[0] - local_38;
    uVar2 = max_freeblock_size_get();
    *(undefined4 *)(*DAT_30096d84 + 0x10c) = uVar2;
    cacheFlush(1,DAT_3009718c,0x5f000);
    if ((DAT_30096e94[1] & 0x80000000U) != 0) {
      if (*(int *)(*DAT_30096d84 + 0x24) != 3) {
        taskCpuUnlock();
        exchSave();
        return;
      }
      taskCpuUnlock();
      return;
    }
  }
  iVar1 = excJobAdd(DAT_300972c8,0,0,0,0,0,0);
  if (iVar1 != 0) {
    BSP_WDT_reboot_direct();
  }
  taskCpuUnlock();
  return;
}

/* ----------------------------------------------------------------
 * hexToString @ 0x300971A0  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300971A0
 * ---------------------------------------------------------------- */
void hexToString(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  
  uVar2 = 0xf;
  for (uVar3 = 0; (uVar3 & 0xff) < 8; uVar3 = uVar3 + 1) {
    uVar1 = (param_1 & uVar2) >> ((uVar3 & 0x3f) << 2);
    cVar4 = (char)uVar1;
    if ((uVar1 & 0xff) < 10) {
      cVar4 = cVar4 + '0';
    }
    else {
      cVar4 = cVar4 + '7';
    }
    *(char *)((param_2 - (uVar3 & 0xff)) + 7) = cVar4;
    uVar2 = uVar2 << 4;
  }
  return;
}

/* ----------------------------------------------------------------
 * omExchFileSave @ 0x3009720C  (примерный размер ~320 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: BSP_TRACE, exchAddToFile, exchFileSave, memset
 * Константы: 0x3009720C, 0xFFFFFFFF
 * Данные: DAT_3009750c, DAT_30097510, DAT_30097514, DAT_30097518, DAT_3009751c, DAT_30097520, DAT_30097524
 * ---------------------------------------------------------------- */
undefined4 omExchFileSave(int param_1,int param_2,char param_3,byte param_4)

{
  undefined4 uVar1;
  
  if (((param_1 == 0) || (param_2 == 0)) || (1 < param_4)) {
    BSP_TRACE(4,0x25,DAT_3009750c,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else if (*DAT_30097510 == '\0') {
    if (param_4 == 1) {
      uVar1 = exchFileSave(DAT_30097514,DAT_30097518,param_1,param_2,DAT_30097510);
    }
    else {
      uVar1 = exchFileSave(DAT_3009751c,DAT_30097520,param_1,param_2,DAT_30097510);
    }
  }
  else if (param_3 == '\0') {
    uVar1 = exchAddToFile(DAT_30097510,DAT_30097524,param_1,param_2);
  }
  else {
    uVar1 = exchAddToFile(DAT_30097510,DAT_30097524,param_1,param_2);
    memset(DAT_30097510,0,1);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * testExcFileSave @ 0x30097374  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: exchFileSave
 * Константы: 0x30097374
 * Данные: DAT_30097528, DAT_3009752c, DAT_30097530
 * ---------------------------------------------------------------- */
void testExcFileSave(void)

{
  exchFileSave(DAT_30097528,DAT_3009752c,DAT_30097530,0x200,0);
  return;
}

/* ----------------------------------------------------------------
 * ErrlogRegFunc @ 0x300977F8  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: OSAL_LogMsg
 * Константы: 0x300977F8
 * Данные: DAT_30097fc4, DAT_30097fc8
 * ---------------------------------------------------------------- */
void ErrlogRegFunc(undefined4 param_1)

{
  OSAL_LogMsg(DAT_30097fc4,0,0,0,0,0,0);
  *DAT_30097fc8 = param_1;
  return;
}

/* ----------------------------------------------------------------
 * UsbErrLog_IFCReceive @ 0x30097840  (примерный размер ~444 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: OSAL_LogMsg, printf
 * Константы: 0xFFFFFFFF, 0x30097840
 * Данные: DAT_30097fc8, DAT_30097fcc, DAT_30097fd0, DAT_30097fd4, DAT_30097fd8, DAT_30097fdc, DAT_30097fe0, DAT_30097fe4
 * ---------------------------------------------------------------- */
undefined4 UsbErrLog_IFCReceive(int *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *DAT_30097fd0 = *DAT_30097fcc;
  OSAL_LogMsg(DAT_30097fd4,param_2,(int)(char)*param_1,(int)*(char *)((int)param_1 + 1),
              (int)*(char *)((int)param_1 + 2),(int)*(char *)((int)param_1 + 3),
              (int)(char)param_1[1]);
  if (param_1 == (int *)0x0) {
    OSAL_LogMsg(DAT_30097fd8,0,0,0,0,0,0);
    uVar1 = 0xffffffff;
  }
  else {
    if (*param_1 == DAT_30097fdc) {
      if (param_2 < 0x28) {
        printf(DAT_30097fe0);
        return 0xffffffff;
      }
      if (*DAT_30097fd0 == 0) {
        OSAL_LogMsg(DAT_30097fe4,0,0,0,0,0,0);
      }
      else {
        iVar2 = (*(code *)*DAT_30097fd0)();
        param_1[9] = iVar2;
      }
      if (*DAT_30097fc8 == 0) {
        OSAL_LogMsg(DAT_30097ff4,0,0,0,0,0,0);
      }
      else {
        (*(code *)*DAT_30097fc8)
                  (DAT_30097fe8,DAT_30097fec,DAT_30097ff0,DAT_30097fdc,param_1 + 2,0x20);
      }
    }
    else {
      OSAL_LogMsg(DAT_30097ff8,*param_1,0,0,0,0,0);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * reg_save @ 0x30097A48  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30097A48
 * ---------------------------------------------------------------- */
void reg_save(undefined4 *param_1,int param_2,uint param_3)

{
  uint local_10;
  
  for (local_10 = 0; local_10 < param_3 >> 2; local_10 = local_10 + 1) {
    *param_1 = *(undefined4 *)(param_2 + local_10 * 4);
    param_1 = param_1 + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * save_task_name @ 0x30097AAC  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: CvTaskNameget
 * Вызывают: exchSaveAndRebootJob
 * Константы: 0x30097AAC
 * Данные: DAT_30098004
 * ---------------------------------------------------------------- */
void save_task_name(void)

{
  undefined4 local_8 [2];
  
  local_8[0] = 100;
  CvTaskNameget(*DAT_30098004,local_8);
  return;
}

/* ----------------------------------------------------------------
 * testExcTaskShow @ 0x30097E24  (примерный размер ~168 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 6
 * Вызывает: exchFileSave, exchRegsShow, exchTaskShow, printf, strlen, taskNameToId
 * Константы: 0x30097E24
 * Данные: DAT_30098044, DAT_30098048, DAT_3009804c, DAT_30098050, DAT_30098054, DAT_30098058
 * ---------------------------------------------------------------- */
void testExcTaskShow(char *param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  uVar2 = 0;
  local_18 = *(undefined4 *)(*DAT_30098044 + 0xec);
  local_14 = 0xc000;
  local_10 = DAT_30098048;
  sVar1 = strlen(param_1);
  if (sVar1 != 0) {
    uVar2 = taskNameToId(param_1);
  }
  printf(DAT_3009804c);
  exchRegsShow(uVar2,&local_18);
  printf(DAT_30098050);
  exchTaskShow(uVar2,&local_18);
  exchFileSave(DAT_30098054,DAT_30098058,*(undefined4 *)(*DAT_30098044 + 0xec),0xc000,0);
  return;
}

/* ----------------------------------------------------------------
 * testExcMemShow @ 0x30097ECC  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: exchFileSave, exchMemShow, printf
 * Константы: 0x30097ECC
 * Данные: DAT_30098044, DAT_30098048, DAT_3009804c, DAT_30098050, DAT_30098054, DAT_30098058
 * ---------------------------------------------------------------- */
void testExcMemShow(int param_1)

{
  int local_14 [3];
  
  local_14[0] = *(int *)(*DAT_30098044 + 0xec);
  local_14[1] = 0xc000;
  local_14[2] = DAT_30098048;
  if (param_1 == 0) {
    param_1 = local_14[0];
  }
  printf(DAT_3009804c);
  exchMemShow(param_1,0x20,4,local_14);
  printf(DAT_30098050);
  exchFileSave(DAT_30098054,DAT_30098058,*(undefined4 *)(*DAT_30098044 + 0xec),0xc000,0);
  return;
}

/* ----------------------------------------------------------------
 * omDrvInit @ 0x30098064  (примерный размер ~368 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: OM_RegisterRequestProcedure, OSAL_LogMsg, semBCreate, taskSpawn
 * Константы: 0x30098064
 * Данные: DAT_30099040, DAT_30099044, DAT_30099048, DAT_3009904c, DAT_30099050, DAT_30099054, DAT_30099058, DAT_3009905c
 * ---------------------------------------------------------------- */
void omDrvInit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = OM_RegisterRequestProcedure(0x1f,DAT_30099040);
  iVar2 = OM_RegisterRequestProcedure(0x2d,DAT_30099044);
  iVar3 = OM_RegisterRequestProcedure(0x2e,DAT_30099048);
  if (iVar3 == 0 && (iVar2 == 0 && iVar1 == 0)) {
    iVar1 = semBCreate(1,0);
    *DAT_30099050 = iVar1;
    if (*DAT_30099050 == 0) {
      OSAL_LogMsg(DAT_30099054,0,0,0,0,0,0);
    }
    else {
      iVar1 = taskSpawn(DAT_3009905c,0xdc,0,2000,DAT_30099058,0,0,0,0,0,0,0,0,0,0);
      if (iVar1 == -1) {
        OSAL_LogMsg(DAT_30099060,0,0,0,0,0,0);
      }
    }
  }
  else {
    OSAL_LogMsg(DAT_3009904c,0,0,0,0,0,0);
  }
  return;
}

/* ----------------------------------------------------------------
 * CvInfoContinue @ 0x300981D4  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: getTimeTickAndCount, memset, taskIdListGet
 * Вызывают: CvInfoReport
 * Константы: 0x300981D4
 * Данные: DAT_3009913c, DAT_30099140, DAT_30099144, DAT_30099148
 * ---------------------------------------------------------------- */
void CvInfoContinue(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  memset((void *)*DAT_3009913c,0,0x640);
  uVar1 = taskIdListGet(DAT_30099140,100);
  DAT_30099144[5] = uVar1;
  for (iVar2 = 0; iVar2 < (int)DAT_30099144[5]; iVar2 = iVar2 + 1) {
    puVar3 = (undefined1 *)(*DAT_3009913c + iVar2 * 0x10);
    uVar1 = *(undefined4 *)(DAT_30099140 + iVar2 * 4);
    puVar3[3] = (char)((uint)uVar1 >> 0x18);
    puVar3[2] = (char)((uint)uVar1 >> 0x10);
    puVar3[1] = (char)((uint)uVar1 >> 8);
    *puVar3 = (char)uVar1;
    *(int *)(*(int *)(DAT_30099140 + iVar2 * 4) + 0x1ac) = iVar2;
  }
  getTimeTickAndCount(DAT_30099144,DAT_30099148);
  DAT_30099144[2] = *DAT_30099144;
  DAT_30099144[3] = DAT_30099144[1];
  DAT_30099144[6] = 1;
  return;
}

/* ----------------------------------------------------------------
 * CvInfoReport @ 0x3009829C  (примерный размер ~540 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: CvInfoContinue, OSAL_LogMsg, free, malloc, memcpy, memset
 * Вызывают: omDrvSend
 * Константы: 0x3009829C
 * Данные: DAT_3009913c, DAT_30099144, DAT_30099208, DAT_3009920c, DAT_30099210, DAT_30099214, DAT_30099218, DAT_300993e0
 * ---------------------------------------------------------------- */
void CvInfoReport(void)

{
  undefined1 *__s;
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(int *)(DAT_30099144 + 0x14) == 0) {
    OSAL_LogMsg(DAT_30099208,0,0,0,0,0,0);
  }
  else if (*DAT_3009920c == 0) {
    OSAL_LogMsg(DAT_30099210,0,0,0,0,0,0);
  }
  else {
    uVar1 = *(int *)(DAT_30099144 + 0x14) * 0x10 + 0x2c;
    __s = (undefined1 *)malloc(uVar1 & 0xffff);
    if (__s == (undefined1 *)0x0) {
      OSAL_LogMsg(DAT_30099214,0,0,0,0,0,0);
    }
    else {
      memset(__s,0,0x3c);
      *__s = 0x1f;
      uVar2 = uVar1 + DAT_30099218 & 0xffff;
      __s[3] = (char)(uVar2 >> 8);
      __s[2] = (char)uVar2;
      __s[7] = 0;
      __s[6] = 0;
      __s[5] = 0x90;
      __s[4] = 0;
      iVar3 = (uVar1 & 0xffff) - 0x20;
      __s[0x1f] = (char)((uint)iVar3 >> 0x18);
      __s[0x1e] = (char)((uint)iVar3 >> 0x10);
      __s[0x1d] = (char)((uint)iVar3 >> 8);
      __s[0x1c] = (char)iVar3;
      uVar4 = *(undefined4 *)(DAT_30099144 + 0x14);
      __s[0x2b] = (char)((uint)uVar4 >> 0x18);
      __s[0x2a] = (char)((uint)uVar4 >> 0x10);
      __s[0x29] = (char)((uint)uVar4 >> 8);
      __s[0x28] = (char)uVar4;
      memcpy(__s + 0x2c,(void *)*DAT_3009913c,*(int *)(DAT_30099144 + 0x14) << 4);
      iVar3 = (*(code *)*DAT_3009920c)(__s,uVar1 & 0xffff);
      if (iVar3 != 0) {
        OSAL_LogMsg(DAT_300993e0,0,0,0,0,0,0);
      }
      free(__s);
      CvInfoContinue();
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * omDrvSend @ 0x300984B8  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: CvInfoReport, semTake
 * Константы: 0x300984B8, 0xFFFFFFFF
 * Данные: DAT_30099050, DAT_30099144
 * ---------------------------------------------------------------- */
void omDrvSend(void)

{
  do {
    do {
      semTake(*DAT_30099050,0xffffffff);
    } while (*(int *)(DAT_30099144 + 0x1c) == 0);
    CvInfoReport();
  } while( true );
}

/* ----------------------------------------------------------------
 * omDrvTraceReqEntry @ 0x300984E4  (примерный размер ~600 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: OM_AddSNTime, OSAL_LogMsg, free, malloc, memcpy
 * Константы: 0x300984E4
 * Данные: DAT_30099218, DAT_300993e4, DAT_300993e8, DAT_30099420, DAT_30099424, DAT_30099428
 * ---------------------------------------------------------------- */
void omDrvTraceReqEntry(int param_1,code *param_2)

{
  undefined2 uVar1;
  undefined1 *__ptr;
  int iVar2;
  uint uVar3;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_30 = 0;
  local_2c = 0;
  if ((param_1 == 0) || (param_2 == (code *)0x0)) {
    OSAL_LogMsg(DAT_300993e4,0,0,0,0,0,0);
  }
  else if (*(ushort *)(param_1 + 4) == DAT_300993e8) {
    __ptr = (undefined1 *)malloc(0x130);
    if (__ptr == (undefined1 *)0x0) {
      OSAL_LogMsg(DAT_30099420,0,0,0,0,0,0);
    }
    else {
      memcpy(__ptr + 0x14,DAT_30099424,0x11c);
      __ptr[0xd] = 0x91;
      __ptr[0xc] = 2;
      __ptr[0x13] = 0;
      __ptr[0x12] = 0;
      __ptr[0x11] = 0;
      __ptr[0x10] = 0x25;
      uVar3 = DAT_30099218 + 0x130U & 0xffff;
      __ptr[3] = (char)(uVar3 >> 8);
      __ptr[2] = (char)uVar3;
      *__ptr = 0x2d;
      uVar1 = *(undefined2 *)(param_1 + 6);
      __ptr[0xf] = (char)((ushort)uVar1 >> 8);
      __ptr[0xe] = (char)uVar1;
      local_30 = *(undefined4 *)(__ptr + 4);
      local_2c = *(undefined4 *)(__ptr + 8);
      OM_AddSNTime(&local_30,&local_2c);
      iVar2 = (*param_2)(__ptr,0x130);
      if (iVar2 != 0) {
        OSAL_LogMsg(DAT_30099428,0,0,0,0,0,0);
      }
      if (__ptr != (undefined1 *)0x0) {
        free(__ptr);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * CvTaskNameget @ 0x3009873C  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 4
 * Вызывает: memset, strncpy, taskIdListGet, taskName
 * Вызывают: omDrvCpuViewReqEntry, save_task_name, systemError
 * Константы: 0x3009873C
 * Данные: DAT_30099140
 * ---------------------------------------------------------------- */
void CvTaskNameget(void *param_1,uint *param_2)

{
  uint uVar1;
  char *__src;
  uint uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  if ((param_1 != (void *)0x0) && (param_2 != (uint *)0x0)) {
    memset(param_1,0,0x640);
    uVar1 = taskIdListGet(DAT_30099140,100);
    if (uVar1 <= *param_2) {
      for (uVar2 = 0; uVar2 < uVar1; uVar2 = uVar2 + 1) {
        puVar3 = (undefined1 *)((int)param_1 + uVar2 * 0x10);
        uVar4 = *(undefined4 *)(DAT_30099140 + uVar2 * 4);
        puVar3[3] = (char)((uint)uVar4 >> 0x18);
        puVar3[2] = (char)((uint)uVar4 >> 0x10);
        puVar3[1] = (char)((uint)uVar4 >> 8);
        *puVar3 = (char)uVar4;
        __src = (char *)taskName(*(undefined4 *)(DAT_30099140 + uVar2 * 4));
        strncpy((char *)((int)param_1 + uVar2 * 0x10 + 4),__src,0xb);
      }
      *param_2 = uVar1;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * CvInfoStart @ 0x30098804  (примерный размер ~288 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: getTimeTickAndCount, memset, taskIdListGet, taskSwitchHookAdd
 * Вызывают: exchWdtHook, omDrvCpuViewReqEntry
 * Константы: 0x30098804
 * Данные: DAT_3009913c, DAT_30099140, DAT_30099144, DAT_30099148, DAT_3009942c
 * ---------------------------------------------------------------- */
void CvInfoStart(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  memset((void *)*DAT_3009913c,0,0x640);
  uVar1 = taskIdListGet(DAT_30099140,100);
  DAT_30099144[5] = uVar1;
  for (iVar2 = 0; iVar2 < (int)DAT_30099144[5]; iVar2 = iVar2 + 1) {
    puVar3 = (undefined1 *)(*DAT_3009913c + iVar2 * 0x10);
    uVar1 = *(undefined4 *)(DAT_30099140 + iVar2 * 4);
    puVar3[3] = (char)((uint)uVar1 >> 0x18);
    puVar3[2] = (char)((uint)uVar1 >> 0x10);
    puVar3[1] = (char)((uint)uVar1 >> 8);
    *puVar3 = (char)uVar1;
    iVar4 = *DAT_3009913c + iVar2 * 0x10;
    uVar1 = *(undefined4 *)(*(int *)(DAT_30099140 + iVar2 * 4) + 0x74);
    *(char *)(iVar4 + 0xf) = (char)((uint)uVar1 >> 0x18);
    *(char *)(iVar4 + 0xe) = (char)((uint)uVar1 >> 0x10);
    *(char *)(iVar4 + 0xd) = (char)((uint)uVar1 >> 8);
    *(char *)(iVar4 + 0xc) = (char)uVar1;
    *(int *)(*(int *)(DAT_30099140 + iVar2 * 4) + 0x1ac) = iVar2;
  }
  taskSwitchHookAdd(DAT_3009942c);
  getTimeTickAndCount(DAT_30099144,DAT_30099148);
  DAT_30099144[2] = *DAT_30099144;
  DAT_30099144[3] = DAT_30099144[1];
  DAT_30099144[4] = param_1;
  DAT_30099144[7] = param_2;
  DAT_30099144[6] = 1;
  return;
}

/* ----------------------------------------------------------------
 * CvInfoStop @ 0x30098924  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskSwitchHookDelete
 * Вызывают: omDrvCpuViewReqEntry
 * Константы: 0x30098924
 * Данные: DAT_30099144, DAT_3009942c
 * ---------------------------------------------------------------- */
void CvInfoStop(void)

{
  taskSwitchHookDelete(DAT_3009942c);
  *DAT_30099144 = 0;
  DAT_30099144[1] = 0;
  DAT_30099144[2] = 0;
  DAT_30099144[3] = 0;
  DAT_30099144[4] = 0;
  DAT_30099144[7] = 0;
  DAT_30099144[6] = 0;
  return;
}

/* ----------------------------------------------------------------
 * omDrvCpuViewReqEntry @ 0x30098988  (примерный размер ~868 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: CvInfoStart, CvInfoStop, CvTaskNameget, OSAL_LogMsg, free, malloc, memcpy, sysClkRateGet
 * Константы: 0x30098988
 * Данные: DAT_3009920c, DAT_30099218, DAT_30099430, DAT_30099434, DAT_30099438, DAT_3009943c, DAT_30099440, DAT_30099444
 * ---------------------------------------------------------------- */
void omDrvCpuViewReqEntry(int param_1,code *param_2)

{
  undefined1 *__ptr;
  int iVar1;
  uint uVar2;
  int local_30;
  uint local_2c;
  
  local_30 = 100;
  if ((param_1 == 0) || (param_2 == (code *)0x0)) {
    OSAL_LogMsg(DAT_30099430,0,0,0,0,0,0);
  }
  else if (*(ushort *)(param_1 + 2) < 0x1c) {
    OSAL_LogMsg(DAT_30099434,0,0,0,0,0,0);
  }
  else {
    *DAT_3009920c = param_2;
    if (*(int *)(param_1 + 4) == 0x9000) {
      if (*(int *)(param_1 + 0x20) == 0) {
        CvInfoStop();
      }
      else {
        iVar1 = sysClkRateGet();
        CvInfoStart(*(int *)(param_1 + 0x20) * iVar1,1);
      }
    }
    else if (*(int *)(param_1 + 4) == DAT_30099438) {
      CvTaskNameget(*DAT_3009943c,&local_30);
      uVar2 = local_30 * 0x10 + 0x24;
      __ptr = (undefined1 *)malloc(uVar2 & 0xffff);
      if (__ptr == (undefined1 *)0x0) {
        OSAL_LogMsg(DAT_30099440,0,0,0,0,0,0);
      }
      else {
        __ptr[7] = 0;
        __ptr[6] = 0;
        __ptr[5] = 0x90;
        __ptr[4] = 7;
        __ptr[0xb] = 0;
        __ptr[10] = 0;
        __ptr[9] = 0;
        __ptr[8] = 0;
        __ptr[0xf] = 0;
        __ptr[0xe] = 0;
        __ptr[0xd] = 0;
        __ptr[0xc] = 0;
        iVar1 = local_30 * 0x10 + 4;
        __ptr[0x1f] = (char)((uint)iVar1 >> 0x18);
        __ptr[0x1e] = (char)((uint)iVar1 >> 0x10);
        __ptr[0x1d] = (char)((uint)iVar1 >> 8);
        __ptr[0x1c] = (char)iVar1;
        __ptr[0x23] = (char)((uint)local_30 >> 0x18);
        __ptr[0x22] = (char)((uint)local_30 >> 0x10);
        __ptr[0x21] = (char)((uint)local_30 >> 8);
        __ptr[0x20] = (char)local_30;
        memcpy(__ptr + 0x24,(void *)*DAT_3009943c,local_30 << 4);
        local_2c = uVar2 + DAT_30099218 & 0xffff;
        __ptr[3] = (char)(local_2c >> 8);
        __ptr[2] = (char)local_2c;
        *__ptr = 0x1f;
        iVar1 = (*param_2)(__ptr,uVar2 & 0xffff);
        if (iVar1 != 0) {
          OSAL_LogMsg(DAT_30099444,0,0,0,0,0,0);
        }
        free(__ptr);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * omDrvMemRead @ 0x30098CEC  (примерный размер ~432 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: omDrvQueryReqEntry
 * Константы: 0x30098CEC, 0x30000000
 * Данные: DAT_30099448
 * ---------------------------------------------------------------- */
void omDrvMemRead(int *param_1,undefined1 *param_2)

{
  int iVar1;
  uint uVar2;
  
  for (uVar2 = 0; uVar2 < (uint)param_1[1]; uVar2 = uVar2 + 1) {
    if ((uVar2 + *param_1 < 0x30000000) || (DAT_30099448 <= uVar2 + *param_1)) {
      param_2[uVar2 * 2 + 0xc] = 1;
    }
    else {
      param_2[uVar2 * 2 + 0xc] = 0;
      param_2[uVar2 * 2 + 0xd] = *(undefined1 *)(uVar2 + *param_1);
    }
  }
  iVar1 = *param_1;
  param_2[7] = (char)((uint)iVar1 >> 0x18);
  param_2[6] = (char)((uint)iVar1 >> 0x10);
  param_2[5] = (char)((uint)iVar1 >> 8);
  param_2[4] = (char)iVar1;
  iVar1 = param_1[1];
  param_2[0xb] = (char)((uint)iVar1 >> 0x18);
  param_2[10] = (char)((uint)iVar1 >> 0x10);
  param_2[9] = (char)((uint)iVar1 >> 8);
  param_2[8] = (char)iVar1;
  param_2[3] = 0;
  param_2[2] = 0;
  param_2[1] = 0;
  *param_2 = 0;
  return;
}

/* ----------------------------------------------------------------
 * omDrvMemWrite @ 0x30098E9C  (примерный размер ~540 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: memcpy
 * Вызывают: omDrvQueryReqEntry
 * Константы: 0x30098E9C, 0x30000000
 * Данные: DAT_30099448
 * ---------------------------------------------------------------- */
void omDrvMemWrite(uint *param_1,undefined1 *param_2)

{
  uint uVar1;
  
  if ((*param_1 < 0x30000000) || (DAT_30099448 < *param_1 + param_1[1])) {
    param_2[3] = 0;
    param_2[2] = 0;
    param_2[1] = 0;
    *param_2 = 1;
  }
  else {
    memcpy((void *)*param_1,param_1 + 2,param_1[1]);
    param_2[3] = 0;
    param_2[2] = 0;
    param_2[1] = 0;
    *param_2 = 0;
  }
  uVar1 = *param_1;
  param_2[7] = (char)(uVar1 >> 0x18);
  param_2[6] = (char)(uVar1 >> 0x10);
  param_2[5] = (char)(uVar1 >> 8);
  param_2[4] = (char)uVar1;
  uVar1 = param_1[1];
  param_2[0xb] = (char)(uVar1 >> 0x18);
  param_2[10] = (char)(uVar1 >> 0x10);
  param_2[9] = (char)(uVar1 >> 8);
  param_2[8] = (char)uVar1;
  memcpy(param_2 + 0xc,param_1 + 2,param_1[1]);
  return;
}

/* ----------------------------------------------------------------
 * omDrvQueryReqEntry @ 0x300990B8  (примерный размер ~844 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: OSAL_LogMsg, free, malloc, omDrvMemRead, omDrvMemWrite
 * Константы: 0x300990B8
 * Данные: DAT_3009944c, DAT_30099450, DAT_30099454, DAT_30099458, DAT_3009945c, DAT_30099460, DAT_30099464
 * ---------------------------------------------------------------- */
void omDrvQueryReqEntry(int param_1,code *param_2)

{
  undefined2 uVar1;
  undefined1 *__ptr;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 == 0) || (param_2 == (code *)0x0)) {
    OSAL_LogMsg(DAT_3009944c,0,0,0,0,0,0);
    return;
  }
  uVar4 = (uint)*(ushort *)(param_1 + 4);
  if (uVar4 == DAT_30099450) {
    uVar4 = (uint)*(ushort *)(param_1 + 0xc) * 2 + 0x14;
    __ptr = (undefined1 *)malloc(uVar4 & 0xffff);
    if (__ptr == (undefined1 *)0x0) {
      OSAL_LogMsg(DAT_3009945c,0,0,0,0,0,0);
      return;
    }
    omDrvMemRead(param_1 + 8,__ptr + 8);
    __ptr[5] = 0x92;
    __ptr[4] = 2;
  }
  else if (uVar4 == DAT_30099454) {
    uVar4 = 0x18;
    __ptr = (undefined1 *)malloc(0x18);
    if (__ptr == (undefined1 *)0x0) {
      OSAL_LogMsg(DAT_3009945c,0,0,0,0,0,0);
      return;
    }
    omDrvMemWrite(param_1 + 8,__ptr + 8);
    __ptr[5] = 0x92;
    __ptr[4] = 4;
  }
  else {
    if (uVar4 != DAT_30099458) {
      return;
    }
    uVar4 = 0xc;
    __ptr = (undefined1 *)malloc(0xc);
    if (__ptr == (undefined1 *)0x0) {
      OSAL_LogMsg(DAT_3009945c,0,0,0,0,0,0);
      return;
    }
    __ptr[5] = 0x92;
    __ptr[4] = 6;
  }
  uVar3 = uVar4 + DAT_30099460 & 0xffff;
  __ptr[3] = (char)(uVar3 >> 8);
  __ptr[2] = (char)uVar3;
  *__ptr = 0x2e;
  uVar1 = *(undefined2 *)(param_1 + 6);
  __ptr[7] = (char)((ushort)uVar1 >> 8);
  __ptr[6] = (char)uVar1;
  iVar2 = (*param_2)(__ptr,uVar4 & 0xffff);
  if (iVar2 != 0) {
    OSAL_LogMsg(DAT_30099464,0,0,0,0,0,0);
  }
  if (__ptr != (undefined1 *)0x0) {
    free(__ptr);
  }
  return;
}

/* ----------------------------------------------------------------
 * CvTaskStatusSwitch @ 0x30099404  (примерный размер ~348 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: CvAnnounce
 * Константы: 0x30099404, 0x3009941C
 * Данные: DAT_30099468
 * ---------------------------------------------------------------- */
undefined4 CvTaskStatusSwitch(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x18) {
                    /* WARNING: Could not recover jumptable at 0x3009941c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_30099468 + param_1 * 4))();
    return uVar1;
  }
  return 0x74;
}

/* ----------------------------------------------------------------
 * CvAnnounce @ 0x30099560  (примерный размер ~340 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: CvTaskStatusSwitch, getTimeTickAndCount, semGive
 * Константы: 0x30099560
 * Данные: DAT_30099798, DAT_3009979c, DAT_300997a0
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

void CvAnnounce(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 0;
  if ((DAT_30099798[6] != 0) &&
     (getTimeTickAndCount(local_28,local_28 + 1),
     (uint)(*DAT_30099798 + DAT_30099798[4]) <= local_28[0])) {
    DAT_30099798[6] = 0;
    for (uVar2 = 0; uVar2 < (uint)DAT_30099798[5]; uVar2 = uVar2 + 1) {
      piVar1 = (int *)(*DAT_3009979c + uVar2 * 0x10);
      uVar3 = *(undefined4 *)(*piVar1 + 0x74);
      *(char *)((int)piVar1 + 0xf) = (char)((uint)uVar3 >> 0x18);
      *(char *)((int)piVar1 + 0xe) = (char)((uint)uVar3 >> 0x10);
      *(char *)((int)piVar1 + 0xd) = (char)((uint)uVar3 >> 8);
      *(char *)(piVar1 + 3) = (char)uVar3;
      uVar3 = CvTaskStatusSwitch(*(undefined4 *)(*piVar1 + 0x70));
      *(char *)((int)piVar1 + 0xb) = (char)((uint)uVar3 >> 0x18);
      *(char *)((int)piVar1 + 10) = (char)((uint)uVar3 >> 0x10);
      *(char *)((int)piVar1 + 9) = (char)((uint)uVar3 >> 8);
      *(char *)(piVar1 + 2) = (char)uVar3;
    }
    if (DAT_30099798[7] != 0) {
      semGive(*DAT_300997a0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * CvTaskSwitchHook @ 0x300996B4  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: getTimeTickAndCount
 * Константы: 0x300996B4
 * Данные: DAT_30099798, DAT_3009979c, DAT_300997a4
 * ---------------------------------------------------------------- */
void CvTaskSwitchHook(int param_1)

{
  int iVar1;
  int iVar2;
  int local_20;
  int local_1c;
  
  local_20 = 0;
  local_1c = 0;
  if (*(int *)(DAT_30099798 + 0x18) != 0) {
    getTimeTickAndCount(&local_20,&local_1c);
    iVar1 = *DAT_3009979c + *(int *)(param_1 + 0x1ac) * 0x10;
    iVar2 = *(int *)(iVar1 + 4) +
            (((local_20 - *(int *)(DAT_30099798 + 8)) * DAT_300997a4 + local_1c) -
            *(int *)(DAT_30099798 + 0xc));
    *(char *)(iVar1 + 7) = (char)((uint)iVar2 >> 0x18);
    *(char *)(iVar1 + 6) = (char)((uint)iVar2 >> 0x10);
    *(char *)(iVar1 + 5) = (char)((uint)iVar2 >> 8);
    *(char *)(iVar1 + 4) = (char)iVar2;
    *(int *)(DAT_30099798 + 8) = local_20;
    *(int *)(DAT_30099798 + 0xc) = local_1c;
  }
  return;
}

/* ----------------------------------------------------------------
 * osReboot @ 0x300997B8  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: systemError
 * Константы: 0x300997B8
 * ---------------------------------------------------------------- */
void osReboot(void)

{
  systemError(0x25,2,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * heapInfoGet @ 0x300997E4  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: memInfoGet
 * Вызывают: systemError
 * Константы: 0x300997E4, 0xFFFFFFFF
 * Данные: DAT_30099cb8
 * ---------------------------------------------------------------- */
undefined4 heapInfoGet(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar6;
  int local_24 [6];
  undefined4 *puVar5;
  
  piVar3 = local_24;
  iVar6 = 3;
  puVar4 = DAT_30099cb8;
  do {
    puVar5 = puVar4 + 1;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 2;
    uVar2 = *puVar5;
    iVar6 = iVar6 + -1;
    puVar5 = piVar3 + 1;
    *piVar3 = uVar1;
    piVar3 = piVar3 + 2;
    *puVar5 = uVar2;
  } while (iVar6 != 0);
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else {
    memInfoGet(local_24,uVar2,local_24);
    *param_1 = local_24[3];
    *param_2 = local_24[3] + local_24[0];
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * omTimerGet @ 0x30099864  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 0
 * Вызывают: FUN_30062d44, exchHookFuncDelete, exchIntHook, exchSubIntHook, exchTaskSwitchHook, omTimerTickGet, systemError
 * Константы: 0x30099864
 * Данные: DAT_30099cbc
 * ---------------------------------------------------------------- */
undefined4 omTimerGet(void)

{
  return *DAT_30099cbc;
}

/* ----------------------------------------------------------------
 * omTimerTickGet @ 0x30099870  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 29 | Вызывает: 2
 * Вызывает: __mul64, omTimerGet
 * Вызывают: DCBInit, FUN_30080798, FUN_30081f50, FUN_300827c0, ImageDloadToFlash, ImageDloadToRam, dloadDealBootrom, dloadFromFsCheckSpaceForISO, dloadFromFsGetUnitData, dloadFromFsGetUnitSize
 *           ...
 * Константы: 0x30099870
 * ---------------------------------------------------------------- */
uint omTimerTickGet(void)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = omTimerGet();
  uVar2 = __mul64(-1 - iVar1,0,100,0);
  return (uint)uVar2 >> 0xf | (int)((ulonglong)uVar2 >> 0x20) << 0x11;
}

/* ----------------------------------------------------------------
 * max_freeblock_size_get @ 0x3009990C  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: OSAL_LogMsg, memPartInfoGet, memset
 * Вызывают: systemError
 * Константы: 0x3009990C
 * Данные: DAT_30099cc0, DAT_30099cc4
 * ---------------------------------------------------------------- */
undefined4 max_freeblock_size_get(void)

{
  int iVar1;
  undefined1 auStack_1c [8];
  undefined4 local_14;
  
  memset(auStack_1c,0,0x18);
  iVar1 = memPartInfoGet(*DAT_30099cc0,auStack_1c);
  if (iVar1 != 0) {
    OSAL_LogMsg(DAT_30099cc4,1,2,3,4,5,6);
    local_14 = 0;
  }
  return local_14;
}

/* ----------------------------------------------------------------
 * OM_RegisterRequestProcedure @ 0x30099984  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: omDrvInit
 * Константы: 0x30099984
 * ---------------------------------------------------------------- */
undefined4 OM_RegisterRequestProcedure(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * OM_AddSNTime @ 0x3009998C  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: omDrvTraceReqEntry
 * Константы: 0x3009998C
 * ---------------------------------------------------------------- */
void OM_AddSNTime(void)

{
  return;
}

/* ----------------------------------------------------------------
 * Mem16Check3Step1st @ 0x30099990  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Mem16Check3StepEntry
 * Константы: 0xFFFFFFFE, 0x30099990
 * Данные: DAT_30099cc8, DAT_30099ccc
 * ---------------------------------------------------------------- */
ushort * Mem16Check3Step1st(int param_1,int param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar2 = (ushort *)
           (param_1 + (uint)((ulonglong)DAT_30099cc8 * (ulonglong)(uint)(param_2 - param_1) >> 0x21)
           & 0xfffffffe);
  puVar1 = (ushort *)
           (param_2 - (uint)((ulonglong)DAT_30099cc8 * (ulonglong)(uint)(param_2 - param_1) >> 0x21)
           & 0xfffffffe);
  *puVar2 = 0;
  *puVar1 = (ushort)DAT_30099ccc;
  if ((*puVar2 == 0) && (puVar2 = puVar1, *puVar1 == DAT_30099ccc)) {
    puVar2 = (ushort *)0x0;
  }
  return puVar2;
}

/* ----------------------------------------------------------------
 * Mem16Check3Step2nd @ 0x30099A28  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Mem16Check3StepEntry
 * Константы: 0x30099A28
 * ---------------------------------------------------------------- */
ushort * Mem16Check3Step2nd(ushort *param_1)

{
  uint uVar1;
  
  for (uVar1 = 1; (uVar1 & 0xffff) != 0; uVar1 = (uVar1 << 0x10) >> 0xf) {
    *param_1 = (ushort)uVar1;
    if ((uint)*param_1 != (uVar1 & 0xffff)) {
      return param_1;
    }
  }
  uVar1 = 1;
  while( true ) {
    if ((uVar1 & 0xffff) == 0) {
      return (ushort *)0x0;
    }
    *param_1 = (ushort)~uVar1;
    if ((uint)*param_1 != (~uVar1 & 0xffff)) break;
    uVar1 = (uVar1 << 0x10) >> 0xf;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * Mem16Check3Step3rd @ 0x30099ABC  (примерный размер ~212 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Mem16Check3StepEntry
 * Константы: 0x30099ABC
 * Данные: DAT_30099ccc
 * ---------------------------------------------------------------- */
ushort * Mem16Check3Step3rd(ushort *param_1,int param_2)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (param_2 - (int)param_1) - 1;
  *param_1 = (ushort)DAT_30099ccc;
  for (uVar3 = 2; uVar3 <= uVar2; uVar3 = uVar3 << 1) {
    *(ushort *)((int)param_1 + uVar3) = ~(ushort)uVar3;
    if (*param_1 != DAT_30099ccc) {
      return (ushort *)((int)param_1 + uVar3);
    }
  }
  *(ushort *)(param_2 + -1) = (ushort)DAT_30099ccc;
  uVar3 = 2;
  while( true ) {
    if (uVar2 < uVar3) {
      return (ushort *)0x0;
    }
    puVar1 = (ushort *)((int)param_1 + (~uVar3 & (param_2 - (int)param_1) - 2U));
    *puVar1 = (ushort)~uVar3;
    if (*(ushort *)(param_2 + -1) != DAT_30099ccc) break;
    uVar3 = uVar3 << 1;
  }
  return puVar1;
}

/* ----------------------------------------------------------------
 * Mem16Check3StepParam @ 0x30099B90  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: Mem16Check3StepEntry
 * Константы: 0x30099B90
 * ---------------------------------------------------------------- */
uint Mem16Check3StepParam(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = 0;
  uVar4 = param_2 - param_1;
  for (uVar1 = uVar4; uVar1 != 0; uVar1 = uVar1 >> 1) {
    uVar2 = uVar2 + (uVar1 & 1);
  }
  if (uVar2 < 2) {
    iVar3 = 0;
    uVar1 = param_1;
    for (; uVar4 != 0; uVar4 = uVar4 >> 1) {
      uVar1 = uVar1 >> 1;
      iVar3 = iVar3 + 1;
    }
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      uVar1 = uVar1 << 1;
    }
    if (uVar1 == param_1) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * Mem16Check3StepEntry @ 0x30099C24  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: Mem16Check3Step1st, Mem16Check3Step2nd, Mem16Check3Step3rd, Mem16Check3StepParam
 * Константы: 0x30099C24, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 Mem16Check3StepEntry(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Mem16Check3StepParam(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = Mem16Check3Step1st(param_1,param_2);
    if (iVar1 == 0) {
      iVar1 = Mem16Check3Step2nd(param_1);
      if (iVar1 == 0) {
        iVar1 = Mem16Check3Step3rd(param_1,param_2);
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 3;
        }
      }
      else {
        uVar2 = 2;
      }
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
 * cfg_GetUeSoftPrivateVer @ 0x30099E74  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099E74, 0xFFFFFFFF
 * Данные: DAT_30099ec0
 * ---------------------------------------------------------------- */
undefined4 cfg_GetUeSoftPrivateVer(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = DAT_30099ec0;
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  param_1[2] = *(undefined4 *)(DAT_30099ec0 + 0x44);
  *param_1 = *(undefined4 *)(iVar1 + 0x3c);
  param_1[1] = *(undefined4 *)(iVar1 + 0x40);
  return 0;
}

/* ----------------------------------------------------------------
 * cfg_GetMspBuildVersion @ 0x30099EA8  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099EA8
 * Данные: DAT_30099ec4
 * ---------------------------------------------------------------- */
undefined4 cfg_GetMspBuildVersion(void)

{
  return DAT_30099ec4;
}

/* ----------------------------------------------------------------
 * cfg_GetUeSoftRevisionVersion @ 0x30099EB0  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099EB0
 * Данные: DAT_30099ec0
 * ---------------------------------------------------------------- */
undefined4 cfg_GetUeSoftRevisionVersion(void)

{
  return *(undefined4 *)(DAT_30099ec0 + 0x40);
}

/* ----------------------------------------------------------------
 * MSP_GetVersion @ 0x30099EBC  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099EBC
 * ---------------------------------------------------------------- */
void MSP_GetVersion(void)

{
  return;
}

/* ----------------------------------------------------------------
 * OSA_CacheDmaMalloc @ 0x30099EC8  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099EC8, 0x00100000
 * Данные: DAT_30099f64
 * ---------------------------------------------------------------- */
undefined4 OSA_CacheDmaMalloc(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (0x100000 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_30099f64)();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * OSA_CdmCacheDmaMalloc @ 0x30099EF4  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099EF4, 0x00200000
 * Данные: DAT_30099f64
 * ---------------------------------------------------------------- */
undefined4 OSA_CdmCacheDmaMalloc(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (0x200000 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_30099f64)();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * OSA_Phys2Virt @ 0x30099F20  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099F20
 * ---------------------------------------------------------------- */
int OSA_Phys2Virt(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = param_1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * OSA_Virt2Phys @ 0x30099F34  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099F34
 * ---------------------------------------------------------------- */
int OSA_Virt2Phys(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = param_1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * OSM_TaskDelay @ 0x30099F48  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099F48
 * Данные: DAT_30099f68
 * ---------------------------------------------------------------- */
void OSM_TaskDelay(int param_1)

{
  if (param_1 != 0) {
    (*DAT_30099f68)();
  }
  return;
}

/* ----------------------------------------------------------------
 * OSA_HeapAllocD @ 0x30099F6C  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099F6C, 0x00100000
 * Данные: DAT_3009a178
 * ---------------------------------------------------------------- */
undefined4 OSA_HeapAllocD(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (0x100000 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_3009a178)();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * OSA_HeapFreeD @ 0x30099F98  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099F98
 * Данные: DAT_3009a17c
 * ---------------------------------------------------------------- */
void OSA_HeapFreeD(int param_1)

{
  if (param_1 != 0) {
    (*DAT_3009a17c)();
  }
  return;
}

/* ----------------------------------------------------------------
 * OSM_CreateSemaphoreVx @ 0x30099FB4  (примерный размер ~224 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30099FB4, 0xFFFFFFFF
 * Данные: DAT_3009a180, DAT_3009a184, DAT_3009a188, DAT_3009a18c
 * ---------------------------------------------------------------- */
int OSM_CreateSemaphoreVx(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 < param_1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    if (param_2 == 1) {
      iVar1 = (*DAT_3009a180)(0,param_1 != 0);
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      iVar1 = (*DAT_3009a184)(0,param_2);
      if (iVar1 == 0) {
        return 0;
      }
      if (param_2 != param_1) {
        iVar2 = param_2 - param_1;
        do {
          (*DAT_3009a188)(iVar1,0xffffffff);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    if (iVar1 != 0) {
      (*DAT_3009a18c)(0x16,iVar1,param_1,param_2);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * OSM_WaitForSemaphoreVx @ 0x3009A094  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x3009A094
 * Данные: DAT_3009a188, DAT_3009a190
 * ---------------------------------------------------------------- */
undefined4 OSM_WaitForSemaphoreVx(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_3009a190;
  if ((param_1 != 0) && (iVar1 = (*DAT_3009a188)(param_1,0xffffffff), uVar2 = 0, iVar1 != 0)) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * OSM_SignalSemaphoreVx @ 0x3009A0D4  (примерный размер ~60 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A0D4, 0xFFFFFFFF
 * Данные: DAT_3009a190, DAT_3009a194
 * ---------------------------------------------------------------- */
undefined4 OSM_SignalSemaphoreVx(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_3009a190;
  if ((param_1 != 0) && (iVar1 = (*DAT_3009a194)(), uVar2 = 0, iVar1 != 0)) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * OSM_wdCreate @ 0x3009A110  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A110
 * Данные: DAT_3009a198
 * ---------------------------------------------------------------- */
void OSM_wdCreate(void)

{
  (*DAT_3009a198)();
  return;
}

/* ----------------------------------------------------------------
 * OSM_wdStart @ 0x3009A124  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x3009A124
 * Данные: DAT_3009a19c
 * ---------------------------------------------------------------- */
undefined4 OSM_wdStart(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = (*DAT_3009a19c)();
    if (iVar2 == -1) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * OSM_wdStop @ 0x3009A154  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A154
 * Данные: DAT_3009a1a0
 * ---------------------------------------------------------------- */
void OSM_wdStop(int param_1)

{
  if (param_1 != 0) {
    (*DAT_3009a1a0)();
  }
  return;
}

/* ----------------------------------------------------------------
 * OSM_SYNC_Wait @ 0x3009A170  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A170
 * ---------------------------------------------------------------- */
void OSM_SYNC_Wait(void)

{
  return;
}

/* ----------------------------------------------------------------
 * OSM_SYNC_Give @ 0x3009A174  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A174
 * ---------------------------------------------------------------- */
void OSM_SYNC_Give(void)

{
  return;
}

/* ----------------------------------------------------------------
 * sda_SdmDiagGetInfo @ 0x3009A1A4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A1A4
 * Данные: DAT_3009a220
 * ---------------------------------------------------------------- */
undefined4 sda_SdmDiagGetInfo(void)

{
  return DAT_3009a220;
}

/* ----------------------------------------------------------------
 * sda_DiagSysDebug @ 0x3009A1AC  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A1AC
 * Данные: DAT_3009a220
 * ---------------------------------------------------------------- */
void sda_DiagSysDebug(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 * 0x14 + DAT_3009a220);
  *piVar1 = *piVar1 + 1;
  piVar1[1] = param_2;
  piVar1[2] = param_3;
  piVar1[3] = param_4;
  return;
}

/* ----------------------------------------------------------------
 * sda_DiagSysDebugEx @ 0x3009A1E0  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A1E0
 * Данные: DAT_3009a220, DAT_3009a224
 * ---------------------------------------------------------------- */
undefined4 sda_DiagSysDebugEx(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = DAT_3009a220;
  *(undefined4 *)(DAT_3009a220 + param_1 * 0x14) = param_2;
  if (0xb < param_4) {
    param_4 = 0xc;
  }
  (*DAT_3009a224)(iVar1 + param_1 * 0x14 + 4,param_3,param_4);
  return 0;
}

/* ----------------------------------------------------------------
 * sda_GetFrameTime @ 0x3009A228  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A228, 0xFFFFFFFE
 * Данные: DAT_3009a260
 * ---------------------------------------------------------------- */
uint sda_GetFrameTime(void)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = DAT_3009a260;
  uVar3 = *DAT_3009a260;
  puVar1 = DAT_3009a260 + 1;
  uVar4 = uVar3 + 1;
  *DAT_3009a260 = uVar4;
  puVar2[1] = *puVar1 + (uint)(0xfffffffe < uVar3);
  return uVar4;
}

/* ----------------------------------------------------------------
 * SDA_TimGetRtcTime @ 0x3009A258  (примерный размер ~12 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009A258
 * ---------------------------------------------------------------- */
undefined4 SDA_TimGetRtcTime(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * at_BootromCmdProc @ 0x3009B2E8  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009B2E8
 * Данные: DAT_3009b468, DAT_3009b46c, DAT_3009b470, DAT_3009b474
 * ---------------------------------------------------------------- */
int at_BootromCmdProc(int param_1,uint param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_10;
  
  local_10 = 0;
  if (((param_1 == 0) || (param_2 == 0)) || (0x400 < param_2)) {
    iVar1 = 2;
  }
  else if (param_2 < 3) {
    iVar1 = 2;
  }
  else {
    iVar1 = (*DAT_3009b468)(param_1,&local_10);
    if (iVar1 == 0) {
      iVar1 = (*DAT_3009b470)(param_1,local_10);
      if (iVar1 == 0) {
        pcVar2 = (code *)(*DAT_3009b474)(param_1,local_10);
        if (pcVar2 == (code *)0x0) {
          (*DAT_3009b46c)();
          iVar1 = 1;
        }
        else {
          iVar1 = (*pcVar2)();
          if (iVar1 != 0) {
            (*DAT_3009b46c)();
            iVar1 = 1;
          }
        }
      }
    }
    else {
      (*DAT_3009b46c)();
      iVar1 = 2;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * NV_GET_LOCAL_FLASH_SUPPORT @ 0x3009BC2C  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BC2C
 * ---------------------------------------------------------------- */
undefined4 NV_GET_LOCAL_FLASH_SUPPORT(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * MSP_SysFidInit @ 0x3009BCDC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BCDC
 * ---------------------------------------------------------------- */
undefined4 MSP_SysFidInit(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * MSP_DsFidInit @ 0x3009BCE4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BCE4
 * ---------------------------------------------------------------- */
undefined4 MSP_DsFidInit(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * MSP_L4FidInit @ 0x3009BCEC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BCEC
 * ---------------------------------------------------------------- */
undefined4 MSP_L4FidInit(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * MSP_HalFidInit @ 0x3009BCF4  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BCF4
 * ---------------------------------------------------------------- */
undefined4 MSP_HalFidInit(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * MSP_Init @ 0x3009BCFC  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrAppInit
 * Константы: 0x3009BCFC
 * ---------------------------------------------------------------- */
undefined4 MSP_Init(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * sda_GetDLoadVer @ 0x3009BD04  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BD04
 * Данные: DAT_3009c088, DAT_3009c08c
 * ---------------------------------------------------------------- */
int sda_GetDLoadVer(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_3009c088;
  if (((param_1 != 0) && (param_2 != 0)) && (iVar1 = (*DAT_3009c08c)(), iVar1 == -1)) {
    iVar1 = -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sda_GetBootRomVer @ 0x3009BD38  (примерный размер ~84 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BD38
 * Данные: DAT_3009c088, DAT_3009c090
 * ---------------------------------------------------------------- */
undefined4 sda_GetBootRomVer(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_14 [12];
  
  iVar2 = 0xc;
  puVar3 = auStack_14;
  puVar4 = DAT_3009c090;
  do {
    iVar2 = iVar2 + -1;
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar2 != 0);
  uVar1 = DAT_3009c088;
  if (param_1 != 0 && param_2 != 0) {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sda_GetSoftwareVer @ 0x3009BD8C  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BD8C, 0xFFFFFFFF
 * Данные: DAT_3009c088, DAT_3009c094, DAT_3009c098
 * ---------------------------------------------------------------- */
undefined4 sda_GetSoftwareVer(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_3009c088;
  if (param_1 != 0 && param_2 != 0) {
    iVar1 = (*DAT_3009c094)(param_1);
    if (iVar1 == 0) {
      uVar2 = (*DAT_3009c098)(param_1);
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * sda_GetISOVer @ 0x3009BDE4  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BDE4, 0xFFFFFFFF
 * Данные: DAT_3009c088, DAT_3009c098, DAT_3009c09c
 * ---------------------------------------------------------------- */
undefined4 sda_GetISOVer(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_3009c088;
  if (param_1 != 0 && param_2 != 0) {
    iVar1 = (*DAT_3009c09c)(param_1);
    if (iVar1 == 0) {
      uVar2 = (*DAT_3009c098)(param_1);
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * sda_GetProductId @ 0x3009BE3C  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BE3C
 * Данные: DAT_3009c088, DAT_3009c0a0
 * ---------------------------------------------------------------- */
int sda_GetProductId(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_3009c088;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = (*DAT_3009c0a0)();
    if (iVar1 == -1) {
      iVar1 = -1;
    }
    else if (0x1f < iVar1) {
      iVar1 = 0x1f;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sda_GetDloadType @ 0x3009BE84  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BE84
 * Данные: DAT_3009c0a4
 * ---------------------------------------------------------------- */
void sda_GetDloadType(void)

{
  (*DAT_3009c0a4)();
  return;
}

/* ----------------------------------------------------------------
 * sda_GetAuthorityVer @ 0x3009BE98  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BE98
 * Данные: DAT_3009c088, DAT_3009c0ac
 * ---------------------------------------------------------------- */
undefined4 sda_GetAuthorityVer(char *param_1,int param_2)

{
  undefined4 uVar1;
  char local_14;
  char local_13;
  char local_12;
  char local_11;
  uint local_10;
  
  local_10 = 0;
  uVar1 = DAT_3009c088;
  if (param_1 != (char *)0x0 && param_2 != 0) {
    (*DAT_3009c0ac)(&local_10);
    local_14 = (char)local_10;
    if (9 < (local_10 & 0xff)) {
      local_14 = '\0';
    }
    local_13 = (char)(local_10 >> 8);
    if (9 < (local_10 >> 8 & 0xff)) {
      local_13 = '\0';
    }
    local_12 = (char)(local_10 >> 0x10);
    if (9 < (local_10 >> 0x10 & 0xff)) {
      local_12 = '\0';
    }
    local_11 = (char)(local_10 >> 0x18);
    if (9 < local_10 >> 0x18) {
      local_11 = '\0';
    }
    *param_1 = local_14 + '0';
    param_1[1] = local_13 + '0';
    param_1[2] = local_12 + '0';
    param_1[3] = local_11 + '0';
    uVar1 = 4;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * sda_GetAuthorityId @ 0x3009BF8C  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BF8C, 0xFFFFFFFF
 * Данные: DAT_3009c088, DAT_3009c0b0
 * ---------------------------------------------------------------- */
undefined4 sda_GetAuthorityId(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_3009c088;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = (*DAT_3009c0b0)();
    if (iVar1 == 0) {
      uVar2 = 0xf;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * sda_GetAuthorityType @ 0x3009BFC4  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009BFC4
 * Данные: DAT_3009c0b4
 * ---------------------------------------------------------------- */
uint sda_GetAuthorityType(void)

{
  uint local_8 [2];
  
  local_8[0] = 0;
  (*DAT_3009c0b4)(local_8);
  if (0xff < local_8[0]) {
    local_8[0] = 0;
  }
  return local_8[0] & 0xff;
}

/* ----------------------------------------------------------------
 * sda_SetCurMode @ 0x3009C004  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009C004
 * Данные: DAT_3009c0b8
 * ---------------------------------------------------------------- */
void sda_SetCurMode(void)

{
  (*DAT_3009c0b8)();
  return;
}

/* ----------------------------------------------------------------
 * sda_GetCurMode @ 0x3009C018  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009C018
 * Данные: DAT_3009c0bc
 * ---------------------------------------------------------------- */
void sda_GetCurMode(void)

{
  (*DAT_3009c0bc)();
  return;
}

/* ----------------------------------------------------------------
 * sda_Reset @ 0x3009C02C  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009C02C
 * Данные: DAT_3009c0c0
 * ---------------------------------------------------------------- */
void sda_Reset(void)

{
  (*DAT_3009c0c0)();
  return;
}

/* ----------------------------------------------------------------
 * sda_SetSoftLoad @ 0x3009C040  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009C040
 * Данные: DAT_3009c0c4
 * ---------------------------------------------------------------- */
void sda_SetSoftLoad(void)

{
  (*DAT_3009c0c4)();
  return;
}

/* ----------------------------------------------------------------
 * sda_SendDataCom @ 0x3009C054  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009C054, 0xFFFFFFFF
 * Данные: DAT_3009c0c8
 * ---------------------------------------------------------------- */
undefined4 sda_SendDataCom(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*DAT_3009c0c8)();
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * sda_AtProcReg @ 0x3009C074  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009C074
 * Данные: DAT_3009c0cc
 * ---------------------------------------------------------------- */
void sda_AtProcReg(void)

{
  (*DAT_3009c0cc)();
  return;
}

/* ----------------------------------------------------------------
 * LNV_SetAreaAccessable @ 0x3009C0D0  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009C0D0
 * Данные: DAT_3009d048, DAT_3009d04c
 * ---------------------------------------------------------------- */
void LNV_SetAreaAccessable(void)

{
  (*DAT_3009d048)();
  (*DAT_3009d04c)();
  return;
}

/* ----------------------------------------------------------------
 * LNV_Copy_Data_To_Memory @ 0x3009C0F0  (примерный размер ~664 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009C0F0
 * Данные: DAT_3009d048, DAT_3009d04c, DAT_3009d050, DAT_3009d054, DAT_3009d058, DAT_3009d05c, DAT_3009d060, DAT_3009d064
 * ---------------------------------------------------------------- */
int LNV_Copy_Data_To_Memory(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  (*DAT_3009d048)();
  (*DAT_3009d04c)();
  *(undefined1 *)*DAT_3009d050 = 0;
  (*DAT_3009d048)();
  (*DAT_3009d04c)();
  iVar1 = (*DAT_3009d054)();
  uVar5 = DAT_3009d058;
  if (iVar1 != 0) {
    uVar5 = DAT_3009d05c;
  }
  iVar1 = (*DAT_3009d060)(uVar5,DAT_3009d064);
  if (iVar1 == 0) {
    (*DAT_3009d068)(DAT_3009d06c);
    (*DAT_3009d070)(4,0,0,0);
    return DAT_3009d074;
  }
  *DAT_3009d07c = DAT_3009d078;
  iVar2 = (*DAT_3009d080)(iVar1,0,2);
  if (iVar2 == 0) {
    uVar3 = (*DAT_3009d13c)(iVar1);
    if ((uVar3 == 0) || (0x7ffff < uVar3)) {
      (*DAT_3009d070)(4,uVar3,0,3);
      (*DAT_3009d140)(iVar1);
      return DAT_3009d144;
    }
    iVar2 = (*DAT_3009d080)(iVar1,0,0);
    if (iVar2 == 0) {
      if (DAT_3009d148 <= uVar3) {
        (*DAT_3009d070)(4,uVar3,0,6);
        (*DAT_3009d140)(iVar1);
        return 8;
      }
      (*DAT_3009d048)();
      (*DAT_3009d04c)();
      uVar4 = (*DAT_3009d240)(*DAT_3009d07c,1,uVar3,iVar1);
      if (uVar4 != uVar3) {
        (*DAT_3009d070)(4,uVar4,uVar3,5);
        (*DAT_3009d140)(iVar1);
        return DAT_3009d244;
      }
      *(undefined1 *)*DAT_3009d050 = 1;
      (*DAT_3009d048)(uVar4,uVar4);
      (*DAT_3009d04c)();
    }
    else {
      (*DAT_3009d070)(4,iVar2,0,4);
    }
  }
  else {
    (*DAT_3009d070)(4,iVar2,0,2);
  }
  (*DAT_3009d140)(iVar1);
  return iVar2;
}

/* ----------------------------------------------------------------
 * LNV_UpDate_Memory_To_File @ 0x3009C388  (примерный размер ~424 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009C388
 * Данные: DAT_3009d054, DAT_3009d058, DAT_3009d05c, DAT_3009d060, DAT_3009d064, DAT_3009d070, DAT_3009d074, DAT_3009d07c
 * ---------------------------------------------------------------- */
int LNV_UpDate_Memory_To_File(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = (*DAT_3009d054)();
  uVar5 = DAT_3009d058;
  if (iVar1 != 0) {
    uVar5 = DAT_3009d05c;
  }
  iVar1 = (*DAT_3009d060)(uVar5,DAT_3009d064);
  if (iVar1 == 0) {
    (*DAT_3009d070)(4,0,0,7);
    iVar2 = DAT_3009d074;
  }
  else {
    iVar2 = (*DAT_3009d080)(iVar1,0,2);
    if (iVar2 == 0) {
      uVar3 = (*DAT_3009d13c)(iVar1);
      if ((uVar3 == 0) || (0x7ffff < uVar3)) {
        (*DAT_3009d070)(4,0,uVar3,9);
        (*DAT_3009d140)(iVar1);
        return DAT_3009d144;
      }
      iVar2 = (*DAT_3009d080)(iVar1,0,0);
      if (iVar2 == 0) {
        uVar4 = (*DAT_3009d42c)(*DAT_3009d07c,1,uVar3,iVar1);
        if (uVar4 != uVar3) {
          (*DAT_3009d070)(4,uVar4,uVar3,0xb);
          iVar2 = DAT_3009d430;
        }
      }
      else {
        (*DAT_3009d070)(4,0,iVar2,10);
      }
    }
    else {
      (*DAT_3009d070)(4,0,iVar2,8);
    }
    (*DAT_3009d140)(iVar1);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * NVIM_WriteFactoryForce @ 0x3009C530  (примерный размер ~600 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009C530
 * Данные: DAT_3009d070, DAT_3009d434, DAT_3009d498, DAT_3009d49c, DAT_3009d4a0, DAT_3009d4a4, DAT_3009d4a8, DAT_3009d4ac
 * ---------------------------------------------------------------- */
int NVIM_WriteFactoryForce(uint param_1,int param_2,ushort param_3)

{
  int iVar1;
  ushort local_20 [2];
  undefined4 local_1c;
  undefined1 auStack_18 [4];
  
  (*DAT_3009d070)(7,0,param_1,0);
  iVar1 = (*DAT_3009d434)();
  if (iVar1 == 0) {
    if (param_2 == 0) {
      (*DAT_3009d070)(8,0,param_1,2);
      iVar1 = DAT_3009d498;
    }
    else if ((param_3 == 0) || (0x800 < param_3)) {
      (*DAT_3009d070)(8,0,param_1,3);
      iVar1 = DAT_3009d49c;
    }
    else {
      (*DAT_3009d4a0)();
      iVar1 = (*DAT_3009d4a4)(param_1 & 0xffff,local_20,&local_1c,auStack_18);
      if (iVar1 == 0) {
        if (param_3 == local_20[0]) {
          if (local_20[0] == 0) {
            (*DAT_3009d4a8)();
            (*DAT_3009d070)(8,local_20[0],param_1,6);
            iVar1 = DAT_3009d498;
          }
          else {
            iVar1 = (*DAT_3009d4ac)(local_1c,param_2,param_3);
            if (iVar1 != 0) {
              (*DAT_3009d070)(8,iVar1,param_1,7);
            }
            iVar1 = (*DAT_3009d4b0)(local_1c,param_2,param_3);
            if (iVar1 != 0) {
              (*DAT_3009d070)(8,iVar1,param_1,8);
            }
            (*DAT_3009d4a8)();
          }
        }
        else {
          (*DAT_3009d4a8)();
          (*DAT_3009d070)(8,local_20[0],param_1,5);
          iVar1 = DAT_3009d498;
        }
      }
      else {
        (*DAT_3009d4a8)();
        (*DAT_3009d070)(8,iVar1,param_1,4);
      }
    }
  }
  else {
    (*DAT_3009d070)(8,0,param_1,1);
    iVar1 = 3;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * LNvm_Flush @ 0x3009C788  (примерный размер ~116 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009C788
 * Данные: DAT_3009d068, DAT_3009d070, DAT_3009d4b4, DAT_3009d4b8
 * ---------------------------------------------------------------- */
int LNvm_Flush(void)

{
  int iVar1;
  
  (*DAT_3009d068)(DAT_3009d4b4);
  (*DAT_3009d070)(5,0,0,5);
  iVar1 = (*DAT_3009d4b8)();
  if (iVar1 != 0) {
    (*DAT_3009d070)(6,iVar1,0,8);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * LNvm_Init @ 0x3009C7FC  (примерный размер ~540 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009C7FC
 * Данные: DAT_3009d054, DAT_3009d070, DAT_3009d4b8, DAT_3009d4bc, DAT_3009d4c0, DAT_3009d4c4, DAT_3009d4c8, DAT_3009d4cc
 * ---------------------------------------------------------------- */
int LNvm_Init(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar7;
  undefined8 uVar8;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 auStack_38 [6];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_10;
  undefined4 *puVar6;
  
  puVar4 = auStack_38;
  iVar7 = 5;
  puVar5 = DAT_3009d4bc;
  do {
    puVar6 = puVar5 + 1;
    uVar1 = *puVar5;
    iVar7 = iVar7 + -1;
    puVar5 = puVar5 + 2;
    uVar2 = *puVar6;
    puVar6 = puVar4 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 2;
    *puVar6 = uVar2;
  } while (iVar7 != 0);
  *puVar4 = *puVar5;
  local_40 = 0;
  local_3c = 0;
  (*DAT_3009d070)(1,param_1,0,0);
  uVar8 = (*DAT_3009d4c0)();
  if ((int)uVar8 == 0) {
    uVar8 = (*DAT_3009d4c4)(0,(int)((ulonglong)uVar8 >> 0x20));
    if ((int)uVar8 == 0) {
      iVar7 = (*DAT_3009d4c8)(0,(int)((ulonglong)uVar8 >> 0x20));
      if (iVar7 != 0) {
        (*DAT_3009d070)(2,iVar7,0,1);
        return -1;
      }
      iVar7 = (*DAT_3009d054)();
      if (iVar7 == 0) {
        iVar3 = (*DAT_3009d4cc)(1,&local_40,&local_3c);
        uVar1 = local_40;
        iVar7 = iVar3;
        if (iVar3 != 0) goto LAB_3009c9fc;
      }
      else {
        uVar1 = 0;
      }
      (*DAT_3009d4d0)(uVar1);
      (*DAT_3009d4d4)();
      iVar3 = (*DAT_3009d4d8)();
      iVar7 = iVar3;
      if ((iVar3 == 0) &&
         ((iVar7 = (*DAT_3009d4dc)(), iVar7 != 0 ||
          (iVar3 = (*DAT_3009d4b8)(), iVar7 = iVar3, iVar3 == 0)))) {
        auStack_38[1] = DAT_3009d4e0;
        auStack_38[2] = DAT_3009d4e4;
        local_10 = DAT_3009d4e8;
        local_1c = DAT_3009d4ec;
        local_18 = DAT_3009d4f0;
        auStack_38[3] = DAT_3009d4f4;
        local_20 = DAT_3009d4f8;
        auStack_38[4] = DAT_3009d4fc;
        iVar3 = (*DAT_3009d500)(DAT_3009d504,auStack_38,0);
        iVar7 = iVar3;
        if (iVar3 == 0) {
          return 0;
        }
      }
    }
    else {
      iVar3 = -1;
      iVar7 = (int)uVar8;
    }
  }
  else {
    iVar3 = -1;
    iVar7 = (int)uVar8;
  }
LAB_3009c9fc:
  (*DAT_3009d070)(2,iVar3);
  return iVar7;
}

/* ----------------------------------------------------------------
 * LNvm_Read @ 0x3009CA18  (примерный размер ~512 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009CA18
 * Данные: DAT_3009d070, DAT_3009d434, DAT_3009d498, DAT_3009d4a0, DAT_3009d4a4, DAT_3009d4a8, DAT_3009d508
 * ---------------------------------------------------------------- */
int LNvm_Read(undefined2 param_1,int param_2,short param_3)

{
  int iVar1;
  short local_20 [2];
  undefined4 local_1c;
  undefined1 auStack_18 [4];
  
  (*DAT_3009d070)(9,param_3,param_1,0);
  iVar1 = (*DAT_3009d434)();
  if (iVar1 == 0) {
    if ((param_2 == 0) || (param_3 == 0)) {
      (*DAT_3009d070)(10,0,param_1,2);
      iVar1 = DAT_3009d498;
    }
    else {
      (*DAT_3009d4a0)();
      iVar1 = (*DAT_3009d4a4)(param_1,local_20,&local_1c,auStack_18);
      if (iVar1 == 0) {
        if (param_3 == local_20[0]) {
          if (local_20[0] == 0) {
            (*DAT_3009d4a8)();
            (*DAT_3009d070)(10,local_20[0],param_1,5);
            iVar1 = DAT_3009d498;
          }
          else {
            iVar1 = (*DAT_3009d508)(local_1c,param_2,param_3);
            if (iVar1 != 0) {
              (*DAT_3009d070)(10,iVar1,param_1,6);
            }
            (*DAT_3009d4a8)();
          }
        }
        else {
          (*DAT_3009d4a8)();
          (*DAT_3009d070)(10,local_20[0],param_1,4);
          iVar1 = DAT_3009d498;
        }
      }
      else {
        (*DAT_3009d4a8)();
        (*DAT_3009d070)(10,iVar1,param_1,3);
      }
    }
  }
  else {
    (*DAT_3009d070)(10,0,param_1,1);
    iVar1 = 3;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * LNvm_Write @ 0x3009CDF8  (примерный размер ~872 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009CDF8
 * Данные: DAT_3009d054, DAT_3009d070, DAT_3009d434, DAT_3009d498, DAT_3009d49c, DAT_3009d4a0, DAT_3009d4a4, DAT_3009d4a8
 * ---------------------------------------------------------------- */
int LNvm_Write(undefined2 param_1,int param_2,ushort param_3)

{
  int iVar1;
  int unaff_r11;
  ushort local_20 [2];
  undefined4 local_1c;
  uint local_18;
  
  local_18 = 0;
  (*DAT_3009d070)(7,0,param_1,0);
  iVar1 = (*DAT_3009d434)();
  if (iVar1 == 0) {
    if (param_2 == 0) {
      (*DAT_3009d070)(8,0,param_1,2);
      iVar1 = DAT_3009d498;
    }
    else if ((param_3 == 0) || (0x800 < param_3)) {
      (*DAT_3009d070)(8,0,param_1,3);
      iVar1 = DAT_3009d49c;
    }
    else {
      iVar1 = DAT_3009d51c;
      if (unaff_r11 != 0) {
        (*DAT_3009d4a0)(0);
        iVar1 = (*DAT_3009d4a4)(param_1,local_20,&local_1c,&local_18);
        if (iVar1 == 0) {
          if (param_3 == local_20[0]) {
            if (local_20[0] == 0) {
              (*DAT_3009d4a8)();
              (*DAT_3009d070)(8,local_20[0],param_1,6);
              iVar1 = DAT_3009d498;
            }
            else {
              iVar1 = (*DAT_3009d054)();
              if (iVar1 == 0) {
                iVar1 = (*DAT_3009d4ac)(local_1c,param_2,param_3);
                if (iVar1 != 0) {
                  (*DAT_3009d4a8)();
                  (*DAT_3009d070)(8,iVar1,param_1,7);
                  return iVar1;
                }
              }
              else {
                iVar1 = (*DAT_3009d520)(local_1c,param_2,param_3,local_18 & 0xffff);
                if (iVar1 != 0) {
                  (*DAT_3009d4a8)();
                  (*DAT_3009d524)(DAT_3009d528,iVar1,param_1);
                  return iVar1;
                }
              }
              iVar1 = (*DAT_3009d4b0)(local_1c,param_2,param_3);
              if (iVar1 == 0) {
                (*DAT_3009d4a8)();
              }
              else {
                (*DAT_3009d4a8)();
                (*DAT_3009d52c)(8,iVar1,param_1,8);
              }
            }
          }
          else {
            (*DAT_3009d4a8)();
            (*DAT_3009d070)(8,local_20[0],param_1,5);
            iVar1 = DAT_3009d498;
          }
        }
        else {
          (*DAT_3009d4a8)();
          (*DAT_3009d070)(8,iVar1,param_1,4);
        }
      }
    }
  }
  else {
    (*DAT_3009d070)(8,0,param_1,1);
    iVar1 = 3;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * LXML_Nvm_Read @ 0x3009D160  (примерный размер ~460 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009D160
 * Данные: DAT_3009d498, DAT_3009d4a0, DAT_3009d4a4, DAT_3009d4a8, DAT_3009d508, DAT_3009d52c
 * ---------------------------------------------------------------- */
int LXML_Nvm_Read(undefined2 param_1,int param_2,short param_3)

{
  int iVar1;
  short local_20 [2];
  undefined4 local_1c;
  undefined1 auStack_18 [4];
  
  (*DAT_3009d52c)(9,param_3,param_1,0);
  if ((param_2 == 0) || (param_3 == 0)) {
    (*DAT_3009d52c)(10,0,param_1,2);
    iVar1 = DAT_3009d498;
  }
  else {
    (*DAT_3009d4a0)();
    iVar1 = (*DAT_3009d4a4)(param_1,local_20,&local_1c,auStack_18);
    if (iVar1 == 0) {
      if (param_3 == local_20[0]) {
        if (local_20[0] == 0) {
          (*DAT_3009d4a8)();
          (*DAT_3009d52c)(10,local_20[0],param_1,5);
          iVar1 = DAT_3009d498;
        }
        else {
          iVar1 = (*DAT_3009d508)(local_1c,param_2,param_3);
          if (iVar1 != 0) {
            (*DAT_3009d52c)(10,iVar1,param_1,6);
          }
          (*DAT_3009d4a8)();
        }
      }
      else {
        (*DAT_3009d4a8)();
        (*DAT_3009d52c)(10,local_20[0],param_1,4);
        iVar1 = DAT_3009d498;
      }
    }
    else {
      (*DAT_3009d4a8)();
      (*DAT_3009d52c)(10,iVar1,param_1,3);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * LXML_Nvm_Write @ 0x3009D32C  (примерный размер ~516 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009D32C
 * Данные: DAT_3009d498, DAT_3009d4a0, DAT_3009d4a4, DAT_3009d4a8, DAT_3009d4b0, DAT_3009d52c
 * ---------------------------------------------------------------- */
int LXML_Nvm_Write(undefined2 param_1,undefined4 param_2,short param_3)

{
  int iVar1;
  short local_20 [2];
  undefined4 local_1c;
  undefined1 auStack_18 [4];
  
  (*DAT_3009d4a0)();
  iVar1 = (*DAT_3009d4a4)(param_1,local_20,&local_1c,auStack_18);
  if (iVar1 == 0) {
    if (param_3 == local_20[0]) {
      if (local_20[0] == 0) {
        (*DAT_3009d4a8)();
        (*DAT_3009d52c)(8,local_20[0],param_1,0xe);
        iVar1 = DAT_3009d498;
      }
      else {
        iVar1 = (*DAT_3009d4b0)(local_1c,param_2,param_3);
        if (iVar1 != 0) {
          (*DAT_3009d52c)(8,iVar1,param_1,0xf);
        }
        (*DAT_3009d4a8)();
      }
    }
    else {
      (*DAT_3009d4a8)();
      (*DAT_3009d52c)(8,local_20[0],param_1,0xd);
      iVar1 = DAT_3009d498;
    }
  }
  else {
    (*DAT_3009d4a8)();
    (*DAT_3009d52c)(8,iVar1,param_1,0xc);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * LNVM_UpgradeBackup @ 0x3009DC44  (примерный размер ~256 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009DC44
 * Данные: DAT_3009e0c4, DAT_3009e0cc, DAT_3009e100, DAT_3009e158, DAT_3009e15c, DAT_3009e160, DAT_3009e164, DAT_3009e168
 * ---------------------------------------------------------------- */
undefined4 LNVM_UpgradeBackup(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint local_10;
  
  (*DAT_3009e0cc)(DAT_3009e158);
  iVar1 = (*DAT_3009e100)(0x134,&local_10,4);
  if (iVar1 == 0) {
    if (local_10 < 0x80001) {
      iVar1 = *DAT_3009e160;
      if (iVar1 == 0) {
        uVar2 = 0xf;
      }
      else {
        (*DAT_3009e164)(0);
        *(undefined2 *)(iVar1 + 0x66) = param_1;
        (*DAT_3009e164)(1);
        uVar2 = (*DAT_3009e0c4)();
        uVar2 = (*DAT_3009e168)(iVar1,uVar2,local_10);
        (*DAT_3009e164)(0);
        *(undefined2 *)(iVar1 + 0x66) = 1;
        (*DAT_3009e164)(1);
      }
    }
    else {
      (*DAT_3009e0cc)(DAT_3009e15c,0);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * LNVM_UpgradeRestore @ 0x3009DD44  (примерный размер ~400 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009DD44
 * Данные: DAT_3009e0c4, DAT_3009e0c8, DAT_3009e0cc, DAT_3009e0d0, DAT_3009e0d8, DAT_3009e0dc, DAT_3009e0e4, DAT_3009e16c
 * ---------------------------------------------------------------- */
int LNVM_UpgradeRestore(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 local_10;
  
  iVar1 = (*DAT_3009e0c4)();
  iVar1 = (*DAT_3009e0c8)(&local_10,iVar1 + 0x134,4);
  if (iVar1 == 0) {
    (*DAT_3009e0cc)(DAT_3009e16c);
    iVar2 = (*DAT_3009e0d8)(local_10);
    if (iVar2 == 0) {
      (*DAT_3009e0cc)(DAT_3009e170);
      iVar1 = 0xf;
    }
    else {
      iVar1 = (*DAT_3009e0dc)(iVar2);
      if (iVar1 == 0) {
        iVar1 = (*DAT_3009e17c)(iVar2,0);
        if (iVar1 == 0) {
          (*DAT_3009e0e4)(iVar2);
          iVar1 = (*DAT_3009e184)();
          uVar3 = DAT_3009e188;
          pcVar4 = DAT_3009e0cc;
          if (iVar1 == 0) {
            (*DAT_3009e18c)(1);
            uVar3 = 1;
            pcVar4 = DAT_3009e174;
          }
        }
        else {
          (*DAT_3009e0cc)(DAT_3009e180,iVar1);
          (*DAT_3009e0e4)(iVar2);
          uVar3 = 0;
          pcVar4 = DAT_3009e174;
        }
        (*pcVar4)(uVar3);
      }
      else {
        (*DAT_3009e0e4)(iVar2);
        (*DAT_3009e174)(0);
        (*DAT_3009e0cc)(DAT_3009e178);
        iVar1 = 0;
      }
    }
  }
  else {
    (*DAT_3009e0cc)(DAT_3009e0d0,iVar1,local_10);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * Is_LnvmNeedRestore @ 0x3009F25C  (примерный размер ~252 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3009F25C
 * Данные: DAT_3009f550, DAT_3009f698, DAT_3009f6c0, DAT_3009f9b0, DAT_3009fce8, DAT_3009fcec
 * ---------------------------------------------------------------- */
bool Is_LnvmNeedRestore(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  bool bVar4;
  ushort local_10 [2];
  
  local_10[0] = (ushort)DAT_3009fce8;
  if (*DAT_3009f550 == 0) {
    bVar4 = false;
  }
  else if (*(short *)(*DAT_3009f550 + 0x66) == 1) {
    bVar4 = false;
  }
  else {
    iVar1 = (*DAT_3009f698)(param_1);
    if (iVar1 == 0) {
      iVar2 = *DAT_3009fcec;
      iVar1 = (*DAT_3009f698)();
      pcVar3 = DAT_3009f6c0;
      if (iVar1 != 0) {
        pcVar3 = DAT_3009f9b0;
      }
      iVar1 = (*pcVar3)(local_10,iVar2 + 0x66,2);
      if (iVar1 == 0) {
        bVar4 = local_10[0] != DAT_3009fce8;
      }
      else {
        bVar4 = false;
      }
    }
    else {
      iVar2 = *DAT_3009fcec;
      iVar1 = (*DAT_3009f698)();
      pcVar3 = DAT_3009f6c0;
      if (iVar1 != 0) {
        pcVar3 = DAT_3009f9b0;
      }
      iVar1 = (*pcVar3)(local_10,iVar2 + 0x66,2);
      bVar4 = iVar1 == 0;
    }
  }
  return bVar4;
}

/* ----------------------------------------------------------------
 * aimCacheInit @ 0x300A05FC  (примерный размер ~1724 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: bzero
 * Вызывают: cacheAimCortexA8LibInit, cacheAimCortexA9LibInit
 * Константы: 0x300A05FC, 0xFFFFFF00, 0x10000000, 0x300A0814, 0x300A0AAC
 * Данные: DAT_300a0818, DAT_300a081c, DAT_300a0820, DAT_300a0824, DAT_300a0830, DAT_300a0834, DAT_300a0838, DAT_300a083c
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

int aimCacheInit(uint *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  uint auStack_204 [59];
  uint uStack_118;
  uint auStack_114 [60];
  
  iVar3 = 0;
  bzero(auStack_204,0xf0);
  bzero(auStack_114,0xf0);
  uVar7 = 0;
  if (*param_1 != 0) {
    do {
      if (iVar3 != 0) break;
      uVar4 = param_1[uVar7 * 0x29 + 1];
      uVar2 = param_1[uVar7 * 0x29 + 4];
      *(uint *)(DAT_300a0830 + uVar4 * 4) = uVar2;
      uVar8 = param_1[uVar7 * 0x29 + 5];
      *(uint *)(DAT_300a0824 + uVar4 * 4) = uVar8;
      if ((uVar2 != 0) && (uVar8 != 0)) {
        iVar1 = uVar4 * 4;
        *(uint *)(DAT_300a0834 + iVar1) = param_1[uVar7 * 0x29 + 6];
        *(uint *)(DAT_300a0838 + iVar1) = param_1[uVar7 * 0x29 + 7];
        *(uint *)(DAT_300a083c + iVar1) = param_1[uVar7 * 0x29 + 8];
        *(uint *)(DAT_300a0840 + iVar1) = param_1[uVar7 * 0x29 + 9];
        *(uint *)(DAT_300a0844 + iVar1) = param_1[uVar7 * 0x29 + 10];
        *(uint *)(DAT_300a0848 + iVar1) = param_1[uVar7 * 0x29 + 0xb];
        *(uint *)(DAT_300a081c + iVar1) = ~(uVar8 - 1);
        *(uint *)(DAT_300a0820 + iVar1) = uVar8 - 1;
        uVar9 = 0;
        uVar2 = uVar8 & 1;
        while (uVar2 == 0) {
          uVar9 = uVar9 + 1;
          uVar2 = uVar8 & 1 << (uVar9 & 0xff);
        }
        *(uint *)(DAT_300a084c + uVar4 * 4) = uVar9;
        iVar1 = DAT_300a0850;
        *(undefined4 *)(DAT_300a0850 + uVar4 * 0x18) = 1;
        iVar1 = iVar1 + uVar4 * 0x18;
        *(uint *)(iVar1 + 4) = uVar4;
        *(uint *)(iVar1 + 8) = param_1[uVar7 * 0x29 + 4];
        *(uint *)(iVar1 + 0xc) = param_1[uVar7 * 0x29 + 5];
        *(uint *)(iVar1 + 0x10) = param_1[uVar7 * 0x29 + 3];
        *(uint *)(iVar1 + 0x14) = param_1[uVar7 * 0x29 + 2];
        *(undefined4 *)(DAT_300a0818 + uVar4 * 4) = 1;
        if (*DAT_300a0854 < param_1[uVar7 * 0x29 + 5]) {
          *DAT_300a0854 = param_1[uVar7 * 0x29 + 5];
        }
        puVar5 = param_1 + uVar7 * 0x29 + 0xc;
        iVar1 = 0;
        do {
          if (iVar3 != 0) break;
          uVar2 = *puVar5;
          uVar8 = uVar2 & 0xffffff00;
          if (uVar8 != 0x100) {
            uVar9 = uVar2 & 0xff;
            if ((uVar2 & 0x10000000) == 0) {
              if ((uVar2 & 0x4000) == 0) {
                auStack_204[uVar4 * 0x1e + uVar9 * 2] = uVar8;
                auStack_204[uVar4 * 0x1e + uVar9 * 2 + 1] = puVar5[1];
              }
              else {
                auStack_114[uVar4 * 0x1e + uVar9 * 2] = uVar8;
                auStack_114[uVar4 * 0x1e + uVar9 * 2 + 1] = puVar5[1];
              }
            }
            if (uVar9 < 0xd) {
                    /* WARNING: Could not recover jumptable at 0x300a0814. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              iVar3 = (**(code **)(DAT_300a0858 + uVar9 * 4))();
              return iVar3;
            }
            iVar3 = -1;
          }
          iVar1 = iVar1 + 1;
          puVar5 = puVar5 + 2;
        } while (iVar1 < 0xf);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *param_1);
  }
  uVar2 = 0;
  uVar7 = *DAT_300a0abc * 8 - 1;
  *DAT_300a0ac0 = uVar7;
  *DAT_300a0ac4 = ~uVar7;
  iVar1 = DAT_300a0ac8;
  uVar7 = *param_1;
  if ((uVar7 != 0) && (iVar3 == 0)) {
    do {
      iVar6 = 0;
      puVar5 = &uStack_118 + uVar2 * 0x1e;
      puVar10 = auStack_204 + uVar2 * 0x1e + -1;
      iVar11 = DAT_300a0acc + uVar2 * 0x3c;
      do {
        puVar10 = puVar10 + 2;
        *(uint *)(iVar11 + iVar6 * 4) = *puVar10;
        puVar5 = puVar5 + 2;
        *(uint *)(iVar1 + uVar2 * 0x3c + iVar6 * 4) = *puVar5;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0xf);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar7);
  }
  uVar2 = 0;
  if (uVar7 != 0) {
    do {
      uVar7 = 0;
      do {
        if (uVar7 < 0xd) {
                    /* WARNING: Could not recover jumptable at 0x300a0aac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          iVar3 = (**(code **)(DAT_300a0ad0 + uVar7 * 4))();
          return iVar3;
        }
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < 0xf);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *param_1);
  }
  *DAT_300a1270 = *(undefined4 *)(DAT_300a126c + 0x2c);
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_300a0cb8 @ 0x300A0CB8  (примерный размер ~148 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300a0548, __errno
 * Константы: 0x300A0CB8
 * Данные: DAT_300a1248, DAT_300a1274
 * ---------------------------------------------------------------- */
int FUN_300a0cb8(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  
  iVar2 = FUN_300a0548();
  iVar1 = DAT_300a1248;
  if (iVar2 == 0) {
    puVar4 = (undefined4 *)__errno();
    iVar2 = -1;
    *puVar4 = DAT_300a1274;
  }
  else {
    param_1 = param_1 * 0xc;
    if (*(int *)(DAT_300a1248 + param_1) == 0) {
      pcVar3 = *(code **)(DAT_300a1248 + param_1 + 4);
      if (pcVar3 == (code *)0x0) {
        *(undefined4 *)(DAT_300a1248 + param_1) = 1;
        iVar2 = 0;
      }
      else {
        iVar2 = (*pcVar3)();
        if (iVar2 == 0) {
          *(undefined4 *)(iVar1 + param_1) = 1;
        }
      }
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300a0d4c @ 0x300A0D4C  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300a0548, __errno
 * Константы: 0x300A0D4C
 * Данные: DAT_300a1248, DAT_300a1274
 * ---------------------------------------------------------------- */
int FUN_300a0d4c(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  
  iVar2 = FUN_300a0548();
  iVar1 = DAT_300a1248;
  if (iVar2 == 0) {
    puVar4 = (undefined4 *)__errno();
    iVar2 = -1;
    *puVar4 = DAT_300a1274;
  }
  else {
    param_1 = param_1 * 0xc;
    if (*(int *)(DAT_300a1248 + param_1) == 0) {
      iVar2 = 0;
    }
    else {
      pcVar3 = *(code **)(DAT_300a1248 + param_1 + 8);
      if (pcVar3 == (code *)0x0) {
        iVar2 = 0;
        *(undefined4 *)(DAT_300a1248 + param_1) = 0;
      }
      else {
        iVar2 = (*pcVar3)();
        if (iVar2 == 0) {
          *(undefined4 *)(iVar1 + param_1) = 0;
        }
      }
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_300a0ddc @ 0x300A0DDC  (примерный размер ~244 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300a0548, FUN_300a0578, FUN_300a0588, FUN_300a05bc, __errno
 * Вызывают: FUN_300a10a8
 * Константы: 0x300A0DDC, 0xFFFFFFFF
 * Данные: DAT_300a1274, DAT_300a1278, DAT_300a127c, DAT_300a1280, DAT_300a1284, DAT_300a1288, DAT_300a128c, DAT_300a1290
 * ---------------------------------------------------------------- */
undefined4 FUN_300a0ddc(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  code *pcVar5;
  
  iVar1 = FUN_300a0548();
  uVar2 = DAT_300a1274;
  if (iVar1 != 0) {
    if (param_3 != -1) {
      uVar2 = FUN_300a0578(param_2,param_1);
      uVar3 = FUN_300a0588(param_3 + param_2,param_1);
      uVar2 = FUN_300a05bc(uVar2,uVar3,*(undefined4 *)(DAT_300a1278 + param_1 * 4),param_1,3);
      return uVar2;
    }
    pcVar5 = *(code **)(DAT_300a127c + param_1 * 0x3c);
    uVar2 = DAT_300a1280;
    if (pcVar5 != (code *)0x0) {
      param_1 = param_1 * 4;
      uVar2 = (*pcVar5)(*(undefined4 *)(DAT_300a1288 + param_1),
                        *(undefined4 *)(DAT_300a128c + param_1),
                        *(undefined4 *)(DAT_300a1278 + param_1),
                        *(undefined4 *)(DAT_300a1290 + param_1),
                        *(undefined4 *)(DAT_300a1284 + param_1),0);
      return uVar2;
    }
  }
  puVar4 = (undefined4 *)__errno();
  *puVar4 = uVar2;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300a0ed0 @ 0x300A0ED0  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300a0548, FUN_300a0578, FUN_300a0588, FUN_300a05bc, __errno
 * Вызывают: FUN_300a10a8
 * Константы: 0x300A0ED0, 0xFFFFFFFF
 * Данные: DAT_300a1274, DAT_300a1278, DAT_300a1280, DAT_300a1284, DAT_300a1288, DAT_300a128c, DAT_300a1290, DAT_300a1294
 * ---------------------------------------------------------------- */
undefined4 FUN_300a0ed0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  code *pcVar5;
  
  iVar1 = FUN_300a0548();
  uVar2 = DAT_300a1274;
  if (iVar1 != 0) {
    if (param_3 != -1) {
      uVar2 = FUN_300a0578(param_2,param_1);
      uVar3 = FUN_300a0588(param_3 + param_2,param_1);
      uVar2 = FUN_300a05bc(uVar2,uVar3,*(undefined4 *)(DAT_300a1278 + param_1 * 4),param_1,4);
      return uVar2;
    }
    pcVar5 = *(code **)(DAT_300a1294 + param_1 * 0x3c);
    uVar2 = DAT_300a1280;
    if (pcVar5 != (code *)0x0) {
      param_1 = param_1 * 4;
      uVar2 = (*pcVar5)(*(undefined4 *)(DAT_300a1288 + param_1),
                        *(undefined4 *)(DAT_300a128c + param_1),
                        *(undefined4 *)(DAT_300a1278 + param_1),
                        *(undefined4 *)(DAT_300a1290 + param_1),
                        *(undefined4 *)(DAT_300a1284 + param_1));
      return uVar2;
    }
  }
  puVar4 = (undefined4 *)__errno();
  *puVar4 = uVar2;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300a0fbc @ 0x300A0FBC  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300a0548, FUN_300a0578, FUN_300a0588, FUN_300a05bc, __errno
 * Константы: 0x300A0FBC, 0xFFFFFFFF
 * Данные: DAT_300a1274, DAT_300a1278, DAT_300a1280, DAT_300a1284, DAT_300a1288, DAT_300a128c, DAT_300a1290, DAT_300a1298
 * ---------------------------------------------------------------- */
undefined4 FUN_300a0fbc(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  code *pcVar5;
  
  iVar1 = FUN_300a0548();
  uVar2 = DAT_300a1274;
  if (iVar1 != 0) {
    if (param_3 != -1) {
      uVar2 = FUN_300a0578(param_2,param_1);
      uVar3 = FUN_300a0588(param_3 + param_2,param_1);
      uVar2 = FUN_300a05bc(uVar2,uVar3,*(undefined4 *)(DAT_300a1278 + param_1 * 4),param_1,5);
      return uVar2;
    }
    pcVar5 = *(code **)(DAT_300a1298 + param_1 * 0x3c);
    uVar2 = DAT_300a1280;
    if (pcVar5 != (code *)0x0) {
      param_1 = param_1 * 4;
      uVar2 = (*pcVar5)(*(undefined4 *)(DAT_300a1288 + param_1),
                        *(undefined4 *)(DAT_300a128c + param_1),
                        *(undefined4 *)(DAT_300a1278 + param_1),
                        *(undefined4 *)(DAT_300a1290 + param_1),
                        *(undefined4 *)(DAT_300a1284 + param_1));
      return uVar2;
    }
  }
  puVar4 = (undefined4 *)__errno();
  *puVar4 = uVar2;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300a10a8 @ 0x300A10A8  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_300a0548, FUN_300a0ddc, FUN_300a0ed0, __errno
 * Константы: 0x300A10A8
 * Данные: DAT_300a1274
 * ---------------------------------------------------------------- */
int FUN_300a10a8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_300a0548();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    iVar1 = 0;
    *puVar2 = DAT_300a1274;
  }
  else {
    iVar1 = FUN_300a0ddc(param_1,param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = FUN_300a0ed0(param_1,param_2,param_3);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_300a1110 @ 0x300A1110  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_300a0548, __errno
 * Константы: 0xFFFFFFFF, 0x300A1110
 * Данные: DAT_300a1274, DAT_300a1278, DAT_300a1280, DAT_300a129c
 * ---------------------------------------------------------------- */
undefined4 FUN_300a1110(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  
  iVar1 = FUN_300a0548(0);
  uVar3 = DAT_300a1274;
  if (iVar1 != 0) {
    uVar5 = FUN_300a0548(1);
    iVar1 = (int)((ulonglong)uVar5 >> 0x20);
    uVar3 = DAT_300a1274;
    if (((int)uVar5 != 0) && (uVar3 = DAT_300a1280, iVar1 != -1)) {
      if (*(int *)(DAT_300a129c + 0x54) == 0) {
        if (*(int *)(DAT_300a129c + 0x18) == 0) {
          return 0xffffffff;
        }
        iVar2 = 0;
      }
      else {
        iVar2 = 1;
      }
      uVar3 = (**(code **)(iVar2 * 0x3c + DAT_300a129c + 0x18))
                        (param_1,iVar1,*DAT_300a1278,DAT_300a1278[1]);
      return uVar3;
    }
  }
  puVar4 = (undefined4 *)__errno();
  *puVar4 = uVar3;
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_300a11bc @ 0x300A11BC  (примерный размер ~228 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: __errno
 * Константы: 0x300A11BC
 * Данные: DAT_300a125c, DAT_300a1280
 * ---------------------------------------------------------------- */
int FUN_300a11bc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)*DAT_300a125c;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)__errno();
    iVar1 = -1;
    *puVar2 = DAT_300a1280;
  }
  else {
    iVar1 = (*(code *)*puVar2)(1,param_1,param_2);
    if (iVar1 == 0) {
      iVar1 = (*(code *)puVar2[1])(0,param_1,param_2);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * _dbgArchInit @ 0x300A12A0  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: dbgInit
 * Константы: 0x300A12A0
 * Данные: DAT_300a1494, DAT_300a1498
 * ---------------------------------------------------------------- */
void _dbgArchInit(void)

{
  *DAT_300a1498 = DAT_300a1494;
  return;
}

/* ----------------------------------------------------------------
 * _dbgInstSizeGet @ 0x300A12B0  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: dsmNbytes
 * Вызывают: FUN_30114a38
 * Константы: 0x300A12B0
 * ---------------------------------------------------------------- */
uint _dbgInstSizeGet(void)

{
  uint uVar1;
  
  uVar1 = dsmNbytes();
  return uVar1 >> 2;
}

/* ----------------------------------------------------------------
 * _dbgRetAdrsGet @ 0x300A12C0  (примерный размер ~252 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30114a38
 * Константы: 0x300A12C0, 0xFFFFFFF0
 * Данные: DAT_300a149c, DAT_300a14a0, DAT_300a14a4, DAT_300a14a8, DAT_300a14ac, DAT_300a14b0, DAT_300a14b4, DAT_300a14b8
 * ---------------------------------------------------------------- */
undefined4 _dbgRetAdrsGet(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = *(int *)(param_1 + 0x3c);
  bVar5 = *(int *)(param_1 + 0x2c) == 0;
  if (!bVar5) {
    piVar1 = (int *)(iVar4 + 4);
    iVar2 = 3;
    do {
      piVar1 = piVar1 + -1;
      if (*piVar1 == DAT_300a149c) break;
      iVar2 = iVar2 + -1;
    } while (-1 < iVar2);
    iVar3 = iVar2 + -3;
    if (iVar2 + -1 < 0 == SCARRY4(iVar3,2)) {
      iVar2 = iVar4 + iVar3 * 4;
      if ((*(uint *)(iVar2 + 4) & DAT_300a14a0) == DAT_300a14a4) {
        bVar5 = *(int *)(iVar2 + 8) == DAT_300a14a8;
        if (bVar5) goto LAB_300a13a8;
        goto LAB_300a1348;
      }
    }
    else {
LAB_300a1348:
      if (iVar3 < -3) goto LAB_300a13b0;
    }
    iVar4 = iVar4 + iVar3 * 4;
    if (((*(uint *)(iVar4 + 8) & DAT_300a14a0) != DAT_300a14a4) ||
       ((*(uint *)(iVar4 + 0xc) & DAT_300a14ac) != DAT_300a14b0)) goto LAB_300a13b0;
    bVar5 = (*(uint *)(iVar4 + 4) & 0xfffffff0) == DAT_300a14b4;
    if (!bVar5) {
      bVar5 = (*(uint *)(iVar4 + 4) & DAT_300a14ac) == DAT_300a14b8;
    }
  }
LAB_300a13a8:
  if (bVar5) {
    return *(undefined4 *)(param_1 + 0x38);
  }
LAB_300a13b0:
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + -4);
}

/* ----------------------------------------------------------------
 * _dbgFuncCallCheck @ 0x300A13BC  (примерный размер ~72 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: armInstrChangesPc
 * Вызывают: FUN_30114a38
 * Константы: 0x300A13BC, 0x0F000000, 0x0B000000, 0x0FFFFFFF
 * Данные: DAT_300a14bc
 * ---------------------------------------------------------------- */
undefined4 _dbgFuncCallCheck(uint *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*param_1 & 0xf000000) == 0xb000000) ||
     (((param_1[-1] & 0xfffffff) == DAT_300a14bc && (iVar1 = armInstrChangesPc(), iVar1 != 0)))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * _dbgTaskPCSet @ 0x300A1404  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: taskRegsGet, taskRegsSet
 * Вызывают: FUN_30114a38
 * Константы: 0x300A1404
 * ---------------------------------------------------------------- */
void _dbgTaskPCSet(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_54 [60];
  undefined4 local_18;
  
  iVar1 = taskRegsGet(param_1,auStack_54);
  if (iVar1 == 0) {
    local_18 = param_2;
    taskRegsSet(param_1,auStack_54);
  }
  return;
}

/* ----------------------------------------------------------------
 * _dbgTaskPCGet @ 0x300A143C  (примерный размер ~352 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: taskRegsGet
 * Вызывают: FUN_30114a38
 * Константы: 0x300A143C
 * ---------------------------------------------------------------- */
undefined4 _dbgTaskPCGet(undefined4 param_1)

{
  undefined1 auStack_4c [60];
  undefined4 local_10;
  
  taskRegsGet(param_1,auStack_4c);
  return local_10;
}

