-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : TI_I2CDRV
-- Unit(s) Under Test: I2c
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: I2c

-- Subprogram: Client_I2CCbAck_temp

-- Test Case: Client_I2CCbAck_temp.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:Client_I2CCbAck_temp
TEST.NEW
TEST.NAME:Client_I2CCbAck_temp.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.END

-- Subprogram: Client_I2CCbJobEnd_temp

-- Test Case: Client_I2CCbJobEnd_temp.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:Client_I2CCbJobEnd_temp
TEST.NEW
TEST.NAME:Client_I2CCbJobEnd_temp.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.END

-- Subprogram: Client_I2CCbRead_temp1

-- Test Case: Client_I2CCbRead_temp1.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:Client_I2CCbRead_temp1
TEST.NEW
TEST.NAME:Client_I2CCbRead_temp1.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.END

-- Subprogram: Client_I2CCbWrite_temp

-- Test Case: Client_I2CCbWrite_temp.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:Client_I2CCbWrite_temp
TEST.NEW
TEST.NAME:Client_I2CCbWrite_temp.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.END

-- Subprogram: DiffCalculationFunction

-- Test Case: DiffCalculationFunction.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:DiffCalculationFunction
TEST.NEW
TEST.NAME:DiffCalculationFunction.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.END

-- Test Case: DiffCalculationFunction.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:DiffCalculationFunction
TEST.NEW
TEST.NAME:DiffCalculationFunction.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.DiffCalculationFunction.StartValue:55
TEST.VALUE:I2c.DiffCalculationFunction.EndValue:1
TEST.VALUE:I2c.DiffCalculationFunction.return:0
TEST.END

-- Subprogram: I2CControllerIntClearEx

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2CControllerIntClearEx
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2CControllerIntClearEx.baseAddr:<<malloc 1>>
TEST.VALUE:I2c.I2CControllerIntClearEx.intFlag:<<MIN>>
TEST.END

-- Subprogram: I2CControllerIntDisableEx

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2CControllerIntDisableEx
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2CControllerIntDisableEx.baseAddr:<<malloc 1>>
TEST.VALUE:I2c.I2CControllerIntDisableEx.intFlag:<<MIN>>
TEST.END

-- Subprogram: I2CControllerIntEnableEx

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2CControllerIntEnableEx
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2CControllerIntEnableEx.baseAddr:<<malloc 1>>
TEST.VALUE:I2c.I2CControllerIntEnableEx.intFlag:<<MIN>>
TEST.END

-- Subprogram: I2CDataCountGet

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2CDataCountGet
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2CDataCountGet.base:<<malloc 1>>
TEST.END

-- Subprogram: I2CDataCountSet

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2CDataCountSet
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2CDataCountSet.base:<<malloc 1>>
TEST.VALUE:I2c.I2CDataCountSet.Sequence:<<MIN>>
TEST.END

-- Subprogram: I2C_GetBufferStatus

-- Test Case: I2C_GetBufferStatus.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2C_GetBufferStatus
TEST.NEW
TEST.NAME:I2C_GetBufferStatus.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2C_GetBufferStatus.base:<<malloc 1>>
TEST.VALUE:I2c.I2C_GetBufferStatus.base[0].BUFSTAT_reg.BUFSTAT_field.u6TXSTAT:1
TEST.VALUE:I2c.I2C_GetBufferStatus.return:0
TEST.END

-- Subprogram: I2C_GetStatusOfSDALine

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2C_GetStatusOfSDALine
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 1
      (1) if (4U > hw) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:I2c.I2C_GetStatusOfSDALine.hw:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2C_GetStatusOfSDALine
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 2
      (1) if (4U > hw) ==> TRUE
      (2) for (index < 2U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
TEST.END_NOTES:
TEST.VALUE:I2c.I2C_GetStatusOfSDALine.hw:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-TEMPLATE
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2C_GetStatusOfSDALine
TEST.NEW
TEST.NAME:BASIS-PATH-003-TEMPLATE
TEST.BASIS_PATH:3 of 5 (template)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 3
      (1) if (4U > hw) ==> TRUE
      (2) for (index < 2U) ==> TRUE
      (3) if (((I2C_BusFreeConf)[index]).HwUnit == hw) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set index due to assignment
      Conflict: Cannot resolve multiple comparisons ( I2c.I2C_GetStatusOfSDALine.hw ) in branches 1/3
TEST.END_NOTES:
TEST.VALUE:I2c.I2C_GetStatusOfSDALine.hw:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2C_GetStatusOfSDALine
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 4
      (1) if (4U > hw) ==> TRUE
      (2) for (index < 2U) ==> TRUE
      (3) if (((I2C_BusFreeConf)[index]).HwUnit == hw) ==> TRUE
      (4) if (Dio_ReadChannel(I2C_PortPin_SDA) == 0U && Dio_ReadChannel(I2C_PortPin_SCL) == 0x1U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set index due to assignment
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2C_BusFreeConf[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2C_GetStatusOfSDALine.hw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Dio_ReadChannel.return:2
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2C_GetStatusOfSDALine
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 5
      (1) if (4U > hw) ==> TRUE
      (2) for (index < 2U) ==> TRUE
      (3) if (((I2C_BusFreeConf)[index]).HwUnit == hw) ==> TRUE
      (4) if (Dio_ReadChannel(I2C_PortPin_SDA) == 0U && Dio_ReadChannel(I2C_PortPin_SCL) == 0x1U) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set index due to assignment
      Conflict: Multiple equality operators with different values (uut_prototype_stubs.Dio_ReadChannel.return) in branch 4
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2C_BusFreeConf[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2C_GetStatusOfSDALine.hw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Dio_ReadChannel.return:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2C_GetStatusOfSDALine
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 5
      (1) if (4U > hw) ==> TRUE
      (2) for (index < 2U) ==> TRUE
      (3) if (((I2C_BusFreeConf)[index]).HwUnit == hw) ==> TRUE
      (4) if (Dio_ReadChannel(I2C_PortPin_SDA) == 0U && Dio_ReadChannel(I2C_PortPin_SCL) == 0x1U) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set index due to assignment
      Conflict: Multiple equality operators with different values (uut_prototype_stubs.Dio_ReadChannel.return) in branch 4
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2C_BusFreeConf[0].HwUnit:3
TEST.VALUE:I2c.I2C_GetStatusOfSDALine.hw:3
TEST.VALUE:uut_prototype_stubs.Dio_ReadChannel.return:0
TEST.END

-- Subprogram: I2C_RxDataCountSet

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2C_RxDataCountSet
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2C_RxDataCountSet.base:<<malloc 1>>
TEST.VALUE:I2c.I2C_RxDataCountSet.Sequence:<<MIN>>
TEST.END

-- Subprogram: I2C_RxGetBufferStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2C_RxGetBufferStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2C_RxGetBufferStatus.base:<<malloc 1>>
TEST.END

-- Subprogram: I2C_SetDataRate

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2C_SetDataRate
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2C_SetDataRate.Sequence:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2C_SetDataRate
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].TransferMode:I2C_STANDARD_MODE
TEST.VALUE:I2c.I2C_SetDataRate.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2C_SetDataRate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].TransferMode:I2C_HIGHSPEED_MODE
TEST.VALUE:I2c.I2C_SetDataRate.Sequence:<<MIN>>
TEST.END

-- Subprogram: I2c_AsyncTransmit

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 13
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-003-Failcaseforse
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-003-Failcaseforse
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].SeqPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].TransferMode:I2C_STANDARD_MODE
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:5
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 13 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].SeqPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].TransferMode:I2C_STANDARD_MODE
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-003-hwfail
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-003-hwfail
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].SeqPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:5
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].TransferMode:I2C_STANDARD_MODE
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 13 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-004_EndNotification
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-004_EndNotification
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:100
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:5
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[1].WholeNetworkStatus:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 13 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.VALUE_USER_CODE:I2c.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<I2c.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 13 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-007
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-007
TEST.BASIS_PATH:7 of 13
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 13 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 13 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.VALUE_USER_CODE:I2c.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<I2c.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-010-PARTIA.endnot
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIA.endnot
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.VALUE_USER_CODE:I2c.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<I2c.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 13 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL
TEST.BASIS_PATH:11 of 13 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-012
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-012
TEST.BASIS_PATH:12 of 13
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-013
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-013
TEST.BASIS_PATH:13 of 13
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-013.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-013.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"2"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:0
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: I2c_AsyncTransmit.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.I2c_AsyncTransmit.Sequence:0
TEST.END

-- Test Case: I2c_AsyncTransmit.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.END

-- Test Case: I2c_AsyncTransmit.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.END

-- Test Case: I2c_AsyncTransmit.004
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.004
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.END

-- Test Case: I2c_AsyncTransmit.005
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.005
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.END

-- Test Case: I2c_AsyncTransmit.006
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.006
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:0
TEST.END

-- Test Case: I2c_AsyncTransmit.007
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.007
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.END

-- Test Case: I2c_AsyncTransmit.008
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.008
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.END

-- Test Case: I2c_AsyncTransmit.009
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.009
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.END

-- Test Case: I2c_AsyncTransmit.010
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.010
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.END

-- Test Case: I2c_AsyncTransmit.011
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.011
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.END

-- Test Case: I2c_AsyncTransmit.012
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.012
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE_USER_CODE:I2c.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<I2c.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: I2c_AsyncTransmit.013
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.013
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE_USER_CODE:I2c.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<I2c.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: I2c_AsyncTransmit.014
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_AsyncTransmit
TEST.NEW
TEST.NAME:I2c_AsyncTransmit.014
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:2
TEST.VALUE_USER_CODE:I2c.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<I2c.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: I2c_Cancel

-- Test Case: I2c_Cancel.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Cancel
TEST.NEW
TEST.NAME:I2c_Cancel.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.END

-- Test Case: I2c_Cancel.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Cancel
TEST.NEW
TEST.NAME:I2c_Cancel.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_Cancel.Sequence:5
TEST.END

-- Test Case: I2c_Cancel.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Cancel
TEST.NEW
TEST.NAME:I2c_Cancel.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:2
TEST.VALUE:I2c.I2c_Cancel.Sequence:0
TEST.END

-- Subprogram: I2c_DeInit

-- Test Case: I2c_DeInit.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_DeInit
TEST.NEW
TEST.NAME:I2c_DeInit.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2c_HwDeInit
TEST.END

-- Subprogram: I2c_Disable

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Disable
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 7
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 1
      (1) if (HwUnitIndex < 4U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_Disable.HwUnitIndex:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Disable
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 2
      (1) if (HwUnitIndex < 4U) ==> TRUE
      (2) if ((I2c_DrvStatus.Status)[HwUnitIndex] != 3U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Cannot resolve multiple comparisons ( I2c.I2c_Disable.HwUnitIndex ) in branches 1/2
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:3
TEST.VALUE:I2c.I2c_Disable.HwUnitIndex:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Disable
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 4
      (1) if (HwUnitIndex < 4U) ==> TRUE
      (2) if ((I2c_DrvStatus.Status)[HwUnitIndex] != 3U) ==> TRUE
      (3) for (seq < 4U) ==> FALSE
      (5) if (ret_val == 0U) ==> TRUE
      (6) if (anySeq < 4U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Cannot resolve multiple comparisons ( I2c.I2c_Disable.HwUnitIndex ) in branches 1/2
      Conflict: Unable to validate expression-to-expression comparison in branch 3
      Cannot set ret_val due to assignment
TEST.END_NOTES:
TEST.STUB:I2c.I2c_FindAnySequenceForHw
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_Disable.HwUnitIndex:<<MIN>>
TEST.VALUE:I2c.I2c_FindAnySequenceForHw.return:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Disable
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 4
      (1) if (HwUnitIndex < 4U) ==> TRUE
      (2) if ((I2c_DrvStatus.Status)[HwUnitIndex] != 3U) ==> TRUE
      (3) for (seq < 4U) ==> FALSE
      (5) if (ret_val == 0U) ==> TRUE
      (6) if (anySeq < 4U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Cannot resolve multiple comparisons ( I2c.I2c_Disable.HwUnitIndex ) in branches 1/2
      Conflict: Unable to validate expression-to-expression comparison in branch 3
      Cannot set ret_val due to assignment
TEST.END_NOTES:
TEST.STUB:I2c.I2c_FindAnySequenceForHw
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_Disable.HwUnitIndex:<<MIN>>
TEST.VALUE:I2c.I2c_FindAnySequenceForHw.return:3
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Disable
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 6
      (1) if (HwUnitIndex < 4U) ==> TRUE
      (2) if ((I2c_DrvStatus.Status)[HwUnitIndex] != 3U) ==> TRUE
      (3) for (seq < 4U) ==> TRUE
      (4) if (((I2c_ChannelConfig)[seq]).HwUnit == HwUnitIndex && ((I2c_ChannelInfo)[seq]).IsQueued != 0U) ==> TRUE
      (5) if (ret_val == 0U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 3
      Cannot set seq due to assignment
      Cannot set ret_val due to assignment
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_Disable.HwUnitIndex:<<MIN>>
TEST.END

-- Subprogram: I2c_DisableSequence

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_DisableSequence
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 1
      (1) if (4U > hw_index) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_DisableSequence.hw_index:<<MAX>>
TEST.VALUE:I2c.I2c_DisableSequence.sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_DisableSequence
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 2
      (1) if (4U > hw_index) ==> TRUE
      (2) if (4U > sequence) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_DisableSequence.hw_index:<<MIN>>
TEST.VALUE:I2c.I2c_DisableSequence.sequence:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_DisableSequence
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 3
      (1) if (4U > hw_index) ==> TRUE
      (2) if (4U > sequence) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_DisableSequence.hw_index:<<MIN>>
TEST.VALUE:I2c.I2c_DisableSequence.sequence:<<MIN>>
TEST.END

-- Subprogram: I2c_Enable

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Enable
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:

SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 1
      (1) if (HwUnitIndex < 4U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_Enable.HwUnitIndex:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Enable
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 2
      (1) if (HwUnitIndex < 4U) ==> TRUE
      (2) if (anySeq < 4U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_Enable.HwUnitIndex:<<MIN>>
TEST.VALUE:I2c.I2c_FindAnySequenceForHw.return:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Enable
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 3
      (1) if (HwUnitIndex < 4U) ==> TRUE
      (2) if (anySeq < 4U) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_Enable.HwUnitIndex:<<MIN>>
TEST.VALUE:I2c.I2c_FindAnySequenceForHw.return:<<MIN>>
TEST.END

-- Test Case: I2c_Enable.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Enable
TEST.NEW
TEST.NAME:I2c_Enable.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.END

-- Test Case: I2c_Enable.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Enable
TEST.NEW
TEST.NAME:I2c_Enable.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.END

-- Test Case: I2c_Enable.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Enable
TEST.NEW
TEST.NAME:I2c_Enable.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.END

-- Test Case: I2c_Enable.004
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Enable
TEST.NEW
TEST.NAME:I2c_Enable.004
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2c_FindAnySequenceForHw
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_FindAnySequenceForHw.return:5
TEST.END

-- Subprogram: I2c_EnableSequence

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_EnableSequence
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 1
      (1) if (4U > hw_index) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_EnableSequence.hw_index:<<MAX>>
TEST.VALUE:I2c.I2c_EnableSequence.sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_EnableSequence
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 2
      (1) if (4U > hw_index) ==> TRUE
      (2) if (4U > sequence) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_EnableSequence.hw_index:<<MIN>>
TEST.VALUE:I2c.I2c_EnableSequence.sequence:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_EnableSequence
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 3
      (1) if (4U > hw_index) ==> TRUE
      (2) if (4U > sequence) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_EnableSequence.hw_index:<<MIN>>
TEST.VALUE:I2c.I2c_EnableSequence.sequence:<<MIN>>
TEST.END

-- Subprogram: I2c_FindAnySequenceForHw

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_FindAnySequenceForHw
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 3 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 1
      (1) for (seq < 4U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_FindAnySequenceForHw.hw:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_FindAnySequenceForHw
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 2
      (1) for (seq < 4U) ==> TRUE
      (2) if (((I2c_ChannelConfig)[seq]).HwUnit == hw) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set seq due to assignment
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_FindAnySequenceForHw.hw:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_FindAnySequenceForHw
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 3
      (1) for (seq < 4U) ==> TRUE
      (2) if (((I2c_ChannelConfig)[seq]).HwUnit == hw) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set seq due to assignment
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_FindAnySequenceForHw.hw:1
TEST.END

-- Subprogram: I2c_FreeBus

-- Test Case: I2c_FreeBus.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_FreeBus
TEST.NEW
TEST.NAME:I2c_FreeBus.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2c_Init
TEST.STUB:I2c.I2c_Enable
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].I2C_Mode:1
TEST.END

-- Subprogram: I2c_FreeSlaveBus

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_FreeSlaveBus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 9
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 1
      (1) if (hw_index < 4U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_FreeSlaveBus.hw_index:<<MAX>>
TEST.END

-- Test Case: I2c_FreeSlaveBus.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_FreeSlaveBus
TEST.NEW
TEST.NAME:I2c_FreeSlaveBus.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2c_Disable
TEST.STUB:I2c.I2c_Enable
TEST.VALUE:uut_prototype_stubs.Pinmux_config.domainId:1
TEST.VALUE:uut_prototype_stubs.Dio_WriteChannel.ChannelId:1
TEST.VALUE:uut_prototype_stubs.Dio_WriteChannel.Level:0
TEST.END

-- Test Case: I2c_FreeSlaveBus.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_FreeSlaveBus
TEST.NEW
TEST.NAME:I2c_FreeSlaveBus.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2c_Disable
TEST.STUB:I2c.I2c_Enable
TEST.VALUE:I2c.I2c_FreeSlaveBus.hw_index:5
TEST.VALUE:uut_prototype_stubs.Pinmux_config.domainId:1
TEST.VALUE:uut_prototype_stubs.Dio_WriteChannel.ChannelId:1
TEST.VALUE:uut_prototype_stubs.Dio_WriteChannel.Level:0
TEST.END

-- Test Case: I2c_FreeSlaveBus.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_FreeSlaveBus
TEST.NEW
TEST.NAME:I2c_FreeSlaveBus.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2c_Disable
TEST.STUB:I2c.I2c_Enable
TEST.VALUE:I2c.<<GLOBAL>>.I2C_BusFreeConf[0].HwUnit:3
TEST.VALUE:I2c.I2c_FreeSlaveBus.hw_index:2
TEST.VALUE:uut_prototype_stubs.Pinmux_config.domainId:1
TEST.VALUE:uut_prototype_stubs.Dio_WriteChannel.ChannelId:1
TEST.VALUE:uut_prototype_stubs.Dio_WriteChannel.Level:0
TEST.END

-- Test Case: I2c_FreeSlaveBus.004
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_FreeSlaveBus
TEST.NEW
TEST.NAME:I2c_FreeSlaveBus.004
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2c_Disable
TEST.STUB:I2c.I2c_Enable
TEST.VALUE:uut_prototype_stubs.Pinmux_config.domainId:1
TEST.VALUE:uut_prototype_stubs.Dio_WriteChannel.ChannelId:1
TEST.VALUE:uut_prototype_stubs.Dio_WriteChannel.Level:0
TEST.END

-- Subprogram: I2c_GetSequenceResult

-- Test Case: I2c_GetSequenceResult.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_GetSequenceResult
TEST.NEW
TEST.NAME:I2c_GetSequenceResult.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.END

-- Test Case: I2c_GetSequenceResult.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_GetSequenceResult
TEST.NEW
TEST.NAME:I2c_GetSequenceResult.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_GetSequenceResult.Sequence:50
TEST.END

-- Subprogram: I2c_GetStatus

-- Test Case: I2c_GetStatus.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_GetStatus
TEST.NEW
TEST.NAME:I2c_GetStatus.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.END

-- Subprogram: I2c_HwDeInit

-- Test Case: I2c_HwDeInit.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_HwDeInit
TEST.NEW
TEST.NAME:I2c_HwDeInit.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_HwDeInit.I2c_unit:<<malloc 1>>
TEST.END

-- Subprogram: I2c_HwInit

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_HwInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_HwInit.I2c_unit_index:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_HwInit
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_HwInit.I2c_unit_index:<<MIN>>
TEST.END

-- Test Case: I2c_HwInit.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_HwInit
TEST.NEW
TEST.NAME:I2c_HwInit.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2c_Init
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_HwInit.I2c_unit_index:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.END

-- Subprogram: I2c_Init

-- Test Case: I2c_Init.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Init
TEST.NEW
TEST.NAME:I2c_Init.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2c_HwInit
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1]:252
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status:"1"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].SlaveAddress:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsRepeatStart:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[1].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[1].TxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[1].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[1].RxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[1].TxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[1].TxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[1].RxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[1].RxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[1].SlaveAddress:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[1].Result:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[1].IsQueued:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[1].IsRepeatStart:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:100
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.I2c_HwInit.I2c_unit_index:1
TEST.END

-- Subprogram: I2c_MainFunction

-- Test Case: BASIS-PATH-001-TEMPLATE
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE
TEST.BASIS_PATH:1 of 24 (template)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 1
      (1) for (Sequence < 4U) ==> FALSE
      (7) for (HwUnitIndex < 4U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Conflict: Unable to validate expression-to-expression comparison in branch 7
      Conflict: Unable to validate expression-to-expression comparison in branch 16
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367

This is an automatically generated test case.
   Test Path 2
      (1) for (Sequence < 4U) ==> FALSE
      (7) for (HwUnitIndex < 4U) ==> FALSE
      (16) for (Sequence < 4U) ==> TRUE
      (17) if (HwUnitIndex < 4U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Conflict: Unable to validate expression-to-expression comparison in branch 7
      Conflict: Unable to validate expression-to-expression comparison in branch 16
      Cannot set Sequence due to assignment
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-TEMPLATE
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-002-TEMPLATE
TEST.BASIS_PATH:2 of 22 (template)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:100
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL
TEST.BASIS_PATH:11 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:3
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE_USER_CODE:I2c.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<I2c.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:6
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE_USER_CODE:I2c.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<I2c.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-016-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-016-PARTIAL
TEST.BASIS_PATH:16 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:2
TEST.END

-- Test Case: BASIS-PATH-019-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-019-PARTIAL
TEST.BASIS_PATH:19 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-020-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-020-PARTIAL
TEST.BASIS_PATH:20 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-021-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-021-PARTIAL
TEST.BASIS_PATH:21 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-022-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-022-PARTIAL
TEST.BASIS_PATH:22 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-023-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-023-PARTIAL
TEST.BASIS_PATH:23 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].SeqPriority:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-024-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-024-PARTIAL
TEST.BASIS_PATH:24 of 24 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].SeqPriority:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.END

-- Test Case: I2c_MainFunction.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:I2c_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.END

-- Test Case: I2c_MainFunction.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:I2c_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.END

-- Test Case: I2c_MainFunction.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:I2c_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.END

-- Test Case: I2c_MainFunction.004
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MainFunction
TEST.NEW
TEST.NAME:I2c_MainFunction.004
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.END

-- Subprogram: I2c_MasterTransferComplete

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MasterTransferComplete
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 7
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MAX>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MasterTransferComplete
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].MasterSetting:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MasterTransferComplete
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].MasterSetting:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.base[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.I2c_MasterTransferComplete.sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MasterTransferComplete
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].MasterSetting:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.base[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.I2c_MasterTransferComplete.sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MasterTransferComplete
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].MasterSetting:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.base[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.I2c_MasterTransferComplete.sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MasterTransferComplete
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].MasterSetting:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.base[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.I2c_MasterTransferComplete.sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_MasterTransferComplete
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].MasterSetting:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_MasterTransferComplete.base[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.I2c_MasterTransferComplete.sequence:<<MIN>>
TEST.END

-- Subprogram: I2c_PrepareReadTransfer

-- Test Case: I2c_PrepareReadTransfer.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_PrepareReadTransfer
TEST.NEW
TEST.NAME:I2c_PrepareReadTransfer.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.END

-- Test Case: I2c_PrepareReadTransfer.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_PrepareReadTransfer
TEST.NEW
TEST.NAME:I2c_PrepareReadTransfer.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:2
TEST.VALUE:I2c.I2c_PrepareReadTransfer.I2cUnitPtr:<<malloc 1>>
TEST.END

-- Test Case: I2c_PrepareReadTransfer.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_PrepareReadTransfer
TEST.NEW
TEST.NAME:I2c_PrepareReadTransfer.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0x30
TEST.VALUE:I2c.I2c_PrepareReadTransfer.I2cUnitPtr:<<malloc 1>>
TEST.END

-- Subprogram: I2c_ReadFiFoArray

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_ReadFiFoArray
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_RxGetBufferStatus
TEST.VALUE:I2c.I2c_ReadFiFoArray.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_ReadFiFoArray.rxBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_ReadFiFoArray.size:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_ReadFiFoArray
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_RxGetBufferStatus
TEST.VALUE:I2c.I2c_ReadFiFoArray.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_ReadFiFoArray.rxBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_ReadFiFoArray.size:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_ReadFiFoArray
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_RxGetBufferStatus
TEST.VALUE:I2c.I2c_ReadFiFoArray.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_ReadFiFoArray.rxBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_ReadFiFoArray.size:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_ReadFiFoArray
TEST.NEW
TEST.NAME:BASIS-PATH-003.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_RxGetBufferStatus
TEST.VALUE:I2c.I2C_RxGetBufferStatus.return:40
TEST.VALUE:I2c.I2c_ReadFiFoArray.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_ReadFiFoArray.rxBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_ReadFiFoArray.size:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_ReadFiFoArray
TEST.NEW
TEST.NAME:BASIS-PATH-003.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_RxGetBufferStatus
TEST.VALUE:I2c.I2C_RxGetBufferStatus.return:40
TEST.VALUE:I2c.I2c_ReadFiFoArray.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_ReadFiFoArray.rxBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_ReadFiFoArray.size:<<MAX>>
TEST.END

-- Subprogram: I2c_ReadFiFoWithoutCheck

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_ReadFiFoWithoutCheck
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_ReadFiFoWithoutCheck.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_ReadFiFoWithoutCheck.rxBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_ReadFiFoWithoutCheck.size:0
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_ReadFiFoWithoutCheck
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_ReadFiFoWithoutCheck.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_ReadFiFoWithoutCheck.rxBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_ReadFiFoWithoutCheck.size:1
TEST.END

-- Subprogram: I2c_RepeatedStart

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_RepeatedStart
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_RepeatedStart.Sequence:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_RepeatedStart
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_RepeatedStart.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_RepeatedStart
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_RepeatedStart.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_RepeatedStart
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_RepeatedStart.Sequence:<<MIN>>
TEST.END

-- Subprogram: I2c_SetupEB

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SetupEB
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 8
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_SetupEB.Channel:<<MAX>>
TEST.VALUE:I2c.I2c_SetupEB.TxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.RxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.TxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.RxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.SlaveAddress:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SetupEB
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 8 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MAX>>
TEST.VALUE:I2c.I2c_SetupEB.Channel:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.TxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.RxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.TxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.RxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.SlaveAddress:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SetupEB
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 8 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.Channel:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.TxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.RxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.TxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.RxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.SlaveAddress:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SetupEB
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 8 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.Channel:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.TxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.RxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.TxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.RxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.SlaveAddress:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SetupEB
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 8 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.Channel:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.TxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.RxBufferPtr:<<malloc 9>>
TEST.VALUE:I2c.I2c_SetupEB.RxBufferPtr:<<null>>
TEST.VALUE:I2c.I2c_SetupEB.TxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.RxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.SlaveAddress:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SetupEB
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 8 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.Channel:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.TxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.RxBufferPtr:<<malloc 9>>
TEST.VALUE:I2c.I2c_SetupEB.RxBufferPtr:<<null>>
TEST.VALUE:I2c.I2c_SetupEB.TxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.RxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.SlaveAddress:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SetupEB
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 8 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.Channel:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.TxBufferPtr:<<malloc 9>>
TEST.VALUE:I2c.I2c_SetupEB.TxBufferPtr:<<null>>
TEST.VALUE:I2c.I2c_SetupEB.RxBufferPtr:<<malloc 9>>
TEST.VALUE:I2c.I2c_SetupEB.RxBufferPtr:<<null>>
TEST.VALUE:I2c.I2c_SetupEB.TxLength:0
TEST.VALUE:I2c.I2c_SetupEB.RxLength:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.SlaveAddress:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SetupEB
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.Channel:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.TxBufferPtr:<<malloc 9>>
TEST.VALUE:I2c.I2c_SetupEB.TxBufferPtr:<<null>>
TEST.VALUE:I2c.I2c_SetupEB.RxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.TxLength:0
TEST.VALUE:I2c.I2c_SetupEB.RxLength:1
TEST.VALUE:I2c.I2c_SetupEB.SlaveAddress:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SetupEB
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 8 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.Channel:<<MIN>>
TEST.VALUE:I2c.I2c_SetupEB.TxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.RxBufferPtr:<<malloc 1>>
TEST.VALUE:I2c.I2c_SetupEB.TxLength:<<MAX>>
TEST.VALUE:I2c.I2c_SetupEB.RxLength:0
TEST.VALUE:I2c.I2c_SetupEB.SlaveAddress:<<MIN>>
TEST.END

-- Subprogram: I2c_StartTransfer

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_StartTransfer
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_StartTransfer.Sequence:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_StartTransfer
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_StartTransfer.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_StartTransfer
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 5 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_StartTransfer.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_StartTransfer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_StartTransfer.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_StartTransfer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_StartTransfer.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_StartTransfer
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_StartTransfer.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_StartTransfer
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_StartTransfer.Sequence:<<MIN>>
TEST.END

-- Subprogram: I2c_Stop

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_Stop
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_Stop.Reg_pt:<<malloc 1>>
TEST.END

-- Subprogram: I2c_StopWait

-- Test Case: I2c_StopWait.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_StopWait
TEST.NEW
TEST.NAME:I2c_StopWait.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_StopWait.HwUnitIndexVAr:5
TEST.END

-- Test Case: I2c_StopWait.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_StopWait
TEST.NEW
TEST.NAME:I2c_StopWait.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2c_Stop
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:7
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_StopWait.HwUnitIndexVAr:1
TEST.END

-- Test Case: I2c_StopWait.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_StopWait
TEST.NEW
TEST.NAME:I2c_StopWait.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.MasterInterrupt
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:5
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:0
TEST.VALUE:I2c.I2c_StopWait.HwUnitIndexVAr:0
TEST.END

-- Test Case: I2c_StopWait.004
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_StopWait
TEST.NEW
TEST.NAME:I2c_StopWait.004
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.MasterInterrupt
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:5
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:0
TEST.VALUE:I2c.I2c_StopWait.HwUnitIndexVAr:0
TEST.END

-- Subprogram: I2c_SyncTransmit

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 36
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (Sequence < 4U) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MAX>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL
TEST.BASIS_PATH:11 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-012-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-012-PARTIAL
TEST.BASIS_PATH:12 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL
TEST.BASIS_PATH:13 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL
TEST.BASIS_PATH:14 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-015-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-015-PARTIAL
TEST.BASIS_PATH:15 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-016-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-016-PARTIAL
TEST.BASIS_PATH:16 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-017-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-017-PARTIAL
TEST.BASIS_PATH:17 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-018-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-018-PARTIAL
TEST.BASIS_PATH:18 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-022-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-022-PARTIAL
TEST.BASIS_PATH:22 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-023-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-023-PARTIAL
TEST.BASIS_PATH:23 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-024-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-024-PARTIAL
TEST.BASIS_PATH:24 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-025-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-025-PARTIAL
TEST.BASIS_PATH:25 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-025-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-025-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].SlaveAddress:0x48
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:0
TEST.END

-- Test Case: BASIS-PATH-025-PARTIAL.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-025-PARTIAL.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-026-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-026-PARTIAL
TEST.BASIS_PATH:26 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-027-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-027-PARTIAL
TEST.BASIS_PATH:27 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-028-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-028-PARTIAL
TEST.BASIS_PATH:28 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-029-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-029-PARTIAL
TEST.BASIS_PATH:29 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-034-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-034-PARTIAL
TEST.BASIS_PATH:34 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-035-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-035-PARTIAL
TEST.BASIS_PATH:35 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-035-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-035-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-036-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-036-PARTIAL
TEST.BASIS_PATH:36 of 36 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_DrvStatus.Status[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelConfig[0].HwUnit:<<MIN>>
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:<<MIN>>
TEST.END

-- Test Case: I2c_SyncTransmit-PARTITIONS
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:I2c_SyncTransmit-PARTITIONS
TEST.VALUE:<<OPTIONS>>.DATA_PARTITIONS:0
TEST.VALUE:I2c.I2c_SyncTransmit.Sequence:VARY FROM:<<MIN>> TO:<<MAX>> BY: <<PARTITION>>
TEST.VALUE:I2c.I2c_SyncTransmit.return:VARY FROM:<<MIN>> TO:<<MAX>> BY: <<PARTITION>>
TEST.END

-- Test Case: I2c_SyncTransmit_MAX.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:I2c_SyncTransmit_MAX.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:<<ALL_MAX>>
TEST.END

-- Test Case: I2c_SyncTransmit_MAX.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:I2c_SyncTransmit_MAX.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:<<ALL_MAX>>
TEST.END

-- Test Case: I2c_SyncTransmit_MID.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:I2c_SyncTransmit_MID.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:<<ALL_MID>>
TEST.END

-- Test Case: I2c_SyncTransmit_MIN.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_SyncTransmit
TEST.NEW
TEST.NAME:I2c_SyncTransmit_MIN.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:<<ALL_MIN>>
TEST.END

-- Subprogram: I2c_TrySlaveBusRecovery

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_TrySlaveBusRecovery
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (hwIndex < 4U) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_TrySlaveBusRecovery.hwIndex:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_TrySlaveBusRecovery
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (hwIndex < 4U) ==> TRUE
      (2) if (I2C_GetStatusOfSDALine(hwIndex) == 1U) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_GetStatusOfSDALine
TEST.VALUE:I2c.I2C_GetStatusOfSDALine.return:<<MIN>>
TEST.VALUE:I2c.I2c_TrySlaveBusRecovery.hwIndex:<<MIN>>
TEST.END

-- Test Case: I2c_TrySlaveBusRecovery-PARTITIONS
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_TrySlaveBusRecovery
TEST.NEW
TEST.NAME:I2c_TrySlaveBusRecovery-PARTITIONS
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.DATA_PARTITIONS:0
TEST.VALUE:I2c.I2c_TrySlaveBusRecovery.hwIndex:VARY FROM:<<MIN>> TO:<<MAX>> BY: <<PARTITION>>
TEST.END

-- Test Case: I2c_TrySlaveBusRecovery-PARTITIONS.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_TrySlaveBusRecovery
TEST.NEW
TEST.NAME:I2c_TrySlaveBusRecovery-PARTITIONS.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_GetStatusOfSDALine
TEST.STUB:I2c.I2c_FreeSlaveBus
TEST.VALUE:<<OPTIONS>>.DATA_PARTITIONS:0
TEST.VALUE:I2c.I2C_GetStatusOfSDALine.return:1
TEST.VALUE:I2c.I2c_TrySlaveBusRecovery.hwIndex:VARY FROM:<<MIN>> TO:<<MAX>> BY: <<PARTITION>>
TEST.END

-- Subprogram: I2c_TxRxIsroutine

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_TxRxIsroutine
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_TxRxIsroutine.HwUnitIndex:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_TxRxIsroutine
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.I2c_TxRxIsroutine.HwUnitIndex:<<MIN>>
TEST.END

-- Subprogram: I2c_WriteFiFoArray

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_WriteFiFoArray
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_GetBufferStatus
TEST.VALUE:I2c.<<GLOBAL>>.txfifobufferstatus:1
TEST.VALUE:I2c.I2c_WriteFiFoArray.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_WriteFiFoArray.txBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_WriteFiFoArray.size:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_WriteFiFoArray
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_GetBufferStatus
TEST.VALUE:I2c.<<GLOBAL>>.txfifobufferstatus:0
TEST.VALUE:I2c.I2c_WriteFiFoArray.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_WriteFiFoArray.txBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_WriteFiFoArray.size:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_WriteFiFoArray
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_GetBufferStatus
TEST.VALUE:I2c.<<GLOBAL>>.txfifobufferstatus:1
TEST.VALUE:I2c.I2c_WriteFiFoArray.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_WriteFiFoArray.txBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_WriteFiFoArray.size:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_WriteFiFoArray
TEST.NEW
TEST.NAME:BASIS-PATH-003.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_GetBufferStatus
TEST.VALUE:I2c.<<GLOBAL>>.txfifobufferstatus:1
TEST.VALUE:I2c.I2C_GetBufferStatus.return:40
TEST.VALUE:I2c.I2c_WriteFiFoArray.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_WriteFiFoArray.txBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_WriteFiFoArray.size:<<MIN>>
TEST.END

-- Subprogram: I2c_WriteFiFoWithoutCheck

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_WriteFiFoWithoutCheck
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_WriteFiFoWithoutCheck.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_WriteFiFoWithoutCheck.txBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_WriteFiFoWithoutCheck.size:0
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_WriteFiFoWithoutCheck
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_WriteFiFoWithoutCheck.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_WriteFiFoWithoutCheck.txBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_WriteFiFoWithoutCheck.size:1
TEST.END

-- Subprogram: I2c_XDRWriteFiFoArray

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_XDRWriteFiFoArray
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_XDRWriteFiFoArray.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_XDRWriteFiFoArray.txBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_XDRWriteFiFoArray.size:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_XDRWriteFiFoArray
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.I2c_XDRWriteFiFoArray.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_XDRWriteFiFoArray.txBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_XDRWriteFiFoArray.size:<<MIN>>
TEST.END

-- Test Case: I2c_XDRWriteFiFoArray.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_XDRWriteFiFoArray
TEST.NEW
TEST.NAME:I2c_XDRWriteFiFoArray.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_GetBufferStatus
TEST.VALUE:I2c.I2C_GetBufferStatus.return:6
TEST.END

-- Test Case: I2c_XDRWriteFiFoArray.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:I2c_XDRWriteFiFoArray
TEST.NEW
TEST.NAME:I2c_XDRWriteFiFoArray.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.STUB:I2c.I2C_GetBufferStatus
TEST.VALUE:I2c.I2C_GetBufferStatus.return:6
TEST.VALUE:I2c.I2c_XDRWriteFiFoArray.base:<<malloc 1>>
TEST.VALUE:I2c.I2c_XDRWriteFiFoArray.txBuf:VECTORCAST_INT1
TEST.VALUE:I2c.I2c_XDRWriteFiFoArray.size:<<MAX>>
TEST.VALUE:I2c.I2c_XDRWriteFiFoArray.return:10
TEST.END

-- Subprogram: MasterInterrupt

-- Test Case: BASIS-PATH-001
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 37
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 37
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:55
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-002.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:5
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-002.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:55
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsRepeatStart:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-002.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsRepeatStart:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002.004
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-002.004
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002.005
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-002.005
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:55
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002.006
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-002.006
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:55
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"4"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].SlaveAddress:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsRepeatStart:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0x4000
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1GC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1STC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AAS:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RDR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR:1
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:0
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.I2c_Config.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:INPUT_BASE=16
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"4"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:55
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].SlaveAddress:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsRepeatStart:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0x4000
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1GC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1STC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AAS:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RDR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR:1
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:0
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.I2c_Config.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:INPUT_BASE=16
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"4"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].SlaveAddress:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsRepeatStart:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0x4000
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1GC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1STC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AAS:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RDR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR:1
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:0
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.I2c_Config.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:INPUT_BASE=16
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"4"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:15
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].SlaveAddress:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsRepeatStart:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0x4000
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1GC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1STC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AAS:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RDR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR:1
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:0
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.I2c_Config.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:INPUT_BASE=16
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.004
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.004
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"4"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:15
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].SlaveAddress:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsRepeatStart:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0x4000
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1GC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1STC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AAS:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RDR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].BUFSTAT_reg.BUFSTAT_field.u6TXSTAT:5
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:0
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.I2c_Config.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:INPUT_BASE=16
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.005
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.005
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"4"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:15
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].SlaveAddress:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsRepeatStart:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0x4002
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1GC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1STC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AAS:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RDR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].CNT_reg.CNT_field.u16DCOUNT:50
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:0
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.I2c_Config.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:INPUT_BASE=16
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.006
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.006
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"4"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:15
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].SlaveAddress:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsRepeatStart:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0x2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1GC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1STC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AAS:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RDR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].CNT_reg.CNT_field.u16DCOUNT:50
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:0
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.I2c_Config.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:INPUT_BASE=16
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.007
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.007
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"4"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:15
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxIndex:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 2>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:"0"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].SlaveAddress:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsQueued:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].IsRepeatStart:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].TimeoutCount:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].HwStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentPriority:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].IsStopWait:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].BusBusyTimeout:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_BusBusyState[0].WholeNetworkStatus:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0x4004
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1GC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1STC:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AAS:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RDR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].BUFSTAT_reg.BUFSTAT_field.u6TXSTAT:5
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:0
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.I2c_Config.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:INPUT_BASE=16
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"4"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL
TEST.BASIS_PATH:11 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-012-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-012-PARTIAL
TEST.BASIS_PATH:12 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL
TEST.BASIS_PATH:13 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"8"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"8"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:55
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"9"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0x20
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"9"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0x1E
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.004
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.004
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"9"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0x21
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.005
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.005
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"9"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0x25
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.006
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.006
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:8
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:9
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.007
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.007
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:9
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:9
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.008
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.008
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:9
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.009
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.009
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:9
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.010
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.010
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:9
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.011
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.011
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:9
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.012
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.012
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:9
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:55
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.013
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.013
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.014
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.014
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:8
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.015
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.015
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:8
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].CON_reg.CON_field.u1STP:0x1
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.016
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.016
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:9
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:2048
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.017
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.017
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:9
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:2048
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].BUFSTAT_reg.BUFSTAT_field.u6TXSTAT:16
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.018
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.018
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:9
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0x80
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:2048
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL.019
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL.019
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState[0]:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"10"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:5
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:8
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"10"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:5
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0x2000
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL.004
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL.004
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:<<malloc 3>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"10"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0x2000
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL.005
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL.005
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"10"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0x2000
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL.006
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL.006
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"10"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0x2000
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.VALUE_USER_CODE:I2c.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<I2c.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL.007
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL.007
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:<<malloc 3>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"10"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0x2000
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].CON_reg.CON_field.u1STP:0x1
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL.008
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL.008
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:<<malloc 3>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"10"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0x2000
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].CON_reg.CON_field.u1STP:0x1
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.VALUE_USER_CODE:I2c.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<I2c.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL.009
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL.009
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:<<malloc 3>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"10"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:3
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0x2000
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.VALUE_USER_CODE:I2c.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<I2c.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL.010
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL.010
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:<<malloc 3>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"10"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxBuffer:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:8
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0x2000
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.VALUE_USER_CODE:I2c.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<I2c.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-015-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-015-PARTIAL
TEST.BASIS_PATH:15 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"9"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-016-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-016-PARTIAL
TEST.BASIS_PATH:16 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"9"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-017-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-017-PARTIAL
TEST.BASIS_PATH:17 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"9"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-018-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-018-PARTIAL
TEST.BASIS_PATH:18 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_InternalState:"9"
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-019-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-019-PARTIAL
TEST.BASIS_PATH:19 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-020-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-020-PARTIAL
TEST.BASIS_PATH:20 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-021-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-021-PARTIAL
TEST.BASIS_PATH:21 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-022-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-022-PARTIAL
TEST.BASIS_PATH:22 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-023-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-023-PARTIAL
TEST.BASIS_PATH:23 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-024-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-024-PARTIAL
TEST.BASIS_PATH:24 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-025-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-025-PARTIAL
TEST.BASIS_PATH:25 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-026-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-026-PARTIAL
TEST.BASIS_PATH:26 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-027-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-027-PARTIAL
TEST.BASIS_PATH:27 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-028-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-028-PARTIAL
TEST.BASIS_PATH:28 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].BUFSTAT_reg.BUFSTAT_field.u6TXSTAT:1
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-029-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-029-PARTIAL
TEST.BASIS_PATH:29 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].BUFSTAT_reg.BUFSTAT_field.u6TXSTAT:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-030-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-030-PARTIAL
TEST.BASIS_PATH:30 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].CNT_reg.CNT_field.u16DCOUNT:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].BUFSTAT_reg.BUFSTAT_field.u6TXSTAT:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-031-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-031-PARTIAL
TEST.BASIS_PATH:31 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].CNT_reg.CNT_field.u16DCOUNT:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].BUFSTAT_reg.BUFSTAT_field.u6TXSTAT:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-032-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-032-PARTIAL
TEST.BASIS_PATH:32 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-033-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-033-PARTIAL
TEST.BASIS_PATH:33 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-034-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-034-PARTIAL
TEST.BASIS_PATH:34 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-035-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-035-PARTIAL
TEST.BASIS_PATH:35 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:<<MAX>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:<<MIN>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-036-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-036-PARTIAL
TEST.BASIS_PATH:36 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-036-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-036-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:4
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR:0
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-036-PARTIAL.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-036-PARTIAL.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:4
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:256
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-036-PARTIAL.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-036-PARTIAL.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].Result:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:4
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL:1
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.u32Register:256
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:0
TEST.END

-- Test Case: BASIS-PATH-037-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-037-PARTIAL
TEST.BASIS_PATH:37 of 37 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_HwInfo[0].CurrentSeq:6
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:2
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-037-PARTIAL.001
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-037-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.IRQSTATUS_field.u1BF:1
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-037-PARTIAL.002
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-037-PARTIAL.002
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_reg.IRQSTATUS_field.u1BF:1
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.VALUE_USER_CODE:uut_prototype_stubs.<<GLOBAL>>.I2c_ChannelConfig.I2c_ChannelConfig[0].I2C_EndNotificationCallback
<<uut_prototype_stubs.<<GLOBAL>>.I2c_ChannelConfig>>[0].I2C_EndNotificationCallback = ( &Client_I2CCbJobEnd_temp );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-037-PARTIAL.003
TEST.UNIT:I2c
TEST.SUBPROGRAM:MasterInterrupt
TEST.NEW
TEST.NAME:BASIS-PATH-037-PARTIAL.003
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].TxLength:0
TEST.VALUE:I2c.<<GLOBAL>>.I2c_ChannelInfo[0].RxLength:15
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress:<<malloc 1>>
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.u32Register:2
TEST.VALUE:I2c.<<GLOBAL>>.I2c_Config[0].BaseAddress[0].IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB:0x1
TEST.VALUE:I2c.MasterInterrupt.HwUnitIndexVAr:<<MIN>>
TEST.END

-- Subprogram: RxDiffCalculationFunction

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:RxDiffCalculationFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 3 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.RxDiffCalculationFunction.StartValue:<<MIN>>
TEST.VALUE:I2c.RxDiffCalculationFunction.EndValue:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:RxDiffCalculationFunction
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.RxDiffCalculationFunction.StartValue:<<MIN>>
TEST.VALUE:I2c.RxDiffCalculationFunction.EndValue:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:I2c
TEST.SUBPROGRAM:RxDiffCalculationFunction
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
SoftwareArchitecture::MCAL::I2cdrv::I2Cdrv_Detailed_Design::I2CDrv_Class
Requirement_PE4TI29141-5367
TEST.END_NOTES:
TEST.VALUE:I2c.RxDiffCalculationFunction.StartValue:<<MAX>>
TEST.VALUE:I2c.RxDiffCalculationFunction.EndValue:<<MIN>>
TEST.END
