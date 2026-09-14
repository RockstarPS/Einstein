-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : WDG_PROXY_LINUX_UT
-- Unit(s) Under Test: main wdg_proxy_comm_if wdg_proxy_linux
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: main

-- Subprogram: VCAST_main

-- Test Case: VCAST_main.Success
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.Success
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_onInit
TEST.STUB:wdg_proxy_linux.WdgProxy_onStart
TEST.VALUE:wdg_proxy_linux.WdgProxy_onInit.return:WP_OK
TEST.VALUE:wdg_proxy_linux.WdgProxy_onStart.return:WP_OK
TEST.END

-- Test Case: VCAST_main.WdgProxy_OnInit_fail
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.WdgProxy_OnInit_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_onInit
TEST.VALUE:wdg_proxy_linux.WdgProxy_onInit.return:WP_FAIL
TEST.END

-- Test Case: VCAST_main.WdgProxy_OnStart_fail
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.WdgProxy_OnStart_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_onInit
TEST.STUB:wdg_proxy_linux.WdgProxy_onStart
TEST.VALUE:wdg_proxy_linux.WdgProxy_onInit.return:WP_OK
TEST.VALUE:wdg_proxy_linux.WdgProxy_onStart.return:WP_FAIL
TEST.END

-- Test Case: VCAST_main.g_exit_U8=0
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.g_exit_U8=0
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_onInit
TEST.STUB:wdg_proxy_linux.WdgProxy_onStart
TEST.VALUE:main.<<GLOBAL>>.g_exit_U8:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_onInit.return:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_onStart.return:0
TEST.END

-- Subprogram: handle_sigterm

-- Test Case: handle_sigterm.cleanup
TEST.UNIT:main
TEST.SUBPROGRAM:handle_sigterm
TEST.NEW
TEST.NAME:handle_sigterm.cleanup
TEST.STUB:wdg_proxy_linux.WdgProxy_onStop
TEST.STUB:wdg_proxy_linux.WdgProxy_onShutdown
TEST.VALUE:main.handle_sigterm.signum:15
TEST.VALUE:wdg_proxy_linux.WdgProxy_onStop.return:WP_OK
TEST.VALUE:wdg_proxy_linux.WdgProxy_onShutdown.return:WP_OK
TEST.END

-- Unit: wdg_proxy_comm_if

-- Subprogram: WdgProxyCommIF_SendHealthEvent

-- Test Case: WdgProxyCommIF_SendHealthEvent.WdgProxyCommIf_Init_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIF_SendHealthEvent
TEST.NEW
TEST.NAME:WdgProxyCommIF_SendHealthEvent.WdgProxyCommIf_Init_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_FAIL
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_FAIL
TEST.END

-- Test Case: WdgProxyCommIF_SendHealthEvent.return_WP_OK
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIF_SendHealthEvent
TEST.NEW
TEST.NAME:WdgProxyCommIF_SendHealthEvent.return_WP_OK
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:VMF_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_OK
TEST.END

-- Test Case: WdgProxyCommIF_SendHealthEvent.vmf_send_basic_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIF_SendHealthEvent
TEST.NEW
TEST.NAME:WdgProxyCommIF_SendHealthEvent.vmf_send_basic_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:-1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxyCommIf_Init

-- Test Case: WdgProxyCommIf_Init.Successful_init
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_Init
TEST.NEW
TEST.NAME:WdgProxyCommIf_Init.Successful_init
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:1
TEST.VALUE:wdg_proxy_comm_if.<<GLOBAL>>.vmf_client_id:-1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.END

-- Test Case: WdgProxyCommIf_Init.vmf_client_id_!=-1
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_Init
TEST.NEW
TEST.NAME:WdgProxyCommIf_Init.vmf_client_id_!=-1
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_comm_if.<<GLOBAL>>.vmf_client_id:1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.END

-- Test Case: WdgProxyCommIf_Init.vmf_connect_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_Init
TEST.NEW
TEST.NAME:WdgProxyCommIf_Init.vmf_connect_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:-1
TEST.VALUE:wdg_proxy_comm_if.<<GLOBAL>>.vmf_client_id:-1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxyCommIf_PackageDLTLogs

-- Test Case: WdgProxyCommIf_PackageDLTLogs.WdgProxyCommIf_Init_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_PackageDLTLogs
TEST.NEW
TEST.NAME:WdgProxyCommIf_PackageDLTLogs.WdgProxyCommIf_Init_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_FAIL
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_PackageDLTLogs.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_PackageDLTLogs.return:WP_FAIL
TEST.END

-- Test Case: WdgProxyCommIf_PackageDLTLogs.return_WP_OK
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_PackageDLTLogs
TEST.NEW
TEST.NAME:WdgProxyCommIf_PackageDLTLogs.return_WP_OK
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:VMF_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_PackageDLTLogs.return:WP_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_PackageDLTLogs.return:WP_OK
TEST.END

-- Test Case: WdgProxyCommIf_PackageDLTLogs.vmf_send_basic_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_PackageDLTLogs
TEST.NEW
TEST.NAME:WdgProxyCommIf_PackageDLTLogs.vmf_send_basic_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:-1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_PackageDLTLogs.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_PackageDLTLogs.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxyCommIf_SendFatalError

-- Test Case: WdgProxyCommIf_SendFatalError.WdgProxyCommIf_Init_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_SendFatalError
TEST.NEW
TEST.NAME:WdgProxyCommIf_SendFatalError.WdgProxyCommIf_Init_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_FAIL
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.return:WP_FAIL
TEST.END

-- Test Case: WdgProxyCommIf_SendFatalError.return_WP_OK
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_SendFatalError
TEST.NEW
TEST.NAME:WdgProxyCommIf_SendFatalError.return_WP_OK
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:VMF_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.return:WP_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.return:WP_OK
TEST.END

-- Test Case: WdgProxyCommIf_SendFatalError.vmf_send_basic_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_SendFatalError
TEST.NEW
TEST.NAME:WdgProxyCommIf_SendFatalError.vmf_send_basic_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:-1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxyCommIf_SendHeartbeat

-- Test Case: WdgProxyCommIf_SendHeartbeat.WdgProxyCommIf_Init_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_SendHeartbeat
TEST.NEW
TEST.NAME:WdgProxyCommIf_SendHeartbeat.WdgProxyCommIf_Init_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_FAIL
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_SendHeartbeat.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_SendHeartbeat.return:WP_FAIL
TEST.END

-- Test Case: WdgProxyCommIf_SendHeartbeat.return_WP_OK
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_SendHeartbeat
TEST.NEW
TEST.NAME:WdgProxyCommIf_SendHeartbeat.return_WP_OK
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:VMF_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_SendHeartbeat.return:WP_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_SendHeartbeat.return:WP_OK
TEST.END

-- Test Case: WdgProxyCommIf_SendHeartbeat.vmf_send_basic_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_SendHeartbeat
TEST.NEW
TEST.NAME:WdgProxyCommIf_SendHeartbeat.vmf_send_basic_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:-1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_SendHeartbeat.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_SendHeartbeat.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxyCommIf_Shutdown

-- Test Case: WdgProxyCommIf_Shutdown.vmf_client_id==-1
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_Shutdown
TEST.NEW
TEST.NAME:WdgProxyCommIf_Shutdown.vmf_client_id==-1
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_comm_if.<<GLOBAL>>.vmf_client_id:-1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Shutdown.return:WP_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_Shutdown.return:WP_OK
TEST.END

-- Test Case: WdgProxyCommIf_Shutdown.vmf_client_id_!=-1
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_Shutdown
TEST.NEW
TEST.NAME:WdgProxyCommIf_Shutdown.vmf_client_id_!=-1
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_comm_if.<<GLOBAL>>.vmf_client_id:1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Shutdown.return:WP_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_Shutdown.return:WP_OK
TEST.END

-- Unit: wdg_proxy_linux

-- Subprogram: WdgProxy_GetCurrentState

-- Test Case: WdgProxy_GetCurrentState.ActiveState_active
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_GetCurrentState
TEST.NEW
TEST.NAME:WdgProxy_GetCurrentState.ActiveState_active
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_QuerySdBusProperity
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 7>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"active"
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.index:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_OK
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_OK
TEST.END

-- Test Case: WdgProxy_GetCurrentState.ActiveState_activing
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_GetCurrentState
TEST.NEW
TEST.NAME:WdgProxy_GetCurrentState.ActiveState_activing
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_QuerySdBusProperity
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 11>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"activating"
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.index:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_ACTIVATING
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_ACTIVATING
TEST.END

-- Test Case: WdgProxy_GetCurrentState.ActiveState_failed
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_GetCurrentState
TEST.NEW
TEST.NAME:WdgProxy_GetCurrentState.ActiveState_failed
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_QuerySdBusProperity
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 7>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"failed"
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.index:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_FAILED
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_FAILED
TEST.END

-- Test Case: WdgProxy_GetCurrentState.ActiveState_inactive
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_GetCurrentState
TEST.NEW
TEST.NAME:WdgProxy_GetCurrentState.ActiveState_inactive
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_QuerySdBusProperity
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 9>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"inactive"
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.index:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_INACTIVE
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_INACTIVE
TEST.END

-- Test Case: WdgProxy_GetCurrentState.ActiveState_deactivating
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_GetCurrentState
TEST.NEW
TEST.NAME:WdgProxy_GetCurrentState.ActiveState_deactivating
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_QuerySdBusProperity
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 13>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"deactivating"
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.index:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_DEACTIVATING
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_DEACTIVATING
TEST.END

-- Test Case: WdgProxy_GetCurrentState.ActiveState_unknown
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_GetCurrentState
TEST.NEW
TEST.NAME:WdgProxy_GetCurrentState.ActiveState_unknown
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_QuerySdBusProperity
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 8>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"unknown"
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.index:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_FAIL
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_GetCurrentState.QuerrySdBusProperity_ret_Fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_GetCurrentState
TEST.NEW
TEST.NAME:WdgProxy_GetCurrentState.QuerrySdBusProperity_ret_Fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_QuerySdBusProperity
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_FAIL
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxy_CheckProcessCurrState

-- Test Case: WdgProxy_CheckProcessCurrState.idx_out_of_range
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_CheckProcessCurrState
TEST.NEW
TEST.NAME:WdgProxy_CheckProcessCurrState.idx_out_of_range
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.WdgProxy_CheckProcessCurrState.idx:5
TEST.END

-- Test Case: WdgProxy_CheckProcessCurrState.unknown_to_started
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_CheckProcessCurrState
TEST.NEW
TEST.NAME:WdgProxy_CheckProcessCurrState.unknown_to_started
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.WdgProxy_CheckProcessCurrState.idx:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_UNKNOWN_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_ACTIVE
TEST.EXPECTED:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_STARTED_ST
TEST.END

-- Test Case: WdgProxy_CheckProcessCurrState.stopped_to_started
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_CheckProcessCurrState
TEST.NEW
TEST.NAME:WdgProxy_CheckProcessCurrState.stopped_to_started
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.STUB:wdg_proxy_linux.WdgProxy_QuerySdBusProperity
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent
TEST.VALUE:wdg_proxy_linux.WdgProxy_CheckProcessCurrState.idx:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_STOPPED_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_ACTIVE
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_STARTED_ST
TEST.END

-- Test Case: WdgProxy_CheckProcessCurrState.inactive_to_started
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_CheckProcessCurrState
TEST.NEW
TEST.NAME:WdgProxy_CheckProcessCurrState.inactive_to_started
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.STUB:wdg_proxy_linux.WdgProxy_QuerySdBusProperity
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent
TEST.VALUE:wdg_proxy_linux.WdgProxy_CheckProcessCurrState.idx:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_INACTIVE_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_ACTIVE
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_STARTED_ST
TEST.END

-- Test Case: WdgProxy_CheckProcessCurrState.active_state_no_change
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_CheckProcessCurrState
TEST.NEW
TEST.NAME:WdgProxy_CheckProcessCurrState.active_state_no_change
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.WdgProxy_CheckProcessCurrState.idx:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_ACTIVE
TEST.EXPECTED:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.END

-- Test Case: WdgProxy_CheckProcessCurrState.inactive_state_timer_running
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_CheckProcessCurrState
TEST.NEW
TEST.NAME:WdgProxy_CheckProcessCurrState.inactive_state_timer_running
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.WdgProxy_CheckProcessCurrState.idx:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_UNKNOWN_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:200
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_INACTIVE
TEST.EXPECTED:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:100
TEST.END

-- Test Case: WdgProxy_CheckProcessCurrState.inactive_status_no_timer_change
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_CheckProcessCurrState
TEST.NEW
TEST.NAME:WdgProxy_CheckProcessCurrState.inactive_status_no_timer_change
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.WdgProxy_CheckProcessCurrState.idx:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_INACTIVE_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:200
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_INACTIVE
TEST.EXPECTED:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:200
TEST.END

-- Test Case: WdgProxy_CheckProcessCurrState.failed_state_timer_expired
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_CheckProcessCurrState
TEST.NEW
TEST.NAME:WdgProxy_CheckProcessCurrState.failed_state_timer_expired
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.STUB:wdg_proxy_linux.WdgProxy_ReportFatalError
TEST.VALUE:wdg_proxy_linux.WdgProxy_CheckProcessCurrState.idx:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_STOPPED_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_FAILED
TEST.VALUE:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_OK
TEST.END

-- Test Case: WdgProxy_CheckProcessCurrState.activating_no_error
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_CheckProcessCurrState
TEST.NEW
TEST.NAME:WdgProxy_CheckProcessCurrState.activating_no_error
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.WdgProxy_CheckProcessCurrState.idx:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_ACTIVATING
TEST.END

-- Test Case: WdgProxy_CheckProcessCurrState.deactivating_no_error
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_CheckProcessCurrState
TEST.NEW
TEST.NAME:WdgProxy_CheckProcessCurrState.deactivating_no_error
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.WdgProxy_CheckProcessCurrState.idx:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_DEACTIVATING
TEST.END

-- Test Case: WdgProxy_CheckProcessCurrState.query_failed_reports_error
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_CheckProcessCurrState
TEST.NEW
TEST.NAME:WdgProxy_CheckProcessCurrState.query_failed_reports_error
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.STUB:wdg_proxy_linux.WdgProxy_ReportFatalError
TEST.VALUE:wdg_proxy_linux.WdgProxy_CheckProcessCurrState.idx:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_FAIL
TEST.VALUE:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_OK
TEST.END

-- Test Case: WdgProxy_CheckProcessCurrState.invalid_state_reports_error
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_CheckProcessCurrState
TEST.NEW
TEST.NAME:WdgProxy_CheckProcessCurrState.invalid_state_reports_error
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.STUB:wdg_proxy_linux.WdgProxy_ReportFatalError
TEST.VALUE:wdg_proxy_linux.WdgProxy_CheckProcessCurrState.idx:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:99
TEST.VALUE:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_OK
TEST.END

-- Subprogram: WdgProxy_ProcessSDBUSEvent

-- Test Case: WdgProxy_ProcessSDBUSEvent.PROCESS_MONITOR_LIST_SIZE_>_index
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSDBUSEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessSDBUSEvent.PROCESS_MONITOR_LIST_SIZE_>_index
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSDBUSEvent.index:5
TEST.END

-- Test Case: WdgProxy_ProcessSDBUSEvent.prevState_active_&_currState_failed
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSDBUSEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessSDBUSEvent.prevState_active_&_currState_failed
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 7>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"failed"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:<<malloc 7>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:"active"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSDBUSEvent.index:0
TEST.END

-- Test Case: WdgProxy_ProcessSDBUSEvent.prevState_active_&_currState_inactive
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSDBUSEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessSDBUSEvent.prevState_active_&_currState_inactive
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 9>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"inactive"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:<<malloc 7>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:"active"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSDBUSEvent.index:0
TEST.END

-- Test Case: WdgProxy_ProcessSDBUSEvent.prevState_active_&_currState_restart
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSDBUSEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessSDBUSEvent.prevState_active_&_currState_restart
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 8>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"restart"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:<<malloc 7>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:"active"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSDBUSEvent.index:0
TEST.END

-- Test Case: WdgProxy_ProcessSDBUSEvent.prevState_deactivating_&_currState_active
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSDBUSEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessSDBUSEvent.prevState_deactivating_&_currState_active
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 7>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"active"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:<<malloc 13>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:"deactivating"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSDBUSEvent.index:0
TEST.END

-- Test Case: WdgProxy_ProcessSDBUSEvent.prevState_deactivating_&_currState_inactive
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSDBUSEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessSDBUSEvent.prevState_deactivating_&_currState_inactive
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 9>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"inactive"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:<<malloc 13>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:"deactivating"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSDBUSEvent.index:0
TEST.EXPECTED:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_INACTIVE_ST
TEST.END

-- Test Case: WdgProxy_ProcessSDBUSEvent.prevState_deactivating_&_currState_failed
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSDBUSEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessSDBUSEvent.prevState_deactivating_&_currState_failed
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 7>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"failed"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:<<malloc 13>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:"deactivating"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSDBUSEvent.index:0
TEST.END

-- Test Case: WdgProxy_ProcessSDBUSEvent.state_WP_PROCESS_STOPPED_ST
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSDBUSEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessSDBUSEvent.state_WP_PROCESS_STOPPED_ST
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_STOPPED_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSDBUSEvent.index:0
TEST.END

-- Subprogram: WdgProxy_ProcessSdBusMsg

-- Test Case: WdgProxy_ProcessSdBusMsg.process_index_unknown
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.process_index_unknown
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/opt"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:WP_PROCESS_UNKNOWN
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:WP_PROCESS_UNKNOWN
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_enter_container_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_enter_container_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:-1
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_enter_container_fail_2nd_time
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_enter_container_fail_2nd_time
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:1,-1
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_enter_container_fail_3rd_time
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_enter_container_fail_3rd_time
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:(2)1,-1
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_enter_container_ret_2nd_time_with_0
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_enter_container_ret_2nd_time_with_0
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:1,0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_get_path_NULL
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_get_path_NULL
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<null>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:WP_PROCESS_UNKNOWN
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:WP_PROCESS_UNKNOWN
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_ActiveState
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_ActiveState
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:uut_prototype_stubs.strncpy
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:(3)1,-1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:1
TEST.VALUE:uut_prototype_stubs.strcmp.return:0,(2)1,0
TEST.VALUE:uut_prototype_stubs.strncpy.return:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.strncpy.return:<<null>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.msg:<<malloc 1>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.sd_bus_message_read.key.key
char *temp = (char *)malloc(20);
strcpy(temp, "ActiveState");
<<uut_prototype_stubs.sd_bus_message_read.key>> = temp;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_ActiveState_read_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_ActiveState_read_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:uut_prototype_stubs.strncpy
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:(3)1,-1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:-1
TEST.VALUE:uut_prototype_stubs.strcmp.return:0,(2)1,0
TEST.VALUE:uut_prototype_stubs.strncpy.return:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.strncpy.return:<<null>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.msg:<<malloc 1>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.sd_bus_message_read.key.key
char *temp = (char *)malloc(20);
strcpy(temp, "ActiveState");
<<uut_prototype_stubs.sd_bus_message_read.key>> = temp;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_ExecMainPID
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_ExecMainPID
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strcmp
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:(3)1,-1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:1
TEST.VALUE:uut_prototype_stubs.strcmp.return:(2)0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.msg:<<malloc 1>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.sd_bus_message_read.key.key
char *temp = (char *)malloc(20);
//strcpy(temp, "ExecMainPID");
<<uut_prototype_stubs.sd_bus_message_read.key>> = temp;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_ExecMainPID_read_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_ExecMainPID_read_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strcmp
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:(3)1,-1
TEST.VALUE:uut_prototype_stubs.strcmp.return:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.msg:<<malloc 1>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.sd_bus_message_read.key.key
char *temp = (char *)malloc(20);
strcpy(temp, "ExecMainPID");
<<uut_prototype_stubs.sd_bus_message_read.key>> = temp;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_Result
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_Result
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strcmp
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:(3)1,-1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:1
TEST.VALUE:uut_prototype_stubs.strcmp.return:0,1,0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.msg:<<malloc 1>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.sd_bus_message_read.key.key
char *temp = (char *)malloc(20);
strcpy(temp, "Result");
<<uut_prototype_stubs.sd_bus_message_read.key>> = temp;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_Result_read_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_Result_read_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strcmp
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:(3)1,-1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:-1
TEST.VALUE:uut_prototype_stubs.strcmp.return:0,1,0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.msg:<<malloc 1>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.sd_bus_message_read.key.key
char *temp = (char *)malloc(20);
strcpy(temp, "Result");
<<uut_prototype_stubs.sd_bus_message_read.key>> = temp;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:-1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:1
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_unknown_value
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_unknown_value
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:uut_prototype_stubs.strncpy
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_skip.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:(3)1,-1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:1
TEST.VALUE:uut_prototype_stubs.strcmp.return:0,(3)1
TEST.VALUE:uut_prototype_stubs.strncpy.return:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.strncpy.return:<<null>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.msg:<<malloc 1>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.sd_bus_message_read.key.key
char *temp = (char *)malloc(20);
strcpy(temp, "ActiveState");
<<uut_prototype_stubs.sd_bus_message_read.key>> = temp;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_unknown_value_skip_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ProcessSdBusMsg
TEST.NEW
TEST.NAME:WdgProxy_ProcessSdBusMsg.sd_bus_msg_read_key_unknown_value_skip_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:uut_prototype_stubs.strncpy
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.sd_bus_message_get_path.return:"/tmp"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_skip.return:-1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:(3)1,0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:1
TEST.VALUE:uut_prototype_stubs.strcmp.return:0,(3)1
TEST.VALUE:uut_prototype_stubs.strncpy.return:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.strncpy.return:<<null>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 5>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"/tmp"
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.msg:<<malloc 1>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ProcessSdBusMsg.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.sd_bus_message_read.key.key
char *temp = (char *)malloc(20);
strcpy(temp, "ActiveState");
<<uut_prototype_stubs.sd_bus_message_read.key>> = temp;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: WdgProxy_QuerySdBusProperity

-- Test Case: WdgProxy_QuerySdBusProperity.peek_type_int_&_read_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_QuerySdBusProperity
TEST.NEW
TEST.NAME:WdgProxy_QuerySdBusProperity.peek_type_int_&_read_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:-1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.type:"u"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.return:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_QuerySdBusProperity.peek_type_int_&_read_success
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_QuerySdBusProperity
TEST.NEW
TEST.NAME:WdgProxy_QuerySdBusProperity.peek_type_int_&_read_success
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strcpy
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.p:"10"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.type:"u"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.return:0
TEST.VALUE:uut_prototype_stubs.strcpy.return:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.strcpy.return:<<null>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.result:<<malloc 1>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_OK
TEST.END

-- Test Case: WdgProxy_QuerySdBusProperity.peek_type_int_&_read_success_result_buf_null
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_QuerySdBusProperity
TEST.NEW
TEST.NAME:WdgProxy_QuerySdBusProperity.peek_type_int_&_read_success_result_buf_null
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.p:"10"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.type:"u"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.return:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.result:<<null>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_QuerySdBusProperity.peek_type_str_&_read_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_QuerySdBusProperity
TEST.NEW
TEST.NAME:WdgProxy_QuerySdBusProperity.peek_type_str_&_read_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:-1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.type:"s"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.return:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_QuerySdBusProperity.peek_type_str_&_read_success
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_QuerySdBusProperity
TEST.NEW
TEST.NAME:WdgProxy_QuerySdBusProperity.peek_type_str_&_read_success
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strcpy
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.p:"abc"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.type:"s"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.return:0
TEST.VALUE:uut_prototype_stubs.strcpy.return:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.strcpy.return:<<null>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.str_result:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_OK
TEST.END

-- Test Case: WdgProxy_QuerySdBusProperity.peek_type_str_&_read_success_str_buf_null
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_QuerySdBusProperity
TEST.NEW
TEST.NAME:WdgProxy_QuerySdBusProperity.peek_type_str_&_read_success_str_buf_null
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strcpy
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.p:"abc"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read_basic.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.type:"s"
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.return:0
TEST.VALUE:uut_prototype_stubs.strcpy.return:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.strcpy.return:<<null>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.str_result:<<malloc 9>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.str_result:<<null>>
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_QuerySdBusProperity.sd_bus_call_method_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_QuerySdBusProperity
TEST.NEW
TEST.NAME:WdgProxy_QuerySdBusProperity.sd_bus_call_method_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:-1
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_QuerySdBusProperity.sd_bus_msg_enter_container_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_QuerySdBusProperity
TEST.NEW
TEST.NAME:WdgProxy_QuerySdBusProperity.sd_bus_msg_enter_container_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:-1
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_QuerySdBusProperity.sd_bus_msg_read_peek_type_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_QuerySdBusProperity
TEST.NEW
TEST.NAME:WdgProxy_QuerySdBusProperity.sd_bus_msg_read_peek_type_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_enter_container.return:0
TEST.VALUE:uut_prototype_stubs.sd_bus_message_peek_type.return:-1
TEST.VALUE:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_QuerySdBusProperity.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxy_ReportFatalError

-- Test Case: WdgProxy_ReportFatalError.PROCESS_MONITOR_LIST_SIZE_>_idx
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ReportFatalError
TEST.NEW
TEST.NAME:WdgProxy_ReportFatalError.PROCESS_MONITOR_LIST_SIZE_>_idx
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.WdgProxy_ReportFatalError.idx:5
TEST.VALUE:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_ReportFatalError.SendHealthEvent_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ReportFatalError
TEST.NEW
TEST.NAME:WdgProxy_ReportFatalError.SendHealthEvent_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_FAIL
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].health_event_sent:false
TEST.VALUE:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_ReportFatalError.delayTimerExpired_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ReportFatalError
TEST.NEW
TEST.NAME:WdgProxy_ReportFatalError.delayTimerExpired_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[1].health_event_sent:true
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[1].delay_timer:200
TEST.VALUE:wdg_proxy_linux.WdgProxy_ReportFatalError.idx:1
TEST.VALUE:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_ReportFatalError.return_WP_OK
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ReportFatalError
TEST.NEW
TEST.NAME:WdgProxy_ReportFatalError.return_WP_OK
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.return:WP_OK
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[1].health_event_sent:true
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[1].delay_timer:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_ReportFatalError.idx:1
TEST.VALUE:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_OK
TEST.END

-- Test Case: WdgProxy_ReportFatalError.SendHealthEvent_ok
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_ReportFatalError
TEST.NEW
TEST.NAME:WdgProxy_ReportFatalError.SendHealthEvent_ok
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_OK
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[1].health_event_sent:false
TEST.VALUE:wdg_proxy_linux.WdgProxy_ReportFatalError.idx:1
TEST.VALUE:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_ReportFatalError.return:WP_OK
TEST.END

-- Subprogram: WdgProxy_RunEventTimer

-- Test Case: WdgProxy_RunEventTimer.fatal_error_false
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.fatal_error_false
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.msg_timer_cnt:100
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.fatal_error:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isActive:true
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[1].state:WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[1].isActive:true
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[2].state:WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[2].isActive:true
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[3].state:WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[3].isActive:true
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isActive:true
TEST.END

-- Test Case: WdgProxy_RunEventTimer.fatal_error_true
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.fatal_error_true
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.msg_timer_cnt:100
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.fatal_error:true
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.END

-- Test Case: WdgProxy_RunEventTimer.msg_timer_cnt_>_0
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.msg_timer_cnt_>_0
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.msg_timer_cnt:1000
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.fatal_error:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_Invalid
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_Invalid
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:6
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_WP_PROCESS_INACTIVE_ST
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_WP_PROCESS_INACTIVE_ST
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_INACTIVE_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_SD_PROCESS_CURR_STATE_ACTIVATING
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_UNKNOWN_getCurrentStatus_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_UNKNOWN_getCurrentStatus_fail
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_UNKNOWN_ST
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_UNKNOWN_isActive_false
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_UNKNOWN_isActive_false
TEST.NOTES:
WdgProxy in GIP_INFRA::InfrastructureServices::WdgProxy (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_UNKNOWN_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isActive:false
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_OK
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_UNKNOWN_isActive_true
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_UNKNOWN_isActive_true
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_UNKNOWN_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isActive:true
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_OK
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_WP_PROCESS_ERROR_ST
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_WP_PROCESS_ERROR_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_ERROR_ST
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_WP_PROCESS_HEALTHY_ST
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_WP_PROCESS_STARTED_ST
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_WP_PROCESS_STARTED_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_STARTED_ST
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_WP_PROCESS_STOPPED_ST_delayTimerExpire_false
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_WP_PROCESS_STOPPED_ST_delayTimerExpire_false
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_STOPPED_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isActive:true
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].delayTimerExpired:false
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_OK
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_WP_PROCESS_STOPPED_ST_delayTimerExpire_true
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_WP_PROCESS_STOPPED_ST_delayTimerExpire_true
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_STOPPED_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isActive:true
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].delayTimerExpired:true
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].ReCheck:true
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_OK
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_WP_PROCESS_STOPPED_ST_getCurrentStatus_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_WP_PROCESS_STOPPED_ST_getCurrentStatus_fail
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_STOPPED_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isActive:true
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].delayTimerExpired:true
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_WP_PROCESS_STOPPED_ST_isActive_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_WP_PROCESS_STOPPED_ST_isActive_fail
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_STOPPED_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isActive:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].delayTimerExpired:true
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_OK
TEST.END

-- Test Case: WdgProxy_RunEventTimer.state_WP_PROCESS_STOPPED_ST_isActive_fail_rechek_no
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.state_WP_PROCESS_STOPPED_ST_isActive_fail_rechek_no
TEST.STUB:wdg_proxy_linux.WdgProxy_GetCurrentState
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_STOPPED_ST
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isActive:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].delayTimerExpired:true
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].ReCheck:true
TEST.VALUE:wdg_proxy_linux.WdgProxy_GetCurrentState.return:WP_OK
TEST.END

-- Subprogram: WdgProxy_SetupSdBusMatchRule

-- Test Case: WdgProxy_SetupSdBusMatchRule.return_WP_OK
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_SetupSdBusMatchRule
TEST.NEW
TEST.NAME:WdgProxy_SetupSdBusMatchRule.return_WP_OK
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_add_match.return:1
TEST.VALUE:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule.return:WP_OK
TEST.END

-- Test Case: WdgProxy_SetupSdBusMatchRule.sd_bus_add_match_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_SetupSdBusMatchRule
TEST.NEW
TEST.NAME:WdgProxy_SetupSdBusMatchRule.sd_bus_add_match_fail
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_add_match.return:-1
TEST.VALUE:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_SetupSdBusMatchRule.sd_bus_call_method_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_SetupSdBusMatchRule
TEST.NEW
TEST.NAME:WdgProxy_SetupSdBusMatchRule.sd_bus_call_method_fail
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:-1
TEST.VALUE:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_SetupSdBusMatchRule.sd_bus_msg_read_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_SetupSdBusMatchRule
TEST.NEW
TEST.NAME:WdgProxy_SetupSdBusMatchRule.sd_bus_msg_read_fail
TEST.VALUE:uut_prototype_stubs.sd_bus_call_method.return:1
TEST.VALUE:uut_prototype_stubs.sd_bus_message_read.return:-1
TEST.VALUE:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxy_StartEventTimer

-- Test Case: WdgProxy_StartEventTimer.return_WP_OK
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_StartEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StartEventTimer.return_WP_OK
TEST.VALUE:uut_prototype_stubs.timerfd_create.return:0
TEST.VALUE:uut_prototype_stubs.timerfd_settime.return:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_StartEventTimer.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_StartEventTimer.return:WP_OK
TEST.END

-- Test Case: WdgProxy_StartEventTimer.timerfd_create_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_StartEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StartEventTimer.timerfd_create_fail
TEST.VALUE:uut_prototype_stubs.timerfd_create.return:-1
TEST.VALUE:wdg_proxy_linux.WdgProxy_StartEventTimer.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_StartEventTimer.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_StartEventTimer.timerfd_settime_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_StartEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StartEventTimer.timerfd_settime_fail
TEST.VALUE:uut_prototype_stubs.timerfd_create.return:0
TEST.VALUE:uut_prototype_stubs.timerfd_settime.return:-1
TEST.VALUE:wdg_proxy_linux.WdgProxy_StartEventTimer.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_StartEventTimer.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxy_StopEventTimer

-- Test Case: WdgProxy_StopEventTimer.close_ret_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_StopEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StopEventTimer.close_ret_fail
TEST.VALUE:uut_prototype_stubs.close.return:-1
TEST.VALUE:wdg_proxy_linux.WdgProxy_StopEventTimer.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_StopEventTimer.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_StopEventTimer.return_WP_OK
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_StopEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StopEventTimer.return_WP_OK
TEST.VALUE:uut_prototype_stubs.close.return:0
TEST.VALUE:wdg_proxy_linux.WdgProxy_StopEventTimer.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_StopEventTimer.return:WP_OK
TEST.END

-- Subprogram: WdgProxy_onInit

-- Test Case: WdgProxy_onInit.bus_access_<_0
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_onInit
TEST.NEW
TEST.NAME:WdgProxy_onInit.bus_access_<_0
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:-1
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_onInit.return:WP_FAIL
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.sd_bus_open_system.ret
<<uut_prototype_stubs.sd_bus_open_system.ret>> = &<<wdg_proxy_linux.<<GLOBAL>>.bus>>;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_onInit.bus_access_>0
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_onInit
TEST.NEW
TEST.NAME:WdgProxy_onInit.bus_access_>0
TEST.VALUE:uut_prototype_stubs.sd_bus_open_system.return:1
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_onInit.return:WP_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.sd_bus_open_system.ret
<<uut_prototype_stubs.sd_bus_open_system.ret>> = &<<wdg_proxy_linux.<<GLOBAL>>.bus>>;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: WdgProxy_onShutdown

-- Test Case: WdgProxy_onShutdown.return_WP_OK
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_onShutdown
TEST.NEW
TEST.NAME:WdgProxy_onShutdown.return_WP_OK
TEST.END

-- Subprogram: WdgProxy_onStart

-- Test Case: WdgProxy_onStart.SetupSdBusMatchRule_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_onStart
TEST.NEW
TEST.NAME:WdgProxy_onStart.SetupSdBusMatchRule_fail
TEST.STUB:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.matchRule:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.matchRule:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ExecMainPID:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.Result:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.Result:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].RestartTimer:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].restartCount:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].event:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isWdgEnabled:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isActive:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].health_event_sent:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].delayTimerExpired:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].ReCheck:false
TEST.VALUE:wdg_proxy_linux.WdgProxy_onStart.return:WP_OK
TEST.VALUE:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_onStart.return:WP_OK
TEST.END

-- Test Case: WdgProxy_onStart.return_WP_OK
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_onStart
TEST.NEW
TEST.NAME:WdgProxy_onStart.return_WP_OK
TEST.STUB:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule
TEST.VALUE:uut_prototype_stubs.sd_bus_get_fd.return:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.matchRule:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.matchRule:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ExecMainPID:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.Result:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.Result:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].RestartTimer:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].restartCount:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].event:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isWdgEnabled:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isActive:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].health_event_sent:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].delayTimerExpired:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].ReCheck:false
TEST.VALUE:wdg_proxy_linux.WdgProxy_onStart.return:WP_OK
TEST.VALUE:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_onStart.return:WP_OK
TEST.END

-- Test Case: WdgProxy_onStart.sd_bus_get_fd_ret_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_onStart
TEST.NEW
TEST.NAME:WdgProxy_onStart.sd_bus_get_fd_ret_fail
TEST.STUB:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule
TEST.VALUE:uut_prototype_stubs.sd_bus_get_fd.return:-1
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.matchRule:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.matchRule:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceCfg.objPath:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ExecMainPID:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.Result:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.Result:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.ActiveState:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:<<malloc 2>>
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].serviceProperity.PrevActiveState:"0"
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].RestartTimer:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].state:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].restartCount:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].event:0
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isWdgEnabled:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].isActive:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].health_event_sent:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].delayTimerExpired:false
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.ProcessMonitorData[0].ReCheck:false
TEST.VALUE:wdg_proxy_linux.WdgProxy_onStart.return:WP_FAIL
TEST.VALUE:wdg_proxy_linux.WdgProxy_SetupSdBusMatchRule.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_onStart.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxy_onStop

-- Test Case: WdgProxy_onStop.WdgProxyCommIf_Shutdown_ret_WP_FAIL
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_onStop
TEST.NEW
TEST.NAME:WdgProxy_onStop.WdgProxyCommIf_Shutdown_ret_WP_FAIL
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Shutdown
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Shutdown.return:WP_FAIL
TEST.VALUE:wdg_proxy_linux.WdgProxy_onStop.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_onStop.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_onStop.WdgProxyCommIf_Shutdown_ret_WP_OK
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_onStop
TEST.NEW
TEST.NAME:WdgProxy_onStop.WdgProxyCommIf_Shutdown_ret_WP_OK
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Shutdown
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Shutdown.return:WP_OK
TEST.VALUE:wdg_proxy_linux.WdgProxy_onStop.return:WP_OK
TEST.EXPECTED:wdg_proxy_linux.WdgProxy_onStop.return:WP_OK
TEST.END

-- Subprogram: WdgProxy_worker

-- Test Case: WdgProxy_worker.poll_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.poll_fail
TEST.VALUE:uut_prototype_stubs.poll.return:-1
TEST.END

-- Test Case: WdgProxy_worker.poll_fail.fd_0_revent_POLLERR
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.poll_fail.fd_0_revent_POLLERR
TEST.VALUE:uut_prototype_stubs.sd_bus_process.r[0]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.sd_bus_process.return:1
TEST.VALUE:uut_prototype_stubs.poll.return:1
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.fds[0].revents:POLLERR
TEST.END

-- Test Case: WdgProxy_worker.poll_fail.fd_0_revent_POLLIN
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.poll_fail.fd_0_revent_POLLIN
TEST.VALUE:uut_prototype_stubs.sd_bus_process.r[0]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.sd_bus_process.return:1
TEST.VALUE:uut_prototype_stubs.poll.return:1
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.fds[0].revents:POLLIN
TEST.END

-- Test Case: WdgProxy_worker.fd_0_revent_POLLIN_no_pending_msg
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.fd_0_revent_POLLIN_no_pending_msg
TEST.VALUE:uut_prototype_stubs.sd_bus_process.return:0
TEST.VALUE:uut_prototype_stubs.poll.return:1
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.fds[0].revents:POLLIN
TEST.END

-- Test Case: WdgProxy_worker.poll_fail.fd_0_revent_POLLIN_msg_NULL
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.poll_fail.fd_0_revent_POLLIN_msg_NULL
TEST.VALUE:uut_prototype_stubs.sd_bus_process.r:<<null>>
TEST.VALUE:uut_prototype_stubs.sd_bus_process.return:1
TEST.VALUE:uut_prototype_stubs.poll.return:1
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.fds[0].revents:POLLIN
TEST.END

-- Test Case: WdgProxy_worker.poll_fail.fd_0_revent_sd_bus_process_fail
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.poll_fail.fd_0_revent_sd_bus_process_fail
TEST.VALUE:uut_prototype_stubs.sd_bus_process.return:-1
TEST.VALUE:uut_prototype_stubs.poll.return:1
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.fds[0].revents:POLLIN
TEST.END

-- Test Case: WdgProxy_worker.poll_fail.fd_1_revent_POLLIN
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.poll_fail.fd_1_revent_POLLIN
TEST.VALUE:uut_prototype_stubs.poll.return:2
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.fds[0].revents:POLLHUP
TEST.VALUE:wdg_proxy_linux.<<GLOBAL>>.fds[1].revents:POLLIN
TEST.END

-- Test Case: WdgProxy_worker.read_fds==0
TEST.UNIT:wdg_proxy_linux
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.read_fds==0
TEST.VALUE:uut_prototype_stubs.poll.return:0
TEST.END
