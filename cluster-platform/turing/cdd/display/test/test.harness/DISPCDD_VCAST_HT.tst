-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : DISPCDD_VCAST_HT
-- Unit(s) Under Test: DisplayCdd DisplayDrvCdd DisplayI2CDrvCdd DisplayIfCdd DisplayMgrCdd
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: DisplayCdd

-- Subprogram: CDisplayCdd_BistTest_Start

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CDisplayCdd_BistTest_Start
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:DisplayCdd.CDisplayCdd_BistTest_Start.DeviceId:<<MIN>>
TEST.VALUE:DisplayCdd.CDisplayCdd_BistTest_Start.BistPatternType:<<MIN>>
TEST.VALUE:DisplayCdd.CDisplayCdd_BistTest_Start.PatternHoldTime:<<MIN>>
TEST.END

-- Subprogram: CDisplayCdd_BistTest_Stop

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CDisplayCdd_BistTest_Stop
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:DisplayCdd.CDisplayCdd_BistTest_Stop.DeviceId:<<MIN>>
TEST.END

-- Subprogram: CDisplayCdd_GetStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CDisplayCdd_GetStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:DisplayCdd.CDisplayCdd_GetStatus.DeviceId:<<MIN>>
TEST.VALUE:DisplayCdd.CDisplayCdd_GetStatus.DeviceStatus:<<malloc 1>>
TEST.VALUE:DisplayCdd.CDisplayCdd_GetStatus.DevicePowerState:<<malloc 1>>
TEST.END

-- Subprogram: CDisplayCdd_Impl_MainFunction

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CDisplayCdd_Impl_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: CDisplayCdd_Impl_OnCommand

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CDisplayCdd_Impl_OnCommand
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:DisplayCdd.CDisplayCdd_Impl_OnCommand.Cmd:<<MIN>>
TEST.END

-- Subprogram: CDisplayCdd_SetState

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CDisplayCdd_SetState
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:DisplayCdd.CDisplayCdd_SetState.DeviceID:<<MIN>>
TEST.VALUE:DisplayCdd.CDisplayCdd_SetState.PowerState:<<MIN>>
TEST.END

-- Subprogram: CmpActivation

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uint8)1U != DispPreCheckStatus) ==> FALSE
      (4) if (DisplayDetectInfo.DisplayCddInitState == (DisplayStartInit)) ==> FALSE
   Test Case Generation Notes:
      Cannot set DispPreCheckStatus due to assignment
TEST.END_NOTES:
TEST.STUB:DisplayCdd.CDisplayCdd_Impl_MainFunction
TEST.STUB:DisplayCdd.CDisplayCdd_Impl_OnCommand
TEST.STUB:DisplayCdd.CmpInit
TEST.STUB:DisplayCdd.CmpDeInit
TEST.STUB:DisplayCdd.CmpDeActivation
TEST.STUB:DisplayCdd.CmpActive
TEST.STUB:DisplayCdd.CmpDiag
TEST.STUB:DisplayCdd.CmpDiagReturn
TEST.STUB:DisplayCdd.CDisplayCdd_SetState
TEST.STUB:DisplayCdd.CDisplayCdd_GetStatus
TEST.STUB:DisplayCdd.CDisplayCdd_BistTest_Start
TEST.STUB:DisplayCdd.CDisplayCdd_BistTest_Stop
TEST.VALUE:DisplayCdd.<<GLOBAL>>.DisplayDetectInfo.DisplayCddInitState:DisplayInitNotStarted
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)1U != DispPreCheckStatus) ==> FALSE
      (4) if (DisplayDetectInfo.DisplayCddInitState == (DisplayStartInit)) ==> TRUE
   Test Case Generation Notes:
      Cannot set DispPreCheckStatus due to assignment
TEST.END_NOTES:
TEST.VALUE:DisplayCdd.<<GLOBAL>>.DisplayDetectInfo.DisplayCddInitState:DisplayStartInit
TEST.END

-- Test Case: BASIS-PATH-003-TEMPLATE
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:BASIS-PATH-003-TEMPLATE
TEST.BASIS_PATH:3 of 5 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((uint8)1U != DispPreCheckStatus) ==> TRUE
      (2) if (DisplayInitCheck.displayReadNVMDisplayType != (void *)0) ==> FALSE
      (4) if (DisplayDetectInfo.DisplayCddInitState == (DisplayStartInit)) ==> FALSE
   Test Case Generation Notes:
      Cannot set DispPreCheckStatus due to assignment
            Cannot set value of field for a const class/struct/union for DisplayInitCheck.displayReadNVMDisplayType in branch 2
      Cannot set DisplayDetectInfo.DisplayCddInitState due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((uint8)1U != DispPreCheckStatus) ==> TRUE
      (2) if (DisplayInitCheck.displayReadNVMDisplayType != (void *)0) ==> TRUE
      (3) if ((uint8)0xff == DetectedDisplayId || (uint8)1U <= DetectedDisplayId) ==> FALSE
      (4) if (DisplayDetectInfo.DisplayCddInitState == (DisplayStartInit)) ==> FALSE
   Test Case Generation Notes:
      Cannot set DispPreCheckStatus due to assignment
            Cannot set value of field for a const class/struct/union for DisplayInitCheck.displayReadNVMDisplayType in branch 2
      Cannot set DisplayDetectInfo.DisplayCddInitState due to assignment
TEST.END_NOTES:
TEST.VALUE:DisplayCdd.<<GLOBAL>>.DetectedDisplayId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((uint8)1U != DispPreCheckStatus) ==> TRUE
      (2) if (DisplayInitCheck.displayReadNVMDisplayType != (void *)0) ==> TRUE
      (3) if ((uint8)0xff == DetectedDisplayId || (uint8)1U <= DetectedDisplayId) ==> TRUE
      (4) if (DisplayDetectInfo.DisplayCddInitState == (DisplayStartInit)) ==> FALSE
   Test Case Generation Notes:
      Cannot set DispPreCheckStatus due to assignment
            Cannot set value of field for a const class/struct/union for DisplayInitCheck.displayReadNVMDisplayType in branch 2
      Cannot set DisplayDetectInfo.DisplayCddInitState due to assignment
TEST.END_NOTES:
TEST.VALUE:DisplayCdd.<<GLOBAL>>.DetectedDisplayId:255
TEST.END

-- Subprogram: CmpActive

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (DisplayDetectInfo.DisplayCddInitState == (DisplayInitCompleted)) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayCdd.<<GLOBAL>>.DisplayDetectInfo.DisplayCddInitState:DisplayInitNotStarted
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (DisplayDetectInfo.DisplayCddInitState == (DisplayInitCompleted)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayCdd.<<GLOBAL>>.DisplayDetectInfo.DisplayCddInitState:DisplayInitCompleted
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpDiag

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpInit

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayCdd
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Unit: DisplayDrvCdd

-- Subprogram: DisplayDetectI2CMethod

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDetectI2CMethod
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (currentDisplayCheck < (uint8)1U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.currentDisplayCheck:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDetectI2CMethod
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (currentDisplayCheck < (uint8)1U) ==> TRUE
      (2) if (DispI2cRetryCount != 0U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.currentDisplayCheck:<<MIN>>
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.DispI2cRetryCount:0
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDetectI2CMethod
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (currentDisplayCheck < (uint8)1U) ==> TRUE
      (2) if (DispI2cRetryCount != 0U) ==> TRUE
      (3) if ((uint8)0U == displayi2cstatus && (uint8)1U > (DisplayCheckConfig[currentDisplayCheck]).displayType) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.currentDisplayCheck:<<MIN>>
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.DispI2cRetryCount:1
TEST.VALUE:DisplayDrvCdd.DisplayDrvI2CSendDetect.return:1
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDetectI2CMethod
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (currentDisplayCheck < (uint8)1U) ==> TRUE
      (2) if (DispI2cRetryCount != 0U) ==> TRUE
      (3) if ((uint8)0U == displayi2cstatus && (uint8)1U > (DisplayCheckConfig[currentDisplayCheck]).displayType) ==> TRUE
      (4) if (DisplayInitCheck.displayWriteNVMDisplayType != (void *)0) ==> FALSE
   Test Case Generation Notes:
            Cannot set value of field for a const class/struct/union for (DisplayCheckConfig[currentDisplayCheck]).displayType in branch 3
            Cannot set value of field for a const class/struct/union for DisplayInitCheck.displayWriteNVMDisplayType in branch 4
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.currentDisplayCheck:<<MIN>>
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.DispI2cRetryCount:1
TEST.VALUE:DisplayDrvCdd.DisplayDrvI2CSendDetect.return:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDetectI2CMethod
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (currentDisplayCheck < (uint8)1U) ==> TRUE
      (2) if (DispI2cRetryCount != 0U) ==> TRUE
      (3) if ((uint8)0U == displayi2cstatus && (uint8)1U > (DisplayCheckConfig[currentDisplayCheck]).displayType) ==> TRUE
      (4) if (DisplayInitCheck.displayWriteNVMDisplayType != (void *)0) ==> TRUE
   Test Case Generation Notes:
            Cannot set value of field for a const class/struct/union for (DisplayCheckConfig[currentDisplayCheck]).displayType in branch 3
            Cannot set value of field for a const class/struct/union for DisplayInitCheck.displayWriteNVMDisplayType in branch 4
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.currentDisplayCheck:<<MIN>>
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.DispI2cRetryCount:1
TEST.VALUE:DisplayDrvCdd.DisplayDrvI2CSendDetect.return:0
TEST.END

-- Subprogram: DisplayDrvCdd_BistTest_Start

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_BistTest_Start
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_BistTest_Start.DeviceId:<<MIN>>
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_BistTest_Start.BistPatternType:<<MIN>>
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_BistTest_Start.PatternHoldTime:<<MIN>>
TEST.END

-- Subprogram: DisplayDrvCdd_BistTest_Stop

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_BistTest_Stop
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_BistTest_Stop.DeviceId:<<MIN>>
TEST.END

-- Subprogram: DisplayDrvCdd_DeInit

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_DeInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uint8)1U > Device_No) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_DeInit.Device_No:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_DeInit
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)1U > Device_No) ==> TRUE
      (2) if ((DisplayCdd_DeInit[Device_No]).Drv_DeInit != (void *)0) ==> FALSE
   Test Case Generation Notes:
            Cannot set value of field for a const class/struct/union for (DisplayCdd_DeInit[Device_No]).Drv_DeInit in branch 2
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_DeInit.Device_No:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_DeInit
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((uint8)1U > Device_No) ==> TRUE
      (2) if ((DisplayCdd_DeInit[Device_No]).Drv_DeInit != (void *)0) ==> TRUE
   Test Case Generation Notes:
            Cannot set value of field for a const class/struct/union for (DisplayCdd_DeInit[Device_No]).Drv_DeInit in branch 2
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_DeInit.Device_No:<<MIN>>
TEST.END

-- Subprogram: DisplayDrvCdd_Init

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_Init
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uint8)1U > Device_No) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_Init.Device_No:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_Init
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)1U > Device_No) ==> TRUE
      (2) if ((DisplayCdd_Init[Device_No]).Drv_Init != (void *)0) ==> FALSE
   Test Case Generation Notes:
            Cannot set value of field for a const class/struct/union for (DisplayCdd_Init[Device_No]).Drv_Init in branch 2
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_Init.Device_No:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_Init
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((uint8)1U > Device_No) ==> TRUE
      (2) if ((DisplayCdd_Init[Device_No]).Drv_Init != (void *)0) ==> TRUE
   Test Case Generation Notes:
            Cannot set value of field for a const class/struct/union for (DisplayCdd_Init[Device_No]).Drv_Init in branch 2
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_Init.Device_No:<<MIN>>
TEST.END

-- Subprogram: DisplayDrvCdd_MainFunction

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uint8)1U > Device_No) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_MainFunction.Device_No:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)1U > Device_No) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_MainFunction.Device_No:<<MIN>>
TEST.END

-- Subprogram: DisplayDrvCdd_SetState

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_SetState
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uint8)1U > DeviceId) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_SetState.DeviceId:<<MAX>>
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_SetState.NewPowerState:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_SetState
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)1U > DeviceId) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_SetState.DeviceId:<<MIN>>
TEST.VALUE:DisplayDrvCdd.DisplayDrvCdd_SetState.NewPowerState:<<MIN>>
TEST.END

-- Subprogram: DisplayDrvI2CSendDetect

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvI2CSendDetect
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (6) case displayCheckState ==> default
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.displayCheckState:2
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvI2CSendDetect
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) case displayCheckState ==> SEND_COMMAND
      (2) if ((uint8)0U == Result) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.DisplayDrvCdd_I2C_Write.return:1
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.displayCheckState:SEND_COMMAND
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvI2CSendDetect
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) case displayCheckState ==> SEND_COMMAND
      (2) if ((uint8)0U == Result) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.DisplayDrvCdd_I2C_Write.return:0
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.displayCheckState:SEND_COMMAND
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvI2CSendDetect
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (3) case displayCheckState ==> WAIT_ACKNOWLEDGE
      (4) if (1U == I2cStatus) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.I2c_GetStatus.return:<<MIN>>
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.displayCheckState:WAIT_ACKNOWLEDGE
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvI2CSendDetect
TEST.NEW
TEST.NAME:BASIS-PATH-005
TEST.BASIS_PATH:5 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (3) case displayCheckState ==> WAIT_ACKNOWLEDGE
      (4) if (1U == I2cStatus) ==> TRUE
      (5) if (0U == resAcknowledge) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.I2c_GetStatus.return:1
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.return:1
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.displayCheckState:WAIT_ACKNOWLEDGE
TEST.END

-- Test Case: BASIS-PATH-006
TEST.UNIT:DisplayDrvCdd
TEST.SUBPROGRAM:DisplayDrvI2CSendDetect
TEST.NEW
TEST.NAME:BASIS-PATH-006
TEST.BASIS_PATH:6 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (3) case displayCheckState ==> WAIT_ACKNOWLEDGE
      (4) if (1U == I2cStatus) ==> TRUE
      (5) if (0U == resAcknowledge) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.I2c_GetStatus.return:1
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.return:0
TEST.VALUE:DisplayDrvCdd.<<GLOBAL>>.displayCheckState:WAIT_ACKNOWLEDGE
TEST.END

-- Unit: DisplayI2CDrvCdd

-- Subprogram: DisplayDrvCdd_I2cSeqEndCallback

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayI2CDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_I2cSeqEndCallback
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: DisplayDrvCdd_I2cSeqErrorCallback

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayI2CDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_I2cSeqErrorCallback
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (I2CTrigerDeviceId < (uint8)1U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayI2CDrvCdd.<<GLOBAL>>.I2CTrigerDeviceId:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:DisplayI2CDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_I2cSeqErrorCallback
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (I2CTrigerDeviceId < (uint8)1U) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayI2CDrvCdd.<<GLOBAL>>.I2CTrigerDeviceId:<<MIN>>
TEST.END

-- Subprogram: DisplayDrvCdd_I2cWrite

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayI2CDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_I2cWrite
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 != I2c_TxBufferPtr && TxLength > 0U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.RegAddr:<<MIN>>
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.I2c_TxBufferPtr:<<malloc 9>>
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.I2c_TxBufferPtr:<<null>>
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.TxLength:<<MIN>>
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.TriggeredDevice:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:DisplayI2CDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_I2cWrite
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((void *)0 != I2c_TxBufferPtr && TxLength > 0U) ==> TRUE
      (2) for (index < TxLength) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.TxLength 'less than' and 'greater than' same value in branches 1/2
TEST.END_NOTES:
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.RegAddr:<<MIN>>
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.I2c_TxBufferPtr:<<malloc 1>>
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.TxLength:0
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.TriggeredDevice:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:DisplayI2CDrvCdd
TEST.SUBPROGRAM:DisplayDrvCdd_I2cWrite
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 != I2c_TxBufferPtr && TxLength > 0U) ==> TRUE
      (2) for (index < TxLength) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.RegAddr:<<MIN>>
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.I2c_TxBufferPtr:<<malloc 1>>
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.TxLength:1
TEST.VALUE:DisplayI2CDrvCdd.DisplayDrvCdd_I2cWrite.TriggeredDevice:<<MIN>>
TEST.END

-- Unit: DisplayIfCdd

-- Subprogram: DispIfCdd_BistTest_Start

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DispIfCdd_BistTest_Start
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.DispIfCdd_BistTest_Start.DeviceId:<<MIN>>
TEST.VALUE:DisplayIfCdd.DispIfCdd_BistTest_Start.BistPatternType:<<MIN>>
TEST.VALUE:DisplayIfCdd.DispIfCdd_BistTest_Start.PatternHoldTime:<<MIN>>
TEST.END

-- Subprogram: DispIfCdd_BistTest_Stop

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DispIfCdd_BistTest_Stop
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.DispIfCdd_BistTest_Stop.DeviceId:<<MIN>>
TEST.END

-- Subprogram: DispIfCdd_GetDisplayStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DispIfCdd_GetDisplayStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uint8)1U > DeviceId) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.DispIfCdd_GetDisplayStatus.DeviceId:<<MAX>>
TEST.VALUE:DisplayIfCdd.DispIfCdd_GetDisplayStatus.GetDeviceStatus:<<malloc 1>>
TEST.VALUE:DisplayIfCdd.DispIfCdd_GetDisplayStatus.GetPresentPowerState:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DispIfCdd_GetDisplayStatus
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)1U > DeviceId) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.DispIfCdd_GetDisplayStatus.DeviceId:<<MIN>>
TEST.VALUE:DisplayIfCdd.DispIfCdd_GetDisplayStatus.GetDeviceStatus:<<malloc 1>>
TEST.VALUE:DisplayIfCdd.DispIfCdd_GetDisplayStatus.GetPresentPowerState:<<malloc 1>>
TEST.END

-- Subprogram: DispIfCdd_UpdateDisplayStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DispIfCdd_UpdateDisplayStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uint8)1U > DeviceIndex) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.DispIfCdd_UpdateDisplayStatus.DeviceIndex:<<MAX>>
TEST.VALUE:DisplayIfCdd.DispIfCdd_UpdateDisplayStatus.CompletedPowerState:<<MIN>>
TEST.VALUE:DisplayIfCdd.DispIfCdd_UpdateDisplayStatus.Devicestatus:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DispIfCdd_UpdateDisplayStatus
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)1U > DeviceIndex) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.DispIfCdd_UpdateDisplayStatus.DeviceIndex:<<MIN>>
TEST.VALUE:DisplayIfCdd.DispIfCdd_UpdateDisplayStatus.CompletedPowerState:<<MIN>>
TEST.VALUE:DisplayIfCdd.DispIfCdd_UpdateDisplayStatus.Devicestatus:<<MIN>>
TEST.END

-- Subprogram: DisplayIfCdd_DeInit

-- Test Case: BASIS-PATH-001-TEMPLATE
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_DeInit
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE
TEST.BASIS_PATH:1 of 2 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (Device_No < (uint8)1U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002-TEMPLATE
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_DeInit
TEST.NEW
TEST.NAME:BASIS-PATH-002-TEMPLATE
TEST.BASIS_PATH:2 of 2 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (Device_No < (uint8)1U) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.END

-- Subprogram: DisplayIfCdd_Init

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_Init
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != DisplayIfCddDetectInfo.IdentifiedDeviceStatus && (uint8)1U > DisplayIfCddDetectInfo.IdentifiedDeviceID) ==> FALSE
      (2) for (Device_No < (uint8)1U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 2
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.IdentifiedDeviceStatus:0
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.IdentifiedDeviceID:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_Init
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U != DisplayIfCddDetectInfo.IdentifiedDeviceStatus && (uint8)1U > DisplayIfCddDetectInfo.IdentifiedDeviceID) ==> FALSE
      (2) for (Device_No < (uint8)1U) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 2
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.IdentifiedDeviceStatus:0
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.IdentifiedDeviceID:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_Init
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (0U != DisplayIfCddDetectInfo.IdentifiedDeviceStatus && (uint8)1U > DisplayIfCddDetectInfo.IdentifiedDeviceID) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.IdentifiedDeviceStatus:1
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.IdentifiedDeviceID:<<MIN>>
TEST.END

-- Subprogram: DisplayIfCdd_MainFunction

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled) ==> FALSE
      (5) for (Device_No < (uint8)1U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 5
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled:0
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U != DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled) ==> FALSE
      (5) for (Device_No < (uint8)1U) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 5
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled:0
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (0U != DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled) ==> TRUE
      (2) if (0U != DisplayIfCddDetectInfo.IdentifiedDeviceStatus) ==> FALSE
      (3) if (1U == DisplayInitCheck.DisplayDetectMethod) ==> FALSE
      (4) if (0U == DisplayInitCheck.DisplayDetectMethod) ==> FALSE
   Test Case Generation Notes:
            Cannot set value of field for a const class/struct/union for DisplayInitCheck.DisplayDetectMethod in branch 3
            Cannot set value of field for a const class/struct/union for DisplayInitCheck.DisplayDetectMethod in branch 4
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled:1
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.IdentifiedDeviceStatus:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (0U != DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled) ==> TRUE
      (2) if (0U != DisplayIfCddDetectInfo.IdentifiedDeviceStatus) ==> FALSE
      (3) if (1U == DisplayInitCheck.DisplayDetectMethod) ==> FALSE
      (4) if (0U == DisplayInitCheck.DisplayDetectMethod) ==> TRUE
   Test Case Generation Notes:
            Cannot set value of field for a const class/struct/union for DisplayInitCheck.DisplayDetectMethod in branch 3
            Cannot set value of field for a const class/struct/union for DisplayInitCheck.DisplayDetectMethod in branch 4
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled:1
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.IdentifiedDeviceStatus:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (0U != DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled) ==> TRUE
      (2) if (0U != DisplayIfCddDetectInfo.IdentifiedDeviceStatus) ==> FALSE
      (3) if (1U == DisplayInitCheck.DisplayDetectMethod) ==> TRUE
   Test Case Generation Notes:
            Cannot set value of field for a const class/struct/union for DisplayInitCheck.DisplayDetectMethod in branch 3
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled:1
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.IdentifiedDeviceStatus:0
TEST.END

-- Test Case: BASIS-PATH-006
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-006
TEST.BASIS_PATH:6 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (0U != DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled) ==> TRUE
      (2) if (0U != DisplayIfCddDetectInfo.IdentifiedDeviceStatus) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled:1
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.IdentifiedDeviceStatus:1
TEST.END

-- Subprogram: DisplayIfCdd_SetState

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_SetState
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((NewState > 0U && NewState < 5U) && (uint8)1U > DeviceId) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.DisplayIfCdd_SetState.DeviceId:2
TEST.VALUE:DisplayIfCdd.DisplayIfCdd_SetState.NewState:6
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_SetState
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((NewState > 0U && NewState < 5U) && (uint8)1U > DeviceId) ==> TRUE
      (2) if (2U != (DisplayInfoTable[DeviceId]).DeviceStatus && NewState != (DisplayInfoTable[DeviceId]).DevicePowerState) ==> FALSE
   Test Case Generation Notes:
      Conflict: Cannot resolve multiple comparisons ( DisplayIfCdd.DisplayIfCdd_SetState.DeviceId ) in branches 1/2
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayInfoTable[0].DeviceStatus:2
TEST.VALUE:DisplayIfCdd.DisplayIfCdd_SetState.DeviceId:<<MIN>>
TEST.VALUE:DisplayIfCdd.DisplayIfCdd_SetState.NewState:1
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_SetState
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((NewState > 0U && NewState < 5U) && (uint8)1U > DeviceId) ==> TRUE
      (2) if (2U != (DisplayInfoTable[DeviceId]).DeviceStatus && NewState != (DisplayInfoTable[DeviceId]).DevicePowerState) ==> TRUE
      (3) if (1U == NewState || 3U == NewState) ==> FALSE
   Test Case Generation Notes:
      Conflict: Cannot resolve multiple comparisons ( DisplayIfCdd.DisplayIfCdd_SetState.DeviceId ) in branches 1/2
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayInfoTable[0].DeviceStatus:<<MIN>>
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayInfoTable[0].DevicePowerState:<<MIN>>
TEST.VALUE:DisplayIfCdd.DisplayIfCdd_SetState.DeviceId:<<MIN>>
TEST.VALUE:DisplayIfCdd.DisplayIfCdd_SetState.NewState:2
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_SetState
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((NewState > 0U && NewState < 5U) && (uint8)1U > DeviceId) ==> TRUE
      (2) if (2U != (DisplayInfoTable[DeviceId]).DeviceStatus && NewState != (DisplayInfoTable[DeviceId]).DevicePowerState) ==> TRUE
      (3) if (1U == NewState || 3U == NewState) ==> TRUE
   Test Case Generation Notes:
      Conflict: Cannot resolve multiple comparisons ( DisplayIfCdd.DisplayIfCdd_SetState.DeviceId ) in branches 1/2
      Conflict: Cannot resolve multiple comparisons ( DisplayIfCdd.DisplayIfCdd_SetState.NewState ) in branches 2/3
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayInfoTable[0].DeviceStatus:<<MIN>>
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayInfoTable[0].DevicePowerState:1
TEST.VALUE:DisplayIfCdd.DisplayIfCdd_SetState.DeviceId:2
TEST.VALUE:DisplayIfCdd.DisplayIfCdd_SetState.NewState:<<MIN>>
TEST.END

-- Subprogram: DisplayIfCdd_UpdateAutoDetect

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_UpdateAutoDetect
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((DisplayStartInit) == DisplayIfCddDetectInfo.DisplayCddInitState) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.DisplayCddInitState:DisplayInitNotStarted
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_UpdateAutoDetect
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((DisplayStartInit) == DisplayIfCddDetectInfo.DisplayCddInitState) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.<<GLOBAL>>.DisplayIfCddDetectInfo.DisplayCddInitState:DisplayStartInit
TEST.END

-- Subprogram: DisplayIfCdd_UpdateIdentifiedDeviceStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_UpdateIdentifiedDeviceStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (IdentifiedDeviceID < (uint8)1U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.DisplayIfCdd_UpdateIdentifiedDeviceStatus.IdentifiedDeviceID:<<MAX>>
TEST.VALUE:DisplayIfCdd.DisplayIfCdd_UpdateIdentifiedDeviceStatus.IdentifiedDevStatus:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:DisplayIfCdd
TEST.SUBPROGRAM:DisplayIfCdd_UpdateIdentifiedDeviceStatus
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (IdentifiedDeviceID < (uint8)1U) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayIfCdd.DisplayIfCdd_UpdateIdentifiedDeviceStatus.IdentifiedDeviceID:<<MIN>>
TEST.VALUE:DisplayIfCdd.DisplayIfCdd_UpdateIdentifiedDeviceStatus.IdentifiedDevStatus:<<MIN>>
TEST.END

-- Unit: DisplayMgrCdd

-- Subprogram: DispMgrCdd_GetDisplayStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayMgrCdd
TEST.SUBPROGRAM:DispMgrCdd_GetDisplayStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uint8)1U > DeviceId) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayMgrCdd.DispMgrCdd_GetDisplayStatus.DeviceId:<<MAX>>
TEST.VALUE:DisplayMgrCdd.DispMgrCdd_GetDisplayStatus.DeviceStatus:<<malloc 1>>
TEST.VALUE:DisplayMgrCdd.DispMgrCdd_GetDisplayStatus.GetPresentPowerState:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:DisplayMgrCdd
TEST.SUBPROGRAM:DispMgrCdd_GetDisplayStatus
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)1U > DeviceId) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayMgrCdd.DispMgrCdd_GetDisplayStatus.DeviceId:<<MIN>>
TEST.VALUE:DisplayMgrCdd.DispMgrCdd_GetDisplayStatus.DeviceStatus:<<malloc 1>>
TEST.VALUE:DisplayMgrCdd.DispMgrCdd_GetDisplayStatus.GetPresentPowerState:<<malloc 1>>
TEST.END

-- Subprogram: DisplayMgrCdd_BistTest_Start

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayMgrCdd
TEST.SUBPROGRAM:DisplayMgrCdd_BistTest_Start
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:DisplayMgrCdd.DisplayMgrCdd_BistTest_Start.DeviceId:<<MIN>>
TEST.VALUE:DisplayMgrCdd.DisplayMgrCdd_BistTest_Start.BistPatternType:<<MIN>>
TEST.VALUE:DisplayMgrCdd.DisplayMgrCdd_BistTest_Start.PatternHoldTime:<<MIN>>
TEST.END

-- Subprogram: DisplayMgrCdd_BistTest_Stop

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayMgrCdd
TEST.SUBPROGRAM:DisplayMgrCdd_BistTest_Stop
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:DisplayMgrCdd.DisplayMgrCdd_BistTest_Stop.DeviceId:<<MIN>>
TEST.END

-- Subprogram: DisplayMgrCdd_DeInit

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayMgrCdd
TEST.SUBPROGRAM:DisplayMgrCdd_DeInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: DisplayMgrCdd_Init

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayMgrCdd
TEST.SUBPROGRAM:DisplayMgrCdd_Init
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: DisplayMgrCdd_MainFunction

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayMgrCdd
TEST.SUBPROGRAM:DisplayMgrCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: DisplayMgrCdd_SetState

-- Test Case: BASIS-PATH-001
TEST.UNIT:DisplayMgrCdd
TEST.SUBPROGRAM:DisplayMgrCdd_SetState
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uint8)1U > DeviceId) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayMgrCdd.DisplayMgrCdd_SetState.DeviceId:<<MAX>>
TEST.VALUE:DisplayMgrCdd.DisplayMgrCdd_SetState.NewState:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:DisplayMgrCdd
TEST.SUBPROGRAM:DisplayMgrCdd_SetState
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)1U > DeviceId) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:DisplayMgrCdd.DisplayMgrCdd_SetState.DeviceId:<<MIN>>
TEST.VALUE:DisplayMgrCdd.DisplayMgrCdd_SetState.NewState:<<MIN>>
TEST.END
