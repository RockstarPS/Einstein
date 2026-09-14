-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : BACKLIGHTCDD_MAX20446_VCAST_HT
-- Unit(s) Under Test: BacklightCdd_ErrorHandler BacklightDrvCdd BacklightDrvCdd_I2C BacklightDrvCdd_I2C_MAX20446 Backlightcdd CDD_Backlight
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: BacklightCdd_ErrorHandler

-- Subprogram: BacklightCdd_ReportError

-- Test Case: BacklightCdd_ReportError.001
TEST.UNIT:BacklightCdd_ErrorHandler
TEST.SUBPROGRAM:BacklightCdd_ReportError
TEST.NEW
TEST.NAME:BacklightCdd_ReportError.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Unit: BacklightDrvCdd

-- Subprogram: BacklightCdd_Internal_I2cGetSeqResult

-- Test Case: BacklightCdd_Internal_I2cGetSeqResult.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightCdd_Internal_I2cGetSeqResult
TEST.NEW
TEST.NAME:BacklightCdd_Internal_I2cGetSeqResult.001
TEST.VALUE:BacklightDrvCdd.BacklightCdd_Internal_I2cGetSeqResult.I2CCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.BacklightCdd_Internal_I2cGetSeqResult.I2CCfg[0].i2cSeqIdWrite:1
TEST.END

-- Subprogram: BacklightDrvCdd_DeInit

-- Test Case: BacklightDrvCdd_DeInit.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_DeInit
TEST.NEW
TEST.NAME:BacklightDrvCdd_DeInit.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: BacklightDrvCdd_EnterSafeState

-- Test Case: BacklightDrvCdd_EnterSafeState.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_EnterSafeState
TEST.NEW
TEST.NAME:BacklightDrvCdd_EnterSafeState.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: BacklightDrvCdd_ExitSafeState

-- Test Case: BacklightDrvCdd_ExitSafeState.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_ExitSafeState
TEST.NEW
TEST.NAME:BacklightDrvCdd_ExitSafeState.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_FLT1:1.0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_FLT1:1.0
TEST.END

-- Subprogram: BacklightDrvCdd_GetStatus

-- Test Case: BacklightDrvCdd_GetStatus.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_GetStatus
TEST.NEW
TEST.NAME:BacklightDrvCdd_GetStatus.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Subprogram: BacklightDrvCdd_Init

-- Test Case: BacklightDrvCdd_Init.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Init
TEST.NEW
TEST.NAME:BacklightDrvCdd_Init.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightDrvCdd_Init.002
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Init
TEST.NEW
TEST.NAME:BacklightDrvCdd_Init.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightDrvCdd_Init.003
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Init
TEST.NEW
TEST.NAME:BacklightDrvCdd_Init.003
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorLen:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Subprogram: BacklightDrvCdd_Internal_MainFunction

-- Test Case: BacklightDrvCdd_Internal_MainFunction.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.002
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.002
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_ON_WAIT
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.003
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.003
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_ON
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].EnableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.004
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.004
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:Backlightcdd.CBacklightCdd_SetBrightnessValue.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.005
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.005
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_ON_WAIT
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.006
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.006
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_ON_WAIT
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:2
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:10
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.007
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.007
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_CONFIGURE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:7
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].RegTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.008
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.008
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_CONFIGURE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].RegTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.009
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.009
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_CONFIGURE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].RegTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.010
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.010
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_ON
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].EnableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.011
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.011
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.012
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.012
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_FAULTDIAG
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.013
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.013
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_FAULTDIAG
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.014
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.014
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_FAULTDIAG
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.015
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.015
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_SAFETYREACTION
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.016
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.016
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_SAFETYREACTION
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.017
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.017
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERROR
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.018
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.018
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERROR
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:25
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.019
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.019
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERROR
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.020
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.020
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERROR
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.021
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.021
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_CONFIGURE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:0x15
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].RegTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.022
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.022
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_IDLE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:15
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.023
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.023
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Reg_monitor
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:10
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_NORMAL
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.024
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.024
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:10
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_IDLE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.025
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.025
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERROR
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.026
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.026
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERRORRECOVERY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.027
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.027
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Reg_monitor
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_NORMAL
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.FltActLvl:BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_HIGH
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.028
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.028
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERRORRECOVERY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.029
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.029
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERRORRECOVERY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.030
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.030
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:BacklightDrvCdd_I2C.BacklightDrvCdd_Process_Set_Brightness
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_SAFE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.031
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.031
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_PERMANENT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.032
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.032
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_OFF
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.033
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.033
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERRORRECOVERY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.034
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.034
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_CONFIGURE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].RegTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.return:1
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.035
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.035
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_FAULTDIAG
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.FltActLvl:BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_HIGH
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.036
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.036
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Reg_monitor
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:10
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_NORMAL
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FltMonDlyCntr:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.037
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.037
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.038
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.038
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_SAFETYREACTION
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.039
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.039
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERROR
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.FltActLvl:BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_HIGH
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.040
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.040
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:18
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.FltActLvl:BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_HIGH
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.041
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.041
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Reg_monitor
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:BacklightDrvCdd_I2C.BacklightDrvCdd_Process_Set_Brightness
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_NORMAL
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.042
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.042
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_CONFIGURE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].RegTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.043
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.043
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_CONFIGURE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:11
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].RegTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.044
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.044
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:BacklightDrvCdd_I2C.BacklightDrvCdd_Process_Set_Brightness
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_SAFE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.045
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.045
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd.BacklightCdd_Internal_I2cGetSeqResult
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_OFF_WAIT
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.046
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.046
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdateI2CDuty
TEST.STUB:BacklightDrvCdd.BacklightCdd_Internal_I2cGetSeqResult
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_OFF_WAIT
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Reg_count:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.Retry_count:245
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DeviceId:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:BacklightDrvCdd.BacklightCdd_Internal_I2cGetSeqResult.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].Backlight_EnableDoutID:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].DisableLevel:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: BacklightDrvCdd_IsFaultActive

-- Test Case: BacklightDrvCdd_IsFaultActive.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_IsFaultActive
TEST.NEW
TEST.NAME:BacklightDrvCdd_IsFaultActive.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.FltActLvl:BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_LOW
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.return:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightDrvCdd_IsFaultActive.002
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_IsFaultActive
TEST.NEW
TEST.NAME:BacklightDrvCdd_IsFaultActive.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.FltActLvl:BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_LOW
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.FaultSignal:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightDrvCdd_IsFaultActive.003
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_IsFaultActive
TEST.NEW
TEST.NAME:BacklightDrvCdd_IsFaultActive.003
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.FltActLvl:3
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.FaultSignal:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: BacklightDrvCdd_MainFunction

-- Test Case: BacklightDrvCdd_MainFunction.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_MainFunction.001
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Internal_MainFunction
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: BacklightDrvCdd_Reg_monitor

-- Test Case: BacklightDrvCdd_Reg_monitor.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Reg_monitor
TEST.NEW
TEST.NAME:BacklightDrvCdd_Reg_monitor.001
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 1>>
TEST.END

-- Test Case: BacklightDrvCdd_Reg_monitor.006
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Reg_monitor
TEST.NEW
TEST.NAME:BacklightDrvCdd_Reg_monitor.006
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.END

-- Test Case: BacklightDrvCdd_Reg_monitor.011
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Reg_monitor
TEST.NEW
TEST.NAME:BacklightDrvCdd_Reg_monitor.011
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 2>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorLen:3
TEST.END

-- Test Case: BacklightDrvCdd_Reg_monitor.012
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Reg_monitor
TEST.NEW
TEST.NAME:BacklightDrvCdd_Reg_monitor.012
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].timer:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 2>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorLen:3
TEST.END

-- Test Case: BacklightDrvCdd_Reg_monitor.013
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Reg_monitor
TEST.NEW
TEST.NAME:BacklightDrvCdd_Reg_monitor.013
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].timer:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 2>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorLen:3
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult.return:1
TEST.END

-- Test Case: BacklightDrvCdd_Reg_monitor.014
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Reg_monitor
TEST.NEW
TEST.NAME:BacklightDrvCdd_Reg_monitor.014
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].timer:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 2>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorLen:3
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead.return:1
TEST.END

-- Test Case: BacklightDrvCdd_Reg_monitor.015
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Reg_monitor
TEST.NEW
TEST.NAME:BacklightDrvCdd_Reg_monitor.015
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].state:REGMON_BUSY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 2>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorLen:3
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead.return:1
TEST.END

-- Test Case: BacklightDrvCdd_Reg_monitor.016
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Reg_monitor
TEST.NEW
TEST.NAME:BacklightDrvCdd_Reg_monitor.016
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].state:REGMON_BUSY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].firstReadDone:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 2>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorLen:3
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead.return:1
TEST.END

-- Test Case: BacklightDrvCdd_Reg_monitor.017
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Reg_monitor
TEST.NEW
TEST.NAME:BacklightDrvCdd_Reg_monitor.017
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].state:REGMON_BUSY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].firstReadDone:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 2>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorLen:3
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead.return:1
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult.return:1
TEST.END

-- Test Case: BacklightDrvCdd_Reg_monitor.018
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Reg_monitor
TEST.NEW
TEST.NAME:BacklightDrvCdd_Reg_monitor.018
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetRxData
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].state:REGMON_BUSY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].firstReadDone:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 2>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].SafetyAction:BACKLIGHT_INIT
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].SafetyAction:BACKLIGHT_INIT
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorLen:1
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead.return:1
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cGetRxData.val[0]:4
TEST.END

-- Test Case: BacklightDrvCdd_Reg_monitor.019
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Reg_monitor
TEST.NEW
TEST.NAME:BacklightDrvCdd_Reg_monitor.019
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetRxData
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].state:REGMON_BUSY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].firstReadDone:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 2>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[1].SafetyAction:BACKLIGHT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorLen:1
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead.return:1
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cGetRxData.val[0]:4
TEST.END

-- Test Case: BacklightDrvCdd_Reg_monitor.020
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Reg_monitor
TEST.NEW
TEST.NAME:BacklightDrvCdd_Reg_monitor.020
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetRxData
TEST.STUB:BacklightDrvCdd_I2C.BacklightCdd_I2cGetSeqResult
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].state:REGMON_BUSY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_RegRuntimeMonitor[0].firstReadDone:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].mask:4
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorRegs[0].SafetyAction:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].monitorLen:1
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cAsyncRegRead.return:1
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cGetRxData.val[0]:4
TEST.END

-- Subprogram: BacklightDrvCdd_RequestPower

-- Test Case: BacklightDrvCdd_RequestPower.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_RequestPower
TEST.NEW
TEST.NAME:BacklightDrvCdd_RequestPower.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Subprogram: BacklightDrvCdd_SetBrightness

-- Test Case: BacklightDrvCdd_SetBrightness.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_SetBrightness
TEST.NEW
TEST.NAME:BacklightDrvCdd_SetBrightness.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Subprogram: BacklightDrvCdd_UpdateI2CDuty

-- Test Case: BacklightDrvCdd_UpdateI2CDuty.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_UpdateI2CDuty
TEST.NEW
TEST.NAME:BacklightDrvCdd_UpdateI2CDuty.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightDrvCdd_UpdateI2CDuty.002
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_UpdateI2CDuty
TEST.NEW
TEST.NAME:BacklightDrvCdd_UpdateI2CDuty.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_DutyInfo.CurrentDutyValue:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_DutyInfo.LastDutyValue:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightDrvCdd_UpdateI2CDuty.003
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_UpdateI2CDuty
TEST.NEW
TEST.NAME:BacklightDrvCdd_UpdateI2CDuty.003
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_DutyInfo.CurrentDutyValue:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_DutyInfo.LastDutyValue:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_SAFETYREACTION
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Unit: BacklightDrvCdd_I2C

-- Subprogram: BacklightCdd_I2cAsyncRegRead

-- Test Case: BacklightCdd_I2cAsyncRegRead.001
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightCdd_I2cAsyncRegRead
TEST.NEW
TEST.NAME:BacklightCdd_I2cAsyncRegRead.001
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.END

-- Test Case: BacklightCdd_I2cAsyncRegRead.002
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightCdd_I2cAsyncRegRead
TEST.NEW
TEST.NAME:BacklightCdd_I2cAsyncRegRead.002
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.return:1
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.END

-- Test Case: BacklightCdd_I2cAsyncRegRead.003
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightCdd_I2cAsyncRegRead
TEST.NEW
TEST.NAME:BacklightCdd_I2cAsyncRegRead.003
TEST.VALUE:uut_prototype_stubs.I2c_AsyncTransmit.return:1
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.END

-- Subprogram: BacklightCdd_I2cGetRxData

-- Test Case: BacklightCdd_I2cGetRxData.001
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightCdd_I2cGetRxData
TEST.NEW
TEST.NAME:BacklightCdd_I2cGetRxData.001
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cGetRxData.val:<<malloc 1>>
TEST.END

-- Subprogram: BacklightCdd_I2cGetSeqResult

-- Test Case: BacklightCdd_I2cGetSeqResult.001
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightCdd_I2cGetSeqResult
TEST.NEW
TEST.NAME:BacklightCdd_I2cGetSeqResult.001
TEST.END

-- Test Case: BacklightCdd_I2cGetSeqResult.002
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightCdd_I2cGetSeqResult
TEST.NEW
TEST.NAME:BacklightCdd_I2cGetSeqResult.002
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.return:1
TEST.END

-- Subprogram: BacklightCdd_I2cWriteReg

-- Test Case: BacklightCdd_I2cWriteReg.001
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightCdd_I2cWriteReg
TEST.NEW
TEST.NAME:BacklightCdd_I2cWriteReg.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.Channel:1
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.TxBufferPtr:"abc"
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.RxBufferPtr:"abc"
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.return:1
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.reg:0
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.val:1
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.return:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightCdd_I2cWriteReg.002
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightCdd_I2cWriteReg
TEST.NEW
TEST.NAME:BacklightCdd_I2cWriteReg.002
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.Channel:1
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.TxBufferPtr:"abc"
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.RxBufferPtr:"abc"
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.return:1
TEST.VALUE:uut_prototype_stubs.I2c_AsyncTransmit.return:1
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].initSeq:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.reg:0
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.val:1
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.return:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END

-- Test Case: BacklightCdd_I2cWriteReg.003
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightCdd_I2cWriteReg
TEST.NEW
TEST.NAME:BacklightCdd_I2cWriteReg.003
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.Channel:1
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.TxBufferPtr:"abc"
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.RxBufferPtr:"abc"
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.return:0
TEST.VALUE:uut_prototype_stubs.I2c_AsyncTransmit.return:1
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].initSeq:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.reg:0
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.val:1
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.return:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END

-- Test Case: BacklightCdd_I2cWriteReg.004
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightCdd_I2cWriteReg
TEST.NEW
TEST.NAME:BacklightCdd_I2cWriteReg.004
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.Channel:1
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.TxBufferPtr:"abc"
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.RxBufferPtr:"abc"
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.return:0
TEST.VALUE:uut_prototype_stubs.I2c_AsyncTransmit.return:0
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].initSeq:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.reg:0
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.val:1
TEST.VALUE:BacklightDrvCdd_I2C.BacklightCdd_I2cWriteReg.return:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END

-- Subprogram: BacklightDrvCdd_ManageConfigRegI2CTransmission

-- Test Case: BacklightDrvCdd_ManageConfigRegI2CTransmission.001
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightDrvCdd_ManageConfigRegI2CTransmission
TEST.NEW
TEST.NAME:BacklightDrvCdd_ManageConfigRegI2CTransmission.001
TEST.STUB:BacklightDrvCdd_I2C.BacklightDrvCdd_Process_Set_Brightness
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightDrvCdd_Process_Set_Brightness.return:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightDrvCdd_ManageConfigRegI2CTransmission.002
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightDrvCdd_ManageConfigRegI2CTransmission
TEST.NEW
TEST.NAME:BacklightDrvCdd_ManageConfigRegI2CTransmission.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightDrvCdd_ManageConfigRegI2CTransmission.003
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightDrvCdd_ManageConfigRegI2CTransmission
TEST.NEW
TEST.NAME:BacklightDrvCdd_ManageConfigRegI2CTransmission.003
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.return:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightDrvCdd_ManageConfigRegI2CTransmission.004
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightDrvCdd_ManageConfigRegI2CTransmission
TEST.NEW
TEST.NAME:BacklightDrvCdd_ManageConfigRegI2CTransmission.004
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].initSeq:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg[0].data:"abc"
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.Sequence:0
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.return:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightDrvCdd_ManageConfigRegI2CTransmission.005
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightDrvCdd_ManageConfigRegI2CTransmission
TEST.NEW
TEST.NAME:BacklightDrvCdd_ManageConfigRegI2CTransmission.005
TEST.STUB:BacklightCdd_ErrorHandler.BacklightCdd_ReportError
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.Sequence:0
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.return:0
TEST.VALUE:BacklightDrvCdd_I2C.BacklightDrvCdd_ManageConfigRegI2CTransmission.return:BACKLIGHTCDD_INIT_REGCFG_SUCCESS
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightDrvCdd_ManageConfigRegI2CTransmission.006
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightDrvCdd_ManageConfigRegI2CTransmission
TEST.NEW
TEST.NAME:BacklightDrvCdd_ManageConfigRegI2CTransmission.006
TEST.STUB:BacklightCdd_ErrorHandler.BacklightCdd_ReportError
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.Sequence:1
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.return:1
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightChipHandler:<<malloc 2>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightDrvCdd_ManageConfigRegI2CTransmission.return:BACKLIGHTCDD_INIT_REGCFG_SUCCESS
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightDrvCdd_ManageConfigRegI2CTransmission.007
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightDrvCdd_ManageConfigRegI2CTransmission
TEST.NEW
TEST.NAME:BacklightDrvCdd_ManageConfigRegI2CTransmission.007
TEST.STUB:BacklightCdd_ErrorHandler.BacklightCdd_ReportError
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.Sequence:1
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.return:5
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightChipHandler:<<malloc 2>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightDrvCdd_ManageConfigRegI2CTransmission.return:BACKLIGHTCDD_INIT_REGCFG_SUCCESS
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightDrvCdd_ManageConfigRegI2CTransmission.008
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightDrvCdd_ManageConfigRegI2CTransmission
TEST.NEW
TEST.NAME:BacklightDrvCdd_ManageConfigRegI2CTransmission.008
TEST.STUB:BacklightDrvCdd_I2C.BacklightDrvCdd_Process_Set_Brightness
TEST.STUB:BacklightCdd_ErrorHandler.BacklightCdd_ReportError
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.Sequence:1
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.return:5
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightChipHandler:<<malloc 2>>
TEST.VALUE:BacklightDrvCdd_I2C.BacklightDrvCdd_Process_Set_Brightness.targetBrightness:0
TEST.VALUE:BacklightDrvCdd_I2C.BacklightDrvCdd_Process_Set_Brightness.return:0
TEST.VALUE:BacklightDrvCdd_I2C.BacklightDrvCdd_ManageConfigRegI2CTransmission.return:BACKLIGHTCDD_INIT_REGCFG_SUCCESS
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Subprogram: BacklightDrvCdd_Process_Set_Brightness

-- Test Case: BacklightDrvCdd_Process_Set_Brightness.001
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightDrvCdd_Process_Set_Brightness
TEST.NEW
TEST.NAME:BacklightDrvCdd_Process_Set_Brightness.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightDrvCdd_Process_Set_Brightness.002
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightDrvCdd_Process_Set_Brightness
TEST.NEW
TEST.NAME:BacklightDrvCdd_Process_Set_Brightness.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:uut_prototype_stubs.dummytest.return:1
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightChipHandler:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightChipHandler.BacklightChipHandler[0].CalcDutyRegisters
<<BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightChipHandler>>[0].CalcDutyRegisters = &dummytest;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Process_Set_Brightness.003
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightDrvCdd_Process_Set_Brightness
TEST.NEW
TEST.NAME:BacklightDrvCdd_Process_Set_Brightness.003
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:uut_prototype_stubs.dummytest.return:1
TEST.VALUE:uut_prototype_stubs.I2c_GetSequenceResult.return:1
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightChipHandler:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightChipHandler.BacklightChipHandler[0].CalcDutyRegisters
<<BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightChipHandler>>[0].CalcDutyRegisters = &dummytest;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Process_Set_Brightness.004
TEST.UNIT:BacklightDrvCdd_I2C
TEST.SUBPROGRAM:BacklightDrvCdd_Process_Set_Brightness
TEST.NEW
TEST.NAME:BacklightDrvCdd_Process_Set_Brightness.004
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:uut_prototype_stubs.dummytest.return:1
TEST.VALUE:uut_prototype_stubs.I2c_SetupEB.return:1
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightConfig.DeviceTable[0].I2cCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightChipHandler:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightChipHandler.BacklightChipHandler[0].CalcDutyRegisters
<<BacklightDrvCdd_I2C.<<GLOBAL>>.BacklightChipHandler>>[0].CalcDutyRegisters = &dummytest;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Unit: BacklightDrvCdd_I2C_MAX20446

-- Subprogram: BacklightDrvCdd_I2C_Init

-- Test Case: BacklightDrvCdd_I2C_Init.001
TEST.UNIT:BacklightDrvCdd_I2C_MAX20446
TEST.SUBPROGRAM:BacklightDrvCdd_I2C_Init
TEST.NEW
TEST.NAME:BacklightDrvCdd_I2C_Init.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: MAX20446_CalcDutyRegisters

-- Test Case: MAX20446_CalcDutyRegisters.001
TEST.UNIT:BacklightDrvCdd_I2C_MAX20446
TEST.SUBPROGRAM:MAX20446_CalcDutyRegisters
TEST.NEW
TEST.NAME:MAX20446_CalcDutyRegisters.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd_I2C_MAX20446.MAX20446_CalcDutyRegisters.txBuf:<<malloc 4>>
TEST.VALUE:BacklightDrvCdd_I2C_MAX20446.MAX20446_CalcDutyRegisters.txBuf:"abc"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Unit: Backlightcdd

-- Subprogram: BacklightCdd_DeInit

-- Test Case: BacklightCdd_DeInit.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_DeInit
TEST.NEW
TEST.NAME:BacklightCdd_DeInit.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightCdd_DeInit.002
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_DeInit
TEST.NEW
TEST.NAME:BacklightCdd_DeInit.002
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfDeInit
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfDeInit = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: BacklightCdd_Init

-- Test Case: BacklightCdd_Init.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_Init
TEST.NEW
TEST.NAME:BacklightCdd_Init.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightCdd_Init.002
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_Init
TEST.NEW
TEST.NAME:BacklightCdd_Init.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfInit
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfInit = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: BacklightCdd_MainFunction

-- Test Case: BacklightCdd_MainFunction.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfMainFunction
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfMainFunction = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightCdd_MainFunction.002
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.002
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfMainFunction
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfMainFunction = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: CBacklightCdd_EnterSafeState

-- Test Case: CBacklightCdd_EnterSafeState.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_EnterSafeState
TEST.NEW
TEST.NAME:CBacklightCdd_EnterSafeState.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: CBacklightCdd_EnterSafeState.002
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_EnterSafeState
TEST.NEW
TEST.NAME:CBacklightCdd_EnterSafeState.002
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfEnterSafeStatus
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfEnterSafeStatus = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: CBacklightCdd_ExitSafeState

-- Test Case: CBacklightCdd_ExitSafeState.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_ExitSafeState
TEST.NEW
TEST.NAME:CBacklightCdd_ExitSafeState.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CBacklightCdd_ExitSafeState.002
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_ExitSafeState
TEST.NEW
TEST.NAME:CBacklightCdd_ExitSafeState.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfExitSafeStatus
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfExitSafeStatus = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: CBacklightCdd_GetStatus

-- Test Case: CBacklightCdd_GetStatus.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_GetStatus
TEST.NEW
TEST.NAME:CBacklightCdd_GetStatus.001
TEST.STUB:Backlightcdd.CBacklightCdd_RequestPower
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.CBacklightCdd_RequestPower.deviceId:1
TEST.VALUE:Backlightcdd.CBacklightCdd_GetStatus.DeviceName:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CBacklightCdd_GetStatus.002
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_GetStatus
TEST.NEW
TEST.NAME:CBacklightCdd_GetStatus.002
TEST.STUB:Backlightcdd.CBacklightCdd_RequestPower
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:Backlightcdd.CBacklightCdd_RequestPower.deviceId:0
TEST.VALUE:Backlightcdd.CBacklightCdd_GetStatus.DeviceName:0
TEST.VALUE:Backlightcdd.CBacklightCdd_GetStatus.DeviceStatus:<<malloc 4>>
TEST.VALUE:Backlightcdd.CBacklightCdd_GetStatus.DeviceStatus:"abc"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfGetStatus
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfGetStatus = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: CBacklightCdd_RequestPower

-- Test Case: CBacklightCdd_RequestPower.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_RequestPower
TEST.NEW
TEST.NAME:CBacklightCdd_RequestPower.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CBacklightCdd_RequestPower.002
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_RequestPower
TEST.NEW
TEST.NAME:CBacklightCdd_RequestPower.002
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.VALUE:Backlightcdd.CBacklightCdd_RequestPower.deviceId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfRequestPower
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfRequestPower = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: CBacklightCdd_RequestPower.003
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_RequestPower
TEST.NEW
TEST.NAME:CBacklightCdd_RequestPower.003
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.VALUE:Backlightcdd.CBacklightCdd_RequestPower.deviceId:0
TEST.VALUE:Backlightcdd.CBacklightCdd_RequestPower.return:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfRequestPower
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfRequestPower = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: CBacklightCdd_SetBrightnessValue

-- Test Case: CBacklightCdd_SetBrightnessValue.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_SetBrightnessValue
TEST.NEW
TEST.NAME:CBacklightCdd_SetBrightnessValue.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: CBacklightCdd_SetBrightnessValue.002
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_SetBrightnessValue
TEST.NEW
TEST.NAME:CBacklightCdd_SetBrightnessValue.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfSetBrightness
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfSetBrightness = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: CBacklightCdd_SetBrightnessValue.003
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_SetBrightnessValue
TEST.NEW
TEST.NAME:CBacklightCdd_SetBrightnessValue.003
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.VALUE:Backlightcdd.CBacklightCdd_SetBrightnessValue.DeviceName:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfSetBrightness
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfSetBrightness = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Unit: CDD_Backlight

-- Subprogram: CBacklightCdd_Impl_MainFunction

-- Test Case: CBacklightCdd_Impl_MainFunction.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CBacklightCdd_Impl_MainFunction
TEST.NEW
TEST.NAME:CBacklightCdd_Impl_MainFunction.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CBacklightCdd_Impl_OnCommand

-- Test Case: CBacklightCdd_Impl_OnCommand.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CBacklightCdd_Impl_OnCommand
TEST.NEW
TEST.NAME:CBacklightCdd_Impl_OnCommand.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Subprogram: CmpActivation

-- Test Case: CmpActivation.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: CmpDeInit.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit.001
TEST.STUB:Backlightcdd.BacklightCdd_Init
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.VALUE:CDD_Backlight.CmpInit.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END
