/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : lib — libc/математика/криптография/компрессия (AES, zlib-подобный QC_*)
 * Часть  : 1 (функций: 150, адреса 0x300041C4..0x300B0DBC)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * __rt_memcpy @ 0x300041C4  (примерный размер ~304 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300041C4
 * ---------------------------------------------------------------- */
undefined8 __rt_memcpy(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint *puVar2;
  byte *pbVar3;
  byte bVar4;
  byte bVar5;
  uint unaff_r5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  
  if (3 < param_3) {
    uVar6 = (uint)param_1 & 3;
    unaff_r5 = uVar6;
    if (uVar6 != 0) {
      bVar4 = (byte)*param_2;
      puVar2 = (uint *)((int)param_2 + 1);
      if (uVar6 < 3) {
        puVar2 = (uint *)((int)param_2 + 2);
        unaff_r5 = (uint)*(byte *)((int)param_2 + 1);
      }
      *(byte *)param_1 = bVar4;
      param_2 = puVar2;
      if (uVar6 < 2) {
        param_2 = (uint *)((int)puVar2 + 1);
        bVar4 = (byte)*puVar2;
      }
      param_3 = (param_3 + uVar6) - 4;
      puVar2 = (uint *)((int)param_1 + 1);
      if (uVar6 < 3) {
        puVar2 = (uint *)((int)param_1 + 2);
        *(byte *)((int)param_1 + 1) = (byte)unaff_r5;
      }
      param_1 = puVar2;
      if (uVar6 < 2) {
        param_1 = (uint *)((int)puVar2 + 1);
        *(byte *)puVar2 = bVar4;
      }
    }
    param_4 = (uint)param_2 & 3;
    if (param_4 == 0) {
      bVar9 = 0x1f < param_3;
      param_3 = param_3 - 0x20;
      if (bVar9) {
        do {
          if (bVar9) {
            uVar6 = param_2[1];
            uVar7 = param_2[2];
            uVar8 = param_2[3];
            *param_1 = *param_2;
            param_1[1] = uVar6;
            param_1[2] = uVar7;
            param_1[3] = uVar8;
            param_4 = param_2[4];
            uVar6 = param_2[5];
            uVar7 = param_2[6];
            uVar8 = param_2[7];
            param_2 = param_2 + 8;
            param_1[4] = param_4;
            param_1[5] = uVar6;
            param_1[6] = uVar7;
            param_1[7] = uVar8;
            param_1 = param_1 + 8;
            bVar9 = 0x1f < param_3;
            param_3 = param_3 - 0x20;
          }
        } while (bVar9);
      }
      puVar2 = param_1;
      if ((bool)((byte)(param_3 >> 4) & 1)) {
        param_4 = *param_2;
        uVar6 = param_2[1];
        uVar7 = param_2[2];
        uVar8 = param_2[3];
        param_2 = param_2 + 4;
        *param_1 = param_4;
        param_1[1] = uVar6;
        param_1[2] = uVar7;
        param_1[3] = uVar8;
        puVar2 = param_1 + 4;
      }
      if ((int)(param_3 << 0x1c) < 0) {
        param_4 = *param_2;
        uVar6 = param_2[1];
        param_2 = param_2 + 2;
        *puVar2 = param_4;
        puVar2[1] = uVar6;
        puVar2 = puVar2 + 2;
      }
      unaff_r5 = param_3 << 0x1e;
      param_1 = puVar2;
      if ((bool)((byte)(param_3 >> 2) & 1)) {
        param_4 = *param_2;
        param_1 = puVar2 + 1;
        *puVar2 = param_4;
        param_2 = param_2 + 1;
      }
      if (unaff_r5 == 0) {
        return CONCAT44(param_2,param_1);
      }
    }
    else {
      bVar9 = 3 < param_3;
      param_3 = param_3 - 4;
      if (bVar9) {
        param_2 = (uint *)((int)param_2 - param_4);
        unaff_r5 = *param_2;
        puVar2 = param_1;
        if (param_4 == 2) {
          do {
            puVar1 = param_2;
            param_4 = unaff_r5 >> 0x10;
            param_2 = puVar1 + 1;
            unaff_r5 = *param_2;
            bVar9 = 3 < param_3;
            param_3 = param_3 - 4;
            param_4 = param_4 | unaff_r5 << 0x10;
            param_1 = puVar2 + 1;
            *puVar2 = param_4;
            puVar2 = param_1;
          } while (bVar9);
          param_2 = (uint *)((int)puVar1 + 6);
        }
        else if (param_4 < 3) {
          do {
            puVar1 = param_2;
            param_4 = unaff_r5 >> 8;
            param_2 = puVar1 + 1;
            unaff_r5 = *param_2;
            bVar9 = 3 < param_3;
            param_3 = param_3 - 4;
            param_4 = param_4 | unaff_r5 << 0x18;
            param_1 = puVar2 + 1;
            *puVar2 = param_4;
            puVar2 = param_1;
          } while (bVar9);
          param_2 = (uint *)((int)puVar1 + 5);
        }
        else {
          do {
            puVar1 = param_2;
            param_4 = unaff_r5 >> 0x18;
            param_2 = puVar1 + 1;
            unaff_r5 = *param_2;
            bVar9 = 3 < param_3;
            param_3 = param_3 - 4;
            param_4 = param_4 | unaff_r5 << 8;
            param_1 = puVar2 + 1;
            *puVar2 = param_4;
            puVar2 = param_1;
          } while (bVar9);
          param_2 = (uint *)((int)puVar1 + 7);
        }
      }
    }
  }
  bVar5 = (byte)unaff_r5;
  bVar4 = (byte)param_4;
  bVar10 = (bool)((byte)(param_3 >> 1) & 1);
  param_3 = param_3 << 0x1f;
  bVar9 = (int)param_3 < 0;
  puVar2 = param_2;
  if (bVar9) {
    puVar2 = (uint *)((int)param_2 + 1);
    param_3 = (uint)(byte)*param_2;
  }
  if (bVar10) {
    pbVar3 = (byte *)((int)puVar2 + 1);
    bVar4 = (byte)*puVar2;
    puVar2 = (uint *)((int)puVar2 + 2);
    bVar5 = *pbVar3;
  }
  puVar1 = param_1;
  if (bVar9) {
    puVar1 = (uint *)((int)param_1 + 1);
    *(byte *)param_1 = (byte)param_3;
  }
  if (bVar10) {
    pbVar3 = (byte *)((int)puVar1 + 1);
    *(byte *)puVar1 = bVar4;
    puVar1 = (uint *)((int)puVar1 + 2);
    *pbVar3 = bVar5;
  }
  return CONCAT44(puVar2,puVar1);
}

/* ----------------------------------------------------------------
 * power_off_clearup_flag @ 0x30004AF8  (примерный размер ~52 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 3
 * Вызывает: fclose, fopen, remove
 * Вызывают: BSP_DRV_BOOTROM_Init
 * Константы: 0x30004AF8
 * Данные: DAT_300050e4, DAT_300050e8
 * ---------------------------------------------------------------- */
void power_off_clearup_flag(void)

{
  FILE *__stream;
  
  __stream = fopen(DAT_300050e4,DAT_300050e8);
  if (__stream != (FILE *)0x0) {
    fclose(__stream);
    remove(DAT_300050e4);
  }
  return;
}

/* ----------------------------------------------------------------
 * crypto_aes_init @ 0x300377B4  (примерный размер ~216 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 3
 * Вызывает: crypto_aes_set_key, memcpy, memset
 * Вызывают: crypto_decrypt, crypto_encrypt
 * Константы: 0xFFFFFFF6, 0x300377B4, 0xFFFFFFFC
 * ---------------------------------------------------------------- */
undefined4 crypto_aes_init(int param_1,int param_2,short param_3,int param_4,void *param_5)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffff6;
  }
  else if (((param_3 == 0x80) || (param_3 == 0xc0)) || (param_3 == 0x100)) {
    if (((param_4 == 1) || (param_4 == 2)) || (param_4 == 3)) {
      *(int *)(param_1 + 0x218) = param_4;
      if (param_2 == 0) {
        uVar1 = 0xfffffff6;
      }
      else {
        if (param_5 == (void *)0x0) {
          memset((void *)(param_1 + 0x208),0,0x10);
        }
        else {
          memcpy((void *)(param_1 + 0x208),param_5,0x10);
        }
        crypto_aes_set_key(param_1,param_2,(int)param_3,0);
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0xfffffffc;
    }
  }
  else {
    uVar1 = 0xfffffff6;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * crypto_aes_encrypt_block @ 0x3003788C  (примерный размер ~540 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 2
 * Вызывает: crypto_aes_encrypt, memcpy
 * Вызывают: crypto_encrypt
 * Константы: 0xFFFFFFFB, 0x3003788C
 * ---------------------------------------------------------------- */
undefined4
crypto_aes_encrypt_block(int param_1,uint *param_2,int param_3,uint *param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  if (param_1 == 0) {
    uVar2 = 0xfffffffb;
  }
  else if ((param_2 == (uint *)0x0) || (param_3 < 1)) {
    uVar2 = 0;
  }
  else {
    iVar1 = (int)(param_3 + ((uint)(param_3 >> 0x1f) >> 0x1c)) >> 4;
    iVar3 = *(int *)(param_1 + 0x218);
    iVar6 = iVar1;
    if (iVar3 == 1) {
      for (; 0 < iVar6; iVar6 = iVar6 + -1) {
        crypto_aes_encrypt(param_1,param_2,param_4);
        param_2 = param_2 + 4;
        param_4 = param_4 + 4;
      }
    }
    else if (iVar3 == 2) {
      puVar9 = (uint *)(param_1 + 0x208);
      for (; puVar8 = param_4, 0 < iVar6; iVar6 = iVar6 + -1) {
        local_38 = *param_2 ^ *puVar9;
        local_34 = param_2[1] ^ puVar9[1];
        puVar10 = param_2 + 3;
        local_30 = param_2[2] ^ puVar9[2];
        param_2 = param_2 + 4;
        local_2c = *puVar10 ^ puVar9[3];
        crypto_aes_encrypt(param_1,&local_38,puVar8);
        param_4 = puVar8 + 4;
        puVar9 = puVar8;
      }
    }
    else {
      if (iVar3 != 3) {
        return 0xfffffffb;
      }
      iVar3 = param_1 + 0x208;
      for (; 0 < iVar6; iVar6 = iVar6 + -1) {
        memcpy(param_4,param_2,0x10);
        for (uVar5 = 0; (int)uVar5 < 0x80; uVar5 = uVar5 + 1) {
          crypto_aes_encrypt(param_1,iVar3,&local_38);
          pbVar7 = (byte *)((int)param_4 + ((int)uVar5 >> 3));
          *pbVar7 = *pbVar7 ^ (byte)((local_38 & 0x80) >> (uVar5 & 7));
          for (iVar4 = 0; iVar4 < 0xf; iVar4 = iVar4 + 1) {
            *(byte *)(iVar3 + iVar4) =
                 *(byte *)(iVar3 + iVar4 + 1) >> 7 | *(char *)(iVar3 + iVar4) << 1;
          }
          *(byte *)(param_1 + 0x217) =
               *(byte *)((int)param_4 + ((int)uVar5 >> 3)) >> (7 - (uVar5 & 7) & 0xff) & 1 |
               *(char *)(param_1 + 0x217) << 1;
        }
        param_4 = param_4 + 4;
        param_2 = param_2 + 4;
      }
    }
    *param_5 = iVar1 << 4;
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * crypto_aes_decrypt_block @ 0x30037AA8  (примерный размер ~580 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 2
 * Вызывает: crypto_aes_decrypt, memcpy
 * Вызывают: crypto_decrypt
 * Константы: 0xFFFFFFFB, 0x30037AA8
 * ---------------------------------------------------------------- */
undefined4
crypto_aes_decrypt_block(int param_1,void *param_2,int param_3,void *param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  if (param_1 == 0) {
    uVar2 = 0xfffffffb;
  }
  else if ((param_2 == (void *)0x0) || (param_3 < 1)) {
    uVar2 = 0;
  }
  else {
    iVar1 = (int)(param_3 + ((uint)(param_3 >> 0x1f) >> 0x1c)) >> 4;
    iVar3 = *(int *)(param_1 + 0x218);
    iVar6 = iVar1;
    if (iVar3 == 1) {
      for (; 0 < iVar6; iVar6 = iVar6 + -1) {
        crypto_aes_decrypt(param_1,param_2,param_4);
        param_2 = (void *)((int)param_2 + 0x10);
        param_4 = (void *)((int)param_4 + 0x10);
      }
    }
    else if (iVar3 == 2) {
      for (; 0 < iVar6; iVar6 = iVar6 + -1) {
        crypto_aes_decrypt(param_1,param_2,&local_38);
        local_38 = local_38 ^ *(uint *)(param_1 + 0x208);
        local_34 = local_34 ^ *(uint *)(param_1 + 0x20c);
        local_30 = local_30 ^ *(uint *)(param_1 + 0x210);
        local_2c = local_2c ^ *(uint *)(param_1 + 0x214);
        memcpy((void *)(param_1 + 0x208),param_2,0x10);
        memcpy(param_4,&local_38,0x10);
        param_2 = (void *)((int)param_2 + 0x10);
        param_4 = (void *)((int)param_4 + 0x10);
      }
    }
    else {
      if (iVar3 != 3) {
        return 0xfffffffb;
      }
      iVar3 = param_1 + 0x208;
      for (; 0 < iVar6; iVar6 = iVar6 + -1) {
        memcpy(param_4,param_2,0x10);
        for (uVar5 = 0; (int)uVar5 < 0x80; uVar5 = uVar5 + 1) {
          crypto_aes_decrypt(param_1,iVar3,&local_38);
          for (iVar4 = 0; iVar4 < 0xf; iVar4 = iVar4 + 1) {
            *(byte *)(iVar3 + iVar4) =
                 *(byte *)(iVar3 + iVar4 + 1) >> 7 | *(char *)(iVar3 + iVar4) << 1;
          }
          *(byte *)(param_1 + 0x217) =
               *(byte *)((int)param_2 + ((int)uVar5 >> 3)) >> (7 - (uVar5 & 7) & 0xff) & 1 |
               *(char *)(param_1 + 0x217) << 1;
          pbVar7 = (byte *)((int)param_4 + ((int)uVar5 >> 3));
          *pbVar7 = *pbVar7 ^ (byte)((local_38 & 0x80) >> (uVar5 & 7));
        }
        param_4 = (void *)((int)param_4 + 0x10);
        param_2 = (void *)((int)param_2 + 0x10);
      }
    }
    *param_5 = iVar1 << 4;
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * crypto_aes_encrypt_pad @ 0x30037CEC  (примерный размер ~468 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: crypto_aes_encrypt, memcpy, memset
 * Константы: 0xFFFFFFFB, 0x30037CEC
 * ---------------------------------------------------------------- */
undefined4 crypto_aes_encrypt_pad(int param_1,uint *param_2,int param_3,uint *param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  
  if (param_1 == 0) {
    uVar2 = 0xfffffffb;
  }
  else if ((param_2 == (uint *)0x0) || (param_3 < 1)) {
    uVar2 = 0;
  }
  else {
    param_3 = param_3 + ((uint)(param_3 >> 0x1f) >> 0x1c);
    iVar1 = param_3 >> 4;
    iVar4 = iVar1;
    if (*(int *)(param_1 + 0x218) == 1) {
      for (; 0 < iVar4; iVar4 = iVar4 + -1) {
        crypto_aes_encrypt(param_1,param_2,param_4);
        param_2 = param_2 + 4;
        param_4 = param_4 + 4;
      }
      iVar4 = 0x10 - (param_3 + iVar1 * -0x10);
      memcpy(&local_34,param_2,0x10 - iVar4);
      memset(&stack0xffffffdc + -iVar4,iVar4,iVar4);
      crypto_aes_encrypt(param_1,&local_34,param_4);
    }
    else {
      if (*(int *)(param_1 + 0x218) != 2) {
        return 0xfffffffb;
      }
      puVar3 = (uint *)(param_1 + 0x208);
      for (; 0 < iVar4; iVar4 = iVar4 + -1) {
        local_34 = *param_2 ^ *puVar3;
        local_30 = param_2[1] ^ puVar3[1];
        puVar6 = param_2 + 3;
        local_2c = param_2[2] ^ puVar3[2];
        param_2 = param_2 + 4;
        local_28 = *puVar6 ^ puVar3[3];
        crypto_aes_encrypt(param_1,&local_34,param_4);
        puVar3 = param_4;
        param_4 = param_4 + 4;
      }
      iVar4 = 0x10 - (param_3 + iVar1 * -0x10);
      for (iVar5 = 0; iVar5 < 0x10 - iVar4; iVar5 = iVar5 + 1) {
        *(byte *)((int)&local_34 + iVar5) =
             *(byte *)((int)param_2 + iVar5) ^ *(byte *)((int)puVar3 + iVar5);
      }
      for (iVar5 = 0x10 - iVar4; iVar5 < 0x10; iVar5 = iVar5 + 1) {
        *(byte *)((int)&local_34 + iVar5) = (byte)iVar4 ^ *(byte *)((int)puVar3 + iVar5);
      }
      crypto_aes_encrypt(param_1,&local_34,param_4);
    }
    *param_5 = iVar1 * 0x10 + 0x10;
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * crypto_aes_decrypt_pad @ 0x30037EC0  (примерный размер ~608 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: crypto_aes_decrypt, memcpy
 * Константы: 0xFFFFFFF8, 0xFFFFFFFB, 0x30037EC0
 * ---------------------------------------------------------------- */
undefined4 crypto_aes_decrypt_pad(int param_1,int param_2,uint param_3,void *param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_30;
  uint local_2c;
  uint local_28;
  undefined4 local_24;
  
  if (param_1 == 0) {
    uVar2 = 0xfffffffb;
  }
  else if ((param_2 == 0) || ((int)param_3 < 1)) {
    uVar2 = 0;
  }
  else if ((param_3 & 0xf) == 0) {
    iVar1 = (int)(param_3 + ((uint)((int)param_3 >> 0x1f) >> 0x1c)) >> 4;
    iVar4 = iVar1;
    if (*(int *)(param_1 + 0x218) == 1) {
      while( true ) {
        if (iVar4 + -1 < 1) break;
        crypto_aes_decrypt(param_1,param_2,param_4);
        param_2 = param_2 + 0x10;
        param_4 = (void *)((int)param_4 + 0x10);
        iVar4 = iVar4 + -1;
      }
      crypto_aes_decrypt(param_1,param_2,&local_30);
      uVar3 = (uint)local_24._3_1_;
      if (0xf < uVar3) {
        return 0xfffffff8;
      }
      for (iVar4 = 0x10 - uVar3; iVar4 < 0x10; iVar4 = iVar4 + 1) {
        if (*(byte *)((int)&local_30 + iVar4) != uVar3) {
          return 0xfffffff8;
        }
      }
      memcpy(param_4,&local_30,0x10 - uVar3);
    }
    else {
      if (*(int *)(param_1 + 0x218) != 2) {
        return 0xfffffffb;
      }
      while (0 < iVar4 + -1) {
        crypto_aes_decrypt(param_1,param_2,&local_30);
        local_30 = local_30 ^ *(uint *)(param_1 + 0x208);
        local_2c = local_2c ^ *(uint *)(param_1 + 0x20c);
        local_28 = local_28 ^ *(uint *)(param_1 + 0x210);
        local_24 = local_24 ^ *(uint *)(param_1 + 0x214);
        crypto_aes_decrypt(param_1,param_2,&local_30);
        memcpy(param_4,&local_30,0x10);
        param_2 = param_2 + 0x10;
        param_4 = (void *)((int)param_4 + 0x10);
        iVar4 = iVar4 + -1;
      }
      crypto_aes_decrypt(param_1,param_2,param_4);
      local_30 = local_30 ^ *(uint *)(param_1 + 0x208);
      local_2c = local_2c ^ *(uint *)(param_1 + 0x20c);
      local_28 = local_28 ^ *(uint *)(param_1 + 0x210);
      local_24 = local_24 ^ *(uint *)(param_1 + 0x214);
      uVar3 = local_24 >> 0x18;
      if ((uVar3 == 0) || (0x10 < uVar3)) {
        return 0xfffffff8;
      }
      for (iVar4 = 0x10 - uVar3; iVar4 < 0x10; iVar4 = iVar4 + 1) {
        if (*(byte *)((int)&local_30 + iVar4) != uVar3) {
          return 0xfffffff8;
        }
      }
      memcpy(param_4,&local_30,0x10 - uVar3);
    }
    *param_5 = iVar1 * 0x10 - uVar3;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffff8;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30038120 @ 0x30038120  (примерный размер ~1308 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: crypto_aes_set_key
 * Константы: 0x30038120
 * Данные: DAT_30039118, DAT_3003911c, DAT_30039120, DAT_30039124, DAT_30039128, DAT_30039244, DAT_30039248, DAT_3003924c
 * ---------------------------------------------------------------- */
void FUN_30038120(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar7 = 1;
  for (uVar5 = 0; uVar5 < 0x100; uVar5 = uVar5 + 1) {
    *(char *)(DAT_30039118 + uVar5) = (char)uVar7;
    *(char *)(DAT_3003911c + (uVar7 & 0xff)) = (char)uVar5;
    if ((uVar7 & 0x80) == 0) {
      local_5b = 0;
    }
    else {
      local_5b = 0x1b;
    }
    uVar7 = uVar7 ^ uVar7 << 1 ^ (uint)local_5b;
  }
  *(undefined1 *)(DAT_3003911c + 1) = 0;
  uVar7 = 1;
  for (uVar5 = 0; uVar5 < 10; uVar5 = uVar5 + 1) {
    *(uint *)(DAT_30039120 + uVar5 * 4) = uVar7 & 0xff;
    if ((uVar7 & 0x80) == 0) {
      local_5c = 0;
    }
    else {
      local_5c = 0x1b;
    }
    uVar7 = (uint)local_5c ^ uVar7 << 1;
  }
  for (uVar5 = 0; uVar5 < 0x100; uVar5 = uVar5 + 1) {
    if (uVar5 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (uint)*(byte *)(DAT_30039118 + (0xff - (uint)*(byte *)(DAT_3003911c + uVar5)));
    }
    uVar8 = uVar7 << 1;
    uVar2 = uVar7 >> 7;
    uVar9 = (uVar8 & 0xff | uVar2) << 1;
    uVar3 = uVar8 >> 7;
    uVar1 = ((uVar8 & 0x7f | uVar2) << 1 | uVar3) << 1;
    uVar4 = uVar9 >> 7;
    uVar7 = uVar7 ^ (uVar8 | uVar2) ^ (uVar9 | uVar3) ^ (uVar1 | uVar4) ^
            ((((uVar8 & 0x3f | uVar2) << 1 | uVar3) << 1 | uVar4) << 1 | uVar1 >> 7) ^ 99;
    *(char *)(DAT_30039124 + uVar5) = (char)uVar7;
    *(char *)(DAT_30039128 + (uVar7 & 0xff)) = (char)uVar5;
  }
  for (uVar5 = 0; uVar5 < 0x100; uVar5 = uVar5 + 1) {
    uVar7 = (uint)*(byte *)(DAT_30039124 + uVar5);
    *(uint *)(DAT_30039244 + uVar5 * 4) = uVar7;
    *(uint *)(DAT_30039248 + uVar5 * 4) = uVar7 << 8;
    *(uint *)(DAT_3003924c + uVar5 * 4) = uVar7 << 0x10;
    *(uint *)(DAT_30039250 + uVar5 * 4) = uVar7 << 0x18;
    if (uVar7 == 0) {
      local_24 = 0;
      local_28 = 0;
    }
    else {
      iVar6 = (uint)*(byte *)(DAT_3003911c + 2) + (uint)*(byte *)(DAT_3003911c + uVar7);
      local_24 = (uint)*(byte *)(DAT_30039118 +
                                iVar6 + (iVar6 + (int)((ulonglong)
                                                       ((longlong)iVar6 * (longlong)DAT_30039254) >>
                                                      0x20) >> 7) * -0xff);
      iVar6 = (uint)*(byte *)(DAT_3003911c + 3) + (uint)*(byte *)(DAT_3003911c + uVar7);
      local_28 = (uint)*(byte *)(DAT_30039118 +
                                iVar6 + (iVar6 + (int)((ulonglong)
                                                       ((longlong)iVar6 * (longlong)DAT_30039254) >>
                                                      0x20) >> 7) * -0xff);
    }
    uVar8 = local_24 | uVar7 << 8;
    uVar9 = uVar8 | uVar7 << 0x10;
    uVar7 = uVar9 | local_28 << 0x18;
    *(uint *)(DAT_30039350 + uVar5 * 4) = uVar7;
    *(uint *)(DAT_30039354 + uVar5 * 4) = local_28 | uVar9 << 8;
    *(uint *)(DAT_30039358 + uVar5 * 4) = uVar7 >> 0x10 | uVar8 << 0x10;
    *(uint *)(DAT_3003935c + uVar5 * 4) = uVar7 >> 8 | local_24 << 0x18;
    uVar7 = (uint)*(byte *)(DAT_30039128 + uVar5);
    *(uint *)(DAT_30039360 + uVar5 * 4) = uVar7;
    *(uint *)(DAT_30039364 + uVar5 * 4) = uVar7 << 8;
    *(uint *)(DAT_30039368 + uVar5 * 4) = uVar7 << 0x10;
    *(uint *)(DAT_3003936c + uVar5 * 4) = uVar7 << 0x18;
    if (uVar7 == 0) {
      local_2c = 0;
      local_30 = 0;
      local_34 = 0;
      local_38 = 0;
    }
    else {
      iVar6 = (uint)*(byte *)(DAT_3003911c + 0xe) + (uint)*(byte *)(DAT_3003911c + uVar7);
      local_2c = (uint)*(byte *)(DAT_30039118 +
                                iVar6 + (iVar6 + (int)((ulonglong)
                                                       ((longlong)iVar6 * (longlong)DAT_30039254) >>
                                                      0x20) >> 7) * -0xff);
      iVar6 = (uint)*(byte *)(DAT_3003911c + 9) + (uint)*(byte *)(DAT_3003911c + uVar7);
      local_30 = (uint)*(byte *)(DAT_30039118 +
                                iVar6 + (iVar6 + (int)((ulonglong)
                                                       ((longlong)iVar6 * (longlong)DAT_30039254) >>
                                                      0x20) >> 7) * -0xff);
      iVar6 = (uint)*(byte *)(DAT_3003911c + 0xd) + (uint)*(byte *)(DAT_3003911c + uVar7);
      local_34 = (uint)*(byte *)(DAT_30039118 +
                                iVar6 + (iVar6 + (int)((ulonglong)
                                                       ((longlong)iVar6 * (longlong)DAT_30039254) >>
                                                      0x20) >> 7) * -0xff);
      iVar6 = (uint)*(byte *)(DAT_3003911c + 0xb) + (uint)*(byte *)(DAT_3003911c + uVar7);
      local_38 = (uint)*(byte *)(DAT_30039118 +
                                iVar6 + (iVar6 + (int)((ulonglong)
                                                       ((longlong)iVar6 * (longlong)DAT_30039254) >>
                                                      0x20) >> 7) * -0xff);
    }
    uVar8 = local_2c | local_30 << 8;
    uVar9 = uVar8 | local_34 << 0x10;
    uVar7 = uVar9 | local_38 << 0x18;
    *(uint *)(DAT_30039590 + uVar5 * 4) = uVar7;
    *(uint *)(DAT_30039594 + uVar5 * 4) = local_38 | uVar9 << 8;
    *(uint *)(DAT_30039598 + uVar5 * 4) = uVar7 >> 0x10 | uVar8 << 0x10;
    *(uint *)(DAT_3003959c + uVar5 * 4) = uVar7 >> 8 | local_2c << 0x18;
  }
  *DAT_300395a0 = 1;
  return;
}

/* ----------------------------------------------------------------
 * crypto_aes_set_key @ 0x3003863C  (примерный размер ~1760 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30038120
 * Вызывают: crypto_aes_init
 * Константы: 0x3003863C
 * Данные: DAT_30039120, DAT_30039244, DAT_30039248, DAT_3003924c, DAT_30039250, DAT_300395a0, DAT_30039b20, DAT_30039b24
 * ---------------------------------------------------------------- */
uint * crypto_aes_set_key(uint *param_1,undefined1 *param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  
  puVar4 = param_1 + 1;
  puVar5 = param_1 + 0x41;
  param_1[0x81] = (uint)(param_4 == 0);
  if (*DAT_300395a0 == 0) {
    FUN_30038120();
  }
  *param_1 = param_3 + 0x1fU >> 5;
  *(undefined1 *)puVar4 = *param_2;
  *(undefined1 *)((int)param_1 + 5) = param_2[1];
  *(undefined1 *)((int)param_1 + 6) = param_2[2];
  *(undefined1 *)((int)param_1 + 7) = param_2[3];
  *(undefined1 *)(param_1 + 2) = param_2[4];
  *(undefined1 *)((int)param_1 + 9) = param_2[5];
  *(undefined1 *)((int)param_1 + 10) = param_2[6];
  *(undefined1 *)((int)param_1 + 0xb) = param_2[7];
  *(undefined1 *)(param_1 + 3) = param_2[8];
  *(undefined1 *)((int)param_1 + 0xd) = param_2[9];
  *(undefined1 *)((int)param_1 + 0xe) = param_2[10];
  *(undefined1 *)((int)param_1 + 0xf) = param_2[0xb];
  *(undefined1 *)(param_1 + 4) = param_2[0xc];
  *(undefined1 *)((int)param_1 + 0x11) = param_2[0xd];
  *(undefined1 *)((int)param_1 + 0x12) = param_2[0xe];
  *(undefined1 *)((int)param_1 + 0x13) = param_2[0xf];
  if (*param_1 == 4) {
    uVar1 = param_1[4];
    for (uVar3 = 0; uVar3 < 10; uVar3 = uVar3 + 1) {
      uVar1 = *(uint *)(DAT_30039244 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(DAT_30039248 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(DAT_3003924c + (uVar1 >> 0x18) * 4) ^
              *(uint *)(DAT_30039250 + (uVar1 & 0xff) * 4) ^ *(uint *)(DAT_30039120 + uVar3 * 4) ^
              puVar4[uVar3 * 4];
      puVar4[uVar3 * 4 + 4] = uVar1;
      uVar1 = uVar1 ^ puVar4[uVar3 * 4 + 1];
      puVar4[uVar3 * 4 + 5] = uVar1;
      uVar1 = uVar1 ^ puVar4[uVar3 * 4 + 2];
      puVar4[uVar3 * 4 + 6] = uVar1;
      uVar1 = uVar1 ^ puVar4[uVar3 * 4 + 3];
      puVar4[uVar3 * 4 + 7] = uVar1;
    }
  }
  else {
    *(undefined1 *)(param_1 + 5) = param_2[0x10];
    *(undefined1 *)((int)param_1 + 0x15) = param_2[0x11];
    *(undefined1 *)((int)param_1 + 0x16) = param_2[0x12];
    *(undefined1 *)((int)param_1 + 0x17) = param_2[0x13];
    *(undefined1 *)(param_1 + 6) = param_2[0x14];
    *(undefined1 *)((int)param_1 + 0x19) = param_2[0x15];
    *(undefined1 *)((int)param_1 + 0x1a) = param_2[0x16];
    *(undefined1 *)((int)param_1 + 0x1b) = param_2[0x17];
    if (*param_1 == 6) {
      uVar1 = param_1[6];
      for (uVar3 = 0; uVar3 < 8; uVar3 = uVar3 + 1) {
        uVar1 = *(uint *)(DAT_30039244 + (uVar1 >> 8 & 0xff) * 4) ^
                *(uint *)(DAT_30039248 + (uVar1 >> 0x10 & 0xff) * 4) ^
                *(uint *)(DAT_3003924c + (uVar1 >> 0x18) * 4) ^
                *(uint *)(DAT_30039250 + (uVar1 & 0xff) * 4) ^ *(uint *)(DAT_30039120 + uVar3 * 4) ^
                puVar4[uVar3 * 6];
        puVar4[uVar3 * 6 + 6] = uVar1;
        uVar1 = uVar1 ^ puVar4[uVar3 * 6 + 1];
        puVar4[uVar3 * 6 + 7] = uVar1;
        uVar1 = uVar1 ^ puVar4[uVar3 * 6 + 2];
        puVar4[uVar3 * 6 + 8] = uVar1;
        uVar1 = uVar1 ^ puVar4[uVar3 * 6 + 3];
        puVar4[uVar3 * 6 + 9] = uVar1;
        uVar1 = uVar1 ^ puVar4[uVar3 * 6 + 4];
        puVar4[uVar3 * 6 + 10] = uVar1;
        uVar1 = uVar1 ^ puVar4[uVar3 * 6 + 5];
        puVar4[uVar3 * 6 + 0xb] = uVar1;
      }
    }
    else {
      *(undefined1 *)(param_1 + 7) = param_2[0x18];
      *(undefined1 *)((int)param_1 + 0x1d) = param_2[0x19];
      *(undefined1 *)((int)param_1 + 0x1e) = param_2[0x1a];
      *(undefined1 *)((int)param_1 + 0x1f) = param_2[0x1b];
      *(undefined1 *)(param_1 + 8) = param_2[0x1c];
      *(undefined1 *)((int)param_1 + 0x21) = param_2[0x1d];
      *(undefined1 *)((int)param_1 + 0x22) = param_2[0x1e];
      *(undefined1 *)((int)param_1 + 0x23) = param_2[0x1f];
      if (*param_1 == 8) {
        uVar1 = param_1[8];
        for (uVar3 = 0; uVar3 < 7; uVar3 = uVar3 + 1) {
          uVar1 = *(uint *)(DAT_30039244 + (uVar1 >> 8 & 0xff) * 4) ^
                  *(uint *)(DAT_30039248 + (uVar1 >> 0x10 & 0xff) * 4) ^
                  *(uint *)(DAT_3003924c + (uVar1 >> 0x18) * 4) ^
                  *(uint *)(DAT_30039250 + (uVar1 & 0xff) * 4) ^ *(uint *)(DAT_30039120 + uVar3 * 4)
                  ^ puVar4[uVar3 * 8];
          puVar4[uVar3 * 8 + 8] = uVar1;
          uVar1 = uVar1 ^ puVar4[uVar3 * 8 + 1];
          puVar4[uVar3 * 8 + 9] = uVar1;
          uVar1 = uVar1 ^ puVar4[uVar3 * 8 + 2];
          puVar4[uVar3 * 8 + 10] = uVar1;
          uVar1 = uVar1 ^ puVar4[uVar3 * 8 + 3];
          puVar4[uVar3 * 8 + 0xb] = uVar1;
          uVar1 = *(uint *)(DAT_30039244 + (uVar1 & 0xff) * 4) ^
                  *(uint *)(DAT_30039248 + (uVar1 >> 8 & 0xff) * 4) ^
                  *(uint *)(DAT_3003924c + (uVar1 >> 0x10 & 0xff) * 4) ^
                  *(uint *)(DAT_30039250 + (uVar1 >> 0x18) * 4) ^ puVar4[uVar3 * 8 + 4];
          puVar4[uVar3 * 8 + 0xc] = uVar1;
          uVar1 = uVar1 ^ puVar4[uVar3 * 8 + 5];
          puVar4[uVar3 * 8 + 0xd] = uVar1;
          uVar1 = uVar1 ^ puVar4[uVar3 * 8 + 6];
          puVar4[uVar3 * 8 + 0xe] = uVar1;
          uVar1 = uVar1 ^ puVar4[uVar3 * 8 + 7];
          puVar4[uVar3 * 8 + 0xf] = uVar1;
        }
      }
    }
  }
  if (param_1[0x81] != 0) {
    *puVar5 = *puVar4;
    param_1[0x42] = param_1[2];
    param_1[0x43] = param_1[3];
    param_1[0x44] = param_1[4];
    for (uVar1 = 4; uVar1 < *param_1 * 4 + 0x18; uVar1 = uVar1 + 1) {
      uVar3 = ((puVar4[uVar1] & DAT_30039b20) >> 7) * 0x1b ^ (puVar4[uVar1] & DAT_30039b24) << 1;
      uVar6 = ((uVar3 & DAT_30039b20) >> 7) * 0x1b ^ (uVar3 & DAT_30039b24) << 1;
      uVar7 = ((uVar6 & DAT_30039b20) >> 7) * 0x1b ^ (uVar6 & DAT_30039b24) << 1;
      uVar2 = uVar7 ^ puVar4[uVar1];
      puVar5[uVar1] = uVar7 ^ uVar3 ^ uVar6;
      puVar5[uVar1] =
           puVar5[uVar1] ^ ((uVar3 ^ uVar2) >> 8 | (uVar3 ^ uVar2) << 0x18) ^
           ((uVar6 ^ uVar2) >> 0x10 | (uVar6 ^ uVar2) << 0x10) ^ (uVar2 >> 0x18 | uVar2 << 8);
    }
    puVar5[*param_1 * 4 + 0x18] = puVar4[*param_1 * 4 + 0x18];
    puVar5[*param_1 * 4 + 0x19] = puVar4[*param_1 * 4 + 0x19];
    puVar5[*param_1 * 4 + 0x1a] = puVar4[*param_1 * 4 + 0x1a];
    puVar5[*param_1 * 4 + 0x1b] = puVar4[*param_1 * 4 + 0x1b];
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * crypto_aes_encrypt @ 0x30038D1C  (примерный размер ~5684 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: crypto_aes_encrypt_block, crypto_aes_encrypt_pad
 * Константы: 0x30038D1C
 * Данные: DAT_30039350, DAT_30039354, DAT_30039358, DAT_3003935c, DAT_3003a33c, DAT_3003a340, DAT_3003a344, DAT_3003a348
 * ---------------------------------------------------------------- */
void crypto_aes_encrypt(uint *param_1,uint *param_2,undefined1 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_38 = *param_2 ^ param_1[1];
  local_34 = param_2[1] ^ param_1[2];
  local_30 = param_2[2] ^ param_1[3];
  puVar4 = param_1 + 5;
  local_2c = param_2[3] ^ param_1[4];
  if (6 < *param_1) {
    uVar5 = *(uint *)(DAT_30039350 + (local_38 & 0xff) * 4) ^
            *(uint *)(DAT_30039354 + (local_34 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30039358 + (local_30 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003935c + (local_2c >> 0x18) * 4) ^ *puVar4;
    uVar1 = *(uint *)(DAT_30039350 + (local_34 & 0xff) * 4) ^
            *(uint *)(DAT_30039354 + (local_30 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30039358 + (local_2c >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003935c + (local_38 >> 0x18) * 4) ^ param_1[6];
    uVar6 = *(uint *)(DAT_30039350 + (local_30 & 0xff) * 4) ^
            *(uint *)(DAT_30039354 + (local_2c >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30039358 + (local_38 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003935c + (local_34 >> 0x18) * 4) ^ param_1[7];
    uVar2 = *(uint *)(DAT_30039350 + (local_2c & 0xff) * 4) ^
            *(uint *)(DAT_30039354 + (local_38 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30039358 + (local_34 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003935c + (local_30 >> 0x18) * 4) ^ param_1[8];
    local_38 = *(uint *)(DAT_30039350 + (uVar5 & 0xff) * 4) ^
               *(uint *)(DAT_30039354 + (uVar1 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_30039358 + (uVar6 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003935c + (uVar2 >> 0x18) * 4) ^ param_1[9];
    local_34 = *(uint *)(DAT_30039350 + (uVar1 & 0xff) * 4) ^
               *(uint *)(DAT_30039354 + (uVar6 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_30039358 + (uVar2 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003935c + (uVar5 >> 0x18) * 4) ^ param_1[10];
    local_30 = *(uint *)(DAT_30039350 + (uVar6 & 0xff) * 4) ^
               *(uint *)(DAT_30039354 + (uVar2 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_30039358 + (uVar5 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003935c + (uVar1 >> 0x18) * 4) ^ param_1[0xb];
    puVar4 = param_1 + 0xd;
    local_2c = *(uint *)(DAT_30039350 + (uVar2 & 0xff) * 4) ^
               *(uint *)(DAT_30039354 + (uVar5 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_30039358 + (uVar1 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003935c + (uVar6 >> 0x18) * 4) ^ param_1[0xc];
  }
  if (4 < *param_1) {
    uVar5 = *(uint *)(DAT_30039350 + (local_38 & 0xff) * 4) ^
            *(uint *)(DAT_30039354 + (local_34 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30039358 + (local_30 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003935c + (local_2c >> 0x18) * 4) ^ *puVar4;
    uVar1 = *(uint *)(DAT_30039350 + (local_34 & 0xff) * 4) ^
            *(uint *)(DAT_30039354 + (local_30 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30039358 + (local_2c >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003935c + (local_38 >> 0x18) * 4) ^ puVar4[1];
    uVar6 = *(uint *)(DAT_30039350 + (local_30 & 0xff) * 4) ^
            *(uint *)(DAT_30039354 + (local_2c >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30039358 + (local_38 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003935c + (local_34 >> 0x18) * 4) ^ puVar4[2];
    uVar2 = *(uint *)(DAT_30039350 + (local_2c & 0xff) * 4) ^
            *(uint *)(DAT_30039354 + (local_38 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30039358 + (local_34 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003935c + (local_30 >> 0x18) * 4) ^ puVar4[3];
    local_38 = *(uint *)(DAT_30039350 + (uVar5 & 0xff) * 4) ^
               *(uint *)(DAT_30039354 + (uVar1 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_30039358 + (uVar6 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003935c + (uVar2 >> 0x18) * 4) ^ puVar4[4];
    local_34 = *(uint *)(DAT_30039350 + (uVar1 & 0xff) * 4) ^
               *(uint *)(DAT_30039354 + (uVar6 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_30039358 + (uVar2 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003935c + (uVar5 >> 0x18) * 4) ^ puVar4[5];
    puVar3 = puVar4 + 7;
    local_30 = *(uint *)(DAT_3003a33c + (uVar6 & 0xff) * 4) ^
               *(uint *)(DAT_3003a340 + (uVar2 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_3003a344 + (uVar5 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003a348 + (uVar1 >> 0x18) * 4) ^ puVar4[6];
    puVar4 = puVar4 + 8;
    local_2c = *(uint *)(DAT_3003a33c + (uVar2 & 0xff) * 4) ^
               *(uint *)(DAT_3003a340 + (uVar5 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_3003a344 + (uVar1 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003a348 + (uVar6 >> 0x18) * 4) ^ *puVar3;
  }
  uVar6 = *(uint *)(DAT_3003a33c + (local_38 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (local_34 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (local_30 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (local_2c >> 0x18) * 4) ^ *puVar4;
  uVar1 = *(uint *)(DAT_3003a33c + (local_34 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (local_30 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (local_2c >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (local_38 >> 0x18) * 4) ^ puVar4[1];
  uVar7 = *(uint *)(DAT_3003a33c + (local_30 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (local_2c >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (local_38 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (local_34 >> 0x18) * 4) ^ puVar4[2];
  uVar2 = *(uint *)(DAT_3003a33c + (local_2c & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (local_38 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (local_34 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (local_30 >> 0x18) * 4) ^ puVar4[3];
  uVar8 = *(uint *)(DAT_3003a33c + (uVar6 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar2 >> 0x18) * 4) ^ puVar4[4];
  uVar5 = *(uint *)(DAT_3003a33c + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar2 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar6 >> 0x18) * 4) ^ puVar4[5];
  uVar9 = *(uint *)(DAT_3003a33c + (uVar7 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar2 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar1 >> 0x18) * 4) ^ puVar4[6];
  uVar1 = *(uint *)(DAT_3003a33c + (uVar2 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar7 >> 0x18) * 4) ^ puVar4[7];
  uVar6 = *(uint *)(DAT_3003a33c + (uVar8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar9 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar1 >> 0x18) * 4) ^ puVar4[8];
  uVar2 = *(uint *)(DAT_3003a33c + (uVar5 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar9 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar8 >> 0x18) * 4) ^ puVar4[9];
  uVar7 = *(uint *)(DAT_3003a33c + (uVar9 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar5 >> 0x18) * 4) ^ puVar4[10];
  uVar1 = *(uint *)(DAT_3003a33c + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar9 >> 0x18) * 4) ^ puVar4[0xb];
  uVar8 = *(uint *)(DAT_3003a33c + (uVar6 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar2 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar1 >> 0x18) * 4) ^ puVar4[0xc];
  uVar5 = *(uint *)(DAT_3003a33c + (uVar2 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar6 >> 0x18) * 4) ^ puVar4[0xd];
  uVar9 = *(uint *)(DAT_3003a33c + (uVar7 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar2 >> 0x18) * 4) ^ puVar4[0xe];
  uVar1 = *(uint *)(DAT_3003a33c + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar2 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar7 >> 0x18) * 4) ^ puVar4[0xf];
  uVar6 = *(uint *)(DAT_3003a33c + (uVar8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar9 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar1 >> 0x18) * 4) ^ puVar4[0x10];
  uVar2 = *(uint *)(DAT_3003a33c + (uVar5 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar9 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar8 >> 0x18) * 4) ^ puVar4[0x11];
  uVar7 = *(uint *)(DAT_3003a33c + (uVar9 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar5 >> 0x18) * 4) ^ puVar4[0x12];
  uVar1 = *(uint *)(DAT_3003a33c + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar9 >> 0x18) * 4) ^ puVar4[0x13];
  uVar8 = *(uint *)(DAT_3003a33c + (uVar6 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar2 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar1 >> 0x18) * 4) ^ puVar4[0x14];
  uVar5 = *(uint *)(DAT_3003a33c + (uVar2 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar6 >> 0x18) * 4) ^ puVar4[0x15];
  uVar9 = *(uint *)(DAT_3003a33c + (uVar7 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar2 >> 0x18) * 4) ^ puVar4[0x16];
  uVar1 = *(uint *)(DAT_3003a33c + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar2 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar7 >> 0x18) * 4) ^ puVar4[0x17];
  uVar6 = *(uint *)(DAT_3003a33c + (uVar8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar9 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar1 >> 0x18) * 4) ^ puVar4[0x18];
  uVar2 = *(uint *)(DAT_3003a33c + (uVar5 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar9 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar8 >> 0x18) * 4) ^ puVar4[0x19];
  uVar7 = *(uint *)(DAT_3003a33c + (uVar9 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar5 >> 0x18) * 4) ^ puVar4[0x1a];
  uVar1 = *(uint *)(DAT_3003a33c + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar9 >> 0x18) * 4) ^ puVar4[0x1b];
  uVar8 = *(uint *)(DAT_3003a33c + (uVar6 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar2 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar1 >> 0x18) * 4) ^ puVar4[0x1c];
  uVar5 = *(uint *)(DAT_3003a33c + (uVar2 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar6 >> 0x18) * 4) ^ puVar4[0x1d];
  uVar9 = *(uint *)(DAT_3003a33c + (uVar7 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar2 >> 0x18) * 4) ^ puVar4[0x1e];
  uVar1 = *(uint *)(DAT_3003a33c + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar2 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar7 >> 0x18) * 4) ^ puVar4[0x1f];
  uVar6 = *(uint *)(DAT_3003a33c + (uVar8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar9 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar1 >> 0x18) * 4) ^ puVar4[0x20];
  uVar2 = *(uint *)(DAT_3003a33c + (uVar5 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar9 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar8 >> 0x18) * 4) ^ puVar4[0x21];
  uVar7 = *(uint *)(DAT_3003a33c + (uVar9 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar5 >> 0x18) * 4) ^ puVar4[0x22];
  uVar1 = *(uint *)(DAT_3003a33c + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003a340 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003a344 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003a348 + (uVar9 >> 0x18) * 4) ^ puVar4[0x23];
  uVar8 = *(uint *)(DAT_3003b128 + (uVar6 & 0xff) * 4) ^
          *(uint *)(DAT_3003b12c + (uVar2 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b130 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b134 + (uVar1 >> 0x18) * 4) ^ puVar4[0x24];
  uVar5 = *(uint *)(DAT_3003b128 + (uVar2 & 0xff) * 4) ^
          *(uint *)(DAT_3003b12c + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b130 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b134 + (uVar6 >> 0x18) * 4) ^ puVar4[0x25];
  uVar9 = *(uint *)(DAT_3003b128 + (uVar7 & 0xff) * 4) ^
          *(uint *)(DAT_3003b12c + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b130 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b134 + (uVar2 >> 0x18) * 4) ^ puVar4[0x26];
  uVar1 = *(uint *)(DAT_3003b128 + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003b12c + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b130 + (uVar2 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b134 + (uVar7 >> 0x18) * 4) ^ puVar4[0x27];
  local_38._0_1_ = (undefined1)uVar8;
  *param_3 = (undefined1)local_38;
  local_38._1_1_ = (undefined1)(uVar8 >> 8);
  param_3[1] = local_38._1_1_;
  local_38._2_1_ = (undefined1)(uVar8 >> 0x10);
  param_3[2] = local_38._2_1_;
  local_38._3_1_ = (undefined1)(uVar8 >> 0x18);
  param_3[3] = local_38._3_1_;
  local_34._0_1_ = (undefined1)uVar5;
  param_3[4] = (undefined1)local_34;
  local_34._1_1_ = (undefined1)(uVar5 >> 8);
  param_3[5] = local_34._1_1_;
  local_34._2_1_ = (undefined1)(uVar5 >> 0x10);
  param_3[6] = local_34._2_1_;
  local_34._3_1_ = (undefined1)(uVar5 >> 0x18);
  param_3[7] = local_34._3_1_;
  local_30._0_1_ = (undefined1)uVar9;
  param_3[8] = (undefined1)local_30;
  local_30._1_1_ = (undefined1)(uVar9 >> 8);
  param_3[9] = local_30._1_1_;
  local_30._2_1_ = (undefined1)(uVar9 >> 0x10);
  param_3[10] = local_30._2_1_;
  local_30._3_1_ = (undefined1)(uVar9 >> 0x18);
  param_3[0xb] = local_30._3_1_;
  local_2c._0_1_ = (undefined1)uVar1;
  param_3[0xc] = (undefined1)local_2c;
  local_2c._1_1_ = (undefined1)(uVar1 >> 8);
  param_3[0xd] = local_2c._1_1_;
  local_2c._2_1_ = (undefined1)(uVar1 >> 0x10);
  param_3[0xe] = local_2c._2_1_;
  local_2c._3_1_ = (undefined1)(uVar1 >> 0x18);
  param_3[0xf] = local_2c._3_1_;
  return;
}

/* ----------------------------------------------------------------
 * crypto_aes_decrypt @ 0x3003A350  (примерный размер ~5648 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: crypto_aes_decrypt_block, crypto_aes_decrypt_pad
 * Константы: 0x3003A350
 * Данные: DAT_3003b35c, DAT_3003b360, DAT_3003b364, DAT_3003b468, DAT_3003b940, DAT_3003b944, DAT_3003b948, DAT_3003b94c
 * ---------------------------------------------------------------- */
void crypto_aes_decrypt(uint *param_1,uint *param_2,undefined1 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar4 = *param_1;
  local_38 = *param_2 ^ param_1[uVar4 * 4 + 0x59];
  local_34 = param_2[1] ^ param_1[uVar4 * 4 + 0x5a];
  local_30 = param_2[2] ^ param_1[uVar4 * 4 + 0x5b];
  local_2c = param_2[3] ^ param_1[uVar4 * 4 + 0x5c];
  puVar3 = param_1 + uVar4 * 4 + 0x55;
  if (6 < *param_1) {
    uVar5 = *(uint *)(DAT_3003b35c + (local_38 & 0xff) * 4) ^
            *(uint *)(DAT_3003b360 + (local_2c >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_3003b364 + (local_30 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003b468 + (local_34 >> 0x18) * 4) ^ *puVar3;
    uVar1 = *(uint *)(DAT_3003b35c + (local_34 & 0xff) * 4) ^
            *(uint *)(DAT_3003b360 + (local_38 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_3003b364 + (local_2c >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003b468 + (local_30 >> 0x18) * 4) ^ param_1[uVar4 * 4 + 0x56];
    uVar6 = *(uint *)(DAT_3003b35c + (local_30 & 0xff) * 4) ^
            *(uint *)(DAT_3003b360 + (local_34 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_3003b364 + (local_38 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003b468 + (local_2c >> 0x18) * 4) ^ param_1[uVar4 * 4 + 0x57];
    uVar2 = *(uint *)(DAT_3003b35c + (local_2c & 0xff) * 4) ^
            *(uint *)(DAT_3003b360 + (local_30 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_3003b364 + (local_34 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003b468 + (local_38 >> 0x18) * 4) ^ param_1[uVar4 * 4 + 0x58];
    local_38 = *(uint *)(DAT_3003b35c + (uVar5 & 0xff) * 4) ^
               *(uint *)(DAT_3003b360 + (uVar2 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_3003b364 + (uVar6 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003b468 + (uVar1 >> 0x18) * 4) ^ param_1[uVar4 * 4 + 0x51];
    local_34 = *(uint *)(DAT_3003b35c + (uVar1 & 0xff) * 4) ^
               *(uint *)(DAT_3003b360 + (uVar5 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_3003b364 + (uVar2 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003b468 + (uVar6 >> 0x18) * 4) ^ param_1[uVar4 * 4 + 0x52];
    local_30 = *(uint *)(DAT_3003b35c + (uVar6 & 0xff) * 4) ^
               *(uint *)(DAT_3003b360 + (uVar1 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_3003b364 + (uVar5 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003b468 + (uVar2 >> 0x18) * 4) ^ param_1[uVar4 * 4 + 0x53];
    local_2c = *(uint *)(DAT_3003b35c + (uVar2 & 0xff) * 4) ^
               *(uint *)(DAT_3003b360 + (uVar6 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_3003b364 + (uVar1 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003b468 + (uVar5 >> 0x18) * 4) ^ param_1[uVar4 * 4 + 0x54];
    puVar3 = param_1 + uVar4 * 4 + 0x4d;
  }
  if (4 < *param_1) {
    uVar2 = *(uint *)(DAT_3003b35c + (local_38 & 0xff) * 4) ^
            *(uint *)(DAT_3003b360 + (local_2c >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_3003b364 + (local_30 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003b468 + (local_34 >> 0x18) * 4) ^ *puVar3;
    uVar4 = *(uint *)(DAT_3003b35c + (local_34 & 0xff) * 4) ^
            *(uint *)(DAT_3003b360 + (local_38 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_3003b364 + (local_2c >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003b468 + (local_30 >> 0x18) * 4) ^ puVar3[1];
    uVar5 = *(uint *)(DAT_3003b35c + (local_30 & 0xff) * 4) ^
            *(uint *)(DAT_3003b360 + (local_34 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_3003b364 + (local_38 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003b468 + (local_2c >> 0x18) * 4) ^ puVar3[2];
    uVar1 = *(uint *)(DAT_3003b35c + (local_2c & 0xff) * 4) ^
            *(uint *)(DAT_3003b360 + (local_30 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_3003b364 + (local_34 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_3003b468 + (local_38 >> 0x18) * 4) ^ puVar3[3];
    local_38 = *(uint *)(DAT_3003b35c + (uVar2 & 0xff) * 4) ^
               *(uint *)(DAT_3003b360 + (uVar1 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_3003b364 + (uVar5 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003b468 + (uVar4 >> 0x18) * 4) ^ puVar3[-4];
    local_34 = *(uint *)(DAT_3003b35c + (uVar4 & 0xff) * 4) ^
               *(uint *)(DAT_3003b360 + (uVar2 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_3003b364 + (uVar1 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003b468 + (uVar5 >> 0x18) * 4) ^ puVar3[-3];
    local_30 = *(uint *)(DAT_3003b35c + (uVar5 & 0xff) * 4) ^
               *(uint *)(DAT_3003b360 + (uVar4 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_3003b364 + (uVar2 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003b468 + (uVar1 >> 0x18) * 4) ^ puVar3[-2];
    local_2c = *(uint *)(DAT_3003b35c + (uVar1 & 0xff) * 4) ^
               *(uint *)(DAT_3003b360 + (uVar5 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_3003b364 + (uVar4 >> 0x10 & 0xff) * 4) ^
               *(uint *)(DAT_3003b468 + (uVar2 >> 0x18) * 4) ^ puVar3[-1];
    puVar3 = puVar3 + -8;
  }
  uVar5 = *(uint *)(DAT_3003b35c + (local_38 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (local_2c >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (local_30 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (local_34 >> 0x18) * 4) ^ *puVar3;
  uVar4 = *(uint *)(DAT_3003b35c + (local_34 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (local_38 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (local_2c >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (local_30 >> 0x18) * 4) ^ puVar3[1];
  uVar6 = *(uint *)(DAT_3003b35c + (local_30 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (local_34 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (local_38 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (local_2c >> 0x18) * 4) ^ puVar3[2];
  uVar1 = *(uint *)(DAT_3003b35c + (local_2c & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (local_30 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (local_34 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (local_38 >> 0x18) * 4) ^ puVar3[3];
  uVar7 = *(uint *)(DAT_3003b35c + (uVar5 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar4 >> 0x18) * 4) ^ puVar3[-4];
  uVar2 = *(uint *)(DAT_3003b35c + (uVar4 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar6 >> 0x18) * 4) ^ puVar3[-3];
  uVar8 = *(uint *)(DAT_3003b35c + (uVar6 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar1 >> 0x18) * 4) ^ puVar3[-2];
  uVar4 = *(uint *)(DAT_3003b35c + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar5 >> 0x18) * 4) ^ puVar3[-1];
  uVar5 = *(uint *)(DAT_3003b35c + (uVar7 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar2 >> 0x18) * 4) ^ puVar3[-8];
  uVar1 = *(uint *)(DAT_3003b35c + (uVar2 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar8 >> 0x18) * 4) ^ puVar3[-7];
  uVar6 = *(uint *)(DAT_3003b35c + (uVar8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar2 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar4 >> 0x18) * 4) ^ puVar3[-6];
  uVar4 = *(uint *)(DAT_3003b35c + (uVar4 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar2 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar7 >> 0x18) * 4) ^ puVar3[-5];
  uVar7 = *(uint *)(DAT_3003b35c + (uVar5 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar1 >> 0x18) * 4) ^ puVar3[-0xc];
  uVar2 = *(uint *)(DAT_3003b35c + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar6 >> 0x18) * 4) ^ puVar3[-0xb];
  uVar8 = *(uint *)(DAT_3003b35c + (uVar6 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar4 >> 0x18) * 4) ^ puVar3[-10];
  uVar4 = *(uint *)(DAT_3003b35c + (uVar4 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar5 >> 0x18) * 4) ^ puVar3[-9];
  uVar5 = *(uint *)(DAT_3003b35c + (uVar7 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar2 >> 0x18) * 4) ^ puVar3[-0x10];
  uVar1 = *(uint *)(DAT_3003b35c + (uVar2 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar8 >> 0x18) * 4) ^ puVar3[-0xf];
  uVar6 = *(uint *)(DAT_3003b35c + (uVar8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar2 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar4 >> 0x18) * 4) ^ puVar3[-0xe];
  uVar4 = *(uint *)(DAT_3003b35c + (uVar4 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar2 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar7 >> 0x18) * 4) ^ puVar3[-0xd];
  uVar7 = *(uint *)(DAT_3003b35c + (uVar5 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar1 >> 0x18) * 4) ^ puVar3[-0x14];
  uVar2 = *(uint *)(DAT_3003b35c + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar6 >> 0x18) * 4) ^ puVar3[-0x13];
  uVar8 = *(uint *)(DAT_3003b35c + (uVar6 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar4 >> 0x18) * 4) ^ puVar3[-0x12];
  uVar4 = *(uint *)(DAT_3003b35c + (uVar4 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar5 >> 0x18) * 4) ^ puVar3[-0x11];
  uVar5 = *(uint *)(DAT_3003b35c + (uVar7 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b364 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar2 >> 0x18) * 4) ^ puVar3[-0x18];
  uVar1 = *(uint *)(DAT_3003b35c + (uVar2 & 0xff) * 4) ^
          *(uint *)(DAT_3003b360 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b940 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar8 >> 0x18) * 4) ^ puVar3[-0x17];
  uVar6 = *(uint *)(DAT_3003b944 + (uVar8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b948 + (uVar2 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b940 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar4 >> 0x18) * 4) ^ puVar3[-0x16];
  uVar4 = *(uint *)(DAT_3003b944 + (uVar4 & 0xff) * 4) ^
          *(uint *)(DAT_3003b948 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b940 + (uVar2 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b468 + (uVar7 >> 0x18) * 4) ^ puVar3[-0x15];
  uVar7 = *(uint *)(DAT_3003b944 + (uVar5 & 0xff) * 4) ^
          *(uint *)(DAT_3003b948 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b940 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b94c + (uVar1 >> 0x18) * 4) ^ puVar3[-0x1c];
  uVar2 = *(uint *)(DAT_3003b944 + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003b948 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b940 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b94c + (uVar6 >> 0x18) * 4) ^ puVar3[-0x1b];
  uVar8 = *(uint *)(DAT_3003b944 + (uVar6 & 0xff) * 4) ^
          *(uint *)(DAT_3003b948 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b940 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b94c + (uVar4 >> 0x18) * 4) ^ puVar3[-0x1a];
  uVar4 = *(uint *)(DAT_3003b944 + (uVar4 & 0xff) * 4) ^
          *(uint *)(DAT_3003b948 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b940 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b94c + (uVar5 >> 0x18) * 4) ^ puVar3[-0x19];
  uVar5 = *(uint *)(DAT_3003b944 + (uVar7 & 0xff) * 4) ^
          *(uint *)(DAT_3003b948 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b940 + (uVar8 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b94c + (uVar2 >> 0x18) * 4) ^ puVar3[-0x20];
  uVar1 = *(uint *)(DAT_3003b944 + (uVar2 & 0xff) * 4) ^
          *(uint *)(DAT_3003b948 + (uVar7 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b940 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b94c + (uVar8 >> 0x18) * 4) ^ puVar3[-0x1f];
  uVar6 = *(uint *)(DAT_3003b944 + (uVar8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b948 + (uVar2 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b940 + (uVar7 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b94c + (uVar4 >> 0x18) * 4) ^ puVar3[-0x1e];
  uVar4 = *(uint *)(DAT_3003b944 + (uVar4 & 0xff) * 4) ^
          *(uint *)(DAT_3003b948 + (uVar8 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b940 + (uVar2 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b94c + (uVar7 >> 0x18) * 4) ^ puVar3[-0x1d];
  uVar7 = *(uint *)(DAT_3003b950 + (uVar5 & 0xff) * 4) ^
          *(uint *)(DAT_3003b954 + (uVar4 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b958 + (uVar6 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b95c + (uVar1 >> 0x18) * 4) ^ puVar3[-0x24];
  uVar2 = *(uint *)(DAT_3003b950 + (uVar1 & 0xff) * 4) ^
          *(uint *)(DAT_3003b954 + (uVar5 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b958 + (uVar4 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b95c + (uVar6 >> 0x18) * 4) ^ puVar3[-0x23];
  uVar8 = *(uint *)(DAT_3003b950 + (uVar6 & 0xff) * 4) ^
          *(uint *)(DAT_3003b954 + (uVar1 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b958 + (uVar5 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b95c + (uVar4 >> 0x18) * 4) ^ puVar3[-0x22];
  uVar4 = *(uint *)(DAT_3003b950 + (uVar4 & 0xff) * 4) ^
          *(uint *)(DAT_3003b954 + (uVar6 >> 8 & 0xff) * 4) ^
          *(uint *)(DAT_3003b958 + (uVar1 >> 0x10 & 0xff) * 4) ^
          *(uint *)(DAT_3003b95c + (uVar5 >> 0x18) * 4) ^ puVar3[-0x21];
  local_38._0_1_ = (undefined1)uVar7;
  *param_3 = (undefined1)local_38;
  local_38._1_1_ = (undefined1)(uVar7 >> 8);
  param_3[1] = local_38._1_1_;
  local_38._2_1_ = (undefined1)(uVar7 >> 0x10);
  param_3[2] = local_38._2_1_;
  local_38._3_1_ = (undefined1)(uVar7 >> 0x18);
  param_3[3] = local_38._3_1_;
  local_34._0_1_ = (undefined1)uVar2;
  param_3[4] = (undefined1)local_34;
  local_34._1_1_ = (undefined1)(uVar2 >> 8);
  param_3[5] = local_34._1_1_;
  local_34._2_1_ = (undefined1)(uVar2 >> 0x10);
  param_3[6] = local_34._2_1_;
  local_34._3_1_ = (undefined1)(uVar2 >> 0x18);
  param_3[7] = local_34._3_1_;
  local_30._0_1_ = (undefined1)uVar8;
  param_3[8] = (undefined1)local_30;
  local_30._1_1_ = (undefined1)(uVar8 >> 8);
  param_3[9] = local_30._1_1_;
  local_30._2_1_ = (undefined1)(uVar8 >> 0x10);
  param_3[10] = local_30._2_1_;
  local_30._3_1_ = (undefined1)(uVar8 >> 0x18);
  param_3[0xb] = local_30._3_1_;
  local_2c._0_1_ = (undefined1)uVar4;
  param_3[0xc] = (undefined1)local_2c;
  local_2c._1_1_ = (undefined1)(uVar4 >> 8);
  param_3[0xd] = local_2c._1_1_;
  local_2c._2_1_ = (undefined1)(uVar4 >> 0x10);
  param_3[0xe] = local_2c._2_1_;
  local_2c._3_1_ = (undefined1)(uVar4 >> 0x18);
  param_3[0xf] = local_2c._3_1_;
  return;
}

/* ----------------------------------------------------------------
 * rsa_public_block @ 0x3003CA30  (примерный размер ~368 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 6
 * Вызывает: memset, nn_cmp, nn_decode, nn_digits, nn_encode, nn_mod_exp
 * Вызывают: rsa_public_decrypt, rsa_public_encrypt
 * Константы: 0x3003CA30, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4
rsa_public_block(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined2 *param_4,
                int *param_5)

{
  undefined2 uVar1;
  undefined2 uVar2;
  short sVar3;
  undefined4 uVar4;
  undefined1 auStack_230 [132];
  undefined1 auStack_1ac [132];
  undefined1 auStack_128 [132];
  undefined1 auStack_a4 [132];
  
  memset(auStack_128,0,0x84);
  memset(auStack_1ac,0,0x84);
  memset(auStack_230,0,0x84);
  nn_decode(auStack_1ac,0x21,param_1,param_2);
  nn_decode(auStack_230,0x21,param_5 + 1,0x80);
  nn_decode(auStack_a4,0x21,param_5 + 0x21,0x80);
  uVar1 = nn_digits(auStack_230,0x21);
  uVar2 = nn_digits(auStack_a4,0x21);
  sVar3 = nn_cmp(auStack_1ac,auStack_230,uVar1);
  if (sVar3 < 0) {
    nn_mod_exp(auStack_128,auStack_1ac,auStack_a4,uVar2,auStack_230,uVar1);
    *param_4 = (short)((int)(*param_5 + 7U & 0xffff) >> 3);
    nn_encode(param_3,*param_4,auStack_128,uVar1);
    uVar4 = 0;
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

/* ----------------------------------------------------------------
 * rsa_private_block @ 0x3003CBA0  (примерный размер ~1052 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 12
 * Вызывает: memset, nn_add, nn_assign_zero, nn_cmp, nn_decode, nn_digits, nn_encode, nn_mod, nn_mod_exp, nn_mod_mult, nn_mult, nn_sub
 * Вызывают: rsa_private_decrypt, rsa_private_encrypt
 * Константы: 0x3003CBA0, 0xFFFFFFFF
 * Данные: DAT_3003d484, DAT_3003d488, DAT_3003d48c, DAT_3003d490
 * ---------------------------------------------------------------- */
undefined4
rsa_private_block(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined2 *param_4)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  short sVar5;
  undefined4 uVar6;
  int *piVar7;
  
  iVar1 = -DAT_3003d484;
  piVar7 = *(int **)(&stack0x00000638 + iVar1);
  memset(&stack0x00000170 + iVar1,0,0x84);
  memset(&stack0x000002fc + iVar1,0,0x84);
  memset(&stack0x00000380 + iVar1,0,0x84);
  memset(&stack0xffffffdc + DAT_3003d488 + iVar1,0,0x84);
  memset(&stack0xffffffdc + DAT_3003d48c + iVar1,0,0x84);
  memset(&stack0x000001f4 + iVar1,0,0x84);
  memset(&stack0x00000068 + iVar1,0,0x84);
  memset(&stack0x000000ec + iVar1,0,0x84);
  memset(&stack0x00000278 + iVar1,0,0x84);
  memset(&stack0x0000050c + iVar1,0,0x84);
  memset(&stack0xffffffe4 + iVar1,0,0x84);
  nn_decode(&stack0x00000170 + iVar1,0x21,param_1,param_2);
  nn_decode(&stack0xffffffdc + DAT_3003d490 + iVar1,0x21,piVar7 + 1,0x80);
  nn_decode(&stack0x000000ec + iVar1,0x21,piVar7 + 0x61,0x40);
  nn_decode(&stack0x00000278 + iVar1,0x21,piVar7 + 0x81,0x40);
  nn_decode(&stack0xffffffdc + DAT_3003d488 + iVar1,0x21,piVar7 + 0xa1,0x40);
  nn_decode(&stack0xffffffdc + DAT_3003d48c + iVar1,0x21,piVar7 + 0xc1,0x40);
  nn_decode(&stack0x0000050c + iVar1,0x21,piVar7 + 0xe1,0x40);
  uVar2 = nn_digits(&stack0x00000170 + iVar1,0x21);
  uVar3 = nn_digits(&stack0xffffffdc + DAT_3003d490 + iVar1,0x21);
  uVar4 = nn_digits(&stack0x000000ec + iVar1,0x21);
  sVar5 = nn_cmp(&stack0x00000170 + iVar1,&stack0xffffffdc + DAT_3003d490 + iVar1,uVar3);
  if (sVar5 < 0) {
    *(uint *)(&stack0xffffffdc + iVar1) = (uint)uVar4;
    nn_mod(&stack0x000002fc + iVar1,&stack0x00000170 + iVar1,uVar2,&stack0x000000ec + iVar1);
    *(uint *)(&stack0xffffffdc + iVar1) = (uint)uVar4;
    nn_mod(&stack0x00000380 + iVar1,&stack0x00000170 + iVar1,uVar2,&stack0x00000278 + iVar1);
    *(undefined1 **)(&stack0xffffffdc + iVar1) = &stack0x000000ec + iVar1;
    *(uint *)(&stack0xffffffe0 + iVar1) = (uint)uVar4;
    nn_mod_exp(&stack0x000001f4 + iVar1,&stack0x000002fc + iVar1,
               &stack0xffffffdc + DAT_3003d488 + iVar1,uVar4);
    nn_assign_zero(&stack0x00000068 + iVar1,uVar3);
    *(undefined1 **)(&stack0xffffffdc + iVar1) = &stack0x00000278 + iVar1;
    *(uint *)(&stack0xffffffe0 + iVar1) = (uint)uVar4;
    nn_mod_exp(&stack0x00000068 + iVar1,&stack0x00000380 + iVar1,
               &stack0xffffffdc + DAT_3003d48c + iVar1,uVar4);
    sVar5 = nn_cmp(&stack0x000001f4 + iVar1,&stack0x00000068 + iVar1,uVar4);
    if (sVar5 < 0) {
      nn_sub(&stack0xffffffe4 + iVar1,&stack0x00000068 + iVar1,&stack0x000001f4 + iVar1,uVar4);
      nn_sub(&stack0xffffffe4 + iVar1,&stack0x000000ec + iVar1,&stack0xffffffe4 + iVar1,uVar4);
    }
    else {
      nn_sub(&stack0xffffffe4 + iVar1,&stack0x000001f4 + iVar1,&stack0x00000068 + iVar1,uVar4);
    }
    *(uint *)(&stack0xffffffdc + iVar1) = (uint)uVar4;
    nn_mod_mult(&stack0xffffffe4 + iVar1,&stack0xffffffe4 + iVar1,&stack0x0000050c + iVar1,
                &stack0x000000ec + iVar1);
    nn_mult(&stack0xffffffe4 + iVar1,&stack0xffffffe4 + iVar1,&stack0x00000278 + iVar1,uVar4);
    nn_add(&stack0xffffffe4 + iVar1,&stack0xffffffe4 + iVar1,&stack0x00000068 + iVar1,uVar3);
    *param_4 = (short)((int)(*piVar7 + 7U & 0xffff) >> 3);
    nn_encode(param_3,*param_4,&stack0xffffffe4 + iVar1,uVar3);
    uVar6 = 0;
  }
  else {
    uVar6 = 0xffffffff;
  }
  return uVar6;
}

/* ----------------------------------------------------------------
 * rsa_private_encrypt @ 0x3003CFBC  (примерный размер ~252 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: memcpy, memset, rsa_private_block
 * Константы: 0x3003CFBC
 * ---------------------------------------------------------------- */
int rsa_private_encrypt(void *param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                       int *param_5)

{
  short sVar1;
  int iVar2;
  short sVar3;
  undefined1 auStackY_80a4 [32764];
  undefined1 local_a4 [128];
  
  memset(local_a4,0,0x80);
  iVar2 = (int)(*param_5 + 7U & 0xffff) >> 3;
  sVar1 = (short)iVar2;
  if ((uint)(int)sVar1 < (param_2 & 0xffff) + 0xb) {
    iVar2 = -1;
  }
  else {
    local_a4[0] = 0;
    local_a4[1] = 1;
    for (sVar3 = 2; (int)sVar3 < (int)(((int)sVar1 - (param_2 & 0xffff)) + -1); sVar3 = sVar3 + 1) {
      local_a4[sVar3] = 0xff;
    }
    local_a4[sVar3] = 0;
    memcpy(local_a4 + (short)(sVar3 + 1),param_1,param_2 & 0xffff);
    sVar1 = rsa_private_block(local_a4,iVar2,param_3,param_4,param_5);
    iVar2 = (int)sVar1;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * rsa_public_decrypt @ 0x3003D0B8  (примерный размер ~360 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 3
 * Вызывает: memcpy, memset, rsa_public_block
 * Вызывают: crypto_rsa_decrypt
 * Константы: 0x3003D0B8
 * ---------------------------------------------------------------- */
int rsa_public_decrypt(undefined4 param_1,uint param_2,void *param_3,ushort *param_4,int *param_5)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  char acStackY_80a4 [32760];
  ushort local_a8 [2];
  char local_a4 [128];
  
  memset(local_a4,0,0x80);
  uVar1 = (int)(*param_5 + 7U & 0xffff) >> 3;
  if (uVar1 < (param_2 & 0xffff)) {
    iVar3 = -1;
  }
  else {
    sVar2 = rsa_public_block(param_1,param_2,local_a4,local_a8,param_5);
    if (sVar2 == 0) {
      if (local_a8[0] == uVar1) {
        if ((local_a4[0] == '\0') && (local_a4[1] == '\x01')) {
          for (sVar2 = 2; ((int)sVar2 < (int)(uVar1 - 1) && (local_a4[sVar2] == -1));
              sVar2 = sVar2 + 1) {
          }
          if (local_a4[sVar2] == '\0') {
            *param_4 = (short)uVar1 - (sVar2 + 1);
            if (uVar1 < *param_4 + 0xb) {
              iVar3 = -1;
            }
            else {
              memcpy(param_3,local_a4 + (short)(sVar2 + 1),(uint)*param_4);
              iVar3 = 0;
            }
          }
          else {
            iVar3 = -1;
          }
        }
        else {
          iVar3 = -1;
        }
      }
      else {
        iVar3 = -1;
      }
    }
    else {
      iVar3 = (int)sVar2;
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * rsa_public_encrypt @ 0x3003D220  (примерный размер ~252 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 3
 * Вызывает: memcpy, memset, rsa_public_block
 * Вызывают: crypto_rsa_encrypt
 * Константы: 0x3003D220
 * ---------------------------------------------------------------- */
int rsa_public_encrypt(void *param_1,uint param_2,undefined4 param_3,undefined4 param_4,int *param_5
                      )

{
  short sVar1;
  int iVar2;
  short sVar3;
  undefined1 auStackY_80a4 [32764];
  undefined1 local_a4 [128];
  
  memset(local_a4,0,0x80);
  iVar2 = (int)(*param_5 + 7U & 0xffff) >> 3;
  sVar1 = (short)iVar2;
  if ((uint)(int)sVar1 < (param_2 & 0xffff) + 0xb) {
    iVar2 = -1;
  }
  else {
    local_a4[0] = 0;
    local_a4[1] = 1;
    for (sVar3 = 2; (int)sVar3 < (int)(((int)sVar1 - (param_2 & 0xffff)) + -1); sVar3 = sVar3 + 1) {
      local_a4[sVar3] = 0xff;
    }
    local_a4[sVar3] = 0;
    memcpy(local_a4 + (short)(sVar3 + 1),param_1,param_2 & 0xffff);
    sVar1 = rsa_public_block(local_a4,iVar2,param_3,param_4,param_5);
    iVar2 = (int)sVar1;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * rsa_private_decrypt @ 0x3003D31C  (примерный размер ~376 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: memcpy, memset, rsa_private_block
 * Константы: 0x3003D31C
 * ---------------------------------------------------------------- */
int rsa_private_decrypt(undefined4 param_1,uint param_2,void *param_3,ushort *param_4,int *param_5)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  char acStackY_80a4 [32760];
  ushort local_a8 [2];
  char local_a4 [128];
  
  memset(local_a4,0,0x80);
  uVar1 = (int)(*param_5 + 7U & 0xffff) >> 3;
  if (uVar1 < (param_2 & 0xffff)) {
    iVar3 = -1;
  }
  else {
    sVar2 = rsa_private_block(param_1,param_2,local_a4,local_a8,param_5);
    if (sVar2 == 0) {
      if (local_a8[0] == uVar1) {
        if ((local_a4[0] == '\0') && (local_a4[1] == '\x01')) {
          for (sVar2 = 2; ((int)sVar2 < (int)(uVar1 - 1) && (local_a4[sVar2] == -1));
              sVar2 = sVar2 + 1) {
          }
          if (local_a4[sVar2] == '\0') {
            *param_4 = (short)uVar1 - (sVar2 + 1);
            if (uVar1 < *param_4 + 0xb) {
              iVar3 = -1;
            }
            else {
              memcpy(param_3,local_a4 + (short)(sVar2 + 1),(uint)*param_4);
              iVar3 = 0;
            }
          }
          else {
            iVar3 = -1;
          }
        }
        else {
          iVar3 = -1;
        }
      }
      else {
        iVar3 = -1;
      }
    }
    else {
      iVar3 = (int)sVar2;
    }
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * crypto_hash @ 0x3003EB28  (примерный размер ~272 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 3
 * Вызывает: encrypt_lock_md5_data, printf, secDataSha
 * Вызывают: create_crypto_key
 * Константы: 0xFFFFFFFF, 0x3003EB28
 * Данные: DAT_3003f270, DAT_3003f274, DAT_3003f278, DAT_3003f27c, DAT_3003f280
 * ---------------------------------------------------------------- */
undefined4 crypto_hash(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((param_1 == 0) || (param_4 == 0)) || (param_5 == (int *)0x0)) {
    printf(DAT_3003f270);
    uVar1 = 0xffffffff;
  }
  else if (param_2 < 1) {
    printf(DAT_3003f274);
    uVar1 = 0xffffffff;
  }
  else {
    if (param_3 == 0) {
      if (*param_5 < 0x10) {
        printf(DAT_3003f278);
        return 0xffffffff;
      }
      encrypt_lock_md5_data(param_1,param_2,param_4);
      *param_5 = 0x10;
    }
    else {
      if (param_3 != 1) {
        printf(DAT_3003f280);
        return 0xffffffff;
      }
      if (*param_5 < 0x14) {
        printf(DAT_3003f278);
        return 0xffffffff;
      }
      iVar2 = secDataSha(param_1,param_2,param_4);
      if (iVar2 != 0) {
        printf(DAT_3003f27c);
        return 0xffffffff;
      }
      *param_5 = 0x14;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * crypto_encrypt @ 0x3003EE9C  (примерный размер ~248 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: crypto_aes_encrypt_block, crypto_aes_init, printf
 * Константы: 0xFFFFFFFF, 0x3003EE9C
 * Данные: DAT_3003f2a8, DAT_3003f2ac, DAT_3003f2b0, DAT_3003f2b4
 * ---------------------------------------------------------------- */
undefined4
crypto_encrypt(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  short sVar1;
  undefined4 uVar2;
  undefined1 auStack_238 [540];
  
  if ((((param_1 == 0) || (param_4 == 0)) || (param_6 == 0)) || (param_7 == 0)) {
    printf(DAT_3003f2a8);
    uVar2 = 0xffffffff;
  }
  else if ((param_2 < 1) || (param_5 != 0x10)) {
    printf(DAT_3003f2ac);
    uVar2 = 0xffffffff;
  }
  else {
    crypto_aes_init(auStack_238,param_4,0x80,1,0);
    if (param_3 == 0) {
      sVar1 = crypto_aes_encrypt_block(auStack_238,param_1,param_2,param_6,param_7);
      if (sVar1 == 0) {
        uVar2 = 0;
      }
      else {
        printf(DAT_3003f2b0);
        uVar2 = 0xffffffff;
      }
    }
    else {
      printf(DAT_3003f2b4);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * crypto_decrypt @ 0x3003EF94  (примерный размер ~248 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: crypto_aes_decrypt_block, crypto_aes_init, printf
 * Константы: 0xFFFFFFFF, 0x3003EF94
 * Данные: DAT_3003f2b8, DAT_3003f2bc, DAT_3003f2c0, DAT_3003f2c4
 * ---------------------------------------------------------------- */
undefined4
crypto_decrypt(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
              undefined4 param_7)

{
  short sVar1;
  undefined4 uVar2;
  undefined1 auStack_234 [540];
  
  if ((((param_1 == 0) || (param_2 == 0)) || (param_6 == 0)) || (param_4 == 0)) {
    printf(DAT_3003f2b8);
    uVar2 = 0xffffffff;
  }
  else if ((param_2 < 1) || (param_5 != 0x10)) {
    printf(DAT_3003f2bc);
    uVar2 = 0xffffffff;
  }
  else {
    crypto_aes_init(auStack_234,param_4,0x80,1,0);
    if (param_3 == 0) {
      sVar1 = crypto_aes_decrypt_block(auStack_234,param_1,param_2,param_6,param_7);
      if (sVar1 == 0) {
        uVar2 = 0;
      }
      else {
        printf(DAT_3003f2c0);
        uVar2 = 0xffffffff;
      }
    }
    else {
      printf(DAT_3003f2c4);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * crypto_rsa_encrypt @ 0x3003F08C  (примерный размер ~196 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: printf, rsa_public_encrypt
 * Константы: 0xFFFFFFFF, 0x3003F08C
 * Данные: DAT_3003f2c8, DAT_3003f2cc, DAT_3003f2d0
 * ---------------------------------------------------------------- */
undefined4
crypto_rsa_encrypt(int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  short sVar1;
  undefined4 uVar2;
  
  if ((((param_1 == 0) || (param_3 == 0)) || (param_5 == 0)) || (param_6 == 0)) {
    printf(DAT_3003f2c8);
    uVar2 = 0xffffffff;
  }
  else if (((int)param_2 < 1) || (param_4 != 0x208)) {
    printf(DAT_3003f2cc);
    uVar2 = 0xffffffff;
  }
  else {
    sVar1 = rsa_public_encrypt(param_1,param_2 & 0xffff,param_5,param_6,param_3 + 0x104);
    if (sVar1 == 0) {
      uVar2 = 0;
    }
    else {
      printf(DAT_3003f2d0);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * crypto_rsa_decrypt @ 0x3003F150  (примерный размер ~196 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: printf, rsa_public_decrypt
 * Константы: 0xFFFFFFFF, 0x3003F150
 * Данные: DAT_3003f2d4, DAT_3003f2d8, DAT_3003f2dc
 * ---------------------------------------------------------------- */
undefined4
crypto_rsa_decrypt(int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  short sVar1;
  undefined4 uVar2;
  
  if ((((param_1 == 0) || (param_3 == 0)) || (param_5 == 0)) || (param_6 == 0)) {
    printf(DAT_3003f2d4);
    uVar2 = 0xffffffff;
  }
  else if (((int)param_2 < 1) || (param_4 != 0x208)) {
    printf(DAT_3003f2d8);
    uVar2 = 0xffffffff;
  }
  else {
    sVar1 = rsa_public_decrypt(param_1,param_2 & 0xffff,param_5,param_6,param_3 + 0x104);
    if (sVar1 == 0) {
      uVar2 = 0;
    }
    else {
      printf(DAT_3003f2dc);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * crypto_rand @ 0x3003F214  (примерный размер ~212 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: printf, ran_next, ran_seed
 * Константы: 0xFFFFFFFF, 0x3003F214
 * Данные: DAT_3003f2e0, DAT_3003f2e4
 * ---------------------------------------------------------------- */
undefined4 crypto_rand(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    printf(DAT_3003f2e0);
    uVar1 = 0xffffffff;
  }
  else if (param_2 == 4) {
    ran_seed(1);
    uVar1 = ran_next();
    *param_1 = uVar1;
    uVar1 = 0;
  }
  else {
    printf(DAT_3003f2e4);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * __bswap16 @ 0x300457A8  (примерный размер ~32 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300457A8
 * ---------------------------------------------------------------- */
uint __bswap16(uint param_1)

{
  return (param_1 << 0x10 | param_1) >> 8 & 0xffff;
}

/* ----------------------------------------------------------------
 * __bswap32 @ 0x300457C8  (примерный размер ~40 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300457C8
 * ---------------------------------------------------------------- */
uint __bswap32(uint param_1)

{
  return param_1 >> 8 & 0xff00 | param_1 >> 0x18 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
}

/* ----------------------------------------------------------------
 * log_buf_copy @ 0x30062BA8  (примерный размер ~192 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: semGive, semTake, vxprintk_get_len
 * Константы: 0x30062BA8, 0xFFFFFFFF
 * Данные: DAT_30063144, DAT_30063148, DAT_3006314c
 * ---------------------------------------------------------------- */
int log_buf_copy(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  semTake(*DAT_30063148,0xffffffff);
  iVar1 = vxprintk_get_len();
  if ((param_2 < 0) || (iVar1 <= param_2)) {
    param_3 = -1;
  }
  else {
    if (iVar1 - param_2 < param_3) {
      param_3 = iVar1 - param_2;
    }
    iVar3 = *(int *)(*DAT_30063144 + 8);
    iVar2 = param_3;
    while (0 < iVar2) {
      iVar2 = iVar2 + -1;
      *(undefined1 *)(param_1 + iVar2) =
           *(undefined1 *)
            (*(int *)(*DAT_30063144 + 0x14) + (param_2 + (iVar3 - iVar1) + iVar2 & DAT_3006314c));
    }
  }
  semGive(*DAT_30063148);
  return param_3;
}

/* ----------------------------------------------------------------
 * FUN_30062c68 @ 0x30062C68  (примерный размер ~220 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30062d44, vxprintk_write
 * Константы: 0x30062C68
 * Данные: DAT_30063144, DAT_3006314c
 * ---------------------------------------------------------------- */
void FUN_30062c68(undefined1 param_1)

{
  *(undefined1 *)(*(int *)(*DAT_30063144 + 0x14) + (*(uint *)(*DAT_30063144 + 8) & DAT_3006314c)) =
       param_1;
  *(int *)(*DAT_30063144 + 8) = *(int *)(*DAT_30063144 + 8) + 1;
  if (*(uint *)(*DAT_30063144 + 0x10) <
      (uint)(*(int *)(*DAT_30063144 + 8) - *(int *)(*DAT_30063144 + 4))) {
    *(int *)(*DAT_30063144 + 4) = *(int *)(*DAT_30063144 + 8) - *(int *)(*DAT_30063144 + 0x10);
  }
  if (*(uint *)(*DAT_30063144 + 0xc) < *(uint *)(*DAT_30063144 + 0x10)) {
    *(int *)(*DAT_30063144 + 0xc) = *(int *)(*DAT_30063144 + 0xc) + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30062d44 @ 0x30062D44  (примерный размер ~220 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_30062c68, omTimerGet, sprintf
 * Вызывают: FUN_30062e20, vxprintk_write
 * Константы: 0x30062D44
 * Данные: DAT_30063150, DAT_30063154, DAT_30063158
 * ---------------------------------------------------------------- */
int FUN_30062d44(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  char acStack_4c [52];
  
  iVar2 = 0;
  if ((*DAT_30063150 != 0) && (*DAT_30063150 = 0, *DAT_30063154 != 0)) {
    iVar2 = omTimerGet();
    iVar2 = sprintf(acStack_4c,DAT_30063158,-iVar2 - 1U >> 5);
    for (pcVar1 = acStack_4c; pcVar1 < acStack_4c + iVar2; pcVar1 = pcVar1 + 1) {
      FUN_30062c68((int)*pcVar1);
    }
  }
  FUN_30062c68(param_1);
  if ((char)param_1 == '\n') {
    *DAT_30063150 = 1;
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_30062e20 @ 0x30062E20  (примерный размер ~136 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_30062d44, semGive, semTake, vsnprintf
 * Вызывают: vxprintk
 * Константы: 0x30062E20, 0xFFFFFFFF
 * Данные: DAT_30063148, DAT_3006315c, DAT_30063160
 * ---------------------------------------------------------------- */
int FUN_30062e20(char *param_1,__gnuc_va_list param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  if (*DAT_3006315c == 1) {
    semTake(*DAT_30063148,0xffffffff);
    iVar1 = vsnprintf(DAT_30063160,0x400,param_1,param_2);
    for (pcVar3 = DAT_30063160; *pcVar3 != '\0'; pcVar3 = pcVar3 + 1) {
      iVar2 = FUN_30062d44((int)*pcVar3);
      iVar1 = iVar2 + iVar1;
    }
    semGive(*DAT_30063148);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * QC_adler32 @ 0x30086CD8  (примерный размер ~864 байт)
 * Модуль: lib | Вызывают: 5 | Вызывает: 0
 * Вызывают: FUN_300899a8, QC_deflate, QC_deflateReset, QC_deflateSetDictionary, QC_inflateSetDictionary
 * Константы: 0x30086CD8
 * Данные: DAT_30087148, DAT_3008714c, DAT_30087150, DAT_30087154, DAT_30087158
 * ---------------------------------------------------------------- */
uint QC_adler32(uint param_1,byte *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  uVar2 = DAT_30087148 & param_1 >> 0x10;
  param_1 = param_1 & DAT_30087148;
  if (param_3 == 1) {
    param_1 = param_1 + *param_2;
    if (DAT_3008714c <= param_1) {
      param_1 = param_1 - DAT_3008714c;
    }
    uVar2 = uVar2 + param_1;
    if (DAT_3008714c <= uVar2) {
      uVar2 = uVar2 - DAT_3008714c;
    }
    param_1 = param_1 | uVar2 << 0x10;
  }
  else if (param_2 == (byte *)0x0) {
    param_1 = 1;
  }
  else if (param_3 < 0x10) {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      param_1 = param_1 + *param_2;
      uVar2 = uVar2 + param_1;
      param_2 = param_2 + 1;
    }
    if (DAT_3008714c <= param_1) {
      param_1 = param_1 - DAT_3008714c;
    }
    param_1 = param_1 | (uVar2 - DAT_3008714c *
                                 (uint)((ulonglong)DAT_30087150 * (ulonglong)uVar2 >> 0x2f)) *
                        0x10000;
  }
  else {
    while (DAT_30087154 <= param_3) {
      param_3 = param_3 - DAT_30087154;
      iVar1 = DAT_30087158;
      do {
        iVar4 = param_1 + *param_2;
        iVar5 = iVar4 + (uint)param_2[1];
        iVar6 = iVar5 + (uint)param_2[2];
        iVar7 = iVar6 + (uint)param_2[3];
        iVar8 = iVar7 + (uint)param_2[4];
        iVar9 = iVar8 + (uint)param_2[5];
        iVar10 = iVar9 + (uint)param_2[6];
        iVar11 = iVar10 + (uint)param_2[7];
        iVar12 = iVar11 + (uint)param_2[8];
        iVar13 = iVar12 + (uint)param_2[9];
        iVar14 = iVar13 + (uint)param_2[10];
        iVar15 = iVar14 + (uint)param_2[0xb];
        iVar16 = iVar15 + (uint)param_2[0xc];
        iVar17 = iVar16 + (uint)param_2[0xd];
        pbVar3 = param_2 + 0xf;
        iVar18 = iVar17 + (uint)param_2[0xe];
        param_2 = param_2 + 0x10;
        param_1 = iVar18 + (uint)*pbVar3;
        uVar2 = uVar2 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 + iVar12 +
                iVar13 + iVar14 + iVar15 + iVar16 + iVar17 + iVar18 + param_1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      param_1 = param_1 - DAT_3008714c *
                          (uint)((ulonglong)DAT_30087150 * (ulonglong)param_1 >> 0x2f);
      uVar2 = uVar2 - DAT_3008714c * (uint)((ulonglong)DAT_30087150 * (ulonglong)uVar2 >> 0x2f);
    }
    if (param_3 != 0) {
      for (; 0xf < param_3; param_3 = param_3 - 0x10) {
        iVar1 = param_1 + *param_2;
        iVar4 = iVar1 + (uint)param_2[1];
        iVar5 = iVar4 + (uint)param_2[2];
        iVar6 = iVar5 + (uint)param_2[3];
        iVar7 = iVar6 + (uint)param_2[4];
        iVar8 = iVar7 + (uint)param_2[5];
        iVar9 = iVar8 + (uint)param_2[6];
        iVar10 = iVar9 + (uint)param_2[7];
        iVar11 = iVar10 + (uint)param_2[8];
        iVar12 = iVar11 + (uint)param_2[9];
        iVar13 = iVar12 + (uint)param_2[10];
        iVar14 = iVar13 + (uint)param_2[0xb];
        iVar15 = iVar14 + (uint)param_2[0xc];
        iVar16 = iVar15 + (uint)param_2[0xd];
        pbVar3 = param_2 + 0xf;
        iVar17 = iVar16 + (uint)param_2[0xe];
        param_2 = param_2 + 0x10;
        param_1 = iVar17 + (uint)*pbVar3;
        uVar2 = uVar2 + iVar1 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 +
                iVar12 + iVar13 + iVar14 + iVar15 + iVar16 + iVar17 + param_1;
      }
      for (; param_3 != 0; param_3 = param_3 - 1) {
        param_1 = param_1 + *param_2;
        uVar2 = uVar2 + param_1;
        param_2 = param_2 + 1;
      }
      param_1 = param_1 - DAT_3008714c *
                          (uint)((ulonglong)DAT_30087150 * (ulonglong)param_1 >> 0x2f);
      uVar2 = uVar2 - DAT_3008714c * (uint)((ulonglong)DAT_30087150 * (ulonglong)uVar2 >> 0x2f);
    }
    param_1 = param_1 | uVar2 << 0x10;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * QC_adler32_combine @ 0x30087038  (примерный размер ~300 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30087038
 * Данные: DAT_30087148, DAT_3008714c, DAT_30087150, DAT_3008715c, DAT_30087160
 * ---------------------------------------------------------------- */
uint QC_adler32_combine(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = param_3 - DAT_3008714c * (uint)((ulonglong)DAT_30087150 * (ulonglong)param_3 >> 0x2f);
  uVar3 = (param_1 & DAT_30087148) * iVar1;
  uVar2 = (param_1 & DAT_30087148) + (param_2 & DAT_30087148) + DAT_3008715c;
  uVar3 = (uVar3 - DAT_3008714c * (uint)((ulonglong)DAT_30087150 * (ulonglong)uVar3 >> 0x2f)) +
          (((DAT_30087148 & param_1 >> 0x10) + (DAT_30087148 & param_2 >> 0x10)) - iVar1) +
          DAT_3008714c;
  if (DAT_3008714c < uVar2) {
    uVar2 = uVar2 - DAT_3008714c;
  }
  if (DAT_3008714c < uVar2) {
    uVar2 = uVar2 - DAT_3008714c;
  }
  if (DAT_30087160 < uVar3) {
    uVar3 = uVar3 - DAT_30087160;
  }
  if (DAT_3008714c < uVar3) {
    uVar3 = uVar3 - DAT_3008714c;
  }
  return uVar2 | uVar3 << 0x10;
}

/* ----------------------------------------------------------------
 * QC_compress2 @ 0x30087164  (примерный размер ~224 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 3
 * Вызывает: QC_deflate, QC_deflateEnd, QC_deflateInit_
 * Вызывают: QC_compress
 * Константы: 0x30087164
 * Данные: DAT_300872a0
 * ---------------------------------------------------------------- */
int QC_compress2(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_48;
  int local_44;
  int local_40;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_44 = *param_2;
  if (local_44 == *param_2) {
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_54 = param_3;
    local_50 = param_4;
    local_48 = param_1;
    iVar1 = QC_deflateInit_(&local_54,param_5,DAT_300872a0,0x38);
    if (iVar1 == 0) {
      iVar1 = QC_deflate(&local_54,4);
      if (iVar1 == 1) {
        *param_2 = local_40;
        iVar1 = QC_deflateEnd(&local_54);
      }
      else {
        QC_deflateEnd(&local_54);
        if (iVar1 == 0) {
          iVar1 = -5;
        }
      }
    }
  }
  else {
    iVar1 = -5;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * QC_compress @ 0x30087244  (примерный размер ~60 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: QC_compress2
 * Константы: 0x30087244, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
void QC_compress(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  QC_compress2(param_1,param_2,param_3,param_4,0xffffffff);
  return;
}

/* ----------------------------------------------------------------
 * QC_compressBound @ 0x30087280  (примерный размер ~36 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: QC_deflateBound
 * Константы: 0x30087280
 * ---------------------------------------------------------------- */
int QC_compressBound(uint param_1)

{
  return param_1 + (param_1 >> 0xc) + (param_1 >> 0xe) + 0xb;
}

/* ----------------------------------------------------------------
 * QC_get_crc_table @ 0x300872A4  (примерный размер ~8 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300872A4
 * Данные: DAT_30087b70
 * ---------------------------------------------------------------- */
undefined4 QC_get_crc_table(void)

{
  return DAT_30087b70;
}

/* ----------------------------------------------------------------
 * FUN_300872ac @ 0x300872AC  (примерный размер ~852 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: QC_crc32
 * Константы: 0x300872AC
 * Данные: DAT_30087b70, DAT_30087b74, DAT_30087b78, DAT_30087b7c
 * ---------------------------------------------------------------- */
uint FUN_300872ac(uint param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  
  param_1 = ~param_1;
  for (; (param_3 != 0 && (((uint)param_2 & 3) != 0)); param_2 = (uint *)((int)param_2 + 1)) {
    param_1 = *(uint *)(DAT_30087b70 + ((param_1 ^ (byte)*param_2) & 0xff) * 4) ^ param_1 >> 8;
    param_3 = param_3 - 1;
  }
  for (; 0x1f < param_3; param_3 = param_3 - 0x20) {
    param_1 = param_1 ^ *param_2;
    uVar2 = *(uint *)(DAT_30087b74 + (param_1 & 0xff) * 4) ^
            *(uint *)(DAT_30087b78 + (param_1 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b7c + (param_1 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b70 + (param_1 >> 0x18) * 4) ^ param_2[1];
    uVar2 = *(uint *)(DAT_30087b74 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b78 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b7c + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b70 + (uVar2 >> 0x18) * 4) ^ param_2[2];
    uVar2 = *(uint *)(DAT_30087b74 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b78 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b7c + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b70 + (uVar2 >> 0x18) * 4) ^ param_2[3];
    uVar2 = *(uint *)(DAT_30087b74 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b78 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b7c + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b70 + (uVar2 >> 0x18) * 4) ^ param_2[4];
    uVar2 = *(uint *)(DAT_30087b74 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b78 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b7c + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b70 + (uVar2 >> 0x18) * 4) ^ param_2[5];
    puVar1 = param_2 + 7;
    uVar2 = *(uint *)(DAT_30087b74 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b78 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b7c + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b70 + (uVar2 >> 0x18) * 4) ^ param_2[6];
    param_2 = param_2 + 8;
    uVar2 = *(uint *)(DAT_30087b74 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b78 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b7c + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b70 + (uVar2 >> 0x18) * 4) ^ *puVar1;
    param_1 = *(uint *)(DAT_30087b74 + (uVar2 & 0xff) * 4) ^
              *(uint *)(DAT_30087b78 + (uVar2 >> 8 & 0xff) * 4) ^
              *(uint *)(DAT_30087b7c + (uVar2 >> 0x10 & 0xff) * 4) ^
              *(uint *)(DAT_30087b70 + (uVar2 >> 0x18) * 4);
  }
  for (; 3 < param_3; param_3 = param_3 - 4) {
    param_1 = param_1 ^ *param_2;
    param_1 = *(uint *)(DAT_30087b74 + (param_1 & 0xff) * 4) ^
              *(uint *)(DAT_30087b78 + (param_1 >> 8 & 0xff) * 4) ^
              *(uint *)(DAT_30087b7c + (param_1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(DAT_30087b70 + (param_1 >> 0x18) * 4);
    param_2 = param_2 + 1;
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    param_1 = *(uint *)(DAT_30087b70 + ((param_1 ^ (byte)*param_2) & 0xff) * 4) ^ param_1 >> 8;
    param_2 = (uint *)((int)param_2 + 1);
  }
  return ~param_1;
}

/* ----------------------------------------------------------------
 * FUN_30087600 @ 0x30087600  (примерный размер ~936 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x01000000, 0x30087600
 * Данные: DAT_30087b80, DAT_30087b84, DAT_30087b88, DAT_30087b8c
 * ---------------------------------------------------------------- */
int FUN_30087600(uint param_1,byte *param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = ~((param_1 >> 8 & 0xff00) + (param_1 >> 0x18) + (param_1 & 0xff00) * 0x100 +
           param_1 * 0x1000000);
  for (; (param_3 != 0 && (((uint)param_2 & 3) != 0)); param_2 = param_2 + 1) {
    uVar2 = *(uint *)(DAT_30087b80 + ((uint)*param_2 ^ uVar2 >> 0x18) * 4) ^ uVar2 << 8;
    param_3 = param_3 - 1;
  }
  puVar1 = (uint *)(param_2 + -4);
  for (; 0x1f < param_3; param_3 = param_3 - 0x20) {
    uVar2 = uVar2 ^ puVar1[1];
    uVar2 = *(uint *)(DAT_30087b80 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b84 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b88 + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b8c + (uVar2 >> 0x18) * 4) ^ puVar1[2];
    uVar2 = *(uint *)(DAT_30087b80 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b84 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b88 + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b8c + (uVar2 >> 0x18) * 4) ^ puVar1[3];
    uVar2 = *(uint *)(DAT_30087b80 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b84 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b88 + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b8c + (uVar2 >> 0x18) * 4) ^ puVar1[4];
    uVar2 = *(uint *)(DAT_30087b80 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b84 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b88 + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b8c + (uVar2 >> 0x18) * 4) ^ puVar1[5];
    uVar2 = *(uint *)(DAT_30087b80 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b84 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b88 + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b8c + (uVar2 >> 0x18) * 4) ^ puVar1[6];
    uVar2 = *(uint *)(DAT_30087b80 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b84 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b88 + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b8c + (uVar2 >> 0x18) * 4) ^ puVar1[7];
    puVar1 = puVar1 + 8;
    uVar2 = *(uint *)(DAT_30087b80 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b84 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b88 + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b8c + (uVar2 >> 0x18) * 4) ^ *puVar1;
    uVar2 = *(uint *)(DAT_30087b80 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b84 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b88 + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b8c + (uVar2 >> 0x18) * 4);
  }
  for (; 3 < param_3; param_3 = param_3 - 4) {
    puVar1 = puVar1 + 1;
    uVar2 = uVar2 ^ *puVar1;
    uVar2 = *(uint *)(DAT_30087b80 + (uVar2 & 0xff) * 4) ^
            *(uint *)(DAT_30087b84 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_30087b88 + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(DAT_30087b8c + (uVar2 >> 0x18) * 4);
  }
  puVar1 = puVar1 + 1;
  for (; param_3 != 0; param_3 = param_3 - 1) {
    uVar2 = *(uint *)(DAT_30087b80 + ((uint)(byte)*puVar1 ^ uVar2 >> 0x18) * 4) ^ uVar2 << 8;
    puVar1 = (uint *)((int)puVar1 + 1);
  }
  uVar2 = ~uVar2;
  return (uVar2 >> 8 & 0xff00) + (uVar2 >> 0x18) + (uVar2 & 0xff00) * 0x100 + uVar2 * 0x1000000;
}

/* ----------------------------------------------------------------
 * QC_crc32 @ 0x300879A8  (примерный размер ~100 байт)
 * Модуль: lib | Вызывают: 8 | Вызывает: 1
 * Вызывает: FUN_300872ac
 * Вызывают: FUN_300899a8, FUN_3008b498, FUN_3008b88c, QC_deflate, QC_deflateReset, QC_gzread, QC_gzrewind, QC_gzwrite
 * Константы: 0x300879A8, 0x300879F4
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300879f4) */

undefined4 QC_crc32(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_300872ac(param_1,param_2,param_3);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30087a0c @ 0x30087A0C  (примерный размер ~64 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_30087a4c, QC_crc32_combine
 * Константы: 0x30087A0C
 * ---------------------------------------------------------------- */
uint FUN_30087a0c(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  for (; param_2 != 0; param_2 = param_2 >> 1) {
    if ((param_2 & 1) != 0) {
      uVar1 = uVar1 ^ *param_1;
    }
    param_1 = param_1 + 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30087a4c @ 0x30087A4C  (примерный размер ~52 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30087a0c
 * Вызывают: QC_crc32_combine
 * Константы: 0x30087A4C
 * ---------------------------------------------------------------- */
void FUN_30087a4c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar2 < 0x20; iVar2 = iVar2 + 1) {
    uVar1 = FUN_30087a0c(param_2,*(undefined4 *)(param_2 + iVar2 * 4));
    *(undefined4 *)(param_1 + iVar2 * 4) = uVar1;
  }
  return;
}

/* ----------------------------------------------------------------
 * QC_crc32_combine @ 0x30087A80  (примерный размер ~276 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_30087a0c, FUN_30087a4c
 * Константы: 0x30087A80
 * Данные: DAT_30087b90
 * ---------------------------------------------------------------- */
uint QC_crc32_combine(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int local_118 [32];
  undefined1 auStack_98 [128];
  
  if (param_3 != 0) {
    local_118[0] = DAT_30087b90;
    iVar1 = 1;
    for (iVar2 = 1; iVar2 < 0x20; iVar2 = iVar2 + 1) {
      local_118[iVar2] = iVar1;
      iVar1 = iVar1 << 1;
    }
    FUN_30087a4c(auStack_98,local_118);
    FUN_30087a4c(local_118,auStack_98);
    do {
      FUN_30087a4c(auStack_98,local_118);
      if ((param_3 & 1) != 0) {
        param_1 = FUN_30087a0c(auStack_98,param_1);
      }
      if ((int)param_3 >> 1 == 0) break;
      FUN_30087a4c(local_118,auStack_98);
      if (((int)param_3 >> 1 & 1U) != 0) {
        param_1 = FUN_30087a0c(local_118,param_1);
      }
      param_3 = (int)param_3 >> 2;
    } while (param_3 != 0);
    param_1 = param_1 ^ param_2;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * FUN_30087b94 @ 0x30087B94  (примерный размер ~220 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: memset
 * Вызывают: QC_deflateReset
 * Константы: 0x30087B94
 * Данные: DAT_30088b8c, DAT_30088b90, DAT_30088b94, DAT_30088b98
 * ---------------------------------------------------------------- */
void FUN_30087b94(int param_1)

{
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x2c) << 1;
  *(undefined2 *)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x4c) * 2 + -2) = 0;
  memset(*(void **)(param_1 + 0x44),0,*(int *)(param_1 + 0x4c) * 2 - 2);
  *(uint *)(param_1 + 0x80) = (uint)*(ushort *)(DAT_30088b8c + *(int *)(param_1 + 0x84) * 0xc);
  *(uint *)(param_1 + 0x8c) = (uint)*(ushort *)(DAT_30088b90 + *(int *)(param_1 + 0x84) * 0xc);
  *(uint *)(param_1 + 0x90) = (uint)*(ushort *)(DAT_30088b94 + *(int *)(param_1 + 0x84) * 0xc);
  *(uint *)(param_1 + 0x7c) = (uint)*(ushort *)(DAT_30088b98 + *(int *)(param_1 + 0x84) * 0xc);
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 2;
  *(undefined4 *)(param_1 + 0x60) = 2;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  return;
}

/* ----------------------------------------------------------------
 * QC_deflateReset @ 0x30087C70  (примерный размер ~256 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_30087b94, QC_adler32, QC_crc32, QC_tr_init
 * Вызывают: QC_deflateInit2_
 * Константы: 0x30087C70, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4 QC_deflateReset(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) || (*(int *)(param_1 + 0x20) == 0)) ||
     (*(int *)(param_1 + 0x24) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 2;
    iVar2 = *(int *)(param_1 + 0x1c);
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + 8);
    if (*(int *)(iVar2 + 0x18) < 0) {
      *(int *)(iVar2 + 0x18) = -*(int *)(iVar2 + 0x18);
    }
    if (*(int *)(iVar2 + 0x18) == 0) {
      *(undefined4 *)(iVar2 + 4) = 0x71;
    }
    else {
      *(undefined4 *)(iVar2 + 4) = 0x2a;
    }
    if (*(int *)(iVar2 + 0x18) == 2) {
      uVar1 = QC_crc32(0,0,0);
      *(undefined4 *)(param_1 + 0x30) = uVar1;
    }
    else {
      uVar1 = QC_adler32(0,0,0);
      *(undefined4 *)(param_1 + 0x30) = uVar1;
    }
    *(undefined4 *)(iVar2 + 0x28) = 0;
    QC_tr_init(iVar2);
    FUN_30087b94(iVar2);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_deflateEnd @ 0x30087D70  (примерный размер ~340 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 0
 * Вызывают: FUN_3008b394, QC_compress2, QC_deflateCopy, QC_deflateInit2_
 * Константы: 0xFFFFFFFE, 0x30087D70, 0xFFFFFFFD
 * Данные: DAT_30088cc0
 * ---------------------------------------------------------------- */
undefined4 QC_deflateEnd(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x1c) + 4);
    if ((((iVar2 == 0x2a) || (iVar2 == 0x45)) || (iVar2 == 0x49)) ||
       (((iVar2 == 0x5b || (iVar2 == 0x67)) || ((iVar2 == 0x71 || (iVar2 == DAT_30088cc0)))))) {
      if (*(int *)(*(int *)(param_1 + 0x1c) + 8) != 0) {
        (**(code **)(param_1 + 0x24))
                  (*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(*(int *)(param_1 + 0x1c) + 8));
      }
      if (*(int *)(*(int *)(param_1 + 0x1c) + 0x44) != 0) {
        (**(code **)(param_1 + 0x24))
                  (*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x44))
        ;
      }
      if (*(int *)(*(int *)(param_1 + 0x1c) + 0x40) != 0) {
        (**(code **)(param_1 + 0x24))
                  (*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x40))
        ;
      }
      if (*(int *)(*(int *)(param_1 + 0x1c) + 0x38) != 0) {
        (**(code **)(param_1 + 0x24))
                  (*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x38))
        ;
      }
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c))
      ;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      if (iVar2 == 0x71) {
        uVar1 = 0xfffffffd;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0xfffffffe;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_deflateInit2_ @ 0x30087EC4  (примерный размер ~820 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 2
 * Вызывает: QC_deflateEnd, QC_deflateReset
 * Вызывают: FUN_3008b498, FUN_3008b88c, QC_deflateInit_
 * Константы: 0xFFFFFFFE, 0xFFFFFFFC, 0x30087EC4, 0xFFFFFFFA
 * Данные: DAT_30088cc0, DAT_30088e00, DAT_30088e04, DAT_30088e08, DAT_30088fac, DAT_30088fb0, DAT_300890dc, DAT_300890e0
 * ---------------------------------------------------------------- */
undefined4
QC_deflateInit2_(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
                char *param_7,int param_8)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 1;
  if (((param_7 == (char *)0x0) || (*param_7 != *DAT_30088e00)) || (param_8 != 0x38)) {
    uVar1 = 0xfffffffa;
  }
  else if (param_1 == 0) {
    uVar1 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
    if (*(int *)(param_1 + 0x20) == 0) {
      *(undefined4 *)(param_1 + 0x20) = DAT_30088e04;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      *(undefined4 *)(param_1 + 0x24) = DAT_30088e08;
    }
    if (param_2 == -1) {
      param_2 = 6;
    }
    if (param_4 < 0) {
      iVar3 = 0;
      param_4 = -param_4;
    }
    else if (0xf < param_4) {
      iVar3 = 2;
      param_4 = param_4 + -0x10;
    }
    if ((((param_5 - 1U < 9) && (param_3 == 8)) &&
        ((param_4 - 8U < 8 && ((-1 < param_2 && (param_2 < 10)))))) && (param_6 < 5)) {
      if (param_4 == 8) {
        param_4 = 9;
      }
      piVar2 = (int *)(**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x16c0);
      if (piVar2 == (int *)0x0) {
        uVar1 = 0xfffffffc;
      }
      else {
        *(int **)(param_1 + 0x1c) = piVar2;
        *piVar2 = param_1;
        piVar2[6] = iVar3;
        piVar2[7] = 0;
        piVar2[0xc] = param_4;
        piVar2[0xb] = 1 << (piVar2[0xc] & 0xffU);
        piVar2[0xd] = piVar2[0xb] + -1;
        piVar2[0x14] = param_5 + 7;
        piVar2[0x13] = 1 << (piVar2[0x14] & 0xffU);
        piVar2[0x15] = piVar2[0x13] + -1;
        piVar2[0x16] = (uint)((ulonglong)DAT_30088fac * (ulonglong)(piVar2[0x14] + 2) >> 0x21);
        iVar3 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),piVar2[0xb],2);
        piVar2[0xe] = iVar3;
        iVar3 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),piVar2[0xb],2);
        piVar2[0x10] = iVar3;
        iVar3 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),piVar2[0x13],2);
        piVar2[0x11] = iVar3;
        *(int *)((int)piVar2 + DAT_30088fb0) = 1 << (param_5 + 6U & 0xff);
        iVar3 = (**(code **)(param_1 + 0x20))
                          (*(undefined4 *)(param_1 + 0x28),
                           *(undefined4 *)((int)piVar2 + DAT_30088fb0),4);
        piVar2[2] = iVar3;
        piVar2[3] = *(int *)((int)piVar2 + DAT_30088fb0) << 2;
        if ((((piVar2[0xe] == 0) || (piVar2[0x10] == 0)) || (piVar2[0x11] == 0)) || (piVar2[2] == 0)
           ) {
          piVar2[1] = DAT_30088cc0;
          *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(DAT_300890dc + 0x18);
          QC_deflateEnd(param_1);
          uVar1 = 0xfffffffc;
        }
        else {
          *(uint *)((int)piVar2 + DAT_300890e0) =
               iVar3 + (*(uint *)((int)piVar2 + DAT_30088fb0) & 0xfffffffe);
          *(int *)((int)piVar2 + DAT_300890e4) =
               piVar2[2] + *(int *)((int)piVar2 + DAT_30088fb0) * 3;
          piVar2[0x21] = param_2;
          piVar2[0x22] = param_6;
          *(undefined1 *)(piVar2 + 9) = 8;
          uVar1 = QC_deflateReset(param_1);
        }
      }
    }
    else {
      uVar1 = 0xfffffffe;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_deflateInit_ @ 0x300881F8  (примерный размер ~76 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: QC_deflateInit2_
 * Вызывают: QC_compress2
 * Константы: 0x300881F8
 * ---------------------------------------------------------------- */
void QC_deflateInit_(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  QC_deflateInit2_(param_1,param_2,8,0xf,8,0,param_3,param_4);
  return;
}

/* ----------------------------------------------------------------
 * QC_deflateSetDictionary @ 0x30088244  (примерный размер ~428 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: QC_adler32, memcpy
 * Константы: 0x30088244, 0xFFFFFFFE
 * Данные: DAT_300891f8
 * ---------------------------------------------------------------- */
undefined4 QC_deflateSetDictionary(int param_1,void *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint __n;
  int iVar3;
  
  if ((((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) || (param_2 == (void *)0x0)) ||
     ((*(int *)(*(int *)(param_1 + 0x1c) + 0x18) == 2 ||
      ((*(int *)(*(int *)(param_1 + 0x1c) + 0x18) == 1 &&
       (*(int *)(*(int *)(param_1 + 0x1c) + 4) != 0x2a)))))) {
    uVar1 = 0xfffffffe;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x1c);
    if (*(int *)(iVar3 + 0x18) != 0) {
      uVar1 = QC_adler32(*(undefined4 *)(param_1 + 0x30),param_2,param_3);
      *(undefined4 *)(param_1 + 0x30) = uVar1;
    }
    if (param_3 < 3) {
      uVar1 = 0;
    }
    else {
      __n = param_3;
      if ((uint)(*(int *)(iVar3 + 0x2c) - DAT_300891f8) < param_3) {
        __n = *(int *)(iVar3 + 0x2c) - DAT_300891f8;
        param_2 = (void *)((int)param_2 + (param_3 - __n));
      }
      memcpy(*(void **)(iVar3 + 0x38),param_2,__n);
      *(uint *)(iVar3 + 0x6c) = __n;
      *(uint *)(iVar3 + 0x5c) = __n;
      *(uint *)(iVar3 + 0x48) = (uint)**(byte **)(iVar3 + 0x38);
      *(uint *)(iVar3 + 0x48) =
           ((uint)*(byte *)(*(int *)(iVar3 + 0x38) + 1) ^
           *(int *)(iVar3 + 0x48) << (*(uint *)(iVar3 + 0x58) & 0xff)) & *(uint *)(iVar3 + 0x54);
      for (uVar2 = 0; uVar2 <= __n - 3; uVar2 = uVar2 + 1) {
        *(uint *)(iVar3 + 0x48) =
             ((uint)*(byte *)(*(int *)(iVar3 + 0x38) + uVar2 + 2) ^
             *(int *)(iVar3 + 0x48) << (*(uint *)(iVar3 + 0x58) & 0xff)) & *(uint *)(iVar3 + 0x54);
        *(undefined2 *)(*(int *)(iVar3 + 0x40) + (uVar2 & *(uint *)(iVar3 + 0x34)) * 2) =
             *(undefined2 *)(*(int *)(iVar3 + 0x44) + *(int *)(iVar3 + 0x48) * 2);
        *(short *)(*(int *)(iVar3 + 0x44) + *(int *)(iVar3 + 0x48) * 2) = (short)uVar2;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_deflateSetHeader @ 0x300883F0  (примерный размер ~84 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFE, 0x300883F0
 * ---------------------------------------------------------------- */
undefined4 QC_deflateSetHeader(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else if (*(int *)(*(int *)(param_1 + 0x1c) + 0x18) == 2) {
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x1c) = param_2;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_deflatePrime @ 0x30088444  (примерный размер ~96 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30088444, 0xFFFFFFFE
 * Данные: DAT_300893b8, DAT_300893bc, DAT_300893c0
 * ---------------------------------------------------------------- */
undefined4 QC_deflatePrime(int param_1,uint param_2,ushort param_3)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    *(uint *)(*(int *)(param_1 + 0x1c) + DAT_300893b8) = param_2;
    *(ushort *)(*(int *)(param_1 + 0x1c) + DAT_300893c0) =
         param_3 & (short)DAT_300893bc + (short)(1 << (param_2 & 0xff));
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300884a4 @ 0x300884A4  (примерный размер ~76 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: QC_deflate
 * Константы: 0x300884A4
 * ---------------------------------------------------------------- */
void FUN_300884a4(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)((uint)param_2 >> 8);
  *(int *)(param_1 + 0x14) = iVar1 + 1;
  iVar1 = *(int *)(param_1 + 0x14);
  *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)param_2;
  *(int *)(param_1 + 0x14) = iVar1 + 1;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300884f0 @ 0x300884F0  (примерный размер ~176 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 1
 * Вызывает: memcpy
 * Вызывают: FUN_3008a0a0, FUN_3008a2ec, FUN_3008a8bc, QC_deflate
 * Константы: 0x300884F0
 * ---------------------------------------------------------------- */
void FUN_300884f0(int param_1)

{
  size_t __n;
  int *piVar1;
  
  __n = *(uint *)(*(int *)(param_1 + 0x1c) + 0x14);
  if (*(uint *)(param_1 + 0x10) < __n) {
    __n = *(size_t *)(param_1 + 0x10);
  }
  if (__n != 0) {
    memcpy(*(void **)(param_1 + 0xc),*(void **)(*(int *)(param_1 + 0x1c) + 0x10),__n);
    *(size_t *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + __n;
    piVar1 = (int *)(*(int *)(param_1 + 0x1c) + 0x10);
    *piVar1 = *piVar1 + __n;
    *(size_t *)(param_1 + 0x14) = __n + *(int *)(param_1 + 0x14);
    *(size_t *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - __n;
    piVar1 = (int *)(*(int *)(param_1 + 0x1c) + 0x14);
    *piVar1 = *piVar1 - __n;
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x14) == 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x10) =
           *(undefined4 *)(*(int *)(param_1 + 0x1c) + 8);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * QC_deflate @ 0x300885A0  (примерный размер ~4108 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 7
 * Вызывает: FUN_300884a4, FUN_300884f0, QC_adler32, QC_crc32, QC_tr_align, QC_tr_stored_block, memset
 * Вызывают: FUN_3008c560, QC_compress2, QC_deflateParams, QC_gzwrite
 * Константы: 0xFFFFFFFB, 0xFFFFFFFE, 0x300885A0
 * Данные: DAT_30088cc0, DAT_300890dc, DAT_300893bc, DAT_30089afc, DAT_30089b00, DAT_3008a174, DAT_3008a178, DAT_3008a17c
 * ---------------------------------------------------------------- */
uint QC_deflate(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  bool bVar6;
  uint local_dc;
  int local_d4;
  
  if ((((param_1 == (int *)0x0) || (param_1[7] == 0)) || (4 < param_2)) || (param_2 < 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    piVar3 = (int *)param_1[7];
    if (((param_1[3] == 0) || ((*param_1 == 0 && (param_1[1] != 0)))) ||
       ((piVar3[1] == DAT_30088cc0 && (param_2 != 4)))) {
      param_1[6] = *(int *)(DAT_300890dc + 0x10);
      uVar1 = 0xfffffffe;
    }
    else if (param_1[4] == 0) {
      param_1[6] = *(int *)(DAT_300890dc + 0x1c);
      uVar1 = 0xfffffffb;
    }
    else {
      *piVar3 = (int)param_1;
      iVar5 = piVar3[10];
      piVar3[10] = param_2;
      if (piVar3[1] == 0x2a) {
        if (piVar3[6] == 2) {
          iVar2 = QC_crc32(0,0,0);
          param_1[0xc] = iVar2;
          iVar2 = piVar3[5];
          *(undefined1 *)(piVar3[2] + iVar2) = 0x1f;
          piVar3[5] = iVar2 + 1;
          iVar2 = piVar3[5];
          *(undefined1 *)(piVar3[2] + iVar2) = 0x8b;
          piVar3[5] = iVar2 + 1;
          iVar2 = piVar3[5];
          *(undefined1 *)(piVar3[2] + iVar2) = 8;
          piVar3[5] = iVar2 + 1;
          if (piVar3[7] == 0) {
            iVar2 = piVar3[5];
            *(undefined1 *)(piVar3[2] + iVar2) = 0;
            piVar3[5] = iVar2 + 1;
            iVar2 = piVar3[5];
            *(undefined1 *)(piVar3[2] + iVar2) = 0;
            piVar3[5] = iVar2 + 1;
            iVar2 = piVar3[5];
            *(undefined1 *)(piVar3[2] + iVar2) = 0;
            piVar3[5] = iVar2 + 1;
            iVar2 = piVar3[5];
            *(undefined1 *)(piVar3[2] + iVar2) = 0;
            piVar3[5] = iVar2 + 1;
            iVar2 = piVar3[5];
            *(undefined1 *)(piVar3[2] + iVar2) = 0;
            piVar3[5] = iVar2 + 1;
            if (piVar3[0x21] == 9) {
              iVar2 = piVar3[5];
              *(undefined1 *)(piVar3[2] + iVar2) = 2;
              piVar3[5] = iVar2 + 1;
            }
            else if ((piVar3[0x22] < 2) && (1 < piVar3[0x21])) {
              iVar2 = piVar3[5];
              *(undefined1 *)(piVar3[2] + iVar2) = 0;
              piVar3[5] = iVar2 + 1;
            }
            else {
              iVar2 = piVar3[5];
              *(undefined1 *)(piVar3[2] + iVar2) = 4;
              piVar3[5] = iVar2 + 1;
            }
            iVar2 = piVar3[5];
            *(undefined1 *)(piVar3[2] + iVar2) = 3;
            piVar3[5] = iVar2 + 1;
            piVar3[1] = 0x71;
          }
          else {
            iVar2 = *(int *)piVar3[7];
            bVar6 = iVar2 == 0;
            if (bVar6) {
              iVar2 = 0;
            }
            cVar4 = (char)iVar2;
            if (!bVar6) {
              cVar4 = '\x01';
            }
            iVar2 = piVar3[5];
            *(char *)(piVar3[2] + iVar2) =
                 cVar4 + (*(int *)(piVar3[7] + 0x2c) != 0) * '\x02' +
                 (*(int *)(piVar3[7] + 0x10) != 0) * '\x04' +
                 (*(int *)(piVar3[7] + 0x1c) != 0) * '\b' +
                 (*(int *)(piVar3[7] + 0x24) != 0) * '\x10';
            piVar3[5] = iVar2 + 1;
            iVar2 = piVar3[5];
            *(char *)(piVar3[2] + iVar2) = (char)*(undefined4 *)(piVar3[7] + 4);
            piVar3[5] = iVar2 + 1;
            iVar2 = piVar3[5];
            *(char *)(piVar3[2] + iVar2) = (char)((uint)*(undefined4 *)(piVar3[7] + 4) >> 8);
            piVar3[5] = iVar2 + 1;
            iVar2 = piVar3[5];
            *(char *)(piVar3[2] + iVar2) = (char)*(undefined2 *)(piVar3[7] + 6);
            piVar3[5] = iVar2 + 1;
            iVar2 = piVar3[5];
            *(undefined1 *)(piVar3[2] + iVar2) = *(undefined1 *)(piVar3[7] + 7);
            piVar3[5] = iVar2 + 1;
            if (piVar3[0x21] == 9) {
              iVar2 = piVar3[5];
              *(undefined1 *)(piVar3[2] + iVar2) = 2;
              piVar3[5] = iVar2 + 1;
            }
            else if ((piVar3[0x22] < 2) && (1 < piVar3[0x21])) {
              iVar2 = piVar3[5];
              *(undefined1 *)(piVar3[2] + iVar2) = 0;
              piVar3[5] = iVar2 + 1;
            }
            else {
              iVar2 = piVar3[5];
              *(undefined1 *)(piVar3[2] + iVar2) = 4;
              piVar3[5] = iVar2 + 1;
            }
            iVar2 = piVar3[5];
            *(char *)(piVar3[2] + iVar2) = (char)*(undefined4 *)(piVar3[7] + 0xc);
            piVar3[5] = iVar2 + 1;
            if (*(int *)(piVar3[7] + 0x10) != 0) {
              iVar2 = piVar3[5];
              *(char *)(piVar3[2] + iVar2) = (char)*(undefined4 *)(piVar3[7] + 0x14);
              piVar3[5] = iVar2 + 1;
              iVar2 = piVar3[5];
              *(char *)(piVar3[2] + iVar2) = (char)((uint)*(undefined4 *)(piVar3[7] + 0x14) >> 8);
              piVar3[5] = iVar2 + 1;
            }
            if (*(int *)(piVar3[7] + 0x2c) != 0) {
              iVar2 = QC_crc32(param_1[0xc],piVar3[2],piVar3[5]);
              param_1[0xc] = iVar2;
            }
            piVar3[8] = 0;
            piVar3[1] = 0x45;
          }
        }
        else {
          if ((piVar3[0x22] < 2) && (1 < piVar3[0x21])) {
            if (piVar3[0x21] < 6) {
              local_d4 = 1;
            }
            else {
              local_d4 = (piVar3[0x21] != 6) + 2;
            }
          }
          else {
            local_d4 = 0;
          }
          local_dc = DAT_30089afc + piVar3[0xc] * 0x1000 | local_d4 << 6;
          if (piVar3[0x1b] != 0) {
            local_dc = local_dc | 0x20;
          }
          iVar2 = (int)((ulonglong)DAT_30089b00 * (ulonglong)local_dc >> 0x20);
          piVar3[1] = 0x71;
          FUN_300884a4(piVar3,(iVar2 + (local_dc - iVar2 >> 1) >> 4) * 0x1f + 0x1f);
          if (piVar3[0x1b] != 0) {
            FUN_300884a4(piVar3,*(undefined2 *)((int)param_1 + 0x32));
            FUN_300884a4(piVar3,param_1[0xc] & DAT_300893bc);
          }
          iVar2 = QC_adler32(0,0,0);
          param_1[0xc] = iVar2;
        }
      }
      if (piVar3[1] == 0x45) {
        if (*(int *)(piVar3[7] + 0x10) == 0) {
          piVar3[1] = 0x49;
        }
        else {
          uVar1 = piVar3[5];
          while ((uint)piVar3[8] < (*(uint *)(piVar3[7] + 0x14) & DAT_300893bc)) {
            if (piVar3[5] == piVar3[3]) {
              if ((*(int *)(piVar3[7] + 0x2c) != 0) && (uVar1 < (uint)piVar3[5])) {
                iVar2 = QC_crc32(param_1[0xc],piVar3[2] + uVar1,piVar3[5] - uVar1);
                param_1[0xc] = iVar2;
              }
              FUN_300884f0(param_1);
              uVar1 = piVar3[5];
              if (piVar3[5] == piVar3[3]) break;
            }
            iVar2 = piVar3[5];
            *(undefined1 *)(piVar3[2] + iVar2) =
                 *(undefined1 *)(*(int *)(piVar3[7] + 0x10) + piVar3[8]);
            piVar3[5] = iVar2 + 1;
            piVar3[8] = piVar3[8] + 1;
          }
          if ((*(int *)(piVar3[7] + 0x2c) != 0) && (uVar1 < (uint)piVar3[5])) {
            iVar2 = QC_crc32(param_1[0xc],piVar3[2] + uVar1,piVar3[5] - uVar1);
            param_1[0xc] = iVar2;
          }
          if (piVar3[8] == *(int *)(piVar3[7] + 0x14)) {
            piVar3[8] = 0;
            piVar3[1] = 0x49;
          }
        }
      }
      if (piVar3[1] == 0x49) {
        if (*(int *)(piVar3[7] + 0x1c) == 0) {
          piVar3[1] = 0x5b;
        }
        else {
          uVar1 = piVar3[5];
          do {
            if (piVar3[5] == piVar3[3]) {
              if ((*(int *)(piVar3[7] + 0x2c) != 0) && (uVar1 < (uint)piVar3[5])) {
                iVar2 = QC_crc32(param_1[0xc],piVar3[2] + uVar1,piVar3[5] - uVar1);
                param_1[0xc] = iVar2;
              }
              FUN_300884f0(param_1);
              uVar1 = piVar3[5];
              if (piVar3[5] == piVar3[3]) {
                cVar4 = '\x01';
                break;
              }
            }
            cVar4 = *(char *)(*(int *)(piVar3[7] + 0x1c) + piVar3[8]);
            piVar3[8] = piVar3[8] + 1;
            iVar2 = piVar3[5];
            *(char *)(piVar3[2] + iVar2) = cVar4;
            piVar3[5] = iVar2 + 1;
          } while (cVar4 != '\0');
          if ((*(int *)(piVar3[7] + 0x2c) != 0) && (uVar1 < (uint)piVar3[5])) {
            iVar2 = QC_crc32(param_1[0xc],piVar3[2] + uVar1,piVar3[5] - uVar1);
            param_1[0xc] = iVar2;
          }
          if (cVar4 == '\0') {
            piVar3[8] = 0;
            piVar3[1] = 0x5b;
          }
        }
      }
      if (piVar3[1] == 0x5b) {
        if (*(int *)(piVar3[7] + 0x24) == 0) {
          piVar3[1] = 0x67;
        }
        else {
          uVar1 = piVar3[5];
          do {
            if (piVar3[5] == piVar3[3]) {
              if ((*(int *)(piVar3[7] + 0x2c) != 0) && (uVar1 < (uint)piVar3[5])) {
                iVar2 = QC_crc32(param_1[0xc],piVar3[2] + uVar1,piVar3[5] - uVar1);
                param_1[0xc] = iVar2;
              }
              FUN_300884f0(param_1);
              uVar1 = piVar3[5];
              if (piVar3[5] == piVar3[3]) {
                cVar4 = '\x01';
                break;
              }
            }
            cVar4 = *(char *)(*(int *)(piVar3[7] + 0x24) + piVar3[8]);
            piVar3[8] = piVar3[8] + 1;
            iVar2 = piVar3[5];
            *(char *)(piVar3[2] + iVar2) = cVar4;
            piVar3[5] = iVar2 + 1;
          } while (cVar4 != '\0');
          if ((*(int *)(piVar3[7] + 0x2c) != 0) && (uVar1 < (uint)piVar3[5])) {
            iVar2 = QC_crc32(param_1[0xc],piVar3[2] + uVar1,piVar3[5] - uVar1);
            param_1[0xc] = iVar2;
          }
          if (cVar4 == '\0') {
            piVar3[1] = 0x67;
          }
        }
      }
      if (piVar3[1] == 0x67) {
        if (*(int *)(piVar3[7] + 0x2c) == 0) {
          piVar3[1] = 0x71;
        }
        else {
          if ((uint)piVar3[3] < piVar3[5] + 2U) {
            FUN_300884f0(param_1);
          }
          if (piVar3[5] + 2U <= (uint)piVar3[3]) {
            iVar2 = piVar3[5];
            *(char *)(piVar3[2] + iVar2) = (char)param_1[0xc];
            piVar3[5] = iVar2 + 1;
            iVar2 = piVar3[5];
            *(char *)(piVar3[2] + iVar2) = (char)((uint)param_1[0xc] >> 8);
            piVar3[5] = iVar2 + 1;
            iVar2 = QC_crc32(0,0,0);
            param_1[0xc] = iVar2;
            piVar3[1] = 0x71;
          }
        }
      }
      if (piVar3[5] == 0) {
        if (((param_1[1] == 0) && (param_2 <= iVar5)) && (param_2 != 4)) {
          param_1[6] = *(int *)(DAT_3008a174 + 0x1c);
          return 0xfffffffb;
        }
      }
      else {
        FUN_300884f0(param_1);
        if (param_1[4] == 0) {
          piVar3[10] = -1;
          return 0;
        }
      }
      if ((piVar3[1] == DAT_3008a178) && (param_1[1] != 0)) {
        param_1[6] = *(int *)(DAT_3008a174 + 0x1c);
        uVar1 = 0xfffffffb;
      }
      else {
        if (((param_1[1] != 0) || (piVar3[0x1d] != 0)) ||
           ((param_2 != 0 && (piVar3[1] != DAT_3008a178)))) {
          iVar5 = (**(code **)(DAT_3008a17c + piVar3[0x21] * 0xc))(piVar3,param_2);
          if ((iVar5 == 2) || (iVar5 == 3)) {
            piVar3[1] = DAT_3008a178;
          }
          if ((iVar5 == 0) || (iVar5 == 2)) {
            if (param_1[4] == 0) {
              piVar3[10] = -1;
            }
            return 0;
          }
          if (iVar5 == 1) {
            if (param_2 == 1) {
              QC_tr_align(piVar3);
            }
            else {
              QC_tr_stored_block(piVar3,0,0,0);
              if (param_2 == 3) {
                *(undefined2 *)(piVar3[0x11] + piVar3[0x13] * 2 + -2) = 0;
                memset((void *)piVar3[0x11],0,piVar3[0x13] * 2 - 2);
              }
            }
            FUN_300884f0(param_1);
            if (param_1[4] == 0) {
              piVar3[10] = -1;
              return 0;
            }
          }
        }
        if (param_2 == 4) {
          if (piVar3[6] < 1) {
            uVar1 = 1;
          }
          else {
            if (piVar3[6] == 2) {
              iVar5 = piVar3[5];
              *(char *)(piVar3[2] + iVar5) = (char)param_1[0xc];
              piVar3[5] = iVar5 + 1;
              iVar5 = piVar3[5];
              *(char *)(piVar3[2] + iVar5) = (char)((uint)param_1[0xc] >> 8);
              piVar3[5] = iVar5 + 1;
              iVar5 = piVar3[5];
              *(char *)(piVar3[2] + iVar5) = (char)*(undefined2 *)((int)param_1 + 0x32);
              piVar3[5] = iVar5 + 1;
              iVar5 = piVar3[5];
              *(undefined1 *)(piVar3[2] + iVar5) = *(undefined1 *)((int)param_1 + 0x33);
              piVar3[5] = iVar5 + 1;
              iVar5 = piVar3[5];
              *(char *)(piVar3[2] + iVar5) = (char)param_1[2];
              piVar3[5] = iVar5 + 1;
              iVar5 = piVar3[5];
              *(char *)(piVar3[2] + iVar5) = (char)((uint)param_1[2] >> 8);
              piVar3[5] = iVar5 + 1;
              iVar5 = piVar3[5];
              *(char *)(piVar3[2] + iVar5) = (char)*(undefined2 *)((int)param_1 + 10);
              piVar3[5] = iVar5 + 1;
              iVar5 = piVar3[5];
              *(undefined1 *)(piVar3[2] + iVar5) = *(undefined1 *)((int)param_1 + 0xb);
              piVar3[5] = iVar5 + 1;
            }
            else {
              FUN_300884a4(piVar3,*(undefined2 *)((int)param_1 + 0x32));
              FUN_300884a4(piVar3,param_1[0xc] & DAT_3008a4cc);
            }
            FUN_300884f0(param_1);
            if (0 < piVar3[6]) {
              piVar3[6] = -piVar3[6];
            }
            uVar1 = (uint)(piVar3[5] == 0);
          }
        }
        else {
          uVar1 = 0;
        }
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_deflateParams @ 0x300895AC  (примерный размер ~288 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: QC_deflate
 * Вызывают: QC_gzsetparams
 * Константы: 0xFFFFFFFE, 0x300895AC
 * Данные: DAT_3008a17c, DAT_3008a5e0, DAT_3008a5e4, DAT_3008a5e8, DAT_3008a5ec
 * ---------------------------------------------------------------- */
undefined4 QC_deflateParams(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if ((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x1c);
    if (param_2 == -1) {
      param_2 = 6;
    }
    if (((param_2 < 0) || (9 < param_2)) || (4 < param_3)) {
      uVar1 = 0xfffffffe;
    }
    else {
      if ((*(int *)(DAT_3008a17c + param_2 * 0xc) !=
           *(int *)(DAT_3008a17c + *(int *)(iVar2 + 0x84) * 0xc)) && (*(int *)(param_1 + 8) != 0)) {
        uVar1 = QC_deflate(param_1,1);
      }
      if (*(int *)(iVar2 + 0x84) != param_2) {
        *(int *)(iVar2 + 0x84) = param_2;
        *(uint *)(iVar2 + 0x80) = (uint)*(ushort *)(DAT_3008a5e0 + param_2 * 0xc);
        *(uint *)(iVar2 + 0x8c) = (uint)*(ushort *)(DAT_3008a5e4 + param_2 * 0xc);
        *(uint *)(iVar2 + 0x90) = (uint)*(ushort *)(DAT_3008a5e8 + param_2 * 0xc);
        *(uint *)(iVar2 + 0x7c) = (uint)*(ushort *)(DAT_3008a5ec + param_2 * 0xc);
      }
      *(uint *)(iVar2 + 0x88) = param_3;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_deflateTune @ 0x300896CC  (примерный размер ~84 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300896CC, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4
QC_deflateTune(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x1c);
    *(undefined4 *)(iVar2 + 0x8c) = param_2;
    *(undefined4 *)(iVar2 + 0x80) = param_3;
    *(undefined4 *)(iVar2 + 0x90) = param_4;
    *(undefined4 *)(iVar2 + 0x7c) = param_5;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_deflateBound @ 0x30089720  (примерный размер ~120 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: QC_compressBound
 * Константы: 0x30089720
 * ---------------------------------------------------------------- */
int QC_deflateBound(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2 + (param_2 + 7U >> 3) + (param_2 + 0x3fU >> 6) + 0xb;
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x1c) != 0)) &&
      (*(int *)(*(int *)(param_1 + 0x1c) + 0x30) == 0xf)) &&
     (*(int *)(*(int *)(param_1 + 0x1c) + 0x50) == 0xf)) {
    iVar1 = QC_compressBound(param_2);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * QC_deflateCopy @ 0x30089798  (примерный размер ~528 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: QC_deflateEnd, memcpy
 * Константы: 0xFFFFFFFE, 0xFFFFFFFC, 0x30089798
 * Данные: DAT_3008a74c, DAT_3008a87c, DAT_3008a880, DAT_3008a884, DAT_3008a888
 * ---------------------------------------------------------------- */
undefined4 QC_deflateCopy(void *param_1,void *param_2)

{
  undefined4 uVar1;
  undefined4 *__dest;
  int iVar2;
  void *__src;
  
  if (((param_2 == (void *)0x0) || (param_1 == (void *)0x0)) || (*(int *)((int)param_2 + 0x1c) == 0)
     ) {
    uVar1 = 0xfffffffe;
  }
  else {
    __src = *(void **)((int)param_2 + 0x1c);
    memcpy(param_1,param_2,0x38);
    __dest = (undefined4 *)
             (**(code **)((int)param_1 + 0x20))(*(undefined4 *)((int)param_1 + 0x28),1,0x16c0);
    if (__dest == (undefined4 *)0x0) {
      uVar1 = 0xfffffffc;
    }
    else {
      *(undefined4 **)((int)param_1 + 0x1c) = __dest;
      memcpy(__dest,__src,0x16c0);
      *__dest = param_1;
      uVar1 = (**(code **)((int)param_1 + 0x20))(*(undefined4 *)((int)param_1 + 0x28),__dest[0xb],2)
      ;
      __dest[0xe] = uVar1;
      uVar1 = (**(code **)((int)param_1 + 0x20))(*(undefined4 *)((int)param_1 + 0x28),__dest[0xb],2)
      ;
      __dest[0x10] = uVar1;
      uVar1 = (**(code **)((int)param_1 + 0x20))
                        (*(undefined4 *)((int)param_1 + 0x28),__dest[0x13],2);
      __dest[0x11] = uVar1;
      iVar2 = (**(code **)((int)param_1 + 0x20))
                        (*(undefined4 *)((int)param_1 + 0x28),
                         *(undefined4 *)((int)__dest + DAT_3008a74c),4);
      __dest[2] = iVar2;
      if (((__dest[0xe] == 0) || (__dest[0x10] == 0)) || ((__dest[0x11] == 0 || (__dest[2] == 0))))
      {
        QC_deflateEnd(param_1);
        uVar1 = 0xfffffffc;
      }
      else {
        memcpy((void *)__dest[0xe],*(void **)((int)__src + 0x38),__dest[0xb] << 1);
        memcpy((void *)__dest[0x10],*(void **)((int)__src + 0x40),__dest[0xb] << 1);
        memcpy((void *)__dest[0x11],*(void **)((int)__src + 0x44),__dest[0x13] << 1);
        memcpy((void *)__dest[2],*(void **)((int)__src + 8),__dest[3]);
        __dest[4] = __dest[2] + (*(int *)((int)__src + 0x10) - *(int *)((int)__src + 8));
        *(uint *)((int)__dest + DAT_3008a87c) =
             iVar2 + (*(uint *)((int)__dest + DAT_3008a74c) & 0xfffffffe);
        *(int *)((int)__dest + DAT_3008a880) = __dest[2] + *(int *)((int)__dest + DAT_3008a74c) * 3;
        __dest[0x2c6] = __dest + 0x25;
        __dest[0x2c9] = (int)__dest + DAT_3008a884;
        __dest[0x2cc] = (int)__dest + DAT_3008a888;
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_300899a8 @ 0x300899A8  (примерный размер ~200 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 3
 * Вызывает: QC_adler32, QC_crc32, memcpy
 * Вызывают: FUN_30089f00
 * Константы: 0x300899A8
 * ---------------------------------------------------------------- */
uint FUN_300899a8(int *param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint __n;
  
  __n = param_1[1];
  if (param_3 < __n) {
    __n = param_3;
  }
  if (__n == 0) {
    __n = 0;
  }
  else {
    param_1[1] = param_1[1] - __n;
    if (*(int *)(param_1[7] + 0x18) == 1) {
      iVar1 = QC_adler32(param_1[0xc],*param_1,__n);
      param_1[0xc] = iVar1;
    }
    else if (*(int *)(param_1[7] + 0x18) == 2) {
      iVar1 = QC_crc32(param_1[0xc],*param_1,__n);
      param_1[0xc] = iVar1;
    }
    memcpy(param_2,(void *)*param_1,__n);
    *param_1 = *param_1 + __n;
    param_1[2] = __n + param_1[2];
  }
  return __n;
}

/* ----------------------------------------------------------------
 * FUN_30089a70 @ 0x30089A70  (примерный размер ~788 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_3008a2ec, FUN_3008a8bc
 * Константы: 0x30089A70
 * Данные: DAT_3008aa0c, DAT_3008aa10
 * ---------------------------------------------------------------- */
uint FUN_30089a70(int param_1,uint param_2)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  char *pcVar6;
  char cVar7;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  local_3c = *(uint *)(param_1 + 0x7c);
  pcVar3 = (char *)(*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x6c));
  uVar1 = *(uint *)(param_1 + 0x78);
  local_38 = *(uint *)(param_1 + 0x90);
  if ((uint)(*(int *)(param_1 + 0x2c) - DAT_3008aa0c) < *(uint *)(param_1 + 0x6c)) {
    local_30 = *(int *)(param_1 + 0x6c) - (*(int *)(param_1 + 0x2c) - DAT_3008aa0c);
  }
  else {
    local_30 = 0;
  }
  pcVar6 = (char *)(*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x6c) + DAT_3008aa10);
  cVar5 = pcVar3[uVar1 - 1];
  cVar7 = pcVar3[uVar1];
  if (*(uint *)(param_1 + 0x8c) <= *(uint *)(param_1 + 0x78)) {
    local_3c = local_3c >> 2;
  }
  if (*(uint *)(param_1 + 0x74) < local_38) {
    local_38 = *(uint *)(param_1 + 0x74);
  }
  do {
    pcVar2 = (char *)(*(int *)(param_1 + 0x38) + param_2);
    if ((((pcVar2[uVar1] == cVar7) && (pcVar2[uVar1 - 1] == cVar5)) && (*pcVar2 == *pcVar3)) &&
       (pcVar2[1] == pcVar3[1])) {
      pcVar2 = pcVar2 + 2;
      pcVar3 = pcVar3 + 2;
      while (((((pcVar4 = pcVar3 + 1, *pcVar4 == pcVar2[1] &&
                (pcVar4 = pcVar3 + 2, *pcVar4 == pcVar2[2])) &&
               ((pcVar4 = pcVar3 + 3, *pcVar4 == pcVar2[3] &&
                ((pcVar4 = pcVar3 + 4, *pcVar4 == pcVar2[4] &&
                 (pcVar4 = pcVar3 + 5, *pcVar4 == pcVar2[5])))))) &&
              (pcVar4 = pcVar3 + 6, *pcVar4 == pcVar2[6])) &&
             (pcVar4 = pcVar3 + 7, *pcVar4 == pcVar2[7]))) {
        pcVar4 = pcVar3 + 8;
        pcVar2 = pcVar2 + 8;
        if ((*pcVar4 != *pcVar2) || (pcVar3 = pcVar4, pcVar6 <= pcVar4)) break;
      }
      local_34 = DAT_3008aa10 - ((int)pcVar6 - (int)pcVar4);
      pcVar3 = pcVar6 + -DAT_3008aa10;
      if ((int)uVar1 < (int)local_34) {
        *(uint *)(param_1 + 0x70) = param_2;
        if ((int)local_38 <= (int)local_34) {
LAB_30089d44:
          if (*(uint *)(param_1 + 0x74) <= local_34) {
            local_34 = *(uint *)(param_1 + 0x74);
          }
          return local_34;
        }
        cVar5 = pcVar3[local_34 - 1];
        cVar7 = pcVar3[local_34];
        uVar1 = local_34;
      }
    }
    local_34 = uVar1;
    param_2 = (uint)*(ushort *)
                     (*(int *)(param_1 + 0x40) + (param_2 & *(uint *)(param_1 + 0x34)) * 2);
    if ((param_2 <= local_30) || (local_3c = local_3c - 1, uVar1 = local_34, local_3c == 0))
    goto LAB_30089d44;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_30089d84 @ 0x30089D84  (примерный размер ~380 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_3008a2ec, FUN_3008a8bc
 * Константы: 0x30089D84
 * Данные: DAT_3008aa10
 * ---------------------------------------------------------------- */
uint FUN_30089d84(int param_1,int param_2)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar4 = (char *)(*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x6c));
  pcVar2 = (char *)(*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x6c) + DAT_3008aa10);
  pcVar3 = (char *)(*(int *)(param_1 + 0x38) + param_2);
  if ((*pcVar3 == *pcVar4) && (pcVar3[1] == pcVar4[1])) {
    pcVar3 = pcVar3 + 2;
    pcVar4 = pcVar4 + 2;
    while (((((pcVar5 = pcVar4 + 1, *pcVar5 == pcVar3[1] &&
              (pcVar5 = pcVar4 + 2, *pcVar5 == pcVar3[2])) &&
             (pcVar5 = pcVar4 + 3, *pcVar5 == pcVar3[3])) &&
            ((pcVar5 = pcVar4 + 4, *pcVar5 == pcVar3[4] &&
             (pcVar5 = pcVar4 + 5, *pcVar5 == pcVar3[5])))) &&
           ((pcVar5 = pcVar4 + 6, *pcVar5 == pcVar3[6] &&
            (pcVar5 = pcVar4 + 7, *pcVar5 == pcVar3[7]))))) {
      pcVar5 = pcVar4 + 8;
      pcVar3 = pcVar3 + 8;
      if ((*pcVar5 != *pcVar3) || (pcVar4 = pcVar5, pcVar2 <= pcVar5)) break;
    }
    uVar1 = DAT_3008aa10 - ((int)pcVar2 - (int)pcVar5);
    if ((int)uVar1 < 3) {
      uVar1 = 2;
    }
    else {
      *(int *)(param_1 + 0x70) = param_2;
      if (*(uint *)(param_1 + 0x74) <= uVar1) {
        uVar1 = *(uint *)(param_1 + 0x74);
      }
    }
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30089f00 @ 0x30089F00  (примерный размер ~416 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 2
 * Вызывает: FUN_300899a8, memcpy
 * Вызывают: FUN_3008a0a0, FUN_3008a2ec, FUN_3008a8bc
 * Константы: 0x30089F00
 * Данные: DAT_3008aa0c
 * ---------------------------------------------------------------- */
void FUN_30089f00(int *param_1)

{
  size_t __n;
  int iVar1;
  ushort *puVar2;
  int iVar3;
  size_t sVar4;
  
  __n = param_1[0xb];
  while( true ) {
    iVar1 = (param_1[0xf] - param_1[0x1d]) - param_1[0x1b];
    if ((__n + param_1[0xb]) - DAT_3008aa0c <= (uint)param_1[0x1b]) {
      memcpy((void *)param_1[0xe],(void *)(param_1[0xe] + __n),__n);
      param_1[0x1c] = param_1[0x1c] - __n;
      param_1[0x1b] = param_1[0x1b] - __n;
      param_1[0x17] = param_1[0x17] - __n;
      iVar3 = param_1[0x13];
      puVar2 = (ushort *)(param_1[0x11] + iVar3 * 2);
      do {
        puVar2 = puVar2 + -1;
        if (*puVar2 < __n) {
          *puVar2 = 0;
        }
        else {
          *puVar2 = *puVar2 - (short)__n;
        }
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      puVar2 = (ushort *)(param_1[0x10] + __n * 2);
      sVar4 = __n;
      do {
        puVar2 = puVar2 + -1;
        if (*puVar2 < __n) {
          *puVar2 = 0;
        }
        else {
          *puVar2 = *puVar2 - (short)__n;
        }
        sVar4 = sVar4 - 1;
      } while (sVar4 != 0);
      iVar1 = iVar1 + __n;
    }
    if (*(int *)(*param_1 + 4) == 0) break;
    iVar1 = FUN_300899a8(*param_1,param_1[0xe] + param_1[0x1b] + param_1[0x1d],iVar1);
    param_1[0x1d] = iVar1 + param_1[0x1d];
    if (2 < (uint)param_1[0x1d]) {
      param_1[0x12] = (uint)*(byte *)(param_1[0xe] + param_1[0x1b]);
      param_1[0x12] =
           ((uint)*(byte *)(param_1[0xe] + param_1[0x1b] + 1) ^
           param_1[0x12] << (param_1[0x16] & 0xffU)) & param_1[0x15];
    }
    if (DAT_3008aa0c <= (uint)param_1[0x1d]) {
      return;
    }
    if (*(int *)(*param_1 + 4) == 0) {
      return;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3008a0a0 @ 0x3008A0A0  (примерный размер ~588 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_300884f0, FUN_30089f00, QC_tr_flush_block
 * Константы: 0x3008A0A0
 * Данные: DAT_3008a4cc, DAT_3008aa0c
 * ---------------------------------------------------------------- */
int FUN_3008a0a0(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = DAT_3008a4cc;
  if (param_1[3] - 5U < DAT_3008a4cc) {
    uVar1 = param_1[3] - 5;
  }
  do {
    if ((uint)param_1[0x1d] < 2) {
      FUN_30089f00(param_1);
      if ((param_1[0x1d] == 0) && (param_2 == 0)) {
        return 0;
      }
      if (param_1[0x1d] == 0) {
        if (param_1[0x17] < 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = param_1[0xe] + param_1[0x17];
        }
        QC_tr_flush_block(param_1,iVar2,param_1[0x1b] - param_1[0x17]);
        param_1[0x17] = param_1[0x1b];
        FUN_300884f0(*param_1);
        if (*(int *)(*param_1 + 0x10) == 0) {
          return (uint)(param_2 == 4) << 1;
        }
        return (uint)(param_2 == 4) * 2 + 1;
      }
    }
    param_1[0x1b] = param_1[0x1b] + param_1[0x1d];
    param_1[0x1d] = 0;
    uVar3 = uVar1 + param_1[0x17];
    if ((param_1[0x1b] == 0) || (uVar3 <= (uint)param_1[0x1b])) {
      param_1[0x1d] = param_1[0x1b] - uVar3;
      param_1[0x1b] = uVar3;
      if (param_1[0x17] < 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = param_1[0xe] + param_1[0x17];
      }
      QC_tr_flush_block(param_1,iVar2,param_1[0x1b] - param_1[0x17],0);
      param_1[0x17] = param_1[0x1b];
      FUN_300884f0(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return 0;
      }
    }
    if ((uint)(param_1[0xb] - DAT_3008aa0c) <= (uint)(param_1[0x1b] - param_1[0x17])) {
      if (param_1[0x17] < 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = param_1[0xe] + param_1[0x17];
      }
      QC_tr_flush_block(param_1,iVar2,param_1[0x1b] - param_1[0x17],0);
      param_1[0x17] = param_1[0x1b];
      FUN_300884f0(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return 0;
      }
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_3008a2ec @ 0x3008A2EC  (примерный размер ~1488 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300884f0, FUN_30089a70, FUN_30089d84, FUN_30089f00, QC_tr_flush_block
 * Константы: 0x3008A2EC
 * Данные: DAT_3008a4cc, DAT_3008a74c, DAT_3008a87c, DAT_3008a880, DAT_3008a884, DAT_3008aa0c, DAT_3008b014, DAT_3008b018
 * ---------------------------------------------------------------- */
int FUN_3008a2ec(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  short *psVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  int local_3c;
  uint local_38;
  
  uVar5 = 0;
  do {
    if ((uint)param_1[0x1d] < DAT_3008aa0c) {
      FUN_30089f00(param_1);
      if (((uint)param_1[0x1d] < DAT_3008aa0c) && (param_2 == 0)) {
        return 0;
      }
      if (param_1[0x1d] == 0) {
        if (param_1[0x17] < 0) {
          local_3c = 0;
        }
        else {
          local_3c = param_1[0xe] + param_1[0x17];
        }
        QC_tr_flush_block(param_1,local_3c,param_1[0x1b] - param_1[0x17]);
        param_1[0x17] = param_1[0x1b];
        FUN_300884f0(*param_1);
        if (*(int *)(*param_1 + 0x10) == 0) {
          return (uint)(param_2 == 4) << 1;
        }
        return (uint)(param_2 == 4) * 2 + 1;
      }
    }
    if (2 < (uint)param_1[0x1d]) {
      param_1[0x12] =
           ((uint)*(byte *)(param_1[0xe] + param_1[0x1b] + 2) ^
           param_1[0x12] << (param_1[0x16] & 0xffU)) & param_1[0x15];
      *(undefined2 *)(param_1[0x10] + (param_1[0x1b] & param_1[0xd]) * 2) =
           *(undefined2 *)(param_1[0x11] + param_1[0x12] * 2);
      uVar5 = (uint)*(ushort *)(param_1[0x10] + (param_1[0x1b] & param_1[0xd]) * 2);
      *(short *)(param_1[0x11] + param_1[0x12] * 2) = (short)param_1[0x1b];
    }
    if ((uVar5 != 0) && (param_1[0x1b] - uVar5 <= param_1[0xb] - DAT_3008aa0c)) {
      if ((param_1[0x22] == 2) || (param_1[0x22] == 3)) {
        if ((param_1[0x22] == 3) && (param_1[0x1b] - uVar5 == 1)) {
          iVar2 = FUN_30089d84(param_1,uVar5);
          param_1[0x18] = iVar2;
        }
      }
      else {
        iVar2 = FUN_30089a70(param_1,uVar5);
        param_1[0x18] = iVar2;
      }
    }
    if ((uint)param_1[0x18] < 3) {
      bVar1 = *(byte *)(param_1[0xe] + param_1[0x1b]);
      *(undefined2 *)
       (*(int *)((int)param_1 + DAT_3008a87c) + *(int *)((int)param_1 + DAT_3008b014) * 2) = 0;
      iVar2 = *(int *)((int)param_1 + DAT_3008b014);
      *(byte *)(*(int *)((int)param_1 + DAT_3008a880) + iVar2) = bVar1;
      *(int *)((int)param_1 + DAT_3008b014) = iVar2 + 1;
      *(short *)(param_1 + bVar1 + 0x25) = (short)param_1[bVar1 + 0x25] + 1;
      bVar8 = *(int *)((int)param_1 + DAT_3008b014) == *(int *)((int)param_1 + DAT_3008a74c) + -1;
      param_1[0x1d] = param_1[0x1d] + -1;
      param_1[0x1b] = param_1[0x1b] + 1;
    }
    else {
      bVar1 = (char)param_1[0x18] - 3;
      iVar6 = param_1[0x1b];
      iVar7 = param_1[0x1c];
      *(short *)(*(int *)((int)param_1 + DAT_3008a87c) + *(int *)((int)param_1 + DAT_3008b014) * 2)
           = (short)(iVar6 - iVar7);
      iVar2 = *(int *)((int)param_1 + DAT_3008b014);
      *(byte *)(*(int *)((int)param_1 + DAT_3008a880) + iVar2) = bVar1;
      *(int *)((int)param_1 + DAT_3008b014) = iVar2 + 1;
      uVar4 = (iVar6 - iVar7) + DAT_3008a4cc;
      psVar3 = (short *)((int)param_1 +
                        DAT_3008b01c + (uint)*(byte *)(DAT_3008b018 + (uint)bVar1) * 4);
      *psVar3 = *psVar3 + 1;
      if ((uVar4 & 0xffff) < 0x100) {
        bVar1 = *(byte *)(DAT_3008b020 + (uVar4 & 0xffff));
      }
      else {
        bVar1 = *(byte *)(DAT_3008b024 + ((int)(uVar4 & 0xffff) >> 7));
      }
      local_38 = (uint)bVar1;
      psVar3 = (short *)((int)param_1 + DAT_3008a884 + local_38 * 4);
      *psVar3 = *psVar3 + 1;
      bVar8 = *(int *)((int)param_1 + DAT_3008b014) == *(int *)((int)param_1 + DAT_3008a74c) + -1;
      param_1[0x1d] = param_1[0x1d] - param_1[0x18];
      if (((uint)param_1[0x20] < (uint)param_1[0x18]) || ((uint)param_1[0x1d] < 3)) {
        param_1[0x1b] = param_1[0x1b] + param_1[0x18];
        param_1[0x18] = 0;
        param_1[0x12] = (uint)*(byte *)(param_1[0xe] + param_1[0x1b]);
        param_1[0x12] =
             ((uint)*(byte *)(param_1[0xe] + param_1[0x1b] + 1) ^
             param_1[0x12] << (param_1[0x16] & 0xffU)) & param_1[0x15];
      }
      else {
        param_1[0x18] = param_1[0x18] + -1;
        do {
          param_1[0x1b] = param_1[0x1b] + 1;
          param_1[0x12] =
               ((uint)*(byte *)(param_1[0xe] + param_1[0x1b] + 2) ^
               param_1[0x12] << (param_1[0x16] & 0xffU)) & param_1[0x15];
          *(undefined2 *)(param_1[0x10] + (param_1[0x1b] & param_1[0xd]) * 2) =
               *(undefined2 *)(param_1[0x11] + param_1[0x12] * 2);
          uVar5 = (uint)*(ushort *)(param_1[0x10] + (param_1[0x1b] & param_1[0xd]) * 2);
          *(short *)(param_1[0x11] + param_1[0x12] * 2) = (short)param_1[0x1b];
          param_1[0x18] = param_1[0x18] + -1;
        } while (param_1[0x18] != 0);
        param_1[0x1b] = param_1[0x1b] + 1;
      }
    }
    if (bVar8) {
      if (param_1[0x17] < 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = param_1[0xe] + param_1[0x17];
      }
      QC_tr_flush_block(param_1,iVar2,param_1[0x1b] - param_1[0x17],0);
      param_1[0x17] = param_1[0x1b];
      FUN_300884f0(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return 0;
      }
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_3008a8bc @ 0x3008A8BC  (примерный размер ~1920 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_300884f0, FUN_30089a70, FUN_30089d84, FUN_30089f00, QC_tr_flush_block
 * Константы: 0x3008A8BC
 * Данные: DAT_3008aa0c, DAT_3008b014, DAT_3008b018, DAT_3008b01c, DAT_3008b020, DAT_3008b024, DAT_3008b028, DAT_3008b02c
 * ---------------------------------------------------------------- */
int FUN_3008a8bc(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  short *psVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_3c;
  int local_38;
  uint local_34;
  
  uVar5 = 0;
  do {
    if ((uint)param_1[0x1d] < DAT_3008aa0c) {
      FUN_30089f00(param_1);
      if (((uint)param_1[0x1d] < DAT_3008aa0c) && (param_2 == 0)) {
        return 0;
      }
      if (param_1[0x1d] == 0) {
        if (param_1[0x1a] != 0) {
          bVar1 = *(byte *)(param_1[0xe] + param_1[0x1b] + -1);
          *(undefined2 *)
           (*(int *)((int)param_1 + DAT_3008b02c) + *(int *)((int)param_1 + DAT_3008b014) * 2) = 0;
          iVar2 = *(int *)((int)param_1 + DAT_3008b014);
          *(byte *)(*(int *)((int)param_1 + DAT_3008b030) + iVar2) = bVar1;
          *(int *)((int)param_1 + DAT_3008b014) = iVar2 + 1;
          *(short *)(param_1 + bVar1 + 0x25) = (short)param_1[bVar1 + 0x25] + 1;
          param_1[0x1a] = 0;
        }
        if (param_1[0x17] < 0) {
          local_3c = 0;
        }
        else {
          local_3c = param_1[0xe] + param_1[0x17];
        }
        QC_tr_flush_block(param_1,local_3c,param_1[0x1b] - param_1[0x17]);
        param_1[0x17] = param_1[0x1b];
        FUN_300884f0(*param_1);
        if (*(int *)(*param_1 + 0x10) == 0) {
          return (uint)(param_2 == 4) << 1;
        }
        return (uint)(param_2 == 4) * 2 + 1;
      }
    }
    if (2 < (uint)param_1[0x1d]) {
      param_1[0x12] =
           ((uint)*(byte *)(param_1[0xe] + param_1[0x1b] + 2) ^
           param_1[0x12] << (param_1[0x16] & 0xffU)) & param_1[0x15];
      *(undefined2 *)(param_1[0x10] + (param_1[0x1b] & param_1[0xd]) * 2) =
           *(undefined2 *)(param_1[0x11] + param_1[0x12] * 2);
      uVar5 = (uint)*(ushort *)(param_1[0x10] + (param_1[0x1b] & param_1[0xd]) * 2);
      *(short *)(param_1[0x11] + param_1[0x12] * 2) = (short)param_1[0x1b];
    }
    param_1[0x1e] = param_1[0x18];
    param_1[0x19] = param_1[0x1c];
    param_1[0x18] = 2;
    if (((uVar5 != 0) && ((uint)param_1[0x1e] < (uint)param_1[0x20])) &&
       (param_1[0x1b] - uVar5 <= param_1[0xb] - DAT_3008aa0c)) {
      if ((param_1[0x22] == 2) || (param_1[0x22] == 3)) {
        if ((param_1[0x22] == 3) && (param_1[0x1b] - uVar5 == 1)) {
          iVar2 = FUN_30089d84(param_1,uVar5);
          param_1[0x18] = iVar2;
        }
      }
      else {
        iVar2 = FUN_30089a70(param_1,uVar5);
        param_1[0x18] = iVar2;
      }
      if (((uint)param_1[0x18] < 6) &&
         ((param_1[0x22] == 1 ||
          ((param_1[0x18] == 3 && (0x1000 < (uint)(param_1[0x1b] - param_1[0x1c]))))))) {
        param_1[0x18] = 2;
      }
    }
    if (((uint)param_1[0x1e] < 3) || ((uint)param_1[0x1e] < (uint)param_1[0x18])) {
      if (param_1[0x1a] == 0) {
        param_1[0x1a] = 1;
        param_1[0x1b] = param_1[0x1b] + 1;
        param_1[0x1d] = param_1[0x1d] + -1;
      }
      else {
        bVar1 = *(byte *)(param_1[0xe] + param_1[0x1b] + -1);
        *(undefined2 *)
         (*(int *)((int)param_1 + DAT_3008b02c) + *(int *)((int)param_1 + DAT_3008b014) * 2) = 0;
        iVar2 = *(int *)((int)param_1 + DAT_3008b014);
        *(byte *)(*(int *)((int)param_1 + DAT_3008b030) + iVar2) = bVar1;
        *(int *)((int)param_1 + DAT_3008b014) = iVar2 + 1;
        *(short *)(param_1 + bVar1 + 0x25) = (short)param_1[bVar1 + 0x25] + 1;
        if (*(int *)((int)param_1 + DAT_3008b014) == *(int *)((int)param_1 + DAT_3008b038) + -1) {
          if (param_1[0x17] < 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = param_1[0xe] + param_1[0x17];
          }
          QC_tr_flush_block(param_1,iVar2,param_1[0x1b] - param_1[0x17],0);
          param_1[0x17] = param_1[0x1b];
          FUN_300884f0(*param_1);
        }
        param_1[0x1b] = param_1[0x1b] + 1;
        param_1[0x1d] = param_1[0x1d] + -1;
        if (*(int *)(*param_1 + 0x10) == 0) {
          return 0;
        }
      }
    }
    else {
      iVar8 = param_1[0x1b];
      iVar6 = param_1[0x1d];
      bVar1 = (char)param_1[0x1e] - 3;
      iVar2 = (param_1[0x1b] - param_1[0x19]) + DAT_3008b028;
      *(short *)(*(int *)((int)param_1 + DAT_3008b02c) + *(int *)((int)param_1 + DAT_3008b014) * 2)
           = (short)iVar2;
      iVar7 = *(int *)((int)param_1 + DAT_3008b014);
      *(byte *)(*(int *)((int)param_1 + DAT_3008b030) + iVar7) = bVar1;
      *(int *)((int)param_1 + DAT_3008b014) = iVar7 + 1;
      uVar4 = iVar2 + DAT_3008b028;
      psVar3 = (short *)((int)param_1 +
                        DAT_3008b01c + (uint)*(byte *)(DAT_3008b018 + (uint)bVar1) * 4);
      *psVar3 = *psVar3 + 1;
      if ((uVar4 & 0xffff) < 0x100) {
        bVar1 = *(byte *)(DAT_3008b020 + (uVar4 & 0xffff));
      }
      else {
        bVar1 = *(byte *)(DAT_3008b024 + ((int)(uVar4 & 0xffff) >> 7));
      }
      local_34 = (uint)bVar1;
      psVar3 = (short *)((int)param_1 + DAT_3008b034 + local_34 * 4);
      *psVar3 = *psVar3 + 1;
      iVar7 = *(int *)((int)param_1 + DAT_3008b014);
      iVar2 = *(int *)((int)param_1 + DAT_3008b038);
      param_1[0x1d] = param_1[0x1d] - (param_1[0x1e] + -1);
      param_1[0x1e] = param_1[0x1e] + -2;
      do {
        param_1[0x1b] = param_1[0x1b] + 1;
        if ((uint)param_1[0x1b] <= (iVar8 + iVar6) - 3U) {
          param_1[0x12] =
               ((uint)*(byte *)(param_1[0xe] + param_1[0x1b] + 2) ^
               param_1[0x12] << (param_1[0x16] & 0xffU)) & param_1[0x15];
          *(undefined2 *)(param_1[0x10] + (param_1[0x1b] & param_1[0xd]) * 2) =
               *(undefined2 *)(param_1[0x11] + param_1[0x12] * 2);
          uVar5 = (uint)*(ushort *)(param_1[0x10] + (param_1[0x1b] & param_1[0xd]) * 2);
          *(short *)(param_1[0x11] + param_1[0x12] * 2) = (short)param_1[0x1b];
        }
        param_1[0x1e] = param_1[0x1e] + -1;
      } while (param_1[0x1e] != 0);
      param_1[0x1a] = 0;
      param_1[0x18] = 2;
      param_1[0x1b] = param_1[0x1b] + 1;
      if (iVar7 == iVar2 + -1) {
        if (param_1[0x17] < 0) {
          local_38 = 0;
        }
        else {
          local_38 = param_1[0xe] + param_1[0x17];
        }
        QC_tr_flush_block(param_1,local_38,param_1[0x1b] - param_1[0x17],0);
        param_1[0x17] = param_1[0x1b];
        FUN_300884f0(*param_1);
        if (*(int *)(*param_1 + 0x10) == 0) {
          return 0;
        }
      }
    }
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_3008b03c @ 0x3008B03C  (примерный размер ~252 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 2
 * Вызывает: __errno, fread
 * Вызывают: FUN_3008b138, FUN_3008bde0
 * Константы: 0xFFFFFFFF, 0x3008B03C
 * ---------------------------------------------------------------- */
uint FUN_3008b03c(int *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  size_t sVar3;
  byte *pbVar4;
  
  if (param_1[0xf] == 0) {
    if (param_1[1] == 0) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = 0;
      sVar3 = fread((void *)param_1[0x11],1,0x4000,(FILE *)param_1[0x10]);
      param_1[1] = sVar3;
      if (param_1[1] == 0) {
        param_1[0xf] = 1;
        if (((*(int *)(param_1[0x10] + 4) == param_1[0x10]) &&
            (*(char *)(param_1[0x10] + 10) == 'f')) &&
           ((*(ushort *)(param_1[0x10] + 0x18) & 0x40) != 0)) {
          param_1[0xe] = -1;
        }
        return 0xffffffff;
      }
      *param_1 = param_1[0x11];
    }
    param_1[1] = param_1[1] + -1;
    pbVar4 = (byte *)*param_1;
    *param_1 = *param_1 + 1;
    uVar1 = (uint)*pbVar4;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3008b138 @ 0x3008B138  (примерный размер ~604 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 3
 * Вызывает: FUN_3008b03c, __errno, fread
 * Вызывают: FUN_3008b498, FUN_3008b88c, QC_gzread
 * Константы: 0x3008B138
 * ---------------------------------------------------------------- */
void FUN_3008b138(int *param_1)

{
  undefined4 *puVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = param_1[1];
  if (uVar5 < 2) {
    if (uVar5 != 0) {
      *(undefined1 *)param_1[0x11] = *(undefined1 *)*param_1;
    }
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0;
    sVar2 = fread((void *)(param_1[0x11] + uVar5),1,0x4000 >> (uVar5 & 0xff),(FILE *)param_1[0x10]);
    if ((((sVar2 == 0) && (*(int *)(param_1[0x10] + 4) == param_1[0x10])) &&
        (*(char *)(param_1[0x10] + 10) == 'f')) && ((*(ushort *)(param_1[0x10] + 0x18) & 0x40) != 0)
       ) {
      param_1[0xe] = -1;
    }
    param_1[1] = sVar2 + param_1[1];
    *param_1 = param_1[0x11];
    if ((uint)param_1[1] < 2) {
      param_1[0x16] = param_1[1];
      return;
    }
  }
  if ((*(char *)*param_1 == '\x1f') && (*(char *)(*param_1 + 1) == -0x75)) {
    param_1[1] = param_1[1] + -2;
    *param_1 = *param_1 + 2;
    iVar3 = FUN_3008b03c(param_1);
    uVar5 = FUN_3008b03c(param_1);
    if ((iVar3 == 8) && ((uVar5 & 0xe0) == 0)) {
      for (uVar6 = 0; uVar6 < 6; uVar6 = uVar6 + 1) {
        FUN_3008b03c(param_1);
      }
      if ((uVar5 & 4) != 0) {
        iVar3 = FUN_3008b03c(param_1);
        iVar4 = FUN_3008b03c(param_1);
        iVar3 = iVar3 + iVar4 * 0x100;
        do {
          if (iVar3 == 0) break;
          iVar4 = FUN_3008b03c(param_1);
          iVar3 = iVar3 + -1;
        } while (iVar4 != -1);
      }
      if ((uVar5 & 8) != 0) {
        do {
          iVar3 = FUN_3008b03c(param_1);
          if (iVar3 == 0) break;
        } while (iVar3 != -1);
      }
      if ((uVar5 & 0x10) != 0) {
        do {
          iVar3 = FUN_3008b03c(param_1);
          if (iVar3 == 0) break;
        } while (iVar3 != -1);
      }
      if ((uVar5 & 2) != 0) {
        for (uVar5 = 0; uVar5 < 2; uVar5 = uVar5 + 1) {
          FUN_3008b03c(param_1);
        }
      }
      if (param_1[0xf] == 0) {
        param_1[0xe] = 0;
      }
      else {
        param_1[0xe] = -3;
      }
    }
    else {
      param_1[0xe] = -3;
    }
  }
  else {
    param_1[0x16] = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3008b394 @ 0x3008B394  (примерный размер ~260 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 5
 * Вызывает: QC_deflateEnd, QC_inflateEnd, __errno, fclose, free
 * Вызывают: FUN_3008b498, FUN_3008b88c, QC_gzclose
 * Константы: 0x3008B394, 0xFFFFFFFE, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 FUN_3008b394(void *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_1 == (void *)0x0) {
    uVar3 = 0xfffffffe;
  }
  else {
    if (*(int *)((int)param_1 + 0x50) != 0) {
      free(*(void **)((int)param_1 + 0x50));
    }
    if (*(int *)((int)param_1 + 0x1c) != 0) {
      if (*(char *)((int)param_1 + 0x5c) == 'w') {
        uVar3 = QC_deflateEnd(param_1);
      }
      else if (*(char *)((int)param_1 + 0x5c) == 'r') {
        uVar3 = QC_inflateEnd(param_1);
      }
    }
    if (((*(int *)((int)param_1 + 0x40) != 0) &&
        (iVar1 = fclose(*(FILE **)((int)param_1 + 0x40)), iVar1 != 0)) &&
       (piVar2 = (int *)__errno(), *piVar2 != 0x1d)) {
      uVar3 = 0xffffffff;
    }
    if (*(int *)((int)param_1 + 0x38) < 0) {
      uVar3 = *(undefined4 *)((int)param_1 + 0x38);
    }
    if (*(int *)((int)param_1 + 0x44) != 0) {
      free(*(void **)((int)param_1 + 0x44));
    }
    if (*(int *)((int)param_1 + 0x48) != 0) {
      free(*(void **)((int)param_1 + 0x48));
    }
    if (*(int *)((int)param_1 + 0x54) != 0) {
      free(*(void **)((int)param_1 + 0x54));
    }
    if (param_1 != (void *)0x0) {
      free(param_1);
    }
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_3008b498 @ 0x3008B498  (примерный размер ~1012 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 13
 * Вызывает: FUN_3008b138, FUN_3008b394, QC_crc32, QC_deflateInit2_, QC_inflateInit2_, __errno, fdopen, fopen, fprintf, ftell, malloc, strlen, strncpy
 * Вызывают: QC_gzdopen, QC_gzopen
 * Константы: 0xFFFFFFF1, 0x3008B498, 0xFFFFFFFF
 * Данные: DAT_3008c5d8, DAT_3008c798
 * ---------------------------------------------------------------- */
undefined4 * FUN_3008b498(char *param_1,char *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  size_t sVar3;
  void *pvVar4;
  undefined4 *puVar5;
  FILE *pFVar6;
  long lVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  char local_78 [80];
  
  iVar9 = -1;
  uVar8 = 0;
  pcVar10 = local_78;
  if ((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)malloc(0x74);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1[8] = 0;
      puVar1[9] = 0;
      puVar1[10] = 0;
      puVar1[0x11] = 0;
      *puVar1 = 0;
      puVar1[0x12] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[1] = 0;
      puVar1[0x10] = 0;
      puVar1[0xe] = 0;
      puVar1[0xf] = 0;
      puVar1[0x19] = 0;
      puVar1[0x1a] = 0;
      puVar1[0x1b] = 0xffffffff;
      uVar2 = QC_crc32(0,0,0);
      puVar1[0x13] = uVar2;
      puVar1[0x14] = 0;
      puVar1[0x16] = 0;
      sVar3 = strlen(param_1);
      pvVar4 = malloc(sVar3 + 1);
      puVar1[0x15] = pvVar4;
      if (puVar1[0x15] == 0) {
        FUN_3008b394(puVar1);
        puVar1 = (undefined4 *)0x0;
      }
      else {
        sVar3 = strlen(param_1);
        strncpy((char *)puVar1[0x15],param_1,sVar3 + 1);
        *(undefined1 *)(puVar1 + 0x17) = 0;
        do {
          if (*param_2 == 'r') {
            *(undefined1 *)(puVar1 + 0x17) = 0x72;
          }
          if ((*param_2 == 'w') || (*param_2 == 'a')) {
            *(undefined1 *)(puVar1 + 0x17) = 0x77;
          }
          if ((int)*param_2 - 0x30U < 10) {
            iVar9 = *param_2 + -0x30;
          }
          else if (*param_2 == 'f') {
            uVar8 = 1;
          }
          else if (*param_2 == 'h') {
            uVar8 = 2;
          }
          else if (*param_2 == 'R') {
            uVar8 = 3;
          }
          else {
            *pcVar10 = *param_2;
            pcVar10 = pcVar10 + 1;
          }
        } while ((*param_2 != '\0') && (param_2 = param_2 + 1, &stack0xffffffd8 != pcVar10));
        if (*(char *)(puVar1 + 0x17) == '\0') {
          FUN_3008b394(puVar1);
          puVar1 = (undefined4 *)0x0;
        }
        else {
          if (*(char *)(puVar1 + 0x17) == 'w') {
            iVar9 = QC_deflateInit2_(puVar1,iVar9,8,0xfffffff1,8,uVar8,DAT_3008c5d8,0x38);
            pvVar4 = malloc(0x4000);
            puVar1[0x12] = pvVar4;
            puVar1[3] = puVar1[0x12];
            if ((iVar9 != 0) || (puVar1[0x12] == 0)) {
              FUN_3008b394(puVar1);
              return (undefined4 *)0x0;
            }
          }
          else {
            pvVar4 = malloc(0x4000);
            puVar1[0x11] = pvVar4;
            *puVar1 = puVar1[0x11];
            iVar9 = QC_inflateInit2_(puVar1,0xfffffff1,DAT_3008c5d8,0x38);
            if ((iVar9 != 0) || (puVar1[0x11] == 0)) {
              FUN_3008b394(puVar1);
              return (undefined4 *)0x0;
            }
          }
          puVar1[4] = 0x4000;
          puVar5 = (undefined4 *)__errno();
          *puVar5 = 0;
          if (param_3 < 0) {
            pFVar6 = fopen(param_1,local_78);
            puVar1[0x10] = pFVar6;
          }
          else {
            pFVar6 = fdopen(param_3,local_78);
            puVar1[0x10] = pFVar6;
          }
          if (puVar1[0x10] == 0) {
            FUN_3008b394(puVar1);
            puVar1 = (undefined4 *)0x0;
          }
          else if (*(char *)(puVar1 + 0x17) == 'w') {
            fprintf((FILE *)puVar1[0x10],DAT_3008c798,0x1f,0x8b,8,0,0,0,0,0,0,3);
            puVar1[0x18] = 10;
          }
          else {
            FUN_3008b138(puVar1);
            lVar7 = ftell((FILE *)puVar1[0x10]);
            puVar1[0x18] = lVar7 - puVar1[1];
          }
        }
      }
    }
  }
  return puVar1;
}

/* ----------------------------------------------------------------
 * FUN_3008b88c @ 0x3008B88C  (примерный размер ~1088 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 14
 * Вызывает: FUN_3008b138, FUN_3008b394, QC_crc32, QC_deflateInit2_, QC_inflateInit2_, __errno, fdopen, fopen, fprintf, fseek, ftell, malloc, strlen, strncpy
 * Вызывают: QC_gzopen
 * Константы: 0xFFFFFFF1, 0x3008B88C, 0xFFFFFFFF
 * Данные: DAT_3008c5d8, DAT_3008c798
 * ---------------------------------------------------------------- */
undefined4 * FUN_3008b88c(char *param_1,char *param_2,int param_3,long param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  size_t sVar3;
  void *pvVar4;
  undefined4 *puVar5;
  FILE *pFVar6;
  long lVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  char local_7c [80];
  
  iVar9 = -1;
  uVar8 = 0;
  pcVar10 = local_7c;
  if ((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)malloc(0x74);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1[8] = 0;
      puVar1[9] = 0;
      puVar1[10] = 0;
      puVar1[0x11] = 0;
      *puVar1 = 0;
      puVar1[0x12] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[1] = 0;
      puVar1[0x10] = 0;
      puVar1[0xe] = 0;
      puVar1[0xf] = 0;
      puVar1[0x19] = 0;
      puVar1[0x1a] = 0;
      puVar1[0x1b] = 0xffffffff;
      uVar2 = QC_crc32(0,0,0);
      puVar1[0x13] = uVar2;
      puVar1[0x14] = 0;
      puVar1[0x16] = 0;
      sVar3 = strlen(param_1);
      pvVar4 = malloc(sVar3 + 1);
      puVar1[0x15] = pvVar4;
      if (puVar1[0x15] == 0) {
        FUN_3008b394(puVar1);
        puVar1 = (undefined4 *)0x0;
      }
      else {
        sVar3 = strlen(param_1);
        strncpy((char *)puVar1[0x15],param_1,sVar3 + 1);
        *(undefined1 *)(puVar1 + 0x17) = 0;
        do {
          if (*param_2 == 'r') {
            *(undefined1 *)(puVar1 + 0x17) = 0x72;
          }
          if ((*param_2 == 'w') || (*param_2 == 'a')) {
            *(undefined1 *)(puVar1 + 0x17) = 0x77;
          }
          if ((int)*param_2 - 0x30U < 10) {
            iVar9 = *param_2 + -0x30;
          }
          else if (*param_2 == 'f') {
            uVar8 = 1;
          }
          else if (*param_2 == 'h') {
            uVar8 = 2;
          }
          else if (*param_2 == 'R') {
            uVar8 = 3;
          }
          else {
            *pcVar10 = *param_2;
            pcVar10 = pcVar10 + 1;
          }
        } while ((*param_2 != '\0') && (param_2 = param_2 + 1, &stack0xffffffd4 != pcVar10));
        if (*(char *)(puVar1 + 0x17) == '\0') {
          FUN_3008b394(puVar1);
          puVar1 = (undefined4 *)0x0;
        }
        else {
          if (*(char *)(puVar1 + 0x17) == 'w') {
            iVar9 = QC_deflateInit2_(puVar1,iVar9,8,0xfffffff1,8,uVar8,DAT_3008c5d8,0x38);
            pvVar4 = malloc(0x4000);
            puVar1[0x12] = pvVar4;
            puVar1[3] = puVar1[0x12];
            if ((iVar9 != 0) || (puVar1[0x12] == 0)) {
              FUN_3008b394(puVar1);
              return (undefined4 *)0x0;
            }
          }
          else {
            pvVar4 = malloc(0x4000);
            puVar1[0x11] = pvVar4;
            *puVar1 = puVar1[0x11];
            iVar9 = QC_inflateInit2_(puVar1,0xfffffff1,DAT_3008c5d8,0x38);
            if ((iVar9 != 0) || (puVar1[0x11] == 0)) {
              FUN_3008b394(puVar1);
              return (undefined4 *)0x0;
            }
          }
          puVar1[4] = 0x4000;
          puVar5 = (undefined4 *)__errno();
          *puVar5 = 0;
          if (param_3 < 0) {
            pFVar6 = fopen(param_1,local_7c);
            puVar1[0x10] = pFVar6;
          }
          else {
            pFVar6 = fdopen(param_3,local_7c);
            puVar1[0x10] = pFVar6;
          }
          if (puVar1[0x10] == 0) {
            FUN_3008b394(puVar1);
            puVar1 = (undefined4 *)0x0;
          }
          else {
            iVar9 = fseek((FILE *)puVar1[0x10],param_4,0);
            if (iVar9 < 0) {
              FUN_3008b394(puVar1);
              puVar1 = (undefined4 *)0x0;
            }
            else if (puVar1[0x10] == 0) {
              FUN_3008b394(puVar1);
              puVar1 = (undefined4 *)0x0;
            }
            else if (*(char *)(puVar1 + 0x17) == 'w') {
              fprintf((FILE *)puVar1[0x10],DAT_3008c798,0x1f,0x8b,8,0,0,0,0,0,0,3);
              puVar1[0x18] = 10;
            }
            else {
              FUN_3008b138(puVar1);
              lVar7 = ftell((FILE *)puVar1[0x10]);
              puVar1[0x18] = lVar7 - puVar1[1];
            }
          }
        }
      }
    }
  }
  return puVar1;
}

/* ----------------------------------------------------------------
 * QC_gzopen @ 0x3008BCCC  (примерный размер ~68 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 2
 * Вызывает: FUN_3008b498, FUN_3008b88c
 * Вызывают: gz_compressFile, gz_uncompressFile, gzgetUncompressLength, gzuncompressFileToStream
 * Константы: 0xFFFFFFFF, 0x3008BCCC
 * ---------------------------------------------------------------- */
void QC_gzopen(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    FUN_3008b498(param_1,param_2,0xffffffff);
  }
  else {
    FUN_3008b88c(param_1,param_2,0xffffffff,param_3);
  }
  return;
}

/* ----------------------------------------------------------------
 * QC_gzdopen @ 0x3008BD10  (примерный размер ~76 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_3008b498, printf
 * Константы: 0x3008BD10
 * Данные: DAT_3008cbfc
 * ---------------------------------------------------------------- */
undefined4 QC_gzdopen(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char acStack_3c [48];
  
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    printf(acStack_3c,0x2e,DAT_3008cbfc,param_1);
    uVar1 = FUN_3008b498(acStack_3c,param_2,param_1);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_gzsetparams @ 0x3008BD5C  (примерный размер ~132 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: QC_deflateParams, fwrite
 * Константы: 0x3008BD5C, 0xFFFFFFFE, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
undefined4 QC_gzsetparams(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  size_t sVar2;
  
  if ((param_1 == 0) || (*(char *)(param_1 + 0x5c) != 'w')) {
    uVar1 = 0xfffffffe;
  }
  else {
    if (*(int *)(param_1 + 0x10) == 0) {
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x48);
      sVar2 = fwrite(*(void **)(param_1 + 0x48),1,0x4000,*(FILE **)(param_1 + 0x40));
      if (sVar2 != 0x4000) {
        *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
      }
      *(undefined4 *)(param_1 + 0x10) = 0x4000;
    }
    uVar1 = QC_deflateParams(param_1,param_2,param_3);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3008bde0 @ 0x3008BDE0  (примерный размер ~96 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3008b03c
 * Вызывают: QC_gzread
 * Константы: 0x3008BDE0, 0xFFFFFFFD, 0x01000000
 * ---------------------------------------------------------------- */
int FUN_3008bde0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_3008b03c(param_1);
  iVar2 = FUN_3008b03c(param_1);
  iVar3 = FUN_3008b03c(param_1);
  iVar4 = FUN_3008b03c(param_1);
  if (iVar4 == -1) {
    *(undefined4 *)(param_1 + 0x38) = 0xfffffffd;
  }
  return iVar1 + iVar2 * 0x100 + iVar3 * 0x10000 + iVar4 * 0x1000000;
}

/* ----------------------------------------------------------------
 * QC_gzread @ 0x3008BE40  (примерный размер ~964 байт)
 * Модуль: lib | Вызывают: 5 | Вызывает: 8
 * Вызывает: FUN_3008b138, FUN_3008bde0, QC_crc32, QC_inflate, QC_inflateReset, __errno, fread, memcpy
 * Вызывают: QC_gzgetc, QC_gzgets, QC_gzseek, gz_uncompressFile, gzuncompressFileToStream
 * Константы: 0x3008BE40
 * ---------------------------------------------------------------- */
int QC_gzread(int *param_1,undefined1 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *__ptr;
  size_t sVar3;
  
  if ((param_1 == (int *)0x0) || ((char)param_1[0x17] != 'r')) {
    param_3 = -2;
  }
  else if ((param_1[0xe] == -3) || (param_1[0xe] == -1)) {
    param_3 = -1;
  }
  else if (param_1[0xe] == 1) {
    param_3 = 0;
  }
  else {
    param_1[3] = (int)param_2;
    param_1[4] = param_3;
    __ptr = param_2;
    if ((param_1[4] != 0) && (param_1[0x1b] != -1)) {
      __ptr = param_2 + 1;
      *param_2 = (char)param_1[0x1b];
      param_1[3] = param_1[3] + 1;
      param_1[4] = param_1[4] + -1;
      param_1[0x1b] = -1;
      param_1[0x1a] = param_1[0x1a] + 1;
      param_2 = param_2 + 1;
      if (param_1[0x1c] != 0) {
        param_1[0xe] = 1;
        return 1;
      }
    }
    while (param_1[4] != 0) {
      if (param_1[0x16] != 0) {
        sVar3 = param_1[1];
        if ((uint)param_1[4] < sVar3) {
          sVar3 = param_1[4];
        }
        if (sVar3 != 0) {
          memcpy((void *)param_1[3],(void *)*param_1,sVar3);
          __ptr = __ptr + sVar3;
          param_1[3] = (int)__ptr;
          *param_1 = *param_1 + sVar3;
          param_1[4] = param_1[4] - sVar3;
          param_1[1] = param_1[1] - sVar3;
        }
        if (param_1[4] != 0) {
          sVar3 = fread(__ptr,1,param_1[4],(FILE *)param_1[0x10]);
          param_1[4] = param_1[4] - sVar3;
        }
        param_3 = param_3 - param_1[4];
        param_1[0x19] = param_3 + param_1[0x19];
        param_1[0x1a] = param_3 + param_1[0x1a];
        if (param_3 != 0) {
          return param_3;
        }
        param_1[0xf] = 1;
        return 0;
      }
      if ((param_1[1] == 0) && (param_1[0xf] == 0)) {
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 0;
        sVar3 = fread((void *)param_1[0x11],1,0x4000,(FILE *)param_1[0x10]);
        param_1[1] = sVar3;
        if ((param_1[1] == 0) &&
           (((param_1[0xf] = 1, *(int *)(param_1[0x10] + 4) == param_1[0x10] &&
             (*(char *)(param_1[0x10] + 10) == 'f')) &&
            ((*(ushort *)(param_1[0x10] + 0x18) & 0x40) != 0)))) {
          param_1[0xe] = -1;
          break;
        }
        *param_1 = param_1[0x11];
      }
      param_1[0x19] = param_1[0x19] + param_1[1];
      param_1[0x1a] = param_1[0x1a] + param_1[4];
      iVar2 = QC_inflate(param_1,0);
      param_1[0xe] = iVar2;
      param_1[0x19] = param_1[0x19] - param_1[1];
      param_1[0x1a] = param_1[0x1a] - param_1[4];
      if (param_1[0xe] == 1) {
        iVar2 = QC_crc32(param_1[0x13],param_2,param_1[3] - (int)param_2);
        param_1[0x13] = iVar2;
        param_2 = (undefined1 *)param_1[3];
        iVar2 = FUN_3008bde0(param_1);
        if (iVar2 == param_1[0x13]) {
          FUN_3008bde0(param_1);
          FUN_3008b138(param_1);
          if (param_1[0xe] == 0) {
            QC_inflateReset(param_1);
            iVar2 = QC_crc32(0,0,0);
            param_1[0x13] = iVar2;
          }
        }
        else {
          param_1[0xe] = -3;
        }
      }
      if ((param_1[0xe] != 0) || (param_1[0xf] != 0)) break;
    }
    iVar2 = QC_crc32(param_1[0x13],param_2,param_1[3] - (int)param_2);
    param_1[0x13] = iVar2;
    if ((param_1[4] == param_3) && ((param_1[0xe] == -3 || (param_1[0xe] == -1)))) {
      param_3 = -1;
    }
    else {
      param_3 = param_3 - param_1[4];
    }
  }
  return param_3;
}

/* ----------------------------------------------------------------
 * QC_gzgetc @ 0x3008C204  (примерный размер ~60 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: QC_gzread
 * Константы: 0x3008C204, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
uint QC_gzgetc(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  byte local_10 [4];
  
  iVar1 = QC_gzread(param_1,local_10,1);
  if (iVar1 == 1) {
    uVar2 = (uint)local_10[0];
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * QC_gzungetc @ 0x3008C240  (примерный размер ~140 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3008C240
 * ---------------------------------------------------------------- */
int QC_gzungetc(int param_1,int param_2)

{
  if ((((param_2 == 0) || (*(char *)(param_2 + 0x5c) != 'r')) || (param_1 == -1)) ||
     (*(int *)(param_2 + 0x6c) != -1)) {
    param_1 = -1;
  }
  else {
    *(int *)(param_2 + 0x6c) = param_1;
    *(int *)(param_2 + 0x68) = *(int *)(param_2 + 0x68) + -1;
    *(uint *)(param_2 + 0x70) = (uint)(*(int *)(param_2 + 0x38) == 1);
    if (*(int *)(param_2 + 0x70) != 0) {
      *(undefined4 *)(param_2 + 0x38) = 0;
    }
    *(undefined4 *)(param_2 + 0x3c) = 0;
  }
  return param_1;
}

/* ----------------------------------------------------------------
 * QC_gzgets @ 0x3008C2CC  (примерный размер ~144 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: QC_gzread
 * Константы: 0x3008C2CC
 * ---------------------------------------------------------------- */
char * QC_gzgets(undefined4 param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  if ((param_2 == (char *)0x0) || (pcVar3 = param_2, param_3 < 1)) {
    param_2 = (char *)0x0;
  }
  else {
    do {
      param_3 = param_3 + -1;
      pcVar4 = pcVar3;
      if ((param_3 < 1) || (iVar2 = QC_gzread(param_1,pcVar3,1), iVar2 != 1)) break;
      pcVar4 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar4;
    } while (cVar1 != '\n');
    *pcVar4 = '\0';
    if ((param_2 == pcVar4) && (0 < param_3)) {
      param_2 = (char *)0x0;
    }
  }
  return param_2;
}

/* ----------------------------------------------------------------
 * QC_gzwrite @ 0x3008C35C  (примерный размер ~260 байт)
 * Модуль: lib | Вызывают: 5 | Вызывает: 3
 * Вызывает: QC_crc32, QC_deflate, fwrite
 * Вызывают: QC_gzprintf, QC_gzputc, QC_gzputs, QC_gzseek, gz_compressFile
 * Константы: 0x3008C35C, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int QC_gzwrite(undefined4 *param_1,undefined4 param_2,int param_3)

{
  size_t sVar1;
  undefined4 uVar2;
  
  if ((param_1 == (undefined4 *)0x0) || (*(char *)(param_1 + 0x17) != 'w')) {
    param_3 = -2;
  }
  else {
    *param_1 = param_2;
    param_1[1] = param_3;
    do {
      if (param_1[1] == 0) break;
      if (param_1[4] == 0) {
        param_1[3] = param_1[0x12];
        sVar1 = fwrite((void *)param_1[0x12],1,0x4000,(FILE *)param_1[0x10]);
        if (sVar1 != 0x4000) {
          param_1[0xe] = 0xffffffff;
          break;
        }
        param_1[4] = 0x4000;
      }
      param_1[0x19] = param_1[0x19] + param_1[1];
      param_1[0x1a] = param_1[0x1a] + param_1[4];
      uVar2 = QC_deflate(param_1,0);
      param_1[0xe] = uVar2;
      param_1[0x19] = param_1[0x19] - param_1[1];
      param_1[0x1a] = param_1[0x1a] - param_1[4];
    } while (param_1[0xe] == 0);
    uVar2 = QC_crc32(param_1[0x13],param_2,param_3);
    param_1[0x13] = uVar2;
    param_3 = param_3 - param_1[1];
  }
  return param_3;
}

/* ----------------------------------------------------------------
 * QC_gzprintf @ 0x3008C460  (примерный размер ~148 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: QC_gzwrite, vsnprintf
 * Константы: 0x3008C460
 * Данные: DAT_3008ce48, DAT_3008ce4c, DAT_3008ce50
 * ---------------------------------------------------------------- */
undefined4 QC_gzprintf(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_1020 [4096];
  
  acStack_1020[DAT_3008ce48] = '\0';
  iVar1 = vsnprintf(acStack_1020,0x1000,*(char **)(acStack_1020 + DAT_3008ce50),
                    acStack_1020 + DAT_3008ce4c);
  if (((iVar1 < 1) || (0xfff < iVar1)) || (acStack_1020[DAT_3008ce48] != '\0')) {
    uVar2 = 0;
  }
  else {
    uVar2 = QC_gzwrite(param_1,acStack_1020,iVar1);
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * QC_gzputc @ 0x3008C4F4  (примерный размер ~68 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: QC_gzwrite
 * Константы: 0x3008C4F4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
uint QC_gzputc(undefined4 param_1,byte param_2)

{
  int iVar1;
  uint uVar2;
  byte local_14 [4];
  
  local_14[0] = param_2;
  iVar1 = QC_gzwrite(param_1,local_14,1);
  if (iVar1 == 1) {
    uVar2 = (uint)local_14[0];
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * QC_gzputs @ 0x3008C538  (примерный размер ~40 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: QC_gzwrite, strlen
 * Константы: 0x3008C538
 * ---------------------------------------------------------------- */
void QC_gzputs(undefined4 param_1,char *param_2)

{
  size_t sVar1;
  
  sVar1 = strlen(param_2);
  QC_gzwrite(param_1,param_2,sVar1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3008c560 @ 0x3008C560  (примерный размер ~316 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 2
 * Вызывает: QC_deflate, fwrite
 * Вызывают: QC_gzclose, QC_gzflush
 * Константы: 0xFFFFFFFF, 0x3008C560, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4 FUN_3008c560(int param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  size_t sVar3;
  size_t __n;
  
  bVar1 = false;
  if ((param_1 == 0) || (*(char *)(param_1 + 0x5c) != 'w')) {
    uVar2 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0;
    do {
      __n = 0x4000 - *(int *)(param_1 + 0x10);
      if (__n != 0) {
        sVar3 = fwrite(*(void **)(param_1 + 0x48),1,__n,*(FILE **)(param_1 + 0x40));
        if (sVar3 != __n) {
          *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
          return 0xffffffff;
        }
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x48);
        *(undefined4 *)(param_1 + 0x10) = 0x4000;
      }
      if (bVar1) break;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + *(int *)(param_1 + 0x10);
      uVar2 = QC_deflate(param_1,param_2);
      *(undefined4 *)(param_1 + 0x38) = uVar2;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) - *(int *)(param_1 + 0x10);
      if ((__n == 0) && (*(int *)(param_1 + 0x38) == -5)) {
        *(undefined4 *)(param_1 + 0x38) = 0;
      }
      if ((*(int *)(param_1 + 0x10) == 0) && (*(int *)(param_1 + 0x38) != 1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
    } while ((*(int *)(param_1 + 0x38) == 0) || (*(int *)(param_1 + 0x38) == 1));
    if (*(int *)(param_1 + 0x38) == 1) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x38);
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * QC_gzflush @ 0x3008C69C  (примерный размер ~88 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_3008c560, fflush
 * Константы: 0x3008C69C
 * ---------------------------------------------------------------- */
int QC_gzflush(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_3008c560(param_1,param_2);
  if (iVar1 == 0) {
    fflush(*(FILE **)(param_1 + 0x40));
    if (*(int *)(param_1 + 0x38) == 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x38);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * QC_gzrewind @ 0x3008C6F4  (примерный размер ~156 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 3
 * Вызывает: QC_crc32, QC_inflateReset, fseek
 * Вызывают: QC_gzseek
 * Константы: 0x3008C6F4, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
int QC_gzrewind(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == (undefined4 *)0x0) || (*(char *)(param_1 + 0x17) != 'r')) {
    iVar1 = -1;
  }
  else {
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x1b] = 0xffffffff;
    param_1[1] = 0;
    *param_1 = param_1[0x11];
    uVar2 = QC_crc32(0,0,0);
    param_1[0x13] = uVar2;
    if (param_1[0x16] == 0) {
      QC_inflateReset(param_1);
    }
    param_1[0x19] = 0;
    param_1[0x1a] = 0;
    iVar1 = fseek((FILE *)param_1[0x10],param_1[0x18],0);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * QC_gzseek @ 0x3008C790  (примерный размер ~620 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 6
 * Вызывает: QC_gzread, QC_gzrewind, QC_gzwrite, fseek, malloc, memset
 * Вызывают: QC_gztell
 * Константы: 0xFFFFFFFF, 0x3008C790
 * ---------------------------------------------------------------- */
int QC_gzseek(undefined4 *param_1,int param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  
  if ((((param_1 == (undefined4 *)0x0) || (param_3 == 2)) || (param_1[0xe] == -1)) ||
     (param_1[0xe] == -3)) {
    param_2 = -1;
  }
  else if (*(char *)(param_1 + 0x17) == 'w') {
    if (param_3 == 0) {
      param_2 = param_2 - param_1[0x19];
    }
    if (param_2 < 0) {
      param_2 = -1;
    }
    else {
      if (param_1[0x11] == 0) {
        pvVar1 = malloc(0x4000);
        param_1[0x11] = pvVar1;
        if (param_1[0x11] == 0) {
          return -1;
        }
        memset((void *)param_1[0x11],0,0x4000);
      }
      for (; 0 < param_2; param_2 = param_2 - iVar2) {
        iVar2 = 0x4000;
        if (param_2 < 0x4000) {
          iVar2 = param_2;
        }
        iVar2 = QC_gzwrite(param_1,param_1[0x11],iVar2);
        if (iVar2 == 0) {
          return -1;
        }
      }
      param_2 = param_1[0x19];
    }
  }
  else {
    if (param_3 == 1) {
      param_2 = param_2 + param_1[0x1a];
    }
    if (param_2 < 0) {
      param_2 = -1;
    }
    else if (param_1[0x16] == 0) {
      if (param_2 < (int)param_1[0x1a]) {
        iVar2 = QC_gzrewind(param_1);
        if (iVar2 < 0) {
          return -1;
        }
      }
      else {
        param_2 = param_2 - param_1[0x1a];
      }
      if ((param_2 != 0) && (param_1[0x12] == 0)) {
        pvVar1 = malloc(0x4000);
        param_1[0x12] = pvVar1;
        if (param_1[0x12] == 0) {
          return -1;
        }
      }
      if ((param_2 != 0) && (param_1[0x1b] != -1)) {
        param_1[0x1b] = 0xffffffff;
        param_1[0x1a] = param_1[0x1a] + 1;
        param_2 = param_2 + -1;
        if (param_1[0x1c] != 0) {
          param_1[0xe] = 1;
        }
      }
      for (; 0 < param_2; param_2 = param_2 - iVar2) {
        iVar2 = 0x4000;
        if (param_2 < 0x4000) {
          iVar2 = param_2;
        }
        iVar2 = QC_gzread(param_1,param_1[0x12],iVar2);
        if (iVar2 < 1) {
          return -1;
        }
      }
      param_2 = param_1[0x1a];
    }
    else {
      param_1[0x1b] = 0xffffffff;
      param_1[1] = 0;
      *param_1 = param_1[0x11];
      iVar2 = fseek((FILE *)param_1[0x10],param_2,0);
      if (iVar2 < 0) {
        param_2 = -1;
      }
      else {
        param_1[0x1a] = param_2;
        param_1[0x19] = param_1[0x1a];
      }
    }
  }
  return param_2;
}

/* ----------------------------------------------------------------
 * QC_gztell @ 0x3008C9FC  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: QC_gzseek
 * Константы: 0x3008C9FC
 * ---------------------------------------------------------------- */
void QC_gztell(undefined4 param_1)

{
  QC_gzseek(param_1,0,1);
  return;
}

/* ----------------------------------------------------------------
 * QC_gzeof @ 0x3008CA18  (примерный размер ~84 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: gz_uncompressFile, gzuncompressFileToStream
 * Константы: 0x3008CA18
 * ---------------------------------------------------------------- */
undefined4 QC_gzeof(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(char *)(param_1 + 0x5c) != 'r')) {
    uVar1 = 0;
  }
  else if (*(int *)(param_1 + 0x3c) == 0) {
    if (*(int *)(param_1 + 0x38) == 1) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_gzdirect @ 0x3008CA6C  (примерный размер ~52 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3008CA6C
 * ---------------------------------------------------------------- */
undefined4 QC_gzdirect(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(char *)(param_1 + 0x5c) != 'r')) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x58);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3008caa0 @ 0x3008CAA0  (примерный размер ~52 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: fputc
 * Вызывают: QC_gzclose
 * Константы: 0x3008CAA0
 * ---------------------------------------------------------------- */
void FUN_3008caa0(FILE *param_1,uint param_2)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    fputc(param_2 & 0xff,param_1);
    param_2 = param_2 >> 8;
  }
  return;
}

/* ----------------------------------------------------------------
 * QC_isCompress @ 0x3008CAD4  (примерный размер ~36 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: gzgetUncompressLength, gzuncompressFileToStream
 * Константы: 0x3008CAD4
 * ---------------------------------------------------------------- */
bool QC_isCompress(int param_1)

{
  return *(int *)(param_1 + 0x58) == 0;
}

/* ----------------------------------------------------------------
 * QC_gzgetlength @ 0x3008CAF8  (примерный размер ~232 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 2
 * Вызывает: fread, fseek
 * Вызывают: gzgetUncompressLength
 * Константы: 0xFFFFFFFF, 0x3008CAF8
 * ---------------------------------------------------------------- */
undefined4 QC_gzgetlength(int param_1,uint param_2)

{
  int iVar1;
  size_t sVar2;
  undefined4 local_20;
  
  local_20 = 0;
  if (param_2 < 0x14) {
    local_20 = 0xffffffff;
  }
  else {
    iVar1 = fseek(*(FILE **)(param_1 + 0x40),param_2 - 4,0);
    if (iVar1 < 0) {
      local_20 = 0xffffffff;
    }
    else {
      sVar2 = fread(&local_20,4,1,*(FILE **)(param_1 + 0x40));
      if ((((*(int *)(*(int *)(param_1 + 0x40) + 4) == *(int *)(param_1 + 0x40)) &&
           (*(char *)(*(int *)(param_1 + 0x40) + 10) == 'f')) &&
          ((*(ushort *)(*(int *)(param_1 + 0x40) + 0x18) & 0x40) != 0)) || (sVar2 == 0)) {
        local_20 = 0xffffffff;
      }
    }
  }
  return local_20;
}

/* ----------------------------------------------------------------
 * QC_gzclose @ 0x3008CBE0  (примерный размер ~116 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 3
 * Вызывает: FUN_3008b394, FUN_3008c560, FUN_3008caa0
 * Вызывают: gz_compressFile, gz_uncompressFile, gzgetUncompressLength, gzuncompressFileToStream
 * Константы: 0x3008CBE0, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4 QC_gzclose(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffffe;
  }
  else {
    if (*(char *)(param_1 + 0x5c) == 'w') {
      iVar2 = FUN_3008c560(param_1,4);
      if (iVar2 != 0) {
        uVar1 = FUN_3008b394(param_1);
        return uVar1;
      }
      FUN_3008caa0(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x4c));
      FUN_3008caa0(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 100));
    }
    uVar1 = FUN_3008b394(param_1);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_gzerror @ 0x3008CC54  (примерный размер ~356 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 7
 * Вызывает: __errno, free, malloc, strerror, strlen, strncat, strncpy
 * Вызывают: gz_compressFile, gz_uncompressFile, gzgetUncompressLength, gzuncompressFileToStream
 * Константы: 0x3008CC54
 * Данные: DAT_3008ce54, DAT_3008ce58, DAT_3008ce5c
 * ---------------------------------------------------------------- */
undefined4 QC_gzerror(int param_1,int *param_2)

{
  int *piVar1;
  char *__s;
  size_t sVar2;
  size_t sVar3;
  void *pvVar4;
  undefined4 uVar5;
  
  if (param_1 == 0) {
    *param_2 = -2;
    uVar5 = *(undefined4 *)(DAT_3008ce54 + 0x10);
  }
  else {
    *param_2 = *(int *)(param_1 + 0x38);
    uVar5 = DAT_3008ce58;
    if (*param_2 != 0) {
      if (*param_2 == -1) {
        piVar1 = (int *)__errno();
        __s = strerror(*piVar1);
      }
      else {
        __s = *(char **)(param_1 + 0x18);
      }
      if ((__s == (char *)0x0) || (*__s == '\0')) {
        __s = *(char **)(DAT_3008ce54 + *(int *)(param_1 + 0x38) * -4 + 8);
      }
      if (*(int *)(param_1 + 0x50) != 0) {
        free(*(void **)(param_1 + 0x50));
      }
      sVar2 = strlen(*(char **)(param_1 + 0x54));
      sVar3 = strlen(__s);
      pvVar4 = malloc(sVar3 + sVar2 + 3);
      *(void **)(param_1 + 0x50) = pvVar4;
      if (*(int *)(param_1 + 0x50) == 0) {
        uVar5 = *(undefined4 *)(DAT_3008ce54 + 0x18);
      }
      else {
        sVar2 = strlen(*(char **)(param_1 + 0x54));
        sVar3 = strlen(__s);
        strncpy(*(char **)(param_1 + 0x50),*(char **)(param_1 + 0x54),sVar3 + sVar2 + 3);
        sVar2 = strlen(*(char **)(param_1 + 0x54));
        sVar3 = strlen(__s);
        strncat(*(char **)(param_1 + 0x50),DAT_3008ce5c,sVar3 + sVar2 + 3);
        sVar2 = strlen(*(char **)(param_1 + 0x54));
        sVar3 = strlen(__s);
        strncat(*(char **)(param_1 + 0x50),__s,sVar3 + sVar2 + 3);
        uVar5 = *(undefined4 *)(param_1 + 0x50);
      }
    }
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * QC_gzclearerr @ 0x3008CDB8  (примерный размер ~168 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3008CDB8
 * ---------------------------------------------------------------- */
void QC_gzclearerr(int param_1)

{
  ushort *puVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x38) != 1) {
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    *(undefined4 *)(param_1 + 0x3c) = 0;
    if ((*(int *)(*(int *)(param_1 + 0x40) + 4) == *(int *)(param_1 + 0x40)) &&
       (*(char *)(*(int *)(param_1 + 0x40) + 10) == 'f')) {
      puVar1 = (ushort *)(*(int *)(param_1 + 0x40) + 0x18);
      *puVar1 = *puVar1 & 0xff9f;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * QC_inflate_fast @ 0x3008CE60  (примерный размер ~1860 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3008CE60
 * Данные: DAT_3008d594, DAT_3008d598, DAT_3008d59c, DAT_3008d5a0
 * ---------------------------------------------------------------- */
void QC_inflate_fast(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint uVar13;
  int iVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  undefined4 *puVar21;
  byte *pbVar22;
  undefined1 *puVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  byte *pbVar27;
  byte *local_58;
  undefined2 local_54;
  ushort local_52;
  
  puVar21 = (undefined4 *)param_1[7];
  local_58 = (byte *)(*param_1 + -1);
  pbVar22 = local_58 + param_1[1] + -5;
  puVar9 = (undefined1 *)(param_1[3] + -1);
  iVar3 = param_1[4];
  puVar23 = puVar9 + (param_1[4] - DAT_3008d594);
  iVar4 = puVar21[10];
  uVar24 = puVar21[0xb];
  uVar7 = puVar21[0xc];
  iVar25 = puVar21[0xd];
  uVar8 = puVar21[0xe];
  uVar20 = puVar21[0xf];
  iVar5 = puVar21[0x13];
  iVar26 = puVar21[0x14];
  uVar1 = puVar21[0x15];
  uVar2 = puVar21[0x16];
  puVar10 = puVar9;
LAB_3008cf68:
  if (uVar20 < 0xf) {
    pbVar27 = local_58 + 1;
    local_58 = local_58 + 2;
    uVar8 = uVar8 + ((uint)*pbVar27 << (uVar20 & 0xff)) + ((uint)*local_58 << (uVar20 + 8 & 0xff));
    uVar20 = uVar20 + 0x10;
  }
  puVar6 = (ushort *)(iVar5 + (uVar8 & (1 << (uVar1 & 0xff)) - 1U) * 4);
  local_54 = *puVar6;
  local_52 = puVar6[1];
  while( true ) {
    uVar8 = uVar8 >> (uint)local_54._1_1_;
    uVar20 = uVar20 - local_54._1_1_;
    uVar17 = (uint)(byte)local_54;
    if (uVar17 == 0) break;
    if ((local_54 & 0x10) != 0) {
      uVar19 = (uint)local_52;
      uVar17 = uVar17 & 0xf;
      if ((local_54 & 0xf) != 0) {
        if (uVar20 < uVar17) {
          local_58 = local_58 + 1;
          uVar8 = uVar8 + ((uint)*local_58 << (uVar20 & 0xff));
          uVar20 = uVar20 + 8;
        }
        uVar19 = uVar19 + (uVar8 & (1 << uVar17) - 1U);
        uVar8 = uVar8 >> uVar17;
        uVar20 = uVar20 - uVar17;
      }
      if (uVar20 < 0xf) {
        pbVar27 = local_58 + 1;
        local_58 = local_58 + 2;
        uVar8 = uVar8 + ((uint)*pbVar27 << (uVar20 & 0xff)) +
                ((uint)*local_58 << (uVar20 + 8 & 0xff));
        uVar20 = uVar20 + 0x10;
      }
      puVar6 = (ushort *)(iVar26 + (uVar8 & (1 << (uVar2 & 0xff)) - 1U) * 4);
      local_54 = *puVar6;
      local_52 = puVar6[1];
      goto LAB_3008d0c0;
    }
    if ((local_54 & 0x40) != 0) {
      if ((local_54 & 0x20) == 0) {
        param_1[6] = DAT_3008d5a0;
        *puVar21 = 0x1b;
      }
      else {
        *puVar21 = 0xb;
      }
      goto LAB_3008d4a4;
    }
    puVar6 = (ushort *)(iVar5 + ((uint)local_52 + (uVar8 & (1 << uVar17) - 1U)) * 4);
    local_54 = *puVar6;
    local_52 = puVar6[1];
  }
  puVar10[1] = (char)local_52;
  puVar11 = puVar10 + 1;
  goto LAB_3008d484;
LAB_3008d0c0:
  uVar8 = uVar8 >> (uint)local_54._1_1_;
  uVar20 = uVar20 - local_54._1_1_;
  if ((local_54 & 0x10) != 0) goto code_r0x3008d0d8;
  if ((local_54 & 0x40) != 0) {
    param_1[6] = DAT_3008d59c;
    *puVar21 = 0x1b;
    goto LAB_3008d4a4;
  }
  puVar6 = (ushort *)(iVar26 + ((uint)local_52 + (uVar8 & (1 << (uint)(byte)local_54) - 1U)) * 4);
  local_54 = *puVar6;
  local_52 = puVar6[1];
  goto LAB_3008d0c0;
code_r0x3008d0d8:
  uVar18 = (byte)local_54 & 0xf;
  uVar17 = uVar20;
  pbVar27 = local_58;
  if (uVar20 < uVar18) {
    uVar8 = uVar8 + ((uint)local_58[1] << (uVar20 & 0xff));
    uVar17 = uVar20 + 8;
    pbVar27 = local_58 + 1;
    if (uVar17 < uVar18) {
      uVar8 = uVar8 + ((uint)local_58[2] << (uVar17 & 0xff));
      uVar17 = uVar20 + 0x10;
      pbVar27 = local_58 + 2;
    }
  }
  local_58 = pbVar27;
  uVar13 = (uint)local_52 + (uVar8 & (1 << uVar18) - 1U);
  uVar8 = uVar8 >> uVar18;
  uVar20 = uVar17 - uVar18;
  uVar17 = (int)puVar10 - ((int)puVar9 - (param_2 - iVar3));
  if (uVar17 < uVar13) {
    uVar17 = uVar13 - uVar17;
    if (uVar24 < uVar17) {
      param_1[6] = DAT_3008d598;
      *puVar21 = 0x1b;
LAB_3008d4a4:
      local_58 = local_58 + -(uVar20 >> 3);
      uVar20 = uVar20 + (uVar20 >> 3) * -8;
      *param_1 = (int)(local_58 + 1);
      param_1[3] = (int)(puVar10 + 1);
      if (local_58 < pbVar22) {
        param_1[1] = (int)(pbVar22 + (5 - (int)local_58));
      }
      else {
        param_1[1] = 5 - ((int)local_58 - (int)pbVar22);
      }
      if (puVar10 < puVar23) {
        param_1[4] = (int)(puVar23 + (DAT_3008d594 - (int)puVar10));
      }
      else {
        param_1[4] = DAT_3008d594 - ((int)puVar10 - (int)puVar23);
      }
      puVar21[0xe] = uVar8 & (1 << (uVar20 & 0xff)) - 1U;
      puVar21[0xf] = uVar20;
      return;
    }
    iVar14 = iVar25 + -1;
    if (uVar7 == 0) {
      puVar15 = (undefined1 *)(iVar14 + (iVar4 - uVar17));
      if (uVar17 < uVar19) {
        uVar19 = uVar19 - uVar17;
        do {
          puVar10 = puVar10 + 1;
          puVar15 = puVar15 + 1;
          *puVar10 = *puVar15;
          uVar17 = uVar17 - 1;
        } while (uVar17 != 0);
        puVar15 = puVar10 + -uVar13;
      }
    }
    else if (uVar7 < uVar17) {
      puVar15 = (undefined1 *)(iVar14 + ((iVar4 + uVar7) - uVar17));
      uVar17 = uVar17 - uVar7;
      if (uVar17 < uVar19) {
        uVar19 = uVar19 - uVar17;
        do {
          puVar10 = puVar10 + 1;
          puVar15 = puVar15 + 1;
          *puVar10 = *puVar15;
          uVar17 = uVar17 - 1;
        } while (uVar17 != 0);
        puVar15 = (undefined1 *)(iVar25 + -1);
        if (uVar7 < uVar19) {
          uVar19 = uVar19 - uVar7;
          uVar17 = uVar7;
          do {
            puVar10 = puVar10 + 1;
            puVar15 = puVar15 + 1;
            *puVar10 = *puVar15;
            uVar17 = uVar17 - 1;
          } while (uVar17 != 0);
          puVar15 = puVar10 + -uVar13;
        }
      }
    }
    else {
      puVar15 = (undefined1 *)(iVar14 + (uVar7 - uVar17));
      if (uVar17 < uVar19) {
        uVar19 = uVar19 - uVar17;
        do {
          puVar10 = puVar10 + 1;
          puVar15 = puVar15 + 1;
          *puVar10 = *puVar15;
          uVar17 = uVar17 - 1;
        } while (uVar17 != 0);
        puVar15 = puVar10 + -uVar13;
      }
    }
    for (; 2 < uVar19; uVar19 = uVar19 - 3) {
      puVar10[1] = puVar15[1];
      puVar10[2] = puVar15[2];
      puVar10 = puVar10 + 3;
      puVar15 = puVar15 + 3;
      *puVar10 = *puVar15;
    }
    puVar11 = puVar10;
    if (uVar19 != 0) {
      puVar11 = puVar10 + 1;
      *puVar11 = puVar15[1];
      if (1 < uVar19) {
        puVar11 = puVar10 + 2;
        *puVar11 = puVar15[2];
      }
    }
  }
  else {
    puVar15 = puVar10 + -uVar13;
    do {
      puVar16 = puVar15;
      puVar12 = puVar10;
      puVar12[1] = puVar16[1];
      puVar12[2] = puVar16[2];
      puVar11 = puVar12 + 3;
      *puVar11 = puVar16[3];
      uVar19 = uVar19 - 3;
      puVar10 = puVar11;
      puVar15 = puVar16 + 3;
    } while (2 < uVar19);
    if (uVar19 != 0) {
      puVar11 = puVar12 + 4;
      *puVar11 = puVar16[4];
      if (1 < uVar19) {
        puVar11 = puVar12 + 5;
        *puVar11 = puVar16[5];
      }
    }
  }
LAB_3008d484:
  puVar10 = puVar11;
  if ((pbVar22 <= local_58) || (puVar23 <= puVar11)) goto LAB_3008d4a4;
  goto LAB_3008cf68;
}

/* ----------------------------------------------------------------
 * QC_inflateReset @ 0x3008D5A4  (примерный размер ~200 байт)
 * Модуль: lib | Вызывают: 4 | Вызывает: 0
 * Вызывают: QC_gzread, QC_gzrewind, QC_inflateInit2_, QC_inflateSync
 * Константы: 0x3008D5A4, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4 QC_inflateReset(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 0x1c);
    puVar2[7] = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x30) = 1;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[3] = 0;
    puVar2[5] = 0x8000;
    puVar2[8] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    puVar2[0xc] = 0;
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar2[0x1b] = puVar2 + 0x14c;
    puVar2[0x14] = puVar2[0x1b];
    puVar2[0x13] = puVar2[0x14];
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_inflateInit2_ @ 0x3008D66C  (примерный размер ~312 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 1
 * Вызывает: QC_inflateReset
 * Вызывают: FUN_3008b498, FUN_3008b88c, QC_inflateInit_
 * Константы: 0xFFFFFFFE, 0x3008D66C, 0xFFFFFFFA, 0xFFFFFFFC
 * Данные: DAT_3008da60, DAT_3008da64, DAT_3008da68, DAT_3008da6c
 * ---------------------------------------------------------------- */
undefined4 QC_inflateInit2_(int param_1,uint param_2,char *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((param_3 == (char *)0x0) || (*param_3 != *DAT_3008da60)) || (param_4 != 0x38)) {
    uVar1 = 0xfffffffa;
  }
  else if (param_1 == 0) {
    uVar1 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
    if (*(int *)(param_1 + 0x20) == 0) {
      *(undefined4 *)(param_1 + 0x20) = DAT_3008da64;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      *(undefined4 *)(param_1 + 0x24) = DAT_3008da68;
    }
    iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,DAT_3008da6c);
    if (iVar2 == 0) {
      uVar1 = 0xfffffffc;
    }
    else {
      *(int *)(param_1 + 0x1c) = iVar2;
      if ((int)param_2 < 0) {
        *(undefined4 *)(iVar2 + 8) = 0;
        param_2 = -param_2;
      }
      else {
        *(int *)(iVar2 + 8) = ((int)param_2 >> 4) + 1;
        if ((int)param_2 < 0x30) {
          param_2 = param_2 & 0xf;
        }
      }
      if (param_2 - 8 < 8) {
        *(uint *)(iVar2 + 0x24) = param_2;
        *(undefined4 *)(iVar2 + 0x34) = 0;
        uVar1 = QC_inflateReset(param_1);
      }
      else {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar2);
        *(undefined4 *)(param_1 + 0x1c) = 0;
        uVar1 = 0xfffffffe;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_inflateInit_ @ 0x3008D7A4  (примерный размер ~40 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: QC_inflateInit2_
 * Вызывают: QC_uncompress
 * Константы: 0x3008D7A4
 * ---------------------------------------------------------------- */
void QC_inflateInit_(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  QC_inflateInit2_(param_1,0xf,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3008d7cc @ 0x3008D7CC  (примерный размер ~48 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3008D7CC
 * Данные: DAT_3008da70, DAT_3008da74
 * ---------------------------------------------------------------- */
void FUN_3008d7cc(int param_1)

{
  *(undefined4 *)(param_1 + 0x4c) = DAT_3008da70;
  *(undefined4 *)(param_1 + 0x54) = 9;
  *(undefined4 *)(param_1 + 0x50) = DAT_3008da74;
  *(undefined4 *)(param_1 + 0x58) = 5;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3008d7fc @ 0x3008D7FC  (примерный размер ~392 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: memcpy
 * Вызывают: QC_inflateSetDictionary
 * Константы: 0x3008D7FC
 * ---------------------------------------------------------------- */
undefined4 FUN_3008d7fc(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  size_t __n;
  int iVar3;
  uint __n_00;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  if (*(int *)(iVar3 + 0x34) == 0) {
    uVar1 = (**(code **)(param_1 + 0x20))
                      (*(undefined4 *)(param_1 + 0x28),1 << (*(uint *)(iVar3 + 0x24) & 0xff),1);
    *(undefined4 *)(iVar3 + 0x34) = uVar1;
    if (*(int *)(iVar3 + 0x34) == 0) {
      return 1;
    }
  }
  if (*(int *)(iVar3 + 0x28) == 0) {
    *(int *)(iVar3 + 0x28) = 1 << (*(uint *)(iVar3 + 0x24) & 0xff);
    *(undefined4 *)(iVar3 + 0x30) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
  }
  uVar2 = param_2 - *(int *)(param_1 + 0x10);
  if (uVar2 < *(uint *)(iVar3 + 0x28)) {
    __n_00 = *(int *)(iVar3 + 0x28) - *(int *)(iVar3 + 0x30);
    if (uVar2 < __n_00) {
      __n_00 = uVar2;
    }
    memcpy((void *)(*(int *)(iVar3 + 0x34) + *(int *)(iVar3 + 0x30)),
           (void *)(*(int *)(param_1 + 0xc) - uVar2),__n_00);
    __n = uVar2 - __n_00;
    if (__n == 0) {
      *(uint *)(iVar3 + 0x30) = __n_00 + *(int *)(iVar3 + 0x30);
      if (*(int *)(iVar3 + 0x30) == *(int *)(iVar3 + 0x28)) {
        *(undefined4 *)(iVar3 + 0x30) = 0;
      }
      if (*(uint *)(iVar3 + 0x2c) < *(uint *)(iVar3 + 0x28)) {
        *(uint *)(iVar3 + 0x2c) = __n_00 + *(int *)(iVar3 + 0x2c);
      }
    }
    else {
      memcpy(*(void **)(iVar3 + 0x34),(void *)(*(int *)(param_1 + 0xc) - __n),__n);
      *(size_t *)(iVar3 + 0x30) = __n;
      *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 0x28);
    }
  }
  else {
    memcpy(*(void **)(iVar3 + 0x34),(void *)(*(int *)(param_1 + 0xc) - *(int *)(iVar3 + 0x28)),
           *(size_t *)(iVar3 + 0x28));
    *(undefined4 *)(iVar3 + 0x30) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 0x28);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * QC_inflate @ 0x3008D984  (примерный размер ~7224 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: QC_gzread, QC_uncompress
 * Константы: 0x3008D984, 0x3008DA5C, 0xFFFFFFFE
 * Данные: DAT_3008da78
 * ---------------------------------------------------------------- */
undefined4 QC_inflate(int *param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  
  if ((((param_1 != (int *)0x0) && (param_1[7] != 0)) && (param_1[3] != 0)) &&
     ((*param_1 != 0 || (param_1[1] == 0)))) {
    puVar2 = (uint *)param_1[7];
    if (*puVar2 == 0xb) {
      *puVar2 = 0xc;
    }
    if (*puVar2 < 0x1e) {
                    /* WARNING: Could not recover jumptable at 0x3008da5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(DAT_3008da78 + *puVar2 * 4))();
      return uVar1;
    }
  }
  return 0xfffffffe;
}

/* ----------------------------------------------------------------
 * QC_inflateEnd @ 0x3008F5BC  (примерный размер ~128 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_3008b394, QC_uncompress
 * Константы: 0x3008F5BC, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4 QC_inflateEnd(int param_1)

{
  undefined4 uVar1;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) || (*(int *)(param_1 + 0x24) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x34) != 0) {
      (**(code **)(param_1 + 0x24))
                (*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x34));
    }
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_inflateSetDictionary @ 0x3008F63C  (примерный размер ~296 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: FUN_3008d7fc, QC_adler32, memcpy
 * Константы: 0xFFFFFFFE, 0x3008F63C, 0xFFFFFFFD, 0xFFFFFFFC
 * ---------------------------------------------------------------- */
undefined4 QC_inflateSetDictionary(int param_1,void *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x1c);
    if ((piVar3[2] == 0) || (*piVar3 == 10)) {
      if (*piVar3 == 10) {
        uVar1 = QC_adler32(0,0,0);
        iVar2 = QC_adler32(uVar1,param_2,param_3);
        if (piVar3[6] != iVar2) {
          return 0xfffffffd;
        }
      }
      iVar2 = FUN_3008d7fc(param_1,*(undefined4 *)(param_1 + 0x10));
      if (iVar2 == 0) {
        if ((uint)piVar3[10] < param_3) {
          memcpy((void *)piVar3[0xd],(void *)((int)param_2 + (param_3 - piVar3[10])),piVar3[10]);
          piVar3[0xb] = piVar3[10];
        }
        else {
          memcpy((void *)((piVar3[0xd] + piVar3[10]) - param_3),param_2,param_3);
          piVar3[0xb] = param_3;
        }
        piVar3[3] = 1;
        uVar1 = 0;
      }
      else {
        *piVar3 = 0x1c;
        uVar1 = 0xfffffffc;
      }
    }
    else {
      uVar1 = 0xfffffffe;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_inflateGetHeader @ 0x3008F764  (примерный размер ~88 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFE, 0x3008F764
 * ---------------------------------------------------------------- */
undefined4 QC_inflateGetHeader(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else if ((*(uint *)(*(int *)(param_1 + 0x1c) + 8) & 2) == 0) {
    uVar1 = 0xfffffffe;
  }
  else {
    *(int *)(*(int *)(param_1 + 0x1c) + 0x20) = param_2;
    *(undefined4 *)(param_2 + 0x30) = 0;
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3008f7bc @ 0x3008F7BC  (примерный размер ~144 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: QC_inflateSync
 * Константы: 0x3008F7BC
 * ---------------------------------------------------------------- */
uint FUN_3008f7bc(uint *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  
  uVar2 = *param_1;
  uVar1 = 0;
  while ((uVar1 < param_3 && (uVar2 < 4))) {
    if (uVar2 < 2) {
      cVar3 = '\0';
    }
    else {
      cVar3 = -1;
    }
    if (*(char *)(param_2 + uVar1) == cVar3) {
      uVar2 = uVar2 + 1;
    }
    else if (*(char *)(param_2 + uVar1) == '\0') {
      uVar2 = 4 - uVar2;
    }
    else {
      uVar2 = 0;
    }
    uVar1 = uVar1 + 1;
  }
  *param_1 = uVar2;
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_inflateSync @ 0x3008F84C  (примерный размер ~348 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 2
 * Вызывает: FUN_3008f7bc, QC_inflateReset
 * Константы: 0x3008F84C, 0xFFFFFFFE, 0xFFFFFFFB, 0xFFFFFFFD
 * ---------------------------------------------------------------- */
undefined4 QC_inflateSync(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 local_1c [4];
  
  if ((param_1 == (int *)0x0) || (param_1[7] == 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    piVar2 = (int *)param_1[7];
    if ((param_1[1] == 0) && ((uint)piVar2[0xf] < 8)) {
      uVar1 = 0xfffffffb;
    }
    else {
      if (*piVar2 != 0x1d) {
        *piVar2 = 0x1d;
        piVar2[0xe] = piVar2[0xe] << (piVar2[0xf] & 7U);
        piVar2[0xf] = piVar2[0xf] - (piVar2[0xf] & 7U);
        iVar4 = 0;
        while (7 < (uint)piVar2[0xf]) {
          local_1c[iVar4] = (char)piVar2[0xe];
          iVar4 = iVar4 + 1;
          piVar2[0xe] = (uint)piVar2[0xe] >> 8;
          piVar2[0xf] = piVar2[0xf] + -8;
        }
        piVar2[0x1a] = 0;
        FUN_3008f7bc(piVar2 + 0x1a,local_1c,iVar4);
      }
      iVar4 = FUN_3008f7bc(piVar2 + 0x1a,*param_1,param_1[1]);
      param_1[1] = param_1[1] - iVar4;
      *param_1 = *param_1 + iVar4;
      param_1[2] = iVar4 + param_1[2];
      if (piVar2[0x1a] == 4) {
        iVar3 = param_1[2];
        iVar4 = param_1[5];
        QC_inflateReset(param_1);
        param_1[2] = iVar3;
        param_1[5] = iVar4;
        *piVar2 = 0xb;
        uVar1 = 0;
      }
      else {
        uVar1 = 0xfffffffd;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_inflateSyncPoint @ 0x3008F9A8  (примерный размер ~88 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3008F9A8, 0xFFFFFFFE
 * ---------------------------------------------------------------- */
undefined4 QC_inflateSyncPoint(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else if ((**(int **)(param_1 + 0x1c) == 0xd) && ((*(int **)(param_1 + 0x1c))[0xf] == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_inflateCopy @ 0x3008FA00  (примерный размер ~496 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: memcpy
 * Константы: 0xFFFFFFFC, 0x3008FA00, 0xFFFFFFFE
 * Данные: DAT_3008fbe8, DAT_3008fbec
 * ---------------------------------------------------------------- */
undefined4 QC_inflateCopy(void *param_1,void *param_2)

{
  undefined4 uVar1;
  void *__dest;
  void *__dest_00;
  void *__src;
  
  if ((((param_1 == (void *)0x0) || (param_2 == (void *)0x0)) ||
      (*(int *)((int)param_2 + 0x1c) == 0)) ||
     ((*(int *)((int)param_2 + 0x20) == 0 || (*(int *)((int)param_2 + 0x24) == 0)))) {
    uVar1 = 0xfffffffe;
  }
  else {
    __src = *(void **)((int)param_2 + 0x1c);
    __dest = (void *)(**(code **)((int)param_2 + 0x20))
                               (*(undefined4 *)((int)param_2 + 0x28),1,DAT_3008fbe8);
    if (__dest == (void *)0x0) {
      uVar1 = 0xfffffffc;
    }
    else {
      __dest_00 = (void *)0x0;
      if ((*(int *)((int)__src + 0x34) == 0) ||
         (__dest_00 = (void *)(**(code **)((int)param_2 + 0x20))
                                        (*(undefined4 *)((int)param_2 + 0x28),
                                         1 << (*(uint *)((int)__src + 0x24) & 0xff),1),
         __dest_00 != (void *)0x0)) {
        memcpy(param_1,param_2,0x38);
        memcpy(__dest,__src,DAT_3008fbe8);
        if (((int)__src + 0x530U <= *(uint *)((int)__src + 0x4c)) &&
           (*(uint *)((int)__src + 0x4c) <= (uint)((int)__src + DAT_3008fbec))) {
          *(int *)((int)__dest + 0x4c) =
               (int)__dest + (*(int *)((int)__src + 0x4c) - ((int)__src + 0x530) >> 2) * 4 + 0x530;
          *(int *)((int)__dest + 0x50) =
               (int)__dest + (*(int *)((int)__src + 0x50) - ((int)__src + 0x530) >> 2) * 4 + 0x530;
        }
        *(int *)((int)__dest + 0x6c) =
             (int)__dest + (*(int *)((int)__src + 0x6c) - ((int)__src + 0x530) >> 2) * 4 + 0x530;
        if (__dest_00 != (void *)0x0) {
          memcpy(__dest_00,*(void **)((int)__src + 0x34),1 << (*(uint *)((int)__src + 0x24) & 0xff))
          ;
        }
        *(void **)((int)__dest + 0x34) = __dest_00;
        *(void **)((int)param_1 + 0x1c) = __dest;
        uVar1 = 0;
      }
      else {
        (**(code **)((int)param_2 + 0x24))(*(undefined4 *)((int)param_2 + 0x28),__dest);
        uVar1 = 0xfffffffc;
      }
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * QC_inflate_table @ 0x3008FBF0  (примерный размер ~1968 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0xFFFFFFFF, 0x3008FBF0
 * Данные: DAT_30090388, DAT_3009038c, DAT_30090390, DAT_30090394, DAT_30090398, DAT_3009039c
 * ---------------------------------------------------------------- */
undefined4
QC_inflate_table(int param_1,int param_2,uint param_3,int *param_4,uint *param_5,int param_6)

{
  ushort uVar1;
  byte bVar2;
  undefined4 uVar3;
  short *psVar4;
  undefined2 *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  ushort *puVar14;
  undefined2 local_ac;
  short local_aa;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  ushort local_70 [16];
  ushort auStack_50 [16];
  
  for (uVar13 = 0; uVar13 < 0x10; uVar13 = uVar13 + 1) {
    local_70[uVar13] = 0;
  }
  for (uVar13 = 0; uVar13 < param_3; uVar13 = uVar13 + 1) {
    local_70[*(ushort *)(param_2 + uVar13 * 2)] = local_70[*(ushort *)(param_2 + uVar13 * 2)] + 1;
  }
  local_a8 = *param_5;
  for (local_a0 = 0xf; (local_a0 != 0 && (local_70[local_a0] == 0)); local_a0 = local_a0 - 1) {
  }
  if (local_a0 < local_a8) {
    local_a8 = local_a0;
  }
  if (local_a0 == 0) {
    puVar5 = (undefined2 *)*param_4;
    *puVar5 = 0x140;
    puVar5[1] = 0;
    *param_4 = (int)(puVar5 + 2);
    puVar5 = (undefined2 *)*param_4;
    *puVar5 = 0x140;
    puVar5[1] = 0;
    *param_4 = (int)(puVar5 + 2);
    *param_5 = 1;
    uVar3 = 0;
  }
  else {
    for (local_a4 = 1; (local_a4 < 0x10 && (local_70[local_a4] == 0)); local_a4 = local_a4 + 1) {
    }
    if (local_a8 < local_a4) {
      local_a8 = local_a4;
    }
    iVar10 = 1;
    for (uVar13 = 1; uVar13 < 0x10; uVar13 = uVar13 + 1) {
      iVar10 = iVar10 * 2 - (uint)local_70[uVar13];
      if (iVar10 < 0) {
        return 0xffffffff;
      }
    }
    if ((iVar10 < 1) || ((param_1 != 0 && (local_a0 == 1)))) {
      auStack_50[1] = 0;
      for (uVar13 = 1; uVar13 < 0xf; uVar13 = uVar13 + 1) {
        auStack_50[uVar13 + 1] = auStack_50[uVar13] + local_70[uVar13];
      }
      for (uVar13 = 0; uVar13 < param_3; uVar13 = uVar13 + 1) {
        if (*(short *)(param_2 + uVar13 * 2) != 0) {
          uVar1 = auStack_50[*(ushort *)(param_2 + uVar13 * 2)];
          *(short *)(param_6 + (uint)uVar1 * 2) = (short)uVar13;
          auStack_50[*(ushort *)(param_2 + uVar13 * 2)] = uVar1 + 1;
        }
      }
      if (param_1 == 0) {
        local_90 = param_6;
        local_8c = param_6;
        local_88 = 0x13;
      }
      else if (param_1 == 1) {
        local_8c = DAT_30090388 - DAT_3009038c;
        local_90 = DAT_30090390 - DAT_3009038c;
        local_88 = 0x100;
      }
      else {
        local_8c = DAT_30090394;
        local_90 = DAT_30090398;
        local_88 = -1;
      }
      uVar13 = 0;
      iVar10 = 0;
      if (0xf < local_a4) {
        local_a4 = 0xf;
      }
      local_94 = *param_4;
      uVar8 = 0;
      local_98 = 0xffffffff;
      local_9c = 1 << (local_a8 & 0xff);
      uVar6 = local_9c - 1;
      uVar12 = local_a8;
      if ((param_1 == 1) && (0x5af < local_9c)) {
        uVar3 = 1;
      }
      else {
        while( true ) {
          do {
            bVar2 = (char)local_a4 - (char)uVar8;
            if ((int)(uint)*(ushort *)(param_6 + iVar10 * 2) < local_88) {
              local_ac = (ushort)bVar2 << 8;
              local_aa = *(short *)(param_6 + iVar10 * 2);
            }
            else if (local_88 < (int)(uint)*(ushort *)(param_6 + iVar10 * 2)) {
              local_ac = CONCAT11(bVar2,(char)*(undefined2 *)
                                               (local_90 +
                                               (uint)*(ushort *)(param_6 + iVar10 * 2) * 2));
              local_aa = *(short *)(local_8c + (uint)*(ushort *)(param_6 + iVar10 * 2) * 2);
            }
            else {
              local_ac = CONCAT11(bVar2,0x60);
              local_aa = 0;
            }
            iVar11 = 1 << (uVar12 & 0xff);
            iVar7 = iVar11;
            do {
              iVar7 = iVar7 - (1 << (local_a4 - uVar8 & 0xff));
              psVar4 = (short *)(local_94 + (iVar7 + (uVar13 >> (uVar8 & 0xff))) * 4);
              *psVar4 = local_ac;
              psVar4[1] = local_aa;
            } while (iVar7 != 0);
            for (uVar9 = 1 << (local_a4 - 1 & 0xff); (uVar13 & uVar9) != 0; uVar9 = uVar9 >> 1) {
            }
            if (uVar9 == 0) {
              uVar13 = 0;
            }
            else {
              uVar13 = (uVar13 & uVar9 - 1) + uVar9;
            }
            iVar10 = iVar10 + 1;
            puVar14 = local_70 + local_a4;
            *puVar14 = *puVar14 + (short)DAT_3009039c;
            if (*puVar14 == 0) {
              if (local_a4 == local_a0) {
                local_ac = CONCAT11((char)local_a4 - (char)uVar8,0x40);
                goto LAB_300902b4;
              }
              local_a4 = (uint)*(ushort *)(param_2 + (uint)*(ushort *)(param_6 + iVar10 * 2) * 2);
            }
          } while ((local_a4 <= local_a8) || ((uVar13 & uVar6) == local_98));
          if (uVar8 == 0) {
            uVar8 = local_a8;
          }
          local_94 = local_94 + iVar11 * 4;
          uVar12 = local_a4 - uVar8;
          for (iVar11 = 1 << (uVar12 & 0xff);
              (uVar12 + uVar8 < local_a0 &&
              (iVar7 = uVar12 + uVar8, 0 < (int)(iVar11 - (uint)local_70[iVar7])));
              iVar11 = (iVar11 - (uint)local_70[iVar7]) * 2) {
            uVar12 = uVar12 + 1;
          }
          local_9c = local_9c + (1 << (uVar12 & 0xff));
          if ((param_1 == 1) && (0x5af < local_9c)) break;
          local_98 = uVar13 & uVar6;
          *(char *)(*param_4 + local_98 * 4) = (char)uVar12;
          *(char *)(*param_4 + local_98 * 4 + 1) = (char)local_a8;
          *(short *)(*param_4 + local_98 * 4 + 2) = (short)(local_94 - *param_4 >> 2);
        }
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
LAB_300902b4:
  if (uVar13 == 0) {
LAB_3009034c:
    *param_4 = *param_4 + local_9c * 4;
    *param_5 = local_a8;
    return 0;
  }
  if ((uVar8 != 0) && ((uVar13 & uVar6) != local_98)) {
    uVar8 = 0;
    local_94 = *param_4;
    local_ac = CONCAT11((char)local_a8,(undefined1)local_ac);
    local_a4 = local_a8;
  }
  puVar5 = (undefined2 *)(local_94 + (uVar13 >> (uVar8 & 0xff)) * 4);
  *puVar5 = local_ac;
  puVar5[1] = 0;
  for (uVar12 = 1 << (local_a4 - 1 & 0xff); (uVar13 & uVar12) != 0; uVar12 = uVar12 >> 1) {
  }
  if (uVar12 == 0) goto LAB_3009034c;
  uVar13 = (uVar13 & uVar12 - 1) + uVar12;
  goto LAB_300902b4;
}

/* ----------------------------------------------------------------
 * FUN_300903a0 @ 0x300903A0  (примерный размер ~228 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: QC_tr_flush_block, QC_tr_init
 * Константы: 0x300903A0
 * Данные: DAT_30091340, DAT_30091344, DAT_30091348, DAT_3009134c, DAT_30091350, DAT_30091354, DAT_30091358, DAT_3009135c
 * ---------------------------------------------------------------- */
void FUN_300903a0(int param_1)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < DAT_30091340; iVar1 = iVar1 + 1) {
    *(undefined2 *)(param_1 + iVar1 * 4 + 0x94) = 0;
  }
  for (iVar1 = 0; iVar1 < 0x1e; iVar1 = iVar1 + 1) {
    *(undefined2 *)(param_1 + iVar1 * 4 + DAT_30091344) = 0;
  }
  for (iVar1 = 0; iVar1 < 0x13; iVar1 = iVar1 + 1) {
    *(undefined2 *)(param_1 + iVar1 * 4 + DAT_30091348) = 0;
  }
  *(undefined2 *)(param_1 + DAT_3009134c) = 1;
  *(undefined4 *)(param_1 + DAT_30091350) = 0;
  *(undefined4 *)(param_1 + DAT_30091354) = 0;
  *(undefined4 *)(param_1 + DAT_30091358) = 0;
  *(undefined4 *)(param_1 + DAT_3009135c) = 0;
  return;
}

/* ----------------------------------------------------------------
 * QC_tr_init @ 0x30090484  (примерный размер ~132 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_300903a0, FUN_30093648
 * Вызывают: QC_deflateReset
 * Константы: 0x30090484
 * Данные: DAT_30091344, DAT_30091348, DAT_30091458, DAT_3009145c, DAT_30091460, DAT_30091464, DAT_30091468, DAT_3009146c
 * ---------------------------------------------------------------- */
void QC_tr_init(int param_1)

{
  FUN_30093648();
  *(int *)(param_1 + 0xb18) = param_1 + 0x94;
  *(undefined4 *)(param_1 + 0xb20) = DAT_30091458;
  *(int *)(param_1 + 0xb24) = param_1 + DAT_30091344;
  *(undefined4 *)(param_1 + 0xb2c) = DAT_3009145c;
  *(int *)(param_1 + 0xb30) = param_1 + DAT_30091348;
  *(undefined4 *)(param_1 + 0xb38) = DAT_30091460;
  *(undefined2 *)(param_1 + DAT_30091464) = 0;
  *(undefined4 *)(param_1 + DAT_30091468) = 0;
  *(undefined4 *)(param_1 + DAT_3009146c) = 8;
  FUN_300903a0(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30090508 @ 0x30090508  (примерный размер ~400 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30090b10
 * Константы: 0x30090508
 * Данные: DAT_30091470, DAT_30091474
 * ---------------------------------------------------------------- */
void FUN_30090508(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + param_3 * 4 + 0xb5c);
  iVar1 = param_3 << 1;
  while (iVar1 <= *(int *)(param_1 + DAT_30091470)) {
    iVar2 = iVar1;
    if ((iVar1 < *(int *)(param_1 + DAT_30091470)) &&
       ((*(ushort *)(param_2 + *(int *)(param_1 + iVar1 * 4 + 0xb60) * 4) <
         *(ushort *)(param_2 + *(int *)(param_1 + iVar1 * 4 + 0xb5c) * 4) ||
        ((*(short *)(param_2 + *(int *)(param_1 + iVar1 * 4 + 0xb60) * 4) ==
          *(short *)(param_2 + *(int *)(param_1 + iVar1 * 4 + 0xb5c) * 4) &&
         (*(byte *)(param_1 + *(int *)(param_1 + iVar1 * 4 + 0xb60) + DAT_30091474) <=
          *(byte *)(param_1 + *(int *)(param_1 + iVar1 * 4 + 0xb5c) + DAT_30091474))))))) {
      iVar2 = iVar1 + 1;
    }
    if ((*(ushort *)(param_2 + iVar3 * 4) <
         *(ushort *)(param_2 + *(int *)(param_1 + iVar2 * 4 + 0xb5c) * 4)) ||
       ((*(short *)(param_2 + iVar3 * 4) ==
         *(short *)(param_2 + *(int *)(param_1 + iVar2 * 4 + 0xb5c) * 4) &&
        (*(byte *)(param_1 + iVar3 + DAT_30091474) <=
         *(byte *)(param_1 + *(int *)(param_1 + iVar2 * 4 + 0xb5c) + DAT_30091474))))) break;
    *(undefined4 *)(param_1 + param_3 * 4 + 0xb5c) = *(undefined4 *)(param_1 + iVar2 * 4 + 0xb5c);
    param_3 = iVar2;
    iVar1 = iVar2 << 1;
  }
  *(int *)(param_1 + param_3 * 4 + 0xb5c) = iVar3;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30090698 @ 0x30090698  (примерный размер ~888 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30090b10
 * Константы: 0x30090698
 * Данные: DAT_30091350, DAT_30091354, DAT_300916bc, DAT_300916c0, DAT_300916c4, DAT_30091830, DAT_30091834
 * ---------------------------------------------------------------- */
void FUN_30090698(int param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int local_48;
  int local_44;
  
  iVar5 = *param_2;
  iVar4 = param_2[1];
  iVar10 = *(int *)param_2[2];
  iVar2 = *(int *)(param_2[2] + 4);
  iVar11 = *(int *)(param_2[2] + 8);
  uVar9 = *(uint *)(param_2[2] + 0x10);
  local_48 = 0;
  for (iVar6 = 0; iVar6 < 0x10; iVar6 = iVar6 + 1) {
    *(undefined2 *)(param_1 + iVar6 * 2 + DAT_300916bc) = 0;
  }
  *(undefined2 *)(iVar5 + *(int *)(param_1 + *(int *)(param_1 + DAT_300916c0) * 4 + 0xb5c) * 4 + 2)
       = 0;
  iVar6 = *(int *)(param_1 + DAT_300916c0);
  while (iVar6 = iVar6 + 1, iVar6 < DAT_300916c4) {
    iVar8 = *(int *)(param_1 + iVar6 * 4 + 0xb5c);
    uVar7 = *(ushort *)(iVar5 + (uint)*(ushort *)(iVar5 + iVar8 * 4 + 2) * 4 + 2) + 1;
    if ((int)uVar9 < (int)uVar7) {
      local_48 = local_48 + 1;
      uVar7 = uVar9;
    }
    *(short *)(iVar5 + iVar8 * 4 + 2) = (short)uVar7;
    if (iVar8 <= iVar4) {
      psVar3 = (short *)(param_1 + uVar7 * 2 + DAT_300916bc);
      *psVar3 = *psVar3 + 1;
      local_44 = 0;
      if (iVar11 <= iVar8) {
        local_44 = *(int *)(iVar2 + (iVar8 - iVar11) * 4);
      }
      uVar1 = *(ushort *)(iVar5 + iVar8 * 4);
      *(uint *)(param_1 + DAT_30091354) =
           (uint)uVar1 * (uVar7 + local_44) + *(int *)(param_1 + DAT_30091354);
      if (iVar10 != 0) {
        *(uint *)(param_1 + DAT_30091350) =
             (uint)uVar1 * (local_44 + (uint)*(ushort *)(iVar10 + iVar8 * 4 + 2)) +
             *(int *)(param_1 + DAT_30091350);
      }
    }
  }
  uVar7 = uVar9;
  if (local_48 != 0) {
    do {
      do {
        uVar7 = uVar7 - 1;
      } while (*(short *)(param_1 + uVar7 * 2 + DAT_300916bc) == 0);
      psVar3 = (short *)(param_1 + uVar7 * 2 + DAT_300916bc);
      *psVar3 = *psVar3 + (short)DAT_30091830;
      psVar3 = (short *)(param_1 + uVar7 * 2 + DAT_30091834);
      *psVar3 = *psVar3 + 2;
      psVar3 = (short *)(param_1 + uVar9 * 2 + DAT_300916bc);
      *psVar3 = *psVar3 + (short)DAT_30091830;
      local_48 = local_48 + -2;
      uVar7 = uVar9;
    } while (0 < local_48);
    for (; uVar9 != 0; uVar9 = uVar9 - 1) {
      uVar7 = (uint)*(ushort *)(param_1 + uVar9 * 2 + DAT_300916bc);
      while (uVar7 != 0) {
        iVar6 = iVar6 + -1;
        iVar2 = *(int *)(param_1 + iVar6 * 4 + 0xb5c);
        if (iVar2 <= iVar4) {
          if (*(ushort *)(iVar5 + iVar2 * 4 + 2) != uVar9) {
            *(uint *)(param_1 + DAT_30091354) =
                 (uVar9 - *(ushort *)(iVar5 + iVar2 * 4 + 2)) * (uint)*(ushort *)(iVar5 + iVar2 * 4)
                 + *(int *)(param_1 + DAT_30091354);
            *(short *)(iVar5 + iVar2 * 4 + 2) = (short)uVar9;
          }
          uVar7 = uVar7 - 1;
        }
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30090a10 @ 0x30090A10  (примерный размер ~256 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30090b10
 * Константы: 0x30090A10, 0x7FFFFFFF
 * ---------------------------------------------------------------- */
uint FUN_30090a10(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    uVar3 = param_1 & 1;
    param_1 = param_1 >> 1;
    param_2 = param_2 + -1;
    uVar1 = (uVar2 | uVar3) << 1;
  } while (0 < param_2);
  return uVar2 & 0x7fffffff | uVar3;
}

/* ----------------------------------------------------------------
 * FUN_30090b10 @ 0x30090B10  (примерный размер ~916 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 3
 * Вызывает: FUN_30090508, FUN_30090698, FUN_30090a10
 * Вызывают: FUN_30091b34, QC_tr_flush_block
 * Константы: 0x30090B10
 * Данные: DAT_30091350, DAT_30091354, DAT_30091470, DAT_30091474, DAT_300916bc, DAT_300916c0, DAT_300916c4
 * ---------------------------------------------------------------- */
void FUN_30090b10(int param_1,int *param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  short asStack_48 [10];
  int local_34;
  int local_30;
  int local_2c;
  
  iVar5 = *param_2;
  local_30 = *(int *)param_2[2];
  local_2c = *(int *)(param_2[2] + 0xc);
  iVar3 = -1;
  *(undefined4 *)(param_1 + DAT_30091470) = 0;
  *(undefined4 *)(param_1 + DAT_300916c0) = DAT_300916c4;
  for (iVar8 = 0; iVar8 < local_2c; iVar8 = iVar8 + 1) {
    if (*(short *)(iVar5 + iVar8 * 4) == 0) {
      *(undefined2 *)(iVar5 + iVar8 * 4 + 2) = 0;
    }
    else {
      *(int *)(param_1 + DAT_30091470) = *(int *)(param_1 + DAT_30091470) + 1;
      *(int *)(param_1 + *(int *)(param_1 + DAT_30091470) * 4 + 0xb5c) = iVar8;
      *(undefined1 *)(param_1 + iVar8 + DAT_30091474) = 0;
      iVar3 = iVar8;
    }
  }
  while (*(int *)(param_1 + DAT_30091470) < 2) {
    if (iVar3 < 2) {
      iVar3 = iVar3 + 1;
      iVar8 = iVar3;
    }
    else {
      iVar8 = 0;
    }
    *(int *)(param_1 + DAT_30091470) = *(int *)(param_1 + DAT_30091470) + 1;
    *(int *)(param_1 + *(int *)(param_1 + DAT_30091470) * 4 + 0xb5c) = iVar8;
    iVar8 = *(int *)(param_1 + *(int *)(param_1 + DAT_30091470) * 4 + 0xb5c);
    *(undefined2 *)(iVar5 + iVar8 * 4) = 1;
    *(undefined1 *)(param_1 + iVar8 + DAT_30091474) = 0;
    *(int *)(param_1 + DAT_30091354) = *(int *)(param_1 + DAT_30091354) + -1;
    if (local_30 != 0) {
      *(uint *)(param_1 + DAT_30091350) =
           *(int *)(param_1 + DAT_30091350) - (uint)*(ushort *)(local_30 + iVar8 * 4 + 2);
    }
  }
  param_2[1] = iVar3;
  for (iVar8 = *(int *)(param_1 + DAT_30091470) / 2; iVar6 = local_2c, 0 < iVar8; iVar8 = iVar8 + -1
      ) {
    FUN_30090508(param_1,iVar5,iVar8);
  }
  do {
    iVar9 = *(int *)(param_1 + 0xb60);
    local_34 = *(int *)(param_1 + DAT_30091470);
    *(undefined4 *)(param_1 + 0xb60) = *(undefined4 *)(param_1 + local_34 * 4 + 0xb5c);
    *(int *)(param_1 + DAT_30091470) = local_34 + -1;
    FUN_30090508(param_1,iVar5,1);
    iVar8 = *(int *)(param_1 + 0xb60);
    *(int *)(param_1 + DAT_300916c0) = *(int *)(param_1 + DAT_300916c0) + -1;
    *(int *)(param_1 + *(int *)(param_1 + DAT_300916c0) * 4 + 0xb5c) = iVar9;
    *(int *)(param_1 + DAT_300916c0) = *(int *)(param_1 + DAT_300916c0) + -1;
    *(int *)(param_1 + *(int *)(param_1 + DAT_300916c0) * 4 + 0xb5c) = iVar8;
    *(short *)(iVar5 + iVar6 * 4) = *(short *)(iVar5 + iVar9 * 4) + *(short *)(iVar5 + iVar8 * 4);
    if (*(byte *)(param_1 + iVar9 + DAT_30091474) < *(byte *)(param_1 + iVar8 + DAT_30091474)) {
      cVar1 = *(char *)(param_1 + iVar8 + DAT_30091474);
    }
    else {
      cVar1 = *(char *)(param_1 + iVar9 + DAT_30091474);
    }
    *(char *)(param_1 + iVar6 + DAT_30091474) = cVar1 + '\x01';
    *(short *)(iVar5 + iVar8 * 4 + 2) = (short)iVar6;
    *(undefined2 *)(iVar5 + iVar9 * 4 + 2) = *(undefined2 *)(iVar5 + iVar8 * 4 + 2);
    *(int *)(param_1 + 0xb60) = iVar6;
    FUN_30090508(param_1,iVar5,1);
    iVar6 = iVar6 + 1;
  } while (1 < *(int *)(param_1 + DAT_30091470));
  *(int *)(param_1 + DAT_300916c0) = *(int *)(param_1 + DAT_300916c0) + -1;
  *(undefined4 *)(param_1 + *(int *)(param_1 + DAT_300916c0) * 4 + 0xb5c) =
       *(undefined4 *)(param_1 + 0xb60);
  FUN_30090698(param_1,param_2);
  sVar4 = 0;
  for (iVar8 = 1; iVar8 < 0x10; iVar8 = iVar8 + 1) {
    sVar4 = (sVar4 + *(short *)(param_1 + DAT_300916bc + iVar8 * 2 + -2)) * 2;
    asStack_48[iVar8] = sVar4;
  }
  for (iVar8 = 0; iVar8 <= iVar3; iVar8 = iVar8 + 1) {
    uVar7 = (uint)*(ushort *)(iVar5 + iVar8 * 4 + 2);
    if (uVar7 != 0) {
      psVar10 = asStack_48 + uVar7;
      sVar4 = *psVar10;
      *psVar10 = *psVar10 + 1;
      uVar2 = FUN_30090a10(sVar4,uVar7);
      *(undefined2 *)(iVar5 + iVar8 * 4) = uVar2;
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30090ea4 @ 0x30090EA4  (примерный размер ~444 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30091b34
 * Константы: 0x30090EA4, 0xFFFFFFFF
 * Данные: DAT_30091348, DAT_30091830, DAT_30091f08, DAT_30091f0c
 * ---------------------------------------------------------------- */
void FUN_30090ea4(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_2c;
  
  local_2c = 0xffffffff;
  uVar1 = *(ushort *)(param_2 + 2);
  iVar8 = 0;
  iVar2 = 7;
  iVar5 = 4;
  if (uVar1 == 0) {
    iVar2 = 0x8a;
    iVar5 = 3;
  }
  *(short *)(param_2 + param_3 * 4 + 6) = (short)DAT_30091830;
  uVar6 = (uint)uVar1;
  for (iVar3 = 0; iVar3 <= param_3; iVar3 = iVar3 + 1) {
    uVar7 = (uint)*(ushort *)(param_2 + iVar3 * 4 + 6);
    iVar8 = iVar8 + 1;
    if ((iVar2 <= iVar8) || (uVar6 != uVar7)) {
      if (iVar8 < iVar5) {
        psVar4 = (short *)(param_1 + uVar6 * 4 + DAT_30091348);
        *psVar4 = *psVar4 + (short)iVar8;
      }
      else if (uVar6 == 0) {
        if (iVar8 < 0xb) {
          *(short *)(param_1 + 0xac0) = *(short *)(param_1 + 0xac0) + 1;
        }
        else {
          *(short *)(param_1 + DAT_30091f0c) = *(short *)(param_1 + DAT_30091f0c) + 1;
        }
      }
      else {
        if (uVar6 != local_2c) {
          psVar4 = (short *)(param_1 + uVar6 * 4 + DAT_30091348);
          *psVar4 = *psVar4 + 1;
        }
        *(short *)(param_1 + DAT_30091f08) = *(short *)(param_1 + DAT_30091f08) + 1;
      }
      iVar8 = 0;
      local_2c = uVar6;
      if (uVar7 == 0) {
        iVar2 = 0x8a;
        iVar5 = 3;
      }
      else if (uVar6 == uVar7) {
        iVar2 = 6;
        iVar5 = 3;
      }
      else {
        iVar2 = 7;
        iVar5 = 4;
      }
    }
    uVar6 = uVar7;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30091060 @ 0x30091060  (примерный размер ~2772 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30091bcc
 * Константы: 0x30091060, 0xFFFFFFFF
 * Данные: DAT_30091348, DAT_30091464, DAT_30091468, DAT_30091f08, DAT_30091f0c, DAT_30092028, DAT_300922f0, DAT_300922f4
 * ---------------------------------------------------------------- */
void FUN_30091060(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_48;
  
  local_48 = 0xffffffff;
  local_a8 = 7;
  local_a4 = 4;
  if (*(ushort *)(param_2 + 2) == 0) {
    local_a8 = 0x8a;
    local_a4 = 3;
  }
  iVar7 = 0;
  uVar4 = (uint)*(ushort *)(param_2 + 2);
  for (local_a0 = 0; local_a0 <= param_3; local_a0 = local_a0 + 1) {
    uVar5 = (uint)*(ushort *)(param_2 + local_a0 * 4 + 6);
    iVar3 = iVar7 + 1;
    if ((local_a8 <= iVar3) || (uVar4 != uVar5)) {
      if (iVar3 < local_a4) {
        do {
          uVar6 = (uint)*(ushort *)(param_1 + uVar4 * 4 + DAT_30092028);
          if ((int)(0x10 - uVar6) < *(int *)(param_1 + DAT_30091468)) {
            uVar1 = *(ushort *)(param_1 + uVar4 * 4 + DAT_30091348);
            *(ushort *)(param_1 + DAT_30091464) =
                 *(ushort *)(param_1 + DAT_30091464) |
                 uVar1 << (*(uint *)(param_1 + DAT_30091468) & 0xff);
            iVar7 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar7) = (char)*(undefined2 *)(param_1 + DAT_30091464)
            ;
            *(int *)(param_1 + 0x14) = iVar7 + 1;
            iVar7 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar7) =
                 (char)((ushort)*(undefined2 *)(param_1 + DAT_30091464) >> 8);
            *(int *)(param_1 + 0x14) = iVar7 + 1;
            *(ushort *)(param_1 + DAT_30091464) =
                 uVar1 >> (0x10U - *(int *)(param_1 + DAT_30091468) & 0xff);
            *(uint *)(param_1 + DAT_30091468) = uVar6 + *(int *)(param_1 + DAT_30091468) + -0x10;
          }
          else {
            *(ushort *)(param_1 + DAT_30091464) =
                 *(ushort *)(param_1 + DAT_30091464) |
                 *(short *)(param_1 + uVar4 * 4 + DAT_30091348) <<
                 (*(uint *)(param_1 + DAT_30091468) & 0xff);
            *(uint *)(param_1 + DAT_30091468) = uVar6 + *(int *)(param_1 + DAT_30091468);
          }
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      else if (uVar4 == 0) {
        if (iVar3 < 0xb) {
          uVar6 = (uint)*(ushort *)(param_1 + DAT_3009255c);
          if ((int)(0x10 - uVar6) < *(int *)(param_1 + DAT_30092410)) {
            uVar1 = *(ushort *)(param_1 + 0xac0);
            *(ushort *)(param_1 + DAT_30092414) =
                 *(ushort *)(param_1 + DAT_30092414) |
                 uVar1 << (*(uint *)(param_1 + DAT_30092410) & 0xff);
            iVar2 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar2) = (char)*(undefined2 *)(param_1 + DAT_30092414)
            ;
            *(int *)(param_1 + 0x14) = iVar2 + 1;
            iVar2 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar2) =
                 (char)((ushort)*(undefined2 *)(param_1 + DAT_30092414) >> 8);
            *(int *)(param_1 + 0x14) = iVar2 + 1;
            *(ushort *)(param_1 + DAT_30092414) =
                 uVar1 >> (0x10U - *(int *)(param_1 + DAT_30092410) & 0xff);
            *(uint *)(param_1 + DAT_30092410) = uVar6 + *(int *)(param_1 + DAT_30092410) + -0x10;
          }
          else {
            *(ushort *)(param_1 + DAT_30092414) =
                 *(ushort *)(param_1 + DAT_30092414) |
                 *(short *)(param_1 + 0xac0) << (*(uint *)(param_1 + DAT_30092410) & 0xff);
            *(uint *)(param_1 + DAT_30092410) = uVar6 + *(int *)(param_1 + DAT_30092410);
          }
          if (*(int *)(param_1 + DAT_30092410) < 0xe) {
            *(ushort *)(param_1 + DAT_30092414) =
                 *(ushort *)(param_1 + DAT_30092414) |
                 (ushort)(iVar3 + DAT_30092558 << (*(uint *)(param_1 + DAT_30092410) & 0xff));
            *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + 3;
          }
          else {
            *(ushort *)(param_1 + DAT_30092414) =
                 *(ushort *)(param_1 + DAT_30092414) |
                 (ushort)(iVar7 - 2U << (*(uint *)(param_1 + DAT_30092410) & 0xff));
            iVar3 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)*(undefined2 *)(param_1 + DAT_30092414)
            ;
            *(int *)(param_1 + 0x14) = iVar3 + 1;
            iVar3 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar3) =
                 (char)((ushort)*(undefined2 *)(param_1 + DAT_30092414) >> 8);
            *(int *)(param_1 + 0x14) = iVar3 + 1;
            *(short *)(param_1 + DAT_30092414) =
                 (short)((iVar7 - 2U & 0xffff) >> (0x10U - *(int *)(param_1 + DAT_30092410) & 0xff))
            ;
            *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + -0xd;
          }
        }
        else {
          uVar6 = (uint)*(ushort *)(param_1 + DAT_300927a0);
          if ((int)(0x10 - uVar6) < *(int *)(param_1 + DAT_30092410)) {
            uVar1 = *(ushort *)(param_1 + DAT_30091f0c);
            *(ushort *)(param_1 + DAT_30092414) =
                 *(ushort *)(param_1 + DAT_30092414) |
                 uVar1 << (*(uint *)(param_1 + DAT_30092410) & 0xff);
            iVar2 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar2) = (char)*(undefined2 *)(param_1 + DAT_30092414)
            ;
            *(int *)(param_1 + 0x14) = iVar2 + 1;
            iVar2 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar2) =
                 (char)((ushort)*(undefined2 *)(param_1 + DAT_30092414) >> 8);
            *(int *)(param_1 + 0x14) = iVar2 + 1;
            *(ushort *)(param_1 + DAT_30092414) =
                 uVar1 >> (0x10U - *(int *)(param_1 + DAT_30092410) & 0xff);
            *(uint *)(param_1 + DAT_30092410) = uVar6 + *(int *)(param_1 + DAT_30092410) + -0x10;
          }
          else {
            *(ushort *)(param_1 + DAT_30092414) =
                 *(ushort *)(param_1 + DAT_30092414) |
                 *(short *)(param_1 + DAT_30091f0c) << (*(uint *)(param_1 + DAT_30092410) & 0xff);
            *(uint *)(param_1 + DAT_30092410) = uVar6 + *(int *)(param_1 + DAT_30092410);
          }
          if (*(int *)(param_1 + DAT_30092410) < 10) {
            *(ushort *)(param_1 + DAT_30092414) =
                 *(ushort *)(param_1 + DAT_30092414) |
                 (ushort)(iVar3 + DAT_30092a14 << (*(uint *)(param_1 + DAT_30092410) & 0xff));
            *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + 7;
          }
          else {
            *(ushort *)(param_1 + DAT_30092414) =
                 *(ushort *)(param_1 + DAT_30092414) |
                 (ushort)(iVar7 - 10U << (*(uint *)(param_1 + DAT_30092410) & 0xff));
            iVar3 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)*(undefined2 *)(param_1 + DAT_30092414)
            ;
            *(int *)(param_1 + 0x14) = iVar3 + 1;
            iVar3 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar3) =
                 (char)((ushort)*(undefined2 *)(param_1 + DAT_30092414) >> 8);
            *(int *)(param_1 + 0x14) = iVar3 + 1;
            *(short *)(param_1 + DAT_30092414) =
                 (short)((iVar7 - 10U & 0xffff) >> (0x10U - *(int *)(param_1 + DAT_30092410) & 0xff)
                        );
            *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + -9;
          }
        }
      }
      else {
        if (uVar4 != local_48) {
          uVar6 = (uint)*(ushort *)(param_1 + uVar4 * 4 + DAT_30092028);
          iVar3 = iVar7;
          if ((int)(0x10 - uVar6) < *(int *)(param_1 + DAT_30091468)) {
            uVar1 = *(ushort *)(param_1 + uVar4 * 4 + DAT_30091348);
            *(ushort *)(param_1 + DAT_30091464) =
                 *(ushort *)(param_1 + DAT_30091464) |
                 uVar1 << (*(uint *)(param_1 + DAT_30091468) & 0xff);
            iVar7 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar7) = (char)*(undefined2 *)(param_1 + DAT_30091464)
            ;
            *(int *)(param_1 + 0x14) = iVar7 + 1;
            iVar7 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar7) =
                 (char)((ushort)*(undefined2 *)(param_1 + DAT_30091464) >> 8);
            *(int *)(param_1 + 0x14) = iVar7 + 1;
            *(ushort *)(param_1 + DAT_30091464) =
                 uVar1 >> (0x10U - *(int *)(param_1 + DAT_30091468) & 0xff);
            *(uint *)(param_1 + DAT_30091468) = uVar6 + *(int *)(param_1 + DAT_30091468) + -0x10;
          }
          else {
            *(ushort *)(param_1 + DAT_30091464) =
                 *(ushort *)(param_1 + DAT_30091464) |
                 *(short *)(param_1 + uVar4 * 4 + DAT_300922f0) <<
                 (*(uint *)(param_1 + DAT_30091468) & 0xff);
            *(uint *)(param_1 + DAT_30091468) = uVar6 + *(int *)(param_1 + DAT_30091468);
          }
        }
        uVar6 = (uint)*(ushort *)(param_1 + DAT_300922f4);
        if ((int)(0x10 - uVar6) < *(int *)(param_1 + DAT_30091468)) {
          uVar1 = *(ushort *)(param_1 + DAT_30091f08);
          *(ushort *)(param_1 + DAT_30091464) =
               *(ushort *)(param_1 + DAT_30091464) |
               uVar1 << (*(uint *)(param_1 + DAT_30091468) & 0xff);
          iVar7 = *(int *)(param_1 + 0x14);
          *(char *)(*(int *)(param_1 + 8) + iVar7) = (char)*(undefined2 *)(param_1 + DAT_30091464);
          *(int *)(param_1 + 0x14) = iVar7 + 1;
          iVar7 = *(int *)(param_1 + 0x14);
          *(char *)(*(int *)(param_1 + 8) + iVar7) =
               (char)((ushort)*(undefined2 *)(param_1 + DAT_30091464) >> 8);
          *(int *)(param_1 + 0x14) = iVar7 + 1;
          *(ushort *)(param_1 + DAT_30092414) =
               uVar1 >> (0x10U - *(int *)(param_1 + DAT_30092410) & 0xff);
          *(uint *)(param_1 + DAT_30092410) = uVar6 + *(int *)(param_1 + DAT_30092410) + -0x10;
        }
        else {
          *(ushort *)(param_1 + DAT_30092414) =
               *(ushort *)(param_1 + DAT_30092414) |
               *(short *)(param_1 + DAT_30091f08) << (*(uint *)(param_1 + DAT_30092410) & 0xff);
          *(uint *)(param_1 + DAT_30092410) = uVar6 + *(int *)(param_1 + DAT_30092410);
        }
        if (*(int *)(param_1 + DAT_30092410) < 0xf) {
          *(ushort *)(param_1 + DAT_30092414) =
               *(ushort *)(param_1 + DAT_30092414) |
               (ushort)(iVar3 + DAT_30092558 << (*(uint *)(param_1 + DAT_30092410) & 0xff));
          *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + 2;
        }
        else {
          *(ushort *)(param_1 + DAT_30092414) =
               *(ushort *)(param_1 + DAT_30092414) |
               (ushort)(iVar3 - 3U << (*(uint *)(param_1 + DAT_30092410) & 0xff));
          iVar7 = *(int *)(param_1 + 0x14);
          *(char *)(*(int *)(param_1 + 8) + iVar7) = (char)*(undefined2 *)(param_1 + DAT_30092414);
          *(int *)(param_1 + 0x14) = iVar7 + 1;
          iVar7 = *(int *)(param_1 + 0x14);
          *(char *)(*(int *)(param_1 + 8) + iVar7) =
               (char)((ushort)*(undefined2 *)(param_1 + DAT_30092414) >> 8);
          *(int *)(param_1 + 0x14) = iVar7 + 1;
          *(short *)(param_1 + DAT_30092414) =
               (short)((iVar3 - 3U & 0xffff) >> (0x10U - *(int *)(param_1 + DAT_30092410) & 0xff));
          *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + -0xe;
        }
      }
      iVar3 = 0;
      local_48 = uVar4;
      if (uVar5 == 0) {
        local_a8 = 0x8a;
        local_a4 = 3;
      }
      else if (uVar4 == uVar5) {
        local_a8 = 6;
        local_a4 = 3;
      }
      else {
        local_a8 = 7;
        local_a4 = 4;
      }
    }
    iVar7 = iVar3;
    uVar4 = uVar5;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30091b34 @ 0x30091B34  (примерный размер ~152 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 2
 * Вызывает: FUN_30090b10, FUN_30090ea4
 * Вызывают: QC_tr_flush_block
 * Константы: 0x30091B34
 * Данные: DAT_30092028, DAT_30092a18, DAT_30092a1c, DAT_30092b1c
 * ---------------------------------------------------------------- */
int FUN_30091b34(int param_1)

{
  int iVar1;
  
  FUN_30090ea4(param_1,param_1 + 0x94,*(undefined4 *)(param_1 + 0xb1c));
  FUN_30090ea4(param_1,param_1 + DAT_30092a18,*(undefined4 *)(param_1 + 0xb28));
  FUN_30090b10(param_1,param_1 + 0xb30);
  iVar1 = 0x12;
  while ((2 < iVar1 &&
         (*(short *)(param_1 + (uint)*(byte *)(DAT_30092a1c + iVar1) * 4 + DAT_30092028) == 0))) {
    iVar1 = iVar1 + -1;
  }
  *(int *)(param_1 + DAT_30092b1c) = *(int *)(param_1 + DAT_30092b1c) + iVar1 * 3 + 0x11;
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30091bcc @ 0x30091BCC  (примерный размер ~1260 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30091060
 * Вызывают: QC_tr_flush_block
 * Константы: 0x30091BCC
 * Данные: DAT_30092028, DAT_30092410, DAT_30092414, DAT_30092a18, DAT_30092a1c, DAT_30092b20, DAT_30092c48, DAT_30092d30
 * ---------------------------------------------------------------- */
void FUN_30091bcc(int param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + DAT_30092410) < 0xc) {
    *(ushort *)(param_1 + DAT_30092414) =
         *(ushort *)(param_1 + DAT_30092414) |
         (ushort)(param_2 + DAT_30092c48 << (*(uint *)(param_1 + DAT_30092410) & 0xff));
    *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + 5;
  }
  else {
    uVar3 = param_2 - DAT_30092b20;
    *(ushort *)(param_1 + DAT_30092414) =
         *(ushort *)(param_1 + DAT_30092414) |
         (ushort)(uVar3 << (*(uint *)(param_1 + DAT_30092410) & 0xff));
    iVar4 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar4) = (char)*(undefined2 *)(param_1 + DAT_30092414);
    *(int *)(param_1 + 0x14) = iVar4 + 1;
    iVar4 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar4) =
         (char)((ushort)*(undefined2 *)(param_1 + DAT_30092414) >> 8);
    *(int *)(param_1 + 0x14) = iVar4 + 1;
    *(short *)(param_1 + DAT_30092414) =
         (short)((uVar3 & 0xffff) >> (0x10U - *(int *)(param_1 + DAT_30092410) & 0xff));
    *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + -0xb;
  }
  if (*(int *)(param_1 + DAT_30092410) < 0xc) {
    *(ushort *)(param_1 + DAT_30092414) =
         *(ushort *)(param_1 + DAT_30092414) |
         (ushort)(param_3 + DAT_30092d30 << (*(uint *)(param_1 + DAT_30092410) & 0xff));
    *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + 5;
  }
  else {
    *(ushort *)(param_1 + DAT_30092414) =
         *(ushort *)(param_1 + DAT_30092414) |
         (ushort)(param_3 - 1U << (*(uint *)(param_1 + DAT_30092410) & 0xff));
    iVar4 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar4) = (char)*(undefined2 *)(param_1 + DAT_30092414);
    *(int *)(param_1 + 0x14) = iVar4 + 1;
    iVar4 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar4) =
         (char)((ushort)*(undefined2 *)(param_1 + DAT_30092414) >> 8);
    *(int *)(param_1 + 0x14) = iVar4 + 1;
    *(short *)(param_1 + DAT_30092414) =
         (short)((param_3 - 1U & 0xffff) >> (0x10U - *(int *)(param_1 + DAT_30092410) & 0xff));
    *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + -0xb;
  }
  if (*(int *)(param_1 + DAT_30092410) < 0xd) {
    *(ushort *)(param_1 + DAT_30092414) =
         *(ushort *)(param_1 + DAT_30092414) |
         (ushort)(param_4 + DAT_30092e30 << (*(uint *)(param_1 + DAT_30092410) & 0xff));
    *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + 4;
  }
  else {
    *(ushort *)(param_1 + DAT_30092414) =
         *(ushort *)(param_1 + DAT_30092414) |
         (ushort)(param_4 - 4U << (*(uint *)(param_1 + DAT_30092410) & 0xff));
    iVar4 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar4) = (char)*(undefined2 *)(param_1 + DAT_30092414);
    *(int *)(param_1 + 0x14) = iVar4 + 1;
    iVar4 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar4) =
         (char)((ushort)*(undefined2 *)(param_1 + DAT_30092414) >> 8);
    *(int *)(param_1 + 0x14) = iVar4 + 1;
    *(short *)(param_1 + DAT_30092414) =
         (short)((param_4 - 4U & 0xffff) >> (0x10U - *(int *)(param_1 + DAT_30092410) & 0xff));
    *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + -0xc;
  }
  for (iVar4 = 0; iVar4 < param_4; iVar4 = iVar4 + 1) {
    if (*(int *)(param_1 + DAT_30092410) < 0xe) {
      *(ushort *)(param_1 + DAT_30092414) =
           *(ushort *)(param_1 + DAT_30092414) |
           *(short *)(param_1 + (uint)*(byte *)(DAT_30092a1c + iVar4) * 4 + DAT_30092f68) <<
           (*(uint *)(param_1 + DAT_30092410) & 0xff);
      *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + 3;
    }
    else {
      uVar1 = *(ushort *)(param_1 + (uint)*(byte *)(DAT_30092a1c + iVar4) * 4 + DAT_30092028);
      *(ushort *)(param_1 + DAT_30092414) =
           *(ushort *)(param_1 + DAT_30092414) | uVar1 << (*(uint *)(param_1 + DAT_30092410) & 0xff)
      ;
      iVar2 = *(int *)(param_1 + 0x14);
      *(char *)(*(int *)(param_1 + 8) + iVar2) = (char)*(undefined2 *)(param_1 + DAT_30092414);
      *(int *)(param_1 + 0x14) = iVar2 + 1;
      iVar2 = *(int *)(param_1 + 0x14);
      *(char *)(*(int *)(param_1 + 8) + iVar2) =
           (char)((ushort)*(undefined2 *)(param_1 + DAT_30092414) >> 8);
      *(int *)(param_1 + 0x14) = iVar2 + 1;
      *(ushort *)(param_1 + DAT_30092414) =
           uVar1 >> (0x10U - *(int *)(param_1 + DAT_30092410) & 0xff);
      *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + -0xd;
    }
  }
  FUN_30091060(param_1,param_1 + 0x94,param_2 + -1);
  FUN_30091060(param_1,param_1 + DAT_30092a18,param_3 + -1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300920b8 @ 0x300920B8  (примерный размер ~444 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 0
 * Вызывают: QC_tr_flush_block, QC_tr_stored_block
 * Константы: 0x300920B8
 * Данные: DAT_30092410, DAT_30092414
 * ---------------------------------------------------------------- */
void FUN_300920b8(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + DAT_30092410) < 9) {
    if (0 < *(int *)(param_1 + DAT_30092410)) {
      iVar1 = *(int *)(param_1 + 0x14);
      *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)*(undefined2 *)(param_1 + DAT_30092414);
      *(int *)(param_1 + 0x14) = iVar1 + 1;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)*(undefined2 *)(param_1 + DAT_30092414);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    iVar1 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar1) =
         (char)((ushort)*(undefined2 *)(param_1 + DAT_30092414) >> 8);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
  }
  *(undefined2 *)(param_1 + DAT_30092414) = 0;
  *(undefined4 *)(param_1 + DAT_30092410) = 0;
  return;
}

/* ----------------------------------------------------------------
 * QC_tr_stored_block @ 0x30092274  (примерный размер ~288 байт)
 * Модуль: lib | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_300920b8
 * Вызывают: QC_deflate, QC_tr_flush_block
 * Константы: 0x30092274
 * Данные: DAT_30092410, DAT_30092414, DAT_3009311c
 * ---------------------------------------------------------------- */
void QC_tr_stored_block(int param_1,undefined1 *param_2,int param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  
  if (*(int *)(param_1 + DAT_30092410) < 0xe) {
    *(ushort *)(param_1 + DAT_30092414) =
         *(ushort *)(param_1 + DAT_30092414) |
         (ushort)(param_4 << (*(uint *)(param_1 + DAT_30092410) & 0xff));
    *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + 3;
  }
  else {
    *(ushort *)(param_1 + DAT_30092414) =
         *(ushort *)(param_1 + DAT_30092414) |
         (ushort)(param_4 << (*(uint *)(param_1 + DAT_30092410) & 0xff));
    iVar2 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar2) = (char)*(undefined2 *)(param_1 + DAT_30092414);
    *(int *)(param_1 + 0x14) = iVar2 + 1;
    iVar2 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar2) =
         (char)((ushort)*(undefined2 *)(param_1 + DAT_30092414) >> 8);
    *(int *)(param_1 + 0x14) = iVar2 + 1;
    *(short *)(param_1 + DAT_30092414) =
         (short)((param_4 & 0xffff) >> (0x10U - *(int *)(param_1 + DAT_30092410) & 0xff));
    *(int *)(param_1 + DAT_30092410) = *(int *)(param_1 + DAT_30092410) + -0xd;
  }
  FUN_300920b8(param_1);
  *(undefined4 *)(param_1 + DAT_3009311c) = 8;
  iVar2 = *(int *)(param_1 + 0x14);
  *(byte *)(*(int *)(param_1 + 8) + iVar2) = (byte)param_3;
  *(int *)(param_1 + 0x14) = iVar2 + 1;
  iVar2 = *(int *)(param_1 + 0x14);
  bVar1 = (byte)((uint)param_3 >> 8);
  *(byte *)(*(int *)(param_1 + 8) + iVar2) = bVar1;
  *(int *)(param_1 + 0x14) = iVar2 + 1;
  iVar2 = *(int *)(param_1 + 0x14);
  *(byte *)(*(int *)(param_1 + 8) + iVar2) = ~(byte)param_3;
  *(int *)(param_1 + 0x14) = iVar2 + 1;
  iVar2 = *(int *)(param_1 + 0x14);
  *(byte *)(*(int *)(param_1 + 8) + iVar2) = ~bVar1;
  *(int *)(param_1 + 0x14) = iVar2 + 1;
  for (; param_3 != 0; param_3 = param_3 + -1) {
    iVar2 = *(int *)(param_1 + 0x14);
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar2) = *param_2;
    *(int *)(param_1 + 0x14) = iVar2 + 1;
    param_2 = param_2 + 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30092394 @ 0x30092394  (примерный размер ~236 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: QC_tr_align
 * Константы: 0x30092394
 * Данные: DAT_30092410, DAT_30092414, DAT_30093304, DAT_30093308, DAT_3009330c
 * ---------------------------------------------------------------- */
void FUN_30092394(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + DAT_30092410) == 0x10) {
    iVar1 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)*(undefined2 *)(param_1 + DAT_30092414);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    iVar1 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar1) =
         (char)((ushort)*(undefined2 *)(param_1 + DAT_30092414) >> 8);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(undefined2 *)(param_1 + DAT_30092414) = 0;
    *(undefined4 *)(param_1 + DAT_30092410) = 0;
  }
  else if (7 < *(int *)(param_1 + DAT_30093304)) {
    iVar1 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)*(undefined2 *)(param_1 + DAT_30093308);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(ushort *)(param_1 + DAT_30093308) = (ushort)*(byte *)(param_1 + DAT_3009330c);
    *(int *)(param_1 + DAT_30093304) = *(int *)(param_1 + DAT_30093304) + -8;
  }
  return;
}

/* ----------------------------------------------------------------
 * QC_tr_align @ 0x30092480  (примерный размер ~1176 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_30092394
 * Вызывают: QC_deflate
 * Константы: 0x30092480
 * Данные: DAT_3009311c, DAT_30093304, DAT_30093308, DAT_30093498, DAT_3009349c
 * ---------------------------------------------------------------- */
void QC_tr_align(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + DAT_30093304) < 0xe) {
    *(ushort *)(param_1 + DAT_30093308) =
         *(ushort *)(param_1 + DAT_30093308) |
         (ushort)(2 << (*(uint *)(param_1 + DAT_30093304) & 0xff));
    *(int *)(param_1 + DAT_30093304) = *(int *)(param_1 + DAT_30093304) + 3;
  }
  else {
    *(ushort *)(param_1 + DAT_30093308) =
         *(ushort *)(param_1 + DAT_30093308) |
         (ushort)(2 << (*(uint *)(param_1 + DAT_30093304) & 0xff));
    iVar3 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)*(undefined2 *)(param_1 + DAT_30093308);
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    iVar3 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar3) =
         (char)((ushort)*(undefined2 *)(param_1 + DAT_30093308) >> 8);
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    *(short *)(param_1 + DAT_30093308) =
         (short)(2 >> (0x10U - *(int *)(param_1 + DAT_30093304) & 0xff));
    *(int *)(param_1 + DAT_30093304) = *(int *)(param_1 + DAT_30093304) + -0xd;
  }
  uVar2 = (uint)*(ushort *)(DAT_30093498 + DAT_3009349c);
  if ((int)(0x10 - uVar2) < *(int *)(param_1 + DAT_30093304)) {
    uVar1 = *(ushort *)(DAT_30093498 + 0x400);
    *(ushort *)(param_1 + DAT_30093308) =
         *(ushort *)(param_1 + DAT_30093308) | uVar1 << (*(uint *)(param_1 + DAT_30093304) & 0xff);
    iVar3 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)*(undefined2 *)(param_1 + DAT_30093308);
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    iVar3 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar3) =
         (char)((ushort)*(undefined2 *)(param_1 + DAT_30093308) >> 8);
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    *(ushort *)(param_1 + DAT_30093308) = uVar1 >> (0x10U - *(int *)(param_1 + DAT_30093304) & 0xff)
    ;
    *(uint *)(param_1 + DAT_30093304) = uVar2 + *(int *)(param_1 + DAT_30093304) + -0x10;
  }
  else {
    *(ushort *)(param_1 + DAT_30093308) =
         *(ushort *)(param_1 + DAT_30093308) |
         *(short *)(DAT_30093498 + 0x400) << (*(uint *)(param_1 + DAT_30093304) & 0xff);
    *(uint *)(param_1 + DAT_30093304) = uVar2 + *(int *)(param_1 + DAT_30093304);
  }
  FUN_30092394(param_1);
  if ((*(int *)(param_1 + DAT_3009311c) - *(int *)(param_1 + DAT_30093304)) + 0xb < 9) {
    if (*(int *)(param_1 + DAT_30093304) < 0xe) {
      *(ushort *)(param_1 + DAT_30093308) =
           *(ushort *)(param_1 + DAT_30093308) |
           (ushort)(2 << (*(uint *)(param_1 + DAT_30093304) & 0xff));
      *(int *)(param_1 + DAT_30093304) = *(int *)(param_1 + DAT_30093304) + 3;
    }
    else {
      *(ushort *)(param_1 + DAT_30093308) =
           *(ushort *)(param_1 + DAT_30093308) |
           (ushort)(2 << (*(uint *)(param_1 + DAT_30093304) & 0xff));
      iVar3 = *(int *)(param_1 + 0x14);
      *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)*(undefined2 *)(param_1 + DAT_30093308);
      *(int *)(param_1 + 0x14) = iVar3 + 1;
      iVar3 = *(int *)(param_1 + 0x14);
      *(char *)(*(int *)(param_1 + 8) + iVar3) =
           (char)((ushort)*(undefined2 *)(param_1 + DAT_30093308) >> 8);
      *(int *)(param_1 + 0x14) = iVar3 + 1;
      *(short *)(param_1 + DAT_30093308) =
           (short)(2 >> (0x10U - *(int *)(param_1 + DAT_30093304) & 0xff));
      *(int *)(param_1 + DAT_30093304) = *(int *)(param_1 + DAT_30093304) + -0xd;
    }
    uVar2 = (uint)*(ushort *)(DAT_30093498 + DAT_3009349c);
    if ((int)(0x10 - uVar2) < *(int *)(param_1 + DAT_30093304)) {
      uVar1 = *(ushort *)(DAT_30093498 + 0x400);
      *(ushort *)(param_1 + DAT_30093308) =
           *(ushort *)(param_1 + DAT_30093308) | uVar1 << (*(uint *)(param_1 + DAT_30093304) & 0xff)
      ;
      iVar3 = *(int *)(param_1 + 0x14);
      *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)*(undefined2 *)(param_1 + DAT_30093308);
      *(int *)(param_1 + 0x14) = iVar3 + 1;
      iVar3 = *(int *)(param_1 + 0x14);
      *(char *)(*(int *)(param_1 + 8) + iVar3) =
           (char)((ushort)*(undefined2 *)(param_1 + DAT_30093308) >> 8);
      *(int *)(param_1 + 0x14) = iVar3 + 1;
      *(ushort *)(param_1 + DAT_30093308) =
           uVar1 >> (0x10U - *(int *)(param_1 + DAT_30093304) & 0xff);
      *(uint *)(param_1 + DAT_30093304) = uVar2 + *(int *)(param_1 + DAT_30093304) + -0x10;
    }
    else {
      *(ushort *)(param_1 + DAT_30093308) =
           *(ushort *)(param_1 + DAT_30093308) |
           *(short *)(DAT_30093498 + 0x400) << (*(uint *)(param_1 + DAT_30093304) & 0xff);
      *(uint *)(param_1 + DAT_30093304) = uVar2 + *(int *)(param_1 + DAT_30093304);
    }
    FUN_30092394(param_1);
  }
  *(undefined4 *)(param_1 + DAT_3009311c) = 7;
  return;
}

/* ----------------------------------------------------------------
 * FUN_30092918 @ 0x30092918  (примерный размер ~2020 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: QC_tr_flush_block
 * Константы: 0x30092918
 * Данные: DAT_3009311c, DAT_30093304, DAT_30093308, DAT_3009349c, DAT_3009364c, DAT_30093650, DAT_30093654, DAT_30093658
 * ---------------------------------------------------------------- */
void FUN_30092918(int param_1,int param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  uVar5 = 0;
  if (*(int *)(param_1 + DAT_3009364c) != 0) {
    do {
      uVar7 = (uint)*(ushort *)(*(int *)(param_1 + DAT_30093650) + uVar5 * 2);
      uVar6 = (uint)*(byte *)(*(int *)(param_1 + DAT_30093654) + uVar5);
      uVar5 = uVar5 + 1;
      if (uVar7 == 0) {
        uVar7 = (uint)*(ushort *)(param_2 + uVar6 * 4 + 2);
        if ((int)(0x10 - uVar7) < *(int *)(param_1 + DAT_30093304)) {
          uVar2 = *(ushort *)(param_2 + uVar6 * 4);
          *(ushort *)(param_1 + DAT_30093308) =
               *(ushort *)(param_1 + DAT_30093308) |
               uVar2 << (*(uint *)(param_1 + DAT_30093304) & 0xff);
          iVar3 = *(int *)(param_1 + 0x14);
          *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)*(undefined2 *)(param_1 + DAT_30093308);
          *(int *)(param_1 + 0x14) = iVar3 + 1;
          iVar3 = *(int *)(param_1 + 0x14);
          *(char *)(*(int *)(param_1 + 8) + iVar3) =
               (char)((ushort)*(undefined2 *)(param_1 + DAT_30093308) >> 8);
          *(int *)(param_1 + 0x14) = iVar3 + 1;
          *(ushort *)(param_1 + DAT_30093308) =
               uVar2 >> (0x10U - *(int *)(param_1 + DAT_30093304) & 0xff);
          *(uint *)(param_1 + DAT_30093304) = uVar7 + *(int *)(param_1 + DAT_30093304) + -0x10;
        }
        else {
          *(ushort *)(param_1 + DAT_30093308) =
               *(ushort *)(param_1 + DAT_30093308) |
               *(short *)(param_2 + uVar6 * 4) << (*(uint *)(param_1 + DAT_30093304) & 0xff);
          *(uint *)(param_1 + DAT_30093304) = uVar7 + *(int *)(param_1 + DAT_30093304);
        }
      }
      else {
        uVar4 = (uint)*(byte *)(DAT_30093658 + uVar6);
        uVar8 = (uint)*(ushort *)(param_2 + uVar4 * 4 + DAT_3009365c);
        if ((int)(0x10 - uVar8) < *(int *)(param_1 + DAT_30093304)) {
          uVar2 = *(ushort *)(param_2 + uVar4 * 4 + DAT_30093660);
          *(ushort *)(param_1 + DAT_30093308) =
               *(ushort *)(param_1 + DAT_30093308) |
               uVar2 << (*(uint *)(param_1 + DAT_30093304) & 0xff);
          iVar3 = *(int *)(param_1 + 0x14);
          *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)*(undefined2 *)(param_1 + DAT_30093308);
          *(int *)(param_1 + 0x14) = iVar3 + 1;
          iVar3 = *(int *)(param_1 + 0x14);
          *(char *)(*(int *)(param_1 + 8) + iVar3) =
               (char)((ushort)*(undefined2 *)(param_1 + DAT_30093308) >> 8);
          *(int *)(param_1 + 0x14) = iVar3 + 1;
          *(ushort *)(param_1 + DAT_30093308) =
               uVar2 >> (0x10U - *(int *)(param_1 + DAT_30093304) & 0xff);
          *(uint *)(param_1 + DAT_30093304) = uVar8 + *(int *)(param_1 + DAT_30093304) + -0x10;
        }
        else {
          *(ushort *)(param_1 + DAT_30093308) =
               *(ushort *)(param_1 + DAT_30093308) |
               *(short *)(param_2 + uVar4 * 4 + DAT_30093660) <<
               (*(uint *)(param_1 + DAT_30093304) & 0xff);
          *(uint *)(param_1 + DAT_30093304) = uVar8 + *(int *)(param_1 + DAT_30093304);
        }
        iVar3 = *(int *)(DAT_30093664 + uVar4 * 4);
        if (iVar3 != 0) {
          uVar6 = uVar6 - *(int *)(DAT_30093668 + uVar4 * 4);
          if (0x10 - iVar3 < *(int *)(param_1 + DAT_30093304)) {
            *(ushort *)(param_1 + DAT_30093308) =
                 *(ushort *)(param_1 + DAT_30093308) |
                 (ushort)(uVar6 << (*(uint *)(param_1 + DAT_30093304) & 0xff));
            iVar9 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar9) = (char)*(undefined2 *)(param_1 + DAT_30093308)
            ;
            *(int *)(param_1 + 0x14) = iVar9 + 1;
            iVar9 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar9) =
                 (char)((ushort)*(undefined2 *)(param_1 + DAT_30093308) >> 8);
            *(int *)(param_1 + 0x14) = iVar9 + 1;
            *(short *)(param_1 + DAT_30093308) =
                 (short)((uVar6 & 0xffff) >> (0x10U - *(int *)(param_1 + DAT_30093304) & 0xff));
            *(int *)(param_1 + DAT_30093304) = iVar3 + *(int *)(param_1 + DAT_30093304) + -0x10;
          }
          else {
            *(ushort *)(param_1 + DAT_30093308) =
                 *(ushort *)(param_1 + DAT_30093308) |
                 (ushort)(uVar6 << (*(uint *)(param_1 + DAT_30093304) & 0xff));
            *(int *)(param_1 + DAT_30093304) = iVar3 + *(int *)(param_1 + DAT_30093304);
          }
        }
        uVar7 = uVar7 - 1;
        if (uVar7 < 0x100) {
          bVar1 = *(byte *)(DAT_3009366c + uVar7);
        }
        else {
          bVar1 = *(byte *)(DAT_30093670 + (uVar7 >> 7));
        }
        uVar4 = (uint)bVar1;
        uVar6 = (uint)*(ushort *)(param_3 + uVar4 * 4 + 2);
        if ((int)(0x10 - uVar6) < *(int *)(param_1 + DAT_30093304)) {
          uVar2 = *(ushort *)(param_3 + uVar4 * 4);
          *(ushort *)(param_1 + DAT_30093308) =
               *(ushort *)(param_1 + DAT_30093308) |
               uVar2 << (*(uint *)(param_1 + DAT_30093304) & 0xff);
          iVar3 = *(int *)(param_1 + 0x14);
          *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)*(undefined2 *)(param_1 + DAT_30093308);
          *(int *)(param_1 + 0x14) = iVar3 + 1;
          iVar3 = *(int *)(param_1 + 0x14);
          *(char *)(*(int *)(param_1 + 8) + iVar3) =
               (char)((ushort)*(undefined2 *)(param_1 + DAT_30093308) >> 8);
          *(int *)(param_1 + 0x14) = iVar3 + 1;
          *(ushort *)(param_1 + DAT_30093308) =
               uVar2 >> (0x10U - *(int *)(param_1 + DAT_30093304) & 0xff);
          *(uint *)(param_1 + DAT_30093304) = uVar6 + *(int *)(param_1 + DAT_30093304) + -0x10;
        }
        else {
          *(ushort *)(param_1 + DAT_30093308) =
               *(ushort *)(param_1 + DAT_30093308) |
               *(short *)(param_3 + uVar4 * 4) << (*(uint *)(param_1 + DAT_30093304) & 0xff);
          *(uint *)(param_1 + DAT_30093304) = uVar6 + *(int *)(param_1 + DAT_30093304);
        }
        iVar3 = *(int *)(DAT_30093674 + uVar4 * 4);
        if (iVar3 != 0) {
          uVar7 = uVar7 - *(int *)(DAT_30093678 + uVar4 * 4);
          if (0x10 - iVar3 < *(int *)(param_1 + DAT_30093304)) {
            *(ushort *)(param_1 + DAT_30093308) =
                 *(ushort *)(param_1 + DAT_30093308) |
                 (ushort)(uVar7 << (*(uint *)(param_1 + DAT_30093304) & 0xff));
            iVar9 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar9) = (char)*(undefined2 *)(param_1 + DAT_30093308)
            ;
            *(int *)(param_1 + 0x14) = iVar9 + 1;
            iVar9 = *(int *)(param_1 + 0x14);
            *(char *)(*(int *)(param_1 + 8) + iVar9) =
                 (char)((ushort)*(undefined2 *)(param_1 + DAT_30093308) >> 8);
            *(int *)(param_1 + 0x14) = iVar9 + 1;
            *(short *)(param_1 + DAT_30093308) =
                 (short)((uVar7 & 0xffff) >> (0x10U - *(int *)(param_1 + DAT_30093304) & 0xff));
            *(int *)(param_1 + DAT_30093304) = iVar3 + *(int *)(param_1 + DAT_30093304) + -0x10;
          }
          else {
            *(ushort *)(param_1 + DAT_30093308) =
                 *(ushort *)(param_1 + DAT_30093308) |
                 (ushort)(uVar7 << (*(uint *)(param_1 + DAT_30093304) & 0xff));
            *(int *)(param_1 + DAT_30093304) = iVar3 + *(int *)(param_1 + DAT_30093304);
          }
        }
      }
    } while (uVar5 < *(uint *)(param_1 + DAT_3009364c));
  }
  uVar5 = (uint)*(ushort *)(param_2 + DAT_3009349c);
  if ((int)(0x10 - uVar5) < *(int *)(param_1 + DAT_30093304)) {
    uVar2 = *(ushort *)(param_2 + 0x400);
    *(ushort *)(param_1 + DAT_30093308) =
         *(ushort *)(param_1 + DAT_30093308) | uVar2 << (*(uint *)(param_1 + DAT_30093304) & 0xff);
    iVar3 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)*(undefined2 *)(param_1 + DAT_30093308);
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    iVar3 = *(int *)(param_1 + 0x14);
    *(char *)(*(int *)(param_1 + 8) + iVar3) =
         (char)((ushort)*(undefined2 *)(param_1 + DAT_30093308) >> 8);
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    *(ushort *)(param_1 + DAT_30093308) = uVar2 >> (0x10U - *(int *)(param_1 + DAT_30093304) & 0xff)
    ;
    *(uint *)(param_1 + DAT_30093304) = uVar5 + *(int *)(param_1 + DAT_30093304) + -0x10;
  }
  else {
    *(ushort *)(param_1 + DAT_30093308) =
         *(ushort *)(param_1 + DAT_30093308) |
         *(short *)(param_2 + 0x400) << (*(uint *)(param_1 + DAT_30093304) & 0xff);
    *(uint *)(param_1 + DAT_30093304) = uVar5 + *(int *)(param_1 + DAT_30093304);
  }
  *(uint *)(param_1 + DAT_3009311c) = (uint)*(ushort *)(param_2 + DAT_3009349c);
  return;
}

/* ----------------------------------------------------------------
 * FUN_300930fc @ 0x300930FC  (примерный размер ~132 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: QC_tr_flush_block
 * Константы: 0x300930FC
 * ---------------------------------------------------------------- */
void FUN_300930fc(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while ((iVar1 < 9 && ((short)param_1[iVar1 + 0x25] == 0))) {
    iVar1 = iVar1 + 1;
  }
  if (iVar1 == 9) {
    iVar1 = 0xe;
    while ((iVar1 < 0x20 && ((short)param_1[iVar1 + 0x25] == 0))) {
      iVar1 = iVar1 + 1;
    }
  }
  *(uint *)(*param_1 + 0x2c) = (uint)(iVar1 == 0x20);
  return;
}

/* ----------------------------------------------------------------
 * QC_tr_flush_block @ 0x30093180  (примерный размер ~952 байт)
 * Модуль: lib | Вызывают: 3 | Вызывает: 8
 * Вызывает: FUN_300903a0, FUN_30090b10, FUN_30091b34, FUN_30091bcc, FUN_300920b8, FUN_30092918, FUN_300930fc, QC_tr_stored_block
 * Вызывают: FUN_3008a0a0, FUN_3008a2ec, FUN_3008a8bc
 * Константы: 0x30093180
 * Данные: DAT_30093304, DAT_30093308, DAT_30093498, DAT_3009367c, DAT_30093680, DAT_30093684, DAT_30093688, DAT_3009368c
 * ---------------------------------------------------------------- */
void QC_tr_flush_block(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_34;
  
  local_34 = 0;
  if (param_1[0x21] < 1) {
    uVar2 = param_3 + 5;
    uVar3 = uVar2;
  }
  else {
    if ((param_3 != 0) && (*(int *)(*param_1 + 0x2c) == 2)) {
      FUN_300930fc(param_1);
    }
    FUN_30090b10(param_1,(int)param_1 + DAT_3009367c);
    FUN_30090b10(param_1,(int)param_1 + DAT_30093680);
    local_34 = FUN_30091b34(param_1);
    uVar3 = *(int *)((int)param_1 + DAT_30093684) + 10U >> 3;
    uVar2 = *(int *)((int)param_1 + DAT_30093688) + 10U >> 3;
    if (uVar2 <= uVar3) {
      uVar3 = uVar2;
    }
  }
  if ((uVar3 < param_3 + 4U) || (param_2 == 0)) {
    if ((param_1[0x22] == 4) || (uVar2 == uVar3)) {
      if (*(int *)((int)param_1 + DAT_30093304) < 0xe) {
        *(ushort *)((int)param_1 + DAT_3009368c) =
             *(ushort *)((int)param_1 + DAT_3009368c) |
             (ushort)(param_4 + 2 << (*(uint *)((int)param_1 + DAT_30093690) & 0xff));
        *(int *)((int)param_1 + DAT_30093690) = *(int *)((int)param_1 + DAT_30093690) + 3;
      }
      else {
        *(ushort *)((int)param_1 + DAT_30093308) =
             *(ushort *)((int)param_1 + DAT_30093308) |
             (ushort)(param_4 + 2U << (*(uint *)((int)param_1 + DAT_30093304) & 0xff));
        iVar1 = param_1[5];
        *(char *)(param_1[2] + iVar1) = (char)*(undefined2 *)((int)param_1 + DAT_30093308);
        param_1[5] = iVar1 + 1;
        iVar1 = param_1[5];
        *(char *)(param_1[2] + iVar1) =
             (char)((ushort)*(undefined2 *)((int)param_1 + DAT_3009368c) >> 8);
        param_1[5] = iVar1 + 1;
        *(short *)((int)param_1 + DAT_3009368c) =
             (short)((param_4 + 2U & 0xffff) >>
                    (0x10U - *(int *)((int)param_1 + DAT_30093690) & 0xff));
        *(int *)((int)param_1 + DAT_30093690) = *(int *)((int)param_1 + DAT_30093690) + -0xd;
      }
      FUN_30092918(param_1,DAT_30093498,DAT_30093694);
    }
    else {
      if (*(int *)((int)param_1 + DAT_30093690) < 0xe) {
        *(ushort *)((int)param_1 + DAT_3009368c) =
             *(ushort *)((int)param_1 + DAT_3009368c) |
             (ushort)(param_4 + 4 << (*(uint *)((int)param_1 + DAT_30093690) & 0xff));
        *(int *)((int)param_1 + DAT_30093690) = *(int *)((int)param_1 + DAT_30093690) + 3;
      }
      else {
        *(ushort *)((int)param_1 + DAT_3009368c) =
             *(ushort *)((int)param_1 + DAT_3009368c) |
             (ushort)(param_4 + 4U << (*(uint *)((int)param_1 + DAT_30093690) & 0xff));
        iVar1 = param_1[5];
        *(char *)(param_1[2] + iVar1) = (char)*(undefined2 *)((int)param_1 + DAT_3009368c);
        param_1[5] = iVar1 + 1;
        iVar1 = param_1[5];
        *(char *)(param_1[2] + iVar1) =
             (char)((ushort)*(undefined2 *)((int)param_1 + DAT_3009368c) >> 8);
        param_1[5] = iVar1 + 1;
        *(short *)((int)param_1 + DAT_3009368c) =
             (short)((param_4 + 4U & 0xffff) >>
                    (0x10U - *(int *)((int)param_1 + DAT_30093690) & 0xff));
        *(int *)((int)param_1 + DAT_30093690) = *(int *)((int)param_1 + DAT_30093690) + -0xd;
      }
      FUN_30091bcc(param_1,param_1[0x2c7] + 1,param_1[0x2ca] + 1,local_34 + 1);
      FUN_30092918(param_1,param_1 + 0x25,(int)param_1 + DAT_30093698);
    }
  }
  else {
    QC_tr_stored_block(param_1,param_2,param_3,param_4);
  }
  FUN_300903a0(param_1);
  if (param_4 != 0) {
    FUN_300920b8(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * QC_tr_tally @ 0x30093538  (примерный размер ~272 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x30093538
 * Данные: DAT_3009364c, DAT_30093650, DAT_30093654, DAT_30093658, DAT_3009366c, DAT_30093670, DAT_30093698, DAT_3009369c
 * ---------------------------------------------------------------- */
bool QC_tr_tally(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  short *psVar3;
  uint uVar4;
  
  *(short *)(*(int *)(param_1 + DAT_30093650) + *(int *)(param_1 + DAT_3009364c) * 2) =
       (short)param_2;
  iVar2 = *(int *)(param_1 + DAT_3009364c);
  *(char *)(*(int *)(param_1 + DAT_30093654) + iVar2) = (char)param_3;
  *(int *)(param_1 + DAT_3009364c) = iVar2 + 1;
  if (param_2 == 0) {
    psVar3 = (short *)(param_1 + param_3 * 4 + 0x94);
    *psVar3 = *psVar3 + 1;
  }
  else {
    *(int *)(param_1 + DAT_3009369c) = *(int *)(param_1 + DAT_3009369c) + 1;
    uVar4 = param_2 - 1;
    psVar3 = (short *)(param_1 + (uint)*(byte *)(DAT_30093658 + param_3) * 4 + DAT_300936a0);
    *psVar3 = *psVar3 + 1;
    if (uVar4 < 0x100) {
      bVar1 = *(byte *)(DAT_3009366c + uVar4);
    }
    else {
      bVar1 = *(byte *)(DAT_30093670 + (uVar4 >> 7));
    }
    psVar3 = (short *)(param_1 + (uint)bVar1 * 4 + DAT_30093698);
    *psVar3 = *psVar3 + 1;
  }
  return *(int *)(param_1 + DAT_3009364c) == *(int *)(param_1 + DAT_300936a4) + -1;
}

/* ----------------------------------------------------------------
 * FUN_30093648 @ 0x30093648  (примерный размер ~96 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 0
 * Вызывают: QC_tr_init
 * Константы: 0x30093648
 * ---------------------------------------------------------------- */
void FUN_30093648(void)

{
  return;
}

/* ----------------------------------------------------------------
 * QC_uncompress @ 0x300936A8  (примерный размер ~256 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: QC_inflate, QC_inflateEnd, QC_inflateInit_
 * Константы: 0x300936A8, 0x300936D8
 * Данные: DAT_300937a4
 * ---------------------------------------------------------------- */
/* WARNING: Removing unreachable block (ram,0x300936d8) */

int QC_uncompress(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 local_50;
  int local_4c;
  undefined4 local_44;
  int local_40;
  int local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_40 = *param_2;
  if (local_40 == *param_2) {
    local_30 = 0;
    local_2c = 0;
    local_50 = param_3;
    local_4c = param_4;
    local_44 = param_1;
    iVar1 = QC_inflateInit_(&local_50,DAT_300937a4,0x38);
    if (iVar1 == 0) {
      iVar1 = QC_inflate(&local_50,4);
      if (iVar1 == 1) {
        *param_2 = local_3c;
        iVar1 = QC_inflateEnd(&local_50);
      }
      else {
        QC_inflateEnd(&local_50);
        if ((iVar1 == 2) || ((iVar1 == -5 && (local_4c == 0)))) {
          iVar1 = -3;
        }
      }
    }
  }
  else {
    iVar1 = -5;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * QC_zlibVersion @ 0x300937A8  (примерный размер ~8 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300937A8
 * Данные: DAT_30093810
 * ---------------------------------------------------------------- */
undefined4 QC_zlibVersion(void)

{
  return DAT_30093810;
}

/* ----------------------------------------------------------------
 * QC_zlibCompileFlags @ 0x300937B0  (примерный размер ~20 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300937B0
 * ---------------------------------------------------------------- */
undefined4 QC_zlibCompileFlags(void)

{
  return 0x55;
}

/* ----------------------------------------------------------------
 * QC_zError @ 0x300937C4  (примерный размер ~32 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300937C4
 * Данные: DAT_30093814
 * ---------------------------------------------------------------- */
undefined4 QC_zError(int param_1)

{
  return *(undefined4 *)(DAT_30093814 + param_1 * -4 + 8);
}

/* ----------------------------------------------------------------
 * QC_zcalloc @ 0x300937E4  (примерный размер ~24 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: malloc
 * Константы: 0x300937E4
 * ---------------------------------------------------------------- */
void QC_zcalloc(undefined4 param_1,int param_2,int param_3)

{
  malloc(param_3 * param_2);
  return;
}

/* ----------------------------------------------------------------
 * QC_zcfree @ 0x300937FC  (примерный размер ~28 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: free
 * Константы: 0x300937FC
 * ---------------------------------------------------------------- */
void QC_zcfree(undefined4 param_1,void *param_2)

{
  free(param_2);
  return;
}

/* ----------------------------------------------------------------
 * fread_req @ 0x30099E1C  (примерный размер ~44 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: fread
 * Константы: 0x30099E1C
 * ---------------------------------------------------------------- */
void fread_req(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  fread(param_1,param_2,param_3,param_4);
  return;
}

/* ----------------------------------------------------------------
 * fwrite_req @ 0x30099E48  (примерный размер ~44 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 1
 * Вызывает: fwrite
 * Константы: 0x30099E48
 * ---------------------------------------------------------------- */
void fwrite_req(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  fwrite(param_1,param_2,param_3,param_4);
  return;
}

/* ----------------------------------------------------------------
 * bcopy @ 0x300A9D54  (примерный размер ~1160 байт)
 * Модуль: lib | Вызывают: 53 | Вызывает: 0
 * Вызывают: FUN_30094530, FUN_300ac1fc, FUN_300aebec, FUN_300bc39c, FUN_300cad40, FUN_300cb00c, FUN_300cd2a8, FUN_300cd79c, FUN_300cdb24, FUN_300ce044
 *           ...
 * Константы: 0xFFFFFFFC, 0x300A9D54
 * ---------------------------------------------------------------- */
void bcopy(void *__src,void *__dest,size_t __n)

{
  byte bVar1;
  uint *puVar2;
  byte *pbVar3;
  uint *puVar4;
  uint *puVar5;
  byte *pbVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint in_r3;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  bool bVar17;
  
  if (__src < __dest) {
    puVar4 = (uint *)((int)__src + __n);
    puVar7 = (uint *)((int)__dest + __n);
    iVar8 = __n - 4;
    iVar10 = iVar8;
    if ((int)__n < 4) goto LAB_300aa030;
    uVar12 = (uint)puVar7 & 3;
    if (uVar12 != 0) {
      bVar1 = *(byte *)((int)puVar4 + -1);
      *(byte *)((int)puVar7 + -1) = bVar1;
      puVar5 = (uint *)((int)puVar7 + -1);
      puVar2 = (uint *)((int)puVar4 + -1);
      if (1 < uVar12) {
        bVar1 = *(byte *)((int)puVar4 + -2);
        *(byte *)((int)puVar7 + -2) = bVar1;
        puVar5 = (uint *)((int)puVar7 + -2);
        puVar2 = (uint *)((int)puVar4 + -2);
      }
      puVar4 = puVar2;
      puVar7 = puVar5;
      if (2 < uVar12) {
        puVar4 = (uint *)((int)puVar4 + -1);
        bVar1 = *(byte *)puVar4;
      }
      in_r3 = (uint)bVar1;
      if (2 < uVar12) {
        puVar7 = (uint *)((int)puVar7 + -1);
        *(byte *)puVar7 = bVar1;
      }
      iVar10 = iVar8 - uVar12;
      bVar16 = iVar8 < (int)uVar12;
      iVar8 = iVar10;
      if (bVar16) goto LAB_300aa030;
    }
    uVar12 = (uint)puVar4 & 3;
    if (uVar12 == 0) {
      iVar9 = iVar8 + -8;
      if (7 < iVar8) {
        iVar8 = iVar8 + -0x1c;
        iVar10 = iVar8;
        if (0x13 < iVar9) {
          do {
            uVar15 = puVar4[-2];
            uVar13 = puVar4[-3];
            uVar12 = puVar4[-4];
            puVar7[-1] = puVar4[-1];
            puVar7[-2] = uVar15;
            puVar7[-3] = uVar13;
            puVar7[-4] = uVar12;
            puVar5 = puVar4 + -5;
            uVar13 = puVar4[-6];
            uVar12 = puVar4[-7];
            puVar4 = puVar4 + -8;
            in_r3 = *puVar4;
            puVar7[-5] = *puVar5;
            puVar7[-6] = uVar13;
            puVar7[-7] = uVar12;
            puVar7 = puVar7 + -8;
            *puVar7 = in_r3;
            iVar8 = iVar10 + -0x20;
            bVar16 = 0x1f < iVar10;
            iVar10 = iVar8;
          } while (bVar16);
        }
        if (iVar8 + 0x10 < 0 == SCARRY4(iVar8,0x10)) {
          puVar5 = puVar4 + -1;
          uVar13 = puVar4[-2];
          uVar12 = puVar4[-3];
          puVar4 = puVar4 + -4;
          in_r3 = *puVar4;
          puVar7[-1] = *puVar5;
          puVar7[-2] = uVar13;
          puVar7[-3] = uVar12;
          puVar7 = puVar7 + -4;
          *puVar7 = in_r3;
          iVar8 = iVar8 + -0x10;
        }
        iVar9 = iVar8 + 0x14;
        if (iVar9 < 0 == SCARRY4(iVar8,0x14)) {
          puVar5 = puVar4 + -1;
          uVar12 = puVar4[-2];
          puVar4 = puVar4 + -3;
          in_r3 = *puVar4;
          puVar7[-1] = *puVar5;
          puVar7[-2] = uVar12;
          puVar7 = puVar7 + -3;
          *puVar7 = in_r3;
          iVar9 = iVar8 + 8;
        }
      }
      iVar10 = iVar9 + 8;
      if (iVar10 < 0 == SCARRY4(iVar9,8)) {
        if (iVar10 < 4) {
          puVar4 = puVar4 + -1;
          in_r3 = *puVar4;
        }
        if (iVar9 + 4 < 0 == SBORROW4(iVar10,4)) {
          puVar5 = puVar4 + -1;
          puVar4 = puVar4 + -2;
          uVar12 = *puVar4;
          puVar7[-1] = *puVar5;
          puVar7 = puVar7 + -2;
          *puVar7 = uVar12;
          iVar10 = iVar9;
        }
        else {
          puVar7 = puVar7 + -1;
          *puVar7 = in_r3;
          iVar10 = iVar9 + 4;
        }
      }
      goto LAB_300aa030;
    }
    puVar4 = (uint *)((uint)puVar4 & 0xfffffffc);
    uVar13 = *puVar4;
    if (1 < uVar12) {
      if (uVar12 == 2) {
        if (iVar8 < 0xc) {
LAB_300aa150:
          do {
            uVar12 = uVar13 << 0x10;
            puVar4 = puVar4 + -1;
            uVar13 = *puVar4;
            puVar7 = puVar7 + -1;
            *puVar7 = uVar12 | uVar13 >> 0x10;
            iVar10 = iVar8 + -4;
            bVar16 = 3 < iVar8;
            iVar8 = iVar10;
          } while (bVar16);
        }
        else {
          iVar8 = iVar8 + -0xc;
          do {
            iVar9 = iVar8;
            uVar12 = uVar13 << 0x10;
            uVar14 = puVar4[-1];
            uVar11 = puVar4[-2];
            uVar15 = puVar4[-3];
            puVar4 = puVar4 + -4;
            uVar13 = *puVar4;
            puVar7[-1] = uVar12 | uVar14 >> 0x10;
            puVar7[-2] = uVar14 << 0x10 | uVar11 >> 0x10;
            puVar7[-3] = uVar11 << 0x10 | uVar15 >> 0x10;
            puVar7 = puVar7 + -4;
            *puVar7 = uVar15 << 0x10 | uVar13 >> 0x10;
            iVar8 = iVar9 + -0x10;
          } while (0xf < iVar9);
          iVar10 = iVar9 + -4;
          iVar8 = iVar10;
          if (iVar10 < 0 == SCARRY4(iVar9 + -0x10,0xc)) goto LAB_300aa150;
        }
        puVar4 = (uint *)((int)puVar4 + 2);
        goto LAB_300aa030;
      }
      if (iVar8 < 0xc) {
LAB_300aa0e4:
        do {
          uVar12 = uVar13 << 8;
          puVar4 = puVar4 + -1;
          uVar13 = *puVar4;
          puVar7 = puVar7 + -1;
          *puVar7 = uVar12 | uVar13 >> 0x18;
          iVar10 = iVar8 + -4;
          bVar16 = 3 < iVar8;
          iVar8 = iVar10;
        } while (bVar16);
      }
      else {
        iVar8 = iVar8 + -0xc;
        do {
          iVar9 = iVar8;
          uVar12 = uVar13 << 8;
          uVar14 = puVar4[-1];
          uVar11 = puVar4[-2];
          uVar15 = puVar4[-3];
          puVar4 = puVar4 + -4;
          uVar13 = *puVar4;
          puVar7[-1] = uVar12 | uVar14 >> 0x18;
          puVar7[-2] = uVar14 << 8 | uVar11 >> 0x18;
          puVar7[-3] = uVar11 << 8 | uVar15 >> 0x18;
          puVar7 = puVar7 + -4;
          *puVar7 = uVar15 << 8 | uVar13 >> 0x18;
          iVar8 = iVar9 + -0x10;
        } while (0xf < iVar9);
        iVar10 = iVar9 + -4;
        iVar8 = iVar10;
        if (iVar10 < 0 == SCARRY4(iVar9 + -0x10,0xc)) goto LAB_300aa0e4;
      }
      puVar4 = (uint *)((int)puVar4 + 3);
      goto LAB_300aa030;
    }
    if (iVar8 < 0xc) {
LAB_300aa1bc:
      do {
        uVar12 = uVar13 << 0x18;
        puVar4 = puVar4 + -1;
        uVar13 = *puVar4;
        puVar7 = puVar7 + -1;
        *puVar7 = uVar12 | uVar13 >> 8;
        iVar10 = iVar8 + -4;
        bVar16 = 3 < iVar8;
        iVar8 = iVar10;
      } while (bVar16);
    }
    else {
      iVar8 = iVar8 + -0xc;
      do {
        iVar9 = iVar8;
        uVar12 = uVar13 << 0x18;
        uVar14 = puVar4[-1];
        uVar11 = puVar4[-2];
        uVar15 = puVar4[-3];
        puVar4 = puVar4 + -4;
        uVar13 = *puVar4;
        puVar7[-1] = uVar12 | uVar14 >> 8;
        puVar7[-2] = uVar14 << 0x18 | uVar11 >> 8;
        puVar7[-3] = uVar11 << 0x18 | uVar15 >> 8;
        puVar7 = puVar7 + -4;
        *puVar7 = uVar15 << 0x18 | uVar13 >> 8;
        iVar8 = iVar9 + -0x10;
      } while (0xf < iVar9);
      iVar10 = iVar9 + -4;
      iVar8 = iVar10;
      if (iVar10 < 0 == SCARRY4(iVar9 + -0x10,0xc)) goto LAB_300aa1bc;
    }
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_300aa030:
    iVar8 = iVar10 + 4;
    if (iVar10 != -4) {
      bVar16 = iVar10 + 2 < 0;
      pbVar3 = (byte *)((int)puVar4 + -1);
      bVar1 = *pbVar3;
      pbVar6 = (byte *)((int)puVar7 + -1);
      *pbVar6 = bVar1;
      if (1 < iVar8) {
        pbVar3 = (byte *)((int)puVar4 + -2);
        bVar1 = *pbVar3;
      }
      if (bVar16 == SBORROW4(iVar8,2)) {
        pbVar6 = (byte *)((int)puVar7 + -2);
        *pbVar6 = bVar1;
      }
      if (iVar8 != 2 && bVar16 == SBORROW4(iVar8,2)) {
        pbVar6[-1] = pbVar3[-1];
      }
      return;
    }
    return;
  }
  if (__src == __dest) {
    return;
  }
  iVar8 = __n - 4;
  puVar4 = (uint *)__dest;
  iVar10 = iVar8;
  if ((int)__n < 4) goto LAB_300a9df0;
  if (((uint)__dest & 3) == 0) {
    uVar12 = (uint)__src & 3;
  }
  else {
    iVar10 = -((uint)__dest & 3);
    iVar9 = iVar10 + 4;
    bVar17 = SBORROW4(iVar9,2);
    bVar16 = iVar10 + 2 < 0;
                    /* WARNING: Load size is inaccurate */
    bVar1 = *__src;
    *(byte *)__dest = bVar1;
    puVar4 = (uint *)((int)__src + 1);
    if (1 < iVar9) {
      puVar4 = (uint *)((int)__src + 2);
      bVar1 = *(byte *)((int)__src + 1);
    }
    puVar7 = (uint *)((int)__dest + 1);
    if (bVar16 == bVar17) {
      puVar7 = (uint *)((int)__dest + 2);
      *(byte *)((int)__dest + 1) = bVar1;
    }
    __src = puVar4;
    if (iVar9 != 2 && bVar16 == bVar17) {
      __src = (void *)((int)puVar4 + 1);
      bVar1 = (byte)*puVar4;
    }
    in_r3 = (uint)bVar1;
    puVar4 = puVar7;
    if (iVar9 != 2 && bVar16 == bVar17) {
      puVar4 = (uint *)((int)puVar7 + 1);
      *(byte *)puVar7 = bVar1;
    }
    iVar10 = iVar8 - iVar9;
    if (iVar8 < iVar9) goto LAB_300a9df0;
    uVar12 = (uint)__src & 3;
    iVar8 = iVar10;
    __dest = puVar4;
  }
  if (uVar12 == 0) {
    iVar9 = iVar8 + -8;
    if (7 < iVar8) {
      iVar8 = iVar8 + -0x1c;
      if (0x13 < iVar9) {
        do {
          iVar10 = iVar8;
          puVar7 = (uint *)__dest;
          puVar4 = (uint *)__src;
          uVar12 = puVar4[1];
          uVar13 = puVar4[2];
          uVar15 = puVar4[3];
          *puVar7 = *puVar4;
          puVar7[1] = uVar12;
          puVar7[2] = uVar13;
          puVar7[3] = uVar15;
          in_r3 = puVar4[4];
          uVar12 = puVar4[5];
          uVar13 = puVar4[6];
          uVar15 = puVar4[7];
          __src = puVar4 + 8;
          puVar7[4] = in_r3;
          puVar7[5] = uVar12;
          puVar7[6] = uVar13;
          puVar7[7] = uVar15;
          __dest = puVar7 + 8;
          iVar8 = iVar10 + -0x20;
        } while (0x1f < iVar10);
                    /* WARNING: Load size is inaccurate */
        if (iVar10 + -0x10 < 0 == SCARRY4(iVar8,0x10)) {
          in_r3 = *__src;
          uVar12 = puVar4[9];
          uVar13 = puVar4[10];
          uVar15 = puVar4[0xb];
          __src = puVar4 + 0xc;
          *(uint *)__dest = in_r3;
          puVar7[9] = uVar12;
          puVar7[10] = uVar13;
          puVar7[0xb] = uVar15;
          __dest = puVar7 + 0xc;
          iVar8 = iVar10 + -0x30;
        }
      }
      bVar17 = SCARRY4(iVar8,0x14);
      iVar9 = iVar8 + 0x14;
      bVar16 = iVar9 < 0;
      do {
                    /* WARNING: Load size is inaccurate */
        if (bVar16 == bVar17) {
          in_r3 = *__src;
          uVar12 = *(uint *)((int)__src + 4);
          uVar13 = *(uint *)((int)__src + 8);
          __src = (void *)((int)__src + 0xc);
          *(uint *)__dest = in_r3;
          *(uint *)((int)__dest + 4) = uVar12;
          *(uint *)((int)__dest + 8) = uVar13;
          __dest = (void *)((int)__dest + 0xc);
          bVar17 = SBORROW4(iVar9,0xc);
          iVar9 = iVar9 + -0xc;
          bVar16 = iVar9 < 0;
        }
      } while (bVar16 == bVar17);
    }
    iVar10 = iVar9 + 8;
    puVar4 = (uint *)__dest;
    if (iVar10 < 0 == SCARRY4(iVar9,8)) {
                    /* WARNING: Load size is inaccurate */
      if (iVar10 < 4) {
        in_r3 = *__src;
        __src = (uint *)((int)__src + 4);
      }
      if (iVar9 + 4 < 0 == SBORROW4(iVar10,4)) {
                    /* WARNING: Load size is inaccurate */
        uVar12 = *__src;
        uVar13 = *(uint *)((int)__src + 4);
        __src = (void *)((int)__src + 8);
        *(uint *)__dest = uVar12;
        *(uint *)((int)__dest + 4) = uVar13;
        puVar4 = (uint *)((int)__dest + 8);
        iVar10 = iVar9;
      }
      else {
        puVar4 = (uint *)((int)__dest + 4);
        *(uint *)__dest = in_r3;
        iVar10 = iVar9 + 4;
      }
    }
    goto LAB_300a9df0;
  }
  puVar7 = (uint *)((uint)__src & 0xfffffffc) + 1;
  uVar13 = *(uint *)((uint)__src & 0xfffffffc);
  if (uVar12 < 3) {
    if (uVar12 == 2) {
      puVar5 = puVar7;
      if (iVar8 < 0xc) {
LAB_300a9f14:
        do {
          uVar12 = uVar13 >> 0x10;
          puVar7 = puVar5 + 1;
          uVar13 = *puVar5;
          puVar4 = (uint *)((int)__dest + 4);
          *(uint *)__dest = uVar12 | uVar13 << 0x10;
          iVar10 = iVar8 + -4;
          bVar16 = 3 < iVar8;
          puVar5 = puVar7;
          __dest = puVar4;
          iVar8 = iVar10;
        } while (bVar16);
      }
      else {
        iVar8 = iVar8 + -0xc;
        do {
          iVar9 = iVar8;
          uVar12 = uVar13 >> 0x10;
          uVar15 = *puVar7;
          uVar11 = puVar7[1];
          uVar14 = puVar7[2];
          uVar13 = puVar7[3];
          puVar7 = puVar7 + 4;
          *(uint *)__dest = uVar12 | uVar15 << 0x10;
          *(uint *)((int)__dest + 4) = uVar15 >> 0x10 | uVar11 << 0x10;
          *(uint *)((int)__dest + 8) = uVar11 >> 0x10 | uVar14 << 0x10;
          *(uint *)((int)__dest + 0xc) = uVar14 >> 0x10 | uVar13 << 0x10;
          __dest = (void *)((int)__dest + 0x10);
          iVar8 = iVar9 + -0x10;
        } while (0xf < iVar9);
        iVar10 = iVar9 + -4;
        puVar5 = puVar7;
        puVar4 = (uint *)__dest;
        iVar8 = iVar10;
        if (iVar10 < 0 == SCARRY4(iVar9 + -0x10,0xc)) goto LAB_300a9f14;
      }
      __src = (void *)((int)puVar7 + -2);
      goto LAB_300a9df0;
    }
    puVar5 = puVar7;
    if (iVar8 < 0xc) {
LAB_300a9ea8:
      do {
        uVar12 = uVar13 >> 8;
        puVar7 = puVar5 + 1;
        uVar13 = *puVar5;
        puVar4 = (uint *)((int)__dest + 4);
        *(uint *)__dest = uVar12 | uVar13 << 0x18;
        iVar10 = iVar8 + -4;
        bVar16 = 3 < iVar8;
        puVar5 = puVar7;
        __dest = puVar4;
        iVar8 = iVar10;
      } while (bVar16);
    }
    else {
      iVar8 = iVar8 + -0xc;
      do {
        iVar9 = iVar8;
        uVar12 = uVar13 >> 8;
        uVar15 = *puVar7;
        uVar11 = puVar7[1];
        uVar14 = puVar7[2];
        uVar13 = puVar7[3];
        puVar7 = puVar7 + 4;
        *(uint *)__dest = uVar12 | uVar15 << 0x18;
        *(uint *)((int)__dest + 4) = uVar15 >> 8 | uVar11 << 0x18;
        *(uint *)((int)__dest + 8) = uVar11 >> 8 | uVar14 << 0x18;
        *(uint *)((int)__dest + 0xc) = uVar14 >> 8 | uVar13 << 0x18;
        __dest = (void *)((int)__dest + 0x10);
        iVar8 = iVar9 + -0x10;
      } while (0xf < iVar9);
      iVar10 = iVar9 + -4;
      puVar5 = puVar7;
      puVar4 = (uint *)__dest;
      iVar8 = iVar10;
      if (iVar10 < 0 == SCARRY4(iVar9 + -0x10,0xc)) goto LAB_300a9ea8;
    }
    __src = (void *)((int)puVar7 + -3);
    goto LAB_300a9df0;
  }
  puVar5 = puVar7;
  if (iVar8 < 0xc) {
LAB_300a9f80:
    do {
      uVar12 = uVar13 >> 0x18;
      puVar7 = puVar5 + 1;
      uVar13 = *puVar5;
      puVar4 = (uint *)((int)__dest + 4);
      *(uint *)__dest = uVar12 | uVar13 << 8;
      iVar10 = iVar8 + -4;
      bVar16 = 3 < iVar8;
      puVar5 = puVar7;
      __dest = puVar4;
      iVar8 = iVar10;
    } while (bVar16);
  }
  else {
    iVar8 = iVar8 + -0xc;
    do {
      iVar9 = iVar8;
      uVar12 = uVar13 >> 0x18;
      uVar15 = *puVar7;
      uVar11 = puVar7[1];
      uVar14 = puVar7[2];
      uVar13 = puVar7[3];
      puVar7 = puVar7 + 4;
      *(uint *)__dest = uVar12 | uVar15 << 8;
      *(uint *)((int)__dest + 4) = uVar15 >> 0x18 | uVar11 << 8;
      *(uint *)((int)__dest + 8) = uVar11 >> 0x18 | uVar14 << 8;
      *(uint *)((int)__dest + 0xc) = uVar14 >> 0x18 | uVar13 << 8;
      __dest = (void *)((int)__dest + 0x10);
      iVar8 = iVar9 + -0x10;
    } while (0xf < iVar9);
    iVar10 = iVar9 + -4;
    puVar5 = puVar7;
    puVar4 = (uint *)__dest;
    iVar8 = iVar10;
    if (iVar10 < 0 == SCARRY4(iVar9 + -0x10,0xc)) goto LAB_300a9f80;
  }
  __src = (void *)((int)puVar7 + -1);
LAB_300a9df0:
  iVar8 = iVar10 + 4;
  if (iVar10 != -4) {
    bVar16 = iVar10 + 2 < 0;
                    /* WARNING: Load size is inaccurate */
    bVar1 = (byte)*__src;
    *(byte *)puVar4 = bVar1;
    pbVar3 = (byte *)((int)__src + 1);
    if (1 < iVar8) {
      pbVar3 = (byte *)((int)__src + 2);
      bVar1 = *(byte *)((int)__src + 1);
    }
    pbVar6 = (byte *)((int)puVar4 + 1);
    if (bVar16 == SBORROW4(iVar8,2)) {
      pbVar6 = (byte *)((int)puVar4 + 2);
      *(byte *)((int)puVar4 + 1) = bVar1;
    }
    if (iVar8 != 2 && bVar16 == SBORROW4(iVar8,2)) {
      *pbVar6 = *pbVar3;
    }
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * bcopyBytes @ 0x300AA1DC  (примерный размер ~348 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AA1DC
 * ---------------------------------------------------------------- */
void bcopyBytes(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  if (param_3 == 0) {
    return;
  }
  if (param_2 == param_1) {
    return;
  }
  if (((int)param_1 <= (int)param_2) && ((int)param_2 - (int)param_1 < (int)param_3)) {
    param_2 = param_2 + param_3;
    param_1 = param_1 + param_3;
    uVar3 = param_3;
    switch(param_3 & 0xf) {
    case 1:
      while( true ) {
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
        param_3 = uVar3 - 0x10;
        if (param_3 == 0 || (int)uVar3 < 0x10) break;
switchD_300aa20c_default:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_f:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_e:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_d:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_c:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_b:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_a:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_9:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_8:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_7:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_6:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_5:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_4:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_3:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa20c_caseD_2:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
        uVar3 = param_3;
      }
      break;
    case 2:
      goto switchD_300aa20c_caseD_2;
    case 3:
      goto switchD_300aa20c_caseD_3;
    case 4:
      goto switchD_300aa20c_caseD_4;
    case 5:
      goto switchD_300aa20c_caseD_5;
    case 6:
      goto switchD_300aa20c_caseD_6;
    case 7:
      goto switchD_300aa20c_caseD_7;
    case 8:
      goto switchD_300aa20c_caseD_8;
    case 9:
      goto switchD_300aa20c_caseD_9;
    case 10:
      goto switchD_300aa20c_caseD_a;
    case 0xb:
      goto switchD_300aa20c_caseD_b;
    case 0xc:
      goto switchD_300aa20c_caseD_c;
    case 0xd:
      goto switchD_300aa20c_caseD_d;
    case 0xe:
      goto switchD_300aa20c_caseD_e;
    case 0xf:
      goto switchD_300aa20c_caseD_f;
    default:
      goto switchD_300aa20c_default;
    }
    return;
  }
  puVar1 = param_1;
  puVar2 = param_2;
  uVar3 = param_3;
  switch(param_3 & 0xf) {
  case 1:
    while( true ) {
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
      param_3 = uVar3 - 0x10;
      if (param_3 == 0 || (int)uVar3 < 0x10) break;
switchD_300aa2a8_default:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa2a8_caseD_f:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa2a8_caseD_e:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa2a8_caseD_d:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa2a8_caseD_c:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa2a8_caseD_b:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa2a8_caseD_a:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa2a8_caseD_9:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa2a8_caseD_8:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa2a8_caseD_7:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa2a8_caseD_6:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa2a8_caseD_5:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa2a8_caseD_4:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa2a8_caseD_3:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa2a8_caseD_2:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
      uVar3 = param_3;
    }
    break;
  case 2:
    goto switchD_300aa2a8_caseD_2;
  case 3:
    goto switchD_300aa2a8_caseD_3;
  case 4:
    goto switchD_300aa2a8_caseD_4;
  case 5:
    goto switchD_300aa2a8_caseD_5;
  case 6:
    goto switchD_300aa2a8_caseD_6;
  case 7:
    goto switchD_300aa2a8_caseD_7;
  case 8:
    goto switchD_300aa2a8_caseD_8;
  case 9:
    goto switchD_300aa2a8_caseD_9;
  case 10:
    goto switchD_300aa2a8_caseD_a;
  case 0xb:
    goto switchD_300aa2a8_caseD_b;
  case 0xc:
    goto switchD_300aa2a8_caseD_c;
  case 0xd:
    goto switchD_300aa2a8_caseD_d;
  case 0xe:
    goto switchD_300aa2a8_caseD_e;
  case 0xf:
    goto switchD_300aa2a8_caseD_f;
  default:
    goto switchD_300aa2a8_default;
  }
  return;
}

/* ----------------------------------------------------------------
 * bcopyWords @ 0x300AA338  (примерный размер ~352 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AA338
 * ---------------------------------------------------------------- */
void bcopyWords(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  int iVar4;
  
  if (param_3 == 0) {
    return;
  }
  iVar4 = (int)param_2 - (int)param_1;
  if (iVar4 == 0) {
    return;
  }
  if (((int)param_1 <= (int)param_2) &&
     ((int)(iVar4 + param_3 * -2) < 0 != SBORROW4(iVar4,param_3 * 2))) {
    param_2 = param_2 + param_3;
    param_1 = param_1 + param_3;
    uVar3 = param_3;
    switch(param_3 & 0xf) {
    case 1:
      while( true ) {
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
        param_3 = uVar3 - 0x10;
        if (param_3 == 0 || (int)uVar3 < 0x10) break;
switchD_300aa36c_default:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_f:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_e:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_d:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_c:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_b:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_a:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_9:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_8:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_7:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_6:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_5:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_4:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_3:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
switchD_300aa36c_caseD_2:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
        uVar3 = param_3;
      }
      break;
    case 2:
      goto switchD_300aa36c_caseD_2;
    case 3:
      goto switchD_300aa36c_caseD_3;
    case 4:
      goto switchD_300aa36c_caseD_4;
    case 5:
      goto switchD_300aa36c_caseD_5;
    case 6:
      goto switchD_300aa36c_caseD_6;
    case 7:
      goto switchD_300aa36c_caseD_7;
    case 8:
      goto switchD_300aa36c_caseD_8;
    case 9:
      goto switchD_300aa36c_caseD_9;
    case 10:
      goto switchD_300aa36c_caseD_a;
    case 0xb:
      goto switchD_300aa36c_caseD_b;
    case 0xc:
      goto switchD_300aa36c_caseD_c;
    case 0xd:
      goto switchD_300aa36c_caseD_d;
    case 0xe:
      goto switchD_300aa36c_caseD_e;
    case 0xf:
      goto switchD_300aa36c_caseD_f;
    default:
      goto switchD_300aa36c_default;
    }
    return;
  }
  puVar1 = param_1;
  puVar2 = param_2;
  uVar3 = param_3;
  switch(param_3 & 0xf) {
  case 1:
    while( true ) {
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
      param_3 = uVar3 - 0x10;
      if (param_3 == 0 || (int)uVar3 < 0x10) break;
switchD_300aa408_default:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa408_caseD_f:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa408_caseD_e:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa408_caseD_d:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa408_caseD_c:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa408_caseD_b:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa408_caseD_a:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa408_caseD_9:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa408_caseD_8:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa408_caseD_7:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa408_caseD_6:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa408_caseD_5:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa408_caseD_4:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
switchD_300aa408_caseD_3:
      param_1 = puVar1 + 1;
      param_2 = puVar2 + 1;
      *puVar2 = *puVar1;
switchD_300aa408_caseD_2:
      puVar1 = param_1 + 1;
      puVar2 = param_2 + 1;
      *param_2 = *param_1;
      uVar3 = param_3;
    }
    break;
  case 2:
    goto switchD_300aa408_caseD_2;
  case 3:
    goto switchD_300aa408_caseD_3;
  case 4:
    goto switchD_300aa408_caseD_4;
  case 5:
    goto switchD_300aa408_caseD_5;
  case 6:
    goto switchD_300aa408_caseD_6;
  case 7:
    goto switchD_300aa408_caseD_7;
  case 8:
    goto switchD_300aa408_caseD_8;
  case 9:
    goto switchD_300aa408_caseD_9;
  case 10:
    goto switchD_300aa408_caseD_a;
  case 0xb:
    goto switchD_300aa408_caseD_b;
  case 0xc:
    goto switchD_300aa408_caseD_c;
  case 0xd:
    goto switchD_300aa408_caseD_d;
  case 0xe:
    goto switchD_300aa408_caseD_e;
  case 0xf:
    goto switchD_300aa408_caseD_f;
  default:
    goto switchD_300aa408_default;
  }
  return;
}

/* ----------------------------------------------------------------
 * bcopyLongs @ 0x300AA498  (примерный размер ~316 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AA498
 * ---------------------------------------------------------------- */
undefined8 bcopyLongs(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  iVar6 = (int)param_2 - (int)param_1;
  if (iVar6 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (((int)param_2 < (int)param_1) || (iVar6 + param_3 * -4 < 0 == SBORROW4(iVar6,param_3 * 4))) {
    iVar5 = param_3 + -0x10;
    iVar6 = iVar5;
    if (0xf < param_3) {
      do {
        uVar7 = param_1[1];
        uVar8 = param_1[2];
        uVar9 = param_1[3];
        *param_2 = *param_1;
        param_2[1] = uVar7;
        param_2[2] = uVar8;
        param_2[3] = uVar9;
        uVar7 = param_1[5];
        uVar8 = param_1[6];
        uVar9 = param_1[7];
        param_2[4] = param_1[4];
        param_2[5] = uVar7;
        param_2[6] = uVar8;
        param_2[7] = uVar9;
        uVar7 = param_1[9];
        uVar8 = param_1[10];
        uVar9 = param_1[0xb];
        puVar11 = param_1 + 0xc;
        param_2[8] = param_1[8];
        param_2[9] = uVar7;
        param_2[10] = uVar8;
        param_2[0xb] = uVar9;
        uVar7 = param_1[0xd];
        uVar8 = param_1[0xe];
        uVar9 = param_1[0xf];
        param_1 = param_1 + 0x10;
        param_2[0xc] = *puVar11;
        param_2[0xd] = uVar7;
        param_2[0xe] = uVar8;
        param_2[0xf] = uVar9;
        param_2 = param_2 + 0x10;
        iVar5 = iVar6 + -0x10;
        bVar1 = 0xf < iVar6;
        iVar6 = iVar5;
      } while (bVar1);
    }
    iVar5 = iVar5 + 0x10;
    if (iVar5 != 0) {
      iVar6 = iVar5 >> 2;
      if (iVar6 != 0) {
        iVar5 = iVar5 + iVar6 * -4;
        uVar7 = param_1[1];
        uVar8 = param_1[2];
        uVar9 = param_1[3];
        puVar11 = param_1 + 4;
        *param_2 = *param_1;
        param_2[1] = uVar7;
        param_2[2] = uVar8;
        param_2[3] = uVar9;
        puVar3 = param_2 + 4;
        if (1 < iVar6) {
          uVar7 = *puVar11;
          uVar8 = param_1[5];
          uVar9 = param_1[6];
          uVar10 = param_1[7];
          puVar11 = param_1 + 8;
          param_2[4] = uVar7;
          param_2[5] = uVar8;
          param_2[6] = uVar9;
          param_2[7] = uVar10;
          puVar3 = param_2 + 8;
        }
        param_2 = puVar3;
        param_1 = puVar11;
        if (2 < iVar6) {
          uVar7 = puVar11[1];
          uVar8 = puVar11[2];
          uVar9 = puVar11[3];
          param_1 = puVar11 + 4;
          *param_2 = *puVar11;
          param_2[1] = uVar7;
          param_2[2] = uVar8;
          param_2[3] = uVar9;
          param_2 = param_2 + 4;
        }
        if (iVar5 == 0) {
          return CONCAT44(param_2,param_1);
        }
      }
      *param_2 = *param_1;
      puVar3 = param_2 + 1;
      puVar11 = param_1 + 1;
      if (1 < iVar5) {
        puVar11 = param_1 + 2;
        puVar3 = param_2 + 2;
        param_2[1] = param_1[1];
      }
      puVar4 = puVar3;
      puVar2 = puVar11;
      if (2 < iVar5) {
        puVar2 = puVar11 + 1;
        puVar4 = puVar3 + 1;
        *puVar3 = *puVar11;
      }
      return CONCAT44(puVar4,puVar2);
    }
    return CONCAT44(param_2,param_1);
  }
  param_2 = param_2 + param_3;
  param_1 = param_1 + param_3;
  iVar5 = param_3 + -0x10;
  iVar6 = iVar5;
  if (0xf < param_3) {
    do {
      uVar9 = param_1[-2];
      uVar8 = param_1[-3];
      uVar7 = param_1[-4];
      param_2[-1] = param_1[-1];
      param_2[-2] = uVar9;
      param_2[-3] = uVar8;
      param_2[-4] = uVar7;
      uVar9 = param_1[-6];
      uVar8 = param_1[-7];
      uVar7 = param_1[-8];
      param_2[-5] = param_1[-5];
      param_2[-6] = uVar9;
      param_2[-7] = uVar8;
      param_2[-8] = uVar7;
      uVar9 = param_1[-10];
      uVar8 = param_1[-0xb];
      uVar7 = param_1[-0xc];
      param_2[-9] = param_1[-9];
      param_2[-10] = uVar9;
      param_2[-0xb] = uVar8;
      param_2[-0xc] = uVar7;
      puVar11 = param_1 + -0xd;
      uVar9 = param_1[-0xe];
      uVar8 = param_1[-0xf];
      param_1 = param_1 + -0x10;
      uVar7 = *param_1;
      param_2[-0xd] = *puVar11;
      param_2[-0xe] = uVar9;
      param_2[-0xf] = uVar8;
      param_2 = param_2 + -0x10;
      *param_2 = uVar7;
      iVar5 = iVar6 + -0x10;
      bVar1 = 0xf < iVar6;
      iVar6 = iVar5;
    } while (bVar1);
  }
  iVar5 = iVar5 + 0x10;
  if (iVar5 != 0) {
    iVar6 = iVar5 >> 2;
    if (iVar6 != 0) {
      iVar5 = iVar5 + iVar6 * -4;
      uVar9 = param_1[-2];
      uVar8 = param_1[-3];
      puVar11 = param_1 + -4;
      uVar7 = *puVar11;
      param_2[-1] = param_1[-1];
      param_2[-2] = uVar9;
      param_2[-3] = uVar8;
      param_2[-4] = uVar7;
      puVar3 = param_2 + -4;
      if (1 < iVar6) {
        uVar9 = param_1[-6];
        uVar8 = param_1[-7];
        puVar11 = param_1 + -8;
        uVar7 = *puVar11;
        param_2[-5] = param_1[-5];
        param_2[-6] = uVar9;
        param_2[-7] = uVar8;
        param_2[-8] = uVar7;
        puVar3 = param_2 + -8;
      }
      param_2 = puVar3;
      param_1 = puVar11;
      if (2 < iVar6) {
        uVar9 = puVar11[-2];
        uVar8 = puVar11[-3];
        param_1 = puVar11 + -4;
        uVar7 = *param_1;
        param_2[-1] = puVar11[-1];
        param_2[-2] = uVar9;
        param_2[-3] = uVar8;
        param_2 = param_2 + -4;
        *param_2 = uVar7;
      }
      if (iVar5 == 0) {
        return CONCAT44(param_2,param_1);
      }
    }
    puVar11 = param_1 + -1;
    puVar3 = param_2 + -1;
    *puVar3 = *puVar11;
    if (1 < iVar5) {
      puVar11 = param_1 + -2;
      puVar3 = param_2 + -2;
      *puVar3 = *puVar11;
    }
    if (2 < iVar5) {
      puVar11 = puVar11 + -1;
      puVar3 = puVar3 + -1;
      *puVar3 = *puVar11;
    }
    return CONCAT44(puVar3,puVar11);
  }
  return CONCAT44(param_2,param_1);
}

/* ----------------------------------------------------------------
 * bfill @ 0x300AA5D4  (примерный размер ~188 байт)
 * Модуль: lib | Вызывают: 15 | Вызывает: 0
 * Вызывают: FUN_300ac39c, FUN_300ad5ec, FUN_300d9028, FUN_300daffc, bzero, exchMemShow, fat16ClustValueSet, kernelInit, loadShareTgtMemSet, memPartInit
 *           ...
 * Константы: 0x300AA5D4
 * ---------------------------------------------------------------- */
uint * bfill(uint *param_1,int param_2,uint param_3)

{
  undefined1 uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  
  param_2 = param_2 + -4;
  iVar5 = param_2;
  if (-1 < param_2) {
    if (((uint)param_1 & 3) != 0) {
      iVar5 = -((uint)param_1 & 3);
      iVar4 = iVar5 + 4;
      uVar1 = (undefined1)param_3;
      *(undefined1 *)param_1 = uVar1;
      puVar2 = (uint *)((int)param_1 + 1);
      if (1 < iVar4) {
        puVar2 = (uint *)((int)param_1 + 2);
        *(undefined1 *)((int)param_1 + 1) = uVar1;
      }
      param_1 = puVar2;
      if (iVar4 != 2 && iVar5 + 2 < 0 == SBORROW4(iVar4,2)) {
        param_1 = (uint *)((int)puVar2 + 1);
        *(undefined1 *)puVar2 = uVar1;
      }
      iVar5 = param_2 - iVar4;
      if (param_2 < iVar4) goto LAB_300aa654;
    }
    param_3 = param_3 & 0xff | (param_3 & 0xff) << 8;
    param_3 = param_3 | param_3 << 0x10;
    iVar4 = iVar5 + -8;
    if (7 < iVar5) {
      iVar5 = iVar5 + -0x1c;
      if (0x13 < iVar4) {
        do {
          iVar4 = iVar5;
          puVar2 = param_1;
          *puVar2 = param_3;
          puVar2[1] = param_3;
          puVar2[2] = param_3;
          puVar2[3] = param_3;
          puVar2[4] = param_3;
          puVar2[5] = param_3;
          puVar2[6] = param_3;
          puVar2[7] = param_3;
          param_1 = puVar2 + 8;
          iVar5 = iVar4 + -0x20;
        } while (0x1f < iVar4);
        if (iVar4 + -0x10 < 0 == SCARRY4(iVar5,0x10)) {
          *param_1 = param_3;
          puVar2[9] = param_3;
          puVar2[10] = param_3;
          puVar2[0xb] = param_3;
          param_1 = puVar2 + 0xc;
          iVar5 = iVar4 + -0x30;
        }
      }
      bVar8 = SCARRY4(iVar5,0x14);
      iVar4 = iVar5 + 0x14;
      bVar7 = iVar4 < 0;
      do {
        if (bVar7 == bVar8) {
          *param_1 = param_3;
          param_1[1] = param_3;
          param_1[2] = param_3;
          param_1 = param_1 + 3;
          bVar8 = SBORROW4(iVar4,0xc);
          iVar4 = iVar4 + -0xc;
          bVar7 = iVar4 < 0;
        }
      } while (bVar7 == bVar8);
    }
    iVar6 = iVar4 + 8;
    iVar5 = iVar6;
    if (iVar6 < 0 == SCARRY4(iVar4,8)) {
      if (iVar6 < 4) {
        *param_1 = param_3;
        param_1 = param_1 + 1;
      }
      iVar5 = iVar4 + 4;
      if (iVar4 + 4 < 0 == SBORROW4(iVar6,4)) {
        *param_1 = param_3;
        param_1[1] = param_3;
        param_1 = param_1 + 2;
        iVar5 = iVar4;
      }
    }
  }
LAB_300aa654:
  iVar4 = iVar5 + 4;
  if (iVar5 == -4) {
    return param_1;
  }
  uVar1 = (undefined1)param_3;
  *(undefined1 *)param_1 = uVar1;
  puVar2 = (uint *)((int)param_1 + 1);
  if (1 < iVar4) {
    puVar2 = (uint *)((int)param_1 + 2);
    *(undefined1 *)((int)param_1 + 1) = uVar1;
  }
  puVar3 = puVar2;
  if (iVar4 != 2 && iVar5 + 2 < 0 == SBORROW4(iVar4,2)) {
    puVar3 = (uint *)((int)puVar2 + 1);
    *(undefined1 *)puVar2 = uVar1;
  }
  return puVar3;
}

/* ----------------------------------------------------------------
 * bfillBytes @ 0x300AA690  (примерный размер ~112 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 0
 * Константы: 0x300AA690
 * ---------------------------------------------------------------- */
void bfillBytes(undefined1 *param_1,uint param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    puVar1 = param_1;
    uVar2 = param_2;
    switch(param_2 & 0xf) {
    case 1:
      while( true ) {
        param_1 = puVar1 + 1;
        *puVar1 = param_3;
        param_2 = uVar2 - 0x10;
        if (param_2 == 0 || (int)uVar2 < 0x10) break;
switchD_300aa6a4_default:
        puVar1 = param_1 + 1;
        *param_1 = param_3;
switchD_300aa6a4_caseD_f:
        param_1 = puVar1 + 1;
        *puVar1 = param_3;
switchD_300aa6a4_caseD_e:
        puVar1 = param_1 + 1;
        *param_1 = param_3;
switchD_300aa6a4_caseD_d:
        param_1 = puVar1 + 1;
        *puVar1 = param_3;
switchD_300aa6a4_caseD_c:
        puVar1 = param_1 + 1;
        *param_1 = param_3;
switchD_300aa6a4_caseD_b:
        param_1 = puVar1 + 1;
        *puVar1 = param_3;
switchD_300aa6a4_caseD_a:
        puVar1 = param_1 + 1;
        *param_1 = param_3;
switchD_300aa6a4_caseD_9:
        param_1 = puVar1 + 1;
        *puVar1 = param_3;
switchD_300aa6a4_caseD_8:
        puVar1 = param_1 + 1;
        *param_1 = param_3;
switchD_300aa6a4_caseD_7:
        param_1 = puVar1 + 1;
        *puVar1 = param_3;
switchD_300aa6a4_caseD_6:
        puVar1 = param_1 + 1;
        *param_1 = param_3;
switchD_300aa6a4_caseD_5:
        param_1 = puVar1 + 1;
        *puVar1 = param_3;
switchD_300aa6a4_caseD_4:
        puVar1 = param_1 + 1;
        *param_1 = param_3;
switchD_300aa6a4_caseD_3:
        param_1 = puVar1 + 1;
        *puVar1 = param_3;
switchD_300aa6a4_caseD_2:
        puVar1 = param_1 + 1;
        *param_1 = param_3;
        uVar2 = param_2;
      }
      break;
    case 2:
      goto switchD_300aa6a4_caseD_2;
    case 3:
      goto switchD_300aa6a4_caseD_3;
    case 4:
      goto switchD_300aa6a4_caseD_4;
    case 5:
      goto switchD_300aa6a4_caseD_5;
    case 6:
      goto switchD_300aa6a4_caseD_6;
    case 7:
      goto switchD_300aa6a4_caseD_7;
    case 8:
      goto switchD_300aa6a4_caseD_8;
    case 9:
      goto switchD_300aa6a4_caseD_9;
    case 10:
      goto switchD_300aa6a4_caseD_a;
    case 0xb:
      goto switchD_300aa6a4_caseD_b;
    case 0xc:
      goto switchD_300aa6a4_caseD_c;
    case 0xd:
      goto switchD_300aa6a4_caseD_d;
    case 0xe:
      goto switchD_300aa6a4_caseD_e;
    case 0xf:
      goto switchD_300aa6a4_caseD_f;
    default:
      goto switchD_300aa6a4_default;
    }
    return;
  }
  return;
}

/* ----------------------------------------------------------------
 * __rt_fp_status_addr @ 0x300AF140  (примерный размер ~8 байт)
 * Модуль: lib | Вызывают: 19 | Вызывает: 0
 * Вызывают: __32__ieee_status, __addsf3, __divdf3, __divsf3, __dunder, __dunder_d, __extendsfdf2, __fpl_cmpreturn, __fpl_exception, __fpl_fcheck_NaN2
 *           ...
 * Константы: 0x300AF140
 * Данные: DAT_300af14c
 * ---------------------------------------------------------------- */
undefined4 __rt_fp_status_addr(void)

{
  return DAT_300af14c;
}

/* ----------------------------------------------------------------
 * acos @ 0x300AF150  (примерный размер ~2264 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 5
 * Вызывает: __adddf3, __divdf3, __muldf3, __subdf3, _dsqrt
 * Константы: 0x40000000, 0x300AF150, 0x7FFFFFFF
 * Данные: DAT_300af9b8, DAT_300af9bc, DAT_300af9c0, DAT_300af9c4, DAT_300af9c8, DAT_300af9cc, DAT_300af9d0, DAT_300af9d4
 * ---------------------------------------------------------------- */
double acos(double __x)

{
  uint uVar1;
  int in_r0;
  undefined4 uVar2;
  uint in_r1;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  double in_d0;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar1 = DAT_300af9b8;
  uVar5 = in_r1 & 0x7fffffff;
  if ((int)uVar5 < (int)DAT_300af9b8) {
    if ((int)uVar5 < DAT_300af9c4) {
      if (DAT_300af9c8 < (int)uVar5) {
        uVar6 = __muldf3();
        uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
        uVar2 = (undefined4)uVar6;
        uVar6 = __muldf3(uVar2,uVar3,DAT_300af9d4,DAT_300af9d0);
        uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300af9dc,DAT_300af9d8);
        uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
        uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300af9e4,DAT_300af9e0);
        uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
        uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300af9ec,DAT_300af9e8);
        uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
        uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300af9f4,DAT_300af9f0);
        uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
        uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300af9fc,DAT_300af9f8);
        uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
        uVar7 = __muldf3(uVar2,uVar3,DAT_300afa04,DAT_300afa00);
        uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300afa0c,DAT_300afa08);
        uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar3);
        uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300afa14,DAT_300afa10);
        uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar3);
        uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300afa1c,DAT_300afa18);
        uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar3);
        uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,DAT_300af9b8);
        uVar6 = __divdf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar7,
                         (int)((ulonglong)uVar7 >> 0x20));
        uVar6 = __muldf3(in_r0,in_r1,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
        uVar6 = __subdf3(DAT_300afa24,DAT_300afa20,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
        uVar6 = __subdf3(in_r0,in_r1,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
        in_d0 = (double)__subdf3(DAT_300af9c0,DAT_300af9cc,(int)uVar6,
                                 (int)((ulonglong)uVar6 >> 0x20));
      }
    }
    else if ((int)in_r1 < 0) {
      uVar6 = __adddf3(in_r0,in_r1,0,DAT_300af9b8);
      uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,DAT_300af9c4);
      uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
      uVar2 = (undefined4)uVar6;
      uVar6 = __muldf3(uVar2,uVar3,DAT_300af9d4,DAT_300af9d0);
      uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300af9dc,DAT_300af9d8);
      uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
      uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300af9e4,DAT_300af9e0);
      uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
      uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300af9ec,DAT_300af9e8);
      uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
      uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300af9f4,DAT_300af9f0);
      uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
      uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300af9fc,DAT_300af9f8);
      uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar2,uVar3);
      uVar7 = __muldf3(uVar2,uVar3,DAT_300afa04,DAT_300afa00);
      uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300afa0c,DAT_300afa08);
      uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar3);
      uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300afa14,DAT_300afa10);
      uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar3);
      uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300afa1c,DAT_300afa18);
      uVar7 = __muldf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar3);
      uVar7 = __adddf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,uVar1);
      uVar8 = _dsqrt(uVar2,uVar3);
      uVar2 = (undefined4)((ulonglong)uVar8 >> 0x20);
      uVar6 = __divdf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar7,
                       (int)((ulonglong)uVar7 >> 0x20));
      uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar8,uVar2);
      uVar6 = __subdf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_300afa24,DAT_300afa20);
      uVar6 = __adddf3((int)uVar8,uVar2,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
      uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x40000000);
      in_d0 = (double)__subdf3(DAT_300af9c0,DAT_300af9bc,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20))
      ;
    }
    else {
      uVar6 = __subdf3(0,DAT_300af9b8);
      uVar6 = __muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,DAT_300af9c4);
      uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
      uVar2 = (undefined4)uVar6;
      uVar6 = _dsqrt();
      uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
      __muldf3(0,uVar4,0,uVar4);
      uVar7 = __adddf3((int)uVar6,uVar4);
      uVar8 = __subdf3(uVar2,uVar3);
      uVar7 = __divdf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,
                       (int)((ulonglong)uVar7 >> 0x20));
      uVar8 = __muldf3(uVar2,uVar3,DAT_300af9d4,DAT_300af9d0);
      uVar8 = __adddf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_300af9dc,DAT_300af9d8);
      uVar8 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar2,uVar3);
      uVar8 = __adddf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_300af9e4,DAT_300af9e0);
      uVar8 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar2,uVar3);
      uVar8 = __adddf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_300af9ec,DAT_300af9e8);
      uVar8 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar2,uVar3);
      uVar8 = __adddf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_300af9f4,DAT_300af9f0);
      uVar8 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar2,uVar3);
      uVar8 = __adddf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_300af9fc,DAT_300af9f8);
      uVar8 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar2,uVar3);
      uVar9 = __muldf3(uVar2,uVar3,DAT_300afa04,DAT_300afa00);
      uVar9 = __adddf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_300afa0c,DAT_300afa08);
      uVar9 = __muldf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar2,uVar3);
      uVar9 = __adddf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_300afa14,DAT_300afa10);
      uVar9 = __muldf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar2,uVar3);
      uVar9 = __adddf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_300afa1c,DAT_300afa18);
      uVar9 = __muldf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar2,uVar3);
      uVar9 = __adddf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,uVar1);
      uVar8 = __divdf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar9,
                       (int)((ulonglong)uVar9 >> 0x20));
      uVar6 = __muldf3((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar6,uVar4);
      uVar6 = __adddf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar7,
                       (int)((ulonglong)uVar7 >> 0x20));
      uVar6 = __adddf3(0,uVar4,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
      in_d0 = (double)__muldf3((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x40000000);
    }
  }
  else if (in_r0 != 0 || uVar5 != DAT_300af9b8) {
    uVar6 = __subdf3();
    uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
    in_d0 = (double)__divdf3((int)uVar6,uVar2,(int)uVar6,uVar2);
  }
  return in_d0;
}

/* ----------------------------------------------------------------
 * asin @ 0x300AFA28  (примерный размер ~2048 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 7
 * Вызывает: __adddf3, __divdf3, __muldf3, __subdf3, _d_fngt, _dsqrt, fabs
 * Константы: 0x40000000, 0x300AFA28, 0x7FFFFFFF, 0x3E3FFFFF
 * Данные: DAT_300b01b0, DAT_300b01b4, DAT_300b01b8, DAT_300b01bc, DAT_300b01c0, DAT_300b01c4, DAT_300b01c8, DAT_300b01cc
 * ---------------------------------------------------------------- */
double asin(double __x)

{
  uint uVar1;
  int in_r0;
  int iVar2;
  undefined4 uVar3;
  uint in_r1;
  undefined4 uVar4;
  undefined4 extraout_r1;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  double dVar9;
  double extraout_d0;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  double in_stack_ffffff8c;
  
  uVar8 = in_r1 & 0x7fffffff;
  if ((int)DAT_300b01b0 <= (int)uVar8) {
    if (in_r0 == 0 && uVar8 == DAT_300b01b0) {
      uVar10 = __muldf3(in_r0,in_r1,DAT_300b01b8,DAT_300b01b4);
      uVar11 = __muldf3();
      dVar9 = (double)__adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar10,
                               (int)((ulonglong)uVar10 >> 0x20));
      return dVar9;
    }
    uVar10 = __subdf3();
    uVar3 = (undefined4)((ulonglong)uVar10 >> 0x20);
    dVar9 = (double)__divdf3((int)uVar10,uVar3,(int)uVar10,uVar3);
    return dVar9;
  }
  if ((int)uVar8 < DAT_300b01c4) {
    if (0x3e3fffff < uVar8) {
      uVar10 = __muldf3();
      uVar4 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar3 = (undefined4)uVar10;
      uVar10 = __muldf3(uVar3,uVar4,DAT_300b01d4,DAT_300b01d0);
      uVar10 = __adddf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_300b01dc,DAT_300b01d8);
      uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar3,uVar4);
      uVar10 = __adddf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_300b01e4,DAT_300b01e0);
      uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar3,uVar4);
      uVar10 = __adddf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_300b01ec,DAT_300b01e8);
      uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar3,uVar4);
      uVar10 = __adddf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_300b01f4,DAT_300b01f0);
      uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar3,uVar4);
      uVar10 = __adddf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_300b01fc,DAT_300b01f8);
      uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar3,uVar4);
      uVar11 = __muldf3(uVar3,uVar4,DAT_300b0204,DAT_300b0200);
      uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b020c,DAT_300b0208);
      uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar4);
      uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b0214,DAT_300b0210);
      uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar4);
      uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b021c,DAT_300b0218);
      uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar4);
      uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_300b01b0);
      __divdf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
               (int)((ulonglong)uVar11 >> 0x20));
      __muldf3();
      dVar9 = (double)__adddf3();
      return dVar9;
    }
    uVar10 = __adddf3(in_r0,in_r1,DAT_300b01cc,DAT_300b01c8);
    iVar2 = _d_fngt((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,DAT_300b01b0);
    if (iVar2 == 0) {
      return extraout_d0;
    }
  }
  fabs(in_stack_ffffff8c);
  uVar1 = DAT_300b01b0;
  uVar10 = __subdf3(0,DAT_300b01b0,in_r0,extraout_r1);
  uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,DAT_300b01c4);
  uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
  uVar3 = (undefined4)uVar10;
  uVar10 = __muldf3(uVar3,uVar5,DAT_300b01d4,DAT_300b01d0);
  uVar10 = __adddf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_300b01dc,DAT_300b01d8);
  uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar3,uVar5);
  uVar10 = __adddf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_300b01e4,DAT_300b01e0);
  uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar3,uVar5);
  uVar10 = __adddf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_300b01ec,DAT_300b01e8);
  uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar3,uVar5);
  uVar10 = __adddf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_300b01f4,DAT_300b01f0);
  uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar3,uVar5);
  uVar10 = __adddf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_300b01fc,DAT_300b01f8);
  uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar3,uVar5);
  uVar6 = (undefined4)((ulonglong)uVar10 >> 0x20);
  uVar11 = __muldf3(uVar3,uVar5,DAT_300b0204,DAT_300b0200);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b020c,DAT_300b0208);
  uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar5);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b0214,DAT_300b0210);
  uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar5);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b021c,DAT_300b0218);
  uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar5);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,uVar1);
  uVar12 = _dsqrt(uVar3,uVar5);
  uVar7 = (undefined4)((ulonglong)uVar12 >> 0x20);
  uVar4 = (undefined4)uVar12;
  if ((int)uVar8 < DAT_300b0220) {
    __muldf3(0,uVar7,0,uVar7);
    uVar11 = __adddf3(uVar4,uVar7,0,uVar7);
    uVar12 = __subdf3(uVar3,uVar5);
    uVar11 = __divdf3((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar11,
                      (int)((ulonglong)uVar11 >> 0x20));
    uVar10 = __divdf3((int)uVar10,uVar6);
    uVar10 = __muldf3(uVar4,uVar7,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,0x40000000);
    uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,0x40000000);
    uVar11 = __subdf3(DAT_300b01c0,DAT_300b01bc,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
    uVar10 = __subdf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                      (int)((ulonglong)uVar11 >> 0x20));
    uVar11 = __muldf3(0,uVar7,0,0x40000000);
    uVar4 = DAT_300b0224;
    uVar3 = DAT_300b01b8;
    uVar11 = __subdf3(DAT_300b01b8,DAT_300b0224,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
    uVar10 = __subdf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                      (int)((ulonglong)uVar11 >> 0x20));
    dVar9 = (double)__subdf3(uVar3,uVar4,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
  }
  else {
    uVar10 = __divdf3((int)uVar10,uVar6,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
    uVar10 = __muldf3(uVar4,uVar7,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    uVar10 = __adddf3(uVar4,uVar7,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    uVar10 = __muldf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,0x40000000);
    uVar10 = __subdf3((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_300b01c0,DAT_300b01bc);
    dVar9 = (double)__subdf3(DAT_300b01b8,DAT_300b01b4,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20))
    ;
  }
  return dVar9;
}

/* ----------------------------------------------------------------
 * atan @ 0x300B0228  (примерный размер ~1460 байт)
 * Модуль: lib | Вызывают: 1 | Вызывает: 6
 * Вызывает: __adddf3, __divdf3, __muldf3, __subdf3, _d_fngt, fabs
 * Вызывают: atan2
 * Константы: 0x300B0228, 0x7FFFFFFF, 0x40000000
 * Данные: DAT_300b0740, DAT_300b0744, DAT_300b0754, DAT_300b0758, DAT_300b075c, DAT_300b0760, DAT_300b0764, DAT_300b0768
 * ---------------------------------------------------------------- */
double atan(double __x)

{
  int in_r0;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint in_r1;
  undefined4 extraout_r1;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  double in_d0;
  double dVar8;
  double extraout_d0;
  undefined8 uVar9;
  longlong lVar10;
  undefined8 uVar11;
  double in_stack_ffffff9c;
  int local_5c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar11 = CONCAT44(in_r1,in_r0);
  uVar7 = in_r1 & 0x7fffffff;
  if (DAT_300b0740 <= (int)uVar7) {
    if ((int)uVar7 <= (int)DAT_300b0744) {
      if (uVar7 != DAT_300b0744) {
        return in_d0;
      }
      if (in_r0 == 0) {
        return in_d0;
      }
    }
    dVar8 = (double)__adddf3(in_r0,in_r1);
    return dVar8;
  }
  if ((int)uVar7 < DAT_300b0754) {
    if ((int)uVar7 < DAT_300b0758) {
      uVar9 = __adddf3(in_r0,in_r1,DAT_300b0760,DAT_300b075c);
      iVar1 = _d_fngt((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,DAT_300b0764);
      if (iVar1 == 0) {
        return extraout_d0;
      }
    }
    local_5c = -1;
  }
  else {
    fabs(in_stack_ffffff9c);
    uVar2 = DAT_300b0774;
    uVar11 = CONCAT44(extraout_r1,in_r0);
    if ((int)uVar7 < DAT_300b0768) {
      if ((int)uVar7 < DAT_300b076c) {
        local_5c = 0;
        uVar11 = __muldf3();
        uVar9 = __adddf3(in_r0,extraout_r1,0,0x40000000);
        uVar11 = __subdf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_300b0764);
        uVar11 = __divdf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar9,
                          (int)((ulonglong)uVar9 >> 0x20));
        goto LAB_300b0484;
      }
      local_5c = 1;
      uVar11 = __adddf3();
      lVar10 = __subdf3(in_r0,extraout_r1,0,DAT_300b0764);
    }
    else {
      if ((int)uVar7 < DAT_300b0770) {
        local_5c = 2;
        uVar11 = __muldf3();
        uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_300b0764);
        uVar9 = __subdf3(in_r0,extraout_r1,0,uVar2);
        uVar11 = __divdf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),(int)uVar11,
                          (int)((ulonglong)uVar11 >> 0x20));
        goto LAB_300b0484;
      }
      local_5c = 3;
      lVar10 = (ulonglong)DAT_300b0778 << 0x20;
    }
    uVar11 = __divdf3((int)lVar10,(int)((ulonglong)lVar10 >> 0x20),(int)uVar11,
                      (int)((ulonglong)uVar11 >> 0x20));
  }
LAB_300b0484:
  local_4 = (undefined4)((ulonglong)uVar11 >> 0x20);
  local_8 = (undefined4)uVar11;
  uVar11 = __muldf3(local_8,local_4);
  uVar4 = (undefined4)((ulonglong)uVar11 >> 0x20);
  uVar2 = (undefined4)uVar11;
  uVar11 = __muldf3(uVar2,uVar4,uVar2,uVar4);
  uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
  uVar3 = (undefined4)uVar11;
  uVar11 = __muldf3(uVar3,uVar5,DAT_300b0780,DAT_300b077c);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b0788,DAT_300b0784);
  uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar5);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b0790,DAT_300b078c);
  uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar5);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b0798,DAT_300b0794);
  uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar5);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b07a0,DAT_300b079c);
  uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar3,uVar5);
  uVar11 = __adddf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_300b07a8,DAT_300b07a4);
  uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),uVar2,uVar4);
  uVar2 = (undefined4)((ulonglong)uVar11 >> 0x20);
  uVar9 = __muldf3(uVar3,uVar5,DAT_300b07b0,DAT_300b07ac);
  uVar9 = __adddf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_300b07b8,DAT_300b07b4);
  uVar9 = __muldf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar3,uVar5);
  uVar9 = __adddf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_300b07c0,DAT_300b07bc);
  uVar9 = __muldf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar3,uVar5);
  uVar9 = __adddf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_300b07c8,DAT_300b07c4);
  uVar9 = __muldf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar3,uVar5);
  uVar9 = __adddf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_300b07d0,DAT_300b07cc);
  uVar9 = __muldf3((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar3,uVar5);
  uVar3 = (undefined4)((ulonglong)uVar9 >> 0x20);
  if (local_5c < 0) {
    uVar11 = __adddf3((int)uVar11,uVar2,(int)uVar9,uVar3);
    uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),local_8,local_4);
    dVar8 = (double)__subdf3(local_8,local_4,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
  }
  else {
    puVar6 = (undefined4 *)(DAT_300b07d4 + local_5c * 8);
    uVar4 = *puVar6;
    uVar5 = puVar6[1];
    uVar11 = __adddf3((int)uVar11,uVar2,(int)uVar9,uVar3);
    uVar11 = __muldf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),local_8,local_4);
    puVar6 = (undefined4 *)(DAT_300b07d8 + local_5c * 8);
    uVar11 = __subdf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),*puVar6,puVar6[1]);
    uVar11 = __subdf3((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),local_8,local_4);
    dVar8 = (double)__subdf3(uVar4,uVar5,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
  }
  return dVar8;
}

/* ----------------------------------------------------------------
 * atan2 @ 0x300B07DC  (примерный размер ~848 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 5
 * Вызывает: __adddf3, __divdf3, __subdf3, atan, fabs
 * Константы: 0x7FFFFFFF, 0x300B07DC
 * Данные: DAT_300b0af4, DAT_300b0af8, DAT_300b0afc, DAT_300b0b00, DAT_300b0b0c, DAT_300b0b24, DAT_300b0b28
 * ---------------------------------------------------------------- */
/* WARNING: Type propagation algorithm not settling */

double atan2(double __y,double __x)

{
  int iVar1;
  uint in_r0;
  undefined4 uVar2;
  uint in_r1;
  undefined4 extraout_r1;
  uint in_r2;
  uint in_r3;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  double in_d0;
  undefined8 uVar7;
  double in_stack_ffffff9c;
  
  uVar5 = in_r3 & 0x7fffffff;
  uVar6 = in_r1 & 0x7fffffff;
  if ((DAT_300b0af4 < (uVar5 | (in_r2 | -in_r2) >> 0x1f)) ||
     (DAT_300b0af4 < (uVar6 | (in_r0 | -in_r0) >> 0x1f))) {
    in_d0 = (double)__adddf3();
  }
  else if (in_r2 == 0 && in_r3 == DAT_300b0af8) {
    in_d0 = atan(in_stack_ffffff9c);
  }
  else {
    uVar3 = (int)in_r1 >> 0x1f & 1U | (int)in_r3 >> 0x1e & 2U;
    if (((((uVar6 != 0 || in_r0 != 0) ||
          ((((uVar3 != 0 && (uVar3 != 1)) && (uVar3 != 2)) && (uVar3 != 3)))) &&
         (uVar5 != 0 || in_r2 != 0)) &&
        ((uVar5 != DAT_300b0af4 ||
         (((uVar3 != 0 && (uVar3 != 1)) && ((uVar3 != 2 && (uVar3 != 3)))))))) &&
       (uVar6 != DAT_300b0af4)) {
      iVar1 = (int)(uVar6 - uVar5) >> 0x14;
      uVar2 = DAT_300b0b00;
      uVar4 = DAT_300b0b0c;
      if (iVar1 < 0x3d) {
        if (((int)in_r3 < 0) && (iVar1 + 0x3c < 0 != SCARRY4(iVar1,0x3c))) {
          uVar2 = 0;
          uVar4 = 0;
        }
        else {
          uVar2 = __divdf3(in_r0,in_r1);
          fabs(in_stack_ffffff9c);
          in_d0 = atan(in_stack_ffffff9c);
          uVar4 = extraout_r1;
        }
      }
      if ((uVar3 != 0) && (uVar3 != 1)) {
        if (uVar3 == 2) {
          uVar7 = __subdf3(uVar2,uVar4,DAT_300b0b28,DAT_300b0b24);
          in_d0 = (double)__subdf3(DAT_300b0b00,DAT_300b0afc,(int)uVar7,
                                   (int)((ulonglong)uVar7 >> 0x20));
        }
        else {
          uVar7 = __subdf3(uVar2,uVar4,DAT_300b0b28,DAT_300b0b24);
          in_d0 = (double)__subdf3((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_300b0b00,
                                   DAT_300b0afc);
        }
      }
    }
  }
  return in_d0;
}

/* ----------------------------------------------------------------
 * cos @ 0x300B0B2C  (примерный размер ~248 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 4
 * Вызывает: __ieee754_rem_pio2, __kernel_cos, __kernel_sin, __subdf3
 * Константы: 0x7FFFFFFF, 0x300B0B2C
 * Данные: DAT_300b0c1c, DAT_300b0c20
 * ---------------------------------------------------------------- */
double cos(double __x)

{
  undefined4 in_r0;
  uint uVar1;
  uint in_r1;
  double dVar2;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  if (DAT_300b0c1c < (int)(in_r1 & 0x7fffffff)) {
    if ((int)(in_r1 & 0x7fffffff) < DAT_300b0c20) {
      uVar1 = __ieee754_rem_pio2(in_r0,in_r1,&local_34);
      uVar1 = uVar1 & 3;
      if (uVar1 == 0) {
        dVar2 = (double)__kernel_cos(local_34,local_30,local_2c,local_28);
      }
      else if (uVar1 == 1) {
        dVar2 = (double)__kernel_sin(local_34,local_30,local_2c,local_28,1);
      }
      else if (uVar1 == 2) {
        dVar2 = (double)__kernel_cos(local_34,local_30,local_2c,local_28);
      }
      else {
        dVar2 = (double)__kernel_sin(local_34,local_30,local_2c,local_28,1);
      }
    }
    else {
      dVar2 = (double)__subdf3();
    }
  }
  else {
    dVar2 = (double)__kernel_cos(in_r0,in_r1,0);
  }
  return dVar2;
}

/* ----------------------------------------------------------------
 * sin @ 0x300B0C24  (примерный размер ~252 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 4
 * Вызывает: __ieee754_rem_pio2, __kernel_cos, __kernel_sin, __subdf3
 * Константы: 0x7FFFFFFF, 0x300B0C24
 * Данные: DAT_300b0d18, DAT_300b0d1c
 * ---------------------------------------------------------------- */
double sin(double __x)

{
  undefined4 in_r0;
  uint uVar1;
  uint in_r1;
  double dVar2;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  if (DAT_300b0d18 < (int)(in_r1 & 0x7fffffff)) {
    if ((int)(in_r1 & 0x7fffffff) < DAT_300b0d1c) {
      uVar1 = __ieee754_rem_pio2(in_r0,in_r1,&local_34);
      uVar1 = uVar1 & 3;
      if (uVar1 == 0) {
        dVar2 = (double)__kernel_sin(local_34,local_30,local_2c,local_28,1);
      }
      else if (uVar1 == 1) {
        dVar2 = (double)__kernel_cos(local_34,local_30,local_2c,local_28);
      }
      else if (uVar1 == 2) {
        dVar2 = (double)__kernel_sin(local_34,local_30,local_2c,local_28,1);
      }
      else {
        dVar2 = (double)__kernel_cos(local_34,local_30,local_2c,local_28);
      }
    }
    else {
      dVar2 = (double)__subdf3();
    }
  }
  else {
    dVar2 = (double)__kernel_sin(in_r0,in_r1,0,0,0);
  }
  return dVar2;
}

/* ----------------------------------------------------------------
 * tan @ 0x300B0D20  (примерный размер ~156 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 3
 * Вызывает: __ieee754_rem_pio2, __kernel_tan, __subdf3
 * Константы: 0x7FFFFFFF, 0x300B0D20
 * Данные: DAT_300b0db4, DAT_300b0db8
 * ---------------------------------------------------------------- */
double tan(double __x)

{
  uint in_r1;
  double dVar1;
  
  if (DAT_300b0db4 < (int)(in_r1 & 0x7fffffff)) {
    if (DAT_300b0db8 <= (int)(in_r1 & 0x7fffffff)) {
      dVar1 = (double)__subdf3();
      return dVar1;
    }
    __ieee754_rem_pio2();
  }
  dVar1 = (double)__kernel_tan();
  return dVar1;
}

/* ----------------------------------------------------------------
 * cosh @ 0x300B0DBC  (примерный размер ~556 байт)
 * Модуль: lib | Вызывают: 0 | Вызывает: 6
 * Вызывает: __adddf3, __divdf3, __muldf3, exp, expm1, fabs
 * Константы: 0x300B0DBC, 0x7FFFFFFF, 0x3C7FFFFF
 * Данные: DAT_300b0fc4, DAT_300b0fc8, DAT_300b0fcc, DAT_300b0fd0, DAT_300b0fd4, DAT_300b0fd8, DAT_300b0fdc, DAT_300b0fe0
 * ---------------------------------------------------------------- */
double cosh(double __x)

{
  uint in_r0;
  undefined4 uVar1;
  uint in_r1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  uint uVar2;
  double dVar3;
  double extraout_d0;
  undefined8 uVar4;
  undefined8 uVar5;
  double in_stack_ffffffb4;
  
  uVar2 = in_r1 & 0x7fffffff;
  if ((int)uVar2 < DAT_300b0fc4) {
    if ((int)uVar2 < DAT_300b0fc8) {
      fabs(in_stack_ffffffb4);
      expm1(in_stack_ffffffb4);
      uVar4 = __adddf3();
      uVar1 = (undefined4)((ulonglong)uVar4 >> 0x20);
      dVar3 = extraout_d0;
      if (0x3c7fffff < uVar2) {
        uVar5 = __muldf3(in_r0,extraout_r1,in_r0,extraout_r1);
        uVar4 = __adddf3((int)uVar4,uVar1,(int)uVar4,uVar1);
        uVar4 = __divdf3((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar4,
                         (int)((ulonglong)uVar4 >> 0x20));
        dVar3 = (double)__adddf3((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,DAT_300b0fcc);
      }
    }
    else if ((int)uVar2 < DAT_300b0fd0) {
      fabs(in_stack_ffffffb4);
      exp(in_stack_ffffffb4);
      uVar1 = DAT_300b0fd4;
      uVar4 = __muldf3();
      uVar5 = __divdf3(0,uVar1,in_r0,extraout_r1_00);
      dVar3 = (double)__adddf3((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar4,
                               (int)((ulonglong)uVar4 >> 0x20));
    }
    else if ((int)uVar2 < DAT_300b0fd8) {
      fabs(in_stack_ffffffb4);
      exp(in_stack_ffffffb4);
      dVar3 = (double)__muldf3();
    }
    else if (((int)uVar2 < (int)DAT_300b0fdc) ||
            ((uVar2 == DAT_300b0fdc && (in_r0 <= DAT_300b0fe0)))) {
      fabs(in_stack_ffffffb4);
      uVar1 = __muldf3();
      exp(in_stack_ffffffb4);
      uVar4 = __muldf3();
      dVar3 = (double)__muldf3((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),uVar1,extraout_r1_01);
    }
    else {
      dVar3 = (double)__muldf3(*DAT_300b0fe4,DAT_300b0fe4[1],*DAT_300b0fe4,DAT_300b0fe4[1]);
    }
  }
  else {
    dVar3 = (double)__muldf3();
  }
  return dVar3;
}

