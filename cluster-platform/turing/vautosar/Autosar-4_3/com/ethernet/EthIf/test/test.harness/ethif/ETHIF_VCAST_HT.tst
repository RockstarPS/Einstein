-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : ETHIF_VCAST_HT
-- Unit(s) Under Test: EthIf
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: EthIf

-- Subprogram: EthIf_CheckWakeup

-- Test Case: EthIf_CheckWakeup.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_CheckWakeup
TEST.NEW
TEST.NAME:EthIf_CheckWakeup.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_CheckWakeup.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_CHECKWAKEUP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_CheckWakeup.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_CheckWakeup
TEST.NEW
TEST.NAME:EthIf_CheckWakeup.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.EXPECTED:EthIf.EthIf_CheckWakeup.return:E_OK
TEST.END

-- Subprogram: EthIf_CtrlModeIndication

-- Test Case: EthIf_CtrlModeIndication.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_CtrlModeIndication
TEST.NEW
TEST.NAME:EthIf_CtrlModeIndication.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_CTRLMODEINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_CtrlModeIndication.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_CtrlModeIndication
TEST.NEW
TEST.NAME:EthIf_CtrlModeIndication.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_CtrlModeIndication.CtrlIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_CTRLMODEINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_CtrlModeIndication.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_CtrlModeIndication
TEST.NEW
TEST.NAME:EthIf_CtrlModeIndication.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_CtrlModeIndication.CtrlIdx:0
TEST.EXPECTED:uut_prototype_stubs.EthSM_CtrlModeIndication.CtrlIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_EnableEgressTimeStamp

-- Test Case: EthIf_EnableEgressTimeStamp.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_EnableEgressTimeStamp
TEST.NEW
TEST.NAME:EthIf_EnableEgressTimeStamp.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_ENABLEEGRESSTIMESTAMP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_EnableEgressTimeStamp.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_EnableEgressTimeStamp
TEST.NEW
TEST.NAME:EthIf_EnableEgressTimeStamp.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_EnableEgressTimeStamp.CtrlIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_ENABLEEGRESSTIMESTAMP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_EnableEgressTimeStamp.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_EnableEgressTimeStamp
TEST.NEW
TEST.NAME:EthIf_EnableEgressTimeStamp.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_EnableEgressTimeStamp.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_EnableEgressTimeStamp.BufIdx:1
TEST.EXPECTED:uut_prototype_stubs.Eth_EnableEgressTimeStamp.CtrlIdx:0
TEST.EXPECTED:uut_prototype_stubs.Eth_EnableEgressTimeStamp.BufIdx:1
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_GetAndResetMeasurementData

-- Test Case: EthIf_GetAndResetMeasurementData.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetAndResetMeasurementData
TEST.NEW
TEST.NAME:EthIf_GetAndResetMeasurementData.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_GetAndResetMeasurementData.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETANDRESETMEASUREMENTDATA_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetAndResetMeasurementData.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetAndResetMeasurementData
TEST.NEW
TEST.NAME:EthIf_GetAndResetMeasurementData.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.EthIf_GetAndResetMeasurementData.MeasurementDataPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetAndResetMeasurementData.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETANDRESETMEASUREMENTDATA_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.END

-- Test Case: EthIf_GetAndResetMeasurementData.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetAndResetMeasurementData
TEST.NEW
TEST.NAME:EthIf_GetAndResetMeasurementData.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.EthIf_GetAndResetMeasurementData.MeasurementDataPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_GetAndResetMeasurementData.return:E_OK
TEST.END

-- Subprogram: EthIf_GetBufferLevel

-- Test Case: EthIf_GetBufferLevel.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetBufferLevel
TEST.NEW
TEST.NAME:EthIf_GetBufferLevel.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_GetBufferLevel.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETBUFLEVEL_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetBufferLevel.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetBufferLevel
TEST.NEW
TEST.NAME:EthIf_GetBufferLevel.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfSwitchCount:1
TEST.VALUE:EthIf.EthIf_GetBufferLevel.SwitchIdx:1
TEST.EXPECTED:EthIf.EthIf_GetBufferLevel.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETBUFLEVEL_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_SWT_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetBufferLevel.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetBufferLevel
TEST.NEW
TEST.NAME:EthIf_GetBufferLevel.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfSwitchCount:1
TEST.VALUE:EthIf.EthIf_GetBufferLevel.SwitchIdx:0
TEST.VALUE:EthIf.EthIf_GetBufferLevel.SwitchBufferLevelPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetBufferLevel.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETBUFLEVEL_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetBufferLevel.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetBufferLevel
TEST.NEW
TEST.NAME:EthIf_GetBufferLevel.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfSwitchCount:1
TEST.VALUE:EthIf.EthIf_GetBufferLevel.SwitchIdx:0
TEST.VALUE:EthIf.EthIf_GetBufferLevel.SwitchBufferLevelPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_GetBufferLevel.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_GetControllerMode

-- Test Case: EthIf_GetControllerMode.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetControllerMode
TEST.NEW
TEST.NAME:EthIf_GetControllerMode.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_GetControllerMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETCTRLMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetControllerMode.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetControllerMode
TEST.NEW
TEST.NAME:EthIf_GetControllerMode.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetControllerMode.CtrlIdx:1
TEST.EXPECTED:EthIf.EthIf_GetControllerMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETCTRLMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.END

-- Test Case: EthIf_GetControllerMode.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetControllerMode
TEST.NEW
TEST.NAME:EthIf_GetControllerMode.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetControllerMode.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetControllerMode.CtrlModePtr:<<malloc 9>>
TEST.VALUE:EthIf.EthIf_GetControllerMode.CtrlModePtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetControllerMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETCTRLMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.END

-- Test Case: EthIf_GetControllerMode.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetControllerMode
TEST.NEW
TEST.NAME:EthIf_GetControllerMode.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetControllerMode.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetControllerMode.CtrlModePtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_GetControllerMode.return:E_OK
TEST.END

-- Subprogram: EthIf_GetCtrlIdxList

-- Test Case: EthIf_GetCtrlIdxList.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetCtrlIdxList
TEST.NEW
TEST.NAME:EthIf_GetCtrlIdxList.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_GetCtrlIdxList.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETCTRLIDXLIST_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetCtrlIdxList.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetCtrlIdxList
TEST.NEW
TEST.NAME:EthIf_GetCtrlIdxList.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.EthIf_GetCtrlIdxList.NumberOfCtrlIdx:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetCtrlIdxList.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETCTRLIDXLIST_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.END

-- Test Case: EthIf_GetCtrlIdxList.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetCtrlIdxList
TEST.NEW
TEST.NAME:EthIf_GetCtrlIdxList.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.EthIf_GetCtrlIdxList.NumberOfCtrlIdx:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetCtrlIdxList.CtrlIdxListPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetCtrlIdxList.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETCTRLIDXLIST_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.END

-- Test Case: EthIf_GetCtrlIdxList.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetCtrlIdxList
TEST.NEW
TEST.NAME:EthIf_GetCtrlIdxList.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.EthIf_GetCtrlIdxList.NumberOfCtrlIdx:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetCtrlIdxList.CtrlIdxListPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_GetCtrlIdxList.return:E_OK
TEST.END

-- Subprogram: EthIf_GetCurrentTime

-- Test Case: EthIf_GetCurrentTime.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetCurrentTime
TEST.NEW
TEST.NAME:EthIf_GetCurrentTime.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_GetCurrentTime.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETCURRENTTIME_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetCurrentTime.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetCurrentTime
TEST.NEW
TEST.NAME:EthIf_GetCurrentTime.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetCurrentTime.CtrlIdx:1
TEST.EXPECTED:EthIf.EthIf_GetCurrentTime.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETCURRENTTIME_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetCurrentTime.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetCurrentTime
TEST.NEW
TEST.NAME:EthIf_GetCurrentTime.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetCurrentTime.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetCurrentTime.timeQualPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetCurrentTime.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETCURRENTTIME_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetCurrentTime.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetCurrentTime
TEST.NEW
TEST.NAME:EthIf_GetCurrentTime.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetCurrentTime.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetCurrentTime.timeQualPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetCurrentTime.timeStampPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetCurrentTime.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETCURRENTTIME_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetCurrentTime.005
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetCurrentTime
TEST.NEW
TEST.NAME:EthIf_GetCurrentTime.005
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetCurrentTime.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetCurrentTime.timeQualPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetCurrentTime.timeStampPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_GetCurrentTime.return:E_OK
TEST.EXPECTED:uut_prototype_stubs.Eth_GetCurrentTime.CtrlIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_GetDropCount

-- Test Case: EthIf_GetDropCount.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetDropCount
TEST.NEW
TEST.NAME:EthIf_GetDropCount.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_GetDropCount.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETDROPCOUNT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetDropCount.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetDropCount
TEST.NEW
TEST.NAME:EthIf_GetDropCount.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfSwitchCount:1
TEST.VALUE:EthIf.EthIf_GetDropCount.SwitchIdx:1
TEST.EXPECTED:EthIf.EthIf_GetDropCount.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETDROPCOUNT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_SWT_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetDropCount.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetDropCount
TEST.NEW
TEST.NAME:EthIf_GetDropCount.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfSwitchCount:1
TEST.VALUE:EthIf.EthIf_GetDropCount.SwitchIdx:0
TEST.VALUE:EthIf.EthIf_GetDropCount.DropCount:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetDropCount.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETDROPCOUNT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetDropCount.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetDropCount
TEST.NEW
TEST.NAME:EthIf_GetDropCount.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfSwitchCount:1
TEST.VALUE:EthIf.EthIf_GetDropCount.SwitchIdx:0
TEST.VALUE:EthIf.EthIf_GetDropCount.DropCount:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_GetDropCount.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_GetEgressTimeStamp

-- Test Case: EthIf_GetEgressTimeStamp.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetEgressTimeStamp
TEST.NEW
TEST.NAME:EthIf_GetEgressTimeStamp.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETEGRESSTIMESTAMP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetEgressTimeStamp.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetEgressTimeStamp
TEST.NEW
TEST.NAME:EthIf_GetEgressTimeStamp.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetEgressTimeStamp.CtrlIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETEGRESSTIMESTAMP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetEgressTimeStamp.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetEgressTimeStamp
TEST.NEW
TEST.NAME:EthIf_GetEgressTimeStamp.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetEgressTimeStamp.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetEgressTimeStamp.timeQualPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETEGRESSTIMESTAMP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetEgressTimeStamp.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetEgressTimeStamp
TEST.NEW
TEST.NAME:EthIf_GetEgressTimeStamp.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetEgressTimeStamp.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetEgressTimeStamp.timeQualPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetEgressTimeStamp.timeStampPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETEGRESSTIMESTAMP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetEgressTimeStamp.005
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetEgressTimeStamp
TEST.NEW
TEST.NAME:EthIf_GetEgressTimeStamp.005
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetEgressTimeStamp.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetEgressTimeStamp.timeQualPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetEgressTimeStamp.timeStampPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Eth_GetEgressTimeStamp.CtrlIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_GetIngressTimeStamp

-- Test Case: EthIf_GetIngressTimeStamp.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetIngressTimeStamp
TEST.NEW
TEST.NAME:EthIf_GetIngressTimeStamp.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETINGRESSTIMESTAMP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetIngressTimeStamp.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetIngressTimeStamp
TEST.NEW
TEST.NAME:EthIf_GetIngressTimeStamp.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.CtrlIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETINGRESSTIMESTAMP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetIngressTimeStamp.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetIngressTimeStamp
TEST.NEW
TEST.NAME:EthIf_GetIngressTimeStamp.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.DataPtr:<<null>>
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.timeQualPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.timeStampPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETINGRESSTIMESTAMP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetIngressTimeStamp.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetIngressTimeStamp
TEST.NEW
TEST.NAME:EthIf_GetIngressTimeStamp.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.DataPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.timeQualPtr:<<null>>
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.timeStampPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETINGRESSTIMESTAMP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetIngressTimeStamp.005
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetIngressTimeStamp
TEST.NEW
TEST.NAME:EthIf_GetIngressTimeStamp.005
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.DataPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.timeQualPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.timeStampPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETINGRESSTIMESTAMP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetIngressTimeStamp.006
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetIngressTimeStamp
TEST.NEW
TEST.NAME:EthIf_GetIngressTimeStamp.006
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.DataPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.timeQualPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetIngressTimeStamp.timeStampPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Eth_GetIngressTimeStamp.CtrlIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_GetPhysAddr

-- Test Case: EthIf_GetPhysAddr.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetPhysAddr
TEST.NEW
TEST.NAME:EthIf_GetPhysAddr.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETPHYADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetPhysAddr.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetPhysAddr
TEST.NEW
TEST.NAME:EthIf_GetPhysAddr.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetPhysAddr.CtrlIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETPHYADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetPhysAddr.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetPhysAddr
TEST.NEW
TEST.NAME:EthIf_GetPhysAddr.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetPhysAddr.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetPhysAddr.PhysAddrPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETPHYADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetPhysAddr.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetPhysAddr
TEST.NEW
TEST.NAME:EthIf_GetPhysAddr.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetPhysAddr.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetPhysAddr.PhysAddrPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Eth_GetPhysAddr.CtrlIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_GetPortMacAddr

-- Test Case: EthIf_GetPortMacAddr.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetPortMacAddr
TEST.NEW
TEST.NAME:EthIf_GetPortMacAddr.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_GetPortMacAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETPORTMACADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetPortMacAddr.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetPortMacAddr
TEST.NEW
TEST.NAME:EthIf_GetPortMacAddr.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.EthIf_GetPortMacAddr.MacAddrPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetPortMacAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETPORTMACADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.END

-- Test Case: EthIf_GetPortMacAddr.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetPortMacAddr
TEST.NEW
TEST.NAME:EthIf_GetPortMacAddr.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.EthIf_GetPortMacAddr.MacAddrPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetPortMacAddr.SwitchIdxPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetPortMacAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETPORTMACADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.END

-- Test Case: EthIf_GetPortMacAddr.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetPortMacAddr
TEST.NEW
TEST.NAME:EthIf_GetPortMacAddr.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.EthIf_GetPortMacAddr.MacAddrPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetPortMacAddr.SwitchIdxPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetPortMacAddr.PortIdxPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetPortMacAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETPORTMACADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.END

-- Test Case: EthIf_GetPortMacAddr.005
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetPortMacAddr
TEST.NEW
TEST.NAME:EthIf_GetPortMacAddr.005
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.EthIf_GetPortMacAddr.MacAddrPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetPortMacAddr.SwitchIdxPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_GetPortMacAddr.PortIdxPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_GetPortMacAddr.return:E_OK
TEST.END

-- Subprogram: EthIf_GetTransceiverMode

-- Test Case: EthIf_GetTransceiverMode.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetTransceiverMode
TEST.NEW
TEST.NAME:EthIf_GetTransceiverMode.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_GetTransceiverMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETTRCVMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetTransceiverMode.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetTransceiverMode
TEST.NEW
TEST.NAME:EthIf_GetTransceiverMode.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_GetTransceiverMode.TrcvIdx:1
TEST.EXPECTED:EthIf.EthIf_GetTransceiverMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETTRCVMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetTransceiverMode.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetTransceiverMode
TEST.NEW
TEST.NAME:EthIf_GetTransceiverMode.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_GetTransceiverMode.TrcvIdx:0
TEST.VALUE:EthIf.EthIf_GetTransceiverMode.TrcvModePtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetTransceiverMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETTRCVMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetTransceiverMode.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetTransceiverMode
TEST.NEW
TEST.NAME:EthIf_GetTransceiverMode.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_GetTransceiverMode.TrcvIdx:0
TEST.VALUE:EthIf.EthIf_GetTransceiverMode.TrcvModePtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_GetTransceiverMode.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_GetTransceiverWakeupMode

-- Test Case: EthIf_GetTransceiverWakeupMode.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthIf_GetTransceiverWakeupMode.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_GetTransceiverWakeupMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETTRCVWAKEUPMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetTransceiverWakeupMode.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthIf_GetTransceiverWakeupMode.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_GetTransceiverWakeupMode.TrcvIdx:1
TEST.EXPECTED:EthIf.EthIf_GetTransceiverWakeupMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETTRCVWAKEUPMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetTransceiverWakeupMode.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthIf_GetTransceiverWakeupMode.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_GetTransceiverWakeupMode.TrcvIdx:0
TEST.VALUE:EthIf.EthIf_GetTransceiverWakeupMode.TrcvWakeupModePtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetTransceiverWakeupMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETTRCVWAKEUPMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetTransceiverWakeupMode.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthIf_GetTransceiverWakeupMode.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_GetTransceiverWakeupMode.TrcvIdx:0
TEST.VALUE:EthIf.EthIf_GetTransceiverWakeupMode.TrcvWakeupModePtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_GetTransceiverWakeupMode.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_GetVersionInfo

-- Test Case: EthIf_GetVersionInfo.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetVersionInfo
TEST.NEW
TEST.NAME:EthIf_GetVersionInfo.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.EthIf_GetVersionInfo.VersionInfoPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETVERSIONINFO_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.END

-- Test Case: EthIf_GetVersionInfo.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetVersionInfo
TEST.NEW
TEST.NAME:EthIf_GetVersionInfo.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.EthIf_GetVersionInfo.VersionInfoPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_GetVersionInfo.VersionInfoPtr[0].vendorID:ETHIF_VENDOR_ID
TEST.EXPECTED:EthIf.EthIf_GetVersionInfo.VersionInfoPtr[0].moduleID:ETHIF_MODULE_ID
TEST.EXPECTED:EthIf.EthIf_GetVersionInfo.VersionInfoPtr[0].sw_major_version:ETHIF_SW_MAJOR_VERSION
TEST.EXPECTED:EthIf.EthIf_GetVersionInfo.VersionInfoPtr[0].sw_minor_version:ETHIF_SW_MINOR_VERSION
TEST.EXPECTED:EthIf.EthIf_GetVersionInfo.VersionInfoPtr[0].sw_patch_version:ETHIF_SW_PATCH_VERSION
TEST.END

-- Subprogram: EthIf_GetVlanId

-- Test Case: EthIf_GetVlanId.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetVlanId
TEST.NEW
TEST.NAME:EthIf_GetVlanId.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_GetVlanId.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETVLANID_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_GetVlanId.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetVlanId
TEST.NEW
TEST.NAME:EthIf_GetVlanId.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetVlanId.CtrlIdx:1
TEST.EXPECTED:EthIf.EthIf_GetVlanId.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETVLANID_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetVlanId.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetVlanId
TEST.NEW
TEST.NAME:EthIf_GetVlanId.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetVlanId.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetVlanId.VlanIdPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_GetVlanId.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_GETVLANID_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_GetVlanId.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_GetVlanId
TEST.NEW
TEST.NAME:EthIf_GetVlanId.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_GetVlanId.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_GetVlanId.VlanIdPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_GetVlanId.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_Init

-- Test Case: EthIf_Init.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_Init
TEST.NEW
TEST.NAME:EthIf_Init.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfFrameType:0x800
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_Init.CfgPtr:<<null>>
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:0x800
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:INVALID_BUFFER_INDEX
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = &(EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_ProvideTxBuffer

-- Test Case: EthIf_ProvideTxBuffer.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ProvideTxBuffer
TEST.NEW
TEST.NAME:EthIf_ProvideTxBuffer.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_ProvideTxBuffer.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_PROVIDETXBUFFER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_ProvideTxBuffer.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ProvideTxBuffer
TEST.NEW
TEST.NAME:EthIf_ProvideTxBuffer.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.CtrlIdx:1
TEST.EXPECTED:EthIf.EthIf_ProvideTxBuffer.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_PROVIDETXBUFFER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_ProvideTxBuffer.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ProvideTxBuffer
TEST.NEW
TEST.NAME:EthIf_ProvideTxBuffer.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufIdxPtr:<<null>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_ProvideTxBuffer.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_PROVIDETXBUFFER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_ProvideTxBuffer.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ProvideTxBuffer
TEST.NEW
TEST.NAME:EthIf_ProvideTxBuffer.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufIdxPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufPtr:<<null>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_ProvideTxBuffer.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_PROVIDETXBUFFER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_ProvideTxBuffer.005
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ProvideTxBuffer
TEST.NEW
TEST.NAME:EthIf_ProvideTxBuffer.005
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufIdxPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_ProvideTxBuffer.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_PROVIDETXBUFFER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_ProvideTxBuffer.006
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ProvideTxBuffer
TEST.NEW
TEST.NAME:EthIf_ProvideTxBuffer.006
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:INVALID_VLAN_ID
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufIdxPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr[0]:1600
TEST.EXPECTED:EthIf.EthIf_ProvideTxBuffer.return:BUFREQ_E_NOT_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_ProvideTxBuffer.007
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ProvideTxBuffer
TEST.NEW
TEST.NAME:EthIf_ProvideTxBuffer.007
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:INVALID_VLAN_ID
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufIdxPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr[0]:1400
TEST.VALUE:uut_prototype_stubs.Eth_ProvideTxBuffer.return:BUFREQ_OK
TEST.EXPECTED:EthIf.EthIf_ProvideTxBuffer.return:BUFREQ_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_ProvideTxBuffer.008
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ProvideTxBuffer
TEST.NEW
TEST.NAME:EthIf_ProvideTxBuffer.008
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufIdxPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr[0]:1600
TEST.EXPECTED:EthIf.EthIf_ProvideTxBuffer.return:BUFREQ_E_NOT_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_ProvideTxBuffer.009
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ProvideTxBuffer
TEST.NEW
TEST.NAME:EthIf_ProvideTxBuffer.009
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.Priority:PRIORITY_SIZE
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufIdxPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr[0]:1400
TEST.EXPECTED:EthIf.EthIf_ProvideTxBuffer.return:BUFREQ_E_NOT_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_ProvideTxBuffer.010
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ProvideTxBuffer
TEST.NEW
TEST.NAME:EthIf_ProvideTxBuffer.010
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.Priority:0
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufIdxPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr:<<malloc 20>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr[0]:1400
TEST.VALUE:uut_prototype_stubs.Eth_ProvideTxBuffer.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:EthIf.EthIf_ProvideTxBuffer.return:BUFREQ_E_NOT_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_ProvideTxBuffer.011
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ProvideTxBuffer
TEST.NEW
TEST.NAME:EthIf_ProvideTxBuffer.011
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.Priority:0
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufIdxPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.BufPtr[0]:<<malloc 20>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_ProvideTxBuffer.LenBytePtr[0]:1400
TEST.VALUE:uut_prototype_stubs.Eth_ProvideTxBuffer.return:BUFREQ_OK
TEST.EXPECTED:EthIf.EthIf_ProvideTxBuffer.return:BUFREQ_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_ResetConfiguration

-- Test Case: EthIf_ResetConfiguration.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ResetConfiguration
TEST.NEW
TEST.NAME:EthIf_ResetConfiguration.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_ResetConfiguration.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_RESETCONFIG_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_ResetConfiguration.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ResetConfiguration
TEST.NEW
TEST.NAME:EthIf_ResetConfiguration.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfSwitchCount:1
TEST.VALUE:EthIf.EthIf_ResetConfiguration.SwitchIdx:1
TEST.EXPECTED:EthIf.EthIf_ResetConfiguration.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_RESETCONFIG_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_SWT_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_ResetConfiguration.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_ResetConfiguration
TEST.NEW
TEST.NAME:EthIf_ResetConfiguration.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthTrcvId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfSwitchCount:1
TEST.VALUE:EthIf.EthIf_ResetConfiguration.SwitchIdx:0
TEST.EXPECTED:EthIf.EthIf_ResetConfiguration.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_RxIndication

-- Test Case: EthIf_RxIndication.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_RxIndication
TEST.NEW
TEST.NAME:EthIf_RxIndication.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_RxIndication.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_RxIndication
TEST.NEW
TEST.NAME:EthIf_RxIndication.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_RxIndication.CtrlIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_RxIndication.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_RxIndication
TEST.NEW
TEST.NAME:EthIf_RxIndication.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_RxIndication.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_RxIndication.DataPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_RxIndication.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_RxIndication
TEST.NEW
TEST.NAME:EthIf_RxIndication.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:INVALID_VLAN_ID
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfFrameType:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfRxIndicationHandle:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfTrcvLinkStateChgFuncArr:<<null>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_RxIndication.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_RxIndication.FrameType:0
TEST.VALUE:EthIf.EthIf_RxIndication.DataPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr.pEthIfULRxIndicationFuncArr[0]
<<EthIf.<<GLOBAL>>.EthIf_Config>>.pEthIfULRxIndicationFuncArr[0] = ( &ULRxIndicationFunc );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_RxIndication.005
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_RxIndication
TEST.NEW
TEST.NAME:EthIf_RxIndication.005
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:INVALID_VLAN_ID
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfFrameType:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfRxIndicationHandle:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr[0]:<<value error>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfTrcvLinkStateChgFuncArr:<<null>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_RxIndication.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_RxIndication.FrameType:0
TEST.VALUE:EthIf.EthIf_RxIndication.DataPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_RxIndication.006
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_RxIndication
TEST.NEW
TEST.NAME:EthIf_RxIndication.006
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:INVALID_VLAN_ID
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfFrameType:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfRxIndicationHandle:ETHIF_INVALID_HANDLE
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfTrcvLinkStateChgFuncArr:<<null>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_RxIndication.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_RxIndication.FrameType:0
TEST.VALUE:EthIf.EthIf_RxIndication.DataPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr.pEthIfULRxIndicationFuncArr[0]
<<EthIf.<<GLOBAL>>.EthIf_Config>>.pEthIfULRxIndicationFuncArr[0] = ( &ULRxIndicationFunc );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_RxIndication.007
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_RxIndication
TEST.NEW
TEST.NAME:EthIf_RxIndication.007
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:INVALID_VLAN_ID
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfFrameType:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfRxIndicationHandle:ETHIF_INVALID_HANDLE
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfTrcvLinkStateChgFuncArr:<<null>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_RxIndication.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_RxIndication.FrameType:1
TEST.VALUE:EthIf.EthIf_RxIndication.DataPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr.pEthIfULRxIndicationFuncArr[0]
<<EthIf.<<GLOBAL>>.EthIf_Config>>.pEthIfULRxIndicationFuncArr[0] = ( &ULRxIndicationFunc );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_RxIndication.008
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_RxIndication
TEST.NEW
TEST.NAME:EthIf_RxIndication.008
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfFrameType:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfRxIndicationHandle:ETHIF_INVALID_HANDLE
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfTrcvLinkStateChgFuncArr:<<null>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_RxIndication.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_RxIndication.FrameType:1
TEST.VALUE:EthIf.EthIf_RxIndication.DataPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr.pEthIfULRxIndicationFuncArr[0]
<<EthIf.<<GLOBAL>>.EthIf_Config>>.pEthIfULRxIndicationFuncArr[0] = ( &ULRxIndicationFunc );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_RxIndication.009
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_RxIndication
TEST.NEW
TEST.NAME:EthIf_RxIndication.009
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:ETH_FRAME_TYPE_VLAN
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfFrameType:ETH_FRAME_TYPE_VLAN
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfRxIndicationHandle:ETHIF_INVALID_HANDLE
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfTrcvLinkStateChgFuncArr:<<null>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_RxIndication.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_RxIndication.FrameType:ETH_FRAME_TYPE_VLAN
TEST.VALUE:EthIf.EthIf_RxIndication.DataPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:ETH_FRAME_TYPE_VLAN
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr.pEthIfULRxIndicationFuncArr[0]
<<EthIf.<<GLOBAL>>.EthIf_Config>>.pEthIfULRxIndicationFuncArr[0] = ( &ULRxIndicationFunc );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_RxIndication.010
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_RxIndication
TEST.NEW
TEST.NAME:EthIf_RxIndication.010
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:ETH_FRAME_TYPE_VLAN
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:0x101
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfFrameType:ETH_FRAME_TYPE_VLAN
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfRxIndicationHandle:ETHIF_INVALID_HANDLE
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfTrcvLinkStateChgFuncArr:<<null>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_RxIndication.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_RxIndication.FrameType:ETH_FRAME_TYPE_VLAN
TEST.VALUE:EthIf.EthIf_RxIndication.DataPtr:<<malloc 10>>
TEST.VALUE:EthIf.EthIf_RxIndication.DataPtr[0]:01
TEST.VALUE:EthIf.EthIf_RxIndication.DataPtr[1]:01
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:ETH_FRAME_TYPE_VLAN
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULRxIndicationFuncArr.pEthIfULRxIndicationFuncArr[0]
<<EthIf.<<GLOBAL>>.EthIf_Config>>.pEthIfULRxIndicationFuncArr[0] = ( &ULRxIndicationFunc );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_SetControllerMode

-- Test Case: EthIf_SetControllerMode.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetControllerMode
TEST.NEW
TEST.NAME:EthIf_SetControllerMode.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.VALUE:EthIf.EthIf_SetControllerMode.CtrlIdx:0
TEST.EXPECTED:EthIf.EthIf_SetControllerMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETCTRLMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_SetControllerMode.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetControllerMode
TEST.NEW
TEST.NAME:EthIf_SetControllerMode.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_SetControllerMode.CtrlIdx:2
TEST.EXPECTED:EthIf.EthIf_SetControllerMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETCTRLMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_SetControllerMode.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetControllerMode
TEST.NEW
TEST.NAME:EthIf_SetControllerMode.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_SetControllerMode.CtrlIdx:0
TEST.VALUE:uut_prototype_stubs.Eth_SetControllerMode.return:E_OK
TEST.EXPECTED:EthIf.EthIf_SetControllerMode.return:E_OK
TEST.EXPECTED:uut_prototype_stubs.Eth_SetControllerMode.CtrlIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_SetCorrectionTime

-- Test Case: EthIf_SetCorrectionTime.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetCorrectionTime
TEST.NEW
TEST.NAME:EthIf_SetCorrectionTime.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETCORRECTIONTIME_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_SetCorrectionTime.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetCorrectionTime
TEST.NEW
TEST.NAME:EthIf_SetCorrectionTime.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_SetCorrectionTime.CtrlIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETCORRECTIONTIME_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_SetCorrectionTime.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetCorrectionTime
TEST.NEW
TEST.NAME:EthIf_SetCorrectionTime.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_SetCorrectionTime.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_SetCorrectionTime.timeOffsetPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETCORRECTIONTIME_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_SetCorrectionTime.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetCorrectionTime
TEST.NEW
TEST.NAME:EthIf_SetCorrectionTime.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_SetCorrectionTime.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_SetCorrectionTime.rateRatioPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETCORRECTIONTIME_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_SetCorrectionTime.005
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetCorrectionTime
TEST.NEW
TEST.NAME:EthIf_SetCorrectionTime.005
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_SetCorrectionTime.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_SetCorrectionTime.timeOffsetPtr:<<malloc 1>>
TEST.VALUE:EthIf.EthIf_SetCorrectionTime.rateRatioPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Eth_SetCorrectionTime.CtrlIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_SetGlobalTime

-- Test Case: EthIf_SetGlobalTime.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetGlobalTime
TEST.NEW
TEST.NAME:EthIf_SetGlobalTime.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_SetGlobalTime.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETGLOBALTIME_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_SetGlobalTime.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetGlobalTime
TEST.NEW
TEST.NAME:EthIf_SetGlobalTime.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_SetGlobalTime.CtrlIdx:1
TEST.EXPECTED:EthIf.EthIf_SetGlobalTime.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETGLOBALTIME_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_SetGlobalTime.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetGlobalTime
TEST.NEW
TEST.NAME:EthIf_SetGlobalTime.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_SetGlobalTime.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_SetGlobalTime.timeStampPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_SetGlobalTime.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETGLOBALTIME_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_SetGlobalTime.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetGlobalTime
TEST.NEW
TEST.NAME:EthIf_SetGlobalTime.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_SetGlobalTime.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_SetGlobalTime.timeStampPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_SetGlobalTime.return:E_OK
TEST.EXPECTED:uut_prototype_stubs.Eth_SetGlobalTime.CtrlIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_SetPhysAddr

-- Test Case: EthIf_SetPhysAddr.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetPhysAddr
TEST.NEW
TEST.NAME:EthIf_SetPhysAddr.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETPHYADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_SetPhysAddr.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetPhysAddr
TEST.NEW
TEST.NAME:EthIf_SetPhysAddr.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_SetPhysAddr.CtrlIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETPHYADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_SetPhysAddr.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetPhysAddr
TEST.NEW
TEST.NAME:EthIf_SetPhysAddr.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_SetPhysAddr.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_SetPhysAddr.PhysAddrPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETPHYADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_SetPhysAddr.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetPhysAddr
TEST.NEW
TEST.NAME:EthIf_SetPhysAddr.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_SetPhysAddr.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_SetPhysAddr.PhysAddrPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Eth_SetPhysAddr.CtrlIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_SetTransceiverMode

-- Test Case: EthIf_SetTransceiverMode.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetTransceiverMode
TEST.NEW
TEST.NAME:EthIf_SetTransceiverMode.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_SetTransceiverMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETTRCVMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_SetTransceiverMode.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetTransceiverMode
TEST.NEW
TEST.NAME:EthIf_SetTransceiverMode.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_SetTransceiverMode.TrcvIdx:1
TEST.EXPECTED:EthIf.EthIf_SetTransceiverMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETTRCVMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_SetTransceiverMode.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetTransceiverMode
TEST.NEW
TEST.NAME:EthIf_SetTransceiverMode.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_SetTransceiverMode.TrcvIdx:0
TEST.EXPECTED:EthIf.EthIf_SetTransceiverMode.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_SetTransceiverWakeupMode

-- Test Case: EthIf_SetTransceiverWakeupMode.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthIf_SetTransceiverWakeupMode.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_SetTransceiverWakeupMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETTRCVWAKEUPMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_SetTransceiverWakeupMode.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthIf_SetTransceiverWakeupMode.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_SetTransceiverWakeupMode.TrcvIdx:1
TEST.EXPECTED:EthIf.EthIf_SetTransceiverWakeupMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_SETTRCVWAKEUPMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_SetTransceiverWakeupMode.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_SetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthIf_SetTransceiverWakeupMode.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_SetTransceiverWakeupMode.TrcvIdx:0
TEST.EXPECTED:EthIf.EthIf_SetTransceiverWakeupMode.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_StoreConfiguration

-- Test Case: EthIf_StoreConfiguration.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_StoreConfiguration
TEST.NEW
TEST.NAME:EthIf_StoreConfiguration.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_StoreConfiguration.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_STORECONFIG_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_StoreConfiguration.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_StoreConfiguration
TEST.NEW
TEST.NAME:EthIf_StoreConfiguration.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfSwitchCount:1
TEST.VALUE:EthIf.EthIf_StoreConfiguration.SwitchIdx:1
TEST.EXPECTED:EthIf.EthIf_StoreConfiguration.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_STORECONFIG_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_SWT_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_StoreConfiguration.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_StoreConfiguration
TEST.NEW
TEST.NAME:EthIf_StoreConfiguration.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfSwitchCount:1
TEST.VALUE:EthIf.EthIf_StoreConfiguration.SwitchIdx:0
TEST.EXPECTED:EthIf.EthIf_StoreConfiguration.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_Transmit

-- Test Case: EthIf_Transmit.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_Transmit
TEST.NEW
TEST.NAME:EthIf_Transmit.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_TRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_Transmit.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_Transmit
TEST.NEW
TEST.NAME:EthIf_Transmit.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_Transmit.CtrlIdx:1
TEST.EXPECTED:EthIf.EthIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_TRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_Transmit.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_Transmit
TEST.NEW
TEST.NAME:EthIf_Transmit.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:2
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_Transmit.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.BufIdx:3
TEST.VALUE:EthIf.EthIf_Transmit.PhysAddrPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_TRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_PARAM
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_Transmit.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_Transmit
TEST.NEW
TEST.NAME:EthIf_Transmit.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:2
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_Transmit.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.BufIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.PhysAddrPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_TRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_Transmit.005
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_Transmit
TEST.NEW
TEST.NAME:EthIf_Transmit.005
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:2
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_Transmit.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.BufIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.LenByte:1600
TEST.VALUE:EthIf.EthIf_Transmit.PhysAddrPtr:<<malloc 6>>
TEST.EXPECTED:EthIf.EthIf_Transmit.return:E_NOT_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_Transmit.006
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_Transmit
TEST.NEW
TEST.NAME:EthIf_Transmit.006
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:2
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:INVALID_VLAN_ID
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_Transmit.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.BufIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.LenByte:1400
TEST.VALUE:EthIf.EthIf_Transmit.PhysAddrPtr:<<malloc 6>>
TEST.VALUE:uut_prototype_stubs.Eth_Transmit.return:E_NOT_OK
TEST.EXPECTED:EthIf.EthIf_Transmit.return:E_NOT_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_Transmit.007
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_Transmit
TEST.NEW
TEST.NAME:EthIf_Transmit.007
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:2
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr[0]:<<null>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_Transmit.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.BufIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.LenByte:1400
TEST.VALUE:EthIf.EthIf_Transmit.PhysAddrPtr:<<malloc 6>>
TEST.VALUE:uut_prototype_stubs.Eth_Transmit.return:E_OK
TEST.EXPECTED:EthIf.EthIf_Transmit.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_Transmit.008
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_Transmit
TEST.NEW
TEST.NAME:EthIf_Transmit.008
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:2
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_Transmit.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.BufIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.TxConfirmation:TRUE
TEST.VALUE:EthIf.EthIf_Transmit.LenByte:1400
TEST.VALUE:EthIf.EthIf_Transmit.PhysAddrPtr:<<malloc 6>>
TEST.VALUE:uut_prototype_stubs.Eth_Transmit.return:E_OK
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:0
TEST.EXPECTED:EthIf.EthIf_Transmit.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr.pEthIfULTxConfirmationFuncArr[0]
void Eth_Confirm(uint8 CtrlIdx, Eth_BufIdxType BufIdx )
{

}
<<EthIf.<<GLOBAL>>.EthIf_Config>>.pEthIfULTxConfirmationFuncArr[0] = ( &Eth_Confirm );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_Transmit.009
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_Transmit
TEST.NEW
TEST.NAME:EthIf_Transmit.009
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:2
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_Transmit.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.BufIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.TxConfirmation:FALSE
TEST.VALUE:EthIf.EthIf_Transmit.LenByte:1400
TEST.VALUE:EthIf.EthIf_Transmit.PhysAddrPtr:<<malloc 6>>
TEST.VALUE:uut_prototype_stubs.Eth_Transmit.return:E_OK
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:INVALID_BUFFER_INDEX
TEST.EXPECTED:EthIf.EthIf_Transmit.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr.pEthIfULTxConfirmationFuncArr[0]
void Eth_Confirm(uint8 CtrlIdx, Eth_BufIdxType BufIdx )
{

}
<<EthIf.<<GLOBAL>>.EthIf_Config>>.pEthIfULTxConfirmationFuncArr[0] = ( &Eth_Confirm );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_Transmit.010
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_Transmit
TEST.NEW
TEST.NAME:EthIf_Transmit.010
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:800
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:2
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_Transmit.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.BufIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.FrameType:0
TEST.VALUE:EthIf.EthIf_Transmit.TxConfirmation:FALSE
TEST.VALUE:EthIf.EthIf_Transmit.LenByte:1400
TEST.VALUE:EthIf.EthIf_Transmit.PhysAddrPtr:<<malloc 6>>
TEST.VALUE:uut_prototype_stubs.Eth_Transmit.return:E_OK
TEST.EXPECTED:EthIf.EthIf_Transmit.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr.pEthIfULTxConfirmationFuncArr[0]
void Eth_Confirm(uint8 CtrlIdx, Eth_BufIdxType BufIdx )
{

}
<<EthIf.<<GLOBAL>>.EthIf_Config>>.pEthIfULTxConfirmationFuncArr[0] = ( &Eth_Confirm );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_Transmit.011
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_Transmit
TEST.NEW
TEST.NAME:EthIf_Transmit.011
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].FrameType:800
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:2
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlMtu:1500
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfVlanId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<null>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_Transmit.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.BufIdx:0
TEST.VALUE:EthIf.EthIf_Transmit.FrameType:0
TEST.VALUE:EthIf.EthIf_Transmit.TxConfirmation:FALSE
TEST.VALUE:EthIf.EthIf_Transmit.LenByte:1400
TEST.VALUE:EthIf.EthIf_Transmit.PhysAddrPtr:<<malloc 6>>
TEST.VALUE:uut_prototype_stubs.Eth_Transmit.return:E_OK
TEST.EXPECTED:EthIf.EthIf_Transmit.return:E_OK
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_TxConfirmation

-- Test Case: EthIf_TxConfirmation.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_TxConfirmation
TEST.NEW
TEST.NAME:EthIf_TxConfirmation.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_TXCONFIRMATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_TxConfirmation.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_TxConfirmation
TEST.NEW
TEST.NAME:EthIf_TxConfirmation.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_TxConfirmation.CtrlIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_TXCONFIRMATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_TxConfirmation.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_TxConfirmation
TEST.NEW
TEST.NAME:EthIf_TxConfirmation.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_TxConfirmation.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_TxConfirmation.BufIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_TXCONFIRMATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_PARAM
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_TxConfirmation.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_TxConfirmation
TEST.NEW
TEST.NAME:EthIf_TxConfirmation.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<null>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.EthIf_TxConfirmation.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_TxConfirmation.BufIdx:0
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_TxConfirmation.005
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_TxConfirmation
TEST.NEW
TEST.NAME:EthIf_TxConfirmation.005
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfTxConfirmationHandle:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_TxConfirmation.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_TxConfirmation.BufIdx:0
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr.pEthIfULTxConfirmationFuncArr[0]
<<EthIf.<<GLOBAL>>.EthIf_Config>>.pEthIfULTxConfirmationFuncArr[0] = ( &EthConfirm );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_TxConfirmation.006
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_TxConfirmation
TEST.NEW
TEST.NAME:EthIf_TxConfirmation.006
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfTxConfirmationHandle:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_TxConfirmation.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_TxConfirmation.BufIdx:0
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_TxConfirmation.007
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_TxConfirmation
TEST.NEW
TEST.NAME:EthIf_TxConfirmation.007
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfTxConfirmationHandle:ETHIF_INVALID_HANDLE
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_TxConfirmation.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_TxConfirmation.BufIdx:0
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_TxConfirmation.008
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_TxConfirmation
TEST.NEW
TEST.NAME:EthIf_TxConfirmation.008
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfMaxTxBufsTotal:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfOwnerCfg[0].EthIfTxConfirmationHandle:ETHIF_INVALID_HANDLE
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfULTxConfirmationFuncArr:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfOwnersCount:1
TEST.VALUE:EthIf.EthIf_TxConfirmation.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_TxConfirmation.BufIdx:0
TEST.EXPECTED:EthIf.<<GLOBAL>>.EthIf_BufferIdToFrameMap[0].BufferIdx:1
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthIf_UpdatePhysAddrFilter

-- Test Case: EthIf_UpdatePhysAddrFilter.001
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_UpdatePhysAddrFilter
TEST.NEW
TEST.NAME:EthIf_UpdatePhysAddrFilter.001
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_UNINIT
TEST.EXPECTED:EthIf.EthIf_UpdatePhysAddrFilter.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_UPDATEPHYADDRFILTER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_UNINIT
TEST.END

-- Test Case: EthIf_UpdatePhysAddrFilter.002
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_UpdatePhysAddrFilter
TEST.NEW
TEST.NAME:EthIf_UpdatePhysAddrFilter.002
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_UpdatePhysAddrFilter.CtrlIdx:1
TEST.EXPECTED:EthIf.EthIf_UpdatePhysAddrFilter.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_UPDATEPHYADDRFILTER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_INV_CTRL_IDX
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_UpdatePhysAddrFilter.003
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_UpdatePhysAddrFilter
TEST.NEW
TEST.NAME:EthIf_UpdatePhysAddrFilter.003
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_UpdatePhysAddrFilter.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_UpdatePhysAddrFilter.PhysAddrPtr:<<null>>
TEST.EXPECTED:EthIf.EthIf_UpdatePhysAddrFilter.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHIF_UPDATEPHYADDRFILTER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHIF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthIf_UpdatePhysAddrFilter.004
TEST.UNIT:EthIf
TEST.SUBPROGRAM:EthIf_UpdatePhysAddrFilter
TEST.NEW
TEST.NAME:EthIf_UpdatePhysAddrFilter.004
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_InitStatus:ETHIF_STATE_INIT
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg:<<malloc 1>>
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.pEthIfCtrlCfg[0].EthIfEthCtrlId:0
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfCtrlCount:1
TEST.VALUE:EthIf.<<GLOBAL>>.EthIf_Config.EthIfTrcvCount:1
TEST.VALUE:EthIf.EthIf_UpdatePhysAddrFilter.CtrlIdx:0
TEST.VALUE:EthIf.EthIf_UpdatePhysAddrFilter.PhysAddrPtr:<<malloc 1>>
TEST.EXPECTED:EthIf.EthIf_UpdatePhysAddrFilter.return:E_OK
TEST.EXPECTED:uut_prototype_stubs.Eth_UpdatePhysAddrFilter.CtrlIdx:0
TEST.VALUE_USER_CODE:EthIf.<<GLOBAL>>.pEthIfConfig
<<EthIf.<<GLOBAL>>.pEthIfConfig>> = ( &EthIf_Config );
TEST.END_VALUE_USER_CODE:
TEST.END
