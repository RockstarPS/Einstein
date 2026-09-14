-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : BACKLIGHTCDD_LP8867_VCAST_HT
-- Unit(s) Under Test: BacklightCdd_ErrorHandler BacklightDrvCdd Backlightcdd CDD_Backlight
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
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Unit: BacklightDrvCdd

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
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Subprogram: BacklightDrvCdd_ExitSafeState

-- Test Case: BacklightDrvCdd_ExitSafeState.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_ExitSafeState
TEST.NEW
TEST.NAME:BacklightDrvCdd_ExitSafeState.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: BacklightDrvCdd_GetStatus

-- Test Case: BacklightDrvCdd_GetStatus.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_GetStatus
TEST.NEW
TEST.NAME:BacklightDrvCdd_GetStatus.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_GetStatus.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Subprogram: BacklightDrvCdd_Init

-- Test Case: BacklightDrvCdd_Init.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Init
TEST.NEW
TEST.NAME:BacklightDrvCdd_Init.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: BacklightDrvCdd_Internal_MainFunction

-- Test Case: BacklightDrvCdd_Internal_MainFunction.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_IDLE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.002
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.002
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_PwmDutyInfo.LastDutyValue:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_ON
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_ON_WAIT
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.004
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.004
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_ON_WAIT
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_NORMAL
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_ON_WAIT
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_FAULTDIAG
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_FAULTDIAG
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_SAFETYREACTION
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERROR
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERROR
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERROR
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERRORRECOVERY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERRORRECOVERY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_SAFE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_PERMANENT_SAFESTATE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_FAULTDIAG
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.STUB:Backlightcdd.CBacklightCdd_EnterSafeState
TEST.STUB:Backlightcdd.CBacklightCdd_ExitSafeState
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:uut_prototype_stubs.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<uut_prototype_stubs.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_FAULTDIAG
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERROR
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERROR
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_OFF
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_NORMAL
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_FAULTDIAG
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_SAFETYREACTION
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERROR
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_SAFE
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_ERRORRECOVERY
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_Error_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_ErrorRecovery_RetryCounter:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultPin_DeBounceCounter:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.030
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.030
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_NORMAL
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:uut_prototype_stubs.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<uut_prototype_stubs.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &read_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:uut_prototype_stubs.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<uut_prototype_stubs.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_SafeStatus:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_NORMAL
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.032
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.032
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_NORMAL
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.return:0
TEST.VALUE:uut_prototype_stubs.EcuBatteryM_GetChannelStatus.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.VALUE:uut_prototype_stubs.EcuBatteryM_GetChannelStatus.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
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
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_SAFETYREACTION
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FaultDiag_DeBounceCounter:6
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.VALUE:uut_prototype_stubs.EcuBatteryM_GetChannelStatus.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.035
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.035
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_RequestPower
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_SetBrightness
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_EnterSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_ExitSafeState
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_NORMAL
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_PON_DelayCounter:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_FltMonDlyCntr:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:200
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg[0].Backlight_PwmId:1
TEST.VALUE:uut_prototype_stubs.EcuBatteryM_GetChannelStatus.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightDrvCdd_Internal_MainFunction.036
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_Internal_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_Internal_MainFunction.036
TEST.STUB:Backlightcdd.CBacklightCdd_SetBrightnessValue
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_PwmDutyInfo.LastDutyValue:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_POWER_ON
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable:<<malloc 1>>
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PowerOnDelayCnt:255
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightConfig.DeviceTable[0].PwmCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.EcuBatteryM_GetChannelStatus.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbReadChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbReadChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbWriteChannel
<<BacklightDrvCdd.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbWriteChannel = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: BacklightDrvCdd_IsFaultActive

-- Test Case: BacklightDrvCdd_IsFaultActive.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_IsFaultActive
TEST.NEW
TEST.NAME:BacklightDrvCdd_IsFaultActive.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.FltActLvl:BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_LOW
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightDrvCdd_IsFaultActive.002
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_IsFaultActive
TEST.NEW
TEST.NAME:BacklightDrvCdd_IsFaultActive.002
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.FltActLvl:BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_LOW
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_IsFaultActive.FaultSignal:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: BacklightDrvCdd_MainFunction

-- Test Case: BacklightDrvCdd_MainFunction.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightDrvCdd_MainFunction.001
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Internal_MainFunction
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: BacklightDrvCdd_RequestPower

-- Test Case: BacklightDrvCdd_RequestPower.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_RequestPower
TEST.NEW
TEST.NAME:BacklightDrvCdd_RequestPower.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: BacklightDrvCdd_SetBrightness

-- Test Case: BacklightDrvCdd_SetBrightness.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_SetBrightness
TEST.NEW
TEST.NAME:BacklightDrvCdd_SetBrightness.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: BacklightDrvCdd_UpdatePwmDuty

-- Test Case: BacklightDrvCdd_UpdatePwmDuty.001
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_UpdatePwmDuty
TEST.NEW
TEST.NAME:BacklightDrvCdd_UpdatePwmDuty.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightDrvCdd_UpdatePwmDuty.002
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_UpdatePwmDuty
TEST.NEW
TEST.NAME:BacklightDrvCdd_UpdatePwmDuty.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_PwmDutyInfo.CurrentDutyValue:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_PwmDutyInfo.LastDutyValue:3
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_OpState:BACKLIGHTDRVCDD_STATE_SAFETYREACTION
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty.io:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightDrvCdd_UpdatePwmDuty.003
TEST.UNIT:BacklightDrvCdd
TEST.SUBPROGRAM:BacklightDrvCdd_UpdatePwmDuty
TEST.NEW
TEST.NAME:BacklightDrvCdd_UpdatePwmDuty.003
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Init
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_DeInit
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_GetStatus
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_MainFunction
TEST.STUB:BacklightDrvCdd.BacklightDrvCdd_Internal_MainFunction
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_PwmDutyInfo.CurrentDutyValue:5
TEST.VALUE:BacklightDrvCdd.<<GLOBAL>>.BacklightDrvCdd_PwmDutyInfo.LastDutyValue:3
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_GetStatus.deviceId:1
TEST.VALUE:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty.io:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty.io.io[0].IoHwAbSetDuty
<<BacklightDrvCdd.BacklightDrvCdd_UpdatePwmDuty.io>>[0].IoHwAbSetDuty = &write_channel;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:uut_prototype_stubs.<<GLOBAL>>.BacklightCdd_IOTable.IoHwAbSetDuty
<<uut_prototype_stubs.<<GLOBAL>>.BacklightCdd_IOTable>>.IoHwAbSetDuty = &write_channel;
TEST.END_VALUE_USER_CODE:
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
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfDeInit = ( write_channel );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: BacklightCdd_Init

-- Test Case: BacklightCdd_Init.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_Init
TEST.NEW
TEST.NAME:BacklightCdd_Init.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfInit
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfInit = ( write_channel );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightCdd_Init.002
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_Init
TEST.NEW
TEST.NAME:BacklightCdd_Init.002
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: BacklightCdd_MainFunction

-- Test Case: BacklightCdd_MainFunction.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.002
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.002
TEST.STUB:Backlightcdd.BacklightCdd_Init
TEST.STUB:Backlightcdd.BacklightCdd_DeInit
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfInit
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfInit = ( write_channel );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BacklightCdd_MainFunction.003
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.003
TEST.STUB:Backlightcdd.BacklightCdd_Init
TEST.STUB:Backlightcdd.BacklightCdd_DeInit
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.004
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.004
TEST.STUB:Backlightcdd.BacklightCdd_Init
TEST.STUB:Backlightcdd.BacklightCdd_DeInit
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.005
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.005
TEST.STUB:Backlightcdd.BacklightCdd_Init
TEST.STUB:Backlightcdd.BacklightCdd_DeInit
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.006
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.006
TEST.STUB:Backlightcdd.BacklightCdd_Init
TEST.STUB:Backlightcdd.BacklightCdd_DeInit
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.007
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.007
TEST.STUB:Backlightcdd.BacklightCdd_Init
TEST.STUB:Backlightcdd.BacklightCdd_DeInit
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.008
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.008
TEST.STUB:Backlightcdd.BacklightCdd_Init
TEST.STUB:Backlightcdd.BacklightCdd_DeInit
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.009
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.009
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.010
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.010
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.011
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.011
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.012
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.012
TEST.COMPOUND_ONLY
TEST.STUB:Backlightcdd.BacklightCdd_Init
TEST.STUB:Backlightcdd.BacklightCdd_DeInit
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.013
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.013
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.014
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.014
TEST.STUB:Backlightcdd.BacklightCdd_Init
TEST.STUB:Backlightcdd.BacklightCdd_DeInit
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.015
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.015
TEST.STUB:Backlightcdd.BacklightCdd_Init
TEST.STUB:Backlightcdd.BacklightCdd_DeInit
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.016
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.016
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.017
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.017
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.018
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.018
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.019
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.019
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.020
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.020
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END

-- Test Case: BacklightCdd_MainFunction.021
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:BacklightCdd_MainFunction
TEST.NEW
TEST.NAME:BacklightCdd_MainFunction.021
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfMainFunction
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfMainFunction = ( write_channel );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: CBacklightCdd_EnterSafeState

-- Test Case: CBacklightCdd_EnterSafeState.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_EnterSafeState
TEST.NEW
TEST.NAME:CBacklightCdd_EnterSafeState.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CBacklightCdd_EnterSafeState.002
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_EnterSafeState
TEST.NEW
TEST.NAME:CBacklightCdd_EnterSafeState.002
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfEnterSafeStatus
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfEnterSafeStatus = ( write_channel );
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
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfExitSafeStatus
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfExitSafeStatus = ( write_channel );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: CBacklightCdd_GetStatus

-- Test Case: CBacklightCdd_GetStatus.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_GetStatus
TEST.NEW
TEST.NAME:CBacklightCdd_GetStatus.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.VALUE:Backlightcdd.CBacklightCdd_GetStatus.DeviceName:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfGetStatus
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfGetStatus = ( write_channel );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: CBacklightCdd_GetStatus.002
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_GetStatus
TEST.NEW
TEST.NAME:CBacklightCdd_GetStatus.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.VALUE:Backlightcdd.CBacklightCdd_GetStatus.DeviceStatus:<<malloc 4>>
TEST.VALUE:Backlightcdd.CBacklightCdd_GetStatus.DeviceStatus:"abc"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfGetStatus
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfGetStatus = ( write_channel );
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
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfRequestPower
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfRequestPower = ( write_channel );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: CBacklightCdd_RequestPower.003
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_RequestPower
TEST.NEW
TEST.NAME:CBacklightCdd_RequestPower.003
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.VALUE:Backlightcdd.CBacklightCdd_RequestPower.deviceId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfRequestPower
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfRequestPower = ( write_channel );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: CBacklightCdd_RequestPower.004
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_RequestPower
TEST.NEW
TEST.NAME:CBacklightCdd_RequestPower.004
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.VALUE:Backlightcdd.CBacklightCdd_RequestPower.state:7
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfRequestPower
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfRequestPower = ( write_channel );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: CBacklightCdd_SetBrightnessValue

-- Test Case: CBacklightCdd_SetBrightnessValue.001
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_SetBrightnessValue
TEST.NEW
TEST.NAME:CBacklightCdd_SetBrightnessValue.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END

-- Test Case: CBacklightCdd_SetBrightnessValue.003
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_SetBrightnessValue
TEST.NEW
TEST.NAME:CBacklightCdd_SetBrightnessValue.003
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfSetBrightness
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfSetBrightness = ( write_channel );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: CBacklightCdd_SetBrightnessValue.004
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_SetBrightnessValue
TEST.NEW
TEST.NAME:CBacklightCdd_SetBrightnessValue.004
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.VALUE:Backlightcdd.CBacklightCdd_SetBrightnessValue.DeviceName:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:1
TEST.END

-- Test Case: CBacklightCdd_SetBrightnessValue.005
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_SetBrightnessValue
TEST.NEW
TEST.NAME:CBacklightCdd_SetBrightnessValue.005
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfSetBrightness
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfSetBrightness = ( write_channel );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: CBacklightCdd_SetBrightnessValue.006
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_SetBrightnessValue
TEST.NEW
TEST.NAME:CBacklightCdd_SetBrightnessValue.006
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfSetBrightness
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfSetBrightness = ( write_channel );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: CBacklightCdd_SetBrightnessValue.007
TEST.UNIT:Backlightcdd
TEST.SUBPROGRAM:CBacklightCdd_SetBrightnessValue
TEST.NEW
TEST.NAME:CBacklightCdd_SetBrightnessValue.007
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Backlightcdd.<<GLOBAL>>.BacklightCdd_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE_USER_CODE:Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable.pfSetBrightness
<<Backlightcdd.<<GLOBAL>>.BacklightCdd_DrvTable>>.pfSetBrightness = ( write_channel );
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
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
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
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT3:1
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit.001
TEST.UNIT:CDD_Backlight
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit.001
TEST.STUB:Backlightcdd.BacklightCdd_Init
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CDD_Backlight.CmpInit.return:244
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.001
TEST.SLOT: "1", "Backlightcdd", "BacklightCdd_MainFunction", "5", "BacklightCdd_MainFunction.012"
TEST.END
--
