-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : BL-UPDATE-CLIENT-UT
-- Unit(s) Under Test: UPD_Cfg UPD_memdrv_if UPDd
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UPD_memdrv_if

-- Subprogram: BasicCodeFlashBlockingTest1

-- Test Case: BasicCodeFlashBlockingTest1.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:BasicCodeFlashBlockingTest1
TEST.NEW
TEST.NAME:BasicCodeFlashBlockingTest1.001
TEST.VALUE:UPD_memdrv_if.BasicCodeFlashBlockingTest1.SectorAddr:10000
TEST.VALUE:UPD_memdrv_if.BasicCodeFlashBlockingTest1.SectorSizeInByte:1
TEST.END

-- Test Case: BasicCodeFlashBlockingTest1.002
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:BasicCodeFlashBlockingTest1
TEST.NEW
TEST.NAME:BasicCodeFlashBlockingTest1.002
TEST.VALUE:UPD_memdrv_if.BasicCodeFlashBlockingTest1.SectorAddr:100000
TEST.VALUE:UPD_memdrv_if.BasicCodeFlashBlockingTest1.SectorSizeInByte:0xFFFFFFFF
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.cy_assertLine:451
TEST.EXPECTED:uut_prototype_stubs.Cy_SysLib_Halt.reason:0
TEST.END

-- Subprogram: BasicWorkFlashBlockingTest

-- Test Case: BasicWorkFlashBlockingTest.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:BasicWorkFlashBlockingTest
TEST.NEW
TEST.NAME:BasicWorkFlashBlockingTest.001
TEST.VALUE:UPD_memdrv_if.BasicWorkFlashBlockingTest.SectorAddr:100000
TEST.VALUE:UPD_memdrv_if.BasicWorkFlashBlockingTest.SectorSizeInByte:1020
TEST.ATTRIBUTES:UPD_memdrv_if.BasicWorkFlashNonBlockingTest.SectorSizeInByte:INPUT_BASE=10
TEST.END

-- Subprogram: BasicWorkFlashNonBlockingTest

-- Test Case: BasicWorkFlashNonBlockingTest.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:BasicWorkFlashNonBlockingTest
TEST.NEW
TEST.NAME:BasicWorkFlashNonBlockingTest.001
TEST.END

-- Test Case: BasicWorkFlashNonBlockingTest.002
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:BasicWorkFlashNonBlockingTest
TEST.NEW
TEST.NAME:BasicWorkFlashNonBlockingTest.002
TEST.VALUE:uut_prototype_stubs.Cy_Is_SROM_API_Completed.return:true
TEST.END

-- Test Case: BasicWorkFlashNonBlockingTest.003
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:BasicWorkFlashNonBlockingTest
TEST.NEW
TEST.NAME:BasicWorkFlashNonBlockingTest.003
TEST.VALUE:uut_prototype_stubs.Cy_Is_SROM_API_Completed.return:true
TEST.VALUE:UPD_memdrv_if.BasicWorkFlashNonBlockingTest.SectorAddr:10000
TEST.VALUE:UPD_memdrv_if.BasicWorkFlashNonBlockingTest.SectorSizeInByte:1
TEST.END

-- Test Case: BasicWorkFlashNonBlockingTest.004
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:BasicWorkFlashNonBlockingTest
TEST.NEW
TEST.NAME:BasicWorkFlashNonBlockingTest.004
TEST.VALUE:uut_prototype_stubs.Cy_Is_SROM_API_Completed.return:true
TEST.VALUE:UPD_memdrv_if.<<GLOBAL>>.programData1[0]:120
TEST.VALUE:UPD_memdrv_if.BasicWorkFlashNonBlockingTest.SectorAddr:100000
TEST.VALUE:UPD_memdrv_if.BasicWorkFlashNonBlockingTest.SectorSizeInByte:12
TEST.END

-- Test Case: BasicWorkFlashNonBlockingTest.005
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:BasicWorkFlashNonBlockingTest
TEST.NEW
TEST.NAME:BasicWorkFlashNonBlockingTest.005
TEST.VALUE:uut_prototype_stubs.Cy_WorkFlashBlankCheck.sectorAddr:1
TEST.VALUE:uut_prototype_stubs.Cy_WorkFlashBlankCheck.blocking:CY_FLASH_DRIVER_NON_BLOCKING
TEST.VALUE:uut_prototype_stubs.Cy_WorkFlashBlankCheck.return:false
TEST.END

-- Subprogram: FblFlashDrv_Erase

-- Test Case: FblFlashDrv_Erase.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblFlashDrv_Erase
TEST.NEW
TEST.NAME:FblFlashDrv_Erase.001
TEST.VALUE:uut_prototype_stubs.Cy_SysLib_Halt.reason:1
TEST.VALUE:UPD_memdrv_if.FblFlashDrv_Erase.addr:111111
TEST.VALUE:UPD_memdrv_if.FblFlashDrv_Erase.len:327680
TEST.VALUE:UPD_memdrv_if.FblFlashDrv_Erase.return:1
TEST.ATTRIBUTES:UPD_memdrv_if.BasicWorkFlashNonBlockingTest.SectorSizeInByte:INPUT_BASE=10
TEST.END

-- Test Case: FblFlashDrv_Erase.003
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblFlashDrv_Erase
TEST.NEW
TEST.NAME:FblFlashDrv_Erase.003
TEST.VALUE:uut_prototype_stubs.Cy_SysLib_Halt.reason:1
TEST.VALUE:UPD_memdrv_if.FblFlashDrv_Erase.addr:0x103F0001
TEST.VALUE:UPD_memdrv_if.FblFlashDrv_Erase.len:0
TEST.VALUE:UPD_memdrv_if.FblFlashDrv_Erase.return:1
TEST.ATTRIBUTES:UPD_memdrv_if.BasicWorkFlashNonBlockingTest.SectorSizeInByte:INPUT_BASE=10
TEST.END

-- Subprogram: FblFlashDrv_Init

-- Test Case: FblFlashDrv_Init.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblFlashDrv_Init
TEST.NEW
TEST.NAME:FblFlashDrv_Init.001
TEST.EXPECTED:uut_prototype_stubs.Cy_FlashInit.blocking:false
TEST.END

-- Subprogram: FblFlashDrv_Write

-- Test Case: FblFlashDrv_Write.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblFlashDrv_Write
TEST.NEW
TEST.NAME:FblFlashDrv_Write.001
TEST.VALUE:UPD_memdrv_if.FblFlashDrv_Write.pLen:<<malloc 1>>
TEST.END

-- Test Case: FblFlashDrv_Write.002
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblFlashDrv_Write
TEST.NEW
TEST.NAME:FblFlashDrv_Write.002
TEST.VALUE:UPD_memdrv_if.FblFlashDrv_Write.pLen:<<malloc 1>>
TEST.VALUE:UPD_memdrv_if.FblFlashDrv_Write.pLen[0]:1024
TEST.VALUE:UPD_memdrv_if.FblFlashDrv_Write.pBuffer:<<malloc 1>>
TEST.END

-- Subprogram: FblHsmFlashDrv_Erase

-- Test Case: FblHsmFlashDrv_Erase.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblHsmFlashDrv_Erase
TEST.NEW
TEST.NAME:FblHsmFlashDrv_Erase.001
TEST.EXPECTED:UPD_memdrv_if.<<GLOBAL>>.l_HsmReflashStartDone:0
TEST.EXPECTED:UPD_memdrv_if.<<GLOBAL>>.l_HsmReflashUpdateDone:0
TEST.END

-- Subprogram: FblHsmFlashDrv_Init

-- Test Case: FblHsmFlashDrv_Init.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblHsmFlashDrv_Init
TEST.NEW
TEST.NAME:FblHsmFlashDrv_Init.001
TEST.END

-- Subprogram: FblHsmFlashDrv_Write

-- Test Case: FblHsmFlashDrv_Write.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblHsmFlashDrv_Write
TEST.NEW
TEST.NAME:FblHsmFlashDrv_Write.001
TEST.END

-- Test Case: FblHsmFlashDrv_Write.002
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblHsmFlashDrv_Write
TEST.NEW
TEST.NAME:FblHsmFlashDrv_Write.002
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.addr:0x10000000
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.pLen:<<malloc 1>>
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.pLen[0]:512
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.pBuffer:<<malloc 1>>
TEST.EXPECTED:UPD_memdrv_if.<<GLOBAL>>.l_Callback_Status:CSM_E_BUSY
TEST.EXPECTED:UPD_memdrv_if.<<GLOBAL>>.l_HsmReflashStartDone:1
TEST.END

-- Test Case: FblHsmFlashDrv_Write.003
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblHsmFlashDrv_Write
TEST.NEW
TEST.NAME:FblHsmFlashDrv_Write.003
TEST.VALUE:UPD_memdrv_if.<<GLOBAL>>.l_Callback_Status:CSM_E_OK
TEST.VALUE:UPD_memdrv_if.<<GLOBAL>>.l_HsmReflashStartDone:1
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.addr:0x10000000
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.pLen:<<malloc 1>>
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.pLen[0]:512
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.pBuffer:<<malloc 1>>
TEST.EXPECTED:UPD_memdrv_if.<<GLOBAL>>.l_HsmReflashUpdateDone:1
TEST.END

-- Test Case: FblHsmFlashDrv_Write.004
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblHsmFlashDrv_Write
TEST.NEW
TEST.NAME:FblHsmFlashDrv_Write.004
TEST.VALUE:UPD_memdrv_if.<<GLOBAL>>.l_Callback_Status:CSM_E_BUSY
TEST.VALUE:UPD_memdrv_if.<<GLOBAL>>.l_HsmReflashStartDone:1
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.addr:0x10000000
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.pLen:<<malloc 1>>
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.pLen[0]:512
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.pBuffer:<<malloc 1>>
TEST.END

-- Test Case: FblHsmFlashDrv_Write.005
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblHsmFlashDrv_Write
TEST.NEW
TEST.NAME:FblHsmFlashDrv_Write.005
TEST.VALUE:UPD_memdrv_if.<<GLOBAL>>.l_Callback_Status:CSM_E_OK
TEST.VALUE:UPD_memdrv_if.<<GLOBAL>>.l_HsmReflashStartDone:1
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.addr:0x10000000
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.pLen:<<malloc 1>>
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.pLen[0]:1
TEST.VALUE:UPD_memdrv_if.FblHsmFlashDrv_Write.pBuffer:<<malloc 1>>
TEST.END

-- Subprogram: FblHsmFlashGetResp_erase

-- Test Case: FblHsmFlashGetResp_erase.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblHsmFlashGetResp_erase
TEST.NEW
TEST.NAME:FblHsmFlashGetResp_erase.001
TEST.END

-- Test Case: FblHsmFlashGetResp_erase.002
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblHsmFlashGetResp_erase
TEST.NEW
TEST.NAME:FblHsmFlashGetResp_erase.002
TEST.VALUE:UPD_memdrv_if.<<GLOBAL>>.l_Callback_Status:CSM_E_OK
TEST.END

-- Subprogram: FblHsmFlashGetResp_write

-- Test Case: FblHsmFlashGetResp_write.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblHsmFlashGetResp_write
TEST.NEW
TEST.NAME:FblHsmFlashGetResp_write.001
TEST.END

-- Test Case: FblHsmFlashGetResp_write.002
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblHsmFlashGetResp_write
TEST.NEW
TEST.NAME:FblHsmFlashGetResp_write.002
TEST.VALUE:UPD_memdrv_if.<<GLOBAL>>.l_Callback_Status:CSM_E_OK
TEST.END

-- Subprogram: FblHsmFlashPeriodic

-- Test Case: FblHsmFlashPeriodic.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:FblHsmFlashPeriodic
TEST.NEW
TEST.NAME:FblHsmFlashPeriodic.001
TEST.END

-- Subprogram: HSM_Reflash_FBLNotify_callback

-- Test Case: HSM_Reflash_FBLNotify_callback.001
TEST.UNIT:UPD_memdrv_if
TEST.SUBPROGRAM:HSM_Reflash_FBLNotify_callback
TEST.NEW
TEST.NAME:HSM_Reflash_FBLNotify_callback.001
TEST.END

-- Unit: UPDd

-- Subprogram: CUPD_UpdateCdd_Impl_MainFunction

-- Test Case: CUPD_UpdateCdd_Impl_MainFunction.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:CUPD_UpdateCdd_Impl_MainFunction
TEST.NEW
TEST.NAME:CUPD_UpdateCdd_Impl_MainFunction.001
TEST.END

-- Subprogram: CUPD_UpdateCdd_Impl_OnCommand

-- Test Case: CUPD_UpdateCdd_Impl_OnCommand.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:CUPD_UpdateCdd_Impl_OnCommand
TEST.NEW
TEST.NAME:CUPD_UpdateCdd_Impl_OnCommand.001
TEST.END

-- Subprogram: CmpActivation

-- Test Case: CmpActivation.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation.001
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.001
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation.001
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: CmpDeInit.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit.001
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag.001
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn.001
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit.001
TEST.STUB:UPDd.UPDd_AdapterInit
TEST.END

-- Subprogram: UPDd_GetInactiveBank

-- Test Case: UPDd_GetInactiveBank.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:UPDd_GetInactiveBank
TEST.NEW
TEST.NAME:UPDd_GetInactiveBank.001
TEST.VALUE:UPDd.UPDd_GetInactiveBank.this:<<malloc 1>>
TEST.END

-- Subprogram: UPDd_GetInitialIV

-- Test Case: UPDd_GetInitialIV.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:UPDd_GetInitialIV
TEST.NEW
TEST.NAME:UPDd_GetInitialIV.001
TEST.VALUE:UPDd.UPDd_GetInitialIV.IVBufferAddr:<<malloc 17>>
TEST.END

-- Subprogram: UPDi_CheckDependencies

-- Test Case: UPDi_CheckDependencies.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:UPDi_CheckDependencies
TEST.NEW
TEST.NAME:UPDi_CheckDependencies.001
TEST.END

-- Subprogram: UpDdi_GetEraseSize

-- Test Case: UpDdi_GetEraseSize.001
TEST.UNIT:UPDd
TEST.SUBPROGRAM:UpDdi_GetEraseSize
TEST.NEW
TEST.NAME:UpDdi_GetEraseSize.001
TEST.VALUE:UPDd.UpDdi_GetEraseSize.address:0x10000000
TEST.END

-- Test Case: UpDdi_GetEraseSize.002
TEST.UNIT:UPDd
TEST.SUBPROGRAM:UpDdi_GetEraseSize
TEST.NEW
TEST.NAME:UpDdi_GetEraseSize.002
TEST.VALUE:UPDd.UpDdi_GetEraseSize.address:0x103F0000
TEST.END

-- Test Case: UpDdi_GetEraseSize.003
TEST.UNIT:UPDd
TEST.SUBPROGRAM:UpDdi_GetEraseSize
TEST.NEW
TEST.NAME:UpDdi_GetEraseSize.003
TEST.VALUE:UPDd.UpDdi_GetEraseSize.address:0x10048000
TEST.END

-- Test Case: UpDdi_GetEraseSize.004
TEST.UNIT:UPDd
TEST.SUBPROGRAM:UpDdi_GetEraseSize
TEST.NEW
TEST.NAME:UpDdi_GetEraseSize.004
TEST.VALUE:UPDd.UpDdi_GetEraseSize.address:0x60000000
TEST.END
