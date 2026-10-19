/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : flash — флеш-подсистема: NAND-контроллер, ptable, YAFFS/YAFFS2, NV-память (NVM/nvim)
 * Часть  : 2 (функций: 150, адреса 0x30019F40..0x30022138)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * yaffs_CheckSpaceForAllocation @ 0x30019F40  (примерный размер ~64 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 1
 * Вызывает: yaffs2_CalcCheckpointBlocksRequired
 * Вызывают: FUN_30019f80, yaffs2_HandleHole, yaffs_DoWriteDataToFile
 * Константы: 0x30019F40
 * ---------------------------------------------------------------- */
bool yaffs_CheckSpaceForAllocation(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  iVar1 = yaffs2_CalcCheckpointBlocksRequired(param_1);
  return *(int *)(param_1 + 0xc) * (iVar2 + iVar1) + param_2 < *(int *)(param_1 + 0xd58);
}

/* ----------------------------------------------------------------
 * FUN_30019f80 @ 0x30019F80  (примерный размер ~380 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_30018fb8, FUN_30019e10, printf, yaffs_CheckSpaceForAllocation, yaffs_SetChunkBit
 * Вызывают: FUN_3001a0fc
 * Константы: 0x30019F80, 0xFF0FFFFF, 0x00500000, 0xFFFFFFFF
 * Данные: DAT_3001ac34, DAT_3001ac38, DAT_3001ae44, DAT_3001ae48, DAT_3001afc8
 * ---------------------------------------------------------------- */
int FUN_30019f80(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  
  if (*(int *)(param_1 + 0x138) < 0) {
    uVar1 = FUN_30019e10(param_1);
    *(undefined4 *)(param_1 + 0x138) = uVar1;
    *(undefined4 *)(param_1 + 0x13c) = 0;
  }
  if ((param_2 == 0) && (iVar2 = yaffs_CheckSpaceForAllocation(param_1,1), iVar2 == 0)) {
    iVar2 = -1;
  }
  else {
    if ((*(int *)(param_1 + 0x134) < *(int *)(param_1 + 0x1c)) &&
       ((*(int *)(param_1 + 0x13c) == 0 && ((*DAT_3001ae44 & 4) != 0)))) {
      printf(DAT_3001ae48);
    }
    if (*(int *)(param_1 + 0x138) < 0) {
      printf(DAT_3001afc8);
      iVar2 = -1;
    }
    else {
      puVar3 = (uint *)FUN_30018fb8(param_1,*(undefined4 *)(param_1 + 0x138));
      iVar2 = *(int *)(param_1 + 0x138) * *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x13c);
      *puVar3 = *puVar3 & DAT_3001ac34 | (((*puVar3 << 0xc) >> 0x16) + 1 & DAT_3001ac38) << 10;
      yaffs_SetChunkBit(param_1,*(undefined4 *)(param_1 + 0x138),*(undefined4 *)(param_1 + 0x13c));
      *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + 1;
      *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) + -1;
      if (*(uint *)(param_1 + 0xc) <= *(uint *)(param_1 + 0x13c)) {
        *puVar3 = *puVar3 & 0xff0fffff | 0x500000;
        *(undefined4 *)(param_1 + 0x138) = 0xffffffff;
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = puVar3;
      }
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_3001a0fc @ 0x3001A0FC  (примерный размер ~504 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 10
 * Вызывает: FUN_300195b0, FUN_30019658, FUN_30019704, FUN_30019d80, FUN_30019f80, printf, yaffs2_InvalidateCheckpoint, yaffs_DeleteChunk, yaffs_SkipRestOfBlock, yaffs_WriteChunkWithTagsToNAND
 * Вызывают: FUN_3001b01c, FUN_3001d45c, yaffs_UpdateObjectHeader
 * Константы: 0x02000000, 0x3001A0FC, 0xFDFFFFFF
 * Данные: DAT_3001b0d4, DAT_3001b0d8, DAT_3001b0dc, DAT_3001b0e0
 * ---------------------------------------------------------------- */
int FUN_3001a0fc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *local_28;
  
  uVar4 = 0;
  iVar3 = 0;
  yaffs2_InvalidateCheckpoint(param_1);
  while( true ) {
    local_28 = (uint *)0x0;
    iVar2 = 0;
    iVar1 = FUN_30019f80(param_1,param_4,&local_28);
    if (iVar1 < 0) break;
    uVar4 = uVar4 + 1;
    if (*(int *)(param_1 + 0x84) != 0) {
      *local_28 = *local_28 & 0xfdffffff;
    }
    if (((*local_28 & 0x2000000) == 0) && (iVar2 = FUN_300195b0(param_1,iVar1), iVar2 != 1)) {
      printf(DAT_3001b0d4,iVar1);
      yaffs_DeleteChunk(param_1,iVar1,1,DAT_3001b0d8);
      yaffs_SkipRestOfBlock(param_1);
    }
    else {
      iVar3 = yaffs_WriteChunkWithTagsToNAND(param_1,iVar1,param_2,param_3);
      if ((*local_28 & 0x2000000) == 0) {
        iVar3 = FUN_30019658(param_1,iVar1,param_2,param_3);
      }
      if (iVar3 == 1) {
        *local_28 = *local_28 | 0x2000000;
        FUN_30019704(param_1,iVar1,param_2,param_3);
      }
      else {
        FUN_30019d80(param_1,iVar1,iVar2);
      }
    }
    if ((iVar3 == 1) || ((*DAT_3001b0dc != 0 && (*DAT_3001b0dc < uVar4)))) break;
  }
  if (iVar3 == 0) {
    iVar1 = -1;
  }
  if (1 < (int)uVar4) {
    printf(DAT_3001b0e0,uVar4);
    *(uint *)(param_1 + 0xe50) = uVar4 + *(int *)(param_1 + 0xe50) + -1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3001a2f4 @ 0x3001A2F4  (примерный размер ~80 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: yaffs_FindObjectByName, yaffs_SetObjectName
 * Константы: 0x3001A2F4
 * ---------------------------------------------------------------- */
short FUN_3001a2f4(byte *param_1)

{
  ushort uVar1;
  short sVar2;
  
  sVar2 = 0;
  uVar1 = 1;
  if (param_1 != (byte *)0x0) {
    for (; (*param_1 != 0 && (uVar1 < 0x7f)); uVar1 = uVar1 + 1) {
      sVar2 = *param_1 * uVar1 + sVar2;
      param_1 = param_1 + 1;
    }
  }
  return sVar2;
}

/* ----------------------------------------------------------------
 * yaffs_SetObjectName @ 0x3001A344  (примерный размер ~104 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 4
 * Вызывает: FUN_3001a2f4, memset, strcpy, ystrnlen
 * Вызывают: FUN_3001ca68, FUN_3001e034, yaffs_SetObjectNameFromOH
 * Константы: 0x3001A344
 * ---------------------------------------------------------------- */
void yaffs_SetObjectName(int param_1,char *param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  memset((void *)(param_1 + 0x38),0,0x10);
  if ((param_2 == (char *)0x0) || (iVar2 = ystrnlen(param_2,0x10), 0xf < iVar2)) {
    *(undefined1 *)(param_1 + 0x38) = 0;
  }
  else {
    strcpy((char *)(param_1 + 0x38),param_2);
  }
  uVar1 = FUN_3001a2f4(param_2);
  *(undefined2 *)(param_1 + 4) = uVar1;
  return;
}

/* ----------------------------------------------------------------
 * yaffs_SetObjectNameFromOH @ 0x3001A3AC  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 1
 * Вызывает: yaffs_SetObjectName
 * Вызывают: FUN_3001beac, yaffs1_Scan, yaffs2_ScanBackwards
 * Константы: 0x3001A3AC
 * ---------------------------------------------------------------- */
void yaffs_SetObjectNameFromOH(undefined4 param_1,int param_2)

{
  yaffs_SetObjectName(param_1,param_2 + 10);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_GetTnode @ 0x3001A3CC  (примерный размер ~72 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 2
 * Вызывает: memset, yaffs_AllocateRawTnode
 * Вызывают: FUN_3001d1d8, FUN_30029b40, yaffs_AddOrFindLevel0Tnode
 * Константы: 0x3001A3CC
 * ---------------------------------------------------------------- */
void * yaffs_GetTnode(int param_1)

{
  void *__s;
  
  __s = (void *)yaffs_AllocateRawTnode(param_1);
  if (__s != (void *)0x0) {
    memset(__s,0,*(size_t *)(param_1 + 0xb0));
    *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + 1;
  }
  *(undefined4 *)(param_1 + 0x120) = 0;
  return __s;
}

/* ----------------------------------------------------------------
 * FUN_3001a414 @ 0x3001A414  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 8 | Вызывает: 1
 * Вызывает: yaffs_FreeRawTnode
 * Вызывают: FUN_3001aa7c, FUN_3001b01c, FUN_3001cd00, FUN_3001cda0, FUN_3001cea4, FUN_3001d1d8, yaffs_AddOrFindLevel0Tnode, yaffs_DeleteFile
 * Константы: 0x3001A414
 * ---------------------------------------------------------------- */
void FUN_3001a414(int param_1,undefined4 param_2)

{
  yaffs_FreeRawTnode(param_1,param_2);
  *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + -1;
  *(undefined4 *)(param_1 + 0x120) = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001a444 @ 0x3001A444  (примерный размер ~36 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: yaffs_DeinitialiseRawTnodesAndObjects
 * Вызывают: yaffs_Deinitialise, yaffs_GutsInitialise
 * Константы: 0x3001A444
 * ---------------------------------------------------------------- */
void FUN_3001a444(int param_1)

{
  yaffs_DeinitialiseRawTnodesAndObjects(param_1);
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  return;
}

/* ----------------------------------------------------------------
 * yaffs_LoadLevel0Tnode @ 0x3001A468  (примерный размер ~268 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_3001aa7c, FUN_3001d7ac, yaffs_PutChunkIntoFile
 * Константы: 0x3001A468
 * ---------------------------------------------------------------- */
void yaffs_LoadLevel0Tnode(int param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  param_4 = param_4 >> (*(ushort *)(param_1 + 0xa4) & 0xff);
  uVar2 = *(int *)(param_1 + 0xa8) * (param_3 & 0xf);
  uVar1 = uVar2 >> 5;
  uVar2 = uVar2 & 0x1f;
  uVar4 = *(uint *)(param_1 + 0xac);
  puVar3 = (uint *)(param_2 + uVar1 * 4);
  *puVar3 = *puVar3 & ~(uVar4 << uVar2);
  puVar3 = (uint *)(param_2 + uVar1 * 4);
  *puVar3 = *puVar3 | (uVar4 & param_4) << uVar2;
  if (0x20 - uVar2 < *(uint *)(param_1 + 0xa8)) {
    uVar4 = *(uint *)(param_1 + 0xac) >> (0x20 - uVar2 & 0xff);
    puVar3 = (uint *)(param_2 + (uVar1 + 1) * 4);
    *puVar3 = *puVar3 & ~uVar4;
    puVar3 = (uint *)(param_2 + (uVar1 + 1) * 4);
    *puVar3 = *puVar3 | uVar4 & param_4 >> (0x20 - uVar2 & 0xff);
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_GetChunkGroupBase @ 0x3001A574  (примерный размер ~128 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_3001aa7c, FUN_3001d7ac, yaffs_FindChunkInFile, yaffs_PutChunkIntoFile, yaffs_VerifyFile
 * Константы: 0x3001A574
 * ---------------------------------------------------------------- */
int yaffs_GetChunkGroupBase(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(int *)(param_1 + 0xa8) * (param_3 & 0xf);
  uVar1 = uVar3 >> 5;
  uVar3 = uVar3 & 0x1f;
  uVar2 = *(uint *)(param_2 + uVar1 * 4) >> uVar3;
  if (0x20 - uVar3 < *(uint *)(param_1 + 0xa8)) {
    uVar2 = uVar2 | *(int *)(param_2 + (uVar1 + 1) * 4) << (0x20 - uVar3 & 0xff);
  }
  return (uVar2 & *(uint *)(param_1 + 0xac)) << (*(ushort *)(param_1 + 0xa4) & 0xff);
}

/* ----------------------------------------------------------------
 * yaffs_FindLevel0Tnode @ 0x3001A5F4  (примерный размер ~172 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_3001d7ac, yaffs_FindChunkInFile, yaffs_VerifyFile
 * Константы: 0x3001A5F4
 * Данные: DAT_3001b520
 * ---------------------------------------------------------------- */
int yaffs_FindLevel0Tnode(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_2 + 0x10);
  uVar1 = *(uint *)(param_2 + 0xc);
  if (uVar1 < 7) {
    if (DAT_3001b520 < param_3) {
      iVar4 = 0;
    }
    else {
      iVar2 = 0;
      for (uVar3 = param_3 >> 4; uVar3 != 0; uVar3 = uVar3 >> 3) {
        iVar2 = iVar2 + 1;
      }
      if (*(int *)(param_2 + 0xc) < iVar2) {
        iVar4 = 0;
      }
      else {
        for (; (0 < (int)uVar1 && (iVar4 != 0));
            iVar4 = *(int *)(iVar4 + (param_3 >> (iVar2 + 1U & 0xff) & 7) * 4)) {
          iVar2 = uVar1 * 3;
          uVar1 = uVar1 - 1;
        }
      }
    }
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * yaffs_AddOrFindLevel0Tnode @ 0x3001A6A0  (примерный размер ~524 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_3001a414, memcpy, printf, yaffs_GetTnode
 * Вызывают: FUN_30029b40, yaffs_PutChunkIntoFile
 * Константы: 0x3001A6A0
 * Данные: DAT_3001b520, DAT_3001b6e8
 * ---------------------------------------------------------------- */
void * yaffs_AddOrFindLevel0Tnode(int param_1,int param_2,uint param_3,void *param_4)

{
  void *__dest;
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (*(uint *)(param_2 + 0xc) < 7) {
    if (DAT_3001b520 < param_3) {
      __dest = (void *)0x0;
    }
    else {
      iVar4 = 0;
      for (uVar5 = param_3 >> 4; uVar5 != 0; uVar5 = uVar5 >> 3) {
        iVar4 = iVar4 + 1;
      }
      if (*(int *)(param_2 + 0xc) < iVar4) {
        for (iVar3 = *(int *)(param_2 + 0xc); iVar3 < iVar4; iVar3 = iVar3 + 1) {
          puVar1 = (undefined4 *)yaffs_GetTnode(param_1);
          if (puVar1 == (undefined4 *)0x0) {
            printf(DAT_3001b6e8);
            return (void *)0x0;
          }
          *puVar1 = *(undefined4 *)(param_2 + 0x10);
          *(undefined4 **)(param_2 + 0x10) = puVar1;
          *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
        }
      }
      iVar4 = *(int *)(param_2 + 0xc);
      __dest = *(void **)(param_2 + 0x10);
      if (0 < iVar4) {
        while( true ) {
          if (iVar4 < 1) {
            return __dest;
          }
          if (__dest == (void *)0x0) break;
          uVar5 = param_3 >> (iVar4 * 3 + 1U & 0xff) & 7;
          if ((iVar4 < 2) || (*(int *)((int)__dest + uVar5 * 4) != 0)) {
            if (iVar4 == 1) {
              if (param_4 == (void *)0x0) {
                if (*(int *)((int)__dest + uVar5 * 4) == 0) {
                  uVar2 = yaffs_GetTnode(param_1);
                  *(undefined4 *)((int)__dest + uVar5 * 4) = uVar2;
                  if (*(int *)((int)__dest + uVar5 * 4) == 0) {
                    return (void *)0x0;
                  }
                }
              }
              else {
                if (*(int *)((int)__dest + uVar5 * 4) != 0) {
                  FUN_3001a414(param_1,*(undefined4 *)((int)__dest + uVar5 * 4));
                }
                *(void **)((int)__dest + uVar5 * 4) = param_4;
              }
            }
          }
          else {
            uVar2 = yaffs_GetTnode(param_1);
            *(undefined4 *)((int)__dest + uVar5 * 4) = uVar2;
            if (*(int *)((int)__dest + uVar5 * 4) == 0) {
              return (void *)0x0;
            }
          }
          __dest = *(void **)((int)__dest + uVar5 * 4);
          iVar4 = iVar4 + -1;
        }
        return (void *)0x0;
      }
      if (param_4 != (void *)0x0) {
        memcpy(__dest,param_4,(uint)(*(int *)(param_1 + 0xa8) << 4) >> 3);
        FUN_3001a414(param_1,param_4);
      }
    }
  }
  else {
    __dest = (void *)0x0;
  }
  return __dest;
}

/* ----------------------------------------------------------------
 * FUN_3001a8ac @ 0x3001A8AC  (примерный размер ~92 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3001a908
 * Константы: 0x3001A8AC
 * ---------------------------------------------------------------- */
undefined4 FUN_3001a8ac(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (((*(int *)(param_1 + 0xc) == param_3) && (*(int *)(param_1 + 8) == param_2)) &&
     (*(int *)(param_1 + 0x1c) == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3001a908 @ 0x3001A908  (примерный размер ~216 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_3001a8ac, __div32, yaffs_CheckChunkBit, yaffs_ReadChunkWithTagsFromNAND
 * Вызывают: FUN_3001d7ac, yaffs_FindChunkInFile
 * Константы: 0x3001A908
 * ---------------------------------------------------------------- */
int FUN_3001a908(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  do {
    if ((param_2 == 0) || ((int)(uint)*(ushort *)(param_1 + 0xa6) <= iVar3)) {
      return -1;
    }
    iVar1 = __div32(param_2,*(undefined4 *)(param_1 + 0xc));
    iVar4 = *(int *)(param_1 + 0xc);
    uVar2 = __div32(param_2,*(undefined4 *)(param_1 + 0xc));
    iVar1 = yaffs_CheckChunkBit(param_1,uVar2,param_2 - iVar4 * iVar1);
    if (iVar1 != 0) {
      if (*(short *)(param_1 + 0xa6) == 1) {
        return param_2;
      }
      yaffs_ReadChunkWithTagsFromNAND(param_1,param_2,0,param_3);
      iVar1 = FUN_3001a8ac(param_3,param_4,param_5);
      if (iVar1 != 0) {
        return param_2;
      }
    }
    param_2 = param_2 + 1;
    iVar3 = iVar3 + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_3001a9e0 @ 0x3001A9E0  (примерный размер ~156 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_30018fb8, __div32, printf, yaffs2_UpdateOldestDirtySequence
 * Вызывают: FUN_3001aa7c
 * Константы: 0x3001A9E0
 * Данные: DAT_3001ac38, DAT_3001ae44, DAT_3001b95c, DAT_3001b960
 * ---------------------------------------------------------------- */
void FUN_3001a9e0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  
  if ((*DAT_3001ae44 & 0x200) != 0) {
    printf(DAT_3001b95c,param_2);
  }
  uVar1 = __div32(param_2,*(undefined4 *)(param_1 + 0xc));
  puVar2 = (uint *)FUN_30018fb8(param_1,uVar1);
  if (puVar2 != (uint *)0x0) {
    *puVar2 = *puVar2 & DAT_3001b960 | (*puVar2 & 0x3ff) + 1 & DAT_3001ac38;
    *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) + 1;
    yaffs2_UpdateOldestDirtySequence(param_1,uVar1,puVar2);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001aa7c @ 0x3001AA7C  (примерный размер ~296 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_3001a414, FUN_3001a9e0, yaffs_GetChunkGroupBase, yaffs_LoadLevel0Tnode
 * Вызывают: FUN_3001cd00
 * Константы: 0x3001AA7C
 * ---------------------------------------------------------------- */
bool FUN_3001aa7c(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
  iVar1 = 1;
  uVar3 = *(undefined4 *)(param_1 + 8);
  if (param_2 == 0) {
    bVar4 = true;
  }
  else if (param_3 == 0) {
    for (iVar1 = 0xf; -1 < iVar1; iVar1 = iVar1 + -1) {
      iVar2 = yaffs_GetChunkGroupBase(uVar3,param_2,iVar1);
      if (iVar2 != 0) {
        FUN_3001a9e0(uVar3,iVar2);
        yaffs_LoadLevel0Tnode(uVar3,param_2,iVar1,0);
      }
    }
    bVar4 = true;
  }
  else {
    for (iVar2 = 7; (iVar1 != 0 && (-1 < iVar2)); iVar2 = iVar2 + -1) {
      if ((*(int *)(param_2 + iVar2 * 4) != 0) &&
         (iVar1 = FUN_3001aa7c(param_1,*(undefined4 *)(param_2 + iVar2 * 4),param_3 + -1,
                               iVar2 + param_4 * 8), iVar1 != 0)) {
        FUN_3001a414(uVar3,*(undefined4 *)(param_2 + iVar2 * 4));
        *(undefined4 *)(param_2 + iVar2 * 4) = 0;
      }
    }
    bVar4 = iVar1 != 0;
  }
  return bVar4;
}

/* ----------------------------------------------------------------
 * FUN_3001aba4 @ 0x3001ABA4  (примерный размер ~92 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_30018f98, FUN_30019514, FUN_30020c7c
 * Вызывают: FUN_3001ac00
 * Константы: 0x3001ABA4
 * ---------------------------------------------------------------- */
void FUN_3001aba4(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar1 = FUN_30020c7c(param_1 + 0xc);
  if (iVar1 == 0) {
    FUN_30018f98(param_1 + 0xc);
    iVar1 = FUN_30019514(*(undefined4 *)(param_1 + 0x30));
    piVar3 = (int *)(iVar2 + iVar1 * 0xc + 0x15c);
    *piVar3 = *piVar3 + -1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001ac00 @ 0x3001AC00  (примерный размер ~212 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_3001aba4, FUN_30020c7c, printf, yaffs_FreeRawObject
 * Вызывают: FUN_3001cc70
 * Константы: 0x3001AC00
 * Данные: DAT_3001babc, DAT_3001bac0, DAT_3001bb9c, DAT_3001bba0
 * ---------------------------------------------------------------- */
void FUN_3001ac00(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if (param_1 == 0) {
    printf(DAT_3001babc,DAT_3001bac0);
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    printf(DAT_3001babc,DAT_3001bb9c);
  }
  iVar1 = FUN_30020c7c(param_1 + 0x20);
  if (iVar1 == 0) {
    printf(DAT_3001babc,DAT_3001bba0);
  }
  FUN_3001aba4(param_1);
  yaffs_FreeRawObject(iVar2,param_1);
  *(int *)(iVar2 + 0x148) = *(int *)(iVar2 + 0x148) + -1;
  *(undefined4 *)(iVar2 + 0x120) = 0;
  return;
}

/* ----------------------------------------------------------------
 * yaffs_FindObjectByNumber @ 0x3001ACD4  (примерный размер ~132 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 1
 * Вызывает: FUN_30019514
 * Вызывают: FUN_3001b01c, yaffs1_Scan, yaffs_FindOrCreateObjectByNumber, yaffs_HandleShadowedObject, yaffs_HardlinkFixup
 * Константы: 0x3001ACD4
 * ---------------------------------------------------------------- */
int yaffs_FindObjectByNumber(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_30019514(param_2);
  piVar2 = *(int **)(param_1 + iVar1 * 0xc + 0x154);
  while( true ) {
    if ((int *)(param_1 + iVar1 * 0xc + 0x154) == piVar2) {
      return 0;
    }
    if ((piVar2 != (int *)0x0) && (piVar2[9] == param_2)) break;
    piVar2 = (int *)*piVar2;
  }
  return (int)(piVar2 + -3);
}

/* ----------------------------------------------------------------
 * FUN_3001ad58 @ 0x3001AD58  (примерный размер ~60 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3001b01c
 * Константы: 0x3001AD58
 * ---------------------------------------------------------------- */
int FUN_3001ad58(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc) * *(int *)(param_1 + 0x134);
  if (0 < *(int *)(param_1 + 0x138)) {
    iVar1 = iVar1 + (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x13c));
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * yaffs_FindChunkInFile @ 0x3001AD94  (примерный размер ~140 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 3
 * Вызывает: FUN_3001a908, yaffs_FindLevel0Tnode, yaffs_GetChunkGroupBase
 * Вызывают: FUN_3001b01c, FUN_3001d45c, FUN_3001d720, yaffsGetFileSavings, yaffs_PutChunkIntoFile
 * Константы: 0x3001AD94, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 yaffs_FindChunkInFile(int param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_68 [72];
  
  uVar3 = 0xffffffff;
  uVar2 = *(undefined4 *)(param_1 + 8);
  if (param_3 == (undefined1 *)0x0) {
    param_3 = auStack_68;
  }
  iVar1 = yaffs_FindLevel0Tnode(uVar2,param_1 + 0x68,param_2);
  if (iVar1 != 0) {
    uVar3 = yaffs_GetChunkGroupBase(uVar2,iVar1,param_2);
    uVar3 = FUN_3001a908(uVar2,uVar3,param_3,*(undefined4 *)(param_1 + 0x30),param_2);
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * yaffs_PutChunkIntoFile @ 0x3001AE20  (примерный размер ~508 байт)
 * Модуль: flash | Вызывают: 4 | Вызывает: 7
 * Вызывает: printf, yaffs_AddOrFindLevel0Tnode, yaffs_DeleteChunk, yaffs_FindChunkInFile, yaffs_GetChunkGroupBase, yaffs_LoadLevel0Tnode, yaffs_ReadChunkWithTagsFromNAND
 * Вызывают: FUN_3001b01c, FUN_3001d45c, yaffs1_Scan, yaffs2_ScanBackwards
 * Константы: 0x3001AE20
 * Данные: DAT_3001babc, DAT_3001bdb8, DAT_3001bdbc, DAT_3001bdc0, DAT_3001bedc, DAT_3001bee0, DAT_3001bee4
 * ---------------------------------------------------------------- */
undefined4 yaffs_PutChunkIntoFile(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_b4 [32];
  int local_94;
  undefined1 auStack_6c [32];
  uint local_4c;
  
  uVar3 = *(undefined4 *)(param_1 + 8);
  if (*(int *)(param_1 + 100) == 1) {
    iVar1 = yaffs_AddOrFindLevel0Tnode(uVar3,param_1 + 0x68,param_2,0);
    if (iVar1 == 0) {
      uVar3 = 0;
    }
    else if (param_3 == 0) {
      uVar3 = 1;
    }
    else {
      iVar2 = yaffs_GetChunkGroupBase(uVar3,iVar1,param_2);
      if ((param_4 != 0) && (0 < iVar2)) {
        if (0 < param_4) {
          yaffs_ReadChunkWithTagsFromNAND(uVar3,param_3,0,auStack_6c);
          iVar2 = yaffs_FindChunkInFile(param_1,param_2,auStack_b4);
        }
        if (iVar2 < 1) {
          printf(DAT_3001bedc);
        }
        if ((param_4 < 1) || ((0 < iVar2 && ((local_94 + 1U & 3) != local_4c)))) {
          yaffs_DeleteChunk(uVar3,param_3,1,DAT_3001bee4);
          return 1;
        }
        yaffs_DeleteChunk(uVar3,iVar2,1,DAT_3001bee0);
      }
      if (iVar2 == 0) {
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
      }
      yaffs_LoadLevel0Tnode(uVar3,iVar1,param_2,param_3);
      uVar3 = 1;
    }
  }
  else {
    if (param_4 == 0) {
      printf(DAT_3001bdb8);
      printf(DAT_3001babc,DAT_3001bdbc);
    }
    yaffs_DeleteChunk(uVar3,param_3,1,DAT_3001bdc0);
    uVar3 = 1;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_3001b01c @ 0x3001B01C  (примерный размер ~1620 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 21
 * Вызывает: FUN_30018fb8, FUN_3001a0fc, FUN_3001a414, FUN_3001ad58, FUN_3001cc70, printf, yaffs_BlockBecameDirty, yaffs_CheckChunkBit, yaffs_DeleteChunk, yaffs_FindChunkInFile, yaffs_FindObjectByNumber, yaffs_GetTempBuffer, yaffs_InitialiseTags, yaffs_PutChunkIntoFile
 *           ...
 * Вызывают: FUN_3001bb54
 * Константы: 0xFF0FFFFF, 0x3001B01C, 0x00800000, 0xBFFFFFFF, 0x00500000
 * Данные: DAT_3001b960, DAT_3001bdb4, DAT_3001c020, DAT_3001c024, DAT_3001c028, DAT_3001c184, DAT_3001c188, DAT_3001c24c
 * ---------------------------------------------------------------- */
int FUN_3001b01c(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int local_9c;
  int local_98;
  undefined4 local_8c;
  undefined1 auStack_74 [8];
  undefined4 local_6c;
  int local_68;
  undefined4 local_64;
  int local_54;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  
  local_9c = 1;
  iVar1 = FUN_3001ad58(param_1);
  puVar2 = (uint *)FUN_30018fb8(param_1,param_2);
  uVar7 = *puVar2;
  printf(DAT_3001c020,param_2,(*puVar2 << 0xc) >> 0x16,*puVar2 >> 0x1e & 1,param_3);
  if ((*puVar2 >> 0x14 & 0xf) == 5) {
    *puVar2 = *puVar2 & 0xff0fffff | 0x800000;
  }
  *puVar2 = *puVar2 & 0xbfffffff;
  *(undefined4 *)(param_1 + 0xd68) = 1;
  if (((uVar7 >> 0x14 & 0xf) == 7) ||
     (iVar3 = yaffs_StillSomeChunkBits(param_1,param_2), iVar3 == 0)) {
    printf(DAT_3001c024,param_2);
    yaffs_BlockBecameDirty(param_1,param_2);
  }
  else {
    iVar3 = yaffs_GetTempBuffer(param_1,DAT_3001c028);
    yaffs_VerifyBlock(param_1,puVar2,param_2);
    if (param_3 == 0) {
      local_98 = 5;
    }
    else {
      local_98 = *(int *)(param_1 + 0xc);
    }
    iVar6 = param_2 * *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0xd80);
    while ((((local_9c == 1 && (*(uint *)(param_1 + 0xd80) < *(uint *)(param_1 + 0xc))) &&
            ((*puVar2 >> 0x14 & 0xf) == 8)) && (0 < local_98))) {
      iVar4 = yaffs_CheckChunkBit(param_1,param_2,*(undefined4 *)(param_1 + 0xd80));
      if (iVar4 != 0) {
        local_98 = local_98 + -1;
        local_8c = 1;
        yaffs_InitialiseTags(auStack_74);
        yaffs_ReadChunkWithTagsFromNAND(param_1,iVar6,iVar3,auStack_74);
        pbVar5 = (byte *)yaffs_FindObjectByNumber(param_1,local_6c);
        if ((*DAT_3001bdb4 & 0x1000) != 0) {
          printf(DAT_3001c184,*(undefined4 *)(param_1 + 0xd80),local_6c,local_68,local_64);
        }
        if ((pbVar5 != (byte *)0x0) && (iVar4 = yaffs_SkipVerification(param_1), iVar4 == 0)) {
          if (local_68 == 0) {
            iVar4 = *(int *)(pbVar5 + 0x28);
          }
          else {
            iVar4 = iVar6;
            if ((*pbVar5 & 2) == 0) {
              iVar4 = yaffs_FindChunkInFile(pbVar5,local_68,0);
            }
          }
          if (iVar6 != iVar4) {
            printf(DAT_3001c188,iVar6,iVar4,local_6c,local_68);
          }
        }
        if (pbVar5 == (byte *)0x0) {
          printf(DAT_3001c24c,iVar6,local_6c,local_68,local_64);
LAB_3001b3dc:
          if (pbVar5 != (byte *)0x0) {
            local_54 = local_54 + 1;
            *(int *)(param_1 + 0xe38) = *(int *)(param_1 + 0xe38) + 1;
            if (local_68 == 0) {
              *(undefined4 *)(iVar3 + 0x1fc) = 0;
              local_44 = 0;
              *(undefined4 *)(iVar3 + 0x1f8) = 0;
              *(undefined4 *)(iVar3 + 0x1e8) = 0;
              local_40 = 0;
              if (*(int *)(pbVar5 + 100) == 1) {
                *(undefined4 *)(iVar3 + 0x124) = *(undefined4 *)(pbVar5 + 0x68);
                local_38 = *(undefined4 *)(iVar3 + 0x124);
              }
              yaffs_VerifyObjectHeader(pbVar5,iVar3,auStack_74,1);
              iVar4 = FUN_3001a0fc(param_1,iVar3,auStack_74,1);
            }
            else {
              iVar4 = FUN_3001a0fc(param_1,iVar3,auStack_74,1);
            }
            if (iVar4 < 0) {
              local_9c = 0;
              goto LAB_3001b50c;
            }
            if (local_68 == 0) {
              *(int *)(pbVar5 + 0x28) = iVar4;
              pbVar5[2] = (byte)local_54;
            }
            else {
              yaffs_PutChunkIntoFile(pbVar5,local_68,iVar4,0);
            }
          }
        }
        else {
          if (((*pbVar5 & 3) != 3) || (local_68 == 0)) goto LAB_3001b3dc;
          *(int *)(param_1 + 0xd58) = *(int *)(param_1 + 0xd58) + -1;
          *puVar2 = *puVar2 & DAT_3001b960 | (*puVar2 & 0x3ff) - 1 & DAT_3001c250;
          *(int *)(pbVar5 + 0x2c) = *(int *)(pbVar5 + 0x2c) + -1;
          if (*(int *)(pbVar5 + 0x2c) < 1) {
            *(undefined4 *)(*(int *)(param_1 + 0xd5c) + *(int *)(param_1 + 0xd60) * 4) = local_6c;
            *(int *)(param_1 + 0xd60) = *(int *)(param_1 + 0xd60) + 1;
          }
          local_8c = 0;
        }
        yaffs_DeleteChunk(param_1,iVar6,local_8c,DAT_3001c46c);
      }
LAB_3001b50c:
      *(int *)(param_1 + 0xd80) = *(int *)(param_1 + 0xd80) + 1;
      iVar6 = iVar6 + 1;
    }
    yaffs_ReleaseTempBuffer(param_1,iVar3,DAT_3001c470);
  }
  yaffs_VerifyCollectedBlock(param_1,puVar2,param_2);
  if ((*puVar2 >> 0x14 & 0xf) == 8) {
    *puVar2 = *puVar2 & 0xff0fffff | 0x500000;
  }
  else {
    for (uVar7 = 0; uVar7 < *(uint *)(param_1 + 0xd60); uVar7 = uVar7 + 1) {
      iVar3 = yaffs_FindObjectByNumber
                        (param_1,*(undefined4 *)(*(int *)(param_1 + 0xd5c) + uVar7 * 4));
      if (iVar3 != 0) {
        FUN_3001a414(param_1,*(undefined4 *)(iVar3 + 0x78));
        *(undefined4 *)(iVar3 + 0x78) = 0;
        if ((*DAT_3001bdb4 & 0x40) != 0) {
          printf(DAT_3001c474,*(undefined4 *)(iVar3 + 0x30));
        }
        FUN_3001cc70(iVar3);
        piVar8 = (int *)(*(int *)(iVar3 + 8) + DAT_3001c478);
        *piVar8 = *piVar8 + -1;
      }
    }
    iVar3 = FUN_3001ad58(param_1);
    if ((iVar3 <= iVar1) && ((*DAT_3001bdb4 & 0x40) != 0)) {
      printf(DAT_3001c588,iVar1,iVar3);
    }
    *(undefined4 *)(param_1 + 0xd7c) = 0;
    *(undefined4 *)(param_1 + 0xd80) = 0;
    *(undefined4 *)(param_1 + 0xd60) = 0;
  }
  *(undefined4 *)(param_1 + 0xd68) = 0;
  return local_9c;
}

/* ----------------------------------------------------------------
 * FUN_3001b670 @ 0x3001B670  (примерный размер ~1252 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_30018fb8, printf, yaffs2_BlockNotDisqualifiedFromGC, yaffs2_FindOldestDirtySequence
 * Вызывают: FUN_3001bb54
 * Константы: 0x3001B670, 0x04000000
 * Данные: DAT_3001bdb4, DAT_3001c9a4, DAT_3001c9a8, DAT_3001c9ac, DAT_3001c9b0
 * ---------------------------------------------------------------- */
int FUN_3001b670(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint local_48;
  uint local_44;
  uint local_40;
  undefined4 local_38;
  uint local_34;
  
  iVar7 = 0;
  uVar5 = 0;
  bVar1 = false;
  if ((*(int *)(param_1 + 0xd64) != 0) && (param_2 == 0)) {
    *(undefined4 *)(param_1 + 0xd70) = 0;
    puVar6 = *(uint **)(param_1 + 0x124);
    iVar4 = *(int *)(param_1 + 0xdc);
    while ((iVar4 <= *(int *)(param_1 + 0xe0) && (iVar7 == 0))) {
      if (((*puVar6 & 0x4000000) != 0) &&
         ((bVar1 = true, (*puVar6 >> 0x14 & 0xf) == 5 &&
          (iVar2 = yaffs2_BlockNotDisqualifiedFromGC(param_1,puVar6), iVar2 != 0)))) {
        uVar5 = 1;
        iVar7 = iVar4;
      }
      puVar6 = puVar6 + 2;
      iVar4 = iVar4 + 1;
    }
    if (((bVar1) && (iVar7 == 0)) && (*(int *)(param_1 + 0xe18) != 0)) {
      iVar7 = *(int *)(param_1 + 0xe18);
    }
    if (!bVar1) {
      *(undefined4 *)(param_1 + 0xd64) = 0;
    }
  }
  if (iVar7 == 0) {
    iVar4 = (*(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc)) + 1;
    if (param_2 == 0) {
      if (param_3 == 0) {
        local_44 = (int)(*(int *)(param_1 + 0xc) + ((uint)(*(int *)(param_1 + 0xc) >> 0x1f) >> 0x1d)
                        ) >> 3;
      }
      else {
        local_44 = *(int *)(param_1 + 0xc) / 2;
      }
      if ((int)local_44 < 4) {
        local_44 = 4;
      }
      if (param_3 == 0) {
        local_48 = 0;
      }
      else {
        local_48 = *(int *)(param_1 + 0xd78) * 2 + 4;
      }
      if ((int)local_48 < 4) {
        local_40 = 4;
      }
      else {
        local_40 = local_48;
      }
      if ((int)local_44 < (int)local_40) {
        local_48 = local_44;
      }
      else {
        local_48 = local_40;
      }
      iVar4 = ((int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1c)) >> 4) + 1;
      if (100 < iVar4) {
        iVar4 = 100;
      }
    }
    else {
      local_48 = *(uint *)(param_1 + 0xc);
    }
    iVar2 = 0;
    while ((iVar2 < iVar4 && ((*(int *)(param_1 + 0xd70) == 0 || (2 < *(uint *)(param_1 + 0xd74)))))
          ) {
      *(int *)(param_1 + 0xd6c) = *(int *)(param_1 + 0xd6c) + 1;
      if ((*(uint *)(param_1 + 0xd6c) < *(uint *)(param_1 + 0xdc)) ||
         (*(uint *)(param_1 + 0xe0) < *(uint *)(param_1 + 0xd6c))) {
        *(undefined4 *)(param_1 + 0xd6c) = *(undefined4 *)(param_1 + 0xdc);
      }
      puVar6 = (uint *)FUN_30018fb8(param_1,*(undefined4 *)(param_1 + 0xd6c));
      uVar8 = ((*puVar6 << 0xc) >> 0x16) - (*puVar6 & 0x3ff);
      if (((((*puVar6 >> 0x14 & 0xf) == 5) && ((int)uVar8 < *(int *)(param_1 + 0xc))) &&
          ((*(int *)(param_1 + 0xd70) == 0 || (uVar8 < *(uint *)(param_1 + 0xd74))))) &&
         (iVar3 = yaffs2_BlockNotDisqualifiedFromGC(param_1,puVar6), iVar3 != 0)) {
        *(undefined4 *)(param_1 + 0xd70) = *(undefined4 *)(param_1 + 0xd6c);
        *(uint *)(param_1 + 0xd74) = uVar8;
      }
      iVar2 = iVar2 + 1;
    }
    if ((*(int *)(param_1 + 0xd70) != 0) && (*(uint *)(param_1 + 0xd74) <= local_48)) {
      iVar7 = *(int *)(param_1 + 0xd70);
    }
  }
  if ((iVar7 == 0) && (*(int *)(param_1 + 0x2c) != 0)) {
    if (param_3 == 0) {
      local_34 = 0x14;
    }
    else {
      local_34 = 10;
    }
    if (local_34 <= *(uint *)(param_1 + 0xd78)) {
      yaffs2_FindOldestDirtySequence(param_1);
      if (*(int *)(param_1 + 0xe18) == 0) {
        *(undefined4 *)(param_1 + 0xd78) = 0;
      }
      else {
        iVar7 = *(int *)(param_1 + 0xe18);
        *(int *)(param_1 + 0xd70) = iVar7;
        *(int *)(param_1 + 0xe44) = *(int *)(param_1 + 0xe44) + 1;
        puVar6 = (uint *)FUN_30018fb8(param_1,iVar7);
        *(uint *)(param_1 + 0xd74) = ((*puVar6 << 0xc) >> 0x16) - (*puVar6 & 0x3ff);
      }
    }
  }
  if (iVar7 == 0) {
    *(int *)(param_1 + 0xd78) = *(int *)(param_1 + 0xd78) + 1;
    if ((*DAT_3001bdb4 & 0x40) != 0) {
      if (param_3 == 0) {
        local_38 = DAT_3001c9ac;
      }
      else {
        local_38 = DAT_3001c9a8;
      }
      printf(DAT_3001c9b0,*(undefined4 *)(param_1 + 0xd6c),*(undefined4 *)(param_1 + 0xd78),local_48
             ,*(undefined4 *)(param_1 + 0xd70),*(undefined4 *)(param_1 + 0xd74),
             *(undefined4 *)(param_1 + 0xe18),local_38);
    }
  }
  else {
    if ((*DAT_3001bdb4 & 0x40) != 0) {
      printf(DAT_3001c9a4,iVar7,*(int *)(param_1 + 0xc) - *(int *)(param_1 + 0xd74),uVar5);
    }
    *(int *)(param_1 + 0xe48) = *(int *)(param_1 + 0xe48) + 1;
    if (param_3 != 0) {
      *(int *)(param_1 + 0xe4c) = *(int *)(param_1 + 0xe4c) + 1;
    }
    *(undefined4 *)(param_1 + 0xd70) = 0;
    *(undefined4 *)(param_1 + 0xd74) = 0;
    *(undefined4 *)(param_1 + 0xd78) = 0;
    if (0 < *(int *)(param_1 + 0xe1c)) {
      *(int *)(param_1 + 0xe1c) = *(int *)(param_1 + 0xe1c) + -1;
    }
  }
  return iVar7;
}

/* ----------------------------------------------------------------
 * FUN_3001bb54 @ 0x3001BB54  (примерный размер ~644 байт)
 * Модуль: flash | Вызывают: 4 | Вызывает: 5
 * Вызывает: FUN_3001b01c, FUN_3001b670, printf, yaffs2_CalcCheckpointBlocksRequired, yaffs2_FindRefreshBlock
 * Вызывают: FUN_3001d45c, yaffs_BackgroundGarbageCollect, yaffs_ResizeFile, yaffs_UpdateObjectHeader
 * Константы: 0x3001BB54
 * Данные: DAT_3001bdb4, DAT_3001cc60, DAT_3001cc64
 * ---------------------------------------------------------------- */
undefined4 FUN_3001bb54(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar7 = 0;
  uVar6 = 1;
  iVar5 = 0;
  if (((*(int *)(param_1 + 0x6c) != 0) &&
      (uVar1 = (**(code **)(param_1 + 0x6c))(param_1), (uVar1 & 1) == 0)) ||
     (*(int *)(param_1 + 0xd68) != 0)) {
    return 1;
  }
  do {
    iVar5 = iVar5 + 1;
    iVar2 = yaffs2_CalcCheckpointBlocksRequired(param_1);
    iVar4 = *(int *)(param_1 + 0xc) * *(int *)(param_1 + 0x134);
    if (*(int *)(param_1 + 0x134) < iVar2 + *(int *)(param_1 + 0x1c) + 1) {
      iVar7 = 1;
    }
    else {
      if ((param_2 == 0) &&
         ((int)(*(int *)(param_1 + 0xd58) + ((uint)(*(int *)(param_1 + 0xd58) >> 0x1f) >> 0x1e)) >>
          2 < iVar4)) goto LAB_3001bda4;
      if (0x14 < *(uint *)(param_1 + 0xd84)) {
        *(undefined4 *)(param_1 + 0xd84) = 0x14;
      }
      if (((*(int *)(param_1 + 0xd58) / 2 <= iVar4) && (*(int *)(param_1 + 0xd84) != 0)) &&
         (param_2 == 0)) {
        *(int *)(param_1 + 0xd84) = *(int *)(param_1 + 0xd84) + -1;
LAB_3001bda4:
        if (iVar7 == 0) {
          return 1;
        }
        return uVar6;
      }
      iVar7 = 0;
    }
    *(undefined4 *)(param_1 + 0xd84) = 5;
    if ((*(int *)(param_1 + 0xd7c) == 0) && (iVar7 == 0)) {
      uVar3 = yaffs2_FindRefreshBlock(param_1);
      *(undefined4 *)(param_1 + 0xd7c) = uVar3;
      *(undefined4 *)(param_1 + 0xd80) = 0;
      *(undefined4 *)(param_1 + 0xd60) = 0;
    }
    if (*(int *)(param_1 + 0xd7c) == 0) {
      uVar3 = FUN_3001b670(param_1,iVar7,param_2);
      *(undefined4 *)(param_1 + 0xd7c) = uVar3;
      *(undefined4 *)(param_1 + 0xd80) = 0;
      *(undefined4 *)(param_1 + 0xd60) = 0;
    }
    if (*(int *)(param_1 + 0xd7c) != 0) {
      *(int *)(param_1 + 0xe3c) = *(int *)(param_1 + 0xe3c) + 1;
      if (iVar7 == 0) {
        *(int *)(param_1 + 0xe40) = *(int *)(param_1 + 0xe40) + 1;
      }
      if ((*DAT_3001bdb4 & 0x40) != 0) {
        printf(DAT_3001cc60,*(undefined4 *)(param_1 + 0x134),iVar7);
      }
      uVar6 = FUN_3001b01c(param_1,*(undefined4 *)(param_1 + 0xd7c),iVar7);
    }
    if (((*(int *)(param_1 + 0x134) < *(int *)(param_1 + 0x1c)) && (*(int *)(param_1 + 0xd7c) != 0))
       && ((*DAT_3001bdb4 & 0x40) != 0)) {
      printf(DAT_3001cc64,*(undefined4 *)(param_1 + 0x134),iVar5,*(undefined4 *)(param_1 + 0xd7c));
    }
    if (((*(int *)(param_1 + 0x1c) <= *(int *)(param_1 + 0x134)) || (*(int *)(param_1 + 0xd7c) == 0)
        ) || (1 < iVar5)) goto LAB_3001bda4;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_3001bdd8 @ 0x3001BDD8  (примерный размер ~112 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_UpdateObjectHeader
 * Константы: 0x3001BDD8
 * ---------------------------------------------------------------- */
undefined4 FUN_3001bdd8(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (*(int *)(*(int *)(param_1 + 8) + 0x20) <= iVar2) {
      return 0;
    }
    piVar1 = (int *)(*(int *)(*(int *)(param_1 + 8) + 0xd98) + iVar2 * 0x1c);
    if ((*piVar1 == param_1) && (piVar1[3] != 0)) break;
    iVar2 = iVar2 + 1;
  }
  return 1;
}

/* ----------------------------------------------------------------
 * yaffs_CloneString @ 0x3001BE48  (примерный размер ~100 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 3
 * Вызывает: malloc, strncpy, ystrnlen
 * Вызывают: FUN_3001beac, FUN_3001e034, yaffs1_Scan, yaffs2_ScanBackwards, yaffs_GetSymlinkAlias
 * Константы: 0x3001BE48
 * Данные: DAT_3001c9ac
 * ---------------------------------------------------------------- */
char * yaffs_CloneString(char *param_1)

{
  size_t __n;
  char *__dest;
  
  if (param_1 == (char *)0x0) {
    param_1 = DAT_3001c9ac;
  }
  __n = ystrnlen(param_1,0x9f);
  __dest = (char *)malloc(__n + 1);
  if (__dest != (char *)0x0) {
    strncpy(__dest,param_1,__n);
    __dest[__n] = '\0';
  }
  return __dest;
}

/* ----------------------------------------------------------------
 * FUN_3001beac @ 0x3001BEAC  (примерный размер ~260 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 5
 * Вызывает: yaffs_CloneString, yaffs_GetTempBuffer, yaffs_ReadChunkWithTagsFromNAND, yaffs_ReleaseTempBuffer, yaffs_SetObjectNameFromOH
 * Вызывают: yaffs_FindObjectByName, yaffs_GetEquivalentObject, yaffs_GetObjectName, yaffs_GutsInitialise, yaffs_UpdateObjectHeader
 * Константы: 0x3001BEAC
 * Данные: DAT_3001cd78, DAT_3001ce74
 * ---------------------------------------------------------------- */
void FUN_3001beac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_64 [72];
  
  if (((param_1 != 0) && (uVar3 = *(undefined4 *)(param_1 + 8), (*(byte *)(param_1 + 1) & 1) != 0))
     && (0 < *(int *)(param_1 + 0x28))) {
    *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfe;
    iVar1 = yaffs_GetTempBuffer(uVar3,DAT_3001cd78);
    yaffs_ReadChunkWithTagsFromNAND(uVar3,*(undefined4 *)(param_1 + 0x28),iVar1,auStack_64);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(iVar1 + 0x10c);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(iVar1 + 0x110);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(iVar1 + 0x114);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(iVar1 + 0x118);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(iVar1 + 0x11c);
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(iVar1 + 0x120);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(iVar1 + 0x1cc);
    yaffs_SetObjectNameFromOH(param_1,iVar1);
    if (*(int *)(param_1 + 100) == 2) {
      uVar2 = yaffs_CloneString(iVar1 + 300);
      *(undefined4 *)(param_1 + 0x68) = uVar2;
    }
    yaffs_ReleaseTempBuffer(uVar3,iVar1,DAT_3001ce74);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001bfb0 @ 0x3001BFB0  (примерный размер ~208 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: nval_del, nval_hasvalues, nval_set
 * Вызывают: yaffs_UpdateObjectHeader
 * Константы: 0x3001BFB0
 * ---------------------------------------------------------------- */
int FUN_3001bfb0(int param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x9c) + -0x200;
  param_2 = param_2 + 0x200;
  if (*param_3 == 0) {
    iVar1 = nval_del(param_2,iVar3,param_3[1]);
  }
  else {
    iVar1 = nval_set(param_2,iVar3,param_3[1],param_3[2],param_3[3],param_3[4]);
  }
  uVar2 = nval_hasvalues(param_2,iVar3);
  *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xdf | (byte)((uVar2 & 1) << 5) | 0x10;
  param_3[5] = iVar1;
  return iVar1;
}

/* ----------------------------------------------------------------
 * yaffs_UpdateObjectHeader @ 0x3001C080  (примерный размер ~1180 байт)
 * Модуль: flash | Вызывают: 10 | Вызывает: 19
 * Вызывает: FUN_30018fb8, FUN_3001a0fc, FUN_3001bb54, FUN_3001bdd8, FUN_3001beac, FUN_3001bfb0, FUN_30020c58, __div32, memcpy, memset, printf, strcpy, strncpy, yaffs_DeleteChunk
 *           ...
 * Вызывают: FUN_3001ca68, FUN_3001df80, FUN_3001e034, FUN_3001fd28, yaffs1_Scan, yaffs2_HandleHole, yaffs_FlushFile, yaffs_ResizeFile, yaffs_SetAttributes, yaffs_UpdateDirtyDirectories
 * Константы: 0x3001C080, 0x40000000
 * Данные: DAT_3001cfec, DAT_3001cff0, DAT_3001cff8, DAT_3001cffc, DAT_3001d228, DAT_3001d22c, DAT_3001d3bc, DAT_3001d3c0
 * ---------------------------------------------------------------- */
int yaffs_UpdateObjectHeader
              (byte *param_1,char *param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  undefined4 uVar1;
  uint *puVar2;
  undefined4 *__s;
  char *__src;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_1c0 [8];
  undefined4 local_1b8;
  undefined4 local_1b4;
  uint local_1a0;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  uint local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined1 auStack_178 [72];
  char acStack_130 [256];
  
  iVar4 = *(int *)(param_1 + 8);
  iVar5 = 0;
  __s = (undefined4 *)0x0;
  strcpy(acStack_130,DAT_3001cfec);
  if (((((*param_1 & 8) == 0) || (*(byte **)(iVar4 + 0xd88) == param_1)) || (param_3 != 0)) ||
     (param_6 != 0)) {
    FUN_3001bb54(iVar4,0);
    FUN_3001beac(param_1);
    __s = (undefined4 *)yaffs_GetTempBuffer(*(undefined4 *)(param_1 + 8),DAT_3001cff0);
    iVar3 = *(int *)(param_1 + 0x28);
    if (iVar3 < 1) {
      memset(__s,0xff,*(size_t *)(iVar4 + 0x9c));
    }
    else {
      iVar5 = yaffs_ReadChunkWithTagsFromNAND(iVar4,iVar3,__s,auStack_178);
      if (iVar5 == 0) {
        printf(DAT_3001cff8,DAT_3001cffc);
        return -1;
      }
      yaffs_VerifyObjectHeader(param_1,__s,auStack_178,0);
      memcpy(acStack_130,(void *)((int)__s + 10),0x100);
      memset(__s,0xff,0x200);
    }
    *__s = *(undefined4 *)(param_1 + 100);
    __s[0x43] = *(undefined4 *)(param_1 + 0x34);
    __s[0x7a] = param_5;
    __s[0x7e] = __s[0x7a];
    __s[0x44] = *(undefined4 *)(param_1 + 0x4c);
    __s[0x45] = *(undefined4 *)(param_1 + 0x50);
    __s[0x46] = *(undefined4 *)(param_1 + 0x54);
    __s[0x47] = *(undefined4 *)(param_1 + 0x58);
    __s[0x48] = *(undefined4 *)(param_1 + 0x5c);
    __s[0x73] = *(undefined4 *)(param_1 + 0x60);
    if (*(int *)(param_1 + 0x1c) == 0) {
      __s[1] = 0;
    }
    else {
      __s[1] = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x30);
    }
    if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
      if (iVar3 < 1) {
        memset((void *)((int)__s + 10),0,0x100);
      }
      else {
        memcpy((void *)((int)__s + 10),acStack_130,0x100);
      }
    }
    else {
      memset((void *)((int)__s + 10),0,0x100);
      FUN_30020c58(iVar4,(int)__s + 10,param_2);
    }
    __s[0x7f] = param_4;
    iVar5 = *(int *)(param_1 + 100);
    if (iVar5 == 1) {
      if ((__s[1] == 4) || (__s[1] == 3)) {
        __s[0x49] = 0;
      }
      else {
        __s[0x49] = *(undefined4 *)(param_1 + 0x68);
      }
    }
    else if (iVar5 == 2) {
      __src = *(char **)(param_1 + 0x68);
      if (*(char **)(param_1 + 0x68) == (char *)0x0) {
        __src = DAT_3001d228;
      }
      strncpy((char *)(__s + 0x4b),__src,0x9f);
      *(undefined1 *)((int)__s + DAT_3001d22c) = 0;
    }
    else if (iVar5 == 4) {
      __s[0x4a] = *(undefined4 *)(param_1 + 0x6c);
    }
    if (param_6 != 0) {
      FUN_3001bfb0(param_1,__s,param_6);
    }
    yaffs_InitialiseTags(auStack_1c0);
    param_1[2] = param_1[2] + 1;
    local_1b4 = 0;
    local_1b8 = *(undefined4 *)(param_1 + 0x30);
    local_1a0 = (uint)param_1[2];
    local_198 = 1;
    local_194 = __s[1];
    local_184 = __s[0x49];
    local_190 = __s[0x7f];
    local_180 = __s[0x4a];
    local_18c = (uint)(0 < (int)__s[0x7e]);
    local_188 = *(undefined4 *)(param_1 + 100);
    yaffs_VerifyObjectHeader(param_1,__s,auStack_1c0,1);
    iVar5 = FUN_3001a0fc(iVar4,__s,auStack_1c0,0 < iVar3);
    if (-1 < iVar5) {
      *(int *)(param_1 + 0x28) = iVar5;
      if (0 < iVar3) {
        yaffs_DeleteChunk(iVar4,iVar3,1,DAT_3001d3bc);
      }
      iVar3 = FUN_3001bdd8(param_1);
      if (iVar3 == 0) {
        *param_1 = *param_1 & 0xbf;
      }
      if (param_4 != 0) {
        uVar1 = __div32(iVar5,*(undefined4 *)(*(int *)(param_1 + 8) + 0xc));
        puVar2 = (uint *)FUN_30018fb8(*(undefined4 *)(param_1 + 8),uVar1);
        *puVar2 = *puVar2 | 0x40000000;
      }
    }
  }
  if (__s != (undefined4 *)0x0) {
    yaffs_ReleaseTempBuffer(iVar4,__s,DAT_3001d3c0);
  }
  return iVar5;
}

/* ----------------------------------------------------------------
 * FUN_3001c51c @ 0x3001C51C  (примерный размер ~112 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_30018f98, yaffs_VerifyDirectory, yaffs_VerifyObjectInDirectory
 * Вызывают: FUN_3001cc70, yaffs_AddObjectToDirectory
 * Константы: 0x3001C51C
 * ---------------------------------------------------------------- */
void FUN_3001c51c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  yaffs_VerifyObjectInDirectory(param_1);
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  yaffs_VerifyDirectory(uVar1);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 100) != 0)) {
    (**(code **)(iVar2 + 100))(param_1);
  }
  FUN_30018f98(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  yaffs_VerifyDirectory(uVar1);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_AddObjectToDirectory @ 0x3001C58C  (примерный размер ~348 байт)
 * Модуль: flash | Вызывают: 10 | Вызывает: 5
 * Вызывает: FUN_30018f50, FUN_3001c51c, printf, yaffs_VerifyDirectory, yaffs_VerifyObjectInDirectory
 * Вызывают: FUN_3001ca68, FUN_3001cf58, FUN_3001e034, FUN_3001e3e4, FUN_3001f760, FUN_300200d4, FUN_30029838, yaffs1_Scan, yaffs2_ScanBackwards, yaffs_HandleShadowedObject
 * Константы: 0x3001C58C
 * Данные: DAT_3001cff8, DAT_3001d4c8, DAT_3001d4cc, DAT_3001d4d0, DAT_3001d4d4, DAT_3001d4d8
 * ---------------------------------------------------------------- */
void yaffs_AddObjectToDirectory(int param_1,byte *param_2)

{
  if (param_1 == 0) {
    printf(DAT_3001d4c8);
    printf(DAT_3001cff8,DAT_3001d4cc);
  }
  else {
    if (*(int *)(param_1 + 100) != 3) {
      printf(DAT_3001d4d0);
      printf(DAT_3001cff8,DAT_3001d4d4);
    }
    if (*(int *)(param_2 + 0x24) == 0) {
      printf(DAT_3001cff8,DAT_3001d4d8);
    }
    yaffs_VerifyDirectory(param_1);
    FUN_3001c51c(param_2);
    FUN_30018f50(param_2 + 0x20,param_1 + 0x68);
    *(int *)(param_2 + 0x1c) = param_1;
    if ((*(int *)(*(int *)(param_2 + 8) + 0xda0) == param_1) ||
       (*(int *)(*(int *)(param_2 + 8) + 0xda4) == param_1)) {
      *param_2 = *param_2 | 4;
      *(int *)(*(int *)(param_2 + 8) + 0xdb0) = *(int *)(*(int *)(param_2 + 8) + 0xdb0) + 1;
      *param_2 = *param_2 & 0xef;
    }
    yaffs_VerifyDirectory(param_1);
    yaffs_VerifyObjectInDirectory(param_2);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001c6e8 @ 0x3001C6E8  (примерный размер ~184 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: strcat, strcpy, strncpy, ystrnlen
 * Вызывают: yaffs_GetObjectName
 * Константы: 0x3001C6E8
 * Данные: DAT_3001d5d4, DAT_3001d5d8
 * ---------------------------------------------------------------- */
void FUN_3001c6e8(int param_1,char *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  char *__src;
  char acStack_40 [38];
  char local_1a [2];
  
  iVar1 = ystrnlen(param_2,0xff);
  if (iVar1 == 0) {
    __src = local_1a + 1;
    uVar2 = *(uint *)(param_1 + 0x30);
    local_1a[1] = 0;
    for (; uVar2 != 0; uVar2 = (uint)((ulonglong)DAT_3001d5d4 * (ulonglong)uVar2 >> 0x23)) {
      __src = __src + -1;
      *__src = (char)uVar2 + (char)(uint)((ulonglong)DAT_3001d5d4 * (ulonglong)uVar2 >> 0x23) * -10
               + '0';
    }
    strcpy(acStack_40,DAT_3001d5d8);
    strcat(acStack_40,__src);
    strncpy(param_2,acStack_40,param_3 - 1);
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_GetObjectName @ 0x3001C7A0  (примерный размер ~264 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 10
 * Вызывает: FUN_3001beac, FUN_3001c6e8, FUN_30020c34, memset, strcpy, strncpy, yaffs_GetTempBuffer, yaffs_ReadChunkWithTagsFromNAND, yaffs_ReleaseTempBuffer, ystrnlen
 * Вызывают: FUN_3001e3e4, yaffs_FindObjectByName, yaffs_readdir
 * Константы: 0x3001C7A0
 * Данные: DAT_3001d698, DAT_3001d69c, DAT_3001d764
 * ---------------------------------------------------------------- */
void yaffs_GetObjectName(int param_1,char *param_2,size_t param_3)

{
  void *__s;
  
  memset(param_2,0,param_3);
  FUN_3001beac(param_1);
  if (*(int *)(param_1 + 0x30) == 2) {
    strncpy(param_2,DAT_3001d698,param_3 - 1);
  }
  else if (*(char *)(param_1 + 0x38) == '\0') {
    if (0 < *(int *)(param_1 + 0x28)) {
      __s = (void *)yaffs_GetTempBuffer(*(undefined4 *)(param_1 + 8),DAT_3001d69c);
      memset(__s,0,*(size_t *)(*(int *)(param_1 + 8) + 0x9c));
      if (0 < *(int *)(param_1 + 0x28)) {
        yaffs_ReadChunkWithTagsFromNAND
                  (*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x28),__s,0);
      }
      FUN_30020c34(*(undefined4 *)(param_1 + 8),param_2,(int)__s + 10,param_3);
      yaffs_ReleaseTempBuffer(*(undefined4 *)(param_1 + 8),__s,DAT_3001d764);
    }
  }
  else {
    strcpy(param_2,(char *)(param_1 + 0x38));
  }
  FUN_3001c6e8(param_1,param_2,param_3);
  ystrnlen(param_2,0xff);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_FindObjectByName @ 0x3001C8A8  (примерный размер ~448 байт)
 * Модуль: flash | Вызывают: 6 | Вызывает: 6
 * Вызывает: FUN_3001a2f4, FUN_3001beac, printf, strcmp, strncmp, yaffs_GetObjectName
 * Вызывают: FUN_3001ca68, FUN_3001e034, FUN_30024828, yaffs_RenameObject, yaffs_Unlink, yaffsfs_FindObject
 * Константы: 0x3001C8A8
 * Данные: DAT_3001cff8, DAT_3001d698, DAT_3001d768, DAT_3001d76c, DAT_3001d770, DAT_3001d874, DAT_3001d878
 * ---------------------------------------------------------------- */
int yaffs_FindObjectByName(int param_1,char *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char acStack_118 [256];
  
  if (param_2 != (char *)0x0) {
    if (param_1 == 0) {
      printf(DAT_3001d768);
      printf(DAT_3001cff8,DAT_3001d76c);
    }
    else {
      if (*(int *)(param_1 + 100) != 3) {
        printf(DAT_3001d770);
        printf(DAT_3001cff8,DAT_3001d874);
      }
      sVar1 = FUN_3001a2f4(param_2);
      for (piVar4 = *(int **)(param_1 + 0x68); (int *)(param_1 + 0x68) != piVar4;
          piVar4 = (int *)*piVar4) {
        if (piVar4 != (int *)0x0) {
          iVar3 = (int)(piVar4 + -8);
          if (piVar4[-1] != param_1) {
            printf(DAT_3001cff8,DAT_3001d878);
          }
          FUN_3001beac(iVar3);
          if (piVar4[4] == 2) {
            iVar2 = strcmp(param_2,DAT_3001d698);
          }
          else {
            if ((*(short *)(piVar4 + -7) != sVar1) && (0 < piVar4[2])) goto LAB_3001ca50;
            yaffs_GetObjectName(iVar3,acStack_118,0x100);
            iVar2 = strncmp(param_2,acStack_118,0xff);
          }
          if (iVar2 == 0) {
            return iVar3;
          }
        }
LAB_3001ca50:
      }
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3001ca68 @ 0x3001CA68  (примерный размер ~400 байт)
 * Модуль: flash | Вызывают: 4 | Вызывает: 5
 * Вызывает: printf, yaffs_AddObjectToDirectory, yaffs_FindObjectByName, yaffs_SetObjectName, yaffs_UpdateObjectHeader
 * Вызывают: FUN_3001cc70, FUN_3001dbc0, FUN_3001e3e4, yaffs_RenameObject
 * Константы: 0x3001CA68
 * Данные: DAT_3001cff8, DAT_3001d9d4, DAT_3001d9d8
 * ---------------------------------------------------------------- */
undefined4 FUN_3001ca68(byte *param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  if (param_2 == 0) {
    param_2 = *(int *)(param_1 + 0x1c);
  }
  if (*(int *)(param_2 + 100) != 3) {
    printf(DAT_3001d9d4);
    printf(DAT_3001cff8,DAT_3001d9d8);
  }
  if (*(int *)(*(int *)(param_1 + 8) + 0x2c) == 0) {
    if ((*(int *)(*(int *)(param_1 + 8) + 0xda0) == param_2) && (*(int *)(param_1 + 100) == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
  }
  else {
    bVar2 = *(int *)(*(int *)(param_1 + 8) + 0xda0) == param_2;
  }
  bVar3 = *(int *)(*(int *)(param_1 + 8) + 0xda4) == param_2;
  iVar1 = yaffs_FindObjectByName(param_2,param_3);
  if (((((bVar2) || (bVar3)) || (param_4 != 0)) || ((0 < param_5 || (iVar1 == 0)))) &&
     (*(int *)(param_2 + 100) == 3)) {
    yaffs_SetObjectName(param_1,param_3);
    *param_1 = *param_1 | 0x40;
    yaffs_AddObjectToDirectory(param_2,param_1);
    if (bVar2) {
      *param_1 = *param_1 | 4;
    }
    iVar1 = yaffs_UpdateObjectHeader(param_1,param_3,0,bVar3,param_5,0);
    if (-1 < iVar1) {
      return 1;
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3001cbf8 @ 0x3001CBF8  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_3001cc70, yaffs_ResizeFile
 * Константы: 0x3001CBF8
 * ---------------------------------------------------------------- */
void FUN_3001cbf8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  if (0 < *(int *)(iVar1 + 0x20)) {
    for (iVar2 = 0; iVar2 < *(int *)(iVar1 + 0x20); iVar2 = iVar2 + 1) {
      if (*(int *)(*(int *)(iVar1 + 0xd98) + iVar2 * 0x1c) == param_1) {
        *(undefined4 *)(*(int *)(iVar1 + 0xd98) + iVar2 * 0x1c) = 0;
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001cc70 @ 0x3001CC70  (примерный размер ~144 байт)
 * Модуль: flash | Вызывают: 7 | Вызывает: 5
 * Вызывает: FUN_3001ac00, FUN_3001c51c, FUN_3001ca68, FUN_3001cbf8, yaffs_DeleteChunk
 * Вызывают: FUN_3001b01c, FUN_3001cd00, FUN_3001ddf0, FUN_3001de1c, FUN_3001de4c, FUN_3001e3e4, yaffs_DeleteFile
 * Константы: 0x3001CC70
 * Данные: DAT_3001dbdc, DAT_3001dbe0
 * ---------------------------------------------------------------- */
undefined4 FUN_3001cc70(int param_1)

{
  FUN_3001cbf8(param_1);
  if ((*(int *)(*(int *)(param_1 + 8) + 0x2c) != 0) &&
     (*(int *)(param_1 + 0x1c) != *(int *)(*(int *)(param_1 + 8) + 0xda4))) {
    FUN_3001ca68(param_1,*(undefined4 *)(*(int *)(param_1 + 8) + 0xda4),DAT_3001dbdc,0,0);
  }
  FUN_3001c51c(param_1);
  yaffs_DeleteChunk(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x28),1,DAT_3001dbe0);
  *(undefined4 *)(param_1 + 0x28) = 0;
  FUN_3001ac00(param_1);
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3001cd00 @ 0x3001CD00  (примерный размер ~160 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_3001a414, FUN_3001aa7c, FUN_3001cc70, printf
 * Вызывают: FUN_3001dbc0, yaffs_DeleteFile
 * Константы: 0x3001CD00
 * Данные: DAT_3001dbe4
 * ---------------------------------------------------------------- */
void FUN_3001cd00(byte *param_1)

{
  if ((((*param_1 & 1) != 0) && (*(int *)(param_1 + 100) == 1)) && ((*param_1 & 2) == 0)) {
    if (*(int *)(param_1 + 0x2c) < 1) {
      FUN_3001a414(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x78));
      param_1[0x78] = 0;
      param_1[0x79] = 0;
      param_1[0x7a] = 0;
      param_1[0x7b] = 0;
      printf(DAT_3001dbe4,*(undefined4 *)(param_1 + 0x30));
      FUN_3001cc70(param_1);
    }
    else {
      FUN_3001aa7c(param_1,*(undefined4 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x74),0);
      *param_1 = *param_1 | 2;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001cda0 @ 0x3001CDA0  (примерный размер ~260 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3001a414
 * Вызывают: FUN_3001cea4
 * Константы: 0x3001CDA0
 * ---------------------------------------------------------------- */
int FUN_3001cda0(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 != 0) {
    uVar2 = 0;
    if (param_3 == 0) {
      for (iVar3 = 0; (uVar2 == 0 && (iVar3 < (int)(*(uint *)(param_1 + 0xb0) >> 2)));
          iVar3 = iVar3 + 1) {
        uVar2 = (uint)(*(int *)(param_2 + iVar3 * 4) != 0);
      }
    }
    else {
      for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
        if (*(int *)(param_2 + iVar3 * 4) != 0) {
          iVar4 = param_4;
          if (iVar3 != 0) {
            iVar4 = 1;
          }
          uVar1 = FUN_3001cda0(param_1,*(undefined4 *)(param_2 + iVar3 * 4),param_3 + -1,iVar4);
          *(undefined4 *)(param_2 + iVar3 * 4) = uVar1;
        }
        uVar2 = uVar2 + (*(int *)(param_2 + iVar3 * 4) != 0);
      }
    }
    if ((uVar2 == 0) && (param_4 != 0)) {
      FUN_3001a414(param_1,param_2);
      param_2 = 0;
    }
  }
  return param_2;
}

/* ----------------------------------------------------------------
 * FUN_3001cea4 @ 0x3001CEA4  (примерный размер ~180 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3001a414, FUN_3001cda0
 * Вызывают: yaffs_ResizeDown
 * Константы: 0x3001CEA4
 * ---------------------------------------------------------------- */
undefined4 FUN_3001cea4(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  bVar1 = false;
  if (0 < *(int *)(param_2 + 0xc)) {
    uVar2 = FUN_3001cda0(param_1,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0xc),0);
    *(undefined4 *)(param_2 + 0x10) = uVar2;
    while ((*(int *)(param_2 + 0xc) != 0 && (!bVar1))) {
      puVar3 = *(undefined4 **)(param_2 + 0x10);
      iVar4 = 0;
      for (iVar5 = 1; iVar5 < 8; iVar5 = iVar5 + 1) {
        iVar4 = iVar4 + (uint)(puVar3[iVar5] != 0);
      }
      if (iVar4 == 0) {
        *(undefined4 *)(param_2 + 0x10) = *puVar3;
        *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + -1;
        FUN_3001a414(param_1,puVar3);
      }
      else {
        bVar1 = true;
      }
    }
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3001cf58 @ 0x3001CF58  (примерный размер ~276 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_30018f50, memset, yaffs_AddObjectToDirectory, yaffs_AllocateRawObject
 * Вызывают: FUN_3001d1d8
 * Константы: 0x3001CF58
 * ---------------------------------------------------------------- */
void * FUN_3001cf58(int param_1)

{
  void *__s;
  
  __s = (void *)yaffs_AllocateRawObject(param_1);
  if (__s != (void *)0x0) {
    *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + 1;
    memset(__s,0,0x7c);
    *(byte *)((int)__s + 1) = *(byte *)((int)__s + 1) | 4;
    *(int *)((int)__s + 8) = param_1;
    *(undefined4 *)((int)__s + 0x28) = 0;
    *(undefined4 *)((int)__s + 100) = 0;
    *(int *)((int)__s + 0x14) = (int)__s + 0x14;
    *(int *)((int)__s + 0x18) = (int)__s + 0x14;
    *(int *)((int)__s + 0xc) = (int)__s + 0xc;
    *(int *)((int)__s + 0x10) = (int)__s + 0xc;
    *(int *)((int)__s + 0x20) = (int)__s + 0x20;
    *(int *)((int)__s + 0x24) = (int)__s + 0x20;
    if (*(int *)(param_1 + 0xd88) != 0) {
      *(undefined4 *)((int)__s + 0x1c) = *(undefined4 *)(param_1 + 0xd88);
      FUN_30018f50((int)__s + 0x20,*(int *)(param_1 + 0xd88) + 0x68);
    }
    if (*(int *)(param_1 + 0xd8c) != 0) {
      yaffs_AddObjectToDirectory(*(undefined4 *)(param_1 + 0xd8c),__s);
    }
    *(byte *)((int)__s + 1) = *(byte *)((int)__s + 1) & 0xfb;
  }
  *(undefined4 *)(param_1 + 0x120) = 0;
  return __s;
}

/* ----------------------------------------------------------------
 * FUN_3001d06c @ 0x3001D06C  (примерный размер ~132 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3001d0f0
 * Константы: 0x3001D06C
 * Данные: DAT_3001de8c, DAT_3001de90
 * ---------------------------------------------------------------- */
undefined4 FUN_3001d06c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = DAT_3001de90;
  uVar2 = DAT_3001de8c;
  while ((iVar3 < 10 && (4 < iVar1))) {
    *(uint *)(param_1 + 0xd54) = *(int *)(param_1 + 0xd54) + 1U & 0xff;
    if (*(int *)(*(int *)(param_1 + 0xd54) * 0xc + param_1 + 0x15c) < iVar1) {
      iVar1 = *(int *)(*(int *)(param_1 + 0xd54) * 0xc + param_1 + 0x15c);
      uVar2 = *(undefined4 *)(param_1 + 0xd54);
    }
    iVar3 = iVar3 + 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3001d0f0 @ 0x3001D0F0  (примерный размер ~140 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3001d06c
 * Вызывают: FUN_3001d1d8
 * Константы: 0x3001D0F0
 * ---------------------------------------------------------------- */
int FUN_3001d0f0(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = FUN_3001d06c(param_1);
  bVar1 = false;
  iVar3 = iVar2;
  while (!bVar1) {
    bVar1 = true;
    iVar3 = iVar3 + 0x100;
    for (piVar4 = *(int **)(param_1 + iVar2 * 0xc + 0x154);
        (int *)(param_1 + iVar2 * 0xc + 0x154) != piVar4; piVar4 = (int *)*piVar4) {
      if ((piVar4 != (int *)0x0) && (piVar4[9] == iVar3)) {
        bVar1 = false;
      }
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_3001d17c @ 0x3001D17C  (примерный размер ~92 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30018f50, FUN_30019514
 * Вызывают: FUN_3001d1d8
 * Константы: 0x3001D17C
 * ---------------------------------------------------------------- */
void FUN_3001d17c(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = FUN_30019514(*(undefined4 *)(param_1 + 0x30));
  iVar2 = *(int *)(param_1 + 8);
  FUN_30018f50(param_1 + 0xc,iVar2 + iVar1 * 0xc + 0x154);
  piVar3 = (int *)(iVar2 + iVar1 * 0xc + 0x15c);
  *piVar3 = *piVar3 + 1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001d1d8 @ 0x3001D1D8  (примерный размер ~320 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 5
 * Вызывает: FUN_3001a414, FUN_3001cf58, FUN_3001d0f0, FUN_3001d17c, yaffs_GetTnode
 * Вызывают: FUN_3001d318, FUN_3001e034, yaffs_FindOrCreateObjectByNumber
 * Константы: 0x3001D1D8
 * Данные: DAT_3001de94
 * ---------------------------------------------------------------- */
byte * FUN_3001d1d8(undefined4 param_1,int param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 < 0) {
    param_2 = FUN_3001d0f0(param_1);
  }
  if ((param_3 == 1) && (iVar2 = yaffs_GetTnode(param_1), iVar2 == 0)) {
    pbVar1 = (byte *)0x0;
  }
  else {
    pbVar1 = (byte *)FUN_3001cf58(param_1);
    if (pbVar1 == (byte *)0x0) {
      if (iVar2 != 0) {
        FUN_3001a414(param_1,iVar2);
      }
      pbVar1 = (byte *)0x0;
    }
    else if (pbVar1 != (byte *)0x0) {
      *pbVar1 = *pbVar1 & 0xe7 | 0x30;
      *(int *)(pbVar1 + 0x30) = param_2;
      FUN_3001d17c(pbVar1);
      *(int *)(pbVar1 + 100) = param_3;
      *(undefined4 *)(pbVar1 + 0x5c) = DAT_3001de94;
      *(undefined4 *)(pbVar1 + 0x58) = DAT_3001de94;
      *(undefined4 *)(pbVar1 + 0x54) = DAT_3001de94;
      if (param_3 == 1) {
        pbVar1[0x68] = 0;
        pbVar1[0x69] = 0;
        pbVar1[0x6a] = 0;
        pbVar1[0x6b] = 0;
        pbVar1[0x6c] = 0;
        pbVar1[0x6d] = 0;
        pbVar1[0x6e] = 0;
        pbVar1[0x6f] = 0;
        pbVar1[0x70] = 0xff;
        pbVar1[0x71] = 0xff;
        pbVar1[0x72] = 0xff;
        pbVar1[0x73] = 0xff;
        pbVar1[0x74] = 0;
        pbVar1[0x75] = 0;
        pbVar1[0x76] = 0;
        pbVar1[0x77] = 0;
        *(int *)(pbVar1 + 0x78) = iVar2;
      }
      else if (param_3 == 3) {
        *(byte **)(pbVar1 + 0x68) = pbVar1 + 0x68;
        *(byte **)(pbVar1 + 0x6c) = pbVar1 + 0x68;
        *(byte **)(pbVar1 + 0x70) = pbVar1 + 0x70;
        *(byte **)(pbVar1 + 0x74) = pbVar1 + 0x70;
      }
    }
  }
  return pbVar1;
}

/* ----------------------------------------------------------------
 * FUN_3001d318 @ 0x3001D318  (примерный размер ~84 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3001d1d8
 * Вызывают: FUN_300200d4
 * Константы: 0x3001D318
 * ---------------------------------------------------------------- */
byte * FUN_3001d318(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)FUN_3001d1d8(param_1,param_2,3);
  if (pbVar1 != (byte *)0x0) {
    *pbVar1 = *pbVar1 & 0xca | 8;
    *(undefined4 *)(pbVar1 + 0x34) = param_3;
    *(undefined4 *)(pbVar1 + 8) = param_1;
    pbVar1[0x28] = 0;
    pbVar1[0x29] = 0;
    pbVar1[0x2a] = 0;
    pbVar1[0x2b] = 0;
  }
  return pbVar1;
}

/* ----------------------------------------------------------------
 * FUN_3001d36c @ 0x3001D36C  (примерный размер ~160 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: yaffs_InitialiseRawTnodesAndObjects
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x3001D36C
 * ---------------------------------------------------------------- */
void FUN_3001d36c(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  yaffs_InitialiseRawTnodesAndObjects(param_1);
  for (iVar1 = 0; iVar1 < 0x100; iVar1 = iVar1 + 1) {
    *(int *)(param_1 + iVar1 * 0xc + 0x154) = param_1 + iVar1 * 0xc + 0x154;
    *(int *)(param_1 + iVar1 * 0xc + 0x158) = param_1 + iVar1 * 0xc + 0x154;
    *(undefined4 *)(param_1 + iVar1 * 0xc + 0x15c) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_FindOrCreateObjectByNumber @ 0x3001D40C  (примерный размер ~80 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 2
 * Вызывает: FUN_3001d1d8, yaffs_FindObjectByNumber
 * Вызывают: FUN_30029838, FUN_30029dd4, yaffs1_Scan, yaffs2_ScanBackwards, yaffs_HandleShadowedObject
 * Константы: 0x3001D40C
 * ---------------------------------------------------------------- */
int yaffs_FindOrCreateObjectByNumber(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_2) {
    iVar1 = yaffs_FindObjectByNumber(param_1,param_2);
  }
  if (iVar1 == 0) {
    iVar1 = FUN_3001d1d8(param_1,param_2,param_3);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3001d45c @ 0x3001D45C  (примерный размер ~384 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 8
 * Вызывает: FUN_3001a0fc, FUN_3001bb54, printf, yaffs_DeleteChunk, yaffs_FindChunkInFile, yaffs_InitialiseTags, yaffs_PutChunkIntoFile, yaffs_VerifyFileSanity
 * Вызывают: FUN_3001d5dc, yaffs_DoWriteDataToFile, yaffs_ResizeDown
 * Константы: 0x3001D45C
 * Данные: DAT_3001de9c, DAT_3001dea0, DAT_3001dea4, DAT_3001dea8
 * ---------------------------------------------------------------- */
int FUN_3001d45c(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_b0 [8];
  undefined4 local_a8;
  undefined4 local_a4;
  uint local_a0;
  int local_90;
  undefined1 auStack_68 [32];
  int local_48;
  
  iVar3 = *(int *)(param_1 + 8);
  FUN_3001bb54(iVar3,0);
  iVar1 = yaffs_FindChunkInFile(param_1,param_2,auStack_68);
  if ((iVar1 < 1) && (iVar2 = yaffs_PutChunkIntoFile(param_1,param_2,0,0), iVar2 == 0)) {
    iVar2 = 0;
  }
  else {
    yaffs_InitialiseTags(auStack_b0);
    local_a8 = *(undefined4 *)(param_1 + 0x30);
    if (iVar1 < 1) {
      local_90 = 1;
    }
    else {
      local_90 = local_48 + 1;
    }
    local_a4 = param_2;
    local_a0 = param_4;
    if (((int)param_4 < 1) || (*(uint *)(iVar3 + 8) < param_4)) {
      printf(DAT_3001de9c,param_4);
      printf(DAT_3001dea0,DAT_3001dea4);
    }
    iVar2 = FUN_3001a0fc(iVar3,param_3,auStack_b0,param_5);
    if (0 < iVar2) {
      yaffs_PutChunkIntoFile(param_1,param_2,iVar2,0);
      if (0 < iVar1) {
        yaffs_DeleteChunk(iVar3,iVar1,1,DAT_3001dea8);
      }
      yaffs_VerifyFileSanity(param_1);
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_3001d5dc @ 0x3001D5DC  (примерный размер ~324 байт)
 * Модуль: flash | Вызывают: 4 | Вызывает: 2
 * Вызывает: FUN_3001d45c, printf
 * Вызывают: FUN_3001ea98, yaffs_FlushEntireDeviceCache, yaffs_FlushFile, yaffs_ResizeFile
 * Константы: 0x3001D5DC
 * Данные: DAT_3001deac
 * ---------------------------------------------------------------- */
void FUN_3001d5dc(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 8);
  iVar5 = -99;
  iVar2 = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x20);
  if (0 < iVar1) {
    do {
      puVar3 = (undefined4 *)0x0;
      for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
        if (((*(int *)(*(int *)(iVar6 + 0xd98) + iVar4 * 0x1c) == param_1) &&
            (*(int *)(*(int *)(iVar6 + 0xd98) + iVar4 * 0x1c + 0xc) != 0)) &&
           ((puVar3 == (undefined4 *)0x0 ||
            (*(int *)(*(int *)(iVar6 + 0xd98) + iVar4 * 0x1c + 4) < iVar5)))) {
          puVar3 = (undefined4 *)(*(int *)(iVar6 + 0xd98) + iVar4 * 0x1c);
          iVar5 = puVar3[1];
        }
      }
      if ((puVar3 != (undefined4 *)0x0) && (puVar3[5] == 0)) {
        iVar2 = FUN_3001d45c(*puVar3,puVar3[1],puVar3[6],puVar3[4],1);
        puVar3[3] = 0;
        *puVar3 = 0;
      }
    } while ((puVar3 != (undefined4 *)0x0) && (0 < iVar2));
    if (puVar3 != (undefined4 *)0x0) {
      printf(DAT_3001deac);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001d720 @ 0x3001D720  (примерный размер ~140 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 4
 * Вызывает: memset, printf, yaffs_FindChunkInFile, yaffs_ReadChunkWithTagsFromNAND
 * Вызывают: yaffs_DoWriteDataToFile, yaffs_ReadDataFromFile, yaffs_ResizeDown
 * Константы: 0x3001D720
 * Данные: DAT_3001de98, DAT_3001deb0
 * ---------------------------------------------------------------- */
undefined4 FUN_3001d720(int param_1,undefined4 param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = yaffs_FindChunkInFile(param_1,param_2,0);
  if (iVar1 < 0) {
    if ((*DAT_3001de98 & 0x800) != 0) {
      printf(DAT_3001deb0,iVar1);
    }
    memset(param_3,0,*(size_t *)(*(int *)(param_1 + 8) + 0x9c));
    uVar2 = 0;
  }
  else {
    uVar2 = yaffs_ReadChunkWithTagsFromNAND(*(undefined4 *)(param_1 + 8),iVar1,param_3,0);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3001d7ac @ 0x3001D7AC  (примерный размер ~168 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_3001a908, yaffs_FindLevel0Tnode, yaffs_GetChunkGroupBase, yaffs_LoadLevel0Tnode
 * Вызывают: FUN_3001d854
 * Константы: 0x3001D7AC
 * ---------------------------------------------------------------- */
int FUN_3001d7ac(int param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_68 [72];
  
  uVar4 = *(undefined4 *)(param_1 + 8);
  iVar3 = -1;
  if (param_3 == (undefined1 *)0x0) {
    param_3 = auStack_68;
  }
  iVar1 = yaffs_FindLevel0Tnode(uVar4,param_1 + 0x68,param_2);
  if (iVar1 != 0) {
    uVar2 = yaffs_GetChunkGroupBase(uVar4,iVar1,param_2);
    iVar3 = FUN_3001a908(uVar4,uVar2,param_3,*(undefined4 *)(param_1 + 0x30),param_2);
    if (iVar3 != -1) {
      yaffs_LoadLevel0Tnode(uVar4,iVar1,param_2,0);
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_3001d854 @ 0x3001D854  (примерный размер ~264 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_3001d7ac, __div32, printf, yaffs_DeleteChunk
 * Вызывают: yaffs_ResizeDown
 * Константы: 0x3001D854
 * Данные: DAT_3001deb4
 * ---------------------------------------------------------------- */
void FUN_3001d854(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 8);
  iVar1 = __div32(*(int *)(param_1 + 0x68) + -1,*(undefined4 *)(iVar4 + 0x9c));
  iVar2 = __div32(param_2 + *(int *)(iVar4 + 0x9c) + -1,*(undefined4 *)(iVar4 + 0x9c));
  for (iVar1 = iVar1 + 1; iVar2 + 1 <= iVar1; iVar1 = iVar1 + -1) {
    iVar3 = FUN_3001d7ac(param_1,iVar1,0);
    if (0 < iVar3) {
      iVar5 = *(int *)(iVar4 + 0xc) * *(int *)(iVar4 + 0xdc);
      if ((iVar5 - iVar3 == 0 || iVar5 < iVar3) &&
         (iVar5 = *(int *)(iVar4 + 0xc) * (*(int *)(iVar4 + 0xe0) + 1),
         iVar5 - iVar3 != 0 && iVar3 <= iVar5)) {
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -1;
        yaffs_DeleteChunk(iVar4,iVar3,1,0xec0);
      }
      else {
        printf(DAT_3001deb4,iVar3,iVar1);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_ResizeDown @ 0x3001D95C  (примерный размер ~268 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 8
 * Вызывает: FUN_3001cea4, FUN_3001d45c, FUN_3001d720, FUN_3001d854, memset, yaffs_AddrToChunk, yaffs_GetTempBuffer, yaffs_ReleaseTempBuffer
 * Вызывают: yaffs2_HandleHole, yaffs_ResizeFile
 * Константы: 0x3001D95C
 * Данные: DAT_3001deb8, DAT_3001debc
 * ---------------------------------------------------------------- */
void yaffs_ResizeDown(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int local_30;
  int local_2c [2];
  undefined4 local_24;
  undefined4 local_20;
  
  iVar2 = *(int *)(param_1 + 8);
  local_24 = param_2;
  local_20 = param_3;
  yaffs_AddrToChunk(iVar2,param_2,param_3,local_2c,&local_30);
  FUN_3001d854(param_1,param_2);
  if (local_30 != 0) {
    iVar1 = yaffs_GetTempBuffer(iVar2,DAT_3001deb8);
    FUN_3001d720(param_1,local_2c[0] + 1,iVar1);
    memset((void *)(iVar1 + local_30),0,*(int *)(iVar2 + 0x9c) - local_30);
    FUN_3001d45c(param_1,local_2c[0] + 1,iVar1,local_30,1);
    yaffs_ReleaseTempBuffer(iVar2,iVar1,DAT_3001debc);
  }
  *(undefined4 *)(param_1 + 0x68) = param_2;
  FUN_3001cea4(iVar2,param_1 + 0x68);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_ResizeFile @ 0x3001DA68  (примерный размер ~344 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 6
 * Вызывает: FUN_3001bb54, FUN_3001cbf8, FUN_3001d5dc, yaffs2_HandleHole, yaffs_ResizeDown, yaffs_UpdateObjectHeader
 * Вызывают: FUN_3001dbc0, yaffs_DeleteFile, yaffs_SetAttributes, yaffs_open, yaffs_truncate
 * Константы: 0x3001DA68
 * ---------------------------------------------------------------- */
undefined4 yaffs_ResizeFile(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  bool bVar4;
  
  uVar3 = *(undefined4 *)(param_1 + 8);
  uVar2 = *(uint *)(param_1 + 0x68);
  FUN_3001d5dc(param_1);
  FUN_3001cbf8(param_1);
  FUN_3001bb54(uVar3,0);
  if (*(int *)(param_1 + 100) != 1) {
    return 0;
  }
  uVar1 = (int)uVar2 >> 0x1f;
  if (uVar1 == param_3 && uVar2 == param_2) {
    return 1;
  }
  bVar4 = param_3 <= uVar1;
  if (uVar1 == param_3) {
LAB_3001dafc:
    if (uVar1 == param_3) {
      bVar4 = param_2 <= uVar2;
    }
    if (bVar4) {
LAB_3001db30:
      yaffs_ResizeDown(param_1,param_2,param_3);
      goto LAB_3001db50;
    }
  }
  else if ((int)param_3 <= (int)uVar1) {
    if ((int)uVar1 < (int)param_3) goto LAB_3001dafc;
    goto LAB_3001db30;
  }
  yaffs2_HandleHole(param_1,param_2,param_3);
  *(uint *)(param_1 + 0x68) = param_2;
LAB_3001db50:
  if ((((*(int *)(param_1 + 0x1c) != 0) && ((*(byte *)(param_1 + 1) & 8) == 0)) &&
      (*(int *)(*(int *)(param_1 + 0x1c) + 0x30) != 3)) &&
     (*(int *)(*(int *)(param_1 + 0x1c) + 0x30) != 4)) {
    yaffs_UpdateObjectHeader(param_1,0,0,0,0,0);
  }
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3001dbc0 @ 0x3001DBC0  (примерный размер ~264 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_3001ca68, FUN_3001cd00, printf, yaffs_ResizeFile
 * Вызывают: yaffs_DeleteFile
 * Константы: 0x3001DBC0
 * Данные: DAT_3001dec0, DAT_3001dec4, DAT_3001dec8, DAT_3001decc
 * ---------------------------------------------------------------- */
undefined4 FUN_3001dbc0(byte *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 0x48) == 0) {
    uVar1 = FUN_3001ca68(param_1,*(undefined4 *)(*(int *)(param_1 + 8) + 0xda4),DAT_3001dec0,0,0);
    printf(DAT_3001dec4,*(undefined4 *)(param_1 + 0x30));
    *param_1 = *param_1 | 1;
    *(int *)(*(int *)(param_1 + 8) + DAT_3001dec8) =
         *(int *)(*(int *)(param_1 + 8) + DAT_3001dec8) + 1;
    if ((*(int *)(iVar2 + 0x7c) != 0) || (*(int *)(iVar2 + 0x2c) != 0)) {
      yaffs_ResizeFile(param_1,0,0);
    }
    FUN_3001cd00(param_1);
  }
  else {
    uVar1 = FUN_3001ca68(param_1,*(undefined4 *)(*(int *)(param_1 + 8) + 0xda0),DAT_3001decc,0,0);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_DeleteFile @ 0x3001DCC8  (примерный размер ~236 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 5
 * Вызывает: FUN_3001a414, FUN_3001cc70, FUN_3001cd00, FUN_3001dbc0, yaffs_ResizeFile
 * Вызывают: FUN_3001e3e4, yaffs_close
 * Константы: 0x3001DCC8
 * Данные: DAT_3001dec8
 * ---------------------------------------------------------------- */
bool yaffs_DeleteFile(byte *param_1)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = 1;
  if ((*(int *)(*(int *)(param_1 + 8) + 0x7c) != 0) || (*(int *)(*(int *)(param_1 + 8) + 0x2c) != 0)
     ) {
    yaffs_ResizeFile(param_1,0,0);
  }
  if (*(int *)(param_1 + 0x2c) < 1) {
    FUN_3001a414(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x78));
    param_1[0x78] = 0;
    param_1[0x79] = 0;
    param_1[0x7a] = 0;
    param_1[0x7b] = 0;
    FUN_3001cc70(param_1);
    bVar3 = true;
  }
  else {
    if ((*param_1 & 4) == 0) {
      iVar2 = FUN_3001dbc0(param_1);
    }
    bVar1 = *param_1 & 1;
    if ((iVar2 == 1) && ((*param_1 & 5) == 4)) {
      *param_1 = *param_1 | 1;
      bVar1 = 1;
      *(int *)(*(int *)(param_1 + 8) + DAT_3001dec8) =
           *(int *)(*(int *)(param_1 + 8) + DAT_3001dec8) + 1;
      FUN_3001cd00(param_1);
    }
    bVar3 = bVar1 != 0;
  }
  return bVar3;
}

/* ----------------------------------------------------------------
 * FUN_3001ddb4 @ 0x3001DDB4  (примерный размер ~60 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_30020c7c
 * Вызывают: FUN_3001ddf0, FUN_3001e3e4
 * Константы: 0x3001DDB4
 * ---------------------------------------------------------------- */
undefined4 FUN_3001ddb4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 100) == 3) && (iVar1 = FUN_30020c7c(param_1 + 0x68), iVar1 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3001ddf0 @ 0x3001DDF0  (примерный размер ~44 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3001cc70, FUN_3001ddb4
 * Вызывают: FUN_3001e3e4
 * Константы: 0x3001DDF0
 * ---------------------------------------------------------------- */
undefined4 FUN_3001ddf0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_3001ddb4(param_1);
  if (iVar1 == 0) {
    uVar2 = FUN_3001cc70(param_1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3001de1c @ 0x3001DE1C  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3001cc70, free
 * Вызывают: FUN_3001e3e4
 * Константы: 0x3001DE1C
 * ---------------------------------------------------------------- */
void FUN_3001de1c(int param_1)

{
  if (*(int *)(param_1 + 0x68) != 0) {
    free(*(void **)(param_1 + 0x68));
  }
  *(undefined4 *)(param_1 + 0x68) = 0;
  FUN_3001cc70(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001de4c @ 0x3001DE4C  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30018f98, FUN_3001cc70
 * Вызывают: FUN_3001e3e4
 * Константы: 0x3001DE4C
 * ---------------------------------------------------------------- */
void FUN_3001de4c(int param_1)

{
  FUN_30018f98(param_1 + 0x14);
  FUN_3001cc70(param_1);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_DeleteObject @ 0x3001DE6C  (примерный размер ~276 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_3001e034, FUN_3001f664, yaffs1_Scan
 * Константы: 0x3001DE6C, 0x3001DE88, 0xFFFFFFFF
 * Данные: DAT_3001ded0
 * ---------------------------------------------------------------- */
undefined4 yaffs_DeleteObject(int param_1)

{
  undefined4 uVar1;
  
  if (*(uint *)(param_1 + 100) < 6) {
                    /* WARNING: Could not recover jumptable at 0x3001de88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_3001ded0 + *(uint *)(param_1 + 100) * 4))();
    return uVar1;
  }
  return 0xffffffff;
}

/* ----------------------------------------------------------------
 * FUN_3001df80 @ 0x3001DF80  (примерный размер ~180 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 4
 * Вызывает: FUN_30018f50, FUN_30020c7c, printf, yaffs_UpdateObjectHeader
 * Вызывают: FUN_3001e034, FUN_3001e3e4, yaffs_RenameObject
 * Константы: 0x3001DF80, 0x00200000
 * Данные: DAT_3001ee88, DAT_3001ee90, DAT_3001ef34
 * ---------------------------------------------------------------- */
void FUN_3001df80(byte *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (byte *)0x0) {
    iVar2 = *(int *)(param_1 + 8);
    *param_1 = *param_1 | 0x40;
    *(undefined4 *)(param_1 + 0x5c) = DAT_3001ee90;
    *(undefined4 *)(param_1 + 0x58) = DAT_3001ee90;
    if (*(int *)(iVar2 + 0x80) == 0) {
      yaffs_UpdateObjectHeader(param_1,0,0,0,0,0);
    }
    else {
      iVar1 = FUN_30020c7c(param_1 + 0x70);
      if ((iVar1 != 0) &&
         (FUN_30018f50(param_1 + 0x70,iVar2 + 0xe20), (*DAT_3001ee88 & 0x200000) != 0)) {
        printf(DAT_3001ef34,*(undefined4 *)(param_1 + 0x30));
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001e034 @ 0x3001E034  (примерный размер ~428 байт)
 * Модуль: flash | Вызывают: 5 | Вызывает: 10
 * Вызывает: FUN_30018f50, FUN_3001d1d8, FUN_3001df80, free, yaffs_AddObjectToDirectory, yaffs_CloneString, yaffs_DeleteObject, yaffs_FindObjectByName, yaffs_SetObjectName, yaffs_UpdateObjectHeader
 * Вызывают: yaffs_Link, yaffs_MknodDirectory, yaffs_MknodFile, yaffs_MknodSpecial, yaffs_MknodSymLink
 * Константы: 0x3001E034, 0xFFFFFFFF
 * Данные: DAT_3001ee90
 * ---------------------------------------------------------------- */
byte * FUN_3001e034(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                   ,undefined4 param_6,int param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  void *__ptr;
  
  __ptr = (void *)0x0;
  uVar3 = *(undefined4 *)(param_2 + 8);
  iVar1 = yaffs_FindObjectByName(param_2,param_3);
  if (iVar1 == 0) {
    if ((param_1 == 2) && (__ptr = (void *)yaffs_CloneString(param_8), __ptr == (void *)0x0)) {
      pbVar2 = (byte *)0x0;
    }
    else {
      pbVar2 = (byte *)FUN_3001d1d8(uVar3,0xffffffff,param_1);
      if (pbVar2 == (byte *)0x0) {
        if (__ptr != (void *)0x0) {
          free(__ptr);
        }
        pbVar2 = (byte *)0x0;
      }
      else if (pbVar2 != (byte *)0x0) {
        pbVar2[0x28] = 0;
        pbVar2[0x29] = 0;
        pbVar2[0x2a] = 0;
        pbVar2[0x2b] = 0;
        *pbVar2 = *pbVar2 | 0x80;
        *(int *)(pbVar2 + 100) = param_1;
        *(undefined4 *)(pbVar2 + 0x34) = param_4;
        *(undefined4 *)(pbVar2 + 0x5c) = DAT_3001ee90;
        *(undefined4 *)(pbVar2 + 0x58) = DAT_3001ee90;
        *(undefined4 *)(pbVar2 + 0x54) = DAT_3001ee90;
        *(undefined4 *)(pbVar2 + 0x60) = param_9;
        *(undefined4 *)(pbVar2 + 0x4c) = param_5;
        *(undefined4 *)(pbVar2 + 0x50) = param_6;
        pbVar2[0x2c] = 0;
        pbVar2[0x2d] = 0;
        pbVar2[0x2e] = 0;
        pbVar2[0x2f] = 0;
        yaffs_SetObjectName(pbVar2,param_3);
        *pbVar2 = *pbVar2 | 0x40;
        yaffs_AddObjectToDirectory(param_2,pbVar2);
        *(undefined4 *)(pbVar2 + 8) = *(undefined4 *)(param_2 + 8);
        if (param_1 == 2) {
          *(void **)(pbVar2 + 0x68) = __ptr;
        }
        else if (param_1 == 4) {
          *(int *)(pbVar2 + 0x68) = param_7;
          *(undefined4 *)(pbVar2 + 0x6c) = *(undefined4 *)(param_7 + 0x30);
          FUN_30018f50(pbVar2 + 0x14,param_7 + 0x14);
        }
        iVar1 = yaffs_UpdateObjectHeader(pbVar2,param_3,0,0,0,0);
        if (iVar1 < 0) {
          yaffs_DeleteObject(pbVar2);
          pbVar2 = (byte *)0x0;
        }
        FUN_3001df80(param_2);
      }
    }
  }
  else {
    pbVar2 = (byte *)0x0;
  }
  return pbVar2;
}

/* ----------------------------------------------------------------
 * yaffs_MknodFile @ 0x3001E1E0  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3001e034
 * Вызывают: yaffs_open
 * Константы: 0x3001E1E0
 * ---------------------------------------------------------------- */
void yaffs_MknodFile(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  FUN_3001e034(1,param_1,param_2,param_3,param_4,param_5,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_MknodDirectory @ 0x3001E238  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3001e034
 * Вызывают: yaffs_mkdir
 * Константы: 0x3001E238
 * ---------------------------------------------------------------- */
void yaffs_MknodDirectory
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  FUN_3001e034(3,param_1,param_2,param_3,param_4,param_5,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_MknodSpecial @ 0x3001E290  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_3001e034
 * Константы: 0x3001E290
 * ---------------------------------------------------------------- */
void yaffs_MknodSpecial(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6)

{
  FUN_3001e034(5,param_1,param_2,param_3,param_4,param_5,0,0,param_6);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_MknodSymLink @ 0x3001E2E8  (примерный размер ~88 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3001e034
 * Вызывают: yaffs_symlink
 * Константы: 0x3001E2E8
 * ---------------------------------------------------------------- */
void yaffs_MknodSymLink(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6)

{
  FUN_3001e034(2,param_1,param_2,param_3,param_4,param_5,0,param_6,0);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_GetEquivalentObject @ 0x3001E340  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 9 | Вызывает: 1
 * Вызывает: FUN_3001beac
 * Вызывают: FUN_30025414, FUN_30025674, yaffs_GetFileSize, yaffs_GetObjectFileLength, yaffs_GetObjectInode, yaffs_GetObjectType, yaffs_GetSymlinkAlias, yaffs_Link, yaffs_readdir
 * Константы: 0x3001E340
 * ---------------------------------------------------------------- */
int yaffs_GetEquivalentObject(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 100) == 4)) {
    param_1 = *(int *)(param_1 + 0x68);
    FUN_3001beac(param_1);
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * yaffs_Link @ 0x3001E370  (примерный размер ~116 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3001e034, yaffs_GetEquivalentObject
 * Вызывают: yaffs_link
 * Константы: 0x3001E370
 * ---------------------------------------------------------------- */
undefined4 yaffs_Link(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = yaffs_GetEquivalentObject(param_3);
  iVar2 = FUN_3001e034(4,param_1,param_2,0,0,0,uVar1,0,0);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3001e3e4 @ 0x3001E3E4  (примерный размер ~404 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 12
 * Вызывает: FUN_30018f98, FUN_3001ca68, FUN_3001cc70, FUN_3001ddb4, FUN_3001ddf0, FUN_3001de1c, FUN_3001de4c, FUN_3001df80, FUN_30020c7c, yaffs_AddObjectToDirectory, yaffs_DeleteFile, yaffs_GetObjectName
 * Вызывают: FUN_3001e578
 * Константы: 0x3001E3E4
 * Данные: DAT_3001f468
 * ---------------------------------------------------------------- */
int FUN_3001e3e4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_118 [256];
  
  iVar3 = *(int *)(param_1 + 0x48);
  if (param_1 != 0) {
    FUN_3001df80(*(undefined4 *)(param_1 + 0x1c));
  }
  if (*(int *)(param_1 + 100) == 4) {
    iVar3 = FUN_3001de4c(param_1);
  }
  else {
    iVar1 = FUN_30020c7c(param_1 + 0x14);
    if (iVar1 == 0) {
      iVar3 = *(int *)(param_1 + 0x14);
      iVar1 = iVar3 + -0x14;
      yaffs_GetObjectName(iVar1,auStack_118,0x100);
      uVar2 = *(undefined4 *)(iVar3 + 8);
      FUN_30018f98(iVar3);
      yaffs_AddObjectToDirectory(*(undefined4 *)(*(int *)(param_1 + 8) + 0xda0),iVar1);
      iVar3 = FUN_3001ca68(param_1,uVar2,auStack_118,0,0);
      if (iVar3 == 1) {
        iVar3 = FUN_3001cc70(iVar1);
      }
    }
    else if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 100);
      if (iVar3 == 1) {
        iVar3 = yaffs_DeleteFile(param_1);
      }
      else if (iVar3 == 2) {
        iVar3 = FUN_3001de1c(param_1);
      }
      else if (iVar3 == 3) {
        FUN_30018f98(param_1 + 0x70);
        iVar3 = FUN_3001ddf0(param_1);
      }
      else if (iVar3 == 5) {
        iVar3 = FUN_3001cc70(param_1);
      }
      else {
        iVar3 = 0;
      }
    }
    else {
      iVar3 = FUN_3001ddb4(param_1);
      if (iVar3 == 0) {
        iVar3 = FUN_3001ca68(param_1,*(undefined4 *)(*(int *)(param_1 + 8) + 0xda0),DAT_3001f468,0,0
                            );
      }
      else {
        iVar3 = 0;
      }
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_3001e578 @ 0x3001E578  (примерный размер ~48 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 1
 * Вызывает: FUN_3001e3e4
 * Вызывают: FUN_3001f8d0, yaffs_RenameObject, yaffs_Unlink
 * Константы: 0x3001E578
 * ---------------------------------------------------------------- */
undefined4 FUN_3001e578(byte *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (byte *)0x0) || ((*param_1 & 0x20) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_3001e3e4(param_1);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_RenameObject @ 0x3001E5A8  (примерный размер ~456 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_3001ca68, FUN_3001df80, FUN_3001e578, FUN_30020c7c, printf, yaffs_FindObjectByName, ystrnlen
 * Вызывают: yaffs_rename
 * Константы: 0x3001E5A8
 * Данные: DAT_3001f524, DAT_3001f528, DAT_3001f52c
 * ---------------------------------------------------------------- */
undefined4 yaffs_RenameObject(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 100) != 3)) {
    printf(DAT_3001f524,DAT_3001f528);
  }
  if ((param_3 == 0) || (*(int *)(param_3 + 100) != 3)) {
    printf(DAT_3001f524,DAT_3001f52c);
  }
  iVar5 = *(int *)(param_1 + 8);
  iVar1 = ystrnlen(param_4,0x100);
  if (iVar1 < 0x100) {
    pbVar3 = (byte *)yaffs_FindObjectByName(param_1,param_2);
    if ((pbVar3 == (byte *)0x0) || ((*pbVar3 & 0x10) == 0)) {
      uVar2 = 0;
    }
    else {
      pbVar4 = (byte *)yaffs_FindObjectByName(param_3,param_4);
      if (((pbVar4 == (byte *)0x0) || (*(int *)(pbVar4 + 100) != 3)) ||
         (iVar1 = FUN_30020c7c(pbVar4 + 0x68), iVar1 != 0)) {
        if ((pbVar4 != (byte *)0x0) && (pbVar4 != pbVar3)) {
          *(undefined4 *)(iVar5 + 0xd68) = 1;
          FUN_3001ca68(pbVar3,param_3,param_4,0,*(undefined4 *)(pbVar4 + 0x30));
          pbVar4[1] = pbVar4[1] | 8;
          FUN_3001e578(pbVar4);
          *(undefined4 *)(iVar5 + 0xd68) = 0;
        }
        uVar2 = FUN_3001ca68(pbVar3,param_3,param_4,1,0);
        FUN_3001df80(param_1);
        if (param_3 != param_1) {
          FUN_3001df80(param_3);
        }
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3001e770 @ 0x3001E770  (примерный размер ~296 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: malloc, memset
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x3001E770, 0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFD
 * ---------------------------------------------------------------- */
undefined4 FUN_3001e770(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (*(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc)) + 1;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0xffffffff;
  pvVar1 = malloc(iVar3 * 8);
  *(void **)(param_1 + 0x124) = pvVar1;
  if (*(int *)(param_1 + 0x124) == 0) {
    pvVar1 = malloc(iVar3 * 8);
    *(void **)(param_1 + 0x124) = pvVar1;
    *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) | 1;
  }
  else {
    *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) & 0xfffffffe;
  }
  if (*(int *)(param_1 + 0x124) != 0) {
    iVar4 = *(int *)(param_1 + 0xc) + 7;
    *(int *)(param_1 + 0x130) = (int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3;
    pvVar1 = malloc(*(int *)(param_1 + 0x130) * iVar3);
    *(void **)(param_1 + 0x128) = pvVar1;
    if (*(int *)(param_1 + 0x128) == 0) {
      pvVar1 = malloc(*(int *)(param_1 + 0x130) * iVar3);
      *(void **)(param_1 + 0x128) = pvVar1;
      *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) | 2;
    }
    else {
      *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) & 0xfffffffd;
    }
  }
  if ((*(int *)(param_1 + 0x124) == 0) || (*(int *)(param_1 + 0x128) == 0)) {
    uVar2 = 0;
  }
  else {
    memset(*(void **)(param_1 + 0x124),0,iVar3 * 8);
    memset(*(void **)(param_1 + 0x128),0,*(int *)(param_1 + 0x130) * iVar3);
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_3001e898 @ 0x3001E898  (примерный размер ~164 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: free
 * Вызывают: yaffs_Deinitialise, yaffs_GutsInitialise
 * Константы: 0x3001E898, 0xFFFFFFFE, 0xFFFFFFFD
 * ---------------------------------------------------------------- */
void FUN_3001e898(int param_1)

{
  if (((*(uint *)(param_1 + 300) & 1) == 0) || (*(int *)(param_1 + 0x124) == 0)) {
    if (*(int *)(param_1 + 0x124) != 0) {
      free(*(void **)(param_1 + 0x124));
    }
  }
  else {
    free(*(void **)(param_1 + 0x124));
  }
  *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) & 0xfffffffe;
  *(undefined4 *)(param_1 + 0x124) = 0;
  if (((*(uint *)(param_1 + 300) & 2) == 0) || (*(int *)(param_1 + 0x128) == 0)) {
    if (*(int *)(param_1 + 0x128) != 0) {
      free(*(void **)(param_1 + 0x128));
    }
  }
  else {
    free(*(void **)(param_1 + 0x128));
  }
  *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) & 0xfffffffd;
  *(undefined4 *)(param_1 + 0x128) = 0;
  return;
}

/* ----------------------------------------------------------------
 * yaffs_BackgroundGarbageCollect @ 0x3001E93C  (примерный размер ~96 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_3001bb54, printf
 * Константы: 0x3001E93C, 0x00200000
 * Данные: DAT_3001ee88, DAT_3001f870
 * ---------------------------------------------------------------- */
bool yaffs_BackgroundGarbageCollect(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x134);
  iVar1 = *(int *)(param_1 + 0xc);
  if ((*DAT_3001ee88 & 0x200000) != 0) {
    printf(DAT_3001f870,param_2);
  }
  FUN_3001bb54(param_1,1);
  return *(int *)(param_1 + 0xd58) / 2 < iVar1 * iVar2;
}

/* ----------------------------------------------------------------
 * yaffs_FlushEntireDeviceCache @ 0x3001E99C  (примерный размер ~148 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3001d5dc
 * Вызывают: yaffs_unmount
 * Константы: 0x3001E99C
 * ---------------------------------------------------------------- */
void yaffs_FlushEntireDeviceCache(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x20);
  while( true ) {
    iVar3 = 0;
    iVar1 = 0;
    while ((iVar1 < iVar2 && (iVar3 == 0))) {
      if ((*(int *)(*(int *)(param_1 + 0xd98) + iVar1 * 0x1c) != 0) &&
         (*(int *)(*(int *)(param_1 + 0xd98) + iVar1 * 0x1c + 0xc) != 0)) {
        iVar3 = *(int *)(*(int *)(param_1 + 0xd98) + iVar1 * 0x1c);
      }
      iVar1 = iVar1 + 1;
    }
    if (iVar3 == 0) break;
    FUN_3001d5dc(iVar3);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001ea30 @ 0x3001EA30  (примерный размер ~104 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3001ea98
 * Константы: 0x3001EA30
 * ---------------------------------------------------------------- */
int FUN_3001ea30(int param_1)

{
  int iVar1;
  
  if (0 < *(int *)(param_1 + 0x20)) {
    for (iVar1 = 0; iVar1 < *(int *)(param_1 + 0x20); iVar1 = iVar1 + 1) {
      if (*(int *)(*(int *)(param_1 + 0xd98) + iVar1 * 0x1c) == 0) {
        return *(int *)(param_1 + 0xd98) + iVar1 * 0x1c;
      }
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3001ea98 @ 0x3001EA98  (примерный размер ~288 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 2
 * Вызывает: FUN_3001d5dc, FUN_3001ea30
 * Вызывают: yaffs_DoWriteDataToFile, yaffs_ReadDataFromFile
 * Константы: 0x3001EA98
 * ---------------------------------------------------------------- */
int FUN_3001ea98(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x20) < 1) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_3001ea30(param_1);
    if (iVar1 == 0) {
      uVar4 = 0;
      iVar3 = -1;
      iVar1 = 0;
      for (iVar2 = 0; iVar2 < *(int *)(param_1 + 0x20); iVar2 = iVar2 + 1) {
        if (((*(int *)(*(int *)(param_1 + 0xd98) + iVar2 * 0x1c) != 0) &&
            (*(int *)(*(int *)(param_1 + 0xd98) + iVar2 * 0x1c + 0x14) == 0)) &&
           ((*(int *)(*(int *)(param_1 + 0xd98) + iVar2 * 0x1c + 8) < iVar3 || (iVar1 == 0)))) {
          iVar3 = *(int *)(*(int *)(param_1 + 0xd98) + iVar2 * 0x1c + 8);
          uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xd98) + iVar2 * 0x1c);
          iVar1 = *(int *)(param_1 + 0xd98) + iVar2 * 0x1c;
        }
      }
      if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 0)) {
        FUN_3001d5dc(uVar4);
        iVar1 = FUN_3001ea30(param_1);
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3001ebb8 @ 0x3001EBB8  (примерный размер ~160 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 0
 * Вызывают: FUN_3001ecec, yaffs_DoWriteDataToFile, yaffs_ReadDataFromFile
 * Константы: 0x3001EBB8
 * ---------------------------------------------------------------- */
int FUN_3001ebb8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if (0 < *(int *)(iVar2 + 0x20)) {
    for (iVar1 = 0; iVar1 < *(int *)(iVar2 + 0x20); iVar1 = iVar1 + 1) {
      if ((*(int *)(*(int *)(iVar2 + 0xd98) + iVar1 * 0x1c) == param_1) &&
         (*(int *)(*(int *)(iVar2 + 0xd98) + iVar1 * 0x1c + 4) == param_2)) {
        *(int *)(iVar2 + 0xe74) = *(int *)(iVar2 + 0xe74) + 1;
        return *(int *)(iVar2 + 0xd98) + iVar1 * 0x1c;
      }
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3001ec58 @ 0x3001EC58  (примерный размер ~148 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: yaffs_DoWriteDataToFile, yaffs_ReadDataFromFile
 * Константы: 0x3001EC58
 * Данные: DAT_3001fb74
 * ---------------------------------------------------------------- */
void FUN_3001ec58(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (0 < *(int *)(param_1 + 0x20)) {
    if (DAT_3001fb74 <= *(uint *)(param_1 + 0xd9c)) {
      for (iVar1 = 1; iVar1 < *(int *)(param_1 + 0x20); iVar1 = iVar1 + 1) {
        *(undefined4 *)(*(int *)(param_1 + 0xd98) + iVar1 * 0x1c + 8) = 0;
      }
      *(undefined4 *)(param_1 + 0xd9c) = 0;
    }
    *(int *)(param_1 + 0xd9c) = *(int *)(param_1 + 0xd9c) + 1;
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0xd9c);
    if (param_3 != 0) {
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001ecec @ 0x3001ECEC  (примерный размер ~64 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3001ebb8
 * Вызывают: yaffs_DoWriteDataToFile
 * Константы: 0x3001ECEC
 * ---------------------------------------------------------------- */
void FUN_3001ecec(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  if ((0 < *(int *)(*(int *)(param_1 + 8) + 0x20)) &&
     (puVar1 = (undefined4 *)FUN_3001ebb8(param_1,param_2), puVar1 != (undefined4 *)0x0)) {
    *puVar1 = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_ReadDataFromFile @ 0x3001ED2C  (примерный размер ~544 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_3001d720, FUN_3001ea98, FUN_3001ebb8, FUN_3001ec58, memcpy, yaffs_AddrToChunk, yaffs_GetTempBuffer, yaffs_ReleaseTempBuffer
 * Вызывают: yaffs_read
 * Константы: 0x3001ED2C
 * Данные: DAT_3001fda0, DAT_3001fda4
 * ---------------------------------------------------------------- */
int yaffs_ReadDataFromFile(int param_1,void *param_2,uint param_3,int param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint __n;
  int local_50;
  int local_4c [2];
  uint local_44;
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_8;
  int local_4;
  
  iVar4 = 0;
  iVar3 = *(int *)(param_1 + 8);
  local_8 = param_3;
  local_4 = param_4;
  for (; 0 < (int)param_5; param_5 = param_5 - __n) {
    local_3c = local_8;
    local_38 = local_4;
    yaffs_AddrToChunk(iVar3,local_8,local_4,&local_50,local_4c);
    local_50 = local_50 + 1;
    __n = param_5;
    if (*(uint *)(iVar3 + 0x9c) <= local_4c[0] + param_5) {
      __n = *(int *)(iVar3 + 0x9c) - local_4c[0];
    }
    piVar1 = (int *)FUN_3001ebb8(param_1,local_50);
    if (((piVar1 == (int *)0x0) && (*(uint *)(iVar3 + 0x9c) == __n)) && (*(int *)(iVar3 + 4) == 0))
    {
      FUN_3001d720(param_1,local_50,param_2);
    }
    else if (*(int *)(iVar3 + 0x20) < 1) {
      iVar2 = yaffs_GetTempBuffer(iVar3,DAT_3001fda0);
      FUN_3001d720(param_1,local_50,iVar2);
      memcpy(param_2,(void *)(iVar2 + local_4c[0]),__n);
      yaffs_ReleaseTempBuffer(iVar3,iVar2,DAT_3001fda4);
    }
    else {
      if (piVar1 == (int *)0x0) {
        piVar1 = (int *)FUN_3001ea98(*(undefined4 *)(param_1 + 8));
        *piVar1 = param_1;
        piVar1[1] = local_50;
        piVar1[3] = 0;
        piVar1[5] = 0;
        FUN_3001d720(param_1,local_50,piVar1[6]);
        piVar1[4] = 0;
      }
      FUN_3001ec58(iVar3,piVar1,0);
      piVar1[5] = 1;
      memcpy(param_2,(void *)(piVar1[6] + local_4c[0]),__n);
      piVar1[5] = 0;
    }
    local_44 = local_8 + __n;
    local_40 = local_4 + ((int)__n >> 0x1f) + (uint)CARRY4(local_8,__n);
    param_2 = (void *)((int)param_2 + __n);
    iVar4 = iVar4 + __n;
    local_34 = local_44;
    local_30 = local_40;
    local_8 = local_44;
    local_4 = local_40;
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * yaffs_DoWriteDataToFile @ 0x3001EF4C  (примерный размер ~1088 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 12
 * Вызывает: FUN_3001d45c, FUN_3001d720, FUN_3001ea98, FUN_3001ebb8, FUN_3001ec58, FUN_3001ecec, memcpy, printf, yaffs_AddrToChunk, yaffs_CheckSpaceForAllocation, yaffs_GetTempBuffer, yaffs_ReleaseTempBuffer
 * Вызывают: yaffs2_HandleHole, yaffs_WriteDataToFile
 * Константы: 0x3001EF4C
 * Данные: DAT_3001f524, DAT_3001ff7c, DAT_3001ff80, DAT_300200c4, DAT_30020190
 * ---------------------------------------------------------------- */
int yaffs_DoWriteDataToFile
              (byte *param_1,void *param_2,uint param_3,int param_4,uint param_5,int param_6)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int local_64;
  uint local_60;
  int local_5c;
  int local_58;
  uint local_54;
  uint local_50;
  uint local_48;
  int local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  void *local_c;
  uint local_8;
  int local_4;
  
  local_5c = 0;
  iVar2 = 0;
  iVar3 = *(int *)(param_1 + 8);
  local_54 = param_3;
  local_c = param_2;
  local_8 = param_3;
  local_4 = param_4;
  do {
    while( true ) {
      if (((int)param_5 < 1) || (iVar2 < 0)) {
        if (*(uint *)(param_1 + 0x68) < local_54 + local_5c) {
          *(uint *)(param_1 + 0x68) = local_54 + local_5c;
        }
        *param_1 = *param_1 | 0x40;
        return local_5c;
      }
      local_40 = local_8;
      local_3c = local_4;
      yaffs_AddrToChunk(iVar3,local_8,local_4,&local_64,&local_60);
      if ((local_4 != 0 || local_64 * *(int *)(iVar3 + 0x9c) + local_60 != local_8) ||
         (*(uint *)(iVar3 + 0x9c) <= local_60)) {
        printf(DAT_3001ff7c,local_8,local_64,local_60);
      }
      iVar6 = local_64 + 1;
      if (local_60 + param_5 < *(uint *)(iVar3 + 0x9c)) {
        local_50 = *(int *)(iVar3 + 0x9c) * local_64;
        if (*(uint *)(param_1 + 0x68) < local_50) {
          uVar5 = 0;
        }
        else {
          uVar5 = *(int *)(param_1 + 0x68) - local_50;
          if (*(uint *)(iVar3 + 0x9c) < uVar5) {
            uVar5 = *(uint *)(iVar3 + 0x9c);
          }
        }
        if (uVar5 <= local_60 + param_5) {
          uVar5 = local_60 + param_5;
        }
        uVar4 = param_5;
        if (((int)uVar5 < 0) || (local_64 = iVar6, *(int *)(iVar3 + 0x9c) < (int)uVar5)) {
          local_64 = iVar6;
          printf(DAT_3001f524,DAT_3001ff80);
        }
      }
      else {
        uVar4 = *(int *)(iVar3 + 0x9c) - local_60;
        uVar5 = *(uint *)(iVar3 + 0x9c);
        local_64 = iVar6;
      }
      if ((*(uint *)(iVar3 + 0x9c) != uVar4) || (*(int *)(iVar3 + 4) != 0)) break;
      iVar2 = FUN_3001d45c(param_1,local_64,local_c,*(undefined4 *)(iVar3 + 0x9c),0);
      FUN_3001ecec(param_1,local_64);
LAB_3001f2e4:
      if (-1 < iVar2) {
        param_5 = param_5 - uVar4;
        local_48 = local_8 + uVar4;
        local_44 = local_4 + ((int)uVar4 >> 0x1f) + (uint)CARRY4(local_8,uVar4);
        local_c = (void *)((int)local_c + uVar4);
        local_5c = local_5c + uVar4;
        local_38 = local_48;
        local_34 = local_44;
        local_8 = local_48;
        local_4 = local_44;
      }
    }
    if (*(int *)(iVar3 + 0x20) < 1) {
      local_58 = yaffs_GetTempBuffer(iVar3,DAT_300200c4);
      FUN_3001d720(param_1,local_64,local_58);
      memcpy((void *)(local_58 + local_60),local_c,uVar4);
      iVar2 = FUN_3001d45c(param_1,local_64,local_58,uVar5,0);
      yaffs_ReleaseTempBuffer(iVar3,local_58,DAT_30020190);
      goto LAB_3001f2e4;
    }
    puVar1 = (undefined4 *)FUN_3001ebb8(param_1,local_64);
    if ((puVar1 == (undefined4 *)0x0) &&
       (iVar6 = yaffs_CheckSpaceForAllocation(iVar3,1), iVar6 != 0)) {
      puVar1 = (undefined4 *)FUN_3001ea98(iVar3);
      *puVar1 = param_1;
      puVar1[1] = local_64;
      puVar1[3] = 0;
      puVar1[5] = 0;
      FUN_3001d720(param_1,local_64,puVar1[6]);
    }
    else if ((puVar1 != (undefined4 *)0x0) &&
            ((puVar1[3] == 0 && (iVar6 = yaffs_CheckSpaceForAllocation(iVar3,1), iVar6 == 0)))) {
      puVar1 = (undefined4 *)0x0;
    }
    if (puVar1 != (undefined4 *)0x0) {
      FUN_3001ec58(iVar3,puVar1,1);
      puVar1[5] = 1;
      memcpy((void *)(puVar1[6] + local_60),local_c,uVar4);
      puVar1[5] = 0;
      puVar1[4] = uVar5;
      if (param_6 != 0) {
        iVar2 = FUN_3001d45c(*puVar1,puVar1[1],puVar1[6],puVar1[4],1);
        puVar1[3] = 0;
      }
      goto LAB_3001f2e4;
    }
    iVar2 = -1;
  } while( true );
}

/* ----------------------------------------------------------------
 * yaffs_WriteDataToFile @ 0x3001F38C  (примерный размер ~128 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: yaffs2_HandleHole, yaffs_DoWriteDataToFile
 * Вызывают: yaffs_write
 * Константы: 0x3001F38C
 * ---------------------------------------------------------------- */
void yaffs_WriteDataToFile
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  yaffs2_HandleHole(param_1,param_3,param_4);
  yaffs_DoWriteDataToFile(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_GetFileSize @ 0x3001F40C  (примерный размер ~156 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: yaffs_GetEquivalentObject, ystrnlen
 * Вызывают: yaffs_GetAttributes
 * Константы: 0x3001F40C
 * ---------------------------------------------------------------- */
undefined8 yaffs_GetFileSize(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = yaffs_GetEquivalentObject(param_1);
  if (*(int *)(iVar1 + 100) == 1) {
    iVar2 = *(int *)(iVar1 + 0x68);
    iVar1 = 0;
  }
  else if (*(int *)(iVar1 + 100) == 2) {
    if (*(int *)(iVar1 + 0x68) == 0) {
      iVar1 = 0;
      iVar2 = 0;
    }
    else {
      iVar2 = ystrnlen(*(int *)(iVar1 + 0x68),0x9f);
      iVar1 = iVar2 >> 0x1f;
    }
  }
  else {
    iVar1 = 0;
    iVar2 = 0;
  }
  return CONCAT44(iVar1,iVar2);
}

/* ----------------------------------------------------------------
 * yaffs_FlushFile @ 0x3001F4A8  (примерный размер ~160 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 2
 * Вызывает: FUN_3001d5dc, yaffs_UpdateObjectHeader
 * Вызывают: FUN_30025674, yaffsIoctl, yaffs_close
 * Константы: 0x3001F4A8
 * Данные: DAT_300203d8
 * ---------------------------------------------------------------- */
undefined4 yaffs_FlushFile(byte *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*param_1 & 0x40) == 0) {
    uVar2 = 1;
  }
  else {
    FUN_3001d5dc(param_1);
    if (param_3 == 0) {
      if (param_2 != 0) {
        *(undefined4 *)(param_1 + 0x58) = DAT_300203d8;
      }
      iVar1 = yaffs_UpdateObjectHeader(param_1,0,0,0,0,0);
      if (iVar1 < 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_Unlink @ 0x3001F548  (примерный размер ~40 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3001e578, yaffs_FindObjectByName
 * Вызывают: yaffsfs_DoUnlink
 * Константы: 0x3001F548
 * ---------------------------------------------------------------- */
void yaffs_Unlink(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = yaffs_FindObjectByName(param_1,param_2);
  FUN_3001e578(uVar1);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_HandleShadowedObject @ 0x3001F570  (примерный размер ~124 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: yaffs_AddObjectToDirectory, yaffs_FindObjectByNumber, yaffs_FindOrCreateObjectByNumber
 * Вызывают: yaffs2_ScanBackwards
 * Константы: 0x3001F570
 * ---------------------------------------------------------------- */
void yaffs_HandleShadowedObject(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  
  if (((param_3 == 0) || (iVar1 = yaffs_FindObjectByNumber(param_1,param_2), iVar1 == 0)) &&
     (pbVar2 = (byte *)yaffs_FindOrCreateObjectByNumber(param_1,param_2,1), pbVar2 != (byte *)0x0))
  {
    pbVar2[1] = pbVar2[1] | 8;
    yaffs_AddObjectToDirectory(*(undefined4 *)(param_1 + 0xda0),pbVar2);
    pbVar2[0x70] = 0;
    pbVar2[0x71] = 0;
    pbVar2[0x72] = 0;
    pbVar2[0x73] = 0;
    *pbVar2 = *pbVar2 | 0x80;
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_HardlinkFixup @ 0x3001F5EC  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 2
 * Вызывает: FUN_30018f50, yaffs_FindObjectByNumber
 * Вызывают: FUN_30029dd4, yaffs1_Scan, yaffs2_ScanBackwards
 * Константы: 0x3001F5EC
 * ---------------------------------------------------------------- */
void yaffs_HardlinkFixup(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  while (param_2 != 0) {
    iVar2 = *(int *)(param_2 + 0x14);
    iVar1 = yaffs_FindObjectByNumber(param_1,*(undefined4 *)(param_2 + 0x6c));
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0x68) = 0;
      *(int *)(param_2 + 0x14) = param_2 + 0x14;
      *(int *)(param_2 + 0x18) = param_2 + 0x14;
      param_2 = iVar2;
    }
    else {
      *(int *)(param_2 + 0x68) = iVar1;
      FUN_30018f50(param_2 + 0x14,iVar1 + 0x14);
      param_2 = iVar2;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001f664 @ 0x3001F664  (примерный размер ~168 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: yaffs_DeleteObject
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x3001F664
 * ---------------------------------------------------------------- */
void FUN_3001f664(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0xd4) == 0) {
    puVar1 = (undefined4 *)**(undefined4 **)(*(int *)(param_1 + 0xda0) + 0x68);
    puVar3 = *(undefined4 **)(*(int *)(param_1 + 0xda0) + 0x68);
    while (puVar2 = puVar1, (undefined4 *)(*(int *)(param_1 + 0xda0) + 0x68) != puVar3) {
      if (puVar3 != (undefined4 *)0x0) {
        yaffs_DeleteObject(puVar3 + -8);
      }
      puVar1 = (undefined4 *)*puVar2;
      puVar3 = puVar2;
    }
    puVar1 = (undefined4 *)**(undefined4 **)(*(int *)(param_1 + 0xda4) + 0x68);
    puVar3 = *(undefined4 **)(*(int *)(param_1 + 0xda4) + 0x68);
    while (puVar2 = puVar1, (undefined4 *)(*(int *)(param_1 + 0xda4) + 0x68) != puVar3) {
      if (puVar3 != (undefined4 *)0x0) {
        yaffs_DeleteObject(puVar3 + -8);
      }
      puVar1 = (undefined4 *)*puVar2;
      puVar3 = puVar2;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001f70c @ 0x3001F70C  (примерный размер ~84 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3001f760
 * Константы: 0x3001F70C
 * ---------------------------------------------------------------- */
undefined4 FUN_3001f70c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((*(int *)(param_1 + 0xda4) == param_2) || (*(int *)(param_1 + 0xda0) == param_2)) ||
     (*(int *)(param_1 + 0xd88) == param_2)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3001f760 @ 0x3001F760  (примерный размер ~368 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_3001f70c, printf, yaffs_AddObjectToDirectory
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x3001F760
 * Данные: DAT_3001fe78, DAT_3002072c
 * ---------------------------------------------------------------- */
void FUN_3001f760(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0xd4) == 0) {
    for (iVar5 = 0; iVar5 < 0x100; iVar5 = iVar5 + 1) {
      puVar1 = (undefined4 *)**(undefined4 **)(param_1 + iVar5 * 0xc + 0x154);
      puVar4 = *(undefined4 **)(param_1 + iVar5 * 0xc + 0x154);
      while (puVar3 = puVar1, (undefined4 *)(param_1 + iVar5 * 0xc + 0x154) != puVar4) {
        if (puVar4 != (undefined4 *)0x0) {
          iVar6 = puVar4[4];
          iVar2 = FUN_3001f70c(param_1,puVar4 + -3);
          if (iVar2 == 0) {
            if ((iVar6 == 0) || (*(int *)(iVar6 + 100) != 3)) {
LAB_3001f890:
              if ((*DAT_3001fe78 & 8) != 0) {
                printf(DAT_3002072c,puVar4[9]);
              }
              yaffs_AddObjectToDirectory(*(undefined4 *)(param_1 + 0xd8c),puVar4 + -3);
            }
            else {
              iVar2 = FUN_3001f70c(param_1,iVar6);
              if (iVar2 == 0) {
                for (iVar2 = 100;
                    (((*(int *)(param_1 + 0xd88) != iVar6 && (*(int *)(iVar6 + 0x1c) != 0)) &&
                     (*(int *)(*(int *)(iVar6 + 0x1c) + 100) == 3)) && (0 < iVar2));
                    iVar2 = iVar2 + -1) {
                  iVar6 = *(int *)(iVar6 + 0x1c);
                }
                if (*(int *)(param_1 + 0xd88) != iVar6) goto LAB_3001f890;
              }
            }
          }
        }
        puVar1 = (undefined4 *)*puVar3;
        puVar4 = puVar3;
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3001f8d0 @ 0x3001F8D0  (примерный размер ~168 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_3001e578, printf
 * Вызывают: FUN_30020c20
 * Константы: 0x3001F8D0
 * Данные: DAT_3001fe78, DAT_3002084c, DAT_30020850, DAT_30020854
 * ---------------------------------------------------------------- */
void FUN_3001f8d0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 100) != 3) {
    printf(DAT_3002084c,DAT_30020850);
  }
  puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x68);
  puVar3 = *(undefined4 **)(param_1 + 0x68);
  while (puVar2 = puVar1, (undefined4 *)(param_1 + 0x68) != puVar3) {
    if (puVar3 != (undefined4 *)0x0) {
      if (puVar3[0x11] == 3) {
        FUN_3001f8d0(puVar3 + -8);
      }
      if ((*DAT_3001fe78 & 8) != 0) {
        printf(DAT_30020854,puVar3[4]);
      }
      FUN_3001e578(puVar3 + -8);
    }
    puVar1 = (undefined4 *)*puVar2;
    puVar3 = puVar2;
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_UpdateDirtyDirectories @ 0x3001F978  (примерный размер ~168 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 4
 * Вызывает: FUN_30018f98, FUN_30020c7c, printf, yaffs_UpdateObjectHeader
 * Константы: 0x00200000, 0x3001F978
 * Данные: DAT_3001fe78, DAT_30020858, DAT_3002085c
 * ---------------------------------------------------------------- */
void yaffs_UpdateDirtyDirectories(int param_1)

{
  int iVar1;
  
  if ((*DAT_3001fe78 & 0x200000) != 0) {
    printf(DAT_30020858);
  }
  while (iVar1 = FUN_30020c7c(param_1 + 0xe20), iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0xe20);
    FUN_30018f98(iVar1);
    if ((*DAT_3001fe78 & 0x200000) != 0) {
      printf(DAT_3002085c,*(undefined4 *)(iVar1 + -0x40));
    }
    if ((*(byte *)(iVar1 + -0x70) & 0x40) != 0) {
      yaffs_UpdateObjectHeader((byte *)(iVar1 + -0x70),0,0,0,0,0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_GetObjectFileLength @ 0x3001FA20  (примерный размер ~100 байт)
 * Модуль: flash | Вызывают: 6 | Вызывает: 2
 * Вызывает: yaffs_GetEquivalentObject, ystrnlen
 * Вызывают: FUN_30025414, yaffsGetFileSavings, yaffsIoctl, yaffs_lseek, yaffs_read, yaffs_write
 * Константы: 0x3001FA20
 * ---------------------------------------------------------------- */
undefined4 yaffs_GetObjectFileLength(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = yaffs_GetEquivalentObject(param_1);
  if (*(int *)(iVar1 + 100) == 1) {
    uVar2 = *(undefined4 *)(iVar1 + 0x68);
  }
  else if (*(int *)(iVar1 + 100) == 2) {
    if (*(int *)(iVar1 + 0x68) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = ystrnlen(*(undefined4 *)(iVar1 + 0x68),0x9f);
    }
  }
  else {
    uVar2 = *(undefined4 *)(*(int *)(iVar1 + 8) + 0x9c);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_GetObjectLinkCount @ 0x3001FA84  (примерный размер ~76 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30025414
 * Константы: 0x3001FA84
 * ---------------------------------------------------------------- */
uint yaffs_GetObjectLinkCount(byte *param_1)

{
  byte *pbVar1;
  uint uVar2;
  
  uVar2 = (uint)((*param_1 & 4) == 0);
  for (pbVar1 = *(byte **)(param_1 + 0x14); param_1 + 0x14 != pbVar1; pbVar1 = *(byte **)pbVar1) {
    uVar2 = uVar2 + 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_GetObjectInode @ 0x3001FAD0  (примерный размер ~28 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: yaffs_GetEquivalentObject
 * Константы: 0x3001FAD0
 * ---------------------------------------------------------------- */
undefined4 yaffs_GetObjectInode(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = yaffs_GetEquivalentObject(param_1);
  return *(undefined4 *)(iVar1 + 0x30);
}

/* ----------------------------------------------------------------
 * yaffs_GetObjectType @ 0x3001FAEC  (примерный размер ~204 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: yaffs_GetEquivalentObject
 * Константы: 0x3001FAEC
 * ---------------------------------------------------------------- */
char yaffs_GetObjectType(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = yaffs_GetEquivalentObject(param_1);
  iVar2 = *(int *)(iVar1 + 100);
  if (iVar2 == 3) {
    return '\x04';
  }
  if (iVar2 < 4) {
    if (iVar2 == 1) {
      return '\b';
    }
    if (iVar2 == 2) {
      return '\n';
    }
  }
  else {
    if (iVar2 == 4) {
      return '\b';
    }
    if (iVar2 == 5) {
      if ((*(uint *)(iVar1 + 0x34) & 0xf000) == 0x1000) {
        return '\x01';
      }
      if ((*(uint *)(iVar1 + 0x34) & 0xf000) == 0x2000) {
        return '\x02';
      }
      return ((*(uint *)(iVar1 + 0x34) & 0xf000) != 0x6000) * '\x02' + '\x06';
    }
  }
  return '\b';
}

/* ----------------------------------------------------------------
 * yaffs_GetSymlinkAlias @ 0x3001FBB8  (примерный размер ~56 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 2
 * Вызывает: yaffs_CloneString, yaffs_GetEquivalentObject
 * Константы: 0x3001FBB8
 * Данные: DAT_30020a60
 * ---------------------------------------------------------------- */
void yaffs_GetSymlinkAlias(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = yaffs_GetEquivalentObject(param_1);
  if (*(int *)(iVar1 + 100) == 2) {
    yaffs_CloneString(*(undefined4 *)(iVar1 + 0x68));
  }
  else {
    yaffs_CloneString(DAT_30020a60);
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_SetAttributes @ 0x3001FBF0  (примерный размер ~192 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 2
 * Вызывает: yaffs_ResizeFile, yaffs_UpdateObjectHeader
 * Константы: 0x3001FBF0
 * ---------------------------------------------------------------- */
undefined4 yaffs_SetAttributes(int param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2;
  if ((uVar1 & 1) != 0) {
    *(uint *)(param_1 + 0x34) = param_2[1];
  }
  if ((uVar1 & 2) != 0) {
    *(uint *)(param_1 + 0x4c) = param_2[2];
  }
  if ((uVar1 & 4) != 0) {
    *(uint *)(param_1 + 0x50) = param_2[3];
  }
  if ((uVar1 & 0x10) != 0) {
    *(uint *)(param_1 + 0x54) = param_2[5];
  }
  if ((uVar1 & 0x40) != 0) {
    *(uint *)(param_1 + 0x5c) = param_2[7];
  }
  if ((uVar1 & 0x20) != 0) {
    *(uint *)(param_1 + 0x58) = param_2[6];
  }
  if ((uVar1 & 8) != 0) {
    yaffs_ResizeFile(param_1,param_2[4],0);
  }
  yaffs_UpdateObjectHeader(param_1,0,1,0,0,0);
  return 1;
}

/* ----------------------------------------------------------------
 * yaffs_GetAttributes @ 0x3001FCB0  (примерный размер ~120 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: yaffs_GetFileSize
 * Константы: 0x3001FCB0
 * ---------------------------------------------------------------- */
undefined4 yaffs_GetAttributes(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  param_2[1] = *(undefined4 *)(param_1 + 0x34);
  param_2[2] = *(undefined4 *)(param_1 + 0x4c);
  param_2[3] = *(undefined4 *)(param_1 + 0x50);
  param_2[5] = *(undefined4 *)(param_1 + 0x54);
  param_2[7] = *(undefined4 *)(param_1 + 0x5c);
  param_2[6] = *(undefined4 *)(param_1 + 0x58);
  uVar1 = yaffs_GetFileSize(param_1);
  param_2[4] = uVar1;
  *param_2 = 0x7f;
  return 1;
}

/* ----------------------------------------------------------------
 * FUN_3001fd28 @ 0x3001FD28  (примерный размер ~508 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: yaffs_UpdateObjectHeader
 * Вызывают: yaffs_RemoveXAttribute, yaffs_SetXAttribute
 * Константы: 0xFFFFFFE4, 0x3001FD28
 * ---------------------------------------------------------------- */
undefined4
FUN_3001fd28(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_24 = param_5;
  local_20 = param_6;
  local_1c = 0xffffffe4;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  iVar1 = yaffs_UpdateObjectHeader(param_1,0,0,0,0,&local_30);
  if (iVar1 < 1) {
    local_1c = 0xffffffe4;
  }
  return local_1c;
}

/* ----------------------------------------------------------------
 * yaffs_SetXAttribute @ 0x3001FF24  (примерный размер ~64 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_3001fd28
 * Константы: 0x3001FF24
 * ---------------------------------------------------------------- */
void yaffs_SetXAttribute(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        ,undefined4 param_5)

{
  FUN_3001fd28(param_1,1,param_2,param_3,param_4,param_5);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_RemoveXAttribute @ 0x3001FF64  (примерный размер ~72 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: FUN_3001fd28
 * Константы: 0x3001FF64
 * ---------------------------------------------------------------- */
void yaffs_RemoveXAttribute(undefined4 param_1,undefined4 param_2)

{
  FUN_3001fd28(param_1,0,param_2,0,0,0);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_GetXAttribute @ 0x3001FFAC  (примерный размер ~44 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 6
 * Вызывает: nval_get, nval_hasvalues, nval_list, yaffs_GetTempBuffer, yaffs_ReadChunkWithTagsFromNAND, yaffs_ReleaseTempBuffer
 * Константы: 0xFFFFFFB2, 0x3001FFAC, 0xFFFFFFF4, 0xFFFFFFFE
 * Данные: DAT_30020c9c, DAT_30020ca0
 * ---------------------------------------------------------------- */
undefined4 yaffs_GetXAttribute(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_74 [72];
  
  iVar5 = *(int *)(param_1 + 8);
  iVar6 = *(int *)(iVar5 + 0x9c) + -0x200;
  if (*(int *)(param_1 + 0x28) < 1) {
    uVar1 = 0xffffffb2;
  }
  else if ((*(byte *)(param_1 + 1) & 0x30) == 0x10) {
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffb2;
    }
  }
  else {
    iVar2 = yaffs_GetTempBuffer(iVar5,DAT_30020c9c);
    if (iVar2 == 0) {
      uVar1 = 0xfffffff4;
    }
    else {
      iVar3 = yaffs_ReadChunkWithTagsFromNAND
                        (iVar5,*(undefined4 *)(param_1 + 0x28),iVar2,auStack_74);
      if (iVar3 == 1) {
        iVar3 = iVar2 + 0x200;
        if ((*(byte *)(param_1 + 1) & 0x10) == 0) {
          uVar4 = nval_hasvalues(iVar3,iVar6);
          *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xdf | (byte)((uVar4 & 1) << 5) | 0x10;
        }
        if (param_2 == 0) {
          uVar1 = nval_list(iVar3,iVar6,param_3,param_4);
        }
        else {
          uVar1 = nval_get(iVar3,iVar6,param_2,param_3,param_4);
        }
      }
      else {
        uVar1 = 0xfffffffe;
      }
      yaffs_ReleaseTempBuffer(iVar5,iVar2,DAT_30020ca0);
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_ListXAttributes @ 0x3001FFD8  (примерный размер ~40 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 5
 * Вызывает: nval_hasvalues, nval_list, yaffs_GetTempBuffer, yaffs_ReadChunkWithTagsFromNAND, yaffs_ReleaseTempBuffer
 * Константы: 0x3001FFD8, 0x3001FE1C, 0x3001FEC4, 0xFFFFFFB2, 0xFFFFFFF4, 0xFFFFFFFE
 * Данные: DAT_30020c9c, DAT_30020ca0
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x3001fe1c) */
/* WARNING: Removing unreachable block (ram,0x3001fec4) */

undefined4 yaffs_ListXAttributes(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_74 [72];
  
  iVar5 = *(int *)(param_1 + 8);
  iVar6 = *(int *)(iVar5 + 0x9c) + -0x200;
  if (*(int *)(param_1 + 0x28) < 1) {
    uVar1 = 0xffffffb2;
  }
  else if ((*(byte *)(param_1 + 1) & 0x30) == 0x10) {
    uVar1 = 0;
  }
  else {
    iVar2 = yaffs_GetTempBuffer(iVar5,DAT_30020c9c);
    if (iVar2 == 0) {
      uVar1 = 0xfffffff4;
    }
    else {
      iVar3 = yaffs_ReadChunkWithTagsFromNAND
                        (iVar5,*(undefined4 *)(param_1 + 0x28),iVar2,auStack_74);
      if (iVar3 == 1) {
        if ((*(byte *)(param_1 + 1) & 0x10) == 0) {
          uVar4 = nval_hasvalues(iVar2 + 0x200,iVar6);
          *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xdf | (byte)((uVar4 & 1) << 5) | 0x10;
        }
        uVar1 = nval_list(iVar2 + 0x200,iVar6,param_2,param_3);
      }
      else {
        uVar1 = 0xfffffffe;
      }
      yaffs_ReleaseTempBuffer(iVar5,iVar2,DAT_30020ca0);
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_Deinitialise @ 0x3002019C  (примерный размер ~276 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_3001a444, FUN_3001e898, free
 * Вызывают: yaffs_GutsInitialise, yaffs_unmount
 * Константы: 0x3002019C
 * ---------------------------------------------------------------- */
void yaffs_Deinitialise(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xd0) != 0) {
    FUN_3001e898(param_1);
    FUN_3001a444(param_1);
    if ((0 < *(int *)(param_1 + 0x20)) && (*(int *)(param_1 + 0xd98) != 0)) {
      for (iVar1 = 0; iVar1 < *(int *)(param_1 + 0x20); iVar1 = iVar1 + 1) {
        if (*(int *)(*(int *)(param_1 + 0xd98) + iVar1 * 0x1c + 0x18) != 0) {
          free(*(void **)(*(int *)(param_1 + 0xd98) + iVar1 * 0x1c + 0x18));
        }
        *(undefined4 *)(*(int *)(param_1 + 0xd98) + iVar1 * 0x1c + 0x18) = 0;
      }
      free(*(void **)(param_1 + 0xd98));
      *(undefined4 *)(param_1 + 0xd98) = 0;
    }
    free(*(void **)(param_1 + 0xd5c));
    for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
      free(*(void **)(param_1 + iVar1 * 0xc + 0xdb8));
    }
    *(undefined4 *)(param_1 + 0xd0) = 0;
    if (*(int *)(param_1 + 0x50) != 0) {
      (**(code **)(param_1 + 0x50))(param_1);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300202b0 @ 0x300202B0  (примерный размер ~8 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x300202B0
 * ---------------------------------------------------------------- */
undefined4 FUN_300202b0(void)

{
  return 1;
}

/* ----------------------------------------------------------------
 * yaffs_GutsInitialise @ 0x300202B8  (примерный размер ~2104 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 26
 * Вызывает: FUN_30019144, FUN_30019190, FUN_300191cc, FUN_3001a444, FUN_3001beac, FUN_3001d36c, FUN_3001e770, FUN_3001e898, FUN_3001f664, FUN_3001f760, FUN_30020008, FUN_300200d4, FUN_300202b0, FUN_30020c20
 *           ...
 * Вызывают: yaffs_mount
 * Константы: 0xFFFFFFFF, 0x300202B8
 * Данные: DAT_30020a60, DAT_30020cac, DAT_30020cb0, DAT_30020cb4, DAT_30020cb8, DAT_30020cbc, DAT_30020cc0, DAT_30020cc4
 * ---------------------------------------------------------------- */
undefined4 yaffs_GutsInitialise(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  size_t __size;
  uint uVar4;
  bool bVar5;
  
  printf(DAT_30020cac);
  if (param_1 == 0) {
    printf(DAT_30020cb0);
    uVar1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0xe4) = 0;
    *(undefined4 *)(param_1 + 0xe8) = 0;
    *(undefined4 *)(param_1 + 0xd58) = 0;
    *(undefined4 *)(param_1 + 0xd7c) = 0;
    if (*(int *)(param_1 + 0x14) == 0) {
      *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0x14) + 1;
      *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0x18) + 1;
      *(undefined4 *)(param_1 + 0xe4) = 1;
      *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 0xc);
    }
    if (((((((*(int *)(param_1 + 4) == 0) && (*(int *)(param_1 + 0x2c) != 0)) &&
           (*(uint *)(param_1 + 8) < 0x400)) ||
          ((*(int *)(param_1 + 0x2c) == 0 && (*(uint *)(param_1 + 8) < 0x200)))) ||
         ((*(int *)(param_1 + 4) != 0 && (*(int *)(param_1 + 0x2c) == 0)))) ||
        (((*(int *)(param_1 + 0xc) < 2 || (*(int *)(param_1 + 0x1c) < 2)) ||
         (*(int *)(param_1 + 0xdc) < 1)))) ||
       ((*(int *)(param_1 + 0xe0) < 1 ||
        (*(int *)(param_1 + 0xe0) <= *(int *)(param_1 + 0xdc) + *(int *)(param_1 + 0x1c) + 2)))) {
      uVar1 = DAT_30020a60;
      if (*(int *)(param_1 + 0x2c) != 0) {
        uVar1 = DAT_30020cb4;
      }
      printf(DAT_30020cb8,*(undefined4 *)(param_1 + 8),uVar1,*(undefined4 *)(param_1 + 4));
      uVar1 = 0;
    }
    else {
      iVar2 = yaffs_InitialiseNAND(param_1);
      if (iVar2 == 1) {
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 8);
        }
        else {
          *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 8) + -0x10;
        }
        iVar2 = FUN_30020008(param_1);
        if (iVar2 == 0) {
          printf(DAT_30020cc0);
          uVar1 = 0;
        }
        else {
          iVar2 = FUN_300202b0();
          if (iVar2 == 0) {
            printf(DAT_30020cc4);
            uVar1 = 0;
          }
          else if (*(int *)(param_1 + 0xd0) == 0) {
            *(undefined4 *)(param_1 + 0xd0) = 1;
            uVar4 = *(uint *)(param_1 + 0x9c);
            uVar1 = FUN_30019190(uVar4);
            *(undefined4 *)(param_1 + 0xb4) = uVar1;
            *(uint *)(param_1 + 0xb8) = uVar4 >> (*(uint *)(param_1 + 0xb4) & 0xff);
            *(int *)(param_1 + 0xbc) = (1 << (*(uint *)(param_1 + 0xb4) & 0xff)) + -1;
            uVar4 = FUN_30019144((*(int *)(param_1 + 0xe0) + 1) * *(int *)(param_1 + 0xc));
            if (*(int *)(param_1 + 0x78) == 0) {
              uVar4 = uVar4 + (uVar4 & 1);
              if ((int)uVar4 < 0x10) {
                *(undefined4 *)(param_1 + 0xa8) = 0x10;
              }
              else {
                *(uint *)(param_1 + 0xa8) = uVar4;
              }
            }
            else {
              *(undefined4 *)(param_1 + 0xa8) = 0x10;
            }
            *(int *)(param_1 + 0xac) = (1 << (*(uint *)(param_1 + 0xa8) & 0xff)) + -1;
            if (*(uint *)(param_1 + 0xa8) < uVar4) {
              *(short *)(param_1 + 0xa4) = (short)uVar4 - (short)*(undefined4 *)(param_1 + 0xa8);
            }
            else {
              *(undefined2 *)(param_1 + 0xa4) = 0;
            }
            *(uint *)(param_1 + 0xb0) = (uint)(*(int *)(param_1 + 0xa8) << 4) >> 3;
            if (*(uint *)(param_1 + 0xb0) < 0x20) {
              *(undefined4 *)(param_1 + 0xb0) = 0x20;
            }
            *(short *)(param_1 + 0xa6) = (short)(1 << (*(ushort *)(param_1 + 0xa4) & 0xff));
            if (*(int *)(param_1 + 0xc) < (int)(uint)*(ushort *)(param_1 + 0xa6)) {
              printf(DAT_30020ccc);
              uVar1 = 0;
            }
            else {
              *(undefined4 *)(param_1 + 0xe3c) = 0;
              *(undefined4 *)(param_1 + 0xe40) = 0;
              *(undefined4 *)(param_1 + 0xe44) = 0;
              *(undefined4 *)(param_1 + 0xe4c) = 0;
              *(undefined4 *)(param_1 + 0xd6c) = 0;
              *(undefined4 *)(param_1 + 0xd90) = 0xffffffff;
              *(undefined4 *)(param_1 + 0xd94) = 0;
              *(undefined4 *)(param_1 + 0xdac) = 0;
              *(undefined4 *)(param_1 + 0xdb4) = 0;
              *(undefined4 *)(param_1 + 0xdb0) = 0;
              *(undefined4 *)(param_1 + 0xe58) = 0;
              *(undefined4 *)(param_1 + 0xe5c) = 0;
              *(undefined4 *)(param_1 + 0xe60) = 0;
              *(undefined4 *)(param_1 + 0xe64) = 0;
              *(undefined4 *)(param_1 + 0xe34) = 0;
              *(undefined4 *)(param_1 + 0x134) = 0;
              *(undefined4 *)(param_1 + 0xd68) = 0;
              *(undefined4 *)(param_1 + 0xd64) = 1;
              *(int *)(param_1 + 0xe20) = param_1 + 0xe20;
              *(int *)(param_1 + 0xe24) = param_1 + 0xe20;
              *(undefined4 *)(param_1 + 0xe14) = 0;
              *(undefined4 *)(param_1 + 0xe18) = 0;
              iVar2 = FUN_300191cc(param_1);
              bVar5 = iVar2 == 0;
              *(undefined4 *)(param_1 + 0xd98) = 0;
              *(undefined4 *)(param_1 + 0xd5c) = 0;
              if ((!bVar5) && (0 < *(int *)(param_1 + 0x20))) {
                __size = *(int *)(param_1 + 0x20) * 0x1c;
                if (0x14 < *(int *)(param_1 + 0x20)) {
                  *(undefined4 *)(param_1 + 0x20) = 0x14;
                }
                pvVar3 = malloc(__size);
                *(void **)(param_1 + 0xd98) = pvVar3;
                pvVar3 = *(void **)(param_1 + 0xd98);
                if (*(int *)(param_1 + 0xd98) != 0) {
                  memset(*(void **)(param_1 + 0xd98),0,__size);
                }
                iVar2 = 0;
                while ((iVar2 < *(int *)(param_1 + 0x20) && (pvVar3 != (void *)0x0))) {
                  *(undefined4 *)(*(int *)(param_1 + 0xd98) + iVar2 * 0x1c) = 0;
                  *(undefined4 *)(*(int *)(param_1 + 0xd98) + iVar2 * 0x1c + 8) = 0;
                  *(undefined4 *)(*(int *)(param_1 + 0xd98) + iVar2 * 0x1c + 0xc) = 0;
                  pvVar3 = malloc(*(size_t *)(param_1 + 8));
                  *(void **)(*(int *)(param_1 + 0xd98) + iVar2 * 0x1c + 0x18) = pvVar3;
                  iVar2 = iVar2 + 1;
                }
                bVar5 = pvVar3 == (void *)0x0 || bVar5;
                *(undefined4 *)(param_1 + 0xd9c) = 0;
              }
              *(undefined4 *)(param_1 + 0xe74) = 0;
              if (!bVar5) {
                pvVar3 = malloc(*(int *)(param_1 + 0xc) << 2);
                *(void **)(param_1 + 0xd5c) = pvVar3;
                if (*(int *)(param_1 + 0xd5c) == 0) {
                  bVar5 = true;
                }
              }
              if (*(int *)(param_1 + 0x2c) != 0) {
                *(undefined4 *)(param_1 + 0x70) = 1;
              }
              if ((!bVar5) && (iVar2 = FUN_3001e770(param_1), iVar2 == 0)) {
                bVar5 = true;
              }
              FUN_3001d36c(param_1);
              if ((!bVar5) && (iVar2 = FUN_300200d4(param_1), iVar2 == 0)) {
                bVar5 = true;
              }
              print_yaffs_Device(param_1);
              if (!bVar5) {
                if (*(int *)(param_1 + 0x2c) == 0) {
                  iVar2 = yaffs1_Scan(param_1);
                  if (iVar2 == 0) {
                    bVar5 = true;
                  }
                }
                else {
                  iVar2 = yaffs2_CheckpointRestore(param_1);
                  if (iVar2 == 0) {
                    FUN_3001e898(param_1);
                    FUN_3001a444(param_1);
                    *(undefined4 *)(param_1 + 0x134) = 0;
                    *(undefined4 *)(param_1 + 0xd58) = 0;
                    *(undefined4 *)(param_1 + 0x138) = 0xffffffff;
                    *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
                    *(undefined4 *)(param_1 + 0xdac) = 0;
                    *(undefined4 *)(param_1 + 0xdb0) = 0;
                    *(undefined4 *)(param_1 + 0xdb4) = 0;
                    if ((!bVar5) && (iVar2 = FUN_3001e770(param_1), iVar2 == 0)) {
                      bVar5 = true;
                    }
                    FUN_3001d36c(param_1);
                    if ((!bVar5) && (iVar2 = FUN_300200d4(param_1), iVar2 == 0)) {
                      bVar5 = true;
                    }
                    if ((!bVar5) && (iVar2 = yaffs2_ScanBackwards(param_1), iVar2 == 0)) {
                      bVar5 = true;
                    }
                  }
                  else {
                    FUN_3001beac(*(undefined4 *)(param_1 + 0xd88));
                    printf(DAT_30020cd0);
                  }
                }
                FUN_3001f664(param_1);
                FUN_3001f760(param_1);
                if (*(int *)(param_1 + 0x30) != 0) {
                  FUN_30020c20(param_1);
                }
              }
              if (bVar5) {
                printf(DAT_30020cd4);
                yaffs_Deinitialise(param_1);
                uVar1 = 0;
              }
              else {
                *(undefined4 *)(param_1 + 0xe2c) = 0;
                *(undefined4 *)(param_1 + 0xe28) = 0;
                *(undefined4 *)(param_1 + 0xe30) = 0;
                *(undefined4 *)(param_1 + 0xe38) = 0;
                *(undefined4 *)(param_1 + 0xe50) = 0;
                *(undefined4 *)(param_1 + 0xe54) = 0;
                yaffs_VerifyFreeChunks(param_1);
                yaffs_VerifyBlocks(param_1);
                if ((*(int *)(param_1 + 0xd8) == 0) && (0 < *(int *)(param_1 + 0x100))) {
                  yaffs2_InvalidateCheckpoint(param_1);
                }
                print_yaffs_Device(param_1);
                printf(DAT_30020cd8);
                uVar1 = 1;
              }
            }
          }
          else {
            printf(DAT_30020cc8);
            uVar1 = 0;
          }
        }
      }
      else {
        printf(DAT_30020cbc);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_CountFreeChunks @ 0x30020AF0  (примерный размер ~140 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_VerifyFreeChunks
 * Константы: 0x30020AF0
 * ---------------------------------------------------------------- */
int yaffs_CountFreeChunks(int param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar2 = *(uint **)(param_1 + 0x124);
  for (iVar3 = *(int *)(param_1 + 0xdc); iVar3 <= *(int *)(param_1 + 0xe0); iVar3 = iVar3 + 1) {
    uVar1 = *puVar2 >> 0x14 & 0xf;
    if ((((uVar1 == 3) || (uVar1 == 4)) || (uVar1 == 5)) || (uVar1 == 8)) {
      iVar4 = iVar4 + (*(int *)(param_1 + 0xc) - ((*puVar2 << 0xc) >> 0x16)) + (*puVar2 & 0x3ff);
    }
    puVar2 = puVar2 + 2;
  }
  return iVar4;
}

/* ----------------------------------------------------------------
 * yaffs_GetNumberOfFreeChunks @ 0x30020B7C  (примерный размер ~164 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: yaffs2_CalcCheckpointBlocksRequired
 * Вызывают: yaffs_freespace
 * Константы: 0x30020B7C
 * ---------------------------------------------------------------- */
int yaffs_GetNumberOfFreeChunks(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0xd58);
  iVar4 = *(int *)(param_1 + 0xdac);
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < *(int *)(param_1 + 0x20); iVar2 = iVar2 + 1) {
    iVar3 = iVar3 + (uint)(*(int *)(*(int *)(param_1 + 0xd98) + iVar2 * 0x1c + 0xc) != 0);
  }
  iVar5 = *(int *)(param_1 + 0x1c);
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = yaffs2_CalcCheckpointBlocksRequired(param_1);
  iVar2 = (((iVar6 + iVar4) - iVar3) - iVar1 * (iVar5 + 1)) - *(int *)(param_1 + 0xc) * iVar2;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_30020c20 @ 0x30020C20  (примерный размер ~20 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3001f8d0
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x30020C20
 * ---------------------------------------------------------------- */
void FUN_30020c20(int param_1)

{
  FUN_3001f8d0(*(undefined4 *)(param_1 + 0xd8c));
  return;
}

/* ----------------------------------------------------------------
 * FUN_30020c34 @ 0x30020C34  (примерный размер ~36 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: strncpy
 * Вызывают: yaffs_GetObjectName
 * Константы: 0x30020C34
 * ---------------------------------------------------------------- */
void FUN_30020c34(undefined4 param_1,char *param_2,char *param_3,int param_4)

{
  strncpy(param_2,param_3,param_4 - 1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30020c58 @ 0x30020C58  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: strncpy
 * Вызывают: yaffs_UpdateObjectHeader
 * Константы: 0x30020C58
 * ---------------------------------------------------------------- */
void FUN_30020c58(undefined4 param_1,char *param_2,char *param_3)

{
  strncpy(param_2,param_3,0xfe);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30020c78 @ 0x30020C78  (примерный размер ~4 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_DeleteChunk
 * Константы: 0x30020C78
 * ---------------------------------------------------------------- */
void FUN_30020c78(void)

{
  return;
}

/* ----------------------------------------------------------------
 * FUN_30020c7c @ 0x30020C7C  (примерный размер ~96 байт)
 * Модуль: flash | Вызывают: 7 | Вызывает: 0
 * Вызывают: FUN_3001aba4, FUN_3001ac00, FUN_3001ddb4, FUN_3001df80, FUN_3001e3e4, yaffs_RenameObject, yaffs_UpdateDirtyDirectories
 * Константы: 0x30020C7C
 * ---------------------------------------------------------------- */
bool FUN_30020c7c(int *param_1)

{
  return (int *)*param_1 == param_1;
}

/* ----------------------------------------------------------------
 * FUN_30020cdc @ 0x30020CDC  (примерный размер ~128 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: yaffs_ReadChunkWithTagsFromNAND
 * Константы: 0x30020CDC
 * Данные: DAT_300210a0, DAT_300210a4
 * ---------------------------------------------------------------- */
int FUN_30020cdc(int param_1,int param_2)

{
  if ((param_2 < *(int *)(param_1 + 0xdc)) || (*(int *)(param_1 + 0xe0) < param_2)) {
    printf(DAT_300210a0,param_2);
    printf(DAT_300210a4,0x1e);
  }
  return *(int *)(param_1 + 0x124) + (param_2 - *(int *)(param_1 + 0xdc)) * 8;
}

/* ----------------------------------------------------------------
 * yaffs_ReadChunkWithTagsFromNAND @ 0x30020D5C  (примерный размер ~204 байт)
 * Модуль: flash | Вызывают: 15 | Вызывает: 4
 * Вызывает: FUN_30020cdc, __div32, yaffs_HandleChunkError, yaffs_TagsCompatabilityReadChunkWithTagsFromNAND
 * Вызывают: FUN_300195b0, FUN_30019658, FUN_3001a908, FUN_3001b01c, FUN_3001beac, FUN_3001d720, yaffs1_Scan, yaffs2_ScanBackwards, yaffs_GetObjectName, yaffs_GetXAttribute
 *           ...
 * Константы: 0x30020D5C
 * ---------------------------------------------------------------- */
undefined4
yaffs_ReadChunkWithTagsFromNAND(int param_1,int param_2,undefined4 param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_68 [72];
  
  iVar3 = param_2 - *(int *)(param_1 + 0xe8);
  *(int *)(param_1 + 0xe2c) = *(int *)(param_1 + 0xe2c) + 1;
  if (param_4 == (undefined1 *)0x0) {
    param_4 = auStack_68;
  }
  if (*(int *)(param_1 + 0x58) == 0) {
    uVar1 = yaffs_TagsCompatabilityReadChunkWithTagsFromNAND(param_1,iVar3,param_3,param_4);
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x58))(param_1,iVar3,param_3,param_4);
  }
  if ((param_4 != (undefined1 *)0x0) && (1 < *(int *)(param_4 + 0x14))) {
    uVar2 = __div32(param_2,*(undefined4 *)(param_1 + 0xc));
    uVar2 = FUN_30020cdc(param_1,uVar2);
    yaffs_HandleChunkError(param_1,uVar2);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_WriteChunkWithTagsToNAND @ 0x30020E28  (примерный размер ~316 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 3
 * Вызывает: printf, yaffs_TagsCompatabilityWriteChunkWithTagsToNAND, yaffs_ValidateTags
 * Вызывают: FUN_3001a0fc, yaffs_DeleteChunk
 * Константы: 0x30020E28
 * Данные: DAT_3002109c, DAT_300210a8, DAT_300210ac, DAT_300210b0, DAT_300210b4
 * ---------------------------------------------------------------- */
void yaffs_WriteChunkWithTagsToNAND(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  *(int *)(param_1 + 0xe28) = *(int *)(param_1 + 0xe28) + 1;
  param_2 = param_2 - *(int *)(param_1 + 0xe8);
  if (param_4 == 0) {
    printf(DAT_300210b4);
    printf(DAT_300210ac,0x4f);
  }
  else {
    *(undefined4 *)(param_4 + 0x24) = *(undefined4 *)(param_1 + 0xe10);
    *(undefined4 *)(param_4 + 4) = 1;
    iVar1 = yaffs_ValidateTags(param_4);
    if (iVar1 == 0) {
      printf(DAT_300210a8);
      printf(DAT_300210ac,0x48);
    }
    if ((*DAT_3002109c & 0x80) != 0) {
      printf(DAT_300210b0,param_2,*(undefined4 *)(param_4 + 8),*(undefined4 *)(param_4 + 0xc));
    }
  }
  if (*(int *)(param_1 + 0x54) == 0) {
    yaffs_TagsCompatabilityWriteChunkWithTagsToNAND(param_1,param_2,param_3,param_4);
  }
  else {
    (**(code **)(param_1 + 0x54))(param_1,param_2,param_3,param_4);
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_MarkBlockBad @ 0x30020F64  (примерный размер ~80 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: yaffs_TagsCompatabilityMarkNANDBlockBad
 * Вызывают: FUN_300197f0
 * Константы: 0x30020F64
 * ---------------------------------------------------------------- */
void yaffs_MarkBlockBad(int param_1,int param_2)

{
  param_2 = param_2 - *(int *)(param_1 + 0xe4);
  if (*(int *)(param_1 + 0x5c) == 0) {
    yaffs_TagsCompatabilityMarkNANDBlockBad(param_1,param_2);
  }
  else {
    (**(code **)(param_1 + 0x5c))(param_1,param_2);
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_QueryInitialBlockState @ 0x30020FB4  (примерный размер ~104 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 1
 * Вызывает: yaffs_TagsCompatabilityQueryNANDBlock
 * Вызывают: yaffs1_Scan, yaffs2_ScanBackwards
 * Константы: 0x30020FB4
 * ---------------------------------------------------------------- */
void yaffs_QueryInitialBlockState(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  param_2 = param_2 - *(int *)(param_1 + 0xe4);
  if (*(int *)(param_1 + 0x60) == 0) {
    yaffs_TagsCompatabilityQueryNANDBlock(param_1,param_2,param_3,param_4);
  }
  else {
    (**(code **)(param_1 + 0x60))(param_1,param_2,param_3,param_4);
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_EraseBlockInNAND @ 0x3002101C  (примерный размер ~72 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300197f0, yaffs_BlockBecameDirty
 * Константы: 0x3002101C
 * ---------------------------------------------------------------- */
undefined4 yaffs_EraseBlockInNAND(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + 1;
  uVar1 = (**(code **)(param_1 + 0x48))(param_1,param_2 - *(int *)(param_1 + 0xe4));
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_InitialiseNAND @ 0x30021064  (примерный размер ~84 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_GutsInitialise
 * Константы: 0x30021064
 * ---------------------------------------------------------------- */
undefined4 yaffs_InitialiseNAND(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x4c))(param_1);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300210b8 @ 0x300210B8  (примерный размер ~64 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: FUN_3002145c, yaffs_PackTags2TagsPart, yaffs_UnpackTags2TagsPart
 * Константы: 0x300210B8
 * Данные: DAT_30021470, DAT_30021474
 * ---------------------------------------------------------------- */
void FUN_300210b8(undefined4 *param_1)

{
  if ((*DAT_30021470 & 0x4000) != 0) {
    printf(DAT_30021474,param_1[1],param_1[2],param_1[3],*param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300210f8 @ 0x300210F8  (примерный размер ~104 байт)
 * Модуль: flash | Вызывают: 3 | Вызывает: 1
 * Вызывает: printf
 * Вызывают: yaffs_PackTags2TagsPart, yaffs_UnpackTags2, yaffs_UnpackTags2TagsPart
 * Константы: 0x300210F8
 * Данные: DAT_30021470, DAT_30021478
 * ---------------------------------------------------------------- */
void FUN_300210f8(int param_1)

{
  if ((*DAT_30021470 & 0x4000) != 0) {
    printf(DAT_30021478,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
           *(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
           *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x1c),
           *(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24));
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_PackTags2TagsPart @ 0x30021160  (примерный размер ~236 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300210b8, FUN_300210f8
 * Вызывают: yaffs_PackTags2
 * Константы: 0x30021160, 0x80000000, 0x40000000, 0x20000000, 0x0FFFFFFF
 * ---------------------------------------------------------------- */
void yaffs_PackTags2TagsPart(undefined4 *param_1,int param_2)

{
  param_1[2] = *(undefined4 *)(param_2 + 0xc);
  *param_1 = *(undefined4 *)(param_2 + 0x24);
  param_1[3] = *(undefined4 *)(param_2 + 0x10);
  param_1[1] = *(undefined4 *)(param_2 + 8);
  if ((*(int *)(param_2 + 0xc) == 0) && (*(int *)(param_2 + 0x28) != 0)) {
    param_1[2] = *(uint *)(param_2 + 0x2c) | 0x80000000;
    if (*(int *)(param_2 + 0x30) != 0) {
      param_1[2] = param_1[2] | 0x40000000;
    }
    if (*(int *)(param_2 + 0x34) != 0) {
      param_1[2] = param_1[2] | 0x20000000;
    }
    param_1[1] = param_1[1] & 0xfffffff;
    param_1[1] = param_1[1] | *(int *)(param_2 + 0x38) << 0x1c;
    if (*(int *)(param_2 + 0x38) == 4) {
      param_1[3] = *(undefined4 *)(param_2 + 0x40);
    }
    else if (*(int *)(param_2 + 0x38) == 1) {
      param_1[3] = *(undefined4 *)(param_2 + 0x3c);
    }
    else {
      param_1[3] = 0;
    }
  }
  FUN_300210b8(param_1);
  FUN_300210f8(param_2);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_PackTags2 @ 0x3002124C  (примерный размер ~60 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: yaffs_ECCCalculateOther, yaffs_PackTags2TagsPart
 * Вызывают: yaffs_TagsCompatabilityWriteChunkWithTagsToNAND
 * Константы: 0x3002124C
 * ---------------------------------------------------------------- */
void yaffs_PackTags2(int param_1,undefined4 param_2,int param_3)

{
  yaffs_PackTags2TagsPart(param_1,param_2);
  if (param_3 != 0) {
    yaffs_ECCCalculateOther(param_1,0x10,param_1 + 0x10);
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_UnpackTags2TagsPart @ 0x30021288  (примерный размер ~276 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300210b8, FUN_300210f8, memset, yaffs_InitialiseTags
 * Вызывают: yaffs_UnpackTags2
 * Константы: 0x0FFFFFFF, 0x30021288
 * ---------------------------------------------------------------- */
void yaffs_UnpackTags2TagsPart(void *param_1,int *param_2)

{
  memset(param_1,0,0x48);
  yaffs_InitialiseTags(param_1);
  if (*param_2 != -1) {
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    *(undefined4 *)((int)param_1 + 4) = 1;
    *(int *)((int)param_1 + 8) = param_2[1];
    *(int *)((int)param_1 + 0xc) = param_2[2];
    *(int *)((int)param_1 + 0x10) = param_2[3];
    *(undefined4 *)((int)param_1 + 0x1c) = 0;
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    *(int *)((int)param_1 + 0x24) = *param_2;
    if ((param_2[2] & 0x80000000U) != 0) {
      *(undefined4 *)((int)param_1 + 0xc) = 0;
      *(undefined4 *)((int)param_1 + 0x10) = 0;
      *(undefined4 *)((int)param_1 + 0x28) = 1;
      *(uint *)((int)param_1 + 0x2c) = param_2[2] & 0xfffffff;
      *(uint *)((int)param_1 + 0x30) = (uint)param_2[2] >> 0x1e & 1;
      *(uint *)((int)param_1 + 0x34) = (uint)param_2[2] >> 0x1d & 1;
      *(uint *)((int)param_1 + 0x38) = (uint)param_2[1] >> 0x1c;
      *(uint *)((int)param_1 + 8) = *(uint *)((int)param_1 + 8) & 0xfffffff;
      if (*(int *)((int)param_1 + 0x38) == 4) {
        *(int *)((int)param_1 + 0x40) = param_2[3];
      }
      else {
        *(int *)((int)param_1 + 0x3c) = param_2[3];
      }
    }
  }
  FUN_300210b8(param_2);
  FUN_300210f8(param_1);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_UnpackTags2 @ 0x3002139C  (примерный размер ~192 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300210f8, FUN_3002145c, yaffs_ECCCalculateOther, yaffs_ECCCorrectOther, yaffs_UnpackTags2TagsPart
 * Вызывают: yaffs_TagsCompatabilityReadChunkWithTagsFromNAND
 * Константы: 0x3002139C
 * ---------------------------------------------------------------- */
void yaffs_UnpackTags2(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_24 [12];
  
  uVar2 = 1;
  if ((*param_2 != -1) && (param_3 != 0)) {
    yaffs_ECCCalculateOther(param_2,0x10,auStack_24);
    iVar1 = yaffs_ECCCorrectOther(param_2,0x10,param_2 + 4,auStack_24);
    if (iVar1 == -1) {
      uVar2 = 3;
    }
    else if (iVar1 == 0) {
      uVar2 = 1;
    }
    else if (iVar1 == 1) {
      uVar2 = 2;
    }
    else {
      uVar2 = 0;
    }
  }
  yaffs_UnpackTags2TagsPart(param_1,param_2);
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  FUN_3002145c(param_2);
  FUN_300210f8(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3002145c @ 0x3002145C  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_300210b8
 * Вызывают: yaffs_UnpackTags2
 * Константы: 0x3002145C
 * ---------------------------------------------------------------- */
void FUN_3002145c(undefined4 param_1)

{
  FUN_300210b8(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3002147c @ 0x3002147C  (примерный размер ~148 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_qsort
 * Константы: 0x3002147C
 * ---------------------------------------------------------------- */
void FUN_3002147c(undefined4 *param_1,undefined4 *param_2,uint param_3,int param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if (param_4 < 2) {
    param_3 = param_3 >> 2;
    do {
      uVar2 = *param_1;
      *param_1 = *param_2;
      param_1 = param_1 + 1;
      *param_2 = uVar2;
      param_3 = param_3 - 1;
      param_2 = param_2 + 1;
    } while (0 < (int)param_3);
  }
  else {
    do {
      uVar1 = *(undefined1 *)param_1;
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_2 = uVar1;
      param_3 = param_3 - 1;
      param_2 = (undefined4 *)((int)param_2 + 1);
    } while (0 < (int)param_3);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30021510 @ 0x30021510  (примерный размер ~220 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_qsort
 * Константы: 0x30021510
 * ---------------------------------------------------------------- */
undefined4 FUN_30021510(undefined4 param_1,undefined4 param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  
  iVar1 = (*param_4)(param_1,param_2);
  if (iVar1 < 0) {
    iVar1 = (*param_4)(param_2,param_3);
    if ((-1 < iVar1) && (iVar1 = (*param_4)(param_1,param_3), param_2 = param_1, iVar1 < 0)) {
      param_2 = param_3;
    }
  }
  else {
    iVar1 = (*param_4)(param_2,param_3);
    if ((iVar1 < 1) && (iVar1 = (*param_4)(param_1,param_3), param_2 = param_1, -1 < iVar1)) {
      param_2 = param_3;
    }
  }
  return param_2;
}

/* ----------------------------------------------------------------
 * yaffs_qsort @ 0x300215EC  (примерный размер ~1452 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_3002147c, FUN_30021510, __udiv32
 * Вызывают: yaffs2_ScanBackwards
 * Константы: 0x300215EC
 * ---------------------------------------------------------------- */
void yaffs_qsort(undefined4 *param_1,uint param_2,uint param_3,code *param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int local_5c;
  undefined4 *local_58;
  undefined4 *local_54;
  undefined4 *local_50;
  uint local_4;
  
  local_4 = param_2;
  while( true ) {
    if ((((uint)param_1 & 3) == 0) && ((param_3 & 3) == 0)) {
      if (param_3 == 4) {
        iVar6 = 0;
      }
      else {
        iVar6 = 1;
      }
    }
    else {
      iVar6 = 2;
    }
    bVar1 = false;
    local_58 = param_1;
    if (local_4 < 7) {
      while (local_58 = (undefined4 *)((int)local_58 + param_3), puVar3 = local_58,
            local_58 < (undefined4 *)(local_4 * param_3 + (int)param_1)) {
        while ((param_1 < puVar3 && (iVar2 = (*param_4)((int)puVar3 - param_3,puVar3), 0 < iVar2)))
        {
          if (iVar6 == 0) {
            uVar7 = *puVar3;
            *puVar3 = *(undefined4 *)((int)puVar3 - param_3);
            *(undefined4 *)((int)puVar3 - param_3) = uVar7;
          }
          else {
            FUN_3002147c(puVar3,(int)puVar3 - param_3,param_3,iVar6);
          }
          puVar3 = (undefined4 *)((int)puVar3 - param_3);
        }
      }
      return;
    }
    local_58 = (undefined4 *)(param_3 * (local_4 >> 1) + (int)param_1);
    if (7 < local_4) {
      local_50 = (undefined4 *)(param_3 * (local_4 - 1) + (int)param_1);
      puVar3 = param_1;
      if (0x28 < local_4) {
        iVar2 = (local_4 >> 3) * param_3;
        puVar3 = (undefined4 *)
                 FUN_30021510(param_1,(undefined4 *)((int)param_1 + iVar2),(int)param_1 + iVar2 * 2,
                              param_4);
        local_58 = (undefined4 *)
                   FUN_30021510((int)local_58 - iVar2,local_58,(undefined4 *)((int)local_58 + iVar2)
                                ,param_4);
        local_50 = (undefined4 *)
                   FUN_30021510((int)local_50 + iVar2 * -2,(int)local_50 - iVar2,local_50,param_4);
      }
      local_58 = (undefined4 *)FUN_30021510(puVar3,local_58,local_50,param_4);
    }
    if (iVar6 == 0) {
      uVar7 = *param_1;
      *param_1 = *local_58;
      *local_58 = uVar7;
    }
    else {
      FUN_3002147c(param_1,local_58,param_3,iVar6);
    }
    puVar5 = (undefined4 *)((int)param_1 + param_3);
    puVar4 = (undefined4 *)(param_3 * (local_4 - 1) + (int)param_1);
    puVar3 = puVar4;
    local_54 = puVar5;
    while( true ) {
      while ((puVar5 <= puVar3 && (iVar2 = (*param_4)(puVar5,param_1), iVar2 < 1))) {
        if (iVar2 == 0) {
          bVar1 = true;
          if (iVar6 == 0) {
            uVar7 = *local_54;
            *local_54 = *puVar5;
            *puVar5 = uVar7;
          }
          else {
            FUN_3002147c(local_54,puVar5,param_3,iVar6);
          }
          local_54 = (undefined4 *)((int)local_54 + param_3);
        }
        puVar5 = (undefined4 *)((int)puVar5 + param_3);
      }
      while ((puVar5 <= puVar3 && (iVar2 = (*param_4)(puVar3,param_1), -1 < iVar2))) {
        if (iVar2 == 0) {
          bVar1 = true;
          if (iVar6 == 0) {
            uVar7 = *puVar3;
            *puVar3 = *puVar4;
            *puVar4 = uVar7;
          }
          else {
            FUN_3002147c(puVar3,puVar4,param_3,iVar6);
          }
          puVar4 = (undefined4 *)((int)puVar4 - param_3);
        }
        puVar3 = (undefined4 *)((int)puVar3 - param_3);
      }
      if (puVar3 < puVar5) break;
      if (iVar6 == 0) {
        uVar7 = *puVar5;
        *puVar5 = *puVar3;
        *puVar3 = uVar7;
      }
      else {
        FUN_3002147c(puVar5,puVar3,param_3,iVar6);
      }
      bVar1 = true;
      puVar5 = (undefined4 *)((int)puVar5 + param_3);
      puVar3 = (undefined4 *)((int)puVar3 - param_3);
    }
    local_58 = param_1;
    if (!bVar1) break;
    iVar2 = local_4 * param_3;
    if ((int)local_54 - (int)param_1 < (int)puVar5 - (int)local_54) {
      local_5c = (int)local_54 - (int)param_1;
    }
    else {
      local_5c = (int)puVar5 - (int)local_54;
    }
    if (0 < local_5c) {
      FUN_3002147c(param_1,(int)puVar5 - local_5c,local_5c,iVar6);
    }
    if ((int)puVar4 - (int)puVar3 < (int)((int)param_1 + ((iVar2 - (int)puVar4) - param_3))) {
      local_5c = (int)puVar4 - (int)puVar3;
    }
    else {
      local_5c = (int)param_1 + ((iVar2 - (int)puVar4) - param_3);
    }
    if (0 < local_5c) {
      FUN_3002147c(puVar5,(int)param_1 + (iVar2 - local_5c),local_5c,iVar6);
    }
    if (param_3 < (uint)((int)puVar5 - (int)local_54)) {
      uVar7 = __udiv32((int)puVar5 - (int)local_54,param_3);
      yaffs_qsort(param_1,uVar7,param_3,param_4);
    }
    uVar8 = (int)puVar4 - (int)puVar3;
    if (uVar8 <= param_3) {
      return;
    }
    param_1 = (undefined4 *)((int)param_1 + (iVar2 - uVar8));
    local_4 = __udiv32(uVar8,param_3);
  }
  while (local_58 = (undefined4 *)((int)local_58 + param_3), puVar3 = local_58,
        local_58 < (undefined4 *)(local_4 * param_3 + (int)param_1)) {
    while ((param_1 < puVar3 && (iVar2 = (*param_4)((int)puVar3 - param_3,puVar3), 0 < iVar2))) {
      if (iVar6 == 0) {
        uVar7 = *puVar3;
        *puVar3 = *(undefined4 *)((int)puVar3 - param_3);
        *(undefined4 *)((int)puVar3 - param_3) = uVar7;
      }
      else {
        FUN_3002147c(puVar3,(int)puVar3 - param_3,param_3,iVar6);
      }
      puVar3 = (undefined4 *)((int)puVar3 - param_3);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_CountBits @ 0x30021B98  (примерный размер ~32 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30021B98
 * Данные: DAT_300220b8
 * ---------------------------------------------------------------- */
int yaffs_CountBits(uint param_1)

{
  return (int)*(char *)(DAT_300220b8 + (param_1 & 0xff));
}

/* ----------------------------------------------------------------
 * yaffs_CalcECC @ 0x30021BB8  (примерный размер ~52 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: yaffs_ECCCalculate
 * Константы: 0x30021BB8
 * ---------------------------------------------------------------- */
void yaffs_CalcECC(int param_1,int param_2)

{
  yaffs_ECCCalculate(param_1,param_2 + 8);
  yaffs_ECCCalculate(param_1 + 0x100,param_2 + 0xd);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_CalcTagsECC @ 0x30021BEC  (примерный размер ~136 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_CheckECCOnTags
 * Константы: 0x30021BEC
 * Данные: DAT_300220bc, DAT_300220c0
 * ---------------------------------------------------------------- */
void yaffs_CalcTagsECC(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = 0;
  uVar1 = 0;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & DAT_300220bc;
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {
    for (uVar3 = 1; (uVar3 & 0xff) != 0; uVar3 = uVar3 << 1) {
      uVar1 = uVar1 + 1;
      if ((uVar3 & *(byte *)(param_1 + uVar4)) != 0) {
        uVar2 = uVar2 ^ uVar1;
      }
    }
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & DAT_300220bc | (uVar2 & DAT_300220c0) << 0x12;
  }
  return;
}

/* ----------------------------------------------------------------
 * yaffs_CheckECCOnTags @ 0x30021C74  (примерный размер ~136 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 1
 * Вызывает: yaffs_CalcTagsECC
 * Константы: 0x30021C74, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 yaffs_CheckECCOnTags(int param_1)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 4);
  yaffs_CalcTagsECC(param_1);
  uVar3 = ((uVar3 ^ *(uint *)(param_1 + 4)) << 2) >> 0x14;
  if ((uVar3 == 0) || (0x40 < uVar3)) {
    if (uVar3 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    pbVar2 = (byte *)(param_1 + (uVar3 - 1 >> 3));
    *pbVar2 = *pbVar2 ^ (byte)(1 << (uVar3 - 1 & 7));
    yaffs_CalcTagsECC(param_1);
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffs_LoadTagsIntoSpare @ 0x30021CFC  (примерный размер ~228 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_TagsCompatabilityWriteChunkWithTagsToNAND
 * Константы: 0x30021CFC
 * ---------------------------------------------------------------- */
void yaffs_LoadTagsIntoSpare(undefined1 *param_1,undefined4 *param_2)

{
  *param_1 = (char)*param_2;
  param_1[1] = (char)((uint)*param_2 >> 8);
  param_1[2] = (char)*(undefined2 *)((int)param_2 + 2);
  param_1[3] = *(undefined1 *)((int)param_2 + 3);
  param_1[4] = (char)param_2[1];
  param_1[5] = (char)((uint)param_2[1] >> 8);
  param_1[6] = (char)*(undefined2 *)((int)param_2 + 6);
  param_1[7] = *(undefined1 *)((int)param_2 + 7);
  param_1[8] = (char)param_2[2];
  param_1[9] = (char)((uint)param_2[2] >> 8);
  param_1[10] = (char)*(undefined2 *)((int)param_2 + 10);
  param_1[0xb] = *(undefined1 *)((int)param_2 + 0xb);
  param_1[0xc] = (char)param_2[3];
  param_1[0xd] = (char)((uint)param_2[3] >> 8);
  param_1[0xe] = (char)*(undefined2 *)((int)param_2 + 0xe);
  param_1[0xf] = *(undefined1 *)((int)param_2 + 0xf);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_GetTagsFromSpare @ 0x30021DE0  (примерный размер ~164 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_TagsCompatabilityReadChunkWithTagsFromNAND
 * Константы: 0x01000000, 0x30021DE0
 * ---------------------------------------------------------------- */
void yaffs_GetTagsFromSpare(byte *param_1,int *param_2)

{
  *param_2 = (uint)param_1[3] * 0x1000000 + (uint)param_1[2] * 0x10000 + (uint)param_1[1] * 0x100 +
             (uint)*param_1;
  param_2[1] = (uint)param_1[7] * 0x1000000 + (uint)param_1[6] * 0x10000 + (uint)param_1[5] * 0x100
               + (uint)param_1[4];
  param_2[2] = (uint)param_1[0xb] * 0x1000000 + (uint)param_1[10] * 0x10000 +
               (uint)param_1[9] * 0x100 + (uint)param_1[8];
  param_2[3] = (uint)param_1[0xf] * 0x1000000 + (uint)param_1[0xe] * 0x10000 +
               (uint)param_1[0xd] * 0x100 + (uint)param_1[0xc];
  return;
}

/* ----------------------------------------------------------------
 * nand_assert @ 0x30021E84  (примерный размер ~16 байт)
 * Модуль: flash | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30021E84
 * ---------------------------------------------------------------- */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nand_assert(void)

{
  _Reset = 0;
  return;
}

/* ----------------------------------------------------------------
 * yaffs_TagsCompatabilityWriteChunkWithTagsToNAND @ 0x30021E94  (примерный размер ~164 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 3
 * Вызывает: memset, yaffs_LoadTagsIntoSpare, yaffs_PackTags2
 * Вызывают: yaffs_WriteChunkWithTagsToNAND
 * Константы: 0x30021E94
 * ---------------------------------------------------------------- */
void yaffs_TagsCompatabilityWriteChunkWithTagsToNAND
               (int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined1 auStack_30 [28];
  
  memset(auStack_30,0xff,0x1c);
  memset((void *)(param_1 + 0xc0),0xff,0x10);
  if (param_4 != 0) {
    yaffs_PackTags2(auStack_30,param_4);
    yaffs_LoadTagsIntoSpare(param_1 + 0xc0,auStack_30);
  }
  (**(code **)(param_1 + 0x40))(param_1,param_2,param_3,param_1 + 0xc0);
  return;
}

/* ----------------------------------------------------------------
 * yaffs_TagsCompatabilityReadChunkWithTagsFromNAND @ 0x30021F38  (примерный размер ~168 байт)
 * Модуль: flash | Вызывают: 2 | Вызывает: 3
 * Вызывает: memset, yaffs_GetTagsFromSpare, yaffs_UnpackTags2
 * Вызывают: yaffs_ReadChunkWithTagsFromNAND, yaffs_TagsCompatabilityQueryNANDBlock
 * Константы: 0x30021F38
 * ---------------------------------------------------------------- */
undefined4
yaffs_TagsCompatabilityReadChunkWithTagsFromNAND
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_34 [28];
  
  memset(auStack_34,0xff,0x1c);
  iVar1 = (**(code **)(param_1 + 0x44))(param_1,param_2,param_3,param_1 + 0xc0);
  if (iVar1 == 1) {
    if (param_4 != 0) {
      yaffs_GetTagsFromSpare(param_1 + 0xc0,auStack_34);
      yaffs_UnpackTags2(param_4,auStack_34);
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * yaffs_TagsCompatabilityMarkNANDBlockBad @ 0x30021FE0  (примерный размер ~24 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 1
 * Вызывает: nand_bad
 * Вызывают: yaffs_MarkBlockBad
 * Константы: 0x30021FE0
 * ---------------------------------------------------------------- */
undefined4 yaffs_TagsCompatabilityMarkNANDBlockBad(undefined4 param_1,undefined4 param_2)

{
  nand_bad(param_2);
  return 1;
}

/* ----------------------------------------------------------------
 * yaffs_TagsCompatabilityQueryNANDBlock @ 0x30021FF8  (примерный размер ~204 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 2
 * Вызывает: nand_isbad, yaffs_TagsCompatabilityReadChunkWithTagsFromNAND
 * Вызывают: yaffs_QueryInitialBlockState
 * Константы: 0x30021FF8
 * ---------------------------------------------------------------- */
bool yaffs_TagsCompatabilityQueryNANDBlock(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int local_64;
  undefined1 auStack_60 [4];
  int local_5c;
  undefined4 local_3c;
  
  local_64 = 0;
  iVar1 = nand_isbad(param_2,&local_64);
  if ((iVar1 == 0) && (local_64 != 1)) {
    yaffs_TagsCompatabilityReadChunkWithTagsFromNAND
              (param_1,*(int *)(param_1 + 0xc) * param_2,0,auStack_60);
    if (local_5c == 0) {
      *param_4 = 0;
      *param_3 = 3;
    }
    else {
      *param_4 = local_3c;
      *param_3 = 2;
    }
  }
  else {
    *param_3 = 9;
    *param_4 = 0;
  }
  return *param_3 != 9;
}

/* ----------------------------------------------------------------
 * yaffs_InitialiseTags @ 0x300220C4  (примерный размер ~44 байт)
 * Модуль: flash | Вызывают: 6 | Вызывает: 1
 * Вызывает: memset
 * Вызывают: FUN_300197f0, FUN_3001b01c, FUN_3001d45c, yaffs_DeleteChunk, yaffs_UnpackTags2TagsPart, yaffs_UpdateObjectHeader
 * Константы: 0x300220C4
 * Данные: DAT_30022130, DAT_30022134
 * ---------------------------------------------------------------- */
void yaffs_InitialiseTags(undefined4 *param_1)

{
  memset(param_1,0,0x48);
  *param_1 = DAT_30022130;
  param_1[0x11] = DAT_30022134;
  return;
}

/* ----------------------------------------------------------------
 * yaffs_ValidateTags @ 0x300220F0  (примерный размер ~72 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_WriteChunkWithTagsToNAND
 * Константы: 0x300220F0
 * Данные: DAT_30022130, DAT_30022134
 * ---------------------------------------------------------------- */
undefined4 yaffs_ValidateTags(int *param_1)

{
  undefined4 uVar1;
  
  if ((*param_1 == DAT_30022130) && (param_1[0x11] == DAT_30022134)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * yaffsfs_LocalInitialisation @ 0x30022138  (примерный размер ~4 байт)
 * Модуль: flash | Вызывают: 1 | Вызывает: 0
 * Вызывают: yaffs_StartUp
 * Константы: 0x30022138
 * ---------------------------------------------------------------- */
void yaffsfs_LocalInitialisation(void)

{
  return;
}

