/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : kernel — ядро VxWorks 6.8: задачи, семафоры, очереди, прерывания, память, планировщик
 * Часть  : 6 (функций: 150, адреса 0x3011EED8..0x30124A88)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * qFifoEach @ 0x3011EED8  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011EED8
 * ---------------------------------------------------------------- */
int * qFifoEach(int *param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  
  param_1 = (int *)*param_1;
  if (param_1 != (int *)0x0) {
    iVar1 = (*param_2)(param_1,param_3);
    while ((iVar1 != 0 && (param_1 = (int *)*param_1, param_1 != (int *)0x0))) {
      iVar1 = (*param_2)(param_1,param_3);
    }
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * qFifoNext @ 0x3011EF44  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011EF44
 * ---------------------------------------------------------------- */
undefined4 qFifoNext(undefined4 param_1,undefined4 *param_2)

{
  return *param_2;
}

/* ----------------------------------------------------------------
 * qInit @ 0x3011EF4C  (примерный размер ~196 байт)
 * Модуль: kernel | Вызывают: 9 | Вызывает: 1
 * Вызывает: __errno
 * Вызывают: kernelInit, msgQInit, pause, semQInit, semRWInitialize, sigsuspend, sigtimedwait, taskInitialize, usrKernelInit
 * Константы: 0x3011EF4C, 0xFFFFFFFF
 * Данные: DAT_3011f1a0
 * ---------------------------------------------------------------- */
undefined4 qInit(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uStack_48;
  undefined4 local_44 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  if (*(int *)(param_2 + 0x40) == param_2) {
    puVar3 = &uStack_48;
    iVar4 = 10;
    puVar1 = &uStack_8;
    do {
      puVar3 = puVar3 + 1;
      *puVar3 = *puVar1;
      iVar4 = iVar4 + -1;
      puVar1 = puVar1 + 1;
    } while (iVar4 != 0);
    *(int *)(param_1 + 0xc) = param_2;
    uVar2 = (**(code **)(param_2 + 4))
                      (param_1,local_44[0],local_44[1],local_44[2],local_44[3],local_34,local_30,
                       local_2c,local_28,local_24,local_20);
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_3011f1a0;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * qTerminate @ 0x3011F010  (примерный размер ~56 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F010, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 qTerminate(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0xc))();
  if (iVar1 == 0) {
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * qFirst @ 0x3011F048  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F048
 * ---------------------------------------------------------------- */
undefined4 qFirst(undefined4 *param_1)

{
  return *param_1;
}

/* ----------------------------------------------------------------
 * qPut @ 0x3011F050  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F050
 * ---------------------------------------------------------------- */
void qPut(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x10))();
  return;
}

/* ----------------------------------------------------------------
 * qGet @ 0x3011F070  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F070
 * ---------------------------------------------------------------- */
void qGet(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x14))();
  return;
}

/* ----------------------------------------------------------------
 * qRemove @ 0x3011F090  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F090
 * ---------------------------------------------------------------- */
void qRemove(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x18))();
  return;
}

/* ----------------------------------------------------------------
 * qResort @ 0x3011F0B0  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F0B0
 * ---------------------------------------------------------------- */
void qResort(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))();
  return;
}

/* ----------------------------------------------------------------
 * qAdvance @ 0x3011F0D0  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F0D0
 * ---------------------------------------------------------------- */
void qAdvance(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x20))();
  return;
}

/* ----------------------------------------------------------------
 * qGetExpired @ 0x3011F0F0  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F0F0
 * ---------------------------------------------------------------- */
void qGetExpired(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x24))();
  return;
}

/* ----------------------------------------------------------------
 * qKey @ 0x3011F110  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F110
 * ---------------------------------------------------------------- */
void qKey(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x28))(param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * qCalibrate @ 0x3011F138  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F138
 * ---------------------------------------------------------------- */
void qCalibrate(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x2c))();
  return;
}

/* ----------------------------------------------------------------
 * qInfo @ 0x3011F158  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F158
 * ---------------------------------------------------------------- */
void qInfo(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x30))();
  return;
}

/* ----------------------------------------------------------------
 * qEach @ 0x3011F178  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F178
 * ---------------------------------------------------------------- */
void qEach(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x34))();
  return;
}

/* ----------------------------------------------------------------
 * qNullRtn @ 0x3011F198  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F198
 * ---------------------------------------------------------------- */
undefined4 qNullRtn(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * qPriBMapInit @ 0x3011F1A4  (примерный размер ~140 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: bzero, dllInit, errnoSet
 * Константы: 0xFFFFFFFF, 0x3011F1A4
 * Данные: DAT_3011f7b4, DAT_3011f7b8
 * ---------------------------------------------------------------- */
undefined4 qPriBMapInit(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (DAT_3011f7b4 < param_3 - 1U) {
    return 0xffffffff;
  }
  if (param_2 == (undefined4 *)0x0) {
    errnoSet(DAT_3011f7b8);
    return 0xffffffff;
  }
  param_1[1] = param_2;
  if (param_3 != 0) {
    puVar1 = param_2 + 10;
    iVar2 = param_3;
    do {
      dllInit(puVar1);
      puVar1 = puVar1 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  *param_1 = 0;
  param_1[2] = param_3;
  *param_2 = 0;
  bzero(param_2 + 1,0x24);
  return 0;
}

/* ----------------------------------------------------------------
 * qTradPriBMapSetCompatible @ 0x3011F230  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F230
 * Данные: DAT_3011f7bc, DAT_3011f7c0, DAT_3011f7c4
 * ---------------------------------------------------------------- */
void qTradPriBMapSetCompatible(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_3011f7c0;
  *(undefined4 *)(*DAT_3011f7bc + 0x1c) = DAT_3011f7c0;
  *DAT_3011f7c4 = uVar1;
  return;
}

/* ----------------------------------------------------------------
 * qPriBMapSet @ 0x3011F24C  (примерный размер ~56 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F24C
 * ---------------------------------------------------------------- */
void qPriBMapSet(uint *param_1,uint param_2)

{
  *param_1 = *param_1 | 1 << ((int)param_2 >> 5 & 0xffU);
  param_1[((int)param_2 >> 5) + 1] = param_1[((int)param_2 >> 5) + 1] | 1 << (param_2 & 0x1f);
  return;
}

/* ----------------------------------------------------------------
 * qPriBMapPut @ 0x3011F284  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: dllAdd
 * Вызывают: FUN_3011f5b4, qPriBMapResort
 * Константы: 0x3011F284
 * ---------------------------------------------------------------- */
void qPriBMapPut(int *param_1,int param_2,uint param_3)

{
  uint *puVar1;
  
  *(uint *)(param_2 + 8) = param_3;
  if ((*param_1 == 0) || (param_3 < *(uint *)(*param_1 + 8))) {
    *param_1 = param_2;
  }
  puVar1 = (uint *)param_1[1];
  *puVar1 = *puVar1 | 1 << ((int)param_3 >> 5 & 0xffU);
  puVar1[((int)param_3 >> 5) + 1] = puVar1[((int)param_3 >> 5) + 1] | 1 << (param_3 & 0x1f);
  dllAdd(puVar1 + param_3 * 2 + 10);
  return;
}

/* ----------------------------------------------------------------
 * qPriBMapRemove @ 0x3011F2F0  (примерный размер ~300 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 1
 * Вызывает: ffsLsb
 * Вызывают: FUN_3011f5b4, qPriBMapGet, qPriBMapResort
 * Константы: 0x3011F2F0
 * ---------------------------------------------------------------- */
undefined4 qPriBMapRemove(uint *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  if ((int *)param_2[1] == (int *)0x0) {
    *(int *)(param_1[1] + param_2[2] * 8 + 0x28) = *param_2;
  }
  else {
    *(int *)param_2[1] = *param_2;
  }
  if (*param_2 == 0) {
    *(int *)(param_1[1] + param_2[2] * 8 + 0x2c) = param_2[1];
  }
  else {
    *(int *)(*param_2 + 4) = param_2[1];
  }
  uVar4 = param_2[2];
  puVar5 = (uint *)param_1[1];
  if (puVar5[uVar4 * 2 + 10] == 0) {
    uVar1 = (int)uVar4 >> 5;
    uVar4 = puVar5[uVar1 + 1] & ~(1 << (uVar4 & 0x1f));
    puVar5[uVar1 + 1] = uVar4;
    if (uVar4 == 0) {
      *puVar5 = *puVar5 & ~(1 << (uVar1 & 0xff));
    }
    if ((int *)*param_1 == param_2) {
      iVar2 = ffsLsb(*puVar5);
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        iVar3 = ffsLsb(puVar5[iVar2]);
        uVar4 = iVar3 - 1U | (iVar2 + -1) * 0x20;
      }
      *param_1 = *(uint *)(param_1[1] + uVar4 * 8 + 0x28);
    }
  }
  else if ((int *)*param_1 == param_2) {
    *param_1 = puVar5[((int *)*param_1)[2] * 2 + 10];
  }
  return 0;
}

/* ----------------------------------------------------------------
 * qPriBMapGet @ 0x3011F41C  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: qPriBMapRemove
 * Константы: 0x3011F41C
 * ---------------------------------------------------------------- */
int qPriBMapGet(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    qPriBMapRemove(param_1,iVar1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * qPriBMapRestore @ 0x3011F43C  (примерный размер ~128 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllInsert
 * Константы: 0x3011F43C
 * ---------------------------------------------------------------- */
void qPriBMapRestore(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  *(uint *)(param_2 + 8) = param_3;
  iVar2 = *param_1;
  iVar1 = 0;
  if ((iVar2 == 0) || (param_3 < *(uint *)(iVar2 + 8))) {
    *param_1 = param_2;
  }
  else if (*(uint *)(iVar2 + 8) == param_3) {
    iVar1 = iVar2;
  }
  puVar3 = (uint *)param_1[1];
  *puVar3 = *puVar3 | 1 << ((int)param_3 >> 5 & 0xffU);
  puVar3[((int)param_3 >> 5) + 1] = puVar3[((int)param_3 >> 5) + 1] | 1 << (param_3 & 0x1f);
  dllInsert(puVar3 + param_3 * 2 + 10,iVar1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * qPriBMapNext @ 0x3011F4BC  (примерный размер ~196 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: ffsLsb
 * Константы: 0x3011F4BC
 * ---------------------------------------------------------------- */
uint qPriBMapNext(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  if (*param_2 != 0) {
    return *param_2;
  }
  puVar3 = *(uint **)(param_1 + 4);
  iVar2 = (int)param_2[2] >> 5;
  uVar4 = param_2[2] + 1 & 0x1f;
  if ((uVar4 == 0) || (iVar1 = ffsLsb(puVar3[iVar2 + 1] & ~((1 << uVar4) - 1U)), iVar1 == 0)) {
    iVar2 = ffsLsb(*puVar3 & ~((1 << (iVar2 + 1U & 0xff)) - 1U));
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = ffsLsb(puVar3[iVar2]);
    uVar4 = iVar1 - 1U | (iVar2 + -1) * 0x20;
  }
  else {
    uVar4 = iVar1 - 1U | iVar2 << 5;
  }
  return puVar3[uVar4 * 2 + 10];
}

/* ----------------------------------------------------------------
 * qPriBMapResort @ 0x3011F580  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: qPriBMapPut, qPriBMapRemove
 * Константы: 0x3011F580
 * ---------------------------------------------------------------- */
void qPriBMapResort(undefined4 param_1,int param_2,int param_3)

{
  if (*(int *)(param_2 + 8) == param_3) {
    return;
  }
  qPriBMapRemove();
  qPriBMapPut(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3011f5b4 @ 0x3011F5B4  (примерный размер ~184 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: dllInsert, qPriBMapPut, qPriBMapRemove
 * Константы: 0x3011F5B4
 * ---------------------------------------------------------------- */
void FUN_3011f5b4(int *param_1,int param_2,uint param_3)

{
  uint *puVar1;
  
  if (param_3 < *(uint *)(param_2 + 8)) {
    qPriBMapRemove(param_1,param_2);
    qPriBMapPut(param_1,param_2,param_3);
  }
  else {
    if (param_3 <= *(uint *)(param_2 + 8)) {
      return;
    }
    qPriBMapRemove(param_1,param_2);
    *(uint *)(param_2 + 8) = param_3;
    if ((*param_1 == 0) || (param_3 <= *(uint *)(*param_1 + 8))) {
      *param_1 = param_2;
    }
    puVar1 = (uint *)param_1[1];
    *puVar1 = *puVar1 | 1 << ((int)param_3 >> 5 & 0xffU);
    puVar1[((int)param_3 >> 5) + 1] = puVar1[((int)param_3 >> 5) + 1] | 1 << (param_3 & 0x1f);
    dllInsert(puVar1 + param_3 * 2 + 10,0,param_2);
  }
  return;
}

/* ----------------------------------------------------------------
 * qPriBMapKey @ 0x3011F66C  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F66C
 * ---------------------------------------------------------------- */
undefined4 qPriBMapKey(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}

/* ----------------------------------------------------------------
 * qPriBMapInfo @ 0x3011F674  (примерный размер ~188 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllCount
 * Константы: 0x3011F674
 * ---------------------------------------------------------------- */
int qPriBMapInfo(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = 0;
  uVar4 = 0;
  if (param_2 == (int *)0x0) {
    if (*(int *)(param_1 + 8) != 0) {
      do {
        iVar1 = dllCount(*(int *)(param_1 + 4) + uVar4 * 8 + 0x28);
        uVar4 = uVar4 + 1;
        iVar5 = iVar1 + iVar5;
      } while (uVar4 < *(uint *)(param_1 + 8));
    }
    return iVar5;
  }
  piVar3 = param_2;
  if (*(int *)(param_1 + 8) != 0) {
    piVar2 = (int *)(*(int *)(param_1 + 4) + 0x28);
    do {
      for (piVar6 = (int *)*piVar2; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
        param_3 = param_3 + -1;
        if (param_3 < 0) goto LAB_3011f724;
        *piVar3 = (int)piVar6;
        piVar3 = piVar3 + 1;
      }
      if (param_3 < 0) break;
      piVar2 = piVar2 + 2;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 8));
  }
LAB_3011f724:
  return (int)piVar3 - (int)param_2 >> 2;
}

/* ----------------------------------------------------------------
 * qPriBMapEach @ 0x3011F730  (примерный размер ~152 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F730
 * ---------------------------------------------------------------- */
int qPriBMapEach(int param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      for (piVar3 = *(int **)(*(int *)(param_1 + 4) + uVar2 * 8 + 0x28); piVar3 != (int *)0x0;
          piVar3 = (int *)*piVar3) {
        iVar1 = (*param_2)(piVar3,param_3);
        if (iVar1 == 0) {
          return (int)piVar3;
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 8));
  }
  return 0;
}

/* ----------------------------------------------------------------
 * qPriDeltaInit @ 0x3011F7C8  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllInit
 * Константы: 0x3011F7C8
 * ---------------------------------------------------------------- */
undefined4 qPriDeltaInit(void)

{
  dllInit();
  return 0;
}

/* ----------------------------------------------------------------
 * qPriDeltaTerminate @ 0x3011F7D8  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F7D8
 * ---------------------------------------------------------------- */
undefined4 qPriDeltaTerminate(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * qPriDeltaPut @ 0x3011F7E0  (примерный размер ~120 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: dllInsert
 * Вызывают: qPriDeltaResort
 * Константы: 0x3011F7E0
 * ---------------------------------------------------------------- */
void qPriDeltaPut(int *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(undefined4 *)(param_2 + 8) = param_3;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      dllInsert(param_1,param_1[1],param_2);
      return;
    }
    if (*(uint *)(param_2 + 8) < (uint)piVar1[2]) break;
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) - piVar1[2];
    piVar1 = (int *)*piVar1;
  }
  dllInsert(param_1,piVar1[1],param_2);
  piVar1[2] = piVar1[2] - *(int *)(param_2 + 8);
  return;
}

/* ----------------------------------------------------------------
 * qPriDeltaGet @ 0x3011F858  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllGet
 * Константы: 0x3011F858
 * ---------------------------------------------------------------- */
void qPriDeltaGet(int *param_1)

{
  if (*param_1 != 0) {
    dllGet(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * qPriDeltaRemove @ 0x3011F874  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllRemove
 * Константы: 0x3011F874
 * ---------------------------------------------------------------- */
undefined4 qPriDeltaRemove(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 != 0) {
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + param_2[2];
  }
  dllRemove();
  return 0;
}

/* ----------------------------------------------------------------
 * qPriDeltaResort @ 0x3011F89C  (примерный размер ~72 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: dllRemove, qPriDeltaPut
 * Константы: 0x3011F89C
 * ---------------------------------------------------------------- */
void qPriDeltaResort(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 != 0) {
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + param_2[2];
  }
  dllRemove(param_1,param_2);
  qPriDeltaPut(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * qPriDeltaAdvance @ 0x3011F8E4  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F8E4
 * ---------------------------------------------------------------- */
void qPriDeltaAdvance(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return;
  }
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -1;
  return;
}

/* ----------------------------------------------------------------
 * qPriDeltaGetExpired @ 0x3011F900  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllRemove
 * Константы: 0x3011F900
 * ---------------------------------------------------------------- */
int * qPriDeltaGetExpired(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    if (piVar2[2] == 0) {
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 8);
      }
      dllRemove(param_1,piVar2);
    }
    else {
      piVar2 = (int *)0x0;
    }
  }
  return piVar2;
}

/* ----------------------------------------------------------------
 * qPriDeltaKey @ 0x3011F944  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F944
 * ---------------------------------------------------------------- */
int qPriDeltaKey(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 != 0) {
    do {
      piVar1 = (int *)(param_1 + 8);
      param_1 = *(int *)(param_1 + 4);
      iVar2 = iVar2 + *piVar1;
    } while (param_1 != 0);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * qPriDeltaInfo @ 0x3011F96C  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllCount
 * Константы: 0x3011F96C
 * ---------------------------------------------------------------- */
int qPriDeltaInfo(undefined4 *param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    iVar2 = dllCount();
  }
  else {
    while ((piVar3 != (int *)0x0 && (param_3 = param_3 + -1, -1 < param_3))) {
      *piVar1 = (int)piVar3;
      piVar3 = (int *)*piVar3;
      piVar1 = piVar1 + 1;
    }
    iVar2 = (int)piVar1 - (int)param_2 >> 2;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * qPriDeltaEach @ 0x3011F9B8  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011F9B8
 * ---------------------------------------------------------------- */
int * qPriDeltaEach(int *param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  
  param_1 = (int *)*param_1;
  if (param_1 != (int *)0x0) {
    iVar1 = (*param_2)(param_1,param_3);
    while ((iVar1 != 0 && (param_1 = (int *)*param_1, param_1 != (int *)0x0))) {
      iVar1 = (*param_2)(param_1,param_3);
    }
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * qPriDeltaNext @ 0x3011FA24  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011FA24
 * ---------------------------------------------------------------- */
undefined4 qPriDeltaNext(undefined4 param_1,undefined4 *param_2)

{
  return *param_2;
}

/* ----------------------------------------------------------------
 * qPriListInit @ 0x3011FA2C  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllInit
 * Константы: 0x3011FA2C, 0xFFFFFFFC
 * ---------------------------------------------------------------- */
undefined4 qPriListInit(int param_1,uint param_2)

{
  dllInit();
  if ((param_2 & 0xfffffffc) != 0) {
    param_2 = 0;
  }
  *(uint *)(param_1 + 8) = param_2;
  return 0;
}

/* ----------------------------------------------------------------
 * qTradPriListSetCompatible @ 0x3011FA54  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011FA54
 * Данные: DAT_3011fd90, DAT_3011fd94
 * ---------------------------------------------------------------- */
void qTradPriListSetCompatible(void)

{
  *(undefined4 *)(*DAT_3011fd90 + 0x1c) = DAT_3011fd94;
  return;
}

/* ----------------------------------------------------------------
 * qPriListTerminate @ 0x3011FA68  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011FA68
 * ---------------------------------------------------------------- */
undefined4 qPriListTerminate(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * qPriListPut @ 0x3011FA70  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: dllInsert
 * Вызывают: FUN_3011fb94, qPriListResort
 * Константы: 0x3011FA70
 * ---------------------------------------------------------------- */
void qPriListPut(int *param_1,int param_2,uint param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  *(uint *)(param_2 + 8) = param_3;
  do {
    if (piVar1 == (int *)0x0) {
      iVar2 = param_1[1];
LAB_3011faac:
      dllInsert(param_1,iVar2,param_2,param_4);
      return;
    }
    param_4 = param_3;
    if (param_3 < (uint)piVar1[2]) {
      iVar2 = piVar1[1];
      goto LAB_3011faac;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}

/* ----------------------------------------------------------------
 * qPriListPutFromTail @ 0x3011FABC  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllInsert
 * Константы: 0x3011FABC
 * ---------------------------------------------------------------- */
void qPriListPutFromTail(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(uint *)(param_2 + 8) = param_3;
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    param_4 = param_3;
    if (*(uint *)(iVar1 + 8) <= param_3) goto LAB_3011faf0;
  }
  iVar1 = 0;
LAB_3011faf0:
  dllInsert(param_1,iVar1,param_2,param_4);
  return;
}

/* ----------------------------------------------------------------
 * qPriListGet @ 0x3011FB00  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllGet
 * Константы: 0x3011FB00
 * ---------------------------------------------------------------- */
void qPriListGet(int *param_1)

{
  if (*param_1 != 0) {
    dllGet(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * qPriListRemove @ 0x3011FB1C  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllRemove
 * Константы: 0x3011FB1C
 * ---------------------------------------------------------------- */
undefined4 qPriListRemove(void)

{
  dllRemove();
  return 0;
}

/* ----------------------------------------------------------------
 * qPriListResort @ 0x3011FB2C  (примерный размер ~104 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: dllRemove, qPriListPut
 * Константы: 0x3011FB2C
 * ---------------------------------------------------------------- */
void qPriListResort(undefined4 param_1,int *param_2,uint param_3)

{
  if (((param_2[1] == 0) || (*(uint *)(param_2[1] + 8) <= param_3)) &&
     ((*param_2 == 0 || (param_3 <= *(uint *)(*param_2 + 8))))) {
    param_2[2] = param_3;
    return;
  }
  dllRemove(param_1,param_2);
  qPriListPut(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3011fb94 @ 0x3011FB94  (примерный размер ~180 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: dllInsert, dllRemove, qPriListPut
 * Константы: 0x3011FB94
 * ---------------------------------------------------------------- */
void FUN_3011fb94(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  
  if (((param_2[1] == 0) || (*(uint *)(param_2[1] + 8) <= param_3)) &&
     ((*param_2 == 0 || (param_3 <= *(uint *)(*param_2 + 8))))) {
    param_2[2] = param_3;
    return;
  }
  dllRemove(param_1,param_2);
  if (param_3 < (uint)param_2[2]) {
    qPriListPut(param_1,param_2,param_3);
  }
  else {
    piVar2 = (int *)*param_1;
    param_2[2] = param_3;
    for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if (param_3 <= (uint)piVar2[2]) {
        iVar1 = piVar2[1];
        goto LAB_3011fc38;
      }
    }
    iVar1 = param_1[1];
LAB_3011fc38:
    dllInsert(param_1,iVar1,param_2);
  }
  return;
}

/* ----------------------------------------------------------------
 * qPriListAdvance @ 0x3011FC48  (примерный размер ~4 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011FC48
 * ---------------------------------------------------------------- */
void qPriListAdvance(void)

{
  return;
}

/* ----------------------------------------------------------------
 * qPriListGetExpired @ 0x3011FC4C  (примерный размер ~52 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllGet
 * Константы: 0x3011FC4C
 * Данные: DAT_3011fd98
 * ---------------------------------------------------------------- */
undefined4 qPriListGetExpired(int *param_1)

{
  undefined4 uVar1;
  
  if ((*param_1 == 0) || (*DAT_3011fd98 < *(uint *)(*param_1 + 8))) {
    uVar1 = 0;
  }
  else {
    uVar1 = dllGet();
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * qPriListCalibrate @ 0x3011FC80  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011FC80
 * ---------------------------------------------------------------- */
void qPriListCalibrate(int *param_1,int param_2)

{
  param_1 = (int *)*param_1;
  if (param_1 == (int *)0x0) {
    return;
  }
  do {
    param_1[2] = param_2 + param_1[2];
    param_1 = (int *)*param_1;
  } while (param_1 != (int *)0x0);
  return;
}

/* ----------------------------------------------------------------
 * qPriListKey @ 0x3011FCA8  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011FCA8
 * Данные: DAT_3011fd98
 * ---------------------------------------------------------------- */
int qPriListKey(int param_1,int param_2)

{
  if (param_2 == 0) {
    return *(int *)(param_1 + 8);
  }
  return *(int *)(param_1 + 8) - *DAT_3011fd98;
}

/* ----------------------------------------------------------------
 * qPriListInfo @ 0x3011FCD0  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: dllCount
 * Константы: 0x3011FCD0
 * ---------------------------------------------------------------- */
int qPriListInfo(undefined4 *param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    iVar2 = dllCount();
  }
  else {
    while ((piVar3 != (int *)0x0 && (param_3 = param_3 + -1, -1 < param_3))) {
      *piVar1 = (int)piVar3;
      piVar3 = (int *)*piVar3;
      piVar1 = piVar1 + 1;
    }
    iVar2 = (int)piVar1 - (int)param_2 >> 2;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * qPriListEach @ 0x3011FD1C  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011FD1C
 * ---------------------------------------------------------------- */
int * qPriListEach(int *param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  
  param_1 = (int *)*param_1;
  if (param_1 != (int *)0x0) {
    iVar1 = (*param_2)(param_1,param_3);
    while ((iVar1 != 0 && (param_1 = (int *)*param_1, param_1 != (int *)0x0))) {
      iVar1 = (*param_2)(param_1,param_3);
    }
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * qPriListNext @ 0x3011FD88  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011FD88
 * ---------------------------------------------------------------- */
undefined4 qPriListNext(undefined4 param_1,undefined4 *param_2)

{
  return *param_2;
}

/* ----------------------------------------------------------------
 * rngFlush @ 0x3011FD9C  (примерный размер ~16 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300ef2f4, FUN_300ef370, rngCreate
 * Константы: 0x3011FD9C
 * ---------------------------------------------------------------- */
void rngFlush(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}

/* ----------------------------------------------------------------
 * rngCreate @ 0x3011FDAC  (примерный размер ~96 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: free, malloc, rngFlush
 * Вызывают: tyDevInit
 * Константы: 0x3011FDAC
 * ---------------------------------------------------------------- */
void * rngCreate(int param_1)

{
  void *__ptr;
  void *pvVar1;
  
  __ptr = malloc(0x10);
  if (__ptr == (void *)0x0) {
    return (void *)0x0;
  }
  pvVar1 = malloc(param_1 + 1U);
  if (pvVar1 == (void *)0x0) {
    free(__ptr);
    return (void *)0x0;
  }
  *(size_t *)((int)__ptr + 8) = param_1 + 1U;
  *(void **)((int)__ptr + 0xc) = pvVar1;
  rngFlush(__ptr);
  return __ptr;
}

/* ----------------------------------------------------------------
 * rngDelete @ 0x3011FE0C  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: free
 * Вызывают: tyDevRemove, tyDevTerminate
 * Константы: 0x3011FE0C
 * ---------------------------------------------------------------- */
void rngDelete(void *param_1)

{
  free(*(void **)((int)param_1 + 0xc));
  free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * rngBufGet @ 0x3011FE28  (примерный размер ~200 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: bcopy
 * Вызывают: tyRead
 * Константы: 0x3011FE28
 * ---------------------------------------------------------------- */
size_t rngBufGet(size_t *param_1,void *param_2,size_t param_3)

{
  size_t __n;
  size_t sVar1;
  size_t sVar2;
  
  __n = *param_1;
  sVar2 = param_1[1];
  sVar1 = param_3;
  if ((int)__n < (int)sVar2) {
    if ((int)(param_1[2] - sVar2) <= (int)param_3) {
      sVar1 = param_1[2] - sVar2;
    }
    bcopy((void *)(param_1[3] + sVar2),param_2,sVar1);
    sVar2 = sVar1 + param_1[1];
    if (param_1[2] == sVar2) {
      if ((int)(param_3 - sVar1) < (int)__n) {
        __n = param_3 - sVar1;
      }
      bcopy((void *)param_1[3],(void *)((int)param_2 + sVar1),__n);
      param_1[1] = __n;
      return sVar1 + __n;
    }
  }
  else {
    if ((int)(__n - sVar2) <= (int)param_3) {
      sVar1 = __n - sVar2;
    }
    bcopy((void *)(param_1[3] + sVar2),param_2,sVar1);
    sVar2 = sVar1 + param_1[1];
  }
  param_1[1] = sVar2;
  return sVar1;
}

/* ----------------------------------------------------------------
 * rngBufPut @ 0x3011FEF0  (примерный размер ~220 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: bcopy
 * Вызывают: tyIRd, tyWrite
 * Константы: 0x3011FEF0
 * ---------------------------------------------------------------- */
size_t rngBufPut(size_t *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  
  sVar1 = param_1[1];
  sVar3 = *param_1;
  sVar2 = param_3;
  if ((int)sVar1 <= (int)sVar3) {
    if (sVar1 != 0) {
      if ((int)(param_1[2] - sVar3) <= (int)param_3) {
        sVar2 = param_1[2] - sVar3;
      }
      bcopy(param_2,(void *)(param_1[3] + sVar3),sVar2);
      sVar3 = sVar2 + *param_1;
      if (param_1[2] == sVar3) {
        param_3 = param_3 - sVar2;
        if ((int)(sVar1 - 1) <= (int)param_3) {
          param_3 = sVar1 - 1;
        }
        bcopy((void *)((int)param_2 + sVar2),(void *)param_1[3],param_3);
        *param_1 = param_3;
        return sVar2 + param_3;
      }
      goto LAB_3011ffc0;
    }
    sVar1 = param_1[2];
  }
  if ((int)((sVar1 - sVar3) + -1) <= (int)param_3) {
    sVar2 = (sVar1 - sVar3) - 1;
  }
  bcopy(param_2,(void *)(param_1[3] + sVar3),sVar2);
  sVar3 = sVar2 + *param_1;
LAB_3011ffc0:
  *param_1 = sVar3;
  return sVar2;
}

/* ----------------------------------------------------------------
 * rngIsEmpty @ 0x3011FFCC  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: tyRead
 * Константы: 0x3011FFCC
 * ---------------------------------------------------------------- */
bool rngIsEmpty(int *param_1)

{
  return *param_1 == param_1[1];
}

/* ----------------------------------------------------------------
 * rngIsFull @ 0x3011FFE4  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3011FFE4
 * ---------------------------------------------------------------- */
undefined4 rngIsFull(int *param_1)

{
  if ((*param_1 - param_1[1] != -1) && (param_1[2] != (*param_1 - param_1[1]) + 1)) {
    return 0;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * rngFreeBytes @ 0x30120014  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 0
 * Вызывают: FUN_300eecf8, FUN_300eedcc, FUN_300eee5c, tyIRd, tyITx, tyRead, tyWrite
 * Константы: 0x30120014
 * ---------------------------------------------------------------- */
int rngFreeBytes(int *param_1)

{
  int iVar1;
  
  iVar1 = (param_1[1] - *param_1) + -1;
  if (iVar1 < 0) {
    iVar1 = iVar1 + param_1[2];
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * rngNBytes @ 0x30120038  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_300ed7fc, FUN_300eecf8, FUN_300eedcc, FUN_300eee5c, tyIRd
 * Константы: 0x30120038
 * ---------------------------------------------------------------- */
int rngNBytes(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 - param_1[1];
  if (iVar1 < 0) {
    iVar1 = iVar1 + param_1[2];
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * rngPutAhead @ 0x30120058  (примерный размер ~40 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: tyIRd
 * Константы: 0x30120058
 * ---------------------------------------------------------------- */
void rngPutAhead(int *param_1,undefined1 param_2,int param_3)

{
  param_3 = param_3 + *param_1;
  if (param_1[2] <= param_3) {
    param_3 = param_3 - param_1[2];
  }
  *(undefined1 *)(param_1[3] + param_3) = param_2;
  return;
}

/* ----------------------------------------------------------------
 * rngMoveAhead @ 0x30120080  (примерный размер ~28 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: tyIRd
 * Константы: 0x30120080
 * ---------------------------------------------------------------- */
void rngMoveAhead(int *param_1,int param_2)

{
  param_2 = param_2 + *param_1;
  if (param_1[2] <= param_2) {
    param_2 = param_2 - param_1[2];
  }
  *param_1 = param_2;
  return;
}

/* ----------------------------------------------------------------
 * sllInit @ 0x3012009C  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 0
 * Вызывают: hashTblInit, loadSegInfoDescAllocate, memPartInit, msgQInit
 * Константы: 0x3012009C
 * ---------------------------------------------------------------- */
undefined4 sllInit(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * sllTerminate @ 0x301200B0  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x301200B0
 * ---------------------------------------------------------------- */
undefined4 sllTerminate(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * sllPutAtHead @ 0x301200B8  (примерный размер ~24 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: hashTblPut
 * Константы: 0x301200B8
 * ---------------------------------------------------------------- */
void sllPutAtHead(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_2 = iVar1;
  if (iVar1 == 0) {
    param_1[1] = (int)param_2;
  }
  *param_1 = (int)param_2;
  return;
}

/* ----------------------------------------------------------------
 * sllPutAtTail @ 0x301200D0  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_300f1e5c, FUN_300f9b38, loadSegInfoDescAllocate
 * Константы: 0x301200D0
 * ---------------------------------------------------------------- */
void sllPutAtTail(int *param_1,undefined4 *param_2)

{
  *param_2 = 0;
  if (*param_1 == 0) {
    *param_1 = (int)param_2;
  }
  else {
    *(undefined4 **)param_1[1] = param_2;
  }
  param_1[1] = (int)param_2;
  return;
}

/* ----------------------------------------------------------------
 * sllGet @ 0x301200F4  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: loadSegInfoDescFree
 * Константы: 0x301200F4
 * ---------------------------------------------------------------- */
int sllGet(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if ((piVar1 != (int *)0x0) && (*param_1 = *piVar1, (int *)param_1[1] == piVar1)) {
    param_1[1] = 0;
  }
  return (int)piVar1;
}

/* ----------------------------------------------------------------
 * sllRemove @ 0x30120124  (примерный размер ~60 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: hashTblRemove
 * Константы: 0x30120124
 * ---------------------------------------------------------------- */
void sllRemove(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_3 == (undefined4 *)0x0) {
    *param_1 = *param_2;
    if ((undefined4 *)param_1[1] != param_2) {
      return;
    }
    param_3 = (undefined4 *)0x0;
  }
  else {
    *param_3 = *param_2;
    if ((undefined4 *)param_1[1] != param_2) {
      return;
    }
  }
  param_1[1] = param_3;
  return;
}

/* ----------------------------------------------------------------
 * sllPrevious @ 0x30120160  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: hashTblRemove
 * Константы: 0x30120160
 * ---------------------------------------------------------------- */
int * sllPrevious(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  param_1 = (int *)*param_1;
  if ((param_1 != (int *)0x0) && (param_1 != param_2)) {
    iVar2 = *param_1;
    while (iVar2 != 0) {
      piVar1 = (int *)*param_1;
      if (piVar1 == param_2) {
        return param_1;
      }
      param_1 = piVar1;
      iVar2 = *piVar1;
    }
  }
  return (int *)0x0;
}

/* ----------------------------------------------------------------
 * sllCount @ 0x301201A4  (примерный размер ~36 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x301201A4
 * ---------------------------------------------------------------- */
int sllCount(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
      param_1 = (undefined4 *)*param_1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * sllEach @ 0x301201C8  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: hashTblEach, msgQInfoGet
 * Константы: 0x301201C8
 * ---------------------------------------------------------------- */
int sllEach(int *param_1,code *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  do {
    piVar1 = piVar3;
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    piVar3 = (int *)*piVar1;
    iVar2 = (*param_2)(piVar1,param_3);
  } while (iVar2 != 0);
  return (int)piVar1;
}

/* ----------------------------------------------------------------
 * FUN_3012021c @ 0x3012021C  (примерный размер ~184 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 4
 * Вызывает: calloc, lstAdd, strcpy, strlen
 * Вызывают: FUN_301204a4, symListGet
 * Константы: 0x3012021C
 * ---------------------------------------------------------------- */
undefined4 FUN_3012021c(char *param_1,char *param_2,int param_3,undefined4 param_4)

{
  size_t sVar1;
  void *pvVar2;
  char *__dest;
  int iVar3;
  
  iVar3 = 0;
  if (param_2 != (char *)0x0) {
    sVar1 = strlen(param_2);
    iVar3 = sVar1 + 1;
  }
  sVar1 = strlen(param_1);
  pvVar2 = calloc(1,sVar1 + iVar3 + 0x19);
  if (pvVar2 == (void *)0x0) {
    return 0;
  }
  *(char **)((int)pvVar2 + 8) = (char *)((int)pvVar2 + 0x18);
  strcpy((char *)((int)pvVar2 + 0x18),param_1);
  *(int *)((int)pvVar2 + 0x14) = param_3;
  sVar1 = strlen(param_1);
  __dest = (char *)(*(int *)((int)pvVar2 + 8) + sVar1 + 1);
  if (param_3 == 2) {
    *(char **)((int)pvVar2 + 0xc) = __dest;
  }
  else {
    if (param_3 != 3) goto LAB_301202c0;
    *(char **)((int)pvVar2 + 0x10) = __dest;
  }
  strcpy(__dest,param_2);
LAB_301202c0:
  lstAdd(param_4,pvVar2);
  return 1;
}

/* ----------------------------------------------------------------
 * symListGet @ 0x301202D4  (примерный размер ~464 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 12
 * Вызывает: FUN_3012021c, calloc, cplusDemangleToBuffer, cplusMangledSymCheck, free, lstCount, lstGet, lstInit, strlen, strncmp, strncpy, symEach
 * Вызывают: FUN_301040fc, completionSymListGet
 * Константы: 0x301202D4
 * Данные: DAT_301204e0, DAT_301204e4
 * ---------------------------------------------------------------- */
void symListGet(int param_1,byte *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  size_t __n;
  void *__ptr;
  byte *pbVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *local_148;
  undefined4 local_144;
  undefined1 *local_140;
  byte *local_13c;
  undefined1 auStack_138 [12];
  undefined1 auStack_12c [256];
  undefined1 uStack_2c;
  
  if (param_1 != 0) {
    lstInit(auStack_138);
    local_140 = auStack_138;
    if (param_3 == 0) {
      uVar3 = 1;
      local_13c = param_2;
    }
    else {
      for (pbVar2 = param_2;
          ((*(byte *)(*DAT_301204e0 + (uint)*pbVar2) & 7) != 0 || (*pbVar2 == 0x5f));
          pbVar2 = pbVar2 + 1) {
      }
      local_13c = (byte *)calloc(1,(size_t)(pbVar2 + (1 - (int)param_2)));
      if (local_13c == (byte *)0x0) {
        return;
      }
      strncpy((char *)local_13c,(char *)param_2,(int)pbVar2 - (int)param_2);
      uVar3 = 2;
    }
    symEach(param_1,DAT_301204e4,&local_140);
    if (param_3 != 0) {
      free(local_13c);
    }
    iVar1 = lstCount(auStack_138);
    if (iVar1 != 0) {
      __n = strlen((char *)param_2);
      __ptr = (void *)lstGet(auStack_138);
      while (__ptr != (void *)0x0) {
        uStack_2c = 0;
        local_144 = 0x100;
        cplusDemangleToBuffer
                  (*(undefined4 *)((int)__ptr + 8),auStack_12c,&local_144,uVar3,&local_148);
        if (param_3 == 0) {
          iVar1 = strncmp(local_148,(char *)param_2,__n);
          if ((iVar1 == 0) &&
             (iVar1 = cplusMangledSymCheck(*(undefined4 *)((int)__ptr + 8)), iVar1 != 0)) {
            uVar4 = 2;
          }
          else {
            iVar1 = strncmp(*(char **)((int)__ptr + 8),(char *)param_2,__n);
            if (iVar1 != 0) goto LAB_30120474;
            uVar4 = 1;
            local_148 = (char *)0x0;
          }
LAB_30120460:
          FUN_3012021c(*(undefined4 *)((int)__ptr + 8),local_148,uVar4,param_4);
        }
        else {
          iVar1 = strncmp(local_148,(char *)param_2,__n);
          if (iVar1 == 0) {
            uVar4 = 3;
            goto LAB_30120460;
          }
        }
LAB_30120474:
        free(__ptr);
        __ptr = (void *)lstGet(auStack_138);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_301204a4 @ 0x301204A4  (примерный размер ~68 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_3012021c, strstr
 * Константы: 0x301204A4
 * ---------------------------------------------------------------- */
undefined4 FUN_301204a4(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = strstr(param_1,(char *)param_4[1]);
  if (pcVar1 == (char *)0x0) {
    return 1;
  }
  uVar2 = FUN_3012021c(param_1,0,0,*param_4);
  return uVar2;
}

/* ----------------------------------------------------------------
 * hookAddToTail @ 0x301204E8  (примерный размер ~160 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 3
 * Вызывает: errnoSet, taskCpuLock, taskCpuUnlock
 * Вызывают: fsmUnmountHookAdd, shellInOutInputHookAdd, shellResourceReleaseHookAdd, taskCreateHookAdd, taskSwitchHookAdd
 * Константы: 0x301204E8, 0xFFFFFFFF
 * Данные: DAT_30120778, DAT_3012077c, DAT_30120780
 * ---------------------------------------------------------------- */
undefined4 hookAddToTail(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_30120778;
  if (param_2 != 0) {
    if (*DAT_3012077c != 0) {
      taskCpuLock();
    }
    if (0 < param_3) {
      piVar1 = (int *)(param_2 + -4);
      do {
        piVar1 = piVar1 + 1;
        if (*piVar1 == 0) {
          *piVar1 = param_1;
          if (*DAT_3012077c != 0) {
            taskCpuUnlock();
          }
          return 0;
        }
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    uVar2 = DAT_30120780;
    if (*DAT_3012077c != 0) {
      taskCpuUnlock();
      uVar2 = DAT_30120780;
    }
  }
  errnoSet(uVar2);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * hookAddToHead @ 0x30120588  (примерный размер ~160 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: errnoSet, taskCpuLock, taskCpuUnlock
 * Вызывают: shellInOutInputHookAdd, taskDeleteHookAdd
 * Константы: 0xFFFFFFFF, 0x30120588
 * Данные: DAT_30120778, DAT_3012077c, DAT_30120780
 * ---------------------------------------------------------------- */
undefined4 hookAddToHead(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  piVar1 = DAT_3012077c;
  uVar3 = 0;
  if (param_2 != (undefined4 *)0x0) {
    if (*DAT_3012077c != 0) {
      taskCpuLock();
    }
    if (param_2[param_3 + -1] == 0) {
      param_3 = param_3 + -2;
      puVar2 = param_2 + param_3;
      for (; -1 < param_3; param_3 = param_3 + -1) {
        puVar2[1] = *puVar2;
        puVar2 = puVar2 + -1;
      }
      *param_2 = param_1;
    }
    else {
      errnoSet(DAT_30120780);
      uVar3 = 0xffffffff;
    }
    if (*piVar1 != 0) {
      taskCpuUnlock();
    }
    return uVar3;
  }
  errnoSet(DAT_30120778);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * hookDelete @ 0x30120628  (примерный размер ~196 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 3
 * Вызывает: errnoSet, taskCpuLock, taskCpuUnlock
 * Вызывают: fsmUnmountHookDelete, shellInOutInputHookDelete, taskCreateHookDelete, taskDeleteHookDelete, taskSwitchHookDelete
 * Константы: 0x30120628, 0xFFFFFFFF
 * Данные: DAT_30120778, DAT_3012077c, DAT_30120784
 * ---------------------------------------------------------------- */
undefined4 hookDelete(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  piVar1 = DAT_3012077c;
  uVar3 = DAT_30120778;
  if (param_2 != 0) {
    if (*DAT_3012077c != 0) {
      taskCpuLock(param_1);
    }
    iVar2 = 0;
    if (0 < param_3) {
      do {
        if (*(int *)(param_2 + iVar2 * 4) == param_1) {
          if (param_3 + -1 == iVar2) {
            *(undefined4 *)(param_2 + iVar2 * 4) = 0;
          }
          else {
            piVar4 = (int *)(param_2 + iVar2 * 4);
            do {
              iVar2 = iVar2 + 1;
              *piVar4 = piVar4[1];
              piVar4 = piVar4 + 1;
            } while (*piVar4 != 0);
          }
          if (*piVar1 != 0) {
            taskCpuUnlock(iVar2);
          }
          return 0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_3);
    }
    uVar3 = DAT_30120784;
    if (*piVar1 != 0) {
      taskCpuUnlock();
      uVar3 = DAT_30120784;
    }
  }
  errnoSet(uVar3);
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * hookFind @ 0x301206EC  (примерный размер ~156 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: errnoSet, taskCpuLock, taskCpuUnlock
 * Константы: 0x301206EC
 * Данные: DAT_30120778, DAT_3012077c
 * ---------------------------------------------------------------- */
undefined4 hookFind(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = DAT_3012077c;
  if (param_2 == 0) {
    errnoSet(DAT_30120778);
  }
  else {
    if (*DAT_3012077c != 0) {
      taskCpuLock();
    }
    if (0 < param_3) {
      piVar2 = (int *)(param_2 + -4);
      do {
        piVar2 = piVar2 + 1;
        if (*piVar2 == param_1) {
          if (*piVar1 != 0) {
            taskCpuUnlock();
          }
          return 1;
        }
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    if (*piVar1 != 0) {
      taskCpuUnlock();
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30120788 @ 0x30120788  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 0
 * Вызывают: FUN_301207c8, FUN_3012084c, FUN_301208f4, FUN_30120968, bootNetmaskExtract, bootScanNum, bootStringToStructAdd
 * Константы: 0x30120788
 * Данные: DAT_3012109c
 * ---------------------------------------------------------------- */
void FUN_30120788(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_3012109c;
  if ((*(byte *)(*DAT_3012109c + (uint)*(byte *)*param_1) & 0x28) == 0) {
    return;
  }
  do {
    iVar2 = *param_1;
    *param_1 = iVar2 + 1;
  } while ((*(byte *)(*piVar1 + (uint)*(byte *)(iVar2 + 1)) & 0x28) != 0);
  return;
}

/* ----------------------------------------------------------------
 * FUN_301207c8 @ 0x301207C8  (примерный размер ~132 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: FUN_30120788, index
 * Вызывают: FUN_30120968, bootStringToStructAdd
 * Константы: 0x301207C8
 * ---------------------------------------------------------------- */
undefined4 FUN_301207c8(undefined4 *param_1,byte *param_2,int param_3,char *param_4)

{
  char *pcVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  FUN_30120788();
  param_3 = param_3 + -1;
  pbVar2 = (byte *)*param_1;
  pbVar3 = (byte *)*param_1;
  if (0 < param_3) {
    do {
      pbVar3 = pbVar2;
      if ((*pbVar2 == 0) || (pcVar1 = index(param_4,(uint)*pbVar2), pcVar1 != (char *)0x0)) break;
      pbVar3 = pbVar2 + 1;
      param_3 = param_3 + -1;
      *param_2 = *pbVar2;
      param_2 = param_2 + 1;
      pbVar2 = pbVar3;
    } while (param_3 != 0);
  }
  *param_2 = 0;
  if ((byte *)*param_1 != pbVar3) {
    *param_1 = pbVar3;
    return 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3012084c @ 0x3012084C  (примерный размер ~168 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_30120788
 * Вызывают: FUN_30120968, bootStringToStructAdd
 * Константы: 0x3012084C
 * Данные: DAT_3012109c, DAT_301210a0
 * ---------------------------------------------------------------- */
undefined4 FUN_3012084c(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  
  FUN_30120788();
  bVar1 = *param_2;
  pbVar2 = (byte *)*param_1;
  while( true ) {
    if (bVar1 == 0) {
      *param_1 = pbVar2;
      return 1;
    }
    uVar3 = (uint)*pbVar2;
    if ((uVar3 < 0x80) && ((*(byte *)(*DAT_3012109c + uVar3) & 1) != 0)) {
      uVar3 = (uint)*(byte *)(*DAT_301210a0 + uVar3);
    }
    uVar4 = (uint)*param_2;
    if ((uVar4 < 0x80) && ((*(byte *)(*DAT_3012109c + uVar4) & 1) != 0)) {
      uVar4 = (uint)*(byte *)(*DAT_301210a0 + uVar4);
    }
    if (uVar3 != uVar4) break;
    param_2 = param_2 + 1;
    bVar1 = *param_2;
    pbVar2 = pbVar2 + 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_301208f4 @ 0x301208F4  (примерный размер ~116 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30120788, sscanf
 * Вызывают: bootStringToStructAdd
 * Константы: 0x301208F4
 * Данные: DAT_3012109c, DAT_301210a4
 * ---------------------------------------------------------------- */
undefined4 FUN_301208f4(int *param_1,undefined4 param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  
  FUN_30120788();
  iVar3 = sscanf((char *)*param_1,DAT_301210a4,param_2);
  piVar2 = DAT_3012109c;
  if (iVar3 == 1) {
    bVar1 = *(byte *)(*DAT_3012109c + (uint)*(byte *)*param_1);
    while ((bVar1 & 4) != 0) {
      iVar3 = *param_1;
      *param_1 = iVar3 + 1;
      bVar1 = *(byte *)(*piVar2 + (uint)*(byte *)(iVar3 + 1));
    }
    return 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30120968 @ 0x30120968  (примерный размер ~112 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_30120788, FUN_301207c8, FUN_3012084c
 * Вызывают: FUN_30120ad8, bootStringToStructAdd
 * Константы: 0x30120968
 * Данные: DAT_301210a8, DAT_301210ac
 * ---------------------------------------------------------------- */
undefined4 FUN_30120968(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_30120788();
  iVar1 = FUN_3012084c(param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  FUN_30120788(param_1);
  iVar1 = FUN_3012084c(param_1,DAT_301210a8);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_301207c8(param_1,param_3,param_4,DAT_301210ac);
  return uVar2;
}

/* ----------------------------------------------------------------
 * poolLibInit @ 0x30121114  (примерный размер ~32 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: semMInit
 * Вызывают: usrRoot
 * Константы: 0x30121114, 0xFFFFFFFF
 * Данные: DAT_30121a70
 * ---------------------------------------------------------------- */
undefined4 poolLibInit(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = semMInit(DAT_30121a70,0xd);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30121134 @ 0x30121134  (примерный размер ~208 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 4
 * Вызывает: lstAdd, memPartAlignedAlloc, memPartAlloc, memPartFree
 * Вызывают: poolBlockAdd, poolCreate, poolItemGet
 * Константы: 0xFFFFFFFF, 0x30121134
 * ---------------------------------------------------------------- */
undefined4 FUN_30121134(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x78);
  uVar3 = 0;
  if (param_3 == 0) {
    param_3 = memPartAlignedAlloc(*(undefined4 *)(param_1 + 0x88),param_2 * iVar2,
                                  *(undefined4 *)(param_1 + 0x7c));
    if (param_3 == 0) {
      return 0xffffffff;
    }
  }
  else {
    uVar3 = 1;
  }
  iVar1 = memPartAlloc(*(undefined4 *)(param_1 + 0x88),0x10);
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 8) = param_3 | uVar3;
    *(int *)(iVar1 + 0xc) = param_2;
    iVar4 = param_2;
    if (param_2 != 0) {
      do {
        lstAdd(param_1 + 0x9c,param_3);
        param_3 = param_3 + iVar2;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    lstAdd(param_1 + 0x90,iVar1);
    *(int *)(param_1 + 0x84) = param_2 + *(int *)(param_1 + 0x84);
    return 0;
  }
  if (uVar3 != 1) {
    memPartFree(*(undefined4 *)(param_1 + 0x88),param_3);
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * poolCreate @ 0x30121204  (примерный размер ~388 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 12
 * Вызывает: FUN_30121134, __errno, free, lstAdd, lstGet, lstInit, malloc, memPartFree, semMGive, semMInit, semMTake, semTerminate
 * Вызывают: FUN_300ad460, iosInit
 * Константы: 0x30121204, 0xFFFFFFFF
 * Данные: DAT_30121a70, DAT_30121a74, DAT_30121a78, DAT_30121a7c
 * ---------------------------------------------------------------- */
void * poolCreate(undefined4 param_1,uint param_2,uint param_3,int param_4,undefined4 param_5,
                 int param_6,undefined4 param_7)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  void *__ptr;
  
  __ptr = (void *)0x0;
  if (param_3 == 0) {
    param_3 = 4;
  }
  if ((param_2 == 0) || ((param_3 & param_3 - 1) != 0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30121a74;
  }
  else {
    __ptr = malloc(0xa8);
    if (__ptr != (void *)0x0) {
      *(uint *)((int)__ptr + 0x74) = param_2;
      *(uint *)((int)__ptr + 0x7c) = param_3;
      *(undefined4 *)((int)__ptr + 0x8c) = param_7;
      *(undefined4 *)((int)__ptr + 0x80) = param_5;
      *(undefined4 *)((int)__ptr + 8) = param_1;
      *(undefined4 *)((int)__ptr + 0x84) = 0;
      uVar4 = 8;
      if (7 < param_2) {
        uVar4 = param_2;
      }
      *(uint *)((int)__ptr + 0x78) = (uVar4 + param_3) - 1 & ~(param_3 - 1);
      if (param_6 == 0) {
        param_6 = *DAT_30121a78;
      }
      *(int *)((int)__ptr + 0x88) = param_6;
      lstInit((int)__ptr + 0x9c);
      lstInit((int)__ptr + 0x90);
      if ((param_4 == 0) || (iVar3 = FUN_30121134(__ptr,param_4,0), iVar3 != -1)) {
        if (((*(uint *)((int)__ptr + 0x8c) & 1) == 0) ||
           (iVar3 = semMInit((int)__ptr + 0xc,0xd), iVar3 != -1)) {
          uVar1 = DAT_30121a70;
          iVar3 = semMTake(DAT_30121a70,0xffffffff);
          if (iVar3 == 0) {
            lstAdd(DAT_30121a7c,__ptr);
            semMGive(uVar1);
            return __ptr;
          }
          if ((*(uint *)((int)__ptr + 0x8c) & 1) != 0) {
            semTerminate((int)__ptr + 0xc);
          }
        }
        iVar3 = lstGet((int)__ptr + 0x90);
        if (iVar3 != 0) {
          memPartFree(*(undefined4 *)((int)__ptr + 0x88),*(undefined4 *)(iVar3 + 8));
          memPartFree(*(undefined4 *)((int)__ptr + 0x88),iVar3);
        }
      }
      free(__ptr);
      return (void *)0x0;
    }
  }
  return __ptr;
}

/* ----------------------------------------------------------------
 * poolDelete @ 0x30121388  (примерный размер ~280 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 9
 * Вызывает: __errno, free, lstCount, lstDelete, lstGet, memPartFree, semMGive, semMTake, semTerminate
 * Константы: 0xFFFFFFFF, 0x30121388
 * Данные: DAT_30121a70, DAT_30121a7c, DAT_30121a80, DAT_30121a84
 * ---------------------------------------------------------------- */
undefined4 poolDelete(void *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_1 == (void *)0x0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30121a80;
  }
  else if (((*(uint *)((int)param_1 + 0x8c) & 1) == 0) ||
          (iVar3 = semMTake((int)param_1 + 0xc,0xffffffff), iVar3 != -1)) {
    if ((param_2 == 0) &&
       (iVar3 = lstCount((int)param_1 + 0x9c), iVar3 != *(int *)((int)param_1 + 0x84))) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_30121a84;
    }
    else {
      uVar1 = DAT_30121a70;
      iVar3 = semMTake(DAT_30121a70,0xffffffff);
      if (iVar3 == 0) {
        lstDelete(DAT_30121a7c,param_1);
        semMGive(uVar1);
        while (iVar3 = lstGet((int)param_1 + 0x90), iVar3 != 0) {
          if ((*(uint *)(iVar3 + 8) & 1) == 0) {
            memPartFree(*(undefined4 *)((int)param_1 + 0x88),*(uint *)(iVar3 + 8));
          }
          memPartFree(*(undefined4 *)((int)param_1 + 0x88),iVar3);
        }
        if ((*(uint *)((int)param_1 + 0x8c) & 1) != 0) {
          semTerminate((int)param_1 + 0xc);
        }
        free(param_1);
        return 0;
      }
    }
    if ((*(uint *)((int)param_1 + 0x8c) & 1) != 0) {
      semMGive((int)param_1 + 0xc);
    }
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * poolBlockAdd @ 0x301214A0  (примерный размер ~224 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_30121134, __errno, __udiv32, semMGive, semMTake
 * Вызывают: FUN_300ac39c
 * Константы: 0x301214A0, 0xFFFFFFFF
 * Данные: DAT_30121a80, DAT_30121a88, DAT_30121a8c
 * ---------------------------------------------------------------- */
int poolBlockAdd(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30121a80;
    return 0;
  }
  if (param_2 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30121a88;
    return 0;
  }
  uVar4 = (param_2 + *(int *)(param_1 + 0x7c)) - 1U & ~(*(int *)(param_1 + 0x7c) - 1U);
  iVar2 = __udiv32(param_3 - (uVar4 - param_2),*(undefined4 *)(param_1 + 0x78));
  if (iVar2 < 1) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30121a8c;
    return 0;
  }
  if (((*(uint *)(param_1 + 0x8c) & 1) != 0) &&
     (iVar3 = semMTake(param_1 + 0xc,0xffffffff), iVar3 == -1)) {
    return 0;
  }
  iVar3 = FUN_30121134(param_1,iVar2,uVar4);
  if (iVar3 == -1) {
    iVar2 = 0;
  }
  if ((*(uint *)(param_1 + 0x8c) & 1) != 0) {
    semMGive(param_1 + 0xc);
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_30121580 @ 0x30121580  (примерный размер ~100 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 1
 * Вызывает: lstFind
 * Вызывают: poolUnusedBlocksFree
 * Константы: 0x30121580, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4 FUN_30121580(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x78);
  uVar4 = *(uint *)(param_2 + 8) & 0xfffffffe;
  uVar3 = 0;
  if (*(int *)(param_2 + 0xc) != 0) {
    do {
      iVar1 = lstFind(param_1 + 0x9c,uVar4);
      if (iVar1 == -1) {
        return 0;
      }
      uVar4 = uVar4 + iVar2;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_2 + 0xc));
  }
  return 1;
}

/* ----------------------------------------------------------------
 * poolUnusedBlocksFree @ 0x301215E4  (примерный размер ~284 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_30121580, __errno, lstDelete, lstFirst, lstNext, memPartFree, semMGive, semMTake
 * Константы: 0xFFFFFFFF, 0x301215E4, 0xFFFFFFFE
 * Данные: DAT_30121a80
 * ---------------------------------------------------------------- */
undefined4 poolUnusedBlocksFree(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30121a80;
    return 0xffffffff;
  }
  if (((*(uint *)(param_1 + 0x8c) & 1) != 0) &&
     (iVar2 = semMTake(param_1 + 0xc,0xffffffff), iVar2 == -1)) {
    return 0xffffffff;
  }
  iVar2 = lstFirst(param_1 + 0x90);
  while (iVar4 = iVar2, iVar4 != 0) {
    iVar2 = lstNext(iVar4);
    iVar3 = FUN_30121580(param_1,iVar4);
    if ((iVar3 != 0) && ((*(uint *)(iVar4 + 8) & 1) == 0)) {
      uVar5 = *(uint *)(iVar4 + 8) & 0xfffffffe;
      iVar3 = *(int *)(param_1 + 0x78);
      uVar6 = 0;
      if (*(int *)(iVar4 + 0xc) != 0) {
        do {
          lstDelete(param_1 + 0x9c,uVar5);
          uVar5 = uVar5 + iVar3;
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint *)(iVar4 + 0xc));
      }
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) - *(int *)(iVar4 + 0xc);
      lstDelete(param_1 + 0x90,iVar4);
      memPartFree(*(undefined4 *)(param_1 + 0x88),*(undefined4 *)(iVar4 + 8));
      memPartFree(*(undefined4 *)(param_1 + 0x88),iVar4);
    }
  }
  if ((*(uint *)(param_1 + 0x8c) & 1) != 0) {
    semMGive(param_1 + 0xc);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * poolItemGet @ 0x30121700  (примерный размер ~216 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_30121134, __errno, intContext, lstCount, lstGet, semMGive, semMTake
 * Вызывают: FUN_300ac39c, iosFdEntryGet
 * Константы: 0x30121700, 0xFFFFFFFF
 * Данные: DAT_30121a80, DAT_30121a90, DAT_30121a94
 * ---------------------------------------------------------------- */
undefined4 poolItemGet(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30121a80;
    return 0;
  }
  if (((*(uint *)(param_1 + 0x8c) & 1) != 0) &&
     (iVar2 = semMTake(param_1 + 0xc,0xffffffff), iVar2 == -1)) {
    return 0;
  }
  iVar2 = lstCount(param_1 + 0x9c);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x80) == 0) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = DAT_30121a90;
      goto LAB_301217bc;
    }
    iVar2 = intContext();
    if (iVar2 != 0) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = DAT_30121a94;
      goto LAB_301217bc;
    }
    iVar2 = FUN_30121134(param_1,*(undefined4 *)(param_1 + 0x80),0);
    if (iVar2 == -1) goto LAB_301217bc;
  }
  uVar3 = lstGet(param_1 + 0x9c);
LAB_301217bc:
  if ((*(uint *)(param_1 + 0x8c) & 1) != 0) {
    semMGive(param_1 + 0xc);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_301217d8 @ 0x301217D8  (примерный размер ~128 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: __udiv32, lstFirst, lstNext
 * Вызывают: poolItemReturn
 * Константы: 0x301217D8, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
bool FUN_301217d8(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x78);
  iVar1 = lstFirst(param_1 + 0x90);
  while( true ) {
    if (iVar1 == 0) {
      return false;
    }
    uVar2 = *(uint *)(iVar1 + 8) & 0xfffffffe;
    if ((uVar2 <= param_2) && (param_2 < iVar3 * *(int *)(iVar1 + 0xc) + uVar2)) break;
    iVar1 = lstNext(iVar1);
  }
  iVar1 = __udiv32(param_2 - uVar2,iVar3);
  return iVar3 * iVar1 - (param_2 - uVar2) == 0;
}

/* ----------------------------------------------------------------
 * poolItemReturn @ 0x30121858  (примерный размер ~236 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 6
 * Вызывает: FUN_301217d8, __errno, lstAdd, lstFind, semMGive, semMTake
 * Вызывают: FUN_300ad708, iosFdEntryReturn
 * Константы: 0xFFFFFFFF, 0x30121858
 * Данные: DAT_30121a80, DAT_30121a98, DAT_30121a9c
 * ---------------------------------------------------------------- */
undefined4 poolItemReturn(int param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0xffffffff;
  bVar1 = true;
  if (param_1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30121a80;
    return 0xffffffff;
  }
  if (param_2 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30121a98;
    return 0xffffffff;
  }
  if (((*(uint *)(param_1 + 0x8c) & 1) != 0) &&
     (iVar3 = semMTake(param_1 + 0xc,0xffffffff), iVar3 == -1)) {
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0x8c) & 2) != 0) {
    iVar3 = lstFind(param_1 + 0x9c,param_2);
    if (iVar3 != -1) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_30121a9c;
      goto LAB_30121928;
    }
    iVar3 = FUN_301217d8(param_1,param_2);
    if (iVar3 == 0) {
      puVar2 = (undefined4 *)__errno();
      bVar1 = false;
      *puVar2 = DAT_30121a98;
    }
  }
  if (bVar1) {
    lstAdd(param_1 + 0x9c,param_2);
    uVar4 = 0;
  }
LAB_30121928:
  if ((*(uint *)(param_1 + 0x8c) & 1) != 0) {
    semMGive(param_1 + 0xc);
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * poolIncrementSet @ 0x30121944  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: __errno
 * Константы: 0x30121944, 0xFFFFFFFF
 * Данные: DAT_30121a80
 * ---------------------------------------------------------------- */
undefined4 poolIncrementSet(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30121a80;
    uVar2 = 0xffffffff;
  }
  else {
    *(undefined4 *)(param_1 + 0x80) = param_2;
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * poolIncrementGet @ 0x30121970  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: __errno
 * Константы: 0x30121970
 * Данные: DAT_30121a80
 * ---------------------------------------------------------------- */
undefined4 poolIncrementGet(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30121a80;
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x80);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * poolTotalCount @ 0x3012199C  (примерный размер ~44 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: __errno
 * Константы: 0x3012199C
 * Данные: DAT_30121a80
 * ---------------------------------------------------------------- */
undefined4 poolTotalCount(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30121a80;
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x84);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * poolFreeCount @ 0x301219C8  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: __errno, lstCount
 * Константы: 0x301219C8
 * Данные: DAT_30121a80
 * ---------------------------------------------------------------- */
undefined4 poolFreeCount(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30121a80;
    uVar2 = 0;
  }
  else {
    uVar2 = lstCount(param_1 + 0x9c);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * poolIdListGet @ 0x301219F8  (примерный размер ~168 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: lstFirst, lstNext, semMGive, semMTake
 * Константы: 0x301219F8, 0xFFFFFFFF
 * Данные: DAT_30121a70, DAT_30121a7c
 * ---------------------------------------------------------------- */
int poolIdListGet(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  uVar1 = DAT_30121a70;
  iVar4 = 0;
  iVar2 = semMTake(DAT_30121a70,0xffffffff);
  if (iVar2 != 0) {
    return -1;
  }
  iVar2 = lstFirst(DAT_30121a7c);
  if (0 < param_2) {
    piVar3 = (int *)(param_1 + -4);
    iVar4 = param_2;
    do {
      if (iVar2 == 0) break;
      piVar3 = piVar3 + 1;
      *piVar3 = iVar2;
      iVar2 = lstNext();
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar4 = param_2 - iVar4;
  }
  semMGive(uVar1);
  return iVar4;
}

/* ----------------------------------------------------------------
 * kernelVersion @ 0x30122764  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 0
 * Вызывают: printLogo, version
 * Константы: 0x30122764
 * Данные: DAT_30122928
 * ---------------------------------------------------------------- */
undefined4 kernelVersion(void)

{
  return DAT_30122928;
}

/* ----------------------------------------------------------------
 * kernelTimeSlice @ 0x30122770  (примерный размер ~108 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: tickAnnounceHookAdd
 * Константы: 0x30122770, 0xFFFFFFFF
 * Данные: DAT_301228f4, DAT_3012292c, DAT_30122930, DAT_30122934
 * ---------------------------------------------------------------- */
undefined4 kernelTimeSlice(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    *DAT_301228f4 = 0;
  }
  else {
    if (*DAT_3012292c == 0) {
      iVar1 = tickAnnounceHookAdd(DAT_30122930);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      *DAT_3012292c = 1;
    }
    *DAT_30122934 = param_1;
    *DAT_301228f4 = 1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_301227dc @ 0x301227DC  (примерный размер ~156 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x301227DC
 * Данные: DAT_301228d4, DAT_301228f4, DAT_30122934
 * ---------------------------------------------------------------- */
void FUN_301227dc(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((((*DAT_301228f4 != 0) && (*(int *)(param_1 + 0x7c) == 0)) && (*(int *)(param_1 + 0x70) == 0))
     && (uVar2 = *(int *)(param_1 + 0xa0) + 1, *(uint *)(param_1 + 0xa0) = uVar2,
        *DAT_30122934 <= uVar2)) {
    *(undefined4 *)(param_1 + 0xa0) = 0;
    iVar1 = DAT_301228d4;
    (**(code **)(*(int *)(DAT_301228d4 + 0xc) + 0x18))(DAT_301228d4,param_1 + 0x50);
    (**(code **)(*(int *)(iVar1 + 0xc) + 0x10))
              (iVar1,param_1 + 0x50,*(undefined4 *)(param_1 + 0x74));
  }
  return;
}

/* ----------------------------------------------------------------
 * kernelRoundRobinInstall @ 0x30122878  (примерный размер ~56 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30122878, 0xFFFFFFFF
 * Данные: DAT_3012292c, DAT_30122930, DAT_30122938
 * ---------------------------------------------------------------- */
undefined4 kernelRoundRobinInstall(void)

{
  if (*DAT_30122938 == 0) {
    *DAT_30122938 = DAT_30122930;
    *DAT_3012292c = 1;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * kernelCpuEnable @ 0x301228B0  (примерный размер ~8 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x301228B0, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 kernelCpuEnable(void)

{
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * kernelIsCpuIdle @ 0x301228B8  (примерный размер ~12 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x301228B8
 * Данные: DAT_3012293c
 * ---------------------------------------------------------------- */
undefined4 kernelIsCpuIdle(void)

{
  return *DAT_3012293c;
}

/* ----------------------------------------------------------------
 * kernelIsSystemIdle @ 0x301228C4  (примерный размер ~124 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 0
 * Константы: 0x301228C4
 * Данные: DAT_3012293c
 * ---------------------------------------------------------------- */
undefined4 kernelIsSystemIdle(void)

{
  return *DAT_3012293c;
}

/* ----------------------------------------------------------------
 * msgQCreateLibInit @ 0x30122940  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrKernelCoreInit
 * Константы: 0x30122940
 * Данные: DAT_30122c38, DAT_30122c3c
 * ---------------------------------------------------------------- */
void msgQCreateLibInit(void)

{
  *(undefined4 *)(*DAT_30122c38 + 0x14) = DAT_30122c3c;
  return;
}

/* ----------------------------------------------------------------
 * msgQCreate @ 0x30122954  (примерный размер ~240 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 5
 * Вызывает: __errno, intContext, msgQInit, objAllocExtra, objFree
 * Вызывают: logInit, os_msg_q_create, pipeDevCreate
 * Константы: 0x30122954, 0xFFFFFFFC
 * Данные: DAT_30122c38, DAT_30122c40, DAT_30122c44, DAT_30122c48
 * ---------------------------------------------------------------- */
int msgQCreate(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_18;
  
  iVar1 = intContext();
  if (iVar1 == 0) {
    if (param_1 < 0) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_30122c44;
      iVar1 = 0;
    }
    else if (param_2 < 0) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = DAT_30122c48;
      iVar1 = 0;
    }
    else {
      iVar1 = objAllocExtra(*DAT_30122c38,(param_2 + 0xfU & 0xfffffffc) * param_1,&local_18);
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar3 = msgQInit(iVar1,param_1,param_2,param_3,local_18);
        if (iVar3 == 0) {
          *(ushort *)(iVar1 + 8) = *(ushort *)(iVar1 + 8) | 2;
        }
        else {
          objFree(*DAT_30122c38,iVar1);
          iVar1 = 0;
        }
      }
    }
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30122c40;
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30122a44 @ 0x30122A44  (примерный размер ~136 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 7
 * Вызывает: objCoreInvalidate, objCoreTerminate, objFree, taskCpuUnlock, taskUnsafe, windExit, windPendQTerminate
 * Вызывают: msgQDelete, msgQDestroy, msgQTerminate
 * Константы: 0x30122A44
 * Данные: DAT_30122c38, DAT_30122c4c, DAT_30122c50
 * ---------------------------------------------------------------- */
undefined4 FUN_30122a44(int param_1,int param_2)

{
  objCoreInvalidate();
  taskCpuUnlock();
  *DAT_30122c4c = 1;
  windPendQTerminate(param_1 + 0x4c);
  windPendQTerminate(param_1 + 0x68);
  if ((code *)*DAT_30122c50 != (code *)0x0) {
    (*(code *)*DAT_30122c50)(param_1 + 0x8c);
  }
  windExit();
  objCoreTerminate(param_1);
  if (param_2 != 0) {
    objFree(*DAT_30122c38,param_1);
  }
  taskUnsafe();
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30122acc @ 0x30122ACC  (примерный размер ~216 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 5
 * Вызывает: __errno, intContext, objVerify, taskCpuUnlock, taskUnsafe
 * Вызывают: msgQDelete, msgQDestroy, msgQTerminate
 * Константы: 0xFFFFFFFF, 0x30122ACC
 * Данные: DAT_30122c38, DAT_30122c40, DAT_30122c54, DAT_30122c58, DAT_30122c5c
 * ---------------------------------------------------------------- */
undefined4 FUN_30122acc(uint param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((param_1 & 1) != 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30122c54;
    return 0xffffffff;
  }
  iVar2 = intContext();
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30122c40;
    return 0xffffffff;
  }
  *(int *)(*DAT_30122c58 + 0xac) = *(int *)(*DAT_30122c58 + 0xac) + 1;
  *(int *)(*DAT_30122c58 + 0x7c) = *(int *)(*DAT_30122c58 + 0x7c) + 1;
  iVar2 = objVerify(param_1,*DAT_30122c38);
  if (iVar2 != 0) {
    taskCpuUnlock();
    taskUnsafe();
    return 0xffffffff;
  }
  if ((param_2 != 1) && ((*(ushort *)(param_1 + 8) & 0x80) != 0)) {
    taskCpuUnlock();
    taskUnsafe();
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30122c5c;
    return 0xffffffff;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * msgQTerminate @ 0x30122BA4  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30122a44, FUN_30122acc
 * Константы: 0x30122BA4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 msgQTerminate(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_30122acc(param_1,0);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  uVar2 = FUN_30122a44(param_1,0);
  return uVar2;
}

/* ----------------------------------------------------------------
 * msgQDelete @ 0x30122BD4  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 2
 * Вызывает: FUN_30122a44, FUN_30122acc
 * Вызывают: os_msg_q_delete, pipeDevCreate, pipeDevDelete
 * Константы: 0x30122BD4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 msgQDelete(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_30122acc(param_1,0);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  uVar2 = FUN_30122a44(param_1,1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * msgQDestroy @ 0x30122C04  (примерный размер ~92 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30122a44, FUN_30122acc
 * Константы: 0x30122C04, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 msgQDestroy(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_30122acc(param_1,1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  uVar2 = FUN_30122a44(param_1,param_2);
  return uVar2;
}

/* ----------------------------------------------------------------
 * msgQLibInit @ 0x30122C60  (примерный размер ~140 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: classInit, taskDeleteHookAdd
 * Вызывают: usrKernelCoreInit
 * Константы: 0x30122C60, 0xFFFFFFFF
 * Данные: DAT_30123aec, DAT_30123af0, DAT_30123af4
 * ---------------------------------------------------------------- */
undefined4 msgQLibInit(void)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  bVar3 = *DAT_30123aec == 0;
  if (bVar3) {
    iVar1 = classInit(*DAT_30123af0,0xb0,0,0,0,0,0,0,3,0);
    if ((iVar1 == 0) && (iVar1 = taskDeleteHookAdd(DAT_30123af4), iVar1 == 0)) {
      *DAT_30123aec = 1;
    }
    bVar3 = *DAT_30123aec == 0;
  }
  if (bVar3) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30122cec @ 0x30122CEC  (примерный размер ~84 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_30122f24, FUN_30123680, msgQInit, msgQReceive, msgQSend
 * Константы: 0x30122CEC
 * ---------------------------------------------------------------- */
void FUN_30122cec(int *param_1,int *param_2,int param_3)

{
  if (*param_1 == 0) {
    *param_2 = 0;
    *param_1 = (int)param_2;
    param_1[1] = (int)param_2;
  }
  else if (param_3 == 0) {
    *param_2 = 0;
    *(int **)param_1[1] = param_2;
    param_1[1] = (int)param_2;
  }
  else {
    *param_2 = *param_1;
    *param_1 = (int)param_2;
  }
  param_1[2] = param_1[2] + 1;
  return;
}

/* ----------------------------------------------------------------
 * msgQInit @ 0x30122D40  (примерный размер ~420 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_30122cec, __errno, bzero, errnoSet, objCoreInit, qInit, sllInit
 * Вызывают: msgQCreate, msgQInitialize
 * Константы: 0xFFFFFFFF, 0x30122D40, 0xFFFFFFF8, 0xFFFFFFFC
 * Данные: DAT_30123af0, DAT_30123af8, DAT_30123afc, DAT_30123b00, DAT_30123b04, DAT_30123b08, DAT_30123b0c
 * ---------------------------------------------------------------- */
undefined4 msgQInit(void *param_1,int param_2,int param_3,uint param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 < 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30123b04;
    uVar3 = 0xffffffff;
  }
  else if (param_3 < 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30123b08;
    uVar3 = 0xffffffff;
  }
  else if ((param_4 & 0xfffffff8) == 0) {
    bzero(param_1,0xb0);
    if ((param_4 & 1) == 0) {
      uVar3 = *DAT_30123af8;
    }
    else {
      if ((param_4 & 1) != 1) {
        errnoSet(DAT_30123b00);
        return 0xffffffff;
      }
      uVar3 = *DAT_30123afc;
    }
    iVar4 = (int)param_1 + 0x40;
    iVar5 = 2;
    do {
      iVar1 = sllInit(iVar4);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      *(undefined4 *)(iVar4 + 8) = 0;
      iVar4 = qInit(iVar4 + 0xc,uVar3,(int)param_4 >> 2 & 1,0,0,0,0,0,0,0,0,0);
      if (iVar4 != 0) {
        return 0xffffffff;
      }
      iVar4 = (int)param_1 + 0x5c;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar4 = param_2;
    if (0 < param_2) {
      do {
        FUN_30122cec((int)param_1 + 0x5c,param_5,1);
        *(void **)(param_5 + 8) = param_1;
        param_5 = param_5 + (param_3 + 0xfU & 0xfffffffc);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    *(uint *)((int)param_1 + 0x78) = param_4;
    *(int *)((int)param_1 + 0x7c) = param_2;
    *(int *)((int)param_1 + 0x80) = param_3;
    *(undefined4 *)((int)param_1 + 0x90) = 0;
    *(undefined4 *)((int)param_1 + 0x8c) = 0;
    *(undefined1 *)((int)param_1 + 0x94) = 0;
    objCoreInit(param_1,*DAT_30123af0);
    uVar3 = 0;
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30123b0c;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * msgQInitialize @ 0x30122EE4  (примерный размер ~64 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: msgQInit
 * Константы: 0x30122EE4
 * ---------------------------------------------------------------- */
int msgQInitialize(int param_1)

{
  int iVar1;
  
  if ((param_1 == 0) || (iVar1 = msgQInit(param_1), iVar1 != 0)) {
    param_1 = 0;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * FUN_30122f24 @ 0x30122F24  (примерный размер ~176 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 3
 * Вызывает: FUN_30122cec, windExit, windPendQGet
 * Вызывают: FUN_30123a80, msgQReceive, msgQSend
 * Константы: 0x80000000, 0x30122F24, 0x7FFFFFFF
 * Данные: DAT_30123b10
 * ---------------------------------------------------------------- */
void FUN_30122f24(int param_1,undefined4 param_2,int param_3)

{
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  if (*(int *)(param_1 + 0x68) == 0) {
    if (param_3 == 0) {
      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) & 0x7fffffff;
    }
    FUN_30122cec(param_1 + 0x5c,param_2,1);
  }
  else {
    if (param_3 != 0) {
      if ((*(uint *)(param_1 + 0x78) & 0x80000000) != 0) {
        FUN_30122cec(param_1 + 0x5c,param_2,1);
        return;
      }
      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 0x80000000;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x68) + 0xf8) = param_2;
    *DAT_30123b10 = 1;
    windPendQGet(param_1 + 0x68,
                 (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b |
                 0x80);
    windExit();
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30122fd4 @ 0x30122FD4  (примерный размер ~336 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 4
 * Вызывает: errnoSet, objVerify, windExit, windPendQPut
 * Вызывают: msgQReceive, msgQSend
 * Константы: 0xFFFFFF00, 0x30122FD4, 0x80000000
 * Данные: DAT_30123af0, DAT_30123b10, DAT_30123b14, DAT_30123b18
 * ---------------------------------------------------------------- */
int FUN_30122fd4(int param_1,int *param_2,int *param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  int unaff_r8;
  int *piVar3;
  bool bVar4;
  byte in_Q;
  byte bVar5;
  uint in_cpsr;
  uint uVar6;
  
  piVar3 = (int *)(param_1 + 0x40);
  bVar4 = piVar3 == param_3;
  if (!bVar4) {
    unaff_r8 = 0;
  }
  uVar2 = *(uint *)(param_1 + 0x78) & 1;
  if (bVar4) {
    unaff_r8 = 1;
  }
  bVar5 = ((int)piVar3 - (int)param_3 < 0) << 4 | bVar4 << 3 | (param_3 <= piVar3) << 2 |
          SBORROW4((int)piVar3,(int)param_3) << 1 | in_Q;
  uVar6 = in_cpsr & 0xffffff00;
  while( true ) {
    piVar3 = (int *)*param_3;
    if ((piVar3 != (int *)0x0) &&
       (((uVar2 != 0 || (unaff_r8 != 0)) || ((*(uint *)(param_1 + 0x78) & 0x80000000) == 0)))) {
      *param_3 = *piVar3;
      param_3[2] = param_3[2] + -1;
      *param_2 = (int)piVar3;
      return 0;
    }
    if (param_4 == 0) {
      errnoSet(DAT_30123b14,(uint)bVar5 << 0x1b | 0x80);
      return -1;
    }
    *DAT_30123b10 = 1;
    bVar5 = (uVar6 >> 0x1b & 1) != 0;
    iVar1 = windPendQPut(param_3 + 3,param_4);
    if (iVar1 == -1) break;
    iVar1 = windExit();
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = objVerify(param_1,*DAT_30123af0);
    if (iVar1 != 0) {
      errnoSet(DAT_30123b18);
      *(undefined4 *)(param_6 + 0x148) = 0;
      return -1;
    }
    if (uVar2 == 0) {
      *param_2 = *(int *)(param_6 + 0x148);
      return 0;
    }
    bVar5 = (uVar2 == 0) << 3 | 4U | bVar5;
    uVar6 = uVar6 & 0xffffff00;
  }
  windExit();
  return -1;
}

/* ----------------------------------------------------------------
 * FUN_30123124 @ 0x30123124  (примерный размер ~88 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: msgQSend
 * Константы: 0x30123124, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_30123124(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x5c);
  if (piVar1 != (int *)0x0) {
    *(int *)(param_1 + 0x5c) = *piVar1;
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + -1;
    *param_2 = (int)piVar1;
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_3012317c @ 0x3012317C  (примерный размер ~120 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 2
 * Вызывает: errnoGet, errnoSet
 * Вызывают: FUN_30123680, msgQSend
 * Константы: 0x3012317C, 0xFFFFFFFF
 * Данные: DAT_30123b1c, DAT_30123b20
 * ---------------------------------------------------------------- */
undefined4 FUN_3012317c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar1 = errnoGet();
  iVar2 = (*(code *)*DAT_30123b1c)(*(undefined4 *)(param_1 + 0x90),*(undefined4 *)(param_1 + 0x8c));
  if (iVar2 == 0) {
    if ((*(byte *)(param_1 + 0x94) & 1) == 0) goto LAB_301231e0;
  }
  else if ((*(uint *)(param_1 + 0x78) & 2) != 0) {
    uVar3 = 0xffffffff;
    uVar1 = DAT_30123b20;
  }
  *(undefined4 *)(param_1 + 0x90) = 0;
LAB_301231e0:
  errnoSet(uVar1);
  return uVar3;
}

/* ----------------------------------------------------------------
 * msgQSend @ 0x301231F4  (примерный размер ~1164 байт)
 * Модуль: kernel | Вызывают: 3 | Вызывает: 14
 * Вызывает: FUN_30122cec, FUN_30122f24, FUN_30122fd4, FUN_30123124, FUN_3012317c, __errno, bcopy, errnoGet, errnoSet, objVerify, taskCpuUnlock, windExit, windPendQGet, workQAdd2
 * Вызывают: FUN_300ecf38, logMsg, os_msg_q_send
 * Константы: 0xFFFFFFFF, 0x301231F4, 0x7FFFFFFF
 * Данные: DAT_30123af0, DAT_30123b08, DAT_30123b10, DAT_30123b18, DAT_30123b24, DAT_30123b28, DAT_30123b2c, DAT_30123b30
 * ---------------------------------------------------------------- */
undefined4 msgQSend(uint param_1,void *param_2,uint param_3,int param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *unaff_r10;
  undefined4 *puVar6;
  int iVar7;
  byte in_Q;
  undefined4 *local_40;
  int local_3c;
  int local_34;
  uint local_30;
  int local_2c;
  
  iVar5 = 0;
  if ((param_1 & 1) == 0) {
    if (*DAT_30123b30 < 1) {
      *(int *)(*DAT_30123b38 + 0x7c) = *(int *)(*DAT_30123b38 + 0x7c) + 1;
    }
    else {
      iVar5 = 1;
      if (param_4 != 0) {
        errnoSet(DAT_30123b34);
        return 0xffffffff;
      }
    }
    puVar1 = DAT_30123af0;
    local_34 = *DAT_30123b38;
    while (iVar3 = objVerify(param_1,*puVar1), iVar3 == 0) {
      if (*(uint *)(param_1 + 0x80) < param_3) {
        if (iVar5 == 0) {
          taskCpuUnlock();
        }
        errnoSet(DAT_30123b08);
        return 0xffffffff;
      }
      local_40 = unaff_r10;
      local_3c = FUN_30122fd4(param_1,&local_40,param_1 + 0x5c,param_4,iVar5,local_34);
      puVar6 = local_40;
      if (local_3c != 1) {
        if (local_3c == -1) {
          iVar3 = errnoGet();
          if (iVar3 == DAT_30123b40) {
            iVar3 = objVerify(param_1,*puVar1);
            if (iVar3 == 0) {
              *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
            }
            else {
              errnoSet(DAT_30123b18);
            }
          }
          if (iVar5 == 0) {
            if (param_4 != 0) {
              *(undefined4 *)(local_34 + 0x148) = 0;
            }
            taskCpuUnlock();
          }
          return 0xffffffff;
        }
        iVar3 = *DAT_30123b10;
        if (iVar3 == 1) {
          bcopy(param_2,local_40 + 3,param_3);
          local_40[1] = param_3;
          workQAdd2(DAT_30123b44,local_40,param_5);
          return 0;
        }
        uVar4 = *(uint *)(param_1 + 0x78) & 1;
        local_34 = 0;
        local_2c = 1;
        local_30 = (uint)(byte)((iVar3 + -1 < 0) << 4 | (iVar3 == 1) << 3 | (iVar3 != 0) << 2 |
                                SBORROW4(iVar3,1) << 1 | in_Q) << 0x1b;
        iVar3 = *(int *)(param_1 + 0x4c);
        if (iVar3 == 0) {
          bcopy(param_2,local_40 + 3,param_3);
          puVar6[1] = param_3;
          FUN_30122cec(param_1 + 0x40,puVar6,param_5);
          if (*(int *)(param_1 + 0x90) != 0) {
            *DAT_30123b10 = 1;
            local_34 = FUN_3012317c(param_1);
            windExit();
          }
        }
        else {
          *DAT_30123b10 = 1;
          windPendQGet(param_1 + 0x4c,local_30 | 0x80);
          windExit();
          if (uVar4 == 0) {
            if (iVar5 == 0) {
              iVar7 = *(int *)(*DAT_30123b38 + 0x90);
            }
            else {
              iVar7 = *DAT_30123b48;
            }
            if (iVar7 == *(int *)(iVar3 + 0x40)) {
              if (*(uint *)(iVar3 + 0xfc) < param_3) {
                param_3 = *(uint *)(iVar3 + 0xfc);
              }
              if ((param_3 != 0) && (*(void **)(iVar3 + 0xf4) != (void *)0x0)) {
                bcopy(param_2,*(void **)(iVar3 + 0xf4),param_3);
              }
              *(undefined4 *)(iVar3 + 0xf8) = 0;
              *(uint *)(iVar3 + 0xfc) = param_3;
              *puVar6 = 0;
              local_3c = 0;
              local_2c = 0;
            }
            else {
              *(undefined4 **)(iVar3 + 0xf8) = puVar6;
              if (*(uint *)(iVar3 + 0xfc) < param_3) {
                puVar6[1] = *(uint *)(iVar3 + 0xfc);
              }
              else {
                puVar6[1] = param_3;
              }
              *puVar6 = 0xffffffff;
              bcopy(param_2,puVar6 + 3,puVar6[1]);
            }
          }
          else {
            puVar6[1] = param_3;
            bcopy(param_2,puVar6 + 3,param_3);
            FUN_30122cec(param_1 + 0x40,puVar6,param_5);
          }
        }
        if (uVar4 == 0) {
          if (local_2c != 0) {
            local_3c = FUN_30123124(param_1,&local_40);
            puVar6 = local_40;
          }
          if (local_3c == 0) {
            FUN_30122f24(param_1,puVar6,0);
          }
          else {
            *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) & 0x7fffffff;
          }
        }
        if (iVar5 != 0) {
          return local_34;
        }
        if (param_4 != 0) {
          *(undefined4 *)(*DAT_30123b38 + 0x148) = 0;
        }
        taskCpuUnlock();
        return local_34;
      }
      param_4 = (*(code *)*DAT_30123b3c)(param_4);
      unaff_r10 = local_40;
    }
    if (iVar5 == 0) {
      taskCpuUnlock();
    }
    uVar2 = 0xffffffff;
  }
  else if ((code *)*DAT_30123b24 == (code *)0x0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30123b28;
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (*(code *)*DAT_30123b24)(param_1 + *DAT_30123b2c,param_2,param_3,param_4,param_5);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30123680 @ 0x30123680  (примерный размер ~204 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_30122cec, FUN_3012317c, windPendQGet
 * Константы: 0x30123680, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_30123680(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1[2];
  iVar1 = *(int *)(iVar3 + 0x4c);
  uVar2 = 0;
  if (iVar1 == 0) {
    FUN_30122cec(iVar3 + 0x40,param_1,param_2);
    if (*(int *)(iVar3 + 0x90) != 0) {
      uVar2 = FUN_3012317c(iVar3);
    }
  }
  else if ((*(uint *)(iVar3 + 0x78) & 1) == 0) {
    *(undefined4 **)(iVar1 + 0xf8) = param_1;
    if (*(uint *)(iVar1 + 0xfc) <= (uint)param_1[1]) {
      param_1[1] = *(uint *)(iVar1 + 0xfc);
    }
    *param_1 = 0xffffffff;
    windPendQGet(iVar3 + 0x4c);
  }
  else {
    FUN_30122cec(iVar3 + 0x40,param_1,param_2);
    windPendQGet(iVar3 + 0x4c);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * msgQReceive @ 0x3012374C  (примерный размер ~664 байт)
 * Модуль: kernel | Вызывают: 4 | Вызывает: 11
 * Вызывает: FUN_30122cec, FUN_30122f24, FUN_30122fd4, __errno, bcopy, errnoGet, errnoSet, objVerify, taskCpuUnlock, windExit, windPendQGet
 * Вызывают: FUN_300ecefc, FUN_300ed06c, logTask, os_msg_q_recv
 * Константы: 0xFFFFFFFF, 0x3012374C
 * Данные: DAT_30123af0, DAT_30123b08, DAT_30123b10, DAT_30123b18, DAT_30123b28, DAT_30123b2c, DAT_30123b30, DAT_30123b38
 * ---------------------------------------------------------------- */
size_t msgQReceive(uint param_1,void *param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  int unaff_r8;
  int iVar5;
  size_t local_2c;
  int local_28;
  
  if (*DAT_30123b30 < 1) {
    iVar5 = *DAT_30123b38;
    if ((param_1 & 1) == 0) {
      if ((int)param_3 < 0) {
        errnoSet(DAT_30123b08);
        sVar2 = 0xffffffff;
      }
      else {
        *(int *)(*DAT_30123b38 + 0x7c) = *(int *)(*DAT_30123b38 + 0x7c) + 1;
        puVar1 = DAT_30123af0;
        while (iVar3 = objVerify(param_1,*puVar1), iVar3 == 0) {
          uVar4 = *(uint *)(param_1 + 0x78) & 1;
          if (uVar4 == 0) {
            *(void **)(iVar5 + 0x144) = param_2;
            *(uint *)(iVar5 + 0x14c) = param_3;
          }
          local_28 = unaff_r8;
          iVar3 = FUN_30122fd4(param_1,&local_28,param_1 + 0x40,param_4,0,iVar5);
          if (iVar3 != 1) {
            if (iVar3 == -1) {
              iVar3 = errnoGet();
              if (iVar3 == DAT_30123b40) {
                iVar3 = objVerify(param_1,*puVar1);
                if (iVar3 == 0) {
                  *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
                }
                else {
                  errnoSet(DAT_30123b18);
                }
              }
              if (param_4 != 0) {
                *(undefined4 *)(iVar5 + 0x148) = 0;
              }
              taskCpuUnlock();
              return 0xffffffff;
            }
            if (local_28 == 0) {
              taskCpuUnlock();
              return *(size_t *)(*DAT_30123b38 + 0x14c);
            }
            local_2c = param_3;
            if (*(uint *)(local_28 + 4) < param_3) {
              local_2c = *(uint *)(local_28 + 4);
            }
            if ((local_2c != 0) && (param_2 != (void *)0x0)) {
              bcopy((void *)(local_28 + 0xc),param_2,local_2c);
            }
            if (uVar4 == 0) {
              FUN_30122f24(param_1,local_28,1);
            }
            else {
              FUN_30122cec(param_1 + 0x5c,local_28,1);
              if (*(int *)(param_1 + 0x68) != 0) {
                *DAT_30123b10 = 1;
                windPendQGet(param_1 + 0x68);
                windExit();
              }
            }
            *(undefined4 *)(iVar5 + 0x148) = 0;
            taskCpuUnlock();
            return local_2c;
          }
          param_4 = (*(code *)*DAT_30123b3c)(param_4);
          unaff_r8 = local_28;
        }
        taskCpuUnlock();
        sVar2 = 0xffffffff;
      }
    }
    else if ((code *)*DAT_30123b50 == (code *)0x0) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = DAT_30123b28;
      sVar2 = 0xffffffff;
    }
    else {
      sVar2 = (*(code *)*DAT_30123b50)(param_1 + *DAT_30123b2c,param_2,param_3,param_4);
    }
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30123b4c;
    sVar2 = 0xffffffff;
  }
  return sVar2;
}

/* ----------------------------------------------------------------
 * msgQNumMsgs @ 0x301239E4  (примерный размер ~156 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 2
 * Вызывает: __errno, objVerify
 * Вызывают: FUN_300ed06c
 * Константы: 0xFFFFFFFF, 0x301239E4
 * Данные: DAT_30123af0, DAT_30123b28, DAT_30123b2c, DAT_30123b54
 * ---------------------------------------------------------------- */
undefined4 msgQNumMsgs(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 & 1) == 0) {
    iVar3 = objVerify(param_1,*DAT_30123af0);
    if (iVar3 == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x48);
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else if ((code *)*DAT_30123b54 == (code *)0x0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30123b28;
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (*(code *)*DAT_30123b54)(param_1 + *DAT_30123b2c);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30123a80 @ 0x30123A80  (примерный размер ~216 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_30122f24, objVerify, taskCpuUnlock
 * Константы: 0x30123A80
 * Данные: DAT_30123af0, DAT_30123b38
 * ---------------------------------------------------------------- */
void FUN_30123a80(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x148);
  if (iVar3 != 0) {
    uVar2 = *(undefined4 *)(iVar3 + 8);
    *(int *)(*DAT_30123b38 + 0x7c) = *(int *)(*DAT_30123b38 + 0x7c) + 1;
    iVar1 = objVerify(uVar2,*DAT_30123af0);
    if (iVar1 == 0) {
      FUN_30122f24(uVar2,iVar3);
    }
    taskCpuUnlock();
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * msgQEvStart @ 0x30123B58  (примерный размер ~196 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 6
 * Вызывает: __errno, errnoSet, eventStart, intContext, objVerify, taskCpuUnlock
 * Константы: 0xFFFFFFFF, 0x30123B58
 * Данные: DAT_30123cb8, DAT_30123cbc, DAT_30123cc0, DAT_30123cc4, DAT_30123cc8
 * ---------------------------------------------------------------- */
undefined4 msgQEvStart(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 == 0) {
    errnoSet(DAT_30123cb8);
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = intContext();
    if (iVar2 == 0) {
      *(int *)(*DAT_30123cc0 + 0x7c) = *(int *)(*DAT_30123cc0 + 0x7c) + 1;
      iVar2 = objVerify(param_1,*DAT_30123cc4);
      if (iVar2 == 0) {
        uVar1 = eventStart(param_1,param_1 + 0x8c,DAT_30123cc8,param_2,param_3,0);
      }
      else {
        taskCpuUnlock();
        uVar1 = 0xffffffff;
      }
    }
    else {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = DAT_30123cbc;
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * msgQEvStop @ 0x30123C1C  (примерный размер ~260 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 4
 * Вызывает: __errno, errnoSet, intContext, objVerify
 * Константы: 0xFFFFFFFF, 0x30123C1C
 * Данные: DAT_30123cbc, DAT_30123cc0, DAT_30123cc4, DAT_30123ccc
 * ---------------------------------------------------------------- */
undefined4 msgQEvStop(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = intContext();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30123cbc;
    return 0xffffffff;
  }
  iVar3 = *DAT_30123cc0;
  iVar1 = objVerify(param_1,*DAT_30123cc4);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x90) != iVar3) {
    errnoSet(DAT_30123ccc);
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x90) = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * msgQInfoGet @ 0x30123D20  (примерный размер ~444 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 3
 * Вызывает: __errno, objVerify, sllEach
 * Вызывают: FUN_300ed06c
 * Константы: 0xFFFFFFFF, 0x30123D20
 * Данные: DAT_30123ec8, DAT_30123ecc, DAT_30123ed0, DAT_30123ed4, DAT_30123ed8
 * ---------------------------------------------------------------- */
undefined4 msgQInfoGet(uint param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((param_1 & 1) == 0) {
    iVar4 = objVerify(param_1,*DAT_30123ed4);
    if (iVar4 == 0) {
      if (*(int *)(param_1 + 0x48) == 0) {
        iVar4 = param_1 + 0x4c;
      }
      else {
        iVar4 = param_1 + 0x68;
      }
      if (param_2[8] != 0) {
        iVar5 = (**(code **)(*(int *)(iVar4 + 0xc) + 0x30))(iVar4,param_2[8],param_2[7]);
        iVar6 = 0;
        if (0 < iVar5) {
          iVar7 = param_2[8];
          do {
            iVar1 = iVar6 * 4;
            iVar6 = iVar6 + 1;
            *(int *)(iVar7 + iVar1) = *(int *)(iVar7 + iVar1) + -0x50;
          } while (iVar6 < iVar5);
        }
      }
      if (((param_2[10] != 0) || (param_2[0xb] != 0)) && (*param_2 = 0, 0 < (int)param_2[9])) {
        sllEach(param_1 + 0x40,DAT_30123ed8,param_2);
      }
      *param_2 = *(undefined4 *)(param_1 + 0x48);
      uVar3 = (**(code **)(*(int *)(iVar4 + 0xc) + 0x30))(iVar4,0,0);
      param_2[1] = uVar3;
      param_2[4] = *(undefined4 *)(param_1 + 0x78);
      param_2[5] = *(undefined4 *)(param_1 + 0x7c);
      param_2[6] = *(undefined4 *)(param_1 + 0x80);
      param_2[2] = *(undefined4 *)(param_1 + 0x84);
      param_2[3] = *(undefined4 *)(param_1 + 0x88);
      uVar3 = 0;
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  else if ((code *)*DAT_30123ec8 == (code *)0x0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = DAT_30123ecc;
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = (*(code *)*DAT_30123ec8)(param_1 + *DAT_30123ed0,param_2);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * semBInit @ 0x30123EDC  (примерный размер ~180 байт)
 * Модуль: kernel | Вызывают: 7 | Вызывает: 3
 * Вызывает: __errno, objCoreInit, semQInit
 * Вызывают: FUN_300edd18, excInit, jobLibInit, ptyDevCreate, semBCreate, semBInitialize, tyDevInit
 * Константы: 0xFFFFFFFF, 0x30123EDC, 0xFFFFFF8E
 * Данные: DAT_30124664, DAT_30124668, DAT_3012466c, DAT_30124670
 * ---------------------------------------------------------------- */
undefined4 semBInit(int param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((param_2 & 0xffffff8e) != 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30124664;
    return 0xffffffff;
  }
  iVar2 = semQInit();
  if (iVar2 == 0) {
    if (param_3 == 0) {
      *(undefined4 *)(param_1 + 0x54) = *DAT_30124668;
    }
    else {
      if (param_3 != 1) {
        puVar1 = (undefined4 *)__errno();
        *puVar1 = DAT_3012466c;
        return 0xffffffff;
      }
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    *(undefined2 *)(param_1 + 0x42) = 0;
    *(char *)(param_1 + 0x41) = (char)param_2;
    *(undefined1 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0;
    *(undefined1 *)(param_1 + 0x60) = 0;
    objCoreInit(param_1,*DAT_30124670);
    return 0;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * semBInitialize @ 0x30123F90  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: semBInit
 * Константы: 0x30123F90
 * ---------------------------------------------------------------- */
int semBInitialize(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = semBInit(param_1), iVar1 == 0)) {
    return param_1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * semBGive @ 0x30123FC0  (примерный размер ~292 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: errnoGet, errnoSet, objVerify, windExit, windPendQGet
 * Константы: 0xFFFFFFFF, 0x30123FC0
 * Данные: DAT_30124670, DAT_30124674, DAT_30124678, DAT_3012467c
 * ---------------------------------------------------------------- */
undefined4 semBGive(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = objVerify(param_1,*DAT_30124670);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x44) == 0) {
      iVar1 = *(int *)(param_1 + 0x54);
      *(undefined4 *)(param_1 + 0x54) = 0;
      if ((*(int *)(param_1 + 0x5c) == 0) || (iVar1 == 0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 0;
        *DAT_30124674 = 1;
        uVar3 = errnoGet();
        iVar1 = (*(code *)*DAT_30124678)
                          (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
        if (iVar1 == 0) {
          if ((*(byte *)(param_1 + 0x60) & 1) != 0) {
            *(undefined4 *)(param_1 + 0x5c) = 0;
          }
        }
        else {
          if ((*(byte *)(param_1 + 0x41) & 0x10) != 0) {
            uVar2 = 0xffffffff;
            uVar3 = DAT_3012467c;
          }
          *(undefined4 *)(param_1 + 0x5c) = 0;
        }
        windExit();
        errnoSet(uVar3);
      }
    }
    else {
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x44) + -0x50;
      *DAT_30124674 = 1;
      windPendQGet(param_1 + 0x44);
      windExit();
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * semBGiveNoLock @ 0x301240E4  (примерный размер ~188 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 3
 * Вызывает: errnoGet, errnoSet, windPendQGet
 * Константы: 0x301240E4, 0xFFFFFFFF
 * Данные: DAT_30124678, DAT_3012467c
 * ---------------------------------------------------------------- */
undefined4 semBGiveNoLock(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x44) + -0x50;
    windPendQGet(param_1 + 0x44);
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x54) = 0;
  if (*(int *)(param_1 + 0x5c) == 0) {
    return 0;
  }
  if (iVar3 == 0) {
    return 0;
  }
  uVar2 = 0;
  uVar1 = errnoGet();
  iVar3 = (*(code *)*DAT_30124678)(*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
  if (iVar3 == 0) {
    if ((*(byte *)(param_1 + 0x60) & 1) == 0) goto LAB_30124174;
  }
  else if ((*(byte *)(param_1 + 0x41) & 0x10) != 0) {
    uVar2 = 0xffffffff;
    uVar1 = DAT_3012467c;
  }
  *(undefined4 *)(param_1 + 0x5c) = 0;
LAB_30124174:
  errnoSet(uVar1);
  return uVar2;
}

/* ----------------------------------------------------------------
 * semBTake @ 0x301241A0  (примерный размер ~292 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 5
 * Вызывает: __errno, errnoSet, objVerify, windExit, windPendQPut
 * Вызывают: FUN_300e2404
 * Константы: 0x301241A0
 * Данные: DAT_30124668, DAT_30124670, DAT_30124674, DAT_30124680, DAT_30124684, DAT_30124688, DAT_3012468c, DAT_30124690
 * ---------------------------------------------------------------- */
int semBTake(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*DAT_30124680 < 1) {
    do {
      iVar2 = objVerify(param_1,*DAT_30124670);
      if (iVar2 != 0) {
        return -1;
      }
      if (*(int *)(param_1 + 0x54) == 0) {
        *(undefined4 *)(param_1 + 0x54) = *DAT_30124668;
        return 0;
      }
      if (param_2 == 0) {
        errnoSet(DAT_30124688);
        return -1;
      }
      *DAT_30124674 = 1;
      iVar2 = windPendQPut(param_1 + 0x44,param_2);
      if (iVar2 != 0) {
        windExit();
        return -1;
      }
      iVar2 = windExit();
      if (iVar2 != 1) {
        return iVar2;
      }
      param_2 = (*(code *)*DAT_3012468c)(param_2);
    } while (param_2 != 0);
    errnoSet(DAT_30124690);
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30124684;
  }
  return -1;
}

/* ----------------------------------------------------------------
 * semBTakeNoLock @ 0x301242C4  (примерный размер ~76 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 2
 * Вызывает: errnoSet, windPendQPut
 * Константы: 0xFFFFFFFF, 0x301242C4
 * Данные: DAT_30124688
 * ---------------------------------------------------------------- */
undefined4 semBTakeNoLock(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x54) == 0) {
    *(undefined4 *)(param_1 + 0x54) = param_3;
    uVar1 = 0;
  }
  else if (param_2 == 0) {
    errnoSet(DAT_30124688);
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = windPendQPut(param_1 + 0x44);
    if (iVar2 == 0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * semBGiveScalable @ 0x30124310  (примерный размер ~400 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 7
 * Вызывает: __errno, errnoGet, errnoSet, objVerify, windExit, windPendQGet, workQAdd1
 * Константы: 0xFFFFFFFF, 0x30124310
 * Данные: DAT_30124664, DAT_30124670, DAT_30124674, DAT_30124678, DAT_3012467c, DAT_30124694, DAT_30124698
 * ---------------------------------------------------------------- */
undefined4 semBGiveScalable(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  byte in_Q;
  undefined8 uVar6;
  
  if ((param_2 & DAT_30124694) == 0) {
    iVar5 = *DAT_30124674;
    if (iVar5 == 1) {
      workQAdd1(DAT_30124698,param_1);
      uVar4 = 0;
    }
    else {
      uVar3 = (uint)(byte)((iVar5 + -1 < 0) << 4 | (iVar5 == 1) << 3 | (iVar5 != 0) << 2 |
                           SBORROW4(iVar5,1) << 1 | in_Q) << 0x1b | 0x80;
      if (((param_2 & 0x40) == 0) &&
         (uVar6 = objVerify(param_1,*DAT_30124670), uVar3 = (uint)((ulonglong)uVar6 >> 0x20),
         (int)uVar6 != 0)) {
        uVar4 = 0xffffffff;
      }
      else if (*(int *)(param_1 + 0x44) == 0) {
        if ((param_2 & 0x100) == 0) {
          iVar5 = *(int *)(param_1 + 0x54);
          *(undefined4 *)(param_1 + 0x54) = 0;
          if ((*(int *)(param_1 + 0x5c) == 0) || (iVar5 == 0)) {
            uVar4 = 0;
          }
          else {
            uVar4 = 0;
            *DAT_30124674 = 1;
            uVar2 = errnoGet();
            iVar5 = (*(code *)*DAT_30124678)
                              (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
            if (iVar5 == 0) {
              if ((*(byte *)(param_1 + 0x60) & 1) != 0) {
                *(undefined4 *)(param_1 + 0x5c) = 0;
              }
            }
            else {
              if ((*(byte *)(param_1 + 0x41) & 0x10) != 0) {
                uVar4 = 0xffffffff;
                uVar2 = DAT_3012467c;
              }
              *(undefined4 *)(param_1 + 0x5c) = 0;
            }
            windExit();
            errnoSet(uVar2);
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x54) = 0;
          uVar4 = 0;
        }
      }
      else {
        *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x44) + -0x50;
        *DAT_30124674 = 1;
        windPendQGet(param_1 + 0x44,uVar3);
        windExit();
        uVar4 = 0;
      }
    }
  }
  else {
    puVar1 = (undefined4 *)__errno();
    uVar4 = 0xffffffff;
    *puVar1 = DAT_30124664;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * semBTakeScalable @ 0x301244A0  (примерный размер ~328 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: __errno, errnoSet, objVerify, windExit, windPendQPut
 * Константы: 0xFFFFFF00, 0x301244A0
 * Данные: DAT_30124664, DAT_30124668, DAT_30124670, DAT_30124674, DAT_30124680, DAT_30124684, DAT_30124688, DAT_3012468c
 * ---------------------------------------------------------------- */
int semBTakeScalable(int param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  char in_CY;
  char in_OV;
  char cVar5;
  byte in_Q;
  uint in_cpsr;
  uint uVar6;
  undefined8 uVar7;
  
  if ((param_3 & DAT_30124694) != 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30124664;
    return -1;
  }
  cVar5 = (param_3 & 0x80) == 0;
  cVar4 = false;
  if ((bool)cVar5) {
    iVar3 = *DAT_30124680;
    cVar4 = iVar3 < 0;
    cVar5 = iVar3 == 0;
    in_CY = '\x01';
    in_OV = '\0';
    if (0 < iVar3) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = DAT_30124684;
      return -1;
    }
  }
  while( true ) {
    uVar2 = (uint)(byte)(cVar4 << 4 | cVar5 << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b | 0x80;
    uVar6 = in_cpsr & 0xffffff00;
    if ((param_3 & 0x40) == 0) {
      uVar7 = objVerify(param_1,*DAT_30124670);
      uVar2 = (uint)((ulonglong)uVar7 >> 0x20);
      if ((int)uVar7 != 0) {
        return -1;
      }
    }
    if (*(int *)(param_1 + 0x54) == 0) {
      *(undefined4 *)(param_1 + 0x54) = *DAT_30124668;
      return 0;
    }
    if (param_2 == 0) {
      errnoSet(DAT_30124688,uVar2);
      return -1;
    }
    *DAT_30124674 = 1;
    in_cpsr = uVar6 & 0xffffff00;
    in_Q = (uVar6 >> 0x1b & 1) != 0;
    iVar3 = windPendQPut(param_1 + 0x44,param_2);
    if (iVar3 != 0) break;
    iVar3 = windExit();
    in_CY = iVar3 != 0;
    in_OV = SBORROW4(iVar3,1);
    cVar4 = iVar3 + -1 < 0;
    cVar5 = iVar3 == 1;
    if (!(bool)cVar5) {
      return iVar3;
    }
    param_2 = (*(code *)*DAT_3012468c)(param_2);
  }
  windExit();
  return -1;
}

/* ----------------------------------------------------------------
 * semBGiveDefer @ 0x301245E8  (примерный размер ~180 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: windPendQGet
 * Константы: 0x301245E8
 * Данные: DAT_30124678
 * ---------------------------------------------------------------- */
void semBGiveDefer(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = *(int *)(param_1 + 0x54);
  iVar1 = *(int *)(param_1 + 0x44);
  *(int *)(param_1 + 0x54) = iVar1;
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 0x5c) != 0) && (iVar2 != 0)) {
      iVar1 = (*(code *)*DAT_30124678)(*(int *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
      bVar3 = iVar1 == 0;
      if (bVar3) {
        bVar3 = (*(byte *)(param_1 + 0x60) & 1) == 0;
      }
      if (!bVar3) {
        *(undefined4 *)(param_1 + 0x5c) = 0;
      }
    }
  }
  else {
    *(int *)(param_1 + 0x54) = iVar1 + -0x50;
    windPendQGet(param_1 + 0x44);
  }
  return;
}

/* ----------------------------------------------------------------
 * semCInit @ 0x3012469C  (примерный размер ~164 байт)
 * Модуль: kernel | Вызывают: 2 | Вызывает: 3
 * Вызывает: __errno, objCoreInit, semQInit
 * Вызывают: semCCreate, semCInitialize
 * Константы: 0xFFFFFFFF, 0x3012469C, 0xFFFFFFCE
 * Данные: DAT_30124a44, DAT_30124a48, DAT_30124a4c
 * ---------------------------------------------------------------- */
undefined4 semCInit(int param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((param_2 & 0xffffffce) != 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30124a44;
    return 0xffffffff;
  }
  if (param_3 < 0) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30124a48;
    return 0xffffffff;
  }
  iVar2 = semQInit(param_1,param_2);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 0x54) = param_3;
  *(undefined2 *)(param_1 + 0x42) = 0;
  *(char *)(param_1 + 0x41) = (char)param_2;
  *(undefined1 *)(param_1 + 0x40) = 2;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined1 *)(param_1 + 0x60) = 0;
  objCoreInit(param_1,*DAT_30124a4c);
  return 0;
}

/* ----------------------------------------------------------------
 * semCInitialize @ 0x30124740  (примерный размер ~48 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: semCInit
 * Константы: 0x30124740
 * ---------------------------------------------------------------- */
int semCInitialize(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = semCInit(param_1), iVar1 == 0)) {
    return param_1;
  }
  return 0;
}

/* ----------------------------------------------------------------
 * semCGive @ 0x30124770  (примерный размер ~312 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 6
 * Вызывает: __errno, errnoGet, errnoSet, objVerify, windExit, windPendQGet
 * Константы: 0xFFFFFFFF, 0x30124770
 * Данные: DAT_30124a4c, DAT_30124a50, DAT_30124a54, DAT_30124a58, DAT_30124a5c
 * ---------------------------------------------------------------- */
undefined4 semCGive(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar1 = objVerify(param_1,*DAT_30124a4c);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x44) == 0) {
      iVar1 = *(int *)(param_1 + 0x54);
      iVar5 = iVar1 + 1;
      *(int *)(param_1 + 0x54) = iVar5;
      if (iVar5 == 0) {
        *(int *)(param_1 + 0x54) = iVar1;
        puVar3 = (undefined4 *)__errno();
        *puVar3 = DAT_30124a50;
        uVar2 = 0xffffffff;
      }
      else if (*(int *)(param_1 + 0x5c) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 0;
        *DAT_30124a54 = 1;
        uVar4 = errnoGet();
        iVar1 = (*(code *)*DAT_30124a58)
                          (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
        if (iVar1 == 0) {
          if ((*(byte *)(param_1 + 0x60) & 1) != 0) {
            *(undefined4 *)(param_1 + 0x5c) = 0;
          }
        }
        else {
          if ((*(byte *)(param_1 + 0x41) & 0x10) != 0) {
            uVar2 = 0xffffffff;
            uVar4 = DAT_30124a5c;
          }
          *(undefined4 *)(param_1 + 0x5c) = 0;
        }
        windExit();
        errnoSet(uVar4);
      }
    }
    else {
      *DAT_30124a54 = 1;
      windPendQGet(param_1 + 0x44);
      windExit();
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * semCTake @ 0x301248A8  (примерный размер ~288 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 5
 * Вызывает: __errno, errnoSet, objVerify, windExit, windPendQPut
 * Константы: 0x301248A8
 * Данные: DAT_30124a4c, DAT_30124a54, DAT_30124a60, DAT_30124a64, DAT_30124a68, DAT_30124a6c, DAT_30124a70
 * ---------------------------------------------------------------- */
int semCTake(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*DAT_30124a60 < 1) {
    do {
      iVar2 = objVerify(param_1,*DAT_30124a4c);
      if (iVar2 != 0) {
        return -1;
      }
      if (*(int *)(param_1 + 0x54) != 0) {
        *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
        return 0;
      }
      if (param_2 == 0) {
        errnoSet(DAT_30124a68);
        return -1;
      }
      *DAT_30124a54 = 1;
      iVar2 = windPendQPut(param_1 + 0x44,param_2);
      if (iVar2 != 0) {
        windExit();
        return -1;
      }
      iVar2 = windExit();
      if (iVar2 != 1) {
        return iVar2;
      }
      param_2 = (*(code *)*DAT_30124a6c)(param_2);
    } while (param_2 != 0);
    errnoSet(DAT_30124a70);
  }
  else {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = DAT_30124a64;
  }
  return -1;
}

/* ----------------------------------------------------------------
 * semCGiveDefer @ 0x301249C8  (примерный размер ~172 байт)
 * Модуль: kernel | Вызывают: 0 | Вызывает: 1
 * Вызывает: windPendQGet
 * Константы: 0x301249C8
 * Данные: DAT_30124a58
 * ---------------------------------------------------------------- */
void semCGiveDefer(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x44) == 0) {
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
    if (*(int *)(param_1 + 0x5c) != 0) {
      iVar1 = (*(code *)*DAT_30124a58)(*(int *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
      if (iVar1 == 0) {
        if ((*(byte *)(param_1 + 0x60) & 1) == 1) {
          *(undefined4 *)(param_1 + 0x5c) = 0;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x5c) = 0;
      }
    }
  }
  else {
    windPendQGet(param_1 + 0x44);
  }
  return;
}

/* ----------------------------------------------------------------
 * semDeleteLibInit @ 0x30124A74  (примерный размер ~20 байт)
 * Модуль: kernel | Вызывают: 1 | Вызывает: 0
 * Вызывают: usrKernelCoreInit
 * Константы: 0x30124A74
 * Данные: DAT_30124c98, DAT_30124c9c
 * ---------------------------------------------------------------- */
void semDeleteLibInit(void)

{
  *(undefined4 *)(*DAT_30124c98 + 0x14) = DAT_30124c9c;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30124a88 @ 0x30124A88  (примерный размер ~156 байт)
 * Модуль: kernel | Вызывают: 5 | Вызывает: 6
 * Вызывает: objCoreInvalidate, objCoreTerminate, objFree, taskUnsafe, windExit, windSemDelete
 * Вызывают: __diab_free_mutex, __diab_free_semaphore, semDelete, semDestroy, semTerminate
 * Константы: 0x30124A88
 * Данные: DAT_30124c98, DAT_30124ca0, DAT_30124ca4, DAT_30124ca8
 * ---------------------------------------------------------------- */
undefined4 FUN_30124a88(int param_1,int param_2)

{
  objCoreInvalidate();
  *DAT_30124ca0 = 1;
  windSemDelete(param_1);
  if ((code *)*DAT_30124ca4 != (code *)0x0) {
    (*(code *)*DAT_30124ca4)(param_1 + 0x58);
  }
  *(int *)(*DAT_30124ca8 + 0xac) = *(int *)(*DAT_30124ca8 + 0xac) + 1;
  windExit();
  objCoreTerminate(param_1);
  if (param_2 != 0) {
    objFree(*DAT_30124c98,param_1);
  }
  taskUnsafe();
  return 0;
}

