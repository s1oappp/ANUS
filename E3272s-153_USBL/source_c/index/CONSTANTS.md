# Часто повторяющиеся 32-битные константы (кандидаты на MMIO/магию)

| Константа | Сколько функций | Примеры функций |
|---|---|---|
| 0xFFFFFFFF | 1400 | sysNvRamGet, sysNvRamSet, sysToMonitor |
| 0x80000000 | 96 | yaffs_PackTags2TagsPart, HI6451_current_overflow_get, HI6451_reset_log_save |
| 0xFFFFFFFE | 91 | ABB_UnReset, BBP_UnReset, FUN_3001e770 |
| 0x7FFFFFFF | 76 | SsdmaReset, FUN_30036888, ran_seed |
| 0x00100000 | 63 | BSP_WDT_reboot_direct, BSP_OM_SoftReboot, nandc_host_add_nand_chip |
| 0x40000000 | 44 | yaffs_DeleteChunk, yaffs_UpdateObjectHeader, yaffs_PackTags2TagsPart |
| 0xFFFFFFFC | 41 | USB_UnReset, armGicIntReroute, crypto_aes_init |
| 0x01000000 | 30 | yaffs_HandleChunkError, yaffs_BlockBecameDirty, FUN_30019d80 |
| 0x00800000 | 29 | FUN_3001b01c, HI6451_error_log_save, HI6451_undervoltage_isr |
| 0xFFFFFFFD | 27 | USB_UnReset, primeCellSioIntTx, hwVerGet |
| 0x00200000 | 23 | FUN_3001df80, yaffs_BackgroundGarbageCollect, yaffs_UpdateDirtyDirectories |
| 0xFF000000 | 23 | FUN_300a5fe4, FUN_300a62bc, FUN_300ac330 |
| 0xF0000000 | 22 | nandc_ctrl_read_normal, FUN_30011240, FUN_30011bd4 |
| 0x0FFFFFFF | 22 | FUN_30011bd4, FUN_3001465c, FUN_30014c54 |
| 0xFFFFFFFB | 19 | crypto_aes_encrypt_block, crypto_aes_decrypt_block, crypto_aes_encrypt_pad |
| 0x08000000 | 18 | USB_UnReset, armGicCtlInit, nandc_host_add_nand_chip |
| 0xFFFFFFEA | 18 | yaffs_unmount, yaffs_freespace, yaffs_readlink |
| 0x00FFFFFF | 17 | TestBitValue, HSSD_Send_CMD6, Unpack_CCCR_reg |
| 0x300A1490 | 16 | r0, r1, r2 |
| 0x20000000 | 14 | nandc_native_host_create, yaffs_PackTags2TagsPart, HI6451_voltage_switch |
| 0xFFFFFF00 | 13 | sysInit, FUN_30004008, Resume_Transfer |
| 0xFFFFFFF7 | 13 | BBP_UnReset, yaffs_close, yaffs_read |
| 0x04000000 | 13 | yaffs_HandleChunkError, FUN_3001b670, HI6451_current_overflow_get |
| 0x00400000 | 13 | FUN_30019e10, HI6451_current_overflow_get, HI6451_reset_log_save |
| 0x10000000 | 12 | PWRCTRL_SPI_SoftClkDis, PWRCTRL_SPI_SoftClkEn, HI6451_current_overflow_get |
| 0x1FFFFFFF | 11 | nandc_ctrl_read_normal, FUN_30011240, nandc_ctrl_entry |
| 0x30000000 | 10 | sysInit, FUN_30004008, usrBanner |
| 0xFFFFEFFF | 10 | USB_UnReset, hwVerGet, Form_SDIO_CmdReg |
| 0x02000000 | 10 | USB_UnReset, yaffs_BlockBecameDirty, FUN_3001a0fc |
| 0xFF0FFFFF | 10 | FUN_30017ee4, FUN_300183fc, yaffs2_CheckpointClose |
| 0xFFF00001 | 9 | __fpl_dcheck_NaN2, __fpl_dcmp_InfNaN, _drdiv |
| 0x07000000 | 8 | sysInit, FUN_30004008, cacheAimArch7DClearAll |
| 0xFFFFFFF0 | 8 | yaffs_mount, yaffs_unmount, SetSsdmaRsaMode |
| 0xFFFFFFEF | 7 | BBP_UnReset, yaffs_open, yaffs_link |
| 0x3FFFFFFF | 7 | FUN_30050f7c, FUN_30051430, FUN_300515b4 |
| 0xFFDFFFFF | 7 | FUN_30051150, Form_Send_Cmd, Form_SDIO_CmdReg |
| 0xFFFFFFC0 | 6 | Blksize_Data_Transfer, Partial_Blk_Xfer, Read_Write_StreamData |
| 0x7F000000 | 6 | __truncdfsf2, __extendsfdf2, __fixunssfsi |
| 0xFFE00000 | 6 | __fpl_dcmp_InfNaN, _dcmpeq, _dcmpge |
| 0xFFFFFF7F | 5 | BBP_UnReset, Form_CSD_Write_Cmd, Default_CmdReg_forDataCmd |
| 0xFFFFFFF8 | 5 | hwVerGet, FUN_300296d0, crypto_aes_decrypt_pad |
| 0xFFFFFFE4 | 5 | FUN_3001fd28, yaffs_mkdir, yaffs_symlink |
| 0xFFFFFFB2 | 5 | yaffs_GetXAttribute, yaffs_ListXAttributes, nval_del |
| 0xFFFF7FFF | 5 | GPIO_Int_handle, Form_SDIO_CmdReg, Form_Data_Command |
| 0x0A000000 | 5 | FUN_30050f7c, FUN_30051430, FUN_300515b4 |
| 0x84000000 | 5 | FUN_30050f7c, FUN_30051430, FUN_300515b4 |
| 0xFFFFFBFF | 5 | BSP_CY22393_Init, Form_SDIO_CmdReg, Form_Data_Command |
| 0xFFFFF7FF | 5 | Form_SDIO_CmdReg, Form_Data_Command, Form_CSD_Write_Cmd |
| 0xFFEFFFFF | 5 | FUN_300ad9ec, sfpDoubleNormalize, sfpDoubleNormalize2 |
| 0xC0000000 | 5 | expm1, _drdiv, __divdf3 |
| 0x00140000 | 5 | _drdiv, __divdf3, _drem |
| 0xFF000001 | 5 | __divsf3, _fcmpeq, _fcmpge |
| 0x00900000 | 4 | FUN_30017ee4, FUN_300197f0, yaffs1_Scan |
| 0x00700000 | 4 | FUN_300183fc, yaffs2_CheckpointClose, yaffs2_ScanBackwards |
| 0x00500000 | 4 | yaffs_SkipRestOfBlock, FUN_30019f80, FUN_3001b01c |
| 0xFFE0FFFF | 4 | Form_SDIO_CmdReg, Form_Data_Command, Form_CSD_Write_Cmd |
| 0xFFFFBFFF | 4 | Form_SDIO_CmdReg, Form_Data_Command, Form_CSD_Write_Cmd |
| 0x00F00000 | 4 | FUN_300a2ff8, FUN_300ac5b4, FUN_300ae13c |
| 0x00130000 | 4 | _drdiv, __divdf3, _drem |
| 0x40100000 | 4 | __fixunsdfsi, _dfixu_r, __fixunsdfdi |
| 0x00FF0000 | 4 | __divsf3, __funder_d, __mulsf3 |
| 0x7F800000 | 4 | __divsf3, __addsf3, _frsb |
| 0x300B86F0 | 4 | __addsf3, _frsb, __subsf3 |
| 0x300B8794 | 4 | __addsf3, _frsb, __subsf3 |
| 0xFFFFDFFF | 3 | USB_UnReset, Form_SDIO_CmdReg, Form_Data_Command |
| 0x00300000 | 3 | FUN_30017ee4, yaffs_BlockBecameDirty, __floatdidf |
| 0xBFFFFFFF | 3 | FUN_3001b01c, ptable_mark_default, HI6451_error_log_save |
| 0xFFFFFFF4 | 3 | yaffs_GetXAttribute, yaffs_ListXAttributes, yaffs_mount |
| 0xFFFFFFEC | 3 | yaffs_open, yaffsfs_DoUnlink, yaffs_link |
| 0xFFFFFFF1 | 3 | yaffsfs_DoUnlink, FUN_3008b498, FUN_3008b88c |
| 0x80000001 | 3 | ran_next, __dunder, FUN_300d063c |
| 0xFFBFFFFF | 3 | sdmmcDrvHwInit, sdmmcHwInit, sdmmcStatusPollTask |
| 0xFFFFFFFA | 3 | QC_deflateInit2_, QC_inflateInit2_, mmuCortexA8ADisable |
| 0x300A9D4C | 3 | windExit, reschedule, windLoadContext |
| 0xFFF00000 | 3 | __fpl_dcheck_NaN2, __fpl_dcmp_InfNaN, __adddf3 |
| 0xA0000000 | 3 | __adddf3, _drsb, __subdf3 |
| 0xFEFFFFFF | 3 | __addsf3, _frsb, __subsf3 |
| 0xFFFFFFF9 | 3 | windPendQRemove, windPendQGet, windReadyQPut |
| 0xFDFFFFFF | 2 | USB_UnReset, FUN_3001a0fc |
| 0xFFFFFFF3 | 2 | yaffs_open, yaffs_rename |
| 0xFFFFFFEE | 2 | yaffs_rename, yaffs_link |
| 0xFFFFFFED | 2 | yaffs_mount, yaffs_unmount |
| 0x03FFFFFF | 2 | ABB_LineCtrl, SDIO_RdWr_Extended |
| 0xFFFFFFE0 | 2 | SetSsdmaRsaMode, cacheDmaMalloc |
| 0x7FFFFFFE | 2 | ran_seed, ran_next |
| 0x8FFFFFFF | 2 | Abort_transfer, Resume_Transfer |
| 0xFFFFC0FF | 2 | sdmmcDrvHwInit, sdmmcHwInit |
| 0x0F000000 | 2 | _dbgFuncCallCheck, __floatdisf |
| 0x01200000 | 2 | FUN_300a3184, FUN_300a3228 |
| 0xFE000000 | 2 | FUN_300a5fe4, __funder_d |
| 0x300A7308 | 2 | excEnterPrefetchAbort, excEnterUndef |
| 0x300A7328 | 2 | excEnterPrefetchAbort, excEnterUndef |
| 0x300A7330 | 2 | excEnterPrefetchAbort, excEnterUndef |
| 0x3E3FFFFF | 2 | asin, __kernel_sin |
| 0x60000000 | 2 | pow, __funder_d |
| 0xFF800001 | 2 | __fpl_fcheck_NaN2, __divsf3 |
| 0x007FFFFF | 2 | __fpl_fcheck_NaN2, __funder |
| 0x00FC0000 | 2 | __divsf3, __mulsf3 |
| 0xCF000001 | 2 | __fixsfsi, _ffix_r |
| 0xDF000001 | 2 | __fixsfdi, _ll_sfrom_f_r |
| 0x01F00000 | 2 | __floatsidf, __dflt_normalise |
| 0x0F800000 | 2 | __floatsisf, __fflt_normalise |
| 0x300E0D0C | 2 | coprocEnable, coprocDisable |
| 0x300E0DFC | 2 | coprocTaskRegsGet, coprocTaskRegsSet |
| 0xFF00FFFF | 2 | FUN_300f5c58, FUN_300f9380 |
| 0xFFFFFFC2 | 2 | semMInit, semRWInitialize |
| 0x30004000 | 1 | sysInit |
| 0x30004008 | 1 | FUN_30004008 |
| 0x3000414C | 1 | archPwrDown |
| 0x30004174 | 1 | spinLockAmpGive |
| 0x30004188 | 1 | spinLockAmpTake |
| 0x300041AC | 1 | spinLockAmpTakeOneTime |
| 0x300041C4 | 1 | __rt_memcpy |
| 0x300042F4 | 1 | sysNvRamGet |
| 0x300042FC | 1 | sysNvRamSet |
| 0x30004304 | 1 | sysModel |
| 0x3000430C | 1 | sysBspRev |
| 0x30004314 | 1 | sysHwInit0 |
| 0x30004334 | 1 | sysHwInit |
| 0x30004360 | 1 | sysHwInit2 |
| 0x300043BC | 1 | sysPhysMemTop |
| 0x300043E4 | 1 | sysMemTop |
| 0x30004418 | 1 | sysToMonitor |
| 0x300044EC | 1 | sysProcNumGet |
| 0x300044F8 | 1 | sysProcNumSet |
| 0x30004510 | 1 | bspSerialChanGet |
| 0x30004518 | 1 | sysCpuAvailableGet |
| 0x3000452C | 1 | sysMsDelay |
| 0x300045F8 | 1 | sysDelay |
| 0x3000465C | 1 | ABB_UnReset |
| 0x300046B4 | 1 | BSP_LDScript |
| 0x3000476C | 1 | BSP_OsWait |
| 0x300048D8 | 1 | activeAppCore |
| 0x300048E0 | 1 | BSP_USB_RegEnumDoneForMsp |
| 0x30004920 | 1 | BSP_USB_RegEnumDoneForPs |
| 0x30004960 | 1 | BBP_UnReset |
| 0xFFFFFFBF | 1 | BBP_UnReset |
| 0xFFFF1FFF | 1 | BBP_UnReset |
| 0x30004A18 | 1 | USB_UnReset |
| 0xF7FFFFFF | 1 | USB_UnReset |
| 0xE7FFFFFF | 1 | USB_UnReset |
| 0x30004AF8 | 1 | power_off_clearup_flag |
| 0x30004B2C | 1 | waitACoreNandRelease |
| 0x30004B30 | 1 | drvMultiCoreInit |
| 0x30004B34 | 1 | BSP_PromptSet |
| 0x30004B88 | 1 | BSP_DRV_BOOTROM_Init |
| 0x30005018 | 1 | usrAppInit |
| 0x30005084 | 1 | dummyForMSP |
| 0x30005150 | 1 | usrRtpAppInit |
| 0x30005154 | 1 | BSP_ClearLogModule |
| 0x300051F0 | 1 | BSP_SetLogModule |
| 0x30005288 | 1 | BSP_GetLogModule |
| 0x30005294 | 1 | BSP_SetLogLevel |
| 0x300052AC | 1 | BSP_GetLogLevel |
| 0x300052B8 | 1 | BSP_SetPrintPos |
| 0x300052D0 | 1 | BSP_GetPrintPos |
| 0x300052DC | 1 | BSP_ErrnoGet |
| 0x300052E0 | 1 | BSP_TaskErrnoGet |
| 0x300052F4 | 1 | BSP_ErrnoSet |
| 0x30005308 | 1 | BSP_TaskErrnoSet |
| 0x30005324 | 1 | BSP_RegExceptionalEventReport |
| 0x3000533C | 1 | BSP_TRACE |
| 0x300054B8 | 1 | BSPLogHelp |
| 0x30005590 | 1 | IOS_Config |
| 0x300055A8 | 1 | IOS_Config |
| 0x30005B50 | 1 | FUN_30005b50 |
| 0x30005C90 | 1 | BSP_SFree |
| 0x30005D3C | 1 | FUN_30005d3c |
| 0x30005E50 | 1 | memUsrInitFunction |
| 0x30005E74 | 1 | BSP_MEM_SetMostUsedSize |
| 0x30005F54 | 1 | BSP_MEM_Init |
| 0x3000602C | 1 | BSP_Malloc |
| 0x3000604C | 1 | BSP_MallocDbg |
| 0x30006084 | 1 | BSP_Free |
| 0x300060A4 | 1 | BSP_FreeDbg |
| 0x30006138 | 1 | BSP_SMalloc |
| 0x3000615C | 1 | BSP_SMallocDbg |
| 0x300061B4 | 1 | BSP_SFreeDbg |
| 0x300061C8 | 1 | BSP_MEM_Info |
| 0x30006370 | 1 | BSP_MEM_DumpBlock |
| 0x30006484 | 1 | BSP_MEM_DumpAllocList |
| 0x300065C4 | 1 | BSP_MEM_Scan |
| 0x300067B0 | 1 | FUN_300067b0 |
| 0x30006964 | 1 | FUN_30006964 |
| 0x30006BA8 | 1 | FUN_30006ba8 |
| 0x30006CC0 | 1 | FUN_30006cc0 |
| 0x30006D10 | 1 | FUN_30006d10 |
| 0x30006EDC | 1 | BSP_CalcCrc32 |
| 0x30006F54 | 1 | WDT_FeedLogStart |
| 0x30006F7C | 1 | WDT_FeedLogStop |
| 0x30006F98 | 1 | WDT_FeedLog |
| 0x3000702C | 1 | WDT_FeedLogClean |
| 0x3000703C | 1 | WDT_ShowLog |
| 0x30007124 | 1 | PWRCTRL_WDT_SoftClkStatus |
| 0x30007174 | 1 | PWRCTRL_WDT_SoftClkDis |
| 0x30007184 | 1 | PWRCTRL_WDT_SoftClkEn |
| 0x30007194 | 1 | WDT_LOCK |
| 0x300071A4 | 1 | WDT_UNLOCK |
| 0x300071B4 | 1 | BSP_WDT_HardwareFeed |
| 0x30007260 | 1 | WDT_LowTask |
