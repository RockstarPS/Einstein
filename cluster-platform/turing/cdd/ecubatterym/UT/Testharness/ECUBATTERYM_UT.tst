-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : ECUBATTERYM_UT
-- Unit(s) Under Test: CDD_EcuBatteryM CDD_EcuBatteryM_ErrorHandler EcuBatteryM
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CDD_EcuBatteryM

-- Subprogram: CCDD_EcuBatteryM_Impl_MainFunction

-- Test Case: CCDD_EcuBatteryM_Impl_MainFunction.001
TEST.UNIT:CDD_EcuBatteryM
TEST.SUBPROGRAM:CCDD_EcuBatteryM_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_EcuBatteryM_Impl_MainFunction.001
TEST.END

-- Subprogram: CCDD_EcuBatteryM_Impl_OnCommand

-- Test Case: CCDD_EcuBatteryM_Impl_OnCommand.001
TEST.UNIT:CDD_EcuBatteryM
TEST.SUBPROGRAM:CCDD_EcuBatteryM_Impl_OnCommand
TEST.NEW
TEST.NAME:CCDD_EcuBatteryM_Impl_OnCommand.001
TEST.END

-- Subprogram: CmpActivation

-- Test Case: CmpActivation.001
TEST.UNIT:CDD_EcuBatteryM
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation.001
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive.001
TEST.UNIT:CDD_EcuBatteryM
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.001
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation.001
TEST.UNIT:CDD_EcuBatteryM
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation.001
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: CmpDeInit.001
TEST.UNIT:CDD_EcuBatteryM
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit.001
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag.001
TEST.UNIT:CDD_EcuBatteryM
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag.001
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn.001
TEST.UNIT:CDD_EcuBatteryM
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn.001
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit.001
TEST.UNIT:CDD_EcuBatteryM
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit.001
TEST.END

-- Unit: CDD_EcuBatteryM_ErrorHandler

-- Subprogram: EcuBatteryM_ReportError

-- Test Case: EcuBatteryM_ReportError.001
TEST.UNIT:CDD_EcuBatteryM_ErrorHandler
TEST.SUBPROGRAM:EcuBatteryM_ReportError
TEST.NEW
TEST.NAME:EcuBatteryM_ReportError.001
TEST.END

-- Unit: EcuBatteryM

-- Subprogram: EcuBatteryM_DeInit

-- Test Case: EcuBatteryM_DeInit.001
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_DeInit
TEST.NEW
TEST.NAME:EcuBatteryM_DeInit.001
TEST.STUB:EcuBatteryM.EcuBatteryM_SetMonitoringState
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_INITIALIZED
TEST.VALUE:EcuBatteryM.EcuBatteryM_SetMonitoringState.channel:9
TEST.END

-- Test Case: EcuBatteryM_DeInit.002
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_DeInit
TEST.NEW
TEST.NAME:EcuBatteryM_DeInit.002
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_UNINITIALIZED
TEST.EXPECTED:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_UNINITIALIZED
TEST.END

-- Subprogram: EcuBatteryM_GetChannelRawStatus

-- Test Case: EcuBatteryM_GetChannelRawStatus.001
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_GetChannelRawStatus
TEST.NEW
TEST.NAME:EcuBatteryM_GetChannelRawStatus.001
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_UNINITIALIZED
TEST.END

-- Test Case: EcuBatteryM_GetChannelRawStatus.002
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_GetChannelRawStatus
TEST.NEW
TEST.NAME:EcuBatteryM_GetChannelRawStatus.002
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetChannelRawStatus.channel:10
TEST.END

-- Test Case: EcuBatteryM_GetChannelRawStatus.003
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_GetChannelRawStatus
TEST.NEW
TEST.NAME:EcuBatteryM_GetChannelRawStatus.003
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetChannelRawStatus.channel:1
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetChannelRawStatus.status:<<malloc 5>>
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetChannelRawStatus.status:"E_OK"
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetChannelRawStatus.return:0
TEST.END

-- Subprogram: EcuBatteryM_GetChannelStatus

-- Test Case: EcuBatteryM_GetChannelStatus.001
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_GetChannelStatus
TEST.NEW
TEST.NAME:EcuBatteryM_GetChannelStatus.001
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetChannelStatus.status:<<malloc 1>>
TEST.END

-- Test Case: EcuBatteryM_GetChannelStatus.002
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_GetChannelStatus
TEST.NEW
TEST.NAME:EcuBatteryM_GetChannelStatus.002
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_UNINITIALIZED
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetChannelStatus.status:<<malloc 1>>
TEST.EXPECTED:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_UNINITIALIZED
TEST.END

-- Test Case: EcuBatteryM_GetChannelStatus.003
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_GetChannelStatus
TEST.NEW
TEST.NAME:EcuBatteryM_GetChannelStatus.003
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetChannelStatus.channel:9
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetChannelStatus.status:<<malloc 1>>
TEST.EXPECTED:EcuBatteryM.EcuBatteryM_GetChannelStatus.channel:9
TEST.END

-- Subprogram: EcuBatteryM_GetThresholdAndHystValues

-- Test Case: EcuBatteryM_GetThresholdAndHystValues.001
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_GetThresholdAndHystValues
TEST.NEW
TEST.NAME:EcuBatteryM_GetThresholdAndHystValues.001
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.channel:10
TEST.END

-- Test Case: EcuBatteryM_GetThresholdAndHystValues.002
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_GetThresholdAndHystValues
TEST.NEW
TEST.NAME:EcuBatteryM_GetThresholdAndHystValues.002
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.thresholdType:4
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.threshold:<<null>>
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.hysteresis:<<null>>
TEST.END

-- Test Case: EcuBatteryM_GetThresholdAndHystValues.003
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_GetThresholdAndHystValues
TEST.NEW
TEST.NAME:EcuBatteryM_GetThresholdAndHystValues.003
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.channel:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.thresholdType:ECUBATTERYM_THRESHOLD_TYPE_ON
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.threshold:<<malloc 1>>
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.threshold[0]:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.hysteresis:<<malloc 1>>
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.hysteresis[0]:0
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].OnThresholdValueApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].OnThresholdValueApi = ( &dummy );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].OnHysteresisValueApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].OnHysteresisValueApi = ( &dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_GetThresholdAndHystValues.004
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_GetThresholdAndHystValues
TEST.NEW
TEST.NAME:EcuBatteryM_GetThresholdAndHystValues.004
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.channel:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.thresholdType:ECUBATTERYM_THRESHOLD_TYPE_OFF
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.threshold:<<malloc 1>>
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.threshold[0]:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.hysteresis:<<malloc 1>>
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.hysteresis[0]:0
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].OffThresholdValueApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].OffThresholdValueApi = ( &dummy
 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].OffHysteresisValueApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].OffHysteresisValueApi = ( &dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EcuBatteryM_Init

-- Test Case: EcuBatteryM_Init.001
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_Init
TEST.NEW
TEST.NAME:EcuBatteryM_Init.001
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_UNINITIALIZED
TEST.END

-- Test Case: EcuBatteryM_Init.002
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_Init
TEST.NEW
TEST.NAME:EcuBatteryM_Init.002
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_INITIALIZED
TEST.EXPECTED:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_INITIALIZED
TEST.END

-- Test Case: EcuBatteryM_Init.003
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_Init
TEST.NEW
TEST.NAME:EcuBatteryM_Init.003
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_UNINITIALIZED
TEST.END

-- Subprogram: EcuBatteryM_MonitorChannel

-- Test Case: EcuBatteryM_MonitorChannel.001
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.001
TEST.VALUE:EcuBatteryM.EcuBatteryM_MonitorChannel.channel:2
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.002
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.002
TEST.STUB:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].monitorState:TRUE
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_HIGH
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].hwid:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_MonitorChannel.channel:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.threshold[0]:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.hysteresis[0]:4
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.003
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.003
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_INVALID
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.004
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.004
TEST.STUB:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_LOW
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.threshold[0]:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.hysteresis[0]:1
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.005
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.005
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_PGOOD
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].offThreshold:0
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.006
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.006
TEST.VALUE:uut_prototype_stubs.Dio_ReadChannel.return:1
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_HIGH
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.007
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.007
TEST.VALUE:uut_prototype_stubs.Dio_ReadChannel.return:1
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_HIGH
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFF
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.008
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.008
TEST.VALUE:uut_prototype_stubs.Dio_ReadChannel.return:1
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_HIGH
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFF
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].offThreshold:0xFFFF
TEST.EXPECTED:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].offThreshold:0xFFFF
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.009
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.009
TEST.VALUE:uut_prototype_stubs.Dio_ReadChannel.return:1
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_HIGH
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].onThreshold:0xFFFF
TEST.EXPECTED:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].onThreshold:0xFFFF
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.010
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.010
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_LOW
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFF
TEST.ATTRIBUTES:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.011
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.011
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_LOW
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFF
TEST.ATTRIBUTES:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.012
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.012
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_LOW
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFF
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].offThreshold:0xFF
TEST.ATTRIBUTES:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.013
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.013
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_LOW
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFF
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].onThreshold:0xFF
TEST.EXPECTED:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].onThreshold:0xFF
TEST.ATTRIBUTES:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.014
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.014
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_PGOOD
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFF
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.015
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.015
TEST.VALUE:uut_prototype_stubs.dummy.return:10
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_PGOOD
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFF
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].offThreshold:0
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.016
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.016
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_PGOOD
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFF
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].offThreshold:0xFF
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.017
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.017
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_PGOOD
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFF
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].onThreshold:0xFFFF
TEST.EXPECTED:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].onThreshold:0xFFFF
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &dummy;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.018
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.018
TEST.VALUE:uut_prototype_stubs.dummy.return:255
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.019
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.019
TEST.STUB:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[1].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[2].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_HIGH
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[1].monitoringType:ECUBATTERYM_MONITORING_TYPE_HIGH
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[2].monitoringType:ECUBATTERYM_MONITORING_TYPE_HIGH
TEST.VALUE:EcuBatteryM.EcuBatteryM_MonitorChannel.channel:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.threshold[0]:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.hysteresis[0]:4
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = ( &dummy );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[1].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[1].VoltageSourceApi = ( &dummy
 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[2].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[2].VoltageSourceApi = ( &dummy
 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.020
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.020
TEST.STUB:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:uut_prototype_stubs.Dummy_VoltageSourceApi.error[0]:11
TEST.VALUE:uut_prototype_stubs.Dummy_VoltageSourceApi.return:0
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[1].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[2].state:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_HIGH
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[1].monitoringType:ECUBATTERYM_MONITORING_TYPE_HIGH
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[2].monitoringType:ECUBATTERYM_MONITORING_TYPE_HIGH
TEST.VALUE:EcuBatteryM.EcuBatteryM_MonitorChannel.channel:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.threshold[0]:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_GetThresholdAndHystValues.hysteresis[0]:4
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = ( &Dummy_VoltageSourceApi );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[1].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[1].VoltageSourceApi = ( &dummy
 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[2].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[2].VoltageSourceApi = ( &dummy
 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.021
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.021
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:uut_prototype_stubs.Dummy_VoltageSourceApi.error[0]:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_LOW
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFF
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].onThreshold:0xFF
TEST.EXPECTED:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].onThreshold:0xFF
TEST.ATTRIBUTES:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &Dummy_VoltageSourceApi;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuBatteryM_MonitorChannel.022
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannel
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannel.022
TEST.VALUE:uut_prototype_stubs.dummy.return:2
TEST.VALUE:uut_prototype_stubs.Dummy_VoltageSourceApi.error[0]:1
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].monitoringType:ECUBATTERYM_MONITORING_TYPE_PGOOD
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFF
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].onThreshold:0xFFFF
TEST.EXPECTED:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].onThreshold:0xFFFF
TEST.VALUE_USER_CODE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData.EcuBatteryM_ChannelConfigData[0].VoltageSourceApi
<<EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData>>[0].VoltageSourceApi = &Dummy_VoltageSourceApi;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EcuBatteryM_MonitorChannels

-- Test Case: EcuBatteryM_MonitorChannels.001
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannels
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannels.001
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_UNINITIALIZED
TEST.END

-- Test Case: EcuBatteryM_MonitorChannels.002
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_MonitorChannels
TEST.NEW
TEST.NAME:EcuBatteryM_MonitorChannels.002
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_INITIALIZED
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].monitorDelayTimer:0
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].monitorState:TRUE
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[1].monitorDelayTimer:20
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[1].monitorState:TRUE
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[2].monitorDelayTimer:0
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[2].monitorState:TRUE
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enableid:0xFFFF
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[0].enablePolarity:ECUBATTERYM_POLARITY_TYPE_LOW
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[1].enableid:0x0
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[1].enablePolarity:260
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[1].monitorDelayTime:20
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[2].enableid:0xFFFF
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelConfigData[2].enablePolarity:260
TEST.END

-- Subprogram: EcuBatteryM_ProcessDebounce

-- Test Case: EcuBatteryM_ProcessDebounce.001
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_ProcessDebounce
TEST.NEW
TEST.NAME:EcuBatteryM_ProcessDebounce.001
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDebounce.debounceCounter:<<malloc 1>>
TEST.END

-- Test Case: EcuBatteryM_ProcessDebounce.002
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_ProcessDebounce
TEST.NEW
TEST.NAME:EcuBatteryM_ProcessDebounce.002
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDebounce.conditionMet:1
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDebounce.state:<<malloc 1>>
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDebounce.debounceCounter:<<malloc 1>>
TEST.EXPECTED:EcuBatteryM.EcuBatteryM_ProcessDebounce.conditionMet:1
TEST.END

-- Test Case: EcuBatteryM_ProcessDebounce.003
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_ProcessDebounce
TEST.NEW
TEST.NAME:EcuBatteryM_ProcessDebounce.003
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDebounce.conditionMet:1
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDebounce.state:<<malloc 1>>
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDebounce.debounceCounter:<<malloc 1>>
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDebounce.debounceLimit:3
TEST.EXPECTED:EcuBatteryM.EcuBatteryM_ProcessDebounce.conditionMet:1
TEST.END

-- Test Case: EcuBatteryM_ProcessDebounce.004
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_ProcessDebounce
TEST.NEW
TEST.NAME:EcuBatteryM_ProcessDebounce.004
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDebounce.conditionMet:1
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDebounce.state:<<malloc 1>>
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDebounce.state[0]:1
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDebounce.debounceCounter:<<malloc 1>>
TEST.EXPECTED:EcuBatteryM.EcuBatteryM_ProcessDebounce.conditionMet:1
TEST.END

-- Subprogram: EcuBatteryM_ProcessDelayTime

-- Test Case: EcuBatteryM_ProcessDelayTime.001
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_ProcessDelayTime
TEST.NEW
TEST.NAME:EcuBatteryM_ProcessDelayTime.001
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDelayTime.channel:2
TEST.END

-- Test Case: EcuBatteryM_ProcessDelayTime.002
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_ProcessDelayTime
TEST.NEW
TEST.NAME:EcuBatteryM_ProcessDelayTime.002
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_ChannelState[0].monitorDelayTimer:10
TEST.VALUE:EcuBatteryM.EcuBatteryM_ProcessDelayTime.channel:0
TEST.END

-- Subprogram: EcuBatteryM_SetMonitoringState

-- Test Case: EcuBatteryM_SetMonitoringState.001
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_SetMonitoringState
TEST.NEW
TEST.NAME:EcuBatteryM_SetMonitoringState.001
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_UNINITIALIZED
TEST.END

-- Test Case: EcuBatteryM_SetMonitoringState.002
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_SetMonitoringState
TEST.NEW
TEST.NAME:EcuBatteryM_SetMonitoringState.002
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_INITIALIZED
TEST.VALUE:EcuBatteryM.EcuBatteryM_SetMonitoringState.channel:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_SetMonitoringState.state:TRUE
TEST.END

-- Test Case: EcuBatteryM_SetMonitoringState.003
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_SetMonitoringState
TEST.NEW
TEST.NAME:EcuBatteryM_SetMonitoringState.003
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_INITIALIZED
TEST.VALUE:EcuBatteryM.EcuBatteryM_SetMonitoringState.channel:0
TEST.VALUE:EcuBatteryM.EcuBatteryM_SetMonitoringState.state:FALSE
TEST.END

-- Test Case: EcuBatteryM_SetMonitoringState.004
TEST.UNIT:EcuBatteryM
TEST.SUBPROGRAM:EcuBatteryM_SetMonitoringState
TEST.NEW
TEST.NAME:EcuBatteryM_SetMonitoringState.004
TEST.VALUE:EcuBatteryM.<<GLOBAL>>.EcuBatteryM_InitStatus:ECUBATTERYM_S_INITIALIZED
TEST.VALUE:EcuBatteryM.EcuBatteryM_SetMonitoringState.channel:10
TEST.VALUE:EcuBatteryM.EcuBatteryM_SetMonitoringState.state:FALSE
TEST.END
