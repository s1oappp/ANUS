/* ============================================================
 * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция
 * Модуль : data — прочее: обработчики данных, product-таблицы, служебные функции
 * Часть  : 3 (функций: 150, адреса 0x3004A868..0x3005CD8C)
 * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)
 * ============================================================ */

/* ----------------------------------------------------------------
 * core_change_string_descriptor @ 0x3004A868  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: chp9_set_string_descriptors
 * Константы: 0x3004A868
 * ---------------------------------------------------------------- */
void core_change_string_descriptor(int param_1,uint param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + (param_2 & 0xff) * 4 + 0x3c) = param_3;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3004a894 @ 0x3004A894  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3004c2d8
 * Константы: 0x3004A894
 * ---------------------------------------------------------------- */
undefined4 FUN_3004a894(int param_1,byte param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || (0x20 < param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + (uint)param_2 * 4 + 0x3c);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004a8d8 @ 0x3004A8D8  (примерный размер ~488 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 5
 * Вызывает: core_read_data, core_send_data, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3004b5d0, FUN_3004b88c, FUN_3004c22c, FUN_3004c2d8, FUN_3004c4c0, FUN_3004c688, FUN_3004c8a0
 * Константы: 0x3004A8D8
 * Данные: DAT_3004b640, DAT_3004b644, DAT_3004b648, DAT_3004b85c, DAT_3004b860, DAT_3004b864, DAT_3004b960, DAT_3004b964
 * ---------------------------------------------------------------- */
undefined4 FUN_3004a8d8(int param_1,uint param_2,uint param_3,char param_4)

{
  undefined4 uVar1;
  undefined1 uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x38) == 0) {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004b640 + 0xa0)) && (0 < *(int *)(DAT_3004b640 + 0xa4))) {
      os_dprintf(DAT_3004b644,DAT_3004b648,0x114);
      os_printf(DAT_3004b85c);
    }
    uVar1 = 10;
  }
  else if (*(int *)(*(int *)(param_1 + 0x38) + 0x18) == 0) {
    if (*(char *)(param_1 + 0x3c) == param_4) {
      valid_type(0x29);
      if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
        os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004b964);
        os_printf(DAT_3004b968,param_2,param_3);
      }
      uVar3 = param_3;
      if (param_3 <= param_2) {
        uVar3 = 0;
      }
      uVar2 = (undefined1)uVar3;
      if (param_2 < param_3) {
        uVar2 = 1;
      }
      **(undefined1 **)(param_1 + 0x38) = uVar2;
      *(char *)(*(int *)(param_1 + 0x38) + 3) = param_4;
      *(int *)(*(int *)(param_1 + 0x38) + 0x14) = param_1;
      *(undefined4 *)(*(int *)(param_1 + 0x38) + 0x10) = DAT_3004b96c;
      if (param_3 < param_2) {
        param_2 = param_3;
      }
      *(uint *)(*(int *)(param_1 + 0x38) + 0x1c) = param_2;
      if (param_3 == 0) {
        uVar1 = core_read_data(param_1,0,*(undefined4 *)(param_1 + 0x38));
      }
      else {
        uVar1 = core_send_data(param_1,0,*(undefined4 *)(param_1 + 0x38));
      }
    }
    else {
      valid_type(0x29);
      if ((0 < *(int *)(DAT_3004b640 + 0xa0)) && (0 < *(int *)(DAT_3004b640 + 0xa4))) {
        os_dprintf(DAT_3004b644,DAT_3004b648,0x120);
        os_printf(DAT_3004b960);
      }
      uVar1 = 0;
    }
  }
  else {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004b640 + 0xa0)) && (0 < *(int *)(DAT_3004b640 + 0xa4))) {
      os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004b860);
      os_printf(DAT_3004b864);
    }
    uVar1 = 8;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004aac0 @ 0x3004AAC0  (примерный размер ~232 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3004ad3c, FUN_3004ae68
 * Константы: 0x3004AAC0
 * Данные: DAT_3004b640, DAT_3004b644, DAT_3004b648, DAT_3004ba8c, DAT_3004ba90
 * ---------------------------------------------------------------- */
void FUN_3004aac0(int param_1,byte *param_2)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(uint)*param_2; iVar1 = iVar1 + 1) {
    valid_type(0x29);
    if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
      os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004ba8c);
      os_printf(DAT_3004ba90,*(undefined1 *)(iVar1 * 0x3c + *(int *)(param_2 + 4) + 0xb),
                *(undefined4 *)(iVar1 * 0x3c + *(int *)(param_2 + 4) + 0x28));
    }
    if ((*(int *)(iVar1 * 0x3c + *(int *)(param_2 + 4) + 0x28) == 1) ||
       (*(int *)(iVar1 * 0x3c + *(int *)(param_2 + 4) + 0x28) == 3)) {
      (**(code **)(*(int *)(param_1 + 0x24) + 0x20))
                (*(undefined4 *)(param_1 + 0x20),*(int *)(param_2 + 4) + iVar1 * 0x3c);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3004aba8 @ 0x3004ABA8  (примерный размер ~404 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3004ad7c, FUN_3004ae68
 * Константы: 0x3004ABA8
 * Данные: DAT_3004b640, DAT_3004b644, DAT_3004b648, DAT_3004ba94, DAT_3004ba98, DAT_3004bba8, DAT_3004bbac, DAT_3004bbb0
 * ---------------------------------------------------------------- */
int FUN_3004aba8(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
    os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004ba94);
    os_printf(DAT_3004ba98,param_2);
  }
  iVar2 = 0;
  while( true ) {
    if ((int)(uint)*param_2 <= iVar2) {
      valid_type(0x29);
      if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
        os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004bbac);
        os_printf(DAT_3004bbb0);
      }
      return 0;
    }
    valid_type(0x29);
    if ((4 < *(int *)(DAT_3004b640 + 0xa0)) && (4 < *(int *)(DAT_3004b640 + 0xa4))) {
      os_dprintf(DAT_3004b644,DAT_3004b648,0x16c);
      os_printf(DAT_3004bba8,*(undefined1 *)(iVar2 * 0x3c + *(int *)(param_2 + 4) + 0xb));
    }
    if (*(int *)(param_1 + 0x14) == 3) {
      *(undefined2 *)(iVar2 * 0x3c + *(int *)(param_2 + 4) + 0x24) =
           *(undefined2 *)(*(int *)(param_2 + 4) + iVar2 * 0x3c);
    }
    else {
      *(undefined2 *)(iVar2 * 0x3c + *(int *)(param_2 + 4) + 0x24) =
           *(undefined2 *)(iVar2 * 0x3c + *(int *)(param_2 + 4) + 2);
    }
    iVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x1c))
                      (*(undefined4 *)(param_1 + 0x20),*(int *)(param_2 + 4) + iVar2 * 0x3c);
    if (iVar1 != 0) break;
    iVar2 = iVar2 + 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004ad3c @ 0x3004AD3C  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: FUN_3004aac0
 * Вызывают: chp9_handle_set_configuration
 * Константы: 0x3004AD3C
 * ---------------------------------------------------------------- */
void FUN_3004ad3c(int param_1)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(param_1 + 0x34); iVar1 = iVar1 + 1) {
    FUN_3004aac0(param_1,*(undefined4 *)(iVar1 * 0x14 + *(int *)(param_1 + 0x30) + 0x10));
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3004ad7c @ 0x3004AD7C  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_3004aba8, os_dprintf, os_printf, valid_type
 * Вызывают: chp9_handle_set_configuration
 * Константы: 0x3004AD7C
 * Данные: DAT_3004b640, DAT_3004b644, DAT_3004b648, DAT_3004bc4c, DAT_3004bc50, DAT_3004bd58
 * ---------------------------------------------------------------- */
int FUN_3004ad7c(int param_1)

{
  int iVar1;
  int iVar2;
  
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
    os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004bc4c);
    os_printf(DAT_3004bc50);
  }
  iVar2 = 0;
  while( true ) {
    if ((int)(uint)*(byte *)(param_1 + 0x34) <= iVar2) {
      return 0;
    }
    valid_type(0x29);
    if ((4 < *(int *)(DAT_3004b640 + 0xa0)) && (4 < *(int *)(DAT_3004b640 + 0xa4))) {
      os_dprintf(DAT_3004b644,DAT_3004b648,0x1a4);
      os_printf(DAT_3004bd58,iVar2,*(undefined4 *)(iVar2 * 0x14 + *(int *)(param_1 + 0x30) + 0x10));
    }
    iVar1 = FUN_3004aba8(param_1,*(undefined4 *)(iVar2 * 0x14 + *(int *)(param_1 + 0x30) + 0x10));
    if (iVar1 != 0) break;
    iVar2 = iVar2 + 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004ae68 @ 0x3004AE68  (примерный размер ~916 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_3004aac0, FUN_3004aba8, os_dprintf, os_printf, valid_type
 * Константы: 0x3004AE68
 * Данные: DAT_3004b640, DAT_3004b644, DAT_3004b648, DAT_3004bd5c, DAT_3004bd60, DAT_3004bd64, DAT_3004beb4, DAT_3004beb8
 * ---------------------------------------------------------------- */
int FUN_3004ae68(int param_1,byte param_2,byte param_3)

{
  int iVar1;
  int iVar2;
  
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
    os_dprintf(DAT_3004b644,DAT_3004b648,0x1c0);
    os_printf(DAT_3004bd5c,param_2,param_3);
  }
  if (param_2 < *(byte *)(param_1 + 0x34)) {
    if (param_3 < *(byte *)(*(int *)((uint)param_2 * 0x14 + *(int *)(param_1 + 0x30) + 0xc) + 8)) {
      if (*(char *)(param_1 + 0x10) == '\0') {
        valid_type(0x29);
        if ((1 < *(int *)(DAT_3004b640 + 0xa0)) && (1 < *(int *)(DAT_3004b640 + 0xa4))) {
          os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004bebc);
          os_printf(DAT_3004bec0);
        }
        iVar1 = 10;
      }
      else {
        valid_type(0x29);
        if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
          os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004bec4);
          os_printf(DAT_3004bec8,param_2,param_3);
        }
        iVar2 = *(int *)((uint)param_2 * 0x14 + *(int *)(param_1 + 0x30) + 8);
        if (*(int *)(iVar2 + 4) == 0) {
          (**(code **)(*(int *)(iVar2 + 8) + 8))(*(undefined4 *)(iVar2 + 0x10));
        }
        *(undefined4 *)(iVar2 + 4) = 1;
        FUN_3004aac0(param_1,*(undefined4 *)((uint)param_2 * 0x14 + *(int *)(param_1 + 0x30) + 0x10)
                    );
        *(uint *)((uint)param_2 * 0x14 + *(int *)(param_1 + 0x30) + 0x10) =
             *(int *)(*(int *)((uint)param_2 * 0x14 + *(int *)(param_1 + 0x30) + 0xc) + 4) +
             (uint)param_3 * 0x10;
        *(byte *)(*(int *)((uint)param_2 * 0x14 + *(int *)(param_1 + 0x30) + 0xc) + 9) = param_3;
        iVar1 = FUN_3004aba8(param_1,*(undefined4 *)
                                      ((uint)param_2 * 0x14 + *(int *)(param_1 + 0x30) + 0x10));
        if (iVar1 == 0) {
          *(undefined4 *)(*(int *)(iVar2 + 0xc) + 4) = *(undefined4 *)(param_1 + 0x14);
          iVar1 = (**(code **)(*(int *)(iVar2 + 8) + 4))(*(undefined4 *)(iVar2 + 0x10));
          if (iVar1 == 0) {
            *(undefined4 *)(iVar2 + 4) = 0;
            valid_type(0x29);
            if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
              os_dprintf(DAT_3004b644,DAT_3004b648,0x208);
              os_printf(DAT_3004c044,param_2,param_3,0);
            }
            return 0;
          }
        }
        FUN_3004aac0(param_1,*(undefined4 *)((uint)param_2 * 0x14 + *(int *)(param_1 + 0x30) + 0x10)
                    );
        valid_type(0x29);
        if ((1 < *(int *)(DAT_3004b640 + 0xa0)) && (1 < *(int *)(DAT_3004b640 + 0xa4))) {
          os_dprintf(DAT_3004b644,DAT_3004b648,0x210);
          os_printf(DAT_3004c048,param_2,param_3,iVar1);
        }
      }
    }
    else {
      valid_type(0x29);
      if ((1 < *(int *)(DAT_3004b640 + 0xa0)) && (1 < *(int *)(DAT_3004b640 + 0xa4))) {
        os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004beb4);
        os_printf(DAT_3004beb8,param_2,param_3);
      }
      iVar1 = 10;
    }
  }
  else {
    valid_type(0x29);
    if ((1 < *(int *)(DAT_3004b640 + 0xa0)) && (1 < *(int *)(DAT_3004b640 + 0xa4))) {
      os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004bd60);
      os_printf(DAT_3004bd64,param_2);
    }
    iVar1 = 10;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * chp9_handle_set_configuration @ 0x3004B1FC  (примерный размер ~980 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 7
 * Вызывает: FUN_3004ad3c, FUN_3004ad7c, j_device_get_softc, os_dprintf, os_notify, os_printf, valid_type
 * Вызывают: FUN_3004ffac, core_disable, core_disconnect, core_unregister_dcd
 * Константы: 0x3004B1FC
 * Данные: DAT_3004b640, DAT_3004b644, DAT_3004b648, DAT_3004c100, DAT_3004c104, DAT_3004c108, DAT_3004c1e8, DAT_3004c1ec
 * ---------------------------------------------------------------- */
int chp9_handle_set_configuration(int param_1,byte param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
    os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004c100);
    os_printf(DAT_3004c104,param_2);
  }
  if (param_2 < 2) {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x48))(*(undefined4 *)(param_1 + 0x20),param_2);
    if (iVar1 == 0) {
      if (*(char *)(param_1 + 0x10) != '\0') {
        *(undefined4 *)(param_1 + 8) = 1;
        for (piVar3 = *(int **)(param_1 + 0x2c); piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
          if (piVar3[1] == 0) {
            (**(code **)(piVar3[2] + 8))(piVar3[4]);
          }
          piVar3[1] = 1;
        }
        FUN_3004ad3c(param_1);
      }
      if (param_2 == 0) {
        if (*(char *)(param_1 + 0x10) != '\0') {
          *(undefined1 *)(param_1 + 0x10) = 0;
          uVar2 = j_device_get_softc(*(undefined4 *)(param_1 + 0x20));
          os_notify(0xd,uVar2);
        }
        iVar1 = 0;
      }
      else {
        valid_type(0x29);
        if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
          os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004c1e8);
          os_printf(DAT_3004c1ec,param_2,*(undefined4 *)(param_1 + 0x14));
        }
        for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(param_1 + 0x34); iVar1 = iVar1 + 1) {
          *(undefined4 *)(iVar1 * 0x14 + *(int *)(param_1 + 0x30) + 0x10) =
               *(undefined4 *)(*(int *)(iVar1 * 0x14 + *(int *)(param_1 + 0x30) + 0xc) + 4);
          valid_type(0x29);
          if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
            os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004c2b8);
            os_printf(DAT_3004c2bc,iVar1,
                      *(undefined1 *)(iVar1 * 0x14 + *(int *)(param_1 + 0x30) + 5),
                      *(undefined4 *)(iVar1 * 0x14 + *(int *)(param_1 + 0x30) + 0x10));
          }
          *(undefined1 *)(*(int *)(iVar1 * 0x14 + *(int *)(param_1 + 0x30) + 0xc) + 9) = 0;
        }
        iVar1 = FUN_3004ad7c(param_1);
        if (iVar1 == 0) {
          for (piVar3 = *(int **)(param_1 + 0x2c); piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
            *(undefined4 *)(piVar3[3] + 4) = *(undefined4 *)(param_1 + 0x14);
            iVar1 = (**(code **)(piVar3[2] + 4))(piVar3[4]);
            if (iVar1 != 0) goto LAB_3004b534;
            piVar3[1] = 0;
          }
          *(undefined4 *)(param_1 + 8) = 0;
          *(byte *)(param_1 + 0x10) = param_2;
          uVar2 = j_device_get_softc(*(undefined4 *)(param_1 + 0x20));
          os_notify(0xc,uVar2);
          valid_type(0x29);
          if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
            os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004c380);
            os_printf(DAT_3004c384,0);
          }
          iVar1 = 0;
        }
        else {
LAB_3004b534:
          FUN_3004ad3c(param_1);
          for (piVar3 = *(int **)(param_1 + 0x2c); piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
            if (piVar3[1] == 0) {
              (**(code **)(piVar3[2] + 8))(piVar3[4]);
            }
            piVar3[1] = 1;
          }
          *(undefined1 *)(param_1 + 0x10) = 0;
          valid_type(0x29);
          if ((1 < *(int *)(DAT_3004b640 + 0xa0)) && (1 < *(int *)(DAT_3004b640 + 0xa4))) {
            os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004c430);
            os_printf(DAT_3004c434,iVar1);
          }
        }
      }
    }
  }
  else {
    valid_type(0x29);
    if ((1 < *(int *)(DAT_3004b640 + 0xa0)) && (1 < *(int *)(DAT_3004b640 + 0xa4))) {
      os_dprintf(DAT_3004b644,DAT_3004b648,0x22c);
      os_printf(DAT_3004c108);
    }
    iVar1 = 10;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004b5d0 @ 0x3004B5D0  (примерный размер ~304 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_3004a8d8, os_dprintf, os_memcpy, os_printf, valid_type
 * Вызывают: FUN_3004c9d4
 * Константы: 0x3004B5D0
 * Данные: DAT_3004b640, DAT_3004b644, DAT_3004b648, DAT_3004c438, DAT_3004c43c, DAT_3004c440
 * ---------------------------------------------------------------- */
void FUN_3004b5d0(int param_1,undefined2 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x108);
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004b640 + 0xa0)) && (3 < *(int *)(DAT_3004b640 + 0xa4))) {
    os_dprintf(DAT_3004b644,DAT_3004b648,DAT_3004c438);
    os_printf(DAT_3004c43c);
  }
  *(undefined1 *)(DAT_3004c440 + 0xf) = *(undefined1 *)(param_1 + 0xc1);
  *(undefined1 *)(DAT_3004c440 + 0xe) = *(undefined1 *)(param_1 + 0xc2);
  *(undefined1 *)(DAT_3004c440 + 0x10) = *(undefined1 *)(param_1 + 0xc3);
  *(undefined2 *)(DAT_3004c440 + 8) = *(undefined2 *)(iVar2 + 2);
  *(undefined2 *)(DAT_3004c440 + 10) = *(undefined2 *)(iVar2 + 4);
  *(undefined2 *)(DAT_3004c440 + 0xc) = *(undefined2 *)(iVar2 + 6);
  *(undefined1 *)(DAT_3004c440 + 4) = *(undefined1 *)(iVar2 + 8);
  *(undefined1 *)(DAT_3004c440 + 5) = *(undefined1 *)(iVar2 + 9);
  *(undefined1 *)(DAT_3004c440 + 6) = *(undefined1 *)(iVar2 + 10);
  uVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x4c))(*(undefined4 *)(param_1 + 0x20));
  *(undefined1 *)(DAT_3004c440 + 7) = uVar1;
  os_memcpy(**(undefined4 **)(*(int *)(param_1 + 0x38) + 8),DAT_3004c440,0x12);
  FUN_3004a8d8(param_1,0x12,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3004b700 @ 0x3004B700  (примерный размер ~396 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3004b88c
 * Константы: 0x3004B700
 * ---------------------------------------------------------------- */
short FUN_3004b700(int param_1)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  short sVar8;
  undefined4 *local_28;
  
  sVar8 = 9;
  iVar1 = 0;
  local_28 = *(undefined4 **)(param_1 + 0x2c);
  for (bVar4 = 0; bVar4 < *(byte *)(param_1 + 0x34); bVar4 = bVar4 + 1) {
    if ((int)(*(byte *)(local_28[3] + 8) - 1) < iVar1) {
      local_28 = (undefined4 *)*local_28;
      iVar1 = 0;
    }
    iVar7 = *(int *)((uint)bVar4 * 0x14 + *(int *)(param_1 + 0x30) + 0xc);
    if ((iVar1 == 0) && (*(int *)(local_28[3] + 0x10) != 0)) {
      sVar8 = sVar8 + 8;
    }
    for (bVar3 = 0; bVar3 < *(byte *)(iVar7 + 8); bVar3 = bVar3 + 1) {
      pbVar6 = (byte *)(*(int *)(iVar7 + 4) + (uint)bVar3 * 0x10);
      sVar8 = sVar8 + 9;
      if ((bVar3 == 0) && (*(short *)(iVar7 + 0x10) != 0)) {
        sVar8 = sVar8 + *(short *)(iVar7 + 0x10);
      }
      if (*(short *)(pbVar6 + 0xc) != 0) {
        sVar8 = sVar8 + *(short *)(pbVar6 + 0xc);
      }
      for (iVar2 = 0; iVar2 < (int)(uint)*pbVar6; iVar2 = iVar2 + 1) {
        iVar5 = *(int *)(pbVar6 + 4) + iVar2 * 0x3c;
        sVar8 = sVar8 + 7;
        if (*(short *)(iVar5 + 0x10) != 0) {
          sVar8 = sVar8 + *(short *)(iVar5 + 0x10);
        }
      }
    }
    iVar1 = iVar1 + 1;
  }
  return sVar8;
}

/* ----------------------------------------------------------------
 * FUN_3004b88c @ 0x3004B88C  (примерный размер ~2464 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 7
 * Вызывает: FUN_3004a8d8, FUN_3004b700, core_request_alloc, os_dprintf, os_memcpy, os_printf, valid_type
 * Вызывают: FUN_3004c58c, FUN_3004c9d4
 * Константы: 0x3004B88C
 * Данные: DAT_3004c78c, DAT_3004c790, DAT_3004c794, DAT_3004c798, DAT_3004c79c, DAT_3004c7a0, DAT_3004c828, DAT_3004c82c
 * ---------------------------------------------------------------- */
undefined4 FUN_3004b88c(int param_1,char param_2,byte param_3,undefined2 param_4,undefined1 param_5)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  ushort *puVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  byte local_54;
  byte local_53;
  int local_48;
  undefined4 *local_44;
  
  iVar11 = *(int *)(DAT_3004c78c + 0x10);
  iVar13 = *(int *)(DAT_3004c78c + 0x1c);
  puVar12 = *(uint **)(param_1 + 0x108);
  uVar2 = FUN_3004b700(param_1);
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004c790 + 0xa0)) && (3 < *(int *)(DAT_3004c790 + 0xa4))) {
    os_dprintf(DAT_3004c794,DAT_3004c798,DAT_3004c79c);
    os_printf(DAT_3004c7a0,param_2);
  }
  if (param_2 == '\0') {
    if (0x100 < uVar2) {
      uVar3 = *(undefined4 *)(param_1 + 0x38);
      valid_type(0x29);
      if ((2 < *(int *)(DAT_3004c790 + 0xa0)) && (2 < *(int *)(DAT_3004c790 + 0xa4))) {
        os_dprintf(DAT_3004c794,DAT_3004c798,0x32c);
        os_printf(DAT_3004c830);
      }
      uVar4 = core_request_alloc(param_1,uVar2,0);
      *(undefined4 *)(param_1 + 0x38) = uVar4;
      if (*(int *)(param_1 + 0x38) == 0) {
        valid_type(0x29);
        if ((0 < *(int *)(DAT_3004c790 + 0xa0)) && (0 < *(int *)(DAT_3004c790 + 0xa4))) {
          os_dprintf(DAT_3004c794,DAT_3004c798,DAT_3004c93c);
          os_printf(DAT_3004c940,uVar2);
        }
        *(undefined4 *)(param_1 + 0x38) = uVar3;
        return 7;
      }
      *(undefined4 *)(*(int *)(param_1 + 0x38) + 0x28) = uVar3;
    }
    iVar10 = **(int **)(*(int *)(param_1 + 0x38) + 8);
    *(undefined1 *)(DAT_3004c944 + 4) = *(undefined1 *)(param_1 + 0x34);
    *(undefined1 *)(DAT_3004c944 + 5) = 1;
    if ((*puVar12 & 1) != 0) {
      *(byte *)(DAT_3004c944 + 7) = *(byte *)(DAT_3004c944 + 7) | 0x40;
    }
    if ((*puVar12 & 2) != 0) {
      *(byte *)(DAT_3004c944 + 7) = *(byte *)(DAT_3004c944 + 7) | 0x20;
    }
    *(undefined1 *)(DAT_3004c944 + 8) = *(undefined1 *)((int)puVar12 + 1);
    iVar8 = 9;
    local_54 = 0;
    local_48 = 0;
    local_44 = *(undefined4 **)(param_1 + 0x2c);
    for (; local_54 < *(byte *)(param_1 + 0x34); local_54 = local_54 + 1) {
      if ((int)(*(byte *)(local_44[3] + 8) - 1) < local_48) {
        local_44 = (undefined4 *)*local_44;
        local_48 = 0;
      }
      iVar5 = *(int *)((uint)local_54 * 0x14 + *(int *)(param_1 + 0x30) + 0xc);
      if ((local_48 == 0) && (*(int *)(local_44[3] + 0x10) != 0)) {
        valid_type(0x29);
        if ((4 < *(int *)(DAT_3004c790 + 0xa0)) && (4 < *(int *)(DAT_3004c790 + 0xa4))) {
          os_dprintf(DAT_3004c794,DAT_3004c798,0x364);
          os_printf(DAT_3004cab8,local_54);
        }
        if ((int)(uint)uVar2 < iVar8 + 8) {
          return 7;
        }
        os_memcpy(iVar10 + iVar8,*(undefined4 *)(local_44[3] + 0x10),8);
        iVar8 = iVar8 + 8;
      }
      for (local_53 = 0; local_53 < *(byte *)(iVar5 + 8); local_53 = local_53 + 1) {
        pbVar7 = (byte *)(*(int *)(iVar5 + 4) + (uint)local_53 * 0x10);
        *(byte *)(DAT_3004cabc + 2) = local_54;
        *(byte *)(DAT_3004cabc + 3) = local_53;
        *(byte *)(DAT_3004cabc + 4) = *pbVar7;
        if (((*(short *)(iVar5 + 0x10) == 0) || (iVar13 == DAT_3004cbc4)) ||
           (((iVar11 != DAT_3004cbc8 && (iVar11 != DAT_3004cbcc)) &&
            (((iVar11 != DAT_3004cbd0 || (*(int *)(*DAT_3004cbd4 + (uint)local_54 * 8 + 0x10) == 8))
             || (*(int *)(*DAT_3004cbd4 + (uint)local_54 * 8 + 0x10) == 7)))))) {
          *(undefined1 *)(DAT_3004cabc + 5) = *(undefined1 *)(iVar5 + 0x13);
          *(undefined1 *)(DAT_3004cabc + 6) = *(undefined1 *)(iVar5 + 0x14);
          *(undefined1 *)(DAT_3004cabc + 7) = *(undefined1 *)(iVar5 + 0x15);
          *(undefined1 *)(DAT_3004cabc + 8) = *(undefined1 *)(iVar5 + 0x16);
        }
        else {
          *(undefined1 *)(DAT_3004cabc + 5) = 0xff;
          *(undefined1 *)(DAT_3004cabc + 6) = 0xff;
          *(undefined1 *)(DAT_3004cabc + 7) = 0xff;
          *(undefined1 *)(DAT_3004cabc + 8) = *(undefined1 *)(iVar5 + 0x16);
        }
        if ((int)(uint)uVar2 < iVar8 + 9) {
          return 7;
        }
        os_memcpy(iVar10 + iVar8,DAT_3004cabc,9);
        iVar8 = iVar8 + 9;
        if (((((iVar11 != DAT_3004cbd0) && (iVar11 != DAT_3004cbcc)) && (iVar11 != DAT_3004cbc8)) ||
            ((iVar11 == DAT_3004cbd0 &&
             ((*(int *)(*DAT_3004cbd4 + (uint)local_54 * 8 + 0x10) == 8 ||
              (*(int *)(*DAT_3004cbd4 + (uint)local_54 * 8 + 0x10) == 7)))))) &&
           ((local_53 == 0 && (*(short *)(iVar5 + 0x10) != 0)))) {
          if ((int)(uint)uVar2 < (int)(iVar8 + (uint)*(ushort *)(iVar5 + 0x10))) {
            return 7;
          }
          os_memcpy(iVar10 + iVar8,*(undefined4 *)(iVar5 + 0xc),*(undefined2 *)(iVar5 + 0x10));
          iVar8 = iVar8 + (uint)*(ushort *)(iVar5 + 0x10);
        }
        if (*(short *)(pbVar7 + 0xc) != 0) {
          if ((int)(uint)uVar2 < (int)(iVar8 + (uint)*(ushort *)(pbVar7 + 0xc))) {
            return 7;
          }
          os_memcpy(iVar10 + iVar8,*(undefined4 *)(pbVar7 + 8),*(undefined2 *)(pbVar7 + 0xc));
          iVar8 = iVar8 + (uint)*(ushort *)(pbVar7 + 0xc);
        }
        for (iVar9 = 0; iVar9 < (int)(uint)*pbVar7; iVar9 = iVar9 + 1) {
          puVar6 = (ushort *)(*(int *)(pbVar7 + 4) + iVar9 * 0x3c);
          DAT_3004cc38[2] = ((char)puVar6[4] == '\0') << 7;
          DAT_3004cc38[2] = DAT_3004cc38[2] | *(byte *)((int)puVar6 + 0xb);
          DAT_3004cc38[3] = (byte)*(undefined4 *)(puVar6 + 2);
          DAT_3004cc38[6] = *(byte *)((int)puVar6 + 0xd);
          if (*(int *)(puVar6 + 2) == 1) {
            DAT_3004cc38[3] = DAT_3004cc38[3] | *(char *)((int)puVar6 + 9) << 2;
            DAT_3004cc38[3] = DAT_3004cc38[3] | (char)puVar6[5] << 4;
          }
          if (param_3 == 3) {
            uVar1 = *puVar6;
          }
          else {
            uVar1 = puVar6[1];
          }
          if (uVar1 < *(ushort *)(DAT_3004cc3c + (uint)param_3 * 2 + *(int *)(puVar6 + 2) * 6)) {
            if (param_3 == 3) {
              *(ushort *)(DAT_3004cc38 + 4) = *puVar6;
            }
            else {
              *(ushort *)(DAT_3004cc38 + 4) = puVar6[1];
            }
          }
          else {
            *(undefined2 *)(DAT_3004cc38 + 4) =
                 *(undefined2 *)(DAT_3004cc3c + (uint)param_3 * 2 + *(int *)(puVar6 + 2) * 6);
          }
          if ((param_3 == 3) &&
             (((*(int *)(puVar6 + 2) == 1 || (*(int *)(puVar6 + 2) == 3)) &&
              (*(ushort *)(DAT_3004cc38 + 4) =
                    *(ushort *)(DAT_3004cc38 + 4) | (ushort)(byte)puVar6[6] << 0xb,
              (char)puVar6[0xc] != '\0')))) {
            DAT_3004cc38[6] = (byte)puVar6[0xc];
          }
          *DAT_3004cc38 = 7;
          if ((int)(uint)uVar2 < (int)(iVar8 + (uint)*DAT_3004cc38)) {
            return 7;
          }
          os_memcpy(iVar10 + iVar8,DAT_3004cc38,*DAT_3004cc38);
          iVar8 = iVar8 + (uint)*DAT_3004cc38;
          if (puVar6[8] != 0) {
            valid_type(0x29);
            if ((4 < *(int *)(DAT_3004c790 + 0xa0)) && (4 < *(int *)(DAT_3004c790 + 0xa4))) {
              os_dprintf(DAT_3004c794,DAT_3004c798,DAT_3004cc40);
              os_printf(DAT_3004cc44,puVar6[8],*(undefined4 *)(puVar6 + 10));
            }
            if ((int)(uint)uVar2 < (int)(iVar8 + (uint)puVar6[8])) {
              return 7;
            }
            os_memcpy(iVar10 + iVar8,*(undefined4 *)(puVar6 + 10),puVar6[8]);
            iVar8 = iVar8 + (uint)puVar6[8];
          }
        }
      }
      local_48 = local_48 + 1;
    }
    *(short *)(DAT_3004c944 + 2) = (short)iVar8;
    os_memcpy(iVar10,DAT_3004c944,9);
    uVar3 = FUN_3004a8d8(param_1,iVar8,param_4,param_5);
  }
  else {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004c790 + 0xa0)) && (0 < *(int *)(DAT_3004c790 + 0xa4))) {
      os_dprintf(DAT_3004c794,DAT_3004c798,DAT_3004c828);
      os_printf(DAT_3004c82c,param_2);
    }
    uVar3 = 10;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_3004c22c @ 0x3004C22C  (примерный размер ~172 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: FUN_3004a8d8, os_memset, os_strlen
 * Вызывают: FUN_3004c2d8
 * Константы: 0x3004C22C
 * ---------------------------------------------------------------- */
undefined4 FUN_3004c22c(int param_1,int param_2,undefined2 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 == 0) {
    uVar1 = 10;
  }
  else {
    pcVar3 = (char *)**(undefined4 **)(*(int *)(param_1 + 0x38) + 8);
    iVar2 = os_strlen(param_2);
    *pcVar3 = (char)iVar2 * '\x02' + '\x02';
    pcVar3[1] = '\x03';
    os_memset(pcVar3 + 2,0,iVar2 << 1);
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      pcVar3[iVar2 * 2] = *(char *)(param_2 + iVar2 + -1);
    }
    uVar1 = FUN_3004a8d8(param_1,*pcVar3,param_3,param_4);
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004c2d8 @ 0x3004C2D8  (примерный размер ~488 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_3004a894, FUN_3004a8d8, FUN_3004c22c, os_dprintf, os_memcpy, os_printf, valid_type
 * Вызывают: FUN_3004c9d4
 * Константы: 0x3004C2D8
 * Данные: DAT_3004c790, DAT_3004c794, DAT_3004c798, DAT_3004cc48, DAT_3004cc4c, DAT_3004cc50, DAT_3004cc54, DAT_3004cc58
 * ---------------------------------------------------------------- */
undefined4 FUN_3004c2d8(int param_1,uint param_2,undefined4 param_3,uint param_4,undefined1 param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004c790 + 0xa0)) && (3 < *(int *)(DAT_3004c790 + 0xa4))) {
    os_dprintf(DAT_3004c794,DAT_3004c798,DAT_3004cc48);
    os_printf(DAT_3004cc4c,param_2 & 0xff);
  }
  puVar3 = (undefined1 *)**(undefined4 **)(*(int *)(param_1 + 0x38) + 8);
  if ((param_2 & 0xff) == 0) {
    *puVar3 = 4;
    puVar3[1] = 3;
    puVar3[2] = 9;
    puVar3[3] = 4;
    uVar1 = FUN_3004a8d8(param_1,4,param_4 & 0xffff,param_5);
  }
  else if (((param_2 & 0xff) == 0xee) && (*(char *)(param_1 + 0xc0) != '\0')) {
    valid_type(0x29);
    if ((2 < *(int *)(DAT_3004c790 + 0xa0)) && (2 < *(int *)(DAT_3004c790 + 0xa4))) {
      os_dprintf(DAT_3004c794,DAT_3004c798,DAT_3004cc50);
      os_printf(DAT_3004cc54,param_2 & 0xff);
    }
    *puVar3 = 0x12;
    puVar3[1] = 3;
    os_memcpy(puVar3 + 2,DAT_3004cc58,0xe);
    puVar3[0x10] = *(undefined1 *)(param_1 + 0xc0);
    puVar3[0x11] = 0;
    uVar1 = FUN_3004a8d8(param_1,0x12,param_4 & 0xffff,param_5);
  }
  else {
    iVar2 = FUN_3004a894(param_1,param_2);
    if (iVar2 == 0) {
      valid_type(0x29);
      if ((1 < *(int *)(DAT_3004c790 + 0xa0)) && (1 < *(int *)(DAT_3004c790 + 0xa4))) {
        os_dprintf(DAT_3004c794,DAT_3004c798,DAT_3004cc5c);
        os_printf(DAT_3004cc60,param_2 & 0xff);
      }
      uVar1 = 10;
    }
    else {
      uVar1 = FUN_3004c22c(param_1,iVar2,param_4,param_5);
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004c4c0 @ 0x3004C4C0  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_3004a8d8, os_dprintf, os_memcpy, os_printf, valid_type
 * Вызывают: FUN_3004c9d4
 * Константы: 0x3004C4C0
 * Данные: DAT_3004c790, DAT_3004c794, DAT_3004c798, DAT_3004cc64, DAT_3004cc68, DAT_3004cc6c
 * ---------------------------------------------------------------- */
void FUN_3004c4c0(int param_1,undefined2 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x108);
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004c790 + 0xa0)) && (3 < *(int *)(DAT_3004c790 + 0xa4))) {
    os_dprintf(DAT_3004c794,DAT_3004c798,DAT_3004cc64);
    os_printf(DAT_3004cc68);
  }
  *(undefined1 *)(DAT_3004cc6c + 4) = *(undefined1 *)(iVar2 + 8);
  *(undefined1 *)(DAT_3004cc6c + 5) = *(undefined1 *)(iVar2 + 9);
  *(undefined1 *)(DAT_3004cc6c + 6) = *(undefined1 *)(iVar2 + 10);
  uVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x4c))(*(undefined4 *)(param_1 + 0x20));
  *(undefined1 *)(DAT_3004cc6c + 7) = uVar1;
  os_memcpy(**(undefined4 **)(*(int *)(param_1 + 0x38) + 8),DAT_3004cc6c,10);
  FUN_3004a8d8(param_1,10,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3004c58c @ 0x3004C58C  (примерный размер ~252 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_3004b88c, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3004c9d4
 * Константы: 0x3004C58C
 * Данные: DAT_3004c790, DAT_3004c794, DAT_3004c798, DAT_3004c944, DAT_3004cc70, DAT_3004cc74, DAT_3004cc78
 * ---------------------------------------------------------------- */
undefined4 FUN_3004c58c(int param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004c790 + 0xa0)) && (3 < *(int *)(DAT_3004c790 + 0xa4))) {
    os_dprintf(DAT_3004c794,DAT_3004c798,DAT_3004cc70);
    os_printf(DAT_3004cc74);
  }
  if (*(char *)(param_1 + 0x18) == '\x03') {
    *(undefined1 *)(DAT_3004c944 + 1) = 7;
    uVar1 = FUN_3004b88c(param_1,0,(*(int *)(param_1 + 0x14) != 3) + '\x02',param_2,param_3);
    *(undefined1 *)(DAT_3004c944 + 1) = 2;
  }
  else {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004c790 + 0xa0)) && (0 < *(int *)(DAT_3004c790 + 0xa4))) {
      os_dprintf(DAT_3004c794,DAT_3004c798,0x480);
      os_printf(DAT_3004cc78);
    }
    uVar1 = 10;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004c688 @ 0x3004C688  (примерный размер ~348 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_3004a8d8, os_dprintf, os_memcpy, os_printf, valid_type
 * Константы: 0x3004C688
 * Данные: DAT_3004c790, DAT_3004c794, DAT_3004c798, DAT_3004cc7c, DAT_3004cc80, DAT_3004cc84
 * ---------------------------------------------------------------- */
int FUN_3004c688(int param_1,uint param_2,undefined1 param_3,undefined2 param_4,undefined1 param_5)

{
  int iVar1;
  uint *puVar2;
  byte local_20;
  byte local_1f;
  
  local_20 = *DAT_3004cc7c;
  local_1f = DAT_3004cc7c[1];
  puVar2 = *(uint **)(param_1 + 0x108);
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004c790 + 0xa0)) && (3 < *(int *)(DAT_3004c790 + 0xa4))) {
    os_dprintf(DAT_3004c794,DAT_3004c798,DAT_3004cc80);
    os_printf(DAT_3004cc84);
  }
  param_2 = param_2 & 3;
  if (param_2 == 0) {
    if ((*puVar2 & 1) != 0) {
      local_20 = local_20 | 1;
    }
    if (*(int *)(param_1 + 0xc4) != 0) {
      local_20 = local_20 | 2;
    }
  }
  else if (param_2 != 1) {
    if (param_2 != 2) {
      return 10;
    }
    iVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x3c))
                      (*(undefined4 *)(param_1 + 0x20),&local_20,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  os_memcpy(**(undefined4 **)(*(int *)(param_1 + 0x38) + 8),&local_20,2);
  iVar1 = FUN_3004a8d8(param_1,0x12,param_4,param_5);
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004c7e4 @ 0x3004C7E4  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3004c8a0
 * Константы: 0x3004C7E4
 * Данные: DAT_3004cc88, DAT_3004cc8c, DAT_3004cc90, DAT_3004cc94, DAT_3004cc98
 * ---------------------------------------------------------------- */
int FUN_3004c7e4(short param_1,char param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 == 0) {
    if (param_2 != '\x02') {
      iVar1 = 10;
    }
  }
  else if (((param_1 == 1) || (param_1 == 2)) && (param_2 != '\0')) {
    iVar1 = 10;
    goto LAB_3004c84c;
  }
  if (iVar1 == 0) {
    return 0;
  }
LAB_3004c84c:
  valid_type(0x29);
  if ((0 < *(int *)(DAT_3004cc88 + 0xa0)) && (0 < *(int *)(DAT_3004cc88 + 0xa4))) {
    os_dprintf(DAT_3004cc8c,DAT_3004cc90,DAT_3004cc94);
    os_printf(DAT_3004cc98,0,param_2,param_1);
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004c8a0 @ 0x3004C8A0  (примерный размер ~308 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_3004a8d8, FUN_3004c7e4, os_dprintf, os_printf, valid_type
 * Константы: 0x3004C8A0
 * Данные: DAT_3004cc88, DAT_3004cc8c, DAT_3004cc90, DAT_3004cc9c, DAT_3004cca0, DAT_3004cca4, DAT_3004cca8
 * ---------------------------------------------------------------- */
int FUN_3004c8a0(int param_1,uint param_2,undefined2 param_3,char param_4,undefined1 param_5,
                undefined1 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_3004c7e4(param_2,param_6);
  if (iVar1 == 0) {
    if ((param_2 & 0xffff) == 1) {
      if ((**(uint **)(param_1 + 0x108) & 2) == 0) {
        valid_type(0x29);
        if ((1 < *(int *)(DAT_3004cc88 + 0xa0)) && (1 < *(int *)(DAT_3004cc88 + 0xa4))) {
          os_dprintf(DAT_3004cc8c,DAT_3004cc90,DAT_3004cc9c);
          uVar2 = DAT_3004cca4;
          if (param_4 != '\0') {
            uVar2 = DAT_3004cca0;
          }
          os_printf(DAT_3004cca8,uVar2);
        }
        return 0xb;
      }
      if (param_4 == '\0') {
        *(undefined4 *)(param_1 + 0xc4) = 0;
      }
      else {
        *(undefined4 *)(param_1 + 0xc4) = 1;
      }
    }
    else {
      iVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x44))
                        (*(undefined4 *)(param_1 + 0x20),param_2 & 0xffff,param_3,param_4);
    }
    if (iVar1 == 0) {
      iVar1 = FUN_3004a8d8(param_1,0,1,param_5);
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004c9d4 @ 0x3004C9D4  (примерный размер ~528 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: FUN_3004b5d0, FUN_3004b88c, FUN_3004c2d8, FUN_3004c4c0, FUN_3004c58c, os_dprintf, os_printf, valid_type
 * Константы: 0x3004C9D4
 * Данные: DAT_3004cc88, DAT_3004cc8c, DAT_3004cc90, DAT_3004ccac, DAT_3004ccb0, DAT_3004ccb4, DAT_3004ccb8, DAT_3004ccbc
 * ---------------------------------------------------------------- */
undefined4
FUN_3004c9d4(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (int)(param_2 & 0xffff) >> 8;
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004cc88 + 0xa0)) && (3 < *(int *)(DAT_3004cc88 + 0xa4))) {
    os_dprintf(DAT_3004cc8c,DAT_3004cc90,DAT_3004ccac);
    os_printf(DAT_3004ccb0,uVar1);
  }
  if (uVar1 == 3) {
    uVar2 = FUN_3004c2d8(param_1,param_2 & 0xff,param_3,param_4,param_5);
    return uVar2;
  }
  if (uVar1 < 4) {
    if (uVar1 == 1) {
      uVar2 = FUN_3004b5d0(param_1,param_4,param_5);
      return uVar2;
    }
    if (uVar1 == 2) {
      uVar2 = FUN_3004b88c(param_1,param_2 & 0xff,*(undefined4 *)(param_1 + 0x14),param_4,param_5);
      return uVar2;
    }
  }
  else {
    if (uVar1 == 6) {
      if (*(int *)(param_1 + 0x104) != 0) {
        return 10;
      }
      uVar2 = FUN_3004c4c0(param_1,param_4,param_5);
      return uVar2;
    }
    if (uVar1 == 7) {
      if (*(int *)(param_1 + 0x104) != 0) {
        return 10;
      }
      uVar2 = FUN_3004c58c(param_1,param_4,param_5);
      return uVar2;
    }
  }
  valid_type(0x29);
  if ((1 < *(int *)(DAT_3004cc88 + 0xa0)) && (1 < *(int *)(DAT_3004cc88 + 0xa4))) {
    os_dprintf(DAT_3004cc8c,DAT_3004cc90,DAT_3004ccb4);
    os_printf(DAT_3004ccb8,uVar1);
  }
  valid_type(0x29);
  if ((1 < *(int *)(DAT_3004cc88 + 0xa0)) && (1 < *(int *)(DAT_3004cc88 + 0xa4))) {
    os_dprintf(DAT_3004cc8c,DAT_3004cc90,DAT_3004ccbc);
    os_printf(DAT_3004ccc0);
  }
  return 0xb;
}

/* ----------------------------------------------------------------
 * FUN_3004cbe4 @ 0x3004CBE4  (примерный размер ~1420 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: chp9_handle_usb_command
 * Константы: 0x3004CBE4, 0x3004CC34
 * Данные: DAT_3004ccc4, DAT_3004d5fc, DAT_3004d600, DAT_3004d604, DAT_3004d648, DAT_3004d64c
 * ---------------------------------------------------------------- */
undefined4 FUN_3004cbe4(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(byte *)(param_2 + 1) < 0xd) {
                    /* WARNING: Could not recover jumptable at 0x3004cc34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_3004ccc4 + (uint)*(byte *)(param_2 + 1) * 4))();
    return uVar1;
  }
  valid_type(0x29);
  if ((1 < *(int *)(DAT_3004d5fc + 0xa0)) && (1 < *(int *)(DAT_3004d5fc + 0xa4))) {
    os_dprintf(DAT_3004d600,DAT_3004d604,DAT_3004d648);
    os_printf(DAT_3004d64c);
  }
  return 0xb;
}

/* ----------------------------------------------------------------
 * chp9_handle_usb_command @ 0x3004D170  (примерный размер ~956 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_3004cbe4, os_dprintf, os_printf, valid_type
 * Вызывают: core_handle_ep0
 * Константы: 0x3004D170
 * Данные: DAT_3004d5fc, DAT_3004d600, DAT_3004d604, DAT_3004d650, DAT_3004d654, DAT_3004d658, DAT_3004d65c, DAT_3004d660
 * ---------------------------------------------------------------- */
int chp9_handle_usb_command(int param_1,byte *param_2,undefined1 param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  
  bVar2 = false;
  uVar5 = (uint)*(byte *)(param_1 + 0x34);
  bVar7 = *param_2 & 0x60;
  bVar1 = *param_2;
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004d5fc + 0xa0)) && (3 < *(int *)(DAT_3004d5fc + 0xa4))) {
    os_dprintf(DAT_3004d600,DAT_3004d604,DAT_3004d650);
    os_printf(DAT_3004d654,*param_2,param_2[1],*(undefined2 *)(param_2 + 2),
              *(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 6));
  }
  if (bVar7 == 0) {
    iVar3 = FUN_3004cbe4(param_1,param_2,param_3);
    if (iVar3 != 0xb) {
      return iVar3;
    }
  }
  else if ((bVar7 == 0x40) && (param_2[1] == *(byte *)(param_1 + 0xc0))) {
    valid_type(0x29);
    if ((2 < *(int *)(DAT_3004d5fc + 0xa0)) && (2 < *(int *)(DAT_3004d5fc + 0xa4))) {
      os_dprintf(DAT_3004d600,DAT_3004d604,DAT_3004d658);
      os_printf(DAT_3004d65c);
    }
    uVar5 = *(ushort *)(param_2 + 2) & 0xff;
  }
  if ((bVar1 & 3) == 1) {
    uVar5 = *(ushort *)(param_2 + 4) & 0xff;
  }
  else if ((bVar1 & 3) == 2) {
    uVar6 = 0;
    while (((int)uVar6 < (int)(uint)*(byte *)(param_1 + 0x34) && (!bVar2))) {
      iVar3 = 0;
      while (((*(int *)(uVar6 * 0x14 + *(int *)(param_1 + 0x30) + 0x10) != 0 &&
              (iVar3 < (int)(uint)**(byte **)(uVar6 * 0x14 + *(int *)(param_1 + 0x30) + 0x10))) &&
             (!bVar2))) {
        if ((ushort)*(byte *)(iVar3 * 0x3c +
                              *(int *)(*(int *)(uVar6 * 0x14 + *(int *)(param_1 + 0x30) + 0x10) + 4)
                             + 0xb) ==
            (*(ushort *)(param_2 + 4) & 0xf | *(ushort *)(param_2 + 4) & 0x80)) {
          bVar2 = true;
          uVar5 = uVar6;
        }
        iVar3 = iVar3 + 1;
      }
      uVar6 = uVar6 + 1;
    }
  }
  if ((uVar5 & 0xff) < (uint)*(byte *)(param_1 + 0x34)) {
    valid_type(0x29);
    if ((3 < *(int *)(DAT_3004d5fc + 0xa0)) && (3 < *(int *)(DAT_3004d5fc + 0xa4))) {
      os_dprintf(DAT_3004d600,DAT_3004d604,DAT_3004d670);
      os_printf(DAT_3004d674,uVar5 & 0xff);
    }
    iVar3 = (**(code **)(*(int *)(param_1 + 0x30) + (uVar5 & 0xff) * 0x14))
                      (*(undefined4 *)
                        (*(int *)((uVar5 & 0xff) * 0x14 + *(int *)(param_1 + 0x30) + 8) + 0x10),
                       param_2,param_3);
  }
  else if (bVar7 == 0x40) {
    for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)(param_1 + 0x34); iVar3 = iVar3 + 1) {
      iVar4 = (**(code **)(*(int *)(param_1 + 0x30) + iVar3 * 0x14))
                        (*(undefined4 *)
                          (*(int *)(iVar3 * 0x14 + *(int *)(param_1 + 0x30) + 8) + 0x10),param_2,
                         param_3);
      if (iVar4 != 0xb) {
        valid_type(0x29);
        if (*(int *)(DAT_3004d5fc + 0xa0) < 3) {
          return iVar4;
        }
        if (*(int *)(DAT_3004d5fc + 0xa4) < 3) {
          return iVar4;
        }
        os_dprintf(DAT_3004d600,DAT_3004d604,DAT_3004d668);
        os_printf(DAT_3004d66c,iVar3);
        return iVar4;
      }
    }
    iVar3 = 10;
  }
  else {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004d5fc + 0xa0)) && (0 < *(int *)(DAT_3004d5fc + 0xa4))) {
      os_dprintf(DAT_3004d600,DAT_3004d604,DAT_3004d660);
      os_printf(DAT_3004d664,uVar5 & 0xff);
    }
    iVar3 = 10;
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * chp9_set_string_descriptors @ 0x3004D52C  (примерный размер ~332 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 3
 * Вызывает: core_add_string_descriptor, core_change_string_descriptor, core_release_string_descriptor
 * Вызывают: FUN_3004ffac, core_enable
 * Константы: 0x3004D52C
 * ---------------------------------------------------------------- */
void chp9_set_string_descriptors(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x108);
  if (*(char *)(param_1 + 0xc1) == '\0') {
    uVar1 = core_add_string_descriptor(param_1,*(undefined4 *)(iVar2 + 0xc));
    *(undefined1 *)(param_1 + 0xc1) = uVar1;
  }
  else {
    core_change_string_descriptor
              (param_1,*(undefined1 *)(param_1 + 0xc1),*(undefined4 *)(iVar2 + 0xc));
  }
  if (*(char *)(param_1 + 0xc2) == '\0') {
    uVar1 = core_add_string_descriptor(param_1,*(undefined4 *)(iVar2 + 0x10));
    *(undefined1 *)(param_1 + 0xc2) = uVar1;
  }
  else {
    core_change_string_descriptor
              (param_1,*(undefined1 *)(param_1 + 0xc2),*(undefined4 *)(iVar2 + 0x10));
  }
  if (*(int *)(iVar2 + 0x14) == 0) {
    if (*(char *)(param_1 + 0xc3) != '\0') {
      core_release_string_descriptor(param_1,*(undefined1 *)(param_1 + 0xc3));
      *(undefined1 *)(param_1 + 0xc3) = 0;
    }
  }
  else if (*(char *)(param_1 + 0xc3) == '\0') {
    uVar1 = core_add_string_descriptor(param_1,*(undefined4 *)(iVar2 + 0x14));
    *(undefined1 *)(param_1 + 0xc3) = uVar1;
  }
  else {
    core_change_string_descriptor
              (param_1,*(undefined1 *)(param_1 + 0xc3),*(undefined4 *)(iVar2 + 0x14));
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3004d678 @ 0x3004D678  (примерный размер ~132 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3004d6fc
 * Константы: 0x3004D678
 * Данные: DAT_3004e5fc, DAT_3004e600, DAT_3004e604, DAT_3004e608, DAT_3004e60c, DAT_3004e610
 * ---------------------------------------------------------------- */
undefined4 FUN_3004d678(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0xc) == 6) {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
      os_dprintf(DAT_3004e600,DAT_3004e604,0x70);
      uVar1 = DAT_3004e60c;
      if (*(char *)(param_2 + 1) == '\0') {
        uVar1 = DAT_3004e608;
      }
      os_printf(DAT_3004e610,uVar1);
    }
    uVar1 = 0xd;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004d6fc @ 0x3004D6FC  (примерный размер ~636 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_3004d678, os_dprintf, os_printf, valid_type
 * Вызывают: core_read_data, core_send_data
 * Константы: 0x3004D6FC
 * Данные: DAT_3004e5fc, DAT_3004e600, DAT_3004e604, DAT_3004e608, DAT_3004e60c, DAT_3004e6fc, DAT_3004e700, DAT_3004e704
 * ---------------------------------------------------------------- */
undefined4 FUN_3004d6fc(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (((*(int *)(param_1 + 0xc) == 5) || (*(int *)(param_1 + 0xc) == 6)) ||
     (*(int *)(param_1 + 8) == 0)) {
    if ((param_2 == 0) && (*(char *)(param_1 + 0x3c) != *(char *)(param_3 + 3))) {
      valid_type(0x29);
      if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
        os_dprintf(DAT_3004e600,DAT_3004e604,0x8e);
        os_printf(DAT_3004e700,*(undefined1 *)(param_1 + 0x3c),*(undefined1 *)(param_3 + 3));
      }
      uVar1 = 3;
    }
    else if ((param_2 == 0) || (*(int *)(param_2 + 0x28) != 4)) {
      if (*(int *)(param_3 + 0x18) == 0) {
        if ((*(int *)(param_3 + 0x1c) == 0) ||
           ((*(int *)(param_3 + 4) != 0 && (*(int *)(param_3 + 8) != 0)))) {
          uVar1 = FUN_3004d678(param_1,param_3);
        }
        else {
          valid_type(0x29);
          if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
            os_dprintf(DAT_3004e600,DAT_3004e604,0xa9);
            uVar1 = DAT_3004e60c;
            if (*(char *)(param_3 + 1) == '\0') {
              uVar1 = DAT_3004e608;
            }
            os_printf(DAT_3004e82c,uVar1);
          }
          uVar1 = 10;
        }
      }
      else {
        valid_type(0x29);
        if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
          os_dprintf(DAT_3004e600,DAT_3004e604,0x9f);
          os_printf(DAT_3004e828,param_3,*(undefined4 *)(param_3 + 0x18));
        }
        uVar1 = 8;
      }
    }
    else {
      valid_type(0x29);
      if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
        os_dprintf(DAT_3004e600,DAT_3004e604,0x96);
        uVar1 = DAT_3004e60c;
        if (*(char *)(param_3 + 1) == '\0') {
          uVar1 = DAT_3004e608;
        }
        os_printf(DAT_3004e704,uVar1);
      }
      uVar1 = 0x10;
    }
  }
  else {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
      os_dprintf(DAT_3004e600,DAT_3004e604,0x86);
      uVar1 = DAT_3004e60c;
      if (*(char *)(param_3 + 1) == '\0') {
        uVar1 = DAT_3004e608;
      }
      os_printf(DAT_3004e6fc,uVar1,*(undefined4 *)(param_1 + 8));
    }
    uVar1 = 0x10;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * core_enable @ 0x3004D978  (примерный размер ~692 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: chp9_set_string_descriptors, os_dprintf, os_printf, valid_type
 * Вызывают: core_enable_by_ctx, jslave_enable
 * Константы: 0x3004D978
 * Данные: DAT_3004e5fc, DAT_3004e600, DAT_3004e604, DAT_3004e830, DAT_3004e834, DAT_3004e954, DAT_3004e958, DAT_3004e95c
 * ---------------------------------------------------------------- */
int core_enable(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
      os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004e830);
      os_printf(DAT_3004e834);
    }
    iVar1 = 10;
  }
  else {
    valid_type(0x29);
    if ((2 < *(int *)(DAT_3004e5fc + 0xa0)) && (2 < *(int *)(DAT_3004e5fc + 0xa4))) {
      os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004e954);
      os_printf(DAT_3004e958,param_1,*(undefined4 *)(param_1 + 0xc));
    }
    if (*(int *)(param_1 + 0xc) == 4) {
      if ((*(int *)(param_1 + 0x1c) != 0) && (*(char *)(*(int *)(param_1 + 0x108) + 8) == '\0')) {
        iVar1 = *(int *)(param_1 + 0x108);
        valid_type(0x29);
        if ((2 < *(int *)(DAT_3004e5fc + 0xa0)) && (2 < *(int *)(DAT_3004e5fc + 0xa4))) {
          os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004ea70);
          os_printf(DAT_3004ea74);
        }
        *(undefined1 *)(iVar1 + 8) = 0xef;
        *(undefined1 *)(iVar1 + 9) = 2;
        *(undefined1 *)(iVar1 + 10) = 1;
      }
      chp9_set_string_descriptors(param_1);
      *(undefined4 *)(param_1 + 0xc) = 5;
      iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x24))
                        (*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x104));
      if (iVar1 == 0) {
        valid_type(0x29);
        if ((3 < *(int *)(DAT_3004e5fc + 0xa0)) && (3 < *(int *)(DAT_3004e5fc + 0xa4))) {
          os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004ea78);
          os_printf(DAT_3004ea7c);
        }
        iVar1 = 0;
      }
    }
    else {
      iVar1 = *(int *)(param_1 + 0xc);
      if (iVar1 == 2) {
        valid_type(0x29);
        if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
          os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004e95c);
          os_printf(DAT_3004e960);
        }
      }
      else if (iVar1 == 3) {
        valid_type(0x29);
        if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
          os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004e964);
          os_printf(DAT_3004e968);
        }
      }
      else {
        if (iVar1 == 5) {
          return 0;
        }
        valid_type(0x29);
        if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
          os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004e96c);
          os_printf(DAT_3004e970,*(undefined4 *)(param_1 + 0xc));
        }
      }
      iVar1 = 0x10;
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * core_enable_by_ctx @ 0x3004DC2C  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: core_enable
 * Константы: 0x3004DC2C
 * ---------------------------------------------------------------- */
void core_enable_by_ctx(undefined4 param_1)

{
  core_enable(param_1);
  return;
}

/* ----------------------------------------------------------------
 * core_disable @ 0x3004DC40  (примерный размер ~456 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: chp9_handle_set_configuration, os_dprintf, os_printf, valid_type
 * Вызывают: core_disable_by_ctx, jslave_disable
 * Константы: 0x3004DC40
 * Данные: DAT_3004e5fc, DAT_3004e600, DAT_3004e604, DAT_3004eb28, DAT_3004eb2c, DAT_3004eb30, DAT_3004eb34, DAT_3004eb38
 * ---------------------------------------------------------------- */
void core_disable(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
      os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004eb28);
      os_printf(DAT_3004eb2c);
    }
  }
  else {
    valid_type(0x29);
    if ((3 < *(int *)(DAT_3004e5fc + 0xa0)) && (3 < *(int *)(DAT_3004e5fc + 0xa4))) {
      os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004eb30);
      os_printf(DAT_3004eb34,param_1);
    }
    if ((*(int *)(param_1 + 0xc) == 5) || (*(int *)(param_1 + 0xc) == 6)) {
      iVar1 = chp9_handle_set_configuration(param_1,0);
      if ((iVar1 != 0) &&
         ((valid_type(0x29), 1 < *(int *)(DAT_3004e5fc + 0xa0) &&
          (1 < *(int *)(DAT_3004e5fc + 0xa4))))) {
        os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004ec14);
        os_printf(DAT_3004ec18,iVar1);
      }
      (**(code **)(*(int *)(param_1 + 0x24) + 4))(*(undefined4 *)(param_1 + 0x20));
      *(undefined4 *)(param_1 + 0xc) = 4;
      valid_type(0x29);
      if ((3 < *(int *)(DAT_3004e5fc + 0xa0)) && (3 < *(int *)(DAT_3004e5fc + 0xa4))) {
        os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004ec1c);
        os_printf(DAT_3004ec20,param_1);
      }
    }
    else {
      valid_type(0x29);
      if ((1 < *(int *)(DAT_3004e5fc + 0xa0)) && (1 < *(int *)(DAT_3004e5fc + 0xa4))) {
        os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004eb38);
        os_printf(DAT_3004ec10,*(undefined4 *)(param_1 + 0xc));
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * core_disable_by_ctx @ 0x3004DE08  (примерный размер ~724 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: core_disable
 * Константы: 0x3004DE08
 * ---------------------------------------------------------------- */
void core_disable_by_ctx(undefined4 param_1)

{
  core_disable(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3004e0dc @ 0x3004E0DC  (примерный размер ~176 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: core_request_complete
 * Константы: 0x3004E0DC
 * Данные: DAT_3004e5fc, DAT_3004e600, DAT_3004e604, DAT_3004f004, DAT_3004f008
 * ---------------------------------------------------------------- */
void FUN_3004e0dc(int param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  
  if (((param_2 != 0) && (*(int *)(param_2 + 0x28) != 4)) &&
     (iVar1 = *(int *)(param_2 + 0x34), iVar1 != 0)) {
    valid_type(0x29);
    if ((3 < *(int *)(DAT_3004e5fc + 0xa0)) && (3 < *(int *)(DAT_3004e5fc + 0xa4))) {
      os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004f004);
      if (param_2 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined1 *)(param_2 + 0xb);
      }
      os_printf(DAT_3004f008,iVar1,uVar2);
    }
    (**(code **)(*(int *)(param_1 + 0x24) + 0x30))(*(undefined4 *)(param_1 + 0x20),param_2,iVar1);
  }
  return;
}

/* ----------------------------------------------------------------
 * core_request_complete @ 0x3004E18C  (примерный размер ~388 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 7
 * Вызывает: FUN_3004e0dc, jvirt_to_sg, os_dprintf, os_memcpy, os_panic, os_printf, valid_type
 * Вызывают: FUN_300515b4, FUN_30054a98, core_abort_pipe
 * Константы: 0x3004E18C
 * Данные: DAT_3004e5fc, DAT_3004e600, DAT_3004e604, DAT_3004f00c, DAT_3004f0e8, DAT_3004f0ec, DAT_3004f0f0, DAT_3004f0f4
 * ---------------------------------------------------------------- */
void core_request_complete(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = *(int *)(param_2 + 0x34);
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004e5fc + 0xa0)) && (3 < *(int *)(DAT_3004e5fc + 0xa4))) {
    os_dprintf(DAT_3004e600,DAT_3004e604,0x150);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined1 *)(iVar1 + 0xb);
    }
    os_printf(DAT_3004f00c,param_2,uVar2);
  }
  *(undefined4 *)(param_2 + 0x34) = 0;
  if (((*(char *)(param_2 + 1) == '\x01') && (*(int *)(param_2 + 0x20) != 0)) &&
     (*(int *)(param_2 + 4) != *(int *)(param_2 + 8))) {
    if (**(int **)(param_2 + 8) == 0) {
      jvirt_to_sg(**(undefined4 **)(param_2 + 4),*(undefined4 *)(*(int *)(param_2 + 8) + 8),
                  *(undefined4 *)(param_2 + 0x20));
    }
    else {
      os_memcpy(**(undefined4 **)(param_2 + 8),**(undefined4 **)(param_2 + 4),
                *(undefined4 *)(param_2 + 0x20));
    }
  }
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x34) != param_2) {
      os_dprintf(DAT_3004f0e8,DAT_3004e604,DAT_3004f0ec);
      os_dprintf(DAT_3004f0f0,param_2,*(undefined4 *)(iVar1 + 0x34),*(undefined1 *)(iVar1 + 0xb));
      os_panic(DAT_3004f0f4,DAT_3004e604,DAT_3004f0ec);
    }
    *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(*(int *)(iVar1 + 0x34) + 0x2c);
    if (*(int *)(iVar1 + 0x34) == 0) {
      *(int *)(iVar1 + 0x38) = iVar1 + 0x34;
    }
  }
  FUN_3004e0dc(param_1,iVar1);
  if (*(int *)(param_2 + 0x10) != 0) {
    (**(code **)(param_2 + 0x10))(param_2);
  }
  return;
}

/* ----------------------------------------------------------------
 * core_send_data @ 0x3004E310  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 10 | Вызывает: 6
 * Вызывает: FUN_3004d6fc, jsg_to_virt, os_dprintf, os_memcpy, os_printf, valid_type
 * Вызывают: FUN_3004a8d8, FUN_30057544, FUN_30057fc8, FUN_3005db28, FUN_3005e3c4, cdc_handle_encapsulated_response, cdc_send_status, uwd_acm_notify_network_connection, uwd_acm_notify_serial_state, uwd_cdc_write
 * Константы: 0x3004E310
 * Данные: DAT_3004e5fc, DAT_3004e600, DAT_3004e604, DAT_3004ed28, DAT_3004ed2c, DAT_3004ee88, DAT_3004ee8c, DAT_3004ee90
 * ---------------------------------------------------------------- */
int core_send_data(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  bool bVar4;
  
  *(undefined1 *)(param_3 + 1) = 0;
  bVar4 = false;
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004e5fc + 0xa0)) && (3 < *(int *)(DAT_3004e5fc + 0xa4))) {
    os_dprintf(DAT_3004e600,DAT_3004e604,0xe7);
    os_printf(DAT_3004ed28);
  }
  iVar1 = FUN_3004d6fc(param_1,param_2,param_3);
  if (iVar1 == 0) {
    valid_type(0x29);
    if ((2 < *(int *)(DAT_3004e5fc + 0xa0)) && (2 < *(int *)(DAT_3004e5fc + 0xa4))) {
      os_dprintf(DAT_3004e600,DAT_3004e604,0xef);
      if (param_2 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined1 *)(param_2 + 0xb);
      }
      os_printf(DAT_3004ed2c,uVar2,*(undefined4 *)(param_3 + 0x1c));
    }
    if (((*(int *)(param_3 + 0x1c) != 0) && (*(int *)(param_3 + 4) != *(int *)(param_3 + 8))) &&
       (*(char *)(param_3 + 1) == '\0')) {
      if (**(int **)(param_3 + 8) == 0) {
        jsg_to_virt(*(undefined4 *)(*(int *)(param_3 + 8) + 8),**(undefined4 **)(param_3 + 4),
                    *(undefined4 *)(param_3 + 0x1c));
      }
      else {
        os_memcpy(**(undefined4 **)(param_3 + 4),**(undefined4 **)(param_3 + 8),
                  *(undefined4 *)(param_3 + 0x1c));
      }
    }
    *(undefined4 *)(param_3 + 0x18) = 1;
    *(undefined4 *)(param_3 + 0x20) = 0;
    *(int *)(param_3 + 0x34) = param_2;
    if ((*(int *)(*(int *)(param_1 + 0x24) + 0x2c) == 0) ||
       (iVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x2c))
                          (*(undefined4 *)(param_1 + 0x20),param_2,param_3), iVar1 == 0)) {
      if (param_2 != 0) {
        bVar4 = *(int *)(param_2 + 0x34) == 0;
        valid_type(0x29);
        if ((4 < *(int *)(DAT_3004e5fc + 0xa0)) && (4 < *(int *)(DAT_3004e5fc + 0xa4))) {
          os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004ee88);
          uVar3 = DAT_3004ee90;
          if (bVar4) {
            uVar3 = DAT_3004ee8c;
          }
          os_printf(DAT_3004ee94,param_3,*(undefined1 *)(param_2 + 0xb),uVar3);
        }
        *(undefined4 *)(param_3 + 0x2c) = 0;
        **(int **)(param_2 + 0x38) = param_3;
        *(int *)(param_2 + 0x38) = param_3 + 0x2c;
      }
      if ((*(int *)(param_1 + 200) == 0) && ((param_2 == 0 || (bVar4)))) {
        valid_type(0x29);
        if ((3 < *(int *)(DAT_3004e5fc + 0xa0)) && (3 < *(int *)(DAT_3004e5fc + 0xa4))) {
          os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004ee98);
          if (param_2 == 0) {
            uVar2 = 0;
          }
          else {
            uVar2 = *(undefined1 *)(param_2 + 0xb);
          }
          os_printf(DAT_3004ee9c,param_3,uVar2);
        }
        (**(code **)(*(int *)(param_1 + 0x24) + 0x30))
                  (*(undefined4 *)(param_1 + 0x20),param_2,param_3);
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * core_read_data @ 0x3004E33C  (примерный размер ~44 байт)
 * Модуль: data | Вызывают: 6 | Вызывает: 6
 * Вызывает: FUN_3004d6fc, jsg_to_virt, os_dprintf, os_memcpy, os_printf, valid_type
 * Вызывают: FUN_3004a8d8, FUN_3005d890, FUN_3005e140, cdc_handle_encapsulated_command, uwd_cdc_read, uwd_cdc_read_flow
 * Константы: 0x3004E33C
 * Данные: DAT_3004e5fc, DAT_3004e600, DAT_3004e604, DAT_3004ed28, DAT_3004ed2c, DAT_3004ee88, DAT_3004ee8c, DAT_3004ee90
 * ---------------------------------------------------------------- */
int core_read_data(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  bool bVar4;
  
  *(undefined1 *)(param_3 + 1) = 1;
  bVar4 = false;
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004e5fc + 0xa0)) && (3 < *(int *)(DAT_3004e5fc + 0xa4))) {
    os_dprintf(DAT_3004e600,DAT_3004e604,0xe7);
    os_printf(DAT_3004ed28);
  }
  iVar1 = FUN_3004d6fc(param_1,param_2,param_3);
  if (iVar1 == 0) {
    valid_type(0x29);
    if ((2 < *(int *)(DAT_3004e5fc + 0xa0)) && (2 < *(int *)(DAT_3004e5fc + 0xa4))) {
      os_dprintf(DAT_3004e600,DAT_3004e604,0xef);
      if (param_2 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined1 *)(param_2 + 0xb);
      }
      os_printf(DAT_3004ed2c,uVar2,*(undefined4 *)(param_3 + 0x1c));
    }
    if (((*(int *)(param_3 + 0x1c) != 0) && (*(int *)(param_3 + 4) != *(int *)(param_3 + 8))) &&
       (*(char *)(param_3 + 1) == '\0')) {
      if (**(int **)(param_3 + 8) == 0) {
        jsg_to_virt(*(undefined4 *)(*(int *)(param_3 + 8) + 8),**(undefined4 **)(param_3 + 4),
                    *(undefined4 *)(param_3 + 0x1c));
      }
      else {
        os_memcpy(**(undefined4 **)(param_3 + 4),**(undefined4 **)(param_3 + 8),
                  *(undefined4 *)(param_3 + 0x1c));
      }
    }
    *(undefined4 *)(param_3 + 0x18) = 1;
    *(undefined4 *)(param_3 + 0x20) = 0;
    *(int *)(param_3 + 0x34) = param_2;
    if ((*(int *)(*(int *)(param_1 + 0x24) + 0x2c) == 0) ||
       (iVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x2c))
                          (*(undefined4 *)(param_1 + 0x20),param_2,param_3), iVar1 == 0)) {
      if (param_2 != 0) {
        bVar4 = *(int *)(param_2 + 0x34) == 0;
        valid_type(0x29);
        if ((4 < *(int *)(DAT_3004e5fc + 0xa0)) && (4 < *(int *)(DAT_3004e5fc + 0xa4))) {
          os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004ee88);
          uVar3 = DAT_3004ee90;
          if (bVar4) {
            uVar3 = DAT_3004ee8c;
          }
          os_printf(DAT_3004ee94,param_3,*(undefined1 *)(param_2 + 0xb),uVar3);
        }
        *(undefined4 *)(param_3 + 0x2c) = 0;
        **(int **)(param_2 + 0x38) = param_3;
        *(int *)(param_2 + 0x38) = param_3 + 0x2c;
      }
      if ((*(int *)(param_1 + 200) == 0) && ((param_2 == 0 || (bVar4)))) {
        valid_type(0x29);
        if ((3 < *(int *)(DAT_3004e5fc + 0xa0)) && (3 < *(int *)(DAT_3004e5fc + 0xa4))) {
          os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004ee98);
          if (param_2 == 0) {
            uVar2 = 0;
          }
          else {
            uVar2 = *(undefined1 *)(param_2 + 0xb);
          }
          os_printf(DAT_3004ee9c,param_3,uVar2);
        }
        (**(code **)(*(int *)(param_1 + 0x24) + 0x30))
                  (*(undefined4 *)(param_1 + 0x20),param_2,param_3);
      }
    }
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * core_set_out_nak @ 0x3004E368  (примерный размер ~40 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: dcd_set_out_nak
 * Вызывают: uwd_cdc_set_out_nak
 * Константы: 0x3004E368
 * ---------------------------------------------------------------- */
void core_set_out_nak(int param_1,undefined4 param_2,undefined4 param_3)

{
  dcd_set_out_nak(*(undefined4 *)(param_1 + 0x20),param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * core_stall_pipe @ 0x3004E390  (примерный размер ~140 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: core_stall_ctrl_pipe
 * Константы: 0x3004E390
 * Данные: DAT_3004e5fc, DAT_3004e600, DAT_3004e604, DAT_3004f2b8
 * ---------------------------------------------------------------- */
void core_stall_pipe(int param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x28))
                    (*(undefined4 *)(param_1 + 0x20),param_2,param_3);
  if (((iVar1 != 0) && (valid_type(0x29), 0 < *(int *)(DAT_3004e5fc + 0xa0))) &&
     (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
    os_dprintf(DAT_3004e600,DAT_3004e604,0x1b8);
    os_printf(DAT_3004f2b8,iVar1);
  }
  return;
}

/* ----------------------------------------------------------------
 * core_stall_ctrl_pipe @ 0x3004E41C  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 4
 * Вызывает: core_stall_pipe, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30057200, FUN_3005d728, FUN_3005df90
 * Константы: 0x3004E41C
 * Данные: DAT_3004e5fc, DAT_3004e600, DAT_3004e604, DAT_3004f2bc, DAT_3004f2c0
 * ---------------------------------------------------------------- */
void core_stall_ctrl_pipe(int param_1,char param_2)

{
  if (param_2 == *(char *)(param_1 + 0x3c)) {
    core_stall_pipe(param_1,0,1);
  }
  else {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
      os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004f2bc);
      os_printf(DAT_3004f2c0);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * core_abort_pipe @ 0x3004E494  (примерный размер ~240 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 4
 * Вызывает: core_request_complete, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30058f88, core_disconnect, uwd_cdc_abort_read, uwd_cdc_abort_write
 * Константы: 0x3004E494, 0xFFFFFFFF
 * Данные: DAT_3004e5fc, DAT_3004e600, DAT_3004e604, DAT_3004f2c4, DAT_3004f2c8
 * ---------------------------------------------------------------- */
void core_abort_pipe(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  
  uVar2 = 0;
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004e5fc + 0xa0)) && (3 < *(int *)(DAT_3004e5fc + 0xa4))) {
    os_dprintf(DAT_3004e600,DAT_3004e604,DAT_3004f2c4);
    if (param_2 == 0) {
      uVar3 = 0;
      uVar4 = 0xffffffff;
    }
    else {
      uVar3 = *(undefined1 *)(param_2 + 0xb);
      uVar4 = *(undefined4 *)(param_2 + 0x28);
    }
    os_printf(DAT_3004f2c8,uVar3,uVar4);
  }
  if (param_2 != 0) {
    uVar2 = *(undefined4 *)(param_2 + 0x28);
    *(undefined4 *)(param_2 + 0x28) = 4;
  }
  (**(code **)(*(int *)(param_1 + 0x24) + 0x24))(*(undefined4 *)(param_1 + 0x20),param_2);
  if (param_2 != 0) {
    while (*(int *)(param_2 + 0x34) != 0) {
      iVar1 = *(int *)(param_2 + 0x34);
      *(undefined4 *)(iVar1 + 0x18) = 2;
      core_request_complete(param_1,iVar1);
    }
    *(undefined4 *)(param_2 + 0x28) = uVar2;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3004e584 @ 0x3004E584  (примерный размер ~552 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3004ea94
 * Константы: 0x3004E584
 * Данные: DAT_3004e5fc, DAT_3004e600, DAT_3004e604, DAT_3004f444, DAT_3004f448, DAT_3004f44c, DAT_3004f450, DAT_3004f454
 * ---------------------------------------------------------------- */
int FUN_3004e584(undefined4 param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  if (*param_2 == 0x10) {
    pcVar2 = (code *)param_2[2];
    if (pcVar2 == (code *)0x0) {
      valid_type(0x29);
      if ((0 < *(int *)(DAT_3004e5fc + 0xa0)) && (0 < *(int *)(DAT_3004e5fc + 0xa4))) {
        os_dprintf(DAT_3004e600,DAT_3004e604,0x210);
        os_printf(DAT_3004f444);
      }
      return 10;
    }
  }
  else {
    for (iVar3 = 0;
        (*(int *)(DAT_3004f448 + iVar3 * 8) != 0 && (*(int *)(DAT_3004f448 + iVar3 * 8) != *param_2)
        ); iVar3 = iVar3 + 1) {
    }
    if (*(int *)(DAT_3004f448 + iVar3 * 8) == 0) {
      valid_type(0x29);
      if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa4))) {
        os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004f458);
        os_printf(DAT_3004f45c,*param_2);
      }
      return 4;
    }
    if (*(int *)(DAT_3004f460 + iVar3 * 8) == 0) {
      valid_type(0x29);
      if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa4))) {
        os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004f514);
        os_printf(DAT_3004f518,*param_2);
      }
      return 10;
    }
    pcVar2 = *(code **)(DAT_3004f460 + iVar3 * 8);
  }
  iVar4 = 0;
  iVar3 = 0;
  while( true ) {
    if ((int)(uint)*(byte *)(param_2 + 1) <= iVar4) {
      return 0;
    }
    if (param_2[3] == 0) {
      iVar1 = (*pcVar2)(param_1,0);
    }
    else {
      iVar3 = iVar3 + (uint)(*(int *)(param_2[3] + iVar3 * 4 + 4) != 0);
      iVar1 = (*pcVar2)(param_1,*(undefined4 *)(param_2[3] + iVar3 * 4));
    }
    if (iVar1 != 0) break;
    iVar4 = iVar4 + 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004e7ac @ 0x3004E7AC  (примерный размер ~744 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_30050400, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3004ea94
 * Константы: 0x3004E7AC
 * Данные: DAT_3004f44c, DAT_3004f450, DAT_3004f454, DAT_3004f6a8, DAT_3004f6ac, DAT_3004f6b0, DAT_3004f6b4, DAT_3004f7cc
 * ---------------------------------------------------------------- */
undefined4 FUN_3004e7ac(int param_1)

{
  undefined4 uVar1;
  byte bVar2;
  byte bVar3;
  undefined4 *puVar4;
  char cVar5;
  
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004f44c + 0xa0)) && (3 < *(int *)(DAT_3004f44c + 0xa4))) {
    os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004f6a8);
    os_printf(DAT_3004f6ac);
  }
  if (*(int *)(param_1 + 0xc) == 3) {
    uVar1 = FUN_30050400((uint)*(byte *)(param_1 + 0x34) * 0x14,1,DAT_3004f454,DAT_3004f6b4);
    *(undefined4 *)(param_1 + 0x30) = uVar1;
    if (*(int *)(param_1 + 0x30) == 0) {
      uVar1 = 7;
    }
    else {
      cVar5 = '\0';
      bVar2 = 0;
      puVar4 = *(undefined4 **)(param_1 + 0x2c);
      for (bVar3 = 0; (puVar4 != (undefined4 *)0x0 && (bVar3 < *(byte *)(param_1 + 0x34)));
          bVar3 = bVar3 + 1) {
        if (*(byte *)(puVar4[3] + 8) <= bVar2) {
          puVar4 = (undefined4 *)*puVar4;
          cVar5 = cVar5 + '\x01';
          bVar2 = 0;
        }
        valid_type(0x29);
        if ((3 < *(int *)(DAT_3004f44c + 0xa0)) && (3 < *(int *)(DAT_3004f44c + 0xa4))) {
          os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004f7cc);
          os_printf(DAT_3004f7d0,bVar3,cVar5);
        }
        *(byte *)((uint)bVar3 * 0x14 + *(int *)(param_1 + 0x30) + 5) = bVar2;
        *(undefined4 **)((uint)bVar3 * 0x14 + *(int *)(param_1 + 0x30) + 8) = puVar4;
        *(byte *)((uint)bVar3 * 0x14 + *(int *)(param_1 + 0x30) + 4) = bVar3;
        *(undefined4 *)((uint)bVar3 * 0x14 + *(int *)(param_1 + 0x30) + 0x10) =
             *(undefined4 *)(*(int *)(puVar4[3] + 0xc) + (uint)bVar2 * 0x18 + 4);
        *(uint *)((uint)bVar3 * 0x14 + *(int *)(param_1 + 0x30) + 0xc) =
             *(int *)(puVar4[3] + 0xc) + (uint)bVar2 * 0x18;
        *(undefined4 *)((uint)bVar3 * 0x14 + *(int *)(param_1 + 0x30)) =
             *(undefined4 *)(*(int *)(puVar4[3] + 0xc) + (uint)bVar2 * 0x18);
        *(byte *)(*(int *)(puVar4[3] + 0xc) + (uint)bVar2 * 0x18 + 0x12) = bVar3;
        *(undefined1 *)(*(int *)(puVar4[3] + 0xc) + (uint)bVar2 * 0x18 + 9) = 0;
        bVar2 = bVar2 + 1;
      }
      *(undefined4 *)(param_1 + 0xc) = 4;
      uVar1 = 0;
    }
  }
  else {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa4))) {
      os_dprintf(DAT_3004f450,DAT_3004f454,0x288);
      os_printf(DAT_3004f6b0,*(undefined4 *)(param_1 + 0xc));
    }
    uVar1 = 0x10;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3004ea94 @ 0x3004EA94  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 5
 * Вызывает: FUN_3004e584, FUN_3004e7ac, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3004ffac, core_register_dcd
 * Константы: 0x3004EA94
 * Данные: DAT_3004f44c, DAT_3004f450, DAT_3004f454, DAT_3004fa00, DAT_3004fa04
 * ---------------------------------------------------------------- */
int FUN_3004ea94(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    if (*(byte *)(param_1 + 0x10c) <= uVar3) {
      *(undefined4 *)(param_1 + 0xc) = 3;
      iVar1 = FUN_3004e7ac(param_1);
      return iVar1;
    }
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x110) + uVar3 * 0x10);
    iVar1 = FUN_3004e584(param_1,puVar2);
    if (iVar1 != 0) break;
    uVar3 = uVar3 + 1;
  }
  valid_type(0x29);
  if (*(int *)(DAT_3004f44c + 0xa0) < 1) {
    return iVar1;
  }
  if (*(int *)(DAT_3004f44c + 0xa4) < 1) {
    return iVar1;
  }
  os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004fa00);
  os_printf(DAT_3004fa04,*puVar2);
  return iVar1;
}

/* ----------------------------------------------------------------
 * core_register_fd @ 0x3004EB50  (примерный размер ~1088 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: BSP_FreeDbg, FUN_30050400, os_dprintf, os_printf, valid_type
 * Вызывают: cdc_init
 * Константы: 0x3004EB50
 * Данные: DAT_3004f44c, DAT_3004f450, DAT_3004f454, DAT_3004fa08, DAT_3004fa0c, DAT_3004fa10, DAT_3004fa14, DAT_3004fb34
 * ---------------------------------------------------------------- */
int core_register_fd(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004f44c + 0xa0)) && (3 < *(int *)(DAT_3004f44c + 0xa4))) {
    os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004fa08);
    os_printf(DAT_3004fa0c);
  }
  if ((*(int *)(param_1 + 0xc) == 2) || (*(int *)(param_1 + 0xc) == 3)) {
    puVar2 = (undefined4 *)FUN_30050400(0x14,1,DAT_3004f454,DAT_3004fb34);
    if (puVar2 == (undefined4 *)0x0) {
      valid_type(0x29);
      if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa4))) {
        os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004fb38);
        os_printf(DAT_3004fb3c);
      }
      iVar1 = 7;
    }
    else {
      puVar2[2] = param_2;
      puVar2[4] = param_3;
      *puVar2 = 0;
      puVar2[1] = 1;
      uVar3 = (**(code **)puVar2[2])(puVar2[4]);
      puVar2[3] = uVar3;
      if (puVar2[3] == 0) {
        valid_type(0x29);
        if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa4))) {
          os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004fb40);
          os_printf(DAT_3004fb44);
        }
        BSP_FreeDbg(puVar2,DAT_3004f454,DAT_3004fb48);
        iVar1 = 10;
      }
      else {
        valid_type(0x29);
        if ((3 < *(int *)(DAT_3004f44c + 0xa0)) && (3 < *(int *)(DAT_3004f44c + 0xa4))) {
          os_dprintf(DAT_3004f450,DAT_3004f454,0x2e8);
          os_printf(DAT_3004fc3c,*(undefined1 *)(puVar2[3] + 8));
        }
        for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(puVar2[3] + 8); iVar1 = iVar1 + 1) {
          for (uVar5 = 0;
              (int)uVar5 < (int)(uint)*(byte *)(iVar1 * 0x18 + *(int *)(puVar2[3] + 0xc) + 8);
              uVar5 = uVar5 + 1) {
            for (iVar8 = 0;
                iVar8 < (int)(uint)*(byte *)(*(int *)(iVar1 * 0x18 + *(int *)(puVar2[3] + 0xc) + 4)
                                            + uVar5 * 0x10); iVar8 = iVar8 + 1) {
              iVar7 = *(int *)(*(int *)(iVar1 * 0x18 + *(int *)(puVar2[3] + 0xc) + 4) + uVar5 * 0x10
                              + 4) + iVar8 * 0x3c;
              iVar4 = (**(code **)(*(int *)(param_1 + 0x24) + 0x34))
                                (*(undefined4 *)(param_1 + 0x20),iVar7,
                                 iVar1 + (uint)*(byte *)(param_1 + 0x34) & 0xff,uVar5 & 0xff);
              if (iVar4 != 0) {
                valid_type(0x29);
                if (*(int *)(DAT_3004f44c + 0xa0) < 1) {
                  return iVar4;
                }
                if (*(int *)(DAT_3004f44c + 0xa4) < 1) {
                  return iVar4;
                }
                os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004fd44);
                os_printf(DAT_3004fd48,iVar4,puVar2);
                return iVar4;
              }
              *(undefined4 *)(iVar7 + 0x34) = 0;
              *(int *)(iVar7 + 0x38) = iVar7 + 0x34;
            }
          }
        }
        *(char *)(param_1 + 0x34) = *(char *)(param_1 + 0x34) + *(char *)(puVar2[3] + 8);
        if (*(int *)puVar2[3] < (int)(uint)*(byte *)(param_1 + 0x18)) {
          *(char *)(param_1 + 0x18) = (char)*(undefined4 *)puVar2[3];
        }
        if (*(int *)(puVar2[3] + 0x10) != 0) {
          *(undefined4 *)(param_1 + 0x1c) = 1;
        }
        for (piVar6 = (int *)(param_1 + 0x2c); *piVar6 != 0; piVar6 = (int *)*piVar6) {
        }
        *piVar6 = (int)puVar2;
        valid_type(0x29);
        if ((3 < *(int *)(DAT_3004f44c + 0xa0)) && (3 < *(int *)(DAT_3004f44c + 0xa4))) {
          os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004fe00);
          os_printf(DAT_3004fe04,*(undefined4 *)(param_1 + 0xc));
        }
        iVar1 = 0;
      }
    }
  }
  else {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa4))) {
      os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004fa10);
      os_printf(DAT_3004fa14,*(undefined4 *)(param_1 + 0xc));
    }
    iVar1 = 0x10;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * core_get_available_iface @ 0x3004EF90  (примерный размер ~24 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 0
 * Вызывают: FUN_300589d0, FUN_3005eed4
 * Константы: 0x3004EF90
 * ---------------------------------------------------------------- */
undefined1 core_get_available_iface(int param_1)

{
  return *(undefined1 *)(param_1 + 0x34);
}

/* ----------------------------------------------------------------
 * core_request_alloc @ 0x3004EFA8  (примерный размер ~584 байт)
 * Модуль: data | Вызывают: 7 | Вызывает: 7
 * Вызывает: BSP_FreeDbg, FUN_30050400, jdma_alloc, jdma_buffer_get, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3004b88c, FUN_30056d90, FUN_30057354, core_register_dcd, uwd_cdc_read, uwd_cdc_read_flow, uwd_cdc_write
 * Константы: 0x3004EFA8
 * Данные: DAT_3004f44c, DAT_3004f450, DAT_3004f454, DAT_3004ff60, DAT_3004ff64, DAT_3004ff68, DAT_3004ff6c, DAT_3004ff70
 * ---------------------------------------------------------------- */
int core_request_alloc(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  
  iVar3 = 0;
  bVar4 = 0;
  if (param_3 != (int *)0x0) {
    bVar4 = *param_3 != 0;
    if (param_3[1] != 0) {
      bVar4 = bVar4 | 2;
    }
    if (param_3[2] != 0) {
      bVar4 = bVar4 | 4;
    }
    if (((bVar4 & 1) == 0) && ((param_3[2] == 0 || (*(int *)param_3[2] == 0)))) {
      valid_type(0x29);
      if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa4))) {
        os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004ff60);
        os_printf(DAT_3004ff64);
      }
      goto LAB_3004f1cc;
    }
  }
  iVar3 = FUN_30050400(0x44,1,DAT_3004f454,DAT_3004ff68);
  if (iVar3 == 0) {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa4))) {
      os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004ff6c);
      os_printf(DAT_3004ff70);
    }
    return 0;
  }
  *(undefined4 *)(iVar3 + 0xc) = param_2;
  if ((bVar4 & *(byte *)(param_1 + 0x28)) != 0) {
    *(int **)(iVar3 + 8) = param_3;
    *(int **)(iVar3 + 4) = param_3;
    return iVar3;
  }
  iVar1 = jdma_alloc(param_2,0,0,0,2,iVar3 + 0x24);
  if (iVar1 == 0) {
    if (param_3 == (int *)0x0) {
      uVar2 = jdma_buffer_get(*(undefined4 *)(iVar3 + 0x24));
      *(undefined4 *)(iVar3 + 8) = uVar2;
    }
    else {
      *(int **)(iVar3 + 8) = param_3;
    }
    uVar2 = jdma_buffer_get(*(undefined4 *)(iVar3 + 0x24));
    *(undefined4 *)(iVar3 + 4) = uVar2;
    return iVar3;
  }
  valid_type(0x29);
  if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa4))) {
    os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3004ff74);
    os_printf(DAT_3004ff78,param_2);
  }
LAB_3004f1cc:
  if (iVar3 != 0) {
    BSP_FreeDbg(iVar3,DAT_3004f454,DAT_300500b8);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * core_request_free @ 0x3004F1F0  (примерный размер ~56 байт)
 * Модуль: data | Вызывают: 16 | Вызывает: 2
 * Вызывает: BSP_FreeDbg, jdma_free
 * Вызывают: FUN_3004a64c, FUN_30056524, FUN_30056644, FUN_30056d90, FUN_30057544, FUN_30057c70, FUN_30057fc8, FUN_30058178, FUN_30058310, FUN_3005ebb0
 *           ...
 * Константы: 0x3004F1F0
 * Данные: DAT_3004f454
 * ---------------------------------------------------------------- */
void core_request_free(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x24) != 0) {
      jdma_free(*(undefined4 *)(param_1 + 0x24));
    }
    BSP_FreeDbg(param_1,DAT_3004f454,0x3b0);
  }
  return;
}

/* ----------------------------------------------------------------
 * core_handle_ep0 @ 0x3004F228  (примерный размер ~416 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: chp9_handle_usb_command, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30051280
 * Константы: 0x3004F228
 * Данные: DAT_3004f44c, DAT_3004f450, DAT_3004f454, DAT_300500bc, DAT_300500c0, DAT_30050180, DAT_30050184, DAT_30050188
 * ---------------------------------------------------------------- */
undefined4 core_handle_ep0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  valid_type(0x29);
  if ((3 < *(int *)(DAT_3004f44c + 0xa0)) && (3 < *(int *)(DAT_3004f44c + 0xa4))) {
    os_dprintf(DAT_3004f450,DAT_3004f454,DAT_300500bc);
    os_printf(DAT_300500c0);
  }
  *(char *)(param_1 + 0x3c) = *(char *)(param_1 + 0x3c) + '\x01';
  if (*(int *)(param_1 + 0xc) == 5) {
    if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 8) == 1)) {
      if (param_2 == 0) {
        valid_type(0x29);
        if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa4))) {
          os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3005018c);
          os_printf(DAT_30050190,0);
        }
        uVar1 = 10;
      }
      else {
        *(undefined4 *)(param_1 + 0x14) = param_3;
        uVar1 = chp9_handle_usb_command(param_1,param_2,*(undefined1 *)(param_1 + 0x3c));
      }
    }
    else {
      valid_type(0x29);
      if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa4))) {
        os_dprintf(DAT_3004f450,DAT_3004f454,0x3d4);
        os_printf(DAT_30050188,*(undefined4 *)(param_1 + 8));
      }
      uVar1 = 0x10;
    }
  }
  else {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa4))) {
      os_dprintf(DAT_3004f450,DAT_3004f454,DAT_30050180);
      os_printf(DAT_30050184,*(undefined4 *)(param_1 + 0xc));
    }
    uVar1 = 0x10;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * core_wakeup_host @ 0x3004F3C8  (примерный размер ~184 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: jslave_wakeup_host
 * Константы: 0x3004F3C8
 * Данные: DAT_3004f44c, DAT_3004f450, DAT_3004f454, DAT_3005026c, DAT_30050270
 * ---------------------------------------------------------------- */
undefined4 core_wakeup_host(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x24) + 8) == 0) {
    uVar1 = 0xb;
  }
  else if (*(int *)(param_1 + 0xc4) == 0) {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_3004f44c + 0xa0)) && (0 < *(int *)(DAT_3004f44c + 0xa8))) {
      os_dprintf(DAT_3004f450,DAT_3004f454,DAT_3005026c);
      os_printf(DAT_30050270);
    }
    uVar1 = 10;
  }
  else {
    uVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 8))(*(undefined4 *)(param_1 + 0x20));
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * core_suspend @ 0x3004F480  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: j_device_get_softc, os_notify
 * Вызывают: FUN_3005310c
 * Константы: 0x3004F480
 * ---------------------------------------------------------------- */
undefined4 core_suspend(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = j_device_get_softc(*(undefined4 *)(param_1 + 0x20));
  os_notify(2,uVar1);
  *(undefined4 *)(param_1 + 0xc) = 6;
  (**(code **)(*(int *)(param_1 + 0x24) + 0x24))(*(undefined4 *)(param_1 + 0x20),0);
  *(undefined4 *)(*(int *)(param_1 + 0x38) + 0x18) = 0;
  for (piVar2 = *(int **)(param_1 + 0x2c); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    if ((piVar2[2] != 0) && (*(int *)(piVar2[2] + 0xc) != 0)) {
      (**(code **)(piVar2[2] + 0xc))(piVar2[4]);
    }
  }
  uVar1 = j_device_get_softc(*(undefined4 *)(param_1 + 0x20));
  os_notify(3,uVar1);
  return 0;
}

/* ----------------------------------------------------------------
 * core_resume @ 0x3004F53C  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: j_device_get_bus, j_device_get_softc, os_notify
 * Вызывают: FUN_30053174
 * Константы: 0x3004F53C
 * ---------------------------------------------------------------- */
undefined4 core_resume(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  j_device_get_bus(*(undefined4 *)(param_1 + 0x20));
  if (*(int *)(param_1 + 0xc) != 5) {
    uVar1 = j_device_get_softc(*(undefined4 *)(param_1 + 0x20));
    os_notify(4,uVar1);
    *(undefined4 *)(param_1 + 0xc) = 5;
    for (piVar2 = *(int **)(param_1 + 0x2c); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if (((piVar2[1] == 0) && (piVar2[2] != 0)) && (*(int *)(piVar2[2] + 0x10) != 0)) {
        (**(code **)(piVar2[2] + 0x10))(piVar2[4]);
      }
    }
    uVar1 = j_device_get_softc(*(undefined4 *)(param_1 + 0x20));
    os_notify(5,uVar1);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * core_disconnect @ 0x3004F5F8  (примерный размер ~436 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: chp9_handle_set_configuration, core_abort_pipe, j_device_get_softc, os_dprintf, os_notify, os_printf, uwe_str, valid_type
 * Вызывают: FUN_30051038
 * Константы: 0x3004F5F8
 * Данные: DAT_30050454, DAT_30050458, DAT_3005045c, DAT_30050460, DAT_30050464, DAT_30050468, DAT_3005046c, DAT_30050470
 * ---------------------------------------------------------------- */
void core_disconnect(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  valid_type(0x29);
  if ((3 < *(int *)(DAT_30050454 + 0xa0)) && (3 < *(int *)(DAT_30050454 + 0xa4))) {
    os_dprintf(DAT_30050458,DAT_3005045c,DAT_30050460);
    os_printf(DAT_30050464);
  }
  uVar1 = j_device_get_softc(*(undefined4 *)(param_1 + 0x20));
  os_notify(6,uVar1);
  if ((((*(int *)(param_1 + 0xc) != 5) && (*(int *)(param_1 + 0xc) != 4)) &&
      (*(int *)(param_1 + 0xc) != 6)) &&
     ((valid_type(0x29), 0 < *(int *)(DAT_30050454 + 0xa0) && (0 < *(int *)(DAT_30050454 + 0xa4)))))
  {
    os_dprintf(DAT_30050458,DAT_3005045c,DAT_30050468);
    os_printf(DAT_3005046c,*(undefined4 *)(param_1 + 0xc));
  }
  *(undefined4 *)(param_1 + 0xc4) = 0;
  core_abort_pipe(param_1,0);
  iVar2 = chp9_handle_set_configuration(param_1,0);
  if (((iVar2 != 0) && (valid_type(0x29), 1 < *(int *)(DAT_30050454 + 0xa0))) &&
     (1 < *(int *)(DAT_30050454 + 0xa4))) {
    os_dprintf(DAT_30050458,DAT_3005045c,DAT_30050470);
    uVar1 = uwe_str(iVar2);
    os_printf(DAT_30050474,uVar1);
  }
  *(undefined4 *)(param_1 + 0xc) = 5;
  uVar1 = j_device_get_softc(*(undefined4 *)(param_1 + 0x20));
  os_notify(7,uVar1);
  valid_type(0x29);
  if ((3 < *(int *)(DAT_30050454 + 0xa0)) && (3 < *(int *)(DAT_30050454 + 0xa4))) {
    os_dprintf(DAT_30050458,DAT_3005045c,DAT_30050478);
    os_printf(DAT_3005047c);
  }
  return;
}

/* ----------------------------------------------------------------
 * core_register_dcd @ 0x3004F7AC  (примерный размер ~1336 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 12
 * Вызывает: BSP_FreeDbg, FUN_3004ea94, FUN_30050400, core_request_alloc, j_device_get_params, j_device_set_core_ctx, jtask_init, os_dprintf, os_memcpy, os_panic, os_printf, valid_type
 * Вызывают: FUN_30055e10
 * Константы: 0x3004F7AC
 * Данные: DAT_30050454, DAT_30050458, DAT_3005045c, DAT_30050480, DAT_30050484, DAT_30050488, DAT_3005048c, DAT_30050490
 * ---------------------------------------------------------------- */
int core_register_dcd(undefined4 param_1,int param_2,int *param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar5 = 7;
  iVar4 = 0;
  valid_type(0x29);
  if ((3 < *(int *)(DAT_30050454 + 0xa0)) && (3 < *(int *)(DAT_30050454 + 0xa4))) {
    os_dprintf(DAT_30050458,DAT_3005045c,DAT_30050480);
    os_printf(DAT_30050484);
  }
  if (param_2 == 0) {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_30050454 + 0xa0)) && (0 < *(int *)(DAT_30050454 + 0xa4))) {
      os_dprintf(DAT_30050458,DAT_3005045c,DAT_30050488);
      os_printf(DAT_3005048c);
    }
    iVar5 = 10;
  }
  else if (*(int *)(param_2 + 0x50) == 0) {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_30050454 + 0xa0)) && (0 < *(int *)(DAT_30050454 + 0xa4))) {
      os_dprintf(DAT_30050458,DAT_3005045c,DAT_30050490);
      os_printf(DAT_30050494);
    }
    iVar5 = 10;
  }
  else {
    iVar2 = j_device_get_params(param_1);
    if (iVar2 == 0) {
      os_dprintf(DAT_30050498,DAT_3005045c,0x4c0);
      os_dprintf(DAT_3005049c);
      os_panic(DAT_300504a0,DAT_3005045c,0x4c0);
    }
    iVar6 = FUN_30050400(0x118,1,DAT_3005045c,DAT_300504a4);
    if (iVar6 == 0) {
      valid_type(0x29);
      if ((0 < *(int *)(DAT_30050454 + 0xa0)) && (0 < *(int *)(DAT_30050454 + 0xa4))) {
        os_dprintf(DAT_30050458,DAT_3005045c,DAT_300504a8);
        os_printf(DAT_300504ac,0);
      }
      iVar5 = 7;
    }
    else {
      iVar4 = iVar6 + 0xfc;
      uVar3 = FUN_30050400(0x18,0,DAT_3005045c,DAT_300504b0);
      *(undefined4 *)(iVar6 + 0x108) = uVar3;
      if (*(int *)(iVar2 + 0xc) != 0) {
        os_memcpy(*(undefined4 *)(iVar6 + 0x108),*(undefined4 *)(iVar2 + 0xc),0x18);
        uVar3 = FUN_30050400((uint)*(byte *)(iVar2 + 0x10) << 4,0,DAT_3005045c,DAT_300504b4);
        *(undefined4 *)(iVar6 + 0x110) = uVar3;
        if (*(int *)(iVar2 + 0x14) != 0) {
          os_memcpy(*(undefined4 *)(iVar6 + 0x110),*(undefined4 *)(iVar2 + 0x14),
                    (uint)*(byte *)(iVar2 + 0x10) << 4);
          *(undefined1 *)(iVar6 + 0x10c) = *(undefined1 *)(iVar2 + 0x10);
          *(undefined4 *)(iVar6 + 0x104) = *(undefined4 *)(iVar2 + 8);
          valid_type(0x29);
          if ((3 < *(int *)(DAT_30050454 + 0xa0)) && (3 < *(int *)(DAT_30050454 + 0xa4))) {
            os_dprintf(DAT_30050458,DAT_3005045c,DAT_300504b8);
            os_printf(DAT_300504bc,iVar6);
          }
          if (param_3 != (int *)0x0) {
            *param_3 = iVar6;
          }
          iVar5 = jtask_init(iVar6 + 0xcc,0);
          if (iVar5 == 0) {
            *(undefined4 *)(iVar6 + 0xc) = 2;
            *(undefined4 *)(iVar6 + 8) = 1;
            *(undefined1 *)(iVar6 + 0x18) = 3;
            *(int *)(iVar6 + 0x24) = param_2;
            *(undefined4 *)(iVar6 + 0x20) = param_1;
            *(undefined4 *)(iVar6 + 0x1c) = 0;
            uVar1 = (**(code **)(param_2 + 0x50))(*(undefined4 *)(iVar6 + 0x20));
            *(undefined1 *)(iVar6 + 0x28) = uVar1;
            if (*(char *)(iVar6 + 0x28) == '\0') {
              valid_type(0x29);
              if ((0 < *(int *)(DAT_30050454 + 0xa0)) && (0 < *(int *)(DAT_30050454 + 0xa4))) {
                os_dprintf(DAT_30050458,DAT_3005045c,DAT_300504c8);
                os_printf(DAT_300504cc);
              }
              iVar5 = 10;
            }
            else {
              uVar3 = core_request_alloc(iVar6,0x100,0);
              *(undefined4 *)(iVar6 + 0x38) = uVar3;
              if (*(int *)(iVar6 + 0x38) == 0) {
                valid_type(0x29);
                if ((0 < *(int *)(DAT_30050454 + 0xa0)) && (0 < *(int *)(DAT_30050454 + 0xa4))) {
                  os_dprintf(DAT_30050458,DAT_3005045c,DAT_300504d0);
                  os_printf(DAT_300504d4);
                }
                iVar5 = 7;
              }
              else {
                iVar5 = FUN_3004ea94(iVar6);
                if (iVar5 == 0) {
                  valid_type(0x29);
                  if ((3 < *(int *)(DAT_30050454 + 0xa0)) && (3 < *(int *)(DAT_30050454 + 0xa4))) {
                    os_dprintf(DAT_30050458,DAT_3005045c,DAT_300504d8);
                    os_printf(DAT_300504dc,*(undefined4 *)(iVar6 + 0xc));
                  }
                  j_device_set_core_ctx(param_1,iVar6);
                  return 0;
                }
              }
            }
          }
          else {
            valid_type(0x29);
            if ((0 < *(int *)(DAT_30050454 + 0xa0)) && (0 < *(int *)(DAT_30050454 + 0xa4))) {
              os_dprintf(DAT_30050458,DAT_3005045c,DAT_300504c0);
              os_printf(DAT_300504c4,iVar5);
            }
          }
        }
      }
    }
  }
  valid_type(0x29);
  if ((0 < *(int *)(DAT_30050454 + 0xa0)) && (0 < *(int *)(DAT_30050454 + 0xa4))) {
    os_dprintf(DAT_30050458,DAT_3005045c,0x520);
    os_printf(DAT_300504e0);
  }
  if (iVar4 != 0) {
    if (*(int *)(iVar4 + 0x14) != 0) {
      BSP_FreeDbg(*(undefined4 *)(iVar4 + 0x14),DAT_3005045c,DAT_300504e4);
    }
    if (*(int *)(iVar4 + 0xc) != 0) {
      BSP_FreeDbg(*(undefined4 *)(iVar4 + 0xc),DAT_3005045c,DAT_300504e8);
    }
  }
  if (iVar6 != 0) {
    BSP_FreeDbg(iVar6,DAT_3005045c,DAT_300504ec);
  }
  return iVar5;
}

/* ----------------------------------------------------------------
 * FUN_3004fce4 @ 0x3004FCE4  (примерный размер ~364 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: BSP_FreeDbg
 * Вызывают: FUN_3004ffac, core_unregister_dcd
 * Константы: 0x3004FCE4
 * Данные: DAT_3005045c, DAT_300504f0, DAT_300504f4, DAT_300504f8
 * ---------------------------------------------------------------- */
void FUN_3004fce4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_1 + 0x2c);
  while (puVar5 != (undefined4 *)0x0) {
    for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)(puVar5[3] + 8); iVar3 = iVar3 + 1) {
      for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)(iVar3 * 0x18 + *(int *)(puVar5[3] + 0xc) + 8);
          iVar2 = iVar2 + 1) {
        for (iVar1 = 0;
            iVar1 < (int)(uint)*(byte *)(*(int *)(iVar3 * 0x18 + *(int *)(puVar5[3] + 0xc) + 4) +
                                        iVar2 * 0x10); iVar1 = iVar1 + 1) {
          (**(code **)(*(int *)(param_1 + 0x24) + 0x38))
                    (*(undefined4 *)(param_1 + 0x20),
                     *(int *)(*(int *)(iVar3 * 0x18 + *(int *)(puVar5[3] + 0xc) + 4) + iVar2 * 0x10
                             + 4) + iVar1 * 0x3c);
        }
      }
    }
    if (puVar5[2] != 0) {
      (**(code **)(puVar5[2] + 0x14))(puVar5[4]);
    }
    puVar4 = (undefined4 *)*puVar5;
    BSP_FreeDbg(puVar5,DAT_3005045c,DAT_300504f0);
    puVar5 = puVar4;
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    BSP_FreeDbg(*(undefined4 *)(param_1 + 0x30),DAT_3005045c,DAT_300504f4);
  }
  *(undefined1 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0xc) = 2;
  *DAT_300504f8 = 0;
  return;
}

/* ----------------------------------------------------------------
 * core_unregister_dcd @ 0x3004FE50  (примерный размер ~348 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 9
 * Вызывает: BSP_FreeDbg, FUN_3004fce4, chp9_handle_set_configuration, core_request_free, j_device_set_core_ctx, jtask_uninit, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30055d50
 * Константы: 0x3004FE50
 * Данные: DAT_30050454, DAT_30050458, DAT_3005045c, DAT_300504fc, DAT_30050500, DAT_30050504, DAT_30050508, DAT_3005050c
 * ---------------------------------------------------------------- */
void core_unregister_dcd(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_30050454 + 0xa0)) && (0 < *(int *)(DAT_30050454 + 0xa4))) {
      os_dprintf(DAT_30050458,DAT_3005045c,DAT_300504fc);
      os_printf(DAT_30050500);
    }
  }
  else {
    j_device_set_core_ctx(*(undefined4 *)(param_1 + 0x20),0);
    iVar1 = chp9_handle_set_configuration(param_1,0);
    if (((iVar1 != 0) && (valid_type(0x29), 1 < *(int *)(DAT_30050454 + 0xa0))) &&
       (1 < *(int *)(DAT_30050454 + 0xa4))) {
      os_dprintf(DAT_30050458,DAT_3005045c,DAT_30050504);
      os_printf(DAT_30050508,iVar1);
    }
    FUN_3004fce4(param_1);
    if (*(int *)(param_1 + 0xcc) != 0) {
      jtask_uninit(*(undefined4 *)(param_1 + 0xcc));
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      core_request_free(*(undefined4 *)(param_1 + 0x38));
    }
    if (*(int *)(param_1 + 0x110) != 0) {
      BSP_FreeDbg(*(undefined4 *)(param_1 + 0x110),DAT_3005045c,DAT_3005050c);
    }
    if (*(int *)(param_1 + 0x108) != 0) {
      BSP_FreeDbg(*(undefined4 *)(param_1 + 0x108),DAT_3005045c,DAT_30050510);
    }
    BSP_FreeDbg(param_1,DAT_3005045c,DAT_30050514);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_3004ffac @ 0x3004FFAC  (примерный размер ~488 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 13
 * Вызывает: BSP_FreeDbg, FUN_3004ea94, FUN_3004fce4, chp9_handle_set_configuration, chp9_set_string_descriptors, init_endpoints2, j_device_get_softc, os_delay_ms, os_dprintf, os_notify, os_printf, uninit_endpoints, valid_type
 * Константы: 0x3004FFAC
 * Данные: DAT_30050454, DAT_30050458, DAT_3005045c, DAT_30050518, DAT_3005051c, DAT_30050520, DAT_30050524, DAT_30050528
 * ---------------------------------------------------------------- */
void FUN_3004ffac(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = j_device_get_softc(*(undefined4 *)(param_1 + 0x20));
  BSP_FreeDbg(*(undefined4 *)(param_1 + 0x110),DAT_3005045c,DAT_30050518);
  *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(param_1 + 0xec);
  *(undefined1 *)(param_1 + 0x10c) = *(undefined1 *)(param_1 + 0xe8);
  iVar2 = chp9_handle_set_configuration(param_1,0);
  if (((iVar2 != 0) && (valid_type(0x29), 1 < *(int *)(DAT_30050454 + 0xa0))) &&
     (1 < *(int *)(DAT_30050454 + 0xa4))) {
    os_dprintf(DAT_30050458,DAT_3005045c,0x630);
    os_printf(DAT_3005051c,iVar2);
  }
  FUN_3004fce4(param_1);
  uninit_endpoints(uVar1);
  init_endpoints2(uVar1);
  iVar2 = FUN_3004ea94(param_1);
  if (iVar2 == 0) {
    BSP_FreeDbg(*(undefined4 *)(param_1 + 0x108),DAT_3005045c,DAT_30050520);
    *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0xe4);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0xf4);
    if (*(int *)(param_1 + 0xc) == 5) {
      chp9_set_string_descriptors(param_1);
    }
    os_delay_ms(100);
    if (*(int *)(*(int *)(param_1 + 0x24) + 0x10) != 0) {
      (**(code **)(*(int *)(param_1 + 0x24) + 0x10))(*(undefined4 *)(param_1 + 0x20));
    }
  }
  valid_type(0x29);
  if ((2 < *(int *)(DAT_30050454 + 0xa0)) && (2 < *(int *)(DAT_30050454 + 0xa4))) {
    os_dprintf(DAT_30050458,DAT_3005045c,DAT_30050524);
    os_printf(DAT_30050528,iVar2);
  }
  *(undefined4 *)(param_1 + 0xf8) = 0;
  if (*(int *)(param_1 + 0xd0) != 0) {
    (**(code **)(param_1 + 0xd0))(*(undefined4 *)(param_1 + 0xd4),iVar2);
  }
  uVar1 = j_device_get_softc(*(undefined4 *)(param_1 + 0x20));
  os_notify(9,uVar1);
  return;
}

/* ----------------------------------------------------------------
 * core_reconfig @ 0x30050194  (примерный размер ~620 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 9
 * Вызывает: BSP_FreeDbg, FUN_30050400, j_device_get_softc, jtask_schedule_d, os_dprintf, os_memcpy, os_notify, os_printf, valid_type
 * Вызывают: jslave_reconfig
 * Константы: 0x30050194
 * Данные: DAT_30050454, DAT_30050458, DAT_3005045c, DAT_3005052c, DAT_30050530, DAT_30050534, DAT_30050538, DAT_3005053c
 * ---------------------------------------------------------------- */
undefined4 core_reconfig(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 == 0) {
    valid_type(0x29);
    if ((0 < *(int *)(DAT_30050454 + 0xa0)) && (0 < *(int *)(DAT_30050454 + 0xa4))) {
      os_dprintf(DAT_30050458,DAT_3005045c,DAT_3005052c);
      os_printf(DAT_30050530);
    }
    uVar2 = 10;
  }
  else {
    uVar1 = j_device_get_softc(*(undefined4 *)(param_1 + 0x20));
    os_notify(8,uVar1);
    if (*(int *)(param_1 + 0xf8) == 0) {
      uVar1 = FUN_30050400((uint)*(byte *)(param_2 + 0x10) << 4,1,DAT_3005045c,DAT_3005053c);
      *(undefined4 *)(param_1 + 0xec) = uVar1;
      if (*(int *)(param_1 + 0xec) == 0) {
        valid_type(0x29);
        if ((0 < *(int *)(DAT_30050454 + 0xa0)) && (0 < *(int *)(DAT_30050454 + 0xa4))) {
          os_dprintf(DAT_30050458,DAT_3005045c,DAT_30050540);
          os_printf(DAT_30050544);
        }
        uVar2 = 7;
      }
      else {
        uVar1 = FUN_30050400(0x18,1,DAT_3005045c,DAT_30050548);
        *(undefined4 *)(param_1 + 0xe4) = uVar1;
        if (*(int *)(param_1 + 0xe4) == 0) {
          valid_type(0x29);
          if ((0 < *(int *)(DAT_30050454 + 0xa0)) && (0 < *(int *)(DAT_30050454 + 0xa4))) {
            os_dprintf(DAT_30050458,DAT_3005045c,DAT_3005054c);
            os_printf(DAT_30050550);
          }
          uVar2 = 7;
          BSP_FreeDbg(*(undefined4 *)(param_1 + 0xec),DAT_3005045c,DAT_30050554);
        }
        else {
          *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_1 + 0xc);
          *(undefined4 *)(param_1 + 0xf8) = 1;
          if (*(int *)(*(int *)(param_1 + 0x24) + 0x18) != 0) {
            (**(code **)(*(int *)(param_1 + 0x24) + 0x18))(*(undefined4 *)(param_1 + 0x20));
          }
          os_memcpy(*(undefined4 *)(param_1 + 0xec),*(undefined4 *)(param_2 + 0x14),
                    (uint)*(byte *)(param_2 + 0x10) << 4);
          *(undefined1 *)(param_1 + 0xe8) = *(undefined1 *)(param_2 + 0x10);
          os_memcpy(*(undefined4 *)(param_1 + 0xe4),*(undefined4 *)(param_2 + 0xc),0x18);
          *(undefined4 *)(param_1 + 0xd0) = param_3;
          *(undefined4 *)(param_1 + 0xd4) = param_4;
          jtask_schedule_d(*(undefined4 *)(param_1 + 0xcc),0,DAT_3005055c,param_1,DAT_3005045c,
                           DAT_30050558);
        }
      }
    }
    else {
      valid_type(0x29);
      if ((0 < *(int *)(DAT_30050454 + 0xa0)) && (0 < *(int *)(DAT_30050454 + 0xa4))) {
        os_dprintf(DAT_30050458,DAT_3005045c,DAT_30050534);
        os_printf(DAT_30050538);
      }
      uVar2 = 10;
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30050400 @ 0x30050400  (примерный размер ~352 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 2
 * Вызывает: BSP_MallocDbg, memset
 * Вызывают: FUN_3004e7ac, core_reconfig, core_register_dcd, core_register_fd, core_request_alloc
 * Константы: 0x30050400
 * ---------------------------------------------------------------- */
void * FUN_30050400(size_t param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)BSP_MallocDbg(param_1,0,param_3,param_4);
  if ((param_2 == 1) && (__s != (void *)0x0)) {
    memset(__s,0,param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * FUN_30050560 @ 0x30050560  (примерный размер ~2304 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: os_bus_space_read_4, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3005264c, FUN_30052a84
 * Константы: 0x30050560
 * Данные: DAT_30051504, DAT_30051508, DAT_3005150c, DAT_30051510, DAT_30051514, DAT_30051518, DAT_30051624, DAT_30051628
 * ---------------------------------------------------------------- */
void FUN_30050560(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0xe5);
    os_printf(DAT_30051510);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0xe8);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x44);
    os_printf(DAT_30051514,0x44,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0xea);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x48);
    os_printf(DAT_30051518,0x48,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0xec);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x4c);
    os_printf(DAT_30051624,0x4c,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0xee);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x50);
    os_printf(DAT_30051628,0x50,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0xf1);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x800);
    os_printf(DAT_3005162c,0x800,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0xf3);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30051630);
    os_printf(DAT_30051634,DAT_30051630,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0xf5);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_300516ec);
    os_printf(DAT_300516f0,DAT_300516ec,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0xf8);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),8);
    os_printf(DAT_300516f4,8,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0xfa);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0xc);
    os_printf(DAT_300516f8,0xc,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0xfc);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x10);
    os_printf(DAT_30051794,0x10,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0xfe);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x14);
    os_printf(DAT_30051798,0x14,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0x100);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x18);
    os_printf(DAT_3005179c,0x18,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051880);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x24);
    os_printf(DAT_30051884,0x24,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0x104);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x28);
    os_printf(DAT_30051888,0x28,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,DAT_3005188c);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30051890);
    os_printf(DAT_30051894,DAT_30051890,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051934);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30051938);
    os_printf(DAT_3005193c,DAT_30051938,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0x10c);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30051940);
    os_printf(DAT_30051944,DAT_30051940,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051948);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x810);
    os_printf(DAT_3005194c,0x810,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,0x110);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30051a6c);
    os_printf(DAT_30051a70,DAT_30051a6c,uVar1);
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051a74);
    os_printf(DAT_30051a78);
  }
  for (uVar2 = 0; uVar2 < *(byte *)(param_1 + 0xa2c); uVar2 = uVar2 + 1) {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
      os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051a7c);
      uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),uVar2 * 0x20 + 0x900);
      os_printf(DAT_30051a80,uVar2 * 0x20 + 0x900,uVar2,uVar1);
    }
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
      os_dprintf(DAT_30051508,DAT_3005150c,0x118);
      uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30051a84 + uVar2 * 0x20);
      os_printf(DAT_30051a88,DAT_30051a84 + uVar2 * 0x20,uVar2,uVar1);
    }
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051b70);
    os_printf(DAT_30051b74);
  }
  for (uVar2 = 0; uVar2 < *(byte *)(param_1 + 0xa2c); uVar2 = uVar2 + 1) {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
      os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051b78);
      uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),uVar2 * 0x20 + 0xb00);
      os_printf(DAT_30051b7c,uVar2 * 0x20 + 0xb00,uVar2,uVar1);
    }
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
      os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051b80);
      uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30051b84 + uVar2 * 0x20);
      os_printf(DAT_30051b88,DAT_30051b84 + uVar2 * 0x20,uVar2,uVar1);
    }
  }
  valid_type(0x2a);
  if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051ca4);
    os_printf(DAT_30051ca8);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30050e60 @ 0x30050E60  (примерный размер ~284 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 6
 * Вызывает: os_bus_space_read_4, os_bus_space_write_4, os_delay_us, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30051038, FUN_30052290, FUN_30054a98, FUN_3005532c
 * Константы: 0x30050E60, 0x80000000
 * Данные: DAT_30051504, DAT_30051508, DAT_3005150c, DAT_30051cac, DAT_30051cb0, DAT_30051cb4, DAT_30051cb8, DAT_30051cbc
 * ---------------------------------------------------------------- */
void FUN_30050e60(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_30051504 + 0xa0)) && (3 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051cac,param_4,uVar3);
    os_printf(DAT_30051cb0,param_2);
  }
  while( true ) {
    os_delay_us(10);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x10);
    uVar2 = uVar2 + 1;
    if (DAT_30051cb4 < uVar2) break;
    if ((uVar1 & 0x80000000) != 0) {
      os_bus_space_write_4(*(undefined4 *)(param_1 + 8),0x10,param_2 << 6 | 0x20);
      do {
        uVar2 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x10);
      } while ((uVar2 & 0x20) != 0);
      os_delay_us(1);
      return;
    }
  }
  valid_type(0x2a);
  if (*(int *)(DAT_30051504 + 0xa0) < 1) {
    return;
  }
  if (*(int *)(DAT_30051504 + 0xa8) < 1) {
    return;
  }
  os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051cb8);
  os_printf(DAT_30051cbc);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30050f7c @ 0x30050F7C  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 3
 * Вызывает: jdma_phys_addr, os_bus_space_read_4, os_bus_space_write_4
 * Вызывают: FUN_30051038, FUN_30051280, FUN_300520c8, FUN_300528d0
 * Константы: 0x30050F7C, 0x40000000, 0x0A000000, 0x3FFFFFFF, 0x84000000
 * Данные: DAT_30051d9c, DAT_30051da0
 * ---------------------------------------------------------------- */
void FUN_30050f7c(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  
  *(undefined4 *)(*(int *)(param_1 + 0xacc) + *(int *)(param_1 + 0xad0) * 8) = 0x40000000;
  *(uint *)(*(int *)(param_1 + 0xacc) + *(int *)(param_1 + 0xad0) * 8) =
       *(uint *)(*(int *)(param_1 + 0xacc) + *(int *)(param_1 + 0xad0) * 8) & DAT_30051d9c | 0x40;
  puVar3 = (uint *)(*(int *)(param_1 + 0xacc) + *(int *)(param_1 + 0xad0) * 8);
  *puVar3 = *puVar3 | 0xa000000;
  *(uint *)(*(int *)(param_1 + 0xacc) + *(int *)(param_1 + 0xad0) * 8) =
       *(uint *)(*(int *)(param_1 + 0xacc) + *(int *)(param_1 + 0xad0) * 8) & 0x3fffffff;
  uVar1 = jdma_phys_addr(*(undefined4 *)(param_1 + 0xac8),*(int *)(param_1 + 0xad0) << 3);
  os_bus_space_write_4(*(undefined4 *)(param_1 + 8),DAT_30051da0,uVar1);
  uVar2 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0xb00);
  os_bus_space_write_4(*(undefined4 *)(param_1 + 8),0xb00,uVar2 | 0x84000000);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30051038 @ 0x30051038  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_30050e60, FUN_30050f7c, core_disconnect, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30053248
 * Константы: 0x30051038, 0x08000000, 0xFFFFF80F
 * Данные: DAT_30051504, DAT_30051508, DAT_3005150c, DAT_30051938, DAT_30051a6c, DAT_30051da4, DAT_30051ea0
 * ---------------------------------------------------------------- */
void FUN_30051038(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_30051504 + 0xa0)) && (3 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051da4);
    os_printf(DAT_30051ea0);
  }
  core_disconnect(*(undefined4 *)(param_1 + 4));
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  for (uVar2 = 0; uVar2 < *(byte *)(param_1 + 0xa2d); uVar2 = uVar2 + 1) {
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),uVar2 * 0x20 + 0xb00);
    os_bus_space_write_4(*(undefined4 *)(param_1 + 8),uVar2 * 0x20 + 0xb00,uVar1 | 0x8000000);
  }
  os_bus_space_write_4(*(undefined4 *)(param_1 + 8),DAT_30051a6c,0x22f);
  os_bus_space_write_4(*(undefined4 *)(param_1 + 8),0x810,0x227);
  os_bus_space_write_4(*(undefined4 *)(param_1 + 8),DAT_30051938,*(undefined4 *)(param_1 + 0xa3c));
  uVar2 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x800);
  os_bus_space_write_4(*(undefined4 *)(param_1 + 8),0x800,uVar2 & 0xfffff80f);
  FUN_30050e60(param_1,0x10);
  FUN_30050f7c(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30051150 @ 0x30051150  (примерный размер ~304 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 6
 * Вызывает: j_device_get_softc, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30051280, FUN_300556dc
 * Константы: 0x30051150, 0xFFDFFFFF, 0x10000000, 0x00200000
 * Данные: DAT_30051504, DAT_30051508, DAT_3005150c, DAT_30051ffc, DAT_30052000
 * ---------------------------------------------------------------- */
undefined4 FUN_30051150(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = j_device_get_softc(param_1);
  if (param_2 == 0) {
    uVar3 = 0;
    if (*(int *)(iVar1 + 0x40) == 0) {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = *(uint *)(param_2 + 0x20);
  }
  iVar2 = iVar1 + uVar3 * 0x50;
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_30051504 + 0xa0)) && (3 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,DAT_30051ffc);
    os_printf(DAT_30052000,uVar3,param_3);
  }
  if (*(int *)(iVar2 + 0x2c) == 0) {
    iVar4 = (uVar3 >> 1) * 0x20 + 0xb00;
  }
  else {
    iVar4 = (uVar3 >> 1) * 0x20 + 0x900;
  }
  uVar3 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),iVar4);
  if (param_2 != 0) {
    *(int *)(iVar2 + 0x44) = param_3;
  }
  if (param_3 == 0) {
    uVar3 = uVar3 & 0xffdfffff | 0x10000000;
  }
  else {
    uVar3 = uVar3 | 0x200000;
  }
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),iVar4,uVar3);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30051280 @ 0x30051280  (примерный размер ~276 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_30050f7c, FUN_30051150, core_handle_ep0, os_dprintf, os_memcpy, os_printf, valid_type
 * Вызывают: FUN_300528d0
 * Константы: 0x30051280
 * Данные: DAT_30051504, DAT_30051508, DAT_3005150c, DAT_30052004, DAT_30052008, DAT_3005200c, DAT_30052160
 * ---------------------------------------------------------------- */
void FUN_30051280(undefined4 *param_1)

{
  int iVar1;
  undefined1 auStack_18 [8];
  
  iVar1 = 0x40 - (*(uint *)(param_1[0x2b3] + param_1[0x2b4] * 8) & DAT_30052004);
  if (iVar1 == 8) {
    os_memcpy(auStack_18,*(undefined4 *)param_1[7],8);
    iVar1 = core_handle_ep0(param_1[1],auStack_18,param_1[9]);
    if (iVar1 == 0) {
      return;
    }
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
      os_dprintf(DAT_30051508,DAT_3005150c,0x1d8);
      os_printf(DAT_30052160,iVar1);
    }
    FUN_30051150(*param_1,0,1);
  }
  else {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
      os_dprintf(DAT_30051508,DAT_3005150c,DAT_30052008);
      os_printf(DAT_3005200c,iVar1,*(undefined4 *)(param_1[0x2b3] + param_1[0x2b4] * 8));
    }
  }
  FUN_30050f7c(param_1);
  return;
}

/* ----------------------------------------------------------------
 * FUN_30051394 @ 0x30051394  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: os_bus_space_read_4, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30053248
 * Константы: 0x30051394
 * Данные: DAT_30051504, DAT_30051508, DAT_3005150c, DAT_300516ec, DAT_30052164, DAT_30052168
 * ---------------------------------------------------------------- */
void FUN_30051394(int param_1)

{
  uint uVar1;
  
  uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_300516ec);
  if ((uVar1 & 2) == 0) {
    *(uint *)(param_1 + 0x24) = (uint)((uVar1 & 4) == 0) * 2 + 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x24) = 2;
  }
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_30051504 + 0xa0)) && (3 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,DAT_30052164);
    os_printf(DAT_30052168,*(undefined4 *)(param_1 + 0x24));
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30051430 @ 0x30051430  (примерный размер ~388 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: __urem32, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_300527b8
 * Константы: 0x30051430, 0x40000000, 0x0A000000, 0x3FFFFFFF, 0x84000000
 * Данные: DAT_30051504, DAT_30051508, DAT_3005150c, DAT_30051da0, DAT_30052268, DAT_3005226c, DAT_30052270, DAT_30052274
 * ---------------------------------------------------------------- */
void FUN_30051430(int param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = *(char **)(param_1 + 0x90);
  valid_type(0x2a);
  if ((2 < *(int *)(DAT_30051504 + 0xa0)) && (2 < *(int *)(DAT_30051504 + 0xa8))) {
    os_dprintf(DAT_30051508,DAT_3005150c,DAT_30052268);
    os_printf(DAT_3005226c);
  }
  if (((*(int *)(pcVar3 + 0x1c) != 0) && (*pcVar3 != '\0')) &&
     (iVar1 = __urem32(*(undefined4 *)(pcVar3 + 0x20),*(undefined2 *)(param_1 + 0x88)), iVar1 == 0))
  {
    if (*(int *)(param_1 + 0x7c) == 0) {
      if (*(int *)(pcVar3 + 0x20) == *(int *)(pcVar3 + 0x1c)) {
        **(undefined4 **)(param_1 + 0xb0) = 0x40000000;
        **(uint **)(param_1 + 0xb0) = **(uint **)(param_1 + 0xb0) | 0xa000000;
        *(undefined4 *)(*(int *)(param_1 + 0xb0) + 4) = 0;
        **(uint **)(param_1 + 0xb0) = **(uint **)(param_1 + 0xb0) & 0x3fffffff;
        os_bus_space_write_4
                  (*(undefined4 *)(param_1 + 8),DAT_30051da0,*(undefined4 *)(param_1 + 0xb0));
        uVar2 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0xb00);
        os_bus_space_write_4(*(undefined4 *)(param_1 + 8),0xb00,uVar2 | 0x84000000);
      }
    }
    else {
      valid_type(0x2a);
      if ((0 < *(int *)(DAT_30051504 + 0xa0)) && (0 < *(int *)(DAT_30051504 + 0xa8))) {
        os_dprintf(DAT_30051508,DAT_3005150c,DAT_30052270);
        os_printf(DAT_30052274);
      }
    }
    *pcVar3 = '\0';
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300515b4 @ 0x300515B4  (примерный размер ~548 байт)
 * Модуль: data | Вызывают: 4 | Вызывает: 7
 * Вызывает: __urem32, core_request_complete, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_300520c8, FUN_30052290, FUN_300528d0, FUN_30052a84
 * Константы: 0x40000000, 0x3FFFFFFF, 0x84000000, 0x300515B4, 0x0A000000, 0x0E000000
 * Данные: DAT_30051da0, DAT_300523f8, DAT_300523fc, DAT_30052400, DAT_30052404, DAT_30052408, DAT_3005240c
 * ---------------------------------------------------------------- */
void FUN_300515b4(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  
  iVar5 = param_1 + param_2 * 0x50;
  pcVar4 = *(char **)(iVar5 + 0x40);
  uVar1 = param_2 >> 1;
  valid_type(0x2a);
  if ((2 < *(int *)(DAT_300523f8 + 0xa0)) && (2 < *(int *)(DAT_300523f8 + 0xa8))) {
    os_dprintf(DAT_300523fc,DAT_30052400,DAT_30052404);
    os_printf(DAT_30052408,param_2);
  }
  if (((*(int *)(pcVar4 + 0x1c) == 0) || (*pcVar4 == '\0')) ||
     (iVar2 = __urem32(*(undefined4 *)(pcVar4 + 0x20),*(undefined2 *)(iVar5 + 0x38)), iVar2 != 0)) {
    *(undefined4 *)(param_2 * 0x50 + param_1 + 0x40) = 0;
    if (*(int *)(pcVar4 + 0x18) != 2) {
      pcVar4[0x18] = '\x05';
      pcVar4[0x19] = '\0';
      pcVar4[0x1a] = '\0';
      pcVar4[0x1b] = '\0';
    }
    core_request_complete(*(undefined4 *)(param_1 + 4),pcVar4);
  }
  else {
    if (*(int *)(iVar5 + 0x2c) == 0) {
      if (*(int *)(pcVar4 + 0x20) == *(int *)(pcVar4 + 0x1c)) {
        **(undefined4 **)(iVar5 + 0x60) = 0x40000000;
        **(uint **)(iVar5 + 0x60) = **(uint **)(iVar5 + 0x60) | 0xa000000;
        *(undefined4 *)(*(int *)(iVar5 + 0x60) + 4) = 0;
        **(uint **)(iVar5 + 0x60) = **(uint **)(iVar5 + 0x60) & 0x3fffffff;
        os_bus_space_write_4
                  (*(undefined4 *)(param_1 + 8),DAT_30051da0 + uVar1 * 0x20,
                   *(undefined4 *)(iVar5 + 0x60));
        uVar3 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0xb00);
        os_bus_space_write_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0xb00,uVar3 | 0x84000000);
      }
    }
    else {
      **(undefined4 **)(iVar5 + 0x60) = 0x40000000;
      **(uint **)(iVar5 + 0x60) = **(uint **)(iVar5 + 0x60) | 0xe000000;
      *(undefined4 *)(*(int *)(iVar5 + 0x60) + 4) = 0;
      **(uint **)(iVar5 + 0x60) = **(uint **)(iVar5 + 0x60) & 0x3fffffff;
      os_bus_space_write_4
                (*(undefined4 *)(param_1 + 8),DAT_3005240c + uVar1 * 0x20,
                 *(undefined4 *)(iVar5 + 0x60));
      uVar3 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0x900);
      os_bus_space_write_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0x900,uVar3 | 0x84000000);
    }
    *pcVar4 = '\0';
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300517d8 @ 0x300517D8  (примерный размер ~108 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: __udiv32
 * Вызывают: FUN_30051ff4, FUN_3005264c
 * Константы: 0x300517D8
 * ---------------------------------------------------------------- */
int FUN_300517d8(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 * 0x50 + param_1 + 0x40);
  iVar1 = 1;
  if ((param_2 >> 1 != 0) && (*(int *)(iVar2 + 0x1c) != 0)) {
    iVar1 = __udiv32(*(int *)(iVar2 + 0x1c) + -1,
                     *(undefined2 *)(*(int *)(param_2 * 0x50 + param_1 + 0x48) + 0x24));
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30051844 @ 0x30051844  (примерный размер ~404 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: BSP_FreeDbg, jdma_free
 * Вызывают: FUN_300519d8, FUN_30051c34, uninit_endpoints
 * Константы: 0x30051844
 * Данные: DAT_30052400, DAT_3005274c, DAT_30052750, DAT_3005284c
 * ---------------------------------------------------------------- */
void FUN_30051844(int param_1)

{
  int iVar1;
  
  while (iVar1 = *(int *)(param_1 + 0x48), iVar1 != 0) {
    if (*(int *)(*(int *)(param_1 + 0x48) + 0xc) == 0) {
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x10);
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x48) + 0xc) + 0x10) =
           *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x10);
    }
    **(undefined4 **)(*(int *)(param_1 + 0x48) + 0x10) =
         *(undefined4 *)(*(int *)(param_1 + 0x48) + 0xc);
    BSP_FreeDbg(iVar1,DAT_30052400,DAT_3005274c);
  }
  while (iVar1 = *(int *)(param_1 + 0x40), iVar1 != 0) {
    if (*(int *)(*(int *)(param_1 + 0x40) + 0xc) == 0) {
      *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x10);
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x40) + 0xc) + 0x10) =
           *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x10);
    }
    **(undefined4 **)(*(int *)(param_1 + 0x40) + 0x10) =
         *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xc);
    BSP_FreeDbg(iVar1,DAT_30052400,DAT_30052750);
  }
  while (iVar1 = *(int *)(param_1 + 0x38), iVar1 != 0) {
    if (*(int *)(*(int *)(param_1 + 0x38) + 0xc) == 0) {
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(*(int *)(param_1 + 0x38) + 0x10);
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x38) + 0xc) + 0x10) =
           *(undefined4 *)(*(int *)(param_1 + 0x38) + 0x10);
    }
    **(undefined4 **)(*(int *)(param_1 + 0x38) + 0x10) =
         *(undefined4 *)(*(int *)(param_1 + 0x38) + 0xc);
    BSP_FreeDbg(iVar1,DAT_30052400,DAT_3005284c);
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    jdma_free(*(undefined4 *)(param_1 + 0x30));
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return;
}

/* ----------------------------------------------------------------
 * FUN_300519d8 @ 0x300519D8  (примерный размер ~468 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 8
 * Вызывает: FUN_30051844, FUN_30056278, jdma_alloc, jdma_phys_addr, jdma_virt_addr, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30051c34, init_endpoints, init_endpoints2
 * Константы: 0x300519D8
 * Данные: DAT_300523f8, DAT_300523fc, DAT_30052400, DAT_30052850, DAT_30052854, DAT_30052998, DAT_3005299c, DAT_300529a0
 * ---------------------------------------------------------------- */
int FUN_300519d8(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  
  iVar1 = jdma_alloc(param_2 << 3,4,0,0,1,param_1 + 0x30);
  if (iVar1 == 0) {
    uVar2 = jdma_virt_addr(*(undefined4 *)(param_1 + 0x30),0);
    *(undefined4 *)(param_1 + 0x34) = uVar2;
    for (uVar4 = 0; uVar4 < param_2; uVar4 = uVar4 + 1) {
      piVar3 = (int *)FUN_30056278(0x14,1,DAT_30052400,DAT_30052998);
      if (piVar3 == (int *)0x0) {
        valid_type(0x2a);
        if ((0 < *(int *)(DAT_300523f8 + 0xa0)) && (0 < *(int *)(DAT_300523f8 + 0xa8))) {
          os_dprintf(DAT_300523fc,DAT_30052400,DAT_3005299c);
          os_printf(DAT_300529a0,0);
        }
        FUN_30051844(param_1);
        return 7;
      }
      *piVar3 = *(int *)(param_1 + 0x34) + uVar4 * 8;
      iVar1 = jdma_phys_addr(*(undefined4 *)(param_1 + 0x30),uVar4 << 3);
      piVar3[1] = iVar1;
      piVar3[3] = 0;
      piVar3[4] = *(int *)(param_1 + 0x3c);
      **(int **)(param_1 + 0x3c) = (int)piVar3;
      *(int **)(param_1 + 0x3c) = piVar3 + 3;
    }
    *(uint *)(param_1 + 0x2c) = param_2;
    iVar1 = 0;
  }
  else {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_300523f8 + 0xa0)) && (0 < *(int *)(DAT_300523f8 + 0xa8))) {
      os_dprintf(DAT_300523fc,DAT_30052400,DAT_30052850);
      os_printf(DAT_30052854,0);
    }
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30051bac @ 0x30051BAC  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: __udiv32
 * Вызывают: FUN_30051c34
 * Константы: 0x30051BAC
 * ---------------------------------------------------------------- */
int FUN_30051bac(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_3 == 0) {
    iVar2 = 1;
  }
  else if (*(int *)(*(int *)(param_2 + 4) + 8) == 0) {
    iVar2 = __udiv32(param_3 + *(int *)(param_1 + 0x24) + -1,*(undefined4 *)(param_1 + 0x24));
  }
  else {
    iVar2 = 0;
    for (uVar3 = 0; uVar3 < param_3;
        uVar3 = uVar3 + *(int *)(iVar1 + *(int *)(*(int *)(param_2 + 4) + 8) + 8)) {
      iVar1 = iVar2 * 0xc;
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

/* ----------------------------------------------------------------
 * FUN_30051c34 @ 0x30051C34  (примерный размер ~960 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_30051844, FUN_300519d8, FUN_30051bac, __urem32, os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: FUN_30051ff4
 * Константы: 0x30051C34, 0x40000000, 0x04000000, 0x0A000000, 0x3FFFFFFF
 * Данные: DAT_30052004, DAT_300523f8, DAT_300523fc, DAT_30052400, DAT_30052afc, DAT_30052b00, DAT_30052c68, DAT_30052c6c
 * ---------------------------------------------------------------- */
int FUN_30051c34(int param_1,char *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar1 = FUN_30051bac(param_1,param_2,param_3);
  valid_type(0x2a);
  if ((4 < *(int *)(DAT_300523f8 + 0xa0)) && (4 < *(int *)(DAT_300523f8 + 0xa8))) {
    os_dprintf(DAT_300523fc,DAT_30052400,DAT_30052afc);
    os_printf(DAT_30052b00,0,uVar1);
  }
  if (*(uint *)(param_1 + 0x2c) < uVar1) {
    FUN_30051844(param_1);
    iVar2 = FUN_300519d8(param_1,uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  **(undefined4 **)(param_1 + 0x34) = 0x40000000;
  uVar4 = 0;
  iVar2 = 0;
  do {
    if (uVar1 <= uVar4) {
      iVar3 = __urem32(param_3,*(undefined2 *)(param_1 + 0xc));
      if (((iVar3 != 0) || (param_2[2] != '\0')) ||
         ((*param_2 != '\0' &&
          ((*(int *)(param_2 + 0x1c) != 0 &&
           (param_3 + *(int *)(param_2 + 0x20) == *(int *)(param_2 + 0x1c))))))) {
        puVar5 = (uint *)(*(int *)(param_1 + 0x34) + uVar4 * 8 + -8);
        *puVar5 = *puVar5 | 0x4000000;
        *param_2 = '\0';
        param_2[2] = '\0';
        valid_type(0x2a);
        if ((4 < *(int *)(DAT_300523f8 + 0xa0)) && (4 < *(int *)(DAT_300523f8 + 0xa8))) {
          os_dprintf(DAT_300523fc,DAT_30052400,DAT_30052dac);
          os_printf(DAT_30052db0,0);
        }
      }
      puVar5 = (uint *)(*(int *)(param_1 + 0x34) + uVar4 * 8 + -8);
      *puVar5 = *puVar5 | 0xa000000;
      if (param_3 != iVar2) {
        os_dprintf(DAT_30052c68,DAT_30052400,0xae0);
        os_dprintf(DAT_30052ee0);
        os_panic(DAT_30052c74,DAT_30052400,0xae0);
      }
      return 0;
    }
    if (*(int *)(*(int *)(param_2 + 4) + 8) == 0) {
      if (*(uint *)(param_1 + 0x24) < (uint)(param_3 - iVar2)) {
        uVar6 = *(uint *)(param_1 + 0x24);
      }
      else {
        uVar6 = param_3 - iVar2;
      }
      *(int *)(*(int *)(param_1 + 0x34) + uVar4 * 8 + 4) =
           iVar2 + *(int *)(*(int *)(param_2 + 4) + 4) + *(int *)(param_2 + 0x20);
    }
    else {
      uVar6 = *(uint *)(uVar4 * 0xc + *(int *)(*(int *)(param_2 + 4) + 8) + 8);
      if (*(uint *)(param_1 + 0x24) < uVar6) {
        os_dprintf(DAT_30052c68,DAT_30052400,DAT_30052c6c);
        os_dprintf(DAT_30052c70,0,uVar6);
        os_panic(DAT_30052c74,DAT_30052400,DAT_30052c6c);
      }
      if (*(uint *)(param_1 + 0x24) < uVar6) {
        return 10;
      }
      *(undefined4 *)(*(int *)(param_1 + 0x34) + uVar4 * 8 + 4) =
           *(undefined4 *)(uVar4 * 0xc + *(int *)(*(int *)(param_2 + 4) + 8) + 4);
    }
    if (uVar4 != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x34) + uVar4 * 8) = 0;
      *(uint *)(*(int *)(param_1 + 0x34) + uVar4 * 8) =
           *(uint *)(*(int *)(param_1 + 0x34) + uVar4 * 8) & 0x3fffffff;
    }
    *(uint *)(*(int *)(param_1 + 0x34) + uVar4 * 8) =
         *(uint *)(*(int *)(param_1 + 0x34) + uVar4 * 8) & DAT_30052c78 | uVar6 & DAT_30052004;
    iVar2 = iVar2 + uVar6;
    valid_type(0x2a);
    if ((4 < *(int *)(DAT_300523f8 + 0xa0)) && (4 < *(int *)(DAT_300523f8 + 0xa8))) {
      os_dprintf(DAT_300523fc,DAT_30052400,DAT_30052da4);
      os_printf(DAT_30052da8,0,uVar4,*(undefined4 *)(*(int *)(param_1 + 0x34) + uVar4 * 8),uVar6,
                *(undefined4 *)(*(int *)(param_1 + 0x34) + uVar4 * 8 + 4));
    }
    uVar4 = uVar4 + 1;
  } while( true );
}

/* ----------------------------------------------------------------
 * FUN_30051ff4 @ 0x30051FF4  (примерный размер ~212 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 4
 * Вызывает: FUN_300517d8, FUN_30051c34, os_bus_space_read_4, os_bus_space_write_4
 * Вызывают: FUN_300520c8, FUN_300551c0
 * Константы: 0x30051FF4, 0x3FFFFFFF, 0x84000000
 * Данные: DAT_3005240c
 * ---------------------------------------------------------------- */
int FUN_30051ff4(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1 + param_2 * 0x50;
  iVar3 = *(int *)(iVar4 + 0x40);
  uVar1 = param_2 >> 1;
  FUN_300517d8(param_1,param_2);
  iVar3 = FUN_30051c34(iVar4 + 0x2c,iVar3,*(undefined4 *)(iVar3 + 0x1c));
  if (iVar3 == 0) {
    **(uint **)(iVar4 + 0x60) = **(uint **)(iVar4 + 0x60) & 0x3fffffff;
    os_bus_space_write_4
              (*(undefined4 *)(param_1 + 8),DAT_3005240c + uVar1 * 0x20,
               *(undefined4 *)(iVar4 + 0x60));
    uVar2 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0x900);
    os_bus_space_write_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0x900,uVar2 | 0x84000000);
  }
  return iVar3;
}

/* ----------------------------------------------------------------
 * FUN_300520c8 @ 0x300520C8  (примерный размер ~456 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_30050f7c, FUN_300515b4, FUN_30051ff4, os_bus_space_read_4, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30053248
 * Константы: 0x300520C8
 * Данные: DAT_300523f8, DAT_300523fc, DAT_30052400, DAT_3005240c, DAT_30053020, DAT_30053024, DAT_30053028, DAT_300530e8
 * ---------------------------------------------------------------- */
void FUN_300520c8(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x40);
  if (iVar3 != 0) {
    if ((((param_2 & 0x20) != 0) && (valid_type(0x2a), 0 < *(int *)(DAT_300523f8 + 0xa0))) &&
       (0 < *(int *)(DAT_300523f8 + 0xa8))) {
      os_dprintf(DAT_300523fc,DAT_30052400,DAT_30053020);
      os_printf(DAT_30053024,0);
    }
    if ((param_2 & 1) != 0) {
      if (*(int *)(iVar3 + 0x1c) == 0) {
        FUN_30050f7c(param_1);
        FUN_300515b4(param_1,0);
        return;
      }
      uVar2 = **(uint **)(param_1 + 0x60) & DAT_30053028;
      *(uint *)(iVar3 + 0x20) =
           *(int *)(iVar3 + 0x20) + ((*(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x20)) - uVar2);
      if ((*(uint *)(iVar3 + 0x20) < *(uint *)(iVar3 + 0x1c)) && (uVar2 == 0)) {
        FUN_30051ff4(param_1,0);
      }
      else {
        FUN_30050f7c(param_1);
        FUN_300515b4(param_1,0);
      }
    }
    if ((param_2 & 4) != 0) {
      valid_type(0x2a);
      if ((0 < *(int *)(DAT_300523f8 + 0xa0)) && (0 < *(int *)(DAT_300523f8 + 0xa8))) {
        os_dprintf(DAT_300523fc,DAT_30052400,0x2dc);
        os_printf(DAT_300530e8,0);
      }
      valid_type(0x2a);
      if ((0 < *(int *)(DAT_300523f8 + 0xa0)) && (0 < *(int *)(DAT_300523f8 + 0xa8))) {
        os_dprintf(DAT_300523fc,DAT_30052400,DAT_300530ec);
        uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_3005240c);
        os_printf(DAT_300530f0,0,uVar1);
      }
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30052290 @ 0x30052290  (примерный размер ~820 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 6
 * Вызывает: FUN_30050e60, FUN_300515b4, os_bus_space_read_4, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30053248
 * Константы: 0x30052290, 0x08000000
 * Данные: DAT_300523f8, DAT_300523fc, DAT_30052400, DAT_3005321c, DAT_30053220, DAT_30053224, DAT_30053228, DAT_3005322c
 * ---------------------------------------------------------------- */
void FUN_30052290(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1 + param_2 * 0xa0;
  iVar3 = *(int *)(iVar4 + 0x40);
  uVar2 = 0;
  if ((((param_3 & 0x200) != 0) && (valid_type(0x2a), 0 < *(int *)(DAT_300523f8 + 0xa0))) &&
     (0 < *(int *)(DAT_300523f8 + 0xa8))) {
    os_dprintf(DAT_300523fc,DAT_30052400,DAT_3005321c);
    os_printf(DAT_30053220,0);
  }
  if ((((param_3 & 0x20) != 0) && (valid_type(0x2a), 0 < *(int *)(DAT_300523f8 + 0xa0))) &&
     (0 < *(int *)(DAT_300523f8 + 0xa8))) {
    os_dprintf(DAT_300523fc,DAT_30052400,0x3cc);
    os_printf(DAT_30053224,0,param_2);
  }
  if ((iVar3 != 0) && ((param_3 & 1) != 0)) {
    do {
      if (*(uint *)(*(int *)(iVar4 + 0x60) + uVar2 * 8) >> 0x1e != 2) {
        valid_type(0x2a);
        if ((0 < *(int *)(DAT_30053344 + 0xa0)) && (0 < *(int *)(DAT_30053344 + 0xa8))) {
          os_dprintf(DAT_30053348,DAT_3005334c,0x3f8);
          os_printf(DAT_30053358,0,*(undefined4 *)(*(int *)(iVar4 + 0x60) + uVar2 * 8));
        }
        break;
      }
      valid_type(0x2a);
      if ((2 < *(int *)(DAT_300523f8 + 0xa0)) && (2 < *(int *)(DAT_300523f8 + 0xa8))) {
        os_dprintf(DAT_300523fc,DAT_30052400,DAT_30053228);
        os_printf(DAT_3005322c,0,param_2,*(undefined4 *)(*(int *)(iVar4 + 0x60) + uVar2 * 8));
      }
      if ((*(uint *)(*(int *)(iVar4 + 0x60) + uVar2 * 8) & 0x8000000) != 0) {
        *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar3 + 0x1c);
        valid_type(0x2a);
        if ((2 < *(int *)(DAT_300523f8 + 0xa0)) && (2 < *(int *)(DAT_30053344 + 0xa8))) {
          os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053350);
          os_printf(DAT_30053354,0,*(undefined4 *)(iVar3 + 0x20));
        }
        break;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(iVar4 + 0x58));
    FUN_300515b4(param_1,param_2 * 2);
  }
  if ((param_3 & 2) != 0) {
    valid_type(0x2a);
    if ((3 < *(int *)(DAT_30053344 + 0xa0)) && (3 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_3005335c);
      os_printf(DAT_30053360,param_2 * 2);
    }
    FUN_30050e60(param_1,param_2);
  }
  if ((param_3 & 4) != 0) {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30053344 + 0xa0)) && (0 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053364);
      os_printf(DAT_30053368,0,param_2);
    }
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30053344 + 0xa0)) && (0 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053490);
      uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30053494 + param_2 * 0x20);
      os_printf(DAT_30053498,0,param_2,uVar1);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300525c4 @ 0x300525C4  (примерный размер ~136 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_3005264c
 * Константы: 0x300525C4, 0x40000000, 0x0A000000
 * Данные: DAT_30052c78, DAT_30053028
 * ---------------------------------------------------------------- */
void FUN_300525c4(int param_1,int param_2,uint param_3)

{
  **(undefined4 **)(param_1 + 0x34) = 0x40000000;
  **(uint **)(param_1 + 0x34) = **(uint **)(param_1 + 0x34) | 0xa000000;
  if (*(uint *)(param_1 + 0x24) < param_3) {
    param_3 = *(uint *)(param_1 + 0x24);
  }
  *(uint *)(param_1 + 0x28) = param_3;
  **(uint **)(param_1 + 0x34) = **(uint **)(param_1 + 0x34) & DAT_30052c78 | param_3 & DAT_30053028;
  *(int *)(*(int *)(param_1 + 0x34) + 4) =
       *(int *)(*(int *)(param_2 + 4) + 4) + *(int *)(param_2 + 0x20);
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005264c @ 0x3005264C  (примерный размер ~364 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 8
 * Вызывает: FUN_30050560, FUN_300517d8, FUN_300525c4, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_panic, valid_type
 * Вызывают: FUN_300527b8, FUN_30052a84, FUN_300551c0
 * Константы: 0x3005264C, 0x3FFFFFFF, 0x84000000, 0x88000000
 * Данные: DAT_30052c68, DAT_30052c74, DAT_30053344, DAT_3005334c, DAT_3005349c, DAT_300534a0, DAT_300535a8
 * ---------------------------------------------------------------- */
void FUN_3005264c(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_1 + param_2 * 0x50;
  iVar4 = *(int *)(iVar5 + 0x40);
  uVar1 = param_2 >> 1;
  if ((*(uint *)(*(int *)(iVar4 + 4) + 4) & 3) != 0) {
    os_dprintf(DAT_30052c68,DAT_3005334c,DAT_3005349c);
    os_dprintf(DAT_300534a0);
    os_panic(DAT_30052c74,DAT_3005334c,DAT_3005349c);
  }
  iVar2 = FUN_300517d8(param_1,param_2);
  if (uVar1 == 0) {
    iVar2 = 0x40;
  }
  else {
    iVar2 = (uint)*(ushort *)(iVar5 + 0x38) * iVar2 - *(int *)(iVar4 + 0x20);
  }
  FUN_300525c4(iVar5 + 0x2c,iVar4,iVar2);
  **(uint **)(iVar5 + 0x60) = **(uint **)(iVar5 + 0x60) & 0x3fffffff;
  os_bus_space_write_4
            (*(undefined4 *)(param_1 + 8),DAT_300535a8 + uVar1 * 0x20,*(undefined4 *)(iVar5 + 0x60))
  ;
  if (*(int *)(iVar4 + 0x40) == 0) {
    uVar3 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0xb00);
    os_bus_space_write_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0xb00,uVar3 | 0x84000000);
  }
  else {
    uVar3 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0xb00);
    os_bus_space_write_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0xb00,uVar3 | 0x88000000);
  }
  if (((uVar1 != 0) && (valid_type(0x2a), 4 < *(int *)(DAT_30053344 + 0xa0))) &&
     (4 < *(int *)(DAT_30053344 + 0xa8))) {
    FUN_30050560(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300527b8 @ 0x300527B8  (примерный размер ~280 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_30051430, FUN_3005264c, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_300528d0
 * Константы: 0x300527B8
 * Данные: DAT_30053028, DAT_30053344, DAT_30053348, DAT_3005334c, DAT_30053358, DAT_300536f0, DAT_300536f4, DAT_300536f8
 * ---------------------------------------------------------------- */
void FUN_300527b8(int param_1,int param_2)

{
  if (**(uint **)(param_1 + 0xb0) >> 0x1e == 2) {
    *(uint *)(param_2 + 0x20) =
         *(int *)(param_2 + 0x20) + (0x40 - (**(uint **)(param_1 + 0xb0) & DAT_30053028));
    valid_type(0x2a);
    if ((4 < *(int *)(DAT_30053344 + 0xa0)) && (4 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_300536f0);
      os_printf(DAT_300536f4,**(undefined4 **)(param_1 + 0xb0));
    }
  }
  else {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30053344 + 0xa0)) && (0 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_300536f8);
      os_printf(DAT_30053358,0,**(undefined4 **)(param_1 + 0xb0));
    }
  }
  if (*(uint *)(param_2 + 0x20) < *(uint *)(param_2 + 0x1c)) {
    FUN_3005264c(param_1,1);
  }
  else {
    FUN_30051430(param_1);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_300528d0 @ 0x300528D0  (примерный размер ~436 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_30050f7c, FUN_30051280, FUN_300515b4, FUN_300527b8, os_bus_space_read_4, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30053248
 * Константы: 0x300528D0, 0x01000000
 * Данные: DAT_30053344, DAT_30053348, DAT_3005334c, DAT_300535a8, DAT_30053848, DAT_3005384c, DAT_30053850, DAT_30053854
 * ---------------------------------------------------------------- */
void FUN_300528d0(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_2 & 1) != 0) {
    if (*(int *)(param_1 + 0x90) == 0) {
      if ((*(uint *)(*(int *)(param_1 + 0xacc) + *(int *)(param_1 + 0xad0) * 8) & 0x1000000) == 0) {
        FUN_30050f7c(param_1);
      }
    }
    else {
      FUN_300527b8(param_1,*(int *)(param_1 + 0x90));
    }
  }
  if ((param_2 & 8) != 0) {
    valid_type(0x2a);
    if ((2 < *(int *)(DAT_30053344 + 0xa0)) && (2 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053848);
      os_printf(DAT_3005384c,param_2);
    }
    FUN_30051280(param_1);
  }
  if ((param_2 & 0x20) != 0) {
    valid_type(0x2a);
    if ((2 < *(int *)(DAT_30053344 + 0xa0)) && (2 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053850);
      os_printf(DAT_30053854,0);
    }
    FUN_300515b4(param_1,1);
  }
  if ((param_2 & 4) != 0) {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30053344 + 0xa0)) && (0 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053858);
      os_printf(DAT_3005385c,0);
    }
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30053344 + 0xa0)) && (0 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053860);
      uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_300535a8);
      os_printf(DAT_30053864,0,uVar1);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30052a84 @ 0x30052A84  (примерный размер ~1120 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_30050560, FUN_300515b4, FUN_3005264c, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30053248
 * Константы: 0x30052A84, 0x08000000
 * Данные: DAT_30053028, DAT_30053344, DAT_30053348, DAT_3005334c, DAT_30053354, DAT_30053358, DAT_300535a8, DAT_300539c0
 * ---------------------------------------------------------------- */
void FUN_30052a84(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_2 * 2 + 1;
  iVar4 = param_1 + iVar5 * 0x50;
  iVar3 = *(int *)(iVar4 + 0x40);
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_30053344 + 0xa0)) && (3 < *(int *)(DAT_30053344 + 0xa8))) {
    os_dprintf(DAT_30053348,DAT_3005334c,DAT_300539c0);
    os_printf(DAT_300539c4,param_2);
  }
  valid_type(0x2a);
  if ((4 < *(int *)(DAT_30053344 + 0xa0)) && (4 < *(int *)(DAT_30053344 + 0xa8))) {
    os_dprintf(DAT_30053348,DAT_3005334c,DAT_300539c8);
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),param_2 * 0x20 + 0xb00);
    os_printf(DAT_300539cc,param_3,uVar1);
  }
  valid_type(0x2a);
  if ((4 < *(int *)(DAT_30053344 + 0xa0)) && (4 < *(int *)(DAT_30053344 + 0xa8))) {
    FUN_30050560(param_1);
  }
  if ((((param_3 & 0x200) != 0) && (valid_type(0x2a), 0 < *(int *)(DAT_30053344 + 0xa0))) &&
     (0 < *(int *)(DAT_30053344 + 0xa8))) {
    os_dprintf(DAT_30053348,DAT_3005334c,DAT_300539d0);
    os_printf(DAT_300539d4,0);
  }
  if ((iVar3 != 0) && ((param_3 & 1) != 0)) {
    valid_type(0x2a);
    if ((4 < *(int *)(DAT_30053344 + 0xa0)) && (4 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053aec);
      os_printf(DAT_30053af0,param_2);
    }
    if ((**(uint **)(iVar4 + 0x60) >> 0x1e == 2) && ((**(uint **)(iVar4 + 0x60) & 0x8000000) != 0))
    {
      valid_type(0x2a);
      if ((4 < *(int *)(DAT_30053344 + 0xa0)) && (4 < *(int *)(DAT_30053344 + 0xa8))) {
        os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053af4);
        os_printf(DAT_30053af8,0,param_2,**(undefined4 **)(iVar4 + 0x60));
      }
      *(uint *)(iVar3 + 0x20) =
           *(int *)(iVar3 + 0x20) +
           (*(int *)(iVar4 + 0x54) - (**(uint **)(iVar4 + 0x60) & DAT_30053028));
      valid_type(0x2a);
      if ((2 < *(int *)(DAT_30053344 + 0xa0)) && (2 < *(int *)(DAT_30053344 + 0xa8))) {
        os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053afc);
        os_printf(DAT_30053354,0,*(undefined4 *)(iVar3 + 0x20));
      }
    }
    else {
      valid_type(0x2a);
      if ((0 < *(int *)(DAT_30053344 + 0xa0)) && (0 < *(int *)(DAT_30053344 + 0xa8))) {
        os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053bf4);
        os_printf(DAT_30053358,0,**(undefined4 **)(iVar4 + 0x60));
      }
    }
    if ((*(uint *)(iVar3 + 0x20) < *(uint *)(iVar3 + 0x1c)) &&
       ((**(uint **)(iVar4 + 0x60) & DAT_30053028) == 0)) {
      FUN_3005264c(param_1,iVar5);
    }
    else {
      FUN_300515b4(param_1,iVar5);
    }
  }
  if ((param_3 & 2) != 0) {
    valid_type(0x2a);
    if ((3 < *(int *)(DAT_30053344 + 0xa0)) && (3 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053bf8);
      os_printf(DAT_30053bfc,iVar5);
    }
    uVar2 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30053cf8);
    os_bus_space_write_4(*(undefined4 *)(param_1 + 8),DAT_30053cf8,uVar2 | 0x400);
  }
  if ((param_3 & 4) != 0) {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30053344 + 0xa0)) && (0 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053cfc);
      os_printf(DAT_30053d00,0,param_2);
    }
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_30053344 + 0xa0)) && (0 < *(int *)(DAT_30053344 + 0xa8))) {
      os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053d04);
      uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_300535a8 + param_2 * 0x20);
      os_printf(DAT_30053d08,0,param_2,uVar1);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30052ee4 @ 0x30052EE4  (примерный размер ~552 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: os_bus_space_read_4, os_bus_space_write_4
 * Константы: 0x30052EE4
 * Данные: DAT_30053d0c, DAT_30053e64, DAT_30053e68, DAT_30053f78
 * ---------------------------------------------------------------- */
bool FUN_30052ee4(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  bool bVar5;
  
  uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x14);
  *(uint *)(param_1 + 0xa30) = *(uint *)(param_1 + 0xa30) | uVar1 & *(uint *)(param_1 + 0xa34);
  uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30053d0c);
  *(uint *)(param_1 + 0xa38) = uVar1 | *(uint *)(param_1 + 0xa38);
  if (*(int *)(param_1 + 0xa30) == 0) {
    bVar5 = false;
  }
  else {
    uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x14);
    if ((uVar1 & 0x1000) != 0) {
      *(int *)(param_1 + 0xac0) = *(int *)(param_1 + 0xac0) + 1;
    }
    os_bus_space_write_4(*(undefined4 *)(param_1 + 8),0x14,*(undefined4 *)(param_1 + 0xa30));
    if ((*(uint *)(param_1 + 0xa30) & 0x40000) != 0) {
      if ((*(uint *)(param_1 + 0xa38) & 1) != 0) {
        uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30053e64);
        *(uint *)(param_1 + 0xa40) = uVar1 | *(uint *)(param_1 + 0xa40);
        os_bus_space_write_4
                  (*(undefined4 *)(param_1 + 8),DAT_30053e64,*(undefined4 *)(param_1 + 0xa40));
      }
      for (uVar1 = 1; (int)uVar1 < (int)(uint)*(byte *)(param_1 + 0xa2c); uVar1 = uVar1 + 1) {
        if ((*(uint *)(param_1 + 0xa38) & 1 << (uVar1 & 0xff)) != 0) {
          puVar4 = (uint *)(param_1 + uVar1 * 8 + 0xa40);
          uVar2 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30053e64 + uVar1 * 0x20);
          *puVar4 = uVar2 | *puVar4;
          os_bus_space_write_4
                    (*(undefined4 *)(param_1 + 8),DAT_30053e64 + uVar1 * 0x20,
                     *(undefined4 *)(param_1 + uVar1 * 8 + 0xa40));
        }
      }
    }
    if ((*(uint *)(param_1 + 0xa30) & 0x80000) != 0) {
      if ((*(uint *)(param_1 + 0xa38) & 0x10000) != 0) {
        uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30053e68);
        *(uint *)(param_1 + 0xa44) = uVar1 | *(uint *)(param_1 + 0xa44);
        os_bus_space_write_4
                  (*(undefined4 *)(param_1 + 8),DAT_30053e68,*(undefined4 *)(param_1 + 0xa44));
      }
      for (iVar3 = 1; iVar3 < (int)(uint)*(byte *)(param_1 + 0xa2d); iVar3 = iVar3 + 1) {
        if ((*(uint *)(param_1 + 0xa38) & 1 << (iVar3 + 0x10U & 0xff)) != 0) {
          puVar4 = (uint *)(param_1 + iVar3 * 8 + DAT_30053f78);
          uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),DAT_30053e68 + iVar3 * 0x20);
          *puVar4 = uVar1 | *puVar4;
          os_bus_space_write_4
                    (*(undefined4 *)(param_1 + 8),DAT_30053e68 + iVar3 * 0x20,
                     *(undefined4 *)(param_1 + iVar3 * 8 + 0xa44));
        }
      }
    }
    bVar5 = *(int *)(param_1 + 0xa30) != 0;
  }
  return bVar5;
}

/* ----------------------------------------------------------------
 * FUN_3005310c @ 0x3005310C  (примерный размер ~104 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: core_suspend, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30053248
 * Константы: 0x3005310C
 * Данные: DAT_30053344, DAT_30053348, DAT_3005334c, DAT_30053f7c, DAT_30053f80
 * ---------------------------------------------------------------- */
void FUN_3005310c(int param_1)

{
  valid_type(0x2a);
  if ((4 < *(int *)(DAT_30053344 + 0xa0)) && (4 < *(int *)(DAT_30053344 + 0xa8))) {
    os_dprintf(DAT_30053348,DAT_3005334c,DAT_30053f7c);
    os_printf(DAT_30053f80);
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    core_suspend(*(undefined4 *)(param_1 + 4));
    *(undefined4 *)(param_1 + 0x14) = 1;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30053174 @ 0x30053174  (примерный размер ~212 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: core_resume, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30053248
 * Константы: 0x30053174
 * Данные: DAT_30053344, DAT_30053348, DAT_3005334c, DAT_3005407c, DAT_30054080, DAT_30054084
 * ---------------------------------------------------------------- */
void FUN_30053174(int param_1)

{
  valid_type(0x2a);
  if ((4 < *(int *)(DAT_30053344 + 0xa0)) && (4 < *(int *)(DAT_30053344 + 0xa8))) {
    os_dprintf(DAT_30053348,DAT_3005334c,DAT_3005407c);
    os_printf(DAT_30054080);
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    if (*(int *)(param_1 + 0x18) != 0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      valid_type(0x2a);
      if ((2 < *(int *)(DAT_30053344 + 0xa0)) && (2 < *(int *)(DAT_30053344 + 0xa8))) {
        os_dprintf(DAT_30053348,DAT_3005334c,0xf30);
        os_printf(DAT_30054084);
      }
    }
    core_resume(*(undefined4 *)(param_1 + 4));
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30053248 @ 0x30053248  (примерный размер ~1288 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 14
 * Вызывает: FUN_30051038, FUN_30051394, FUN_300520c8, FUN_30052290, FUN_300528d0, FUN_30052a84, FUN_3005310c, FUN_30053174, jos_critical_enter_d, jos_critical_leave_d, os_bus_space_read_4, os_dprintf, os_printf, valid_type
 * Константы: 0x30053248, 0x80000000
 * Данные: DAT_30053344, DAT_30053348, DAT_3005334c, DAT_30054088, DAT_3005408c, DAT_300541a0, DAT_300541a4, DAT_300541a8
 * ---------------------------------------------------------------- */
void FUN_30053248(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  jos_critical_enter_d(DAT_3005334c,DAT_30054088);
  uVar5 = *(uint *)(param_1 + 0xa30);
  uVar4 = *(uint *)(param_1 + 0xa38);
  *(undefined4 *)(param_1 + 0xa38) = 0;
  *(undefined4 *)(param_1 + 0xa30) = 0;
  jos_critical_leave_d(DAT_3005334c,DAT_3005408c);
  valid_type(0x2a);
  if ((4 < *(int *)(DAT_30053344 + 0xa0)) && (4 < *(int *)(DAT_30053344 + 0xa8))) {
    os_dprintf(DAT_30053348,DAT_3005334c,DAT_300541a0);
    os_printf(DAT_300541a4,uVar5,uVar4);
  }
  if (uVar5 != 0) {
    if ((uVar5 & 0x800) != 0) {
      valid_type(0x2a);
      if ((4 < *(int *)(DAT_30053344 + 0xa0)) && (4 < *(int *)(DAT_30053344 + 0xa8))) {
        os_dprintf(DAT_30053348,DAT_3005334c,DAT_300541a8);
        os_printf(DAT_300541ac);
      }
      FUN_3005310c(param_1);
    }
    if ((uVar5 & 0x80000000) != 0) {
      valid_type(0x2a);
      if ((4 < *(int *)(DAT_30053344 + 0xa0)) && (4 < *(int *)(DAT_300541b0 + 0xa8))) {
        os_dprintf(DAT_300541b4,DAT_300541b8,DAT_300541bc);
        os_printf(DAT_300541c0);
      }
      FUN_30053174(param_1);
    }
    if ((uVar5 & 0x1000) != 0) {
      valid_type(0x2a);
      if ((4 < *(int *)(DAT_300541b0 + 0xa0)) && (4 < *(int *)(DAT_300541b0 + 0xa8))) {
        os_dprintf(DAT_300541b4,DAT_300541b8,DAT_300542cc);
        os_printf(DAT_300542d0);
      }
      *(int *)(param_1 + 0xac4) = *(int *)(param_1 + 0xac4) + 1;
      FUN_30053174(param_1);
      FUN_30051038(param_1);
    }
    if ((uVar5 & 0x2000) != 0) {
      valid_type(0x2a);
      if ((4 < *(int *)(DAT_300541b0 + 0xa0)) && (4 < *(int *)(DAT_300541b0 + 0xa8))) {
        os_dprintf(DAT_300541b4,DAT_300541b8,DAT_300542d4);
        os_printf(DAT_300542d8);
      }
      FUN_30051394(param_1);
    }
    if ((uVar5 & 0x40000) != 0) {
      valid_type(0x2a);
      if ((4 < *(int *)(DAT_300541b0 + 0xa0)) && (4 < *(int *)(DAT_300541b0 + 0xa8))) {
        os_dprintf(DAT_300541b4,DAT_300541b8,DAT_300542dc);
        os_printf(DAT_300542e0);
      }
      if (*(int *)(param_1 + 0x14) != 0) {
        FUN_30053174(param_1);
      }
      if ((uVar4 & 1) != 0) {
        jos_critical_enter_d(DAT_300541b8,DAT_300542e4);
        uVar1 = *(undefined4 *)(param_1 + 0xa40);
        *(undefined4 *)(param_1 + 0xa40) = 0;
        jos_critical_leave_d(DAT_300541b8,DAT_300543e8);
        FUN_300520c8(param_1,uVar1);
      }
      for (uVar2 = 1; (int)uVar2 < (int)(uint)*(byte *)(param_1 + 0xa2c); uVar2 = uVar2 + 1) {
        if (((uVar4 & 1 << (uVar2 & 0xff)) != 0) &&
           ((*(short *)(uVar2 * 0xa0 + param_1 + 0x3c) != 0 ||
            (*(short *)(uVar2 * 0xa0 + param_1 + 0x3e) != 0)))) {
          jos_critical_enter_d(DAT_300541b8,0x680);
          uVar1 = *(undefined4 *)(param_1 + uVar2 * 8 + 0xa40);
          *(undefined4 *)(param_1 + uVar2 * 8 + 0xa40) = 0;
          jos_critical_leave_d(DAT_300541b8,DAT_300543ec);
          FUN_30052290(param_1,uVar2,uVar1);
        }
      }
    }
    if ((uVar5 & 0x80000) != 0) {
      valid_type(0x2a);
      if ((3 < *(int *)(DAT_300541b0 + 0xa0)) && (3 < *(int *)(DAT_300541b0 + 0xa8))) {
        os_dprintf(DAT_300541b4,DAT_300541b8,DAT_300543f0);
        os_printf(DAT_300543f4,uVar4);
      }
      if (*(int *)(param_1 + 0x14) != 0) {
        FUN_30053174(param_1);
      }
      if ((uVar4 & 0x10000) != 0) {
        jos_critical_enter_d(DAT_300541b8,DAT_30054508);
        uVar1 = *(undefined4 *)(param_1 + 0xa44);
        *(undefined4 *)(param_1 + 0xa44) = 0;
        jos_critical_leave_d(DAT_300541b8,DAT_3005450c);
        FUN_300528d0(param_1,uVar1);
      }
      for (iVar3 = 1; iVar3 < (int)(uint)*(byte *)(param_1 + 0xa2d); iVar3 = iVar3 + 1) {
        if (((uVar4 & 1 << (iVar3 + 0x10U & 0xff)) != 0) &&
           ((*(short *)(iVar3 * 0xa0 + param_1 + 0x8c) != 0 ||
            (*(short *)(iVar3 * 0xa0 + param_1 + 0x8e) != 0)))) {
          jos_critical_enter_d(DAT_300541b8,0x6b0);
          uVar1 = *(undefined4 *)(param_1 + iVar3 * 8 + 0xa44);
          *(undefined4 *)(param_1 + iVar3 * 8 + 0xa44) = 0;
          jos_critical_leave_d(DAT_300541b8,DAT_30054510);
          FUN_30052a84(param_1,iVar3,uVar1);
        }
      }
    }
    valid_type(0x2a);
    if ((4 < *(int *)(DAT_300541b0 + 0xa0)) && (4 < *(int *)(DAT_300541b0 + 0xa8))) {
      os_dprintf(DAT_300541b4,DAT_300541b8,DAT_300545b0);
      uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x18);
      os_printf(DAT_300545b4,uVar1);
    }
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30053750 @ 0x30053750  (примерный размер ~152 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 7
 * Вызывает: j_device_get_softc, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_notify, os_printf, valid_type
 * Константы: 0x30053750
 * Данные: DAT_300541b0, DAT_300541b4, DAT_300541b8, DAT_300545b8, DAT_300545bc
 * ---------------------------------------------------------------- */
undefined4 FUN_30053750(undefined4 param_1,ushort param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = j_device_get_softc(param_1);
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_300541b0 + 0xa0)) && (3 < *(int *)(DAT_300541b0 + 0xa8))) {
    os_dprintf(DAT_300541b4,DAT_300541b8,DAT_300545b8);
    os_printf(DAT_300545bc,param_2);
  }
  uVar2 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),0x800);
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),0x800,uVar2 | (uint)param_2 << 4);
  uVar3 = j_device_get_softc(param_1);
  os_notify(0xb,uVar3);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300537e8 @ 0x300537E8  (примерный размер ~296 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 9
 * Вызывает: j_device_get_bus, j_device_get_softc, os_bus_space_read_4, os_bus_space_write_4, os_delay_ms, os_dprintf, os_notify, os_printf, valid_type
 * Константы: 0x300537E8, 0xFFFFFFFE
 * Данные: DAT_30053cf8, DAT_300541b0, DAT_300541b4, DAT_300541b8, DAT_30054708, DAT_3005470c, DAT_30054710, DAT_30054714
 * ---------------------------------------------------------------- */
undefined4 FUN_300537e8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = j_device_get_softc(param_1);
  uVar2 = j_device_get_bus(param_1);
  valid_type(0x2a);
  if ((2 < *(int *)(DAT_300541b0 + 0xa0)) && (2 < *(int *)(DAT_300541b0 + 0xa8))) {
    os_dprintf(DAT_300541b4,DAT_300541b8,DAT_30054708);
    os_printf(DAT_3005470c);
  }
  iVar3 = os_notify(10,uVar2);
  if (iVar3 == 0) {
    uVar4 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),DAT_30053cf8);
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),DAT_30053cf8,uVar4 | 1);
    os_delay_ms(10);
    uVar4 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),DAT_30053cf8);
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),DAT_30053cf8,uVar4 & 0xfffffffe);
    uVar2 = 0;
  }
  else {
    valid_type(0x2a);
    if ((1 < *(int *)(DAT_300541b0 + 0xa0)) && (1 < *(int *)(DAT_300541b0 + 0xa8))) {
      os_dprintf(DAT_300541b4,DAT_300541b8,DAT_30054710);
      os_printf(DAT_30054714);
    }
    uVar2 = 3;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * FUN_30053910 @ 0x30053910  (примерный размер ~144 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: j_device_get_softc, os_bus_space_read_4, os_bus_space_write_4, os_delay_ms, os_dprintf, os_notify, os_printf, valid_type
 * Константы: 0x30053910
 * Данные: DAT_30053cf8, DAT_300541b0, DAT_300541b4, DAT_300541b8, DAT_3005480c, DAT_30054810
 * ---------------------------------------------------------------- */
undefined4 FUN_30053910(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = j_device_get_softc(param_1);
  valid_type(0x2a);
  if ((2 < *(int *)(DAT_300541b0 + 0xa0)) && (2 < *(int *)(DAT_300541b0 + 0xa8))) {
    os_dprintf(DAT_300541b4,DAT_300541b8,DAT_3005480c);
    os_printf(DAT_30054810);
  }
  uVar2 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),DAT_30053cf8);
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),DAT_30053cf8,uVar2 | 2);
  os_notify(1,iVar1);
  os_delay_ms(4);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_300539a0 @ 0x300539A0  (примерный размер ~160 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: j_device_get_softc, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_notify, os_printf, valid_type
 * Вызывают: FUN_30055924
 * Константы: 0x300539A0, 0xFFFFFFFD
 * Данные: DAT_30053cf8, DAT_300541b0, DAT_300541b4, DAT_300541b8, DAT_30054814, DAT_30054818
 * ---------------------------------------------------------------- */
undefined4 FUN_300539a0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = j_device_get_softc(param_1);
  valid_type(0x2a);
  if ((2 < *(int *)(DAT_300541b0 + 0xa0)) && (2 < *(int *)(DAT_300541b0 + 0xa8))) {
    os_dprintf(DAT_300541b4,DAT_300541b8,DAT_30054814);
    os_printf(DAT_30054818);
  }
  uVar2 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),DAT_30053cf8);
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),DAT_30053cf8,uVar2 & 0xfffffffd);
  os_notify(0,iVar1);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30053a40 @ 0x30053A40  (примерный размер ~524 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: os_bus_space_read_4, os_dprintf, os_panic, os_printf, valid_type
 * Вызывают: init_endpoints
 * Константы: 0x30053A40, 0x02000000
 * Данные: DAT_300541b0, DAT_300541b4, DAT_300541b8, DAT_30054918, DAT_3005491c, DAT_30054ac8, DAT_30054acc, DAT_30054ad0
 * ---------------------------------------------------------------- */
void FUN_30053a40(int param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x44);
  uVar2 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x48);
  iVar5 = (uVar2 >> 10 & 0xf) + 1;
  uVar2 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x50);
  iVar4 = (uVar2 >> 0x1a & 0xf) + 1;
  valid_type(0x2a);
  if ((2 < *(int *)(DAT_300541b0 + 0xa0)) && (2 < *(int *)(DAT_300541b0 + 0xa8))) {
    os_dprintf(DAT_300541b4,DAT_300541b8,DAT_30054918);
    os_printf(DAT_3005491c,iVar5,iVar4);
  }
  for (bVar3 = 0; (int)((uint)bVar3 + iVar5 * -2) < 0 != SBORROW4((uint)bVar3,iVar5 * 2);
      bVar3 = bVar3 + 2) {
    uVar2 = uVar1 >> bVar3 & 3;
    if (uVar2 == 0) {
      *(undefined4 *)((uint)bVar3 * 0x50 + param_1 + 0x4c) = 1;
      *(char *)(param_1 + 0xa2c) = *(char *)(param_1 + 0xa2c) + '\x01';
      *(undefined4 *)((uint)bVar3 * 0x50 + param_1 + 0x9c) = 1;
      *(char *)(param_1 + 0xa2d) = *(char *)(param_1 + 0xa2d) + '\x01';
    }
    else if (uVar2 == 1) {
      *(undefined4 *)((uint)bVar3 * 0x50 + param_1 + 0x4c) = 1;
      *(char *)(param_1 + 0xa2c) = *(char *)(param_1 + 0xa2c) + '\x01';
      *(undefined4 *)((uint)bVar3 * 0x50 + param_1 + 0x9c) = 0;
    }
    else if (uVar2 == 2) {
      *(undefined4 *)((uint)bVar3 * 0x50 + param_1 + 0x4c) = 0;
      *(undefined4 *)((uint)bVar3 * 0x50 + param_1 + 0x9c) = 1;
      *(char *)(param_1 + 0xa2d) = *(char *)(param_1 + 0xa2d) + '\x01';
    }
    else {
      os_dprintf(DAT_30054ac8,DAT_300541b8,DAT_30054acc);
      os_dprintf(DAT_30054ad0);
      os_panic(DAT_30054ad4,DAT_300541b8,DAT_30054acc);
    }
  }
  uVar1 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),0x50);
  if ((uVar1 & 0x2000000) != 0) {
    *(char *)(param_1 + 0xa2c) = (char)iVar4;
  }
  return;
}

/* ----------------------------------------------------------------
 * uninit_endpoints @ 0x30053C4C  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 2 | Вызывает: 1
 * Вызывает: FUN_30051844
 * Вызывают: FUN_3004ffac, FUN_30055d50
 * Константы: 0x30053C4C
 * ---------------------------------------------------------------- */
void uninit_endpoints(int param_1)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0x20; iVar1 = iVar1 + 1) {
    FUN_30051844(param_1 + iVar1 * 0x50 + 0x2c);
  }
  return;
}

/* ----------------------------------------------------------------
 * init_endpoints @ 0x30053C80  (примерный размер ~1144 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 5
 * Вызывает: FUN_300519d8, FUN_30053a40, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30055e10
 * Константы: 0x30053C80
 * Данные: DAT_300541b0, DAT_300541b4, DAT_300541b8, DAT_30054ad8, DAT_30054adc, DAT_30054f3c
 * ---------------------------------------------------------------- */
int init_endpoints(int param_1)

{
  int iVar1;
  byte bVar2;
  
  FUN_30053a40(param_1);
  valid_type(0x2a);
  if ((2 < *(int *)(DAT_300541b0 + 0xa0)) && (2 < *(int *)(DAT_300541b0 + 0xa8))) {
    os_dprintf(DAT_300541b4,DAT_300541b8,DAT_30054ad8);
    os_printf(DAT_30054adc,*(undefined1 *)(param_1 + 0xa2c),*(undefined1 *)(param_1 + 0xa2d));
  }
  bVar2 = 0;
  while( true ) {
    if (0x1f < bVar2) {
      *(undefined1 *)(param_1 + 0x30) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined2 *)(param_1 + 0x38) = 0x40;
      *(undefined4 *)(param_1 + 0x34) = 1;
      *(undefined4 *)(param_1 + 0x4c) = 1;
      *(undefined1 *)(param_1 + 0x80) = 0;
      *(undefined4 *)(param_1 + 0x98) = 0;
      *(undefined4 *)(param_1 + 0x84) = 1;
      *(undefined2 *)(param_1 + 0x88) = 0x40;
      *(undefined4 *)(param_1 + 0x9c) = 1;
      *(undefined4 *)(param_1 + 0x50) = DAT_30054f3c;
      *(undefined4 *)(param_1 + 0xa0) = DAT_30054f3c;
      return 0;
    }
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x2c) = 1;
    *(undefined1 *)((uint)bVar2 * 0x50 + param_1 + 0x30) = 0;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x3c) = 0;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x3e) = 0;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x38) = 0x400;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x3a) = 0;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x40) = 0;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x44) = 0;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 100) = 0;
    *(uint *)((uint)bVar2 * 0x50 + param_1 + 0x68) = (uint)bVar2 * 0x50 + param_1 + 100;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x6c) = 0;
    *(uint *)((uint)bVar2 * 0x50 + param_1 + 0x70) = (uint)bVar2 * 0x50 + param_1 + 0x6c;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x74) = 0;
    *(uint *)((uint)bVar2 * 0x50 + param_1 + 0x78) = (uint)bVar2 * 0x50 + param_1 + 0x74;
    iVar1 = FUN_300519d8(param_1 + (uint)bVar2 * 0x50 + 0x2c,10);
    if (iVar1 != 0) break;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x7c) = 0;
    *(undefined1 *)((uint)bVar2 * 0x50 + param_1 + 0x80) = 0;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x8c) = 0;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x8e) = 0;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x88) = 0x400;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x8a) = 0;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x90) = 0;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x94) = 0;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0xb4) = 0;
    *(uint *)((uint)bVar2 * 0x50 + param_1 + 0xb8) = (uint)bVar2 * 0x50 + param_1 + 0xb4;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0xbc) = 0;
    *(uint *)((uint)bVar2 * 0x50 + param_1 + 0xc0) = (uint)bVar2 * 0x50 + param_1 + 0xbc;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0xc4) = 0;
    *(uint *)((uint)bVar2 * 0x50 + param_1 + 200) = (uint)bVar2 * 0x50 + param_1 + 0xc4;
    iVar1 = FUN_300519d8(param_1 + (uint)bVar2 * 0x50 + 0x7c,10);
    if (iVar1 != 0) {
      return iVar1;
    }
    bVar2 = bVar2 + 2;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * init_endpoints2 @ 0x300540F8  (примерный размер ~1168 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: FUN_300519d8, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_3004ffac
 * Константы: 0x300540F8
 * Данные: DAT_300541b0, DAT_300541b4, DAT_300541b8, DAT_30054adc, DAT_30054f3c, DAT_30054f40
 * ---------------------------------------------------------------- */
int init_endpoints2(int param_1)

{
  int iVar1;
  byte bVar2;
  
  valid_type(0x2a);
  if ((2 < *(int *)(DAT_300541b0 + 0xa0)) && (2 < *(int *)(DAT_300541b0 + 0xa8))) {
    os_dprintf(DAT_300541b4,DAT_300541b8,DAT_30054f40);
    os_printf(DAT_30054adc,*(undefined1 *)(param_1 + 0xa2c),*(undefined1 *)(param_1 + 0xa2d));
  }
  bVar2 = 0;
  while( true ) {
    if (0x1f < bVar2) {
      *(undefined1 *)(param_1 + 0x30) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined2 *)(param_1 + 0x38) = 0x40;
      *(undefined4 *)(param_1 + 0x34) = 1;
      *(undefined4 *)(param_1 + 0x4c) = 1;
      *(undefined1 *)(param_1 + 0x80) = 0;
      *(undefined4 *)(param_1 + 0x98) = 0;
      *(undefined4 *)(param_1 + 0x84) = 1;
      *(undefined2 *)(param_1 + 0x88) = 0x40;
      *(undefined4 *)(param_1 + 0x9c) = 1;
      *(undefined4 *)(param_1 + 0x50) = DAT_30054f3c;
      *(undefined4 *)(param_1 + 0xa0) = DAT_30054f3c;
      return 0;
    }
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x2c) = 1;
    *(undefined1 *)((uint)bVar2 * 0x50 + param_1 + 0x30) = 0;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x3c) = 0;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x3e) = 0;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x38) = 0x400;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x3a) = 0;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x40) = 0;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x44) = 0;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 100) = 0;
    *(uint *)((uint)bVar2 * 0x50 + param_1 + 0x68) = (uint)bVar2 * 0x50 + param_1 + 100;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x6c) = 0;
    *(uint *)((uint)bVar2 * 0x50 + param_1 + 0x70) = (uint)bVar2 * 0x50 + param_1 + 0x6c;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x74) = 0;
    *(uint *)((uint)bVar2 * 0x50 + param_1 + 0x78) = (uint)bVar2 * 0x50 + param_1 + 0x74;
    iVar1 = FUN_300519d8(param_1 + (uint)bVar2 * 0x50 + 0x2c,10);
    if (iVar1 != 0) break;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x7c) = 0;
    *(undefined1 *)((uint)bVar2 * 0x50 + param_1 + 0x80) = 0;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x8c) = 0;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x8e) = 0;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x88) = 0x400;
    *(undefined2 *)((uint)bVar2 * 0x50 + param_1 + 0x8a) = 0;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x90) = 0;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0x94) = 0;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0xb4) = 0;
    *(uint *)((uint)bVar2 * 0x50 + param_1 + 0xb8) = (uint)bVar2 * 0x50 + param_1 + 0xb4;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0xbc) = 0;
    *(uint *)((uint)bVar2 * 0x50 + param_1 + 0xc0) = (uint)bVar2 * 0x50 + param_1 + 0xbc;
    *(undefined4 *)((uint)bVar2 * 0x50 + param_1 + 0xc4) = 0;
    *(uint *)((uint)bVar2 * 0x50 + param_1 + 200) = (uint)bVar2 * 0x50 + param_1 + 0xc4;
    iVar1 = FUN_300519d8(param_1 + (uint)bVar2 * 0x50 + 0x7c,10);
    if (iVar1 != 0) {
      return iVar1;
    }
    bVar2 = bVar2 + 2;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * FUN_30054588 @ 0x30054588  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: __udiv32
 * Вызывают: FUN_300545e8
 * Константы: 0x30054588
 * Данные: DAT_300554e4, DAT_300554e8, DAT_300554ec
 * ---------------------------------------------------------------- */
short FUN_30054588(int *param_1)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = DAT_300554ec;
  if (((char)param_1[1] == '\x01') && (uVar2 = DAT_300554e8, *param_1 != 0)) {
    uVar2 = DAT_300554e4;
  }
  sVar1 = __udiv32(uVar2 & 0xffff,(short)param_1[3]);
  return (short)param_1[3] * sVar1;
}

/* ----------------------------------------------------------------
 * FUN_300545e8 @ 0x300545E8  (примерный размер ~644 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 9
 * Вызывает: FUN_30054588, j_device_get_softc, jos_critical_enter_d, jos_critical_leave_d, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_printf, valid_type
 * Константы: 0x300545E8
 * Данные: DAT_300554f0, DAT_300554f4, DAT_300554f8, DAT_300554fc, DAT_30055500, DAT_300555a4, DAT_300555a8, DAT_300556a4
 * ---------------------------------------------------------------- */
undefined4 FUN_300545e8(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = j_device_get_softc(param_1);
  uVar5 = *(uint *)(param_2 + 0x20);
  iVar3 = iVar1 + uVar5 * 0x50;
  piVar4 = (int *)(iVar3 + 0x2c);
  uVar6 = uVar5 >> 1;
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_300554f0 + 0xa0)) && (3 < *(int *)(DAT_300554f0 + 0xa8))) {
    os_dprintf(DAT_300554f4,DAT_300554f8,DAT_300554fc);
    os_printf(DAT_30055500,*(undefined1 *)(param_2 + 0xb),uVar5);
  }
  *(char *)(iVar3 + 0x30) = (char)*(undefined4 *)(param_2 + 4);
  *(int *)(iVar3 + 0x48) = param_2;
  *(undefined2 *)(iVar3 + 0x38) = *(undefined2 *)(param_2 + 0x24);
  *(undefined4 *)(*(int *)(iVar3 + 0x48) + 0x28) = 1;
  *(undefined4 *)(iVar3 + 0x34) = 1;
  uVar5 = FUN_30054588(piVar4);
  *(uint *)(iVar3 + 0x50) = uVar5 & 0xffff;
  uVar5 = (uint)*(ushort *)(param_2 + 0x24) | (uint)*(byte *)(iVar3 + 0x30) << 0x12;
  if (*piVar4 == 0) {
    os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),uVar6 * 0x20 + 0xb00,uVar5 | DAT_300555a4);
    valid_type(0x2a);
    if ((3 < *(int *)(DAT_300554f0 + 0xa0)) && (3 < *(int *)(DAT_300554f0 + 0xa8))) {
      os_dprintf(DAT_300554f4,DAT_300554f8,DAT_300556a8);
      uVar2 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),uVar6 * 0x20 + 0xb00);
      os_printf(DAT_300556ac,uVar6,uVar2,uVar6 * 0x20 + 0xb00);
    }
  }
  else {
    os_bus_space_write_4
              (*(undefined4 *)(iVar1 + 8),uVar6 * 0x20 + 0x900,uVar5 | uVar6 << 0x16 | DAT_300555a4)
    ;
    valid_type(0x2a);
    if ((3 < *(int *)(DAT_300554f0 + 0xa0)) && (3 < *(int *)(DAT_300554f0 + 0xa8))) {
      os_dprintf(DAT_300554f4,DAT_300554f8,DAT_300555a8);
      uVar2 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),uVar6 * 0x20 + 0x900);
      os_printf(DAT_300556a4,uVar6,uVar2,uVar6 * 0x20 + 0x900);
    }
  }
  if (*piVar4 == 0) {
    uVar6 = uVar6 + 0x10;
  }
  jos_critical_enter_d(DAT_300554f8,DAT_300556b0);
  uVar5 = os_bus_space_read_4(*(undefined4 *)(iVar1 + 8),DAT_300556b4);
  os_bus_space_write_4(*(undefined4 *)(iVar1 + 8),DAT_300556b4,uVar5 | 1 << (uVar6 & 0xff));
  jos_critical_leave_d(DAT_300554f8,DAT_300556b8);
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3005486c @ 0x3005486C  (примерный размер ~556 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 8
 * Вызывает: j_device_get_softc, jos_critical_enter_d, jos_critical_leave_d, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_printf, valid_type
 * Константы: 0x3005486C
 * Данные: DAT_300554f0, DAT_300554f4, DAT_300554f8, DAT_300556b4, DAT_30055808, DAT_3005580c, DAT_30055810, DAT_30055814
 * ---------------------------------------------------------------- */
undefined4 FUN_3005486c(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar2 = j_device_get_softc(param_1);
  uVar6 = *(uint *)(param_2 + 0x20);
  iVar5 = iVar2 + uVar6 * 0x50;
  valid_type(0x2a);
  if ((2 < *(int *)(DAT_300554f0 + 0xa0)) && (2 < *(int *)(DAT_300554f0 + 0xa8))) {
    os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055808);
    os_printf(DAT_3005580c,*(undefined4 *)(param_2 + 0x20));
  }
  if (*(int *)(iVar5 + 0x34) == 0) {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_300554f0 + 0xa0)) && (0 < *(int *)(DAT_300554f0 + 0xa8))) {
      os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055810);
      os_printf(DAT_30055814,*(undefined1 *)(param_2 + 0xb));
    }
    uVar3 = 8;
  }
  else if ((*(int *)(param_2 + 0x28) == 1) || (*(int *)(param_2 + 0x28) == 3)) {
    uVar6 = uVar6 >> 1;
    uVar1 = uVar6;
    if (*(int *)(iVar5 + 0x2c) == 0) {
      uVar1 = uVar6 + 0x10;
    }
    jos_critical_enter_d(DAT_300554f8,DAT_30055820);
    uVar4 = os_bus_space_read_4(*(undefined4 *)(iVar2 + 8),DAT_300556b4);
    os_bus_space_write_4(*(undefined4 *)(iVar2 + 8),DAT_300556b4,uVar4 & ~(1 << (uVar1 & 0xff)));
    jos_critical_leave_d(DAT_300554f8,DAT_300558f4);
    if (*(int *)(iVar5 + 0x2c) == 0) {
      os_bus_space_write_4(*(undefined4 *)(iVar2 + 8),uVar6 * 0x20 + 0xb00,0);
    }
    else {
      os_bus_space_write_4(*(undefined4 *)(iVar2 + 8),uVar6 * 0x20 + 0x900,0);
    }
    *(undefined4 *)(param_2 + 0x28) = 2;
    *(undefined4 *)(iVar5 + 0x34) = 0;
    valid_type(0x2a);
    if ((2 < *(int *)(DAT_300554f0 + 0xa0)) && (2 < *(int *)(DAT_300554f0 + 0xa8))) {
      os_dprintf(DAT_300554f4,DAT_300554f8,DAT_300558f8);
      os_printf(DAT_300558fc,*(undefined4 *)(param_2 + 0x20));
    }
    uVar3 = 0;
  }
  else {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_300554f0 + 0xa0)) && (0 < *(int *)(DAT_300554f0 + 0xa8))) {
      os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055818);
      os_printf(DAT_3005581c);
    }
    uVar3 = 0x10;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * FUN_30054a98 @ 0x30054A98  (примерный размер ~320 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: FUN_30050e60, core_request_complete, os_bus_space_read_4, os_bus_space_write_4, os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30054bd8
 * Константы: 0x80000000, 0x48000000, 0x30054A98
 * Данные: DAT_300554f0, DAT_300554f4, DAT_300554f8, DAT_30055a38, DAT_30055a3c
 * ---------------------------------------------------------------- */
void FUN_30054a98(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1 + param_2 * 0x50;
  iVar3 = *(int *)(iVar4 + 0x40);
  uVar1 = param_2 >> 1;
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_300554f0 + 0xa0)) && (3 < *(int *)(DAT_300554f0 + 0xa8))) {
    os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055a38);
    os_printf(DAT_30055a3c,0,param_2);
  }
  if (*(int *)(iVar4 + 0x2c) == 0) {
    uVar2 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0xb00);
    if ((uVar2 & 0x80000000) != 0) {
      os_bus_space_write_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0xb00,uVar2 | 0x48000000);
    }
  }
  else {
    uVar2 = os_bus_space_read_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0x900);
    if ((uVar2 & 0x80000000) != 0) {
      os_bus_space_write_4(*(undefined4 *)(param_1 + 8),uVar1 * 0x20 + 0x900,uVar2 | 0x48000000);
    }
    FUN_30050e60(param_1,uVar1);
  }
  if ((iVar3 != 0) && (*(char *)(iVar4 + 0x30) != '\x01')) {
    *(undefined4 *)(iVar3 + 0x18) = 2;
    *(undefined4 *)(iVar4 + 0x40) = 0;
    core_request_complete(*(undefined4 *)(param_1 + 4),iVar3);
  }
  return;
}

/* ----------------------------------------------------------------
 * FUN_30054bd8 @ 0x30054BD8  (примерный размер ~200 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 5
 * Вызывает: FUN_30054a98, j_device_get_softc, os_dprintf, os_printf, valid_type
 * Константы: 0x30054BD8
 * Данные: DAT_300554f0, DAT_300554f4, DAT_300554f8, DAT_30055b58, DAT_30055b5c
 * ---------------------------------------------------------------- */
undefined4 FUN_30054bd8(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  
  iVar1 = j_device_get_softc(param_1);
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_300554f0 + 0xa0)) && (3 < *(int *)(DAT_300554f0 + 0xa8))) {
    os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055b58);
    if (param_2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined1 *)(param_2 + 0xb);
    }
    os_printf(DAT_30055b5c,uVar3);
  }
  if (param_2 == 0) {
    iVar2 = 0;
    if (*(int *)(iVar1 + 0x40) == 0) {
      iVar2 = 1;
    }
  }
  else {
    iVar2 = *(int *)(param_2 + 0x20);
  }
  if (*(int *)(iVar1 + iVar2 * 0x50 + 0x40) != 0) {
    FUN_30054a98(iVar1,iVar2);
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30054ca0 @ 0x30054CA0  (примерный размер ~88 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 2
 * Вызывает: j_device_get_softc, os_panic
 * Константы: 0x30054CA0
 * Данные: DAT_30055b60
 * ---------------------------------------------------------------- */
undefined4 FUN_30054ca0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = j_device_get_softc(param_1);
  iVar1 = iVar1 + *(int *)(param_2 + 0x20) * 0x50;
  if (*(int *)(iVar1 + 0x34) != 0) {
    os_panic(DAT_30055b60);
  }
  *(undefined2 *)(iVar1 + 0x3c) = 0;
  *(undefined2 *)(iVar1 + 0x3e) = 0;
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_30054cf8 @ 0x30054CF8  (примерный размер ~1100 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 4
 * Вызывает: j_device_get_softc, os_dprintf, os_printf, valid_type
 * Константы: 0x30054CF8
 * Данные: DAT_300554f0, DAT_300554f4, DAT_300554f8, DAT_30055ca0, DAT_30055ca4, DAT_30055ca8, DAT_30055cac, DAT_30055d68
 * ---------------------------------------------------------------- */
undefined4 FUN_30054cf8(undefined4 param_1,short *param_2,char param_3,char param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  byte bVar10;
  int iVar11;
  bool bVar12;
  uint local_30;
  
  iVar2 = j_device_get_softc(param_1);
  bVar12 = (char)param_2[4] != '\0';
  iVar7 = 0;
  bVar10 = param_3 + 1;
  bVar9 = param_4 + 1;
  valid_type(0x2a);
  if ((3 < *(int *)(DAT_300554f0 + 0xa0)) && (3 < *(int *)(DAT_300554f0 + 0xa8))) {
    os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055ca0);
    os_printf(DAT_30055ca4,0,param_2,bVar10,bVar9);
  }
  iVar4 = bVar12 + 2;
  if (bVar12) {
    bVar1 = *(byte *)(iVar2 + 0xa2d);
  }
  else {
    bVar1 = *(byte *)(iVar2 + 0xa2c);
  }
  local_30 = (uint)bVar1;
  iVar11 = iVar4 + local_30 * 2 + -2;
  for (; iVar4 < iVar11; iVar4 = iVar4 + 2) {
    iVar8 = iVar2 + iVar4 * 0x50;
    iVar7 = iVar8 + 0x2c;
    if (*(int *)(iVar8 + 0x4c) != 0) {
      valid_type(0x2a);
      if ((3 < *(int *)(DAT_300554f0 + 0xa0)) && (3 < *(int *)(DAT_300554f0 + 0xa8))) {
        os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055ca8);
        os_printf(DAT_30055cac,iVar4,*(undefined2 *)(iVar8 + 0x3c),*(undefined2 *)(iVar8 + 0x3e));
      }
      if ((*(short *)(iVar8 + 0x3c) == 0) ||
         ((*(ushort *)(iVar8 + 0x3c) == (ushort)bVar10 &&
          (*(ushort *)(iVar8 + 0x3e) != (ushort)bVar9)))) {
        if ((ushort)param_2[1] <= *(ushort *)(iVar8 + 0x38)) break;
        valid_type(0x2a);
        if ((2 < *(int *)(DAT_300554f0 + 0xa0)) && (2 < *(int *)(DAT_300554f0 + 0xa8))) {
          os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055d68);
          os_printf(DAT_30055d6c,0,param_2[1],*(undefined2 *)(iVar8 + 0x38));
        }
      }
    }
  }
  if (iVar4 == iVar11) {
    valid_type(0x2a);
    if ((0 < *(int *)(DAT_300554f0 + 0xa0)) && (0 < *(int *)(DAT_300554f0 + 0xa8))) {
      os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055d70);
      os_printf(DAT_30055d74,0);
    }
    uVar3 = 10;
  }
  else {
    *(ushort *)(iVar7 + 0x10) = (ushort)bVar10;
    *(ushort *)(iVar7 + 0x12) = (ushort)bVar9;
    uVar6 = (*(byte *)(param_2 + 6) + 1) * *param_2;
    if (param_2[0x18] == 0) {
      valid_type(0x2a);
      if ((2 < *(int *)(DAT_300554f0 + 0xa0)) && (2 < *(int *)(DAT_300554f0 + 0xa8))) {
        os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055ed4);
        os_printf(DAT_30055ed8,0,uVar6);
      }
    }
    else if ((ushort)param_2[0x18] < uVar6) {
      valid_type(0x2a);
      if ((0 < *(int *)(DAT_300554f0 + 0xa0)) && (0 < *(int *)(DAT_300554f0 + 0xa8))) {
        os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055ecc);
        os_printf(DAT_30055ed0,0,param_2[0x18],uVar6);
      }
    }
    else {
      valid_type(0x2a);
      if ((2 < *(int *)(DAT_300554f0 + 0xa0)) && (2 < *(int *)(DAT_300554f0 + 0xa8))) {
        os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055ec4);
        os_printf(DAT_30055ec8,0,param_2[0x18]);
      }
      uVar6 = param_2[0x18];
    }
    if ((uint)*(ushort *)(iVar7 + 0xe) <= (uint)((int)(uint)uVar6 >> 2)) {
      *(ushort *)(iVar7 + 0xe) = uVar6 >> 2;
    }
    if (0x100 < *(ushort *)(iVar7 + 0xe)) {
      *(undefined2 *)(iVar7 + 0xe) = 0x100;
    }
    uVar5 = iVar4 - (iVar4 >> 0x1f);
    *(char *)((int)param_2 + 0xb) = (char)(iVar4 / 2);
    *(byte *)((int)param_2 + 0xb) = ((uVar5 & 1) == 0) << 7 | *(byte *)((int)param_2 + 0xb);
    *(uint *)(param_2 + 0x10) = uVar5;
    valid_type(0x2a);
    if ((2 < *(int *)(DAT_300554f0 + 0xa0)) && (2 < *(int *)(DAT_300554f0 + 0xa8))) {
      os_dprintf(DAT_300554f4,DAT_300554f8,DAT_30055fbc);
      os_printf(DAT_30055fc0,uVar5,param_2,*(undefined1 *)((int)param_2 + 0xb),
                *(undefined2 *)(iVar7 + 0xe));
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* ----------------------------------------------------------------
 * syn_hsfc_init @ 0x30056244  (примерный размер ~52 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: jdriver_register
 * Константы: 0x30056244
 * Данные: DAT_300563a0, DAT_300563a4, DAT_300563a8, DAT_300563ac
 * ---------------------------------------------------------------- */
undefined4 syn_hsfc_init(void)

{
  undefined4 uVar1;
  
  uVar1 = jdriver_register(1,DAT_300563a4,DAT_300563a8,DAT_300563ac,DAT_300563a0);
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_30056278 @ 0x30056278  (примерный размер ~312 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_MallocDbg, memset
 * Вызывают: FUN_300519d8
 * Константы: 0x30056278
 * ---------------------------------------------------------------- */
void * FUN_30056278(size_t param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)BSP_MallocDbg(param_1,0,param_3,param_4);
  if ((param_2 == 1) && (__s != (void *)0x0)) {
    memset(__s,0,param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * uw_app_uninit @ 0x30059A08  (примерный размер ~204 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: jstart_stack, jstop_stack, uw_app_init
 * Константы: 0x30059A08
 * Данные: DAT_30059b90, DAT_30059b94, DAT_30059b98, DAT_30059b9c, DAT_30059ba0, DAT_30059ba4, DAT_30059ba8
 * ---------------------------------------------------------------- */
void uw_app_uninit(void)

{
  int iVar1;
  
  valid_type(0x22);
  if ((2 < *(int *)(DAT_30059b90 + 0x78)) && (2 < *(int *)(DAT_30059b90 + 0x88))) {
    os_dprintf(DAT_30059b94,DAT_30059b98,9);
    os_printf(DAT_30059b9c);
  }
  for (iVar1 = 0; *(int *)(DAT_30059ba0 + iVar1 * 0xc) != 0; iVar1 = iVar1 + 1) {
  }
  while (iVar1 != 0) {
    iVar1 = iVar1 + -1;
    if (*(int *)(DAT_30059ba4 + iVar1 * 0xc) != 0) {
      (**(code **)(DAT_30059ba8 + iVar1 * 0xc))();
    }
    *(undefined4 *)(iVar1 * 0xc + DAT_30059ba4) = 0;
  }
  return;
}

/* ----------------------------------------------------------------
 * uw_app_init @ 0x30059AD4  (примерный размер ~220 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 4
 * Вызывает: os_dprintf, os_printf, uw_app_uninit, valid_type
 * Вызывают: jstart_stack
 * Константы: 0x30059AD4
 * Данные: DAT_30059b90, DAT_30059b94, DAT_30059b98, DAT_30059ba0, DAT_30059ba4, DAT_30059bac
 * ---------------------------------------------------------------- */
int uw_app_init(void)

{
  int iVar1;
  int iVar2;
  
  valid_type(0x22);
  if ((2 < *(int *)(DAT_30059b90 + 0x78)) && (2 < *(int *)(DAT_30059b90 + 0x88))) {
    os_dprintf(DAT_30059b94,DAT_30059b98,0x1e);
    os_printf(DAT_30059bac);
  }
  iVar2 = 0;
  while( true ) {
    if (*(int *)(DAT_30059ba0 + iVar2 * 0xc) == 0) {
      return 0;
    }
    iVar1 = (**(code **)(DAT_30059ba0 + iVar2 * 0xc))();
    if (iVar1 != 0) break;
    *(undefined4 *)(iVar2 * 0xc + DAT_30059ba4) = 1;
    iVar2 = iVar2 + 1;
  }
  uw_app_uninit();
  return iVar1;
}

/* ----------------------------------------------------------------
 * get_uw_args @ 0x3005B2BC  (примерный размер ~96 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: BSP_USB_BuildDevArgs, BSP_USB_GetUwArgs, os_printf
 * Вызывают: jusb_entry
 * Константы: 0x3005B2BC
 * Данные: DAT_3005b314, DAT_3005b318
 * ---------------------------------------------------------------- */
undefined4 get_uw_args(void)

{
  int iVar1;
  undefined4 uVar2;
  
  BSP_USB_GetUwArgs();
  iVar1 = BSP_USB_BuildDevArgs();
  uVar2 = DAT_3005b314;
  if (iVar1 != 0) {
    os_printf(DAT_3005b318,0);
    uVar2 = 0;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * os_generic_isr @ 0x3005B31C  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3005B31C
 * Данные: DAT_3005bf08
 * ---------------------------------------------------------------- */
void os_generic_isr(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = *DAT_3005bf08;
  *DAT_3005bf08 = 4;
  for (puVar3 = *(undefined4 **)(param_1 + 0xc); puVar3 != (undefined4 *)0x0;
      puVar3 = (undefined4 *)puVar3[4]) {
    iVar2 = (*(code *)*puVar3)(puVar3[1]);
    if ((iVar2 == 1) && (puVar3[2] != 0)) {
      (*(code *)puVar3[2])(puVar3[3]);
    }
  }
  *DAT_3005bf08 = uVar1;
  return;
}

/* ----------------------------------------------------------------
 * dummy_isr @ 0x3005B398  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3005B398
 * ---------------------------------------------------------------- */
void dummy_isr(void)

{
  return;
}

/* ----------------------------------------------------------------
 * os_interrupt_setup @ 0x3005B39C  (примерный размер ~720 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 10
 * Вызывает: BSP_FreeDbg, FUN_3005beb4, intConnect, intDisable, intEnable, jos_critical_enter_d, jos_critical_leave_d, os_dprintf, os_printf, valid_type
 * Вызывают: jos_interrupt_setup
 * Константы: 0x3005B39C
 * Данные: DAT_3005bf0c, DAT_3005bf10, DAT_3005bf14, DAT_3005bf18, DAT_3005bf1c, DAT_3005bf20, DAT_3005bf24
 * ---------------------------------------------------------------- */
undefined4
os_interrupt_setup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  
  uVar5 = 0;
  puVar2 = (undefined4 *)FUN_3005beb4(0x18,1,DAT_3005bf0c,0x7a);
  if (puVar2 == (undefined4 *)0x0) {
    return 7;
  }
  *puVar2 = param_2;
  puVar2[1] = param_3;
  puVar2[2] = param_4;
  puVar2[3] = param_5;
  for (piVar4 = (int *)*DAT_3005bf10; (piVar4 != (int *)0x0 && (*piVar4 != *(int *)(param_1 + 0xc)))
      ; piVar4 = (int *)piVar4[1]) {
  }
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)FUN_3005beb4(0x14,1,DAT_3005bf0c,0x8e);
    if (piVar4 == (int *)0x0) {
      uVar5 = 7;
    }
    else {
      *piVar4 = *(int *)(param_1 + 0xc);
      piVar4[3] = 0;
      piVar4[4] = (int)(piVar4 + 3);
      piVar4[1] = 0;
      piVar4[2] = DAT_3005bf10[1];
      *(int **)DAT_3005bf10[1] = piVar4;
      DAT_3005bf10[1] = piVar4 + 1;
      intDisable(*(undefined4 *)(param_1 + 8));
      iVar3 = intConnect(*piVar4,DAT_3005bf14,piVar4);
      if (iVar3 == 0) {
        iVar3 = intEnable(*(undefined4 *)(param_1 + 8));
        if (iVar3 == 0) goto LAB_3005b55c;
        valid_type(3);
        if ((0 < *DAT_3005bf18) && (0 < DAT_3005bf18[3])) {
          os_dprintf(DAT_3005bf1c,DAT_3005bf0c,0xaa);
          os_printf(DAT_3005bf24);
        }
      }
      else {
        valid_type(3);
        if ((0 < *DAT_3005bf18) && (0 < DAT_3005bf18[3])) {
          os_dprintf(DAT_3005bf1c,DAT_3005bf0c,0xa4);
          os_printf(DAT_3005bf20);
        }
      }
    }
    if (piVar4 != (int *)0x0) {
      jos_critical_enter_d(DAT_3005bf0c,0xbc);
      bVar1 = false;
      piVar6 = (int *)*DAT_3005bf10;
      while (piVar7 = piVar6, piVar7 != (int *)0x0) {
        piVar6 = (int *)piVar7[1];
        if (piVar7 == piVar4) {
          if (piVar7[1] == 0) {
            DAT_3005bf10[1] = piVar7[2];
          }
          else {
            *(int *)(piVar7[1] + 8) = piVar7[2];
          }
          *(int *)piVar7[2] = piVar7[1];
          bVar1 = true;
        }
      }
      jos_critical_leave_d(DAT_3005bf0c,0xbf);
      if (bVar1) {
        BSP_FreeDbg(piVar4,DAT_3005bf0c,0xc1);
      }
      uVar5 = 10;
    }
    BSP_FreeDbg(puVar2,DAT_3005bf0c,0xc4);
  }
  else {
LAB_3005b55c:
    *(undefined4 **)(param_1 + 0x10) = puVar2;
    jos_critical_enter_d(DAT_3005bf0c,0xb2);
    puVar2[4] = 0;
    puVar2[5] = piVar4[4];
    *(undefined4 **)piVar4[4] = puVar2;
    piVar4[4] = (int)(puVar2 + 4);
    jos_critical_leave_d(DAT_3005bf0c,0xb4);
    uVar5 = 0;
  }
  return uVar5;
}

/* ----------------------------------------------------------------
 * os_interrupt_teardown @ 0x3005B66C  (примерный размер ~648 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: BSP_FreeDbg, intConnect, intDisable, jos_critical_enter_d, jos_critical_leave_d, os_dprintf, os_printf, valid_type
 * Вызывают: jos_interrupt_teardown
 * Константы: 0x3005B66C
 * Данные: DAT_3005bf0c, DAT_3005bf10, DAT_3005bf18, DAT_3005bf1c, DAT_3005bf28, DAT_3005bf2c, DAT_3005bf30, DAT_3005bf34
 * ---------------------------------------------------------------- */
undefined4 os_interrupt_teardown(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  
  if (param_1 == 0) {
    valid_type(3);
    if ((0 < *DAT_3005bf18) && (0 < DAT_3005bf18[3])) {
      os_dprintf(DAT_3005bf1c,DAT_3005bf0c,0xd4);
      os_printf(DAT_3005bf28);
    }
    return 10;
  }
  iVar7 = *(int *)(param_1 + 0x10);
  for (piVar6 = (int *)*DAT_3005bf10; (piVar6 != (int *)0x0 && (*piVar6 != *(int *)(param_1 + 0xc)))
      ; piVar6 = (int *)piVar6[1]) {
  }
  if (piVar6 == (int *)0x0) {
    valid_type(3);
    if ((0 < *DAT_3005bf18) && (0 < DAT_3005bf18[3])) {
      os_dprintf(DAT_3005bf1c,DAT_3005bf0c,0xe4);
      os_printf(DAT_3005bf2c);
    }
    return 10;
  }
  jos_critical_enter_d(DAT_3005bf0c,0xe9);
  bVar1 = false;
  iVar4 = piVar6[3];
  while (iVar5 = iVar4, iVar5 != 0) {
    iVar4 = *(int *)(iVar5 + 0x10);
    if (iVar5 == iVar7) {
      if (*(int *)(iVar5 + 0x10) == 0) {
        piVar6[4] = *(int *)(iVar5 + 0x14);
      }
      else {
        *(undefined4 *)(*(int *)(iVar5 + 0x10) + 0x14) = *(undefined4 *)(iVar5 + 0x14);
      }
      **(undefined4 **)(iVar5 + 0x14) = *(undefined4 *)(iVar5 + 0x10);
      bVar1 = true;
    }
  }
  jos_critical_leave_d(DAT_3005bf0c,0xec);
  if (bVar1) {
    BSP_FreeDbg(iVar7,DAT_3005bf0c,0xf1);
    if (piVar6[3] == 0) {
      intDisable(*(undefined4 *)(param_1 + 8));
      intConnect(*(undefined4 *)(param_1 + 0xc),DAT_3005bf30,0);
      jos_critical_enter_d(DAT_3005bf0c,DAT_3005bf34);
      bVar1 = false;
      piVar8 = (int *)*DAT_3005bf10;
      while (piVar3 = piVar8, piVar3 != (int *)0x0) {
        piVar8 = (int *)piVar3[1];
        if (piVar3 == piVar6) {
          if (piVar3[1] == 0) {
            DAT_3005bf10[1] = piVar3[2];
          }
          else {
            *(int *)(piVar3[1] + 8) = piVar3[2];
          }
          *(int *)piVar3[2] = piVar3[1];
          bVar1 = true;
        }
      }
      jos_critical_leave_d(DAT_3005bf0c,DAT_3005bf38);
      if (!bVar1) goto LAB_3005b8a4;
      BSP_FreeDbg(piVar6,DAT_3005bf0c,DAT_3005bf3c);
    }
    uVar2 = 0;
  }
  else {
LAB_3005b8a4:
    valid_type(3);
    if ((0 < *DAT_3005bf18) && (0 < DAT_3005bf18[3])) {
      os_dprintf(DAT_3005bf1c,DAT_3005bf0c,0x110);
      os_printf(DAT_3005bf40);
    }
    uVar2 = 10;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * os_nv_read @ 0x3005B8F4  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: NVM_Read
 * Вызывают: BSP_USB_GetDevProfileInfo
 * Константы: 0x3005B8F4
 * ---------------------------------------------------------------- */
void os_nv_read(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  NVM_Read(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * os_dashboard_get @ 0x3005B918  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3005B918
 * Данные: DAT_300769c4, DAT_300769c8
 * ---------------------------------------------------------------- */
bool os_dashboard_get(void)

{
  return *(int *)(DAT_300769c4 + 0x18) != DAT_300769c8;
}

/* ----------------------------------------------------------------
 * os_notify @ 0x3005B9B4  (примерный размер ~316 байт)
 * Модуль: data | Вызывают: 10 | Вызывает: 4
 * Вызывает: os_dprintf, os_printf, usb_enum_notify_usr, valid_type
 * Вызывают: FUN_3004ffac, FUN_30053750, FUN_300537e8, FUN_30053910, FUN_300539a0, chp9_handle_set_configuration, core_disconnect, core_reconfig, core_resume, core_suspend
 * Константы: 0x3005B9B4
 * Данные: DAT_3005bf0c, DAT_3005bf18, DAT_3005bf1c, DAT_3005bf5c, DAT_3005bf60, DAT_3005bf64, DAT_3005bf68, DAT_3005bf6c
 * ---------------------------------------------------------------- */
undefined4 os_notify(int param_1)

{
  if (param_1 == 0xd) {
    valid_type(3);
    if ((2 < *DAT_3005bf18) && (2 < DAT_3005bf18[3])) {
      os_dprintf(DAT_3005bf1c,DAT_3005bf0c,DAT_3005bf5c);
      os_printf(DAT_3005bf60,0);
    }
    *DAT_3005bf64 = 0;
  }
  if (param_1 == 0xc) {
    valid_type(3);
    if ((2 < *DAT_3005bf18) && (2 < DAT_3005bf18[3])) {
      os_dprintf(DAT_3005bf1c,DAT_3005bf0c,DAT_3005bf68);
      os_printf(DAT_3005bf6c,0);
    }
    *DAT_3005bf64 = 0;
    if ((*(int *)(*DAT_3005bf70 + 0x10) != 10) && (*(int *)(*DAT_3005bf70 + 0x10) != 0xb)) {
      valid_type(3);
      if ((2 < *DAT_3005bf18) && (2 < DAT_3005bf18[3])) {
        os_dprintf(DAT_3005bf1c,DAT_3005bf0c,0x1c8);
        os_printf(DAT_3005bf74,0);
      }
      *DAT_3005bf78 = 1;
      usb_enum_notify_usr();
    }
  }
  return 0;
}

/* ----------------------------------------------------------------
 * FUN_3005baf0 @ 0x3005BAF0  (примерный размер ~120 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: os_hw_init
 * Константы: 0x3005BAF0
 * ---------------------------------------------------------------- */
int FUN_3005baf0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if ((int)(uint)*(byte *)(param_1 + 4) <= iVar1) {
      return 0;
    }
    if ((*(int *)(*(int *)(param_1 + 8) + iVar1 * 0x1c) == param_2) &&
       (*(int *)(iVar1 * 0x1c + *(int *)(param_1 + 8) + 0x18) == 0)) break;
    iVar1 = iVar1 + 1;
  }
  return iVar1 * 0x1c + *(int *)(param_1 + 8);
}

/* ----------------------------------------------------------------
 * os_hw_uninit @ 0x3005BB68  (примерный размер ~92 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: del_generic_controller, uw_hw_uninit
 * Вызывают: jstart_stack, jstop_stack, os_hw_init
 * Константы: 0x3005BB68
 * Данные: DAT_3005bf10, DAT_3005bf7c
 * ---------------------------------------------------------------- */
void os_hw_uninit(void)

{
  int iVar1;
  
  for (iVar1 = *DAT_3005bf7c; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
    if (*(int *)(iVar1 + 8) != 0) {
      del_generic_controller(*(undefined4 *)(iVar1 + 8));
      *(undefined4 *)(iVar1 + 8) = 0;
    }
  }
  uw_hw_uninit();
  *DAT_3005bf10 = 0;
  DAT_3005bf10[1] = DAT_3005bf10;
  return;
}

/* ----------------------------------------------------------------
 * os_hw_init @ 0x3005BBC4  (примерный размер ~228 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 8
 * Вызывает: FUN_3005baf0, add_generic_controller, os_dprintf, os_hw_uninit, os_printf, uw_get_buses, uw_hw_init, valid_type
 * Вызывают: jstart_stack
 * Константы: 0x3005BBC4
 * Данные: DAT_3005bf0c, DAT_3005bf10, DAT_3005bf18, DAT_3005bf1c, DAT_3005bf7c, DAT_3005bf80, DAT_3005bf84
 * ---------------------------------------------------------------- */
int os_hw_init(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  *DAT_3005bf10 = 0;
  DAT_3005bf10[1] = DAT_3005bf10;
  iVar1 = uw_hw_init();
  if (iVar1 == 0) {
    uVar2 = uw_get_buses();
    *DAT_3005bf7c = uVar2;
    for (puVar3 = (undefined4 *)*DAT_3005bf7c; puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)puVar3[4]) {
      uVar2 = FUN_3005baf0(param_1,*puVar3);
      iVar1 = add_generic_controller(puVar3,*puVar3,uVar2,puVar3 + 2);
      if (iVar1 != 0) goto LAB_3005bc5c;
    }
  }
  else {
LAB_3005bc5c:
    valid_type(3);
    if ((0 < *DAT_3005bf18) && (0 < DAT_3005bf18[3])) {
      os_dprintf(DAT_3005bf1c,DAT_3005bf0c,DAT_3005bf80);
      os_printf(DAT_3005bf84);
    }
    os_hw_uninit();
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * os_bus_alloc_resource @ 0x3005BCA8  (примерный размер ~316 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 3
 * Вызывает: os_dprintf, os_printf, valid_type
 * Вызывают: FUN_30055e10
 * Константы: 0x3005BCA8
 * Данные: DAT_3005bf0c, DAT_3005bf18, DAT_3005bf1c, DAT_3005bf88, DAT_3005bf8c, DAT_3005bf90, DAT_3005bf94, DAT_3005bf98
 * ---------------------------------------------------------------- */
int * os_bus_alloc_resource(int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  if (param_1 == 0) {
    valid_type(3);
    if ((0 < *DAT_3005bf18) && (0 < DAT_3005bf18[3])) {
      os_dprintf(DAT_3005bf1c,DAT_3005bf0c,DAT_3005bf88);
      os_printf(DAT_3005bf8c);
    }
  }
  else {
    valid_type(3);
    if ((3 < *DAT_3005bf18) && (3 < DAT_3005bf18[3])) {
      os_dprintf(DAT_3005bf1c,DAT_3005bf0c,DAT_3005bf90);
      os_printf(DAT_3005bf94,param_2,param_3);
    }
    for (piVar1 = *(int **)(param_1 + 4); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[5]) {
      if ((piVar1[1] == param_2) && (*piVar1 == param_3)) {
        return piVar1;
      }
    }
    valid_type(3);
    if ((0 < *DAT_3005bf18) && (0 < DAT_3005bf18[3])) {
      os_dprintf(DAT_3005bf1c,DAT_3005bf0c,DAT_3005bf98);
      os_printf(DAT_3005bf9c,param_2,param_3);
    }
  }
  return (int *)0x0;
}

/* ----------------------------------------------------------------
 * os_bus_release_resource @ 0x3005BDE4  (примерный размер ~4 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: FUN_30055d50
 * Константы: 0x3005BDE4
 * ---------------------------------------------------------------- */
void os_bus_release_resource(void)

{
  return;
}

/* ----------------------------------------------------------------
 * os_bus_space_read_1 @ 0x3005BDE8  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3005BDE8
 * ---------------------------------------------------------------- */
undefined1 os_bus_space_read_1(int param_1,int param_2)

{
  return *(undefined1 *)(*(int *)(param_1 + 8) + param_2);
}

/* ----------------------------------------------------------------
 * os_bus_space_read_2 @ 0x3005BE08  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3005BE08
 * ---------------------------------------------------------------- */
undefined2 os_bus_space_read_2(int param_1,int param_2)

{
  return *(undefined2 *)(*(int *)(param_1 + 8) + param_2);
}

/* ----------------------------------------------------------------
 * os_bus_space_read_4 @ 0x3005BE28  (примерный размер ~32 байт)
 * Модуль: data | Вызывают: 29 | Вызывает: 0
 * Вызывают: FUN_30050560, FUN_30050e60, FUN_30050f7c, FUN_30051038, FUN_30051150, FUN_30051394, FUN_30051430, FUN_300515b4, FUN_30051ff4, FUN_300520c8
 *           ...
 * Константы: 0x3005BE28
 * ---------------------------------------------------------------- */
undefined4 os_bus_space_read_4(int param_1,int param_2)

{
  return *(undefined4 *)(*(int *)(param_1 + 8) + param_2);
}

/* ----------------------------------------------------------------
 * os_bus_space_write_1 @ 0x3005BE48  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3005BE48
 * ---------------------------------------------------------------- */
void os_bus_space_write_1(int param_1,int param_2,undefined1 param_3)

{
  *(undefined1 *)(*(int *)(param_1 + 8) + param_2) = param_3;
  return;
}

/* ----------------------------------------------------------------
 * os_bus_space_write_2 @ 0x3005BE6C  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 0
 * Константы: 0x3005BE6C
 * ---------------------------------------------------------------- */
void os_bus_space_write_2(int param_1,int param_2,undefined2 param_3)

{
  *(undefined2 *)(*(int *)(param_1 + 8) + param_2) = param_3;
  return;
}

/* ----------------------------------------------------------------
 * os_bus_space_write_4 @ 0x3005BE90  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 22 | Вызывает: 0
 * Вызывают: FUN_30050e60, FUN_30050f7c, FUN_30051038, FUN_30051150, FUN_30051430, FUN_300515b4, FUN_30051ff4, FUN_3005264c, FUN_30052a84, FUN_30052ee4
 *           ...
 * Константы: 0x3005BE90
 * ---------------------------------------------------------------- */
void os_bus_space_write_4(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(*(int *)(param_1 + 8) + param_2) = param_3;
  return;
}

/* ----------------------------------------------------------------
 * FUN_3005beb4 @ 0x3005BEB4  (примерный размер ~236 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: BSP_MallocDbg, memset
 * Вызывают: os_interrupt_setup
 * Константы: 0x3005BEB4
 * ---------------------------------------------------------------- */
void * FUN_3005beb4(size_t param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = (void *)BSP_MallocDbg(param_1,0,param_3,param_4);
  if ((param_2 == 1) && (__s != (void *)0x0)) {
    memset(__s,0,param_1);
  }
  return __s;
}

/* ----------------------------------------------------------------
 * os_port_init @ 0x3005C074  (примерный размер ~48 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: os_sync_init
 * Вызывают: jos_init
 * Константы: 0x3005C074
 * Данные: DAT_3005c0e4
 * ---------------------------------------------------------------- */
int os_port_init(void)

{
  int iVar1;
  
  iVar1 = os_sync_init();
  if (iVar1 == 0) {
    *DAT_3005c0e4 = *DAT_3005c0e4 | 1;
  }
  return iVar1;
}

/* ----------------------------------------------------------------
 * os_port_uninit @ 0x3005C0A4  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: os_sync_uninit
 * Вызывают: jos_uninit
 * Константы: 0x3005C0A4
 * Данные: DAT_3005c0e4
 * ---------------------------------------------------------------- */
void os_port_uninit(void)

{
  if ((*DAT_3005c0e4 & 1) != 0) {
    os_sync_uninit();
  }
  *DAT_3005c0e4 = 0;
  return;
}

/* ----------------------------------------------------------------
 * os_printf @ 0x3005C0E8  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 227 | Вызывает: 1
 * Вызывает: logMsg
 * Вызывают: BSP_USB_BuildDevArgs, BSP_USB_BuildDevProfile, BSP_USB_DumpDevProfile, BSP_USB_DumpDevProt, BSP_USB_GetDevDescIdx, BSP_USB_GetDevProfileInfo, BSP_USB_QueryDevProfile, BSP_USB_UpdateDevPidInfo, BSP_USB_UpdateDevProfileInfo, BSP_USB_ValidateDevProfile
 *           ...
 * Константы: 0x3005C0E8
 * ---------------------------------------------------------------- */
void os_printf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_34 [6];
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar2 = &local_c;
  for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
    local_34[iVar1] = *puVar2;
    puVar2 = puVar2 + 1;
  }
  local_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  logMsg(param_1,local_34[0],local_34[1],local_34[2],local_34[3],local_34[4],local_34[5]);
  return;
}

/* ----------------------------------------------------------------
 * os_panic @ 0x3005C168  (примерный размер ~180 байт)
 * Модуль: data | Вызывают: 64 | Вызывает: 3
 * Вызывает: logMsg, taskIdSelf, taskSuspend
 * Вызывают: FUN_30047018, FUN_3004749c, FUN_30048358, FUN_30048f78, FUN_300498e4, FUN_30051c34, FUN_3005264c, FUN_30053a40, FUN_30054ca0, FUN_300551c0
 *           ...
 * Константы: 0x3005C168
 * Данные: DAT_3005c2d0
 * ---------------------------------------------------------------- */
void os_panic(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_34 [6];
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar2 = &local_c;
  for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
    local_34[iVar1] = *puVar2;
    puVar2 = puVar2 + 1;
  }
  local_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  logMsg(DAT_3005c2d0,0,0,0,0,0,0);
  logMsg(param_1,local_34[0],local_34[1],local_34[2],local_34[3],local_34[4],local_34[5]);
  taskIdSelf();
  taskSuspend();
  return;
}

/* ----------------------------------------------------------------
 * os_dprintf @ 0x3005C21C  (примерный размер ~188 байт)
 * Модуль: data | Вызывают: 227 | Вызывает: 2
 * Вызывает: dbg_get_time_diff, logMsg
 * Вызывают: FUN_30043bd4, FUN_30043e64, FUN_30046174, FUN_30047018, FUN_300471c0, FUN_3004749c, FUN_300475c0, FUN_30048358, FUN_300483e8, FUN_30048b78
 *           ...
 * Константы: 0x3005C21C
 * Данные: DAT_3005c2d4
 * ---------------------------------------------------------------- */
void os_dprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_38 [6];
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar3 = &local_c;
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    local_38[iVar2] = *puVar3;
    puVar3 = puVar3 + 1;
  }
  local_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar1 = dbg_get_time_diff();
  logMsg(DAT_3005c2d4,uVar1,0,0,0,0,0);
  logMsg(param_1,local_38[0],local_38[1],local_38[2],local_38[3],local_38[4],local_38[5]);
  return;
}

/* ----------------------------------------------------------------
 * uw_hw_init @ 0x3005C2D8  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: os_hw_init
 * Константы: 0x3005C2D8
 * ---------------------------------------------------------------- */
undefined4 uw_hw_init(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * uw_hw_uninit @ 0x3005C2E0  (примерный размер ~8 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: os_hw_uninit
 * Константы: 0x3005C2E0
 * ---------------------------------------------------------------- */
undefined4 uw_hw_uninit(void)

{
  return 0;
}

/* ----------------------------------------------------------------
 * uw_get_buses @ 0x3005C2E8  (примерный размер ~16 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 0
 * Вызывают: os_hw_init
 * Константы: 0x3005C2E8
 * Данные: DAT_3005c2f4
 * ---------------------------------------------------------------- */
undefined4 uw_get_buses(void)

{
  return *DAT_3005c2f4;
}

/* ----------------------------------------------------------------
 * os_malloc @ 0x3005C2F8  (примерный размер ~64 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: malloc, os_memset
 * Вызывают: jmalloc_d
 * Константы: 0x3005C2F8
 * ---------------------------------------------------------------- */
void * os_malloc(size_t param_1,uint param_2)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if ((pvVar1 != (void *)0x0) && ((param_2 & 1) != 0)) {
    os_memset(pvVar1,0,param_1);
  }
  return pvVar1;
}

/* ----------------------------------------------------------------
 * os_free @ 0x3005C338  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: free
 * Вызывают: jfree_d
 * Константы: 0x3005C338
 * ---------------------------------------------------------------- */
void os_free(void *param_1)

{
  free(param_1);
  return;
}

/* ----------------------------------------------------------------
 * os_dma_alloc @ 0x3005C34C  (примерный размер ~156 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: cacheDmaMalloc, os_memset
 * Вызывают: FUN_300471c0
 * Константы: 0x3005C34C
 * Данные: DAT_3005c584
 * ---------------------------------------------------------------- */
undefined4 os_dma_alloc(undefined4 param_1,int *param_2,int *param_3,uint param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = cacheDmaMalloc(param_1);
  if (iVar1 == 0) {
    uVar2 = 7;
  }
  else {
    *param_5 = iVar1;
    *param_2 = iVar1;
    if (*(int *)(DAT_3005c584 + 8) == 0) {
      *param_3 = *param_2;
    }
    else {
      iVar1 = (**(code **)(DAT_3005c584 + 8))(*param_2);
      *param_3 = iVar1;
    }
    if ((param_4 & 1) != 0) {
      os_memset(*param_2,0,param_1);
    }
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * os_dma_free @ 0x3005C3E8  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: cacheDmaFree
 * Вызывают: jdma_free_all
 * Константы: 0x3005C3E8
 * ---------------------------------------------------------------- */
void os_dma_free(undefined4 param_1)

{
  cacheDmaFree(param_1);
  return;
}

/* ----------------------------------------------------------------
 * os_cache_flush @ 0x3005C3FC  (примерный размер ~196 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: cacheFlush, os_dprintf, os_panic
 * Константы: 0x3005C3FC
 * Данные: DAT_3005c588, DAT_3005c58c, DAT_3005c590, DAT_3005c594
 * ---------------------------------------------------------------- */
void os_cache_flush(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_3005c588,DAT_3005c58c,0x3c);
    os_dprintf(DAT_3005c590);
    os_panic(DAT_3005c594,DAT_3005c58c,0x3c);
  }
  if (*param_1 == 0) {
    if (param_1[2] != 0) {
      iVar2 = 0;
      uVar1 = 0;
      do {
        cacheFlush(1,*(undefined4 *)(param_1[2] + iVar2 * 0xc),
                   *(undefined4 *)(iVar2 * 0xc + param_1[2] + 8));
        uVar1 = uVar1 + *(int *)(iVar2 * 0xc + param_1[2] + 8);
        iVar2 = iVar2 + 1;
      } while (uVar1 < param_2);
    }
  }
  else {
    cacheFlush(1,*param_1,param_2);
  }
  return;
}

/* ----------------------------------------------------------------
 * os_cache_invalidate @ 0x3005C4C0  (примерный размер ~216 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 3
 * Вызывает: cacheInvalidate, os_dprintf, os_panic
 * Константы: 0x3005C4C0
 * Данные: DAT_3005c588, DAT_3005c58c, DAT_3005c590, DAT_3005c594
 * ---------------------------------------------------------------- */
void os_cache_invalidate(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    os_dprintf(DAT_3005c588,DAT_3005c58c,0x55);
    os_dprintf(DAT_3005c590);
    os_panic(DAT_3005c594,DAT_3005c58c,0x55);
  }
  if (*param_1 == 0) {
    if (param_1[2] != 0) {
      iVar2 = 0;
      uVar1 = 0;
      do {
        cacheInvalidate(1,*(undefined4 *)(param_1[2] + iVar2 * 0xc),
                        *(undefined4 *)(iVar2 * 0xc + param_1[2] + 8));
        uVar1 = uVar1 + *(int *)(iVar2 * 0xc + param_1[2] + 8);
        iVar2 = iVar2 + 1;
      } while (uVar1 < param_2);
    }
  }
  else {
    cacheInvalidate(1,*param_1,param_2);
  }
  return;
}

/* ----------------------------------------------------------------
 * os_memcmp @ 0x3005C598  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: memcmp
 * Константы: 0x3005C598
 * ---------------------------------------------------------------- */
void os_memcmp(void *param_1,void *param_2,size_t param_3)

{
  memcmp(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * os_memcpy @ 0x3005C5BC  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 23 | Вызывает: 1
 * Вызывает: memcpy
 * Вызывают: BSP_USB_BuildDevProfile, BSP_USB_GetDevProfileInfo, FUN_30048b78, FUN_30048f78, FUN_3004b5d0, FUN_3004b88c, FUN_3004c2d8, FUN_3004c4c0, FUN_3004c688, FUN_30051280
 *           ...
 * Константы: 0x3005C5BC
 * ---------------------------------------------------------------- */
void os_memcpy(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * os_memset @ 0x3005C5E0  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 12 | Вызывает: 1
 * Вызывает: memset
 * Вызывают: BSP_USB_BuildDevProfile, BSP_USB_FreeDevProfile, BSP_USB_QueryDevProfile, BSP_USB_ValidateDevProfile, FUN_300498e4, FUN_3004c22c, jdbg_hex_dump, jdma_alloc, jmalloc_d, jos_sync_init
 *           ...
 * Константы: 0x3005C5E0
 * ---------------------------------------------------------------- */
void os_memset(void *param_1,int param_2,size_t param_3)

{
  memset(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * os_strlen @ 0x3005C604  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 5 | Вызывает: 1
 * Вызывает: strlen
 * Вызывают: FUN_3004c22c, j_device_set_nameunit, j_strdup, j_strlcpy, jmark_time_v
 * Константы: 0x3005C604
 * ---------------------------------------------------------------- */
void os_strlen(char *param_1)

{
  strlen(param_1);
  return;
}

/* ----------------------------------------------------------------
 * os_strcmp @ 0x3005C618  (примерный размер ~28 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: strcmp
 * Константы: 0x3005C618
 * ---------------------------------------------------------------- */
void os_strcmp(char *param_1,char *param_2)

{
  strcmp(param_1,param_2);
  return;
}

/* ----------------------------------------------------------------
 * os_strncmp @ 0x3005C634  (примерный размер ~36 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 1
 * Вызывает: strncmp
 * Константы: 0x3005C634
 * ---------------------------------------------------------------- */
void os_strncmp(char *param_1,char *param_2,size_t param_3)

{
  strncmp(param_1,param_2,param_3);
  return;
}

/* ----------------------------------------------------------------
 * os_snprintf @ 0x3005C658  (примерный размер ~100 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: vsnprintf
 * Вызывают: j_device_set_nameunit
 * Константы: 0x3005C658, 0xFFFFFFFF
 * ---------------------------------------------------------------- */
uint os_snprintf(char *param_1,size_t param_2,char *param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uStack_4;
  
  if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uStack_4 = param_4;
    uVar1 = vsnprintf(param_1,param_2,param_3,&uStack_4);
    if (param_2 < uVar1) {
      uVar1 = param_2 - uVar1;
    }
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * FUN_3005c6bc @ 0x3005C6BC  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 2
 * Вызывает: taskCpuLock, taskCpuUnlock
 * Вызывают: FUN_3005c700
 * Константы: 0x3005C6BC
 * Данные: DAT_3005d5e0
 * ---------------------------------------------------------------- */
int FUN_3005c6bc(int param_1)

{
  int *piVar1;
  
  taskCpuLock();
  for (piVar1 = (int *)*DAT_3005d5e0; (piVar1 != (int *)0x0 && (piVar1[2] != param_1));
      piVar1 = (int *)*piVar1) {
  }
  taskCpuUnlock();
  return (int)piVar1;
}

/* ----------------------------------------------------------------
 * FUN_3005c700 @ 0x3005C700  (примерный размер ~292 байт)
 * Модуль: data | Вызывают: 0 | Вызывает: 9
 * Вызывает: BSP_FreeDbg, FUN_3005c6bc, jos_safe_enter_d, jos_safe_leave_d, os_dprintf, os_printf, taskDelete, taskIdSelf, valid_type
 * Константы: 0x3005C700, 0xFFFFFFFF
 * Данные: DAT_3005d5e0, DAT_3005d5e4, DAT_3005d5e8, DAT_3005d5ec, DAT_3005d5f0
 * ---------------------------------------------------------------- */
undefined4 FUN_3005c700(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  uVar1 = taskIdSelf();
  piVar2 = (int *)FUN_3005c6bc(uVar1);
  if (piVar2 == (int *)0x0) {
    valid_type(2);
    if ((0 < *DAT_3005d5e4) && (0 < DAT_3005d5e4[2])) {
      os_dprintf(DAT_3005d5e8,DAT_3005d5ec,0x2e);
      os_printf(DAT_3005d5f0);
    }
    uVar1 = 0xffffffff;
  }
  else {
    jos_safe_enter_d(DAT_3005d5ec,0x33);
    (*(code *)piVar2[3])(piVar2[4]);
    jos_safe_leave_d(DAT_3005d5ec,0x35);
    piVar3 = (int *)*DAT_3005d5e0;
    while (piVar4 = piVar3, piVar4 != (int *)0x0) {
      piVar3 = (int *)*piVar4;
      if (piVar4 == piVar2) {
        if (*piVar4 == 0) {
          DAT_3005d5e0[1] = piVar4[1];
        }
        else {
          *(int *)(*piVar4 + 4) = piVar4[1];
        }
        *(int *)piVar4[1] = *piVar4;
      }
    }
    BSP_FreeDbg(piVar2,DAT_3005d5ec,0x3a);
    taskDelete(uVar1);
    uVar1 = 0;
  }
  return uVar1;
}

/* ----------------------------------------------------------------
 * os_get_context @ 0x3005C824  (примерный размер ~68 байт)
 * Модуль: data | Вызывают: 8 | Вызывает: 1
 * Вызывает: taskIdSelf
 * Вызывают: FUN_300483e8, FUN_30048f78, jdbg_check_context, jmutex_unlock_d, jos_core_lock_check, jos_mutex_lock_checked, jos_safe_check, jtask_uninit
 * Константы: 0x3005C824
 * Данные: DAT_3005d5f4
 * ---------------------------------------------------------------- */
undefined4 os_get_context(void)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  cVar1 = *DAT_3005d5f4;
  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
    uVar2 = taskIdSelf();
  }
  else if (cVar1 == '\x04') {
    uVar2 = 1;
  }
  return uVar2;
}

/* ----------------------------------------------------------------
 * os_thread_create @ 0x3005C868  (примерный размер ~584 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 9
 * Вызывает: BSP_FreeDbg, FUN_3005d58c, os_dprintf, os_panic, os_printf, taskCpuLock, taskCpuUnlock, taskSpawn, valid_type
 * Вызывают: jos_thread_create
 * Константы: 0x3005C868
 * Данные: DAT_3005d5e0, DAT_3005d5e4, DAT_3005d5e8, DAT_3005d5ec, DAT_3005d5f4, DAT_3005d5f8, DAT_3005d5fc, DAT_3005d600
 * ---------------------------------------------------------------- */
undefined4
os_thread_create(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  
  if ((*DAT_3005d5f4 & 1) == 0) {
    uVar3 = DAT_3005d5f8;
    if ((*DAT_3005d5f4 != 4) && (uVar3 = DAT_3005d600, *DAT_3005d5f4 == 2)) {
      uVar3 = DAT_3005d5fc;
    }
    os_panic(DAT_3005d604,DAT_3005d5ec,0x5d,uVar3);
  }
  piVar1 = (int *)FUN_3005d58c(0x14,1,DAT_3005d5ec,0x60);
  if (piVar1 != (int *)0x0) {
    piVar1[3] = param_1;
    piVar1[4] = param_2;
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = piVar1;
    }
    taskCpuLock();
    *piVar1 = 0;
    piVar1[1] = DAT_3005d5e0[1];
    *(int **)DAT_3005d5e0[1] = piVar1;
    DAT_3005d5e0[1] = piVar1;
    taskCpuUnlock();
    taskCpuLock();
    iVar2 = taskSpawn(param_4,param_3 + 0x7e,0,DAT_3005d60c,DAT_3005d608,0,0,0,0,0,0,0,0,0,0);
    piVar1[2] = iVar2;
    taskCpuUnlock();
    if (piVar1[2] != -1) {
      return 0;
    }
    piVar4 = (int *)*DAT_3005d5e0;
    while (piVar5 = piVar4, piVar5 != (int *)0x0) {
      piVar4 = (int *)*piVar5;
      if (piVar5 == piVar1) {
        if (*piVar5 == 0) {
          DAT_3005d5e0[1] = piVar5[1];
        }
        else {
          *(int *)(*piVar5 + 4) = piVar5[1];
        }
        *(int *)piVar5[1] = *piVar5;
      }
    }
    BSP_FreeDbg(piVar1,DAT_3005d5ec,0x7e);
  }
  valid_type(2);
  if ((0 < *DAT_3005d5e4) && (0 < DAT_3005d5e4[2])) {
    os_dprintf(DAT_3005d5e8,DAT_3005d5ec,0x81);
    os_printf(DAT_3005d610);
  }
  return 7;
}

/* ----------------------------------------------------------------
 * os_mutex_init @ 0x3005CAB0  (примерный размер ~264 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: BSP_FreeDbg, FUN_3005d58c, os_dprintf, os_panic, os_printf, semMCreate, valid_type
 * Вызывают: jmutex_init_d
 * Константы: 0x3005CAB0
 * Данные: DAT_3005d5e4, DAT_3005d5e8, DAT_3005d5ec, DAT_3005d5f4, DAT_3005d5f8, DAT_3005d5fc, DAT_3005d600, DAT_3005d604
 * ---------------------------------------------------------------- */
undefined4 os_mutex_init(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*DAT_3005d5f4 & 1) == 0) {
    uVar2 = DAT_3005d5f8;
    if ((*DAT_3005d5f4 != 4) && (uVar2 = DAT_3005d600, *DAT_3005d5f4 == 2)) {
      uVar2 = DAT_3005d5fc;
    }
    os_panic(DAT_3005d604,DAT_3005d5ec,0x8c,uVar2);
  }
  iVar1 = FUN_3005d58c(8,1,DAT_3005d5ec,0x8e);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    uVar2 = semMCreate(4);
    *(undefined4 *)(iVar1 + 4) = uVar2;
    if (*(int *)(iVar1 + 4) != 0) {
      return 0;
    }
    BSP_FreeDbg(iVar1,DAT_3005d5ec,0x95);
    *param_1 = 0;
  }
  valid_type(2);
  if ((0 < *DAT_3005d5e4) && (0 < DAT_3005d5e4[2])) {
    os_dprintf(DAT_3005d5e8,DAT_3005d5ec,0x9d);
    os_printf(DAT_3005d614);
  }
  return 7;
}

/* ----------------------------------------------------------------
 * os_mutex_uninit @ 0x3005CBB8  (примерный размер ~216 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 7
 * Вызывает: BSP_FreeDbg, os_dprintf, os_panic, os_printf, semDelete, semFlush, valid_type
 * Вызывают: jmutex_uninit_d
 * Константы: 0x3005CBB8
 * Данные: DAT_3005d5e4, DAT_3005d5e8, DAT_3005d5ec, DAT_3005d5f4, DAT_3005d5f8, DAT_3005d5fc, DAT_3005d600, DAT_3005d604
 * ---------------------------------------------------------------- */
void os_mutex_uninit(char *param_1)

{
  undefined4 uVar1;
  
  if ((*DAT_3005d5f4 & 1) == 0) {
    uVar1 = DAT_3005d5f8;
    if ((*DAT_3005d5f4 != 4) && (uVar1 = DAT_3005d600, *DAT_3005d5f4 == 2)) {
      uVar1 = DAT_3005d5fc;
    }
    os_panic(DAT_3005d604,DAT_3005d5ec,0xa5,uVar1);
  }
  if (*param_1 != '\0') {
    valid_type(2);
    if ((1 < *DAT_3005d5e4) && (1 < DAT_3005d5e4[2])) {
      os_dprintf(DAT_3005d5e8,DAT_3005d5ec,0xa9);
      os_printf(DAT_3005d618,param_1);
    }
    semFlush(*(undefined4 *)(param_1 + 4));
  }
  semDelete(*(undefined4 *)(param_1 + 4));
  BSP_FreeDbg(param_1,DAT_3005d5ec,0xaf);
  return;
}

/* ----------------------------------------------------------------
 * os_mutex_lock @ 0x3005CC90  (примерный размер ~128 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: os_panic, semTake
 * Вызывают: jos_mutex_lock, jos_mutex_lock_checked, jos_safe_enter
 * Константы: 0x3005CC90, 0xFFFFFFFF
 * Данные: DAT_3005d5ec, DAT_3005d5f4, DAT_3005d5f8, DAT_3005d5fc, DAT_3005d600, DAT_3005d604
 * ---------------------------------------------------------------- */
void os_mutex_lock(char *param_1)

{
  undefined4 uVar1;
  
  if ((*DAT_3005d5f4 & 1) == 0) {
    uVar1 = DAT_3005d5f8;
    if ((*DAT_3005d5f4 != 4) && (uVar1 = DAT_3005d600, *DAT_3005d5f4 == 2)) {
      uVar1 = DAT_3005d5fc;
    }
    os_panic(DAT_3005d604,DAT_3005d5ec,0xb6,uVar1);
  }
  *param_1 = *param_1 + '\x01';
  semTake(*(undefined4 *)(param_1 + 4),0xffffffff);
  return;
}

/* ----------------------------------------------------------------
 * os_mutex_unlock @ 0x3005CD10  (примерный размер ~124 байт)
 * Модуль: data | Вызывают: 3 | Вызывает: 2
 * Вызывает: os_panic, semGive
 * Вызывают: jmutex_unlock_d, jos_mutex_unlock, jos_safe_leave
 * Константы: 0x3005CD10
 * Данные: DAT_3005d5ec, DAT_3005d5f4, DAT_3005d5f8, DAT_3005d5fc, DAT_3005d600, DAT_3005d604
 * ---------------------------------------------------------------- */
void os_mutex_unlock(char *param_1)

{
  undefined4 uVar1;
  
  if ((*DAT_3005d5f4 & 1) == 0) {
    uVar1 = DAT_3005d5f8;
    if ((*DAT_3005d5f4 != 4) && (uVar1 = DAT_3005d600, *DAT_3005d5f4 == 2)) {
      uVar1 = DAT_3005d5fc;
    }
    os_panic(DAT_3005d604,DAT_3005d5ec,0xc1,uVar1);
  }
  semGive(*(undefined4 *)(param_1 + 4));
  *param_1 = *param_1 + -1;
  return;
}

/* ----------------------------------------------------------------
 * os_critical_enter @ 0x3005CD8C  (примерный размер ~20 байт)
 * Модуль: data | Вызывают: 1 | Вызывает: 1
 * Вызывает: intCpuLock
 * Вызывают: jos_critical_enter
 * Константы: 0x3005CD8C
 * Данные: DAT_3005d61c
 * ---------------------------------------------------------------- */
void os_critical_enter(void)

{
  undefined4 uVar1;
  
  uVar1 = intCpuLock();
  *DAT_3005d61c = uVar1;
  return;
}

