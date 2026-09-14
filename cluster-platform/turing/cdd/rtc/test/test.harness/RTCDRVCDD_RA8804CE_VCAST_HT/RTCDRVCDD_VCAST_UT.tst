-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RTCDRVCDD_VCAST_UT
-- Unit(s) Under Test: RtcCdd RtcDrvCdd_I2c RtcDrvCdd_RA8804CE RtcIfCdd RtcMgrCdd
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: RtcCdd

-- Subprogram: CRtcCdd_Impl_MainFunction

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:CRtcCdd_Impl_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: CRtcCdd_Impl_OnCommand

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:CRtcCdd_Impl_OnCommand
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:RtcCdd.CRtcCdd_Impl_OnCommand.Cmd:<<MIN>>
TEST.END

-- Subprogram: CmpActivation

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpActive

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
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
TEST.UNIT:RtcCdd
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
TEST.UNIT:RtcCdd
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
TEST.UNIT:RtcCdd
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
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcCdd_AlarmNotification

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:RtcCdd_AlarmNotification
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcCdd_ClearAlarm

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:RtcCdd_ClearAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcCdd_ClearPeriodicAlarm

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:RtcCdd_ClearPeriodicAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcCdd_DisableAlarmNotification

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:RtcCdd_DisableAlarmNotification
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcCdd_EnableAlarmNotification

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:RtcCdd_EnableAlarmNotification
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcCdd_GetTime

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:RtcCdd_GetTime
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((boolean)0U != RtcCdd_ActivationDone) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:RtcCdd.<<GLOBAL>>.RtcCdd_ActivationDone:0
TEST.VALUE:RtcCdd.RtcCdd_GetTime.p_time:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:RtcCdd_GetTime
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((boolean)0U != RtcCdd_ActivationDone) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:RtcCdd.<<GLOBAL>>.RtcCdd_ActivationDone:1
TEST.VALUE:RtcCdd.RtcCdd_GetTime.p_time:<<malloc 1>>
TEST.END

-- Subprogram: RtcCdd_SetAlarm

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:RtcCdd_SetAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((boolean)0U != RtcCdd_ActivationDone) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:RtcCdd.<<GLOBAL>>.RtcCdd_ActivationDone:0
TEST.VALUE:RtcCdd.RtcCdd_SetAlarm.p_alarm:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:RtcCdd_SetAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((boolean)0U != RtcCdd_ActivationDone) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:RtcCdd.<<GLOBAL>>.RtcCdd_ActivationDone:1
TEST.VALUE:RtcCdd.RtcCdd_SetAlarm.p_alarm:<<malloc 1>>
TEST.END

-- Subprogram: RtcCdd_SetPeriodicAlarm

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:RtcCdd_SetPeriodicAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:RtcCdd.RtcCdd_SetPeriodicAlarm.p_alarm:VECTORCAST_INT1
TEST.END

-- Subprogram: RtcCdd_SetTime

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:RtcCdd_SetTime
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((boolean)0U != RtcCdd_ActivationDone) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:RtcCdd.<<GLOBAL>>.RtcCdd_ActivationDone:0
TEST.VALUE:RtcCdd.RtcCdd_SetTime.p_time:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:RtcCdd
TEST.SUBPROGRAM:RtcCdd_SetTime
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((boolean)0U != RtcCdd_ActivationDone) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:RtcCdd.<<GLOBAL>>.RtcCdd_ActivationDone:1
TEST.VALUE:RtcCdd.RtcCdd_SetTime.p_time:<<malloc 1>>
TEST.END

-- Unit: RtcDrvCdd_I2c

-- Subprogram: RtcDrvCdd_i2cCheckIfBufferEmpty

-- Test Case: RtcDrvCdd_i2cCheckIfBufferEmpty.001
TEST.UNIT:RtcDrvCdd_I2c
TEST.SUBPROGRAM:RtcDrvCdd_i2cCheckIfBufferEmpty
TEST.NEW
TEST.NAME:RtcDrvCdd_i2cCheckIfBufferEmpty.001
TEST.END

-- Test Case: RtcDrvCdd_i2cCheckIfBufferEmpty.002
TEST.UNIT:RtcDrvCdd_I2c
TEST.SUBPROGRAM:RtcDrvCdd_i2cCheckIfBufferEmpty
TEST.NEW
TEST.NAME:RtcDrvCdd_i2cCheckIfBufferEmpty.002
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cCheckIfBufferEmpty.pI2c_CB:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cCheckIfBufferEmpty.pI2c_CB[0].u8BufferHead:1
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cCheckIfBufferEmpty.pI2c_CB[0].u8BufferTail:2
TEST.END

-- Subprogram: RtcDrvCdd_i2cProcessCircularBuffer

-- Test Case: RtcDrvCdd_i2cProcessCircularBuffer.001
TEST.UNIT:RtcDrvCdd_I2c
TEST.SUBPROGRAM:RtcDrvCdd_i2cProcessCircularBuffer
TEST.NEW
TEST.NAME:RtcDrvCdd_i2cProcessCircularBuffer.001
TEST.END

-- Test Case: RtcDrvCdd_i2cProcessCircularBuffer.002
TEST.UNIT:RtcDrvCdd_I2c
TEST.SUBPROGRAM:RtcDrvCdd_i2cProcessCircularBuffer
TEST.NEW
TEST.NAME:RtcDrvCdd_i2cProcessCircularBuffer.002
TEST.VALUE:uut_prototype_stubs.I2c_GetStatus.return:1
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB[0].u8BufferHead:0xF
TEST.END

-- Test Case: RtcDrvCdd_i2cProcessCircularBuffer.003
TEST.UNIT:RtcDrvCdd_I2c
TEST.SUBPROGRAM:RtcDrvCdd_i2cProcessCircularBuffer
TEST.NEW
TEST.NAME:RtcDrvCdd_i2cProcessCircularBuffer.003
TEST.VALUE:uut_prototype_stubs.I2c_GetStatus.return:1
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB[0].eSequenceType[15]:eRtcDrvCdd_I2cRead
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB[0].u8BufferHead:0xF
TEST.END

-- Test Case: RtcDrvCdd_i2cProcessCircularBuffer.004
TEST.UNIT:RtcDrvCdd_I2c
TEST.SUBPROGRAM:RtcDrvCdd_i2cProcessCircularBuffer
TEST.NEW
TEST.NAME:RtcDrvCdd_i2cProcessCircularBuffer.004
TEST.VALUE:uut_prototype_stubs.I2c_GetStatus.return:1
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB[0].I2c_TxBuffer[15]:<<malloc 2>>
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB[0].I2c_TxBuffer[15]:"1"
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB[0].eSequenceType[15]:eRtcDrvCdd_I2cRead
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB[0].u8BufferHead:0xF
TEST.END

-- Test Case: RtcDrvCdd_i2cProcessCircularBuffer.005
TEST.UNIT:RtcDrvCdd_I2c
TEST.SUBPROGRAM:RtcDrvCdd_i2cProcessCircularBuffer
TEST.NEW
TEST.NAME:RtcDrvCdd_i2cProcessCircularBuffer.005
TEST.VALUE:uut_prototype_stubs.I2c_AsyncTransmit.return:1
TEST.VALUE:uut_prototype_stubs.I2c_GetStatus.return:1
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB[0].eSequenceType[15]:eRtcDrvCdd_I2cRead
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cProcessCircularBuffer.pI2c_CB[0].u8BufferHead:0xF
TEST.END

-- Subprogram: RtcDrvCdd_i2cReadRegisters

-- Test Case: RtcDrvCdd_i2cReadRegisters.001
TEST.UNIT:RtcDrvCdd_I2c
TEST.SUBPROGRAM:RtcDrvCdd_i2cReadRegisters
TEST.NEW
TEST.NAME:RtcDrvCdd_i2cReadRegisters.001
TEST.END

-- Test Case: RtcDrvCdd_i2cReadRegisters.002
TEST.UNIT:RtcDrvCdd_I2c
TEST.SUBPROGRAM:RtcDrvCdd_i2cReadRegisters
TEST.NEW
TEST.NAME:RtcDrvCdd_i2cReadRegisters.002
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cReadRegisters.pI2c_CB:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cReadRegisters.pI2c_CB[0].u8BufferTail:0x20
TEST.END

-- Subprogram: RtcDrvCdd_i2cWriteRegisters

-- Test Case: RtcDrvCdd_i2cWriteRegisters.001
TEST.UNIT:RtcDrvCdd_I2c
TEST.SUBPROGRAM:RtcDrvCdd_i2cWriteRegisters
TEST.NEW
TEST.NAME:RtcDrvCdd_i2cWriteRegisters.001
TEST.END

-- Test Case: RtcDrvCdd_i2cWriteRegisters.002
TEST.UNIT:RtcDrvCdd_I2c
TEST.SUBPROGRAM:RtcDrvCdd_i2cWriteRegisters
TEST.NEW
TEST.NAME:RtcDrvCdd_i2cWriteRegisters.002
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cWriteRegisters.pI2c_CB:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cWriteRegisters.pI2c_CB[0].u8BufferTail:0x20
TEST.END

-- Unit: RtcDrvCdd_RA8804CE

-- Subprogram: RtcCdd_I2cEndNotification

-- Test Case: RtcCdd_I2cEndNotification.001
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcCdd_I2cEndNotification
TEST.NEW
TEST.NAME:RtcCdd_I2cEndNotification.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcDrvCdd_Activate

-- Test Case: RtcDrvCdd_Activate.001
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_Activate
TEST.NEW
TEST.NAME:RtcDrvCdd_Activate.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcDrvCdd_AlarmInterruptHandler

-- Test Case: RtcDrvCdd_AlarmInterruptHandler.001
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_AlarmInterruptHandler
TEST.NEW
TEST.NAME:RtcDrvCdd_AlarmInterruptHandler.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.I2c_CircularBuffer.I2c_RxBufferBTC[14]:8
TEST.END

-- Test Case: RtcDrvCdd_AlarmInterruptHandler.002
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_AlarmInterruptHandler
TEST.NEW
TEST.NAME:RtcDrvCdd_AlarmInterruptHandler.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.I2c_CircularBuffer.I2c_RxBufferBTC[14]:16
TEST.END

-- Test Case: RtcDrvCdd_AlarmInterruptHandler.003
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_AlarmInterruptHandler
TEST.NEW
TEST.NAME:RtcDrvCdd_AlarmInterruptHandler.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.I2c_CircularBuffer.I2c_RxBufferBTC[14]:32
TEST.END

-- Subprogram: RtcDrvCdd_ClearAlarm

-- Test Case: RtcDrvCdd_ClearAlarm.001
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_ClearAlarm
TEST.NEW
TEST.NAME:RtcDrvCdd_ClearAlarm.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_I2c.RtcDrvCdd_i2cWriteRegisters
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cWriteRegisters.return:1
TEST.END

-- Subprogram: RtcDrvCdd_DeInit

-- Test Case: RtcDrvCdd_DeInit.001
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_DeInit
TEST.NEW
TEST.NAME:RtcDrvCdd_DeInit.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcDrvCdd_GetTime

-- Test Case: RtcDrvCdd_GetTime.001
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_GetTime
TEST.NEW
TEST.NAME:RtcDrvCdd_GetTime.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.END

-- Test Case: RtcDrvCdd_GetTime.002
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_GetTime
TEST.NEW
TEST.NAME:RtcDrvCdd_GetTime.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.I2c_CircularBuffer.I2c_RxBufferBTC[14]:2
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_GetTime.pTimeDate:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_GetTime.return:1
TEST.EXPECTED:RtcDrvCdd_RA8804CE.<<GLOBAL>>.I2c_CircularBuffer.I2c_RxBufferBTC[14]:2
TEST.END

-- Test Case: RtcDrvCdd_GetTime.003
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_GetTime
TEST.NEW
TEST.NAME:RtcDrvCdd_GetTime.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.I2c_CircularBuffer.I2c_RxBufferBTC:<<malloc 2>>
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.I2c_CircularBuffer.I2c_RxBufferBTC:"1"
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.bRTCInitReadFinishedFlag:1
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_GetTime.pTimeDate:<<malloc 1>>
TEST.END

-- Subprogram: RtcDrvCdd_GetWeek

-- Test Case: RtcDrvCdd_GetWeek.001
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_GetWeek
TEST.NEW
TEST.NAME:RtcDrvCdd_GetWeek.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_GetWeek.RxWeek:1
TEST.END

-- Test Case: RtcDrvCdd_GetWeek.002
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_GetWeek
TEST.NEW
TEST.NAME:RtcDrvCdd_GetWeek.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_GetWeek.RxWeek:2
TEST.END

-- Test Case: RtcDrvCdd_GetWeek.003
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_GetWeek
TEST.NEW
TEST.NAME:RtcDrvCdd_GetWeek.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_GetWeek.RxWeek:8
TEST.END

-- Test Case: RtcDrvCdd_GetWeek.004
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_GetWeek
TEST.NEW
TEST.NAME:RtcDrvCdd_GetWeek.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_GetWeek.RxWeek:4
TEST.END

-- Test Case: RtcDrvCdd_GetWeek.005
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_GetWeek
TEST.NEW
TEST.NAME:RtcDrvCdd_GetWeek.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_GetWeek.RxWeek:16
TEST.END

-- Test Case: RtcDrvCdd_GetWeek.006
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_GetWeek
TEST.NEW
TEST.NAME:RtcDrvCdd_GetWeek.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_GetWeek.RxWeek:32
TEST.END

-- Test Case: RtcDrvCdd_GetWeek.007
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_GetWeek
TEST.NEW
TEST.NAME:RtcDrvCdd_GetWeek.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_GetWeek.RxWeek:64
TEST.END

-- Subprogram: RtcDrvCdd_Init

-- Test Case: RtcDrvCdd_Init.001
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_Init
TEST.NEW
TEST.NAME:RtcDrvCdd_Init.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcDrvCdd_MainFunction

-- Test Case: RtcDrvCdd_MainFunction.001
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_MainFunction
TEST.NEW
TEST.NAME:RtcDrvCdd_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.RtcState:eRtcCddInited
TEST.END

-- Test Case: RtcDrvCdd_MainFunction.002
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_MainFunction
TEST.NEW
TEST.NAME:RtcDrvCdd_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_I2c.RtcDrvCdd_i2cCheckIfBufferEmpty
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cCheckIfBufferEmpty.return:1
TEST.END

-- Test Case: RtcDrvCdd_MainFunction.003
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_MainFunction
TEST.NEW
TEST.NAME:RtcDrvCdd_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.RtcState:eRtcCddInited
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.I2c_CircularBuffer.I2c_RxBufferBTC[14]:1
TEST.END

-- Test Case: RtcDrvCdd_MainFunction.004
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_MainFunction
TEST.NEW
TEST.NAME:RtcDrvCdd_MainFunction.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.RtcState:eRtcCddMainRoutine
TEST.END

-- Test Case: RtcDrvCdd_MainFunction.005
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_MainFunction
TEST.NEW
TEST.NAME:RtcDrvCdd_MainFunction.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.RtcState:eRtcCddApplySettings
TEST.END

-- Test Case: RtcDrvCdd_MainFunction.006
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_MainFunction
TEST.NEW
TEST.NAME:RtcDrvCdd_MainFunction.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.RtcState:eRtcCddInterruptsHandling
TEST.END

-- Test Case: RtcDrvCdd_MainFunction.007
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_MainFunction
TEST.NEW
TEST.NAME:RtcDrvCdd_MainFunction.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_RA8804CE.<<GLOBAL>>.RtcState:10
TEST.END

-- Subprogram: RtcDrvCdd_SetAlarm

-- Test Case: RtcDrvCdd_SetAlarm.001
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_SetAlarm
TEST.NEW
TEST.NAME:RtcDrvCdd_SetAlarm.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_I2c.RtcDrvCdd_i2cWriteRegisters
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cWriteRegisters.return:0
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetAlarm.Alarm:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetAlarm.Alarm[0].day:255
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetAlarm.Alarm[0].minute:255
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetAlarm.Alarm[0].hour:255
TEST.END

-- Test Case: RtcDrvCdd_SetAlarm.002
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_SetAlarm
TEST.NEW
TEST.NAME:RtcDrvCdd_SetAlarm.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_I2c.RtcDrvCdd_i2cWriteRegisters
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cWriteRegisters.return:1
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetAlarm.Alarm:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetAlarm.Alarm[0].day:255
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetAlarm.Alarm[0].minute:255
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetAlarm.Alarm[0].hour:255
TEST.END

-- Subprogram: RtcDrvCdd_SetTime

-- Test Case: RtcDrvCdd_SetTime.001
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_SetTime
TEST.NEW
TEST.NAME:RtcDrvCdd_SetTime.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::RtcCdd::RtcCdd_Detailed_Design::RtcCdd_ClassDiagram
Requirement_PE4TI29141-8905
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_I2c.RtcDrvCdd_i2cWriteRegisters
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cWriteRegisters.return:1
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetTime.pTimeDate:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetTime.return:0x1
TEST.END

-- Test Case: RtcDrvCdd_SetTime.002
TEST.UNIT:RtcDrvCdd_RA8804CE
TEST.SUBPROGRAM:RtcDrvCdd_SetTime
TEST.NEW
TEST.NAME:RtcDrvCdd_SetTime.002
TEST.STUB:RtcDrvCdd_I2c.RtcDrvCdd_i2cWriteRegisters
TEST.STUB:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetResetState
TEST.VALUE:RtcDrvCdd_I2c.RtcDrvCdd_i2cWriteRegisters.return:1
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetTime.pTimeDate:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_RA8804CE.RtcDrvCdd_SetResetState.return:0
TEST.END

-- Unit: RtcMgrCdd

-- Subprogram: RtcMgrCdd_AlarmNotification

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_AlarmNotification
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcMgrCdd_ClearAlarm

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_ClearAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcMgrCdd_ClearPeriodicAlarm

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_ClearPeriodicAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcMgrCdd_DeActivation

-- Test Case: RtcMgrCdd_DeActivation.001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_DeActivation
TEST.NEW
TEST.NAME:RtcMgrCdd_DeActivation.001
TEST.END

-- Subprogram: RtcMgrCdd_DeInit

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_DeInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcMgrCdd_DisableAlarmNotification

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_DisableAlarmNotification
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcMgrCdd_EnableAlarmNotification

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_EnableAlarmNotification
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcMgrCdd_GetTime

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_GetTime
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:RtcMgrCdd.RtcMgrCdd_GetTime.p_time:<<malloc 1>>
TEST.END

-- Subprogram: RtcMgrCdd_Init

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_Init
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcMgrCdd_MainFunction

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcMgrCdd_SetAlarm

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_SetAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:RtcMgrCdd.RtcMgrCdd_SetAlarm.p_alarm:<<malloc 1>>
TEST.END

-- Subprogram: RtcMgrCdd_SetPeriodicAlarm

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_SetPeriodicAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcMgrCdd_SetTime

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcMgrCdd
TEST.SUBPROGRAM:RtcMgrCdd_SetTime
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:RtcMgrCdd.RtcMgrCdd_SetTime.p_time:<<malloc 1>>
TEST.END
