-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : ETHTRCV_VCAST_HT
-- Unit(s) Under Test: EthTrcv
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: EthTrcv_CheckWakeup

-- Test Case: EthTrcv_CheckWakeup.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_CheckWakeup
TEST.NEW
TEST.NAME:EthTrcv_CheckWakeup.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.EXPECTED:EthTrcv.EthTrcv_CheckWakeup.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_CHECKWAKEUP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_NOT_INITIALIZED
TEST.END

-- Test Case: EthTrcv_CheckWakeup.002
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_CheckWakeup
TEST.NEW
TEST.NAME:EthTrcv_CheckWakeup.002
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_CheckWakeup.TrcvIdx:1
TEST.EXPECTED:EthTrcv.EthTrcv_CheckWakeup.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_CHECKWAKEUP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_CheckWakeup.003
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_CheckWakeup
TEST.NEW
TEST.NAME:EthTrcv_CheckWakeup.003
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_CheckWakeup.TrcvIdx:0
TEST.EXPECTED:EthTrcv.EthTrcv_CheckWakeup.return:E_OK
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthTrcv_GetBaudRate

-- Test Case: EthTrcv_GetBaudRate.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetBaudRate
TEST.NEW
TEST.NAME:EthTrcv_GetBaudRate.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.EXPECTED:EthTrcv.EthTrcv_GetBaudRate.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETBAUDRATE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_NOT_INITIALIZED
TEST.END

-- Test Case: EthTrcv_GetBaudRate.002
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetBaudRate
TEST.NEW
TEST.NAME:EthTrcv_GetBaudRate.002
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetBaudRate.TrcvIdx:1
TEST.EXPECTED:EthTrcv.EthTrcv_GetBaudRate.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETBAUDRATE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_GetBaudRate.003
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetBaudRate
TEST.NEW
TEST.NAME:EthTrcv_GetBaudRate.003
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetBaudRate.TrcvIdx:0
TEST.VALUE:EthTrcv.EthTrcv_GetBaudRate.BaudRatePtr:<<null>>
TEST.EXPECTED:EthTrcv.EthTrcv_GetBaudRate.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETBAUDRATE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_GetBaudRate.004
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetBaudRate
TEST.NEW
TEST.NAME:EthTrcv_GetBaudRate.004
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetBaudRate.TrcvIdx:0
TEST.VALUE:EthTrcv.EthTrcv_GetBaudRate.BaudRatePtr:<<malloc 1>>
TEST.EXPECTED:EthTrcv.EthTrcv_GetBaudRate.return:E_OK
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthTrcv_GetDuplexMode

-- Test Case: EthTrcv_GetDuplexMode.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetDuplexMode
TEST.NEW
TEST.NAME:EthTrcv_GetDuplexMode.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.EXPECTED:EthTrcv.EthTrcv_GetDuplexMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETDUPLEXMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_NOT_INITIALIZED
TEST.END

-- Test Case: EthTrcv_GetDuplexMode.002
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetDuplexMode
TEST.NEW
TEST.NAME:EthTrcv_GetDuplexMode.002
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetDuplexMode.TrcvIdx:1
TEST.EXPECTED:EthTrcv.EthTrcv_GetDuplexMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETDUPLEXMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_GetDuplexMode.003
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetDuplexMode
TEST.NEW
TEST.NAME:EthTrcv_GetDuplexMode.003
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetDuplexMode.TrcvIdx:0
TEST.VALUE:EthTrcv.EthTrcv_GetDuplexMode.DuplexModePtr:<<null>>
TEST.EXPECTED:EthTrcv.EthTrcv_GetDuplexMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETDUPLEXMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_GetDuplexMode.004
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetDuplexMode
TEST.NEW
TEST.NAME:EthTrcv_GetDuplexMode.004
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetDuplexMode.TrcvIdx:0
TEST.VALUE:EthTrcv.EthTrcv_GetDuplexMode.DuplexModePtr:<<malloc 1>>
TEST.EXPECTED:EthTrcv.EthTrcv_GetDuplexMode.return:E_OK
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthTrcv_GetLinkState

-- Test Case: EthTrcv_GetLinkState.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetLinkState
TEST.NEW
TEST.NAME:EthTrcv_GetLinkState.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.EXPECTED:EthTrcv.EthTrcv_GetLinkState.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETLINKSTATE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_NOT_INITIALIZED
TEST.END

-- Test Case: EthTrcv_GetLinkState.002
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetLinkState
TEST.NEW
TEST.NAME:EthTrcv_GetLinkState.002
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetLinkState.TrcvIdx:1
TEST.EXPECTED:EthTrcv.EthTrcv_GetLinkState.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETLINKSTATE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_GetLinkState.003
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetLinkState
TEST.NEW
TEST.NAME:EthTrcv_GetLinkState.003
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetLinkState.TrcvIdx:0
TEST.VALUE:EthTrcv.EthTrcv_GetLinkState.LinkStatePtr:<<null>>
TEST.EXPECTED:EthTrcv.EthTrcv_GetLinkState.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETLINKSTATE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_GetLinkState.004
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetLinkState
TEST.NEW
TEST.NAME:EthTrcv_GetLinkState.004
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetLinkState.TrcvIdx:0
TEST.VALUE:EthTrcv.EthTrcv_GetLinkState.LinkStatePtr:<<malloc 1>>
TEST.EXPECTED:EthTrcv.EthTrcv_GetLinkState.return:E_OK
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthTrcv_GetTransceiverMode

-- Test Case: EthTrcv_GetTransceiverMode.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetTransceiverMode
TEST.NEW
TEST.NAME:EthTrcv_GetTransceiverMode.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.EXPECTED:EthTrcv.EthTrcv_GetTransceiverMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETTRANSCEIVERMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_NOT_INITIALIZED
TEST.END

-- Test Case: EthTrcv_GetTransceiverMode.002
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetTransceiverMode
TEST.NEW
TEST.NAME:EthTrcv_GetTransceiverMode.002
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetTransceiverMode.TrcvIdx:1
TEST.EXPECTED:EthTrcv.EthTrcv_GetTransceiverMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETTRANSCEIVERMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_GetTransceiverMode.003
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetTransceiverMode
TEST.NEW
TEST.NAME:EthTrcv_GetTransceiverMode.003
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetTransceiverMode.TrcvIdx:0
TEST.VALUE:EthTrcv.EthTrcv_GetTransceiverMode.TrcvModePtr:<<null>>
TEST.EXPECTED:EthTrcv.EthTrcv_GetTransceiverMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETTRANSCEIVERMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_GetTransceiverMode.004
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetTransceiverMode
TEST.NEW
TEST.NAME:EthTrcv_GetTransceiverMode.004
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetTransceiverMode.TrcvIdx:0
TEST.VALUE:EthTrcv.EthTrcv_GetTransceiverMode.TrcvModePtr:<<malloc 1>>
TEST.EXPECTED:EthTrcv.EthTrcv_GetTransceiverMode.return:E_OK
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthTrcv_GetTransceiverWakeupMode

-- Test Case: EthTrcv_GetTransceiverWakeupMode.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthTrcv_GetTransceiverWakeupMode.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.EXPECTED:EthTrcv.EthTrcv_GetTransceiverWakeupMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETTRANSCEIVERWAKEUPMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_NOT_INITIALIZED
TEST.END

-- Test Case: EthTrcv_GetTransceiverWakeupMode.002
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthTrcv_GetTransceiverWakeupMode.002
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetTransceiverWakeupMode.TrcvIdx:1
TEST.EXPECTED:EthTrcv.EthTrcv_GetTransceiverWakeupMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETTRANSCEIVERWAKEUPMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_GetTransceiverWakeupMode.003
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthTrcv_GetTransceiverWakeupMode.003
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetTransceiverWakeupMode.TrcvIdx:0
TEST.VALUE:EthTrcv.EthTrcv_GetTransceiverWakeupMode.TrcvWakeupModePtr:<<null>>
TEST.EXPECTED:EthTrcv.EthTrcv_GetTransceiverWakeupMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETTRANSCEIVERWAKEUPMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_GetTransceiverWakeupMode.004
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthTrcv_GetTransceiverWakeupMode.004
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_GetTransceiverWakeupMode.TrcvIdx:0
TEST.VALUE:EthTrcv.EthTrcv_GetTransceiverWakeupMode.TrcvWakeupModePtr:<<malloc 1>>
TEST.EXPECTED:EthTrcv.EthTrcv_GetTransceiverWakeupMode.return:E_OK
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthTrcv_GetVersionInfo

-- Test Case: EthTrcv_GetVersionInfo.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetVersionInfo
TEST.NEW
TEST.NAME:EthTrcv_GetVersionInfo.001
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_GETVERSIONINFO_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_PARAM_POINTER
TEST.END

-- Test Case: EthTrcv_GetVersionInfo.003
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_GetVersionInfo
TEST.NEW
TEST.NAME:EthTrcv_GetVersionInfo.003
TEST.VALUE:EthTrcv.EthTrcv_GetVersionInfo.VersionInfoPtr:<<malloc 1>>
TEST.EXPECTED:EthTrcv.EthTrcv_GetVersionInfo.VersionInfoPtr[0].vendorID:ETHTRCV_VENDOR_ID
TEST.EXPECTED:EthTrcv.EthTrcv_GetVersionInfo.VersionInfoPtr[0].moduleID:ETHTRCV_MODULE_ID
TEST.EXPECTED:EthTrcv.EthTrcv_GetVersionInfo.VersionInfoPtr[0].sw_major_version:ETHTRCV_SW_MAJOR_VERSION
TEST.EXPECTED:EthTrcv.EthTrcv_GetVersionInfo.VersionInfoPtr[0].sw_minor_version:ETHTRCV_SW_MINOR_VERSION
TEST.EXPECTED:EthTrcv.EthTrcv_GetVersionInfo.VersionInfoPtr[0].sw_patch_version:ETHTRCV_SW_PATCH_VERSION
TEST.END

-- Subprogram: EthTrcv_Init

-- Test Case: EthTrcv_Init.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_Init
TEST.NEW
TEST.NAME:EthTrcv_Init.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_LinkState:ETHTRCV_LINK_STATE_DOWN
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_WakeupMode:ETHTRCV_WUM_ENABLE
TEST.EXPECTED:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.EXPECTED:EthTrcv.<<GLOBAL>>.EthTrcv_LinkState:ETHTRCV_LINK_STATE_DOWN
TEST.EXPECTED:EthTrcv.<<GLOBAL>>.EthTrcv_WakeupMode:ETHTRCV_WUM_DISABLE
TEST.END

-- Subprogram: EthTrcv_MainFunction

-- Test Case: EthTrcv_MainFunction.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_MainFunction
TEST.NEW
TEST.NAME:EthTrcv_MainFunction.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_NOT_INITIALIZED
TEST.END

-- Test Case: EthTrcv_MainFunction.002
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_MainFunction
TEST.NEW
TEST.NAME:EthTrcv_MainFunction.002
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.EXPECTED:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.END

-- Subprogram: EthTrcv_ReadMiiIndication

-- Test Case: EthTrcv_ReadMiiIndication.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_ReadMiiIndication
TEST.NEW
TEST.NAME:EthTrcv_ReadMiiIndication.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_READMIIINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_NOT_INITIALIZED
TEST.END

-- Test Case: EthTrcv_ReadMiiIndication.002
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_ReadMiiIndication
TEST.NEW
TEST.NAME:EthTrcv_ReadMiiIndication.002
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_ReadMiiIndication.TrcvIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_READMIIINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_ReadMiiIndication.003
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_ReadMiiIndication
TEST.NEW
TEST.NAME:EthTrcv_ReadMiiIndication.003
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_ReadMiiIndication.TrcvIdx:0
TEST.EXPECTED:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthTrcv_SetTransceiverMode

-- Test Case: EthTrcv_SetTransceiverMode.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_SetTransceiverMode
TEST.NEW
TEST.NAME:EthTrcv_SetTransceiverMode.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.EXPECTED:EthTrcv.EthTrcv_SetTransceiverMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_SETTRANSCEIVERMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_NOT_INITIALIZED
TEST.END

-- Test Case: EthTrcv_SetTransceiverMode.002
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_SetTransceiverMode
TEST.NEW
TEST.NAME:EthTrcv_SetTransceiverMode.002
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvIdx:1
TEST.VALUE:EthTrcv.EthTrcv_SetTransceiverMode.TrcvIdx:1
TEST.EXPECTED:EthTrcv.EthTrcv_SetTransceiverMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_SETTRANSCEIVERMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_SetTransceiverMode.003
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_SetTransceiverMode
TEST.NEW
TEST.NAME:EthTrcv_SetTransceiverMode.003
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvIdx:1
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_SetTransceiverMode.TrcvIdx:0
TEST.EXPECTED:EthTrcv.EthTrcv_SetTransceiverMode.return:E_OK
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthTrcv_SetTransceiverWakeupMode

-- Test Case: EthTrcv_SetTransceiverWakeupMode.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_SetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthTrcv_SetTransceiverWakeupMode.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.EXPECTED:EthTrcv.EthTrcv_SetTransceiverWakeupMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_SETTRANSCEIVERWAKEUPMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_NOT_INITIALIZED
TEST.END

-- Test Case: EthTrcv_SetTransceiverWakeupMode.002
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_SetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthTrcv_SetTransceiverWakeupMode.002
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_SetTransceiverWakeupMode.TrcvIdx:1
TEST.EXPECTED:EthTrcv.EthTrcv_SetTransceiverWakeupMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_SETTRANSCEIVERWAKEUPMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_SetTransceiverWakeupMode.003
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_SetTransceiverWakeupMode
TEST.NEW
TEST.NAME:EthTrcv_SetTransceiverWakeupMode.003
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_SetTransceiverWakeupMode.TrcvIdx:0
TEST.EXPECTED:EthTrcv.EthTrcv_SetTransceiverWakeupMode.return:E_OK
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthTrcv_StartAutoNegotiation

-- Test Case: EthTrcv_StartAutoNegotiation.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_StartAutoNegotiation
TEST.NEW
TEST.NAME:EthTrcv_StartAutoNegotiation.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.EXPECTED:EthTrcv.EthTrcv_StartAutoNegotiation.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_STARTAUTONEGOTIATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_NOT_INITIALIZED
TEST.END

-- Test Case: EthTrcv_StartAutoNegotiation.002
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_StartAutoNegotiation
TEST.NEW
TEST.NAME:EthTrcv_StartAutoNegotiation.002
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_StartAutoNegotiation.TrcvIdx:1
TEST.EXPECTED:EthTrcv.EthTrcv_StartAutoNegotiation.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_STARTAUTONEGOTIATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_StartAutoNegotiation.003
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_StartAutoNegotiation
TEST.NEW
TEST.NAME:EthTrcv_StartAutoNegotiation.003
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_StartAutoNegotiation.TrcvIdx:0
TEST.EXPECTED:EthTrcv.EthTrcv_StartAutoNegotiation.return:E_OK
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthTrcv_WriteMiiIndication

-- Test Case: EthTrcv_WriteMiiIndication.001
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_WriteMiiIndication
TEST.NEW
TEST.NAME:EthTrcv_WriteMiiIndication.001
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_WRITEMIIINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_NOT_INITIALIZED
TEST.END

-- Test Case: EthTrcv_WriteMiiIndication.002
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_WriteMiiIndication
TEST.NEW
TEST.NAME:EthTrcv_WriteMiiIndication.002
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_WriteMiiIndication.TrcvIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHTRCV_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHTRCV_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHTRCV_WRITEMIIINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHTRCV_E_INV_TRCV_IDX
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthTrcv_WriteMiiIndication.003
TEST.UNIT:EthTrcv
TEST.SUBPROGRAM:EthTrcv_WriteMiiIndication
TEST.NEW
TEST.NAME:EthTrcv_WriteMiiIndication.003
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE:EthTrcv.<<GLOBAL>>.EthTrcv_Config.EthTrcvTotalTrcvCount:1
TEST.VALUE:EthTrcv.EthTrcv_WriteMiiIndication.TrcvIdx:0
TEST.EXPECTED:EthTrcv.<<GLOBAL>>.EthTrcv_InitStatus:ETHTRCV_STATE_INIT
TEST.VALUE_USER_CODE:EthTrcv.<<GLOBAL>>.pEthTrcvConfig
<<EthTrcv.<<GLOBAL>>.pEthTrcvConfig>> = ( &EthTrcv_Config );
TEST.END_VALUE_USER_CODE:
TEST.END
